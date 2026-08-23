#pragma push
#pragma force_active on

extern void* memcpy(register void* dst, register const void* src, register unsigned long n);
extern void DCFlushRangeNoSync(register void* addr, register unsigned long n);
extern void ICInvalidateRange(register void* addr, register unsigned long n);
extern void __OSSystemCallVectorStart(void);
extern void __OSSystemCallVectorEnd(void);
extern void __OSSystemCallVectorEnd(void);
extern void __OSSystemCallVectorEnd(void);

asm void SystemCallVector(void)
{
    nofralloc
entry __OSSystemCallVectorStart
    mfspr	r9, 0x3f0
    ori	r10, r9, 0x8
    mtspr	0x3f0, r10
    isync
    sync
    mtspr	0x3f0, r9
    rfi
entry __OSSystemCallVectorEnd
    nop
}

asm void __OSInitSystemCall(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    lis	r5, 0x8000
    lis	r4, 0x8001
    lis     r3, __OSSystemCallVectorEnd@ha
    addi	r31, r5, 0xc00
    addi	r0, r3, __OSSystemCallVectorEnd@l
    addi	r4, r4, 0xbc
    mr	r3, r31
    subf	r5, r4, r0
    bl      memcpy
    mr	r3, r31
    li	r4, 0x100
    bl      DCFlushRangeNoSync
    sync
    mr	r3, r31
    li	r4, 0x100
    bl      ICInvalidateRange
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr
}

asm void fn_80010140(void)
{
    nofralloc
    blr
}

#pragma pop
