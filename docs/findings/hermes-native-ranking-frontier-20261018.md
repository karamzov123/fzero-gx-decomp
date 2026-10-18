# Native ranking templates, record iteration, and preserved frontiers

## Landed and link-verified

- `fn_1_15906C`: commit `cca2e024`, 245/245 instructions, 980 bytes.
- `fn_1_1586AC`: commit `cd7ae639`, 181/181 instructions, 724 bytes.
- Both passed normal `write-unit` lint, `submit`, and `verify`; no forced match, alternate object, or link-gate bypass.
- After both commits, `build/tools/dtk shasum -q -c config/GFZE01/build.sha1` returned `16 files OK` with exit 0. Repository lint returned zero findings.

### fn_1_15906C: meaningful initializer boundaries

The saved body was not merely one commuted addition away from closure. It also widened rounded `0.8f`/`0.2f` values to double and put four automatic zero-vector templates after the scalar pool. Correct native literals are `10.0`, `0.8`, and `0.2`.

Named const zero-template assignments reproduce pool offsets but hoist loads across record initialization, regressing thirteen early words. Instead, define the actual `clear_record_copy` and three axis-vector setters before the later random-magnitude primer. Each helper performs the real aggregate initialization/copy, and each call remains at its original operation site. The compiler then places four 12-byte automatic templates at `0x78/0x84/0x90/0x9c`, followed by the scalar constants at `0xa8` onward. The resulting pool was byte-proven against `lbl_1_rodata_D958`.

A proper row type closes the final address expression:

    struct Row { u32 cell[20][40]; };
    ((struct Row *)((u8 *)manager + 12))[x].cell[y][z] = 1;

The row strides are the retail `0xc80`, `0xa0`, and `4`, not transposed dimensions. Flat byte-offset alternatives commute the final add or introduce an indexed store. The typed row gives all 245 words. Nested read-pointer helper chains, unused aggregate locals, and the reducible `goto` dispatch were removed; ordinary field reads and structured switch control flow still match.

### fn_1_1586AC: pointer induction recovers the actual unroll

The older source indexed `record[index]` through its 400-record initialization loop and compiled an eight-record unroll. Advancing the record pointer in the loop header instead reproduces retail's four-record unroll and closes all 181 words:

    for (record_index = 0; record_index < 400; record_index++, record++) {
        record->unk_0 = 0;
        record->unk_8 = *(struct RankingResetVector *)lbl_1_rodata_D978;
        record->unk_14 = *(struct RankingResetVector *)lbl_1_rodata_D984;
    }

No unroll pragma is needed. Explicit unroll-on variants were identical. Do not rewrite the subsequent raw grid address expressions merely for stylistic uniformity: the typed-grid variant changes the nested-loop lowering and regresses 81 raw words. Retail clears 20 words of each 40-word row; preserve that behavior.

## Portable unmatched frontiers

Archive: `state/repairs/hermes-native-ranking-frontier-20261018.json.gz`.

This is the existing `fzgx-source-repairs-v1` format, with complete C, hashes, compiler version, separate raw-word and aligned-row measurements, and exact oracle results. It contains six records: the two landed bodies and the four unmatched bodies below. Replay actually returned `{"reproduced": 6}`:

    .venv/bin/python tools/fzgx.py fixup --archive state/repairs/hermes-native-ranking-frontier-20261018.json.gz

These are work-copy frontiers, NOT matches or enabled units:

| Function | Fresh aligned residual | Important distinction |
|---|---:|---|
| `fn_1_1188CC` | 19/305 rows | Previously 31/306. Correct pool literals and Y update order; positive null guard removes an extra branch. |
| `fn_1_C0B0C` | 5/190 rows | Raw comparison is 4/189 words; objdiff aligns the reordered initialization as five rows. Do not conflate the metrics. |
| `fn_1_158984` | 9/430 rows | Full native motion/collision reconstruction, versus 306 real residual rows in the old source. |
| `fn_1_15AC10` | 47/504 rows | Complete native-u64 reconstruction, 502 retail versus 503 candidate instructions. Raw comparison has 77 differing words because alignment shifts. |

