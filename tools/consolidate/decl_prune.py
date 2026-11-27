#!/usr/bin/env python3
"""Drop top-level declarations nothing in the file uses, keeping the compiled object identical.

  decl_prune.py [--apply] SOURCE...        (sources under src/, e.g. rel/movie_module/fn_12_4D4.c)

Recut pieces (tu_cut.py) and merged lifts carry the declarations of functions that now live in
other units: prototypes, externs, struct views and typedefs that their remaining functions never
name. Those leftovers are what makes the blocks of one TU disagree when they are reconciled
under one prologue. Roots are everything that emits code or data (non-static function
definitions, variable definitions) and every preprocessor line; an extern, prototype, typedef,
struct/union/enum definition or static function is kept when a kept item names it
(transitively; enumerators count as names). The pruned file must compile to the same object in
every region its unit builds for (sections, relocations and defined symbols), else it is left
as it is. Run gate.sh afterwards.
"""
import json, pathlib, re, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent))
import devprobe as d, objsig

IDENT = re.compile(r'\b[A-Za-z_]\w*\b')
KEYWORDS = set('auto break case char const continue default do double else enum extern float for goto if '
               'inline int long register return short signed sizeof static struct switch typedef union '
               'unsigned void volatile while asm'.split())


def items(text):
    """Top-level items: (start, end) spans; comments and blank lines join the following item."""
    out, i, n, start, depth = [], 0, len(text), 0, 0
    while i < n:
        c = text[i]
        if text.startswith('//', i):
            i = text.find('\n', i); i = n if i < 0 else i + 1; continue
        if text.startswith('/*', i):
            i = text.find('*/', i + 2); i = n if i < 0 else i + 2; continue
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            i = j + 1; continue
        if c == '#' and depth == 0 and (i == 0 or text[i - 1] == '\n'):
            j = i
            while True:
                j = text.find('\n', j); j = n if j < 0 else j
                if j > 0 and text[j - 1] == '\\' and j < n:
                    j += 1; continue
                break
            out.append((start, min(j + 1, n), 'pp')); start = i = min(j + 1, n); continue
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                # a function body ends the item; an aggregate definition runs on to its ';'
                head = strip_comments(text[start:i])
                if re.search(r'\)\s*\{', head) and not re.match(r'\s*(typedef|struct|union|enum)\b', head) \
                        and '=' not in head.split('{')[0]:
                    out.append((start, i + 1, 'fn')); start = i + 1
        elif c == ';' and depth == 0:
            out.append((start, i + 1, 'decl')); start = i + 1
        i += 1
    if text[start:].strip():
        out.append((start, n, 'tail'))
    return out


def strip_comments(s):
    return re.sub(r'//[^\n]*|/\*.*?\*/', ' ', s, flags=re.S)


def strip_strings(s):
    return re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', ' ', s)


def classify(kind, body):
    """(removable, defined names) of one item."""
    s = strip_strings(strip_comments(body)).strip()
    if kind in ('pp', 'tail') or not s:
        return False, set()
    if kind == 'fn':
        head = s.split('{')[0]
        name = re.findall(r'\b(\w+)\s*\(', head)
        names = {name[0]} if name else set()
        return bool(re.match(r'(static\b|inline\b)', head)) and 'static' in head.split(), names
    if re.match(r'typedef\b', s):
        tail = s.rsplit('}', 1)[-1] if '}' in s else s[len('typedef'):]
        names = set(re.findall(r'\(\s*\*\s*(\w+)\s*\)', tail)) or {w for w in IDENT.findall(re.sub(r'\[[^\]]*\]', '', tail)) if w not in KEYWORDS}
        names = {list(names)[-1]} if names and '}' not in s and not re.search(r'\(\s*\*', tail) else names
        tag = re.match(r'typedef\s+(?:struct|union|enum)\s+(\w+)', s)
        names |= {tag[1]} if tag else set()
        names |= enumerators(s)
        return True, names
    m = re.match(r'(struct|union|enum)\s+(\w+)?\s*\{', s)
    if m and s.rstrip(';').rstrip().endswith('}'):
        return True, ({m[2]} if m[2] else set()) | enumerators(s)
    if re.match(r'(struct|union|enum)\s+\w+\s*;$', s):
        return True, {s.split()[1].rstrip(';')}
    decl = s.split('=')[0]
    is_proto = re.search(r'\w\s*\([^()]*(\([^()]*\)[^()]*)*\)\s*;?$', decl.rstrip(';')) and '{' not in s
    if re.match(r'extern\b', s) or is_proto:
        d_ = re.sub(r'\([^()]*(\([^()]*\)[^()]*)*\)\s*;?$', '', decl.rstrip(';').rstrip()) if is_proto else decl
        d_ = re.sub(r'\[[^\]]*\]', '', d_).rstrip(';')
        words = [w for w in IDENT.findall(d_) if w not in KEYWORDS]
        fp = re.findall(r'\(\s*\*\s*(\w+)\s*\)', d_)
        return True, set(fp) if fp else ({words[-1]} if words else set())
    return False, set()   # a variable definition: emits data


def enumerators(s):
    m = re.search(r'\benum\b[^{]*\{([^}]*)\}', s)
    return {x.split('=')[0].strip() for x in m[1].split(',') if x.split('=')[0].strip()} if m else set()


def prune(text):
    its = items(text)
    info = [(a, b) + classify(k, text[a:b]) for a, b, k in its]
    keep = [not rem for _, _, rem, _ in info]
    refs = [set(IDENT.findall(strip_strings(strip_comments(text[a:b])))) - names for a, b, _, names in info]
    changed = True
    while changed:
        changed = False
        need = set().union(*(refs[k] for k in range(len(info)) if keep[k]))
        for k, (_, _, rem, names) in enumerate(info):
            if not keep[k] and names & need:
                keep[k] = changed = True
    out = ''.join(text[a:b] if keep[k] else re.sub(r'[^\n]', '', '') for k, (a, b, _, _) in enumerate(info))
    out += text[its[-1][1]:] if its else text
    return re.sub(r'\n{3,}', '\n\n', out), sum(not k for k in keep)


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    apply = '--apply' in sys.argv
    units = {u['source']: u for u in json.load(open('config/GFZE01/units.json'))}
    nu = d.ninja_units()
    total = 0
    for src in args:
        path = pathlib.Path('src', src)
        text = path.read_text()
        new, dropped = prune(text)
        if not dropped:
            continue
        u = units.get(src)
        key = 'src/' + src if 'src/' + src in nu else f'build/GFZE01/gen/{src}'
        if u is None or key not in nu or u.get('tu'):
            print('skip', src, 'not a standalone unit'); continue
        mv, cf = nu[key]
        with tempfile.TemporaryDirectory(dir='.fzgx/tu_collapse/tmp') as td:
            a, b = d.compile_all(text, mv, cf, td, u), d.compile_all(new, mv, cf, td, u)
            if None in a or None in b:
                print('no ', src, 'does not compile after pruning'); continue
            sigs = []
            for objs in (a, b):
                s_ = []
                for k, o in enumerate(objs):
                    p_ = pathlib.Path(td, f'{k}.o'); p_.write_bytes(o); g = objsig.sig(p_)
                    s_.append((g['sections'], g['relocs'], sorted(g['defs'])))
                sigs.append(s_)
        if sigs[0] != sigs[1]:
            print('no ', src, 'object changes'); continue
        total += dropped
        print(f'OK  {src}: -{dropped} declarations')
        if apply:
            path.write_text(new)
    print('dropped', total)


if __name__ == '__main__':
    main()
