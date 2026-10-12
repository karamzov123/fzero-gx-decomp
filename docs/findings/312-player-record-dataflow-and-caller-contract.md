# Player-result dataflow and the large renderer's caller contract

## Scope and evidence

Continue fn_1_15C6C0, the blocked 5,820-byte main_rel renderer. Its existing
compiler-pinned typed-table frontier remains 83.79% adjusted / 238 differing rows.
No further large-function closure is claimed in this pass.

A read-only retail scan identifies 26 main_rel functions using the shared owner
and a 0xA0 stride or the selector at global offset 0xA7. Specific producer/consumer
assembly is preserved rather than replacing a whole object from inferred names.

fn_1_2E928 proves the first indexed 32-bit value at entry+0x24 is composed as:

    (byte at input+0x1E0 << 20) |
    (byte at input+0x1E1 << 12) |
    halfword at input+0x1E2

The adjacent indexed field at entry+0x38 uses input+0x1D4/1D5/1D6 with the same
packing. There is no extra halfword mask in those instruction sequences; do not
invent one. fn_1_14B500 reads both fields and an indexed halfword at entry+0x18.
The 0xA0 entry stride and +0xD4 owner displacement are independently repeated in
initialization/sorting/update consumers. A complete array bound and whole-record
semantic struct are NOT established by this evidence.

The rank-output producer fn_1_156218 writes 32 bytes to its first and third
outputs and a halfword ending at byte 26 to its middle output. This is written
extent evidence, not proof that the complete source objects have those sizes.
Retail renderer stack slots remain 56 bytes apart. Shrinking its Rank objects
solely from the callee's last store would be a guess.

## Bounded hypotheses

An initial claim about extra 0x41000000 branches was wrong: the current source
contains neither branch. The intended-edit assertion failed before any change.
The incorrect claim was explicitly corrected; no fabricated control-flow repair
is retained or credited.

A narrow field view with a real +0x24 displacement and a u32 time value was tested
at both renderer loads. It preserves the stride/index arithmetic and avoids
inventing a complete array bound. GC/1.3.2 emits the same 83.79% / 238-row result,
including the addi/lwzx selection. The source-shape hypothesis therefore does not
repair that instruction difference; no additional generic permutation sweep was
launched.

The actual matched caller's block declares the renderer as (u16,int), whereas
the compiled frontier defines it as (s32,s32). Narrowing the frontier's first
argument to u16 worsens adjusted similarity to 80.36% / 293 rows and changes the
save-helper boundary. This caller prototype alone is not proof of callee source
type or permission to overwrite the better frontier.

## Compilation contract change integrated

fn_1_15DFD4 calls the renderer with the existing u16 counter loaded from
lbl_1_bss_50EC[index]. Its standalone baseline and declaration-compatible source
both match retail at 100% under the unit's recorded compiler/options.

The caller declaration is now:

    extern void fn_1_15C6C0(s32, s32);

This removes a C declaration conflict with the current signed frontier while
preserving the caller's machine code. It does not add casts, change the counter
storage, assert a newly proven callee ABI, or change the other functions in its
shared source file. The large renderer remains nonmatching and blocked from
blind model dispatch. This is a caller-side compilation prerequisite, not 508
newly decompiled bytes.

The standing fleet was drained and claims cleared before the source edit. Fresh
configure/Ninja relink regenerated the RELs and all sixteen executable hashes
pass. Ordinary lint has zero findings; the eleven existing tests pass outside
the build lock. Existing configure notices and linker section warnings remain;
the build is not reported warning-free. Protected operator-file hashes are intact.

## Provenance and next boundary

state/repairs/15C6C0-record-dataflow-and-caller-contract-20261011.json.gz contains
five actual retail producers, the 26-function cohort, both rejected/equal-score
source probes and their verdicts, and the caller's exact baseline/compatible C.
No model sessions, new repair runner, opcode fixtures, guessed initialization or
new executable-byte ownership were introduced. The remaining large-function
work is variable-web/source selection and full storage reconstruction. A no-change
field-view probe is not evidence that arbitrary register forcing is needed.
