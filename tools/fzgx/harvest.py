"""Harvest matched C from another ref of this project: a fork branch or a cloud-session branch.

A ref's `state/ledger.json` lists what it matched; for every function matched there and
unmatched here, the ref's C is tried under the ref's recorded compiler options, with the
ref's symbol names rebound to ours by (module, section, address):

  raw            the ref's unit text, includes resolving against this tree
  ours-prologue  the ref's block under this TU's prologue
  selective      the ref's unit with only the ref's headers missing here inlined; includes that
                 resolve here stay, so hardware/SDK declarations come from our own headers.
                 Compile errors are then repaired for a few rounds: `+swap` inlines the ref's
                 version of one of our headers that declares an identifier named in the error,
                 `+fix` injects a ref-only type definition, rewrites `sym` as `(T)&sym` where
                 the ref declares an array and we declare a struct, or gives a local the ref's
                 struct as `<Type>_dw` when our struct lacks a member
  preprocessed   the ref's unit expanded by MWCC -EP in the ref's own tree (pragmas kept)

Only full-oracle matches and pool matches that are also lint clean are submitted, through
claim/write_unit/submit, so every acceptance gate applies; `fzgx verify` still links and
checks all 16 hashes.
See docs/CLOUD.md.
"""
from __future__ import annotations

import hashlib
import json
import re
import shlex
import subprocess
import tarfile
import io
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import Dict, List, Optional

from . import api, oracle, reuse, tufile
from .lint import allocator_scaffolding, lint_file
from .ledger import Ledger
from .project import ROOT, STATE_DIR, Project

INC_RE = re.compile(r'^[ \t]*#[ \t]*include[ \t]*[<"]([^">]+)[">].*$', re.M)
BRACES = r'\{(?:[^{}]|\{(?:[^{}]|\{[^{}]*\})*\})*\}'
SYM_RE = re.compile(r'^(\S+)\s*=\s*(\.[\w.]+):0x([0-9A-Fa-f]+);')
PRAGMA_RE = re.compile(r'(?m)^[ \t]*#pragma[^\n]*')


def _git(*args: str) -> bytes:
    return subprocess.run(['git', *args], cwd=ROOT, check=True, capture_output=True).stdout


def export(ref: str) -> Path:
    """`src include config` of the ref, extracted once per commit under .fzgx/harvest/."""
    sha = _git('rev-parse', ref).decode().strip()
    tree = STATE_DIR / 'harvest' / sha[:12]
    if not (tree / '.complete').exists():
        tree.mkdir(parents=True, exist_ok=True)
        data = _git('archive', sha, 'src', 'include', 'config', 'state/ledger.json')
        tarfile.open(fileobj=io.BytesIO(data)).extractall(tree, filter='data')
        (tree / '.complete').write_text(sha + '\n')
    return tree


def fixup_imports(sha: str) -> Dict[str, dict]:
    """The ref's `state/repairs/fixup_imports.json`: deterministic-repair outputs with their
    compiler settings. A ref can hold an exact body there for a function its ledger no longer
    counts as matched (4 such on deltawave784/fzgx@13b0aeca)."""
    try:
        return json.loads(_git('show', f'{sha}:state/repairs/fixup_imports.json'))
    except (subprocess.CalledProcessError, ValueError):
        return {}


def gain(tree: Path) -> List[str]:
    theirs = json.loads((tree / 'state/ledger.json').read_text())['functions']
    ours = dict(Ledger().db.execute('SELECT symbol, status FROM functions'))
    sha = (tree / '.complete').read_text().strip()
    # Blocked functions are open work too: an exact body elsewhere is what unblocks them
    # (fn_80036AC4 matched on a fork branch while blocked here).
    open_here = ('unmatched', 'blocked')
    found = {r['symbol'] for r in theirs if r['status'] == 'matched' and ours.get(r['symbol']) in open_here}
    found |= {k for k, v in fixup_imports(sha).items() if v.get('generated_source') and ours.get(k) in open_here}
    # A ref's ledger snapshot can lag its commits; a unit is only created at submit, so a
    # matching unit in the ref's config is a match too (the oracle still decides here).
    units = tree / 'config/GFZE01/units.json'
    if units.exists():
        for u in json.loads(units.read_text()):
            if u.get('status') == 'matching' and not u.get('asm') and not u.get('data'):
                for name in u.get('symbols') or ():
                    key = name if name in ours else f"{u.get('module')}:{name}"
                    if ours.get(key) in open_here:
                        found.add(key)
    return sorted(found)


