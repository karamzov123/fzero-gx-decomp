typedef int BOOL;
typedef unsigned int u32;
typedef unsigned long long u64;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);

asm u64 OSGetTime(void)
{
    nofralloc
retry:
    mftb    r3, 269
    mftb    r4, 268
    mftb    r5, 269
    cmpw    r3, r5
    bne     retry
    blr
}

asm u32 OSGetTick(void)
{
    nofralloc
    mftb    r3, 268
    blr
}

asm u64 __OSGetSystemTime(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    bl      OSDisableInterrupts
    mr      r31, r3
    bl      OSGetTime
    lis     r6, 0x8000
    lwz     r5, 0x30dc(r6)
    lwz     r0, 0x30d8(r6)
    addc    r29, r5, r4
    adde    r30, r0, r3
    mr      r3, r31
    bl      OSRestoreInterrupts
    mr      r4, r29
    mr      r3, r30
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}
