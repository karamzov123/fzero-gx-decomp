# Shared data imports

`uv run tools/fzgx.py data-import --inventory --module profile` lists unowned
objects, existing declarations and function references. Import explicit symbols
with `data-import SYMBOL ... --apply`. Without `--apply`, the same generator and
MWCC object checks run in `.fzgx/dataimport/` without transferring ownership.

Definitions live in `src/<module>/data/`; recovered aggregate types live in
`include/<module>/data/`. Contiguous symbols compile together. Existing generated
units can grow to include adjacent members without waiting for any function.
`state/dataimports/GFZE01.json` records declarations, references, retail payload
hashes, symbolic relocations, source ownership and any measured layout recipe.

Reproduce every saved definition and verify the result:

```sh
uv run tools/fzgx.py data-import --regenerate \
  --recipes state/dataimports/recipes.json --apply
```

The importer checks each compiled symbol's size and offset, section size and
alignment, exact initialized bytes, and every relocation's module, section,
target address and addend. BSS must be NOBITS. Extra allocated sections are
rejected. Applying runs configure, Ninja, and the explicit 16-target hash check,
then checks the actual Ninja objects too. Failed integration restores the files
it changed and rebuilds the previous tree. Commit the tooling, source, headers,
splits, units and provenance together; never push.

## Group retries (2026-11-04)

Contiguous unowned objects are grouped into one compile, so one bad member used
to reject its whole run. A failing group is now retried as independent chunks,
each beginning at an 8-byte-aligned member (MWCC's minimum section alignment):
runs that crossed two TUs' headers with conflicting typedefs, or that started off
alignment because their predecessor belongs to a function unit, import in pieces.
Every chunk is still compiled, validated and hash-checked on its own; `--regenerate`
keeps the recorded groups and never splits. A BSS chunk that still fails because a
header type does not reproduce the retail extent is retried with that member as an
opaque `u8[size]` (method `opaque-bss-header-mismatch`). Measured on the whole tree:
screened importable data 481 KB -> 1.2 MB (the second figure includes regrouped
existing units).

## Layout rules recovered from real imports

- Existing BSS header declarations retain their structs and pointer fields.
  Unrecovered BSS uses an explicitly opaque byte array of the retail extent.
- Finite floats use decimal constants checked against their exact retail bits.
  Float-tagged pools with non-finite words use a union of raw bits and float
  values; the annotation alone does not establish that every word is a float.
- Strings retain terminators and interior padding. Fixed-width octal escapes
  preserve Shift-JIS bytes without depending on source-file encoding.
- Relocated table fields use function pointers and byte pointers with symbolic
  offsets. Code-interior pointers and jump tables are excluded from independent
  data import. Unsupported layouts are reported, not dumped as arbitrary assets.
- MWCC initialized sections have a minimum 8-byte alignment. Group contiguous
  members to preserve symbols at 4-byte offsets. Owned trailing zero padding
  extends splits to DTK's word boundary; the linker supplies those padding bytes.
  A separate C padding array would introduce another alignment gap.
- DTK can omit an isolated zero-only auto range, including its named symbol.
  Include adjacent zero objects and all members of an affected generated unit.
  `#pragma explicit_zero_data on` keeps initialized scalar zeros out of BSS.
- REL offsets overlap across sections. Padding and relocation checks must use
  the named section, not the first raw section containing that numeric offset.

## Profile text layout

`lbl_16_data_0` is 535,296 bytes, entirely fixed-capacity text:

| Offset | Layout | Bytes |
| --- | --- | ---: |
| `0x00000` | 41 pilots × 6 language slots × 2,048-byte biographies | 503,808 |
| `0x7B000` | 41 machines × 2 text fields × 6 language slots × 64 bytes | 31,488 |

The two machine fields contain engine and maker strings. Language slot 0 is
English, slot 5 contains Shift-JIS text, and slots 1–4 are empty in GFZE01.
Every cell has a terminator followed entirely by zero padding. The generator
checks all 738 cells rather than inferring padding from a sample.

`profile:_prolog` builds biography addresses at `0x3000` strides.
`fn_16_1038` uses a `0x3000` pilot stride and `0x800` language stride for
`lbl_16_bss_B0B8`, the corresponding 503,808-byte working buffer. The recovered
headers expose both layouts; recipes retain the evidence used to select them.

## Interview camera tracks (2026-11-04)

`include/rel/interview/camera_track.h` declares 656 tracks (`InterviewCameraMove[]`,
403 KB with the adjacent text) recovered from `fn_17_7A74` and `fn_17_7728`:
`lbl_17_data_63190` holds 41 sets of 16 track pointers. Each 0x54-byte move holds a
frame count, a blend rate, two 0x24-byte camera keys (flags, eye, target, fov, roll) and a mode
(0 linear, 3 ease, 2 blend). All 4,623 retail moves have zero padding, zero flags, finite floats
and one of those three modes. A recovered header outside `data/` is how unreferenced
objects get a type: `declarations()` picks up its externs and `declared_record_initializer`
emits the typed initializer. Two fixes came with it. `is_text_pool` accepts U+3000
(the ideographic space, which `str.isprintable()` rejects). Grouping now lets padding owned by
either neighbour's unit join them. Two unnamed per-language string-pointer tables
(`lbl_17_data_6282C`, `lbl_17_data_6288C`) were named in `symbols.txt`.
