import importlib.util
import shutil
import subprocess
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
# Standalone-run support: `python3 tests/test_emit_m2c_asm.py` puts tests/ on
# sys.path, not the repo root, so `import tools.find_xrefs` below fails with
# ModuleNotFoundError. Every other test in this dir spec-loads its module and
# is therefore immune; this one needs find_xrefs as a real package import.
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))
SPEC = importlib.util.spec_from_file_location(
    "emit_m2c_asm_under_test", ROOT / "tools/emit_m2c_asm.py")
assert SPEC and SPEC.loader
emit_mod = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(emit_mod)


def _have_uv():
    return shutil.which("uv") is not None


def _obj_for(symbol):
    """Find the first real .o defining `symbol` in this worktree."""
    import tools.find_xrefs as fx  # noqa: F401  (import side-effect: path setup)
    idx = fx.build_index()
    for rec in idx["defines"].get(symbol, []):
        if rec["section"] == ".text":
            return ROOT / rec["object"]
    return None


class EmitM2cAsmTests(unittest.TestCase):
    """Contract tests for emit_m2c_asm.py (item 3)."""

    @classmethod
    def setUpClass(cls):
        cls.obj = _obj_for("GXSetMisc")
        cls.asm = None
        if cls.obj is not None:
            try:
                cls.asm = emit_mod.emit(cls.obj, only_symbol="GXSetMisc")
            except SystemExit:
                cls.asm = None

    def test_emits_section_and_machine_directive(self):
        self.assertIsNotNone(self.asm, "emit() requires capstone via uv")
        self.assertIn(".machine ppc", self.asm)
        self.assertIn(".text", self.asm)

    def test_preserves_function_boundary_with_size_directive(self):
        self.assertIn("GXSetMisc:", self.asm)
        self.assertIn(".size GXSetMisc, .-GXSetMisc", self.asm)

    def test_sda21_reloc_emitted_in_default_m2c_mode(self):
        # Spec item 3: R_PPC_EMB_SDA21 -> sym@sda21 (NOT @l) in the default
        # (m2c-targeting) mode. The clang @l rewrite only applies with
        # --numeric-regs, which we do NOT use here.
        self.assertIn("@sda21", self.asm)
        self.assertIn("gx@sda21", self.asm)

    def test_emit_does_not_silently_rewrite_sda21_to_l(self):
        # Guarantee the default path keeps @sda21 and never emits gx@l.
        for line in self.asm.splitlines():
            if "gx" in line and "@" in line:
                self.assertIn("@sda21", line)
                self.assertNotIn("gx@l", line)

    def test_round_trip_support_only_via_numeric_regs_flag(self):
        # The --numeric-regs path rewrites @sda21 -> @l for *clang* assembly
        # verification only (not linkability). Confirm the flag exists and
        # changes the emitted text without mutating the default contract.
        if self.obj is None:
            self.skipTest("no target object")
        try:
            num = emit_mod.emit(self.obj, only_symbol="GXSetMisc",
                                numeric_regs=True)
        except SystemExit:
            self.skipTest("capstone/uv unavailable for numeric-regs path")
        self.assertIn("@l", num)
        # default still has @sda21 (no shared mutation)
        self.assertIn("@sda21", self.asm)


