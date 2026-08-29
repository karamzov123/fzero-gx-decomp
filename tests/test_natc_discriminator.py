"""Regression tests for object-scoped compiler pin experiments."""
import importlib.util
import sys
from pathlib import Path

TOOL = Path(__file__).parents[1] / "tools" / "natc_discriminator.py"
sys.path.insert(0, str(TOOL.parent))
SPEC = importlib.util.spec_from_file_location("natc_discriminator_test", TOOL)
assert SPEC and SPEC.loader
mod = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(mod)


def test_ambiguous_low_only_schema_has_no_scale_signal():
    side = {"symbols": [{"match_percent": 0.73756}, {"match_percent": 1.0}]}
    assert mod.match_scale(side) is None


def test_legacy_percent_schema_is_preserved_including_one_percent():
    side = {"symbols": [{"match_percent": 73.756}, {"match_percent": 1.0}]}
    scale = mod.match_scale(side)
    assert scale == 1.0
    assert mod.percent(73.756, scale) == 73.756
    assert not mod.is_exact(1.0, scale)
    assert mod.is_exact(100.0, scale)


def test_object_score_is_byte_weighted_over_paired_functions_only():
    left = {"symbols": [
        {"name": "A", "kind": "SYMBOL_FUNCTION", "size": "100"},
        {"name": "data", "kind": "SYMBOL_OBJECT", "size": "1000"},
        {"name": "B", "kind": "SYMBOL_FUNCTION", "size": "0x64"},
        {"name": "unknown", "kind": "SYMBOL_FUNCTION", "size": "0"},
    ]}
    right = {"symbols": [
        {"name": "A", "kind": "SYMBOL_FUNCTION", "match_percent": 100.0},
        {"name": "data", "kind": "SYMBOL_OBJECT", "match_percent": 0.0},
        {"name": "B", "kind": "SYMBOL_FUNCTION", "match_percent": 0.0},
        {"name": "unknown", "kind": "SYMBOL_FUNCTION", "match_percent": 100.0},
    ]}
    assert mod.score_function_pairs(left, right) == (1, 2, 50.0)


def test_mismatched_right_data_symbol_is_not_counted_as_function():
    left = {"symbols": [
        {"name": "A", "kind": "SYMBOL_FUNCTION", "size": "4"},
    ]}
    right = {"symbols": [
        {"name": "data", "kind": "SYMBOL_OBJECT", "match_percent": 100.0},
    ]}
    assert mod.score_function_pairs(left, right) == (0, 0, 0.0)


def test_winner_uses_similarity_when_exact_counts_tie():
    scores = {
        "1.2.5n": {"funcs_exact": 0, "text_pct": 55.267},
        "1.3": {"funcs_exact": 0, "text_pct": 73.756},
    }
    assert mod.choose_winner(scores, "1.2.5n") == ("1.3", 0)


def test_mixed_complete_unit_has_compiler_signal():
    text = "asm void Old(void) { nofralloc; blr }\nint New(void) { return 1; }\n"
    assert mod.has_natural_c_definition(text)


def test_asm_only_unit_has_no_compiler_signal():
    assert not mod.has_natural_c_definition("asm void Old(void) { nofralloc; blr }\n")
