typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void DCFlushRange(void);
extern void GXResetWriteGatherPipe(void);
extern void OSGetArenaHi(void);
extern void OSReport(void);
extern void OSSetArenaHi(void);
extern void __GXSetDirtyState(void);
extern void _restgpr_19(void);
extern void _restgpr_24(void);
extern void _restgpr_25(void);
extern void _restgpr_27(void);
extern void _savegpr_19(void);
extern void _savegpr_24(void);
extern void _savegpr_25(void);
extern void _savegpr_27(void);
extern void __GXGetTexBufferSize(void);
extern void GXInitTexObj(void);
extern void fn_80035EC4(void);
extern void __GXSetTexRegion(void);
extern void GXWritePrimitiveFifo(void);
extern void PSVecNormalize3(void);
extern void PSMTXLookAtNoUp(void);
extern void PSMTXReflect(void);
extern void fn_80070D94(void);
extern void fn_80070E00(void);
extern void fn_80071794(void);
extern void fn_800717BC(void);
extern void fn_80072168(void);
extern void fn_800723B8(void);
extern void fn_800723D8(void);
extern void fn_80072404(void);
extern void GXLoadMtxArray(void);
extern void GXSetMatrixIndexA(void);
extern void GXSetMatrixIndexB(void);
extern void LightCtrl_SetCachedFog(void);
extern void LightCtrl_InitChannels4(void);
extern void LightCtrl_SetCachedColor_1C(void);
extern void LightCtrl_SetCachedParam_2C(void);
extern void LightCtrl_SetCachedPair_6C(void);
extern void ModelSetCachedParam_F0(void);
extern void ModelSetCachedParam_1F0(void);
extern void ModelSetCachedParam_2F0(void);
extern void ModelSetCachedParam_430(void);
extern void ModelSetCachedMaterial_570(void);
extern void GXCachedSetTevSwapTable(void);
extern void ModelSetCachedState_6B0(void);
extern void ModelSetCachedNumTexGens(void);
extern void ModelSetCachedTex_704(void);
extern void ModelCacheMaterialParams(void);
extern void ModelSetCachedState_840(void);
extern void fn_800738E0(void);
extern void fn_80073A58(void);
extern void fn_80073B50(void);
extern void ModelClearCacheSlot_B28(void);
extern void ModelSetCachedPair5_B28(void);
extern void GXSetNumTexGensCached(void);
extern void GXSetChanAmbColorCached(void);
extern void LightCtrl_SetCachedRec_C30(void);
extern void GXColorClampScale(void);
extern void GXColorScale(void);
extern void fn_80078538(void);
extern void fn_800786B0(void);
extern void fn_80078768(void);
extern void GXWriteFifoWord(void);
extern void GXWriteFifoWordPair(void);
extern void fn_800789D8(void);
extern void fn_80078C28(void);
extern void fn_80078CDC(void);
extern void fn_80078D60(void);
extern void QuatNormalizeCompare(void);
extern void fn_8006D7F4(void);
extern void mtx_gpstack_push(void);
extern void mtx_gpstack_pop(void);
extern void fn_8006DB74(void);
extern void fn_8006DD14(void);
extern void fn_8006DFC4(void);
extern void fn_8006E14C(void);
extern void lbl_8006E1B0(void);
extern void memset(void);
extern unsigned char lbl_80094E20[16];
extern unsigned char lbl_8015AD10[12];
extern unsigned char lbl_8015AD1C[12];
extern unsigned char lbl_8015AD28[16];
extern unsigned char lbl_8015AD48[272];
extern unsigned char lbl_8019F008[28];
extern unsigned char lbl_8019F040[240];
extern unsigned char lbl_8019F130[28];
extern unsigned char lbl_8019F14C[12];
extern unsigned char lbl_8019F158[168];
extern unsigned char lbl_8019F200[16416];
extern unsigned char lbl_801A3220[96];
asm void fn_80074D88(void);
asm void fn_80075080(void);
asm void AvDispSetupModel(void);
asm void fn_800756B0(void);
asm void fn_80075908(void);
asm void fn_80075C78(void);
asm void fn_80075D48(void);
asm void fn_80076134(void);
asm void fn_80076238(void);
asm void fn_800764A0(void);
asm void ModelBlendMatrixPush(void);
asm void fn_8007698C(void);
asm void AvDispTraverseMaterialCache(void);
asm void fn_80077240(void);
asm void fn_80077384(void);
asm void fn_80077488(void);
asm void fn_800775EC(void);
asm void fn_80077654(void);
asm void fn_80077714(void);
asm void AvDispInitModel(void);
asm void AvDispClearMatrixStack(void);
asm void AvDispAllocMatrixStack(void);
asm void fn_80077A18(void);
asm void fn_80077A20(void);
asm void AvDispGetModelMatrices(void);
asm void AvDispSetAmbient(void);
asm void avdispWarnNotEffectiveModel(void);
asm void avdispWarnNotSkinningModel(void);
asm void fn_80077BAC(void);
asm void fn_80077BBC(void);
asm void fn_80077BD4(void);
asm void fn_80077D40(void);
asm void fn_80077E0C(void);
asm void fn_80077E7C(void);
asm void fn_80077F8C(void);
asm void fn_800780A4(void);
asm void fn_800781B8(void);
asm void GXWriteFifoByte(void);
asm void fn_80078360(void);
#pragma push
#pragma force_active on

