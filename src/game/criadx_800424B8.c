#pragma push
#pragma force_active on

extern void memset(void);
extern void fn_80045FA4(void);
extern void fn_800425D0(void);
extern void fn_80042980(void);
extern void fn_80042D24(void);
extern void fn_8008023C(void);
extern void fn_8004E270(void);
extern void fn_8004313C(void);
extern unsigned char RIFF_str[];
extern unsigned char WAVE_str[];
extern unsigned char lbl_801798C0[];
extern unsigned char lbl_8012B6F0[];
extern unsigned char lbl_8012B6F4[];

asm void fn_800424B8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_801798C0@ha
    li	r4, 0
    stw	r0, 0x14(r1)
    addi    r3, r3, lbl_801798C0@l
    li	r5, 0x9c0
    bl      memset
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800424E8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80045FA4
    lis     r3, lbl_801798C0@ha
    li	r4, 0
    addi    r3, r3, lbl_801798C0@l
    li	r5, 0x9c0
    bl      memset
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004251C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lha	r0, 0x9a(r3)
    cmpwi	r0, 2
    bne     _8004253c
    bl      fn_800425D0
    b       _80042558
_8004253c:
    cmpwi	r0, 1
    bne     _8004254c
    bl      fn_80042980
    b       _80042558
_8004254c:
    extsh.	r0, r0
    bne     _80042558
    bl      fn_80042D24
