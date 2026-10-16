# 347 — fn_1_1384C: the first-loop explicit-copy init (`boff = k`) is a selector/allocator fixed point, not a source shape

Session of 2026-10-16 (opencode/deepseek session, agent `deepseek-opencode`).
Follow-up to 346 (the shared-counter `mr` law) and 301/343/345 (the
materialise-vs-fold tie-break class). **The function stays unmatched
(not blocked); do not re-run the measured families below.**

## The residual, exactly (119 words, differing word index [22])

Retail and our saved best body (`.fzgx/attempts/fn_1_1384C.1791783071.c`,
ledger best 99.4958% attempt 32; word-scored 99.160 / 118 of 119 words) agree
on every word except the unrolled per-tab-iteration loop header:

    w20 beq  .L_continue                 | same
    w21 li   r30, 0                      | same        (k = 0)
    w22 mr   r27, r30   <- residual      | li r27, 0   (boff = k)
    w23 b    .L_k_test                   | same

`k` is the k-loop counter (fresh: used only in this loop), `boff` the explicit
byte-offset local (`boff += 8` in the loop increment; the name access is
`(u8 *)unk_8 + boff + 4`). We cannot reuse the 346 fix (`v6`-style counter
sharing) here: the k-loop is nested inside the tab/j/i loops, so every earlier
counter is an enclosing loop's counter and sharing would clobber it; k has no
sibling loop.

## Measured levers (all offline probes, sweeps 25–31 and earlier; no checks spent)

| lever | result |
|---|---|
| baseline `for (k = 0, boff = k; ...)` | 1 [22] `li r27, 0` |
| separate statements / nested `boff = k = 0` / casts `(u32)k`, `(s32)k` | 1 — all fold |
| label join, `if (0) goto L;`, empty `if (k) {}`, dead `isMV = 0` between | 1 — fold survives CFG joins |
| `boff = k * 8` / `k << 3` / `8 * k` / `(u32)k * 8` | 1 [22] — ours is `slwi r27, r30, 3` (multiply is *not* constant-folded, yet not `mr` either) |
| drop `boff`, multiply-addressed name access (`base + k * 8 + 4`) | 22 diffs — `boff`'s vreg disappears, whole allocation shifts |
| pragma cells: `opt_propagation` (on/off/mid-function), `opt_lifetimes`, `opt_dead_assignments`, `opt_strength_reduction`, `opt_loop_invariants`, `opt_dead_code`, `opt_induction` (invalid) | 1 — no effect on w22 (`opt_propagation off` already present and load-bearing for 13 other words) |
| `peephole off` / `opt_common_subs off` / `scheduling off` / `global_optimizer off` | 109–102 diffs — unusable |
| declaration-order swaps around `k`/`boff` | 11–15 diffs — breaks the matching allocation |
| compiler versions GC/1.0 … GC/3.0a5.2 (all 20 available) | 1.3+ all fold at w22 (119 words, 1 diff); older versions emit a different structure entirely |
| `-O1` / `-O2` / `-O3` / `-O4` / `-O4,s` / `-O4,p` / `-O3,p` | `-O2` keeps the copy (`mr r28, r31`) but 79 diffs; `-O3` 18 diffs and folds; all `-O4` variants fold (1 diff) |
| `fn_1_A358C` "copy has its own lifetime" idiom (`s32 id = arg0;` under `opt_propagation off`) | not applicable: that copy's source is a *parameter* (no known constant, so no fold to block); our copy's source is the just-zeroed counter |

The multiply forms are the sharpest control: `boff = k * 8` shows the compiler
does **not** propagate the constant into arithmetic (`slwi` is emitted), while
`boff = k` is rewritten to `li r27, 0` — the fold is copy-specific, survives
every pragma axis, and is decided downstream of source text.

## Corpus context (35 true retail `li rX, 0; mr rY, rX` init pairs, all 2323 objects)

- Matched owners are all 346-law shadow cases (shared counters):
  `fn_1_1024F8` w56, `fn_1_41F58` w31, `fn_1_4270C` w204, `fn_1_42E74` w25/w51.
- `fn_1_152CB4` (asm, bg_aur) is the counterexample that shows retail's
  selector keeping a *first-loop* copy: w17 `li r30, 0; mr r26, r30` and
  w49 the same for a second loop, with a variable-stride accumulator
  (`add r26, r26, r8`). So the retail build does keep first-loop init copies —
  in our compile of fn_1_1384C the equivalent copy folds. Same class as
  finding 301 (`fn_12_2F970`: retail `mr r30, r31`, ours `li r30, 0`) and
  findings 343/345: the copy-vs-constant materialisation is a downstream
  decision (selector/allocator state), not reachable from source spelling.
- `fn_1_1384C` is the only unmatched function whose residual is exactly this
  first-loop init shape; the next-closest, `fn_1_17098` (w342/w357), has two
  such pairs and is untouched by this campaign.

## Stopping condition

Sweeps 25–31 (~50 measured shapes: init spellings, pragma cells, CFG joins,
declaration orders, flag/compiler sweep) produced zero closures and zero score
improvements over the saved best; the class is already documented as a wall
(301, 343, 345) and 346's shared-counter lever is unavailable in this
nesting. Saved best stays `.fzgx/attempts/fn_1_1384C.1791783071.c`; the
function remains `unmatched` and claimable (finding 345 precedent — no block).

If ever revisited, closure needs a tool that commits the materialise/fold
decision (`fixup --capture`-style allocator replay), a new pragma axis, or a
retail region-crossing match (finding 301's decisive input). Do not re-run the
families above.

## Method note (recreatable)

Offline probing used `/tmp/opencode/probe.py` and the sweep drivers
`/tmp/opencode/sweep25.py` … `sweep31.py` (+ `sweep_compilers.py`), all
`oracle.compile_source` + `oracle.word_score` against
`build/GFZE01/main_rel/obj/rel/main_rel/som/fn_1_1384C.o` with no ledger
checks. The retail `li;mr` scan is `/tmp/opencode/scan_li_mr3.py` (X-form
logical ops carry the destination in the A field, bits 16–20 — the field
order matters when decoding `or`/`mr`). The 346 law was re-verified offline on
the matched `fn_1_1024F8` (`/tmp/opencode/probe1024F8.py`: renaming loop 2's
counter flips only w57 `mr r29, r27` → `li r29, 0`).
