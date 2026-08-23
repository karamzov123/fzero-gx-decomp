#pragma push
#pragma force_active on

extern void DSPCheckMailToDSP(void);
extern void DSPCheckMailFromDSP(void);
extern void DSPReadMailFromDSP(void);
extern void DSPSendMailToDSP(void);
extern void DSPInit(void);
extern void DSPCheckInit(void);
extern void DSPAddTask(void);
extern void DSPCancelTask(void);
extern void DSPAssertTask(void);
extern void __DSP_debug_printf(void);
extern void __DSPHandler(void);
extern void __DSP_exec_task(void);
extern void __DSP_boot_task(void);
extern void __DSP_insert_task(void);
extern void __DSP_remove_task(void);
extern void fn_80029824(void);
extern void OSClearContext(void);
extern void OSDisableInterrupts(void);
extern void OSEnableInterrupts(void);
extern void OSRegisterVersion(void);
extern void OSRestoreInterrupts(void);
extern void OSSetCurrentContext(void);
extern void OSWakeupThread(void);
extern void __OSSetInterruptHandler(void);
extern void __OSUnmaskInterrupts(void);
extern void __cvt_fp2unsigned(void);

asm void DSPCheckMailToDSP(void)
{
    nofralloc
    lis	r3, -0x3400
    lhz	r0, 0x5000(r3)
    rlwinm	r3, r0, 0x11, 0x1f, 0x1f
    blr	
}

asm void DSPCheckMailFromDSP(void)
{
    nofralloc
    lis	r3, -0x3400
    lhz	r0, 0x5004(r3)
    rlwinm	r3, r0, 0x11, 0x1f, 0x1f
    blr	
}

asm void DSPReadMailFromDSP(void)
{
    nofralloc
    lis	r3, -0x3400
    addi	r3, r3, 0x5000
    lhz	r0, 4(r3)
    lhz	r3, 6(r3)
    rlwimi	r3, r0, 0x10, 0, 0xf
    blr	
}

asm void DSPSendMailToDSP(void)
{
    nofralloc
    lis	r4, -0x3400
    srwi	r0, r3, 0x10
    sth	r0, 0x5000(r4)
    sth	r3, 0x5002(r4)
    blr	
}

