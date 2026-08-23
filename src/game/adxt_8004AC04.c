#pragma push
#pragma force_active on

extern void fn_80046718(void);
extern void fn_80046738(void);
extern void fn_80046F7C(void);
extern void fn_8004A5F4(void);
extern void fn_800547C8(void);
extern void fn_80058A40(void);
extern void fn_80059AB4(void);
extern void fn_80059B44(void);
extern void memset(void);

asm void fn_8004AC04(void)
{
    nofralloc
    cmpwi	r4, 0
    blt     _8004ac14
    stw	r4, 0x2c(r3)
    blr	
_8004ac14:
    lwz	r6, 0x10(r3)
    slwi	r0, r6, 0x15
    srwi	r5, r6, 0x1f
    subf	r4, r5, r0
    srawi	r0, r6, 0xb
    rotlwi	r4, r4, 0xb
    add	r5, r4, r5
    addze	r0, r0
    neg	r4, r5
    andc	r4, r4, r5
    srwi	r4, r4, 0x1f
    add	r0, r0, r4
    stw	r0, 0x2c(r3)
    blr	
}

asm void fn_8004AC4C(void)
{
    nofralloc
    stw	r4, 0x34(r3)
    stw	r5, 0x38(r3)
    blr	
}

asm void fn_8004AC58(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    lwz	r3, 8(r3)
    cmplwi	r3, 0
    beq     _8004ac94
    lbz	r0, 0x42(r31)
    extsb.	r0, r0
    bne     _8004ac94
    bl      fn_800547C8
_8004ac94:
    bl      fn_80059B44
    li	r3, 1
    li	r0, 0
    stb	r3, 1(r31)
    stb	r0, 2(r31)
    stw	r0, 0x20(r31)
    bl      fn_80059AB4
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004acec
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004acec
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004acf4
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004acf4
_8004acec:
    li	r0, 1
    stb	r0, 1(r31)
_8004acf4:
    bl      fn_80059AB4
    lis	r3, -0x7fe8
    addi	r30, r3, -0x2904
_8004ad00:
    mr	r3, r30
    bl      fn_80058A40
    cmpwi	r3, 0
    beq     _8004ad4c
    lis	r3, -0x7fe8
    li	r29, 0
    addi	r28, r3, -0x28f8
_8004ad1c:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8004ad30
    mr	r3, r28
    bl      fn_8004A5F4
_8004ad30:
    addi	r29, r29, 1
    addi	r28, r28, 0x5c
    cmpwi	r29, 0x28
    blt     _8004ad1c
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x2904(r3)
_8004ad4c:
    lbz	r0, 1(r31)
    cmpwi	r0, 1
    bne     _8004ad00
    lwz	r0, 0x20(r31)
    cmplwi	r0, 0
    bne     _8004ad00
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004AD84(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004add4
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004add4
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004addc
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004addc
_8004add4:
    li	r0, 1
    stb	r0, 1(r31)
_8004addc:
    bl      fn_80059AB4
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004ADF4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      fn_80046738
    li	r0, 0
    stw	r0, 0x30(r31)
    stb	r0, 3(r31)
    lwz	r0, 0x10(r31)
    cmpwi	r0, 0
    bne     _8004ae30
    li	r0, 3
    stb	r0, 1(r31)
    b       _8004ae38
_8004ae30:
    li	r0, 2
    stb	r0, 1(r31)
_8004ae38:
    li	r5, 0
    lis	r3, 0x10
    stb	r5, 2(r31)
    li	r4, 1
    addi	r0, r3, -1
    stw	r5, 0x20(r31)
    stw	r5, 0x24(r31)
    stb	r4, 0x43(r31)
    stw	r0, 0x58(r31)
    bl      fn_80046718
    lwz	r0, 0x14(r1)
    li	r3, 1
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004AE78(void)
{
    nofralloc
    lwz	r0, 8(r3)
    cmplwi	r0, 0
    beq     _8004ae8c
    lwz	r3, 0x54(r3)
    blr	
_8004ae8c:
    li	r3, 0
    blr	
}

asm void fn_8004AE94(void)
{
    nofralloc
    stw	r4, 0x54(r3)
    lwz	r0, 0x54(r3)
    lwz	r5, 0x10(r3)
    slwi	r0, r0, 0xb
    cmpw	r0, r5
    ble     _8004aedc
    slwi	r0, r5, 0x15
    srwi	r4, r5, 0x1f
    subf	r0, r4, r0
    srawi	r5, r5, 0xb
    rotlwi	r0, r0, 0xb
    add	r4, r0, r4
    addze	r5, r5
    neg	r0, r4
    andc	r0, r0, r4
    srwi	r0, r0, 0x1f
    add	r0, r5, r0
    stw	r0, 0x54(r3)
_8004aedc:
    lwz	r3, 0x54(r3)
    blr	
}

asm void fn_8004AEE4(void)
{
    nofralloc
    lbz	r3, 1(r3)
    extsb	r3, r3
    blr	
}

asm void fn_8004AEF0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    lwz	r3, 8(r3)
    cmplwi	r3, 0
    beq     _8004af2c
    lbz	r0, 0x42(r31)
    extsb.	r0, r0
    bne     _8004af2c
    bl      fn_800547C8
_8004af2c:
    bl      fn_80059B44
    li	r3, 1
    li	r0, 0
    stb	r3, 1(r31)
    stb	r0, 2(r31)
    stw	r0, 0x20(r31)
    bl      fn_80059AB4
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004af84
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004af84
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004af8c
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004af8c
_8004af84:
    li	r0, 1
    stb	r0, 1(r31)
_8004af8c:
    bl      fn_80059AB4
    lis	r3, -0x7fe8
    addi	r30, r3, -0x2904
_8004af98:
    mr	r3, r30
    bl      fn_80058A40
    cmpwi	r3, 0
    beq     _8004afe4
    lis	r3, -0x7fe8
    li	r29, 0
    addi	r28, r3, -0x28f8
_8004afb4:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8004afc8
    mr	r3, r28
    bl      fn_8004A5F4
_8004afc8:
    addi	r29, r29, 1
    addi	r28, r28, 0x5c
    cmpwi	r29, 0x28
    blt     _8004afb4
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x2904(r3)
_8004afe4:
    lbz	r0, 1(r31)
    cmpwi	r0, 1
    bne     _8004af98
    lwz	r0, 0x20(r31)
    cmplwi	r0, 0
    bne     _8004af98
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004b038
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004b038
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004b040
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004b040
_8004b038:
    li	r0, 1
    stb	r0, 1(r31)
_8004b040:
    bl      fn_80059AB4
    bl      fn_80059B44
    lbz	r0, 0x45(r31)
    cmpwi	r0, 1
    bne     _8004b05c
    li	r0, 1
    stb	r0, 0x42(r31)
_8004b05c:
    li	r0, 0
    stb	r0, 0x41(r31)
    bl      fn_80059AB4
    lis	r3, -0x7fe8
    addi	r30, r3, -0x2904
_8004b070:
    lbz	r0, 0x45(r31)
    extsb.	r0, r0
    beq     _8004b0cc
    mr	r3, r30
    bl      fn_80058A40
    cmpwi	r3, 0
    beq     _8004b070
    lis	r3, -0x7fe8
    li	r29, 0
    addi	r28, r3, -0x28f8
_8004b098:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8004b0ac
    mr	r3, r28
    bl      fn_8004A5F4
_8004b0ac:
    addi	r29, r29, 1
    addi	r28, r28, 0x5c
    cmpwi	r29, 0x28
    blt     _8004b098
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x2904(r3)
    b       _8004b070
_8004b0cc:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004B0EC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004b13c
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004b13c
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004b144
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004b144
_8004b13c:
    li	r0, 1
    stb	r0, 1(r31)
_8004b144:
    bl      fn_80059AB4
    bl      fn_80059B44
    lbz	r0, 0x45(r31)
    cmpwi	r0, 1
    bne     _8004b160
    li	r0, 1
    stb	r0, 0x42(r31)
_8004b160:
    li	r0, 0
    stb	r0, 0x41(r31)
    bl      fn_80059AB4
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004B180(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r27, r3
    mr	r28, r4
    mr	r29, r5
    mr	r30, r6
    mr	r31, r7
    bl      fn_80059B44
    stw	r30, 0xc(r27)
    slwi	r3, r31, 0xb
    li	r0, 1
    stw	r3, 0x10(r27)
    stw	r28, 0x4c(r27)
    stw	r29, 0x50(r27)
    stb	r0, 0x41(r27)
    bl      fn_80059AB4
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004B1DC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    or.	r31, r3, r3
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    beq     _8004b4c0
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8004b21c
    lbz	r0, 0x42(r31)
    extsb.	r0, r0
    bne     _8004b21c
    bl      fn_800547C8
_8004b21c:
    bl      fn_80059B44
    li	r3, 1
    li	r0, 0
    stb	r3, 1(r31)
    stb	r0, 2(r31)
    stw	r0, 0x20(r31)
    bl      fn_80059AB4
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004b274
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004b274
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004b27c
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004b27c
_8004b274:
    li	r0, 1
    stb	r0, 1(r31)
_8004b27c:
    bl      fn_80059AB4
    lis	r3, -0x7fe8
    addi	r30, r3, -0x2904
_8004b288:
    mr	r3, r30
    bl      fn_80058A40
    cmpwi	r3, 0
    beq     _8004b2d4
    lis	r3, -0x7fe8
    li	r29, 0
    addi	r28, r3, -0x28f8
_8004b2a4:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8004b2b8
    mr	r3, r28
    bl      fn_8004A5F4
_8004b2b8:
    addi	r29, r29, 1
    addi	r28, r28, 0x5c
    cmpwi	r29, 0x28
    blt     _8004b2a4
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x2904(r3)
_8004b2d4:
    lbz	r0, 1(r31)
    cmpwi	r0, 1
    bne     _8004b288
    lwz	r0, 0x20(r31)
    cmplwi	r0, 0
    bne     _8004b288
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8004b308
    lbz	r0, 0x42(r31)
    extsb.	r0, r0
    bne     _8004b308
    bl      fn_800547C8
_8004b308:
    bl      fn_80059B44
    li	r3, 1
    li	r0, 0
    stb	r3, 1(r31)
    stb	r0, 2(r31)
    stw	r0, 0x20(r31)
    bl      fn_80059AB4
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004b360
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004b360
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004b368
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004b368
_8004b360:
    li	r0, 1
    stb	r0, 1(r31)
_8004b368:
    bl      fn_80059AB4
    lis	r3, -0x7fe8
    addi	r30, r3, -0x2904
_8004b374:
    mr	r3, r30
    bl      fn_80058A40
    cmpwi	r3, 0
    beq     _8004b3c0
    lis	r3, -0x7fe8
    li	r29, 0
    addi	r28, r3, -0x28f8
_8004b390:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8004b3a4
    mr	r3, r28
    bl      fn_8004A5F4
_8004b3a4:
    addi	r29, r29, 1
    addi	r28, r28, 0x5c
    cmpwi	r29, 0x28
    blt     _8004b390
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x2904(r3)
_8004b3c0:
    lbz	r0, 1(r31)
    cmpwi	r0, 1
    bne     _8004b374
    lwz	r0, 0x20(r31)
    cmplwi	r0, 0
    bne     _8004b374
    bl      fn_80059B44
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004b414
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8004b414
    li	r0, 1
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004b41c
    li	r0, 0
    stb	r0, 0x43(r31)
    b       _8004b41c
_8004b414:
    li	r0, 1
    stb	r0, 1(r31)
_8004b41c:
    bl      fn_80059AB4
    bl      fn_80059B44
    lbz	r0, 0x45(r31)
    cmpwi	r0, 1
    bne     _8004b438
    li	r0, 1
    stb	r0, 0x42(r31)
_8004b438:
    li	r0, 0
    stb	r0, 0x41(r31)
    bl      fn_80059AB4
    lis	r3, -0x7fe8
    addi	r30, r3, -0x2904
_8004b44c:
    lbz	r0, 0x45(r31)
    extsb.	r0, r0
    beq     _8004b4a8
    mr	r3, r30
    bl      fn_80058A40
    cmpwi	r3, 0
    beq     _8004b44c
    lis	r3, -0x7fe8
    li	r29, 0
    addi	r28, r3, -0x28f8
_8004b474:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8004b488
    mr	r3, r28
    bl      fn_8004A5F4
_8004b488:
    addi	r29, r29, 1
    addi	r28, r28, 0x5c
    cmpwi	r29, 0x28
    blt     _8004b474
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x2904(r3)
    b       _8004b44c
_8004b4a8:
    li	r0, 0
    mr	r3, r31
    stb	r0, 0(r31)
    li	r4, 0
    li	r5, 0x5c
    bl      memset
_8004b4c0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004B4E0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    cmpwi	r4, 0x100
    lis	r4, -0x7fed
    stw	r0, 0x24(r1)
    addi	r5, r4, -0x4700
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    bge     _8004b64c
    lis	r3, -0x7fe8
    li	r31, 0
    addi	r4, r3, -0x2908
    lis	r3, -0x7fe8
    lwz	r0, 0(r4)
    mr	r6, r31
    lwz	r5, 0(r5)
    addi	r4, r3, -0x28f8
    mulli	r3, r0, 0x5c
    mtctr	r5
    cmpwi	r5, 0
    ble     _8004b558
_8004b53c:
    add	r31, r4, r3
    lbz	r0, 0(r31)
    extsb.	r0, r0
    beq     _8004b558
    addi	r3, r3, 0x5c
    addi	r6, r6, 1
    bdnz    _8004b53c
_8004b558:
    cmpw	r6, r5
    bne     _8004b568
    li	r31, 0
    b       _8004b644
_8004b568:
    bl      fn_80046738
    li	r0, 1
    lis	r3, 0x10
    stb	r0, 1(r31)
    li	r5, 0
    li	r4, 0x200
    addi	r0, r3, -1
    stb	r5, 2(r31)
    stw	r30, 4(r31)
    stw	r5, 8(r31)
    stw	r5, 0xc(r31)
    stw	r5, 0x10(r31)
    stw	r4, 0x28(r31)
    stw	r5, 0x54(r31)
    stw	r0, 0x58(r31)
    lwz	r0, 0x10(r31)
    srawi	r0, r0, 0xb
    addze	r0, r0
    stw	r0, 0x2c(r31)
    lwz	r3, 0x10(r31)
    slwi	r0, r3, 0x15
    srwi	r3, r3, 0x1f
    subf	r0, r3, r0
    rotlwi	r0, r0, 0xb
    add.	r0, r0, r3
    ble     _8004b5dc
    lwz	r3, 0x2c(r31)
    addi	r0, r3, 1
    stw	r0, 0x2c(r31)
_8004b5dc:
    lwz	r0, 4(r31)
    cmplwi	r0, 0
    beq     _8004b630
    lwz	r5, 0(r30)
    mr	r3, r30
    li	r4, 1
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    lwz	r5, 0(r30)
    mr	r29, r3
    mr	r3, r30
    li	r4, 0
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    add	r0, r3, r29
    stw	r0, 0x3c(r31)
    lwz	r0, 0x3c(r31)
    stw	r0, 0x14(r31)
    stw	r0, 0x18(r31)
_8004b630:
    li	r3, 0
    li	r0, 1
    stb	r3, 0x40(r31)
    stb	r0, 0(r31)
    bl      fn_80046718
_8004b644:
    mr	r3, r31
    b       _8004b780
_8004b64c:
    lwz	r0, 4(r5)
    li	r31, 0
    lis	r3, -0x7fe8
    lwz	r6, 8(r5)
    mr	r5, r31
    addi	r4, r3, -0x28f8
    mulli	r3, r0, 0x5c
    mtctr	r6
    cmpwi	r6, 0
    ble     _8004b690
_8004b674:
    add	r31, r4, r3
    lbz	r0, 0(r31)
    extsb.	r0, r0
    beq     _8004b690
    addi	r3, r3, 0x5c
    addi	r5, r5, 1
    bdnz    _8004b674
_8004b690:
    cmpw	r5, r6
    bne     _8004b6a0
    li	r31, 0
    b       _8004b77c
_8004b6a0:
    bl      fn_80046738
    li	r0, 1
    lis	r3, 0x10
    stb	r0, 1(r31)
    li	r5, 0
    li	r4, 0x200
    addi	r0, r3, -1
    stb	r5, 2(r31)
    stw	r30, 4(r31)
    stw	r5, 8(r31)
    stw	r5, 0xc(r31)
    stw	r5, 0x10(r31)
    stw	r4, 0x28(r31)
    stw	r5, 0x54(r31)
    stw	r0, 0x58(r31)
    lwz	r0, 0x10(r31)
    srawi	r0, r0, 0xb
    addze	r0, r0
    stw	r0, 0x2c(r31)
    lwz	r3, 0x10(r31)
    slwi	r0, r3, 0x15
    srwi	r3, r3, 0x1f
    subf	r0, r3, r0
    rotlwi	r0, r0, 0xb
    add.	r0, r0, r3
    ble     _8004b714
    lwz	r3, 0x2c(r31)
    addi	r0, r3, 1
    stw	r0, 0x2c(r31)
_8004b714:
    lwz	r0, 4(r31)
    cmplwi	r0, 0
    beq     _8004b768
    lwz	r5, 0(r30)
    mr	r3, r30
    li	r4, 1
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    lwz	r5, 0(r30)
    mr	r29, r3
    mr	r3, r30
    li	r4, 0
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    add	r0, r3, r29
    stw	r0, 0x3c(r31)
    lwz	r0, 0x3c(r31)
    stw	r0, 0x14(r31)
    stw	r0, 0x18(r31)
_8004b768:
    li	r3, 0
    li	r0, 1
    stb	r3, 0x40(r31)
    stb	r0, 0(r31)
    bl      fn_80046718
_8004b77c:
    mr	r3, r31
_8004b780:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004B79C(void)
{
    nofralloc
    blr	
}

asm void fn_8004B7A0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe8
    li	r4, 0
    stw	r0, 0x14(r1)
    addi	r3, r3, -0x28f8
    li	r5, 0xe60
    bl      memset
    lwz	r0, 0x14(r1)
    li	r3, 1
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004B7D4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80046F7C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
