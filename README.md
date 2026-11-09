# F-Zero GX

[![Build Status]][actions] [![Code Progress]][progress] [![Fuzzy Match]][progress] [![DOL Progress]][progress] [![RELs Progress]][progress] [![Data Progress]][progress] [![Discord Badge]][discord]

[Build Status]: https://github.com/karamzov123/fzero-gx-decomp/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/karamzov123/fzero-gx-decomp/actions/workflows/build.yml
[Code Progress]: https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=code&label=Code&category=all
[Fuzzy Match]: https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=fuzzy_match&label=Fuzzy&category=all
[DOL Progress]: https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=code&label=DOL&category=dol
[RELs Progress]: https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=code&label=RELs&category=modules
[Data Progress]: https://decomp.dev/karamzov123/fzero-gx-decomp.svg?mode=shield&measure=data&label=Data
[progress]: https://decomp.dev/karamzov123/fzero-gx-decomp
[Discord Badge]: https://img.shields.io/discord/727908905392275526?color=%237289DA&logo=discord&logoColor=%23FFFFFF
[discord]: https://discord.gg/hKx3FJJgrV

[<img src="https://decomp.dev/karamzov123/fzero-gx-decomp.svg?w=1024&h=320" width="1024" height="320" alt="Live progress treemap">][progress]

A matching decompilation of **F-Zero GX** (2003) for the Nintendo GameCube.

The goal of this project is to reconstruct readable, maintainable, matching C source code that faithfully reproduces every byte of all 16 retail executables when compiled with the original Metrowerks CodeWarrior compiler toolchain.

> [!IMPORTANT]
> This repository does **not** contain any copyrighted game assets, binary dumps, or ROM files. A legally obtained copy of the retail game is required to extract the original targets and build the project.

---

## Current Status

- **Code Matched:** **98.53%** (7,272 / 7,312 functions authored in C)
- **Target Executables:** **16 / 16** link cleanly and match the retail SHA-1 hashes byte for byte (`16 files OK`)
- **DOL Core:** **98.61%** code matched
- **Relocatable Modules:** **98.51%** code matched

### Supported Versions

| Game ID | Region | Revision | Status |
|---|---|---|---|
| `GFZE01` | North America (NTSC-U) | Rev 0 | **Primary target** (all 16 targets verified) |
| `GFZP01` | Europe (PAL) | Rev 0 | Configuration scaffold |
| `GFZJ01` | Japan (NTSC-J) | Rev 0 | Configuration scaffold |

---

## What Is Being Matched

The retail disc contains **16 distinct PowerPC executables**. Every single one of them is built and byte-verified by the build system:

| Target | Description | Size / Scope |
|---|---|---|
| `sys/main.dol` | Main game executable and engine core: Dolphin SDK, MetroTRK debugger, MSL runtime, CRI ADX audio, AXFX sound engine. | ~2.9 MB |
| `main.rel` | In-race gameplay engine: vehicle physics, camera, track collision, AI, machine customization, rendering. Reconstructed from `files/enemy_line/line__.bin` (encrypted and LZ-compressed on disc). | ~2.3 MB |
| `files/fze.*.rel` (14) | Relocatable game modules: title, pilotpoint, customisation, story, replay, memory card, sound, movie player, options, and menu screens. | ~1.8 MB total |
| `files/fze.sample.rel` | Bootstrap loader that locates, decrypts, and dynamically links `main.rel` into memory at runtime. | ~16 KB |

The build finishes with `16 files OK` when all targets match their respective retail SHA-1 checksums.

---

## Repository Structure

```
fzero-gx-decomp/
├── config/                  # Decomp-toolkit configurations, symbol maps, and splits
│   ├── GFZE01/              # USA Rev 0 target configuration
│   │   ├── main_rel/        # Symbols and splits for main.rel
│   │   ├── splits.txt       # Split object boundary definitions
│   │   ├── symbols.txt      # Global symbol definitions and addresses
│   │   └── units.json       # Database of matching C units and compiler flags
│   └── ...                  # PAL (GFZP01) and JPN (GFZJ01) scaffolds
├── docs/                    # Architectural findings, compiler quirks, and coding rules
│   ├── CODING_RULES.md      # Code standards (no hardcoded pointers, shiftability)
│   ├── MWCC_IDIOMS.md       # Documented CodeWarrior register allocation patterns
│   └── RESOURCES.md         # Attribution, research papers, and technical references
├── include/                 # C headers and type definitions
│   ├── dolphin/             # Dolphin SDK headers (OS, GX, DVD, PAD, CARD, VI, AX)
│   └── rel/                 # Module interfaces and recovered struct layouts
├── orig/                    # Extracted retail binaries and targets (gitignored)
├── src/                     # Reconstructed matching C source code
│   ├── dol/                 # DOL translation units
│   └── rel/                 # Module translation units (main_rel, movie, sel, etc.)
├── state/                   # Matching ledger, import provenance, and repair archives
└── tools/                   # Decompilation toolchain and helper scripts
    ├── fzgx.py              # Main CLI for inventory, claims, diffs, and verification
    ├── prepare_orig.py      # Target extractor and line__.bin decryptor/decompressor
    └── project.py           # Ninja build generation and configuration logic
```

---

## Prerequisites & Dependencies

