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

Swept all 124 unmatched >=99.0% symbols this way: **102 are stale** (unit 1-29
days newer than the attempt that produced the score), 5 have no unit entry, and
only **17 are genuinely fresh**. So the near-miss shelf is largely a measurement
artifact of the carve rather than a wall of regalloc-blocked bodies.
`tools/stale_score_audit.py` automates the check (read-only). When selecting a
producing attempt for that comparison, match on `final_percent`, never
`max(ended)` — a later attempt postdates the registration and hides staleness.
Also worth noting: `search` refuses outright below 80% ("needs a body at 80% or
better"), so a carved unit whose stored best predates the carve cannot even be
searched until it is rebuilt from scratch.

Attempts on this symbol, for the record: an indexed `base[i].field` rewrite of
the loop (retail shows `mr r31, r24` + `r31 += 4`, a strength-reduced induction
shadow) **regressed** to 99 rows / 144 — the shadow pointer was absorbing the
parameter copies (`mr r30, r4` etc.), and removing it forced `addi rN, rM, 0x0`
copies of all four arguments. Restored to the 56-row / 63.2% baseline.

No match; no executable-byte change.

---

# fn_800288C4: a 2-row residual where the real lever is division *order*, not registers

`fn_800288C4` (main, 252 B, 63 instructions) is the top *fresh* near-miss at
99.841%. Its residual is two rows:

    0080  subf r5, r7, r3   |   subf r0, r7, r3
    0084  slwi r0, r5, 2    |   slwi r0, r0, 2

Read naively that is a survivor-order swap: keep `arg0 - d*100` in its own
register instead of folding it into the index. Holding it in a fresh local
(`r = arg0 - d * 100`) **regresses to 86.6%**, and so does every declaration
position tried — which is the tell that the register choice is not the free
variable here.

The free variable is the order the two magic-number divisions are emitted. Retail
does `/1200` first, then `/100`:

    0010  lis r5, 0x1b4f ; subi r0, r5, 0x7e4b   ; /1200 magic 0x1b4e81b5, shift 7
    001C  mulhw r0, r0, r3 ; srawi r8, r0, 7     ; q
    0028  mulli r0, r0, 0x4b0                    ; q * 1200
    0030  lis r5, 0x51ec ; subi r5, r5, 0x7ae1   ; /100 magic 0x51eb851f, shift 5
    003C  mulhw r0, r5, r0 ; srawi r6, r0, 5     ; m
    0044  mulhw r0, r5, r3 ; srawi r0, r0, 5     ; d

The stored body writes `d = arg0 / 100` before `q = arg0 / 1200`, so MWCC emits
the `/100` magic first and the whole schedule shifts. Both magics are correct for
their divisors (verified: `0x1b4e81b5` is the shift-7 magic for 1200 and
`0x51eb851f` the shift-5 magic for 100), so this is purely evaluation order.

Measured (each a full compile + diff):

- baseline, `d` before `q`, remainder assigned back to `arg0` — **99.8%, 2 rows**
- `r = arg0 - d*100` in a fresh local, order unchanged — **86.6%, 17 rows**
- `/1200` first, `m = (arg0 - q*1200)/100`, `r` separate — **90.9%, 17 rows**
  (best of the reorderings; closes the constant-order rows but retail's doubled
  `srawi r8,r0,7` / `srawi r0,r0,7` then appears as a missing instruction)
- `m = (arg0 % 1200) / 100` instead — **86.6%** (the `%` re-emits `/100` first)
- v4 order plus a duplicated `/1200` in the index expression — **84.3%, 23 rows**

The attempt stopped on the harness's own plateau guard (5 consecutive
non-improving checks) at 99.8%. The productive next step is to reproduce retail's
*paired* `srawi` on the v4 ordering — retail computes each quotient twice as
independent expressions rather than reusing a local — without disturbing the
`/1200`-first order that v4 established.

---

# A carve silently changes a unit's compiler — and that alone can cost 21 points

`fn_80043798` (main, 944 B, 236 instructions) is the clearest case of a *stale
score with a fresh timestamp*. Its best attempt ended 10-11 13:03; the unit was
carved 10-09 23:49. Timestamps therefore said "fresh", the stale audit agreed, and
yet the saved body scored **78.0%** instead of the ledger's **99.745766**.

The bytes were not the problem. Six stored bodies carried md5 `c8015fad` (only
trailing-whitespace variants among them) and that exact md5 had scored 99.745766%
in five earlier attempts and 19.4% in two others. Recompiling the same file three
times gave 78.0% every time, so it was deterministic — just wrong.

Cause, in `tools/fzgx/oracle.py:1034` (`version_for`):

    unit_src = project.unit_of(sym)
    if unit_src:
        u = project.unit_record(unit_src) or {}
        return u.get("mw_version"), (" ".join(u.get("extra_cflags") or []) or None)

For a **carved** unit the check compiles with the unit's own `mw_version` and
`extra_cflags` and *nothing else*. This unit had `mw_version: null` and
`extra_cflags: []`, so it fell back to the `main` module default — measured here as
**`GC/1.2.5n` with `-O4,p`**. Before the carve the same body went through
`version_candidates()`, which compiles under each candidate and keeps the best
fitting one.

Swept every candidate for the `main` module against the unchanged body:

    GC/1.2.5n  (module default)   78.0%
    GC/1.2.5n  -O2                25.0%
    GC/1.2.5n  -O3                26.1%
    GC/1.2.5n  -O4                28.7%
    GC/1.2.5n  -O1                23.9%
    GC/1.3.2                       99.7%   <- matches the historical score
    GC/1.3.2  -use_lmw_stmw on     99.7%

