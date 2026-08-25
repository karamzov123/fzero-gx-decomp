#pragma push
#pragma force_active on

extern asm void fn_8001BDF0(void);
extern asm void GXSetDrawDoneCallback(void);
extern asm void GXDrawDone(void);
extern asm void fn_80070100(void);
extern asm void fn_8007001C(void);
extern asm void GXSetDrawDone(void);
extern asm void GXGetGPFifo(void);
extern asm void GXGetFifoPtrs(void);
extern asm void GXGetCPUFifo(void);
extern asm void GXSaveCPUFifo(void);
extern asm void fn_800700B4(void);
extern asm void fn_80070068(void);
extern asm void GXSetGPFifo(void);
extern asm void LightCtrl_SetCachedByte_EC(void);
extern asm void __GXSetDispCopy(void);
extern asm void fn_8001BE6C(void);
extern asm void OSGetTick(void);
extern asm void _savegpr_27(void);
extern asm void OSGetTime(void);
extern asm void OSReport(void);
extern asm void _restgpr_27(void);
extern void fn_800700F4(void);
extern unsigned char lbl_8015AA10[98];
extern void fn_800700F4(void);

extern unsigned char lbl_801A6CB0[4];
extern unsigned char lbl_801A6CB4[1];
extern unsigned char lbl_801A6CB8[4];
extern unsigned char lbl_801A6CBC[2];
extern unsigned char lbl_801A6CC0[4];
extern unsigned char lbl_801A6CC4[2];
extern unsigned char lbl_801A6CC6[2];
extern unsigned char lbl_801A6CC8[4];
extern unsigned char lbl_801A6CCC[4];
extern unsigned char lbl_801A6CD0[4];
extern unsigned char lbl_801A6CD4[4];
extern unsigned char lbl_801A6CD8[8];
extern unsigned char lbl_801A6CE0[4];
extern unsigned char lbl_801A6CE4[4];
extern unsigned char lbl_801A6D30[8];
asm void fn_8006FC1C(void)
{
    nofralloc
    lbz	r6, 0(r3)
    lbz	r7, 0(r4)
    mr	r5, r3
    cmpw	r6, r7
    li	r3, 0
    bnelr	
_8006fc34:
    lbzu	r6, 1(r5)
    lbzu	r7, 1(r4)
    cmpw	r6, r7
    cmpwi	cr1, r6, 0
    cmpwi	cr5, r7, 0
    bnelr	
    bne	cr1, _8006fc34
    bne	cr5, _8006fc34
    li	r3, 1
    blr	
}

asm void fn_8006FC5C(void)
{
    nofralloc
    cmpwi	r5, 0
    mr	r6, r3
    li	r3, 0
    beqlr	
    lbz	r7, 0(r6)
    lbz	r8, 0(r4)
    cmpw	cr1, r7, r8
    addic.	r5, r5, -1
    bnelr	cr1
    beq	_8006fcac
_8006fc84:
    lbzu	r7, 1(r6)
    lbzu	r8, 1(r4)
    addic.	r5, r5, -1
    cmpw	cr1, r7, r8
    cmpwi	cr5, r7, 0
    cmpwi	cr6, r8, 0
    bnelr	cr1
    beq	_8006fcac
    bne	cr5, _8006fc84
    bne	cr6, _8006fc84
_8006fcac:
    li	r3, 1
    blr	
}

