typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;

#define NULL ((void*) 0)

typedef struct OSContext {
    u64 fields[0x59];
} OSContext;

extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern s64 OSGetTime(void);
extern unsigned char lbl_801A69A8[4];
extern unsigned char lbl_801A69AC[4];

asm void __AICallbackStackSwitch(register void* callback);

#pragma push
#pragma force_active on

asm void __AISHandler(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x2e0(r1)
    stw	r31, 0x2dc(r1)
    lis	r31, -0x3400
    lwz	r0, 0x6c00(r31)
    addi	r3, r1, 0x10
    stw	r30, 0x2d8(r1)
    ori	r0, r0, 8
    stw	r0, 0x6c00(r31)
    addi	r30, r4, 0
    bl      OSClearContext
    addi	r3, r1, 0x10
    bl      OSSetCurrentContext
    lwz	r12, -0x7a20(r13)
    cmplwi	r12, 0
    beq     _8001e4d4
    addi	r3, r31, 0x6c00
    mtlr	r12
    lwz	r3, 8(r3)
    blrl	
_8001e4d4:
    addi	r3, r1, 0x10
    bl      OSClearContext
    mr	r3, r30
    bl      OSSetCurrentContext
    lwz	r0, 0x2e4(r1)
    lwz	r31, 0x2dc(r1)
    lwz	r30, 0x2d8(r1)
    addi	r1, r1, 0x2e0
    mtlr	r0
    blr	
}

asm void __AIDHandler(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr	r0
    lis	r3, -0x3400
    stw	r0, 4(r1)
    addi	r3, r3, 0x5000
    li	r0, -0xa1
    stwu	r1, -0x2e0(r1)
    stw	r31, 0x2dc(r1)
    addi	r31, r4, 0
    lhz	r5, 0xa(r3)
    and	r0, r5, r0
    ori	r0, r0, 8
    sth	r0, 0xa(r3)
    addi	r3, r1, 0x10
    bl      OSClearContext
    addi	r3, r1, 0x10
    bl      OSSetCurrentContext
    lwz	r3, -0x7a1c(r13)
    cmplwi	r3, 0
    beq     _8001e584
    lwz	r0, -0x7a0c(r13)
    cmpwi	r0, 0
    bne     _8001e584
    lwz	r0, -0x7a18(r13)
    li	r4, 1
    stw	r4, -0x7a0c(r13)
    cmplwi	r0, 0
    beq     _8001e570
    bl      __AICallbackStackSwitch
    b       _8001e57c
_8001e570:
    addi	r12, r3, 0
    mtlr	r12
    blrl	
_8001e57c:
    li	r0, 0
    stw	r0, -0x7a0c(r13)
_8001e584:
    addi	r3, r1, 0x10
    bl      OSClearContext
    mr	r3, r31
    bl      OSSetCurrentContext
    lwz	r0, 0x2e4(r1)
    lwz	r31, 0x2dc(r1)
    addi	r1, r1, 0x2e0
    mtlr	r0
    blr	
}

