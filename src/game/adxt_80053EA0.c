#pragma push
#pragma force_active on

extern void ADXTReadBits(void);
extern void fn_800501EC(void);
extern void fn_800504BC(void);
extern void fn_800504EC(void);
extern void fn_80050F64(void);
extern void fn_80050F6C(void);
extern void fn_80050F74(void);
extern void ADXF_StreamTeardown(void);
extern void fn_800510C4(void);
extern void ADXT_GetStreamStatus(void);
extern void fn_80051448(void);
extern void fn_80051594(void);
extern void fn_80051678(void);
extern void fn_8005174C(void);
extern void fn_800517C0(void);
extern void fn_8005190C(void);
extern void fn_80051958(void);
extern void adxtNullCallback(void);
extern void fn_80053F38(void);
extern void svm_ringbuf_read(void);
extern void sprintf(void);
extern void __msl_strncmp(void);
extern void strcpy(void);
extern void memcpy(void);
extern void memset(void);
extern void strlen(void);
extern unsigned char E0040302_handl_is_null_str[24];
extern unsigned char E0040303_invalidate_size_str[26];
extern unsigned char E0092912_handl_is_null_str[24];
extern unsigned char cvFsClose_1_handle_error_str[26];
extern unsigned char cvFsClose_2_vtbl_error_str[204];
extern unsigned char cvFsGetStat_1_handle_error_str[28];
extern unsigned char cvFsGetStat_2_vtbl_error_str[26];
extern unsigned char cvFsReqRd_1_handle_error_str[26];
extern unsigned char cvFsReqRd_2_vtbl_error_str[24];
extern unsigned char cvFsSeek_1_handle_error_str[25];
extern unsigned char cvFsSeek_2_vtbl_error_str[23];
extern unsigned char cvFsSetDefDev_1_illegal_device_name_str[37];
extern unsigned char cvFsSetDefDev_2_unknown_device_name_str[184];
extern unsigned char cvFsStopTr_1_handle_error_str[27];
extern unsigned char cvFsStopTr_2_vtbl_error_str[80];
extern unsigned char cvFsTell_1_handle_error_str[25];
extern unsigned char cvFsTell_2_vtbl_error_str[23];
extern unsigned char lbl_80091388[8];
extern unsigned char lbl_80091390[2232];
extern unsigned char gcci_client_ctx[4];
extern unsigned char lbl_801873D8[4];
extern unsigned char lbl_801873DC[16];
extern unsigned char lbl_801873EC[68];
extern unsigned char lbl_80187430[4];
extern unsigned char lbl_80187434[320];
extern unsigned char lbl_80187574[836];
extern unsigned char gcci_nullcheck_callback[4];
void fn_80055580(void);

asm void fn_80053EA0(void)
{
    nofralloc
    lwz	r3, 0x1c(r3)
    blr	
}

asm void fn_80053EA8(void)
{
    nofralloc
    lwz	r3, 0x20(r3)
    blr	
}

asm void fn_80053EB0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lbz	r0, 5(r3)
    extsb	r0, r0
    cmpwi	r0, 2
    bne     _80053edc
    bl      fn_80053F38
    b     _80053f24
_80053edc:
    cmpwi	r0, 1
    bne     _80053f24
    lwz	r3, 0xc(r31)
    li	r4, 1
    lwz	r5, 0(r3)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    cmpwi	r3, 0x24
    blt     _80053f24
    lwz	r3, 0(r31)
    bl      fn_80051448
    lwz	r3, 0(r31)
    bl      ADXT_GetStreamStatus
    li	r3, 1
    li	r0, 2
    stb	r3, 7(r31)
    stb	r0, 5(r31)
