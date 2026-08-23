typedef unsigned int u32;
typedef int BOOL;

extern BOOL OSDisableInterrupts(void);
extern u32 __OSMaskInterrupts(u32 intrMask);
extern void __OSSetInterruptHandler(int interrupt, void* handler);
extern BOOL OSRegisterResetFunction(void* info);
extern void DCInvalidateRange(void* addr, u32 size);
extern void RealMode(void (*event)(void));
extern u32 __OSUnmaskInterrupts(u32 intrMask);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void __OSUnhandledException(int error, void* context, u32 cause, u32 addr);
extern void MEMIntrruptHandler(int interrupt, void* context);
extern unsigned char ResetFunctionInfo[];
extern unsigned char __OSErrorTable[];

#pragma push
#pragma force_active on

asm void __OSModuleInit(void)
{
    nofralloc
    lis	r4, -0x8000
    li	r0, 0
    stw	r0, 0x30cc(r4)
    stw	r0, 0x30c8(r4)
    stw	r0, 0x30d0(r4)
    blr	
}

asm u32 OSGetPhysicalMemSize(void)
{
    nofralloc
    lis	r3, -0x8000
    lwz	r3, 0x28(r3)
    blr	
}

asm u32 OSGetConsoleSimulatedMemSize(void)
{
    nofralloc
    lis	r3, -0x8000
    lwz	r3, 0xf0(r3)
    blr	
}

asm BOOL OnReset(register BOOL final)
{
    nofralloc
    mflr	r0
    cmpwi	r3, 0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    beq     _8000e7d4
    lis	r3, -0x3400
    li	r0, 0xff
    sth	r0, 0x4010(r3)
    lis	r3, -0x1000
    bl      __OSMaskInterrupts
_8000e7d4:
    li	r3, 1
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void MEMIntrruptHandler(register int interrupt, register void* context)
{
    nofralloc
    mflr	r0
    lis	r3, -0x3400
    stw	r0, 4(r1)
    addi	r8, r3, 0x4000
    li	r0, 0
    stwu	r1, -8(r1)
    lhz	r7, 0x4024(r3)
    lis     r3, __OSErrorTable@ha
    lhz	r6, 0x22(r8)
    addi    r3, r3, __OSErrorTable@l
    lhz	r5, 0x1e(r8)
    rlwimi	r6, r7, 0x10, 6, 0xf
    sth	r0, 0x20(r8)
    lwz	r12, 0x3c(r3)
    cmplwi	r12, 0
    beq     _8000e83c
    mtlr	r12
    li	r3, 0xf
    crxor	6, 6, 6
    blrl	
    b       _8000e844
_8000e83c:
    li	r3, 0xf
    bl      __OSUnhandledException
_8000e844:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void Config24MB(void)
{
    nofralloc
    li	r7, 0
    lis	r4, 0
    addi	r4, r4, 2
    lis	r3, -0x8000
    addi	r3, r3, 0x1ff
    lis	r6, 0x100
    addi	r6, r6, 2
    lis	r5, -0x7f00
    addi	r5, r5, 0xff
    isync	
    mtdbatu	0, r7
    mtdbatl	0, r4
    mtdbatu	0, r3
    isync	
    mtibatu	0, r7
    mtibatl	0, r4
    mtibatu	0, r3
    isync	
    mtdbatu	2, r7
    mtdbatl	2, r6
    mtdbatu	2, r5
    isync	
    mtibatu	2, r7
    mtibatl	2, r6
    mtibatu	2, r5
    isync	
    mfmsr	r3
    ori	r3, r3, 0x30
    mtspr	0x1b, r3
    mflr	r3
    mtspr	0x1a, r3
    rfi	
}

asm void Config48MB(void)
{
    nofralloc
    li	r7, 0
    lis	r4, 0
    addi	r4, r4, 2
    lis	r3, -0x8000
    addi	r3, r3, 0x3ff
    lis	r6, 0x200
    addi	r6, r6, 2
    lis	r5, -0x7e00
    addi	r5, r5, 0x1ff
    isync	
    mtdbatu	0, r7
    mtdbatl	0, r4
    mtdbatu	0, r3
    isync	
    mtibatu	0, r7
    mtibatl	0, r4
    mtibatu	0, r3
    isync	
    mtdbatu	2, r7
    mtdbatl	2, r6
    mtdbatu	2, r5
    isync	
    mtibatu	2, r7
    mtibatl	2, r6
    mtibatu	2, r5
    isync	
    mfmsr	r3
    ori	r3, r3, 0x30
    mtspr	0x1b, r3
    mflr	r3
    mtspr	0x1a, r3
    rfi	
}

asm void RealMode(register void (*Event)(void))
{
    nofralloc
    clrlwi	r3, r3, 2
    mtspr	0x1a, r3
    mfmsr	r3
    rlwinm	r3, r3, 0, 0x1c, 0x19
    mtspr	0x1b, r3
    rfi	
}

asm void __OSInitMemoryProtection(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x50(r1)
    stmw	r27, 0x3c(r1)
    lis	r27, -0x8000
    lwz	r31, 0xf0(r27)
    bl      OSDisableInterrupts
    lis	r4, -0x3400
    addi	r28, r4, 0x4000
    li	r0, 0
    sth	r0, 0x20(r28)
    li	r0, 0xff
    mr	r30, r3
    sth	r0, 0x10(r28)
    lis	r3, -0x1000
    bl      __OSMaskInterrupts
    lis     r3, MEMIntrruptHandler@ha
    addi    r3, r3, MEMIntrruptHandler@l
    mr	r4, r29
    li	r3, 0
    bl      __OSSetInterruptHandler
    mr	r4, r29
    li	r3, 1
    bl      __OSSetInterruptHandler
    mr	r4, r29
    li	r3, 2
    bl      __OSSetInterruptHandler
    mr	r4, r29
    li	r3, 3
    bl      __OSSetInterruptHandler
    mr	r4, r29
    li	r3, 4
    bl      __OSSetInterruptHandler
    lis     r3, ResetFunctionInfo@ha
    addi    r3, r3, ResetFunctionInfo@l
    bl      OSRegisterResetFunction
    lwz	r3, 0xf0(r27)
    lwz	r0, 0x28(r27)
    cmplw	r3, r0
    bge     _8000ea2c
    addis	r0, r3, -0x180
    cmplwi	r0, 0
    bne     _8000ea2c
    lis	r3, -0x7e80
    lis	r4, 0x180
    bl      DCInvalidateRange
    li	r0, 2
    sth	r0, 0x28(r28)
_8000ea2c:
    lis	r0, 0x180
    cmplw	r31, r0
    bgt     _8000ea48
    lis     r3, Config24MB@ha
    addi    r3, r3, Config24MB@l
    bl      RealMode
    b       _8000ea60
_8000ea48:
    lis	r0, 0x300
    cmplw	r31, r0
    bgt     _8000ea60
    lis     r3, Config48MB@ha
    addi    r3, r3, Config48MB@l
    bl      RealMode
_8000ea60:
    lis	r3, 0x800
    bl      __OSUnmaskInterrupts
    mr	r3, r30
    bl      OSRestoreInterrupts
    lmw	r27, 0x3c(r1)
    lwz	r0, 0x54(r1)
    addi	r1, r1, 0x50
    mtlr	r0
    blr	
}

#pragma pop
