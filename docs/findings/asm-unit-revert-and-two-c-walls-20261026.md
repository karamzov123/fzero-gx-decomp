# The 60 asm units are reverted; two of them measured as C

`b2a7592aa` reverts the ten `asm units:` commits from 2026-10-25 20:20-20:42
(fn_1_7B2E8, fn_1_1FDB0, fn_1_DDF80, ... 60 functions). Those commits satisfied
the hash gate by linking each function from a copy of its own retail assembly,
which credits the address without producing reconstructed C, so the splits,
`"asm": true` unit records and `.s` bodies are gone and every function is
unmatched again. `python3 configure.py && ninja` printed `16 files OK` after the
revert. The local ledger rows were moved from `asm` back to `unmatched` and their
attempt counters reset so the functions are claimable.

Two of the 60 were then worked in C.

## fn_1_7B2E8 - 87.6%, blocked on interior-address materialization

The saved body reproduces the whole control flow: cache check, three `sprintf`
calls, the two `fn_1_D38C4`/`fn_1_D35D4` loads, the accumulate loop and the tail
stores. The remaining rows are:

- retail materializes `addi r31, r27, 0x2b4` (the course cache), `addi r4, r29,
  0x17c` and `addi r3, r29, 0x18c`; our compile folds all three into
  `lha 0x2bc(r27)`, `psq_st 0x17c(r29)` and `stfs 0x18c(r29)` and so keeps one
  fewer value live (frame 0xa0 vs 0xb0, `_savegpr_24` vs `_savegpr_23`);
- the tail therefore also stores in a different order, and `(f32)count` needs
  `s32 count` (the `xoris` form), not `u32`.

Measured: **no installed GC compiler** (all 21 under `build/compilers/GC`)
materializes a symbol+constant interior address for this shape. A minimal probe
(`Cache *c = (Cache *)((u8 *)&sym + 0x2b4); if (c->course != x) f(); c->course = x;`)
folds in every version, and so do the struct-member, `u8 *` base, live-base and
`volatile` spellings. The only spelling that materializes is a pointer escaping
into a call (`addi r31, r3, 0x2b4`), which retail does not have. This is the same
codegen gap recorded in `gc-symbol-offset-folding-and-load-update-20261026.md`.

## fn_1_1FDB0 - 94.2%, instruction stream identical, only FPR colours differ

The stream (124 rows, all immediates, all branches, both `lbl_8006D0B4` calls and
the `lbl_1_rodata_6D0`/`D4` clamp) matches retail row for row; 59 rows differ only
in the float register number (retail `f2,f0,f3` for the first `psvec_sub`, ours
`f5,f0,f1`). Measured no-ops on the colouring: swapping `num`/`den` statement and
declaration order, collapsing `t` into one expression, removing the `len2`
helper, dropping the unused-call temporary, moving scalar declarations above and
below the `Vec3` locals, and `#pragma opt_propagation off` (which regressed the
body to 90.0%).

Both remain unmatched with their bodies preserved in `.fzgx/attempts/`.

## Tooling: the constraint engine can now read paired-single code

`fzgx fixup --capture` runs on this host (lldb + wibo, replay verified, 0 errors) and
modeled `fn_1_1FDB0` exactly: `same_code`, `same_object`, two allocator passes, both
with a selection-order witness. The projection step was unreachable, though, because
`mwconstraints.target_mapping` stopped at the first `psq_l` of the body as
`unsupported-instruction` (row 3): the pinned capstone has no Gekko paired-single
decoder, and it reports several opcode-4 words as unrelated Altivec operations
(`ps_sub` -> `vmsumshm`), so every paired-single register was dropped from the
constraint set. `_recover_undecoded` now decodes opcode 56/57/60/61 (psq_l/lu/st/stu)
and opcode 4 with a form table that emits only the operand fields each mnemonic uses.

Measured after the change:

- matched paired-single siblings map onto themselves completely - `fn_1_7B558` 300
  words, `fn_12_11CE0` 159 words, both `fixed-graph-hypothesis`, 0 conflicts, 0
  incompatible rows, 30 and 20 registers bound;
- `fn_1_1FDB0` moves from `unsupported-instruction` (no data at all) to
  `needs-web-alignment` with six register conflicts and only two shape rows (64, 68),
  which are the swapped `lfs b.z` / `psq_l b.xy` pair in the clamp block.

The projection still requires an identical instruction shape, so this function needs
those two scheduling rows closed first; that is the next step, not a colour search.
