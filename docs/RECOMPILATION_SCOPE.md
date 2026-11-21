# Project scope: a recompilable reconstruction

Owner decision, 2026-11-20. This supersedes the 2026-11-14 statement of the active goal
("full USA completion"); that definition remains part of this one (requirement R6).

## Goal

**The source tree must be in a state from which a recompilation of F-Zero GX for any platform
can be created, while the same tree keeps rebuilding all 16 retail executables byte for byte
with the original CodeWarrior toolchain.**

The matching build is the proof that the source is correct. This project does not build the
port itself; it makes one possible. Anyone (as with the third-party PC port of the Super Smash
Bros. Melee decompilation) should be able to create a recompilation for any CPU, compiler, word
size or byte order by writing a platform layer and asset loader, without re-decompiling game code.

The primary target stays USA `GFZE01`. PAL and NTSC-J remain verify-only regions until the USA
source meets this scope.

## Requirements

| # | Requirement | Means |
|---|---|---|
| R1 | **TU fidelity** | Every retail translation unit is one source file that compiles as one unit with that TU's measured compiler and flags. No per-function units, `noprologue` blocks or split ranges are needed to match. Requires a TU map for the DOL and every REL. |
| R2 | **Data ownership** | All data (initialized, read-only and BSS) is defined in C with real types, in the TU that owns it. No retail data blobs are linked; no `fzgx_obj_*` or `__fzgx_offset_*` layout scaffolding; no literal-pool primers. Game assets stay on the disc and are loaded at run time; they are never checked in. |
| R3 | **Build independence** | No construct that only makes sense inside this build system: `.fzgxpool` primer functions, `mwcc_pool` post-compile literal remapping, generated per-function units. The matching build may still use CodeWarrior-specific flags, measured per TU. |
| R4 | **Platform boundary** | Hardware and SDK access (GX FIFO writes, hardware registers, locked cache, paired-single kernels, MWCC intrinsics, inline assembly, OS/DVD/CARD/PAD/AX/ADX/Sofdec) lives in SDK/middleware TUs or named shared headers, so a port can supply a replacement layer. Game code calls interfaces, not addresses. |
| R5 | **Portable game C** | No pointer/integer punning in game code (pointers held in `u32`, address arithmetic on integers), complete typed struct layouts instead of byte-offset views, no reliance on big-endian layout through unions or byte views. Where retail matching forces a spelling, it is documented at the site. |
| R6 | **Natural C, no devices** | The existing definition: natural C wherever the original was C, assembly only with evidence that the original was assembly, zero compiler-diff devices ([docs/ASM_POLICY.md](ASM_POLICY.md)). |
| R7 | **Readable interfaces** | Shared types and headers for cross-TU structures; names for public functions and globals, progressively. A port does not need every local named, but it needs to know what each module exposes. |

Non-goals: writing or shipping a port or platform layer (that is left to downstream projects),
distributing assets or binaries, changing retail behaviour, or completing other regions before USA.

## Baseline (2026-11-20, HEAD `2d61b75e9`)

| Measure | Value |
|---|---|
| Retail parity | 16 / 16 executables byte-identical; 7,351 / 7,351 functions match |
| Authored C credit | 7,159 / 7,351 functions, 98.79% of code bytes (192 evidenced or reviewed assembly) |
| Code units / data units | 3,032 code units (182 assembly), 4,565 data-import units |
| TU map | RELs: 69 TU files cover 1,677 code units; `profile` (41), `movie_module` (307), `sample` (4) and `movie` (1) have no TU map. DOL: **no TU map** (1,175 units, mostly one function each) |
| TUs compiling as one unit (R1) | 13 of 69 REL TU files; 0 in the DOL |
| `noprologue` blocks (R1) | 1,095 |
| Literal-pool remapped units / primer functions (R2, R3) | 1,214 units / 459 primers in 142 files |
| Layout scaffolding names (R2) | 8,684 distinct `fzgx_obj_*` / `__fzgx_offset_*` names |
| Hardware addresses in REL source (R4) | 471 literals (`0xCC00xxxx`, `0xE000xxxx`); GX FIFO written directly in 18 REL files |
| MWCC intrinsics in REL source (R4) | 595 uses; paired-single kernels (`psvec.h`) in 33 files; inline assembly in 4 REL game files |
| Pointer/integer punning (R5) | 632 address-to-integer casts; 451 pointer views of `unk_` fields |
| Compiler-diff devices (R6) | 95 marked spots; 821 unmarked optimizer pragma setters |
| Naming (R7) | 6,440 of 7,351 functions still `fn_` named |

## Work order

1. **TU map.** Assign every function and data object to its retail TU, DOL first (it has none).
   Evidence: `__FILE__`/assert strings, section start alignment, literal-pool deduplication (a
   repeated literal means a TU boundary; see story_mode `fn_7_4108` in
   [TU_COLLAPSE.md](TU_COLLAPSE.md)), Dolphin SDK/MSL/TRK library layouts, and the F-Zero AX
   reference below. Output: `config/GFZE01/**/tus.json` for every executable, with evidence.
2. **TU collapse.** Per TU: one prologue, declarations reconciled (`fzgx tutruth`), `noprologue`
   retired, units merged until the TU is one unit (`fzgx tu-check`, `tools/consolidate/`).
   Pool maps and primers disappear when the TU owns its own pool.
3. **Data ownership.** Define each TU's data in its file with real types (`fzgx data-import`,
   section-layout objects), replacing scaffolding names and byte views with typed members.
4. **Platform boundary and portable C** (R4, R5): route hardware and intrinsic use through
   named SDK interfaces and headers; replace punning with typed pointers.
5. **Devices, natural C and naming** (R6, R7) continue alongside, using the measured tools.

Every step keeps the 16-target hash gate, lint and the region builds green.

## Reference input: F-Zero AX

The owner supplied a legally obtained F-Zero AX disc image (Japan, Rev C, disc ID `GFZJ8P`,
SHA-1 `dcfda2dd92c5d2c0813158a5ee908b8745695be0`). It is a separate build of the same engine:

- `sys/main.dol` (3.24 MiB) names 88 source files, including TUs absent from the GX map so far
  (`avdisp.c`, `avfile.c`, `avload.c`, `avsystem.c`, `arc.c`); the race engine appears to be
  linked into the DOL there.
- Besides release modules `fz.*.rel` it ships debug modules `fzD.*.rel` whose strings pair 123
  function names with their source files (for example `name_entry_disp_main : name_entry.c`,
  `LightMain : title.c`).

Use: evidence for TU boundaries and names only. Its bytes, code and data are never committed,
and nothing is copied from it into GX source; record provenance (disc ID, file, string) for every
name or boundary derived from it, as with GX's own strings. Keep the image outside the repository
or under `orig/` (gitignored).
