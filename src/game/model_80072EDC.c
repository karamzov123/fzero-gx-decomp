typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void GXSetLineWidth(void);
extern void GXSetPointSize(void);
extern void _restgpr_22(void);
extern void _restgpr_23(void);
extern void _restgpr_25(void);
extern void _restgpr_26(void);
extern void _restgpr_27(void);
extern void _savegpr_22(void);
extern void _savegpr_23(void);
extern void _savegpr_25(void);
extern void _savegpr_26(void);
extern void _savegpr_27(void);
extern void GXSetTexCoordGen2(void);
extern void GXSetNumTexGens(void);
extern void __GXSetScissor_LT(void);
extern void __GXSetScissor_RB(void);
extern void __GXSetScissorBoxOffset(void);
extern void __GXInitTexObjHW(void);
extern void __GXSetBlendModePair(void);
extern void __GXSetChanAmbColor(void);
extern void __GXSetChanCtrl(void);
extern void GXXFormSetupA(void);
extern void GXXFormSetupB(void);
extern void GXLoadTexObj(void);
extern void __GXInitTexObj(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9);
extern void __GXInitTexObjLOD(void);
extern void __GXInitTexCacheRegs(void);
extern void fn_80036DA0(void);
extern void fn_80036EB4(void);
extern void GXWriteCachedParamF0(void);
extern void GXWriteCachedParam1F0(void);
extern void fn_80037128(void);
extern void fn_80037190(void);
extern void __GXSetChanMatColor(void);
extern void __GXSetLightAttnEnable_A(void);
extern void __GXSetLightAttnEnable_B(s32 chan, s32 val);
extern void GXSetChanCtrl(void);
extern void __GXWriteMatColorRegs(void);
extern void __GXWriteChanCtrlBitfields(void);
extern void GXSetScissor(void);
extern void GXComputeDeltaRatio(void);
extern void memcpy_fast(void);
extern void strncmp(void);
extern void fn_8006DD14(void);
extern unsigned char lbl_8019F040[240];
extern void* g_modelSysPtr;
extern double lbl_801A7468;
extern float lbl_801A7470;
extern float lbl_801A7474;
extern double lbl_801A7478;
extern s32 lbl_801A6D78;
asm void fn_80072EDC(void);
asm void ModelSetCachedMaterial_570(void);
asm void GXCachedSetTevSwapTable(void);

asm void ModelSetCachedNumTexGens(void);
asm void ModelSetCachedTex_704(void);
asm void ModelCacheMaterialParams(void);
asm void GXIntToFloatCopy(void);
asm void ModelSetCachedState_840(void);
asm void fn_800738E0(void);
asm void fn_800739E0(void);
asm void fn_80073A58(void);
asm void fn_80073B50(void);
asm void fn_80073D60(void);
asm void fn_80073E8C(void);
asm void fn_80074188(void);
asm void ModelSetCachedScissorLT_AFC(void);
asm void ModelSetCachedScissorRB_B08(void);
asm void ModelSetCachedScissorOffset_B04(void);
asm void ModelSetCachedTexObjHW_B10(void);
asm void ModelMatchCachedSlot_B20(void);
asm void ModelSetCachedPair5_B28(void);
asm void GXSetNumTexGensCached(void);
asm void GXSetLineWidthCached(void);
asm void GXSetPointSizeCached(void);
asm void GXSetChanAmbColorCached(void);
asm void LightCtrl_SetCachedRec_C30(void);
asm void GXSetTexGenCached(void);
asm void GXCopyMtxDirty(void);
#pragma push
#pragma force_active on

// provenance: original asm-relocation-fix fn_80072EDC (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_80072EDC(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    or. r29, r3, r3
    bne _80072F04
    li r31, 0xa
    li r30, 5
    b _80072F0C
_80072F04:
    li r31, 0
    li r30, 0
_80072F0C:
    cmpwi r4, 2
    beq _800732B0
    bge _80072F28
    cmpwi r4, 0
    beq _80073018
    bge _80072F38
    b _8007338C
_80072F28:
    cmpwi r4, 4
    beq _800731D8
    bge _8007338C
    b _800730F8
_80072F38:
    slwi r27, r29, 4
    lwz r0, g_modelSysPtr
    addi r28, r27, 0xf0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpw r0, r31
    bne _80072F78
    lwz r0, 4(r28)
    cmpwi r0, 8
    bne _80072F78
    lwz r0, 8(r28)
    cmpwi r0, 9
    bne _80072F78
    lwz r0, 0xc(r28)
    cmpwi r0, 0xf
    beq _80072FAC
_80072F78:
    mr r3, r29
    mr r4, r31
    li r5, 8
    li r6, 9
    li r7, 0xf
    bl GXWriteCachedParamF0
    stw r31, 0(r28)
    li r4, 8
    li r3, 9
    li r0, 0xf
    stw r4, 4(r28)
    stw r3, 8(r28)
    stw r0, 0xc(r28)
_80072FAC:
    lwz r0, g_modelSysPtr
    addi r28, r27, 0x1f0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 7
    bne _80072FE8
    lwz r0, 4(r28)
    cmpwi r0, 7
    bne _80072FE8
    lwz r0, 8(r28)
    cmpwi r0, 7
    bne _80072FE8
    lwz r0, 0xc(r28)
    cmpw r0, r30
    beq _8007338C
_80072FE8:
    mr r3, r29
    mr r7, r30
    li r4, 7
    li r5, 7
    li r6, 7
    bl GXWriteCachedParam1F0
    li r0, 7
    stw r0, 0(r28)
    stw r0, 4(r28)
    stw r0, 8(r28)
    stw r30, 0xc(r28)
    b _8007338C
_80073018:
    slwi r27, r29, 4
    lwz r0, g_modelSysPtr
    addi r28, r27, 0xf0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 0xf
    bne _80073058
    lwz r0, 4(r28)
    cmpwi r0, 8
    bne _80073058
    lwz r0, 8(r28)
    cmpw r0, r31
    bne _80073058
    lwz r0, 0xc(r28)
    cmpwi r0, 0xf
    beq _80073088
_80073058:
    mr r3, r29
    mr r6, r31
    li r4, 0xf
    li r5, 8
    li r7, 0xf
    bl GXWriteCachedParamF0
    li r3, 0xf
    li r0, 8
    stw r3, 0(r28)
    stw r0, 4(r28)
    stw r31, 8(r28)
    stw r3, 0xc(r28)
