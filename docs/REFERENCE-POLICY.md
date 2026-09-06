# NATC Reference and Readability Policy

## Adapted reference code

Adaptation from the indexed trees under `indexed reference trees` is permitted. Every adapted function MUST carry a `// provenance: <project>:<file>:<line>` comment, and the batch `CARD.md` MUST record the same provenance. `dolsdk2001` is the Dolphin SDK itself and should be tried first; the game trees are useful revision references.

Every newly changed function body MUST carry a `CARD.md` entry and provenance. Use `// provenance: original` for a reconstruction that did not adapt a reference body.

## Readability line

| shaping | policy |
|---|---|
| declaration reordering to move registers | allowed without comment |
| extra local temporaries with no semantic role | allowed without comment |
| explicit empty `case X: break;` for a switch pivot | allowed without comment |
| `volatile` without a hardware reason | allowed only with a one-line justification comment |
| `union` used purely for codegen | allowed only with a one-line justification comment |
| `goto` | forbidden unless the target CFG is genuinely irreducible and the function has a one-line justification comment |

`volatile` and `union` without nearby justification are flagged in review. An unjustified `goto` blocks the change.

## Honest mission counting

Gap and padding symbols are retained when needed for the retail link, but names matching `^gap_`, names containing `_pad`, and symbols marked as gaps by configuration do not count as decompiled functions. Empty-body C functions count only with a source comment explaining that retail is a bare `blr` (for example, `// retail is a bare blr`).

`tools/decomp_report.py` applies this filter to the published report, so the **Exact natural C** figure on decomp.dev already excludes gaps, padding, and hand-written `asm` bodies. The **Diagnostic objdiff** category is the unfiltered whole-binary view.
