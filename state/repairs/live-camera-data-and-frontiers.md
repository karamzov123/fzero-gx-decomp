# Live-camera data recovery and unmatched source frontiers

## Verified data

The live-camera import owns eight retail objects, 3,308 initialized bytes:

- lbl_1_data_43B8: 12 bytes.
- lbl_1_data_4440 / lbl_1_data_4484 / lbl_1_data_44F4: 200 bytes.
- lbl_1_data_4568 / lbl_1_data_4754 / lbl_1_data_47B4 /
  lbl_1_data_4AA0: 3,096 bytes, including the 1,760-byte preset table.

The table has 55 entries at a measured stride of 0x20. fn_1_11ABC indexes
that stride and copies its first three words as a vector. LiveCameraPreset
preserves all recovered word/float field types; the original whole-object
Obj_1_data_4AA0 view remains available. Four trailing bytes per row remain
uninterpreted, not invented padding. The typed array replaces a 0x6C4-byte
opaque tail in the initialized definition.

The dispatch object's fourteen pointer relocations and three trailing words
come from the retail object. Its generated declaration replaces the previous
u8[68] view. fn_1_EE04 now explicitly takes the object's address; its object
still matches exactly. fn_1_11ABC also still matches exactly.

The data importer proved MWCC layout, all initialized bytes, relocation
bindings, actual Ninja objects, and all 16 executable hashes. Provenance and
regeneration inputs are in state/dataimports/GFZE01.json. The preset table
was initially imported separately, then preserved intact when its adjacent
objects were grouped into the aligned lbl_1_data_4568 unit.

## Verified BSS storage (separate from initialized data)

Four existing recovered aggregate definitions were also transferred to C,
without changing their header layouts:

| Object | Module | BSS bytes |
| --- | --- | ---: |
| lbl_3_bss_7EE40 | customize | 33,216 |
| lbl_3_bss_87040 | customize | 33,216 |
| lbl_1_bss_86ED0 | main_rel | 7,280 |
| lbl_1_bss_88B50 | main_rel | 3,072 |

Total: 76,784 bytes of zero-initialized storage, not initialized-file payload
and not executable-code progress. MWCC emitted all four symbols in ELF .bss
(SHT_NOBITS/type 8), at their exact retail sizes. The importer proved member
layouts and object bindings before transferring the splits and passing all
16 executable hashes. No new filler objects or padding were introduced.
The generated source's section attribute is not sufficient to identify its
actual storage section; inspect the emitted symbol and ELF section.

## Unmatched frontiers (no executable-byte credit)

### fn_1_5C83C

GC/1.3.2. A successive conversion / reciprocal / subtraction expression
reduces the residual from seven differing words to six, with no shape edits.
Four meaningful fade/vector helper boundaries compiled identically to the
baseline. Five expression alternatives and a fresh captured-allocator pass
(48 proposals over two seeds) did not close it. Preserve the simple successive
reciprocal version; do not infer closure from its high raw objdiff score.
Portable sources and compiler profiles: effect-fade-frontier.json.gz.

### fn_12_BBC0

GC/1.3.2, -use_lmw_stmw on. Refreshed baseline: 12 differing words / three
shape edits. Coordinate-copy ordering and first-window aliases did not close.
A single consumed-pointer expression has nine differing words but five shape
edits: it changes the tail's constant-folding/scheduling tradeoff rather than
closing the function. Retain both frontiers, not just a raw-score winner.
Portable evidence: movie-reader-window-frontier.json.gz.

### fn_1_11C08

The historical higher-score body has two substantive errors: the preset
index is s16 at offset 4 (retail lha), not s8, and Z interpolation must use
frames * (speed * (target - current)), not (speed * frames) * delta.
Do not restore either error merely to improve a similarity score.

The retained natural source uses LiveCameraPreset, the approved LC_BASE
hardware definition, and a real three-component smoothing helper. Its explicit
fp_contract pragma preserves the measured non-fused arithmetic. It has 52
differing instruction words and no shape edits. Optimizer/profile alternatives
and two fresh captured-allocation rounds (96 proposals) did not close it.
The older raw-score best is not an admissible continuation seed. Synthetic
one-field carrier variants emitted by the stock engine were excluded from
the portable frontier rather than treated as natural-C improvements.
Portable clean sources/settings: camera-preset-smoothing-frontier.json.gz.

Replay any archive with:

    uv run tools/fzgx.py fixup --archive state/repairs/ARCHIVE.json.gz

All three functions remain blocked and unauthored. These partials add no
verified code progress.

## Read-only CLI probe correction

Explicit fixup --body probes used to silently return zero functions when the
selected function was claimed or blocked. load_records now accepts those
states only for an explicit body without --apply. Default saved/corpus scans
and application retain the original ownership filter.

The exact claimed-function CLI reproduction now compiles one fn_1_11C08 body
and reports its measured 52-word residual. Direct checks of load_records prove
that --apply and implicit saved-source loading still exclude that claim.
No unit tests were added; verification used the real source and compiler.
