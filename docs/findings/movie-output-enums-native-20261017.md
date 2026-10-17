# Native movie-output enum conversion landed; three frontiers retained

## Accepted function

`fn_12_35B08`: 620 bytes / 155 instructions, GC/1.3.2 with
`-use_lmw_stmw on`, acceptance commit `05e93d52`.

The canonical source independently rechecks at 100.0%, `matched: true`,
`matched_pool: false`. It is registered `matching`, with a relocation-map
pool dictionary (not boolean `pool: true`), and ledger link state `verified`.
Normal submit queued it, and normal verify accepted it with no rejected unit.

Source, fingerprint, canonical oracle receipt, exact registration, original
readonly-object bounds and fingerprints, all-target gate output, and the three
nonmatching source frontiers are portable in:

`state/repairs/movie-output-enums-native-20261017.json`.

## Why the old 98% frontier was not a one-row spelling problem

The old draft held `lbl_12_rodata_15D0` through a one-field text carrier and
then addressed errors hundreds of bytes beyond that individual owner's
424-byte bound. Its flat enum switches also lost a retail branch stub.
Neither a macro alias nor a pointer-read wrapper establishes native storage.

Recover the actual `.rodata` interval 0x15d0..0x1d88: 1,976 bytes, including
original constants and alignment. All original payloads in this interval
are relocation-free. Emit their bounded native objects in real order, with
first-access layout in `.fzgxpool`, not the requested function. Let MWCC's
native alignment recreate the original gaps; no fake gap objects are needed.

The final 0xc8-byte owner at 0x1cc0 is split at its actual message boundaries:

| Owner-relative range | Bytes | Role |
| --- | ---: | --- |
| 0x00..0x34 | 52 | preceding converter-error storage |
| 0x34..0x54 | 32 | invalid chroma position |
| 0x54..0x78 | 36 | invalid chroma format |
| 0x78..0xa0 | 40 | invalid picture structure |
| 0xa0..0xc8 | 40 | invalid buffer format |

Use canonical `__fzgx_offset_` bindings for the four interior message objects.
The oracle verifies all 23 emitted native objects and the complete initializer
interval before accepting their shared-base relocations.

Native objects alone produce the right 155-word shape but leave 44 aligned
rows different, mostly a permutation of input/output/shared-base registers.
Recover the meaningful enum operations as inline helpers:

- buffer-format normalization, falling back to format 3 after an error;
- picture-structure normalization, default 3;
- chroma-format normalization, default 1;
- chroma-position normalization, reused for both position fields, default 1.

Keep explicit identity mappings for the valid enum cases. They preserve the
actual per-case return/control-flow structure, including the switch branch
stubs; they are not injected padding instructions. Inlining these operations
reproduces the retail register assignment and all 155 instructions. Keep the
existing propagation setting scoped and reset it after the function.

No register pinning, one-field liveness carrier, fake helper, or assembly
escape remains in the accepted source.

## Nonmatching work: no code credit

### fn_12_36208

Recovered the real bounded readonly region and native allocation/reverse-free
helpers, replacing carrier structs and pointer-read wrappers. The leading
three readonly descriptors contain pointer relocations: their raw section
bytes look zero-filled, but they are NOT zero-filled padding. Their native
pointer initializers must reproduce the symbol/addend relocations.

The clean 177-word version remains at 69 differing allocation rows. A bounded
public search's address-local variation reduces that to 60, still nonmatching.
A stronger pointer-domain model (allocator returns, free callback arguments,
work fields and the tracked allocation array) was also measured: same 69 rows.
Ordinary parameter aliases, embedded-state spelling, a standard register hint,
and allocator argument order did not change this assignment. Do not repeat
these families without new allocation evidence. The portable preferred source
uses real pointer types and carries no claimed match or linked-byte credit.

### fn_12_31860

Removed the one-field kind/index carriers and byte-read wrapper. A real
kind-validation helper restores that part of the retail lowering. To reproduce
the separate high-nibble extract and insert, retain the explicit nibble mask:
extracting from an unsigned byte without the mask instead merges the bit
operations differently. The clean 99-word source has 19 remaining allocation
rows. Paired-loop spelling loses counter instructions; calculating the entry
address only on a successful comparison loses the retail address/move pairs.
No match or submission.

### fn_12_2CDD0

The clean native ring/timestamp lookup remains two rows short of exact: the
last wrapped-interval test fuses to `blt found`, whereas retail retains
`bge next; b found`. Structured positive ranges, an inline interval-search
operation, disabling peephole optimization and a negative OR condition were
measured, not assumed. None closes the branch-layout difference. Preserve the
original safe near-match as evidence, not as accepted code.

## Verification

After acceptance and releasing all manual claims:

    ninja build/GFZE01/ok
        rebuilt fn_12_35B08.o, linked movie_module, regenerated RELs
        16 files OK (exit 0)
    build/tools/dtk shasum -q -c config/GFZE01/build.sha1
        16 files OK (exit 0)
    .venv/bin/python tools/fzgx.py lint
        0 finding(s) (exit 0)

The section warnings are the existing shared-storage/primer handling; the
requested function is real `.text` and is not emitted in an ignored primer
section. No runtime/emulator claim is made. The approved publisher additionally
verifies the final committed snapshot before pushing the owner's fork.

Work was inline only, with no subagents. Other workers' source and claims were
not altered. Only this one function earns new code credit in this continuation.
