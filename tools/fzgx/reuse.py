"""Exact retail clone discovery and C binding for the shared fixup engine."""

from __future__ import annotations

import re
import hashlib
import shlex
import subprocess
from collections import defaultdict
from pathlib import Path
from typing import Optional

from . import oracle
from .ledger import Ledger
from .project import Project, ROOT, STATE_DIR


def replace_symbols(text: str, mapping: dict) -> str:
    if not mapping:
        return text
    names = "|".join(re.escape(n) for n in sorted(mapping, key=len, reverse=True))
    return re.sub(r"(?<![\w.$])(" + names + r")(?![\w.$])", lambda m: mapping[m[0]], text)


def shape(fn) -> tuple:
    # Preserve registers, immediates, relocation kinds, addends, and branch destinations.
    # Only names change; a shared global must remain shared at every reference site.
    names = {name: f"$S{i}" for i, name in enumerate(fn.refs)}
    labels = {line[:-1]: f"$L{i}" for i, line in enumerate(fn.asm) if line.endswith(":")}
    return tuple(replace_symbols(line.split(": ", 1)[-1], names | labels)
                 for line in fn.asm if not line.endswith(":"))


def families(p, max_size=None, module=None, symbol=None):
    ledger = Ledger()
    groups = defaultdict(list)
    for row in ledger.db.execute("SELECT symbol, module, status, size FROM functions "
                                 "WHERE status IN ('matched', 'unmatched') ORDER BY symbol"):
        key, mod, status, size = row
        if max_size is not None and size > max_size:
            continue
        fn = p.function_asm(mod).get(key.split(":")[-1])
        if fn is not None and fn.symbol.size == size and p.key(fn.symbol) == key:
            groups[shape(fn)].append(dict(symbol=key, module=mod, status=status, size=size))
    return [group for group in groups.values() if len(group) > 1 and any(
        r['status'] == 'unmatched' and (not module or r['module'] == module)
        and (not symbol or r['symbol'] == symbol) for r in group)]


def bindings(p, donor, recipient):
    a, b = p.function(donor), p.function(recipient)
    if a is None or b is None or shape(a) != shape(b):
        raise ValueError(f'{donor} and {recipient}: retail clone changed')
    return dict(zip(a.refs, b.refs)) | {a.symbol.name: b.symbol.name}


def rebind(body, mapping):
    from .sdkimport import replace_c_symbols
    return replace_c_symbols(body, mapping)


def declaration_closure(body):
    from .sdkimport import declarations, masked, IDENT, LEXICAL
    clean = re.sub(r'(?m)^[ \t]*#pragma[^\n]*', lambda m: ' '*len(m[0]), masked(body))
    spans=[]; start=depth=parens=0; function=False
    for i, char in enumerate(clean):
        if char == '(':
            parens += 1
        elif char == ')':
            parens -= 1
        elif char == '{':
            if depth == 0:
                prefix=clean[start:i].strip()
                function=bool(re.search(r'\)\s*$',prefix)) and '=' not in prefix
            depth += 1
        elif char == '}':
            depth -= 1
            if depth == 0 and function:
                spans.append((start,i+1,False));start=i+1;function=False
        elif char == ';' and depth == 0 and parens == 0:
            text=clean[start:i+1].lstrip()
            spans.append((start,i+1,text.startswith(('extern ', 'typedef ', 'struct ', 'union ', 'enum '))))
            start=i+1
    nodes=[]
    for start,end,removable in spans:
        pieces=declarations(clean[start:end])
        names=set().union(*(p.names for p in pieces))
        # A struct declaration may also define storage. Keep every definition;
        # only unused types and extern declarations can disappear here.
        removable=removable and bool(pieces) and all(p.kind=='type' or p.text.startswith('extern ') for p in pieces)
        nodes.append((start,end,removable,names,set(IDENT.findall(clean[start:end]))))
    selected={i for i,n in enumerate(nodes) if not n[2]}
    needed=set().union(*(nodes[i][4] for i in selected))
    while True:
        more={i for i,n in enumerate(nodes) if i not in selected and n[3] & needed}
        if not more:
            break
        selected.update(more)
        needed.update(set().union(*(nodes[i][4] for i in more)))
    for i,(start,end,_,_,_) in reversed(list(enumerate(nodes))):
        if i not in selected:
            text=body[start:end]
            # Keep licensing and compiler state; field-layout commentary leaves
            # with its unused declaration.
            retained=[(m.start(),m[0]) for m in LEXICAL.finditer(text)
                      if m[0].startswith(('/*','//')) and re.search(r'copyright|license|SPDX',m[0],re.I)]
            retained.extend((m.start(),m[0]) for m in re.finditer(r'(?m)^[ \t]*#pragma[^\n]*',text))
            body=body[:start]+'\n'+'\n'.join(t for _,t in sorted(retained))+'\n'+body[end:]
    return re.sub(r'\n(?:[ \t]*\n){2,}', '\n\n', body)


