# 354 — fn_10_924C: shared index across exclusive paths closes a three-word initialization frontier

Manual continuation, 2026-10-16, hermes-sol-manual / gpt-6.1-sol.
**MATCHED, link-verified, commit `a5980408`: 576 bytes / 144 instructions.**

The saved best C had three differing positional words, indices 70, 71, 72.
Retail emitted `li r27,0; addi r26,r1,8; mr r28,r27`; the source initialized
independent zero values instead of preserving the counter-to-zero copy.

Previous initialization/declaration shuffles, an all-u32 web, for-loop form,
and manually expressed zero copies had failed. Apply the shared-index law
without inventing an explicit strength-reduced pointer or allocator wrapper:

- Declare `s16 i` at function scope.
- Use it for the first branch's selected-bit index instead of a separate `a`.
- In the exclusive else branch, explicitly reset `i = 0` before initializing
  the entries array's pointer/zero locals.
- Keep those subsequent declarations in a nested block, because this compiler
  rejects mixed declarations after statements in the same C89 block.

These are exclusive paths, so no prior index value flows into the array loop.
The nested scope is necessary source syntax, not new machine-code padding.

Bounded stock-GC/1.3.2 measurements:

| Source | Words | Positional differences |
| --- | ---: | ---: |
| Original | 144 | 3 |
| Shared index with mixed declarations after assignment | — | compiler rejects C89 syntax |
| Shared index, chained `zero = i = 0` declaration | 144 | 13 |
| Shared index, explicit reset and nested declaration scope | 144 | **0** |

Retain the last form. Rename the existing archive-path pointer temporary to
reflect its actual use and indent the new scope; first full `write-unit`
check remains **100.0% MATCH**, lint clean. No new pragma or helper was added.

`submit` accepted without pool repair. `verify` reported exactly fn_10_924C
verified, no rejected functions, commit `a5980408`. Manifest is matching and
ledger link_state verified. All 16 SHA-1 targets and whole-project lint pass.

The successful complete source and failed bounded probes are preserved in
`state/repairs/manual-exclusive-index-and-title-pool-20261016.json`.
