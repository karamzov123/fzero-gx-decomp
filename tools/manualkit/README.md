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
