#pragma push
#pragma force_active on

extern void ARQPostRequest(void);
extern void AXAcquireVoice(void);
extern void AXFreeVoice(void);
extern void DCFlushRange(void);
extern void fn_800230A4(void);
extern void AXSetVoiceType_cached(void);
extern void fn_80023284(void);
extern void fn_80023438(void);
extern void fn_80025EF4(void);
extern void axmix_device_ctrl_clear(void);
extern void fn_80026D90(void);
extern void fn_80026EE0(void);
extern void svmExitCritical(void);
extern void svmEnterCritical(void);
extern void fn_80058498(void);
extern void svm_ringbuf_read(void);
extern void fn_8005A5BC(void);
extern void svm_exit_critical_wrapper(void);
extern void svm_enter_critical_wrapper(void);
extern void fn_8005A9B8(void);
extern void fn_8005AE98(void);
extern void fn_8005B0C4(void);
extern void fn_8005B264(void);
extern void fn_8005BE68(void);
extern void fn_8005BE80(void);
extern void fn_8005BE98(void);
extern void fn_8005BEAC(void);
extern void sprintf(void);
extern void strncpy(void);
extern void strcpy(void);
extern void strtol(void);
extern void memset(void);
extern void strlen(void);
extern unsigned char E01100308_length_of_s_is_not_17_bytes_mfci_get_adr_size_str[61];
extern unsigned char E01100309_illegal_file_name_format_s_mfci_get_adr_size_str[59];
extern unsigned char lbl_80092790[44];
extern unsigned char lbl_800927D0[440];
extern unsigned char lbl_801324F0[104];
extern unsigned char adxt_volume_scale_table[124];
extern unsigned char lbl_80190178[4];
extern unsigned char lbl_80190B70[4];
extern unsigned char lbl_80190C7C[4];
extern unsigned char lbl_80190C88[4];
extern unsigned char lbl_80190C8C[4288];
extern unsigned char lbl_80191D4C[3716];
void fn_8005ACF0(void);
void fn_8005ADBC(void);

