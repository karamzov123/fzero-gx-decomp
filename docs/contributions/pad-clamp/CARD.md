# PAD signed-stick clamp

## Scope

Replace only `ClampS8` at `0x8001C0C0` (304 bytes) with C in
`src/dolphin/pad/pad_8001C01C.c`, and replace its assembly-only forward
declaration with the compatible five-argument prototype:

```c
void ClampS8(s8* px, s8* py, s8 max, s8 xy, s8 min);
```

The implementation keeps signed-byte loads/narrowing, signed integer arithmetic,
deadzone subtraction, and the two octagonal-limit divisions. It remains at the
same position in the existing owner. No PAD decoder, caller, storage definition,
split, symbol configuration, command-line flag, or compiler selection changes.

## Provenance

This is an adaptation of reference SDK code, not an original-authorship or
clean-room claim. The function's adjacent marker identifies the actual reference:

- `prime:extern/sdk/dolphin/pad/PadClamp.c:71`, `ClampStick`, from
  [PrimeDecomp/prime at `3fb2167ba9161b8067f53620e72ad34c65a8aeb3`](https://github.com/PrimeDecomp/prime/blob/3fb2167ba9161b8067f53620e72ad34c65a8aeb3/extern/sdk/dolphin/pad/PadClamp.c#L71).
  The complete reference body was consulted. Adaptation changes its name and
  linkage to the receiving owner's existing global `ClampS8`, supplies the
  compatible local declaration, and follows receiving indentation.
- Corroborating reference, not the imported body:
  [doldecomp/dolsdk2001 at `eb1234c45e6df75757c652c835507ca89674f9a8`](https://github.com/doldecomp/dolsdk2001/blob/eb1234c45e6df75757c652c835507ca89674f9a8/src/pad/Padclamp.c#L11),
  `src/pad/Padclamp.c:11`. That older `ClampStick` uses fixed constants and a
  two-argument signature; those constants/signature are not substituted here.

## Local compiler control

The unchanged GC/1.2.5n compiler emits 308 bytes for the normal reference port in
this mixed assembly/C owner. A `#pragma peephole on` immediately before
`ClampS8` restores the 304-byte match. A separate same-body control with explicit
local `peephole off` reproduces the normal port's complete allocated output.
The later existing decoder pragma is retained; it cannot restore optimizer
state for this earlier function. No function reordering or global build-option
workaround is used.

Compiler executable SHA-256:
`ccf4b465cec73b5aae9c5c5543dcf8cda8a62aba246f89e2e0b200d742f2e55c`.

## Verification

Receiving base and freshly checked upstream main:
`41b5520b3dd134f5b01dacb646297b62fd7261c4`.

- Fresh baseline, candidate, and restored **current-base full source builds**
  (`ninja -v -j4 all_source build/GFZE01/main.dol`) succeed and produce retail
  SHA-1 `421c88106697d3275a3fc26fb7a01bf6d816b271`. No last-green fallback is used.
- All 25 owner functions, allocated sections (bytes/type/flags/size/alignment),
  normalized symbols, and 418 relocation records equal the fresh source-built
  baseline. All existing decoder/caller bodies remain unchanged. Same-path
  baseline, candidate, and restored owner objects are also **raw byte-identical**.
- All 25 function byte sequences also equal the retail-split owner. The retail
  split object is not raw-identical: its SDA21 relocations name the instruction
  start while MWCC names the halfword at `+2`. After explicitly normalizing only
  those offsets, all 418 relocation records agree. This representation adjustment
  is not needed for baseline/candidate/restored comparisons.
- A meaningful actual C-source negative control changes only `x -= min` to
  `x += min`. The source rebuild/link succeeds, but its separate checksum gate
  fails with DOL SHA-1 `a87d22ab9c79287df91d3371265b47b4529d66a5`.
  Only `ClampS8` changes; its size, symbol metadata, and relocations remain fixed.
  Exact source restoration recompiles and relinks the original object/DOL.
  Baseline, candidate, mutant, and restored source/object/DOL artifacts are frozen
  separately. No binary patch or supplied replacement object is used.
- The pinned-compiler ABI probe verifies signed-byte width 1, integer/pointer
  width 4, and unchanged `PADStatus` size 12/alignment 2/axis offsets 2–5/error
  offset 10. Both declarations and a typed function-pointer initializer agree.
  The unchanged actual `PadClampStatus` passes byte pointers in r3/r4 and
  max/xy/min in r5/r6/r7. Linked table `0x8008FF40` matches retail and supplies
  `(72,40,15)` and `(59,31,15)`; the callee sign-extends its byte parameters.
- Fresh repository discovery runs **11 tests**, passing on baseline, candidate,
  and restored source. Builds/probes use an offline namespace sandbox with
  read-only source/assets/root, dropped capabilities, and resource limits.

- Final candidate and restored linked DOLs each pass **131,072 ClampS8 cases**:
  every signed-byte coordinate pair for both retail parameter sets, with varied
  distinct pointer placements. Each also passes **1,792 cases** through the real
  four-status `PadClampStatus` caller, without mocked calls.
- Checks cover outputs, err/padding/guards, memory-access bounds, incoming stack
  backchain/canaries, SP/LR, nonvolatile GPRs and CR2-CR4. Separate diagnostic
  corruptions prove sensitivity; they are not the source-participation proof.
- The actual source mutant fails both a direct leaf test and a real-caller
  dead-zone-boundary test. The unchanged code passes those same witnesses.
- Unchanged SPEC0/SPEC1 decoders pass **268,192 regression cases per positive
  DOL**, and `PADSetSpec` passes eight callback-selection cases per positive DOL.

These are bounded linked-PowerPC checks, not hardware tests, FPR-preservation
proof, or validation of arbitrary clamp parameters, aliasing or invalid divisors.
Proprietary compilers, assets, generated binaries/disassembly and private
investigation records are excluded from the contribution.
