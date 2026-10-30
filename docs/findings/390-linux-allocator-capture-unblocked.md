# 390 — Allocator capture works on Linux; the walls measured from the real allocator

## What was missing

`mwgraph.capture` needs three components. This host had two:

| requirement | state |
| --- | --- |
| LLDB with embedded Python | present: `lldb 23.1.4`, embedded Python `/usr/bin/python3`. `mwgraph` already falls back from `xcrun lldb` to a bare `lldb`. |
| Wibo at `build/tools/wibo` | **absent**. Installed with the repo's own downloader: `python3 tools/download_tool.py wibo build/tools/wibo --tag 1.0.0` |
| the stock PE compiler under it | works: `build/tools/wibo build/compilers/GC/1.3.2/mwcceppc.exe` prints its banner and exits 0 |

The release Wibo matters: `wibo-x86_64` 1.0.0 is a statically linked ELF **with
debug info**, which is what the capture needs, because `mwgraph_lldb.run` breaks
on the loader by name (`loadPEFromSource`). A stripped build would not attach.

No Windows, Wine or macOS is involved. Nothing else was missing.

## Measured (2026-10-29, this host)

Six saved near-miss bodies captured at **0.51 s/function**, replay exact:

| symbol | passes | replay err | simplify err | target status | projections |
| --- | ---: | ---: | ---: | --- | ---: |
| `fn_12_3A64` | 2 | 0 | 0 | `fixed-graph-hypothesis` | 0 |
| `fn_80059DD8` | 1 | 0 | 0 | `needs-web-alignment` | 0 |
| `fn_80022BF4` | 1 | 0 | 0 | `needs-web-alignment` | 0 |
| `fn_800720B0` | 1 | 0 | 0 | `needs-web-alignment` | 0 |
| `fn_80072168` | 1 | 0 | 0 | `needs-web-alignment` | 0 |
| `fn_12_7870` | 1 | 0 | 0 | `needs-web-alignment` | 0 |

All six also report `same_code` and `same_object` true, i.e. the object rebuilt
under the debugger is the same object the oracle scores.

## `fn_12_3A64`: the mapping is retail's three-cycle, and it is not source-reachable

The capture's target mapping is exactly what the instruction diff predicted:

```
r29 -> r28    (table)
r28 -> r27    (object)
r27 -> r29    (far_z)
```

with two baseline selection-order witnesses. So the interference graph is
unchanged (`fixed-graph-hypothesis`), the allocator *can* produce retail's
colouring under a different selection order, and the three values rotate as the
20-row residual showed. `mwconstraints.declaration_projection` still yields **no**
source candidate, and the capture-projected engine run
(`fixup --corpus /tmp/capcorpus --captures /tmp/capout --rounds 3 --beam 5`)
produced 853 candidates with **0 matches**, best 99.5327 with 1 word error — the
already-saved `s8` + `return far_z` body.

That is the independent confirmation of `REGISTER_REPAIR.md`'s "zero declaration
projections pass the graph prediction", now measured on this host against the
real allocator rather than inferred: reordering movable named locals cannot move
a parameter or a generated `@` web's rank, which is where this residual lives.

## The other five are web alignment, not ordering

`needs-web-alignment` means our interference graph is not retail's, so there is
no selection order to search for — the source must first produce a different web
set. That is the PCode value-web/source-origin work named in
`REGISTER_REPAIR.md`, not an allocator tie to be re-swept. Recording it here so
these five are not dispatched to more spelling searches.

## Regional ISOs do not help either

Finding 302 already extracted US/EU/JP and measured `movie_module.rel` `.text`
byte-identical across all three regions, with DOL differences being data
immediates only. Since all three builds use the same compiler on the same source,
there is no region-crossing match to read the responsible construct off. The
extracted ISOs add nothing to this class; the capture above is the evidence path
that does work.

## Corpus papercut fixed

`mwgraph.capture` read `inputs[symbol]['target']` for the retail object, so a
hand-built corpus without that key died with `KeyError: 'target'` *after* the
compiler run had already been paid for. It now falls back to
`project.target_object_for`, and raises a named error only when the symbol
genuinely has no retail target. Validated by stripping `target` from the
six-record corpus and replaying: 0 errors and the same statuses as the table
above.