So the compiler, not the source, accounted for the whole 21-point gap. Pinning
`"mw_version": "GC/1.3.2"` on the unit restores 99.7% and leaves a **single**
residual row — `extrwi r9, r10, 8, 16` against our `srawi r9, r10, 8` — which is
the unsigned-extract form of a 16-bit byte swap.

**The general rule:** whenever a symbol's score collapses without its body
changing, sweep `version_candidates()` before touching the C. A carve pins the
compiler; if the pin is absent the module default applies and can be far worse
than the pre-carve best-fit. The stale-score audit's timestamp test does not catch
this, because the unit genuinely does predate the attempt.

Verified with the pin in place: ninja green, 16/16 SHA1s, lint 0 findings, 11/11
tests. The remaining row resisted `search` (0 candidates beat 99.7%), the `sample`
local, `(unsigned short)` truncation on the store, and `(u32)` casts (the last
regressed to 94.3% by widening past the 16-bit store).

---

# fn_80043798: the last row is a retail codegen oddity, not a source difference

Two separate things were going on with this function, and they must be kept apart.

**1. The 99.75% -> 78.0% collapse was the compiler pin, now fixed.** The carve left
`mw_version: null`, so `version_for()` (`tools/fzgx/oracle.py:1034`) used the `main`
module default `GC/1.2.5n -O4,p`. Pinning `GC/1.3.2` restores 99.7%. Committed as
`5c73f098`. Six stored bodies shared md5 `c8015fad` and had scored 99.745766%
pre-carve, so the timestamp-based stale audit could not see it.

**2. With the pin, the remaining single row is not reachable from C.** Retail's
2-channel loop is unrolled eight times and every copy does the identical byte swap:

    8004387C: lhz   r10, 0x0(r4)
    80043884: srawi r9, r10, 8
    80043888: rlwimi r9, r10, 8, 8, 23
    8004388C: sth   r9, 0x0(r5)

...except the eighth, which uses a different opcode for the same operation:

    80043960: lhz   r10, 0x1c(r4)
    80043964: extrwi r9, r10, 8, 16     <- srawi in all seven others
    80043968: rlwimi r9, r10, 8, 23
    8004396C: sth   r9, 0xe(r5)

`extrwi r9, r10, 8, 16` extracts bits 16-23 of `r10`. `r10` was loaded with `lhz`,
so it holds a zero-extended 16-bit value and bits 16-23 are **zero** — whereas
`srawi r9, r10, 8` is `r10 >> 8`. After the shared `rlwimi` only bits 0-7 of `r9`
survive, so the `extrwi` copy would drop the swapped high byte. In other words the
odd copy is not merely differently encoded, it is semantically wrong relative to its
seven siblings.

No C source expresses "perform this identical shift on all iterations except the
eighth." Confirmed empirically — the structural candidates all fail or regress:

- explicitly masked halves `((s & 0xFF) << 8) | ((s >> 8) & 0xFF)` — **82.2%**, 57 rows
- `sample` held in a local with `(unsigned short)` truncation — 99.7%, same 1 row
- `(u32)` casts on both halves — **94.3%**, 36 rows (widens past the 16-bit store)
- `search` — **0 candidates** above 99.7%

**Lesson:** before chasing a one-row residual in an unrolled loop, check whether the
surrounding copies agree. A single opcode deviating inside an otherwise uniform
unrolled body is a retail compiler artifact; the row is unwinnable and further
structural attempts are wasted budget.

---

# fn_12_72F4: part of the documented regalloc plateau was a wrong-compiler artifact

`docs/findings/314` recorded `fn_12_72F4` as regalloc-blocked at 99.88%, with the
body saved and the residual described as unfixable. That measurement was taken
under the unit's module default. Pinning `GC/1.3.2 -use_lmw_stmw on` (which
`tools/pin_scan.py` selected) moves the *same body* from **74.2% to 99.9%**.

So a quarter of the near-99% shelf was not a register-allocation wall at all — it
was units compiled with the wrong MWCC version after the carve.

## The remaining row, characterised precisely

One row, and it is a genuine emission-order problem rather than a naming one:

    00007318  mr r30, r25    |    mr r30, r27

Retail's prologue, in order:

    7308  mr    r25, r3            ; movie
    730C  addi  r26, r25, 0x78     ; output
    7310  li    r28, 0x0           ; i
    7314  addi  r27, r25, 0x44     ; arg        <- arg's address FIRST
    7318  mr    r30, r25           ; induction base
    731C  mr    r31, r26

Our best body assigns the induction base from `arg` (`current = (u8 *)arg`), so it
lands in `r27`. Changing it to `movie` produces the right register but the
allocator then emits `mr r30, r25` **before** `addi r27, r25, 0x44` — the two
instructions are exactly swapped, and the score drops to 95.3% (the shifted
alignment costs a second row).

Measured, all giving the same 95.3% / 2 rows:

- `current = (u8 *)movie` — right register, wrong order
- `arg` materialised early plus `(void)arg` — allocator ignores it
- induction base assigned at the position retail uses — same order
- dead `current` local removed — same order

The cause is that `arg` is first *used* inside the loop (`arg->field_1c = ...`), so
MWCC defers materialising its address, while `movie` is used immediately. Getting
`arg`'s address emitted before the induction base therefore needs the loop to take
`arg` through a path that forces early materialisation — an inlined helper or a
restructured loop — not a statement reordering. That is the concrete next step.
