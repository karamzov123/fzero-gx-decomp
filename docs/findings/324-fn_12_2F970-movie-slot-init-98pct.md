# fn_12_2F970 (movie_module): movie slot init, 98.0% with 1-row regalloc residual

Selected a carved-but-never-written unit (120 B, `movie_module/rel/movie_module`). A prior session
reached 99.8% (8 rows) and then regressed. No claims remained; no fleet settings were changed and no
canonical gameplay source was submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

Initializes 3 movie slots. For each slot:
1. Zeroes a 16-byte structure (4 u32 fields)
2. Calls `fn_12_2269C(arg0, value, i, &slot->copy)` to process it
3. Advances to the next slot (0x10 bytes apart)

Also stores the slot array pointer at `arg0->slots` and reads `arg0->value` once.

## Residual: 1 row, register allocation

The body reaches **98.0% raw** with exactly 1 differing row:

    mr r30, r31  |  li r30, 0x0

Retail initializes the loop counter `i` (r30) by copying from r31 (which already holds 0 from the
`li r31, 0x0` used for the zero stores). Our code generates a separate `li r30, 0x0`.

Probed approaches that did not close the gap:
- `s32 zero = 0; i = zero;` — compiler still emits `li r30, 0x0`
- `i = p->pre;` (read back from the zeroed field) — generates a load, regresses to 89.3%
- `i = *(s32 *)&p->pre;` — same, regresses to 89.3%

This is a register allocation artifact: the compiler keeps `0` in r31 and copies it to r30 in retail,
but our formulation causes it to materialize `0` separately. The `fzgx_live` pointer pattern for the
zero stores is what forces the `stmw`/`lmw` register save pattern.

The body is at `.fzgx/attempts/fn_12_2F970.best.c`
(SHA-256 `ef581711334f1d3d...`, full hash in `.fzgx/attempts/fn_12_2F970.best.json`), 98.0% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_12_2F970.best.c`, compiler GC/1.3.2 with
`-use_lmw_stmw on`, no extra command-line flags. Next step: find a C formulation where `i` is
initialized from the same SSA value as the zero stores (e.g., a ternary or comma expression that
ties them together).
