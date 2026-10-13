# OSResetSystem (main): Dolphin SDK reset, 66.9% first pass

Selected a carved-but-never-written unit (648 B, `main`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

The Dolphin SDK `OSResetSystem`. It:
1. Disables the scheduler and stops the audio system
2. Conditionally disables PAD recalibration (reset type 2)
3. Iterates the reset function queue, calling each with FALSE until one returns TRUE
4. Syncs SRAM in a retry loop
5. For reset type 1 with a flag, sets an SRAM byte and syncs
6. Disables interrupts, iterates the reset function queue again with TRUE
7. For reset type 1: writes VI register, invalidates IC, calls Reset
8. For reset type 0: cancels threads, reboots
9. Cancels remaining threads, zeroes OS state via memset

## Key structural findings

- Compiler is GC/1.2.5n (Dolphin SDK code)
- `stmw r26`/`lmw r26` for register save/restore
- `blrl` for function pointer calls through the reset queue
- `cntlzw`/`srwi` for boolean conversion of function return values
- Hardcoded addresses for VI registers (0xCC002002) and OS state (0x80000040, etc.)

## Residual: instruction selection and hardcoded addresses, ~103 rows

The body reaches **66.9% raw**. The structure is largely correct but the instruction selection
differs in several places. The `blrl` (branch-link-register) for function pointer calls generates
different code, and the memset calls with hardcoded addresses produce lint warnings.

The body is at `.fzgx/attempts/OSResetSystem.best.c`
(SHA-256 `258acfb5d6930d4b...`, full hash in `.fzgx/attempts/OSResetSystem.best.json`), 66.9% raw.

Not an exact C match. Resume `.fzgx/attempts/OSResetSystem.best.c`, compiler GC/1.2.5n, no extra
command-line flags. Next steps: match the `blrl` pattern for function pointer calls, use proper
extern symbols for the hardcoded addresses, and align the loop structure for the reset queue
iteration.
