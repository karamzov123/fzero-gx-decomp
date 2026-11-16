# GFZE01 source-debt census

Run `python tools/fzgx.py devicecensus` for the live summary, or add `--json` for every source location, owner and input fingerprint. The command is read-only: it does not compile, change claims, or update the ledger.

## Measured checkpoint

The latest source fingerprint and complete compressed inventory are retained in `state/repairs/device-census-bitmap-resource-20261116.json.gz`; `state/repairs/bitmap-resource-layout-20261116.json`, `state/repairs/typed-index-recovery-20261116.json`, `state/repairs/bgwin-string-layout-20261116.json` and `state/repairs/automated-device-cleanup-20261116.json` record accepted source hashes, compiler context, replay archives and validation. Earlier inventories and their evidence manifests remain intact. Each inventory records its base commit and explicitly notes modified source/configuration; the source-tree digest identifies the measured contents independently of that base.

| Category | Spots | Files | Owner functions |
| --- | ---: | ---: | ---: |
| Explicit device-warning comments | 38 | 13 | 14 |
| ADX dead-write macro uses | 7 | 1 | 1 |
| Synthetic `.fzgxpool` primer function definitions | 10,630 | 145 | 958 |
| Tagged `__reg_value_` register-staging assignments | 44 | 8 | 10 |
| Optimization-setting directives (excluding reset/push/pop) | 937 | 273 | 695 |
| Anonymous one-field `value` scalar-carrier shapes | 267 | 96 | 176 |
| Other `fzgx_` function definitions requiring review | 4 | 4 | 4 |
| `volatile` tokens | 15,470 | 389 | 1,235 |

The explicit-warning and ADX-use owner-function union is **14**, not 15. One shared-header warning has no single function owner. Warnings are spots, not distinct devices: several comments can describe the same device and one comment can describe several. The directive, carrier-shape and volatile rows are **review queues, not confirmed device totals**. Hardware volatility, SDK implementation requirements and legitimate aggregate types must not be counted as defects without review.

Including the confirmed synthetic layout-primer and tagged-staging owners gives a distinct known-scaffolding owner-function union of **972**. Schema 3 adds tagged-staging coverage: this expansion from the earlier marker/primer-only union of 967 is not a source regression. There are 72 primer definitions in shared/unassigned scope, beyond the 958 mapped primer owners. Primer counts are physical definitions, including repeated source copies; they are not 10,630 distinct original data objects or instructions executed by retail. Four synthetic-name helpers outside `.fzgxpool` stay review-only. An independent balanced-parenthesis scan and separate section/attribute classifier agree with every one of the 10,634 synthetic definitions, including function-pointer parameters.

The current configured retail-function denominator is 7,351: 7,159 C-form, 186 standalone-assembly, five reviewed original-assembly, and one mixed function. These categories describe source form, not natural-C completion. Original assembly is legitimate when evidenced; the 192 outside-pure-C forms are not automatically C-conversion debt. Raw ledger totals can also retain retired entries, so they are not the source-form denominator.

## Scope and limitations

The scanner visits physical `src` and `include` C/C++/assembly files once, excluding generated build copies. It recognizes warning markers only inside comments and review tokens only outside comments/strings. Function ownership comes from matching configured units and physical TU block boundaries; shared helpers, primers and headers can affect additional consumers that this inventory does not infer. Public symbols are module-qualified. Every finding carries its path and source line; the JSON includes source/configuration fingerprints and unresolved owners.

This is a reproducible marked-debt lower bound and a review queue, **not a certified count of all remaining compiler devices, type/data recovery work, or device-free functions**. An unmarked function is not certified natural.

## Cleanup evidence

The first census-guided pass froze the 32 smallest single-function carrier owners. All 32 installed controls matched; none of the 66 removal-only or combined carrier/pragma probes matched. They are retained in `state/repairs/small-carrier-removals-20261116.sources.json.gz`, not installed.

A subsequent computation-based probe removed the carrier in `movie_module:fn_12_38680`: a real inline resource-offset computation performs the lookup and mode adjustment, rather than using an aggregate to steer allocation. It preserves the null guard, base-call ordering and unsigned arithmetic, emits no extra helper, and matches the retail object and relocations. The rounded-quotient alternatives for `main:fn_80059C0C` still differ by four aligned words and remain unaccepted.

