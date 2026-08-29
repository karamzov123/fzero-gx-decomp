from __future__ import annotations

import importlib.util
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def _load():
    spec = importlib.util.spec_from_file_location(
        "natc_compiler_invocation", ROOT / "tools/natc_compiler_invocation.py"
    )
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_parse_edge_preserves_sjis_and_quoted_pragma():
    m = _load()
    line = (
        "build/tools/wibo build/tools/sjiswrap.exe "
        "build/compilers/GC/1.2.5n/mwcceppc.exe -O4 -pragma 'cats off' "
        "-MMD -c src/a.c -o build/a.o && transform_dep build/a.d"
    )
    edge = m.parse_ninja_command(line)
    assert edge["mw_version"] == "GC/1.2.5n"
    assert edge["sjis"] is True
    assert "-MMD" not in edge["argv"]
    assert edge["argv"][edge["argv"].index("-pragma") + 1] == "cats off"


def test_invocation_identity_changes_with_compiler_bytes(tmp_path):
    m = _load()
    compiler = tmp_path / "GC" / "1.2.5n" / "mwcceppc.exe"
    compiler.parent.mkdir(parents=True)
    compiler.write_bytes(b"compiler-a")
    src = tmp_path / "candidate.c"
    src.write_text("int f(void) { return 1; }\n")
    edge = {
        "argv": ["wibo", str(compiler), "-O4", "-c", "src/original.c"],
        "src": "src/original.c",
        "mw_version": "GC/1.2.5n",
        "sjis": False,
    }
    first = m.build_invocation(edge, "unit/a", src, tmp_path / "a.o")
    compiler.write_bytes(b"compiler-b")
    second = m.build_invocation(edge, "unit/a", src, tmp_path / "a.o")
    assert first.compiler_sha256 != second.compiler_sha256
    assert first.invocation_id != second.invocation_id
    assert len(first.compiler_sha256) == 64
    assert len(first.flags_sha256) == 64


def test_compiler_override_only_replaces_executable(tmp_path):
    m = _load()
    old = tmp_path / "GC" / "1.2.5n" / "mwcceppc.exe"
    new = tmp_path / "GC" / "1.2.5" / "mwcceppc.exe"
    old.parent.mkdir(parents=True)
    new.parent.mkdir(parents=True)
    old.write_bytes(b"old")
    new.write_bytes(b"new")
    src = tmp_path / "candidate.c"
    src.write_text("void f(void) {}\n")
    edge = {
        "argv": ["wibo", str(old), "-lang", "c", "-c", "old.c"],
        "src": "old.c",
        "mw_version": "GC/1.2.5n",
        "sjis": False,
    }
    inv = m.build_invocation(
        edge, "unit/a", src, tmp_path / "a.o", compiler_override=new
    )
    assert inv.mw_version == "GC/1.2.5"
    assert inv.argv[0] == "wibo"
    assert inv.argv[1] == str(new)
    assert inv.argv[2:5] == ("-lang", "c", "-c")
    assert inv.argv[-2:] == ("-o", str(tmp_path / "a.o"))


def test_record_contains_full_reproducibility_identity(tmp_path):
    m = _load()
    compiler = tmp_path / "GC" / "1.3" / "mwcceppc.exe"
    compiler.parent.mkdir(parents=True)
    compiler.write_bytes(b"cc")
    src = tmp_path / "candidate.c"
    src.write_text("int f;\n")
    edge = {
        "argv": ["wibo", str(compiler), "-c", "old.c"],
        "src": "old.c",
        "mw_version": "GC/1.3",
        "sjis": False,
    }
    rec = m.build_invocation(edge, "u", src, tmp_path / "x.o").to_record(
        context_sha256="c" * 64, canonical_head="abc123"
    )
    assert rec["schema_version"] == 1
    assert rec["source_sha256"] == m.sha256_file(src)
    assert rec["context_sha256"] == "c" * 64
    assert rec["canonical_head"] == "abc123"
    assert rec["argv"][-1] == str(tmp_path / "x.o")
