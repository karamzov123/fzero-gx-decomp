# 357 — fn_1_12F358: recover native selection-state objects, not a truncated pointer carrier

Manual continuation, 2026-10-16, hermes-sol-manual / gpt-6.1-sol.
**MATCHED, link-verified, commit `bcc811aa`: 336 bytes / 84 instructions.**

## The small extension frontier was not an invitation to pad a pointer

The saved body tried to reproduce two address-materialization sites by
passing the state pointer through a padded struct with a u16 value. It also
used a one-field selection-array pointer and a generic array-read helper.
That historical diagnostic is not an admissible final source: it discards
the high half of a real state address.

Removing the padding/truncation, pointer carrier and array-read helper gives
an 82-word natural source versus retail's 84. Toggling propagation only around
the meaningful input-flag helper does not restore the missing address steps.
Do not go back to padded, truncated, volatile or opaque pointer tricks.

## Recover the real separate objects behind the shared BSS register

Retail materializes state at `base + 0xC0`, reads its input index at +0x9E,
and toggles two bytes at base +0x310/+0x311. The old source pretended those
were members reachable by arithmetic from the first object. Symbol ownership
shows otherwise:

| Native object | Size |
| --- | ---: |
| lbl_1_bss_8B2E0 | 192 |
| lbl_1_bss_8B3A0 | 332 |
| lbl_1_bss_8B4EC | 128 |
| lbl_1_bss_8B56C | 96 |
| lbl_1_bss_8B5CC | 32 |
| lbl_1_bss_8B5EC | 4 |
| lbl_1_bss_8B5F0 | 1 |
| lbl_1_bss_8B5F1 | 1 |

Define the measured objects separately, with private canonical-binding names
and the established `.fzgxpool` native-order primer. The state view has its
known index at +0x9E and an unknown tail ending at the actual 332-byte boundary;
no invented allocation padding or cross-object C pointer arithmetic is needed.

Pass the actual state object to the reusable input-flag lookup helper, and
read/write the actual two byte objects directly. The helper still performs
real work—indexing the input array and testing bit 4—and is used on both paths.
No generic one-use read helper remains. The selection array uses ordinary
indexing through a plain pointer.

Because these are native objects defined in one unit, MWCC naturally shares
its BSS section base and emits the two state-address materializations retail
uses. This closes **84/84 instruction words** with no padded carrier, pointer
truncation, dead liveness expression, new branch or instruction patch.

## Acceptance

- Full oracle: **100.0% MATCH**, complete nine-entry map (section base plus
  the eight measured objects), no unresolved pool fallback.
- First `write-unit` check of the native body: MATCH and lint clean.
- `submit`: pending real C link.
- `verify`: exactly fn_1_12F358 verified, no rejection, commit `bcc811aa`.
- Manifest matching; ledger matched / verified / matched_commit bcc811aa.
- All 16 target SHA-1 checks pass; whole-project lint has zero findings.

No shared header, prologue, compiler, tool implementation or neighbor function
was modified. This is the missing native-object layout, not a source spelling
that preserves an artificial register web.

## Other bounded work; no additional closures

### fn_3_4538

Probed full-width flags/results and an unsigned input field, removed the
one-use array helper, liveness expressions, union steering and fictitious
one-element extern-array bounds. The natural body is 232 words versus retail
234 and retains 18 differing aligned rows in the full oracle (cast placement,
input-load reuse and allocation). Final ABI of the selection-returning callee
is not independently established by this probe and must not be asserted.
The candidate is preserved as provisional nonmatching evidence, not a match.

### fn_1_141C10

Both elapsed-time spellings—using the same current-time temporary in the two
branches, or directly writing current minus saved time—are byte-identical to
the 225-word baseline, retaining six global address/load/subtract register
residuals at words 93..98. These spellings are measured and stopped; no semantic
correction or new C closure was claimed.

## Handoff

Complete sources, stock compiler settings, target-object digests and bounded
probe metadata are in `state/repairs/manual-selection-bss-ownership-20261016.json`.

Honest closure: **1494 functions remain**; main_rel 2468 done / 762 todo;
zero credited-but-unauthored functions. All 48 original changed/untracked paths
remain hash-identical, and all claims are drained. No fleet restart, subagents
or push.
