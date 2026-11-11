# Completion recovery: protected data ownership

The owner requested targeted completion work while keeping the GPT fleet lane disabled. This cohort recovers existing, previously uncommitted data-source work; it is not newly decompiled executable code.

## Reproduced pending imports

- 61 added `declared-bss` provenance records across 48 C translation units, totaling 19,084 bytes.
- Modules: main, main_rel, customize, interview, movie_module, winning.
- Re-ran `fzgx.dataimport.import_data(Project(), names, regenerate=True)` without applying changes. All 61 objects passed; none were skipped.
- Every generated source was byte-identical to the pending source, and saved address, size, section, alignment, source ownership, definition, method and SHA-256 fields agreed with the fresh compiler proof.
- Ran configure, Ninja at two jobs, explicit DTK check of `config/GFZE01/build.sha1` (16 files OK), and lint (0 findings).
- Validated all 61 records again with `dataimport.validate` against the actual Ninja-produced objects, not just importer probe objects.
- Included the dependent pending DOL/interview/movie_module/winning splits and DOL force-active symbol annotations. main_rel/customize ownership was already committed but their source files/provenance were not, so they are included for complete reproducibility.

Local detailed receipts: `.fzgx/completion-existing-data-reprobe.json` and `.fzgx/completion-existing-data-gate.log`.

## Recovered executable-source ownership

Two existing accepted bodies were missing their unit manifest records: `fn_14_C850` (pilotpoint, 1,056 bytes) and `fn_8_704` (title, 80 bytes). Both freshly checked at exact 100%, but simply registering them failed the complete link hash gate. Registration was rolled back and all 16 original hashes were verified again before correcting the cause.

Binary comparison isolated the failures:
- title differed in just two bytes: BSS size grew from 0x556 to 0x564. Seven unused private scaffold declarations emitted 12 BSS bytes plus alignment. Removing these declarations preserved the exact code match and prevented the extra BSS allocation.
- pilotpoint's code was identical, but two anonymous integer-to-double bias literals expanded rodata and shifted the following section. `@40` is the first eight retail bytes at `lbl_14_rodata_60` (4330000080000000); `@42` matches `lbl_14_rodata_110` (4330000000000000). Registered the established pool retarget/drop pipeline with these proven owners.

The corrected manifest registers the existing pilotpoint TU body and title standalone body as matching. Configure + Ninja rebuilt 832 steps, all 16 hashes passed, and lint returned 0 findings. Both actual registered build objects then checked at exact 100%. Build report source-linked code increased from 1,132,692 to 1,133,828 bytes: 1,136 recovered link-owned bytes, not two newly solved functions. Pilotpoint's pending TU edit is included, resolving its source protection too.

Local receipts: `.fzgx/completion-orphan-registration.json`, `.fzgx/completion-orphan-registration-fixed-gate.log`, and the failed and rolled-back gate logs. The failed candidate RELs and section-difference report are retained in `.fzgx/completion-structural-frontier/`.

## Remaining source-ownership warnings

Configuration now reports only missing `src/dol/fn_80036AC4.c` and missing configuration for `rel/sel/fn_10_266AC.c` and `rel/movie_module/fn_12_23410.c`. The authored-source audit decreased from three to two credited-but-unauthored functions and from 1,593 to 1,592 functions to write. The selector/movie bodies are not treated as safe link recoveries without a fresh per-object and complete-hash proof.

## Compiler-reproduced structural frontier

The machine-readable dossier is `docs/COMPLETION-FRONTIER-REPROBE-2026-10-07.json`. It includes source SHA-256, compiler identity, residual rows, row classification, and register-flow evidence for five archived candidates. These were evaluated privately; no source claims, attempts, compiler caps or provider cooldowns were reset.

- `sample:_prolog`: fresh baseline 98.56863%, adjusted 98.05%, five differing rows. The initial loop check and indexed-vs-pointer unroll are the isolated residual. A pointer/countdown formulation disabled retail loop unrolling and regressed badly; an explicit pointer with a counted loop also regressed. Keep the saved baseline. Normalize colon-bearing archive names before invoking the Windows compiler, and verify the literal normalized path exists.
- `colchg_menu_disp`: fresh baseline 94.74419%, six differing rows. Register lifetime and conditional call-argument scheduling remain. A conditional argument expression regressed; retain the baseline rather than redispatch the same shape.
- `fn_13_3FC` (replay): fresh baseline 95.15212%, adjusted 62.62%, 151 differing rows. The old report's tiny-residual inference is false for this archived body. It needs broader frame/register/address-promotion reconstruction, not one more local cast retry.
- `fn_1_7D6B8` (main_rel, 2,856 bytes): fresh baseline 99.66339%, adjusted 98.74%, nine differing rows. Isolate two regions: indexed-row pointer lowering at 0x22C/0x230, and signed selection update/bit construction at 0x47C..0x4D0. There are no remaining literal-pool rows. Recover lifetimes in these regions without rebuilding the entire 714-row function or repeating global optimization toggles.
- `fn_1_13B98` (main_rel, 4,416 bytes): fresh baseline 96.88493%, adjusted 82.07%, 198 differing rows. Four pool rows are not the substantive blocker. Treat this as broad lifetime/frame structure work rather than a near-exact easy closure.

No small module was fully closed and no new unmatched function was solved in this recovery. GPT remains disabled by the owner's live control; other lanes resume unchanged after the verified commits.