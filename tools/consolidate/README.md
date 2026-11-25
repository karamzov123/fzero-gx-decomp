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
| `steer_prune.py --kind K [--apply]` | removes steering that no longer changes any object: `volatile`, one-member `carrier`s, `register`, `castview` (`*(T *)&x`), `pcast` (`(T)(e)`), `icast` (`(T)x`), `ptrcast` (`(T *)e`), `plus0`, `derefaddr` (`*&x`), `parens` (`((x))`), `soloparen` (`(x)`), `unusedlocal` (declarations inside function bodies whose name is never used); per block, bisected on failure, all regions |
| `pragma_rank.py`, `pragma_diff.py`, `trysrc.py` | rank pragma setters by words changed; show the asm diff; try a hand rewrite (scoped to one function) against the unit object |
| `tu_data.py CAND UNIT SECTION LO` | a candidate's data section against retail, relocated words masked, before `tu_own_data.py` |
| `data_split.py dol/data/U.c SYM... [--apply]` | splits a data-import unit at object boundaries (a unit is aligned to its most aligned object, so a trimmed unit can need splitting first) |
| `rename_regions.py MAP.json` | after `fzgx rename --map`: restores units.json order and versions and renames in the region symbol files and TU maps |
| `tu_cut.py SRC OUT FN...` | cuts a source down to some function definitions (declarations and static inlines kept), to split a unit that crosses TUs |
| `tu_reverse.py SRC OUT` | writes a file's definitions in reverse order (MSL's source order under `-inline deferred`), hoisting declarations and keeping each function's pragmas |
| `tu_order.py CAND UNIT` | the function order a candidate emits, against retail's (tu_regions.py compares by name only) |
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
- steer_prune results (2026-11-20): carriers 24, volatile 128 (hardware/buffer/primer
  volatiles excluded by pattern), register 67, castview 993, pcast 4600, icast 3126, ptrcast 4209,
  plus0 280, derefaddr 394, parens 653, soloparen 1267 in the RELs; in lifted dol/fn_* files without
  SDK-imported symbols: pcast 602, icast 363, ptrcast 647, plus0 245, derefaddr 57, parens 102,
  soloparen 395, carrier 4 (volatile/register are not pruned in the DOL).
  Remaining instances change code. A member access is not always equivalent to the lifter's
  byte view: in car_test fn_1_7D6B8 only 7 of 16 offsets convert with an identical object.
