#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import json
import re
import shlex
import subprocess
import sys
from pathlib import Path
from typing import Any, Dict, List, Tuple

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "GFZE01",  # 0: NTSC-U (primary)
    "GFZP01",  # 1: PAL (asm baseline)
    "GFZJ01",  # 2: NTSC-J (asm baseline)
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-2"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.8.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.2.0"
if not is_windows() and not config.wrapper:
    _wibo_bin = config.build_dir / "tools" / "wibo"
    if _wibo_bin.is_file():
        try:
            _ver = subprocess.run([str(_wibo_bin), "--version"], capture_output=True, text=True, timeout=5)
            if config.wibo_tag not in (_ver.stdout + _ver.stderr):
                _wibo_bin.unlink(missing_ok=True)
        except OSError:
            _wibo_bin.unlink(missing_ok=True)

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []  # extended below with units.json

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Warning flags
if args.warn == "all":
    cflags_base.append("-W all")
elif args.warn == "off":
    cflags_base.append("-W off")
elif args.warn == "error":
    cflags_base.append("-W error")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

# Linker/compiler versions are provisional until M1 verifies them against
# retail codegen (see docs/TOOLCHAIN.md). The existing GFZE01 project links
# with GC/1.3 and compiles most units with GC/1.2.5n or GC/1.3.
config.linker_version = "GC/1.3.2"
# Object name used to link RELs that have no configured units yet.
config.rel_empty_file = "rel/empty.c"
# Retail RELs were linked with dead-stripping. Evidence: a static function that MWCC inlined at
# every call is not in retail code, but the literals it created are at the place of its
# definition (replay .rodata 0x0: the floats of fn_13_CDC are before the colours of fn_13_BCC,
# main_rel .data 0x1EF68: the car_test model/texture info strings are before the strings of
# fn_1_7C2A0). Every shipped MWCC emits the code of such a function, so the link removed it.
# Retail also keeps functions with no caller (main.rel fn_1_8CA20). The roots of the retail link
# are not known. This build assumes that they were the global symbols: tools/rel_forceactive.py
# puts every global symbol in FORCEACTIVE and `-strip_partial` removes only unreferenced local
# symbols. A carved unit needs no entry. tools/rel_strip_check.py stops the build when the link
# removes a local symbol that config/GFZE01/<module>/strip_allow.txt does not list.
config.rel_strip_partial = True


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_rel,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.shift_jis = config.version == "GFZJ01"
config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "progress_category": "sdk",  # str | List[str]
        "objects": [
            Object(NonMatching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
        ],
    },
]


# Per-function and per-TU units are generated by tools/fzgx. One list serves every version:
# config/GFZE01/units.json. Each entry: {"module": "main"|<rel name>,
#   "source": "dol/....c"|"rel/<mod>/....c", "symbols": [...],
#   "status": "matching"|"nonmatching", "matching_for": [<VERSION>, ...] (optional),
#   "mw_version": null|"GC/1.3", "extra_cflags": [...]}
# As in dtk-template: "matching" alone is Matching (every version); with "matching_for"
# it is MatchingFor(*matching_for). Other versions build only the units that match them,
# from their own symbols.txt (GFZE01 names at their addresses); their splits are the
# GFZE01 unit splits moved to those addresses (render_version_config).
CANONICAL_VERSION = VERSIONS[DEFAULT_VERSION]
CANONICAL_UNITS = Path("config") / CANONICAL_VERSION / "units.json"


def unit_matches(u: Dict[str, Any], version: str) -> bool:
    """Matching, or MatchingFor(*u["matching_for"])."""
    return u.get("status") == "matching" and version in u.get("matching_for", VERSIONS)


def version_units() -> List[Dict[str, Any]]:
    """The units configured for config.version, with `status` meaning this version."""
    if not CANONICAL_UNITS.exists():
        return []
    out = []
    for u in json.loads(CANONICAL_UNITS.read_text()):
        if config.version == CANONICAL_VERSION:
            v = dict(u)
            if not unit_matches(u, config.version) and v.get("status") == "matching":
                v["status"] = "nonmatching"
            out.append(v)
        elif unit_matches(u, config.version):
            out.append(dict(u))
    return out


