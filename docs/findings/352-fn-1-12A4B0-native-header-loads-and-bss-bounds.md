# 352 — fn_1_12A4B0: native little-endian loads, real header extent, and complete BSS binding

Manual continuation, 2026-10-16, hermes-sol-manual / gpt-6.1-sol.
**MATCHED, link-verified, commit `3fec25c9`: 552 bytes / 138 instructions.**

## Fix semantic errors before coloring

The saved best body had only four differing positional words, but its header
logic was not an admissible source frontier. It used byte accesses through an
uninitialized `u16 idx` in place of two retail `lwbrx` instructions and declared
the third function parameter signed-16 despite retail comparing it full-width.
The original diagnostic was 134/138 positional words equal.

Use the already established MWCC builtin, also present in matched mdlload.c:

```c
/* The archive header stores two little-endian 32-bit words. */
hp = (void *)&lbl_1_bss_897AC_1B14[0];
(void)__lwbrx(hp, 0);
size = __lwbrx(hp, 4);
```

The unused first load is present in retail and retained by the intrinsic.
Remove the uninitialized index and byte-read fiction. The proper loads alone
leave one differing word; changing `arg2` from s16 to s32 closes all 138 words.
Remove the unused ArchiveState scaffolding and unneeded volatile qualification;
these cleanups remain byte-identical.

## A pool match was not yet linked C

The first submit saved an accepted pool match, but manifest status remained
nonmatching/pool, with no pool_map. `verify` committed its source as `59181aab`
with **zero verified functions**. The binary hashes passed because retail
fallback remained active. That commit was not counted as a new C closure.

Inspection of stock object BSS definitions and retail symbols showed the
scratch buffer declared as `u32 [0x20]`: 128 bytes, not the measured 32 bytes.
Retail ownership is:

- lbl_1_bss_897AC: size 0x1B34.
- Scratch header: owner + 0x1B14, leaving exactly 0x20 bytes.
- lbl_1_bss_8B2E0: next object, size 0xC0.
- lbl_1_bss_8B3A0: following object, size 0x14C.

Change the scratch storage to `u32 [8]`. The existing
`fixup_layout.bss_member_bindings` pass then names the measured interior
pieces, including the scratch as `lbl_1_bss_897AC__fzgx_offset_1B14`.
Every object now has a proven binding, and the full oracle reports MATCH
rather than MATCH(pool). Do not make a new repair runner or rewrite instructions.

## Compatible installation, without shared-prologue edits

The first revise attempt was rejected because archive.c's existing shared
prologue declares a consumed return value as void. No guard was bypassed.
Keep the measured call interfaces scoped inside this function and use a
private canonical-BSS alias for the unsigned word that conflicts with a
shared signed declaration. The result compiles both standalone and under
the existing TU prologue, with the same 138 words. No header or neighboring
function was changed.

The normal revise path accepted that body. A subsequent normal submit of
its canonical source promoted the manifest from pool fallback to matching
and installed the complete pool_map. The standard verifier then reported
`verified: [fn_1_12A4B0]`, no rejection, commit `3fec25c9`.

## Acceptance evidence

- Full oracle: MATCH, no differing rows, complete native BSS mapping.
- Manifest: status matching, not pool fallback.
- Ledger: matched / verified / matched_commit 3fec25c9.
- All 16 target SHA-1 checks pass; project lint has zero findings.
- Sources, bounded probe results and replay metadata are archived in
  `state/repairs/manual-native-header-and-title-20261016.json`.

This closure is 552 bytes of linked C, not the earlier pool-only source save.
