#pragma push
#pragma force_active on

extern void fn_800454CC(void);
extern void fn_800454B4(void);
extern void fn_800454C4(void);
extern void fn_800454D4(void);
extern void fn_800454DC(void);
extern void fn_800454E4(void);
extern void fn_800454FC(void);
extern void fn_80045504(void);
extern void criadx_get_stream_ptr(void);
extern void fn_80045514(void);
extern void fn_8004551C(void);
extern void criadx_get_field_0E(void);
extern void criadx_get_field_14(void);
extern void criadx_get_status(void);
extern void fn_80045414(void);
extern void fn_80041BF8(void);
extern void fn_80044E7C(void);
extern void fn_80045304(void);
extern void fn_800452FC(void);
extern void svm_ringbuf_read(void);
extern void fn_8004530C(void);
extern void ADXB_DecodeHeader(void);
extern unsigned char lbl_801798C0[2496];

asm void fn_80041460(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r4
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r3, 4(r3)
    bl      fn_800454CC
    cmpwi	r3, 0
    ble     _800414b4
    lbz	r0, 1(r30)
    extsb	r0, r0
    cmpwi	r0, 2
    beq     _800414a4
    cmpwi	r0, 3
    bne     _800414b4
_800414a4:
    lwz	r3, 4(r30)
    mr	r4, r31
    bl      fn_800454B4
    b       _800414b8
_800414b4:
    li	r3, -0x80
_800414b8:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800414D0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lwz	r3, 4(r3)
    bl      fn_800454CC
    cmpwi	r3, 0
    ble     _80041518
    lbz	r0, 1(r31)
    extsb	r0, r0
    cmpwi	r0, 2
    beq     _8004150c
    cmpwi	r0, 3
    bne     _80041518
_8004150c:
    lwz	r3, 4(r31)
    bl      fn_800454C4
    b       _8004151c
_80041518:
    li	r3, 0
_8004151c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80041530(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      fn_800454D4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80041554(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      fn_800454DC
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80041578(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80041594
    li	r3, 0
    b       _8004159c
_80041594:
    lwz	r3, 4(r3)
    bl      fn_800454E4
_8004159c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800415AC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      fn_800454FC
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800415D0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      fn_80045504
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void criadx_get_stream_ptr_wrapper(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      criadx_get_stream_ptr
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80041618(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      fn_80045514
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004163C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      fn_8004551C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80041660(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      criadx_get_field_0E
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void criadxGetValue(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      criadx_get_field_14
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800416A8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 4(r3)
    bl      criadx_get_status
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800416CC(void)
{
    nofralloc
    stw	r4, 0x44(r3)
    blr	
}

asm void criadx_set_field_40(void)
{
    nofralloc
    stw	r4, 0x40(r3)
    blr	
}

asm void criadx_set_field_3C(void)
{
    nofralloc
    stw	r4, 0x3c(r3)
    blr	
}

asm void fn_800416E4(void)
{
    nofralloc
    stw	r4, 0x48(r3)
    stw	r5, 0x4c(r3)
    blr	
}

asm void fn_800416F0(void)
{
    nofralloc
    stw	r4, 0x34(r3)
    blr	
}

asm void fn_800416F8(void)
{
    nofralloc
    lwz	r3, 0x2c(r3)
    blr	
}

asm void fn_80041700(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    lis     r3, lbl_801798C0@ha
    stw	r0, 0x44(r1)
    stmw	r22, 0x18(r1)
    li	r26, 0
    addi	r28, r3, lbl_801798C0@l
_8004171c:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8004196c
    lbz	r0, 1(r28)
    extsb	r0, r0
    cmpwi	r0, 2
    bne     _8004195c
    lwz	r31, 4(r28)
    mr	r3, r31
    bl      fn_80045414
    cmpwi	r3, 0
    bne     _80041754
    mr	r3, r28
    bl      fn_80041BF8
_80041754:
    mr	r3, r31
    bl      fn_80044E7C
    mr	r3, r31
    bl      fn_80045414
    cmpwi	r3, 3
    bne     _800418d8
    lwz	r29, 4(r28)
    lwz	r25, 8(r28)
    mr	r3, r29
    bl      criadx_get_stream_ptr
    mr	r27, r3
    mr	r3, r29
    bl      fn_80045304
    mr	r30, r3
    mr	r3, r29
    bl      fn_800452FC
    lwz	r0, 0x34(r28)
    subf	r27, r0, r27
    cmpw	r3, r27
    bge     _800417a8
    mr	r27, r3
_800417a8:
    mr	r4, r30
    addi	r3, r28, 0x14
    addi	r5, r1, 8
    addi	r6, r1, 0x10
    bl      svm_ringbuf_read
    lwz	r6, 0(r25)
    mr	r3, r25
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r25)
    mr	r3, r25
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    mr	r24, r28
    mr	r23, r28
    slwi	r22, r27, 1
    li	r25, 0
    b       _80041884
_80041808:
    mr	r4, r22
    addi	r3, r24, 0x1c
    addi	r5, r1, 8
    addi	r6, r1, 0x10
    bl      svm_ringbuf_read
    lwz	r12, 0x50(r28)
    cmplwi	r12, 0
    beq     _80041840
    mr	r4, r25
    lwz	r3, 0x54(r28)
    lwz	r5, 8(r1)
    lwz	r6, 0xc(r1)
    mtctr	r12
    bctrl	
_80041840:
    lwz	r3, 0xc(r23)
    addi	r5, r1, 8
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r3, 0xc(r23)
    addi	r5, r1, 0x10
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r24, r24, 8
    addi	r23, r23, 4
    addi	r25, r25, 1
_80041884:
    lwz	r3, 4(r28)
    bl      criadx_get_field_0E
    cmpw	r25, r3
    blt     _80041808
    lwz	r0, 0x2c(r28)
    mr	r3, r29
    add	r0, r0, r27
    stw	r0, 0x2c(r28)
    lwz	r0, 0x30(r28)
    add	r0, r0, r30
    stw	r0, 0x30(r28)
    lwz	r0, 0x34(r28)
    add	r0, r0, r27
    stw	r0, 0x34(r28)
    lwz	r0, 0x40(r28)
    add	r0, r0, r27
    stw	r0, 0x40(r28)
    lwz	r0, 0x44(r28)
    add	r0, r0, r30
    stw	r0, 0x44(r28)
    bl      fn_8004530C
_800418d8:
    lha	r0, 0x98(r31)
    cmpwi	r0, 0xa
    beq     _800418fc
    cmpwi	r0, 0x14
    beq     _800418fc
    cmpwi	r0, 0xb
    beq     _800418fc
    cmpwi	r0, 0xf
    bne     _8004196c
_800418fc:
    lwz	r25, 4(r28)
    mr	r3, r25
    bl      criadx_get_stream_ptr
    mr	r29, r3
    mr	r3, r25
    bl      fn_80045304
    mr	r27, r3
    mr	r3, r25
    bl      fn_800452FC
    lwz	r0, 0x34(r28)
    subf	r4, r0, r29
    cmpw	r3, r4
    bge     _80041934
    mr	r4, r3
_80041934:
    lwz	r0, 0x2c(r28)
    add	r0, r0, r4
    stw	r0, 0x2c(r28)
    lwz	r0, 0x30(r28)
    add	r0, r0, r27
    stw	r0, 0x30(r28)
    lwz	r0, 0x34(r28)
    add	r0, r0, r4
    stw	r0, 0x34(r28)
    b       _8004196c
_8004195c:
    cmpwi	r0, 1
    bne     _8004196c
    mr	r3, r28
    bl      ADXB_DecodeHeader
_8004196c:
    addi	r26, r26, 1
    addi	r28, r28, 0x9c
    cmpwi	r26, 0x10
    blt     _8004171c
    lmw	r22, 0x18(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_80041990(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stmw	r23, 0x1c(r1)
    mr	r27, r3
    lbz	r0, 1(r3)
    extsb	r0, r0
    cmpwi	r0, 2
    bne     _80041bd8
    lwz	r31, 4(r27)
    mr	r3, r31
    bl      fn_80045414
    cmpwi	r3, 0
    bne     _800419d0
    mr	r3, r27
    bl      fn_80041BF8
_800419d0:
    mr	r3, r31
    bl      fn_80044E7C
    mr	r3, r31
    bl      fn_80045414
    cmpwi	r3, 3
    bne     _80041b54
    lwz	r29, 4(r27)
    lwz	r26, 8(r27)
    mr	r3, r29
    bl      criadx_get_stream_ptr
    mr	r28, r3
    mr	r3, r29
    bl      fn_80045304
    mr	r30, r3
    mr	r3, r29
    bl      fn_800452FC
    lwz	r0, 0x34(r27)
    subf	r28, r0, r28
    cmpw	r3, r28
    bge     _80041a24
    mr	r28, r3
_80041a24:
    mr	r4, r30
    addi	r3, r27, 0x14
    addi	r5, r1, 8
    addi	r6, r1, 0x10
    bl      svm_ringbuf_read
    lwz	r6, 0(r26)
    mr	r3, r26
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r26)
    mr	r3, r26
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    mr	r25, r27
    mr	r24, r27
    slwi	r23, r28, 1
    li	r26, 0
    b       _80041b00
_80041a84:
    mr	r4, r23
    addi	r3, r25, 0x1c
    addi	r5, r1, 8
    addi	r6, r1, 0x10
    bl      svm_ringbuf_read
    lwz	r12, 0x50(r27)
    cmplwi	r12, 0
    beq     _80041abc
    mr	r4, r26
    lwz	r3, 0x54(r27)
    lwz	r5, 8(r1)
    lwz	r6, 0xc(r1)
    mtctr	r12
    bctrl	
_80041abc:
    lwz	r3, 0xc(r24)
    addi	r5, r1, 8
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r3, 0xc(r24)
    addi	r5, r1, 0x10
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r25, r25, 8
    addi	r24, r24, 4
    addi	r26, r26, 1
_80041b00:
    lwz	r3, 4(r27)
    bl      criadx_get_field_0E
    cmpw	r26, r3
    blt     _80041a84
    lwz	r0, 0x2c(r27)
    mr	r3, r29
    add	r0, r0, r28
    stw	r0, 0x2c(r27)
    lwz	r0, 0x30(r27)
    add	r0, r0, r30
    stw	r0, 0x30(r27)
    lwz	r0, 0x34(r27)
    add	r0, r0, r28
    stw	r0, 0x34(r27)
    lwz	r0, 0x40(r27)
    add	r0, r0, r28
    stw	r0, 0x40(r27)
    lwz	r0, 0x44(r27)
    add	r0, r0, r30
    stw	r0, 0x44(r27)
    bl      fn_8004530C
_80041b54:
    lha	r0, 0x98(r31)
    cmpwi	r0, 0xa
    beq     _80041b78
    cmpwi	r0, 0x14
    beq     _80041b78
    cmpwi	r0, 0xb
    beq     _80041b78
    cmpwi	r0, 0xf
    bne     _80041be4
_80041b78:
    lwz	r26, 4(r27)
    mr	r3, r26
    bl      criadx_get_stream_ptr
    mr	r29, r3
    mr	r3, r26
    bl      fn_80045304
    mr	r28, r3
    mr	r3, r26
    bl      fn_800452FC
    lwz	r0, 0x34(r27)
    subf	r4, r0, r29
    cmpw	r3, r4
    bge     _80041bb0
    mr	r4, r3
_80041bb0:
    lwz	r0, 0x2c(r27)
    add	r0, r0, r4
    stw	r0, 0x2c(r27)
    lwz	r0, 0x30(r27)
    add	r0, r0, r28
    stw	r0, 0x30(r27)
    lwz	r0, 0x34(r27)
    add	r0, r0, r4
    stw	r0, 0x34(r27)
    b       _80041be4
_80041bd8:
    cmpwi	r0, 1
    bne     _80041be4
    bl      ADXB_DecodeHeader
_80041be4:
    lmw	r23, 0x1c(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

#pragma pop
