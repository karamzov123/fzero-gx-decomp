#pragma push
#pragma force_active on

extern void fn_8004E270(void);
extern void fn_80044C74(void);
extern void strncmp(void);
extern void fn_80044EF8(void);
extern void fn_800433A4(void);
extern void fn_80046020(void);
extern void fn_8004342C(void);
extern void fn_80043FA4(void);
extern void fn_8004251C(void);
extern void fn_8004E204(void);
extern void fn_8004E1E4(void);
extern void fn_8004E238(void);
extern void fn_8004E098(void);
extern void fn_8004E190(void);
extern void fn_8004E198(void);
extern unsigned char lbl_80090098[4];
extern unsigned char snd_str[5];

asm void fn_800443AC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r0, 4(r3)
    lwz	r31, 0x48(r3)
    cmpwi	r0, 1
    bne     _800446a0
    lwz	r3, 8(r30)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _800446a0
    lwz	r12, 0x78(r30)
    addi	r4, r30, 0x68
    addi	r5, r30, 0x6c
    addi	r6, r30, 0x70
    lwz	r3, 0x7c(r30)
    mtctr	r12
    bctrl	
    lwz	r4, 0x68(r30)
    lwz	r0, 0x60(r30)
    lwz	r3, 0x6c(r30)
    subf	r8, r4, r0
    cmpw	r8, r3
    ble     _8004441c
    mr	r8, r3
_8004441c:
    lwz	r0, 0x4c(r30)
    cmpw	r8, r0
    ble     _8004442c
    mr	r8, r0
_8004442c:
    lbz	r0, 0xe(r30)
    slwi	r3, r4, 1
    lwz	r5, 0x5c(r30)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r5, r3
    bne     _800445b0
    lwz	r3, 0x64(r30)
    cmpwi	r8, 0
    li	r7, 0
    add	r3, r3, r4
    slwi	r3, r3, 1
    add	r6, r5, r3
    ble     _80044684
    cmpwi	r8, 8
    addi	r10, r8, -8
    ble     _80044564
    addi	r9, r10, 7
    mr	r3, r31
    srwi	r9, r9, 3
    mr	r4, r0
    mr	r5, r6
    mtctr	r9
    cmpwi	r10, 0
    ble     _80044564
