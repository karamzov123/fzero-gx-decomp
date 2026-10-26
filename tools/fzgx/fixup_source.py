"""Source transformations and compiler-response algebra for the single fixup engine.

No compilation, search runners, caches, or submission live in this module.
"""
from __future__ import annotations
import difflib
import itertools
import math
import re
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Tuple
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN
from Levenshtein import distance
from . import oracle, mwgraph, mwconstraints
from .signatures import records, record_tag, declarator

TYPE = (r'(?:(?:register|const|volatile)\s+){0,3}'
        r'(?:(?:unsigned|signed)\s+)?'
        r'(?:(?:long\s+long|long|short)(?:\s+int)?|(?:struct|union|enum)\s+\w+|[A-Za-z_]\w*)'
        r'(?:\s*\*)*')
DECL_RE = re.compile(r'^\s*(' + TYPE + r')(?:(?<=\*)\s*|\s+)([A-Za-z_]\w*)'
                     r'((?:\[[^\]]*\])*)\s*(?:=\s*([^;]+))?;\s*(?:(?:/\*.*?\*/|//[^\n]*)\s*)?$')


_LITERAL = re.compile(r'"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'')


def _wrap_uses(name, text):
    """`name` -> `name.value` at variable uses only: never inside a string or character
    literal ("%d" became "%d.value" and lost fn_14_82E4's match) and never a member
    of the same spelling (`p->d`, `s.d`)."""
    pattern = re.compile(r'(?<![.\w])(?<!->)' + re.escape(name) + r'\b(?!\.value)')
    out, last = [], 0
    for literal in _LITERAL.finditer(text):
        out.append(pattern.sub(name + '.value', text[last:literal.start()])); out.append(literal.group(0))
        last = literal.end()
    out.append(pattern.sub(name + '.value', text[last:]))
    return ''.join(out)


def _function_body_span(body: str, name: str) -> Optional[Tuple[int, int, int]]:
    m = re.search(rf"\b{re.escape(name)}\s*\([^;{{]*\)\s*\{{", body)
    if not m:
        return None
    depth, i = 0, m.end() - 1
    while i < len(body):
        if body[i] == "{":
            depth += 1
        elif body[i] == "}":
            depth -= 1
            if depth == 0:
                return m.start(), m.end(), i
        i += 1
    return None


def _locals(body: str, span) -> List[Tuple[int, int, str, str, str]]:
    """Leading local declarations, one per line: (start, end, type, name, dims). Declarations
    with initializers count (their text keeps the initializer)."""
    out = []
    from .sdkimport import masked
    code = masked(body)
    aggregates = None
    consumed = span[1]
    for m in re.finditer(r"[^\n]*\n", code[span[1]:span[2]]):
        line = m.group(0)
        s0 = span[1] + m.start()
        if s0 < consumed:
            continue
        if not line.strip():
            continue
        dm = DECL_RE.match(line.rstrip("\n"))
        if not dm:
            # Inline record declarations used to hide every subsequent local
            # from declaration-order and lifetime repairs.
            if not re.match(r'\s*(?:struct|union)\b',line):
                break
            if aggregates is None:
                aggregates = list(records(code,span[2]))
            start = s0+len(line)-len(line.lstrip())
            record = next((r for r in aggregates if r['start']==start),None)
            if not record:
                break
            end = code.find(';',record['end'],span[2])
            if end<0 or '=' in code[record['end']:end]:
                break
            tail = DECL_RE.fullmatch(record['kind']+' '+record['key']+code[record['end']:end+1])
            if not tail:
                break
            consumed = end+1
            if code[consumed:consumed+1]=='\n':
                consumed += 1
            typ = body[start:record['end']]+tail[1][len(record['kind']+' '+record['key']):]
            out.append((s0,consumed,typ,tail[2],tail[3]))
            continue
        out.append((s0, s0 + len(line), dm.group(1), dm.group(2), dm.group(3)))
    return out


def _init_of(line: str) -> Optional[str]:
    dm = DECL_RE.match(line.rstrip("\n"))
    return dm.group(4).strip() if dm and dm.group(4) else None


def split_declaration_groups(body, name):
    """Expose each scalar home to the captured declaration/lifetime repairs."""
    span = _function_body_span(body, name)
    if not span:
        return []
    pattern = re.compile(r'(?m)^([ \t]*)(' + TYPE + r')\s+'
                         r'(\w+(?:\[[^\],]+\])*(?:\s*,\s*\w+(?:\[[^\],]+\])*)+);[ \t]*$')
    def expand(match):
        if match[2] not in SCALAR_TYPES:
            return match[0]
        return '\n'.join(match[1] + match[2] + ' ' + var.strip() + ';' for var in match[3].split(','))
    inner = pattern.sub(expand, body[span[1]:span[2]])
    if inner == body[span[1]:span[2]]:
        return []
    return [('split scalar declaration groups', body[:span[1]] + inner + body[span[2]:])]


def _order_ok(locs, lines: List[str], order: Tuple[int, ...]) -> bool:
    """An initializer may only name locals declared before it."""
    placed = set()
    for i in order:
        init = _init_of(lines[i])
        if init and any(re.search(rf"\b{re.escape(locs[j][3])}\b", init) for j in range(len(locs)) if j not in placed and j != i):
            return False
        placed.add(i)
    return True


def split_inits(body: str, name: str) -> List[Tuple[str, str]]:
    """`T x = e;` -> `T x;` ... `x = e;` as the first statement (all at once, and one at a
    time); the reverse for a local whose first statement is a plain assignment."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    if not locs:
        return out
    lines = [body[s:e] for s, e, *_ in locs]
    inits = [(i, _init_of(l)) for i, l in enumerate(lines)]
    with_init = [i for i, e in inits if e]
    indent = re.match(r"\s*", lines[0]).group(0)

    def rebuild(split_idx: List[int]) -> str:
        decls, assigns = [], []
        for i, l in enumerate(lines):
            if i in split_idx:
                dm = DECL_RE.match(l.rstrip("\n"))
                decls.append(f"{indent}{dm.group(1)} {dm.group(2)}{dm.group(3)};\n")
                assigns.append(f"{indent}{dm.group(2)} = {dm.group(4).strip()};\n")
            else:
                decls.append(l)
        return body[:locs[0][0]] + "".join(decls) + "".join(assigns) + body[locs[-1][1]:]

    if with_init:
        out.append(("split all inits", rebuild(with_init)))
        if len(with_init) > 1:
            for i in with_init:
                out.append((f"split init {locs[i][3]}", rebuild([i])))
    # the reverse: the first statements `x = e;` for locals without initializers, folded in
    rest = body[locs[-1][1]:span[2]]
    text = body
    folded = 0
    for i, l in enumerate(lines):
        if _init_of(l):
            continue
        m = re.match(r"\s*\n?(\s*)" + re.escape(locs[i][3]) + r" = ([^;]+);\n", rest)
        if not m:
            break
        dm = DECL_RE.match(l.rstrip("\n"))
        new_line = f"{indent}{dm.group(1)} {dm.group(2)}{dm.group(3)} = {m.group(2)};\n"
        text = text.replace(l, new_line, 1)
        text = text.replace(m.group(0), "\n" if m.group(0).startswith("\n") else "", 1)
        rest = rest[m.end():]
        folded += 1
        out.append((f"fold {folded} inits", text))
    return out


def hoists(body: str, name: str) -> List[Tuple[str, str]]:
    """A local declared in an inner block moved to the top of the function."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    top = locs[-1][1] if locs else span[1] + (1 if body[span[1]] == "\n" else 0)
    names = {l[3] for l in locs}
    from .sdkimport import masked
    code=masked(body)
    sites=[]
    for line in re.finditer(r'(?m)^[ \t]+[^\n]*;[^\n]*\n',code[top:span[2]]):
        declaration=DECL_RE.fullmatch(line[0].rstrip('\n'))
        if declaration and declaration[1] not in ('return','goto','break','continue'):
            sites.append((line,declaration))
    for line, declaration in sites:
        typ,nm,dims,init=declaration.groups()
        if nm in names or nm == name:
            continue
        if sum(d[2]==nm for _,d in sites)>1:
            continue
        indent = re.match(r"\s*", body[locs[0][0]:locs[0][1]]).group(0) if locs else "    "
        s0, e0 = top + line.start(), top + line.end()
        decl = f"{indent}{declarator(typ,nm+dims)};\n"
        repl = f"{re.match(r'[ \t]*',line[0])[0]}{nm} = {body[s0+declaration.start(4):s0+declaration.end(4)].strip()};\n" if init else ""
        text = body[:s0] + repl + body[e0:]
        text = text[:top] + decl + text[top:]
        out.append((f"hoist {nm}", text))
    return out


def compound_assignments(body: str, name: str) -> List[Tuple[str, str]]:
    """Contract repeated pure lvalues without regrouping the RHS expression.

    MWCC's compound-assignment lowering can give an induction variable a different
    lifetime even when the emitted operations are otherwise identical.
    """
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span or re.search(r'\bvolatile\b', code):
        return []
    directives = '\n'.join(re.findall(r'(?m)^[ \t]*#[^\n]*', code.replace('\\\n', '')))
    if '##' in directives:
        return []
    macros = set(re.findall(r'(?m)^[ \t]*#\s*define\s+(\w+)', directives))
    operations = []
    commutations(code, name, operations)
    roots = {(op['start'], op['end']): op for op in operations}
    identifier = r'[A-Za-z_]\w*'
    lvalue = identifier + r'(?:\s*(?:->|\.)\s*' + identifier + r'|\s*\[[^\[\]\n]+\])*'
    changes = []
    for m in re.finditer(r'(?m)^[ \t]+([^;{}\n]+?)\s*=\s*([^;{}\n]+);', code[span[1]:span[2]]):
        lhs, rhs = m[1].strip(), m[2].strip()
        if not re.fullmatch(lvalue, lhs) or re.search(r'\+\+|--|[=,?:]|\b\w+\s*\(', lhs):
            continue
        if macros.intersection(re.findall(identifier, lhs)):
            continue
        start, end = span[1] + m.start(1), span[1] + m.end()
        if re.search(r'/[/*]', body[start:end]):
            continue
        rs = span[1] + m.start(2) + len(m[2]) - len(m[2].lstrip())
        re_ = rs + len(rhs)
        root = roots.get((rs, re_))
        if not root or root['op'] not in ('+', '-', '*', '/', '%', '<<', '>>', '&', '|', '^'):
            continue
        a, b = root['left']
        if TOKEN.findall(code[a:b]) != TOKEN.findall(lhs):
            continue
        a, b = root['right']
        replacement = body[start:start + len(lhs)] + ' ' + root['op'] + '= ' + body[a:b] + ';'
        changes.append((start, end, replacement, root['op']))
    out = [('compound ' + op + ' at ' + str(start), body[:start] + text + body[end:])
           for start, end, text, op in changes]
    if len(changes) > 1:
        text = body
        for start, end, replacement, _ in reversed(changes):
            text = text[:start] + replacement + text[end:]
        out.append(('compound all repeated lvalues', text))
    return out


def through_local(body: str, name: str) -> List[Tuple[str, str]]:
    """`x = A op B;` where A is a load -> `x = A; x = x op B;` (the loaded value is the local's
    own register), and `if (p->f OP k)` -> `t = p->f; if (t OP k)` with a fresh local."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    inner = body[span[1]:span[2]]
    for m in re.finditer(r"^(\s*)([A-Za-z_]\w*) = ((?:\("+TYPE+r"\)\s*)?[A-Za-z_][\w>.\-\[\]\(\)\* ]*?) (>>|<<|\+|-|&|\||\*|%|/) ([^;]+);\n", inner, re.M):
        ind, x, a, op, b = m.groups()
        value=re.sub(r'^\('+TYPE+r'\)\s*','',a)
        if re.search(r'\b'+re.escape(x)+r'\b',a) or "(" in value and not value.startswith("*("):
            continue
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"through {x}", body[:s0] + f"{ind}{x} = {a};\n{ind}{x} = {x} {op} {b};\n" + body[e0:]))
        # A compound assignment groups its entire RHS. The regex can split
        # input * 53 + 74 at '*'; input *= 53 + 74 would change the value.
        depth = 0
        grouped = True
        for token in TOKEN.findall(b):
            if token in ('(', '['):
                depth += 1
            elif token in (')', ']'):
                depth -= 1
            elif depth == 0 and (token in ('?', ',', ':') or
                                 token in PREC and PREC[token] <= PREC[op]):
                grouped = False
                break
        if grouped and depth == 0:
            out.append((f"through {x} compound", body[:s0] + f"{ind}{x} = {a};\n{ind}{x} {op}= {b};\n" + body[e0:]))
    if locs:
        top = locs[-1][1]
        indent = re.match(r"\s*", body[locs[0][0]:locs[0][1]]).group(0)
        k = 0
        for m in re.finditer(r"^(\s*)(if|while) \(\(?([A-Za-z_]\w*(?:->|\.)\w+) (==|!=|<|>|<=|>=|&)", inner, re.M):
            if span[1] + m.start() < top:
                continue
            k += 1
            t = f"tmp_ra{k}"
            s0 = span[1] + m.start()
            expr = m.group(3)
            text = body[:s0] + f"{m.group(1)}{t} = {expr};\n" + body[s0:s0 + m.start(3) - m.start()] + t + body[s0 + m.end(3) - m.start():]
            text = text[:top] + f"{indent}s32 {t};\n" + text[top:]
            out.append((f"temp for {expr}", text))
    return out



def _decl_anchor(body: str, name: str):
    """(top, indent) for inserting a declaration after the leading locals, or None."""
    span = _function_body_span(body, name)
    if not span:
        return None
    locs = _locals(body, span)
    top = locs[-1][1] if locs else span[1] + (1 if body[span[1]] == "\n" else 0)
    indent = re.match(r"\s*", body[locs[0][0]:locs[0][1]]).group(0) if locs else "    "
    return span, locs, top, indent


def call_results_to_locals(body: str, name: str) -> List[Tuple[str, str]]:
    """A call nested in a larger expression held in a local first: the allocator numbers a
    declared local below every lowering temporary, so the value takes a different register
    (`n = f(); if (a > n - 1)` reproduced fn_1_DA6C's `extsb r4`)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    protos = {m.group(2): m.group(1).strip() for m in re.finditer(
        r'(?m)^\s*(?:extern\s+)?(' + TYPE + r')\s*\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*;', body[:span[0]])}
    inner = body[top:span[2]]
    # A function-like macro may be an lvalue or have a non-call result type.
    # Hoisting W(p, o) out of W(p, o) += base loses the actual memory store.
    macros = set(re.findall(r'(?m)^\s*#\s*define\s+([A-Za-z_]\w*)\(', body))
    k = 0
    per_callee: Dict[str, list] = {}
    for m in re.finditer(r"(?m)^([ \t]+)(?!return\b)([^\n;{}]*?)\b([A-Za-z_]\w*)\s*(\([^()]*\))([^\n;{]*)([;{])\n", inner):
        ind, before, callee, args, after, term = m.groups()
        after = after + term
        if callee in ('if', 'while', 'for', 'switch', 'sizeof', 'return') or callee == name:
            continue
        if callee in macros or re.match(r'\s*(?:\+\+|--|(?:[+\-*/%&|^]|<<|>>)?=(?!=))', after):
            continue  # only rvalue function calls, never macro/assignment targets
        if not (before.strip() or after.strip()):
            continue  # a bare call statement or `x = f();` already carries its own register
        if re.fullmatch(r"\s*[A-Za-z_]\w*\s*=\s*", before) and not after.strip():
            continue
        head = re.sub(r'^\s*(if|while|switch)\s*\(', '', before)
        if head.count('(') != head.count(')'):
            continue
        k += 1
        tn = f"tmp_call{k}"
        typ = protos.get(callee, 's32')
        if typ == 'void':
            continue
        if '*' not in typ and typ not in ('u32', 'f32', 'f64', 'float', 'double', 'unsigned int', 'unsigned long'):
            typ = 's32'  # a narrow result widens once, into the local (retail's extsb after the call)
        s0 = top + m.start()
        stmt = f"{ind}{tn} = {callee}{args};\n{ind}{before}{tn}{after}\n"
        text = body[:s0] + stmt + body[top + m.end():]
        for label, pos in (("last", top), ("first", locs[0][0] if locs else top)):
            out.append((f"hold {callee} result in a local declared {label}",
                        text[:pos] + f"{indent}{declarator(typ, tn)};\n" + text[pos:]))
        per_callee.setdefault(callee, []).append((s0, top + m.end(), stmt.replace(tn, f"tmp_{callee}"), typ))
    # every site of one callee through the same reassigned local, and only the sites inside
    # conditions (fn_1_DA6C held the bound in a local for its two `if` tests, not the assignments)
    for callee, sites in per_callee.items():
        if len(sites) < 2:
            continue
        subsets = [("every", sites)]
        conds = [s for s in sites if re.match(r'\s*(if|while|for|else if)\b', s[2].split('\n')[1])]
        if 1 < len(conds) < len(sites):
            subsets.append(("condition", conds))
        for kind, chosen in subsets:
            text = body
            for s0, e0, stmt, typ in sorted(chosen, reverse=True):
                text = text[:s0] + stmt + text[e0:]
            for label, pos in (("last", top), ("first", locs[0][0] if locs else top)):
                out.append((f"hold {kind} {callee} result in one local declared {label}",
                            text[:pos] + f"{indent}{declarator(chosen[0][3], 'tmp_' + callee)};\n" + text[pos:]))
    return out