asm void fn_8005A24C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    cmplwi	r3, 0
    lis	r6, -0x7ff7
    stw	r0, 0x24(r1)
    lis     r4, lbl_80190178@ha
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r4, lbl_80190178@l
    stw	r29, 0x14(r1)
    addi	r29, r6, 0x24f8
    bne     _8005a2a4
    lwz	r12, 0(r30)
    cmplwi	r12, 0
    beq     _8005a29c
    addi	r4, r29, 0x21c
    lwz	r3, 4(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a29c:
    li	r3, 0
    b     _8005a460
_8005a2a4:
    cmpwi	r5, 0
    beq     _8005a2d4
    lwz	r12, 0(r30)
    cmplwi	r12, 0
    beq     _8005a2cc
    addi	r4, r29, 0x240
    lwz	r3, 4(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a2cc:
    li	r3, 0
    b     _8005a460
_8005a2d4:
    li	r31, 0
    li	r0, 0x28
    mr	r4, r31
    addi	r5, r30, 0x134
    mtctr	r0
_8005a2e8:
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bne     _8005a304
    mulli	r0, r4, 0x38
    addi	r31, r30, 0x134
    add	r31, r31, r0
    b     _8005a310
_8005a304:
    addi	r5, r5, 0x38
    addi	r4, r4, 1
    bdnz     _8005a2e8
_8005a310:
    cmplwi	r31, 0
    bne     _8005a340
    lwz	r12, 0(r30)
    cmplwi	r12, 0
    beq     _8005a338
    addi	r4, r29, 0x264
    lwz	r3, 4(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a338:
    li	r3, 0
    b     _8005a460
_8005a340:
    mr	r4, r3
    addi	r3, r31, 0x1c
    bl      strcpy
    li	r0, 0x800
    addi	r3, r31, 0x1c
    stw	r0, 4(r31)
    bl      strlen
    cmplwi	r3, 0x11
    beq     _8005a398
    addi	r3, r30, 8
    addi	r4, r29, 0xc0
    addi	r5, r31, 0x1c
    crxor	6, 6, 6
    bl      sprintf
    lwz	r12, 0(r30)
    cmplwi	r12, 0
    beq     _8005a398
    addi	r4, r30, 8
    lwz	r3, 4(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a398:
    lbz	r0, 0x24(r31)
    cmpwi	r0, 0x2e
    beq     _8005a3d8
    addi	r3, r30, 8
    addi	r4, r29, 0x100
    addi	r5, r31, 0x1c
    crxor	6, 6, 6
    bl      sprintf
    lwz	r12, 0(r30)
    cmplwi	r12, 0
    beq     _8005a3d8
    addi	r4, r30, 8
    lwz	r3, 4(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a3d8:
    addi	r3, r31, 0x1c
    addi	r4, r1, 8
    stw	r3, 8(r1)
    li	r5, 0x10
    bl      strtol
    lwz	r3, 8(r1)
    lbz	r0, 0(r3)
    extsb.	r0, r0
    beq     _8005a404
    addi	r0, r3, 1
    stw	r0, 8(r1)
_8005a404:
    addic.	r0, r1, 0xc
    beq     _8005a420
    lwz	r3, 8(r1)
    addi	r4, r1, 8
    li	r5, 0x10
    bl      strtol
    stw	r3, 0xc(r1)
_8005a420:
    lwz	r5, 0xc(r1)
    li	r4, 0
    li	r0, 1
    mr	r3, r31
    stw	r5, 8(r31)
    lwz	r6, 4(r31)
    lwz	r5, 8(r31)
    add	r5, r6, r5
    addi	r5, r5, -1
    divw	r5, r5, r6
    stw	r5, 0xc(r31)
    stw	r4, 0x10(r31)
    stw	r4, 0x18(r31)
    stw	r4, 0x14(r31)
    stb	r4, 1(r31)
    stb	r0, 0(r31)
_8005a460:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005A47C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r4, lbl_80190178@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, lbl_80190178@l
    stw	r30, 0x18(r1)
    mr	r30, r3
    bl      strlen
    cmplwi	r3, 0x11
    beq     _8005a4e0
    lis     r3, E01100308_length_of_s_is_not_17_bytes_mfci_get_adr_size_str@ha
    mr	r5, r30
    addi	r4, r3, E01100308_length_of_s_is_not_17_bytes_mfci_get_adr_size_str@l
    addi	r3, r31, 8
    crxor	6, 6, 6
    bl      sprintf
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _8005a4e0
    addi	r4, r31, 8
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a4e0:
    lbz	r0, 8(r30)
    cmpwi	r0, 0x2e
    beq     _8005a524
    lis     r3, E01100309_illegal_file_name_format_s_mfci_get_adr_size_str@ha
    mr	r5, r30
    addi	r4, r3, E01100309_illegal_file_name_format_s_mfci_get_adr_size_str@l
    addi	r3, r31, 8
    crxor	6, 6, 6
    bl      sprintf
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _8005a524
    addi	r4, r31, 8
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a524:
    stw	r30, 8(r1)
    mr	r3, r30
    addi	r4, r1, 8
    li	r5, 0x10
    bl      strtol
    lwz	r3, 8(r1)
    lbz	r0, 0(r3)
    extsb.	r0, r0
    beq     _8005a550
    addi	r0, r3, 1
    stw	r0, 8(r1)
_8005a550:
    addic.	r0, r1, 0xc
    beq     _8005a56c
    lwz	r3, 8(r1)
    addi	r4, r1, 8
    li	r5, 0x10
    bl      strtol
    stw	r3, 0xc(r1)
_8005a56c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r3, 0xc(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005A588(void)
{
    nofralloc
    lis	r6, -0x7fe7
    lis	r5, -0x7fe7
    stw	r3, 0x178(r6)
    stw	r4, 0x17c(r5)
    blr	
}

asm void fn_8005A59C(void)
{
    nofralloc
    li	r0, 0
    cmpwi	r0, 0x28
    blr	
}

asm void fn_8005A5A8(void)
{
    nofralloc
    lis	r4, -0x7ff7
    lis     r3, lbl_801324F0@ha
    lwz	r0, 0x2528(r4)
    addi	r3, r3, lbl_801324F0@l
    blr	
}

asm void fn_8005A5BC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, lbl_80190B70@ha
    li	r5, 0xff
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_80190B70@l
    mr	r4, r3
    addi	r3, r31, 8
    bl      strncpy
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _8005a600
    addi	r4, r31, 8
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
_8005a600:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005A614(void)
{
    nofralloc
    lis	r6, -0x7fe7
    lis	r5, -0x7fe7
    stw	r3, 0xb70(r6)
    stw	r4, 0xb74(r5)
    blr	
}

asm void svm_exit_critical_wrapper(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      svmExitCritical
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void svm_enter_critical_wrapper(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      svmEnterCritical
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005A668(void)
{
    nofralloc
    cmplwi	r3, 0
    beqlr	
    sth	r4, 0xa0(r3)
    blr	
}

asm void fn_8005A678(void)
{
    nofralloc
    li	r3, 0
    blr	
}

asm void fn_8005A680(void)
{
    nofralloc
    li	r3, 0
    blr	
}

asm void fn_8005A688(void)
{
    nofralloc
    cmplwi	r3, 0
    beqlr	
    stw	r4, 0x80(r3)
    blr	
}

asm void fn_8005A698(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    or.	r29, r3, r3
    beq     _8005a730
    lbz	r0, 2(r29)
    extsb	r0, r0
    cmpw	r4, r0
    bge     _8005a730
    cmpwi	r5, 0xf
    li	r0, 0xf
    bge     _8005a6d8
    mr	r0, r5
_8005a6d8:
    cmpwi	r0, -0xf
    li	r31, -0xf
    ble     _8005a6e8
    mr	r31, r0
_8005a6e8:
    slwi	r30, r4, 2
    add	r3, r29, r30
    lwz	r0, 0x88(r3)
    cmpw	r31, r0
    beq     _8005a730
    stw	r31, 0x88(r3)
    bl      svm_enter_critical_wrapper
    add	r3, r29, r30
    lwz	r3, 8(r3)
    cmplwi	r3, 0
    beq     _8005a72c
    lis     r4, adxt_volume_scale_table@ha
    slwi	r0, r31, 2
    addi	r4, r4, adxt_volume_scale_table@l
    add	r4, r4, r0
    lwz	r4, 0x3c(r4)
    bl      fn_80026EE0
_8005a72c:
    bl      svm_exit_critical_wrapper
_8005a730:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005A74C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    or.	r28, r3, r3
    beq     _8005a7d8
    srawi	r0, r4, 0x1f
    li	r30, -0x3e7
    and	r0, r4, r0
    cmpwi	r0, -0x3e7
    ble     _8005a788
    mr	r30, r0
_8005a788:
    lwz	r0, 0x84(r28)
    cmpw	r30, r0
    beq     _8005a7d8
    stw	r30, 0x84(r28)
    mr	r31, r28
    li	r29, 0
    b     _8005a7c8
_8005a7a4:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8005a7bc
    mr	r4, r30
    bl      fn_80026D90
_8005a7bc:
    bl      svm_exit_critical_wrapper
    addi	r31, r31, 4
    addi	r29, r29, 1
_8005a7c8:
    lbz	r0, 2(r28)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005a7a4
_8005a7d8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005A7F8(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stmw	r25, 0x24(r1)
    or.	r25, r3, r3
    mr	r26, r4
    beq     _8005a938
    mulli	r5, r26, 0x464
    lis	r4, 0x7482
    lis	r3, 0x1062
    stw	r26, 0x24(r25)
    addi	r4, r4, 0x296b
    addi	r0, r5, 0x464
    mulhw	r5, r4, r0
    addi	r4, r3, 0x4dd3
    slwi	r0, r26, 8
    mr	r31, r25
    li	r27, 0
    srawi	r5, r5, 9
    mulhw	r3, r4, r26
    srwi	r6, r5, 0x1f
    add	r30, r5, r6
    srawi	r3, r3, 0xb
    mulhw	r0, r4, r0
    srwi	r4, r3, 0x1f
    add	r29, r3, r4
    srawi	r0, r0, 3
    srwi	r3, r0, 0x1f
    add	r0, r0, r3
    clrlwi	r28, r0, 0x10
    b     _8005a928
_8005a874:
    bl      svm_enter_critical_wrapper
    lwz	r0, 8(r31)
    cmplwi	r0, 0
    beq     _8005a91c
    lha	r0, 0xa0(r25)
    cmpwi	r0, 1
    bne     _8005a8e4
    cmpwi	r26, 0x7d00
    bne     _8005a8bc
    lha	r0, 0xa2(r25)
    cmpwi	r0, 0
    bne     _8005a8bc
    cmplwi	r25, 0
    beq     _8005a8bc
    li	r3, 0
    li	r0, 1
    stw	r3, 0xa4(r25)
    sth	r0, 0xa2(r25)
_8005a8bc:
    lis	r3, 0x1062
    slwi	r0, r30, 8
    addi	r3, r3, 0x4dd3
    mulhwu	r0, r3, r0
    mulhwu	r4, r3, r30
    rlwinm	r0, r0, 0x1d, 0x10, 0x1f
    sth	r0, 0xa(r1)
    rlwinm	r3, r4, 0x15, 0x10, 0x1f
    sth	r3, 8(r1)
    b     _8005a8ec
_8005a8e4:
    sth	r29, 8(r1)
    sth	r28, 0xa(r1)
_8005a8ec:
    li	r0, 0
    sth	r0, 0xc(r1)
    sth	r0, 0xe(r1)
    sth	r0, 0x10(r1)
    sth	r0, 0x12(r1)
    sth	r0, 0x14(r1)
    lwz	r3, 8(r31)
    lwz	r4, 0xa4(r25)
    bl      fn_800230A4
    lwz	r3, 8(r31)
    addi	r4, r1, 8
    bl      fn_80023438
_8005a91c:
    bl      svm_exit_critical_wrapper
    addi	r31, r31, 4
    addi	r27, r27, 1
_8005a928:
    lbz	r0, 2(r25)
    extsb	r0, r0
    cmpw	r27, r0
    blt     _8005a874
_8005a938:
    lmw	r25, 0x24(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8005A94C(void)
{
    nofralloc
    cmplwi	r3, 0
    beqlr	
    stb	r4, 3(r3)
    blr	
}

asm void fn_8005A95C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80191D4C@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_80191D4C@l
    stw	r30, 8(r1)
    li	r30, 0
_8005a97c:
    lbz	r0, 0(r31)
    cmpwi	r0, 1
    bne     _8005a990
    mr	r3, r31
    bl      fn_8005A9B8
_8005a990:
    addi	r30, r30, 1
    addi	r31, r31, 0xe8
    cmplwi	r30, 0x10
    blt     _8005a97c
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005A9B8(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stmw	r26, 0x38(r1)
    or.	r31, r3, r3
    beq     _8005acdc
    bne     _8005a9dc
    li	r0, -1
    b     _8005a9e4
_8005a9dc:
    lbz	r0, 1(r31)
    rlwinm	r0, r0, 0x1f, 0x1f, 0x1f
_8005a9e4:
    cmpwi	r0, 1
    bne     _8005a9f4
    mr	r3, r31
    bl      fn_8005AE98
_8005a9f4:
    cmplwi	r31, 0
    bne     _8005aa04
    li	r0, -1
    b     _8005aa0c
_8005aa04:
    lbz	r0, 1(r31)
    clrlwi	r0, r0, 0x1f
_8005aa0c:
    cmpwi	r0, 1
    bne     _8005aba0
    mr	r28, r31
    mr	r27, r31
    mr	r26, r31
    li	r29, 0
    b     _8005ab8c
_8005aa28:
    lwz	r0, 8(r28)
    cmplwi	r0, 0
    beq     _8005ab7c
    lwz	r0, 0x60(r28)
    cmpwi	r0, 0
    bne     _8005ab7c
    lwz	r3, 0x38(r28)
    addi	r6, r1, 0x28
    li	r4, 0
    li	r5, 0x2000
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r3, 0x30(r28)
    addi	r6, r1, 0x18
    lwz	r5, 0x2c(r1)
    li	r4, 1
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r3, 0x2c(r1)
    lwz	r0, 0x1c(r1)
    cmpw	r0, r3
    bge     _8005aa94
    mr	r3, r0
_8005aa94:
    srawi	r0, r3, 5
    addi	r3, r1, 0x28
    addze	r0, r0
    addi	r6, r1, 0x30
    slwi	r30, r0, 5
    mr	r5, r3
    mr	r4, r30
    bl      svm_ringbuf_read
    lwz	r3, 0x38(r28)
    addi	r5, r1, 0x30
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r3, r1, 0x18
    mr	r4, r30
    mr	r5, r3
    addi	r6, r1, 0x20
    bl      svm_ringbuf_read
    lwz	r3, 0x30(r28)
    addi	r5, r1, 0x20
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    cmpwi	r30, 0
    beq     _8005acdc
    lwz	r4, 0x1c(r1)
    lwz	r0, 0x2c(r1)
    cmpw	r4, r0
    beq     _8005ab1c
_8005ab18:
    b     _8005ab18
_8005ab1c:
    lwz	r3, 0x18(r1)
    srwi	r0, r30, 1
    stw	r3, 0x40(r27)
    stw	r4, 0x44(r27)
    lwz	r4, 0x28(r1)
    lwz	r3, 0x2c(r1)
    stw	r4, 0x50(r27)
    stw	r3, 0x54(r27)
    stw	r0, 0x68(r31)
    lwz	r3, 0x40(r27)
    lwz	r4, 0x44(r27)
    bl      DCFlushRange
    li	r0, 1
    lis     r3, fn_8005ADBC@ha
    stw	r0, 0x60(r28)
    addi	r10, r3, fn_8005ADBC@l
    mr	r9, r30
    addi	r3, r26, 0xa8
    lwz	r4, 0x28(r28)
    li	r5, 0
    lwz	r7, 0x18(r1)
    li	r6, 1
    lwz	r8, 0x28(r1)
    bl      ARQPostRequest
_8005ab7c:
    addi	r28, r28, 4
    addi	r27, r27, 8
    addi	r26, r26, 0x20
    addi	r29, r29, 1
_8005ab8c:
    lbz	r0, 3(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005aa28
    b     _8005acdc
_8005aba0:
    cmplwi	r31, 0
    bne     _8005abb0
    li	r0, -1
    b     _8005abb8
_8005abb0:
    lbz	r0, 1(r31)
    rlwinm	r0, r0, 0x1f, 0x1f, 0x1f
_8005abb8:
    cmpwi	r0, 1
    bne     _8005acdc
    lwz	r3, 0x7c(r31)
    lwz	r0, 0x20(r31)
    cmpw	r3, r0
    bge     _8005acdc
    mr	r26, r31
    mr	r27, r31
    mr	r28, r31
    li	r29, 0
    b     _8005accc
_8005abe4:
    lwz	r0, 0x70(r26)
    cmpwi	r0, 0
    bne     _8005acbc
    lwz	r3, 0x38(r26)
    addi	r6, r1, 8
    li	r4, 0
    li	r5, 0x2000
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0xc(r1)
    addi	r3, r1, 8
    mr	r5, r3
    addi	r6, r1, 0x10
    srawi	r0, r0, 5
    addze	r0, r0
    slwi	r30, r0, 5
    mr	r4, r30
    bl      svm_ringbuf_read
    lwz	r3, 0x38(r26)
    addi	r5, r1, 0x10
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    cmpwi	r30, 0
    beq     _8005acdc
    lwz	r6, 8(r1)
    lis     r3, lbl_80190C7C@ha
    lwz	r5, 0xc(r1)
    srwi	r0, r30, 1
    addi	r3, r3, lbl_80190C7C@l
    li	r4, 0x1000
    stw	r6, 0x50(r27)
    stw	r5, 0x54(r27)
    stw	r0, 0x78(r31)
    lwz	r3, 0(r3)
    bl      DCFlushRange
    li	r0, 1
    lis     r3, lbl_80190C7C@ha
    stw	r0, 0x70(r26)
    addi	r5, r3, lbl_80190C7C@l
    lis     r3, fn_8005ACF0@ha
    mr	r9, r30
    lwz	r7, 0(r5)
    addi	r10, r3, fn_8005ACF0@l
    lwz	r4, 0x28(r26)
    addi	r3, r28, 0xa8
    lwz	r8, 8(r1)
    li	r5, 0
    li	r6, 1
    bl      ARQPostRequest
_8005acbc:
    addi	r26, r26, 4
    addi	r27, r27, 8
    addi	r28, r28, 0x20
    addi	r29, r29, 1
_8005accc:
    lbz	r0, 3(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005abe4
_8005acdc:
    lmw	r26, 0x38(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_8005ACF0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    lwz	r0, 4(r3)
    lis     r3, lbl_80191D4C@ha
    addi	r3, r3, lbl_80191D4C@l
    clrlwi	r4, r0, 1
    clrlwi	r0, r0, 0x1f
    srwi	r5, r4, 0x1f
    add	r4, r5, r4
    srawi	r4, r4, 1
    xor	r0, r0, r5
    mulli	r4, r4, 0xe8
    subf	r29, r5, r0
    add	r30, r3, r4
    slwi	r3, r29, 2
    add	r31, r30, r3
    lwzu	r0, 0x70(r31)
    cmpwi	r0, 1
    bne     _8005ada0
    add	r3, r30, r3
    slwi	r4, r29, 3
    lwz	r3, 0x38(r3)
    addi	r5, r4, 0x50
    add	r5, r30, r5
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    stw	r0, 0(r31)
    lbz	r0, 3(r30)
    extsb	r3, r0
    addi	r0, r3, -1
    cmpw	r29, r0
    bne     _8005ada0
    lwz	r3, 0x7c(r30)
    lwz	r0, 0x78(r30)
    add	r0, r3, r0
    stw	r0, 0x7c(r30)
_8005ada0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005ADBC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    lwz	r0, 4(r3)
    lis     r3, lbl_80191D4C@ha
    addi	r3, r3, lbl_80191D4C@l
    clrlwi	r4, r0, 1
    clrlwi	r0, r0, 0x1f
    srwi	r5, r4, 0x1f
    add	r4, r5, r4
    srawi	r4, r4, 1
    xor	r0, r0, r5
    mulli	r4, r4, 0xe8
    subf	r30, r5, r0
    add	r31, r3, r4
    slwi	r29, r30, 2
    add	r27, r31, r29
    lwzu	r0, 0x60(r27)
    cmpwi	r0, 1
    bne     _8005ae84
    add	r3, r31, r29
    slwi	r0, r30, 3
    lwz	r3, 0x30(r3)
    add	r28, r31, r0
    addi	r5, r28, 0x40
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    add	r3, r31, r29
    addi	r5, r28, 0x50
    lwz	r3, 0x38(r3)
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    stw	r0, 0(r27)
    lbz	r0, 3(r31)
    extsb	r3, r0
    addi	r0, r3, -1
    cmpw	r30, r0
    bne     _8005ae84
    lwz	r3, 0x6c(r31)
    lwz	r0, 0x68(r31)
    add	r0, r3, r0
    stw	r0, 0x6c(r31)
_8005ae84:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005AE98(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r27, 0x1c(r1)
    mr	r30, r3
    lbz	r0, 3(r3)
    lwz	r9, 4(r3)
    extsb	r0, r0
    slwi	r0, r0, 2
    add	r5, r30, r0
    lwz	r7, 4(r5)
    cmplwi	r7, 0
    beq     _8005affc
    lis     r4, lbl_80190C88@ha
    lis     r3, lbl_80190C8C@ha
    addi	r6, r4, lbl_80190C88@l
    lwz	r8, 0x14(r5)
    lwz	r5, 0(r6)
    addi	r3, r3, lbl_80190C8C@l
    lwz	r7, 0x1b2(r7)
    addi	r4, r5, 1
    slwi	r0, r5, 2
    subf	r5, r8, r7
    stw	r4, 0(r6)
    cmpwi	r4, 0x20
    stwx	r5, r3, r0
    bne     _8005af0c
    li	r0, 0
    stw	r0, 0(r6)
_8005af0c:
    cmpwi	r5, 0
    blt     _8005af20
    lwz	r0, 0x20(r30)
    cmpw	r5, r0
    ble     _8005af24
_8005af20:
    b     _8005af20
_8005af24:
    cmpwi	r9, -1
    bne     _8005af48
    cmpwi	r5, 0
    bne     _8005af3c
    li	r31, 0
    b     _8005af48
_8005af3c:
    li	r0, 0
    li	r9, 0
    stw	r0, 4(r30)
_8005af48:
    cmpwi	r9, -1
    beq     _8005af68
    cmpw	r5, r9
    ble     _8005af60
    subf	r31, r9, r5
    b     _8005af68
_8005af60:
    subf	r0, r5, r9
    subfic	r31, r0, 0x1000
_8005af68:
    srawi	r0, r31, 0xb
    addze	r0, r0
    rlwinm.	r31, r0, 0xb, 0, 0x14
    ble     _8005affc
    mr	r29, r30
    slwi	r27, r31, 1
    li	r28, 0
    b     _8005afcc
_8005af88:
    lwz	r3, 0x38(r29)
    mr	r5, r27
    addi	r6, r1, 8
    li	r4, 1
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r3, 0x38(r29)
    addi	r5, r1, 8
    li	r4, 0
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    addi	r29, r29, 4
    addi	r28, r28, 1
_8005afcc:
    lbz	r0, 3(r30)
    extsb	r0, r0
    cmpw	r28, r0
    blt     _8005af88
    lwz	r0, 4(r30)
    add	r0, r0, r31
    stw	r0, 4(r30)
    lwz	r3, 4(r30)
    cmpwi	r3, 0x1000
    blt     _8005affc
    addi	r0, r3, -0x1000
    stw	r0, 4(r30)
_8005affc:
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8005B010(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8005b02c
    li	r3, -1
    b     _8005b058
_8005b02c:
    lbz	r0, 3(r3)
    li	r4, 0
    extsb	r0, r0
    slwi	r0, r0, 2
    add	r3, r3, r0
    lwz	r3, 0x34(r3)
    lwz	r5, 0(r3)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    srwi	r3, r3, 1
_8005b058:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005B068(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8005b084
    li	r3, -1
    b     _8005b0b4
_8005b084:
    lbz	r0, 3(r3)
    li	r4, 0
    extsb	r0, r0
    slwi	r0, r0, 2
    add	r3, r3, r0
    lwz	r3, 0x34(r3)
    lwz	r5, 0(r3)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    srwi	r0, r3, 1
    subfic	r3, r0, 0x1000
_8005b0b4:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005B0C4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    or.	r31, r3, r3
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    mr	r29, r4
    beq     _8005b248
    bne     _8005b0f4
    li	r0, -1
    b     _8005b0fc
_8005b0f4:
    lbz	r0, 1(r31)
    rlwinm	r0, r0, 0x1f, 0x1f, 0x1f
_8005b0fc:
    cmpw	r29, r0
    beq     _8005b248
    bl      svm_enter_critical_wrapper
    cmpwi	r29, 1
    bne     _8005b1b0
    li	r0, -1
    mr	r30, r31
    stw	r0, 4(r31)
    li	r29, 0
    b     _8005b190
_8005b124:
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8005b188
    lwz	r4, 0x20(r31)
    li	r5, 1
    lwz	r6, 0x18(r30)
    li	r0, 0xa
    addi	r7, r4, -1
    srawi	r4, r6, 0x10
    sth	r5, 8(r1)
    add	r7, r6, r7
    srawi	r5, r7, 0x10
    sth	r0, 0xa(r1)
    srawi	r0, r6, 0x10
    sth	r4, 0xc(r1)
    addi	r4, r1, 8
    sth	r6, 0xe(r1)
    sth	r5, 0x10(r1)
    sth	r7, 0x12(r1)
    sth	r0, 0x14(r1)
    sth	r6, 0x16(r1)
    bl      fn_80023284
    lwz	r3, 8(r30)
    li	r4, 1
    bl      AXSetVoiceType_cached
_8005b188:
    addi	r30, r30, 4
    addi	r29, r29, 1
_8005b190:
    lbz	r0, 3(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005b124
    lbz	r0, 1(r31)
    ori	r0, r0, 2
    stb	r0, 1(r31)
    b     _8005b244
_8005b1b0:
    cmpwi	r29, 0
    bne     _8005b238
    mr	r30, r31
    li	r29, 0
    b     _8005b1e0
_8005b1c4:
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8005b1d8
    li	r4, 0
    bl      AXSetVoiceType_cached
_8005b1d8:
    addi	r30, r30, 4
    addi	r29, r29, 1
_8005b1e0:
    lbz	r0, 3(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005b1c4
    mr	r30, r31
    li	r29, 0
    b     _8005b218
_8005b1fc:
    lwz	r3, 0x38(r30)
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
    addi	r30, r30, 4
    addi	r29, r29, 1
_8005b218:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005b1fc
    lbz	r0, 1(r31)
    clrlwi	r0, r0, 0x1f
    stb	r0, 1(r31)
    b     _8005b244
_8005b238:
    lis     r3, lbl_800927D0@ha
    addi	r3, r3, lbl_800927D0@l
    bl      fn_8005A5BC
_8005b244:
    bl      svm_exit_critical_wrapper
_8005b248:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8005B264(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    or.	r31, r3, r3
    lis     r3, lbl_80092790@ha
    addi	r5, r3, lbl_80092790@l
    beq     _8005b450
    bne     _8005b290
    li	r0, -1
    b     _8005b298
_8005b290:
    lbz	r0, 1(r31)
    clrlwi	r0, r0, 0x1f
_8005b298:
    cmpw	r4, r0
    beq     _8005b450
    cmpwi	r4, 1
    bne     _8005b35c
    bl      svm_enter_critical_wrapper
    mr	r30, r31
    mr	r29, r31
    mr	r28, r31
    li	r27, 0
    b     _8005b31c
_8005b2c0:
    lwz	r3, 0x38(r30)
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
    addi	r3, r29, 0x40
    li	r4, 0
    li	r5, 8
    bl      memset
    addi	r3, r29, 0x50
    li	r4, 0
    li	r5, 8
    bl      memset
    addi	r3, r28, 0xa8
    li	r4, 0
    li	r5, 0x20
    bl      memset
    li	r0, 0
    addi	r28, r28, 0x20
    stw	r0, 0x60(r30)
    addi	r30, r30, 4
    addi	r27, r27, 1
    addi	r29, r29, 8
_8005b31c:
    lbz	r0, 3(r31)
    extsb	r0, r0
    cmpw	r27, r0
    blt     _8005b2c0
    li	r3, 0
    li	r0, -1
    stw	r3, 0x68(r31)
    stw	r3, 0x6c(r31)
    stw	r3, 0x78(r31)
    stw	r3, 0x7c(r31)
    stw	r0, 4(r31)
    lbz	r0, 1(r31)
    ori	r0, r0, 1
    stb	r0, 1(r31)
    bl      svm_exit_critical_wrapper
    b     _8005b450
_8005b35c:
    cmpwi	r4, 0
    bne     _8005b448
    lbz	r6, 3(r31)
    lis	r3, 2
    mr	r4, r31
    li	r7, 0
    extsb	r6, r6
    addi	r3, r3, -0x7960
    b     _8005b430
_8005b380:
    li	r8, 0
    li	r9, 0
_8005b388:
    lwz	r0, 0x60(r4)
    cmpwi	r0, 0
    beq     _8005b3c0
    cmpw	r9, r3
    bge     _8005b3b4
    addi	r0, r3, 7
    srwi	r0, r0, 3
    mtctr	r0
    cmpwi	r3, 0
    ble     _8005b3b4
_8005b3b0:
    bdnz     _8005b3b0
_8005b3b4:
    addi	r8, r8, 1
    cmpwi	r8, 0xc8
    blt     _8005b388
_8005b3c0:
    cmpwi	r8, 0xc8
    bne     _8005b3d4
    addi	r3, r5, 0x64
    bl      fn_8005A5BC
    b     _8005b450
_8005b3d4:
    li	r8, 0
    mr	r9, r8
_8005b3dc:
    lwz	r0, 0x70(r4)
    cmpwi	r0, 0
    beq     _8005b414
    cmpw	r9, r3
    bge     _8005b408
    addi	r0, r3, 7
    srwi	r0, r0, 3
    mtctr	r0
    cmpwi	r3, 0
    ble     _8005b408
_8005b404:
    bdnz     _8005b404
_8005b408:
    addi	r8, r8, 1
    cmpwi	r8, 0xc8
    blt     _8005b3dc
_8005b414:
    cmpwi	r8, 0xc8
    bne     _8005b428
    addi	r3, r5, 0x9c
    bl      fn_8005A5BC
    b     _8005b450
_8005b428:
    addi	r4, r4, 4
    addi	r7, r7, 1
_8005b430:
    cmpw	r7, r6
    blt     _8005b380
    lbz	r0, 1(r31)
    rlwinm	r0, r0, 0, 0x1e, 0x1e
    stb	r0, 1(r31)
    b     _8005b450
_8005b448:
    addi	r3, r5, 0xd4
    bl      fn_8005A5BC
_8005b450:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005B464(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    or.	r29, r3, r3
    beq     _8005b518
    li	r4, 0
    bl      fn_8005B0C4
    mr	r3, r29
    li	r4, 0
    bl      fn_8005B264
    mr	r31, r29
    li	r30, 0
    b     _8005b4f8
_8005b4a4:
    lwz	r3, 0x38(r31)
    cmplwi	r3, 0
    beq     _8005b4c0
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8005b4c0:
    lwz	r3, 0x10(r31)
    cmplwi	r3, 0
    beq     _8005b4d0
    bl      fn_8005BE98
_8005b4d0:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8005b4ec
    bl      axmix_device_ctrl_clear
    lwz	r3, 8(r31)
    bl      AXFreeVoice
_8005b4ec:
    bl      svm_exit_critical_wrapper
    addi	r31, r31, 4
    addi	r30, r30, 1
_8005b4f8:
    lbz	r0, 2(r29)
    extsb	r0, r0
    cmpw	r30, r0
    blt     _8005b4a4
    mr	r3, r29
    li	r4, 0
    li	r5, 0xe8
    bl      memset
_8005b518:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005B534(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    cmpwi	r4, 0
    lis     r5, lbl_80092790@ha
    stw	r0, 0x34(r1)
    stmw	r26, 0x18(r1)
    addi	r30, r5, lbl_80092790@l
    bgt     _8005b564
    addi	r3, r30, 0xf8
    bl      fn_8005A5BC
    li	r3, 0
    b     _8005bc0c
_8005b564:
    cmplwi	r3, 0
    bne     _8005b57c
    addi	r3, r30, 0x120
    bl      fn_8005A5BC
    li	r3, 0
    b     _8005bc0c
_8005b57c:
    mr	r5, r3
    mtctr	r4
    cmplwi	r4, 0
    ble     _8005b5b0
_8005b58c:
    lwz	r0, 0(r5)
    cmplwi	r0, 0
    bne     _8005b5a8
    addi	r3, r30, 0x148
    bl      fn_8005A5BC
    li	r3, 0
    b     _8005bc0c
_8005b5a8:
    addi	r5, r5, 4
    bdnz     _8005b58c
_8005b5b0:
    lis     r5, lbl_80191D4C@ha
    li	r0, 2
    addi	r5, r5, lbl_80191D4C@l
    li	r7, 0
    mtctr	r0
_8005b5c4:
    lbz	r0, 0(r5)
    extsb.	r0, r0
    beq     _8005b668
    lbz	r0, 0xe8(r5)
    addi	r7, r7, 1
    addi	r5, r5, 0xe8
    extsb.	r0, r0
    beq     _8005b668
    lbz	r0, 0xe8(r5)
    addi	r7, r7, 1
    addi	r5, r5, 0xe8
    extsb.	r0, r0
    beq     _8005b668
    lbz	r0, 0xe8(r5)
    addi	r7, r7, 1
    addi	r5, r5, 0xe8
    extsb.	r0, r0
    beq     _8005b668
    lbz	r0, 0xe8(r5)
    addi	r7, r7, 1
    addi	r5, r5, 0xe8
    extsb.	r0, r0
    beq     _8005b668
    lbz	r0, 0xe8(r5)
    addi	r7, r7, 1
    addi	r5, r5, 0xe8
    extsb.	r0, r0
    beq     _8005b668
    lbz	r0, 0xe8(r5)
    addi	r7, r7, 1
    addi	r5, r5, 0xe8
    extsb.	r0, r0
    beq     _8005b668
    lbz	r0, 0xe8(r5)
    addi	r7, r7, 1
    addi	r5, r5, 0xe8
    extsb.	r0, r0
    beq     _8005b668
    addi	r5, r5, 0xe8
    addi	r7, r7, 1
    bdnz     _8005b5c4
_8005b668:
    cmplwi	r7, 0x10
    bne     _8005b680
    addi	r3, r30, 0x170
    bl      fn_8005A5BC
    li	r3, 0
    b     _8005bc0c
_8005b680:
    mulli	r6, r7, 0xe8
    lis     r5, lbl_80191D4C@ha
    addi	r0, r5, lbl_80191D4C@l
    add	r31, r0, r6
    stb	r4, 3(r31)
    mr	r5, r31
    li	r6, 0
    stb	r4, 2(r31)
    b     _8005b6b8
_8005b6a4:
    lwz	r0, 0(r3)
    addi	r3, r3, 4
    addi	r6, r6, 1
    stw	r0, 0x30(r5)
    addi	r5, r5, 4
_8005b6b8:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmplw	r6, r0
    blt     _8005b6a4
    li	r26, 0
    lis	r3, -0x7ffa
    stw	r26, 0x84(r31)
    li	r4, 0x7f
    li	r0, -0x3e7
    mr	r27, r31
    stw	r4, 0x90(r31)
    slwi	r28, r7, 1
    addi	r29, r3, -0x43e0
    stw	r0, 0x94(r31)
    stw	r0, 0x98(r31)
    stw	r26, 0x9c(r31)
    b     _8005b9c0
_8005b6fc:
    oris	r0, r28, 0x8000
    stw	r0, 0x28(r27)
    bl      fn_8005BEAC
    cmplwi	r3, 0
    stw	r3, 0x10(r27)
    bne     _8005b7c4
    addi	r3, r30, 0x194
    bl      fn_8005A5BC
    cmplwi	r31, 0
    beq     _8005b7bc
    mr	r3, r31
    li	r4, 0
    bl      fn_8005B0C4
    mr	r3, r31
    li	r4, 0
    bl      fn_8005B264
    mr	r30, r31
    li	r29, 0
    b     _8005b79c
_8005b748:
    lwz	r3, 0x38(r30)
    cmplwi	r3, 0
    beq     _8005b764
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8005b764:
    lwz	r3, 0x10(r30)
    cmplwi	r3, 0
    beq     _8005b774
    bl      fn_8005BE98
_8005b774:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8005b790
    bl      axmix_device_ctrl_clear
    lwz	r3, 8(r30)
    bl      AXFreeVoice
_8005b790:
    bl      svm_exit_critical_wrapper
    addi	r30, r30, 4
    addi	r29, r29, 1
_8005b79c:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005b748
    mr	r3, r31
    li	r4, 0
    li	r5, 0xe8
    bl      memset
_8005b7bc:
    li	r3, 0
    b     _8005bc0c
_8005b7c4:
    lwz	r3, 0x10(r27)
    bl      fn_8005BE80
    stw	r3, 0x18(r27)
    lwz	r3, 0x10(r27)
    bl      fn_8005BE68
    stw	r3, 0x20(r31)
    li	r5, 0
    lwz	r3, 0x18(r27)
    lwz	r0, 0x20(r31)
    slwi	r3, r3, 1
    slwi	r4, r0, 1
    bl      fn_80058498
    stw	r3, 0x38(r27)
    lwz	r0, 0x38(r27)
    cmplwi	r0, 0
    bne     _8005b8b4
    addi	r3, r30, 0x1b4
    bl      fn_8005A5BC
    cmplwi	r31, 0
    beq     _8005b8ac
    mr	r3, r31
    li	r4, 0
    bl      fn_8005B0C4
    mr	r3, r31
    li	r4, 0
    bl      fn_8005B264
    mr	r30, r31
    li	r29, 0
    b     _8005b88c
_8005b838:
    lwz	r3, 0x38(r30)
    cmplwi	r3, 0
    beq     _8005b854
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8005b854:
    lwz	r3, 0x10(r30)
    cmplwi	r3, 0
    beq     _8005b864
    bl      fn_8005BE98
_8005b864:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8005b880
    bl      axmix_device_ctrl_clear
    lwz	r3, 8(r30)
    bl      AXFreeVoice
_8005b880:
    bl      svm_exit_critical_wrapper
    addi	r30, r30, 4
    addi	r29, r29, 1
_8005b88c:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005b838
    mr	r3, r31
    li	r4, 0
    li	r5, 0xe8
    bl      memset
_8005b8ac:
    li	r3, 0
    b     _8005bc0c
_8005b8b4:
    mr	r4, r29
    li	r3, 0x1f
    li	r5, 0
    bl      AXAcquireVoice
    cmplwi	r3, 0
    stw	r3, 8(r27)
    bne     _8005b980
    addi	r3, r30, 0x1d0
    bl      fn_8005A5BC
    cmplwi	r31, 0
    beq     _8005b978
    mr	r3, r31
    li	r4, 0
    bl      fn_8005B0C4
    mr	r3, r31
    li	r4, 0
    bl      fn_8005B264
    mr	r30, r31
    li	r29, 0
    b     _8005b958
_8005b904:
    lwz	r3, 0x38(r30)
    cmplwi	r3, 0
    beq     _8005b920
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8005b920:
    lwz	r3, 0x10(r30)
    cmplwi	r3, 0
    beq     _8005b930
    bl      fn_8005BE98
_8005b930:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8005b94c
    bl      axmix_device_ctrl_clear
    lwz	r3, 8(r30)
    bl      AXFreeVoice
_8005b94c:
    bl      svm_exit_critical_wrapper
    addi	r30, r30, 4
    addi	r29, r29, 1
_8005b958:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005b904
    mr	r3, r31
    li	r4, 0
    li	r5, 0xe8
    bl      memset
_8005b978:
    li	r3, 0
    b     _8005bc0c
_8005b980:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r27)
    cmplwi	r3, 0
    beq     _8005b9b0
    lwz	r5, 0x84(r31)
    li	r4, 3
    lwz	r6, 0x94(r31)
    li	r8, 0x40
    lwz	r7, 0x98(r31)
    lwz	r9, 0x90(r31)
    lwz	r10, 0x9c(r31)
    bl      fn_80025EF4
_8005b9b0:
    bl      svm_exit_critical_wrapper
    addi	r28, r28, 1
    addi	r27, r27, 4
    addi	r26, r26, 1
_8005b9c0:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmplw	r26, r0
    blt     _8005b6fc
    lis	r3, -0x7fe7
    cmplwi	r31, 0
    lwz	r0, 0xc80(r3)
    beq     _8005b9e4
    sth	r0, 0xa0(r31)
_8005b9e4:
    lis	r3, -0x7fed
    cmplwi	r31, 0
    lwz	r0, 0x2558(r3)
    beq     _8005ba00
    stw	r0, 0xa4(r31)
    li	r0, 1
    sth	r0, 0xa2(r31)
_8005ba00:
    li	r29, 0
    cmplwi	r31, 0
    sth	r29, 0xa2(r31)
    beq     _8005bab4
    lis	r3, 1
    mr	r27, r31
    addi	r0, r3, -0x4480
    stw	r0, 0x24(r31)
    b     _8005baa4
_8005ba24:
    bl      svm_enter_critical_wrapper
    lwz	r0, 8(r27)
    cmplwi	r0, 0
    beq     _8005ba98
    lha	r0, 0xa0(r31)
    cmpwi	r0, 1
    bne     _8005ba54
    li	r3, 1
    li	r0, 0x7fa9
    sth	r3, 8(r1)
    sth	r0, 0xa(r1)
    b     _8005ba68
_8005ba54:
    lis	r3, 1
    li	r4, 1
    addi	r0, r3, -0x8000
    sth	r4, 8(r1)
    sth	r0, 0xa(r1)
_8005ba68:
    li	r0, 0
    lwz	r3, 8(r27)
    sth	r0, 0xc(r1)
    lwz	r4, 0xa4(r31)
    sth	r0, 0xe(r1)
    sth	r0, 0x10(r1)
    sth	r0, 0x12(r1)
    sth	r0, 0x14(r1)
    bl      fn_800230A4
    lwz	r3, 8(r27)
    addi	r4, r1, 8
    bl      fn_80023438
_8005ba98:
    bl      svm_exit_critical_wrapper
    addi	r27, r27, 4
    addi	r29, r29, 1
_8005baa4:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8005ba24
_8005bab4:
    cmplwi	r31, 0
    beq     _8005bac4
    li	r0, 0x10
    stw	r0, 0x80(r31)
_8005bac4:
    lbz	r3, 2(r31)
    cmpwi	r3, 2
    bne     _8005bb90
    cmplwi	r31, 0
    beq     _8005bb24
    extsb.	r0, r3
    ble     _8005bb24
    li	r29, -0xf
    cmpwi	r29, -0xf
    lwz	r0, 0x88(r31)
    cmpw	r29, r0
    beq     _8005bb24
    stw	r29, 0x88(r31)
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8005bb20
    lis     r4, adxt_volume_scale_table@ha
    slwi	r0, r29, 2
    addi	r4, r4, adxt_volume_scale_table@l
    add	r4, r4, r0
    lwz	r4, 0x3c(r4)
    bl      fn_80026EE0
_8005bb20:
    bl      svm_exit_critical_wrapper
_8005bb24:
    cmplwi	r31, 0
    beq     _8005bbf8
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpwi	r0, 1
    ble     _8005bbf8
    li	r0, 0xf
    li	r30, -0xf
    cmpwi	r0, -0xf
    ble     _8005bb50
    mr	r30, r0
_8005bb50:
    lwz	r0, 0x8c(r31)
    cmpw	r30, r0
    beq     _8005bbf8
    stw	r30, 0x8c(r31)
    bl      svm_enter_critical_wrapper
    lwz	r3, 0xc(r31)
    cmplwi	r3, 0
    beq     _8005bb88
    lis     r4, adxt_volume_scale_table@ha
    slwi	r0, r30, 2
    addi	r4, r4, adxt_volume_scale_table@l
    add	r4, r4, r0
    lwz	r4, 0x3c(r4)
    bl      fn_80026EE0
_8005bb88:
    bl      svm_exit_critical_wrapper
    b     _8005bbf8
_8005bb90:
    cmplwi	r31, 0
    beq     _8005bbf8
    extsb.	r0, r3
    ble     _8005bbf8
    li	r3, 0
    li	r5, -0xf
    subfc	r0, r3, r5
    lwz	r0, 0x88(r31)
    srwi	r4, r3, 0x1f
    srwi	r3, r5, 0x1f
    subfe	r3, r3, r4
    andc	r29, r5, r3
    cmpw	r29, r0
    beq     _8005bbf8
    stw	r29, 0x88(r31)
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8005bbf4
    lis     r4, adxt_volume_scale_table@ha
    slwi	r0, r29, 2
    addi	r4, r4, adxt_volume_scale_table@l
    add	r4, r4, r0
    lwz	r4, 0x3c(r4)
    bl      fn_80026EE0
_8005bbf4:
    bl      svm_exit_critical_wrapper
_8005bbf8:
    li	r3, 0
    li	r0, 1
    stb	r3, 1(r31)
    mr	r3, r31
    stb	r0, 0(r31)
_8005bc0c:
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
