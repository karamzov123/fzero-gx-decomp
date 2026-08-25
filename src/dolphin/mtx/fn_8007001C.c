#pragma push
#pragma force_active on

extern asm void GXSetTexGenCached(void);
extern asm void GXWriteLightReg(void);
extern asm void LightCtrl_SetCachedByte_EE(void);
extern asm void GXGetCPUFifo(void);
extern asm void GXSetCPUFifo(void);
extern asm void GXGetGPStatus(void);
extern asm void GXClearVtxDesc(void);
extern asm void fn_800723F8(void);
extern asm void LightCtrl_SetCachedFogArray(void);
extern unsigned char lbl_8015A860[432];

extern unsigned char lbl_801A6CB4[1];
extern unsigned char lbl_801A6D30[8];
asm void fn_8007001C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r3, 1
    li	r4, 3
    stw	r0, 0x14(r1)
    li	r5, 1
    bl      GXSetTexGenCached
    li	r3, 7
    li	r4, 0
    li	r5, 0
    li	r6, 7
    li	r7, 0
    bl      GXWriteLightReg
    li	r3, 1
    bl      LightCtrl_SetCachedByte_EE
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80070068(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      GXGetCPUFifo
    lwz	r4, lbl_801A6D30
    lwz	r0, 0x14(r4)
    cmplw	r3, r0
    beq	_80070098
    mr	r3, r0
    bl      GXSetCPUFifo
    li	r3, 1
    b	_800700a4
_80070098:
    lwz	r3, 0x18(r4)
    bl      GXSetCPUFifo
    li	r3, 0
_800700a4:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800700B4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
_800700c0:
    addi	r3, r1, 0xb
    addi	r5, r1, 0xa
    mr	r4, r3
    addi	r6, r1, 9
    addi	r7, r1, 8
    bl      GXGetGPStatus
    lbz	r0, 0xa(r1)
    cmplwi	r0, 1
    bne	_800700c0
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800700F4(void)
{
    nofralloc
    li	r0, 1
    stb	r0, lbl_801A6CB4
    blr	
}

asm void fn_80070100(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8015A860@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8015A860@l
    bl      GXClearVtxDesc
    bl      fn_800723F8
    addi	r4, r31, 0
    li	r3, 0
    bl      LightCtrl_SetCachedFogArray
    addi	r4, r31, 0xc0
    li	r3, 1
    bl      LightCtrl_SetCachedFogArray
    addi	r4, r31, 0x180
    li	r3, 7
    bl      LightCtrl_SetCachedFogArray
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
