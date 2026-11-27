"""Whole-object build checks for declaration reconciliation."""
from __future__ import annotations

import shlex
import subprocess
from pathlib import Path

from consolidate import objsig

from . import poolfix
from .project import ROOT, VERSIONS, load_json_retry, unit_matches


def link_signature(path: Path) -> tuple:
    """Compare emitted sections, bindings, alignment and relocations, not debug paths."""
    signature, _ = objsig.canon(objsig.sig(path))
    elf = poolfix.Elf(path.read_bytes())
    return signature, {s['name']: s['addralign'] for s in elf.sections
                       if s['name'] in signature['sections'] and s['size']}


class RegionalVerifier:
    """Check every matching region against the unit built by the hash gate."""

    def __init__(self, units: dict, scratch: Path):
        self.scratch = scratch
        self.profiles = {}
        self.errors = {}
        self.memo = {}
        self.baselines = {}
        for version in VERSIONS:
            selected = {n: u for n, u in units.items() if unit_matches(u, version)}
            if not selected:
                continue
            build = ROOT / 'build' / version
            meta_path = build / 'objdiff.json'
            config = (load_json_retry(meta_path) if meta_path.is_file() else None) or {}
            metadata = {row['name']: row for row in config.get('units', [])}
            for n, u in selected.items():
                key = version, n
                name = f"{u['module']}/{Path(u['source']).with_suffix('')}"
                meta = metadata.get(name, {})
                flags = meta.get('scratch', {}).get('c_flags')
                base = ROOT / meta.get('base_path', '')
                if (not flags or not meta.get('metadata', {}).get('complete') or not base.is_file()
                        or not (build / 'ok').is_file()):
                    self.errors[key] = f'{version}: build {u["source"]} with gate.sh before reconciliation'
                    continue
                mw = u.get('mw_version') or ('GC/1.2.5n' if u['module'] == 'main' else 'GC/1.3.2')
                pool = u.get('pool_for', {}).get(version, u.get('pool', {})) or {}
                pool = {k: ('=' + ('+' if v in (u.get('export') or []) else '') + v
                            if v in (u.get('own') or []) else v) for k, v in pool.items()}
                self.profiles[key] = (base, mw, flags, pool)

    def check(self, name: str, text: str) -> str | None:
        checked = False
        for version in VERSIONS:
            key = version, name
            if key in self.errors:
                return self.errors[key]
            if key not in self.profiles:
                continue
            checked = True
            memo_key = key, text
            if memo_key not in self.memo:
                self.memo[memo_key] = self._check(key, text)
            if self.memo[memo_key] is not None:
                return self.memo[memo_key]
        return None if checked else 'no matching regional production object'

    def _check(self, key: tuple, text: str) -> str | None:
        version, name = key
        base, mw, flags, pool = self.profiles[key]
        path = self.scratch / version / Path(base.name).with_suffix('.c')
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
        obj = path.with_suffix('.o')
        obj.unlink(missing_ok=True)
        cmd = [str(ROOT / 'build/tools/wibo'), str(ROOT / 'build/compilers' / mw / 'mwcceppc.exe')]
        cmd += shlex.split(flags) + ['-i', 'include', '-i', f'build/{version}/include',
                                      '-c', str(path), '-o', str(obj)]
        cp = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=120)
        if cp.returncode or not obj.is_file():
            return f'{version}: {(cp.stdout + cp.stderr).strip()[-700:]}'
        if pool:
            result = poolfix.apply(obj, pool)
            if result['skipped'] or not result['rodata_emptied']:
                return f'{version}: recorded pool bindings no longer apply ({result["skipped"]})'
        if key not in self.baselines:
            self.baselines[key] = link_signature(base)
        if link_signature(obj) != self.baselines[key]:
            return f'{version}: {name} differs from the production object (sections, symbols or relocations)'
        return None
