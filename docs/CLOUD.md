# Cloud sessions and fork harvesting

Two sources of matched C that cost no local model time feed one landing path:

- **Other forks.** Independent contributors match functions in their own forks of the
  CC0 upstream (`rayanht/fzgx`). On 2026-10-21, `deltawave784/fzgx`
  (`windows-and-types`) held 465 functions matched there and unmatched here; 459
  passed this repository's oracle unchanged or after name rebinding.
- **Claude cloud sessions.** Routines run the normal workflow in Anthropic-hosted VMs
  and push their own session branch. Nothing from a cloud branch counts until the
  local harvest re-checks it against the oracle and `fzgx verify` passes all 16 hashes.

## Harvesting a ref

A harvest takes a git ref (a fork branch or a `claude/*` session branch), lists the
functions its `state/ledger.json` marks matched that are unmatched here, and tries
each one under the ref's recorded compiler and flags (`units.json`):

1. `raw`: the ref's unit text as-is, resolving includes against this tree;
2. `ours-prologue`: the ref's block under this TU's own prologue;
3. `preprocessed`: the ref's unit expanded by MWCC `-EP` inside the ref's own tree,
   pragmas preserved, trimmed by `reuse.declaration_closure`.

Every candidate gets the ref's symbol names rebound to this tree's names by (module,
section, address). Only full-oracle matches and pool matches go on to
`claim` → `write_unit` → `submit`. Provenance is recorded in
`state/forkimports/<source>.json`: ref, candidate kind, compiler and body hash.
Lint still applies, and `verify` still bisects and rejects link mismatches. Three DOL
functions compiled with `#pragma optimize_for_size on` matched as objects but failed
the DOL hash, so they stay unmatched.

## Status (2026-10-21): cloud workers parked

Anthropic's documentation says cloud sessions count toward the plan's usage limits and
share rate limits with all other Claude Code usage. The trial logs show `rate_limit_event`s
against the account. The owner wants cloud sessions only if they are outside those limits,
so the two trial routines (`fzgx cloud-1 trial`, `fzgx cloud-2 trial`) are disabled. Setup
was proven up to the toolchain unpack (orig copy, private release over REST, sha256);
installing `zstd` was the remaining fix and is in `bootstrap.sh`, still unexercised.

## Harvest outcome and leftovers (deltawave784/fzgx@13b0aeca)

437 functions landed and link-verified (`state/forkimports/deltawave784.json`). The
"preprocessed" candidate pastes the fork's expanded headers into the body, so lint
refuses it (hardware `volatile`s, float bit patterns, Shift-JIS data). Most of those were
recovered by inlining **only the fork headers missing here** and keeping includes that
resolve in this tree. A few more needed the SDK `include/dolphin/os/OSFastCast.h`
(imported), a fork struct under a `_dw` name for one view, or `(T)&sym` where the fork
declares an array and this tree declares a struct.

Left for a later session (bodies under `.fzgx/harvest/`; screening scripts are not committed):
- near-misses after fixes: fn_1_30054 (98.5%), fn_1_14B1FC (98.5%), fn_1_F6A8 (91.9%),
  fn_1_10846C (84.5%), fn_3_E64, fn_3_130C8, fn_4_A82C, fn_8_5840 (about 98.5% each);
- still not compiling against this tree's declarations: fn_80068BFC, fn_1_11E98,
  fn_1_ECF88, fn_3_106FC, fn_1_113C58, fn_8005D5A4;
- object match but link mismatch: fn_8006B224, fn_8006B92C, fn_8006BC1C (DOL,
  `#pragma optimize_for_size`), fn_8007F508, fn_1_9AABC, fn_1_A5594, fn_1_10BA00.

## Cloud session setup

A cloud session needs both repositories attached: this one and the private
`karamzov123/fzgx-build`, which holds `orig/GFZE01` and the `toolchain-*` release.
The VM's GitHub proxy only serves attached repositories, and its Trusted network
list leaves out `files.decomp.dev`, so `configure.py` cannot download tools there.
`tools/cloud/bootstrap.sh` copies `orig/`, unpacks the private toolchain release
(sha256-checked), configures, builds to `16 files OK`, and loads the ledger. The VM has
4 CPUs and 16 GB of RAM.

Seeds: `fuzzy/GFZE01/` publishes the best saved partial bodies with their compiler
settings, about 850 functions.

## Worker contract (cloud)

- Work only on the functions named in the routine prompt (disjoint per worker).
- After each verified match, run `fzgx snapshot`, commit, and push **only the
  session's own branch**. Never push `main`, never commit `orig/` or `build/`.
- Save an improved non-match as `cloud/partials/<symbol>.c` plus `<symbol>.json`
  (`mw`, `flags`, `percent`) on the same branch, so the next session continues from it.
