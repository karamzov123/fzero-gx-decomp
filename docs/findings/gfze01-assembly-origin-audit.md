# GFZE01 Assembly Source-Origin Audit (`main_rel`, `movie_module`, `main`)

Audited against GFZE01 (`34dd6166ac74ea55679a43a13059758790391387`) and the 184 `needs-origin-review` entries in [`docs/US_ASSEMBLY_INVENTORY.csv`](../US_ASSEMBLY_INVENTORY.csv). All 184 entries now have verified source-origin classifications (**175 `evidenced-assembly`**, **9 `mixed-review`**, **0 `needs-origin-review`**), alongside the 2 previously audited `blocked` C-suspect units (`fn_1_4B6D4`, `fn_1_4B788`), 5 `config/original_assembly.json` units, and 1 prior `mixed-review` unit (`__OSPSInit`).

| Module | `needs-origin-review` audited | Classified `evidenced-assembly` | Classified `mixed-review` |
| --- | ---: | ---: | ---: |
| `main_rel` | 1 | 1 | 0 |
| `movie_module` | 7 | 4 | 3 |
| `main` (DOL) | 176 | 170 | 6 |
| **Total audited** | **184** | **175** | **9** |

---

## 1. `main_rel` (1 audited -> 1 `evidenced-assembly`) {#main-rel-curve}

