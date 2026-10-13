# fn_1_A1DCC (sound): byte-cast volume pointer lifts 96.7% -> 98.9%; residual is the base-materialization wall

Selected a carved-but-never-written unit (1092 B, `main_rel/rel/main_rel/sound`). A prior session
reached 96.7% with 9 differing rows and plateaued after trying pointer helpers, `volatile`,
`opt_aliasing`, and index-increment forms. No claims remained; no fleet settings were changed and no
canonical gameplay source was submitted. Only `.fzgx` state and the unit body were touched.

## What improved it

The prior best wrote the second volume channel as `s->volume[1] = ...` (through a
`play_read_pointer` helper), which MWCC folds to a direct `sth r0, 0x886(r30)`. Changing the store
to a byte-cast pointer local

    s16 *volumes = (s16 *)((u8 *)s + 0x884);
    volumes[1] = ((s16 *)&lbl_1_data_2D93C)[(u8)track];

lifts the body to **98.9% raw** with 9 differing rows (down from the prior 96.7%). The body is at
`.fzgx/attempts/fn_1_A1DCC.best.c`
(SHA-256 `b0c48780289e3351...`, full hash recorded in `.fzgx/attempts/fn_1_A1DCC.best.json`).

## Residual: the base-materialization wall, 9 rows

All 9 rows are the same class. Retail materializes the volume-array base as its own `addi` and then
stores by displacement:

    000A1F88: addi r4, r3, lbl_1_data_2D93C@l   ; table base
    000A1F8C: lhax r0, r4, r0
    000A1F90: addi r3, r30, 0x884               ; &s->volume  <- materialized
    000A1F94: sth r0, 0x2(r3)                    ; volume[1] via r3

Ours folds the second store to `sth r0, 0x886(r30)`, eliminating the `addi r3, r30, 0x884` row.
The identical pattern appears twice (the `h == handles[0]` and `h == handles[1]` branches), which
is why the residual is 9 rows across two sites plus the shared table-base `addi` register swap
(`r4` vs `r3`).

Probed forms that all still fold (verified offline, no attempt budget spent beyond the one
confirming check):

- `s->volume[1]` (original)
- `play_read_pointer(s)` returning `owner->volume` (prior attempt)
- `(s16 *)((u8 *)s + 0x884)` byte-cast local, then `volumes[1]` (this attempt)
- `*(volumes + 1)` pointer arithmetic
- `++volumes; *volumes = ...`

This is the documented "base-register fold vs materialized pointer" wall
(`docs/REGISTER_REPAIR.md`, findings `314` and `316`). Retail's `addi r3, r30, 0x884` is an address
computation MWCC declines to emit as a separate value here. Reaching it needs a new transform, not a
source rewrite.

Not an exact C match. Resume `.fzgx/attempts/fn_1_A1DCC.best.c`, compiler GC/1.3.2, no extra
command-line flags.
