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

## Work in progress: keeping a plateaued body in the tree

A body that is semantically right but does not yet assemble to the retail bytes
can still live in `src/`, and still show up as progress, without touching the
retail hash. Mark its unit `Object(NonMatching, ...)` in `configure.py`:

- `main.dol` links the **original** object for that unit, so the retail SHA-1 is
  unaffected.
- The unit is still compiled and still diffed, so objdiff reports its real
  per-function percentage.
- **Exact natural C** does not count it, because it is not exact.
- **C-expressed** does, weighted by how close it is. This is the only thing that
  makes the two categories differ.

CI builds `ninja all_source build/GFZE01/main.dol` rather than the DOL alone,
because the DOL target does not build an object it will never link.

Worked example, `dolphin/ai/airegs.c` at the shape documented in its dossier
(a `volatile u16*` at the raw hardware address, which MWCC folds into a D-form
offset where retail materialises the address in two steps):

    AIStartDMA  83 %      diagnostic    93.7025 %
    AIStopDMA   83 %      natural-c     13.2957 %
                          c-expressed   13.3026 %   <- the 83 % showing up

    build/GFZE01/main.dol  421c88106697d3275a3fc26fb7a01bf6d816b271  (retail)

A plateau kept this way should carry a dossier next to it saying what was tried,
so the next person does not repeat the search.
