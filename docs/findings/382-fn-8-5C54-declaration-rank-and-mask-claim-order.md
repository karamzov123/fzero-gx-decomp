# 382 — fn_8_5C54 landed: two rank levers (the counter declared *last*, and `& 0xFF` over the `(u8)` cast) close a two-web claim transposition

Session of 2026-10-18 (opencode manual CLI, agent `deepseek-opencode`).
Closed a **6-attempt / 16k-permutation plateau** in one counted check on
attempt 7: `write-unit` `100.0% MATCH`, submit `link: pending`, verify fast
path 10.7 s (`16 files OK`), commit `351b536c`.

## The state before this session

`fn_8_5C54` (title, 896 B / 224 instructions, unit block of
`src/rel/title/title.c`) had six ledger attempts. The frontier came from
`fleet-v2-oc1-…` (attempt 21492, 3 checks, 99.50893 raw / 92.41 adjusted):
**17 register-only rows**, with the diagnosis already exact —

> "Body is exact except a pure allocator rank transposition of two webs: this
> compiler always ranks the loop-carried counter n at slot 11 (r21) and the
> CSE'd (u8)n slot index at slot 4 (r28), while retail ranks them 2 (r30) and
> 11 (r21) … no C-level restructuring reproduces retail's ordering"
> (16k+ mechanical permutations through `fzgx fixup`).

Re-deriving the claim orders this session (saved-register claims r31..r17, in
claim order) confirmed it is *exactly* a swap:

```
retail: a n arg iB &2AC &2B0 count entry acc infoptr clr1 i j iRD8 i&2AC
ours:   a arg iB clr1 &2AC &2B0 count entry acc infoptr n  i j iRD8 i&2AC
```

The other thirteen webs sit in identical relative order in both; only `n`
(loop counter, wants slot 2) and `clr1` (the `(u8)n` slot index, wants slot 11)
occupy each other's slots.

Why the engine could not find it: `fixup_source.py`'s declaration search is
only exhaustive for **≤ 5 locals** (`every permutation`, else
`reverse + adjacent swaps` — line 804); this body has 12, and the winning
position (the **last** slot) is not reachable by reverse/adjacent swaps. The
mask spelling is outside its rewrite families entirely.

## The two levers

Relative to the saved body (`.fzgx/attempts/fn_8_5C54.1790881991.c`):

1. **Declare `n` last** — move `s32 n;` from the 5th declaration to the final
   slot (after `s32 tmp_RD;`). This ranks the loop-carried counter above the
   other named locals, so it claims the first saved color after `a`:
   `n → r30` ✓, and `arg`/`iB` slide into 3/4 (r29/r28) ✓. Everything after
   still shifts one color down (40 rows, all register cascade).
2. **Spell the byte truncation as a mask** — `k = n & 0xFF;` for the slot
   index **and** `k < (n & 0xFF)` for the second loop bound, instead of
   `(u8)n`. Measured on the base body, the mask form alone moves `clr1` from
   slot 4 (r28) to slot 11 (r21) with the whole middle band re-seating behind
   it (44 rows, pure cascade); the cast form's conversion node ranks the
   truncated web **early**, the AND node ranks it **late**.

Applied together the claim order becomes retail's exactly, and the body is
224/224 words (`differing_rows 0`).

## Measured cohort (offline screen, positional word diff vs the retail obj)

| variant | raw % | rows | what it fixed |
|---|---|---|---|
| base (oc1 frontier) | 99.509 | 17 | — |
| `g1` n declared last | 98.97 | 40 | `n → r30`, `arg r29`, `iB r28` |
| `c1` `k = n & 0xFF` | 98.84 | 44 | `clr1 → r21` (slot 11) |
| `g1 + c1` | 99.866 | 4 | only `clr2`/`k` swapped |
| `g1 + c1 + u8 total` bound | 99.866 | 4 | same swap — a named `u8` bound does **not** do it |
| **`g1 + c1 + (n & 0xFF)` bound** | **100.0** | **0** | ✓ |

The last four rows were `0x2BC/0x2CC/0x2E8/0x2F4` (`clrlwi` of the bound,
`li k`, `k++`, `cmpw`): with the cast bound the bound-value web claims `r21`
and `k` falls to `r18`; the mask bound reverses exactly that pair.

Non-movers worth recording (all measured, all no-ops): every mask/slot spelling
alone (`u8 slot` local at four declaration positions, bound via `n & 0xFF` or a
`u8 total`, distinct temps vs the reused `tmp_RD`, thirteen dead uses
`(void)x;`, `n_2` split for the tail); `n` declared **first** or in a middle
slot; `n`/`k` swapped; `u32 tmp_RD`; reversed compare spelling. The
**declaration-initializer** form (`s32 n = 0;`) is forbidden: it hoists the
`li` into the declaration region and destroys the schedule (91 rows).

## Evidence chain

- Offline: `/tmp/opencode/5c54/v3/gc2_nlast_both_and.c` — 224/224 words,
  `matched=True`, `percent_adjusted 100.0`, `pool []` (no retarget needed).
- Claim attempt 7 (`--max-attempts 50`); the `write-unit` auto check is the
  only counted check (`oracle match accepted automatically`). The 47-variant
  screen (three batches, `compile_source` + `word_score`) consumed none.
- `fzgx verify`: fast path 10.7 s; `16 files OK`; commit `351b536c`
  "match: 1 functions link-verified (fn_8_5C54)" — carries the spliced block
  (`src/rel/title/title.c` `fn_8_5C54`) and the `units.json` status flip.
- `fzgx lint`: 0 findings.

## Rule for the corpus

When a residual is a **pure claim-order transposition** of two webs in an
otherwise word-perfect body, the remaining levers are not expression
permutations — they are:

1. **the declaration slot**: for a named local, only the *last* declaration
   slot was measured to out-rank the earlier ones (first/middle slots were
   no-ops on this body), so try `last` explicitly rather than relying on the
   ≤5-local permutation sweep;
2. **the IR spelling of truncations**: `x & 0xFF` and `(u8)x` emit the same
   `clrlwi`, but the AND's web claims a **late** saved color and the cast's
   web claims an **early** one. Measure both spellings wherever a masked or
   truncated value is allocated to a long web — including the *loop bound*,
   which allocates its own web.