All 103 probe bodies were reconstructed and recompiled using the shared repair archive replay. Their source-SHA sets, match verdicts and aligned-word error counts agree with the original measurements. The accepted source also passes lint and all 16 linked retail hashes. Removing one carrier reduces that review row from 274 to 273; it does not reduce the warning count and is not credited as project-wide natural-source completion.

The next recovery shares four constructor-evidenced layouts (`MotaSignal`, `MotaEntry`, `MotaTrack`, `MotaList`) between `fn_1_41518` and `fn_1_41C18`. The name binder now uses an ordinary typed indexed loop with no offset carrier or manually maintained byte stride. Both functions still match retail objects and relocations. Real MWCC-emitted layout data verifies four sizes and seven relevant offsets; the list remains only the observed 0x50-byte prefix of its 0x60-byte allocation, without inventing the tail. All eight source probes replay with identical hashes, verdicts and aligned errors, and all 16 linked hashes plus lint pass. This removes one more carrier, leaving 272 in the review queue; unrelated constructor devices are not credited as removed.

## Automated inverse-device checkpoint

The next batch removes 54 tagged register-copy blocks, three scalar carriers and eight duplicate optimizer setters across 22 functions. It preserves the staging type's conversion at each assignment and uses a real unsigned counted byte index for `main_rel:fn_1_15BA78`. These are partial cleanups, **not 22 newly certified natural functions**. The three text-entry clones in option/sel/title share a successful transformation but are each independently compiled and relocation-checked. Four literal-pool maps are refreshed from real object evidence; no compiler flags or acceptance gates are relaxed.

Six `automated-cleanup-*.sources.json.gz` archives retain 783 compiled probe bodies, including unsuccessful alternatives and controls. Shared repair-engine replay reproduces the complete source-SHA/compiler/flags/verdict/aligned-error multisets. The installed 22 source hashes are checked separately; the whole build and independent retail checks both report `16 files OK`, and lint reports zero findings.

A compiler-context bug explained a false barrier: ordinary sel units inherited the first unit's `-inline on,noauto` override. Module defaults now come from an override-free unit and cache invalidation includes `units.json`. Comparing 11,604 configured profiles finds no remaining effective flag differences after excluding output/control, default-C selector and include-path switches. The retained `sel:fn_10_23990` regression has 172 aligned errors with the leaked override and zero with its actual configured profile. Archive records pin effective compiler arguments and reject profile drift. Two historical positive-cohort probes explicitly retain the legacy override in their replay recipes rather than silently changing their measurements.

Use the existing engine's read-only mode for bounded cohorts:

```sh
python tools/fzgx.py fixup --cleanup --module sel --limit 32 --rounds 4 --max-candidates 64 --budget 120 --output .fzgx/manual-device-review/cleanup-sel-next
```

It requires exact installed-source controls, proposes known inverse devices only, stops when a round has no improvements, and preserves every frozen probe in its report/archive. It does not apply sources, change claims, run flag/allocator searches or claim linked verification. `--cleanup --apply` and incompatible repair selectors are rejected. Without `--output`, each run gets a separate timestamped cleanup directory rather than overwriting an ordinary repair corpus or previous checkpoint.

The live 32-function trial admitted 30 controls and blocked two: their code words match but extra-helper/source-policy checks reject them. It produced no further accepted proposals; a historical-body smoke cohort produced one. The sel trial admitted five controls and produced no further proposals. Zero yield is a stopping signal, not permission to widen arbitrary search. Primer removal remains a measured negative frontier in the retained actual-profile archive and rejected-generator snapshot. Further gains need shared types, actual computations or native-TU/data recovery, not repeated removal-only sweeps.

## Shared string-resource layout

`fn_1_15B970` (endian conversion) and `fn_1_15BA78` (name lookup) now share three layouts in `include/rel/main_rel/bg_win.h`: a header with count, entry-table offset and result-table offset, an 8-byte name entry (length, name offset) and an 8-byte result row whose second word is the value offset. The conversion swaps header words 0x08..0x18 and both words of every row; the lookup reads exactly the named fields. The first eight header bytes and result word zero remain uninterpreted. Both loops index the typed rows directly instead of maintaining byte strides. Real MWCC-emitted layout data verifies the three layout sizes, nine field offsets and the 0x10-byte global slot that holds the table pointer.

