#!/usr/bin/env python3
"""Inventory a legally extracted GFZE01 game tree.

This is deliberately an inventory tool, not a ROM extractor.  It records the
files needed to define the full executable decompilation target without copying
copyrighted game data into the repository.
"""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
from typing import Any

# The NTSC-U build dynamically loads these game-code modules from bg/.  Keep
# this list explicit: a scan that notices only sample.rel would still omit most
# of the game's executable code.
REQUIRED = {
    "main.dol": {"kind": "dol", "names": {"main.dol"}},
    "line__.bin": {"kind": "encrypted-lz-container", "names": {"line__.bin"}},
    "main.rel": {"kind": "rel", "names": {"main.rel"}},
    **{
        name: {"kind": "rel", "names": {name}}
        for name in (
            "fze.car_colchg.rel",
            "fze.customize.rel",
            "fze.interview.rel",
            "fze.movie.rel",
            "fze.movie_module.rel",
            "fze.option.rel",
            "fze.pilotpoint.rel",
            "fze.profile.rel",
            "fze.replay.rel",
            "fze.sample.rel",
            "fze.sel.rel",
            "fze.story.rel",
            "fze.title.rel",
            "fze.winning.rel",
        )
    },
}


def _digest(path: Path) -> str:
    digest = hashlib.sha1()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def inventory_game(root: Path) -> dict[str, Any]:
    root = root.resolve()
    files = sorted(path for path in root.rglob("*") if path.is_file())
    required: dict[str, dict[str, Any]] = {}
    missing: list[str] = []

    for label, spec in REQUIRED.items():
        matches = [path for path in files if path.name.lower() in spec["names"]]
        if not matches:
            missing.append(label)
            continue
        # Multiple matches are ambiguous and must be resolved by the caller.
        if len(matches) > 1:
            raise ValueError(
                f"ambiguous {label}: "
                + ", ".join(str(path.relative_to(root)) for path in matches)
            )
        path = matches[0]
        required[label] = {
            "path": path.relative_to(root).as_posix(),
            "kind": spec["kind"],
            "size": path.stat().st_size,
            "sha1": _digest(path),
        }

    return {
        "schema": 1,
        "game_id": "GFZE01",
        "scope": "full-executable-game",
        "complete": not missing,
        "missing_required": missing,
        "required": required,
        "file_count": len(files),
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path, help="extracted game/disc root")
    parser.add_argument("--output", type=Path, help="write JSON instead of stdout")
    args = parser.parse_args()
    report = inventory_game(args.root)
    rendered = json.dumps(report, indent=2, sort_keys=True) + "\n"
    if args.output:
        args.output.write_text(rendered, encoding="utf-8")
    else:
        print(rendered, end="")
    return 0 if report["complete"] else 2


if __name__ == "__main__":
    raise SystemExit(main())
