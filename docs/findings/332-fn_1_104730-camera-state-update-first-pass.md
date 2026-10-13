# fn_1_104730 (camera): camera state update, 56.5% first pass

Selected a carved-but-never-written unit (688 B, `main_rel`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

A camera state update function. It:
1. Gets the camera mode
2. If mode is -1, copies default camera parameters from rodata
3. Otherwise, calls camera subsystem functions and negates position vectors
4. Based on a flag, selects scale factors from rodata
5. Computes 9 output values as linear combinations of position and scale factors

## Key structural findings

- `_savegpr_27`/`_restgpr_27` for register save/restore
- Hardware register writes at 0xE00000C via `lis r5, 0xe000` pattern
- Sign-magnitude decomposition via `srwi`/`clrlwi`/`xor`/`subf` for the flag check
- 9 float computations using `fmuls` + `fadds` (not `fmadds` — `fp_contract off` needed)

## Residual: register allocation and float operation ordering, ~175 rows

The body reaches **56.5% raw**. The structure is largely correct but the register allocation
differs significantly (83 regalloc rows). The float operations use different register assignments,
and the operand order in some `fadds` operations is reversed.

The body is at `.fzgx/attempts/fn_1_104730.best.c`
(SHA-256 `87ee6b905a062ae7...`, full hash in `.fzgx/attempts/fn_1_104730.best.json`), 56.5% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_104730.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: match the register allocation for the float temporaries, fix
operand order in the `fadds` operations, and align the conditional branch structure for the
scale factor selection.
