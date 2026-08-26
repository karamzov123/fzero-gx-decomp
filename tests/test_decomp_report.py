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
            self.assertEqual(cats["c-expressed"]["measures"]["matched_functions"], 1)
            self.assertEqual(cats["diagnostic"]["measures"], report["measures"])
            self.assertEqual(cats["diagnostic"]["measures"]["total_data"], "1000")
            self.assertNotIn("total_data", got["measures"])


if __name__ == "__main__":
    unittest.main()
