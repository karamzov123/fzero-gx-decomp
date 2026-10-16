# F-Zero GX decomp session — state and handoff

Last updated: 2026-10-16. Repo: `/home/armandofm/projects/fzgx` (branch `main`,
fork `karamzov123/fzgx`). **Read this first in any new session.**
(The 2026-10-12 sections below are still valid; the newest session state is in the
`2026-10-16 session state` section just below.)

## 2026-10-16 session state (opencode/deepseek)

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

**Free candidate probe (big time-saver, use it first).** Do NOT spend ledger checks to
test source shapes: `write_unit` AND `check` each consume one, and the plateau guard
trips at 5 non-improving checks (a tripped attempt refuses `write_unit` *before writing
the file*). Instead compile the candidate offline with the unit's own compiler/flags via
`oracle.compile_source(project, module, src, /tmp/…/x.o, mw, extra)` (mw/extra from
`project.unit_record(unit)`), then `oracle.words(project.target_object_for(sym))` vs
`oracle.words(obj)` and `oracle.word_score` — exact positional word diff, ~10 s per
shape, no claim, no work-copy writes. That method is how 343's table was produced.
Claim+release is only needed for probes that touch `.fzgx/work/`.

**Next candidates** (same one-word tier): `state/one_word_tier.json` — after fn_1_2D038
the ordering is `fn_1_135D7C` (callee-saved store-pair register, likely regalloc-wall),
`fn_1_4270C`, `fn_1_53E40` (structmap already refuted the field-offset reading in 286 —
look for *which pointer retail keeps in r31 where we keep a different one*). Probe one
shape list offline per function before claiming.

Not touched this session: the in-flight main-tree leftovers listed in the previous
handoff, the `fzgx-storage.service --max-sessions 2` question (still the user's call).

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
  on the same symbol: `release` then `claim --max-attempts 50`.
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

matched=**5764** + 20 asm (was 5762 at session start), unmatched=1521, blocked=3, 0 claims.

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
