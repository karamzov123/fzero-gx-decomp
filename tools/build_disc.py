#!/usr/bin/env python3
"""Rebuild the retail disc image with every executable taken from the build.

  uv run tools/build_disc.py --version GFZE01 [--image orig/disc.iso] [--out build/GFZE01/disc.iso]

The decomp builds code only; game assets stay on the user's disc. This tool
starts from the user's own raw disc image (.iso/.gcm, the same image
prepare_orig.py reads), replaces the 16 executables with the build outputs and
writes a new image:

  sys/main.dol                   <- build/<VERSION>/main.dol
  files/fze.<module>.rel  (14)   <- build/<VERSION>/<module>/<module>.rel
                                    (fzp.* on PAL, fz.* on JPN)
  files/enemy_line/line__.bin    <- build/<VERSION>/main_rel/main_rel.rel,
                                    compressed (avlz) and encrypted (linecrypt)

It then compares every replaced file and the whole image against the input.
When the build matches, the rebuilt image is byte-identical to the retail
disc. Disc layout (header, apploader, FST, inter-file filler) and all assets
are copied from the input image; nothing is generated, so file sizes must match
the disc's FST entries.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
import sys
from pathlib import Path

import avlz
import linecrypt

ROOT = Path(__file__).resolve().parent.parent
RAW_EXTS = (".iso", ".gcm")
REGION_BY_VERSION = {"GFZE01": "INT", "GFZP01": "INT", "GFZJ01": "JPN"}
# REL file prefix on each disc: fze.*.rel (USA), fzp.*.rel (PAL), fz.*.rel (JPN).
REL_PREFIX = {"GFZE01": "fze", "GFZP01": "fzp", "GFZJ01": "fz"}
REL_NAMES = [
    "car_colchg", "customize", "interview", "movie", "movie_module", "option",
    "pilotpoint", "profile", "replay", "sample", "sel", "story", "title", "winning",
]


def sha1(data: bytes | bytearray) -> str:
    return hashlib.sha1(data).hexdigest()


def _game_id(path: Path) -> str:
    with path.open("rb") as f:
        return f.read(6).decode("ascii", "replace")


def find_image(version: str) -> Path:
    orig = ROOT / "orig"
    for base in (orig, orig / version):
        if base.is_dir():
            for p in sorted(base.iterdir()):
                if p.suffix.lower() in RAW_EXTS and _game_id(p) == version:
                    return p
    raise SystemExit(f"no raw {version} disc image ({', '.join(RAW_EXTS)}) under {orig}; pass --image")


def read_fst(img: bytes) -> dict[str, tuple[int, int]]:
    """Map disc path (relative to files/) -> (offset, size)."""
    be = lambda o: struct.unpack_from(">I", img, o)[0]
    fst = be(0x424)
    count = be(fst + 8)
    names = fst + count * 12
    files: dict[str, tuple[int, int]] = {}

    def name(off: int) -> str:
        start = names + off
        return img[start:img.index(b"\0", start)].decode("shift_jis")

    def walk(i: int, end: int, prefix: str) -> None:
        while i < end:
            entry = fst + i * 12
            is_dir = img[entry] != 0
            a, b = be(entry + 4), be(entry + 8)
            n = name(be(entry) & 0xFFFFFF)
            if is_dir:
                walk(i + 1, b, prefix + n + "/")
                i = b
            else:
                files[prefix + n] = (a, b)
                i += 1

    walk(1, count, "")
    return files


def dol_extent(img: bytes) -> tuple[int, int]:
    be = lambda o: struct.unpack_from(">I", img, o)[0]
    base = be(0x420)
    size = 0
    for k in range(18):
        off, length = be(base + k * 4), be(base + 0x90 + k * 4)
        if off:
            size = max(size, off + length)
    return base, size


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--version", default="GFZE01", choices=sorted(REGION_BY_VERSION))
    ap.add_argument("--image", type=Path, help="raw retail disc image (default: first .iso/.gcm under orig/)")
    ap.add_argument("--out", type=Path, help="output image (default: build/<VERSION>/disc.iso)")
    args = ap.parse_args(argv)

    image = args.image or find_image(args.version)
    out = args.out or ROOT / "build" / args.version / "disc.iso"
    build = ROOT / "build" / args.version
    region = REGION_BY_VERSION[args.version]
    prefix = REL_PREFIX[args.version]

    retail = image.read_bytes()
    img = bytearray(retail)
    files = read_fst(retail)

    targets: list[tuple[str, int, int, bytes]] = []
    off, size = dol_extent(retail)
    targets.append(("sys/main.dol", off, size, (build / "main.dol").read_bytes()))
    for mod in REL_NAMES:
        path = f"{prefix}.{mod}.rel"
        off, size = files[path]
        targets.append((f"files/{path}", off, size, (build / mod / f"{mod}.rel").read_bytes()))
    off, size = files["enemy_line/line__.bin"]
    main_rel = (build / "main_rel" / "main_rel.rel").read_bytes()
    targets.append(("files/enemy_line/line__.bin", off, size,
                    linecrypt.crypt(avlz.compress(main_rel), region)))

    bad = 0
    for path, off, size, data in targets:
        same = data == retail[off:off + size]
        if len(data) != size:
            print(f"  SIZE  {path}: build {len(data)} bytes, disc {size} bytes (FST not rewritten)")
            bad += 1
            continue
        img[off:off + size] = data
        print(f"  {'OK  ' if same else 'DIFF'}  {path}")
        bad += not same

    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(img)
    ours, theirs = sha1(img), sha1(retail)
    print(f"{out.relative_to(ROOT) if out.is_relative_to(ROOT) else out}: sha1 {ours}")
    print(f"retail image: sha1 {theirs} -> {'IDENTICAL' if ours == theirs else 'DIFFERS'}")
    return 0 if ours == theirs and not bad else 1


if __name__ == "__main__":
    sys.exit(main())
