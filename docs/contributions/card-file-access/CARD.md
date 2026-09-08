# CARD file access — GFZE01

## Scope and provenance

Tested receiving base: `6b93eeb2921a6fe3f4c4c0d7fdd4a4b1dc73dfb3`.
This is a frozen-base result, not a claim to have tested latest upstream.
The five routines are public-source adaptations from
[doldecomp/dolsdk2001, `src/card/CARDOpen.c`](https://github.com/doldecomp/dolsdk2001/blob/eb1234c45e6df75757c652c835507ca89674f9a8/src/card/CARDOpen.c),
pin `eb1234c45e6df75757c652c835507ca89674f9a8`, not original authorship.
Exact tracked path, blob and line starts were verified with `git ls-tree` and
`git show`; reference blob is `fc67caa30fcb1f29aff3730523c4c805c5d7c0a5`.

| Routine | Reference line | Retail address | Bytes |
|---|---:|---:|---:|
| `__CARDCompareFileName` | 6 | `0x8002E954` | 104 |
| `__CARDAccess` | 25 | `0x8002E9BC` | 152 |
| `__CARDGetFileNo` | 45 | `0x8002EA84` | 336 |
| `CARDOpen` | 106 | `0x8002EBD4` | 376 |
| `CARDClose` | 138 | `0x8002ED4C` | 84 |

Total: **1,052 bytes** converted from assembly. No new helper, symbol, storage
or split is introduced. No `goto`, `volatile`, or inline assembly in these five
bodies. Reference debug assertions are omitted for the receiving release build.

## Receiving adaptations and code generation

- Access takes the receiving `CARDControl*` and reads its disk ID at `0x10C`,
  rather than importing the SDK global disk-ID model. The wildcard is the
  address of existing `lbl_80177B80`, not an equal-content substitute.
- The receiving symbol named `strncmp` is the fixed-count unsigned-byte assembly
  comparator in `src/dolphin/msl/multibyte.c:265`, not standard NUL-aware
  `__msl_strncmp` in `tail_8008279C.c:1519`. Its arguments occupy r3/r4/r5 and
  it returns -1/0/+1. The target declaration uses `unsigned long` count, agreeing
  with this tree's CARD `u32` and CARDReadWrite declaration. The actual owner is
  an assembly placeholder, so this is a machine-ABI contract, not compatibility
  with a nonexistent typed C definition. `unsigned int` is a distinct C type;
  an actual-TU negative redeclaration probe rejects it.
- Compare retains signed-char lowering, the bounded 32-byte loop, and the final
  filename[32] terminator read. Access still compares bytes after embedded NUL.
- GetFileNo's attachment read converts the control pointer to its genuine first
  `s32 attached` member. The original padding-based draft was superseded by the
  canonical field exposure below. Its redundant local Access result was removed:
  direct comparison preserves semantics and allows the retail asymmetric inline
  graph without a duplicate helper or inline-depth override.
- GetFileNo embeds Access and Compare. Open embeds GetFileNo and Access but calls
  Compare. Open validates `5 <= startBlock < cBlock`, leaves length untouched,
  writes chan=-1 before acquisition, and returns the actual release call result.
- Local push/peephole-on/pop scopes restore compiler state after legacy assembly.
  The inherited `__CARDIsPublic` brace body is unchanged; the same bounded state
  repair reduces its previously nonmatching 52-byte lowering to retail 48 bytes.
  This is **not** a sixth C conversion. `configure.py` changes only CARDDir's
  matching classification and its explanatory comment so the source object links.
  GC/1.2.5n and the generated compiler flags remain unchanged.

## Approved type/signature repairs

These are original receiving-tree repairs against the tested base, not imported
SDK record definitions. Binary layout and primitive typedefs are unchanged;
canonical C record declarations do change. Adjacent provenance records the base.

- `include/dolphin/card_private.h`: expose `s32 attached@0`, retaining eight
  leading padding bytes; expose `u16 freeNo@0xBC` and `startBlock@0xBE`, retaining
  four padding bytes at `0xB8`. Control size stays `0x110`, fileInfo@`0xC0`,
  callback@`0xD0`, diskID@`0x10C`; shared public `card.h` is unchanged.
- `CARDDelete.c`: replace incompatible duplicate complete control/directory
  records with the canonical private header; correct GetFileNo declaration and
  remove redundant/conflicting declarations. Every function body is unchanged.
- `CARDStat.c`: use canonical public directory and file-scope incomplete control
  tag; correct Access declaration. Function bodies are unchanged.
- `CARDRename.c`: alias canonical `CARDDir` as `CARDEntry`; correct Access/Compare
  declarations. The only expression change in `CARDRenameAsync` is
  `strncpy((char*)ent->fileName, ...)`, viewing canonical byte storage as characters.
- `CARDReadWrite.c`: add file-scope canonical forward tags and correct Access
  declaration. The only expression change in `CARDFastOpen` casts the selected
  byte-addressed directory record to `struct CARDDir*` at that call.

Get/PutControlBlock (`CARDMount.c:195/252`) and GetDirBlock (`CARDBlock.c:1557`)
remain assembly placeholders with independently inspected register contracts;
typed caller declarations do not convert their definitions. Storage remains the
existing generated assembly: `__CARDBlock` 0x220 bytes and wildcard 0x20 bytes.
This contribution does not claim repository-wide ISO C consistency: inherited
`__CARDIsOpened`, other IsPublic/callback placeholders and legacy string-function
prototype discrepancies outside the selected boundaries remain out of scope.

## Verification

Private isolated evidence is retained under `verification/final-evidence`; no
retail binaries or large proof tree are added to this contribution.

- Fresh frozen-base full `all_source` + DOL build, then clean source-object
  candidate rebuild with CARDDir selected for the final link. Candidate and each
  restoration produce retail SHA1 `421c88106697d3275a3fc26fb7a01bf6d816b271`.
- All 26 owner functions and allocated section contents match the extracted
  retail owner. All 211 relocation tuples match after normalizing only SDA21
  relocation site convention (type 109, instruction start versus +2 halfword).
  **Raw retail/candidate object bytes are not identical.** Raw candidate and
  restored objects are identical. No other relocation difference is waived.
- The fresh baseline source owner differs because inherited IsPublic was not
  matching and CARDDir was `NonMatching`; baseline retail hash alone was not
  accepted as source-linkage evidence. The other owner functions do not regress.
- 196 source-object hashes checked. Only CARDDir differs baseline to candidate;
  all four repaired consumer objects are raw-identical. Every restoration
  reproduces the complete candidate object-hash map.
- Five separately compiled and linked meaningful mutants fail retail SHA1:
  Compare loop bound (also changes inlined GetFileNo); Access denial result
  (also GetFileNo/Open); detached lookup result (also Open); Open offset store;
  Close channel store. Function sizes, symbols and relocation tuples remain
  fixed, and only the named target/inline consumers change. Each source is
  restored and rebuilt immediately, preserving source/object/DOL evidence.
- Repository tests pass on baseline, candidate and final restoration: 11 each.
- Complete actual-TU MWCC probes: five positives (owner and four consumers),
  fifteen real failing type/layout controls. Probes append to exact source
  snapshots, use receiving compiler/flags, and bind source, command, dependencies,
  logs and output objects. Width equality alone is not a type-compatibility test.

- Independent linked-PPC oracle executed read-only on all 12 real build phases:
  baseline, candidate and five restorations each pass 441 scenarios / 448 target
  invocations. All five source mutants are rejected (Compare 22, Access 7,
  GetFileNo 5, Open 159, Close 21 failing scenarios). Open's rejected integration
  stages stop early, so that mutant has 441 invocations; all other phases have
  448. Total: 5,292 scenarios / 5,369 invocations. The harness's separately bound
  19 meaningful guard controls were verified as complete; they are not substitutes
  for the five compiled mutants. Full reports and ordered transcripts are in
  `verification/linked-phases-complete/`.
- Oracle executes the actual linked GetDirBlock and fixed-count strncmp helpers;
  only acquisition/release system boundaries are stubbed. It checks ordered data
  reads/writes/calls, stack frames/backchains/LR/canaries, nonvolatile GPRs and
  CR2-4. It does not claim FPR preservation, exhaustive aliasing or CARD hardware.

Final independent acceptance remains the parent's separate gate. No commit or
publication performed by the implementation worker.
