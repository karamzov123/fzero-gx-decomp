# Finding 316: the 613 "unmeasured" functions have never been written

`inventory` used to crash on this set (`TypeError` on `best_percent is NULL`, fixed in
`cbe9dccf`), which made them look like an untapped vein of near-misses. They are not.

Measured by resolving every unmeasured symbol against its unit:

| state | count |
|---|---|
| no unit registered | 590 |
| unit file missing on disk | 19 |
| empty carve stub (no function body) | 3 |
| **has a real C body** | **0** |

So **none of the 613 has ever been written in C.** Their `best_percent` is NULL because
there is nothing to measure, not because measurement failed.

Proof of the failure mode, from `fn_8004CD70` (1052 B, `main`):

    fn_8004CD70: 0.0%  unit=main/dol/fn_8004CD70  no match
    missing in our object: fn_8004CD70

The carve stub is:

    #include "types.h"

    // fn_8004CD70: main .text:0x8004CD70 size 0x41C
    // Carved by fzgx. Replace this file's body with the matching C.

It declares no function, so the symbol is never emitted. The compiled
`.fzgx/work/fn_8004CD70.o` is **400 bytes with zero instructions** — verified by
disassembling it with capstone.

**Consequence:** `asm-unit` is the only path that can "land" these without writing C,
and it works (it links the retail disassembly directly). But converting an *unwritten*
function to asm is not the same as converting a *regalloc wall*: findings/315 justifies
its asm units with a measured C residual, whereas these have no C attempt at all. Use
`asm-unit` on them only if the goal is byte coverage; it does not advance the
decompilation.

The real work on this set is writing the C, which is ordinary decompilation labour:
claim, read the retail disassembly from the claim context, write the body, check.

## But writing the C is real, tractable work — proof: fn_8004CD70

`fn_8004CD70` (1052 B, `main`, 263 retail instructions) was an empty carve stub
scoring 0.0%. A first C body written from the retail disassembly reached **27.5%**
in four iterations, and the structure is now fully recovered:

- 16-entry slot table at `lbl_80178CBC`, 0xC0 bytes per entry
- free-slot scan on the `used` byte, `NULL` when all 16 are taken
- argument guard: `a < 0 || a == 0 || b < 0` calls `fn_800474E4` and returns `NULL`
- `memset(slot, 0, 0xC0)` then the field layout
- `field_20 = (a + 0x3F) & ~0x3F`, `field_24 = ((b - (rounded - a) - 0x124) >> 11) << 11`,
  `field_28 = 0x24`, `field_AC = field_28 + field_20 + field_24`
- `field_2C = b`, `field_30 = a`, `field_34 = 0`, `field_14 = 0`
- `field_10 = fn_80058498(field_20, field_24, field_28)` — returns a pointer (its `r3`
  result is stored), despite the symbol table declaring it `void`

The body is saved at `.fzgx/attempts/fn_8004CD70.v4.c` for continuation.

Two general lessons from the iterations:

1. **A struct of `u8 pad[]` fields silently degrades stores.** The first version used
   byte arrays for the slot fields and MWCC emitted `stb` where retail has `stw`,
   costing ~200 rows. Declaring the fields at their real width (`u32 field_20` etc.)
   took it from 23.3% to 25.8%.
2. **The residual is dominated by the frame size, not the logic.** Retail uses a 0x30
   frame with `stmw r27` (five callee-saved registers) because the *later* part of the
   function calls `fn_8004CAC8` six times plus `fn_8004B4E0`, `fn_8004EF28`,
   `fn_8005710C` and `fn_80042228`. Until those calls are written, our frame is 0x28
   with only `r31`/`r30`, so every offset after the prologue shifts. **Write the whole
   function before chasing per-row residuals** — a partial body cannot align the frame.

Only 79 of 271 aligned rows differ, and all of them are prologue/scheduling shifts
downstream of the unwritten tail.