def wrap_constant_pointers(body: str, name: str) -> List[Tuple[str, str]]:
    """A pointer local holding a constant address is a rematerializable temporary numbered
    above every declared local; a one-member struct keeps it an ordinary local."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    globals_ = set(re.findall(r'(?m)^\s*extern\s+[^;(]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;', body[:span[0]]))
    inner = body[span[1]:span[2]]
    for s0, e0, typ, nm, dims in locs:
        if dims or '*' not in typ or typ.startswith('struct {'):
            continue
        init = _init_of(body[s0:e0])
        assigns = re.findall(r'(?m)^\s*' + re.escape(nm) + r'\s*=\s*([^;]+);', inner)
        values = ([init] if init else []) + assigns
        const_re = r'\(?\s*(?:\(' + TYPE + r'\)\s*)?&?\s*([A-Za-z_]\w*)(?:\s*\+\s*0x[0-9A-Fa-f]+|\s*\+\s*\d+)?\s*\)?'
        first = re.fullmatch(const_re, values[0].strip()) if values else None
        if not first or first.group(1) not in globals_:
            continue  # the first definition must be a constant address; later ones may vary
        decl_line = body[s0:e0]
        base_type = typ.rstrip('* ').strip()
        stars = typ.count('*')
        new_decl = f"{indent}struct {{ {base_type} {'*' * stars}value; }} {nm};\n"
        rest = body[e0:span[2]]
        rest = _wrap_uses(nm, rest)
        text = body[:s0] + new_decl + (f"{indent}{nm}.value = {init};\n" if init else "") + rest + body[span[2]:]
        if init:
            # the initializer becomes the first statement after the declarations
            text = body[:s0] + new_decl + rest + body[span[2]:]
            t2 = top - (e0 - s0) + len(new_decl)
            text = text[:t2] + f"{indent}{nm}.value = {init};\n" + text[t2:]
        out.append((f"struct-wrap constant pointer {nm}", text))
    return out


def decse_repeated_expressions(body: str, name: str) -> List[Tuple[str, str]]:
    """A repeated `x << k` / `x * k` computed once into a declared local used at every site:
    the compiler's own common-subexpression web is numbered above every local, a declared
    local is not (fn_12_2D888's offset)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    inner = body[top:span[2]]
    exprs: Dict[str, List[int]] = {}
    for m in re.finditer(r'\(?(?<![*\w.>])\b([A-Za-z_]\w*)\s*(<<|\*)\s*(0x[0-9A-Fa-f]+|\d+)\b\)?', inner):
        key = f"{m.group(1)} {m.group(2)} {m.group(3)}"
        exprs.setdefault(key, []).append(m.start())
    # a repeated member-array base `((T *)(base + K))[i]`: retail keeps the base in a register
    # (`addi rB, base, K; lwzx`) where a per-site recompute folds K into the displacement
    for m in re.finditer(r'\(\(' + TYPE + r'\)\(([A-Za-z_]\w*) \+ (0x[0-9A-Fa-f]+|\d+)\)\)', inner):
        key = f"ptr {m.group(0)}"
        exprs.setdefault(key, []).append(m.start())
    k = 0
    for key, sites in exprs.items():
        if len(sites) < 2:
            continue
        k += 1
        tn = f"tmp_cse{k}"
        if key.startswith('ptr '):
            expr = key[4:]
            ptype = re.match(r'\(\((' + TYPE + r')\)', expr).group(1).strip()
            text = inner.replace(expr, tn)
            decl_type = ptype
            key = expr[1:-1]  # the value assigned: (T *)(base + K)
        else:
            var = key.split()[0]
            decl_type = 's32'
            text = re.sub(r'\(?\b' + re.escape(var) + r'\s*' + re.escape(key.split()[1]) + r'\s*' + re.escape(key.split()[2]) + r'\b\)?', tn, inner)
        stmt_start = max(inner.rfind(';\n', 0, sites[0]), inner.rfind('{\n', 0, sites[0]), inner.rfind('}\n', 0, sites[0]))
        first_line = stmt_start + 2 if stmt_start >= 0 else 0
        ind = re.match(r'[ \t]*', inner[first_line:]).group(0)
        # C89: the assignment goes after the declarations of the block; a declaration
        # initializer at the first site is split into declaration and assignment
        lines = text[first_line:].split('\n')
        pending = []
        j = 0
        while j < len(lines):
            dm = DECL_RE.match(lines[j])
            if not dm or dm.group(1).strip() in ('return', 'goto', 'break', 'continue'):
                break
            if dm.group(4):
                lines[j] = f"{ind}{declarator(dm.group(1).strip(), dm.group(2) + dm.group(3))};"
                pending.append(f"{ind}{dm.group(2)} = {dm.group(4).strip()};")
            j += 1
        lines[j:j] = [f"{ind}{tn} = {key};"] + pending
        text = text[:first_line] + '\n'.join(lines)
        for label, pos in (("last", top), ("first", locs[0][0] if locs else top)):
            full = body[:top] + text + body[span[2]:]
            out.append((f"de-CSE {key} into a local declared {label}",
                        full[:pos] + f"{indent}{declarator(decl_type, tn)};\n" + full[pos:]))
    return out



SCALAR_TYPES = {'s8', 'u8', 's16', 'u16', 's32', 'u32', 'int', 'long', 'short', 'char', 'unsigned',
                'unsigned int', 'unsigned long', 'unsigned short', 'unsigned char', 'BOOL', 'f32', 'f64', 'float', 'double'}


def scalar_carriers(body: str, name: str) -> List[Tuple[str, str]]:
    """A scalar local wrapped in a one-member struct: the aggregate is numbered in the
    frontend's promotion stratum above strength-reduced induction variables and CSE temps,
    so its web claims a callee-saved register ahead of them (measured on mwcceppc: a stored
    carrier also owns a 4-byte frame home under 1.2.5n)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    for s0, e0, typ, nm, dims in locs:
        base = re.sub(r'\b(register|const|volatile)\b', '', typ).strip()
        if dims or '*' in base or base not in SCALAR_TYPES or _init_of(body[s0:e0]):
            continue
        rest = body[e0:span[2]]
        if not re.search(r'\b' + re.escape(nm) + r'\b', rest):
            continue
        rest = _wrap_uses(nm, rest)
        out.append((f"one-field carrier {nm}", body[:s0] + f"{indent}struct {{ {base} value; }} {nm};\n" + rest + body[span[2]:]))
    return out


def unwrap_scalar_carriers(body: str, name: str) -> List[Tuple[str, str]]:
    """Offer ordinary locals for anonymous one-member scalar wrappers in old seeds.

    Do not reinterpret real records or whole-object uses. Candidate compilation and
    byte verification remain the caller's responsibility, just as for other rewrites.
    """
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    directives = '\n'.join(re.findall(r'(?m)^[ \t]*#[^\n]*', code.replace('\\\n', '')))
    if '##' in directives:
        return []
    changes = []
    for start, end, _, variable, _ in _locals(body, span):
        # Macro expansion can refer to a local outside its textual function span.
        if re.search(r'\b' + re.escape(variable) + r'\b', directives):
            continue
        line_end = end if body[end - 1:end] == '\n' else body.find('\n', end)
        if re.search(r'/[/*]', body[start:line_end if line_end >= 0 else len(body)]):
            continue
        declaration = re.fullmatch(
            r'([ \t]*)struct\s*\{\s*(' + TYPE + r')(?:\s+|(?<=\*))value\s*;\s*\}'
            r'\s*' + re.escape(variable) + r'\s*;[ \t]*\n?', code[start:end])
        if not declaration:
            continue
        typ = declaration[2].strip()
        if 'volatile' in typ or not (typ in SCALAR_TYPES or '*' in typ):
            continue
        replacements = [(start, end, declaration[1] + typ + ' ' + variable + ';\n')]
        valid = True
        for use in re.finditer(r'\b' + re.escape(variable) + r'\b', code[span[1]:span[2]]):
            pos = span[1] + use.start()
            if start <= pos < end:
                continue
            prefix = code[span[1]:pos].rstrip()
            if prefix.endswith(('.', '->')):
                continue
            member = re.match(r'\s*\.\s*value\b', code[pos + len(variable):])
            if not member or re.search(r'/[/*]', body[pos + len(variable):pos + len(variable) + member.end()]):
                valid = False
                break
            replacements.append((pos + len(variable), pos + len(variable) + member.end(), ''))
        if valid:
            changes.append((variable, replacements))

    def apply(edits):
        text = body
        for start, end, replacement in sorted(edits, reverse=True):
            text = text[:start] + replacement + text[end:]
        return text

    out = [('unwrap scalar carrier ' + var, apply(edits)) for var, edits in changes]
    if len(changes) > 1:
        out.append(('unwrap all scalar carriers', apply([edit for _, edits in changes for edit in edits])))
    return out


def member_copy_states(body: str, name: str) -> List[Tuple[str, str]]:
    """Group copied 32-bit locals into real aggregate state (findings 371/376).

    MWCC promotes member copies differently from scalar constant rematerialization.
    Keep every statement and use in place; never invent a copy or move a store.
    Signed long/int have the same target representation, but `int` members avoid
    the measured signed-long second-member promotion failure. Exclude escaped,
    shadowed and qualified locals: those substitutions need a type/alias proof.
    """
    from .sdkimport import masked
    anchor = _decl_anchor(body, name)
    if not anchor:
        return []
    span, locs, top, indent = anchor
    code = masked(body)
    inner = code[top:span[2]]
    types = {'s32': 'int', 'long': 'int', 'signed long': 'int',
             'int': 'int', 'signed int': 'int',
             'u32': 'unsigned int', 'unsigned long': 'unsigned int',
             'unsigned': 'unsigned int', 'unsigned int': 'unsigned int'}
    eligible = {}
    for start, end, typ, nm, dims in locs:
        if dims or typ.strip() not in types or _init_of(body[start:end]):
            continue
        # Address/sizeof/typeof use or a nested declaration can observe the
        # changed C type/object identity. Preprocessor uses are not parsed here.
        if re.search(r'&\s*\b' + re.escape(nm) + r'\b|\b(?:sizeof|typeof)\s*\(?\s*' + re.escape(nm) + r'\b', code[span[1]:span[2]]):
            continue
        if re.search(r'\b(?!(?:return|goto|case)\b)' + TYPE + r'\s+' + re.escape(nm) + r'\s*(?:[;=,\[])', inner):
            continue
        if re.search(r'(?m)^\s*#.*\b' + re.escape(nm) + r'\b', code):
            continue
        eligible[nm] = (start, end, types[typ.strip()])
    pairs = []
    for match in re.finditer(r'(?m)^\s*(\w+)\s*=\s*(\w+)\s*;', inner):
        dest, src = match.groups()
        if dest != src and dest in eligible and src in eligible and (src, dest) not in pairs:
            pairs.append((src, dest))
    out = []
    for src, dest in pairs:
        state = 'fzgx_copy_state'
        while re.search(r'\b' + state + r'\b', code):
            state += '_'
        members = (src, dest)
        edits = [(eligible[nm][0], eligible[nm][1], '') for nm in members]
        first = min(eligible[nm][0] for nm in members)
        definition = indent + 'struct { ' + ' '.join(
            eligible[nm][2] + ' ' + nm + ';' for nm in members) + ' } ' + state + ';\n'
        for i, (start, end, text) in enumerate(edits):
            if start == first:
                edits[i] = (start, end, definition)
        for match in re.finditer(r'\b(?:' + '|'.join(map(re.escape, members)) + r')\b', inner):
            start, end = top + match.start(), top + match.end()
            prefix = code[top:start].rstrip()
            if prefix.endswith(('.', '->')):
                continue
            edits.append((start, end, state + '.' + match[0]))
        text = body
        for start, end, replacement in sorted(edits, reverse=True):
            text = text[:start] + replacement + text[end:]
        out.append((f'member-copy state {src}->{dest}', text))
    return out


def dead_uses(body: str, name: str) -> List[Tuple[str, str]]:
    """`(void) x;` after a definition: a statement-level use that keeps the value's web
    where the definition put it (no code is emitted)."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    names = [l[3] for l in locs if not l[4]][:12]
    inner = body[top:span[2]]
    for nm in names:
        for m in re.finditer(r'(?m)^([ \t]+)' + re.escape(nm) + r'(?:\.value)?\s*=[^=][^;\n]*;\n', inner):
            s = top + m.end()
            out.append((f"dead use of {nm} after its definition",
                        body[:s] + f"{m.group(1)}(void) {nm};  /* fzgx: keeps the web at its definition */\n" + body[s:]))
    return out


def self_assign_barriers(body: str, name: str) -> List[Tuple[str, str]]:
    """Zero-cost self-assignment barriers (`v = v;`) for coloring order, inline AST
    substitution, and loop constant propagation (fn_1_CDC8C, fn_4_28FC, fn_1_22F90).

    1. User-local barrier (`v = expr; v = v;`): prevents single-definition IRO expression
       folding into downstream uses while coalescing `v = v;` to zero instructions, keeping
       intermediate values in user-local vregs (colored after IRO CSE `@` temporaries).
    2. Inline parameter barrier (`param = param;`): inside `static inline` helpers, stops
       MWCC's AST inliner from substituting the caller's argument expression directly into
       uses of `param`, preserving top-down expression lowering order.
    3. Loop-step barrier (`for (...; ...; step, v = v)`): prevents `opt_propagation` from
       constant-propagating `v = 0.0f` / `v = 0` into a loop without `#pragma opt_propagation off`.
    """
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if a:
        span, locs, top, _ = a
        names = [l[3] for l in locs if not l[4]][:16]
        inner = body[top:span[2]]
        per_var_sites = []
        for nm in names:
            for m in re.finditer(r'(?m)^([ \t]+)' + re.escape(nm) + r'\s*=\s*(?!' + re.escape(nm) + r'\s*;)[^=;\n][^;\n]*;\n', inner):
                s = top + m.end()
                stmt = f"{m.group(1)}{nm} = {nm};\n"
                if body[s:s + len(stmt)] == stmt:
                    continue
                out.append((f"self-assign barrier {nm} after definition", body[:s] + stmt + body[s:]))
                per_var_sites.append((s, stmt))
            # Loop-step self-assignment barrier (`for (...; ...; step, nm = nm)`) when `nm`
            # is initialized to a constant before a `for` loop and read inside it.
            for fm in re.finditer(r'(?m)^([ \t]*)' + re.escape(nm) + r'\s*=\s*(?:0(?:\.0f?)?|-?\d+(?:\.\d*f?)?|0x[0-9A-Fa-f]+)\s*;\n'
                                  r'((?:[ \t]*[^\n;{}]+;\n){0,4}[ \t]*for\s*\([^;\n]*;[^;\n]*;)([^)\n]+)\)', inner):
                step_s, step_e = top + fm.start(3), top + fm.end(3)
                step_txt = body[step_s:step_e].strip()
                if re.search(r'\b' + re.escape(nm) + r'\b', step_txt):
                    continue
                out.append((f"loop-step self-assign barrier {nm}",
                            body[:step_s] + f" {step_txt}, {nm} = {nm}" + body[step_e:]))
        if len(per_var_sites) > 1:
            text = body
            for s, stmt in sorted(per_var_sites, reverse=True):
                text = text[:s] + stmt + text[s:]
            out.append(("self-assign barriers after all local definitions", text))
    # Inline parameter barriers (`param = param;`) in `static inline` helpers (and `name` itself if inline).
    for hm in re.finditer(r'\bstatic\s+inline\s+' + TYPE + r'\s*(?:(?<=\*)|\s)(\w+)\s*\(([^;{}]*)\)\s*\{', body):
        hname = hm.group(1)
        hspan = _function_body_span(body, hname)
        if not hspan:
            continue
        hparams = _parameters(body, hspan)
        if not hparams:
            continue
        hlocs = _locals(body, hspan)
        htop = hlocs[-1][1] if hlocs else hspan[1] + (1 if body[hspan[1]:hspan[1] + 1] == "\n" else 0)
        hindent = re.match(r"\s*", body[hlocs[0][0]:hlocs[0][1]]).group(0) if hlocs else "    "
        all_barriers = []
        for _, pnm in hparams:
            stmt = f"{hindent}{pnm} = {pnm};\n"
            if stmt in body[htop:hspan[2]]:
                continue
            all_barriers.append(stmt)
            out.append((f"inline param barrier {hname}:{pnm}", body[:htop] + stmt + body[htop:]))
        if len(all_barriers) > 1:
            out.append((f"inline param barriers {hname}:all", body[:htop] + "".join(all_barriers) + body[htop:]))
    return out


def const_array_qualifiers(body: str, name: str) -> List[Tuple[str, str]]:
    """Qualify read-only `extern` array declarations as `const` so MWCC's pre-RA
    instruction scheduler can hoist loads (`lhz`/`lwz`/`lbz`) across stores (`stb`/`stw`)
    that cannot alias read-only tables (fn_8006953C)."""
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    out: List[Tuple[str, str]] = []
    edits = []
    for m in re.finditer(r'(?m)^([ \t]*extern\s+)(?!const\b)((?:u8|s8|u16|s16|u32|s32|f32|f64|char|short|int|long|unsigned(?:\s+\w+)?|signed(?:\s+\w+)?|struct\s+\w+)\s+)'
                         r'([A-Za-z_]\w*)\s*(\[[^\]]*\](?:\[[^\]]*\])*)\s*;', code[:span[0]]):
        sym = m.group(3)
        if not re.search(r'\b' + re.escape(sym) + r'\b', code[span[1]:span[2]]):
            continue
        # Skip if written to (`sym[...] = ...`) inside the function body.
        if re.search(r'\b' + re.escape(sym) + r'\b[^\n;]*?(?<![=!<>])=(?!=)', code[span[1]:span[2]]):
            continue
        pos = m.end(1)
        edits.append((pos, sym))
        out.append((f"const-qualify read-only array {sym}", body[:pos] + "const " + body[pos:]))
    if len(edits) > 1:
        text = body
        for pos, _ in reversed(edits):
            text = text[:pos] + "const " + text[pos:]
        out.append(("const-qualify all read-only extern arrays", text))
    return out


def scalarized_loop_structs(body: str, name: str) -> List[Tuple[str, str]]:
    """Group loop-local variables into an unreferenced-address local struct so MWCC's
    `local_var_Scalarize` pass replaces each member with a synthetic `@` variable numbered
    in first-access order (colored before user locals in `SelectColors`), with zero-cost
    entry `(void)fzgx_lp.m;` touches controlling the exact `@` order without `#pragma` (fn_1_4BD4C)."""
    from .sdkimport import masked
    code = masked(body)
    a = _decl_anchor(body, name)
    if not a:
        return []
    span, locs, top, indent = a
    if len(locs) < 2:
        return []
    inner = code[top:span[2]]
    # Identify locals used inside any loop and never address-taken.
    loop_spans = list(_loop_regions(code, top, span[2]))
    if not loop_spans:
        return []
    eligible = []
    for s0, e0, typ, nm, dims in locs:
        if dims or '{' in typ or _init_of(body[s0:e0]):
            continue
        if re.search(r'&\s*\b' + re.escape(nm) + r'\b', inner):
            continue
        if any( re.search(r'\b' + re.escape(nm) + r'\b', code[ls:le]) for ls, le in loop_spans ):
            eligible.append((s0, e0, typ.strip(), nm))
    if not (2 <= len(eligible) <= 5):
        return []
    holder = 'fzgx_lp'
    while re.search(r'\b' + holder + r'\b', code):
        holder += '_'
    fields = ' '.join(f'{declarator(typ, nm)};' for _, _, typ, nm in eligible)
    struct_decl = f'{indent}struct {{ {fields} }} {holder};\n'
    first_pos = eligible[0][0]
    edits = []
    for i, (s0, e0, _, _) in enumerate(eligible):
        edits.append((s0, e0, struct_decl if i == 0 else ''))
    names_pat = re.compile(r'(?<![.\w])(?<!->)\b(' + '|'.join(re.escape(nm) for *_, nm in eligible) + r')\b')
    for m in names_pat.finditer(code, top, span[2]):
        edits.append((m.start(), m.end(), f'{holder}.{m.group(1)}'))
    base_text = body
    for s0, e0, repl in sorted(edits, reverse=True):
        base_text = base_text[:s0] + repl + base_text[e0:]
    out: List[Tuple[str, str]] = [("scalarized loop struct (" + ",".join(nm for *_, nm in eligible) + ")", base_text)]
    # Propose cyclic and reversed entry first-access orders via `(void)fzgx_lp.nm;` at function entry.
    new_a = _decl_anchor(base_text, name)
    if new_a:
        _, _, new_top, _ = new_a
        nms = [nm for *_, nm in eligible]
        orders = list(itertools.permutations(nms)) if len(nms) <= 3 else (
            [tuple(nms[i:] + nms[:i]) for i in range(len(nms))] + [tuple(reversed(nms))]
        )
        for order in orders[:8]:
            primer = ''.join(f'{indent}(void){holder}.{nm};\n' for nm in order)
            out.append((f"scalarized loop struct order {'/'.join(order)}", base_text[:new_top] + primer + base_text[new_top:]))
    return out



def variable_splits(body: str, name: str) -> List[Tuple[str, str]]:
    """A local assigned in two regions split into two locals, the second declared last:
    a second assignment otherwise creates a rename web numbered above every named local."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    inner = body[top:span[2]]
    for s0, e0, typ, nm, dims in locs:
        if dims:
            continue
        defs = [m for m in re.finditer(r'(?m)^[ \t]+' + re.escape(nm) + r'\s*=[^=]', inner)]
        if len(defs) < 2:
            continue
        # split at the second and at the last definition: a reassigned local's later webs are
        # numbered above every declared local, a fresh local declared at position P is not
        # (fn_8003043C: the late result declared right after base takes r26 after base)
        cuts = {defs[1].start(), defs[-1].start()}
        for cut in sorted(cuts):
            tail = re.sub(r'\b' + re.escape(nm) + r'\b', nm + '_2', inner[cut:])
            text = body[:top] + inner[:cut] + tail + body[span[2]:]
            positions = [("last", top)] + [(f"after {l[3]}", l[1]) for l in locs]
            for label, pos in positions:
                out.append((f"split {nm} at definition {sorted(cuts).index(cut) + 1}, {nm}_2 declared {label}",
                            text[:pos] + f"{indent}{declarator(typ.strip(), nm + '_2' + dims)};\n" + text[pos:]))
    return out



SIGN_FLIP = {'s32': 'u32', 'u32': 's32', 'int': 'u32', 's16': 'u16', 'u16': 's16', 's8': 'u8', 'u8': 's8'}


def signedness_flips(body: str, name: str) -> List[Tuple[str, str]]:
    """A local's signedness flipped: `cmpwi` against `cmplwi`, `srawi` against `srwi`,
    `extsh` against `clrlwi` are decided by the declared type, not the value."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    narrow = []
    for s0, e0, typ, nm, dims in locs:
        base = typ.strip()
        if base not in SIGN_FLIP:
            continue
        line = body[s0:e0]
        new_line = re.sub(r'\b' + re.escape(base) + r'\b', SIGN_FLIP[base], line, count=1)
        out.append((f"{nm}: {base} -> {SIGN_FLIP[base]}", body[:s0] + new_line + body[e0:]))
        if base in ('u8', 's8', 'u16', 's16'):
            # a byte/halfword local kept in a register is truncated at every compare and
            # argument (`clrlwi`); retail's untruncated form is a 32-bit local (fn_80076CD4)
            wide = 's32' if base[0] == 's' else 'u32'
            out.append((f"{nm}: {base} -> {wide}", body[:s0] + re.sub(r'\b' + re.escape(base) + r'\b', wide, line, count=1) + body[e0:]))
            out.append((f"{nm}: {base} -> s32", body[:s0] + re.sub(r'\b' + re.escape(base) + r'\b', 's32', line, count=1) + body[e0:]))
            narrow.append((s0, e0, base, line))
    if len(narrow) > 1:
        text = body
        for s0, e0, base, line in sorted(narrow, reverse=True):
            text = text[:s0] + re.sub(r'\b' + re.escape(base) + r'\b', 's32', line, count=1) + text[e0:]
        out.append(("every byte/halfword local -> s32", text))
    return out


def store_view_signedness(body: str, name: str) -> List[Tuple[str, str]]:
    """A narrow store's view type flipped: `*(u16 *)(p + 14) = x << 5;` folds the
    truncation into the shift (`clrlslwi`/`rlwinm ..,16,26`) and splits the value from
    its other uses, while an `s16` destination keeps one plain `slwi` for the store and
    the multiply (fn_12_27224). Tries each store site, then every site of one type."""
    out: List[Tuple[str, str]] = []
    sites: Dict[str, List[int]] = {}
    for m in re.finditer(r'\*\((u16|s16|u8|s8) \*\)\(', body):
        depth, i = 0, m.end() - 1
        while i < len(body):
            if body[i] == '(':
                depth += 1
            elif body[i] == ')':
                depth -= 1
                if depth == 0:
                    break
            i += 1
        if re.match(r'\s*=(?!=)', body[i + 1:i + 4]):
            sites.setdefault(m.group(1), []).append(m.start(1))
    for typ, starts in sites.items():
        flip = SIGN_FLIP[typ]
        for pos in starts[:12]:
            out.append((f"store view at {pos}: {typ} -> {flip}", body[:pos] + flip + body[pos + len(typ):]))
        if len(starts) > 1:
            text = body
            for pos in reversed(starts):
                text = text[:pos] + flip + text[pos + len(typ):]
            out.append((f"every {typ} store view -> {flip}", text))
    return out


_CAST_MASK = {'u8': '0xFF', 'u16': '0xFFFF', 'unsigned char': '0xFF', 'unsigned short': '0xFFFF'}


def mask_spellings(body: str, name: str) -> List[Tuple[str, str]]:
    """`(u8)X` -> `(X & 0xFF)` (and the u16 variant): the same `clrlwi` bytes, a different
    node. The AND result is numbered late in the vreg order, so a truncated value that
    lands in a saved colour claims a *later* slot than the conversion-result web does — the
    difference between claim 4 (r28) and claim 11 (r21) for the slot-index web of
    fn_8_5C54, in both the index assignment and the loop bound (finding 382). Signed casts
    are excluded: `(s8)X` sign-extends, which a plain mask cannot express."""
    out: List[Tuple[str, str]] = []
    for m in re.finditer(r'\((u8|u16|unsigned char|unsigned short)\)\s*'
                         r'([A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)*(?:\[[^\]]*\])*|\([^()]*\))', body):
        typ, operand = m.group(1), m.group(2)
        inner = operand[1:-1] if operand.startswith('(') else operand
        out.append((f"({typ}) -> mask", body[:m.start()] + f"({inner} & {_CAST_MASK[typ]})" + body[m.end():]))
    return out


def float_precision(body: str, name: str) -> List[Tuple[str, str]]:
    """Single against double arithmetic: an unsuffixed literal in a float expression promotes
    to double (`fsub` where retail has `fsubs`), and an `f64` local keeps a double temp where
    retail computed in single precision; try the literal suffixes and f32 locals."""
    out: List[Tuple[str, str]] = []
    a = _decl_anchor(body, name)
    if not a:
        return out
    span, locs, top, indent = a
    inner = body[span[1]:span[2]]
    lits = list(re.finditer(r'(?<![\w.])(\d+\.\d*|\.\d+)(?:[eE][+-]?\d+)?(?![\w.])', inner))
    if lits:
        text = inner
        for m in reversed(lits):
            text = text[:m.end()] + 'f' + text[m.end():]
        out.append(("float literal suffixes at every site", body[:span[1]] + text + body[span[2]:]))
        for m in lits[:8]:
            out.append((f"float literal suffix at {m.group(0)}", body[:span[1]] + inner[:m.end()] + 'f' + inner[m.end():] + body[span[2]:]))
    for s0, e0, typ, nm, dims in locs:
        if typ.strip() in ('f64', 'double'):
            line = body[s0:e0]
            out.append((f"{nm}: f64 -> f32", body[:s0] + re.sub(r'\b(f64|double)\b', 'f32', line, count=1) + body[e0:]))
            cast = re.sub(r'\(f64\)\s*', '', body[e0:span[2]])
            out.append((f"{nm}: f64 -> f32 without double casts", body[:s0] + re.sub(r'\b(f64|double)\b', 'f32', line, count=1) + cast + body[span[2]:]))
    return out



def embedded_call_assignments(body: str, name: str) -> List[Tuple[str, str]]:
    """`x = expr; f(.., x, ..)` -> `f(.., (x = expr), ..)`: the load lowers straight into the
    variable's web instead of a temporary plus a copy (`lwz r0; mr rX, r0`)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    inner = body[span[1]:span[2]]
    pat = re.compile(r'(?m)^([ \t]+)([A-Za-z_]\w*) = ([^;\n]+);\n([ \t]+)((?:[A-Za-z_][\w.>\-]*\s*=\s*)?[A-Za-z_]\w*\s*\()([^;\n]*?)\)\s*;\n')
    for m in pat.finditer(inner):
        ind, x, expr, ind2, callhead, args = m.groups()
        if x == name or re.search(r'\b' + re.escape(x) + r'\b', expr):
            continue
        argl = [a.strip() for a in args.split(',')]
        if argl.count(x) != 1 or re.search(r'\b' + re.escape(x) + r'\b', callhead):
            continue
        argl[argl.index(x)] = f"({x} = {expr})"
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"embed {x} = ... in its call argument",
                    body[:s0] + f"{ind2}{callhead}{', '.join(argl)});\n" + body[e0:]))
    return out



def condition_embedded_assignments(body: str, name: str) -> List[Tuple[str, str]]:
    """`if (G OP k) { x = G; } else ...` and `x = G; if (x OP k)` -> `if ((x = G) OP k)`: the
    load lowers straight into x's web (a virgin named local otherwise gets `lwz rT; cmp rT;
    mr rX, rT`); keeping a redundant `x = G;` in the then-branch preserves the non-inverted
    branch pair (fn_8000CEBC, capture-validated)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    inner = body[span[1]:span[2]]
    # form A: the then-branch assigns the compared global
    for m in re.finditer(r'(?m)^([ \t]+)if \(([A-Za-z_][\w.>\-\[\]]*) (<=|<|>=|>|==|!=) ([^()\n]+?)\) \{\n([ \t]+)([A-Za-z_]\w*) = \2;\n', inner):
        ind, g, op, k, ind2, x = m.groups()
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"embed {x} = {g} in its condition", body[:s0] + f"{ind}if (({x} = {g}) {op} {k}) {{\n" + body[e0:]))
        out.append((f"embed {x} = {g} in its condition, then-branch reload kept",
                    body[:s0] + f"{ind}if (({x} = {g}) {op} {k}) {{\n{ind2}{x} = {g};\n" + body[e0:]))
    # form B: an assignment immediately followed by a test of the variable
    for m in re.finditer(r'(?m)^([ \t]+)([A-Za-z_]\w*) = ([^;\n]+);\n\1if \(\2 (<=|<|>=|>|==|!=) ([^()\n]+?)\) \{\n', inner):
        ind, x, g, op, k = m.groups()
        s0, e0 = span[1] + m.start(), span[1] + m.end()
        out.append((f"embed {x} = {g} in the following condition", body[:s0] + f"{ind}if (({x} = {g}) {op} {k}) {{\n" + body[e0:]))
    return out


def rewrites(body: str, name: str) -> List[Tuple[str, str]]:
    """Every single second-stage rewrite of a body."""
    out: List[Tuple[str, str]] = []
    for fn in (scope_moves, split_inits, hoists, compound_assignments, through_local, return_values,
               call_results_to_locals, wrap_constant_pointers, decse_repeated_expressions,
               member_copy_states, scalar_carriers, unwrap_scalar_carriers, dead_uses,
               self_assign_barriers, const_array_qualifiers, scalarized_loop_structs,
               variable_splits, signedness_flips, store_view_signedness, mask_spellings,
               float_precision, embedded_call_assignments, condition_embedded_assignments, loop_helpers):
        try:
            out += fn(body, name)
        except Exception:
            continue
    return out


def return_values(body: str, name: str) -> List[Tuple[str, str]]:
    """Recover an omitted result when a void draft leaves the value outside r3.

    Tail calls forward their own result; preserving a local across the call would
    create a different live range and hide the actual return convention.
    """
    signature = re.search(rf'\bvoid\s+{re.escape(name)}\s*\(', body)
    span = _function_body_span(body, name)
    if not signature or not span:
        return []
    locals_ = _locals(body, span)
    values = [nm for _, _, ty, nm, dims in locals_ if not dims and
              (ty.strip() in ('u32', 's32', 'int', 'unsigned', 'u16', 's16', 'u8', 's8') or '*' in ty)]
    out = []
    for value in values:
        inner = body[span[1]:span[2]]
        inner = re.sub(r'\breturn\s*;', f'return (u32){value};', inner)
        inner += f'    return (u32){value};\n'
        text = body[:span[1]] + inner + body[span[2]:]
        text = text[:signature.start()] + 'u32' + text[signature.start() + 4:]
        out.append((f'return {value}', text))
        calls = set()
        def forward(match):
            callee = match[2]
            if not re.search(rf'\bextern\s+void\s+{re.escape(callee)}\s*\(', text):
                return match[0]
            calls.add(callee)
            return f'{match[1]}return {callee}({match[3]});'
        inner = re.sub(r'(?m)^([ \t]*)(\w+)\(([^;\n]*)\);(?=\s*})', forward, inner)
        if calls:
            text = body[:span[1]] + inner + body[span[2]:]
            text = text[:signature.start()] + 'u32' + text[signature.start() + 4:]
            for callee in calls:
                text = re.sub(rf'\bextern\s+void(?=\s+{re.escape(callee)}\s*\()', 'extern u32', text)
            out.append((f'return {value}, forward tail calls', text))
    return out


def reorder(body: str, locs, order: Tuple[int, ...]) -> str:
    lines = [body[s:e] for s, e, *_ in locs]
    return body[:locs[0][0]] + "".join(lines[i] for i in order) + body[locs[-1][1]:]


def scope_moves(body: str, name: str) -> List[Tuple[str, str]]:
    """Each local re-declared in an inner block around its uses; each local split off
    into its own declaration block after a blank line (a second declaration group)."""
    out: List[Tuple[str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    if not locs:
        return out
    inner = body[span[1]:span[2]]
    for s, e, typ, nm, dims in locs:
        uses = [span[1] + m.start() for m in re.finditer(rf"\b{re.escape(nm)}\b", inner)]
        uses = [u for u in uses if u >= locs[-1][1]]
        if not uses:
            continue
        line_start = body.rfind("\n", 0, uses[0]) + 1
        line_end = body.find("\n", uses[-1]) + 1
        # only when the use range is a run of whole statements at one nesting depth
        seg = body[line_start:line_end]
        if seg.count("{") != seg.count("}"):
            continue
        decl = body[s:e]
        text = body[:s] + body[e:]
        a, b = line_start - (e - s), line_end - (e - s)
        out.append((f"scope {nm}", text[:a] + "{\n" + decl + text[a:b] + "}\n" + text[b:]))
    return out


_ASSIGNS = r'(?:\+\+|--)\s*{0}\b|\b{0}\s*(?:\+\+|--|(?:[-+*/%&|^]|<<|>>)?=(?!=))|&\s*{0}\b'


def _parameters(body: str, span) -> List[Tuple[str, str]]:
    """(type, name) of each named parameter of the function at `span`."""
    sig = body[span[0]:span[1]]
    inner = sig[sig.find('(') + 1:sig.rfind(')')]
    out = []
    for part in inner.split(','):
        m = re.fullmatch(r'\s*(' + TYPE + r')\s*([A-Za-z_]\w*)\s*', part)
        if m:
            out.append((m[1].strip(), m[2]))
    return out


def _loop_regions(code: str, start: int, end: int):
    """(start, end) of every for/while/do statement in code[start:end]."""
    for m in re.finditer(r'(?m)^[ \t]*(for|while|do)\b', code[start:end]):
        s = start + m.start()
        i = start + m.end()
        if m[1] != 'do':
            if code[i:i + 1].strip() == '':
                i = len(code[:i]) + (len(code[i:]) - len(code[i:].lstrip()))
            if code[i:i + 1] != '(':
                continue
            depth = 0
            while i < end:
                depth += {'(': 1, ')': -1}.get(code[i], 0)
                i += 1
                if depth == 0:
                    break
        j = i + len(code[i:end]) - len(code[i:end].lstrip())
        if code[j:j + 1] == '{':
            depth = 0
            while j < end:
                depth += {'{': 1, '}': -1}.get(code[j], 0)
                j += 1
                if depth == 0:
                    break
        else:
            j = code.find(';', j, end) + 1
            if j <= 0:
                continue
        if m[1] == 'do':
            w = re.match(r'\s*while\s*\([^;]*\)\s*;', code[j:end])
            if not w:
                continue
            j += w.end()
        nl = code.find('\n', j - 1, end)
        yield s, (nl + 1 if nl >= 0 else j)


def loop_helpers(body: str, name: str) -> List[Tuple[str, str]]:
    """A loop moved into a `static inline` helper, with any directly preceding
    initializers of loop-only locals. MWCC numbers an inlined helper's locals as one
    coalescing group, which is what makes retail initialise a second loop value by
    copying the first (`li r31, 0; mr r30, r31`) where a function-level loop gives
    `li; li` under every spelling, type and pragma (fn_80077BD4, fn_1_1384C,
    fn_80078F0C, fn_1_14DD68, fn_3_6E14 and fn_1_152A28 closed this way). Values the
    loop only reads become parameters; locals used nowhere else move inside, in each
    declaration order."""
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    locs = _locals(body, span)
    if not locs:
        return []
    decl_end = locs[-1][1]
    params = _parameters(body, span)
    vars_ = {nm: (typ, dims) for _, _, typ, nm, dims in locs}
    # block-scope declarations type the values a loop reads from its enclosing block
    block_vars = {}
    for line in body[decl_end:span[2]].splitlines():
        dm = DECL_RE.match(line)
        if dm and dm.group(2) not in vars_ and dm.group(1).split()[0] not in ('return', 'goto'):
            block_vars.setdefault(dm.group(2), (dm.group(1).strip(), dm.group(3)))
    # anonymous record locals cannot be named in a helper's parameter list
    opaque = {nm for nm, v in vars_.items() if '{' in v[0]}
    vars_ = {nm: v for nm, v in vars_.items() if nm not in opaque}
    ptypes = {nm: typ for typ, nm in params}
    line_start = body.rfind('\n', 0, span[0]) + 1
    out: List[Tuple[str, str]] = []
    for k, (ls, le) in enumerate(_loop_regions(code, decl_end, span[2])):
        starts = [ls]
        # up to four directly preceding simple assignments join the region
        prev = ls
        for _ in range(4):
            pm = re.search(r'(?m)^[ \t]*[A-Za-z_][\w.]*\s*=(?!=)[^;{}]*;[ \t]*\n(?:[ \t]*\n)*\Z', code[decl_end:prev])
            if not pm:
                break
            prev = decl_end + pm.start()
            starts.append(prev)
        for rs in starts:
            region = code[rs:le]
            if re.search(r'\b(?:return|goto)\b', region) or re.search(r'(?m)^\s*\w+\s*:(?!:)', region):
                continue
            if any(re.search(rf'\b{re.escape(nm)}\b', region) for nm in opaque):
                continue
            outside = code[decl_end:rs] + code[le:span[2]]
            used = [nm for nm in dict.fromkeys(list(vars_) + list(ptypes)) if re.search(rf'\b{re.escape(nm)}\b', region)]
            inner_locals, args, results, copies, ok = [], [], [], [], True
            def defined_first(nm, text):
                first = re.search(rf'\b{re.escape(nm)}\b', text)
                return first is not None and re.match(rf'{re.escape(nm)}\s*=(?!=)', text[first.start():])
            for nm in used:
                if nm in vars_ and not re.search(rf'\b{re.escape(nm)}\b', outside):
                    inner_locals.append(nm)
                    continue
                after = code[le:span[2]]
                if nm in vars_ and not vars_[nm][1] and defined_first(nm, region) and \
                        (not re.search(rf'\b{re.escape(nm)}\b', after) or defined_first(nm, after)):
                    # a counter every later loop re-initialises: the helper gets its own
                    copies.append(nm)
                    continue
                if re.search(_ASSIGNS.format(re.escape(nm)), region):
                    # one scalar local the loop computes for later code is the result
                    if nm in vars_ and not vars_[nm][1] and not re.search(rf'&\s*{re.escape(nm)}\b', region):
                        results.append(nm)
                        continue
                    ok = False
                    break
                if nm in vars_:
                    typ, dims = vars_[nm]
                    args.append((typ + ' *' if dims else typ, nm))
                else:
                    args.append((ptypes[nm], nm))
            for nm, (typ, dims) in block_vars.items():
                # declared in an enclosing block (not inside the region): a read-only argument
                if not ok or not re.search(rf'\b{re.escape(nm)}\b', region) or \
                        re.search(rf'^\s*{re.escape(typ)}\s*\*?\s*{re.escape(nm)}\b', region, re.M):
                    continue
                if re.search(_ASSIGNS.format(re.escape(nm)), region):
                    ok = False
                    break
                args.append((typ + ' *' if dims else typ, nm))
            if not ok or not (inner_locals or copies) or len(results) > 1:
                continue
            if results:
                # the result's incoming value must not flow into the helper
                first = re.search(rf'\b{re.escape(results[0])}\b', region)
                if not re.match(rf'{re.escape(results[0])}\s*=(?!=)', region[first.start():]):
                    continue
            rtype = vars_[results[0]][0] if results else 'void'
            helper = f'{name}_loop{k}'
            ptext = ', '.join(f'{typ} {nm}' if not typ.endswith('*') else f'{typ}{nm}' for typ, nm in args) or 'void'
            decls = {nm: next(body[s:e] for s, e, _, n2, _ in locs if n2 == nm) for nm in inner_locals}
            if results:
                decls[results[0]] = next(body[s:e] for s, e, _, n2, _ in locs if n2 == results[0])
            for nm in copies:
                decls[nm] = next(body[s:e] for s, e, _, n2, _ in locs if n2 == nm)
            members = inner_locals + copies + results
            orders = list(itertools.permutations(members)) if len(members) <= 3 else \
                [tuple(members[i:] + members[:i]) for i in range(len(members))]
            indent = re.match(r'[ \t]*', body[rs:])[0]
            for order in orders:
                fn = (f'static inline {rtype} {helper}({ptext}) {{\n' +
                      ''.join(decls[nm] if decls[nm].endswith('\n') else decls[nm] + '\n' for nm in order) +
                      body[rs:le] + (f'    return {results[0]};\n' if results else '') + '}\n\n')
                target = f'{results[0]} = ' if results else ''
                call = f'{indent}{target}{helper}({", ".join(nm for _, nm in args)});\n'
                text = body[:rs] + call + body[le:]
                for s, e, _, nm, _ in sorted((l for l in locs if l[3] in inner_locals), reverse=True):
                    text = text[:s] + text[e:]
                text = text[:line_start] + fn + text[line_start:]
                out.append((f'loop {k} helper{"+init" if rs != ls else ""} {"/".join(order)}', text))
    return out


def normalise(body: str) -> str:
    """One declarator per line (`u32 a, b;` -> `u32 a;\n u32 b;`), so every family sees every local."""
    lines = []
    for line in body.splitlines(keepends=True):
        # Match only a declaration prefix before splitting declarators. A repeated
        # declaration regex backtracks exponentially on long generated call lines.
        match = re.fullmatch(r'([ \t]+)(struct[ \t]+\w+|[A-Za-z_]\w*)[ \t]+([^;]+);[ \t]*(\n?)', line)
        if match and ',' in match[3]:
            decls = match[3].split(',')
            if all(re.fullmatch(r'\*?\s*[A-Za-z_]\w*(?:\[[^\]]*\])*\s*', decl) for decl in decls):
                lines.append('\n'.join(f'{match[1]}{match[2]} {decl.strip()};' for decl in decls) + match[4])
                continue
        lines.append(line)
    return ''.join(lines)




FLIP = {"s32": "u32", "u32": "s32", "s16": "u16", "u16": "s16", "s8": "u8", "u8": "s8", "f32": "f64", "f64": "f32", "int": "u32"}

def argument_lifetimes(body, name, callees=None):
    """Materialize typed call arguments, optionally selected by retail evidence."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:
        return []
    locs=_locals(body,span);out=[];groups={};calls=call_sites(code)
    prototypes={callee:args for callee,start,end,args in calls if start<span[0] and re.match(r'\s*;',code[end:])}
    for callee,start,end,args in calls:
        if not span[1]<=start<end<=span[2] or (callees is not None and callee not in callees):
            continue
        lo=code.rfind('\n',span[1],start)+1
        prefix=re.fullmatch(r'([ \t]*)((?:[A-Za-z_][\w>.\-\[\]]*\s*=\s*)?)',code[lo:start])
        suffix=re.match(r'[ \t]*;[ \t]*\n',code[end:])
        if not prefix or not suffix:
            continue
        indent,lhs=prefix.groups();hi=end+suffix.end()
        parts=[body[a:b].strip() for a,b in args]
        parameter_types = []
        if callee in prototypes:
            for a,b in prototypes[callee]:
                parameter = code[a:b].strip()
                typed = re.fullmatch('('+TYPE+r')(?:\s+\w+)?', parameter)
                parameter_types.append(typed[1] if typed else None)
        for k, a in enumerate(parts):
            known_type = parameter_types[k] if k < len(parameter_types) else None
            if not known_type and re.fullmatch(r"[A-Za-z_]\w*|-?\d+|0x[0-9A-Fa-f]+|&[A-Za-z_]\w*|\d+\.\d*f?", a):
                continue
            tname = f"lab_t{k}"
            while re.search(r'\b'+tname+r'\b',body):
                tname += '_'
            newparts = list(parts); newparts[k] = tname
            replacement=f"{indent}{tname} = {a};\n{indent}{lhs}{callee}({', '.join(newparts)});\n"
            text = body[:lo] + replacement + body[hi:]
            # The call's conversion belongs in the temporary too. In particular,
            # pointer arguments are not integers and narrow counts truncate here.
            cast = re.match(r'\(('+TYPE+r')\)',a)
            ty = known_type or (cast[1] if cast else None) or ("f32" if re.search(r"\d\.\d|f32|unk_\w*f\b", a) else "u32")
            ins_at = locs[-1][1] if locs else span[1] + 1
            text = text[:ins_at] + f"    {ty} {tname};\n" + text[ins_at:]
            out.append((f"hoist arg {k} of {callee}", text))
            groups.setdefault((callee,k,ty,tname),[]).append((lo,hi,replacement))
        result=re.search(r'(?m)^[ \t]*(?:extern\s+)?('+TYPE+r')\s*'+re.escape(callee)+r'\s*\(',body[:span[0]])
        if callees is not None and result and len(parameter_types)==len(parts) and all(ty and ty!='...' for ty in parameter_types):
            helper=name+'_call_'+callee
            while re.search(r'\b'+re.escape(helper)+r'\b',body):
                helper+='_'
            for order in (list(range(len(parts))),list(reversed(range(len(parts))))):
                params=', '.join(parameter_types[i]+' a'+str(i) for i in order)
                call=callee+'('+', '.join('a'+str(i) for i in range(len(parts)))+');'
                definition='static inline '+result[1]+' '+helper+'('+params+') { '+('' if result[1].strip()=='void' else 'return ')+call+' }\n'
                a,b=start,end
                text=body[:a]+helper+'('+', '.join(parts[i] for i in order)+')'+body[b:]
                at=body.rfind('\n',0,span[0])+1
                text=text[:at]+definition+text[at:]
                out.append((f'call parameter order {callee} '+','.join(map(str,order))+f' at {a}',text))
    for (callee,k,ty,tname),edits in groups.items():
        if len(edits)<2:
            continue
        text=body
        for a,b,value in reversed(edits):
            text=text[:a]+value+text[b:]
        at=locs[-1][1] if locs else span[1]+1
        text=text[:at]+f'    {ty} {tname};\n'+text[at:]
        out.append((f'hoist arg {k} of {callee} at every site',text))
    return out


def perturbations(body: str, name: str) -> List[Tuple[str, str, str]]:
    """(family, label, text) for every single rewrite."""
    out: List[Tuple[str, str, str]] = []
    span = _function_body_span(body, name)
    if not span:
        return out
    locs = _locals(body, span)
    # 1. declaration order: every permutation of up to 5 locals, else reverse, adjacent swaps,
    #    and each single local moved to either end of the list (finding 382: only the LAST
    #    slot promoted fn_8_5C54's counter `n` above the other named locals and returned its
    #    r30 claim, while the first and middle slots measured as no-ops - the rank is not a
    #    straight function of slot order, so both ends get probed explicitly)
    if len(locs) >= 2:
        lines = [body[s:e] for s, e, *_ in locs]
        blk_s, blk_e = locs[0][0], locs[-1][1]
        n = len(lines)
        if n <= 5:
            perms = list(itertools.permutations(range(n)))
        else:
            perms = [tuple(reversed(range(n)))]
            perms += [tuple(list(range(i)) + [i + 1, i] + list(range(i + 2, n))) for i in range(n - 1)]
            perms += [tuple(list(range(i)) + list(range(i + 1, n)) + [i]) for i in range(n)]
            perms += [tuple([i] + list(range(i)) + list(range(i + 1, n))) for i in range(n)]
        for perm in perms:
            if list(perm) == list(range(len(lines))):
                continue
            out.append(("decl-order", "order " + ",".join(locs[i][3] for i in perm), body[:blk_s] + "".join(lines[i] for i in perm) + body[blk_e:]))
    # 2. local types
    for s, e, typ, nm, dims in locs:
        t0 = typ.strip()
        if t0 in FLIP:
            out.append(("local-type", f"{nm}: {t0}->{FLIP[t0]}", body[:s] + body[s:e].replace(t0, FLIP[t0], 1) + body[e:]))
    # 3. inner block scope for a local: declare it where it is first used
    inner = body[span[1]:span[2]]
    for s, e, typ, nm, dims in locs:
        uses = [m.start() for m in re.finditer(rf"\b{re.escape(nm)}\b", inner)]
        uses = [u for u in uses if span[1] + u >= locs[-1][1]]
        if not uses:
            continue
        first = span[1] + uses[0]
        line_start = body.rfind("\n", 0, first) + 1
        last = span[1] + uses[-1]
        line_end = body.find("\n", last) + 1
        decl = body[s:e]
        text = body[:s] + body[e:]
        shift = e - s
        a, b = line_start - shift, line_end - shift
        text = text[:a] + "{\n" + decl + text[a:b] + "}\n" + text[b:]
        out.append(("inner-scope", f"scope {nm}", text))
    # Nested switch arms commonly reuse a spelling for unrelated locals. Count
    # reads inside the declaration's scope, rather than the whole function.
    from .sdkimport import masked
    code = masked(body)
    scopes, stack = [], []
    for token in re.finditer(r'[{}]', code):
        if token[0] == '{':
            stack.append(token.start())
        elif stack:
            scopes.append((stack.pop(), token.start()))
    # 4. temp inlining: `v = expr;` used once afterwards -> substitute
    for m in re.finditer(r"^(\s*)([A-Za-z_]\w*) = ([^;]+);\n", body[span[1]:span[2]], re.M):
        v, expr = m.group(2), m.group(3)
        start, end = span[1] + m.start(), span[1] + m.end()
        declarations = list(re.finditer(r'\b'+TYPE+r'\s*(?:(?<=\*)|\s)'+re.escape(v)+r'\s*[;=]', code[span[1]:start]))
        scope_end = span[2]
        for declaration in reversed(declarations):
            enclosing = [(a,b) for a,b in scopes if a < span[1]+declaration.start() < start < b]
            if enclosing:
                scope_end = min(enclosing, key=lambda s:s[1]-s[0])[1]
                break
        rest = body[end:scope_end]
        uses = list(re.finditer(rf"\b{re.escape(v)}\b", rest))
        if len(uses) == 1 and not re.search(rf"\b{re.escape(v)}\s*=", rest):
            # Move only into the immediately following statement. Calls, writes
            # or control flow between the definition and read can change it.
            prefix = rest[:uses[0].start()]
            if re.search(r'[;{}]|\+\+|--', prefix) or call_sites(expr+prefix):
                continue
            new_rest = rest[:uses[0].start()] + f"({expr})" + rest[uses[0].end():]
            out.append(("inline-temp", f"inline {v} at {start}", body[:start] + new_rest + body[scope_end:]))
    out.extend(("hoist-arg",label,text) for label,text in argument_lifetimes(body,name))
    # 6. increment forms
    for m in re.finditer(r"^(\s*)(\S[^=\n]*?) = \2 \+ 1;\n", body, re.M):
        out.append(("increment", "x = x + 1 -> x++", body[:m.start()] + f"{m.group(1)}{m.group(2)}++;\n" + body[m.end():]))
    for m in re.finditer(r"^(\s*)(\S[^\n]*?)\+\+;\n", body, re.M):
        out.append(("increment", "x++ -> x = x + 1", body[:m.start()] + f"{m.group(1)}{m.group(2)} = {m.group(2)} + 1;\n" + body[m.end():]))
    # 7. return forms
    for m in re.finditer(r"^(\s*)return ([A-Za-z_]\w*\([^;]*\));\n", body, re.M):
        out.append(("return-form", "return f() -> f(); return", body[:m.start()] + f"{m.group(1)}{m.group(2)};\n{m.group(1)}return;\n" + body[m.end():]))
    # 8. address forms
    for m in re.finditer(r"\(struct (\w+) \*\)&([A-Za-z_]\w*)", body):
        out.append(("address-form", f"drop cast on &{m.group(2)}", body[:m.start()] + f"&{m.group(2)}" + body[m.end():]))
    # 9. compare forms
    for m in re.finditer(r"\(([^()]+?) != 0\)", body):
        out.append(("compare-form", "x != 0 -> x", body[:m.start()] + f"({m.group(1)})" + body[m.end():]))
    for m in re.finditer(r"\(([^()]+?) == 0\)", body):
        out.append(("compare-form", "x == 0 -> !x", body[:m.start()] + f"(!({m.group(1)}))" + body[m.end():]))
    # 11. commute the operands of a commutative binary operator (register assignment follows
    #     operand order)
    for m in re.finditer(r"\(([A-Za-z_][\w>.\-\[\]]*) ([+*&|^]|==|!=) ([A-Za-z_][\w>.\-\[\]]*|-?\d+|0x[0-9A-Fa-f]+)\)", body[span[1]:span[2]]):
        a_, op, b_ = m.groups()
        if a_ == b_:
            continue
        s0 = span[1] + m.start(); e0 = span[1] + m.end()
        out.append(("commute", f"{a_} {op} {b_} -> {b_} {op} {a_}", body[:s0] + f"({b_} {op} {a_})" + body[e0:]))
    # 12. swap two adjacent statements that share no identifier (independent: order is free)
    from .dataimport import BASIC
    _, variables = declared_types(body,span[0])
    layouts = record_layouts(body,span[0],variables)
    stmts_ = [(m.start() + span[1], m.end() + span[1], m.group(0)) for m in re.finditer(r"^[ \t]*[^\n{}]+;\n", body[span[1]:span[2]], re.M)]
    for (s1, e1, t1), (s2, e2, t2) in zip(stmts_, stmts_[1:]):
        if e1 != s2:
            continue
        ids1 = set(re.findall(r"[A-Za-z_]\w*", t1)); ids2 = set(re.findall(r"[A-Za-z_]\w*", t2))
        shared=ids1 & ids2
        for root in tuple(shared):
            accesses=[]
            for text in (t1,t2):
                pattern=r'\b'+re.escape(root)+r'(?:(?:->|\.)\w+)+'
                members=re.findall(pattern,text)
                if not members or re.search(r'\b'+re.escape(root)+r'\b',re.sub(pattern,'',text)):break
                ranges=[]
                for expression in members:
                    layout=member_layout(expression,layouts,variables)
                    if not layout or layout[0]!=root or layout[3] is not None:break
                    typ=layout[2].strip();width=4 if '*' in typ else BASIC.get(typ,(0,))[0]
                    if not width or 'volatile' in typ:break
                    ranges.append((layout[1],layout[1]+width))
                if len(ranges)!=len(members):break
                accesses.append(ranges)
            if len(accesses)==2 and all(b<=c or d<=a for a,b in accesses[0] for c,d in accesses[1]):shared.remove(root)
        if shared or "(" in t1 and "(" in t2:  # shared values or two calls: order carries meaning
            continue
        out.append(("stmt-swap", f"swap `{t1.strip()[:30]}` / `{t2.strip()[:30]}`", body[:s1] + t2 + t1 + body[e2:]))
    pure=set()
    for helper in re.finditer(r'\bstatic\s+inline\s+'+TYPE+r'\s*(?:(?<=\*)|\s)(\w+)\([^;{}]*\)\s*\{',body[:span[0]]):
        helper_span=_function_body_span(body,helper[1])
        if not helper_span:continue
        text=body[helper_span[1]:helper_span[2]]
        locals_={r[3] for r in _locals(body,helper_span)}
        writes=re.findall(r'\b(\w+(?:(?:->|\.)\w+)*)\s*=(?!=)',text)
        if (not call_sites(text) and not re.search(r'volatile|\+\+|--|(?:^|;)\s*\*[^;]+=(?!=)',text)
                and all('->' not in w and w.split('.')[0] in locals_ for w in writes)):pure.add(helper[1])
    for (a,b,first),(c,d,second),(e,f,third) in zip(stmts_,stmts_[1:],stmts_[2:]):
        if body[b:c].strip() or body[d:e].strip():continue
        store=re.fullmatch(r'\s*(\w+(?:(?:->|\.)\w+)+)\s*=\s*(-?\d+|0x[0-9A-Fa-f]+)[uU]?;\s*',first)
        load=re.fullmatch(r'\s*(\w+)\s*=\s*([^;]+);\s*',second)
        address=re.fullmatch(r'\s*(\w+)\s*=\s*([^;]+);\s*',third)
        if not store or not load or not address or '*' not in variables.get(address[1],''):continue
        if re.search(r'\b'+re.escape(store[1])+r'\b',second+third) or re.search(r'\+\+|--|volatile',second+third):continue
        if any(fn not in pure for fn,_,_,_ in call_sites(second+third)):continue
        if re.search(r'\b'+re.escape(load[1])+r'\b',address[2]) and load[1]!=address[1]:
            out.append(('stmt-swap',f'form address before store at {a}',body[:a]+second+third+first+body[f:]))
    # 13. struct layout: shift every field of a block-private struct by a small delta (front padding)
    for m in re.finditer(r"(?:typedef\s+)?struct\s+\w*\s*\{([^}]*)\}", body):
        inner = m.group(1)
        for delta in (4, 8, -4, -8):
            if delta > 0:
                out.append(("struct-pad", f"+{delta} front padding", body[:m.start(1)] + f"\n    u8 lab_pad[{delta}];" + inner + body[m.end(1):]))
            else:
                pm = re.match(r"\s*u8\s+(\w+)\[(0x[0-9A-Fa-f]+|\d+)\];", inner)
                if pm and int(pm.group(2), 0) + delta > 0:
                    out.append(("struct-pad", f"{delta} front padding", body[:m.start(1)] + re.sub(r"^\s*u8\s+\w+\[[^\]]+\];", f"\n    u8 {pm.group(1)}[{int(pm.group(2), 0) + delta}];", inner, count=1) + body[m.end(1):]))
    # 14. a repeated non-trivial expression becomes a local computed once
    exprs = {}
    for m in re.finditer(r"[A-Za-z_]\w*(?:->|\.)\w+(?:(?:->|\.)\w+)*|[A-Za-z_]\w*\[[^\]]+\]", body[span[1]:span[2]]):
        exprs[m.group(0)] = exprs.get(m.group(0), 0) + 1
    for ex, n in exprs.items():
        if n < 2 or re.search(rf"{re.escape(ex)}\s*=[^=]", body[span[1]:span[2]]):
            continue
        first = body.find(ex, span[1])
        line_start = body.rfind("\n", 0, first) + 1
        ins_at = locs[-1][1] if locs else span[1] + 1
        ty = "f32" if re.search(r"f32|\bf\w*\b", ex) and False else "u32"
        text = body[:line_start] + f"    lab_v = {ex};\n" + body[line_start:]
        text = text.replace(ex, "lab_v")
        text = text.replace("    lab_v = lab_v;\n", f"    lab_v = {ex};\n", 1)
        text = text[:ins_at] + f"    {ty} lab_v;\n" + text[ins_at:]
        out.append(("repeat-to-local", f"local for {ex}", text))
    # 10. parameters: signedness flips and unused trailing parameters
    pm = re.search(rf"\b{re.escape(name)}\s*\(([^)]*)\)\s*\{{", body)
    if pm:
        params = [x.strip() for x in pm.group(1).split(",")] if pm.group(1).strip() not in ("", "void") else []
        for k, prm in enumerate(params):
            t0 = prm.split()[0]
            if t0 in FLIP:
                np = list(params); np[k] = prm.replace(t0, FLIP[t0], 1)
                out.append(("param-type", f"param {k}: {t0}->{FLIP[t0]}", body[:pm.start(1)] + ", ".join(np) + body[pm.end(1):]))
        for extra in (1, 2, 3):
            np = params + [f"u32 lab_unused{i}" for i in range(extra)]
            out.append(("param-count", f"+{extra} unused params", body[:pm.start(1)] + ", ".join(np) + body[pm.end(1):]))
    return out




FIELD_FLIP = {"u16": "s16", "s16": "u16", "u8": "s8", "s8": "u8", "u32": "s32", "s32": "u32"}


def _fn_span(body: str, name: str):
    return _function_body_span(body, name)


def extra_families(body: str, name: str) -> List[Tuple[str, str, str]]:
    """(family, label, text): near/far externs, pointer locals for globals, field signedness,
    loop direction, compare casts, call-result temps."""
    out: List[Tuple[str, str, str]] = []
    span = _fn_span(body, name)
    if not span:
        return out
    # 1. near <-> far: a scalar extern becomes an unknown-size array (far) or back
    for m in re.finditer(r"^extern ((?:struct \w+|[us](?:8|16|32)|f32|f64)) ([A-Za-z_]\w*);$", body, re.M):
        t, g = m.groups()
        text = body[:m.start()] + f"extern {t} {g}[];" + body[m.end():]
        if t.startswith("struct"):
            text = re.sub(rf"(?<![\w>.]){re.escape(g)}\.unk_", f"{g}[0].unk_", text)
        else:
            text = re.sub(rf"(?<![\w>.&]){re.escape(g)}\b(?!\s*\[|\s*=\s*\()", f"{g}[0]", text)
        out.append(("near-far", f"{g} far", text))
    for m in re.finditer(r"^extern ((?:struct \w+|[us](?:8|16|32)|f32|f64)) ([A-Za-z_]\w*)\[\];$", body, re.M):
        t, g = m.groups()
        text = body[:m.start()] + f"extern {t} {g};" + body[m.end():]
        text = text.replace(f"{g}[0]", g)
        out.append(("near-far", f"{g} near", text))
    # 2. a global struct accessed several times through a pointer local
    inner = body[span[1]:span[2]]
    for m in re.finditer(r"^extern struct (\w+) ([A-Za-z_]\w*)(\[\])?;$", body, re.M):
        st, g, arr = m.groups()
        uses = re.findall(rf"(?<![\w>.]){re.escape(g)}(?:\[0\])?\.unk_", inner)
        if len(uses) < 2 or f"p_{g}" in body:
            continue
        acc = f"{g}[0].unk_" if arr else f"{g}.unk_"
        new_inner = inner.replace(acc, f"p_{g}->unk_")
        # the assignment goes before the first statement; the declaration with the locals
        first_stmt = re.search(r"\n(\s*)(?![A-Za-z_][\w ]*\*?\s*[A-Za-z_]\w*(\[[^\]]*\])*;\n)([^\n]*;)", new_inner)
        if not first_stmt:
            continue
        at = first_stmt.start(3)
        new_inner = new_inner[:at] + f"p_{g} = (struct {st} *)&{g};\n    " + new_inner[at:]
        new_inner = f"\n    struct {st} *p_{g};" + new_inner
        out.append(("ptr-local", f"pointer local for {g}", body[:span[1]] + new_inner + body[span[2]:]))
    # 3. field signedness in block-private structs
    for m in re.finditer(r"^(    )([us](?:8|16|32)) (unk_[0-9A-F]+)(\[[^\]]*\])?;$", body, re.M):
        t = m.group(2)
        out.append(("field-type", f"{m.group(3)}: {t}->{FIELD_FLIP[t]}", body[:m.start(2)] + FIELD_FLIP[t] + body[m.end(2):]))
    # 4. counted loop direction
    for m in re.finditer(r"for \((\w+) = ([^;]+); \1 != 0; \1--\)", body):
        v, n = m.groups()
        out.append(("loop-form", "count down -> up", body[:m.start()] + f"for ({v} = 0; {v} < {n}; {v}++)" + body[m.end():]))
    for m in re.finditer(r"for \((\w+) = 0; \1 < ([^;]+); \1\+\+\)", body):
        v, n = m.groups()
        out.append(("loop-form", "count up -> down", body[:m.start()] + f"for ({v} = {n}; {v} != 0; {v}--)" + body[m.end():]))
    # 4b. combinatorial induction-variable spellings (regalloc tie-break lever).
    # A pure-regalloc near-miss where retail keeps the loop counter and the byte-offset
    # accumulator in specific registers, and MWCC coalesces the counter onto a live zero
    # (mr r30,r31) while ours materialises an independent li. Single levers (counter form,
    # offset rematerialisation) just shuffle which tied register each lands in -- measured
    # on fn_1_10161C and fn_12_2F970. What has not been tried is the COMBINATION: spell
    # the counter and the offset accumulator together, in every pairing, so the allocator
    # sees a different live-range shape and may pick retail's colouring. Each pairing is a
    # distinct candidate; the oracle decides. (finding 301)
    for am in re.finditer(r"(\w+) \+= (0x[0-9A-Fa-f]+|\d+)", inner):
        acc, kstr = am.group(1), am.group(2)
        k = kstr
        # find the innermost for-loop whose increment clause or body contains this
        # += (scan backward from the += site to find the nearest 'for (' or '{')
        acc_pos = inner.find(f"{acc} +=")
        if acc_pos < 0:
            continue
        counter = None
        nearest_for = None
        for m2 in re.finditer(r"for \(", inner[:acc_pos]):
            nearest_for = m2
        if nearest_for:
            cm = re.match(r"\s*for \(([\w.]+) =", inner[nearest_for.start():])
            if cm:
                counter = cm.group(1)
        if counter is None:
            continue
        # rematerialise: drop the declaration, initialisation, and += step FIRST,
        # then replace remaining uses of acc with (counter * K)
        new_text = re.sub(rf"(?m)^\s*(?:u32|s32|int)\s+{re.escape(acc)}\s*;\s*\n", "", inner)
        new_text = re.sub(rf"(?m)^\s*{re.escape(acc)}\s*=\s*0\s*;\s*\n", "", new_text)
        new_text = new_text.replace(f"{acc} += {k}, ", "").replace(f", {acc} += {k}", "")
        new_text = new_text.replace(f"{acc} += {k}", "").replace(f"{acc} += {k};", "")
        new_text = re.sub(rf"(?<![\w>.]){re.escape(acc)}(?![\w])", f"({counter} * {k})", new_text)
        if new_text != inner:
            out.append(("induction-combo",
                        f"counter={counter} acc={acc} rematerialised as {counter}*{k}",
                        body[:span[1]] + new_text + body[span[2]:]))
    # 5. compare casts: drop or flip the cast on a compare operand
    for m in re.finditer(r"\((s32|u32)\)([A-Za-z_][\w>.\-\[\]]*) (==|!=|<|>|<=|>=)", inner):
        s0 = span[1] + m.start(); e0 = span[1] + m.end()
        other = "u32" if m.group(1) == "s32" else "s32"
        out.append(("compare-cast", f"drop ({m.group(1)}) on {m.group(2)}", body[:s0] + f"{m.group(2)} {m.group(3)}" + body[e0:]))
        out.append(("compare-cast", f"({m.group(1)})->({other}) on {m.group(2)}", body[:s0] + f"({other}){m.group(2)} {m.group(3)}" + body[e0:]))
    # 6. a returned parameter or constant on a function whose r3 is scratch: a void function
    ret = re.search(r"^(\s*)return ((?:arg\d+|v\d+|-?\d+|0x[0-9A-Fa-f]+));\n\}\s*$", body, re.M)
    if ret:
        sig = re.search(rf"^(u32|s32|s16|u16|s8|u8)( {re.escape(name)}\()", body, re.M)
        if sig:
            text = body[:sig.start(1)] + "void" + body[sig.end(1):]
            text = text.replace(ret.group(0), "}\n", 1)
            out.append(("void-return", "drop the returned value", text))
    # 7. an early return is the source's if-block around the tail: `if (c) { return; } S` -> `if (!c) { S }`
    for m in re.finditer(r"^(\s*)if \((.+?)\) \{ return; \}[^\n]*\n", inner, re.M):
        cond = m.group(2)
        tail = inner[m.end():]
        close = tail.rfind("\n")
        stmts_tail = tail[:close] if close >= 0 else tail
        if "{" in stmts_tail or "}" in stmts_tail or "return" in stmts_tail or not stmts_tail.strip():
            continue
        inv = {"==": "!=", "!=": "==", "<": ">=", ">": "<=", "<=": ">", ">=": "<"}
        mm = re.fullmatch(r"(.+?) (==|!=|<|>|<=|>=) (.+)", cond)
        ncond = f"{mm.group(1)} {inv[mm.group(2)]} {mm.group(3)}" if mm else f"!({cond})"
        new_inner = inner[:m.start()] + f"{m.group(1)}if ({ncond}) {{\n" + stmts_tail + f"\n{m.group(1)}}}" + tail[close:]
        out.append(("return-to-block", "early return -> if block", body[:span[1]] + new_inner + body[span[2]:]))
    # 8a. a call assigned to a field or global goes through a local first (the scheduler places
    #     the store differently when the value has a home)
    for m in re.finditer(r"^(\s*)([A-Za-z_][\w>.\-\[\]]*) = ([A-Za-z_]\w*\([^;]*\));\n", inner, re.M):
        ind, lhs, call = m.groups()
        if re.fullmatch(r"[A-Za-z_]\w*", lhs) and not re.search(rf"(?:->|\.)", lhs):
            continue  # already a plain local
        decl_at = _locals(body, span)
        ins_at = decl_at[-1][1] if decl_at else span[1] + 1
        new_inner = inner[:m.start()] + f"{ind}spell_call = {call};\n{ind}{lhs} = spell_call;\n" + inner[m.end():]
        text = body[:span[1]] + new_inner + body[span[2]:]
        text = text[:ins_at] + "    u32 spell_call;\n" + text[ins_at:]
        out.append(("call-to-local", f"local for {call[:30]}", text))
    # 9. 64-bit values the body split into two u32 halves (OSTime everywhere in the OS SDK): the
    #    halves travel as an adjacent register pair, so the split is invisible in the diff except
    #    as register order. Pairs are rejoined in the signature, at call sites, in stores, and in
    #    the callee's prototype.
    u64_1 = _u64_family(body, name, span, inner)
    out += u64_1
    seen_u64 = {t for _, _, t in u64_1}
    for _, label1, t1 in u64_1[:12]:
        sp1 = _fn_span(t1, name)
        if not sp1:
            continue
        for _, label2, t2 in _u64_family(t1, name, sp1, t1[sp1[1]:sp1[2]])[:12]:
            if t2 not in seen_u64 and t2 != body:
                seen_u64.add(t2); out.append(("u64", f"{label1} + {label2}", t2))
    # 8. a temporary for a call result used once: inline it
    for m in re.finditer(r"^(\s*)(t\d+) = ([A-Za-z_]\w*\([^;]*\));\n", inner, re.M):
        tn, call = m.group(2), m.group(3)
        rest = inner[m.end():]
        if len(re.findall(rf"\b{tn}\b", rest)) == 1:
            new_inner = inner[:m.start()] + re.sub(rf"\b{tn}\b", call, rest, count=1)
            out.append(("inline-call", f"inline {tn}", body[:span[1]] + new_inner + body[span[2]:]))
    return out


def call_sites(text, indirect=False):
    """Balanced call and argument spans, including casts and nested calls."""
    from .sdkimport import masked
    code = masked(text)
    stack, calls = [], []
    for token in re.finditer(r'(?P<name>\b[A-Za-z_]\w*)\s*\(|[()\[\]{},]',code):
        if token[0].endswith('('):
            name = token['name']
            if indirect and name is None and code[:token.start()].rstrip().endswith((')', ']')):
                name = '<indirect>'
            stack.append([name,token.start(),token.end(),[]])
        elif token[0] in '[{':
            stack.append([None,token.start(),token.end(),[]])
        elif token[0]==',' and stack and stack[-1][0]:
            frame=stack[-1];frame[3].append((frame[2],token.start()));frame[2]=token.end()
        elif token[0] in ')]}' and stack:
            name,start,last,args=stack.pop()
            if name:
                if args or code[last:token.start()].strip():
                    args.append((last,token.start()))
                calls.append((name,start,token.end(),args))
    return sorted(calls,key=lambda call:call[1])


def reaching_assignment(code, name, before, lower=0):
    """A scalar definition in the same straight-line region as its use.

    Deliberately stop at control flow or an address escape. Callers may inspect
    the expression, but must not move a load or a side effect to the use site.
    """
    region = code[lower:before]
    pattern = re.compile(r'(?m)^[ \t]*' + re.escape(name) + r'\s*=(?!=)\s*([^;{}\n]+);')
    definitions = list(pattern.finditer(region))
    if not definitions:
        return None
    match = definitions[-1]
    suffix = region[match.end():]
    if (re.search(r'[{}]|\b(?:if|else|while|for|do|switch|goto|case|break|continue|return)\b', suffix)
            or re.search(r'&\s*\b'+re.escape(name)+r'\b|\b'+re.escape(name)+r'\s*(?:[+*/&|^-]=|\+\+|--)', suffix)):
        return None
    return lower + match.start(1), lower + match.end(1)


def initialized_local(code, name, before, lower):
    """Require an assignment in an enclosing block, not solely a sibling arm."""
    scopes, scope = [], ()
    definitions = []
    pattern = r'[{}]|(?m:^[ \t]*)\b' + re.escape(name) + r'\s*=(?!=)[^;{}\n]+;'
    for token in re.finditer(pattern, code[lower:before]):
        if token[0] == '{':
            scopes.append(token.start()); scope = tuple(scopes)
        elif token[0] == '}':
            if scopes:
                scopes.pop()
            scope = tuple(scopes)
        else:
            definitions.append(scope)
    return any(scope[:len(parent)] == parent for parent in definitions)


def _pair_proto(text: str, callee: str, idx: int) -> Optional[str]:
    """The callee's extern prototype with parameters idx and idx+1 (both 32-bit ints) as one u64."""
    m = re.search(rf"^extern ([\w ]+?\*?) {re.escape(callee)}\(([^)]*)\);$", text, re.M)
    if not m:
        return None
    ps = [x.strip() for x in m.group(2).split(",")]
    if len(ps) <= idx + 1 or not all(re.fullmatch(r"(u32|s32|int|unsigned int|unsigned|long|unsigned long)", ps[k]) for k in (idx, idx + 1)):
        return None
    ps[idx:idx + 2] = ["u64"]
    return text[:m.start(2)] + ", ".join(ps) + text[m.end(2):]


def loop_lifetimes(body, name):
    """Separate loop-local homes while preserving their outgoing scalar values."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    types={r[3]:r[2] for r in _locals(body,span) if not r[4] and
           ('{' not in r[2] or re.fullmatch(r'struct\s*\{\s*'+TYPE+r'\s+value;\s*\}',r[2]))};out=[]
    counted = []
    for callee,start,end,args in call_sites(code):
        if callee != 'for' or not span[1] <= start < end < span[2]:
            continue
        header = re.match(r'for\s*\(\s*(\w+)\s*=(?!=)', code[start:end])
        opening = re.match(r'\s*\{', code[end:])
        if not header or header[1] not in types or not opening:
            continue
        var = header[1]
        lo = end + opening.end() - 1
        hi, depth = lo + 1, 1
        while hi < span[2] and depth:
            depth += (code[hi] == '{') - (code[hi] == '}'); hi += 1
        if (depth or re.search(r'\bgoto\b', code[span[1]:span[2]])
                or re.search(r'&\s*\b' + re.escape(var) + r'\b', code[span[1]:span[2]])
                or any(a <= start < b for a,b,_ in counted)):
            continue
        local = 'fzgx_loop_' + var + '_' + str(start)
        if re.search(r'\b' + local + r'\b', code):
            continue
        region = body[start:hi]
        changes, previous = [], None
        for token in TOKEN.finditer(masked(region)):
            if token[0] == var and previous not in ('.', '->'):
                changes.append((token.start(), token.end()))
            previous = token[0]
        for a,b in reversed(changes):
            region = region[:a] + local + region[b:]
        # Keep the outgoing value, including a break from the loop. Dead-copy
        # elimination removes it when the next loop initializes the counter.
        replacement = ('{\n    ' + types[var] + ' ' + local + ';\n' + region +
                       '\n    ' + var + ' = ' + local + ';\n}')
        counted.append((start, hi, replacement))
    if counted:
        groups = [[edit] for edit in counted]
        if len(counted) > 1:
            groups.append(counted)
            groups.extend([edit for j,edit in enumerate(counted) if j != i] for i in range(len(counted)))
        for group in groups:
            text = body
            for lo,hi,replacement in reversed(group):
                text = text[:lo] + replacement + text[hi:]
            out.append(('lifetime counted loops at ' + ','.join(str(edit[0]) for edit in group), text))
    for callee,start,end,args in call_sites(code):
        if callee!='while' or not span[1]<=start<end<span[2]:continue
        opening=re.match(r'\s*\{',code[end:])
        if not opening:continue
        lo=end+opening.end()-1;depth=1;hi=lo+1
        while hi<span[2] and depth:
            depth+=(code[hi]=='{')-(code[hi]=='}');hi+=1
        if depth or re.search(r'\bgoto\b',code[lo:hi]):continue
        a=body.rfind('\n',0,start)+1;initializers=[]
        for _ in range(6):
            previous=re.search(r'(?m)^([ \t]*)(\w+)(?:\.value)?\s*=\s*[^;{}\n]+;\s*\Z',code[span[1]:a])
            if not previous or previous[2] not in types:break
            a=span[1]+previous.start();initializers.insert(0,previous[2])
        variables=[v for v in initializers if re.search(r'\b'+re.escape(v)+r'\b',code[start:hi]) and
                   not re.search(r'&\s*\b'+re.escape(v)+r'\b',code[span[1]:span[2]])]
        if not variables:continue
        groups=[(v,) for v in variables]
        groups+=list(itertools.combinations(variables,2))
        if len(variables)>2:groups.append(tuple(variables))
        for group in groups:
            names={v:'fzgx_loop_'+v+'_'+str(start) for v in group}
            if any(re.search(r'\b'+n+r'\b',code) for n in names.values()):continue
            region=body[a:hi];changes=[];previous=None
            for token in TOKEN.finditer(masked(region)):
                if token[0] in names and previous not in ('.','->'):
                    changes.append((token.start(),token.end(),names[token[0]]))
                previous=token[0]
            for x,y,value in reversed(changes):region=region[:x]+value+region[y:]
            declarations='\n'.join('    '+types[v]+' '+names[v]+';' for v in group)
            copies='\n'.join('    '+v+('.value' if '{' in types[v] else '')+' = '+names[v]+('.value' if '{' in types[v] else '')+';' for v in group)
            text=body[:a]+'{\n'+declarations+'\n'+region+'\n'+copies+'\n}'+body[hi:]
            out.append((f'lifetime loop at {start}: '+','.join(group),text))
    return out


def flag_stores(body, name):
    """Recover consecutive flag-field assignments hidden by a cached word."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    pattern=(r'(?m)^([ \t]*)(\w+(?:(?:->|\.)\w+)+)\s*=\s*(\w+)\s*&\s*(0x[0-9a-fA-F]+)[uU]?;\s*\n'
             r'[ \t]*\2\s*=\s*\3\s*&\s*(0x[0-9a-fA-F]+)[uU]?;')
    sites=[]
    for m in re.finditer(pattern,code[span[1]:span[2]]):
        indent,member,var,first,second=m.groups();a,b=span[1]+m.start(),span[1]+m.end()
        assignment=reaching_assignment(code,var,a,span[1])
        if not assignment or code[slice(*assignment)].strip()!=member:continue
        first,second=int(first,16),int(second,16)
        if first&second!=second or first>0xffffffff:continue
        sites.append((a,b,indent,member,first,second))
    out=[]
    for selected in ([sites] if len(sites)>1 else [])+[[s] for s in sites]:
        text=body
        for a,b,indent,member,first,second in reversed(selected):
            replacement=indent+member+' &= '+hex(first)+'U;\n'+indent+member+' &= '+hex(second)+'U;'
            text=text[:a]+replacement+text[b:]
        out.append(('lifetime flag stores compound at '+','.join(str(s[0]) for s in selected),text))
    return out


def initialization_orders(body, name):
    """Reorder independent local initializations as one scheduling decision."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    locals_={r[3] for r in _locals(body,span)};groups=[];group=[]
    for match in re.finditer(r'(?m)^[ \t]*[^\n]+;[ \t]*$',code[span[1]:span[2]]):
        declaration=DECL_RE.fullmatch(match[0])
        if declaration and declaration[1].strip() not in ('return','goto','break','continue'):
            locals_.add(declaration[2])
    for record in records(code,span[2]):
        if record['start']<span[1]:continue
        tail=re.match(r'\s*(\w+)\s*;',code[record['end']:])
        if tail:locals_.add(tail[1])
    for m in re.finditer(r'(?m)^([ \t]*)(\w+(?:\.\w+)?)\s*=\s*([^;{}\n]+);[ \t]*\n',code[span[1]:span[2]]):
        a,b=span[1]+m.start(),span[1]+m.end();var,value=m[2],m[3]
        if var.split('.')[0] not in locals_ or re.search(r'\b\w+\s*\(|->|[.\[\]+/?:=]|--',value) or re.search(r'&\s*\b'+re.escape(var)+r'\b',code[span[1]:span[2]]):
            if len(group)>1:groups.append(group)
            group=[];continue
        if group and (a!=group[-1][1] or len(group)==4):
            if len(group)>1:groups.append(group)
            group=[]
        group.append((a,b,var,value))
    if len(group)>1:groups.append(group)
    out=[];policies=defaultdict(list)
    for group in groups:
        names={r[2].split('.')[0] for r in group}
        if len(names)!=len(group) or any(names & set(re.findall(r'\b\w+\b',r[3])) for r in group):continue
        a,b=group[0][0],group[-1][1]
        for order in itertools.permutations(group):
            if list(order)==group:continue
            replacement=''.join(body[r[0]:r[1]] for r in order)
            text=body[:a]+replacement+body[b:]
            policies[(tuple(r[2] for r in group),tuple(r[2] for r in order))].append((a,b,replacement))
            out.append((f'lifetime initialization order at {a}: '+','.join(r[2] for r in order),text))
    for (before,after),changes in policies.items():
        if len(changes)<2:continue
        text=body
        for a,b,replacement in reversed(changes):text=text[:a]+replacement+text[b:]
        out.append(('lifetime repeated initialization order: '+','.join(after),text))
    return out


def reuse_temporaries(body, name):
    """Let a dead local carry a later result without extending its old value."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    # A textual last use is not a death point across a back edge. In particular,
    # a for-loop increment precedes its body in C: reusing that counter in the
    # body changes the next iteration even though no later token names it.
    if re.search(r'\bgoto\b',code[span[1]:span[2]]):return []
    loops=[]
    starts=[(start,end) for callee,start,end,_ in call_sites(code)
            if callee in ('for','while') and span[1]<=start<end<span[2]]
    starts.extend((m.start(),m.end()) for m in re.finditer(r'\bdo\b',code)
                  if span[1]<=m.start()<span[2])
    for start,end in starts:
        opening=re.match(r'\s*\{',code[end:])
        if not opening:
            # The closing while of a do-loop has no body of its own.
            if code[end:].lstrip().startswith(';'):continue
            # Without a compound body we cannot bound nested if/else statements
            # using braces. Keep these locals live through the function.
            loops.append((start,span[2]));continue
        hi=end+opening.end();depth=1
        while hi<span[2] and depth:
            depth+=(code[hi]=='{')-(code[hi]=='}');hi+=1
        loops.append((start,hi if not depth else span[2]))
    locals_=_locals(body,span);_,variables=declared_types(code,span[0]);out=[]
    candidates=[]
    for a,b,ty,var,dims in locals_:
        if dims or ty.strip() not in ('u32','s32','int','unsigned') or re.search(r'&\s*\b'+re.escape(var)+r'\b',code[span[1]:span[2]]):continue
        uses=list(re.finditer(r'\b'+re.escape(var)+r'\b',code[b:span[2]]))
        if uses:
            last=b+uses[-1].end()
            last=max([last]+[hi for lo,hi in loops
                            if any(lo<=b+use.start()<hi for use in uses)])
            candidates.append((var,last))
    for m in re.finditer(r'(?m)^([ \t]*)(\w+)\s*=\s*([^;{}\n]+);',code[span[1]:span[2]]):
        a,b=span[1]+m.start(),span[1]+m.end();indent,var,value=m.groups()
        if variables.get(var,'').strip() not in ('u32','s32','int','unsigned'):continue
        if re.fullmatch(r'-?\d+|0x[0-9A-Fa-f]+',value.strip()):continue
        for temp,last in candidates:
            if last>=a or temp==var:continue
            text=body[:a]+indent+temp+' = '+value+';\n'+indent+var+' = '+temp+';'+body[b:]
            out.append((f'lifetime reuse {temp} for {var} at {a}',text))
    return out


def returned_regions(body, name):
    """Recover a context-free inlined getter from both arms of a value join."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:return []
    _,variables=declared_types(code,span[0]);locals_=set()
    for line in code[span[1]:span[2]].splitlines():
        declaration=DECL_RE.match(line)
        if declaration and declaration[1] not in ('return','break','goto'):locals_.add(declaration[2])
    signature=code[span[0]:span[1]]
    for part in signature[signature.index('(')+1:signature.rfind(')')].split(','):
        match=re.search(r'\b(\w+)\s*$',part)
        if match:locals_.add(match[1])
    closing={};stack=[]
    for token in re.finditer(r'[{}]',code[span[1]-1:span[2]+1]):
        at=span[1]-1+token.start()
        if token[0]=='{':stack.append(at)
        elif stack:closing[stack.pop()]=at
    out=[]
    for callee,start,end,args in call_sites(code):
        if callee!='if' or not span[1]<=start<end<span[2]:continue
        left=re.match(r'\s*\{',code[end:])
        if not left:continue
        a=end+left.end()-1;b=closing.get(a)
        if b is None:continue
        right=re.match(r'\s*else\s*\{',code[b+1:])
        if not right:continue
        c=b+right.end();d=closing.get(c)
        if d is None:continue
        assignments=[]
        for lo,hi in ((a+1,b),(c+1,d)):
            matches=list(re.finditer(r'\b(\w+)\s*=\s*([^;{}]+);\s*$',code[lo:hi]))
            if not matches:break
            match=matches[-1];assignments.append((lo+match.start(),lo+match.end(),match[1],body[lo+match.start(2):lo+match.end(2)]))
        if len(assignments)!=2 or assignments[0][2]!=assignments[1][2]:continue
        var=assignments[0][2];ty=variables.get(var,'')
        if var not in locals_ or not ty or '*' in ty or any(q in ty for q in ('volatile','const')):continue
        region=body[start:d+1]
        for lo,hi,_,value in reversed(assignments):region=region[:lo-start]+'return '+value+';\n'+region[hi-start:]
        identifiers=[];previous=None
        for token in TOKEN.finditer(masked(region)):
            if token[0] in locals_ and previous not in ('.','->'):identifiers.append(token[0])
            previous=token[0]
        if identifiers or re.search(r'\b(?:goto|continue|return)\b',code[start:d+1]):continue
        helper=name+'_value_region'
        while re.search(r'\b'+helper+r'\b',code):helper+='_'
        first=body[start:b+1];last=body[c+1:d]
        lo,hi,_,value=assignments[0];first=first[:lo-start]+'return '+value+';\n'+first[hi-start:]
        lo,hi,_,value=assignments[1];last=last[:lo-c-1]+'return '+value+';\n'+last[hi-c-1:]
        for label,contents in (('',region),(' early return',first+'\n'+last)):
            definition='static inline '+ty+' '+helper+'(void) {\n'+contents+'\n}\n'
            text=body[:start]+var+' = '+helper+'();'+body[d+1:]
            pos=body.rfind('\n',0,span[0])+1
            text=text[:pos]+definition+text[pos:]
            out.append((f'lifetime returned region {var} at {start}'+label,text))
            tail=code[d+1:span[2]]
            consumer=re.match(r'\s*if\s*\(\s*('+re.escape(var)+r')\s*(?:==|!=|<=|>=|<|>)\s*\w+\s*\)',tail)
            if consumer and len(re.findall(r'\b'+re.escape(var)+r'\b',tail))==1:
                x,y=d+1+consumer.start(1),d+1+consumer.end(1)
                text=body[:start]+body[d+1:x]+helper+'()'+body[y:]
                text=text[:pos]+definition+text[pos:]
                out.append((f'lifetime returned region {var} at {start}'+label+' into condition',text))
    return out




def promoted_locals(body, name):
    """Keep narrow conversions explicit while using a full-width local home."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:
        return []
    stack=[];scopes=[]
    for token in re.finditer(r'[{}]',code[span[1]-1:span[2]+1]):
        at=span[1]-1+token.start()
        if token[0]=='{':stack.append(at)
        elif stack:scopes.append((stack.pop(),at))
    out=[];groups={}
    for decl in re.finditer(r'(?m)^[ \t]*(s8|u8|s16|u16|short|unsigned short|signed char|unsigned char)\s+(\w+)\s*(?:=\s*([^;{}]+))?;',code[span[1]:span[2]]):
        a,b=span[1]+decl.start(),span[1]+decl.end();ty,var=decl[1],decl[2]
        enclosing=[(lo,hi) for lo,hi in scopes if lo<a<b<=hi]
        if not enclosing:continue
        end=min(enclosing,key=lambda s:s[1]-s[0])[1];region=code[b:end]
        ident=r'(?<![.>\w])'+re.escape(var)+r'\b'
        if re.search(r'&\s*'+ident,region) or re.search(ident+r'\s*(?:\+\+|--|[+*/&|^%-]=)|(?:\+\+|--)\s*'+ident,region):continue
        if re.search(TYPE+r'\s+'+re.escape(var)+r'\s*[;=]',region):continue
        assignments=list(re.finditer(ident+r'\s*=(?!=)\s*([^;{}]+);',region))
        if not assignments and decl[3] is None:continue
        new='s32' if ty in ('s8','s16','short','signed char') else 'u32'
        changes=[(span[1]+decl.start(1),span[1]+decl.end(1),new)]
        if decl[3] is not None:
            lo,hi=span[1]+decl.start(3),span[1]+decl.end(3)
            narrow_load=re.fullmatch(r'\s*\(\s*\*\s*\(\s*'+re.escape(ty)+r'(?:\s+volatile)?\s*\*\s*\)\s*&\s*\([^();]+\)\s*\)\s*',code[lo:hi])
            if not narrow_load:
                changes.append((lo,hi,'('+ty+')('+body[lo:hi]+')'))
        changes.extend((b+m.start(1),b+m.end(1),'('+ty+')('+body[b+m.start(1):b+m.end(1)]+')') for m in assignments)
        text=body
        for x,y,value in sorted(changes,reverse=True):text=text[:x]+value+text[y:]
        out.append((f'lifetime promoted {var} {ty}->{new} at {a}',text))
        groups.setdefault((var,ty,new),[]).extend(changes)
    for (var,ty,new),changes in groups.items():
        if sum(value==new for _,_,value in changes)<2:continue
        text=body
        for a,b,value in sorted(changes,reverse=True):text=text[:a]+value+text[b:]
        out.insert(0,(f'lifetime promoted {var} {ty}->{new} at every site',text))
    return out


def wide_member_values(body, name):
    """Recover 64-bit values split across adjacent, explicitly typed members."""
    from .sdkimport import masked
    code=masked(body);span=_function_body_span(code,name)
    if not span:
        return []
    fields,variables=declared_types(code,span[0]);layouts=record_layouts(code,span[0],variables)
    member=r'\w+(?:(?:->|\.)\w+)+'
    def pair(high,low):
        h=re.fullmatch(r'(.+)(->|\.)(\w+)',high);l=re.fullmatch(r'(.+)(->|\.)(\w+)',low)
        if not h or not l or h.groups()[:2]!=l.groups()[:2]:
            return None
        owner=member_type(h[1],fields,variables)
        tag=re.sub(r'\b(?:extern|static|struct|const|volatile)\b|\*','',owner).strip()
        layout=layouts.get(tag,{})
        a,b=layout.get(h[3]),layout.get(l[3])
        if not a or not b or b[0]!=a[0]+4 or a[2] or b[2] or a[1] not in ('u32','unsigned int') or b[1] not in ('u32','unsigned int'):
            return None
        if 'volatile' in owner or any('volatile' in member_type(x,fields,variables) for x in (high,low)):
            return None
        return '(*(const u64 *)&'+high+')'
    edits=[]
    shifted=re.compile(r'\(\s*('+member+r')\s*<<\s*(\d+)\s*\)\s*\|\s*\(\s*('+member+r')\s*>>\s*(\d+)\s*\)')
    for m in shifted.finditer(code,span[1],span[2]):
        value=pair(m[1],m[3]);left,right=int(m[2]),int(m[4])
        if value and 0<left<32 and left+right==32:
            edits.append((m.start(),m.end(),f'((u32)({value} >> {right}))','shift'))
    compared=re.compile(r'\(\s*('+member+r')\s*\^\s*('+member+r')\s*\)\s*\|\s*\(\s*('+member+r')\s*\^\s*('+member+r')\s*\)')
    conditions=[args[0] for callee,start,end,args in call_sites(code) if callee in ('if','while') and len(args)==1 and span[1]<=start<end<=span[2]]
    for m in compared.finditer(code,span[1],span[2]):
        left,right=pair(m[1],m[3]),pair(m[2],m[4])
        if not left or not right:
            continue
        for a,b in conditions:
            if not a<=m.start()<m.end()<=b or not re.fullmatch(r'\s*\(*\s*',code[a:m.start()]):
                continue
            suffix=re.fullmatch(r'\s*\)*\s*(==|!=)\s*0\s*\)*\s*',code[m.end():b])
            if suffix:
                edits.append((a,b,f'{left} {suffix[1]} {right}','comparison'))
    out=[]
    for a,b,value,kind in edits:
        out.append((f'recover wide member {kind} at {a}',body[:a]+value+body[b:]))
    if len(edits)>1:
        text=body
        for a,b,value,_ in sorted(edits,reverse=True):
            text=text[:a]+value+text[b:]
        out.insert(0,('recover wide members at every site',text))
    return out


def _u64_family(body: str, name: str, span, inner: str) -> List[Tuple[str, str, str]]:
    out: List[Tuple[str, str, str]] = []
    protos = set(re.findall(r"^extern [\w ]+?\*? ([A-Za-z_]\w*)\([^)]*\);$", body, re.M))
    # `#define InsertAlarm InsertAlarm_8000AC44`: the call names the alias, the prototype the symbol
    aliases = dict(re.findall(r"^#define (\w+) (\w+)$", body, re.M))
    protos |= {a for a, t in aliases.items() if t in protos}
    def proto_name(c):
        return aliases.get(c, c)
    # (a) two adjacent zero arguments: one u64 zero (materialised low word first, as retail does)
    declared = {m.group(1) for m in re.finditer(r"^extern [\w ]+?\*? ([A-Za-z_]\w*)\(", body, re.M)} | set(aliases)
    keywords = {"if", "while", "for", "switch", "return", "sizeof"}
    for callee,_,_,arguments in call_sites(inner):
        if callee == name or callee in keywords or not arguments:
            continue
        al = [inner[a:b].strip() for a,b in arguments]
        for k in range(len(al) - 1):
            if al[k] == "0" and al[k + 1] == "0":
                new_inner = inner[:arguments[0][0]] + ", ".join(al[:k] + ["(u64)0"] + al[k + 2:]) + inner[arguments[-1][1]:]
                text = body[:span[1]] + new_inner + body[span[2]:]
                text = _pair_proto(text, proto_name(callee), k) if callee in declared else text
                if text:
                    out.append(("u64", f"{callee}: zero pair at {k} -> (u64)0", text))
    # (b) two adjacent 32-bit parameters that only ever travel together: one u64 parameter
    sig = re.search(rf"\b{re.escape(name)}\s*\(([^)]*)\)\s*\{{", body)
    if sig and sig.group(1).strip() not in ("", "void"):
        ps = [x.strip() for x in sig.group(1).split(",")]
        for k in range(len(ps) - 1):
            ma = re.fullmatch(r"(u32|s32) (\w+)", ps[k]); mb = re.fullmatch(r"(u32|s32) (\w+)", ps[k + 1])
            if not (ma and mb):
                continue
            A, B = ma.group(2), mb.group(2)
            pair_re = rf"\b{A}, {B}\b"
            # a store of both halves to fields 4 bytes apart, in either order
            store_re = (rf"^(\s*)([A-Za-z_][\w>.\-\[\]]*?)unk_([0-9A-Fa-f]+) = ({A}|{B});\n\s*\2unk_([0-9A-Fa-f]+) = ({A}|{B});\n")
            stores = [m for m in re.finditer(store_re, inner, re.M) if {m.group(4), m.group(6)} == {A, B}
                      and abs(int(m.group(3), 16) - int(m.group(5), 16)) == 4]
            n_pair = len(re.findall(pair_re, inner))
            if n_pair + len(stores) == 0:
                continue
            if len(re.findall(rf"\b{A}\b", inner)) != n_pair + len(stores) or len(re.findall(rf"\b{B}\b", inner)) != n_pair + len(stores):
                continue
            P = f"{A}_{B}"
            new_inner = inner
            for m in reversed(stores):
                lo = min(int(m.group(3), 16), int(m.group(5), 16))
                # the high half is the first parameter (the lower register); the u64 store covers both
                new_inner = new_inner[:m.start()] + f"{m.group(1)}*(u64 *)&{m.group(2)}unk_{lo:X} = {P};\n" + new_inner[m.end():]
            # call sites: the pair becomes one argument; the callee's prototype pairs the same slot
            text = body[:span[1]] + new_inner + body[span[2]:]
            ok = True
            for callee,_,_,arguments in call_sites(new_inner):
                al = [new_inner[a:b].strip() for a,b in arguments]
                for j in range(len(al) - 1):
                    if al[j] == A and al[j + 1] == B:
                        t2 = _pair_proto(text, proto_name(callee), j)
                        if t2 is None:
                            ok = False
                        else:
                            text = t2
            if not ok:
                continue
            text = re.sub(pair_re, P, text)
            text = text.replace(sig.group(1), ", ".join(ps[:k] + [f"u64 {P}"] + ps[k + 2:]), 1)
            out.append(("u64", f"parameters {A}, {B} -> u64 {P}", text))
    # (d) a call argument that is a cast local or a plain local: dropped, with the prototype
    #     shortened (retail's register there was scratch; the body invented the argument)
    for callee,_,_,arguments in call_sites(inner):
        if callee == name or callee in keywords or not arguments:
            continue
        al = [inner[a:b].strip() for a,b in arguments]
        for k, arg in enumerate(al):
            if not re.fullmatch(r"\((?:u32|s32)\)\w+|[a-z]\w*", arg) or len(al) < 2:
                continue
            new_inner = inner[:arguments[0][0]] + ", ".join(al[:k] + al[k + 1:]) + inner[arguments[-1][1]:]
            text = body[:span[1]] + new_inner + body[span[2]:]
            if callee in declared:
                pm = re.search(rf"^extern ([\w ]+?\*?) {re.escape(proto_name(callee))}\(([^)]*)\);$", text, re.M)
                if not pm:
                    continue
                ps = [x.strip() for x in pm.group(2).split(",")]
                if len(ps) != len(al):
                    continue
                del ps[k]
                text = text[:pm.start(2)] + ", ".join(ps) + text[pm.end(2):]
            out.append(("u64", f"{callee}: drop argument {k} ({arg})", text))
    # (c) a u64 value stored as two halves: one store
    for m in re.finditer(r"^(\s*)([A-Za-z_][\w>.\-\[\]]*?)unk_([0-9A-Fa-f]+) = \(u32\)\((\w+) >> 32\);\n\s*\2unk_([0-9A-Fa-f]+) = \(u32\)\4;\n", inner, re.M):
        if int(m.group(5), 16) - int(m.group(3), 16) != 4:
            continue
        new_inner = inner[:m.start()] + f"{m.group(1)}*(u64 *)&{m.group(2)}unk_{m.group(3)} = {m.group(4)};\n" + inner[m.end():]
        out.append(("u64", f"{m.group(4)}: halves -> one u64 store", body[:span[1]] + new_inner + body[span[2]:]))
    return out


def all_rewrites(body: str, name: str) -> List[Tuple[str, str, str]]:
    """Expose every site; the engine owns the compilation budget."""
    out: List[Tuple[str, str, str]] = []
    for fn in (lambda b, n: perturbations(b, n),
               lambda b, n: [("regalloc", l, t) for l, t in rewrites(b, n)],
               extra_families):
        try:
            out += fn(body, name)
        except Exception:
            continue
    kept = list(out)
    by_fam: Dict[str, List[str]] = {}
    for fam, label, text in out:
        by_fam.setdefault(fam, []).append(text)
    # every edit of a family applied together (the same fix at every site): the composition of
    # the per-site texts when their edits do not overlap
    for fam, texts in by_fam.items():
        if len(texts) < 2 or fam in ("decl-order", "regalloc", "param-count", "struct-pad"):
            continue
        changes=[]
        for t in texts[:24]:
            ops=edits(body,t)
            if any(a<max(d,c+1) and c<max(b,a+1) for a,b,_ in ops for c,d,_ in changes):
                continue
            changes.extend(ops)
        text=body
        for a,b,value in sorted(changes,reverse=True):text=text[:a]+value+text[b:]
        if text != body and text not in texts:
            kept.append((fam, f"{fam} compatible sites", text))
    return kept


def fitness(tw: List[int], ow: List[int]) -> Tuple[float, float]:
    """(aligned matched words as a percent, positional percent)."""
    if not tw or not ow:
        return (0.0, 0.0)
    n = max(len(tw), len(ow))
    pos, _ = oracle.word_score(tw, ow)
    return (100.0 * (n - distance(tw, ow)) / n, pos)




TOKEN = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|'
                   r'[A-Za-z_]\w*|(?:0[xX][0-9a-fA-F]+|\d+(?:\.\d*)?)(?:[eE][+-]?\d+)?[uUlLfF]*|'
                   r'->|\+\+|--|<<|>>|<=|>=|==|!=|&&|\|\||[+*/%&|^!-]=|[^\s]', re.S)
