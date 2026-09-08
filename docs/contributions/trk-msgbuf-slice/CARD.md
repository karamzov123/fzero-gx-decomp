# MetroTRK ABI slice: three natural-C conversions in trk_80088B00

Target: GFZE01 `main/dolphin/metrotrk/trk_80088B00`, five functions —
`TRKSetBufferPosition` (0x30 bytes), `TRKAcquireMutex` (8 bytes),
`usr_put_initialize` (4 bytes), `TRKGetBuffer` (0x2C bytes),
`TRKReleaseBuffer` (0x64 bytes) — in
`src/dolphin/metrotrk/trk_80088B00.c`.

Base: GitHub main 48293c7019e77dad3a0565ec70bf51cfee29ea0f, including
contributor PRs #6, #8, #9, #10 and #14.

## Provenance

| function | reference |
|---|---|
| `TRKSetBufferPosition` | `melee:src/MetroTRK/msgbuf.c:90` |
| `TRKAcquireMutex` | `melee:src/MetroTRK/mutex_TRK.c:10` |
| `usr_put_initialize` | `melee:src/MetroTRK/usr_put.c:5` |
| `TRKGetBuffer` | `melee:src/MetroTRK/msgbuf.c:53` |
| `TRKReleaseBuffer` | `melee:src/MetroTRK/msgbuf.c:64` |

Adapted, not pasted: the reference bodies are melee's, but they only compile
against a `MessageBuffer` whose layout is retail's, not melee's. See below.

## The adaptation: MessageBuffer is 0x890 here, 0x88C there

melee builds MetroTRK with an empty `DSMutex`, so its `MessageBuffer` is
0x88C with `fLength` at 0x04. Retail's is 0x890 and every field after the
mutex is four bytes later. Three independent retail facts pin that:

* `TRKGetBuffer` indexes `gTRKMsgBufs` with `mulli r4, r3, 0x890`;
* `gTRKMsgBufs` is 0x19B0 bytes = 3 * 0x890;
* `TRKReleaseBuffer` clears `fInUse` with `stw r0, 4(r31)` — a word at 0x04,
  not melee's `bool`.

So `fLength` is 0x08, `fPosition` 0x0C, `fData` 0x10. `TRKSetBufferPosition`
is the direct check: retail reads 0x08 and stores 0x0C, which is melee's
`if (pos > buf->fLength) buf->fLength = pos;` after `buf->fPosition = pos;`.

The layout is independently corroborated by the unit's own hand-derived
`TRKBuffer` struct, which this replaces — same eight unknown leading bytes,
same 0x890 total, and the two functions already converted against it read
length at 0x08 and position at 0x0C exactly as the SDK names do. Those two
were renamed onto the SDK spelling so the reference bodies compile against
the names they were written with.

`include/dolphin/metrotrk.h` carries the result, with compile-time size
guards on both `MessageBuffer` (0x890) and `TRKMsgBufs` (0x19B0), so a
future edit that gets the layout wrong fails to build rather than silently
scoring worse.

`usr_put_initialize` has an empty body and carries the source comment the
reference policy requires: retail is a bare `blr`.

## The two mutex stubs are named the wrong way round

`TRKReleaseBuffer` is the one adaptation that is not a layout question.
melee's body is `TRKAcquireMutex(&b->fMutex); TRKSetBufferUsed(b, 0);
TRKReleaseMutex(&b->fMutex);`. Retail calls **`TRKReleaseMutex_stub` first
and `TRKAcquireMutex_stub` last** around the same `stw r0, 4(r31)`, so the
two symbols this tree carved out have each other's names.

The body here is written in retail's order against the names the carve gave
them, with a comment saying why, rather than renaming a public symbol as a
side effect of a conversion. Renaming them is a separate change and should be
its own one.

Retyping the two stub declarations and definitions from `(void)` to
`(register DSMutex* mutex)` is what took `TRKReleaseBuffer` from 87.400% to
exact: with the parameter typed, `&b->fMutex` no longer goes through an
implicit conversion.

## Verification

- All five functions score 100.000% against retail.
- The unit has exactly one imperfect symbol before and after this change —
  `TRKDoReset` at 99.773%, unchanged and pre-existing — so nothing regressed.
- Header adoption was landed and verified separately as codegen-neutral
  before any body was converted.
- `ninja`: full build; DOL SHA-1 `421c88106697d3275a3fc26fb7a01bf6d816b271`.
- 421 tests pass.

Verified conversion gain: five assembly functions replaced by natural C.