The build system utilizes [decomp-toolkit (dtk)](https://github.com/encounter/decomp-toolkit), [ninja](https://ninja-build.org/), and [wibo](https://github.com/decompals/wibo) (a lightweight 32-bit Windows binary wrapper that runs original Metrowerks CodeWarrior compilers natively on Linux and macOS without a full Wine install).

Original compilers are automatically downloaded during the initial project configuration.

### Linux

Install Python 3.10+, Ninja, and `uv`:

```sh
# Debian / Ubuntu
sudo apt update && sudo apt install -y build-essential git python3 python3-pip ninja-build

# Arch Linux
sudo pacman -S --needed base-devel git python ninja

# Install uv (fast Python package and project manager)
curl -LsSf https://astral.sh/uv/install.sh | sh
```

### macOS

Install dependencies using [Homebrew](https://brew.sh/):

```sh
brew install git ninja python
curl -LsSf https://astral.sh/uv/install.sh | sh
```

*(Note: On Apple Silicon, `wibo` runs under Rosetta 2 seamlessly.)*

### Windows

Native Windows tooling is strongly recommended (WSL is **not** required and is discouraged for diffing due to filesystem notification limits):

1. Install [Python](https://www.python.org/downloads/) and ensure **"Add Python to PATH"** is checked.
2. Install [ninja](https://github.com/ninja-build/ninja/releases) and add it to your `%PATH%` (or run `pip install ninja`).
3. Install [uv](https://docs.astral.sh/uv/):
   ```powershell
   powershell -ExecutionPolicy ByPass -c "irm https://astral.sh/uv/install.ps1 | iex"
   ```

---

## Building

### 1. Clone the repository

```sh
git clone https://github.com/karamzov123/fzero-gx-decomp.git
cd fzero-gx-decomp
```

### 2. Prepare the original game assets

Place a legally acquired retail disc image of F-Zero GX (USA / `GFZE01`) in the `orig/` directory (supported formats: `.iso`, `.gcm`, `.rvz`, `.wia`, `.wbfs`, `.ciso`, `.tgc`).

Extract the retail executables and decrypt `line__.bin`:

```sh
uv run tools/prepare_orig.py --version GFZE01
```

This step populates `orig/GFZE01/` with the original binaries and displays their SHA-1 hashes. The disc image may be safely deleted or moved afterwards.

### 3. Configure the build

```sh
python configure.py
```

To configure for another revision (when supported), specify `--version <GAME_ID>`.

### 4. Build and verify

```sh
ninja
```

When the build succeeds, `ninja` links all 16 executables and checks their SHA-1 checksums:

```
[182/185] CHECK config/GFZE01/build.sha1
16 files OK
```

---

## Matching & Interactive Diffing

### Using `objdiff` (GUI)

[objdiff](https://github.com/encounter/objdiff) provides live, interactive side-by-side assembly diffing against retail code.

1. Download the latest release of `objdiff` for your OS.
2. Under **Project Settings**, set the **Project Directory** to the root of this repository.
3. The configuration will load automatically from `objdiff.json`.
4. Select any function from the left sidebar. Any changes saved to source files or headers will automatically trigger a background rebuild and refresh the diff view.

### Using the `fzgx` CLI

The repository includes a unified decompilation assistant CLI at `tools/fzgx.py`:

```sh
# View overall honest authored code progress
uv run tools/fzgx.py honest

# Find unmatched functions under a specific size
uv run tools/fzgx.py inventory --module main_rel --status unmatched --max-size 256

# Claim a function and export its initial C context and assembly diff
uv run tools/fzgx.py claim fn_1_XXXX --agent <your_name>

# Check your C implementation against retail object code
uv run tools/fzgx.py check fn_1_XXXX

# Test against all supported Metrowerks CodeWarrior versions
uv run tools/fzgx.py check fn_1_XXXX --versions all

# Run the strict project linter (checks for hardcoded addresses, invalid constructs)
uv run tools/fzgx.py lint

# Submit a matched function and verify all 16 targets link
uv run tools/fzgx.py submit fn_1_XXXX --agent <your_name> --message "matched function description"
uv run tools/fzgx.py verify
```

---

## Contributing

We welcome contributions from everyone! Whether you are an experienced decompiler or matching your very first function:

- Review [CONTRIBUTING.md](CONTRIBUTING.md) for full pull request and workflow guidelines.
- Review [docs/CODING_RULES.md](docs/CODING_RULES.md) for code structure standards (no hardcoded pointer literals, shiftability requirements, proper struct typing).
- Consult [docs/MWCC_IDIOMS.md](docs/MWCC_IDIOMS.md) for patterns and CodeWarrior compiler quirks discovered across the project.
- Join the discussion on the [GameCube / Wii Decompilation Discord][discord] in `#dtk`.

---

## Credits & Acknowledgements

This project is built on the shoulders of the GameCube/Wii decompilation and modding communities:

- [decomp-toolkit](https://github.com/encounter/decomp-toolkit), [objdiff](https://github.com/encounter/objdiff), [wibo](https://github.com/decompals/wibo), and [dtk-template](https://github.com/encounter/dtk-template) by **encounter** and the **decompals** community.
- **CosmoCortney** for [Line__Crypt](https://github.com/CosmoCortney/Line__Crypt) and **bobjrsenior** for [SMB_LZ_Tool](https://github.com/bobjrsenior/SMB_LZ_Tool), which made decrypting and decompressing `line__.bin` (`main.rel`) possible.
- The **F-Zero GX modding community** for over a decade of reverse-engineering track, model, and engine formats.
- All past and present contributors to this repository and its forks.

---

## License

The source code and tooling created in this repository are dedicated to the public domain under the [Creative Commons Zero 1.0 Universal (CC0 1.0)](LICENSE) license.

*F-Zero GX is a trademark of Nintendo. Game content, assets, and original binaries are © 2003 Nintendo / Sega / Amusement Vision. This project is an independent educational and preservation effort and is not affiliated with or endorsed by Nintendo or Sega.*
