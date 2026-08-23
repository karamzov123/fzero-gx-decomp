#pragma push
#pragma force_active on

asm void fn_80052430(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80052454:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, -0xe80(r3)
    lfs	f4, 8(r4)
    lfs	f2, -0xe00(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, -0xc80(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, -0xc00(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, -0xa80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, -0xa00(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x880(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80052530
    fmr	f0, f3
    b       _80052540
_80052530:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80052540
    fmr	f0, f2
_80052540:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80052454
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80052590(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_800525b4:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, -0xe00(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, -0xc80(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, -0xc00(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, -0xa80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, -0xa00(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x880(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80052690
    fmr	f0, f3
    b       _800526a0
_80052690:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _800526a0
    fmr	f0, f2
_800526a0:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _800525b4
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800526F0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80052714:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, -0xc80(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, -0xc00(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, -0xa80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, -0xa00(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x880(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _800527f0
    fmr	f0, f3
    b       _80052800
_800527f0:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80052800
    fmr	f0, f2
_80052800:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80052714
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80052850(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80052874:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, -0xc00(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, -0xa80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, -0xa00(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x880(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80052950
    fmr	f0, f3
    b       _80052960
_80052950:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80052960
    fmr	f0, f2
_80052960:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80052874
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800529B0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_800529d4:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, -0xa80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, -0xa00(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x880(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80052ab0
    fmr	f0, f3
    b       _80052ac0
_80052ab0:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80052ac0
    fmr	f0, f2
_80052ac0:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _800529d4
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80052B10(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80052b34:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, -0xa00(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x880(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80052c10
    fmr	f0, f3
    b       _80052c20
_80052c10:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80052c20
    fmr	f0, f2
_80052c20:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80052b34
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80052C70(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80052c94:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x880(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80052d70
    fmr	f0, f3
    b       _80052d80
_80052d70:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80052d80
    fmr	f0, f2
_80052d80:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80052c94
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80052DD0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80052df4:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, -0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80052ed0
    fmr	f0, f3
    b       _80052ee0
_80052ed0:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80052ee0
    fmr	f0, f2
_80052ee0:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80052df4
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80052F30(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80052f54:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, -0x680(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80053030
    fmr	f0, f3
    b       _80053040
_80053030:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80053040
    fmr	f0, f2
_80053040:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80052f54
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80053090(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_800530b4:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, 0x980(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, -0x600(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80053190
    fmr	f0, f3
    b       _800531a0
_80053190:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _800531a0
    fmr	f0, f2
_800531a0:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _800530b4
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800531F0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80053214:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, 0x980(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, 0xa00(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, -0x480(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _800532f0
    fmr	f0, f3
    b       _80053300
_800532f0:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80053300
    fmr	f0, f2
_80053300:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80053214
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80053350(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80053374:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, 0x980(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, 0xa00(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, 0xb80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, -0x400(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80053450
    fmr	f0, f3
    b       _80053460
_80053450:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80053460
    fmr	f0, f2
_80053460:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80053374
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800534B0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_800534d4:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, 0x980(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, 0xa00(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, 0xb80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, 0xc00(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, -0x280(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _800535b0
    fmr	f0, f3
    b       _800535c0
_800535b0:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _800535c0
    fmr	f0, f2
_800535c0:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _800534d4
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80053610(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80053634:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, 0x980(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, 0xa00(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, 0xb80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, 0xc00(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0xd80(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, -0x200(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80053710
    fmr	f0, f3
    b       _80053720
_80053710:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80053720
    fmr	f0, f2
_80053720:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80053634
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80053770(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_80053794:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, 0x980(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, 0xa00(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, 0xb80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, 0xc00(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0xd80(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, 0xe00(r3)
    lfs	f2, -0x80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _80053870
    fmr	f0, f3
    b       _80053880
_80053870:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _80053880
    fmr	f0, f2
_80053880:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _80053794
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800538D0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f31, 0x20(r1)
    psq_st	f31, 0x28(r1), 0, 0
    lis	r6, -0x7ff7
    li	r8, 0x20
    addi	r7, r6, 0x1338
    lfd	f1, 0x10(r7)
    lis	r6, 0x4330
    lfs	f3, 4(r7)
_800538f4:
    lfs	f0, 0(r7)
    lfs	f4, 0(r4)
    lfs	f2, 0(r3)
    lfs	f6, 4(r4)
    fmadds	f0, f4, f2, f0
    lfs	f5, 0x180(r3)
    lfs	f4, 8(r4)
    lfs	f2, 0x200(r3)
    fmadds	f0, f6, f5, f0
    lfs	f8, 0xc(r4)
    lfs	f7, 0x380(r3)
    lfs	f6, 0x10(r4)
    fmadds	f0, f4, f2, f0
    lfs	f4, 0x400(r3)
    lfs	f5, 0x14(r4)
    lfs	f2, 0x580(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x18(r4)
    lfs	f9, 0x600(r3)
    lfs	f8, 0x1c(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0x780(r3)
    lfs	f6, 0x20(r4)
    lfs	f4, 0x800(r3)
    fmadds	f0, f5, f2, f0
    lfs	f5, 0x24(r4)
    lfs	f2, 0x980(r3)
    lfs	f31, 0x28(r4)
    fmadds	f0, f10, f9, f0
    lfs	f13, 0xa00(r3)
    lfs	f12, 0x2c(r4)
    lfs	f11, 0xb80(r3)
    fmadds	f0, f8, f7, f0
    lfs	f10, 0x30(r4)
    lfs	f9, 0xc00(r3)
    lfs	f8, 0x34(r4)
    fmadds	f0, f6, f4, f0
    lfs	f7, 0xd80(r3)
    lfs	f6, 0x38(r4)
    lfs	f4, 0x3c(r4)
    addi	r4, r4, 0x40
    fmadds	f0, f5, f2, f0
    lfs	f5, 0xe00(r3)
    lfs	f2, 0xf80(r3)
    addi	r3, r3, 4
    fmadds	f0, f31, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f2, f0
    fcmpo	cr0, f0, f3
    ble     _800539d0
    fmr	f0, f3
    b       _800539e0
_800539d0:
    lfs	f2, 8(r7)
    fcmpo	cr0, f0, f2
    bge     _800539e0
    fmr	f0, f2
_800539e0:
    fctiwz	f0, f0
    stw	r6, 0x10(r1)
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    srawi	r0, r0, 0x10
    xoris	r0, r0, 0x8000
    addic.	r8, r8, -1
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    sth	r0, 0(r5)
    addi	r5, r5, 2
    bne     _800538f4
    psq_l	f31, 0x28(r1), 0, 0
    lfd	f31, 0x20(r1)
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
