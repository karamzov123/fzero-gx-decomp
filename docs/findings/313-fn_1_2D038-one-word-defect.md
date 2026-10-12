# One-word tier: fn_1_2D038 residual defect (measured 2026-10-11)

fn_1_2D038 (main_rel/stcoli, 1260 B) sits at 99.68% with exactly ONE genuine
defect. All other diff rows are literal-pool relocations (`p`-marked) that the
tooling retargets at submit.

## The defect

Target vs ours, text row 0x104:

    lbz r0, 0x5(r3)      <- retail: r3 = &p_bss->unk_30, load unk_30.unk_5
    lbz r0, 0x35(r31)    <- ours: folded offset from r31 (p_bss)

Retail materializes the header pointer into r3 and keeps it live across both the
byte load and the `fn_1_F22D4(ph)` call:

    .L_0002D12C:  lbz  r0, 0x1634(r31)      ; unk_1634 check
                   bne  .L_0002D154          ; short-circuit
                   addi r3, r31, 0x30        ; ph = &p_bss->unk_30
                   lbz  r0, 0x5(r3)          ; ph->unk_5
                   cmplwi r0, 0x2
                   bne  .L_0002D1D8
                   bl   fn_1_F22D4           ; r3 still holds ph

The candidate source uses a comma expression
`(ph = &p_bss->unk_30, ph->unk_5 == 2)` inside the `||`. MWCC keeps `ph` dead
after the load because nothing downstream reuses it in that form, so it folds the
load to `0x35(r31)`.

## What was tried (all measured via oracle.check on the saved body)

- comma expression (original): folds to 0x35(r31) — the 99.68% single defect
- `ph = &unk_30;` as a standalone statement before the `if`: fixes the load
  (r3-relative) but hoists `addi r3, r31, 0x30` to row 0xF8, 12 bytes too early
  (before the unk_1634 branch) — 98.92%
- `goto` to preserve branch order: restores the single-defect shape at 99.54%
  but the load folds again to 0x35(r31)
- `volatile u8` read: hoists the addi early like the standalone form
- if/else split with `hdr_hit` flag: matches the 0x104 load but shifts the whole
  stack frame (regalloc-sensitive) — frame size changes 0xf0 -> 0x100

## Conclusion

The fix needs the pointer live in r3 across load AND call, computed only on the
fall-through path (after the unk_1634 bne), without disturbing the frame. This
is a register-allocation puzzle, not a one-line edit. Left at the canonical
99.68% body; handed to the fleet's matcher for a full session rather than
forcing a fragile edit. No executable-byte change claimed.

Canonical body: .fzgx/attempts/fn_1_2D038.1790918739.c (also .fzgx/work/many/).
The unit record exists but the TU block was never spliced, so `fzgx check` reports
"missing in our object" — same class of gap as fn_1_15C6C0.
