#pragma push
#pragma force_active on

extern void OSCancelThread(void);
extern void OSCreateThread(void);
extern void OSDisableInterrupts(void);
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern void OSRestoreInterrupts(void);
extern void OSResumeThread(void);
extern void OSSetThreadPriority(void);
extern void OSSuspendThread(void);
extern void fn_800102AC(void);
extern void fn_80011358(void);
extern void fn_8001AF64(void);
extern void fn_80046D94(void);
extern void fn_800474E4(void);
extern void fn_8004ED3C(void);
extern void fn_8004EFA8(void);
extern void fn_8004F00C(void);
extern void fn_8004F26C(void);
extern void fn_8004F55C(void);
extern void fn_8005466C(void);
extern void fn_800551D0(void);
extern void fn_80055304(void);
extern void fn_800565F0(void);
extern void fn_80058B54(void);
extern void fn_80058BFC(void);
extern void fn_80058C94(void);
extern void fn_80058D24(void);
extern void fn_80058DB4(void);
extern void fn_80058E44(void);
extern void fn_80058ED4(void);
extern void fn_80058EE4(void);
extern void fn_80058EF4(void);
extern void fn_80059028(void);
extern void fn_800595A4(void);
extern void fn_80059AB4(void);
extern void fn_80059B44(void);
extern void fn_8005A668(void);
extern void fn_8005A678(void);
extern void fn_8005A680(void);
extern void fn_8005A688(void);
extern void fn_8005A698(void);
extern void fn_8005A74C(void);
extern void fn_8005A7F8(void);
extern void fn_8005A94C(void);
extern void fn_8005A95C(void);
extern void fn_8005B010(void);
extern void fn_8005B068(void);
extern void fn_8005B0C4(void);
extern void fn_8005B264(void);
extern void fn_8005B464(void);
extern void fn_8005B534(void);
extern void fn_8005BCB4(void);
extern void fn_8005BDD4(void);
extern void fn_8005BE48(void);
extern void memset(void);

