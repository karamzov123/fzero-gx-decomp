# fn_1_7D6B8: regalloc residual, and the admissibility of the saved best body

`fn_1_7D6B8` (main_rel, 2852 B, 713 instructions) is the highest-scoring
unmatched function in the project at 99.958% raw / 100.0% objdiff similarity.
Attempt 8 (hermes-manual, 2026-10-12) confirmed it is regalloc-blocked and
produced one durable, reusable finding.

## The residual (5 rows, all `regalloc`)

Row addresses are function-relative. Target = retail, ours = our object.

    047C  extsb r7, r4     | extsb r5, r4
    0488  add  r3, r0, r7  | add  r3, r0, r5
    04C8  extsb r5, r4     | extsb r4, r4
    04CC  slw  r5, r6, r5  | slw  r6, r6, r4
    04D8  and. r0, r5, r0  | and. r0, r6, r0

The 04C8/04CC/04D8 cluster is the interesting one, because it is a *shape*
difference rather than a pure renaming. Retail:

    0007DB70: lbz   r4, 0x24(r30)   ; reload arg->field_24
    0007DB80: extsb r5, r4          ; sign-extend into a FRESH register
    0007DB84: slw   r5, r6, r5      ; result back into the shift-amount register
    0007DB90: and.  r0, r5, r0

Ours fuses the sign-extension in place (`extsb r4, r4`) and shifts into the
`1` register (`slw r6, r6, r4`). Same effective computation; the live range of
the reloaded byte differs, so the allocator picks a different register pair.
The 047C/0488 cluster is the same phenomenon on the loop's induction register.

Tried and measured (do not repeat):

- `temp_bit = 1 << temp_r4_2;` (single expression): **99.7%, 7 rows** — worse.
  It hoists `li r4, 0x1` above the reload and moves `li r6, 0x1` down, so the
  shift reads the wrong base. Regression recorded.
- Reading the reload as `u8` then casting `(s8)category` in a nested block
  (the shape that *matches* at rows 04B4/04BC elsewhere in the same function):
  100.0%, still the same 5 rows.
- Deterministic search: **8851 compiled candidates**, "not reachable by
  declaration order, type/sign flips, pragmas or pool priming."

This is the same survivor-order / regalloc-fold wall documented for the rest of
the near-99% shelf; fn_1_7D6B8 is the largest instance of it.

## The saved 99.958% body was not admissible natural C

The body the fleet saved as its best (`.fzgx/attempts/fn_1_7D6B8.1791760162.c`)
is **rejected by `write-unit`** under the current guard in
`tools/fzgx/api.py` (`allocator_scaffolding`, `tools/fzgx/lint.py:36`). It used
two allocation-forcing devices:

    u8 lab_pad[4]; s8 value; } temp_r4_2;              /* forces a 5-byte local */
    (void) temp_bit;  /* fzgx: keeps the web at its definition */

Both are now recognised as "observed diagnostic tricks". Replacing them with a
plain `s8 temp_r4_2;` local and dropping the no-op reproduces the **identical**
100.0% score and the identical 5-row residual, so nothing was lost — but the
consequence is general and worth knowing:

**Any saved best body that scored via `lab_pad[` or the `fzgx: keeps the web`
comment cannot be re-submitted.** Its percentage is not reproducible through the
admitted write path. Before treating a stored near-miss body as a starting
point, check it against `allocator_scaffolding()`; if it trips, rewrite it to
plain locals first, as was done here, and re-measure rather than trusting the
stored score.

A cleaned, admissible body scoring 100.0% is kept at
`.fzgx/attempts/fn_1_7D6B8.*.c` for continuation. No match, no executable-byte
change claimed.

---

# fn_80067DE4: a one-row residual that is genuinely unreachable, and a search that lies

`fn_80067DE4` (main, 388 B, 97 instructions) sat at 99.938% with a **single**
differing row:

    0170  addi r3, r31, 0x0   |   addi r3, r30, 0x4

