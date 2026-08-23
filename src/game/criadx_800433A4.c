#pragma push
#pragma force_active on

extern void fn_80043460(void);
extern void fn_80043798(void);
extern void fn_8004E270(void);
extern void fn_80043D34(void);
extern void fn_8008023C(void);
extern void fn_80043FE8(void);
extern void fn_800443AC(void);
extern void fn_800446E4(void);
extern unsigned char AIFF_str[5];
extern unsigned char FORM_str[5];
extern unsigned char lbl_8012B6F8[512];

asm void fn_800433A4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r4, -0x7fe8
    stw	r0, 0x14(r1)
    lwz	r12, -0x5d80(r4)
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800433D0(void)
{
    nofralloc
    lis	r5, 0x2aab
    stw	r4, 0xb4(r3)
    addi	r0, r5, -0x5555
    mulhw	r0, r0, r4
    srawi	r0, r0, 4
    srwi	r4, r0, 0x1f
    add	r0, r0, r4
    stw	r0, 0xb8(r3)
    blr	
}

asm void fn_800433F4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 0xb0(r3)
    cmplwi	r3, 0
    beq     _8004341c
    lis	r5, -0x7fe8
    lwz	r12, -0x5d7c(r5)
    mtctr	r12
    bctrl	
_8004341c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004342C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lha	r0, 0x9a(r3)
    cmpwi	r0, 1
    bne     _8004344c
    bl      fn_80043460
    b       _80043450
_8004344c:
    bl      fn_80043798
_80043450:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80043460(void)
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
    bne     _80043754
    lwz	r3, 8(r30)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _80043754
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
    ble     _800434d0
    mr	r8, r3
_800434d0:
    lwz	r0, 0x4c(r30)
    cmpw	r8, r0
    ble     _800434e0
    mr	r8, r0
_800434e0:
    lbz	r0, 0xe(r30)
    slwi	r3, r4, 1
    lwz	r5, 0x5c(r30)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r5, r3
    bne     _80043664
    lwz	r3, 0x64(r30)
    cmpwi	r8, 0
    li	r7, 0
    add	r3, r3, r4
    slwi	r3, r3, 1
    add	r6, r5, r3
    ble     _80043738
    cmpwi	r8, 8
    addi	r10, r8, -8
    ble     _80043618
    addi	r9, r10, 7
    mr	r3, r31
    srwi	r9, r9, 3
    mr	r4, r0
    mr	r5, r6
    mtctr	r9
    cmpwi	r10, 0
    ble     _80043618
_80043544:
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
    bdnz    _80043544
_80043618:
    slwi	r9, r7, 1
    subf	r3, r7, r8
    add	r4, r31, r9
    add	r5, r0, r9
    add	r6, r6, r9
    mtctr	r3
    cmpw	r7, r8
    bge     _80043738
_80043638:
    lbz	r0, 0(r4)
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r5)
    addi	r5, r5, 2
    lbz	r0, 1(r4)
    addi	r4, r4, 2
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r6)
    addi	r6, r6, 2
    bdnz    _80043638
    b       _80043738
_80043664:
    cmpwi	r8, 0
    li	r3, 0
    ble     _80043738
    cmpwi	r8, 8
    addi	r5, r8, -8
    ble     _80043704
    addi	r4, r5, 7
    mr	r6, r0
    srwi	r4, r4, 3
    mtctr	r4
    cmpwi	r5, 0
    ble     _80043704
_80043694:
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
    bdnz    _80043694
_80043704:
    slwi	r5, r3, 1
    subf	r4, r3, r8
    add	r6, r0, r5
    add	r5, r31, r3
    mtctr	r4
    cmpw	r3, r8
    bge     _80043738
_80043720:
    lbz	r0, 0(r5)
    addi	r5, r5, 1
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r6)
    addi	r6, r6, 2
    bdnz    _80043720
