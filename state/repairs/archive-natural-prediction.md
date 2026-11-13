# fn_1_12F4A8: natural prediction and progress-ratio helpers

## Accepted partial cleanup

Baseline: `7ba38a82d` (`devices: simplify ADX mono identity and propagation paths`).

Replace the identity helper `compiler_diff_keep` and both of its calls in the
case 5-8 header with real arithmetic helpers:

- `predict_base` computes a scaled forward displacement and adds it to the
  machine position, using the existing `psvec_scale` and `psvec_add` primitives.
  It produces both the displacement and predicted position in caller storage.
- `progress_ratio` divides the progress record's position by its width. Its
  ordinary `position` local is used in that division, not returned unchanged.

Remove the now-unused outer `speed` declaration. Preserve the entry ABI, all
recovered structure members, both fzgx markers and the unit's stock GC/1.3.2
compiler settings (no extra flags). No assembly primitive was added or modified;
no new pragma, volatile access, widened integer, dead assignment or identity
helper was introduced.

The scale local, dead pedal compare, dead-assignment pragma and existing
propagation pragma remain. Their relevant warning comments are retained and
updated. This is NOT a fully device-free function.

## Measured source evidence

All word counts below are positional relocation-masked differences from
`tools/manualkit/fast.py`, not edit distance or rounded objdiff similarity.

- Ratio helper with a real loaded position local: 0 words off while retaining
  the speed identity call. This intermediate candidate was superseded.
- A helper that only scales the forward vector: 15 words off with ratio first;
  11 with scaling first. Inspection showed the remaining differences were
  floating-register assignments across scale/add primitives.
- A coherent prediction helper containing both vector operations, called before
  the ratio helper, preserves their inline depth and closes those differences:
  0 words off, 1465/1465 words.
- Moving the scale constant into the prediction helper while calculating the
  ratio first reaches 4 words off, but swaps the speed/denominator registers.
  It was NOT installed.
- Explicit removal-only subsets after the accepted cleanup: removing just the
  scale local gives 21 differing words; removing just the propagation pragma
  gives 27; removing the dead compare with its dead-assignment pragma gives 29.
  Removing all those mechanisms gives 36. No subset tested here was exact.
  The previously measured full-natural 29-word frontier is not superseded by
  that worse 36-word candidate.

Bounded helper-shape, calculation-order and actual arithmetic-local cohorts were
stopped after the exact partial closure and unsuccessful remaining-device
removal probes. Unused candidate helpers and weaker bodies were not installed.

Earlier priority checks in the same continuation:

- `fn_8006BCF8`: natural baseline and coherent table-pair helper remain 2 words
  off; sample-scaling/store helper forms were 5. No replacement installed.
- `fn_1_145C6C`: the natural baseline and byte-index reuse remain 9 words off;
  wider index reuse and alternate width computations did not close it.
- `fn_1_977BC`: fresh removal-only baseline remains 37 words off. Retain the
  previously archived stock allocator evidence; no weaker replacement installed.
- `fn_8004313C`: real byte-order helper probes were nonexact under the registered
  GC/1.3.2 flags (`-sdata 0 -sdata2 0 -use_lmw_stmw on`); none installed.
- Neither separately owned function, `fn_1_2CBAC` or `fn_1_10B800`, was edited.

## Literal/jump-table binding

Adding/removing helper declarations renumbers MWCC's private jump-table label.
The original `@559` becomes `@558` in the final accepted unit. Retarget that one
key in `config/GFZE01/units.json` to the SAME `jumptable_1_data_40CC8` object;
leave all established literal-pool mappings unchanged. The intermediate
ratio-only form used `@561`, which is not the final binding.

The first full build correctly rejected a stale private label. Read the freshly
compiled object's symbol table with the repository's `poolfix.Elf` and use
`oracle.refreshed_pool_map` after `configure.py` has regenerated the TU block.
An oracle check before regeneration can still describe the previous generated
source. Both missing-label build failures were resolved by refreshing only this
proven binding; no instruction or retail-target bytes were patched.

## Verification

Final installed block SHA-256, extracted between its fzgx markers:
`20fa46fbc658f7d60442d5c921ecf2b98ed998f49a8c4dc553cbf67dca17f56a`.

GC/1.3.2 compiler executable SHA-256:
`7cbae0a5bd81e07d7fa8975bbc4e969b5dea265cc29c5ee6bae0453a6e25f225`.

Final checks, after the final source and pool-map changes:

- `python3 configure.py --version GFZE01`: exit 0.
- `uv run ninja`: exit 0, `16 files OK`.
- `build/tools/dtk shasum -q -c config/GFZE01/build.sha1`: exit 0,
  independently prints `16 files OK`.
- `oracle.check(Project(), 'main_rel:fn_1_12F4A8', 30)` after regeneration:
  compiled, 100.0%, `matched=true`, zero differing rows, no pool-only verdict.
- `uv run tools/fzgx.py lint`: `0 finding(s)`.
- `git diff --check`: clean.

The linker continues to emit its existing unknown-section warnings; all target
hashes still pass. Primary `WARNING: compiler-diff device` markers across src
and include decrease from 32 to 31; two `WARNING: device` references remain.
This function retains three primary warning markers, down from four. No new
matched bytes or fully device-free function is claimed. The intentional local
`.claude/settings.json` change is excluded from this work.

## Reproduction

Regenerate and run the complete build/hash/lint gates above. For a scratch
function-only score, extract the block between `/* fzgx:begin fn_1_12F4A8 */`
and `/* fzgx:end fn_1_12F4A8 */` into a session-scratch directory, preserving the
self-contained block body. Then run:

    uv run python tools/manualkit/fast.py fn_1_12F4A8 SCRATCH_DIR GC/1.3.2 ''
    uv run tools/manual.py try fn_1_12F4A8 SCRATCH_DIR --mw GC/1.3.2 --flags='' -v

Do not create candidate or object directories in the source/provenance tree.