asm void fn_8006FCB4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r3, 0
    stw	r0, 0x14(r1)
    bl      fn_8001BDF0
    lis     r3, fn_800700F4@ha
    addi	r3, r3, fn_800700F4@l
    bl      GXSetDrawDoneCallback
    li	r0, 0
    stb	r0, lbl_801A6CB4
    bl      GXDrawDone
    li	r0, 0
    li	r4, 1
    li	r3, -1
    stw	r4, lbl_801A6CD0
    stw	r3, lbl_801A6CCC
    sth	r0, lbl_801A6CC6
    sth	r0, lbl_801A6CC4
    bl      fn_80070100
    bl      fn_8007001C
    li	r0, 0
    stw	r0, lbl_801A6CD4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8006FD1C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    li	r0, 0
    stb	r0, lbl_801A6CB4
    bl      GXSetDrawDone
    lwz	r0, lbl_801A6CE0
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    beq	_8006fd74
    bl      GXGetGPFifo
    addi	r4, r1, 0xc
    addi	r5, r1, 8
    bl      GXGetFifoPtrs
    bl      GXGetCPUFifo
    bl      GXSaveCPUFifo
    bl      fn_800700B4
    bl      fn_80070068
    lwz	r0, lbl_801A6D30
    slwi	r3, r3, 2
    add	r3, r0, r3
    lwz	r3, 0x14(r3)
    bl      GXSetGPFifo
_8006fd74:
    bl      GXGetCPUFifo
    addi	r4, r1, 0xc
    addi	r5, r1, 8
    bl      GXGetFifoPtrs
    lwz	r0, 8(r1)
    li	r3, 1
    stw	r0, lbl_801A6CD8
    bl      LightCtrl_SetCachedByte_EC
    bl      fn_8007001C
    lwz	r3, lbl_801A6D30
    li	r4, 1
    lwz	r3, 0(r3)
    bl      __GXSetDispCopy
    bl      fn_80070100
    bl      fn_8001BE6C
    stw	r3, lbl_801A6CCC
    bl      OSGetTick
    li	r0, 0
    stw	r3, lbl_801A6CC8
    sth	r0, lbl_801A6CC6
    sth	r0, lbl_801A6CC4
    bl      OSGetTick
    li	r0, 0
    stw	r3, lbl_801A6CB8
    stw	r0, lbl_801A6CC0
    sth	r0, lbl_801A6CBC
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8006FDEC(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    addi	r11, r1, 0x30
    bl      _savegpr_27
    li	r31, 0
    bl      OSGetTime
    mr	r27, r4
    mr	r28, r3
    b	_8006fe94
_8006fe14:
    bl      OSGetTime
    lwz	r0, 0xf8(r29)
    subfc	r4, r27, r4
    subfe	r3, r28, r3
    srwi	r5, r0, 2
    xoris	r3, r3, 0x8000
    subfc	r0, r4, r5
    subfe	r3, r3, r30
    subfe	r3, r30, r30
    neg.	r3, r3
    beq	_8006fea0
    lis	r3, 0x431c
    lwz	r4, lbl_801A6CC0
    addi	r0, r3, -0x217d
    lhz	r6, lbl_801A6CBC
    mulhwu	r0, r0, r5
    slwi	r7, r4, 3
    lis     r3, lbl_8015AA10@ha
    lhz	r4, lbl_801A6CC6
    lhz	r5, lbl_801A6CC4
    addi	r3, r3, lbl_8015AA10@l
    srwi	r0, r0, 0xf
    divwu	r7, r7, r0
    crxor	6, 6, 6
    bl      OSReport
    lwz	r12, lbl_801A6CB0
    cmplwi	r12, 0
    beq	_8006fe8c
    mtctr	r12
    bctrl	
_8006fe8c:
    li	r31, 1
    b	_8006feac
_8006fe94:
    li	r0, 0
    lis	r29, -0x8000
    xoris	r30, r0, 0x8000
_8006fea0:
    lbz	r0, lbl_801A6CB4
    cmplwi	r0, 0
    beq	_8006fe14
_8006feac:
    bl      GXGetCPUFifo
    addi	r4, r1, 0xc
    addi	r5, r1, 8
    bl      GXGetFifoPtrs
    lwz	r4, lbl_801A6CD8
    lwz	r3, 8(r1)
    cmplw	r4, r3
    subf	r0, r4, r3
    ble	_8006fedc
    lwz	r0, lbl_801A6CE4
    add	r0, r0, r3
    subf	r0, r4, r0
_8006fedc:
    stw	r0, lbl_801A6CD4
    mr	r3, r31
    addi	r11, r1, 0x30
    bl      _restgpr_27
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
