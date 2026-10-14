F-Zero GX
[![Build Status]][actions] [![Code Progress]][progress] [![Fuzzy Match]][progress] [![DOL Progress]][progress] [![RELs Progress]][progress] [![Data Progress]][progress] [![Discord Badge]][discord]
=========

[Build Status]: https://github.com/karamzov123/fzgx/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/karamzov123/fzgx/actions/workflows/build.yml
[Code Progress]: https://decomp.dev/karamzov123/fzgx.svg?mode=shield&measure=code&label=Code&category=all
[Fuzzy Match]: https://decomp.dev/karamzov123/fzgx.svg?mode=shield&measure=fuzzy_match&label=Fuzzy&category=all
[DOL Progress]: https://decomp.dev/karamzov123/fzgx.svg?mode=shield&measure=code&label=DOL&category=dol
[RELs Progress]: https://decomp.dev/karamzov123/fzgx.svg?mode=shield&measure=code&label=RELs&category=modules
[Data Progress]: https://decomp.dev/karamzov123/fzgx.svg?mode=shield&measure=data&label=Data
[progress]: https://decomp.dev/karamzov123/fzgx
[Discord Badge]: https://img.shields.io/discord/727908905392275526?color=%237289DA&logo=discord&logoColor=%23FFFFFF
[discord]: https://discord.gg/hKx3FJJgrV

[<img src="https://decomp.dev/karamzov123/fzgx.svg?w=1024&h=320" width="1024" height="320" alt="Live progress treemap">][progress]

A work-in-progress matching decompilation of F-Zero GX for the Nintendo GameCube.

This repository does **not** contain any game assets or assembly whatsoever. An existing copy of the game is required.

Supported versions:

- `GFZE01`: Rev 0 (USA) — primary
- `GFZP01`: Rev 0 (PAL) — configuration scaffold only
- `GFZJ01`: Rev 0 (JPN) — configuration scaffold only

What is being matched
=====================

The disc ships sixteen executables and this project rebuilds every one of them byte for byte:

| Target | Role |
|---|---|
| `sys/main.dol` | Loader and engine core: Dolphin SDK, MSL, MetroTRK, CRI ADX, AX |
| `main.rel` | Almost half of all code: physics, racing, machines, AI, in-race logic. Not on the disc as a file: it is the encrypted, LZ-compressed archive `files/enemy_line/line__.bin`, which `tools/prepare_orig.py` decrypts and decompresses |
| `files/fze.*.rel` (14) | Title, selection, customise, story, ranking, replay, memory card, movie and other screens |
| `files/fze.sample.rel` | The stub that locates, decrypts and links `main.rel` |

`ninja` ends with `16 files OK` when every target hashes identically to the retail files.

Source is organised by recovered translation unit. main.rel embeds its original file names (`camera.c`, `coli.c`, `car.c`, `driver.c`, `enemy_ctrl.c`, ...), and the order of those strings in `.data` matches the order of the code that references them, so each function is placed under `src/rel/main_rel/<file>/`. Struct layouts for the most-referenced globals are recovered from every access in the disassembly and generated into `include/rel/main_rel/globals.h`, with every field offset proven under the original compiler.

How the matching is done
========================

This project is an experiment in agent-driven matching. A matching decompilation has a perfect oracle: the object either assembles to the retail bytes or it does not. Most functions are therefore matched by many cheap language-model agents, one function each, iterating compile-and-diff through a small tool surface (`tools/fzgx.py`, exposed to agents as an MCP server) until objdiff reports 100% and the full link still hashes identical. Agents cannot run a shell, edit anything but their own unit, or hardcode an address; every accepted function is byte-verified before it is committed. Naming, types and translation-unit structure are separate passes with their own tooling, and the tree carries no assembly at all: unmatched code stays in decomp-toolkit's split objects until it is matched in C.

Because of this, contributions here are held to the artifact, not the author: a change is acceptable when it matches, passes lint, and reads like code a person would write. See [Contributing](#contributing).

Dependencies
============

Windows
--------

On Windows, it's **highly recommended** to use native tooling. WSL or msys2 are **not** required.  
When running under WSL, [objdiff](#diffing) is unable to get filesystem notifications for automatic rebuilds.

- Install [Python](https://www.python.org/downloads/) and add it to `%PATH%`.
  - Also available from the [Windows Store](https://apps.microsoft.com/store/detail/python-311/9NRWMJP3717K).
- Download [ninja](https://github.com/ninja-build/ninja/releases) and add it to `%PATH%`.
  - Quick install via pip: `pip install ninja`

macOS
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages):

  ```sh
  brew install ninja
  ```

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used (under Rosetta 2 on Apple Silicon).

Linux
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages).

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

All platforms
-------------

- Install [uv](https://docs.astral.sh/uv/) for the project tooling (`tools/`).

Building
========

- Clone the repository:

  ```sh
  git clone https://github.com/rayanht/fzgx.git
  ```

- Copy your game's disc image to `orig/` (not `orig/GFZE01/`).
  - Supported formats: ISO (GCM), RVZ, WIA, WBFS, CISO, NFS, GCZ, TGC
  - `dtk disc verify` should report a Redump match.

- Extract the targets and derive `main.rel`:

  ```sh
  uv run tools/prepare_orig.py --version GFZE01
  ```

  This pulls the sixteen targets out of the image into `orig/GFZE01/`, decrypts and decompresses `line__.bin`, and prints the SHA-1 of each target. The disc image can be deleted afterwards.

- Configure:

  ```sh
  python configure.py
  ```

  To use a version other than `GFZE01` (USA), specify it with `--version`.

- Build:

  ```sh
  ninja
  ```

Diffing
=======

Once the initial build succeeds, an `objdiff.json` should exist in the project root.

Download the latest release from [encounter/objdiff](https://github.com/encounter/objdiff). Under project settings, set `Project directory`. The configuration should be loaded automatically.

Select an object from the left sidebar to begin diffing. Changes to the project will rebuild automatically: changes to source files, headers, `configure.py`, `splits.txt` or `symbols.txt`.

Contributing
============

See [CONTRIBUTING.md](CONTRIBUTING.md). In short: one function per change, matched and link-verified through `tools/fzgx.py`, no hardcoded addresses, no inline assembly, readable C. Both people and agents go through the same tools and the same oracle. Questions and discussion: the [GC/Wii Decompilation Discord][discord], `#dtk`.

Credits
=======

See [docs/RESOURCES.md](docs/RESOURCES.md). This project stands on [decomp-toolkit](https://github.com/encounter/decomp-toolkit), [objdiff](https://github.com/encounter/objdiff), [wibo](https://github.com/decompals/wibo) and [dtk-template](https://github.com/encounter/dtk-template) by encounter and the decompals community, on CosmoCortney's [Line__Crypt](https://github.com/CosmoCortney/Line__Crypt) and bobjrsenior's [SMB_LZ_Tool](https://github.com/bobjrsenior/SMB_LZ_Tool) for the `line__.bin` format, and on a decade of format work by the F-Zero GX modding community.

License
=======

The source code and tooling in this repository are released under [CC0 1.0](LICENSE). F-Zero GX is © Nintendo / Sega / Amusement Vision; no game data is distributed here.
