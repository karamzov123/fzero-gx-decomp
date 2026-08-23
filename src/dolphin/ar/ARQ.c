typedef signed int s32;
typedef unsigned int u32;
typedef int BOOL;

typedef void (*ARQCallback)(void);
typedef struct ARQRequest ARQRequest;

extern void OSRegisterVersion(const char* version);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void ARStartDMA(register u32 dir, register u32 memaddr, register u32 aramaddr, register u32 length);
extern ARQCallback ARRegisterDMACallback(register ARQCallback callback);

#pragma push
#pragma force_active on

asm void __ARQServiceQueueLo(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r0, -0x79ac(r13)
    cmplwi	r0, 0
    bne     _80020390
    lwz	r3, -0x79b8(r13)
    cmplwi	r3, 0
    beq     _80020390
    stw	r3, -0x79ac(r13)
    lwz	r0, 0(r3)
    stw	r0, -0x79b8(r13)
_80020390:
    lwz	r5, -0x79ac(r13)
    cmplwi	r5, 0
    beq     _80020450
    lwz	r6, 0x18(r5)
    lwz	r0, -0x79a0(r13)
    cmplw	r6, r0
    bgt     _800203e4
    lwz	r3, 8(r5)
    cmplwi	r3, 0
    bne     _800203c8
    lwz	r4, 0x10(r5)
    lwz	r5, 0x14(r5)
    bl      ARStartDMA
    b       _800203d4
_800203c8:
    lwz	r4, 0x14(r5)
    lwz	r5, 0x10(r5)
    bl      ARStartDMA
_800203d4:
    lwz	r3, -0x79ac(r13)
    lwz	r0, 0x1c(r3)
    stw	r0, -0x79a4(r13)
    b       _80020414
_800203e4:
    lwz	r3, 8(r5)
    cmplwi	r3, 0
    bne     _80020404
    lwz	r4, 0x10(r5)
    mr	r6, r0
    lwz	r5, 0x14(r5)
    bl      ARStartDMA
    b       _80020414
_80020404:
    lwz	r4, 0x14(r5)
    mr	r6, r0
    lwz	r5, 0x10(r5)
    bl      ARStartDMA
_80020414:
    lwz	r3, -0x79ac(r13)
    lwz	r4, -0x79a0(r13)
    lwz	r0, 0x18(r3)
    subf	r0, r4, r0
    stw	r0, 0x18(r3)
    lwz	r4, -0x79ac(r13)
    lwz	r0, -0x79a0(r13)
    lwz	r3, 0x10(r4)
    add	r0, r3, r0
    stw	r0, 0x10(r4)
    lwz	r4, -0x79ac(r13)
    lwz	r0, -0x79a0(r13)
    lwz	r3, 0x14(r4)
    add	r0, r3, r0
    stw	r0, 0x14(r4)
_80020450:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void __ARQCallbackHack(void)
{
    nofralloc
    blr	
}

asm u32 __ARQInterruptServiceRoutine(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r12, -0x79a8(r13)
    cmplwi	r12, 0
    beq     _80020498
    lwz	r3, -0x79b0(r13)
    mtlr	r12
    blrl	
    li	r0, 0
    stw	r0, -0x79b0(r13)
    stw	r0, -0x79a8(r13)
    b       _800204bc
_80020498:
    lwz	r12, -0x79a4(r13)
    cmplwi	r12, 0
    beq     _800204bc
    lwz	r3, -0x79ac(r13)
    mtlr	r12
    blrl	
    li	r0, 0
    stw	r0, -0x79ac(r13)
    stw	r0, -0x79a4(r13)
_800204bc:
    lwz	r6, -0x79c0(r13)
    cmplwi	r6, 0
    beq     _80020510
    lwz	r3, 8(r6)
    cmplwi	r3, 0
    bne     _800204e8
    lwz	r4, 0x10(r6)
    lwz	r5, 0x14(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
    b       _800204f8
_800204e8:
    lwz	r4, 0x14(r6)
    lwz	r5, 0x10(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
_800204f8:
    lwz	r3, -0x79c0(r13)
    lwz	r0, 0x1c(r3)
    stw	r0, -0x79a8(r13)
    stw	r3, -0x79b0(r13)
    lwz	r0, 0(r3)
    stw	r0, -0x79c0(r13)
_80020510:
    lwz	r0, -0x79b0(r13)
    cmplwi	r0, 0
    bne     _80020520
    bl      __ARQServiceQueueLo
_80020520:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void ARQInit(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    lwz	r0, -0x799c(r13)
    cmpwi	r0, 1
    beq     _8002058c
    lwz	r3, -0x7ee0(r13)
    bl      OSRegisterVersion
    li	r31, 0
    li	r0, 0x1000
    stw	r31, -0x79b8(r13)
    lis	r3, -0x7ffe
    stw	r31, -0x79c0(r13)
    addi	r3, r3, 0x464
    stw	r0, -0x79a0(r13)
    bl      ARRegisterDMACallback
    li	r0, 1
    stw	r31, -0x79b0(r13)
    stw	r31, -0x79ac(r13)
    stw	r31, -0x79a8(r13)
    stw	r31, -0x79a4(r13)
    stw	r0, -0x799c(r13)
_8002058c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void ARQPostRequest(register struct ARQRequest* request, register u32 owner, register u32 type, register u32 priority, register u32 source, register u32 dest, register u32 length, register ARQCallback callback)
{
    nofralloc
    mflr	r0
    cmplwi	r10, 0
    stw	r0, 4(r1)
    li	r0, 0
    stwu	r1, -0x38(r1)
    stw	r31, 0x34(r1)
    stw	r30, 0x30(r1)
    addi	r30, r6, 0
    stw	r29, 0x2c(r1)
    addi	r29, r3, 0
    stw	r0, 0(r3)
    stw	r4, 4(r3)
    stw	r5, 8(r3)
    stw	r7, 0x10(r3)
    stw	r8, 0x14(r3)
    stw	r9, 0x18(r3)
    beq     _800205ec
    stw	r10, 0x1c(r29)
    b       _800205f8
_800205ec:
    lis	r3, -0x7ffe
    addi	r0, r3, 0x460
    stw	r0, 0x1c(r29)
_800205f8:
    bl      OSDisableInterrupts
    cmpwi	r30, 1
    addi	r31, r3, 0
    beq     _8002063c
    bge     _8002065c
    cmpwi	r30, 0
    bge     _80020618
    b       _8002065c
_80020618:
    lwz	r0, -0x79b8(r13)
    cmplwi	r0, 0
    beq     _80020630
    lwz	r3, -0x79b4(r13)
    stw	r29, 0(r3)
    b       _80020634
_80020630:
    stw	r29, -0x79b8(r13)
_80020634:
    stw	r29, -0x79b4(r13)
    b       _8002065c
_8002063c:
    lwz	r0, -0x79c0(r13)
    cmplwi	r0, 0
    beq     _80020654
    lwz	r3, -0x79bc(r13)
    stw	r29, 0(r3)
    b       _80020658
_80020654:
    stw	r29, -0x79c0(r13)
_80020658:
    stw	r29, -0x79bc(r13)
_8002065c:
    lwz	r0, -0x79b0(r13)
    cmplwi	r0, 0
    bne     _800206d8
    lwz	r0, -0x79ac(r13)
    cmplwi	r0, 0
    bne     _800206d8
    lwz	r6, -0x79c0(r13)
    cmplwi	r6, 0
    beq     _800206c8
    lwz	r3, 8(r6)
    cmplwi	r3, 0
    bne     _800206a0
    lwz	r4, 0x10(r6)
    lwz	r5, 0x14(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
    b       _800206b0
_800206a0:
    lwz	r4, 0x14(r6)
    lwz	r5, 0x10(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
_800206b0:
    lwz	r3, -0x79c0(r13)
    lwz	r0, 0x1c(r3)
    stw	r0, -0x79a8(r13)
    stw	r3, -0x79b0(r13)
    lwz	r0, 0(r3)
    stw	r0, -0x79c0(r13)
_800206c8:
    lwz	r0, -0x79b0(r13)
    cmplwi	r0, 0
    bne     _800206d8
    bl      __ARQServiceQueueLo
_800206d8:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x3c(r1)
    lwz	r31, 0x34(r1)
    lwz	r30, 0x30(r1)
    lwz	r29, 0x2c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm void ARQSetChunkSize(register u32 size)
{
    nofralloc
    clrlwi.	r0, r3, 0x1b
    beq     _80020714
    subfic	r0, r0, 0x20
    add	r0, r3, r0
    stw	r0, -0x79a0(r13)
    blr	
_80020714:
    stw	r3, -0x79a0(r13)
    blr	
}

asm u32 ARQGetChunkSize(void)
{
    nofralloc
    lwz	r3, -0x79a0(r13)
    blr	
}

#pragma pop
