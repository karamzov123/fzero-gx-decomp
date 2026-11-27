#!/usr/bin/env python3
"""Measure the recompilation-scope requirements (docs/RECOMPILATION_SCOPE.md, R1-R7), USA GFZE01.

  python3 tools/scope_metrics.py [--rev REV] [--json]

Reads the working tree, or any git revision with --rev (nothing is checked out), so two points in
history are measured with the same definitions. Each measure is a plain count over committed
files; the definitions are the patterns below, not hand counts.
"""
import argparse, collections, json, re, subprocess, sys

VERSION = 'GFZE01'
INTRINSICS = ('cntlzw rlwinm rlwimi rlwnm fabs fnabs frsqrte fres fsel sync isync eieio lhbrx lwbrx '
              'sthbrx stwbrx dcbf dcbst dcbt dcbz dcbi icbi mfspr mtspr setflm mulhw mulhwu abs labs').split()
PATTERNS = {
    'hw_literals': re.compile(r'\b0x(?:CC|cc|E0|e0)00[0-9A-Fa-f]{4}\b'),
    'intrinsics': re.compile(r'\b__(?:' + '|'.join(INTRINSICS) + r')\s*\('),
    'addr_to_int': re.compile(r'\(\s*(?:u32|s32|int|unsigned int|unsigned long|long)\s*\)\s*&'),
    'unk_views': re.compile(r'\*\s*\(\s*[A-Za-z_]\w*\s*\*+\s*\)\s*&[^;]*?\bunk_'),
    'devices': re.compile(r'WARNING: compiler-diff device'),
    'pragma_setters': re.compile(r'^\s*#pragma\s+(?:opt_\w+|optimization_level|scheduling|peephole|'
                                 r'global_optimizer|optimize_for_size|fp_contract|inline_depth|auto_inline)'
                                 r'\s+(?:on|off|\d+)\b', re.M),
    'scaffolding': re.compile(r'\b(?:fzgx_obj_\w+|\w+__fzgx_offset_\w+)'),
    'primer': re.compile(r'\.fzgxpool'),
    'noprologue': re.compile(r'/\* fzgx:begin \S+ noprologue'),
}


class Tree:
    def __init__(self, rev):
        self.rev = rev

    def files(self, prefix):
        if self.rev:
            out = subprocess.run(['git', 'ls-tree', '-r', '--name-only', self.rev, '--', prefix],
                                 capture_output=True, text=True, check=True).stdout
        else:
            out = subprocess.run(['git', 'ls-files', '--', prefix], capture_output=True, text=True, check=True).stdout
            out += subprocess.run(['git', 'ls-files', '--others', '--exclude-standard', '--', prefix],
                                  capture_output=True, text=True).stdout
        return [l for l in out.splitlines() if l]

    def read(self, path):
        if self.rev:
            r = subprocess.run(['git', 'show', f'{self.rev}:{path}'], capture_output=True)
            return r.stdout.decode('utf-8', 'replace') if r.returncode == 0 else None
        try:
            return open(path, encoding='utf-8', errors='replace').read()
        except OSError:
            return None


def measure(tree):
    units = json.loads(tree.read(f'config/{VERSION}/units.json'))
    usa = [u for u in units if u.get('status') == 'matching' and VERSION in u.get('matching_for', [VERSION])]
    code = [u for u in usa if not u.get('data')]
    m = collections.OrderedDict()
    m['code_units'] = len(code)
    m['code_units_by_module'] = dict(collections.Counter(u['module'] for u in code).most_common())
    m['asm_units'] = sum(1 for u in code if u.get('asm'))
    m['data_units'] = sum(1 for u in usa if u.get('data'))
    m['pool_remapped_units'] = sum(1 for u in code if u.get('pool'))
    # R1: REL TU files and how many build as one unit
    per_tu = collections.Counter(u['tu'] for u in code if u.get('tu'))
    m['rel_tu_files'] = len(per_tu)
    m['rel_tu_files_one_unit'] = sum(1 for n in per_tu.values() if n == 1)
    # TU maps: mapped functions per executable
    mapped = 0
    for p in tree.files(f'config/{VERSION}'):
        if p.endswith('/tus.json'):
            d = json.loads(tree.read(p)); mapped += sum(len(t['functions']) for t in d['tus'])
    dol = tree.read(f'state/tumap/{VERSION}_main.json')
    m['rel_tus_json'] = sum(1 for p in tree.files(f'config/{VERSION}') if p.endswith('/tus.json'))
    m['rel_mapped_functions'] = mapped
    if dol:
        d = json.loads(dol)
        m['dol_map_tus'] = len(d['tus'])
        m['dol_mapped_functions'] = sum(len(t['functions']) for t in d['tus'])
        tu_of = {f: t['file'] for t in d['tus'] for f in t['functions']}
        dol_units = collections.Counter()
        for u in code:
            if u['module'] == 'main':
                for t in {tu_of.get(s) for s in u['symbols']} - {None}:
                    dol_units[t] += 1
        m['dol_tus_one_unit'] = sum(1 for n in dol_units.values() if n == 1)
        m['dol_tus_with_units'] = len(dol_units)
    # source-pattern counts
    counts = collections.Counter(); files = collections.Counter()
    for path in tree.files('src'):
        if not path.endswith(('.c', '.h', '.cpp')):
            continue
        text = tree.read(path) or ''
        rel = path.startswith('src/rel/')
        for k, pat in PATTERNS.items():
            if k in ('hw_literals', 'intrinsics', 'addr_to_int', 'unk_views') and not rel:
                continue
            if k == 'scaffolding':
                continue
            n = len(pat.findall(text))
            counts[k] += n; files[k] += bool(n)
    names = set()
    for path in tree.files('src'):
        if path.endswith('.c'):
            names |= set(PATTERNS['scaffolding'].findall(tree.read(path) or ''))
    m.update({k: counts[k] for k in PATTERNS if k != 'scaffolding'})
    m['primer_files'] = files['primer']
    m['scaffolding_names'] = len(names)
    syms = [s for u in code for s in u['symbols']]
    m['functions_in_units'] = len(syms)
    m['fn_named'] = sum(1 for s in syms if re.match(r'fn_[0-9A-Fa-f_]+$', s))
    return m


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--rev'); ap.add_argument('--json', action='store_true')
    a = ap.parse_args()
    m = measure(Tree(a.rev))
    if a.json:
        print(json.dumps(m, indent=1)); return
    for k, v in m.items():
        print(f'{k:24s} {v}')


if __name__ == '__main__':
    sys.exit(main())
