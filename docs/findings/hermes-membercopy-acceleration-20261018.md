# Evidence-driven acceleration: member-copy repair and refreshed SDK corpus

## Result

Against `573ade52`, this pass installed and hash-verified **40 new natural-C
functions / 25,692 text bytes**: 16 main-DOL functions and 24 movie_module
functions. Authored functions increased **5,850 -> 5,890**; authored code bytes
increased **1,214,312 -> 1,240,004**, or **41.5222% -> 42.4007%** of known code.
These are natural-C gains, not inline-assembly, fuzzy, or data-only credit.

The native loop landed in `f0bd667d`; donor batches landed in `8d2d00ea` and
`bfc8fcdb`. All 16 target SHA-1 checks passed, and lint reported zero findings.
The remaining code is still large; main_rel's 748 unauthored functions did not
shrink in this pass. Do not extrapolate this library harvest into a general game
logic decompiler.

Portable evidence:
`state/repairs/hermes-membercopy-acceleration-20261018.json.gz` contains the
40-function inventory, source/setting-pinned initial seeds, partial bodies,
real-compiler controls, coverage, baseline errors, donor discovery/import
reports and the final integrated-command replay. The exact imported donor
revision, original/generated source hashes, bindings, compiler and license
remain in `state/sdkimports/sourcealign.json`. Existing provenance entries were
compared against the baseline and are unchanged.

## What was built

### 1. Native member-copy state repair

Findings 371 and 376 established that MWCC can rematerialize a scalar copy of
zero as `li`, while promoting a real local struct's member copy as `mr`. The
second member must use `int` rather than signed `long` in the measured profile.
The repair engine had a single-member carrier family, but not this paired rule.

`fixup_source.member_copy_states` now groups an existing assignment between two
eligible 32-bit locals into real aggregate state. It preserves statement order,
member signedness and values; it does not invent work, add padding, or force
registers. Escaped, shadowed, qualified and initialized locals are excluded.
Comments, string literals and unrelated object-member accesses are not rewritten.

Real compiler controls:

- `fn_12_2F7AC`: saved scalar body 99.016396%, one residual -> generated body 100%.
- `fn_12_2F970`: scalarized current body 98%, one residual -> generated body 100%.

The initial scan inspected **79,644 distinct saved bodies**, selected 210
functions, and compiled 206 baselines. Two rounds tested **323 + 295 candidates**.
There were 19 final percentage improvements, but **zero exact matches from the
new family alone**. Only seven bodies exceeded the then-current ledger best;
these were saved through claim/release with `save_only=True`, not submitted as
matches. Their statuses remain unmatched; two null-score histories intentionally
remain null in the ledger but have their body/settings in the portable archive.

The most useful lead was `fn_12_2F730`: 98.03226% -> 99.96774%. Its sole residual
was a callback load at +0xC instead of +0x4. The saved draft carried an obsolete
8-byte `lab_pad` ahead of its real two-word callback record. Removing that padding
produced a 100% object match, which then passed the full link/hash gate. The final
native body has no artificial padding.

### 2. Reusable historical-body selection and compiler-correct sweeps

Use the existing CLI; no separate decompiler or runner was added:

```sh
.venv/bin/python tools/fzgx.py sweep --recover-membercopy --min-percent 0 \
  --rounds 2 --output .fzgx/work/membercopy-run
```

This selects the best *eligible historical body*, rather than only considering
the best ledger body. It freezes source hashes, compiler versions and extra flags
in `seeds.json`, writes coverage and errors, and runs the new `membercopy` family.
To replay a selection without rescanning history:

```sh
.venv/bin/python tools/fzgx.py sweep --seeds .fzgx/work/membercopy-run/seeds.json \
  --min-percent 0 --families membercopy --rounds 2 \
  --output .fzgx/work/membercopy-replay
```

Use `--land` only when integration is wanted; submit still rechecks exact
candidates, and `fzgx verify` remains the final acceptance gate. Saved improvements
use `save_only=True` so this bounded sweep does not accidentally invoke a full
repair search on release. The selected compiler and flags are retained for
baseline checks, variant/base compilation, winner checks, saved attempts and
submission. Historical argument-list flags are converted reversibly using
`shlex.join`; their original list is retained in the selection manifest.

After the 40 lands, the integrated command was exercised end to end again:
80,198 historical body/settings contexts inspected, 196 eligible functions,
192 compiling baselines, **287 + 265 candidates**, zero further exact matches.
Four invalid legacy baselines are named with actual compiler diagnostics in
`errors.json`; they are not silently treated as checked functions. Different
initial/final coverage reflects the removed matched functions and context-aware
deduplication, not additional new functions.

### 3. Preserve historical import provenance

`sourcealign.submit_saved` previously refreshed every historical manifest entry's
license/repository from the current donor checkout. An unrelated unsupported
legacy donor could therefore raise after a new batch had already been submitted.
It now updates repository information only for newly accepted imports. Their
license check and archived license copy still occur before submission; historical
revision/license records are not reinterpreted from today's checkout.

