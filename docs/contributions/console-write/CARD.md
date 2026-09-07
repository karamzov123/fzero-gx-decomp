# Console write callback

Base: `45bda14af57c39d20c989888d84b1c36e8adb9a2` (GFZE01).

## Change and provenance

- `fn_80085814` (`0x80085814`, 208 bytes): replace its assembly body with C
  in the existing `src/dolphin/msl/msl_80083E84.c` owner.
- `init_uart_console`: inlined helper, no new storage or standalone function.
- Provenance: `marioparty4:src/MSL_C.PPCEABI.bare.H/uart_console_io.c:16`
  (callback) and `:3` (helper), at
  [`147b165a83187ac9e6cfdc3bf52f2e73437b1ffd`](https://github.com/mariopartyrd/marioparty4/tree/147b165a83187ac9e6cfdc3bf52f2e73437b1ffd).
  The same revision's `src/dolphin/exi/EXIUart.c`,
  `src/TRK_MINNOW_DOLPHIN/mslsupp.c`, `src/dolphin/os/OS.c` and associated
  ABI headers were also consulted. No tracked license file or README license
  grant was found; this is not a clean-room or license-clearance claim.

- Started from the contributor's previously matched console-write reconstruction;
  credited the consulted public structure conservatively. GX additionally bypasses
  UART when console-type bit `0x20000000` is set. UART success still calls TRK;
  TRK's return status is ignored, but its count and buffer effects are preserved.

## ABI and ownership

The callback and TRK declaration use the receiver's four-argument
`int(unsigned int, char*, unsigned int*, unsigned int)` convention, as called
by `__flush_buffer`; no donor idle-function-pointer conversion is retained.
`WriteUARTN` retains the receiver's `int(void*, long)` signature and writable
buffer. `InitializeUART` is declared/defined as `int(unsigned long)` (the incoming
baud argument is ignored by its unchanged assembly body). `OSGetConsoleType`
returns `unsigned long`, consistently with the existing EXI declaration.
Only signatures change in `OS.c`, `EXIBios.c`, and MetroTRK `main.c`; their
assembly bodies are unchanged. No compiler flags, splits, headers or linkage
settings change. `lbl_801A6DE8` remains an external four-byte `.sbss` object
owned by `coarse/sbss_801A66A0.c`.

## Verification

Fresh baseline/candidate/restoration builds on this base preserve retail DOL
SHA-1 `421c88106697d3275a3fc26fb7a01bf6d816b271`.
All 208 target bytes and six relocations match the separately extracted retail
object. Complete allocated sections, symbol records, function bytes and
relocations agree across all six rebuilt objects: the four changed units plus
`stdio_8007A060` and `printf`. Only MSL nonallocated metadata/symbol ordering
changes; the other five raw objects are identical.

`ninja all_source build/GFZE01/main.dol` and all eight repository tests pass.
Changing the UART-error return from `1` to `2` builds successfully and changes
the DOL hash; restoring the final source restores all six objects and the retail
hash. Fresh logs, source hashes, ELF snapshots, mutant source/object/DOL and
restoration receipts are retained privately.

Baseline and candidate linked PPC code each pass 432 emulated cases with mocked
OS/UART/TRK boundaries, checking calls, arguments, errors, memory effects and
preserved registers. The source mutant fails this harness. This is not hardware
testing.
