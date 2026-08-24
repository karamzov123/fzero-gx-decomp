#pragma force_active on

extern asm void OSReport(void);
extern asm void OSPanic(void);
extern asm void OSDisableInterrupts(void);
extern asm void OSRestoreInterrupts(void);
extern asm void OSGetTick(void);
extern asm void SITransferSync(void);
extern asm void SIGetResponseSync(void);
extern asm void fn_80013994(void);
extern asm void fn_800139E8(void);
extern asm void fn_80015EE8(void);
extern asm void AXFreeVoice(void);
extern asm void AXSetVoiceType_cached(void);
extern asm void axmix_device_ctrl_clear(void);
extern asm void axmix_device_ctrl_unlink(void);
extern asm void GXBegin(void);
extern asm void __GXSetTexRegion(void);
extern asm void GXLoadMatIdxTripleToXF(void);
extern asm void SndAllocBankEntry(void);
extern asm void QuatNormalizeCompare(void);
extern asm void GXLoadMtxArray(void);
extern asm void LightCtrl_SetCachedCullMode(void);
extern asm void LightCtrl_SetCachedColor_1C(void);
extern asm void LightCtrl_SetCachedPair_6C(void);
extern asm void ModelSetCachedParam_F0(void);
extern asm void ModelSetCachedParam_1F0(void);
extern asm void ModelSetCachedParam_2F0(void);
extern asm void ModelSetCachedParam_430(void);
extern asm void ModelSetCachedMaterial_570(void);
extern asm void ModelSetCachedNumTexGens(void);
extern asm void GXIntToFloatCopy(void);
extern asm void ModelSetCachedState_840(void);
extern asm void ModelClearCacheSlot_B28(void);
extern asm void GXSetNumTexGensCached(void);
extern asm void GXSetChanAmbColorCached(void);
extern asm void LightCtrl_SetCachedRec_C30(void);
extern asm void GXSetTexGenCached(void);
extern asm void fn_8007ED90(void);
extern asm void atan(void);
extern asm void expf(void);
extern asm void __msl_fp_helper(void);
extern unsigned char ARCInitHandle_bad_archive_format_str[34];
extern unsigned char arc_open_file_not_found_str[70];
extern unsigned char lbl_801327F8[163944];
extern unsigned char lbl_80199670[18720];
extern unsigned char lbl_8019DF90[132];
extern unsigned char lbl_8019E014[128];
extern unsigned char lbl_8019E094[128];
extern unsigned char lbl_8019E114[44];

asm void fn_80069AE0(void);
asm void fn_80069B10(void);
asm void AvHeapReleaseById(void);
asm void fn_80069FCC(void);
asm void fn_8006A1F8(void);
asm void ARCInitHandle(void);
asm void ARCOpen(void);
asm void ARCConvertPathToEntrynum(void);
asm void ARCEntryGetPath(void);
asm void ARCGetEntryPath(void);
asm void ARCGetStartAddr(void);
asm void ARCGetLength(void);
asm void ARCChangeDir(void);
asm void fn_8006AA20(void);
asm void fn_8006AA44(void);
asm void fn_8006AC44(void);
asm void fn_8006AE90(void);
asm void fn_8006AF94(void);
asm void fn_8006B048(void);
asm void fn_8006B188(void);
asm void fn_8006B224(void);
asm void fn_8006B294(void);
asm void fn_8006B3F0(void);
asm void fn_8006B470(void);
asm void fn_8006B55C(void);
asm void fn_8006B628(void);
asm void fn_8006B6F8(void);
asm void fn_8006B7B4(void);
asm void fn_8006B870(void);
asm void fn_8006B92C(void);
asm void fn_8006B99C(void);
asm void fn_8006BA74(void);
asm void fn_8006BB30(void);
asm void fn_8006BB74(void);
asm void fn_8006BB9C(void);
asm void fn_8006BBDC(void);
asm void fn_8006BC1C(void);
asm void fn_8006BC50(void);
asm void fn_8006BC84(void);
asm void fn_8006BCF8(void);
asm void fn_8006BE0C(void);
asm void fn_8006C134(void);
asm void fn_8006C17C(void);
asm void fn_8006C190(void);
asm void fn_8006C570(void);
asm void fn_8006C634(void);
asm void fn_8006C6E8(void);
asm void fn_8006C788(void);
asm void fn_8006C7E8(void);
asm void fn_8006C92C(void);
asm void fn_8006CCC8(void);
asm void fn_8006CD20(void);
asm void fn_8006CD2C(void);
asm void fn_8006CD40(void);
asm void fn_8006CD50(void);
asm void fn_8006CDA8(void);
asm void fn_8006CDFC(void);
asm void fn_8006CE1C(void);
asm void fn_8006CE44(void);

asm void fn_80069AE0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, -0x7740(r13)
    lwz	r3, 0x444(r3)
    rlwinm.	r0, r3, 0, 0x19, 0x19
    bc      4, 2, _80069b00
    bl      SndAllocBankEntry
