# `fn_4_EF8` (option): the saved body read the wrong input bits

Hand pass of 2026-10-27. The saved body for `fn_4_EF8` (option module, `GC/1.3.2`,
1356 bytes/339 rows) scored 68.4% and got several structures wrong. Reconstructing it
from the retail disassembly took it to 77.8% (209 of 359 aligned rows still differ).

## What the saved body had wrong

- **Input bit masks.** Retail tests the halfword at `lbl_1_bss_9F8 + arg0*0x14 + 0x10`
  with `extrwi. r0, r0, 1, 30` / `clrlwi. r0, r0, 31` / `extrwi. 1, 28` / `extrwi. 1, 29`,
  i.e. **bits 1, 0, 3, 2** (`(x >> 1) & 1`, `x & 1`, `(x >> 3) & 1`, `(x >> 2) & 1`) —
  the same four direction bits `fn_4_0` uses. The saved body wrote
  `0x4000 / 0x8000 / 0x1000 / 0x2000`, which is not even the same four bits.
  `extrwi rA,rS,1,sh` extracts bit `31-sh`, so read the mask off the shift field.
- **The repeated-input idiom.** The first read is `lhzu r0, 0x10(r5)`, the rest are
  `lhz r0, 0x0(r5)`: the source is `(*(volatile u16 *)(input += 0x10) ...)` followed by
  further `*(volatile u16 *)input` reads, exactly the `p += 0x10` form that matched
  `fn_4_0` in the same file. The volatile comment is required (repeated loads).
- **The flag prelude is per case.** Inside the angle-in-sector branch it guards only the
  `d1 < din` update; in the four *sector* cases of the else chain
  (`tab[0], tab[2], tab[4], tab[6]`) each body repeats
  `if (p->flag == 0) { fn_1_A2D84(0xA9010300); p->flag = 3; }`. The four `< px`/`< py`
  cases for `tab[8..14]` have **no** prelude.
- **The float work is six conversions, then three lengths.** Retail converts each of
  `tab[idx].x/y`, `tab[idx+8].x/y`, `px`, `py` once (int→float via the shared
  `lbl_4_rodata_100+0` 2^52 constant, `fsubs` = the result is `f32`), then forms
  `d1`, `din = px² + py²`, `d2`. The saved body wrote the products in integer
  arithmetic. Writing `(f32)p->tab[idx].x * (f32)p->tab[idx].x` inline is **not**
  CSE'd by MWCC (it emits 12 conversions and grows the frame by 0x30 — 0xb0 instead
  of 0x80); the conversions must be named `f32` locals.
- Tail: `tv = (u16)t` is the zero-extended angle used by the sector tests (`cmplwi`),
  while the two in-sector compares use `(t & 0x3FFF)` twice (`cmpwi`, signed) — so `tv`
  is `u16` and the sector value stays `s32`.
- `px`/`py` are `s32` locals loaded from `s8` fields: retail extends them once at the
  load (`lbz; extsb`) and never again. With `s8` locals MWCC re-extends per use
  (`extsb.` at each compare).
- Else chain is `if (tab[k].x/y <op> px/py && tv ...)`: the angle window comes *second*
  in every source term, and the wrap-around case is `tv > 0xF000 || tv < 0x1000`
  (centres 0, 0x4000, 0x8000, 0xC000 with half-width 0x1000; the last four cases carry
  no angle test at all).

## What is left (measured, not repaired)

- **Base materialisation.** Retail addresses the vectors as a constant base plus the
  scaled index (`addi r29, r31, 0x20; lbzx r3, r29, r30`, `addi r0, r31, 0x30;
  add r26, r0, r30`, `addi r3, r31, 0x40; add r3, r3, r30`), and in the else chain it
  rematerialises `&tab[0]`/`&tab[8]`/`&tab2[0]` per case (`addi r3, r31, 0x20` then
  `0x5(r3)` for `tab[2].y`). Direct member access compiles the other way round
  (`add r29, r31, r30; lbz r0, 0x20(r29)`), i.e. `p + idx*2` as the base.
  Naming the bases as pointer locals (`v1 = p->tab; v2 = &p->tab[8]; t2 = p->tab2;`)
  does reproduce the bases, but the three extra live values shift the whole
  callee-saved panel (`_savegpr_22` instead of `_savegpr_24`) and grew the frame to
  0x90: 77.4% with pointers, 77.0% when the assignments were moved into each branch.
  Retail keeps such bases in r26–r29 only while they are live across the
  `fn_1_A2D84` call and rematerialises them everywhere else, which is what a
  shorter-lived spelling would have to reproduce.
- **`&p->cnt` materialisation.** The `cnt.y` accesses read `addi r4, r31, 0x14;
  lbz r3, 0x1(r4)` while `cnt.x` folds to `0x14(r31)`, and the `before.y` compare
  does the same — only the `.y` half materialises the pair's address. No source
  spelling found yet (`struct` member, `u8[2]`, pointer local all fold both halves).
- Everything else is the usual register-panel shift (ours sits one register above
  retail's: `mr r25, r3` where retail has `mr r24, r3`).

Best body: `.fzgx/attempts/fn_4_EF8.1793080440.c` (77.8%).
