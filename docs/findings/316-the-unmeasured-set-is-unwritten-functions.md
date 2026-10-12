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
