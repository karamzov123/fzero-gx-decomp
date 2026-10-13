# fn_8004313C (main): entry validation and parsing, 78.1% first pass

Selected a carved-but-never-written unit (616 B, `main`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

An entry validation and parsing function. It:
1. Searches for a matching entry using `fn_8008023C` (two passes with different tags)
2. Validates the entry (alignment check, field range check)
3. Byte-swaps u16 and u32 fields using `clrlslwi`/`rlwimi` patterns
4. Stores swapped values to output parameters
5. Computes derived values (division, conditional adjustments)
6. Returns 0 or -1 based on validation

## Key structural findings

- Compiler is GC/1.2.5n (but check used GC/1.3.2 with `-use_lmw_stmw on`)
- `stmw r18`/`lmw r18` for register save/restore (10 registers saved)
- Byte swapping via `clrlslwi` + `rlwimi` (not `lhbrx`/`stwbrx` for u16)
- `stwbrx` for byte-swapped u32 store
- Division by signed s8 values (`divw` instruction)
- Sign-magnitude check via `srwi`/`add`/`srawi` pattern

## Residual: register allocation and byte-swap codegen, ~98 rows

The body reaches **78.1% raw**. The structure is largely correct but the register allocation differs
(50 regalloc rows). The byte-swap operations use different register assignments, and some of the
conditional branch structures produce different code.

The body is at `.fzgx/attempts/fn_8004313C.best.c`
(SHA-256 `418c0ccc128cc136...`, full hash in `.fzgx/attempts/fn_8004313C.best.json`), 78.1% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_8004313C.best.c`, compiler GC/1.2.5n, no extra
command-line flags. Next steps: match the register allocation for the byte-swap temporaries, use
`__builtin_bswap32` or inline asm for the `stwbrx` store, and align the conditional branch structure.