_80073088:
    lwz r0, g_modelSysPtr
    addi r28, r27, 0x1f0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 7
    bne _800730C4
    lwz r0, 4(r28)
    cmpwi r0, 4
    bne _800730C4
    lwz r0, 8(r28)
    cmpw r0, r30
    bne _800730C4
    lwz r0, 0xc(r28)
    cmpwi r0, 7
    beq _8007338C
_800730C4:
    mr r3, r29
    mr r6, r30
    li r4, 7
    li r5, 4
    li r7, 7
    bl GXWriteCachedParam1F0
    li r3, 7
    li r0, 4
    stw r3, 0(r28)
    stw r0, 4(r28)
    stw r30, 8(r28)
    stw r3, 0xc(r28)
    b _8007338C
_800730F8:
    slwi r27, r29, 4
    lwz r0, g_modelSysPtr
    addi r28, r27, 0xf0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 0xf
    bne _80073138
    lwz r0, 4(r28)
    cmpwi r0, 0xf
    bne _80073138
    lwz r0, 8(r28)
    cmpwi r0, 0xf
    bne _80073138
    lwz r0, 0xc(r28)
    cmpwi r0, 8
    beq _80073168
_80073138:
    mr r3, r29
    li r4, 0xf
    li r5, 0xf
    li r6, 0xf
    li r7, 8
    bl GXWriteCachedParamF0
    li r3, 0xf
    li r0, 8
    stw r3, 0(r28)
    stw r3, 4(r28)
    stw r3, 8(r28)
    stw r0, 0xc(r28)
_80073168:
    lwz r0, g_modelSysPtr
    addi r28, r27, 0x1f0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 7
    bne _800731A4
    lwz r0, 4(r28)
    cmpwi r0, 7
    bne _800731A4
    lwz r0, 8(r28)
    cmpwi r0, 7
    bne _800731A4
    lwz r0, 0xc(r28)
    cmpwi r0, 4
    beq _8007338C
_800731A4:
    mr r3, r29
    li r4, 7
    li r5, 7
    li r6, 7
    li r7, 4
    bl GXWriteCachedParam1F0
    li r3, 7
    li r0, 4
    stw r3, 0(r28)
    stw r3, 4(r28)
    stw r3, 8(r28)
    stw r0, 0xc(r28)
    b _8007338C
_800731D8:
    slwi r27, r29, 4
    lwz r0, g_modelSysPtr
    addi r28, r27, 0xf0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 0xf
    bne _80073218
    lwz r0, 4(r28)
    cmpwi r0, 0xf
    bne _80073218
    lwz r0, 8(r28)
    cmpwi r0, 0xf
    bne _80073218
    lwz r0, 0xc(r28)
    cmpw r0, r31
    beq _80073244
_80073218:
    mr r3, r29
    mr r7, r31
    li r4, 0xf
    li r5, 0xf
    li r6, 0xf
    bl GXWriteCachedParamF0
    li r0, 0xf
    stw r0, 0(r28)
    stw r0, 4(r28)
    stw r0, 8(r28)
    stw r31, 0xc(r28)
_80073244:
    lwz r0, g_modelSysPtr
    addi r28, r27, 0x1f0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 7
    bne _80073280
    lwz r0, 4(r28)
    cmpwi r0, 7
    bne _80073280
    lwz r0, 8(r28)
    cmpwi r0, 7
    bne _80073280
    lwz r0, 0xc(r28)
    cmpw r0, r30
    beq _8007338C
_80073280:
    mr r3, r29
    mr r7, r30
    li r4, 7
    li r5, 7
    li r6, 7
    bl GXWriteCachedParam1F0
    li r0, 7
    stw r0, 0(r28)
    stw r0, 4(r28)
    stw r0, 8(r28)
    stw r30, 0xc(r28)
    b _8007338C
_800732B0:
    slwi r27, r29, 4
    lwz r0, g_modelSysPtr
    addi r28, r27, 0xf0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpw r0, r31
    bne _800732F0
    lwz r0, 4(r28)
    cmpwi r0, 0xf
    bne _800732F0
    lwz r0, 8(r28)
    cmpwi r0, 8
    bne _800732F0
    lwz r0, 0xc(r28)
    cmpwi r0, 8
    beq _80073320
_800732F0:
    mr r3, r29
    mr r4, r31
    li r5, 0xf
    li r6, 8
    li r7, 8
    bl GXWriteCachedParamF0
    stw r31, 0(r28)
    li r3, 0xf
    li r0, 8
    stw r3, 4(r28)
    stw r0, 8(r28)
    stw r0, 0xc(r28)
_80073320:
    lwz r0, g_modelSysPtr
    addi r28, r27, 0x1f0
    add r28, r0, r28
    lwz r0, 0(r28)
    cmpwi r0, 7
    bne _8007335C
    lwz r0, 4(r28)
    cmpwi r0, 4
    bne _8007335C
    lwz r0, 8(r28)
    cmpw r0, r30
    bne _8007335C
    lwz r0, 0xc(r28)
    cmpwi r0, 7
    beq _8007338C
_8007335C:
    mr r3, r29
    mr r6, r30
    li r4, 7
    li r5, 4
    li r7, 7
    bl GXWriteCachedParam1F0
    li r3, 7
    li r0, 4
    stw r3, 0(r28)
    stw r0, 4(r28)
    stw r30, 8(r28)
    stw r3, 0xc(r28)
_8007338C:
    mulli r27, r29, 0x14
    lwz r0, g_modelSysPtr
    addi r28, r27, 0x2f0
    add r28, r0, r28
    lwz r0, 0x10(r28)
    cmpwi r0, 0
    bne _800733D8
    lwz r0, 8(r28)
    cmpwi r0, 0
    bne _800733D8
    lbz r0, 0xc(r28)
    cmplwi r0, 1
    bne _800733D8
    lwz r0, 0(r28)
    cmpwi r0, 0
    bne _800733D8
    lwz r0, 4(r28)
    cmpwi r0, 0
    beq _80073410
_800733D8:
    mr r3, r29
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl fn_80037128
    li r3, 0
    li r0, 1
    stw r3, 0(r28)
    stw r3, 4(r28)
    stw r3, 8(r28)
    stb r0, 0xc(r28)
    stw r3, 0x10(r28)