def _symbol_addrs(path: Path) -> Dict[str, Tuple[str, int]]:
    out = {}
    for line in path.read_text().splitlines():
        m = re.match(r"(\S+) = (\.\w+):0x([0-9A-Fa-f]+);", line)
        if m:
            out[m.group(1)] = (m.group(2), int(m.group(3), 16))
    return out


def render_version_config(units: List[Dict[str, Any]]) -> Path:
    """build/<VERSION>/config.yml whose splits are the GFZE01 unit splits moved to this version.

    Every symbol named in both versions inside a split range must move by the same amount,
    or the unit cannot be placed and configure stops. Section headers stay in
    config/<VERSION>/**/splits.txt."""
    src_cfg = Path("config") / config.version / "config.yml"
    out_dir = Path(config.build_dir) / config.version / "splits"
    by_mod: Dict[str, List[Dict[str, Any]]] = {}
    for u in units:
        by_mod.setdefault(u["module"], []).append(u)

    def module_dir(ver: str, mod: str) -> Path:
        return Path("config") / ver if mod == "main" else Path("config") / ver / mod

    def render(m: "re.Match[str]") -> str:
        rel = Path(m.group(1))
        mod = "main" if rel.parent == Path("config") / config.version else rel.parent.name
        us_syms = _symbol_addrs(module_dir(CANONICAL_VERSION, mod) / "symbols.txt")
        rg_syms = _symbol_addrs(module_dir(config.version, mod) / "symbols.txt")
        blocks = {}
        for block in (module_dir(CANONICAL_VERSION, mod) / "splits.txt").read_text().split("\n\n")[1:]:
            lines = block.strip().splitlines()
            if lines and lines[0].endswith(":"):
                blocks[lines[0][:-1]] = lines[1:]
        header = rel.read_text().split("\n\n")[0].strip() if rel.exists() else ""
        body = []
        for u in sorted(by_mod.get(mod, []), key=lambda u: u["source"]):
            lines = blocks.get(u["source"])
            if lines is None:
                sys.exit(f"{config.version}: {u['source']} has no {CANONICAL_VERSION} split")
            moved = []
            for line in lines:
                r = re.match(r"(\t(\.\w+)\s+start:0x)([0-9A-F]+)( end:0x)([0-9A-F]+)(.*)", line)
                if not r:
                    sys.exit(f"{config.version}: cannot read split line {line!r}")
                sec, lo, hi = r.group(2), int(r.group(3), 16), int(r.group(5), 16)
                deltas = {rg_syms[s][1] - a for s, (ssec, a) in us_syms.items()
                          if ssec == sec and lo <= a < hi and s in rg_syms and rg_syms[s][0] == sec}
                if len(deltas) != 1:
                    sys.exit(f"{config.version}: {u['source']} {sec} cannot be placed "
                             f"(its symbols in config/{config.version} do not move together)")
                d = deltas.pop()
                moved.append(f"{r.group(1)}{lo + d:08X}{r.group(4)}{hi + d:08X}{r.group(6)}")
            start = min(int(re.search(r"start:0x([0-9A-F]+)", x).group(1), 16) for x in moved)
            body.append((start, f"{u['source']}:\n" + "\n".join(moved)))
        out = out_dir / rel.relative_to(Path("config") / config.version)
        out.parent.mkdir(parents=True, exist_ok=True)
        parts = ([header] if header else []) + [b for _, b in sorted(body)]
        content = "\n\n".join(parts) + "\n" if parts else ""
        if not out.exists() or out.read_text() != content:
            out.write_text(content)
        return f"splits: {out.as_posix()}"

    text = re.sub(r"splits: (\S+)", render, src_cfg.read_text())
    dest = Path(config.build_dir) / config.version / "config.yml"
    if not dest.exists() or dest.read_text() != text:
        dest.write_text(text)
    return dest


