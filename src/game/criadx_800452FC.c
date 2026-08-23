#pragma push
#pragma force_active on

extern void fn_8004E198(void);
extern void fn_8004E1B0(void);
extern void fn_8004E300(void);
extern void fn_8004E2CC(void);
extern void fn_8004E2DC(void);
extern void fn_8004E2B0(void);
extern void CRI_FORM_parser(void);
extern void criadx_spsd_probe(void);
extern void fn_800462F8(void);
extern void criadx_wav_probe(void);
extern void fn_80043050(void);
extern void criadx_aiff_probe(void);
extern void fn_80043B48(void);
extern void CRI_WAVE_parser(void);
extern void criadx_snd_probe(void);
extern void fn_80046C28(void);
extern void adx_err_report(void);
extern void fn_80046B90(void);
extern void sprintf(void);
extern void fn_80046BE0(void);
extern void fn_80046AC0(void);
extern void fn_8004E324(void);
extern void fn_800469A4(void);
extern void fn_8004683C(void);
extern void fn_8004E278(void);
extern void memset(void);
extern void fn_8004E354(void);
extern void fn_8004E4AC(void);
extern void strncmp(void);
extern void ADXT_GetCmdState(void);
extern unsigned char SPSD_str[5];
extern void fn_80045F58(void);
extern void fn_80045F74(void);
extern unsigned char lbl_8017A288[20];
extern unsigned char lbl_8017A29C[3460];
extern void fn_80045F58(void);
extern void fn_80045F74(void);

asm void fn_800452FC(void)
{
    nofralloc
    lwz	r3, 0x90(r3)
    blr	
}

asm void fn_80045304(void)
{
    nofralloc
    lwz	r3, 0x94(r3)
    blr	
}

asm void fn_8004530C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lwz	r0, 4(r3)
    cmpwi	r0, 3
    bne     _80045340
    lwz	r3, 8(r31)
    bl      fn_8004E198
    li	r0, 0
    stw	r0, 0x8c(r31)
    stw	r0, 4(r31)
