# 379 — fn_12_3A64 void tail and fn_12_27884 allocator mirror

Session of 2026-10-23. Two near-misses narrowed to a single class each, with the
remaining difference measured rather than guessed. Neither was closed; the
hypotheses at the end are the useful part.

## fn_12_3A64 (movie_module, 852 B / 0x354, 213 words, saved body at 99.25%)

The only row is an **extra** instruction on our side, at the function tail:

    retail 33c: bdnz 2a8        ; last iteration of the inlined MakeCnvZTbl loop
           340: lmw r26,72(r1)  ; epilogue, r3 never written
    ours   340: mr r3, r29      ; extra: return-value materialisation

Saved body ends with `s8 fn_12_3A64(...) { ... return (u32)far_z; }`. The
caller in `rel/movie_module/fn_12_A5C.c` declares the symbol `extern void
fn_12_3A64(s32, s32, s32)` and discards the result, and retail writes r3
nowhere after the loop, so the function is `void` in reality.

Measured (module default compiler, relocation-aware oracle):

| body | insns | rows |
|---|---|---|
| `s8` + `return (u32)far_z;` (saved) | 214 | 1 (`ins`) |
| `u32` + `return far_z;` | 214 | 1 (`ins`, the same `mr r3,r29`) |
| `void` + no return | 213 | 20 |
| `void` + `return;`/no return, swappable | 213 | 20 |
| `void` + `(void)far_z;` before `}` | 213 | 20 (statement dead-eliminated) |
| `u32`/`s8` + no return statement | 213 | 51 |
| `void` with parameters declared `(object, table, index)` | 213 | 23 |

The with-return body reproduces retail's callee-saved panel exactly
(`r26` index, `r27` object, `r28` table, `r29` far_z) and differs only by the
final `mr`. Every genuinely-`void` body drops one callee-saved slot, so
`far_z` stops being long-lived and the panel rotates one register.

That is the contradiction worth chasing: retail has `void` semantics (no r3
write, void caller) **and** the panel of a body whose result escapes. So in
retail something keeps `far_z` live to the epilogue that emits no instruction.
Note the inlined `sfxzmv_MakeCnvZTbl` chain ends with a loop that writes only
through `r5`/`r30`, i.e. if `far_z` were in a volatile register it could be
returned for free — but every inlined use of `far_z` in our body matched retail
in `r29`.

Hypotheses for the next session:

- the true tail is `sfxzmv_MakeCnvZTbl(...)` followed by a use MWCC removes
  *after* allocation (a `(void)` cast is removed before it — measured above);
- or the helper chain's last call takes `far_z` by a form that keeps the web
  alive past the inlined block (e.g. an inlined wrapper returning it);
- or the function returns the *inlined helper's* value under a `void`
  prototype, which MWCC accepts and emits nothing for — worth one probe with
  the `void *f(void)` inlined into a return position.

## fn_12_27884 (movie_module, 980 B / 0x3D4, 245 words, saved body at 99.86%)

Seven rows, all `regalloc`, all in one mirrored pair:

    retail 1a0: li r0,0 ; lwz r3,0x74(r31) ; cmpwi r3,4 ...
    ours   1a0: li r3,0 ; lwz r0,0x74(r31) ; cmpwi r0,4 ...

`result` (the inlined `check_state` accumulator) takes `r3` in every body we
can write, and the switch selector takes the other slot; retail has them
swapped, so `result` sits in `r0` for its whole live range.

The switch *tree* was confirmed correct first, and that mattered: retail pivots
on 4 and then 2, which only happens when case 4 has a body
(`case 4: result = 0;`) and case 5 is a separate label. Folding either into
`default:` makes MWCC select a 3-case tree that pivots on 3 — a 246-word
function instead of 247. See the idiom entry added to `docs/MWCC_IDIOMS.md`.

Probed with no effect on the allocation (all 247 words, identical rows):
`result`/`state` declaration order, declare-then-assign, `u32` result,
`register` keyword, inner block around `state`, `switch ((u32)load)`,
`switch (*(int *)((u8 *)work + 0x74))`, dropping the `work` local, and the four
saved attempts in `.fzgx/attempts/fn_12_27884.*.c`.

Hypothesis: `r0` is where MWCC puts a value it treats as a *temporary* rather
than a named local, so retail's accumulator is probably the inlined return
value itself (the caller folds `if (check_state(...))`), not a local of the
helper. A body whose helper has no accumulator local — one that returns from
each case through a shared expression — is the next thing to try; the
`case 4`/`case 5` pivot above pins the tree, so any such body must keep four
distinct case labels.
