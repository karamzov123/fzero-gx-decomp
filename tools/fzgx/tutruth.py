"""One truth per symbol for a TU file.

A block matched under whatever declarations it wrote; blocks disagree, and a single-TU
compile rejects the second spelling of any symbol. The truth of a function is its matched
definition (its own code proves the parameter types), else a header, else the prologue, else
the most common spelling. A block that declared other parameter types keeps its code by
casting each argument to the type it relied on (`fn((u8)x, y, (u8)z)`): the conversion the
old prototype implied is now explicit. Every rewritten block is re-verified under the new
prologue; a block that no longer matches is reverted and reported.
"""
from __future__ import annotations

import re
from pathlib import Path
from collections import Counter, OrderedDict
from typing import Dict, List, Optional, Tuple

from . import oracle, reconcile, tufile, tutidy
from .project import ROOT, STATE_DIR, Project

SCALAR = {'void', 'int', 'char', 'short', 'long', 'unsigned', 'signed', 'float', 'double',
          's8', 'u8', 's16', 'u16', 's32', 'u32', 's64', 'u64', 'f32', 'f64', 'BOOL', 'size_t'}
PROTO_RE = re.compile(r'^\s*(?:extern\s+)?(.*?)\b([A-Za-z_]\w*)\s*\(([^()]*)\)\s*(?:,|;)')


def _sig(decl: str) -> Optional[Tuple[str, str, List[str]]]:
    """(return type, name, [parameter types]) of a prototype line, or None for data."""
    m = PROTO_RE.match(decl.strip())
    if not m:
        return None
    ret = re.sub(r'\s+', ' ', m.group(1)).strip()
    params = []
    inner = m.group(3).strip()
    if inner and inner != 'void':
        for part in inner.split(','):
            part = part.strip()
            if part == '...':
                params.append('...')
                continue
            # drop the parameter name: the last identifier not followed by '*' or a type word
            t = re.sub(r'\b([A-Za-z_]\w*)\s*$', lambda mm: '' if mm.group(1) not in SCALAR else mm.group(1), part).strip()
            params.append(re.sub(r'\s+', ' ', t))
    return ret, m.group(2), params


def _same(a: str, b: str) -> bool:
    n = lambda s: re.sub(r'\s+', '', s).replace('int', 's32').replace('const', '')
    return n(a) == n(b)


def project_definition(p: Project, name: str) -> Optional[str]:
    """`extern <signature>;` of the project's matched definition of `name`, if any."""
    pat = re.compile(r'^((?:[A-Za-z_][\w\s\*]*?)\b' + re.escape(name) + r'\s*\(([^;{}()]*)\))\s*\{', re.M)
    for f in sorted((ROOT / 'src').rglob('*.c')):
        text = f.read_text()
        if name not in text:
            continue
        m = pat.search(text)
        if m:
            return 'extern ' + re.sub(r'\s+', ' ', m.group(1)).strip() + ';'
    return None


