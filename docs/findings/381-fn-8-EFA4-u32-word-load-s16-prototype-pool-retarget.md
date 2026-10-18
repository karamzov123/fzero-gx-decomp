# 381 — fn_8_EFA4 landed: the u32 word load and the s16-prototype call shape (an `s8` header artifact blocked both)

Session of 2026-10-17/18 (opencode manual CLI, agent `deepseek-opencode`).
Closed a 3-attempt plateau in **one counted check** on attempt 4: `write-unit`
`100.0% MATCH`, submit on the compile-and-retarget path
(`pool_map {...rodata.0→lbl_8_rodata_408, @37→lbl_8_rodata_AF8,
@38→lbl_8_rodata_B00}`), verify fast path 3.69 s (`16 files OK`), commit
`fd68a52a` (the same drain also link-verified Hermes's `__pformatter`).

## The state before this session

`fn_8_EFA4` (title/name_entry, 2624 B / 656 words) had four ledger attempts:

- `tuclose-luna-codex-22` (2 checks): 0.0% — 913 differing rows, frame/allocation
  and conversion shape dominated.
- `all-none-workers-…-codex-1092` (16 checks): 89.47%.
- `import-repair-archives`: 93.03% body recovered from the archives.
- `hermes-sol-manual` (14 checks, released): the real frontier — 99.0 raw /
  **99.85 adjusted**, with **four residual rows** in the sin-cursor image
  materialization/store scheduling (`target20cc..20d8`). Its note records two
  automatic searches promoting an **invalid `extern s8 lbl_801A66A0`**:
  1-row 99.3 raw / 99.8 adjusted is REJECTED — `lbz` replaces retail's `lwz`;
  a big-endian byte read is not a word read. "Do NOT promote that automatic
  best. Narrowing global forbidden."

That warning is correct, and this session re-derived the same conclusion: the
target word at the load is `80030000` (`lwz r0, lbl_801A66A0@l(r3)`); every
`s8` spelling emits `88030000` (`lbz`). The `s8` "improvement" is only the
adjusted score forgiving a row it must not.

## The three-line fix

Relative to the archived frontier body `.fzgx/attempts/fn_8_EFA4.1792273159.c`:

1. `extern s8 lbl_801A66A0;` → **`extern u32 lbl_801A66A0;`** — the symbol is
   `.sbss` size `0x4` (`config/GFZE01/symbols.txt:3090`); every matched sibling
   that reads it uses a word load.
2. `extern f32 lbl_8006D188(u32);` → **`extern f32 lbl_8006D188(s16);`** — the
   option twin's prototype (`fuzzy/GFZE01/option/fn_4_C768.c:334`); the callee
   consumes the rotation halfword.
3. `lbl_8006D188((u32)(s16)((lbl_801A66A0 << 8) & 0xFF00))` →
   **`lbl_8006D188((s16)((lbl_801A66A0 << 8) & 0xFF00))`** — the outer `(u32)`
   cast disappears (it was there to satisfy the old `u32` prototype).

The third edit is the schedule discriminator. With the correct `u32` extern but
the old call shape, the body still differs in the residual cluster (rows
470-474 — hermes's four-row sin-cursor materialization/store residual),
reproduced identically under **every** GC compiler 1.3.2-2.7 and across all
mask/cast/temp spellings tried offline; **only** the uncast `(s16)` argument
paired with the `s16` prototype is word-identical. Twin witness:
`fn_4_C768` line 529 carries the same call expression verbatim, and the twin is
where the shape was found.

## Evidence chain

- Offline: `/tmp/opencode/e4a/batch4/d6_exprproto.c` — 656/656 instruction rows
  identical (`differing_rows 0`, `percent_adjusted 100.0`).
- Claim (attempt 4, `--max-attempts 50`) consumed **0 ledger checks**; the
  `write-unit` check is `{"n": 14, "percent": 100.0, "adjusted": 100.0,
  "matched": true, "rows": 0}` with the oracle's own line "literal pool:
  private constants retargeted to the shared retail symbols".
- Submit carved the unit `rel/title/name_entry/fn_8_EFA4.c` (TU
  `src/rel/title/name_entry.c`, split `0xEFA4..0xF9E4`) and recorded
  `link: pending` + non-empty `pool_map` — the compile-and-retarget path, not
  the retail-linked `pool: true` fallback.
- `fzgx verify`: fast path 3.69 s; `[197/197] CHECK config/GFZE01/build.sha1` →
  `16 files OK`; commit `fd68a52a` "match: 2 functions link-verified
  (fn_8_EFA4, __pformatter)". Ledger row: `matched / verified / fd68a52a`.
- `fzgx lint`: 0 findings.

## Rule for the corpus

When a frontier is a single load-width row (`lwz` vs `lbz`) inside an otherwise
perfect function, the fix is **never** to narrow the extern: check `symbols.txt`
for the true width, then check the callers/twins for the **argument prototype**
that lets the compiler keep the wide value. The last mile here was the callee
prototype plus the uncast mask argument, not any expression permutation on the
load side — and narrowing `lbl_801A66A0` produced an out-of-band row that the
adjusted score hides.
