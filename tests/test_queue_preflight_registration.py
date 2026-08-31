"""The registration-time preflight gate (2026-08-28).

218 batches were registered and then refused — each costing a 30 s serialised
gate build to learn what a 10 ms text check knew. register() must refuse such
batches at registration with the true preflight reason, and must NOT run
preflight for already-known batch ids (the recovery/reconciliation path may
legitimately re-register retired directories).
"""
import sqlite3
import subprocess

import pytest

import natc_submission_queue as q


@pytest.fixture()
def mem_db():
    c = sqlite3.connect(":memory:")
    c.row_factory = sqlite3.Row
    c.executescript("""
    CREATE TABLE batches (batch_id TEXT PRIMARY KEY, worker TEXT NOT NULL,
      batch_path TEXT NOT NULL, content_sha256 TEXT NOT NULL, state TEXT NOT NULL,
      claim_token TEXT, claim_until REAL, result_json TEXT, error TEXT,
      registered_at REAL NOT NULL, updated_at REAL NOT NULL);
    """)
    yield c
    c.close()


def _mapped_batch(tmp_path):
    """A batch that passes admission but fails preflight's cheapest check:
    the candidate cannot be mapped to a src file (no `// dest:` header)."""
    b = tmp_path / "bad"
    b.mkdir()
    (b / "CARD.md").write_text("# probe\n// provenance: test fn_80000000\n")
    (b / "u.c").write_text("int fn_80000000(void){ return 1; }\n")
    return b


def test_refused_at_registration_with_true_reason(tmp_path, mem_db, monkeypatch):
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT", "1")
    with pytest.raises(ValueError) as ei:
        q.register(mem_db, "w/bad", "w", _mapped_batch(tmp_path))
    assert "refused at registration" in str(ei.value)
    assert "preflight" in str(ei.value)
    # nothing may have been inserted
    assert mem_db.execute("select count(*) from batches").fetchone()[0] == 0


def test_opt_out_registers(monkeypatch, tmp_path, mem_db):
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT", "0")
    row = q.register(mem_db, "w/bad", "w", _mapped_batch(tmp_path))
    assert row["state"] == "ready"


def test_preflight_timeout_is_not_admitted(monkeypatch, tmp_path, mem_db):
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT", "1")
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT_STRICT", "1")

    def timeout(*args, **kwargs):
        raise subprocess.TimeoutExpired(cmd=args[0], timeout=kwargs["timeout"])

    monkeypatch.setattr(q.subprocess, "run", timeout)
    with pytest.raises(ValueError, match="preflight unavailable"):
        q.register(mem_db, "w/timeout", "w", _mapped_batch(tmp_path))
    assert mem_db.execute("select count(*) from batches").fetchone()[0] == 0


def test_known_id_skips_preflight(monkeypatch, tmp_path, mem_db):
    """Re-registration of a known id is the recovery path; preflight must not
    run even with the gate enabled."""
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT", "1")
    b = _mapped_batch(tmp_path)
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT", "0")
    q.register(mem_db, "w/bad", "w", b)
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT", "1")
    row = q.register(mem_db, "w/bad", "w", b)
    assert row["state"] == "ready"
