# Region versions: GFZP01 (PAL) and GFZJ01 (NTSC-J)

GFZE01 is the primary target. PAL and NTSC-J build from the same source tree and the
same unit list; a unit is built from C for a region once it matches there. Everything
else in a region stays its dtk assembly baseline, so all three versions always rebuild
their retail files byte for byte.

## Model

- **One set of names.** GFZE01 names are canonical. `config/GFZP01/**/symbols.txt` and
  `config/GFZJ01/**/symbols.txt` place those names at the region's addresses; source never
  uses region-specific names.
- **One unit list, dtk-template semantics.** `config/GFZE01/units.json` is the only unit
  list, and a unit's completion reads like an `Object(...)` in dtk-template projects
  (Twilight Princess, Wind Waker, Sunshine):

  | `units.json` | dtk-template | built from C in |
  |---|---|---|
  | `"status": "matching"` | `Matching` | every version |
  | `"status": "matching", "matching_for": ["GFZE01", "GFZP01"]` | `MatchingFor("GFZE01", "GFZP01")` | those versions |
  | `"status": "nonmatching"` | `NonMatching` | none (each version links its assembly) |

  A version a unit does not match links its own assembly for that range, so every
  version always rebuilds its retail files.
- **Per-version files** are only what differs: `config.yml`, `build.sha1`, `symbols.txt`,
  `ldscript.tpl` and the `Sections:` headers in `splits.txt`. There is no region
  `units.json` and there are no per-unit region splits.
- **Region splits are derived.** `configure.py --version GFZP01` writes
  `build/GFZP01/config.yml` and `build/GFZP01/splits/**`: each unit listed for the version
  gets its GFZE01 split ranges, each moved by the address difference of the symbols named
  in both versions inside that range. If those symbols do not all move by the same amount,
  configure stops and names the unit.
- **Region differences go in the shared source**, so a file stays one file and one unit in
  every version. `include/version.h` follows Wind Waker's `global.h`:

  ```c
  #include "version.h"
  f32 speed = VERSION_SELECT(1.0f, 1.2f, 1.0f); /* USA, PAL, JPN */
  #if VERSION == VERSION_PAL
  ...
  #endif
  ```

## Tooling

- New matches record where they were verified. `fzgx` saves a unit that becomes matching
  without `matching_for` as `["GFZE01"]`; only units already stored as plain `"matching"`
  stay that way. A list naming every version is stored as plain `"matching"`.
- `fzgx` `Project("GFZP01")` sees only the units that match GFZP01. Units are saved
  through GFZE01; a unit's versions are its `matching_for`.
- `fzgx collapse` and `fzgx data-import` give a merged unit the versions every unit it
  replaces matched.
- sjiswrap is used for GFZJ01 only when a built source has non-ASCII text outside
  comments (sjiswrap v1.2.2 does not start under wibo 1.2.0).

## Adding a unit to a region

Prerequisites: a GFZE01 build (`python3 configure.py && ninja`) and the region's files
(`uv run tools/prepare_orig.py --version GFZP01` with its disc image in `orig/`).

```sh
python3 tools/region_config.py --version GFZP01 --units rel/car_colchg/car_colchg/_prolog.c
python3 configure.py --version GFZP01 && ninja   # must print: 16 files OK
```

`tools/region_config.py` rewrites the region's `symbols.txt` and section headers, and adds
the region to `matching_for` of the units given with `--units`. Without `--units` it lists
the region for every unit it considers eligible and removes it elsewhere. It only proposes;
the region build decides. A unit matching all three versions becomes plain `"matching"`.

How it names region symbols:

1. **Identical modules** (same section layout, same relocation sites, same bytes outside
   them) keep the GFZE01 symbols as they are. The targets of their relocations are named
   from the region's relocation table at the same sites, which is exact.
2. **Elsewhere**, each GFZE01 function of 16 bytes or more whose code (immediates and branch
   targets masked) occurs exactly once in the region module is named there, keeping only hits
   in address order. dtk then disassembles both versions; functions whose instructions are
   equal apart from symbol operands, with every operand pairing consistently, name the
   region's data and labels.
3. Region names that dtk would generate and that equal a GFZE01 name in use are renamed
   `rgn_<name>`.

A unit is eligible when its symbols are named in the region and every symbol its GFZE01
object leaves undefined is defined there.

## Differences between the versions

- REL module ids: PAL uses the GFZE01 ids; NTSC-J differs (interview 18, movie_module 13,
  pilotpoint 15, profile 17, replay 14, sample 19, winning 16). Names that carry a module
  id are never paired across modules.
- REL file names: `fze.*.rel` (GFZE01), `fzp.*.rel` (GFZP01), `fz.*.rel` (GFZJ01).
- Alignment: PAL and NTSC-J place `main.dol` `.sdata2` and `.sbss2`, and `main.rel` `.data`,
  on 32-byte boundaries.
- `enemy_line/line__.bin`: GFZP01 uses the GFZE01 key, GFZJ01 its own (`tools/linecrypt.py`).

## Verifying a region

```sh
python3 configure.py --version GFZP01 && ninja
uv run tools/build_disc.py --version GFZP01 --image PATH/TO/GFZP01.iso --out /tmp/GFZP01.iso
```

CI builds all three versions (`GFZE01`, `GFZP01`, `GFZJ01`) and uploads a `<VERSION>_report`
for each, so decomp.dev reports every version. A unit that is plain `"matching"` or names a
region in `matching_for` must still link there: check it locally before pushing.
