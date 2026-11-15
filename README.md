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

Verified locally on **2026-11-14**, after consolidating merged upstream through PR #376 and the accepted changes below, for **GFZE01**:

- **Diagnostic Object Match:** **100.0%** of code bytes (7,351 / 7,351 functions in the objdiff report). This includes assembly and retail fallback objects; it is not a natural-C completion percentage.
- **Authored C Credit:** **7,160 / 7,351** functions, **98.7912%** of code bytes (`fzgx sync`, then `fzgx honest`). This includes C with compiler-diff devices and evidenced inline assembly kernels, not just device-free natural C.
- **Assembly-Owned Functions:** **191** current configured functions remain outside authored-C credit. This is an audit inventory, not 191 proven C conversions: original assembly is permitted when supported by evidence.
- **Compiler-Diff Debt:** **34 primary warning markers across 11 files** in `src/` and `include/` (36 markers when `WARNING: device` cross-references are included). Markers are not a count of distinct devices or affected functions; unmarked constructs still need review.
- **Target Executables:** **16 / 16** link and match the retail SHA-1 hashes byte for byte (`16 files OK`, followed by an independent checksum check).
- **Diagnostic Data Match:** **98.63%** (4,999,117 / 5,068,445 bytes in the regenerated report). This is not an asset-reconstruction or source-owned-data percentage.
- **Source Coverage:** **13 / 16** executables have authored-C credit for every configured function. The remaining inventories are listed below.
- **Lint:** **0 findings** (`fzgx lint`).

These are separate gates. A green object report or retail checksum does not prove natural-C
completion, and `fzgx honest` is not a device-free-source audit. Under
[the assembly and device policy](docs/ASM_POLICY.md), completion requires every function to match,
natural C wherever the original was C, assembly only with original-assembly evidence, and zero
compiler-diff devices. A separate audited device-free natural-C total is not yet established.

### Remaining Work and Next Steps

| Executable | Authored C / known functions | Outside C credit | Authored code bytes |
|---|---:|---:|---:|
| `main.dol` | 2,064 / 2,245 | 181 | 94.6328% |
| `main_rel` | 3,227 / 3,230 | 3 | 99.9469% |
| `movie_module` | 784 / 791 | 7 | 98.5292% |
| Other 13 executables | All configured functions | 0 | 100% |

1. **Remove compiler-diff devices without losing exactness.** Start with the dead assembly writes in `include/adx_compiler_diff.h` and their remaining caller, `src/dol/fn_8004F26C.c`. Continue through the ADX decoder scheduling/stack-escape devices, stream-writer volatile staging, and gameplay helpers. While merging a completed cleanup into `main` requires real MWCC object evidence and all 16 hashes, **pull requests with better near-matches are welcome and encouraged**: submitting improved near-matches, cleaner candidate structures, or partial cleanups allows the community to collaborate, inspect compiler evidence, and help close the remaining diffs.
2. **Audit the 191 assembly-owned functions against original-assembly evidence.** Preserve genuine SDK/runtime/MetroTRK and middleware assembly; convert only code that was plausibly C. The three `main_rel` entries are `fn_1_4B6D4`, `fn_1_4B788`, and `fn_1_9DFB8`. The seven `movie_module` entries are `fn_12_52E8`, `fn_12_D0B8`, `fn_12_12564`, `fn_12_33664`, `fn_12_33698`, `fn_12_3CB74`, and `fn_12_3D144`.
3. **Keep metrics synchronized and reproducible.** Run `fzgx sync` after updating source/configuration, then regenerate progress and report authored C, evidenced assembly, and device debt separately. Ledger totals can include retired symbols; use the current configured-function denominator rather than adding raw ledger statuses. Data ownership and readable shared types remain separate work; executable hash parity does not prove complete source-owned data.
4. **Preserve the acceptance gate.** Rebuild with `python3 configure.py && ninja`, independently run `build/tools/dtk shasum -c config/GFZE01/build.sha1`, run `fzgx lint`, and snapshot provenance before committing accepted changes. Do not replace a working match with an unverified naturalization attempt.
5. **Extend regional source coverage after the primary cleanup.** PAL and Japanese configurations have landed assembly baselines, not primary-target C coverage. Verify each region separately with legally obtained inputs; the USA checksum result above does not certify either regional build.

The first ADX probe reproduced the installed `fn_8004F26C` exactly, but removing its dead
inner clamp arm left three differing instruction words. Genuine prediction helpers and
arithmetic-local reuse did not close that residual. No candidate replaced the working match;
the next investigation needs allocator/liveness evidence rather than more equivalent expression
rewrites. See [the portable probe evidence](state/repairs/adx-inner-clamp-20261114.json).

