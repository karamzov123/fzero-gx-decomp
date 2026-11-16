# Coding rules

These rules keep the tree shiftable and readable. `fzgx lint` enforces A1, A2, A3,
S1, S2; `fzgx submit` refuses a unit that fails lint. Follow the source-faithful
forms in [ASM_POLICY.md](ASM_POLICY.md) and [RECONSTRUCTION_STANDARDS.md](RECONSTRUCTION_STANDARDS.md).

## A. Shiftability (hard rules)

- **A1** No integer literal in `0x80000000..0x817FFFFF`, `0xC0000000..0xC17FFFFF`
  or `0xCC000000..0xCC00FFFF` anywhere except `include/dolphin/hw_regs.h`. Hardware register
  blocks are the link script's absolute symbols (`extern vu32 __DIRegs[];`, see
  `config/GFZE01/ldscript.tpl`); a raw literal is allowed only with a `/* fzgx-allow: A1 ... */` comment.
  Every cross-reference is a symbol. If the disassembly shows `lis/addi` to an
  address, find or declare the symbol at that address (`symbols.txt`).
- **A2** No `(T *)0x8...` casts. Declare `extern T name;` instead.
- **A3** C-source assembly bodies require reviewed original-assembly evidence and
  a matching path/function/form/body entry in `config/original_assembly.json`.
  No whole-file exemption or inline `fzgx-allow` can authorize new assembly.
- **Symbol ownership** Data referenced by code gets a symbol and a declaration; never compute
  an address arithmetically from another symbol unless the original code does
  (array indexing is fine; `&symbol + 0x1234` across objects is not).
- **A4** Do not depend on link order or on gaps between objects.

## S. Style

- **S1** `goto` only when the control flow is genuinely irreducible, with a
  one-line comment naming why on the same or previous line.
- **S2** `volatile` and codegen-only `union` need a one-line justification
  comment on the same or previous line. Hardware registers are the normal
  reason.
- **S3** Names: use the community vocabulary in `docs/VOCABULARY.md` first,
  then descriptive `snake_case` for game code; SDK names verbatim. Generated
  names (`fn_...`, `lbl_...`) may remain only while a function is unmatched.
  Propose names through the submit sidecar; do not rename other units' symbols.
- **S4** 4-space indent, K&R braces, comments say why. No dead code, no commented-out asm.
- **S5** Reference adaptation from Dolphin SDK decomps is allowed; credit goes in
  `docs/RESOURCES.md` at file level.

## Opting out

A single line may carry `// fzgx-allow: A1 <reason>` (or A2/S1/S2). Use it
rarely and only with a reason a reviewer would accept.
