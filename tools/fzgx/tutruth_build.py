"""Whole-object build checks for declaration reconciliation."""
from __future__ import annotations

import shlex
import subprocess
from pathlib import Path
from collections import defaultdict

from consolidate import objsig

from . import poolfix
from .project import ROOT, VERSIONS, load_json_retry, unit_matches


def link_signature(path: Path, preserve=()) -> tuple:
    """Compare emitted sections, bindings, alignment and relocations, not debug paths."""
    raw = objsig.sig(path)
    _, locals_by_location = objsig.canon(raw)
    locations = {n: loc for n, loc in locals_by_location.items() if n not in preserve
                 and any(row[0] == n and row[4] == 0 for row in raw['defs'])}
    raw['defs'] = {(locations.get(n, n), *rest) for n, *rest in raw['defs']}
    raw['relocs'] = {s: sorted((o, t, locations.get(n, n), a) for o, t, n, a in rels)
                     for s, rels in raw['relocs'].items()}
    elf = poolfix.Elf(path.read_bytes())
    return raw, {s['name']: s['addralign'] for s in elf.sections
                 if s['name'] in raw['sections'] and s['size']}


def renumber(pool, before, after):
    """Identify a numbered private name by its unchanged relocation use sites."""
    sites = defaultdict(set)
    uses = defaultdict(set)
    for sec, relocs in before['relocs'].items():
        for off, kind, name, addend in relocs:
            uses[name].add((sec, off, kind, addend))
    for sec, relocs in after['relocs'].items():
        for off, kind, name, addend in relocs:
            sites[(sec, off, kind, addend)].add(name)
    _, old_local = objsig.canon(before)
    _, new_local = objsig.canon(after)
    result = {}
    for old, target in pool.items():
        new = old
        if old in old_local and uses[old]:
            choices = set.intersection(*(sites[site] for site in uses[old])) & new_local.keys()
            if len(choices) != 1:
                return None
            new = next(iter(choices))
        if new in result:
            return None
        result[new] = target
    return result


class RegionalVerifier:
    """Check every matching region against the unit built by the hash gate."""

    def __init__(self, units: dict, scratch: Path, original: dict):
        self.scratch = scratch
        self.profiles = {}
        self.errors = {}
        self.memo = {}
        self.baselines = {}
        self.original = original
        self.raw_baselines = {}
        self.maps = {}
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
                self.profiles[key] = (base, mw, flags, pool, set(u.get('own') or []), set(u.get('export') or []))

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
        base, mw, flags, pool, own, exported = self.profiles[key]
        path = self.scratch / version / Path(base.name).with_suffix('.c')
        path.parent.mkdir(parents=True, exist_ok=True)
        obj = path.with_suffix('.o')
        cmd = [str(ROOT / 'build/tools/wibo'), str(ROOT / 'build/compilers' / mw / 'mwcceppc.exe')]
        cmd += shlex.split(flags) + ['-i', 'include', '-i', f'build/{version}/include',
                                      '-c', str(path), '-o', str(obj)]

        def compile_text(source):
            path.write_text(source)
            obj.unlink(missing_ok=True)
            cp = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=120)
            if cp.returncode or not obj.is_file():
                return f'{version}: {(cp.stdout + cp.stderr).strip()[-700:]}'
            return None

        def matches(mapping):
            if mapping:
                applied = {k: ('=' + ('+' if v in exported else '') + v if v in own else v)
                           for k, v in mapping.items()}
                result = poolfix.apply(obj, applied)
                if result['skipped'] or not result['rodata_emptied']:
                    return False
            return link_signature(obj, own) == self.baselines[key]

        err = compile_text(text)
        if err:
            return err
        if key not in self.baselines:
            self.baselines[key] = link_signature(base, own)
        raw = obj.read_bytes() if pool else b''
        if matches(pool):
            self.maps[key, text] = pool
            return None
        if pool and text != self.original[name]:
            obj.write_bytes(raw)
            candidate = objsig.sig(obj)
            if key not in self.raw_baselines:
                err = compile_text(self.original[name])
                if err:
                    return err
                self.raw_baselines[key] = objsig.sig(obj)
            mapping = renumber(pool, self.raw_baselines[key], candidate)
            if mapping is not None and mapping != pool:
                obj.write_bytes(raw)
                if matches(mapping):
                    self.maps[key, text] = mapping
                    return None
        return f'{version}: {name} differs from the production object (sections, symbols or relocations)'