PREC = {'=': 1, '+=': 1, '-=': 1, '*=': 1, '/=': 1, '|=': 1, '&=': 1,
        '||': 2, '&&': 3, '|': 4, '^': 5, '&': 6, '==': 7, '!=': 7,
        '<': 8, '>': 8, '<=': 8, '>=': 8, '<<': 9, '>>': 9,
        '+': 10, '-': 10, '*': 11, '/': 11, '%': 11}
COMMUTE = {'+', '*', '&', '|', '^', '==', '!='}


def commutations(body, name, operations=None):
    """Parse expression precedence, retaining source spans and parenthesization.

    Calls, updates and assignments make an expression ineligible to commute,
    though pure subexpressions within it remain eligible. Casts and unsupported
    syntax end a parse; compilation checks all proposals against retail.
    """
    span = _function_body_span(body, name)
    if not span:
        return []
    tokens = [(m[0], m.start() + span[1], m.end() + span[1])
              for m in TOKEN.finditer(body[span[1]:span[2]])
              if not m[0].startswith(('/*', '//'))]
    proposals, sites = [], defaultdict(list)
    types = {'void', 'char', 'short', 'int', 'long', 'signed', 'unsigned', 'float', 'double',
             'u8', 's8', 'u16', 's16', 'u32', 's32', 'u64', 's64', 'f32', 'f64'}
    types.update(re.findall(r'\btypedef\s+[^;{}]+\s+(\w+)\s*;', body))

    def parse(i, minimum=1):
        if i >= len(tokens):
            raise ValueError
        tok, start, end = tokens[i]
        i += 1
        pure = True
        if tok == '(':
            close = i
            while close < len(tokens) and (re.fullmatch(r'\w+', tokens[close][0]) or tokens[close][0] == '*'):
                close += 1
            cast = (i < close < len(tokens) and tokens[close][0] == ')' and
                    (tokens[i][0] in types or tokens[i][0] in ('struct', 'union', 'enum', 'const', 'volatile')))
            if cast:
                i, (_, end, pure) = parse(close + 1, 12)
            else:
                i, (_, end, pure) = parse(i)
                if i >= len(tokens) or tokens[i][0] != ')':
                    raise ValueError
                end = tokens[i][2]
                i += 1
        elif tok in ('-', '+', '!', '~', '*', '&', '++', '--'):
            i, (_, end, pure) = parse(i, 12)
            pure &= tok not in ('++', '--')
        elif not re.match(r'[\w"\']', tok):
            raise ValueError
        while i < len(tokens):
            op = tokens[i][0]
            if op in ('->', '.') and i + 1 < len(tokens):
                end = tokens[i + 1][2]
                i += 2
                continue
            if op == '[':
                j, _ = parse(i + 1)
                if j >= len(tokens) or tokens[j][0] != ']':
                    raise ValueError
                # Index expressions can have side effects too.
                pure &= not any(t[0] in ('(', '++', '--', '=') for t in tokens[i + 1:j])
                end, i = tokens[j][2], j + 1
                continue
            if op == '(':
                # Parse arguments to discover commutations inside calls.
                j = i + 1
                while j < len(tokens) and tokens[j][0] != ')':
                    j, _ = parse(j)
                    if j < len(tokens) and tokens[j][0] == ',':
                        j += 1
                    else:
                        break
                if j >= len(tokens) or tokens[j][0] != ')':
                    raise ValueError
                end, i, pure = tokens[j][2], j + 1, False
                continue
            if op in ('++', '--'):
                end, i, pure = tokens[i][2], i + 1, False
                continue
            precedence = PREC.get(op, 0)
            if precedence < minimum:
                break
            j, (rs, re_, rp) = parse(i + 1, precedence + (precedence != 1))
            if operations is not None and pure and rp and precedence > 1:
                operations.append({'start': start, 'end': re_, 'left': (start, end),
                                   'right': (rs, re_), 'op': op})
            if op in COMMUTE and pure and rp and body[start:end] != body[rs:re_]:
                replacement = f'(({body[rs:re_]}) {op} ({body[start:end]}))'
                proposals.append((f'operand {op} at {start}', body[:start] + replacement + body[re_:]))
                sites[(body[start:re_], replacement, op)].append((start, re_))
            end, i, pure = re_, j, pure and rp and precedence != 1
        return i, (start, end, pure)

    i = 0
    while i < len(tokens):
        try:
            j, _ = parse(i)
            i = max(i + 1, j)
        except (ValueError, RecursionError):
            i += 1
    # CSE couples identical occurrences: changing one may leave the shared
    # expression's operand order determined by the unchanged occurrence.
    grouped = []
    for (old, replacement, op), ranges in sites.items():
        ranges = sorted(set(ranges))
        if len(ranges) > 1 and all(b <= c for (_, b), (c, _) in zip(ranges, ranges[1:])):
            text = body
            for a, b in reversed(ranges):
                text = text[:a] + replacement + text[b:]
            grouped.append((f'shared operands {old}', text))
    # Repeated blocks often use different temporary names. Exact text grouping
    # misses their coupled operand choices; group disjoint scalar expressions by
    # operator as well. Exclude pointer arithmetic and nested overlapping trees.
    by_operator = defaultdict(list)
    for (old, replacement, op), ranges in sites.items():
        if re.search(r'\*\s*\)|\b(?:u8|s8|void|char)\b|\[', old):
            continue
        for a,b in ranges:
            by_operator[op].append((a,b,replacement))
    for op, ranges in by_operator.items():
        ranges=sorted(set(ranges))
        if len(ranges)>1 and all(b<=c for (_,b,_),(c,_,_) in zip(ranges,ranges[1:])):
            text=body
            for a,b,replacement in reversed(ranges):
                text=text[:a]+replacement+text[b:]
            grouped.append((f'coupled scalar operands {op}',text))
    return list(dict.fromkeys(grouped + proposals))


