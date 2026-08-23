typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int BOOL;
typedef signed long long s64;

#define NULL ((void*) 0)

typedef void (*ARQCallback)(void);

typedef struct OSContext {
    u64 fields[0x59];
} OSContext;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(const char* version);
extern void __OSSetInterruptHandler(s32 interrupt, void* handler);
extern void __OSUnmaskInterrupts(u32 mask);
extern void DCInvalidateRange(void* addr, u32 length);
extern void DCFlushRange(void* addr, u32 length);
extern void PPCSync(void);
extern void memset(void* dst, int val, u32 n);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);

asm void __ARChecksize(void);

#pragma push
#pragma force_active on

asm ARQCallback ARRegisterDMACallback(register ARQCallback callback)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    lwz	r31, -0x79e0(r13)
    bl      OSDisableInterrupts
    stw	r30, -0x79e0(r13)
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm u32 AIGetDSPInterruptEnable(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      OSDisableInterrupts
    lis	r4, -0x3400
    lhz	r0, 0x500a(r4)
    rlwinm	r31, r0, 0, 0x16, 0x16
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void ARStartDMA(register u32 dir, register u32 memaddr, register u32 aramaddr, register u32 length)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r6, 0
    stw	r30, 0x20(r1)
    addi	r30, r5, 0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    stw	r28, 0x18(r1)
    addi	r28, r4, 0
    bl      OSDisableInterrupts
    lis	r6, -0x3400
    lhz	r0, 0x5020(r6)
    addi	r8, r6, 0x5000
    addi	r9, r6, 0x5000
    rlwinm	r4, r0, 0, 0, 0x15
    srwi	r0, r28, 0x10
    or	r0, r4, r0
    sth	r0, 0x5020(r6)
    clrlwi	r0, r28, 0x10
    addi	r4, r6, 0x5000
    lhz	r5, 0x5022(r6)
    rlwinm	r5, r5, 0, 0x1b, 0xf
    or	r0, r5, r0
    sth	r0, 0x5022(r6)
    addi	r5, r6, 0x5000
    srwi	r0, r30, 0x10
    lhz	r6, 0x5024(r6)
    rlwinm	r6, r6, 0, 0, 0x15
    or	r0, r6, r0
    sth	r0, 0x24(r8)
    clrlwi	r0, r30, 0x10
    lhz	r6, 0x26(r9)
    rlwinm	r6, r6, 0, 0x1b, 0xf
    or	r0, r6, r0
    sth	r0, 0x26(r9)
    srwi	r6, r31, 0x10
    clrlwi	r0, r31, 0x10
    lhz	r7, 0x28(r4)
    rlwinm	r7, r7, 0, 0x11, 0xf
    rlwimi	r7, r29, 0xf, 0, 0x10
    sth	r7, 0x28(r4)
    lhz	r7, 0x28(r4)
    rlwinm	r7, r7, 0, 0, 0x15
    or	r6, r7, r6
    sth	r6, 0x28(r4)
    lhz	r4, 0x2a(r5)
    rlwinm	r4, r4, 0, 0x1b, 0xf
    or	r0, r4, r0
    sth	r0, 0x2a(r5)
    bl      OSRestoreInterrupts
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    lwz	r28, 0x18(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm u32 fn_8001E954(register u32 length)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lwz	r31, -0x79d0(r13)
    lwz	r4, -0x79c8(r13)
    add	r0, r31, r30
    stw	r0, -0x79d0(r13)
    stw	r30, 0(r4)
    lwz	r5, -0x79c8(r13)
    lwz	r4, -0x79cc(r13)
    addi	r5, r5, 4
    addi	r0, r4, -1
    stw	r5, -0x79c8(r13)
    stw	r0, -0x79cc(r13)
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm u32 fn_8001E9BC(register void* out)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lwz	r4, -0x79c8(r13)
    cmplwi	r31, 0
    addi	r0, r4, -4
    stw	r0, -0x79c8(r13)
    beq     _8001e9f4
    lwz	r4, -0x79c8(r13)
    lwz	r0, 0(r4)
    stw	r0, 0(r31)
_8001e9f4:
    lwz	r5, -0x79c8(r13)
    lwz	r4, -0x79cc(r13)
    lwz	r6, 0(r5)
    addi	r0, r4, 1
    lwz	r5, -0x79d0(r13)
    stw	r0, -0x79cc(r13)
    subf	r0, r6, r5
    stw	r0, -0x79d0(r13)
    bl      OSRestoreInterrupts
    lwz	r3, -0x79d0(r13)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm u32 ARInit(register u32* stack_index_addr, register u32 num_entries)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    lwz	r0, -0x79c4(r13)
    cmpwi	r0, 1
    bne     _8001ea64
    li	r3, 0x4000
    b       _8001ead8
_8001ea64:
    lwz	r3, -0x7ee8(r13)
    bl      OSRegisterVersion
    bl      OSDisableInterrupts
    li	r0, 0
    lis     r4, __ARHandler@ha
    stw	r0, -0x79e0(r13)
    addi	r31, r3, 0
    addi    r4, r4, __ARHandler@l
    li	r3, 6
    bl      __OSSetInterruptHandler
    lis	r3, 0x200
    bl      __OSUnmaskInterrupts
    li	r0, 0x4000
    stw	r30, -0x79cc(r13)
    lis	r3, -0x3400
    stw	r0, -0x79d0(r13)
    addi	r4, r3, 0x5000
    stw	r29, -0x79c8(r13)
    lhz	r0, 0x1a(r4)
    lhz	r3, 0x501a(r3)
    rlwinm	r0, r0, 0, 0, 0x17
    rlwimi	r0, r3, 0, 0x18, 0x1f
    sth	r0, 0x1a(r4)
    bl      __ARChecksize
    li	r0, 1
    stw	r0, -0x79c4(r13)
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r3, -0x79d0(r13)
_8001ead8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __ARHandler(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr	r0
    lis	r3, -0x3400
    stw	r0, 4(r1)
    addi	r3, r3, 0x5000
    li	r0, -0x89
    stwu	r1, -0x2e0(r1)
    stw	r31, 0x2dc(r1)
    addi	r31, r4, 0
    lhz	r5, 0xa(r3)
    and	r0, r5, r0
    ori	r0, r0, 0x20
    sth	r0, 0xa(r3)
    addi	r3, r1, 0x10
    bl      OSClearContext
    addi	r3, r1, 0x10
    bl      OSSetCurrentContext
    lwz	r12, -0x79e0(r13)
    cmplwi	r12, 0
    beq     _8001eb48
    mtlr	r12
    blrl	
_8001eb48:
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

asm void __ARChecksize(void)
{
    nofralloc
    mflr	r0
    lis	r3, -0x3400
    stw	r0, 4(r1)
    addi	r3, r3, 0x5000
    stwu	r1, -0x2c0(r1)
    stmw	r14, 0x278(r1)
_8001eb84:
    lhz	r0, 0x16(r3)
    clrlwi.	r0, r0, 0x1f
    beq     _8001eb84
    lis	r23, -0x3400
    addi	r0, r23, 0x5000
    stw	r0, 0x248(r1)
    lis	r3, 0x100
    addi	r0, r1, 0x1f3
    stw	r3, -0x79d8(r13)
    lis	r5, -0x2152
    lwz	r4, 0x248(r1)
    rlwinm	r22, r0, 0, 0, 0x1a
    addi	r0, r1, 0x1b3
    lhz	r4, 0x12(r4)
    addi	r7, r1, 0xb3
    rlwinm	r7, r7, 0, 0, 0x1a
    rlwinm	r4, r4, 0, 0, 0x19
    stw	r7, 0x21c(r1)
    ori	r6, r4, 0x23
    lwz	r4, 0x248(r1)
    addi	r10, r1, 0x173
    sth	r6, 0x12(r4)
    addi	r5, r5, -0x4111
    lis	r4, -0x452f
    rlwinm	r21, r0, 0, 0, 0x1a
    stw	r5, 0(r22)
    addi	r0, r4, -0x4530
    stw	r0, 0(r21)
    addi	r4, r1, 0x33
    addi	r6, r1, 0x73
    stw	r5, 4(r22)
    rlwinm	r4, r4, 0, 0, 0x1a
    rlwinm	r6, r6, 0, 0, 0x1a
    stw	r0, 4(r21)
    addi	r9, r1, 0x133
    addi	r8, r1, 0xf3
    stw	r5, 8(r22)
    addi	r19, r3, 0
    addi	r3, r22, 0
    stw	r0, 8(r21)
    rlwinm	r24, r10, 0, 0, 0x1a
    rlwinm	r28, r9, 0, 0, 0x1a
    stw	r5, 0xc(r22)
    rlwinm	r20, r8, 0, 0, 0x1a
    stw	r0, 0xc(r21)
    stw	r5, 0x10(r22)
    stw	r0, 0x10(r21)
    stw	r5, 0x14(r22)
    stw	r0, 0x14(r21)
    stw	r5, 0x18(r22)
    stw	r0, 0x18(r21)
    stw	r5, 0x1c(r22)
    lwz	r5, 0x248(r1)
    stw	r4, 0x214(r1)
    li	r4, 3
    addi	r5, r5, 0x12
    sth	r4, 0x270(r1)
    li	r4, 0x20
    stw	r6, 0x218(r1)
    stw	r0, 0x1c(r21)
    stw	r5, 0x248(r1)
    bl      DCFlushRange
    addi	r3, r21, 0
    li	r4, 0x20
    bl      DCFlushRange
    li	r0, 0
    stw	r0, -0x79d4(r13)
    addi	r3, r28, 0
    li	r4, 0x20
    bl      DCInvalidateRange
    srwi	r3, r28, 0x10
    lhz	r0, 0x5020(r23)
    stw	r3, 0x23c(r1)
    addi	r25, r23, 0x5000
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x23c(r1)
    addi	r26, r23, 0x5000
    srwi	r17, r19, 0x10
    or	r0, r3, r0
    sthu	r0, 0x20(r25)
    clrlwi	r3, r28, 0x10
    addi	r27, r23, 0x5000
    lhz	r0, 0x5022(r23)
    clrlwi	r18, r19, 0x10
    stw	r3, 0x24c(r1)
    addi	r28, r23, 0x5000
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x24c(r1)
    addi	r30, r23, 0x5000
    addi	r29, r23, 0x5000
    or	r0, r3, r0
    sthu	r0, 0x22(r26)
    lhz	r0, 0x5024(r23)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sthu	r0, 0x24(r27)
    lhz	r0, 0x5026(r23)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sthu	r0, 0x26(r28)
    lhz	r0, 0x5028(r23)
    ori	r0, r0, 0x8000
    sth	r0, 0x5028(r23)
    lhz	r0, 0x5028(r23)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sthu	r0, 0x28(r30)
    lhz	r0, 0x502a(r23)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sthu	r0, 0x2a(r29)
_8001ed40:
    addi	r31, r23, 0x5000
    lhzu	r0, 0xa(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001ed40
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    srwi	r0, r22, 0x10
    lhz	r3, 0(r25)
    stw	r0, 0x244(r1)
    rlwinm	r3, r3, 0, 0, 0x15
    lwz	r0, 0x244(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    clrlwi	r0, r22, 0x10
    stw	r0, 0x250(r1)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x250(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001edec:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001edec
    lhz	r0, 0(r31)
    li	r4, -0x89
    addi	r3, r24, 0
    and	r0, r0, r4
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    li	r4, 0
    li	r5, 0x20
    bl      memset
    addi	r3, r24, 0
    li	r4, 0x20
    bl      DCFlushRange
    srwi	r0, r24, 0x10
    lhz	r3, 0(r25)
    stw	r0, 0x240(r1)
    rlwinm	r3, r3, 0, 0, 0x15
    lwz	r0, 0x240(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    clrlwi	r0, r24, 0x10
    stw	r0, 0x254(r1)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x254(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001eeac:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001eeac
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r3, 0(r24)
    lwz	r0, 0(r22)
    cmplw	r3, r0
    bne     _80020340
    addi	r3, r20, 0
    li	r4, 0x20
    bl      DCInvalidateRange
    srwi	r0, r20, 0x10
    lhz	r4, 0(r25)
    stw	r0, 0x234(r1)
    addis	r3, r19, 0x20
    rlwinm	r4, r4, 0, 0, 0x15
    lwz	r0, 0x234(r1)
    srwi	r16, r3, 0x10
    clrlwi	r23, r3, 0x10
    or	r0, r4, r0
    sth	r0, 0(r25)
    clrlwi	r0, r20, 0x10
    stw	r0, 0x258(r1)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x258(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r16
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r23
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001ef7c:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001ef7c
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r3, 0x21c(r1)
    li	r4, 0x20
    bl      DCInvalidateRange
    lwz	r0, 0x21c(r1)
    addis	r3, r19, 0x100
    lhz	r4, 0(r25)
    srwi	r14, r3, 0x10
    srwi	r0, r0, 0x10
    stw	r0, 0x22c(r1)
    rlwinm	r4, r4, 0, 0, 0x15
    clrlwi	r15, r3, 0x10
    lwz	r0, 0x22c(r1)
    or	r0, r4, r0
    sth	r0, 0(r25)
    lwz	r0, 0x21c(r1)
    clrlwi	r0, r0, 0x10
    stw	r0, 0x25c(r1)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x25c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r14
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r15
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f044:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f044
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r3, 0x218(r1)
    li	r4, 0x20
    bl      DCInvalidateRange
    lwz	r0, 0x218(r1)
    addi	r3, r19, 0x200
    lhz	r4, 0(r25)
    srwi	r0, r0, 0x10
    stw	r0, 0x224(r1)
    rlwinm	r4, r4, 0, 0, 0x15
    lwz	r0, 0x224(r1)
    or	r0, r4, r0
    sth	r0, 0(r25)
    srwi	r0, r3, 0x10
    clrlwi	r3, r3, 0x10
    stw	r0, 0x230(r1)
    lwz	r0, 0x218(r1)
    stw	r3, 0x264(r1)
    clrlwi	r0, r0, 0x10
    stw	r0, 0x260(r1)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x260(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x230(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x264(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f11c:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f11c
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r3, 0x214(r1)
    li	r4, 0x20
    bl      DCInvalidateRange
    lwz	r0, 0x214(r1)
    addis	r3, r19, 0x40
    lhz	r4, 0(r25)
    srwi	r0, r0, 0x10
    stw	r0, 0x220(r1)
    rlwinm	r4, r4, 0, 0, 0x15
    lwz	r0, 0x220(r1)
    or	r0, r4, r0
    sth	r0, 0(r25)
    srwi	r0, r3, 0x10
    clrlwi	r3, r3, 0x10
    stw	r0, 0x228(r1)
    lwz	r0, 0x214(r1)
    stw	r3, 0x26c(r1)
    clrlwi	r0, r0, 0x10
    stw	r0, 0x268(r1)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x268(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x228(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x26c(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f1f4:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f1f4
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    srwi	r0, r21, 0x10
    lhz	r3, 0(r25)
    stw	r0, 0x238(r1)
    clrlwi	r20, r21, 0x10
    rlwinm	r3, r3, 0, 0, 0x15
    lwz	r0, 0x238(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r20
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r16
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r23
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f294:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f294
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x244(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x250(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f328:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f328
    lhz	r0, 0(r31)
    li	r4, -0x89
    addi	r3, r24, 0
    and	r0, r0, r4
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    li	r4, 0
    li	r5, 0x20
    bl      memset
    addi	r3, r24, 0
    li	r4, 0x20
    bl      DCFlushRange
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x240(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x254(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r16
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r23
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f3d8:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f3d8
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r3, 0(r24)
    lwz	r0, 0(r22)
    cmplw	r3, r0
    bne     _8001f4b0
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x23c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x24c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f480:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f480
    lhz	r4, 0(r31)
    li	r3, -0x89
    lis	r0, 0x20
    and	r3, r4, r3
    ori	r3, r3, 0x20
    sth	r3, 0(r31)
    addis	r19, r19, 0x20
    stw	r0, -0x79d4(r13)
    b       _80020324
_8001f4b0:
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x238(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r20
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r14
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r15
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f520:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f520
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x244(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x250(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f5b4:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f5b4
    lhz	r0, 0(r31)
    li	r4, -0x89
    addi	r3, r24, 0
    and	r0, r0, r4
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    li	r4, 0
    li	r5, 0x20
    bl      memset
    addi	r3, r24, 0
    li	r4, 0x20
    bl      DCFlushRange
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x240(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x254(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r14
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r15
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f664:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f664
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r3, 0(r24)
    lwz	r0, 0(r22)
    cmplw	r3, r0
    bne     _8001f7dc
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x23c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x24c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f70c:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f70c
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x234(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x258(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r16
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r23
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f7a0:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f7a0
    lhz	r4, 0(r31)
    li	r0, -0x89
    lis	r3, 0x40
    and	r0, r4, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    addis	r19, r19, 0x40
    lhz	r0, 0x270(r1)
    stw	r3, -0x79d4(r13)
    ori	r0, r0, 8
    sth	r0, 0x270(r1)
    b       _80020324
_8001f7dc:
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x238(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r20
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x230(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x264(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f854:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f854
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x244(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x250(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f8e8:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f8e8
    lhz	r0, 0(r31)
    li	r4, -0x89
    addi	r3, r24, 0
    and	r0, r0, r4
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    li	r4, 0
    li	r5, 0x20
    bl      memset
    addi	r3, r24, 0
    li	r4, 0x20
    bl      DCFlushRange
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x240(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x254(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x230(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x264(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001f9a0:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001f9a0
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r3, 0(r24)
    lwz	r0, 0(r22)
    cmplw	r3, r0
    bne     _8001fbac
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x23c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x24c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001fa48:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001fa48
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x234(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x258(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r16
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r23
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001fadc:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001fadc
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x22c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x25c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r14
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r15
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001fb70:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001fb70
    lhz	r4, 0(r31)
    li	r0, -0x89
    lis	r3, 0x80
    and	r0, r4, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    addis	r19, r19, 0x80
    lhz	r0, 0x270(r1)
    stw	r3, -0x79d4(r13)
    ori	r0, r0, 0x10
    sth	r0, 0x270(r1)
    b       _80020324
_8001fbac:
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x238(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r20
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x228(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x26c(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001fc24:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001fc24
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x244(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x250(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001fcb8:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001fcb8
    lhz	r0, 0(r31)
    li	r4, -0x89
    addi	r3, r24, 0
    and	r0, r0, r4
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    li	r4, 0
    li	r5, 0x20
    bl      memset
    addi	r3, r24, 0
    li	r4, 0x20
    bl      DCFlushRange
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x240(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x254(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x228(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x26c(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    ori	r0, r0, 0x8000
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001fd70:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001fd70
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    bl      PPCSync
    lwz	r0, 0(r24)
    lwz	r3, 0(r22)
    cmplw	r0, r3
    bne     _80020018
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x23c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x24c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001fe18:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001fe18
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x234(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x258(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r16
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r23
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001feac:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001feac
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x22c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x25c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r14
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r15
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001ff40:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001ff40
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x224(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x260(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x230(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x264(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8001ffdc:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8001ffdc
    lhz	r4, 0(r31)
    li	r0, -0x89
    lis	r3, 0x100
    and	r0, r4, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    addis	r19, r19, 0x100
    lhz	r0, 0x270(r1)
    stw	r3, -0x79d4(r13)
    ori	r0, r0, 0x18
    sth	r0, 0x270(r1)
    b       _80020324
_80020018:
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x23c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x24c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r17
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r18
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_8002008c:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8002008c
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x234(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x258(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r16
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r23
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_80020120:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _80020120
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x22c(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x25c(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r0, r0, 0, 0, 0x15
    or	r0, r0, r14
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    or	r0, r0, r15
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_800201b4:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _800201b4
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x224(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x260(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x230(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x264(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_80020250:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _80020250
    lhz	r3, 0(r31)
    li	r0, -0x89
    and	r0, r3, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    lhz	r0, 0(r25)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x220(r1)
    or	r0, r3, r0
    sth	r0, 0(r25)
    lhz	r0, 0(r26)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x268(r1)
    or	r0, r3, r0
    sth	r0, 0(r26)
    lhz	r0, 0(r27)
    rlwinm	r3, r0, 0, 0, 0x15
    lwz	r0, 0x228(r1)
    or	r0, r3, r0
    sth	r0, 0(r27)
    lhz	r0, 0(r28)
    rlwinm	r3, r0, 0, 0x1b, 0xf
    lwz	r0, 0x26c(r1)
    or	r0, r3, r0
    sth	r0, 0(r28)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0(r30)
    lhz	r0, 0(r30)
    rlwinm	r0, r0, 0, 0, 0x15
    nop	
    sth	r0, 0(r30)
    lhz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1b, 0xf
    ori	r0, r0, 0x20
    sth	r0, 0(r29)
_800202ec:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _800202ec
    lhz	r4, 0(r31)
    li	r0, -0x89
    lis	r3, 0x200
    and	r0, r4, r0
    ori	r0, r0, 0x20
    sth	r0, 0(r31)
    addis	r19, r19, 0x200
    lhz	r0, 0x270(r1)
    stw	r3, -0x79d4(r13)
    ori	r0, r0, 0x20
    sth	r0, 0x270(r1)
_80020324:
    lwz	r3, 0x248(r1)
    lhz	r0, 0(r3)
    rlwinm	r3, r0, 0, 0, 0x19
    lhz	r0, 0x270(r1)
    or	r0, r3, r0
    lwz	r3, 0x248(r1)
    sth	r0, 0(r3)
_80020340:
    lis	r3, -0x4000
    stw	r19, 0xd0(r3)
    stw	r19, -0x79dc(r13)
    lwz	r0, 0x2c4(r1)
    lmw	r14, 0x278(r1)
    addi	r1, r1, 0x2c0
    mtlr	r0
    blr	
}

#pragma pop
