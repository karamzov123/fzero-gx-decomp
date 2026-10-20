# Explicit empty compiler overrides must not inherit unit flags

## Root cause and repair

`oracle.check(..., source=body, extra_cflags='')` used truthiness to select
between candidate flags and the configured carved-unit override. An explicit
empty profile therefore silently inherited the configured flags. `[]` already
normalized to `''` in the single-check path and had the same problem.

`check_many` had the same truthiness fallback. It also used a caller's nonempty
argv list directly in its grouping key, raising `TypeError: unhashable type:
'list'` instead of compiling.

The repaired contract is:

- `None`: inherit the configured unit override.
- `''` or `[]`: use only the module's base flags, without the unit override.
- A nonempty string or argv list: apply that explicit candidate override.

Batch checks normalize argv lists with `shlex.join`, like single checks. Both
paths now select the configured flags only when the explicit argument is None.
No diff, relocation, pool, matching, submission or hash predicate was relaxed.

## Real-compiler reproduction

Function: `fn_8004EC34` (main).
Saved body: `.fzgx/attempts/fn_8004EC34.1791119346.c`.
Compiler: `GC/1.3.2`.
Configured unit override: `['-O1']`.

Measured results with the identical saved C and the actual compiler/objdiff:

| Path | Explicit argument | Effective override | Similarity |
| --- | --- | --- | --- |
| single | None | `-O1` | 63.270832% |
| single | `''` | `''` | 95.833336% |
| single | `[]` | `''` | 95.833336% |
| single | `'-O2'` | `-O2` | 67.854164% |
| batch | `''` | `''` | 95.833336% |
| batch | `['-O2']` | `-O2` | 67.854164% |

Before the repair, the explicit-empty single-check probe failed because the
compiler received `-O1`; batch explicit-empty probes did likewise, and the
nonempty list probe raised the grouping-key TypeError. Temporary probes are
kept outside the repository in accordance with repository rules.

This recovers reliable profile testing, not a new native-C match. The historical
95.83% source still has real instruction differences and has not been promoted.
The inherited source also contains a standalone volatile read requiring a
separate admissibility investigation.

## Other investigated residuals

- `fn_800720B0`: saved 96.95652% body reproduces 25/46 register-only differing
  words. Replacing raw FIFO addresses with existing `GX_FIFO_BASE` preserves the
  verdict and removes address literals from the work copy. Local scopes,
  flags/count lifetimes and natural FIFO helpers did not close it; saved only.
- `fn_8006BC50`: original two-word zero-copy/startup scheduling residual remains.
  A natural inline clear helper emits the missing `mr`, but has nine register
  differences. Its higher 95.77% similarity is not fewer differing words and is
  not acceptance evidence. The original work copy was restored.
- `fn_3_12D4`: natural scalar/color-aggregate reconstructions did not improve the
  seed. Existing volatile pool qualifiers were not added to accepted source.

## Verification

- `python3 configure.py` completed successfully. It reported existing missing
  source/configuration warnings for `fn_80036AC4` and `fn_10_266AC`; these were
  not changed as part of this fix.
- The existing repository suite passed: 24 tests. No test file was added to
  the repository; three temporary override probes also passed from scratch.
- `ninja -j 4` completed, including the complete build and progress generation.
- `build/tools/dtk shasum -c config/GFZE01/build.sha1` independently passed all
  16 image checks (main DOL and every listed REL).
- `git diff --check` passed.

Build-wide progress also changed during concurrent work; it is not credited to
this tooling repair. All investigation claims were released; other owners' claims and concurrent
source/configuration changes were preserved. No workers were spawned and no
push or merge was performed.
