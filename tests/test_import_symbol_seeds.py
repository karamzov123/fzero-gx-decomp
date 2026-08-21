import csv
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "tools" / "import_symbol_seeds.py"


class ImportSymbolSeedsTest(unittest.TestCase):
    def test_applies_only_exact_main_dol_seed_and_is_idempotent(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp_path = Path(tmp)
            symbols = tmp_path / "symbols.txt"
            seeds = tmp_path / "seeds.csv"
            symbols.write_text(
                "fn_80008E84 = .text:0x80008E84; // type:function size:0x44\n"
                "fn_80008EC8 = .text:0x80008EC8; // type:function size:0x10\n"
            )
            with seeds.open("w", newline="") as f:
                writer = csv.writer(f)
                writer.writerow(["module", "address", "kind", "name", "provenance"])
                writer.writerow(["main.dol", "0x80008E84", "function", "OSSetCurrentHeap", "findings/30"])
                writer.writerow(["resident", "0x80235718", "function", "loadStage", "findings/30"])

            command = [
                sys.executable,
                str(SCRIPT),
                "--symbols",
                str(symbols),
                "--seeds",
                str(seeds),
                "--write",
            ]
            first = subprocess.run(command, text=True, capture_output=True)
            self.assertEqual(first.returncode, 0, first.stderr)
            self.assertIn("applied=1", first.stdout)
            self.assertIn("external=1", first.stdout)
            self.assertIn("OSSetCurrentHeap = .text:0x80008E84", symbols.read_text())
            self.assertNotIn("loadStage", symbols.read_text())

            second = subprocess.run(command, text=True, capture_output=True)
            self.assertEqual(second.returncode, 0, second.stderr)
            self.assertIn("applied=0", second.stdout)
            self.assertIn("already_named=1", second.stdout)

    def test_rejects_conflicting_existing_name(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp_path = Path(tmp)
            symbols = tmp_path / "symbols.txt"
            seeds = tmp_path / "seeds.csv"
            symbols.write_text(
                "KnownFunction = .text:0x80008E84; // type:function size:0x44\n"
            )
            seeds.write_text(
                "module,address,kind,name,provenance\n"
                "main.dol,0x80008E84,function,OSSetCurrentHeap,findings/30\n"
            )
            result = subprocess.run(
                [
                    sys.executable,
                    str(SCRIPT),
                    "--symbols",
                    str(symbols),
                    "--seeds",
                    str(seeds),
                    "--write",
                ],
                text=True,
                capture_output=True,
            )
            self.assertNotEqual(result.returncode, 0)
            self.assertIn("conflict", result.stderr.lower())
            self.assertIn("KnownFunction", symbols.read_text())


if __name__ == "__main__":
    unittest.main()
