# 376 — fn_12_2F970 landed: local-struct promotion needs a non-`s32` second member and the pre store before the counter init

Session of 2026-10-17 (opencode/deepseek, agent `deepseek-opencode`). Closes the
99.833336% / one-word plateau of `fn_12_2F970` (movie_module, 30 words, attempt
22): retail word 7 (byte 0x1C) is `mr r30,r31` (counter = copy of the
just-zeroed register); ours emitted `li r30,0`, the frontend fold of finding
371. Landed commit `e1788001` (`claim --max-attempts 50`, write-unit auto-check
100.0% MATCH, verify fast path 10.8 s; gate: ninja 0, dtk shasum 16 files OK,
lint 0, unittest 11 OK; ledger 5833/7308 matched, +1). Extends finding 371:
member copies of a local struct survive, but only if the struct is promoted at
all and the members are initialised in the right order.

## The landed shape

    typedef struct Fn122F970Loop { u32 zero; int index; } Fn122F970Loop;
    ...
    Fn122F970Loop s;
    s.zero = 0;
    p->pre = s.zero;      /* pre store must precede the counter init */
    s.index = s.zero;     /* -> li r31,0; mr r30,r31 (words 6/7) */
    do {
        fzgx_live = p->copy.a; fzgx_live[k] = s.zero;   /* k = 0..3 */
        fn_12_2269C((u8 *)arg0, v, s.index, &p->copy);
        s.index++;
        p = (struct MovieSlot *)((u8 *)p + 0x10);
    } while (s.index < 3);

`#pragma opt_loop_invariants off` and the unit's `-use_lmw_stmw on` are both
required: without the pragma the whole allocation shifts (p→r28, v→r30,
i→r29, `li r29`); without `-use_lmw_stmw` the prologue form changes.

## Type rule: a `long` second member pins the struct to the stack

`include/types.h` defines `s32` as `signed long` and `u32` as
`unsigned long`. Probe `typeprom.c` (same GC/1.3.2 flags, compiled via
`oracle.compile_source`) shows MWCC 1.3.2 promotes the two-member local struct
into registers for `{int,int}`, `{u32,u32}`, `{unsigned int,unsigned int}`,
`{s32,u32}`, `{int,u32}` — each emits the `li r30,0; mr r31,r30` copy — but
`{u32,s32}` and `{s32,s32}` stay on the stack (`stw r31,8(r1)`,
`lwz r3,0xc(r1)`; 28 words, no copy). The whole earlier `u1`–`u6` family used
`struct { u32 z; s32 i; }`, so every spelling folded to `li r30,0` for a
reason unrelated to the loop: the counter web was never in a register.

## Counter member must be `int`, and the pre store must come first

Sweep B (`sweep_b.c`, 280 full-function variants in one TU, ~0.1 s per 100
functions; map `sweep_b_map.json`) crossed 8 member-type pairs × 7 init orders
× 5 loop-store carriers. Exactly 18 variants hit 30/30 words, zero diffs: all
have second member `int`, first member ∈ {`u32`,`int`,`unsigned int`}, the
pre store written before the counter init, and the `fzgx_live` carrier with
either `s.zero` or literal `0`. Measured failures:

- `{u32,u32}` promotes, but `s.i < 3` becomes `cmplwi` (word 22) → 29/30.
- Counter init before the pre store (`s.index = s.zero;` then
  `p->pre = s.zero;`) demotes the struct to the stack entirely: 33 words,
  0x30 frame, `stmw r24` prologue.
- The `direct` (`p->copy.a[k] =`) and `chain` store carriers never hit; the
  four separate `fzgx_live[k]` stores are the matching spelling.

## Corpus corroboration

Adjacent `li rD,0; mr rA,rD` pairs (raw words, `addi rD,r0,0` required, so a
relocated `addi rD,rX,0` strength-reduced offset copy is excluded — masking
relocation fields makes it look like `li`):

- carved corpus `build/GFZE01/*/obj/rel/**/fn_*.o` (3,959 objects): 31 pairs
  in 20 objects; 10 of those are landed matches, including the target
  (`fn_1_E34`, `fn_1_10D2F0`, `fn_1_5370`, `fn_1_1024F8`, `fn_1_3DB9C`,
  `fn_1_41F58`, `fn_1_4270C`, `fn_1_42AD0`, `fn_1_42E74`, `fn_12_2F970`).
- retail `auto_*.o` corpus (1,215 objects): 100 pairs in 59 objects.
- witness reading: landed `fn_1_4270C` (finding 346) keeps its offset
  accumulator in a one-member struct (`struct { u32 value; } v31;
  v31.value = 0;`) and emits `li r29,0; mr r30,r29` at its word 0x330 before
  the accumulator loop — the same member-copy device. `fn_1_3DB9C` passes the
  copy to the callee every iteration (`li r29,0; mr r3,r29; bl; addi
  r29,r29,1; cmpwi r29,4; blt`), the same relationship as our `mr r5,r30`
  before `bl fn_12_2269C`.

Earlier scans of the same idiom reported 95 rows (`/tmp/opencode/limr_scan.txt`)
and were re-run at landing time; the numbers above are the fresh counts.

## Notes

- Finding 375's primer guard is not exercised: the landed source has no pool
  or `.fzgxpool` sections.
- The prior best body `.fzgx/attempts/fn_12_2F970.best.c` (29 words) is
  superseded; the sweep generator is `/tmp/opencode/tri970/gen_sweep_b.py`.
- Attempt accounting is unchanged: attempt 22 of the claim, best 100.0% after
  the write, no pool/adjustment credit involved.

Files: landed body `src/rel/movie_module/fn_12_2F970.c` (commit `e1788001`);
type probe `/tmp/opencode/tri970/typeprom.c`; sweep
`/tmp/opencode/tri970/sweep_b.c` + `sweep_b_map.json`; winning standalone
reproduction `/tmp/opencode/tri970/final.c`.
