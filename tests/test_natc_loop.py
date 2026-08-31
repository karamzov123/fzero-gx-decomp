import importlib.util
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
SPEC = importlib.util.spec_from_file_location(
    "natc_loop_under_test", ROOT / "tools/natc_loop.py")
assert SPEC and SPEC.loader
loop = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(loop)


class NatcLoopContextTests(unittest.TestCase):
    """Contract tests for natc_loop.build_context (item 4).

    build_context shells out to find_xrefs/similar/natc_refs; those need the
    real objects + (for disasm) capstone via uv. We assert the assembled
    context carries every section the spec demands, and skip the disasm-
    dependent tail when uv/capstone is unavailable.
    """

    UNIT = "main/dolphin/gx/GXMisc"
    SYM = "GXSetMisc"

    def test_context_contains_symbolised_disasm_section(self):
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("FUNCTION GXSetMisc", ctx)
        self.assertIn("size", ctx)

    def test_context_contains_xref_summary(self):
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("XREF SUMMARY", ctx)
        self.assertIn("CALLERS", ctx)
        self.assertIn("GXInit", ctx)  # known caller of GXSetMisc

    def test_context_surfaces_find_xrefs_header_fragment_verbatim(self):
        # The single most useful artifact: the minimal compilable decls this
        # symbol's relocations require — must be present, never blank.
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("MINIMAL HEADER FRAGMENT", ctx)
        self.assertIn("gx", ctx)

    def test_context_contains_similar_twins_section(self):
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("SIMILAR TWINS", ctx)

    def test_context_contains_reference_dump_section(self):
        # Step 0 of the loop: natc_refs --unit --dump results.
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("REFERENCE BODIES", ctx)

    def test_reference_context_uses_at_most_two_real_bodies_and_excludes_asm(self):
        unit = "main/test/unit"
        with tempfile.TemporaryDirectory() as td:
            refdir = Path(td) / ".cache/natc/ref-bodies" / unit.replace("/", "_")
            refdir.mkdir(parents=True)
            (refdir / "Target.c").write_text(
                "// provenance: dolsdk2001:Target.c:10\n"
                "int Target(int x) { return x + 1; }\n")
            (refdir / "Helper.c").write_text(
                "// provenance: melee:Helper.c:20\n"
                "int Helper(int x) { return x - 1; }\n")
            (refdir / "Asm.c").write_text(
                "// provenance: melee:Asm.c:30\n"
                "asm void Asm(void) { nop; }\n")
            with patch.object(loop.Path, "home", return_value=Path(td)):
                bodies = loop._reference_bodies(unit, "Target", max_chars=10000)
            self.assertLessEqual(len(bodies), 2)
            self.assertEqual(len(bodies), 2)
            joined = "\n".join(bodies)
            self.assertIn("Target", joined)
            self.assertIn("Helper", joined)
            self.assertNotIn("asm void", joined)
            self.assertIn("provenance:", joined)

    def test_reference_context_size_budget_is_fail_closed(self):
        unit = "main/test/unit"
        with tempfile.TemporaryDirectory() as td:
            refdir = Path(td) / ".cache/natc/ref-bodies" / unit.replace("/", "_")
            refdir.mkdir(parents=True)
            (refdir / "Target.c").write_text(
                "// provenance: dolsdk2001:Target.c:1\n"
                "int Target(void) { return 1; }\n" + "x" * 200)
            with patch.object(loop.Path, "home", return_value=Path(td)):
                self.assertEqual(loop._reference_bodies(unit, "Target", max_chars=20), [])

    def test_reference_dump_report_is_not_candidate_context(self):
        with patch.object(loop, "_reference_bodies", return_value=[
                "// provenance: dolsdk2001:X.c:1\nint GXSetMisc(void) { return 0; }\n"],), \
             patch.object(loop, "symbolised_disasm", return_value=("FUNCTION GXSetMisc", [], "")), \
             patch.object(loop, "sh", return_value=(0, "UNIT COVERAGE REPORT 99%", "")), \
             patch.object(loop, "run_m2c_seed", return_value=(False, "(unavailable)")), \
             patch.object(loop, "run_similar", return_value=(False, "unavailable")), \
             patch.object(loop, "runtime_context_section", return_value="runtime"):
            # find_xrefs is the first sh call; return a valid minimal payload.
            with patch.object(loop, "sh", side_effect=[
                    (0, '{"definition": {}, "callers": [], "callees": [], "globals_referenced": [], "reloc_histogram": {}, "header_fragment": "int gx;"}', ""),
                    (0, "UNIT COVERAGE REPORT 99%", "")]):
                ctx = loop.build_context("u", "GXSetMisc")
            self.assertIn("int GXSetMisc", ctx)
            self.assertNotIn("UNIT COVERAGE REPORT", ctx)
    def test_context_contains_verified_runtime_facts_for_referenced_globals(self):
        runtime = ("--- VERIFIED RUNTIME FACTS (evidence only) ---\n"
                   "CARD.__CARDBlock[2] address=0x80177960")
        with patch.object(loop, "runtime_context_section", return_value=runtime) as select:
            ctx = loop.build_context(self.UNIT, self.SYM)

        self.assertIn(runtime, ctx)
        symbols = select.call_args.args[1]
        self.assertIn(self.SYM, symbols)
        self.assertIn("gx", symbols)

    def test_context_contains_provenance_seed(self):
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("PROVENANCE SEED", ctx)

    # CLI-level: --context-only must NOT require --worker (context assembly
    # never writes fleet state). A regression broke this by demanding the
    # worker id for every non-self-test invocation.
    def test_cli_context_only_without_worker(self):
        import subprocess
        r = subprocess.run(
            ["python3", "tools/natc_loop.py",
             "--unit", self.UNIT, "--symbol", self.SYM, "--context-only"],
            cwd=ROOT, capture_output=True, text=True)
        self.assertEqual(r.returncode, 0,
                         f"--context-only failed without --worker: "
                         f"{r.stderr[-300:]}")
        self.assertIn("SIMILAR TWINS", r.stdout)

    def test_context_has_no_blank_placeholder_for_header(self):
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertNotIn("(none)", ctx.split("MINIMAL HEADER FRAGMENT")[1]
                          if "MINIMAL HEADER FRAGMENT" in ctx else ctx)

    # --- regression: relocation column must render (was silently blank) ----
    # symbolised_disasm keyed relmap by SECTION-ABSOLUTE offset while the
    # disasm rows are FUNCTION-RELATIVE, so reloc types/symbols never lined up
    # and the column was empty. Workers would have chosen declaration shapes
    # blind. GXSetMisc references `gx` via SDA21, so the column must show it.
    def test_context_disasm_shows_sda21_reloc_column(self):
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("R_PPC_EMB_SDA21", ctx)
        self.assertIn("gx", ctx)
        # the per-instruction reloc annotation line
        self.assertIn("R_PPC_EMB_SDA21 gx", ctx)

    def test_attempt_budget_ignores_legacy_metadata_rows(self):
        import sqlite3
        import tempfile
        from unittest.mock import patch

        with tempfile.TemporaryDirectory() as td:
            db = Path(td) / ".cache/natc/runs.sqlite"
            db.parent.mkdir(parents=True)
            con = sqlite3.connect(db)
            con.execute(
                "create table attempts(unit text, symbol text, kind text, "
                "attempt integer, ts real, ctx_sha text)"
            )
            rows = [
                ("u", "s", None, None, 0.0, None),
                ("u", "s", "attempt", 1, 1.0, "ctx"),
                ("u", "s", "verify", None, 2.0, "ctx"),
            ]
            con.executemany("insert into attempts values(?,?,?,?,?,?)", rows)
            con.commit()
            con.close()
            with patch.object(loop.Path, "home", return_value=Path(td)), \
                    patch.object(loop, "_budget_context", return_value="ctx"):
                self.assertEqual(loop.attempts_used("u", "s"), 1)

    # Viewing context never spends an attempt; an already-landed function
    # must still be viewable even when its conversion budget is exhausted.
    def test_context_only_not_blocked_by_budget(self):
        import subprocess
        # OSInitAlloc is a landed function with many ok attempts; pick a unit
        # whose symbol is known to exist in the object index.
        r = subprocess.run(
            ["python3", "tools/natc_loop.py",
             "--unit", "main/dolphin/os/OSAllocHead",
             "--symbol", "OSInitAlloc", "--context-only"],
            cwd=ROOT, capture_output=True, text=True)
        self.assertEqual(r.returncode, 0,
                         f"--context-only blocked for landed fn: "
                         f"{r.stderr[-300:]}")
        self.assertIn("FUNCTION OSInitAlloc", r.stdout)
        # reloc column must be present (the other regression)
        self.assertIn("R_PPC_EMB_SDA21", r.stdout)


    # --- DOL-only fallback (no per-unit object) ----------------------------
    # MTX's fn_8006E250 / C_MTXMultVec lives ONLY inside the linked main.dol
    # (no MTX.o function entry). symbolised_disasm must fall back to DOL-
    # derived disasm instead of erroring. Regression: a bytes `input` paired
    # with `text=True` crashed the nested uv subprocess with
    # "'bytes' object has no attribute 'encode'".
    def test_dol_fallback_disasms_dol_only_symbol(self):
        dis, traps, err = loop.symbolised_disasm(
            "main/dolphin/mtx/MTX", "fn_8006E250", max_lines=80)
        self.assertEqual(err, "", f"fallback errored: {err}")
        self.assertIsNotNone(dis, "DOL fallback returned no disasm")
        self.assertIn("FUNCTION fn_8006E250", dis)
        # The fixed-coefficient ABI the board describes: r5 = 0xE0000000
        # base via `lis r5,-0x2000` then lfs off +0x0C/+0x1C/+0x2C.
        # `lfs f10, 0xc(r5)` proves the DOL slice landed right.
        self.assertIn("lfs f10, 0xc(r5)", dis)

    def test_dol_fallback_context_only(self):
        import subprocess
        r = subprocess.run(
            ["python3", "tools/natc_loop.py",
             "--unit", "main/dolphin/mtx/MTX",
             "--symbol", "fn_8006E250", "--context-only"],
            cwd=ROOT, capture_output=True, text=True)
        self.assertEqual(r.returncode, 0,
                         f"--context-only DOL fallback failed: "
                         f"{r.stderr[-300:]}")
        self.assertIn("FUNCTION fn_8006E250", r.stdout)

    # --- item 3 wiring: the loop must actually run emit_m2c_asm and surface
    #     its m2c CFG/type SEED in the assembled context. The spec names item
    #     3 ("emit_m2c_asm.py") as one of the tools the loop runs; a build
    #     that omitted it left the M2C SEED section absent. The seed is a
    #     SEED, not a matching oracle, so we assert presence + the
    #     identifying header, nothing about inferred types.
    def test_context_contains_m2c_seed_section(self):
        ctx = loop.build_context(self.UNIT, self.SYM)
        self.assertIn("M2C SEED (item 3", ctx)

    def test_m2c_seed_section_has_real_seed_for_carved_unit(self):
        # GXSetMisc has a real object + m2c path; the SEED subsection must
        # carry actual C (extern/void), not just the "(unavailable)" note.
        ctx = loop.build_context(self.UNIT, self.SYM)
        seed_block = ctx.split("M2C SEED (item 3", 1)[1]
        # either a real seed header or an unavailable note — both valid, but
        # the unavailable note must be explicit and clean (never a traceback).
        self.assertTrue(
            "SEED ONLY" in seed_block or "unavailable" in seed_block,
            "M2C SEED section neither carried a seed nor stated unavailable")
        self.assertNotIn("Traceback", ctx,
                         "m2c seed path leaked a traceback into context")

    def test_m2c_seed_clean_unavailable_for_dol_only_symbol(self):
        # fn_8006E250 is DOL-only (no per-unit object) -> emit_m2c_asm cannot
        # run; the loop must surface a clean note, not crash.
        import subprocess
        r = subprocess.run(
            ["python3", "tools/natc_loop.py",
             "--unit", "main/dolphin/mtx/MTX",
             "--symbol", "fn_8006E250", "--context-only"],
            cwd=ROOT, capture_output=True, text=True)
        self.assertEqual(r.returncode, 0,
                         f"DOL-only context failed: {r.stderr[-300:]}")
        self.assertIn("M2C SEED (item 3)", r.stdout)
        self.assertIn("unavailable", r.stdout)

    # --- T9 fixed-coefficient ABI trap (findings 242/244) -------------------
    # The hard-tail most-repeated hazard: a fixed base 0xE0000000 materialised
    # via `lis rN,-0x2000` with coefficient lanes +0x0C/+0x1C/+0x2C. The loop
    # must flag this so a worker does NOT model it as a conventional SDK
    # Mtx44/Vec. fn_8006E250 is the canonical DOL-only example; its disasm
    # carries `-0x2000` and `lfs f10, 0xc(r5)`, which the trap keys off.
    def test_trap_t9_fixed_coefficient_abi(self):
        dis, traps, err = loop.symbolised_disasm(
            "main/dolphin/mtx/MTX", "fn_8006E250", max_lines=80)
        self.assertEqual(err, "", f"disasm errored: {err}")
        self.assertIsNotNone(dis, "no disasm")
        self.assertTrue(
            any("fixed-coefficient ABI" in t for t in traps),
            f"T9 trap missing for fixed-coefficient ABI fn: traps={traps}")

    def test_trap_t9_surfaced_in_context(self):
        import subprocess
        r = subprocess.run(
            ["python3", "tools/natc_loop.py",
             "--unit", "main/dolphin/mtx/MTX",
             "--symbol", "fn_8006E250", "--context-only"],
            cwd=ROOT, capture_output=True, text=True)
        self.assertEqual(r.returncode, 0,
                         f"context failed: {r.stderr[-300:]}")
        self.assertIn(
            "TRAPS IN PLAY", r.stdout,
            "no TRAPS section emitted for hard-tail fn")
        self.assertIn(
            "fixed-coefficient ABI", r.stdout,
            "T9 fixed-coefficient ABI trap not surfaced in TRAPS section")

    # --- crash resilience: a broken objdiff.json must NOT take down the whole
    #     context assembly. build_context must still emit xref/twins/refs and
    #     a clean "(disasm unavailable: ...)" note — never a traceback. This is
    #     the contract guarantee that context assembly never crashes when a
    #     dependency is unavailable/transient.
    def test_context_survives_broken_objdiff_json(self):
        import shutil, tempfile
        obj = ROOT / "objdiff.json"
        tmp = tempfile.mkdtemp()
        backup = Path(tmp) / "objdiff.json"
        shutil.copy(obj, backup)
        try:
            obj.write_text("{ not valid json")
            ctx = loop.build_context(self.UNIT, self.SYM)
            self.assertNotIn("Traceback", ctx,
                             "broken objdiff.json leaked a traceback")
            self.assertIn("XREF SUMMARY", ctx,
                          "xrefs dropped when disasm failed")
            self.assertIn("SIMILAR TWINS", ctx,
                          "twins dropped when disasm failed")
            self.assertIn("disasm unavailable", ctx.lower())
        finally:
            shutil.copy(backup, obj)


if __name__ == "__main__":
    unittest.main()
