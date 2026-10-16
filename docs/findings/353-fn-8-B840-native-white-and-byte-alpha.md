# 353 — fn_8_B840: actual white color, byte-width alpha, and an anonymous initializer

Manual continuation, 2026-10-16, hermes-sol-manual / gpt-6.1-sol.
**MATCHED, link-verified, commit `3b2bad56`: 684 bytes / 171 instructions.**

## The residual was semantic and scheduling, not just a color displacement

The saved candidate had 171 instructions, four differing positional words,
and a guessed black TitleColor `{0,0,0,255}` at relative pool offset 0x180.
Retail loads a white word FFFFFFFF at relative offset 0x17C.

Read the correct retail anchor: **lbl_8_rodata_160**, not section offset zero.
Raw `.rodata[0x17C]` is unrelated to the instruction's `0x17C(r31)`;
the referenced color is `.rodata[0x160 + 0x17C]`. Always derive the section
base, symbol anchor and displacement explicitly.

Remove the duplicate trailing u32 white-color primer table/keep helper and
replace the actual color with white. The source prefix now reproduces exactly
384 bytes of retail data starting at lbl_8_rodata_160. Four word differences
remain because the signed-32 alpha conversion schedules differently:

```diff
-color.a = (s32)(255.0f * opacity);
+color.a = (u8)(255.0f * opacity);
```

This natural field-width conversion closes all 171 instruction words.
A named byte-alpha intermediate also matches; a signed-32 intermediate does
not. The minimal direct u8 conversion was retained.

## Remove source-only pool fallback

The first accepted submit was still MATCH(pool), with an empty pool_map and
nonmatching manifest status. Verifier commit `15e67e83` saved that source but
verified **zero functions**; passing hashes at that point still used fallback.

Two ownership corrections remove that last integration obstacle:

1. Use the canonical `lbl_8_bss_3D0` already declared in operation.h. Remove
   the redundant private BSS objects, unused padding objects and their layout
   helper. This function does not need to own or recreate that shared BSS.
2. Replace the named file-static color object with the natural block-local
   initializer `TitleColor color = {255,255,255,255}` around its use. The named
   static object kept a private defined symbol alive after pool retargeting;
   the anonymous automatic initializer permits complete native pool binding.

This preserves every instruction and uses neither volatile tricks nor object
patches. The remaining pre-existing pool primer represents the measured
384-byte prefix and is handled by the established build pipeline.

The standard revise path accepted the body under its existing TU prologue.
A normal submit promoted the canonical source's manifest to matching with the
complete pool map. Verifier then reported exactly fn_8_B840 verified, no
rejections, commit `3b2bad56`.

## Other bounded continuation: fn_1_C742C remains unmatched

The historical high-score source is inadmissible: unsigned-byte camera mode,
undefined `fn_1_5348() >> 32`, one-field mode/group carriers, a one-use pointer
helper and a liveness-only expression. Do not retry it as a legitimate frontier.

Recovered a signed camera mode and low-byte flag test and removed the carriers,
pointer helper and liveness expression. camera.c confirms camera_get_mode
returns s16. The natural body with the old s32 return declaration has 189 words
vs retail 188. With the proven s16 return declaration it has 190 words and
32 differing aligned rows (192 aligned rows including insertion/deletion).
It is a valid saved structural starting point, not a match or a claimed gain.
The portable evidence preserves this clean source independently of the raw
score's choice of best body. No further flag/type permutation sweep was run.

## Final state of this continuation

- Two newly linked C functions, 1236 bytes / 309 instructions total.
- All 16 target SHA-1 hashes pass; whole-project lint has zero findings.
- Ledger: both functions matched / verified, with the exact commits above.
- Both manifest records are matching, not pool fallback.
- Honest closure: 1498 functions remain; main_rel 2467 done / 763 todo;
  title 88 done / 32 todo; zero credited-but-unauthored functions.
- All 48 original changed/untracked paths remain hash-identical; claims drained.
- Fleet remains stopped; no subagents and no push.

Portable sources and replay evidence:
`state/repairs/manual-native-header-and-title-20261016.json`.
