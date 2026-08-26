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


def _fixture(td):
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
    return db


def _rows(db):
    return {unit: (status, worker) for unit, status, worker
            in db.execute("select unit,status,worker from units")}


class LeaseSweepTests(unittest.TestCase):
    def test_sweep_reclaims_expired_only(self):
        """A live lease is never touched, however many a worker holds.

        The sweep used to also release every lease but the newest per worker,
        once a minute. That took units away from workers mid-conversion and,
        worse, from units whose batch was already queued — after which the
        gate's T24 check refused finished work for a bookkeeping reason.
        `natc1` holds two live leases here and must still hold both.
        """
        with tempfile.TemporaryDirectory() as td:
            db = _fixture(td)
            result = natc_rank.sweep_leases(db, protected=set())
            rows = _rows(db)
            self.assertEqual(rows["old"], ("pending", None))
            self.assertEqual(rows["new"], ("leased", "natc1"))
            self.assertEqual(rows["other"], ("leased", "natc2"))
            self.assertEqual(result,
                             {"expired": 1, "duplicates": 0, "protected": 0})

    def test_expired_lease_is_kept_when_its_batch_is_queued(self):
        """An expired lease whose work is already submitted stays put.

        Reclaiming it would hand the unit to another worker while a finished
        candidate for it sits in the integrator's queue, and the gate would
        then refuse that candidate.
        """
        with tempfile.TemporaryDirectory() as td:
            db = _fixture(td)
            result = natc_rank.sweep_leases(db, protected={"old"})
            rows = _rows(db)
            self.assertEqual(rows["old"], ("leased", "natc1"))
            self.assertEqual(result,
                             {"expired": 0, "duplicates": 0, "protected": 1})

    def test_pending_submission_scan_does_not_leak_handles(self):
        """It reads the live tree; it must not hold it open."""
        import warnings
        with warnings.catch_warnings():
            warnings.simplefilter("error", ResourceWarning)
            natc_rank.units_with_pending_submission()


if __name__ == "__main__":
    unittest.main()
