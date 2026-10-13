# fn_12_3DCF0 (movie_module): fresh unit, palette color-masking converter, 20.6% first pass

Selected a carved-but-never-written unit (536 B, `movie_module/rel/movie_module`). No prior session
had attempted it. No claims remained; no fleet settings were changed and no canonical gameplay source
was submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

A palette-based pixel format converter. It takes a source buffer, a destination buffer, and a
palette table, and converts 4-bit indexed pixels to a masked RGB format. The retail assembly is a
nested loop with a fully unrolled 8-group inner body.

Retail structure (verified by disassembling the retail object directly):

    li r9, 0                          ; outer counter i
    stmw r25, 0x14(r1)                ; save 7 callee-saved regs
    lwz r7, 0x4(r4)                   ; dst->f4
    lwz r12, 0xc(r3)                  ; src->stride
    srawi r6, r7, 2 ; addze r10, r6   ; r10 = dst->f4 / 4  (signed div)
    lwz r0, 0xc(r4)                   ; dst->f_c
    lwz r8, 0x8(r4)                   ; dst->f8
    lwz r6, 0x0(r3)                   ; src->pixels
    subf r7, r7, r0                   ; r7 = dst->f_c - dst->f4
    srawi r8, r8, 2 ; addze r11, r8   ; r11 = dst->f8 / 4  (signed div)
    lwz r31, 0x0(r4)                  ; dst->words
    mulli r3, r12, 0x3                ; r3 = stride * 3
    slwi r0, r12, 2                   ; r0 = stride * 4
    extlwi r4, r7, 26, 4              ; r4 = (dst->f_c - dst->f4) >> 4
    b .L_0003DEF4                     ; jump to loop condition

Outer loop: `while (i < f8/4) { ... i++ }` (condition-first via `b`).
Inner loop: `mtctr r10; cmpwi r10, 0; ble skip` — a `do { ... } while (--n)` with r10 = f4/4.

Each inner iteration processes 4 source groups (8 output words). Each group reads 4 source bytes,
looks each up in the palette via `lbzx`, and builds a masked color:

    color = (palette[src[0]] << 24) | 0x00FF0000 | (palette[src[1]] << 8) | 0x000000FF
    out[2k]   &= color   (uses src[0], src[1])
    out[2k+1] &= color'  (uses src[2], src[3])

The 4 groups read from threaded source pointers:

    g0 = row
    g1 = row + stride
    g2 = row + 2*stride + 4
    g3 = row + 3*stride + 4

After the inner loop: `row += stride*3`, `out += (f_c - f4) >> 4` (byte offset via extlwi),
`i++`. Per inner iteration: `row += 8`, `out += 16` (0x40 bytes, only 0x20 written).

## Prologue idioms (probed offline with real GC/1.3.2)

- `(s32)x >> 2` emits only `srawi` — WRONG for this function.
- `(s32)x / 4` emits `srawi` + `addze` — this is the idiom retail uses for both loop counts.
- `(u32)(a - b) >> 4` emits `srwi` (no mask) — does NOT match retail's `extlwi r4, r7, 26, 4`.
- `((a - b) / 16)` (signed) emits `srawi` + `addze` — also does not match (retail uses extlwi).

Retail's `extlwi r4, r7, 26, 4` = `(r7 >> 4) & 0x3FFFFFF` (logical, 26-bit mask). The exact source
form that produces this masked extract has not been identified yet — it needs the subtraction result
to have garbage in the upper bits, or an explicit mask in the source.

## Residual: register pressure and pointer-threading structure, ~177 rows

The first-pass body (20.6% raw) uses a `for k` inner loop and recomputed group pointers. Retail
instead:

1. Uses `stmw r25, 0x14(r1)` — 7 callee-saved registers (r25-r31) live across the inner loop,
   indicating the 4 group pointers plus loop state are all kept live simultaneously.
2. Threads the group pointers incrementally (`add r30, r6, r30` etc.) rather than recomputing from
   `row`, which keeps them in registers across the 8 stores.
3. Has `li r9, 0` before the `stmw`, and a frame of -0x30 (vs our -0x20).

A second variant using the correct `/ 4` divisions and explicit 4-group unroll scored 16.7% — the
body structure and register pressure are the wall, not the division idiom.

The body is at `.fzgx/attempts/fn_12_3DCF0.best.c`
(SHA-256 `ea1d73ded94698dc...`, full hash in `.fzgx/attempts/fn_12_3DCF0.best.json`), 20.6% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_12_3DCF0.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: identify the source form that produces `extlwi` (try explicit
`& 0x3FFFFFF` mask or narrower field types), and restructure the inner loop to thread the 4 group
pointers incrementally to raise register pressure to 7 callee-saved.
