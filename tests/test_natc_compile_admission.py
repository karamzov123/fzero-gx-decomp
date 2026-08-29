import importlib.util
import sqlite3
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
SPEC = importlib.util.spec_from_file_location("natc_compile_admission", ROOT / "tools" / "natc_compile.py")
assert SPEC and SPEC.loader
natc_compile = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(natc_compile)


class AdmissionTests(unittest.TestCase):
    def test_exact_candidate_context_is_blocked(self):
        with tempfile.TemporaryDirectory() as td:
            db_path = Path(td) / "runs.sqlite"
            con = sqlite3.connect(db_path)
            con.execute("""create table attempts(
                id integer primary key, unit text, symbol text, src_sha text,
                compiler text, ctx_sha text, kind text)""")
            con.execute("insert into attempts(unit,symbol,src_sha,compiler,ctx_sha,kind) values(?,?,?,?,?,?)",
                        ("u", "f", "sha", "1.2.5n", "ctx", "attempt"))
            con.commit(); con.close()
            old = natc_compile.RUNS_DB
            setattr(natc_compile, "RUNS_DB", str(db_path))
            try:
                self.assertTrue(natc_compile.identical_attempt_exists("u", "f", "sha", "1.2.5n", "ctx"))
                self.assertFalse(natc_compile.identical_attempt_exists("u", "f", "new", "1.2.5n", "ctx"))
                self.assertFalse(natc_compile.identical_attempt_exists("u", "f", "sha", "1.3", "ctx"))
                self.assertFalse(natc_compile.identical_attempt_exists("u", "f", "sha", "1.2.5n", "newctx"))
            finally:
                setattr(natc_compile, "RUNS_DB", old)


if __name__ == "__main__":
    unittest.main()
