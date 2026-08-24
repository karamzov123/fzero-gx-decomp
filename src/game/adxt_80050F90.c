#pragma push
#pragma force_active on

extern void fn_8004FF68(void);
extern void svm_ringbuf_skip(void);
extern void getCupModeConst(void);
extern void ADXF_Stop(void);
extern void fn_80050BD4(void);
extern void fn_80053A30(void);
extern void fn_80053DB4(void);
extern unsigned char adxt_sample_rate_table[32];
extern unsigned char lbl_80130B68[48];
extern unsigned char lbl_80187118[24];

asm void ADXF_StreamTeardown(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r26, 8(r1)
    mr	r31, r3
    mr	r27, r4
    mr	r26, r5
    lwz	r0, 0x348(r3)
    lwz	r28, 0x388(r3)
    cmpwi	r0, 0xc
    bne     _80050fc4
    li	r3, 0
    b       _800510b0
_80050fc4:
    bl      fn_80053A30
    lis     r5, lbl_80187118@ha
    addi	r4, r31, 0x384
    addi	r6, r5, lbl_80187118@l
    addi	r5, r31, 0x3b8
    stw	r3, 0(r6)
    addi	r6, r31, 0x5b8
    lwz	r0, 0x348(r31)
    lwz	r3, 0x34c(r31)
    lwz	r8, 0(r31)
    srawi	r7, r0, 2
    bl      ADXF_Stop
    bl      fn_80053A30
    lis     r4, lbl_80187118@ha
    mr	r30, r27
    addi	r4, r4, lbl_80187118@l
    li	r27, 0
    stw	r3, 0xc(r4)
    li	r29, 0
_80051010:
    lwz	r0, 0(r31)
    mr	r6, r30
    lwz	r3, 0x350(r31)
    li	r5, 0
    add	r4, r0, r29
    bl      fn_80053DB4
    addi	r27, r27, 1
    addi	r29, r29, 0x80
    cmpwi	r27, 3
    addi	r30, r30, 0x40
    blt     _80051010
    bl      fn_80053A30
    lis     r4, lbl_80187118@ha
    cmpwi	r28, 2
    addi	r4, r4, lbl_80187118@l
    stw	r3, 0x10(r4)
    blt     _80051090
    li	r28, 0
    mr	r29, r26
    mr	r30, r28
_80051060:
    lwz	r0, 0(r31)
    addi	r4, r30, 0x180
    lwz	r3, 0x350(r31)
    mr	r6, r29
    add	r4, r0, r4
    li	r5, 1
    bl      fn_80053DB4
    addi	r28, r28, 1
    addi	r30, r30, 0x80
    cmpwi	r28, 3
    addi	r29, r29, 0x40
    blt     _80051060
_80051090:
    bl      fn_80053A30
    lis     r4, lbl_80187118@ha
    addi	r4, r4, lbl_80187118@l
    stw	r3, 0x14(r4)
    li	r3, 0x60
    lwz	r4, 0x348(r31)
    addi	r0, r4, 1
    stw	r0, 0x348(r31)
_800510b0:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800510C4(void)
{
    nofralloc
    lwz	r0, 0x348(r3)
    subfic	r0, r0, 0xc
    cntlzw	r0, r0
    srwi	r3, r0, 5
    blr	
}

asm void ADXT_GetStreamStatus(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stmw	r21, 0x14(r1)
    mr	r29, r3
    lwz	r3, 0x34c(r3)
    cmplwi	r3, 0
    bne     _80051100
    li	r3, 0
    b       _80051434
_80051100:
    bl      fn_8004FF68
    cmpwi	r3, 1
    beq     _80051114
    li	r3, 1
    b       _80051434
_80051114:
    lwz	r30, 0x34c(r29)
    li	r4, 1
    mr	r3, r30
    bl      svm_ringbuf_skip
    stw	r3, 0x354(r29)
    mr	r3, r30
    li	r4, 2
    bl      svm_ringbuf_skip
    subfic	r0, r3, 4
    mr	r3, r30
    stw	r0, 0x358(r29)
    li	r4, 1
    bl      svm_ringbuf_skip
    cntlzw	r0, r3
    mr	r3, r30
    srwi	r0, r0, 5
    li	r4, 4
    stw	r0, 0x35c(r29)
    bl      svm_ringbuf_skip
    stw	r3, 0x360(r29)
    mr	r3, r30
    li	r4, 2
    bl      svm_ringbuf_skip
    stw	r3, 0x364(r29)
    mr	r3, r30
    li	r4, 1
    bl      svm_ringbuf_skip
    stw	r3, 0x368(r29)
    mr	r3, r30
    li	r4, 1
    bl      svm_ringbuf_skip
    stw	r3, 0x36c(r29)
    mr	r3, r30
    li	r4, 2
    bl      svm_ringbuf_skip
    stw	r3, 0x370(r29)
    mr	r3, r30
    li	r4, 2
    bl      svm_ringbuf_skip
    stw	r3, 0x374(r29)
    mr	r3, r30
    li	r4, 1
    bl      svm_ringbuf_skip
    stw	r3, 0x378(r29)
    mr	r3, r30
    li	r4, 1
    bl      svm_ringbuf_skip
    stw	r3, 0x37c(r29)
    mr	r3, r30
    li	r4, 2
    bl      svm_ringbuf_skip
    stw	r3, 0x380(r29)
    lwz	r0, 0x384(r29)
    cmpwi	r0, 0
    bne     _80051210
    lwz	r0, 0x370(r29)
    cmpwi	r0, 3
    bne     _80051208
    li	r0, 1
    stw	r0, 0x388(r29)
    b       _80051210
_80051208:
    li	r0, 2
    stw	r0, 0x388(r29)
_80051210:
    lwz	r0, 0x358(r29)
    cmpwi	r0, 2
    bne     _80051230
    addi	r4, r29, 0x39c
    li	r3, 0
    bl      getCupModeConst
    stw	r3, 0x394(r29)
    b       _80051238
_80051230:
    li	r0, 0x20
    stw	r0, 0x394(r29)
_80051238:
    lwz	r0, 0x370(r29)
    cmpwi	r0, 1
    bne     _8005126c
    lwz	r4, 0x358(r29)
    lis     r3, lbl_80130B68@ha
    lwz	r0, 0x374(r29)
    addi	r3, r3, lbl_80130B68@l
    slwi	r4, r4, 4
    add	r3, r3, r4
    slwi	r0, r0, 2
    lwzx	r0, r3, r0
    stw	r0, 0x398(r29)
    b       _80051274
_8005126c:
    lwz	r0, 0x394(r29)
    stw	r0, 0x398(r29)
_80051274:
    lwz	r0, 0x384(r29)
    cmpwi	r0, 0
    bne     _800512a4
    lwz	r4, 0x354(r29)
    lis     r3, adxt_sample_rate_table@ha
    lwz	r0, 0x364(r29)
    addi	r3, r3, adxt_sample_rate_table@l
    slwi	r4, r4, 4
    add	r3, r3, r4
    slwi	r0, r0, 2
    lwzx	r0, r3, r0
    stw	r0, 0x38c(r29)
_800512a4:
    lwz	r28, 0x39c(r29)
    mr	r23, r29
    lwz	r25, 0x34c(r29)
    li	r26, 0
    lwz	r30, 0x394(r29)
    mr	r22, r28
    lwz	r31, 0x388(r29)
    lwz	r21, 0x398(r29)
    b       _80051300
_800512c8:
    mr	r24, r23
    li	r27, 0
    b       _800512ec
_800512d4:
    lwz	r4, 4(r22)
    mr	r3, r25
    bl      svm_ringbuf_skip
    stw	r3, 0x3b8(r24)
    addi	r24, r24, 0x80
    addi	r27, r27, 1
_800512ec:
    cmpw	r27, r31
    blt     _800512d4
    addi	r23, r23, 4
    addi	r22, r22, 0x180
    addi	r26, r26, 1
_80051300:
    cmpw	r26, r21
    blt     _800512c8
    mulli	r3, r21, 0x180
    slwi	r0, r21, 2
    add	r23, r29, r0
    add	r22, r28, r3
    b       _8005133c
_8005131c:
    lwz	r4, 4(r22)
    mr	r3, r25
    bl      svm_ringbuf_skip
    stw	r3, 0x438(r23)
    addi	r22, r22, 0x180
    addi	r21, r21, 1
    stw	r3, 0x3b8(r23)
    addi	r23, r23, 4
_8005133c:
    cmpw	r21, r30
    blt     _8005131c
    slwi	r0, r30, 2
    add	r22, r29, r0
    b       _80051400
_80051350:
    cmpwi	r31, 0
    li	r21, 0
    ble     _800513f8
    cmpwi	r31, 8
    addi	r11, r31, -8
    ble     _800513cc
    addi	r0, r11, 7
    mr	r12, r22
    srwi	r0, r0, 3
    mr	r10, r21
    mr	r9, r21
    mr	r8, r21
    mr	r7, r21
    mr	r6, r21
    mr	r5, r21
    mr	r4, r21
    mr	r3, r21
    mtctr	r0
    cmpwi	r11, 0
    ble     _800513cc
_800513a0:
    stw	r10, 0x3b8(r12)
    addi	r21, r21, 8
    stw	r9, 0x438(r12)
    stw	r8, 0x4b8(r12)
    stw	r7, 0x538(r12)
    stw	r6, 0x5b8(r12)
    stw	r5, 0x638(r12)
    stw	r4, 0x6b8(r12)
    stw	r3, 0x738(r12)
    addi	r12, r12, 0x400
    bdnz    _800513a0
_800513cc:
    slwi	r3, r21, 7
    subf	r0, r21, r31
    add	r4, r22, r3
    li	r3, 0
    mtctr	r0
    cmpw	r21, r31
    bge     _800513f8
_800513e8:
    stw	r3, 0x3b8(r4)
    addi	r4, r4, 0x80
    addi	r21, r21, 1
    bdnz    _800513e8
_800513f8:
    addi	r22, r22, 4
    addi	r30, r30, 1
_80051400:
    cmpwi	r30, 0x20
    blt     _80051350
    lwz	r3, 0x34c(r29)
    addi	r4, r29, 0x384
    addi	r5, r29, 0x3b8
    addi	r6, r29, 0x4b8
    addi	r7, r29, 0x5b8
    bl      fn_80050BD4
    li	r3, 1
    li	r0, 0
    stb	r3, 0x345(r29)
    li	r3, 0
    stw	r0, 0x348(r29)
_80051434:
    lmw	r21, 0x14(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

#pragma pop
