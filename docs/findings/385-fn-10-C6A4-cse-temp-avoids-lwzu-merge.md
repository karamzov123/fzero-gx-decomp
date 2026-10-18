# 385 - fn_10_C6A4: don't cache the global — the CSE temp that avoids the lwzu merge

Symbol: `fn_10_C6A4` (sel, 516 B, 129 instructions). Landed at attempt 10.
Commit `d3d89f4f` (unit splice + units.json), link-verified (fast path, 10.4 s).
Best before: 99.2% with exactly one extra instruction.

## The residual was a single insertion

The 99.2% body cached the flag word in a declared local:

```c
s8 v1;
...
v1 = lbl_10_bss_55664;
```

which compiled to retail's exact shape (value `r3`, address `r4`) plus one
insert:

```
14  lis  r3, lbl_10_bss_55664@ha      14  lis  r3, ...
15  li   r0, 5                        15  li   r0, 5
16  addi r4, r3, lbl_10_bss_55664@l   16  addi r4, r3, ...
17  lwz  r3, 0x0(r4)                  17  lwz  r3, 0x0(r4)
18  rlwnm. r0, r3, r0, 0x1f, 0x1f     18  extsb r3, r3        <- extra
                                      19  rlwnm. r0, r3, ...
```

Only the tail check mattered: with the insertion removed, the remaining 111 rows
matched retail 1:1, and the head diffs were only the five forward branches whose
+4 offset follows from the inserted word. One instruction, zero other content
differences.

## Why the two obvious spellings both fail

| body | result |
| --- | --- |
| `s8`/`s16` local (extension at assignment) | retail's register shape (value r3 / addr r4) but the extension emits `extsb`/`extsh` (130/131 words) |
| `s32`/`u32` local (no extension) | no extra insn, but the peephole fires: `addi r4, r3, @l; lwz r4, 0(r4)` merges to `lwzu r4, @l(r3)` — address in r3, value r4, 128 words |

The merge condition is `load target == addi target`. A declared local that must
carry the extension cannot coalesce cleanly, so its load result stays in a
separate register (r3) and the merge never matches; a plain 32-bit local lets
the allocator put the value in the addi's target and the update-form proceeds.

Every spelling that keeps a local leaks into one of the two: pointer locals
(`u32 *p`, before/after calls, `register`, load-only, store-only) either get
coalesced to the merged form or get pinned to a callee-saved register (r31 with
its own frame stores) when live across a call; casts (`(s32)`, `+`), volatile
loads/casts, `u8` intermediates, inline getters, statement and declaration
orders are all no-ops; GC/1.3.2-2.7 emit identical code (1.0-1.2.5 and 3.0ax
differ wholesale); `-O4` vs `-O4,p` vs `-O3`/`-O2` (no effect / worse).

## The fix: no local at all

The original source used the global directly at every use; the front end CSEs
the loads into one compiler temporary that colors value r3 / address r4:

```c
if (__rlwnm(lbl_10_bss_55664, 5, 31, 31)) return;
if (__rlwnm(lbl_10_bss_55664, 6, 31, 31)) return;
if ((s32)lbl_10_bss_55664 == 0) {
    lbl_10_bss_55664 = (s32)lbl_10_bss_55664 | 0x80000000;
} else {
    switch ((s32)__cntlzw((s32)lbl_10_bss_55664)) { ... }
}
```

129/129 words exact, no scratch pragmas, no address-split, no pool retarget.
Both the direct-everywhere form and the "direct tests + late `s32` local for the
switch" form are byte-identical (the CSE makes the caching decision); the
committed block uses the direct form. The `(s32)` casts at the `== 0` and
`cntlzw` are load-bearing only in the sense that they match the signed compares;
keep them when reworking.

## Unit-compatible declarations (src/rel/sel/sel.c already declares these)

`extern s32 lbl_1_bss_7180C;`, `extern u8 lbl_1_bss_718E0;`,
`extern int fn_1_B7C5C(void);`, `extern int fn_1_B7E98(int);`,
`extern void fn_1_AA6D8(int, int, void *);`,
`extern void fn_80008BEC(void *, int, u32);`,
`extern u32 lbl_10_bss_3C0[74736];`, plus the block's own
`extern u32 lbl_10_bss_55664;`, `extern u32 lbl_10_bss_55668;`,
`extern u8 lbl_10_bss_5566C;`, `extern u8 fn_1_B7C00(void);`,
`extern s32 fn_1_B7C6C(u32);`, `extern u32 fn_1_B7CD4(void);`,
`extern void fn_1_B7F24(void);`, `extern void fn_1_F79C8(void);`.
No `sel.h` include — the unit declares inline per block and header types
conflict with the unit's existing inline decls. `extern u8 lbl_1_bss_718E0;`
reproduces the pointer store exactly (the symbol is `u8` in this unit).

## Corpus rule

When a one-instruction `extsb`/`extsh` insertion sits right after a global
load, and the "obvious" local type removes the extension but turns the load
into `lwzu`, the retail source likely cached nothing: drop the local and use
the global directly (CSE supplies the temp). This is the inverse of the
'88-copy / declaration-rank' levers: here the local is the bug, not its slot.