## The larger gain: compile and replay licensed donor sources

The MK Deception checkout was already at
`33b1e0082c7630ee4f20b828559966872ae670e1` (Batch5). Existing objects/reports were
not enough evidence that the current source corpus had been exhausted. Rebuilt
its Dolphin, ADX, Sofdec and runtime corpus through the existing sourcealign
engine, across twelve compiler/flag profiles:

```sh
.venv/bin/python tools/fzgx.py sourcealign --compile-sdk mk-deception \
  --root src/dolphin --root src/libadxgca --root src/libmwsfdg --root src/runtime
.venv/bin/python tools/fzgx.py sourcealign --discover --min-size 16 \
  --root src/dolphin --root src/libadxgca --root src/libmwsfdg --root src/runtime
```

The initial refreshed catalog contained 9,258 donor functions and found 167
unfinished relatives. Every one was attempted, in three bounded groups:

| Group | Functions attempted | Object-exact candidates | New hash-verified functions |
|---|---:|---:|---:|
| Exact opcode shape, <=256 bytes | 27 | 9 | 9 |
| Exact opcode shape, >256 bytes | 57 | 31 | 30 |
| Non-identical opcode relatives | 83 | 0 | 0 |

One object-exact `DBWrite` candidate was rejected by the repository's hardcoded-
address lint rule (line 12, 0xC0000000). No exception or address bypass was added;
it is not counted as a land. Existing `sourcealign` extracts native C and infers
symbol/relocation bindings; object matches alone were not the acceptance gate.

A second pass isolated native functions from **all 48 whole-file failures**.
This yielded 3,516 function-mode objects, expanding the catalog to 15,295 donor
functions. Only `float2str` and `double2hex` gained new/expanded retained candidate
sets; both were attempted and neither closed. Repeating the unchanged donor
sweep now has negative evidence.

Representative accepted imports include `sfply_StatPlay`, `SFD_CloseStmSj`,
`MCV_HpelPcol`, `MPV_SearchFrmTag`, `ADXT_ExecErrChk`, `ADXD_DecodeInfoAdx`,
`__GXAbort`, four ADX stereo decode forms and four ADX stereo encode forms.

## Online and prior-work check

- MK Deception: https://github.com/ShulkMaster/mk-deception/commit/33b1e0082c7630ee4f20b828559966872ae670e1
  was checked against the documented prior Sofdec donor revision
  `7f36c3c64be9e2c40ea7301fe6c150d585b1a97d`. Its CC0 donor sources remain the
  productive compatible library evidence; no license-unknown source was added.
- m2c: https://github.com/matt-kempster/m2c/commit/708d2d2cb269
  has recent PowerPC comparison-pattern work. The project already uses m2c;
  these changes are not evidence of automatic matching C for the remaining game.
- objdiff: https://github.com/encounter/objdiff/commit/eed74b99c4e9
  is 3.8.2. decomp-toolkit: https://github.com/encounter/decomp-toolkit/commit/0645e1651181.
  They remain useful object/layout/progress tools, not substitutes for native
  type/ABI/control-flow evidence.
- Upstream https://github.com/rayanht/fzgx/pull/22 was checked against the local
  ledger. Most of its advertised matches are already incorporated, not an unused
  76-function harvest. The branch had no other open fork PR to duplicate.
- The earlier broad near-match sweep had already tested 40,208 candidates without
  closure. This pass targeted an evidenced new idiom and refreshed compiled donor
  input instead of repeating it unchanged or adding more workers.

## Verification and limits

- `python configure.py && ninja build/GFZE01/ok`: exit 0.
- `sha1sum -c config/GFZE01/build.sha1`: all 16 outputs OK.
- `fzgx lint`: 0 findings.
- `python -m unittest discover -s tests -v`: 24 tests pass, including nine new
  transformation/context/provenance/recovery regressions.
- Compiler/donor similarity was not credited as completion;
  all 40 accepted bodies are native C and their linked outputs match retail.
- Existing configure warnings for missing `fn_80036AC4.c` and the `sel` unit
  configuration remain outside this change; the full acceptance target succeeds.
- No subagents, fleets, other profiles, model transports or provider settings
  were changed. All work was inline under this repository's no-swarm policy.

## Highest-value continuation

1. Refresh *licensed, compiled* adjacent library corpora before repeating source
   searches. Count newly accepted bytes after verify, not donor similarity hits.
2. Apply new MWCC idioms to the entire saved corpus, with frozen compiler contexts;
   the top ledger body may no longer contain the source shape the rule needs.
3. For main_rel/game logic, concentrate on shared object layout/call ABI and
   same-module matched witnesses; this pass did not uncover a library-sized
   shortcut for those 748 functions.
4. Treat DBWrite's address expression, the four broken saved baselines, and the
   failed printf relatives as named evidence frontiers, not reasons to relax lint
   or replay the identical sweeps indefinitely.
