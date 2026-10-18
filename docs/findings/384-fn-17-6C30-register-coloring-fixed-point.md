# 384 - fn_17_6C30 register-coloring fixed point: two address webs swapped r3/r4

Symbol: `fn_17_6C30` (interview, 304 B, 76 words; hint "has stack frame"). Best
99.47369 (adjusted) / 92.11 raw. Released at attempt 13 (12 prior attempts + my
batches) after every reachable source shape produced byte-identical code.

## The residual, exactly

Rows 22-28 (retail | ours). Two independent webs are live at once: the
`lbl_17_bss_D8.object` address chain (3 instructions + value load) and the
`base + 0x2c34` kinds-pointer chain, consumed together by the final `lhax`.

```
22  lis  r4, lbl_17_bss_D8@ha   | lis  r3, lbl_17_bss_D8@ha
23  addi r3, r31, 0x2c34        | addi r4, r31, 0x2c34
24  addi r4, r4, lbl_17_bss_D8@l| addi r3, r3, lbl_17_bss_D8@l
25  lwz  r4, 0x0(r4)            | lwz  r3, 0x0(r3)
26  lwz  r0, 0x88(r4)           | lwz  r0, 0x88(r3)
27  slwi r0, r0, 1              | slwi r0, r0, 1
28  lhax r0, r3, r0             | lhax r0, r4, r0     <- kind = kinds[value]
```

Retail: D8 chain in r4, kinds chain in r3. Ours: the reverse. Emission order is
identical; only the two registers differ. The register-flow classifier marks
rows 22-26 as pure register-equivalence (same opcode, renamed operand) and row
28 as the `lhax` consuming the renamed base.

## What was measured (all byte-identical output, bad=[22,23,24,25,26,28])

| family | shapes |
| --- | --- |
| statement/initializer order | `kinds`/`kind`/`v`/`obj` in every order, incl. split assignment forms |
| scope/rank | `kinds`,`kind` declared in the block vs at the function top at all six declaration slots; `InterviewObject *obj` first/last |
| expression spelling | `kinds[value]`, commuted `value[kinds]`, `*(s16*)((u8*)kinds + value*2)`, cast chains, pointer+integer forms |
| engine sweeps | my run: 6061 candidates (rounds 3, beam 8, 3.3 s); the prior attempt's log: 14011 candidates on the same body - both best 99.47369 |
| optimizer pragmas | `opt_lifetimes`, `opt_dead_assignments`, `opt_common_subs`, `opt_strength_reduction`, `opt_induction`, `opt_loop_invariants`, `opt_common_subexpressions`, `opt_unroll_loops`, `peephole`, `scheduling`, `opt_propagation` (each off, and all off): flat or catastrophic |
| compiler version | GC/1.3, 1.3.2, 1.3.2r, 2.0, 2.0p1, 2.5, 2.6, 2.7 all identical (92.1053, same six rows); GC/1.0-1.2.5 and 3.0ax are a different codegen era (74/71 bad rows) |

The front end normalizes every spelling to the same RTL, and the allocator's
numbering of the two webs is not observable from C: the second-created web
takes the lower scratch register under every reachable form. Note the identical
RTL is also reached with `-O4,p` through all pragma settings except the
catastrophic ones, so no local toggle re-ranks it.

## Wall

Same class as `fn_1_2A214` (finding 378): an allocator fixed point, not a
source shape. Do not re-run the source-shape search. Next evidence that would
move this:

1. an RTL/allocator capture of this row in the retail build, or
2. a matched twin where a first-materialized address web takes the higher
   scratch register against a later second web (would identify a spelling
   family not in the swept set).

Parked `unmatched`/claimable per project convention; `blocked` is for
unsupported credit.
