# __CARDCheckSum

## Scope and provenance

- One natural-C function, `__CARDCheckSum`, 432 bytes at `0x8002C720`.
- Actual receiving owner: `src/dolphin/card/CARDBlock.c`, already `Matching`.
- The owner forward declaration and the one declaration in `CARDDir.c` are
  corrected to `void (void *, int, unsigned short *, unsigned short *)`.
  No caller body, configuration, compiler, flags, split, function order, storage,
  unrelated CARD function, or matching classification changes.
- `// provenance: dolsdk2001:src/card/CARDCheck.c:11`
  ([reference](https://github.com/doldecomp/dolsdk2001/blob/eb1234c45e6df75757c652c835507ca89674f9a8/src/card/CARDCheck.c#L11)).
  Corroboration: [Prime `extern/sdk/dolphin/card/CARDCheck.c:13`](https://github.com/PrimeDecomp/prime/blob/3fb2167ba9161b8067f53620e72ad34c65a8aeb3/extern/sdk/dolphin/card/CARDCheck.c#L13).
  Both exact-case paths were verified with `git show` at those revisions.
  This is reference adaptation, not an original-authorship claim. A cached
  adaptation informed discovery; the public SDK source is the attribution.

The adaptation omits the SDK debug assertion, spells `u16` as its compatible
`unsigned short` type, uses explicit signed division by two, and sequences the
inverse/sum initialization as separate stores. The signed division is deliberate:
under the receiving compiler, division by `sizeof(unsigned short)` is unsigned
and would not preserve retail behavior for negative lengths. Separate stores
preserve retail order while avoiding a chained double write if outputs alias.

## ABI and behavior

The receiving GC/1.2.5n compiler, with the unchanged project's flags, compiles a
probe derived from the complete final source and both actual declarations.
It verifies signed 32-bit `int`, 32-bit pointers, unsigned 16-bit output/input
words with two-byte alignment, and the compatible function-pointer type.
Additional compiled probes distinguish signed `/ 2` from unsigned `sizeof`
division and confirm truncation toward zero for signed negative division.

The function reads complete aligned 16-bit words from a signed byte length,
accumulates sum and one's-complement sum modulo 65536, then maps `0xffff` to
zero in each output. Odd positive byte lengths discard the final byte; negative
lengths and lengths below two read no input and zero the outputs. Both output
pointers must denote writable aligned words, even when no input is read.
Positive lengths require the corresponding readable word range. There is no
`restrict` promise; separate statements preserve read/write sequencing when
outputs share storage or overlap word-typed input. In particular, the inverse
sum reloads the input after the sum store; it must not use a cached word.

All five real call sites are assembly callers passing r3/r4/r5/r6:

| Caller | Input and signed byte count | Outputs |
|---|---|---|
| `__CARDUpdateFatBlock` | FAT + 4, `0x1ffc` | FAT + 0, FAT + 2 |
| `__CARDUpdateDir` | directory, `0x1ffc` | directory + `0x1ffc`, + `0x1ffe` |
| `__CARDFormatRegionAsync` (ID) | ID, `0x1fc` | ID + `0x1fc`, + `0x1fe` |
| `__CARDFormatRegionAsync` (directory) | directory, `0x1ffc` | directory + `0x1ffc`, + `0x1ffe` |
| `__CARDFormatRegionAsync` (FAT) | FAT + 4, `0x1ffc` | FAT + 0, FAT + 2 |

The two owner call sites remain byte-identical. `CARDDir.c` remains
`NonMatching`: its corrected source is compiled by `all_source`, while the
original split object remains selected for the full link. Its source-built
object is raw-identical before and after the declaration correction and in
all mutation/restoration phases. No new caller is converted or counted.

## Matching and compiler control

Three bounded source hypotheses were tested:

1. Reference-adapted signed-divisor C: 480 bytes, not exact.
2. Same body with local `#pragma peephole on`: 432 bytes, exact owner.
3. Separate sequenced output initialization: still 432 bytes, exact owner;
   this is the final source.

A scratch explicit-peephole-off control reproduces the first hypothesis's
allocated bytes, symbols and relocations. The pragma repairs GC/1.2.5n's
observable inline-assembly peephole-state leakage immediately before the final
C function; it does not change the command line or other functions.

For the final source, the source-built baseline, candidate and restoration
owner objects are raw-identical. All 19 function records, allocated section
bytes/type/flags/alignment, normalized symbols and all 110 relocation tuples
are equal. The target has zero relocations; no non-target function changes.
The retail-split object is not raw-identical. It has the same allocated data,
functions and normalized symbols; normalizing only SDA21 relocation offsets
from instruction-start versus halfword representation makes its relocation
records equal as well. No such normalization is needed between compiled states.

## Current-main build and linked-source control

Receiving base: `2232987a0018a9403c0bf33b3624838720dbeab0`.
The contribution was rebased after the upstream CARDDir private-header cleanup.
The resolution preserves that include, removed placeholders and typed assembly
signatures; only the remaining checksum declaration changes in `CARDDir.c`.
The checksum implementation itself is unchanged. The build, caller-object and
linked behavioral checks below were repeated on this base, not inferred from
the earlier `41b5520b3dd134f5b01dacb646297b62fd7261c4` results.
Fresh configuration and `ninja -v -j4 all_source build/GFZE01/main.dol` passed
for the baseline, final candidate and restoration. The link graph selects the
source-built `CARDBlock.o`, not the original owner. Each candidate/mutant/restore
forced that owner to rebuild. All positive DOLs have retail SHA-1
`421c88106697d3275a3fc26fb7a01bf6d816b271`.

The actual C mutation changes only `*checksum += *p;` to `*checksum -= *p;`.
It compiles and links successfully, preserves target size and relocations,
and changes only the checksum function's bytes. The separate retail-hash gate
fails: mutant DOL SHA-1 `90b67c3929246cec65f780550ab6444559096f61`.
For a disjoint single input word of value 2, addition yields 2 whereas subtraction
yields 65534, so this is a meaningful arithmetic change, not an inert boundary
edit. Restoring the exact C source restores the byte-identical object and
retail DOL. There is no retained mutation marker.

Fresh repository unittest discovery passes all 11 tests in baseline, candidate,
and restored states.

## Linked behavioral verification

The final candidate and exact-restoration DOLs each pass 198,474 linked checksum
executions, for 396,948 positive cases. Coverage includes every 16-bit single-word
value at byte lengths two and three, every complementary two-word pair, bounded
loop/remainder and block sizes, signed nonpositive lengths (including null-input
no-read cases), deterministic random data, and selected aligned alias layouts.
The actual callers' 508-byte and 8,188-byte sizes and before/after adjacent output
geometries are represented. These are checksum invocations using caller-derived
layouts, not executions of the hardware-facing callers themselves.

Disjoint-input results use an independent algebraic checksum oracle. Aliased
storage uses an ordered memory oracle preserving every observed load/store
sequence. Tests check permitted input reads and output writes, guarded memory,
stack, nonvolatile GPRs and nonvolatile CR fields. They do not claim arbitrary
length/alias exhaustiveness, FPR preservation, instruction-fetch bounds, or
hardware-backed card I/O.

The actual rebuilt source mutant fails both a one-word witness and an eight-word
unrolled-loop witness that pass on the unchanged baseline. Its 18 nonpositive
control cases still pass. All source/object/link restoration checks pass.
Separately, six in-memory diagnostics reject initialization, length,
normalization, extra-read, extra-write and nonvolatile-register faults; optimized
Python is rejected. Those diagnostics test harness sensitivity, not source
participation. Independent final review remains a separate publication gate.

Private build artifacts, command logs, compiler binaries and game assets are
not included in this contribution.
