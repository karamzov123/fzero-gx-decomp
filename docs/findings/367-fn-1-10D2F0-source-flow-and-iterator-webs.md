# fn_1_10D2F0: source-flow repair and iterator webs

Target: main_rel/accessory fn_1_10D2F0, 1252 bytes (313 instructions).
Accepted commit: 5d36419c. Compiler pin unchanged.

## Source diagnosis

The archived reconstruction contained a reversed null guard and a synthetic
return value, an incorrectly nested positive-side test, and a two-argument
allocation call missing the retail file symbol and line argument. Restore
`if (arg0 != 0) { ... }`, void return, the positive conjunction, and the
four-argument allocation call with lbl_1_data_40530 and line 0xDF0.

Remove stale dead-assignment/lifetime pragmas and their generated temporary
locals. Initialize compaction iterators from one shared base before either
scan; reloading/reconstructing the source base after the first scan retained
an extra move. Cleaned source reaches 313 aligned instructions with only
register differences.

## Measured source shapes

- Flow repair on inherited generated seed: 130 differing rows / 314 aligned.
- Clean source + common compaction base: 97 register rows / 313 aligned.
- Index-first loop initializers: 27 register rows.
- Separate first sorting pass's inner pointer: removes its mirrored homes.
- Reuse one explicitly reloaded zero for BOTH negative-side comparisons:
  removes the extra/mis-homed floating reload. A volatile expression only in
  the first test creates a different short-lived FP web; removing the reload
  entirely deletes a retail instruction. The accepted source documents why.
- Separate initial classification pass's pointer: seven residual register
  rows, all in the first category sort (outer pointer r25 vs retail r26,
  inner counter r26 vs retail r25).
- Indexed initial pointer: introduces reload/add instructions; cached base
  changes induction update order. Separate initial counter perturbs later
  loops. Further splitting each sorting outer pointer moves the residual to
  subsequent loops, then regresses globally. Stop at the five-check plateau.

## Deterministic closure

Use `fzgx release` rather than more manual declaration/permutation probes.
Its repair engine found an exact match in ~2.2 seconds with:

    stmt-swap: swap `Elem *p, *e, *a, *b, *c, *last`
               / `u32 i, j, k, pairs, q;`

The release auto-submitted the exact candidate. `fzgx verify` then accepted
fn_1_10D2F0, rejected nothing, and committed 5d36419c. This is a useful example
of source-level semantic/CFG repair followed by deterministic allocator
closure, not a reason to manually enumerate declaration permutations.

## Verification and coordination

- Project lint: 0 finding(s).
- dtk shasum against config/GFZE01/build.sha1: 16 files OK.
- Ledger readback: matched, link_state verified, no active claim.
- Main_rel authored: 2473 -> 2474; remaining: 757 -> 756.
- Whole-project remaining: 1481 -> 1480.
- User disclosed an independent OpenCode session in the same checkout.
  Sent synthetic steering notes through its live API without resuming or
  restarting it; reserved fn_1_10D2F0 and avoided its movie_module/main targets.
  Announced the shared verification window. No branch/tool/pin changes.
