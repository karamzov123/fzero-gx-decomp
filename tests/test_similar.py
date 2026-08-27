import importlib.util
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))
SPEC = importlib.util.spec_from_file_location(
    "similar_under_test", ROOT / "tools/similar.py")
assert SPEC and SPEC.loader
sim = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(sim)


class SimilarCorpusTests(unittest.TestCase):
    """Contract tests for similar.py (item 2).

    The corpus is disassembled once from orig/GFZE01/sys/main.dol via the
    real baseline.json, normalised, and cached by content hash under
    [local cache]/slice/. These double as a regression guard for the
    Jaccard neighbours the fleet retrieves as 'accepted twins'.
    """

    @classmethod
    def setUpClass(cls):
        cls.corpus = sim.disasm_all()

    def test_corpus_covers_full_function_set(self):
        # Spec item 2: over the 2,235 functions in this DOL.
        self.assertGreaterEqual(len(self.corpus), 2235,
                                "opcode-similarity must cover the whole corpus")

    def test_every_record_has_unit_size_and_grams(self):
        for _name, rec in self.corpus.items():
            self.assertIn("unit", rec)
            self.assertIn("size", rec)
            self.assertIn("grams", rec)
            self.assertIsInstance(rec["grams"], list)


class SimilarNeighborTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.corpus = sim.disasm_all()
        cls.probe = "GXSetMisc" if "GXSetMisc" in cls.corpus \
            else next(iter(cls.corpus))

    def test_known_twins_rank_high(self):
        # CARDRead/CARDWrite are near-identical twins (board: dolphin/card 77%).
        tw = sim.neighbors(self.corpus, "CARDRead", k=1)
        self.assertTrue(tw, "CARDRead must have at least one neighbor")
        self.assertGreater(tw[0][0], 0.5, f"twin retrieval broken: {tw}")

    def test_k_bounds(self):
        hits = sim.neighbors(self.corpus, self.probe, k=5)
        self.assertLessEqual(len(hits), 5)
        self.assertGreaterEqual(len(hits), 1)

    def test_jaccard_sorted_descending(self):
        hits = sim.neighbors(self.corpus, self.probe, k=5)
        scores = [j for j, *_ in hits]
        self.assertEqual(scores, sorted(scores, reverse=True))

    def test_self_excluded_by_default(self):
        hits = sim.neighbors(self.corpus, self.probe, k=5)
        self.assertNotIn(self.probe, [n for _, n, _, _ in hits])

    def test_accepted_only_restricts_to_accepted_units(self):
        acc = sim.accepted_symbols()
        hits = sim.neighbors(self.corpus, self.probe, k=5, accepted_only=True)
        for _, _, unit, _ in hits:
            self.assertIn(unit, acc)




class NegativeHexBucketingTests(unittest.TestCase):
    """Regression guard for the SDA21 displacement bucketing bug.

    Negative hex displacements (`-0x7b18(r13)`, the r13-relative SDA21 form
    MWCC emits for every sdata/sbss global) were not sign-stripped before the
    numeric-literal check in psx_dis.normalise, so they survived as unique
    tokens. Any function dominated by global access — e.g. __DVDFSInit, whose
    relocations are four R_PPC_EMB_SDA21 entries — then shared no n-gram with
    anything and retrieved ZERO neighbours, silently.
    """

    def setUp(self):
        sys.path.insert(0, str(ROOT / "tools"))
        import psx_dis
        self.psx = psx_dis

    def test_negative_hex_displacement_is_bucketed(self):
        tok = self.psx.normalise("lwz", "r3, -0x7b18(r13)")
        self.assertNotIn("0x7b18", tok, f"unbucketed negative hex: {tok}")
        self.assertIn("(m)", tok)

    def test_positive_and_negative_forms_bucket_alike(self):
        pos = self.psx.normalise("lwz", "r3, 0x7b18(r13)")
        neg = self.psx.normalise("lwz", "r3, -0x7b18(r13)")
        # same magnitude class, distinguished only by sign prefix
        self.assertTrue(pos.startswith("lwz imm_big"), pos)
        self.assertTrue(neg.startswith("lwz neg_big"), neg)

    def test_sda21_heavy_function_retrieves_neighbours(self):
        corpus = sim.disasm_all()
        if "__DVDFSInit" not in corpus:
            self.skipTest("__DVDFSInit absent from baseline")
        hits = sim.neighbors(corpus, "__DVDFSInit", k=5)
        self.assertTrue(hits, "SDA21-heavy function retrieved zero neighbours")


if __name__ == "__main__":
    unittest.main()
