import importlib.util
import sqlite3
import tempfile
import time
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("natc_rank_under_test", ROOT / "tools/natc_rank.py")
assert SPEC and SPEC.loader
natc_rank = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(natc_rank)


class LeaseSweepTests(unittest.TestCase):
    def test_sweep_reclaims_expired_and_keeps_one_newest_lease(self):
        with tempfile.TemporaryDirectory() as td:
            db = sqlite3.connect(Path(td) / "runs.sqlite")
            db.execute("""create table units(
                unit text primary key, status text, worker text, leased_at real,
                disposition text)""")
            now = time.time()
            db.executemany(
                "insert into units values(?,?,?,?,?)",
                [
                    ("old", "leased", "natc1", now - natc_rank.TTL - 1, None),
                    ("new", "leased", "natc1", now - 10, None),
                    ("other", "leased", "natc2", now - 10, None),
                    ("pending", "pending", None, None, None),
                ],
            )
            db.commit()

            result = natc_rank.sweep_leases(db)
            rows = {
                unit: (status, worker)
                for unit, status, worker in db.execute(
                    "select unit,status,worker from units"
                )
            }
            self.assertEqual(rows["old"], ("pending", None))
            self.assertEqual(rows["new"], ("leased", "natc1"))
            self.assertEqual(rows["other"], ("leased", "natc2"))
            self.assertEqual(result, {"expired": 1, "duplicates": 0})


if __name__ == "__main__":
    unittest.main()
