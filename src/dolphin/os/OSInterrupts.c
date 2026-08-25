typedef int BOOL;
typedef unsigned int u32;
typedef void (*__OSInterruptHandler)(int interrupt, void *context);

extern __OSInterruptHandler *InterruptHandlerTable;
extern void *memset(void *ptr, int value, u32 num);
extern u32 __OSMaskInterrupts(u32 mask);
extern void __OSSetExceptionHandler(int index, void *handler);
extern void *ExternalInterruptHandler;

asm BOOL OSDisableInterrupts(void)
{
    nofralloc
    mfmsr   r3
    rlwinm  r4, r3, 0, 17, 15
    mtmsr   r4
    extrwi  r3, r3, 1, 16
    blr
}

asm BOOL OSEnableInterrupts(void)
{
    nofralloc
    mfmsr   r3
    ori     r4, r3, 0x8000
    mtmsr   r4
    extrwi  r3, r3, 1, 16
    blr
}

asm BOOL OSRestoreInterrupts(register BOOL level)
{
    nofralloc
    cmpwi   level, 0
    mfmsr   r4
    beq     _disable
    ori     r5, r4, 0x8000
    b       _restore
_disable:
    rlwinm  r5, r4, 0, 17, 15
_restore:
    mtmsr   r5
    extrwi  r3, r4, 1, 16
    blr
}

__OSInterruptHandler __OSSetInterruptHandler(short interrupt, __OSInterruptHandler handler)
{
    __OSInterruptHandler old;
    old = InterruptHandlerTable[interrupt];
    InterruptHandlerTable[interrupt] = handler;
    return old;
}

__OSInterruptHandler __OSGetInterruptHandler(short interrupt)
{
    return InterruptHandlerTable[interrupt];
}

asm void __OSInterruptInit(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    lis     r31, 0x8000
    addi    r0, r31, 0x3040
    stw	r0, InterruptHandlerTable
    li      r4, 0
    li      r5, 0x80
    lwz	r3, InterruptHandlerTable
    bl      memset
    li      r0, 0
    stw     r0, 0xC4(r31)
    lis     r3, 0xCC00
    addi    r4, r3, 0x3000
    stw     r0, 0xC8(r31)
    li      r0, 0xF0
    li      r3, -0x20
    stw     r0, 4(r4)
    bl      __OSMaskInterrupts
    lis     r3, ExternalInterruptHandler@ha
    addi    r4, r3, ExternalInterruptHandler@l
    li      r3, 4
    bl      __OSSetExceptionHandler
    lwz     r0, 0x14(r1)
    lwz     r31, 0xC(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}