### fn_1_1188CC

Recover actual literal values in the primer, not unresolved external field reads: double gravity `0.0013611111376020642`, float damping `0.0027222223579883575`, `-0.25f`, and `1.2000000476837158f`. Reload position Y before adding velocity Y, as retail does. The canonical `lbl_1_data_3FFBC` declaration is a struct; include `globals.h` and use its real s32 table view rather than redeclaring an s32 array.

The remaining rows are sixteen relaxing-pass register homes and three last-loop counter homes. A meaningful group iterator carries both group index and first-item pointer, replacing the one-member index carrier without changing words. Moving relaxing work into an inline helper with caller-owned vector scratch is identical; helper-local vectors regress the frame. Do not repeat those families.

### fn_1_C0B0C

Separate the long-hex branch's actual digit, text-pointer, and loop-counter variables from the short-hex branch. Keep the result accumulator shared. Put both long-loop increments in the `for` header. This removes the pointer/digit home swap and counter scheduling differences from the 27-row baseline.

Only initialization scheduling/zero reuse remains: retail starts `li r3,0; li r0,2; mr r5,r3; addi r6,r31,2`, while the candidate starts `li r0,2; addi r6,r31,2; li r3,0; li r5,0`. Full parser helpers, sharing the loop counter, and propagation policy changes do not close it. The similarity-based best selector prefers an older, worse instruction frontier, so retain the portable body rather than trusting `best_percent`.

### fn_1_158984

Reconstruct the manager's real grid and 400 records, object vectors and angles, and global vector scratch. Aggregate vector copies eliminate the old erroneous float-to-u32 conversions. Collision exchange is inside the active/eligible-mode branch and uses squared distance `<= 40000.0f`, not `<`.

The mode returned by `camera_get_mode()` is passed to `fn_1_8627C(mode)`; declaring the latter void-argument loses that real value flow. A widened s32 local retains the single `extsh. r3,r3`.

Keep the damping product in a double temporary before adding to the original angle: a single expression contracts into the wrong `fmadd`. The lazy axis-range macro preserves the real per-axis boolean ladder and the retail quirk where the Z containment upper bound uses the X center. Stage squared length in X (`dx *= dx; dx += dy*dy; dx += dz*dz`) to recover the two fused single-precision additions.

Residual: seven collision flag/index home or zero-CSE rows and two delta-X input FPR rows. BOOL/u8/u32 flags are identical. Whole-function lifetime disabling regresses. Real Vec3 delta construction or a separate distance accumulator adds five FPR rows. Parent-assigned depth-1 closure work may produce a later frontier; this archive records the verified starting point.

### fn_1_15AC10

Native u64 recovers the bit-code and decimal-display algorithm without any of the lifter's 79 unhandled-instruction placeholders. Stage the masked high word before the second call, then combine `(high << 32) + fn_8003D4C0()`; constructing the shifted code earlier keeps an unwanted zero live across the call. Cast the high mask to u64, preserve the real six flag bits, and cast the seed mix to u8 rather than ANDing a u64 with `0xff`.

Split bit extraction from addition of the random remainder so `__shr2u` occurs before `__mod2u`. Bits 13, 20, 32, and 33 are excluded. Signed random15 results are promoted to u64 as retail does. All twenty decimal quotient/remainder stores and the four hyphens match, least-significant digit first. The tail scrambles characters 5 through 23, skipping hyphens.

The residual is saved-pair allocation in the bit loop and tail, two RNG operand homes, and tail pointer/counter lowering. Whole bit or digit phase helpers regress. The candidate retains the actual algorithm and correct frame but is not submitted. Parent-assigned closure work is restricted to this function.

## Coordination and publication

OpenCode's customize claim `fn_3_1AEE4` was not touched. All parent edits were inline, claim-scoped work; no fleet, profile, transport, or model configuration was changed. Two depth-1 agents were subsequently assigned independent closure attempts for `fn_1_158984` and `fn_1_15AC10`, work copies only, with parent integration required.

No manual push or upstream PR was issued; the configured repository publisher owns publication. The match commits were produced by the supported link-verification gate.
