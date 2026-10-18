# 386 - fn_17_3E08 base-materialization wall: retail re-materializes lbl_17_bss_D8 for the third case-2 node

Symbol: `fn_17_3E08` (interview, 868 B; retail 217 words, best ours 215 words).
Best 99.0553 (two independent fleet bodies, see below). Released `unmatched`
after every reachable source shape produced byte-identical code. No claim was
taken by this pass; the claim gate reports attempt cap (6 ledger attempts).

## The residual, exactly

Rows 84-86 (0-based instruction rows; retail | ours):

```
84  lis  r3, lbl_17_bss_D8@ha   |  (nothing - row 7 already holds r31 = &lbl_17_bss_D8)
85  addi r3, r3, lbl_17_bss_D8@l|  (nothing)
86  lwz  r27, 0xc(r3)           |  lwz r27, 0xc(r31)
```

Retail 217 words, ours 215. The complete object-level relocation tables differ
only in this pair of HA/LO entries (`lbl_17_bss_D8 + 0`); every other word,
including branch targets and the `.unk_0` refresh chains, is identical. Aligned
screen: `matched=208 len=215 aligned=95.8525`.

Context of the difference (case 2 of the dispatch, three nodes):

- `r31 = &lbl_17_bss_D8` is materialized once at row 7 (`addi r31, r3, @l`) and
  kept live to row 146; `r29` is the walker (`r29 = r31`, stepped +4/iter).
- The two slot-2 node loads, rows 54 and 146, are `lwz r27, 8(r31)` in **both**
  compilations.
- Every `.unk_0` access fresh-materializes (`lis`+`addi`+`lwz`, rows 27-33 etc.)
  in **both** compilations.
- Only the third case-2 node load (row 84, slot `+0xC`) splits: retail
  re-materializes, ours reuses the kept copy.

## What was measured (all byte-identical 215-word output unless noted)

| family | shapes |
| --- | --- |
| expression spelling | p1-p7, including `((T *)&lbl_17_bss_D8)[3]`, `*(T **)((u8 *)&lbl_17_bss_D8 + 0xC)`, typed/untyped casts, commuted address algebra |
| view aliasing | `u32[8]` word view (w1); `u8[34]` byte view with decay (y2, y2b, y2c); struct member vs slot-array spelling |
| local carriers | pointer locals for the slot (x3, x4); the variant that also shadows the walker broke to 203 words (x5) |
| expansion shape | inline expansions i1-i6; z-first body order diverged (95.39) |
| declaration order | 576 permutations (24 function-scope x 24 macro-scope) of the movable stratum |
| pragmas | micro-region z1-z7 (inert); whole-function `opt_propagation` / `opt_common_subs` / `opt_strength_reduction` / `opt_dead_assignments off` all diverge (49-77 aligned, none match) |
| qualifiers | `volatile` on the slot and the base (inert) |
| compiler version | GC/1.3 through 2.7 emit the identical 215 words |
| fixup engine | 2,983 candidates (prior pass) and the long final run (beam 12, 800 candidates/round, 5 rounds, 900 s, 177+ records): best remains the base body, no source-realizable improvement |

A block-scope redeclaration of `lbl_17_bss_D8` with a second type is not
expressible: MWCC rejects it (`identifier 'lbl_17_bss_D8' redeclared ...`), so
the "two views, two value numbers" theory has no C form in one unit.

Both fleet bodies at 99.0553 - `opencode/space-bunny-free`
(`.fzgx/attempts/fn_17_3E08.1791042150.c`, local `InterviewObj` typedefs) and
`coord-claude-1014b` (`.fzgx/attempts/fn_17_3E08.1792024000.c`, shared header
types) - are structurally quite different and compile to the identical 215
words, so the difference is not declaration style.

## Allocator-constraint evidence (2026-10-11 fleet capture)

`.fzgx/captures/` holds the 361-function stuck-corpus capture that includes this
symbol (job source `27e6552c...`). Its verdict:

```
fn_17_3E08  target_constraints.status = "instruction-shape"
            active_nodes = 131, baseline_order_witnesses = 2, mapping = null
```

`fixup_source.web_constraints` returns `instruction-shape` when the word-level
alignment has a length difference, and `fixup_source.declaration_candidates`
line 2285 early-returns `[]` for every status other than `web-hypothesis`. So
the capture-driven generator families (declaration orders, carriers, scoped
carriers) produce no candidates for this function by construction: the fleet's
own allocation tooling classifies the residual as an instruction-count/shape
difference, not a web/selection problem. For comparison, the same capture run
classified `fn_1_8CA70`/`fn_1_8CAF4` as `fixed-graph-hypothesis` with
`selection-witness` graphs - the case where those families do fire.

(The captures themselves are now stale: the header fingerprint rotated from
`2bdc463c...` to `ad0f67b6...`, so any future capture-driven run must recapture
first - but no recapture can change an `instruction-shape` classification while
the word counts differ.)

## Sibling evidence and wall class

Matched neighbours in the same module do emit exactly the retail shape:
`fn_17_6848` (line 1682) and `fn_17_69EC` (line 1765) materialize
`lbl_17_bss_D8` fresh (`lis`+`addi`+`lwz disp` for slots 0x8/0xC, sometimes
twice in adjacent statements), and `fn_17_416C` (line 1147) materializes
walkers directly - but none of them keeps a callee-saved symbol base across
calls. Our function does (`r31`, rows 7-146), and every access spelled against
that base then reuses it. The rematerialization is an allocator choice over a
value graph the front end builds identically for all reachable spellings.

Wall class: base materialization (findings 314/316/318) and allocator fixed
points (378/384). Do not re-run the source-shape search.

Next evidence that would move this:

1. a matched twin that keeps a loop-invariant symbol base in a callee-saved
   register across calls *and* rematerializes it for one later access (a
   spelling family not in the swept set), or
2. an allocator capture with length-difference alignment (the current capture
   path stops at `instruction-shape`).

Parked `unmatched`/claimable per project convention (`blocked` is for
unsupported credit); attempt count is 6 against the cap of 3, so any future
attempt needs `--max-attempts`. Bodies: `.fzgx/attempts/fn_17_3E08.1792024000.c`
(base), `/tmp/opencode/i3e08/base.c` (working copy), screened variants under
`/tmp/opencode/i3e08/`.
