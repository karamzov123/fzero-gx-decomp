# 383 - fn_1_1384C zero-init copy wall: `li`+`mr` is an induction re-init artifact

Symbol: `fn_1_1384C` (main_rel, 476 B, 119 words). Best: 99.4958 raw / 99.16
adjusted, one differing row. Released at attempt 33 after ~40 measured probes.

## The residual

```
row 21  li r30, 0x0        li r30, 0x0        k = 0
row 22  mr r27, r30        li r27, 0x0        boff = k      <- the whole wall
row 23  b .L_0001393C      b .L_0001393C
```

Retail keeps `boff`'s initialization as a register copy of the freshly-zeroed
index register. Every C spelling we can construct folds it to an independent
constant materialization (`li r27, 0`) or to a shift (`slwi r27, r30, 3`).

## Probe families (all compile + positional word check against the target object)

| family | spelling | result |
| --- | --- | --- |
| variable copy | `boff = k` (frontier), `(u32)k`, `(s32)k`, `+k`, `(k)` | bad=[22], emits `li r27, 0` |
| literal | `boff = 0` | bad=[22] |
| identity arithmetic | `k - 0`, `k + 0`, `k >> 0`, `k \| k`, `k * 8`, `k << 3` | bad=[22]; the `*8`/`<<3` forms emit `slwi r27, r30, 3` |
| chained assignment | `boff = (k = 0)`, `boff = k = 0`, `k = boff = 0`, `boff = (k)`-comma forms | bad=[22] (chained), order-swapped pair 21/22 for `k = boff = 0` |
| statement split | `k = 0;` `boff = k;` | bad=[22] |
| statement zeros | `k = 0;` `boff = 0;` | bad=[22] |
| pointer conversion | `u8 *boff; boff = (u8 *)k;` | bad=[22] |
| decl initializers (top) | `s32 k = 0; u32 boff = 0/k;` | emitted at the top, 110 bad rows - no sinking for a loop-nested first use |
| inner block decl-init | `{ s32 k = 0; u32 boff = 0; ... }` | renumbers every local (73.9%, 31 bad rows) |
| C99 for-init decls | `for (s32 k = 0, boff = 0; ...)` | does not compile (C89 front end) |
| pass pragmas | `peephole`, `opt_propagation`, `opt_common_subs`, `opt_strength_reduction`, `opt_loop_invariants`, `opt_common_subexpressions`, `opt_unroll_loops`, `scheduling` (each off; all five off; none at all) | no configuration emits `mr` at row 22 |
| opaque zero init | `k = (s32)(f32)0.0f`, `(s32)0.0`, `(s32)(f64)0.0` | front end folds through them; bad=[22] |

## Why nothing reaches it: the twin evidence

A word-scan of the retail objects for the consecutive pair `li rX, 0` +
`mr rY, rX` finds it in 113 objects. The matched twins and their source sites:

| twin | site | source spelling |
| --- | --- | --- |
| `fn_1_5370` (camera) | decl inits `u32 num = 0; u32 flag = 0;` sunk to the switch dispatch (their only use) | second decl initializer reuses the first materialized zero |
| `fn_1_41F58` (motasglist) | second `for (i = 0; i < data->second_count; i++)` of two identical loops | offset induction `i * 0x10` re-init folds to a copy of the zeroed index |
| `fn_1_1024F8` (cloth) | second `for (i = 0; i < p->unk_1C; i++)` after the `if (obj->unk_4 & 0x10)` block | offset induction `B = ARR + i*sizeof(Node)` re-init becomes `mr r29, r27` |
| `fn_1_10D2F0` (accessory) | one of the many re-initializations of `i`/`j`/`k` with `i + 1`-style scaled offsets | offset induction re-init |

Common shape: the `mr` is the **offset induction re-init** for the *second
static initialization of the same index variable* in the function. The loop
strength-reduction pass reuses the existing induction register and emits its
re-init as a copy of the index register (which was just set to 0), instead of
materializing a fresh constant. The same loop spelled first (fresh induction)
gets `li`.

`fn_1_1384C` initializes its `k`/`boff` pair exactly once (inside the tab loop,
re-executed dynamically but a single static init) and has no earlier
same-stride induction to reuse, so the first-init `li`+`li` shape is what the
compiler emits under every spelling above. The `mr` in retail is an artifact of
that code path, not of a C construct.

## Wall

Do not re-grind the init expression. Next evidence that would move this:

1. a matched twin with the copy form on a *first* (statically unique) init of a
   loop-nested index+offset pair, or
2. an allocator/RTL capture of this row in the retail build.

Both remaining pool-retarget rows stay behind the single instruction row.
