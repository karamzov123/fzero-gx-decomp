# Native dropped-frame query landing: reuse the accepted helper family first

## Accepted result

`fn_12_3A69C` is exact native C: 232 bytes / 58 instructions, GC/1.3.2,
acceptance commit `e76abf74`. Normal submit and verify accepted it without
rejection. The canonical unit independently checks at 100.0%, `matched: true`,
`matched_pool: false`, and is registered `matching` with link state `verified`.
Its pool is a verified relocation dictionary, not boolean fallback credit.

Portable source, source fingerprint, canonical oracle receipt, registration,
owned-region proof, gate log, and four nonmatching frontiers are recorded in:

`state/repairs/movie-drop-query-native-20261017.json`.

## Reuse the operations recovered in fn_12_39A68

The historical draft flattened three validity checks and held error strings
through an invented aggregate view over `lbl_12_rodata_2718`. Its third message
was actually in the following object, beyond that owner's declared extent.
It also treated repeated queries as flat control flow rather than the real
stream/skip-count operations.

This entry point implements precisely the dropped-frame query already
recovered as an inline operation in `fn_12_39A68`:

1. Validate the player; on failure, report the drop-count error and return 0.
2. Obtain the skipped-decoder count, with that operation's own validity and
   stream-handle checks and error paths.
3. Add `fn_12_33874(object)` and return the result.

Reuse the accepted `ply_is_valid`, `ply_get_stream`, and `ply_get_skip_dec`
operations and byte-proven native readonly objects. The first complete
helper-family reproduction was already exact. Then remove the unrelated
empty-B operation, its unused 52-byte error object, and the public entry's
extra forwarding layer. The direct public body still matches all 58 retail
instructions. The remaining helpers perform real operations; no pointer-read
wrapper, one-field liveness carrier, register pin, or assembly escape is used.

The retained `.rodata` prefix is 353 bytes, 0x2718..0x2879:

| Object | Bytes |
| --- | ---: |
| 0x2718 owner prefix through +0xd4 | 212 |
| owned interior message at +0xd4 | 44 |
| owned interior message at +0x100 | 48 |
| following named message at 0x2848 | 49 |

The original 304-byte owner and following 49-byte object are relocation-free
and completely account for this prefix. The four native objects partition
those real bytes; none is invented padding. Original symbol identity and the
interior `__fzgx_offset_` bindings are verified before rebinding the private
shared base.

Before chasing unrelated high-percentage functions, inspect unmatched public
entry points for the inline algorithms just recovered in accepted callers.
That relationship proved more productive here than scalar/register spelling
sweeps.

## Nonmatching work retained, with no code credit

### fn_1_103B0 — live-camera interpolation

Recovered a 184-byte native literal primer. Aligned `fn_80008E30` with its
canonical unsigned return declaration, preserving retail's signed conversion
with an explicit s32 cast at the float use. This removes the old translation-
unit declaration conflict.

The clean 258-word draft still has 14 differing rows: entry scratch-register
assignment, half-period floating registers, and argument-address ordering.
An explicit index, ordinary parameter copy, multiplication commutation, a real
repeated point-interpolation helper, and 10,317 public-search candidates did
not close it. Disabling propagation regresses to 23 rows / 259 aligned words.
Do not repeat these source families without new evidence. Not submitted.

### fn_1_F326C — replay updates

The historical five-row frontier used artificial one-field loop/base/vector
carriers, and the s16 base snapshot generated an unwanted sign extension.
Removed these in the portable preferred native draft, retained a genuine s32
index snapshot, and documented the actual second shared-byte flag observation.
The clean draft remains 43 differing rows / 194 aligned words. A positive
bit3 body, full difference-vector record, nested loop-index scope, and real
per-racer helper did not reproduce the register assignment or retained guard
branch. Do not promote the historical carrier cache. Not submitted.

### fn_12_22008 — channel range consumption

The saved 12-row draft included an allocator-only forwarding wrapper around
`fn_12_24A88`. The wrapper-free raw channel/state version remains 23 differing
rows / 147 aligned words. A real position-validation helper and a small channel
header were measured but did not recover the held +0x1150 state base. All
measurements that compare the prologue must retain `-use_lmw_stmw on`.
Not submitted.

### fn_12_3D740 — YUV lookup-table construction

Confirmed the real BSS owner is 0x354 bytes (852) and coefficient input is a
0x24-byte data object. A correctly typed, complete native BSS owner avoids the
old diagnostic float-array cast but does not improve code generation. The
preferred scratch version remains at 66 differing rows / 139 aligned words.
Function-scoped propagation/common-subexpression settings were also measured
and left the same result. The matrix pointer is folded into context-relative
loads rather than held in retail's r7; the conversion-bias/constant addresses
and subsequent scratch allocation differ. The existing canonical nonmatching
file was left unchanged. Not submitted.

## Verification and scope

After the accepted query was rebuilt, with all manual claims released:

    ninja build/GFZE01/ok
        rebuilt fn_12_3A69C.o, linked movie_module, regenerated RELs
        16 files OK (exit 0)
    build/tools/dtk shasum -q -c config/GFZE01/build.sha1
        16 files OK (exit 0)
    .venv/bin/python tools/fzgx.py lint
        0 finding(s) (exit 0)

Only fn_12_3A69C earns new linked-C credit in this continuation. Source and
compiler proof, not raw percentages, determine admission. No runtime/emulator
claim is made. Work was entirely inline, with no subagents and no changes to
another worker's claims or source. The approved fork publisher independently
checks the committed snapshot before publication.
