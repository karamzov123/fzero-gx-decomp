# Whole-TU collapse workstream

Synthetic `.fzgxpool` layout primers are the largest known-scaffolding category (958 of the 972 owner functions in `docs/DEVICE_CENSUS.md`). They exist because each function block compiles as its own unit and cannot reproduce its translation unit's literal pool or section-base addressing. Removing them one function at a time is a measured negative frontier. A TU that compiles and links as one object (`fzgx tu-check`, `tutrial`, `collapse`) produces those layouts natively, so collapsing whole TUs is the main route to removing primers, per-function pragmas and `noprologue` scaffolding together.

## Survey (2026-11-16)

`state/repairs/tu-whole-compile-survey-20261116.jsonl.gz` records, for every un-collapsed TU, its block count, census debt counts and whole-file compile result:

- 21 TUs are already collapsed. The other 70 TUs have all functions matched, but **none compiles as one file**. Every one stops at its first conflicting declaration (`-maxerrors 1`), so the first error does not show how far a TU is from compiling.
- 4,273 blocks remain, 1,406 of them `noprologue`. Primers are concentrated: the ten heaviest files hold 7,620 of 10,630 definitions (`sel.c` 2,301, `effect.c` 1,054, `effect_car.c` 702, `accessory.c` 608, `pilotpoint.c` 606, `toolkit.c` 599).
- After normalizing the module default (`-` = GC/1.3.2 for RELs), 23 of 70 TUs use one compiler profile. Only 136 functions need another (88 GC/1.3, 28 GC/2.5, 8 GC/2.0, plus a few flag variants). Each one blocks a single-profile whole-TU compile and needs its own investigation.

## Pilot: bg_tow.c / rep_memcard.c boundary

The TU map gave bg_tow.c seven functions, but only `fn_1_154410` belongs there (it panics with `"bg_tow.c"`). `fn_1_154708`-`fn_1_1549B8` belong to rep_memcard.c. Their data includes the `"rep_memcard.c"` file string passed with line 0x73, the `REP_MEMCARD_*` state names and `"RepMemcardEvent"`. rep_memcard's state table at 0x49A18 lists `fn_1_1548A8`, `fn_1_154930` and `fn_1_1549B8` together with `fn_1_154A08` and `fn_1_154BE4`, across the old boundary. The map now starts rep_memcard.c at 0x154708, with data from 0x49A18. `fzgx tu-regroup` moved exactly those six blocks, byte-identical and relink-verified. Unused rep_memcard declarations were pruned from bg_tow.c, and the ledger snapshot changes only those six unit paths.

The literal pool and handler table then showed that bg_tow.c also started too late. Retail's background handler table `lbl_1_data_2A9B8` has nine handlers per background, and bg_tow's entry is `fn_1_153988`, `15398C`, `1539D0`, `153A28`, `153AAC`, `153AB0`, `153AF4`, `1543E8` and `154410`. The helpers `153AF8`-`154164` are called only from those handlers, and `153B24`/`153D74` use bg_tow's literal pool `lbl_1_rodata_D508`, which already backed `fn_1_154410`. `fn_1_154410` panics at bg_tow.c lines 482-527, so most of that file precedes it, and `fn_1_152FAC` ends exactly at 0x153988. bg_tow.c therefore starts at 0x153988, and regroup moved those 15 functions from bg_aur.c byte-identically.

The remaining "bg_aur.c" range still mixes TUs. bg_aur's own handler entry is `fn_1_150500`-`fn_1_15176C`, which starts before the mapped range. `fn_1_151AF0`-`fn_1_152FAC` are a separate library used by customize and sel, and no evidence names it yet, so that range keeps its current mapping.

Without its primer, the one-function bg_tow.c compiled whole but fell to 99.49% and could not place its literals. Its pool belonged to the larger TU above, so a wrong TU boundary can also be what makes a primer necessary.

**bg_tow.c now compiles as one file and matches 16/16 inside that compile**, the first un-collapsed TU to do so. Its moved blocks carried bg_aur's whole old prologue. Removing 294 extern declarations no block referenced changed no code and let tutruth unify 15 of 16 blocks. `fn_1_1540B0` was the last self-contained block (93%, an r27/r28 swap from passing the object as `u32`). It now takes the shared object type and copies the constant vector as a struct, and it matches under the TU prologue. The file has no `noprologue` blocks left. Bodies replay from `state/repairs/bgtow-whole-tu-20261116.sources.json.gz`.

It is not collapsed yet: its primer is still needed. Without it, 15/16 still match, but `fn_1_154410` drops to 99.51% and bg_tow's strings no longer fill its `.data` range exactly. The primer serves `fn_1_153D74`, which reads the literal pool through a lifter struct view (`AuroraDef` over `lbl_1_rodata_D508`: seven floats, a zero, the int-to-float bias, five vectors, four floats). It also carries other devices (`fzgx_live`, an inert multiply helper, raw locked-cache stores). Rewriting it with real literals and a constant vector table is the next step before primer removal and collapse.

The pilot also showed what each TU needs before it can collapse:

1. **Correct ownership**: TU boundaries, then regenerated TU headers. Regenerating moves declarations; a block that redeclares a symbol with another type (for example a scalar `lbl_1_data_49A18` against the header's `u32[5]`) and data units or import records that name the old header must follow in the same change.
2. **One declaration per symbol**: `fzgx tutruth`. Lifter-style blocks (register-mirroring locals, private struct views over the TU's section base) cannot follow shared declarations and stay self-contained. They need natural reconstruction, usually as real file-scope statics in retail order, which is also the original source shape.
3. **One compiler profile**, then `tutrial` per-function scoring and `collapse` with the full link hash as the oracle.
