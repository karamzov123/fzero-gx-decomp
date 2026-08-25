extern void DCStoreRange(void);
extern void DVDGetDriveStatus(void);
extern void DVDInit(void);
extern void GXBegin(void);
extern void OSAllocFromHeap(void);
extern void OSGetArenaHi(void);
extern void OSGetArenaLo(void);
extern void OSGetProgressiveMode(void);
extern void OSGetResetCode(void);
extern void OSGetResetSwitchState(void);
extern void OSGetSaveRegion(void);
extern void OSGetTick(void);
extern void OSInit(void);
extern void OSLink(void);
extern void OSResetSystem(void);
extern void OSSetArenaHi(void);
extern void OSSetArenaLo(void);
extern void OSSetStringTable(void);
extern void OSUnlink(void);
extern void _restgpr_23(void);
extern void _restgpr_24(void);
extern void _restgpr_26(void);
extern void _restgpr_27(void);
extern void _savegpr_23(void);
extern void _savegpr_24(void);
extern void _savegpr_26(void);
extern void _savegpr_27(void);
extern void fn_80005660(void);
extern void main_read_fze_str(void);
extern void fn_800057CC(void);
extern void fn_800057F8(void);
extern void main_load_sample_rel(void);
extern void fn_800058D8(void);
extern void GameMainLoopFrame(void);
extern void fn_80005A08(void);
extern void fn_80005AD0(void);
extern void mmu_user_fn(void);
extern void fn_80005E0C(void);
extern void fn_80005EDC(void);
extern void fn_800060D8(void);
extern void fn_80006334(void);
extern void fn_80006340(void);
extern void dvd_read_sync_wait(void);
extern void fn_800063AC(void);
extern void dvdfs_user_fn(void);
extern void fn_800068F4(void);
extern void fn_80006904(void);
extern void fn_80006914(void);
extern void fn_8000691C(void);
extern void fn_80006AEC(void);
extern void fn_80006AF4(void);
extern void fn_80006AFC(void);
extern void fn_80006B30(void);
extern void fn_80006B4C(void);
extern void fn_80006B70(void);
extern void __va_save_registers(void);
extern void fn_80006C2C(void);
extern void fn_80006C4C(void);
extern void fn_80006CE4(void);
extern void fn_80006D1C(void);
extern void fn_80006DAC(void);
extern void fn_80006DE8(void);
void dvd_read_sync_wait(void);
void fn_8000691C(void);
void fn_80006B4C(void);
extern void fn_80006DFC(void);
extern void fn_80006E10(void);
extern void fn_80006FE0(void);
extern void fn_8000700C(void);
extern void fn_800071B8(void);
extern void fn_8000740C(void);
extern void fn_800074C4(void);
extern void fn_800075AC(void);
extern void OSVirtualToPhysical(void);
extern void fn_80007664(void);
extern void fn_80007700(void);
extern void fn_80007730(void);
extern void fn_800077E0(void);
extern void fn_800079A0(void);
extern void fn_800079C4(void);
extern void fn_80007A00(void);
extern void fn_80007A44(void);
extern void fn_80007AB4(void);
extern void dvd_user_fn(void);
extern void fn_80007C2C(void);
extern void fn_80007C60(void);
extern void fn_80007CDC(void);
extern void fn_80007D58(void);
extern void fn_80007F70(void);
extern void fn_800081C8(void);
extern void fn_80008204(void);
extern void fn_800084E8(void);
extern void fn_800087F4(void);
extern void fn_80008A4C(void);
extern void fn_80008BA8(void);
extern void fn_80008BEC(void);
extern void fn_80008C20(void);
extern void OSInitArenaPoll(void);
extern void OSAllocFromArenaLo(void);
extern void OSPanic(void);
extern void Yay0ReadyFlagUpdate(void);
extern void fn_8000CEBC(void);
extern void fn_8000D1F0(void);
extern void PSMTXMultVecPair(void);
extern void MTXOrtho(void);
extern void DVDConvertPathToEntrynum(void);
extern void fn_800170EC(void);
extern void DVDOpen(void);
extern void DVDCancelSync(void);
extern void fn_80017470(void);
extern void DVDReadPrio(void);
extern void DVDReadAsync(void);
extern void fn_8001AAB4(void);
extern void VIWaitForRetrace(void);
extern void fn_8001BDF0(void);
extern void PADInit(void);
extern void PADRead(void);
extern void PADSetAnalogMode(void);
extern void GXInitTexObj(void);
extern void __GXInitTexMapPreload(void);
extern void __GXSetTexRegion(void);
extern void GXWriteLightReg(void);
extern void GXWriteTextureState(void);
extern void GXWriteLightAttn(void);
extern void GXGetProjectionv(void);
extern void GXLoadMatIdxTripleToXF(void);
extern void fn_8006B188(void);
extern void fn_8006B470(void);
extern void fn_8006CCC8(void);
extern void fn_8006CD40(void);
extern void fn_8006CDFC(void);
extern void fn_8006CE1C(void);
extern void fn_8006CFF8(void);
extern void MTXQuatInterpolate(void);
extern void PSMTXQuat_fromMtx(void);
extern void fn_8006FCB4(void);
extern void fn_8006FD1C(void);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FF8C(void);
extern void fn_8006FFCC(void);
extern void fn_80070158(void);
extern void fn_800702E4(void);
extern void fn_80070538(void);
extern void fn_80070620(void);
extern void fn_8007075C(void);
extern void fn_80070774(void);
extern void fn_80070AC0(void);
extern void GXCompareVecDirty(void);
extern void Snd_SetOutputModeBit0(void);
extern void fn_800721FC(void);
extern void fn_800723F8(void);
extern void GXLoadMtxArray(void);
extern void VIFlush(void);
extern void GXSetMatrixIndexA(void);
extern void GXSetMatrixIndexB(void);
extern void LightCtrl_SetCachedCullMode(void);
extern void LightCtrl_SetCachedColor_1C(void);
extern void LightCtrl_SetCachedPair_6C(void);
extern void LightCtrl_SetCachedByte_EE(void);
extern void ModelSetCachedParam_F0(void);
extern void ModelSetCachedParam_1F0(void);
extern void ModelSetCachedParam_2F0(void);
extern void ModelSetCachedParam_430(void);
extern void fn_80072EDC(void);
extern void ModelSetCachedMaterial_570(void);
extern void GXCachedSetTevSwapTable(void);
extern void ModelSetCachedState_6B0(void);
extern void ModelSetCachedNumTexGens(void);
extern void ModelSetCachedTex_704(void);
extern void ModelCacheMaterialParams(void);
extern void GXIntToFloatCopy(void);
extern void ModelSetCachedState_840(void);
extern void ModelClearCacheSlot_B28(void);
extern void ModelMatchCachedSlot_B20(void);
extern void ModelSetCachedPair5_B28(void);
extern void GXSetNumTexGensCached(void);
extern void GXSetLineWidthCached(void);
extern void GXSetChanAmbColorCached(void);
extern void LightCtrl_SetCachedRec_C30(void);
extern void GXSetTexGenCached(void);
extern void fn_800791A4(void);
extern void fn_800791E8(void);
extern void ModelLoadLcDma(void);
extern void memcpy_fast(void);
extern void __cvt_fp2unsigned(void);
extern void __msl_strncmp(void);
extern void __msl_strcmp(void);
extern void __msl_strcpy(void);
extern void strncpy(void);
extern void strcpy(void);
extern void MathSin(void);
extern void PSVecNormalize3(void);
extern void QuatNormalizeCompare(void);
extern void PSMTXLoadIdentityFused(void);
extern void mtx_gpstack_push(void);
extern void mtx_gpstack_pop(void);
extern void MTXQuatExtract(void);
extern void main(void);
extern void memcpy(void);
extern void memset(void);
extern void strlen(void);
extern unsigned char jumptable_8012208C[52];
extern unsigned char lbl_80095EA0[15];
extern unsigned char lbl_8012205C[48];
extern unsigned char lbl_801220C0[9];
extern unsigned char dvd_open_from_dvd_str[17];
extern unsigned char lbl_801220E0[16];
extern unsigned char dvd_reading_from_dvd_str[20];
extern unsigned char lbl_80122104[156];
extern unsigned char mmu_cant_allocate_pte_str[26];
extern unsigned char lbl_8015B920[32];
extern unsigned char lbl_8015B940[1024];
extern unsigned char lbl_8015BD40[256];

#pragma push
#pragma force_active on

