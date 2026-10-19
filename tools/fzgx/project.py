"""Project model shared by every fzgx subcommand.

Reads decomp-toolkit's config (config.yml, symbols.txt, splits.txt), the
generated build/<VERSION>/config.json and objdiff.json, and the disassembly
dtk writes under build/<VERSION>/**/asm/*.s. Nothing here talks to an LLM.

Address conventions follow dtk: DOL symbols use absolute addresses
(0x80xxxxxx); REL symbols use section-relative offsets.
"""

from __future__ import annotations

import json
import struct
import os
import re
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional

ROOT = Path(__file__).resolve().parent.parent.parent
DEFAULT_VERSION = "GFZE01"
# Ledger, locks, saved attempts and caches: outside build/ on purpose (a build wipe must not lose state).
STATE_DIR = ROOT / ".fzgx"

# "name = .section:0xADDR; // type:function size:0x10 scope:global align:4 data:4byte"
SYMBOL_RE = re.compile(
    r"^(?P<name>[^\s=]+)\s*=\s*(?P<section>\.[\w.$]+):0x(?P<addr>[0-9A-Fa-f]+);"
    r"\s*//\s*(?P<attrs>.*)$"
)
FN_START_RE = re.compile(r"^\.fn\s+(?P<name>\S+?),\s*(?P<scope>\w+)")
FN_END_RE = re.compile(r"^\.endfn\s+(?P<name>\S+)")
# "/* 000003FC 000004B8  7C 05 21 D6 */\tmullw r0, r5, r4"
ASM_LINE_RE = re.compile(
    r"^/\*\s*(?P<addr>[0-9A-Fa-f]+)\s+(?P<off>[0-9A-Fa-f]+)\s+(?P<bytes>(?:[0-9A-Fa-f]{2}\s?){4})\*/\s*(?P<insn>.*)$"
)
PPC_REGS = {f"r{i}" for i in range(32)} | {f"f{i}" for i in range(32)} | {
    f"cr{i}" for i in range(8)} | {"lr", "ctr", "xer", "sp", "rtoc", "qr0"} | {
    f"qr{i}" for i in range(8)}
OPERAND_SYMBOL_RE = re.compile(r"(?<![\w.$@])([A-Za-z_.$][\w.$]*)(?:@(ha|l|sda21|sda2|h|lo|hi))?")


@dataclass
class Symbol:
    name: str
    module: str  # "main" for the DOL, else the REL module name
    section: str
    addr: int
    kind: str  # function | object | label | ...
    size: int
    scope: str
    attrs: Dict[str, str] = field(default_factory=dict)

    @property
    def end(self) -> int:
        return self.addr + self.size


@dataclass
class Split:
    unit: str  # e.g. "rel/sample/keygen.c"
    section: str
    start: int
    end: int
    align: Optional[int]


@dataclass
class Function:
    symbol: Symbol
    asm: List[str]  # instructions without the byte comment prefix
    refs: List[str]  # referenced symbol names (deduplicated, in order)
    unit: Optional[str]  # dtk unit name the function currently belongs to



def load_json_retry(path: Path, tries: int = 20, delay: float = 0.1):
    """json.loads of a file another process may be rewriting (dtk's split writes config.json and
    objdiff.json in place): a short retry instead of a JSONDecodeError on the half-written file."""
    for i in range(tries):
        try:
            return json.loads(path.read_text())
        except (json.JSONDecodeError, FileNotFoundError):
            if i == tries - 1:
                raise
            time.sleep(delay)

