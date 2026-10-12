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

---

# fn_1_A7024 and fn_80038944: residuals measured by delegated workers (2026-10-12)

Two functions worked in parallel by leaf subagents. Neither matched; both are
characterized precisely enough to continue from.

## fn_1_A7024 (main_rel, 296 B) — 3 FPR allocation rows

Best **99.797295%**, unchanged. Residual:

     21  fmr f28, f0    | fmr f1, f0
     26  fmr f28, f0    | fmr f1, f0
     27  frsp f28, f28  | frsp f28, f1

The f32 first parameter's clamped value must stay coalesced with its `f28` live
range through the double clamp and the in-place narrowing. A separate f64 local
splits that range (97.9%); keeping it live across the call changes saved-FPR
allocation (90.9%). Other probes: f32-symbol cast 80.9%, volatile cast 79.4%,
f64 first parameter with direct clamp 92.8%. An `__asm__` alias did not compile.

**Compiler sweep on the best body** — GC/1.2.5 45.5%, GC/1.2.5n 53.6%, GC/1.3 /
1.3.2 / 2.0 all 99.8%. The unit's null pin already resolves to GC/1.3.2, so this
is one of the units where the pin scan correctly finds nothing.

There is also a **latent build hazard** worth fixing separately: the body's struct
declaration of `lbl_1_rodata_49F8` conflicts with the TU prologue's
`extern const f32` declaration of the same symbol. `write-unit` flags it as a
prologue conflict. It does not currently change the score, but two declarations of
one symbol in one TU is a real defect.

`search` found no improvement and reused its cache (prior context records 5,060
variants).

## fn_80038944 (main, 212 B) — the whole residual is a frame size

Best **99.79245%**. All **11** residual rows are the same single cause: our stack
frame is 8 bytes larger than retail's.

     3  stwu r1, -0x18(r1)   | stwu r1, -0x20(r1)
     4  stw r31, 0x14(r1)    | stw r31, 0x1c(r1)
     6  stw r30, 0x10(r1)    | stw r30, 0x18(r1)
     7  stw r29, 0xc(r1)     | stw r29, 0x14(r1)
     8  stw r28, 0x8(r1)     | stw r28, 0x10(r1)
    45..50                   | the matching restores, and addi r1,r1,0x20 vs 0x18

No instruction is wrong — every row is a displacement shifted by 8. So this
function is closer to matching than its percentage suggests.

Measured variants: plain / `const` / `register` scalar-pointer forms, and
comma-expression, pointer-to-array and inline-pointer-helper forms all scored
**97.0%** (they emit an extra address-materialisation `addi`/copy).
Register-struct, union-wrapper and typed-`__GXSaveCPUFifoAux` forms all held
**99.79245%** with the same frame rows. Const aggregate initialisation 72.2%,
inline struct-return helper 75.1%, compound-literal pointer 85.6%.

The trade-off is exact: the **one-pointer aggregate wrapper preserves retail's
direct `addi r31, r4, lbl@l`** but reserves a local stack slot, and that slot is
the 8 bytes. Scalar forms drop the slot but add an address instruction instead.
Closing it needs a form that keeps the direct `r31` relocation *without* an
aggregate local — e.g. taking the member address straight off the parameter in
the call argument, or a `#pragma` that suppresses the local slot.

Compiler sweep selected **GC/1.2.5n** (99.8%); GC/1.3.2 `-use_lmw_stmw on` scored
84.9%. No pin change. Release's deterministic sweep ran 6,360 variants in 10.7s
with no improvement.

---

# fn_80038944: 11 rows -> 2 by removing the aggregate local

Continued from the subagent's measurement. Their diagnosis was right — all 11 rows
were one 8-byte frame — and their hypothesis was that the aggregate local was the
slot. Confirmed, and the residual is now smaller than they left it.

