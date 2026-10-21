"""Harvest matched C from another ref of this project: a fork branch or a cloud-session branch.

A ref's `state/ledger.json` lists what it matched; for every function matched there and
unmatched here, the ref's C is tried under the ref's recorded compiler options, with the
ref's symbol names rebound to ours by (module, section, address):

  raw            the ref's unit text, includes resolving against this tree
  ours-prologue  the ref's block under this TU's prologue
  preprocessed   the ref's unit expanded by MWCC -EP in the ref's own tree (pragmas kept)

Only full-oracle matches and pool matches are submitted, through claim/write_unit/submit,
so lint and every acceptance gate apply; `fzgx verify` still links and checks all 16 hashes.
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
from .ledger import Ledger
from .project import ROOT, STATE_DIR, Project

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


def gain(tree: Path) -> List[str]:
    theirs = json.loads((tree / 'state/ledger.json').read_text())['functions']
    ours = dict(Ledger().db.execute('SELECT symbol, status FROM functions'))
    return sorted(r['symbol'] for r in theirs if r['status'] == 'matched' and ours.get(r['symbol']) == 'unmatched')


class Source:
    def __init__(self, p: Project, tree: Path, workdir: Path):
        self.p, self.tree, self.workdir = p, tree, workdir
        self.units = {s: u for u in json.loads((tree / 'config/GFZE01/units.json').read_text())
                      for s in u.get('symbols', [])}
        self.blocks: Dict[str, Path] = {}
        for path in (tree / 'src').rglob('*.c'):
            text = path.read_text(errors='replace')
            for m in re.finditer(r'^/\* fzgx:begin (\w+)', text, re.M):
                self.blocks.setdefault(m[1], path)
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
        u = self.units.get(sym) or {}
        for path in ([self.tree / 'src' / u['tu']] if u.get('tu') else []) + (
                [self.blocks[sym]] if sym in self.blocks else []):
            if path.exists():
                tf = tufile.parse(path.read_text(errors='replace'))
                if tf.get(sym):
                    return tf, tufile.gen_text(tf, sym)
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
        src = self.workdir / 'pp' / f'{tag}.c'
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

    def screen(self, sym: str) -> dict:
        s = self.p.resolve(sym)
        if s is None:
            return dict(symbol=sym, status='unknown-here')
        module = s.module
        u = self.units.get(sym) or {}
        mw = u.get('mw_version') or oracle.module_flags(self.p, module)[1]
        flags = list(u.get('extra_cflags') or [])
        ftf, ftext = self.unit_text(sym)
        if ftext is None:
            return dict(symbol=sym, module=module, size=s.size, status='no-source')
        cands = [('raw', lambda: self.rebind(ftext, module))]
        ours_tu = tufile.tu_source_for(self.p, s)
        if ftf is not None and ours_tu and tufile.tu_path(self.p, ours_tu).exists():
            cands.append(('ours-prologue', lambda: tufile.load(self.p, ours_tu).prologue + '\n'
                          + self.rebind(ftf.get(sym).body, module)))
        cands.append(('preprocessed', lambda: self.rebind(self.preprocess(ftext, module, mw, flags, sym), module)))
        tried, best = [], None
        for kind, make in cands:
            try:
                body = make()
                f = self.workdir / 'bodies' / f'{sym}.{kind}.c'
                f.parent.mkdir(parents=True, exist_ok=True)
                f.write_text(body)
                r = oracle.check(self.p, sym, 0, source=f, mw_version=mw, extra_cflags=shlex.join(flags))
            except Exception as error:  # a broken candidate never stops the harvest
                tried.append(dict(kind=kind, error=str(error)[-300:]))
                continue
            rec = dict(kind=kind, percent=r.percent, matched=r.matched, pool=r.matched_pool, body=str(f),
                       mw=r.mw_version or mw, flags=r.extra_cflags if r.extra_cflags is not None else shlex.join(flags),
                       error=(r.error or '')[-300:])
            tried.append(rec)
            if best is None or (rec['matched'], rec['pool'], rec['percent']) > (best['matched'], best['pool'], best['percent']):
                best = rec
            if r.matched:
                break
        status = 'matched' if best and best['matched'] else 'pool' if best and best['pool'] else 'partial' if best else 'failed'
        return dict(symbol=sym, module=module, size=s.size, status=status, best=best, tried=tried)


def land(p: Project, results: List[dict], agent: str, label: str, provenance: Path,
         skip: frozenset = frozenset()) -> dict:
    prov = json.loads(provenance.read_text()) if provenance.exists() else {}
    todo = sorted((r for r in results if r['status'] in ('matched', 'pool')
                   and r['symbol'] not in prov and r['symbol'] not in skip),
                  key=lambda r: (r['status'] != 'matched', r['size']))
    landed, failed = [], []
    for r in todo:
        sym, b = r['symbol'], r['best']
        body = Path(b['body']).read_text()
        c = api.claim(p, sym, agent, max_attempts=999)
        if not c.get('ok'):
            failed.append(dict(symbol=sym, stage='claim', error=c.get('error')))
            continue
        w = api.write_unit(p, sym, agent, body)
        if not w.get('ok'):
            api.release(p, sym, 'harvest: write failed', agent=agent)
            failed.append(dict(symbol=sym, stage='write', error=w.get('error')))
            continue
        s = api.submit(p, sym, agent=agent, message=f'harvest {sym} from {label}', harness='harvest',
                       model=label, mw_version=b.get('mw'), extra_cflags=b.get('flags') or '')
        if s.get('ok'):
            prov[sym] = dict(source=label, kind=b['kind'], status=r['status'], mw=b.get('mw'), flags=b.get('flags'),
                             sha256=hashlib.sha256(body.encode()).hexdigest(), landed=int(time.time()))
            provenance.parent.mkdir(parents=True, exist_ok=True)
            provenance.write_text(json.dumps(prov, indent=1, sort_keys=True) + '\n')
            landed.append(sym)
        else:
            failed.append(dict(symbol=sym, stage='submit', error=str(s.get('error') or s)[:300]))
            try:
                api.release(p, sym, 'harvest: submit failed', agent=agent, save_only=True)
            except Exception as error:
                failed[-1]['release'] = str(error)
    return dict(landed=len(landed), failed=failed)


def run(p: Project, ref: str, label: Optional[str] = None, do_land: bool = False,
        workers: int = 12, limit: Optional[int] = None, symbols: Optional[List[str]] = None) -> dict:
    tree = export(ref)
    sha = (tree / '.complete').read_text().strip()
    label = label or f'{ref}@{sha[:8]}'
    workdir = STATE_DIR / 'harvest' / (sha[:12] + '-work')
    syms = symbols or gain(tree)
    syms = sorted(syms, key=lambda k: getattr(p.resolve(k), 'size', 0))[:limit] if limit else syms
    src = Source(p, tree, workdir)
    with ThreadPoolExecutor(workers) as ex:
        results = list(ex.map(src.screen, syms))
    (workdir / 'results.json').write_text(json.dumps(results, indent=1))
    counts: Dict[str, int] = {}
    for r in results:
        counts[r['status']] = counts.get(r['status'], 0) + 1
    out = dict(ref=ref, sha=sha, candidates=len(syms), screened=counts, results=str(workdir / 'results.json'))
    if do_land:
        owner = re.sub(r'[^\w.-]+', '-', label.split('@')[0].split('/')[0]).strip('-') or 'harvest'
        out['land'] = land(p, results, f'harvest-{owner}', label, ROOT / 'state/forkimports' / f'{owner}.json')
    return out
