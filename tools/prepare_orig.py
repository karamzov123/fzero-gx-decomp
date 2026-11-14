#!/usr/bin/env python3
"""Derive main.rel from enemy_line/line__.bin and verify every matching input.

Run after dropping a disc image (or extracted files) into orig/<VERSION>/:

  uv run tools/prepare_orig.py --version GFZE01

Steps:
  1. Locate the disc image or extracted tree under orig/<VERSION>/.
  2. Pull files/enemy_line/line__.bin (via dtk's VFS when a disc image is present).
  3. Decrypt (linecrypt) -> main.rel.lz, decompress (avlz) -> main.rel.
  4. Assert the cipher round-trips byte-exact and report whether our
     compressor reproduces the original .lz (tools/build_disc.py needs it).
  5. Write orig/<VERSION>/files/enemy_line/main.rel and print the SHA-1 of
     every matching target for config/<VERSION>/build.sha1.

Run it as a script from anywhere: the tools/ directory is the script
directory, so the sibling modules import without path tricks.
"""

from __future__ import annotations

import argparse
import hashlib
import subprocess
import sys
from pathlib import Path

import avlz
import linecrypt

ROOT = Path(__file__).resolve().parent.parent
DISC_EXTS = (".rvz", ".iso", ".gcm", ".wia", ".ciso", ".gcz", ".nfs", ".tgc")
REGION_BY_VERSION = {"GFZE01": "INT", "GFZP01": "INT", "GFZJ01": "JPN"}
# REL file prefix on each disc: fze.*.rel (USA), fzp.*.rel (PAL), fz.*.rel (JPN).
REL_PREFIX = {"GFZE01": "fze", "GFZP01": "fzp", "GFZJ01": "fz"}
REL_NAMES = [
    "car_colchg", "customize", "interview", "movie", "movie_module", "option",
    "pilotpoint", "profile", "replay", "sample", "sel", "story", "title", "winning",
]


def sha1(data: bytes) -> str:
    return hashlib.sha1(data).hexdigest()


def find_dtk() -> Path:
    local = ROOT / "build" / "tools" / "dtk"
    if local.exists():
        return local
    raise SystemExit("dtk not found; run configure.py once or place it in build/tools/dtk")


def read_disc_file(orig: Path, rel_path: str) -> bytes:
    """Return a disc file, extracting it into orig/<VERSION>/ from a disc image if needed.

    The disc image itself must live in orig/ (not orig/<VERSION>/): decomp-toolkit
    switches to reading objects straight from an image found in object_base, and
    main.rel is not on the disc, so the build must see an extracted tree.
    """
    extracted = orig / rel_path
    if extracted.exists():
        return extracted.read_bytes()
    images = sorted(p for p in orig.parent.iterdir() if p.suffix.lower() in DISC_EXTS)
    # With several versions' images in orig/, prefer the raw image whose header
    # game ID (first 6 bytes) is this version; compressed formats are kept as fallback.
    def header_id(p: Path) -> str:
        if p.suffix.lower() not in (".iso", ".gcm"):
            return ""
        with p.open("rb") as f:
            return f.read(6).decode("ascii", "replace")
    raw = {p: header_id(p) for p in images}
    if any(raw.values()):
        images = [p for p in images if raw[p] == orig.name] + [p for p in images if not raw[p]]
    if not images:
        raise SystemExit(f"{rel_path} not found under {orig} and no disc image in {orig.parent}")
    extracted.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([str(find_dtk()), "vfs", "cp", f"{images[0]}:{rel_path}", str(extracted)],
                   check=True, capture_output=True)
    return extracted.read_bytes()


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--version", default="GFZE01", choices=sorted(REGION_BY_VERSION))
    args = ap.parse_args(argv)
    orig = ROOT / "orig" / args.version
    region = REGION_BY_VERSION[args.version]

    line_bin = read_disc_file(orig, "files/enemy_line/line__.bin")
    lz = linecrypt.crypt(line_bin, region)
    if linecrypt.crypt(lz, region) != line_bin:
        raise SystemExit("cipher round-trip failed")
    rel = avlz.decompress(lz)
    ours = avlz.compress(rel)
    if avlz.decompress(ours) != rel:
        raise SystemExit("our compressor output does not decode back to main.rel")

    dest = orig / "files" / "enemy_line" / "main.rel"
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_bytes(rel)

    print(f"line__.bin  {len(line_bin):9d} bytes  sha1 {sha1(line_bin)}")
    print(f"main.rel.lz {len(lz):9d} bytes  sha1 {sha1(lz)}")
    print(f"main.rel    {len(rel):9d} bytes  sha1 {sha1(rel)}  -> {dest.relative_to(ROOT)}")
    print(f"compressor reproduces original .lz: {'yes' if ours == lz else 'no'} "
          f"(ours {len(ours)} bytes, original {len(lz)} bytes)")
    print()
    print("targets:")
    print(f"  {sha1(read_disc_file(orig, 'sys/main.dol'))}  sys/main.dol")
    prefix = REL_PREFIX[args.version]
    for name in REL_NAMES:
        p = f"files/{prefix}.{name}.rel"
        try:
            print(f"  {sha1(read_disc_file(orig, p))}  {p}")
        except subprocess.CalledProcessError:
            print(f"  {'-' * 40}  {p} (missing)")
    print(f"  {sha1(rel)}  files/enemy_line/main.rel")
    return 0


if __name__ == "__main__":
    sys.exit(main())
