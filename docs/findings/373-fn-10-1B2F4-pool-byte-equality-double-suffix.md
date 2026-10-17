# 373 — fn_10_1B2F4 landed: the pool comparison needs the *whole* reached region byte-equal; two `d = <decimal>f` primes and an inlined-away primer were the only defects

Session of 2026-10-17 (opencode/deepseek, agent `deepseek-opencode`).
Closes the 99.26267% / `adjusted 99.08` plateau of `fn_10_1B2F4` (sel, 217
words, attempt 5). Retail's two remaining rows were the pool-base `lis`/`addi`
pair (`lbl_10_rodata_158` vs our `...rodata.0`); `pool_rows` was 9,
`pool_coverage` 0, and every saved body (seed, two fixup "bests") checked
identically. Landed in commit `7256d6b0` (`claim --max-attempts 50`,
`write-unit` auto-check `100.0% MATCH`, verify `fast_path`; gate: ninja no
work, 16 files OK, lint 0, tests 11 OK).

## The residual, exactly, and the reach rule

`_pool_rows` accepts the two base rows only when the compared slice of our
`.rodata` is byte-identical to retail's region at `lbl_10_rodata_158`. The
slice's length is **not** the function's own reads: it is the maximum positive
displacement through the *pool base register* across the whole instruction
list (all `lfs|lfd|lwz|lha|lhz|lbz|stw|stfs|stfd`, any base equal to the
register the `@l` row materialises), plus the access width, rounded up:
`lfs f2, 0xf70(r31)` → reach 0xf74. The seed had *two* extra discrepancies
inside that window that no row of the function itself exposes:

1. `d = 0.55f;` (pool+0x830) and `d = 0.49f;` (pool+0xB90) — the `f` suffix
   makes MWCC round the decimal to f32 and *then* widen to f64, giving
   `3FE19999A0000000`/`3FDF5C2900000000` instead of the exact
   `3FE199999999999A`/`3FDF5C28F5C28F5C` (9 bytes total).
   Dropping the suffix (`d = 0.55;`) reproduces retail's doubles exactly —
   MWCC's decimal parser is correctly rounded for f64 literals.
2. **The fixup session's own "best" was the worst body for the pool.** Its
   `inline helper at 14443` edits turned `fzgx_pool_prime66` into an unused
   `static inline` function; MWCC drops unreferenced inline functions, so the
   primer never emitted its `0.64f` literal and the word at pool+0x8E0
   vanished, shifting everything after it by 4 bytes (17 words wrong). The
   session's `score 100.0 / word_errors 0` measures the function's own words;
   `pool_coverage` was 0 for seed and best alike, so nothing in the session
   ranking could see the regression. **Never apply `inline`/unused-parameter
   helper fixups to `.fzgxpool` primer functions.**

With the two suffixes fixed, the *seed* body's `.rodata[0..0xf74)` matched
retail exactly — no other edits needed (verified by compiling both variants
and byte-comparing: 0 mismatching runs; 217/217 words).

## The scaffolding gate and the natural-C equivalent

`write-unit` rejected the body: `allocator-only scaffolding is not admissible
natural C` — `lint.allocator_scaffolding` flags `lab_pad[` and the literal
comment `fzgx: keeps the web at its definition`, i.e. the
`(void) p;  /* fzgx: keeps the web at its definition */` line the fixup had
inserted before the last `p = lbl_1_rodata_26F8;` copy. Removing that line
compiles to a **byte-identical object** (`.text` 868 B, `.rodata` 3960 B,
both equal to the with-line build): the line was not load-bearing for the
accepted body. Do not build non-natural C around it; try removal first.

## Landing mechanics

- The unit is a block of `src/rel/sel/sel.c` (`build/GFZE01/gen/...` holds the
  carve stub); `write-unit` splices after `verify`, no `noprologue` needed.
- `write-unit` check output: `100.0% MATCH` with the pool report
  `lbl_10_rodata_158=initializer[3956]` (the whole region) plus the three
  interior literals `lbl_10_rodata_1E8`, `lbl_10_rodata_158+0x44`, `+0x48`.
- `submit` recorded `pool_map`:
  `{...rodata.0 → lbl_10_rodata_158, @27 → lbl_10_rodata_1E8,
  @9 → lbl_10_rodata_158+0x44, @10 → lbl_10_rodata_158+0x48}`;
  `units.json` gained the same `pool` map with `status: matching`.
- `verify` committed `7256d6b0` (`config/GFZE01/units.json`,
  `src/rel/sel/sel.c`), `link_state: verified`.

## Reusable rule

Before spending checks on a "pool-blocked" plateau, compile the candidate
offline and byte-compare `ours[0 : (reach+3)&~3]` against retail from the pool
symbol — over the *reach window*, not just the literal offsets the rows show.
Doubles emitted from decimal literals must not carry an `f` suffix if their
low word matters; primers must stay non-inline; the `word_errors 0` fixup
score says nothing about the pool bytes behind the base rows.