def probes(body, name, limit=32):
    """Linear probes, not permutations; each observed response is reusable."""
    choices = commutations(body, name)
    normalized = normalise(body)
    span = _function_body_span(normalized, name)
    if span:
        locs = _locals(normalized, span)
        lines = [normalized[s:e] for s, e, *_ in locs]
        for i in range(len(locs) - 1):
            order = list(range(len(locs)))
            order[i:i + 2] = reversed(order[i:i + 2])
            if _order_ok(locs, lines, order):
                choices.append((f'adjacent declarations {i}', reorder(normalized, locs, order)))
    # Scope and materialization change live ranges; they are not register renames.
    nested = []
    if span:
        declarations = [(m.start() + span[1], m.end() + span[1], m[0])
                        for m in re.finditer(r'[^\n]*\n', normalized[span[1]:span[2]])
                        if (match := DECL_RE.match(m[0].rstrip('\n')))
                        and match[1].strip() not in ('return', 'goto', 'break', 'continue')]
        for (a, b, first), (c, d, second) in zip(declarations, declarations[1:]):
            if b != c:
                continue
            fm, sm = (DECL_RE.match(line.rstrip('\n')) for line in (first, second))
            if re.search(r'\b' + re.escape(fm[2]) + r'\b', sm[4] or ''):
                continue
            nested.append((f'block declarations {fm[2]}, {sm[2]}', normalized[:a] + second + first + normalized[d:]))
    from .fixup_evidence import optimizer_pragmas
    families = [choices, nested, scope_moves(normalized, name),
                optimizer_pragmas(body, name),
                through_local(normalized, name), split_inits(normalized, name)]
    out, seen = [], {body}
    for i in range(max(map(len, families), default=0)):
        for family in families:
            if i < len(family) and family[i][1] not in seen:
                seen.add(family[i][1])
                out.append(family[i])
                if len(out) == limit:
                    return out
    return out


