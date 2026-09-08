# CARD read / seek

## Scope and attribution

Receiving base: `145ce2718fe82b9301e2de91bd8d45e850665798` (`GFZE01`).
The four-file contribution consists of this document and three source files:
`src/dolphin/card/CARDRead.c`, `src/dolphin/card/CARDBlock.c`, and
`src/dolphin/dsp/DSP.c`. Only the read trio gains C implementations. The latter
two files receive minimal declaration/definition signature repairs, retaining
every existing brace body byte-for-byte. Function order, global linkage,
`force_active`, configuration, splits, storage and shared headers are unchanged.
No new assembly is introduced.

| Function | Retail address | Bytes | Change / provenance |
| --- | --- | ---: | --- |
| `__CARDSeek` | `0x8002F140` | 440 | C adapted from `prime:extern/sdk/dolphin/card/CARDRead.c:8` |
| `CARDRead_ReadCallback` | `0x8002F2F8` | 304 | C adapted from `prime:extern/sdk/dolphin/card/CARDRead.c:56` |
| `CARDReadAsync` | `0x8002F428` | 328 | C adapted from `prime:extern/sdk/dolphin/card/CARDRead.c:104`; public-permission fallback corroborated by `dolsdk2001:src/card/CARDRead.c:118` |
| `CARDRead` | `0x8002F570` | 72 | Signature-only correction to four arguments; entire existing assembly brace body preserved verbatim, not counted as new C |

Auxiliary signature-only repairs (no new implementation or matching credit):

| Source / helper | Repair / provenance |
| --- | --- |
| `CARDBlock.c` / `__CARDGetFatBlock` | Forward declaration and definition become `unsigned short*(struct CARDControl*)`, with a file-scope forward tag; shared header's typed ABI is authoritative. Existing `dolsdk2001:src/card/CARDBlock.c:9` implementation marker and complete brace body are retained. The SDK reference itself returns `void*`; it is not claimed as the source of the receiving typed return. |
| `DSP.c` / `__CARDDefaultApiCallback` | Forward declaration and definition become `void(int chan, int result)`; the empty brace body is unchanged. `dolsdk2001:src/card/CARDBios.c:22` corroborates the callback signature only, not a newly imported implementation. |

These are adaptations, not original/clean-room reconstructions. The SDK was
inspected first. The Prime revision supplies the closer retail callback
arithmetic and two-argument access check. Pinned references:

- [PrimeDecomp/prime, CARDRead.c](https://github.com/PrimeDecomp/prime/blob/3fb2167ba9161b8067f53620e72ad34c65a8aeb3/extern/sdk/dolphin/card/CARDRead.c),
  commit `3fb2167ba9161b8067f53620e72ad34c65a8aeb3`,
  Git blob `ffffc5f94ece1ae67049ab0276bea4d08538ed23`,
  file SHA-256 `151344b03cdd45b548fdd8bce146ff28603d3d5f16329c421bb6189a583d40e1`.
- [dolsdk2001, CARDRead.c](https://github.com/doldecomp/dolsdk2001/blob/eb1234c45e6df75757c652c835507ca89674f9a8/src/card/CARDRead.c),
  commit `eb1234c45e6df75757c652c835507ca89674f9a8`,
  Git blob `698ce86ecfd9634e508f6e1cd89521121bc44ae3`,
  file SHA-256 `eb2fbe06ef21ae3e45e3194132dfddd020cdd9d1d68ff3674be87467f234d723`.
  Seek/callback/Async start at lines 12/64/118 respectively.

Both references were retrieved from the exact Git commit/path and bound to
those blob IDs. Auxiliary SDK references use the same pinned SDK commit:

- [CARDBlock.c line 9](https://github.com/doldecomp/dolsdk2001/blob/eb1234c45e6df75757c652c835507ca89674f9a8/src/card/CARDBlock.c#L9),
  blob `a1cb35458c7023ff89a659ec589bd6201652aa5c`,
  SHA-256 `a04fea68ce6bcfd76c4ec46cb177ad2bd6d80fbe0d2acb7ab1181366a466788c`.
- [CARDBios.c line 22](https://github.com/doldecomp/dolsdk2001/blob/eb1234c45e6df75757c652c835507ca89674f9a8/src/card/CARDBios.c#L22),
  blob `b6959f78e86f5db5509523b011509ebffa962b00`,
  SHA-256 `20f021700576c39fb67ebd16907fd764fa141ad3c63165251d8367bf9c5a9778`.

## Receiving adaptations

- Seek uses the existing `CARDFileInfo` / `CARDControl` / `CARDDir` definitions.
  Capacity bounds and rewind comparisons explicitly interpret 32-bit words as
  `s32`, matching retail `cmpw`; the FAT traversal comparison remains unsigned
  (`cmplw`). The shared unsigned `offset` and `sectorSize` declarations do not
  change. No extra argument validation or rollback is invented.
- Callback retains receiving external name/linkage rather than Prime's static
  `ReadCallback`. A single-pass `do ... while (0)` with `break` uses one common
  completion block without the reference's reducible `goto` cleanup.
- Callback consumed length is the next-sector boundary minus current offset:
  `((offset + sectorSize) & ~(sectorSize - 1)) - offset`. Its arithmetic casts
  preserve the signed interpretation of the reference fields while retaining
  the receiving ABI. The SDK reference's additional sector-minus-one term and
  its special conflicting-cast workaround are deliberately not copied.
- Callback reads the buffer already advanced by the lower-level CARD transfer;
  it does not advance that buffer again. Completion saves and clears
  `apiCallback`, releases the card, then invokes the saved `(chan, result)`
  callback. Successful continuation does neither release nor API dispatch.
- Async uses the receiving `__CARDAccess(card, ent)` two-argument ABI, not the
  older SDK's one-argument call. On `NOPERM`, it uses receiving
  `__CARDIsPublic(ent)`, not Prime's `__CARDIsWritable`.
- `DCInvalidateRange` explicitly takes `unsigned int`, as defined by the actual
  receiving `OSCache.c` typedef, not CARD's distinct `unsigned long` spelling
  of `u32`. Equal target width alone does not make C declarations compatible.
- Async preserves alignment checks, permission-before-invalidation sequencing,
  signed first-transfer minimum, default callback selection and immediate
  read-error behavior. An immediate error releases the control block without
  clearing the installed API callback or invoking it, as in retail.

## ABI boundary audit

| Boundary | Receiving evidence / interpretation |
| --- | --- |
| `__CARDSeek` | Existing shared `s32(CARDFileInfo*, s32 length, s32 offset, CARDControl**)`; actual C caller `CARDWriteAsync` unchanged |
| `CARDReadAsync` | Five arguments in r3–r7: handle, buffer, signed length, signed offset, callback; old channel/four-argument placeholder corrected |
| `CARDRead_ReadCallback` | `void(s32 chan, s32 result)` matches `CARDCallback`; old s32/BOOL placeholder corrected |
| `CARDRead` | Four arguments r3–r6; assembly supplies sync callback in r7; only definition signature corrected |
| `__CARDRead` | Local declaration models actual asm r3–r7 arguments and s32 result: channel, address, length, buffer, callback. Body in CARDBlock stores callback/address/segment count/buffer and returns the segment result |
| Get/PutControlBlock, GetDirBlock, Sync | Existing shared declarations model the actual register inputs/results; definition files still contain historical asm void placeholders |
| `__CARDAccess`, `__CARDIsPublic` | Receiving typed two-pointer access function and actual C entry-pointer public check, respectively |
| `DCInvalidateRange` | Actual typed OSCache definition uses `(void*, unsigned int)`; new C call/declaration use that exact underlying type |
| `__CARDGetFatBlock` | Actual C definition and forward declaration repaired to `unsigned short*(struct CARDControl*)`, compatible with existing shared `u16*(CARDControl*)` |
| `__CARDDefaultApiCallback` | Actual empty C definition and forward declaration repaired to `void(int,int)`, compatible with existing shared callback type |

This is not a claim that the surrounding repository is globally ISO C
type-consistent. The two actual-C helper signature mismatches above are repaired,
not waived because register widths happen to agree. Other inherited assembly
placeholders remain: the shared sync callback models two callback arguments,
while its asm definition consumes channel and ignores result. The typed
declarations for such boundaries model observed machine inputs/results; complete
cross-TU C type consistency for those historical placeholders is not established.
This change neither duplicates private structs nor performs a whole-SDK cleanup.

Actual target-compiler guards checked `s32`/`u32` width, callback pointer width,
`CARDFileInfo` size `0x14`, `CARDControl` size `0x110`, `CARDDir` size `0x40`,
`__CARDBlock[2]` size `0x220`, and every field offset used here. Relevant offsets:
file handle chan/fileNo/offset/length/iBlock = `0/4/8/0x0C/0x10`; control
sectorSize/cBlock/buffer/fileInfo/apiCallback/diskID =
`0x0C/0x10/0xB4/0xC0/0xD0/0x10C`; directory startBlock/length = `0x36/0x38`.
Complete-TU redeclaration probes use the actual CARDRead, CARDBlock, DSP,
OSCache and CARDWrite sources at their normal paths with their unchanged
generated compiler commands. Five positive probes compile and preserve their
whole raw baseline objects. Ten negative controls are rejected: owner layout,
callback return, cache integer type and old helper prototypes; both actual-C
helper definitions with their old prototypes; the cache definition with an
unsigned-long prototype or changed unsigned-long typedef; and the header-using
CARDWrite caller with a wrong Seek length type. Each TU is restored to its exact
source and raw object. These are actual definition/declaration checks, not a
standalone reconstructed type sketch.

## Build verification

The fresh pinned baseline and final candidate were compiled in the same isolated
checkout with the repository's actual **GC/1.2.5n MWCC** command, including the
existing `-O4,p`, `-inline auto`, `-fp_contract on` and other generated flags in
their original order. No per-file compiler override or classification change
was used. Build tooling was fixed and hash-recorded; only the isolated lane was
writable. The owner source, exact command/log/exit receipts, dependency files,
objects, ELF, map and DOL are retained privately, not added to the contribution.

- Entire raw owner object equals the baseline, not merely selected opcodes.
  All four functions, all allocated section bytes, symbol properties and all
  30 relocations also equal the freshly extracted retail owner object.
- All 196 all-source object hashes equal the baseline in candidate/restored
  builds, including unchanged `CARDWrite` and the typed OS cache callee. The
  signature-only synchronous wrapper remains byte- and relocation-identical.
- The current three edited TUs first passed a bounded same-path raw-object
  comparison against the original-base hashes before proceeding. A new untouched
  pinned baseline and candidate then freshly rebuilt all 196 source objects.
  Entire CARDBlock and DSP raw objects, all their functions and relocation
  records remain exact after the signature-only repairs.
- `ninja all_source build/GFZE01/main.dol` succeeds. Fresh baseline, corrected
  candidate and every source-mutant restoration produce retail DOL SHA-1
  `421c88106697d3275a3fc26fb7a01bf6d816b271`; the repository hash check succeeds.
- Repository unittest discovery finds and passes 11 tests for baseline,
  corrected candidate and final restoration. These are build-tool tests, not
  CARD behavior tests.
- Three actual source mutants were separately compiled and linked through the
  same source path: Seek stores offset instead of requested length; callback
  adds rather than subtracts consumed length; Async checks BROKEN instead of
  NOPERM for the public fallback. Each changes only its intended function's
  bytes, preserves function size/symbols/relocations, links successfully, and
  fails the retail DOL hash check. Each restoration returns to the exact raw
  owner/all-source hashes and retail DOL. This proves linked source sensitivity,
  not by itself behavioral correctness.

Matching history is bounded and retained: first candidate matched Seek but
emitted a 300-byte callback; signed field interpretation gave exact 304-byte
callback/whole owner on the second hypothesis. A third compilation verified the
review-required cache typedef correction without any machine-byte difference.
Earlier type-incompatible draft evidence is explicitly superseded, not silently
presented as the final source's proof.

All claims in this section are pinned to `145ce2718fe82b9301e2de91bd8d45e850665798`.
Upstream advanced during verification; this is not a build claim for a newer
upstream tip or a subsequent merge. Two diagnostic-validator retries retained
the compiler's expected rejections and exact source/object restorations; only
the harness's MWCC diagnostic-text matching changed, not candidate C hypotheses.

## Behavior and acceptance boundary

The independent linked PowerPC oracle passed 209 distinct cases on each of the
fresh baseline, candidate and three separately rebuilt restorations: **1,045
positive case runs**. Per DOL, these comprise 86 direct Seek cases, 56 direct
callback cases, 58 direct Async cases, seven asynchronous continuation/completion
scenarios, and two executions through the unchanged synchronous wrapper. The
latter cases execute the real linked read trio; external CARD/cache/sync helpers
are intercepted at their linked addresses with explicit bounded stub behavior.

The matrix covers acquisition failures, signed bounds, backward/forward seek,
FAT link errors, sector fragments, permission fallback, immediate scheduling
errors, default/user callbacks and complete multi-sector dispatch. It compares
API returns (not the void callback's incidental r3), final file/control state,
stub call order/arguments, and state at release/callback boundaries. Integer
callee-saved registers, CR2-4, SP/LR, field/stack access boundaries, protected
backchains, code immutability and a step budget are checked. Thirteen real
instruction-level diagnostics are rejected, including access, backchain,
nonvolatile-register, timeout and callback-clear ordering faults. Optimized
Python is rejected so assertions cannot silently disappear.

Each separately compiled source-mutant DOL is also behaviorally rejected:
64 direct Seek witnesses, 51 direct callback witnesses and ten direct Async
witnesses. Isolated unaffected-function controls still pass. These source-bound
checks are distinct from the in-memory instruction diagnostics above.

Independent final review remains a separate acceptance gate. This is bounded
linked-code testing, not a proof over every possible handle or input. Access
whitelists do not establish exact read counts or complete memory-access order;
no floating-point preservation claim is made. Hardware/cache helper stubs cannot
establish actual card-device I/O. Ordinary signed arithmetic still requires
representable input expressions; there is no portable arbitrary-overflow,
corrupt-handle, malformed-FAT, or unconstrained pointer-alias guarantee. No new
null-callback guard is invented where retail requires an initialized callback.
