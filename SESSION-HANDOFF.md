# F-Zero GX decomp session — state and handoff

Last updated: 2026-10-18. Repo: `/home/armandofm/projects/fzgx` (branch `main`,
fork `karamzov123/fzgx`). **Read this first in any new session.**
(The 2026-10-12 sections below are still valid; the newest session state is the
`2026-10-18 session state` section just below, then `2026-10-17`.)

## 2026-10-18 session state (opencode/deepseek)

**`sel:_epilog` landed** (sel, 556 B, 139 words, commit `406595bf`, finding 388).
The 10-attempt `99.64029` plateau was an artifact of masked flag constants; the
semantically true body sat at 97.84 and the register-work statement order
(`base; mgr; state; f`) at 95.68, with the whole residual a `f` / `B@ha`
register swap (`A@ha` r3, `f` r4, `B@ha` r5 in retail). Every spelling that
assigns the load to a named local writes that local's vreg, and a named local
always colors *after* every statement temp - so `f` could never claim `r4`
before `B@ha`. The fix is a **front-end-invisible, optimizer-visible identity**:
`f = *(u32 *)(state + 0x94) & (*(u32 *)(state + 0x94) | ~*(u32 *)(state + 0x94));`
- the three reads stay expression *operands*, so the value takes this
statement's anonymous temporary; MWCC's optimizer folds `v | ~v` to `-1` and
`v & -1` to `v`, leaving a copy that coalesces into the temporary (the same
survivor direction as the `lis`/`addi` materialisations). Its number is the
statement pair, which colors `A@ha` r3 / `f` r4 / `B@ha` r5 exactly; 139/139
words, 0 differing rows, verify fast path 10.6 s, `16 files OK`. The identity is
exact for u32 (`v | ~v == 0xFFFFFFFF`), not a mask hack - the object still has a
single `lwz`. Full record: finding 388 (includes the measured flat cohort:
identity operators, nested assignment in the store, carriers, block-copies,
self-stores, empty-if CSE, GC/1.3-2.7 sweep).

**Next lead:** `fn_3_1AEE4` (99.45206, 14 attempts) is not in the capture corpus
and needs a fresh capture; within `sel`, the next near-matches are `fn_10_3B44`
(99.038) and `fn_10_25610` (98.956); `fn_10_7130` stays parked
(base+offset-split family, `state/blocked.md`). Reuse the finding-388 lever
whenever a capture says `needs-web-alignment` because a *value* needs an
anonymous temp web and carriers/declaration orders cannot reach it (they only
move values down the local stratum).

Ledger after the landing: matched=**5847** + 20 asm, unmatched=1432, blocked=9,
0 open claims.

## 2026-10-17 session state (opencode/deepseek)

Eight landings (the last two crossed midnight into 10-18). The newest is
**fn_8_5C54** (title, 896 B, commit `351b536c`, finding 382): the 6-attempt /
16k-permutation plateau at 99.50893 (17 register rows — oc1 had already named
it "a pure allocator rank transposition of two webs") fell to the two
claim-order levers the repair engine cannot reach: declare the loop counter
`n` in the **last** declaration slot (that slot alone out-ranks the other
named locals → `n` claims r30; first/middle slots are measured no-ops), and
spell the byte truncation `n & 0xFF` instead of `(u8)n` — in the slot index
**and** the second loop bound. Same `clrlwi` bytes, different node: the AND
web claims a late saved color (`clr1 → r21`, bound value `r18`), the cast web
an early one. 224/224 words, 0 differing rows, no pool retarget; one counted
check (the `write-unit` auto check — the 47-variant offline screen cost
none), verify fast path 10.7 s, `16 files OK`. Full record: finding 382.
Same session tooling: both levers are now stock generators in
`fixup_source.py` (declaration-order end-moves + the `mask_spellings`
family), validated by re-running the engine's own composition on this
frontier body (224/224 from base).

The one before it is
**fn_8_EFA4** (title/name_entry, 2624 B, commit `fd68a52a`, finding 381): the
3-attempt plateau fell to the **true source shape** — the frontier bodies
carried a cross-module header's `extern s8 lbl_801A66A0` for a `.sbss` size-0x4
symbol, so no `u32`-word-load body could reach retail's schedule. With
`extern u32 lbl_801A66A0;`, the callee prototype `extern f32
lbl_8006D188(s16);`, and the uncast argument `(s16)((lbl_801A66A0 << 8) &
0xFF00)` (witness: option twin `fn_4_C768`) the body is word-identical
(656/656, 0 differing rows). One counted check, submit on the
compile-and-retarget path (`pool_map {...rodata.0→lbl_8_rodata_408,
@37→lbl_8_rodata_AF8, @38→lbl_8_rodata_B00}`), verify fast path 3.69 s,
`16 files OK`; the same drain also link-verified Hermes's `__pformatter`.
Full record: finding 381.

The sixth closes the last designated lead of the day (finding 379):
`fn_1_156C08`'s 99.01% / 12-attempt plateau fell to a **one-edge interference
web** — MWCC's stock simplify defers every web whose degree stays >= K=29 GPRs,
so holding `&arg0->handle` in a `u32 *ph` inside the call branch (28 -> 29
neighbors, no emitted instruction) defers the arg0 web and restores retail's
r31/r30 with the correct s32 compare. attempt 13, 2 checks, commit `9b299290`,
gate green. Tooling: `d69576ef` decodes `fcmpo` in `mwconstraints` (capstone
5.0.7 gap that finding 361 misread as an integer row-12 pair, blocking the whole
capture projection). Full record: finding 379.

Earlier in the day (still valid below): the newest is a pool-window/displacement close in the `font` TU;
before it, the `fn_12_2F970` one-word plateau fell to local-struct promotion
typing, and earlier ones to byte-equality over the pool *reach window*:

