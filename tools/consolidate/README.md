# TU consolidation tools

Deterministic passes that merge adjacent matched units into larger compile units and retire
`noprologue` blocks. Each candidate is accepted only when the compiled object is unchanged
(per-function `.text` bytes and relocations, or the whole unit's section bytes, relocations and
defined symbols); the full gate (`gate.sh`: three region builds + `fzgx lint`) still decides.
Run from the repository root; dry-run first.

| script | what it does |
|---|---|
| `consolidate_all.sh` | runs every merger below with `--apply` until the unit count stops falling |
| `apply_unpooled_all_v3.py [--dry-run]` | merges adjacent unpooled `.text`-only runs (REL, dol/, movie_module/) |
| `apply_reloc_derived_multi_primer.py [--dry-run]` | pooled REL merges; pool maps re-derived from relocations |
| `apply_reloc_derived_dol_mm.py [--dry-run]` | the same for dol/ and movie_module/ |
| `apply_multisection_rels.py`, `apply_multisection_dol_mm.py` | merges whose `.data/.rodata/.bss` must also be contiguous |
| `nopro_retire.py [--fix] [--apply] [TU...]` | drops `noprologue` when the prologue-deduped block leaves the unit's object identical; `--fix` reconciles duplicate/retyped declarations (`declfix.py`, cast views disabled) |
| `devprobe.py` | removes each pragma device's pragma and reports whether the unit's object is unchanged |
| `devprobe_tokens.py` | the same for `volatile` and one-member-carrier devices |
| `unitcmp.py [--version V] FILE...` | every unit of FILE, git HEAD vs working tree, in all regions of its `matching_for` |
| `pragma_prune.py [--apply] FILE...` | removes optimizer pragmas that leave every unit (all regions) unchanged |
| `tuflag.py [--all]`, `apply_tuflag.py` | is a pragma kind really a TU-wide build flag? (all units of the TU, all regions) |
| `tuversion.py` | strips all optimizer pragmas of a TU and tries each compiler version x fp_contract |
| `pairdiag.py`, `merge_prep.py` | why adjacent clean units of a TU do not merge; reconcile their declarations |
| `gate.sh` | GFZP01/GFZJ01/GFZE01 builds + lint |

Helpers: `apply_pooled_all.py` (ELF/relocation parsing), `apply_smart_dol_mm.py` (C file merge
with struct-tag renaming), `apply_dol_and_mm.py`, `apply_nopro_smart.py` (prologue-aware block
cleaning), `objsig.py` (order-independent object signature).

`devprobe.ninja_units()` parses build.ninja for the configured version; every check that matters
compiles each unit for all regions in its `matching_for` (flags differ only in `-DVERSION_*`).
Run from a GFZE01-configured tree, and still run `gate.sh`.

Measured limits (2026-11-20): with merges at a fixed point, the remaining `noprologue` blocks
disagree with their prologue on real types. Cast views (`(*(T *)&sym)`) would retire ~50 more
but were rejected as less natural than the self-contained block. All 36 pragma-device sites
change the object when the pragma is removed.
- Whole-TU `-fp_contract off` explains every fp_contract pragma of 13 TUs (applied); other
  `-opt no*` flags reproduce a few files but are not plausible build settings (not applied).
- No compiler version (1.2.5n..2.7, fp_contract on/off) reproduces stcoli/accessory/pilotpoint
  with their optimizer pragmas stripped (3 of 68 pragma-affected units): the ~850 remaining
  setters steer individual functions and need source-shape work.
- name_entry's volatile target-pointer devices: `volatile` is redundant but a no-op pointer cast
  (`*(T **)ref`) is still required, so the device stays; `x--` replaces a volatile reload of x.
