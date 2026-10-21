# Parallel manual matching

N sessions match by hand at once, each on a disjoint slice of the frontier, and one
terminal links and commits. Launch:

1. Verifier terminal (the only process that links, verifies and commits):

       uv run tools/fzgx.py verify --watch --interval 120

2. N agent sessions in the repo root, each given the prompt below with `K` replaced by
   0, 1, ..., N-1 and `N` by the session count.

`tools/manual.py queue --shard K/N` assigns a function to shard `crc32(symbol) % N`, so slices
never overlap; `fzgx claim` is atomic besides. Release reasons are stored in the ledger and shown
in the queue's "last note" column, so the next session starts from what was ruled out.

## Prompt

```text
You are manual matcher K of N on the F-Zero GX matching decompilation in
/home/armandofm/projects/fzgx. Your agent id is manual-K. Goal: as many functions as possible
matched byte-for-byte with natural C and accepted by `fzgx submit`. Work alone: no subagents,
no fleet or orchestrator runs.

Read CLAUDE.md once. Most of it is tooling history; what you need is the "Measured dead ends"
list and the measured compiler laws (allocation rules, the MWCC register allocator, retail TU
section layout, shared literal pools, paired-single kernels). Read nothing else up front.

YOUR SLICE
- `uv run tools/manual.py queue --shard K/N` lists your functions, nearest first
  (`--by bytes` ranks by size x closeness). Never work outside your shard.
- Skip a function whose last note names a measured or structural cause unless you have a
  concrete new idea about that cause.

LOOP, one function at a time
1. `uv run tools/fzgx.py claim SYM --agent manual-K --max-attempts 999 --ttl 7200 --check`
   installs the best saved body as your work copy (.fzgx/work/SYM.c) and shows the diff.
   If the claim fails, take the next function.
2. `uv run tools/fzgx.py context SYM`: retail assembly, compiler, flags and prior attempts.
   Read retail assembly only from there (orphaned .s files under build/ can be stale).
3. Diagnose from the differing rows which C shape produces retail's instructions. Measure
   progress in differing rows/words, never in %.
4. Write several hypotheses at once, one complete file per idea, in /tmp/fzgx-manual-K/SYM/,
   then run `uv run tools/manual.py try SYM /tmp/fzgx-manual-K/SYM -v`
   (`--mw GC/1.2.5n` etc. probes another compiler). Batches of 3-8 variants beat single edits.
5. Put the best into the work copy:
   `uv run tools/fzgx.py write-unit SYM --agent manual-K --file F`, then
   `uv run tools/fzgx.py check SYM`. When only register/order rows remain, run
   `uv run tools/fzgx.py search SYM --agent manual-K` once (deterministic engine, about a minute).
6. At 100% (or a pool match): `uv run tools/fzgx.py submit SYM --agent manual-K
   --message "<what fixed it>"`, adding --mw-version/--extra-cflags if you changed the
   compiler. If check reports a PROLOGUE CONFLICT, align the named declaration with the TU's
   prologue first. After a successful submit, go straight to the next function.
7. Time box: about 40 minutes, or three variant batches in a row with no fewer differing
   rows. Then `uv run tools/fzgx.py release SYM --agent manual-K --reason "<what you ruled
   out; the exact remaining difference>"`. That reason is what the next session reads: make
   it specific and factual. Move on.

ACCEPTANCE RULES (submit enforces most of them)
- Natural C only: no inline asm, no hardcoded addresses (use symbols), no `fzgx-allow`
  comments, no allocator scaffolding (lab_pad, dummy fields or locals that exist only to steer
  registers). `volatile` and `goto` only with a truthful one-line justification.
- Edit only your own work copy, through write-unit or patch-unit. Never edit headers
  (include/**), symbols.txt, splits.txt or units.json. A local view struct inside your unit is
  fine when a generated header types a field differently from how the function uses it.
- Never run configure.py, ninja, dtk, `fzgx verify`, or any git command: the verifier
  terminal links, checks all 16 hashes and commits. Never touch another agent's claim or work
  copy. Do not edit CLAUDE.md; findings go in release reasons.

When your shard's top 30 are all matched, released or skipped, stop and print a table:
symbol | outcome | rows left | one-line reason.
```
