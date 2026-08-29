import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parents[1] / 'tools'))
from natc_discriminator import accept_pin_evidence


def rows(a=10, b=8):
    return {'mwcc-1.2.5n': {'funcs_exact': a, 'text_pct': 99.0, 'executable_id': 'sha:a'},
            'mwcc-2': {'funcs_exact': b, 'text_pct': 98.0, 'executable_id': 'sha:b'}}


def test_pin_requires_two_confirmations_and_identity():
    result = accept_pin_evidence(rows(), current='mwcc-2', confirmations=['mwcc-1.2.5n'])
    assert not result['accepted']
    assert result['reason'] == 'repeated-confirmation-required'
    assert result['writes'] == []


def test_pin_accepts_repeatable_clear_signal_without_writes():
    result = accept_pin_evidence(rows(), current='mwcc-2', confirmations=['mwcc-1.2.5n'] * 2)
    assert result['accepted']
    assert result['winner'] == 'mwcc-1.2.5n'
    assert result['executable_id'] == 'sha:a'
    assert result['writes'] == []


def test_pin_rejects_tie_no_signal_and_narrow_margin():
    tied = rows(10, 10)
    tied['mwcc-2']['text_pct'] = 99.0
    assert accept_pin_evidence(tied, current='mwcc-2', confirmations=['mwcc-1.2.5n'] * 2)['reason'] == 'tie'
    assert accept_pin_evidence({}, current='mwcc-2')['reason'] == 'no-signal'
    assert accept_pin_evidence(rows(10, 9), current='mwcc-2', confirmations=['mwcc-1.2.5n'] * 2, min_margin=2)['reason'] == 'min-margin'


def test_pin_rejects_missing_executable_identity():
    data = {'mwcc': {'funcs_exact': 10, 'text_pct': 99.0}}
    result = accept_pin_evidence(data, current='mwcc', confirmations=['mwcc'] * 2)
    assert not result['accepted']
    assert result['reason'] == 'no-signal'
