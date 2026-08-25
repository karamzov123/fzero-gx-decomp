typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

extern void OSRegisterVersion(void);
extern void __OSSetInterruptHandler(void);
extern void __OSUnmaskInterrupts(void);
extern void __OSLockSram(void);
extern void __OSUnlockSram(void);
extern void OSInitThreadQueue(void);
extern void fn_8001A814(void);
extern void fn_8001A55C(void);
extern unsigned char lbl_8015CF68[240];

extern unsigned char CurrTvMode[4];
extern unsigned char lbl_801A64A0[4];
extern unsigned char lbl_801A6920[4];
extern unsigned char lbl_801A6924[4];
extern unsigned char lbl_801A6928[4];
extern unsigned char lbl_801A6934[4];
extern unsigned char lbl_801A6938[4];
extern unsigned char lbl_801A693C[4];
extern unsigned char lbl_801A6940[2];
extern unsigned char lbl_801A6942[2];
extern unsigned char lbl_801A6944[4];
extern unsigned char lbl_801A6948[4];
extern unsigned char lbl_801A694C[4];
extern unsigned char lbl_801A6950[8];
extern unsigned char lbl_801A6958[4];
extern unsigned char lbl_801A695C[4];
extern unsigned char lbl_801A6960[4];
asm void fn_8001A8B4(void);
asm void fn_8001AAB4(void);

asm void fn_8001A8B4(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    srwi	r31, r3, 2
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    addi	r29, r3, 0
    lis	r3, -0x8000
    stw	r31, 0xcc(r3)
    addi	r3, r29, 0
    rlwinm	r30, r29, 0, 0x1e, 0x1e
    bl      fn_8001A814
    lis	r4, -0x3400
    li	r0, 2
    addi	r5, r4, 0x2000
    sthu	r0, 2(r5)
    li	r0, 0
    stw	r0, 0x1c(r1)
    lwz	r0, 0x1c(r1)
    cmplwi	r0, 0x3e8
    bc      4, 0, _8001a928
    b       _8001a91c
_8001a910:
    lwz	r4, 0x1c(r1)
    addi	r0, r4, 8
    stw	r0, 0x1c(r1)
_8001a91c:
    lwz	r0, 0x1c(r1)
    cmplwi	r0, 0x3e8
    bc      12, 0, _8001a910
_8001a928:
    li	r0, 0
    sth	r0, 0(r5)
    lis	r12, -0x3400
    li	r8, 0x2828
    lhz	r6, 0x1a(r3)
    li	r7, 1
    cmpwi	r29, 2
    sth	r6, 0x2006(r12)
    li	r6, 0x1001
    addi	r4, r12, 0x2000
    lbz	r9, 0x1d(r3)
    lbz	r10, 0x1e(r3)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0x2004(r12)
    lbz	r9, 0x1f(r3)
    lbz	r10, 0x1c(r3)
    slwi	r9, r9, 7
    or	r9, r10, r9
    sth	r9, 0x200a(r12)
    lhz	r9, 0x20(r3)
    rlwinm	r9, r9, 1, 0x10, 0x1e
    sth	r9, 0x2008(r12)
    lhz	r9, 2(r3)
    lbz	r11, 0(r3)
    slwi	r9, r9, 1
    lhz	r10, 4(r3)
    addi	r9, r9, -2
    sth	r11, 0x2000(r12)
    add	r9, r10, r9
    sth	r9, 0x200e(r12)
    lhz	r9, 8(r3)
    addi	r9, r9, 2
    sth	r9, 0x200c(r12)
    lhz	r9, 2(r3)
    lhz	r10, 6(r3)
    slwi	r9, r9, 1
    addi	r9, r9, -2
    add	r9, r10, r9
    sth	r9, 0x2012(r12)
    lhz	r9, 0xa(r3)
    addi	r9, r9, 2
    sth	r9, 0x2010(r12)
    lhz	r9, 0x10(r3)
    lbz	r10, 0xc(r3)
    slwi	r9, r9, 5
    or	r9, r10, r9
    sth	r9, 0x2016(r12)
    lhz	r9, 0x14(r3)
    lbz	r10, 0xe(r3)
    slwi	r9, r9, 5
    or	r9, r10, r9
    sth	r9, 0x2014(r12)
    lhz	r9, 0x12(r3)
    lbz	r10, 0xd(r3)
    slwi	r9, r9, 5
    or	r9, r10, r9
    sth	r9, 0x201a(r12)
    lhz	r9, 0x16(r3)
    lbz	r10, 0xf(r3)
    slwi	r9, r9, 5
    or	r9, r10, r9
    sth	r9, 0x2018(r12)
    sth	r8, 0x2048(r12)
    sth	r7, 0x2036(r12)
    sth	r6, 0x2034(r12)
    lhz	r6, 0x18(r3)
    lhz	r3, 0x1a(r3)
    srawi	r6, r6, 1
    addi	r3, r3, 1
    addze	r6, r6
    sth	r3, 0x2032(r12)
    addi	r6, r6, 1
    ori	r3, r6, 0x1000
    sth	r3, 0x2030(r12)
    bc      12, 2, _8001aa80
    cmpwi	r29, 3
    bc      12, 2, _8001aa80
    cmpwi	r29, 0x1a
    bc      12, 2, _8001aa80
    slwi	r3, r30, 2
    ori	r6, r3, 1
    slwi	r3, r31, 8
    or	r3, r6, r3
    sth	r3, 0(r5)
    sth	r0, 0x6c(r4)
    b       _8001aa98
_8001aa80:
    slwi	r0, r31, 8
    ori	r0, r0, 5
    sth	r0, 0(r5)
    lis	r3, -0x3400
    li	r0, 1
    sth	r0, 0x206c(r3)
_8001aa98:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr
}

