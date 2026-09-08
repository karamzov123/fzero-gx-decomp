import json
import tempfile
import unittest
from pathlib import Path

from tools.game_inventory import inventory_game


class GameInventoryTests(unittest.TestCase):
    def test_inventory_requires_the_game_rel(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "sys").mkdir()
            (root / "sys" / "main.dol").write_bytes(b"dol")

            report = inventory_game(root)

            self.assertFalse(report["complete"])
            self.assertIn("fze.sample.rel", report["missing_required"])
            self.assertEqual(len(report["missing_required"]), 16)

    def test_inventory_finds_rel_case_insensitively(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "sys").mkdir()
            (root / "files").mkdir()
            (root / "sys" / "main.dol").write_bytes(b"dol")
            for name in inventory_game.__globals__["REQUIRED"]:
                if name != "main.dol":
                    (root / "files" / name.upper()).write_bytes(b"rel")

            report = inventory_game(root)

            self.assertTrue(report["complete"])
            self.assertEqual(report["missing_required"], [])
            self.assertEqual(report["required"]["fze.sample.rel"]["path"], "files/FZE.SAMPLE.REL")
            self.assertEqual(report["required"]["fze.sample.rel"]["kind"], "rel")

    def test_inventory_is_json_serializable(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "sys").mkdir()
            (root / "sys" / "main.dol").write_bytes(b"dol")
            report = inventory_game(root)
            json.dumps(report)


if __name__ == "__main__":
    unittest.main()