_80069b00:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_80069B10(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addis	r31, r3, 0x6000
    stw	r30, 0x18(r1)
    clrlwi	r30, r4, 0x1c
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    li	r28, 0
    b       _80069cb8
_80069b3c:
    cmplwi	r31, 0x500
    bc      4, 2, _80069bf4
    clrlwi	r0, r28, 0x18
    lwz	r3, -0x7740(r13)
    mulli	r29, r0, 0x118
    add	r3, r3, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 4
    bc      4, 2, _80069cb4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      AXSetVoiceType_cached
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      axmix_device_ctrl_clear
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r4, -0x7740(r13)
    addi	r0, r29, 0x1434
    li	r5, 0
    addi	r3, r29, 0x1438
    stwx	r5, r4, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r3
    bl      axmix_device_ctrl_unlink
    lwz	r3, -0x7740(r13)
    addi	r5, r29, 0x1408
    lbzx	r0, r3, r5
    cmplwi	r0, 0xff
    bc      12, 2, _80069cb4
    li	r0, 0xff
    addi	r4, r29, 0x1420
    stbx	r0, r3, r5
    li	r6, 0
    addi	r3, r29, 0x1409
    addi	r0, r29, 0x1430
    lwz	r5, -0x7740(r13)
    stwx	r6, r5, r4
    lwz	r4, -0x7740(r13)
    stbx	r6, r4, r3
    lwz	r3, -0x7740(r13)
    stwx	r6, r3, r0
    b       _80069cb4
_80069bf4:
    cmplwi	r31, 0x1500
    bc      4, 2, _80069cb4
    clrlwi	r0, r28, 0x18
    lwz	r3, -0x7740(r13)
    mulli	r29, r0, 0x118
    add	r3, r3, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 4
    bc      4, 2, _80069cb4
    lbz	r0, 0x1413(r3)
    cmpw	r0, r30
    bc      4, 2, _80069cb4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      AXSetVoiceType_cached
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      axmix_device_ctrl_clear
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r4, -0x7740(r13)
    addi	r0, r29, 0x1434
    li	r5, 0
    addi	r3, r29, 0x1438
    stwx	r5, r4, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r3
    bl      axmix_device_ctrl_unlink
    lwz	r3, -0x7740(r13)
    addi	r5, r29, 0x1408
    lbzx	r0, r3, r5
    cmplwi	r0, 0xff
    bc      12, 2, _80069cb4
    li	r0, 0xff
    addi	r4, r29, 0x1420
    stbx	r0, r3, r5
    li	r6, 0
    addi	r3, r29, 0x1409
    addi	r0, r29, 0x1430
    lwz	r5, -0x7740(r13)
    stwx	r6, r5, r4
    lwz	r4, -0x7740(r13)
    stbx	r6, r4, r3
    lwz	r3, -0x7740(r13)
    stwx	r6, r3, r0
_80069cb4:
    addi	r28, r28, 1
_80069cb8:
    clrlwi	r0, r28, 0x18
    cmplwi	r0, 0x40
    bc      12, 0, _80069b3c
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void AvHeapReleaseById(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r28, r3
    mr	r27, r4
    mr	r29, r5
    bl      OSDisableInterrupts
    lis	r0, -0x5fee
    mr	r30, r3
    cmpw	r27, r0
    bc      12, 2, _80069d4c
    bc      4, 0, _80069d3c
    lis	r3, -0x6000
    addi	r0, r3, 0x1500
    cmpw	r27, r0
    bc      12, 2, _80069e70
    bc      4, 0, _80069f9c
    addi	r0, r3, 0x500
    cmpw	r27, r0
    bc      12, 2, _80069e70
    b       _80069f9c
_80069d3c:
    lis	r0, -0x5fde
    cmpw	r27, r0
    bc      12, 2, _80069e80
    b       _80069f9c
_80069d4c:
    rlwinm	r31, r28, 0, 0x1b, 0x1b
    clrlwi	r11, r28, 0x10
    cmpwi	r31, 0x10
    bc      4, 2, _80069de0
    li	r12, 0
    clrlwi	r10, r29, 0x19
    b       _80069dd0
_80069d68:
    rlwinm	r4, r12, 4, 0x14, 0x1b
    lwz	r3, -0x7740(r13)
    addi	r9, r4, 0x496
    addi	r12, r12, 8
    stbx	r10, r3, r9
    addi	r0, r9, 0x10
    addi	r7, r9, 0x20
    addi	r6, r9, 0x30
    lwz	r8, -0x7740(r13)
    addi	r5, r9, 0x40
    addi	r4, r9, 0x50
    addi	r3, r9, 0x60
    stbx	r10, r8, r0
    addi	r0, r9, 0x70
    lwz	r8, -0x7740(r13)
    stbx	r10, r8, r7
    lwz	r7, -0x7740(r13)
    stbx	r10, r7, r6
    lwz	r6, -0x7740(r13)
    stbx	r10, r6, r5
    lwz	r5, -0x7740(r13)
    stbx	r10, r5, r4
    lwz	r4, -0x7740(r13)
    stbx	r10, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r10, r3, r0
_80069dd0:
    clrlwi	r0, r12, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80069d68
    b       _80069df4
_80069de0:
    lwz	r3, -0x7740(r13)
    rlwinm	r0, r11, 4, 0x18, 0x1b
    clrlwi	r4, r29, 0x19
    add	r3, r3, r0
    stb	r4, 0x496(r3)
_80069df4:
    li	r29, 0
    clrlwi	r27, r11, 0x1c
    mr	r28, r29
_80069e00:
    lwz	r0, -0x7740(r13)
    add	r4, r0, r28
    lbz	r0, 0x1408(r4)
    cmplwi	r0, 4
    bc      4, 2, _80069e5c
    cmpwi	r31, 0x10
    bc      12, 2, _80069e28
    lbz	r0, 0x1413(r4)
    cmpw	r27, r0
    bc      4, 2, _80069e5c
_80069e28:
    lwz	r3, 0x1424(r4)
    lbz	r4, 0x1413(r4)
    bl      fn_80069FCC
    lwz	r4, -0x7740(r13)
    addi	r0, r28, 0x141c
    add	r5, r4, r28
    lwz	r4, 0x151c(r5)
    srawi	r4, r4, 0x10
    subf	r4, r4, r3
    slwi	r4, r4, 0x10
    stw	r4, 0x148c(r5)
    lwz	r4, -0x7740(r13)
    stwx	r3, r4, r0
_80069e5c:
    addi	r29, r29, 1
    addi	r28, r28, 0x118
    cmplwi	r29, 0x40
    bc      12, 0, _80069e00
    b       _80069fac
_80069e70:
    mr	r3, r27
    mr	r4, r28
    bl      fn_80069B10
    b       _80069fac
_80069e80:
    rlwinm	r31, r28, 0, 0x1b, 0x1b
    clrlwi	r10, r28, 0x10
    cmpwi	r31, 0x10
    bc      4, 2, _80069f10
    li	r11, 0
    b       _80069f00
_80069e98:
    rlwinm	r4, r11, 1, 0x17, 0x1e
    lwz	r3, -0x7740(r13)
    addi	r9, r4, 0x5a14
    addi	r11, r11, 8
    sthx	r29, r3, r9
    addi	r0, r9, 2
    addi	r7, r9, 4
    addi	r6, r9, 6
    lwz	r8, -0x7740(r13)
    addi	r5, r9, 8
    addi	r4, r9, 0xa
    addi	r3, r9, 0xc
    sthx	r29, r8, r0
    addi	r0, r9, 0xe
    lwz	r8, -0x7740(r13)
    sthx	r29, r8, r7
    lwz	r7, -0x7740(r13)
    sthx	r29, r7, r6
    lwz	r6, -0x7740(r13)
    sthx	r29, r6, r5
    lwz	r5, -0x7740(r13)
    sthx	r29, r5, r4
    lwz	r4, -0x7740(r13)
    sthx	r29, r4, r3
    lwz	r3, -0x7740(r13)
    sthx	r29, r3, r0
_80069f00:
    clrlwi	r0, r11, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80069e98
    b       _80069f20
_80069f10:
    lwz	r3, -0x7740(r13)
    rlwinm	r0, r10, 1, 0x1b, 0x1e
    add	r3, r3, r0
    sth	r29, 0x5a14(r3)
_80069f20:
    li	r29, 0
    clrlwi	r28, r10, 0x1c
    mr	r27, r29
_80069f2c:
    lwz	r0, -0x7740(r13)
    add	r4, r0, r27
    lbz	r0, 0x1408(r4)
    cmplwi	r0, 4
    bc      4, 2, _80069f88
    cmpwi	r31, 0x10
    bc      12, 2, _80069f54
    lbz	r0, 0x1413(r4)
    cmpw	r28, r0
    bc      4, 2, _80069f88
_80069f54:
    lwz	r3, 0x1424(r4)
    lbz	r4, 0x1413(r4)
    bl      fn_80069FCC
    lwz	r4, -0x7740(r13)
    addi	r0, r27, 0x141c
    add	r5, r4, r27
    lwz	r4, 0x151c(r5)
    srawi	r4, r4, 0x10
    subf	r4, r4, r3
    slwi	r4, r4, 0x10
    stw	r4, 0x148c(r5)
    lwz	r4, -0x7740(r13)
    stwx	r3, r4, r0
_80069f88:
    addi	r29, r29, 1
    addi	r27, r27, 0x118
    cmplwi	r29, 0x40
    bc      12, 0, _80069f2c
    b       _80069fac
_80069f9c:
    mr	r3, r30
    bl      OSRestoreInterrupts
    li	r3, -1
    b       _80069fb8
_80069fac:
    mr	r3, r30
    bl      OSRestoreInterrupts
    li	r3, 0
_80069fb8:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_80069FCC(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stfd	f31, 0x40(r1)
    psq_st	f31, 0x48(r1), 0, 0
    stw	r31, 0x3c(r1)
    lwz	r5, -0x7740(r13)
    mr	r31, r4
    lbz	r0, 0x2c(r3)
    li	r7, 0
    lbz	r4, 0x45b(r5)
    lbz	r6, 9(r3)
    slwi	r0, r0, 7
    slwi	r3, r4, 4
    add	r3, r5, r3
    cmplwi	r6, 0
    lwz	r4, 8(r3)
    add	r3, r4, r0
    lwz	r0, 0x20(r4)
    addi	r4, r3, 4
    add	r4, r0, r4
    bc      4, 1, _8006a064
    cmplwi	r6, 8
    addi	r0, r6, -8
    bc      4, 1, _8006a058
    clrlwi	r0, r0, 0x18
    b       _8006a040
_8006a038:
    addi	r4, r4, 8
    addi	r7, r7, 8
_8006a040:
    clrlwi	r3, r7, 0x18
    cmplw	r3, r0
    bc      12, 0, _8006a038
    b       _8006a058
_8006a050:
    addi	r4, r4, 1
    addi	r7, r7, 1
_8006a058:
    clrlwi	r0, r7, 0x18
    cmplw	r0, r6
    bc      12, 0, _8006a050
_8006a064:
    lbz	r3, 0(r4)
    cmplwi	r3, 0
    bc      12, 2, _8006a0a4
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lfd	f2, -0x7ad8(r2)
    stw	r0, 8(r1)
    lfs	f0, -0x7ae8(r2)
    lfd	f1, 8(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7af0(r2)
    fmul	f31, f0, f1
    frsp	f31, f31
    b       _8006a0a8
_8006a0a4:
    lfs	f31, -0x7ae4(r2)
_8006a0a8:
    lwz	r3, -0x7740(r13)
    lbz	r3, 0x5a08(r3)
    cmplwi	r3, 0
    bc      12, 2, _8006a0f0
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f2, -0x7ad8(r2)
    stw	r0, 0x10(r1)
    lfs	f0, -0x7ae0(r2)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7af0(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f31, f31, f0
    b       _8006a0f4
_8006a0f0:
    lfs	f31, -0x7ae4(r2)
_8006a0f4:
    lwz	r3, -0x7740(r13)
    rlwinm	r0, r31, 4, 0x14, 0x1b
    clrlwi	r31, r31, 0x18
    add	r3, r3, r0
    lbz	r3, 0x496(r3)
    cmplwi	r3, 0
    bc      12, 2, _8006a148
    lis	r0, 0x4330
    stw	r3, 0x1c(r1)
    lfd	f2, -0x7ad8(r2)
    stw	r0, 0x18(r1)
    lfs	f0, -0x7ae0(r2)
    lfd	f1, 0x18(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7af0(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f31, f31, f0
    b       _8006a14c
_8006a148:
    lfs	f31, -0x7ae4(r2)
_8006a14c:
    lwz	r3, -0x7740(r13)
    slwi	r0, r31, 1
    lbz	r4, 0x461(r3)
    add	r3, r3, r0
    lha	r31, 0x5a14(r3)
    cmplwi	r4, 0
    bc      12, 2, _8006a1a0
    lis	r0, 0x4330
    stw	r4, 0x24(r1)
    lfd	f2, -0x7ad8(r2)
    stw	r0, 0x20(r1)
    lfs	f0, -0x7ae0(r2)
    lfd	f1, 0x20(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7af0(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f1, f31, f0
    b       _8006a1a4
_8006a1a0:
    lfs	f1, -0x7ae4(r2)
_8006a1a4:
    lfs	f0, -0x7adc(r2)
    lwz	r3, -0x7740(r13)
    fmuls	f0, f0, f1
    lha	r0, 0x5a10(r3)
    fctiwz	f0, f0
    add	r31, r31, r0
    stfd	f0, 0x28(r1)
    lwz	r0, 0x2c(r1)
    extsh	r0, r0
    add	r31, r31, r0
    cmpwi	r31, -0x3c0
    bc      4, 0, _8006a1d8
    li	r31, -0x3c0
_8006a1d8:
    mr	r3, r31
    psq_l	f31, 0x48(r1), 0, 0
    lwz	r0, 0x54(r1)
    lfd	f31, 0x40(r1)
    lwz	r31, 0x3c(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_8006A1F8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    li	r4, 0x7f
    li	r5, 1
    li	r0, 2
    stmw	r26, 8(r1)
    lwz	r3, -0x7740(r13)
    stb	r4, 0x5a08(r3)
    li	r4, 0
    lwz	r3, -0x7740(r13)
    stw	r5, 0x5a0c(r3)
    mtctr	r0
_8006a224:
    lwz	r5, -0x7740(r13)
    addi	r0, r4, 0x496
    li	r3, 0x7f
    addi	r6, r4, 0x497
    stbx	r3, r5, r0
    li	r0, 0x40
    addi	r5, r4, 0x4a6
    addi	r30, r4, 0x4a7
    lwz	r7, -0x7740(r13)
    addi	r29, r4, 0x4b6
    addi	r28, r4, 0x4b7
    addi	r27, r4, 0x4c6
    stbx	r0, r7, r6
    addi	r26, r4, 0x4c7
    addi	r12, r4, 0x4d6
    addi	r11, r4, 0x4d7
    lwz	r6, -0x7740(r13)
    addi	r10, r4, 0x4e6
    addi	r9, r4, 0x4e7
    addi	r8, r4, 0x4f6
    stbx	r3, r6, r5
    addi	r7, r4, 0x4f7
    addi	r6, r4, 0x506
    addi	r5, r4, 0x507
    lwz	r31, -0x7740(r13)
    addi	r4, r4, 0x80
    stbx	r0, r31, r30
    lwz	r30, -0x7740(r13)
    stbx	r3, r30, r29
    lwz	r29, -0x7740(r13)
    stbx	r0, r29, r28
    lwz	r28, -0x7740(r13)
    stbx	r3, r28, r27
    lwz	r27, -0x7740(r13)
    stbx	r0, r27, r26
    lwz	r26, -0x7740(r13)
    stbx	r3, r26, r12
    lwz	r12, -0x7740(r13)
    stbx	r0, r12, r11
    lwz	r11, -0x7740(r13)
    stbx	r3, r11, r10
    lwz	r10, -0x7740(r13)
    stbx	r0, r10, r9
    lwz	r9, -0x7740(r13)
    stbx	r3, r9, r8
    lwz	r8, -0x7740(r13)
    stbx	r0, r8, r7
    lwz	r7, -0x7740(r13)
    stbx	r3, r7, r6
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r5
    bc      16, 0, _8006a224
    li	r0, 8
    li	r4, 0
    mtctr	r0
_8006a300:
    lwz	r5, -0x7740(r13)
    addi	r0, r4, 0x1430
    li	r3, 0
    addi	r6, r4, 0x1413
    stwx	r3, r5, r0
    li	r0, 0xff
    addi	r5, r4, 0x1548
    addi	r27, r4, 0x152b
    lwz	r7, -0x7740(r13)
    addi	r28, r4, 0x1660
    addi	r29, r4, 0x1643
    addi	r30, r4, 0x1778
    stbx	r0, r7, r6
    addi	r31, r4, 0x175b
    addi	r12, r4, 0x1890
    addi	r11, r4, 0x1873
    lwz	r6, -0x7740(r13)
    addi	r10, r4, 0x19a8
    addi	r9, r4, 0x198b
    addi	r8, r4, 0x1ac0
    stwx	r3, r6, r5
    addi	r7, r4, 0x1aa3
    addi	r6, r4, 0x1bd8
    addi	r5, r4, 0x1bbb
    lwz	r26, -0x7740(r13)
    addi	r4, r4, 0x8c0
    stbx	r0, r26, r27
    lwz	r27, -0x7740(r13)
    stwx	r3, r27, r28
    lwz	r28, -0x7740(r13)
    stbx	r0, r28, r29
    lwz	r29, -0x7740(r13)
    stwx	r3, r29, r30
    lwz	r30, -0x7740(r13)
    stbx	r0, r30, r31
    lwz	r31, -0x7740(r13)
    stwx	r3, r31, r12
    lwz	r12, -0x7740(r13)
    stbx	r0, r12, r11
    lwz	r11, -0x7740(r13)
    stwx	r3, r11, r10
    lwz	r10, -0x7740(r13)
    stbx	r0, r10, r9
    lwz	r9, -0x7740(r13)
    stwx	r3, r9, r8
    lwz	r8, -0x7740(r13)
    stbx	r0, r8, r7
    lwz	r7, -0x7740(r13)
    stwx	r3, r7, r6
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r5
    bc      16, 0, _8006a300
    lmw	r26, 8(r1)
    addi	r1, r1, 0x20
    blr
}

asm void ARCInitHandle(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, 0
    stw	r30, 0x10(r1)
    mr	r30, r3
    lwz	r3, 0(r3)
    addis	r0, r3, -0x55aa
    cmplwi	r0, 0x382d
    bc      12, 2, _8006a420
    lis     r3, ARCInitHandle_bad_archive_format_str@ha
    crxor	6, 6, 6
    addi	r5, r3, ARCInitHandle_bad_archive_format_str@l
    addi	r3, r13, -0x7db0
    li	r4, 0x3b
    bl      OSPanic
_8006a420:
    stw	r30, 0(r31)
    li	r0, 0
    li	r3, 1
    lwz	r4, 4(r30)
    add	r5, r30, r4
    stw	r5, 4(r31)
    lwz	r4, 0xc(r30)
    add	r4, r30, r4
    stw	r4, 8(r31)
    lwz	r4, 8(r5)
    stw	r4, 0xc(r31)
    lwz	r4, 0xc(r31)
    mulli	r4, r4, 0xc
    add	r4, r5, r4
    stw	r4, 0x10(r31)
    lwz	r4, 8(r30)
    stw	r4, 0x14(r31)
    stw	r0, 0x18(r31)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void ARCOpen(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0xa8(r1)
    stw	r31, 0xa4(r1)
    stw	r30, 0xa0(r1)
    mr	r30, r5
    stw	r29, 0x9c(r1)
    addi	r29, r4, 0
    stw	r28, 0x98(r1)
    addi	r28, r3, 0
    lwz	r31, 4(r3)
    bl      ARCConvertPathToEntrynum
    cmpwi	r3, 0
    bc      4, 0, _8006a4e8
    addi	r3, r28, 0
    addi	r4, r1, 0x14
    li	r5, 0x80
    bl      ARCGetEntryPath
    lis     r3, arc_open_file_not_found_str@ha
    crxor	6, 6, 6
    addi	r3, r3, arc_open_file_not_found_str@l
    addi	r4, r29, 0
    addi	r5, r1, 0x14
    bl      OSReport
    li	r3, 0
    b       _8006a534
_8006a4e8:
    bc      12, 0, _8006a510
    mulli	r3, r3, 0xc
    lwzx	r0, r31, r3
    rlwinm.	r0, r0, 0, 0, 7
    bc      4, 2, _8006a504
    li	r0, 0
    b       _8006a508
_8006a504:
    li	r0, 1
_8006a508:
    cmpwi	r0, 0
    bc      12, 2, _8006a518
_8006a510:
    li	r3, 0
    b       _8006a534
_8006a518:
    stw	r28, 0(r30)
    add	r4, r31, r3
    li	r3, 1
    lwz	r0, 4(r4)
    stw	r0, 4(r30)
    lwz	r0, 8(r4)
    stw	r0, 8(r30)
_8006a534:
    lwz	r0, 0xac(r1)
    lwz	r31, 0xa4(r1)
    lwz	r30, 0xa0(r1)
    mtlr	r0
    lwz	r29, 0x9c(r1)
    lwz	r28, 0x98(r1)
    addi	r1, r1, 0xa8
    blr
}

asm void ARCConvertPathToEntrynum(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x50(r1)
    stmw	r21, 0x24(r1)
    mr	r24, r3
    mr	r25, r4
    lwz	r3, 0x18(r3)
    lwz	r26, 4(r24)
_8006a574:
    lbz	r0, 0(r25)
    cmplwi	r0, 0
    bc      4, 2, _8006a584
    b       _8006a754
_8006a584:
    cmplwi	r0, 0x2f
    bc      4, 2, _8006a598
    li	r3, 0
    addi	r25, r25, 1
    b       _8006a574
_8006a598:
    cmplwi	r0, 0x2e
    bc      4, 2, _8006a600
    lbz	r0, 1(r25)
    cmplwi	r0, 0x2e
    bc      4, 2, _8006a5e4
    lbz	r0, 2(r25)
    cmplwi	r0, 0x2f
    bc      4, 2, _8006a5cc
    mulli	r3, r3, 0xc
    addi	r0, r3, 4
    lwzx	r3, r26, r0
    addi	r25, r25, 3
    b       _8006a574
_8006a5cc:
    cmplwi	r0, 0
    bc      4, 2, _8006a600
    mulli	r0, r3, 0xc
    add	r3, r26, r0
    lwz	r3, 4(r3)
    b       _8006a754
_8006a5e4:
    cmplwi	r0, 0x2f
    bc      4, 2, _8006a5f4
    addi	r25, r25, 2
    b       _8006a574
_8006a5f4:
    cmplwi	r0, 0
    bc      4, 2, _8006a600
    b       _8006a754
_8006a600:
    mr	r4, r25
    b       _8006a60c
_8006a608:
    addi	r4, r4, 1
_8006a60c:
    lbz	r0, 0(r4)
    cmplwi	r0, 0
    bc      12, 2, _8006a620
    cmplwi	r0, 0x2f
    bc      4, 2, _8006a608
_8006a620:
    cmplwi	r0, 0
    bc      4, 2, _8006a630
    li	r31, 0
    b       _8006a634
_8006a630:
    li	r31, 1
_8006a634:
    mulli	r0, r3, 0xc
    subf	r28, r25, r4
    addi	r27, r3, 1
    add	r30, r26, r0
    b       _8006a720
_8006a648:
    mulli	r0, r27, 0xc
    add	r29, r26, r0
    lwz	r4, 0(r29)
    rlwinm.	r0, r4, 0, 0, 7
    bc      4, 2, _8006a664
    li	r0, 0
    b       _8006a668
_8006a664:
    li	r0, 1
_8006a668:
    cmpwi	r0, 0
    bc      4, 2, _8006a678
    cmpwi	r31, 1
    bc      12, 2, _8006a6f0
_8006a678:
    lwz	r3, 0x10(r24)
    clrlwi	r0, r4, 8
    addi	r22, r25, 0
    add	r21, r3, r0
    b       _8006a6bc
_8006a68c:
    lbz	r3, 0(r21)
    addi	r21, r21, 1
    bl      fn_8007ED90
    lbz	r0, 0(r22)
    addi	r23, r3, 0
    addi	r22, r22, 1
    mr	r3, r0
    bl      fn_8007ED90
    cmpw	r3, r23
    bc      12, 2, _8006a6bc
    li	r0, 0
    b       _8006a6e8
_8006a6bc:
    lbz	r0, 0(r21)
    cmplwi	r0, 0
    bc      4, 2, _8006a68c
    lbz	r0, 0(r22)
    cmplwi	r0, 0x2f
    bc      12, 2, _8006a6dc
    cmplwi	r0, 0
    bc      4, 2, _8006a6e4
_8006a6dc:
    li	r0, 1
    b       _8006a6e8
_8006a6e4:
    li	r0, 0
_8006a6e8:
    cmpwi	r0, 1
    bc      12, 2, _8006a734
_8006a6f0:
    lwz	r0, 0(r29)
    rlwinm.	r0, r0, 0, 0, 7
    bc      4, 2, _8006a704
    li	r0, 0
    b       _8006a708
_8006a704:
    li	r0, 1
_8006a708:
    cmpwi	r0, 0
    bc      12, 2, _8006a718
    lwz	r0, 8(r29)
    b       _8006a71c
_8006a718:
    addi	r0, r27, 1
_8006a71c:
    mr	r27, r0
_8006a720:
    lwz	r0, 8(r30)
    cmplw	r27, r0
    bc      12, 0, _8006a648
    li	r3, -1
    b       _8006a754
_8006a734:
    cmpwi	r31, 0
    bc      4, 2, _8006a744
    mr	r3, r27
    b       _8006a754
_8006a744:
    add	r25, r28, r25
    addi	r3, r27, 0
    addi	r25, r25, 1
    b       _8006a574
_8006a754:
    lmw	r21, 0x24(r1)
    lwz	r0, 0x54(r1)
    addi	r1, r1, 0x50
    mtlr	r0
    blr
}

asm void ARCEntryGetPath(void)
{
    nofralloc
    mflr	r0
    cmplwi	r4, 0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    addi	r30, r6, 0
    stw	r29, 0x24(r1)
    addi	r29, r5, 0
    stw	r28, 0x20(r1)
    lwz	r7, 4(r3)
    bc      4, 2, _8006a7a0
    li	r3, 0
    b       _8006a8ac
_8006a7a0:
    mulli	r0, r4, 0xc
    lwz	r8, 0x10(r3)
    add	r4, r7, r0
    lwzx	r0, r7, r0
    lwz	r4, 4(r4)
    clrlwi	r0, r0, 8
    cmplwi	r4, 0
    add	r31, r8, r0
    bc      4, 2, _8006a7cc
    li	r3, 0
    b       _8006a84c
_8006a7cc:
    mulli	r4, r4, 0xc
    lwzx	r0, r7, r4
    add	r4, r7, r4
    lwz	r4, 4(r4)
    addi	r5, r29, 0
    clrlwi	r0, r0, 8
    addi	r6, r30, 0
    add	r28, r8, r0
    bl      ARCEntryGetPath
    cmplw	r3, r30
    bc      4, 2, _8006a7fc
    b       _8006a84c
_8006a7fc:
    addi	r0, r3, 0
    addi	r3, r3, 1
    li	r4, 0x2f
    subf	r6, r3, r30
    stbx	r4, r29, r0
    addi	r4, r6, 0
    add	r5, r29, r3
    b       _8006a830
_8006a81c:
    lbz	r0, 0(r28)
    addi	r28, r28, 1
    addi	r4, r4, -1
    stb	r0, 0(r5)
    addi	r5, r5, 1
_8006a830:
    cmplwi	r4, 0
    bc      12, 2, _8006a844
    lbz	r0, 0(r28)
    cmplwi	r0, 0
    bc      4, 2, _8006a81c
_8006a844:
    subf	r0, r4, r6
    add	r3, r3, r0
_8006a84c:
    cmplw	r3, r30
    bc      4, 2, _8006a858
    b       _8006a8ac
_8006a858:
    addi	r0, r3, 0
    addi	r3, r3, 1
    li	r4, 0x2f
    subf	r7, r3, r30
    stbx	r4, r29, r0
    addi	r6, r31, 0
    addi	r4, r7, 0
    add	r5, r29, r3
    b       _8006a890
_8006a87c:
    lbz	r0, 0(r6)
    addi	r6, r6, 1
    addi	r4, r4, -1
    stb	r0, 0(r5)
    addi	r5, r5, 1
_8006a890:
    cmplwi	r4, 0
    bc      12, 2, _8006a8a4
    lbz	r0, 0(r6)
    cmplwi	r0, 0
    bc      4, 2, _8006a87c
_8006a8a4:
    subf	r0, r4, r7
    add	r3, r3, r0
_8006a8ac:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    mtlr	r0
    lwz	r29, 0x24(r1)
    lwz	r28, 0x20(r1)
    addi	r1, r1, 0x30
    blr
}

asm void ARCGetEntryPath(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    addi	r29, r5, 0
    addi	r6, r29, 0
    stw	r28, 0x18(r1)
    addi	r28, r4, 0
    addi	r5, r28, 0
    lwz	r30, 0x18(r3)
    lwz	r31, 4(r3)
    addi	r4, r30, 0
    bl      ARCEntryGetPath
    cmplw	r3, r29
    bc      4, 2, _8006a920
    li	r0, 0
    add	r3, r28, r29
    stb	r0, -1(r3)
    b       _8006a974
_8006a920:
    mulli	r0, r30, 0xc
    lwzx	r0, r31, r0
    rlwinm.	r0, r0, 0, 0, 7
    bc      4, 2, _8006a938
    li	r0, 0
    b       _8006a93c
_8006a938:
    li	r0, 1
_8006a93c:
    cmpwi	r0, 0
    bc      12, 2, _8006a968
    addi	r0, r29, -1
    cmplw	r3, r0
    bc      4, 2, _8006a95c
    li	r0, 0
    stbx	r0, r28, r3
    b       _8006a974
_8006a95c:
    li	r0, 0x2f
    stbx	r0, r28, r3
    addi	r3, r3, 1
_8006a968:
    li	r0, 0
    stbx	r0, r28, r3
    li	r0, 1
_8006a974:
    mr	r3, r0
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    mtlr	r0
    lwz	r29, 0x1c(r1)
    lwz	r28, 0x18(r1)
    addi	r1, r1, 0x28
    blr
}

asm void ARCGetStartAddr(void)
{
    nofralloc
    lwz	r4, 0(r3)
    lwz	r0, 4(r3)
    lwz	r3, 0(r4)
    add	r3, r3, r0
    blr
}

asm void ARCGetLength(void)
{
    nofralloc
    lwz	r3, 8(r3)
    blr
}

asm void ARCChangeDir(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      ARCConvertPathToEntrynum
    cmpwi	r3, 0
    lwz	r4, 4(r31)
    bc      12, 0, _8006a9fc
    mulli	r0, r3, 0xc
    lwzx	r0, r4, r0
    rlwinm.	r0, r0, 0, 0, 7
    bc      4, 2, _8006a9f0
    li	r0, 0
    b       _8006a9f4
_8006a9f0:
    li	r0, 1
_8006a9f4:
    cmpwi	r0, 0
    bc      4, 2, _8006aa04
_8006a9fc:
    li	r3, 0
    b       _8006aa0c
_8006aa04:
    stw	r3, 0x18(r31)
    li	r3, 1
_8006aa0c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void fn_8006AA20(void)
{
    nofralloc
    cmpwi	r4, 0
    beqlr	
    mulli	r0, r3, 0x1248
    lis     r3, lbl_80199670@ha
    li	r4, -1
    addi	r3, r3, lbl_80199670@l
    add	r3, r3, r0
    stb	r4, 0x4d(r3)
    blr
}

asm void fn_8006AA44(void)
{
    nofralloc
    lbz	r6, 2(r4)
    lbz	r0, 0x20(r5)
    xor	r0, r6, r0
    rlwinm.	r0, r0, 0, 0x1c, 0x1c
    bc      12, 2, _8006aaec
    li	r6, 0x40
    li	r0, 0x50
    stw	r6, 0x28(r5)
    stb	r0, 4(r5)
    stb	r0, 5(r5)
    lbz	r6, 5(r5)
    lbz	r0, 4(r5)
    subf	r0, r6, r0
    srawi	r0, r0, 1
    addze	r0, r0
    cmpwi	r0, -0x80
    bc      4, 0, _8006aa90
    li	r0, -0x80
    b       _8006aa9c
_8006aa90:
    cmpwi	r0, 0x7f
    bc      4, 1, _8006aa9c
    li	r0, 0x7f
_8006aa9c:
    stb	r0, 6(r5)
    li	r0, 0xb0
    stb	r0, 0xe(r5)
    stb	r0, 0xf(r5)
    lbz	r6, 0xf(r5)
    lbz	r0, 0xe(r5)
    subf	r0, r6, r0
    srawi	r0, r0, 1
    addze	r0, r0
    cmpwi	r0, -0x80
    bc      4, 0, _8006aad0
    li	r0, -0x80
    b       _8006aadc
_8006aad0:
    cmpwi	r0, 0x7f
    bc      4, 1, _8006aadc
    li	r0, 0x7f
_8006aadc:
    stb	r0, 0x10(r5)
    li	r0, 0xa
    stb	r0, 0x18(r5)
    stb	r0, 0x19(r5)
_8006aaec:
    lwz	r6, 0x28(r5)
    cmpwi	r6, 0
    bc      4, 1, _8006ab14
    addi	r4, r6, -1
    li	r0, 0
    stw	r4, 0x28(r5)
    stb	r0, 5(r3)
    stb	r0, 4(r3)
    stb	r0, 6(r3)
    blr
_8006ab14:
    lbz	r0, 2(r4)
    rlwinm.	r0, r0, 0, 0x1c, 0x1c
    bc      12, 2, _8006ac30
    lbz	r8, 4(r4)
    lbz	r7, 4(r5)
    lbz	r9, 0x18(r5)
    cmpw	r8, r7
    lbz	r0, 0xe(r5)
    bc      4, 0, _8006ab40
    stb	r8, 4(r5)
    mr	r7, r8
_8006ab40:
    cmpw	r8, r0
    bc      4, 1, _8006ab50
    stb	r8, 0xe(r5)
    mr	r0, r8
_8006ab50:
    rlwinm	r6, r9, 1, 0x17, 0x1e
    subf	r0, r7, r0
    subf.	r6, r6, r0
    bc      4, 2, _8006ab64
    li	r6, 1
_8006ab64:
    add	r0, r7, r9
    subf	r0, r0, r8
    mulli	r0, r0, 0xff
    divw.	r0, r0, r6
    bc      4, 0, _8006ab7c
    li	r0, 0
_8006ab7c:
    cmpwi	r0, 0xff
    bc      4, 1, _8006ab88
    li	r0, 0xff
_8006ab88:
    stb	r0, 4(r3)
    lbz	r7, 5(r4)
    lbz	r6, 5(r5)
    lbz	r8, 0x19(r5)
    cmpw	r7, r6
    lbz	r0, 0xf(r5)
    bc      4, 0, _8006abac
    stb	r7, 5(r5)
    mr	r6, r7
_8006abac:
    cmpw	r7, r0
    bc      4, 1, _8006abbc
    stb	r7, 0xf(r5)
    mr	r0, r7
_8006abbc:
    rlwinm	r4, r8, 1, 0x17, 0x1e
    subf	r0, r6, r0
    subf.	r4, r4, r0
    bc      4, 2, _8006abd0
    li	r4, 1
_8006abd0:
    add	r0, r6, r8
    subf	r0, r0, r7
    mulli	r0, r0, 0xff
    divw.	r0, r0, r4
    bc      4, 0, _8006abe8
    li	r0, 0
_8006abe8:
    cmpwi	r0, 0xff
    bc      4, 1, _8006abf4
    li	r0, 0xff
_8006abf4:
    stb	r0, 5(r3)
    lbz	r4, 5(r3)
    lbz	r0, 4(r3)
    subf	r0, r4, r0
    srawi	r0, r0, 1
    addze	r0, r0
    cmpwi	r0, -0x80
    bc      4, 0, _8006ac1c
    li	r0, -0x80
    b       _8006ac28
_8006ac1c:
    cmpwi	r0, 0x7f
    bc      4, 1, _8006ac28
    li	r0, 0x7f
_8006ac28:
    stb	r0, 6(r3)
    blr
_8006ac30:
    li	r0, 0
    stb	r0, 5(r3)
    stb	r0, 4(r3)
    stb	r0, 6(r3)
    blr
}

asm void fn_8006AC44(void)
{
    nofralloc
    lbz	r8, 0x1b(r5)
    lbz	r10, 0x11(r5)
    rlwinm	r0, r8, 1, 0x17, 0x1e
    lbz	r9, 6(r4)
    subf	r0, r0, r10
    cmpw	r9, r0
    bc      4, 1, _8006ad08
    lhz	r6, 0(r4)
    lhz	r0, 0x1e(r5)
    xor	r0, r6, r0
    rlwinm.	r0, r0, 0, 0x19, 0x19
    bc      12, 2, _8006ac90
    subf	r7, r8, r9
    li	r0, 0xff
    srawi	r6, r7, 0x1f
    andc	r6, r7, r6
    stb	r6, 0x11(r5)
    stb	r0, 7(r3)
    b       _8006ad68
_8006ac90:
    rlwinm.	r0, r6, 0, 0x19, 0x19
    bc      12, 2, _8006aca4
    li	r0, 0xff
    stb	r0, 7(r3)
    b       _8006ad68
_8006aca4:
    lbz	r7, 7(r5)
    cmpw	r9, r7
    bc      4, 0, _8006acb8
    stb	r9, 7(r5)
    mr	r7, r9
_8006acb8:
    cmpw	r9, r10
    bc      4, 1, _8006acc8
    stb	r9, 0x11(r5)
    mr	r10, r9
_8006acc8:
    rlwinm	r6, r8, 1, 0x17, 0x1e
    subf	r0, r7, r10
    subf.	r6, r6, r0
    bc      4, 2, _8006acdc
    li	r6, 1
_8006acdc:
    add	r0, r7, r8
    subf	r0, r0, r9
    mulli	r0, r0, 0xff
    divw.	r0, r0, r6
    bc      4, 0, _8006acf4
    li	r0, 0
_8006acf4:
    cmpwi	r0, 0xff
    bc      4, 1, _8006ad00
    li	r0, 0xff
_8006ad00:
    stb	r0, 7(r3)
    b       _8006ad68
_8006ad08:
    lbz	r7, 7(r5)
    cmpw	r9, r7
    bc      4, 0, _8006ad1c
    stb	r9, 7(r5)
    mr	r7, r9
_8006ad1c:
    cmpw	r9, r10
    bc      4, 1, _8006ad2c
    stb	r9, 0x11(r5)
    mr	r10, r9
_8006ad2c:
    rlwinm	r6, r8, 1, 0x17, 0x1e
    subf	r0, r7, r10
    subf.	r6, r6, r0
    bc      4, 2, _8006ad40
    li	r6, 1
_8006ad40:
    add	r0, r7, r8
    subf	r0, r0, r9
    mulli	r0, r0, 0xff
    divw.	r0, r0, r6
    bc      4, 0, _8006ad58
    li	r0, 0
_8006ad58:
    cmpwi	r0, 0xff
    bc      4, 1, _8006ad64
    li	r0, 0xff
_8006ad64:
    stb	r0, 7(r3)
_8006ad68:
    lbz	r7, 0x1c(r5)
    lbz	r9, 0x12(r5)
    rlwinm	r0, r7, 1, 0x17, 0x1e
    lbz	r8, 7(r4)
    subf	r0, r0, r9
    cmpw	r8, r0
    bc      4, 1, _8006ae2c
    lhz	r4, 0(r4)
    lhz	r0, 0x1e(r5)
    xor	r0, r4, r0
    rlwinm.	r0, r0, 0, 0x1a, 0x1a
    bc      12, 2, _8006adb4
    subf	r6, r7, r8
    li	r0, 0xff
    srawi	r4, r6, 0x1f
    andc	r4, r6, r4
    stb	r4, 0x12(r5)
    stb	r0, 8(r3)
    blr
_8006adb4:
    rlwinm.	r0, r4, 0, 0x1a, 0x1a
    bc      12, 2, _8006adc8
    li	r0, 0xff
    stb	r0, 8(r3)
    blr
_8006adc8:
    lbz	r6, 8(r5)
    cmpw	r8, r6
    bc      4, 0, _8006addc
    stb	r8, 8(r5)
    mr	r6, r8
_8006addc:
    cmpw	r8, r9
    bc      4, 1, _8006adec
    stb	r8, 0x12(r5)
    mr	r9, r8
_8006adec:
    rlwinm	r4, r7, 1, 0x17, 0x1e
    subf	r0, r6, r9
    subf.	r4, r4, r0
    bc      4, 2, _8006ae00
    li	r4, 1
_8006ae00:
    add	r0, r6, r7
    subf	r0, r0, r8
    mulli	r0, r0, 0xff
    divw.	r0, r0, r4
    bc      4, 0, _8006ae18
    li	r0, 0
_8006ae18:
    cmpwi	r0, 0xff
    bc      4, 1, _8006ae24
    li	r0, 0xff
_8006ae24:
    stb	r0, 8(r3)
    blr
_8006ae2c:
    lbz	r6, 8(r5)
    cmpw	r8, r6
    bc      4, 0, _8006ae40
    stb	r8, 8(r5)
    mr	r6, r8
_8006ae40:
    cmpw	r8, r9
    bc      4, 1, _8006ae50
    stb	r8, 0x12(r5)
    mr	r9, r8
_8006ae50:
    rlwinm	r4, r7, 1, 0x17, 0x1e
    subf	r0, r6, r9
    subf.	r4, r4, r0
    bc      4, 2, _8006ae64
    li	r4, 1
_8006ae64:
    add	r0, r6, r7
    subf	r0, r0, r8
    mulli	r0, r0, 0xff
    divw.	r0, r0, r4
    bc      4, 0, _8006ae7c
    li	r0, 0
_8006ae7c:
    cmpwi	r0, 0xff
    bc      4, 1, _8006ae88
    li	r0, 0xff
_8006ae88:
    stb	r0, 8(r3)
    blr
}

asm void fn_8006AE90(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r29, 0x14(r1)
    mr	r31, r5
    mr	r29, r3
    mr	r30, r4
    lbz	r5, 3(r4)
    lbz	r4, 3(r31)
    extsb	r6, r5
    lbz	r0, 0xd(r31)
    extsb	r4, r4
    lbz	r3, 0x17(r31)
    cmpw	r6, r4
    extsb	r0, r0
    bc      4, 0, _8006aed8
    stb	r5, 3(r31)
    mr	r4, r6
_8006aed8:
    cmpw	r6, r0
    bc      4, 1, _8006aee8
    extsb	r0, r5
    stb	r5, 0xd(r31)
_8006aee8:
    extsb	r5, r3
    subf	r0, r4, r0
    slwi	r3, r5, 1
    subf.	r3, r3, r0
    bc      4, 2, _8006af00
    li	r3, 1
_8006af00:
    add	r0, r4, r5
    subf	r0, r0, r6
    mulli	r0, r0, 0xff
    divw	r3, r0, r3
    addi	r0, r3, -0x7f
    cmpwi	r0, -0x80
    bc      4, 0, _8006af20
    li	r0, -0x80
_8006af20:
    cmpwi	r0, 0x7f
    bc      4, 1, _8006af2c
    li	r0, 0x7f
_8006af2c:
    stb	r0, 3(r29)
    mr	r3, r29
    mr	r4, r30
    mr	r5, r31
    bl      fn_8006AA44
    mr	r3, r29
    mr	r4, r30
    mr	r5, r31
    bl      fn_8006AC44
    lhz	r3, 0(r30)
    li	r0, 0
    sth	r3, 0(r29)
    lbz	r3, 2(r30)
    stb	r3, 2(r29)
    lwz	r4, 0(r30)
    lwz	r3, 4(r30)
    stw	r4, 0x1e(r31)
    stw	r3, 0x22(r31)
    lhz	r3, 8(r30)
    sth	r3, 0x26(r31)
    stb	r0, 9(r29)
    lmw	r29, 0x14(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006AF94(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, lbl_80199670@ha
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    li	r29, 0
    addi	r30, r3, lbl_80199670@l
    li	r31, 0
_8006afb4:
    add	r28, r30, r31
    lbz	r0, 4(r28)
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      12, 2, _8006b024
    addi	r27, r28, 0xc
    mr	r3, r29
    mr	r4, r27
    bl      SIGetResponseSync
    lbz	r0, 8(r27)
    extsb.	r0, r0
    bc      12, 2, _8006b00c
    bc      4, 0, _8006b024
    cmpwi	r0, -1
    bc      4, 0, _8006aff0
    b       _8006b024
_8006aff0:
    li	r0, -1
    li	r3, 1
    stb	r0, 0x4d(r28)
    lbz	r0, 4(r28)
    rlwimi	r0, r3, 6, 0x19, 0x19
    stb	r0, 4(r28)
    b       _8006b024
_8006b00c:
    mr	r4, r27
    addi	r3, r28, 0x44
    addi	r5, r28, 0x18
    bl      fn_8006AE90
    addi	r3, r28, 0x50
    bl      fn_8006C92C
_8006b024:
    addi	r29, r29, 1
    addi	r31, r31, 0x1248
    cmpwi	r29, 4
    bc      12, 0, _8006afb4
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006B048(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r11, 0
    mr	r12, r3
    stw	r0, 0x14(r1)
    li	r9, -1
    li	r8, 0x80
    li	r7, -0x40
    stw	r4, 0(r3)
    li	r6, 0x50
    li	r5, 0x40
    li	r4, 0xb0
    lbz	r0, 4(r3)
    rlwimi	r0, r11, 7, 0x18, 0x18
    stb	r0, 4(r3)
    li	r3, 6
    li	r0, 0xc
    lbz	r10, 4(r12)
    rlwimi	r10, r11, 6, 0x19, 0x19
    stb	r10, 4(r12)
    stw	r9, 8(r12)
    sth	r11, 0xc(r12)
    stb	r11, 0xe(r12)
    stb	r11, 0xf(r12)
    stb	r8, 0x10(r12)
    stb	r8, 0x11(r12)
    stb	r8, 0x12(r12)
    stb	r8, 0x13(r12)
    stb	r9, 0x14(r12)
    stb	r7, 0x1b(r12)
    stb	r6, 0x1f(r12)
    stb	r6, 0x20(r12)
    stb	r5, 0x25(r12)
    stb	r4, 0x29(r12)
    stb	r4, 0x2a(r12)
    stb	r3, 0x2f(r12)
    stb	r0, 0x33(r12)
    stb	r0, 0x34(r12)
    stb	r6, 0x1c(r12)
    stb	r6, 0x1d(r12)
    lbz	r3, 0x1d(r12)
    lbz	r0, 0x1c(r12)
    subf	r0, r3, r0
    srawi	r0, r0, 1
    addze	r0, r0
    cmpwi	r0, -0x80
    bc      4, 0, _8006b10c
    li	r0, -0x80
    b       _8006b118
_8006b10c:
    cmpwi	r0, 0x7f
    bc      4, 1, _8006b118
    li	r0, 0x7f
_8006b118:
    stb	r0, 0x1e(r12)
    li	r0, 0xb0
    stb	r0, 0x26(r12)
    stb	r0, 0x27(r12)
    lbz	r3, 0x27(r12)
    lbz	r0, 0x26(r12)
    subf	r0, r3, r0
    srawi	r0, r0, 1
    addze	r0, r0
    cmpwi	r0, -0x80
    bc      4, 0, _8006b14c
    li	r0, -0x80
    b       _8006b158
_8006b14c:
    cmpwi	r0, 0x7f
    bc      4, 1, _8006b158
    li	r0, 0x7f
_8006b158:
    stb	r0, 0x28(r12)
    li	r0, 0xa
    addi	r3, r12, 0x44
    addi	r4, r12, 0xc
    stb	r0, 0x30(r12)
    addi	r5, r12, 0x18
    stb	r0, 0x31(r12)
    bl      fn_8006AE90
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B188(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    lwz	r0, -0x7738(r13)
    cmpwi	r0, 0
    bc      4, 2, _8006b210
    lis     r4, lbl_80199670@ha
    lis     r3, fn_8006AA20@ha
    addi	r29, r4, lbl_80199670@l
    li	r27, 0
    addi	r30, r3, fn_8006AA20@l
    li	r31, 0
_8006b1bc:
    add	r28, r29, r31
    addi	r3, r28, 0x50
    bl      fn_8006B92C
    mr	r3, r28
    mr	r4, r27
    bl      fn_8006B048
    mr	r3, r27
    mr	r4, r30
    bl      SITransferSync
    mr	r3, r27
    addi	r4, r28, 0xc
    bl      SIGetResponseSync
    addi	r27, r27, 1
    addi	r31, r31, 0x1248
    cmpwi	r27, 4
    bc      12, 0, _8006b1bc
    lis     r3, fn_8006AF94@ha
    addi	r3, r3, fn_8006AF94@l
    bl      fn_80013994
    li	r0, 1
    stw	r0, -0x7738(r13)
_8006b210:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006B224(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r29, 0x14(r1)
    lwz	r0, -0x7738(r13)
    cmpwi	r0, 0
    bc      12, 2, _8006b280
    lis     r3, lbl_80199670@ha
    li	r29, 0
    addi	r30, r3, lbl_80199670@l
    li	r31, 0
_8006b250:
    add	r3, r30, r31
    bl      fn_8006B3F0
    mr	r3, r29
    li	r4, 0x400
    li	r5, 0
    bl      fn_800139E8
    addi	r29, r29, 1
    addi	r31, r31, 0x1248
    cmpwi	r29, 4
    bc      12, 0, _8006b250
    li	r0, 0
    stw	r0, -0x7738(r13)
_8006b280:
    lmw	r29, 0x14(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006B294(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r28, r3
    cmpwi	r28, 4
    mr	r29, r4
    bc      4, 0, _8006b2bc
    cmpwi	r28, 0
    bc      4, 0, _8006b2c4
_8006b2bc:
    li	r3, -2
    b       _8006b3dc
_8006b2c4:
    cmplwi	r29, 0
    bc      4, 2, _8006b2d4
    li	r3, -2
    b       _8006b3dc
_8006b2d4:
    mulli	r31, r28, 0x1248
    lis     r3, lbl_80199670@ha
    addi	r0, r3, lbl_80199670@l
    add	r30, r0, r31
    lbz	r0, 4(r30)
    rlwinm.	r0, r0, 0x1a, 0x1f, 0x1f
    bc      12, 2, _8006b2f8
    mr	r3, r30
    bl      fn_8006B3F0
_8006b2f8:
    lbz	r0, 4(r30)
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      12, 2, _8006b314
    lwz	r0, 8(r30)
    li	r3, -3
    stw	r0, 0(r29)
    b       _8006b3dc
_8006b314:
    lis     r4, fn_8006AA20@ha
    mr	r3, r28
    addi	r4, r4, fn_8006AA20@l
    bl      SITransferSync
    cmpwi	r3, -1
    bc      12, 2, _8006b3d8
    mr	r3, r30
    mr	r4, r28
    bl      fn_8006B048
    addi	r27, r30, 0xc
    mr	r3, r28
    mr	r4, r27
    bl      SIGetResponseSync
    lis     r3, lbl_80199670@ha
    addi	r0, r3, lbl_80199670@l
    add	r4, r0, r31
    lbz	r0, 0x14(r4)
    extsb.	r0, r0
    bc      12, 2, _8006b380
    bc      4, 0, _8006b390
    cmpwi	r0, -1
    bc      4, 0, _8006b370
    b       _8006b390
_8006b370:
    li	r0, -1
    li	r3, -4
    stb	r0, 0x4d(r4)
    b       _8006b3dc
_8006b380:
    mr	r4, r27
    addi	r3, r30, 0x44
    addi	r5, r30, 0x18
    bl      fn_8006AE90
_8006b390:
    lis     r3, lbl_80199670@ha
    li	r6, 0
    addi	r0, r3, lbl_80199670@l
    mr	r4, r30
    add	r5, r0, r31
    addi	r3, r30, 0x50
    stb	r6, 0x4d(r5)
    stw	r30, 0(r29)
    stw	r28, 0(r30)
    lwz	r0, 0(r29)
    stw	r0, 8(r30)
    bl      fn_8006BC1C
    lbz	r0, 4(r30)
    li	r3, 1
    rlwimi	r0, r3, 7, 0x18, 0x18
    li	r3, 0
    stb	r0, 4(r30)
    b       _8006b3dc
_8006b3d8:
    li	r3, -4
_8006b3dc:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006B3F0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    bc      12, 2, _8006b414
    addis	r0, r31, 1
    cmplwi	r0, 0xffff
    bc      4, 2, _8006b41c
_8006b414:
    li	r3, -2
    b       _8006b45c
_8006b41c:
    lbz	r5, 4(r31)
    rlwinm.	r0, r5, 0x19, 0x1f, 0x1f
    bc      4, 2, _8006b430
    li	r3, -2
    b       _8006b45c
_8006b430:
    li	r4, 0
    addi	r3, r31, 0x50
    rlwimi	r5, r4, 7, 0x18, 0x18
    stb	r5, 4(r31)
    lbz	r0, 4(r31)
    rlwimi	r0, r4, 6, 0x19, 0x19
    stb	r0, 4(r31)
    bl      fn_8006BC50
    li	r0, -1
    li	r3, 0
    stw	r0, 8(r31)
_8006b45c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B470(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r26, 8(r1)
    or.	r28, r3, r3
    bc      4, 2, _8006b490
    li	r3, -2
    b       _8006b548
_8006b490:
    lis     r3, lbl_80199670@ha
    li	r30, 0
    addi	r31, r3, lbl_80199670@l
    li	r27, 0
    li	r26, 0
_8006b4a4:
    add	r29, r31, r26
    lbz	r5, 4(r29)
    rlwinm.	r0, r5, 0x1a, 0x1f, 0x1f
    bc      12, 2, _8006b4f8
    cmplwi	r29, 0
    bc      12, 2, _8006b4f8
    addis	r0, r29, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006b4f8
    rlwinm.	r0, r5, 0x19, 0x1f, 0x1f
    bc      12, 2, _8006b4f8
    li	r4, 0
    addi	r3, r29, 0x50
    rlwimi	r5, r4, 7, 0x18, 0x18
    stb	r5, 4(r29)
    lbz	r0, 4(r29)
    rlwimi	r0, r4, 6, 0x19, 0x19
    stb	r0, 4(r29)
    bl      fn_8006BC50
    li	r0, -1
    stw	r0, 8(r29)
_8006b4f8:
    lbz	r0, 4(r29)
    rlwinm.	r0, r0, 0x19, 0x1f, 0x1f
    bc      12, 2, _8006b524
    lwz	r3, 0x44(r29)
    add	r4, r28, r27
    lwz	r0, 0x48(r29)
    stw	r3, 0(r4)
    stw	r0, 4(r4)
    lhz	r0, 0x4c(r29)
    sth	r0, 8(r4)
    b       _8006b530
_8006b524:
    addi	r0, r27, 9
    li	r3, -1
    stbx	r3, r28, r0
_8006b530:
    addi	r30, r30, 1
    addi	r26, r26, 0x1248
    cmpwi	r30, 4
    addi	r27, r27, 0xa
    bc      12, 0, _8006b4a4
    li	r3, 0
_8006b548:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006B55C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    bc      12, 2, _8006b580
    addis	r7, r31, 1
    cmplwi	r7, 0xffff
    bc      4, 2, _8006b588
_8006b580:
    li	r3, -2
    b       _8006b614
_8006b588:
    lbz	r6, 4(r31)
    rlwinm.	r3, r6, 0x19, 0x1f, 0x1f
    bc      4, 2, _8006b59c
    li	r3, -2
    b       _8006b614
_8006b59c:
    cmplwi	r4, 0
    bc      4, 2, _8006b5ac
    li	r3, -2
    b       _8006b614
_8006b5ac:
    cmplwi	r5, 0
    bc      4, 2, _8006b5bc
    li	r3, -2
    b       _8006b614
_8006b5bc:
    rlwinm.	r0, r6, 0x1a, 0x1f, 0x1f
    bc      12, 2, _8006b60c
    cmplwi	r31, 0
    bc      12, 2, _8006b604
    cmplwi	r7, 0xffff
    bc      12, 2, _8006b604
    cmplwi	r3, 0
    bc      12, 2, _8006b604
    li	r4, 0
    addi	r3, r31, 0x50
    rlwimi	r6, r4, 7, 0x18, 0x18
    stb	r6, 4(r31)
    lbz	r0, 4(r31)
    rlwimi	r0, r4, 6, 0x19, 0x19
    stb	r0, 4(r31)
    bl      fn_8006BC50
    li	r0, -1
    stw	r0, 8(r31)
_8006b604:
    li	r3, -2
    b       _8006b614
_8006b60c:
    addi	r3, r31, 0x50
    bl      fn_8006BA74
_8006b614:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B628(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    mr	r5, r4
    stw	r0, 0x14(r1)
    srwi	r0, r3, 0x10
    cmplwi	r0, 4
    stw	r31, 0xc(r1)
    bc      12, 0, _8006b650
    li	r3, -2
    b       _8006b6e4
_8006b650:
    mulli	r6, r0, 0x1248
    lis     r4, lbl_80199670@ha
    addi	r0, r4, lbl_80199670@l
    add	r31, r0, r6
    lbz	r6, 4(r31)
    rlwinm.	r4, r6, 0x19, 0x1f, 0x1f
    bc      4, 2, _8006b674
    li	r3, -2
    b       _8006b6e4
_8006b674:
    cmplwi	r5, 0
    bc      4, 2, _8006b684
    li	r3, -2
    b       _8006b6e4
_8006b684:
    rlwinm.	r0, r6, 0x1a, 0x1f, 0x1f
    bc      12, 2, _8006b6d8
    cmplwi	r31, 0
    bc      12, 2, _8006b6d0
    addis	r0, r31, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006b6d0
    cmplwi	r4, 0
    bc      12, 2, _8006b6d0
    li	r4, 0
    addi	r3, r31, 0x50
    rlwimi	r6, r4, 7, 0x18, 0x18
    stb	r6, 4(r31)
    lbz	r0, 4(r31)
    rlwimi	r0, r4, 6, 0x19, 0x19
    stb	r0, 4(r31)
    bl      fn_8006BC50
    li	r0, -1
    stw	r0, 8(r31)
_8006b6d0:
    li	r3, -2
    b       _8006b6e4
_8006b6d8:
    mr	r4, r3
    addi	r3, r31, 0x50
    bl      fn_8006BB30
_8006b6e4:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B6F8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    srwi	r0, r3, 0x10
    cmplwi	r0, 4
    stw	r31, 0xc(r1)
    bc      12, 0, _8006b71c
    li	r3, -2
    b       _8006b7a0
_8006b71c:
    mulli	r5, r0, 0x1248
    lis     r4, lbl_80199670@ha
    addi	r0, r4, lbl_80199670@l
    add	r31, r0, r5
    lbz	r5, 4(r31)
    rlwinm.	r4, r5, 0x19, 0x1f, 0x1f
    bc      4, 2, _8006b740
    li	r3, -2
    b       _8006b7a0
_8006b740:
    rlwinm.	r0, r5, 0x1a, 0x1f, 0x1f
    bc      12, 2, _8006b794
    cmplwi	r31, 0
    bc      12, 2, _8006b78c
    addis	r0, r31, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006b78c
    cmplwi	r4, 0
    bc      12, 2, _8006b78c
    li	r4, 0
    addi	r3, r31, 0x50
    rlwimi	r5, r4, 7, 0x18, 0x18
    stb	r5, 4(r31)
    lbz	r0, 4(r31)
    rlwimi	r0, r4, 6, 0x19, 0x19
    stb	r0, 4(r31)
    bl      fn_8006BC50
    li	r0, -1
    stw	r0, 8(r31)
_8006b78c:
    li	r3, -2
    b       _8006b7a0
_8006b794:
    mr	r4, r3
    addi	r3, r31, 0x50
    bl      fn_8006BB9C
_8006b7a0:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B7B4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    srwi	r0, r3, 0x10
    cmplwi	r0, 4
    stw	r31, 0xc(r1)
    bc      12, 0, _8006b7d8
    li	r3, -2
    b       _8006b85c
_8006b7d8:
    mulli	r5, r0, 0x1248
    lis     r4, lbl_80199670@ha
    addi	r0, r4, lbl_80199670@l
    add	r31, r0, r5
    lbz	r5, 4(r31)
    rlwinm.	r4, r5, 0x19, 0x1f, 0x1f
    bc      4, 2, _8006b7fc
    li	r3, -2
    b       _8006b85c
_8006b7fc:
    rlwinm.	r0, r5, 0x1a, 0x1f, 0x1f
    bc      12, 2, _8006b850
    cmplwi	r31, 0
    bc      12, 2, _8006b848
    addis	r0, r31, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006b848
    cmplwi	r4, 0
    bc      12, 2, _8006b848
    li	r4, 0
    addi	r3, r31, 0x50
    rlwimi	r5, r4, 7, 0x18, 0x18
    stb	r5, 4(r31)
    lbz	r0, 4(r31)
    rlwimi	r0, r4, 6, 0x19, 0x19
    stb	r0, 4(r31)
    bl      fn_8006BC50
    li	r0, -1
    stw	r0, 8(r31)
_8006b848:
    li	r3, -2
    b       _8006b85c
_8006b850:
    mr	r4, r3
    addi	r3, r31, 0x50
    bl      fn_8006BBDC
_8006b85c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B870(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    srwi	r0, r3, 0x10
    cmplwi	r0, 4
    stw	r31, 0xc(r1)
    bc      12, 0, _8006b894
    li	r3, -2
    b       _8006b918
_8006b894:
    mulli	r5, r0, 0x1248
    lis     r4, lbl_80199670@ha
    addi	r0, r4, lbl_80199670@l
    add	r31, r0, r5
    lbz	r5, 4(r31)
    rlwinm.	r4, r5, 0x19, 0x1f, 0x1f
    bc      4, 2, _8006b8b8
    li	r3, -2
    b       _8006b918
_8006b8b8:
    rlwinm.	r0, r5, 0x1a, 0x1f, 0x1f
    bc      12, 2, _8006b90c
    cmplwi	r31, 0
    bc      12, 2, _8006b904
    addis	r0, r31, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006b904
    cmplwi	r4, 0
    bc      12, 2, _8006b904
    li	r4, 0
    addi	r3, r31, 0x50
    rlwimi	r5, r4, 7, 0x18, 0x18
    stb	r5, 4(r31)
    lbz	r0, 4(r31)
    rlwimi	r0, r4, 6, 0x19, 0x19
    stb	r0, 4(r31)
    bl      fn_8006BC50
    li	r0, -1
    stw	r0, 8(r31)
_8006b904:
    li	r3, -2
    b       _8006b918
_8006b90c:
    mr	r4, r3
    addi	r3, r31, 0x50
    bl      fn_8006BB74
_8006b918:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B92C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    mr	r4, r31
    bl      fn_8006C7E8
    li	r4, 0xff
    li	r3, 0
    stw	r4, 0x11f4(r31)
    li	r0, 0x40
    mr	r4, r3
    mtctr	r0
_8006b960:
    addi	r0, r3, 0xf4
    addi	r3, r3, 4
    stwx	r4, r31, r0
    bc      16, 0, _8006b960
    lwz	r0, -0x7734(r13)
    cmpwi	r0, 0
    bc      4, 2, _8006b988
    bl      fn_8006B99C
    li	r0, 1
    stw	r0, -0x7734(r13)
_8006b988:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006B99C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, lbl_8019DF90@ha
    stw	r0, 0x24(r1)
    stmw	r30, 0x18(r1)
    li	r30, 0
    addi	r31, r3, lbl_8019DF90@l
_8006b9b8:
    cmpwi	r30, 0
    bc      4, 0, _8006ba04
    neg	r3, r30
    lis	r0, 0x4330
    xoris	r3, r3, 0x8000
    stw	r0, 8(r1)
    lfd	f3, -0x7ac0(r2)
    stw	r3, 0xc(r1)
    lfs	f0, -0x7ad0(r2)
    lfd	f1, 8(r1)
    lfs	f2, -0x7acc(r2)
    fsubs	f1, f1, f3
    fmuls	f1, f1, f0
    bl      __msl_fp_helper
    frsp	f2, f1
    lfs	f1, -0x7ac4(r2)
    lfs	f0, -0x7ac8(r2)
    fnmadds	f0, f1, f2, f0
    b       _8006ba40
_8006ba04:
    xoris	r3, r30, 0x8000
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lfd	f3, -0x7ac0(r2)
    stw	r0, 8(r1)
    lfs	f0, -0x7ad0(r2)
    lfd	f1, 8(r1)
    lfs	f2, -0x7acc(r2)
    fsubs	f1, f1, f3
    fmuls	f1, f1, f0
    bl      __msl_fp_helper
    frsp	f2, f1
    lfs	f1, -0x7ac4(r2)
    lfs	f0, -0x7ac8(r2)
    fmadds	f0, f1, f2, f0
_8006ba40:
    fctiwz	f0, f0
    addi	r30, r30, 1
    cmpwi	r30, 0x81
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    stb	r0, 0(r31)
    addi	r31, r31, 1
    bc      12, 0, _8006b9b8
    lmw	r30, 0x18(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006BA74(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r26, 8(r1)
    mr	r26, r3
    mr	r27, r4
    mr	r28, r5
    li	r31, 0
    bl      fn_8006BC84
    stw	r3, 0(r27)
    lwz	r4, 0(r27)
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      4, 2, _8006bab4
    li	r31, -5
    b       _8006bb18
_8006bab4:
    lbz	r0, 0(r28)
    rlwinm	r3, r4, 6, 0x14, 0x19
    addi	r29, r3, 0x1f4
    clrlwi	r30, r4, 0x1a
    cmpwi	r0, 9
    add	r29, r26, r29
    bc      4, 0, _8006baf8
    cmpwi	r0, 0
    bc      4, 0, _8006badc
    b       _8006baf8
_8006badc:
    mr	r3, r29
    bl      fn_8006BCF8
    stw	r26, 0x24(r29)
    mr	r3, r29
    mr	r4, r28
    bl      fn_8006BE0C
    b       _8006bb04
_8006baf8:
    li	r0, -1
    li	r31, -2
    stw	r0, 0(r27)
_8006bb04:
    cmplwi	r29, 0
    bc      12, 2, _8006bb18
    slwi	r0, r30, 2
    add	r3, r26, r0
    stw	r29, 0xf4(r3)
_8006bb18:
    mr	r3, r31
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006BB30(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    rlwinm	r0, r4, 2, 0x18, 0x1d
    add	r3, r3, r0
    lwz	r3, 0xf4(r3)
    li	r0, -2
    cmplwi	r3, 0
    bc      12, 2, _8006bb60
    mr	r4, r5
    bl      fn_8006BE0C
    mr	r0, r3
_8006bb60:
    mr	r3, r0
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006BB74(void)
{
    nofralloc
    rlwinm	r0, r4, 2, 0x18, 0x1d
    add	r4, r3, r0
    li	r3, -2
    lwz	r0, 0xf4(r4)
    cmplwi	r0, 0
    beqlr	
    li	r0, 0
    li	r3, 0
    stw	r0, 0xf4(r4)
    blr
}

asm void fn_8006BB9C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    rlwinm	r0, r4, 2, 0x18, 0x1d
    add	r3, r3, r0
    lwz	r3, 0xf4(r3)
    li	r0, -2
    cmplwi	r3, 0
    bc      12, 2, _8006bbc8
    bl      fn_8006C134
    mr	r0, r3
_8006bbc8:
    mr	r3, r0
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006BBDC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    rlwinm	r0, r4, 2, 0x18, 0x1d
    add	r3, r3, r0
    lwz	r3, 0xf4(r3)
    li	r0, -2
    cmplwi	r3, 0
    bc      12, 2, _8006bc08
    bl      fn_8006C17C
    mr	r0, r3
_8006bc08:
    mr	r3, r0
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006BC1C(void)
{
    nofralloc
    li	r6, 0xff
    li	r5, 0
    stw	r6, 0x11f4(r3)
    li	r0, 0x40
    mr	r6, r5
    mtctr	r0
_8006bc34:
    addi	r0, r5, 0xf4
    addi	r5, r5, 4
    stwx	r6, r3, r0
    bc      16, 0, _8006bc34
    stw	r4, 0xf0(r3)
    li	r3, 0
    blr
}

asm void fn_8006BC50(void)
{
    nofralloc
    li	r4, 0
    li	r0, 0x40
    mr	r5, r4
    mtctr	r0
_8006bc60:
    addi	r6, r4, 0xf4
    lwzx	r0, r3, r6
    cmplwi	r0, 0
    bc      12, 2, _8006bc74
    stwx	r5, r3, r6
_8006bc74:
    addi	r4, r4, 4
    bc      16, 0, _8006bc60
    li	r3, 0
    blr
}

asm void fn_8006BC84(void)
{
    nofralloc
    li	r0, 0x40
    lwz	r6, -0x7730(r13)
    li	r7, -1
    li	r8, 0
    mtctr	r0
_8006bc98:
    add	r5, r8, r6
    rlwinm	r4, r5, 2, 0x18, 0x1d
    addi	r0, r4, 0xf4
    clrlwi	r4, r5, 0x1a
    lwzx	r0, r3, r0
    cmplwi	r0, 0
    bc      4, 2, _8006bce8
    addi	r0, r4, 1
    stw	r0, -0x7730(r13)
    lwz	r0, -0x7730(r13)
    clrlwi	r0, r0, 0x1a
    stw	r0, -0x7730(r13)
    lwz	r3, 0xf0(r3)
    lwz	r0, -0x772c(r13)
    lwz	r3, 0(r3)
    rlwinm	r0, r0, 8, 0x10, 0x17
    rlwimi	r0, r3, 0x10, 0, 0xf
    mr	r7, r0
    rlwimi	r7, r4, 0, 0x1a, 0x1f
    b       _8006bcf0
_8006bce8:
    addi	r8, r8, 1
    bc      16, 0, _8006bc98
_8006bcf0:
    mr	r3, r7
    blr
}

asm void fn_8006BCF8(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    addi	r4, r3, -4
    li	r5, 0x40
    stw	r0, 0x34(r1)
    li	r3, 2
    li	r0, 0
    stmw	r26, 0x18(r1)
_8006bd18:
    stw	r0, 4(r4)
    addic.	r3, r3, -1
    stw	r0, 8(r4)
    stw	r0, 0xc(r4)
    stw	r0, 0x10(r4)
    stw	r0, 0x14(r4)
    stw	r0, 0x18(r4)
    stw	r0, 0x1c(r4)
    stwu	r0, 0x20(r4)
    bc      4, 2, _8006bd18
    clrlwi.	r5, r5, 0x1e
    addi	r3, r4, 3
    bc      12, 2, _8006bd5c
    li	r0, 0
_8006bd50:
    addic.	r5, r5, -1
    stbu	r0, 1(r3)
    bc      4, 2, _8006bd50
_8006bd5c:
    lwz	r0, -0x7728(r13)
    cmpwi	r0, 0
    bc      4, 2, _8006bdf8
    lis     r4, lbl_8019E014@ha
    lis     r3, lbl_8019E094@ha
    addi	r28, r4, lbl_8019E014@l
    li	r26, 0
    addi	r29, r3, lbl_8019E094@l
    li	r31, 0
    li	r30, 0
    lis	r27, 0x4330
_8006bd88:
    xoris	r0, r26, 0x8000
    stw	r27, 8(r1)
    lfd	f2, -0x7ac0(r2)
    stw	r0, 0xc(r1)
    lfs	f3, -0x7ab8(r2)
    lfd	f1, 8(r1)
    lfs	f0, -0x7ad0(r2)
    fsubs	f1, f1, f2
    fmuls	f1, f3, f1
    fmuls	f1, f1, f0
    bl      atan
    li	r0, 0x3f
    addi	r26, r26, 1
    divw	r0, r31, r0
    lfs	f0, -0x7ab4(r2)
    frsp	f1, f1
    cmpwi	r26, 0x40
    addi	r31, r31, 0x400
    fmuls	f0, f0, f1
    fctiwz	f0, f0
    sthx	r0, r29, r30
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    sthx	r0, r28, r30
    addi	r30, r30, 2
    bc      12, 0, _8006bd88
    li	r0, 1
    stw	r0, -0x7728(r13)
_8006bdf8:
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_8006BE0C(void)
{
    nofralloc
    lbz	r7, 0(r4)
    li	r0, 0
    lwz	r6, 4(r4)
    stb	r7, 0(r3)
    cmpwi	r7, 1
    lwz	r5, 8(r4)
    stw	r6, 4(r3)
    stw	r5, 8(r3)
    bc      12, 2, _8006beec
    bc      4, 0, _8006be40
    cmpwi	r7, 0
    bc      4, 0, _8006be54
    b       _8006c128
_8006be40:
    cmpwi	r7, 9
    bc      4, 0, _8006c128
    cmpwi	r7, 7
    bc      4, 0, _8006c068
    b       _8006bf6c
_8006be54:
    lwz	r5, 0x28(r3)
    li	r6, -0xff
    lha	r7, 0xc(r4)
    ori	r5, r5, 0x14
    cmpwi	r7, -0xff
    stw	r5, 0x28(r3)
    bc      12, 0, _8006be74
    mr	r6, r7
_8006be74:
    cmpwi	r6, 0xff
    li	r5, 0xff
    bc      12, 1, _8006be84
    mr	r5, r6
_8006be84:
    lhz	r10, 0xe(r4)
    li	r9, 0x168
    sth	r5, 0xc(r3)
    li	r5, 0xff
    divw	r8, r10, r9
    lbz	r11, 0x18(r4)
    lwz	r7, 0x10(r4)
    lwz	r6, 0x14(r4)
    cmpwi	r11, 0xff
    mullw	r8, r8, r9
    subf	r8, r8, r10
    slwi	r8, r8, 8
    divw	r8, r8, r9
    sth	r8, 0xe(r3)
    stw	r7, 0x10(r3)
    stw	r6, 0x14(r3)
    bc      12, 1, _8006becc
    mr	r5, r11
_8006becc:
    lbz	r6, 0x19(r4)
    li	r4, 0xff
    stb	r5, 0x18(r3)
    cmpwi	r6, 0xff
    bc      12, 1, _8006bee4
    mr	r4, r6
_8006bee4:
    stb	r4, 0x19(r3)
    b       _8006c12c
_8006beec:
    lwz	r5, 0x28(r3)
    li	r6, -0xff
    lha	r7, 0xc(r4)
    ori	r5, r5, 0x24
    cmpwi	r7, -0xff
    stw	r5, 0x28(r3)
    bc      12, 0, _8006bf0c
    mr	r6, r7
_8006bf0c:
    cmpwi	r6, 0xff
    li	r5, 0xff
    bc      12, 1, _8006bf1c
    mr	r5, r6
_8006bf1c:
    lha	r6, 0xe(r4)
    sth	r5, 0xc(r3)
    li	r5, -0xff
    cmpwi	r6, -0xff
    bc      12, 0, _8006bf34
    mr	r5, r6
_8006bf34:
    cmpwi	r5, 0xff
    li	r7, 0xff
    bc      12, 1, _8006bf44
    mr	r7, r5
_8006bf44:
    lhz	r6, 0x10(r4)
    li	r5, 0x168
    sth	r7, 0xe(r3)
    divw	r4, r6, r5
    mullw	r4, r4, r5
    subf	r4, r4, r6
    slwi	r4, r4, 8
    divw	r4, r4, r5
    sth	r4, 0x10(r3)
    b       _8006c12c
_8006bf6c:
    lwz	r5, 0x28(r3)
    li	r6, 0xff
    lbz	r7, 0xc(r4)
    ori	r5, r5, 0x44
    cmpwi	r7, 0xff
    stw	r5, 0x28(r3)
    bc      12, 1, _8006bf8c
    mr	r6, r7
_8006bf8c:
    lhz	r8, 0xe(r4)
    li	r7, 0x168
    lhz	r9, 0x10(r4)
    divw	r5, r8, r7
    stb	r6, 0xc(r3)
    cmplwi	r9, 2
    li	r6, 2
    mullw	r5, r5, r7
    subf	r5, r5, r8
    slwi	r5, r5, 8
    divw	r5, r5, r7
    sth	r5, 0xe(r3)
    bc      12, 0, _8006bfc4
    mr	r6, r9
_8006bfc4:
    lhz	r8, 0x12(r4)
    li	r7, 0x168
    lha	r9, 0x14(r4)
    divw	r5, r8, r7
    sth	r6, 0x10(r3)
    cmpwi	r9, -0xff
    li	r6, -0xff
    mullw	r5, r5, r7
    subf	r5, r5, r8
    slwi	r5, r5, 8
    divw	r5, r5, r7
    sth	r5, 0x12(r3)
    bc      12, 0, _8006bffc
    mr	r6, r9
_8006bffc:
    cmpwi	r6, 0xff
    li	r5, 0xff
    bc      12, 1, _8006c00c
    mr	r5, r6
_8006c00c:
    sth	r5, 0x14(r3)
    li	r5, 0xff
    lwz	r6, 0x18(r4)
    lbz	r7, 0x20(r4)
    stw	r6, 0x18(r3)
    lwz	r6, 0x1c(r4)
    cmpwi	r7, 0xff
    stw	r6, 0x1c(r3)
    bc      12, 1, _8006c034
    mr	r5, r7
_8006c034:
    lbz	r6, 0x21(r4)
    li	r4, 0xff
    stb	r5, 0x20(r3)
    cmpwi	r6, 0xff
    bc      12, 1, _8006c04c
    mr	r4, r6
_8006c04c:
    stb	r4, 0x21(r3)
    lhz	r4, 0x10(r3)
    cmplwi	r4, 4
    bc      4, 0, _8006c12c
    li	r4, 0x40
    sth	r4, 0x12(r3)
    b       _8006c12c
_8006c068:
    lwz	r5, 0x28(r3)
    li	r6, -0xff
    lha	r8, 0x12(r4)
    ori	r5, r5, 0x80
    lbz	r7, 0xc(r4)
    stw	r5, 0x28(r3)
    cmpwi	r8, -0xff
    lbz	r5, 0xd(r4)
    stb	r7, 0xc(r3)
    stb	r5, 0xd(r3)
    bc      12, 0, _8006c098
    mr	r6, r8
_8006c098:
    cmpwi	r6, 0xff
    li	r5, 0xff
    bc      12, 1, _8006c0a8
    mr	r5, r6
_8006c0a8:
    lha	r6, 0x10(r4)
    sth	r5, 0x12(r3)
    li	r5, -0xff
    cmpwi	r6, -0xff
    bc      12, 0, _8006c0c0
    mr	r5, r6
_8006c0c0:
    cmpwi	r5, 0xff
    li	r6, 0xff
    bc      12, 1, _8006c0d0
    mr	r6, r5
_8006c0d0:
    lbz	r5, 0xe(r4)
    sth	r6, 0x10(r3)
    lbz	r4, 0xf(r4)
    rlwinm	r5, r5, 0x1f, 0x18, 0x1f
    stb	r5, 0xe(r3)
    rlwinm	r4, r4, 0x1f, 0x18, 0x1f
    stb	r4, 0xf(r3)
    lbz	r5, 0xd(r3)
    lbz	r4, 0xc(r3)
    srwi	r5, r5, 1
    extsb	r4, r4
    subf	r4, r5, r4
    slwi	r4, r4, 0xc
    stw	r4, 0x38(r3)
    lbz	r5, 0xc(r3)
    lbz	r4, 0xd(r3)
    extsb	r5, r5
    srwi	r4, r4, 1
    add	r4, r5, r4
    slwi	r4, r4, 0xc
    stw	r4, 0x3c(r3)
    b       _8006c12c
_8006c128:
    li	r0, -2
_8006c12c:
    mr	r3, r0
    blr
}

asm void fn_8006C134(void)
{
    nofralloc
    lwz	r4, 0x28(r3)
    li	r0, 0
    ori	r4, r4, 1
    stw	r4, 0x28(r3)
    lwz	r4, 0x28(r3)
    rlwinm	r4, r4, 0, 0x1f, 0x1d
    stw	r4, 0x28(r3)
    stw	r0, 0x2c(r3)
    lwz	r0, 8(r3)
    stw	r0, 0x30(r3)
    lwz	r0, 0x28(r3)
    rlwinm.	r0, r0, 0, 0x19, 0x19
    bc      12, 2, _8006c174
    lhz	r0, 0x12(r3)
    slwi	r0, r0, 0x10
    stw	r0, 0x38(r3)
_8006c174:
    li	r3, 0
    blr
}

asm void fn_8006C17C(void)
{
    nofralloc
    lwz	r0, 0x28(r3)
    rlwinm	r0, r0, 0, 0, 0x1e
    stw	r0, 0x28(r3)
    li	r3, 0
    blr
}

asm void fn_8006C190(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lwz	r0, 0x28(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8006c218
    lwz	r0, 0x30(r31)
    cmplwi	r0, 0
    bc      12, 2, _8006c1dc
    subf	r0, r4, r0
    stw	r0, 0x30(r31)
    lwz	r0, 0x30(r31)
    cmpwi	r0, 0
    bc      4, 0, _8006c218
    li	r0, 0
    stw	r0, 0x30(r31)
    b       _8006c218
_8006c1dc:
    lwz	r0, 0x2c(r31)
    add	r0, r0, r4
    stw	r0, 0x2c(r31)
    lwz	r3, 4(r31)
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006c218
    lwz	r0, 0x2c(r31)
    cmplw	r3, r0
    bc      4, 0, _8006c218
    lwz	r3, 0x28(r31)
    rlwinm.	r0, r3, 0, 0x1e, 0x1e
    bc      12, 2, _8006c218
    rlwinm	r0, r3, 0, 0, 0x1e
    stw	r0, 0x28(r31)
_8006c218:
    lwz	r0, 0x28(r31)
    li	r3, 0
    ori	r0, r0, 2
    stw	r0, 0x28(r31)
    lwz	r5, 0x28(r31)
    clrlwi.	r0, r5, 0x1f
    bc      12, 2, _8006c244
    lwz	r0, 0x30(r31)
    cmplwi	r0, 0
    bc      4, 2, _8006c244
    li	r3, 1
_8006c244:
    cmpwi	r3, 0
    bc      12, 2, _8006c550
    rlwinm.	r0, r5, 0, 0x1b, 0x1b
    bc      12, 2, _8006c274
    lha	r5, 0xc(r31)
    mr	r3, r31
    addi	r4, r31, 0x10
    bl      fn_8006C570
    lhz	r4, 0xe(r31)
    addi	r5, r31, 0x34
    bl      fn_8006C634
    b       _8006c558
_8006c274:
    rlwinm.	r0, r5, 0, 0x1a, 0x1a
    bc      12, 2, _8006c2c0
    lha	r7, 0xc(r31)
    lha	r0, 0xe(r31)
    lwz	r6, 4(r31)
    subf.	r3, r7, r0
    lwz	r4, 0x2c(r31)
    srawi	r0, r6, 1
    addze	r0, r0
    bc      4, 0, _8006c2a0
    neg	r0, r0
_8006c2a0:
    mullw	r3, r3, r4
    lhz	r4, 0x10(r31)
    addi	r5, r31, 0x34
    add	r3, r3, r0
    divw	r0, r3, r6
    add	r3, r7, r0
    bl      fn_8006C634
    b       _8006c558
_8006c2c0:
    rlwinm.	r0, r5, 0, 0x19, 0x19
    bc      12, 2, _8006c4e0
    lhz	r5, 0x10(r31)
    slwi	r4, r4, 0x18
    lwz	r3, 0x38(r31)
    lis	r0, 0x100
    divwu	r4, r4, r5
    add	r3, r3, r4
    stw	r3, 0x38(r31)
    lwz	r3, 0x38(r31)
    cmplw	r3, r0
    bc      12, 0, _8006c2fc
    rlwinm	r0, r3, 0, 0, 7
    subf	r0, r0, r3
    stw	r0, 0x38(r31)
_8006c2fc:
    lbz	r5, 0xc(r31)
    mr	r3, r31
    addi	r4, r31, 0x18
    bl      fn_8006C570
    lbz	r4, 0(r31)
    extsh	r0, r3
    cmpwi	r4, 4
    bc      12, 2, _8006c3e4
    bc      4, 0, _8006c330
    cmpwi	r4, 2
    bc      12, 2, _8006c340
    bc      4, 0, _8006c3c8
    b       _8006c4a4
_8006c330:
    cmpwi	r4, 6
    bc      12, 2, _8006c484
    bc      4, 0, _8006c4a4
    b       _8006c46c
_8006c340:
    lwz	r3, 0x38(r31)
    rlwinm	r5, r3, 0x10, 0x18, 0x1f
    cmplwi	r5, 0x40
    bc      4, 0, _8006c364
    lis     r3, lbl_8019E014@ha
    slwi	r4, r5, 1
    addi	r3, r3, lbl_8019E014@l
    lhax	r3, r3, r4
    b       _8006c3c0
_8006c364:
    cmplwi	r5, 0x80
    bc      4, 0, _8006c384
    subfic	r4, r5, 0x7f
    lis     r3, lbl_8019E014@ha
    slwi	r4, r4, 1
    addi	r3, r3, lbl_8019E014@l
    lhax	r3, r3, r4
    b       _8006c3c0
_8006c384:
    cmplwi	r5, 0xc0
    bc      4, 0, _8006c3a8
    lis     r4, lbl_8019E014@ha
    slwi	r3, r5, 1
    addi	r4, r4, lbl_8019E014@l
    add	r3, r4, r3
    lha	r3, -0x100(r3)
    neg	r3, r3
    b       _8006c3c0
_8006c3a8:
    subfic	r4, r5, 0xff
    lis     r3, lbl_8019E014@ha
    slwi	r4, r4, 1
    addi	r3, r3, lbl_8019E014@l
    lhax	r3, r3, r4
    neg	r3, r3
_8006c3c0:
    mr	r4, r3
    b       _8006c4a8
_8006c3c8:
    lwz	r3, 0x38(r31)
    li	r4, -0x400
    srwi	r3, r3, 0x10
    cmplwi	r3, 0x80
    bc      4, 0, _8006c4a8
    li	r4, 0x400
    b       _8006c4a8
_8006c3e4:
    lwz	r3, 0x38(r31)
    rlwinm	r5, r3, 0x10, 0x18, 0x1f
    cmplwi	r5, 0x40
    bc      4, 0, _8006c408
    lis     r3, lbl_8019E094@ha
    slwi	r4, r5, 1
    addi	r3, r3, lbl_8019E094@l
    lhax	r3, r3, r4
    b       _8006c464
_8006c408:
    cmplwi	r5, 0x80
    bc      4, 0, _8006c428
    subfic	r4, r5, 0x7f
    lis     r3, lbl_8019E094@ha
    slwi	r4, r4, 1
    addi	r3, r3, lbl_8019E094@l
    lhax	r3, r3, r4
    b       _8006c464
_8006c428:
    cmplwi	r5, 0xc0
    bc      4, 0, _8006c44c
    lis     r4, lbl_8019E094@ha
    slwi	r3, r5, 1
    addi	r4, r4, lbl_8019E094@l
    add	r3, r4, r3
    lha	r3, -0x100(r3)
    neg	r3, r3
    b       _8006c464
_8006c44c:
    subfic	r4, r5, 0xff
    lis     r3, lbl_8019E094@ha
    slwi	r4, r4, 1
    addi	r3, r3, lbl_8019E094@l
    lhax	r3, r3, r4
    neg	r3, r3
_8006c464:
    mr	r4, r3
    b       _8006c4a8
_8006c46c:
    lwz	r4, 0x38(r31)
    lis     r3, lbl_8019E094@ha
    addi	r3, r3, lbl_8019E094@l
    rlwinm	r4, r4, 0xf, 0x19, 0x1e
    lhax	r4, r3, r4
    b       _8006c4a8
_8006c484:
    lwz	r4, 0x38(r31)
    lis     r3, lbl_8019E094@ha
    addi	r3, r3, lbl_8019E094@l
    rlwinm	r4, r4, 0x10, 0x18, 0x1f
    subfic	r4, r4, 0xff
    rlwinm	r4, r4, 0x1f, 1, 0x1e
    lhax	r4, r3, r4
    b       _8006c4a8
_8006c4a4:
    li	r4, 0
_8006c4a8:
    cmpwi	r4, 0
    li	r3, 0x200
    bc      4, 0, _8006c4b8
    li	r3, -0x200
_8006c4b8:
    mullw	r6, r4, r0
    lha	r0, 0x14(r31)
    lhz	r4, 0xe(r31)
    addi	r5, r31, 0x34
    add	r6, r6, r3
    srawi	r3, r6, 0xa
    addze	r3, r3
    add	r3, r3, r0
    bl      fn_8006C634
    b       _8006c558
_8006c4e0:
    rlwinm.	r0, r5, 0, 0x18, 0x18
    bc      12, 2, _8006c548
    lbz	r0, 0(r31)
    addi	r4, r31, 0xc
    cmpwi	r0, 8
    bc      12, 2, _8006c518
    bc      4, 0, _8006c53c
    cmpwi	r0, 7
    bc      4, 0, _8006c508
    b       _8006c53c
_8006c508:
    mr	r3, r31
    bl      fn_8006C6E8
    stw	r3, 0x34(r31)
    b       _8006c558
_8006c518:
    mr	r3, r31
    bl      fn_8006C788
    stw	r3, 0x34(r31)
    lwz	r3, 0x34(r31)
    cmpwi	r3, 0
    bc      4, 2, _8006c558
    addi	r0, r3, 1
    stw	r0, 0x34(r31)
    b       _8006c558
_8006c53c:
    li	r0, 0
    stw	r0, 0x34(r31)
    b       _8006c558
_8006c548:
    li	r3, 0
    b       _8006c55c
_8006c550:
    li	r0, 0
    stw	r0, 0x34(r31)
_8006c558:
    li	r3, 1
_8006c55c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006C570(void)
{
    nofralloc
    lwz	r7, 0x2c(r3)
    srawi	r0, r5, 0x1f
    lwz	r6, 0(r4)
    xor	r9, r0, r5
    subf	r9, r0, r9
    srwi	r8, r5, 0x1f
    cmplw	r7, r6
    mr	r5, r9
    bc      4, 0, _8006c5c4
    lbz	r4, 8(r4)
    cmpwi	r7, 0
    srawi	r0, r6, 1
    subf	r3, r4, r9
    addze	r0, r0
    bc      4, 0, _8006c5b0
    neg	r0, r0
_8006c5b0:
    mullw	r3, r7, r3
    add	r3, r3, r0
    divw	r0, r3, r6
    add	r5, r4, r0
    b       _8006c620
_8006c5c4:
    lwz	r3, 4(r3)
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006c620
    lwz	r6, 4(r4)
    subf	r0, r6, r3
    cmplw	r7, r0
    bc      4, 1, _8006c620
    cmplw	r7, r3
    bc      4, 0, _8006c61c
    subf.	r5, r0, r7
    lbz	r3, 9(r4)
    srawi	r0, r6, 1
    subf	r3, r9, r3
    addze	r0, r0
    bc      4, 0, _8006c608
    neg	r0, r0
_8006c608:
    mullw	r3, r5, r3
    add	r3, r3, r0
    divw	r0, r3, r6
    add	r5, r9, r0
    b       _8006c620
_8006c61c:
    lbz	r5, 9(r4)
_8006c620:
    cmpwi	r8, 0
    bc      12, 2, _8006c62c
    neg	r5, r5
_8006c62c:
    mr	r3, r5
    blr
}

asm void fn_8006C634(void)
{
    nofralloc
    clrlwi	r0, r4, 0x18
    cmplwi	r0, 0x40
    bc      4, 0, _8006c654
    lis     r4, lbl_8019E014@ha
    slwi	r0, r0, 1
    addi	r4, r4, lbl_8019E014@l
    lhax	r0, r4, r0
    b       _8006c6b0
_8006c654:
    cmplwi	r0, 0x80
    bc      4, 0, _8006c674
    subfic	r0, r0, 0x7f
    lis     r4, lbl_8019E014@ha
    slwi	r0, r0, 1
    addi	r4, r4, lbl_8019E014@l
    lhax	r0, r4, r0
    b       _8006c6b0
_8006c674:
    cmplwi	r0, 0xc0
    bc      4, 0, _8006c698
    lis     r4, lbl_8019E014@ha
    slwi	r0, r0, 1
    addi	r4, r4, lbl_8019E014@l
    add	r4, r4, r0
    lha	r0, -0x100(r4)
    neg	r0, r0
    b       _8006c6b0
_8006c698:
    subfic	r0, r0, 0xff
    lis     r4, lbl_8019E014@ha
    slwi	r0, r0, 1
    addi	r4, r4, lbl_8019E014@l
    lhax	r0, r4, r0
    neg	r0, r0
_8006c6b0:
    mullw.	r0, r3, r0
    lis	r3, 2
    addi	r4, r3, -0x200
    bc      4, 0, _8006c6c8
    lis	r3, -2
    addi	r4, r3, 0x200
_8006c6c8:
    mulli	r6, r0, 0x7f
    lis	r3, 4
    addi	r0, r3, -0x400
    add	r6, r6, r4
    divw	r0, r6, r0
    neg	r0, r0
    stw	r0, 0(r5)
    blr
}

asm void fn_8006C6E8(void)
{
    nofralloc
    lwz	r5, 0x24(r3)
    lwz	r6, 0x38(r3)
    lwz	r5, 0xc(r5)
    cmpw	r5, r6
    bc      4, 0, _8006c738
    lha	r0, 4(r4)
    subf	r3, r6, r5
    lbz	r4, 2(r4)
    mullw	r0, r3, r0
    neg	r3, r4
    srawi	r0, r0, 0x11
    addze	r0, r0
    cmpw	r3, r0
    bc      4, 1, _8006c724
    mr	r0, r3
_8006c724:
    cmpw	r4, r0
    bc      4, 0, _8006c730
    mr	r0, r4
_8006c730:
    neg	r3, r0
    blr
_8006c738:
    lwz	r3, 0x3c(r3)
    cmpw	r5, r3
    bc      4, 1, _8006c780
    lha	r0, 6(r4)
    subf	r3, r3, r5
    lbz	r4, 3(r4)
    mullw	r0, r3, r0
    neg	r3, r4
    srawi	r0, r0, 0x11
    addze	r0, r0
    cmpw	r3, r0
    bc      4, 1, _8006c76c
    mr	r0, r3
_8006c76c:
    cmpw	r4, r0
    bc      4, 0, _8006c778
    mr	r0, r4
_8006c778:
    neg	r3, r0
    blr
_8006c780:
    li	r3, 0
    blr
}

asm void fn_8006C788(void)
{
    nofralloc
    lwz	r3, 0x24(r3)
    lwz	r5, 0x64(r3)
    cmpwi	r5, 0
    bc      4, 0, _8006c7a8
    lha	r0, 4(r4)
    lbz	r6, 2(r4)
    neg	r0, r0
    b       _8006c7b4
_8006c7a8:
    lha	r0, 6(r4)
    lbz	r6, 3(r4)
    neg	r0, r0
_8006c7b4:
    mullw	r5, r5, r0
    lis	r3, 0x10
    neg	r4, r6
    addi	r0, r3, -0x1000
    mulli	r3, r5, 0x14
    divw	r3, r3, r0
    cmpw	r4, r3
    bc      4, 1, _8006c7d8
    mr	r3, r4
_8006c7d8:
    cmpw	r6, r3
    bgelr	
    mr	r3, r6
    blr
}

asm void fn_8006C7E8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r5, 0
    stw	r0, 0x24(r1)
    li	r0, 0x10
    stw	r31, 0x1c(r1)
    mr	r31, r3
    lwz	r6, -0x7ab0(r2)
    stw	r5, 4(r3)
    mr	r3, r5
    stw	r5, 0x60(r31)
    stw	r6, 8(r1)
    stw	r5, 0xe8(r31)
    mtctr	r0
_8006c820:
    add	r6, r31, r3
    addi	r3, r3, 4
    stw	r5, 0x68(r6)
    stw	r5, 0xa8(r6)
    bc      16, 0, _8006c820
    stw	r4, 0(r31)
    li	r0, 0
    stw	r0, 0xec(r31)
    stw	r0, 0xc(r31)
    stw	r0, 8(r31)
    stw	r0, 0x64(r31)
    bl      OSGetTick
    lis	r4, -0x8000
    li	r6, 0x3e8
    lwz	r4, 0xf8(r4)
    li	r0, 0xa
    addi	r5, r1, 8
    li	r8, 0
    srwi	r7, r4, 2
    li	r4, 0
    divwu	r6, r7, r6
    divwu	r3, r3, r6
    stw	r3, 4(r31)
    mtctr	r0
_8006c880:
    lwzx	r0, r5, r4
    add	r3, r31, r4
    addi	r4, r4, 4
    stw	r0, 0x10(r3)
    stw	r8, 0x38(r3)
    bc      16, 0, _8006c880
    li	r5, 0
    lis     r4, lbl_801327F8@ha
    stw	r5, 0x60(r31)
    lis     r3, lbl_8019E114@ha
    addi	r5, r4, lbl_801327F8@l
    li	r0, 0xa
    addi	r4, r3, lbl_8019E114@l
    li	r3, 0
    mtctr	r0
_8006c8bc:
    lfs	f1, -0x7aac(r2)
    lfsx	f0, r5, r3
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    stwx	r0, r4, r3
    addi	r3, r3, 4
    bc      16, 0, _8006c8bc
    lis     r3, lbl_8019E114@ha
    li	r0, 0xa
    addi	r4, r3, lbl_8019E114@l
    li	r5, 0
    li	r3, 0
    mtctr	r0
_8006c8f8:
    lwzx	r0, r4, r3
    add	r6, r31, r3
    addi	r3, r3, 4
    stw	r0, 0x10(r6)
    stw	r5, 0x38(r6)
    bc      16, 0, _8006c8f8
    li	r0, 0
    stw	r0, 0x60(r31)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006C92C(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    mr	r28, r3
    li	r30, 0
    li	r29, 0
    bl      OSGetTick
    lis	r5, -0x8000
    li	r4, 0x3e8
    lwz	r5, 0xf8(r5)
    lwz	r0, 4(r28)
    srwi	r5, r5, 2
    divwu	r4, r5, r4
    divwu	r3, r3, r4
    stw	r3, 4(r28)
    subf	r7, r0, r3
    lwz	r3, 0(r28)
    lwz	r5, 8(r28)
    lwz	r3, 0xf0(r3)
    lbz	r0, 0x47(r3)
    extsb	r0, r0
    stw	r0, 8(r28)
    lwz	r0, 8(r28)
    slwi	r0, r0, 0xc
    stw	r0, 0xc(r28)
    lwz	r3, 0xe8(r28)
    lwz	r4, 8(r28)
    addi	r0, r3, -1
    stw	r0, 0xe8(r28)
    subf	r4, r5, r4
    lwz	r0, 0xe8(r28)
    cmpwi	r0, 0
    bc      4, 0, _8006c9bc
    li	r0, 0xf
    stw	r0, 0xe8(r28)
_8006c9bc:
    lwz	r0, 0xe8(r28)
    li	r8, 0
    mr	r31, r7
    slwi	r0, r0, 2
    mr	r5, r8
    add	r3, r28, r0
    mr	r6, r8
    stw	r4, 0x68(r3)
    lwz	r0, 0xe8(r28)
    slwi	r0, r0, 2
    add	r3, r28, r0
    stw	r7, 0xa8(r3)
    lwz	r7, 0xe8(r28)
    b       _8006ca24
_8006c9f4:
    slwi	r4, r7, 2
    addi	r7, r7, 1
    addi	r3, r4, 0x68
    addi	r0, r4, 0xa8
    lwzx	r3, r28, r3
    lwzx	r0, r28, r0
    cmpwi	r7, 0x10
    add	r6, r6, r3
    add	r5, r5, r0
    bc      4, 2, _8006ca20
    li	r7, 0
_8006ca20:
    addi	r8, r8, 1
_8006ca24:
    cmpwi	r8, 0x10
    bc      4, 0, _8006ca34
    cmplwi	r5, 0x10
    bc      12, 0, _8006c9f4
_8006ca34:
    cmplwi	r5, 0x10
    bc      4, 1, _8006ca7c
    addic.	r7, r7, -1
    bc      4, 0, _8006ca48
    li	r7, 0xf
_8006ca48:
    slwi	r0, r7, 2
    addic.	r4, r5, -0x10
    add	r3, r28, r0
    lwz	r5, 0xa8(r3)
    lwz	r3, 0x68(r3)
    srawi	r0, r5, 1
    addze	r0, r0
    bc      4, 0, _8006ca6c
    neg	r0, r0
_8006ca6c:
    mullw	r3, r4, r3
    add	r3, r3, r0
    divw	r0, r3, r5
    subf	r6, r0, r6
_8006ca7c:
    lwz	r4, 0x60(r28)
    addi	r3, r4, 1
    slwi	r0, r4, 2
    stw	r3, 0x60(r28)
    add	r3, r28, r0
    stw	r6, 0x38(r3)
    lwz	r0, 0x60(r28)
    cmpwi	r0, 9
    bc      4, 1, _8006caa8
    li	r0, 0
    stw	r0, 0x60(r28)
_8006caa8:
    li	r7, 0
    li	r0, 0xa
    mr	r4, r7
    li	r3, 0x24
    mtctr	r0
_8006cabc:
    lwz	r5, 0x60(r28)
    addi	r0, r3, 0x10
    addi	r6, r5, 1
    slwi	r5, r5, 2
    stw	r6, 0x60(r28)
    addi	r5, r5, 0x38
    lwzx	r6, r28, r5
    lwzx	r5, r28, r0
    lwz	r0, 0x60(r28)
    mullw	r5, r6, r5
    cmpwi	r0, 9
    add	r7, r7, r5
    bc      4, 1, _8006caf4
    stw	r4, 0x60(r28)
_8006caf4:
    addi	r3, r3, -4
    bc      16, 0, _8006cabc
    stw	r7, 0x64(r28)
    li	r25, 0
    li	r27, 0
_8006cb08:
    lwz	r3, 0(r28)
    addi	r0, r27, 0xf4
    lwzx	r26, r3, r0
    cmplwi	r26, 0
    bc      12, 2, _8006cb94
    lwz	r0, 0x28(r26)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8006cb94
    mr	r3, r26
    mr	r4, r31
    bl      fn_8006C190
    lwz	r4, 0x28(r26)
    clrlwi.	r0, r4, 0x1f
    bc      12, 2, _8006cb78
    lwz	r0, 0x30(r26)
    cmplwi	r0, 0
    bc      4, 2, _8006cb78
    lwz	r0, 0x34(r26)
    li	r3, -0x7f
    cmpwi	r0, -0x7f
    bc      12, 0, _8006cb60
    mr	r3, r0
_8006cb60:
    cmpwi	r3, 0x7f
    li	r0, 0x7f
    bc      12, 1, _8006cb70
    mr	r0, r3
_8006cb70:
    rlwinm	r3, r4, 0, 0x1d, 0x1d
    b       _8006cb80
_8006cb78:
    li	r0, 0
    li	r3, 0
_8006cb80:
    cmpwi	r3, 0
    bc      12, 2, _8006cb90
    add	r30, r30, r0
    b       _8006cb94
_8006cb90:
    add	r29, r29, r0
_8006cb94:
    addi	r25, r25, 1
    addi	r27, r27, 4
    cmplwi	r25, 0x40
    bc      12, 0, _8006cb08
    lwz	r3, 0(r28)
    cmpwi	r30, 0x80
    li	r0, 0x80
    lwz	r6, 0x11f4(r3)
    bc      12, 1, _8006cbbc
    mr	r0, r30
_8006cbbc:
    cmpwi	r0, -0x80
    li	r4, -0x80
    bc      12, 0, _8006cbcc
    mr	r4, r0
_8006cbcc:
    cmpwi	r4, 0
    bc      4, 0, _8006cbec
    lis     r3, lbl_8019DF90@ha
    addi	r0, r3, lbl_8019DF90@l
    subf	r3, r4, r0
    lbz	r0, 0(r3)
    neg	r4, r0
    b       _8006cbf8
_8006cbec:
    lis     r3, lbl_8019DF90@ha
    addi	r3, r3, lbl_8019DF90@l
    lbzx	r4, r3, r4
_8006cbf8:
    cmpwi	r6, 0xff
    bc      4, 0, _8006cc40
    cmpwi	r4, 0
    li	r3, 0x7f
    bc      4, 0, _8006cc10
    li	r3, -0x7f
_8006cc10:
    mullw	r4, r4, r6
    li	r0, 0xff
    cmpwi	r29, 0
    li	r5, 0x7f
    add	r4, r4, r3
    divw	r4, r4, r0
    bc      4, 0, _8006cc30
    li	r5, -0x7f
_8006cc30:
    mullw	r3, r29, r6
    li	r0, 0xff
    add	r3, r3, r5
    divw	r29, r3, r0
_8006cc40:
    add	r3, r4, r29
    li	r0, 0x80
    cmpwi	r3, 0x80
    bc      12, 1, _8006cc54
    mr	r0, r3
_8006cc54:
    cmpwi	r0, -0x80
    li	r26, -0x80
    bc      12, 0, _8006cc64
    mr	r26, r0
_8006cc64:
    lwz	r0, 0xec(r28)
    cmpw	r0, r26
    bc      12, 2, _8006ccb0
    cmpwi	r26, 0
    stw	r26, 0xec(r28)
    bc      4, 2, _8006cc98
    lwz	r3, 0(r28)
    li	r4, 0x400
    li	r5, 0
    lwz	r3, 0xf0(r3)
    lwz	r3, 0(r3)
    bl      fn_800139E8
    b       _8006ccb0
_8006cc98:
    lwz	r3, 0(r28)
    mr	r5, r26
    li	r4, 0x600
    lwz	r3, 0xf0(r3)
    lwz	r3, 0(r3)
    bl      fn_800139E8
_8006ccb0:
    mr	r3, r26
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_8006CCC8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    lis	r0, 0x4330
    li	r4, 0
    lfd	f1, -0x7aa0(r2)
    lwz	r3, -0x7aa8(r2)
    lwz	r5, -0x76cc(r13)
    stw	r4, -0x7714(r13)
    stw	r3, -0x7718(r13)
    lhz	r3, 0xe(r5)
    stw	r0, 8(r1)
    stw	r3, 0xc(r1)
    lfd	f0, 8(r1)
    stw	r0, 0x10(r1)
    fsubs	f0, f0, f1
    stfs	f0, -0x771c(r13)
    lhz	r0, 0x10(r5)
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    stfs	f0, -0x7720(r13)
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006CD20(void)
{
    nofralloc
    stfs	f1, -0x771c(r13)
    stfs	f2, -0x7720(r13)
    blr
}

asm void fn_8006CD2C(void)
{
    nofralloc
    lfs	f0, -0x771c(r13)
    stfs	f0, 0(r3)
    lfs	f0, -0x7720(r13)
    stfs	f0, 0(r4)
    blr
}

asm void fn_8006CD40(void)
{
    nofralloc
    lfs	f0, -0x7720(r13)
    stfs	f1, -0x7720(r13)
    fmr	f1, f0
    blr
}

asm void fn_8006CD50(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    lfs	f1, -0x7a98(r2)
    stw	r0, 0x54(r1)
    addi	r3, r1, 8
    fmr	f3, f1
    lfs	f6, -0x7a94(r2)
    fmr	f5, f1
    lfs	f2, -0x7720(r13)
    lfs	f4, -0x771c(r13)
    bl      fn_80015EE8
    addi	r3, r1, 8
    li	r4, 1
    bl      GXIntToFloatCopy
    bl      QuatNormalizeCompare
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      GXLoadMatIdxTripleToXF
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_8006CDA8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      QuatNormalizeCompare
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      GXLoadMatIdxTripleToXF
    lwz	r12, -0x7714(r13)
    cmplwi	r12, 0
    bc      12, 2, _8006cdd8
    mtctr	r12
    bctrl
_8006cdd8:
    bl      QuatNormalizeCompare
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      GXLoadMatIdxTripleToXF
    bl      fn_8006CE44
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006CDFC(void)
{
    nofralloc
    lbz	r6, 0(r3)
    addi	r4, r13, -0x7718
    lbz	r5, 1(r3)
    lbz	r0, 2(r3)
    stb	r6, -0x7718(r13)
    stb	r5, 1(r4)
    stb	r0, 2(r4)
    blr
}

asm void fn_8006CE1C(void)
{
    nofralloc
    lfs	f0, -0x7a90(r2)
    addi	r3, r13, -0x7718
    stwu	r1, -0x10(r1)
    fmuls	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    stb	r0, 3(r3)
    addi	r1, r1, 0x10
    blr
}

asm void fn_8006CE44(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    addi	r3, r13, -0x7718
    stw	r0, 0x14(r1)
    lbz	r0, 3(r3)
    cmplwi	r0, 0
    bc      12, 2, _8006cfe8
    li	r3, 0
    li	r4, 7
    li	r5, 0
    bl      GXSetTexGenCached
    li	r3, 1
    bl      GXSetChanAmbColorCached
    li	r3, 0
    bl      GXSetNumTexGensCached
    li	r3, 1
    bl      ModelSetCachedNumTexGens
    li	r3, 0
    bl      ModelSetCachedState_840
    li	r3, 0
    bl      ModelClearCacheSlot_B28
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 0
    li	r8, 2
    li	r9, 2
    bl      LightCtrl_SetCachedRec_C30
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      LightCtrl_SetCachedPair_6C
    li	r3, 0
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 4
    bl      ModelSetCachedMaterial_570
    li	r3, 0
    li	r4, 0xf
    li	r5, 0xf
    li	r6, 0xf
    li	r7, 2
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
    li	r7, 1
    bl      ModelSetCachedParam_1F0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      ModelSetCachedParam_430
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      LightCtrl_SetCachedColor_1C
    li	r3, 2
    bl      LightCtrl_SetCachedCullMode
    li	r3, 0x200
    bl      GXLoadMtxArray
    lwz	r0, -0x7718(r13)
    addi	r4, r1, 8
    li	r3, 1
    stw	r0, 8(r1)
    bl      __GXSetTexRegion
    li	r3, 0x80
    li	r4, 7
    li	r5, 4
    bl      GXBegin
    lfs	f0, -0x7a98(r2)
    lis	r3, -0x33ff
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7a98(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7a8c(r2)
    stfs	f0, -0x8000(r3)
    lfs	f1, -0x771c(r13)
    stfs	f1, -0x8000(r3)
    lfs	f0, -0x7a98(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7a8c(r2)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f1, -0x7720(r13)
    stfs	f1, -0x8000(r3)
    lfs	f0, -0x7a8c(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7a98(r2)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, -0x7a8c(r2)
    stfs	f0, -0x8000(r3)
_8006cfe8:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

#pragma force_active off
