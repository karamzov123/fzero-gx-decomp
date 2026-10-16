# 349 — fn_1_108EEC: correct the affine-matrix extent and bit-zero predicate before allocator tuning

Manual continuation, 2026-10-16, `hermes-sol-manual` / `gpt-6.1-sol`.
**fn_1_108EEC is MATCHED and link-verified in commit `ee5254ef`.**
No fleet restart, subagents, compiler patches, or model-route changes.

## Exact closure

The saved best source scored 99.46377% raw, but its displayed residual was
14 frame-offset rows plus one flag-test opcode. It declared the stack matrix
as `f32 pad_0[0x10]` (64 bytes) and filtered nodes with `unk_0 & 0x80`.
Retail's frame is 0xB0, not 0xC0, and tests the low bit with
`clrlwi. r0, r0, 31`.

Two semantic/layout corrections suffice:

```diff
 typedef struct {
-    f32 pad_0[0x10];
+    f32 pad_0[12];
 } Mtx;

-        if (!(n->unk_0 & 0x80)) {
+        if (!(n->unk_0 & 1)) {
```

The 48-byte matrix storage is consistent with the affine-matrix usage;
the decisive proof is the stock GC/1.3.2 compilation, not that interpretation.
All other source, pragmas and compiler flags were retained.

- Standalone compile: **138/138 relocation-masked machine words equal**.
- First `write-unit` check: **100.0% MATCH**, lint clean, no prologue conflict.
- `submit`: accepted, pending link.
- `verify`: fast path, verified only `fn_1_108EEC`, no rejected functions,
  local commit `ee5254ef`.
- Independent `sha1sum -c config/GFZE01/build.sha1`: **all 16 targets OK**.
- Whole-project `fzgx lint`: **0 findings**.

This was not a register-allocation fixed point. Prior history had tried matrix
sizes of 4 and 16 floats, but the retained declaration still had the wrong
extent. Read the actual frame delta and semantic flag bit before repeating
compiler settings or declaration permutations.

## Related saved-body correction: fn_1_118D90 remains unmatched

The saved 99.54464% candidate contained two semantic errors visible in retail:
its flag predicate used `& 0x7FFFFFFF` instead of `& 1`, and the link-record
index advanced by 136 instead of 3. Correcting both gives **99.72024% raw**,
with **322/336 equal positional words** (14 differences).

The remaining differences are the pool address's r3/r4 choice (words 6, 7),
the last loop's r29/r30 shadow assignment, and its induction-update schedule.
The exact differing indices are preserved with the source in
`state/repairs/manual-semantic-frontier-20261016.json`.

Bounded structural probes did not close it:

- Separate explicit loop pointers: 22 word differences.
- Remove dead pointer steps, reorder the index update, use the shared output
  index, or spell the last loop as a natural `for`: unchanged at 14 differences.
- Pointer parameter or byte-addressed doubled index: unchanged.
- Pool initialization inside the null guard: 15 differences.
- Evaluate the doubled pointer before the single pointer: 19 differences.
- Explicit output byte offset: 27 differences.

The corrected source is saved in the ledger and portable repair archive.
It is not submitted, carved, blocked, or counted as a completed function.
Do not repeat these unchanged structural families without new evidence.

## Other bounded triage (no matches)

- `fn_1_F4F08`: fresh saved-body compile confirms 39/340 differing words,
  despite 99.367645% raw similarity. A separate back-substitution index is
  byte-identical. Explicit shared bound/decremented count regress to 338 words;
  changed forward bound yields 296 words. Retained original best body.
- `fn_1_42044`: 12/132 differing register words. The count_a/count_b/table_count
  allocation cycle is not finding 346's single loop-init copy. An inline
  table-selection helper is byte-identical; signed table count adds a load
  opcode mismatch. Retained original best body.

All claims released or submitted. The 48 pre-existing dirty/untracked paths
were hash-compared against the start-of-session manifest and left unchanged.
Only this session's match, repair evidence, finding and ledger snapshot are
part of the continuation commits; no push was made.

## Honest progress after closure

`fzgx honest --closure`: main_rel now has 2465 done / 765 todo;
project-wide 1502 functions remain, zero credited-but-unauthored functions,
and zero fully authored modules. That is one newly closed function, not a
claim that the overall decompilation is finished.
