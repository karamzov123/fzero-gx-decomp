# 377 — fn_1_53B14 landed: the zero template matches the code but not the displacements; rebuild the pool window

Session of 2026-10-17 (opencode/deepseek, agent `deepseek-opencode`). Fifth landing
of the day. Closes the 99.22449% plateau of `fn_1_53B14` (main_rel/font, 49 words,
12 prior attempts, attempt 13 of the claim): the saved best body compiled to
**46/49 identical words**, with exactly three residual rows — all displacement
immediates off the live pool base `r7`:

    w25  lfd f2, 0x60(r7)   | lfd f2, 0x68(r7)
    w27  lfd f0, 0x150(r7)  | lfd f0, 0x58(r7)
    w35  lfs f3, 0x158(r7)  | lfs f3, 0x60(r7)

Landed commit `e4abc50a` (claim, write-unit `100.0% MATCH` on the first check,
submit, verify fast path 11.9 s; gate: ninja 0, dtk shasum 16 files OK, lint 0,
11 tests OK). Builds directly on finding 344 (`fn_1_53E40`, the same
`.rodata` region, the same TU): this function needs the *same window* reconstructed
for a different reason.

## Why the best body could not close: zero template instead of the real table

The 99.2% body initialised the 0x58-byte record with `Fn53B14Params params =
{ 0 };`. MWCC materialises a large all-zero aggregate as a copy **from a
compiler-generated zero template in `.rodata`** — instruction-for-instruction the
same copy loop retail uses (`subi r5, r7, 4; mtctr 11; lwz/lwzu/stw/stwu`), which
is why every non-displacement word matched. But the template is anonymous and
all-zero, and the literals then carry **their own layout** relative to it:

    ours:   [zero template 0x58][255.0 @0x58][8.0f @0x60][pad][2^52 @0x68]
    retail: [table 0x58][{0,1.0f} @0x58][2^52 @0x60][58 words @0x68..0x150][255.0 @0x150][8.0f @0x158]

Displacements are baked into the instruction words. `_pool_rows` repairs
*relocation targets* only; nothing in the tooling can repair a displacement
immediate. The ANONYMOUS `...rodata.0` base row additionally failed the byte proof:
our window from the base is the zero template, retail's is the mixed 348-byte
(`0x15C`) region down to the last reach (`lfs f3, 0x158(r7)` → `0x15C`).

## The fix: rebuild the retail window and copy from the real table

The block is self-contained (`noprologue`, like `fn_1_53E40`) and reconstructs
`[lbl_1_rodata_26F8, +0x15C)` byte-equal as native pool objects pinning the
literals in first-use order:

- `fzgx_pool_table1[22]` — the retail 0x58-byte table (the record defaults; the
  same word list finding 344 already reconstructed). The body now does
  `Fn53B14Params params = *(const Fn53B14Params *)fzgx_pool_table1;`.
- `fzgx_pool_table2[2] = {0x00000000, 0x3F800000}` — fills `0x58..0x60` so the
  2^52 magic lands at `+0x60`.
- `.fzgxpool` primer `d = 4503599627370496.0;` — creates the 2^52 literal at
  `+0x60`; the `(f64)(u32)` conversion in the body dedupes onto it
  (`@9 → lbl_1_rodata_2758`).
- `fzgx_pool_table3[58]` — the retail bytes `0x68..0x150`.
- `.fzgxpool` primer `d = 255.0;` — 255.0 at `+0x150` (division constant).
- `.fzgxpool` primer `s = 8.0f;` — 8.0f at `+0x158`. This is the one deviation
  from finding 344's block: `fn_1_53E40` pinned `+0x158` with a native
  `fzgx_pool_table4[1]` because its body never reads 8.0f; this body passes
  `8.0f` four times, so the slot must be a **literal** the call arguments can
  dedupe onto (one `lfs f3, 0x158(r7)` + three `fmr`, retail's shape).

The pool machinery then proves and retargets exactly as for finding 344:

    pool_map {...rodata.0 → lbl_1_rodata_26F8, @9 → lbl_1_rodata_2758,
              fzgx_pool_table1 → lbl_1_rodata_26F8}

Post-retarget object: `.text` **byte-equal to retail** (196 B, verified by direct
comparison), relocations identical (`0xa` ADDR16_HA + `0x16` ADDR16_LO to
`lbl_1_rodata_26F8`, `0xb0` REL24 `fn_1_50190`), `.rodata` emptied.

## Notes

- PROLOGUE CONFLICT is expected and designed: the block declares
  `fn_1_50190(void *, f32×6)` while the TU prologue's view (used by `fn_1_50164`)
  is a 6-float prototype; submit splices the block `noprologue` (finding 344's
  trap-doc entry). `write-unit` reports the conflict but the check still landed
  `100.0% MATCH`; normal submit does not gate on it.
- Blocks compile per unit (`build/GFZE01/gen/rel/main_rel/font/fn_1_53B14.c` →
  its own `.o`), so `fzgx_pool_*` names recurring across blocks of one TU file
  are separate objects — no collision, no cross-block layout coupling. The
  window reconstruction is per-block by construction.
- Validation cost: zero ledger checks before the claim. One offline
  `oracle.check(proj, 'fn_1_53B14', source=…)` predicted 100.0% + full pool_map;
  the byte-equality check of the poolfix-applied object predicted the link. Only
  then claim → write-unit (1 check) → submit → verify.
- Diagnostic rule this adds: **when the only residual rows are displacement
  immediates off a base register that already matches, the source shape is right
  and the layout behind the base is wrong.** Reconstruct the retail window from
  `project._raw_section(module, '.rodata')`, order the native objects/primer
  literals by first use, and let the reach window (`(max displacement + access
  width)`) define the byte proof; do not spend variants on the body.

Files: landed block `src/rel/main_rel/font.c#fn_1_53B14` (commit `e4abc50a`,
units.json `pool` map); candidate probe `/tmp/opencode/f53b14_cand.c`; prior best
body `.fzgx/attempts/fn_1_53B14.1791048667.c` (99.22449).
