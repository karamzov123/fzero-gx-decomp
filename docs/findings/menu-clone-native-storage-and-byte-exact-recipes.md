# Menu clones: native storage bindings and byte-exact repair recipes

## Verified closure

Local commit `897a9300` reconstructs two exact retail-code clones of the already
accepted `fn_10_2406C` menu handler:

- `fn_4_BC04`, option, 2916 executable bytes;
- `fn_8_E440`, title, 2916 executable bytes.

Total: 5832 newly authored executable bytes. Both submissions passed the object
oracle and the all-16-target linked hash gate. No near-match improvement is
included in this total.

The source donor's own initialized array and typed BSS pointer have corresponding
objects in the destination modules. Ordinary external-reference bindings alone
miss those references because the donor owns its storage. The native-storage
path proves the donor object's pool relocation against retail through
`poolfix.map_pool_bindings`, then transfers it through the existing module-aware
exact-clone relocation pairs. Module, section, offset and object range must all
agree. Conflicting bindings are rejected. Flattening includes measured header
types and declarations; it does not erase the source's compiler options.

The existing clone-storage work in `tools/fzgx/reuse.py` and its integration in
`tools/fzgx/fixup.py` are dependencies of these matches, not optional unrelated
tooling. No new standalone search runner was introduced.

## Reproduction

The committed portable archive contains only these two successful repairs,
including the donor C, exact source edits, native-storage bindings, compiler
settings, generated C, and scoring evidence:

    uv run tools/fzgx.py fixup --archive state/repairs/menu_clone_sources_20261021.json.gz

Expected result: `{"reproduced": 2}`. Replay rechecks each generated object against
its current module-specific retail target. `state/repairs/fixup_imports.json`
records the archive path and the verified integration commit for both functions.

The discovery command was:

    uv run tools/fzgx.py fixup --clones --rounds 1 --limit 20 --max-candidates 24 --budget 150 --output .fzgx/fixup/hermes-kb-clones-20261021

It screened five families / eleven unresolved functions, compiled 628 source
variants, and closed these two functions. Follow-up exact-clone reuse had no
additional usable donors. No unchecked family-wide credit was taken.

## Reproducibility defect caught by replay

The first archive failed with `fn_4_BC04: recipe output hash mismatch` even though
the generated functions passed the real link gate. The preprocessor's expanded
C contained CRLF bytes. `Engine.record` correctly hashed and wrote those bytes,
but later `Path.read_text()` calls silently normalized them to LF while building
recipes and archives. Hashes therefore described different bytes than the saved
source edit payloads. Two additional frontier entries had the same defect.

Use `source_text`, a byte-preserving UTF-8 reader, throughout content-addressed
source consumers: expansion, proposals, clone transfer, corpus loading,
integration, recipes and archives. Keep JSON readers unchanged. The source
flattening entry point also preserves its input bytes. This fixes the class
rather than special-casing the two successful functions or weakening hash
validation. The regenerated full discovery archive replayed all 35 entries;
the smaller committed archive replayed both successful entries independently.

## Other measured checks and stopping decisions

- Fresh fork harvesting found no further admissible closures. Harvesting a ref
  with zero candidates reproduced a missing-directory exception; the output
  directory is now created even when no screening worker runs. Both formerly
  failing refs subsequently returned valid empty result files.
- CARD, OS, EXI and SI SDK importer inventories had no remaining candidates.
- Six saved source-alignment candidates rechecked with zero matches.
- A bounded 40-function repair cohort evaluated 13898 source variants in two
  rounds with zero closures. Stop that cohort rather than repeat unchanged
  score-only searches.
- Natural vector cross-product/length helpers replaced identity-helper probes
  for `fn_1_290E8`, but remained nonmatching. A correct void return for
  `fn_12_3A64` still has a real allocation residual. Neither was submitted.
- The small-function trivial screen had zero candidates.

Final checks: `python3 configure.py && ninja`, `fzgx lint` (zero findings), fresh
`fzgx snapshot`, portable archive replay, and explicit
`build/tools/dtk shasum -c config/GFZE01/build.sha1` (all sixteen targets OK).
Existing missing-source/configuration warnings for `fn_80036AC4` and
`fn_10_266AC` remain; neither function is part of this closure.

No fleet/provider changes, subagents, or pushes were used. Unrelated storage
service and compiler-GC work was left in the working tree. Only the two matched
function rows and their new matched attempt records are staged from the live
ledger snapshot; unrelated snapshot changes remain uncommitted.
