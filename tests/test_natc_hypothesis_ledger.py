import json
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


def test_persists_first_divergence_bound_to_candidate_and_run(tmp_path):
    """The differential evaluator must be able to record the first retail-vs-
    candidate divergence without any runtime bundle living in the ledger."""
    ledger = Ledger(tmp_path / 'ledger.sqlite')
    assert ledger.record_divergence(
        'div:d1', hypothesis_id='h1', candidate_id='c1', run_id='r1',
        frame=128, phase='race', address='0x80177A70', kind='struct-offset-0x10',
        payload={'expected': '0x08000000', 'got': '0x00000000'})
    rows = ledger.db.execute(
        'select hypothesis_id,candidate_id,run_id,frame,phase,address,kind '
        'from runtime_divergences').fetchall()
    assert rows == [('h1', 'c1', 'r1', 128, 'race', '0x80177A70', 'struct-offset-0x10')]
    payload = json.loads(ledger.db.execute(
        'select payload from runtime_divergences where id=?', ('div:d1',)).fetchone()[0])
    assert payload['expected'] == '0x08000000' and payload['got'] == '0x00000000'
    ledger.close()


def test_divergence_matches_imported_run_across_the_same_hypothesis(tmp_path):
    """A complete differential path: import a runtime trace for a hypothesis,
    then record that its candidate's first divergence points at the run."""
    import hashlib
    ledger = Ledger(tmp_path / 'ledger.sqlite')
    assert ledger.record_trace_import('trace:h1c1', hypothesis_id='h1',
                                      run_id='r1',
                                      artifact_sha256='a' * 64,
                                      manifest_sha256='b' * 64, record_count=3)
    assert ledger.record_divergence('div:h1c1', hypothesis_id='h1', candidate_id='c1',
                                    run_id='r1', frame=7, kind='counter-mismatch')
    divergence = ledger.db.execute(
        'select run_id,candidate_id from runtime_divergences').fetchone()
    assert divergence == ('r1', 'c1')
    ledger.close()