def edits(before, after):
    """Align lines, then trim changed spans; never quadratic whole-body character LCS."""
    left, right = before.splitlines(keepends=True), after.splitlines(keepends=True)
    offsets = [0]
    for line in left:
        offsets.append(offsets[-1] + len(line))
    changes = []
    for tag, a, b, c, d in difflib.SequenceMatcher(None, left, right, autojunk=False).get_opcodes():
        if tag == 'equal':
            continue
        old, new = ''.join(left[a:b]), ''.join(right[c:d])
        first, last = 0, 0
        while first < min(len(old), len(new)) and old[first] == new[first]:
            first += 1
        while last < min(len(old), len(new)) - first and old[-last-1] == new[-last-1]:
            last += 1
        changes.append((offsets[a] + first, offsets[b] - last, new[first:len(new)-last]))
    return changes


def compose(body, target, baseline, responses):
    """Set cover over exact repaired bits, constrained by source-span conflicts.

    Responses that change any correct bit are excluded. A combined compile is
    essential: register allocation can couple otherwise disjoint source edits.
    """
    remaining = {(i, bit) for i, (a, b) in enumerate(zip(target, baseline))
                 for bit in range(32) if (a ^ b) & (1 << bit)}
    eligible = []
    for label, source, words in responses:
        if words is None or len(words) != len(target):
            continue
        if any((old ^ new) & (wanted ^ new) for wanted, old, new in zip(target, baseline, words)):
            continue
        fixed = {(i, bit) for i, (old, new) in enumerate(zip(baseline, words))
                 for bit in range(32) if (old ^ new) & (1 << bit)}
        if fixed:
            eligible.append((fixed, label, edits(body, source)))
    chosen, patches = [], []
    while eligible:
        eligible.sort(key=lambda r: -len(r[0] & remaining))
        fixed, label, changes = eligible.pop(0)
        if not fixed & remaining:
            break
        if any(max(a, c) <= min(b, d) for a, b, _ in changes for c, d, _ in patches):
            continue
        chosen.append(label)
        patches.extend(changes)
        remaining -= fixed
    if len(chosen) < 2:
        return None
    for a, b, text in sorted(patches, reverse=True):
        body = body[:a] + text + body[b:]
    return ' + '.join(chosen), body


