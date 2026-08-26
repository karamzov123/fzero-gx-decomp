# F-Zero GX — GFZE01 matching decompilation

[![Build report](https://github.com/karamzov123/fzero-gx-decomp/actions/workflows/report.yml/badge.svg)](https://github.com/karamzov123/fzero-gx-decomp/actions/workflows/report.yml) [![Code progress](https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=code&label=Exact%20natural%20C)](https://decomp.dev/karamzov123/fzero-gx-decomp)

This repository is a from-scratch, matching decompilation project for the NTSC-U GameCube release of F-Zero GX. The goal is source code that rebuilds the original code and data as closely as possible while keeping the source readable and provenance explicit.

## At a glance

| Release | Game ID | Artifact | Input SHA-1 |
| --- | --- | --- | --- |
| NTSC-U | `GFZE01` | `main.dol` | `421c88106697d3275a3fc26fb7a01bf6d816b271` |

The SHA-1 above is the checksum of the matching input recorded in [`config/GFZE01/build.sha1`](config/GFZE01/build.sha1). The retail binary, proprietary compiler distribution, and other non-redistributable inputs are intentionally not included.

## Object map

The project is organized around the objects that make up `main.dol`. Each object is split into symbols and source units through the [`GFZE01 split map`](config/GFZE01/splits.txt), then rebuilt by the GameCube toolchain.

```text
main.dol (GFZE01)
├── Dolphin SDK
│   ├── ai, ar, ax, card, dsp, dvd
│   ├── gx, mtx, os, pad, vi
│   └── metrotrk, msl, trk
├── F-Zero GX game code
│   └── src/game
└── Unmatched or investigative sources
    └── src/non_matchings
```

The map is intentionally a source-oriented view: the split file remains the authoritative inventory of retail objects, addresses, symbols, and section boundaries.

## Current progress

Progress is published through the GitHub Actions `GFZE01_report` artifact and tracked on [decomp.dev](https://decomp.dev/karamzov123/fzero-gx-decomp). The public report separates:

- **Exact natural C** — the project mission metric.
- **C-expressed** — supplemental fuzzy progress for C-backed functions.
- **Diagnostic objdiff** — whole-binary parity, including hand-written assembly; useful for build health, but not the decompilation headline.

See the [GFZE01 symbols](config/GFZE01/symbols.txt), [split map](config/GFZE01/splits.txt), and [split documentation](docs/splits.md) for the project inventory.

## How is the codebase structured?

The code in [`src`](src) is divided into the Dolphin SDK, F-Zero GX game code, and explicitly separated non-matching or investigative material. The source tree follows the broad subsystems visible in the original binary.

### `src/dolphin`

These directories contain SDK and runtime components linked into the game:

| Short | Full | Notes |
| --- | --- | --- |
| `ai` | Audio interface | Audio hardware interface. |
| `ar` | Audio RAM | Audio memory and DMA support. |
| `ax` | Audio mixer | GameCube audio mixer and voices. |
| `card` | Memory Card | Memory Card filesystem and I/O. |
| `dsp` | DSP | Digital signal processor support. |
| `dvd` | DVD | Disc filesystem and low-level DVD access. |
| `gx` | GX | Flipper graphics API. |
| `metrotrk` | MetroTRK | Metrowerks debugger/runtime support. |
| `msl` | MSL | Metrowerks Standard Library. |
| `mtx` | Matrix | Vector and matrix math. |
| `os` | Operating system | Dolphin OS services and initialization. |
| `pad` | Controller | GameCube controller input. |
| `trk` | Target Resident Kernel | Debugger event and transport support. |
| `vi` | Video interface | Display timing and video interface. |

### `src/game`

The game-specific sources are grouped by reconstructed subsystem and are progressively moving from address-based names toward semantic names as their behavior becomes understood. See [`splits.txt`](config/GFZE01/splits.txt) for the complete retail object map.

### `src/non_matchings`

This directory contains deliberately isolated experiments, candidate reconstructions, and investigation notes. It is not counted as exact natural C unless a source is promoted into the matching tree and passes the project’s provenance and build gates.

## Project layout

- `src/` — reconstructed C and assembly sources
- `config/GFZE01/` — build version, symbols, split definitions, and input hash
- `tools/` — public build/report tooling
- `tests/` — regression tests for public tooling
- `docs/` — setup, split, provenance, and resource documentation
- `.github/workflows/report.yml` — trusted-main progress report workflow

## Getting started

This is an active matching project rather than a ready-to-run ROM build. Start with:

1. Read [Getting Started](docs/getting_started.md).
2. Review [Dependencies](docs/dependencies.md).
3. Inspect `config/GFZE01/splits.txt` and `config/GFZE01/symbols.txt`.
4. Read the [reference and readability policy](docs/REFERENCE-POLICY.md).
5. Check [decomp.dev](https://decomp.dev/karamzov123/fzero-gx-decomp) for progress and the repository Actions tab for report runs.

For individual difficult functions, [decomp.me](https://decomp.me) provides shareable matching scratches; it works on individual functions, not full binaries.

## Contributing

Please keep changes focused and reproducible. Preserve the existing symbol/split conventions, do not commit copyrighted game assets or private environment files, and document adapted code with provenance as described in the policy. Discussion and review are welcome through the GameCube/Wii decompilation community.

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

## Disclaimer

F-Zero GX and related trademarks are property of their respective rights holders. This repository is an educational and research project and does not distribute the game, game assets, or proprietary compiler binaries.
