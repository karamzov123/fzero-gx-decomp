# MSL rand (`fn_80082908`)

## Scope and provenance

- Function: `fn_80082908`, GFZE01 `.text:0x80082908`, 0x20 bytes.
- Source: `src/dolphin/msl/tail_8008279C.c`.
- Provenance: original reconstruction of the existing retail instruction sequence,
  previously matched in a separate GFZE01 tree and adapted to this source unit;
  no external reference implementation was adapted.
- Keep the existing function name, source unit, split map, and compiler flags.
- Interpret `lbl_801A6638` as two 32-bit words, preserving its existing 8-byte
  extent. Only the first word is read and updated; unsigned arithmetic preserves
  the retail modulo-2^32 state transition.
- Update the declaration in `src/game/gamehead_8005C120.c` to return `int`.

## Verification

Base: `3eed2db4c4d2679842a67fd964c7e90049b34950`.

Compiled both changed translation units before and after the patch using the
project's GC/1.3 compiler and configured flags:

```sh
ninja build/GFZE01/src/dolphin/msl/tail_8008279C.o \
      build/GFZE01/src/game/gamehead_8005C120.o
```

An ELF comparison verified identical allocated section contents, alignment,
function layouts, and relocation tuples (target section, offset, type, symbol,
symbol section/value, and addend):

- MSL tail: all 13 functions and 39 relocations unchanged, including the 32-byte
  `fn_80082908` and its two state accesses.
- Caller unit: all 63 functions and 2,169 relocations unchanged.

### Supplementary full-link check

The full build at the base above is blocked by the absent
`dolphin/card_private.h`; the report tests are separately blocked by the absent
`tools/natc_asmforms.py`. These unrelated dependencies are not changed here.

For an additional link check, applied the same two-file patch to the last
buildable public revision, `12770d18ff53941a14204d926f22fa3fb2c40315`.
The two source files are identical between those upstream revisions.
Both its unmodified build and the patched build passed:

```sh
ninja build/GFZE01/main.dol
sha1sum -c config/GFZE01/build.sha1
```

DOL SHA-1: `421c88106697d3275a3fc26fb7a01bf6d816b271`.

As a negative control in that isolated build, changing the increment from
12345 to 12346 changed the linked DOL hash. Restoring 12345 restored the retail
hash. This confirms that the new C body participates in the link, rather than
being bypassed by an original-object fallback.

This supplementary result is not a claim that the complete current public
checkout builds successfully.