asm void fn_8001AAB4(void)
{
    nofralloc
    mflr	r0
    lis	r4, -0x7fee
    stw	r0, 4(r1)
    lis     r3, lbl_8015CF68@ha
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    addi	r30, r3, lbl_8015CF68@l
    stw	r29, 0xc(r1)
    addi	r29, r4, 0x41c8
    stw	r28, 8(r1)
    lwz	r0, lbl_801A6920
    cmpwi	r0, 0
    bc      4, 2, _8001af44
    lwz	r3, lbl_801A64A0
    bl      OSRegisterVersion
    li	r0, 1
    stw	r0, lbl_801A6920
    lis	r3, -0x3400
    addi	r28, r3, 0x2000
    stw	r0, lbl_801A693C
    lhzu	r0, 2(r28)
    clrlwi.	r0, r0, 0x1f
    bc      4, 2, _8001ab1c
    li	r3, 0
    bl      fn_8001A8B4
_8001ab1c:
    li	r31, 0
    stw	r31, lbl_801A6924
    lis	r3, -0x3400
    addi	r3, r3, 0x2000
    stw	r31, lbl_801A694C
    li	r0, 0x280
    stw	r31, lbl_801A6948
    stw	r31, lbl_801A695C
    stw	r31, lbl_801A6958
    stw	r31, lbl_801A6944
    stw	r31, lbl_801A6950
    stw	r31, lbl_801A6928
    lhz	r5, 0x1c2(r29)
    lhz	r6, 0x1c0(r29)
    rlwinm	r5, r5, 0xa, 0x10, 0x15
    or	r5, r6, r5
    sth	r5, 0x4e(r3)
    lhz	r6, 0x1c2(r29)
    lhz	r5, 0x1c4(r29)
    srawi	r6, r6, 6
    slwi	r5, r5, 4
    or	r5, r6, r5
    sth	r5, 0x4c(r3)
    lhz	r5, 0x1c8(r29)
    lhz	r6, 0x1c6(r29)
    rlwinm	r5, r5, 0xa, 0x10, 0x15
    or	r5, r6, r5
    sth	r5, 0x52(r3)
    lhz	r6, 0x1c8(r29)
    lhz	r5, 0x1ca(r29)
    srawi	r6, r6, 6
    slwi	r5, r5, 4
    or	r5, r6, r5
    sth	r5, 0x50(r3)
    lhz	r5, 0x1ce(r29)
    lhz	r6, 0x1cc(r29)
    rlwinm	r5, r5, 0xa, 0x10, 0x15
    or	r5, r6, r5
    sth	r5, 0x56(r3)
    lhz	r5, 0x1ce(r29)
    lhz	r4, 0x1d0(r29)
    srawi	r5, r5, 6
    slwi	r4, r4, 4
    or	r4, r5, r4
    sth	r4, 0x54(r3)
    lhz	r4, 0x1d4(r29)
    lhz	r5, 0x1d2(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x5a(r3)
    lhz	r4, 0x1d8(r29)
    lhz	r5, 0x1d6(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x58(r3)
    lhz	r4, 0x1dc(r29)
    lhz	r5, 0x1da(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x5e(r3)
    lhz	r4, 0x1e0(r29)
    lhz	r5, 0x1de(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x5c(r3)
    lhz	r4, 0x1e4(r29)
    lhz	r5, 0x1e2(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x62(r3)
    lhz	r4, 0x1e8(r29)
    lhz	r5, 0x1e6(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x60(r3)
    lhz	r4, 0x1ec(r29)
    lhz	r5, 0x1ea(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x66(r3)
    lhz	r4, 0x1f0(r29)
    lhz	r5, 0x1ee(r29)
    slwi	r4, r4, 8
    or	r4, r5, r4
    sth	r4, 0x64(r3)
    sth	r0, 0x70(r3)
    bl      __OSLockSram
    lbz	r0, 0x10(r3)
    li	r3, 0
    extsb	r0, r0
    sth	r31, lbl_801A6942
    sth	r0, lbl_801A6940
    bl      __OSUnlockSram
    lhz	r29, 0(r28)
    lis	r3, -0x8000
    lwz	r3, 0xcc(r3)
    addi	r4, r30, 0x114
    rlwinm	r0, r29, 0x1e, 0x1f, 0x1f
    stw	r0, 0x114(r30)
    rlwinm	r0, r29, 0x18, 0x1e, 0x1f
    cmplwi	r3, 1
    stw	r0, 0x118(r30)
    addi	r28, r30, 0x118
    bc      4, 2, _8001acd0
    lwz	r0, 0(r28)
    cmplwi	r0, 0
    bc      4, 2, _8001acd0
    li	r0, 5
    stw	r0, 0(r28)
_8001acd0:
    lwz	r3, 0(r28)
    cmplwi	r3, 3
    bc      4, 2, _8001ace0
    li	r3, 0
_8001ace0:
    lwz	r0, 0(r4)
    slwi	r3, r3, 2
    add	r3, r3, r0
    bl      fn_8001A814
    stw	r3, 0x144(r30)
    addi	r4, r30, 0x144
    li	r0, 0x280
    sth	r29, 2(r30)
    li	r8, 0
    addi	r6, r30, 0xf6
    lwz	r4, 0(r4)
    addi	r3, r30, 0xf2
    stw	r4, lbl_801A6960
    lwz	r4, 0(r28)
    stw	r4, CurrTvMode
    sth	r0, 0xf4(r30)
    lwz	r4, lbl_801A6960
    lhzu	r0, 2(r4)
    rlwinm	r0, r0, 1, 0x10, 0x1e
    sth	r0, 0xf6(r30)
    lhz	r0, 0xf4(r30)
    subfic	r0, r0, 0x2d0
    srawi	r0, r0, 1
    addze	r0, r0
    sth	r0, 0xf0(r30)
    sth	r8, 0xf2(r30)
    lhz	r0, 0xf4(r30)
    lha	r7, 0xf0(r30)
    lha	r5, -0x7a80(r13)
    subfic	r0, r0, 0x2d0
    lhz	r9, 0(r4)
    add	r5, r7, r5
    cmpw	r5, r0
    bc      4, 1, _8001ad6c
    b       _8001ad80
_8001ad6c:
    cmpwi	r5, 0
    bc      4, 0, _8001ad78
    b       _8001ad7c
_8001ad78:
    mr	r8, r5
_8001ad7c:
    mr	r0, r8
_8001ad80:
    sth	r0, 0xf8(r30)
    addi	r8, r30, 0x110
    lwz	r0, 0x110(r30)
    cmpwi	r0, 0
    bc      4, 2, _8001ad9c
    li	r11, 2
    b       _8001ada0
_8001ad9c:
    li	r11, 1
_8001ada0:
    lhz	r0, 0(r3)
    lha	r5, -0x7a7e(r13)
    extsh	r7, r0
    clrlwi	r0, r0, 0x1f
    add	r7, r7, r5
    cmpw	r7, r0
    bc      4, 1, _8001adc0
    b       _8001adc4
_8001adc0:
    mr	r7, r0
_8001adc4:
    sth	r7, 0xfa(r30)
    extsh	r7, r9
    slwi	r7, r7, 1
    lhz	r28, 0(r6)
    subf	r12, r0, r7
    lha	r10, 0(r3)
    extsh	r7, r28
    add	r9, r7, r5
    add	r9, r10, r9
    subf.	r7, r12, r9
    bc      4, 1, _8001adf8
    subf	r9, r12, r9
    b       _8001adfc
_8001adf8:
    li	r9, 0
_8001adfc:
    add	r10, r10, r5
    subf.	r7, r0, r10
    bc      4, 0, _8001ae10
    subf	r7, r0, r10
    b       _8001ae14
_8001ae10:
    li	r7, 0
_8001ae14:
    add	r7, r28, r7
    subf	r7, r9, r7
    sth	r7, 0xfc(r30)
    lha	r7, 0(r3)
    add	r9, r7, r5
    subf.	r7, r0, r9
    bc      4, 0, _8001ae38
    subf	r7, r0, r9
    b       _8001ae3c
_8001ae38:
    li	r7, 0
_8001ae3c:
    divw	r10, r7, r11
    addi	r7, r30, 0x108
    lhz	r9, 0x108(r30)
    subf	r9, r10, r9
    sth	r9, 0xfe(r30)
    lha	r6, 0(r6)
    lha	r9, 0(r3)
    add	r6, r6, r5
    add	r6, r9, r6
    subf.	r3, r12, r6
    bc      4, 1, _8001ae70
    subf	r6, r12, r6
    b       _8001ae74
_8001ae70:
    li	r6, 0
_8001ae74:
    add	r5, r9, r5
    subf.	r3, r0, r5
    bc      4, 0, _8001ae88
    subf	r0, r0, r5
    b       _8001ae8c
_8001ae88:
    li	r0, 0
_8001ae8c:
    divw	r0, r0, r11
    lhz	r3, 0x10c(r30)
    add	r0, r3, r0
    divw	r5, r6, r11
    subf	r0, r5, r0
    sth	r0, 0x100(r30)
    li	r9, 0x280
    li	r28, 0
    sth	r9, 0x102(r30)
    li	r5, 0x28
    li	r0, 1
    lhz	r6, 0(r4)
    addi	r3, r13, -0x7a94
    rlwinm	r6, r6, 1, 0x10, 0x1e
    sth	r6, 0x104(r30)
    sth	r28, 0x106(r30)
    sth	r28, 0(r7)
    sth	r9, 0x10a(r30)
    lhz	r4, 0(r4)
    rlwinm	r4, r4, 1, 0x10, 0x1e
    sth	r4, 0x10c(r30)
    stw	r28, 0(r8)
    stb	r5, 0x11c(r30)
    stb	r5, 0x11d(r30)
    stb	r5, 0x11e(r30)
    stb	r28, 0x12c(r30)
    stw	r0, 0x130(r30)
    stw	r28, 0x134(r30)
    bl      OSInitThreadQueue
    lis	r3, -0x3400
    lhz	r0, 0x2030(r3)
    addi	r4, r3, 0x2000
    addi	r5, r3, 0x2000
    clrlwi	r0, r0, 0x11
    sth	r0, 0x30(r4)
    lis     r3, fn_8001A55C@ha
    addi	r4, r3, fn_8001A55C@l
    lhz	r0, 0x34(r5)
    li	r3, 0x18
    clrlwi	r0, r0, 0x11
    sth	r0, 0x34(r5)
    stw	r28, lbl_801A6934
    stw	r28, lbl_801A6938
    bl      __OSSetInterruptHandler
    li	r3, 0x80
    bl      __OSUnmaskInterrupts
_8001af44:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    lwz	r29, 0xc(r1)
    lwz	r28, 8(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

#pragma force_active off
