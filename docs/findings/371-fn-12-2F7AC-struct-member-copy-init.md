# 371 — fn_12_2F7AC landed: local-struct member copies keep the `mr` that plain locals fold

Session of 2026-10-17 (opencode/deepseek, agent `deepseek-opencode`).
Closes the 99.0164% / one-word plateau of `fn_12_2F7AC` (movie_module, 61
words, attempt 18): retail word 5 is `mr r31, r6` (index = result right after
`li r6, 0`); ours emitted `li r31, 0` and every plain-local spelling folded.
Landed in commit `dd9ef50e` (`claim --max-attempts 50`, `write-unit` auto-check
100.0% MATCH, verify fast path 14s; gate: ninja 0, 16 files OK, lint 0,
tests 11 OK).

## What the fold is (and is not)

Probe-verified inert: `#pragma opt_propagation off` and `#pragma
opt_common_subs off` change **nothing** — still `li r31, 0`. The fold is not
the optimizer's copy/constant propagation; it is the frontend/allocator
re-materializing a known-constant value at the use. Source spellings that all
folded (1 diff, word 5): `index = result;` base, chained `index = result = 0;`,
`index = (result = 0);`, `index = (result = 0, result);`, comma statements,
single-decl multi-initializer `int result = 0, index = result;`, two separate
initialized declarations, goto-over-the-copy block boundary, temp copy
`{ int tmp = result; index = tmp; }`, plus the 1363 engine variants already
recorded in the claim context. Do not re-run this family.

## The fix

Hold the loop state in a small local struct; member copies survive:

    typedef struct { int result; int index; } loop_state;
    ...
    loop_state s;
    s.result = 0;
    s.index = s.result;      /* -> li r6,0; mr r31,r6 */
    ...
    } while (s.index < 15);
    return s.result;

61/61 words. Corroboration in the same module: matched sibling `mwSfdDestroy`
holds a hoisted constant-0 store value as `mr r30, r28` — a copy of the
just-zeroed counter (`li r28, 0; mr r30, r28` at its w51/52, source
`player->allocations[reverse_index] = 0;` in the loop). MWCC 1.3.2 really does
materialize 0 by copying a register already holding 0; member accesses of a
local struct are the source-visible way to keep that copy instead of a fresh
`li`.

## Method that found it

Scan matched siblings of the *same module* for the exact retail pattern
(`li rX,0` immediately followed by `mr rY,rX`) and read their sources — 649
matched movie_module functions produced exactly one hit (`mwSfdDestroy`),
which exposed the "copy of zeroed register" behavior. For selector questions,
the in-TU witness beats more permutations.

Files: best prior body `.fzgx/attempts/fn_12_2F7AC.1791747400.c`; landed body
`src/rel/movie_module/fn_12_2F7AC.c` (commit `dd9ef50e`).
