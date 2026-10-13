# fn_12_2C9C4 (movie_module): movie state machine, 57.3% first pass

Selected a carved-but-never-written unit (608 B, `movie_module`). No prior session had attempted it.
No claims remained; no fleet settings were changed and no canonical gameplay source was submitted.
Only `.fzgx` state and the unit body were touched.

## What the function does

A movie playback state machine. It:
1. Validates state (1-4) and a flag field
2. Calls `fn_12_335B8` to get a timestamp
3. For states 2-4, calls handler functions
4. Uses a jump table (`jumptable_12_data_CF0`) to dispatch on state (0-6)
5. Each state has complex sub-state logic with multiple function calls
6. Updates the state field and calls `SFTMR_AddTsum` for timing

## Key structural findings

- Jump table dispatch: `lwzx r0, r4, r0; mtctr r0; bctr` (not a C switch — indirect jump)
- `stmw r25`/`lmw r25` for register save/restore
- `subfc`/`subfe` for 64-bit subtraction (timestamp delta)
- Frame size 0x30 with r25-r31 saved (7 registers)

## Residual: jump table codegen and state logic, ~139 rows

The body reaches **57.3% raw**. The structure is largely correct but the jump table dispatch
generates different code, and the state sub-logic has different register assignments. The `goto`
statements generate lint warnings but match retail's branch structure.

The body is at `.fzgx/attempts/fn_12_2C9C4.best.c`
(SHA-256 `a79b84cfa725296c...`, full hash in `.fzgx/attempts/fn_12_2C9C4.best.json`), 57.3% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_12_2C9C4.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: find the C pattern that produces the jump table dispatch (likely
a switch with specific case ordering), match the 64-bit subtraction idiom, and align the state
sub-logic register assignments.