class Source:
    ROUNDS = 10

    def __init__(self, p: Project, tree: Path, workdir: Path, origin: str = 'fork'):
        self.p, self.tree, self.workdir, self.origin = p, tree, workdir, origin
        self.fixups = fixup_imports((tree / '.complete').read_text().strip())
        self.our_include = [ROOT / 'include', ROOT / 'build/GFZE01/include']
        self._headers: Optional[List[str]] = None
        self.units = {(u['module'], s): u for u in json.loads((tree / 'config/GFZE01/units.json').read_text())
                      for s in u.get('symbols', [])}
        self.blocks: Dict[tuple[str, str], Path] = {}
        for path in (tree / 'src').rglob('*.c'):
            parts = path.relative_to(tree / 'src').parts
            module = parts[1] if len(parts) > 1 and parts[0] == 'rel' else 'main'
            text = path.read_text(errors='replace')
            for m in re.finditer(r'^/\* fzgx:begin (\w+)', text, re.M):
                self.blocks.setdefault((module, m[1]), path)
        self._maps: Dict[str, Dict[str, str]] = {}

    @staticmethod
    def _symbols(root: Path, module: str) -> Dict[str, tuple]:
        path = root / 'config/GFZE01' / ('symbols.txt' if module == 'main' else f'{module}/symbols.txt')
        out = {}
        for ln in path.read_text().splitlines():
            m = SYM_RE.match(ln)
            if m:
                out[m[1]] = (m[2], int(m[3], 16))
        return out

    def name_map(self, module: str) -> Dict[str, str]:
        """Ref name -> our name wherever both trees name one address differently."""
        if module not in self._maps:
            theirs, ours = self._symbols(self.tree, module), self._symbols(ROOT, module)
            at = {v: k for k, v in ours.items()}
            local = {k: at[v] for k, v in theirs.items() if v in at and at[v] != k}
            self._maps[module] = local if module == 'main' else {**self.name_map('main'), **local}
        return self._maps[module]

    def rebind(self, body: str, module: str) -> str:
        used = {k: v for k, v in self.name_map(module).items() if k in body}
        return reuse.rebind(body, used) if used else body

    def unit_text(self, sym: str):
        s = self.p.resolve(sym)
        if s is None:
            return None, None
        key = (s.module, s.name)
        u = self.units.get(key) or {}
        for path in ([self.tree / 'src' / u['tu']] if u.get('tu') else []) + (
                [self.blocks[key]] if key in self.blocks else []):
            if path.exists():
                tf = tufile.parse(path.read_text(errors='replace'))
                if tf.get(s.name):
                    return tf, tufile.gen_text(tf, s.name)
        if u.get('source') and (self.tree / 'src' / u['source']).exists():
            return None, (self.tree / 'src' / u['source']).read_text(errors='replace')
        return None, None

    def preprocess(self, text: str, module: str, mw: str, flags: List[str], tag: str) -> str:
        base, _ = oracle.module_flags(self.p, module)
        base = base.replace('-i include', f'-i {self.tree}/include').replace(
            '-i build/GFZE01/include', f'-i {ROOT}/build/GFZE01/include')
        markers: Dict[str, str] = {}

        def keep(m):
            key = f'FZGX_PRAGMA_{len(markers)}_'
            markers[key] = m[0].strip()
            return m[0] + '\n' + key
        src = self.workdir / 'pp' / f'{tag.replace(":", "__")}.c'
        src.parent.mkdir(parents=True, exist_ok=True)
        src.write_text(PRAGMA_RE.sub(keep, text))
        cmd = [str(ROOT / 'build/tools/wibo'), str(ROOT / 'build/compilers' / mw / 'mwcceppc.exe'),
               *shlex.split(base), *flags, '-EP', str(src)]
        r = subprocess.run(cmd, cwd=self.tree, capture_output=True, timeout=120)
        if r.returncode:
            raise ValueError((r.stdout + r.stderr).decode(errors='replace')[-1500:])
        body = reuse.preprocessed_text(r.stdout)
        body = re.sub(r'(?m)^#line[^\n]*\n|^#\s*\d+[^\n]*\n', '', body)
        body = re.sub(r'(?m)^[ \t]*#pragma[^\n]*\n', '', body)
        body = re.sub(r'FZGX_PRAGMA_\d+_', lambda m: '\n' + markers[m[0]] + '\n', body)
        return reuse.declaration_closure(body)


    # -- selective inlining -------------------------------------------------------------
    def _ours(self, name: str) -> Optional[Path]:
        return next((d / name for d in self.our_include if (d / name).exists()), None)

    def expand(self, text: str, force: frozenset = frozenset(), seen: Optional[set] = None, depth: int = 0) -> str:
        """Inline the ref's headers that this tree lacks (and those in `force`); keep the rest."""
        seen = set() if seen is None else seen

        def repl(m):
            name = m[1]
            theirs = self.tree / 'include' / name
            if (self._ours(name) is not None and name not in force) or not theirs.exists() or depth > 12:
                return m[0]
            if name in seen:
                return f'/* {name}: inlined above */'
            seen.add(name)
            return (f'/* begin {name} ({self.origin}) */\n'
                    + self.expand(theirs.read_text(errors='replace'), force, seen, depth + 1) + f'\n/* end {name} */')
        return INC_RE.sub(repl, text)

    def _our_headers_in(self, text: str, seen: Optional[set] = None, depth: int = 0) -> set:
        seen = set() if seen is None else seen
        for name in INC_RE.findall(text):
            path = self._ours(name)
            if path is not None and name not in seen and depth < 12:
                seen.add(name)
                self._our_headers_in(path.read_text(errors='replace'), seen, depth + 1)
        return seen

    def differing_headers(self, text: str) -> frozenset:
        """Headers the ref's unit reaches whose ref text differs from ours, directly or through
        a header they include. Inlining exactly these reproduces the ref's declarations while
        identical headers (SDK, psvec.h, hw_regs.h) stay includes and keep their lint exemption."""
        reach: Dict[str, List[str]] = {}

        def walk(src: str, depth: int = 0):
            for name in INC_RE.findall(src):
                path = self.tree / 'include' / name
                if name in reach or not path.exists() or depth > 12:
                    continue
                body = path.read_text(errors='replace')
                reach[name] = INC_RE.findall(body)
                walk(body, depth + 1)
        walk(text)
        def code(path: Path) -> str:  # comments and layout never change a declaration
            text = re.sub(r'/\*.*?\*/|//[^\n]*', ' ', path.read_text(errors='replace'), flags=re.S)
            return ' '.join(text.split())
        differs = {n for n in reach if (o := self._ours(n)) is None
                   or code(o) != code(self.tree / 'include' / n)}
        changed = True
        while changed:
            changed = False
            for n, incs in reach.items():
                if n not in differs and any(i in differs for i in incs):
                    differs.add(n)
                    changed = True
        return frozenset(n for n in differs if self._ours(n) is not None)

    def clashing_headers(self, body: str, error: str, force: frozenset, pinned: frozenset = frozenset()) -> set:
        """Our headers (reached from the body) that the ref also has and that declare an
        identifier the compiler error names: the ref's version is what its C was written against.
        Headers our TU prologue includes are `pinned`: the generated unit includes ours first,
        so a swapped copy would clash there even when the standalone check passes."""
        idents = set(re.findall(r"'([A-Za-z_]\w*)'", error))
        out = set()
        for name in self._our_headers_in(body):
            if name in force or name in pinned or not (self.tree / 'include' / name).exists():
                continue
            text = self._ours(name).read_text(errors='replace')
            if any(re.search(rf'\b{re.escape(i)}\b', text) for i in idents):
                out.add(name)
        return out

    # -- declaration fixers -------------------------------------------------------------
    def definition(self, name: str) -> Optional[str]:
        """The ref's unique `typedef`/`struct` definition of `name`, if exactly one exists."""
        if self._headers is None:
            self._headers = [h.read_text(errors='replace') for h in (self.tree / 'include').rglob('*.h')]
        n = re.escape(name)
        for pat in (rf'typedef\s+(?:struct|union)\s*\w*\s*{BRACES}\s*{n}\s*;',
                    rf'typedef\s+[^;{{}}]*\b{n}\s*;',
                    rf'(?:struct|union)\s+{n}\s*{BRACES}\s*;'):
            hits = {m.group(0) for h in self._headers for m in re.finditer(pat, h)}
            if len(hits) == 1:
                return hits.pop()
        return None

    @staticmethod
    def trim(text: str) -> str:
        """Drop the inlined declarations the function never reaches (reuse.declaration_closure).
        Preprocessor lines become `#pragma` placeholders first, which the closure keeps verbatim:
        macros, include guards and includes survive. A trimmed body is only kept if it still
        matches, so a declaration used only inside a macro cannot be lost silently."""
        keep: List[str] = []

        def hide(m):
            keep.append(m[0])
            return f'#pragma FZGX_KEEP_{len(keep) - 1}'
        masked = re.sub(r'(?m)^[ \t]*#(?![ \t]*pragma\b)(?:[^\n]*\\\n)*[^\n]*', hide, text)
        # identifiers reached only through macros the code uses: seed them as one kept function
        macros = {m[1]: set(re.findall(r'[A-Za-z_]\w*', m[2])) for line in keep
                  if (m := re.match(r'\s*#\s*define\s+(\w+)(?:\([^)]*\))?(.*)', line, re.S))}
        used = set(re.findall(r'[A-Za-z_]\w*', masked)) & set(macros)
        while (more := set().union(*(macros[u] for u in used)) & set(macros) - used):
            used |= more
        seed = sorted(set().union(*(macros[u] for u in used)) - set(macros)) if used else []
        if seed:
            masked += '\nvoid FZGX_MACRO_USES(void) { ' + ' '.join(seed) + ' }\n'
        out = reuse.declaration_closure(masked)
        out = re.sub(r'\nvoid FZGX_MACRO_USES\(void\) \{[^}]*\}\n?', '\n', out)
        out = re.sub(r'#pragma FZGX_KEEP_(\d+)', lambda m: keep[int(m[1])], out)
        # an include guard or #if left with nothing inside is noise
        for _ in range(3):
            out = re.sub(r'(?m)^[ \t]*#[ \t]*if(?:n?def)?\b[^\n]*\n(?:[ \t]*#[ \t]*define[ \t]+\w+[ \t]*\n)?\s*^[ \t]*#[ \t]*endif[^\n]*\n?', '', out)
            out = re.sub(r'/\* begin (\S+) \([^)]*\) \*/\s*/\* end \1 \*/\n?', '', out)
        return re.sub(r'\n(?:[ \t]*\n){2,}', '\n\n', out)

    @staticmethod
    def _after_includes(text: str, chunk: str) -> str:
        last = max((x.end() for x in re.finditer(r'^[ \t]*#[ \t]*include[^\n]*\n', text, re.M)), default=0)
        return text[:last] + chunk + text[last:]

    def fix(self, text: str, error: str) -> Optional[tuple]:
        """One repair step for a compile error, or None. Returns (new text, description)."""
        m = re.search(r'#\s+(\d+):\s?(.*)\n#\s+Error:\s?( *)(\^+)', error)
        ln, code, col = (int(m[1]), m[2], len(m[3])) if m else (None, None, None)
        lines = text.splitlines()
        if ln is not None and not (0 < ln <= len(lines) and code.strip() and code.strip() in lines[ln - 1]):
            ln = None  # the error is in a header, not in this text
        red = re.search(r"identifier '(\w+)' redeclared", error)
        if red and ln and re.match(rf'\s*extern\b[^;(]*\b{red[1]}\b[^;(]*;\s*$', lines[ln - 1]):
            del lines[ln - 1]  # this tree's declaration stays; later errors are conversions
            return '\n'.join(lines) + '\n', f'redecl {red[1]}'
        und = re.search(r"undefined identifier '(\w+)'", error)
        if und and (d := self.definition(und[1])):
            return self._after_includes(text, f'/* {und[1]}: from {self.origin} */\n{d}\n'), f'type {und[1]}'
        conv = re.search(r"illegal (?:implicit|explicit) conversion from 'struct [^']*' to\s*#?\s*'([^']+)'", error)
        if conv and ln:
            target, line = conv[1].strip(), lines[ln - 1]
            hits = sorted(re.finditer(r'(?<![&\w.>])(lbl_\w+|[A-Za-z_]\w*_data_\w+)\b(?!\s*\()', line),
                          key=lambda x: abs(x.start() - col))
            if hits:
                h = hits[0]
                lines[ln - 1] = line[:h.start()] + f'(({target})&{h[1]})' + line[h.end():]
                return '\n'.join(lines) + '\n', f'conv {h[1]} -> {target}'
        mem = re.search(r"'(\w+)' is not a struct/union/class member", error)
        if mem and ln:
            mm = re.search(rf'(\w+)\s*(?:->|\.)\s*{mem[1]}\b', lines[ln - 1])
            decl = mm and re.search(rf'\b(\w+)\s*\*\s*{mm[1]}\b\s*[=;,)]', text)
            if decl and (d := self.definition(decl[1])):
                t, nt, var = decl[1], decl[1] + '_dw', mm[1]
                text = re.sub(rf'\b{t}(\s*\*\s*{var}\b)', rf'{nt}\1', text)
                text = re.sub(rf'\({t}\s*\*\)(\s*&?\s*\w+)', lambda x: f'({nt} *){x[1]}', text)
                renamed = re.sub(rf'\b{t}\b', nt, d)
                text = self._after_includes(text, f'/* {t} as {self.origin} declares it */\n{renamed}\n')
                return text, f'member {var}: {t}_dw'
        return None

    def _try(self, sym: str, kind: str, body: str, mw: str, flags: List[str], prologue: Optional[str] = None):
        if prologue is not None:
            # tufile.splice hoists every include line to the top of the block: check that form,
            # or an include kept after inlined ref headers compiles differently in the link
            inc, rest = tufile.split_includes(body)
            body = ('\n'.join(inc) + '\n\n' + rest) if inc else rest
        # Qualified REL keys belong in metadata; ':' is not a Windows filename.
        f = self.workdir / 'bodies' / f'{sym.replace(":", "__")}.{kind}.c'
        f.parent.mkdir(parents=True, exist_ok=True)
        f.write_text(body)
        r = oracle.check(self.p, sym, 0, source=f, mw_version=mw, extra_cflags=shlex.join(flags))
        lint = [list(x) for x in lint_file(f)]
        if allocator_scaffolding(body):
            lint.append(['scaffolding', 0, 'allocator-only scaffolding'])
        rec = dict(kind=kind, percent=r.percent, matched=r.matched, pool=r.matched_pool, body=str(f),
                   mw=r.mw_version or mw, flags=r.extra_cflags if r.extra_cflags is not None else shlex.join(flags),
                   error=(r.error or '')[-300:], lint=lint, lines=body.count('\n'))
        if prologue is not None and (r.matched or r.matched_pool):
            rec['gen'] = self._gen_check(sym, kind, body, prologue, rec)
        return r, rec

    def _gen_check(self, sym: str, kind: str, body: str, prologue: str, rec: dict) -> str:
        """The block as its generated unit compiles it (tufile.splice): our TU prologue, then the
        body without the includes the prologue already has. A compile error is fine (`_install`
        then keeps the block self-contained); compiling to different code is not."""
        inc, rest = tufile.split_includes(body)
        have = {ln.strip() for ln in prologue.splitlines()}
        inc = [ln for ln in inc if ln.strip() not in have]
        g = self.workdir / 'bodies' / f'{sym.replace(":", "__")}.{kind}.gen.c'
        g.write_text(prologue + '\n' + ('\n'.join(inc) + '\n\n' if inc else '') + rest)
        r = oracle.check(self.p, sym, 0, source=g, mw_version=rec['mw'], extra_cflags=rec['flags'])
        if not r.ok:
            return 'compile-error'
        return 'match' if (r.matched or r.matched_pool) == (rec['matched'] or rec['pool']) and r.matched == rec['matched'] else 'mismatch'

    def tidy(self, text: str, lint: List[list], module: str) -> Optional[str]:
        """Mechanical repairs for a matching body that only fails lint (measured on the 2026-10-22
        deltawave784 harvest, 7 functions): retail pool words such as 0xC0A00000 (-5.0f) read as
        addresses, OS/GX absolute objects a preprocessed ref header spelled as literals, the
        banned `(void) x;` keep-alive, and interior data labels the ref named as objects. The
        oracle and lint still decide; nothing here is accepted on its own."""
        lines = text.splitlines()
        flagged = {ln for code, ln, _ in lint if code == 'A1' and ln}
        addrs = {}
        hdr = ROOT / 'build/GFZE01/include/sdk_addresses.h'
        if hdr.exists():
            for m in re.finditer(r'#define (FZGX_ADDR_\w+) (0x[0-9A-Fa-f]+)', hdr.read_text()):
                addrs.setdefault(int(m[2], 16), m[1])
        out, used_addr = [], False
        for i, line in enumerate(lines, 1):
            if 'fzgx: keeps the web at its definition' in line:
                continue
            m = re.fullmatch(r'(\s*(?:volatile\s+)?[\w ]+?\s+\w+\s*:\s*)(0x[0-9A-Fa-f]+)u?\s*;\s*', line)
            if m and int(m[2], 16) in addrs:
                if 'volatile' in line:
                    out.append('/* hardware register: every access must reach it */')
                out.append(f'{m[1]}{addrs[int(m[2], 16)]};')
                used_addr = True
                continue
            data = line.split('/*')[0]
            data = re.sub(r'^\s*(?:static\s+)?(?:const\s+)?u32\s+\w+\[\w*\]\s*=\s*', '', data)
            if i in flagged and 'fzgx-allow' not in line and re.fullmatch(
                    r'[\s{]*(?:(?:\(u32\)\w+|0x[0-9A-Fa-f]+|\d+)\s*,?\s*)+[}\s;,]*', data):
                line += '  /* fzgx-allow: A1 retail pool bytes */'
            out.append(line)
        text = '\n'.join(out) + '\n'
        if used_addr and 'sdk_addresses.h' not in text:
            text = '#include "sdk_addresses.h"\n' + text
        syms = self.p.symbols(module)
        objs = sorted(((x.addr, x) for x in syms.values() if x.section in ('.data', '.rodata', '.bss')), key=lambda e: e[0])

        def interior(m):
            name = m[0]
            if name in syms:
                return name
            sec, addr = m[1], int(m[2], 16)
            owner = next((x for a, x in reversed(objs) if x.section == '.' + sec and a < addr < x.end), None)
            return f'{owner.name}__fzgx_offset_{addr - owner.addr:X}' if owner else name
        # .data/.rodata pools bind only through retail names; .bss layouts keep their own names
        text = re.sub(r'\blbl_\d+_(data|rodata)_([0-9A-F]+)\b(?!__)', interior, text)
        return text

    @staticmethod
    def _rank(rec: dict) -> tuple:
        clean = not rec['lint'] and rec.get('gen') != 'mismatch'
        return (clean and rec['matched'], clean and rec['pool'], rec['matched'] or rec['pool'], rec['percent'],
                -rec.get('lines', 0))

    def screen(self, sym: str) -> dict:
        s = self.p.resolve(sym)
        if s is None:
            return dict(symbol=sym, status='unknown-here')
        module = s.module
        u = self.units.get((module, s.name)) or {}
        mw = u.get('mw_version') or oracle.module_flags(self.p, module)[1]
        flags = list(u.get('extra_cflags') or [])
        ftf, ftext = self.unit_text(sym)
        fixup = (self.fixups.get(sym) or {}) if (self.fixups.get(sym) or {}).get('generated_source') else None
        if ftext is None and fixup is None:
            return dict(symbol=sym, module=module, size=s.size, status='no-source')
        tried: List[dict] = []
        best: Optional[dict] = None
        ours_tu = tufile.tu_source_for(self.p, s)
        has_tu = bool(ours_tu and tufile.tu_path(self.p, ours_tu).exists())
        prologue = tufile.load(self.p, ours_tu).prologue if has_tu else None

        def attempt(kind: str, body: str, cc: Optional[str] = None, cflags: Optional[List[str]] = None):
            nonlocal best
            try:
                r, rec = self._try(sym, kind, body, cc or mw, flags if cflags is None else cflags, prologue)
            except Exception as error:  # a broken candidate never stops the harvest
                tried.append(dict(kind=kind, error=str(error)[-300:]))
                return None, False
            tried.append(rec)
            if best is None or self._rank(rec) > self._rank(best):
                best = rec
            return r, bool(r.matched and self._rank(rec)[0])

        def done():
            return best is not None and bool(self._rank(best)[0])

        if fixup is not None:
            attempt('fixup-import', self.rebind(fixup['generated_source'], module),
                    fixup.get('compiler'), shlex.split(fixup.get('flags') or ''))
        if ftext is None or done():
            firsts = []
        else:
            firsts = [('raw', lambda: self.rebind(ftext, module))]
        if firsts and ftf is not None and has_tu:
            firsts.append(('ours-prologue', lambda: prologue + '\n'
                           + self.rebind(ftf.get(s.name).body, module)))
        for kind, make in firsts:
            try:
                body = make()
            except Exception as error:
                tried.append(dict(kind=kind, error=str(error)[-300:]))
                continue
            if attempt(kind, body)[1]:
                break
        pinned = frozenset(self._our_headers_in(prologue)) if has_tu else frozenset()

        def chain(base: str, start: frozenset, swaps: bool):
            force, text, fixes = start, None, []
            for _ in range(self.ROUNDS):
                body = text if text is not None else self.rebind(self.expand(ftext, force), module)
                kind = base + ('+swap' if force != start else '') + ('+fix' if fixes else '')
                r, _ok = attempt(kind, body)
                if r is None:
                    return
                tried[-1].update(swapped=sorted(force - start), fixes=list(fixes))
                if r.ok:
                    if (r.matched or r.matched_pool) and '/* begin ' in body:
                        attempt(kind + '+trim', self.trim(body))
                    return
                culprits = (self.clashing_headers(body, r.error or '', force, pinned)
                            if swaps and text is None else set())
                if culprits:
                    force = force | frozenset(culprits)
                    continue
                step = self.fix(body, r.error or '')
                if step is None:
                    return
                text = step[0]
                fixes.append(step[1])

        if ftext is not None and not done():
            chain('selective', frozenset(), True)
        if ftext is not None and not done():
            differing = self.differing_headers(ftext)
            if differing:
                chain('fork-headers', differing, False)
        if ftext is not None and not done():
            try:
                attempt('preprocessed', self.rebind(self.preprocess(ftext, module, mw, flags, sym), module))
            except Exception as error:
                tried.append(dict(kind='preprocessed', error=str(error)[-300:]))
        if best is not None and not done() and best['percent'] >= 90:
            try:
                tidy = self.tidy(Path(best['body']).read_text(), best['lint'], module)
            except Exception as error:
                tidy = None
                tried.append(dict(kind=best['kind'] + '+tidy', error=str(error)[-300:]))
            if tidy is not None:
                attempt(best['kind'] + '+tidy', tidy, best['mw'], shlex.split(best['flags'] or ''))
        if best is None:
            status = 'failed'
        elif (best['matched'] or best['pool']) and not any(self._rank(best)[:2]):
            status = 'lint' if best['lint'] else 'gen-mismatch'
        else:
            status = 'matched' if best['matched'] else 'pool' if best['pool'] else 'partial'
        return dict(symbol=sym, module=module, size=s.size, status=status, best=best, tried=tried)