class Project:
    def __init__(self, version: str = DEFAULT_VERSION) -> None:
        self.version = version
        self.config_dir = ROOT / "config" / version
        self.build_dir = ROOT / "build" / version
        self.units_path = self.config_dir / "units.json"
        self._modules: Optional[List[str]] = None
        self._symbols: Dict[str, Dict[str, Symbol]] = {}
        self._asm_index: Dict[str, Dict[str, Function]] = {}

    # ------------------------------------------------------------------ modules
    @property
    def modules(self) -> List[str]:
        """Module names: 'main' (DOL) followed by every REL module in config.yml."""
        if self._modules is None:
            names = ["main"]
            text = (self.config_dir / "config.yml").read_text()
            names += re.findall(r"^\s*name:\s*(\S+)\s*$", text, re.M)
            self._modules = names
        return self._modules

    def module_config_dir(self, module: str) -> Path:
        return self.config_dir if module == "main" else self.config_dir / module

    def module_build_dir(self, module: str) -> Path:
        return self.build_dir if module == "main" else self.build_dir / module

    def module_src_prefix(self, module: str) -> str:
        return "dol" if module == "main" else f"rel/{module}"

    # ------------------------------------------------------------------ symbols
    def symbols(self, module: str) -> Dict[str, Symbol]:
        if module not in self._symbols:
            out: Dict[str, Symbol] = {}
            path = self.module_config_dir(module) / "symbols.txt"
            for line in path.read_text().splitlines():
                m = SYMBOL_RE.match(line.strip())
                if not m:
                    continue
                attrs = dict(
                    kv.split(":", 1) if ":" in kv else (kv, "")
                    for kv in m.group("attrs").split()
                )
                size = int(attrs.get("size", "0x0"), 16)
                out[m.group("name")] = Symbol(
                    name=m.group("name"), module=module, section=m.group("section"),
                    addr=int(m.group("addr"), 16), kind=attrs.get("type", ""),
                    size=size, scope=attrs.get("scope", "global"), attrs=attrs,
                )
            self._symbols[module] = out
        return self._symbols[module]

    def find_symbol(self, name: str, module: Optional[str] = None) -> Optional[Symbol]:
        for mod in ([module] if module else self.modules):
            s = self.symbols(mod).get(name)
            if s:
                return s
        return None

    def ambiguous_names(self) -> set:
        """Function names present in more than one module (REL entry points `_prolog`/`_epilog`)."""
        if not hasattr(self, "_ambiguous"):
            seen: Dict[str, int] = {}
            for m in self.modules:
                for s in self.symbols(m).values():
                    if s.kind == "function":
                        seen[s.name] = seen.get(s.name, 0) + 1
            self._ambiguous = {n for n, c in seen.items() if c > 1}
        return self._ambiguous

    def key(self, sym: Symbol) -> str:
        """Ledger key: bare name, or `module:name` when the name exists in several modules."""
        return f"{sym.module}:{sym.name}" if sym.name in self.ambiguous_names() else sym.name

    def resolve(self, ref: str) -> Optional[Symbol]:
        """Look up a function by bare name or `module:name`. Ambiguous bare names return None."""
        if ":" in ref:
            module, name = ref.split(":", 1)
            return self.symbols(module).get(name) if module in self.modules else None
        if ref in self.ambiguous_names():
            return None
        return self.find_symbol(ref)

    def functions(self, module: str) -> List[Symbol]:
        return sorted(
            (s for s in self.symbols(module).values() if s.kind == "function"),
            key=lambda s: s.addr,
        )

    # ------------------------------------------------------------------- splits
    def splits(self, module: str) -> List[Split]:
        # parsed once per file version: every check used to re-read the whole splits file
        path = self.module_config_dir(module) / "splits.txt"
        try:
            stamp = path.stat().st_mtime_ns
        except OSError:
            stamp = None
        cache = self.__dict__.setdefault("_splits_cache", {})
        hit = cache.get(module)
        if hit and hit[0] == stamp:
            return hit[1]
        out: List[Split] = []
        unit: Optional[str] = None
        for raw in path.read_text().splitlines():
            if not raw.strip():
                continue
            if not raw[0].isspace():
                unit = raw.rstrip(":").split(":")[0].strip() if raw.strip() != "Sections:" else None
                continue
            if unit is None:
                continue
            parts = raw.split()
            attrs = dict(p.split(":", 1) for p in parts[1:] if ":" in p)
            if "start" not in attrs:
                continue
            out.append(Split(
                unit=unit, section=parts[0], start=int(attrs["start"], 16),
                end=int(attrs["end"], 16),
                align=int(attrs["align"]) if "align" in attrs else None,
            ))
        cache[module] = (stamp, out)
        return out

    def unit_of(self, sym: Symbol) -> Optional[str]:
        """Configured (non-auto) unit that owns this symbol's address, if any."""
        import bisect
        splits = self.splits(sym.module)
        index = self.__dict__.setdefault("_unit_index", {})
        hit = index.get(sym.module)
        if hit is None or hit[0] is not splits:
            # a linear scan over every split per lookup cost the repair engine 6 ms a call
            by_section = {}
            for sp in splits:
                by_section.setdefault(sp.section, []).append((sp.start, sp.end, sp.unit))
            for rows in by_section.values():
                rows.sort()
            hit = (splits, {sec: ([r[0] for r in rows], rows) for sec, rows in by_section.items()})
            index[sym.module] = hit
        starts_rows = hit[1].get(sym.section)
        if not starts_rows:
            return None
        starts, rows = starts_rows
        i = bisect.bisect_right(starts, sym.addr) - 1
        if i >= 0 and rows[i][0] <= sym.addr < rows[i][1]:
            return rows[i][2]
        return None

    # ---------------------------------------------------------------- asm index
    def _asm_files(self, module: str) -> List[Path]:
        d = self.module_build_dir(module) / "asm"
        config = self.build_dir / 'config.json'
        if not config.exists():
            return sorted(d.rglob('*.s')) if d.exists() else []
        data = load_json_retry(config)
        record = next((m for m in [data] + data.get('modules', []) if m['name'] == module), None)
        paths = []
        for unit in record.get('units', []) if record else []:
            obj = ROOT / unit['object']
            relative = obj.relative_to(self.module_build_dir(module) / 'obj')
            path = (d / relative).with_suffix('.s')
            if path.exists():
                paths.append(path)
        return sorted(paths)

    def callable_asm(self, sym: Symbol) -> Optional[Function]:
        """Read an assembly entry labelled by dtk without changing its ownership or kind."""
        found = self.function_asm(sym.module).get(sym.name)
        if found or sym.section not in ('.text', '.init'):
            return found
        cache = self.__dict__.setdefault('_callable_asm', {})
        key = self.key(sym)
        if key in cache:
            return cache[key]
        modules = self.__dict__.setdefault('_instruction_maps', {})
        if sym.module not in modules:
            instructions = {}
            for path in sorted(self._asm_files(sym.module), key=lambda p: p.stat().st_mtime_ns):
                section = None
                for line in path.read_text().splitlines():
                    sec = re.match(r'\.section\s+([^,\s]+)', line)
                    if sec:
                        section = sec[1]
                    elif line.strip() in ('.text', '.data', '.bss', '.rodata'):
                        section = line.strip()
                    match = ASM_LINE_RE.match(line)
                    if match and section in ('.text', '.init'):
                        instructions[(section, int(match['addr'], 16))] = match['insn'].strip()
            modules[sym.module] = instructions
        instructions = modules[sym.module]
        todo, seen, labels, states = [(sym.addr, {})], set(), {}, {}
        while todo:
            addr, flags = todo.pop()
            old = states.get(addr)
            flags = flags if old is None else {bit: value for bit, value in old.items() if flags.get(bit) == value}
            if old is not None and old == flags:
                continue
            states[addr] = dict(flags)
            insn = instructions.get((sym.section, addr))
            if insn is None:
                cache[key] = None
                return None
            seen.add(addr)
            mnemonic = insn.split()[0].rstrip('+-')
            if mnemonic in ('blr', 'bctr'):
                continue
            set_bit = re.fullmatch(r'cr(set|clr)\s+(?:cr([0-7]))?(lt|gt|eq|so|\d+)', insn)
            if set_bit:
                bit = (int(set_bit[2] or 0) * 4 + ('lt', 'gt', 'eq', 'so').index(set_bit[3])
                       if not set_bit[3].isdigit() else int(set_bit[3]))
                flags[bit] = set_bit[1] == 'set'
            elif mnemonic.startswith(('cmp', 'fcmp')) or mnemonic.endswith('.'):
                field = re.search(r'\bcr([0-7])\b', insn)
                field = int(field[1]) if field else 0
                flags = {bit: value for bit, value in flags.items() if bit // 4 != field}
            elif mnemonic == 'mtcrf':
                mask = int(insn.split()[1].rstrip(','), 0)
                flags = {bit: value for bit, value in flags.items() if not mask & (128 >> (bit // 4))}
            elif mnemonic.startswith('cr'):
                operand = insn.split(None, 1)[1].split(',')[0].strip()
                match = re.fullmatch(r'(?:cr([0-7]))?(lt|gt|eq|so)', operand)
                if match:
                    flags.pop(int(match[1] or 0) * 4 + ('lt', 'gt', 'eq', 'so').index(match[2]), None)
                elif operand.isdigit():
                    flags.pop(int(operand), None)
            elif mnemonic in ('bl', 'bctrl', 'blrl'):
                flags = {bit: value for bit, value in flags.items() if bit // 4 in (2, 3, 4)}
            branch = re.search(r'\b(\.L_([0-9A-Fa-f]+))$', insn)
            if mnemonic.startswith('b') and mnemonic not in ('bl', 'bctrl', 'blrl'):
                condition = re.fullmatch(r'b(eq|ne|lt|ge|gt|le)(?:lr|ctr)?', mnemonic)
                taken = None
                if condition:
                    field = re.search(r'\bcr([0-7])\b', insn)
                    bit = int(field[1] if field else 0) * 4 + {'eq': 2, 'ne': 2, 'lt': 0, 'ge': 0, 'gt': 1, 'le': 1}[condition[1]]
                    if bit in flags:
                        taken = flags[bit] == (condition[1] in ('eq', 'lt', 'gt'))
                if branch and taken is not False:
                    dest = int(branch[2], 16)
                    if dest < sym.addr:
                        cache[key] = None
                        return None
                    labels[dest] = branch[1]
                    todo.append((dest, dict(flags)))
                if mnemonic == 'b' or taken is True:
                    continue
            todo.append((addr + 4, dict(flags)))
        lines = []
        for addr in sorted(seen):
            if addr in labels:
                lines.append(labels[addr] + ':')
            lines.append(f'{addr:08X}: {instructions[(sym.section, addr)]}')
        cache[key] = Function(sym, lines, self._refs(lines, self.symbols(sym.module)), None)
        return cache[key]

    def function_asm(self, module: str) -> Dict[str, Function]:
        """Parse every .s of a module once per process; cached on disk by mtime."""
        if module in self._asm_index:
            return self._asm_index[module]
        files = self._asm_files(module)
        cache = STATE_DIR / f"asm_index_{self.version}_{module}.json"
        stamp = max((f.stat().st_mtime for f in files), default=0)
        if cache.exists():
            try:
                data = json.loads(cache.read_text())
            except (ValueError, FileNotFoundError):
                data = {}  # Regenerate a cache interrupted by an older writer.
            if data.get("stamp") == stamp and data.get("v") == 3:
                self._asm_index[module] = {
                    k: Function(self.symbols(module)[k], v["asm"], v["refs"], v["unit"])
                    for k, v in data["functions"].items() if k in self.symbols(module)
                }
                return self._asm_index[module]
        syms = self.symbols(module)
        # the split output can lag a rename (symbols.txt already new, .s still old): key by address
        by_addr = {s.addr: s for s in syms.values() if s.kind == "function"}
        result: Dict[str, Function] = {}
        # dtk never deletes the .s of a renamed or moved unit; the stale file would shadow the
        # fresh one (old symbol names in its refs). Per function address the file named after
        # the current symbol wins, then an auto unit, then the newest file.
        rank: Dict[int, tuple] = {}
        for f in files:
            unit = str(f.relative_to(self.module_build_dir(module) / "asm").with_suffix(""))
            cur: Optional[str] = None
            lines: List[str] = []
            for raw in f.read_text(errors="replace").splitlines():
                m = FN_START_RE.match(raw)
                if m:
                    cur, lines = m.group("name"), []
                    continue
                if cur and FN_END_RE.match(raw):
                    sym = syms.get(cur)
                    if sym is None and lines:
                        try:
                            sym = by_addr.get(int(lines[0].split(":", 1)[0], 16))
                        except ValueError:
                            sym = None
                    if sym is not None:
                        score = (2 if f.stem == sym.name else 1 if f.name.startswith("auto_") else 0, f.stat().st_mtime)
                        if score >= rank.get(sym.addr, (-1, 0)):
                            rank[sym.addr] = score
                            result[sym.name] = Function(sym, lines, self._refs(lines, syms), unit)
                    cur = None
                    continue
                if cur is None:
                    continue
                m = ASM_LINE_RE.match(raw)
                if m:
                    lines.append(f"{m.group('addr')}: {m.group('insn').strip()}")
                elif raw.strip().endswith(":"):
                    lines.append(raw.strip())  # local label
        cache.parent.mkdir(parents=True, exist_ok=True)
        temporary = cache.with_suffix(f'.{os.getpid()}.tmp')
        temporary.write_text(json.dumps({
            "stamp": stamp, "v": 3,
            "functions": {k: {"asm": v.asm, "refs": v.refs, "unit": v.unit} for k, v in result.items()},
        }))
        try:
            temporary.replace(cache)
        except FileNotFoundError:
            pass  # another thread of this process built and installed the same index first
        self._asm_index[module] = result
        return result

    @staticmethod
    def _refs(lines: List[str], syms: Dict[str, Symbol]) -> List[str]:
        seen: List[str] = []
        for line in lines:
            body = line.split(": ", 1)[1] if ": " in line else line
            if " " not in body:
                continue
            operands = body.split(" ", 1)[1]
            for m in OPERAND_SYMBOL_RE.finditer(operands):
                name = m.group(1)
                if name in PPC_REGS or name.startswith("0x") or name[0].isdigit():
                    continue
                if name in syms and name not in seen:
                    seen.append(name)
        return seen

    def function(self, name: str) -> Optional[Function]:
        sym = self.resolve(name)
        if not sym or sym.kind != "function":
            return None
        return self.function_asm(sym.module).get(sym.name)

    def callers(self, name: str, limit: int = 8) -> List[str]:
        sym = self.resolve(name)
        if not sym:
            return []
        out = [self.key(f.symbol) for f in self.function_asm(sym.module).values() if sym.name in f.refs]
        return out[:limit]

    # -------------------------------------------------------------------- units
    def rewrite_global_references(self, module: str, names: List[str]) -> List[str]:
        mapping = {f'{name}_{sym.addr:08X}': name for name in names
                   if (sym := self.symbols(module).get(name)) and sym.scope == 'global'}
        if not mapping:
            return []
        pattern = re.compile(r'(?<![\w.$@])(?:' + '|'.join(map(re.escape, mapping)) + r')(?![\w.$@])')
        # A dot after a C object starts member access, not a symbol suffix.
        c_pattern = re.compile(r'(?<![\w.$@])(?:' + '|'.join(map(re.escape, mapping)) + r')(?![\w$@])')
        paths = {(ROOT / 'src' / (u.get('tu') or u['source'])).with_suffix('.s' if u.get('asm') else '.c') for u in self.load_units()
                 if module == 'main' or u['module'] == module}
        headers = ROOT / 'include' if module == 'main' else ROOT / 'include/rel' / module
        paths.update(headers.rglob('*.h'))
        changed = []
        for path in sorted(paths):
            if not path.exists():
                continue
            body = path.read_text()
            rewritten = (pattern if path.suffix == ".s" else c_pattern).sub(lambda match: mapping[match[0]], body)
            if rewritten != body:
                path.write_text(rewritten)
                changed.append(str(path.relative_to(ROOT)))
        # Pool targets are linker references too. Keeping an old local suffix
        # here breaks already integrated callers when another unit exports it.
        from . import oracle
        with oracle.build_lock('units.lock'):
            units = self.load_units()
            updated = False
            for unit in units:
                pool = unit.get('pool')
                if not isinstance(pool, dict) or (module != 'main' and unit['module'] != module):
                    continue
                from .poolfix import binding_target
                def rename_binding(target):
                    base, offset = binding_target(target)
                    return mapping.get(base, base) + (f'+0x{offset:X}' if offset else '')
                # The private identifier may retain its original spelling; the
                # compiled symbol is still bound to the promoted owning object.
                renamed = {mapping.get(private, private): rename_binding(target) for private, target in pool.items()}
                if renamed != pool:
                    unit['pool'] = renamed
                    updated = True
            if updated:
                self.save_units(units)
                changed.append(str(self.units_path.relative_to(ROOT)))
        if changed:
            # A promoted function can rename callers outside its own new unit.
            # Those dependencies must land in the same hash-verified commit.
            with (STATE_DIR / 'verify_dependencies.jsonl').open('a') as out:
                out.write(json.dumps(changed) + '\n')
        return changed

    def promote_to_global(self, module: str, names: List[str]) -> List[str]:
        """Mark symbols global in symbols.txt (a reference from another unit needs it: retail
        kept them file-local in a TU our per-function units split). Returns those changed."""
        path = self.module_config_dir(module) / "symbols.txt"
        text = path.read_text()
        changed = []
        for n in names:
            new, k = re.subn(rf"^({re.escape(n)} = .*?)scope:local\b", r"\1scope:global", text, count=1, flags=re.M)
            if k:
                text = new
                changed.append(n)
        if changed:
            path.write_text(text)
            self._symbols.pop(module, None)
        self.rewrite_global_references(module, names)
        return changed

    # ------------------------------------------------------------ retail objects
    def target_object_for(self, sym: Symbol) -> Optional[Path]:
        """The retail split object (dtk output) that defines this function: its own unit's
        object if carved, else the auto unit's. Module identity is part of every key."""
        if not hasattr(self, "_obj_index"):
            from .poolfix import Elf  # scoped: avoids the project<->poolfix import cycle at load
            cache = STATE_DIR / f"obj_index_{self.version}.json"
            # only the objects of the current split (build/<v>/config.json): every split leaves
            # the previous one's auto objects behind as orphans with stale symbol names
            cfg = self.build_dir / "config.json"
            listed: List[str] = []
            def walk(x):
                if isinstance(x, dict):
                    for k, v in x.items():
                        if k == "object" and isinstance(v, str):
                            listed.append(v)
                        else:
                            walk(v)
                elif isinstance(x, list):
                    for v in x:
                        walk(v)
            try:
                walk(load_json_retry(cfg))
            except (OSError, ValueError):
                pass
            objs = sorted(o for o in (ROOT / rel for rel in listed) if o.exists() and "/obj/auto_" in str(o))
            st = cfg.stat() if cfg.exists() else None
            stamp = f"v4:{st.st_mtime_ns}:{st.st_size}:{len(objs)}" if st else "0"
            idx: Dict[str, str] = {}
            suffixed: Dict[str, str] = {}  # plain name -> dtk's address-suffixed local name in the object
            if cache.exists():
                try:
                    d = json.loads(cache.read_text())
                    if d.get("stamp") == stamp:
                        idx = d["index"]; suffixed = d.get("suffixed", {})
                except ValueError:
                    idx = {}
            if not idx:
                for o in objs:
                    relative = o.relative_to(self.build_dir)
                    module = 'main' if relative.parts[0] == 'obj' else relative.parts[0]
                    if module not in self.modules:
                        continue
                    try:
                        elf = Elf(o.read_bytes())
                    except (ValueError, IndexError, struct.error):
                        continue
                    # every executable section (.init holds the boot and cache code, not only .text);
                    # dtk exports a local function under its address-suffixed name (`f_8000314C`)
                    exec_idx = {sec["index"] for sec in elf.sections if sec["flags"] & 4}
                    for e in elf.symbols():
                        if (e["info"] & 0xF) == 2 and e["shndx"] in exec_idx:
                            key = f'{module}:{e["name"]}'
                            idx.setdefault(key, str(o.relative_to(ROOT)))
                            m = re.fullmatch(r"(.+)_[0-9A-F]{8}", e["name"])
                            if m and f"{module}:{m.group(1)}" not in idx:
                                key = f"{module}:{m.group(1)}"
                                idx[key] = str(o.relative_to(ROOT))
                                suffixed[key] = e["name"]
                cache.parent.mkdir(parents=True, exist_ok=True)
                cache.write_text(json.dumps({"stamp": stamp, "index": idx, "suffixed": suffixed}))
            self._obj_index = idx
            self._obj_suffixed = suffixed
        key = f"{sym.module}:{sym.name}"
        rel = self._obj_index.get(key)
        if rel:
            if key in self._obj_suffixed:
                return self._plain_named_copy(ROOT / rel, self._obj_suffixed[key], sym.name)
            return ROOT / rel
        # carved: dtk writes the retail object of the unit itself under <module build dir>/obj
        unit_src = self.unit_of(sym)
        if unit_src:
            o = self.module_build_dir(sym.module) / "obj" / Path(unit_src).with_suffix(".o")
            if o.exists():
                return o
        return None

    def _plain_named_copy(self, obj: Path, suffixed: str, plain: str) -> Path:
        """A copy of a retail object with dtk's address-suffixed local function name shortened
        to the symbols.txt name in place (same string length, NUL-padded), so objdiff sees the
        same symbol on both sides. Cached by the object's mtime."""
        module = obj.relative_to(self.build_dir).parts[0]
        out = STATE_DIR / "objfix" / module / f"{obj.stem}.{plain}.o"
        if out.exists() and out.stat().st_mtime >= obj.stat().st_mtime:
            return out
        data = bytearray(obj.read_bytes())
        needle = suffixed.encode() + b"\0"
        at = data.find(needle)
        if at < 0:
            return obj
        rep = plain.encode() + b"\0" * (len(needle) - len(plain))
        data[at:at + len(needle)] = rep
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(data)
        return out

    # -------------------------------------------------------------------- units
    def load_units(self) -> List[dict]:
        """units.json, parsed once per file version (every check used to re-read it)."""
        if not self.units_path.exists():
            return []
        stamp = self.units_path.stat().st_mtime_ns
        cache = self.__dict__.setdefault("_units_cache", None)
        if cache and cache[0] == stamp:
            return json.loads(cache[1])  # a fresh copy: callers mutate and save the list
        text = self.units_path.read_text()
        self.__dict__["_units_cache"] = (stamp, text)
        return json.loads(text)

    def unit_record(self, unit_source: str) -> Optional[dict]:
        """units.json entry for a split unit name (the `source` field), if configured."""
        stamp = self.units_path.stat().st_mtime_ns if self.units_path.exists() else None
        idx = self.__dict__.get("_units_index")
        if not idx or idx[0] != stamp:
            idx = (stamp, {u["source"]: u for u in self.load_units()})
            self.__dict__["_units_index"] = idx
        return idx[1].get(unit_source)
    def tu_map(self, module: str) -> Dict[str, str]:
        """function symbol -> TU file stem (e.g. 'camera'), from tus.json (cached per module)."""
        if not hasattr(self, "_tu_maps"):
            self._tu_maps: Dict[str, Dict[str, str]] = {}
        if module in self._tu_maps:
            return self._tu_maps[module]
        path = self.module_config_dir(module) / "tus.json"
        out: Dict[str, str] = {}
        if path.exists():
            d = json.loads(path.read_text())
            for tu in d["tus"]:
                stem = tu["file"].rsplit(".", 1)[0]
                for f in tu["functions"]:
                    out[f] = stem
            for f in d.get("unassigned_prefix", []):
                out[f] = "_prolog"
        self._tu_maps[module] = out
        return out

    def work_path(self, key: str) -> Path:
        """An agent's private working copy of a function's unit (never the tree)."""
        return STATE_DIR / "work" / (key.replace(":", "__") + ".c")

    def load_units(self) -> List[dict]:
        """units.json, parsed once per file version (every check used to re-read it)."""
        if not self.units_path.exists():
            return []
        stamp = self.units_path.stat().st_mtime_ns
        cache = self.__dict__.setdefault("_units_cache", None)
        if cache and cache[0] == stamp:
            return json.loads(cache[1])  # a fresh copy: callers mutate and save the list
        text = self.units_path.read_text()
        self.__dict__["_units_cache"] = (stamp, text)
        return json.loads(text)

    def unit_record(self, unit_source: str) -> Optional[dict]:
        """units.json entry for a split unit name (the `source` field), if configured."""
        stamp = self.units_path.stat().st_mtime_ns if self.units_path.exists() else None
        idx = self.__dict__.get("_units_index")
        if not idx or idx[0] != stamp:
            idx = (stamp, {u["source"]: u for u in self.load_units()})
            self.__dict__["_units_index"] = idx
        return idx[1].get(unit_source)

    def save_units(self, units: List[dict]) -> None:
        units.sort(key=lambda u: (u["module"], u["source"]))
        tmp = self.units_path.with_suffix(".json.tmp")
        tmp.write_text(json.dumps(units, indent=2) + "\n")
        os.replace(tmp, self.units_path)  # readers in other processes never see a partial file

    def objdiff_unit_name(self, module: str, source: str) -> str:
        return f"{module}/{source.rsplit('.', 1)[0]}"

    def objdiff_units(self) -> Dict[str, dict]:
        """Read-only object metadata, parsed once per actual file version."""
        path = ROOT / "objdiff.json"
        if not path.exists():
            return {}
        stat = path.stat()
        stamp = (stat.st_dev, stat.st_ino, stat.st_size, stat.st_mtime_ns, stat.st_ctime_ns)
        cached = self.__dict__.get('_objdiff_units_cache')
        if cached is None or cached[0] != stamp:
            units = {u["name"]: u for u in load_json_retry(path)["units"]}
            cached = (stamp, units)
            self.__dict__['_objdiff_units_cache'] = cached
        return cached[1]

    # ------------------------------------------------------------------ strings
    def string_at(self, module: str, name: str, max_len: int = 200) -> Optional[str]:
        """NUL-terminated printable string at a data symbol, read from the retail bytes.

        dtk sometimes emits string tables as raw .4byte words, so the disassembly is
        not a reliable source; the REL/DOL bytes are."""
        sym = self.symbols(module).get(name)
        if not sym or sym.kind != "object" or sym.section in (".bss", ".sbss", ".sbss2"):
            return None
        if module == 'main':
            region = next(((base, data) for base, data in self._rel_layout(module).values()
                           if base <= sym.addr < base + len(data)), None)
            if region is None:
                return None
            base, raw = region
        else:
            raw = self._raw_section(module, sym.section)
            base = self._section_base(module, sym.section)
        if raw is None:
            return None
        start = sym.addr - base
        if start < 0 or start >= len(raw):
            return None
        end = raw.find(b"\0", start, start + max_len)
        chunk = raw[start:end if end >= 0 else start + max_len]
        if len(chunk) < 2 or any(b < 9 or (13 < b < 32) or b > 126 for b in chunk):
            return None
        return chunk.decode("ascii", "replace")

    def bytes_at(self, module: str, name: str) -> Optional[bytes]:
        """Retail bytes of a data symbol (None for bss or unknown)."""
        sym = self.symbols(module).get(name)
        if not sym or sym.kind != "object" or sym.section in (".bss", ".sbss", ".sbss2"):
            return None
        if module == "main":
            # the DOL layout is by segment index, not section name: find the segment by address
            for base, data in self._rel_layout(module).values():
                if base <= sym.addr and sym.addr + sym.size <= base + len(data):
                    return data[sym.addr - base:sym.addr - base + sym.size]
            return None
        raw = self._raw_section(module, sym.section)
        if raw is None:
            return None
        start = sym.addr - self._section_base(module, sym.section)
        if start < 0 or start + sym.size > len(raw):
            return None
        return raw[start:start + sym.size]

    def _rel_layout(self, module: str):
        if not hasattr(self, "_layouts"):
            self._layouts = {}
        if module in self._layouts:
            return self._layouts[module]
        import struct as _struct
        cfg = (self.config_dir / "config.yml").read_text().splitlines()
        obj = None
        if module == "main":
            obj = next(l.split(":", 1)[1].strip() for l in cfg if l.startswith("object:"))
        else:
            for i, line in enumerate(cfg):
                if line.strip() == f"name: {module}":
                    obj = next(l.split(":", 1)[1].strip() for l in reversed(cfg[:i]) if l.startswith("- object:"))
                    break
        data = (ROOT / "orig" / self.version / obj).read_bytes() if obj else b""
        layout = {}
        if module != "main" and data:
            v = _struct.unpack(">16I", data[:0x40])
            names = {1: ".text", 2: ".ctors", 3: ".dtors", 4: ".rodata", 5: ".data"}
            for i in range(v[3]):
                o, sz = _struct.unpack(">II", data[v[4] + 8 * i: v[4] + 8 * i + 8])
                if sz and (o & ~3) and i in names:
                    layout[names[i]] = (0, data[o & ~3: (o & ~3) + sz])
        elif data:
            offs = _struct.unpack(">18I", data[0:0x48]); addrs = _struct.unpack(">18I", data[0x48:0x90])
            sizes = _struct.unpack(">18I", data[0x90:0xD8])
            for sec in self.splits(module) or []:
                pass
            for i in range(18):
                if sizes[i]:
                    layout[f"#{i}"] = (addrs[i], data[offs[i]: offs[i] + sizes[i]])
        self._layouts[module] = layout
        return layout

    def _raw_section(self, module: str, section: str) -> Optional[bytes]:
        layout = self._rel_layout(module)
        if section in layout:
            return layout[section][1]
        return None

    def _section_base(self, module: str, section: str) -> int:
        layout = self._rel_layout(module)
        return layout[section][0] if section in layout else 0

    # ------------------------------------------------------------------- misc
    @staticmethod
    def now() -> int:
        return int(time.time())

    @staticmethod
    def rel(path: Path) -> str:
        return os.path.relpath(path, ROOT)