def preprocessed_text(data: bytes) -> str:
    """Keep raw multibyte literal bytes from MWCC -EP in ASCII C source.

    A Shift-JIS trail byte can be an ASCII backslash. Escape the complete
    multibyte pair before interpreting C escapes; decoding/re-encoding the
    compiler's output as UTF-8 would either fail or change the retail bytes.
    """
    out = bytearray()
    quote = None
    i = 0
    while i < len(data):
        byte = data[i]
        if quote is None:
            if byte in (34, 39):
                quote = byte
            elif byte >= 128:
                raise ValueError('MWCC emitted non-ASCII outside a literal')
            out.append(byte)
        elif byte == quote:
            out.append(byte)
            quote = None
        elif byte == 92:
            out.extend(data[i:i + 2])
            i += 1
        elif byte >= 128:
            out.extend(f'\\{byte:03o}'.encode('ascii'))
            if (0x81 <= byte <= 0x9F or 0xE0 <= byte <= 0xFC) and i + 1 < len(data):
                trail = data[i + 1]
                if 0x40 <= trail <= 0x7E or 0x80 <= trail <= 0xFC:
                    out.extend(f'\\{trail:03o}'.encode('ascii'))
                    i += 1
        else:
            out.append(byte)
        i += 1
    return out.decode('ascii')


class Declarations:
    """Expand owned headers without losing compiler pragmas or lint justifications."""
    def __init__(self, engine):
        self.engine = engine
        self.root = engine.output / 'declarations'
        self.root.mkdir(exist_ok=True)
        self.markers, self.includes, self.expanded = {}, {}, {}

    def protect(self, text):
        from .sdkimport import LEXICAL
        def marker(value):
            key = 'FZGX_PRESERVE_' + hashlib.sha256(value.encode()).hexdigest()
            self.markers[key] = value
            return key
        # Comments inside directives must remain whitespace: inserting a token
        # there could change a macro or an include filename.
        def comment(match):
            line = text[text.rfind('\n', 0, match.start()) + 1:match.start()]
            if not match[0].startswith(('//', '/*')) or line.lstrip().startswith('#'):
                return match[0]
            value = match[0]
            if value.startswith('//'):
                value = '/*' + value[2:] + ' */'
            return ' ' + marker(value) + ' '
        text = LEXICAL.sub(comment, text)
        # Keep the original directive for preprocessor option queries, and a
        # marker for compilation of the expanded source (-E drops pragmas).
        return re.sub(r'(?m)^[ \t]*#pragma[^\n]*', lambda m: m[0] + '\n' + marker(m[0]), text)

    def include(self, path):
        path = path.resolve()
        if path not in self.includes:
            if not path.is_relative_to(ROOT / 'include') and not path.is_relative_to(ROOT / 'build' / self.engine.project.version / 'include'):
                raise ValueError(f'clone declarations require an owned include directory: {path}')
            dest = self.root / hashlib.sha256(str(path).encode()).hexdigest()[:16]
            # Only the configured header roots, never the candidate corpus.
            for header in sorted(path.rglob('*')):
                if header.is_file():
                    output = dest / header.relative_to(path)
                    output.parent.mkdir(parents=True, exist_ok=True)
                    output.write_text(self.protect(header.read_text()))
            self.includes[path] = dest
        return self.includes[path]

    def expand(self, row):
        if row['id'] in self.expanded:
            return self.expanded[row['id']]
        body = Path(row['source']).read_text()
        if not re.search(r'(?m)^\s*#(?!pragma\b)', body):
            return declaration_closure(body)
        p = self.engine.project
        args = shlex.split(oracle.module_flags(p, p.resolve(row['symbol']).module)[0])
        extra = shlex.split(row['flags']); levels = [f for f in extra if f.startswith('-O')]
        args = [levels[-1] if levels and f.startswith('-O') else f for f in args]
        args += [f for f in extra if not f.startswith('-O')]
        for i, arg in enumerate(args[:-1]):
            if arg in ('-i', '-I'):
                args[i + 1] = str(self.include(ROOT / args[i + 1]))
        wrapper = self.root / (row['id'][:24] + '.c')
        wrapper.write_text(self.protect(body))
        cmd = [str(ROOT/'build/tools/wibo'), str(ROOT/'build/compilers'/row['mw']/'mwcceppc.exe'), *args, '-EP', str(wrapper)]
        result = subprocess.run(cmd, cwd=ROOT, capture_output=True, timeout=60)
        if result.returncode:
            diagnostic = (result.stdout + result.stderr).decode('utf-8', errors='backslashreplace')
            raise ValueError(diagnostic[-4000:])
        body = preprocessed_text(result.stdout)
        body = re.sub(r'FZGX_PRESERVE_[0-9a-f]{64}', lambda m: self.markers[m[0]], body)
        body = declaration_closure(body)
        self.expanded[row['id']] = body
        return body


def run(p: Project, max_size: int = 255, module: Optional[str] = None, do_submit: bool = True) -> dict:
    # Compatibility command; all compilation, scoring and integration is fixup's.
    from argparse import Namespace
    from .fixup import command
    return command(p, Namespace(clones=True, symbol=None, body=None, corpus=None,
        output=STATE_DIR/'fixup'/'reuse', captures=None, capture=False, replay=False,
        archive=None, saved=False, apply=do_submit, min_percent=100, max_percent=100,
        module=module, max_size=max_size, limit=None, rounds=0, beam=3,
        max_candidates=80, budget=None, drafts=False))
