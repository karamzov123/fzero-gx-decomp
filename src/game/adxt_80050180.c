#pragma push
#pragma force_active on

extern void fn_800502A0(void);
extern void svm_ringbuf_read(void);
extern void memset(void);
extern unsigned char getCupModeConst_value_tbl[4];
extern unsigned char lbl_8012D9BC[12292];
extern unsigned char lbl_801309C0[136];
extern unsigned char lbl_80186FAC[356];

asm void fn_80050180(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r4, 1
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lwz	r3, 4(r3)
    lwz	r5, 0(r3)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bne     _800501d4
    lwz	r0, 0xc(r31)
    cmpwi	r0, 0
    bne     _800501d4
    lwz	r0, 0x24(r31)
    cmpwi	r0, 0
    bne     _800501d4
    li	r3, 1
    b       _800501d8
_800501d4:
    li	r3, 0
_800501d8:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800501EC(void)
{
    nofralloc
    lwz	r3, 0x10(r3)
    blr	
}

asm void fn_800501F4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r5, -0x7fe8
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    stw	r30, 8(r1)
    mr	r30, r4
    lwzu	r4, 0x6fa8(r5)
    addi	r0, r4, 1
    stw	r0, 0(r5)
    lwz	r0, 0xc(r3)
    cmpw	r0, r30
    bge     _80050230
    bl      fn_800502A0
_80050230:
    lwz	r5, 0xc(r31)
    cmpw	r30, r5
    ble     _80050258
    lwz	r4, 0x10(r31)
    li	r0, 0
    li	r3, 0
    add	r4, r4, r5
    stw	r4, 0x10(r31)
    stw	r0, 0xc(r31)
    b       _80050288
_80050258:
    lis     r3, lbl_801309C0@ha
    slwi	r0, r30, 2
    addi	r4, r3, lbl_801309C0@l
    lwz	r3, 8(r31)
    lwzx	r0, r4, r0
    subf	r4, r30, r5
    sraw	r3, r3, r4
    stw	r4, 0xc(r31)
    and	r3, r3, r0
    lwz	r0, 0x10(r31)
    add	r0, r0, r30
    stw	r0, 0x10(r31)
_80050288:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800502A0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    stw	r30, 0x18(r1)
    lwz	r0, 0xc(r3)
    lwz	r4, 0x24(r3)
    subfic	r0, r0, 0x20
    srawi	r0, r0, 3
    cmpwi	r4, 4
    addze	r30, r0
    bge     _80050368
    lwz	r0, 0x20(r31)
    lwz	r3, 0x1c(r31)
    cmpwi	r0, 0
    stw	r3, 0x10(r1)
    stw	r0, 0x14(r1)
    beq     _80050338
    addi	r3, r1, 0x10
    subf	r4, r4, r0
    mr	r5, r3
    addi	r6, r1, 8
    bl      svm_ringbuf_read
    lwz	r3, 4(r31)
    addi	r5, r1, 0x10
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r3, 4(r31)
    addi	r5, r1, 8
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
_80050338:
    lwz	r3, 4(r31)
    addi	r6, r31, 0x1c
    lwz	r5, 0x18(r31)
    li	r4, 1
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0x1c(r31)
    stw	r0, 0x28(r31)
    lwz	r0, 0x20(r31)
    stw	r0, 0x24(r31)
_80050368:
    lwz	r0, 0x24(r31)
    cmpw	r30, r0
    bge     _80050378
    mr	r0, r30
_80050378:
    cmpwi	r0, 3
    bne     _800503c8
    lwz	r6, 0x28(r31)
    lwz	r5, 8(r31)
    lbz	r4, 0(r6)
    lbz	r3, 1(r6)
    rlwimi	r4, r5, 8, 0, 0x17
    lbz	r0, 2(r6)
    addi	r6, r6, 3
    rlwimi	r3, r4, 8, 0, 0x17
    stw	r6, 0x28(r31)
    rlwimi	r0, r3, 8, 0, 0x17
    stw	r0, 8(r31)
    lwz	r3, 0xc(r31)
    addi	r0, r3, 0x18
    stw	r0, 0xc(r31)
    lwz	r3, 0x24(r31)
    addi	r0, r3, -3
    stw	r0, 0x24(r31)
    b       _800504a4
_800503c8:
    cmpwi	r0, 2
    bne     _80050410
    lwz	r3, 0x28(r31)
    lwz	r5, 8(r31)
    lbz	r4, 0(r3)
    lbz	r0, 1(r3)
    addi	r3, r3, 2
    rlwimi	r4, r5, 8, 0, 0x17
    stw	r3, 0x28(r31)
    rlwimi	r0, r4, 8, 0, 0x17
    stw	r0, 8(r31)
    lwz	r3, 0xc(r31)
    addi	r0, r3, 0x10
    stw	r0, 0xc(r31)
    lwz	r3, 0x24(r31)
    addi	r0, r3, -2
    stw	r0, 0x24(r31)
    b       _800504a4
_80050410:
    cmpwi	r0, 1
    bne     _80050450
    lwz	r3, 0x28(r31)
    lwz	r4, 8(r31)
    lbz	r0, 0(r3)
    addi	r3, r3, 1
    rlwimi	r0, r4, 8, 0, 0x17
    stw	r3, 0x28(r31)
    stw	r0, 8(r31)
    lwz	r3, 0xc(r31)
    addi	r0, r3, 8
    stw	r0, 0xc(r31)
    lwz	r3, 0x24(r31)
    addi	r0, r3, -1
    stw	r0, 0x24(r31)
    b       _800504a4
_80050450:
    cmpwi	r0, 4
    bne     _800504a4
    lwz	r3, 0x28(r31)
    lwz	r7, 8(r31)
    lbz	r6, 0(r3)
    lbz	r5, 1(r3)
    rlwimi	r6, r7, 8, 0, 0x17
    lbz	r4, 2(r3)
    rlwimi	r5, r6, 8, 0, 0x17
    lbz	r0, 3(r3)
    addi	r3, r3, 4
    rlwimi	r4, r5, 8, 0, 0x17
    stw	r3, 0x28(r31)
    rlwimi	r0, r4, 8, 0, 0x17
    stw	r0, 8(r31)
    lwz	r3, 0xc(r31)
    addi	r0, r3, 0x20
    stw	r0, 0xc(r31)
    lwz	r3, 0x24(r31)
    addi	r0, r3, -4
    stw	r0, 0x24(r31)
_800504a4:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800504BC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    beq     _800504dc
    li	r4, 0
    li	r5, 0x2c
    bl      memset
_800504dc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800504EC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r4, lbl_80186FAC@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    addi	r3, r4, lbl_80186FAC@l
    li	r4, 0
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    beq     _800505ac
    addi	r3, r3, 0x2c
    li	r4, 1
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    beq     _800505ac
    lwz	r0, 0x2c(r3)
    li	r4, 2
    addi	r3, r3, 0x2c
    cmpwi	r0, 0
    beq     _800505ac
    lwz	r0, 0x2c(r3)
    li	r4, 3
    addi	r3, r3, 0x2c
    cmpwi	r0, 0
    beq     _800505ac
    lwz	r0, 0x2c(r3)
    li	r4, 4
    addi	r3, r3, 0x2c
    cmpwi	r0, 0
    beq     _800505ac
    lwz	r0, 0x2c(r3)
    li	r4, 5
    addi	r3, r3, 0x2c
    cmpwi	r0, 0
    beq     _800505ac
    lwz	r0, 0x2c(r3)
    li	r4, 6
    addi	r3, r3, 0x2c
    cmpwi	r0, 0
    beq     _800505ac
    lwz	r0, 0x2c(r3)
    li	r4, 7
    cmpwi	r0, 0
    beq     _800505ac
    li	r4, 8
_800505ac:
    cmpwi	r4, 8
    blt     _800505bc
    li	r3, 0
    b       _80050654
_800505bc:
    mulli	r5, r4, 0x2c
    lis     r3, lbl_80186FAC@ha
    li	r4, 0
    addi	r0, r3, lbl_80186FAC@l
    add	r30, r0, r5
    li	r5, 0x2c
    mr	r3, r30
    bl      memset
    stw	r29, 4(r30)
    li	r0, 0
    mr	r3, r29
    li	r4, 0
    stw	r0, 0x10(r30)
    lwz	r5, 0(r29)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    lwz	r5, 0(r29)
    mr	r31, r3
    mr	r3, r29
    li	r4, 1
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    add	r0, r3, r31
    li	r4, 0
    stw	r0, 0x14(r30)
    li	r0, 1
    mr	r3, r30
    lwz	r5, 0x14(r30)
    srawi	r5, r5, 2
    addze	r5, r5
    stw	r5, 0x18(r30)
    stw	r4, 0x24(r30)
    stw	r4, 0x1c(r30)
    stw	r4, 0x20(r30)
    stw	r4, 0x28(r30)
    stw	r0, 0(r30)
_80050654:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void getCupModeConst(void)
{
    nofralloc
    mulli	r7, r3, 0x3000
    lis     r6, lbl_8012D9BC@ha
    lis     r5, getCupModeConst_value_tbl@ha
    addi	r0, r6, lbl_8012D9BC@l
    add	r6, r0, r7
    slwi	r0, r3, 2
    stw	r6, 0(r4)
    addi	r3, r5, getCupModeConst_value_tbl@l
    lwzx	r3, r3, r0
    blr	
}

#pragma pop