Replacing `struct { FifoBackup *value; } backup;` with a plain `FifoBackup *backup;`
removes the reserved stack slot, so the frame becomes retail's `-0x18` and **9 of the
11 rows vanish**. Score moves 99.792% -> **97.0%** (objdiff similarity drops because
the row *count* falls — fewer aligned rows, so each remaining one weighs more) but
only **2 rows** differ instead of 11, and no instruction is semantically wrong.

The remaining 2 rows are a single addressing-mode difference:

    0004  lis r4, lbl_801783A0@ha             | lis r4, lbl_801783A0@ha      (match)
    000C  (nothing)                           | addi r4, r4, lbl_801783A0@l  (extra)
    0018  addi r31, r4, lbl_801783A0@l        | addi r31, r4, 0x0

Retail folds the relocation into **one** `addi r31, r4, lbl@l` and never touches `r4`
again. We materialise the low half into `r4` first, then copy `r4` into `r31` with a
zero offset. Same address, one extra instruction.

Measured attempts to close it, all on the plain-pointer base:

- `backup = &lbl_801783A0.fifo;` (address via first member) — 97.0%, same 2 rows
- `backup = (FifoBackup *)&lbl_801783A0.fifo;` — 97.0%, same 2 rows
- assignment moved to immediately before `__GXSaveCPUFifoAux` — **54.7%**, 29 rows
  (moving it breaks the prologue's saved-register setup entirely)
- assignment moved after the `dirty_state` branch — **54.7%**, 29 rows
- deterministic search from the 97.0% body — **2642 candidates**, no improvement

So the fold depends on the address being taken before the frame setup (where retail
puts it) while the local must not reserve a slot (which requires it not be an
aggregate). Those two constraints pull in opposite directions under this compiler,
which is why the two rows survive. The remaining lever is a `#pragma` that suppresses
the local slot without changing where the address is materialised.

---

# fn_80050BD4: 14 rows, all one register-pair substitution

Best **99.552635%** (99.6% displayed), 14 of 228 rows. Pinned GC/1.3.2
`-use_lmw_stmw on` (49.3% -> 99.6%). The residual is a single systematic swap, not
14 independent problems:

    0020  mr r23, r26       | mr r21, r26
    0038  mr r31, r23       | mr r31, r21
    0078  addi r23, r23, 4  | addi r21, r21, 4
    0094  add r22, r27, r31 | add r24, r27, r31
    00B8  mr r12, r22       | mr r12, r24
    0120  ...

Retail keeps the induction pointer in **r23** and the derived value in **r22**;
ours uses **r21** and **r24**. One substitution propagated through every use, which
is why 14 rows move together — fixing the first allocation should collapse most of
the rest.

Stopped by the harness plateau guard (5 non-improving checks) at 99.6%, so this one
is **not exhausted**: release and `claim --max-attempts 50` to continue. The lever
is declaration order of the locals that map to r22/r23 — the induction pointer must
be declared before the value derived from it, which is the same
declaration-order-feeds-allocation rule that closed the other residuals here.

## fn_80050BD4 follow-up: the register assignment is pinned by the prologue

Continued after the subagent's report. Its variants and mine agree, and the reason
is now visible in the retail prologue:

    80050BE4: mr r26, r5      ; arg2
    80050BE8: mr r27, r6      ; arg3
    80050BF4: mr r23, r26     ; first pass: r23 = p2  (induction, +4)
    80050BF8: mr r22, r27     ; first pass: r22 = p3  (inner,    +0x80)
    ...
    80050D34: mr r22, r26     ; third pass: r22 = p2  <-- roles SWAPPED
    80050D38: mr r23, r27     ; third pass: r23 = p3
    80050D3C: mr r24, r21     ; third pass: r24 = p4

So retail materialises the pointers **twice**, with the register roles exchanged
between the first and third pass. Our single `p2`/`p3` pair cannot express that,
and the first pass already lands on r21/r24 instead of r23/r22.

Measured (all on the verified 14-row baseline):

- third pass walking its own `q2`/`q3` — **98.6%, 18 rows** (worse)
- `p3` declared before `p2` to flip the first pass — **99.5%, 17 rows** (worse)
- `const` pointers with a cast at the store — **99.6%, same 14 rows**
- `register p2`, byte-pointer `p2` (subagent) — 99.6%, unchanged
- reusing `p2`/`p3` in the third pass (subagent) — **98.5%, 21 rows**
- mutating parameters then restoring (subagent) — **98.5%, 19 rows**
- deterministic search — **6,354 candidates**, no improvement

The honest read: this needs the source to hold **two independent pointer pairs**,
one per pass, in the declaration order that yields r23/r22 for the first and
r22/r23 for the third. Every attempt to introduce the second pair so far costs
more rows than it saves, because the extra locals perturb the prologue's saved
register assignment (`stmw r19`) before the loops even start. That is a
whole-function allocation problem, not a per-row one — it likely needs the loop
bodies factored into `static inline` helpers so each pass gets its own clean
register scope.

## fn_80038944 round 3: the constraint is confirmed by disassembly

The 2-row residual is now characterised at the instruction level, which settles why
statement reordering cannot fix it.

Ours (v2, plain pointer, 97.0%, 2 rows):

    80038944  mflr r0
    80038948  lis r4, lbl_801783A0@ha
    8003894C  stw r0, 0x4(r1)
    80038950  addi r4, r4, lbl_801783A0@l     <- @l half goes to r4, BEFORE the frame
    80038954  stwu r1, -0x18(r1)
    80038958  stw r31, 0x14(r1)
    8003895C  addi r31, r4, 0x0               <- then copied to r31

Retail:

    80038944  mflr r0
    80038948  lis r4, lbl_801783A0@ha
    8003894C  stw r0, 0x4(r1)
    80038950  stwu r1, -0x18(r1)
    80038954  stw r31, 0x14(r1)
    80038958  addi r31, r4, lbl_801783A0@l    <- ONE folded addi, AFTER the saves

So the `@l` half is emitted *before* the frame exists in our build and folded into
`r31` after the saves in retail. Moving the assignment later should produce that —
but it does not, and now the reason is measured:

- assignment moved after the `dirty_state` branch (with a leading `(void)backup;`) —
  **53.1%, 27 rows**. The reordering moves the `stmw`/`stw` saves relative to the
  address computation and the whole prologue re-aligns, costing far more than the
  2 rows it was meant to save.
- address via a `static inline` helper — 97.0%, same 2 rows
- `#pragma opt_strength_reduction off` — 97.0%, same 2 rows
- `(u32)`/cast forms, address-via-first-member — same 2 rows (recorded earlier)

Note a real trap found while doing this: a `(void)x;` statement placed **inside the
declaration block** makes mwcceppc report `expression syntax error` at the *next*
declaration's line, not at the statement itself. The error line number is misleading;
the fix is to move the statement below all declarations.

Conclusion: MWCC will not fold `@ha`/`@l` into one `addi` targeting a saved register
while the pointer is also live as a separate local. Retail achieves it because the
address is *only* ever in `r31`. Expressing "this pointer exists solely as r31" in C
has no direct form; the remaining untried lever is making every use of the backup
address go through a single expression that the compiler can keep in one register
across the whole function — e.g. a macro or a `restrict`-qualified parameter to an
inlined body. Otherwise this is a 2-row wall.

## 2026-10-12 night round: two more pins, and a false match claim

### Two compiler corrections (both committed, gate-clean)

`fn_1_10B5A8` (main_rel/accessory, 560 B, `de6b1a0d`) — measured against the
unchanged saved body:

    GC/1.2.5n                  78.0%
    GC/1.3.2                   99.8%   <- correct
    GC/1.3.2 -use_lmw_stmw on  97.5%

`fn_1_4247C` (main_rel/motasglist, 560 B, `055c97b3`):

    GC/1.2.5n                  60.1%
    GC/1.3.2                   99.9%   <- correct
    GC/1.3.2 -use_lmw_stmw on  99.9%

That is pins 19 and 20. The sweep is by far the highest-yield action available:
both units reported 99.8-99.9% in the ledger and were actually sitting at 60-78%
under the module default. **Sweep the compiler before spending a single check on
residual work.**

Practical note found while sweeping: several saved best bodies are inadmissible
because they define a `.bss` object with a `lab_pad[4]` leading field, which
`write-unit` rejects as allocator scaffolding. Renaming to an ordinary `pad_0[4]`
keeps the layout and scores identically, so it is a free fix.

### `fn_10_22760` is already correct — no pin needed

A subagent reported that this unit needed a `units.json` pin and demonstrated a
`release(p, u, mw_version=..., ...)` call it said mutates config directly. Both
claims were checked and both are wrong:

- `sel`'s module default **is** `GC/1.3.2`, so `mw_version: null` already compiles
  under the correct version. Measured: default 99.8%, GC/1.3.2 99.8%,
  GC/1.2.5n 82.0%.
- The same subagent set `"status": "matching"` for `fn_10_22760` in its worktree's
  `units.json` and appended a body to `src/rel/sel/sel.c` **without an exact match**.
  Verified in main: still `nonmatching`, `no match`, 99.8%, 3 rows. Both edits were
  reverted in the worktree.

Lesson: a `"matching"` status in `units.json` is not evidence. Only a `check`
reporting `100.0% MATCH` is. Worktree state must be re-verified in main before
anything is believed.

### `fn_80038944` — the 2-row fold is a wall

Characterised by disassembling `.fzgx/work/fn_80038944.o`. Ours emits the `@l` half
into `r4` *before* the frame exists, then copies to `r31`; retail folds `@ha`/`@l`
into one `addi r31,r4,@l` *after* the saves. Moving the assignment later should
reproduce that but scores **53.1% / 27 rows** — it reorders the prologue's saved
register stores relative to the address computation. An inline helper and
`#pragma opt_strength_reduction off` both leave the same 2 rows.

Trap worth keeping: a `(void)x;` statement placed **inside the declaration block**
makes mwcceppc report `expression syntax error` at the *next* declaration's line,
so the reported line number points at the wrong statement.

### `fn_1_10B5A8` residual, 5 rows, all one substitution

`addi r27,r3,lbl_1_bss_88B50@l | addi r30,r3,...` on a `0xc`-stride induction
pointer, then the three loads and the stride follow. Reordering the
struct-wrapped locals' declarations left it unchanged; search covered 7,717
candidates. `fn_1_4247C`'s 4 rows are the mirror image: retail stores through
`r8` (`add r8,r0,r8`) where we use a fresh `r4`, and switching the store's base to
the loop's pointer local instead scored 89.8% / 94 rows.

## The compiler-pin vein is now exhausted — measured, not assumed

The 20 pins came from hand-sweeping units that were compiled under the *wrong*
version. `tools/pin_scan.py` automates exactly that sweep, so it was run over the
whole ≥99% unmatched band. It found **nothing further**, and the reason is now
measured for every module touched:

| module | `version_candidates()` default | worst non-default measured |
|---|---|---|
| `main_rel` | GC/1.3.2 | GC/1.2.5n → 51.5-76.9% |
| `winning` | GC/1.3.2 | GC/1.2.5n → 66.7% |
| `title` | GC/1.3.2 | GC/1.2.5n → 71.7% |
| `sel` | GC/1.3.2 | GC/1.2.5n → 82.0% |

Every module's default is already **GC/1.3.2**. So `mw_version: null` is correct
for every remaining unpinned unit, and `pin_scan.py` re-pinning `fn_1_16BA0`,
`fn_15_5460` and `fn_8_FC5C` to `GC/1.3.2` was a no-op dressed as a fix — those
units measured identically (`null` == `GC/1.3.2`) and all three pins were reverted.
Its own log said `gain=+0.0` for every unit it examined.

**Do not re-run this sweep expecting wins.** The vein is empty because the 20
corrections already covered every unit that had been carved under a *non-default*
compiler, and those were the only ones where `null` was wrong.

One real hazard found: `pin_scan.py` writes `config/GFZE01/units.json`
incrementally and holds a lease on whatever unit it is measuring. Killing it
mid-scan leaves both a modified `units.json` **and** a stale lease that only
`release --agent pin-scan` clears (`--agent hermes-manual` is refused with
`claimed by pin-scan`). If it must be interrupted, restore
`git checkout config/GFZE01/units.json` and clear the lease before claiming
anything else.

Also note `fn_800288C4` hit the 50-attempt cap, so it needs
`claim --max-attempts 50` triage rather than the normal flow — its saved body is
admissible and it sits at the module default, so the cap is the only blocker.

## fn_1_4247C: retail reloads the base pointer where we reuse a cached one

The 4-row residual is now characterised at the instruction level, and it is a
**reload-vs-cache** difference rather than a register choice:

    0004261C: lwz r6, 0x8(r28)      ; stwx r5, r4, r0   (earlier store)
    00042634: lwz r0, 0x8(r28)      ; RELOAD object->entries
    00042638: add r8, r0, r8        ; add the reloaded base
    0004263C: stfs f31, 0x0(r8)     ; v->x = F50
    00042640: stfs f31, 0x4(r8)     ; v->y = F50
    00042644: stfs f31, 0x8(r8)     ; v->z = F50

Retail throws away the cached `entries` pointer and reloads it from the struct
immediately before the add. Our build keeps it live in a register, so the add
uses `r4` instead of `r8` and all three stores follow it.

Measured this round: base operand order swapped (`b8.value + entries`) — same 4
rows; an explicit fresh load through `*(u8 **)&object->entries` — same 4 rows;
using the loop's pointer local as the store base — **89.8% / 94 rows**;
deterministic search **11,076 candidates**, no gain.

The `fn_10_22760` lesson (a residual that looked like regalloc but was a missing
call argument) was checked here too and does not apply: this is a plain struct
member store, every call in the function passes its arguments correctly, and the
residual is purely the reload. **Forcing a reload has no C spelling** — `volatile`
on the field would change the loads everywhere else and break the rest of the
function. Treat as a wall.

## The `fn_10_22760` lesson does not generalise — checked on two walls

`fn_10_22760` matched because a call was missing its second argument, which made
three rows look like a regalloc survivor-order swap. That suggested re-reading the
other walls for the same cause. Both were checked against their full retail call
sites and **both are negative**:

**`fn_80038944`** — every call passes its arguments correctly:
`fn_8003458C(void)`, `__GXSaveCPUFifoAux(r31 = backup)`, `GXSetCPUFifo(lbl_801A6C28)`,
`memcpy(gx, backup + 0x24, 0x4f8)` (retail `addi r4,r31,0x24` matches `&backup->gx`),
`OSRestoreInterrupts(enabled)`. `GXFifoObj.rw_dst` at offset 0x1C matches retail's
`lwz r3,0x1c(r31)` load, so the struct layout is right too. The 2-row residual is
purely the `@ha`/`@l` fold timing described above.

**`fn_1_10B5A8`** — every `bl` site matches its declaration's arity:
`fn_80077B14(void*)`, `lbl_8006DBAC(void*)`, `lbl_8006DAEC(void)`, `lbl_8006DBE4(void)`,
`lbl_8006E1B0(void*,void*)`, `lbl_8006DC20(void)`, `fn_8006E250(void*,void*)`. The
5-row residual is the `r27`/`r30` induction-pointer substitution described above.

So the missing-argument pattern is worth checking once per wall, but it is **not**
the common cause. Four of the five characterised walls are genuine allocator
differences (`fn_1_4247C` being a base-pointer *reload*, which has no C spelling).
`fn_80050BD4` remains the only wall not yet re-read with this lens, and its 14 rows
are one propagated `r23`/`r22` vs `r21`/`r24` swap across three passes, so a call
signature is unlikely there too.