def region_compositions(body, baseline, responses):
    """Combine disjoint C edits with measured improvements in different blocks.

    Register renumbering and changed instruction counts are allowed. The full
    compiler oracle decides whether the source edits actually compose.
    """
    choices=[]
    for label,text,regions in responses:
        if set(regions)!=set(baseline):
            continue
        fixed={key for key,score in regions.items() if tuple(score[:2])<tuple(baseline[key][:2])
               or (not score[2] and baseline[key][2])}
        worsened={key for key,score in regions.items() if tuple(score[:2])>tuple(baseline[key][:2])}
        if fixed and not worsened:
            choices.append((fixed,label,edits(body,text)))
    result=[]
    for rotate in range(min(4,len(choices))):
        remaining=choices[rotate:]+choices[:rotate];covered=set();patches=[];labels=[]
        while remaining:
            remaining.sort(key=lambda r:-len(r[0]-covered))
            fixed,label,changes=remaining.pop(0)
            if not fixed-covered:
                break
            if any(max(a,c)<=min(b,d) for a,b,_ in changes for c,d,_ in patches):
                continue
            covered.update(fixed);patches.extend(changes);labels.append(label)
        if len(labels)<2:
            continue
        text=body
        for a,b,replacement in sorted(patches,reverse=True):text=text[:a]+replacement+text[b:]
        result.append(('region composition: '+' + '.join(labels),text))
    return list(dict.fromkeys(result))