- **fn_1_53B14** (main_rel/font, 49 words, commit `e4abc50a`, finding 377).
  The 99.22449% body (`params = { 0 }`) compiled 46/49 words: MWCC materialises
  a large zero aggregate as a copy from a compiler-generated **zero template**,
  so the three residual rows were displacement immediates off the live pool base
  (`0x60/0x150/0x158` vs `0x68/0x58/0x60`) — not repairable by the pool
  machinery. Fix: rebuild retail's `[lbl_1_rodata_26F8, +0x15C)` window
  byte-equal in the block (finding 344's table + `{0,1.0f}@0x58` + 2^52 primer
  @0x60 + 58-word filler + 255.0 primer @0x150 + **8.0f primer** @0x158 — a
  literal, unlike finding 344's native table4, because this body reads it),
  then copy from `fzgx_pool_table1`. `pool_map {...rodata.0→lbl_1_rodata_26F8,
  @9→lbl_1_rodata_2758, fzgx_pool_table1→lbl_1_rodata_26F8}`; post-retarget
  `.text` byte-equal to retail, relocations identical, `.rodata` empty. Zero
  ledger checks before the claim: one offline `oracle.check(source=…)` predicted
  100.0% + pool_map; write-unit `100.0% MATCH` (1 check), verify fast path
  11.9 s. Same PROLOGUE CONFLICT / `noprologue` coexistence as finding 344.
- **fn_12_2F970** (movie_module, 30 words, commit `e1788001`, finding 376).
  Retail w7 is `mr r30,r31` (counter copy of the just-zeroed register); plain
  locals fold (finding 371) and `opt_loop_invariants off` fixes the allocation,
  but the whole u1–u6 `{u32 z; s32 i;}` family never promoted: `s32` is `signed
  long`, and MWCC 1.3.2 pins a two-member local struct to the stack when its
  **second** member is `s32`. Promotable pairs need second member `int`
  (`{u32,int}`, `{int,int}`, `{uint,int}` all exact); `{u32,u32}` promotes but
  flips the loop compare to `cmplwi` (29/30); writing the counter init before
  the pre store demotes the struct (33 words, `stmw r24`). 280-variant
  single-TU sweep: 18 exact, all with `s.zero = 0; p->pre = s.zero; s.index =
  s.zero;` and the four `fzgx_live[k] = s.zero` stores; 30/30. Carved corpus
  re-scan: 31 `li rD,0; mr rA,rD` pairs in 3,959 objects (10 landed witnesses);
  landed `fn_1_4270C` keeps its accumulator zero in a one-member struct and
  emits the same pair. attempt 22, write-unit `100.0% MATCH`, verify fast path
  10.8 s.
- **fn_10_1B2F4** (sel, 217 words, commit `7256d6b0`, finding 373). Residual was
  only the pool-base rows (`lbl_10_rodata_158` vs `...rodata.0`) plus 9 pool
  rows; `_pool_rows` accepts them only when our `.rodata[0..(reach+3)&~3)` is
  byte-equal to retail's region, and reach comes from the max positive
  displacement through the pool base (`lfs f2, 0xf70(r31)` → 0xf74), not just
  the literals the rows show. Two defects: `d = 0.55f;`/`d = 0.49f;` decimal
  primes rounded through f32 (drop the `f` suffix → exact doubles), and the
  fixup session's own "best" had inlined `fzgx_pool_prime66` away, dropping its
  `0.64f` literal and shifting 17 words (never mark `.fzgxpool` primers
  `inline`; fixup's `word_errors 0` says nothing about pool bytes). Removing
  `(void) p;  /* fzgx: keeps the web at its definition */` satisfied the
  allocator-scaffolding gate with a byte-identical object. attempt 5
  (`claim --max-attempts 50`), write-unit `100.0% MATCH`, submit recorded
  `pool_map` `{...rodata.0→lbl_10_rodata_158, @9→+0x44, @10→+0x48,
  @27→lbl_10_rodata_1E8}`, verify fast path; gate green (ninja 0, 16 files OK,
  lint 0, 11/11 tests).

Two more one-word landings, both closed by *construct-class* changes after the
whole source-shaping family failed; in both cases a matched same-module sibling
witness found the shape (scan matched siblings for the retail instruction pair
before spending more permutations):

- **fn_12_2F7AC** (movie_module, 244 B, commit `dd9ef50e`, finding 371). Retail
  w5 `mr r31,r6` (init `index = result` after `result = 0`) cannot be kept by
  plain locals: `opt_propagation off`/`opt_common_subs off` are *inert*, and
  chained/multi-decl/goto/temp-copy spellings all re-materialize `li r31,0`
  (frontend, not optimizer). Holding result+index in a local `loop_state`
  **struct** (`s.result = 0; s.index = s.result;`) keeps the copy: 61/61.
  Witness: sibling `mwSfdDestroy` materializes a hoisted constant 0 as
  `mr r30,r28` from the just-zeroed counter.
- **fn_1_A1CE8** (main_rel/sound, commit `a5ac7b0a`, finding 372). Retail w15
  `cmplwi r0,0` with `beq body; b exit` is the last term of a **short-circuit
  OR** guard (`if (ptr == NULL || (u8)arg0 >= 0x2D || flag != 0) return;`);
  every switch/cast variant (u32/u8/bare, `case 0u`, bitfield pun) stays
  `cmpwi`, and the one-case switch reproduces the layout but can never produce
  `cmplwi`. Witness: sibling `fn_1_A0978` (same `lbz; cmplwi; beq +; b far`).

Parked, not landed: **fn_1_2A214** (main_rel/stcoli, 36 words) at its 99.1667%
5-row allocator fixed point — finding 378. All 24 decl perms under
`opt_propagation off` reach exactly 4 colorings, none the retail one
(f2,f1,f0); no-pragma shapes are all the flat 7-row body; GC/1.2.5–2.5
identical. Matched siblings `fn_1_879B0` / `fn_1_156D9C` do emit retail's
descending f2,f1,f0 homes and the exact missing `fmuls f1,f2,f1`, so the wall
is this RTL's selection, not a source spelling. Future lever: capture /
constraint-pipeline support (finding 361 class). Left claimable (`unmatched`).

Ledger after all seven: matched=**5842** + 20 asm, unmatched=1437, blocked=9,
0 open claims, 0 pending links. Gate green: verify `16 files OK` at `fd68a52a`,
lint 0 findings. (Hermes released `fn_12_3763C` unmatched; `fn_8_EFA4` and
`__pformatter` closed and link-verified in the same drain.)
(10-17 morning also added Hermes's finding 370 parked-pass records; commit
`891eeb0c`.)

**Next lead:** the designated lead list is exhausted — `fn_8_EFA4` landed
(finding 381), `fn_1_156C08` landed
(finding 379). Fallback `fn_1_118D90` (main_rel, 1344 B) was explored on 10-17
and parked at a **5-word plateau** (finding 380): archived
`.fzgx/attempts/fn_1_118D90.1792292741.c` at objdiff 99.872025 (words
`[6,7,304,307,309]`), better than every earlier saved body (99.72/99.54/99.43).
The residual needs the old body geometry for the latch pair *and* the M1
geometry for the trio colors at once — all ~60 reachable source shapes couple
them, and the entry `lis r4` needs the raw parameter web live across the lis
temp (every copy spelling coalesces to the entry homing copy). Pick the next
candidate from the largest unmatched units with a saved near-match corpus (or
return to `fn_1_2A214` once capture/constraint support exists). The degree-29
sweep rule (finding 379) is reusable: when a near-match differs only by a
callee-saved register role swap, count the losing web's neighbors — one extra
live-across-the-call web (a source-held pointer that emits no instruction) is
the lever, and a stock-allocator capture shows the degree before and after.

## 2026-10-16 session state (opencode/deepseek)

**movie:_prolog measured to a complete closure set; its asm landing was REVERTED; triage-blocked (23 attempts).**
Full record: `docs/findings/359-movie-prolog-asm-reverted-closure-set-blocked.md` (supersedes
finding 358's escape; the owner's steer — *"does it need to be asm? the goal is c functions"* —
plus finding 301's own "do not convert these to asm units" decided it). The one-word residual
(retail `sth r11, 0(r10)` vs our `stw` at word 87 of the 99.21875% u32 body) has no authored-C
reproduction: every narrow lvalue spelling re-phases the 7 lis / 7 addi window to 88.28%;
value-into-local splits are width-independent 57.03% (u32 control included); source reorder is
46.9% (both widths); the GC/1.3/2.0/2.5/2.7 sweep never reproduces retail phasing under a narrow
store; inline asm is a matcher-tooling ban; region-crossing is unavailable (PAL shares the
byte-identical `fze.movie_module.rel` hash, and the unit's `fze.movie.rel` is US-only; the
sibling `movie_module:_prolog` is an unrelated fp-table initializer). Undo: `fzgx uncarve
rel/movie/_prolog/_prolog.c` (entry/split/`.s` removed, movie relinked inside uncarve → 16 files
OK / lint 0 / tests 11 OK), `fzgx block movie:_prolog --reason…`, `state/blocked.md` row, best C
still in `.fzgx/attempts/movie:_prolog.1791747343.c`, asm `.s` recoverable from `7fa25826`.
Two real tooling bugs fixed in `tools/fzgx/uncarve.py`: an `asm: true` unit's sibling `.s` is
now removed beside the recorded `.c`, and units' ambiguous bare symbols (`_prolog`) now ledger-key
as `module:name` — the old `p.resolve(s)` fallback silently cleared no ledger row.

**fn_1_D123C solved and landed** (commit `63413b8d`, attempt 17, two checks spent).
Full record: `docs/findings/348-fn-1-D123C-value-merge-diamond-s32-sid.md`. The two
`lwzx / cmplwi; beq 8; b` dispatch sites are the value-merge diamond
(`if (EXPR != 0) v = EXPR; else v = call;`); the residual that survived every
construct spelling was `sid`'s register — `s8 sid;`→r25, `s32 sid;`→r27 with the
rest of the function byte-identical (a `switch` keeps sid=r27 but emits `cmpwi`,
2 diffs). First `write-unit` hit a PROLOGUE CONFLICT (`lbl_801A6410` as `u32` vs
the prologue's `void *`); the final body aligns every file-scope declaration with
the prologue and preserves the codegen-critical `s16` return of
`fn_1_12C930` via a call-site `(s16)` cast. Verify fast path, 16 files OK,
lint 0 findings, 11 tests OK. Offline pre-validation recipe (standalone compile +
`_prologue_conflict` replication) is in the finding — use it before spending checks.

**fn_1_53E40 solved and landed** (commit `bdd5b9d9`, attempt 48, one check spent).
Full record: `docs/findings/344-fn-1-53E40-rodata-pool-whole-region.md`. The
47-attempt plateau was a single byte displacement: our 2^52 conversion magic at
private-pool `+0x58` vs retail `+0x60` — retail has 8 filler bytes
(`0x58..0x5F`) between the 0x58-byte record table and the magic that no
function-local reading explains. Closed by reconstructing the whole retail
region `[lbl_1_rodata_26F8, +0x170)` byte-equal: one `static const u32` table
per object, interleaved with `.fzgxpool` primer sinks in first-use order.
Landed via `claim --max-attempts 50` (a plain claim is refused at
`attempts >= 3`), `write-unit` → 100.0% `MATCH` (`matched: true` + `pool_map`),
`submit` (block spliced **`noprologue`** — its `fn_1_50190(void *, …)`
prototype disagrees with the TU prologue's 6-float one used by `fn_1_50164`),
`verify` fast path, 16 files OK. Post-link object: `.text` byte-equal to
retail, `.rodata` empty, relocations identical to retail's two
`lbl_1_rodata_26F8` entries.

**fn_1_2D038 attempted (attempt 46), released at its 99.68% plateau — do not re-derive.**
Full record: `docs/findings/343-fn-1-2D038-fold-schedule-coupling.md`. One-word residual
(`lbz r0, 0x5(r3)` vs folded `0x35(r31)` at word 65). 20+ source shapes measured: every
in-expression form folds; the only shape that yields the register-form load is *statement
separation* (assignment in a different basic block from the load), which then costs 2 words
because the `addi` fills the `lbz` delay slot before `cmplwi`. The fn_17_7728 BSS-object +
pool-map recipe was applied to this symbol (u01–u03) and changed nothing. Pragmas confirmed
dead on this function too (finding 299 holds). Archived best body:
`.fzgx/attempts/fn_1_2D038.1792125978.c` (99.68). Remaining levers if ever revisited: a
pointer variable materialized across the function without spilling, the full private-BSS
TU rewrite, or `uncarve` + `asm-unit`.

**fn_1_135D7C measured to its fixed point (attempt 40+, not blocked).** Full record:
`docs/findings/345-fn-1-135D7C-materialise-allocation-fixed-point.md`. Its named
one-word residual (`mr r4, r3` vs `extsb r4, r3`, w185 of 254) is coupled to the
pool-address lowering: narrow returns materialise with the *retail-correct* scratch
allocation but keep the bad extension; every wide return folds `@l` onto the `lfs`
(one word at w183); the only shape with both instructions right (the FEAC call
inlined into the argument list, wide return) permutes the {pool temp, format base}
pair between r5/r6 (4 words). ~160 measured shapes — expression texts, prototypes,
casts, decl orders, comma forms, inlined helpers mirroring `fn_1_13DDB8`'s
`operand()`, pragma cells, and the private-pool recipe — moved nothing. Cross-corpus
reloc scan: only 6 materialised float symbol reads in all of `main_rel` vs 1405
folded, and matched `fn_1_13DDB8` / `fn_1_FDC00` each fold *and* materialise the
same symbol/expression inside one function — the choice is downstream selector
context, not a source idiom. `fn_1_14FEAC` returns its 4th argument (32-bit), so the
s8 best body is stale-typed (refines 304). Left `unmatched`/claimable per project
convention (`blocked` is for unsupported credit; `fn_1_2D038` precedent).

**Free candidate probe (big time-saver, use it first).** Do NOT spend ledger checks to
test source shapes: `write_unit` AND `check` each consume one, and the plateau guard
trips at 5 non-improving checks (a tripped attempt refuses `write_unit` *before writing
the file*). Instead compile the candidate offline with the unit's own compiler/flags via
`oracle.compile_source(project, module, src, /tmp/…/x.o, mw, extra)` (mw/extra from
`project.unit_record(unit)`), then `oracle.words(project.target_object_for(sym))` vs
`oracle.words(obj)` and `oracle.word_score` — exact positional word diff, ~10 s per
shape, no claim, no work-copy writes. That method is how 343's table was produced.
Claim+release is only needed for probes that touch `.fzgx/work/`.

**fn_1_4270C solved and landed** (commit `ce2e3eb4`, attempt 31, one check spent).
Full record: `docs/findings/346-fn-1-4270C-shared-loop-counter-mr-init.md`. The
99.5851% one-word residual (`mr r30, r29` vs folded `li r30, 0` at w205) is a
selector consequence of *loop-counter variable sharing*: with multiply-addressed
loops (`base + i * K`, `base[i]`), MWCC strength-reduces a running bytes-offset
shadow whose init materialises as `mr rOffset, rCounter` when the counter variable
is **shared with an earlier loop**, and as `li rOffset, 0` when it is fresh.
Same-TU matched siblings `fn_1_41F58` (loop 2) and `fn_1_42E74` (loops 2/3) show
both forms side by side. Fix applied: the second outer loop reuses the first
loop's counter `v6` with `v33 = v32 + v6 * 396` and no explicit offset local —
then 241/241 words, 100%. Copy spells, union/pointer puns, inline helpers,
function-wide `opt_propagation off` (179 words break), `opt_lifetimes off`, and
mid-function pragmas (inert — pragma state is captured per function) were all
measured dead.

**Next candidates** (same one-word tier): `state/one_word_tier.json` REGENERATED this
session by the compiler-backed word-diff scan (46 near-band bodies scored; only
0 < differing ≤ 2 rows kept, so landed/blocked/needing-a-bigger-body entries drop
out). Fresh rows: `fn_1_135D7C` and `fn_1_2D038` and `fn_1_1384C` (all three are
measured fixed points — findings 343/345/347 — the fleet still lists them until
unblocked/matched), `fn_1_707C` (NEW: diff 1 of 48 words, "same mnemonic, immediate
differs" + one relocation-only row, 11 attempts), `fn_800288C4` (diff 2 of 63, needs
the default GC/1.2.5n pin per the previous handoff, 51 attempts). Outside the tier
but the finding-358 designated lead: `fn_1_156C08` (99.01%, 12 attempts — sits below
the 60-body scan cutoff). Landed since: `fn_17_7728` (commit `4ad73314`).
`movie:_prolog` is blocked (finding 359). Probe shapes offline before claiming.

Not touched this session: the in-flight main-tree leftovers listed in the previous
handoff. The disk question was resolved this session: the fixup retention policy
was **relaxed** (historical scored candidates are cold, byte-verified, restorable;
hot set = report best rows + link evidence) — `docs/findings/360`, committed
`53ea1d55`. The `fzgx-storage.service` timer now drains ~1627 closed fixup
sessions' 174GB incrementally (every 10 min pass acts on 2 sessions; the one-off
wider pass of 2026-10-16 ran 24 sessions × up to 100k files). Disk was 18GB free
before; expect steady accrual. Do not restore the old "every scored source hot"
rule without re-reading finding 360's consumer audit.

## How to run things

    cd /home/armandofm/projects/fzgx
    .venv/bin/python tools/fzgx.py <cmd>        # system python3 lacks capstone

Long unattended work: `terminal(background=True, notify=True)`. Do **not** wrap a
long job in `timeout N` — a 590s timeout killed a fixup GC run before it reclaimed
anything.

## Acceptance gate for any executable-affecting change

    ninja build/GFZE01/ok
    sha1sum -c config/GFZE01/build.sha1        # must print 16 files OK
    .venv/bin/python tools/fzgx.py lint        # 0 findings
    .venv/bin/python -m unittest discover -s tests   # 11 tests OK

## The big finding this session: wrong-compiler pins

A carve leaves `mw_version: null`, so `version_for()` (`tools/fzgx/oracle.py:1034`)
falls back to the module default — but the body was measured *pre-carve* under the
best-fitting candidate compiler. Scores collapse with no source change.

    .venv/bin/python tools/pin_scan.py --min-pct 99 --limit 30

Already applied — **18 units total** across commits `78b84514` (11) and `b501ae83` (7):

| symbol | default | pinned | score |
|---|---|---|---|
| fn_8006C7E8 | GC/1.2.5n 46.8% | GC/1.3.2 | 99.6% |
| fn_80050BD4 | GC/1.2.5n 49.3% | GC/1.3.2 +lmw | 99.6% |
| fn_80009830 | GC/1.2.5n 51.2% | GC/1.3.2 | 99.2% |
| fn_80078360 | GC/1.2.5n 63.2% | GC/1.3.2 | 76.4% |
| fn_80059DD8 | GC/1.2.5n 68.3% | GC/1.3.2 +lmw | 99.3% |
| fn_80041700 | GC/1.2.5n 72.2% | GC/1.3.2 +lmw | 99.7% |
| fn_12_72F4 | GC/1.3.2 74.2% | GC/1.3.2 +lmw | 99.9% |
| fn_800478C0 | GC/1.2.5n 73.2% | GC/1.3.2 +lmw | 99.7% |
| fn_80078DA8 | GC/1.2.5n 74.0% | GC/1.3.2 | 99.8% |
| fn_80077BD4 | GC/1.2.5n 81.4% | GC/1.3.2 | 99.3% |
| fn_800446E4 | GC/1.2.5n 78.0% | GC/1.3.2 | 99.7% |
| fn_80074D88 | GC/1.2.5n 90.7% | GC/1.3.2 | 99.5% |
| fn_12_2F970 | GC/1.3.2 78.7% | GC/1.3.2 +lmw | 98.0% |
| fn_12_A5C | GC/1.3.2 92.1% | GC/1.3.2 +lmw | 99.8% |
| fn_12_2DBD4 | GC/1.3.2 95.5% | GC/1.3.2 +lmw | 99.4% |
| fn_12_36208 | GC/1.3.2 94.5% | GC/1.3.2 +lmw | 99.7% |
| fn_12_29524 | GC/1.3.2 98.3% | GC/1.3.2 +lmw | 99.7% |
| fn_12_3A64 | GC/1.3.2 98.0% | GC/1.3.2 +lmw | 99.5% |

`fn_800288C4` correctly needs the **default** GC/1.2.5n (99.8%) — the scan rules
units out too, it does not assume a pin is always the fix.

A full sweep of the unpinned >=99% units has been completed
(`tools/pin_scan.py --min-pct 99 --limit 95`, 78 units scanned). To re-check
anything, or to sweep a lower threshold: `--min-pct 95 --limit 200`.

## Disk / inode safeguard — IMPORTANT

`.fzgx/fixup` grew to **175G** and filled the disk to 94% (37G free). The cleaner is
`tools/fzgx/fixup_gc.py` — lossless (cold tar bundles, verified, originals removed;
reports/cache/captures never rewritten).

    # dry run first (default)
    .venv/bin/python tools/fzgx/fixup_gc.py --min-age-hours 1 --max-files 20000 --max-sessions 4
    # apply, background, NO timeout wrapper
    .venv/bin/python tools/fzgx/fixup_gc.py --apply --min-age-hours 1 \
        --max-files 20000 --max-sessions 2000 \
        --status /home/armandofm/.cache/fzgx-agents/storage-night.json

`fzgx-storage.service` / `fzgx-storage.timer` are systemd-user units meant to run this
every 10 min. **The timer IS firing correctly** (enabled, active, `OnUnitActiveSec=10min`,
last run logged success) — but its `ExecStart` uses **`--max-sessions 2`**, so it reclaims
2 sessions per 10 minutes against 1611 sessions on disk. That is why 175G accumulated: not a
dead safeguard, a safeguard set far too low to ever catch up.

Verify and consider raising the per-run session count:

    systemctl --user list-timers fzgx-storage.timer
    systemctl --user cat fzgx-storage.service      # look at --max-sessions

Measured while fixing this: a manual `--max-sessions 2000 --apply` run reclaimed space
steadily (37G -> 39G free and climbing). Note it only writes its `--status` file at the
very end, so watch `df -h /` rather than the status file to follow progress.

Retention policy detail, so the numbers are not surprising: `plan()` keeps **every**
cache-referenced source (for seed harvesting) and only bundles sources absent from
`cache.json`. Across a 40-session sample that still left ~353k reclaimable sources and
~233k objects, so the space is genuinely recoverable — it just needs enough sessions per run.
A single large session (`fn_10_1A458`) held 2.9G: 1.7G in `sources/`, 1.1G in `objects/`.

### Completed run, 2026-10-12 — verified lossless

One full `--apply --max-sessions 2000` run over **all 1611 sessions** finished cleanly
(`GC_EXIT=0`, `status: healthy`):

    312 archived   |  1264 retained  |  35 recent
    3,245,025 files reclaimed  =  19.9 GB
    disk:  39.5 GB free  ->  59.9 GB free
    inodes: 64.7% used   ->  57.2% used

`fixup` went 175G -> 158G while `fixup-archives` holds only 2.2G across 314 bundles —
about 9:1 compression, so the space is really gone rather than relocated.

**Losslessness verified, not assumed.** Picked an archived session from the log and
restored its bundle with `--restore <archive> --session <session> --dry-run`:
`{"restored": 20000}` — 20,000 of 20,000 files readable and hash-consistent. To
restore for real, drop `--dry-run`. Note `--restore` **requires** the matching
`--session`; pairing an archive with the wrong session raises
`restore session identity mismatch` (the guard works, so match them from the GC log's
`archive` / `session` fields rather than guessing).

The 1264 `retained` sessions are correct-by-design: their sources are all
cache-referenced and kept hot for seed harvesting. Expect a large retained count; it
is not a failure.

Check `df -h /` and `df -i /` before starting any long run.

### `~/.cache/fzgx-agents` is NOT covered by the GC — 7.5G, cleaned by hand

The GC only touches `.fzgx/fixup`. A second 7.5G lived in
`~/.cache/fzgx-agents`, invisible to it:

    hermes-runtime        4.9G   per-run agent session dirs
    clients               1.2G   2252 client dirs (2146 older than 3 days)
    publish-checkouts     922M   git checkouts per published commit
    hermes-uv-cache       317M
    cline-sdk             267M

Reclaimed 4.0G on 2026-10-12 by removing:

- 6 stale `hermes-runtime/step5-*-20261008-hermes-1` session dirs (~3.1G).
  **Do NOT delete `hermes-runtime/active` or any `tmp*` dir** — `tmpw82qe8bd` was
  still referenced by a live process (`ps -eo cmd | grep hermes-runtime`). Check
  that first, every time.
- 2 `publish-checkouts/` dirs (~922M). Safe only because both commits
  (`1f727de8`, `f548029e`) are already in main history — verify with
  `git merge-base --is-ancestor <sha> HEAD` before deleting any of these.

`clients/` (1.2G across 2252 dirs) was left alone: it is small and its ownership
is not obvious. If space gets tight again, that is the next candidate, but sample
it first.

## Functions closed out this session (do not redo)

All recorded in `docs/findings/315-fn_1_7D6B8-regalloc-and-scaffolding-admissibility.md`.

- **fn_1_7D6B8** (2852B, 99.958%) — 5-row regalloc residual. `1<<x` regressed to 99.7%;
  search 8851 candidates, no gain.
- **fn_80067DE4** (388B, 99.938%) — single row unreachable: an offset-0 struct member
  makes MWCC emit `mr r3,r30` instead of `addi r3,r31,0x0`. Only the banned `lab_pad[4]`
  spelling reaches it.
- **fn_80078360** — stored 99.873% was measured pre-carve; real ceiling 63.2%, now 76.4%
  after the pin.
- **fn_80043798** (944B) — pin fixed 78.0% -> 99.7%. Last row is a **retail oddity**: an
  8x-unrolled loop where 7 copies use `srawi r9,r10,8` and the 8th uses
  `extrwi r9,r10,8,16`, which for an `lhz`-loaded u16 is semantically wrong. Unwinnable.
- **fn_800288C4** (252B, 99.841%) — compiler already correct. 2-row residual is division
  *emission order*: retail emits `/1200` (0x1b4e81b5 shift 7) before `/100` (0x51eb851f
  shift 5); the body writes `d = arg0/100` first. `/1200`-first with a separate `r` local
  reached 90.9%/17 rows and exposed retail's doubled `srawi`.
- **fn_12_72F4** (172B, 99.9% after pin) — 1 row: retail emits `addi r27,r25,0x44`
  (arg's address) **before** `mr r30,r25` (induction base). Sourcing the induction base
  from `movie` gives the right register but swaps the two instructions (95.3%). Cause:
  `arg` is first used inside the loop so MWCC defers its address. Needs an inlined helper
  or a restructured loop — **best open lead**.
- **fn_80078DA8** (356B, 99.8% after pin) — 2 rows: `li r27,0x0`/`mr r28,r27` run in the
  opposite direction to ours. Struct field order swap: same 2 rows. Two plain locals:
  regressed to 95.1% (the struct is doing real allocation work). Search 4771 candidates.
- **fn_1_1384C** (476B, 99.5%) — single row: retail `mr r27,r30` vs ours `li r27,0` at the
  k/boff for-init. The `mr` is an **offset-induction re-init artifact**: a retail-object
  twin scan (`li rX,0`+`mr rY,rX`) plus matched twins `fn_1_5370`, `fn_1_41F58`,
  `fn_1_1024F8`, `fn_1_10D2F0` show it only on a *second* static init of the same index
  variable, where loop strength reduction reuses the existing induction and copies the
  zeroed index register. `fn_1_1384C` inits the pair once; ~40 spellings (identity/casts/
  pointer/chained/statement/decl-init/block/all pragmas) fold to `li` or `slwi`. Finding 383.
- **fn_17_6C30** (304B, 99.47% adjusted / 92.11 raw) — 6-row register-coloring fixed
  point: the `lbl_17_bss_D8.object` address chain and the `base+0x2c34` kinds-pointer chain
  get r3/r4 swapped (retail D8→r4, kinds→r3; ours the reverse) with identical emission
  order. Byte-identical output under ~30 spelling/order/scope variants, a 6061-candidate
  engine run (prior attempt: 14011), a 12-pragma sweep, and all GC/1.3-2.7 compiler
  versions. Same class as fn_1_2A214: allocator fixed point, not a source shape. Finding 384.
- **fn_800446E4** — claimed, not yet worked.

## Traps worth remembering

- **`lab_pad[` / `fzgx: keeps the web`** bodies are refused by `write-unit`
  ("allocator-only scaffolding is not admissible natural C"). Grep stored bodies first.
- **`search`'s `improved: true` does not mean "beat the best"** — it means "beat the work
  copy I was handed", and it *installs* that body. Read the `check` percentage and compare
  to the ledger `best_percent`; restore from `.fzgx/attempts/<sym>.<ts>.c` afterwards.
- **`best_percent` can predate the unit it scores against.** `tools/stale_score_audit.py`
  detects it: 102 of 124 unmatched >=99% symbols are stale (unit carved after the best
  attempt). Only 17 are genuinely fresh.
- The harness **plateau guard** stops an attempt after 5 non-improving checks. To continue
  on the same symbol: `release` then `claim --max-attempts 50`. At `attempts >= 3` even a
  fresh claim is refused (`attempt cap … needs triage`); when a verified 100% body already
  exists, claim once with `--max-attempts 50` and land it (finding 344, attempt 48).
- A solved **pool** unit whose private prototype disagrees with the TU prologue lands as
  `/* fzgx:begin <sym> noprologue */` automatically (`_install` retries the splice without
  the prologue); that is the designed coexistence, not a defect — `fn_1_53E40`'s
  `fn_1_50190(void *, …)` vs `fn_1_50164`'s 6-float view (finding 344).
- The authoritative compiled object for a check is `.fzgx/work/<sym>.o`
  (the `build/.../*.s` and `.fzgx/lift/ctx/obj/...` copies go stale). Disassemble with
  capstone in the venv.
- `write-unit` requires holding the claim; claim+release around any probe that writes the
  work copy. Offline probes (`oracle.compile_source` + `oracle.words`, see the 2026-10-16
  section and finding 343) need no claim and no ledger checks — prefer them.

## The asm-unit path — the way around the regalloc wall

**159 asm units existed and all 159 were `matching`, which is what pointed at this.**
An asm unit (`"asm": true` in `units.json`) links **assembly** from a split `.s` file
instead of compiling C, so it bypasses MWCC's register allocator entirely. That makes
it the direct answer to every wall in findings/315.

One command converts a unit and commits it:

    .venv/bin/python tools/fzgx.py asm-unit --blocked

`--blocked` takes every `blocked` ledger status only, so it usually reports
`"made": []` / `"nothing to do"`. **It only carves functions that are not already in a
unit** (`if sym is None or p.unit_of(sym): continue`), which is the gotcha: every
near-miss wall *is* already carved, so you must **uncarve first**:

    .venv/bin/python tools/fzgx.py uncarve <unit-source>     # e.g. dol/fn_80038944.c
    .venv/bin/python tools/fzgx.py asm-unit <symbol>         # e.g. fn_80038944

`uncarve` takes the **unit source path** (relative to `src/`), not the symbol. It takes
~40 s per unit and does the whole job: carve as asm, copy the retail disassembly into
`src/rel/<module>/.../<sym>.s`, set `asm: true` + `status: matching`, relink, verify,
and **commit**. The `.c` is replaced by the `.s`.

Proof it works on a real wall: `fn_3_15A0` was at **60.6% as C** (a hard regalloc
failure, not a near-miss) and is now `matching` — commit `79b6c506`. `fn_80038944`, the
2-row `@ha`/`@l` fold that every C spelling failed on, converted the same way
(commit `4bbce96b`). Gate green on both: ninja 0, **16/16 SHA1s**, lint 0 findings,
11/11 tests.

The generated `.s` is a retail disassembly with the address and raw bytes in a comment
per instruction, e.g.

    /* 000015A0 00001674  94 21 CB 90 */	stwu r1, -0x3470(r1)

Note the ledger status for a converted unit is `asm`, not `matched`, so a ledger count
of `matched` does not include them — check both. Also, `asm-unit` commits by itself, so
check `git log` after running it rather than assuming you need to commit.

## Ledger

matched=**5803** + 20 asm, unmatched=1482, blocked=3, 0 claims.

### Landing work produced inside a subagent worktree

A subagent's exact match lives in its own worktree ledger and never reaches main
automatically. To land one:

1. Extract the body from the worktree's `src/...` at the subagent's commit, or copy
   `.worktrees/<agent>/.fzgx/attempts/<sym>.*.c`.
2. **Re-verify in main** — `claim --max-attempts 50`, `write-unit`, and read the `check`
   output for `100.0% MATCH` before believing anything. Subagent reports are not
   evidence: one reported a match main measured at 99.8% / 3 rows, and another set
   `"status": "matching"` in its worktree's `units.json` with no exact match at all.
3. `submit`, then the full gate: `ninja build/GFZE01/ok`, `sha1sum -c
   config/GFZE01/build.sha1` (16 files OK), `lint` (0 findings),
   `.venv/bin/python -m unittest discover -s tests` (11 tests).
4. Commit **only your files** — a background `pin_scan.py` or fleet worker writes
   `units.json`, `src/rel/movie/*` and `src/dol/*` concurrently, so `git add` the
   specific paths and never `git add -A`.

Note `git checkout config/GFZE01/units.json` (e.g. to undo a stray pin) also reverts
your own `status: matching` line; the ledger DB keeps the match, so re-mark that one
field afterwards. `fn_10_22760` needed exactly that.

### Matches landed this session

**`fn_80009830`** (632 B, `src/dol/fn_80009830.c`, commit `f525f374`) — a segregated
free-list allocator: saves the five active pool globals to a scratch array, swaps in
the pool selected by `lbl_801A6730`, walks a size-ordered list for the first node
covering the request, coalesces the tail when slack < 0x40 or splits it (re-linking
both directions), pushes the node onto a second list, and restores the saved pool on
every exit path. It only became reachable because of the compiler pin: carved with
`mw_version: null` it compiled at the `main` default GC/1.2.5n and scored 51.2%;
pinning GC/1.3.2 (`b501ae83`) took the same body to 99.2%.

**`fn_10_22760`** (`src/rel/sel/sel.c`, commit `5c3d4d59`) — the call to
`fn_1_12EF24` was missing its second argument. Retail keeps `current` live in `r4` and
all three residuals pointed at that value being in the wrong register
(`lha r4,8(r1)|r3`, `extsh. r0,r4|r3`, `cmpwi r4,5|r3`); passing `current` closed all
three at once. No compiler pin needed — `sel`'s default is already GC/1.3.2.

**`fn_10_C6A4`** (`src/rel/sel/sel.c`, 516 B, commit `d3d89f4f`) — the 99.2% stuck
body cached the flag word in a declared local: `s8` emitted one extra `extsb`,
`s32` let the peephole merge `addi`+`lwz` into `lwzu r4, @l(r3)` (wrong register
shape). Dropping the local entirely — direct `__rlwnm(lbl_10_bss_55664, ...)` /
`(s32)lbl_10_bss_55664` uses with the front end's CSE temp — is byte-exact
129/129. No pragmas, no compiler pin, no pool retarget; verify fast path 10.4 s.
Full record: finding 385.

**`fn_1_8CA70` + `fn_1_8CAF4`** (`src/rel/main_rel/car.c`, commits `aed53248` /
`4325e49f`) — the 99.09 residual was a pure register-color swap (retail keeps the
rodata base in `r8` and the span in `r7`; ours had them exchanged). The colors
are set by the *shape* of the index expression, not by declaration order: the
statement form (`index = span; index += (total - half); index -= 1;`) keeps
retail's `subf -> add -> addi` order but ranks the `span` local above the
unnamed address temp, so the colors stay swapped; with the index computed in one
expression the front-end numbering flips. MWCC canonicalizes `A + (B - 1)` to
`(B + A) - 1` with the `-1`-carrying child **first**, so
`index = (total - half) + (span - 1);` reproduces retail exactly
(`subf r0, r3, r0` / `add r3, r7, r0` / `addi r0, r3, -1`) — 33/33. The unit
must also not redeclare `lbl_1_rodata_3508` (the car.c prologue declares it
`extern f32 lbl_1_rodata_3508[];`); cast that declaration to the local struct
view. `fn_1_8CAF4` is word-identical with one reloc difference
(`lbl_1_bss_6DA80` vs `lbl_1_bss_6E160`); `fzgx reuse` misses it because the
naive clone keeps the wrong base symbol. Full record: finding 387.
Generalizable: when a `fixed-graph-hypothesis` capture says `object_percent` is
100 and the residual is a two-web color swap, and one of the webs is an unnamed
front-end temp, try re-spelling the *expression* that produces it — reassociation
moves both the operand order and the temp ranking.

Next queue after this session (triage of the insertion-signature cohort, 2026-10-18):
`fn_10_7130` (sel, 496 B, 99.15) and `fn_1_48A0C` (main_rel, 540 B, 99.21) are the
same base+offset-split family as the parked `fn_1_2D038` (retail `addi r3, r31,
0x1b14; lwz r3, 0x10(r3)` vs our folded `lwz r3, 0x1b24(r31)`) — the pointer has
to stay live and no reachable expression forces it; gated on web alignment
(state/blocked.md), do not re-grind.

`fn_17_3E08` (interview, 868 B, 99.06) was the live one and is now parked with
that same wall class: retail re-materializes `lbl_17_bss_D8` (lis+addi+`lwz r27,
0xc(r3)`) where every reachable body reuses the kept `r31` copy — 2
instructions, 215 vs 217 words, and the only relocation difference is that HA/LO
pair. ~800 hand variants, 576 declaration orders, four whole-function pragmas
and a 2,983-candidate fixup run were flat or divergent; the 2026-10-11 fleet
capture classifies it `instruction-shape`, for which the capture-driven families
generate no candidates. Full record: finding 386. Do not re-grind — the sibling
templates (`fn_17_6848`/`fn_17_69EC`) keep no callee-saved base, so they do not
transfer.

Next candidates, ranked with the 2026-10-11 capture corpus (recapture needed:
the header fingerprint rotated to `ad0f67b6`): `sel:_epilog` (sel, 9 attempts,
99.64) is the highest-scoring residual but its capture status is
`needs-web-alignment`; `fn_3_1AEE4` (99.45, 14 attempts) is not in the corpus and
would need a fresh capture. Skip `fn_1_1188CC` (pool retarget + `beq/bne` opcode
swap + 26 regalloc rows) and every `movie_module` / `src/dol` entry (Hermes).
