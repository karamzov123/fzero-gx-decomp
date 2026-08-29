import os

import pytest


@pytest.fixture(autouse=True)
def _no_registration_preflight(monkeypatch):
    """Queue-mechanics tests use synthetic batches that intentionally fail
    the gate's content checks; registration-time preflight would refuse them
    before the behaviour under test runs. Tests that exercise the preflight
    registration gate itself re-enable it explicitly."""
    monkeypatch.setenv("NATC_QUEUE_PREFLIGHT", "0")
    yield
