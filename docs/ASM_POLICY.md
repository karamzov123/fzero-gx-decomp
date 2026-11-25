# Assembly and compiler-diff device policy

Owner-directed source-faithful reconstruction standard, updated 2026-11-16.
This supersedes the blanket rules that whole assembly functions must be split into
`.s` files and that inline kernels must be moved out of C translation units.

The deciding questions are **what was the original implementation language and
organization, and what does this game's retail object prove?** A `.c` suffix does
not make a function natural C, and a matching hash does not prove source fidelity.
See [the pinned convention survey](RECONSTRUCTION_STANDARDS.md).

## 1. Evidence for original assembly

SDK, runtime, MetroTRK and middleware sources can legitimately contain whole
assembly functions and assembly blocks inside C functions. Reconstructing their
original form is not a compiler-diff device.

Record evidence next to the implementation and in reviewed provenance. Useful
positive evidence includes:

- a version-compatible SDK/middleware reference showing that routine or block as
  assembly, cross-checked against this game's instructions and relocations;
- copied or patched exception-vector/trampoline fragments, entry labels, privileged
  machine-state operations, or context saves that must precede a C prologue;
- an instruction form, register contract or update chain shown by a concrete MWCC
  probe not to arise from the proposed C or intrinsic implementation.

A tiny leaf with no stack frame, an unfamiliar instruction, a difficult allocation
mismatch, or another project's assembly workaround alone is not proof. Do not
classify every `mfspr`, carry operation or paired-single instruction as necessarily
hand-written: account for compiler intrinsics and generated forms.

Prefer a genuine compiler intrinsic when it fits the original source abstraction
and matches. Measure its effects on scheduling and registers. Do not split or
rewrite a known original mixed C/assembly routine solely to make it look like C;
do not replace ordinary compiler-generated C with assembly because it is easier.

## 2. Preferred reconstruction form

1. **Original C or C++:** reconstruct natural source in the original language, with
   shared types, meaningful operations and the measured compiler/ABI settings.
2. **Original CodeWarrior assembly functions in a C/C++ translation unit:** keep
   `asm` functions, `nofralloc`, operand parameters and entry labels alongside the
   related C when evidence supports that organization. Preserve static linkage and
   native data/literal ownership. Whole-TU fidelity is preferred over artificial
   splits; a split is an incremental build technique, not the final goal.
3. **Original inline assembly:** keep the block in its original C function. Use a
   shared header macro or inline helper where the original abstraction was shared
   or evidence supports it, not as a mandatory hiding place for all assembly.
4. **Original standalone assembler:** retain a `.s` unit with `asm: true` in
   `units.json`. Existing verified standalone reconstructions remain valid; migrate
   them only through a reviewed, compiler-backed change with positive evidence.
5. **Uncertain language or organization:** preserve the verified reconstruction,
   record the uncertainty and investigate. Another game's SDK version is a lead,
   not authority to copy its body, layout, pragma, assertion or compiler options.

Original assembly commonly appears in architecture-register helpers, cache and
context routines, runtime save/restore stubs, exception entry, and paired-single
math. This is a reason to investigate those families, not blanket approval of them.

### Scoped enforcement and OS.c

`config/original_assembly.json` records reviewed C-source assembly spans by source
path, enclosing function, form and SHA-256 of the comment/whitespace-independent
assembly tokens. A3 checks whole CodeWarrior asm functions as well as inline blocks.
An added, changed, moved, duplicated or missing registered body requires review;
there is no file-wide exemption and `fzgx-allow: A3` cannot authorize one.
This is a review guard, not an exhaustive C preprocessor or a replacement for the
compiler and retail oracle. Header kernels remain reviewed shared infrastructure.

The accepted OS.c form is one mixed translation unit: `__OSDBIntegrator`,
`__OSDBJump`, `__OSFPRInit`, `OSExceptionVector` and
`OSDefaultExceptionHandler` remain original assembly functions. `__OSPSInit`
retains its C calls/prologue/epilogue and original GQR-reset block. Their copied
fragment boundaries and the original small-data/literal layout remain intact.
No per-file lint exemption or artificial OS split is needed.

Runner-bound matchers still must not introduce assembly or modify the registry.
Original-assembly additions, migrations and header kernels are reviewed changes
made through a PR or an owner-directed manual session. Preserve attribution and
follow [the source-import policy](SOURCE_IMPORT_POLICY.md).

## 3. Compiler-diff devices

A device is a construct whose sole purpose is to steer compiler output and that
the original plausibly did not contain: dead compares/stores, inert identity
helpers, fake parameter/local copies, value-preserving bit tricks, unjustified
`volatile`, padding or pragmas used solely to force an allocation/schedule.
An original ABI declaration, SDK `register` operand, hardware `volatile`, genuine
representation union or evidenced SDK pragma is not a device merely by spelling.

- New device-free reconstruction is the preferred deliverable. A matching device
  is not natural-C completion. Do not weaken guards or relabel debt to claim it.
- Existing accepted devices remain tracked debt; do not regress a verified match
  simply to remove a marker. A reviewed debt change must be explicitly identified
  as a device, not ordinary source progress.
- Every device has a comment starting `WARNING: compiler-diff device, not original
  code`, giving the honest form and measured residual (rows or words). Device
  changes identify themselves in commit and PR titles.
- Assembly inserted solely to steer the compiler, such as dead register writes,
  is not original assembly. A scoped original-assembly entry cannot legitimize it.
- Removing a device is real remaining work. Replacements still need the full
  compiler, object, relocation, lint and sixteen-target hash gates.

Inventory both `WARNING: compiler-diff device` and `WARNING: device` in `src/` and
`include/`. Marker counts are not a count of distinct devices or affected functions;
unmarked constructs still need review.

## 4. What "done" means

The active target is USA GFZE01. Completion requires:

1. all functions and data in its sixteen executables match;
2. natural C/C++ wherever the original used C/C++;
3. original assembly only with evidence and an appropriate reconstruction form;
4. zero compiler-diff devices, with readable shared types and reproducible ownership.

Other regions require their own legally obtained inputs and separate verification.
Executable parity alone does not prove source-owned data or reconstructed assets.

## 5. Metrics

Report binary matching, source form and device debt separately:

- **Binary match:** regenerated objdiff report and all sixteen independent hashes;
  identify any retail fallback objects rather than treating them as authored source.
- **C-authored credit:** `fzgx sync`, then `fzgx honest`; this excludes registered
  original asm functions, mixed functions and standalone assembly. It can still
  include unclassified header kernels and compiler-diff devices, so it is not a
  certified device-free natural-C total.
- **Assembly/mixed source:** the current configured function inventory, ledger
  `asm` status and per-function `source_form`. Mixed C/assembly is distinguished
  from whole-function and standalone assembly, regardless of file suffix.
- **Device debt:** marked spots and files, plus any audited unmarked debt. A
  device-free total needs a separate audit; do not infer it from C file counts.

Historical ledger rows include retired symbols. Use the current retail-function
inventory for denominators, and preserve all historical provenance when syncing.
