typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

// MSL tail region 0x8008279C-0x80083D40 (pm10-c region A)

extern void __va_arg(void);
extern void fn_80080030(void);
extern void fn_80083F10(void);
extern void fn_80085088(void);
extern void fn_80085494(void);
extern void fn_80082A7C(void);
extern void fn_80083428(void);
extern unsigned char jumptable_8015B668[208];
extern unsigned char lbl_80095010[32];
extern unsigned char lbl_8015B100[256];
void fn_800829EC(void);

asm void fn_8008279C(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    cmplwi	r4, 2
    stw	r0, 0x44(r1)
    stmw	r21, 0x14(r1)
    mr	r29, r3
    mr	r30, r5
    mr	r31, r6
    bc      12, 0, _800828f4
    srwi	r3, r4, 1
    addi	r0, r4, -1
    addi	r28, r3, 1
    mr	r27, r4
    addi	r3, r28, -1
    mullw	r3, r30, r3
    mullw	r0, r30, r0
    add	r25, r29, r3
    add	r24, r29, r0
_800827e4:
    cmplwi	r28, 1
    bc      4, 1, _800827f8
    subf	r25, r30, r25
    addi	r28, r28, -1
    b       _8008283c
_800827f8:
    addi	r3, r24, -1
    addi	r4, r25, -1
    addi	r5, r30, 1
    b       _80082824
_80082808:
    lbz	r6, 1(r4)
    lbz	r0, 1(r3)
    extsb	r6, r6
    stb	r0, 1(r4)
    addi	r4, r4, 1
    stb	r6, 1(r3)
    addi	r3, r3, 1
_80082824:
    addic.	r5, r5, -1
    bc      4, 2, _80082808
    addi	r27, r27, -1
    cmplwi	r27, 1
    bc      12, 2, _800828f4
    subf	r24, r30, r24
_8008283c:
    addi	r0, r28, -1
    mr	r26, r28
    mullw	r0, r30, r0
    add	r22, r29, r0
    b       _800828e4
_80082850:
    slwi	r26, r26, 1
    mr	r23, r22
    addi	r0, r26, -1
    mullw	r0, r30, r0
    cmplw	r26, r27
    add	r22, r29, r0
    bc      4, 0, _80082894
    add	r21, r22, r30
    mr	r12, r31
    mr	r3, r22
    mr	r4, r21
    mtctr	r12
    bctrl
    cmpwi	r3, 0
    bc      4, 0, _80082894
    mr	r22, r21
    addi	r26, r26, 1
_80082894:
    mr	r12, r31
    mr	r3, r23
    mr	r4, r22
    mtctr	r12
    bctrl
    cmpwi	r3, 0
    bc      4, 0, _800827e4
    addi	r3, r22, -1
    addi	r4, r23, -1
    addi	r5, r30, 1
    b       _800828dc
_800828c0:
    lbz	r6, 1(r4)
    lbz	r0, 1(r3)
    extsb	r6, r6
    stb	r0, 1(r4)
    addi	r4, r4, 1
    stb	r6, 1(r3)
    addi	r3, r3, 1
_800828dc:
    addic.	r5, r5, -1
    bc      4, 2, _800828c0
_800828e4:
    slwi	r0, r26, 1
    cmplw	r0, r27
    bc      4, 1, _80082850
    b       _800827e4
_800828f4:
    lmw	r21, 0x14(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr
}

asm void fn_80082908(void)
{
    nofralloc
    lis	r3, 0x41c6
    lwz	r4, -0x7d88(r13)
    addi	r0, r3, 0x4e6d
    mullw	r3, r4, r0
    addi	r0, r3, 0x3039
    stw	r0, -0x7d88(r13)
    rlwinm	r3, r0, 0x10, 0x11, 0x1f
    blr
}

asm void fn_80082928(void)
{
    nofralloc
    stwu	r1, -0x90(r1)
    mflr	r0
    stw	r0, 0x94(r1)
    stw	r31, 0x8c(r1)
    bc      4, 6, _8008295c
    stfd	f1, 0x28(r1)
    stfd	f2, 0x30(r1)
    stfd	f3, 0x38(r1)
    stfd	f4, 0x40(r1)
    stfd	f5, 0x48(r1)
    stfd	f6, 0x50(r1)
    stfd	f7, 0x58(r1)
    stfd	f8, 0x60(r1)
_8008295c:
    addi	r11, r1, 0x98
    addi	r0, r1, 8
    lis	r12, 0x200
    cmplwi	r3, 0
    stw	r3, 8(r1)
    addi	r31, r1, 0x70
    stw	r4, 0xc(r1)
    stw	r5, 0x10(r1)
    stw	r6, 0x14(r1)
    stw	r7, 0x18(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r10, 0x24(r1)
    stw	r12, 0x70(r1)
    stw	r11, 0x74(r1)
    stw	r0, 0x78(r1)
    stw	r3, 0x68(r1)
    bc      12, 2, _800829b0
    lbz	r0, 0(r3)
    extsb.	r0, r0
    bc      4, 2, _800829b8
_800829b0:
    li	r3, -1
    b       _800829d8
_800829b8:
    li	r0, 0
    lis     r3, fn_800829EC@ha
    stw	r0, 0x6c(r1)
    mr	r5, r4
    addi	r3, r3, fn_800829EC@l
    mr	r6, r31
    addi	r4, r1, 0x68
    bl      fn_80082A7C
_800829d8:
    lwz	r0, 0x94(r1)
    lwz	r31, 0x8c(r1)
    mtlr	r0
    addi	r1, r1, 0x90
    blr
}

asm void fn_800829EC(void)
{
    nofralloc
    cmpwi	r5, 1
    mr	r6, r3
    bc      12, 2, _80082a40
    bc      4, 0, _80082a08
    cmpwi	r5, 0
    bc      4, 0, _80082a14
    b       _80082a74
_80082a08:
    cmpwi	r5, 3
    bc      4, 0, _80082a74
    b       _80082a6c
_80082a14:
    lwz	r4, 0(r6)
    lbz	r3, 0(r4)
    extsb.	r0, r3
    bc      4, 2, _80082a34
    li	r0, 1
    li	r3, -1
    stw	r0, 4(r6)
    blr
_80082a34:
    addi	r0, r4, 1
    stw	r0, 0(r6)
    blr
_80082a40:
    lwz	r0, 4(r6)
    cmpwi	r0, 0
    bc      4, 2, _80082a5c
    lwz	r3, 0(r6)
    addi	r0, r3, -1
    stw	r0, 0(r6)
    b       _80082a64
_80082a5c:
    li	r0, 0
    stw	r0, 4(r6)
_80082a64:
    mr	r3, r4
    blr
_80082a6c:
    lwz	r3, 4(r6)
    blr
_80082a74:
    li	r3, 0
    blr
}

asm void fn_80082A7C(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    lis	r7, -0x7fea
    stw	r0, 0x84(r1)
    stmw	r16, 0x40(r1)
    mr	r30, r3
    mr	r31, r4
    mr	r16, r6
    mr	r26, r5
    addi	r18, r7, -0x4f00
    li	r29, 0
    li	r28, 0
    li	r27, 0
    b       _800833d4
_80082ab4:
    clrlwi	r0, r17, 0x18
    lbzx	r0, r18, r0
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      12, 2, _80082b38
    lis     r3, lbl_8015B100@ha
    addi	r3, r3, lbl_8015B100@l
_80082acc:
    lbzu	r0, 1(r26)
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      4, 2, _80082acc
    lis     r3, lbl_8015B100@ha
    addi	r17, r3, lbl_8015B100@l
    b       _80082aec
_80082ae8:
    addi	r29, r29, 1
_80082aec:
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    clrlwi	r0, r3, 0x18
    stb	r3, 8(r1)
    lbzx	r0, r17, r0
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      4, 2, _80082ae8
    clrlwi	r4, r3, 0x18
    mr	r12, r30
    mr	r3, r31
    li	r5, 1
    extsb	r4, r4
    mtctr	r12
    bctrl
    b       _800833d4
_80082b38:
    cmpwi	r17, 0x25
    bc      12, 2, _80082b98
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    clrlwi	r0, r17, 0x18
    extsb	r4, r3
    cmpw	r0, r4
    stb	r3, 8(r1)
    bc      12, 2, _80082b8c
    clrlwi	r4, r3, 0x18
    mr	r12, r30
    mr	r3, r31
    li	r5, 1
    extsb	r4, r4
    mtctr	r12
    bctrl
    b       _800833e0
_80082b8c:
    addi	r29, r29, 1
    addi	r26, r26, 1
    b       _800833d4
_80082b98:
    mr	r3, r26
    addi	r4, r1, 0x18
    bl      fn_80083428
    lbz	r0, 0x18(r1)
    mr	r26, r3
    cmplwi	r0, 0
    bc      4, 2, _80082bd4
    lbz	r0, 0x1b(r1)
    cmplwi	r0, 0x25
    bc      12, 2, _80082bd4
    mr	r3, r16
    li	r4, 1
    bl      __va_arg
    lwz	r22, 0(r3)
    b       _80082bd8
_80082bd4:
    li	r22, 0
_80082bd8:
    lbz	r0, 0x1b(r1)
    cmplwi	r0, 0x6e
    bc      12, 2, _80082c04
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl
    cmpwi	r3, 0
    bc      4, 2, _800833e0
_80082c04:
    lbz	r0, 0x1b(r1)
    cmpwi	r0, 0x64
    bc      12, 2, _80082cc8
    bc      4, 0, _80082c68
    cmpwi	r0, 0x58
    bc      12, 2, _80082e0c
    bc      4, 0, _80082c44
    cmpwi	r0, 0x45
    bc      12, 2, _80082f18
    bc      4, 0, _80082c38
    cmpwi	r0, 0x25
    bc      12, 2, _800830ac
    b       _800833e0
_80082c38:
    cmpwi	r0, 0x47
    bc      12, 2, _80082f18
    b       _800833e0
_80082c44:
    cmpwi	r0, 0x61
    bc      12, 2, _80082f18
    bc      4, 0, _80082c5c
    cmpwi	r0, 0x5b
    bc      12, 2, _8008318c
    b       _800833e0
_80082c5c:
    cmpwi	r0, 0x63
    bc      4, 0, _80082f94
    b       _800833e0
_80082c68:
    cmpwi	r0, 0x73
    bc      12, 2, _80083118
    bc      4, 0, _80082ca4
    cmpwi	r0, 0x6e
    bc      12, 2, _80083370
    bc      4, 0, _80082c98
    cmpwi	r0, 0x69
    bc      12, 2, _80082cd0
    bc      4, 0, _800833e0
    cmpwi	r0, 0x68
    bc      4, 0, _800833e0
    b       _80082f18
_80082c98:
    cmpwi	r0, 0x70
    bc      4, 0, _800833e0
    b       _80082dfc
_80082ca4:
    cmpwi	r0, 0x78
    bc      12, 2, _80082e0c
    bc      4, 0, _80082cbc
    cmpwi	r0, 0x75
    bc      12, 2, _80082e04
    b       _800833e0
_80082cbc:
    cmpwi	r0, 0xff
    bc      12, 2, _800833e0
    b       _800833e0
_80082cc8:
    li	r17, 0xa
    b       _80082cd4
_80082cd0:
    li	r17, 0
_80082cd4:
    lbz	r0, 0x1a(r1)
    cmplwi	r0, 4
    bc      4, 2, _80082d08
    lwz	r4, 0x1c(r1)
    mr	r3, r17
    mr	r5, r30
    mr	r6, r31
    addi	r7, r1, 0x14
    addi	r8, r1, 0x10
    addi	r9, r1, 0xc
    bl      fn_80085088
    mr	r24, r4
    mr	r23, r3
_80082d08:
    lbz	r0, 0x1a(r1)
    cmplwi	r0, 4
    bc      12, 2, _80082d38
    lwz	r4, 0x1c(r1)
    mr	r3, r17
    mr	r5, r30
    mr	r6, r31
    addi	r7, r1, 0x14
    addi	r8, r1, 0x10
    addi	r9, r1, 0xc
    bl      fn_80085494
    mr	r25, r3
_80082d38:
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _800833e0
    lbz	r4, 0x1a(r1)
    add	r29, r29, r0
    cmplwi	r4, 4
    bc      4, 2, _80082d7c
    lwz	r0, 0x10(r1)
    cmpwi	r0, 0
    bc      12, 2, _80082d6c
    subfic	r20, r24, 0
    subfze	r0, r23
    b       _80082d74
_80082d6c:
    mr	r20, r24
    mr	r0, r23
_80082d74:
    mr	r19, r0
    b       _80082d94
_80082d7c:
    lwz	r0, 0x10(r1)
    mr	r3, r25
    cmpwi	r0, 0
    bc      12, 2, _80082d90
    neg	r3, r25
_80082d90:
    mr	r21, r3
_80082d94:
    cmplwi	r22, 0
    bc      12, 2, _80082df4
    cmpwi	r4, 2
    bc      12, 2, _80082dd8
    bc      4, 0, _80082db8
    cmpwi	r4, 0
    bc      12, 2, _80082dc8
    bc      4, 0, _80082dd0
    b       _80082df0
_80082db8:
    cmpwi	r4, 4
    bc      12, 2, _80082de8
    bc      4, 0, _80082df0
    b       _80082de0
_80082dc8:
    stw	r21, 0(r22)
    b       _80082df0
_80082dd0:
    stb	r21, 0(r22)
    b       _80082df0
_80082dd8:
    sth	r21, 0(r22)
    b       _80082df0
_80082de0:
    stw	r21, 0(r22)
    b       _80082df0
_80082de8:
    stw	r20, 4(r22)
    stw	r19, 0(r22)
_80082df0:
    addi	r28, r28, 1
_80082df4:
    addi	r27, r27, 1
    b       _800833d4
_80082dfc:
    li	r17, 8
    b       _80082e10
_80082e04:
    li	r17, 0xa
    b       _80082e10
_80082e0c:
    li	r17, 0x10
_80082e10:
    lbz	r0, 0x1a(r1)
    cmplwi	r0, 4
    bc      4, 2, _80082e44
    lwz	r4, 0x1c(r1)
    mr	r3, r17
    mr	r5, r30
    mr	r6, r31
    addi	r7, r1, 0x14
    addi	r8, r1, 0x10
    addi	r9, r1, 0xc
    bl      fn_80085088
    mr	r24, r4
    mr	r23, r3
_80082e44:
    lbz	r0, 0x1a(r1)
    cmplwi	r0, 4
    bc      12, 2, _80082e74
    lwz	r4, 0x1c(r1)
    mr	r3, r17
    mr	r5, r30
    mr	r6, r31
    addi	r7, r1, 0x14
    addi	r8, r1, 0x10
    addi	r9, r1, 0xc
    bl      fn_80085494
    mr	r25, r3
_80082e74:
    lwz	r3, 0x14(r1)
    cmpwi	r3, 0
    bc      12, 2, _800833e0
    lwz	r0, 0x10(r1)
    add	r29, r29, r3
    cmpwi	r0, 0
    bc      12, 2, _80082eac
    lbz	r0, 0x1a(r1)
    cmplwi	r0, 4
    bc      4, 2, _80082ea8
    subfic	r24, r24, 0
    subfze	r23, r23
    b       _80082eac
_80082ea8:
    neg	r25, r25
_80082eac:
    cmplwi	r22, 0
    bc      12, 2, _80082f10
    lbz	r0, 0x1a(r1)
    cmpwi	r0, 2
    bc      12, 2, _80082ef4
    bc      4, 0, _80082ed4
    cmpwi	r0, 0
    bc      12, 2, _80082ee4
    bc      4, 0, _80082eec
    b       _80082f0c
_80082ed4:
    cmpwi	r0, 4
    bc      12, 2, _80082f04
    bc      4, 0, _80082f0c
    b       _80082efc
_80082ee4:
    stw	r25, 0(r22)
    b       _80082f0c
_80082eec:
    stb	r25, 0(r22)
    b       _80082f0c
_80082ef4:
    sth	r25, 0(r22)
    b       _80082f0c
_80082efc:
    stw	r25, 0(r22)
    b       _80082f0c
_80082f04:
    stw	r24, 4(r22)
    stw	r23, 0(r22)
_80082f0c:
    addi	r28, r28, 1
_80082f10:
    addi	r27, r27, 1
    b       _800833d4
_80082f18:
    lwz	r3, 0x1c(r1)
    mr	r4, r30
    mr	r5, r31
    addi	r6, r1, 0x14
    addi	r7, r1, 0xc
    bl      fn_80083F10
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _800833e0
    cmplwi	r22, 0
    add	r29, r29, r0
    bc      12, 2, _80082f8c
    lbz	r0, 0x1a(r1)
    cmpwi	r0, 5
    bc      12, 2, _80082f7c
    bc      4, 0, _80082f64
    cmpwi	r0, 0
    bc      12, 2, _80082f70
    b       _80082f88
_80082f64:
    cmpwi	r0, 7
    bc      4, 0, _80082f88
    b       _80082f84
_80082f70:
    frsp	f0, f1
    stfs	f0, 0(r22)
    b       _80082f88
_80082f7c:
    stfd	f1, 0(r22)
    b       _80082f88
_80082f84:
    stfd	f1, 0(r22)
_80082f88:
    addi	r28, r28, 1
_80082f8c:
    addi	r27, r27, 1
    b       _800833d4
_80082f94:
    lbz	r0, 0x19(r1)
    cmplwi	r0, 0
    bc      4, 2, _80082fa8
    li	r0, 1
    stw	r0, 0x1c(r1)
_80082fa8:
    cmplwi	r22, 0
    bc      12, 2, _80083044
    li	r0, 0
    stw	r0, 0x14(r1)
    b       _80082ff8
_80082fbc:
    lbz	r0, 0x1a(r1)
    stb	r3, 8(r1)
    cmplwi	r0, 7
    bc      4, 2, _80082fe4
    mr	r3, r22
    addi	r4, r1, 8
    li	r5, 1
    bl      fn_80080030
    addi	r22, r22, 1
    b       _80082fec
_80082fe4:
    stb	r3, 0(r22)
    addi	r22, r22, 1
_80082fec:
    lwz	r3, 0x14(r1)
    addi	r0, r3, 1
    stw	r0, 0x14(r1)
_80082ff8:
    lwz	r3, 0x1c(r1)
    addi	r0, r3, -1
    cmpwi	r3, 0
    stw	r0, 0x1c(r1)
    bc      12, 2, _8008302c
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    cmpwi	r3, -1
    bc      4, 2, _80082fbc
_8008302c:
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _800833e0
    add	r29, r29, r0
    addi	r28, r28, 1
    b       _800830a4
_80083044:
    li	r0, 0
    stw	r0, 0x14(r1)
    b       _8008305c
_80083050:
    lwz	r3, 0x14(r1)
    addi	r0, r3, 1
    stw	r0, 0x14(r1)
_8008305c:
    lwz	r3, 0x1c(r1)
    addi	r0, r3, -1
    cmpwi	r3, 0
    stw	r0, 0x1c(r1)
    bc      12, 2, _80083098
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    extsb	r0, r3
    stb	r3, 8(r1)
    cmpwi	r0, -1
    bc      4, 2, _80083050
_80083098:
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _800833e0
_800830a4:
    addi	r27, r27, 1
    b       _800833d4
_800830ac:
    lis     r3, lbl_8015B100@ha
    addi	r17, r3, lbl_8015B100@l
    b       _800830bc
_800830b8:
    addi	r29, r29, 1
_800830bc:
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    clrlwi	r0, r3, 0x18
    stb	r3, 8(r1)
    lbzx	r0, r17, r0
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      4, 2, _800830b8
    clrlwi	r0, r3, 0x18
    extsb	r4, r0
    cmpwi	r4, 0x25
    bc      12, 2, _80083110
    mr	r12, r30
    mr	r3, r31
    li	r5, 1
    mtctr	r12
    bctrl
    b       _800833e0
_80083110:
    addi	r29, r29, 1
    b       _800833d4
_80083118:
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    lis     r4, lbl_8015B100@ha
    stb	r3, 8(r1)
    addi	r17, r4, lbl_8015B100@l
    b       _80083160
_80083140:
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r29, r29, 1
    bctrl
    stb	r3, 8(r1)
_80083160:
    lbz	r4, 8(r1)
    extsb	r4, r4
    clrlwi	r0, r4, 0x18
    lbzx	r0, r17, r0
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      4, 2, _80083140
    mr	r12, r30
    mr	r3, r31
    li	r5, 1
    mtctr	r12
    bctrl
_8008318c:
    cmplwi	r22, 0
    bc      12, 2, _80083294
    li	r0, 0
    addi	r17, r1, 0x18
    stw	r0, 0x14(r1)
    b       _800831dc
_800831a4:
    lbz	r0, 0x1a(r1)
    cmplwi	r0, 7
    bc      4, 2, _800831c8
    mr	r3, r22
    addi	r4, r1, 8
    li	r5, 1
    bl      fn_80080030
    addi	r22, r22, 2
    b       _800831d0
_800831c8:
    stb	r5, 0(r22)
    addi	r22, r22, 1
_800831d0:
    lwz	r3, 0x14(r1)
    addi	r0, r3, 1
    stw	r0, 0x14(r1)
_800831dc:
    lwz	r3, 0x1c(r1)
    addi	r0, r3, -1
    cmpwi	r3, 0
    stw	r0, 0x1c(r1)
    bc      12, 2, _8008323c
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    extsb	r0, r3
    stb	r3, 8(r1)
    cmpwi	r0, -1
    bc      12, 2, _8008323c
    clrlwi	r5, r3, 0x18
    rlwinm	r3, r3, 0x1d, 0x1b, 0x1f
    addi	r4, r3, 8
    li	r3, 1
    clrlwi	r0, r5, 0x1d
    lbzx	r4, r17, r4
    slw	r0, r3, r0
    and.	r0, r4, r0
    bc      4, 2, _800831a4
_8008323c:
    lwz	r3, 0x14(r1)
    cmpwi	r3, 0
    bc      4, 2, _80083268
    lbz	r4, 8(r1)
    mr	r12, r30
    mr	r3, r31
    li	r5, 1
    extsb	r4, r4
    mtctr	r12
    bctrl
    b       _800833e0
_80083268:
    lbz	r0, 0x1a(r1)
    add	r29, r29, r3
    cmplwi	r0, 7
    bc      4, 2, _80083284
    li	r0, 0
    sth	r0, 0(r22)
    b       _8008328c
_80083284:
    li	r0, 0
    stb	r0, 0(r22)
_8008328c:
    addi	r28, r28, 1
    b       _80083340
_80083294:
    li	r0, 0
    addi	r17, r1, 0x18
    stw	r0, 0x14(r1)
    b       _800832b0
_800832a4:
    lwz	r3, 0x14(r1)
    addi	r0, r3, 1
    stw	r0, 0x14(r1)
_800832b0:
    lwz	r3, 0x1c(r1)
    addi	r0, r3, -1
    cmpwi	r3, 0
    stw	r0, 0x1c(r1)
    bc      12, 2, _80083310
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    extsb	r0, r3
    stb	r3, 8(r1)
    cmpwi	r0, -1
    bc      12, 2, _80083310
    clrlwi	r0, r3, 0x18
    rlwinm	r3, r3, 0x1d, 0x1b, 0x1f
    addi	r4, r3, 8
    li	r3, 1
    clrlwi	r0, r0, 0x1d
    lbzx	r4, r17, r4
    slw	r0, r3, r0
    and.	r0, r4, r0
    bc      4, 2, _800832a4
_80083310:
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      4, 2, _8008333c
    lbz	r4, 8(r1)
    mr	r12, r30
    mr	r3, r31
    li	r5, 1
    extsb	r4, r4
    mtctr	r12
    bctrl
    b       _800833d4
_8008333c:
    add	r29, r29, r0
_80083340:
    lwz	r0, 0x1c(r1)
    cmpwi	r0, 0
    bc      12, 0, _80083368
    lbz	r4, 8(r1)
    mr	r12, r30
    mr	r3, r31
    li	r5, 1
    extsb	r4, r4
    mtctr	r12
    bctrl
_80083368:
    addi	r27, r27, 1
    b       _800833d4
_80083370:
    cmplwi	r22, 0
    bc      12, 2, _800833d4
    lbz	r0, 0x1a(r1)
    cmpwi	r0, 2
    bc      12, 2, _800833b0
    bc      4, 0, _80083398
    cmpwi	r0, 0
    bc      12, 2, _800833a8
    bc      4, 0, _800833c0
    b       _800833d4
_80083398:
    cmpwi	r0, 4
    bc      12, 2, _800833c8
    bc      4, 0, _800833d4
    b       _800833b8
_800833a8:
    stw	r29, 0(r22)
    b       _800833d4
_800833b0:
    sth	r29, 0(r22)
    b       _800833d4
_800833b8:
    stw	r29, 0(r22)
    b       _800833d4
_800833c0:
    stb	r29, 0(r22)
    b       _800833d4
_800833c8:
    stw	r29, 4(r22)
    srawi	r0, r29, 0x1f
    stw	r0, 0(r22)
_800833d4:
    lbz	r0, 0(r26)
    extsb.	r17, r0
    bc      4, 2, _80082ab4
_800833e0:
    mr	r12, r30
    mr	r3, r31
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl
    cmpwi	r3, 0
    bc      12, 2, _80083410
    cmpwi	r27, 0
    bc      4, 2, _80083410
    li	r3, -1
    b       _80083414
_80083410:
    mr	r3, r28
_80083414:
    lmw	r16, 0x40(r1)
    lwz	r0, 0x84(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr
}

asm void fn_80083428(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    lis	r6, -0x7ff7
    lbzu	r5, 1(r3)
    stw	r31, 0x3c(r1)
    extsb	r5, r5
    stw	r30, 0x38(r1)
    cmpwi	r5, 0x25
    lwzu	r0, 0x4fe8(r6)
    lwz	r30, 4(r6)
    lwz	r31, 8(r6)
    lwz	r12, 0xc(r6)
    lwz	r11, 0x10(r6)
    lwz	r10, 0x14(r6)
    lwz	r9, 0x18(r6)
    lwz	r8, 0x1c(r6)
    lwz	r7, 0x20(r6)
    lwz	r6, 0x24(r6)
    stw	r0, 8(r1)
    stw	r30, 0xc(r1)
    stw	r31, 0x10(r1)
    stw	r12, 0x14(r1)
    stw	r11, 0x18(r1)
    stw	r10, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r8, 0x24(r1)
    stw	r7, 0x28(r1)
    stw	r6, 0x2c(r1)
    bc      4, 2, _800834d0
    stb	r5, 0xb(r1)
    addi	r3, r3, 1
    lwz	r0, 8(r1)
    stw	r0, 0(r4)
    stw	r30, 4(r4)
    stw	r31, 8(r4)
    stw	r12, 0xc(r4)
    stw	r11, 0x10(r4)
    stw	r10, 0x14(r4)
    stw	r9, 0x18(r4)
    stw	r8, 0x1c(r4)
    stw	r7, 0x20(r4)
    stw	r6, 0x24(r4)
    b       _80083960
_800834d0:
    cmpwi	r5, 0x2a
    bc      4, 2, _800834e8
    lbzu	r5, 1(r3)
    li	r0, 1
    stb	r0, 8(r1)
    extsb	r5, r5
_800834e8:
    lis     r6, lbl_8015B100@ha
    clrlwi	r0, r5, 0x18
    addi	r7, r6, lbl_8015B100@l
    lbzx	r0, r7, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      12, 2, _800835a0
    li	r0, 0
    stw	r0, 0xc(r1)
_80083508:
    lwz	r0, 0xc(r1)
    mulli	r0, r0, 0xa
    add	r6, r5, r0
    lbzu	r5, 1(r3)
    addi	r9, r6, -0x30
    extsb	r5, r5
    stw	r9, 0xc(r1)
    clrlwi	r0, r5, 0x18
    lbzx	r0, r7, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _80083508
    cmpwi	r9, 0
    bc      4, 2, _80083598
    li	r0, 0xff
    lwz	r6, 0x10(r1)
    stb	r0, 0xb(r1)
    addi	r3, r3, 1
    lwz	r5, 0x14(r1)
    lwz	r7, 8(r1)
    lwz	r0, 0x18(r1)
    stw	r7, 0(r4)
    lwz	r8, 0x1c(r1)
    stw	r9, 4(r4)
    lwz	r7, 0x20(r1)
    stw	r6, 8(r4)
    lwz	r6, 0x24(r1)
    stw	r5, 0xc(r4)
    lwz	r5, 0x28(r1)
    stw	r0, 0x10(r4)
    lwz	r0, 0x2c(r1)
    stw	r8, 0x14(r4)
    stw	r7, 0x18(r4)
    stw	r6, 0x1c(r4)
    stw	r5, 0x20(r4)
    stw	r0, 0x24(r4)
    b       _80083960
_80083598:
    li	r0, 1
    stb	r0, 9(r1)
_800835a0:
    cmpwi	r5, 0x68
    li	r7, 1
    bc      12, 2, _800835c8
    bc      4, 0, _800835bc
    cmpwi	r5, 0x4c
    bc      12, 2, _80083620
    b       _8008362c
_800835bc:
    cmpwi	r5, 0x6c
    bc      12, 2, _800835f4
    b       _8008362c
_800835c8:
    lbz	r0, 1(r3)
    li	r6, 2
    stb	r6, 0xa(r1)
    extsb	r6, r0
    cmpwi	r6, 0x68
    bc      4, 2, _80083630
    li	r0, 1
    mr	r5, r6
    stb	r0, 0xa(r1)
    addi	r3, r3, 1
    b       _80083630
_800835f4:
    lbz	r0, 1(r3)
    li	r6, 3
    stb	r6, 0xa(r1)
    extsb	r6, r0
    cmpwi	r6, 0x6c
    bc      4, 2, _80083630
    li	r0, 4
    mr	r5, r6
    stb	r0, 0xa(r1)
    addi	r3, r3, 1
    b       _80083630
_80083620:
    li	r0, 6
    stb	r0, 0xa(r1)
    b       _80083630
_8008362c:
    li	r7, 0
_80083630:
    cmpwi	r7, 0
    bc      12, 2, _80083640
    lbzu	r5, 1(r3)
    extsb	r5, r5
_80083640:
    addi	r0, r5, -0x45
    stb	r5, 0xb(r1)
    cmplwi	r0, 0x33
    bc      12, 1, _80083904
    lis     r5, -0x7fea
    slwi	r0, r0, 2
    addi	r5, r5, -0x4998
    lwzx	r0, r5, r0
    mtctr	r0
    bctr
    lbz	r0, 0xa(r1)
    cmplwi	r0, 6
    bc      4, 2, _8008390c
    li	r0, 0xff
    stb	r0, 0xb(r1)
    b       _8008390c
    lbz	r0, 0xa(r1)
    cmplwi	r0, 1
    bc      12, 2, _8008369c
    cmplwi	r0, 2
    bc      12, 2, _8008369c
    cmplwi	r0, 4
    bc      4, 2, _800836a8
_8008369c:
    li	r0, 0xff
    stb	r0, 0xb(r1)
    b       _8008390c
_800836a8:
    cmplwi	r0, 3
    bc      4, 2, _8008390c
    li	r0, 5
    stb	r0, 0xa(r1)
    b       _8008390c
    li	r5, 3
    li	r0, 0x78
    stb	r5, 0xa(r1)
    stb	r0, 0xb(r1)
    b       _8008390c
    lbz	r0, 0xa(r1)
    cmplwi	r0, 3
    bc      4, 2, _800836e8
    li	r0, 7
    stb	r0, 0xa(r1)
    b       _8008390c
_800836e8:
    cmplwi	r0, 0
    bc      12, 2, _8008390c
    li	r0, 0xff
    stb	r0, 0xb(r1)
    b       _8008390c
    lbz	r0, 0xa(r1)
    cmplwi	r0, 3
    bc      4, 2, _80083714
    li	r0, 7
    stb	r0, 0xa(r1)
    b       _80083724
_80083714:
    cmplwi	r0, 0
    bc      12, 2, _80083724
    li	r0, 0xff
    stb	r0, 0xb(r1)
_80083724:
    li	r0, 4
    addi	r6, r1, 0x10
    li	r5, 0xff
    mtctr	r0
_80083734:
    stb	r5, 0(r6)
    stb	r5, 1(r6)
    stb	r5, 2(r6)
    stb	r5, 3(r6)
    stb	r5, 4(r6)
    stb	r5, 5(r6)
    stb	r5, 6(r6)
    stb	r5, 7(r6)
    addi	r6, r6, 8
    bc      16, 0, _80083734
    li	r5, 0xc1
    li	r0, 0xfe
    stb	r5, 0x11(r1)
    stb	r0, 0x14(r1)
    b       _8008390c
    lbz	r0, 0xa(r1)
    cmplwi	r0, 3
    bc      4, 2, _80083788
    li	r0, 7
    stb	r0, 0xa(r1)
    b       _80083798
_80083788:
    cmplwi	r0, 0
    bc      12, 2, _80083798
    li	r0, 0xff
    stb	r0, 0xb(r1)
_80083798:
    lbzu	r10, 1(r3)
    li	r11, 0
    extsb	r10, r10
    cmpwi	r10, 0x5e
    bc      4, 2, _800837b8
    lbzu	r10, 1(r3)
    li	r11, 1
    extsb	r10, r10
_800837b8:
    cmpwi	r10, 0x5d
    bc      4, 2, _800837d4
    lbz	r0, 0x1b(r1)
    lbzu	r10, 1(r3)
    ori	r0, r0, 0x20
    stb	r0, 0x1b(r1)
    extsb	r10, r10
_800837d4:
    addi	r9, r1, 8
    b       _80083860
_800837dc:
    rlwinm	r5, r10, 0x1d, 0x1b, 0x1f
    lbz	r0, 1(r3)
    addi	r7, r5, 8
    li	r8, 1
    clrlwi	r5, r10, 0x1d
    lbzx	r6, r9, r7
    slw	r5, r8, r5
    cmpwi	r0, 0x2d
    or	r5, r6, r5
    stbx	r5, r9, r7
    bc      4, 2, _80083858
    lbz	r12, 2(r3)
    extsb.	r12, r12
    bc      12, 2, _80083858
    cmpwi	r12, 0x5d
    bc      12, 2, _80083858
    addi	r7, r1, 8
    b       _80083840
_80083824:
    rlwinm	r5, r10, 0x1d, 0x1b, 0x1f
    clrlwi	r0, r10, 0x1d
    addi	r6, r5, 8
    lbzx	r5, r7, r6
    slw	r0, r8, r0
    or	r0, r5, r0
    stbx	r0, r7, r6
_80083840:
    addi	r10, r10, 1
    cmpw	r10, r12
    bc      4, 1, _80083824
    lbzu	r10, 3(r3)
    extsb	r10, r10
    b       _80083860
_80083858:
    lbzu	r10, 1(r3)
    extsb	r10, r10
_80083860:
    cmpwi	r10, 0
    bc      12, 2, _80083870
    cmpwi	r10, 0x5d
    bc      4, 2, _800837dc
_80083870:
    cmpwi	r10, 0
    bc      4, 2, _80083884
    li	r0, 0xff
    stb	r0, 0xb(r1)
    b       _8008390c
_80083884:
    cmpwi	r11, 0
    bc      12, 2, _8008390c
    li	r0, 4
    addi	r5, r1, 0x10
    mtctr	r0
_80083898:
    lbz	r0, 0(r5)
    nor	r0, r0, r0
    stb	r0, 0(r5)
    lbz	r0, 1(r5)
    nor	r0, r0, r0
    stb	r0, 1(r5)
    lbz	r0, 2(r5)
    nor	r0, r0, r0
    stb	r0, 2(r5)
    lbz	r0, 3(r5)
    nor	r0, r0, r0
    stb	r0, 3(r5)
    lbz	r0, 4(r5)
    nor	r0, r0, r0
    stb	r0, 4(r5)
    lbz	r0, 5(r5)
    nor	r0, r0, r0
    stb	r0, 5(r5)
    lbz	r0, 6(r5)
    nor	r0, r0, r0
    stb	r0, 6(r5)
    lbz	r0, 7(r5)
    nor	r0, r0, r0
    stb	r0, 7(r5)
    addi	r5, r5, 8
    bc      16, 0, _80083898
    b       _8008390c
_80083904:
    li	r0, 0xff
    stb	r0, 0xb(r1)
_8008390c:
    lwz	r5, 8(r1)
    addi	r3, r3, 1
    lwz	r0, 0xc(r1)
    stw	r5, 0(r4)
    lwz	r5, 0x10(r1)
    stw	r0, 4(r4)
    lwz	r0, 0x14(r1)
    stw	r5, 8(r4)
    lwz	r5, 0x18(r1)
    stw	r0, 0xc(r4)
    lwz	r0, 0x1c(r1)
    stw	r5, 0x10(r4)
    lwz	r5, 0x20(r1)
    stw	r0, 0x14(r4)
    lwz	r0, 0x24(r1)
    stw	r5, 0x18(r4)
    lwz	r5, 0x28(r1)
    stw	r0, 0x1c(r4)
    lwz	r0, 0x2c(r1)
    stw	r5, 0x20(r4)
    stw	r0, 0x24(r4)
_80083960:
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    addi	r1, r1, 0x40
    blr
}

asm void fn_80083970(void)
{
    nofralloc
    cmplwi	r4, 0
    addi	r5, r3, -1
    beqlr	
    lbz	r6, 0(r4)
    cmplwi	r6, 0
    bc      4, 2, _800839c4
    blr
_8008398c:
    cmplw	r0, r6
    bc      4, 2, _800839c4
    addi	r7, r5, -1
    addi	r8, r4, -1
_8008399c:
    lbzu	r0, 1(r7)
    lbzu	r3, 1(r8)
    cmplw	r0, r3
    bc      4, 2, _800839b4
    cmplwi	r0, 0
    bc      4, 2, _8008399c
_800839b4:
    cmplwi	r3, 0
    bc      4, 2, _800839c4
    mr	r3, r5
    blr
_800839c4:
    lbzu	r0, 1(r5)
    cmplwi	r0, 0
    bc      4, 2, _8008398c
    li	r3, 0
    blr
}

asm void fn_800839D8(void)
{
    nofralloc
    lis     r5, lbl_80095010@ha
    stwu	r1, -0x30(r1)
    addi	r12, r5, lbl_80095010@l
    cmplwi	r3, 0
    lwz	r11, 0(r12)
    lwz	r10, 4(r12)
    lwz	r9, 8(r12)
    lwz	r8, 0xc(r12)
    lwz	r7, 0x10(r12)
    lwz	r6, 0x14(r12)
    lwz	r5, 0x18(r12)
    lwz	r0, 0x1c(r12)
    stw	r11, 8(r1)
    stw	r10, 0xc(r1)
    stw	r9, 0x10(r1)
    stw	r8, 0x14(r1)
    stw	r7, 0x18(r1)
    stw	r6, 0x1c(r1)
    stw	r5, 0x20(r1)
    stw	r0, 0x24(r1)
    bc      12, 2, _80083a30
    stw	r3, -0x7d7c(r13)
_80083a30:
    addi	r7, r4, -1
    addi	r5, r1, 8
    li	r3, 1
    b       _80083a58
_80083a40:
    rlwinm	r6, r0, 0x1d, 0x1b, 0x1f
    clrlwi	r0, r0, 0x1d
    lbzx	r4, r5, r6
    slw	r0, r3, r0
    or	r0, r4, r0
    stbx	r0, r5, r6
_80083a58:
    lbzu	r0, 1(r7)
    cmpwi	r0, 0
    bc      4, 2, _80083a40
    lwz	r4, -0x7d7c(r13)
    addi	r5, r1, 8
    li	r3, 1
    addi	r7, r4, -1
    b       _80083a90
_80083a78:
    rlwinm	r4, r6, 0x1d, 0x1b, 0x1f
    clrlwi	r0, r6, 0x1d
    lbzx	r4, r5, r4
    slw	r0, r3, r0
    and.	r0, r4, r0
    bc      12, 2, _80083a9c
_80083a90:
    lbzu	r6, 1(r7)
    cmpwi	r6, 0
    bc      4, 2, _80083a78
_80083a9c:
    cmpwi	r6, 0
    bc      4, 2, _80083ab4
    lwz	r0, -0x7d80(r13)
    li	r3, 0
    stw	r0, -0x7d7c(r13)
    b       _80083b0c
_80083ab4:
    mr	r3, r7
    addi	r6, r1, 8
    li	r4, 1
    b       _80083adc
_80083ac4:
    rlwinm	r5, r8, 0x1d, 0x1b, 0x1f
    clrlwi	r0, r8, 0x1d
    lbzx	r5, r6, r5
    slw	r0, r4, r0
    and.	r0, r5, r0
    bc      4, 2, _80083ae8
_80083adc:
    lbzu	r8, 1(r7)
    cmpwi	r8, 0
    bc      4, 2, _80083ac4
_80083ae8:
    cmpwi	r8, 0
    bc      4, 2, _80083afc
    lwz	r0, -0x7d80(r13)
    stw	r0, -0x7d7c(r13)
    b       _80083b0c
_80083afc:
    addi	r4, r7, 1
    li	r0, 0
    stw	r4, -0x7d7c(r13)
    stb	r0, 0(r7)
_80083b0c:
    addi	r1, r1, 0x30
    blr
}

asm void fn_80083B14(void)
{
    nofralloc
    addi	r5, r3, -1
    clrlwi	r0, r4, 0x18
    li	r3, 0
    b       _80083b30
_80083b24:
    cmplw	r4, r0
    bc      4, 2, _80083b30
    mr	r3, r5
_80083b30:
    lbzu	r4, 1(r5)
    cmplwi	r4, 0
    bc      4, 2, _80083b24
    cmplwi	r3, 0
    bnelr	
    cmplwi	r0, 0
    bc      12, 2, _80083b54
    li	r3, 0
    blr
_80083b54:
    mr	r3, r5
    blr
}

asm void strchr(void)
{
    nofralloc
    addi	r3, r3, -1
    clrlwi	r0, r4, 0x18
    b       _80083b70
_80083b68:
    cmplw	r4, r0
    beqlr	
_80083b70:
    lbzu	r4, 1(r3)
    cmplwi	r4, 0
    bc      4, 2, _80083b68
    cmplwi	r0, 0
    beqlr	
    li	r3, 0
    blr
}

asm void fn_80083B8C(void)
{
    nofralloc
    addi	r3, r3, -1
    addi	r4, r4, -1
    addi	r6, r5, 1
    b       _80083bbc
_80083b9c:
    lbzu	r0, 1(r3)
    lbzu	r5, 1(r4)
    cmplw	r0, r5
    bc      12, 2, _80083bb4
    subf	r3, r5, r0
    blr
_80083bb4:
    cmplwi	r0, 0
    bc      12, 2, _80083bc4
_80083bbc:
    addic.	r6, r6, -1
    bc      4, 2, _80083b9c
_80083bc4:
    li	r3, 0
    blr
}

asm void fn_80083BCC(void)
{
    nofralloc
    lbz	r5, 0(r3)
    lbz	r0, 0(r4)
    subf.	r0, r0, r5
    bc      12, 2, _80083be4
    mr	r3, r0
    blr
_80083be4:
    clrlwi	r0, r4, 0x1e
    clrlwi	r6, r3, 0x1e
    cmplw	r0, r6
    bc      4, 2, _80083cbc
    cmplwi	r6, 0
    bc      12, 2, _80083c50
    cmplwi	r5, 0
    bc      4, 2, _80083c0c
    li	r3, 0
    blr
_80083c0c:
    subfic	r0, r6, 3
    mtctr	r0
    cmplwi	r0, 0
    bc      12, 2, _80083c48
_80083c1c:
    lbzu	r5, 1(r3)
    lbzu	r0, 1(r4)
    subf.	r0, r0, r5
    bc      12, 2, _80083c34
    mr	r3, r0
    blr
_80083c34:
    cmplwi	r5, 0
    bc      4, 2, _80083c44
    li	r3, 0
    blr
_80083c44:
    bc      16, 0, _80083c1c
_80083c48:
    addi	r3, r3, 1
    addi	r4, r4, 1
_80083c50:
    lwz	r7, 0(r3)
    lis	r5, -0x7f7f
    addi	r6, r5, -0x7f80
    lwz	r8, 0(r4)
    addis	r5, r7, -0x101
    addi	r0, r5, -0x101
    and.	r0, r0, r6
    bc      4, 2, _80083ca4
    b       _80083c8c
_80083c74:
    lwzu	r7, 4(r3)
    lwzu	r8, 4(r4)
    addis	r5, r7, -0x101
    addi	r0, r5, -0x101
    and.	r0, r0, r6
    bc      4, 2, _80083ca4
_80083c8c:
    cmplw	r7, r8
    bc      12, 2, _80083c74
    li	r3, -1
    blelr	
    li	r3, 1
    blr
_80083ca4:
    lbz	r5, 0(r3)
    lbz	r0, 0(r4)
    subf.	r0, r0, r5
    bc      12, 2, _80083cbc
    mr	r3, r0
    blr
_80083cbc:
    cmplwi	r5, 0
    bc      4, 2, _80083ccc
    li	r3, 0
    blr
_80083ccc:
    lbzu	r5, 1(r3)
    lbzu	r0, 1(r4)
    subf.	r0, r0, r5
    bc      12, 2, _80083ce4
    mr	r3, r0
    blr
_80083ce4:
    cmplwi	r5, 0
    bc      4, 2, _80083ccc
    li	r3, 0
    blr
}

asm void fn_80083CF4(void)
{
    nofralloc
    addi	r4, r4, -1
    addi	r6, r3, -1
_80083cfc:
    lbzu	r0, 1(r6)
    cmplwi	r0, 0
    bc      4, 2, _80083cfc
    addi	r6, r6, -1
    addi	r5, r5, 1
    b       _80083d2c
_80083d14:
    lbzu	r0, 1(r4)
    cmplwi	r0, 0
    stbu	r0, 1(r6)
    bc      4, 2, _80083d2c
    addi	r6, r6, -1
    b       _80083d34
_80083d2c:
    addic.	r5, r5, -1
    bc      4, 2, _80083d14
_80083d34:
    li	r0, 0
    stb	r0, 1(r6)
    blr
}

#pragma force_active off