_80044490:
    lbz	r9, 0(r3)
    addi	r7, r7, 8
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0(r4)
    lbz	r9, 1(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0(r5)
    lbz	r9, 2(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 2(r4)
    lbz	r9, 3(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 2(r5)
    lbz	r9, 4(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 4(r4)
    lbz	r9, 5(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 4(r5)
    lbz	r9, 6(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 6(r4)
    lbz	r9, 7(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 6(r5)
    lbz	r9, 8(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 8(r4)
    lbz	r9, 9(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 8(r5)
    lbz	r9, 0xa(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xa(r4)
    lbz	r9, 0xb(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xa(r5)
    lbz	r9, 0xc(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xc(r4)
    lbz	r9, 0xd(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xc(r5)
    lbz	r9, 0xe(r3)
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xe(r4)
    addi	r4, r4, 0x10
    lbz	r9, 0xf(r3)
    addi	r3, r3, 0x10
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xe(r5)
    addi	r5, r5, 0x10
    bdnz    _80044490
_80044564:
    slwi	r9, r7, 1
    subf	r3, r7, r8
    add	r4, r31, r9
    add	r5, r0, r9
    add	r6, r6, r9
    mtctr	r3
    cmpw	r7, r8
    bge     _80044684
_80044584:
    lbz	r0, 0(r4)
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r5)
    addi	r5, r5, 2
    lbz	r0, 1(r4)
    addi	r4, r4, 2
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r6)
    addi	r6, r6, 2
    bdnz    _80044584
    b       _80044684
_800445b0:
    cmpwi	r8, 0
    li	r3, 0
    ble     _80044684
    cmpwi	r8, 8
    addi	r5, r8, -8
    ble     _80044650
    addi	r4, r5, 7
    mr	r6, r0
    srwi	r4, r4, 3
    mtctr	r4
    cmpwi	r5, 0
    ble     _80044650
_800445e0:
    add	r5, r31, r3
    addi	r3, r3, 8
    lbz	r4, 0(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 0(r6)
    lbz	r4, 1(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 2(r6)
    lbz	r4, 2(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 4(r6)
    lbz	r4, 3(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 6(r6)
    lbz	r4, 4(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 8(r6)
    lbz	r4, 5(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 0xa(r6)
    lbz	r4, 6(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 0xc(r6)
    lbz	r4, 7(r5)
    rlwinm	r4, r4, 8, 0x10, 0x17
    sth	r4, 0xe(r6)
    addi	r6, r6, 0x10
    bdnz    _800445e0
_80044650:
    slwi	r5, r3, 1
    subf	r4, r3, r8
    add	r6, r0, r5
    add	r5, r31, r3
    mtctr	r4
    cmpw	r3, r8
    bge     _80044684
_8004466c:
    lbz	r0, 0(r5)
    addi	r5, r5, 1
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r6)
    addi	r6, r6, 2
    bdnz    _8004466c
_80044684:
    stw	r8, 0x90(r30)
    li	r0, 2
    lbz	r3, 0xe(r30)
    extsb	r3, r3
    mullw	r3, r8, r3
    stw	r3, 0x94(r30)
    stw	r0, 4(r30)
_800446a0:
    lwz	r0, 4(r30)
    cmpwi	r0, 2
    bne     _800446cc
    lwz	r12, 0x80(r30)
    lwz	r3, 0x84(r30)
    lwz	r4, 0x94(r30)
    lwz	r5, 0x90(r30)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r30)
_800446cc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800446E4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    stw	r30, 8(r1)
    lwz	r0, 4(r3)
    lwz	r30, 0x48(r3)
    cmpwi	r0, 1
    bne     _80044a50
    lwz	r3, 8(r31)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _80044a50
    lwz	r12, 0x78(r31)
    addi	r4, r31, 0x68
    addi	r5, r31, 0x6c
    addi	r6, r31, 0x70
    lwz	r3, 0x7c(r31)
    mtctr	r12
    bctrl	
    lwz	r5, 0x68(r31)
    lwz	r0, 0x60(r31)
    lwz	r4, 0x6c(r31)
    subf	r3, r5, r0
    cmpw	r3, r4
    ble     _80044754
    mr	r3, r4
_80044754:
    lwz	r0, 0x4c(r31)
    cmpw	r3, r0
    ble     _80044764
    mr	r3, r0
_80044764:
    lbz	r0, 0xe(r31)
    slwi	r4, r5, 1
    lwz	r6, 0x5c(r31)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r6, r4
    bne     _80044934
    lwz	r4, 0x64(r31)
    cmpwi	r3, 0
    li	r8, 0
    add	r4, r4, r5
    slwi	r4, r4, 1
    add	r7, r6, r4
    ble     _80044a30
    cmpwi	r3, 8
    addi	r10, r3, -8
    ble     _800448dc
    addi	r9, r10, 7
    mr	r4, r30
    srwi	r9, r9, 3
    mr	r5, r0
    mr	r6, r7
    mtctr	r9
    cmpwi	r10, 0
    ble     _800448dc
_800447c8:
    lhz	r10, 0(r4)
    addi	r8, r8, 8
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0(r5)
    lhz	r10, 2(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0(r6)
    lhz	r10, 4(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 2(r5)
    lhz	r10, 6(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 2(r6)
    lhz	r10, 8(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 4(r5)
    lhz	r10, 0xa(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 4(r6)
    lhz	r10, 0xc(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 6(r5)
    lhz	r10, 0xe(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 6(r6)
    lhz	r10, 0x10(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 8(r5)
    lhz	r10, 0x12(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 8(r6)
    lhz	r10, 0x14(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0xa(r5)
    lhz	r10, 0x16(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0xa(r6)
    lhz	r10, 0x18(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0xc(r5)
    lhz	r10, 0x1a(r4)
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0xc(r6)
    lhz	r10, 0x1c(r4)
    rlwinm	r9, r10, 0x18, 0x18, 0x1f
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0xe(r5)
    addi	r5, r5, 0x10
    lhz	r10, 0x1e(r4)
    addi	r4, r4, 0x20
    srawi	r9, r10, 8
    rlwimi	r9, r10, 8, 8, 0x17
    sth	r9, 0xe(r6)
    addi	r6, r6, 0x10
    bdnz    _800447c8
_800448dc:
    slwi	r9, r8, 1
    slwi	r5, r8, 2
    subf	r4, r8, r3
    add	r5, r30, r5
    add	r6, r0, r9
    add	r7, r7, r9
    mtctr	r4
    cmpw	r8, r3
    bge     _80044a30
_80044900:
    lhz	r4, 0(r5)
    srawi	r0, r4, 8
    rlwimi	r0, r4, 8, 8, 0x17
    sth	r0, 0(r6)
    addi	r6, r6, 2
    lhz	r4, 2(r5)
    addi	r5, r5, 4
    srawi	r0, r4, 8
    rlwimi	r0, r4, 8, 8, 0x17
    sth	r0, 0(r7)
    addi	r7, r7, 2
    bdnz    _80044900
    b       _80044a30
_80044934:
    cmpwi	r3, 0
    li	r4, 0
    ble     _80044a30
    cmpwi	r3, 8
    addi	r6, r3, -8
    ble     _800449f8
    addi	r5, r6, 7
    mr	r7, r30
    srwi	r5, r5, 3
    mr	r8, r0
    mtctr	r5
    cmpwi	r6, 0
    ble     _800449f8
_80044968:
    lhz	r6, 0(r7)
    addi	r4, r4, 8
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 0(r8)
    lhz	r6, 2(r7)
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 2(r8)
    lhz	r6, 4(r7)
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 4(r8)
    lhz	r6, 6(r7)
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 6(r8)
    lhz	r6, 8(r7)
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 8(r8)
    lhz	r6, 0xa(r7)
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 0xa(r8)
    lhz	r6, 0xc(r7)
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 0xc(r8)
    lhz	r6, 0xe(r7)
    addi	r7, r7, 0x10
    srawi	r5, r6, 8
    rlwimi	r5, r6, 8, 8, 0x17
    sth	r5, 0xe(r8)
    addi	r8, r8, 0x10
    bdnz    _80044968
_800449f8:
    slwi	r7, r4, 1
    subf	r5, r4, r3
    add	r6, r30, r7
    add	r7, r0, r7
    mtctr	r5
    cmpw	r4, r3
    bge     _80044a30
_80044a14:
    lhz	r4, 0(r6)
    addi	r6, r6, 2
    srawi	r0, r4, 8
    rlwimi	r0, r4, 8, 8, 0x17
    sth	r0, 0(r7)
    addi	r7, r7, 2
    bdnz    _80044a14
_80044a30:
    stw	r3, 0x90(r31)
    slwi	r3, r3, 1
    li	r0, 2
    lbz	r4, 0xe(r31)
    extsb	r4, r4
    mullw	r3, r4, r3
    stw	r3, 0x94(r31)
    stw	r0, 4(r31)
_80044a50:
    lwz	r0, 4(r31)
    cmpwi	r0, 2
    bne     _80044a7c
    lwz	r12, 0x80(r31)
    lwz	r3, 0x84(r31)
    lwz	r4, 0x94(r31)
    lwz	r5, 0x90(r31)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r31)
_80044a7c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80044A94(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    cmpwi	r5, 8
    stw	r0, 0x34(r1)
    li	r0, 1
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    mr	r30, r3
    stw	r29, 0x24(r1)
    mr	r29, r4
    sth	r0, 2(r3)
    bge     _80044ad0
    li	r31, 0
    li	r5, -1
    b       _80044b68
_80044ad0:
    mr	r3, r29
    mr	r4, r5
    addi	r5, r1, 8
    addi	r6, r1, 0xc
    addi	r7, r1, 0x10
    addi	r8, r1, 0x14
    addi	r9, r1, 0x18
    bl      fn_80044C74
    cmplwi	r3, 0
    bne     _80044b00
    li	r5, -1
    b       _80044b68
_80044b00:
    subf	r0, r29, r3
    extsh.	r31, r0
    bgt     _80044b14
    li	r5, -1
    b       _80044b68
_80044b14:
    lwz	r4, 8(r1)
    li	r3, -1
    li	r0, 1
    li	r5, 0
    stw	r4, 0x14(r30)
    lwz	r4, 0xc(r1)
    stb	r4, 0xe(r30)
    lwz	r4, 0x10(r1)
    stb	r4, 0xd(r30)
    lwz	r4, 0x14(r1)
    stw	r4, 0x18(r30)
    stb	r3, 0xc(r30)
    lbz	r4, 0xe(r30)
    lbz	r3, 0xd(r30)
    extsb	r4, r4
    extsb	r3, r3
    mullw	r3, r4, r3
    srawi	r3, r3, 3
    addze	r3, r3
    stb	r3, 0xf(r30)
    stw	r0, 0x10(r30)
_80044b68:
    cmpwi	r5, 0
    bge     _80044b78
    li	r3, 0
    b       _80044bf0
_80044b78:
    li	r5, 0
    li	r0, 4
    sth	r5, 0x1c(r30)
    extsh	r3, r31
    sth	r5, 0x26(r30)
    sth	r5, 0x24(r30)
    stw	r5, 0x34(r30)
    stw	r5, 0x30(r30)
    stw	r5, 0x2c(r30)
    stw	r5, 0x28(r30)
    stw	r5, 0x20(r30)
    lbz	r4, 0xe(r30)
    extsb	r4, r4
    stw	r4, 0x50(r30)
    lbz	r4, 0xf(r30)
    extsb	r4, r4
    stw	r4, 0x54(r30)
    lwz	r4, 0x10(r30)
    stw	r4, 0x58(r30)
    lwz	r4, 0x3c(r30)
    stw	r4, 0x5c(r30)
    lwz	r4, 0x40(r30)
    stw	r4, 0x60(r30)
    lwz	r4, 0x44(r30)
    stw	r4, 0x64(r30)
    stw	r5, 0x8c(r30)
    stw	r5, 0x88(r30)
    sth	r0, 0x98(r30)
    lwz	r0, 0x18(r1)
    sth	r0, 0x9a(r30)
_80044bf0:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void CRI_WAVE_parser(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, snd_str@ha
    li	r5, 4
    stw	r0, 0x14(r1)
    addi	r4, r4, snd_str@l
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      strncmp
    cmpwi	r3, 0
    beq     _80044c54
    lis     r4, lbl_80090098@ha
    mr	r3, r31
    addi	r4, r4, lbl_80090098@l
    li	r5, 4
    bl      strncmp
    cmpwi	r3, 0
    bne     _80044c5c
_80044c54:
    li	r3, 1
    b       _80044c60
_80044c5c:
    li	r3, 0
_80044c60:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80044C74(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    lbz	r0, 1(r3)
    lbz	r10, 0(r3)
    rlwimi	r10, r0, 8, 0x10, 0x17
    lbz	r11, 2(r3)
    lbz	r0, 3(r3)
    rlwimi	r10, r11, 0x10, 8, 0xf
    rlwimi	r10, r0, 0x18, 0, 7
    addis	r0, r10, -0x64
    cmplwi	r0, 0x732e
    beq     _80044cb8
    addis	r0, r10, -0x646e
    cmplwi	r0, 0x732e
    beq     _80044cb8
    li	r3, 0
    b       _80044e70
_80044cb8:
    lbz	r0, 5(r3)
    lbz	r10, 4(r3)
    rlwimi	r10, r0, 8, 0x10, 0x17
    lbz	r11, 6(r3)
    lbz	r0, 7(r3)
    rlwimi	r10, r11, 0x10, 8, 0xf
    rlwimi	r10, r0, 0x18, 0, 7
    rlwinm	r0, r10, 0x18, 0x10, 0x17
    rlwimi	r0, r10, 8, 0x18, 0x1f
    rlwimi	r0, r10, 8, 8, 0xf
    rlwimi	r0, r10, 0x18, 0, 7
    cmpw	r0, r4
    ble     _80044cf4
    li	r3, 0
    b       _80044e70
_80044cf4:
    lbz	r4, 0xd(r3)
    lbz	r11, 0xe(r3)
    lbz	r10, 0xc(r3)
    rlwimi	r10, r4, 8, 0x10, 0x17
    rlwimi	r10, r11, 0x10, 8, 0xf
    lbz	r4, 0xf(r3)
    mr	r31, r10
    lbz	r11, 9(r3)
    rlwimi	r31, r4, 0x18, 0, 7
    lbz	r12, 8(r3)
    rlwimi	r12, r11, 8, 0x10, 0x17
    lbz	r10, 0xa(r3)
    rlwinm	r11, r31, 0x18, 0x10, 0x17
    lbz	r4, 0xb(r3)
    rlwimi	r11, r31, 8, 0x18, 0x1f
    rlwimi	r12, r10, 0x10, 8, 0xf
    rlwimi	r11, r31, 8, 8, 0xf
    rlwimi	r11, r31, 0x18, 0, 7
    mr	r10, r12
    rlwimi	r10, r4, 0x18, 0, 7
    rlwinm	r4, r10, 0x18, 0x10, 0x17
    cmpwi	r11, 2
    rlwimi	r4, r10, 8, 0x18, 0x1f
    rlwimi	r4, r10, 8, 8, 0xf
    rlwimi	r4, r10, 0x18, 0, 7
    beq     _80044d8c
    bge     _80044d6c
    cmpwi	r11, 1
    bge     _80044d78
    b       _80044db4
_80044d6c:
    cmpwi	r11, 4
    bge     _80044db4
    b       _80044da0
_80044d78:
    li	r11, 2
    li	r10, 8
    stw	r11, 0(r9)
    stw	r10, 0(r7)
    b       _80044dbc
_80044d8c:
    li	r11, 1
    li	r10, 8
    stw	r11, 0(r9)
    stw	r10, 0(r7)
    b       _80044dbc
_80044da0:
    li	r11, 0
    li	r10, 0x10
    stw	r11, 0(r9)
    stw	r10, 0(r7)
    b       _80044dbc
_80044db4:
    li	r3, 0
    b       _80044e70
_80044dbc:
    lbz	r7, 0x11(r3)
    lbz	r10, 0x10(r3)
    rlwimi	r10, r7, 8, 0x10, 0x17
    lbz	r11, 0x12(r3)
    lbz	r7, 0x13(r3)
    rlwimi	r10, r11, 0x10, 8, 0xf
    rlwimi	r10, r7, 0x18, 0, 7
    stw	r10, 0(r5)
    lwz	r10, 0(r5)
    stwbrx	r10, 0, r5
    lbz	r5, 0x15(r3)
    lbz	r7, 0x14(r3)
    rlwimi	r7, r5, 8, 0x10, 0x17
    lbz	r10, 0x16(r3)
    lbz	r5, 0x17(r3)
    rlwimi	r7, r10, 0x10, 8, 0xf
    rlwimi	r7, r5, 0x18, 0, 7
    stw	r7, 0(r6)
    lwz	r7, 0(r6)
    stwbrx	r7, 0, r6
    lwz	r5, 0(r9)
    cmpwi	r5, 2
    bne     _80044e28
    lwz	r5, 0(r6)
    divw	r4, r4, r5
    stw	r4, 0(r8)
    b       _80044e6c
_80044e28:
    cmpwi	r5, 1
    bne     _80044e40
    lwz	r5, 0(r6)
    divw	r4, r4, r5
    stw	r4, 0(r8)
    b       _80044e6c
_80044e40:
    cmpwi	r5, 0
    bne     _80044e64
    srwi	r7, r4, 0x1f
    lwz	r5, 0(r6)
    add	r4, r7, r4
    srawi	r4, r4, 1
    divw	r4, r4, r5
    stw	r4, 0(r8)
    b       _80044e6c
_80044e64:
    lis	r4, 0x7fff
    stw	r4, 0(r8)
_80044e6c:
    add	r3, r3, r0
_80044e70:
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80044E7C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lha	r4, 0x98(r3)
    extsh.	r0, r4
    bne     _80044e9c
    bl      fn_80044EF8
    b       _80044ee8
_80044e9c:
    cmpwi	r4, 0xa
    bne     _80044eac
    bl      fn_800433A4
    b       _80044ee8
_80044eac:
    cmpwi	r4, 2
    bne     _80044ebc
    bl      fn_80046020
    b       _80044ee8
_80044ebc:
    cmpwi	r4, 3
    bne     _80044ecc
    bl      fn_8004342C
    b       _80044ee8
_80044ecc:
    cmpwi	r4, 4
    bne     _80044edc
    bl      fn_80043FA4
    b       _80044ee8
_80044edc:
    cmpwi	r4, 1
    bne     _80044ee8
    bl      fn_8004251C
_80044ee8:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80044EF8(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r23, 0xc(r1)
    mr	r27, r3
    lwz	r0, 4(r3)
    cmpwi	r0, 1
    bne     _8004505c
    lwz	r3, 8(r27)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _8004505c
    lwz	r12, 0x78(r27)
    addi	r4, r27, 0x68
    addi	r5, r27, 0x6c
    addi	r6, r27, 0x70
    lwz	r3, 0x7c(r27)
    mtctr	r12
    bctrl	
    lwz	r7, 0x58(r27)
    lwz	r11, 0x70(r27)
    addi	r12, r7, -1
    lwz	r8, 0x68(r27)
    mr	r4, r12
    lwz	r24, 0x60(r27)
    add	r12, r11, r12
    lwz	r6, 0x4c(r27)
    divw	r10, r12, r7
    subf	r3, r8, r24
    lwz	r5, 0x50(r27)
    addi	r0, r3, -1
    lwz	r9, 0x6c(r27)
    add	r0, r7, r0
    divw	r3, r0, r7
    mullw	r0, r10, r7
    cmpw	r10, r3
    subf	r0, r0, r12
    subf	r4, r0, r4
    divw	r5, r6, r5
    mullw	r0, r3, r7
    bge     _80044fb0
    add	r0, r8, r0
    subf	r0, r4, r0
    cmpw	r0, r24
    bge     _80044fb0
    addi	r3, r3, 1
_80044fb0:
    cmpw	r11, r9
    bge     _80044fbc
    add	r9, r9, r4
_80044fbc:
    divw	r0, r9, r7
    cmpw	r5, r0
    ble     _80044fcc
    mr	r5, r0
_80044fcc:
    cmpw	r5, r10
    ble     _80044fd8
    mr	r5, r10
_80044fd8:
    cmpw	r5, r3
    ble     _80044fe4
    mr	r5, r3
_80044fe4:
    lwz	r0, 0x50(r27)
    cmpwi	r0, 2
    bne     _8004502c
    lwz	r3, 0x68(r27)
    slwi	r5, r5, 1
    lwz	r0, 0x64(r27)
    lwz	r6, 0x5c(r27)
    slwi	r7, r3, 1
    lwz	r24, 8(r27)
    slwi	r0, r0, 1
    add	r6, r6, r7
    lwz	r4, 0x48(r27)
    mr	r3, r24
    add	r7, r6, r0
    bl      fn_8004E204
    mr	r3, r24
    bl      fn_8004E1E4
    b       _80045054
_8004502c:
    lwz	r0, 0x68(r27)
    lwz	r24, 8(r27)
    lwz	r6, 0x5c(r27)
    slwi	r0, r0, 1
    lwz	r4, 0x48(r27)
    mr	r3, r24
    add	r6, r6, r0
    bl      fn_8004E238
    mr	r3, r24
    bl      fn_8004E1E4
_80045054:
    li	r0, 2
    stw	r0, 4(r27)
_8004505c:
    lwz	r0, 4(r27)
    cmpwi	r0, 2
    bne     _800452e8
    lwz	r3, 8(r27)
    bl      fn_8004E098
    lwz	r3, 8(r27)
    bl      fn_8004E270
    cmpwi	r3, 3
    bne     _800452e8
    lwz	r24, 0x58(r27)
    lwz	r3, 0x70(r27)
    addi	r23, r24, -1
    lwz	r25, 0x54(r27)
    mr	r0, r23
    lwz	r29, 0x68(r27)
    add	r23, r3, r23
    lwz	r28, 0x5c(r27)
    divw	r4, r23, r24
    lwz	r30, 0x40(r27)
    lwz	r31, 0x44(r27)
    lwz	r3, 8(r27)
    mullw	r4, r4, r24
    subf	r4, r4, r23
    subf	r26, r4, r0
    bl      fn_8004E190
    divw	r0, r23, r24
    lwz	r5, 0x50(r27)
    mullw	r4, r3, r24
    mullw	r0, r0, r5
    divw	r4, r4, r5
    cmpw	r0, r3
    bgt     _800450e0
    subf	r4, r26, r4
_800450e0:
    mullw	r0, r3, r25
    stw	r4, 0x90(r27)
    add	r29, r29, r4
    cmpw	r29, r30
    stw	r0, 0x94(r27)
    blt     _800452c0
    lwz	r0, 0x50(r27)
    subf	r29, r30, r29
    cmpwi	r0, 2
    bne     _80045234
    cmpwi	r29, 0
    slwi	r0, r30, 1
    mr	r4, r28
    mr	r3, r29
    add	r5, r28, r0
    ble     _80045198
    rlwinm.	r0, r29, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _80045180
_8004512c:
    lha	r0, 0(r5)
    sth	r0, 0(r4)
    lha	r0, 2(r5)
    sth	r0, 2(r4)
    lha	r0, 4(r5)
    sth	r0, 4(r4)
    lha	r0, 6(r5)
    sth	r0, 6(r4)
    lha	r0, 8(r5)
    sth	r0, 8(r4)
    lha	r0, 0xa(r5)
    sth	r0, 0xa(r4)
    lha	r0, 0xc(r5)
    sth	r0, 0xc(r4)
    lha	r0, 0xe(r5)
    addi	r5, r5, 0x10
    sth	r0, 0xe(r4)
    addi	r4, r4, 0x10
    bdnz    _8004512c
    andi.	r3, r3, 7
    beq     _80045198
_80045180:
    mtctr	r3
_80045184:
    lha	r0, 0(r5)
    addi	r5, r5, 2
    sth	r0, 0(r4)
    addi	r4, r4, 2
    bdnz    _80045184
_80045198:
    add	r0, r31, r30
    cmpwi	r29, 0
    slwi	r4, r0, 1
    mr	r3, r29
    slwi	r0, r31, 1
    add	r5, r28, r4
    add	r4, r28, r0
    ble     _800452c0
    rlwinm.	r0, r29, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _80045218
_800451c4:
    lha	r0, 0(r5)
    sth	r0, 0(r4)
    lha	r0, 2(r5)
    sth	r0, 2(r4)
    lha	r0, 4(r5)
    sth	r0, 4(r4)
    lha	r0, 6(r5)
    sth	r0, 6(r4)
    lha	r0, 8(r5)
    sth	r0, 8(r4)
    lha	r0, 0xa(r5)
    sth	r0, 0xa(r4)
    lha	r0, 0xc(r5)
    sth	r0, 0xc(r4)
    lha	r0, 0xe(r5)
    addi	r5, r5, 0x10
    sth	r0, 0xe(r4)
    addi	r4, r4, 0x10
    bdnz    _800451c4
    andi.	r3, r3, 7
    beq     _800452c0
_80045218:
    mtctr	r3
_8004521c:
    lha	r0, 0(r5)
    addi	r5, r5, 2
    sth	r0, 0(r4)
    addi	r4, r4, 2
    bdnz    _8004521c
    b       _800452c0
_80045234:
    cmpwi	r29, 0
    slwi	r0, r30, 1
    mr	r3, r29
    add	r4, r28, r0
    ble     _800452c0
    rlwinm.	r0, r29, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _800452a8
_80045254:
    lha	r0, 0(r4)
    sth	r0, 0(r28)
    lha	r0, 2(r4)
    sth	r0, 2(r28)
    lha	r0, 4(r4)
    sth	r0, 4(r28)
    lha	r0, 6(r4)
    sth	r0, 6(r28)
    lha	r0, 8(r4)
    sth	r0, 8(r28)
    lha	r0, 0xa(r4)
    sth	r0, 0xa(r28)
    lha	r0, 0xc(r4)
    sth	r0, 0xc(r28)
    lha	r0, 0xe(r4)
    addi	r4, r4, 0x10
    sth	r0, 0xe(r28)
    addi	r28, r28, 0x10
    bdnz    _80045254
    andi.	r3, r3, 7
    beq     _800452c0
_800452a8:
    mtctr	r3
_800452ac:
    lha	r0, 0(r4)
    addi	r4, r4, 2
    sth	r0, 0(r28)
    addi	r28, r28, 2
    bdnz    _800452ac
_800452c0:
    lwz	r3, 8(r27)
    bl      fn_8004E198
    lwz	r12, 0x80(r27)
    lwz	r3, 0x84(r27)
    lwz	r4, 0x94(r27)
    lwz	r5, 0x90(r27)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r27)
_800452e8:
    lmw	r23, 0xc(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