def split_args(text: str, start: int) -> Optional[Tuple[List[Tuple[int, int]], int]]:
    """Top-level argument spans of the call whose '(' is at `start`; returns (spans, end)."""
    depth = 0
    spans = []
    a = start + 1
    i = start
    while i < len(text):
        c = text[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
            if depth == 0:
                if text[a:i].strip():
                    spans.append((a, i))
                return spans, i
        elif c == ',' and depth == 1:
            spans.append((a, i))
            a = i + 1
        elif c == '"':
            i += 1
            while i < len(text) and text[i] != '"':
                i += 2 if text[i] == '\\' else 1
        i += 1
    return None


INTS = {'s8', 'u8', 's16', 'u16', 's32', 'u32', 'int', 'char', 'short', 'long', 'unsigned', 'signed', 'BOOL', 'size_t'}


def cast_calls(body: str, name: str, old: List[str], new: List[str], force: bool = False) -> str:
    """Wrap every argument whose old declared type differs from the truth's in a cast to the
    old type, so the conversion the block's prototype implied stays in the code."""
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue  # a declaration, not a call
        res = split_args(body, m.end() - 1)
        if not res:
            continue
        spans, end = res
        if body[end + 1:].lstrip().startswith('{'):
            continue  # the definition
        if len(spans) != len(old) or len(old) != len(new):
            continue
        text = out
        for (a, b), t_old, t_new in reversed(list(zip(spans, old, new))):
            if t_old == '...' or t_new == '...' or _same(t_old, t_new):
                continue
            if not t_old.split() or not t_new.split():
                continue  # an unparsed (empty) parameter type: nothing to cast to (winning.c crashed here)
            if not force and t_old.split()[-1] in INTS and t_new.split()[-1] in INTS:
                continue  # integer widening/sign at the call is the parameter's own conversion
            arg = text[a:b].strip()
            castable = '*' in t_old or t_old.split()[-1] in SCALAR
            if not castable:
                if t_new.split()[-1] in SCALAR and '*' not in t_new:
                    text = text[:a] + f' ({t_new})({arg})' + text[b:]
                continue
            if re.fullmatch(r'\(\s*' + re.escape(t_old) + r'\s*\)\s*.*', arg):
                if '*' in t_new or (t_new.split()[-1] in SCALAR and '*' in t_old):
                    text = text[:a] + f' ({t_new})({arg})' + text[b:]  # already cast to the old type
                continue
            if '*' in t_new or (t_new.split()[-1] in SCALAR and '*' in t_old):
                text = text[:a] + f' ({t_new})({t_old})({arg})' + text[b:]  # the truth's type outermost
            else:
                text = text[:a] + f' ({t_old})({arg})' + text[b:]
        out = text
    return out


def join_declarations(body: str) -> str:
    """A declaration continued over several lines becomes one line."""
    out = []
    buf = None
    for ln in body.splitlines():
        if buf is not None:
            buf += ' ' + ln.strip()
            if ln.rstrip().endswith(';'):
                out.append(buf)
                buf = None
            continue
        if re.match(r'^\s*(?:extern\s+)?[A-Za-z_][\w \*]*\b[A-Za-z_]\w*\s*\([^;{}]*,\s*$', ln) or (re.match(r'^\s*extern\b[^;{}]*$', ln) and not ln.rstrip().endswith(';')):
            buf = ln.rstrip()
            continue
        out.append(ln)
    if buf is not None:
        out.append(buf)
    return '\n'.join(out) + ('\n' if body.endswith('\n') else '')


def split_multi(body: str) -> str:
    """`extern void a(...), b(...);` becomes one declaration line per prototype."""
    out = []
    for ln in body.splitlines():
        m = re.match(r'^(\s*(?:extern\s+)?[A-Za-z_][^(;=]*?)\b([A-Za-z_]\w*)\s*\(([^()]*)\)\s*,\s*(.*);\s*$', ln)
        if m and re.search(r'\b[A-Za-z_]\w*\s*\([^()]*\)', m.group(4)):
            head = m.group(1)
            protos = re.findall(r'(\**\s*[A-Za-z_]\w*\s*\([^()]*\))', m.group(2) + '(' + m.group(3) + '), ' + m.group(4))
            for pr in protos:
                out.append(f'{head.rstrip()} {pr.strip()};')
            continue
        out.append(ln)
    return '\n'.join(out) + ('\n' if body.endswith('\n') else '')


def private_type_names(body: str) -> set:
    """Names of the types a block defines: struct/union typedefs and tags, function-pointer
    typedefs and plain aliases."""
    names = set(re.findall(r'\}\s*([A-Za-z_]\w*)\s*;', body, re.M))
    names |= set(re.findall(r'^(?:typedef\s+)?(?:struct|union)\s+([A-Za-z_]\w*)\s*\{', body, re.M))
    names |= set(re.findall(r'^typedef\s+[^;{}]*?\(\s*\*\s*([A-Za-z_]\w*)\s*\)\s*\([^;]*\)\s*;', body, re.M))
    names |= set(re.findall(r'^typedef\s+(?!struct\b|union\b|enum\b)[^;{}()\[]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*;', body, re.M))
    return names - {'u8', 'u16', 'u32', 's8', 's16', 's32', 'f32', 'f64'}


def type_definition_span(body: str, tname: str) -> Optional[Tuple[int, int]]:
    """Span of `typedef struct [tag] { ... } tname;`, `struct tname { ... };`, or a one-line
    `typedef ... (*tname)(...);` / `typedef T tname;` in a block."""
    m1 = re.search(r'^typedef\s+[^;{}]*?\(\s*\*\s*' + re.escape(tname) + r'\s*\)\s*\([^;]*\)\s*;\s*\n?', body, re.M)
    if m1:
        return m1.start(), m1.end()
    m2 = re.search(r'^typedef\s+(?!struct\b|union\b|enum\b)[^;{}()\[]*?\b' + re.escape(tname) + r'\s*(?:\[[^\]]*\]\s*)*;\s*\n?', body, re.M)
    if m2:
        return m2.start(), m2.end()
    for m in re.finditer(r'^(?:typedef\s+)?(?:struct|union|enum)\s*(?:[A-Za-z_]\w*\s*)?\{', body, re.M):
        depth = 0
        i = m.end() - 1
        while i < len(body):
            if body[i] == '{':
                depth += 1
            elif body[i] == '}':
                depth -= 1
                if depth == 0:
                    tail = re.match(r'\s*([A-Za-z_]\w*)?\s*;', body[i + 1:])
                    if not tail:
                        break
                    end = i + 1 + tail.end()
                    head = body[m.start():m.end()]
                    name = tail.group(1) if m.group(0).startswith('typedef') else re.search(r'(?:struct|union|enum)\s*([A-Za-z_]\w*)', head)
                    name = name if isinstance(name, str) or name is None else name.group(1)
                    if name == tname:
                        return m.start(), end + (1 if body[end:end + 1] == '\n' else 0)
                    break
            i += 1
    return None


def order_prologue_types(prologue: str) -> str:
    """A prologue definition that names a typedef defined later in the prologue moves after
    it (committed car.c: `EventObject` used `EventData *` seven lines before its typedef)."""
    for _ in range(64):
        defs = []
        # one-line typedefs (forward declarations, aliases, function pointers) define a name too
        for m in re.finditer(r'^typedef\s+[^;{}]*;\s*\n?', prologue, re.M):
            text = m.group(0)
            fp = re.search(r'\(\s*\*\s*([A-Za-z_]\w*)\s*\)', text)
            name = fp.group(1) if fp else re.findall(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*;', text)[-1]
            defs.append((m.start(), m.end(), {name}))
        for m in re.finditer(r'^(?:typedef\s+)?(?:struct|union|enum)\b[^;{]*\{', prologue, re.M):
            # find the end of this definition
            i = m.end() - 1
            depth = 0
            while i < len(prologue):
                if prologue[i] == '{':
                    depth += 1
                elif prologue[i] == '}':
                    depth -= 1
                    if depth == 0:
                        tail = re.match(r'\s*([A-Za-z_]\w*)?\s*;\s*\n?', prologue[i + 1:])
                        if tail:
                            head = prologue[m.start():m.end()]
                            tagm = re.search(r'(?:struct|union|enum)\s+([A-Za-z_]\w*)', head)
                            names = {x for x in (tail.group(1), tagm.group(1) if tagm else None) if x}
                            defs.append((m.start(), i + 1 + tail.end(), names))
                        break
                i += 1
        defs.sort()
        moved = False
        for k, (a, b, names) in enumerate(defs):
            text = prologue[a:b]
            if re.match(r'^typedef\s+struct\s+(\w+)\s+\1\s*;', text.strip()):
                continue  # a forward declaration depends on nothing
            body_idents = set(re.findall(r'[A-Za-z_]\w*', text)) - names
            by_pointer = set(re.findall(r'\b([A-Za-z_]\w*)\s*\*', text)) - names
            later = []
            for a2, b2, n2 in defs[k + 1:]:
                if not (n2 & body_idents):
                    continue
                is_forward = bool(re.match(r'^typedef\s+struct\s+(\w+)\s+\1\s*;', prologue[a2:b2].strip()))
                # a name used only through a pointer needs just its forward typedef before it
                if (n2 & body_idents) <= by_pointer and not is_forward and any(
                        re.search(r'^typedef\s+struct\s+' + re.escape(x) + r'\s+' + re.escape(x) + r'\s*;', prologue, re.M) for x in n2):
                    continue
                later.append((a2, b2, n2))
            if later:
                a2, b2, _ = later[0]
                dep = prologue[a2:b2]
                prologue = prologue[:a] + dep + prologue[a:a2] + prologue[b2:]
                moved = True
                break
        if not moved:
            break
    return prologue


def hoist_private_types(tf: tufile.TuFile, truths: Dict[str, str], report: Dict[str, object]) -> None:
    """Move the definitions of block-private types that a truth names into the prologue,
    dependencies first, when exactly one block defines the type (reconcile prefixed the
    colliding ones)."""
    private: Dict[str, List[str]] = {}
    for b in tf.blocks:
        for t in private_type_names(b.body):
            private.setdefault(t, []).append(b.name)
    hoisted: List[Tuple[str, str]] = []
    done: set = set()

    def in_prologue(t: str) -> bool:
        return bool(re.search(r'\}\s*' + re.escape(t) + r'\s*;', tf.prologue, re.M)
                    or re.search(r'^(?:typedef\s+)?struct\s+' + re.escape(t) + r'\s*\{', tf.prologue, re.M))

    def hoist(t: str, stack: Tuple[str, ...] = ()) -> None:
        if t in done or t in stack or t not in private or in_prologue(t):
            return
        owners = private[t]
        if len(set(owners)) != 1:
            report.setdefault('unhoistable', []).append(f'{t}: defined in {sorted(set(owners))}')
            done.add(t)
            return
        b = tf.get(owners[0])
        span = type_definition_span(b.body, t)
        if not span:
            report.setdefault('unhoistable', []).append(f'{t}: no definition span in {b.name}')
            done.add(t)
            return
        text = b.body[span[0]:span[1]]
        for inner in dict.fromkeys(re.findall(r'[A-Za-z_]\w*', text)):
            if inner != t and inner in private:
                hoist(inner, stack + (t,))
            elif inner != t:
                # a forward typedef (`typedef struct X X;`) the definition relies on
                fwd_ = re.search(r'^typedef\s+struct\s+' + re.escape(inner) + r'\s+' + re.escape(inner) + r'\s*;\s*\n?', b.body, re.M)
                if fwd_ and not re.search(r'^typedef\s+struct\s+' + re.escape(inner) + r'\s+' + re.escape(inner) + r'\s*;', tf.prologue, re.M):
                    tf.prologue = tf.prologue.rstrip('\n') + '\n\n' + fwd_.group(0).strip() + '\n'
                    b.body = b.body[:fwd_.start()] + b.body[fwd_.end():]
        span = type_definition_span(b.body, t)  # offsets may have moved with an inner hoist
        text = b.body[span[0]:span[1]]
        b.body = b.body[:span[0]] + b.body[span[1]:]
        # a forward typedef of the tag (`typedef struct X X;`, self-referential structs) goes first
        fwd = re.search(r'^typedef\s+struct\s+' + re.escape(t) + r'\s+' + re.escape(t) + r'\s*;\s*\n?', b.body, re.M)
        if fwd:
            b.body = b.body[:fwd.start()] + b.body[fwd.end():]
        if (fwd or re.search(r'\b' + re.escape(t) + r'\s*\*', text)) and not re.search(r'^typedef\s+struct\s+' + re.escape(t) + r'\s+' + re.escape(t) + r'\s*;', tf.prologue, re.M) and text.startswith('struct'):
            tf.prologue = tf.prologue.rstrip('\n') + f'\n\ntypedef struct {t} {t};\n'
        tf.prologue = tf.prologue.rstrip('\n') + '\n\n' + text.rstrip('\n') + '\n'
        hoisted.append((t, b.name))
        done.add(t)

    for truth in truths.values():
        for t in re.findall(r'[A-Za-z_]\w*', truth):
            if t in private:
                hoist(t)
    report['hoisted_types'] = hoisted


def cast_results(body: str, name: str, old_ret: str) -> str:
    """`x = f(...)` under a truth with another return type: cast the call to the old type."""
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{'):
            continue
        before = body[line_start:m.start()]
        if not re.search(r'(=|return|\(|,|\?|:)\s*$', before):
            continue
        out = out[:m.start()] + f'({old_ret})' + out[m.start():]
    return out


def min_call_args(body: str, name: str) -> Optional[int]:
    """Fewest arguments any call of `name` in the body passes (None: no call)."""
    least = None
    for m in re.finditer(r'\b' + re.escape(name) + r'\s*\(', body):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{'):
            continue
        least = len(res[0]) if least is None else min(least, len(res[0]))
    return least


def view_rewrite(body: str, name: str, decl: str, truth_is_pointer: bool = False) -> Optional[str]:
    """Every use of a data symbol goes through the block's own view of the object:
    `extern T n;` -> `(*(T *)&n)`, `extern T n[..];` -> `((T *)&n)`, `extern T *n;` -> `((T)n)`
    when the truth is a pointer too. The address is the same symbol."""
    m = re.match(r'^\s*extern\s+(.*?)\s*\b' + re.escape(name) + r'\s*((?:\[[^\]]*\])*)\s*;', decl.strip())
    if not m:
        return None
    t = re.sub(r'\s+', ' ', m.group(1)).strip()
    if m.group(2):
        view = f'((({t} *)&{name}))'
    elif t.endswith('*') and truth_is_pointer:
        view = f'(({t}){name})'
    else:
        view = f'(*(({t} *)&{name}))'
    ident = re.compile(r'(?<![\w.>])' + re.escape(name) + r'\b')
    out_lines = []
    for ln in body.splitlines():
        if tutidy.DECL_LINE_RE.match(ln) and tutidy._decl_name(ln) == name:
            continue
        out_lines.append(ident.sub(view, ln))
    return '\n'.join(out_lines) + ('\n' if body.endswith('\n') else '')


def adapt(body: str, n: str, old_decl: Optional[str], truth: str, report_bad: List[str], force: bool = False) -> Optional[str]:
    """The block's body under `truth` for symbol n, given the declaration it was written
    against (`old_decl`: its private line, or the old prologue line, or None). Returns None
    when no mechanical adaptation exists (a data view whose declaration cannot be parsed)."""
    lines = [x for x in body.splitlines() if not (tutidy.DECL_LINE_RE.match(x) and tutidy._decl_name(x) == n)]
    body = '\n'.join(lines) + ('\n' if body.endswith('\n') else '')
    if old_decl is None or old_decl.strip() == truth.strip():
        return body
    sv, st = _sig(old_decl), _sig(truth)
    if sv and st:
        if st[2] and st[2][-1] == '...':
            return body
        if len(sv[2]) == len(st[2]):
            if sv[2] != st[2] and '...' not in sv[2]:
                permuted = permute_args(body, n, sv[2], st[2])
                body = permuted if permuted is not None else cast_calls(body, n, sv[2], st[2], force)
        elif len(sv[2]) > len(st[2]) and all(_same(a, b) for a, b in zip(sv[2][len(sv[2]) - len(st[2]):], st[2])):
            body = drop_leading_args(body, n, len(sv[2]) - len(st[2]))
        if sv[0] != st[0] and not _same(sv[0], st[0]) and re.sub(r'\s', '', sv[0]) != 'void':
            if re.sub(r'\s', '', st[0]) == 'void' and re.search(r'=\s*' + re.escape(n) + r'\s*\(', body):
                return None
            body = cast_results(body, n, sv[0])
        return body
    if not sv and not st:
        truth_ptr = bool(re.match(r'^\s*extern\s+.*\*\s*' + re.escape(n) + r'\s*;', truth))
        return view_rewrite(body, n, old_decl, truth_is_pointer=truth_ptr)
    return None


def _reg_class(t: str) -> str:
    return 'F' if re.sub(r'\bconst\b', '', t).strip() in ('f32', 'f64', 'float', 'double') else 'G'


def permute_args(body: str, name: str, old: List[str], new: List[str]) -> Optional[str]:
    """Two prototypes that place the same values in the same registers in another order
    (`(u8, f32, f32)` against `(f32, f32, s32)`): reorder the call's arguments so each
    register still receives what it did. Returns None when the classes do not permute."""
    oc, nc = [_reg_class(t) for t in old], [_reg_class(t) for t in new]
    if sorted(oc) != sorted(nc) or oc == nc:
        return None
    order = []
    used = set()
    for c in nc:
        j = next((j for j, c2 in enumerate(oc) if c2 == c and j not in used), None)
        if j is None:
            return None
        used.add(j)
        order.append(j)
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{') or len(res[0]) != len(old):
            continue
        args = [body[a:b].strip() for a, b in res[0]]
        new_args = [f'({new[i]})({args[order[i]]})' if not _same(old[order[i]], new[i]) else args[order[i]] for i in range(len(new))]
        out = out[:res[0][0][0]] + ', '.join(new_args) + out[res[0][-1][1]:]
    return out


def knr_definition(body: str, name: str) -> str:
    """The definition of `name` in non-prototype (K&R) form, so callers may pass fewer
    arguments after it (fn_1_5448C's lab_unused parameters; its code is unchanged)."""
    m = re.search(r'^([A-Za-z_][\w \*]*?)\b' + re.escape(name) + r'\s*\(([^;{}()]*)\)\s*\{', body, re.M)
    if not m or m.group(2).strip() in ('', 'void'):
        return body
    params = [x.strip() for x in m.group(2).split(',')]
    names, decls = [], []
    for prm in params:
        pm = re.search(r'([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)$', prm)
        if not pm or prm == '...':
            return body
        names.append(pm.group(1))
        decls.append(prm + ';')
    return body[:m.start()] + f'{m.group(1)}{name}({", ".join(names)})\n' + '\n'.join(decls) + '\n{' + body[m.end():]


def drop_leading_args(body: str, name: str, k: int) -> str:
    """Calls that passed k more leading arguments than the truth declares."""
    out = body
    for m in reversed(list(re.finditer(r'\b' + re.escape(name) + r'\s*\(', body))):
        line_start = body.rfind('\n', 0, m.start()) + 1
        line_end = body.find('\n', m.start())
        if tutidy.DECL_LINE_RE.match(body[line_start:line_end if line_end >= 0 else len(body)]):
            continue
        res = split_args(body, m.end() - 1)
        if not res or body[res[1] + 1:].lstrip().startswith('{') or len(res[0]) <= k:
            continue
        spans = res[0]
        out = out[:spans[0][0]] + out[spans[k][0]:]
    return out


def resolve(p: Project, tu_source: str, v, apply: bool = True,
            extra_blocks: Optional[Dict[str, str]] = None) -> Dict[str, object]:
    """`extra_blocks` ({name: body}) join the TU as unverified members (unmatched functions'
    best bodies): their declarations are reconciled and adapted like everyone else's, they
    are never restored, and the result is only reported, never written."""
    module = tu_source.split('/')[1] if tu_source.startswith('rel/') else 'main'
    units = {u['symbols'][0]: u for u in p.load_units() if u.get('tu') == tu_source}
    tf = tufile.load(p, tu_source)
    extra_names = set()
    if extra_blocks:
        apply = False
        for name_, body_ in extra_blocks.items():
            tf.blocks.append(tufile.Block(name_, body_, []))
            extra_names.add(name_)
    report: Dict[str, object] = {'tu': tu_source, 'truth': {}, 'rewritten': [], 'reverted': [], 'unresolved': {}}
    tf.prologue = order_prologue_types(split_multi(join_declarations(tf.prologue)))
    for b in tf.blocks:
        b.body = split_multi(join_declarations(b.body))
        b.flags = [x for x in b.flags if x != 'noprologue']  # every block under the one prologue
    # one include set for the TU: headers a block includes join the prologue
    block_includes = []
    own_includes: Dict[str, List[str]] = {}
    for b in tf.blocks:
        inc, rest = tufile.split_includes(b.body)
        own_includes[b.name] = [ln.strip() for ln in inc if ln.strip()]
        for ln in inc:
            if ln.strip() and ln.strip() not in {x.strip() for x in tf.prologue.splitlines()} and ln.strip() not in block_includes:
                block_includes.append(ln.strip())
        b.body = rest.lstrip('\n')
    if block_includes:
        tf.prologue = tufile.merge_prologue(tf.prologue, block_includes)
        report['promoted_includes'] = block_includes
    header_names, header_typedefs = tutidy._header_names(p, tf.prologue)
    hdecl: Dict[str, str] = {}
    for ln in tf.prologue.splitlines():
        m = re.search(r'#include\s+"([^"]+)"', ln)
        if m and (ROOT / 'include' / m.group(1)).exists():
            for hl in (ROOT / 'include' / m.group(1)).read_text().splitlines():
                hl = re.sub(r'\s*//.*$', '', hl)  # generated headers annotate declarations
                if tutidy.DECL_LINE_RE.match(hl):
                    n = tutidy._decl_name(hl)
                    if n:
                        hdecl.setdefault(n, hl.strip())
    # block typedefs that collide with a header or prologue typedef: an identical definition
    # is dropped (the prologue carries it), a different one gets the block's prefix
    # block -> private type names it renamed to `<block>_<name>`: a prologue declaration the block
    # relied on must follow the rename (fn_9_454's view cast named the unrenamed, incomplete tag)
    block_renames: Dict[str, set] = {}
    prologue_typedefs = set(re.findall(r'\}\s*([A-Za-z_]\w*)\s*;', tf.prologue, re.M)) | set(re.findall(r'^(?:typedef\s+)?struct\s+([A-Za-z_]\w*)\s*\{', tf.prologue, re.M))
    for b in tf.blocks:
        for t in sorted((set(re.findall(r'\}\s*([A-Za-z_]\w*)\s*;', b.body, re.M)) | set(re.findall(r'^(?:typedef\s+)?struct\s+([A-Za-z_]\w*)\s*\{', b.body, re.M))) & (set(header_typedefs) | prologue_typedefs)):
            span = type_definition_span(b.body, t)
            pspan = type_definition_span(tf.prologue, t)
            if span and pspan and re.sub(r'\s+', ' ', b.body[span[0]:span[1]]).strip() == re.sub(r'\s+', ' ', tf.prologue[pspan[0]:pspan[1]]).strip():
                b.body = b.body[:span[0]] + b.body[span[1]:]
                report.setdefault('dropped_typedefs', []).append((b.name, t))
            else:
                b.body = re.sub(r'\b' + re.escape(t) + r'\b', f'{b.name}_{t}', b.body)
                report.setdefault('renamed_typedefs', []).append((b.name, t))
                block_renames.setdefault(b.name, set()).add(t)
    # the same private type defined by several blocks: identical text is hoisted once and
    # dropped from the blocks, differing definitions get each block's prefix
    defs_by_type: Dict[str, List[Tuple[str, str]]] = {}
    for b in tf.blocks:
        for t in set(re.findall(r'\}\s*([A-Za-z_]\w*)\s*;', b.body, re.M)) | set(re.findall(r'^(?:typedef\s+)?(?:struct|union)\s+([A-Za-z_]\w*)\s*\{', b.body, re.M)):
            span = type_definition_span(b.body, t)
            if span:
                defs_by_type.setdefault(t, []).append((b.name, re.sub(r'\s+', ' ', b.body[span[0]:span[1]]).strip()))
    for t, owners in defs_by_type.items():
        if type_definition_span(tf.prologue, t):
            continue  # the prologue defines it: the block-vs-prologue rule above handled the copies
        if len(owners) < 2:
            continue
        texts = {text for _, text in owners}
        if len(texts) == 1:
            first = True
            for bname, _ in owners:
                b = tf.get(bname)
                span = type_definition_span(b.body, t)
                if not span:
                    continue
                if first:
                    tf.prologue = tf.prologue.rstrip('\n') + '\n\n' + b.body[span[0]:span[1]].rstrip('\n') + '\n'
                    first = False
                b.body = b.body[:span[0]] + b.body[span[1]:]
            report.setdefault('shared_types', []).append(t)
        else:
            for bname, _ in owners:
                b = tf.get(bname)
                b.body = re.sub(r'\b' + re.escape(t) + r'\b', f'{bname}_{t}', b.body)
                block_renames.setdefault(bname, set()).add(t)
            report.setdefault('renamed_typedefs', []).append(('*', t))
    pdecl: Dict[str, str] = {}
    kept_pro = []
    for ln in tf.prologue.splitlines():
        if tutidy.DECL_LINE_RE.match(ln):
            n = tutidy._decl_name(ln)
            if n:
                pdecl[n] = ln.strip()
                continue  # every prologue declaration is re-decided below
        kept_pro.append(ln)
    base_prologue = '\n'.join(kept_pro).rstrip('\n') + '\n'
    definitions: Dict[str, str] = {}
    for b in tf.blocks:
        for m in reconcile.DEF_RE.finditer(b.body):
            definitions[m.group(2)] = 'extern ' + re.sub(r'\s+', ' ', m.group(1)).strip() + ';'
    variants: Dict[str, Counter] = OrderedDict()
    where: Dict[str, Dict[str, str]] = {}
    for b in tf.blocks:
        for n, ln in reconcile._decls(b.body):
            variants.setdefault(n, Counter())[ln] += 1
            where.setdefault(n, {})[b.name] = ln
    symbols = list(dict.fromkeys(list(variants) + list(pdecl)))
    private_types = set()
    for b in tf.blocks:
        private_types |= private_type_names(b.body)
    known_types = SCALAR | set(header_typedefs) | private_types | private_type_names(tf.prologue) | {'struct', 'union', 'enum', 'extern', 'const', 'volatile', 'static', 'inline', 'unsigned', 'signed'}

    def admissible(decl: str) -> bool:
        sig = _sig(decl)
        stripped = re.sub(r'\[[^\]]*\]', '', decl.split('=')[0])  # array dimensions are not types
        words = set(re.findall(r'(?<![\w])[A-Za-z_]\w*', sig[0] + ' ' + ' '.join(sig[2]))) if sig else set(re.findall(r'(?<![\w])[A-Za-z_]\w*', stripped))
        if not sig:
            words -= {tutidy._decl_name(decl)}
        return all(w in known_types or w == '...' for w in words)

    candidates: Dict[str, List[Tuple[str, str]]] = {}
    for n in symbols:
        c: List[Tuple[str, str]] = []
        if n in hdecl:
            c.append(('header', hdecl[n]))
        d = definitions.get(n) or project_definition(p, n)
        if d:
            c.append(('definition', d))
        if n in pdecl:
            c.append(('prologue', pdecl[n]))
        for t, _ in sorted(variants.get(n, {}).items(), key=lambda kv: (-kv[1], len(kv[0]))):
            c.append(('variant', t))
        seen = set()
        adm = [(src, t) for src, t in c if not (t.strip() in seen or seen.add(t.strip())) and admissible(t)]
        if not adm:
            # no spelling whose types this TU can see: the symbol stays out of the prologue and
            # every block keeps its own line (reported; usually a broken committed prologue)
            report.setdefault('inadmissible', []).append((n, c[0][1] if c else None))
            candidates[n] = []
            continue
        c = adm
        # a definition's parameter order across register classes is unconstrained by its own
        # code; a caller's spelling that permutes it by class carries the evaluation-order
        # evidence (fn_1_563E4: retail loads the s32 colour before the two floats)
        d_ = next((t for src, t in c if src == 'definition'), None)
        if d_ and _sig(d_):
            dc = [_reg_class(t) for t in _sig(d_)[2]]
            if len(set(dc)) > 1:
                perms = [(src, t) for src, t in c if src == 'variant' and _sig(t) and len(_sig(t)[2]) == len(dc)
                         and sorted(_reg_class(x) for x in _sig(t)[2]) == sorted(dc) and [_reg_class(x) for x in _sig(t)[2]] != dc]
                if perms:
                    c = perms + [x for x in c if x not in perms]
                    report.setdefault('definition_order_from_callers', []).append((n, perms[0][1]))
        # a definition whose return type is register-identical to the callers' (u32 against
        # void *): the callers' type, with the definition retyped to it (fn_1_548AC)
        if d_ and _sig(d_) and n in definitions:
            dr = _sig(d_)

            def gpr_equivalent(a: str, b: str) -> bool:
                # identical, or an integer against a pointer (never two different pointer types:
                # a definer's field accesses need its own struct pointer)
                if _same(a, b):
                    return True
                ia, ib = a.split()[-1] in INTS and '*' not in a, b.split()[-1] in INTS and '*' not in b
                return ia != ib and ('*' in a or '*' in b) and a != '...' and b != '...'

            for src, t in list(c):
                vs_ = _sig(t)
                if src == 'variant' and vs_ and len(vs_[2]) == len(dr[2]) and t.strip() != d_.strip() \
                        and all(gpr_equivalent(a, b) for a, b in zip(vs_[2], dr[2])) and gpr_equivalent(vs_[0], dr[0]):
                    retyped = f'extern {vs_[0]} {n}({", ".join(vs_[2]) or "void"});'
                    c.insert(0, ('definition-retyped', retyped))
                    break
        if n in definitions:
            # the definer must agree with the prologue: only its own signature or a retyping of it
            c = [(src, t) for src, t in c if src in ('header', 'definition', 'definition-retyped')] or c[:1]
        if n in hdecl and admissible(hdecl[n]):
            # a header declaration is the file's truth for everyone, definers included
            c = [('header', hdecl[n])]
        candidates[n] = c
    # users of a symbol: blocks that declared it privately, called it, or defined it
    users: Dict[str, List[str]] = {}
    for n in symbols:
        pat = re.compile(r'\b' + re.escape(n) + r'\b')
        users[n] = [b.name for b in tf.blocks if b.name in where.get(n, {}) or pat.search(b.body)]
    original = {b.name: b.body for b in tf.blocks}
    symbols = [n for n in symbols if candidates.get(n)]
    choice: Dict[str, int] = {n: 0 for n in symbols}

    def old_decl_for(bname: str, n: str) -> Optional[str]:
        own = where.get(n, {}).get(bname)
        if own:
            return own
        decl = pdecl.get(n)
        for tname in block_renames.get(bname, ()):
            if decl:
                decl = re.sub(r'\b' + re.escape(tname) + r'\b', f'{bname}_{tname}', decl)
        return decl

    forced: set = set()
    # definitions whose callers pass fewer arguments than they declare (unused trailing
    # parameters a match needed): the definition goes non-prototype so the calls stay legal
    knr_defs: set = set()
    for n in symbols:
        if n not in definitions:
            continue
        st0 = _sig(definitions[n])
        if not st0 or '...' in st0[2]:
            continue
        for b in tf.blocks:
            least = min_call_args(original[b.name], n)
            if least is not None and least < len(st0[2]):
                knr_defs.add(n)

    definer_of = {n: next((bn for bn, ob in original.items() if re.search(r'\b' + re.escape(n) + r'\s*\([^;{}()]*\)\s*\{', ob)), None)
                  for n in symbols if n in definitions}

    def derive(bname: str) -> Optional[str]:
        body = original[bname]
        for n in symbols:
            if bname not in users[n]:
                continue
            truth = candidates[n][choice[n]][1]
            if n in definitions and bname == definer_of.get(n):
                # the definer: its own private declaration goes, its signature is the truth
                body = '\n'.join(x for x in body.splitlines() if not (tutidy.DECL_LINE_RE.match(x) and tutidy._decl_name(x) == n)) + '\n'
                if n in knr_defs:
                    body = knr_definition(body, n)
                if candidates[n][choice[n]][0] == 'definition-retyped':
                    st_ = _sig(truth)
                    dm = re.search(r'^([A-Za-z_][\w \*]*?)\b' + re.escape(n) + r'\s*\(([^;{}()]*)\)\s*\{', body, re.M)
                    if dm:
                        params = [x.strip() for x in dm.group(2).split(',')] if dm.group(2).strip() not in ('', 'void') else []
                        names_ = [re.search(r'([A-Za-z_]\w*)\s*$', x).group(1) if re.search(r'([A-Za-z_]\w*)\s*$', x) else '' for x in params]
                        new_params = ', '.join(f'{t} {nm}'.replace('* ', '*') for t, nm in zip(st_[2], names_)) if params else 'void'
                        body = body[:dm.start()] + f'{st_[0]} {n}({new_params}) {{' + body[dm.end():]
                    if not _same(st_[0], dr_ret := _sig(d_full := definitions[n])[0]):
                        body = re.sub(r'\breturn\s+([^;]+);', lambda mm: f'return ({st_[0]})({mm.group(1)});' if not mm.group(1).strip().startswith('(' + st_[0]) else mm.group(0), body)
                continue
            body = adapt(body, n, old_decl_for(bname, n), truth, [], force=bname in forced)
            if body is None:
                return None
        return body

    def render_prologue() -> str:
        lines = []
        knr = set()
        for n in symbols:
            truth = candidates[n][choice[n]][1]
            st = _sig(truth)
            if st and '...' not in st[2]:
                for bname in users[n]:
                    least = min_call_args(tf.get(bname).body, n)
                    if least is not None and least != len(st[2]):
                        knr.add(n)
            if n in hdecl and candidates[n][choice[n]][0] == 'header':
                continue
            if n in hdecl and candidates[n][choice[n]][0] == 'header':
                continue
            if (n in knr or n in knr_defs) and st:
                lines.append(f'extern {st[0]} {n}();')
            elif n in definitions and candidates[n][choice[n]][0] == 'definition':
                lines.append(truth)  # the TU's own definition, declared ahead of its callers
            else:
                lines.append(truth)
        report['knr'] = sorted(knr)
        return order_prologue_types(base_prologue.rstrip('\n') + '\n' + '\n'.join(dict.fromkeys(lines)) + '\n')

    before_hoist = tf.prologue
    hoist_private_types(tf, {f'{n}#{k}': t for n in symbols for k, (_, t) in enumerate(candidates[n])}, report)
    base_prologue = base_prologue.rstrip('\n') + '\n' + tf.prologue[len(before_hoist):]  # the hoisted types
    original = {b.name: b.body for b in tf.blocks}

    scratch = STATE_DIR / 'work' / 'tutruth' / Path(tu_source).stem
    scratch.mkdir(parents=True, exist_ok=True)

    memo: Dict[Tuple[str, str], bool] = {}

    def verify(names_: List[str]) -> Dict[str, bool]:
        """Direct oracle verdicts on the current state: prologue + block per unit, memoised by
        the generated text within this run (no persistent cache)."""
        out: Dict[str, bool] = {}
        items = []
        for n_ in names_:
            text = tufile.gen_text(tf, n_)
            if (n_, text) in memo:
                out[n_] = memo[(n_, text)]
                continue
            path = scratch / f'{n_}.c'
            path.write_text(text)
            items.append((f'{module}:{n_}', path, text))
        if items:
            res = oracle.check_many(p, [(k, path) for k, path, _ in items], 20)
            for k, path, text in items:
                r_ = res.get(k)
                ok = bool(r_ and r_.ok and (r_.matched or r_.matched_pool) and oracle.unit_fully_matches(r_) is None)
                n_ = k.split(':', 1)[1]
                memo[(n_, text)] = ok
                out[n_] = ok
        return out

    def rebuild() -> None:
        for b in tf.blocks:
            nb = derive(b.name)
            b.body = nb if nb is not None else original[b.name]
        tf.prologue = render_prologue()

    rebuild()
    names = [b.name for b in tf.blocks if b.name in units and b.name not in extra_names]
    verdict = verify(names)
    if names and sum(1 for n_ in names if not verdict.get(n_)) > len(names) // 2:
        # the prologue itself is likely broken: keep the first compiler message for the report
        first = next(n_ for n_ in names if not verdict.get(n_))
        res0 = oracle.check(p, f'{module}:{first}', 20, source=scratch / f'{first}.c')
        report['first_round_error'] = res0.error[-900:] if not res0.ok else f'{first}: {res0.percent}'
        report['first_round_prologue'] = tf.prologue
    failing = [n for n in names if not verdict.get(n)]
    for bname in list(failing):
        fixed = False
        forced.add(bname)
        rebuild()
        if verify([bname]).get(bname):
            fixed = True
        else:
            forced.discard(bname)
        differing = [n for n in symbols if not fixed and bname in users[n] and len(candidates[n]) > 1
                     and (old_decl_for(bname, n) or '').strip() != candidates[n][choice[n]][1].strip()]
        for n in differing:
            prev = choice[n]
            for k in range(len(candidates[n])):
                if k == prev:
                    continue
                choice[n] = k
                rebuild()
                affected = sorted(set(users[n]) | {bname})
                vd = verify(affected)
                if vd.get(bname) and all(vd.get(x) for x in affected if verdict.get(x)):
                    fixed = True  # the block matches and no other user regressed
                    break
            if fixed:
                break
            choice[n] = prev
        if fixed:
            rebuild()
            verdict = verify(names)
            failing = [n for n in names if not verdict.get(n)]
    for n in symbols:
        report['truth'][n] = candidates[n][choice[n]]
    report['rewritten'] = [n for n in names if verdict.get(n)]
    report['reverted'] = failing
    # a block that cannot be adapted keeps its committed, self-contained form (still contested)
    pristine = tufile.load(p, tu_source)

    def restore(bname: str) -> None:
        """The committed block, self-contained: under the committed prologue when it was not
        self-contained before (its declarations are what it matched against)."""
        b = tf.get(bname)
        pb = pristine.get(bname)
        b.flags = list(pb.flags)
        if 'noprologue' in pb.flags:
            b.body = pb.body
        else:
            # includes and type definitions always; declarations only when the block names them
            keep = []
            idents = set(re.findall(r'[A-Za-z_]\w*', pb.body))
            for ln in pristine.prologue.splitlines():
                if tutidy.DECL_LINE_RE.match(ln):
                    n_ = tutidy._decl_name(ln)
                    if n_ and n_ not in idents:
                        continue
                keep.append(ln)
            b.body = '\n'.join(keep).rstrip('\n') + '\n\n' + pb.body
            b.flags.append('noprologue')

    report['prologue'] = tf.prologue
    for bname in failing:
        report.setdefault('adapted', {})[bname] = tf.get(bname).body
        res_ = oracle.check(p, f'{module}:{bname}', 12, source=scratch / f'{bname}.c')
        report.setdefault('why', {})[bname] = (res_.error[-500:] if not res_.ok else
                                              f'{res_.percent:.2f} ' + ' | '.join(l for l in res_.diff if l[0] in '?<>')[:600])
        restore(bname)
    final = verify(names)
    for n in [n for n, ok in final.items() if not ok]:
        restore(n)
    final.update(verify([n for n, ok in final.items() if not ok]))
    report['final_matching'] = sum(1 for x in final.values() if x)
    report['final_failing'] = [n for n, ok in final.items() if not ok]
    report['self_contained'] = [b.name for b in tf.blocks if 'noprologue' in b.flags]
    if extra_names:
        report['extra_verdicts'] = verify(sorted(extra_names))
        compiles = {}
        for n_ in sorted(extra_names):
            res_ = oracle.check(p, f'{module}:{n_}', 0, source=scratch / f'{n_}.c')
            compiles[n_] = bool(res_.ok)
            if not res_.ok:
                report.setdefault('extra_errors', {})[n_] = res_.error[-300:]
        report['extra_compiles'] = compiles
        report['tu_text'] = tf.render()
    if apply and not report['final_failing']:
        tufile._write_atomic(tufile.tu_path(p, tu_source), tf.render())
        for u in units.values():
            tufile.write_gen(p, u, tf)
        # a rewritten block may renumber its private literals: keep pool mappings current
        for u in list(units.values()):
            if isinstance(u.get('pool'), dict):
                res = oracle.check(p, f"{module}:{u['symbols'][0]}", 20)
                new_map = res.pool_map if res.ok and (res.matched or res.matched_pool) else None
                if not new_map:
                    # an empty map means the recorded one was already applied: never wipe it (finish.py's
                    # guard), unless the recorded private names no longer exist in the compiled object
                    # (a new prologue renumbers the block's @N literals): then bind them again
                    from . import collapse, poolfix
                    obj = scratch / f"{u['symbols'][0]}.pool.o"
                    cp_ = oracle.compile_unit(p, p.objdiff_unit_name(module, u['source']), u['source'], None, output=obj)
                    if cp_.returncode == 0:
                        names_ = {s['name'] for s in poolfix.Elf(obj.read_bytes()).symbols()}
                        if any(k not in names_ for k in u['pool']):
                            new_map = collapse._pool_map(p, module, u['symbols'], obj)
                if new_map and new_map != u['pool']:
                    with oracle.build_lock('units.lock'):
                        all_units = p.load_units()
                        for x in all_units:
                            if x['source'] == u['source']:
                                x['pool'] = dict(new_map)
                        p.save_units(all_units)
                    report.setdefault('pool_remapped', []).append(u['symbols'][0])
        for u in units.values():
            tufile.write_gen(p, u, tf)
    return report
