# F-Zero GX decomp session — state and handoff

Last updated: 2026-10-12 ~01:45 EDT. Repo: `/home/armandofm/projects/fzgx` (branch `main`,
fork `karamzov123/fzgx`). **Read this first in any new session.**

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

Already applied (commit `78b84514`), 11 units:

| symbol | default | pinned | score |
|---|---|---|---|
| fn_8006C7E8 | GC/1.2.5n 46.8% | GC/1.3.2 | 99.6% |
| fn_80041700 | GC/1.2.5n 72.2% | GC/1.3.2 +lmw | 99.7% |
| fn_800478C0 | GC/1.2.5n 73.2% | GC/1.3.2 +lmw | 99.7% |
| fn_80078DA8 | GC/1.2.5n 74.0% | GC/1.3.2 | 99.8% |
| fn_12_72F4 | GC/1.3.2 74.2% | GC/1.3.2 +lmw | 99.9% |
| fn_800446E4 | GC/1.2.5n 78.0% | GC/1.3.2 | 99.7% |
| fn_12_2F970 | GC/1.3.2 78.7% | GC/1.3.2 +lmw | 98.0% |
| fn_80078360 | GC/1.2.5n 63.2% | GC/1.3.2 | 76.4% |
| fn_12_A5C | GC/1.3.2 92.1% | GC/1.3.2 +lmw | 99.8% |
| fn_12_36208 | GC/1.3.2 94.5% | GC/1.3.2 +lmw | 99.7% |
| fn_12_29524 | GC/1.3.2 98.3% | GC/1.3.2 +lmw | 99.7% |

`fn_800288C4` correctly needs the **default** GC/1.2.5n (99.8%) — the scan rules
units out too, it does not assume a pin is always the fix.

A night scan over the remaining 95 unpinned >=99% units was launched
(`/tmp/ps_night1.log`, `tools/pin_scan.py --min-pct 99 --limit 95`). Re-run it if the
log is incomplete; results are additive to the table above.

## Disk / inode safeguard — IMPORTANT

`.fzgx/fixup` grew to **175G** and filled the disk to 94% (38G free). The cleaner is
`tools/fzgx/fixup_gc.py` — lossless (cold tar bundles, verified, originals removed;
reports/cache/captures never rewritten).

    # dry run first (default)
    .venv/bin/python tools/fzgx/fixup_gc.py --min-age-hours 1 --max-files 20000 --max-sessions 4
    # apply, background, NO timeout wrapper
    .venv/bin/python tools/fzgx/fixup_gc.py --apply --min-age-hours 1 \
        --max-files 20000 --max-sessions 2000 \
        --status /home/armandofm/.cache/fzgx-agents/storage-night.json

`fzgx-storage.service` / `fzgx-storage.timer` are systemd-user units meant to run this
every 10 min. **Verify they are actually enabled and firing** — they were not, which is
how 175G accumulated:

    systemctl --user list-timers fzgx-storage.timer
    systemctl --user status fzgx-storage.service

If the timer is dead, that is the real fix; re-running the GC by hand only treats the
symptom. Check `df -h /` before starting any long run.

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
- `write-unit` requires holding the claim; claim+release around any scripted probe.

## Ledger

matched=5762, unmatched=1542, blocked=4. No new matches landed from manual work this
session — the value so far is corrected measurements and 11 compiler pins.
