# Large main_rel reconstruction: six-strip storage and the compilation path

## Scope: the 5,820-byte fn_1_15C6C0, not small cleanup

This pass works on the large main_rel renderer's actual data storage and source
compilation. It does not close the complete function or claim authored C bytes.
The 9,832-byte fn_1_BC310 remains a separate unresolved dataflow obligation.

## Retail storage proof

The saved source obtains six rectangles via lbl_1_rodata_DD58+0x64. DTK records
DD58 as a four-byte .rodata object; that declaration is not proof of the table's
storage extent. The existing pool-object/payload helpers identify the containing
owner as lbl_1_rodata_DD98, at .rodata:0xDD98, size 0xB8. The rectangle bytes start
at owner+0x24 and occupy 96 bytes, entirely inside that object. No relocations lie
in the slice. All 24 big-endian signed words equal the saved table initializer.

The six (x,y,width,height) records are:

    (0,0,75,100), (76,0,35,100), (152,0,75,100),
    (76,0,35,100), (228,0,75,100), (304,0,75,100)

The source now represents them as a typed Strips/Strip constant, not an arbitrary
oversized array, opaque placeholder or guessed global struct. The function copies
that typed constant into its 96-byte local array before the existing render loop.
The initialized table comes from actual retail payload, not synthetic test data.

## Hypotheses and stock compiler results

A bounded reference to the real external owner was tested first. It fixes the
extent reference but retains a separate external base plus the private constant
pool: adjusted similarity 83.08%, 249 differing rows. It was not the best
compilation form.

Referencing the already verified native initialized table permits MWCC to share
the table's private literal-pool base with the function's constants. A typed
six-rectangle initializer and direct struct assignment reproduce the same result
without the former u32-array-to-Strips cast:

- Prior source: raw 95.971825%, adjusted 83.15%, 248 differing rows.
- Typed native table: raw 96.4268%, adjusted 83.79%, 238 differing rows.

The source retains ordinary arithmetic/control flow and the pre-existing pool
primer mechanism. No local register-forcing padding or no-op liveness expression
was added. The owner declaration and all compiler settings are preserved in the
archive, as are the slightly worse bounded-owner alternative and the baseline.

Stock object bytes match the complete 248-byte pool starting at retail DD58,
including its adjacent DD60/DD6C/DD98 objects. The oracle now proves
DD58=initializer[248] alongside the scalar bindings. Oracle pool-list entries are
successful byte proofs, not compiler failures; remaining register/value/control
flow differences still prevent matched_pool or exact-function acceptance.

One typed-source preparation attempt failed because the typedef insertion had
not occurred before the initializer. The source was inspected, the definitions
were placed before use, and the intended-edit assertion added before recompile.
This setup failure is not compiler evidence against the rectangle layout.

## Next compilation step executed: registration and coherent context

The frontier also compiles unchanged after adding the actual bg_win shared-TU
prologue. The fleet was drained before configuration edits and no claims remained.
The existing carve tool dry-ran and registered this exact executable range:

    .text [0x15C6C0, 0x15DD7C), alignment 4
    rel/main_rel/bg_win/fn_1_15C6C0.c

The unit is explicitly nonmatching and pinned to the measured GC/1.3.2 compiler.
A fresh check through the registered-unit path retains 83.79% / 238 rows. This
removes missing split/registration as a future integration obstacle; it does not
link partial C as if it were exact. The build continues to use its retail fallback
until the existing verifier accepts a genuine exact candidate.

The stock allocator capture covers this real shared-TU source. Normal-object and
replay checks pass with no errors; the portable replay includes one function and
two allocation passes. These validate the capture, not equality to retail.

The target remains blocked from generic model dispatch because 238 residual rows
are not a near-exact task. Its three historical attempts and old raw score are not
permission to retry stale source. Manual frozen-source capture was run only while
the fleet was off: the existing loader excludes blocked targets, so the API block
was temporarily lifted and restored in finally. No claim or model session was
created by that diagnostic operation. state/blocked.md preserves the reason and
points to the new typed frontier.

## Verification and continuation boundary

Completed acceptance gate: fresh configure plus 172 Ninja steps, all sixteen
executable hashes, zero ordinary lint findings, eleven passing tests outside the
build lock, and exact provenance checks that only one unit was added and all prior
unit records were preserved. The build is not warning-free: it emitted 915 warning
lines and configure retained its missing-source/missing-configuration notices;
no claim is made that those separate obligations were repaired here.
Registration preserves existing split ownership; the partial frontier is not
credited as authored executable C. The standing two-slot Codex high policy and
parked Hermes ultra policy are unchanged; restore the service after the gate and
selective local commit.

state/repairs/15C6C0-storage-and-compile-path-20261011.json.gz contains the exact
storage proof, typed shared-TU source/hash, all source alternatives and verdict,
retail assembly, stock allocator capture and new unit metadata. New authored
executable bytes remain zero. Remaining work is the renderer's BSS/player-record
views, FPR/variable webs and branch/operand shapes; none is declared solved by
this rectangle-storage repair.
