# fn_3_0: independent indexed inline-helper lifetimes

Target: customize:fn_3_0, 1068 bytes. Accepted C commit: 55ae3eba.

The saved reconstruction used one inline helper three times. Its explicit
`volatile s16 *pIndex` retained r29 in every expansion. Retail uses r29 in
the first expansion, r27 in the second, and r26 in the third: eight
instruction rows differed in the latter two expansions.

Measured source hypotheses, in order:

1. Expand all helper bodies directly into separate caller scopes: 89 register
   rows differ (267 aligned instruction rows). Rejected.
2. Keep three independent static-inline helper definitions with the saved
   explicit pointer: eight register rows differ. Not exact.
3. In only helper_b and helper_c, remove pIndex and spell its dereferences as
   bss20->indices[i]. Keep the first helper unchanged. Oracle: 100.0%, empty
   instruction diff. Justification comments for the inherited volatile reloads
   leave the exact result unchanged; candidate lint is empty.

The indexed spelling allows the second and third copies' index addresses to
use the retail lifetime/register reuse instead of a named pointer web. This
is a source-shape repair, not another declaration permutation or compiler
search. The failed direct expansion shows that replacing inline helpers with
caller-local scopes is not allocation-neutral.

Validation:

- fzgx submit: accepted; pending linked verification.
- fzgx verify: fn_3_0 verified, no rejected functions, commit 55ae3eba.
- fzgx lint: 0 finding(s).
- build/tools/dtk shasum -q -c config/GFZE01/build.sha1: 16 files OK.
- Ledger readback: matched, link_state verified, no active claim.
- Honest customize authored count: 176 -> 177; remaining functions: 102 -> 101.
- Whole-project remaining authored functions: 1482 -> 1481.

No fleet, provider configuration, or startup policy was changed. Work is local
on branch hermes/customize-fn-3-0; no push was performed.
