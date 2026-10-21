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
3. `selective`: the ref's unit with **only the ref's headers missing here** inlined; includes
   that resolve here stay, so hardware and SDK declarations come from our own headers. Up to
   ten repair rounds follow, driven by the compiler error: `+swap` inlines the ref's version
   of one of our headers that declares an identifier named in the error (never a header our
   TU prologue includes: the generated unit includes ours first and the copies clash there);
   `+fix` injects a ref-only type definition, drops the ref's `extern` that redeclares a
   symbol we declare differently, rewrites `sym` as `(T)&sym` where the ref declares an array
   and we declare a struct, or gives one local the ref's struct as `<Type>_dw` when our struct
   lacks a member;
4. `preprocessed`: the ref's unit expanded by MWCC `-EP` inside the ref's own tree, pragmas
   preserved, trimmed by `reuse.declaration_closure`. Usually refused by lint (hardware
   `volatile`s, float bit patterns, inlined asm helpers), so it is tried last.

Every candidate gets the ref's symbol names rebound to this tree's names by (module,
section, address). A candidate is accepted only if it is a full-oracle or pool match, lint
clean, free of allocator scaffolding, and (for a TU block) does not compile to different code
under our TU prologue (`gen`: a compile error there is fine, `_install` keeps the block
`noprologue`). Accepted bodies go through `claim` → `write_unit` → `submit` (retrying while
`fzgx verify` holds submit.lock). Provenance is recorded in `state/forkimports/<owner>.json`
(ref, candidate kind, compiler, body hash) and lists only functions the ledger still counts as
matched: the next `--land` drops what `verify` rejected. Screening results accumulate by symbol
in `.fzgx/harvest/<sha>-work/results.json`; statuses `lint` and `gen-mismatch` name matches
that were refused.

    uv run tools/fzgx.py harvest fork-deltawave784/windows-and-types \
        --label 'deltawave784/fzgx@13b0aeca (CC0)' [--symbol S ...] [--land]
    uv run tools/fzgx.py verify --message '...'

Forks checked on 2026-10-21 (by name and by module+address): only deltawave784's
`windows-and-types` holds matches we lack; its `codex` and `main` branches, pabloski2300,
nkhoit, nhawke, zeranemesis and the four forks of karamzov123/fzero-gx-decomp hold none.

## Status (2026-10-21): cloud workers parked

Anthropic's documentation says cloud sessions count toward the plan's usage limits and
share rate limits with all other Claude Code usage. The trial logs show `rate_limit_event`s
against the account. The owner wants cloud sessions only if they are outside those limits,
so the two trial routines (`fzgx cloud-1 trial`, `fzgx cloud-2 trial`) are disabled. Setup
was proven up to the toolchain unpack (orig copy, private release over REST, sha256);
installing `zstd` was the remaining fix and is in `bootstrap.sh`, still unexercised.

## Harvest outcome and leftovers (deltawave784/fzgx@13b0aeca)

445 functions landed and link-verified (`state/forkimports/deltawave784.json`), the last 8
through the selective/fix candidates above. The three DOL `#pragma optimize_for_size`
functions and the other former "object match, link mismatch" cases all linked once landed
alone; fn_1_10BA00's earlier failure was a `+swap` of `rel/main_rel/globals.h`, which the TU
prologue also includes (now pinned).

Left (20, bodies under `.fzgx/harvest/13b0aecab6ac-work/`):
- matches refused by lint (15): the fork's C needs its own inline-asm vector helpers (A3:
  fn_1_10846C, fn_1_113C58, fn_1_F6A8, fn_1_12D404), hardware `volatile`s or addresses
  (S2/A1: fn_1_11E98, fn_1_12BB18, fn_1_12FD4, fn_1_14B1FC, fn_1_30054, fn_1_ECF88, fn_3_106FC,
  fn_80068BFC), an unjustified `goto` (fn_8005D5A4), or allocator scaffolding (fn_1_65E8C,
  fn_3_169B8). Never silence these with `fzgx-allow`;
- near-misses (5): fn_3_E64, fn_3_130C8, fn_4_A82C, fn_8_5840 (about 98.5%), fn_3_6270
  (does not compile here).

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
