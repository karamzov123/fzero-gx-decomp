# MetroTRK `.init` blob map — `init_trk_800035E4` (0x800035E4–0x80005518, 0x1F34 bytes)

Historical notes below include a superseded address interpretation. The
[GFZE01 `.init` TU map](../../state/tumap/GFZE01_main_init.json) records the
actual table at `0x800035E4`, the reset vector at `0x800036E4`, and its target
at `0x80005518`, verified against the GFZE01 extracted objects.

Blob is the **entire MetroTRK NUB interrupt-vector table** (`gTRKInterruptVectorTable` …
`gTRKInterruptVectorTableEnd`) plus two small trailing init functions. It corresponds 1:1 to
doldecomp/melee `src/MetroTRK/__exception.s` (verified instruction-by-instruction: same
`Metrowerks Target Resident Kernel for PowerPC` banner at offset +0x00, same per-vector
`trk_redirect`/`trk_tlb_redirect` stubs, same padding). Note: unlike melee (banner first,
handlers in place), GX's link places each handler's code *after* the reserved 0x100-byte slot —
the layout below reflects the actual bytes.

## Layout (VA = file VA; blob-relative offset = VA − 0x800035E4)

| VA range | Contents |
|---|---|
| `800035E4–80003AC8` | Pre-table code region (see "Functions before the table") |
| `80003AC8` (+0x000) | `gTRKInterruptVectorTable` start: string `"Metrowerks Target Resident Kernel for PowerPC"` + zero pad to +0x100 |
| `80003BC8` (+0x100) | System Reset vector slot: only word present is `b __TRK_reset` → `0x800059FC` |
| `80003CC8` (+0x200) | Machine Check handler (`trk_redirect 0x200`) |
| `80003DC8` (+0x300) | DSI handler (`trk_redirect 0x300`) |
| `80003EC8` (+0x400) | ISI handler |
| `80003FC8` (+0x500) | External Interrupt handler |
| `800040C8` (+0x600) | Alignment handler |
| `800041C8` (+0x700) | Program handler |
| `800042C8` (+0x800) | FPU Unavailable handler |
| `800043C8` (+0x900) | Decrementer handler |
| `800046C8` (+0xC00) | System Call handler |
| `800047C8` (+0xD00) | Trace handler |
| `800048C8` (+0xE00) | FP Assist handler |
| `800049E8` (+0xF00/0xF20) | Performance-Monitor / AltiVec-Unavailable pair (`38600F20`, then branch to `80004A1C` = `38600F00`) |
| `80004AC8` (+0x1000) | 603e Instruction TLB Miss (`trk_tlb_redirect 0x1000`; includes SRR0 icbi/dcbi prologue) |
| `80004BC8` (+0x1100) | Data Load TLB Miss |
| `80004CC8` (+0x1200) | Data Store TLB Miss |
| `80004DC8` (+0x1300) | Instruction Address Breakpoint |
| `80004EC8` (+0x1400) | System Management Interrupt |
| `800050C8` (+0x1600) | Denorm Detect / Java Mode |
| `800051C8` (+0x1700) | Thermal Management Interrupt |
| `800056C8` (+0x1C00) | Data Breakpoint |
| `800057C8` (+0x1D00) | Instruction Breakpoint |
| `800058C8` (+0x1E00) | Peripheral Breakpoint |
| `800059C8` (+0x1F00) | Non-Maskable Development Port |
| `800059F8` (+0x1F14) | **`gTRKInterruptVectorTableEnd`** |
| `800059FC–80005A24` | `__TRK_reset`: `bl memset(r3=0,r4=0,r5=0)` @`80005A14` → `0x8000F490` (memset), then falls through to reset loop |
| `80005A28–80005A90` | `_rom_copy_info` (12-byte records ×8: dst,dst,len pairs for .init/.text/.ctors/.dtors/.rodata/.data/.sdata/.sdata2 — matches words at 80005A28+) |
| `80005A94–80005AAC` | `_bss_init_info` (.bss/.sbss/.sbss2 ranges) |

## Every trk_redirect stub targets
`lis r3, 0x8008 ; ori r3, r3, 0xB12C` ⇒ **TRKInterruptHandler = 0x8008B12C** (confirmed by ELF symtab, size 404). All handlers end `rfi` (0x4C000064).

## Functions before the table (0x800035E4–0x80003AC8)
These sit ahead of the symbol but are part of the same coarse block; bl targets resolved:

| VA | Candidate identity | Evidence |
|---|---|---|
| ~`800035E4–80003794` | `__init_registers`-adjacent init glue? Actually: **TRK copy/init helpers** — `bl 0x8000F490` (memset), `bl 0x80015F1C`, `bl 0x8000A894`, `bl 0x80011D6C`, self-referential `bl 0x800035E4`, `bl 0x8008D42C` (**TRKUARTInterruptHandler**, symtab-confirmed) at `8000377C` | calls into metrotrk text units |
| `80003794–80003824` | small func called from `80003638`; ends `b 0x8007A544` (exit path) | |
| `80003824–800038E4` | func called from `80003650`; contains `bl 0x80005AC4` (past-blob, _rom_copy_info consumer = `__init_data`-style copier) and `bl 0x80003A24` | |
| `800038E4–80003908` | func from `8000363C` |
| `80003908–80003A24` | func from `80003884`; calls `0x8000B038`, `0x8000A5E0`, `0x8000BF9C` |
| `80003A24–80003AB8` | leaf pair with byte-copy loop ending `80003AC4` (`blr`); likely `TRK_memcpy`-style inline or `__copy_rom_section` |

⚠️ Caveat: this pre-table region is *not* part of `gTRKInterruptVectorTable` proper — it is
`.init` section neighbors (MW CRT init glue) that the coarse unit swallowed. The named symbol
`pad_00_800035E4_init` (size 7988 = 0x1F34... actually covers whole blob) is a placeholder.

## String anchors
- `80003AC8`: `"Metrowerks Target Resident Kernel for PowerPC"` — pins `gTRKInterruptVectorTable`.
- No other real strings exist in the blob. The strings `"MetroTRK for GAMECUBE v2.0"`, `"TRK_Packet_Header"`, `"TRK_CMD_ReadMemory"` asked about are **not present** in this .init range (they live elsewhere / not in GX build).
- Garbage 4-char matches at `8000380C`, `8000398E`, `800039AE`, `80004A1B` etc. are instruction bytes, not data.

## Cross-reference to known sources
- Source correspondence: doldecomp/melee `src/MetroTRK/__exception.s` (exact structural match for the table) and `targimpl.c::TRKInterruptHandler` (= 0x8008B12C here).
- Repo already-matched units confirm family: `InitMetroTRK` 0x8008CEB0, `TRKInitializeTarget` 0x8008CFDC, `TRK_saved_exceptionID`/`gTRKState` 0x801A50BC, `gTRKCPUState` 0x801A5160, `gTRKSaveState` 0x801A5590.

## Suggested split for decomp
1. `__exception.s` equivalent: symbol `gTRKInterruptVectorTable` at **0x80003AC8**, end `gTRKInterruptVectorTableEnd` at **0x800059FC** (size 0x1F34−0x14 tail… exactly 0x1F14+4).
2. `__TRK_reset` @ 0x800059FC.
3. `_rom_copy_info` @ 0x80005A28, `_bss_init_info` @ 0x80005A94.
4. Remaining 0x800035E4–0x80003AC8: MW runtime init glue, split on bl-target boundaries above.
