# 350 — fn_1_152510: shared scan/init index closes the literal-zero vs register-copy frontier

Manual continuation, 2026-10-16, `hermes-sol-manual` / `gpt-6.1-sol`.
**MATCHED, link-verified, commit `1114cbb4`.** 816 bytes / 204 instructions.

The saved body had 98.0% similarity and four differing positional words,
all at the initialization-loop preheader. Retail initializes its counter
with `li r6,0`, then initializes the strength-reduced row base with `mr r4,r6`.
The saved C used separate signed-16-bit counters `i` (availability scan),
`j` (table initialization), and `n` (input IDs). It emitted independent
literal-zero initializations for the row counter and row base.

Previous attempts at an explicit `base = j`, base += cols, or row-base local
had moved the entire loop allocation and regressed badly. Finding 346's
shared-counter law suggested retaining the implicit induction shadow and
sharing the original source index instead of manufacturing the shadow in C.

## Minimal change

Remove `s16 j;` and use the existing `i` in the second outer loop and its
`table[(i * cols) + k]` indexing. The source still explicitly initializes the
second loop with `i = 0`; no value from the first loop leaks into its semantics.
Leave `n` independent in the final loop.

Bounded stock-GC/1.3.2 probes:

| Source | Words | Differing positional words |
| --- | ---: | ---: |
| Original separate counters | 204 | 4 (27, 28, 29, 30) |
| Share first and second counters | 204 | **0** |
| Share second and third counters only | 204 | 4 |
| Share all three outer counters | 204 | **0** |

Installed the smaller first/second-only change. No new pragma, one-field
wrapper, helper, padding, volatile access, compiler patch or object edit.

## Acceptance

- `write-unit`: lint clean, **100.0% MATCH** on its first check.
- `submit`: accepted without pool repair, pending link.
- `verify`: verified only `fn_1_152510`, no rejections; commit `1114cbb4`.
- Independent SHA-1 validation of all 16 build targets: **OK**.
- Whole-project lint: **0 findings**.

Both successful source forms and probe results survive in the portable
`state/repairs/manual-shared-index-and-colors-20261016.json` evidence archive.
This is another measured shared-index closure, not evidence that arbitrary
loop-variable reuse will fix register-only plateaus.
