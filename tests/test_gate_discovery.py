"""Fixture tests for natc_gate recursive batch discovery (tooling fix 2026-08-26).

Regression: map_batch_units used a flat glob('*.c') and find_card_md used a
flat lookup, so batches that store candidates/CARD.md in a subdirectory
(e.g. `dvdfs/dvdfs.c` + `dvdfs/CARD.md`) were silently refused with
'no .c candidates' / 'CARD.md contains no provenance record'. Discovery must
recurse. This is a discovery fix only -- it MUST NOT alter any refusal branch;
run `tools/natc_gate.py --self-test` to confirm the refusal paths are intact.
"""
import importlib.util
import textwrap
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location(
    "natc_gate_under_test", REPO / "tools/natc_gate.py")
assert SPEC and SPEC.loader
g = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(g)

# Real src filenames that exist in the tree, so the unique src/**/<name> map
# resolves instead of raising "N src matches".
SRC_DVDFS = "src/dolphin/dvd/dvdfs.c"
SRC_DVDLOW = "src/dolphin/dvd/dvdlow.c"


def _mk(batch: Path, layout, card_text):
    for rel, text in layout.items():
        p = batch / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text)
    (batch / "CARD.md").write_text(textwrap.dedent(card_text))


class GateDiscoveryTests(unittest.TestCase):
    def test_flat_batch_still_maps(self):
        b = Path(__file__).resolve().parent / "_fx" / "flat"
        _mk(b, {"dvdfs.c": "void fn_dvdfs(void) {}\n"},
            "fn_dvdfs — provenance: original\n")
        pairs = g.map_batch_units(b)
        self.assertEqual(len(pairs), 1)
        self.assertEqual(pairs[0][0].name, "dvdfs.c")

    def test_nested_candidate_is_found(self):
        b = Path(__file__).resolve().parent / "_fx" / "nested"
        # Candidate nested under dvdfs/, with a // dest: routing header.
        _mk(b, {"dvdfs/dvdfs.c": "// dest: src/dolphin/dvd/dvdfs.c\n"
                                 "void fn_dvdfs(void) {}\n"},
            "fn_dvdfs — provenance: original\n")
        pairs = g.map_batch_units(b)
        self.assertEqual(len(pairs), 1)
        # Previously flat glob returned [] -> 'no .c candidates' refusal.
        self.assertEqual(pairs[0][0].name, "dvdfs.c")
        self.assertEqual(str(pairs[0][1]), str(REPO / SRC_DVDFS))

    def test_find_card_md_recurses_to_nested(self):
        b = Path(__file__).resolve().parent / "_fx" / "nested_card"
        _mk(b, {"dvdfs/dvdfs.c": "// dest: src/dolphin/dvd/dvdfs.c\n"
                                 "void fn_dvdfs(void) {}\n",
                "dvdfs/CARD.md": "# nested card\n- `fn_dvdfs` -- // provenance: original\n"},
            "# root card, no provenance\n")
        card = g.find_card_md(b)
        self.assertIsNotNone(card)
        # A provenance-bearing card is preferred even if a root card exists.
        self.assertIn("dvdfs", str(card))
        self.assertTrue(card.name == "CARD.md")

    def test_nested_candidate_maps_to_src_by_name(self):
        b = Path(__file__).resolve().parent / "_fx" / "nested_map"
        # No // dest: -> must resolve via unique src/**/<name> (real name).
        _mk(b, {"dvdlow/dvdlow.c": "void fn_dvdlow(void) {}\n"},
            "fn_dvdlow — provenance: original\n")
        pairs = g.map_batch_units(b)
        self.assertEqual(len(pairs), 1)
        self.assertEqual(str(pairs[0][1]), str(REPO / SRC_DVDLOW))


if __name__ == "__main__":
    unittest.main()