* **`fn_1_9DFB8` (404 B) -> `evidenced-assembly`**: Closed by four independent proofs documented in [`docs/findings/gfze01-main-rel-assembly-frontier.md`](gfze01-main-rel-assembly-frontier.md#curve-evaluator-fn_1_9dfb8-origin-audit-evidenced-assembly): six `bCC+` static branch prediction hints (`0/7,159` C functions in GFZE01), two self-XOR register zeroings (`xor r9, r9, r9` at `0x9DFF0`, `xor r7, r7, r7` at `0x9E130`), locked-cache `0xE000019C` constant reads via `lis r6, 0xe000; lfs f9, 0x19c(r6)` with zero `.rodata` relocations, and an unreachable dead `b .L_0009E05C` retained after `b .L_0009E074`.

---

## 2. `movie_module` (7 audited -> 4 `evidenced-assembly`, 3 `mixed-review`)

### 2A. GQR setup/save/restore cohort (4 -> `evidenced-assembly`) {#movie-gqr}

Symbols: `fn_12_52E8` (16 B), `fn_12_12564` (40 B), `fn_12_33664` (52 B), `fn_12_33698` (52 B).

* All four are frameless leaves touching PowerPC Gekko graphics quantization registers (`GQR2`–`GQR7`, SPRs `0x392`–`0x397`) via `mtspr`/`mfspr`:
  * `fn_12_52E8` sets `GQR7` (`li r0, 7; oris r0, r0, 7; mtspr GQR7, r0; blr`).
  * `fn_12_12564` sets `GQR4`, `GQR3`, and `GQR5` (`li r0, LO; oris r0, r0, HI; mtspr GQRn, r0`).
  * `fn_12_33664` / `fn_12_33698` bulk-restore and bulk-save `GQR2..GQR7` at `r3 + 0x08..0x1C` in one unframed sweep.
* Stock MWCC `GC/1.3.2` has no `__mtspr`/`__mfspr` C builtins (compiling them emits external `bl __mtspr` / `bl __mfspr` calls), and `fn_12_52E8` / `fn_12_12564` materialize 32-bit constants using `li LO; oris HI`, the reverse of MWCC's `lis HI; ori/addi LO` idiom. Original PowerPC assembly / CodeWarrior `asm` functions under `docs/ASM_POLICY.md`.

### 2B. CRI Sofdec / M2A / CFT middleware cohort (3 -> `mixed-review`) {#movie-middleware}

Symbols: `fn_12_D0B8` (884 B), `fn_12_3CB74` (1,488 B), `fn_12_3D144` (1,248 B).

* **`fn_12_D0B8`** (`M2A` hardware initialization, companion to `fn_12_D038.c`): Standard MWCC `-use_lmw_stmw on` C prologue/epilogue (`stwu r1, -0x30(r1); mflr r0; stw r0, 0x34(r1); stmw r27, 0x1c(r1)`) and normal C calls (`bl DCT_FsriInit`, `bl DCT_FsriInitScaleTbl` — the historical `fn_12_5674` relocation/symbol issue in [`docs/findings/295-fn_12_5674-is-dct-fsriinit.md`](295-fn_12_5674-is-dct-fsriinit.md) is already resolved on `main`), wrapping an inline `asm` block that reads `HID2` (`mfspr r0, HID2`), initializes locked cache, and runs a 7x-unrolled `dcbi; dcbz_l` loop over locked cache.
* **`fn_12_3CB74`** and **`fn_12_3D144`** (CRI Color Format Transform YCC420-to-ARGB8888 Gekko kernels, siblings of `fn_12_3C8CC.c` and `fn_12_3D624.c`): Both emit standard MWCC paired-single C prologues (`stwu r1, -0x150(r1)` / `-0x120(r1)` saving `stfd` + `psq_st` for `f18..f31` / `f21..f31`) and C outer loops wrapping inline `asm` blocks that configure `GQR4` (`mtspr GQR4, r0`), zero output cache lines (`dcbz`), and convert macroblock tiles with paired-single instructions (`ps_add`, `ps_merge00`, `ps_merge10`, `ps_merge11`, `psq_st ..., qr4`). Both belong to `mixed-review` (recoverable natural C enclosing evidenced inline `asm` kernels or retained under scoped mixed-source policy).

---

## 3. `main` (DOL, 176 audited -> 170 `evidenced-assembly`, 6 `mixed-review`)

### 3A. Mixed C + inline assembly cohort (6 -> `mixed-review`) {#main-mixed-review}

* **`PPCMffpscr` (32 B), `PPCMtfpscr` (40 B)** (`base/PPCArch.c`): Allocate 24-byte / 32-byte MWCC C stack frames (`stwu r1, -0x18(r1)` / `-0x20(r1)`), save `f31`, convert between `u32` and `f64` through a stack union (`stw`/`lwz`), and wrap single-instruction inline `asm` (`mffs f31` / `mtfsf 255, f31`).
* **`fn_800071B8` (596 B), `fn_80007664` (156 B)** (`os/` MMU/PTE routines): Standard MWCC C frames/control flow (`fn_800071B8`: `stwu r1, -0x10(r1); mflr r0; stw r0, 0x14(r1); stw r31/r30`, calls `OSGetArenaHi`; `fn_80007664`: PTE bitfield updates with `rlwimi`/`extrwi`) wrapping inline MMU/cache instructions.
* **`fn_8003AB08` (1,288 B), `fn_8003B010` (1,580 B)** (THP video decoder 2D IDCT routines): Compiled C prologues (`mflr r0; lis r4, lbl_801788C0@ha; stw r0, 0x4(r1); stwu r1, -0x58/-0x60(r1)`, saving `f14..f31` and GPRs) and C 1D IDCT butterfly math wrapping inline paired-single `psq_stu`/`psq_stux` stores.

### 3B. Evidenced original assembly families in `main` (170 -> `evidenced-assembly`)

1. **Dolphin SDK `base/PPCArch.c` SPR, syscall & FPSCR leaves (24)** {#ppcarch-leaves}:
   `PPCHalt`, `PPCMfhid0`, `PPCMfhid2`, `PPCMfl2cr`, `PPCMfmsr`, `PPCMtdec`, `PPCMthid2`, `PPCMtl2cr`, `PPCMtmmcr0`, `PPCMtmmcr1`, `PPCMtmsr`, `PPCMtpmc1`, `PPCMtpmc2`, `PPCMtpmc3`, `PPCMtpmc4`, `PPCMtwpar`, `PPCSetFpNonIEEEMode`, `fn_80009FD4` (`mtspr HID0, r3`), `fn_80009FF4` (`sc; blr`), `fn_8000A020..fn_8000A050` (`mfspr r3, PMC1..PMC4`), `fn_8000A0B8` (`sync; mfspr r3, WPAR; blr`). Frameless single-SPR / `sc` / `mtfsb1` / `sync` leaves implemented as SDK `asm` functions.
2. **Dolphin SDK `os/OSCache.c` cache & DMA leaves (13)** {#oscache-leaves}:
   `DCEnable`, `DCFlushRange`, `DCFlushRangeNoSync`, `DCInvalidateRange`, `DCStoreRange`, `ICEnable`, `ICFlashInvalidate`, `ICInvalidateRange`, `LCDisable`, `LCLoadBlocks`, `LCStoreBlocks`, `__LCEnable`, `fn_8000B8AC` (`mfspr r4, HID2; bgt` LC queue wait). Frameless cache-line (`dcbi`/`dcbf`/`dcbst`/`dcbz`/`dcbt`/`icbi`), `HID2`, `MSR`, and `DMA_U`/`DMA_L` SPR loops.
3. **Dolphin SDK `os/OSContext.c` & `os/OS.c` context/FPU routines (9)** {#oscontext-fpu}:
   `OSInitContext`, `OSLoadContext`, `OSSaveContext`, `OSSaveFPUContext`, `OSSetCurrentContext`, `OSSwitchFPUContext`, `__OSFPRInit`, `__OSLoadFPUContext`, `__OSSaveFPUContext`. Raw ABI context-frame save/restore (`psq_l`/`psq_st`, `lfd`/`stfd`, `stmw`/`lmw`, `mtcrf`, `mfmsr`/`mtmsr`, `rfi` / SPRs) implemented as `asm` functions in the Dolphin SDK.
4. **Dolphin SDK `os/` boot, exception, interrupt, time, reset & MMU assembly routines (22)** {#os-boot-exc-mmu}:
   `Config24MB`, `Config48MB`, `DecrementerExceptionHandler`, `ExternalInterruptHandler`, `OSDisableInterrupts`, `OSEnableInterrupts`, `OSGetTime`, `OSRestoreInterrupts`, `RealMode`, `Reset`, `Run`, `SystemCallVector`, `__DBExceptionDestination`, `__flush_cache`, `__init_hardware`, `__init_registers`, `__start`, `fn_80007654` (`mfsrin`), `fn_80007700` (`tlbie; tlbsync; dcbf`), `fn_800079A0` (`mfsdr1`), `fn_8000BFC0` (`mr r3, r1; blr`), `fn_8003D4C0` (`mfspr r3..r6, 924..927` ECID read). All use privileged SPRs, `msr`, segment registers, TLB ops, raw register conventions (`mr r3, r1`), or exception vectors.
5. **Dolphin SDK `ai/AI.c` stack switcher (1)** {#ai-stack}:
   `__AICallbackStackSwitch` — manipulates `r1` across saved/callback stacks around the AI callback invocation.
6. **Dolphin SDK `mtx/mtx.c` paired-single matrix leaves (3)** {#mtx-ps}:
   `PSMTXIdentity`, `PSMTXQuat`, `PSMTXScale` — frameless `psq_l`/`psq_st`/`ps_merge*`/`ps_mul`/`ps_madd` routines matching the rest of `mtx.c`'s evidenced assembly.
7. **HVQM4 video decoder paired-single leaves (2)** {#hvqm4-ps}:
   `fn_8003BCE4`, `fn_8003BD78` — frameless leaves executing `psq_l` with `qr2` quantization, `ps_sub`, and paired-single stores over macroblocks.
8. **Metrowerks `Runtime.PPCEABI.H.a` helpers (14)** {#cw-runtime}:
   `__cvt_dbl_usll`, `__cvt_fp2unsigned`, `__div2i`, `__div2u`, `__mod2i`, `__mod2u`, `__restore_fpr`, `__restore_gpr`, `__save_fpr`, `__save_gpr`, `__shl2i`, `__shr2i`, `__shr2u`, `fn_80079D74` (64-bit signed-long-long to `double` conversion). Multi-entry register-save helpers and hand-coded 64-bit integer/IEEE-754 conversion routines (`cntlzw`, `subfze`, `addze`, `lis @h; ori @l`).
9. **Metrowerks MetroTRK debugger assembly routines (18)** {#metrotrk}:
   `InitMetroTRK`, `InitMetroTRK_BBA`, `TRKExceptionHandler`, `TRKInterruptHandler`, `TRKInterruptHandlerEnableInterrupts`, `TRKLoadContext`, `TRKRestoreExtended1Block`, `TRKSaveExtended1Block`, `TRKSwapAndGo`, `gTRKInterruptVectorTable`, `fn_8008AFF0` (`dcbst; dcbf; icbi` flush), `fn_8008B0E0` (`mfmsr`), `fn_8008B0E8` (`mtmsr`), `fn_8008B0F0` (real/virtual MSR-toggled `lbzx`/`stbx`), `fn_8008CB20`, `fn_8008CB28`, `fn_8008CB30`, `fn_8008CB38` (`twui r0, 0; blr` trap stubs).
10. **Amusement Vision `mathutil` locked-cache (`0xE0000000`) & paired-single math library (51)** {#av-mathutil}:
    `approx_rsqrt`, `float_return_values`, `fn_8006D830`, `fn_8006E250`, `func_80008378`, `lbl_8006D0B4`..`lbl_8006E1B0` (40 symbols), `mathutil_init`, `mathutil_mtxA_from_quat`, `mathutil_mtxA_rotate_x`, `mathutil_mtxA_rotate_y`, `mathutil_mtxA_rotate_z`, `mathutil_quat_mult`. Operate directly on the locked-cache matrix stack at `0xE0000000` (`GQR0..7` setup in `mathutil_init`), paired singles, `lis @h; ori @l` trig table addressing (`andi.` unused scratch bits), `cr1`/`cr0` multi-entry tail ABI, and `approx_rsqrt`/`float_return_values` non-EABI leaf contracts.
11. **Amusement Vision `gxutil` FIFO/DMA/paired-single routines (5)** {#av-gxutil}:
    `u_gxutil_upload_some_mtx`, `fn_80072558`, `fn_80078538`, `fn_80078884`, `fn_80078944`. Frameless routines driving locked-cache `DMA_U`/`DMA_L` (`0xE0003800`), `0xCC008000` WGPIPE bursts with `psq_l`, `mcrf cr1, cr0`, `dcbt`, and static branch hints (`beq+`).
12. **Hand-written audio DSP/PCM paired-single & `mcrxr` kernels (5)** {#audio-ps}:
    `fn_80023B70`, `fn_80023D00`, `fn_800248D4`, `fn_80024E6C`, `fn_80025004`. Custom hand-written assembly kernels: `fn_80023B70` uses paired-single stereo mixing (`ps_merge00`, `ps_muls0`, `ps_mul`, `ps_sum0`, `stfiwx`); `fn_80023D00` and `fn_800248D4` use a non-MWCC stack save layout storing `f14..f25` / `f14..f20` in ascending order *above* `stmw` GPRs alongside `bne+` hints across `cr0/cr1/cr5/cr6`; `fn_80024E6C` and `fn_80025004` use `addc` + `mcrxr cr0` carry-bit branching and `bne+` hints.
13. **Multi-CR parallel-compare string leaves (2)** {#str-multi-cr}:
    `fn_8006FC1C` (`cmpw` + `cmpwi cr1` + `cmpwi cr5`, `bnelr`) and `fn_8006FC5C` (`cmpwi` + `cmpw cr1` + `cmpwi cr5` + `cmpwi cr6`, `subic.`, `bnelr cr1`). Simultaneous multi-condition-register byte-comparison loops.
14. **Locked-cache / MMU / paired-single timing loop (1)** {#ps-timing}:
    `fn_80005E0C` — frameless 50-iteration outer loop executing `mfibatu r0, 0; ps_sub f0, f0, f0; mfibatu r0, 0; ps_sub f1, f1, f1` and `bne-` raw hint loops with `addis r3, r3, 0x4000` over `lbl_801A66D0@sda21`.