_80045340:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80045354(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lwz	r3, 8(r3)
    bl      fn_8004E1B0
    li	r0, 0
    stw	r0, 4(r31)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004538C(void)
{
    nofralloc
    lwz	r0, 4(r3)
    cmpwi	r0, 0
    bnelr	
    li	r0, 1
    stw	r0, 4(r3)
    blr	
}

asm void fn_800453A4(void)
{
    nofralloc
    lha	r0, 0x98(r3)
    cmpwi	r0, 0
    bne     _800453d8
    stw	r4, 0x48(r3)
    li	r0, 0
    lbz	r4, 0xf(r3)
    extsb	r4, r4
    divw	r4, r5, r4
    stw	r4, 0x4c(r3)
    stw	r0, 0x74(r3)
    stw	r0, 0x90(r3)
    stw	r0, 0x94(r3)
    blr	
_800453d8:
    stw	r4, 0x48(r3)
    li	r0, 0
    lbz	r6, 0xd(r3)
    lbz	r4, 0xe(r3)
    extsb	r6, r6
    srawi	r6, r6, 3
    extsb	r4, r4
    addze	r6, r6
    mullw	r4, r6, r4
    divw	r4, r5, r4
    stw	r4, 0x4c(r3)
    stw	r0, 0x74(r3)
    stw	r0, 0x90(r3)
    stw	r0, 0x94(r3)
    blr	
}

asm void fn_80045414(void)
{
    nofralloc
    lwz	r3, 4(r3)
    blr	
}

asm void fn_8004541C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    addi	r4, r31, 0xa8
    lwz	r3, 8(r3)
    addi	r5, r31, 0xac
    bl      fn_8004E300
    lwz	r3, 8(r31)
    lha	r4, 0xa2(r31)
    lha	r5, 0xa4(r31)
    lha	r6, 0xa6(r31)
    bl      fn_8004E2CC
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80045468(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    addi	r4, r31, 0xa8
    lwz	r3, 8(r3)
    addi	r5, r31, 0xac
    bl      fn_8004E2DC
    lwz	r3, 8(r31)
    addi	r4, r31, 0xa2
    addi	r5, r31, 0xa4
    addi	r6, r31, 0xa6
    bl      fn_8004E2B0
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800454B4(void)
{
    nofralloc
    slwi	r0, r4, 1
    add	r3, r3, r0
    lha	r3, 0xd2(r3)
    blr	
}

asm void fn_800454C4(void)
{
    nofralloc
    lha	r3, 0xd0(r3)
    blr	
}

asm void fn_800454CC(void)
{
    nofralloc
    lwz	r3, 0xbc(r3)
    blr	
}

asm void fn_800454D4(void)
{
    nofralloc
    lwz	r3, 0x34(r3)
    blr	
}

asm void fn_800454DC(void)
{
    nofralloc
    lwz	r3, 0x30(r3)
    blr	
}

asm void fn_800454E4(void)
{
    nofralloc
    cmplwi	r3, 0
    bne     _800454f4
    li	r3, 0
    blr	
_800454f4:
    lwz	r3, 0x2c(r3)
    blr	
}

asm void fn_800454FC(void)
{
    nofralloc
    lwz	r3, 0x28(r3)
    blr	
}

asm void fn_80045504(void)
{
    nofralloc
    lha	r3, 0x24(r3)
    blr	
}

asm void fn_8004550C(void)
{
    nofralloc
    lwz	r3, 0x18(r3)
    blr	
}

asm void fn_80045514(void)
{
    nofralloc
    lwz	r3, 0x10(r3)
    blr	
}

asm void fn_8004551C(void)
{
    nofralloc
    lha	r4, 0x98(r3)
    extsh.	r0, r4
    bne     _80045530
    li	r3, 0x10
    blr	
_80045530:
    cmpwi	r4, 2
    bne     _80045560
    lha	r0, 0x9a(r3)
    cmpwi	r0, 2
    bne     _8004554c
    li	r3, 4
    blr	
_8004554c:
    cmpwi	r0, 1
    li	r3, 0x10
    bnelr	
    li	r3, 8
    blr	
_80045560:
    cmpwi	r4, 1
    bne     _80045580
    lha	r0, 0x9a(r3)
    li	r3, 0x10
    cmpwi	r0, 2
    bnelr	
    li	r3, 4
    blr	
_80045580:
    li	r3, 0x10
    blr	
}

asm void fn_80045588(void)
{
    nofralloc
    lbz	r3, 0xe(r3)
    extsb	r3, r3
    blr	
}

asm void fn_80045594(void)
{
    nofralloc
    lwz	r3, 0x14(r3)
    blr	
}

asm void fn_8004559C(void)
{
    nofralloc
    lha	r3, 0x98(r3)
    blr	
}

asm void fn_800455A4(void)
{
    nofralloc
    lwz	r3, 0x3c(r3)
    blr	
}

asm void fn_800455AC(void)
{
    nofralloc
    stw	r4, 0x78(r3)
    stw	r5, 0x7c(r3)
    blr	
}

asm void criadx_format_dispatch(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    mr	r29, r3
    lhz	r0, 0(r4)
    cmplwi	r0, 0x8000
    bne     _800455f0
    bl      CRI_FORM_parser
    b       _80045684
_800455f0:
    mr	r3, r30
    bl      criadx_spsd_probe
    cmpwi	r3, 0
    beq     _80045614
    mr	r3, r29
    mr	r4, r30
    mr	r5, r31
    bl      fn_800462F8
    b       _80045684
_80045614:
    mr	r3, r30
    bl      criadx_wav_probe
    cmpwi	r3, 0
    beq     _80045638
    mr	r3, r29
    mr	r4, r30
    mr	r5, r31
    bl      fn_80043050
    b       _80045684
_80045638:
    mr	r3, r30
    bl      criadx_aiff_probe
    cmpwi	r3, 0
    beq     _8004565c
    mr	r3, r29
    mr	r4, r30
    mr	r5, r31
    bl      fn_80043B48
    b       _80045684
_8004565c:
    mr	r3, r30
    bl      CRI_WAVE_parser
    cmpwi	r3, 0
    beq     _80045680
    mr	r3, r29
    mr	r4, r30
    mr	r5, r31
    bl      criadx_snd_probe
    b       _80045684
_80045680:
    li	r3, -1
_80045684:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void CRI_FORM_parser(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    lis	r6, -0x7ff7
    stw	r0, 0x54(r1)
    li	r0, 1
    stmw	r26, 0x38(r1)
    mr	r29, r3
    mr	r31, r5
    mr	r30, r4
    lis     r5, lbl_8017A288@ha
    addi	r27, r6, 0xa0
    addi	r26, r5, lbl_8017A288@l
    mr	r4, r31
    addi	r5, r1, 0x12
    addi	r6, r29, 0xc
    addi	r7, r29, 0xd
    addi	r8, r29, 0xf
    addi	r9, r29, 0xe
    addi	r10, r29, 0x14
    sth	r0, 2(r3)
    addi	r0, r29, 0x18
    mr	r3, r30
    stw	r0, 8(r1)
    addi	r0, r29, 0x10
    stw	r0, 0xc(r1)
    bl      fn_80046C28
    cmpwi	r3, 0
    bge     _80045718
    li	r3, 0
    b       _80045d28
_80045718:
    lbz	r0, 0xc(r29)
    extsb	r0, r0
    cmpwi	r0, 4
    ble     _80045798
    lwz	r0, 0xb0(r29)
    cmplwi	r0, 0
    bne     _80045748
    addi	r3, r27, 0x838
    addi	r4, r27, 0x858
    bl      adx_err_report
    li	r3, -1
    b       _80045d28
_80045748:
    li	r0, 8
    li	r4, 0x60
    stb	r0, 0xd(r29)
    li	r3, 0xa
    li	r0, 0
    lbz	r5, 0xe(r29)
    mulli	r5, r5, 0xc0
    stb	r5, 0xf(r29)
    stw	r4, 0x10(r29)
    sth	r3, 0x98(r29)
    sth	r0, 0x1c(r29)
    sth	r0, 0x24(r29)
    sth	r0, 0x26(r29)
    stw	r0, 0x20(r29)
    stw	r0, 0x28(r29)
    stw	r0, 0x2c(r29)
    stw	r0, 0x30(r29)
    stw	r0, 0x34(r29)
    stw	r0, 0x88(r29)
    b       _80045ce4
_80045798:
    mr	r3, r30
    mr	r4, r31
    addi	r5, r1, 0x11
    addi	r6, r1, 0x10
    bl      fn_80046B90
    cmpwi	r3, 0
    bge     _800457bc
    li	r3, 0
    b       _80045d28
_800457bc:
    lbz	r0, 0x11(r1)
    lwz	r5, 0x18(r29)
    cmplwi	r0, 4
    lbz	r0, 0x10(r1)
    bge     _800457e0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    b       _80045c14
_800457e0:
    cmplwi	r0, 0x10
    blt     _80045bb4
    addi	r3, r1, 0x1c
    addi	r4, r27, 0x830
    crxor	6, 6, 6
    bl      sprintf
    lwz	r3, 0(r26)
    cmpwi	r3, 0
    bne     _8004580c
    addi	r0, r3, 1
    stw	r0, 0(r26)
_8004580c:
    lbz	r0, 0x1c(r1)
    addi	r3, r27, 0x30
    lbz	r5, 0x1d(r1)
    addi	r4, r3, 0x100
    extsb	r6, r0
    lbz	r0, 0x1e(r1)
    slwi	r6, r6, 1
    extsb	r5, r5
    lha	r7, 0x200(r3)
    slwi	r10, r5, 1
    lhax	r5, r4, r6
    extsb	r0, r0
    slwi	r11, r0, 1
    lbz	r6, 0x1f(r1)
    mullw	r12, r7, r5
    lbz	r0, 0x20(r1)
    extsb	r8, r6
    lbz	r7, 0x21(r1)
    extsb	r6, r0
    lbz	r0, 0x22(r1)
    slwi	r9, r12, 0x16
    srwi	r26, r12, 0x1f
    subf	r9, r26, r9
    slwi	r8, r8, 1
    rotlwi	r12, r9, 0xa
    slwi	r9, r6, 1
    add	r12, r12, r26
    lhax	r6, r4, r10
    slwi	r10, r12, 1
    extsb	r7, r7
    lhax	r12, r3, r10
    slwi	r10, r7, 1
    extsb	r0, r0
    lhax	r7, r4, r11
    mullw	r12, r12, r6
    lhax	r8, r4, r8
    slwi	r0, r0, 1
    lhax	r9, r4, r9
    lhax	r10, r4, r10
    lhax	r11, r4, r0
    slwi	r0, r12, 0x16
    srwi	r12, r12, 0x1f
    subf	r0, r12, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r12
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r12, r0, r7
    slwi	r0, r12, 0x16
    srwi	r12, r12, 0x1f
    subf	r0, r12, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r12
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r12, r0, r8
    slwi	r0, r12, 0x16
    srwi	r12, r12, 0x1f
    subf	r0, r12, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r12
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r12, r0, r9
    slwi	r0, r12, 0x16
    srwi	r12, r12, 0x1f
    subf	r0, r12, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r12
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r12, r0, r10
    slwi	r0, r12, 0x16
    srwi	r12, r12, 0x1f
    subf	r0, r12, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r12
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r12, r0, r11
    slwi	r0, r12, 0x16
    srwi	r12, r12, 0x1f
    subf	r0, r12, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r12
    slwi	r0, r0, 1
    lhax	r12, r3, r0
    lha	r0, 0x400(r3)
    extsh	r26, r12
    lbz	r12, 0x23(r1)
    mullw	r27, r0, r5
    lha	r28, 0x600(r3)
    extsb	r0, r12
    slwi	r0, r0, 1
    lhax	r12, r4, r0
    slwi	r0, r27, 0x16
    srwi	r4, r27, 0x1f
    subf	r0, r4, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r4
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r26, r26, r12
    mullw	r4, r0, r6
    slwi	r0, r26, 0x16
    srwi	r26, r26, 0x1f
    subf	r27, r26, r0
    slwi	r0, r4, 0x16
    srwi	r4, r4, 0x1f
    rotlwi	r27, r27, 0xa
    subf	r0, r4, r0
    rotlwi	r0, r0, 0xa
    add	r26, r27, r26
    add	r0, r0, r4
    slwi	r0, r0, 1
    slwi	r27, r26, 1
    lhax	r4, r3, r0
    lhax	r0, r3, r27
    mullw	r27, r4, r7
    slwi	r4, r27, 0x16
    srwi	r27, r27, 0x1f
    subf	r4, r27, r4
    rotlwi	r4, r4, 0xa
    add	r4, r4, r27
    slwi	r4, r4, 1
    lhax	r4, r3, r4
    mullw	r27, r4, r8
    slwi	r4, r27, 0x16
    srwi	r27, r27, 0x1f
    subf	r4, r27, r4
    rotlwi	r4, r4, 0xa
    add	r4, r4, r27
    slwi	r4, r4, 1
    lhax	r4, r3, r4
    mullw	r27, r4, r9
    slwi	r4, r27, 0x16
    srwi	r27, r27, 0x1f
    subf	r4, r27, r4
    rotlwi	r4, r4, 0xa
    add	r4, r4, r27
    slwi	r4, r4, 1
    lhax	r4, r3, r4
    mullw	r27, r4, r10
    slwi	r4, r27, 0x16
    srwi	r27, r27, 0x1f
    subf	r4, r27, r4
    rotlwi	r4, r4, 0xa
    add	r4, r4, r27
    slwi	r4, r4, 1
    lhax	r4, r3, r4
    mullw	r27, r4, r11
    slwi	r4, r27, 0x16
    srwi	r27, r27, 0x1f
    subf	r4, r27, r4
    rotlwi	r4, r4, 0xa
    add	r4, r4, r27
    slwi	r4, r4, 1
    lhax	r4, r3, r4
    mullw	r27, r4, r12
    slwi	r4, r27, 0x16
    srwi	r27, r27, 0x1f
    subf	r4, r27, r4
    rotlwi	r4, r4, 0xa
    add	r4, r4, r27
    slwi	r4, r4, 1
    lhax	r27, r3, r4
    extsh	r28, r28
    mr	r4, r0
    mullw	r28, r28, r5
    mr	r5, r27
    slwi	r0, r28, 0x16
    srwi	r28, r28, 0x1f
    subf	r0, r28, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r28
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r6, r0, r6
    slwi	r0, r6, 0x16
    srwi	r6, r6, 0x1f
    subf	r0, r6, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r6
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r6, r0, r7
    slwi	r0, r6, 0x16
    srwi	r6, r6, 0x1f
    subf	r0, r6, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r6
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r6, r0, r8
    slwi	r0, r6, 0x16
    srwi	r6, r6, 0x1f
    subf	r0, r6, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r6
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r6, r0, r9
    slwi	r0, r6, 0x16
    srwi	r6, r6, 0x1f
    subf	r0, r6, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r6
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r6, r0, r10
    slwi	r0, r6, 0x16
    srwi	r6, r6, 0x1f
    subf	r0, r6, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r6
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r6, r0, r11
    slwi	r0, r6, 0x16
    srwi	r6, r6, 0x1f
    subf	r0, r6, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r6
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    mullw	r6, r0, r12
    slwi	r0, r6, 0x16
    srwi	r6, r6, 0x1f
    subf	r0, r6, r0
    rotlwi	r0, r0, 0xa
    add	r0, r0, r6
    slwi	r0, r0, 1
    lhax	r6, r3, r0
    b       _80045c14
_80045bb4:
    cmplwi	r0, 8
    blt     _80045c08
    lha	r0, 0x9c(r29)
    cmpwi	r0, 0
    bne     _80045bf8
    lha	r0, 0x9e(r29)
    cmpwi	r0, 0
    bne     _80045bf8
    lha	r0, 0xa0(r29)
    cmpwi	r0, 0
    bne     _80045bf8
    lha	r0, 0xc(r26)
    sth	r0, 0x9c(r29)
    lha	r0, 0xe(r26)
    sth	r0, 0x9e(r29)
    lha	r0, 0x10(r26)
    sth	r0, 0xa0(r29)
_80045bf8:
    lha	r4, 0x9c(r29)
    lha	r5, 0x9e(r29)
    lha	r6, 0xa0(r29)
    b       _80045c14
_80045c08:
    li	r4, 0
    li	r5, 0
    li	r6, 0
_80045c14:
    li	r0, 0
    cmpwi	r0, 0
    bge     _80045c28
    li	r3, -1
    b       _80045d28
_80045c28:
    lwz	r3, 8(r29)
    bl      fn_8004E2CC
    mr	r3, r30
    mr	r4, r31
    addi	r5, r29, 0x1c
    bl      fn_80046BE0
    cmpwi	r3, 0
    bge     _80045c50
    li	r3, 0
    b       _80045d28
_80045c50:
    mr	r3, r30
    mr	r4, r31
    addi	r5, r1, 0x18
    addi	r6, r1, 0x14
    bl      fn_80046AC0
    cmpwi	r3, 0
    bge     _80045c74
    li	r3, 0
    b       _80045d28
_80045c74:
    lwz	r3, 8(r29)
    lwz	r4, 0x14(r29)
    lha	r5, 0x1c(r29)
    bl      fn_8004E324
    lwz	r3, 8(r29)
    addi	r4, r1, 0x18
    addi	r5, r1, 0x14
    bl      fn_8004E300
    addi	r0, r29, 0x34
    mr	r3, r30
    stw	r0, 8(r1)
    mr	r4, r31
    addi	r5, r29, 0x20
    addi	r6, r29, 0x24
    addi	r7, r29, 0x26
    addi	r8, r29, 0x28
    addi	r9, r29, 0x2c
    addi	r10, r29, 0x30
    bl      fn_800469A4
    mr	r3, r30
    mr	r4, r31
    addi	r5, r29, 0xbc
    addi	r6, r29, 0xc0
    addi	r7, r29, 0xd0
    addi	r8, r29, 0xd2
    bl      fn_8004683C
    li	r0, 0
    sth	r0, 0x98(r29)
_80045ce4:
    lbz	r3, 0xe(r29)
    li	r0, 0
    extsb	r3, r3
    stw	r3, 0x50(r29)
    lbz	r3, 0xf(r29)
    extsb	r3, r3
    stw	r3, 0x54(r29)
    lwz	r3, 0x10(r29)
    stw	r3, 0x58(r29)
    lwz	r3, 0x3c(r29)
    stw	r3, 0x5c(r29)
    lwz	r3, 0x40(r29)
    stw	r3, 0x60(r29)
    lwz	r3, 0x44(r29)
    stw	r3, 0x64(r29)
    stw	r0, 0x8c(r29)
    lha	r3, 0x12(r1)
_80045d28:
    lmw	r26, 0x38(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_80045D3C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    beq     _80045d7c
    lwz	r3, 8(r31)
    li	r0, 0
    stw	r0, 8(r31)
    bl      fn_8004E278
    mr	r3, r31
    li	r4, 0
    li	r5, 0xd8
    bl      memset
    li	r0, 0
    sth	r0, 0(r31)
_80045d7c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80045D90(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r7, lbl_8017A29C@ha
    stw	r0, 0x24(r1)
    li	r0, 2
    addi	r7, r7, lbl_8017A29C@l
    stmw	r27, 0xc(r1)
    mr	r27, r3
    mr	r28, r4
    mr	r30, r5
    mr	r31, r6
    li	r3, 0
    mtctr	r0
_80045dc4:
    lha	r0, 0(r7)
    cmpwi	r0, 0
    beq     _80045e68
    lha	r0, 0xd8(r7)
    addi	r3, r3, 1
    addi	r7, r7, 0xd8
    cmpwi	r0, 0
    beq     _80045e68
    lha	r0, 0xd8(r7)
    addi	r3, r3, 1
    addi	r7, r7, 0xd8
    cmpwi	r0, 0
    beq     _80045e68
    lha	r0, 0xd8(r7)
    addi	r3, r3, 1
    addi	r7, r7, 0xd8
    cmpwi	r0, 0
    beq     _80045e68
    lha	r0, 0xd8(r7)
    addi	r3, r3, 1
    addi	r7, r7, 0xd8
    cmpwi	r0, 0
    beq     _80045e68
    lha	r0, 0xd8(r7)
    addi	r3, r3, 1
    addi	r7, r7, 0xd8
    cmpwi	r0, 0
    beq     _80045e68
    lha	r0, 0xd8(r7)
    addi	r3, r3, 1
    addi	r7, r7, 0xd8
    cmpwi	r0, 0
    beq     _80045e68
    lha	r0, 0xd8(r7)
    addi	r3, r3, 1
    addi	r7, r7, 0xd8
    cmpwi	r0, 0
    beq     _80045e68
    addi	r7, r7, 0xd8
    addi	r3, r3, 1
    bdnz    _80045dc4
_80045e68:
    cmpwi	r3, 0x10
    bne     _80045e78
    li	r3, 0
    b       _80045f44
_80045e78:
    mulli	r5, r3, 0xd8
    lis     r3, lbl_8017A29C@ha
    li	r4, 0
    addi	r0, r3, lbl_8017A29C@l
    add	r29, r0, r5
    li	r5, 0xd8
    mr	r3, r29
    bl      memset
    li	r0, 1
    sth	r0, 0(r29)
    bl      fn_8004E354
    stw	r3, 8(r29)
    lwz	r3, 8(r29)
    cmplwi	r3, 0
    bne     _80045ee8
    cmplwi	r29, 0
    beq     _80045ee0
    li	r0, 0
    stw	r0, 8(r29)
    bl      fn_8004E278
    mr	r3, r29
    li	r4, 0
    li	r5, 0xd8
    bl      memset
    li	r0, 0
    sth	r0, 0(r29)
_80045ee0:
    li	r3, 0
    b       _80045f44
_80045ee8:
    stw	r27, 0x38(r29)
    lis     r4, fn_80045F74@ha
    lis     r3, fn_80045F58@ha
    li	r6, 0
    stw	r28, 0x3c(r29)
    addi	r8, r4, fn_80045F74@l
    addi	r7, r3, fn_80045F58@l
    li	r0, -0x80
    stw	r30, 0x40(r29)
    addi	r3, r29, 0xc0
    li	r4, 0
    li	r5, 0x10
    stw	r31, 0x44(r29)
    stw	r8, 0x78(r29)
    stw	r29, 0x7c(r29)
    stw	r7, 0x80(r29)
    stw	r29, 0x84(r29)
    stw	r6, 0xbc(r29)
    sth	r6, 0xd0(r29)
    sth	r0, 0xd2(r29)
    sth	r0, 0xd4(r29)
    bl      memset
    mr	r3, r29
_80045f44:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}
asm void fn_80045F58(void)
{
    nofralloc
    lwz	r0, 0x8c(r3)
    add	r0, r0, r5
    stw	r0, 0x8c(r3)
    lwz	r0, 0x88(r3)
    add	r0, r0, r5
    stw	r0, 0x88(r3)
    blr	
}

asm void fn_80045F74(void)
{
    nofralloc
    lwz	r0, 0x8c(r3)
    stw	r0, 0(r4)
    lwz	r4, 0x8c(r3)
    lwz	r0, 0x40(r3)
    subf	r0, r4, r0
    stw	r0, 0(r5)
    lwz	r4, 0x88(r3)
    lwz	r0, 0x18(r3)
    subf	r0, r4, r0
    stw	r0, 0(r6)
    lwz	r3, 0x3c(r3)
    blr	
}

asm void fn_80045FA4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8004E4AC
    lis     r4, lbl_8017A288@ha
    lis     r3, lbl_8017A29C@ha
    addi	r7, r4, lbl_8017A288@l
    li	r5, 0xd80
    lwz	r6, 0(r7)
    li	r4, 0
    addi	r3, r3, lbl_8017A29C@l
    addi	r0, r6, 1
    stw	r0, 0(r7)
    bl      memset
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void criadx_spsd_probe(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, SPSD_str@ha
    li	r5, 4
    stw	r0, 0x14(r1)
    addi	r4, r4, SPSD_str@l
    bl      strncmp
    cntlzw	r0, r3
    srwi	r3, r0, 5
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80046020(void)
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
    bne     _800462b4
    lwz	r3, 8(r30)
    bl      ADXT_GetCmdState
    cmpwi	r3, 0
    bne     _800462b4
    lwz	r12, 0x78(r30)
    addi	r4, r30, 0x68
    addi	r5, r30, 0x6c
    addi	r6, r30, 0x70
    lwz	r3, 0x7c(r30)
    mtctr	r12
    bctrl	
    lwz	r6, 0x68(r30)
    lwz	r0, 0x60(r30)
    lwz	r3, 0x6c(r30)
    subf	r5, r6, r0
    cmpw	r5, r3
    ble     _80046090
    mr	r5, r3
_80046090:
    lwz	r0, 0x4c(r30)
    cmpw	r5, r0
    ble     _800460a0
    mr	r5, r0
_800460a0:
    lbz	r0, 0xe(r30)
    slwi	r3, r6, 1
    lwz	r7, 0x5c(r30)
    extsb	r0, r0
    cmpwi	r0, 2
    add	r0, r7, r3
    bne     _800461e0
    lwz	r3, 0x64(r30)
    cmpwi	r5, 0
    li	r4, 0
    add	r3, r3, r6
    slwi	r3, r3, 1
    add	r3, r7, r3
    ble     _80046294
    cmpwi	r5, 8
    addi	r7, r5, -8
    ble     _80046198
    addi	r6, r7, 7
    mr	r8, r31
    srwi	r6, r6, 3
    mr	r9, r0
    mr	r10, r3
    mtctr	r6
    cmpwi	r7, 0
    ble     _80046198
_80046104:
    lhz	r6, 0(r8)
    addi	r4, r4, 8
    sth	r6, 0(r9)
    lhz	r6, 2(r8)
    sth	r6, 0(r10)
    lhz	r6, 4(r8)
    sth	r6, 2(r9)
    lhz	r6, 6(r8)
    sth	r6, 2(r10)
    lhz	r6, 8(r8)
    sth	r6, 4(r9)
    lhz	r6, 0xa(r8)
    sth	r6, 4(r10)
    lhz	r6, 0xc(r8)
    sth	r6, 6(r9)
    lhz	r6, 0xe(r8)
    sth	r6, 6(r10)
    lhz	r6, 0x10(r8)
    sth	r6, 8(r9)
    lhz	r6, 0x12(r8)
    sth	r6, 8(r10)
    lhz	r6, 0x14(r8)
    sth	r6, 0xa(r9)
    lhz	r6, 0x16(r8)
    sth	r6, 0xa(r10)
    lhz	r6, 0x18(r8)
    sth	r6, 0xc(r9)
    lhz	r6, 0x1a(r8)
    sth	r6, 0xc(r10)
    lhz	r6, 0x1c(r8)
    sth	r6, 0xe(r9)
    addi	r9, r9, 0x10
    lhz	r6, 0x1e(r8)
    addi	r8, r8, 0x20
    sth	r6, 0xe(r10)
    addi	r10, r10, 0x10
    bdnz    _80046104
_80046198:
    slwi	r9, r4, 1
    slwi	r7, r4, 2
    subf	r6, r4, r5
    add	r7, r31, r7
    add	r8, r0, r9
    add	r3, r3, r9
    mtctr	r6
    cmpw	r4, r5
    bge     _80046294
_800461bc:
    lhz	r0, 0(r7)
    sth	r0, 0(r8)
    addi	r8, r8, 2
    lhz	r0, 2(r7)
    addi	r7, r7, 4
    sth	r0, 0(r3)
    addi	r3, r3, 2
    bdnz    _800461bc
    b       _80046294
_800461e0:
    cmpwi	r5, 0
    li	r8, 0
    ble     _80046294
    cmpwi	r5, 8
    addi	r4, r5, -8
    ble     _80046264
    addi	r3, r4, 7
    mr	r6, r31
    srwi	r3, r3, 3
    mr	r7, r0
    mtctr	r3
    cmpwi	r4, 0
    ble     _80046264
_80046214:
    lhz	r3, 0(r6)
    addi	r8, r8, 8
    sth	r3, 0(r7)
    lhz	r3, 2(r6)
    sth	r3, 2(r7)
    lhz	r3, 4(r6)
    sth	r3, 4(r7)
    lhz	r3, 6(r6)
    sth	r3, 6(r7)
    lhz	r3, 8(r6)
    sth	r3, 8(r7)
    lhz	r3, 0xa(r6)
    sth	r3, 0xa(r7)
    lhz	r3, 0xc(r6)
    sth	r3, 0xc(r7)
    lhz	r3, 0xe(r6)
    addi	r6, r6, 0x10
    sth	r3, 0xe(r7)
    addi	r7, r7, 0x10
    bdnz    _80046214
_80046264:
    slwi	r6, r8, 1
    subf	r3, r8, r5
    add	r4, r31, r6
    add	r6, r0, r6
    mtctr	r3
    cmpw	r8, r5
    bge     _80046294
_80046280:
    lhz	r0, 0(r4)
    addi	r4, r4, 2
    sth	r0, 0(r6)
    addi	r6, r6, 2
    bdnz    _80046280
_80046294:
    stw	r5, 0x90(r30)
    slwi	r3, r5, 1
    li	r0, 2
    lbz	r4, 0xe(r30)
    extsb	r4, r4
    mullw	r3, r4, r3
    stw	r3, 0x94(r30)
    stw	r0, 4(r30)
_800462b4:
    lwz	r0, 4(r30)
    cmpwi	r0, 2
    bne     _800462e0
    lwz	r12, 0x80(r30)
    lwz	r3, 0x84(r30)
    lwz	r4, 0x94(r30)
    lwz	r5, 0x90(r30)
    mtctr	r12
    bctrl	
    li	r0, 3
    stw	r0, 4(r30)
_800462e0:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
