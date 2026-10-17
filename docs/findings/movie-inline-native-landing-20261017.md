# Two movie-module native-C landings: inline boundaries and owned subobjects

Both functions are exact native C, registered `matching`, with `link_state`
`verified`. Neither is a pool-only retail fallback. Their pool maps are
relocation dictionaries, not `pool: true`.

| Function | Retail text bytes | Compiler | Acceptance commit |
| --- | ---: | --- | --- |
| fn_12_39A68 | 572 (143 instructions) | GC/1.3.2, -O4,p | 86dd13a5 |
| fn_12_2A6FC | 352 (88 instructions) | GC/1.3.2 | 15b6ef10 |

Total newly linked native C: 924 bytes. Source, SHA-256 fingerprints, complete
exact oracle receipts, unit registrations, owned-region proofs, and the final
hash/lint output are in
`state/repairs/movie-inline-native-landing-20261017.json`.

## fn_12_39A68: reconstruct meaningful inline helper boundaries

The old draft expanded every validity check and result query into one body,
held an external error-array address through a macro-shadowed local, and used
out-of-bounds offsets beyond its declared 304 bytes. The historical 97.6%
frontier was not merely a zero-offset spelling problem.

The retail `.rodata` interval 0x2718..0x28b0 was recovered from module bytes,
not invented zero padding:

- owner 0x2718 is 0x130 bytes; its prefix is 0xd4 bytes and includes earlier
  strings plus actual numeric literal bytes, preserved byte-for-byte;
- its error messages at +0xd4 and +0x100 are independent bounded arrays of
  44 and 48 bytes, using verified `__fzgx_offset_` subobject bindings;
- named owners 0x2848 and 0x287c contain 49 and 52 bytes; the intervening
  three bytes are emitted by the compiler's alignment of the native objects.

Defining these native objects removes the MR-vs-ADDI and extra address-add
problems, but a flat body still changes the register allocation. Reconstructing
actual operations as inline helpers closes the rest:

- player validity;
- stream-handle access with its own validation/error;
- decoded-frame skip count;
- total dropped-frame count, including the separate fn_12_33874 query;
- empty-B skip count.

These helpers have actual algorithmic responsibilities and result structs;
they are not pointer-read wrappers or allocator-only liveness carriers. MWCC
reproduces the retail 0x120-byte frame, four result-buffer positions, shared
error-base register, and all 143 instructions. Explicit -O4,p overrides the
unit's old -O1 setting; the selected flags are stored in units.json.

The object oracle reports 100.0%, `matched: true`, `matched_pool: false`.
Normal submit queued the function, and verify accepted it without rejection.

## fn_12_2A6FC: remove the oversized BSS layout, bind the real owner

The saved 98.3% draft declared the first 0x70 bytes as several objects with
noncanonical names, then retained an unrelated 18,440-word buffer and later
BSS globals merely to prime the section. Its supposed two layout-only rows
were not a complete ownership solution.

The real `.bss` owner `lbl_12_bss_96A0` is exactly 0x70 bytes:

| Offset | Size | Meaning |
| ---: | ---: | --- |
| 0x00 | 4 | leading state word |
| 0x04 | 64 | sixteen aligned widths |
| 0x44 | 8 | aligned width/height |
| 0x4c | 36 | copied MovieParams record |

The sum is 112 bytes and the ranges partition the owner without overlap or
fabricated gaps. Keep these as bounded native subobjects, with canonical
`__fzgx_offset_4`, `_44`, and `_4C` names. The legitimate first-access primer
mentions only these four objects and remains in `.fzgxpool`; the requested
function is in `.text`. No unrelated buffer or following BSS object is needed.

Collapsing the subobjects into one struct was measured but not retained: it
folds the explicit params/size addresses into field stores, eliminates the
retail frame, and changes 56 of 89 aligned rows. Separate native subobjects
preserve the retail access shape and allow verified rebinding of `.bss.0` to
the real owner. The result is exact: 100.0%, `matched_pool: false`, all 88
instructions. Normal submit and verify linked it successfully.

## Final gate and scope

After both acceptances, with no live claims or pending links:

    ninja build/GFZE01/ok
        ninja: no work to do. (exit 0)
    build/tools/dtk shasum -q -c config/GFZE01/build.sha1
        16 files OK (exit 0)
    .venv/bin/python tools/fzgx.py lint
        0 finding(s) (exit 0)

Both C units are active build inputs. No emulator/runtime claim is made;
this result is instruction exactness plus every linked target's retail hash.
Work was performed inline, with no subagent source or compiler result used.
Other workers' claims and source were not modified. The approved publisher
performs an additional isolated committed-snapshot build before publication.