_80043738:
    stw	r8, 0x90(r30)
    li	r0, 2
    lbz	r3, 0xe(r30)
    extsb	r3, r3
    mullw	r3, r8, r3
    stw	r3, 0x94(r30)
    stw	r0, 4(r30)
_80043754:
    lwz	r0, 4(r30)
    cmpwi	r0, 2
    bne     _80043780
    lwz	r12, 0x80(r30)
    lwz	r3, 0x84(r30)
    lwz	r4, 0x94(r30)
    lwz	r5, 0x90(r30)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r30)
_80043780:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80043798(void)
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
    bne     _80043b04
    lwz	r3, 8(r31)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _80043b04
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
    ble     _80043808
    mr	r3, r4
_80043808:
    lwz	r0, 0x4c(r31)
    cmpw	r3, r0
    ble     _80043818
    mr	r3, r0
_80043818:
    lbz	r0, 0xe(r31)
    slwi	r4, r5, 1
    lwz	r6, 0x5c(r31)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r6, r4
    bne     _800439e8
    lwz	r4, 0x64(r31)
    cmpwi	r3, 0
    li	r8, 0
    add	r4, r4, r5
    slwi	r4, r4, 1
    add	r7, r6, r4
    ble     _80043ae4
    cmpwi	r3, 8
    addi	r10, r3, -8
    ble     _80043990
    addi	r9, r10, 7
    mr	r4, r30
    srwi	r9, r9, 3
    mr	r5, r0
    mr	r6, r7
    mtctr	r9
    cmpwi	r10, 0
    ble     _80043990
_8004387c:
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
    bdnz    _8004387c
_80043990:
    slwi	r9, r8, 1
    slwi	r5, r8, 2
    subf	r4, r8, r3
    add	r5, r30, r5
    add	r6, r0, r9
    add	r7, r7, r9
    mtctr	r4
    cmpw	r8, r3
    bge     _80043ae4
_800439b4:
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
    bdnz    _800439b4
    b       _80043ae4
_800439e8:
    cmpwi	r3, 0
    li	r4, 0
    ble     _80043ae4
    cmpwi	r3, 8
    addi	r6, r3, -8
    ble     _80043aac
    addi	r5, r6, 7
    mr	r7, r30
    srwi	r5, r5, 3
    mr	r8, r0
    mtctr	r5
    cmpwi	r6, 0
    ble     _80043aac
_80043a1c:
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
    bdnz    _80043a1c
_80043aac:
    slwi	r7, r4, 1
    subf	r5, r4, r3
    add	r6, r30, r7
    add	r7, r0, r7
    mtctr	r5
    cmpw	r4, r3
    bge     _80043ae4
_80043ac8:
    lhz	r4, 0(r6)
    addi	r6, r6, 2
    srawi	r0, r4, 8
    rlwimi	r0, r4, 8, 8, 0x17
    sth	r0, 0(r7)
    addi	r7, r7, 2
    bdnz    _80043ac8
_80043ae4:
    stw	r3, 0x90(r31)
    slwi	r3, r3, 1
    li	r0, 2
    lbz	r4, 0xe(r31)
    extsb	r4, r4
    mullw	r3, r4, r3
    stw	r3, 0x94(r31)
    stw	r0, 4(r31)
_80043b04:
    lwz	r0, 4(r31)
    cmpwi	r0, 2
    bne     _80043b30
    lwz	r12, 0x80(r31)
    lwz	r3, 0x84(r31)
    lwz	r4, 0x94(r31)
    lwz	r5, 0x90(r31)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r31)
