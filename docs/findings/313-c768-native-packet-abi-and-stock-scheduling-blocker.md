# fn_4_C768: native packet, angle ABI, and stock scheduling blocker

Continued the same 2,624-byte option-menu function after explicit owner authorization to ignore the plateau guard. No shared/fleet guard settings were changed and no agents were delegated. All work used one owned claim, private sources, the existing oracle, and the existing repair/capture engine. No canonical gameplay source was submitted.

## Safe result

GC/1.3.2, no extra flags: **98.06707% raw / 97.88% adjusted, 14 differing rows out of 659**. This improves the previous saved safe result of 96.5% raw / 94.25% adjusted with 38 differing rows. It remains nonmatching, with zero new authored-byte credit.

The admissible source is `.fzgx/analysis/hermes-large-oct12/deep-sin-s16-mask.c`, SHA-256 `9b7fc3525a1c0123f08e2321432b96785d90839a32a73dba99078ccd191b1774`. The released attempt saves that source at `.fzgx/attempts/fn_4_C768.1791857517.c`; the ledger records 97.88% and has no remaining claim.

Portable source, complete oracle rows, compiler settings, stock allocator capture/validation, residual-region sequences, and rejected-candidate evidence are in `state/repairs/c768-native-packet-stock-scheduling-20261012.json.gz`.

Changes from the prior candidate:

- Use the actual 88-byte FontDrawPacket layout, with typed coordinates, scales, flags, and rotation.
- The four packet tint writes are at offset 0x3C: **color_add**, not color at 0x38. An initial typed-field conversion exposed this distinction; it was corrected against the retail stores.
- Preserve full 32-bit packed RGBA transfers and byte-channel updates through a genuine packed/channel color view.
- Express the pointer-object read through its typed address where retail reloads it. This reproduces the cursor packet's actual reload sequence rather than retaining a cached pointer across the packet copy.
- Retain the final font scale in double precision until argument narrowing.
- Declare the sine entry argument as a signed 16-bit angle, consistent with retail's sign extension. Keep the low-byte phase mask explicit. Moving sign extension to the call boundary reproduces the retail marker setup without fake liveness.

## Remaining differences are two scheduling regions

There are no remaining register-allocation differences in the fresh oracle classification: six instruction, four operand, four immediate rows. Alignment insertion/deletion makes these look like shape changes. Programmatic inspection of both affected straight-line regions shows that each has **32 target instructions and 32 candidate instructions with exactly equal formatted instruction multisets**. Their order differs, chiefly the pointer/palette loads and the 0x4330 int-to-double setup.

The preserved aligned regions are `[0x534,0x5B4)` and `[0x674,0x6F4)`. These are aligned-diff offsets, not literal target function addresses. The archive contains the actual ordered sequences. Equal multisets are diagnostic evidence of this ordering residual, not a general runtime-equivalence proof or permission to submit a nonmatching object.

Direct source probes covered typed/byte/aggregate RGBA transfers, packed-word signedness, double versus rounded scale locals, numerator lifetimes, channel/scale ordering, packet store ordering, and angle ABI/cast forms. The safe scalar and aggregate color spellings retain the same fourteen-row residual. GC/1.3.2r and GC/1.3 were worse; GC/2.0 reproduced the earlier GC/1.3.2 eighteen-row candidate. Processor 750 and 7400 reproduced the final fourteen-row schedule; 603e/604e and scheduling-off regressed.

## Capture and search evidence

The first existing-engine run evaluated 6,376 variant records. A second run used live stock allocator captures and evaluated 19,133 records, for **25,509 compiled variant records total**, with zero exact results. These totals include the runs' baselines and are not counts of improved functions.

The final safe stock capture has identical instrumented and ordinary code/object, two allocation passes, 404 active nodes, zero replay or simplify errors, and no unsupported simplify decisions. Target constraints report `needs-web-alignment`, subkind `instruction-shape`, with **zero source projections**. The current captured allocator projection cannot supply a source witness for the remaining schedule. This, together with the unchanged safe frontier, is the concrete blocker for this attempt; stopping did not rely on the plateau guard.

The public `fixup --body` command initially selected zero rows because the ledger symbol was actively claimed and its loader filters to unmatched rows. The private owned attempt was then passed explicitly to the existing Engine.record/run interface. That run selected and actually compiled the function; the empty initial command is not counted as work.

## Reject the attractive four-row frontier

The capture-backed engine's preferred result is **not admissible**. `word:u32->u16` changes the packet's packed color member to u16, replacing four retail `stw` transfers with `sth`. Another variant narrows to u8. These sources reach 99.04726% raw / 99.39% adjusted with four differing rows precisely because the remaining mismatches are the incorrect store widths. They truncate/corrupt the RGBA packet and cannot be treated as safer or closer source.

Restoring u32 while retaining the engine's extra depth temporary returns to the safe fourteen-row residual. Inspection of the improved engine records found no under-fourteen-row candidate retaining the full-width native packed member. No narrowed candidate was written to the ledger best-body cache or submitted. The bad body and its recipe/receipt are archived only as explicitly rejected diagnostic evidence.

## Gates

After saving and releasing the claim: locked full build succeeded (`ninja: no work to do`); independent DTK verification reported **16 files OK**; repository lint reported **zero findings**. Every pre-existing modified/untracked protected file had its original hash, and no claims remained. These gates verify the existing repository reconstruction, not an exact match or runtime integration of this candidate.
