# PAD status decoders

## Scope

Replace `SPEC0_MakeStatus` and `SPEC1_MakeStatus` with C in
`src/dolphin/pad/pad_8001C01C.c`. Both compile to the existing 372-byte
functions at their original positions. `PADSetSpec` uses a compatible typed
callback instead of pointer/integer casts. `SPEC2_MakeStatus` receives only a
compatible declaration and definition signature: its assembly body is retained,
not credited as a new C match.

The complete local `PADStatus` includes caller-owned `err` and ABI tail padding.
Response words remain `unsigned long` consistently across all callback
prototypes, definitions and assignments; the owner's existing public `u32`
typedef remains `unsigned int`. No storage definition is moved or introduced.

## Provenance

These are adaptations of consulted SDK reference code, not an original-authorship
or clean-room claim. Adjacent `provenance:` markers identify the reference used
for each decoder and the complete status type.

- [PrimeDecomp/prime](https://github.com/PrimeDecomp/prime/tree/3fb2167ba9161b8067f53620e72ad34c65a8aeb3),
  pin `3fb2167ba9161b8067f53620e72ad34c65a8aeb3`:
  `extern/sdk/dolphin/pad/pad.c:514` (SPEC0), `:541` (SPEC1), and
  `extern/sdk/include/dolphin/pad.h:59` (complete `PADStatus`).
- [doldecomp/dolsdk2001](https://github.com/doldecomp/dolsdk2001/tree/eb1234c45e6df75757c652c835507ca89674f9a8),
  pin `eb1234c45e6df75757c652c835507ca89674f9a8`:
  `src/pad/Pad.c:647` (selector), `:672` (SPEC0), `:697` (SPEC1), inspected
  as a corroborating reference. The source markers above identify Prime as
  the actual decoder/type reference rather than silently attributing another
  corpus.

## Local compiler workaround

GC/1.2.5n leaves peephole optimization disabled after preceding assembly in
this mixed translation unit. One `#pragma peephole on` immediately before SPEC0
locally restores it. Controlled comparisons reproduced the disabled output with
explicit `nopeephole` and recovered the matching full owner with this pragma.
This is an intentional local optimization-state change; the compiler pin,
command-line flags, function order, split configuration and linker setup are
unchanged. The adjacent source comment explains why the pragma is necessary.

## Verification and current-base caveat

Receiving base: `9af7e15af23b0dcfbce890532f984f5eb555edfd`.

- Fresh baseline and candidate PAD owner builds used the same original
  GC/1.2.5n command. All 25 functions, allocated-section contents and metadata,
  normalized symbols (excluding file-name metadata), and 418 relocations match
  the receiving baseline. Both new C functions are 372 bytes. The final
  same-path baseline, candidate and restored owner objects are also byte-identical.
- Both current-base full builds fail at the pre-existing EXIBios
  `lbl_801A6840` assembly error. No EXI, CI or unrelated repair is included.
- Supplemental full source builds used unmodified last-green base
  `675f69f289b338df4a7098fedcf89a73de23d113`, first unchanged and then with this
  exact candidate owner source. Both linked a DOL identical to the original
  (SHA-1 `421c88106697d3275a3fc26fb7a01bf6d816b271`).
  The PAD baseline source, relevant symbol/storage and split conditions, and
  receiving compiler command were checked for comparability. The bases have
  unrelated EXI configuration differences; each base kept its own configuration.
  The supplemental result does not assert that the current-base full build passes.
- Separate semantic source mutations raised only the left-trigger threshold
  from 170 to 171 in SPEC0, then SPEC1. Each actual Ninja build emitted a
  nonmatching DOL and failed the hash gate; only the intended function changed,
  with function sizes, normalized symbols and relocations preserved. Each exact
  source restoration rebuilt the matching DOL successfully. No supplied PAD
  object or binary replacement was used.
- Pinned compiler probes bound to the final source verified status size 12,
  alignment 2, member offsets, 4-byte response words and callback pointers, and
  compatible initializers for all three decoder callbacks. Generated storage
  and the linked DOL confirm the aligned 4-byte callback slot initially points
  to SPEC2. A repository-wide declaration/use audit and the retained assembly
  caller agree on channel, status pointer and response pointer arguments.
- Automatic discovery ran the receiving repository's actual eight tests
  successfully on both bases, the candidate, and final restoration.

Builds and probes ran in an offline sandbox with read-only root and source
inputs, isolated namespaces, dropped capabilities and resource limits. Detailed
commands, source/object bindings, baseline failures, layout/storage probes, and
separate mutant/restored artifacts are retained privately. No proprietary
compiler, retail asset, generated binary, disassembly, or private investigation
record belongs in this contribution.

Linked PowerPC emulation separately passed **268,192 decoder cases and eight
`PADSetSpec` selector cases per DOL** on the candidate-source supplemental build
and both independently rebuilt restorations. Coverage includes all 16-bit
button fields, all trigger-byte pairs, every axis-byte value, deterministic
random packets, channels 0–3 and halfword-aligned status buffers. Checks preserve
input data, guard bytes, caller-owned error/padding, nonvolatile GPRs and CR2–4.
The selector test independently binds SDA to linked startup instructions and
checks the original SPEC2 initializer before seeding test states.

Each actual source-mutant DOL failed the expected status check at trigger value
170; its unaffected decoder still passed 134,096 cases. These execute linked
instructions, not C substitutes. Hardware-dependent `PADRead` and SPEC2 decoder
behavior are outside this emulation scope.
