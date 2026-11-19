"""Read-only screening for shared literal-pool conversion cohorts."""
from collections import Counter
import struct

from .poolfix import Elf


def measure(project):
    counts = Counter()
    candidates = []
    for unit in project.load_units():
        mapping = unit.get('pool') or {}
        if not mapping:
            continue
        base = mapping.get('...rodata.0')
        if not base:
            counts['no_rodata_base_key'] += 1
            continue
        module, source = unit['module'], unit['source']
        target = (project.module_build_dir(module) / 'obj' / source).with_suffix('.o')
        if not target.is_file():
            counts['missing_target'] += 1
            continue
        elf = Elf(target.read_bytes())
        symbols = elf.symbols()
        rela = elf.section('.rela.text')
        if not rela:
            counts['no_text_relocations'] += 1
            continue
        start = rela['offset']
        relocations = [
            (symbols[info >> 8]['name'], info & 0xff, addend)
            for _, info, addend in struct.iter_unpack('>IIi', elf.data[start:start + rela['size']])
        ]
        aliases = {binding.split('+', 1)[0] for binding in mapping.values()} - {base}
        base_relocs = sorted((kind, addend) for name, kind, addend in relocations if name == base)
        # R_PPC_ADDR16_LO and R_PPC_ADDR16_HA. This does not prove register
        # flow, literal widths, or that all live loads can be expressed in C.
        if base_relocs != [(4, 0), (6, 0)] or any(name in aliases for name, _, _ in relocations):
            counts['other_base_pattern'] += 1
            continue
        counts['single_base_candidate'] += 1
        candidates.append(dict(module=module, source=source, tu=unit.get('tu'), base=base))
    candidates.sort(key=lambda row: (row['module'], row['base'], row['source']))
    families = Counter((row['module'], row['base']) for row in candidates)
    return dict(version=project.version, total=sum(counts.values()), counts=dict(sorted(counts.items())),
                families=[dict(module=module, base=base, units=count)
                          for (module, base), count in families.most_common()], candidates=candidates)


def summary(report):
    lines = [f"Pool census ({report['version']}): {report['total']} mapped units"]
    lines.extend(f"  {key}: {count}" for key, count in report['counts'].items())
    lines.append('Largest single-base cohorts (screening only, not verified conversions):')
    lines.extend(f"  {row['module']}:{row['base']}: {row['units']}"
                 for row in report['families'][:12])
    return '\n'.join(lines)
