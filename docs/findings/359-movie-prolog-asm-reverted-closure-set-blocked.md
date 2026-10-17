# Finding 359: movie:_prolog asm landing reverted; the narrow-store wall is a complete measured closure set — triage-blocked, not escaped

Measured 2026-10-16. This corrects finding 358's escape and answers the owner's
steer: *"does it need to be asm? the goal is c functions"*. It does not need to be
asm. Finding 301 already says for this class: *do not convert them to asm units
(the project goal is matching C)*, and the matcher contract bans inline asm by
tooling. Commit `7fa25826` remains in history as provenance; the unit is back in
the retail auto object and the 16-target hashes are green.

## What closes the case (all offline; zero ledger checks)

Residual: with the u32 extern body, byte-exact retail except one word — retail
`sth r11, 0(r10)` vs our `stw r11, 0(r10)` at word 87 — 99.21875%.

Every family measured, with controls:

| family | result | what it proves |
| --- | --- | --- |
| any narrow direct lvalue — s16 extern (file scope, function scope), u16 extern, volatile, struct view, `*(s16 *)&sym`, pointer var, `!!`/cast/ternary bool forms, comma-expression DAG grouping of the ptr stores, inline helper | 88.28125% `[74..87, 89, 90]` | narrowness re-phases the 7 lis / 7 addi materialization window; volatility and grouping do not pin it |
| value-into-local split, store moved after the pointer stores — s16/s32/u16/**u32 control** | 57.03125% identical at every width | the long-lived named local damages allocation; width-independent, family dead |
| source reorder (ptr stores before the 96A store) — s16 and **u32 control** | 46.875% both | retail's pair order pins the 96A store's materialization first in source order |
| statement moves / live-chain edits | 46.9% and worse | position of the store statement is pinned |
| compiler sweep | GC/1.3 → 70.5%; GC/2.0/2.5/2.7 → 88.28% | no version reproduces retail phasing under a narrow store; retail's own phasing is what the u32 DAG coincidentally orders |
| inline asm | banned by matcher tooling | not a C path |

Structural paths checked off:

- **Region-crossing unavailable**: `config/GFZP01/config.yml` declares
  `files/fze.movie_module.rel` with hash `a53cb77e…` — identical to the US disc's
  `movie_module`; the unit lives in US-only `fze.movie.rel` (hash `08a6cc86…`),
  which has no PAL counterpart. PAL has nothing to diff.
- **Sibling checked, unrelated**: `movie_module:_prolog` is a fully matched C
  unit — a function-pointer-table initializer (`src/rel/movie_module/_prolog.c`);
  shares only the symbol name.
- **Corpus spelling**: matched writers of `lbl_1_bss_96A` elsewhere
  (`main_rel/_prolog.c`, `ranking.c`, `option/_prolog.c`) all store immediates:
  no bool-arithmetic narrow-store idiom exists in matched C to borrow.

Tooling gaps found while uncarving (both fixed in `tools/fzgx/uncarve.py`):

1. asm units record a `.c` source name but link from the `.s` split assembly;
   `uncarve` missed the sibling `.s` — now unlinks it when `asm: true`.
2. `uncarve`'s ledger clear used `p.resolve(s)` on bare units symbols; ambiguous
   names (`_prolog`) resolve to None and the fallback wrote a bare key that
   matched no row, silently leaving `unit`/`link_state` set and the `asm` status
   behind the removed unit. Units' bare names now resolve through the unit's own
   module (`module:name` keying).

## Current state

- `fzgx uncarve rel/movie/_prolog/_prolog.c` removed the unit entry, split range
  and split assembly; `movie.rel`/`movie.plf` rebuilt inside uncarve's
  reconfigure; `ninja build/GFZE01/ok` → 16 files OK; lint 0 findings; 11 tests OK.
- Ledger: `movie:_prolog` status `blocked` (23 recorded attempts ≥ 3 → triage),
  `unit`/`link_state` cleared, reason above.
- Best measured C archived at `.fzgx/attempts/movie:_prolog.1791747343.c`
  (99.21875%, one word); the asm `.s` lives in history (`7fa25826`) if the owner
  ever wants it restored deliberately.

## What reopens it

- A matched C somewhere in the corpus containing bool-materialized
  narrow-store-plus-heavy-materialization phasing — search retail for
  `srwi`+`addi`+`sth` idiom clusters in matched TUs before believing none exists.
- A DAG lever outside the measured table, with an argument for why it differs.
- Un-discovering some source-truth shape in the surrounding REL that changes the
  alias cluster around `lbl_1_bss_960..96C` in this window specifically.
