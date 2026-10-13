# fn_80049958 (main): streaming data processor, 8.9% first pass

Selected a carved-but-never-written unit (668 B, `main`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

A streaming data processor with virtual calls. It:
1. Gets an object pointer from a struct field
2. Enters a while loop processing data chunks
3. Calls virtual methods (vtbl->unk1C, vtbl->unk18, vtbl->unk20) on multiple objects
4. Uses memcpy/memset to manage data buffers
5. Tracks a running total across iterations

## Key structural findings

- Compiler is GC/1.2.5n (not GC/1.3.2)
- Division by 100 via `mulhw` with magic constant 0x38E38E39 (not 0x6667)
- Virtual calls via `lwz r12, 0x24(r5); mtctr r12; bctrl` pattern
- `stmw r19`/`lmw r19` for register save/restore (not _savegpr)
- Nested loops with different increment patterns (0x4, 0x2, 0x8)

## Residual: virtual call codegen and division, ~193 rows

The body reaches **8.9% raw**. The 223 generated rows vs retail's 167 indicates the code structure
is fundamentally different. Key issues:

- The virtual call pattern generates different code than expected
- Division by 100 via `mulhw` with 0x38E38E39 doesn't match `/ 100` in C
- The while loop condition and pointer advancement differ
- The nested loop structure with different increments is not matching

The body is at `.fzgx/attempts/fn_80049958.best.c`
(SHA-256 `194d95b63d8b7d19...`, full hash in `.fzgx/attempts/fn_80049958.best.json`), 8.9% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_80049958.best.c`, compiler GC/1.2.5n, no extra
command-line flags. Next steps: match the virtual call pattern (function pointer through vtable),
find the C expression for division by 100 that produces `mulhw` with 0x38E38E39, and restructure
the loops to match retail's increment patterns.
