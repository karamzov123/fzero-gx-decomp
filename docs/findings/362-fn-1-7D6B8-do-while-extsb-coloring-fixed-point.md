# 362 — fn_1_7D6B8: do-while loop-extsb coloring fixed point (5 rows)

Session of 2026-10-17. Recorded after ~19 offline probes (hand + 95 engine
variants, zero ledger checks) failed to shift the last five rows of
fn_1_7D6B8 (99.957924%, unit main_rel/rel/main_rel/car_test/fn_1_7D6B8,
compiler pinned mwcc_242_81 = GC/1.3.2 - module default matches the pin).

## The residual (713 words; differing rows 287, 290, 306, 307, 310)

    w287  extsb r7, r4        | extsb r5, r4      <- (s8)var_r4_2 hoist home
    w290  add r3, r0, r7      | add  r3, r0, r5   <- clamp-add consumes it
    w306  extsb r5, r4        | extsb r4, r4      <- (s8)category NO pitch vs pitch
    w307  slw  r5, r6, r5     | slw  r6, r6, r4   <- product absorbs count-reg vs base-reg
    w310  and. r0, r5, r0     | and. r0, r6, r0   <- test uses product home

## Structure (mapped to body lines 165-191, case-1 tail)

- `if (var_r4_2 != 0)` test = words 285-286 (extsb. r0, r4; beq bail),
  OUTSIDE the loop.
- The do-while loop body = words 288-311 (back edge = 311 `beq` -> word 288,
  the (s8 volatile) field_24 read; exit = 312 bl fn_1_816E8, 313 stb field_8,
  314 b). Every iteration re-clamps field_24 into {0..4} by +-1 and asks
  `(1 << (s8)field_24) & *(u8 *)(row + 908)` until the bit sticks.
- `extsb r7, r4` @287 = the LOOP-INVARIANT (s8)var_r4_2, hoisted into the
  pre-header; it is consumed by the add @290 EVERY iteration (loop-carried).
- `li r6, 1` @300 = temp_bit = 1, re-initialized inside the loop; `slw` @307
  = temp_bit << (s8)category; `and.` @310 tests the product.

## Coloring facts

- Retail consumes three fresh scratch slots downward [r7, r6, r5]:
  [hoisted, 1-init, count] and reuses r5 for the product (count-pitch).
  Ours consumes two [r5, r6] (archived: hoisted=r5, 1-init=r6) and PITCHES
  the count extsb into the dying category register r4.
- Neither panel pitches the 287-extsb despite the identical dying source r4 -
  the loop-carried web never pitches there.
- The archived body's prismas (opt_lifetimes/propagation/dead_assignments/
  pointer_analysis off) are load-bearing for the other 708 rows:
  removing opt_lifetimes = 116 rows, removing opt_propagation = 17 rows
  (it flips pitch polarity in the var_r6 block: rows 143-149),
  removing the other two leaves these five unchanged.

## Probed (all offline, mw = module default = pinned GC/1.3.2)

1. V1 merge `temp_bit = 1 << temp_r4_2;` - worse (18 rows, "1" restructured).
2. V2 direct `temp_r4_2 = *(s8 volatile *)&arg->field_24;` - same 5 rows.
3. V3/V4/V5 decl moves of temp_r4_2 / temp_bit - same 5 rows.
4. V6 statement reorder (base pointer before category reload) - worse (11).
5. V8 temp_r4_2 as s32 - same 5 rows.
6. V9/A-family explicit `var_r4_2_32 = var_r4_2;` + its use in the loop add:
   SHIFTS THE PANEL BY ONE SLOT - hoisted r5->r6, 1-init r6->r5, product
   becomes base-pitch (r5) and row 310 starts matching; still 5 rows
   (287 r6 vs r7, 300 li r5 vs r6, 306 pitch remains, 307 base vs count).
   Declaring the s32 first (V16) or at four other positions (A80/A88/A91/
   A94) all give the same shifted panel.
7. V22/V23/V24 two- and three-long +0 identity chains: fold to one web,
   same shifted panel. Chain length does not add slots.
8. Pragma single-removals (V12-V15): V12 116 rows, V13 17 rows, V14/V15
   unchanged.
9. Fixup engine, 95 variants in 2 rounds: matches = [], improved = 0.

## Hypotheses for the next session

- Retail's panel starts one slot higher than any ours-variant: the stock
  allocator's next-available pointer at word 287 differs, driven by web
  structure BEFORE the loop that is word-identical. The var_r6-block area
  (rows ~143-166) is the only tuned-volatile region that could hide it.
- A capture projection (`fixup --capture`) of THIS body may produce an
  order witness; fn_1_156C08's capture failed on a magic-row unsupported,
  this function has no float-magic chains so the port may succeed.
- If nothing else, the one-slot shift (V9/A-family) is a reusable lever
  for other loop-hoist residuals.

## Repro scripts (all under /tmp/opencode)

p7D6B8.py (baseline), v7D6B8.py (V1-V6), v7D6B8b.py (V8-V11),
v7D6B8c.py (V12-V16), v7D6B8d.py (V17-V20), v7D6B8e.py (A-family),
v7D6B8f.py (V22-V24). Archived body:
.fzgx/attempts/fn_1_7D6B8.1791776566.c
