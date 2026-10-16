# 355 — fn_8_ABBC: replace dummy pool padding with the proven title prefix and correct RGBA initializer

Manual continuation, 2026-10-16, hermes-sol-manual / gpt-6.1-sol.
**MATCHED, link-verified, commit `79984161`: 568 bytes / 142 instructions.**

## All instruction words were already equal; the source still did not match

The saved body had 142/142 relocation-masked instruction words equal, but its
literal-pool primers contained synthetic values such as 1234.5, 1001.0,
2001.0..2049.0 and 3001.0..3015.0. Equal word layouts did not establish the
correct constant values. A fresh full-oracle check of that original source
returns **99.26057%, matched false, matched_pool false**.

Use finding 353's measured native prefix anchored at `lbl_8_rodata_160`.
This function needs the prefix through relative offset 0x154 (340 bytes),
not finding 353's complete 384-byte prefix:

- Retain the existing measured primer source through offset 0x14C.
- At 0x14C keep only the first 0xFFFFFF00 word of the three-word table.
- At 0x150 let this function's automatic Color initializer emit its own word.
- Decode the real word at anchor + 0x150: **FFFFFF00**, not FFFFFFFF.
  Set the initializer to `{255,255,255,0}`. Its alpha is subsequently replaced
  by the existing computed alpha, but its bytes still must bind correctly.
- Drop both dummy primer functions completely. The replacement uses the
  established `.fzgxpool` compiler-owned prefix pattern, not extra text helpers
  or literal values chosen merely to fill space.

The native source remains exactly 142 instruction words. The full oracle
now proves the entire 340-byte initializer and all required interior literals,
including the 20.0f scalar, and accepts a real MATCH with a complete pool_map.
No instruction or compiler binary was modified.

## Acceptance

- First `write-unit`: **100.0% MATCH**, lint clean.
- `submit`: pending link, full pool_map rather than pool fallback.
- `verify`: exactly fn_8_ABBC verified, no rejections; commit `79984161`.
- Manifest status matching; ledger matched / verified with that commit.
- Independent SHA-1 validation: **all 16 targets OK**; project lint zero findings.

## Other bounded work; do not restart exhausted families

### fn_80057494 — handle truncation and ring extent corrected, no closure

The old source narrowed a full-width handle to s8 before testing nonzero and
declared eight ring entries while using modulo-16 indexing. Preserve a clean
candidate with a full-width u32 handle and a 16-entry declared view. These are
source semantic corrections, not a claimed linked-C contribution.

Reproduce the right compiler context: main defaults to GC/1.2.5n, while this
saved frontier reproduces four differing words under stock GC/1.3.2 with
`-use_lmw_stmw on` (146 target/candidate words). The recorded `-O3` context
regresses to 147 words and is not interchangeable with that context.

Uniform signed saved values, an explicit zero-copy chain and the full-width
handle fix do not close the four-word frontier. Sharing the earlier status
temporary with the later saved value regresses to 13 word differences;
sharing the final seek zero too gives the same result. Preserve the corrected
body and compiler settings separately from raw-similarity best-body selection.

### fn_1_6D488 — proven vector bytes, readonly-load hoisting remains

Retail's velocity bytes are `{0,0,-2}` at `lbl_1_rodata_2D70 + 0x250`, inside
that symbol's 988-byte owner. Replacing the duplicate integer primer words
with a real named vector constant corrects literal ownership but lets MWCC
hoist all three readonly loads out of the loop. The frame grows 0x180->0x190
and register allocation changes broadly, despite retaining 136 instructions.
Removing the one-field cache-pointer carrier is byte-identical to that named
constant variant. No volatile fiction or compiler patch was used. Original
best body retained; named-constant hoisting family measured and stopped.

## Final handoff

Portable complete sources and compiler/probe metadata:
`state/repairs/manual-exclusive-index-and-title-pool-20261016.json`.

This continuation adds two verified functions: 1144 bytes / 286 instructions.
Honest closure: **1496 functions remain**; sel 128 done / 95 todo;
title 89 done / 31 todo; zero credited-but-unauthored functions.
All 48 pre-existing changed/untracked paths remain hash-identical. No active
claims, no fleet restart, no subagents, and no push.