The mono decoder `fn_8004F55C` likewise retains an early incoming-stack-load mismatch after
natural parameter handling across seven compiler versions and real RNG-update helper probes.
The installed match is unchanged; see [the recorded frontier](state/repairs/adx-mono-stack-20261114.json).

### Latest Accepted Data Ownership

`src/dol/data/DVDLoadFstMessage.c` now owns two DVD/FST diagnostic strings: **62 payload bytes**
in a **64-byte split** including measured padding. The importer proved MWCC layout and retail
bytes, retained the existing `char[52]` consumer declarations, and passed all 16 hashes. Running
`fzgx data-import DVDLoadFstMessage --regenerate --apply` reproduces both objects together.
The rename tooling now updates symbolic literal-pool targets while retaining compiler-private
keys, so `DVDInit` continues to bind its literal to the renamed retail string. This adds data
ownership, not a newly matched function or a removed compiler-diff device.

Next for initialized data: recover mixed layouts for non-finite pools such as
`lbl_3_rodata_990` and `lbl_1_rodata_2B2C`; do not weaken their existing scalar-array declarations
to opaque byte storage just to get them through the importer.

### Latest Accepted Source Cleanup

The compound-scaling batch removed **four volatile declarations/casts, six operand/read helper
definitions, and two pragma pairs** across three current functions:

- `fn_800764A0`: ordinary state/color accesses and direct matrix `*=` assignments; no inline helpers, volatile qualifiers or pragmas remain in its source.
- `C_MTXFrustum`: a normal local vertical scale replaces the operand helper; no helper or pragma is needed.
- `fn_16_61D4`: normal packet scale assignments replace one helper, and helper-only dead-assignment and redundant common-subexpression pragmas are gone. One denominator helper remains; this function is not fully naturalized.

All three still match their real retail objects and passed the supported 16-target verifier.
These devices were unmarked, so the 34-primary-warning tally is unchanged. See
[the measured source and rollback evidence](state/repairs/compound-scaling-20261114.json).

A subsequent main_rel TU cleanup removes one additional operand helper from `fn_1_15EC40`:
a scoped float intensity is computed with ordinary arithmetic before the renderer call. Its
retail object and 16-target link still match. Two other TU rewrites did not match and were not
installed; see [the follow-up evidence](state/repairs/tu-native-intensity-20261114.json).

The existing repair engine now proposes guarded removal of pure two-argument float operand
wrappers. A measured cohort of **12 real baseline functions / 24 candidates** compiled without
errors and produced four exact object candidates. Two were admitted: `fn_10_1B2F4` and
`fn_3_23724` each lose one helper in favor of normal arithmetic. The other two are blocked by
inherited shared-header declaration conflicts and are **not** accepted progress. Conditional
hoisting and overlapping nested-wrapper edits are excluded. See
[the generator and admission evidence](state/repairs/native-operand-family-20261114.json).

Revision submissions now refresh literal-pool bindings when source changes renumber private
constants. Failed revisions preserve the previously accepted source, compiler settings, split
ownership and pool/verified state; a real stale-binding regression verified that fallback.

`fn_8003D42C` now reads its input byte without an unnecessary volatile qualifier. The real MWCC
object still matches retail exactly and the normal submission/verifier path accepted the change.
Its `opt_propagation off` and `peephole off` directives remain: removing them does not match.
This removes one unmarked qualifier device, not a whole function's remaining compiler steering;
authored-function totals and the marked-warning count are unchanged. See
[the compiler evidence](state/repairs/ordinary-stream-read-20261114.json).

The verifier also now resolves Git's actual index-lock location, so accepted source can be
committed from linked worktrees whose `.git` is a file. Existing lock-age and process checks remain.

### Supported Versions

| Game ID | Region | Revision | Status |
|---|---|---|---|
| `GFZE01` | North America (NTSC-U) | Rev 0 | **Primary target** (all 16 targets verified) |
| `GFZP01` | Europe (PAL) | Rev 0 | Builds byte-for-byte (asm baseline, USA names mapped) |
| `GFZJ01` | Japan (NTSC-J) | Rev 0 | Builds byte-for-byte (asm baseline, USA names mapped) |

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
│   └── ...                  # PAL (GFZP01) and JPN (GFZJ01) configs
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
- **Near-matches & PRs:** Pull requests with improved near-matches, cleaner candidate structures, or partial cleanups are welcome and encouraged! Submitting near-matches helps the community collaborate on closing difficult functions.
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
