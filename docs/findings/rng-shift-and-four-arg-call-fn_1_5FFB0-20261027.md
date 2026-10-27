# `fn_1_5FFB0` (main_rel): the RNG reads the high halfword, and a four-argument call

Hand pass of 2026-10-27. Saved body 56.0% → 60.2%. The low score was three
independent mistakes, each visible in the disassembly:

- **RNG shift.** Both random draws are
  `f = (f32)((rnd >> 16) & 0x7FFF) / 32767.0f` (`extrwi r4, r8, 15, 1`, and
  `extrwi` extracts bit `31-sh`, so `nb=15, sh=1` is `(x >> 16) & 0x7FFF`).
  The body had `(rnd >> 1) & 0x7FFF`.
- **`lbl_1_bss_6C86C` is a word.** The second scale factor is
  `g = (f32)lbl_1_bss_6C86C` — retail does `lwz r0, 0x0(r30)` then
  `xoris r0, r0, 0x8000` (the *signed* int→float conversion). The body declared
  it `s16` and read `lha`, which also moves the `extsh`. It is written `30`
  (`stwu r29, lbl_1_bss_6C86C@l(r30)`, a fused store-with-update that leaves the
  base in r30 for the later read) and `lbl_1_bss_6C870[0] = 8` is a word store.
- **`fn_1_45D0` takes four arguments.** r3 is `lbl_801A6410`'s *value*
  (`lwz r3, 0x0(r3)`), r4 = `0xA0`, r5 = `&lbl_1_data_1D62C`
  (`lis r4, ...@ha; addi r5, r4, ...@l` — the pointer to the string that
  follows the RNG state), r6 = `0x1254`. The body called it with two arguments,
  which is why retail carries a `li r6, 0x1254` the body could not explain.

The last draw is `p->unk_54 = (rnd >> 16) & 3`; MWCC renders the 2-bit field
store as `extrwi 15,1` / `extlwi 2,14` / `srwi 31` / `subf` / `rotlwi 2` / `add`
before the `sth`.

## What is left

- **Shared literal pool.** Retail reads its five float constants as
  `lfs f1, 0x54(r28)`, `0x64(r28)`, `0x21c(r28)`, `0x8(r28)`, `0x20(r28)` from
  `lbl_1_rodata_2950`; our unit's private pool has its own offsets, so every
  float-load row differs. This is the pool-primer case in `MWCC_IDIOMS.md`, not
  a source-shape problem.
- **Scheduler slot order** in the two int→float conversion blocks (retail reuses
  stack slots 0x8/0x10/0x18/0x20/0x28/0x30/0x38 in a different order than ours)
  and the fused `stwu` base materialisation.
- Same register panel shift as usual.

Best body: `.fzgx/attempts/fn_1_5FFB0.1793081179.c` (60.2%).
