import importlib.util
import json
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location(
    "find_xrefs_under_test", ROOT / "tools/find_xrefs.py")
assert SPEC and SPEC.loader
fx = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(fx)


class FindXrefsSliceTests(unittest.TestCase):
    """Contract tests for find_xrefs --cslice (item 1).

    These exercise the real index built from the DOL/objects already present
    in this worktree, so they double as a regression guard for the cslice
    JSON shape the rest of the fleet consumes.
    """

    @classmethod
    def setUpClass(cls):
        cls.idx = fx.build_index()
        # GXSetMisc is a small .text FUNC with exactly one SDA21 global (gx).
        cls.sym = "GXSetMisc"

    def test_definition_is_well_formed(self):
        d = fx.cslice(self.idx, self.sym, use_json=True)
        self.assertEqual(d["symbol"], self.sym)
        defn = d["definition"]
        self.assertTrue(defn["object"].endswith(".o"))
        self.assertEqual(defn["section"], ".text")
        self.assertGreater(defn["size"], 0)

    def test_emit_recognises_one_global_with_section_and_type(self):
        d = fx.cslice(self.idx, self.sym, use_json=True)
        grefs = d["globals_referenced"]
        self.assertTrue(any(g["symbol"] == "gx" for g in grefs),
                        "GXSetMisc must reference the SDA21 global 'gx'")
        gx = next(g for g in grefs if g["symbol"] == "gx")
        self.assertEqual(gx["types"], ["R_PPC_EMB_SDA21"])
        self.assertEqual(gx["section"], ".sdata2")
        self.assertEqual(gx["size"], 4)

    def test_header_fragment_applies_t1_t3_for_sda21_scalar(self):
        # T1/T3: a <=8B extern scalar in .sdata2 is emitted as a volatile sda21
        # dec1 — the relocation type IS the declaration rule.
        d = fx.cslice(self.idx, self.sym, use_json=True)
        frag = d["header_fragment"]
        self.assertIn("gx", frag)
        self.assertIn("sda21=True", frag)
        self.assertIn("volatile", frag)

    def test_reloc_histogram_records_sda21(self):
        d = fx.cslice(self.idx, self.sym, use_json=True)
        self.assertEqual(d["reloc_histogram"].get("R_PPC_EMB_SDA21"), 1)

    def test_callers_are_populated_for_uptree_symbol(self):
        # GXSetMisc is called by GXInit in this DOL.
        d = fx.cslice(self.idx, self.sym, use_json=True)
        self.assertIn("GXInit", d["callers"])

    def test_cache_is_content_addressed(self):
        d1 = fx.cslice(self.idx, self.sym, use_json=True)
        d2 = fx.cslice(self.idx, self.sym, use_json=True)
        self.assertEqual(json.dumps(d1, sort_keys=True),
                         json.dumps(d2, sort_keys=True))


class GuessDeclShapeTests(unittest.TestCase):
    """T1/T3 declaration-shape contract for guess_decl (item 1)."""

    def _rec(self, section, size, stype=1):
        return {"section": section, "size": size, "stype": stype}

    def test_addr16_ha_lo_data_4b_is_array_not_scalar(self):
        # A .data/.sbss global referenced via ADDR16_HA+LO of size 4 must be
        # an array (dtk: extern unsigned char lbl_X[4]), NOT a scalar int.
        d = fx.guess_decl("lbl_X", self._rec(".data", 4),
                          ["R_PPC_ADDR16_HA", "R_PPC_ADDR16_LO"])
        self.assertIn("unsigned char lbl_X[4]", d)
        self.assertNotIn("extern int lbl_X", d)

    def test_addr16_plain_data_4b_is_array(self):
        d = fx.guess_decl("lbl_Y", self._rec(".sbss", 4), ["R_PPC_ADDR16"])
        self.assertIn("unsigned char lbl_Y[4]", d)

    def test_addr16_byte_is_volatile_char(self):
        d = fx.guess_decl("lbl_Z", self._rec(".data", 1), ["R_PPC_ADDR16_LO"])
        self.assertIn("volatile unsigned char lbl_Z", d)

    def test_guess_decl_accepts_list_rtypes(self):
        # cslice passes a list (sorted(tset)); must not raise TypeError.
        d = fx.guess_decl("lbl_W", self._rec(".data", 4),
                          sorted(["R_PPC_ADDR16_LO", "R_PPC_ADDR16_HA"]))
        self.assertIn("unsigned char lbl_W[4]", d)

    def test_sda21_scalar_still_scalar(self):
        d = fx.guess_decl("gx", self._rec(".sdata2", 4), [109])
        self.assertIn("extern const volatile float gx", d)


if __name__ == "__main__":
    unittest.main()