asm void __AICallbackStackSwitch(register void* callback)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    lis     r5, lbl_801A69AC@ha
    addi	r5, r5, lbl_801A69AC@l
    stw	r1, 0(r5)
    lis     r5, lbl_801A69A8@ha
    addi	r5, r5, lbl_801A69A8@l
    lwz	r1, 0(r5)
    addi	r1, r1, -8
    mtlr	r31
    blrl	
    lis     r5, lbl_801A69AC@ha
    addi	r5, r5, lbl_801A69AC@l
    lwz	r1, 0(r5)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __AI_SRC_INIT(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stmw	r26, 0x18(r1)
    li	r4, 0
    li	r3, 0
    li	r0, 0
    li	r28, 0
    li	r29, 0
    b       _8001e628
_8001e628:
    lis	r31, -0x3400
    b       _8001e630
_8001e630:
    b       _8001e794
_8001e634:
    lwz	r0, 0x6c00(r31)
    addi	r30, r31, 0x6c00
    addi	r30, r30, 8
    rlwinm	r0, r0, 0, 0x1b, 0x19
    ori	r0, r0, 0x20
    stw	r0, 0x6c00(r31)
    lwz	r0, 0x6c00(r31)
    rlwinm	r0, r0, 0, 0x1f, 0x1d
    stw	r0, 0x6c00(r31)
    lwz	r0, 0x6c00(r31)
    rlwinm	r0, r0, 0, 0, 0x1e
    ori	r0, r0, 1
    stw	r0, 0x6c00(r31)
    lwz	r3, 0(r30)
    b       _8001e670
_8001e670:
    b       _8001e674
_8001e674:
    lwz	r0, 0(r30)
    cmplw	r3, r0
    beq     _8001e674
    bl      OSGetTime
    lwz	r0, 0x6c00(r31)
    mr	r26, r4
    mr	r27, r3
    rlwinm	r0, r0, 0, 0x1f, 0x1d
    ori	r0, r0, 2
    stw	r0, 0x6c00(r31)
    lwz	r0, 0x6c00(r31)
    rlwinm	r0, r0, 0, 0, 0x1e
    ori	r0, r0, 1
    stw	r0, 0x6c00(r31)
    lwz	r3, 0(r30)
    b       _8001e6b4
_8001e6b4:
    b       _8001e6b8
_8001e6b8:
    lwz	r0, 0(r30)
    cmplw	r3, r0
    beq     _8001e6b8
    bl      OSGetTime
    subfc	r8, r26, r4
    lwz	r12, -0x7a04(r13)
    lwz	r5, 0x6c00(r31)
    subfe	r7, r27, r3
    lwz	r10, -0x79e4(r13)
    xoris	r7, r7, 0x8000
    rlwinm	r5, r5, 0, 0x1f, 0x1d
    lwz	r11, -0x7a08(r13)
    subfc	r6, r10, r12
    lwz	r9, -0x79e8(r13)
    stw	r5, 0x6c00(r31)
    subfe	r0, r9, r11
    xoris	r5, r0, 0x8000
    subfc	r0, r6, r8
    lwz	r0, 0x6c00(r31)
    subfe	r5, r5, r7
    subfe	r5, r7, r7
    neg	r5, r5
    rlwinm	r0, r0, 0, 0, 0x1e
    cmpwi	r5, 0
    stw	r0, 0x6c00(r31)
    beq     _8001e730
    lwz	r29, -0x79f8(r13)
    li	r0, 1
    lwz	r28, -0x79f4(r13)
    b       _8001e794
_8001e730:
    addc	r6, r12, r10
    adde	r0, r11, r9
    xoris	r5, r0, 0x8000
    subfc	r0, r6, r8
    subfe	r5, r5, r7
    subfe	r5, r7, r7
    neg	r5, r5
    cmpwi	r5, 0
    bne     _8001e790
    lwz	r5, -0x79fc(r13)
    lwz	r0, -0x7a00(r13)
    subfc	r6, r10, r5
    subfe	r0, r9, r0
    xoris	r5, r0, 0x8000
    subfc	r0, r6, r8
    subfe	r5, r5, r7
    subfe	r5, r7, r7
    neg	r5, r5
    cmpwi	r5, 0
    beq     _8001e790
    lwz	r29, -0x79f0(r13)
    li	r0, 1
    lwz	r28, -0x79ec(r13)
    b       _8001e794
_8001e790:
    li	r0, 0
_8001e794:
    cmplwi	r0, 0
    beq     _8001e634
    addc	r27, r4, r28
    adde	r26, r3, r29
    b       _8001e7a8
_8001e7a8:
    b       _8001e7ac
_8001e7ac:
    bl      OSGetTime
    xoris	r5, r3, 0x8000
    xoris	r3, r26, 0x8000
    subfc	r0, r27, r4
    subfe	r3, r3, r5
    subfe	r3, r5, r5
    neg	r3, r3
    cmpwi	r3, 0
    bne     _8001e7ac
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

#pragma pop
