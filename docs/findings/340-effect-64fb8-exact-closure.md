# fn_1_64FB8: exact effect/camera update closure

`fn_1_64FB8` now matches **100.0%**, with **zero differing instruction rows**, and passes the linked checksum gate. The function is 688 bytes / 172 instructions. Source and integration are in commit `36f65841d163bb23f1927aefd53631537d9a4c26`.

The older partial source under `docs/partial-candidates/20261013/fn_1_64FB8.c` and finding 339 are historical experiment snapshots, not the current canonical implementation. The canonical block is `src/rel/main_rel/effect.c#fn_1_64FB8`, with its standalone build unit and pool mapping recorded in `config/GFZE01/units.json`.

## What closed the residual

1. Keep the native signed-halfword compound damping expressions. They already match the conversion and coefficient/bias register block.
2. Use `#pragma opt_propagation off` for the function, restoring it afterward. This retains the translation scalar webs instead of propagating the matrix stores directly to loads.
3. Declare the translation scalars separately (`f32 z, y, x`) and assign them in X/Y/Z order before writing the matrix column. Initializing them directly in reversed declaration order produces the correct registers but the wrong load order under this pragma.
4. Declare the second locked-cache pointer only after the transform call, inside the translation block. Otherwise its address is kept across the call in a saved GPR, changing the instructions.
5. Express the final growth directly at its output store:

       output_x = (255.0f * (0.5f * (1.0f + gain))) / 255.0f;
       {
           f32 spread = (136.0f * gain) / 255.0f;
           output_y = spread;
           output_z = spread;
       }

   This is the same arithmetic/rounding as the previous intermediate form, but avoids introducing a named growth web which swaps the registers holding 1.0 and 255.0. Moving the named spread before named growth is not equivalent codegen and regresses the tail.
6. Retain the measured native shared-pool primer and submit-time pool retargeting. No inline assembly, dummy padding, forced physical register bindings, or allocator-only translation helper is needed.

## Extended experiments

The user explicitly waived the plateau cutoff for this target. The installed API supports process-local `FZGX_MAX_CHECKS` and `FZGX_MAX_STALE`; both were raised to 256 for the extended run. No fleet-wide setting, ledger budget, or source admission rule was weakened.

The attempt recorded 49 compiler/object checks. A controlled 36-body family permuted the three independent scalar loads and three independent hardware stores, preserving each component's destination. None matched by itself. The closest unmodified optimizer shape had only four remaining rows: the X and Z hardware stores appeared in reverse order in each translation block. This isolated the conflict between propagation/liveness and store ordering and motivated retaining the scalar webs while rewriting the arithmetic tail naturally.

Other measured paths included a pointer-based translation helper, typed matrix columns, absolute hardware object declaration, register/double scalar declarations, an unrolled copy loop, regional propagation pragmas, and combined propagation/CSE suppression. These did not close the full function. The native compound expressions and exact stack/local layouts were retained throughout. Existing matched `live_camera.c` code supplied the propagation-off translation shape, but copying that flag alone was insufficient.

## Verification and commit scope

- Object oracle: 100.0%, no differing rows; accepted literals retargeted to the retail shared pool.
- `fzgx submit`: accepted the function with link pending.
- `fzgx verify`: accepted the function, no rejections; full relink/checksum gate passed.
- `ninja`: succeeded and updated the report to include the function.
- `dtk shasum -q -c config/GFZE01/build.sha1`: all 16 files OK.
- Repository tests (`pytest -q tests` in an ephemeral uv environment): 11 passed.

The verifier initially staged four pre-existing unrelated main-REL split entries together with the new split. Before any push, the unpublished commit was narrowed at the index to only this function's three-line split entry, without changing the working file. The canonical source and unit-manifest blobs were verified identical to the checksum-tested commit, and the ledger's verified commit reference was updated through its existing `finish` method. The unrelated split edits remain local and unstaged.
