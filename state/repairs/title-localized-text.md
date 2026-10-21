# Title localized text pointer table

## Recovered layout

Retail symbol: title:lbl_8_data_62D0, .data offset 0x62D0, size 0xA98
(2,712 bytes). Every four-byte slot has an ADDR32 relocation: 678 pointers,
all in the title module, with zero addends. Every target contains a NUL within
its retail extent and has no relocations in its string bytes.

The contents and consumers identify 113 rows of six language pointers:
English, German, French, Spanish, Italian and Japanese. The YES row is 39
(byte offset 0x3A8), and NO is row 40 (offset 0x3C0). fn_8_2124 and fn_8_23AC
index those rows with the same language selector; its value 5 selects the
Japanese rendering path. Original strings, including Shift-JIS bytes, are
not decoded/re-encoded or duplicated by this change.

Obj_8_data_62D0 now contains const char *text[113][6] rather than a leading
u32 and an opaque 0xA94-byte tail. Both consumers use the bounded typed
rows. The obsolete local single-element-array view in fn_8_23AC was removed,
and its stale scalar declaration of lbl_8_data_7C14 was reconciled with the
existing shared byte-array declaration.

## Proof and reproducibility

The data importer uses the canonical recovered record, not a generic fallback:
method declared-relocated-record, with no generated substitute header.
The actual Ninja object has a .data symbol of exactly 2,712 bytes and exactly
678 ADDR32 relocations; every target and addend matches retail provenance.
state/dataimports/GFZE01.json retains the definition and all bindings.

Regenerate this import with:

    uv run tools/fzgx.py data-import lbl_8_data_62D0 --regenerate --apply

Regenerate block sources before checking their consumers:

    python3 configure.py
    uv run tools/fzgx.py check fn_8_2124
    uv run tools/fzgx.py check fn_8_23AC

fn_8_2124 retains its existing pool-adjusted exact match (162 aligned
instruction rows, zero remaining differences); fn_8_23AC remains an exact
raw object match. All 16 executable hashes and fzgx lint pass.
These are preserved code matches, not newly authored executable functions.
The verified gain is the 2,712-byte initialized pointer table and its types.

## Canonical checks must not mutate Ninja objects

A real canonical check of fn_8_2124 exposed an independent oracle bug:
check() compiled directly into Ninja's link object. If pool retargeting was
only partial, it returned MATCH (pool) but left that object replaced with
raw compiler output. The problem was reproduced after a clean real pool-rule
rebuild: the link-object SHA-256 changed from
899281411e78d9cef92e42fd03efa59d6025783b17f13e3dd5e7a241d3f6a8c3 to
2274b9765acc6581185f92dd965911c8854fa04b4f3857e754bd115204edd57e.
The accepted object was restored through the normal mwcc_pool rule.

Canonical checks now pass an explicit scratch output to compile_unit, diff
that output and perform any retargeting / primer stripping there. No link
object is replaced, whether the source is a work copy or the canonical unit.
No matching, relocation or hash requirement was relaxed.

Verification used the actual canonical pool fn_8_2124 and ordinary matched
fn_8_23AC: both still match, both leave the Ninja object byte-for-byte
unchanged, and the following Ninja build / 16-target hash check passes.
The fn_8_2124 canonical object retains the original 899281... hash above.
No unit tests were added; these are real compiler and integration probes.

## Layout and compiler pitfalls

Use literal measured bounds in this recovered record: the lightweight layout
parser does not resolve its array-bound macros. A dry run with macro bounds
silently chose a generic 678-field pointer record. That fallback was replaced
with the canonical two-dimensional record before committing, and its unused
untracked generated header was removed. Check the recorded import method,
not just whether a byte-level import succeeded.

Adding enum members to this shared MWCC header changed anonymous literal
numbers used by existing saved pool maps. Two other pool units then failed
retargeting with missing @5/@14/@23 symbols. Source-level #define constants
retain meaningful selectors without introducing those enum symbols; the
baseline build and all hashes were restored before reapplying the import.
Do not weaken pool verification or edit bindings blindly to mask the failure.

A check of a block unit can compile a stale build/gen source until configure
regenerates it. The first consumer appeared to reference the removed pad_4
only because its generated source was stale. Always regenerate after editing
a parent TU, and reconcile all extern declarations introduced by new shared
includes before treating standalone check results as integration evidence.
