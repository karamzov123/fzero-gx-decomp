import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "tools" / "decomp_report.py"


class DecompReportTest(unittest.TestCase):
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
            self.assertEqual(cats["natural-c"]["measures"]["complete_units_percent"], 0.0)
            # Invariant that the old behaviour violated.
            # `diagnostic` is a passthrough of upstream objdiff measures and
            # need not carry these keys; the generated categories must.
            for name in ("natural-c", "c-expressed"):
                m = cats[name]["measures"]
                self.assertLessEqual(m["complete_units"], m["total_units"])
                self.assertLessEqual(m["complete_units_percent"], 100.0)
            self.assertEqual(cats["c-expressed"]["measures"]["matched_functions"], 1)
            self.assertEqual(cats["diagnostic"]["measures"], report["measures"])
            self.assertEqual(cats["diagnostic"]["measures"]["total_data"], "1000")
            self.assertEqual(got["measures"]["total_data"], "1000")
            self.assertEqual(got["measures"]["matched_data"], "16")
            self.assertEqual(got["measures"]["matched_data_percent"], 1.6)


if __name__ == "__main__":
    unittest.main()