def _retrying(fn, *a, **k):
    """`fzgx verify` holds submit.lock for minutes while it links; wait it out."""
    for _ in range(40):
        try:
            return fn(*a, **k)
        except TimeoutError:
            time.sleep(30)
    return fn(*a, **k)


def land(p: Project, results: List[dict], agent: str, label: str, provenance: Path,
         skip: frozenset = frozenset()) -> dict:
    prov = json.loads(provenance.read_text()) if provenance.exists() else {}
    ledger = Ledger()
    # provenance lists link-verified landings only: drop what `fzgx verify` rejected since
    status = dict(ledger.db.execute('SELECT symbol, status FROM functions'))
    prov = {k: v for k, v in prov.items() if status.get(k) == 'matched'}
    todo = sorted((r for r in results if r['status'] in ('matched', 'pool')
                   and r['symbol'] not in prov and r['symbol'] not in skip),
                  key=lambda r: (r['status'] != 'matched', r['size']))
    landed, failed = [], []
    for r in todo:
        sym, b = r['symbol'], r['best']
        body = Path(b['body']).read_text()
        row = ledger.get(p.key(p.resolve(sym)))
        if row and row['status'] == 'matched':
            continue
        try:
            c = _retrying(api.claim, p, sym, agent, max_attempts=999)
            if not c.get('ok'):
                failed.append(dict(symbol=sym, stage='claim', error=c.get('error')))
                continue
            w = _retrying(api.write_unit, p, sym, agent, body)
            if not w.get('ok'):
                _retrying(api.release, p, sym, 'harvest: write failed', agent=agent)
                failed.append(dict(symbol=sym, stage='write', error=w.get('error')))
                continue
            s = _retrying(api.submit, p, sym, agent=agent, message=f'harvest {sym} from {label}', harness='harvest',
                          model=label, mw_version=b.get('mw'), extra_cflags=b.get('flags') or '')
        except Exception as error:
            failed.append(dict(symbol=sym, stage='error', error=f'{type(error).__name__}: {error}'[:300]))
            try:
                _retrying(api.release, p, sym, 'harvest: error', agent=agent, save_only=True)
            except Exception:
                pass
            continue
        if s.get('ok'):
            prov[sym] = dict(source=label, kind=b['kind'], status=r['status'], mw=b.get('mw'), flags=b.get('flags'),
                             sha256=hashlib.sha256(body.encode()).hexdigest(), landed=int(time.time()))
            provenance.parent.mkdir(parents=True, exist_ok=True)
            provenance.write_text(json.dumps(prov, indent=1, sort_keys=True) + '\n')
            landed.append(sym)
        else:
            failed.append(dict(symbol=sym, stage='submit', error=str(s.get('error') or s)[:300]))
            try:
                _retrying(api.release, p, sym, 'harvest: submit failed', agent=agent, save_only=True)
            except Exception as error:
                failed[-1]['release'] = str(error)
    return dict(landed=len(landed), failed=failed)


