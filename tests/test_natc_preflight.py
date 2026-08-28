#!/usr/bin/env python3
"""Fixture test for tools/natc_preflight.py — refusal-cache round-trip.

Grounded in real callables: refusal_cache_key (content hash of a batch),
cached_refusal / save_refusal (file-backed under CACHE_ROOT). We point
CACHE_ROOT at a temp dir so nothing writes to [local cache]. Non-mutating
against the real fleet tree.
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


@pytest.fixture
def mod(tmp_path, monkeypatch):
    spec = importlib.util.spec_from_file_location(
        "natc_preflight", REPO / "tools/natc_preflight.py"
    )
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    monkeypatch.setattr(m, "CACHE_ROOT", tmp_path / "preflight-refusals")
    return m


def test_refusal_cache_roundtrip(mod, tmp_path):
    batch = tmp_path / "batch"
    batch.mkdir()
    (batch / "c.c").write_text("int f(void){return 0;}\n")
    (batch / "CARD.md").write_text("// provenance: original f\n")
    dest = tmp_path / "dest.c"
    dest.write_text("int f(void){return 0;}\n")  # must exist: key reads it
    pairs = [(batch / "c.c", dest)]
    key = mod.refusal_cache_key(batch, pairs, "refuse")
    assert mod.cached_refusal(key) is None  # cold cache
    mod.save_refusal(key, "refused: sample reason")
    assert mod.cached_refusal(key) == "refused: sample reason"


def test_refusal_cache_key_changes_with_content(mod, tmp_path):
    batch = tmp_path / "batch"
    batch.mkdir()
    (batch / "c.c").write_text("int f(void){return 0;}\n")
    dest = tmp_path / "dest.c"
    dest.write_text("int f(void){return 0;}\n")
    pairs = [(batch / "c.c", dest)]
    k1 = mod.refusal_cache_key(batch, pairs, "refuse")
    (batch / "c.c").write_text("int f(void){return 1;}\n")  # content changed
    k2 = mod.refusal_cache_key(batch, pairs, "refuse")
    assert k1 != k2  # cache key is content-addressed


def test_refusal_cache_key_stable_per_mode(mod, tmp_path):
    batch = tmp_path / "batch"
    batch.mkdir()
    (batch / "c.c").write_text("int f(void){return 0;}\n")
    dest = tmp_path / "dest.c"
    dest.write_text("int f(void){return 0;}\n")
    pairs = [(batch / "c.c", dest)]
    k1 = mod.refusal_cache_key(batch, pairs, "refuse")
    k2 = mod.refusal_cache_key(batch, pairs, "accept")
    # mode is part of the hash -> different keys for refuse vs accept
    assert k1 != k2
