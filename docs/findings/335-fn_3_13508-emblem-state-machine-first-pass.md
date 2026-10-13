# fn_3_13508 (customize/emblem): emblem state machine, 76.1% first pass

Selected a carved-but-never-written unit (676 B, `customize/rel/customize/emblem`). No prior session
had attempted it. No claims remained; no fleet settings were changed and no canonical gameplay source
was submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

An emblem editor state machine. It:
1. Checks initialization and busy flags (early return if set)
2. Handles a special mode flag (bit 1) with sound and state update
3. Checks button states via `fn_3_19C94` for various values (0x10, 0xF, 0xB, etc.)
4. Manipulates a flags field with bit operations (set/clear/toggle)
5. Looks up emblem data from a table indexed by a byte field
6. Clamps a counter to [0, 0x78]
7. Calls various state transition functions

## Key structural findings

- No stack frame beyond the minimal (stwu r1, -0x10)
- Many conditional branches based on `fn_3_19C94()` return values
- Bit manipulation on a u32 flags field (rlwinm, oris, clrrwi patterns)
- Table lookup: `lbl_1_bss_9F8 + 8 + idx * 0x14` for u16 values
- `goto` used for control flow (matches retail's branch structure)

## Residual: instruction selection and operand order, ~88 rows

The body reaches **76.1% raw**. The structure is largely correct but several `add` instructions
have reversed operand order (`add r3, r3, r0` vs `add r3, r0, r3`), and some immediate values
differ. The `goto` statements generate lint warnings but are needed for the control flow.

The body is at `.fzgx/attempts/fn_3_13508.best.c`
(SHA-256 `0c790e81e6be147f...`, full hash in `.fzgx/attempts/fn_3_13508.best.json`), 76.1% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_3_13508.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: fix operand order in address calculations, match immediate values
for the bit manipulation operations, and verify the goto structure matches retail's branches.
