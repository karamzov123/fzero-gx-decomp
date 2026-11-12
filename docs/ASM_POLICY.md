# Assembly and compiler-diff device policy (owner, 2026-11-12)

This replaces the earlier rule "header asm kernels only where other decomps do the same". The question
that decides whether assembly is allowed is **was the original code assembly?**, not whether another
project happens to use asm for similar code.

## 1. Allowed assembly: only where the original was plausibly assembly

Nintendo's SDK, the Metrowerks runtime, MetroTRK and middleware such as CRI/Sofdec, MusyX and ADX wrote
some code in assembly: whole `asm` functions (`OSContext`, `OSCache`, `__save_gpr`/`__restore_gpr`,
`PSMTX*`) or `asm {}` blocks inside C functions (GX matrix writes, CRI pixel kernels). Reproducing those
as assembly is matching, not cheating.

Assembly needs evidence, recorded in a comment next to it. Any one of these is evidence:

- instructions MWCC never emits from C: `psq_*` in forms the compiler does not generate, `mfspr`/`mtspr`,
  `mfmsr`/`mtmsr`, `dcbz_l`, `mcrxr`, `addc` carry tricks, `stfdu`/`lwzux`/`lfdux` update chains that C
  folds (measure it: write the C, report the word count it misses by);
- no MWCC prologue/epilogue (`nofralloc` shape), or register usage no compiler allocation produces;
- known SDK/middleware source shows the function or block as assembly.

If a compiler intrinsic exists (`__dcbz`, `__dcbt`, `__fabs`, `__frsqrte`, ...) and still matches, use
it instead of asm. Measure it; intrinsics often change the surrounding schedule (fn_12_3C17C: 193 words).

## 2. Form

- **Whole-function assembly** is an asm unit: `fzgx asm-unit`, `.s` in `src/`, `asm: true` in
  `units.json`, ledger status `asm`. It counts as matched, not as C.
- **Small kernels inside a C function** live in `include/` headers as macros or inline functions on the
  caller's register variables (`include/psvec.h`, `include/sofdec/*_ppc.h`, `include/mathutil*.h`).
  Lint rule A3 keeps `asm` bodies out of `src/`. One kernel family per header; a landed header never
  grows (adding inline functions renumbers MWCC's `@N` literals in every includer).
- Matcher agents never add assembly. New kernels are reviewed changes (PR or owner session) that cite
  the evidence from section 1.

## 3. Compiler-diff devices

A device is any construct whose only purpose is to steer MWCC's code generation and that the original
code plausibly did not contain: dead compares or stores kept alive by `opt_dead_assignments off`,
identity inline helpers, parameter copies that exist only for register order, value-preserving casts
(`(u64)x | 0x100000000ull`), `volatile` on non-volatile objects, pragmas used only to move a register.

- Every device is marked with a comment starting `WARNING: compiler-diff device, not original code`,
  followed by the honest form and how far the honest form misses (rows or words). Commit and PR titles
  say "device".
- Prefer a C device over an asm device. **Assembly used only to steer the compiler** (for example the
  dead `asm { mr r6, x }` writes of `include/adx_compiler_diff.h`, PR #322) is the worst kind of device:
  it is tied to one compiler build and hides intent. It is accepted only as marked, tracked debt and is
  first in line for removal.
- Removing a device is real remaining work, ranked with unmatched functions. A replacement lands only if
  the function still matches and all 16 hashes pass.
- Open list: `grep -rn "WARNING: compiler-diff device\|WARNING: device" src include`.

## 4. What "done" means

The project is complete when:

1. every function of all 16 targets matches;
2. every function the original wrote in C is natural C;
3. assembly appears only where the original was assembly (sections 1 and 2);
4. zero compiler-diff devices remain.

## 5. Metrics

Report three numbers, never only one:

- **matched**: `fzgx report` (objdiff) and the ledger's matched + asm counts;
- **natural C**: `fzgx honest` (matched functions with a compiled C body), minus functions that still
  carry a device;
- **devices remaining**: the grep in section 3 (files and marked spots).
