import sqlite3
from pathlib import Path
import sys
sys.path.insert(0, str(Path(__file__).parents[1] / 'tools'))
from natc_hypothesis_ledger import Ledger


def test_typed_trace_import_and_evaluation_rows(tmp_path):
    ledger = Ledger(tmp_path / 'ledger.sqlite')
    assert ledger.record_trace_import('trace:r1', hypothesis_id='h1', run_id='r1',
                                     artifact_sha256='a' * 64, manifest_sha256='b' * 64,
                                     record_count=2)
    assert ledger.record_evaluation('evaluation:c1', hypothesis_id='h1', candidate_id='c1',
                                    score=100, accepted=True, reason='accepted')
    rows = ledger.db.execute('select run_id,artifact_sha256,record_count from trace_imports').fetchall()
    assert rows == [('r1', 'a' * 64, 2)]
    ledger.close()


def test_migrates_old_four_column_tables(tmp_path):
    import sqlite3
    path = tmp_path / 'old.sqlite'
    db = sqlite3.connect(path)
    for table in ('candidates', 'evaluations', 'pin_evidence', 'trace_imports'):
        db.execute(f'create table {table} (id text primary key, schema_version integer, hypothesis_id text, payload text not null)')
    db.commit(); db.close()
    ledger = Ledger(path)
    assert ledger.record_trace_import('trace:r2', hypothesis_id='h2', run_id='r2',
                                     artifact_sha256='c' * 64, record_count=1)
    assert ledger.db.execute('select run_id,record_count from trace_imports').fetchone() == ('r2', 1)
    ledger.close()
