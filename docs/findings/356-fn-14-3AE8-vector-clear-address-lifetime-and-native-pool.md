# 356 — fn_14_3AE8: correct the clear, delay the address, eliminate duplicate constants

Manual continuation, 2026-10-16, hermes-sol-manual / gpt-6.1-sol.
**MATCHED, link-verified, commit `8c6495ce`: 776 bytes / 194 instructions.**

## Six register/scheduling rows hid a semantic error

The saved body had six differing positional words (5, 7, 10, 11, 12, 14).
It initialized the first vector pointer at declaration, before computing
quotient/remainder, and called `fn_80008BEC(va, 12, 0)` where retail passes
zero as the fill and 12 as the byte count.

Correct the first clear to `fn_80008BEC(va, 0, 12)`. That correction alone
leaves the same six differing word positions; similarity is not an admission
that the old zero-length clear was semantically correct.

Declare `Rp_v3 *va` without initializing it, and assign the actual vector
address immediately before the corrected clear, after the division and
remainder work. This changes the source value's definition/use lifetime:

```c
q = v / lbl_14_bss_160.unk_0;
qq = (s16)q;
rem = v - q * lbl_14_bss_160.unk_0;
idx = (s16)(rem + 1);

va = (Rp_v3 *)&lbl_14_bss_92C4.unk_4;
fn_80008BEC(va, 0, 12);
```

Stock GC/1.3.2 results, with original settings retained:

| Source | Words | Positional differences |
| --- | ---: | ---: |
| Original | 194 | 6 |
| Correct clear only | 194 | 6 |
| Correct clear, pointer defined after division | 194 | **0** |
| Direct address passed to clear, pointer assigned after call | 194 | 20 |

No declaration permutations, new optimizer flags, allocator wrappers or object
instruction edits were needed.

## Full native integration, not a pool-source save

The first exact body was only MATCH(pool): it still defined a second set of
native-named constants in addition to its already proven 352-byte pool prefix.
`verify` saved the source as `8c94d4f8`, reporting **zero verified functions**.
The manifest still used retail fallback. That commit was not counted as a
new C closure.

Remove the duplicate file-scope constant definitions. Express the three
actually read scalar values as their measured floating literals:
0.699999988079071f, 182.04444885253906f, and 1.0f. The proven compiler-owned
prefix already provides their correct locations. This removes redundant
owned definitions without changing any of the 194 instruction words.

The full oracle now returns MATCH, not MATCH(pool), with three proven
relocation bindings: the shared base, the conversion double at +0x110, and
the 1.0f literal at +0x30. Standard revise/normal submit promotes the canonical
source to matching; verifier reports exactly fn_14_3AE8 verified, no rejection,
commit `8c6495ce`. No shared header/prologue was changed.

## Bounded negative evidence from this continuation

### fn_17_456C

The saved body has five differing words in 187. Sharing its object variable
across exclusive mode branches adds four more differences, for nine total.
Do not generalize the shared-index success to every pointer web. Baseline
retained, claim released, no closure.

### fn_80021C7C

The historical high-similarity body is not an admissible final source: it
accepts a fill input where retail initializes zero, clears the first region
backwards starting beyond its intended base, fills the next region with 2,
and declares the final word-sized SDA flag as u16.

Saved a natural corrected no-argument source: zero initialization, forward
first clear, zero-filled second clear, word-sized flag, and no one-field
pointer carrier. Under main's stock GC/1.2.5n context it compiles to 210 words
vs retail 208; GC/1.3.2 gives 209. Scalar and typed workspace views change
prologue/zero-value allocation broadly; propagation-off variants give 214–215
words. These bounded forms do not close. Correct source survives separately
from the historical high-score body; none was submitted as matching C.

### fn_1_FF420

The saved body has three differing words in 166, but uses one-use arithmetic
wrappers. Removing them yields a natural arithmetic body with 13 differences.
A symmetric last component sum has 16; a direct angle expression has 12.
These families are measured and stopped, not counted as new decompilation.
The helper-free complete body is preserved in the portable archive.

## Verification and handoff

- Full oracle MATCH; manifest matching, no fallback; ledger verified at 8c6495ce.
- All 16 target SHA-1 hashes pass; whole-project lint has zero findings.
- All 48 pre-existing changed/untracked paths remain hash-identical.
- All claims drained; no fleet restart, no subagents, no push.
- Honest closure: **1495 functions remain**; pilotpoint 45 done / 23 todo;
  zero credited-but-unauthored functions.

Portable sources, exact compiler settings, target-object digests, and bounded
probe metadata are in `state/repairs/manual-vector-clear-lifetime-20261016.json`.
