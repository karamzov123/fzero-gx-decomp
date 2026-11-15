# Contributing

Everything in this repository goes through the same oracle: a unit is accepted when
every function in it assembles to the retail bytes, the data sections are equal, lint
passes, and the full link of all sixteen targets still hashes identical. That is true
for people and for agents alike, and the tooling is the same for both.

## The loop

```sh
uv run tools/fzgx.py sync                              # once: load the function inventory
uv run tools/fzgx.py inventory --module main_rel --status unmatched --max-size 128
uv run tools/fzgx.py claim fn_1_XXXX --agent <you>     # carves src/rel/main_rel/<tu>/fn_1_XXXX.c, prints the context bundle
# edit the unit (or: uv run tools/fzgx.py write-unit fn_1_XXXX --agent <you> --file body.c, which also checks)
uv run tools/fzgx.py check fn_1_XXXX                   # compiles the unit, diffs it against retail
uv run tools/fzgx.py submit fn_1_XXXX --agent <you> --message "what it does"
uv run tools/fzgx.py verify                            # relinks once, verifies every hash, commits pending units
```

`check` shows a `target | ours` instruction diff. `check --versions all` compiles under
every CodeWarrior version we ship, which is how per-unit compiler versions are recorded
(`--mw-version` on submit). If you give up, `release --reason "..."` keeps your best body
for the next attempt.

## Rules (enforced by `fzgx lint` and `submit`)

- No integer literal in `0x80000000..0x817FFFFF`, `0xC0000000..0xC17FFFFF` or
  `0xCC000000..0xCC00FFFF` outside `include/dolphin/hw_regs.h`. Every cross-reference is
  a symbol; the tree must stay shiftable.
- No inline assembly, no `.s` files for code. Unmatched code stays in decomp-toolkit's
  split objects.
- `goto`, `volatile` and codegen-only `union` need a one-line justification comment.
- Use the shared types: `#include "rel/<module>/globals.h"` and its recovered struct
  fields (`unk_XX` names are offsets, and the offsets are verified) instead of casts and
  pointer arithmetic on globals.
- Keep names as they are in a matching change. Renames go through `fzgx rename` or a
  naming proposal, which apply everywhere and relink-verify.
- Reference code adapted from Dolphin SDK decompilations is welcome; credit the source
  in `docs/RESOURCES.md`. Do not copy from projects without a licence.

Full rules: `docs/CODING_RULES.md`. Compiler idioms that unblocked functions before:
`docs/MWCC_IDIOMS.md`.

## Structure

- `src/dol/` — main.dol units; `src/rel/<module>/<tu>/` — REL units grouped by recovered
  translation unit (`config/GFZE01/main_rel/tus.json`).
- `include/rel/<module>/globals.h` — generated (`fzgx headers`), never hand-edited: regenerate.
- `config/GFZE01/` — decomp-toolkit configuration; `units.json` lists every C unit and is
  maintained by the tools.

## Agents

Agent runs are driven by `tools/orchestrate.py`, which spawns one headless harness
process per function with only the `fzgx` MCP server available (no shell, no other
tools), records real token cost in the ledger, and relinks once per batch. See
`AGENTS.md` and `.claude/agents/`. A pull request produced with agents is judged exactly
like any other: it matches, it passes lint, and it reads like code a person would write.
