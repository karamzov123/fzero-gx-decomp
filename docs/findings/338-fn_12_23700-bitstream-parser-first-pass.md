# fn_12_23700 (movie_module): bitstream parser, 76.5% first pass

Selected a carved-but-never-written unit (620 B, `movie_module`). No prior session had attempted it.
No claims remained; no fleet settings were changed and no canonical gameplay source was submitted.
Only `.fzgx` state and the unit body were touched.

## What the function does

A bitstream parser that searches for packet markers in movie data. It:
1. Scans forward for a 3-byte start code (0x000001) using `fn_12_67A4`
2. Validates the marker byte (0xC0-0xDF range)
3. Parses a packet header with `fn_12_6B28`/`fn_12_654C`
4. Calls `fn_12_23410` to process the packet
5. Searches for a 0xFF 0xF8 synchronization pattern within the packet
6. Extracts bit fields via `extrwi`/`clrlwi` into a stack buffer
7. Conditionally updates output fields based on parsed values

## Key structural findings

- `stmw r24`/`lmw r24` for register save/restore
- `extrwi` (extract and right-justify immediate) for bit field extraction
- `mtctr`/`bdnz` for the inner search loop
- `-use_lmw_stmw on` flag for `stmw`/`lmw` instructions

## Residual: register allocation and bit extraction, ~104 rows

The body reaches **76.5% raw**. The structure is largely correct but the register allocation
differs (49 regalloc rows). The bit field extraction via `extrwi` and the stack buffer layout
produce different register assignments.

The body is at `.fzgx/attempts/fn_12_23700.best.c`
(SHA-256 `b162ae985b1f4f1c...`, full hash in `.fzgx/attempts/fn_12_23700.best.json`), 76.5% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_12_23700.best.c`, compiler GC/1.3.2 with
`-use_lmw_stmw on`, no extra command-line flags. Next steps: match the register allocation for
the bit field temporaries, align the stack buffer layout, and verify the loop structure.