The lookup still loads the global through an explicitly marked staging copy: the direct typed global assignment differs by 13 aligned words in both tested forms. Marking it raises the warning row from 37 to 38 spots; the tagged-staging row (44) and the known-scaffolding union (972) are unchanged, so this is layout recovery, **not** device removal or new natural-function credit. Twelve compiled bodies, including both failing direct-load probes and a whitespace-only installed-form control, replay from `bgwin-string-layout-20261116.sources.json.gz` with identical source hashes, compiler profiles, verdicts and aligned errors. The whole build and the independent retail check report `16 files OK`; lint reports zero findings.

A follow-up frontier on that 13-word staging barrier is retained in `state/repairs/bgwin-staging-frontier-20261116.json.gz` (22 compiled bodies with their header variants). Without staging, the lookup is instruction-identical to retail except that `table` and `index` swap r28/r29. A typed pointer member, a scalar pointer global, all six local declaration orders with while/for loops, and a staging copy that reads the typed member all leave the same 13 words. Only the address-taken staging copy matches. The scalar global fits the evidence (two 4-byte offset-0 references; the next object is 32-byte aligned), but it would conflict with the saved 16-byte declared-bss import and gains nothing in codegen, so it is not installed. Do not repeat these variants; a removal needs a different source structure.

## Typed indexing and the ranking archive layout

Retail often keeps a byte offset and an index as separate induction registers. That is MWCC's strength reduction of `&array[i]`, not evidence for a hand-maintained offset. A scan of the carrier queue found seven offset carriers stepped by an element size across five functions. Three outcomes, each from one fixed cohort:

- `main:fn_80077D40` now loops `for (i = 0; i < count; i++) item = &items[i];` with no carrier. All four typed-index spellings match. The LOD tests are also spelled naturally: `addis/cmplwi 0xffff` is MWCC's unsigned compare with `0xFFFFFFFF`, and the promoted `u16` compare with `-1` needs no cast.
- Six ranking.c functions (`fn_1_159440`, `fn_1_159478`, `fn_1_1594AC`, `fn_1_159588`, `fn_1_1596DC`, `fn_1_159804`) now share `RankingArchive` in `include/rel/main_rel/ranking_archive.h` (`lbl_1_data_4C810[4]`, 0x3C each). It replaces five private views and the generated 0xF0 aggregate. Data relocations give its archive path (`"/bmp/bmp_cardt.arc"`, ...) and `-1`-terminated id table; the ring fields come from the enqueue/evict/move-to-tail code. Removing the `fn_1_1596DC` carrier first differed by 8 words, all MWCC's bottom-test loop inversion. Keeping the original top-test `break` with `for (i = 0;; i++)` matches. `fn_1_159478` needs the same entry pointer as `fn_1_159440`: direct `array[index]` addressing differs by 4 words. Callers now use `fn_1_159804`'s true `s16 (s16, RankingArchive *)` prototype. Every one of the 79 ranking.c units whose text changed compiles against retail. `fn_1_1577D0` keeps its pre-existing extra-helper policy flag with an exact object match, identical to its committed control. The raw-word data definition is unchanged.
- `main_rel:fn_1_10A8D0` stays as it is: node, in-half and cross-half edge indexing alone and combined differ by 8-61 words. Do not repeat those variants.

The carrier queue falls from 269 to 267. Neither function is credited as fully natural, because unmarked code is not certified device-free.

## Bitmap resource table layout

`lbl_1_data_FCD4` is 188 records of 0x28 bytes. Retail data relocates words 1-7 of each record to archive-path strings, which `lbl_801A66B4` selects by language. The loader `fn_1_47AD4` records the heap index (an entry of the three-heap table `lbl_1_data_6CA0`), sets `loaded` and stores an image set: a count, 0x10-byte texture headers (flags, data offset, width, height) and 0x20-byte objects built with `GXInitTexObj`. `include/rel/main_rel/bitmap_resource.h` now holds `BitmapResource`, `BitmapImages` and `BitmapImageInfo`. They replace twelve private type definitions and the generated aggregate that was duplicated in bitmap.h, font.h and ranking.h.

Twenty consumers across bitmap.c, font.c and ranking.c now index typed records instead of byte strides. All 28 changed units compile against retail. `fn_1_527B4` misses by 5 words with `&table[index]` or an index temporary, but matches as `entry = lbl_1_data_FCD4; entry += index;`, the same pointer-advance shape `fn_1_4F734` already uses. The loader keeps its own argument view: its body is a dense lifted reconstruction outside this batch. This is shared-type recovery, not device removal. Census rows are unchanged, and no function is credited as fully natural.
