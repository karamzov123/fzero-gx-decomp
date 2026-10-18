# Native ranking templates, record iteration, and preserved frontiers

## Landed and link-verified

- `fn_1_15906C`: commit `cca2e024`, 245/245 instructions, 980 bytes.
- `fn_1_1586AC`: commit `cd7ae639`, 181/181 instructions, 724 bytes.
- `fn_1_15BCDC`: commit `8a89290e`, 87/87 instructions, 348 bytes.
- `InitMetroTRKCommTable`: commit `1a10b098`, 155/155 instructions, 620 bytes.
- All four passed normal `write-unit` lint, `submit`, and `verify`; no forced match, alternate object, or link-gate bypass.
- Total newly matched native code: 2,672 bytes. After all four commits, `build/tools/dtk shasum -q -c config/GFZE01/build.sha1` returned `16 files OK` with exit 0. Repository lint returned zero findings.

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

### fn_1_15BCDC: decode the command before reading the history ring

The 16-bit buttons field is `(u16)(command >> 4)`, bits 4..19, not the old `>>16`. Remove the old cloned scan-loop selector/button locals and update the actual selector and held-button variables. Read the controller's history-end table before deriving its row. Decode a local `buttons` value before the ring read and early-continue command-type check; the value is needed after optional held-button skipping. These changes recover every one of the 87 words.

Keep the explicit narrow update `held_buttons = (u16)((u16)held_buttons | (u16)(event >> 4))`. A cleanup to compound `|=` removes a retail `clrlwi` and changes five other rows. That cleanup was rejected and never integrated. The generic array-read helper is unnecessary; direct ring indexing still matches. Preserve signed `%32`, not an unsigned bit mask.

### InitMetroTRKCommTable: restore the actual success return

The saved source returned the address of `TRK_Use_BBA` after installing UDP/BBA callbacks. Retail instead returns integer zero directly from that branch, bypassing the common stub-status return used by the other transports. Replacing the bogus address assignment with the real early `return 0` reproduces every one of the 155 instructions, including the callback-address schedule and three saved-register roles. No declaration, optimizer, or instruction-padding workaround is needed. The callback table fields were named by their actual operations, and the standard link gate accepted the result.

## Portable unmatched frontiers

Archive: `state/repairs/hermes-native-ranking-frontier-20261018.json.gz`.

This is the existing `fzgx-source-repairs-v1` format, with complete C, hashes, compiler version, separate raw-word and aligned-row measurements, and exact oracle results. It contains twelve records: the four landed bodies, the seven unmatched frontiers below, and the explicitly admission-blocked `fn_1_203E4` matrix reconstruction. Replay actually returned `{"reproduced": 12}`. Replay proves source reproduction, not admission or a match:

    .venv/bin/python tools/fzgx.py fixup --archive state/repairs/hermes-native-ranking-frontier-20261018.json.gz

These are work-copy frontiers, NOT matches or enabled units:

| Function | Fresh aligned residual | Important distinction |
|---|---:|---|
| `fn_1_1188CC` | 19/305 rows | Previously 31/306. Correct pool literals and Y update order; positive null guard removes an extra branch. |
| `fn_1_C0B0C` | 5/190 rows | Raw comparison is 4/189 words; objdiff aligns the reordered initialization as five rows. Do not conflate the metrics. |
| `fn_1_158984` | 1/430 rows | Stock allocator capture guided a verified 9-to-1 reduction; still unmatched. |
| `fn_1_15AC10` | 47/504 rows | Complete native-u64 reconstruction, 502 retail versus 503 candidate instructions. Raw comparison has 77 differing words because alignment shifts. |
| `fn_1_15BBC4` | 31/74 rows | Correct controller-history update semantics; 70 retail versus 68 candidate instructions. |
| `fn_1_86E08` | 27/155 rows | Complete 1,824-byte readonly initializer now includes all 260 pointer bindings; still unmatched. |
| `OSResetSystem` | 5/162 rows | Complete native reset body with the old SDK compiler/peephole profile; only frame offsets remain. |

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

The initial nine-row frontier was reduced to one with stock compiler evidence. Two captured source versions are preserved in `state/repairs/hermes-ranking-allocator-20261018.json.gz`; both had `same_code=true`, `same_object=true`, and zero replay/simplify errors. Portable replay validates four allocation passes over those two versions. This is allocator replay parity, NOT a retail match.

PCode showed an unnamed delta-X input temporary allocated to f1 while the named accumulator was f3. `dx = object->position.x; dx -= other_object->position.x;` coalesces the actual value lifetime and eliminates two rows. A fixed-graph selection-order witness predicted collision locals 52/53/54 could occupy r6/r7/r8; one source projection of those cloned local slots eliminated six more rows. This was a single witnessed projection, not another declaration-permutation campaign.

Only offset `0x538` remains: retail `li r6,0` versus candidate `mr r6,r8`. Helper-local CSE policy changes are identical. Whole-function `-opt nocse`, `-opt noprop`, and `-opt nopeep` regress to 67, 45, and 17 rows. BOOL/u8/u32 flags are identical; a separate vector delta or distance accumulator regresses. Do not repeat those families. The automatic target projector reports unsupported paired-single instruction row 223; that is a tooling projection limitation, not evidence of a fix.

### fn_1_15AC10

Native u64 recovers the bit-code and decimal-display algorithm without any of the lifter's 79 unhandled-instruction placeholders. Stage the masked high word before the second call, then combine `(high << 32) + fn_8003D4C0()`; constructing the shifted code earlier keeps an unwanted zero live across the call. Cast the high mask to u64, preserve the real six flag bits, and cast the seed mix to u8 rather than ANDing a u64 with `0xff`.

