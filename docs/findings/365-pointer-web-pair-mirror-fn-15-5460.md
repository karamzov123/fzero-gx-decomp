# 365 — pointer web pair mirror, fourth tiebreak unit (fn_15_5460)

## fn_15_5460 (module winning, 180 words, pin GC/1.3.2 = mwcc_242_81)

Best body: `.fzgx/attempts/fn_15_5460.1791781829.c` (99.77778%). Residual = 8 rows,
two identical motifs (second motif at 0x1ECC), each:

- w86 retail `addi r4, r31, 0x1e6c` vs ours `addi r5, ...` — A web
  (`tbl_50 = (u32 *)((u8 *)p_data + 0x1E6C);`).
- w87 retail `addi r5, r3, 0` vs ours `addi r4, r3, 0` — B web
  (`p_idx = &lbl_801A66B4;` materializing from the section-base `lis r3`).
- w89/w91: the load and the indexed load follow the pair (`lwz r0, 0(B)` and
  `lwzx DEST, A, r0` with the slwi row w90 matched in both).

The {A, B} homes mirror exactly: retail {A=r4, B=r5}, ours {A=r5, B=r4}. C statement
order (A then B, first textual occurrence of both locals at these lines) already
matches the emission order; ours assigns the later-created B the earlier register.

Measured cohort (offline, module-default mw; same 8 diffs unless noted):
- statement swap of lines 104↔103 (p_idx before tbl_50) for both motifs — no change.
- statement swap for one motif only — no change.
- decl swap (`u32 *p_idx;` above `u32 *tbl_50;`) — no change.
- field-alias forms `(u32 *)&lbl_15_data_0.unk_1E6C;` (with explicit cast; the
  bare field form is rejected: `illegal implicit conversion from 'unsigned long
  (*)[1]'`) and `(u32 *)&lbl_15_data_0.pad_1E70[0x5C];` — 92/93-diff reshuffle:
  section-base addressing differs from the r31-based form, not the same shape.
- compiler-version sweep of the base body across GC/1.2, /1.2.5, /1.2.5n, /1.2.7,
  /1.3.2, /1.3.2r, /1.3.2p2: only GC/1.3.2 and GC/1.3.2r produce the 180-word
  structure (1.2.5/1.2.5n = 173 words; others fail); 1.3.2r gives the identical
  8 diffs. Pin confirmed correct.

## Family context (findings 363, 364)

Fourth unit in the same family: a small set of adjacent statement webs whose
{home} assignment is mirrored between ours and retail while the machine state
before the webs, the emission order, and every other row match. Independent probes
(access paths, product order, decl order, statement order, field aliases, compiler
versions) fail to flip it on all four units:

| unit        | rows | webs                      | ours        | retail      |
|-------------|------|---------------------------|-------------|-------------|
| fn_8003A3D4 | 2    | (u16)unk8 cast            | r8 (pitch)  | fresh r7    |
| fn_800288C4 | 2    | arg0-rem subf + slwi      | r0,pitch r0 | r5 fresh, r0 |
| fn_1_16BA0  | 4    | arg0[1]/unk_10 loads      | f1,f3       | f3,f1       |
| fn_15_5460  | 8    | tbl_50/p_idx ptrs (2x)    | r5,r4       | r4,r5       |
| fn_12_A5C   | 5    | quarter dividend + srawi  | r4 src2, r4 pitch | r3 src1, r5 fresh |

Direction is inconsistent (ours=later-lower on 16BA0/15_5460, ours=earlier-pitch on
A3D4/288C4, compound on A5C: src2-pitch + fresh-turns-pitch), so no single C-level
transform closes the family. All five are parked at ~99.77-99.9% with the residual
fully diagnosed. Any closure likely needs allocator-level
evidence beyond source shape (e.g. the mwconstraints engine growing a web-pair
generator with a validated flip evidence).

Status: parked; body remains best saved attempt.
