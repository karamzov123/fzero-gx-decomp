# Whole-TU collapse workstream

Synthetic `.fzgxpool` layout primers are the largest known-scaffolding category (958 of the 972 owner functions in `docs/DEVICE_CENSUS.md`). They exist because each function block compiles as its own unit and cannot reproduce its translation unit's literal pool or section-base addressing. Removing them one function at a time is a measured negative frontier. A TU that compiles and links as one object (`fzgx tu-check`, `tutrial`, `collapse`) produces those layouts natively, so collapsing whole TUs is the main route to removing primers, per-function pragmas and `noprologue` scaffolding together.

## Survey (2026-11-16)

`state/repairs/tu-whole-compile-survey-20261116.jsonl.gz` records, for every un-collapsed TU, its block count, census debt counts and whole-file compile result:

- 21 TUs are already collapsed. The other 70 TUs have all functions matched, but **none compiles as one file**. Every one stops at its first conflicting declaration (`-maxerrors 1`), so the first error does not show how far a TU is from compiling.
- 4,273 blocks remain, 1,406 of them `noprologue`. Primers are concentrated: the ten heaviest files hold 7,620 of 10,630 definitions (`sel.c` 2,301, `effect.c` 1,054, `effect_car.c` 702, `accessory.c` 608, `pilotpoint.c` 606, `toolkit.c` 599).
- After normalizing the module default (`-` = GC/1.3.2 for RELs), 23 of 70 TUs use one compiler profile. Only 136 functions need another (88 GC/1.3, 28 GC/2.5, 8 GC/2.0, plus a few flag variants). Each one blocks a single-profile whole-TU compile and needs its own investigation.

## Pilot: bg_tow.c / rep_memcard.c boundary

The TU map gave bg_tow.c seven functions, but only `fn_1_154410` belongs there (it panics with `"bg_tow.c"`). `fn_1_154708`-`fn_1_1549B8` belong to rep_memcard.c. Their data includes the `"rep_memcard.c"` file string passed with line 0x73, the `REP_MEMCARD_*` state names and `"RepMemcardEvent"`. rep_memcard's state table at 0x49A18 lists `fn_1_1548A8`, `fn_1_154930` and `fn_1_1549B8` together with `fn_1_154A08` and `fn_1_154BE4`, across the old boundary. The map now starts rep_memcard.c at 0x154708, with data from 0x49A18. `fzgx tu-regroup` moved exactly those six blocks, byte-identical and relink-verified. Unused rep_memcard declarations were pruned from bg_tow.c, and the ledger snapshot changes only those six unit paths.

The pilot also showed what each TU needs before it can collapse:

1. **Correct ownership**: TU boundaries, then regenerated TU headers. Regenerating moves declarations; a block that redeclares a symbol with another type (for example a scalar `lbl_1_data_49A18` against the header's `u32[5]`) and data units or import records that name the old header must follow in the same change.
2. **One declaration per symbol**: `fzgx tutruth`. Lifter-style blocks (register-mirroring locals, private struct views over the TU's section base) cannot follow shared declarations and stay self-contained. They need natural reconstruction, usually as real file-scope statics in retail order, which is also the original source shape.
3. **One compiler profile**, then `tutrial` per-function scoring and `collapse` with the full link hash as the oracle.
