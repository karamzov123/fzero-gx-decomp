#pragma push
#pragma force_active on

typedef int BOOL;
extern void fn_80024E6C(void);
extern void fn_80025004(void);
extern void AXInvokeVoiceStopCallbacks(void);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void fn_80025A24(void);
extern void OSAlloc(void);
extern void OSFree(void);
extern void AXMixProcessVoiceFlags(void);
extern unsigned char lbl_80128990[3008];
extern unsigned char lbl_80176160[6144];

extern unsigned char g_currentHeapHandle[4];
extern unsigned char lbl_801A64F8[4];
extern unsigned char lbl_801A64FC[4];
extern unsigned char lbl_801A6B80[4];
extern unsigned char lbl_801A6B84[4];
extern unsigned char lbl_801A6B88[8];
asm void fn_80025504(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stmw	r25, 0x1c(r1)
    mr	r29, r3
    mr	r30, r4
    lbz	r4, 0x24(r30)
    lis	r3, 0x5555
    addi	r0, r3, 0x5556
    lwz	r6, 0(r29)
    addi	r4, r4, 1
    mulhw	r3, r0, r4
    lwz	r7, 4(r29)
    lwz	r8, 8(r29)
    srwi	r0, r3, 0x1f
    add	r0, r3, r0
    mulli	r0, r0, 3
    subf	r0, r0, r4
    clrlwi	r31, r0, 0x18
    slwi	r0, r31, 2
    add	r5, r30, r0
    lwzx	r3, r30, r0
    lwz	r4, 0xc(r5)
    lwz	r5, 0x18(r5)
    b       _80025568
_80025568:
    li	r0, 0x14
    mtctr	r0
    b       _80025574
_80025574:
    b       _80025578
_80025578:
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    lwz	r0, 0(r7)
    addi	r7, r7, 4
    stw	r0, 0(r4)
    addi	r4, r4, 4
    lwz	r0, 0(r8)
    addi	r8, r8, 4
    stw	r0, 0(r5)
    addi	r5, r5, 4
    bdnz    _80025578
    lwz	r0, 0x60(r30)
    srawi	r3, r0, 0x10
    addi	r0, r3, 1
    stw	r0, 0x84(r30)
    lwz	r0, 0x60(r30)
    clrlwi	r0, r0, 0x10
    slwi	r0, r0, 0x10
    stw	r0, 0x80(r30)
    lwz	r3, 0x64(r30)
    addi	r0, r3, -1
    cmplwi	r0, 0
    stw	r0, 0x64(r30)
    bne     _80025744
    lwz	r0, 0x68(r30)
    stw	r0, 0x64(r30)
    lwz	r0, 0x60(r30)
    neg	r0, r0
    stw	r0, 0x60(r30)
_80025744:
    li	r25, 0
    b       _8002574c
_8002574c:
    addi	r26, r30, 0x28
    addi	r27, r30, 0x38
    addi	r28, r30, 0x48
    b       _8002575c
_8002575c:
    b       _80025760
_80025760:
    lwz	r0, 0x5c(r30)
    cmpwi	r25, 1
    stw	r0, 0x7c(r30)
    lwz	r0, 0x58(r30)
    stw	r0, 0x78(r30)
    beq     _800257ac
    bge     _80025788
    cmpwi	r25, 0
    bge     _80025794
    b       _800257d8
_80025788:
    cmpwi	r25, 3
    bge     _800257d8
    b       _800257c4
_80025794:
    lwz	r0, 0(r30)
    stw	r0, 0x70(r30)
    lwz	r0, 0(r29)
    stw	r0, 0x6c(r30)
    stw	r26, 0x74(r30)
    b       _800257d8
_800257ac:
    lwz	r0, 0xc(r30)
    stw	r0, 0x70(r30)
    lwz	r0, 4(r29)
    stw	r0, 0x6c(r30)
    stw	r27, 0x74(r30)
    b       _800257d8
_800257c4:
    lwz	r0, 0x18(r30)
    stw	r0, 0x70(r30)
    lwz	r0, 8(r29)
    stw	r0, 0x6c(r30)
    stw	r28, 0x74(r30)
_800257d8:
    lwz	r0, 0x84(r30)
    cmpwi	r0, 1
    beq     _80025800
    bge     _80025808
    cmpwi	r0, 0
    bge     _800257f4
    b       _80025808
_800257f4:
    addi	r3, r30, 0x6c
    bl      fn_80024E6C
    b       _80025808
_80025800:
    addi	r3, r30, 0x6c
    bl      fn_80025004
_80025808:
    addi	r25, r25, 1
    cmplwi	r25, 3
    blt     _80025760
    lis	r3, -0x7777
    lwz	r4, 0x7c(r30)
    addi	r0, r3, -0x7777
    mulhwu	r0, r0, r4
    srwi	r0, r0, 8
    mulli	r0, r0, 0x1e0
    subf	r0, r0, r4
    stw	r0, 0x5c(r30)
    lwz	r0, 0x78(r30)
    stw	r0, 0x58(r30)
    stb	r31, 0x24(r30)
    lmw	r25, 0x1c(r1)
    lwz	r0, 0x3c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm void fn_80025854(void)
{
    nofralloc
    stwu	r1, -0x18(r1)
    li	r0, 0x50
    mtctr	r0
    stw	r31, 0x14(r1)
    lwz	r6, 0xc(r4)
    lwz	r5, 0x10(r4)
    lwz	r0, 0x14(r4)
    mulli	r11, r6, 0x280
    lwz	r12, 0x30(r4)
    lwz	r10, 0x34(r4)
    mulli	r5, r5, 0x280
    lwz	r6, 0x38(r4)
    lwz	r7, 0(r3)
    lwz	r8, 4(r3)
    mulli	r0, r0, 0x280
    lwz	r9, 8(r3)
    add	r3, r12, r11
    add	r5, r10, r5
    add	r6, r6, r0
_800258a0:
    lwz	r12, 0(r3)
    lwz	r0, 0x18(r4)
    lwz	r11, 0(r7)
    mullw	r10, r12, r0
    lwz	r31, 0(r5)
    lwz	r0, 0(r6)
    srawi	r10, r10, 7
    add	r10, r11, r10
    stw	r10, 0(r3)
    lwz	r10, 0x1c(r4)
    lwz	r11, 0(r8)
    mullw	r10, r31, r10
    srawi	r10, r10, 7
    add	r10, r11, r10
    stw	r10, 0(r5)
    lwz	r10, 0x20(r4)
    lwz	r11, 0(r9)
    mullw	r10, r0, r10
    srawi	r10, r10, 7
    add	r10, r11, r10
    stw	r10, 0(r6)
    lwz	r10, 0x24(r4)
    mullw	r10, r12, r10
    srawi	r10, r10, 7
    stw	r10, 0(r7)
    lwz	r10, 0x28(r4)
    mullw	r10, r31, r10
    srawi	r10, r10, 7
    stw	r10, 0(r8)
    lwz	r10, 0x2c(r4)
    mullw	r0, r0, r10
    srawi	r0, r0, 7
    stw	r0, 0(r9)
    lwz	r12, 4(r3)
    lwz	r0, 0x18(r4)
    lwz	r11, 4(r7)
    mullw	r10, r12, r0
    lwz	r31, 4(r5)
    lwz	r0, 4(r6)
    srawi	r10, r10, 7
    add	r10, r11, r10
    stw	r10, 4(r3)
    addi	r3, r3, 8
    lwz	r10, 0x1c(r4)
    lwz	r11, 4(r8)
    mullw	r10, r31, r10
    srawi	r10, r10, 7
    add	r10, r11, r10
    stw	r10, 4(r5)
    addi	r5, r5, 8
    lwz	r10, 0x20(r4)
    lwz	r11, 4(r9)
    mullw	r10, r0, r10
    srawi	r10, r10, 7
    add	r10, r11, r10
    stw	r10, 4(r6)
    addi	r6, r6, 8
    lwz	r10, 0x24(r4)
    mullw	r10, r12, r10
    srawi	r10, r10, 7
    stw	r10, 4(r7)
    addi	r7, r7, 8
    lwz	r10, 0x28(r4)
    mullw	r10, r31, r10
    srawi	r10, r10, 7
    stw	r10, 4(r8)
    addi	r8, r8, 8
    lwz	r10, 0x2c(r4)
    mullw	r0, r0, r10
    srawi	r0, r0, 7
    stw	r0, 4(r9)
    addi	r9, r9, 8
    bdnz    _800258a0
    lwz	r5, 0xc(r4)
    lwz	r3, 0(r4)
    addi	r5, r5, 1
    divwu	r0, r5, r3
    mullw	r0, r0, r3
    subf	r0, r0, r5
    stw	r0, 0xc(r4)
    lwz	r5, 0x10(r4)
    lwz	r3, 4(r4)
    addi	r5, r5, 1
    divwu	r0, r5, r3
    mullw	r0, r0, r3
    subf	r0, r0, r5
    stw	r0, 0x10(r4)
    lwz	r5, 0x14(r4)
    lwz	r3, 8(r4)
    addi	r5, r5, 1
    divwu	r0, r5, r3
    mullw	r0, r0, r3
    subf	r0, r0, r5
    stw	r0, 0x14(r4)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    blr	
}

asm void fn_80025A24(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    mr	r29, r3
    bl      AXInvokeVoiceStopCallbacks
    bl      OSDisableInterrupts
    lwz	r6, 0x3c(r29)
    lis	r4, -0x3333
    addi	r4, r4, -0x3333
    addi	r0, r6, -5
    slwi	r6, r0, 5
    addi	r0, r6, 0x9f
    mulhwu	r0, r4, r0
    srwi	r0, r0, 7
    stw	r0, 0(r29)
    li	r31, 0
    lis	r5, 0x51ec
    stw	r31, 0xc(r29)
    addi	r30, r3, 0
    addi	r0, r5, -0x7ae1
    lwz	r3, 0x48(r29)
    slwi	r3, r3, 7
    mulhwu	r3, r0, r3
    srwi	r3, r3, 5
    stw	r3, 0x18(r29)
    lwz	r3, 0x54(r29)
    slwi	r3, r3, 7
    mulhwu	r3, r0, r3
    srwi	r3, r3, 5
    stw	r3, 0x24(r29)
    lwz	r3, 0x40(r29)
    addi	r3, r3, -5
    slwi	r3, r3, 5
    addi	r3, r3, 0x9f
    mulhwu	r3, r4, r3
    srwi	r3, r3, 7
    stw	r3, 4(r29)
    stw	r31, 0x10(r29)
    lwz	r3, 0x4c(r29)
    slwi	r3, r3, 7
    mulhwu	r3, r0, r3
    srwi	r3, r3, 5
    stw	r3, 0x1c(r29)
    lwz	r3, 0x58(r29)
    slwi	r3, r3, 7
    mulhwu	r3, r0, r3
    srwi	r3, r3, 5
    stw	r3, 0x28(r29)
    lwz	r3, 0x44(r29)
    addi	r3, r3, -5
    slwi	r3, r3, 5
    addi	r3, r3, 0x9f
    mulhwu	r3, r4, r3
    srwi	r3, r3, 7
    stw	r3, 8(r29)
    stw	r31, 0x14(r29)
    lwz	r3, 0x50(r29)
    slwi	r3, r3, 7
    mulhwu	r3, r0, r3
    srwi	r3, r3, 5
    stw	r3, 0x20(r29)
    lwz	r3, 0x5c(r29)
    slwi	r3, r3, 7
    mulhwu	r0, r0, r3
    srwi	r0, r0, 5
    stw	r0, 0x2c(r29)
    lwz	r0, 0(r29)
    lwz	r12, lbl_801A64F8
    mulli	r3, r0, 0x280
    mtlr	r12
    blrl	
    stw	r3, 0x30(r29)
    lwz	r0, 4(r29)
    lwz	r12, lbl_801A64F8
    mulli	r3, r0, 0x280
    mtlr	r12
    blrl	
    stw	r3, 0x34(r29)
    lwz	r0, 8(r29)
    lwz	r12, lbl_801A64F8
    mulli	r3, r0, 0x280
    mtlr	r12
    blrl	
    stw	r3, 0x38(r29)
    li	r3, 0
    lwz	r4, 0x30(r29)
    lwz	r5, 0x34(r29)
    lwz	r6, 0x38(r29)
    b       _80025ba0
_80025b94:
    stw	r31, 0(r4)
    addi	r4, r4, 4
    addi	r3, r3, 1
_80025ba0:
    lwz	r0, 0(r29)
    mulli	r0, r0, 0xa0
    cmplw	r3, r0
    blt     _80025b94
    li	r4, 0
    addi	r3, r4, 0
    b       _80025bc8
_80025bbc:
    stw	r3, 0(r5)
    addi	r5, r5, 4
    addi	r4, r4, 1
_80025bc8:
    lwz	r0, 4(r29)
    mulli	r0, r0, 0xa0
    cmplw	r4, r0
    blt     _80025bbc
    li	r4, 0
    addi	r3, r4, 0
    b       _80025bf0
_80025be4:
    stw	r3, 0(r6)
    addi	r6, r6, 4
    addi	r4, r4, 1
_80025bf0:
    lwz	r0, 8(r29)
    mulli	r0, r0, 0xa0
    cmplw	r4, r0
    blt     _80025be4
    mr	r3, r30
    bl      OSRestoreInterrupts
    lwz	r0, 0x2c(r1)
    li	r3, 1
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void fn_80025C28(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    li	r0, 0
    stw	r0, 0x30(r31)
    stw	r0, 0x34(r31)
    stw	r0, 0x38(r31)
    bl      OSRestoreInterrupts
    mr	r3, r31
    bl      fn_80025A24
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void AXInvokeVoiceStopCallbacks(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lwz	r0, 0x30(r30)
    addi	r31, r3, 0
    cmplwi	r0, 0
    beq     _80025cac
    lwz	r12, lbl_801A64FC
    mr	r3, r0
    mtlr	r12
    blrl	
_80025cac:
    lwz	r3, 0x34(r30)
    cmplwi	r3, 0
    beq     _80025cc4
    lwz	r12, lbl_801A64FC
    mtlr	r12
    blrl	
_80025cc4:
    lwz	r3, 0x38(r30)
    cmplwi	r3, 0
    beq     _80025cdc
    lwz	r12, lbl_801A64FC
    mtlr	r12
    blrl	
_80025cdc:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    li	r3, 1
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80025D00(void)
{
    nofralloc
    mflr	r0
    mr	r4, r3
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r3, g_currentHeapHandle
    bl      OSAlloc
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_80025D28(void)
{
    nofralloc
    mflr	r0
    mr	r4, r3
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r3, g_currentHeapHandle
    bl      OSFree
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_80025D50(void)
{
    nofralloc
    stw	r3, lbl_801A64F8
    stw	r4, lbl_801A64FC
    blr	
}

asm void AXMixProcessVoiceFlags(void)
{
    nofralloc
    lwz	r0, lbl_801A6B88
    lis     r4, lbl_80128990@ha
    lwz	r5, 0x14(r3)
    addi	r9, r4, lbl_80128990@l
    cmplwi	r0, 3
    lwz	r6, 0x18(r3)
    subfic	r7, r5, 0x7f
    subfic	r10, r6, 0x7f
    bne     _80025dd4
    slwi	r0, r5, 1
    add	r8, r9, r0
    lha	r0, 0x98c(r8)
    slwi	r5, r7, 1
    slwi	r4, r10, 1
    stw	r0, 0x20(r3)
    add	r7, r9, r5
    slwi	r0, r6, 1
    lha	r6, 0x98c(r7)
    add	r5, r9, r4
    add	r4, r9, r0
    stw	r6, 0x24(r3)
    lha	r0, 0x98c(r5)
    stw	r0, 0x28(r3)
    lha	r0, 0x98c(r4)
    stw	r0, 0x2c(r3)
    lha	r0, 0xa8c(r7)
    stw	r0, 0x30(r3)
    lha	r0, 0xa8c(r8)
    stw	r0, 0x34(r3)
    blr	
_80025dd4:
    slwi	r0, r5, 2
    add	r4, r9, r0
    lwz	r5, 0x78c(r4)
    slwi	r0, r7, 2
    slwi	r4, r10, 2
    stw	r5, 0x20(r3)
    add	r5, r9, r0
    slwi	r0, r6, 2
    lwz	r6, 0x78c(r5)
    add	r5, r9, r4
    add	r4, r9, r0
    stw	r6, 0x24(r3)
    lwz	r0, 0x78c(r5)
    stw	r0, 0x28(r3)
    lwz	r0, 0x78c(r4)
    stw	r0, 0x2c(r3)
    blr	
}

asm void axmix_voices_reset_all(void)
{
    nofralloc
    mflr	r0
    lis	r3, lbl_80176160@ha
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    lis	r30, 0x5000
    stw	r29, 0xc(r1)
    addi	r29, r3, lbl_80176160@l
    stw	r28, 8(r1)
    li	r28, 0
_80025e44:
    stw	r30, 4(r29)
    li	r31, 0
    li	r5, -0x3c0
    stw	r31, 8(r29)
    li	r4, 0x40
    li	r0, 0x7f
    stw	r5, 0xc(r29)
    mr	r3, r29
    stw	r5, 0x10(r29)
    stw	r31, 0x1c(r29)
    stw	r4, 0x14(r29)
    stw	r0, 0x18(r29)
    sth	r31, 0x5c(r29)
    sth	r31, 0x58(r29)
    sth	r31, 0x54(r29)
    sth	r31, 0x50(r29)
    sth	r31, 0x4c(r29)
    sth	r31, 0x48(r29)
    sth	r31, 0x44(r29)
    sth	r31, 0x40(r29)
    sth	r31, 0x3c(r29)
    sth	r31, 0x38(r29)
    bl      AXMixProcessVoiceFlags
    addi	r28, r28, 1
    cmpwi	r28, 0x40
    addi	r29, r29, 0x60
    blt     _80025e44
    li	r0, 1
    stw	r31, lbl_801A6B80
    stw	r31, lbl_801A6B84
    stw	r0, lbl_801A6B88
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    lwz	r29, 0xc(r1)
    lwz	r28, 8(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

// provenance: original — direct retail empty-body reconstruction
void fn_80025EE0(void)
{
}

// provenance: original — derived directly from fn_80025EE4 retail store
void fn_80025EE4(void* a)
{
    *(volatile void**)lbl_801A6B88 = a;
}

void* AXGetMixStateWord(void)
{
    return *(volatile void**)lbl_801A6B88;
}

asm void AXMixSetupVoiceEntry(void)
{
    nofralloc
    mflr	r0
    lis     r12, lbl_80128990@ha
    stw	r0, 4(r1)
    stwu	r1, -0xe8(r1)
    stw	r31, 0xe4(r1)
    addi	r31, r12, lbl_80128990@l
    stw	r30, 0xe0(r1)
    stw	r29, 0xdc(r1)
    addi	r29, r5, 0
    stw	r28, 0xd8(r1)
    mr	r28, r3
    lwz	r0, 0x18(r3)
    lis     r3, lbl_80176160@ha
    mulli	r11, r0, 0x60
    addi	r0, r3, lbl_80176160@l
    add	r30, r0, r11
    stw	r28, 0(r30)
    clrlwi	r0, r4, 0x1d
    addi	r3, r30, 0
    stw	r0, 4(r30)
    stw	r29, 8(r30)
    stw	r6, 0xc(r30)
    stw	r7, 0x10(r30)
    stw	r8, 0x14(r30)
    stw	r9, 0x18(r30)
    stw	r10, 0x1c(r30)
    bl      AXMixProcessVoiceFlags
    lwz	r0, 4(r30)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    beq     _80025f78
    li	r0, 0
    sth	r0, 0x38(r30)
    b       _80025fac
_80025f78:
    cmpwi	r29, -0x388
    bgt     _80025f88
    li	r0, 0
    b       _80025fa8
_80025f88:
    cmpwi	r29, 0x3c
    blt     _80025f9c
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80025fa8
_80025f9c:
    slwi	r0, r29, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80025fa8:
    sth	r0, 0x38(r30)
_80025fac:
    lwz	r0, lbl_801A6B88
    li	r29, 0
    cmpwi	r0, 3
    beq     _80026870
    bge     _80026c04
    cmpwi	r0, 0
    beq     _80025fd0
    bge     _800263f8
    b       _80026c04
_80025fd0:
    lwz	r3, 0x1c(r30)
    lwz	r0, 0x28(r30)
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80025fec
    li	r0, 0
    b       _8002600c
_80025fec:
    cmpwi	r0, 0x3c
    blt     _80026000
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002600c
_80026000:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002600c:
    sth	r0, 0x3c(r30)
    lwz	r3, 0x1c(r30)
    lwz	r0, 0x28(r30)
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _8002602c
    li	r0, 0
    b       _8002604c
_8002602c:
    cmpwi	r0, 0x3c
    blt     _80026040
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002604c
_80026040:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002604c:
    sth	r0, 0x40(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0x1c(r30)
    addi	r3, r3, -0x1e
    add	r3, r0, r3
    cmpwi	r3, -0x388
    bgt     _80026070
    li	r0, 0
    b       _80026090
_80026070:
    cmpwi	r3, 0x3c
    blt     _80026084
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026090
_80026084:
    slwi	r0, r3, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026090:
    sth	r0, 0x44(r30)
    lwz	r0, 4(r30)
    clrlwi.	r0, r0, 0x1f
    beq     _80026168
    lwz	r3, 0xc(r30)
    lwz	r0, 0x28(r30)
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800260bc
    li	r0, 0
    b       _800260dc
_800260bc:
    cmpwi	r0, 0x3c
    blt     _800260d0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800260dc
_800260d0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800260dc:
    sth	r0, 0x48(r30)
    lwz	r3, 0xc(r30)
    lwz	r0, 0x28(r30)
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800260fc
    li	r0, 0
    b       _8002611c
_800260fc:
    cmpwi	r0, 0x3c
    blt     _80026110
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002611c
_80026110:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002611c:
    sth	r0, 0x4c(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0xc(r30)
    addi	r3, r3, -0x1e
    add	r3, r0, r3
    cmpwi	r3, -0x388
    bgt     _80026140
    li	r0, 0
    b       _80026160
_80026140:
    cmpwi	r3, 0x3c
    blt     _80026154
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026160
_80026154:
    slwi	r0, r3, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026160:
    sth	r0, 0x50(r30)
    b       _80026244
_80026168:
    lwz	r4, 0x28(r30)
    lwz	r0, 0xc(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _8002618c
    li	r0, 0
    b       _800261ac
_8002618c:
    cmpwi	r0, 0x3c
    blt     _800261a0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800261ac
_800261a0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800261ac:
    sth	r0, 0x48(r30)
    lwz	r4, 0x28(r30)
    lwz	r0, 0xc(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800261d4
    li	r0, 0
    b       _800261f4
_800261d4:
    cmpwi	r0, 0x3c
    blt     _800261e8
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800261f4
_800261e8:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800261f4:
    sth	r0, 0x4c(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x1c(r30)
    add	r3, r0, r3
    addi	r0, r3, -0x1e
    add	r0, r4, r0
    cmpwi	r0, -0x388
    bgt     _80026220
    li	r0, 0
    b       _80026240
_80026220:
    cmpwi	r0, 0x3c
    blt     _80026234
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026240
_80026234:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026240:
    sth	r0, 0x50(r30)
_80026244:
    lwz	r0, 4(r30)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    beq     _80026318
    lwz	r3, 0x10(r30)
    lwz	r0, 0x28(r30)
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _8002626c
    li	r0, 0
    b       _8002628c
_8002626c:
    cmpwi	r0, 0x3c
    blt     _80026280
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002628c
_80026280:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002628c:
    sth	r0, 0x54(r30)
    lwz	r3, 0x10(r30)
    lwz	r0, 0x28(r30)
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800262ac
    li	r0, 0
    b       _800262cc
_800262ac:
    cmpwi	r0, 0x3c
    blt     _800262c0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800262cc
_800262c0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800262cc:
    sth	r0, 0x58(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0x10(r30)
    addi	r3, r3, -0x1e
    add	r3, r0, r3
    cmpwi	r3, -0x388
    bgt     _800262f0
    li	r0, 0
    b       _80026310
_800262f0:
    cmpwi	r3, 0x3c
    blt     _80026304
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026310
_80026304:
    slwi	r0, r3, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026310:
    sth	r0, 0x5c(r30)
    b       _80026c04
_80026318:
    lwz	r4, 0x28(r30)
    lwz	r0, 0x10(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _8002633c
    li	r0, 0
    b       _8002635c
_8002633c:
    cmpwi	r0, 0x3c
    blt     _80026350
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002635c
_80026350:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002635c:
    sth	r0, 0x54(r30)
    lwz	r4, 0x28(r30)
    lwz	r0, 0x10(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026384
    li	r0, 0
    b       _800263a4
_80026384:
    cmpwi	r0, 0x3c
    blt     _80026398
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800263a4
_80026398:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800263a4:
    sth	r0, 0x58(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0x10(r30)
    lwz	r4, 0x1c(r30)
    add	r3, r0, r3
    addi	r0, r3, -0x1e
    add	r0, r4, r0
    cmpwi	r0, -0x388
    bgt     _800263d0
    li	r0, 0
    b       _800263f0
_800263d0:
    cmpwi	r0, 0x3c
    blt     _800263e4
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800263f0
_800263e4:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800263f0:
    sth	r0, 0x5c(r30)
    b       _80026c04
_800263f8:
    lwz	r4, 0x28(r30)
    lwz	r0, 0x20(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _8002641c
    li	r0, 0
    b       _8002643c
_8002641c:
    cmpwi	r0, 0x3c
    blt     _80026430
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002643c
_80026430:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002643c:
    sth	r0, 0x3c(r30)
    lwz	r4, 0x28(r30)
    lwz	r0, 0x24(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026464
    li	r0, 0
    b       _80026484
_80026464:
    cmpwi	r0, 0x3c
    blt     _80026478
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026484
_80026478:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026484:
    sth	r0, 0x40(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0x1c(r30)
    addi	r3, r3, -0x1e
    add	r3, r0, r3
    cmpwi	r3, -0x388
    bgt     _800264a8
    li	r0, 0
    b       _800264c8
_800264a8:
    cmpwi	r3, 0x3c
    blt     _800264bc
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800264c8
_800264bc:
    slwi	r0, r3, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800264c8:
    sth	r0, 0x44(r30)
    lwz	r0, 4(r30)
    clrlwi.	r0, r0, 0x1f
    beq     _800265b0
    lwz	r4, 0x28(r30)
    lwz	r0, 0x20(r30)
    lwz	r3, 0xc(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800264fc
    li	r0, 0
    b       _8002651c
_800264fc:
    cmpwi	r0, 0x3c
    blt     _80026510
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002651c
_80026510:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002651c:
    sth	r0, 0x48(r30)
    lwz	r4, 0x28(r30)
    lwz	r0, 0x24(r30)
    lwz	r3, 0xc(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026544
    li	r0, 0
    b       _80026564
_80026544:
    cmpwi	r0, 0x3c
    blt     _80026558
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026564
_80026558:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026564:
    sth	r0, 0x4c(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0xc(r30)
    addi	r3, r3, -0x1e
    add	r3, r0, r3
    cmpwi	r3, -0x388
    bgt     _80026588
    li	r0, 0
    b       _800265a8
_80026588:
    cmpwi	r3, 0x3c
    blt     _8002659c
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800265a8
_8002659c:
    slwi	r0, r3, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800265a8:
    sth	r0, 0x50(r30)
    b       _8002669c
_800265b0:
    lwz	r3, 0x20(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x28(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800265dc
    li	r0, 0
    b       _800265fc
_800265dc:
    cmpwi	r0, 0x3c
    blt     _800265f0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800265fc
_800265f0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800265fc:
    sth	r0, 0x48(r30)
    lwz	r3, 0x24(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x28(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _8002662c
    li	r0, 0
    b       _8002664c
_8002662c:
    cmpwi	r0, 0x3c
    blt     _80026640
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002664c
_80026640:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002664c:
    sth	r0, 0x4c(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x1c(r30)
    add	r3, r0, r3
    addi	r0, r3, -0x1e
    add	r0, r4, r0
    cmpwi	r0, -0x388
    bgt     _80026678
    li	r0, 0
    b       _80026698
_80026678:
    cmpwi	r0, 0x3c
    blt     _8002668c
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026698
_8002668c:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026698:
    sth	r0, 0x50(r30)
_8002669c:
    lwz	r0, 4(r30)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    beq     _80026780
    lwz	r4, 0x28(r30)
    lwz	r0, 0x20(r30)
    lwz	r3, 0x10(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800266cc
    li	r0, 0
    b       _800266ec
_800266cc:
    cmpwi	r0, 0x3c
    blt     _800266e0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800266ec
_800266e0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800266ec:
    sth	r0, 0x54(r30)
    lwz	r4, 0x28(r30)
    lwz	r0, 0x24(r30)
    lwz	r3, 0x10(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026714
    li	r0, 0
    b       _80026734
_80026714:
    cmpwi	r0, 0x3c
    blt     _80026728
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026734
_80026728:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026734:
    sth	r0, 0x58(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0x10(r30)
    addi	r3, r3, -0x1e
    add	r3, r0, r3
    cmpwi	r3, -0x388
    bgt     _80026758
    li	r0, 0
    b       _80026778
_80026758:
    cmpwi	r3, 0x3c
    blt     _8002676c
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026778
_8002676c:
    slwi	r0, r3, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026778:
    sth	r0, 0x5c(r30)
    b       _80026c04
_80026780:
    lwz	r3, 0x20(r30)
    lwz	r0, 0x10(r30)
    lwz	r4, 0x28(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800267ac
    li	r0, 0
    b       _800267cc
_800267ac:
    cmpwi	r0, 0x3c
    blt     _800267c0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800267cc
_800267c0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800267cc:
    sth	r0, 0x54(r30)
    lwz	r3, 0x24(r30)
    lwz	r0, 0x10(r30)
    lwz	r4, 0x28(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800267fc
    li	r0, 0
    b       _8002681c
_800267fc:
    cmpwi	r0, 0x3c
    blt     _80026810
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002681c
_80026810:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002681c:
    sth	r0, 0x58(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 0x10(r30)
    lwz	r4, 0x1c(r30)
    add	r3, r0, r3
    addi	r0, r3, -0x1e
    add	r0, r4, r0
    cmpwi	r0, -0x388
    bgt     _80026848
    li	r0, 0
    b       _80026868
_80026848:
    cmpwi	r0, 0x3c
    blt     _8002685c
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026868
_8002685c:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026868:
    sth	r0, 0x5c(r30)
    b       _80026c04
_80026870:
    lwz	r4, 0x28(r30)
    lwz	r0, 0x20(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026894
    li	r0, 0
    b       _800268b4
_80026894:
    cmpwi	r0, 0x3c
    blt     _800268a8
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800268b4
_800268a8:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800268b4:
    sth	r0, 0x3c(r30)
    lwz	r4, 0x28(r30)
    lwz	r0, 0x24(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800268dc
    li	r0, 0
    b       _800268fc
_800268dc:
    cmpwi	r0, 0x3c
    blt     _800268f0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800268fc
_800268f0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800268fc:
    sth	r0, 0x40(r30)
    lwz	r4, 0x2c(r30)
    lwz	r0, 0x30(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026924
    li	r0, 0
    b       _80026944
_80026924:
    cmpwi	r0, 0x3c
    blt     _80026938
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026944
_80026938:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026944:
    sth	r0, 0x54(r30)
    lwz	r4, 0x2c(r30)
    lwz	r0, 0x34(r30)
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _8002696c
    li	r0, 0
    b       _8002698c
_8002696c:
    cmpwi	r0, 0x3c
    blt     _80026980
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _8002698c
_80026980:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_8002698c:
    sth	r0, 0x58(r30)
    lwz	r0, 4(r30)
    clrlwi.	r0, r0, 0x1f
    beq     _80026ac0
    lwz	r4, 0x28(r30)
    lwz	r0, 0x20(r30)
    lwz	r3, 0xc(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _800269c0
    li	r0, 0
    b       _800269e0
_800269c0:
    cmpwi	r0, 0x3c
    blt     _800269d4
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _800269e0
_800269d4:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_800269e0:
    sth	r0, 0x48(r30)
    lwz	r4, 0x28(r30)
    lwz	r0, 0x24(r30)
    lwz	r3, 0xc(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026a08
    li	r0, 0
    b       _80026a28
_80026a08:
    cmpwi	r0, 0x3c
    blt     _80026a1c
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026a28
_80026a1c:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026a28:
    sth	r0, 0x4c(r30)
    lwz	r4, 0x2c(r30)
    lwz	r0, 0x30(r30)
    lwz	r3, 0xc(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026a50
    li	r0, 0
    b       _80026a70
_80026a50:
    cmpwi	r0, 0x3c
    blt     _80026a64
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026a70
_80026a64:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026a70:
    sth	r0, 0x50(r30)
    lwz	r4, 0x2c(r30)
    lwz	r0, 0x34(r30)
    lwz	r3, 0xc(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026a98
    li	r0, 0
    b       _80026ab8
_80026a98:
    cmpwi	r0, 0x3c
    blt     _80026aac
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026ab8
_80026aac:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026ab8:
    sth	r0, 0x5c(r30)
    b       _80026c00
_80026ac0:
    lwz	r3, 0x20(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x28(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026aec
    li	r0, 0
    b       _80026b0c
_80026aec:
    cmpwi	r0, 0x3c
    blt     _80026b00
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026b0c
_80026b00:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026b0c:
    sth	r0, 0x48(r30)
    lwz	r3, 0x24(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x28(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026b3c
    li	r0, 0
    b       _80026b5c
_80026b3c:
    cmpwi	r0, 0x3c
    blt     _80026b50
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026b5c
_80026b50:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026b5c:
    sth	r0, 0x4c(r30)
    lwz	r3, 0x30(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x2c(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026b8c
    li	r0, 0
    b       _80026bac
_80026b8c:
    cmpwi	r0, 0x3c
    blt     _80026ba0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026bac
_80026ba0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026bac:
    sth	r0, 0x50(r30)
    lwz	r3, 0x34(r30)
    lwz	r0, 0xc(r30)
    lwz	r4, 0x2c(r30)
    add	r0, r0, r3
    lwz	r3, 0x1c(r30)
    add	r0, r0, r4
    add	r0, r3, r0
    cmpwi	r0, -0x388
    bgt     _80026bdc
    li	r0, 0
    b       _80026bfc
_80026bdc:
    cmpwi	r0, 0x3c
    blt     _80026bf0
    lis	r3, 1
    addi	r0, r3, -0x9c
    b       _80026bfc
_80026bf0:
    slwi	r0, r0, 1
    add	r3, r31, r0
    lhz	r0, 0x710(r3)
_80026bfc:
    sth	r0, 0x5c(r30)
_80026c00:
    ori	r29, r29, 0x4000
_80026c04:
    bl      OSDisableInterrupts
    lhz	r4, 0x38(r30)
    li	r0, 0
    sth	r4, 0x19c(r28)
    addi	r4, r28, 0x14a
    addi	r4, r4, 2
    sth	r0, 0x19e(r28)
    lhz	r0, 0x3c(r30)
    cmplwi	r0, 0
    sth	r0, 0x14a(r28)
    beq     _80026c34
    ori	r29, r29, 1
_80026c34:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x40(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026c54
    ori	r29, r29, 2
_80026c54:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x48(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026c74
    ori	r29, r29, 0x10
_80026c74:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x4c(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026c94
    ori	r29, r29, 0x20
_80026c94:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x54(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026cb4
    ori	r29, r29, 0x200
_80026cb4:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x58(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026cd4
    ori	r29, r29, 0x400
_80026cd4:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x5c(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026cf4
    ori	r29, r29, 0x1000
_80026cf4:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x44(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026d14
    ori	r29, r29, 4
_80026d14:
    li	r0, 0
    sth	r0, 0(r4)
    lhz	r0, 0x50(r30)
    cmplwi	r0, 0
    sth	r0, 2(r4)
    addi	r4, r4, 4
    beq     _80026d34
    ori	r29, r29, 0x80
_80026d34:
    li	r0, 0
    sth	r0, 0(r4)
    sth	r29, 0x144(r28)
    lwz	r0, 0x1c(r28)
    ori	r0, r0, 0x212
    stw	r0, 0x1c(r28)
    bl      OSRestoreInterrupts
    lwz	r0, 0xec(r1)
    lwz	r31, 0xe4(r1)
    lwz	r30, 0xe0(r1)
    lwz	r29, 0xdc(r1)
    lwz	r28, 0xd8(r1)
    addi	r1, r1, 0xe8
    mtlr	r0
    blr	
}

// provenance: fzero-gx:src/game/axmix_80025504.c:1831 axmix_device_ctrl_clear
void axmix_device_ctrl_clear(register void *voice)
{
    unsigned int index;
    index = *(unsigned int *)((unsigned char *)voice + 0x18);
    *(unsigned int *)(lbl_80176160 + index * 0x60) = 0;
}

asm void axmix_set_voice_param_08(void)
{
    nofralloc
    lwz	r5, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r5, 0x60
    add	r3, r0, r3
    stw	r4, 8(r3)
    lwz	r0, 4(r3)
    oris	r0, r0, 0x1000
    stw	r0, 4(r3)
    blr	
}

asm void fn_80026DB8(void)
{
    nofralloc
    lwz	r4, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r4, 0x60
    add	r3, r0, r3
    lwz	r3, 8(r3)
    blr	
}

asm void axmix_voice_clear_flags_and_request_update(void)
{
    nofralloc
    lwz	r4, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r4, 0x60
    add	r3, r0, r3
    lwz	r0, 4(r3)
    rlwinm	r0, r0, 0, 0, 0x1e
    stw	r0, 4(r3)
    lwz	r0, 4(r3)
    oris	r0, r0, 0x4000
    stw	r0, 4(r3)
    blr	
}

asm void fn_80026E04(void)
{
    nofralloc
    lwz	r4, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r4, 0x60
    add	r3, r0, r3
    lwz	r0, 4(r3)
    oris	r0, r0, 0x4000
    ori	r0, r0, 1
    stw	r0, 4(r3)
    blr	
}

asm void fn_80026E2C(void)
{
    nofralloc
    lwz	r5, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r5, 0x60
    add	r3, r0, r3
    stw	r4, 0xc(r3)
    lwz	r0, 4(r3)
    oris	r0, r0, 0x4000
    stw	r0, 4(r3)
    blr	
}

asm void fn_80026E54(void)
{
    nofralloc
    lwz	r4, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r4, 0x60
    add	r3, r0, r3
    lwz	r0, 4(r3)
    rlwinm	r0, r0, 0, 0x1f, 0x1d
    stw	r0, 4(r3)
    lwz	r0, 4(r3)
    oris	r0, r0, 0x4000
    stw	r0, 4(r3)
    blr	
}

asm void fn_80026E84(void)
{
    nofralloc
    lwz	r4, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r4, 0x60
    add	r3, r0, r3
    lwz	r0, 4(r3)
    oris	r0, r0, 0x4000
    ori	r0, r0, 2
    stw	r0, 4(r3)
    blr	
}

asm void fn_80026EAC(void)
{
    nofralloc
    lwz	r0, lbl_801A6B88
    cmplwi	r0, 3
    beqlr	
    lwz	r5, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r5, 0x60
    add	r3, r0, r3
    stw	r4, 0x10(r3)
    lwz	r0, 4(r3)
    oris	r0, r0, 0x4000
    stw	r0, 4(r3)
    blr	
}

#pragma pop
