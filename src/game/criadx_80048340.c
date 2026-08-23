#pragma push
#pragma force_active on

extern void strlen(void);
extern void memcpy(void);

asm void fn_80048340(void)
{
    nofralloc
    stwu	r1, -0x150(r1)
    mflr	r0
    lis	r5, -0x7fed
    stw	r0, 0x154(r1)
    stmw	r27, 0x13c(r1)
    mr	r27, r3
    addi	r3, r5, -0x4704
    mr	r28, r4
    lwz	r3, 0(r3)
    bl      strlen
    lwz	r4, 0(r28)
    mr	r0, r3
    lis	r5, -0x8000
    mr	r3, r28
    lwz	r12, 0x18(r4)
    mr	r31, r0
    addi	r5, r5, -1
    addi	r6, r1, 0x124
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r4, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x124
    lwz	r29, 0x128(r1)
    lwz	r12, 0x1c(r4)
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r3, 0x48(r27)
    addi	r0, r3, 4
    cmpw	r29, r0
    bge     _800483cc
    li	r3, 0
    b       _80049714
_800483cc:
    lwz	r4, 0(r28)
    lis	r3, 1
    addi	r0, r3, -0x8000
    mr	r3, r28
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0x11c
    sth	r0, 0xe(r1)
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x120(r1)
    cmpwi	r0, 2
    bge     _80048428
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x11c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048454
_80048428:
    lwz	r6, 0x11c(r1)
    mr	r3, r28
    lha	r0, 0xe(r1)
    addi	r5, r1, 0x11c
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048454:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x48(r27)
    addi	r6, r1, 0x114
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xa(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x118(r1)
    cmpwi	r0, 2
    bge     _800484b4
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x114
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800484e0
_800484b4:
    lwz	r6, 0x114(r1)
    mr	r3, r28
    lha	r0, 0xa(r1)
    addi	r5, r1, 0x114
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800484e0:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r0, 0x4c(r27)
    mr	r3, r28
    addi	r6, r1, 0x10c
    li	r4, 0
    stb	r0, 8(r1)
    li	r5, 1
    lwz	r7, 0(r28)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0x110(r1)
    cmpwi	r0, 1
    bge     _80048540
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x10c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048570
_80048540:
    lwz	r3, 0x10c(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x10c
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048570:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r0, 0x50(r27)
    mr	r3, r28
    addi	r6, r1, 0x104
    li	r4, 0
    stb	r0, 8(r1)
    li	r5, 1
    lwz	r7, 0(r28)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0x108(r1)
    cmpwi	r0, 1
    bge     _800485d0
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x104
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048600
_800485d0:
    lwz	r3, 0x104(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x104
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048600:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r0, 0x54(r27)
    mr	r3, r28
    addi	r6, r1, 0xfc
    li	r4, 0
    stb	r0, 8(r1)
    li	r5, 1
    lwz	r7, 0(r28)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0x100(r1)
    cmpwi	r0, 1
    bge     _80048660
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xfc
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048690
_80048660:
    lwz	r3, 0xfc(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xfc
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048690:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r0, 0x58(r27)
    mr	r3, r28
    addi	r6, r1, 0xf4
    li	r4, 0
    stb	r0, 8(r1)
    li	r5, 1
    lwz	r7, 0(r28)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0xf8(r1)
    cmpwi	r0, 1
    bge     _800486f0
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xf4
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048720
_800486f0:
    lwz	r3, 0xf4(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xf4
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048720:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x5c(r27)
    addi	r6, r1, 0xec
    lwz	r12, 0x18(r4)
    li	r4, 0
    stw	r0, 0x10(r1)
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0xf0(r1)
    cmpwi	r0, 4
    bge     _80048780
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xec
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800487ac
_80048780:
    lwz	r6, 0xec(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0xec
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800487ac:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x60(r27)
    addi	r6, r1, 0xe4
    lwz	r12, 0x18(r4)
    li	r4, 0
    stw	r0, 0x10(r1)
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0xe8(r1)
    cmpwi	r0, 4
    bge     _8004880c
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xe4
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048838
_8004880c:
    lwz	r6, 0xe4(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0xe4
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048838:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x64(r27)
    addi	r6, r1, 0xdc
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0xe0(r1)
    cmpwi	r0, 2
    bge     _80048898
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xdc
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800488c4
_80048898:
    lwz	r6, 0xdc(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0xdc
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800488c4:
    cmpwi	r0, 1
    bne     _80049710
    li	r0, 4
    mr	r3, r28
    stb	r0, 8(r1)
    addi	r6, r1, 0xd4
    li	r4, 0
    li	r5, 1
    lwz	r7, 0(r28)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0xd8(r1)
    cmpwi	r0, 1
    bge     _80048924
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xd4
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048954
_80048924:
    lwz	r3, 0xd4(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xd4
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048954:
    cmpwi	r0, 1
    bne     _80049710
    lha	r4, 0x2d0(r27)
    li	r0, 8
    mr	r3, r28
    addi	r6, r1, 0xcc
    cntlzw	r5, r4
    li	r4, 0
    rlwinm	r7, r5, 0x1b, 0x1f, 0x1f
    li	r5, 1
    neg	r7, r7
    andc	r0, r0, r7
    stb	r0, 8(r1)
    lwz	r7, 0(r28)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0xd0(r1)
    cmpwi	r0, 1
    bge     _800489c8
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xcc
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800489f8
_800489c8:
    lwz	r3, 0xcc(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xcc
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800489f8:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    li	r0, 0
    mr	r3, r28
    stw	r0, 0x10(r1)
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0xc4
    li	r4, 0
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0xc8(r1)
    cmpwi	r0, 4
    bge     _80048a58
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xc4
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048a84
_80048a58:
    lwz	r6, 0xc4(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0xc4
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048a84:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lha	r0, 0x2c8(r27)
    addi	r6, r1, 0xbc
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0xc0(r1)
    cmpwi	r0, 2
    bge     _80048ae4
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xbc
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048b10
_80048ae4:
    lwz	r6, 0xbc(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0xbc
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048b10:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lha	r0, 0x2cc(r27)
    addi	r6, r1, 0xb4
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0xb8(r1)
    cmpwi	r0, 2
    bge     _80048b70
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xb4
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048b9c
_80048b70:
    lwz	r6, 0xb4(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0xb4
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048b9c:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lha	r0, 0x2ca(r27)
    addi	r6, r1, 0xac
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0xb0(r1)
    cmpwi	r0, 2
    bge     _80048bfc
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xac
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048c28
_80048bfc:
    lwz	r6, 0xac(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0xac
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048c28:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lha	r0, 0x2ce(r27)
    addi	r6, r1, 0xa4
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0xa8(r1)
    cmpwi	r0, 2
    bge     _80048c88
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0xa4
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048cb4
_80048c88:
    lwz	r6, 0xa4(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0xa4
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048cb4:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r0, 0x6c(r27)
    li	r30, 0x1c
    cmpwi	r0, 0
    ble     _80049148
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x68(r27)
    addi	r6, r1, 0x9c
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0xa0(r1)
    cmpwi	r0, 2
    bge     _80048d24
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x9c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048d50
_80048d24:
    lwz	r6, 0x9c(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0x9c
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048d50:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x6c(r27)
    addi	r6, r1, 0x94
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x98(r1)
    cmpwi	r0, 2
    bge     _80048db0
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x94
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048ddc
_80048db0:
    lwz	r6, 0x94(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0x94
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048ddc:
    cmpwi	r0, 1
    bne     _80049710
    li	r29, 0
    li	r30, 0x20
    b       _8004913c
_80048df0:
    lwz	r4, 0(r28)
    mr	r3, r28
    sth	r29, 0xc(r1)
    addi	r6, r1, 0x8c
    lwz	r12, 0x18(r4)
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x90(r1)
    cmpwi	r0, 2
    bge     _80048e44
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x8c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048e70
_80048e44:
    lwz	r6, 0x8c(r1)
    extsh	r0, r29
    mr	r3, r28
    addi	r5, r1, 0x8c
    sth	r0, 0(r6)
    li	r4, 1
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048e70:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    li	r0, 1
    mr	r3, r28
    sth	r0, 0xc(r1)
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0x84
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x88(r1)
    cmpwi	r0, 2
    bge     _80048ed0
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x84
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048efc
_80048ed0:
    lwz	r6, 0x84(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0x84
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048efc:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x70(r27)
    addi	r6, r1, 0x7c
    lwz	r12, 0x18(r4)
    li	r4, 0
    stw	r0, 0x10(r1)
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0x80(r1)
    cmpwi	r0, 4
    bge     _80048f5c
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x7c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80048f88
_80048f5c:
    lwz	r6, 0x7c(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0x7c
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80048f88:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x74(r27)
    addi	r6, r1, 0x74
    lwz	r12, 0x18(r4)
    li	r4, 0
    stw	r0, 0x10(r1)
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0x78(r1)
    cmpwi	r0, 4
    bge     _80048fe8
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x74
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80049014
_80048fe8:
    lwz	r6, 0x74(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0x74
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80049014:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x78(r27)
    addi	r6, r1, 0x6c
    lwz	r12, 0x18(r4)
    li	r4, 0
    stw	r0, 0x10(r1)
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0x70(r1)
    cmpwi	r0, 4
    bge     _80049074
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x6c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800490a0
_80049074:
    lwz	r6, 0x6c(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0x6c
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800490a0:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r0, 0x7c(r27)
    addi	r6, r1, 0x64
    lwz	r12, 0x18(r4)
    li	r4, 0
    stw	r0, 0x10(r1)
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0x68(r1)
    cmpwi	r0, 4
    bge     _80049100
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x64
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _8004912c
_80049100:
    lwz	r6, 0x64(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0x64
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_8004912c:
    cmpwi	r0, 1
    bne     _80049710
    addi	r30, r30, 0x14
    addi	r29, r29, 1
_8004913c:
    lwz	r0, 0x6c(r27)
    cmpw	r29, r0
    blt     _80048df0
_80049148:
    lbz	r0, 0x2d6(r27)
    cmpwi	r0, 1
    bne     _800495c8
    lwz	r0, 0x6c(r27)
    cmpwi	r0, 0
    bne     _800491f0
    lwz	r4, 0(r28)
    li	r0, 0
    mr	r3, r28
    stw	r0, 0x10(r1)
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0x5c
    li	r4, 0
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0x60(r1)
    cmpwi	r0, 4
    bge     _800491b8
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x5c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800491e4
_800491b8:
    lwz	r6, 0x5c(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0x5c
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800491e4:
    cmpwi	r0, 1
    bne     _80049710
    addi	r30, r30, 4
_800491f0:
    lwz	r4, 0(r28)
    lis	r3, 0x4149
    addi	r0, r3, 0x4e46
    mr	r3, r28
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0x54
    stw	r0, 0x10(r1)
    li	r4, 0
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0x58(r1)
    cmpwi	r0, 4
    bge     _8004924c
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x54
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80049278
_8004924c:
    lwz	r6, 0x54(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0x54
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80049278:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    li	r0, 0x18
    mr	r3, r28
    stw	r0, 0x10(r1)
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0x4c
    li	r4, 0
    li	r5, 4
    mtctr	r12
    bctrl	
    lwz	r0, 0x50(r1)
    cmpwi	r0, 4
    bge     _800492d8
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x4c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80049304
_800492d8:
    lwz	r6, 0x4c(r1)
    mr	r3, r28
    lwz	r0, 0x10(r1)
    addi	r5, r1, 0x4c
    li	r4, 1
    stw	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80049304:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r5, 0(r28)
    mr	r3, r28
    addi	r6, r1, 0x44
    li	r4, 0
    lwz	r12, 0x18(r5)
    li	r5, 0x10
    mtctr	r12
    bctrl	
    lwz	r0, 0x48(r1)
    cmpwi	r0, 0x10
    bge     _8004935c
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x44
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _8004938c
_8004935c:
    lwz	r3, 0x44(r1)
    addi	r4, r27, 0x2d7
    li	r5, 0x10
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x44
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 0x10
_8004938c:
    cmplwi	r0, 0x10
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lha	r0, 0x2e8(r27)
    addi	r6, r1, 0x3c
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x40(r1)
    cmpwi	r0, 2
    bge     _800493ec
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x3c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80049418
_800493ec:
    lwz	r6, 0x3c(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0x3c
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80049418:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    li	r0, 0
    mr	r3, r28
    sth	r0, 0xc(r1)
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0x34
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x38(r1)
    cmpwi	r0, 2
    bge     _80049478
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x34
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800494a4
_80049478:
    lwz	r6, 0x34(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0x34
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800494a4:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lha	r0, 0x2ea(r27)
    addi	r6, r1, 0x2c
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x30(r1)
    cmpwi	r0, 2
    bge     _80049504
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x2c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _80049530
_80049504:
    lwz	r6, 0x2c(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0x2c
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_80049530:
    cmpwi	r0, 1
    bne     _80049710
    lwz	r4, 0(r28)
    mr	r3, r28
    lha	r0, 0x2ec(r27)
    addi	r6, r1, 0x24
    lwz	r12, 0x18(r4)
    li	r4, 0
    sth	r0, 0xc(r1)
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x28(r1)
    cmpwi	r0, 2
    bge     _80049590
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x24
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800495bc
_80049590:
    lwz	r6, 0x24(r1)
    mr	r3, r28
    lha	r0, 0xc(r1)
    addi	r5, r1, 0x24
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r28)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_800495bc:
    cmpwi	r0, 1
    bne     _80049710
    addi	r30, r30, 0x20
_800495c8:
    li	r0, 0
    stb	r0, 8(r1)
    lwz	r0, 0x48(r27)
    subf	r27, r31, r0
    b       _80049668
_800495dc:
    lwz	r5, 0(r28)
    mr	r3, r28
    addi	r6, r1, 0x1c
    li	r4, 0
    lwz	r12, 0x18(r5)
    li	r5, 1
    mtctr	r12
    bctrl	
    lwz	r0, 0x20(r1)
    cmpwi	r0, 1
    bge     _8004962c
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x1c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _8004965c
_8004962c:
    lwz	r3, 0x1c(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x1c
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 1
_8004965c:
    cmpwi	r0, 1
    bne     _80049710
    addi	r30, r30, 1
_80049668:
    cmpw	r30, r27
    blt     _800495dc
    lwz	r4, 0(r28)
    lis	r3, -0x7fed
    addi	r7, r3, -0x4704
    mr	r3, r28
    lwz	r12, 0x18(r4)
    mr	r5, r31
    addi	r6, r1, 0x14
    lwz	r27, 0(r7)
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r0, 0x18(r1)
    cmpw	r0, r31
    bge     _800496cc
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x14
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    b       _800496fc
_800496cc:
    lwz	r3, 0x14(r1)
    clrlwi	r5, r31, 0x10
    mr	r4, r27
    bl      memcpy
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 0x14
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    mr	r0, r31
_800496fc:
    cmpw	r31, r0
    bne     _80049710
    add	r30, r30, r31
    addi	r3, r30, 4
    b       _80049714
_80049710:
    li	r3, 0
_80049714:
    lmw	r27, 0x13c(r1)
    lwz	r0, 0x154(r1)
    mtlr	r0
    addi	r1, r1, 0x150
    blr	
}

#pragma pop
