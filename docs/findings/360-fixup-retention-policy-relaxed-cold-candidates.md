# 360 — retention policy relaxed: historical fixup candidates are cold, hot set = report best + link evidence

Session of 2026-10-16 (opencode/GLM continuation), after the owner's disk
questions (`/` at 98%) and the measured record that the standing
`fzgx-storage.service` cleaner freed 0 bytes on every pass.

## Why the cleaner could never reclaim anything

`tools/fzgx/fixup_gc.py`'s hot-evidence rule preserved **every scored source**
(`plan()` added `cache.json` identity prefixes to the kept set "for seed
harvesting"), and `save()` writes `report.json` with `records = history` — the
full row list of the run, source paths included — so the sibling metadata rule
kept those same files hot again. Both rules together made 100% of a search
session's `sources/` + `objects/` permanently hot: 1627 closed sessions,
174.3GB, and candidate_files=0 on every pass *by design*.

Consumer audit (why cold storage is safe):
- `cache.json` rows carry score fields only — no bodies, no external readers.
- No code outside `fixup_gc` reads a session's old sources. `fixup.py`
  `record()` rebuilds the content-addressed `sources/<id>.c` from the body
  text it already holds (line 113), so an Engine re-run that lands an identical
  body self-restores by rewriting the file.
- `--restore ARCHIVE --session S [--member P]` returns any member byte-verified
  (restore() checks content sha256 against the manifest, refuses overwriting
  changed files, and guards the disk reserve).

## The policy change

In `plan()`:
- `cache.json` identity prefixes no longer join the hot set; only
  matched/link-rejected rows' complete **object chunks** stay hot (link
  provenance).
- `report.json` no longer feeds the generic metadata-reference rule (it spans
  the whole run history); its hot needs are the explicit `best` rows kept above.
- Other session metadata (`*.json`, small and deliberate) keeps its
  full-reference rule.

Module docstring updated to state: hot = per-symbol best rows, link-rejected
evidence chunks, and other-metadata references; historical scored candidates are
cold, byte-verified, and restorable.

## Validation against real sessions

- Before: same sessions reported `retained, candidate_files: 0` on manual and
  timer passes (2026-10-16 23:16–23:19 journal).
- After: `--dry-run` plans 20,000 candidates (per-pass `--max-files` cap) on the
  same sessions.
- First bounded apply (`--max-sessions 1`): `fn_1_135D7C` archived 20,000
  members into `.fzgx/fixup-archives/cbafe818…bed98.tar.gz` (content-hash-named,
  format `fzgx-fixup-cold-v1`, tool-side verified_files=20000), deleted the
  originals, +147MB free.
- Independent round-trip: manifest re-verified, `--restore` of two sampled
  members restored with `digest(path) == manifest member sha256`; hot set
  intact (`report.json` untouched, best-row source present).

The standing timer (every 10 min, `--max-sessions 2 --max-files 20000`) now
drains the backlog incrementally; a one-off wider pass (`--max-sessions 24
--max-files 100000`) was run manually on 2026-10-16/17 to accelerate it.

## Measured outcome of the first wide pass

23 sessions archived (+1 busy — the tenant timer was compacting concurrently and
its lease deferred that session, as designed), 2,400,000 files deleted, 18.33GB
of block bytes reclaimed; disk free went 18.9GB → 35.4GB mid-pass (33GB free
after archives settled). Per-session candidates are drained at the pass's file
cap (100,000), so large sessions continue shedding on later passes; the timer's
own passes drain the remaining backlog. Archive store grew 3.1 → 4.6GB (581
bundles) — the 18GB went into ~1.5GB of compressed verified bundles.

## Notes for future cycles

- Restored sample files stay on disk and re-archive on a later pass — the
  archive set is content-hash-named, so cycles are idempotent.
- The engine-side `guard()` (8GB write reserve) still applies on every
  generation; `--restore` uses its own smaller reserve check.
- No unit tests were added per repo contract; validation is the real-session
  A/B plus restore round-trip above.