_80042558:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80042568(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, RIFF_str@ha
    li	r5, 4
    stw	r0, 0x14(r1)
    addi    r4, r4, RIFF_str@l
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      fn_8008023C
    cmpwi	r3, 0
    bne     _800425b8
    lis     r4, WAVE_str@ha
    addi	r3, r31, 8
    addi    r4, r4, WAVE_str@l
    li	r5, 4
    bl      fn_8008023C
    cmpwi	r3, 0
    bne     _800425b8
    li	r3, 1
    b       _800425bc
_800425b8:
    li	r3, 0
_800425bc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800425D0(void)
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
    bne     _8004293c
    lwz	r3, 8(r31)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _8004293c
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
    ble     _80042640
    mr	r3, r4
_80042640:
    lwz	r0, 0x4c(r31)
    cmpw	r3, r0
    ble     _80042650
    mr	r3, r0
_80042650:
    lbz	r0, 0xe(r31)
    slwi	r4, r5, 1
    lwz	r6, 0x5c(r31)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r6, r4
    bne     _80042820
    lwz	r4, 0x64(r31)
    cmpwi	r3, 0
    li	r8, 0
    add	r4, r4, r5
    slwi	r4, r4, 1
    add	r7, r6, r4
    ble     _8004291c
    cmpwi	r3, 8
    addi	r10, r3, -8
    ble     _800427c8
    addi	r9, r10, 7
    mr	r4, r30
    srwi	r9, r9, 3
    mr	r5, r0
    mr	r6, r7
    mtctr	r9
    cmpwi	r10, 0
    ble     _800427c8
_800426b4:
    lbz	r9, 2(r4)
    addi	r8, r8, 8
    lbz	r10, 0(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0(r5)
    lbz	r9, 3(r4)
    lbz	r10, 1(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0(r6)
    lbz	r9, 6(r4)
    lbz	r10, 4(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 2(r5)
    lbz	r9, 7(r4)
    lbz	r10, 5(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 2(r6)
    lbz	r9, 0xa(r4)
    lbz	r10, 8(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 4(r5)
    lbz	r9, 0xb(r4)
    lbz	r10, 9(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 4(r6)
    lbz	r9, 0xe(r4)
    lbz	r10, 0xc(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 6(r5)
    lbz	r9, 0xf(r4)
    lbz	r10, 0xd(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 6(r6)
    lbz	r9, 0x12(r4)
    lbz	r10, 0x10(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 8(r5)
    lbz	r9, 0x13(r4)
    lbz	r10, 0x11(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 8(r6)
    lbz	r9, 0x16(r4)
    lbz	r10, 0x14(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0xa(r5)
    lbz	r9, 0x17(r4)
    lbz	r10, 0x15(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0xa(r6)
    lbz	r9, 0x1a(r4)
    lbz	r10, 0x18(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0xc(r5)
    lbz	r9, 0x1b(r4)
    lbz	r10, 0x19(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0xc(r6)
    lbz	r9, 0x1e(r4)
    lbz	r10, 0x1c(r4)
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0xe(r5)
    addi	r5, r5, 0x10
    lbz	r9, 0x1f(r4)
    lbz	r10, 0x1d(r4)
    addi	r4, r4, 0x20
    rlwimi	r10, r9, 8, 0x10, 0x17
    sth	r10, 0xe(r6)
    addi	r6, r6, 0x10
    bdnz    _800426b4
_800427c8:
    slwi	r9, r8, 1
    slwi	r5, r8, 2
    subf	r4, r8, r3
    add	r5, r30, r5
    add	r6, r0, r9
    add	r7, r7, r9
    mtctr	r4
    cmpw	r8, r3
    bge     _8004291c
_800427ec:
    lbz	r0, 2(r5)
    lbz	r4, 0(r5)
    rlwimi	r4, r0, 8, 0x10, 0x17
    sth	r4, 0(r6)
    addi	r6, r6, 2
    lbz	r0, 3(r5)
    lbz	r4, 1(r5)
    addi	r5, r5, 4
    rlwimi	r4, r0, 8, 0x10, 0x17
    sth	r4, 0(r7)
    addi	r7, r7, 2
    bdnz    _800427ec
    b       _8004291c
_80042820:
    cmpwi	r3, 0
    li	r6, 0
    ble     _8004291c
    cmpwi	r3, 8
    addi	r8, r3, -8
    ble     _800428e4
    addi	r7, r8, 7
    mr	r4, r30
    srwi	r7, r7, 3
    mr	r5, r0
    mtctr	r7
    cmpwi	r8, 0
    ble     _800428e4
_80042854:
    lbz	r7, 1(r4)
    addi	r6, r6, 8
    lbz	r8, 0(r4)
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 0(r5)
    lbz	r7, 3(r4)
    lbz	r8, 2(r4)
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 2(r5)
    lbz	r7, 5(r4)
    lbz	r8, 4(r4)
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 4(r5)
    lbz	r7, 7(r4)
    lbz	r8, 6(r4)
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 6(r5)
    lbz	r7, 9(r4)
    lbz	r8, 8(r4)
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 8(r5)
    lbz	r7, 0xb(r4)
    lbz	r8, 0xa(r4)
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 0xa(r5)
    lbz	r7, 0xd(r4)
    lbz	r8, 0xc(r4)
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 0xc(r5)
    lbz	r7, 0xf(r4)
    lbz	r8, 0xe(r4)
    addi	r4, r4, 0x10
    rlwimi	r8, r7, 8, 0x10, 0x17
    sth	r8, 0xe(r5)
    addi	r5, r5, 0x10
    bdnz    _80042854
_800428e4:
    slwi	r7, r6, 1
    subf	r4, r6, r3
    add	r5, r30, r7
    add	r7, r0, r7
    mtctr	r4
    cmpw	r6, r3
    bge     _8004291c
_80042900:
    lbz	r0, 1(r5)
    lbz	r4, 0(r5)
    addi	r5, r5, 2
    rlwimi	r4, r0, 8, 0x10, 0x17
    sth	r4, 0(r7)
    addi	r7, r7, 2
    bdnz    _80042900
_8004291c:
    stw	r3, 0x90(r31)
    slwi	r3, r3, 1
    li	r0, 2
    lbz	r4, 0xe(r31)
    extsb	r4, r4
    mullw	r3, r4, r3
    stw	r3, 0x94(r31)
    stw	r0, 4(r31)
_8004293c:
    lwz	r0, 4(r31)
    cmpwi	r0, 2
    bne     _80042968
    lwz	r12, 0x80(r31)
    lwz	r3, 0x84(r31)
    lwz	r4, 0x94(r31)
    lwz	r5, 0x90(r31)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r31)
_80042968:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80042980(void)
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
    bne     _80042ce0
    lwz	r3, 8(r30)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _80042ce0
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
    ble     _800429f0
    mr	r8, r3
_800429f0:
    lwz	r0, 0x4c(r30)
    cmpw	r8, r0
    ble     _80042a00
    mr	r8, r0
_80042a00:
    lbz	r0, 0xe(r30)
    slwi	r3, r4, 1
    lwz	r5, 0x5c(r30)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r5, r3
    bne     _80042bcc
    lwz	r3, 0x64(r30)
    cmpwi	r8, 0
    li	r7, 0
    add	r3, r3, r4
    slwi	r3, r3, 1
    add	r6, r5, r3
    ble     _80042cc4
    cmpwi	r8, 8
    addi	r10, r8, -8
    ble     _80042b78
    addi	r9, r10, 7
    mr	r3, r31
    srwi	r9, r9, 3
    mr	r4, r0
    mr	r5, r6
    mtctr	r9
    cmpwi	r10, 0
    ble     _80042b78
_80042a64:
    lbz	r9, 0(r3)
    addi	r7, r7, 8
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0(r4)
    lbz	r9, 1(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0(r5)
    lbz	r9, 2(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 2(r4)
    lbz	r9, 3(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 2(r5)
    lbz	r9, 4(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 4(r4)
    lbz	r9, 5(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 4(r5)
    lbz	r9, 6(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 6(r4)
    lbz	r9, 7(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 6(r5)
    lbz	r9, 8(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 8(r4)
    lbz	r9, 9(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 8(r5)
    lbz	r9, 0xa(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xa(r4)
    lbz	r9, 0xb(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xa(r5)
    lbz	r9, 0xc(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xc(r4)
    lbz	r9, 0xd(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xc(r5)
    lbz	r9, 0xe(r3)
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xe(r4)
    addi	r4, r4, 0x10
    lbz	r9, 0xf(r3)
    addi	r3, r3, 0x10
    addi	r9, r9, -0x80
    rlwinm	r9, r9, 8, 0x10, 0x17
    sth	r9, 0xe(r5)
    addi	r5, r5, 0x10
    bdnz    _80042a64
_80042b78:
    slwi	r9, r7, 1
    subf	r3, r7, r8
    add	r4, r31, r9
    add	r5, r0, r9
    add	r6, r6, r9
    mtctr	r3
    cmpw	r7, r8
    bge     _80042cc4
_80042b98:
    lbz	r3, 0(r4)
    addi	r0, r3, -0x80
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r5)
    addi	r5, r5, 2
    lbz	r3, 1(r4)
    addi	r4, r4, 2
    addi	r0, r3, -0x80
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r6)
    addi	r6, r6, 2
    bdnz    _80042b98
    b       _80042cc4
_80042bcc:
    cmpwi	r8, 0
    li	r4, 0
    ble     _80042cc4
    cmpwi	r8, 8
    addi	r6, r8, -8
    ble     _80042c8c
    addi	r5, r6, 7
    mr	r3, r0
    srwi	r5, r5, 3
    mtctr	r5
    cmpwi	r6, 0
    ble     _80042c8c
_80042bfc:
    add	r6, r31, r4
    addi	r4, r4, 8
    lbz	r5, 0(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 0(r3)
    lbz	r5, 1(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 2(r3)
    lbz	r5, 2(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 4(r3)
    lbz	r5, 3(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 6(r3)
    lbz	r5, 4(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 8(r3)
    lbz	r5, 5(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 0xa(r3)
    lbz	r5, 6(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 0xc(r3)
    lbz	r5, 7(r6)
    addi	r5, r5, -0x80
    rlwinm	r5, r5, 8, 0x10, 0x17
    sth	r5, 0xe(r3)
    addi	r3, r3, 0x10
    bdnz    _80042bfc
_80042c8c:
    slwi	r5, r4, 1
    subf	r3, r4, r8
    add	r6, r0, r5
    add	r5, r31, r4
    mtctr	r3
    cmpw	r4, r8
    bge     _80042cc4
_80042ca8:
    lbz	r3, 0(r5)
    addi	r5, r5, 1
    addi	r0, r3, -0x80
    rlwinm	r0, r0, 8, 0x10, 0x17
    sth	r0, 0(r6)
    addi	r6, r6, 2
    bdnz    _80042ca8
_80042cc4:
    stw	r8, 0x90(r30)
    li	r0, 2
    lbz	r3, 0xe(r30)
    extsb	r3, r3
    mullw	r3, r8, r3
    stw	r3, 0x94(r30)
    stw	r0, 4(r30)
_80042ce0:
    lwz	r0, 4(r30)
    cmpwi	r0, 2
    bne     _80042d0c
    lwz	r12, 0x80(r30)
    lwz	r3, 0x84(r30)
    lwz	r4, 0x94(r30)
    lwz	r5, 0x90(r30)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r30)
_80042d0c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80042D24(void)
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
    bne     _8004300c
    lwz	r3, 8(r31)
    bl      fn_8004E270
    cmpwi	r3, 0
    bne     _8004300c
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
    ble     _80042d94
    mr	r3, r4
_80042d94:
    lwz	r0, 0x4c(r31)
    cmpw	r3, r0
    ble     _80042da4
    mr	r3, r0
_80042da4:
    lbz	r0, 0xe(r31)
    slwi	r4, r5, 1
    lwz	r6, 0x5c(r31)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r6, r4
    bne     _80042f1c
    lwz	r4, 0x64(r31)
    cmpwi	r3, 0
    li	r8, 0
    add	r4, r4, r5
    slwi	r4, r4, 1
    add	r7, r6, r4
    ble     _80042fec
    cmpwi	r3, 8
    addi	r10, r3, -8
    ble     _80042ed4
    addi	r9, r10, 7
    mr	r4, r30
    srwi	r9, r9, 3
    mr	r5, r0
    mr	r6, r7
    mtctr	r9
    cmpwi	r10, 0
    ble     _80042ed4
_80042e08:
    lhz	r10, 0(r4)
    addi	r9, r5, 2
    addi	r8, r8, 8
    sthbrx	r10, 0, r5
    lhz	r10, 2(r4)
    sthbrx	r10, 0, r6
    lhz	r10, 4(r4)
    sthbrx	r10, 0, r9
    addi	r9, r6, 2
    lhz	r10, 6(r4)
    sthbrx	r10, 0, r9
    addi	r9, r5, 4
    lhz	r10, 8(r4)
    sthbrx	r10, 0, r9
    addi	r9, r6, 4
    lhz	r10, 0xa(r4)
    sthbrx	r10, 0, r9
    addi	r9, r5, 6
    lhz	r10, 0xc(r4)
    sthbrx	r10, 0, r9
    addi	r9, r6, 6
    lhz	r10, 0xe(r4)
    sthbrx	r10, 0, r9
    addi	r9, r5, 8
    lhz	r10, 0x10(r4)
    sthbrx	r10, 0, r9
    addi	r9, r6, 8
    lhz	r10, 0x12(r4)
    sthbrx	r10, 0, r9
    addi	r9, r5, 0xa
    lhz	r10, 0x14(r4)
    sthbrx	r10, 0, r9
    addi	r9, r6, 0xa
    lhz	r10, 0x16(r4)
    sthbrx	r10, 0, r9
    addi	r9, r5, 0xc
    lhz	r10, 0x18(r4)
    sthbrx	r10, 0, r9
    addi	r9, r6, 0xc
    lhz	r10, 0x1a(r4)
    sthbrx	r10, 0, r9
    addi	r9, r5, 0xe
    addi	r5, r5, 0x10
    lhz	r10, 0x1c(r4)
    sthbrx	r10, 0, r9
    addi	r9, r6, 0xe
    addi	r6, r6, 0x10
    lhz	r10, 0x1e(r4)
    addi	r4, r4, 0x20
    sthbrx	r10, 0, r9
    bdnz    _80042e08
_80042ed4:
    slwi	r9, r8, 1
    slwi	r5, r8, 2
    subf	r4, r8, r3
    add	r5, r30, r5
    add	r6, r0, r9
    add	r7, r7, r9
    mtctr	r4
    cmpw	r8, r3
    bge     _80042fec
_80042ef8:
    lhz	r4, 0(r5)
    sthbrx	r4, 0, r6
    addi	r6, r6, 2
    lhz	r4, 2(r5)
    addi	r5, r5, 4
    sthbrx	r4, 0, r7
    addi	r7, r7, 2
    bdnz    _80042ef8
    b       _80042fec
_80042f1c:
    cmpwi	r3, 0
    li	r4, 0
    ble     _80042fec
    cmpwi	r3, 8
    addi	r6, r3, -8
    ble     _80042fbc
    addi	r5, r6, 7
    mr	r7, r30
    srwi	r5, r5, 3
    mr	r8, r0
    mtctr	r5
    cmpwi	r6, 0
    ble     _80042fbc
_80042f50:
    lhz	r6, 0(r7)
    addi	r5, r8, 2
    addi	r4, r4, 8
    sthbrx	r6, 0, r8
    lhz	r6, 2(r7)
    sthbrx	r6, 0, r5
    addi	r5, r8, 4
    lhz	r6, 4(r7)
    sthbrx	r6, 0, r5
    addi	r5, r8, 6
    lhz	r6, 6(r7)
    sthbrx	r6, 0, r5
    addi	r5, r8, 8
    lhz	r6, 8(r7)
    sthbrx	r6, 0, r5
    addi	r5, r8, 0xa
    lhz	r6, 0xa(r7)
    sthbrx	r6, 0, r5
    addi	r5, r8, 0xc
    lhz	r6, 0xc(r7)
    sthbrx	r6, 0, r5
    addi	r5, r8, 0xe
    addi	r8, r8, 0x10
    lhz	r6, 0xe(r7)
    addi	r7, r7, 0x10
    sthbrx	r6, 0, r5
    bdnz    _80042f50
_80042fbc:
    slwi	r7, r4, 1
    subf	r5, r4, r3
    add	r6, r30, r7
    add	r7, r0, r7
    mtctr	r5
    cmpw	r4, r3
    bge     _80042fec
_80042fd8:
    lhz	r4, 0(r6)
    addi	r6, r6, 2
    sthbrx	r4, 0, r7
    addi	r7, r7, 2
    bdnz    _80042fd8
_80042fec:
    stw	r3, 0x90(r31)
    slwi	r3, r3, 1
    li	r0, 2
    lbz	r4, 0xe(r31)
    extsb	r4, r4
    mullw	r3, r4, r3
    stw	r3, 0x94(r31)
    stw	r0, 4(r31)
_8004300c:
    lwz	r0, 4(r31)
    cmpwi	r0, 2
    bne     _80043038
    lwz	r12, 0x80(r31)
    lwz	r3, 0x84(r31)
    lwz	r4, 0x94(r31)
    lwz	r5, 0x90(r31)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r31)
_80043038:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80043050(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    li	r0, 1
    stw	r31, 0x2c(r1)
    mr	r31, r3
    addi	r6, r31, 0x10
    sth	r0, 2(r3)
    addi	r0, r31, 0x18
    mr	r3, r4
    mr	r4, r5
    stw	r0, 8(r1)
    addi	r0, r31, 0x9a
    addi	r5, r1, 0x18
    addi	r7, r31, 0xd
    stw	r6, 0xc(r1)
    addi	r6, r31, 0xc
    addi	r8, r31, 0xf
    addi	r9, r31, 0xe
    stw	r0, 0x10(r1)
    addi	r10, r31, 0x14
    bl      fn_8004313C
    cmpwi	r3, 0
    bge     _800430b8
    li	r3, 0
    b       _80043128
_800430b8:
    li	r4, 0
    li	r0, 1
    sth	r4, 0x1c(r31)
    sth	r4, 0x26(r31)
    sth	r4, 0x24(r31)
    stw	r4, 0x34(r31)
    stw	r4, 0x30(r31)
    stw	r4, 0x2c(r31)
    stw	r4, 0x28(r31)
    stw	r4, 0x20(r31)
    lbz	r3, 0xe(r31)
    extsb	r3, r3
    stw	r3, 0x50(r31)
    lbz	r3, 0xf(r31)
    extsb	r3, r3
    stw	r3, 0x54(r31)
    lwz	r3, 0x10(r31)
    stw	r3, 0x58(r31)
    lwz	r3, 0x3c(r31)
    stw	r3, 0x5c(r31)
    lwz	r3, 0x40(r31)
    stw	r3, 0x60(r31)
    lwz	r3, 0x44(r31)
    stw	r3, 0x64(r31)
    stw	r4, 0x8c(r31)
    stw	r4, 0x88(r31)
    sth	r0, 0x98(r31)
    lha	r3, 0x18(r1)
_80043128:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8004313C(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    lis     r11, lbl_8012B6F0@ha
    stw	r0, 0x44(r1)
    stmw	r18, 8(r1)
    mr	r20, r3
    mr	r21, r4
    mr	r22, r5
    mr	r23, r6
    mr	r24, r7
    mr	r25, r8
    mr	r26, r9
    mr	r27, r10
    addi    r11, r11, lbl_8012B6F0@l
    li	r18, 0
    lwz	r28, 0x48(r1)
    lwz	r29, 0x4c(r1)
    lwz	r30, 0x50(r1)
    b       _800431a4
_80043188:
    lwz	r4, 0(r19)
    add	r3, r20, r18
    li	r5, 4
    bl      fn_8008023C
    cmpwi	r3, 0
    beq     _800431ac
    addi	r18, r18, 1
_800431a4:
    cmpw	r18, r21
    blt     _80043188
_800431ac:
    cmpw	r18, r21
    bne     _800431bc
    li	r3, -1
    b       _80043390
_800431bc:
    slwi	r0, r18, 0x1e
    srwi	r3, r18, 0x1f
    subf	r0, r3, r0
    rotlwi	r0, r0, 2
    add.	r0, r0, r3
    beq     _800431dc
    li	r3, -1
    b       _80043390
_800431dc:
    add	r31, r18, r20
    lhz	r3, 8(r31)
    rlwinm	r0, r3, 8, 0x10, 0x17
    rlwimi	r0, r3, 0x18, 0x18, 0x1f
    extsh	r0, r0
    cmpwi	r0, 1
    ble     _80043200
    li	r3, -1
    b       _80043390
_80043200:
    lis     r3, lbl_8012B6F4@ha
    li	r18, 0
    addi    r3, r3, lbl_8012B6F4@l
    b       _8004322c
_80043210:
    lwz	r4, 0(r19)
    add	r3, r20, r18
    li	r5, 4
    bl      fn_8008023C
    cmpwi	r3, 0
    beq     _80043234
    addi	r18, r18, 1
_8004322c:
    cmpw	r18, r21
    blt     _80043210
_80043234:
    cmpw	r18, r21
    bne     _80043244
    li	r3, -1
    b       _80043390
_80043244:
    add	r4, r18, r20
    addi	r3, r18, 8
    lwz	r5, 4(r4)
    li	r0, -1
    li	r4, 1
    sth	r3, 0(r22)
    rlwinm	r3, r5, 0x18, 0x10, 0x17
    rlwimi	r3, r5, 8, 0x18, 0x1f
    stb	r0, 0(r23)
    rlwimi	r3, r5, 8, 8, 0xf
    mr	r0, r3
    lwz	r6, 0xc(r31)
    rlwimi	r0, r5, 0x18, 0, 7
    stwbrx	r6, 0, r27
    lhz	r5, 0xa(r31)
    rlwinm	r3, r5, 8, 0x10, 0x17
    rlwimi	r3, r5, 0x18, 0x18, 0x1f
    stb	r3, 0(r26)
    lhz	r5, 0x16(r31)
    rlwinm	r3, r5, 8, 0x10, 0x17
    rlwimi	r3, r5, 0x18, 0x18, 0x1f
    stb	r3, 0(r24)
    lhz	r5, 0x14(r31)
    rlwinm	r3, r5, 8, 0x10, 0x17
    rlwimi	r3, r5, 0x18, 0x18, 0x1f
    stb	r3, 0(r25)
    lbz	r3, 0(r25)
    extsb	r3, r3
    divw	r3, r0, r3
    stw	r3, 0(r28)
    stw	r4, 0(r29)
    lbz	r3, 0(r24)
    extsb	r3, r3
    cmpwi	r3, 0x10
    bne     _800432dc
    li	r0, 0
    sth	r0, 0(r30)
    b       _80043338
_800432dc:
    cmpwi	r3, 8
    bne     _800432ec
    sth	r4, 0(r30)
    b       _80043338
_800432ec:
    cmpwi	r3, 4
    bne     _80043338
    lbz	r5, 0(r26)
    srwi	r3, r0, 0x1f
    add	r0, r3, r0
    li	r4, 4
    extsb	r5, r5
    li	r3, 0x10
    slwi	r6, r5, 1
    stb	r6, 0(r25)
    srawi	r5, r0, 1
    li	r0, 2
    stw	r4, 0(r29)
    lbz	r4, 0(r26)
    extsb	r4, r4
    divw	r4, r5, r4
    stw	r4, 0(r28)
    stb	r3, 0(r24)
    sth	r0, 0(r30)
_80043338:
    lbz	r0, 0(r24)
    extsb.	r0, r0
    bne     _8004334c
    li	r3, -1
    b       _80043390
_8004334c:
    lbz	r0, 0(r25)
    extsb.	r0, r0
    bne     _80043360
    li	r3, -1
    b       _80043390
_80043360:
    lbz	r3, 0(r26)
    extsb.	r0, r3
    ble     _80043378
    extsb	r0, r3
    cmpwi	r0, 2
    ble     _80043380
_80043378:
    li	r3, -1
    b       _80043390
_80043380:
    lwz	r0, 0(r27)
    cntlzw	r0, r0
    rlwinm	r0, r0, 0x1b, 0x1f, 0x1f
    neg	r3, r0
_80043390:
    lmw	r18, 8(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

#pragma pop