asm void fn_80074D88(void)
{
    nofralloc
    stwu r1, -0x40(r1)
    mflr r0
    stw r0, 0x44(r1)
    stw r31, 0x3c(r1)
    mr r31, r4
    stw r30, 0x38(r1)
    mr r30, r3
    lwz r0, -0x766c(r13)
    cmplwi r0, 0
    beq _80075068
    bl mtx_gpstack_push
    lwz r3, -0x76c0(r13)
    li r4, 0x1e
    li r5, 0
    bl GXWritePrimitiveFifo
    lfs f0, -0x79c0(r2)
    lis r6, -0x2000
    lwz r3, -0x76c0(r13)
    li r4, 0x2d
    lfs f1, -0x79b8(r2)
    li r5, 0
    stfs f0, 0x20(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x24(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x28(r3)
    stfs f0, 0xc(r6)
    stfs f0, 0x1c(r6)
    stfs f1, 0x2c(r6)
    lwz r3, -0x76c0(r13)
    bl GXWritePrimitiveFifo
    bl QuatNormalizeCompare
    lis     r3, lbl_8019F008@ha
    lfs f1, -0x79b4(r2)
    addi r6, r3, lbl_8019F008@l
    lwz r3, -0x76c0(r13)
    lfs f0, 4(r6)
    li r4, 0x4c
    li r5, 0
    fneg f0, f0
    fmuls f0, f1, f0
    stfs f0, 0(r3)
    lfs f0, 0xc(r6)
    lwz r3, -0x76c0(r13)
    fmuls f0, f1, f0
    stfs f0, 0x14(r3)
    lwz r3, -0x76c0(r13)
    stfs f1, 8(r3)
    lwz r3, -0x76c0(r13)
    stfs f1, 0x18(r3)
    lwz r3, -0x76c0(r13)
    bl GXWritePrimitiveFifo
    bl QuatNormalizeCompare
    lfs f0, -0x79b4(r2)
    li r4, 0x49
    lwz r3, -0x76c0(r13)
    li r5, 0
    stfs f0, 0(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x14(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 8(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x18(r3)
    lwz r3, -0x76c0(r13)
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    lis     r3, lbl_8019F158@ha
    lwz r4, 0xc(r31)
    addi r3, r3, lbl_8019F158@l
    bl ModelCacheMaterialParams
    lwz r3, 0x10(r31)
    lwz r4, 4(r31)
    lwz r5, 0xc(r31)
    bl fn_800738E0
    lwz r3, 4(r31)
    li r4, 0
    li r5, 1
    li r6, 0x2d
    li r7, 0
    li r8, 0x49
    bl ModelSetCachedPair5_B28
    lfs f1, -0x79c0(r2)
    addi r4, r1, 0x14
    lfs f3, -0x7674(r13)
    li r3, 1
    stfs f1, 0x14(r1)
    li r5, 1
    lfs f2, -0x79b4(r2)
    stfs f1, 0x18(r1)
    lfs f0, 0x3c(r30)
    fmuls f0, f0, f3
    stfs f1, 0x20(r1)
    stfs f1, 0x28(r1)
    fneg f1, f0
    fmuls f0, f2, f0
    fmuls f1, f2, f1
    stfs f0, 0x24(r1)
    stfs f1, 0x1c(r1)
    bl fn_80073A58
    li r0, 0
    li r5, 0
    stw r0, 8(r1)
    li r6, 7
    li r7, 1
    li r8, 0
    stw r0, 0xc(r1)
    li r9, 0
    li r10, 0
    lwz r3, 0(r31)
    lwz r4, 0x10(r31)
    bl fn_80073B50
    lwz r4, 0x10(r31)
    lis     r3, lbl_8019F040@ha
    addi r3, r3, lbl_8019F040@l
    addi r0, r4, 1
    stw r0, 0x10(r31)
    lwz r4, 4(r31)
    addi r0, r4, 1
    stw r0, 4(r31)
    lwz r4, 0xc(r31)
    addi r0, r4, 1
    stw r0, 0xc(r31)
    lwz r4, 0xc(r31)
    bl ModelCacheMaterialParams
    lwz r3, 4(r31)
    li r4, 0
    li r5, 0
    li r6, 0x1e
    li r7, 0
    li r8, 0x4c
    bl ModelSetCachedPair5_B28
    lwz r0, -0x7670(r13)
    addi r4, r1, 0x10
    li r3, 1
    stw r0, 0x10(r1)
    bl ModelSetCachedTex_704
    lwz r3, 0(r31)
    li r4, 0xd
    bl GXCachedSetTevSwapTable
    lwz r3, 0(r31)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lwz r3, 0(r31)
    li r6, 4
    lwz r4, 4(r31)
    lwz r5, 0xc(r31)
    bl ModelSetCachedMaterial_570
    lwz r3, 0(r31)
    li r4, 0
    li r5, 8
    li r6, 0xe
    li r7, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r31)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r31)
    li r4, 0
    li r5, 6
    li r6, 6
    li r7, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r31)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r31)
    addi r0, r3, 1
    stw r0, 0(r31)
    lwz r3, 4(r31)
    addi r0, r3, 1
    stw r0, 4(r31)
    lwz r3, 0xc(r31)
    addi r0, r3, 1
    stw r0, 0xc(r31)
_80075068:
    lwz r0, 0x44(r1)
    lwz r31, 0x3c(r1)
    lwz r30, 0x38(r1)
    mtlr r0
    addi r1, r1, 0x40
    blr
}

asm void fn_80075080(void)
{
    nofralloc
    stwu r1, -0x50(r1)
    mflr r0
    stw r0, 0x54(r1)
    stfd f31, 0x40(r1)
    psq_st f31, 0x48(r1), 0, 0
    stw r31, 0x3c(r1)
    stw r30, 0x38(r1)
    mr r30, r3
    lwz r3, 0(r3)
    li r31, 0
    li r4, 0
    rlwinm. r0, r3, 0, 0x1c, 0x1c
    beq _800750C0
    li r4, 1
    li r31, 1
    b _800750CC
_800750C0:
    rlwinm. r0, r3, 0, 0x18, 0x18
    beq _800750CC
    li r31, 1
_800750CC:
    lis     r3, lbl_8019F130@ha
    cmpwi r4, 0
    addi r3, r3, lbl_8019F130@l
    lfs f31, 0xc(r3)
    beq _80075128
    lbz r5, 8(r30)
    lis r4, 0x4330
    lbz r3, 9(r30)
    lbz r0, 0xa(r30)
    stw r5, 0x1c(r1)
    lfd f1, -0x79b0(r2)
    stw r4, 0x18(r1)
    lfd f0, 0x18(r1)
    stw r3, 0x24(r1)
    fsubs f4, f0, f1
    stw r4, 0x20(r1)
    lfd f0, 0x20(r1)
    stw r0, 0x2c(r1)
    fsubs f5, f0, f1
    stw r4, 0x28(r1)
    lfd f0, 0x28(r1)
    fsubs f6, f0, f1
    b _80075134
_80075128:
    lfs f4, -0x79bc(r2)
    fmr f5, f4
    fmr f6, f4
_80075134:
    lis     r3, lbl_8019F130@ha
    lfs f0, -0x79bc(r2)
    addi r4, r3, lbl_8019F130@l
    addi r3, r1, 0xc
    lfs f2, 0(r4)
    fmuls f3, f0, f31
    lfs f1, 4(r4)
    lfs f0, 8(r4)
    fmuls f2, f4, f2
    fmuls f1, f5, f1
    fmuls f0, f6, f0
    fctiwz f3, f3
    fctiwz f2, f2
    fctiwz f1, f1
    fctiwz f0, f0
    stfd f3, 0x28(r1)
    stfd f2, 0x20(r1)
    lwz r6, 0x2c(r1)
    stfd f1, 0x18(r1)
    lwz r5, 0x24(r1)
    stfd f0, 0x30(r1)
    lwz r4, 0x1c(r1)
    lwz r0, 0x34(r1)
    stb r6, 0x13(r1)
    stb r5, 0x10(r1)
    stb r4, 0x11(r1)
    stb r0, 0x12(r1)
    lwz r0, 0x10(r1)
    stw r0, 0xc(r1)
    bl GXSetMatrixIndexB
    cmpwi r31, 0
    beq _800751D0
    lbz r4, 4(r30)
    lbz r3, 5(r30)
    lbz r0, 6(r30)
    stb r4, 0x14(r1)
    stb r3, 0x15(r1)
    stb r0, 0x16(r1)
    b _800751E0
_800751D0:
    li r0, 0xff
    stb r0, 0x14(r1)
    stb r0, 0x15(r1)
    stb r0, 0x16(r1)
_800751E0:
    lbz r4, 0x11(r30)
    lis r0, 0x4330
    stw r0, 0x30(r1)
    addi r3, r1, 8
    lfd f1, -0x79b0(r2)
    stw r4, 0x34(r1)
    lfd f0, 0x30(r1)
    fsubs f0, f0, f1
    fmuls f0, f31, f0
    fctiwz f0, f0
    stfd f0, 0x28(r1)
    lwz r0, 0x2c(r1)
    stb r0, 0x17(r1)
    lwz r0, 0x14(r1)
    stw r0, 8(r1)
    bl GXSetMatrixIndexA
    psq_l f31, 0x48(r1), 0, 0
    lwz r0, 0x54(r1)
    lfd f31, 0x40(r1)
    lwz r31, 0x3c(r1)
    lwz r30, 0x38(r1)
    mtlr r0
    addi r1, r1, 0x50
    blr
}

asm void AvDispSetupModel(void)
{
    nofralloc
    stwu r1, -0x50(r1)
    mflr r0
    stw r0, 0x54(r1)
    addi r11, r1, 0x50
    bl _savegpr_25
    lis     r3, lbl_8019F040@ha
    lfs f1, -0x79c0(r2)
    addi r31, r3, lbl_8019F040@l
    lfs f3, -0x79b8(r2)
    addi r5, r31, 0xf0
    li r0, 0
    addi r3, r31, 0xe0
    lwz r7, -0x7518(r2)
    lwz r6, -0x79a8(r2)
    li r4, 1
    fmr f2, f1
    stw r7, 0x1c(r1)
    stw r6, 0x18(r1)
    stfs f3, 8(r5)
    stfs f3, 4(r5)
    stfs f3, 0xf0(r31)
    stw r4, -0x764c(r13)
    stw r0, -0x7648(r13)
    stw r0, 0xe0(r31)
    stw r0, 4(r3)
    stw r0, 8(r3)
    bl fn_8006D7F4
    addi r3, r31, 0x138
    bl fn_8006DB74
    addi r3, r31, 0x138
    li r4, 0x21
    li r5, 0
    bl GXWritePrimitiveFifo
    lfs f1, -0x79c0(r2)
    li r6, -1
    lfs f0, -0x79b8(r2)
    addi r3, r31, 0x10c
    stfs f1, 0x20(r1)
    stfs f0, 0x24(r1)
    lwz r5, 0x20(r1)
    stfs f1, 0x28(r1)
    lwz r4, 0x24(r1)
    lwz r0, 0x28(r1)
    stw r6, -0x7660(r13)
    stw r6, -0x7664(r13)
    stw r5, 0x10c(r31)
    stw r4, 0x110(r31)
    stw r0, 0x114(r31)
    bl PSVecNormalize3
    lfs f0, -0x79b8(r2)
    li r6, 1
    li r0, 0
    lfs f2, -0x79a4(r2)
    addi r7, r31, 0x100
    lfs f1, -0x79c0(r2)
    stfs f0, -0x7650(r13)
    addi r3, r31, 0x180
    li r4, 0xff
    li r5, 0x20
    stfs f0, -0x7654(r13)
    stfs f0, -0x7658(r13)
    stw r6, -0x765c(r13)
    stw r0, -0x7678(r13)
    stfs f1, 0(r7)
    stfs f1, 4(r7)
    stfs f2, 8(r7)
    bl memset
    addi r3, r31, 0x180
    li r4, 0
    li r5, 0x20
    addi r3, r3, 0x20
    bl memset
    addi r3, r31, 0x180
    li r4, 0x40
    bl DCFlushRange
    addi r3, r31, 0x1c0
    addi r4, r31, 0x180
    li r5, 0x10
    li r6, 4
    li r7, 1
    li r8, 0
    li r9, 0
    li r10, 0
    bl GXInitTexObj
    lfs f1, -0x79c0(r2)
    addi r3, r31, 0x1c0
    li r4, 1
    li r5, 1
    fmr f2, f1
    li r6, 0
    fmr f3, f1
    li r7, 0
    li r8, 0
    bl fn_80035EC4
    li r30, 0
    addi r7, r31, 0x1e0
    mr r29, r30
    li r28, 0
_800753C8:
    mr r11, r30
    slwi r3, r30, 6
    li r27, 0
    li r12, 0
_800753D8:
    li r0, 2
    mr r10, r29
    slwi r4, r29, 2
    li r26, 0
    li r9, 0
    mtctr r0
_800753F0:
    slwi r5, r9, 1
    li r6, 0
    add r25, r3, r5
    rlwinm r0, r12, 2, 0x18, 0x1d
    add r25, r25, r7
    addi r5, r5, 2
    stb r6, 0(r25)
    addi r8, r12, 1
    addi r9, r9, 4
    stb r6, 1(r25)
    stb r0, 0x20(r25)
    rlwinm r0, r8, 2, 0x18, 0x1d
    addi r8, r8, 1
    stb r4, 0x21(r25)
    add r25, r3, r5
    add r25, r25, r7
    addi r5, r5, 2
    stb r6, 0(r25)
    stb r6, 1(r25)
    stb r0, 0x20(r25)
    rlwinm r0, r8, 2, 0x18, 0x1d
    addi r8, r8, 1
    stb r4, 0x21(r25)
    add r25, r3, r5
    add r25, r25, r7
    addi r5, r5, 2
    stb r6, 0(r25)
    stb r6, 1(r25)
    stb r0, 0x20(r25)
    rlwinm r0, r8, 2, 0x18, 0x1d
    stb r4, 0x21(r25)
    add r25, r3, r5
    add r25, r25, r7
    stb r6, 0(r25)
    stb r6, 1(r25)
    stb r0, 0x20(r25)
    stb r4, 0x21(r25)
    addi r4, r4, 4
    slwi r5, r9, 1
    add r25, r3, r5
    rlwinm r0, r12, 2, 0x18, 0x1d
    add r25, r25, r7
    addi r5, r5, 2
    stb r6, 0(r25)
    addi r8, r12, 1
    addi r9, r9, 4
    addi r10, r10, 2
    stb r6, 1(r25)
    addi r26, r26, 1
    stb r0, 0x20(r25)
    rlwinm r0, r8, 2, 0x18, 0x1d
    addi r8, r8, 1
    stb r4, 0x21(r25)
    add r25, r3, r5
    add r25, r25, r7
    addi r5, r5, 2
    stb r6, 0(r25)
    stb r6, 1(r25)
    stb r0, 0x20(r25)
    rlwinm r0, r8, 2, 0x18, 0x1d
    addi r8, r8, 1
    stb r4, 0x21(r25)
    add r25, r3, r5
    add r25, r25, r7
    addi r5, r5, 2
    stb r6, 0(r25)
    stb r6, 1(r25)
    stb r0, 0x20(r25)
    rlwinm r0, r8, 2, 0x18, 0x1d
    stb r4, 0x21(r25)
    add r25, r3, r5
    add r25, r25, r7
    stb r6, 0(r25)
    stb r6, 1(r25)
    stb r0, 0x20(r25)
    stb r4, 0x21(r25)
    addi r4, r4, 4
    bdnz _800753F0
    addi r27, r27, 1
    addi r3, r3, 0x40
    cmpwi r27, 0x10
    addi r12, r12, 4
    addi r11, r11, 1
    blt _800753D8
    addi r28, r28, 1
    addi r29, r29, 4
    cmpwi r28, 0x10
    addi r30, r30, 0x10
    blt _800753C8
    addi r3, r31, 0x1e0
    li r4, 0x4000
    bl DCFlushRange
    addi r3, r31, 0x118
    addi r4, r31, 0x1e0
    li r5, 0x40
    li r6, 0x40
    li r7, 6
    li r8, 2
    li r9, 2
    li r10, 0
    bl GXInitTexObj
    lfs f1, -0x79c0(r2)
    addi r3, r31, 0x118
    li r4, 3
    li r5, 1
    fmr f2, f1
    li r6, 0
    fmr f3, f1
    li r7, 0
    li r8, 0
    bl fn_80035EC4
    lwz r0, 0x18(r1)
    li r4, 0
    lfs f0, -0x79b8(r2)
    li r3, 0
    stw r4, -0x766c(r13)
    li r4, 1
    li r5, 0
    li r6, 0
    stw r0, -0x7670(r13)
    stfs f0, -0x7674(r13)
    bl LightCtrl_SetCachedColor_1C
    li r3, 0
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 3
    bl LightCtrl_SetCachedParam_2C
    li r3, 1
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 0
    bl LightCtrl_SetCachedParam_2C
    li r3, 2
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 1
    bl LightCtrl_SetCachedParam_2C
    li r3, 3
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 2
    bl LightCtrl_SetCachedParam_2C
    lwz r0, 0x1c(r1)
    addi r4, r1, 0x14
    li r3, 0
    stw r0, 0x14(r1)
    bl ModelSetCachedTex_704
    lwz r0, 0x1c(r1)
    addi r4, r1, 0x10
    li r3, 1
    stw r0, 0x10(r1)
    bl ModelSetCachedTex_704
    lwz r0, 0x1c(r1)
    addi r4, r1, 0xc
    li r3, 2
    stw r0, 0xc(r1)
    bl ModelSetCachedTex_704
    lwz r0, 0x1c(r1)
    addi r4, r1, 8
    li r3, 3
    stw r0, 8(r1)
    bl ModelSetCachedTex_704
    li r0, 0
    stw r0, -0x7680(r13)
    stw r0, -0x7668(r13)
    stw r0, -0x767c(r13)
    addi r11, r1, 0x50
    bl _restgpr_25
    lwz r0, 0x54(r1)
    mtlr r0
    addi r1, r1, 0x50
    blr
}

asm void fn_800756B0(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_25
    lis     r5, lbl_8019F040@ha
    li r0, 1
    addi r31, r5, lbl_8019F040@l
    mr r29, r3
    stb r0, 0x41e0(r31)
    mr r30, r4
    lwz r0, 4(r3)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _800756EC
    addi r30, r30, 0x20
_800756EC:
    lwz r0, -0x7648(r13)
    cmpwi r0, 0
    beq _8007570C
    addi r3, r31, 0x20
    li r4, 0x24
    li r5, 0
    bl GXWritePrimitiveFifo
    b _8007571C
_8007570C:
    addi r3, r31, 0x138
    li r4, 0x24
    li r5, 0
    bl GXWritePrimitiveFifo
_8007571C:
    addi r28, r31, 0xe0
    addi r26, r31, 0x50
    li r25, 0
    li r27, 0x33
_8007572C:
    lwz r0, 0(r28)
    cmpwi r0, 0
    beq _8007574C
    mr r3, r26
    mr r4, r27
    li r5, 0
    bl GXWritePrimitiveFifo
    b _8007575C
_8007574C:
    mr r4, r27
    addi r3, r31, 0x138
    li r5, 0
    bl GXWritePrimitiveFifo
_8007575C:
    addi r25, r25, 1
    addi r27, r27, 3
    cmpwi r25, 3
    addi r26, r26, 0x30
    addi r28, r28, 4
    blt _8007572C
    mr r3, r30
    bl fn_80075080
    lwz r0, -0x7638(r13)
    addi r9, r31, 0x41e0
    lwz r8, 0xc(r30)
    li r4, -1
    li r3, 0x10
    li r7, 0
    li r6, 0xf
    li r5, 7
    cmpwi r0, 0
    stw r8, 0x10(r9)
    stb r7, 2(r9)
    stw r6, 0x14(r9)
    stw r5, 0x18(r9)
    stb r4, 3(r9)
    stb r4, 4(r9)
    stb r4, 5(r9)
    stw r3, 8(r9)
    stw r3, 0xc(r9)
    beq _800757DC
    lwz r0, -0x7640(r13)
    addi r4, r1, 0xc
    li r3, 2
    stw r0, 0xc(r1)
    bl ModelSetCachedTex_704
_800757DC:
    lwz r0, -0x763c(r13)
    cmpwi r0, 0
    beq _800757FC
    lwz r0, -0x7644(r13)
    addi r4, r1, 8
    li r3, 3
    stw r0, 8(r1)
    bl ModelSetCachedTex_704
_800757FC:
    addi r5, r31, 0x41e0
    li r3, 4
    li r0, 5
    stw r3, 0x1c(r5)
    stw r0, 0x20(r5)
    lwz r0, 0(r30)
    rlwinm. r0, r0, 0, 0x1a, 0x1a
    beq _80075828
    lwz r0, 0x40(r30)
    clrlwi r0, r0, 0x1c
    stw r0, 0x1c(r5)
_80075828:
    lwz r0, 0(r30)
    rlwinm. r0, r0, 0, 0x19, 0x19
    beq _80075840
    lwz r0, 0x40(r30)
    rlwinm r0, r0, 0x1c, 0x1c, 0x1f
    stw r0, 0x20(r5)
_80075840:
    lwz r4, 0x1c(r5)
    li r3, 1
    lwz r5, 0x20(r5)
    li r6, 0
    bl LightCtrl_SetCachedColor_1C
    lwz r0, -0x7678(r13)
    lis r5, 1
    addi r4, r31, 0x41e0
    li r6, -1
    li r3, 0
    addi r5, r5, -1
    cmpwi r0, 0
    stb r6, 1(r4)
    stw r6, 0x24(r4)
    stw r6, 0x28(r4)
    stw r6, 0x2c(r4)
    stw r6, 0x30(r4)
    sth r5, 0x34(r4)
    sth r5, 0x36(r4)
    sth r5, 0x38(r4)
    stw r3, 0x3c(r4)
    stw r3, 0x40(r4)
    stw r3, 0x44(r4)
    stw r3, 0x48(r4)
    stw r3, 0x4c(r4)
    beq _800758CC
    addi r3, r29, 8
    addi r4, r4, 0x50
    bl lbl_8006E1B0
    addi r3, r31, 0x41e0
    lfs f0, 0x14(r29)
    lfs f1, 0x58(r3)
    fsubs f0, f1, f0
    stfs f0, 0x58(r3)
    b _800758E4
_800758CC:
    lwz r5, 0x100(r31)
    lwz r3, 0x104(r31)
    lwz r0, 0x108(r31)
    stw r5, 0x50(r4)
    stw r3, 0x54(r4)
    stw r0, 0x58(r4)
_800758E4:
    addi r3, r31, 0x41e0
    addi r3, r3, 0x50
    bl PSVecNormalize3
    addi r11, r1, 0x30
    bl _restgpr_25
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_80075908(void)
{
    nofralloc
    stwu r1, -0xa0(r1)
    mflr r0
    stw r0, 0xa4(r1)
    addi r11, r1, 0xa0
    bl _savegpr_27
    li r9, 0
    li r0, 0x1e
    li r8, 0x40
    stw r0, 0x5c(r1)
    li r7, 1
    li r6, 0x2d
    stw r9, 0x60(r1)
    li r5, 0x4c
    li r0, 4
    mr r30, r3
    stw r8, 0x68(r1)
    mr r31, r4
    stw r9, 0x6c(r1)
    stw r9, 0x54(r1)
    stw r9, 0x58(r1)
    stw r9, 0x64(r1)
    stw r7, 0x70(r1)
    stw r9, 0x74(r1)
    stw r7, 0x60(r1)
    stw r6, 0x5c(r1)
    stw r5, 0x68(r1)
    stw r0, 0x6c(r1)
    bl fn_800775EC
    lwz r0, 0(r30)
    clrlwi. r0, r0, 0x1f
    bne _8007598C
    mr r3, r30
    bl fn_80075080
_8007598C:
    lwz r0, 0(r30)
    rlwinm r0, r0, 0x1e, 0x1f, 0x1f
    xori r3, r0, 1
    bl fn_80072168
    li r0, 0
    li r4, 0xa
    li r3, 5
    stw r4, 0x10(r1)
    stw r3, 0x14(r1)
    sth r0, 0x18(r1)
    sth r0, 0x1a(r1)
    stw r0, 8(r1)
    stw r0, 0xc(r1)
    lwz r0, 0(r30)
    clrlwi. r0, r0, 0x1f
    beq _800759DC
    mr r3, r30
    addi r4, r1, 8
    bl fn_80077488
    b _800759E4
_800759DC:
    mr r3, r30
    bl fn_80077384
_800759E4:
    lis     r4, lbl_801A3220@ha
    lwz r3, 0x10(r1)
    addi r4, r4, lbl_801A3220@l
    lwz r0, 0x14(r4)
    cmpw r0, r3
    beq _80075A08
    li r0, 1
    stw r3, 0x14(r4)
    stw r0, 8(r1)
_80075A08:
    lis     r4, lbl_801A3220@ha
    lwz r3, 0x14(r1)
    addi r4, r4, lbl_801A3220@l
    lwz r0, 0x18(r4)
    cmpw r0, r3
    beq _80075A2C
    li r0, 1
    stw r3, 0x18(r4)
    stw r0, 0xc(r1)
_80075A2C:
    lwz r0, 0(r30)
    rlwinm. r0, r0, 0, 0x18, 0x18
    bne _80075A44
    lwz r0, -0x7668(r13)
    cmpwi r0, 0
    beq _80075A58
_80075A44:
    mr r3, r30
    addi r4, r1, 0x54
    addi r5, r1, 8
    bl fn_80077240
    b _80075A9C
_80075A58:
    li r3, 0
    li r4, 0xa
    li r5, 0
    li r6, 4
    li r7, 0
    bl LightCtrl_SetCachedFog
    mr r3, r30
    mr r5, r31
    addi r4, r1, 0x54
    addi r6, r1, 8
    bl AvDispTraverseMaterialCache
    cmpwi r3, 0
    bne _80075A9C
    mr r3, r30
    addi r4, r1, 0x54
    addi r5, r1, 8
    bl fn_80077240
_80075A9C:
    lwz r0, 0(r30)
    rlwinm. r0, r0, 0, 0x16, 0x16
    beq _80075AB8
    mr r3, r30
    addi r4, r1, 0x54
    addi r5, r1, 8
    bl fn_80074D88
_80075AB8:
    lwz r12, -0x7680(r13)
    cmplwi r12, 0
    beq _80075B94
    lis r3, -0x7fe6
    lwz r28, 0x54(r1)
    lbz r27, 0x3220(r3)
    addi r3, r1, 0x1c
    lwz r29, 0x58(r1)
    lwz r11, 0x5c(r1)
    lwz r10, 0x60(r1)
    lwz r9, 0x64(r1)
    lwz r8, 0x68(r1)
    lwz r7, 0x6c(r1)
    lwz r6, 0x70(r1)
    lwz r5, 0x74(r1)
    lwz r4, 0x78(r1)
    lwz r0, 0x7c(r1)
    stw r27, 0x1c(r1)
    stw r30, 0x20(r1)
    stw r31, 0x24(r1)
    stw r28, 0x28(r1)
    stw r29, 0x2c(r1)
    stw r11, 0x30(r1)
    stw r10, 0x34(r1)
    stw r9, 0x38(r1)
    stw r8, 0x3c(r1)
    stw r7, 0x40(r1)
    stw r6, 0x44(r1)
    stw r5, 0x48(r1)
    stw r4, 0x4c(r1)
    stw r0, 0x50(r1)
    mtctr r12
    bctrl
    lwz r12, 0x28(r1)
    lwz r11, 0x2c(r1)
    lwz r10, 0x30(r1)
    lwz r9, 0x34(r1)
    lwz r8, 0x38(r1)
    lwz r7, 0x3c(r1)
    lwz r6, 0x40(r1)
    lwz r5, 0x44(r1)
    lwz r4, 0x48(r1)
    lwz r3, 0x4c(r1)
    lwz r0, 0x50(r1)
    stw r12, 0x54(r1)
    stw r11, 0x58(r1)
    stw r10, 0x5c(r1)
    stw r9, 0x60(r1)
    stw r8, 0x64(r1)
    stw r7, 0x68(r1)
    stw r6, 0x6c(r1)
    stw r5, 0x70(r1)
    stw r4, 0x74(r1)
    stw r3, 0x78(r1)
    stw r0, 0x7c(r1)
_80075B94:
    lwz r0, -0x7638(r13)
    cmpwi r0, 0
    beq _80075BCC
    lis     r4, lbl_801A3220@ha
    lwz r3, 0x54(r1)
    addi r4, r4, lbl_801A3220@l
    lwz r0, 8(r4)
    cmpw r0, r3
    beq _80075BC0
    stw r3, 8(r4)
    bl fn_80077654
_80075BC0:
    lwz r3, 0x54(r1)
    addi r0, r3, 1
    stw r0, 0x54(r1)
_80075BCC:
    lwz r0, -0x763c(r13)
    cmpwi r0, 0
    beq _80075C04
    lis     r4, lbl_801A3220@ha
    lwz r3, 0x54(r1)
    addi r4, r4, lbl_801A3220@l
    lwz r0, 0xc(r4)
    cmpw r0, r3
    beq _80075BF8
    stw r3, 8(r4)
    bl fn_80077714
_80075BF8:
    lwz r3, 0x54(r1)
    addi r0, r3, 1
    stw r0, 0x54(r1)
_80075C04:
    li r3, 1
    bl GXSetChanAmbColorCached
    lwz r0, 0x54(r1)
    clrlwi r3, r0, 0x18
    bl ModelSetCachedNumTexGens
    lwz r0, 0x58(r1)
    clrlwi r3, r0, 0x18
    bl GXSetNumTexGensCached
    lwz r0, 0x64(r1)
    clrlwi r3, r0, 0x18
    bl ModelSetCachedState_840
    mr r3, r30
    bl fn_80075C78
    li r4, 0
    lis r3, -0x7fe6
    stbu r4, 0x3220(r3)
    lwz r0, 0(r30)
    rlwinm. r0, r0, 0, 0x18, 0x18
    beq _80075C58
    stb r4, 1(r3)
    b _80075C60
_80075C58:
    lbz r0, 0x12(r30)
    stb r0, 1(r3)
_80075C60:
    addi r11, r1, 0xa0
    bl _restgpr_27
    lwz r0, 0xa4(r1)
    mtlr r0
    addi r1, r1, 0xa0
    blr
}

asm void fn_80075C78(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    li r30, 4
    stw r29, 0x14(r1)
    li r29, 5
    lwz r0, -0x7660(r13)
    cmpwi r0, -1
    bne _80075CBC
    lwz r0, 0(r3)
    rlwinm. r0, r0, 0, 0x1a, 0x1a
    beq _80075CC0
    lwz r0, 0x40(r3)
    clrlwi r30, r0, 0x1c
    b _80075CC0
_80075CBC:
    mr r30, r0
_80075CC0:
    lwz r0, -0x7664(r13)
    cmpwi r0, -1
    bne _80075CE4
    lwz r0, 0(r3)
    rlwinm. r0, r0, 0, 0x19, 0x19
    beq _80075CE8
    lwz r0, 0x40(r3)
    rlwinm r29, r0, 0x1c, 0x1c, 0x1f
    b _80075CE8
_80075CE4:
    mr r29, r0
_80075CE8:
    lis     r3, lbl_801A3220@ha
    addi r31, r3, lbl_801A3220@l
    lwz r0, 0x1c(r31)
    cmpw r0, r30
    bne _80075D08
    lwz r0, 0x20(r31)
    cmpw r0, r29
    beq _80075D2C
_80075D08:
    mr r4, r30
    mr r5, r29
    li r3, 1
    li r6, 0
    bl LightCtrl_SetCachedColor_1C
    lis     r3, lbl_801A3220@ha
    stw r30, 0x1c(r31)
    addi r3, r3, lbl_801A3220@l
    stw r29, 0x20(r3)
_80075D2C:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80075D48(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r4
    stw r30, 8(r1)
    mr r30, r3
    lwz r3, 0(r3)
    bl ModelClearCacheSlot_B28
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lwz r3, 0(r30)
    li r6, 4
    lwz r4, 4(r30)
    lwz r5, 0xc(r30)
    bl ModelSetCachedMaterial_570
    lha r0, 0x10(r31)
    cmpwi r0, 2
    beq _80075DF8
    bge _80075DB0
    cmpwi r0, 0
    beq _80075E30
    bge _80075DC0
    b _80075F74
_80075DB0:
    cmpwi r0, 4
    beq _80075E68
    bge _80075F74
    b _80075F40
_80075DC0:
    lwz r3, 0(r30)
    li r4, 0xf
    lwz r7, 8(r31)
    li r5, 8
    li r6, 0xc
    bl ModelSetCachedParam_F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    b _80075F74
_80075DF8:
    lwz r3, 0(r30)
    li r4, 0xf
    lwz r7, 8(r31)
    li r5, 8
    li r6, 0xc
    bl ModelSetCachedParam_F0
    lwz r3, 0(r30)
    li r4, 1
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    b _80075F74
_80075E30:
    lwz r3, 0(r30)
    li r4, 0xf
    lwz r6, 8(r31)
    li r5, 8
    li r7, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    b _80075F74
_80075E68:
    lwz r3, 0(r30)
    li r4, 0xf
    li r5, 8
    li r6, 0xa
    li r7, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 3
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r30)
    li r4, 7
    lwz r7, 0xc(r31)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r30)
    addi r0, r3, 1
    stw r0, 0(r30)
    lwz r3, 0(r30)
    bl ModelClearCacheSlot_B28
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lwz r3, 0(r30)
    li r6, 0xff
    lwz r4, 4(r30)
    lwz r5, 0xc(r30)
    bl ModelSetCachedMaterial_570
    lwz r3, 0(r30)
    li r5, 6
    lwz r4, 8(r31)
    li r6, 9
    li r7, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    b _80075F74
_80075F40:
    lwz r3, 0(r30)
    li r4, 0xf
    lwz r7, 8(r31)
    li r5, 0xf
    li r6, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
_80075F74:
    lha r0, 0x12(r31)
    cmpwi r0, 3
    beq _800760D0
    bge _80075F9C
    cmpwi r0, 1
    beq _80075FAC
    bge _80075FE4
    cmpwi r0, 0
    bge _8007601C
    b _80076104
_80075F9C:
    cmpwi r0, 5
    beq _8007608C
    bge _80076104
    b _80076054
_80075FAC:
    lwz r3, 0(r30)
    li r4, 4
    lwz r7, 0xc(r31)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    b _80076104
_80075FE4:
    lwz r3, 0(r30)
    li r4, 4
    lwz r7, 0xc(r31)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 1
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    b _80076104
_8007601C:
    lwz r3, 0(r30)
    li r4, 7
    lwz r6, 0xc(r31)
    li r5, 4
    li r7, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    b _80076104
_80076054:
    lwz r3, 0(r30)
    li r4, 7
    li r5, 7
    li r6, 7
    li r7, 4
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    b _80076104
_8007608C:
    lwz r3, 0(r30)
    li r4, 0
    bl ModelSetCachedState_6B0
    lwz r3, 0(r30)
    li r4, 7
    li r5, 7
    li r6, 7
    li r7, 6
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    b _80076104
_800760D0:
    lwz r3, 0(r30)
    li r4, 7
    lwz r7, 0xc(r31)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
_80076104:
    lwz r3, 0(r30)
    addi r0, r3, 1
    stw r0, 0(r30)
    lwz r3, 4(r30)
    addi r0, r3, 1
    stw r0, 4(r30)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80076134(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    bl mtx_gpstack_push
    lfs f0, -0x79c0(r2)
    li r4, 0x1e
    lwz r3, -0x76c0(r13)
    li r5, 0
    stfs f0, 0xc(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    lwz r3, -0x76c0(r13)
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    lis     r3, lbl_801A3220@ha
    li r0, 1
    addi r3, r3, lbl_801A3220@l
    stw r0, 0x3c(r3)
    bl mtx_gpstack_push
    lis     r4, lbl_801A3220@ha
    lis     r3, lbl_8015AD10@ha
    addi r4, r4, lbl_801A3220@l
    addi r3, r3, lbl_8015AD10@l
    addi r4, r4, 0x50
    bl PSMTXLookAtNoUp
    lfs f1, -0x79b4(r2)
    lwz r3, -0x76c0(r13)
    lfs f4, -0x79a4(r2)
    stfs f1, 0xc(r3)
    lfs f2, -0x79c0(r2)
    lwz r3, -0x76c0(r13)
    lfs f0, -0x79b8(r2)
    lfs f3, 0x10(r3)
    fmuls f3, f3, f4
    stfs f3, 0x10(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x14(r3)
    fmuls f3, f3, f4
    stfs f3, 0x14(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x18(r3)
    fmuls f3, f3, f4
    stfs f3, 0x18(r3)
    lwz r3, -0x76c0(r13)
    stfs f1, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x20(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x24(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x28(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    bl fn_8006E14C
    lwz r3, -0x76c0(r13)
    li r4, 0x40
    li r5, 0
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80076238(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_27
    mr r27, r3
    mr r28, r4
    lwz r3, 0(r3)
    mr r29, r5
    mr r30, r6
    bl ModelClearCacheSlot_B28
    lwz r3, 0(r27)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lis     r3, lbl_801A3220@ha
    addi r31, r3, lbl_801A3220@l
    lwz r0, 0x3c(r31)
    cmpwi r0, 0
    bne _800762C4
    bl mtx_gpstack_push
    lfs f0, -0x79c0(r2)
    li r4, 0x1e
    lwz r3, -0x76c0(r13)
    li r5, 0
    stfs f0, 0xc(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    lwz r3, -0x76c0(r13)
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    li r0, 1
    stw r0, 0x3c(r31)
_800762C4:
    lis     r3, lbl_801A3220@ha
    addi r31, r3, lbl_801A3220@l
    lwz r0, 0x40(r31)
    cmpwi r0, 0
    bne _80076384
    bl mtx_gpstack_push
    lis     r4, lbl_801A3220@ha
    lis     r3, lbl_8015AD1C@ha
    addi r4, r4, lbl_801A3220@l
    addi r3, r3, lbl_8015AD1C@l
    addi r4, r4, 0x50
    bl PSMTXLookAtNoUp
    lfs f1, -0x79b4(r2)
    lwz r3, -0x76c0(r13)
    lfs f4, -0x79a4(r2)
    stfs f1, 0xc(r3)
    lfs f2, -0x79c0(r2)
    lwz r3, -0x76c0(r13)
    lfs f0, -0x79b8(r2)
    lfs f3, 0x10(r3)
    fmuls f3, f3, f4
    stfs f3, 0x10(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x14(r3)
    fmuls f3, f3, f4
    stfs f3, 0x14(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x18(r3)
    fmuls f3, f3, f4
    stfs f3, 0x18(r3)
    lwz r3, -0x76c0(r13)
    stfs f1, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x20(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x24(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x28(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    bl fn_8006E14C
    lwz r3, -0x76c0(r13)
    li r4, 0x40
    li r5, 0
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    li r0, 1
    stw r0, 0x40(r31)
_80076384:
    stb r29, 0xc(r1)
    li r6, 4
    lwz r3, 0(r27)
    stb r29, 0xd(r1)
    lwz r4, 4(r27)
    stb r29, 0xe(r1)
    lwz r5, 0xc(r27)
    stb r29, 0xf(r1)
    bl ModelSetCachedMaterial_570
    lwz r0, 0xc(r1)
    addi r4, r1, 8
    li r3, 0
    stw r0, 8(r1)
    bl ModelSetCachedTex_704
    lwz r3, 0(r27)
    li r4, 0xc
    bl GXCachedSetTevSwapTable
    lwz r3, 4(r27)
    li r4, 0
    li r5, 1
    li r6, 0x1e
    li r7, 1
    li r8, 0x40
    bl ModelSetCachedPair5_B28
    cmpwi r30, 0
    beq _80076408
    lwz r3, 0(r27)
    li r4, 0xf
    lwz r6, 8(r28)
    li r5, 8
    li r7, 0xf
    bl ModelSetCachedParam_F0
    b _80076420
_80076408:
    lwz r3, 0(r27)
    li r4, 0xf
    lwz r7, 8(r28)
    li r5, 8
    li r6, 0xe
    bl ModelSetCachedParam_F0
_80076420:
    lwz r3, 0(r27)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r27)
    li r4, 7
    lwz r7, 0xc(r28)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r27)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r27)
    addi r0, r3, 1
    stw r0, 0(r27)
    lwz r3, 4(r27)
    addi r0, r3, 1
    stw r0, 4(r27)
    addi r11, r1, 0x30
    bl _restgpr_27
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_800764A0(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    stw r28, 0x10(r1)
    mr r28, r3
    lwz r3, 0(r3)
    bl ModelClearCacheSlot_B28
    lwz r3, 0(r28)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lis     r3, lbl_801A3220@ha
    addi r31, r3, lbl_801A3220@l
    lwz r0, 0x3c(r31)
    cmpwi r0, 0
    bne _80076530
    bl mtx_gpstack_push
    lfs f0, -0x79c0(r2)
    li r4, 0x1e
    lwz r3, -0x76c0(r13)
    li r5, 0
    stfs f0, 0xc(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    lwz r3, -0x76c0(r13)
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    li r0, 1
    stw r0, 0x3c(r31)
_80076530:
    lis     r3, lbl_801A3220@ha
    addi r31, r3, lbl_801A3220@l
    lwz r0, 0x40(r31)
    cmpwi r0, 0
    bne _800765F0
    bl mtx_gpstack_push
    lis     r4, lbl_801A3220@ha
    lis     r3, lbl_8015AD28@ha
    addi r4, r4, lbl_801A3220@l
    addi r3, r3, lbl_8015AD28@l
    addi r4, r4, 0x50
    bl PSMTXLookAtNoUp
    lfs f1, -0x79b4(r2)
    lwz r3, -0x76c0(r13)
    lfs f4, -0x79a4(r2)
    stfs f1, 0xc(r3)
    lfs f2, -0x79c0(r2)
    lwz r3, -0x76c0(r13)
    lfs f0, -0x79b8(r2)
    lfs f3, 0x10(r3)
    fmuls f3, f3, f4
    stfs f3, 0x10(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x14(r3)
    fmuls f3, f3, f4
    stfs f3, 0x14(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x18(r3)
    fmuls f3, f3, f4
    stfs f3, 0x18(r3)
    lwz r3, -0x76c0(r13)
    stfs f1, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x20(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x24(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x28(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    bl fn_8006E14C
    lwz r3, -0x76c0(r13)
    li r4, 0x40
    li r5, 0
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    li r0, 1
    stw r0, 0x40(r31)
_800765F0:
    stb r30, 0xc(r1)
    li r6, 4
    lwz r3, 0(r28)
    stb r30, 0xd(r1)
    lwz r4, 4(r28)
    stb r30, 0xe(r1)
    lwz r5, 0xc(r28)
    stb r30, 0xf(r1)
    bl ModelSetCachedMaterial_570
    lwz r0, 0xc(r1)
    addi r4, r1, 8
    li r3, 0
    stw r0, 8(r1)
    bl ModelSetCachedTex_704
    lwz r3, 0(r28)
    li r4, 0xc
    bl GXCachedSetTevSwapTable
    lwz r3, 4(r28)
    li r4, 0
    li r5, 1
    li r6, 0x1e
    li r7, 1
    li r8, 0x40
    bl ModelSetCachedPair5_B28
    lwz r3, 0(r28)
    li r4, 0xf
    li r5, 8
    li r6, 0xe
    li r7, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r28)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 2
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r28)
    li r4, 7
    lwz r7, 0xc(r29)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r28)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 2
    bl ModelSetCachedParam_430
    lwz r3, 0(r28)
    addi r0, r3, 1
    stw r0, 0(r28)
    lwz r3, 4(r28)
    addi r0, r3, 1
    stw r0, 4(r28)
    lwz r3, 0(r28)
    bl ModelClearCacheSlot_B28
    lwz r3, 0(r28)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lwz r3, 0(r28)
    li r4, 0xff
    li r5, 0xff
    li r6, 0xff
    bl ModelSetCachedMaterial_570
    lwz r3, 0(r28)
    li r4, 0xf
    lwz r7, 8(r29)
    li r5, 4
    li r6, 0xa
    bl ModelSetCachedParam_F0
    lwz r3, 0(r28)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r28)
    li r4, 7
    li r5, 7
    li r6, 7
    li r7, 2
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r28)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r28)
    addi r0, r3, 1
    stw r0, 0(r28)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void ModelBlendMatrixPush(void)
{
    nofralloc
    stwu r1, -0x70(r1)
    mflr r0
    lis     r3, lbl_80094E20@ha
    stw r0, 0x74(r1)
    addi r5, r3, lbl_80094E20@l
    lwz r4, 0(r5)
    lwz r3, 4(r5)
    lwz r0, 8(r5)
    stw r4, 0x2c(r1)
    stw r3, 0x30(r1)
    stw r0, 0x34(r1)
    bl mtx_gpstack_push
    lis     r3, lbl_801A3220@ha
    lis     r6, lbl_8019F14C@ha
    addi r4, r3, lbl_801A3220@l
    lfs f2, -0x79a0(r2)
    lwz r5, 0x50(r4)
    addi r8, r6, lbl_8019F14C@l
    lwz r6, 0x54(r4)
    addi r3, r1, 0x2c
    lwz r0, 0x58(r4)
    addi r4, r1, 8
    stw r5, 0x14(r1)
    addi r5, r1, 0x20
    lwz r7, 0(r8)
    stw r6, 0x18(r1)
    lwz r6, 4(r8)
    stw r0, 0x1c(r1)
    lwz r0, 8(r8)
    lfs f3, 0x14(r1)
    lfs f1, 0x18(r1)
    lfs f0, 0x1c(r1)
    fmuls f8, f3, f2
    stw r7, 0x20(r1)
    fmuls f7, f1, f2
    fmuls f6, f0, f2
    lfs f3, -0x79b4(r2)
    stw r6, 0x24(r1)
    lfs f0, 0x20(r1)
    stw r0, 0x28(r1)
    lfs f1, 0x24(r1)
    fadds f2, f8, f0
    lfs f0, 0x28(r1)
    fadds f1, f7, f1
    stfs f8, 0x14(r1)
    fmuls f5, f3, f2
    fadds f0, f6, f0
    stfs f7, 0x18(r1)
    fmuls f4, f3, f1
    fsubs f2, f5, f8
    stfs f6, 0x1c(r1)
    fmuls f3, f3, f0
    fsubs f1, f4, f7
    stfs f5, 0x20(r1)
    fsubs f0, f3, f6
    stfs f4, 0x24(r1)
    stfs f3, 0x28(r1)
    stfs f2, 8(r1)
    stfs f1, 0xc(r1)
    stfs f0, 0x10(r1)
    bl PSMTXReflect
    addi r3, r1, 0x38
    bl fn_8006DB74
    lfs f1, -0x79b4(r2)
    lwz r3, -0x76c0(r13)
    lfs f4, -0x79a4(r2)
    stfs f1, 0xc(r3)
    lfs f2, -0x79c0(r2)
    lwz r3, -0x76c0(r13)
    lfs f0, -0x79b8(r2)
    lfs f3, 0x10(r3)
    fmuls f3, f3, f4
    stfs f3, 0x10(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x14(r3)
    fmuls f3, f3, f4
    stfs f3, 0x14(r3)
    lwz r3, -0x76c0(r13)
    lfs f3, 0x18(r3)
    fmuls f3, f3, f4
    stfs f3, 0x18(r3)
    lwz r3, -0x76c0(r13)
    stfs f1, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x20(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x24(r3)
    lwz r3, -0x76c0(r13)
    stfs f2, 0x28(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    bl fn_8006E14C
    lwz r3, -0x76c0(r13)
    li r4, 0x43
    li r5, 0
    bl GXWritePrimitiveFifo
    bl QuatNormalizeCompare
    lfs f2, -0x79c0(r2)
    addi r3, r1, 0x38
    lwz r4, -0x76c0(r13)
    lfs f1, -0x79b4(r2)
    stfs f2, 0(r4)
    lfs f0, -0x79b8(r2)
    lwz r4, -0x76c0(r13)
    stfs f1, 8(r4)
    lwz r4, -0x76c0(r13)
    stfs f1, 0xc(r4)
    lwz r4, -0x76c0(r13)
    stfs f2, 0x14(r4)
    lwz r4, -0x76c0(r13)
    stfs f2, 0x28(r4)
    lwz r4, -0x76c0(r13)
    stfs f0, 0x2c(r4)
    bl fn_8006DFC4
    lwz r3, -0x76c0(r13)
    li r4, 0x46
    li r5, 0
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    lis     r3, lbl_801A3220@ha
    li r0, 1
    addi r3, r3, lbl_801A3220@l
    stw r0, 0x44(r3)
    lwz r0, 0x74(r1)
    mtlr r0
    addi r1, r1, 0x70
    blr
}

asm void fn_8007698C(void)
{
    nofralloc
    stwu r1, -0x50(r1)
    mflr r0
    lis     r5, lbl_801A3220@ha
    stw r0, 0x54(r1)
    stw r31, 0x4c(r1)
    addi r31, r5, lbl_801A3220@l
    stw r30, 0x48(r1)
    mr r30, r4
    stw r29, 0x44(r1)
    mr r29, r3
    lwz r0, 0x4c(r31)
    cmpwi r0, 0
    bne _80076AA4
    lwz r0, 0x10(r31)
    stw r0, 0xc(r1)
    lbz r0, 0xc(r1)
    cmplwi r0, 0
    bne _800769FC
    lbz r0, 0xd(r1)
    cmplwi r0, 0
    bne _800769FC
    lbz r0, 0xe(r1)
    cmplwi r0, 0
    bne _800769FC
    li r0, 0xff
    stb r0, 0xc(r1)
    stb r0, 0xd(r1)
    stb r0, 0xe(r1)
_800769FC:
    lbz r7, 0xc(r1)
    lis r6, 0x4330
    lbz r5, 0xd(r1)
    addi r4, r1, 8
    lbz r0, 0xe(r1)
    li r3, 1
    stw r7, 0x14(r1)
    lfd f5, -0x79b0(r2)
    stw r6, 0x10(r1)
    lfs f3, -0x7650(r13)
    lfd f0, 0x10(r1)
    stw r5, 0x24(r1)
    fsubs f4, f0, f5
    lfs f2, -0x7654(r13)
    stw r6, 0x20(r1)
    lfs f0, -0x7658(r13)
    lfd f1, 0x20(r1)
    fmuls f4, f4, f3
    stw r0, 0x34(r1)
    fsubs f3, f1, f5
    stw r6, 0x30(r1)
    fctiwz f4, f4
    lfd f1, 0x30(r1)
    fmuls f2, f3, f2
    stfd f4, 0x18(r1)
    fsubs f1, f1, f5
    fctiwz f2, f2
    lwz r0, 0x1c(r1)
    fmuls f0, f1, f0
    stb r0, 0xc(r1)
    stfd f2, 0x28(r1)
    fctiwz f0, f0
    lwz r5, 0x2c(r1)
    stfd f0, 0x38(r1)
    lwz r0, 0x3c(r1)
    stb r5, 0xd(r1)
    stb r0, 0xe(r1)
    lwz r0, 0xc(r1)
    stw r0, 8(r1)
    bl ModelSetCachedTex_704
    li r0, 1
    stw r0, 0x4c(r31)
_80076AA4:
    lis     r3, lbl_801A3220@ha
    addi r31, r3, lbl_801A3220@l
    lwz r0, 0x3c(r31)
    cmpwi r0, 0
    bne _80076AF4
    bl mtx_gpstack_push
    lfs f0, -0x79c0(r2)
    li r4, 0x1e
    lwz r3, -0x76c0(r13)
    li r5, 0
    stfs f0, 0xc(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x1c(r3)
    lwz r3, -0x76c0(r13)
    stfs f0, 0x2c(r3)
    lwz r3, -0x76c0(r13)
    bl GXWritePrimitiveFifo
    bl mtx_gpstack_pop
    li r0, 1
    stw r0, 0x3c(r31)
_80076AF4:
    lis     r3, lbl_801A3220@ha
    addi r3, r3, lbl_801A3220@l
    lwz r0, 0x44(r3)
    cmpwi r0, 0
    bne _80076B1C
    lis     r3, lbl_8019F200@ha
    li r4, 0
    addi r3, r3, lbl_8019F200@l
    bl ModelCacheMaterialParams
    bl ModelBlendMatrixPush
_80076B1C:
    lwz r31, 0(r29)
    mr r3, r31
    bl ModelClearCacheSlot_B28
    mr r3, r31
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    mr r3, r31
    li r4, 0xd
    bl GXCachedSetTevSwapTable
    lwz r3, 4(r29)
    li r4, 0
    li r5, 1
    li r6, 0x1e
    li r7, 1
    li r8, 0x46
    bl ModelSetCachedPair5_B28
    lwz r4, 4(r29)
    mr r3, r31
    li r5, 0
    li r6, 4
    bl ModelSetCachedMaterial_570
    mr r3, r31
    li r4, 0xf
    li r5, 8
    li r6, 0xe
    li r7, 0xf
    bl ModelSetCachedParam_F0
    mr r3, r31
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 3
    bl ModelSetCachedParam_2F0
    lwz r7, 0xc(r30)
    mr r3, r31
    li r4, 7
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    mr r3, r31
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 3
    bl ModelSetCachedParam_430
    addi r3, r31, 1
    bl ModelClearCacheSlot_B28
    addi r3, r31, 1
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    addi r3, r31, 1
    li r4, 0xd
    bl GXCachedSetTevSwapTable
    lwz r3, 4(r29)
    li r4, 0
    li r5, 1
    li r6, 0x1e
    addi r3, r3, 1
    li r7, 1
    li r8, 0x43
    bl ModelSetCachedPair5_B28
    lwz r4, 4(r29)
    addi r3, r31, 1
    lwz r5, 0xc(r29)
    li r6, 4
    addi r4, r4, 1
    bl ModelSetCachedMaterial_570
    lwz r7, 8(r30)
    addi r3, r31, 1
    li r4, 0xf
    li r5, 8
    li r6, 6
    bl ModelSetCachedParam_F0
    addi r3, r31, 1
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r7, 0xc(r30)
    addi r3, r31, 1
    li r4, 7
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    addi r3, r31, 1
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r29)
    addi r0, r3, 2
    stw r0, 0(r29)
    lwz r3, 4(r29)
    addi r0, r3, 2
    stw r0, 4(r29)
    lwz r31, 0x4c(r1)
    lwz r30, 0x48(r1)
    lwz r29, 0x44(r1)
    lwz r0, 0x54(r1)
    mtlr r0
    addi r1, r1, 0x50
    blr
}

asm void AvDispTraverseMaterialCache(void)
{
    nofralloc
    stwu r1, -0x40(r1)
    mflr r0
    stw r0, 0x44(r1)
    addi r11, r1, 0x40
    bl _savegpr_19
    lis     r8, lbl_801A3220@ha
    lis r7, 0x51
    addi r8, r8, lbl_801A3220@l
    lbz r23, 0x12(r3)
    mr r19, r4
    mr r20, r5
    mr r21, r6
    addi r26, r3, 0x16
    addi r28, r8, 0x24
    addi r24, r8, 0x34
    addi r31, r7, -0x5ffd
    li r22, 0
    li r29, 4
    b _80077214
_80076D20:
    lhz r0, 0(r26)
    slwi r0, r0, 5
    add r27, r20, r0
    lwz r25, 0(r27)
    and r30, r25, r31
    stw r30, 0(r28)
    lhz r3, 0(r24)
    lhz r0, 0(r26)
    cmplw r3, r0
    bne _80076D54
    lwz r0, 0(r27)
    rlwinm. r0, r0, 0, 0xf, 0xf
    beq _80076D70
_80076D54:
    lwz r3, 8(r27)
    cmplwi r3, 0
    beq _80077210
    lwz r4, 0xc(r19)
    bl ModelCacheMaterialParams
    lhz r0, 0(r26)
    sth r0, 0(r24)
_80076D70:
    lwz r0, 0x10(r27)
    cmplwi r30, 0
    clrlwi r0, r0, 0x1c
    sth r0, 0x10(r21)
    lwz r0, 0x10(r27)
    rlwinm r0, r0, 0x1c, 0x1c, 0x1f
    sth r0, 0x12(r21)
    bne _80076E18
    lwz r0, 0(r27)
    rlwinm. r0, r0, 0, 0xe, 0xe
    beq _80076DEC
    lwz r0, 0x10(r27)
    rlwinm. r0, r0, 0x18, 0x1e, 0x1f
    beq _80076DCC
    mulli r6, r0, 3
    lwz r3, 4(r19)
    mr r5, r29
    li r4, 1
    addi r6, r6, 0x30
    li r7, 0
    li r8, 0x7d
    bl ModelSetCachedPair5_B28
    b _80076E08
_80076DCC:
    lwz r3, 4(r19)
    mr r5, r29
    li r4, 1
    li r6, 0x24
    li r7, 0
    li r8, 0x7d
    bl ModelSetCachedPair5_B28
    b _80076E08
_80076DEC:
    lwz r3, 4(r19)
    mr r5, r29
    li r4, 1
    li r6, 0x3c
    li r7, 0
    li r8, 0x7d
    bl ModelSetCachedPair5_B28
_80076E08:
    mr r3, r19
    mr r4, r21
    bl fn_80075D48
    b _800771E4
_80076E18:
    rlwinm. r0, r25, 0, 0x12, 0x12
    beq _80076FD0
    lwz r25, 0(r27)
    lwz r3, 0(r19)
    bl ModelClearCacheSlot_B28
    rlwinm r3, r25, 0, 0xc, 0xd
    lis r0, 8
    cmpw r3, r0
    beq _80076E8C
    bge _80076E50
    lis r0, 4
    cmpw r3, r0
    beq _80076E60
    b _80076EE4
_80076E50:
    lis r0, 0xc
    cmpw r3, r0
    beq _80076EB8
    b _80076EE4
_80076E60:
    li r3, 2
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 1
    bl LightCtrl_SetCachedParam_2C
    lwz r3, 0(r19)
    li r4, 0
    li r5, 2
    bl LightCtrl_SetCachedPair_6C
    b _80076EF4
_80076E8C:
    li r3, 2
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 2
    bl LightCtrl_SetCachedParam_2C
    lwz r3, 0(r19)
    li r4, 0
    li r5, 2
    bl LightCtrl_SetCachedPair_6C
    b _80076EF4
_80076EB8:
    li r3, 2
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 3
    bl LightCtrl_SetCachedParam_2C
    lwz r3, 0(r19)
    li r4, 0
    li r5, 2
    bl LightCtrl_SetCachedPair_6C
    b _80076EF4
_80076EE4:
    lwz r3, 0(r19)
    li r4, 0
    li r5, 1
    bl LightCtrl_SetCachedPair_6C
_80076EF4:
    rlwinm. r0, r25, 0, 0xe, 0xe
    beq _80076F1C
    lwz r3, 4(r19)
    mr r5, r29
    li r4, 1
    li r6, 0x24
    li r7, 0
    li r8, 0x7d
    bl ModelSetCachedPair5_B28
    b _80076F38
_80076F1C:
    lwz r3, 4(r19)
    mr r5, r29
    li r4, 1
    li r6, 0x3c
    li r7, 0
    li r8, 0x7d
    bl ModelSetCachedPair5_B28
_80076F38:
    lwz r3, 0(r19)
    li r6, 4
    lwz r4, 4(r19)
    lwz r5, 0xc(r19)
    bl ModelSetCachedMaterial_570
    lwz r3, 0(r19)
    li r4, 0xf
    lwz r7, 8(r21)
    li r5, 0xf
    li r6, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r19)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r19)
    li r4, 7
    lwz r6, 0xc(r21)
    li r5, 4
    li r7, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r19)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r19)
    addi r0, r3, 1
    stw r0, 0(r19)
    lwz r3, 4(r19)
    addi r0, r3, 1
    stw r0, 4(r19)
    b _800771E4
_80076FD0:
    rlwinm. r0, r25, 0, 0x1e, 0x1e
    beq _8007718C
    lwz r6, 4(r19)
    li r3, 0
    li r4, 0x19
    li r5, 1
    addi r25, r6, 0xc
    li r6, 4
    li r7, 0
    bl LightCtrl_SetCachedFog
    lwz r3, 0(r19)
    bl ModelClearCacheSlot_B28
    lwz r3, 4(r19)
    mr r5, r29
    li r4, 1
    li r6, 0x3c
    li r7, 0
    li r8, 0x7d
    bl ModelSetCachedPair5_B28
    lwz r3, 0(r19)
    li r6, 4
    lwz r4, 4(r19)
    lwz r5, 0xc(r19)
    bl ModelSetCachedMaterial_570
    lwz r3, 0(r19)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lwz r3, 0(r19)
    li r4, 8
    lwz r7, 8(r21)
    li r5, 0xf
    li r6, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r19)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 0
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r19)
    li r4, 7
    lwz r7, 0xc(r21)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r19)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r19)
    addi r0, r3, 1
    stw r0, 0(r19)
    lwz r3, 4(r19)
    addi r0, r3, 1
    stw r0, 4(r19)
    lwz r3, 0(r19)
    bl ModelClearCacheSlot_B28
    lwz r3, 4(r19)
    mr r5, r25
    li r4, 2
    li r6, 0x3c
    li r7, 0
    li r8, 0x7d
    bl ModelSetCachedPair5_B28
    lwz r3, 0(r19)
    li r6, 0xff
    lwz r4, 4(r19)
    lwz r5, 0xc(r19)
    bl ModelSetCachedMaterial_570
    lwz r3, 0(r19)
    li r4, 0
    li r5, 0
    bl LightCtrl_SetCachedPair_6C
    lwz r3, 0(r19)
    li r4, 8
    li r5, 0xf
    li r6, 0xf
    li r7, 0
    bl ModelSetCachedParam_F0
    lwz r3, 0(r19)
    li r4, 1
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r19)
    li r4, 7
    li r5, 7
    li r6, 7
    li r7, 0
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r19)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r3, 0(r19)
    addi r0, r3, 1
    stw r0, 0(r19)
    lwz r3, 4(r19)
    addi r0, r3, 1
    stw r0, 4(r19)
    b _800771E4
_8007718C:
    clrlwi. r0, r25, 0x1f
    beq _800771D8
    rlwinm. r0, r25, 0, 0xb, 0xb
    beq _800771A4
    lbz r5, 0xc(r27)
    b _800771A8
_800771A4:
    li r5, 0x80
_800771A8:
    lwz r0, -0x767c(r13)
    cmpwi r0, 0
    beq _800771C4
    mr r3, r19
    mr r4, r21
    bl fn_800764A0
    b _800771E4
_800771C4:
    mr r3, r19
    mr r4, r21
    rlwinm r6, r25, 0, 9, 9
    bl fn_80076238
    b _800771E4
_800771D8:
    mr r3, r19
    mr r4, r21
    bl fn_8007698C
_800771E4:
    li r0, 0
    addi r26, r26, 2
    stw r0, 8(r21)
    addi r28, r28, 4
    addi r24, r24, 2
    addi r22, r22, 1
    stw r0, 0xc(r21)
    addi r29, r29, 1
    lwz r3, 0xc(r19)
    addi r0, r3, 1
    stw r0, 0xc(r19)
_80077210:
    addi r23, r23, -1
_80077214:
    cmpwi r23, 0
    bgt _80076D20
    li r0, -1
    mr r3, r22
    stw r0, 0(r28)
    addi r11, r1, 0x40
    bl _restgpr_19
    lwz r0, 0x44(r1)
    mtlr r0
    addi r1, r1, 0x40
    blr
}

asm void fn_80077240(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    lis     r3, lbl_801A3220@ha
    stw r0, 0x14(r1)
    addi r3, r3, lbl_801A3220@l
    stw r31, 0xc(r1)
    mr r31, r5
    stw r30, 8(r1)
    mr r30, r4
    lbz r0, 1(r3)
    extsb. r0, r0
    bne _80077288
    lwz r3, 0(r31)
    cmpwi r3, 0
    bne _80077288
    lwz r0, 4(r31)
    cmpwi r0, 0
    beq _80077308
_80077288:
    lwz r3, 0(r30)
    li r4, 0xff
    li r5, 0xff
    li r6, 4
    bl ModelSetCachedMaterial_570
    lwz r3, 0(r30)
    li r4, 0xf
    lwz r7, 8(r31)
    li r5, 0xf
    li r6, 0xf
    bl ModelSetCachedParam_F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    lwz r3, 0(r30)
    li r4, 7
    lwz r7, 0xc(r31)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
    lwz r3, 0(r30)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    b _80077350
_80077308:
    cmpwi r3, 0
    beq _80077350
    beq _8007732C
    lwz r3, 0(r30)
    li r4, 0xf
    lwz r7, 8(r31)
    li r5, 0xf
    li r6, 0xf
    bl ModelSetCachedParam_F0
_8007732C:
    lwz r0, 4(r31)
    cmpwi r0, 0
    beq _80077350
    lwz r3, 0(r30)
    li r4, 7
    lwz r7, 0xc(r31)
    li r5, 7
    li r6, 7
    bl ModelSetCachedParam_1F0
_80077350:
    lis     r3, lbl_801A3220@ha
    li r0, -1
    addi r3, r3, lbl_801A3220@l
    stw r0, 0x24(r3)
    lwz r3, 0(r30)
    addi r0, r3, 1
    stw r0, 0(r30)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80077384(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    lwz r0, 0(r3)
    rlwinm. r0, r0, 0, 0x17, 0x17
    beq _8007741C
    lis     r3, lbl_801A3220@ha
    addi r4, r3, lbl_801A3220@l
    lbz r0, 2(r4)
    cmplwi r0, 4
    beq _80077478
    lis     r3, lbl_8019F130@ha
    li r0, 4
    addi r3, r3, lbl_8019F130@l
    lfs f1, -0x79b8(r2)
    lfs f0, 0xc(r3)
    li r3, 2
    stb r0, 2(r4)
    li r4, 0
    fcmpu cr0, f1, f0
    li r5, 0
    bne _800773E4
    li r6, 1
    b _800773E8
_800773E4:
    li r6, 0
_800773E8:
    li r7, 0
    li r8, 0
    li r9, 2
    bl LightCtrl_SetCachedRec_C30
    lwz r7, -0x764c(r13)
    li r3, 0
    lwz r9, -0x765c(r13)
    li r4, 1
    li r5, 0
    li r6, 1
    li r8, 2
    bl LightCtrl_SetCachedRec_C30
    b _80077478
_8007741C:
    lis     r3, lbl_801A3220@ha
    addi r4, r3, lbl_801A3220@l
    lbz r0, 2(r4)
    cmplwi r0, 3
    beq _80077478
    li r0, 3
    li r3, 2
    stb r0, 2(r4)
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 0
    li r8, 0
    li r9, 2
    bl LightCtrl_SetCachedRec_C30
    lwz r7, -0x764c(r13)
    li r3, 0
    lwz r9, -0x765c(r13)
    li r4, 1
    li r5, 0
    li r6, 0
    li r8, 2
    bl LightCtrl_SetCachedRec_C30
_80077478:
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80077488(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    stw r31, 0x2c(r1)
    mr r31, r4
    lwz r5, 0(r3)
    rlwinm. r0, r5, 0, 0x17, 0x17
    beq _80077544
    lis     r3, lbl_801A3220@ha
    addi r4, r3, lbl_801A3220@l
    lbz r0, 2(r4)
    cmplwi r0, 2
    beq _800775D8
    lis     r3, lbl_8019F130@ha
    li r0, 2
    addi r3, r3, lbl_8019F130@l
    lfs f1, -0x79b8(r2)
    lfs f0, 0xc(r3)
    stb r0, 2(r4)
    fcmpu cr0, f1, f0
    bne _80077500
    li r3, 4
    li r4, 0
    li r5, 1
    li r6, 1
    li r7, 0
    li r8, 0
    li r9, 2
    bl LightCtrl_SetCachedRec_C30
    b _800775D8
_80077500:
    li r3, 2
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 0
    li r8, 0
    li r9, 2
    bl LightCtrl_SetCachedRec_C30
    li r3, 0
    li r4, 0
    li r5, 1
    li r6, 1
    li r7, 0
    li r8, 0
    li r9, 2
    bl LightCtrl_SetCachedRec_C30
    b _800775D8
_80077544:
    lis     r4, lbl_801A3220@ha
    andi. r0, r5, 0x88
    addi r4, r4, lbl_801A3220@l
    li r0, 1
    stb r0, 2(r4)
    bne _80077570
    li r0, 0xff
    stb r0, 0xc(r1)
    stb r0, 0xd(r1)
    stb r0, 0xe(r1)
    b _80077578
_80077570:
    lwz r0, 4(r3)
    stw r0, 0xc(r1)
_80077578:
    lbz r4, 0x11(r3)
    lis r0, 0x4330
    lis     r3, lbl_8019F130@ha
    stw r0, 0x10(r1)
    addi r3, r3, lbl_8019F130@l
    lfd f2, -0x79b0(r2)
    stw r4, 0x14(r1)
    addi r4, r1, 8
    lfs f0, 0xc(r3)
    li r3, 1
    lfd f1, 0x10(r1)
    fsubs f1, f1, f2
    fmuls f0, f1, f0
    fctiwz f0, f0
    stfd f0, 0x18(r1)
    lwz r0, 0x1c(r1)
    stb r0, 0xf(r1)
    lwz r0, 0xc(r1)
    stw r0, 8(r1)
    bl __GXSetTexRegion
    li r3, 2
    li r0, 1
    stw r3, 8(r31)
    stw r0, 0xc(r31)
_800775D8:
    lwz r0, 0x34(r1)
    lwz r31, 0x2c(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_800775EC(void)
{
    nofralloc
    lis     r4, lbl_801A3220@ha
    lbz r0, 0xc(r3)
    addi r5, r4, lbl_801A3220@l
    lbz r4, 0x10(r5)
    cmplw r4, r0
    bne _80077624
    lbz r4, 0x11(r5)
    lbz r0, 0xd(r3)
    cmplw r4, r0
    bne _80077624
    lbz r4, 0x12(r5)
    lbz r0, 0xe(r3)
    cmplw r4, r0
    beqlr
_80077624:
    lis     r4, lbl_801A3220@ha
    li r0, 0
    addi r4, r4, lbl_801A3220@l
    stw r0, 0x48(r4)
    stw r0, 0x4c(r4)
    lbz r0, 0xc(r3)
    stb r0, 0x10(r5)
    lbz r0, 0xd(r3)
    stb r0, 0x11(r4)
    lbz r0, 0xe(r3)
    stb r0, 0x12(r4)
    blr
}

asm void fn_80077654(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    li r4, 0xe
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r3
    bl GXCachedSetTevSwapTable
    mr r3, r31
    li r4, 0x1e
    bl ModelSetCachedState_6B0
    mr r3, r31
    bl ModelClearCacheSlot_B28
    mr r3, r31
    li r4, 0xff
    li r5, 0xff
    li r6, 0xff
    bl ModelSetCachedMaterial_570
    mr r3, r31
    li r4, 0xf
    li r5, 0
    li r6, 0xe
    li r7, 0xf
    bl ModelSetCachedParam_F0
    mr r3, r31
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    mr r3, r31
    li r4, 7
    li r5, 0
    li r6, 6
    li r7, 7
    bl ModelSetCachedParam_1F0
    mr r3, r31
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80077714(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    li r4, 0xf
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r3
    bl GXCachedSetTevSwapTable
    mr r3, r31
    li r4, 0x1f
    bl ModelSetCachedState_6B0
    mr r3, r31
    bl ModelClearCacheSlot_B28
    mr r3, r31
    li r4, 0xff
    li r5, 0xff
    li r6, 0xff
    bl ModelSetCachedMaterial_570
    mr r3, r31
    li r4, 0
    li r5, 0xf
    li r6, 0xf
    li r7, 0xe
    bl ModelSetCachedParam_F0
    mr r3, r31
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_2F0
    mr r3, r31
    li r4, 0
    li r5, 7
    li r6, 7
    li r7, 6
    bl ModelSetCachedParam_1F0
    mr r3, r31
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl ModelSetCachedParam_430
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void AvDispInitModel(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    bl LightCtrl_InitChannels4
    lfs f1, -0x7998(r2)
    lis     r3, lbl_8019F130@ha
    addi r3, r3, lbl_8019F130@l
    fmr f2, f1
    stfs f1, 0xc(r3)
    fmr f3, f1
    fmr f4, f1
    bl GXColorClampScale
    lfs f1, -0x7994(r2)
    fmr f2, f1
    fmr f3, f1
    fmr f4, f1
    bl GXColorScale
    li r0, 0
    stw r0, -0x7630(r13)
    stw r0, -0x7628(r13)
    stw r0, -0x762c(r13)
    bl AvDispSetupModel
    bl AvDispClearMatrixStack
    bl fn_80070E00
    bl fn_80070D94
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void AvDispClearMatrixStack(void)
{
    nofralloc
    li r0, 0
    stw r0, -0x7618(r13)
    stw r0, -0x761c(r13)
    stw r0, -0x7620(r13)
    blr
}

asm void AvDispAllocMatrixStack(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_25
    cmpwi r4, 0
    mr r31, r3
    beq _800778AC
    bl OSGetArenaHi
    mulli r5, r31, 0x30
    li r0, 0
    stw r0, -0x7620(r13)
    rlwinm r4, r31, 2, 0, 0x1a
    rlwinm r0, r5, 0, 0, 0x1a
    subf r3, r0, r3
    stw r3, -0x7618(r13)
    subf r3, r4, r3
    stw r3, -0x761c(r13)
    bl OSSetArenaHi
    b _800779FC
_800778AC:
    mulli r3, r31, 0x30
    bl fn_80071794
    stw r3, -0x7618(r13)
    slwi r3, r31, 2
    bl fn_80071794
    li r0, 1
    cmplwi r31, 0
    stw r3, -0x761c(r13)
    li r5, 0
    stw r0, -0x7620(r13)
    ble _800779FC
    cmplwi r31, 8
    addi r6, r31, -8
    ble _800779C8
    addi r0, r6, 7
    li r3, 0
    srwi r0, r0, 3
    mr r4, r3
    mtctr r0
    cmplwi r6, 0
    ble _800779C8
_80077900:
    lwz r8, -0x7618(r13)
    addi r7, r3, 0x30
    lwz r6, -0x761c(r13)
    addi r0, r4, 4
    add r8, r8, r3
    addi r26, r3, 0x60
    stwx r8, r6, r4
    addi r27, r4, 8
    addi r28, r3, 0x90
    addi r12, r4, 0xc
    lwz r8, -0x7618(r13)
    addi r30, r3, 0xc0
    lwz r6, -0x761c(r13)
    addi r10, r4, 0x10
    add r7, r8, r7
    addi r11, r3, 0xf0
    stwx r7, r6, r0
    addi r8, r4, 0x14
    addi r9, r3, 0x120
    addi r7, r3, 0x150
    lwz r25, -0x7618(r13)
    addi r6, r4, 0x18
    lwz r29, -0x761c(r13)
    addi r0, r4, 0x1c
    add r26, r25, r26
    addi r3, r3, 0x180
    stwx r26, r29, r27
    addi r4, r4, 0x20
    addi r5, r5, 8
    lwz r27, -0x7618(r13)
    lwz r29, -0x761c(r13)
    add r28, r27, r28
    stwx r28, r29, r12
    lwz r29, -0x7618(r13)
    lwz r12, -0x761c(r13)
    add r30, r29, r30
    stwx r30, r12, r10
    lwz r12, -0x7618(r13)
    lwz r10, -0x761c(r13)
    add r11, r12, r11
    stwx r11, r10, r8
    lwz r10, -0x7618(r13)
    lwz r8, -0x761c(r13)
    add r9, r10, r9
    stwx r9, r8, r6
    lwz r8, -0x7618(r13)
    lwz r6, -0x761c(r13)
    add r7, r8, r7
    stwx r7, r6, r0
    bdnz _80077900
_800779C8:
    subf r0, r5, r31
    slwi r6, r5, 2
    mulli r4, r5, 0x30
    mtctr r0
    cmplw r5, r31
    bge _800779FC
_800779E0:
    lwz r0, -0x7618(r13)
    lwz r3, -0x761c(r13)
    add r0, r0, r4
    addi r4, r4, 0x30
    stwx r0, r3, r6
    addi r6, r6, 4
    bdnz _800779E0
_800779FC:
    lwz r3, -0x761c(r13)
    addi r11, r1, 0x30
    bl _restgpr_25
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_80077A18(void)
{
    nofralloc
    lwz r3, -0x761c(r13)
    blr
}

asm void fn_80077A20(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    lhz r0, 0x18(r3)
    mr r27, r3
    or. r28, r4, r4
    slwi r0, r0, 5
    add r30, r27, r0
    addi r30, r30, 0x40
    mr r29, r30
    bne _80077A84
    lwz r28, -0x761c(r13)
    li r4, 0
    b _80077A70
_80077A60:
    stw r30, 0(r28)
    addi r30, r30, 0x30
    addi r28, r28, 4
    addi r4, r4, 1
_80077A70:
    lbz r0, 0x1e(r27)
    clrlwi r3, r4, 0x18
    cmplw r3, r0
    blt _80077A60
    b _80077AB4
_80077A84:
    li r31, 0
    b _80077AA4
_80077A8C:
    lwz r4, 0(r28)
    mr r3, r30
    bl fn_8006DD14
    addi r30, r30, 0x30
    addi r28, r28, 4
    addi r31, r31, 1
_80077AA4:
    lbz r0, 0x1e(r27)
    clrlwi r3, r31, 0x18
    cmplw r3, r0
    blt _80077A8C
_80077AB4:
    mr r3, r29
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void AvDispGetModelMatrices(void)
{
    nofralloc
    li r7, 0
    li r6, 0
    b _80077AF0
_80077ADC:
    lwz r5, -0x761c(r13)
    addi r7, r7, 1
    stwx r4, r5, r6
    addi r4, r4, 0x30
    addi r6, r6, 4
_80077AF0:
    lbz r0, 0x1e(r3)
    cmpw r7, r0
    blt _80077ADC
    mr r3, r0
    blr
}

asm void AvDispSetAmbient(void)
{
    nofralloc
    lis     r3, lbl_8019F130@ha
    addi r3, r3, lbl_8019F130@l
    stfs f1, 0xc(r3)
    blr
}

asm void avdispWarnNotEffectiveModel(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    lwz r0, 4(r3)
    lwz r4, 0x20(r3)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    add r3, r3, r4
    beq _80077B40
    lwz r0, 8(r3)
    add r3, r3, r0
    b _80077B54
_80077B40:
    lis     r3, lbl_8015AD48@ha
    addi r3, r3, lbl_8015AD48@l
    crxor 6, 6, 6
    bl OSReport
    li r3, 0
_80077B54:
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void avdispWarnNotSkinningModel(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    lwz r0, 4(r3)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _80077B88
    lwz r0, 0x20(r3)
    add r3, r3, r0
    b _80077B9C
_80077B88:
    lis     r3, lbl_8015AD48@ha
    addi r3, r3, lbl_8015AD48@l
    crxor 6, 6, 6
    bl OSReport
    li r3, 0
_80077B9C:
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80077BAC(void)
{
    nofralloc
    lwz r0, -0x7630(r13)
    stw r3, -0x7630(r13)
    mr r3, r0
    blr
}

asm void fn_80077BBC(void)
{
    nofralloc
    cmpwi r3, 0
    li r0, 0
    beq _80077BCC
    li r0, 3
_80077BCC:
    stw r0, -0x7628(r13)
    blr
}

asm void fn_80077BD4(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_24
    mr r24, r3
    li r26, 0
    li r27, 0
    li r28, 0
    b _80077D18
_80077BFC:
    lwz r3, 8(r24)
    lwzx r25, r3, r28
    cmplwi r25, 0
    beq _80077D10
    lwz r0, 0x20(r25)
    li r31, 0
    mr r30, r31
    add r29, r25, r0
    b _80077CF8
_80077C20:
    lwz r3, 0x1c(r29)
    li r4, 0
    bl fn_80072404
    lwz r0, 4(r25)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _80077C68
    lwz r0, 0x28(r29)
    cmplwi r0, 0
    beq _80077C4C
    mullw r0, r3, r0
    add r31, r31, r0
_80077C4C:
    lwz r0, 0x2c(r29)
    cmplwi r0, 0
    beq _80077C60
    mullw r0, r3, r0
    add r31, r31, r0
_80077C60:
    addi r29, r29, 0x60
    b _80077CF4
_80077C68:
    lwz r0, 0x28(r29)
    cmplwi r0, 0
    beq _80077C7C
    divwu r0, r0, r3
    add r31, r31, r0
_80077C7C:
    lwz r0, 0x2c(r29)
    cmplwi r0, 0
    beq _80077C90
    divwu r0, r0, r3
    add r31, r31, r0
_80077C90:
    lbz r4, 0x13(r29)
    li r0, 0
    li r3, 1
    addi r5, r29, 0x60
    slw r0, r3, r0
    and. r0, r4, r0
    beq _80077CB4
    lwz r0, 0x28(r29)
    add r5, r5, r0
_80077CB4:
    li r0, 1
    lbz r4, 0x13(r29)
    slw r0, r3, r0
    and. r0, r4, r0
    beq _80077CD0
    lwz r0, 0x2c(r29)
    add r5, r5, r0
_80077CD0:
    lbz r0, 0x13(r29)
    rlwinm. r0, r0, 0, 0x1c, 0x1d
    beq _80077CF0
    lwz r3, 8(r5)
    lwz r0, 0xc(r5)
    addi r5, r5, 0x20
    add r5, r5, r3
    add r5, r5, r0
_80077CF0:
    mr r29, r5
_80077CF4:
    addi r30, r30, 1
_80077CF8:
    lhz r3, 0x1a(r25)
    lhz r0, 0x1c(r25)
    add r0, r3, r0
    cmplw r30, r0
    blt _80077C20
    add r26, r26, r31
_80077D10:
    addi r28, r28, 8
    addi r27, r27, 1
_80077D18:
    lwz r0, 0(r24)
    cmplw r27, r0
    blt _80077BFC
    mr r3, r26
    addi r11, r1, 0x30
    bl _restgpr_24
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_80077D40(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    mr r27, r3
    li r29, 0
    li r30, 0
    li r31, 0
    b _80077DE4
_80077D68:
    lwz r0, 4(r27)
    add r28, r0, r31
    lwz r0, 0(r28)
    rlwinm. r0, r0, 0, 0x17, 0x17
    bne _80077DDC
    lhz r3, 8(r28)
    lhz r4, 0xa(r28)
    bl fn_800717BC
    mr r7, r3
    addis r0, r7, 1
    cmplwi r0, 0xffff
    bne _80077D9C
    li r7, 0
_80077D9C:
    lhz r0, 0xc(r28)
    cmpwi r0, -1
    beq _80077DB4
    cmplw r0, r7
    bge _80077DB4
    mr r7, r0
_80077DB4:
    neg r0, r7
    lwz r5, 0(r28)
    or r0, r0, r7
    lhz r3, 8(r28)
    lhz r4, 0xa(r28)
    srwi r6, r0, 0x1f
    clrlwi r5, r5, 0x1b
    clrlwi r7, r7, 0x18
    bl __GXGetTexBufferSize
    add r29, r29, r3
_80077DDC:
    addi r31, r31, 0x10
    addi r30, r30, 1
_80077DE4:
    lwz r0, 0(r27)
    cmplw r30, r0
    blt _80077D68
    mr r3, r29
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80077E0C(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    stw r30, 8(r1)
    addi r30, r3, 0x40
    lwz r4, -0x7688(r13)
    lwz r0, 0x20(r3)
    lwz r4, 0x18(r4)
    add r31, r3, r0
    cmpwi r4, 0
    beq _80077E40
    xori r4, r4, 3
_80077E40:
    lwz r0, -0x7630(r13)
    stw r4, -0x7624(r13)
    cmplwi r0, 0
    bne _80077E58
    mr r4, r31
    bl fn_800756B0
_80077E58:
    mr r3, r31
    mr r4, r30
    bl fn_80075908
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80077E7C(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    mr r31, r3
    stw r30, 0x18(r1)
    stw r29, 0x14(r1)
    addi r29, r31, 0x40
    stw r28, 0x10(r1)
    lwz r4, -0x7688(r13)
    lwz r0, 0x20(r3)
    lwz r3, 0x18(r4)
    add r30, r31, r0
    cmpwi r3, 0
    beq _80077EBC
    xori r3, r3, 3
_80077EBC:
    stw r3, -0x7624(r13)
    lwz r3, 4(r31)
    rlwinm. r0, r3, 0, 0x1d, 0x1d
    beq _80077ED8
    mr r3, r31
    bl fn_80078C28
    b _80077EF0
_80077ED8:
    rlwinm. r0, r3, 0, 0x1c, 0x1c
    beq _80077EF0
    rlwinm. r0, r3, 0, 0x19, 0x19
    bne _80077EF0
    mr r3, r30
    bl fn_80078538
_80077EF0:
    li r0, 1
    stw r0, -0x762c(r13)
    lwz r0, 4(r31)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _80077F18
    mr r3, r31
    mr r4, r30
    mr r5, r29
    bl fn_800786B0
    b _80077F4C
_80077F18:
    li r28, 0
    b _80077F38
_80077F20:
    mr r3, r31
    mr r4, r30
    mr r5, r29
    bl fn_800789D8
    mr r30, r3
    addi r28, r28, 1
_80077F38:
    lhz r3, 0x1a(r31)
    lhz r0, 0x1c(r31)
    add r0, r3, r0
    cmpw r28, r0
    blt _80077F20
_80077F4C:
    li r0, 0
    stw r0, -0x762c(r13)
    lwz r0, 4(r31)
    rlwinm r0, r0, 0, 0x1b, 0x18
    stw r0, 4(r31)
    lwz r0, 4(r31)
    rlwinm r3, r0, 0x1e, 0x1f, 0x1f
    bl fn_80078CDC
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80077F8C(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    mr r31, r3
    stw r30, 0x18(r1)
    stw r29, 0x14(r1)
    addi r29, r31, 0x40
    stw r28, 0x10(r1)
    lwz r4, -0x7688(r13)
    lwz r0, 0x20(r3)
    lwz r3, 0x18(r4)
    add r30, r31, r0
    cmpwi r3, 0
    beq _80077FCC
    xori r3, r3, 3
_80077FCC:
    stw r3, -0x7624(r13)
    lwz r3, 4(r31)
    rlwinm. r0, r3, 0, 0x1d, 0x1d
    beq _80077FE8
    mr r3, r31
    bl fn_80078C28
    b _80078000
_80077FE8:
    rlwinm. r0, r3, 0, 0x1c, 0x1c
    beq _80078000
    rlwinm. r0, r3, 0, 0x19, 0x19
    bne _80078000
    mr r3, r30
    bl fn_80078538
_80078000:
    lwz r0, -0x7630(r13)
    cmplwi r0, 0
    bne _80078018
    mr r3, r31
    mr r4, r30
    bl fn_800756B0
_80078018:
    lwz r0, 4(r31)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _80078038
    mr r3, r31
    mr r4, r30
    mr r5, r29
    bl fn_800786B0
    b _8007806C
_80078038:
    li r28, 0
    b _80078058
_80078040:
    mr r3, r31
    mr r4, r30
    mr r5, r29
    bl fn_800789D8
    mr r30, r3
    addi r28, r28, 1
_80078058:
    lhz r3, 0x1a(r31)
    lhz r0, 0x1c(r31)
    add r0, r3, r0
    cmpw r28, r0
    blt _80078040
_8007806C:
    lwz r0, 4(r31)
    rlwinm r0, r0, 0, 0x1b, 0x18
    stw r0, 4(r31)
    lwz r0, 4(r31)
    rlwinm r3, r0, 0x1e, 0x1f, 0x1f
    bl fn_80078CDC
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_800780A4(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    stw r29, 0x14(r1)
    stw r28, 0x10(r1)
    mr r28, r3
    addi r30, r28, 0x40
    lwz r4, -0x7688(r13)
    lwz r0, 0x20(r3)
    lwz r3, 0x18(r4)
    add r31, r28, r0
    cmpwi r3, 0
    beq _800780E4
    xori r3, r3, 3
_800780E4:
    stw r3, -0x7624(r13)
    lwz r3, 4(r28)
    rlwinm. r0, r3, 0, 0x1d, 0x1d
    beq _80078100
    mr r3, r28
    bl fn_80078C28
    b _80078118
_80078100:
    rlwinm. r0, r3, 0, 0x1c, 0x1c
    beq _80078118
    rlwinm. r0, r3, 0, 0x19, 0x19
    bne _80078118
    mr r3, r31
    bl fn_80078538
_80078118:
    lwz r0, -0x7630(r13)
    cmplwi r0, 0
    bne _80078130
    mr r3, r28
    mr r4, r31
    bl fn_800756B0
_80078130:
    lwz r0, 4(r28)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _80078154
    mr r3, r28
    mr r4, r31
    mr r5, r30
    li r6, 1
    bl fn_80078768
    b _80078180
_80078154:
    li r29, 0
    b _80078174
_8007815C:
    mr r3, r28
    mr r4, r31
    mr r5, r30
    bl fn_800789D8
    mr r31, r3
    addi r29, r29, 1
_80078174:
    lhz r0, 0x1a(r28)
    cmpw r29, r0
    blt _8007815C
_80078180:
    lwz r0, 4(r28)
    rlwinm r0, r0, 0, 0x1b, 0x18
    stw r0, 4(r28)
    lwz r0, 4(r28)
    rlwinm r3, r0, 0x1e, 0x1f, 0x1f
    bl fn_80078CDC
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_800781B8(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    stw r29, 0x14(r1)
    mr r29, r3
    addi r30, r29, 0x40
    stw r28, 0x10(r1)
    lwz r4, -0x7688(r13)
    lwz r0, 0x20(r3)
    lwz r3, 0x18(r4)
    add r31, r29, r0
    cmpwi r3, 0
    beq _800781F8
    xori r3, r3, 3
_800781F8:
    stw r3, -0x7624(r13)
    lwz r3, 4(r29)
    rlwinm. r0, r3, 0, 0x1d, 0x1d
    beq _80078214
    mr r3, r29
    bl fn_80078C28
    b _8007822C
_80078214:
    rlwinm. r0, r3, 0, 0x1c, 0x1c
    beq _8007822C
    rlwinm. r0, r3, 0, 0x19, 0x19
    bne _8007822C
    mr r3, r31
    bl fn_80078538
_8007822C:
    lwz r0, -0x7630(r13)
    cmplwi r0, 0
    bne _80078244
    mr r3, r29
    mr r4, r31
    bl fn_800756B0
_80078244:
    lwz r0, 4(r29)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _80078268
    mr r3, r29
    mr r4, r31
    mr r5, r30
    li r6, 0
    bl fn_80078768
    b _8007830C
_80078268:
    lhz r0, 0x1a(r29)
    mtctr r0
    cmpwi r0, 0
    ble _800782E0
_80078278:
    lbz r4, 0x13(r31)
    li r0, 0
    li r3, 1
    addi r5, r31, 0x60
    slw r0, r3, r0
    and. r0, r4, r0
    beq _8007829C
    lwz r0, 0x28(r31)
    add r5, r5, r0
_8007829C:
    li r0, 1
    lbz r4, 0x13(r31)
    slw r0, r3, r0
    and. r0, r4, r0
    beq _800782B8
    lwz r0, 0x2c(r31)
    add r5, r5, r0
_800782B8:
    lbz r0, 0x13(r31)
    rlwinm. r0, r0, 0, 0x1c, 0x1d
    beq _800782D8
    lwz r3, 8(r5)
    lwz r0, 0xc(r5)
    addi r5, r5, 0x20
    add r5, r5, r3
    add r5, r5, r0
_800782D8:
    mr r31, r5
    bdnz _80078278
_800782E0:
    li r28, 0
    b _80078300
_800782E8:
    mr r3, r29
    mr r4, r31
    mr r5, r30
    bl fn_800789D8
    mr r31, r3
    addi r28, r28, 1
_80078300:
    lhz r0, 0x1c(r29)
    cmpw r28, r0
    blt _800782E8
_8007830C:
    lwz r0, 4(r29)
    rlwinm r0, r0, 0, 0x1b, 0x18
    stw r0, 4(r29)
    lwz r0, 4(r29)
    rlwinm r3, r0, 0x1e, 0x1f, 0x1f
    bl fn_80078CDC
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void GXWriteFifoByte(void)
{
    nofralloc
    li r6, 0x40
    lis r7, -0x3400
    ori r7, r7, 0x8000
    stb r6, 0(r7)
    stw r3, 0(r7)
    stw r4, 0(r7)
    blr
}

asm void fn_80078360(void)
{
    nofralloc
    stwu r1, -0x60(r1)
    mflr r0
    stw r0, 0x64(r1)
    addi r11, r1, 0x60
    bl _savegpr_24
    lwz r0, 0(r3)
    mr r24, r3
    mr r30, r4
    lwz r4, 8(r5)
    rlwinm. r3, r0, 0, 0x1e, 0x1e
    lwz r0, -0x7628(r13)
    mr r25, r5
    mr r26, r6
    mr r27, r7
    xori r0, r0, 2
    add r28, r25, r4
    beq _800783A8
    li r0, 0
_800783A8:
    lwz r3, 0x1c(r24)
    mr r29, r0
    bl GXLoadMtxArray
    lwz r12, -0x7630(r13)
    cmplwi r12, 0
    beq _800783DC
    stw r24, 0xc(r1)
    addi r3, r1, 8
    stw r30, 0x10(r1)
    mtctr r12
    bctrl
    clrlwi r0, r3, 0x18
    b _800783F8
_800783DC:
    lwz r0, -0x762c(r13)
    cmpwi r0, 0
    bne _800783F4
    mr r3, r24
    mr r4, r30
    bl fn_80075908
_800783F4:
    li r0, 1
_800783F8:
    clrlwi. r0, r0, 0x18
    beq _8007851C
    bl __GXSetDirtyState
    li r30, 0
    mr r31, r24
_8007840C:
    li r0, 1
    lbz r3, 0x13(r24)
    slw r0, r0, r30
    and. r0, r3, r0
    beq _800784FC
    mr r3, r29
    bl fn_80078D60
    lwz r3, 4(r27)
    rlwinm. r0, r3, 0, 0x19, 0x19
    beq _80078444
    lwz r3, 0x48(r31)
    lwz r4, 0x50(r31)
    bl GXWriteFifoByte
    b _800784FC
_80078444:
    rlwinm. r0, r3, 0, 0x1a, 0x1a
    beq _8007846C
    lwz r3, 0x30(r27)
    lis r4, 8
    addi r0, r3, 0x1f
    rlwinm r0, r0, 0, 0, 0x1a
    stw r0, 0x48(r31)
    lwz r3, 0x48(r31)
    bl fn_800723B8
    bl GXResetWriteGatherPipe
_8007846C:
    lwz r0, 0x1c(r25)
    clrlwi. r0, r0, 0x1f
    beq _8007849C
    lwz r3, 0x1c(r24)
    mr r4, r28
    lwz r6, 0x28(r31)
    mr r5, r26
    bl GXWriteFifoWordPair
    lwz r0, 0x28(r31)
    slwi r0, r0, 1
    add r26, r26, r0
    b _800784BC
_8007849C:
    lwz r3, 0x1c(r24)
    mr r4, r28
    lwz r6, 0x28(r31)
    mr r5, r26
    bl GXWriteFifoWord
    lwz r0, 0x28(r31)
    slwi r0, r0, 2
    add r26, r26, r0
_800784BC:
    lwz r0, 4(r27)
    rlwinm. r0, r0, 0, 0x1a, 0x1a
    beq _800784FC
    bl fn_800723D8
    stw r3, 0x50(r31)
    lwz r3, 0x48(r31)
    lwz r4, 0x50(r31)
    bl GXWriteFifoByte
    lwz r3, 0x48(r31)
    lwz r0, 0x50(r31)
    add r0, r3, r0
    stw r0, 0x30(r27)
    lwz r3, 0x34(r27)
    lwz r0, 0x50(r31)
    add r0, r3, r0
    stw r0, 0x34(r27)
_800784FC:
    cmpwi r29, 0
    beq _8007850C
    lwz r0, -0x7628(r13)
    xori r29, r0, 1
_8007850C:
    addi r30, r30, 1
    addi r31, r31, 4
    cmpwi r30, 2
    blt _8007840C
_8007851C:
    mr r3, r26
    addi r11, r1, 0x60
    bl _restgpr_24
    lwz r0, 0x64(r1)
    mtlr r0
    addi r1, r1, 0x60
    blr
}

#pragma pop
