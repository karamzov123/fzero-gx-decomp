# fn_1_82C70 (car): car entry initialization, 62.3% first pass

Selected a carved-but-never-written unit (620 B, `main_rel/rel/main_rel/car`). No prior session had
attempted it. No claims remained; no fleet settings were changed and no canonical gameplay source was
submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

A car entry initialization function. It:
1. Checks a flag to determine the car ID source (direct call vs struct field)
2. Based on a game mode value (2, 0xE, 0xC), selects a car entry from different tables
3. Validates the entry (null check, field checks)
4. Initializes a car entry structure with function pointers and default values
5. Sets up the entry via `fn_1_7F254` and `fn_1_FD844`
6. Conditionally calls cleanup/registration functions

## Key structural findings

- Multiple conditional branches based on `lbl_1_bss_960` (game mode: 2, 0xE, 0xC, or default)
- Car ID multiplication by `0x10000 - 0x7E40` (0x81C0) for table offset
- Entry structure at `arg3 + carId * 0x440` with function pointers at +0x424/+0x428/+0x42C
- `_savegpr_25`/`_restgpr_25` for register save/restore (not stmw/lmw)

## Residual: register allocation and instruction selection, ~87 rows

The body reaches **62.3% raw**. The structure is largely correct but the instruction selection
differs in several places:
- `add r30, r3, r0` vs `add r30, r0, r3` — operand order in address calculation
- Function pointer stores use different register assignments
- The conditional branch structure produces different codegen

The body is at `.fzgx/attempts/fn_1_82C70.best.c`
(SHA-256 `40658c292d8fb306...`, full hash in `.fzgx/attempts/fn_1_82C70.best.json`), 62.3% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_82C70.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: fix operand order in the address calculation, match the function
pointer store pattern, and align the conditional branch structure.