That row is the argument to `fn_80025C70` in the second switch's case 3 — retail
passes the object base at offset 0. The prior note claimed "no reachable C shape
emits addi-with-zero under this compiler", but attributed the fold to **GC/1.3.2**
while this unit is pinned **GC/1.2.5n**. Attempt 13 tested that claim directly
and it holds, with the mechanism now measured:

- Struct member at offset 0 (`void *p_000` first, pad grown to keep `p_060` at
  0x60): the whole prologue re-colours to `r30` and the call becomes
  `mr r3, r30` — 80.4%, 34 rows. MWCC folds a zero-offset member to a move and
  stops using `r31` as the base.
- First member as `u8 base[4]` passed by decay: same 80.4%.
- First member as `u32 lead`: 82.5%, 33 rows, still `addi r3, r30, 0x4`.
- Deterministic search from the admissible form: **7548 candidates**, no
  improvement over 82.5%.

So offset 0 is not expressible. The stored 99.938% body reached it only through
`u8 lab_pad[4]` — the banned padding name — which is what steers the allocator
into `r31` and yields `addi r3, r31, 0x0`. This is the same admissibility wall as
`fn_1_7D6B8`, now with the causal mechanism identified rather than inferred.

## A `search` can report "improved" while scoring far worse

`tools/fzgx.py search fn_80067DE4` returned `"improved": true, "change":
"sprintf:int->s8"` and installed the body as the work copy — but its own check
line reads **81.3%**, against a stored best of **99.938%**. The flag describes
"better than the work copy I was given", not "better than the function's best",
and it overwrites the work copy with the lower-scoring body. Two consequences:

- **Never accept a `search` result on its `improved` flag.** Read the `check`
  line's percentage and compare it against the ledger's `best_percent` before
  treating the installed body as progress. Here the flag was true and the body
  was 18.6 points *worse* than what was already saved.
- **A search can silently regress a good work copy.** Restore from
  `.fzgx/attempts/<sym>.<ts>.c` (the release path saves the best body) and
  re-measure after any `search` that claims improvement.

No match; no executable-byte change.

---

# A ledger `best_percent` can predate the unit it is scored against

`fn_80078360` (main, 472 B) showed `best_percent = 99.87288` with five separate
attempts agreeing on it (10-02, 10-03 x2, 10-04). Writing the saved body back
scored **63.2%** — and so did the other two independently stored bodies, all with
an identical 56-row residual. Not a body difference; a scoring regression.

Cause, from the repo's own history:

- The unit `dol/fn_80078360.c` did **not exist** when those attempts ran. It was
  carved by `33562471` on 10-09 23:22, seven days later, out of a shared TU.
- `5ae9c6ee` (10-09 23:25) then pinned `-O2` onto it and recorded the effect:
  `fn_80078360 -O2 2.542 -> 49.153`.
- `state/compiler_options.json` still carries `-O2`, so the flag is correct and
  unchanged. The 63.2% is the genuine ceiling **for this carve**.

So the 99.873% was measured against a different compile path (the pre-carve
shared TU, without the pinned level). The ledger value is not wrong history — it
is simply not comparable to anything landable today.

**Operational consequence, generalised:** `best_percent` is only meaningful
together with the compile path that produced it. Before treating a near-miss as a
live target, check that the unit's `source` path and `extra_cflags` existed at
the attempt's timestamp — `git log -S'<source>' -- config/GFZE01/units.json` and
the attempt's `ended` column answer it in one command. A symbol whose unit was
carved *after* its best attempt is carrying a stale score, and the real current
ceiling may be far lower (here: 99.873% -> 63.2%, a 36-point drop).

Also worth noting: `search` refuses outright below 80% ("needs a body at 80% or
better"), so a carved unit whose stored best predates the carve cannot even be
searched until it is rebuilt from scratch.

Attempts on this symbol, for the record: an indexed `base[i].field` rewrite of
the loop (retail shows `mr r31, r24` + `r31 += 4`, a strength-reduced induction
shadow) **regressed** to 99 rows / 144 — the shadow pointer was absorbing the
parameter copies (`mr r30, r4` etc.), and removing it forced `addi rN, rM, 0x0`
copies of all four arguments. Restored to the 56-row / 63.2% baseline.

No match; no executable-byte change.