_80073410:
    lwz r0, g_modelSysPtr
    addi r28, r27, 0x430
    add r28, r0, r28
    lwz r0, 0x10(r28)
    cmpwi r0, 0
    bne _80073458
    lwz r0, 8(r28)
    cmpwi r0, 0
    bne _80073458
    lbz r0, 0xc(r28)
    cmplwi r0, 1
    bne _80073458
    lwz r0, 0(r28)
    cmpwi r0, 0
    bne _80073458
    lwz r0, 4(r28)
    cmpwi r0, 0
    beq _80073490
_80073458:
    mr r3, r29
    li r4, 0
    li r5, 0
    li r6, 0
    li r7, 1
    li r8, 0
    bl fn_80037190
    li r3, 0
    li r0, 1
    stw r3, 0(r28)
    stw r3, 4(r28)
    stw r3, 8(r28)
    stb r0, 0xc(r28)
    stw r3, 0x10(r28)
_80073490:
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedMaterial_570 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedMaterial_570(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    mr r28, r5
    slwi r5, r3, 4
    lwz r7, g_modelSysPtr
    cmpwi r28, 8
    addi r31, r5, 0x570
    mr r27, r4
    mr r29, r6
    add r31, r7, r31
    blt _80073534
    lwz r0, 0(r31)
    cmpw r0, r27
    bne _80073504
    lwz r0, 4(r31)
    cmpwi r0, 0xff
    bne _80073504
    lwz r0, 8(r31)
    cmpw r0, r29
    beq _800735B0
_80073504:
    mr r4, r27
    mr r5, r28
    mr r6, r29
    bl GXSetChanCtrl
    stw r27, 0(r31)
    li r3, 0xff
    li r0, 0
    stw r3, 4(r31)
    stw r29, 8(r31)
    sth r0, 0xc(r31)
    sth r0, 0xe(r31)
    b _800735B0
_80073534:
    mulli r4, r28, 0x24
    lwz r0, 0(r31)
    cmpw r0, r27
    addi r30, r4, 0x720
    add r30, r7, r30
    bne _80073584
    lwz r0, 4(r31)
    cmpw r0, r28
    bne _80073584
    lwz r0, 8(r31)
    cmpw r0, r29
    bne _80073584
    lhz r4, 0xc(r31)
    lhz r0, 0x20(r30)
    cmplw r4, r0
    bne _80073584
    lhz r4, 0xe(r31)
    lhz r0, 0x22(r30)
    cmplw r4, r0
    beq _800735B0
_80073584:
    mr r4, r27
    mr r5, r28
    mr r6, r29
    bl GXSetChanCtrl
    stw r27, 0(r31)
    stw r28, 4(r31)
    stw r29, 8(r31)
    lhz r0, 0x20(r30)
    sth r0, 0xc(r31)
    lhz r0, 0x22(r30)
    sth r0, 0xe(r31)
_800735B0:
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix GXCachedSetTevSwapTable (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXCachedSetTevSwapTable(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    slwi r31, r3, 2
    stw r30, 8(r1)
    mr r30, r4
    lwz r0, g_modelSysPtr
    add r5, r0, r31
    lwz r0, 0x670(r5)
    cmpw r0, r30
    beq _80073608
    bl __GXSetLightAttnEnable_A
    lwz r0, g_modelSysPtr
    add r3, r0, r31
    stw r30, 0x670(r3)
_80073608:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: repo-twin:LightCtrl_SetCachedByte_EC (main/game/lightctrl_8007264C) ModelSetCachedState_6B0
void ModelSetCachedState_6B0(s32 chan, s32 val)
{
    volatile s32* e = (volatile s32*)((u8*)g_modelSysPtr + 0x6b0) + chan;
    if (*e != val) {
        __GXSetLightAttnEnable_B(chan, val);
        e = (volatile s32*)((u8*)g_modelSysPtr + 0x6b0) + chan;
        *e = val;
    }
}

// provenance: original asm-relocation-fix ModelSetCachedNumTexGens (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedNumTexGens(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    clrlwi r0, r3, 0x18
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, g_modelSysPtr
    lbz r4, 0x6f0(r4)
    cmplw r4, r0
    beq _800736AC
    bl __GXWriteMatColorRegs
    lwz r3, g_modelSysPtr
    stb r31, 0x6f0(r3)
_800736AC:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedTex_704 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedTex_704(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    slwi r31, r3, 2
    stw r30, 0x18(r1)
    mr r30, r4
    lwz r0, g_modelSysPtr
    add r5, r0, r31
    lbz r0, 0(r4)
    lbz r4, 0x704(r5)
    cmplw r4, r0
    bne _80073730
    lbz r4, 0x705(r5)
    lbz r0, 1(r30)
    cmplw r4, r0
    bne _80073730
    lbz r4, 0x706(r5)
    lbz r0, 2(r30)
    cmplw r4, r0
    bne _80073730
    lbz r4, 0x707(r5)
    lbz r0, 3(r30)
    cmplw r4, r0
    bne _80073730
    lwz r0, 0x6f4(r5)
    cmpwi r0, 0
    beq _80073760
_80073730:
    lwz r0, 0(r30)
    addi r4, r1, 8
    stw r0, 8(r1)
    bl __GXSetChanMatColor
    lwz r3, g_modelSysPtr
    li r4, 0
    lwz r0, 0(r30)
    add r3, r3, r31
    stw r4, 0x6f4(r3)
    lwz r3, g_modelSysPtr
    add r3, r3, r31
    stw r0, 0x704(r3)
_80073760:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix ModelCacheMaterialParams (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelCacheMaterialParams(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    mr r30, r4
    mulli r4, r30, 0x24
    stw r29, 0x14(r1)
    mr r29, r3
    lwz r0, g_modelSysPtr
    addi r31, r4, 0x720
    add r31, r0, r31
    bl GXXFormSetupA
    sth r3, 0x20(r31)
    mr r3, r29
    bl GXXFormSetupB
    sth r3, 0x22(r31)
    mr r3, r29
    mr r4, r30
    bl GXLoadTexObj
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix GXIntToFloatCopy (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXIntToFloatCopy(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    xoris r5, r4, 0x8000
    lfd f1, lbl_801A7468
    stw r0, 0x34(r1)
    lis r0, 0x4330
    cmpwi r4, 0
    stw r5, 0x2c(r1)
    stw r0, 0x28(r1)
    lfd f0, 0x28(r1)
    fsubs f0, f0, f1
    stfs f0, 8(r1)
    beq _8007381C
    b _80073850
_8007381C:
    lfs f0, 0(r3)
    stfs f0, 0xc(r1)
    lfs f0, 8(r3)
    stfs f0, 0x10(r1)
    lfs f0, 0x14(r3)
    stfs f0, 0x14(r1)
    lfs f0, 0x18(r3)
    stfs f0, 0x18(r1)
    lfs f0, 0x28(r3)
    stfs f0, 0x1c(r1)
    lfs f0, 0x2c(r3)
    stfs f0, 0x20(r1)
    b _80073880
_80073850:
    lfs f0, 0(r3)
    stfs f0, 0xc(r1)
    lfs f0, 0xc(r3)
    stfs f0, 0x10(r1)
    lfs f0, 0x14(r3)
    stfs f0, 0x14(r1)
    lfs f0, 0x1c(r3)
    stfs f0, 0x18(r1)
    lfs f0, 0x28(r3)
    stfs f0, 0x1c(r1)
    lfs f0, 0x2c(r3)
    stfs f0, 0x20(r1)
_80073880:
    addi r3, r1, 8
    bl GXComputeDeltaRatio
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedState_840 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedState_840(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    clrlwi r0, r3, 0x18
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, g_modelSysPtr
    lbz r4, 0x840(r4)
    cmplw r4, r0
    beq _800738CC
    bl fn_80036EB4
    lwz r3, g_modelSysPtr
    stb r31, 0x840(r3)
_800738CC:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: original asm-relocation-fix fn_800738E0 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_800738E0(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    stw r29, 0x14(r1)
    mr r29, r5
    mulli r5, r3, 0xc
    stw r28, 0x10(r1)
    cmpwi r29, 8
    mr r28, r4
    lwz r6, g_modelSysPtr
    addi r31, r5, 0x844
    add r31, r6, r31
    blt _80073958
    lwz r0, 0(r31)
    cmpw r0, r3
    bne _80073934
    lwz r0, 4(r31)
    cmpw r0, r29
    beq _800739C0
_80073934:
    mr r4, r28
    mr r5, r29
    bl fn_80036DA0
    stw r28, 0(r31)
    li r0, 0
    stw r29, 4(r31)
    sth r0, 8(r31)
    sth r0, 0xa(r31)
    b _800739C0
_80073958:
    mulli r4, r29, 0x24
    lwz r0, 0(r31)
    cmpw r0, r3
    addi r30, r4, 0x720
    add r30, r6, r30
    bne _8007399C
    lwz r0, 4(r31)
    cmpw r0, r29
    bne _8007399C
    lhz r4, 8(r31)
    lhz r0, 0x20(r30)
    cmplw r4, r0
    bne _8007399C
    lhz r4, 0xa(r31)
    lhz r0, 0x22(r30)
    cmplw r4, r0
    beq _800739C0
_8007399C:
    mr r4, r28
    mr r5, r29
    bl fn_80036DA0
    stw r28, 0(r31)
    stw r29, 4(r31)
    lhz r0, 0x20(r30)
    sth r0, 8(r31)
    lhz r0, 0x22(r30)
    sth r0, 0xa(r31)
_800739C0:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix fn_800739E0 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_800739E0(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    slwi r6, r3, 3
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    addi r31, r6, 0x874
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    lwz r0, g_modelSysPtr
    add r31, r0, r31
    lwz r0, 0(r31)
    cmpw r0, r29
    bne _80073A28
    lwz r0, 4(r31)
    cmpw r0, r30
    beq _80073A3C
_80073A28:
    mr r4, r29
    mr r5, r30
    bl __GXInitTexCacheRegs
    stw r29, 0(r31)
    stw r30, 4(r31)
_80073A3C:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix fn_80073A58 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_80073A58(void)
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
    or. r28, r3, r3
    beq _80073B30
    cmpwi r28, 3
    bgt _80073AA4
    addi r0, r28, -1
    lwz r4, g_modelSysPtr
    mulli r3, r0, 0x1c
    addi r31, r3, 0x894
    add r31, r4, r31
    b _80073AE0
_80073AA4:
    cmpwi r28, 7
    bgt _80073AC4
    addi r0, r28, -5
    lwz r4, g_modelSysPtr
    mulli r3, r0, 0x1c
    addi r31, r3, 0x894
    add r31, r4, r31
    b _80073AE0
_80073AC4:
    cmpwi r28, 0xb
    bgt _80073AE0
    addi r0, r28, -9
    lwz r4, g_modelSysPtr
    mulli r3, r0, 0x1c
    addi r31, r3, 0x894
    add r31, r4, r31
_80073AE0:
    lbz r3, 0x18(r31)
    extsb r0, r30
    extsb r3, r3
    cmpw r3, r0
    bne _80073B0C
    mr r3, r31
    mr r4, r29
    li r5, 0x18
    bl strncmp
    cmpwi r3, 0
    beq _80073B30
_80073B0C:
    mr r3, r28
    mr r4, r29
    mr r5, r30
    bl __GXInitTexObjLOD
    mr r3, r31
    mr r4, r29
    li r5, 0x18
    bl memcpy_fast
    stb r30, 0x18(r31)
_80073B30:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix fn_80073B50 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_80073B50(void)
{
    nofralloc
    stwu r1, -0x40(r1)
    mflr r0
    stw r0, 0x44(r1)
    addi r11, r1, 0x40
    bl _savegpr_22
    slwi r11, r3, 5
    lwz r0, g_modelSysPtr
    addi r31, r11, 0x8e8
    mr r22, r4
    add r31, r0, r31
    lbz r29, 0x4b(r1)
    lwz r0, 0(r31)
    mr r23, r5
    lwz r30, 0x4c(r1)
    mr r24, r6
    cmpw r0, r22
    mr r25, r7
    mr r26, r8
    mr r27, r9
    mr r28, r10
    bne _80073C08
    lwz r0, 4(r31)
    cmpw r0, r23
    bne _80073C08
    lwz r0, 8(r31)
    cmpw r0, r24
    bne _80073C08
    lwz r0, 0xc(r31)
    cmpw r0, r25
    bne _80073C08
    lwz r0, 0x10(r31)
    cmpw r0, r26
    bne _80073C08
    lwz r0, 0x14(r31)
    cmpw r0, r27
    bne _80073C08
    lbz r4, 0x18(r31)
    clrlwi r0, r28, 0x18
    cmplw r4, r0
    bne _80073C08
    lbz r0, 0x19(r31)
    cmplw r0, r29
    bne _80073C08
    lwz r0, 0x1c(r31)
    cmpw r0, r30
    beq _80073C54
_80073C08:
    stw r29, 8(r1)
    mr r4, r22
    mr r5, r23
    mr r6, r24
    stw r30, 0xc(r1)
    mr r7, r25
    mr r8, r26
    mr r9, r27
    mr r10, r28
    bl __GXInitTexObj
    stw r22, 0(r31)
    stw r23, 4(r31)
    stw r24, 8(r31)
    stw r25, 0xc(r31)
    stw r26, 0x10(r31)
    stw r27, 0x14(r31)
    stb r28, 0x18(r31)
    stb r29, 0x19(r31)
    stw r30, 0x1c(r31)
_80073C54:
    addi r11, r1, 0x40
    bl _restgpr_22
    lwz r0, 0x44(r1)
    mtlr r0
    addi r1, r1, 0x40
    blr
}

// provenance: original asm-relocation-fix ModelClearCacheSlot_B28 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
// provenance: repo-twin:LightCtrl_SetCachedParam_2C (main/game/lightctrl_8007264C) ModelClearCacheSlot_B28
void ModelClearCacheSlot_B28(s32 idx)
{
    volatile s32* e = (volatile s32*)((u8*)g_modelSysPtr + (idx << 5) + 0x8e8);
    volatile u8* eb = (volatile u8*)e;
    if (e[0] || e[1] || e[2] || e[3] || e[4] || e[5] || eb[0x18] || eb[0x19] || e[7]) {
        __GXInitTexObj(idx, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        e[0] = 0; e[1] = 0; e[2] = 0; e[3] = 0; e[4] = 0; e[5] = 0;
        eb[0x18] = 0; eb[0x19] = 0; e[7] = 0;
    }
}

// provenance: original asm-relocation-fix fn_80073D60 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_80073D60(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_27
    clrlwi. r0, r6, 0x18
    mr r27, r4
    mr r28, r7
    li r4, 0
    beq _80073D8C
    li r4, 6
_80073D8C:
    clrlwi. r0, r5, 0x18
    mr r29, r4
    li r5, 0
    beq _80073DA0
    li r5, 7
_80073DA0:
    slwi r4, r3, 5
    lwz r0, g_modelSysPtr
    addi r31, r4, 0x8e8
    mr r30, r5
    add r31, r0, r31
    lwz r0, 0(r31)
    cmpw r0, r27
    bne _80073E20
    lwz r0, 4(r31)
    cmpwi r0, 0
    bne _80073E20
    lwz r0, 8(r31)
    cmpw r0, r5
    bne _80073E20
    lwz r0, 0xc(r31)
    cmpw r0, r28
    bne _80073E20
    lwz r0, 0x10(r31)
    cmpw r0, r29
    bne _80073E20
    lwz r0, 0x14(r31)
    cmpw r0, r29
    bne _80073E20
    lbz r0, 0x18(r31)
    cmplwi r0, 0
    bne _80073E20
    lbz r0, 0x19(r31)
    cmplwi r0, 0
    bne _80073E20
    lwz r0, 0x1c(r31)
    cmpwi r0, 0
    beq _80073E74
_80073E20:
    li r0, 0
    mr r4, r27
    stw r0, 8(r1)
    mr r6, r30
    mr r7, r28
    mr r8, r29
    stw r0, 0xc(r1)
    mr r9, r29
    li r5, 0
    li r10, 0
    bl __GXInitTexObj
    stw r27, 0(r31)
    li r0, 0
    stw r0, 4(r31)
    stw r30, 8(r31)
    stw r28, 0xc(r31)
    stw r29, 0x10(r31)
    stw r29, 0x14(r31)
    stb r0, 0x18(r31)
    stb r0, 0x19(r31)
    stw r0, 0x1c(r31)
_80073E74:
    addi r11, r1, 0x30
    bl _restgpr_27
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

// provenance: original asm-relocation-fix fn_80073E8C (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_80073E8C(void)
{
    nofralloc
    stwu r1, -0x60(r1)
    mflr r0
    stw r0, 0x64(r1)
    addi r11, r1, 0x60
    bl _savegpr_23
    clrlwi r0, r5, 0x10
    lwz r27, 0x68(r1)
    cmpwi r0, 0x40
    lwz r28, 0x6c(r1)
    mr r23, r3
    mr r24, r4
    mr r25, r9
    mr r26, r10
    beq _80073F08
    bge _80073EE0
    cmpwi r0, 0x20
    beq _80073F10
    bge _80073F20
    cmpwi r0, 0x10
    beq _80073F18
    b _80073F20
_80073EE0:
    cmpwi r0, 0x100
    beq _80073EF8
    bge _80073F20
    cmpwi r0, 0x80
    beq _80073F00
    b _80073F20
_80073EF8:
    li r30, 1
    b _80073F24
_80073F00:
    li r30, 2
    b _80073F24
_80073F08:
    li r30, 3
    b _80073F24
_80073F10:
    li r30, 4
    b _80073F24
_80073F18:
    li r30, 5
    b _80073F24
_80073F20:
    li r30, 0
_80073F24:
    clrlwi r0, r6, 0x10
    cmpwi r0, 0x40
    beq _80073F74
    bge _80073F4C
    cmpwi r0, 0x20
    beq _80073F7C
    bge _80073F8C
    cmpwi r0, 0x10
    beq _80073F84
    b _80073F8C
_80073F4C:
    cmpwi r0, 0x100
    beq _80073F64
    bge _80073F8C
    cmpwi r0, 0x80
    beq _80073F6C
    b _80073F8C
_80073F64:
    li r29, 1
    b _80073F90
_80073F6C:
    li r29, 2
    b _80073F90
_80073F74:
    li r29, 3
    b _80073F90
_80073F7C:
    li r29, 4
    b _80073F90
_80073F84:
    li r29, 5
    b _80073F90
_80073F8C:
    li r29, 0
_80073F90:
    lis r3, 0x4330
    clrlwi r4, r7, 0x10
    clrlwi r0, r8, 0x10
    stw r4, 0x2c(r1)
    lfs f1, lbl_801A7474
    cmpwi r26, 0
    stw r3, 0x28(r1)
    lfd f4, lbl_801A7478
    lfd f0, 0x28(r1)
    stw r0, 0x34(r1)
    fsubs f2, f0, f4
    lfs f3, lbl_801A7470
    stw r3, 0x30(r1)
    lfd f0, 0x30(r1)
    fmuls f2, f2, f3
    stfs f1, 0x14(r1)
    fsubs f0, f0, f4
    stfs f2, 0x10(r1)
    fmuls f0, f0, f3
    stfs f1, 0x18(r1)
    stfs f1, 0x1c(r1)
    stfs f0, 0x20(r1)
    stfs f1, 0x24(r1)
    beq _80074098
    cmpwi r26, 3
    bgt _80074010
    addi r0, r26, -1
    lwz r4, g_modelSysPtr
    mulli r3, r0, 0x1c
    addi r31, r3, 0x894
    add r31, r4, r31
    b _8007404C
_80074010:
    cmpwi r26, 7
    bgt _80074030
    addi r0, r26, -5
    lwz r4, g_modelSysPtr
    mulli r3, r0, 0x1c
    addi r31, r3, 0x894
    add r31, r4, r31
    b _8007404C
_80074030:
    cmpwi r26, 0xb
    bgt _8007404C
    addi r0, r26, -9
    lwz r4, g_modelSysPtr
    mulli r3, r0, 0x1c
    addi r31, r3, 0x894
    add r31, r4, r31
_8007404C:
    lbz r0, 0x18(r31)
    cmpwi r0, 0xa
    bne _80074070
    mr r3, r31
    addi r4, r1, 0x10
    li r5, 0x18
    bl strncmp
    cmpwi r3, 0
    beq _80074098
_80074070:
    mr r3, r26
    addi r4, r1, 0x10
    li r5, 0xa
    bl __GXInitTexObjLOD
    mr r3, r31
    addi r4, r1, 0x10
    li r5, 0x18
    bl memcpy_fast
    li r0, 0xa
    stb r0, 0x18(r31)
_80074098:
    slwi r3, r23, 5
    lwz r0, g_modelSysPtr
    addi r31, r3, 0x8e8
    add r31, r0, r31
    lwz r0, 0(r31)
    cmpw r0, r24
    bne _80074114
    lwz r0, 4(r31)
    cmpw r0, r25
    bne _80074114
    lwz r0, 8(r31)
    cmpw r0, r27
    bne _80074114
    lwz r0, 0xc(r31)
    cmpw r0, r26
    bne _80074114
    lwz r0, 0x10(r31)
    cmpw r0, r30
    bne _80074114
    lwz r0, 0x14(r31)
    cmpw r0, r29
    bne _80074114
    lbz r0, 0x18(r31)
    cmplwi r0, 0
    bne _80074114
    lbz r0, 0x19(r31)
    cmplwi r0, 1
    bne _80074114
    lwz r0, 0x1c(r31)
    cmpw r0, r28
    beq _80074170
_80074114:
    li r0, 1
    mr r3, r23
    stw r0, 8(r1)
    mr r4, r24
    mr r5, r25
    mr r6, r27
    stw r28, 0xc(r1)
    mr r7, r26
    mr r8, r30
    mr r9, r29
    li r10, 0
    bl __GXInitTexObj
    stw r24, 0(r31)
    li r3, 0
    li r0, 1
    stw r25, 4(r31)
    stw r27, 8(r31)
    stw r26, 0xc(r31)
    stw r30, 0x10(r31)
    stw r29, 0x14(r31)
    stb r3, 0x18(r31)
    stb r0, 0x19(r31)
    stw r28, 0x1c(r31)
_80074170:
    addi r11, r1, 0x60
    bl _restgpr_23
    lwz r0, 0x64(r1)
    mtlr r0
    addi r1, r1, 0x60
    blr
}

// provenance: original asm-relocation-fix fn_80074188 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void fn_80074188(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    mr r31, r6
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    stw r28, 0x10(r1)
    mr r28, r3
    lwz r7, g_modelSysPtr
    lwz r0, 0xae8(r7)
    cmplw r0, r28
    bne _800741E8
    lwz r0, 0xaec(r7)
    cmplw r0, r29
    bne _800741E8
    lwz r0, 0xaf0(r7)
    cmplw r0, r30
    bne _800741E8
    lwz r0, 0xaf4(r7)
    cmplw r0, r31
    beq _8007421C
_800741E8:
    mr r3, r28
    mr r4, r29
    mr r5, r30
    mr r6, r31
    bl GXSetScissor
    lwz r3, g_modelSysPtr
    stw r28, 0xae8(r3)
    lwz r3, g_modelSysPtr
    stw r29, 0xaec(r3)
    lwz r3, g_modelSysPtr
    stw r30, 0xaf0(r3)
    lwz r3, g_modelSysPtr
    stw r31, 0xaf4(r3)
_8007421C:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedScissorLT_AFC (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedScissorLT_AFC(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    clrlwi r0, r3, 0x10
    stw r31, 0x1c(r1)
    mr r31, r6
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    stw r28, 0x10(r1)
    mr r28, r3
    lwz r7, g_modelSysPtr
    lhz r3, 0xafc(r7)
    cmplw r3, r0
    bne _800742AC
    lhz r3, 0xafe(r7)
    clrlwi r0, r29, 0x10
    cmplw r3, r0
    bne _800742AC
    lhz r3, 0xb00(r7)
    clrlwi r0, r30, 0x10
    cmplw r3, r0
    bne _800742AC
    lhz r3, 0xb02(r7)
    clrlwi r0, r31, 0x10
    cmplw r3, r0
    beq _800742E0
_800742AC:
    mr r3, r28
    mr r4, r29
    mr r5, r30
    mr r6, r31
    bl __GXSetScissor_LT
    lwz r3, g_modelSysPtr
    sth r28, 0xafc(r3)
    lwz r3, g_modelSysPtr
    sth r29, 0xafe(r3)
    lwz r3, g_modelSysPtr
    sth r30, 0xb00(r3)
    lwz r3, g_modelSysPtr
    sth r31, 0xb02(r3)
_800742E0:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedScissorRB_B08 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedScissorRB_B08(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    clrlwi r0, r3, 0x10
    stw r31, 0x1c(r1)
    mr r31, r6
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    stw r28, 0x10(r1)
    mr r28, r3
    lwz r7, g_modelSysPtr
    lhz r3, 0xb08(r7)
    cmplw r3, r0
    bne _80074370
    lhz r3, 0xb0a(r7)
    clrlwi r0, r29, 0x10
    cmplw r3, r0
    bne _80074370
    lhz r3, 0xb0c(r7)
    clrlwi r0, r30, 0x10
    cmplw r3, r0
    bne _80074370
    lhz r3, 0xb0e(r7)
    clrlwi r0, r31, 0x10
    cmplw r3, r0
    beq _800743A4
_80074370:
    mr r3, r28
    mr r4, r29
    mr r5, r30
    mr r6, r31
    bl __GXSetScissor_RB
    lwz r3, g_modelSysPtr
    sth r28, 0xb08(r3)
    lwz r3, g_modelSysPtr
    sth r29, 0xb0a(r3)
    lwz r3, g_modelSysPtr
    sth r30, 0xb0c(r3)
    lwz r3, g_modelSysPtr
    sth r31, 0xb0e(r3)
_800743A4:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedScissorOffset_B04 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedScissorOffset_B04(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    clrlwi r0, r3, 0x10
    stw r31, 0xc(r1)
    mr r31, r4
    stw r30, 8(r1)
    mr r30, r3
    lwz r5, g_modelSysPtr
    lhz r3, 0xb04(r5)
    cmplw r3, r0
    bne _80074404
    lhz r3, 0xb06(r5)
    clrlwi r0, r31, 0x10
    cmplw r3, r0
    beq _80074420
_80074404:
    mr r3, r30
    mr r4, r31
    bl __GXSetScissorBoxOffset
    lwz r3, g_modelSysPtr
    sth r30, 0xb04(r3)
    lwz r3, g_modelSysPtr
    sth r31, 0xb06(r3)
_80074420:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedTexObjHW_B10 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedTexObjHW_B10(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    clrlwi r0, r3, 0x10
    stw r31, 0x1c(r1)
    mr r31, r6
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    stw r28, 0x10(r1)
    mr r28, r3
    lwz r7, g_modelSysPtr
    lhz r3, 0xb10(r7)
    cmplw r3, r0
    bne _800744A4
    lhz r3, 0xb12(r7)
    clrlwi r0, r29, 0x10
    cmplw r3, r0
    bne _800744A4
    lwz r0, 0xb14(r7)
    cmpw r0, r30
    bne _800744A4
    lbz r3, 0xb18(r7)
    clrlwi r0, r31, 0x18
    cmplw r3, r0
    beq _800744D8
_800744A4:
    mr r3, r28
    mr r4, r29
    mr r5, r30
    mr r6, r31
    bl __GXInitTexObjHW
    lwz r3, g_modelSysPtr
    sth r28, 0xb10(r3)
    lwz r3, g_modelSysPtr
    sth r29, 0xb12(r3)
    lwz r3, g_modelSysPtr
    stw r30, 0xb14(r3)
    lwz r3, g_modelSysPtr
    stb r31, 0xb18(r3)
_800744D8:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix ModelMatchCachedSlot_B20 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelMatchCachedSlot_B20(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    lbz r0, 0(r3)
    stw r31, 0x1c(r1)
    mr r31, r4
    stw r30, 0x18(r1)
    mr r30, r3
    lwz r5, g_modelSysPtr
    lbz r3, 0xb20(r5)
    cmplw r3, r0
    bne _80074564
    lbz r3, 0xb21(r5)
    lbz r0, 1(r30)
    cmplw r3, r0
    bne _80074564
    lbz r3, 0xb22(r5)
    lbz r0, 2(r30)
    cmplw r3, r0
    bne _80074564
    lbz r3, 0xb23(r5)
    lbz r0, 3(r30)
    cmplw r3, r0
    bne _80074564
    lwz r0, 0xb24(r5)
    cmplw r0, r31
    beq _8007458C
_80074564:
    lwz r0, 0(r30)
    mr r4, r31
    addi r3, r1, 8
    stw r0, 8(r1)
    bl __GXSetBlendModePair
    lwz r3, g_modelSysPtr
    lwz r0, 0(r30)
    stw r0, 0xb20(r3)
    lwz r3, g_modelSysPtr
    stw r31, 0xb24(r3)
_8007458C:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix ModelSetCachedPair5_B28 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void ModelSetCachedPair5_B28(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_26
    slwi r9, r3, 5
    lwz r0, g_modelSysPtr
    addi r31, r9, 0xb28
    mr r26, r4
    add r31, r0, r31
    mr r27, r5
    lwz r0, 0(r31)
    mr r28, r6
    mr r29, r7
    mr r30, r8
    cmpw r0, r26
    bne _8007461C
    lwz r0, 4(r31)
    cmpw r0, r27
    bne _8007461C
    lwz r0, 8(r31)
    cmplw r0, r28
    bne _8007461C
    lbz r4, 0xc(r31)
    clrlwi r0, r29, 0x18
    cmplw r4, r0
    bne _8007461C
    lwz r0, 0x10(r31)
    cmplw r0, r30
    beq _80074648
_8007461C:
    mr r4, r26
    mr r5, r27
    mr r6, r28
    mr r7, r29
    mr r8, r30
    bl GXSetTexCoordGen2
    stw r26, 0(r31)
    stw r27, 4(r31)
    stw r28, 8(r31)
    stb r29, 0xc(r31)
    stw r30, 0x10(r31)
_80074648:
    addi r11, r1, 0x20
    bl _restgpr_26
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix GXSetNumTexGensCached (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXSetNumTexGensCached(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    clrlwi r0, r3, 0x18
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, g_modelSysPtr
    lbz r4, 0xc28(r4)
    cmplw r4, r0
    beq _80074694
    bl GXSetNumTexGens
    lwz r3, g_modelSysPtr
    stb r31, 0xc28(r3)
_80074694:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: original asm-relocation-fix GXSetLineWidthCached (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXSetLineWidthCached(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    clrlwi r0, r3, 0x18
    stw r31, 0xc(r1)
    mr r31, r4
    stw r30, 8(r1)
    mr r30, r3
    lwz r5, g_modelSysPtr
    lbz r3, 9(r5)
    cmplw r3, r0
    bne _800746E4
    lwz r0, 0xc(r5)
    cmpw r0, r31
    beq _80074700
_800746E4:
    mr r3, r30
    mr r4, r31
    bl GXSetLineWidth
    lwz r3, g_modelSysPtr
    stb r30, 9(r3)
    lwz r3, g_modelSysPtr
    stw r31, 0xc(r3)
_80074700:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: original asm-relocation-fix GXSetPointSizeCached (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXSetPointSizeCached(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    clrlwi r0, r3, 0x18
    stw r31, 0xc(r1)
    mr r31, r4
    stw r30, 8(r1)
    mr r30, r3
    lwz r5, g_modelSysPtr
    lbz r3, 0x10(r5)
    cmplw r3, r0
    bne _80074754
    lwz r0, 0x14(r5)
    cmpw r0, r31
    beq _80074770
_80074754:
    mr r3, r30
    mr r4, r31
    bl GXSetPointSize
    lwz r3, g_modelSysPtr
    stb r30, 0x10(r3)
    lwz r3, g_modelSysPtr
    stw r31, 0x14(r3)
_80074770:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: original asm-relocation-fix GXSetChanAmbColorCached (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXSetChanAmbColorCached(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    clrlwi r0, r3, 0x18
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, g_modelSysPtr
    lbz r4, 0xc2e(r4)
    cmplw r4, r0
    beq _800747BC
    bl __GXSetChanAmbColor
    lwz r3, g_modelSysPtr
    stb r31, 0xc2e(r3)
_800747BC:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

// provenance: original asm-relocation-fix LightCtrl_SetCachedRec_C30 (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void LightCtrl_SetCachedRec_C30(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_25
    cmpwi r3, 3
    mr r26, r4
    mr r27, r5
    mr r28, r6
    mr r29, r7
    mr r30, r8
    mr r31, r9
    beq _80074880
    bge _80074820
    cmpwi r3, 1
    beq _8007483C
    bge _80074848
    cmpwi r3, 0
    bge _80074830
    b _80074880
_80074820:
    cmpwi r3, 5
    beq _8007486C
    bge _80074880
    b _80074854
_80074830:
    lwz r4, g_modelSysPtr
    addi r25, r4, 0xc30
    b _80074880
_8007483C:
    lwz r4, g_modelSysPtr
    addi r25, r4, 0xc48
    b _80074880
_80074848:
    lwz r4, g_modelSysPtr
    addi r25, r4, 0xc60
    b _80074880
_80074854:
    li r3, 0
    bl LightCtrl_SetCachedRec_C30
    lwz r4, g_modelSysPtr
    li r3, 2
    addi r25, r4, 0xc60
    b _80074880
_8007486C:
    li r3, 1
    bl LightCtrl_SetCachedRec_C30
    lwz r4, g_modelSysPtr
    li r3, 3
    addi r25, r4, 0xc78
_80074880:
    lbz r4, 0(r25)
    clrlwi r0, r26, 0x18
    cmplw r4, r0
    bne _800748CC
    lwz r0, 4(r25)
    cmpw r0, r27
    bne _800748CC
    lwz r0, 8(r25)
    cmpw r0, r28
    bne _800748CC
    lwz r0, 0xc(r25)
    cmplw r0, r29
    bne _800748CC
    lwz r0, 0x10(r25)
    cmpw r0, r30
    bne _800748CC
    lwz r0, 0x14(r25)
    cmpw r0, r31
    beq _80074900
_800748CC:
    mr r4, r26
    mr r5, r27
    mr r6, r28
    mr r7, r29
    mr r8, r30
    mr r9, r31
    bl __GXSetChanCtrl
    stb r26, 0(r25)
    stw r27, 4(r25)
    stw r28, 8(r25)
    stw r29, 0xc(r25)
    stw r30, 0x10(r25)
    stw r31, 0x14(r25)
_80074900:
    addi r11, r1, 0x30
    bl _restgpr_25
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

// provenance: original asm-relocation-fix GXSetTexGenCached (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXSetTexGenCached(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    clrlwi r0, r3, 0x18
    stw r31, 0x1c(r1)
    mr r31, r5
    stw r30, 0x18(r1)
    mr r30, r4
    stw r29, 0x14(r1)
    mr r29, r3
    lwz r6, g_modelSysPtr
    lbz r3, 0(r6)
    cmplw r3, r0
    bne _8007496C
    lwz r0, 4(r6)
    cmpw r0, r30
    bne _8007496C
    lbz r3, 8(r6)
    clrlwi r0, r31, 0x18
    cmplw r3, r0
    beq _80074994
_8007496C:
    mr r3, r29
    mr r4, r30
    mr r5, r31
    bl __GXWriteChanCtrlBitfields
    lwz r3, g_modelSysPtr
    stb r29, 0(r3)
    lwz r3, g_modelSysPtr
    stw r30, 4(r3)
    lwz r3, g_modelSysPtr
    stb r31, 8(r3)
_80074994:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

// provenance: original asm-relocation-fix GXCopyMtxDirty (bare-symbol sda21 form so MWCC re-emits R_PPC_EMB_SDA21; no instruction/semantic change)
asm void GXCopyMtxDirty(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    lis     r5, lbl_8019F040@ha
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    addi r31, r5, lbl_8019F040@l
    stw r30, 8(r1)
    or. r30, r3, r3
    mr r3, r4
    bne _80074A00
    cmplwi r3, 0
    beq _800749F4
    addi r4, r31, 0x20
    bl fn_8006DD14
    li r0, 1
    stw r0, lbl_801A6D78
    b _80074A48
_800749F4:
    li r0, 0
    stw r0, lbl_801A6D78
    b _80074A48
_80074A00:
    cmplwi r3, 0
    beq _80074A34
    addi r0, r30, -1
    addi r4, r31, 0x50
    mulli r0, r0, 0x30
    add r4, r4, r0
    bl fn_8006DD14
    addi r0, r30, -1
    addi r3, r31, 0xe0
    slwi r0, r0, 2
    li r4, 1
    stwx r4, r3, r0
    b _80074A48
_80074A34:
    addi r0, r30, -1
    addi r3, r31, 0xe0
    slwi r0, r0, 2
    li r4, 0
    stwx r4, r3, r0
_80074A48:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

#pragma pop