asm void DSPInit(void)
{
    nofralloc
    mflr	r0
    lis	r3, -0x7fed
    stw	r0, 4(r1)
    addi	r5, r3, -0x57b8
    crxor	6, 6, 6
    addi	r3, r5, 0x48
    stwu	r1, -0x10(r1)
    addi	r4, r5, 0x68
    stw	r31, 0xc(r1)
    addi	r5, r5, 0x74
    bl      __DSP_debug_printf
    lwz	r0, -0x7820(r13)
    cmpwi	r0, 1
    beq     _80028dbc
    lwz	r3, -0x7ec0(r13)
    bl      OSRegisterVersion
    bl      OSDisableInterrupts
    lis     r4, __DSPHandler@ha
    addi	r31, r3, 0
    addi    r4, r4, __DSPHandler@l
    li	r3, 7
    bl      __OSSetInterruptHandler
    lis	r3, 0x100
    bl      __OSUnmaskInterrupts
    lis	r3, -0x3400
    addi	r6, r3, 0x5000
    lhz	r3, 0x500a(r3)
    li	r0, -0xa9
    and	r0, r3, r0
    ori	r0, r0, 0x800
    sth	r0, 0xa(r6)
    li	r5, -0xad
    li	r4, 0
    lhz	r7, 0xa(r6)
    li	r0, 1
    addi	r3, r31, 0
    and	r5, r7, r5
    sth	r5, 0xa(r6)
    stw	r4, -0x7810(r13)
    stw	r4, -0x7804(r13)
    stw	r4, -0x780c(r13)
    stw	r4, -0x7808(r13)
    stw	r0, -0x7820(r13)
    bl      OSRestoreInterrupts
_80028dbc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void DSPCheckInit(void)
{
    nofralloc
    lwz	r3, -0x7820(r13)
    blr	
}

asm void DSPAddTask(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    addi	r31, r3, 0
    addi	r3, r30, 0
    bl      __DSP_insert_task
    li	r0, 0
    stw	r0, 0(r30)
    li	r0, 1
    addi	r3, r31, 0
    stw	r0, 8(r30)
    bl      OSRestoreInterrupts
    lwz	r0, -0x7808(r13)
    cmplw	r30, r0
    bne     _80028e2c
    mr	r3, r30
    bl      __DSP_boot_task
_80028e2c:
    mr	r3, r30
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void DSPCancelTask(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lwz	r0, 8(r31)
    ori	r0, r0, 2
    stw	r0, 8(r31)
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void DSPAssertTask(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lwz	r4, -0x7804(r13)
    addi	r31, r3, 0
    cmplw	r4, r30
    bne     _80028ed0
    li	r0, 1
    stw	r30, -0x7814(r13)
    mr	r3, r31
    stw	r0, -0x7818(r13)
    bl      OSRestoreInterrupts
    mr	r3, r30
    b       _80028f38
_80028ed0:
    lwz	r3, 4(r30)
    lwz	r0, 4(r4)
    cmplw	r3, r0
    bge     _80028f2c
    li	r0, 1
    stw	r30, -0x7814(r13)
    stw	r0, -0x7818(r13)
    lwz	r0, 0(r4)
    cmplwi	r0, 1
    bne     _80028f1c
    bl      OSDisableInterrupts
    lis	r4, -0x3400
    addi	r5, r4, 0x5000
    lhz	r4, 0x500a(r4)
    li	r0, -0xa9
    and	r0, r4, r0
    ori	r0, r0, 2
    sth	r0, 0xa(r5)
    bl      OSRestoreInterrupts
_80028f1c:
    mr	r3, r31
    bl      OSRestoreInterrupts
    mr	r3, r30
    b       _80028f38
_80028f2c:
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 0
_80028f38:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __DSP_debug_printf(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    bne     cr1, _80028f78
    stfd	f1, 0x28(r1)
    stfd	f2, 0x30(r1)
    stfd	f3, 0x38(r1)
    stfd	f4, 0x40(r1)
    stfd	f5, 0x48(r1)
    stfd	f6, 0x50(r1)
    stfd	f7, 0x58(r1)
    stfd	f8, 0x60(r1)
_80028f78:
    stw	r3, 8(r1)
    stw	r4, 0xc(r1)
    stw	r5, 0x10(r1)
    stw	r6, 0x14(r1)
    stw	r7, 0x18(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r10, 0x24(r1)
    addi	r1, r1, 0x70
    blr	
}

asm void __DSPHandler(void)
{
    nofralloc
    mflr	r0
    lis	r3, -0x3400
    stw	r0, 4(r1)
    addi	r3, r3, 0x5000
    li	r0, -0x29
    stwu	r1, -0x2e8(r1)
    stw	r31, 0x2e4(r1)
    addi	r31, r4, 0
    lhz	r5, 0xa(r3)
    and	r0, r5, r0
    ori	r0, r0, 0x80
    sth	r0, 0xa(r3)
    addi	r3, r1, 0x10
    bl      OSClearContext
    addi	r3, r1, 0x10
    bl      OSSetCurrentContext
_80028fe0:
    bl      DSPCheckMailFromDSP
    cmplwi	r3, 0
    beq     _80028fe0
    bl      DSPReadMailFromDSP
    lwz	r5, -0x7804(r13)
    lwz	r0, 8(r5)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    beq     _80029014
    addis	r0, r3, 0x232f
    cmplwi	r0, 2
    bne     _80029014
    lis	r3, -0x232f
    addi	r3, r3, 3
_80029014:
    lis	r4, -0x232f
    addi	r0, r4, 2
    cmpw	r3, r0
    beq     _80029094
    bge     _80029038
    cmpw	r3, r4
    beq     _8002904c
    bge     _80029070
    b       _800293a0
_80029038:
    addi	r0, r4, 4
    cmpw	r3, r0
    beq     _80029388
    bge     _800293a0
    b       _800291fc
_8002904c:
    li	r0, 1
    stw	r0, 0(r5)
    lwz	r3, -0x7804(r13)
    lwz	r12, 0x28(r3)
    cmplwi	r12, 0
    beq     _800293a0
    mtlr	r12
    blrl	
    b       _800293a0
_80029070:
    li	r0, 1
    stw	r0, 0(r5)
    lwz	r3, -0x7804(r13)
    lwz	r12, 0x2c(r3)
    cmplwi	r12, 0
    beq     _800293a0
    mtlr	r12
    blrl	
    b       _800293a0
_80029094:
    lwz	r0, -0x7818(r13)
    cmpwi	r0, 0
    beq     _80029134
    lwz	r0, -0x7814(r13)
    cmplw	r5, r0
    bne     _800290ec
    lis	r3, -0x322f
    addi	r3, r3, 3
    bl      DSPSendMailToDSP
_800290b8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800290b8
    li	r0, 0
    lwz	r3, -0x7804(r13)
    stw	r0, -0x7814(r13)
    stw	r0, -0x7818(r13)
    lwz	r12, 0x2c(r3)
    cmplwi	r12, 0
    beq     _800293a0
    mtlr	r12
    blrl	
    b       _800293a0
_800290ec:
    lis	r3, -0x322f
    addi	r3, r3, 1
    bl      DSPSendMailToDSP
_800290f8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800290f8
    lwz	r3, -0x7804(r13)
    lwz	r4, -0x7814(r13)
    bl      __DSP_exec_task
    lwz	r3, -0x7804(r13)
    li	r4, 2
    li	r0, 0
    stw	r4, 0(r3)
    lwz	r3, -0x7814(r13)
    stw	r0, -0x7818(r13)
    stw	r3, -0x7804(r13)
    stw	r0, -0x7814(r13)
    b       _800293a0
_80029134:
    lwz	r0, 0x38(r5)
    cmplwi	r0, 0
    bne     _800291bc
    lwz	r0, -0x7808(r13)
    cmplw	r5, r0
    bne     _80029180
    lis	r3, -0x322f
    addi	r3, r3, 3
    bl      DSPSendMailToDSP
_80029158:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029158
    lwz	r3, -0x7804(r13)
    lwz	r12, 0x2c(r3)
    cmplwi	r12, 0
    beq     _800293a0
    mtlr	r12
    blrl	
    b       _800293a0
_80029180:
    lis	r3, -0x322f
    addi	r3, r3, 1
    bl      DSPSendMailToDSP
_8002918c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002918c
    lwz	r3, -0x7804(r13)
    lwz	r4, -0x7808(r13)
    bl      __DSP_exec_task
    lwz	r3, -0x7804(r13)
    li	r0, 2
    stw	r0, 0(r3)
    lwz	r0, -0x7808(r13)
    stw	r0, -0x7804(r13)
    b       _800293a0
_800291bc:
    lis	r3, -0x322f
    addi	r3, r3, 1
    bl      DSPSendMailToDSP
_800291c8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800291c8
    lwz	r3, -0x7804(r13)
    lwz	r4, 0x38(r3)
    bl      __DSP_exec_task
    lwz	r3, -0x7804(r13)
    li	r0, 2
    stw	r0, 0(r3)
    lwz	r3, -0x7804(r13)
    lwz	r0, 0x38(r3)
    stw	r0, -0x7804(r13)
    b       _800293a0
_800291fc:
    lwz	r0, -0x7818(r13)
    cmpwi	r0, 0
    beq     _80029264
    lwz	r12, 0x30(r5)
    cmplwi	r12, 0
    beq     _80029220
    mtlr	r12
    addi	r3, r5, 0
    blrl	
_80029220:
    lis	r3, -0x322f
    addi	r3, r3, 1
    bl      DSPSendMailToDSP
_8002922c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002922c
    li	r3, 0
    lwz	r4, -0x7814(r13)
    bl      __DSP_exec_task
    lwz	r3, -0x7804(r13)
    bl      __DSP_remove_task
    lwz	r3, -0x7814(r13)
    li	r0, 0
    stw	r0, -0x7818(r13)
    stw	r3, -0x7804(r13)
    stw	r0, -0x7814(r13)
    b       _800293a0
_80029264:
    lwz	r0, 0x38(r5)
    cmplwi	r0, 0
    bne     _80029320
    lwz	r0, -0x7808(r13)
    cmplw	r5, r0
    bne     _800292c4
    lwz	r12, 0x30(r5)
    cmplwi	r12, 0
    beq     _80029294
    mtlr	r12
    addi	r3, r5, 0
    blrl	
_80029294:
    lis	r3, -0x322f
    addi	r3, r3, 2
    bl      DSPSendMailToDSP
_800292a0:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800292a0
    lwz	r3, -0x7804(r13)
    li	r0, 3
    stw	r0, 0(r3)
    lwz	r3, -0x7804(r13)
    bl      __DSP_remove_task
    b       _800293a0
_800292c4:
    lwz	r12, 0x30(r5)
    cmplwi	r12, 0
    beq     _800292dc
    mtlr	r12
    addi	r3, r5, 0
    blrl	
_800292dc:
    lis	r3, -0x322f
    addi	r3, r3, 1
    bl      DSPSendMailToDSP
_800292e8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800292e8
    lwz	r4, -0x7804(r13)
    li	r0, 3
    li	r3, 0
    stw	r0, 0(r4)
    lwz	r4, -0x7808(r13)
    bl      __DSP_exec_task
    lwz	r0, -0x7808(r13)
    lwz	r3, -0x780c(r13)
    stw	r0, -0x7804(r13)
    bl      __DSP_remove_task
    b       _800293a0
_80029320:
    lwz	r12, 0x30(r5)
    cmplwi	r12, 0
    beq     _80029338
    mtlr	r12
    addi	r3, r5, 0
    blrl	
_80029338:
    lis	r3, -0x322f
    addi	r3, r3, 1
    bl      DSPSendMailToDSP
_80029344:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029344
    lwz	r4, -0x7804(r13)
    li	r0, 3
    li	r3, 0
    stw	r0, 0(r4)
    lwz	r4, -0x7804(r13)
    lwz	r4, 0x38(r4)
    bl      __DSP_exec_task
    lwz	r3, -0x7804(r13)
    lwz	r0, 0x38(r3)
    stw	r0, -0x7804(r13)
    lwz	r3, -0x7804(r13)
    lwz	r3, 0x3c(r3)
    bl      __DSP_remove_task
    b       _800293a0
_80029388:
    lwz	r12, 0x34(r5)
    cmplwi	r12, 0
    beq     _800293a0
    mtlr	r12
    addi	r3, r5, 0
    blrl	
_800293a0:
    addi	r3, r1, 0x10
    bl      OSClearContext
    mr	r3, r31
    bl      OSSetCurrentContext
    lwz	r0, 0x2ec(r1)
    lwz	r31, 0x2e4(r1)
    addi	r1, r1, 0x2e8
    mtlr	r0
    blr	
}

asm void __DSP_exec_task(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, 0
    stw	r30, 0x10(r1)
    or.	r30, r3, r3
    beq     _80029424
    lwz	r3, 0x18(r30)
    bl      DSPSendMailToDSP
_800293ec:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800293ec
    lwz	r3, 0x1c(r30)
    bl      DSPSendMailToDSP
_80029400:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029400
    lwz	r3, 0x20(r30)
    bl      DSPSendMailToDSP
_80029414:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029414
    b       _80029460
_80029424:
    li	r3, 0
    bl      DSPSendMailToDSP
_8002942c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002942c
    li	r3, 0
    bl      DSPSendMailToDSP
_80029440:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029440
    li	r3, 0
    bl      DSPSendMailToDSP
_80029454:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029454
_80029460:
    lwz	r3, 0xc(r31)
    bl      DSPSendMailToDSP
_80029468:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029468
    lwz	r3, 0x10(r31)
    bl      DSPSendMailToDSP
_8002947c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002947c
    lwz	r3, 0x14(r31)
    bl      DSPSendMailToDSP
_80029490:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029490
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bne     _800294fc
    lhz	r3, 0x24(r31)
    bl      DSPSendMailToDSP
_800294b0:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800294b0
    li	r3, 0
    bl      DSPSendMailToDSP
_800294c4:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800294c4
    li	r3, 0
    bl      DSPSendMailToDSP
_800294d8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800294d8
    li	r3, 0
    bl      DSPSendMailToDSP
_800294ec:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800294ec
    b       _8002954c
_800294fc:
    lhz	r3, 0x26(r31)
    bl      DSPSendMailToDSP
_80029504:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029504
    lwz	r3, 0x18(r31)
    bl      DSPSendMailToDSP
_80029518:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029518
    lwz	r3, 0x1c(r31)
    bl      DSPSendMailToDSP
_8002952c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002952c
    lwz	r3, 0x20(r31)
    bl      DSPSendMailToDSP
_80029540:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029540
_8002954c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __DSP_boot_task(void)
{
    nofralloc
    mflr	r0
    lis	r4, -0x7fed
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, -0x5738
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
_80029584:
    bl      DSPCheckMailFromDSP
    cmplwi	r3, 0
    beq     _80029584
    bl      DSPReadMailFromDSP
    stw	r3, 0xc(r1)
    lis	r3, -0x7f0c
    addi	r3, r3, -0x5fff
    bl      DSPSendMailToDSP
_800295a4:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800295a4
    lwz	r3, 0xc(r30)
    bl      DSPSendMailToDSP
_800295b8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800295b8
    lis	r3, -0x7f0c
    addi	r3, r3, -0x3ffe
    bl      DSPSendMailToDSP
_800295d0:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800295d0
    lwz	r0, 0x14(r30)
    clrlwi	r3, r0, 0x10
    bl      DSPSendMailToDSP
_800295e8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _800295e8
    lis	r3, -0x7f0c
    addi	r3, r3, -0x5ffe
    bl      DSPSendMailToDSP
_80029600:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029600
    lwz	r3, 0x10(r30)
    bl      DSPSendMailToDSP
_80029614:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029614
    lis	r3, -0x7f0c
    addi	r3, r3, -0x4ffe
    bl      DSPSendMailToDSP
_8002962c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002962c
    li	r3, 0
    bl      DSPSendMailToDSP
_80029640:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029640
    lis	r3, -0x7f0c
    addi	r3, r3, -0x2fff
    bl      DSPSendMailToDSP
_80029658:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80029658
    lhz	r3, 0x24(r30)
    bl      DSPSendMailToDSP
_8002966c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002966c
    addi	r3, r31, 0
    crxor	6, 6, 6
    addi	r4, r30, 0
    bl      __DSP_debug_printf
    lwz	r4, 0xc(r30)
    addi	r3, r31, 0x20
    crxor	6, 6, 6
    bl      __DSP_debug_printf
    lwz	r4, 0x14(r30)
    addi	r3, r31, 0x50
    crxor	6, 6, 6
    bl      __DSP_debug_printf
    lwz	r4, 0x10(r30)
    addi	r3, r31, 0x80
    crxor	6, 6, 6
    bl      __DSP_debug_printf
    lwz	r4, 0x1c(r30)
    addi	r3, r31, 0xb0
    crxor	6, 6, 6
    bl      __DSP_debug_printf
    lhz	r4, 0x24(r30)
    addi	r3, r31, 0xe0
    crxor	6, 6, 6
    bl      __DSP_debug_printf
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __DSP_insert_task(void)
{
    nofralloc
    lwz	r0, -0x7808(r13)
    cmplwi	r0, 0
    bne     _80029718
    stw	r3, -0x7804(r13)
    li	r0, 0
    stw	r3, -0x780c(r13)
    stw	r3, -0x7808(r13)
    stw	r0, 0x3c(r3)
    stw	r0, 0x38(r3)
    blr	
_80029718:
    mr	r5, r0
    b       _80029760
_80029720:
    lwz	r4, 4(r3)
    lwz	r0, 4(r5)
    cmplw	r4, r0
    bge     _8002975c
    lwz	r0, 0x3c(r5)
    stw	r0, 0x3c(r3)
    stw	r3, 0x3c(r5)
    stw	r5, 0x38(r3)
    lwz	r4, 0x3c(r3)
    cmplwi	r4, 0
    bne     _80029754
    stw	r3, -0x7808(r13)
    b       _80029768
_80029754:
    stw	r3, 0x38(r4)
    b       _80029768
_8002975c:
    lwz	r5, 0x38(r5)
_80029760:
    cmplwi	r5, 0
    bne     _80029720
_80029768:
    cmplwi	r5, 0
    bnelr	
    lwz	r4, -0x780c(r13)
    li	r0, 0
    stw	r3, 0x38(r4)
    stw	r0, 0x38(r3)
    lwz	r0, -0x780c(r13)
    stw	r0, 0x3c(r3)
    stw	r3, -0x780c(r13)
    blr	
}

asm void __DSP_remove_task(void)
{
    nofralloc
    li	r4, 0
    stw	r4, 8(r3)
    li	r0, 3
    stw	r0, 0(r3)
    lwz	r0, -0x7808(r13)
    cmplw	r0, r3
    bne     _800297d8
    lwz	r0, 0x38(r3)
    cmplwi	r0, 0
    beq     _800297c8
    stw	r0, -0x7808(r13)
    lwz	r3, 0x38(r3)
    stw	r4, 0x3c(r3)
    blr	
_800297c8:
    stw	r4, -0x7804(r13)
    stw	r4, -0x780c(r13)
    stw	r4, -0x7808(r13)
    blr	
_800297d8:
    lwz	r0, -0x780c(r13)
    cmplw	r0, r3
    bne     _80029800
    lwz	r0, 0x3c(r3)
    stw	r0, -0x780c(r13)
    lwz	r3, 0x3c(r3)
    stw	r4, 0x38(r3)
    lwz	r0, -0x7808(r13)
    stw	r0, -0x7804(r13)
    blr	
_80029800:
    lwz	r0, 0x38(r3)
    stw	r0, -0x7804(r13)
    lwz	r0, 0x38(r3)
    lwz	r4, 0x3c(r3)
    stw	r0, 0x38(r4)
    lwz	r0, 0x3c(r3)
    lwz	r3, 0x38(r3)
    stw	r0, 0x3c(r3)
    blr	
}

asm void fn_80029824(void)
{
    nofralloc
    blr	
}

#pragma pop
