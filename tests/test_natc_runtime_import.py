import hashlib
import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))
from natc_runtime_import import TraceImportError, import_trace


def record(**overrides):
    value = {
        "schema_version": "natc.trace.v1", "run_id": "r1",
        "identity": {"game_id": "GFZE01", "dol_sha1": "a" * 40,
                      "map_id": "map-sha256:" + "b" * 64, "source_path": "x.dol",
                      "repo_revision": "c" * 40, "profile": "fixture",
                      "mem1_size": 0x1800000, "dolphin_pid": 1234,
                      "iso": "/isos/GFZE01.iso", "owner": "natc-runtime",
                      "emulator_label": "live-verified"},
        "source": "dolphin-memory",
        "provenance": {"frame": 1, "phase": "race", "symbol": "gRacers",
                       "address": "0x80001000", "width": 4},
        "observation": {"hex": "12345678", "value": 0x12345678},
        "path_facts": ["race_update"],
    }
    value.update(overrides)
    return value


def write_bundle(path: Path, records: list[dict], **manifest_overrides):
    path.write_text("".join(json.dumps(value, sort_keys=True) + "\n" for value in records))
    first = records[0]
    identity = first["identity"]
    manifest = {
        "manifest_version": "natc.trace.manifest.v1",
        "schema_version": "natc.trace.v1",
        "record_count": len(records),
        "artifact": str(path),
        "artifact_sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
        "run_id": first["run_id"],
        "identity": identity,
        "iso": identity["iso"],
        "owner": identity["owner"],
        "emulator_label": identity["emulator_label"],
        "read_plan": [value["provenance"] for value in records],
    }
    manifest.update(manifest_overrides)
    manifest_path = path.with_suffix(path.suffix + ".manifest.json")
    manifest_raw = json.dumps(manifest).encode()
    manifest_path.write_bytes(manifest_raw)
    marker = {"marker_version": "natc.trace.complete.v1",
              "artifact_sha256": manifest["artifact_sha256"],
              "manifest_sha256": hashlib.sha256(manifest_raw).hexdigest()}
    Path(str(path) + ".complete.json").write_text(json.dumps(marker))


class ImportTests(unittest.TestCase):
    def test_imports_valid_trace_with_exact_identity_and_address(self):
        with tempfile.TemporaryDirectory() as td:
            path = Path(td) / "trace.jsonl"
            write_bundle(path, [record()])
            result = import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                                  map_id="map-sha256:" + "b" * 64)
            self.assertEqual(result["record_count"], 1)
            self.assertEqual(result["observations"][0]["symbol"], "gRacers")
            self.assertEqual(result["identity"]["emulator_label"], "live-verified")

    def test_import_rejects_offline_fixture_and_unbound_read_plan(self):
        with tempfile.TemporaryDirectory() as td:
            path = Path(td) / "trace.jsonl"
            value = record()
            value["identity"] = {**value["identity"], "emulator_label": "offline-fixture"}
            write_bundle(path, [value])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)

            value = record()
            write_bundle(path, [value], read_plan=[])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)

    def test_import_rejects_malformed_observation_without_leaking_type_error(self):
        value = record()
        value["observation"]["hex"] = 7
        with tempfile.TemporaryDirectory() as td:
            path = Path(td) / "trace.jsonl"
            write_bundle(path, [value])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map:" + "b" * 64)

        with tempfile.TemporaryDirectory() as td:
            path = Path(td) / "trace.jsonl"
            write_bundle(path, [record()])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="c" * 40,
                             map_id="map-sha256:" + "b" * 64)
            bad = record(schema_version="natc.trace.v9")
            write_bundle(path, [bad])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)

    def test_import_rejects_mixed_run_bundle_and_bad_manifest_count(self):
        with tempfile.TemporaryDirectory() as td:
            path = Path(td) / "trace.jsonl"
            first = record()
            second = record(run_id="r2")
            write_bundle(path, [first, second])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)
            write_bundle(path, [first], record_count=2)
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)

    def test_import_requires_matching_completion_marker(self):
        with tempfile.TemporaryDirectory() as td:
            path = Path(td) / "trace.jsonl"
            write_bundle(path, [record()])
            Path(str(path) + ".complete.json").write_text(json.dumps({
                "marker_version": "natc.trace.complete.v1",
                "artifact_sha256": "0" * 64, "manifest_sha256": "0" * 64}))
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)

    def test_import_enforces_independent_string_and_path_fact_limits(self):
        with tempfile.TemporaryDirectory() as td:
            path = Path(td) / "trace.jsonl"
            value = record(run_id="r" * 257)
            write_bundle(path, [value])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)
            value = record(path_facts=[str(i) for i in range(65)])
            write_bundle(path, [value])
            with self.assertRaises(TraceImportError):
                import_trace(path, game_id="GFZE01", dol_sha1="a" * 40,
                             map_id="map-sha256:" + "b" * 64)


if __name__ == "__main__":
    unittest.main()
