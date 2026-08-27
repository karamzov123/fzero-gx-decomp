#!/usr/bin/env python3
"""Fixture tests for tools/carve_guard.py (item 5, finding 252).

Guards against a carve generator silently reverting LANDED tracked src/ by
overwriting a file whose on-disk content differs from HEAD. The guard must be
fail-closed: refuse the write, leave the file byte-identical, and only allow an
override when it first stashes a timestamped copy of the displaced content.

Run: uv run --with capstone --with pytest python3 -m pytest tests/test_carve_guard.py -q
"""

import os
import subprocess
import sys
import tempfile
from pathlib import Path

import pytest

# Import the module under test from the repo tools/ dir.
REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import carve_guard as cg  # noqa: E402


def _init_repo(td: Path) -> dict:
    """Make a throwaway git repo with one landed carve file. Returns env dict."""
    env = {
        **os.environ,
        "GIT_AUTHOR_NAME": "t",
        "GIT_AUTHOR_EMAIL": "t@t",
        "GIT_COMMITTER_NAME": "t",
        "GIT_COMMITTER_EMAIL": "t@t",
    }
    subprocess.run(["git", "init", "-q"], cwd=td, check=True, env=env)
    src = td / "src" / "dolphin"
    src.mkdir(parents=True)
    landed = src / "MTXFused.c"
    landed.write_text("lis r6, lbl_801327F8+0x28@h\n")  # the landed named-reloc form
    subprocess.run(["git", "add", "-A"], cwd=td, check=True, env=env)
    subprocess.run(["git", "commit", "-qm", "landed"], cwd=td, check=True, env=env)
    return env


def _cleanup_stashes():
    """Remove any stash files this test run created (namespaced by suffix)."""
    for p in cg.STASH_ROOT.glob("MTXFused.c.*.preforce"):
        try:
            p.unlink()
        except OSError:
            pass


@pytest.fixture
def repo(tmp_path):
    env = _init_repo(tmp_path)
    yield tmp_path, env
    _cleanup_stashes()


def test_classify_clean(repo):
    td, _ = repo
    landed = td / "src" / "dolphin" / "MTXFused.c"
    st, _ = cg.classify(landed)
    assert st == "clean"


def test_classify_modified_refuses(repo):
    td, _ = repo
    landed = td / "src" / "dolphin" / "MTXFused.c"
    # Simulate finding-252: regenerated raw output written locally.
    landed.write_text("lis r6, -0x7fed\n")
    st, _ = cg.classify(landed)
    assert st == "modified"

    with pytest.raises(cg.CarveRefusal):
        cg.safe_write_carve(landed, "raw carve output\n", quiet=True)
    # Refusal must be non-destructive: file left byte-identical.
    assert landed.read_text() == "lis r6, -0x7fed\n"


def test_clean_rewrite_unchanged(repo):
    td, _ = repo
    landed = td / "src" / "dolphin" / "MTXFused.c"
    # Regenerating identical content is a no-op.
    act = cg.safe_write_carve(landed, "lis r6, lbl_801327F8+0x28@h\n", quiet=True)
    assert act == "unchanged"
    assert landed.read_text() == "lis r6, lbl_801327F8+0x28@h\n"


def test_force_overrides_and_stashes(repo):
    td, _ = repo
    landed = td / "src" / "dolphin" / "MTXFused.c"
    landed.write_text("lis r6, -0x7fed\n")  # modified on disk
    act = cg.safe_write_carve(landed, "raw carve output\n", force=True, quiet=True)
    assert act == "forced"
    assert landed.read_text() == "raw carve output\n"
    stashes = list(cg.STASH_ROOT.glob("MTXFused.c.*.preforce"))
    assert stashes, "forced overwrite must stash displaced content"
    newest = max(stashes, key=lambda p: p.stat().st_mtime)
    assert newest.read_text() == "lis r6, -0x7fed\n"


def test_env_override_natc_force_carve(repo, monkeypatch):
    td, _ = repo
    landed = td / "src" / "dolphin" / "MTXFused.c"
    landed.write_text("lis r6, -0x7fed\n")
    monkeypatch.setenv("NATC_FORCE_CARVE", "1")
    act = cg.safe_write_carve(landed, "raw carve output\n", quiet=True)
    assert act == "forced"
    assert landed.read_text() == "raw carve output\n"


def test_new_file_created(repo):
    td, _ = repo
    fresh = td / "src" / "dolphin" / "NewCarve.c"
    act = cg.safe_write_carve(fresh, "new\n", quiet=True)
    assert act == "created"
    assert fresh.read_text() == "new\n"


def test_tracked_deleted_restored(repo):
    td, _ = repo
    landed = td / "src" / "dolphin" / "MTXFused.c"
    landed.unlink()  # tracked at HEAD, gone on disk -> restore is safe
    st, _ = cg.classify(landed)
    assert st == "clean"
    act = cg.safe_write_carve(landed, "restored\n", quiet=True)
    assert act in ("created", "rewritten")
    assert landed.read_text() == "restored\n"


def test_cli_check_modified_exits_refusal(repo, monkeypatch):
    td, _ = repo
    landed = td / "src" / "dolphin" / "MTXFused.c"
    landed.write_text("lis r6, -0x7fed\n")
    monkeypatch.setattr(sys, "argv", ["carve_guard.py", "--check", str(landed)])
    r = cg.main()
    assert r == cg.GUARD_EXIT
