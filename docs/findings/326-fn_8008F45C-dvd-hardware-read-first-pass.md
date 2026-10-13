# fn_8008F45C (main): DVD hardware read, 46.8% first pass

Selected a carved-but-never-written unit (608 B, `main`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

A DVD/DI hardware read operation. It:
1. Disables interrupts
2. Manipulates DI hardware registers at 0xCC006800 base
3. Runs multiple command sequences via `fn_8008FC3C` with polling loops
4. Calls `fn_8008F9D8` for the actual read
5. Restores interrupts

## Key structural findings

- Compiler is GC/1.2.5n (not GC/1.3.2) — different from most main_rel functions
- Hardware registers accessed via `lis r25, 0xcc00` + offset loads/stores
- Polling loops use `cntlzw`/`srwi` pattern (test for non-zero return)
- Multiple repeated command sequences with the same structure

## Residual: hardware register access patterns, ~125 rows

The body reaches **46.8% raw**. The structure is partially correct but the hardware register access
patterns and polling loop codegen don't match. Probed issues:

- Frame size differs (0x78 vs 0x60) — retail uses more stack space for the command buffers
- `cntlzw`/`srwi` for boolean conversion of `fn_8008FC3C` return value
- `addi r30, r25, 0x6800` base pointer pattern for DI register access
- Hardcoded addresses (0xCC006800, 0xC0000000) cause lint failures

The `vu32 *` pointer approach with array indexing generates different code than retail's
`lis` + offset pattern. The polling loops (`while (func() != 0)`) generate `cmpwi`/`beq` instead of
`cntlzw`/`srwi`.

The body is at `.fzgx/attempts/fn_8008F45C.best.c`
(SHA-256 `583882cdcb947a57...`, full hash in `.fzgx/attempts/fn_8008F45C.best.json`), 46.8% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_8008F45C.best.c`, compiler GC/1.2.5n, no extra
command-line flags. Next steps: use `__DIRegs[]` extern array instead of pointer casts, find the C
pattern that produces `cntlzw`/`srwi` for the polling loops, and match the frame size by using the
correct number of local variables.
