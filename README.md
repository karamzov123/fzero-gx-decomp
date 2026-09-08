# F-Zero GX — GFZE01 matching decompilation

[![Build](https://github.com/karamzov123/fzero-gx-decomp/actions/workflows/report.yml/badge.svg?style=flat-square)](https://github.com/karamzov123/fzero-gx-decomp/actions/workflows/report.yml) [![Exact natural C](https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=matched_functions&category=natural-c&label=Exact%20natural%20C)](https://decomp.dev/karamzov123/fzero-gx-decomp) [![Diagnostic](https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=code&label=Diagnostic%20objdiff)](https://decomp.dev/karamzov123/fzero-gx-decomp) [![Game ID](https://img.shields.io/badge/Game%20ID-GFZE01-21262d?style=flat-square)](config/GFZE01) [![Platform](https://img.shields.io/badge/Platform-GameCube-21262d?style=flat-square)](docs/getting_started.md) [![Region](https://img.shields.io/badge/Region-NTSC--U-21262d?style=flat-square)](config/GFZE01)

This repository is a from-scratch, matching decompilation project for the NTSC-U GameCube release of F-Zero GX (`GFZE01`). The goal is source code that rebuilds the original code and data as closely as possible while keeping the source readable and provenance explicit.

The executable target is the complete GFZE01 code set: `sys/main.dol`,
14 direct `bg/fze.*.rel` modules, and the encrypted/LZ-packed
`bg/enemy_line/line__.bin`, which produces `bg/enemy_line/main.rel` (REL
module ID 1). The extracted target therefore contains 16 executable images.

| Version | Game ID | SHA-1 |
| --- | --- | --- |
| NTSC-U | `GFZE01` | `421c88106697d3275a3fc26fb7a01bf6d816b271` |

The SHA-1 is the checksum of the matching input recorded in [`config/GFZE01/build.sha1`](config/GFZE01/build.sha1).

## Scope

This project means the entire executable decompilation, not merely the boot
image. GFZE01 has 14 direct game-code RELs plus the encrypted/LZ-packed
`bg/enemy_line/line__.bin`, which contains the 2,221,812-byte `main.rel`.
All 16 executable images are required by the target manifest in
[`config/GFZE01/modules.yml`](config/GFZE01/modules.yml).

Current reality: all 16 executable inputs are now extracted and configured. The
DOL has existing natural-C coverage; the 15 REL images are present in the
full-target report but currently have no natural-C source units. Disc assets are
inventoried for completeness but are not C decompilation targets and are never
committed.

## Current progress

Progress is published through the GitHub Actions `GFZE01_report` artifact and tracked on [decomp.dev](https://decomp.dev/karamzov123/fzero-gx-decomp). The public report separates:

- **Exact natural C** — the project mission metric: functions with a real C body that assembles to the retail bytes exactly. Hand-written `asm` bodies, gap and padding symbols do not count.
- **C-expressed** — the same set weighted by partial match, for work in progress.
- **Diagnostic objdiff** — whole-binary parity, including hand-written assembly; useful for build health, but not the decompilation headline.
- **Game Code** / **SDK Code** — the mission metric split between F-Zero GX's own code and the Dolphin SDK it links against.

A unit counts as complete only when it is fully converted: no `asm` body is left in its source and every function in it matches.

See the [GFZE01 module manifest](config/GFZE01/modules.yml), [symbols](config/GFZE01/symbols.txt), [split map](config/GFZE01/splits.txt), and [split documentation](docs/splits.md) for the project inventory. Run `python3 tools/game_inventory.py <extracted-game-root>` before treating the executable inventory as complete.

![F-Zero GX GFZE01 codebase map](assets/codebase-map.svg)

*The diagram is a navigational overview; the [split map](config/GFZE01/splits.txt) remains authoritative for retail objects and addresses.*

## Project layout

- `src/` — reconstructed C and assembly sources
- `config/GFZE01/` — build version, module manifest, symbols, and split definitions
- `tools/` — public build/report tooling
- `tests/` — regression tests for the public tooling in `tools/`
- `docs/` — setup, split, provenance, and resource documentation
- `.github/workflows/report.yml` — trusted-main progress report workflow

The retail binary, proprietary compiler distribution, and other non-redistributable inputs are intentionally not included. A local build requires legally obtained matching inputs and the appropriate GameCube toolchain.


## Getting started

This is an active matching project rather than a ready-to-run ROM build. Start with:

1. Read [Getting Started](docs/getting_started.md).
2. Review [Dependencies](docs/dependencies.md).
3. Inspect `config/GFZE01/splits.txt` and `config/GFZE01/symbols.txt`.
4. Read the [reference and readability policy](docs/REFERENCE-POLICY.md).
5. Check [decomp.dev](https://decomp.dev/karamzov123/fzero-gx-decomp) for progress and the repository Actions tab for report runs.

For individual difficult functions, [decomp.me](https://decomp.me) provides shareable matching scratches; it works on individual functions, not full binaries.

### Running the tests

```sh
python -m unittest discover -s tests
```

This covers the public build and report tooling in `tools/`. It does not build
or verify the DOL — that needs the legally obtained matching inputs and the
toolchain described in [Getting Started](docs/getting_started.md).


## Contributing

Pull requests against `main` here are the way in, and they stick: this repository is the source of truth for the source tree, not a generated mirror. Merged work keeps its author's name on it.

Please keep changes focused and reproducible. Preserve the existing symbol/split conventions, do not commit copyrighted game assets or private environment files, and document adapted code with provenance as described in the policy. A short note under `docs/contributions/<name>/CARD.md` recording your provenance and how you verified the match is welcome and will be published with the change.

A branch named `sync/from-private` appears here from time to time. That is the maintainer's working tree proposing changes through the same PR route; it never writes to `main` directly.

Discussion and review are welcome through the GameCube/Wii decompilation community.

## Resources and attributions

This project builds on the following public resources and tools:

- [decomp-toolkit](https://github.com/encounter/decomp-toolkit) — GameCube/Wii project tooling and DOL splitting
- [dtk-template](https://github.com/encounter/dtk-template) — standard GameCube/Wii project structure and workflow reference
- [objdiff](https://github.com/encounter/objdiff) — object comparison and progress reporting
- [wibo](https://github.com/decompals/wibo) — Win32 compatibility wrapper used for MWCC workflows on Linux
- [sjiswrap](https://github.com/encounter/sjiswrap) — Shift-JIS compiler-input wrapper
- [decomp.me](https://decomp.me) — collaborative function-level matching scratches
- [decomp.dev](https://decomp.dev) — progress-report ecosystem
- [doldecomp/dolsdk2001](https://github.com/doldecomp/dolsdk2001) — Dolphin SDK matching reference
- [doldecomp/melee](https://github.com/doldecomp/melee) — reference decompilation tree
- [doldecomp/sms](https://github.com/doldecomp/sms) — Super Mario Sunshine reference tree
- [doldecomp/mkdd](https://github.com/doldecomp/mkdd) — Mario Kart: Double Dash!! reference tree

See [ONLINE-RESOURCES.md](docs/ONLINE-RESOURCES.md) and [REFERENCE-POLICY.md](docs/REFERENCE-POLICY.md) for the detailed attribution and adaptation rules.
