from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import natc_harvest as harvest


class NatcHarvestTests(unittest.TestCase):
    def test_build_rebased_symbol_does_not_replace_unproven_sibling(self):
        dest = """#pragma push
#pragma force_active on
asm int target(void) { return 0; }
asm int sibling(void) { return 1; }
#pragma pop
"""
        recovered = """#pragma push
#pragma force_active on
int target(void) { return 2; }
int sibling(void) { return 99; }
#pragma pop
"""

        rebased = harvest.build_rebased_symbol(dest, recovered, "target")

        self.assertIn("int target(void) { return 2; }", rebased)
        self.assertIn("asm int sibling(void) { return 1; }", rebased)
        self.assertNotIn("return 99", rebased)

    def test_build_rebased_symbol_does_not_fabricate_provenance(self):
        dest = "asm int target(void) { return 0; }\n"
        recovered = (
            "int target(void) { return 2; }\n"
            "// provenance: mkdd:libs/test.c:99 sibling\n"
            "int sibling(void) { return 3; }\n"
        )

        rebased = harvest.build_rebased_symbol(dest, recovered, "target")

        self.assertNotIn("provenance:", rebased)

    def test_symbol_provenance_returns_the_local_tag(self):
        text = (
            "// provenance: mkdd:libs/test.c:12 target\n"
            "int target(void) { return 2; }\n"
        )

        self.assertEqual(
            "// provenance: mkdd:libs/test.c:12 target",
            harvest.symbol_provenance(text, "target"),
        )

    def test_packageability_invokes_real_preflight_on_exact_artifact(self):
        with tempfile.TemporaryDirectory() as td:
            repo = Path(td)
            dest = repo / "src/unit.c"
            dest.parent.mkdir(parents=True)
            dest.write_text("asm int target(void) { return 0; }\n")
            rebased = (
                "// provenance: mkdd:libs/test.c:12 target\n"
                "int target(void) { return 2; }\n"
            )
            observed = {}

            def fake_run(command, **_kwargs):
                batch = Path(command[command.index("--batch") + 1])
                observed["command"] = command
                observed["candidate"] = (batch / "unit.c").read_text()
                observed["card"] = (batch / "CARD.md").read_text()
                return SimpleNamespace(returncode=0)

            with mock.patch.object(harvest, "REPO", repo), \
                 mock.patch.object(harvest.subprocess, "run", side_effect=fake_run):
                self.assertTrue(
                    harvest.artifact_is_packageable(rebased, dest, "main/test")
                )

            self.assertIn("natc_preflight.py", " ".join(observed["command"]))
            self.assertIn("--rescore", observed["command"])
            self.assertEqual("// dest: src/unit.c\n" + rebased,
                             observed["candidate"])
            self.assertIn("// provenance: mkdd:libs/test.c:12 target",
                          observed["card"])

    def test_packageable_batches_emit_the_exact_last_validated_artifact(self):
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            dest = root / "unit.c"
            one = root / "one.c"
            two = root / "two.c"
            dest.write_text(
                "asm int one(void) { return 0; }\n"
                "asm int two(void) { return 0; }\n"
            )
            one.write_text(
                "// provenance: original\n"
                "int one(void) { return 1; }\n"
            )
            two.write_text(
                "// provenance: original\n"
                "int two(void) { return 2; }\n"
            )
            rows = [
                ("main/test", "one", 100.0, one, dest, "test", 0),
                ("main/test", "two", 100.0, two, dest, "test", 0),
            ]
            validated = []

            def validator(text, checked_dest, unit):
                self.assertEqual(dest, checked_dest)
                self.assertEqual("main/test", unit)
                validated.append(text)
                return True

            batches = harvest.build_packageable_batches(rows, validator=validator)
            accepted, emitted = batches[dest]

            self.assertEqual(rows, accepted)
            self.assertEqual(2, len(validated))
            self.assertIn("int one(void) { return 1; }", validated[0])
            self.assertIn("asm int two(void) { return 0; }", validated[0])
            self.assertIn("int one(void) { return 1; }", validated[1])
            self.assertIn("int two(void) { return 2; }", validated[1])
            self.assertEqual(validated[-1], emitted)

    def test_register_emitted_batch_uses_durable_queue(self):
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            batch = root / "harvest-1" / "unit"
            batch.mkdir(parents=True)
            (batch / "CARD.md").write_text("complete-unit: yes\n")
            (batch / "unit.c").write_text("int target(void) { return 1; }\n")
            observed = {}

            class FakeConnection:
                def close(self):
                    observed["closed"] = True

            def fake_open_db(path):
                observed["db"] = path
                return FakeConnection()

            def fake_register(conn, batch_id, worker, batch_path):
                observed.update(batch_id=batch_id, worker=worker,
                                batch_path=Path(batch_path))
                return {"state": "ready"}

            with mock.patch.object(harvest.submission_queue, "open_db",
                                   side_effect=fake_open_db), \
                 mock.patch.object(harvest.submission_queue, "register",
                                   side_effect=fake_register):
                row = harvest.register_emitted_batch(batch, root / "harvest-1",
                                                     "integ")

            self.assertEqual(row["state"], "ready")
            self.assertEqual("integ/harvest-1-unit", observed["batch_id"])
            self.assertEqual("integ", observed["worker"])
            self.assertEqual(batch.resolve(), observed["batch_path"])
            self.assertTrue(observed["closed"])

    def test_sibling_reference_tag_is_never_transferred(self):
        """A reference tag that names another function may not be reused here.

        `// provenance: mkdd:libs/test.c:99 sibling` says where *sibling* came
        from. Carrying it to `target` would manufacture a citation for code
        that may have nothing to do with mkdd. 2026-08-28 the symbol is now
        harvestable, but only under a ledger-backed tag that claims solely what
        the attempts row proves — never the sibling's reference.
        """
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            dest = root / "unit.c"
            recovered = root / "recovered.c"
            dest.write_text("asm int target(void) { return 0; }\n")
            recovered.write_text(
                "// provenance: mkdd:libs/test.c:99 sibling\n"
                "int target(void) { return 1; }\n"
            )
            row = ("main/test", "target", 100.0, recovered,
                   dest, "worker7", 0)

            batches = harvest.build_packageable_batches(
                [row], validator=lambda *_args: True)

            self.assertEqual(1, len(batches))
            _accepted, text = batches[dest]
            tag = harvest.symbol_provenance(text, "target")
            self.assertIsNotNone(tag, "harvested symbol must carry a tag")
            self.assertIn("harvest:runs.sqlite", tag)
            self.assertIn("target", tag)
            self.assertIn("worker7", tag)
            self.assertIn("original reference not recorded", tag)
            self.assertNotIn("mkdd", tag)

    def test_existing_symbol_provenance_is_left_alone(self):
        """A candidate that already cites a reference for THIS symbol keeps
        it verbatim; the ledger tag is a fallback, not a rewrite."""
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            recovered = root / "recovered.c"
            recovered.write_text(
                "// provenance: mkdd:libs/test.c:99 target\n"
                "int target(void) { return 1; }\n"
            )
            text = recovered.read_text()
            out = harvest.ensure_symbol_provenance(
                text, "target", "main/test", "worker7", 0, recovered)
            self.assertEqual(text, out)
            self.assertNotIn("harvest:runs.sqlite", out)

    def test_max_per_batch_caps_accepted_symbols(self):
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            dest = root / "unit.c"
            one = root / "one.c"
            two = root / "two.c"
            dest.write_text(
                "asm int one(void) { return 0; }\n"
                "asm int two(void) { return 0; }\n"
            )
            one.write_text("// provenance: original\nint one(void) { return 1; }\n")
            two.write_text("// provenance: original\nint two(void) { return 2; }\n")
            rows = [
                ("main/test", "one", 100.0, one, dest, "test", 0),
                ("main/test", "two", 100.0, two, dest, "test", 0),
            ]

            cap_stats = {}
            batches = harvest.build_packageable_batches(
                rows, validator=lambda *_args: True, max_per_batch=1,
                stats=cap_stats)

            accepted, emitted = batches[dest]
            self.assertEqual([rows[0]], accepted)
            self.assertIn("int one", emitted)
            self.assertIn("asm int two", emitted)
            self.assertEqual(1, cap_stats["deferred_by_cap"])

    def test_rejected_row_is_not_present_in_emitted_artifact(self):
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            dest = root / "unit.c"
            one = root / "one.c"
            two = root / "two.c"
            dest.write_text(
                "asm int one(void) { return 0; }\n"
                "asm int two(void) { return 0; }\n"
            )
            one.write_text("// provenance: original\nint one(void) { return 1; }\n")
            two.write_text("// provenance: original\nint two(void) { return 2; }\n")
            rows = [
                ("main/test", "one", 100.0, one, dest, "test", 0),
                ("main/test", "two", 100.0, two, dest, "test", 0),
            ]

            validation_calls = []

            def validator(text, _dest, _unit):
                validation_calls.append(text)
                return len(validation_calls) == 1

            batches = harvest.build_packageable_batches(rows, validator=validator)
            accepted, emitted = batches[dest]

            self.assertEqual([rows[0]], accepted)
            self.assertIn("int one(void) { return 1; }", emitted)
            self.assertIn("asm int two(void) { return 0; }", emitted)


if __name__ == "__main__":
    unittest.main()
