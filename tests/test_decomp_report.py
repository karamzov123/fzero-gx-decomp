import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "tools" / "decomp_report.py"

# objdiff.report.Measures, protos/report.proto (report version 2).
MEASURE_FIELDS = {
    "fuzzy_match_percent", "total_code", "matched_code", "matched_code_percent",
    "total_data", "matched_data", "matched_data_percent", "total_functions",
    "matched_functions", "matched_functions_percent", "complete_code",
    "complete_code_percent", "complete_data", "complete_data_percent",
    "total_units", "complete_units",
}


class DecompReportTest(unittest.TestCase):
    def test_section_annotations_do_not_hide_assembly(self):
        import importlib.util
        sys.path.insert(0, str(ROOT / "tools"))
        spec = importlib.util.spec_from_file_location("report_annotation_test", SCRIPT)
        assert spec is not None and spec.loader is not None
        report_module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(report_module)
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "test.c"
            path.write_text('asm __declspec(section ".init") void whole(void) { blr }\n'
                            '__declspec(section ".init") void wrapper(void) { asm { blr } }\n'
                            '__declspec(section ".init") int pure(void) { return 1; }\n')
            c_defs, asm, wrappers, hybrids = report_module.source_asm_forms(path)
            self.assertIn("whole", asm)
            self.assertIn("wrapper", wrappers)
            self.assertEqual(c_defs - asm - wrappers - hybrids, {"pure"})

    def test_adds_mission_categories_without_changing_diagnostic_measures(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "src").mkdir()
            (root / "src/a.c").write_text(
                "void exact_c(void) {}\n"
                "asm void hand_asm(void) { }\n"
                "void partial(void) {}\n"
            )
            for path in (root / "orig/GFZE01/sys/main.dol", root / "build/GFZE01/main.dol"):
                path.parent.mkdir(parents=True, exist_ok=True)
                dol = bytearray(0x110)
                dol[0x1c:0x20] = (0x100).to_bytes(4, "big")
                dol[0xac:0xb0] = (16).to_bytes(4, "big")
                dol[0xd8:0xdc] = (0x8000).to_bytes(4, "big")
                dol[0xdc:0xe0] = (32).to_bytes(4, "big")
                dol[0x100:0x110] = bytes(range(16))
                if path.parts[-3:] == ("build", "GFZE01", "main.dol"):
                    dol[0x100] = 255
                path.write_bytes(dol)
            report = {
                "version": 2,
                "measures": {
                    "total_code": "20", "matched_code": "15",
                    "matched_code_percent": 75.0,
                    "total_functions": 3, "matched_functions": 2,
                    "matched_functions_percent": 66.0,
                    "complete_code": "10", "complete_code_percent": 50.0,
                    "total_data": "1000",
                    "total_units": 1, "complete_units": 0,
                },
                "units": [{
                    "name": "main/a",
                    "measures": {},
                    "functions": [
                        {"name": "exact_c", "size": "4", "fuzzy_match_percent": 100.0},
                        {"name": "hand_asm", "size": "8", "fuzzy_match_percent": 100.0},
                        {"name": "partial", "size": "8", "fuzzy_match_percent": 50.0},
                    ],
                    "sections": [{"name": ".data", "size": "16", "fuzzy_match_percent": 100.0}],
                    "metadata": {"source_path": "src/a.c"},
                }],
                "categories": [],
            }
            src = root / "report.json"
            src.write_text(json.dumps(report))
            out = root / "out.json"
            result = subprocess.run(
                [sys.executable, str(SCRIPT), "--report", str(src), "--root", str(root), "--out", str(out)],
                text=True, capture_output=True,
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            got = json.loads(out.read_text())
            self.assertEqual(got["measures"]["matched_code_percent"], 20.0)
            self.assertEqual(got["measures"]["total_functions"], 3)
            cats = {c["id"]: c for c in got["categories"]}
            self.assertEqual(cats["natural-c"]["measures"]["total_functions"], 3)
            self.assertEqual(cats["natural-c"]["measures"]["matched_functions"], 1)
            self.assertEqual(cats["natural-c"]["measures"]["total_code"], "20")
            self.assertEqual(cats["natural-c"]["measures"]["complete_code"], "4")
            self.assertEqual(cats["natural-c"]["measures"]["complete_data"], "16")
            self.assertEqual(cats["natural-c"]["measures"]["complete_data_percent"], 1.6)
            self.assertEqual(cats["natural-c"]["measures"]["total_units"], 1)
            # The fixture's single unit contains `partial` at 50 %, so the unit
            # is NOT complete. This asserted 100.0 while complete_units was
            # (wrongly) the matched-FUNCTION count; in production that published
            # complete_units=285 against total_units=215 -> 132.5581 %.
            self.assertEqual(cats["natural-c"]["measures"]["complete_units"], 0)
            # Invariant that the old behaviour violated.
            # `diagnostic` is a passthrough of upstream objdiff measures and
            # need not carry these keys; the generated categories must.
            for name in ("natural-c", "c-expressed"):
                m = cats[name]["measures"]
                self.assertLessEqual(m["complete_units"], m["total_units"])
            self.assertEqual(cats["c-expressed"]["measures"]["matched_functions"], 1)
            self.assertEqual(cats["diagnostic"]["measures"], report["measures"])
            self.assertEqual(cats["diagnostic"]["measures"]["total_data"], "1000")
            self.assertEqual(got["measures"]["total_data"], "1000")
            self.assertEqual(got["measures"]["matched_data"], "16")
            self.assertEqual(got["measures"]["matched_data_percent"], 1.6)

            # Every Measures object decomp.dev will parse must contain ONLY
            # fields from the objdiff v2 schema. pbjson's generated
            # deserializer rejects unknown fields outright, so one stray key
            # makes the whole report unparseable and decomp.dev silently keeps
            # serving the last report it could read. `complete_units_percent`
            # did exactly that from 2026-08-26 to 2026-09-06.
            everything = [got["measures"]] + [c["measures"] for c in got["categories"]]
            everything += [u["measures"] for u in got["units"] if "measures" in u]
            for m in everything:
                self.assertEqual(
                    sorted(set(m) - MEASURE_FIELDS), [],
                    "measures carries fields outside the objdiff v2 schema",
                )

    def test_a_unit_with_asm_bodies_left_is_not_a_complete_unit(self):
        """complete_units must not count a unit that is still mostly assembly.

        The eligible-functions-only rule scored 139 of 215 units complete on a
        binary that was 13.3 % decompiled, because a unit whose single C
        function matched counted as finished while twenty asm bodies sat next
        to it. A unit is complete only when nothing in it is still asm.
        """
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "src").mkdir()
            # Every eligible function matches, but an asm body remains.
            (root / "src/mixed.c").write_text(
                "void done(void) {}\nasm void still_asm(void) { }\n")
            # Fully converted: no asm body left.
            (root / "src/pure.c").write_text("void done2(void) {}\n")
            report = {
                "version": 2,
                "measures": {
                    "total_code": "12", "total_functions": 3,
                    "total_data": "0", "total_units": 2, "complete_units": 0,
                },
                "units": [
                    {"name": "main/mixed", "measures": {}, "sections": [],
                     "functions": [
                         {"name": "done", "size": "4", "fuzzy_match_percent": 100.0},
                         {"name": "still_asm", "size": "4", "fuzzy_match_percent": 100.0},
                     ],
                     "metadata": {"source_path": "src/mixed.c"}},
                    {"name": "main/pure", "measures": {}, "sections": [],
                     "functions": [
                         {"name": "done2", "size": "4", "fuzzy_match_percent": 100.0},
                     ],
                     "metadata": {"source_path": "src/pure.c"}},
                ],
                "categories": [],
            }
            src = root / "report.json"
            src.write_text(json.dumps(report))
            out = root / "out.json"
            result = subprocess.run(
                [sys.executable, str(SCRIPT), "--report", str(src), "--root", str(root), "--out", str(out)],
                text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            cats = {c["id"]: c for c in json.loads(out.read_text())["categories"]}
            # main/pure only. main/mixed still has an asm body.
            self.assertEqual(cats["natural-c"]["measures"]["complete_units"], 1)
            self.assertEqual(cats["c-expressed"]["measures"]["complete_units"], 1)

    def test_a_unit_with_no_source_file_is_never_complete(self):
        """No source_path means nothing was converted; it cannot be complete."""
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            report = {
                "version": 2,
                "measures": {"total_code": "4", "total_functions": 1,
                             "total_data": "0", "total_units": 1, "complete_units": 0},
                "units": [{"name": "main/orphan", "measures": {}, "sections": [],
                           "functions": [{"name": "f", "size": "4", "fuzzy_match_percent": 100.0}],
                           "metadata": {}}],
                "categories": [],
            }
            src = root / "report.json"
            src.write_text(json.dumps(report))
            out = root / "out.json"
            result = subprocess.run(
                [sys.executable, str(SCRIPT), "--report", str(src), "--root", str(root), "--out", str(out)],
                text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            cats = {c["id"]: c for c in json.loads(out.read_text())["categories"]}
            self.assertEqual(cats["natural-c"]["measures"]["complete_units"], 0)

    def test_inline_asm_wrappers_and_hybrids_are_not_natural_c(self):
        """The public report must agree with natc_metrics' source-form policy.

        A C signature does not make an asm-only body natural C.  A hybrid has
        real C, but its bounded asm is an additive completion lane, not part
        of either natural-C or fuzzy C-expressed progress.
        """
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "src").mkdir()
            (root / "src/forms.c").write_text(
                "void pure(void) { return; }\n"
                "void wrapper(void) { asm { blr } }\n"
                "int hybrid(void) { int x = 1; asm { mr r3, r3 } return x; }\n"
            )
            report = {
                "version": 2,
                "measures": {
                    "total_code": "20", "total_functions": 5,
                    "total_data": "0", "total_units": 1, "complete_units": 0,
                },
                "units": [{
                    "name": "main/forms", "measures": {}, "sections": [],
                    "functions": [
                        {"name": "pure", "size": "4", "fuzzy_match_percent": 100.0},
                        {"name": "wrapper", "size": "4", "fuzzy_match_percent": 100.0},
                        {"name": "hybrid", "size": "4", "fuzzy_match_percent": 100.0},
                        # These target names are absent from the source (the
                        # real tree has renamed/asm-only symbols like these).
                        {"name": "renamed_target", "size": "4", "fuzzy_match_percent": 100.0},
                        {"name": "pad_00_vector", "size": "4", "fuzzy_match_percent": 100.0},
                    ],
                    "metadata": {"source_path": "src/forms.c"},
                }],
                "categories": [],
            }
            src = root / "report.json"
            src.write_text(json.dumps(report))
            out = root / "out.json"
            result = subprocess.run(
                [sys.executable, str(SCRIPT), "--report", str(src),
                 "--root", str(root), "--out", str(out)],
                text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            cats = {c["id"]: c for c in json.loads(out.read_text())["categories"]}
            for category in ("natural-c", "c-expressed"):
                measures = cats[category]["measures"]
                self.assertEqual(measures["matched_functions"], 1)
                self.assertEqual(measures["matched_code"], "4")
                self.assertEqual(measures["complete_units"], 0)

    def test_missing_source_fails_closed(self):
        """A target-only name must never be promoted when source is absent."""
        import importlib.util
        spec = importlib.util.spec_from_file_location("decomp_report", SCRIPT)
        mod = importlib.util.module_from_spec(spec)
        assert spec and spec.loader
        spec.loader.exec_module(mod)
        with tempfile.TemporaryDirectory() as tmp:
            with self.assertRaises(SystemExit):
                mod.source_asm_forms(Path(tmp) / "missing.c")

    def test_keeps_objdiff_progress_categories_scoped_to_the_mission(self):
        """game/sdk must survive, measured the way the headline is measured.

        configure.py tags units with progress categories, and decomp.dev uses
        the category id to filter the unit list. Replacing report["categories"]
        wholesale threw those ids away. Re-emitting them with objdiff's own
        fuzzy numbers would be worse: a "game 90.8 %" row beside a "natural-c
        13.3 %" headline is the same binary counted two different ways.
        """
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "src").mkdir()
            (root / "src/g.c").write_text("void g_done(void) {}\nasm void g_asm(void) { }\n")
            (root / "src/s.c").write_text("void s_todo(void) {}\n")
            report = {
                "version": 2,
                "measures": {"total_code": "12", "total_functions": 3,
                             "total_data": "0", "total_units": 2, "complete_units": 0},
                "units": [
                    {"name": "main/g", "measures": {}, "sections": [],
                     "functions": [
                         {"name": "g_done", "size": "4", "fuzzy_match_percent": 100.0},
                         {"name": "g_asm", "size": "4", "fuzzy_match_percent": 100.0}],
                     "metadata": {"source_path": "src/g.c", "progress_categories": ["game"]}},
                    {"name": "main/s", "measures": {}, "sections": [],
                     "functions": [{"name": "s_todo", "size": "4", "fuzzy_match_percent": 0.0}],
                     "metadata": {"source_path": "src/s.c", "progress_categories": ["sdk"]}},
                ],
                "categories": [
                    {"id": "game", "name": "Game",
                     "measures": {"total_code": "8", "total_functions": 2, "total_units": 1}},
                    {"id": "sdk", "name": "SDK",
                     "measures": {"total_code": "4", "total_functions": 1, "total_units": 1}},
                ],
            }
            src = root / "report.json"
            src.write_text(json.dumps(report))
            out = root / "out.json"
            result = subprocess.run(
                [sys.executable, str(SCRIPT), "--report", str(src), "--root", str(root), "--out", str(out)],
                text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            cats = {c["id"]: c for c in json.loads(out.read_text())["categories"]}
            self.assertIn("game", cats)
            self.assertIn("sdk", cats)
            # Denominators are objdiff's own for that category -- every
            # function in it, asm included -- not the whole binary and not
            # only the eligible ones. "1 of the 2 functions in game code is
            # exact natural C" is the honest reading.
            self.assertEqual(cats["game"]["measures"]["total_functions"], 2)
            self.assertEqual(cats["game"]["measures"]["matched_functions"], 1)
            self.assertEqual(cats["game"]["measures"]["total_code"], "8")
            self.assertEqual(cats["sdk"]["measures"]["total_functions"], 1)
            self.assertEqual(cats["sdk"]["measures"]["matched_functions"], 0)
            # main/g still has an asm body, so it is not a complete unit.
            self.assertEqual(cats["game"]["measures"]["complete_units"], 0)
            for c in cats.values():
                self.assertEqual(sorted(set(c["measures"]) - MEASURE_FIELDS), [])

    def test_publishes_dol_and_rel_module_metrics(self):
        """Module rows make the whole-game denominator auditable."""
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "src").mkdir()
            (root / "src/dol.c").write_text("void dol_done(void) {}\n")
            (root / "src/rel.c").write_text("void rel_done(void) {}\n")
            report = {
                "version": 2,
                "measures": {"total_code": "12", "total_functions": 2,
                             "total_data": "0", "total_units": 2},
                "units": [
                    {"name": "main/dol", "measures": {"total_code": "8",
                     "total_functions": 1, "total_units": 1}, "sections": [],
                     "functions": [{"name": "dol_done", "size": "8",
                                    "fuzzy_match_percent": 100.0}],
                     "metadata": {"source_path": "src/dol.c", "module_name": "main"}},
                    {"name": "sample/rel", "measures": {"total_code": "4",
                     "total_functions": 1, "total_units": 1}, "sections": [],
                     "functions": [{"name": "rel_done", "size": "4",
                                    "fuzzy_match_percent": 0.0}],
                     "metadata": {"source_path": "src/rel.c", "module_name": "sample"}},
                ],
                "categories": [],
            }
            src = root / "report.json"
            src.write_text(json.dumps(report))
            out = root / "out.json"
            result = subprocess.run(
                [sys.executable, str(SCRIPT), "--report", str(src),
                 "--root", str(root), "--out", str(out)],
                text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            cats = {c["id"]: c for c in json.loads(out.read_text())["categories"]}
            self.assertEqual(cats["module-main"]["measures"]["total_code"], "8")
            self.assertEqual(cats["module-main"]["measures"]["matched_code"], "8")
            self.assertEqual(cats["module-sample"]["measures"]["total_code"], "4")
            self.assertEqual(cats["module-sample"]["measures"]["matched_code"], "0")
            self.assertEqual(json.loads(out.read_text())["measures"]["total_code"], "12")

    def test_refuses_to_write_a_report_decomp_dev_cannot_parse(self):
        """The guard must fail the build, not ship an unreadable report."""
        import importlib.util
        spec = importlib.util.spec_from_file_location("decomp_report", SCRIPT)
        mod = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(mod)
        with self.assertRaises(SystemExit):
            mod.validate_schema({
                "measures": {"total_units": 1, "complete_units_percent": 100.0},
                "categories": [],
                "units": [],
            })


if __name__ == "__main__":
    unittest.main()