def load_generated_units() -> None:
    by_module: Dict[str, List[Object]] = {}
    units = version_units()
    if not units:
        return
    if any(u.get("tu") for u in units):
        # block units: their C is a block of src/<tu>.c; the compiled unit is generated from it
        sys.path.insert(0, str(Path("tools")))
        from fzgx.project import Project as _Project  # scoped: only when block units exist; tools/ on sys.path
        from fzgx import tufile as _tufile  # scoped: same
        _tufile.regenerate(_Project(config.version), units)
    for u in units:
        extra = list(u.get("extra_cflags") or [])
        opts: Dict[str, Any] = {"extra_cflags": [f for f in extra if not f.startswith("-O")]}
        olevel = [f for f in extra if f.startswith("-O")]
        if olevel:  # mwcc keeps the first -O it sees: an override must replace the module's
            base = cflags_base if u["module"] == "main" else cflags_rel
            opts["cflags"] = [olevel[-1] if f.startswith("-O") else f for f in base]
        if u.get("mw_version"):
            opts["mw_version"] = u["mw_version"]
        if u.get("tu"):
            opts["src_dir"] = str(Path("build") / config.version / "gen")
        src = u["source"]
        if u.get("asm"):
            # an assembly unit: the object keeps the split's unit name (dol/x.c) so the template
            # finds its configuration; the source is the split's asm copied into src/
            opts["source"] = src[:-2] + ".s"
        if u["module"] == "main":
            sdk = src.startswith(("dol/dolphin/", "dol/msl/", "dol/trk/", "dol/runtime/"))
            opts["progress_category"] = "sdk" if sdk else "game"
        by_module.setdefault(u["module"], []).append(
            Object(u["status"] == "matching", src, **opts)
        )
    for module, objects in by_module.items():
        if module == "main":
            config.libs.append({
                "lib": "dol",
                "mw_version": "GC/1.2.5n",
                "cflags": cflags_base,
                "progress_category": "game",
                "objects": objects,
            })
        else:
            config.libs.append(Rel(module, objects))


load_generated_units()
config.reconfig_deps = [CANONICAL_UNITS, Path("config") / config.version / "ldscript.tpl"]
if config.version != CANONICAL_VERSION:
    config.config_path = render_version_config(version_units())
    for d in (Path("config") / CANONICAL_VERSION, Path("config") / config.version):
        config.reconfig_deps += sorted(d.glob("**/splits.txt")) + sorted(d.glob("**/symbols.txt"))


# sjiswrap only matters for non-ASCII text the compiler sees (string/char literals); none of
# the shared C has any (a few comments do), and sjiswrap v1.2.2 fails to start under wibo 1.2.0.
def _needs_shift_jis(path: Path) -> bool:
    code = re.sub(rb"/\*.*?\*/|//[^\n]*", b"", path.read_bytes(), flags=re.S)
    return any(b > 0x7F for b in code)


if config.shift_jis:
    _srcs = {Path("src") / (u.get("tu") or u["source"]) for u in version_units()
             if not u.get("asm") and u.get("status") == "matching"}
    config.shift_jis = any(p.exists() and _needs_shift_jis(p) for p in _srcs)


