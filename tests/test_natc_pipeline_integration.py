import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))

from natc_hypothesis import build_payload
from natc_loop import classify_objdiff


def _symbol(name, text, score):
    return {"name": name, "size": 4, "match_percent": score,
            "instruction_rows": [{"instruction": {"formatted": text}}]}


def test_hypothesis_payload_embeds_versioned_oracle():
    xref = {"definition": {"object": "build/x.o", "section": ".sbss",
                           "size": 4, "bind": 1},
            "reloc_histogram": {"R_PPC_EMB_SDA21": 1}}
    result = build_payload("u", "s", {"references": []}, xref, [])
    assert result["declaration_oracle"]["schema_version"] == 1
    assert result["declaration_oracle"]["constraints"]["writable"] is True


def test_loop_uses_rich_real_schema_and_tu_safety():
    diff = {
        "left": {"symbols": [_symbol("target", "li r3,1", 90.0),
                              _symbol("exact_sibling", "blr", 100.0)]},
        "right": {"symbols": [_symbol("target", "li r3,2", 50.0),
                               _symbol("exact_sibling", "nop", 80.0)]},
    }
    result = classify_objdiff(diff, "target")
    assert result["rich"]["first_divergence"] == 0
    assert result["classification"] != "exact"
    assert result["tu_safe"] is False
    assert "exact_sibling" in result["tu"]["exact_sibling_regressions"]
