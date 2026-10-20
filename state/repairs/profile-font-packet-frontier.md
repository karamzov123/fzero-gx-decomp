# Profile font-packet frontier

Symbol: fn_16_4E90 (profile, 4,232 retail bytes). Compiler: GC/1.3.2,
existing flags and opt_propagation/opt_common_subs pragmas retained.
Status: unmatched, blocked. No authored-byte credit or source integration.

The saved raw-95.2% body refreshed to raw 96.024574%, but had 147 differing
instruction words / 30 shape edits. Raw objdiff percentages are not closure.

Measured alternatives against the current retail object, using the unified
fixup Engine and the same compiler profile:

| Source | Differing words | Shape edits |
| --- | ---: | ---: |
| Refreshed saved baseline | 147 | 30 |
| Restore propagation optimization | 288 | 40 |
| Restore CSE optimization | 256 | 21 |
| Restore both optimizations | 395 | 27 |
| Rectangle Y/X computations, flags before | 149 | 31 |
| Rectangle Y/X computations, flags after | 146 | 27 |
| Rectangle X/Y computations, flags before | 148 | 31 |
| Rectangle X/Y computations, flags after | 147 | 28 |
| FontDrawPacket fields, old selection carrier | 147 | 30 |
| Natural scalar selection only | 160 | 30 |
| FontDrawPacket fields and scalar selection | 160 | 30 |
| Typed/scalar frontier after bounded deterministic repair | 147 | 30 |

The retained frontier replaces the untyped 88-byte packet and PF offset casts
with the existing FontDrawPacket declaration and named fields. It removes the
artificial one-field selected-value carrier. These are source improvements,
not a semantic or matching claim. Two rounds of the existing repair engine,
beam two and at most twenty proposals per seed/round, recovered the baseline
word score without closing the function. No further repeated sweep was run.

The portable archive profile-font-packet-frontier.json.gz retains the source,
compiler settings, and word-scored frontier. Replay with:

    uv run tools/fzgx.py fixup --archive state/repairs/profile-font-packet-frontier.json.gz

Do not automatically prefer the historical raw-score best attempt: it still
contains the selection carrier. Investigate algorithmic helper boundaries,
float evaluation/value flow and the early rectangle/conversion schedule
before spending more generic allocation-search budget.