def add_pool_rules() -> None:
    """Units whose private literal-pool constants must be retargeted to the retail pooled
    symbols (units.json `pool` mapping) compile through `mwcc_pool`: mwcc, then
    tools/fzgx/poolfix.py on the object. See tools/fzgx/poolfix.py."""
    # `own` lists retail names whose range the unit's split owns: poolfix renames the private
    # definition (`=NAME`) instead of turning it into a reference; `export` names other units
    # still reference, so the definition also becomes global (`=+NAME`).
    pool = {u["source"]: {k: ("=" + ("+" if v in (u.get("export") or []) else "") + v
                              if v in (u.get("own") or []) else v) for k, v in u["pool"].items()}
            for u in version_units() if isinstance(u.get("pool"), dict) and u["pool"]}
    if not pool:
        return
    ninja_path = Path("build.ninja")
    text = ninja_path.read_text()
    # derive from the generated mwcc rule so compiler/wibo paths (which differ in CI) stay right
    m = re.search(r"^rule mwcc\n((?:  .*\n)+)", text, re.M)
    if not m:
        sys.exit("build.ninja: no mwcc rule to derive mwcc_pool from")
    body = m.group(1)
    cmd = re.search(r"^  command = (.*?)(?=^  \w+ = |\Z)", body, re.M | re.S).group(1)
    cmd = " ".join(l.strip().rstrip("$").strip() for l in cmd.splitlines()).strip()
    rest = re.sub(r"^  command = .*?(?=^  \w+ = |\Z)", "", body, flags=re.M | re.S)
    rule = ("\n# MWCC build, then retarget private literal-pool constants to the retail pooled symbols\n"
            "rule mwcc_pool\n"
            f"  command = {cmd} && $python tools/fzgx/poolfix.py $out $poolmap\n"
            + rest.replace("MWCC $out", "MWCC+POOL $out"))
    if "rule mwcc_pool" not in text:
        text = text.replace("\n# MWCC build (with UTF-8 to Shift JIS wrapper)", rule + "\n# MWCC build (with UTF-8 to Shift JIS wrapper)", 1)
    n = 0
    for source, mapping in pool.items():
        stem = source.rsplit(".", 1)[0]
        # Ninja writes the rule inline (`...o: mwcc $`) when it fits the line, and on a
        # continuation line (`...o: $\n    mwcc ... $`) when the output path is long
        # enough. Both forms occur in the same file, so accept either or the pool
        # retargeting is silently skipped for exactly the longest-named units.
        pat = re.compile(
            rf"^(build build/{re.escape(config.version)}/src/{re.escape(stem)}\.o:[ \t]*(?:\$[ \t]*\n[ \t]+)?)"
            rf"mwcc(?=[ \t]|\$)", re.M)
        m = pat.search(text)
        if m:
            poolmap = ",".join(f"{k}={v}" for k, v in sorted(mapping.items()))
            # MWCC local-static symbols contain '$': preserve it through both
            # Ninja expansion and the platform shell.
            poolmap = (subprocess.list2cmdline([poolmap]) if is_windows() else shlex.quote(poolmap)).replace('$', '$$')
            text = text[:m.start()] + m.group(1) + "mwcc_pool" + text[m.end():]
            # the variable block starts on the first indented line after the edge
            vm = re.compile(r"^  \w+ = ", re.M).search(text, m.start())
            if not vm:
                continue
            # A changed retargeter must rebuild these objects even when the C
            # and mapping stay identical. Compiler edges already have an
            # implicit dependency group for the compiler and depfile tool.
            edge = text[m.start():vm.start()]
            if "tools/fzgx/poolfix.py" not in edge:
                updated = edge.replace(" | ", " | tools/fzgx/poolfix.py ", 1)
                if updated == edge:
                    sys.exit("build.ninja: mwcc_pool edge has no implicit dependencies")
                text = text[:m.start()] + updated + text[vm.start():]
                vm = re.compile(r"^  \w+ = ", re.M).search(text, m.start())
            if not re.search(rf"^  poolmap = .*{re.escape(stem)}", text, re.M):
                text = text[:vm.start()] + f"  poolmap = {poolmap}\n" + text[vm.start():]
                n += 1
    ninja_path.write_text(text)
    if n:
        print(f"build.ninja: {n} units compile through mwcc_pool (literal-pool retargeting)")


_DOL_NAMED: List[Any] = []


def dol_library_at(addr: int) -> str:
    """Library group for a DOL address from dtk's signature-named functions in symbols.txt."""
    import re

    if not _DOL_NAMED:
        sym_re = re.compile(r"^(?P<name>\S+) = \.(?:text|init):0x(?P<addr>[0-9A-Fa-f]+); // type:function")
        for line in (Path("config") / config.version / "symbols.txt").read_text().splitlines():
            m = sym_re.match(line)
            if m and not m.group("name").startswith(("fn_", "lbl_")):
                _DOL_NAMED.append((int(m.group("addr"), 16), m.group("name")))
        _DOL_NAMED.sort()
    name = "runtime"
    for a, n in _DOL_NAMED:
        if a > addr:
            break
        name = n
    # known Dolphin SDK / MetroTRK prefixes; everything else is MSL runtime or engine code
    sdk = ("PSMTX", "ARQ", "CARD", "DVD", "DSP", "EXI", "OSDB", "THP", "TRK", "DDH", "MTX", "PPC", "PAD",
           "AX", "AR", "AI", "DB", "DC", "GD", "GX", "IC", "LC", "OS", "SI", "VI")
    n = name.lstrip("_")
    for pfx in sdk:
        if n.startswith(pfx) and (len(n) == len(pfx) or not n[len(pfx)].islower() or pfx in ("OS", "GX", "VI", "SI")):
            return {"OSDB": "os", "PSMTX": "mtx"}.get(pfx, pfx.lower())
    if n[:1].islower():
        return "msl"  # strlen, memcpy, vprintf, wcstombs, usr_put_initialize ...
    return "engine"