def run(p: Project, ref: str, label: Optional[str] = None, do_land: bool = False,
        workers: int = 4, limit: Optional[int] = None, symbols: Optional[List[str]] = None) -> dict:
    tree = export(ref)
    sha = (tree / '.complete').read_text().strip()
    label = label or f'{ref}@{sha[:8]}'
    workdir = STATE_DIR / 'harvest' / (sha[:12] + '-work')
    syms = symbols or gain(tree)
    syms = sorted(syms, key=lambda k: getattr(p.resolve(k), 'size', 0))[:limit] if limit else syms
    src = Source(p, tree, workdir, origin=label)
    with ThreadPoolExecutor(workers) as ex:
        results = list(ex.map(src.screen, syms))
    path = workdir / 'results.json'  # merged by symbol: a --symbol rerun keeps the rest
    path.parent.mkdir(parents=True, exist_ok=True)
    merged = {r['symbol']: r for r in (json.loads(path.read_text()) if path.exists() else [])}
    merged.update((r['symbol'], r) for r in results)
    path.write_text(json.dumps(list(merged.values()), indent=1))
    counts: Dict[str, int] = {}
    for r in results:
        counts[r['status']] = counts.get(r['status'], 0) + 1
    out = dict(ref=ref, sha=sha, candidates=len(syms), screened=counts, results=str(workdir / 'results.json'))
    if do_land:
        owner = re.sub(r'[^\w.-]+', '-', label.split('@')[0].split('/')[0]).strip('-') or 'harvest'
        out['land'] = land(p, results, f'harvest-{owner}', label, ROOT / 'state/forkimports' / f'{owner}.json')
    return out