def closes_region(target, baseline, words, regions):
    # Cheap shortlist for register-only block repairs. The aligned object diff
    # still has to confirm the block, its relocations and all other effects.
    if len(target)!=len(baseline) or len(target)!=len(words):
        return False
    starts=sorted(int(key)//4 for key in regions)
    return any(target[a:b]==words[a:b] and target[a:b]!=baseline[a:b]
               for a,b in zip(starts,starts[1:]+[len(target)]))


def instruction_shapes(words):
    """Opcode identities for the cheap prefilter; these are never match proof."""
    result=[]
    for word in words:
        primary=word>>26;extra=0
        if primary in (19,31):extra=(word>>1)&1023
        elif primary in (59,63):
            extra=(word>>1)&31
            if extra not in (18,20,21,22,23,25,28,29,30,31):extra=(word>>1)&1023
        result.append((primary<<10)|extra)
    return result


def linear_compositions(body, target, baseline, responses):
    """Solve the measured bit responses over GF(2), including cancelling effects.

    This is a shortlist, never an assertion that the allocator is linear. Rotating
    pivot order exposes bounded alternative solutions without subset enumeration.
    """
    def vector(words):
        return int.from_bytes(b''.join((a ^ b).to_bytes(4, 'big') for a, b in zip(baseline, words)), 'big')
    wanted = vector(target)
    choices = [(label, source, vector(words)) for label, source, words in responses
               if words and len(words) == len(target)]
    choices = [c for c in choices if c[2]]
    proposals, seen = [], set()
    for offset in range(min(len(choices), 8)):
        ordered = choices[offset:] + choices[:offset]
        basis = {}
        for i, (_, _, value) in enumerate(ordered):
            mask = 1 << i
            while value:
                pivot = value.bit_length()
                if pivot not in basis:
                    basis[pivot] = value, mask
                    break
                other, selected = basis[pivot]
                value ^= other
                mask ^= selected
        value, mask = wanted, 0
        while value and value.bit_length() in basis:
            other, selected = basis[value.bit_length()]
            value ^= other
            mask ^= selected
        if value or mask.bit_count() < 2:
            continue
        patches, labels = [], []
        for i, (label, source, _) in enumerate(ordered):
            if not mask & (1 << i):
                continue
            changes = edits(body, source)
            if any(max(a, c) <= min(b, d) for a, b, _ in changes for c, d, _ in patches):
                break
            patches.extend(changes)
            labels.append(label)
        else:
            text = body
            for a, b, replacement in sorted(patches, reverse=True):
                text = text[:a] + replacement + text[b:]
            if text not in seen:
                seen.add(text)
                proposals.append(('response equations: ' + ' + '.join(labels), text))
    return proposals




ALIASES = {'li': 'addi', 'lis': 'addis', 'subi': 'addi', 'subis': 'addis',
           'slwi': 'rlwinm', 'srwi': 'rlwinm', 'clrlwi': 'rlwinm', 'clrrwi': 'rlwinm',
           'rotlwi': 'rlwinm', 'clrlslwi': 'rlwinm', 'mtlr': 'mtspr', 'mflr': 'mfspr',
           'mtctr': 'mtspr', 'mfctr': 'mfspr', 'cmpwi': 'cmpi', 'cmplwi': 'cmpli',
           'cmpw': 'cmp', 'cmplw': 'cmpl'}


def mnemonic(name):
    return ALIASES.get(name, name)


def decode(words):
    md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
    md.skipdata = True
    return [(mnemonic(i.mnemonic), tuple(mwconstraints.REG.findall(i.op_str)), i.op_str)
            for i in md.disasm(b''.join(w.to_bytes(4, 'big') for w in words), 0)]


def final_allocations(captures):
    # Spilling restarts allocation with new virtual registers. Only the last
    # pass of each bank describes the webs that reach the emitted function.
    final = {c['before']['register_class']: i for i, c in enumerate(captures)}
    return [c for i, c in enumerate(captures) if final[c['before']['register_class']] == i]


def web_constraints(captures, target, ours, check=None):
    captures = final_allocations(captures)
    original, retail = decode(ours), decode(target)
    if len(original) != len(ours) or len(retail) != len(target):
        return {'status': 'instruction-shape'}
    shape = lambda row: (row[0], mwconstraints.REG.sub('R', row[2]))
    retail_alignment = difflib.SequenceMatcher(a=[shape(r) for r in original],
                                              b=[shape(r) for r in retail], autojunk=False)
    retail_rows = {block.a + i: block.b + i for block in retail_alignment.get_matching_blocks()
                   for i in range(block.size)}
    if check is not None:
        # Objdiff aligns control-flow changes before the allocator projection.
        # Re-aligning flat opcode strings can join repeated switch arms instead.
        ti=oi=0;aligned={}
        for left,right in zip(*check._rows):
            has_left=bool(left.get('instruction',{}).get('formatted'))
            has_right=bool(right.get('instruction',{}).get('formatted'))
            relocations=[side.get('instruction',{}).get('relocation',{}).get('type_name') for side in (left,right)]
            if (has_left and has_right and oi<len(original) and ti<len(retail) and shape(original[oi])==shape(retail[ti])
                    and all(r in (None,'R_PPC_NONE') for r in relocations)):
                aligned[oi]=ti
            ti+=has_left;oi+=has_right
        if ti==len(retail) and oi==len(original):
            retail_rows=aligned
    nodes = {c['before']['register_class']: {n['virtual_register']: n for n in c['after']['nodes']}
             for c in captures}
    def root(cls, register):
        seen = set()
        while register >= 32 and nodes[cls][register]['flags'] & 4:
            if register in seen:
                raise ValueError('coalescing cycle')
            seen.add(register)
            register = nodes[cls][register]['physical_register']
        return register
    def physical(cls, register):
        register = root(cls, register)
        return register if register < 32 else nodes[cls][register]['physical_register']
    domains, alternatives, anchors = defaultdict(set), [], []
    extra_copies = set()
    # Each bank's PCode is captured before that bank is allocated. The last
    # pass already contains physical operands for earlier banks, so using it
    # for every bank loses their source webs entirely.
    for capture in captures:
        active = capture['before']['register_class']
        pcode = capture['pcode']
        keys, origins = [], []
        displacement_ops={'addi','addis','lbz','lhz','lha','lwz','lfs','lfd','stb','sth','stw','stfs','stfd'}
        def emitted_key(row):
            literals=tuple(int(m[0],0) for m in re.finditer(r'(?<![\w.])-?(?:0x[\da-f]+|\d+)\b',row[2])) if row[0] in displacement_ops else ()
            return row[0],row[1],literals
        for instruction in pcode:
            operands, regs = [], []
            for a in instruction['operands']:
                cls, r = a['class'], a['reg']
                if cls not in nodes or a['flags'] == 0:
                    continue
                prefix = 'r' if cls == 'gpr' else 'f'
                operands.append((cls, root(cls, r)))
                regs.append(prefix + str(physical(cls, r)))
            name = mnemonic(instruction['mnemonic'])
            if name in ('mr', 'fmr') and len(regs) == 2 and regs[0] == regs[1]:
                continue
            literals=[]
            if name in displacement_ops:
                for operand in instruction['operands']:
                    raw=bytes.fromhex(operand['raw'])
                    if operand['class'] is None and int.from_bytes(raw[:2],'little')==2:
                        literals.append(int.from_bytes(raw[2:6],'little',signed=True))
            keys.append((name, tuple(regs),tuple(literals)))
            origins.append(operands)
        matching = difflib.SequenceMatcher(a=[r[:2] for r in keys], b=[r[:2] for r in original], autojunk=False)
        for block in matching.get_matching_blocks():
            for offset in range(block.size):
                row, index = block.b + offset, block.a + offset
                if row not in retail_rows:
                    if keys[index][0] in ('mr','fmr') and len(origins[index])==2:
                        extra_copies.update(web for web in origins[index] if web[0] == active and web[1]>=32)
                    continue
                if keys[index][2] and keys[index][2]!=emitted_key(original[row])[2]:
                    continue
                name, registers, operand_text = retail[retail_rows[row]]
                if name != original[row][0] or len(registers) != len(origins[index]):
                    continue
                if mwconstraints.REG.sub('R', operand_text) != mwconstraints.REG.sub('R', original[row][2]):
                    continue
                pairs = [(web, color) for web, color in zip(origins[index], (int(r[1:]) for r in registers))
                         if web[0] == active]
                anchors.append(row)
                if name in mwconstraints.COMMUTE and len(pairs) == 3:
                    domains[pairs[0][0]].add(pairs[0][1])
                    alternatives.append((row, pairs[1:]))
                else:
                    for web, color in pairs:
                        domains[web].add(color)
    conflicts = {str(k): sorted(v) for k, v in domains.items() if len(v) > 1}
    desired = {web: next(iter(colors)) for web, colors in domains.items() if len(colors) == 1}
    swapped, unresolved = [], []
    for row, pairs in alternatives:
        (a, x), (b, y) = pairs
        valid = [(swap, u, v) for swap, u, v in [(False, x, y), (True, y, x)]
                 if desired.get(a, u) == u and desired.get(b, v) == v and (a != b or u == v)]
        if not valid:
            unresolved.append(row)
            continue
        if len(valid) > 1 and x != y:
            unresolved.append(row)
            continue
        swap, x, y = valid[0]
        desired[a], desired[b] = x, y
        if swap:
            swapped.append(row)
    return {'status': 'web-hypothesis', 'anchors': sorted(set(anchors)),
            'conflicts': conflicts,
            'extra_copy_webs': {cls:[r for bank,r in extra_copies if bank==cls] for cls in nodes},
            'conflicting_webs': {cls:[r for (bank,r),colors in domains.items() if bank==cls and r>=32 and len(colors)>1] for cls in nodes},
            'desired': {cls: {r: c for (bank, r), c in desired.items() if cls == bank and r >= 32}
                        for cls in nodes}, 'operand_order_rows': swapped, 'unresolved_rows': unresolved}


def scalar_locals(body, span):
    # Carriers from a previous repair are fixed aggregate declarations; keep
    # scanning so remaining scalars can be repaired in the next captured graph.
    return [local for local in _locals(body,span) if '{' not in local[2]]


def annotate_verified_branches(body, findings):
    """Document branch preservation only after a full stock-object match."""
    lines = body.splitlines(keepends=True)
    changed = False
    for rule, line, _ in findings:
        if rule != 'S1':
            continue
        match = re.search(r'\bgoto\s+(\w+)\s*;', lines[line - 1])
        if match:
            pos = match.end()
            lines[line - 1] = (lines[line - 1][:pos] + f' /* Keep the verified branch to {match[1]}. */'
                               + lines[line - 1][pos:])
            changed = True
    return [('document verified control flow', ''.join(lines))] if changed else []


def reciprocal_products(body, name):
    """Power-of-two division lowers to multiply with a different operand web."""
    operations = []
    commutations(body, name, operations)
    changes = []
    for operation in operations:
        if operation['op'] != '*':
            continue
        for constant, value in ((operation['left'], operation['right']),
                                (operation['right'], operation['left'])):
            literal = body[slice(*constant)].strip()
            if not re.fullmatch(r'(?:\d+\.\d*|\.\d+|\d+[eE][+-]?\d+)(?:[eE][+-]?\d+)?[fF]?', literal):
                continue
            number = float(literal.rstrip('fF'))
            if not math.isfinite(number) or number <= 0:
                continue
            mantissa, exponent = math.frexp(number)
            if mantissa != 0.5 or not -125 <= exponent <= 127:
                continue
            inverse = format(1.0 / number, '.17g')
            if '.' not in inverse and 'e' not in inverse:
                inverse += '.0'
            inverse += 'f' if literal.endswith(('f', 'F')) else ''
            replacement = f'(({body[slice(*value)]}) / {inverse})'
            changes.append((operation['start'], operation['end'], replacement))
            break
    changes = sorted(set(changes))
    out = [(f'reciprocal division at {a}', body[:a] + replacement + body[b:])
           for a, b, replacement in changes]
    # The AST can contain nested products; do not compose overlapping edits.
    if len(changes) > 1 and all(b <= c for (_, b, _), (c, _, _) in zip(changes, changes[1:])):
        combined = body
        for a, b, replacement in reversed(changes):
            combined = combined[:a] + replacement + combined[b:]
        out.append(('reciprocal division at every site', combined))
    return out


def declaration_candidates(body, name, captures, constraints, max_orders=50000):
    """Evaluate declaration orders in the actual graph, with no compile loop."""
    if constraints['status'] != 'web-hypothesis':
        return [], {'status': constraints['status'], 'orders': 0}
    captures = final_allocations(captures)
    span = _function_body_span(body, name)
    if span is None:
        return [], {'status': 'no-body', 'orders': 0}
    locals_ = scalar_locals(body, span)
    by_name = defaultdict(list)
    for capture in captures:
        cls = capture['before']['register_class']
        for n in capture['before']['nodes']:
            if n.get('name'):
                by_name[n['name']].append((cls, n['virtual_register']))
    if all(all(next(n['physical_register'] for n in c['after']['nodes'] if n['virtual_register'] == r) == color
                   for r, color in constraints['desired'][c['before']['register_class']].items()) for c in captures):
        return [], {'status': 'no-allocation-difference', 'orders': 0}
    movable = [(i, by_name[n][0]) for i, (a, b, _, n, dims) in enumerate(locals_)
               if not dims and _init_of(body[a:b]) is None and len(by_name.get(n, [])) == 1]
    if len(movable) < 2:
        return [], {'status': 'no-movable-stratum', 'orders': 0}
    slots = {cls: sorted((r for _, (bank, r) in movable if bank == cls), reverse=True)
             for cls in constraints['desired']}
    if any([r for _, (bank, r) in movable if bank == cls] != order for cls, order in slots.items()):
        return [], {'status': 'unknown-creation-order', 'orders': 0}
    witnesses = []
    positions = {}
    for capture in captures:
        before=capture['before']; cls=before['register_class']
        desired={n['virtual_register']:n['physical_register'] for n in capture['after']['nodes']
                 if n['virtual_register'] in before['simplify_order']}
        desired.update({r:color for r,color in constraints['desired'][cls].items() if r in desired})
        if any(not 0<=color<32 for color in desired.values()):
            continue
        witness=mwgraph.selection_order(before,desired)
        if witness:
            positions[cls]={r:i for i,r in enumerate(witness)}
    if positions:
        ordered=list(movable)
        for cls,rank in positions.items():
            indices=[i for i,(_, (bank,r)) in enumerate(movable) if bank==cls]
            values=sorted((movable[i] for i in indices),key=lambda x:rank.get(x[1][1],10**9))
            for i,value in zip(indices,values):
                ordered[i]=value
        witnesses.append(ordered)
    candidates, checked, best = [], 0, None
    # Source ranks still have to reproduce simplify and coloring, not merely
    # the abstract selection witness. Keep a bounded small-stratum fallback.
    orders=itertools.chain(witnesses,itertools.islice(itertools.permutations(movable),min(max_orders,720)))
    for order in orders:
        ranks = {cls: dict(zip((r for _, (bank, r) in order if bank == cls), slots[cls])) for cls in slots}
        score = 0
        for capture in captures:
            before = capture['before']; cls = before['register_class']
            select = mwgraph.simplify(before, ranks[cls])
            if select is None:
                score += 100000
                continue
            colors = mwgraph.replay(before, select)
            score += sum(colors[r] != c for r, c in constraints['desired'][cls].items())
        checked += 1
        best = score if best is None else min(best, score)
        if score:
            continue
        replacements = {i: locals_[j] for (i, _), (j, _) in zip(movable, order)}
        text, cursor = [], 0
        for i, (a, b, *_) in enumerate(locals_):
            text.append(body[cursor:a])
            x, y, *_ = replacements.get(i, locals_[i])
            text.append(body[x:y]); cursor = b
        candidate = ''.join(text) + body[cursor:]
        if candidate != body:
            candidates.append(candidate)
        # Equivalent orders of unused locals do not justify more compiler calls.
        if candidates:
            break
    return candidates, {'status': 'predicted' if candidates else 'no-predicted-declaration-repair',
                        'orders': checked, 'exhaustive': checked >= len(witnesses) + math.factorial(len(movable)),
                        'best_conflicts': best}


def carrier_candidates(body, name, captures, constraints, _span=None):
    """Move implicated scalar homes into MWCC's aggregate-scalarization stratum.

    A one-field aggregate preserves the scalar's declared type. Only identifier
    uses in the function body are changed; field names, strings and comments
    retain their spelling. Every result still requires a stock compile.
    """
    span = _span or _function_body_span(body, name)
    if span is None or constraints['status'] != 'web-hypothesis':
        return []
    captures = final_allocations(captures)
    locals_ = scalar_locals(body, span)
    implicated = set()
    for capture in captures:
        cls = capture['before']['register_class']
        desired = {int(r): c for r, c in constraints['desired'][cls].items()}
        nodes = {n['virtual_register']: n for n in capture['after']['nodes']}
        for n in nodes.values():
            r, seen = n['virtual_register'], set()
            while r >= 32 and nodes[r]['flags'] & 4 and r not in seen:
                seen.add(r); r = nodes[r]['physical_register']
            if r >= 32 and r in desired and nodes[r]['physical_register'] != desired[r] and n.get('name'):
                implicated.add(n['name'])
    # Saved compiler temporaries can carry a source scalar whose original home
    # was coalesced into an ABI register. PCode line provenance recovers those
    # assignments instead of mistaking the temporary's @name for a C local.
    assignments = []
    local_names = {l[3] for l in locals_}
    for a,b,typ,var,dims in locals_:
        if _init_of(body[a:b]) is not None:
            assignments.append((body.count('\n',0,a)+1,body.count('\n',0,b)+1,var))
    for match in re.finditer(r'^\s*(\w+)\s*=(?!=)[^;{}]+;', body[span[1]:span[2]], re.M):
        if match[1] not in local_names:
            continue
        start = span[1] + match.start(); end = span[1] + match.end()
        assignments.append((body.count('\n', 0, start) + 1, body.count('\n', 0, end) + 2, match[1]))
    for capture in captures:
        cls = capture['before']['register_class']
        desired = {int(r): c for r, c in constraints['desired'][cls].items()}
        nodes = {n['virtual_register']: n for n in capture['after']['nodes']}
        wrong = {r for r, color in desired.items() if nodes[r]['physical_register'] != color}
        # A single web demanded in several retail registers needs a lifetime
        # split even when every unambiguous allocation already agrees.
        wrong.update(constraints.get('conflicting_webs', {}).get(cls, []))
        wrong.update(constraints.get('extra_copy_webs', {}).get(cls, []))
        implicated.update(n['name'] for r,n in nodes.items() if r in wrong and n.get('name'))
        for instruction in capture['pcode']:
            line = instruction['line']
            if line is None or line < 1:
                continue
            if any(a['class'] == cls and a['reg'] in wrong and a['flags'] & 2 for a in instruction['operands']):
                implicated.update(var for first, last, var in assignments if first <= line <= last)
    selected = [l for l in locals_ if l[3] in implicated and not l[4]]
    proposals = []
    groups = [(local,) for local in selected]
    groups.extend(itertools.combinations(selected, 2))
    if len(selected) > 2:
        groups.append(tuple(selected))
    # Coalescing a loop's pointer copies changes its allocation stratum.
    # Include adjacent live scalar homes in the same source-realizable move.
    related=set(implicated)
    for capture in captures:
        nodes={n['virtual_register']:n for n in capture['after']['nodes']}
        chosen=[n for n in nodes.values() if n.get('name') in implicated and 14<=n['physical_register']<32]
        if not chosen:continue
        low=min(n['physical_register'] for n in chosen)-1
        high=max(n['physical_register'] for n in chosen)+1
        registers={n['virtual_register'] for n in chosen}
        related.update(n['name'] for n in nodes.values() if n.get('name') and
                       low<=n['physical_register']<=high and registers.intersection(n['neighbors']))
    neighbors=tuple(l for l in locals_ if l[3] in related and not l[4])
    if len(selected)<len(neighbors)<=len(selected)+3:groups.append(neighbors)
    for group in groups:
        if any('volatile' in l[2] or 'register' in l[2] for l in group):
            continue
        names = {l[3] for l in group}
        def uses(text):
            changes, previous = [], None
            for match in TOKEN.finditer(text):
                token = match[0]
                if token.startswith(('/*', '//')):
                    continue
                if token in names and previous not in ('.', '->', 'struct', 'union', 'enum'):
                    changes.append((match.start(), match.end(), token + '.value'))
                previous = token
            for a, b, value in reversed(changes):
                text = text[:a] + value + text[b:]
            return text
        changes = []
        for a, b, type_, var, _ in group:
            init = _init_of(body[a:b])
            initializer = ' = { ' + uses(init) + ' }' if init is not None else ''
            changes.append((a, b, f'    struct {{ {type_} value; }} {var}{initializer};\n'))
        # Rewrite uses between converted declarations too, including scalar
        # initializers depending on an earlier converted local.
        pieces, cursor = [], group[0][0]
        for a, b, declaration in sorted(changes):
            pieces.extend((uses(body[cursor:a]), declaration))
            cursor = b
        pieces.append(uses(body[cursor:span[2]]))
        source = body[:group[0][0]] + ''.join(pieces) + body[span[2]:]
        label = 'carrier:' + ','.join(l[3] for l in group)
        proposals.append((label, source))
        # Aggregate initializers can keep an otherwise scalarized pointer on
        # the stack. Split pure address initializers before the carrier move.
        initialized=[l for l in group if _init_of(body[l[0]:l[1]]) is not None]
        if _span is None and initialized and all(l in group or _init_of(body[l[0]:l[1]]) is None for l in locals_):
            split=source;assignments=[]
            for a,b,type_,var,_ in initialized:
                init=_init_of(body[a:b])
                if not re.fullmatch(r'&?\s*\w+',init):break
                declaration=next(d for x,y,d in changes if x==a)
                split=split.replace(declaration,declaration[:declaration.index(' = {')]+ ';\n',1)
                assignments.append('    '+var+'.value = '+uses(init)+';\n')
            else:
                split_span=_function_body_span(split,name);split_locals=_locals(split,split_span)
                if split_locals:
                    pos=split_locals[-1][1]
                    split=split[:pos]+''.join(assignments)+split[pos:]
                    proposals.append((label+':split-initializer',split))
        # A block-local value can survive scalarization as a separate web where
        # assigning the aggregate member directly collapses back to a scalar.
        split = source
        changed = False
        for _, _, type_, var, _ in group:
            temp = '__reg_value_' + var
            while re.search(r'\b' + temp + r'\b', split):
                temp += '_'
            pattern = re.compile(r'^(\s*)' + re.escape(var) + r'\.value\s*=\s*([^;{}]+);', re.M)
            def replace_assignment(match):
                nonlocal changed
                changed = True
                return (match[1] + '{ ' + type_ + ' ' + temp + ' = ' + match[2] + '; ' +
                        var + '.value = ' + temp + '; }')
            end = span[2] + len(split) - len(body)
            split = split[:span[1]] + pattern.sub(replace_assignment, split[span[1]:end]) + split[end:]
        if changed:
            proposals.append((label + ':block-copy', split))
    return proposals


def scoped_carrier_candidates(body, name, captures, constraints):
    """Project captured homes for locals declared inside branches and loops too."""
    from .sdkimport import masked
    code = masked(body)
    function = _function_body_span(code, name)
    if function is None or constraints['status'] != 'web-hypothesis':
        return []
    stack, scopes = [], []
    for match in re.finditer(r'[{}]', code[function[1]:function[2]]):
        at = function[1] + match.start()
        if match[0] == '{':
            stack.append(at)
        elif stack:
            start = stack.pop()
            prefix = code[max(function[1], code.rfind('\n', function[1], start)):start]
            if re.search(r'\b(?:struct|union|enum)\s*\w*\s*$|=\s*$', prefix):
                continue
            scopes.append((function[0], start + 1, at))
    out = []
    for span in sorted(scopes):
        locals_ = scalar_locals(body, span)
        if not locals_ or any(ty not in SCALAR_TYPES and not ty.endswith('*') for _, _, ty, _, _ in locals_):
            continue
        # A carrier's name substitution must not reach a shadowing declaration.
        names = {var for _, _, _, var, _ in locals_}
        shadowed = False
        for line in code[locals_[-1][1]:span[2]].splitlines():
            declaration = DECL_RE.fullmatch(line)
            if declaration and declaration[2] in names:
                shadowed = True
                break
        if shadowed:
            continue
        line = body.count('\n', 0, span[1]) + 1
        out.extend((f'scope {line} {label}', text)
                   for label, text in carrier_candidates(body, name, captures, constraints, _span=span))
    return out


def expression_trees(body, name):
    operations = []
    commutations(body, name, operations)
    out = []
    for outer in operations:
        op = outer['op']
        if op not in ('+', '*', '&', '|', '^'):
            continue
        for side in ('left', 'right'):
            lo, hi = outer[side]
            children = [r for r in operations if r['op'] == op and lo <= r['start'] and r['end'] <= hi
                        and (r['start'], r['end']) != (outer['start'], outer['end'])
                        and not body[lo:r['start']].strip(' (\t\n') and not body[r['end']:hi].strip(' )\t\n')]
            if not children:
                continue
            child = max(children, key=lambda r:r['end']-r['start'])
            other = outer['right' if side == 'left' else 'left']
            terms = [body[a:b] for a,b in (child['left'], child['right'], other)]
            # Constants and load order affect CSE and FMA selection. Enumerate the
            # two three-leaf trees together instead of commuting just one node.
            for a,b,c in dict.fromkeys(itertools.permutations(terms)):
                for text in (f'((({a}) {op} ({b})) {op} ({c}))', f'(({a}) {op} (({b}) {op} ({c})))'):
                    out.append((f'expression-tree {op} at {outer["start"]}',
                                body[:outer['start']]+text+body[outer['end']:]))
    return list(dict.fromkeys(out))


def address_expressions(body, name):
    """Keep member-base formation separate from a dynamic array index.

    Macro bodies participate too: their argument names need not be declared C
    members until expansion. All forms retain the original element type.
    """
    from .sdkimport import masked
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    identities = [m[2] for m in re.finditer(r'\bstatic\s+inline\s+('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\(\s*('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\s*\)\s*\{\s*return\s+\4\s*;\s*\}',code)
                  if '*' in m[1] and m[1].strip()==m[3].strip()]
    wrapper = r'(?:\b(?:'+'|'.join(map(re.escape,identities))+r')\(\s*)?' if identities else ''
    pattern = re.compile(wrapper+r'\b(\w+(?:(?:->|\.)\w+)*)\s*'+(r'\)?' if identities else '')+r'\[([^\[\]\n;]+)\]')
    sites = [m for m in pattern.finditer(code)
             if (span[1] <= m.start() < span[2] or body[body.rfind('\n', 0, m.start())+1:m.start()].rstrip().endswith('=')
                 or '\\' in body[m.end():body.find('\n', m.end())])
             and (')' not in code[m.end(1):m.start(2)] or
                  any(re.match(re.escape(helper)+r'\s*\(',m[0]) for helper in identities))
             and not re.fullmatch(r'\s*(?!return\b)'+TYPE+r'\s+',code[code.rfind('\n',0,m.start())+1:m.start()])
             and not re.match(r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',code[m.end():])
             and not re.search(r'&\s*$',code[max(span[1],m.start()-3):m.start()])]
    out = []
    # Inlining preserves the array parameter's address web before lowering.
    # Resolve macro parameters from their actual member arguments, so a pointer
    # table never acquires an invented scalar element type.
    members = {}
    for declaration in re.finditer(r'('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\s*\[[^\]]+\]\s*;', code[:span[0]]):
        members.setdefault(declaration[2], set()).add(declaration[1].strip())
    fields, variables = declared_types(code,span[0])
    # Indexed stores create their base and index webs in a different order
    # from a dereferenced sum. Byte elements make the displacement unambiguous.
    byte_type = r'(?:u8|s8|char|unsigned char|signed char)'
    store = (r'\*\s*\(\s*('+byte_type+r')\s*\*\s*\)\s*\(\s*'
             r'\(\s*\1\s*\*\s*\)\s*(\w+(?:(?:->|\.)\w+)*)\s*\+\s*')
    for match in re.finditer(store,code[span[1]:span[2]]):
        lo, offset_start = span[1]+match.start(), span[1]+match.end()
        end, depth = offset_start, 1
        while end < span[2] and depth:
            depth += (code[end]=='(')-(code[end]==')'); end += 1
        if depth or not re.match(r'\s*=(?!=)', code[end:]):
            continue
        offset = body[offset_start:end-1].strip()
        if re.search(r'[;{}]|\+\+|--', offset) or call_sites(offset):
            continue
        replacement = '(('+match[1]+' *)'+match[2]+')['+offset+']'
        out.append((f'address indexed byte store at {lo}',body[:lo]+replacement+body[end:]))
    offset_home=(r'('+TYPE+r')\s*(?:(?<=\*)|\s)(\w+)\s*(?:=\s*|;\s*\2\s*=\s*)\(\s*\1\s*\)\s*(\w+)\s*;\s*'
                 r'\2\s*=\s*(\w+)\s*\+\s*\(\s*s32\s*\)\s*\2\s*;\s*return\s+\2\s*;')
    for match in re.finditer(offset_home,code[:span[0]]):
        typ,var,offset,base=match.groups()
        if '*' not in typ:continue
        replacement=('struct { '+typ+' value; } '+var+';\n    '+var+'.value = ('+typ+')'+offset+';\n    '
                     +var+'.value = '+base+' + (s32)'+var+'.value;\n    return '+var+'.value;')
        out.append((f'address aggregate offset home at {match.start()}',body[:match.start()]+replacement+body[match.end():]))
    # A dynamic displacement is a distinct live value in the original code.
    # Keeping that boundary across inlining prevents a trailing constant from
    # being distributed into every later field access.
    for assignment in re.finditer(r'(?m)^[ \t]*(\w+)\s*=\s*([^;{}\n]+);',code[span[1]:span[2]]):
        typ=variables.get(assignment[1],'').strip()
        if '*' not in typ:continue
        lo,hi=span[1]+assignment.start(2),span[1]+assignment.end(2)
        rhs=body[lo:hi];depth=0;split=None
        for i,ch in enumerate(rhs):
            depth+=(ch=='(')-(ch==')')
            if ch=='+' and depth==0:split=i
        if split is None:continue
        base,offset=rhs[:split].strip(),rhs[split+1:].strip()
        if not re.search(r'[*/-]',offset) or re.search(r'\+\+|--|\b\w+\s*\(',offset):continue
        helper=name+'_address_'+str(lo)
        if re.search(r'\b'+helper+r'\b',code):continue
        for reverse in (False,True):
            for home in (False,True):
                parameters=typ+' base, s32 offset' if not reverse else 's32 offset, '+typ+' base'
                arguments=base+', '+offset if not reverse else offset+', '+base
                expression='    return base + offset;\n'
                if home:expression='    '+typ+' result;\n    result = ('+typ+')offset;\n    result = base + (s32)result;\n    return result;\n'
                definition='static inline '+typ+' '+helper+'('+parameters+') {\n'+expression+'}\n'
                text=body[:lo]+helper+'('+arguments+')'+body[hi:]
                insertion=body.rfind('\n',0,span[0])+1
                text=text[:insertion]+definition+text[insertion:]
                out.append((f'address displacement at {lo} '+('offset-first' if reverse else 'base-first')+(' result home' if home else ''),text))
    aliases = dict(re.findall(r'(?m)^#define\s+(\w+)\s+(\w+)\s*$',code))
    typed = {}
    for site in sites:
        member = re.split(r'->|\.',site[1])[-1]
        root = re.match(r'\w+',site[1])[0]
        actual = aliases.get(root,root)+site[1][len(root):]
        resolved = member_type(actual,fields,variables)
        resolved = re.sub(r'\s*\*\s*$', '', resolved) if resolved.rstrip().endswith('*') else ''
        resolved = re.sub(r'\b(?:extern|static|register)\s+','',resolved)
        types = {resolved} if resolved else members.get(member,set())
        if not types:
            definitions = list(re.finditer(r'(?m)^#define\s+(\w+)\(([^)]*)\)',code[:site.start()]))
            if definitions:
                macro = definitions[-1]
                parameters = [x.strip() for x in macro[2].split(',')]
                if member in parameters:
                    index = parameters.index(member)
                    arguments = [call[1].split(',') for call in re.finditer(r'\b'+macro[1]+r'\(([^()\n]*)\)',code[span[1]:span[2]])]
                    actual = [args[index].strip() for args in arguments if index<len(args)]
                    if actual and all(arg in members for arg in actual):
                        types = set().union(*(members[arg] for arg in actual))
        if len(types)==1:
            typed.setdefault(next(iter(types)),[]).append(site)
    for element, accesses in typed.items():
        helper = name+'_array_read'
        while re.search(r'\b'+helper+r'\b',code):
            helper += '_'
        for kind in ('index', 'index-first', 'base'):
            if kind == 'base':
                definition = f'static inline {element} *{helper}({element} *array) {{ return array; }}\n'
            else:
                args = f'{element} *array, s32 index' if kind=='index' else f's32 index, {element} *array'
                definition = f'static inline {element} {helper}({args}) {{ return array[index]; }}\n'
            text = body
            for site in reversed(accesses):
                base,index = body[site.start(1):site.end(1)],body[site.start(2):site.end(2)]
                value = f'{helper}({base})[{index}]' if kind=='base' else (f'{helper}({base}, {index})' if kind=='index' else f'{helper}({index}, {base})')
                text = text[:site.start()]+value+text[site.end():]
            # Earlier macro edits change the declaration's byte offset.
            current = _function_body_span(masked(text),name)
            pos = text.rfind('\n',0,current[0])+1
            text = text[:pos]+definition+text[pos:]
            out.append((f'address typed {kind} at every site ({element})',text))
    for kind in ('index-first', 'dereference', 'index-first-dereference'):
        edits = []
        for m in sites:
            base, index = body[m.start(1):m.end(1)], body[m.start(2):m.end(2)]
            if kind == 'index-first':
                replacement = f'({index})[{base}]'
            elif kind == 'dereference':
                replacement = f'*(({base}) + ({index}))'
            else:
                replacement = f'*(({index}) + ({base}))'
            edits.append((m.start(), m.end(), '('+replacement+')'))
        combined = body
        for a,b,value in reversed(edits):
            combined = combined[:a]+value+combined[b:]
        if edits:
            out.append(('address '+kind+' at every site', combined))
        for a,b,value in edits:
            out.append((f'address {kind} at {a}', body[:a]+value+body[b:]))
    return out


def scalar_square_lifetimes(body, name):
    """Finish a dead scalar's square before unrelated loads take its register."""
    from .sdkimport import masked
    code = masked(body); span = _function_body_span(code, name)
    if not span:
        return []
    _, variables = declared_types(code, span[0]); out = []
    for site in re.finditer(r'\b(\w+)\s*\*\s*\1\b', code[span[1]:span[2]]):
        var = site[1]; a, b = span[1]+site.start(), span[1]+site.end()
        if variables.get(var) not in ('s32', 'u32', 'int', 'unsigned int', 'long', 'unsigned long'):
            continue
        # Declaration, definition and these two reads: overwriting the local
        # cannot affect another use or an escaped address.
        if len(re.findall(r'\b'+re.escape(var)+r'\b', code[span[1]:span[2]])) != 4:
            continue
        assignment = reaching_assignment(code, var, a, span[1])
        if not assignment:
            continue
        end = code.find(';', assignment[1], a)
        if end < 0 or re.search(r'[{}]|\b(?:if|else|for|while|do|goto)\b',code[end+1:a]):
            continue
        text = body[:a]+var+body[b:]
        text = text[:end+1]+'\n    '+var+' = '+var+' * '+var+';'+text[end+1:]
        out.append((f'lifetime scalar square {var}', text))
    return out


def comparison_lifetimes(body, name):
    """Keep the zero operand of a floating comparison in its own scalar home."""
    from .sdkimport import masked
    code = masked(body); span = _function_body_span(code, name)
    if not span:
        return []
    fields, variables = declared_types(code, span[0]); out = []
    local = name+'_zero'
    while re.search(r'\b'+local+r'\b',code):
        local += '_'
    for site in re.finditer(r'\b(\w+(?:(?:->|\.)\w+)*)\s*(==|!=)\s*(0\.0[fF]?)\b',code[span[1]:span[2]]):
        kind = member_type(site[1],fields,variables)
        if kind not in ('f32','float','f64','double'):
            continue
        a,b=span[1]+site.start(),span[1]+site.end()
        value='('+local+' = '+site[3]+', '+site[1]+' '+site[2]+' '+local+')'
        text=body[:a]+value+body[b:]
        text=text[:span[1]]+'\n    '+kind+' '+local+';'+text[span[1]:]
        out.append((f'lifetime floating comparison at {a}',text))
    return out


def operand_lifetimes(body, name, operators):
    """Give pure operands separate parameter/return webs before inlining."""
    operations = []
    commutations(body,name,operations)
    span = _function_body_span(body,name)
    if not span:
        return []
    insertion = body.rfind('\n',0,span[0])+1
    helper = name+'_operand'
    while re.search(r'\b'+helper+r'\b',body):
        helper += '_'
    groups = {}
    for op in operations:
        if op['op'] in operators:
            groups.setdefault((op['op'],body[op['start']:op['end']]),[]).append(op)
    work = list(groups.values())
    # Shared subexpressions can keep the old ordering alive even when their
    # surrounding operands differ. Rewrite disjoint uses of the operator too.
    for operator in operators:
        sites = []
        for op in sorted((o for o in operations if o['op']==operator),key=lambda o:(o['start'],-o['end'])):
            if not sites or op['start'] >= sites[-1]['end']:
                sites.append(op)
        if len({body[s['start']:s['end']] for s in sites})>1:
            work.insert(0,sites)
    out = []
    for sites in work:
        op = sites[0]
        for ty in operators[op['op']]:
            for reverse in (True,False):
                names = ['left','right'] if not reverse else ['right','left']
                for assign in (False,True):
                    expression = ('left '+op['op']+'= right; return left;' if assign else 'return left '+op['op']+' right;')
                    definition = f'static inline {ty} {helper}({ty} {names[0]}, {ty} {names[1]}) {{ {expression} }}\n'
                    for positions in ([sites] if len(sites)==1 else [sites]+[[site] for site in sites]):
                        text = body
                        for site in sorted(positions,key=lambda s:s['start'],reverse=True):
                            left,right = (body[a:b] for a,b in (site['left'],site['right']))
                            values = [left,right] if not reverse else [right,left]
                            replacement = helper+'('+', '.join('('+v+')' for v in values)+')'
                            text = text[:site['start']]+replacement+text[site['end']:]
                        text = text[:insertion]+definition+text[insertion:]
                        where = 'every site' if len(positions)>1 else str(positions[0]['start'])
                        label = f'lifetime operands {op["op"]} at {where} {ty} '+('right-first' if reverse else 'left-first')+(' assigned' if assign else '')
                        out.append((label,text))
    return out


def declared_types(code, end):
    """Resolve fields by their owning record, never by a shared member name."""
    from .signatures import member_declarations, declarator
    fields, instances = {}, {}
    for record in records(code,end):
        members = {}
        for name, typ, dims in (field for part in record['body'].split(';')
                               for field in member_declarations(part) or []):
            if dims:
                typ = (declarator(typ, '(*)'+''.join('['+d+']' for d in dims[1:])) if len(dims)>1
                       else declarator(typ, '*').strip())
            members[name] = typ
        fields[record['key']] = members
        if record['td'] and record['alias']:
            fields[record['alias']] = members
        elif record['alias'] and record['parent'] is None:
            instances[record['alias']] = record['kind']+' '+record['key']
    variables = {}
    type_names = set(fields) | {'void','char','short','int','long','float','double','u8','s8','u16','s16','u32','s32','u64','s64','f32','f64','BOOL'}
    type_names.update(re.findall(r'\btypedef\s+[^;{}]+?\b([A-Za-z_]\w*)\s*(?:\[[^]]*\])?\s*;',code))
    for decl in re.finditer(r'('+TYPE+r')\s*(?:(?<=\*)|\s)([A-Za-z_]\w*)\s*(?=[,;=)\[])', code):
        if re.search(r'\b(?:return|else|case|default|break|continue|goto|if|for|switch|while|do|sizeof)\b',decl[1]):
            continue
        typ = re.sub(r'\b(?:extern|static|register|const|volatile|signed|unsigned)\b|\*','',decl[1]).strip()
        if typ not in type_names and not re.fullmatch(r'(?:struct|union|enum)\s+\w+',typ):
            continue
        variables[decl[2]] = decl[1]+(' *' if code[decl.end():].startswith('[') else '')
    variables.update(instances)
    return fields, variables


def record_layouts(code, end, variables):
    """Byte offsets of explicitly declared PowerPC records and their members."""
    from .signatures import record_layouts as layouts
    parsed, _ = layouts(code, end)
    return {tag:{name:(offset,ty+''.join('['+str(n)+']' for n in dims[1:]),dims[0] if dims else None)
                 for name,ty,offset,width,dims in fields} for tag,fields in parsed.items()}


def member_type(expression, fields, variables):
    parts = re.split(r'->|\.', expression)
    ty = variables.get(parts[0], '')
    for member in parts[1:]:
        tag = record_tag(ty)
        ty = fields.get(tag, {}).get(member, '')
    return ty


def member_layout(expression, layouts, variables):
    """Address base and displacement through inline records and pointer loads."""
    root = re.match(r'\w+', expression)
    if not root:
        return None
    base, typ, offset, count = root[0], variables.get(root[0], ''), 0, None
    for member in re.finditer(r'(->|\.)(\w+)', expression[root.end():]):
        at = root.end() + member.start()
        if member[1] == '->' and at > root.end():
            base, offset = expression[:at], 0
        field = layouts.get(record_tag(typ), {}).get(member[2])
        if not field:
            return None
        delta, typ, count = field
        offset += delta
    return base, offset, typ, count


def accessor_lifetimes(body, name):
    """Repair saved accessors that let a copied aggregate's array escape."""
    from .sdkimport import masked
    from .signatures import member_declarations
    code=masked(body); span=_function_body_span(code,name)
    if not span:
        return []
    arrays={r['key']:{n for n,t,d in member_declarations(r['body']) or [] if d}
            for r in records(code,span[0])}
    pattern=(r'\bstatic\s+inline\s+('+TYPE+r')\s+(\w+)\s*\(\s*'
             r'((?:struct|union)\s+\w+|\w+)\s+(\w+)\s*\)\s*'
             r'\{\s*return\s+\4\.(\w+)\s*;\s*\}')
    changes=[]
    for helper in re.finditer(pattern,code[:span[0]]):
        ret,fn,typ,owner,field=helper.groups()
        if '*' not in ret or field not in arrays.get(record_tag(typ),set()):
            continue
        uses=[call for call in call_sites(body) if call[0]==fn and call[1]>=span[1]]
        if not uses or any(len(c[3])!=1 or not re.fullmatch(r'\w+',code[s:e].strip()) for c in uses for s,e in c[3]):
            continue
        changes.append((helper.start(),helper.end(),''))
        for _,start,end,args in uses:
            a,b=args[0];changes.append((start,end,'('+body[a:b]+').'+field))
    text=body
    for a,b,value in sorted(changes,reverse=True):text=text[:a]+value+text[b:]
    return [('restore escaping aggregate member',text)] if changes else []



def pointer_lifetimes(body, name):
    """Materialize pointer and floating-point reads at their evaluation point.

    A repeated member chain often conceals two live values from the allocator.
    Bind before a complete statement, never inside one of its unsequenced
    operands. Function-wide carriers let separate reads share a live range.
    """
    from .sdkimport import masked
    from .signatures import member_declarations
    code = masked(body)
    span = _function_body_span(code, name)
    if not span:
        return []
    fields, variables = declared_types(code, span[0])
    aliases = {}
    for declaration in re.finditer(r'\btypedef\s+([^;{}]+);', code[:span[0]]):
        aliases.update({name:typ for name,typ,dims in member_declarations(declaration[1]) or [] if not dims})
    pointers = {name for name,typ in aliases.items() if '*' in typ}
    while more := {name for name,typ in aliases.items() if typ in pointers} - pointers:
        pointers.update(more)
    out = []
    # A switch selected through a freshly loaded pointer already dominates
    # each arm. Keep that value when an earlier repair redundantly reassigns
    # it after stores to different fields of the same owner.
    for control,start,end,args in call_sites(code):
        if control!='switch' or len(args)!=1 or not span[1]<=start<end<span[2]:continue
        selector=re.fullmatch(r'\s*(\w+)->\w+\s*',code[slice(*args[0])])
        if not selector:continue
        var=selector[1];before=code[span[1]:start]
        init=re.search(r'\b'+re.escape(var)+r'\s*=\s*(\w+->\w+)\s*;\s*$',before)
        if not init:continue
        value=init[1];opening=re.match(r'\s*\{',code[end:])
        if not opening:continue
        closing=end+opening.end();depth=1
        while closing<span[2] and depth:
            depth+=(code[closing]=='{')-(code[closing]=='}');closing+=1
        region=code[end:closing]
        for reload in re.finditer(r'(?m)^[ \t]*'+re.escape(var)+r'\s*=\s*\(?'+re.escape(value)+r'\)?\s*;[^\S\n]*',region):
            a,b=end+reload.start(),end+reload.end()
            cases=list(re.finditer(r'\b(?:case\s+[^:]+|default)\s*:',code[end:a]))
            if not cases:continue
            prefix=code[end+cases[-1].end():a]
            if re.search(r'\b\w+\s*\(|\b(?:if|switch|for|while|goto)\b|[}\[\]]',prefix):continue
            writes=re.findall(r'([^;{}\n]+?)\s*=(?!=)',prefix)
            if any((lhs:=w.strip())==var or lhs==value or not re.fullmatch(r'\w+|'+re.escape(value.split('->')[0])+r'->\w+',lhs) for w in writes):continue
            out.append((f'lifetime retain switch pointer {var} at {a}',body[:a]+body[b:]))
    # An assignment at the first short-circuited read preserves its evaluation
    # point; hoisting the read before the condition can change both behavior
    # and the allocator's live ranges.
    for callee,start,end,args in call_sites(code):
        if callee!='if' or not span[1]<=start<end<span[2] or len(args)!=1:continue
        a,b=args[0];condition=code[a:b]
        if any(fn not in ('if','sizeof') for fn,lo,hi,_ in call_sites(condition)):
            continue
        sites={}
        for m in re.finditer(r'\b\w+(?:(?:->|\.)\w+)+',condition):
            if member_type(m[0],fields,variables).strip() not in ('u32','s32','unsigned','int'):continue
            sites.setdefault(m[0],[]).append(m)
        for expression,reads in sites.items():
            if len(reads)<2 or re.search(r'(?<![=!<>])=(?!=)|\+\+|--',condition):continue
            temp='fzgx_condition_'+str(a)
            if re.search(r'\b'+temp+r'\b',code):continue
            text=body
            for i,m in reversed(list(enumerate(reads))):
                replacement='('+temp+' = '+expression+')' if i==0 else temp
                lo,hi=a+m.start(),a+m.end();text=text[:lo]+replacement+text[hi:]
            ty=member_type(expression,fields,variables).strip()
            text=text[:span[1]]+'\n    '+ty+' '+temp+';'+text[span[1]:]
            out.append((f'lifetime condition {expression} at {a}',text))
    declarations = {}
    for line in re.finditer(r'(?m)^[ \t]*[^\n]+;[ \t]*$',code[span[1]:span[2]]):
        decl = DECL_RE.match(line[0])
        if not decl or decl[3] or decl[1].strip() in ('return','goto','break','continue'):
            continue
        declarations.setdefault(decl[2],[]).append((span[1]+line.start(),span[1]+line.end(),decl[1],decl[4]))
    leading = {r[3] for r in _locals(body,span)}
    for var, decls in declarations.items():
        if len(decls)<2 or var in leading or len({d[2] for d in decls})!=1:
            continue
        if re.search(r'\b'+re.escape(var)+r'\b',code[span[0]:span[1]]):
            continue
        text = body
        for a,b,ty,init in reversed(decls):
            replacement = (re.match(r'[ \t]*',body[a:b])[0]+var+' = '+body[a:b][body[a:b].find('=')+1:].strip()) if init else ''
            text = text[:a]+replacement+text[b:]
        text = text[:span[1]]+'\n    '+decls[0][2]+' '+var+';'+text[span[1]:]
        out.append(('lifetime shared local '+var,text))
    sites = {}
    pattern = re.compile(r'\b(\w+)((?:(?:->|\.)\w+)+)')
    for m in pattern.finditer(code, span[1], span[2]):
        if (code[:m.start()].rstrip().endswith(('.', '->'))
                or re.search(r'(?:&|\+\+|--)\s*\(*\s*$',code[:m.start()])):
            continue
        ty = variables.get(m[1], '')
        for member in re.finditer(r'(->|\.)(\w+)', m[2]):
            tag = record_tag(ty)
            ty = fields.get(tag, {}).get(member[2], '')
            end = m.start(2)+member.end()
            destination = end == m.end() and re.match(r'\s*\)*\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',code[end:])
            scalar = re.sub(r'\b(?:const|volatile)\b', '', ty).strip()
            if ('*' in ty or scalar in pointers or scalar in ('f32','float','f64','double')) and not destination:
                value_type = ty if '*' in ty else scalar
                sites.setdefault((body[m.start():end], value_type), []).append((m.start(),end))
    for (expression, ty), uses in sites.items():
        var = 'fzgx_live'
        while re.search(r'\b'+var+r'\b', code):
            var += '_'
        grouped = {}
        for a,b in uses:
            line = code.rfind('\n', span[1], a)+1
            grouped.setdefault(line, []).append((a,b))
        # A switch selector and its arms often consume the same pointer web.
        # A declaration in each arm cannot express that shared lifetime.
        for control in re.finditer(r'\bswitch\s*\([^;{}]*\)\s*\{', code[span[1]:span[2]]):
            lo, opening = span[1]+control.start(), span[1]+control.end()-1
            if expression not in body[lo:opening]:
                continue
            depth, end = 1, opening+1
            while depth and end < span[2]:
                depth += (code[end] == '{')-(code[end] == '}')
                end += 1
            if depth:
                continue
            text = body[lo:end]
            text = re.sub(r'\b'+re.escape(expression)+r'\b', var, text)
            replacement = '{\n    '+declarator(ty,var)+' = '+expression+';\n'+text+'\n}'
            out.insert(0, (f'lifetime switch pointer {expression} at {lo}', body[:lo]+replacement+body[end:]))
        edits = []
        for line, positions in grouped.items():
            # Each line must be a complete expression statement, without a
            # short-circuit or control-flow boundary between repeated reads.
            end = code.find('\n', positions[-1][1])
            statement = code[line:end]
            previous = code[span[1]-1:line].rstrip()
            if (any(x in statement for x in ('&&','||','?', 'if ', 'if(', 'while', 'for '))
                    or not statement.rstrip().endswith(';') or not previous.endswith((';','{','}',':'))
                    or statement.count('(')!=statement.count(')') or DECL_RE.fullmatch(statement)):
                continue
            changes = [(a,b,var) for a,b in positions]
            indent = re.match(r'[ \t]*', body[line:])[0]
            changes.insert(0, (line,line,indent+var+' = '+expression+';\n'))
            text = body
            for a,b,value in reversed(changes):
                text = text[:a]+value+text[b:]
            text = text[:span[1]]+'\n    '+declarator(ty,var)+';'+text[span[1]:]
            out.append((f'lifetime pointer {expression} at {line}', text))
            edits.extend(changes)
        if edits:
            text = body
            for a,b,value in sorted(edits, reverse=True):
                text = text[:a]+value+text[b:]
            text = text[:span[1]]+'\n    '+declarator(ty,var)+';'+text[span[1]:]
            out.insert(0, ('lifetime pointer '+expression+' at every site', text))
        # An inlined accessor has its own parameter/return webs before inlining.
        # This can separate a pointer lifetime without forcing a stack spill.
        root = re.match(r'\w+', expression)[0]
        root_type = variables.get(root)
        if root_type:
            helper = name+'_read_pointer'
            while re.search(r'\b'+helper+r'\b', code):
                helper += '_'
            expression_in_helper = 'owner'+expression[len(root):]
            argument = root
            if '*' not in root_type and record_tag(root_type) in fields:
                # Array members must still refer to the caller's object; a
                # by-value owner would return a pointer into a dead temporary.
                root_type += ' *'
                expression_in_helper = 'owner->'+expression[len(root)+1:]
                argument = '&'+root
            definition = 'static inline '+declarator(ty, helper+'('+declarator(root_type, 'owner')+')')+' { return '+expression_in_helper+'; }\n'
            insertion = body.rfind('\n', 0, span[0])+1
            for positions in [uses]+[[use] for use in uses]:
                text = body
                for a,b in reversed(positions):
                    text = text[:a]+helper+'('+argument+')'+text[b:]
                text = text[:insertion]+definition+text[insertion:]
                out.append((f'lifetime accessor {expression} at '+('every site' if positions is uses else str(positions[0][0])), text))
    # A store's address and computed value have independent lifetimes. Expose
    # either side while retaining the recovered field type and conversion.
    assignments = re.compile(r'(?m)^([ \t]*)(\w+(?:(?:->|\.)\w+)+)\s*=\s*([^;\n]+);')
    for assignment in assignments.finditer(code, span[1], span[2]):
        lhs = assignment[2]
        tokens = re.split(r'->|\.', lhs)
        ty = variables.get(tokens[0], '')
        for member in tokens[1:]:
            tag = record_tag(ty)
            ty = fields.get(tag, {}).get(member, '')
        if not ty or 'volatile' in ty or '__fzgx_record_' in ty:
            continue
        var = 'fzgx_value'
        while re.search(r'\b'+var+r'\b', code):
            var += '_'
        rhs = body[assignment.start(3):assignment.end(3)]
        for address in (False, True):
            declaration = declarator(ty, ('*' if address else '')+var)+';'
            first = '&('+lhs+')' if address else rhs
            second = '*'+var+' = '+rhs if address else lhs+' = '+var
            replacement = assignment[1]+var+' = '+first+';\n'+assignment[1]+second+';'
            text = body[:assignment.start()]+replacement+body[assignment.end():]
            text = text[:span[1]]+'\n    '+declaration+text[span[1]:]
            out.append((f'lifetime store {"address" if address else "value"} at {assignment.start()}', text))
    return out


def missing_values(body, name):
    """Bind a used but never-defined scalar to an already-read source lvalue.

    Preserve the existing load's evaluation point through an assignment expression.
    This repairs missing def/use edges without inserting an arbitrary entry load.
    """
    span = _function_body_span(body, name)
    if not span:
        return []
    locals_ = _locals(body, span)
    if not locals_:
        return []
    start = locals_[-1][1]
    tokens = [(m[0], m.start()+start, m.end()+start) for m in TOKEN.finditer(body[start:span[2]])
              if not m[0].startswith(('/*','//'))]
    out=[]
    for a,b,type_,var,dims in locals_:
        if dims or _init_of(body[a:b]):
            continue
        uses=[i for i,t in enumerate(tokens) if t[0]==var and (i==0 or tokens[i-1][0] not in ('.','->'))]
        if not uses:
            continue
        if any((i+1<len(tokens) and tokens[i+1][0] in ('=','+=','-=','*=','/=','++','--','|=','&=','^='))
               or (i and tokens[i-1][0] in ('++','--','&')) for i in uses):
            continue
        first=tokens[uses[0]][1]
        pattern=r'\b(?:lbl_\w+|[A-Za-z_]\w*(?:->|\.)[A-Za-z_]\w*)(?:(?:->|\.)[A-Za-z_]\w*|\[\d+\])*'
        for m in re.finditer(pattern,body[start:first]):
            lo,hi=start+m.start(),start+m.end()
            # Only reads, never assignment destinations or address-taking.
            if re.match(r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',body[hi:]) or body[max(start,lo-1):lo]=='&':
                continue
            replacement=f'({var} = {m[0]})'
            out.append((f'missing-value {var} from {m[0]} at {lo}',body[:lo]+replacement+body[hi:]))
    return out


def external_helper(body, name):
    """Use an already-owned helper instead of emitting a duplicate local copy."""
    span=_function_body_span(body,name)
    if not span:
        return
    start=body.rfind('\n',0,span[0])+1
    header=body[start:span[1]-1].strip()
    header=re.sub(r'\b(?:static|inline)\s+', '', header)
    yield 'reuse owned helper '+name,body[:start]+'extern '+header+';\n'+body[span[2]+1:]


def split_helper_calls(body, name):
    """Separate inlined uses from calls to an already-owned out-of-line helper."""
    span=_function_body_span(body,name)
    if not span:
        return
    alias=name+'_inline'
    if re.search(r'\b'+re.escape(alias)+r'\b',body):
        return
    uses=list(re.finditer(r'\b'+re.escape(name)+r'(?=\s*\()',body[span[2]+1:]))
    if not 1<=len(uses)<=8:
        return
    start=body.rfind('\n',0,span[0])+1
    signature=body[start:span[1]-1].strip()
    signature=re.sub(r'\b(?:static|inline|extern)\s+','',signature)
    # Keep the original signature for external calls; the private copy is only
    # allowed to survive if the compiler inlines every selected use.
    for mask in range(1,1<<len(uses)):
        text=body
        for i,use in reversed(list(enumerate(uses))):
            if mask & (1<<i):
                a,b=span[2]+1+use.start(),span[2]+1+use.end()
                text=text[:a]+alias+text[b:]
        text=text[:span[0]]+alias+text[span[0]+len(name):]
        text=text[:start]+'extern '+signature+';\n'+text[start:]
        yield f'split inline/external helper {name} uses {mask:x}',text


def inline_helpers(body, name, helpers=None):
    """Do not emit unused out-of-line copies of reconstructed static helpers.

    A REL retains these copies even when the target function inlined every call.
    They shift its text and every dependent relocation despite an exact function diff.

    A comment may sit between the parameter list and the brace (`static f32 vec_dist(...)
    /* locks the load order */ {`), which the original pattern did not allow through, so
    the one helper most likely to need inlining -- a hand-named reconstruction carrying a
    rationale -- was the one this never matched. `fn_1_17A9C` was parked as link-mismatch
    with `vec_dist` still out-of-line for exactly that reason.
    """
    pattern = re.compile(r'\bstatic\s+(?!inline\b)(?:'+TYPE+r')\s+(\w+)\s*\([^;{}]*\)\s*'
                         r'(?:(?://[^\n]*|/\*(?:[^*]|\*(?!/))*\*/)\s*)*\{')
    sites = [m.start()+len('static ') for m in pattern.finditer(body)
             if m[1] != name and (helpers is None or m[1] in helpers)]
    if len(sites)>1:
        text=body
        for at in reversed(sites):
            text=text[:at]+'inline '+text[at:]
        yield 'inline all static helpers',text
    for at in sites:
        yield 'inline helper at '+str(at), body[:at]+'inline '+body[at:]
    for definition in re.finditer(r'\bstatic\s+inline\s+(?:'+TYPE+r')\s+(\w+)\s*\([^;{}]*\)\s*\{',body):
        helper=definition[1]
        if helper==name or helpers is not None and helper not in helpers:
            continue
        prototypes=list(re.finditer(r'(?m)^(?!static\b)(?:extern\s+)?(?:'+TYPE+r')\s+'+re.escape(helper)+r'\s*\([^;{}]*\);',body[:definition.start()]))
        if prototypes:
            text=body
            for m in reversed(prototypes):
                text=text[:m.start()]+'static inline '+re.sub(r'^extern\s+','',m[0])+text[m.end():]
            yield 'localize inline helper declaration '+helper,text
    # A recovered helper can also be a public definition already owned by
    # another TU. Keep its body available to the inliner without exporting it.
    pattern = re.compile(r'(?m)^(?!static\b|extern\b)(?:'+TYPE+r')\s+(\w+)\s*\([^;{}]*\)\s*\{')
    for match in pattern.finditer(body):
        if match[1] != name and (helpers is None or match[1] in helpers):
            yield 'internal inline helper '+match[1], body[:match.start()]+'static inline '+body[match.start():]