def name_auto_units_by_tu() -> None:
    """Rename decomp-toolkit's auto-generated objdiff units into their translation units.

    Unmatched code lives in objects dtk names `auto_00_000D3FDC_text`; objdiff (and the
    decomp.dev treemap, which nests units by path) would show those names. The TU map
    recovered from __FILE__ strings (config/<VERSION>/<module>/tus.json) tells which file
    each address belongs to, so the unit becomes `<module>/rel/<module>/<tu>/_unmatched_<addr>`
    and sits next to that file's matched functions. Only objdiff.json changes; the build does not.
    """
    import json
    import re

    objdiff_path = Path("objdiff.json")
    if not objdiff_path.exists():
        return
    data = json.loads(objdiff_path.read_text())
    tu_maps: Dict[str, List[Dict[str, Any]]] = {}
    for tus_file in (Path("config") / config.version).glob("*/tus.json"):
        d = json.loads(tus_file.read_text())
        tu_maps[d["module"]] = d["tus"]
    pat = re.compile(r"^(?P<module>[^/]+)/auto_\d+_(?P<addr>[0-9A-F]+)_(?P<section>\w+)$")
    renamed = 0
    for unit in data["units"]:
        m = pat.match(unit["name"])
        if not m or not unit.get("metadata", {}).get("auto_generated"):
            continue
        module, addr, section = m.group("module"), int(m.group("addr"), 16), m.group("section")
        if section not in ("text", "init"):
            # data/bss remainder: group under the module (TU data ranges are only known for .data)
            base = "main/dol" if module == "main" else f"{module}/rel/{module}"
            unit["name"] = f"{base}/_data/_unmatched_{section}_{addr:X}"
            renamed += 1
            continue
        if module == "main":
            # DOL: no __FILE__ strings; group by the SDK library of the nearest preceding
            # signature-named function (OSInit -> os, GXBegin -> gx, __DVDFSInit -> dvd, ...)
            unit["name"] = f"main/dol/{dol_library_at(addr)}/_unmatched_{addr:X}"
            renamed += 1
            continue
        tus = tu_maps.get(module)
        if not tus:  # no __FILE__ anchors in this REL: at least group by module
            unit["name"] = f"{module}/rel/{module}/_unmatched_{addr:X}"
            renamed += 1
            continue
        tu = next((t for t in tus if t["text"][0] <= addr < t["text"][1]), None)
        stem = tu["file"].rsplit(".", 1)[0] if tu else "_prolog"
        unit["name"] = f"{module}/rel/{module}/{stem}/_unmatched_{addr:X}"
        renamed += 1
    objdiff_path.write_text(json.dumps(data, indent=2) + "\n")
    if renamed:
        print(f"objdiff.json: {renamed} auto-generated code units named by translation unit")


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # MWCC's SDK absolute declarations share their address definitions with the linker.
    template = Path(f"config/{args.version}/ldscript.tpl")
    if template.exists():
        addresses = re.findall(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", template.read_text(), re.M)
        header = args.build_dir / args.version / "include/sdk_addresses.h"
        content = "/* Generated from ldscript.tpl by configure.py. */\n" + "".join(
            f"#define FZGX_ADDR_{name} {address}\n" for name, address in addresses)
        header.parent.mkdir(parents=True, exist_ok=True)
        if not header.exists() or header.read_text() != content:
            header.write_text(content)
    # Write build.ninja and objdiff.json
    # pool units keep their own edge: apply_pool_rules rewrites it to mwcc_pool by name
    config.ungrouped_sources = {"src/" + u["source"] if not u.get("tu") else f"build/{config.version}/gen/{u['source']}"
                                for u in version_units() if isinstance(u.get("pool"), dict) and u["pool"]}
    generate_build(config)
    add_pool_rules()
    name_auto_units_by_tu()
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
