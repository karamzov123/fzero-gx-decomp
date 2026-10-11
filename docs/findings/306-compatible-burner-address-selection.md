# Compatible burner frontier: address selection, not register renaming

## Scope and stopping condition

Continuation of finding 305, limited to `fn_1_9A958` and `fn_1_A02F0`.
The standing fleet was gracefully drained; no claims were open during compiler
probes. No model sessions, asm conversions, accepted-source changes or new
repository test fixtures were introduced. Stop a measured hypothesis family
when it does not reduce the real differing words; do not repeat the old
5,847-variant pass with increased budgets.

## Improved declaration-compatible burner source

The starting compatible burner body reproduced 95.9434% / five aligned
residual rows. Calling the existing inline member accessor at the entry-table
load changes its addressing tree. It now reproduces **97.73585%**, with the
entire canonical `burner.c` prologue unchanged and only **two differing raw
instruction words** out of 53. It is not the old incompatible standalone
97.73585% body, despite having the same fuzzy score.

The selected source's pointer-table and index views were checked against retail:

- The table window starts at `.data:0x2AF74`, within `lbl_1_data_2AF68`
  (size 0x16C), at suboffset 0xC. The remaining 0x160 bytes form 88 pointer slots.
- Retail relocations point to string objects. The exact formats inside
  `lbl_1_data_2CB60` are `%s%s.tpl.lz` at +0x10, `bg/` at +0x1C, and `%s%s.gma.lz` at
  +0x20. Both formats occupy 0xC bytes including their terminators; the view
  corrects the second format's former four-byte extent. The pointer table
  consequently uses `const char *` rather than untyped entries.
- The index object is `lbl_1_data_2B0D4`, size 0x70. Replacing the one-element
  index view with that proven extent and reducing the following gap from 0x1A9B
  to 0x1A2C preserves all later field offsets and all emitted function words.

No owned shared global was redeclared, no initialized data was transferred,
and the generated shared header was not changed.

### Exact residual and effective address

DTK disassembly of the actual retail object confirms the two non-relocated
encodings below. Whole-function word comparison masks relocation fields; the
full oracle separately checks relocation bindings.

| word index | retail encoding/instruction | selected compatible encoding/instruction |
| ---: | --- | --- |
| 15 | 0x387F0EB4: `addi r3,r31,0xEB4` | 0x7C7F0214: `add r3,r31,r0` |
| 16 | 0x7FC3002E: `lwzx r30,r3,r0` | 0x83C30EB4: `lwz r30,0xEB4(r3)` |

The preceding `slwi r0,r3,2` is identical. Both sequences read from
`r31 + 0xEB4 + 4*selected`, so this is load-address instruction selection,
not a wrong struct displacement or a physical-register permutation. The
word-adjusted score is 96.23%; fuzzy similarity alone is not the routing metric.

An alternative explicit-offset form reaches 98.58491% fuzzy but has **three**
differing words / 94.34% word-adjusted. It is retained as evidence, not selected
as the better frontier merely because its fuzzy score is higher.

## Sound candidate: scheduling remains

The declaration-compatible `fn_1_A02F0` still reproduces **98.1982%**, with
111 instructions and two different words at positions 11 and 12. Retail emits
`li r27,1` then `stw r3,8(r31)`; ours emits those same two instructions in the
opposite order. The canonical sound prologue and fn_1_46B4 ABI remain intact.

Scoped tick/one materialization with u8 and u32 locals and a separate tick
variable does not change that residual. Moving the flag store first regresses
it to six aligned rows. No store-order or instruction-scheduling pragma was
invented or silently ignored.

## Bounded probes and compiler evidence

26 targeted probes were recorded: 25 compiled, one failed because replacing an
initialized declaration with an assignment put statements before remaining C89
locals. Moving the assignment after all locals fixed that setup error; it did
not improve the object. The failed setup is not counted as evidence against
parameter reuse or against a model.

Measured families include argument reuse, explicit byte-offset load trees,
member indexing/commutation, inline explicit base versus member address,
proven string pointer types/index extent, and scoped tick/constant lifetimes.
A byte-width `selected` local adds `clrlslwi` where retail uses `slwi`, so the
selected frontier retains the promoted integer index after the byte load.
Deriving the index pointer from the physically adjacent entry table
(`owner->entries + 0x58`) also preserves the same addressing-form residual;
that real shared-address dependency does not realize retail's load selection.
The fresh compatible sources were also checked at GC/1.2.5n, GC/1.2.5, GC/1.3
and GC/2.0. The 1.2.5 variants regress substantially; 1.3 and 2.0 reproduce the
same narrowed residuals as GC/1.3.2. None of the 26 probes is exact.

The final two sources were prepared through the existing fixup engine with
zero search rounds, then captured with the pinned stock GC/1.3.2 compiler.
Both captured objects equal their normal compiled baselines. Both GPR allocator
passes replay with zero color/simplify errors and zero unsupported simplify
cases. No source-realizable declaration projection was produced. Capture and
replay were rerun after changing the string/index view; old source hashes were
not reused for the new source.

## Diagnostic correction

`mwconstraints.target_mapping` previously reported these two objects as
`needs-web-alignment / commutative-only` with an identity rename, despite its
own incompatible rows containing changed opcodes or moved instructions.
That identity satisfied only the compatible rows, not the whole function.

The diagnostic now reports subkind `instruction-shape` and does not advertise
that partial rename as a complete witness. The conservative outer status and
acceptance behavior are unchanged. Verification used the actual two compiled
functions (red before, green after), each captured object's identity mapping,
and the real archived `fn_1_B7CE4` operand-order case. The latter still obtains
`fixed-graph-hypothesis` with its genuine commuted operand at word 28.

## Reproducible deliverable and remaining boundary

`state/repairs/compatible-residual-frontiers-20261011.json.gz` retains both final
C sources, source/prologue/header/compiler hashes, settings, raw target and
baseline words, all 26 probe bodies/results, stock allocator captures and
validation reports. It uses the existing graph archive format:

    .venv/bin/python tools/fzgx.py fixup --archive state/repairs/compatible-residual-frontiers-20261011.json.gz

This replays two functions / two allocation passes with zero errors. That replay
validates allocator evidence, not a retail match; separate pinned oracle checks
prove the reported nonexact frontier scores. `same_object=100%` in a capture
report compares instrumented compilation with its normal baseline, not retail.
The archive explicitly includes each retail verdict to keep that distinction.

The existing priority seed now contains the improved compatible burner body,
its exact word residual and archive reference. The higher-scoring raw alternative
and incompatible standalone body are not used to overwrite it.

**Accepted executable bytes from this continuation: zero.** Do not route either
function as an allocator-only plateau, or repeat the measured spelling/compiler
families unchanged. Further closure needs a source-realizable instruction-selection
witness for burner and a scheduling witness for sound. Neither is supplied by
the existing allocator declaration projection.
