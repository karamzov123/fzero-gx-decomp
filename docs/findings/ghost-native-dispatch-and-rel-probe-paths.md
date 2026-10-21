# Ghost native dispatch closure and REL layout probe paths

## Verified executable gain

`fn_1_E9BA8`: 192 bytes, integrated and link-verified in `09e41e53`.

The saved source used an oversized `s32 *` view anchored at
`lbl_1_data_3E358`. The actual residual consisted of two reversed stores and
two instructions addressing the handler table through the wrong expression
shape. This was not a register-allocation-only obstruction.

The successful source:

- stores the pending index into the current index before resetting pending;
- models the 17-entry handler table at offset 0x98 as a native initialized
  function-pointer array, rather than casting into a larger integer array;
- retains initialized data objects in retail order, with every byte and
  relocation taken from `dataimport.pool_objects` / `dataimport.payload`;
- retains current at +0x1D4 and the full measured eight-byte pending storage
  at +0x1D8. Only the first pending word is accessed by this function;
- removes the unused aggregate view and uses a function-pointer typedef for
  the native dispatch table.

Anonymous DTK gap objects here contain real pointers, including the filename
and handler tables. They were not replaced with assumed zero padding.
`fixup_layout.initialized_data_views` generated the measured native objects;
source cleanup and the normal deterministic submit path preserved the match.
The unit's pool map binds `...data.0` to `lbl_1_data_3E358`.

Independent checks after integration: `16 files OK`; lint `0 finding(s)`.
The committed source is in the `fn_1_E9BA8` block of
`src/rel/main_rel/phys.c`; provenance is in `state/repairs/fixup_imports.json`.

## Cohort follow-through

Eight unresolved functions originally referenced this data base, totaling
15,636 bytes. The closure above is included in that total. The other saved
sources were inspected; no additional closure is claimed. A native string
layout for `fn_1_F0168` retained its scheduling/operand residual, rather than
sharing the dispatch-table obstruction. Word-buffer/address alternatives for
`fn_80053DB4` also failed to close its remaining operand-order difference.

## Real compiler failure fixed

`fixup_layout.probe_layout` interpolated the function key directly into its
source basename. REL entrypoints use keys such as `customize:_prolog`.
MWCC under wibo applies Windows filename rules and rejected that colon with:

    Unexpected error in CWAddProjectEntry [3]
    Errors caused tool to abort.

Before the fix, the exact same real `Obj_Bss_0` layout probe succeeded with
an underscore-only tag but failed with the module-qualified tag. The successful
probe measured `unk_10` at offset 16 and `unk_F0` at offset 240, each with
size/element-size/alignment 4.

The fix normalizes `:` to `__`, matching `Project.work_path`, without dropping
the module name. The formerly failing qualified probe now returns those same
measured offsets. This repairs all callers of the shared probe helper without
changing source, compiler options, layout rules, or oracle acceptance.

A bounded follow-through over the remaining saved REL entrypoints refreshed
102 seeds for four functions and evaluated 2,975 variants. It produced no
new exact matches; the batch was stopped rather than repeated.

## Customize initializer frontier, not a match

The repaired probe also allowed native BSS reconstruction for
`customize:_prolog` (1,048 retail bytes). The first valid rejection identified
an actual type-width error in the old source: the object at BSS+0x20844 is two
bytes, not four. The updated source preserves the canonical header declarations,
uses the measured width, and consolidates overlapping views before native
object generation. The native BSS definitions are derived from individual
module symbols, not an invented monolithic zero allocation.

Portable source/compiler archive:

    state/repairs/manual-customize-native-bss-20261021.json.gz

Replay:

    uv run tools/fzgx.py fixup --archive state/repairs/manual-customize-native-bss-20261021.json.gz

Real result: `{"reproduced": 1}`. The retained candidate is GC/1.3.2,
95.09542% raw similarity, 68 differing words and nine shape errors. Remaining
problems include section-base allocation and ordering; this source is not
accepted and contributes zero executable bytes to the result.

## Scope

The verified function contributes 192 new bytes. Other frontiers and the probe
fix are reported separately. No unit tests were added, no pre-existing tooling
edits were committed, no worker ownership was taken over, and nothing was
pushed. The manual customize claim was released after preserving the frontier.