class M2cWiringTests(unittest.TestCase):
    """Item 3, second half: the m2c wiring itself.

    m2c is NOT at its documented path (source lives at ~/tools/m2c), so the
    interpreter/path/target triple in emit_m2c_asm.main() is the fragile part
    and nothing else in this suite exercised it. These tests pin the wiring
    contract: m2c is reachable, the ppc-mwcc-c target is what we invoke, and
    --m2c actually yields C rather than an m2c error.
    """

    def test_m2c_entrypoint_path_exists(self):
        # If m2c moves, --m2c fails at runtime with a bare traceback; catch it
        # here instead, and keep the resolved location asserted in one place.
        self.assertTrue(
            emit_mod.M2C.is_file(),
            f"m2c entrypoint missing at {emit_mod.M2C} — item 3 wiring broken")

    def test_m2c_target_triple_is_ppc_mwcc_c(self):
        src = (ROOT / "tools/emit_m2c_asm.py").read_text()
        self.assertIn("ppc-mwcc-c", src)

    def test_m2c_only_pins_function_when_symbol_given(self):
        # Regression guard: passing --function "" makes m2c abort with
        # "Function not found." on a whole-object emit.
        src = (ROOT / "tools/emit_m2c_asm.py").read_text()
        self.assertIn('if args.symbol:', src)
        self.assertNotIn('cmd += ["--function", args.symbol or ""]', src)

    def test_m2c_end_to_end_produces_c_for_real_symbol(self):
        obj = _obj_for("GXSetMisc")
        if obj is None:
            self.skipTest("no target object for GXSetMisc")
        if not emit_mod.M2C.is_file():
            self.skipTest("m2c not installed")
        r = subprocess.run(
            [sys.executable, str(ROOT / "tools/emit_m2c_asm.py"), str(obj),
             "--symbol", "GXSetMisc", "--m2c"],
            capture_output=True, text=True, timeout=300)
        self.assertEqual(r.returncode, 0, r.stderr[-800:])
        out = r.stdout
        # A real decompiled body, not an m2c diagnostic.
        self.assertIn("GXSetMisc", out)
        self.assertNotIn("Function not found", out)
        self.assertNotIn("Traceback", out + r.stderr)
        self.assertNotIn("Decompilation failure", out + r.stderr)
        # m2c emits a C signature and a brace body; asm mnemonics must be gone.
        self.assertIn("{", out)
        self.assertNotIn(".machine ppc", out)

    def test_conditional_branch_keeps_no_raw_hex_target(self):
        # Regression guard for the bne/bne-style conditional-branch bug:
        # capstone renders `bne cr1, 0x40` with the target as the SECOND
        # operand, so the emitter must rewrite it to `.Ltgt_*`. A raw hex
        # branch target makes m2c abort with "Failed to parse instruction".
        # OSPanic has a conditional branch (bne cr1, .Ltgt_40) in .text.
        import tools.find_xrefs as fx
        idx = fx.build_index()
        obj = None
        for rec in idx["defines"].get("OSPanic", []):
            if rec["section"] == ".text":
                obj = ROOT / rec["object"]
                break
        if obj is None:
            self.skipTest("no target object for OSPanic")
        asm = emit_mod.emit(obj, only_symbol="OSPanic")
        # no raw-hex unconditional/conditional branch targets remain
        for line in asm.splitlines():
            s = line.strip()
            if s.startswith(("b ", "beq", "bne", "blt", "bgt", "ble",
                             "bge", "bdnz", "bdz", "bctr")) \
                    and "0x" in s:
                self.fail(f"raw hex branch target not rewritten: {line!r}")
        self.assertIn(".Ltgt_", asm)
        # and m2c must parse it without a decompilation failure
        if not emit_mod.M2C.is_file():
            self.skipTest("m2c not installed")
        r = subprocess.run(
            [sys.executable, str(ROOT / "tools/emit_m2c_asm.py"), str(obj),
             "--symbol", "OSPanic", "--m2c"],
            capture_output=True, text=True, timeout=300)
        self.assertEqual(r.returncode, 0, r.stderr[-800:])
        self.assertNotIn("Failed to parse instruction", r.stdout + r.stderr)


class EmitFailureContractTests(unittest.TestCase):
    """emit() must fail loudly, not traceback, on absent/non-code objects.

    A missing .o is the EXPECTED state in a mid-gate tree: worker trees have
    no build.ninja and only the integrator runs the full build. A raw
    FileNotFoundError traceback there reads like a tool bug and sends the
    reader hunting the wrong problem, so this pins the same one-line
    diagnostic + rc=1 contract that find_xrefs/similar already honour.
    """

    def _run(self, *args):
        return subprocess.run(
            [sys.executable, str(ROOT / "tools/emit_m2c_asm.py"), *args],
            capture_output=True, text=True, timeout=300)

    def test_missing_object_exits_1_without_traceback(self):
        r = self._run("build/GFZE01/obj/dolphin/gx/NOSUCH_zz.o",
                      "--symbol", "GXSetMisc")
        self.assertEqual(r.returncode, 1)
        both = r.stdout + r.stderr
        self.assertIn("object not found", both)
        self.assertNotIn("Traceback", both)
        self.assertNotIn("FileNotFoundError", both)

    def test_object_without_text_section_exits_1_without_traceback(self):
        # Reachable, not hypothetical: data-only objects exist in this tree.
        import tools.find_xrefs as fx
        target = None
        for p in sorted((ROOT / "build/GFZE01/obj").rglob("*.o")):
            try:
                secs, _, _ = fx.parse_object(p)
            except Exception:
                continue
            if not any(s["name"] == ".text" for s in secs):
                target = p
                break
        if target is None:
            self.skipTest("no data-only object available in this tree")
        r = self._run(str(target))
        self.assertEqual(r.returncode, 1)
        both = r.stdout + r.stderr
        self.assertIn("not a code object", both)
        self.assertNotIn("Traceback", both)

    def test_good_path_unaffected_by_the_guards(self):
        obj = _obj_for("GXSetMisc")
        if obj is None:
            self.skipTest("no target object for GXSetMisc")
        r = self._run(str(obj), "--symbol", "GXSetMisc")
        self.assertEqual(r.returncode, 0, r.stderr[-400:])
        self.assertIn(".machine ppc", r.stdout)

    def test_non_elf_input_exits_1_without_traceback(self):
        # A worker can pass the linked DOL (orig/GFZE01/sys/main.dol) by
        # mistake; parse_object raises ValueError("not an ELF"). That must
        # become a one-line rc=1 diagnostic — matching find_xrefs/similar —
        # not a traceback that reads like a tool bug.
        dol = ROOT / "orig/GFZE01/sys/main.dol"
        if not dol.is_file():
            self.skipTest("no DOL present in this tree")
        r = self._run(str(dol), "--symbol", "fn_8006E250")
        self.assertEqual(r.returncode, 1)
        both = r.stdout + r.stderr
        self.assertIn("not an ELF object", both)
        self.assertNotIn("Traceback", both)
        self.assertNotIn("ValueError", both)


if __name__ == "__main__":
    unittest.main()
