# Manual matcher kit (scratch compiles only; nothing in the tree changes)

All three score by masked machine words (`oracle.words`), not objdiff: ~1 s for 700 variants.
Positional word counts are only meaningful when lengths match (`len=ours/retail`); when they
differ, read the real diff with `uv run tools/manual.py try SYM DIR -v`.

**Always pass the function's compiler** (the `compiler:` line of `fzgx check`). Without it the
module default is used, which is wrong for most DOL functions (GC/1.2.5n vs a unit's GC/1.3.2).

- `uv run python tools/manualkit/fast.py SYM DIR [MW] [FLAGS] [TOP]` rank every DIR/*.c.
- `MW=GC/1.3.2 uv run python tools/manualkit/perm.py SYM TEMPLATE OUTDIR 'TAIL' var:decl ...`
  exhaustive declaration orders: TEMPLATE contains `@DECLS@`, TAIL (with literal `\n`) is
  appended unpermuted. 7 variables = 5040 variants in ~4 s.
- `uv run python tools/manualkit/vsweep.py SYM1,SYM2,...` best saved body per symbol under
  GC/1.1 .. 2.7 (words per version).

TU `.bss` layouts (MWCC addresses a TU's objects off one section base; only offset 0 of an object
folds into a displacement, any other offset materializes the object's address: `addi rX, base, K;
lwz 0x10(rX)`). When retail shows that and ours folds, the unit must define the TU's objects:
- `uv run python tools/manualkit/bsslayout.py MODULE START END [ADDR=decl;decl...]` prints
  definitions for every retail `.bss` object in [START, END) in address order (`fzgx_obj_` names,
  unaligned dtk objects split into scalars, single-byte pads only where alignment would not place
  the next object) plus a `.fzgxpool` first-access primer. Override an address to split a dtk object
  that merges several retail objects (`OWNER__fzgx_offset_X` names).
- `uv run python tools/manualkit/bssmap.py MODULE FILE BASE [MW]` compiles FILE and lists each
  `.bss` symbol's offset against the address its name implies.
Then access each field by its object name (struct views through a pointer fold). Landed
fn_1_A1DCC, fn_1_A1964 (sound TU), fn_10_7130 (sel, 0x51B28 bytes of layout) this way.

**Rank the frontier by words, not percent.** Raw objdiff percentages hide how much is
left: 99.9% of 700 words is 3 words, 97% of 1200 is 36. `nearlist.py` compiles every
unmatched function's best saved body with its recorded compiler settings and sorts by
the *absolute* number of differing words, so the cheapest remaining functions come first
(and 600-body sweeps of a high percentage band stop looking attractive):
- `uv run python tools/manualkit/nearlist.py --min-percent 90 .fzgx/nearlist.json`

Pair it with `fzgx stuck --min-percent 90 --json`, which labels each body's residual
(regalloc / schedule / imm / ext / frame). Measured 2026-10-23: 137 bodies at >=90%, of
which the sub-5-word tier is ~24 functions and ~20 KB; the single largest is
`fn_1_7D6B8` (2852 B, 5 rows). Bodies whose residual is one `lis`/`ld` swap are
MWCC scheduler tie-breaks, not source errors (see docs/MWCC_IDIOMS.md).

Untouched functions and REL literal pools:
- `uv run python tools/manualkit/liftscan.py OUT.json [MW]` scores every lifter draft
  (`.fzgx/lift/ctx/SYM_total.c`) of an open function; rewrite the best ones by hand from the asm.
- `uv run python tools/manualkit/primer.py SYM FILE OUTDIR [MW]` adds the shared literal-pool primer
  to a native-literal body (literals inline, local aggregate initializers for word copies from the
  pool) so `...rodata.0` binds to the retail pool. Landed fn_1_DB268, fn_1_108BD0, fn_17_9314.
- `python3 tools/manualkit/simscan.py [MIN_RATIO]` lists open functions whose instruction sequence
  is >= MIN_RATIO (default 0.85) similar to a matched function in the same module. Derive the C
  from the matched unit's generated source; immediates/offsets, a removed loop or a parameter
  instead of a global are typical differences. Landed 7 this way on 2026-10-22 (fn_4_7DEC,
  fn_4_A0C, fn_1_5D020, fn_1_1FC98, fn_1_12277C, fn_3_5D84).
  For siblings with added or removed loops, widen the shortlist with
  `--min-gram 0.4 --min-length-ratio 0.5 --max-length-ratio 2`.
  These only change discovery filters; every derived body still needs the object oracle
  and all sixteen linked hashes before acceptance.
- `tools/manualkit/splitdata.py` (import it): `split(text, NAME, BASE, cuts)` splits a generated
  `static union { u32 w[N]; ... } NAME = {{...}};` data object at byte addresses, so a sibling can
  address a sub-table by its own object name (`addi rX, rData, 0x5f8`).

REL pool literals and register permutations (2026-10-26, accessory cloth family):
- `uv run python tools/manualkit/poollits.py IN.c OUT.c [POOLSYM]` turns `F(0xNN)`/`D(0xNN)` macro
  reads of a main_rel literal pool (default `lbl_1_rodata_7AB8`) into native literals; then
  `primer.py` makes MWCC's int->float conversion constants land on retail's pool slots
  (closed fn_1_110478 and fn_1_111980).
- `uv run python tools/manualkit/regmap.py SYM FILE [MW]` prints the retail->ours callee-saved
  register correspondence per 0x200-byte block. A uniform shift means one web is claimed in the
  wrong order; a block-local swap points at one loop's variables (separate loop counters per loop,
  loops as blocks vs inline helpers, decl order). Pair with `declsearch.py`.
