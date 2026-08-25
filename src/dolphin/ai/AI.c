typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;

#define NULL ((void*) 0)

typedef struct OSContext {
    u64 fields[0x59];
} OSContext;

extern unsigned char lbl_801A69B4[4];
extern unsigned char lbl_801A69B0[4];
extern unsigned char lbl_801A64D0[8];
extern unsigned char lbl_801A69BC[4];
extern unsigned char lbl_801A69C4[4];
extern unsigned char lbl_801A69CC[4];
extern unsigned char lbl_801A69DC[4];
extern unsigned char lbl_801A69D4[4];
extern unsigned char lbl_801A69B8[4];
extern unsigned char lbl_801A69C0[4];
extern unsigned char lbl_801A69C8[4];
extern unsigned char lbl_801A69D0[4];
extern unsigned char lbl_801A69D8[4];
extern unsigned char lbl_801A69A0[4];
extern unsigned char lbl_801A69A4[4];
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern s64 OSGetTime(void);
extern unsigned char __CallbackStack[4];
extern unsigned char __OldStack[4];

asm void __AICallbackStackSwitch(register void* callback);

// ---- orphan unit auto_01_8001E314_text: AIInit (0x8001E314, 0x16C) ----

extern void OSRegisterVersion(register void* version);
extern void AISetStreamSampleRate(register unsigned long rate);
extern void AISetDSPSampleRate(register unsigned long rate);
extern void __OSSetInterruptHandler(register int interrupt, register void* handler);
extern void __OSUnmaskInterrupts(register unsigned long mask);
asm void __AIDHandler(register s32 interrupt, register OSContext* context);
asm void __AISHandler(register s32 interrupt, register OSContext* context);

#pragma push
#pragma force_active on

// 0x8001E314 | size: 0x16C
asm void AIInit(register void* stack)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    addi    r30, r3, 0
    lwz	r0, lbl_801A69B0
    cmpwi   r0, 0x1
    beq     _8001E468
    lwz	r3, lbl_801A64D0
    bl      OSRegisterVersion
    lis     r3, 0x8000
    lwz     r0, 0xf8(r3)
    lis     r3, 0x431c
    lis     r4, 0x1
    srwi    r0, r0, 2
    subi    r3, r3, 0x217d
    mulhwu  r0, r3, r0
    srwi    r9, r0, 15
    subi    r5, r4, 0x5bd8
    subi    r3, r4, 0x5bf0
    subi    r0, r4, 0x9e8
    lis     r4, 0x1062
    mullw   r7, r9, r5
    addi    r10, r4, 0x4dd3
    mullw   r5, r9, r3
    mullw   r4, r9, r0
    mulli   r8, r9, 0x7b24
    mulli   r3, r9, 0xbb8
    mulhwu  r8, r10, r8
    mulhwu  r7, r10, r7
    mulhwu  r5, r10, r5
    mulhwu  r4, r10, r4
    mulhwu  r3, r10, r3
    srwi    r8, r8, 9
    srwi    r7, r7, 9
    stw	r8, lbl_801A69BC
    srwi    r5, r5, 9
    srwi    r4, r4, 9
    stw	r7, lbl_801A69C4
    li      r31, 0x0
    srwi    r3, r3, 9
    stw	r5, lbl_801A69CC
    lis     r6, 0xcc00
    stw	r3, lbl_801A69DC
    li      r3, 0x1
    lwz     r0, 0x6c00(r6)
    stw	r4, lbl_801A69D4
    rlwinm  r0, r0, 0, 27, 25
    ori     r0, r0, 0x20
    stw	r31, lbl_801A69B8
    stw	r31, lbl_801A69C0
    stw	r31, lbl_801A69C8
    stw	r31, lbl_801A69D0
    stw	r31, lbl_801A69D8
    lwz     r5, 0x6c04(r6)
    stw     r0, 0x6c00(r6)
    rlwinm  r0, r5, 0, 24, 15
    nop
    stw     r0, 0x6c04(r6)
    lwz     r0, 0x6c04(r6)
    clrrwi  r0, r0, 8
    nop
    stw     r0, 0x6c04(r6)
    stw     r31, 0x6c0c(r6)
    bl      AISetStreamSampleRate
    li      r3, 0x0
    bl      AISetDSPSampleRate
    lis     r3, __AIDHandler@ha
    stw	r31, lbl_801A69A0
    addi    r4, r3, __AIDHandler@l
    stw	r31, lbl_801A69A4
    li      r3, 0x5
    stw	r30, __CallbackStack
    bl      __OSSetInterruptHandler
    lis     r3, 0x400
    bl      __OSUnmaskInterrupts
    lis     r3, __AISHandler@ha
    addi    r4, r3, __AISHandler@l
    li      r3, 0x8
    bl      __OSSetInterruptHandler
    lis     r3, 0x80
    bl      __OSUnmaskInterrupts
    li      r0, 0x1
    stw	r0, lbl_801A69B0
_8001E468:
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

#pragma pop

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
    lwz	r12, lbl_801A69A0
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
    lwz	r3, lbl_801A69A4
    cmplwi	r3, 0
    beq     _8001e584
    lwz	r0, lbl_801A69B4
    cmpwi	r0, 0
    bne     _8001e584
    lwz	r0, __CallbackStack
    li	r4, 1
    stw	r4, lbl_801A69B4
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
    stw	r0, lbl_801A69B4
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
    lis     r5, __OldStack@ha
    addi	r5, r5, __OldStack@l
    stw	r1, 0(r5)
    lis     r5, __CallbackStack@ha
    addi	r5, r5, __CallbackStack@l
    lwz	r1, 0(r5)
    addi	r1, r1, -8
    mtlr	r31
    blrl	
    lis     r5, __OldStack@ha
    addi	r5, r5, __OldStack@l
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
    lwz	r12, lbl_801A69BC
    lwz	r5, 0x6c00(r31)
    subfe	r7, r27, r3
    lwz	r10, lbl_801A69DC
    xoris	r7, r7, 0x8000
    rlwinm	r5, r5, 0, 0x1f, 0x1d
    lwz	r11, lbl_801A69B8
    subfc	r6, r10, r12
    lwz	r9, lbl_801A69D8
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
    lwz	r29, lbl_801A69C8
    li	r0, 1
    lwz	r28, lbl_801A69CC
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
    lwz	r5, lbl_801A69C4
    lwz	r0, lbl_801A69C0
    subfc	r6, r10, r5
    subfe	r0, r9, r0
    xoris	r5, r0, 0x8000
    subfc	r0, r6, r8
    subfe	r5, r5, r7
    subfe	r5, r7, r7
    neg	r5, r5
    cmpwi	r5, 0
    beq     _8001e790
    lwz	r29, lbl_801A69D0
    li	r0, 1
    lwz	r28, lbl_801A69D4
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