asm void fn_8004E098(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    lwz	r0, 0xc(r3)
    cmpwi	r0, 1
    bne     _8004e0c0
    li	r0, 2
    stw	r0, 0xc(r31)
_8004e0c0:
    lwz	r0, 0xc(r31)
    cmpwi	r0, 2
    bne     _8004e17c
    lwz	r0, 0x14(r31)
    cmpwi	r0, 1
    bne     _8004e10c
    lha	r0, 0x38(r31)
    addi	r6, r31, 0x28
    addi	r9, r31, 0x34
    stw	r0, 8(r1)
    lwz	r3, 0x18(r31)
    lwz	r4, 0x1c(r31)
    lwz	r5, 0x20(r31)
    lha	r7, 0x30(r31)
    lha	r8, 0x32(r31)
    lha	r10, 0x36(r31)
    bl      fn_8004F55C
    stw	r3, 0x10(r31)
    b       _8004e174
_8004e10c:
    addi	r0, r31, 0x34
    addi	r6, r31, 0x28
    stw	r0, 8(r1)
    addi	r8, r31, 0x2c
    lha	r0, 0x36(r31)
    stw	r0, 0xc(r1)
    lha	r0, 0x38(r31)
    stw	r0, 0x10(r1)
    lwz	r3, 0x18(r31)
    lwz	r4, 0x1c(r31)
    lwz	r5, 0x20(r31)
    lwz	r7, 0x24(r31)
    lha	r9, 0x30(r31)
    lha	r10, 0x32(r31)
    bl      fn_8004EFA8
    stw	r3, 0x10(r31)
    lwz	r0, 0x10(r31)
    srwi	r3, r0, 0x1f
    clrlwi	r0, r0, 0x1f
    xor	r0, r0, r3
    subf	r0, r3, r0
    cmpwi	r0, 1
    bne     _8004e174
    lis	r3, -0x7fe8
    li	r0, 1
    stw	r0, -0x1a48(r3)
_8004e174:
    li	r0, 3
    stw	r0, 0xc(r31)
_8004e17c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004E190(void)
{
    nofralloc
    lwz	r3, 0x10(r3)
    blr	
}

asm void fn_8004E198(void)
{
    nofralloc
    lwz	r0, 0xc(r3)
    cmpwi	r0, 3
    bnelr	
    li	r0, 0
    stw	r0, 0xc(r3)
    blr	
}

asm void fn_8004E1B0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r4, 0
    li	r5, 8
    stw	r0, 0x14(r1)
    li	r0, 0
    stw	r0, 0xc(r3)
    addi	r3, r3, 0x28
    bl      memset
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E1E4(void)
{
    nofralloc
    lwz	r0, 0xc(r3)
    cmpwi	r0, 0
    bnelr	
    li	r4, 0
    li	r0, 1
    stw	r4, 0x10(r3)
    stw	r0, 0xc(r3)
    blr	
}

asm void fn_8004E204(void)
{
    nofralloc
    lwz	r0, 0xc(r3)
    cmpwi	r0, 0
    bne     _8004e230
    li	r0, 2
    stw	r0, 0x14(r3)
    stw	r4, 0x18(r3)
    stw	r5, 0x1c(r3)
    stw	r6, 0x20(r3)
    stw	r7, 0x24(r3)
    li	r3, 1
    blr	
_8004e230:
    li	r3, 0
    blr	
}

asm void fn_8004E238(void)
{
    nofralloc
    lwz	r0, 0xc(r3)
    cmpwi	r0, 0
    bne     _8004e268
    li	r7, 1
    li	r0, 0
    stw	r7, 0x14(r3)
    stw	r4, 0x18(r3)
    stw	r5, 0x1c(r3)
    stw	r6, 0x20(r3)
    stw	r0, 0x24(r3)
    li	r3, 1
    blr	
_8004e268:
    li	r3, 0
    blr	
}

asm void fn_8004E270(void)
{
    nofralloc
    lwz	r3, 0xc(r3)
    blr	
}

asm void fn_8004E278(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    beq     _8004e2a0
    li	r0, 0
    li	r4, 0
    stw	r0, 0(r3)
    li	r5, 0x3c
    bl      memset
_8004e2a0:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E2B0(void)
{
    nofralloc
    lha	r0, 0x34(r3)
    sth	r0, 0(r4)
    lha	r0, 0x36(r3)
    sth	r0, 0(r5)
    lha	r0, 0x38(r3)
    sth	r0, 0(r6)
    blr	
}

asm void fn_8004E2CC(void)
{
    nofralloc
    sth	r4, 0x34(r3)
    sth	r5, 0x36(r3)
    sth	r6, 0x38(r3)
    blr	
}

asm void fn_8004E2DC(void)
{
    nofralloc
    lha	r0, 0x28(r3)
    sth	r0, 0(r4)
    lha	r0, 0x2a(r3)
    sth	r0, 0(r5)
    lha	r0, 0x2c(r3)
    sth	r0, 2(r4)
    lha	r0, 0x2e(r3)
    sth	r0, 2(r5)
    blr	
}

asm void fn_8004E300(void)
{
    nofralloc
    lha	r0, 0(r4)
    sth	r0, 0x28(r3)
    lha	r0, 0(r5)
    sth	r0, 0x2a(r3)
    lha	r0, 2(r4)
    sth	r0, 0x2c(r3)
    lha	r0, 2(r5)
    sth	r0, 0x2e(r3)
    blr	
}

asm void fn_8004E324(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    mr	r6, r3
    mr	r3, r5
    stw	r0, 0x14(r1)
    addi	r5, r6, 0x30
    addi	r6, r6, 0x32
    bl      fn_80046D94
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E354(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe8
    stw	r0, 0x14(r1)
    li	r0, 2
    addi	r3, r3, -0x1a44
    stw	r31, 0xc(r1)
    li	r31, 0
    stw	r30, 8(r1)
    mtctr	r0
_8004e37c:
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    addi	r3, r3, 0x3c
    addi	r31, r31, 1
    bdnz    _8004e37c
_8004e420:
    cmpwi	r31, 0x10
    bne     _8004e430
    li	r3, 0
    b       _8004e494
_8004e430:
    mulli	r5, r31, 0x3c
    lis	r3, -0x7fe8
    li	r4, 0
    addi	r0, r3, -0x1a44
    add	r30, r0, r5
    li	r5, 0x3c
    mr	r3, r30
    bl      memset
    li	r0, 1
    lis	r3, 1
    stw	r0, 0(r30)
    li	r0, 0
    addi	r4, r3, -0x53bc
    addi	r5, r30, 0x30
    stw	r31, 4(r30)
    addi	r6, r30, 0x32
    li	r3, 0x1f4
    stw	r0, 8(r30)
    stw	r0, 0xc(r30)
    bl      fn_80046D94
    addi	r3, r30, 0x28
    li	r4, 0
    li	r5, 8
    bl      memset
    mr	r3, r30
_8004e494:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E4AC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe8
    li	r4, 0
    stw	r0, 0x14(r1)
    addi	r3, r3, -0x1a44
    li	r5, 0x3c0
    bl      memset
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E4DC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe8
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, -0x1680
    lwz	r3, 4(r31)
    addic.	r0, r3, -1
    stw	r0, 4(r31)
    bne     _8004e56c
    li	r0, 0
    addi	r3, r31, 0x28
    stw	r0, 0xca4(r31)
    li	r4, 1
    bl      OSSetThreadPriority
    b       _8004e524
_8004e51c:
    addi	r3, r31, 0x28
    bl      OSResumeThread
_8004e524:
    lwz	r0, 0xca0(r31)
    cmpwi	r0, 0
    beq     _8004e51c
    addi	r3, r31, 0x340
    bl      OSCancelThread
    addi	r3, r31, 0x658
    bl      OSCancelThread
    li	r0, 0
    addi	r3, r31, 0x970
    stw	r0, 0xcac(r31)
    bl      OSResumeThread
    b       _8004e55c
_8004e554:
    addi	r3, r31, 0x970
    bl      OSResumeThread
_8004e55c:
    lwz	r0, 0xca8(r31)
    cmpwi	r0, 0
    beq     _8004e554
    bl      fn_80058B54
_8004e56c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E580(void)
{
    nofralloc
    lis	r3, -0x7fe8
    addi	r3, r3, -0x167c
    lwz	r3, 0(r3)
    neg	r0, r3
    or	r0, r0, r3
    srwi	r3, r0, 0x1f
    blr	
}

asm void fn_8004E59C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r5, -0x7fe8
    lis	r4, -0x7ff7
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r5, -0x1680
    stw	r30, 8(r1)
    mr	r30, r3
    addi	r3, r4, 0x115c
    lwz	r0, 4(r31)
    lwz	r3, 0(r3)
    cmpwi	r0, 0
    bne     _8004e790
    bl      fn_80058BFC
    lis	r3, -0x7ffb
    li	r4, 0
    addi	r3, r3, -0x1500
    bl      fn_80058EE4
    lis	r3, -0x7ffb
    li	r4, 0
    addi	r3, r3, -0x156c
    bl      fn_80058ED4
    cmplwi	r30, 0
    bne     _8004e63c
    lis	r3, -0x7fed
    li	r8, 0x10
    addi	r7, r3, -0x46e8
    li	r6, 1
    li	r5, 8
    li	r4, 0xc
    li	r3, 0xe
    li	r0, 0x18
    stw	r8, 0x10(r7)
    stw	r6, 0(r7)
    stw	r5, 4(r7)
    stw	r4, 8(r7)
    stw	r3, 0xc(r7)
    stw	r0, 0x14(r7)
    b       _8004e670
_8004e63c:
    lwz	r3, 0(r30)
    lis	r4, -0x7fed
    lwz	r0, 4(r30)
    stwu	r3, -0x46e8(r4)
    stw	r0, 4(r4)
    lwz	r3, 8(r30)
    lwz	r0, 0xc(r30)
    stw	r3, 8(r4)
    stw	r0, 0xc(r4)
    lwz	r3, 0x10(r30)
    lwz	r0, 0x14(r30)
    stw	r3, 0x10(r4)
    stw	r0, 0x14(r4)
_8004e670:
    lis	r3, -0x7fed
    lis	r4, -0x7ffb
    addi	r3, r3, -0x46e8
    addi	r6, r31, 0x6cb0
    lwz	r8, 4(r3)
    addi	r4, r4, -0x1658
    addi	r3, r31, 0x970
    li	r5, 0
    li	r7, 0x1000
    li	r9, 1
    addi	r6, r6, 0x1000
    bl      OSCreateThread
    lis	r3, -0x7fed
    lis	r4, -0x7ffb
    addi	r3, r3, -0x46e8
    addi	r6, r31, 0x4cb0
    lwz	r8, 8(r3)
    addi	r4, r4, -0x1708
    addi	r3, r31, 0x340
    li	r5, 0
    li	r7, 0x2000
    li	r9, 1
    addi	r6, r6, 0x2000
    bl      OSCreateThread
    lis	r3, -0x7fed
    lis	r4, -0x7ffb
    addi	r3, r3, -0x46e8
    addi	r6, r31, 0x2cb0
    lwz	r8, 0xc(r3)
    addi	r4, r4, -0x1760
    addi	r3, r31, 0x658
    li	r5, 0
    li	r7, 0x2000
    li	r9, 1
    addi	r6, r6, 0x2000
    bl      OSCreateThread
    lis	r3, -0x7fed
    lis	r4, -0x7ffb
    addi	r3, r3, -0x46e8
    addi	r6, r31, 0xcb0
    lwz	r8, 0x14(r3)
    addi	r4, r4, -0x182c
    addi	r3, r31, 0x28
    li	r5, 0
    li	r7, 0x2000
    li	r9, 1
    addi	r6, r6, 0x2000
    bl      OSCreateThread
    bl      fn_800102AC
    li	r4, 1
    li	r0, 0
    stw	r3, 0x24(r31)
    addi	r3, r31, 0x340
    stw	r4, 0xc94(r31)
    stw	r4, 0xca4(r31)
    stw	r4, 0xc9c(r31)
    stw	r4, 0xcac(r31)
    stw	r0, 0xc90(r31)
    stw	r0, 0xca0(r31)
    stw	r0, 0xc98(r31)
    stw	r0, 0xca8(r31)
    stw	r0, 0xc8c(r31)
    bl      OSResumeThread
    addi	r3, r31, 0x658
    bl      OSResumeThread
    addi	r3, r31, 0x28
    bl      OSResumeThread
    lis	r4, -0x7ffb
    li	r3, 6
    addi	r4, r4, -0x1628
    li	r5, 0
    bl      fn_80059028
_8004e790:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E7B4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80058EF4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E7D4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r5, -0x7fe8
    lis	r4, -0x7fed
    stw	r0, 0x24(r1)
    lis	r3, -0x7fed
    stw	r31, 0x1c(r1)
    addi	r31, r3, -0x46d0
    stw	r30, 0x18(r1)
    addi	r30, r4, -0x46e8
    stw	r29, 0x14(r1)
    addi	r29, r5, -0x1680
    b       _8004e870
_8004e808:
    lwz	r3, 0x1c(r29)
    addi	r0, r3, 1
    stw	r0, 0x1c(r29)
    bl      fn_80058C94
    cmpwi	r3, 0
    beq     _8004e82c
    lwz	r0, 0xc(r29)
    cmpwi	r0, 1
    bne     _8004e870
_8004e82c:
    lwz	r0, 0xc(r29)
    cmpwi	r0, 1
    bne     _8004e84c
    li	r0, 0
    lwz	r4, 0x14(r30)
    stw	r0, 0xc(r29)
    addi	r3, r29, 0x28
    bl      OSSetThreadPriority
_8004e84c:
    lis	r3, -0x7fed
    lwz	r12, -0x46d0(r3)
    cmplwi	r12, 0
    beq     _8004e868
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
_8004e868:
    addi	r3, r29, 0x28
    bl      OSSuspendThread
_8004e870:
    lwz	r0, 0xca4(r29)
    cmpwi	r0, 1
    beq     _8004e808
    li	r0, 1
    stw	r0, 0xca0(r29)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004E8A0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe8
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, -0x1680
    b       _8004e8d0
_8004e8bc:
    bl      fn_8001AF64
    lwz	r3, 0x18(r31)
    addi	r0, r3, 1
    stw	r0, 0x18(r31)
    bl      fn_80058DB4
_8004e8d0:
    lwz	r0, 0xc94(r31)
    cmpwi	r0, 1
    beq     _8004e8bc
    li	r0, 1
    stw	r0, 0xc90(r31)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004E8F8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r5, -0x7fe8
    lis	r4, -0x7fed
    stw	r0, 0x24(r1)
    lis	r3, -0x7fe8
    stw	r31, 0x1c(r1)
    addi	r31, r3, -0x7348
    stw	r30, 0x18(r1)
    addi	r30, r4, -0x46d0
    stw	r29, 0x14(r1)
    addi	r29, r5, -0x1680
    b       _8004e978
_8004e92c:
    bl      fn_8001AF64
    lwz	r4, 0x14(r29)
    lwz	r3, 0(r31)
    addi	r4, r4, 1
    addi	r0, r3, 1
    stw	r4, 0x14(r29)
    stw	r0, 0(r31)
    bl      fn_80058E44
    lwz	r0, 0xca0(r29)
    cmpwi	r0, 0
    bne     _8004e978
    addi	r3, r29, 0x28
    bl      OSResumeThread
    lwz	r12, 0(r30)
    cmplwi	r12, 0
    beq     _8004e978
    lwz	r3, 4(r30)
    mtctr	r12
    bctrl	
_8004e978:
    lwz	r0, 0xc9c(r29)
    cmpwi	r0, 1
    beq     _8004e92c
    li	r0, 1
    stw	r0, 0xc98(r29)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004E9A8(void)
{
    nofralloc
    lis	r3, -0x7fe8
    addi	r4, r3, -0x1680
    b       _8004e9c0
_8004e9b4:
    lwz	r3, 0x10(r4)
    addi	r0, r3, 1
    stw	r0, 0x10(r4)
_8004e9c0:
    lwz	r0, 0xcac(r4)
    cmpwi	r0, 1
    beq     _8004e9b4
    li	r0, 1
    stw	r0, 0xca8(r4)
    blr	
}

asm void fn_8004E9D8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r3, -0x7fe8
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r3, -0x1680
    stw	r29, 0x14(r1)
    lwz	r0, 0xca0(r30)
    cmpwi	r0, 1
    beq     _8004ea78
    lis	r3, -0x7fed
    li	r0, 1
    lwz	r4, -0x46e8(r3)
    addi	r3, r30, 0x28
    stw	r0, 0xc(r30)
    bl      OSSetThreadPriority
    lis	r3, 0xbec
    li	r29, 0
    addi	r31, r3, -0x3e00
    b       _8004ea44
_8004ea2c:
    addi	r3, r30, 0x28
    bl      OSResumeThread
    lwz	r0, 0xc(r30)
    cmpwi	r0, 0
    beq     _8004ea4c
    addi	r29, r29, 1
_8004ea44:
    cmpw	r29, r31
    blt     _8004ea2c
_8004ea4c:
    addis	r0, r29, -0xbeb
    cmplwi	r0, 0xc200
    bne     _8004ea64
    lis	r3, -0x7ff7
    addi	r3, r3, 0x1160
    bl      fn_800595A4
_8004ea64:
    lis	r4, -0x7fed
    addi	r3, r30, 0x28
    addi	r4, r4, -0x46e8
    lwz	r4, 0x14(r4)
    bl      OSSetThreadPriority
_8004ea78:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004EA94(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe8
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, -0x1680
    stw	r30, 8(r1)
    lwz	r3, 8(r31)
    addi	r0, r3, -1
    stw	r0, 8(r31)
    lwz	r0, 8(r31)
    cmpwi	r0, 0
    bne     _8004eae8
    bl      fn_800102AC
    mr	r0, r3
    addi	r3, r31, 0x970
    mr	r30, r0
    bl      OSSuspendThread
    lwz	r4, 0xc88(r31)
    mr	r3, r30
    bl      OSSetThreadPriority
_8004eae8:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EB00(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r3, -0x7fe8
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r3, -0x1680
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    lwz	r0, 8(r30)
    cmpwi	r0, 0
    bne     _8004eb88
    bl      OSDisableInterrupts
    mr	r29, r3
    bl      OSDisableScheduler
    li	r0, 1
    stw	r0, 0xc8c(r30)
    bl      fn_800102AC
    mr	r28, r3
    bl      fn_80011358
    lis	r4, -0x7fed
    mr	r31, r3
    addi	r4, r4, -0x46e8
    mr	r3, r28
    lwz	r4, 0(r4)
    bl      OSSetThreadPriority
    li	r0, 0
    stw	r31, 0xc88(r30)
    stw	r0, 0xc8c(r30)
    bl      OSEnableScheduler
    mr	r3, r29
    bl      OSRestoreInterrupts
    addi	r3, r30, 0x970
    bl      OSResumeThread
_8004eb88:
    lwz	r3, 8(r30)
    addi	r0, r3, 1
    stw	r0, 8(r30)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004EBB4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80059AB4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EBD4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80059B44
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EBF4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80058D24
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EC14(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8001AF64
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EC34(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r5, -0x7ff7
    lis	r4, -0x7ffb
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r5, 0x1198
    lwz	r0, 0x3c(r31)
    stw	r30, 8(r1)
    mr	r30, r3
    addi	r3, r4, -0x130c
    li	r4, 0
    bl      fn_8005466C
    lis	r4, -0x7ffa
    addi	r3, r31, 0x40
    addi	r4, r4, -0x5a58
    li	r5, 0
    bl      fn_80055304
    lis	r3, -0x7ffb
    li	r4, 0
    addi	r3, r3, -0x130c
    bl      fn_8005466C
    lis	r4, -0x7ffb
    addi	r3, r31, 0x44
    addi	r4, r4, 0x6584
    li	r5, 0
    bl      fn_80055304
    addi	r3, r31, 0x44
    bl      fn_800551D0
    cmplwi	r30, 0
    beq     _8004ecc8
    lwz	r6, 0(r30)
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      fn_800565F0
    b       _8004ecdc
_8004ecc8:
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    bl      fn_800565F0
_8004ecdc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004ECF4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    mr	r3, r4
    stw	r0, 0x14(r1)
    bl      fn_800474E4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004ED18(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 0xc(r3)
    bl      fn_8004ED3C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004ED3C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A668
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004ED5C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A680
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004ED80(void)
{
    nofralloc
    blr	
}

asm void fn_8004ED84(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A678
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EDA4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A688
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EDC4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A698
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EDE4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A74C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EE04(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A7F8
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EE24(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A94C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EE44(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A95C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EE64(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005B010
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EE84(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005B068
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EEA4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005B0C4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EEC4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005B264
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EEE4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r4, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      fn_8005B0C4
    mr	r3, r31
    li	r4, 0
    bl      fn_8005B264
    mr	r3, r31
    bl      fn_8005B464
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EF28(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005B534
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EF48(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005BE48
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EF68(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005BCB4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EF88(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005BDD4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004EFA8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r11, -0x7fe8
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    lwz	r0, -0x4fd8(r11)
    lwz	r31, 0x28(r1)
    cmpwi	r0, 0
    lha	r12, 0x2e(r1)
    lha	r11, 0x32(r1)
    bne     _8004efe8
    stw	r31, 8(r1)
    stw	r12, 0xc(r1)
    stw	r11, 0x10(r1)
    bl      fn_8004F00C
    b       _8004eff8
_8004efe8:
    stw	r31, 8(r1)
    stw	r12, 0xc(r1)
    stw	r11, 0x10(r1)
    bl      fn_8004F26C
_8004eff8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