_80053f24:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80053F38(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    stw	r0, 0x64(r1)
    stmw	r20, 0x30(r1)
    mr	r24, r3
    li	r25, 0
    addi	r27, r24, 0x10
    lbz	r0, 7(r3)
    lwz	r28, 0(r3)
    cmpwi	r0, 1
    lwz	r3, 0xc(r3)
    bne     _80053fa0
    lwz	r5, 0(r3)
    li	r4, 1
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bne     _80053fa0
    lwz	r3, 8(r24)
    bl      ADXTReadBits
    cmpwi	r3, 1
    bne     _80053fa0
    li	r0, 3
    stb	r0, 5(r24)
    b     _800541d8
_80053fa0:
    lwz	r3, 0(r24)
    bl      fn_80050F64
    mr	r31, r3
    lwz	r3, 0(r24)
    bl      fn_80050F6C
    lwz	r6, 0x10(r24)
    srawi	r0, r3, 3
    addze	r26, r0
    li	r4, 0
    lwz	r5, 0(r6)
    mr	r3, r6
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    divw	r0, r3, r26
    cmpw	r0, r31
    blt     _800541d8
    mr	r3, r28
    bl      fn_800510C4
    cmpwi	r3, 0
    beq     _80054030
    bl      adxtNullCallback
    lis     r4, lbl_801873DC@ha
    addi	r4, r4, lbl_801873DC@l
    stw	r3, 8(r4)
    mr	r3, r28
    bl      ADXT_GetStreamStatus
    cmpwi	r3, 1
    bne     _80054020
    li	r0, 3
    stb	r0, 5(r24)
    b     _800541d8
_80054020:
    bl      adxtNullCallback
    lis     r4, lbl_801873DC@ha
    addi	r4, r4, lbl_801873DC@l
    stw	r3, 0xc(r4)
_80054030:
    lwz	r3, 0(r24)
    bl      fn_80050F74
    mr	r30, r3
    addi	r3, r1, 0x18
    li	r4, 0
    li	r5, 0x10
    bl      memset
    mullw	r21, r31, r26
    addi	r29, r1, 0x18
    mr	r22, r27
    mr	r23, r29
    li	r20, 0
    b     _80054090
_80054064:
    lwz	r3, 0(r22)
    mr	r5, r21
    mr	r6, r23
    li	r4, 0
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    addi	r23, r23, 8
    addi	r22, r22, 4
    addi	r20, r20, 1
_80054090:
    cmpw	r20, r30
    blt     _80054064
    cmpwi	r30, 2
    lwz	r20, 0x18(r1)
    bne     _800540a8
    lwz	r25, 0x20(r1)
_800540a8:
    lwz	r0, 0x1c(r1)
    srwi	r0, r0, 1
    cmpw	r0, r31
    beq     _800540bc
_800540b8:
    b     _800540b8
_800540bc:
    bl      adxtNullCallback
    lis     r5, lbl_801873DC@ha
    mr	r4, r20
    addi	r6, r5, lbl_801873DC@l
    mr	r5, r25
    stw	r3, 0(r6)
    mr	r3, r28
    mr	r6, r31
    bl      ADXF_StreamTeardown
    mr	r31, r3
    bl      adxtNullCallback
    mullw	r23, r31, r26
    lis     r4, lbl_801873DC@ha
    mr	r22, r27
    addi	r4, r4, lbl_801873DC@l
    stw	r3, 4(r4)
    addi	r21, r1, 8
    li	r25, 0
    b     _80054164
_80054108:
    mr	r3, r29
    mr	r4, r23
    mr	r5, r29
    mr	r6, r21
    bl      svm_ringbuf_read
    lwz	r3, 0(r22)
    mr	r5, r29
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r3, 0(r22)
    mr	r5, r21
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r21, r21, 8
    addi	r29, r29, 8
    addi	r22, r22, 4
    addi	r25, r25, 1
_80054164:
    cmpw	r25, r30
    blt     _80054108
    lwz	r0, 0x1c(r24)
    add	r0, r0, r31
    stw	r0, 0x1c(r24)
    lwz	r3, 8(r24)
    bl      fn_800501EC
    addi	r0, r3, 7
    srawi	r0, r0, 3
    addze	r0, r0
    stw	r0, 0x20(r24)
    lwz	r0, 0x24(r24)
    add	r0, r0, r31
    stw	r0, 0x24(r24)
    lwz	r0, 0x30(r24)
    add	r0, r0, r31
    stw	r0, 0x30(r24)
    lwz	r3, 0x2c(r24)
    cmpwi	r3, 0
    blt     _800541d8
    lwz	r0, 0x30(r24)
    cmpw	r0, r3
    blt     _800541d8
    lwz	r12, 0x3c(r24)
    cmplwi	r12, 0
    beq     _800541d8
    lwz	r3, 0x40(r24)
    mtctr	r12
    bctrl	
_800541d8:
    lmw	r20, 0x30(r1)
    lwz	r0, 0x64(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr	
}

asm void fn_800541EC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lwz	r3, 0(r3)
    bl      fn_80051678
    li	r0, 0
    stb	r0, 5(r31)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80054224(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r4, 0
    stw	r0, 0x14(r1)
    li	r0, -1
    stw	r31, 0xc(r1)
    mr	r31, r3
    stw	r4, 0x18(r3)
    lis	r3, -0x8000
    addi	r3, r3, -1
    stw	r4, 0x1c(r31)
    stw	r4, 0x20(r31)
    stw	r4, 0x24(r31)
    stw	r3, 0x28(r31)
    stw	r0, 0x2c(r31)
    stw	r4, 0x30(r31)
    stw	r4, 0x34(r31)
    stb	r4, 7(r31)
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _80054280
    stw	r4, 8(r31)
    bl      fn_800504BC
_80054280:
    lwz	r3, 0xc(r31)
    bl      fn_800504EC
    stw	r3, 8(r31)
    lwz	r3, 0(r31)
    lwz	r4, 8(r31)
    bl      fn_80051594
    li	r0, 1
    stb	r0, 5(r31)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original fn_800542B4
void fn_800542B4(void* obj, unsigned int val)
{
    *(unsigned int*)((char*)obj + 0xc) = val;
}

asm void fn_800542BC(void)
{
    nofralloc
    lbz	r3, 5(r3)
    extsb	r3, r3
    blr	
}

asm void fn_800542C8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    or.	r30, r3, r3
    beq     _8005433c
    lwz	r3, 8(r30)
    lwz	r31, 0x38(r30)
    cmplwi	r3, 0
    beq     _80054300
    li	r0, 0
    stw	r0, 8(r30)
    bl      fn_800504BC
_80054300:
    lwz	r3, 0(r30)
    cmplwi	r3, 0
    beq     _80054318
    li	r0, 0
    stw	r0, 0(r30)
    bl      fn_8005174C
_80054318:
    mr	r3, r30
    li	r4, 0
    li	r5, 0x4c
    bl      memset
    lis     r3, lbl_801873EC@ha
    slwi	r0, r31, 2
    addi	r3, r3, lbl_801873EC@l
    li	r4, 0
    stwx	r4, r3, r0
_8005433c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80054354(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r8, lbl_801873EC@ha
    stw	r0, 0x24(r1)
    li	r0, 2
    addi	r8, r8, lbl_801873EC@l
    stmw	r27, 0xc(r1)
    mr	r27, r3
    mr	r29, r4
    mr	r30, r5
    mr	r31, r6
    li	r28, 0
    mtctr	r0
_80054388:
    lwz	r0, 0(r8)
    cmplwi	r0, 0
    beq     _80054410
    lwzu	r0, 4(r8)
    addi	r28, r28, 1
    cmplwi	r0, 0
    beq     _80054410
    lwzu	r0, 4(r8)
    addi	r28, r28, 1
    cmplwi	r0, 0
    beq     _80054410
    lwzu	r0, 4(r8)
    addi	r28, r28, 1
    cmplwi	r0, 0
    beq     _80054410
    lwzu	r0, 4(r8)
    addi	r28, r28, 1
    cmplwi	r0, 0
    beq     _80054410
    lwzu	r0, 4(r8)
    addi	r28, r28, 1
    cmplwi	r0, 0
    beq     _80054410
    lwzu	r0, 4(r8)
    addi	r28, r28, 1
    cmplwi	r0, 0
    beq     _80054410
    lwzu	r0, 4(r8)
    addi	r28, r28, 1
    cmplwi	r0, 0
    beq     _80054410
    addi	r8, r8, 4
    addi	r28, r28, 1
    bdnz     _80054388
_80054410:
    cmpwi	r28, 0x10
    bne     _80054420
    li	r3, 0
    b     _8005459c
_80054420:
    mr	r3, r31
    mr	r5, r7
    li	r4, 0
    bl      memset
    lis     r3, lbl_801873EC@ha
    slwi	r0, r28, 2
    addi	r4, r3, lbl_801873EC@l
    mr	r3, r27
    stwx	r31, r4, r0
    lwzx	r31, r4, r0
    stw	r28, 0x38(r31)
    bl      fn_800504EC
    stw	r3, 8(r31)
    lwz	r0, 8(r31)
    cmplwi	r0, 0
    bne     _80054468
    li	r3, 0
    b     _8005459c
_80054468:
    addi	r3, r31, 0x4c
    li	r4, 0x2bcc
    bl      fn_800517C0
    stw	r3, 0(r31)
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bne     _8005448c
    li	r3, 0
    b     _8005459c
_8005448c:
    stb	r29, 6(r31)
    cmpwi	r29, 0
    li	r6, 0
    stw	r27, 0xc(r31)
    ble     _80054548
    cmpwi	r29, 8
    addi	r3, r29, -8
    ble     _80054518
    addi	r0, r3, 7
    mr	r4, r30
    srwi	r0, r0, 3
    mr	r5, r31
    mtctr	r0
    cmpwi	r3, 0
    ble     _80054518
_800544c8:
    lwz	r0, 0(r4)
    addi	r6, r6, 8
    stw	r0, 0x10(r5)
    lwz	r0, 4(r4)
    stw	r0, 0x14(r5)
    lwz	r0, 8(r4)
    stw	r0, 0x18(r5)
    lwz	r0, 0xc(r4)
    stw	r0, 0x1c(r5)
    lwz	r0, 0x10(r4)
    stw	r0, 0x20(r5)
    lwz	r0, 0x14(r4)
    stw	r0, 0x24(r5)
    lwz	r0, 0x18(r4)
    stw	r0, 0x28(r5)
    lwz	r0, 0x1c(r4)
    addi	r4, r4, 0x20
    stw	r0, 0x2c(r5)
    addi	r5, r5, 0x20
    bdnz     _800544c8
_80054518:
    slwi	r4, r6, 2
    subf	r0, r6, r29
    add	r3, r30, r4
    add	r4, r31, r4
    mtctr	r0
    cmpw	r6, r29
    bge     _80054548
_80054534:
    lwz	r0, 0(r3)
    addi	r3, r3, 4
    stw	r0, 0x10(r4)
    addi	r4, r4, 4
    bdnz     _80054534
_80054548:
    li	r6, 0
    lis	r3, -0x8000
    stb	r6, 5(r31)
    addi	r5, r3, -1
    li	r4, -1
    li	r0, 1
    stw	r6, 0x18(r31)
    mr	r3, r31
    stw	r6, 0x1c(r31)
    stw	r6, 0x20(r31)
    stw	r6, 0x24(r31)
    stw	r5, 0x28(r31)
    stw	r4, 0x2c(r31)
    stw	r6, 0x30(r31)
    stw	r6, 0x34(r31)
    stb	r6, 7(r31)
    stw	r6, 0x3c(r31)
    stw	r6, 0x40(r31)
    stw	r6, 0x44(r31)
    stw	r6, 0x48(r31)
    stb	r0, 4(r31)
_8005459c:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800545B0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_801873D8@ha
    stw	r0, 0x14(r1)
    lwz	r0, lbl_801873D8@l(r3)
    cmpwi	r0, 1
    bne     _800545e4
    lis     r3, lbl_801873EC@ha
    li	r4, 0
    addi	r3, r3, lbl_801873EC@l
    li	r5, 0x40
    bl      memset
    bl      fn_8005190C
_800545e4:
    lis     r3, lbl_801873D8@ha
    addi	r4, r3, lbl_801873D8@l
    lwz	r3, 0(r4)
    addi	r0, r3, -1
    stw	r0, 0(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80054608(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_801873D8@ha
    lis     r4, lbl_80091388@ha
    stw	r0, 0x14(r1)
    lwz	r0, lbl_801873D8@l(r3)
    addi	r3, r4, lbl_80091388@l
    lwz	r3, 0(r3)
    cmpwi	r0, 0
    bne     _80054648
    bl      fn_80051958
    lis     r3, lbl_801873EC@ha
    li	r4, 0
    addi	r3, r3, lbl_801873EC@l
    li	r5, 0x40
    bl      memset
_80054648:
    lis     r3, lbl_801873D8@ha
    addi	r4, r3, lbl_801873D8@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005466C(void)
{
    nofralloc
    cmplwi	r3, 0
    bne     _8005468c
    lis     r4, lbl_80187430@ha
    li	r0, 0
    lis     r3, lbl_80187434@ha
    stw	r0, lbl_80187430@l(r4)
    stw	r0, lbl_80187434@l(r3)
    blr	
_8005468c:
    lis     r6, lbl_80187430@ha
    lis     r5, lbl_80187434@ha
    stw	r3, lbl_80187430@l(r6)
    stw	r4, lbl_80187434@l(r5)
    blr	
}

asm void cvFsGetStat(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    li	r31, 3
    bne     _800546f4
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _800546ec
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsGetStat_1_handle_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsGetStat_1_handle_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_800546ec:
    li	r3, 3
    b     _8005474c
_800546f4:
    lwz	r4, 0(r3)
    lwz	r12, 0x2c(r4)
    cmplwi	r12, 0
    beq     _80054718
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    mr	r31, r3
    b     _80054748
_80054718:
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054748
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsGetStat_2_vtbl_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsGetStat_2_vtbl_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054748:
    mr	r3, r31
_8005474c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80054760(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80187574@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_80187574@l
    stw	r30, 8(r1)
    li	r30, 0
_80054780:
    lwz	r3, 0(r31)
    cmplwi	r3, 0
    beq     _800547a0
    lwz	r12, 0(r3)
    cmplwi	r12, 0
    beq     _800547a0
    mtctr	r12
    bctrl	
_800547a0:
    addi	r30, r30, 1
    addi	r31, r31, 0x10
    cmpwi	r30, 0x20
    blt     _80054780
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void cvFsStopTr(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80054810
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054860
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsStopTr_1_handle_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsStopTr_1_handle_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _80054860
_80054810:
    lwz	r4, 0(r3)
    lwz	r12, 0x28(r4)
    cmplwi	r12, 0
    beq     _80054830
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    b     _80054860
_80054830:
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054860
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsStopTr_2_vtbl_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsStopTr_2_vtbl_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054860:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void cvFsReqRd(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    bne     _800548c0
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _800548b8
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsReqRd_1_handle_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsReqRd_1_handle_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_800548b8:
    li	r3, 0
    b     _8005491c
_800548c0:
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    cmplwi	r12, 0
    beq     _800548e4
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    mr	r31, r3
    b     _80054918
_800548e4:
    lis     r3, lbl_80187430@ha
    li	r31, 0
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054918
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsReqRd_2_vtbl_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsReqRd_2_vtbl_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054918:
    mr	r3, r31
_8005491c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void cvFsSeek(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    bne     _80054980
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054978
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsSeek_1_handle_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsSeek_1_handle_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054978:
    li	r3, 0
    b     _800549dc
_80054980:
    lwz	r6, 0(r3)
    lwz	r12, 0x18(r6)
    cmplwi	r12, 0
    beq     _800549a4
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    mr	r31, r3
    b     _800549d8
_800549a4:
    lis     r3, lbl_80187430@ha
    li	r31, 0
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _800549d8
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsSeek_2_vtbl_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsSeek_2_vtbl_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_800549d8:
    mr	r3, r31
_800549dc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void cvFsTell(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    bne     _80054a40
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054a38
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsTell_1_handle_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsTell_1_handle_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054a38:
    li	r3, 0
    b     _80054a9c
_80054a40:
    lwz	r4, 0(r3)
    lwz	r12, 0x1c(r4)
    cmplwi	r12, 0
    beq     _80054a64
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    mr	r31, r3
    b     _80054a98
_80054a64:
    lis     r3, lbl_80187430@ha
    li	r31, 0
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054a98
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsTell_2_vtbl_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsTell_2_vtbl_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054a98:
    mr	r3, r31
_80054a9c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void cvFsClose(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    bne     _80054afc
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054b58
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsClose_1_handle_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsClose_1_handle_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _80054b58
_80054afc:
    lwz	r3, 0(r31)
    lwz	r12, 0x14(r3)
    cmplwi	r12, 0
    beq     _80054b28
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
    li	r0, 0
    stw	r0, 4(r31)
    stw	r0, 0(r31)
    b     _80054b58
_80054b28:
    lis     r3, lbl_80187430@ha
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _80054b58
    lis     r4, lbl_80187434@ha
    lis     r3, cvFsClose_2_vtbl_error_str@ha
    addi	r5, r4, lbl_80187434@l
    addi	r4, r3, cvFsClose_2_vtbl_error_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054b58:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80054B6C(void)
{
    nofralloc
    stwu	r1, -0x290(r1)
    mflr	r0
    lis     r6, lbl_80091390@ha
    stw	r0, 0x294(r1)
    stmw	r20, 0x260(r1)
    or.	r28, r3, r3
    lis     r3, lbl_80187430@ha
    mr	r25, r4
    mr	r24, r5
    addi	r29, r6, lbl_80091390@l
    addi	r31, r3, lbl_80187430@l
    bne     _80054bc4
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80054bbc
    addi	r4, r29, 0xa2c
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054bbc:
    li	r3, 0
    b     _800551bc
_80054bc4:
    beq     _80054d28
    li	r0, 0x63
    mr	r3, r28
    addi	r4, r1, 0x134
    li	r6, 0
    mtctr	r0
_80054bdc:
    lbz	r5, 0(r3)
    cmpwi	r5, 0x3a
    beq     _80054c3c
    extsb.	r0, r5
    beq     _80054c3c
    stb	r5, 0(r4)
    addi	r6, r6, 1
    lbz	r5, 1(r3)
    cmpwi	r5, 0x3a
    beq     _80054c3c
    extsb.	r0, r5
    beq     _80054c3c
    stb	r5, 1(r4)
    addi	r6, r6, 1
    lbz	r5, 2(r3)
    cmpwi	r5, 0x3a
    beq     _80054c3c
    extsb.	r0, r5
    beq     _80054c3c
    stb	r5, 2(r4)
    addi	r4, r4, 3
    addi	r6, r6, 1
    addi	r3, r3, 3
    bdnz     _80054bdc
_80054c3c:
    lbzx	r0, r28, r6
    extsb.	r0, r0
    bne     _80054c78
    addi	r3, r1, 0x134
    li	r0, 0
    stbx	r0, r3, r6
    bl      strlen
    mr	r5, r3
    addi	r3, r1, 8
    addi	r4, r1, 0x134
    addi	r5, r5, 1
    bl      memcpy
    li	r0, 0
    stb	r0, 0x134(r1)
    b     _80054d28
_80054c78:
    addi	r3, r1, 0x134
    li	r0, 0
    stbx	r0, r3, r6
    addi	r6, r6, 1
    cmpwi	r6, 2
    bne     _80054c98
    mr	r6, r0
    stb	r0, 0x134(r1)
_80054c98:
    subfic	r0, r6, 0x129
    mr	r5, r6
    addi	r4, r1, 8
    add	r3, r28, r6
    mtctr	r0
    cmpwi	r6, 0x129
    bge     _80054cd4
_80054cb4:
    lbz	r7, 0(r3)
    extsb.	r0, r7
    beq     _80054cd4
    subf	r0, r6, r5
    addi	r3, r3, 1
    stbx	r7, r4, r0
    addi	r5, r5, 1
    bdnz     _80054cb4
_80054cd4:
    subf	r0, r6, r5
    addi	r4, r1, 8
    li	r5, 0
    addi	r3, r1, 0x134
    stbx	r5, r4, r0
    bl      strlen
    addi	r0, r3, 1
    addi	r3, r1, 0x134
    mtctr	r0
    cmplwi	r0, 0
    ble     _80054d28
_80054d00:
    lbz	r4, 0(r3)
    extsb	r0, r4
    cmpwi	r0, 0x61
    blt     _80054d20
    cmpwi	r0, 0x7a
    bgt     _80054d20
    addi	r0, r4, -0x20
    stb	r0, 0(r3)
_80054d20:
    addi	r3, r3, 1
    bdnz     _80054d00
_80054d28:
    lbz	r0, 8(r1)
    extsb.	r0, r0
    bne     _80054d5c
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80054d54
    addi	r4, r29, 0xa2c
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054d54:
    li	r3, 0
    b     _800551bc
_80054d5c:
    li	r0, 4
    addi	r4, r31, 0x344
    li	r3, 0
    mtctr	r0
_80054d6c:
    lwz	r0, 4(r4)
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    lwz	r0, 0xc(r4)
    addi	r3, r3, 1
    addi	r4, r4, 8
    cmplwi	r0, 0
    beq     _80054e38
    addi	r4, r4, 8
    addi	r3, r3, 1
    bdnz     _80054d6c
_80054e38:
    cmpwi	r3, 0x28
    slwi	r0, r3, 3
    addi	r3, r31, 0x344
    add	r3, r3, r0
    bne     _80054e50
    li	r3, 0
_80054e50:
    cmplwi	r3, 0
    mr	r30, r3
    bne     _80054e84
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80054e7c
    addi	r4, r29, 0xa4c
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80054e7c:
    li	r3, 0
    b     _800551bc
_80054e84:
    lbz	r0, 0x134(r1)
    addi	r27, r1, 0x134
    extsb.	r0, r0
    bne     _80054edc
    addi	r3, r31, 0x138
    bl      strlen
    lbz	r0, 0x138(r31)
    mr	r5, r3
    extsb.	r0, r0
    bne     _80054eb8
    li	r0, 0
    stb	r0, 0x134(r1)
    b     _80054ec8
_80054eb8:
    mr	r3, r27
    addi	r4, r31, 0x138
    addi	r5, r5, 1
    bl      memcpy
_80054ec8:
    lbz	r0, 0x134(r1)
    extsb.	r0, r0
    bne     _80054edc
    li	r23, 0
    b     _8005509c
_80054edc:
    cmplwi	r27, 0
    mr	r23, r27
    bne     _80054eec
    addi	r23, r31, 0x138
_80054eec:
    mr	r3, r23
    bl      strlen
    addi	r26, r31, 0x144
    li	r22, 0
    mr	r21, r26
    mr	r20, r3
_80054f04:
    mr	r3, r23
    mr	r5, r20
    addi	r4, r21, 4
    bl      __msl_strncmp
    cmpwi	r3, 0
    bne     _80054f2c
    slwi	r0, r22, 4
    addi	r3, r31, 0x144
    lwzx	r3, r3, r0
    b     _80054f40
_80054f2c:
    addi	r22, r22, 1
    addi	r21, r21, 0x10
    cmplwi	r22, 0x20
    blt     _80054f04
    li	r3, 0
_80054f40:
    cmplwi	r3, 0
    bne     _80054f50
    li	r3, 0
    b     _80054f7c
_80054f50:
    lwz	r12, 0x60(r3)
    cmplwi	r12, 0
    beq     _80054f78
    li	r3, 0
    li	r4, 0x64
    li	r5, 0
    li	r6, 0
    mtctr	r12
    bctrl	
    b     _80054f7c
_80054f78:
    li	r3, 0
_80054f7c:
    cmpwi	r3, 1
    bne     _80054fa8
    addi	r3, r31, 0xc
    addi	r4, r1, 8
    bl      strcpy
    mr	r5, r23
    addi	r3, r1, 8
    addi	r4, r29, 0x34
    addi	r6, r31, 0xc
    crxor	6, 6, 6
    bl      sprintf
_80054fa8:
    mr	r3, r27
    bl      strlen
    mr	r20, r26
    li	r23, 0
    mr	r21, r3
_80054fbc:
    mr	r3, r27
    mr	r5, r21
    addi	r4, r20, 4
    bl      __msl_strncmp
    cmpwi	r3, 0
    bne     _80054fe4
    slwi	r0, r23, 4
    addi	r3, r31, 0x144
    lwzx	r23, r3, r0
    b     _80054ff8
_80054fe4:
    addi	r23, r23, 1
    addi	r20, r20, 0x10
    cmplwi	r23, 0x20
    blt     _80054fbc
    li	r23, 0
_80054ff8:
    cmplwi	r23, 0
    bne     _8005509c
    addi	r3, r31, 0x138
    bl      strlen
    lbz	r0, 0x138(r31)
    mr	r5, r3
    extsb.	r0, r0
    bne     _80055024
    li	r0, 0
    stb	r0, 0x134(r1)
    b     _80055034
_80055024:
    mr	r3, r27
    addi	r4, r31, 0x138
    addi	r5, r5, 1
    bl      memcpy
_80055034:
    mr	r3, r27
    bl      strlen
    li	r23, 0
    mr	r20, r3
_80055044:
    mr	r3, r27
    mr	r5, r20
    addi	r4, r26, 4
    bl      __msl_strncmp
    cmpwi	r3, 0
    bne     _8005506c
    slwi	r0, r23, 4
    addi	r3, r31, 0x144
    lwzx	r23, r3, r0
    b     _80055080
_8005506c:
    addi	r23, r23, 1
    addi	r26, r26, 0x10
    cmplwi	r23, 0x20
    blt     _80055044
    li	r23, 0
_80055080:
    cmplwi	r23, 0
    bne     _80055090
    li	r23, 0
    b     _8005509c
_80055090:
    mr	r4, r28
    addi	r3, r1, 8
    bl      strcpy
_8005509c:
    addic.	r0, r1, 0x134
    stw	r23, 0(r30)
    bne     _800550dc
    lwz	r12, 0(r31)
    li	r0, 0
    stw	r0, 4(r30)
    cmplwi	r12, 0
    stw	r0, 0(r30)
    beq     _800550d4
    addi	r4, r29, 0xa70
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_800550d4:
    li	r3, 0
    b     _800551bc
_800550dc:
    lwz	r3, 0(r30)
    cmplwi	r3, 0
    bne     _8005511c
    lwz	r12, 0(r31)
    li	r0, 0
    stw	r0, 4(r30)
    cmplwi	r12, 0
    stw	r0, 0(r30)
    beq     _80055114
    addi	r4, r29, 0xa90
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80055114:
    li	r3, 0
    b     _800551bc
_8005511c:
    lwz	r12, 0x10(r3)
    cmplwi	r12, 0
    beq     _80055144
    mr	r4, r25
    mr	r5, r24
    addi	r3, r1, 8
    mtctr	r12
    bctrl	
    stw	r3, 4(r30)
    b     _80055178
_80055144:
    lwz	r12, 0(r31)
    li	r0, 0
    stw	r0, 4(r30)
    cmplwi	r12, 0
    stw	r0, 0(r30)
    beq     _80055170
    addi	r4, r29, 0xab0
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80055170:
    li	r3, 0
    b     _800551bc
_80055178:
    lwz	r0, 4(r30)
    cmplwi	r0, 0
    bne     _800551b8
    lwz	r12, 0(r31)
    li	r0, 0
    stw	r0, 4(r30)
    cmplwi	r12, 0
    stw	r0, 0(r30)
    beq     _800551b0
    addi	r4, r29, 0xac8
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_800551b0:
    li	r3, 0
    b     _800551bc
_800551b8:
    mr	r3, r30
_800551bc:
    lmw	r20, 0x260(r1)
    lwz	r0, 0x294(r1)
    mtlr	r0
    addi	r1, r1, 0x290
    blr	
}

asm void cvFsSetDefDev(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r4, lbl_80187430@ha
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    or.	r27, r3, r3
    addi	r31, r4, lbl_80187430@l
    bne     _80055218
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _800552f0
    lis     r3, cvFsSetDefDev_1_illegal_device_name_str@ha
    li	r5, 0
    addi	r4, r3, cvFsSetDefDev_1_illegal_device_name_str@l
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
    b     _800552f0
_80055218:
    bl      strlen
    or.	r28, r3, r3
    bne     _80055230
    li	r0, 0
    stb	r0, 0x138(r31)
    b     _800552f0
_80055230:
    mr	r3, r27
    bl      strlen
    addi	r0, r3, 1
    mr	r3, r27
    mtctr	r0
    cmplwi	r0, 0
    ble     _80055274
_8005524c:
    lbz	r4, 0(r3)
    extsb	r0, r4
    cmpwi	r0, 0x61
    blt     _8005526c
    cmpwi	r0, 0x7a
    bgt     _8005526c
    addi	r0, r4, -0x20
    stb	r0, 0(r3)
_8005526c:
    addi	r3, r3, 1
    bdnz     _8005524c
_80055274:
    addi	r29, r31, 0x144
    li	r30, 0
_8005527c:
    mr	r3, r27
    mr	r5, r28
    addi	r4, r29, 4
    bl      __msl_strncmp
    cmpwi	r3, 0
    bne     _8005529c
    li	r0, 1
    b     _800552b0
_8005529c:
    addi	r30, r30, 1
    addi	r29, r29, 0x10
    cmpwi	r30, 0x20
    blt     _8005527c
    li	r0, 0
_800552b0:
    cmpwi	r0, 1
    bne     _800552cc
    mr	r4, r27
    addi	r3, r31, 0x138
    addi	r5, r28, 1
    bl      memcpy
    b     _800552f0
_800552cc:
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _800552f0
    lis     r3, cvFsSetDefDev_2_unknown_device_name_str@ha
    li	r5, 0
    addi	r4, r3, cvFsSetDefDev_2_unknown_device_name_str@l
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
_800552f0:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80055304(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r5, lbl_80091390@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    addi	r30, r5, lbl_80091390@l
    lis     r5, lbl_80187430@ha
    or.	r29, r3, r3
    lwz	r0, 0x30(r30)
    mr	r25, r4
    addi	r31, r5, lbl_80187430@l
    bne     _80055358
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _8005556c
    addi	r4, r30, 0xb54
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _8005556c
_80055358:
    cmplwi	r25, 0
    bne     _80055384
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _8005556c
    addi	r4, r30, 0xb78
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _8005556c
_80055384:
    bl      strlen
    addi	r0, r3, 1
    mr	r3, r29
    mtctr	r0
    cmplwi	r0, 0
    ble     _800553c4
_8005539c:
    lbz	r4, 0(r3)
    extsb	r0, r4
    cmpwi	r0, 0x61
    blt     _800553bc
    cmpwi	r0, 0x7a
    bgt     _800553bc
    addi	r0, r4, -0x20
    stb	r0, 0(r3)
_800553bc:
    addi	r3, r3, 1
    bdnz     _8005539c
_800553c4:
    mr	r12, r25
    mtctr	r12
    bctrl	
    mr	r28, r3
    mr	r3, r29
    bl      strlen
    addi	r26, r31, 0x144
    li	r27, 0
    mr	r25, r3
_800553e8:
    mr	r3, r29
    mr	r5, r25
    addi	r4, r26, 4
    bl      __msl_strncmp
    cmpwi	r3, 0
    bne     _80055410
    slwi	r0, r27, 4
    addi	r3, r31, 0x144
    lwzx	r0, r3, r0
    b     _80055424
_80055410:
    addi	r27, r27, 1
    addi	r26, r26, 0x10
    cmplwi	r27, 0x20
    blt     _800553e8
    li	r0, 0
_80055424:
    cmplwi	r0, 0
    beq     _80055430
    b     _80055520
_80055430:
    li	r0, 4
    addi	r4, r31, 0x144
    li	r3, 0
    mtctr	r0
_80055440:
    lbz	r0, 4(r4)
    extsb.	r0, r0
    beq     _800554e4
    lbz	r0, 0x14(r4)
    addi	r3, r3, 1
    addi	r4, r4, 0x10
    extsb.	r0, r0
    beq     _800554e4
    lbz	r0, 0x14(r4)
    addi	r3, r3, 1
    addi	r4, r4, 0x10
    extsb.	r0, r0
    beq     _800554e4
    lbz	r0, 0x14(r4)
    addi	r3, r3, 1
    addi	r4, r4, 0x10
    extsb.	r0, r0
    beq     _800554e4
    lbz	r0, 0x14(r4)
    addi	r3, r3, 1
    addi	r4, r4, 0x10
    extsb.	r0, r0
    beq     _800554e4
    lbz	r0, 0x14(r4)
    addi	r3, r3, 1
    addi	r4, r4, 0x10
    extsb.	r0, r0
    beq     _800554e4
    lbz	r0, 0x14(r4)
    addi	r3, r3, 1
    addi	r4, r4, 0x10
    extsb.	r0, r0
    beq     _800554e4
    lbz	r0, 0x14(r4)
    addi	r3, r3, 1
    addi	r4, r4, 0x10
    extsb.	r0, r0
    beq     _800554e4
    addi	r4, r4, 0x10
    addi	r3, r3, 1
    bdnz     _80055440
_800554e4:
    cmpwi	r3, 0x20
    bne     _800554f4
    li	r28, 0
    b     _80055520
_800554f4:
    slwi	r0, r3, 4
    addi	r25, r31, 0x144
    add	r25, r25, r0
    mr	r3, r29
    stw	r28, 0(r25)
    bl      strlen
    mr	r5, r3
    mr	r4, r29
    addi	r3, r25, 4
    addi	r5, r5, 1
    bl      memcpy
_80055520:
    cmplwi	r28, 0
    bne     _8005554c
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _8005556c
    addi	r4, r30, 0xb9c
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _8005556c
_8005554c:
    lwz	r12, 4(r28)
    cmplwi	r12, 0
    beq     _8005556c
    lis     r3, fn_80055580@ha
    li	r4, 0
    addi	r3, r3, fn_80055580@l
    mtctr	r12
    bctrl	
_8005556c:
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80055580(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80187430@ha
    stw	r0, 0x14(r1)
    lwz	r12, lbl_80187430@l(r3)
    cmplwi	r12, 0
    beq     _800555b0
    lis     r3, lbl_80187434@ha
    addi	r3, r3, lbl_80187434@l
    lwz	r3, 0(r3)
    mtctr	r12
    bctrl	
_800555b0:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800555C0(void)
{
    nofralloc
    blr	
}

asm void fn_800555C4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80055610
    lis     r3, gcci_client_ctx@ha
    lwz	r12, gcci_client_ctx@l(r3)
    cmplwi	r12, 0
    beq     _80055608
    lis     r4, gcci_nullcheck_callback@ha
    lis     r3, E0092912_handl_is_null_str@ha
    addi	r5, r4, gcci_nullcheck_callback@l
    addi	r4, r3, E0092912_handl_is_null_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80055608:
    li	r3, 0
    b     _80055614
_80055610:
    lwz	r3, 0x20(r3)
_80055614:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80055624(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8005566c
    lis     r3, gcci_client_ctx@ha
    lwz	r12, gcci_client_ctx@l(r3)
    cmplwi	r12, 0
    beq     _800556f8
    lis     r4, gcci_nullcheck_callback@ha
    lis     r3, E0040302_handl_is_null_str@ha
    addi	r5, r4, gcci_nullcheck_callback@l
    addi	r4, r3, E0040302_handl_is_null_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _800556f8
_8005566c:
    lwz	r6, 0x10(r3)
    slwi	r0, r6, 0x1b
    srwi	r5, r6, 0x1f
    subf	r0, r5, r0
    rotlwi	r0, r0, 5
    add.	r0, r0, r5
    beq     _800556bc
    lis     r3, gcci_client_ctx@ha
    lwz	r12, gcci_client_ctx@l(r3)
    cmplwi	r12, 0
    beq     _800556f8
    lis     r4, gcci_nullcheck_callback@ha
    lis     r3, E0040303_invalidate_size_str@ha
    addi	r5, r4, gcci_nullcheck_callback@l
    addi	r4, r3, E0040303_invalidate_size_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _800556f8
_800556bc:
    lwz	r0, 0x1c(r3)
    stw	r4, 0x10(r3)
    mullw	r7, r0, r6
    lwz	r6, 0x10(r3)
    lwz	r0, 0x14(r3)
    add	r5, r6, r0
    addi	r0, r5, -1
    divw	r0, r0, r6
    stw	r0, 0x18(r3)
    lwz	r0, 0x10(r3)
    divw	r0, r7, r0
    stw	r0, 0x1c(r3)
    lwz	r0, 0x24(r3)
    mullw	r0, r0, r4
    stw	r0, 0x20(r3)
_800556f8:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
