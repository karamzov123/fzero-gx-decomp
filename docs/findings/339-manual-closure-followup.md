# Manual closure follow-up: published title match and four partial candidates

The title-screen animation `fn_8_A954` is linked and checksum-verified at commit `3285fc7ad1593cf6fda578fca2a8a167c0bdd8bb`. It was published through fork PR https://github.com/karamzov123/fzgx/pull/14 and merged into fork main. This does not claim an upstream merge.

No additional function reached an exact match in this follow-up. The source snapshots in `docs/partial-candidates/20261013/` are explicitly research-only and are not wired into `config/GFZE01/units.json` or any split. Do not count them as authored matching code.

## fn_1_64FB8: effect/camera transform update

The archived no-helper candidate reaches raw objdiff **99.0%**, adjusted instruction-row score **93.0%**, with **12** non-pool differing rows out of 172 aligned instructions. The complete 0xB0 frame, short damping conversions, vector/matrix stack offsets, control flow, temporary vector copies, transform output pointer, timer conversion, RNG extraction, final scalar arithmetic and shared pool bindings align. Remaining differences are confined to the two locked-cache translation store groups and their FPR assignments.

Corrected defects in the previous body:

- Read/write signed halfwords at +0x5A/+0x5C and +0x18, not bytes.
- Native integer-to-float conversions already subtract the ABI bias; do not subtract the 0x4330 bias again in source.
- Camera position and matrix are stack locals, not fields at +0x38/+0x44 in the effect object.
- Translation is written to the locked-cache matrix column at `LC_BASE + 0xC/0x1C/0x2C`, not a invented data label.
- The default local vectors are real three-word aggregate copies, with Z overridden before transformation.
- The second transform writes to object +0x3C; its output is not discarded.
- Object +0x10 is signed for timer conversion.
- RNG output is `(state >> 16) & 0x7FFF`, not `(state >> 1) & 0x7FFF`.
- Recover native scalar literals and a retail-byte-derived shared pool primer through existing fixup generators.
- Natural short compound damping `*= 0.98f` closes the first conversion/register block.

A temporary translation-helper probe reduced the residual to eight rows (99.2% raw, 95.3% adjusted), but that helper is not established as the original abstraction and is not included in the archived no-helper source. The matched sibling `fn_1_11ABC` in `live_camera.c` uses separate scalar declarations/assignments and `opt_propagation off`; applying that complete shape closes the translation register groups but regresses the remaining scalar block to 32 rows and hoists a locked-cache base into a saved GPR. Hardware volatile stores do not close the residual. Do not repeat these levers unchanged or submit the partial as matching.

## fn_1_F75D8: GX lighting setup

Archived third structural candidate: **95.3% raw**, **77.8% adjusted**, **37** remaining instruction rows out of 167 aligned. The adjusted score was corrected by recompiling this exact archived body in an isolated worker; the previous 88.2% label came from a different attempt-best result and did not describe this source. Corrected light layout, local light object/vector/color sizes, stop-at-first-null behavior, independent light numbering, signed getter/override enables, and paired-single vector scaling using the existing `psvec_scale` helper. Native/shared pool recovery removes the private constant-base mismatch.

Remaining wall: the compiler folds the override index into saved group pointers, using `lwz` where retail preserves an index and uses `lwzx`. It saves one fewer GPR and reserves a smaller frame. Flat versus grouped override arrays, loop-invariant settings and propagation settings were measured; none closed the address/lifetime shape. Do not pad structs or inject unused locals to force the frame.

## fn_1_104730: camera update

Archived best: **87.8%**, **102** differing aligned instruction rows. Corrected the stack-local position vector, actual locked-cache writes through `LC_BASE`, signed remainder switch, component ordering and final caller index. The true fallback vectors are aggregate copies from the shared pool. Remaining mismatches are aggregate-copy scheduling, argument/mode register lifetimes and floating temporary assignment across the coordinate calculations. An explicit-lifetime/propagation-off probe regressed to 84.6% and is not archived as best.

## fn_1_82C70: car object initialization

Archived best: **77.0%**, **45** differing aligned instruction rows. Corrected MSB-numbered flags to 0x40000000 and 0x80000000, actual 0x10440 per-car stride, real callback function relocations rather than nonexistent `_addr` labels, signed mode loads, signed-versus-byte comparison semantics, allocator call argument count, and the selected mode argument. Two distinct typed record views describe the entry and callback address spaces without fake padding for register pressure.

Remaining differences are concentrated in callback-store scheduling/address common subexpressions and parameter/result register webs. Common-subexpression suppression and typed array views were tested; neither reaches exact. The signed load is expressed through the existing symbol because the shared header currently declares its storage as unsigned; changing that shared declaration requires a separate caller audit.

## Publication and verification scope

These four sources are snapshots for future measured work, not build inputs. They use MWCC syntax (including generated shared-pool `__declspec` primer sections), so generic Clang diagnostics are not an authoritative compiler result. Each snapshot was exercised through the project object oracle before archiving. Build claims apply only to the canonical title conversion, not these partials. All manual claims were released when each target was parked. Existing unrelated working-tree changes were preserved and excluded from commits and pushes.
