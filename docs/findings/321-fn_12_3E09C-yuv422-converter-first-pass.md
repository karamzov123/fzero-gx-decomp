# fn_12_3E09C (movie_module): YUV422 pixel converter, 42.5% first pass

Selected a carved-but-never-written unit (760 B, `movie_module/rel/movie_module`). No prior session
had attempted it. No claims remained; no fleet settings were changed and no canonical gameplay source
was submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

A YUV422-to-packed pixel format converter. It calls `fn_12_339B4` to get frame dimensions, then
processes the frame in 4x4 blocks. Each block reads u32 luma values and u16 chroma values, interleaves
the bytes, and writes two output streams (at `arg1` and `arg1+32`).

The retail assembly uses `rlwimi` (rotate-left-word-immediate-then-mask-insert) instructions to build
each output u32 from bytes of the source u32 and u16 values. The byte interleaving pattern is:

    word0 = [A_b3, C_b0, A_b2, C_b1]  (MSB to LSB)
    word1 = [A_b1, C_b0, A_b0, C_b0]

Where A is a u32 (4 luma bytes) and C is a u16 (2 chroma bytes).

## Prologue idioms (probed offline)

- `(s32)x / 4` emits `srawi` + `addze` — the idiom retail uses for both loop counts.
- `-use_lmw_stmw on` flag makes MWCC emit `stmw`/`lmw` for register save/restore.

## Residual: rlwimi codegen matching, ~188 rows

The first-pass body reaches **42.5% raw**. The structure (loops, conditionals, pointer arithmetic)
is correct, but the byte-interleaving expressions don't compile to the exact `rlwimi` sequence retail
uses. Probed multiple C formulations offline:

- `(a >> 8) & 0xFF00 | a & 0xFF000000 | (u32)(c & 0xFF) << 16 | (c >> 8) & 0xFF` →
  `clrrwi` + `rlwimi` + `rlwimi` + `mr` + `rlwimi` (close but first instruction differs)
- `((a << 24) | (a >> 8)) & 0xFF00 | ...` → `srwi` + `rlwimi` + `rlwinm` + `rlwimi` + `rlwimi` + `mr` + `rlwimi`
- Union/struct byte access → `stb`/`lwz` (stack round-trip, wrong)
- Explicit rotate → `srwi` + `extrwi` + `rlwimi` chain (wrong)

Retail's first instruction is `rlwinm r22, r21, 24, 16, 23` (single rotate+mask), while all probes
produce `clrrwi` + `rlwimi` (two instructions) for the first byte. This is a deep MWCC instruction
selection difference that requires finding the exact C expression structure.

The body is at `.fzgx/attempts/fn_12_3E09C.best.c`
(SHA-256 `e97d3424756251bf...`, full hash in `.fzgx/attempts/fn_12_3E09C.best.json`), 42.5% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_12_3E09C.best.c`, compiler GC/1.3.2 with
`-use_lmw_stmw on`, no extra command-line flags. Next steps: find the C expression that produces
`rlwinm r, a, 24, 16, 23` as the first instruction (likely a different formulation of the byte
extraction), and match the remaining `rlwimi` chain exactly.
