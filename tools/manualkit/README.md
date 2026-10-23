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

Untouched functions and REL literal pools:
- `uv run python tools/manualkit/liftscan.py OUT.json [MW]` scores every lifter draft
  (`.fzgx/lift/ctx/SYM_total.c`) of an open function; rewrite the best ones by hand from the asm.
- `uv run python tools/manualkit/primer.py SYM FILE OUTDIR [MW]` adds the shared literal-pool primer
  to a native-literal body (literals inline, local aggregate initializers for word copies from the
  pool) so `...rodata.0` binds to the retail pool. Landed fn_1_DB268, fn_1_108BD0, fn_17_9314.
