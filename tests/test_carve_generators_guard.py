#!/usr/bin/env python3
"""Item-6 integration contract: every carve generator that writes a TRACKED
src/ file must route that write through carve_guard.safe_write_carve (no bare
open(path,'w') on tracked sources). Closes finding 252 across the generator
family, not just the *_carve.py set.

This is a static-integration check, not a behavioral one (the generators need
the full decomp worktree to run; their behavioral refusal is covered by
tests/test_carve_guard.py). It asserts the guard is actually wired into the
write path and the dangerous raw-open form is gone.

Run: uv run --with capstone --with pytest python3 -m pytest tests/test_carve_generators_guard.py -q
"""

import re
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"

# (generator, tracked src path it writes) — the finding-252 surface.
GENERATORS = {
    "gen_gamehead.py": "src/game/gamehead_8005C120.c",
    "gen_mtx_probe.py": "src/dolphin/mtx/MTX.c",
    "gen_carve_cb20.py": "src/dolphin/metrotrk/<fam>.c",  # path built via os.path.join
    "sda21_fix.py": "src/dolphin/os/OSPanic.c",          # in-place rewrite of tracked src/
    "sda21_symbolize.py": "src/dolphin/os/OSPanic.c",     # in-place rewrite of tracked src/
    "convert_global_named.py": "src/dolphin/os/OSThread.c",  # glob src/**/<unit>.c in place
    "gen_asm_from_disasm.py": "src/dolphin/os/OSThreadScheduler.c",  # hardcoded tracked src/
    "fix_reloc_pairs.py": "src/dolphin/os/OSThread.c",   # src/**/*.c in place (--all)
    "rename_sym.py": "src/dolphin/os/OSThread.c",        # every matching src/**/*.c in place
}


def test_generators_import_carve_guard():
    for name in GENERATORS:
        src = (TOOLS / name).read_text()
        assert "carve_guard" in src, f"{name}: must import carve_guard"
        assert "safe_write_carve" in src, f"{name}: must call safe_write_carve"


def test_generators_no_bare_raw_open_for_tracked_src():
    # A raw open(path,'w') is only acceptable if path is NOT a tracked src/ target.
    # These three must not contain the old pattern for their tracked targets.
    for name, tracked in GENERATORS.items():
        src = (TOOLS / name).read_text()
        # The dangerous idiom we removed: open(<path>,'w').write(... ) writing a
        # literal or joined path ending in the tracked .c name.
        dangerous = re.findall(r"open\(\s*[^)]*['\"]w['\"]\s*\)\.write", src)
        # Acceptable: none of the three should still carry the old raw-open write.
        assert not dangerous, (
            f"{name}: still has raw open(...,'w').write(...) — finding-252 reintroduced"
        )
        if "<fam>" not in tracked:
            # The path may appear in the print() confirmation line; only the open()
            # write target is forbidden, which the dangerous-regex above already checks.
            # Confirm the safe_write_carve call is present and the raw-open is gone.
            assert "safe_write_carve" in src, f"{name}: safe_write_carve missing"
            assert f"open('{tracked}'" not in src, f"{name}: raw open of {tracked}"
            assert f'open("{tracked}"' not in src, f"{name}: raw open of {tracked}"


def test_all_tracked_src_paths_guarded():
    # Cross-check: every tracked src/ target referenced by these generators is
    # now reached via safe_write_carve, never a raw 'w' open.
    for name, tracked in GENERATORS.items():
        src = (TOOLS / name).read_text()
        writes_via_guard = src.count("safe_write_carve")
        raw_writes = len(re.findall(r"open\([^)]*,\s*['\"]w['\"]\s*\)", src))
        assert writes_via_guard >= 1, f"{name}: no safe_write_carve call found"
        assert raw_writes == 0, f"{name}: {raw_writes} raw 'w' open(s) remain"
