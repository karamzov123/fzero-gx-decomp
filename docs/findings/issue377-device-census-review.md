# Review of jedgentry's device census (issue #377)

Reviewed 2026-11-16. [Issue #377](https://github.com/karamzov123/fzero-gx-decomp/issues/377)
by jedgentry correctly raises a substantial gap between binary/C-authored progress
and verified device-free reconstruction. Warning-marker counts are not a function
census and miss unmarked optimizer steering, helpers, volatile views and other debt.
The attached census is a valuable investigation queue, but its exact 616-device
claim and 78.11% natural-C estimate are not independently established current totals.

## Inputs and scope

- Attachment: [device_census_0efb2ebad.json](https://github.com/user-attachments/files/34862077/device_census_0efb2ebad.json).
- Attachment SHA-256: `4f4ff62dadd1d017b1823775da6519e6e2107ed9d6e3baaf2d88938106f7d2ef`.
- Claimed scan revision: `0efb2ebad7e1f40c6f9a4be19fbb27560267577c`.
- Current source comparison: `43f969c4d8766e0a40134d4caab500cded51738d`.

An isolated checkout of the claimed revision was built with the local legal retail
inputs and real MWCC. All sixteen executable hashes passed. Fresh objdiff and the
module-qualified project inventory agreed on 7,351 functions and 2,937,044 code
bytes. Current source was inspected separately; historical census results were not
silently treated as a fresh scan of current main. No source variants were installed,
no unit tests were added, and the GitHub issue was not edited or closed.

## What reproduced

Recounting all 745 attachment entries exactly reproduces its own summary:

| Attachment classification | Entries | Reported bytes |
|---|---:|---:|
| MARKED | 12 | 21,856 |
| DEVICE (unmarked pragma candidates) | 604 | 615,840 |
| UNCLEAR | 44 | 15,204 |
| SETTING | 85 | 52,612 |
| MARKED + DEVICE | 616 | 637,696 |

The 78.1106% figure follows arithmetically from excluding the last row's bytes
from the attachment's stated 2,913,268-byte denominator. Including UNCLEAR yields
77.5887%. Those are scenarios under the attachment's identities, denominator and
classifications, not measured device-free source coverage.

All twelve MARKED entries have a primary warning in their selected compiled source
at the cited revision. Representative unmarked pragmas also demonstrably affect
code generation, so this is not merely a naming or comment-count concern.

## Identity and denominator corrections needed

The attachment says 7,310 functions / 2,913,268 bytes. The fresh historical report
instead has 7,351 / 2,937,044, with all sixteen hashes matching. This discrepancy
exists at the cited commit; later source progress does not explain it.

The attachment's function dictionary is keyed by bare names, which cannot preserve
all REL entrypoints. There are fifteen `_prolog` and thirteen `_epilog` symbols in
separate modules. One concrete mixed-identity row is `_prolog`: the attachment gives
`src/rel/customize/_prolog.c` but a size of 664, which belongs to car_colchg's
`_prolog`; customize's is 1,048 bytes.

As a diagnostic, deduplicating only `.text` by bare name produces exactly 7,310
keys. Letting car_colchg's `_prolog` and `_epilog` win those collisions produces
exactly 2,913,268 bytes. This reproduces the published denominator, but is not proof
of the unpublished script's implementation. It is not the full module-qualified
code inventory, and `.init` is also omitted. Use module plus section/address or a
module-qualified symbol as the identity before deriving a mission percentage.

Four DEVICE entries have none of their reported pragmas in the actual generated
or direct source selected by the build at the claimed revision:

- `customize:_prolog`;
- `car_colchg:_epilog`;
- `title:fn_8_B138`;
- `main_rel:fn_1_103B00`.

This is a compiled-source attribution inconsistency, not proof those functions are
otherwise device-free. For block-based TUs, inspect the generated per-function
compiler input and its selected profile, not merely pragmas elsewhere in a source
container. Another UNCLEAR entry, `__init_data`, has a null size in the attachment;
zero bytes in the summary is not a measured function extent.

## Compiler sensitivity is not original-source provenance

Of the 604 DEVICE entries, 491 cite same-TU evidence and 113 cite neighbouring
units. The attachment provides verdict labels, not the experiment script, raw
object diffs or complete compiler transcripts. The full classification experiment
was not independently rerun for all 604 entries.

Moving an option globally and changing a sibling proves code-generation sensitivity,
not that the original source could not have used that scoped setting, nor that two
neighbouring split objects came from the same original TU or library profile. No
change also does not prove that a pragma was original. Check the actual TU boundary,
compiler settings, source abstraction and known original-library evidence.

A concrete ambiguity is `main:__OSSetExceptionHandler`, labelled DEVICE using
neighbours. Its original historical baseline was reproduced, and removing
`peephole off` changes its compiled body. But current native mixed OS.c holds the
same setting at file scope and preserves that handler's instruction stream.
Moving the existing setting to the top of that real TU changes zero instruction
words across all fourteen functions. The neighbour verdict therefore cannot, on
its own, establish an artificial per-function device. This is not a blanket finding
that all OS pragmas are original; the original profile still needs evidence.

## Independent MWCC probes

Each historical baseline reproduced the installed function's relocation-masked
instruction bytes before variants were measured. These are positional instruction
word differences, not objdiff percentages or aligned edit-distance scores.

| Function / removed pragma | Original bytes | Variant bytes | Differing masked instruction-word positions |
|---|---:|---:|---:|
| `main_rel:fn_1_10E3B4` / `opt_common_subs off` | 7,252 | 7,260 | 1,477 |
| `main_rel:fn_1_10E3B4` / `opt_propagation off` | 7,252 | 7,252 | 162 |
| `customize:fn_3_15A0` / `opt_common_subs off` | 7,680 | 7,588 | 1,653 |
| `customize:fn_3_15A0` / `opt_pointer_contraction off` | 7,680 | 7,680 | 0 |
| `main:__OSSetExceptionHandler` / `peephole off` | 28 | 24 | 7 |

These confirm real sensitivity and one redundant directive. They do not prove
original intent, validate all attachment verdicts, or constitute accepted cleanup.
Removing a pragma that changes bytes requires a faithful source repair, not a
weakened match gate. No variant replaced the verified reconstruction.

## Current-main interpretation and next work

The historical list is still useful: all 745 names can be resolved after using the
reported file to recover a module, although that does not repair lost collisions
or erroneous sizes. At current main, ten DEVICE entries no longer have any listed
pragma in their selected compiler input, compared with four at the cited revision.
The six additional cases are `movie:fn_5_169C`, `profile:fn_16_61D4`,
`main_rel:fn_1_56B8`, `movie:fn_5_4C8`, `movie:fn_5_2C54`, and `movie:fn_5_37C`.
This is a pragma-presence screen, not six certified device-free functions: helpers,
flags or other devices may remain. A pragma elsewhere in a whole native unit does
not prove it affects every function in that unit.

Priorities:

1. Preserve the expanded census as a candidate queue, crediting jedgentry's work.
   Do not dismiss unmarked steering because lint and hashes pass.
2. Repair module identity, full code denominator and generated-source attribution,
   then archive exact profiles, baseline/variant objects and comparison results.
3. Audit suspected pragmas individually with original-TU/library evidence, alongside
   unmarked helpers/volatile/dead-code devices and shared-header callers.
4. Remove genuine devices using natural source changes and require object,
   relocation, lint and all sixteen executable hashes before accepting a repair.
5. Keep C-authored, binary matching and audited device-free completion separate.
   False positives and unscanned debt are both possible: the 78.11% scenario is
   neither a certified current percentage nor a rigorous upper/lower bound.

Summary and probe results are retained in
[state/repairs/issue377-census-review.json](../../state/repairs/issue377-census-review.json).
The README keeps natural-C/device-free completion explicitly unaudited rather than
replacing the 98.7909% C-authored metric with an unverified 78.11% headline.
