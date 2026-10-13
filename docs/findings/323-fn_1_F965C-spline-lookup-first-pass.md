# fn_1_F965C (spline): table lookup with copy loops, 0% first pass

Selected a carved-but-never-written unit (556 B, `main_rel/rel/main_rel/spline`). No prior session
had attempted it. No claims remained; no fleet settings were changed and no canonical gameplay source
was submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

A table-driven lookup function. It:
1. Copies a 440-byte (0x37*8) table from `lbl_1_rodata_6E38` to stack three times at different offsets
2. Calls `fn_80008BA8(dst, src, 0xA)` to process 10-byte entries
3. Searches through 0x2C entries for a matching s16 field
4. Uses an outer loop to find the nth match
5. Based on a field value (0-4), calls different functions and extracts a bit

## Key structural findings

- `fn_80008BA8` signature is `(void *dst, void *src, u32 size)` — argument order matters
- The copy loops use `lwzu`/`stwu` with `mtctr 0x37` — a simple 8-bytes-per-iteration pattern
- The search has a nested structure: outer loop increments match counter, inner loop searches entries

## Residual: copy loop codegen, ~384 rows

The body reaches **0% raw** (408 generated rows vs retail's 139). The fundamental problem is that
MWCC unrolls the copy loops (producing 32+ load/store pairs per mtctr iteration) instead of the
simple `lwzu`/`stwu`/`bdnz` pattern retail uses. Probed multiple loop formulations offline:

- Array indexing (`dst[0] = src[0]; dst[1] = src[1]; src += 2; dst += 2;`) → unrolled to 32 pairs
- Pointer decrement (`*d++ = *src++`) → unrolled to 10 pairs with mtctr 0xb
- Struct copy (`*d++ = *src++` with Pair struct) → unrolled to 16 pairs with mtctr 6

None produce the retail pattern of `mtctr 0x37` + single `lwzu`/`stwu` pair + `bdnz`. The retail
pattern comes from a loop that MWCC does not unroll, likely because the copy is part of a larger
expression or the loop body is simpler than any probe.

The body is at `.fzgx/attempts/fn_1_F965C.best.c`
(SHA-256 in `.fzgx/attempts/fn_1_F965C.best.json`), 0% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_F965C.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: find the C loop structure that prevents MWCC from unrolling the
copy (possibly a `while` loop with a conditional, or a copy embedded in a larger statement), and
verify the `fn_80008BA8` argument order against call sites.
