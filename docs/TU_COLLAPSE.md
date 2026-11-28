# Whole-TU collapse workstream

Synthetic `.fzgxpool` layout primers are the largest known-scaffolding category (939 of the 960 owner functions in `docs/DEVICE_CENSUS.md`, 2026-11-17). They exist because each function block compiles as its own unit and cannot reproduce its translation unit's literal pool or section-base addressing. Removing them one function at a time is a measured negative frontier. A TU that compiles and links as one object (`fzgx tu-check`, `tutrial`, `collapse`) produces those layouts natively, so collapsing whole TUs is the main route to removing primers, per-function pragmas and `noprologue` scaffolding together. Collapsing alone does not retire the per-function devices, though: one pass removing each of the 75 marked devices, directives and carriers in 14 already-collapsed units retired one marked device and one carrier; the others still differ (see "Collapsed-unit inverse pass" in `docs/DEVICE_CENSUS.md`). Primers disappear with the collapse; the other devices need source recovery.

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

That intermediate version still needed a primer: without it `fn_1_154410` dropped to 99.51% and the strings no longer filled the `.data` range. **Resolved in `93147f1cb`:** all 16 functions now build in one unit without a pool map or primer. The unit owns retail `.rodata` at `0xD508–0xD598` and `.data` at `0x46408–0x46468`. Use it as a control for recovering real literal and aggregate ownership rather than stripping primer bodies in isolation.

The pilot also showed what each TU needs before it can collapse:

1. **Correct ownership**: TU boundaries, then regenerated TU headers. Regenerating moves declarations; a block that redeclares a symbol with another type (for example a scalar `lbl_1_data_49A18` against the header's `u32[5]`) and data units or import records that name the old header must follow in the same change.
2. **One declaration per symbol**: `fzgx tutruth`. Lifter-style blocks (register-mirroring locals, private struct views over the TU's section base) cannot follow shared declarations and stay self-contained. They need natural reconstruction, usually as real file-scope statics in retail order, which is also the original source shape.
3. **One compiler profile**, then `tutrial` per-function scoring and `collapse` with the full link hash as the oracle.

## Next batch: unify declarations before moving storage

An initial whole-file compile on current GFZE01 found declaration conflicts in all nine single-profile candidates probed (`effect_car`, `bg_lig`, `bg_cas`, `ranking`, `face`, `bitmap`, `car_test`, `custom_memcard`, `rob`). Use `bg_lig` as the bounded pilot (40 functions, with its first two already grouped). Resolve declarations using the definition, caller use and retail object width; compare edited functions before moving on. Once the whole file compiles, score every function and check the native data extents and relocation owners before re-registering any range. Expand to other files only after a linked, primer-free range lands.

In `bg_lig`, removing an unused copy-helper prototype, replacing one-word struct views of `lbl_801A66A0` with its measured `u32` object, and using the signed result type of `fn_1_66B8` preserve the linked binaries. The five `fn_1_681C` callers now share a byte-sized index and an untyped output pointer: the callee masks the index to eight bits and writes a 12-byte result. Widening the caller declaration to `u32` instead changed instructions in four callers; the byte-sized declaration preserves all five. The declared return type of `fn_1_DA6A8` was also reconciled with its `void` definition.

The state setup block now uses the same local declarations as the rest of `bg_lig`, and `bg_san`'s `fn_1_DA3A0` definition no longer claims two float inputs that its body and callers never use. The `fn_1_D9D8C` state/model types are still local views, not a shared layout recovery. The current first whole-file blocker is now incompatible private arrays named `fzgx_pool_table1`, emitted by separate function primers. Recover their common retail literal ownership before attempting to link the whole file; merely renaming the arrays would retain the synthetic copies.

Negative controls: compiling without the existing primers changed five instruction words in `title:fn_8_0` (literal-base displacements) and twenty in `sel:fn_10_261E4`. Neither edit was retained. This favors native pool ownership over more isolated primer deletions.

The two lighting render paths and `background.c` now share the 0x40-byte `BackgroundQuad` layout. The GX declarations agree with the DOL definitions, and the callback forward declaration agrees with its current body. Changing the callback body's argument and introducing a new source-pointer local changed the linked REL, so those variants were not retained.

The scratch whole-file probe now compiles all 40 registered `bg_lig` functions with its eight primer regions removed, preserving the live velocity helper and `lig_down` initializer. Against the extracted retail objects, 31 have identical instruction words; nine differ. Six have equal-size bodies with differences confined to the lower instruction halfwords, which is a lead for literal/relocation analysis, not proof of a relocation-only mismatch. `fn_1_D8D58` has equal size but also differs in upper halfwords. `fn_1_D83E4` and `fn_1_D8878` grow by six and eight words, respectively. Next compare the six equal-shape functions' load displacements and relocation targets against the measured retail pool before changing splits. This probe is not a linked match; production still uses its existing primers and splits.

Follow-up: the six equal-shape functions' 113 differing words are all `lwz`, `lfs`, or `lfd` displacements, and all 113 loads read the same bytes as retail. Naming the `fn_1_D8D58` entry's flag word and declaring its zero temporary before its one temporary preserves the retail build and eliminates that function's register swaps in the whole-file probe. Its 13 remaining differences are also verified same-payload load displacements. This comparison resolves each function's retail base (`0x6360` or `0x6490`) and checks the scratch object's `.rodata` HA/LO pair before comparing the loaded bytes. The scratch compiler uses one 0x1b0-byte section and coalesces nine pairs of retail load slots observed across the original six functions; the measured retail extent is 0x2c8 bytes. A uniform relocation rebase cannot recover those separate slots.

The two instruction-count differences came from compiler settings leaking across the former function boundaries. Resetting `fp_contract` after `fn_1_D7758` removes six extra instructions from each of `fn_1_D83E4` and `fn_1_D8878`; resetting `opt_propagation` after `fn_1_D83E4` removes the two extra register moves still present in `fn_1_D8878`. Both resets are now in the source. All 40 probe functions have retail instruction counts: 31 match after masking relocation fields, and the remaining nine differ at 151 load displacements. Resolving the retail and probe pool bases shows that all 151 loads read the same bytes as retail. This narrows the observed instruction differences to pool layout; it does not establish full relocation equality or a linked match.

The whole-file probe has 395 code relocation sites with matching function-relative positions and types. Of these, 355 retain the same symbol and addend; 18 refer to the two strings and jump table that MWCC emits at their retail `.data` offsets under local names (all 11 table relocations match); the remaining 22 are retail `.rodata` references replaced by local pool references. The leading 14 functions are now one production object without a primer or pool map: `.text 0xD5C70–0xD6748`, existing `.rodata 0x6328–0x6358` and `.data 0x3DBE8–0x3DC38`. The compiler emits the existing 0x30 read-only bytes and 0x4c initialized data bytes; the linked extent includes four trailing zero bytes. The `0x6358` constant remains external. All 16 linked USA artifacts still match. This is a verified partial build grouping, not an asserted original TU boundary.

Two more exact partial groups are now in production: nine functions at `.text 0xD720C–0xD7758` and two at `.text 0xD8EEC–0xD8FC4`. Both emit retail-identical masked instruction words. The first retains the existing `fn_1_D7274` binding to `lbl_1_rodata_64A0`, with the private symbol renamed from `@33` to `@37` by the grouped compile. The second needs no pool binding. No retail data splits moved, and all 16 linked USA artifacts still match.

Boundary control: compiling only the prefix before `fn_1_D720C` leaves all 57 displacement differences in `fn_1_D6748` and `fn_1_D6C10`. Compiling those two functions alone without primers gives `fn_1_D6748` retail-identical masked words and leaves 15 differing load displacements in `fn_1_D6C10`. Keeping the primers in that pair instead gives 16 differing words in `fn_1_D6C10` and expands the emitted pool to `0x148` bytes, so neither direct merge is ready. Trace the first-use order of `fn_1_D6C10`'s scalar constants and velocity aggregate against the 0x130-byte retail object at `0x6360`. Neither experiment establishes an original TU boundary.

In the standalone `fn_1_D6C10` unit, only one of 38 individual scalar primer-assignment removals preserved both code and all `0x130` pool bytes: the `0.0f` assignment in `fzgx_pool_prime2`. The compiler still emits the slot at `+0x10`. Its removal renumbers many private literals, but none of their 22 individual bindings is referenced by live code: the two pool relocations target `...rodata.0` and the loads use fixed offsets. After dropping the discarded primer section, retargeting only the base preserves all 1,532 unmasked `.text` bytes and all 25 code relocation tuples. The production map now contains only that base binding; no splits moved.

The two-function probe's `.rodata` agrees with retail through `+0x6b`. It puts the zero-velocity aggregate at `+0x68`, where retail instead has a nonzero word at `+0x6c`; retail's zero-velocity loads are at `+0xdc/+0xe0/+0xe4`. All 15 displacement differences occur at or beyond this divergence. The retail `800.0f` and `60.0f` loads also interrupt the later sequence at `+0x80` and `+0xa0`; moving the zero vector alone would not repair that order. In the standalone production unit, replacing the zero-vector primer/helper pair with one named `static const` vector kept all 0x130 `.rodata` bytes but shortened the function from 383 to 379 words. Keep the helper and primer for now. The obsolete C view of `lbl_1_rodata_6360` was dead and is removed; the compiled pool binding is unchanged.

The spawn routine and its `bg_san.c` caller now share the `Vec3 *` declaration. The caller's entry begins with a position vector and still has its flag word at `+0x20` and stride `0x24`. The primer-free whole-file probe still compiles after the type change, with the same 24 displacement differences in `fn_1_D6C10`. Without the remaining `0.05` primer, swapping arithmetic operands, hoisting a local, and extracting the addition into an inline helper all left the same two swapped pool slots. Further lexical-only rewrites are unlikely to help; investigate what makes MWCC emit a literal before the first live use instead.

A relocation scan of the indexed retail `main_rel` objects found only the pool-base pairs in `fn_1_D6748` and `fn_1_D6C10`. The former's pool loads end at `+0x60` (8 bytes); the latter loads `800.0f` at `+0x80` for the spawn cutoff and `60.0f` at `+0xa0` for lifetime scaling. No load through either base accounts for the nonzero word at `+0x6c` or the other intervening nonzero slots. This identifies current retail users, not the original producers of the unread bytes; adding more neighboring functions to the probe is not justified by a direct reference. At the pool tail, deleting only the primed `0.02` leaves the compiler to emit it from the particle size calculation at `+0x128`, with all 383 masked words and 0x130 pool bytes unchanged. The literal's private symbol changes from `@154` to `@252`, so the binding must follow it without changing the retail target. Deleting both tail assignments swaps the two doubles at `+0x120/+0x128` and changes two loads. Keep the `0.05` primer until native C reproduces that order as well.

Using the shared `Vec3` layout for `lbl_8006E1C0` and preserving the `f32` return of the in-place normalize helper `lbl_8006D668` clears the vector declaration conflicts without changing the USA binaries. `fn_1_D7EF4` and its callers now share the 0x30-byte `LigParticle` layout. The scratch probe must retain `lig_down`, a live vector initializer inside a primer region, when dropping the layout-only code. Retail's `fn_1_58C4` reads an unsigned byte and takes no arguments. Declaring a byte return at all `bg_lig` call sites changed code in nine functions under MWCC, so the linked build keeps a consistent local `s32` declaration, with explicit unsigned comparisons where retail uses `cmplwi`. This is not a global ABI cleanup. The scratch probe gets past that conflict and an unused duplicate `LigEvent` typedef; shared header declarations now also resolve the `fn_1_D8CA8` and `fn_1_D8D08` state-pointer conflicts, preserving the existing 0xac-byte entry stride and all linked bytes. The callback queue and traversal (`fn_1_D8784`, `fn_1_D8EEC`) now also use shared declarations. The primer-free probe gets past those declarations and an unused duplicate declaration of `fn_1_5448C`. It next stops at `fn_1_D8D58`, where the caller and definition use different state views and the name `LigObject` is reused for other layouts.

The primer-free scratch build gets past `lbl_1_data_2A7E0`, `fn_1_D79E4`, and `fn_1_D7A10`: the spawn block uses the shared global declaration, the clear helper's forward declaration agrees with its definition, and the segment update has one tagged parameter type. It now also gets past the draw-entry and callback declarations (`fn_1_D7B7C`, `fn_1_D7C44`) and the conflicting culling and allocation declarations (`fn_1_54E34`, `fn_1_548AC`). The production build still uses the original split and primers. The candidate retail pool at `0x6360–0x6628` is covered by five contiguous objects with no relocations inside their payloads; this is extent evidence, not proof of a native compiler-emitted pool.

The `fn_1_D8D58` caller and definition now share the same state and entry types in `bg_lig.h`. Both local `LigVec` definitions now use the shared `Vec3` layout, resolving the camera-helper declaration conflicts. Keep the local math helpers at their existing declaration sites: moving the shared offset helper to the common header changed MWCC's anonymous literal labels in unrelated blocks and invalidated their pool maps. Distinct local names preserve the current builds. The caller now uses `fn_1_D83E4`'s tagged state type and unsigned index. The two render blocks also agree on the matrix helpers' pointer declarations and the Z-rotation argument (both retail callers load it with `lha`). The primer-free probe gets past those conflicts and stops at `fn_1_9EDE8`, whose callers use different render-packet types.

### `bg_lig.c` pilot closure: `0x6360` emission proof, `lbl_1_data_2ABAC` boundary, and 24-function primer-free group

1. **Why `fn_1_D6748` + `fn_1_D6C10` (`lbl_1_rodata_6360`, `0x6360..0x6490`, `0x130` bytes) cannot merge without a primer**:
   - MWCC emits a function's local aggregate initializers (`Vec3 zero = {0.0f, 0.0f, 0.0f}`) into `...rodata.0` during front-end parsing *before* the back-end emits that function's new scalar float/double literals.
   - `fn_1_D6748` (called by `fn_1_D41D8`) accounts for `+0x000..+0x067` of `lbl_1_rodata_6360` (`Vec3 {0, 0, 0}` at `+0x000..+0x00b` followed by its 15 scalar literals in exact first-use order).
   - `fn_1_D6C10` (called by `fn_1_DCB10`) has its local aggregate initializer `Vec3 {0, 0, 0}` at `+0x0dc..+0x0e7`, and all 10 of `fn_1_D6C10`'s unique scalar literals (`20.0f`, `0.09`, `30.0`, `10.0f`, `1.5f`, `0.02f`, `0.1`, `221.0f`, `0.05`, `0.02`) follow in exact first-use order at `+0x0e8..+0x12f`.
   - Consequently, the `0x74`-byte middle region `+0x068..+0x0db` (`Vec3 {0, 1, 0}`, `Vec3 {0, 0, 0}`, `800.0f`, `0.008`, `10.0`, `50.0`, `60.0f`, `2.5f`, `85.0f`, `21.0f`, `0.04`, `0.08f`, `182.04444885253906`, `1.5`, `Vec3 {0, 1, 0}`) was emitted into `...rodata.0` *before* `fn_1_D6C10` was compiled—by dead-stripped unreferenced particle-spawner function(s) between `fn_1_D6748` (`bg_lig` particle helper) and `fn_1_D6C10` (`bg_por` particle helper called by `fn_1_DCB10`) whose `.text` was stripped by `mwld` while their pooled `...rodata.0` entries remained and were reused by `fn_1_D6C10` (`800.0f` at `+0x080`, `60.0f` at `+0x0a0`, `182.04444885253906` at `+0x0c0`).
   - `fn_1_D6748`'s `units.json` pool map was simplified from 17 entries down to the single base binding `"pool": {"...rodata.0": "lbl_1_rodata_6360"}`.
2. **True stage TU boundary between `0x6360` and `0x6490` from `lbl_1_data_2ABAC`**:
   - Like `bg_tow.c` (whose `OSPanic("bg_tow.c", ...)` sits in its 9th handler `fn_1_154410`), each background stage TU registers 9 handlers in the stage handler table `lbl_1_data_2ABAC`. `bg_lig.c`'s 9th/last handler is `fn_1_D5C70` (which panics with `"bg_lig.c"` at lines `0x577`/`0x57e`).
   - `fn_1_D720C .. fn_1_DA6A8` (29 functions: 9 stage handlers `fn_1_D720C`, `fn_1_D7274`, `fn_1_D744C`, `fn_1_D74C4`, `fn_1_D75CC`, `fn_1_D7688`, `fn_1_D76EC`, `fn_1_D8F4C`, `fn_1_D8FC4` plus their 20 helpers, currently split across the second half of `src/rel/main_rel/bg_lig.c` and the head of `src/rel/main_rel/bg_san.c`) form a single retail stage TU (`bg_san`) sharing `.rodata` `0x6490..0x6628` (`0x198` bytes), `.data` `0x3DC50..0x3DC70`, and `.bss` `0x7AD78..0x7ADB8`.
   - This explains why the old 40-function whole-file `bg_lig.c` probe coalesced 9 literal pairs: `0x6360` (`fn_1_D6748..fn_1_D6C10`) and `0x6490` (`fn_1_D720C..fn_1_DA6A8`) belong to separate retail TUs with separate `.rodata` pools.
3. **Production consolidation of the 24-function `fn_1_D720C .. fn_1_D8F4C` group**:
   - All 24 trailing functions of `src/rel/main_rel/bg_lig.c` (`fn_1_D720C .. fn_1_D8F4C`, `.text 0x000D720C..0x000D8FC4`) are now consolidated into a single production compile unit (`rel/main_rel/bg_lig/fn_1_D720C.c`) with zero `.fzgxpool` layout primers, retiring all 7 remaining primers in that range (`fn_1_D7758`, `fn_1_D7A10`, `fn_1_D7C44`, `fn_1_D7EF4`, `fn_1_D83E4`, `fn_1_D8878`, `fn_1_D8D58`) and replacing the external `.rodata` array workarounds in `fn_1_D720C`, `fn_1_D7B7C`, `fn_1_D7EF4`, and `fn_1_D8784` with natural local initializers and literals.
   - `src/rel/main_rel/bg_lig.c` is now consolidated from 19 production units down to 5 (`fn_1_D3C00.c` [6 fns], `fn_1_D52DC.c` [8 fns], `fn_1_D6748.c` [1 fn], `fn_1_D6C10.c` [1 fn], `fn_1_D720C.c` [24 fns]), reducing `.fzgxpool` primer blocks in `bg_lig.c` from 8 down to 1 (`fn_1_D6C10`, caused by dead-stripped TU pool entries). All 16 USA binaries and `fzgx lint` pass.

### `bg_lig.c` / `bg_san.c` boundary realignment and 73-function `bg_san.c` native-ownership consolidation

- Realigned `bg_lig.c` (`0x000D5C70..0x000D720C`, 16 functions `fn_1_D5C70..fn_1_D6C10`) and `bg_san.c` (`0x000D720C..0x000DCBF4`, 73 functions `fn_1_D720C..fn_1_DCB9C`) in `config/GFZE01/main_rel/tus.json` and moved the 24 `fn_1_D720C..fn_1_D8F4C` blocks from `src/rel/main_rel/bg_lig.c` to `src/rel/main_rel/bg_san.c`, matching retail handler table `lbl_1_data_2ABAC`. `bg_lig.c` now compiles cleanly whole via `fzgx tu-check rel/main_rel/bg_lig.c` and builds in 3 production units (`fn_1_D5C70.c` [14 fns], `fn_1_D6748.c` [1 fn], `fn_1_D6C10.c` [1 fn], 1 primer remaining).
- Consolidated all 73 `bg_san.c` functions from 50 build units (`rel/main_rel/bg_lig/fn_1_D720C.c` plus 49 old `rel/main_rel/bg_san/*.c` units) into **4 primer-free native-ownership units**: `fn_1_D720C.c` (29 fns, `.rodata 0x6490..0x6628`, `.data 0x3DC50..0x3DC70`, `.bss 0x7AD78..0x7ADB8`), `fn_1_DA7B8.c` (12 fns, `.rodata 0x6628..0x6638`), `fn_1_DAD68.c` (16 fns, `.rodata 0x6638..0x66D0`, `.data 0x3DC70..0x3DC78`, `.bss 0x7ADB8..0x7ADE8`), and `fn_1_DC204.c` (16 fns, `.rodata 0x66D0..0x6750`).
- Retired all 6 `.fzgxpool` primer blocks (`fn_1_D9224`, `fn_1_D9D8C`, `fn_1_DB268`, `fn_1_DB53C`, `fn_1_DB9B0`, `fn_1_DC764`) and all 8 `"pool"` maps across `bg_san.c` (`1,373 -> 1,365` `mwcc_pool` units), deleted `src/rel/main_rel/data/{lbl_1_bss_7AD78,lbl_1_bss_7ADB8}.c`, trimmed `lbl_1_rodata_6358.c` (`0x6358..0x6490`) and `lbl_1_data_3DC38.c` (`0x3DC38..0x3DC50`), and removed 17 migrated data-import records from `state/dataimports/GFZE01.json` (plus `lbl_1_data_3DC70` `size:0x8 -> size:0x4` in `symbols.txt` / `s32` in `bg_san.h`).
- The `fn_1_72648` declarations now agree with its parameterless definition in `screen_effect.c`. Dropping the superfluous argument in `fn_1_DC2F8` preserves the `fn_1_DC204` group's instruction bytes and relocations. Whole-file `tu-check` now reaches the `fn_1_103090` conflict: the TU prologue uses `void *`, the earlier block declarations use a lighting-entry view, and the definition in `cloth.c` uses `ClothState *`. The four production groups are unchanged.

### `effect_car.c`: native resource setup and registration group

- Retail setup `fn_1_680F8` and registration `fn_1_68248` are adjacent (`.text 0x680F8..0x68284`) and reference the same `"effect_car.c"` filename with line numbers `0xC7` and `0xE2`. Setup is also the sole retail user of the `0x60`-byte BSS object at `0x6C878`. The following function, `fn_1_68284`, uses the literal pool at `0x2D70`; it is not part of this build group.
- The two functions now compile together with GC/1.3.2, owning `.data 0x1D8A8..0x1D8B8` and `.bss 0x6C878..0x6C8D8` directly. The compiled `.text` is identical to the extracted `0x18C` bytes, with the same 18 relocation offsets, types, symbols and addends. The compiler emits the exact 13-byte filename and 96-byte BSS extent; the three trailing initialized-section alignment bytes are zero in retail and match at link time. Both standalone data sources and their import records were removed. This group uses no pool map or primer and retires none elsewhere. All 16 hashes and lint pass.
- Production units fell from 37 to 36 without claiming that the prefix is a separate original TU. The common prologue and the self-contained `fn_1_68284` block now use a single `CarObject` declaration and the shared `Vec3`/`Vec3f` definitions. The whole-file probe now stops at the duplicate `EventNode` definition.

### `bg_cas.c`: declaration and boundary checks

- `lbl_1_data_2ABAC` registers `fn_1_FA6C0` through `fn_1_FB798` as the nine `bg_cas` handlers; the last handler passes `"bg_cas.c"` to `OSPanic`. The next nine-entry row starts at `fn_1_FE5E0`, inside the current `bg_cas.c` mapping. Trace its helpers and pool users before treating all 81 functions as one original TU.
- The first two production groups, headed by `fn_1_FA6C0` and `fn_1_FB870`, now use the same three-float `Vec3` definition. The latter group also declares the `u32` length that `fn_80008BEC` actually takes. Their existing `.rodata`, `.data` and `.bss` splits are unchanged and all 16 retail hashes pass. Whole-file `tu-check` now reaches the conflict over the pointer argument and return type of `GXLoadTexMtxImm`; the two groups have not been merged.

### `ranking.c`: native conversion constants in `fn_1_1598C4`

- The `0.0999000967f` scale and MWCC's unsigned integer-to-float conversion constant belong to the same 16-byte retail slice, `.rodata 0xDAE8..0xDAF8`. With an ordinary float literal, GC/1.3.2 emits both constants and the natural four-byte alignment gap in retail order. An explicit `const` definition instead duplicates the float when MWCC folds the reference.
- The unit now owns that slice natively, with identical 540 instruction bytes and all 30 relocations after resolving local constants by address. The `.rodata` bytes also match exactly. The neighboring imported ranges remain unchanged in content and have separate owners on each side. Two import records and one pool map were retired; no `.fzgxpool` helper was involved. All 16 retail hashes and lint pass.

### `bg_for.c`: compiler profile alignment

- The draw routines pass the shared `Vec3` layout to `fn_8006EE70`, matching its DOL definition. Consumers of `lbl_1_rodata_6780` agree on its read-only declaration and keep their existing pool views. The byte-copy, vector-normalization, translation, and matrix-angle callers now agree on their declarations. The whole-file probe reaches a duplicate `fzgx_pool_prime1` definition in `fn_1_DEDC4`. No storage changed hands.
- GC/1.3.2 scratch builds without primers preserved `.text` size in all eight primer-bearing units but matched none. Six units changed only floating-point load displacements, including eight in `fn_1_E1A00` and ten in `fn_1_DF6AC`. `fn_1_DE4B0` and `fn_1_DEDC4` also changed other instructions. These experiments did not alter production source or pool maps.
- `fn_1_DF6AC` now loads −1, 0, and 1 directly from offsets `0x0`, `0x20`, and `0x28` of the existing retail pool at `lbl_1_rodata_6780`. Keeping a single pool pointer and naming the computed weight preserves the retail loads and multiply operand order. All 1,296 instruction bytes and 23 relocations match; the unit emits no local pool and no longer uses a primer or pool map. The shared storage is unchanged.
- `fn_1_E07B8` also reads the existing pool directly, including the three slide constants at offsets `0xF8`, `0xFC`, and `0x100`. A named intermediate for the initial scale preserves the original two-multiply sequence and register order. All 3,152 instruction bytes and 44 relocations match without a local pool, primer, or pool map. The shared storage is unchanged.

#### Finding the next shared-pool batch

After building GFZE01, run `python3 tools/fzgx.py poolcensus --json`. It groups units by module and retail pool base when the extracted `.text` has one zero-addend HA/LO pair to that base and no relocation to another symbol named by the pool map. At the current baseline, 449 of 1,362 pool-mapped units meet that screen. The largest cohorts are `main_rel:lbl_1_rodata_2950` (72), `sel:lbl_10_rodata_158` (40), and `main_rel:lbl_1_rodata_2D70` (28).

Recover the constant layout once per pool. For each consumer, prove the base register and load widths, then check the retail bytes at each effective offset. Use direct read-only references where the source allows it, as in `fn_1_DF6AC` and `fn_1_E07B8`. A census hit is not proof that the compiler will keep the same register allocation or that the entire pool can move. Keep units with compiler-emitted conversion biases or structural codegen differences out of the first batch. In `bg_for.c`, `fn_1_DD890` still differs at its integer-to-float conversion, `fn_1_E1A00` grows by two instructions, and `fn_1_DFBBC` retains register differences despite recovering its retail pool offsets. None of those probes was applied. Require exact instruction and relocation comparisons per unit and the 16-image hash gate on the combined batch before landing.
- `fn_1_DD4DC`, the only explicitly pinned GC/1.3 unit in this mapping, produces a byte-identical object with GC/1.3.2 under the same production flags (948 bytes of `.text`, 64 relocation entries). It now uses the same compiler as its neighbors. No unit or pool ownership changed.
- The whole-file probe uses the shared course-state definition from `globals.h`, keeping the spotlight view at offset `0x3C`, and no longer redeclares the owned camera BSS object with an unused partial type. After removing unused `fn_8006F1F0` declarations and reconciling the draw-helper declarations, it reached `fn_1_DD890`. That block now shares the object layout and prototype used by `fn_1_DD4DC`. It passes matrix addresses directly to `lbl_8006DFE8`, whose retail entry reads a full matrix through the incoming pointer. The rotation helpers now consistently take the callers' signed angle values and declare no return value, matching their matrix-update role. Whole-file compilation next stops at the conflicting vector-pointer declaration of `fn_8006EE70`.
- `fn_1_E1934` walks adjacent objects and calls `fn_1_E1408` on each pair. Correcting that call's declaration to the callee's `s32` return and tagged pointer arguments lets the adjacent functions build together without data sections or pool rewriting. The GC/1.3.2 group owns `.text 0xE1408..0xE1A00` (1,528 bytes); its instruction bytes and all 16 linked hashes match retail. This reduces the mapping from 16 to 15 units without asserting a separate original TU.
- `fn_1_DD4DC` calls the adjacent draw helper `fn_1_DCFA4` with the object address in `r3`; the old float parameter was unused. The two functions first matched as a pair (2,284 instruction bytes and 133 relocations) and now build with the preceding spotlight and camera functions. The six-function GC/1.3.2 group owns `.text 0xDCBF4..0xDD890`: all 3,228 instruction bytes and 166 resolved relocations match. Its existing `.rodata 0x6750..0x6780`, `.data 0x3DC78..0x3DC98`, and `.bss 0x7ADE8..0x7AE88` are unchanged; the last three `.data` bytes are linker alignment. The draw functions still reference the following retail pool externally.
- `fn_1_DDF80` and `fn_1_DE180` use the same vector helpers and three constants at offsets `0x0`, `0x20`, and `0x28` from `lbl_1_rodata_6780`. They now share the vector and pool-view types and build as one GC/1.3.2 unit owning `.text 0xDDF80..0xDE4B0`. All 1,328 instruction bytes and 19 relocations match. This group emits no data and still references the retail pool externally. The mapping now has 12 production units.

### `effect_car.c` prologue unification, `bg_san.c` TU boundary proof, and `stcoli.c` shared-pool retirements

- `effect_car.c`: removed 24 unused copied `car_types.h` declarations and unified all 11 `noprologue` blocks (`fn_1_68284`, `fn_1_68B6C`, `fn_1_694A4`, `fn_1_69BCC`, `fn_1_6A7A4`, `fn_1_6C87C`, `fn_1_6DD68`, `fn_1_6E320`, `fn_1_6F288`, `fn_1_6FFA0`, `fn_1_71024`) with the common prologue, leaving zero `noprologue` blocks and simplifying their 11 `units.json` pool maps to the single live `...rodata.0 -> lbl_1_rodata_2D70` base binding. Whole-file `fzgx tu-check` now advances to the duplicate `fzgx_pool_prime1` definition. A scratch primer-free whole-file GC/1.3.2 compile succeeds for all 37 functions (`0x360` bytes of `.rodata`, 31/37 at retail `.text` size; the remaining six size differences correspond to unreset per-block optimizer pragmas). Production units and splits remain unchanged until native `lbl_1_rodata_2D70` ownership is verified.
- `bg_san.c`: inspecting retail `.rodata` across the four already primer-free units (`fn_1_D720C` `0x6490`, `fn_1_DA7B8` `0x6628`, `fn_1_DAD68` `0x6638`, `fn_1_DC204` `0x66D0`) shows each unit emits its own separate `0.0f` and `1.0f` literals, proving they are four distinct original translation units that must remain separate.
- `stcoli.c`: retired five `.fzgxpool` primers and their `mwcc_pool` maps (`1,362 -> 1,357`) via proved direct read-only references to `lbl_1_rodata_6C8` (`fn_1_16E68`, `fn_1_17920`, `fn_1_216F0`, `fn_1_21950`) and `lbl_1_rodata_840` (`fn_1_2BD30`). Each emits zero local `.rodata`, matches retail 100.0% in `objdiff-cli` under GC/1.3.2, and passes all 16 GFZE01 retail hashes and `fzgx lint` with zero findings. Shared retail storage is unchanged.
- Cross-module shared-pool cohort retirements (`1,357 -> 1,351` `mwcc_pool` units): retired six additional `.fzgxpool` primers and their `mwcc_pool` maps via proved direct read-only references to their retail pools: `customize:fn_3_106FC` (`lbl_3_rodata_288`), `sel:fn_10_1A760` (`lbl_10_rodata_158`), `main_rel:fn_1_9C724` (`lbl_1_rodata_41F0`), `main_rel:fn_1_10A8D0` and `main_rel:fn_1_1188CC` (`lbl_1_rodata_7AB8`), and `main_rel:fn_1_E733C` (`lbl_1_rodata_6780`, GC/1.3). Each emits zero local `.rodata`, matches retail 100.0%, and passes all 16 GFZE01 hashes and `fzgx lint` with zero findings. Shared retail storage is unchanged.
- Additional `main_rel` shared-pool retirements (`1,351 -> 1,348` `mwcc_pool` units): retired three more `.fzgxpool` primers and their `mwcc_pool` maps via proved direct read-only references: `fn_1_1185B4` (`accessory.c`, `lbl_1_rodata_7AB8`), `fn_1_61370` (`effect.c`, `lbl_1_rodata_2950`), and `fn_1_A888` (`camera.c`, `lbl_1_rodata_200`). Each emits zero local `.rodata`, matches retail 100.0% under GC/1.3.2, and passes all 16 GFZE01 hashes and `fzgx lint` with zero findings. Shared retail storage is unchanged.
- `bg_cas.c` native TU consolidation (`1,348 -> 1,338` `mwcc_pool` units; `10,952 -> 10,937` total units): consolidated the 17-function contiguous retail TU `fn_1_FE5E0..fn_1_10069C` (`0x0FE5E0..0x1011CC`, `0x2BEC` bytes `.text`) into a single primer-free native unit `rel/main_rel/bg_cas/fn_1_FE5E0.c` owning its `0x150`-byte `.rodata` pool (`0x76A8..0x77F8`, previously `lbl_1_rodata_76A8[84]` in `lbl_1_rodata_7650.c`). Retired 10 `mwcc_pool` maps, 9 `.fzgxpool` primers, 16 build units, and the `lbl_1_rodata_76A8` external data import; split `lbl_1_rodata_7650.c` into `lbl_1_rodata_7650.c` (`0x7650..0x76A8`) and `lbl_1_rodata_77F8.c` (`0x77F8..0x7A50`); exposed the retail secondary entry point `mathutil_mtxA_rotate_z_s_c` (`0x8006E430`) in `src/dol/mathutil_mtxA_rotate_z.s` and `config/GFZE01/symbols.txt`. Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `effect_car.c` 9-function prefix consolidation (`1,338 -> 1,334` `mwcc_pool` units; `10,937 -> 10,930` total units): consolidated `fn_1_680F8..fn_1_6A7A4` (`0x0680F8..0x06AF70`, 9 functions, retaining `.data 0x1D8A8..0x1D8B8` and `.bss 0x6C878..0x6C8D8`) into a single primer-free GC/1.3.2 unit `rel/main_rel/effect_car/fn_1_680F8.c` with ternary `clampf`, retiring 5 `.fzgxpool` primers (`fn_1_68284`, `fn_1_68B6C`, `fn_1_694A4`, `fn_1_69BCC`, `fn_1_6A7A4`), 4 `mwcc_pool` maps (keeping the single `...rodata.0 -> lbl_1_rodata_2D70` base because trailing `fn_1_6C87C..fn_1_723E0` share `lbl_1_rodata_2D70` across dead-stripped retail pool entries starting at `+0x14C`), and 7 build units. Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `face.c` 15-function consolidation (`1,334 -> 1,333` `mwcc_pool` units; `10,930 -> 10,915` total units): consolidated `fn_1_D2D24..fn_1_D2FB0` (`0x0D2D24..0x0D2FC0`, 9 functions) into `rel/main_rel/face/fn_1_D2D24.c` and the 6-function debug-window loader TU `fn_1_D2FC0..fn_1_D31E0` (`0x0D2FC0..0x0D3214`) into `rel/main_rel/face/fn_1_D2FC0.c` owning `.data 0x3DB40..0x3DBC0` natively. Retired 1 `.fzgxpool` string primer, 1 `mwcc_pool` map, 3 `noprologue` blocks, 15 build units, `src/rel/main_rel/data/{lbl_1_data_3DB40,lbl_1_data_3DB58}.c`, and 3 migrated data-import records. Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `bitmap.c` 21-function TU consolidation (`1,333 -> 1,332` `mwcc_pool` units; `10,915 -> 10,895` total units): consolidated all 21 bitmap functions `fn_1_47AD4..fn_1_48780` (`0x047AD4..0x0487EC`) into a single primer-free, pool-map-free GC/1.3.2 unit `rel/main_rel/bitmap/fn_1_47AD4.c` (using `lbl_1_data_1A364` directly for `".lz"`). Retired 1 `mwcc_pool` map, 7 `noprologue` blocks, and 20 build units. Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `ranking.c` 60-function consolidation (`10,895 -> 10,837` total units): consolidated the 33-function unpooled run `fn_1_156198..fn_1_156B18` (`0x156198..0x156C08`) into `rel/main_rel/ranking/fn_1_156198.c` and the 27-function tail run `fn_1_159440..fn_1_15B698` (`0x159440..0x15B70C`, retaining native `.rodata 0x0000DAE8..0x0000DAF8`) into `rel/main_rel/ranking/fn_1_159440.c`, both under GC/1.3.2. Retired 58 build units and 6 `noprologue` blocks (`fn_1_156218`, `fn_1_1567A8`, `fn_1_1568C4`, `fn_1_1596DC`, `fn_1_159804`, `fn_1_1598C4`). Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `spline.c` 105-function consolidation (`10,837 -> 10,737` total units): consolidated 5 contiguous unpooled GC/1.3.2 runs — `fn_1_F4F08..fn_1_F5B84` (14 fns, `0x0F4F08..0x0F5B88`), `fn_1_F7B2C..fn_1_F9C6C` (58 fns, `0x0F7B2C..0x0F9CA0`), `fn_1_F9CD0..fn_1_F9E4C` (12 fns, `0x0F9CD0..0x0F9E80`), `fn_1_F9FB4..fn_1_FA180` (11 fns, `0x0F9FB4..0x0FA1A8`), and `fn_1_FA450..fn_1_FA69C` (10 fns, `0x0FA450..0x0FA6C0`) — retiring 100 build units and 6 `noprologue` blocks (`fn_1_F8AFC`, `fn_1_F8C50`, `fn_1_F8E30`, `fn_1_FA01C`, `fn_1_FA0A0`, `fn_1_FA0BC`). Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `main_rel` zero-edit unpooled consolidation (`10,737 -> 9,869` total units): consolidated 245 compiler-verified contiguous unpooled GC/1.3.2 runs (1,113 functions -> 245 build units, retiring 868 build units) across 34 `main_rel` TUs (`car`, `font`, `memcard`, `sel_static_disp`, `effect`, `phys`, `archive`, `game`, `_prolog`, `camera`, `ghost`, `stcoli`, `enemy_ctrl`, `replay`, `load`, `driver`, `sound`, etc.). Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- Secondary-REL zero-edit unpooled consolidation (`9,869 -> 9,824` total units): consolidated 27 compiler-verified contiguous unpooled GC/1.3.2 runs (72 functions -> 27 build units, retiring 45 build units) across `customize`, `interview`, `option`, `sel`, and `title`. Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `ranking.c` primer-free 35-function consolidation + `main_rel` `noprologue`-bridging batch (`1,332 -> 1,331` `mwcc_pool` units; `9,824 -> 9,810` total units): extended `rel/main_rel/ranking/fn_1_156198.c` to `fn_1_156198..fn_1_156D9C` (`0x156198..0x156F54`), generating the 56-byte `lbl_1_rodata_D8C8` prefix (`0xD8C8..0xD900`) natively without `.fzgxpool` primers (retiring 2 primers, 1 `mwcc_pool` map, and `fn_1_156D9C`'s `noprologue`), and bridged 6 `noprologue` runs across `font`, `live_camera`, `sel_static_disp`, and `bg_common` (retiring 14 build units and 10 `noprologue` blocks total). Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `main_rel` `noprologue` retirement + `effect.c` `fn_1_59514..fn_1_5962C` primer-free prefix (`1,331 -> 1,330` `mwcc_pool` units; `9,810 -> 9,774` total units): retired 51 `noprologue` blocks across 20 `main_rel` TUs and merged 23 newly contiguous unpooled runs (retiring 35 build units), plus merged `effect/fn_1_59514..fn_1_5962C` primer-free (exact 64-byte `lbl_1_rodata_2950` prefix, retiring 1 `.fzgxpool` primer, 1 `mwcc_pool` map, and 1 build unit). Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- Dolphin SDK (`main.dol`, GC/1.2.5n) 22-TU consolidation (`9,774 -> 9,703` total units): consolidated 93 functions across 22 same-TU Dolphin SDK runs — including `EXIBios` (`SetExiInterruptMask..EXIGetID`, 23->1), `dvdlow` (`DVDLowSeek..DVDLowReset`, 10->1), `CARDBios` (`TimeoutHandler..__CARDEraseSector`, 7->1), `OSInterrupt` (`__OSInterruptInit..__OSDispatchInterrupt`, 5->1), `Pad` (`SPEC0_MakeStatus..PADSetAnalogMode`, 4->1), `CARDBlock` (`EraseCallback..__CARDUpdateFatBlock`, 4->1), `OSRtc`, `dvdfs`, `Padclamp`, `ai`, `dsp`, `CARDStat`, `OSFont`, `OSLink`, `OSMemory`, `dsp_task`, `CARDDelete`, and `GXFifo` — retiring 71 build units and single-function `.c` files. Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.
- `main.dol` (`GC/1.3.2` & `GC/2.0p1`) + `movie_module` consolidation (`9,703 -> 9,468` total units): consolidated 92 compiler-verified contiguous unpooled runs in `src/dol/` (retiring 180 build units and `.c` files) and 25 runs in `src/rel/movie_module/` (retiring 55 build units and `.c` files) — 235 build units and single-function `.c` files retired total. Passes all 16 GFZE01 hashes and `fzgx lint` with zero findings.

### `sasnd`: typed TUs that own their data (2026-11-23)

`sasnd_mix.c`, `sasnd_track.c` and `sasnd_voice.c` are single units on the shared layouts in `include/sasnd/sasnd.h`, and each owns its `.sdata2`; `sasnd_voice.c` also owns `.rodata 0x800929D8..0x80092B38`. `tools/consolidate/tu_own_data.py` moves a verified range into a collapsed DOL unit. Measured while building them:

- A plain `static` helper creates its literals at its definition even when every call is inlined, and the link strips its code. `static inline` does not. Moving the zone, pitch and ratio helpers of `sasnd_track.c` to plain statics reproduced the retail pool with no primer or pool map.
- `tu_try.py` compiles a candidate with the first unit's compiler. In a run mixing GC/1.3 and GC/1.3.2, check the candidate under each before trusting a diff: one false table-addressing difference in `sasnd_voice.c` came from this.
- A caller can need a different declaration from the definition's. `fn_8005C7C0` and `fn_8005C9D8` match only with a block-scope integer-returning declaration of the later `s16 fn_8005D258`.
- All five mapped sasnd TUs are now one unit each and need no literal remap. `sasnd_core.c` owns its strings, the fade and wave tables, `.sdata2 0x801A7328..0x801A7350`, `.bss 0x801932A8..0x80199670` and `.sbss 0x801A6C78..0x801A6C88`. `tools/consolidate/tu_install.py` installs a candidate when `tu_try.py` cannot express a unit's pool selectors.
- One layout primer remains, in `sasnd_core.c`. Uninitialized objects are emitted in first-access order, which does not produce retail's `.bss` order. `= {0}` gives the retail order but moves the objects to `.data`, with or without `explicit_zero_data off`. Find the retail access that sets this order before removing the primer.
- PAL's sound data differs: the bank level offset is at 0x60 and `SndRegion` is four bytes longer, both recorded in the header. `fn_80060724`, `fn_80060950` and `fn_80060BDC` match PAL under that layout. `fn_80060C54` has further code differences, so the track and voice objects are USA and Japan only for now.

### Render TUs before `heap.c` (2026-11-23)

`0x80007A44..0x80008E34` is two TUs: `src/dol/render/render_clear.c` (5 functions) and `render_util.c` (12 functions plus the USA stub `fn_80008E30`, which stays its own USA-only unit). The names are descriptive placeholders: the retail DOL has no `render*.c` filename anchor, and the AX cross-reference has no source filename for `fn_80007CDC`. Both build under GC/2.5 and own their `.sdata2`; `render_clear.c` also owns `.sbss 0x801A6728`. Its color at `.sdata 0x801A6408` is still in the shared data unit `lbl_801A63C0.c`.

- A TU's `.sdata2` starts on an 8-byte boundary and the object before it does not include the padding. The empty word at `0x801A6F0C` separates the two TUs: one compile packs the next literal there.
- Split ends must stop at the last object. A region symbol without a size takes the distance to the next symbol, so shortening a USA object also needs `size:` on the Japan and PAL symbol.
- `fn_80008E30` is empty in USA, absent in Japan and a real function in PAL that reads this TU's literal `0x801A6F20`. `render_util.c` therefore builds for USA and Japan, and PAL links it from retail assembly.
- `fn_80008C20` keeps one marked `opt_propagation off` device. `fn_80007B68` spells out the steps of `fn_80007AB4`, because calling it swaps two stack copies.

### AHX: seven typed TUs (2026-11-23)

The AHX range `0x8004FF68..0x8005466C` is seven TUs in `src/dol/ahx/`: `ahx_bits.c`, `ahx_decode.c`, `ahx_adxt.c`, `ahx_transform.c`, `ahx_synth.c`, `ahx_synthobj.c` and `ahx_player.c`. The file names are placeholders. All 63 functions build from one unit per TU under GC/1.3.2 with `-sdata 0 -sdata2 0`, in USA, Japan and PAL, and every TU with `.rodata` owns it. `ahx_bits.c` also owns its `.bss`.

- Three of the boundaries come from data alone: `0.0f` repeats at `.rodata 0x80091338`, the version string starts on the 8-byte boundary `0x80091358`, and `.bss` jumps from `0x8018710C` to `0x80187110`.
- `-sdata 0` replaces the old array and pad declarations that kept these globals out of small data.
- The remaining `.bss` of `ahx_decode.c`, `ahx_synthobj.c` and `ahx_player.c` stays in data units: first-access order would not reproduce retail's object order without a primer.
- Marked optimizer devices remain in `fn_800501F4`, `fn_80050698`, `fn_80051448` and `fn_80053A84`.

### DOL `.text` TU map complete (2026-11-23)

`state/tumap/GFZE01_main.json` now assigns all 2,230 DOL functions to 259 TUs. The map is a draft in one respect: where no data bounds a TU, its extent is positional and its `notes` say so, and names without a retail or donor source are placeholders. That covers `sasnd_ctrl.c`, `render_*.c`, `lg_view.c`, `exi2.c` and the AHX and sasnd files.

- `sasnd_ctrl.c` holds the last 19 sasnd functions as one typed unit for USA and Japan. `fn_80064FDC` is still a lifted body with byte offsets.
- `dol_tu_split.py --pooled` splits units that carry literal bindings. The historical blockers were `dol/trk/serpoll.c`, `dol/adx/adx_tlk.c` and `dol/fn_8007FE70.c`. A 2026-11-27 audit of `units.json` against this map finds no DOL code unit spanning multiple known `.text` TU owners; unknown owners are not evidence of a boundary.

### Sample REL TU map (2026-11-27)

`config/GFZE01/sample/tus.json` records a provisional single-TU grouping for the four
functions covering the module's complete `.text` section (`0x0..0x730`) and its five-byte
`.rodata` section. The retail REL has no `*.c` filename anchor; the only readable string is
the `.rodata` object referenced by `_prolog`. The grouping follows the current matched source
unit, but the original filename and internal TU boundary are not independently proven. This
map is ownership evidence only and does not change build splits.

### DOL startup and interrupt-vector ownership

[`GFZE01_main_init.json`](../state/tumap/GFZE01_main_init.json) records the six
TU ranges covering the DOL's `.init` code and vector table (`0x80003100..0x80005544`),
which the `.text` map did not count. The pinned MarioClub_us split and symbol
tables agree with the addresses and sizes of all 15 tracked entries, treating
the vector table as an assembly table rather than C. GFZE01 retail-object
relocations confirm the `TRK_fill_mem` call, the reset-vector branch at table
offset `0x100`, and the reset routine's call to `OSResetSystem`. The map
identifies three `.init` ranges with siblings in the `.text` map. The trailing
`_rom_copy_info` and `_bss_init_info` linker tables are not TU code. This is
ownership evidence only: source names, split extents, compilation and linkage
are unchanged.

The consolidation TU guard reads this map alongside the `.text` map. Its
`text_map_file` entries identify the same owner across sections; other `.init`
owners remain distinct when checking candidate merges.

`dol/trk/mem_TRK.c` owns the two `.init` wrappers and the `.text` fill routine
in one GC/1.3.2 object. Keeping the fill definition after the wrappers retains
the retail call instead of inlining it. USA, Japan and PAL have the same
wrapper bytes apart from the branch displacement to their respective fill
symbols, and identical fill bodies. All three builds now compile the wrappers
from source rather than using retail fallback in Japan and PAL.

`dol/__mem.c` now owns the 0x138-byte runtime `.init` range in all three regions:
`memset`, `__fill_mem`, and `memcpy`. The first wrapper retains its call when
the fill routine is defined later in the file. The regional `__fill_mem`
symbols are at `0x80003488`: the branch in each retail `memset` targets that
address, and the entire range has identical bytes in the three DOLs.

The reset entry at `0x80005518` now builds in `dol/trk/dolphin_trk.c` with its
six `.text` siblings in USA and Japan. The `.init` entry and all six existing
functions match in both builds; PAL's existing retail fallback for this TU
is unchanged. The interrupt-vector assembly remains a separate owner.

`dol/runtime/__ppc_eabi_init.c` reunites the two `.init` assembly routines
and the three constructor/exit routines in `.text` under GC/1.2.5n. The
hardware-enable and cache-flush assembly bodies are translated from the
existing matched GX assembly; the SDK reference corroborates their form and
ownership. All three regions now link the full compiled unit, including
the two startup routines that were retail fallback in Japan and PAL.

`dol/__start.c` restores the six-entry, 0x300-byte startup code unit in all
three regions. The regional DOL headers use the same entry address, and
the differences in the startup instructions resolve to named call targets,
the stack and SDA bases, and `Debug_BBA`.
It retains the weak assembler entry and frameless register setup next to the
four C routines. GC/1.2.5n emits the two BBA small-data relocations at byte
offset +2 within the same instruction rather than +0; their type, target and
linked bytes are unchanged. The original owner now defines `Debug_BBA` as a
normal `u8` in `.sbss`; the USA `Reschedule` data import retains its separate
word and preceding extent. The linker still supplies the copy/BSS tables.

### AV system data and regional source coverage

The three existing AV system compile units now emit the USA `.data` span
`0x8015A860..0x8015ABC0` (864 bytes including alignment). The display setup
passes three arrays of 16-byte vertex format records to `fn_800726C0`; the
cache and its callers now use the same record type. The allocator diagnostics
share the `avsystem.c` filename base. The model loader's three literals are
emitted together by MWCC, with the first string exported for `avload.c`.
The three generated data-import units no longer supply these bytes.

The 31 functions now link from source in all regions, replacing eight retail
fallback functions in Japan and 31 in PAL. The PAL TV-mode switch has a
32-byte longer body: retail calls `OSGetEuRgb60Mode` and selects one of two
60-byte render-mode records. The function name is corroborated by
`libs/dolphin/os/OSRtc.c` in SwareJonge/mkdd at
`2a9eb75fefd75c649c0488742db931571cbd7812`; the call targets, flags and mode
records come from the PAL DOL. `split_resize_for` checks the corresponding
symbol-size change and all shared addresses when placing the split. The new
PAL source branch also renumbers three private float literals; `pool_for`
selects their verified PAL bindings without altering the USA/Japan map.

All code bytes and relocations match after resolving the compiler's local
`.data` base alias to the retail name at the same offset. The compile units
remain separate: putting them in one compiler invocation shifted the latter
two string bases and changed their base-relative instructions. This is a data
ownership and regional source-coverage milestone, not a complete TU collapse.

### USA main.rel consolidation and Japan/PAL source retention

The USA memory-card, second selection-display, font and sprite consolidations
use new whole-object splits. `config/GFZE01/regional_fragments.json` retains the
previously verified Japan/PAL compiler inputs instead of letting DTK silently
replace them with retail fallback. Those entries carry the old split extents in
USA coordinates; configure translates them using each region's symbol map.
Unlike `units.json`, the fragment manifest never selects units for USA. Remove
its entries and source containers when the replacement whole object is proven
to match the corresponding regions.

The strip allowlist records helpers for which no retail text survives. The
font/sprite and selection-panel placeholders preserve data layout only; their
bodies are not credited reconstructions. A bulk probe that replaced the five
font/sprite placeholders with explicit objects failed the retail hash gate.
These helpers remain compiler-diff debt, not portable replacements for the
unavailable original bodies.

### AV loader diagnostics and location strings

`avload.c` now defines six writable strings in its native `.data` range
`0x8015ABC0..0x8015AC68` (168 bytes including alignment). Their bindings and
extents come from the USA retail DOL, and uses are in the loader's allocation,
error-reporting and texture paths. The two 21-entry display lookup tables that
follow remain a separate matching import starting at `0x8015AC68`; their
contents and references are unchanged. Japan and PAL previously used retail
fallback for the six strings. The loader has the same `.text` and `.data`
match against fresh regional extraction in all three releases, and is linked
from the compiler output rather than the extracted object in each release.

### AV display lookup tables and vectors

The USA display-head fragment now defines the two 21-entry lookup tables
(`0x8015AC68..0x8015AD10`); the material fragment defines three look-at vectors
(`0x8015AD10..0x8015AD38`) using the shared `Vec3` type. The last vector retains
its measured trailing word without assigning it a semantic role. The original
split objects and consumers establish the extents and ordering. These are
ownership transfers into matching source fragments, not a claim that all of
`avdisp.c` builds as one TU. Japan and PAL keep their existing build selection.

The adjacent 288-byte diagnostic span (`0x8015AD38..0x8015AE58`) now compiles
with `avdisp_tail.c` in USA. The first string and the typed diagnostics object
retain their separate retail symbols. Combining them into one aggregate had
added an `addi` in `fn_80077B14` and `fn_80077B64`; the separate symbol allows
both material warning paths to use an ordinary `OSReport(const char *, ...)`
call and match retail text. The display tail now performs the original
base-relative arithmetic on a 32-bit DOL address rather than forming pointers
outside the first string. It still depends on the two objects being adjacent.

`avdisp_mat.c` now defines its typed 96-byte state in BSS in USA. The matrix
fragment retains its existing layout primer for matching code generation; a
plain external declaration changed the code in `fn_800756B0`, so that probe was
not adopted. The state transfer does not claim to remove that primer.

## MSL is built with `-inline deferred` (2026-11-24)

In USA and PAL, `exit.c` owns its 64-entry `__atexit_funcs` callback table and
`alloc.c` owns its default pool. The pool initializer in retail clears 52 bytes;
the old 56-byte import also covered the four bytes before the next 8-byte-aligned
object. The split still preserves that alignment gap.

The four MSL exit-state words and the byte-sized allocation initialization
flag now build from `exit.c` and `alloc.c` in USA and PAL. The destructor
chain head builds with its typed linked-list walker in USA. The console
initialization flag is defined with its writer in USA. The zero-valued
operands used by `log` and `log10` are defined as doubles in their respective
units in all three builds. These transfers retain the measured small-BSS
ordering and alignment gaps. The shared `errno` storage remains separate;
its consumers establish its use, not its original translation unit.

### MetroTRK and debugger-driver small BSS

The DDH and GDEV initialization flags, EXI2 callback, and six debugger-driver
state objects now compile with their users in USA, Japan, and PAL. The three
flags and callback slots that formerly had oversized standalone definitions
retain their split extents and following padding. The EXI2 callback must use
16-byte alignment: PAL's slot is at `0x801AA2F0`, and overaligning it shifts
the following small-data addresses by 16 bytes. The existing pair at
`lbl_801A6E18` is built separately in all regions to retain both symbols in
the gap. Ninja links all five objects from source; each `.sbss` split matches
the freshly extracted retail object, and all regional retail hashes pass.

`nubinit.c` now links from source in all three releases and owns the endian
flag in ordinary BSS. The retail PAL banner is v2.6; USA and Japan use v2.0.
The input-pending slot now has its pointer type and builds from source in
all three regions. Keep it in a separate small-BSS unit: compiling `nubinit.c`
with `-sdata 0` preserves its retail HA/LO loads of the two typed globals, but
would place a pointer defined in that same unit in ordinary BSS. The slot
retains 32-byte alignment in USA and 16-byte alignment in Japan and PAL.

The event queue, three message buffers, and serial-poll state now build in
`nubevent.c`, `msgbuf.c`, and `serpoll.c` in all three regions. The support
state also builds with `support.c` in all three regions. Together these definitions replace two
standalone BSS imports. The support definition explicitly selects ordinary
BSS through MWCC's `.data` section declaration: an unqualified definition
landed in small BSS and shifted the linked layout.

In USA, `serpoll.c` also owns its eleven trace strings at `.rodata`
`0x800956C0..0x80095850`. Ordinary literals under GC/1.3.2 with `-str readonly`
produce the retail first-use order: 393 initialized bytes followed by seven
verified zero alignment bytes. This replaces six private string arrays and
five byte-offset format-string accesses, removes eleven pointer-to-integer
casts, and retires the standalone byte-array import and pool binding. All
sixteen USA target hashes pass; Japan/PAL retail inputs were unavailable for
this ownership change. Reproduction evidence is in
[`serpoll-native-rodata-20261127.json`](../state/repairs/serpoll-native-rodata-20261127.json).

PAL's final support routine (`fn_8008AD00`) preserves the reply status on a
length mismatch instead of synthesizing the USA/Japan status. Its retail
function is `0x220` bytes, `0x20` shorter than the other variants. The PAL
split translates its verified final-function extent without excluding any
shared function or the support BSS object.

### MSL stream and decimal state

The standard-stream table (`__files`, 320 bytes) is owned by `ansi_files.c`
in USA and PAL. The retail `.data` contains three initialized 80-byte stream
records and a fourth zero record; each populated row has two buffer addresses,
three console callbacks and a link to the next row. The structure and callback
types follow the stream consumers rather than a flattened import. PAL's
`0x8015D858` table and its targets were checked against the original DOL.
The three 256-byte console buffers also belong to `ansi_files.c`; their BSS
extent is bracketed by independent neighboring objects in both USA and PAL.
The build keeps those neighbors in their previous order and compiles the
stream table and buffers without pool remapping. Japan retains its previous
fallback.

The eight-entry decimal powers table at `0x8015AF98` is now private to
`ansi_fp.c`, its only source consumer. It precedes that object's switch tables
in `.data`, rather than sharing an imported object with the stream records.
The compiled `.text` and `.data` match in USA and PAL; Japan retains its
existing fallback for `ansi_fp.c`.

MWCC's `-inline auto,deferred` emits a file's functions in reverse source order and can inline a
function defined later in the file. MSL's retail TUs are laid out last-defined-first (string.c starts
with strstr and strtok, FILE_POS.c with fseek, _fseek, ftell), and FILE_POS.c's `_fseek` inlines
`_ftell`, which only deferred inlining allows. Written in MSL's source order and compiled with
`-inline auto,deferred`, string, scanf, printf, file_io, ansi_files, direct_io, buffer_io, mem,
strtoul, strtold, GCN_Mem_Alloc and FILE_POS reproduce retail; `tools/consolidate/tu_reverse.py`
reverses an address-ordered file and `tu_order.py` checks the emitted order. Reordering renumbers
`@N` literals, so pooled units need their maps re-derived (`tu_try.py ... --apply`).

### MetroTRK message handlers

`msghndlr.c` now builds all eight mapped functions as one GC/1.3.2 object in USA and Japan.
The SerialIO handler's three literals occupy the first `0x34` bytes of the message-handler
string pool, immediately before `DoContinue` at `lbl_800958C4`. Disabling small data and
compiling the strings read-only preserves the handler's existing HA/LO pair and leaves the
seven other functions and their `.data` jump tables unchanged. The single remaining pool
binding is to `lbl_80095890`; read-only data ownership did not move. PAL coverage is unchanged.

### Profile REL ownership evidence

The GFZE01 `profile.c` map covers the 41 functions in the REL's contiguous `0x0..0x6D48`
text range. `tools/seeds/debug_strings.py --module profile` finds the `profile.c` string at
section 5 offset `0x82BF8` through `_epilog`'s direct references. That seed omits `_prolog`:
its retail instructions at `0x88` and `0x450`, `0x474`, and `0x4F0` instead reach the same
string as `.data + 0x80000 + 0x2BF8` for three allocations. It also wires profile callbacks
from the next code group and uses the same BSS base as `_epilog`. These observations place
the entry point in the same map; the remaining helper extents are inferred from the single
filename anchor and module limits. No compile units or data ownership changed.

### movie_module: Sofdec TU map and recut (2026-11-27)

`tools/consolidate/tumap_movie.py` maps movie_module onto MK Deception's GQNE5D `libmwsfdg.a`
link order (CC0 dtk config): 78 TUs, 789 of 791 functions (`_prolog`/`_epilog` are the entry
prefix). A global alignment by function size, with 104 forced anchors (equal names and the
Sofdec import bindings), gives 484 equal-size pairs and 77 contiguous objects in donor order;
the 23 runs it leaves between two objects are decided in the script's `GAPS` table from
.rodata/.bss relocations, CRI error strings (they name their function) and the static call
graph. GX's Sofdec is SFD/GC 1.852 (May 2003), older than the donor: objects carry extra
functions and lack others, and `mpvabdec.o` links between `mpv_umc` and `mpv_mcy`.

`tools/consolidate/rel_tu_batch.py movie_module --recut --apply` cut the 37 units that crossed
those boundaries into per-TU pieces (each checked against its old unit), and the TU guard now
reads every REL `tus.json`, so the consolidators merge only within TUs. Result: crossing units
45 -> 8, one-unit TUs 16 -> 25, code units 303 -> 312. Most TUs still fail as one file: the
lifted blocks declare shared callees and globals with conflicting types (`strncmp(u32, u32,
u32)` against `strncmp(void *, char *, s32)`, pointer arguments passed as `u32`, two struct
views of one global). That is declaration reconciliation (`fzgx tutruth` after `fzgx tu-migrate
--module movie_module`, or donor C), not another merge pass. The remaining crossing units: five
whose pool maps bind section selectors (`...rodata.0`, `...bss.0`, which `tu_try.py` cannot
rebind), and `fn_12_1EF80`, `fn_12_30930`, `fn_12_670C` (data splits or assembly).

Follow-up (same day): `decl_prune.py` removed 1,992 leftover declarations from the recut pieces
(object-identical), `rel_tu_migrate.py` moved 35 multi-unit Sofdec TUs into block-format TU
files, and `fzgx tutruth` + `relmerge.py` collapsed nine of them to one unit each (sud_lib,
sfd_mem, sfd_pl2, sfd_set, sfd_uo, sfd_vom, uty_tmr, mwstm, mwsfdsvm); movie_module
code units 312 -> 292. tutruth assumed one block per unit; two fixes make multi-block units
work (restore a unit whole, carry private-type renames into the unit's later blocks). What still
fails is the same assumption elsewhere: a later block of a multi-function unit inherits the
earlier block's declarations, so tutruth sees no old declaration to adapt its calls from
(`fn_12_24A88(arg0, 0xff000a01)` against a pointer prototype) and the unit's joined text no
longer compiles. Next: split those units into one function per unit before tutruth (each block
then carries its own declarations, the model tutruth verifies), or teach tutruth to read a
block's inherited declarations from its unit.

### REL TU pipeline on the older game TUs (2026-11-27)

`rel_unit_split.py` -> `fzgx tutruth` -> `relmerge.py` collapsed 15 Sofdec TUs, but over 25 of the
39 multi-unit TU files in `main_rel`, `customize`, `title` and `option` it merged none (every
attempt was rolled back; the 14 largest files were not tried). The failures point at three
limits, none of them a matter of more attempts:

- `tutruth` verifies each rewritten block in USA only. These TU files also feed Japan and PAL,
  and a USA-identical rewrite changed PAL `main_rel.rel` in three of them. Its oracle needs the
  regional builds before its rewrites can be trusted here.
- TU files that define data under their prologue (`option/_prolog.c`) end up defining the same
  objects in several units (`multiply-defined: lbl_4_data_*`). Definitions must stay with one
  unit until the TU is one unit.
- Where blocks disagree beyond what call-site casts and renames fix, `tutruth` restores them
  self-contained: the result has no fewer `noprologue` blocks, and the driver discards it.

`relmerge.py` now retains Japan/PAL units as regional fragments when a merge is USA-only, so
once `tutruth` passes in all regions these files can merge without losing regional source.

### Regional reconciliation and native REL data ownership

`tutruth` checks each complete generated unit against its production object in every region
the unit already builds for. Run `tools/consolidate/gate.sh` first to populate the regional
profiles and production objects. Reconciliation compares the emitted sections, symbol layout,
alignment and relocations after applying the existing pool bindings. Numbered private names
can change only when the same relocation sites and full object comparison prove the new map.
Failed groups restore their old source, including exactly one copy of their original prologue.
Simple named prologue storage stays with the unit whose split already owns it; other units
see declarations only. These checks supplement, not replace, the three-region linked hashes.

The first measured collapse after this change is Sofdec `mpv_err.c`: four functions in
`.text` `0xA660..0xA7B0`, one GC/1.3.2 object, no pool map and no isolated blocks. The
shared declarations retain the TU's private inline helper instead of making it an extern.
All three regions retain source coverage for the four functions.

For `mwsfdfrm.c`, the split-first candidate did not recombine: the loader's standalone error
call declares a different variadic ABI. Reconcile the original grouped units instead when
their combined objects verify: four units stay four while isolated blocks fall from ten to
two. The unit containing that call keeps its original source and compiler profile.

The same grouped retry retired all thirteen isolated blocks in `sfd_con.c`. The next pass
resolved the whole-file declaration conflict: both callers now declare `fn_12_6B28` with
the opaque `MovieEntry` return pointee used by its reconstructed definition. GC/1.3.2 with
`-use_lmw_stmw on` compiles the thirteen functions at `.text` `0x22FBC..0x23F00` as one unit
instead of six. All thirteen functions match the freshly split retail objects in USA, PAL,
and Japan, and all three linked hash gates pass. No pool map or regional fragments are needed.

The smallest-first sweep also reconciled `sfx_cnv.c`: 16 to 2 isolated blocks with fourteen
compile units both before and after. The candidate did not collapse to a single object;
only the declaration sharing is retained, with all three hash and lint gates passing.

Two more declaration-only changes preserve the existing splits. `dct_ac.c` uses the existing
typed transform and inverse-table declarations and retires two isolated blocks. Its proposed
three-to-one merge failed the PAL build because the pool retargeter could not empty a private
section; the original splits remain. A follow-up compiled the same merged source under the
three production region profiles. All three derived the same two literal bindings and the
same `.bss` section-base binding. After applying them, `.rodata` and `.fzgxpool` were empty,
but `.bss` still contained `0x404` bytes: the wrapper now refers directly to the in-object
definition of `lbl_12_bss_798`, whereas the initializer uses the section base. The actual
blocker is the local storage that cannot be discarded, not PAL-only literal numbering.
Replacing the transform's zero literal with an extern changes its relocation layout and
does not solve this. The successful follow-up moved the `0x798..0xBA0` BSS split into the
single `dct_ac.c` unit, removed the now-obsolete BSS retargeting and retired the standalone
import. The existing table definitions occupy `0x404` bytes, with the next split starting
at the original aligned boundary. The initializer's `...bss.0` relocations resolve to the
same address as `lbl_12_bss_798`; the raw objdiff score does not recognize that equivalence.
All three regions build the merged unit from source and match the linked retail hashes.
`bg_for.c` drops from thirteen to five isolated blocks
at the original twelve units. Its split-first candidate had fourteen units, and combining
the original groups still hits the duplicate `Fn183D28Vec3` typedef. The accepted rewrite
rebinds two renumbered MWCC literals without changing their retail targets.

Reconciliation against the original twelve `mwsfdsfx.c` units retires 23 isolated blocks
(32 to 9). The split-first variant leaves more units and was rejected. The whole-file compile
still exposes incompatible `MWSFSVM_Error` declarations between groups; no split or compiler
profile changes are part of the retained result. All three region builds and hashes pass.

`main_rel/driver.c` shares four more isolated blocks (12 to 8) across its existing eight
units. A whole-file build still rejects the conflicting private declarations of
`lbl_1_bss_6F648`; the original splits and compiler settings remain in place.

For large TUs, `fzgx tutruth TU --repair-budget N` limits optional declaration-repair trials.
Zero skips the search after the initial reconciliation; it does not skip the initial or
final regional object checks. The JSON reports `repair_trials` and `repair_budget_reached`.
Use this mode for a first sweep and revisit useful failures with a higher budget. The split
`interview.c` replay finished in 60 seconds at budget zero, with all 60 intermediate units
verified under their matching regional profiles, but all 79 blocks remained isolated. That
result is not a merge or a reason to retain the intermediate splits.

At its original fourteen units, `movie_module/sfd_tim.c` drops from 37 to 15 isolated
blocks using three repair trials. All three regional hash and lint gates pass at the
existing splits. Whole-file probes still reject the duplicate `MovieModule_u2` tag.

The smallest-first sweep now has a terminal result for all 63 multi-unit REL files from
the `df39b67f1` inventory. The unbounded driver recorded results through index 55; a
separate, zero-repair-budget replay covered indices 56–62. The split-first path retained
three candidates: `mpv_err.c` collapsed to one unit, while `sfx_cnv.c` and `driver.c`
reduced isolation at their original unit counts. The other sixty split-first candidates
were discarded. This does not count the separate grouped and manual passes, including the
verified `sfd_con.c` collapse. Interview and the last six files did not qualify for
retention. A completed sweep is not equivalent to completing R1: 61 of 145 mapped REL
source files still build as multiple units. Use the rejected object or compiler diagnostics
to select the next repair rather than repeating the same split-first pass unchanged.

`movie_module/sfd_see.c` now builds as one unit instead of two. The analysis and
estimation helpers had duplicate private names despite taking different reconstructed
views of the handle. Naming the estimation helpers separately removes that collision
without changing their bodies or compiler settings. The merged USA text range is
`0x2D008..0x2D500`; all five functions match their freshly extracted retail objects
in USA, Japan and PAL. No new pool bindings were needed.

`movie_module/cftfx.c` now builds as one unit instead of two. The conversion
routines shared eight identical BSS definitions, each duplicated with its own
ordering primer in the old split. The merged file keeps one copy and uses the
second group's existing GC/1.3.2 `-use_lmw_stmw on` profile. All 12 functions
match fresh retail objects in USA, Japan and PAL. The BSS and constant pool
still link through existing retail data splits; the merge is not a transfer
of data ownership.

The subsequent `cftfx.c` ownership transfer assigns `.bss` `0x1E088..0x1E3DC`
to its existing code unit. In the old split, the `0x354`-byte opaque import
provided storage for the section-base remap; the conversion routines were its
only recorded consumers. The source already defines the two matrices, three
pointers and three conversion tables. Fresh MWCC objects in all three regions
emit them at offsets `0x0`, `0x24`, `0x48`, `0x4C`, `0x50`, `0x54`, `0x154`
and `0x254` respectively, filling the whole range. Retire the opaque import and
BSS retarget only; the constant pool and existing ordering primer remain.

Two more Sofdec code units now own their BSS. `mwsfdsvm.c` owns the error buffer
and server state at `0x1B8A0..0x1B9B0`, formerly three standalone imports.
`DCT_FsriInitSparseTbl.c` owns the `float[64][64]` table at `0xDB0..0x4DB0`;
the neighboring `0xBA8..0xDB0` import was left alone. Both use ordinary BSS
definitions with the existing alignment requirements, without the importer's
section overrides. The compiled objects filled the transferred ranges, and
every function in the two units matched retail in USA, Japan and PAL.

In `movie_module/mpv_hdec.c`, `MPV_MoveChunk` now uses the shared Sofdec
stream declarations in `sofdec/sj.h`. Removing its obsolete isolation marker
leaves the existing group intact: both `MPV_MoveChunk` and `fn_12_ABDC` match
retail in all three regional objects.

The two `customize/emblem.c` groups share `EmbColor` without duplicating the
editor's help table or BSS. The storage stays in the first group's block;
eight canvas blocks use the shared prologue. Both USA objects are byte-identical
to their pre-change builds, and Japan/PAL coverage is unchanged. A single
object still changes four instruction words in `fn_3_14778` and was not kept.

Four `movie_module/sfd_buf.c` blocks (`fn_12_21D40`, `fn_12_224FC`,
`fn_12_22FB4`, and `fn_12_22FB8`) now include the shared prologue. The three
affected compile units are byte-identical to their baseline objects in every
region. The whole-file probe still stops at conflicting `fn_12_2F210`
declarations; the compile-unit count is unchanged.

`tools/consolidate/rel_own_data.py` transfers whole adjacent import units into a specified
one-unit REL TU. It checks contiguity and matching regional coverage, carries over the existing
typed definitions in retail order, and verifies the moved symbols against fresh compiled and
retail split objects in addition to the three-region link gate. For a private string already
emitted by the TU, `--native-literal` retires the duplicate import and pool binding without
changing the source spelling that produces the retail code.

- `sample/_prolog.c` takes `.rodata` `0x0..0x5` in USA and PAL. `_prolog` is the import's
  only consumer, and the existing GC/1.3.2 literal (`@33`) emits the five bytes at offset zero
  without the pool fixup. The attempted named-array spelling shortened PAL `_prolog` by one
  instruction and was rejected. NTSC-J continues to use its prior fallback.
- `main_rel/burner.c` extends USA `.data` from `0x27DE0..0x27E08` to `0x27DE0..0x27E20`.
  Its filename anchor `lbl_1_data_27E08` (9 bytes) and `lbl_1_data_27E14` (12 bytes of existing
  zero-initialized storage) follow the 40-byte object already in the TU. GC/1.3.2 emits the
  moved objects at section offsets `0x28` and `0x34`. This preserves the imported C types and
  layout, without claiming to recover the zero object's purpose; regional fallback is unchanged.