Split bit extraction from addition of the random remainder so `__shr2u` occurs before `__mod2u`. Bits 13, 20, 32, and 33 are excluded. Signed random15 results are promoted to u64 as retail does. All twenty decimal quotient/remainder stores and the four hyphens match, least-significant digit first. The tail scrambles characters 5 through 23, skipping hyphens.

The residual is saved-pair allocation in the bit loop and tail, two RNG operand homes, and tail pointer/counter lowering. Whole bit or digit phase helpers regress. The candidate retains the actual algorithm and correct frame but is not submitted. No delegated improvement was admitted for this function.

### fn_1_15BBC4

Recover the actual 15-by-32 history table and use the correct signed `(index + 1) % 32`, not the previous erroneous negative unsigned mask. Cache a controller's current buttons across the separate index store so the compiler does not reread a potentially aliasing u16. Explicitly narrow the returned result before the `0xffff` comparison. Cached entry/index array bases and the native two-dimensional history view reduce the measured draft to 31 aligned rows, but do not close it.

Remaining differences include the saved-pointer home mapping, combined versus separate array-base offsets, induction placement, and cooldown-path load scheduling. Body-top pointer advances emit an unwanted `lhzu`; do not repeat that form. The body is archived and explicitly unmatched.

### fn_1_86E08: bytes alone hid 260 pointer relocations

The older readonly prefix exactly matched 1,824 raw bytes but omitted 260 `R_PPC_ADDR32` bindings to 96 real data symbols. The zero words were REL relocation placeholders, not padding. Reconstruct the native initializers from `dataimport.pool_objects` and `payload`; the revised ELF now passes `_relocated_pool_matches` for the full 1,824 bytes and all pointer targets/addends.

Remove the fake one-member manager box, identity array helper, and zero-only `lab_*` carriers. Real entry lookup and cooldown-field helpers retain the 155-word shape. The remaining register differences are the manager/pool cached-base pair and the timer store's temporary homes. Removing the held manager loses the frame; delaying it adds address materialization; direct timer indexing folds the field displacement into the access. None is a match, and no new global data ownership was enabled.

### OSResetSystem: recover the actual SDK profile without dummy storage

A complete native routine replaces the old mechanical draft with 18 unhandled instructions. It performs the real callback short-circuit polling, SRAM force-menu update/sync, locked-cache shutdown, hot reset, restart/shutdown thread cancellation, low-memory clearing, and pad recalibration restore. Structures and control flow were checked against the pinned SMS and MK-Deception SDK references recorded in `docs/RESOURCES.md`, then adapted to the actual retail flow. The VI reset uses the existing symbolic MMIO block, and the low-memory window uses linker-generated SDK address constants.

The verified working profile is `GC/1.2.5n`, with peephole optimization disabled; this does not uniquely establish the historical minor compiler version. Under the ordinary profile, the compiler folds the SDK's branch trampolines, changes `mr` to zero-add copies, and merges `or` with its compare. A source `#pragma peephole off` preserves the exact 162-instruction control/dataflow. Explicit BOOL return branches, rather than `return !error`, retain the real polling return ladder. Anonymous low-memory constants recover the shared cached base instead of introducing a new named pointer home.

Only five stack-frame rows remain: retail allocates `0x40`, the candidate `0x30`, shifting the save/restore offsets by 16 bytes. The referenced SMS source contains an unused `trash[16]`; it was NOT copied. No padding, dummy work, inline assembly, or forced register storage was added. The candidate object defines only `OSResetSystem`, not extraneous private helper bodies. Debug symbols do not fix the gap; deferred-inline mode interacts with the pragma reset and regresses. This is an unmatched compiler/frame frontier, not an enabled SDK function.

### Other bounded diagnostics, not accepted changes

- `fn_1_15C4EC`: all body instructions match, but ten prologue-save scheduling rows remain. GC/1.3 and 1.3.2r are identical; 1.2.5n and schedule-off regress. No compiler override was persisted.
- `fn_1_15E27C`: native BSS subobject and aggregate-view probes do not reproduce the shared-base form. The apparent aggregate-view improvement crosses the currently declared owner boundary, so it was explicitly rejected rather than promoted by similarity. No header/global/split ownership was changed.
- `fn_1_15E44C`: widening the byte-derived local removes a spurious `extsh`; staging the final selected-entry pointer preserves its field displacement. The larger manager view still needs ownership recovery; no acceptance was attempted.
- `fn_1_203E4`: the preserved standalone body corrects swapped X/Z translation stores and replaces three guessed calls with the proven `mathutil_mtxA_rotate_z__fzgx_offset_C` entry. It uses canonical `LC_BASE` and passes lint, but still has 27 differing rows and canonical-prototype admission conflicts. Its archive record is explicitly blocked; replay does not enable it.

## Fresh verification

After the fourth admission, `ninja -j2` exited zero and regenerated the real report over 7,119 units. The installed unittest suite ran 15 tests and passed; no tests were added. The independent DTK manifest check again returned `16 files OK`, and repository lint reported zero findings. The source archive replay reproduced all twelve records, while the separate graph archive replay reproduced four allocation passes over two captured source versions with zero errors.

## Coordination and publication

OpenCode's customize claim `fn_3_1AEE4` was not touched. All parent edits were inline, claim-scoped work; no fleet, profile, transport, or model configuration was changed. Two depth-1 agents were assigned independent closure attempts for `fn_1_158984` and `fn_1_15AC10`, work copies only. Both stalled in provider API retries and were interrupted after approximately 50 minutes; neither delivered a verified improvement. The parent continued inline, independently verified live claims and artifacts, and made the capture-guided improvement above. No further agents were launched.

No manual push or upstream PR was issued; the configured repository publisher owns publication. The match commits were produced by the supported link-verification gate.