asm void main(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      OSGetResetCode
    lis	r0, -0x8000
    subf	r0, r3, r0
    cntlzw	r0, r0
    rlwinm.	r0, r0, 0x1b, 5, 0x1f
    bc      12, 2, _80005608
    bl      fn_800057F8
_80005608:
    lis	r4, 0x4c00
    lis	r3, -0x8000
    addi	r4, r4, 0x64
    li	r0, 0
    stw	r4, 0x200(r3)
    stw	r4, 0x300(r3)
    stw	r4, 0x400(r3)
    stw	r4, 0x600(r3)
    stw	r4, 0x700(r3)
    stw	r4, 0xc00(r3)
    stw	r4, 0xd00(r3)
    stw	r4, 0x1000(r3)
    stw	r4, 0x1100(r3)
    stw	r4, 0x1200(r3)
    stw	r4, 0x1300(r3)
    stw	r0, -0x7d0c(r13)
    bl      fn_80005660
    bl      GameMainLoopFrame
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80005660(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      OSInit
    bl      DVDInit
    bl      fn_80006AFC
    lis     r3, dvd_read_sync_wait@ha
    addi	r3, r3, dvd_read_sync_wait@l
    bl      fn_80006B30
    bl      fn_8001AAB4
    bl      fn_8006CFF8
    li	r3, 1
    bl      fn_80070158
    li	r3, 1
    bl      fn_8007075C
    li	r3, 1
    bl      fn_8006FF8C
    bl      fn_80070538
    bl      fn_800071B8
    bl      OSGetResetCode
    lis	r0, -0x8000
    subf	r0, r3, r0
    cntlzw	r0, r0
    rlwinm.	r0, r0, 0x1b, 5, 0x1f
    bc      12, 2, _800056dc
    bl      OSGetProgressiveMode
    cmplwi	r3, 0
    bc      12, 2, _800056dc
    li	r3, 1
    bl      fn_80070620
    b       _800056e4
_800056dc:
    li	r3, 0
    bl      fn_80070620
_800056e4:
    li	r3, 1
    lis	r4, 0xc
    li	r5, 1
    bl      fn_80070774
    bl      fn_8006FCB4
    bl      fn_8006CCC8
    lfs	f1, -0x8000(r2)
    bl      fn_8006CD40
    li	r3, 0x20
    li	r4, 1
    bl      fn_80070AC0
    bl      main_read_fze_str
    bl      fn_800057CC
    bl      fn_800058D8
    bl      fn_800063AC
    bl      fn_80005A08
    bl      main_load_sample_rel
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void main_read_fze_str(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lfs	f1, -0x7ffc(r2)
    stw	r0, 0x14(r1)
    lfs	f2, -0x7ff8(r2)
    lwz	r0, -0x7540(r2)
    lfs	f3, -0x7ff4(r2)
    stw	r0, 0xc(r1)
    lfs	f4, -0x7ff0(r2)
    bl      fn_800721FC
    li	r3, 1
    bl      LightCtrl_SetCachedByte_EE
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      LightCtrl_SetCachedColor_1C
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 4
    li	r7, 0
    bl      GXWriteLightReg
    li	r3, 0
    li	r4, 0
    bl      GXWriteLightAttn
    bl      fn_80007A44
    lwz	r0, 0xc(r1)
    addi	r3, r1, 8
    stw	r0, 8(r1)
    bl      fn_8006CDFC
    lfs	f1, -0x7fec(r2)
    bl      fn_8006CE1C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800057CC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r3, 3
    stw	r0, 0x14(r1)
    bl      fn_800702E4
    stw	r3, -0x7cf4(r13)
    bl      fn_800791A4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800057F8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    addi	r3, r1, 0xc
    addi	r4, r1, 8
    bl      OSGetSaveRegion
    lwz	r4, 0xc(r1)
    cmplwi	r4, 0
    bc      12, 2, _80005828
    lwz	r0, 8(r1)
    cmplwi	r0, 0
    bc      4, 2, _8000583c
_80005828:
    addi	r3, r13, -0x7d10
    li	r4, 0
    li	r5, 4
    bl      memset
    b       _80005848
_8000583c:
    addi	r3, r13, -0x7d10
    li	r5, 4
    bl      memcpy
_80005848:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void main_load_sample_rel(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    addi	r3, r13, -0x7ffc
    stw	r0, 0x54(r1)
    addi	r4, r1, 8
    stw	r31, 0x4c(r1)
    bl      DVDOpen
    cmpwi	r3, 0
    bc      12, 2, _800058c4
    lwz	r3, 0x3c(r1)
    li	r4, 0x20
    addi	r0, r3, 0x1f
    rlwinm	r31, r0, 0, 0, 0x1a
    mr	r3, r31
    bl      OSAllocFromArenaLo
    mr	r5, r31
    mr	r31, r3
    addi	r3, r1, 8
    li	r6, 0
    mr	r4, r31
    bl      dvd_read_sync_wait
    cmpwi	r3, 0
    bc      12, 2, _800058bc
    mr	r3, r31
    bl      OSSetStringTable
_800058bc:
    addi	r3, r1, 8
    bl      DVDCancelSync
_800058c4:
    lwz	r0, 0x54(r1)
    lwz	r31, 0x4c(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_800058D8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lbz	r0, -0x7d14(r13)
    cmplwi	r0, 0
    bc      4, 2, _8000590c
    bl      PADInit
    li	r3, 3
    bl      PADSetAnalogMode
    bl      fn_8006B188
    lbz	r3, -0x7d14(r13)
    addi	r0, r3, 1
    stb	r0, -0x7d14(r13)
_8000590c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void GameMainLoopFrame(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    stw	r0, 0x64(r1)
    stw	r31, 0x5c(r1)
    stw	r30, 0x58(r1)
    stw	r29, 0x54(r1)
    stw	r28, 0x50(r1)
    bl      OSGetArenaHi
    mr	r29, r3
    bl      OSGetTick
    clrlwi	r4, r3, 0x1b
    lis     r3, lbl_80095EA0@ha
    addi	r0, r4, 1
    addi	r4, r1, 8
    addi	r3, r3, lbl_80095EA0@l
    slwi	r30, r0, 5
    bl      DVDOpen
    lwz	r3, 0x3c(r1)
    li	r4, 0x20
    addi	r0, r3, 0x1f
    rlwinm	r28, r0, 0, 0, 0x1a
    add	r31, r28, r30
    mr	r3, r31
    bl      OSAllocFromArenaLo
    mr	r30, r3
    mr	r5, r28
    addi	r3, r1, 8
    li	r6, 0
    mr	r4, r30
    bl      dvd_read_sync_wait
    addi	r3, r1, 8
    bl      DVDCancelSync
    mr	r3, r30
    li	r4, 0
    bl      OSLink
    lwz	r12, 0x34(r30)
    mtctr	r12
    bctrl	
    mr	r0, r3
    mr	r3, r30
    mr	r28, r0
    bl      OSUnlink
    mr	r3, r30
    clrlwi	r4, r31, 0x18
    li	r5, 0
    bl      ModelLoadLcDma
    mr	r3, r29
    bl      OSSetArenaHi
    mr	r12, r28
    mtctr	r12
    bctrl	
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    lwz	r30, 0x58(r1)
    lwz	r29, 0x54(r1)
    lwz	r28, 0x50(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr	
}

asm void fn_80005A08(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    bl      OSGetArenaLo
    mr	r29, r3
    bl      OSGetArenaHi
    lis     r4, lbl_8015B920@ha
    mr	r28, r3
    addi	r0, r4, lbl_8015B920@l
    mr	r3, r0
    bl      fn_80005AD0
    li	r30, 0
_80005a48:
    bl      fn_80005E0C
    addi	r30, r30, 1
    cmpwi	r30, 0x14
    bc      12, 0, _80005a48
    lis     r3, lbl_8015B920@ha
    li	r30, 0
    addi	r31, r3, lbl_8015B920@l
_80005a64:
    bl      fn_8006FD1C
    mr	r3, r31
    bl      mmu_user_fn
    bl      fn_80005E0C
    bl      fn_80005E0C
    bl      fn_8006FDEC
    bl      fn_8006FEFC
    addi	r30, r30, 1
    cmpwi	r30, 5
    bc      12, 0, _80005a64
    li	r31, 0
_80005a90:
    bl      fn_80005E0C
    addi	r31, r31, 1
    cmpwi	r31, 0x14
    bc      12, 0, _80005a90
    mr	r3, r29
    bl      OSSetArenaLo
    mr	r3, r28
    bl      OSSetArenaHi
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80005AD0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r5, 0x280
    li	r6, 0x1e0
    stw	r0, 0x14(r1)
    li	r7, 0xe
    li	r8, 0
    li	r9, 0
    lwz	r4, -0x7ff0(r13)
    li	r10, 0
    bl      GXInitTexObj
    bl      __GXInitTexMapPreload
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void mmu_user_fn(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    stw	r0, 0x74(r1)
    stw	r31, 0x6c(r1)
    mr	r31, r3
    lwz	r0, -0x7fe8(r2)
    stw	r0, 0x18(r1)
    bl      fn_800723F8
    li	r3, 0x2200
    bl      GXLoadMtxArray
    bl      fn_800723F8
    li	r3, 0
    bl      GXSetChanAmbColorCached
    li	r3, 1
    bl      GXSetNumTexGensCached
    li	r3, 1
    bl      ModelSetCachedNumTexGens
    li	r3, 0
    bl      ModelSetCachedState_840
    li	r3, 0
    bl      ModelClearCacheSlot_B28
    li	r3, 0
    li	r4, 0
    bl      fn_80072EDC
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl      ModelSetCachedPair5_B28
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0xff
    bl      ModelSetCachedMaterial_570
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      LightCtrl_SetCachedPair_6C
    li	r3, 0
    li	r4, 0xf
    li	r5, 2
    li	r6, 8
    li	r7, 4
    bl      ModelSetCachedParam_F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_2F0
    li	r3, 0
    li	r4, 7
    li	r5, 1
    li	r6, 4
    li	r7, 2
    bl      ModelSetCachedParam_1F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_430
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 0
    li	r8, 2
    li	r9, 2
    bl      LightCtrl_SetCachedRec_C30
    lwz	r0, 0x18(r1)
    addi	r4, r1, 0x14
    li	r3, 1
    stw	r0, 0x14(r1)
    bl      __GXSetTexRegion
    li	r3, 1
    li	r4, 1
    li	r5, 1
    bl      GXSetTexGenCached
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      LightCtrl_SetCachedColor_1C
    lfs	f1, -0x7fe4(r2)
    addi	r4, r1, 0x10
    lfs	f2, -0x7fe0(r2)
    li	r3, 0
    lwz	r0, -0x7538(r2)
    fmr	f3, f1
    fmr	f4, f2
    stw	r0, 0x10(r1)
    bl      GXWriteTextureState
    li	r3, 2
    bl      LightCtrl_SetCachedCullMode
    bl      QuatNormalizeCompare
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      GXLoadMatIdxTripleToXF
    lfs	f1, -0x7fe4(r2)
    addi	r3, r1, 0x1c
    lfs	f2, -0x7fdc(r2)
    fmr	f3, f1
    lfs	f4, -0x7fd8(r2)
    fmr	f5, f1
    lfs	f6, -0x7fd4(r2)
    bl      MTXOrtho
    addi	r3, r1, 0x1c
    li	r4, 1
    bl      GXIntToFloatCopy
    li	r0, 0xff
    addi	r4, r1, 0xc
    stb	r0, 0x18(r1)
    li	r3, 1
    stb	r0, 0x19(r1)
    stb	r0, 0x1a(r1)
    stb	r0, 0x1b(r1)
    lwz	r0, 0x18(r1)
    stw	r0, 0xc(r1)
    bl      __GXSetTexRegion
    li	r0, 0
    addi	r4, r1, 8
    stb	r0, 0x18(r1)
    li	r3, 2
    stb	r0, 0x19(r1)
    stb	r0, 0x1a(r1)
    stb	r0, 0x1b(r1)
    lwz	r0, 0x18(r1)
    stw	r0, 8(r1)
    bl      __GXSetTexRegion
    mr	r3, r31
    li	r4, 0
    bl      ModelCacheMaterialParams
    li	r3, 0x80
    li	r4, 7
    li	r5, 4
    bl      GXBegin
    lfs	f3, -0x7fd0(r2)
    lis	r3, -0x33ff
    lfd	f2, -0x7fc8(r2)
    lfs	f1, -0x7fc0(r2)
    lfd	f0, -0x7fb8(r2)
    fsub	f4, f3, f2
    fadd	f5, f2, f3
    fsub	f2, f1, f0
    frsp	f4, f4
    fadd	f0, f0, f1
    frsp	f3, f2
    stfs	f4, -0x8000(r3)
    frsp	f2, f5
    frsp	f1, f0
    stfs	f3, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    stfs	f4, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    lwz	r31, 0x6c(r1)
    lwz	r0, 0x74(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr	
}

asm void fn_80005E0C(void)
{
    nofralloc
    addi	r3, r13, -0x7cf0
    li	r0, 0x32
    addis	r3, r3, 0x4000
    li	r4, 0
    mtctr	r0
_80005e20:
    mr	r0, r3
    li	r5, 0xc8
_80005e28:
    stw	r5, 0(r3)
    addic.	r5, r5, -1
    bc      4, 2, _80005e28
    li	r5, 0x76c
_80005e38:
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    addic.	r5, r5, -1
    bc      4, 2, _80005e38
    li	r5, 0x76c
_80005e60:
    mfibatu	r0, 0
    ps_sub	f0, f0, f0
    mfibatu	r0, 0
    ps_sub	f1, f1, f1
    addic.	r5, r5, -1
    bc      5, 2, _80005e60
    mr	r0, r3
    li	r5, 0xc8
_80005e80:
    stw	r5, 0(r3)
    addic.	r5, r5, -1
    bc      4, 2, _80005e80
    li	r5, 0x76c
_80005e90:
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    addic.	r5, r5, -1
    bc      4, 2, _80005e90
    li	r5, 0x76c
_80005eb8:
    mfibatu	r0, 0
    ps_sub	f0, f0, f0
    mfibatu	r0, 0
    ps_sub	f1, f1, f1
    addic.	r5, r5, -1
    bc      5, 2, _80005eb8
    addi	r4, r4, 1
    bc      16, 0, _80005e20
    blr	
}

asm void fn_80005EDC(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    li	r3, 0x2200
    stw	r0, 0x64(r1)
    lwz	r0, -0x7fa8(r2)
    stw	r0, 0x14(r1)
    bl      GXLoadMtxArray
    li	r3, 0
    bl      GXSetChanAmbColorCached
    li	r3, 1
    bl      GXSetNumTexGensCached
    li	r3, 1
    bl      ModelSetCachedNumTexGens
    li	r3, 0
    bl      ModelClearCacheSlot_B28
    li	r3, 0
    li	r4, 0
    bl      fn_80072EDC
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl      ModelSetCachedPair5_B28
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0xff
    bl      ModelSetCachedMaterial_570
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      LightCtrl_SetCachedPair_6C
    li	r3, 0
    li	r4, 0xf
    li	r5, 2
    li	r6, 8
    li	r7, 4
    bl      ModelSetCachedParam_F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_2F0
    li	r3, 0
    li	r4, 7
    li	r5, 1
    li	r6, 4
    li	r7, 2
    bl      ModelSetCachedParam_1F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_430
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 0
    li	r8, 2
    li	r9, 2
    bl      LightCtrl_SetCachedRec_C30
    lwz	r0, 0x14(r1)
    addi	r4, r1, 0x10
    li	r3, 1
    stw	r0, 0x10(r1)
    bl      __GXSetTexRegion
    li	r3, 1
    li	r4, 7
    li	r5, 0
    bl      GXSetTexGenCached
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      LightCtrl_SetCachedColor_1C
    lfs	f1, -0x7fa4(r2)
    li	r3, 0
    lfs	f2, -0x7fa0(r2)
    bl      GXCompareVecDirty
    li	r3, 2
    bl      LightCtrl_SetCachedCullMode
    bl      QuatNormalizeCompare
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      GXLoadMatIdxTripleToXF
    lfs	f1, -0x7fa4(r2)
    addi	r3, r1, 0x18
    lfs	f2, -0x7f9c(r2)
    fmr	f3, f1
    lfs	f4, -0x7f98(r2)
    fmr	f5, f1
    lfs	f6, -0x7fa0(r2)
    bl      MTXOrtho
    addi	r3, r1, 0x18
    li	r4, 1
    bl      GXIntToFloatCopy
    li	r0, 0xff
    addi	r4, r1, 0xc
    stb	r0, 0x14(r1)
    li	r3, 1
    stb	r0, 0x15(r1)
    stb	r0, 0x16(r1)
    stb	r0, 0x17(r1)
    lwz	r0, 0x14(r1)
    stw	r0, 0xc(r1)
    bl      __GXSetTexRegion
    li	r0, 0
    addi	r4, r1, 8
    stb	r0, 0x14(r1)
    li	r3, 2
    stb	r0, 0x15(r1)
    stb	r0, 0x16(r1)
    stb	r0, 0x17(r1)
    lwz	r0, 0x14(r1)
    stw	r0, 8(r1)
    bl      __GXSetTexRegion
    lwz	r0, 0x64(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr	
}

asm void fn_800060D8(void)
{
    nofralloc
    stwu	r1, -0xb0(r1)
    mflr	r0
    stw	r0, 0xb4(r1)
    stfd	f31, 0xa0(r1)
    psq_st	f31, 0xa8(r1), 0, 0
    stfd	f30, 0x90(r1)
    psq_st	f30, 0x98(r1), 0, 0
    stfd	f29, 0x80(r1)
    psq_st	f29, 0x88(r1), 0, 0
    stfd	f28, 0x70(r1)
    psq_st	f28, 0x78(r1), 0, 0
    stfd	f27, 0x60(r1)
    psq_st	f27, 0x68(r1), 0, 0
    stfd	f26, 0x50(r1)
    psq_st	f26, 0x58(r1), 0, 0
    stw	r31, 0x4c(r1)
    stw	r30, 0x48(r1)
    fmr	f28, f2
    lfd	f0, -0x7f90(r2)
    fmr	f27, f1
    mr	r30, r3
    fneg	f30, f3
    fadd	f31, f0, f28
    b       _800062e0
_80006138:
    mr	r3, r30
    bl      fn_80006334
    cmpwi	r3, 0
    bc      12, 2, _80006154
    lhz	r4, 0(r30)
    addi	r30, r30, 2
    b       _8000615c
_80006154:
    lbz	r4, 0(r30)
    addi	r30, r30, 1
_8000615c:
    cmplwi	r4, 0x20
    bc      4, 2, _80006174
    lfd	f0, -0x7f88(r2)
    fadd	f27, f27, f0
    frsp	f27, f27
    b       _800062e0
_80006174:
    lha	r0, -0x7cd4(r13)
    lis     r3, lbl_8015B940@ha
    addi	r31, r3, lbl_8015B940@l
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _800061a4
_8000618c:
    lhz	r0, 4(r31)
    cmpw	r0, r4
    bc      4, 2, _8000619c
    b       _800061a8
_8000619c:
    addi	r31, r31, 8
    bc      16, 0, _8000618c
_800061a4:
    li	r31, 0
_800061a8:
    cmplwi	r31, 0
    bc      12, 2, _800062e0
    lwz	r4, 0(r31)
    addi	r3, r1, 8
    li	r5, 0x18
    li	r6, 0x18
    li	r7, 0
    li	r8, 0
    li	r9, 0
    li	r10, 0
    bl      GXInitTexObj
    bl      __GXInitTexMapPreload
    addi	r3, r1, 8
    li	r4, 0
    bl      ModelCacheMaterialParams
    lhz	r4, 6(r31)
    lis	r0, 0x4330
    stw	r0, 0x28(r1)
    frsp	f29, f31
    lfd	f1, -0x7f78(r2)
    li	r3, 0x80
    stw	r4, 0x2c(r1)
    li	r4, 7
    li	r5, 4
    lfd	f0, 0x28(r1)
    fsubs	f0, f0, f1
    fadds	f26, f27, f0
    bl      GXBegin
    lis	r4, -0x33ff
    lis	r0, 0x4330
    stfs	f27, -0x8000(r4)
    lfd	f2, -0x7f78(r2)
    stfs	f28, -0x8000(r4)
    lfd	f1, -0x7f90(r2)
    stfs	f30, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stw	r0, 0x30(r1)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stw	r0, 0x38(r1)
    stfs	f0, -0x8000(r4)
    stfs	f26, -0x8000(r4)
    stfs	f28, -0x8000(r4)
    stfs	f30, -0x8000(r4)
    lhz	r3, 6(r31)
    stw	r0, 0x40(r1)
    stw	r3, 0x34(r1)
    lfd	f0, 0x30(r1)
    fsub	f0, f0, f2
    fdiv	f0, f0, f1
    frsp	f0, f0
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stfs	f0, -0x8000(r4)
    stfs	f26, -0x8000(r4)
    stfs	f29, -0x8000(r4)
    stfs	f30, -0x8000(r4)
    lhz	r0, 6(r31)
    stw	r0, 0x3c(r1)
    lfd	f0, 0x38(r1)
    fsub	f0, f0, f2
    fdiv	f0, f0, f1
    frsp	f0, f0
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f80(r2)
    stfs	f0, -0x8000(r4)
    stfs	f27, -0x8000(r4)
    stfs	f29, -0x8000(r4)
    stfs	f30, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f80(r2)
    stfs	f0, -0x8000(r4)
    lhz	r0, 6(r31)
    stw	r0, 0x44(r1)
    lfd	f0, 0x40(r1)
    fsubs	f0, f0, f2
    fadds	f27, f27, f0
_800062e0:
    lbz	r0, 0(r30)
    cmplwi	r0, 0
    bc      4, 2, _80006138
    psq_l	f31, 0xa8(r1), 0, 0
    lfd	f31, 0xa0(r1)
    psq_l	f30, 0x98(r1), 0, 0
    lfd	f30, 0x90(r1)
    psq_l	f29, 0x88(r1), 0, 0
    lfd	f29, 0x80(r1)
    psq_l	f28, 0x78(r1), 0, 0
    lfd	f28, 0x70(r1)
    psq_l	f27, 0x68(r1), 0, 0
    lfd	f27, 0x60(r1)
    psq_l	f26, 0x58(r1), 0, 0
    lfd	f26, 0x50(r1)
    lwz	r31, 0x4c(r1)
    lwz	r0, 0xb4(r1)
    lwz	r30, 0x48(r1)
    mtlr	r0
    addi	r1, r1, 0xb0
    blr	
}

asm void fn_80006334(void)
{
    nofralloc
    lbz	r0, 0(r3)
    rlwinm	r3, r0, 0x19, 0x1f, 0x1f
    blr	
}

asm void fn_80006340(void)
{
    nofralloc
    cmpwi	r3, -1
    beqlr	
    li	r0, 0
    stb	r0, -0x7ce5(r13)
    blr	
}

asm void dvd_read_sync_wait(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r7, fn_80006340@ha
    li	r8, 2
    stw	r0, 0x14(r1)
    li	r0, 1
    addi	r7, r7, fn_80006340@l
    stw	r31, 0xc(r1)
    mr	r31, r3
    stb	r0, -0x7ce5(r13)
    bl      DVDReadPrio
    b       _80006388
_80006384:
    bl      dvdfs_user_fn
_80006388:
    lbz	r0, -0x7ce5(r13)
    extsb.	r0, r0
    bc      4, 2, _80006384
    lwz	r0, 0x14(r1)
    lwz	r3, 0x34(r31)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800063AC(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    addi	r11, r1, 0x40
    bl      _savegpr_23
    bl      Yay0ReadyFlagUpdate
    clrlwi	r0, r3, 0x10
    cmplwi	r0, 1
    bc      4, 2, _800063e8
    lis     r3, lbl_8012205C@ha
    li	r0, 6
    addi	r3, r3, lbl_8012205C@l
    stw	r0, -0x7cd0(r13)
    stw	r3, -0x7ccc(r13)
    b       _800063fc
_800063e8:
    lis     r3, lbl_8012205C@ha
    li	r0, 6
    addi	r3, r3, lbl_8012205C@l
    stw	r0, -0x7cd0(r13)
    stw	r3, -0x7ccc(r13)
_800063fc:
    bl      OSGetArenaHi
    mr	r31, r3
    bl      Yay0ReadyFlagUpdate
    clrlwi	r0, r3, 0x10
    cmplwi	r0, 1
    bc      4, 2, _80006440
    lis	r3, 9
    li	r4, 0x20
    addi	r3, r3, 0xee4
    bl      OSAllocFromArenaLo
    lis	r5, 5
    mr	r27, r3
    li	r4, 0x20
    addi	r3, r5, -0x3000
    bl      OSAllocFromArenaLo
    mr	r4, r3
    b       _80006464
_80006440:
    lis	r3, 1
    li	r4, 0x20
    addi	r3, r3, 0x120
    bl      OSAllocFromArenaLo
    mr	r27, r3
    li	r3, 0x3000
    li	r4, 0x20
    bl      OSAllocFromArenaLo
    mr	r4, r3
_80006464:
    mr	r3, r27
    bl      fn_8000CEBC
    lwz	r27, -0x7ccc(r13)
    li	r28, 0
    b       _8000655c
_80006478:
    lwz	r29, 0(r27)
    li	r30, 0
    b       _80006548
_80006484:
    lwz	r23, 0(r29)
    lha	r24, -0x7cd4(r13)
    b       _80006530
_80006490:
    rlwinm.	r0, r5, 0, 0x18, 0x18
    mr	r26, r23
    bc      12, 2, _800064a8
    lhz	r5, 0(r23)
    addi	r23, r23, 2
    b       _800064ac
_800064a8:
    addi	r23, r23, 1
_800064ac:
    cmplwi	r5, 0x20
    bc      12, 2, _80006530
    lis     r3, lbl_8015B940@ha
    li	r4, 0
    addi	r25, r3, lbl_8015B940@l
    mtctr	r24
    cmpwi	r24, 0
    bc      4, 1, _800064e4
_800064cc:
    lhz	r0, 4(r25)
    cmplw	r0, r5
    bc      12, 2, _800064e4
    addi	r4, r4, 1
    addi	r25, r25, 8
    bc      16, 0, _800064cc
_800064e4:
    cmpw	r4, r24
    bc      12, 0, _80006530
    sth	r5, 4(r25)
    li	r3, 0x120
    li	r4, 0x20
    bl      OSInitArenaPoll
    stw	r3, 0(r25)
    mr	r3, r26
    addi	r7, r1, 8
    li	r5, 0
    lwz	r4, 0(r25)
    li	r6, 6
    bl      fn_8000D1F0
    lwz	r3, 0(r25)
    li	r4, 0x120
    bl      DCStoreRange
    lwz	r0, 8(r1)
    addi	r24, r24, 1
    sth	r0, 6(r25)
_80006530:
    lbz	r5, 0(r23)
    cmplwi	r5, 0
    bc      4, 2, _80006490
    sth	r24, -0x7cd4(r13)
    addi	r30, r30, 1
    addi	r29, r29, 4
_80006548:
    lwz	r0, 4(r27)
    cmpw	r30, r0
    bc      12, 0, _80006484
    addi	r28, r28, 1
    addi	r27, r27, 8
_8000655c:
    lwz	r0, -0x7cd0(r13)
    cmpw	r28, r0
    bc      12, 0, _80006478
    mr	r3, r31
    bl      OSSetArenaHi
    lis     r3, fn_8000691C@ha
    addi	r3, r3, fn_8000691C@l
    bl      fn_80006914
    li	r3, 0
    bl      fn_80006AEC
    addi	r11, r1, 0x40
    bl      _restgpr_23
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void dvdfs_user_fn(void)
{
    nofralloc
    stwu	r1, -0xa0(r1)
    mflr	r0
    stw	r0, 0xa4(r1)
    stfd	f31, 0x90(r1)
    psq_st	f31, 0x98(r1), 0, 0
    stfd	f30, 0x80(r1)
    psq_st	f30, 0x88(r1), 0, 0
    stfd	f29, 0x70(r1)
    psq_st	f29, 0x78(r1), 0, 0
    stfd	f28, 0x60(r1)
    psq_st	f28, 0x68(r1), 0, 0
    stfd	f27, 0x50(r1)
    psq_st	f27, 0x58(r1), 0, 0
    addi	r11, r1, 0x50
    bl      _savegpr_23
    lwz	r12, -0x7ce4(r13)
    cmplwi	r12, 0
    bc      12, 2, _800065f4
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bc      4, 2, _800068b4
_800065f4:
    li	r24, -1
    li	r25, 0
_800065fc:
    bl      DVDGetDriveStatus
    mr	r31, r3
    cmpwi	r31, -1
    bc      12, 2, _80006628
    lwz	r12, -0x7ce0(r13)
    li	r0, 1
    stb	r0, -0x7ce8(r13)
    mtctr	r12
    bctrl	
    li	r0, 0
    stb	r0, -0x7ce8(r13)
_80006628:
    addi	r0, r31, 1
    cmplwi	r0, 0xc
    bc      12, 1, _80006674
    lis     r3, jumptable_8012208C@ha
    slwi	r0, r0, 2
    addi	r3, r3, jumptable_8012208C@l
    lwzx	r0, r3, r0
    mtctr	r0
    bctr	
    li	r24, 1
    b       _80006688
    li	r24, 0
    b       _80006688
    li	r24, 2
    b       _80006688
    li	r24, 3
    b       _80006688
    li	r24, 4
    b       _80006688
_80006674:
    cmpwi	r25, 0
    bc      12, 2, _80006688
    li	r24, 5
    b       _80006688
    li	r24, -1
_80006688:
    cmpwi	r24, 0
    bc      12, 0, _80006864
    cmpwi	r25, 0
    bc      4, 2, _800066b0
    lwz	r12, -0x7cd8(r13)
    cmplwi	r12, 0
    bc      12, 2, _800066ac
    mtctr	r12
    bctrl	
_800066ac:
    li	r25, 1
_800066b0:
    bl      dvd_user_fn
    cmpwi	r24, 0
    bc      12, 0, _80006858
    bl      fn_80005EDC
    lwz	r3, -0x7ccc(r13)
    slwi	r0, r24, 3
    li	r30, 0
    lfd	f27, -0x7f70(r2)
    lfd	f28, -0x7f68(r2)
    mr	r26, r30
    lfd	f29, -0x7f50(r2)
    add	r29, r3, r0
    lfd	f30, -0x7f60(r2)
    lis	r23, 0x4330
    lfd	f31, -0x7f90(r2)
    b       _8000684c
_800066f0:
    lwz	r3, 0(r29)
    li	r28, 0
    lwzx	r27, r3, r26
    b       _800067c4
_80006700:
    mr	r3, r27
    addi	r4, r13, -0x7fd0
    bl      __msl_strcmp
    cmpwi	r3, 0
    bc      12, 2, _800067d0
    mr	r3, r27
    addi	r4, r13, -0x7fcc
    bl      __msl_strcmp
    cmpwi	r3, 0
    bc      12, 2, _800067d0
    lbz	r4, 0(r27)
    rlwinm.	r0, r4, 0x19, 0x1f, 0x1f
    bc      12, 2, _80006740
    lhz	r4, 0(r27)
    addi	r27, r27, 2
    b       _80006744
_80006740:
    addi	r27, r27, 1
_80006744:
    cmplwi	r4, 0x20
    bc      4, 2, _80006780
    xoris	r3, r28, 0x8000
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lfd	f2, -0x7f50(r2)
    stw	r0, 8(r1)
    lfd	f0, -0x7f88(r2)
    lfd	f1, 8(r1)
    fsub	f1, f1, f2
    fadd	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r28, 0x14(r1)
    b       _800067c4
_80006780:
    lha	r0, -0x7cd4(r13)
    lis     r3, lbl_8015B940@ha
    addi	r3, r3, lbl_8015B940@l
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _800067b0
_80006798:
    lhz	r0, 4(r3)
    cmpw	r0, r4
    bc      4, 2, _800067a8
    b       _800067b4
_800067a8:
    addi	r3, r3, 8
    bc      16, 0, _80006798
_800067b0:
    li	r3, 0
_800067b4:
    cmplwi	r3, 0
    bc      12, 2, _800067c4
    lhz	r0, 6(r3)
    add	r28, r28, r0
_800067c4:
    lbz	r0, 0(r27)
    cmplwi	r0, 0
    bc      4, 2, _80006700
_800067d0:
    lwz	r4, 4(r29)
    xoris	r5, r28, 0x8000
    xoris	r0, r30, 0x8000
    lwz	r3, 0(r29)
    xoris	r4, r4, 0x8000
    stw	r23, 8(r1)
    lfs	f3, -0x7f58(r2)
    stw	r4, 0xc(r1)
    lwzx	r3, r3, r26
    lfd	f0, 8(r1)
    stw	r5, 0x14(r1)
    fsub	f0, f0, f29
    stw	r23, 0x10(r1)
    fmul	f1, f31, f0
    stw	r0, 0x1c(r1)
    lfd	f0, 0x10(r1)
    stw	r23, 0x18(r1)
    fsub	f2, f0, f29
    lfd	f0, 0x18(r1)
    fmul	f1, f28, f1
    fsub	f0, f0, f29
    fmul	f4, f28, f2
    fmul	f0, f31, f0
    fsub	f2, f30, f1
    fsub	f1, f27, f4
    fadd	f2, f2, f0
    frsp	f1, f1
    frsp	f2, f2
    bl      fn_800060D8
    addi	r26, r26, 4
    addi	r30, r30, 1
_8000684c:
    lwz	r0, 4(r29)
    cmpw	r30, r0
    bc      12, 0, _800066f0
_80006858:
    bl      fn_8006FDEC
    bl      fn_8006FEFC
    bl      fn_8006FD1C
_80006864:
    cmpwi	r31, 0
    bc      4, 2, _80006874
    li	r0, 1
    b       _80006890
_80006874:
    cmpwi	r25, 0
    bc      4, 2, _8000688c
    cmpwi	r31, 1
    bc      4, 2, _8000688c
    li	r0, 1
    b       _80006890
_8000688c:
    li	r0, 0
_80006890:
    cmpwi	r0, 0
    bc      12, 2, _800065fc
    cmpwi	r25, 0
    bc      12, 2, _800068b4
    lwz	r12, -0x7cdc(r13)
    cmplwi	r12, 0
    bc      12, 2, _800068b4
    mtctr	r12
    bctrl	
_800068b4:
    psq_l	f31, 0x98(r1), 0, 0
    lfd	f31, 0x90(r1)
    psq_l	f30, 0x88(r1), 0, 0
    lfd	f30, 0x80(r1)
    psq_l	f29, 0x78(r1), 0, 0
    lfd	f29, 0x70(r1)
    psq_l	f28, 0x68(r1), 0, 0
    lfd	f28, 0x60(r1)
    psq_l	f27, 0x58(r1), 0, 0
    addi	r11, r1, 0x50
    lfd	f27, 0x50(r1)
    bl      _restgpr_23
    lwz	r0, 0xa4(r1)
    mtlr	r0
    addi	r1, r1, 0xa0
    blr	
}

asm void fn_800068F4(void)
{
    nofralloc
    lwz	r0, -0x7cd8(r13)
    stw	r3, -0x7cd8(r13)
    mr	r3, r0
    blr	
}

asm void fn_80006904(void)
{
    nofralloc
    lwz	r0, -0x7cdc(r13)
    stw	r3, -0x7cdc(r13)
    mr	r3, r0
    blr	
}

asm void fn_80006914(void)
{
    nofralloc
    stw	r3, -0x7ce0(r13)
    blr	
}

asm void fn_8000691C(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    stw	r0, 0x74(r1)
    addi	r3, r1, 0x30
    stw	r31, 0x6c(r1)
    bl      PADRead
    addi	r3, r1, 8
    bl      fn_8006B470
    lbz	r3, 0x11(r1)
    addi	r31, r1, 0x30
    li	r0, 0
    extsb	r3, r3
    cmpwi	r3, -1
    bc      12, 2, _80006960
    lhz	r3, 8(r1)
    stb	r0, 0x3a(r1)
    sth	r3, 0x30(r1)
_80006960:
    lbz	r3, 0x1b(r1)
    extsb	r3, r3
    cmpwi	r3, -1
    bc      12, 2, _8000697c
    lhz	r3, 0x12(r1)
    stb	r0, 0x46(r1)
    sth	r3, 0x3c(r1)
_8000697c:
    lbz	r3, 0x25(r1)
    extsb	r3, r3
    cmpwi	r3, -1
    bc      12, 2, _80006998
    lhz	r3, 0x1c(r1)
    sth	r3, 0x18(r31)
    stb	r0, 0x22(r31)
_80006998:
    lbz	r3, 0x2f(r1)
    extsb	r3, r3
    cmpwi	r3, -1
    bc      12, 2, _800069b4
    lhz	r3, 0x26(r1)
    sth	r3, 0x24(r31)
    stb	r0, 0x2e(r31)
_800069b4:
    lbz	r3, 0x3a(r1)
    li	r0, 0
    extsb	r3, r3
    cmpwi	r3, -3
    bc      4, 2, _800069cc
    sth	r0, 0x30(r1)
_800069cc:
    lbz	r3, 0x46(r1)
    extsb	r3, r3
    cmpwi	r3, -3
    bc      4, 2, _800069e0
    sth	r0, 0x3c(r1)
_800069e0:
    lbz	r3, 0x22(r31)
    extsb	r3, r3
    cmpwi	r3, -3
    bc      4, 2, _800069f4
    sth	r0, 0x18(r31)
_800069f4:
    lbz	r3, 0x2e(r31)
    extsb	r3, r3
    cmpwi	r3, -3
    bc      4, 2, _80006a08
    sth	r0, 0x24(r31)
_80006a08:
    lbz	r0, -0x7ce6(r13)
    cmplwi	r0, 1
    bc      4, 2, _80006a28
    bl      OSGetResetSwitchState
    cmpwi	r3, 0
    bc      4, 2, _80006a28
    li	r0, 0xff
    stb	r0, -0x7ce7(r13)
_80006a28:
    bl      OSGetResetSwitchState
    cmpwi	r3, 0
    bc      12, 2, _80006a3c
    li	r0, 1
    stb	r0, -0x7ce6(r13)
_80006a3c:
    lbz	r3, -0x7ce7(r13)
    lis	r0, 0x4330
    stw	r0, 0x60(r1)
    lfd	f2, -0x7f78(r2)
    stw	r3, 0x64(r1)
    lfd	f0, -0x7f48(r2)
    lfd	f1, 0x60(r1)
    fsub	f1, f1, f2
    fcmpo	cr0, f1, f0
    bc      4, 1, _80006a90
    bl      VIWaitForRetrace
    li	r3, 1
    bl      fn_8001BDF0
    li	r3, 0
    bl      fn_8006FFCC
    bl      fn_8006FDEC
    bl      fn_8006FEFC
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      OSResetSystem
_80006a90:
    li	r0, 4
    li	r4, 0
    mtctr	r0
_80006a9c:
    lhz	r0, 0(r31)
    andi.	r0, r0, 0x1600
    cmpwi	r0, 0x1600
    bc      4, 2, _80006abc
    lbz	r3, -0x7ce7(r13)
    addi	r0, r3, 1
    stb	r0, -0x7ce7(r13)
    b       _80006ac8
_80006abc:
    addi	r31, r31, 0xc
    addi	r4, r4, 1
    bc      16, 0, _80006a9c
_80006ac8:
    cmplwi	r4, 4
    bc      4, 2, _80006ad8
    li	r0, 0
    stb	r0, -0x7ce7(r13)
_80006ad8:
    lwz	r0, 0x74(r1)
    lwz	r31, 0x6c(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr	
}

asm void fn_80006AEC(void)
{
    nofralloc
    stw	r3, -0x7ce4(r13)
    blr	
}

asm void fn_80006AF4(void)
{
    nofralloc
    lbz	r3, -0x7ce8(r13)
    blr	
}

asm void fn_80006AFC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8015BD40@ha
    addi	r4, r13, -0x7fc8
    stw	r0, 0x14(r1)
    addi	r3, r3, lbl_8015BD40@l
    bl      strcpy
    li	r3, 0
    bl      fn_80006B30
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80006B30(void)
{
    nofralloc
    cmplwi	r3, 0
    bc      12, 2, _80006b3c
    b       _80006b44
_80006b3c:
    lis     r3, fn_80006B4C@ha
    addi	r3, r3, fn_80006B4C@l
_80006b44:
    stw	r3, -0x7cb8(r13)
    blr	
}

asm void fn_80006B4C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r7, 2
    stw	r0, 0x14(r1)
    bl      DVDReadAsync
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80006B70(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, lbl_801220C0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r4
    stw	r30, 8(r1)
    mr	r30, r3
    addi	r3, r5, lbl_801220C0@l
    mr	r4, r30
    crxor	6, 6, 6
    bl      __va_save_registers
    lis     r3, dvd_open_from_dvd_str@ha
    addi	r3, r3, dvd_open_from_dvd_str@l
    crxor	6, 6, 6
    bl      __va_save_registers
    li	r0, 0
    mr	r3, r30
    stw	r0, 0(r31)
    addi	r4, r31, 4
    bl      DVDOpen
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void __va_save_registers(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    bc      4, 6, _80006c04
    stfd	f1, 0x28(r1)
    stfd	f2, 0x30(r1)
    stfd	f3, 0x38(r1)
    stfd	f4, 0x40(r1)
    stfd	f5, 0x48(r1)
    stfd	f6, 0x50(r1)
    stfd	f7, 0x58(r1)
    stfd	f8, 0x60(r1)
_80006c04:
    stw	r3, 8(r1)
    stw	r4, 0xc(r1)
    stw	r5, 0x10(r1)
    stw	r6, 0x14(r1)
    stw	r7, 0x18(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r10, 0x24(r1)
    addi	r1, r1, 0x70
    blr	
}

asm void fn_80006C2C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80006C4C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80006C4C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    or.	r29, r3, r3
    bc      4, 0, _80006c7c
    li	r3, 0
    b       _80006cc8
_80006c7c:
    lis     r3, lbl_801220E0@ha
    mr	r4, r29
    addi	r3, r3, lbl_801220E0@l
    crxor	6, 6, 6
    bl      __va_save_registers
    rlwinm.	r0, r29, 0, 1, 0xf
    bc      4, 2, _80006cc4
    lis     r3, dvd_open_from_dvd_str@ha
    addi	r3, r3, dvd_open_from_dvd_str@l
    crxor	6, 6, 6
    bl      __va_save_registers
    mr	r3, r29
    addi	r4, r30, 4
    bl      fn_800170EC
    or.	r31, r3, r3
    bc      12, 2, _80006cc4
    li	r0, 0
    stw	r0, 0(r30)
_80006cc4:
    mr	r3, r31
_80006cc8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80006CE4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r0, 0(r3)
    cmpwi	r0, 1
    bc      12, 2, _80006d08
    addi	r3, r3, 4
    bl      DVDCancelSync
    mr	r4, r3
_80006d08:
    lwz	r0, 0x14(r1)
    mr	r3, r4
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80006D1C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r11, r1, 0x20
    bl      _savegpr_27
    mr	r27, r3
    mr	r28, r4
    lwz	r0, 0(r3)
    mr	r29, r5
    mr	r30, r6
    cmpwi	r0, 1
    bc      12, 2, _80006d7c
    lis     r3, dvd_reading_from_dvd_str@ha
    addi	r3, r3, dvd_reading_from_dvd_str@l
    crxor	6, 6, 6
    bl      __va_save_registers
    lwz	r12, -0x7cb8(r13)
    mr	r4, r28
    mr	r5, r29
    mr	r6, r30
    addi	r3, r27, 4
    mtctr	r12
    bctrl	
    mr	r31, r3
_80006d7c:
    lis     r3, lbl_80122104@ha
    mr	r4, r31
    addi	r3, r3, lbl_80122104@l
    crxor	6, 6, 6
    bl      __va_save_registers
    mr	r3, r31
    addi	r11, r1, 0x20
    bl      _restgpr_27
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80006DAC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r0, 0(r3)
    cmpwi	r0, 1
    bc      12, 2, _80006dd4
    addi	r3, r3, 4
    li	r8, 2
    bl      DVDReadPrio
    mr	r8, r3
_80006dd4:
    lwz	r0, 0x14(r1)
    mr	r3, r8
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80006DE8(void)
{
    nofralloc
    lwz	r0, 0(r3)
    cmpwi	r0, 1
    beqlr	
    lwz	r3, 0x38(r3)
    blr	
}

asm void fn_80006DFC(void)
{
    nofralloc
    lwz	r0, 0(r3)
    cmpwi	r0, 1
    beqlr	
    lwz	r3, 0x34(r3)
    blr	
}

asm void fn_80006E10(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    bl      fn_80017470
    lis     r3, lbl_8015BD40@ha
    addi	r31, r3, lbl_8015BD40@l
    b       _80006fb4
_80006e40:
    cmplwi	r0, 0x2f
    bc      4, 2, _80006e9c
    addi	r29, r30, 1
    li	r28, 1
    b       _80006e84
_80006e54:
    lbz	r0, 0(r29)
    cmplwi	r0, 0x2f
    bc      12, 2, _80006e7c
    lis     r3, lbl_8015BD40@ha
    add	r4, r28, r30
    addi	r3, r3, lbl_8015BD40@l
    addi	r4, r4, -1
    bl      strcpy
    add	r30, r30, r28
    b       _80006f70
_80006e7c:
    addi	r28, r28, 1
    addi	r29, r29, 1
_80006e84:
    mr	r3, r30
    bl      strlen
    addi	r0, r3, 1
    cmplw	r28, r0
    bc      12, 0, _80006e54
    b       _80006f70
_80006e9c:
    mr	r3, r30
    addi	r4, r13, -0x7fc4
    li	r5, 2
    bl      __msl_strncmp
    cmpwi	r3, 0
    bc      4, 2, _80006f28
    lis     r3, lbl_8015BD40@ha
    addi	r3, r3, lbl_8015BD40@l
    bl      strlen
    addic.	r4, r3, -1
    lis     r3, lbl_8015BD40@ha
    addi	r3, r3, lbl_8015BD40@l
    addi	r0, r4, 1
    add	r3, r3, r4
    mtctr	r0
    bc      12, 0, _80006f0c
_80006edc:
    lbz	r0, 0(r3)
    cmplwi	r0, 0x2f
    bc      4, 2, _80006f00
    lis     r3, lbl_8015BD40@ha
    li	r0, 0
    addi	r3, r3, lbl_8015BD40@l
    addi	r30, r30, 2
    stbx	r0, r3, r4
    b       _80006f0c
_80006f00:
    addi	r3, r3, -1
    addi	r4, r4, -1
    bc      16, 0, _80006edc
_80006f0c:
    lis	r3, lbl_8015BD40@ha
    lbzu	r0, lbl_8015BD40@l(r3)
    cmplwi	r0, 0
    bc      4, 2, _80006f70
    addi	r4, r13, -0x7fc8
    bl      strcpy
    b       _80006f70
_80006f28:
    lis	r3, lbl_8015BD40@ha
    lbz	r0, lbl_8015BD40@l(r3)
    cmplwi	r0, 0x2f
    bc      4, 2, _80006f44
    lbz	r0, 1(r31)
    cmplwi	r0, 0
    bc      12, 2, _80006f54
_80006f44:
    lis     r3, lbl_8015BD40@ha
    addi	r4, r13, -0x7fc8
    addi	r3, r3, lbl_8015BD40@l
    bl      __msl_strcpy
_80006f54:
    lis     r3, lbl_8015BD40@ha
    mr	r4, r30
    addi	r3, r3, lbl_8015BD40@l
    bl      __msl_strcpy
    mr	r3, r30
    bl      strlen
    add	r30, r30, r3
_80006f70:
    lbz	r0, 0(r31)
    cmplwi	r0, 0x2f
    bc      4, 2, _80006f88
    lbz	r0, 1(r31)
    cmplwi	r0, 0
    bc      12, 2, _80006fb4
_80006f88:
    lis     r3, lbl_8015BD40@ha
    addi	r3, r3, lbl_8015BD40@l
    bl      strlen
    lis     r4, lbl_8015BD40@ha
    addi	r5, r3, -1
    addi	r3, r4, lbl_8015BD40@l
    lbzx	r0, r3, r5
    cmplwi	r0, 0x2f
    bc      4, 2, _80006fb4
    li	r0, 0
    stbx	r0, r3, r5
_80006fb4:
    lbz	r0, 0(r30)
    cmplwi	r0, 0
    bc      4, 2, _80006e40
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80006FE0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r6, lbl_8015BD40@ha
    mr	r5, r4
    stw	r0, 0x14(r1)
    addi	r4, r6, lbl_8015BD40@l
    bl      strncpy
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8000700C(void)
{
    nofralloc
    stwu	r1, -0xa0(r1)
    mflr	r0
    lis     r4, lbl_801220C0@ha
    stw	r0, 0xa4(r1)
    stw	r31, 0x9c(r1)
    stw	r30, 0x98(r1)
    addi	r30, r4, lbl_801220C0@l
    stw	r29, 0x94(r1)
    mr	r29, r3
    stw	r28, 0x90(r1)
    lwz	r0, -0x7cc8(r13)
    cmplwi	r0, 0
    bc      4, 2, _8000704c
    bl      DVDConvertPathToEntrynum
    mr	r28, r3
    b       _80007194
_8000704c:
    lwz	r0, -0x7cbc(r13)
    cmplwi	r0, 0
    bc      4, 2, _8000706c
    addi	r3, r30, 0x58
    addi	r5, r30, 0x80
    li	r4, 0x2ed
    crxor	6, 6, 6
    bl      OSPanic
_8000706c:
    lbz	r0, 0(r29)
    cmplwi	r0, 0x2f
    bc      4, 2, _800070c4
    addi	r31, r29, 1
    li	r28, 1
    b       _800070ac
_80007084:
    lbz	r0, 0(r31)
    cmplwi	r0, 0x2f
    bc      12, 2, _800070a4
    add	r4, r28, r29
    addi	r3, r1, 8
    addi	r4, r4, -1
    bl      strcpy
    b       _80007108
_800070a4:
    addi	r28, r28, 1
    addi	r31, r31, 1
_800070ac:
    mr	r3, r29
    bl      strlen
    addi	r0, r3, 1
    cmplw	r28, r0
    bc      12, 0, _80007084
    b       _80007108
_800070c4:
    lis     r4, lbl_8015BD40@ha
    addi	r3, r1, 8
    addi	r4, r4, lbl_8015BD40@l
    bl      strcpy
    lis	r3, lbl_8015BD40@ha
    lbzu	r0, lbl_8015BD40@l(r3)
    cmplwi	r0, 0x2f
    bc      4, 2, _800070f0
    lbz	r0, 1(r3)
    cmplwi	r0, 0
    bc      12, 2, _800070fc
_800070f0:
    addi	r3, r1, 8
    addi	r4, r13, -0x7fc8
    bl      __msl_strcpy
_800070fc:
    mr	r4, r29
    addi	r3, r1, 8
    bl      __msl_strcpy
_80007108:
    mr	r4, r29
    addi	r3, r30, 0xa0
    crxor	6, 6, 6
    bl      __va_save_registers
    lis     r4, lbl_8015BD40@ha
    addi	r3, r30, 0xb0
    addi	r4, r4, lbl_8015BD40@l
    crxor	6, 6, 6
    bl      __va_save_registers
    addi	r3, r30, 0xc0
    addi	r4, r1, 8
    crxor	6, 6, 6
    bl      __va_save_registers
    li	r29, 0
    li	r28, -1
    mr	r31, r29
    b       _80007174
_8000714c:
    lwz	r3, -0x7cc0(r13)
    addi	r4, r1, 8
    lwzx	r3, r3, r31
    bl      __msl_strcmp
    cmpwi	r3, 0
    bc      4, 2, _8000716c
    oris	r28, r29, 0x7fff
    b       _80007180
_8000716c:
    addi	r31, r31, 4
    addi	r29, r29, 1
_80007174:
    lwz	r0, -0x7cc4(r13)
    cmpw	r29, r0
    bc      12, 0, _8000714c
_80007180:
    addi	r3, r30, 0xd0
    addi	r4, r1, 8
    oris	r5, r28, 0x7fff
    crxor	6, 6, 6
    bl      __va_save_registers
_80007194:
    lwz	r0, 0xa4(r1)
    mr	r3, r28
    lwz	r31, 0x9c(r1)
    lwz	r30, 0x98(r1)
    lwz	r29, 0x94(r1)
    lwz	r28, 0x90(r1)
    mtlr	r0
    addi	r1, r1, 0xa0
    blr	
}

asm void fn_800071B8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    li	r0, 1
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    stw	r0, -0x7cac(r13)
    bl      OSGetArenaHi
    addis	r31, r3, -4
    rlwinm	r31, r31, 0, 0, 0xd
    mr	r3, r31
    bl      OSSetArenaHi
    lwz	r0, -0x76e0(r13)
    li	r4, 0x1000
    stw	r4, -0x7ca4(r13)
    rlwinm.	r0, r0, 0, 0x1c, 0x1c
    bc      12, 2, _80007224
    lwz	r31, -0x76c8(r13)
    slwi	r3, r4, 8
    slwi	r4, r4, 2
    stw	r3, -0x7ca8(r13)
    subf	r31, r3, r31
    addi	r0, r3, -1
    andc	r31, r31, r0
    stw	r4, -0x7ca4(r13)
    stw	r31, -0x76c8(r13)
    b       _8000722c
_80007224:
    slwi	r0, r4, 6
    stw	r0, -0x7ca8(r13)
_8000722c:
    clrlwi	r0, r31, 4
    lwz	r5, -0x7ca8(r13)
    oris	r3, r0, 0xc000
    li	r4, 0
    stw	r3, -0x7cb0(r13)
    bl      memset
    lwz	r3, -0x7ca8(r13)
    li	r4, -0x19
    addi	r0, r3, -1
    srwi	r0, r0, 0x10
    rlwimi	r0, r31, 0, 4, 0xf
    mfmsr	r3
    and	r3, r3, r4
    nor	r4, r4, r4
    mtmsr	r3
    isync	
    sync	
    mtspr	0x19, r0
    or	r3, r3, r4
    mtmsr	r3
    isync	
    sync	
    li	r30, 0
    lwz	r3, -0x7ca4(r13)
    li	r0, 2
    srwi	r3, r3, 4
    mtctr	r0
_80007298:
    addi	r0, r30, 8
    slwi	r4, r30, 0x1c
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    mtsrin	r0, r4
    addi	r0, r30, 9
    addi	r30, r30, 1
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    slwi	r4, r30, 0x1c
    mtsrin	r0, r4
    addi	r0, r30, 9
    addi	r30, r30, 1
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    slwi	r4, r30, 0x1c
    mtsrin	r0, r4
    addi	r0, r30, 9
    addi	r30, r30, 1
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    slwi	r4, r30, 0x1c
    mtsrin	r0, r4
    addi	r0, r30, 9
    addi	r30, r30, 1
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    slwi	r4, r30, 0x1c
    mtsrin	r0, r4
    addi	r0, r30, 9
    addi	r30, r30, 1
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    slwi	r4, r30, 0x1c
    mtsrin	r0, r4
    addi	r0, r30, 9
    addi	r30, r30, 1
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    slwi	r4, r30, 0x1c
    mtsrin	r0, r4
    addi	r0, r30, 9
    addi	r30, r30, 1
    clrlwi	r0, r0, 0x1c
    mullw	r0, r3, r0
    slwi	r4, r30, 0x1c
    mtsrin	r0, r4
    addi	r30, r30, 1
    bc      16, 0, _80007298
    isync	
    sync	
    tlbsync	
    sync	
    lwz	r0, -0x76e0(r13)
    rlwinm.	r0, r0, 0, 0x1c, 0x1c
    bc      12, 2, _800073dc
    li	r30, 0
    li	r31, 0
_80007380:
    mr	r4, r31
    addis	r3, r31, -0x8000
    li	r5, 0
    li	r6, 0
    li	r7, 0
    bl      fn_8000740C
    addi	r30, r30, 1
    addi	r31, r31, 0x1000
    cmplwi	r30, 0x3000
    bc      12, 0, _80007380
    li	r4, 0x3f
    li	r0, 0
    isync	
    sync	
    nop	
    mfdbatu	r3, 0
    rlwimi	r3, r4, 0, 0x10, 0x1f
    mtdbatu	0, r3
    mtdbatu	2, r0
    mtdbatl	2, r0
    nop	
    isync	
    sync	
_800073dc:
    lis	r3, 1
    li	r4, 0
    addi	r0, r3, -1
    sth	r4, -0x7c9a(r13)
    sth	r0, -0x7c9c(r13)
    stw	r4, -0x7ca0(r13)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8000740C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r11, r1, 0x20
    bl      _savegpr_26
    mr	r26, r3
    mr	r27, r4
    mr	r28, r5
    mr	r29, r6
    mr	r30, r7
    bl      fn_80007730
    or.	r31, r3, r3
    bc      4, 2, _80007458
    lis     r4, mmu_cant_allocate_pte_str@ha
    addi	r3, r13, -0x7fc0
    addi	r5, r4, mmu_cant_allocate_pte_str@l
    li	r4, 0x1cd
    crxor	6, 6, 6
    bl      OSPanic
_80007458:
    mr	r3, r26
    bl      OSVirtualToPhysical
    lwz	r0, 0(r31)
    rlwimi	r0, r3, 7, 1, 0x18
    mr	r3, r31
    mr	r4, r26
    stw	r0, 0(r31)
    mr	r5, r27
    lbz	r0, 3(r31)
    rlwimi	r0, r26, 0xa, 0x1a, 0x1f
    stb	r0, 3(r31)
    lbz	r0, 7(r31)
    rlwimi	r0, r28, 6, 0x19, 0x19
    stb	r0, 7(r31)
    lbz	r0, 7(r31)
    rlwimi	r0, r29, 5, 0x1a, 0x1a
    stb	r0, 7(r31)
    lbz	r0, 7(r31)
    rlwimi	r0, r30, 0, 0x1e, 0x1f
    stb	r0, 7(r31)
    bl      fn_80007664
    addi	r11, r1, 0x20
    bl      _restgpr_26
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800074C4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    addi	r11, r1, 0x30
    bl      _savegpr_24
    clrlwi	r9, r4, 0x14
    clrlwi	r29, r6, 0x18
    addi	r0, r9, 0xfff
    mr	r27, r3
    add	r0, r5, r0
    mr	r26, r4
    clrlwi	r30, r7, 0x18
    clrlwi	r31, r8, 0x18
    srwi	r24, r0, 0xc
    li	r25, 0
    b       _8000758c
_80007504:
    mr	r3, r27
    bl      fn_80007730
    or.	r28, r3, r3
    bc      4, 2, _8000752c
    lis     r4, mmu_cant_allocate_pte_str@ha
    addi	r3, r13, -0x7fc0
    addi	r5, r4, mmu_cant_allocate_pte_str@l
    li	r4, 0x1cd
    crxor	6, 6, 6
    bl      OSPanic
_8000752c:
    mr	r3, r27
    bl      OSVirtualToPhysical
    lwz	r0, 0(r28)
    rlwimi	r0, r3, 7, 1, 0x18
    mr	r3, r28
    mr	r4, r27
    stw	r0, 0(r28)
    mr	r5, r26
    lbz	r0, 3(r28)
    rlwimi	r0, r27, 0xa, 0x1a, 0x1f
    stb	r0, 3(r28)
    lbz	r0, 7(r28)
    rlwimi	r0, r29, 6, 0x19, 0x19
    stb	r0, 7(r28)
    lbz	r0, 7(r28)
    rlwimi	r0, r30, 5, 0x1a, 0x1a
    stb	r0, 7(r28)
    lbz	r0, 7(r28)
    rlwimi	r0, r31, 0, 0x1e, 0x1f
    stb	r0, 7(r28)
    bl      fn_80007664
    addi	r27, r27, 0x1000
    addi	r26, r26, 0x1000
    addi	r25, r25, 1
_8000758c:
    cmplw	r25, r24
    bc      12, 0, _80007504
    addi	r11, r1, 0x30
    bl      _restgpr_24
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800075AC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    rlwinm	r7, r3, 0, 0, 0x13
    neg	r3, r5
    stw	r0, 0x24(r1)
    or	r3, r3, r5
    clrlwi	r6, r7, 0x14
    li	r0, 3
    stw	r31, 0x1c(r1)
    addi	r5, r6, 0xfff
    srawi	r3, r3, 0x1f
    stw	r30, 0x18(r1)
    and	r0, r0, r3
    add	r4, r4, r5
    mr	r30, r7
    stw	r29, 0x14(r1)
    li	r29, 0
    clrlwi	r31, r0, 0x18
    stw	r28, 0x10(r1)
    srwi	r28, r4, 0xc
    b       _8000762c
_80007600:
    mr	r3, r30
    bl      fn_800077E0
    cmplwi	r3, 0
    bc      12, 2, _80007624
    lbz	r0, 7(r3)
    rlwimi	r0, r31, 0, 0x1e, 0x1f
    mr	r4, r30
    stb	r0, 7(r3)
    bl      fn_80007700
_80007624:
    addi	r30, r30, 0x1000
    addi	r29, r29, 1
_8000762c:
    cmplw	r29, r28
    bc      12, 0, _80007600
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void OSVirtualToPhysical(void)
{
    nofralloc
    rlwinm	r3, r3, 0, 0, 3
    mfsrin	r3, r3
    clrlwi	r3, r3, 8
    blr	
}

asm void fn_80007664(void)
{
    nofralloc
    lbz	r0, 6(r3)
    li	r6, 0
    rlwimi	r0, r6, 1, 0x1c, 0x1e
    rlwinm	r5, r5, 0x14, 0x10, 0x1f
    stb	r0, 6(r3)
    lbz	r0, 7(r3)
    rlwimi	r0, r6, 2, 0x1d, 0x1d
    stb	r0, 7(r3)
    lwz	r0, 4(r3)
    rlwimi	r0, r5, 0xc, 0, 0x13
    stw	r0, 4(r3)
    lbz	r0, 6(r3)
    rlwimi	r0, r6, 0, 0x1f, 0x1f
    stb	r0, 6(r3)
    lbz	r0, 7(r3)
    rlwimi	r0, r6, 7, 0x18, 0x18
    stb	r0, 7(r3)
    lbz	r0, 7(r3)
    rlwimi	r0, r6, 4, 0x1b, 0x1b
    stb	r0, 7(r3)
    lbz	r0, 7(r3)
    rlwimi	r0, r6, 3, 0x1c, 0x1c
    stb	r0, 7(r3)
    sync	
    tlbie	r4
    sync	
    tlbsync	
    sync	
    lbz	r0, 0(r3)
    li	r5, 1
    rlwimi	r0, r5, 7, 0x18, 0x18
    stb	r0, 0(r3)
    dcbf	0, r3
    sync	
    tlbie	r4
    sync	
    tlbsync	
    sync	
    blr	
}

asm void fn_80007700(void)
{
    nofralloc
    sync	
    tlbie	r4
    sync	
    tlbsync	
    sync	
    dcbf	0, r3
    sync	
    tlbie	r4
    sync	
    tlbsync	
    sync	
    blr	
}

asm void fn_80007730(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    bl      fn_800079C4
    stw	r3, 8(r1)
    mr	r3, r29
    bl      fn_80007A00
    stw	r3, 0xc(r1)
    addi	r30, r1, 8
    li	r29, 0
    li	r31, 8
_8000776c:
    lwz	r3, 0(r30)
    bl      fn_800079A0
    li	r5, 0
    mr	r4, r3
    mtctr	r31
_80007780:
    lbz	r0, 0(r4)
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      4, 2, _800077a4
    slwi	r0, r5, 3
    add	r3, r3, r0
    lbz	r0, 3(r3)
    rlwimi	r0, r29, 6, 0x19, 0x19
    stb	r0, 3(r3)
    b       _800077c4
_800077a4:
    addi	r4, r4, 8
    addi	r5, r5, 1
    bc      16, 0, _80007780
    addi	r29, r29, 1
    addi	r30, r30, 4
    cmplwi	r29, 2
    bc      12, 0, _8000776c
    li	r3, 0
_800077c4:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800077E0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    mr	r28, r3
    bl      OSVirtualToPhysical
    mr	r31, r3
    mr	r3, r28
    rlwinm	r29, r28, 0xa, 0x1a, 0x1f
    bl      fn_800079C4
    stw	r3, 8(r1)
    mr	r3, r28
    bl      fn_80007A00
    stw	r3, 0xc(r1)
    addi	r30, r1, 8
    li	r28, 0
_8000782c:
    lwz	r3, 0(r30)
    bl      fn_800079A0
    li	r0, 2
    li	r6, 0
    mr	r5, r3
    mtctr	r0
_80007844:
    lbz	r0, 0(r5)
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      12, 2, _80007888
    lbz	r4, 3(r5)
    rlwinm	r0, r4, 0x1a, 0x1f, 0x1f
    cmplw	r28, r0
    bc      4, 2, _80007888
    clrlwi	r0, r4, 0x1a
    cmplw	r29, r0
    bc      4, 2, _80007888
    lwz	r0, 0(r5)
    rlwinm	r0, r0, 0x19, 8, 0x1f
    cmplw	r31, r0
    bc      4, 2, _80007888
    slwi	r0, r6, 3
    add	r3, r3, r0
    b       _80007980
_80007888:
    lbz	r0, 8(r5)
    addi	r6, r6, 1
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      12, 2, _800078d0
    lbz	r4, 0xb(r5)
    rlwinm	r0, r4, 0x1a, 0x1f, 0x1f
    cmplw	r28, r0
    bc      4, 2, _800078d0
    clrlwi	r0, r4, 0x1a
    cmplw	r29, r0
    bc      4, 2, _800078d0
    lwz	r0, 8(r5)
    rlwinm	r0, r0, 0x19, 8, 0x1f
    cmplw	r31, r0
    bc      4, 2, _800078d0
    slwi	r0, r6, 3
    add	r3, r3, r0
    b       _80007980
_800078d0:
    lbz	r0, 0x10(r5)
    addi	r6, r6, 1
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      12, 2, _80007918
    lbz	r4, 0x13(r5)
    rlwinm	r0, r4, 0x1a, 0x1f, 0x1f
    cmplw	r28, r0
    bc      4, 2, _80007918
    clrlwi	r0, r4, 0x1a
    cmplw	r29, r0
    bc      4, 2, _80007918
    lwz	r0, 0x10(r5)
    rlwinm	r0, r0, 0x19, 8, 0x1f
    cmplw	r31, r0
    bc      4, 2, _80007918
    slwi	r0, r6, 3
    add	r3, r3, r0
    b       _80007980
_80007918:
    lbz	r0, 0x18(r5)
    addi	r6, r6, 1
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      12, 2, _80007960
    lbz	r4, 0x1b(r5)
    rlwinm	r0, r4, 0x1a, 0x1f, 0x1f
    cmplw	r28, r0
    bc      4, 2, _80007960
    clrlwi	r0, r4, 0x1a
    cmplw	r29, r0
    bc      4, 2, _80007960
    lwz	r0, 0x18(r5)
    rlwinm	r0, r0, 0x19, 8, 0x1f
    cmplw	r31, r0
    bc      4, 2, _80007960
    slwi	r0, r6, 3
    add	r3, r3, r0
    b       _80007980
_80007960:
    addi	r5, r5, 0x20
    addi	r6, r6, 1
    bc      16, 0, _80007844
    addi	r28, r28, 1
    addi	r30, r30, 4
    cmplwi	r28, 2
    bc      12, 0, _8000782c
    li	r3, 0
_80007980:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800079A0(void)
{
    nofralloc
    mfspr	r4, 0x19
    slwi	r0, r4, 0x10
    rlwinm	r4, r4, 0, 0, 0xf
    ori	r0, r0, 0xffff
    and	r0, r0, r3
    oris	r0, r0, 0x8000
    or	r4, r4, r0
    mr	r3, r4
    blr	
}

asm void fn_800079C4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      OSVirtualToPhysical
    rlwinm	r4, r31, 0x14, 0x10, 0x1f
    clrlwi	r0, r3, 0xd
    xor	r0, r4, r0
    slwi	r3, r0, 6
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80007A00(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      OSVirtualToPhysical
    rlwinm	r4, r31, 0x14, 0x10, 0x1f
    clrlwi	r0, r3, 0xd
    xor	r0, r4, r0
    slwi	r0, r0, 6
    xoris	r3, r0, 0x1ff
    xori	r3, r3, 0xffc0
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80007A44(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r4, 0x100
    addi	r6, r13, -0x7fb8
    stw	r0, 0x14(r1)
    addi	r3, r1, 8
    addi	r4, r4, -1
    lwz	r0, -0x7f40(r2)
    stw	r0, 0xc(r1)
    lbz	r8, 0xc(r1)
    lbz	r7, 0xd(r1)
    lbz	r5, 0xe(r1)
    lbz	r0, 0xf(r1)
    stb	r8, -0x7fb8(r13)
    stb	r7, 1(r6)
    stb	r5, 2(r6)
    stb	r0, 3(r6)
    lwz	r0, -0x7fb8(r13)
    stw	r0, 8(r1)
    bl      ModelMatchCachedSlot_B20
    addi	r3, r13, -0x7fb8
    bl      fn_80008204
    li	r0, 0
    stw	r0, -0x7c98(r13)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80007AB4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lbz	r0, 0(r3)
    lbz	r4, -0x7fb8(r13)
    cmplw	r4, r0
    bc      4, 2, _80007b04
    addi	r5, r13, -0x7fb8
    lbz	r0, 1(r3)
    lbz	r4, 1(r5)
    cmplw	r4, r0
    bc      4, 2, _80007b04
    lbz	r4, 2(r5)
    lbz	r0, 2(r3)
    cmplw	r4, r0
    bc      4, 2, _80007b04
    lbz	r4, 3(r5)
    lbz	r0, 3(r3)
    cmplw	r4, r0
    bc      12, 2, _80007b50
_80007b04:
    lwz	r0, 0(r3)
    lis	r4, 0x100
    addi	r6, r13, -0x7fb8
    addi	r3, r1, 8
    stw	r0, 0xc(r1)
    addi	r4, r4, -1
    lbz	r8, 0xc(r1)
    lbz	r7, 0xd(r1)
    lbz	r5, 0xe(r1)
    lbz	r0, 0xf(r1)
    stb	r8, -0x7fb8(r13)
    stb	r7, 1(r6)
    stb	r5, 2(r6)
    stb	r0, 3(r6)
    lwz	r0, -0x7fb8(r13)
    stw	r0, 8(r1)
    bl      ModelMatchCachedSlot_B20
    addi	r3, r13, -0x7fb8
    bl      fn_80008204
_80007b50:
    li	r0, 1
    stw	r0, -0x7c98(r13)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void dvd_user_fn(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    lwz	r4, -0x7f3c(r2)
    lbz	r3, -0x7fb8(r13)
    stw	r4, 0x18(r1)
    lbz	r0, 0x18(r1)
    stw	r4, 8(r1)
    cmplw	r3, r0
    stw	r4, 0x14(r1)
    bc      4, 2, _80007bc8
    addi	r4, r13, -0x7fb8
    lbz	r0, 0x19(r1)
    lbz	r3, 1(r4)
    cmplw	r3, r0
    bc      4, 2, _80007bc8
    lbz	r3, 2(r4)
    lbz	r0, 0x1a(r1)
    cmplw	r3, r0
    bc      4, 2, _80007bc8
    lbz	r3, 3(r4)
    lbz	r0, 0x1b(r1)
    cmplw	r3, r0
    bc      12, 2, _80007c14
_80007bc8:
    lwz	r0, 0x14(r1)
    lis	r4, 0x100
    addi	r6, r13, -0x7fb8
    addi	r3, r1, 0xc
    stw	r0, 0x10(r1)
    addi	r4, r4, -1
    lbz	r8, 0x10(r1)
    lbz	r7, 0x11(r1)
    lbz	r5, 0x12(r1)
    lbz	r0, 0x13(r1)
    stb	r8, -0x7fb8(r13)
    stb	r7, 1(r6)
    stb	r5, 2(r6)
    stb	r0, 3(r6)
    lwz	r0, -0x7fb8(r13)
    stw	r0, 0xc(r1)
    bl      ModelMatchCachedSlot_B20
    addi	r3, r13, -0x7fb8
    bl      fn_80008204
_80007c14:
    li	r0, 1
    stw	r0, -0x7c98(r13)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80007C2C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r4, 0x100
    stw	r0, 0x14(r1)
    addi	r3, r1, 8
    addi	r4, r4, -1
    lwz	r0, -0x7fb8(r13)
    stw	r0, 8(r1)
    bl      ModelMatchCachedSlot_B20
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80007C60(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r3, 0
    stw	r0, 0x14(r1)
    bc      4, 2, _80007c80
    lwz	r0, -0x7c98(r13)
    cmpwi	r0, 0
    bc      4, 2, _80007cc4
_80007c80:
    lwz	r0, -0x7f38(r2)
    lis	r4, 0x100
    addi	r6, r13, -0x7fb8
    addi	r3, r1, 8
    stw	r0, 0xc(r1)
    addi	r4, r4, -1
    lbz	r8, 0xc(r1)
    lbz	r7, 0xd(r1)
    lbz	r5, 0xe(r1)
    lbz	r0, 0xf(r1)
    stb	r8, -0x7fb8(r13)
    stb	r7, 1(r6)
    stb	r5, 2(r6)
    stb	r0, 3(r6)
    lwz	r0, -0x7fb8(r13)
    stw	r0, 8(r1)
    bl      ModelMatchCachedSlot_B20
_80007cc4:
    li	r0, 0
    stw	r0, -0x7c98(r13)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80007CDC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    li	r5, 1
    mr	r6, r5
    lfs	f0, 0(r3)
    stfs	f0, 0x10(r1)
    lwz	r0, 0x10(r1)
    rlwinm	r4, r0, 0, 1, 8
    addis	r0, r4, -0x7f80
    cmplwi	r0, 0
    bc      12, 2, _80007d24
    lfs	f0, 4(r3)
    stfs	f0, 0xc(r1)
    lwz	r0, 0xc(r1)
    rlwinm	r4, r0, 0, 1, 8
    addis	r0, r4, -0x7f80
    cmplwi	r0, 0
    bc      12, 2, _80007d24
    li	r6, 0
_80007d24:
    cmpwi	r6, 0
    bc      4, 2, _80007d4c
    lfs	f0, 8(r3)
    stfs	f0, 8(r1)
    lwz	r0, 8(r1)
    rlwinm	r3, r0, 0, 1, 8
    addis	r0, r3, -0x7f80
    cmplwi	r0, 0
    bc      12, 2, _80007d4c
    li	r5, 0
_80007d4c:
    mr	r3, r5
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80007D58(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    li	r0, 1
    mr	r4, r0
    stw	r31, 0x3c(r1)
    mr	r5, r0
    mr	r6, r0
    mr	r7, r0
    stw	r30, 0x38(r1)
    mr	r9, r0
    mr	r10, r0
    mr	r11, r0
    lfs	f0, 0(r3)
    mr	r12, r0
    mr	r31, r0
    mr	r30, r0
    stfs	f0, 0x28(r1)
    lwz	r8, 0x28(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007dcc
    lfs	f0, 4(r3)
    stfs	f0, 0x24(r1)
    lwz	r8, 0x24(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007dcc
    li	r30, 0
_80007dcc:
    cmpwi	r30, 0
    bc      4, 2, _80007df4
    lfs	f0, 8(r3)
    stfs	f0, 0x20(r1)
    lwz	r8, 0x20(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007df4
    li	r31, 0
_80007df4:
    cmpwi	r31, 0
    bc      4, 2, _80007e1c
    lfs	f0, 0x10(r3)
    stfs	f0, 0x1c(r1)
    lwz	r8, 0x1c(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007e1c
    li	r12, 0
_80007e1c:
    cmpwi	r12, 0
    bc      4, 2, _80007e44
    lfs	f0, 0x14(r3)
    stfs	f0, 0x18(r1)
    lwz	r8, 0x18(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007e44
    li	r11, 0
_80007e44:
    cmpwi	r11, 0
    bc      4, 2, _80007e6c
    lfs	f0, 0x18(r3)
    stfs	f0, 0x14(r1)
    lwz	r8, 0x14(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007e6c
    li	r10, 0
_80007e6c:
    cmpwi	r10, 0
    bc      4, 2, _80007e94
    lfs	f0, 0x20(r3)
    stfs	f0, 0x10(r1)
    lwz	r8, 0x10(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007e94
    li	r9, 0
_80007e94:
    cmpwi	r9, 0
    bc      4, 2, _80007ebc
    lfs	f0, 0x24(r3)
    stfs	f0, 0xc(r1)
    lwz	r8, 0xc(r1)
    rlwinm	r8, r8, 0, 1, 8
    addis	r8, r8, -0x7f80
    cmplwi	r8, 0
    bc      12, 2, _80007ebc
    li	r7, 0
_80007ebc:
    cmpwi	r7, 0
    bc      4, 2, _80007ee4
    lfs	f0, 0x28(r3)
    stfs	f0, 8(r1)
    lwz	r7, 8(r1)
    rlwinm	r7, r7, 0, 1, 8
    addis	r7, r7, -0x7f80
    cmplwi	r7, 0
    bc      12, 2, _80007ee4
    li	r6, 0
_80007ee4:
    cmpwi	r6, 0
    bc      4, 2, _80007f0c
    lfs	f0, 0xc(r3)
    stfs	f0, 0x34(r1)
    lwz	r6, 0x34(r1)
    rlwinm	r6, r6, 0, 1, 8
    addis	r6, r6, -0x7f80
    cmplwi	r6, 0
    bc      12, 2, _80007f0c
    li	r5, 0
_80007f0c:
    cmpwi	r5, 0
    bc      4, 2, _80007f34
    lfs	f0, 0x1c(r3)
    stfs	f0, 0x30(r1)
    lwz	r5, 0x30(r1)
    rlwinm	r5, r5, 0, 1, 8
    addis	r5, r5, -0x7f80
    cmplwi	r5, 0
    bc      12, 2, _80007f34
    li	r4, 0
_80007f34:
    cmpwi	r4, 0
    bc      4, 2, _80007f5c
    lfs	f0, 0x2c(r3)
    stfs	f0, 0x2c(r1)
    lwz	r3, 0x2c(r1)
    rlwinm	r3, r3, 0, 1, 8
    addis	r3, r3, -0x7f80
    cmplwi	r3, 0
    bc      12, 2, _80007f5c
    li	r0, 0
_80007f5c:
    lwz	r31, 0x3c(r1)
    mr	r3, r0
    lwz	r30, 0x38(r1)
    addi	r1, r1, 0x40
    blr	
}

asm void fn_80007F70(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    rlwinm	r5, r5, 0xa, 0x10, 0x15
    lfd	f2, -0x7f20(r2)
    stw	r0, 0x84(r1)
    lis	r0, 0x4330
    xoris	r5, r5, 0x8000
    stw	r0, 0x10(r1)
    stw	r5, 0x14(r1)
    lfd	f0, 0x10(r1)
    stw	r31, 0x7c(r1)
    mr	r31, r4
    fsubs	f0, f0, f2
    stw	r30, 0x78(r1)
    mr	r30, r3
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    extsh	r3, r0
    bl      MathSin
    lfs	f2, -0x7f2c(r2)
    lfs	f0, -0x7f30(r2)
    fadds	f1, f2, f1
    lbz	r3, 0(r30)
    lbz	r0, 0(r31)
    cmplw	r3, r0
    fmuls	f1, f0, f1
    bc      4, 0, _80007ffc
    lfd	f0, -0x7f28(r2)
    stb	r3, 0(r31)
    fsub	f3, f0, f1
    stb	r0, 0(r30)
    frsp	f3, f3
    b       _80008000
_80007ffc:
    fmr	f3, f1
_80008000:
    lbz	r3, 1(r30)
    lbz	r0, 1(r31)
    cmplw	r3, r0
    bc      4, 0, _80008028
    lfd	f0, -0x7f28(r2)
    stb	r3, 1(r31)
    fsub	f5, f0, f1
    stb	r0, 1(r30)
    frsp	f5, f5
    b       _8000802c
_80008028:
    fmr	f5, f1
_8000802c:
    lbz	r3, 2(r30)
    lbz	r0, 2(r31)
    cmplw	r3, r0
    bc      4, 0, _80008054
    lfd	f0, -0x7f28(r2)
    stb	r3, 2(r31)
    fsub	f6, f0, f1
    stb	r0, 2(r30)
    frsp	f6, f6
    b       _80008058
_80008054:
    fmr	f6, f1
_80008058:
    lbz	r3, 3(r30)
    lbz	r0, 3(r31)
    cmplw	r3, r0
    bc      4, 0, _80008080
    lfd	f0, -0x7f28(r2)
    stb	r3, 3(r31)
    fsub	f7, f0, f1
    stb	r0, 3(r30)
    frsp	f7, f7
    b       _80008084
_80008080:
    fmr	f7, f1
_80008084:
    lbz	r7, 0(r30)
    lis	r6, 0x4330
    lbz	r5, 0(r31)
    stw	r7, 0x1c(r1)
    lbz	r8, 1(r30)
    stw	r6, 0x18(r1)
    lfd	f4, -0x7f18(r2)
    lfd	f0, 0x18(r1)
    stw	r5, 0x14(r1)
    fsubs	f2, f0, f4
    lbz	r4, 1(r31)
    stw	r6, 0x10(r1)
    lbz	r9, 2(r30)
    lfd	f0, 0x10(r1)
    stw	r8, 0x2c(r1)
    fsubs	f1, f0, f4
    lbz	r3, 2(r31)
    stw	r6, 0x28(r1)
    lbz	r0, 3(r31)
    fsubs	f1, f2, f1
    lfd	f0, 0x28(r1)
    stw	r4, 0x34(r1)
    fsubs	f2, f0, f4
    lbz	r10, 3(r30)
    stw	r6, 0x30(r1)
    fmuls	f1, f3, f1
    lwz	r31, 0x7c(r1)
    lfd	f0, 0x30(r1)
    stw	r9, 0x44(r1)
    fctiwz	f3, f1
    lwz	r30, 0x78(r1)
    fsubs	f1, f0, f4
    stw	r6, 0x40(r1)
    stfd	f3, 0x20(r1)
    fsubs	f1, f2, f1
    lfd	f0, 0x40(r1)
    stw	r3, 0x4c(r1)
    fsubs	f2, f0, f4
    lwz	r4, 0x24(r1)
    fmuls	f0, f5, f1
    stw	r6, 0x48(r1)
    clrlwi	r3, r4, 0x18
    subf	r4, r3, r7
    fctiwz	f3, f0
    lfd	f0, 0x48(r1)
    stw	r10, 0x5c(r1)
    fsubs	f1, f0, f4
    stw	r6, 0x58(r1)
    fsubs	f2, f2, f1
    lfd	f0, 0x58(r1)
    stw	r0, 0x64(r1)
    fsubs	f1, f0, f4
    fmuls	f0, f6, f2
    stw	r6, 0x60(r1)
    stfd	f3, 0x38(r1)
    fctiwz	f2, f0
    lfd	f0, 0x60(r1)
    lwz	r3, 0x3c(r1)
    fsubs	f0, f0, f4
    stb	r4, 8(r1)
    clrlwi	r0, r3, 0x18
    stfd	f2, 0x50(r1)
    subf	r3, r0, r8
    fsubs	f0, f1, f0
    lwz	r0, 0x54(r1)
    stb	r3, 9(r1)
    fmuls	f0, f7, f0
    clrlwi	r0, r0, 0x18
    subf	r0, r0, r9
    stb	r0, 0xa(r1)
    fctiwz	f0, f0
    stfd	f0, 0x68(r1)
    lwz	r0, 0x6c(r1)
    clrlwi	r0, r0, 0x18
    subf	r0, r0, r10
    stb	r0, 0xb(r1)
    lwz	r0, 0x84(r1)
    lwz	r3, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr	
}

asm void fn_800081C8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lwz	r5, 0(r4)
    stw	r0, 0x14(r1)
    addi	r4, r1, 8
    lwz	r0, 0(r3)
    addi	r3, r1, 0xc
    stw	r5, 8(r1)
    lwz	r5, -0x7d20(r13)
    stw	r0, 0xc(r1)
    bl      fn_80007F70
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80008204(void)
{
    nofralloc
    stwu	r1, -0x90(r1)
    mflr	r0
    stw	r0, 0x94(r1)
    stfd	f31, 0x80(r1)
    psq_st	f31, 0x88(r1), 0, 0
    stfd	f30, 0x70(r1)
    psq_st	f30, 0x78(r1), 0, 0
    stfd	f29, 0x60(r1)
    psq_st	f29, 0x68(r1), 0, 0
    stfd	f28, 0x50(r1)
    psq_st	f28, 0x58(r1), 0, 0
    stfd	f27, 0x40(r1)
    psq_st	f27, 0x48(r1), 0, 0
    lwz	r0, 0(r3)
    li	r3, 0x200
    stw	r0, 0x14(r1)
    bl      GXLoadMtxArray
    li	r3, 0
    bl      LightCtrl_SetCachedCullMode
    li	r3, 0
    bl      ModelClearCacheSlot_B28
    li	r3, 0
    li	r4, 0x1c
    bl      ModelSetCachedState_6B0
    li	r3, 0
    li	r4, 0xc
    bl      GXCachedSetTevSwapTable
    lwz	r0, 0x14(r1)
    addi	r4, r1, 0x10
    li	r3, 0
    stw	r0, 0x10(r1)
    bl      ModelSetCachedTex_704
    li	r3, 0
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 4
    bl      ModelSetCachedMaterial_570
    lwz	r0, -0x7530(r2)
    addi	r3, r1, 0xc
    stw	r0, 0xc(r1)
    bl      GXSetMatrixIndexA
    lwz	r0, -0x752c(r2)
    addi	r3, r1, 8
    stw	r0, 8(r1)
    bl      GXSetMatrixIndexB
    li	r3, 0
    li	r4, 0xf
    li	r5, 0xf
    li	r6, 0xf
    li	r7, 0xe
    bl      ModelSetCachedParam_F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_2F0
    li	r3, 0
    li	r4, 7
    li	r5, 7
    li	r6, 7
    li	r7, 6
    bl      ModelSetCachedParam_1F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_430
    li	r3, 1
    bl      ModelSetCachedNumTexGens
    li	r3, 1
    bl      GXSetChanAmbColorCached
    li	r3, 0
    bl      GXSetNumTexGensCached
    li	r3, 0
    bl      ModelSetCachedState_840
    li	r3, 0
    li	r4, 1
    li	r5, 0
    li	r6, 0
    bl      LightCtrl_SetCachedColor_1C
    li	r3, 1
    li	r4, 7
    li	r5, 1
    bl      GXSetTexGenCached
    li	r3, 0
    bl      Snd_SetOutputModeBit0
    addi	r3, r1, 0x18
    bl      GXGetProjectionv
    lfs	f29, 0x30(r1)
    lfs	f30, 0x2c(r1)
    lfs	f1, 0x18(r1)
    fdivs	f31, f29, f30
    bl      __cvt_fp2unsigned
    cmpwi	r3, 0
    bc      12, 2, _80008394
    b       _800083f4
_80008394:
    lfs	f8, -0x7f2c(r2)
    lfs	f2, 0x20(r1)
    fsubs	f1, f30, f8
    lfs	f0, -0x7f08(r2)
    lfs	f9, 0x28(r1)
    fsubs	f4, f8, f2
    lfs	f6, -0x7f0c(r2)
    fsubs	f3, f0, f2
    fdivs	f1, f29, f1
    lfs	f5, 0x1c(r1)
    lfs	f2, 0x24(r1)
    fsubs	f7, f31, f1
    fsubs	f1, f8, f9
    fsubs	f0, f0, f9
    fdivs	f6, f7, f6
    fsubs	f6, f31, f6
    fneg	f27, f6
    fdivs	f5, f27, f5
    fdivs	f2, f27, f2
    fmuls	f29, f4, f5
    fmuls	f31, f3, f5
    fmuls	f30, f1, f2
    fmuls	f28, f0, f2
    b       _80008454
_800083f4:
    lfs	f6, -0x7f2c(r2)
    lfs	f1, 0x1c(r1)
    fadds	f2, f6, f29
    lfs	f0, 0x24(r1)
    lfs	f7, 0x20(r1)
    fdivs	f9, f6, f1
    lfs	f3, -0x7f08(r2)
    lfs	f8, 0x28(r1)
    lfs	f1, -0x7f0c(r2)
    fneg	f5, f2
    fsubs	f4, f6, f7
    fsubs	f2, f3, f7
    fdivs	f5, f5, f30
    fsubs	f5, f31, f5
    fdivs	f7, f6, f0
    fdivs	f0, f5, f1
    fsubs	f5, f31, f0
    fsubs	f1, f6, f8
    fsubs	f0, f3, f8
    fneg	f27, f5
    fmuls	f29, f4, f9
    fmuls	f31, f2, f9
    fmuls	f30, f1, f7
    fmuls	f28, f0, f7
_80008454:
    bl      mtx_gpstack_push
    bl      QuatNormalizeCompare
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      GXLoadMatIdxTripleToXF
    bl      mtx_gpstack_pop
    li	r3, 0x80
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lis	r3, -0x33ff
    stfs	f31, -0x8000(r3)
    stfs	f30, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    stfs	f29, -0x8000(r3)
    stfs	f30, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    stfs	f29, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    psq_l	f31, 0x88(r1), 0, 0
    lfd	f31, 0x80(r1)
    psq_l	f30, 0x78(r1), 0, 0
    lfd	f30, 0x70(r1)
    psq_l	f29, 0x68(r1), 0, 0
    lfd	f29, 0x60(r1)
    psq_l	f28, 0x58(r1), 0, 0
    lfd	f28, 0x50(r1)
    psq_l	f27, 0x48(r1), 0, 0
    lwz	r0, 0x94(r1)
    lfd	f27, 0x40(r1)
    mtlr	r0
    addi	r1, r1, 0x90
    blr	
}

asm void fn_800084E8(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    stfd	f31, 0x70(r1)
    psq_st	f31, 0x78(r1), 0, 0
    stfd	f30, 0x60(r1)
    psq_st	f30, 0x68(r1), 0, 0
    stfd	f29, 0x50(r1)
    psq_st	f29, 0x58(r1), 0, 0
    stfd	f28, 0x40(r1)
    psq_st	f28, 0x48(r1), 0, 0
    stfd	f27, 0x30(r1)
    psq_st	f27, 0x38(r1), 0, 0
    stw	r31, 0x2c(r1)
    mr	r31, r4
    bl      fn_800087F4
    bl      mtx_gpstack_push
    bl      QuatNormalizeCompare
    bl      VIFlush
    bl      mtx_gpstack_pop
    addi	r3, r1, 8
    bl      GXGetProjectionv
    lfs	f1, -0x7f08(r2)
    li	r3, 0x80
    lfs	f0, 0xc(r1)
    li	r4, 0
    lfs	f5, -0x7f2c(r2)
    li	r5, 4
    lfs	f4, 0x14(r1)
    fdivs	f7, f1, f0
    lfs	f3, 4(r31)
    lfs	f6, 0(r31)
    lfs	f2, 0xc(r31)
    lfs	f1, 8(r31)
    lfs	f0, 0x10(r31)
    fmuls	f3, f3, f6
    fmuls	f2, f2, f6
    fdivs	f4, f5, f4
    fmuls	f1, f1, f6
    fmuls	f0, f0, f6
    fmuls	f30, f7, f3
    fmuls	f28, f7, f2
    fmuls	f29, f4, f1
    fmuls	f27, f4, f0
    bl      GXBegin
    lfs	f0, 0(r31)
    lis	r4, -0x33ff
    mr	r3, r31
    stfs	f30, -0x8000(r4)
    stfs	f29, -0x8000(r4)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f10(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f10(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, 0(r31)
    stfs	f28, -0x8000(r4)
    stfs	f29, -0x8000(r4)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f2c(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f10(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, 0(r31)
    stfs	f28, -0x8000(r4)
    stfs	f27, -0x8000(r4)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f2c(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f2c(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, 0(r31)
    stfs	f30, -0x8000(r4)
    stfs	f27, -0x8000(r4)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f10(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f2c(r2)
    stfs	f0, -0x8000(r4)
    bl      fn_80008A4C
    lfs	f31, 0(r31)
    li	r3, 0xb0
    li	r4, 0
    li	r5, 5
    bl      GXBegin
    lis	r3, -0x33ff
    stfs	f30, -0x8000(r3)
    stfs	f29, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f29, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f30, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f30, -0x8000(r3)
    stfs	f29, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    lwz	r0, 0x1c(r31)
    cmpwi	r0, 0
    bc      12, 2, _800087b8
    li	r3, 0xb0
    li	r4, 0
    li	r5, 5
    bl      GXBegin
    lfs	f2, 0x28(r31)
    lis	r6, -0x33ff
    lfs	f1, 0x24(r31)
    li	r3, 0xa8
    lfs	f0, 0x20(r31)
    li	r4, 0
    li	r5, 8
    stfs	f0, -0x8000(r6)
    stfs	f1, -0x8000(r6)
    stfs	f2, -0x8000(r6)
    lfs	f2, 0x34(r31)
    lfs	f1, 0x30(r31)
    lfs	f0, 0x2c(r31)
    stfs	f0, -0x8000(r6)
    stfs	f1, -0x8000(r6)
    stfs	f2, -0x8000(r6)
    lfs	f2, 0x40(r31)
    lfs	f1, 0x3c(r31)
    lfs	f0, 0x38(r31)
    stfs	f0, -0x8000(r6)
    stfs	f1, -0x8000(r6)
    stfs	f2, -0x8000(r6)
    lfs	f2, 0x4c(r31)
    lfs	f1, 0x48(r31)
    lfs	f0, 0x44(r31)
    stfs	f0, -0x8000(r6)
    stfs	f1, -0x8000(r6)
    stfs	f2, -0x8000(r6)
    lfs	f2, 0x28(r31)
    lfs	f1, 0x24(r31)
    lfs	f0, 0x20(r31)
    stfs	f0, -0x8000(r6)
    stfs	f1, -0x8000(r6)
    stfs	f2, -0x8000(r6)
    bl      GXBegin
    lfs	f2, 0x28(r31)
    lis	r3, -0x33ff
    lfs	f1, 0x24(r31)
    lfs	f0, 0x20(r31)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f30, -0x8000(r3)
    stfs	f29, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    lfs	f2, 0x34(r31)
    lfs	f1, 0x30(r31)
    lfs	f0, 0x2c(r31)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f29, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    lfs	f2, 0x40(r31)
    lfs	f1, 0x3c(r31)
    lfs	f0, 0x38(r31)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    lfs	f2, 0x4c(r31)
    lfs	f1, 0x48(r31)
    lfs	f0, 0x44(r31)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f30, -0x8000(r3)
    stfs	f27, -0x8000(r3)
    stfs	f31, -0x8000(r3)
_800087b8:
    psq_l	f31, 0x78(r1), 0, 0
    lfd	f31, 0x70(r1)
    psq_l	f30, 0x68(r1), 0, 0
    lfd	f30, 0x60(r1)
    psq_l	f29, 0x58(r1), 0, 0
    lfd	f29, 0x50(r1)
    psq_l	f28, 0x48(r1), 0, 0
    lfd	f28, 0x40(r1)
    psq_l	f27, 0x38(r1), 0, 0
    lfd	f27, 0x30(r1)
    lwz	r0, 0x84(r1)
    lwz	r31, 0x2c(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr	
}

asm void fn_800087F4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r4
    li	r4, 0
    bl      ModelCacheMaterialParams
    li	r3, 0
    li	r4, 1
    li	r5, 0
    li	r6, 0
    bl      LightCtrl_SetCachedColor_1C
    li	r3, 1
    li	r4, 3
    li	r5, 1
    bl      GXSetTexGenCached
    li	r3, 0
    bl      Snd_SetOutputModeBit0
    li	r3, 0
    bl      LightCtrl_SetCachedCullMode
    lwz	r0, 0x14(r31)
    cmpwi	r0, 1
    bc      12, 2, _80008930
    bc      4, 0, _80008a30
    cmpwi	r0, 0
    bc      4, 0, _80008860
    b       _80008a30
_80008860:
    li	r3, 0
    bl      ModelClearCacheSlot_B28
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl      ModelSetCachedPair5_B28
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0xff
    bl      ModelSetCachedMaterial_570
    li	r3, 0
    li	r4, 0
    bl      ModelSetCachedState_6B0
    li	r3, 0
    li	r4, 0xf
    li	r5, 8
    li	r6, 0xc
    li	r7, 0xf
    bl      ModelSetCachedParam_F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_2F0
    li	r3, 0
    li	r4, 7
    li	r5, 7
    li	r6, 7
    li	r7, 6
    bl      ModelSetCachedParam_1F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_430
    li	r3, 1
    bl      ModelSetCachedNumTexGens
    li	r3, 1
    bl      GXSetNumTexGensCached
    li	r3, 0
    bl      ModelSetCachedState_840
    li	r3, 0
    bl      GXSetChanAmbColorCached
    b       _80008a30
_80008930:
    li	r3, 0
    bl      ModelClearCacheSlot_B28
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl      ModelSetCachedPair5_B28
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0xff
    bl      ModelSetCachedMaterial_570
    li	r0, 0
    li	r3, 0xff
    stb	r3, 0xc(r1)
    addi	r4, r1, 8
    li	r3, 0
    stb	r0, 0xd(r1)
    stb	r0, 0xe(r1)
    lwz	r0, 0xc(r1)
    stw	r0, 8(r1)
    bl      ModelSetCachedTex_704
    li	r3, 0
    li	r4, 0xc
    bl      GXCachedSetTevSwapTable
    li	r3, 0
    li	r4, 0
    bl      ModelSetCachedState_6B0
    li	r3, 0
    li	r4, 0xe
    li	r5, 0xf
    li	r6, 9
    li	r7, 0xf
    bl      ModelSetCachedParam_F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_2F0
    li	r3, 0
    li	r4, 7
    li	r5, 7
    li	r6, 7
    li	r7, 6
    bl      ModelSetCachedParam_1F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_430
    li	r3, 1
    bl      ModelSetCachedNumTexGens
    li	r3, 1
    bl      GXSetNumTexGensCached
    li	r3, 0
    bl      ModelSetCachedState_840
    li	r3, 0
    bl      GXSetChanAmbColorCached
_80008a30:
    li	r3, 0x2200
    bl      GXLoadMtxArray
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80008A4C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r4, 1
    li	r5, 0
    stw	r0, 0x24(r1)
    li	r6, 0
    stw	r31, 0x1c(r1)
    mr	r31, r3
    li	r3, 0
    bl      LightCtrl_SetCachedColor_1C
    li	r3, 1
    li	r4, 3
    li	r5, 1
    bl      GXSetTexGenCached
    li	r3, 0
    bl      Snd_SetOutputModeBit0
    li	r3, 6
    li	r4, 0
    bl      GXSetLineWidthCached
    li	r3, 0
    bl      LightCtrl_SetCachedCullMode
    li	r3, 0
    bl      ModelClearCacheSlot_B28
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl      ModelSetCachedPair5_B28
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0xff
    bl      ModelSetCachedMaterial_570
    lwz	r0, 0x18(r31)
    addi	r4, r1, 8
    li	r3, 0
    stw	r0, 8(r1)
    bl      ModelSetCachedTex_704
    li	r3, 0
    li	r4, 0xc
    bl      GXCachedSetTevSwapTable
    li	r3, 0
    li	r4, 0x1c
    bl      ModelSetCachedState_6B0
    li	r3, 0
    li	r4, 0xf
    li	r5, 0xf
    li	r6, 0xf
    li	r7, 0xe
    bl      ModelSetCachedParam_F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_2F0
    li	r3, 0
    li	r4, 7
    li	r5, 7
    li	r6, 7
    li	r7, 6
    bl      ModelSetCachedParam_1F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_430
    li	r3, 1
    bl      ModelSetCachedNumTexGens
    li	r3, 1
    bl      GXSetNumTexGensCached
    li	r3, 0
    bl      ModelSetCachedState_840
    li	r3, 0
    bl      GXSetChanAmbColorCached
    li	r3, 0x200
    bl      GXLoadMtxArray
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80008BA8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    or	r6, r4, r3
    stw	r0, 0x14(r1)
    clrlwi.	r0, r6, 0x1e
    bc      12, 2, _80008bc8
    bl      memcpy
    b       _80008bdc
_80008bc8:
    clrlwi.	r0, r6, 0x1b
    bc      12, 2, _80008bd8
    bl      memcpy_fast
    b       _80008bdc
_80008bd8:
    bl      fn_800791E8
_80008bdc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80008BEC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    clrlwi.	r0, r3, 0x1b
    bc      4, 2, _80008c08
    bl      ModelLoadLcDma
    b       _80008c10
_80008c08:
    clrlwi	r4, r4, 0x18
    bl      memset
_80008c10:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80008C20(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stw	r31, 0x3c(r1)
    mr	r31, r4
    stw	r30, 0x38(r1)
    mr	r30, r3
    addi	r3, r1, 8
    lfs	f0, 0(r5)
    fneg	f0, f0
    stfs	f0, 8(r1)
    lfs	f0, 4(r5)
    fneg	f0, f0
    stfs	f0, 0xc(r1)
    lfs	f0, 8(r5)
    fneg	f0, f0
    stfs	f0, 0x10(r1)
    bl      PSVecNormalize3
    lfs	f0, -0x7f10(r2)
    fcmpu	cr0, f0, f1
    bc      4, 2, _80008c80
    mr	r3, r30
    bl      PSMTXLoadIdentityFused
    b       _80008d9c
_80008c80:
    lfs	f6, 4(r31)
    addi	r3, r1, 0x20
    lfs	f3, 0x10(r1)
    lfs	f5, 8(r31)
    lfs	f4, 8(r1)
    fmuls	f2, f6, f3
    lfs	f0, 0xc(r1)
    lfs	f7, 0(r31)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x20(r1)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x24(r1)
    stfs	f0, 0x28(r1)
    bl      PSVecNormalize3
    lfs	f0, -0x7f10(r2)
    fcmpu	cr0, f0, f1
    bc      4, 2, _80008cdc
    mr	r3, r30
    bl      PSMTXLoadIdentityFused
    b       _80008d9c
_80008cdc:
    lfs	f6, 0xc(r1)
    addi	r3, r1, 0x14
    lfs	f3, 0x28(r1)
    lfs	f5, 0x10(r1)
    lfs	f4, 0x20(r1)
    fmuls	f2, f6, f3
    lfs	f0, 0x24(r1)
    lfs	f7, 8(r1)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x14(r1)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x18(r1)
    stfs	f0, 0x1c(r1)
    bl      PSVecNormalize3
    lfs	f0, -0x7f10(r2)
    fcmpu	cr0, f0, f1
    bc      4, 2, _80008d38
    mr	r3, r30
    bl      PSMTXLoadIdentityFused
    b       _80008d9c
_80008d38:
    lwz	r3, -0x76c0(r13)
    lfs	f0, 0x20(r1)
    stfs	f0, 0(r3)
    lfs	f0, 0x14(r1)
    stfs	f0, 4(r3)
    lfs	f0, 8(r1)
    stfs	f0, 8(r3)
    lfs	f0, 0(r30)
    stfs	f0, 0xc(r3)
    lfs	f0, 0x24(r1)
    stfs	f0, 0x10(r3)
    lfs	f0, 0x18(r1)
    stfs	f0, 0x14(r3)
    lfs	f0, 0xc(r1)
    stfs	f0, 0x18(r3)
    lfs	f0, 4(r30)
    stfs	f0, 0x1c(r3)
    lfs	f0, 0x28(r1)
    stfs	f0, 0x20(r3)
    lfs	f0, 0x1c(r1)
    stfs	f0, 0x24(r3)
    lfs	f0, 0x10(r1)
    stfs	f0, 0x28(r3)
    lfs	f0, 8(r30)
    stfs	f0, 0x2c(r3)
_80008d9c:
    lwz	r0, 0x44(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

#pragma pop
