# 378 — fn_1_2A214 parked: retail's descending float-home order is an allocator fixed point, not a source shape

Session of 2026-10-17 (opencode/deepseek, agent `deepseek-opencode`). Parks
`fn_1_2A214` (main_rel/stcoli, 36 words / 144 B, 14 attempts, best **99.1667%**)
at a measured allocator fixed point: the installed body is 5 identical-word
rows short (0-based rows **6–10** of 36), and no source shape in a ~400-variant
sweep reaches the retail coloring. **Do not re-run the source-shape search** —
the measured reachable set and the dead-lever list below are the record.
Left `unmatched`/claimable per project convention (`fn_1_2D038` /
`fn_1_135D7C` precedent); `blocked` is for unsupported credit.

## The residual, exactly

Installed body: `.fzgx/work/many/main_rel/fn_1_2A214.c` (the plateau body; same
coloring is reached with plain direct expressions, so the block's
`fn_1_2A214_scale`/`read_pointer` helpers + `opt_strength_reduction off` are not
what pins it). Word diff (retail | ours), reproduced by
`/tmp/opencode/a214_base.py` and `/tmp/opencode/a214_show.py`:

```
   6  lfs f1, 0x1d0(r4)   | lfs f0, 0x1d0(r4)
   7  lfs f0, 0x174(r4)   | lfs f1, 0x174(r4)
   8  fmuls f1, f2, f1    | fmuls f0, f2, f0
   9  stfs f1, 0xa0(r3)   | stfs f0, 0xa0(r3)
  10  lfs f1, 0xa8(r3)    | lfs f0, 0xa8(r3)
```

Words 0–5 and 11–35 are byte-identical. Write the tuple of float homes as
**(V, F, F2)** = (0xa0-load, 0x1d0-load, 0x174-load):

- **retail target: (f2, f1, f0)**, with the a8 reload (w10) landing in f1 and
  `limit` (0xb0, w13) in f2 — i.e. every fresh float def takes the *highest
  free* register, descending f2 → f1 → f0 in load order.
- **plateau (ours): (f2, f0, f1)**, a8 reload in f0.

Trap: rows 11–12 match *despite* the swapped roles. Retail has f1=a8, f0=F2
and emits `fmuls f0, f1, f0` = F2·a8; ours has f0=a8, f1=F2 and emits the
identical word (0xEC010032) because the product commutes. A matching row does
not mean a matching coloring — read the whole window, not the diff.

## The measured reachable set (probe9: all 24 decl perms of [factor, factor2, value, limit], `#pragma opt_propagation off`)

`/tmp/opencode/a214_probe9.py` (re-run 2026-10-17, output below is the live
reproduction; `word_score` here is exact-word fraction):

| (V,F,F2) | differing rows | identical words | count of perms |
|---|---|---|---|
| (f2,f0,f1) | [6,7,8,9,10] | 31/36 | 8 |
| (f0,f2,f1) | [5,6,7,8,9,10] | 30/36 | 8 |
| (f0,f1,f2) | [5,7,8,9,10,11] | 30/36 | 4 |
| (f1,f0,f2) | [5,6,7,8,9,10,11] | 29/36 | 4 |

**Exactly 4 colorings exist, and the retail target (f2,f1,f0) is not among
them.** The a8 reload register is slaved to the coloring (f0 except in the
7-row family), and `limit` is always f2 — so the 5-row plateau is the closest
point of the reachable set. Declaration order only matters with the pragma: the
no-pragma body is the flat `(f1,f0,f2)` 7-row shape, reproduced by probe10's
`flat default` row (80.556%).

## Compiler sweep (`/tmp/opencode/a214_probe10.py`)

GC/1.2.5, 1.2.5n, 1.3, 1.3.2, 2.0, 2.5 → **byte-identical 5-row plateau**.
GC/3.0a5.2 → 38.889% (22 rows). The plateau is not a 1.3.2 artifact.

## Sibling witnesses: the allocator CAN emit the retail coloring

Two matched (100%) siblings emit retail's descending home order *and the exact
missing row* `fmuls f1, f2, f1` (0xEC220072), scanned by
`/tmp/opencode/a214_sib.py`:

- `fn_1_879B0` (car.c, matched `d49833d`) w17–21:
  `lfs f2, …; lfs f1, …; lfs f0, …; fmuls f1,f2,f1; fmuls f0,f1,f0`.
- `fn_1_156D9C` (ranking.c, matched `90a543af`) w11–14 and w33–36: same
  f2 → f1 → f0 load order into a `fmuls f1,f2,f1`.

So the descending-f2/f1/f0 home order is a stock-processor behavior that this
function's RTL never triggers: our allocator refuses to put the *second* fresh
def (0x1d0) in f1 while the *first* (0xa0) still lives in f2 and the third
(0x174) is still to come. Contrast is RTL-internal (interleaving with the
`stfs` between rows 9–10), not a source spelling.

## Dead levers (measured; do not repeat)

~400 offline variants (`oracle.compile_source` + `oracle.words` +
`oracle.word_score`, no ledger checks): flat / brace-value / cluster-init /
cluster-noinit shape families; all 24 decl orders of [factor, factor2, value,
limit]; pragma cells (`opt_propagation`, `opt_strength_reduction`,
`opt_lifetimes`, `opt_common_subs` on/off combinations); casts; held products
(`value * factor` into a local before store); dummy locals; inline helpers
(scale/read-pointer forms); named a8-load local; a8 L/R operand order; mul1
operand flip (`factor * value`, same 5-row plateau); `data[i]` vs `(i)[data]`;
compound assignments (`*=`) and no-value forms; factor2-inline shapes (the load
is then scheduled *after* the intervening `stfs` — the processor does not hoist
it across the store, which changes the window instead of the homes); compilers
GC/1.2.5 → 2.5 (above). All of it collapses to the 4-color table.

## Conclusion and future lever

`fn_1_2A214` is at the **selection/allocation fixed point of the stock 1.x
processor for this RTL**. The remaining lever is the *capture/constraint
pipeline* class of fix (finding 361's need): capture the retail allocation
(`fzgx fixup fn_1_2A214 --capture`), add the missing selection-order support to
`mwconstraints` if the capture exposes it, and project the retail coloring the
way `fixup --captures` projects PCode constraints — a source-search return is
only warranted after that pipeline can express "descending home for the second
fresh def". Until then, this row stays off the fixup fleet's reachable list.

Files: installed plateau body `.fzgx/work/many/main_rel/fn_1_2A214.c`
(unchanged); probes `/tmp/opencode/a214_probe9.py` (24-perm decl sweep),
`/tmp/opencode/a214_probe10.py` (compiler sweep + flat control),
`/tmp/opencode/a214_sib.py` (sibling scan), `/tmp/opencode/a214_show.py`
(full row diff), context `/tmp/opencode/ctx_2A214.md`.
