# Source-faithful reconstruction standards

Owner-selected project standard, 2026-11-16. The target is the original source's
language, abstractions and translation-unit organization, verified against F-Zero
GX retail objects—not a preferred file suffix or the shortest path to a green badge.
[ASM_POLICY.md](ASM_POLICY.md) controls assembly, devices and completion gates.

## Observed community conventions

This survey inspected public source, not just README claims. These are examples of
practice, not proof of F-Zero GX's exact SDK version or a universal community rule.
The survey copied no implementation into the project. Source adaptations still
require compatible licensing, attribution and [the import policy](SOURCE_IMPORT_POLICY.md).

Pinned revisions inspected:

- Melee: `2f8eab8ebd7a2d25541e125abfa246defe1bacec`.
- Sunshine: `ec8be8ed3a7ae186575179ef78b8345aa7102345`.
- Wind Waker: `d217e2b5e1c1514e6f3f640835f83f01dd67aa72`.

### 1. Preserve mixed C/assembly SDK translation units

[Melee OS.c](https://github.com/doldecomp/melee/blob/2f8eab8ebd7a2d25541e125abfa246defe1bacec/libs/dolphin/src/dolphin/os/OS.c#L351)
and [Sunshine OS.c](https://github.com/doldecomp/sms/blob/ec8be8ed3a7ae186575179ef78b8345aa7102345/libs/dolphin/src/os/OS.c#L436)
keep debug trampolines, exception-vector bodies and handlers as CodeWarrior `asm`
functions alongside C. Both retain a C `__OSPSInit` with an inline block.
[Wind Waker OS.c](https://github.com/zeldaret/tww/blob/d217e2b5e1c1514e6f3f640835f83f01dd67aa72/libs/dolphin/src/os/OS.c#L457)
also preserves assembly in the translation unit; its `__OSPSInit` is whole assembly.
The versions differ: Melee's shown block resets only GQR0, whereas GX retail resets
GQR0–GQR7. Adopt the organization when retail supports it, not another game's bytes.

GX application: retain OS.c as one mixed unit, its static scopes, copied-fragment
labels and native small-data/literal layout. The earlier separate OS fragments
were hash-correct but a build-policy workaround, not the preferred final form.

### 2. Architecture, cache and context routines legitimately use assembly

[Melee PPCArch.c](https://github.com/doldecomp/melee/blob/2f8eab8ebd7a2d25541e125abfa246defe1bacec/libs/dolphin/src/dolphin/base/PPCArch.c#L5)
uses `asm`/`nofralloc` for architecture-register leaves.
[Sunshine OSCache.c](https://github.com/doldecomp/sms/blob/ec8be8ed3a7ae186575179ef78b8345aa7102345/libs/dolphin/src/os/OSCache.c#L15)
and [OSContext.c](https://github.com/doldecomp/sms/blob/ec8be8ed3a7ae186575179ef78b8345aa7102345/libs/dolphin/src/os/OSContext.c#L11)
retain cache-control and context-save/restore assembly in their SDK sources.
[Wind Waker PPCArch.c](https://github.com/zeldaret/tww/blob/d217e2b5e1c1514e6f3f640835f83f01dd67aa72/libs/dolphin/src/base/PPCArch.c#L63)
also mixes C representation handling with inline FPSCR access.

GX application: investigate these families as possible original assembly. Preserve
fixed incoming-register contracts, exception-state behavior and special-register
operations rather than forcing unsafe C prologues. A frameless leaf alone is not
proof. [Sunshine OSTime.c](https://github.com/doldecomp/sms/blob/ec8be8ed3a7ae186575179ef78b8345aa7102345/libs/dolphin/src/os/OSTime.c#L33)
also defines OSGetTick as a CodeWarrior asm/nofralloc time-base leaf, corresponding
to GX retail 80011424..8001142C. Our existing OSGetTick source is assembly even
though compiled from `.c`; the reviewed registry now records that fact.

### 3. Portable C and paired-single assembly are distinct implementations

[Melee mtxvec.c](https://github.com/doldecomp/melee/blob/2f8eab8ebd7a2d25541e125abfa246defe1bacec/libs/dolphin/src/dolphin/mtx/mtxvec.c#L26)
and [Wind Waker mtxvec.c](https://github.com/zeldaret/tww/blob/d217e2b5e1c1514e6f3f640835f83f01dd67aa72/libs/dolphin/src/mtx/mtxvec.c#L5)
keep C_MTX operations and optimized PSMTX assembly as separate routines. The latter
uses CodeWarrior `register` operands and paired-single load/store/arithmetic forms;
Wind Waker guards the implementation with `__MWERKS__`.

GX application: do not substitute a portable C variant for a different optimized
retail entrypoint or call it a natural-C conversion. `register` in an original SDK
asm operand list is legitimate; fake register-pressure locals in ordinary C are not.
Existing reviewed shared header kernels remain supported, but new placement should
follow the evidenced original abstraction, not a universal header-only rule.

### 4. Hardware volatility and representation types are legitimate abstractions

[Sunshine OSContext.c](https://github.com/doldecomp/sms/blob/ec8be8ed3a7ae186575179ef78b8345aa7102345/libs/dolphin/src/os/OSContext.c#L8)
uses volatile low-memory context bindings and shared SDK context types.
[Wind Waker PPCArch.c](https://github.com/zeldaret/tww/blob/d217e2b5e1c1514e6f3f640835f83f01dd67aa72/libs/dolphin/src/base/PPCArch.c#L63)
uses a representation union for FPSCR transfers. These are not inherently codegen
tricks. Conversely, adding volatile to an ordinary object merely to force a reload
remains device debt.

GX application: retain recovered SDK/engine types, callback signatures and array
bounds, prove offsets/layout with MWCC, and use our linker-bound MMIO/low-memory
symbols. Do not copy other projects' raw address declarations around our shiftability
guards. Preserve genuine unions/bitfields when evidenced; do not invent them to
manipulate scheduling or allocation.

### 5. Compiler settings and match status are version-specific

[Sunshine configure.py](https://github.com/doldecomp/sms/blob/ec8be8ed3a7ae186575179ef78b8345aa7102345/configure.py#L351)
and [Wind Waker configure.py](https://github.com/zeldaret/tww/blob/d217e2b5e1c1514e6f3f640835f83f01dd67aa72/configure.py#L367)
separate matching, nonmatching and version-specific object selection. Wind Waker's
[mtxvec.c](https://github.com/zeldaret/tww/blob/d217e2b5e1c1514e6f3f640835f83f01dd67aa72/libs/dolphin/src/mtx/mtxvec.c#L47)
contains an explicitly debug-only linker pragma: its existence is not permission to
import it into a retail GX match.

GX application: pin measured compiler versions, ABI/optimization/FP settings and
object selection. Keep actual SDK pragmas when evidenced; do not add arbitrary
pragmas to force a register schedule. Host/editor fallback code or a version guard
is not a verified retail implementation. A near-match PR is welcome as evidence,
not publishable matching source until the acceptance gates pass.

## Review and migration checklist

1. Identify the exact retail function/module, original language and likely library
   version. Prefer the native translation unit and shared declarations.
2. Cross-check reference routines, instruction forms, data extents, static scope,
   entry labels and relocation targets. Preserve unknowns rather than inventing types.
3. Reconstruct C naturally where it was C, original assembly where evidenced, and
   mixed source where that was the original organization. Inspect intrinsics before
   inferring that an unusual instruction requires new assembly.
4. Preserve the selected compiler and native literal/data ownership. Splits and
   literal retargeting are verified tooling, not permission to fabricate source
   structure. Simplify them when a faithful whole TU naturally reproduces the layout.
5. Record attribution, evidence and scoped assembly approvals. Do not introduce a
   file-wide lint waiver or count mixed/whole assembly as C because of its suffix.
6. Build with MWCC; regenerate object/data comparisons; verify all sixteen hashes,
   lint and saved data-import replay; snapshot provenance and publish only the clean,
   pinned commit through the approved publisher.

This audit changed OS.c's organization, assembly enforcement/classification and
documentation. It did not rewrite other SDK families wholesale. Those remain
per-function investigations with the same evidence and verification requirements.
