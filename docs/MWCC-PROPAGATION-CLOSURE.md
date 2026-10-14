# Propagation/lifetime closure for MWCC floating-heavy functions

Use this when a structurally correct natural-C body has a few translation/float register differences and a broader optimizer change fixes one block but regresses another. First verify the compiler version/flags from the function context and actual check; the modern fzgx main REL may use GC/1.3.2, whereas a separate NATC target may require GC/1.2.5n.

## Preconditions

- Own an active claim for exactly one unmatched function.
- Preserve the best source and metadata before claiming; a new claim can clear prior best files.
- Establish semantics, field widths/offsets, whole-function control flow, stack aggregates, signed conversions, and actual hardware destinations before allocator experiments.
- Native signed/unsigned casts already implement their ABI bias subtraction. Do not subtract that bias again in C.
- Use existing native_pool_literals/shared_pool_primer generators only with measured retail bytes; submit-time retargeting must remove private primers.
- Compare non-pool instruction rows, frame, register moves, and actual operations. Raw objdiff is not exactness and an attempt's best percentage is not a candidate-specific adjusted score.

## Proven sequence

1. For damping signed short fields, test natural `velocity *= coefficient` instead of explicit cast/multiply/assign. This can fix bias/coefficient operand/register selection without extra storage.
2. Inspect a genuinely matched sibling which performs the same hardware/vector operations. Copy its complete relevant pragma context, not only a superficial variable order.
3. Test `#pragma opt_propagation off` around the entire function and restore it afterward. Regional optimizer pragmas within a function may be ignored; do not assume local control.
4. Declare translation scalars separately from assignments:

       f32 z, y, x;
       x = position.x;
       y = position.y;
       z = position.z;
       matrix[0][3] = x;
       matrix[1][3] = y;
       matrix[2][3] = z;

   Declaration order, assignment order, initialization order and store order are distinct codegen choices. Reversed initializers can get the registers right but load in the wrong order.
5. Declare a hardware pointer after a preceding transform call when it is only needed afterward. A pointer initialized before the call may be kept in a saved GPR and expand the frame.
6. If propagation-off fixes translations but regresses the final scalar arithmetic, remove redundant named intermediate webs instead of re-enabling propagation. A demonstrated exact shape is:

       output_x = (255.0f * (0.5f * (1.0f + gain))) / 255.0f;
       {
           f32 spread = (136.0f * gain) / 255.0f;
           output_y = spread;
           output_z = spread;
       }

   Naming a separate growth temporary, or defining spread before growth, can swap constant/temporary FPRs. Preserve all floating operations and rounding; do not algebraically cancel multiply/divide chains.
7. Recheck the entire function after every change. The successful block alone is not progress if another block regresses.

## Extended controlled experiments

For an explicit user-authorized plateau waiver, discover the installed API's FZGX_MAX_CHECKS/FZGX_MAX_STALE environment knobs and raise them only for the worker process. Preserve claim ownership, admission lint, duplicate/refusal handling, compiler pin, semantics and exact/link gates. A controlled family can permute truly independent loads/stores without adding storage or extra arithmetic. Record source hash, hypothesis, actual compiler and flags, complete errors, non-pool row count and source path; append to a scratch JSONL and reduce programmatically.

Do not introduce dummy padding, physical register bindings, unused allocation-forcing locals, inline asm, or helpers whose only purpose is register pressure. Correct scalar lifetime/expression shape closed the demonstrated function without these devices.

## Acceptance and integration

An exact object has zero differing non-pool instruction rows. Submit it, then run verify: submit's link-pending status is not a landing. Require the complete linked checksum gate, ninja/report generation and repository tests. Inspect exact commit hunks before pushing: verify can include unrelated pre-existing split entries if it stages a shared file. Narrow an unpublished commit at the index without touching the user's working file, prove source/manifest blobs unchanged, and update the verified commit reference through the existing ledger method.

## Parallel field tests

Assign distinct symbols and central reservations before launching workers. Use independent source trees, mutable build outputs and private SQLite backups, with only immutable compiler/tools/original inputs shared. An OS read-only mount of canonical/sibling source trees provides stronger isolation than prompts alone. Workers produce measured work-copy candidates and stable artifacts; only the supervisor revalidates in the canonical checkout, integrates, commits and pushes.

Before accepting a worker result, hash and read its actual source path. Private release moves/removes the work file; copy the source to a stable path before release or report the saved attempt path afterward. Filter liveness by exact symbol/agent because a private ledger copied from the canonical one contains sibling attempt rows too. Never treat a copied ledger's globally latest attempt as this worker's activity.

The exact demonstration is documented in `docs/findings/340-effect-64fb8-exact-closure.md`. Treat transfer to other functions as an experiment until each passes its own object and linked checksum gates.