_80043b30:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80043B48(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    cmpwi	r5, 0x1000
    stw	r0, 0x34(r1)
    li	r0, 1
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    mr	r30, r3
    stw	r29, 0x24(r1)
    mr	r29, r4
    sth	r0, 2(r3)
    bge     _80043b84
    li	r31, 0
    li	r5, -1
    b       _80043c14
_80043b84:
    mr	r3, r29
    addi	r4, r1, 8
    addi	r5, r1, 0xc
    addi	r6, r1, 0x10
    addi	r7, r1, 0x14
    bl      fn_80043D34
    cmplwi	r3, 0
    bne     _80043bac
    li	r5, -1
    b       _80043c14
_80043bac:
    subf	r0, r29, r3
    extsh.	r31, r0
    bgt     _80043bc0
    li	r5, -1
    b       _80043c14
_80043bc0:
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
_80043c14:
    cmpwi	r5, 0
    bge     _80043c24
    li	r3, 0
    b       _80043cb0
_80043c24:
    li	r4, 0
    li	r0, 3
    sth	r4, 0x1c(r30)
    sth	r4, 0x26(r30)
    sth	r4, 0x24(r30)
    stw	r4, 0x34(r30)
    stw	r4, 0x30(r30)
    stw	r4, 0x2c(r30)
    stw	r4, 0x28(r30)
    stw	r4, 0x20(r30)
    lbz	r3, 0xe(r30)
    extsb	r3, r3
    stw	r3, 0x50(r30)
    lbz	r3, 0xf(r30)
    extsb	r3, r3
    stw	r3, 0x54(r30)
    lwz	r3, 0x10(r30)
    stw	r3, 0x58(r30)
    lwz	r3, 0x3c(r30)
    stw	r3, 0x5c(r30)
    lwz	r3, 0x40(r30)
    stw	r3, 0x60(r30)
    lwz	r3, 0x44(r30)
    stw	r3, 0x64(r30)
    stw	r4, 0x8c(r30)
    stw	r4, 0x88(r30)
    sth	r0, 0x98(r30)
    lbz	r0, 0xd(r30)
    cmpwi	r0, 8
    bne     _80043ca8
    li	r0, 1
    sth	r0, 0x9a(r30)
    b       _80043cac
_80043ca8:
    sth	r4, 0x9a(r30)
_80043cac:
    extsh	r3, r31
_80043cb0:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80043CCC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, FORM_str@ha
    li	r5, 4
    stw	r0, 0x14(r1)
    addi	r4, r4, FORM_str@l
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      fn_8008023C
    cmpwi	r3, 0
    bne     _80043d1c
    lis     r4, AIFF_str@ha
    addi	r3, r31, 8
    addi	r4, r4, AIFF_str@l
    li	r5, 4
    bl      fn_8008023C
    cmpwi	r3, 0
    bne     _80043d1c
    li	r3, 1
    b       _80043d20
_80043d1c:
    li	r3, 0
_80043d20:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80043D34(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    addi	r8, r3, 0xc
    li	r9, 0
    stmw	r27, 0xc(r1)
    lbz	r10, 1(r3)
    lbz	r30, 0(r3)
    rlwimi	r30, r10, 8, 0x10, 0x17
    lbz	r10, 2(r3)
    lbz	r0, 5(r3)
    rlwimi	r30, r10, 0x10, 8, 0xf
    lbz	r12, 4(r3)
    rlwimi	r12, r0, 8, 0x10, 0x17
    lbz	r11, 6(r3)
    lbz	r31, 3(r3)
    mr	r27, r30
    rlwimi	r12, r11, 0x10, 8, 0xf
    lbz	r0, 9(r3)
    lbz	r10, 8(r3)
    rlwimi	r27, r31, 0x18, 0, 7
    rlwimi	r10, r0, 8, 0x10, 0x17
    lbz	r11, 0xa(r3)
    lbz	r29, 7(r3)
    addis	r0, r27, -0x4d52
    cmplwi	r0, 0x4f46
    mr	r28, r12
    rlwimi	r28, r29, 0x18, 0, 7
    lbz	r3, 0xb(r3)
    rlwinm	r12, r28, 0x18, 0x10, 0x17
    rlwimi	r10, r11, 0x10, 8, 0xf
    rlwimi	r12, r28, 8, 0x18, 0x1f
    li	r0, 0
    rlwimi	r12, r28, 8, 8, 0xf
    rlwimi	r10, r3, 0x18, 0, 7
    rlwimi	r12, r28, 0x18, 0, 7
    li	r3, 0
    beq     _80043dcc
    li	r3, 0
    b       _80043f98
_80043dcc:
    addis	r10, r10, -0x4646
    cmplwi	r10, 0x4941
    beq     _80043de0
    li	r3, 0
    b       _80043f98
_80043de0:
    addi	r10, r12, -4
    lis	r11, 0x4d4d
    add	r10, r8, r10
    addi	r11, r11, 0x4f43
    b       _80043f90
_80043df4:
    lbz	r30, 1(r8)
    lbz	r28, 0(r8)
    rlwimi	r28, r30, 8, 0x10, 0x17
    lbz	r31, 2(r8)
    lbz	r12, 5(r8)
    lbz	r27, 4(r8)
    rlwimi	r28, r31, 0x10, 8, 0xf
    lbz	r30, 3(r8)
    rlwimi	r27, r12, 8, 0x10, 0x17
    lbz	r12, 6(r8)
    lbz	r29, 7(r8)
    rlwimi	r28, r30, 0x18, 0, 7
    rlwimi	r27, r12, 0x10, 8, 0xf
    addi	r8, r8, 8
    rlwimi	r27, r29, 0x18, 0, 7
    cmpw	r28, r11
    rlwinm	r29, r27, 0x18, 0x10, 0x17
    rlwimi	r29, r27, 8, 0x18, 0x1f
    rlwimi	r29, r27, 8, 8, 0xf
    rlwimi	r29, r27, 0x18, 0, 7
    beq     _80043e60
    bge     _80043f84
    lis	r12, 0x444e
    addi	r12, r12, 0x5353
    cmpw	r28, r12
    beq     _80043f38
    b       _80043f84
_80043e60:
    cmpwi	r9, 0
    bne     _80043f90
    cmpwi	r29, 0x12
    bge     _80043e78
    li	r3, 0
    b       _80043f98
_80043e78:
    lbz	r12, 1(r8)
    cmpwi	r0, 0
    lbz	r29, 0(r8)
    li	r9, 1
    rlwinm	r12, r12, 8, 8, 0x17
    rlwimi	r12, r29, 0, 0x18, 0x1f
    stw	r12, 0(r5)
    lwz	r29, 0(r5)
    rlwinm	r12, r29, 8, 0x10, 0x17
    rlwimi	r12, r29, 0x18, 0x18, 0x1f
    stw	r12, 0(r5)
    lbz	r12, 3(r8)
    lbz	r29, 2(r8)
    rlwimi	r29, r12, 8, 0x10, 0x17
    lbz	r30, 4(r8)
    lbz	r12, 5(r8)
    rlwimi	r29, r30, 0x10, 8, 0xf
    rlwimi	r29, r12, 0x18, 0, 7
    stw	r29, 0(r7)
    lwz	r29, 0(r7)
    stwbrx	r29, 0, r7
    lbz	r12, 7(r8)
    lbz	r29, 6(r8)
    rlwinm	r12, r12, 8, 8, 0x17
    rlwimi	r12, r29, 0, 0x18, 0x1f
    stw	r12, 0(r6)
    lwz	r29, 0(r6)
    rlwinm	r12, r29, 8, 0x10, 0x17
    rlwimi	r12, r29, 0x18, 0x18, 0x1f
    stw	r12, 0(r6)
    lbz	r12, 9(r8)
    lbz	r29, 8(r8)
    rlwimi	r29, r12, 8, 0x10, 0x17
    lbz	r12, 0xb(r8)
    lbz	r30, 0xa(r8)
    rlwinm	r31, r29, 8, 0x10, 0x17
    rlwimi	r30, r12, 8, 0x10, 0x17
    addi	r8, r8, 0x12
    rlwimi	r31, r29, 0x18, 0x18, 0x1f
    rlwinm	r12, r30, 8, 0x10, 0x17
    rlwimi	r12, r30, 0x18, 0x18, 0x1f
    clrlwi	r27, r31, 0x10
    clrlwi	r28, r12, 0x10
    subfic	r12, r27, 0x400e
    sraw	r12, r28, r12
    stw	r12, 0(r4)
    beq     _80043f90
    b       _80043f98
_80043f38:
    cmpwi	r0, 0
    bne     _80043f90
    lbz	r3, 1(r8)
    cmpwi	r9, 0
    lbz	r12, 0(r8)
    li	r0, 1
    lbz	r31, 2(r8)
    rlwimi	r12, r3, 8, 0x10, 0x17
    lbz	r30, 3(r8)
    addi	r8, r8, 4
    rlwimi	r12, r31, 0x10, 8, 0xf
    rlwimi	r12, r30, 0x18, 0, 7
    rlwinm	r3, r12, 0x18, 0x10, 0x17
    rlwimi	r3, r12, 8, 0x18, 0x1f
    rlwimi	r3, r12, 8, 8, 0xf
    rlwimi	r3, r12, 0x18, 0, 7
    add	r3, r8, r3
    beq     _80043f90
    b       _80043f98
_80043f84:
    addi	r12, r29, 1
    rlwinm	r12, r12, 0, 0, 0x1e
    add	r8, r8, r12
_80043f90:
    cmplw	r8, r10
    blt     _80043df4
_80043f98:
    lmw	r27, 0xc(r1)
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80043FA4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lha	r0, 0x9a(r3)
    cmpwi	r0, 2
    bne     _80043fc4
    bl      fn_80043FE8
    b       _80043fd8
_80043fc4:
    cmpwi	r0, 1
    bne     _80043fd4
    bl      fn_800443AC
    b       _80043fd8
_80043fd4:
    bl      fn_800446E4
_80043fd8:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80043FE8(void)
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
    bne     _80044368
    lwz	r3, 8(r30)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _80044368
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
    subf	r9, r4, r0
    cmpw	r9, r3
    ble     _80044058
    mr	r9, r3
_80044058:
    lwz	r0, 0x4c(r30)
    cmpw	r9, r0
    ble     _80044068
    mr	r9, r0
_80044068:
    lbz	r0, 0xe(r30)
    slwi	r3, r4, 1
    lwz	r5, 0x5c(r30)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r5, r3
    bne     _80044244
    lwz	r3, 0x64(r30)
    cmpwi	r9, 0
    li	r8, 0
    add	r3, r3, r4
    slwi	r3, r3, 1
    add	r7, r5, r3
    ble     _8004434c
    cmpwi	r9, 8
    addi	r11, r9, -8
    ble     _800441e8
    addi	r10, r11, 7
    lis     r3, lbl_8012B6F8@ha
    srwi	r10, r10, 3
    mr	r4, r31
    mr	r5, r0
    mr	r6, r7
    addi	r3, r3, lbl_8012B6F8@l
    mtctr	r10
    cmpwi	r11, 0
    ble     _800441e8
_800440d4:
    lbz	r10, 0(r4)
    addi	r8, r8, 8
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0(r5)
    lbz	r10, 1(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0(r6)
    lbz	r10, 2(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 2(r5)
    lbz	r10, 3(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 2(r6)
    lbz	r10, 4(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 4(r5)
    lbz	r10, 5(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 4(r6)
    lbz	r10, 6(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 6(r5)
    lbz	r10, 7(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 6(r6)
    lbz	r10, 8(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 8(r5)
    lbz	r10, 9(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 8(r6)
    lbz	r10, 0xa(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0xa(r5)
    lbz	r10, 0xb(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0xa(r6)
    lbz	r10, 0xc(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0xc(r5)
    lbz	r10, 0xd(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0xc(r6)
    lbz	r10, 0xe(r4)
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0xe(r5)
    addi	r5, r5, 0x10
    lbz	r10, 0xf(r4)
    addi	r4, r4, 0x10
    slwi	r10, r10, 1
    lhax	r10, r3, r10
    sth	r10, 0xe(r6)
    addi	r6, r6, 0x10
    bdnz    _800440d4
_800441e8:
    slwi	r10, r8, 1
    lis     r4, lbl_8012B6F8@ha
    subf	r3, r8, r9
    add	r5, r31, r10
    add	r6, r0, r10
    add	r7, r7, r10
    addi	r4, r4, lbl_8012B6F8@l
    mtctr	r3
    cmpw	r8, r9
    bge     _8004434c
_80044210:
    lbz	r0, 0(r5)
    slwi	r0, r0, 1
    lhax	r0, r4, r0
    sth	r0, 0(r6)
    addi	r6, r6, 2
    lbz	r0, 1(r5)
    addi	r5, r5, 2
    slwi	r0, r0, 1
    lhax	r0, r4, r0
    sth	r0, 0(r7)
    addi	r7, r7, 2
    bdnz    _80044210
    b       _8004434c
_80044244:
    cmpwi	r9, 0
    li	r6, 0
    ble     _8004434c
    cmpwi	r9, 8
    addi	r7, r9, -8
    ble     _8004430c
    addi	r5, r7, 7
    lis     r3, lbl_8012B6F8@ha
    srwi	r5, r5, 3
    mr	r4, r0
    addi	r3, r3, lbl_8012B6F8@l
    mtctr	r5
    cmpwi	r7, 0
    ble     _8004430c
_8004427c:
    add	r5, r31, r6
    addi	r6, r6, 8
    lbz	r7, 0(r5)
    slwi	r7, r7, 1
    lhax	r7, r3, r7
    sth	r7, 0(r4)
    lbz	r7, 1(r5)
    slwi	r7, r7, 1
    lhax	r7, r3, r7
    sth	r7, 2(r4)
    lbz	r7, 2(r5)
    slwi	r7, r7, 1
    lhax	r7, r3, r7
    sth	r7, 4(r4)
    lbz	r7, 3(r5)
    slwi	r7, r7, 1
    lhax	r7, r3, r7
    sth	r7, 6(r4)
    lbz	r7, 4(r5)
    slwi	r7, r7, 1
    lhax	r7, r3, r7
    sth	r7, 8(r4)
    lbz	r7, 5(r5)
    slwi	r7, r7, 1
    lhax	r7, r3, r7
    sth	r7, 0xa(r4)
    lbz	r7, 6(r5)
    slwi	r7, r7, 1
    lhax	r7, r3, r7
    sth	r7, 0xc(r4)
    lbz	r5, 7(r5)
    slwi	r5, r5, 1
    lhax	r5, r3, r5
    sth	r5, 0xe(r4)
    addi	r4, r4, 0x10
    bdnz    _8004427c
_8004430c:
    slwi	r7, r6, 1
    lis     r5, lbl_8012B6F8@ha
    subf	r3, r6, r9
    add	r4, r31, r6
    add	r7, r0, r7
    addi	r5, r5, lbl_8012B6F8@l
    mtctr	r3
    cmpw	r6, r9
    bge     _8004434c
_80044330:
    lbz	r0, 0(r4)
    addi	r4, r4, 1
    slwi	r0, r0, 1
    lhax	r0, r5, r0
    sth	r0, 0(r7)
    addi	r7, r7, 2
    bdnz    _80044330
_8004434c:
    stw	r9, 0x90(r30)
    li	r0, 2
    lbz	r3, 0xe(r30)
    extsb	r3, r3
    mullw	r3, r9, r3
    stw	r3, 0x94(r30)
    stw	r0, 4(r30)
_80044368:
    lwz	r0, 4(r30)
    cmpwi	r0, 2
    bne     _80044394
    lwz	r12, 0x80(r30)
    lwz	r3, 0x84(r30)
    lwz	r4, 0x94(r30)
    lwz	r5, 0x90(r30)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r30)
_80044394:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
