#pragma push
#pragma force_active on

extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void fn_8004A550(void);
extern void ADXT_GetVoiceByAxHandle(void);
extern void ADXT_StartVoice(void);
extern void fn_8004AD84(void);
extern void fn_8004ADF4(void);
extern void fn_8004AE78(void);
extern void fn_8004AE94(void);
extern void ADXTGetState(void);
extern void ADXT_StopVoice(void);
extern void fn_8004B180(void);
extern void gcciErrPrintf(void);
extern void gcci_set_critical_value(void);
extern void gccicrit_leave(void);
extern void gccicrit_enter(void);
extern void fn_8005676C(void);
extern void gcci_register_filename(void);
extern void fn_80057114(void);
extern void svmExitCritical(void);
extern void svmEnterCritical(void);
extern void SVM_ReportError(void);
extern void __msl_strncmp(void);
extern void memcpy(void);
extern void memset(void);
extern unsigned char SJMEM_Error_str[12];
extern unsigned char SJRBF_Error_str[12];
extern unsigned char E0003_lsc_null_str[35];
extern unsigned char lbl_80092238[42];
extern unsigned char lbl_800922C0[4];
extern unsigned char lbl_80092264[41];
extern unsigned char lbl_800922C8[21];
extern unsigned char lbl_800922E0[16];
extern unsigned char lbl_801322D0[48];
extern unsigned char lbl_80132330[448];
extern unsigned char lbl_80188A88[4];
extern unsigned char lbl_80132300[8];
extern unsigned char lbl_80092330[4];
extern unsigned char lbl_8009232C[4];
extern unsigned char lbl_80188A8C[9092];
extern unsigned char lbl_8018AE10[4];
extern unsigned char lbl_8018AE14[4];
extern unsigned char lbl_8018AE18[4];
extern unsigned char lbl_8018AE1C[1156];
extern unsigned char lbl_8018B2A0[4];
extern unsigned char lbl_8018B2A4[16388];
extern unsigned char lbl_8018F2A8[4];
extern unsigned char lbl_8018F2AC[3076];
void fn_80057D60(void);
void fn_800586E4(void);


/* harvest: declarations carried over from the recovered
   candidate — the converted body below needs them. */
typedef struct {
    unsigned char pad0[0x24];
    signed int field24;
} ADXTState;
asm void fn_800570DC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r6, 0x10
    li	r5, 0
    stw	r0, 0x14(r1)
    addi	r7, r6, -1
    li	r6, 0
    bl      gcci_register_filename
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_8005710C(void* p, int val)
{
    *(int*)((char*)p + 0x28) = val;
}

asm void fn_80057114(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    beq     _800571d8
    bne     _80057144
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _800571c0
_80057144:
    lbz	r0, 1(r31)
    extsb.	r0, r0
    beq     _800571c0
    li	r0, 0
    stb	r0, 1(r31)
    lwz	r3, 0x28(r31)
    cmplwi	r3, 0
    beq     _8005717c
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _8005717c
    bl      ADXT_StartVoice
    li	r0, 0
    stb	r0, 2(r31)
_8005717c:
    li	r3, 0
    cmplwi	r31, 0
    stw	r3, 0x2c(r31)
    bne     _800571a0
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _800571b8
_800571a0:
    lbz	r0, 1(r31)
    extsb.	r0, r0
    bne     _800571b8
    stw	r3, 0x1c(r31)
    stw	r3, 0x20(r31)
    stw	r3, 0x24(r31)
_800571b8:
    li	r0, 0
    stw	r0, 0x34(r31)
_800571c0:
    li	r0, 0
    mr	r3, r31
    stb	r0, 0(r31)
    li	r4, 0
    li	r5, 0x238
    bl      memset
_800571d8:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800571EC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    or.	r29, r3, r3
    bne     _80057224
    lis     r3, lbl_80092238@ha
    addi	r3, r3, lbl_80092238@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    li	r3, 0
    b     _8005735c
_80057224:
    addi	r3, r1, 8
    bl      gccicrit_enter
    lis     r3, lbl_80188A8C@ha
    li	r31, 0
    addi	r4, r3, lbl_80188A8C@l
    li	r0, 0x10
    mr	r3, r31
    mtctr	r0
_80057244:
    lbz	r0, 0(r4)
    extsb.	r0, r0
    bne     _80057264
    mulli	r4, r3, 0x238
    lis     r3, lbl_80188A8C@ha
    addi	r0, r3, lbl_80188A8C@l
    add	r31, r0, r4
    b     _80057270
_80057264:
    addi	r4, r4, 0x238
    addi	r3, r3, 1
    bdnz     _80057244
_80057270:
    cmplwi	r31, 0
    bne     _8005728c
    lis     r3, lbl_80092264@ha
    addi	r3, r3, lbl_80092264@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _80057350
_8005728c:
    stw	r29, 8(r31)
    li	r0, 0
    mr	r3, r29
    li	r4, 1
    stb	r0, 1(r31)
    lwz	r5, 0(r29)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    lwz	r5, 0(r29)
    mr	r30, r3
    mr	r3, r29
    li	r4, 0
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    add	r0, r3, r30
    lis	r3, 0x6666
    stw	r0, 0x18(r31)
    li	r4, 0
    addi	r3, r3, 0x6667
    lwz	r0, 0x18(r31)
    cmpwi	r4, 0x10
    slwi	r0, r0, 3
    mulhw	r0, r3, r0
    srawi	r0, r0, 2
    srwi	r3, r0, 0x1f
    add	r0, r0, r3
    stw	r0, 0x14(r31)
    bge     _80057348
    li	r0, 0
    stw	r0, 0x50(r31)
    stw	r0, 0x70(r31)
    stw	r0, 0x90(r31)
    stw	r0, 0xb0(r31)
    stw	r0, 0xd0(r31)
    stw	r0, 0xf0(r31)
    stw	r0, 0x110(r31)
    stw	r0, 0x130(r31)
    stw	r0, 0x150(r31)
    stw	r0, 0x170(r31)
    stw	r0, 0x190(r31)
    stw	r0, 0x1b0(r31)
    stw	r0, 0x1d0(r31)
    stw	r0, 0x1f0(r31)
    stw	r0, 0x210(r31)
    stw	r0, 0x230(r31)
_80057348:
    li	r0, 1
    stb	r0, 0(r31)
_80057350:
    addi	r3, r1, 8
    bl      gccicrit_leave
    mr	r3, r31
_8005735c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80057378(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r3, r1, 8
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    bl      gccicrit_enter
    lis     r3, lbl_80188A88@ha
    addi	r4, r3, lbl_80188A88@l
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _800573fc
    lis     r3, lbl_80188A8C@ha
    li	r30, 0
    addi	r31, r3, lbl_80188A8C@l
_800573b8:
    lbz	r0, 0(r31)
    cmpwi	r0, 1
    bne     _800573cc
    mr	r3, r31
    bl      fn_80057114
_800573cc:
    addi	r30, r30, 1
    addi	r31, r31, 0x238
    cmpwi	r30, 0x10
    blt     _800573b8
    lis     r3, lbl_80188A8C@ha
    li	r4, 0
    addi	r3, r3, lbl_80188A8C@l
    li	r5, 0x2380
    bl      memset
    li	r3, 0
    li	r4, 0
    bl      gcci_set_critical_value
_800573fc:
    addi	r3, r1, 8
    bl      gccicrit_leave
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005741C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r4, lbl_800922C0@ha
    stw	r0, 0x14(r1)
    addi	r3, r1, 8
    lwz	r0, lbl_800922C0@l(r4)
    bl      gccicrit_enter
    lis     r3, lbl_80188A88@ha
    lwz	r0, lbl_80188A88@l(r3)
    cmpwi	r0, 0
    bne     _80057468
    lis	r3, lbl_80188A8C@ha
    li	r4, 0
    addi	r3, r3, lbl_80188A8C@l
    li	r5, 0x2380
    bl      memset
    li	r3, 0
    li	r4, 0
    bl      gcci_set_critical_value
_80057468:
    lis     r4, lbl_80188A88@ha
    addi	r3, r1, 8
    addi	r5, r4, lbl_80188A88@l
    lwz	r4, 0(r5)
    addi	r0, r4, 1
    stw	r0, 0(r5)
    bl      gccicrit_leave
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80057494(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r27, r3
    lbz	r0, 4(r3)
    cmpwi	r0, 1
    beq     _800576c8
    lbz	r0, 1(r27)
    cmpwi	r0, 2
    bne     _800576c8
    lwz	r0, 0x24(r27)
    cmpwi	r0, 0
    ble     _800576c8
    lwz	r0, 0x20(r27)
    slwi	r4, r0, 5
    add	r3, r27, r4
    lwz	r0, 0x50(r3)
    cmpwi	r0, 1
    bne     _80057554
    lwz	r3, 0x28(r27)
    cmplwi	r3, 0
    bne     _80057504
    lis     r3, lbl_800922C8@ha
    addi	r3, r3, lbl_800922C8@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _80057554
_80057504:
    addi	r28, r4, 0x38
    add	r28, r27, r28
    bl      ADXTGetState
    cmpwi	r3, 4
    bne     _80057524
    li	r0, 3
    stb	r0, 1(r27)
    b     _80057554
_80057524:
    cmpwi	r3, 2
    bne     _8005753c
    lwz	r3, 0x28(r27)
    bl      fn_8004AE78
    stw	r3, 0x1c(r28)
    b     _80057554
_8005753c:
    cmpwi	r3, 3
    bne     _80057554
    lwz	r3, 0x2c(r27)
    li	r0, 2
    stw	r3, 0x1c(r28)
    stw	r0, 0x18(r28)
_80057554:
    lwz	r0, 0x20(r27)
    slwi	r4, r0, 5
    add	r3, r27, r4
    lwz	r0, 0x50(r3)
    cmpwi	r0, 2
    bne     _80057614
    lwz	r0, 0x28(r27)
    li	r28, 0
    mr	r29, r28
    cmplwi	r0, 0
    mr	r30, r28
    mr	r31, r28
    beq     _80057614
    lbz	r0, 3(r27)
    cmpwi	r0, 1
    bne     _800575ac
    addi	r3, r4, 0x38
    add	r3, r27, r3
    lwz	r28, 4(r3)
    lwz	r29, 0xc(r3)
    lwz	r30, 0x10(r3)
    lwz	r31, 0x14(r3)
_800575ac:
    lwz	r3, 0x24(r27)
    addi	r0, r3, -1
    stw	r0, 0x24(r27)
    lwz	r3, 0x20(r27)
    addi	r3, r3, 1
    slwi	r0, r3, 0x1c
    srwi	r3, r3, 0x1f
    subf	r0, r3, r0
    rotlwi	r0, r0, 4
    add	r0, r0, r3
    stw	r0, 0x20(r27)
    lwz	r0, 0x24(r27)
    cmpwi	r0, 0
    bgt     _800575f0
    bl      fn_8005676C
    li	r0, 1
    stb	r0, 1(r27)
_800575f0:
    lbz	r0, 3(r27)
    cmpwi	r0, 1
    bne     _80057614
    mr	r3, r27
    mr	r4, r28
    mr	r5, r29
    mr	r6, r30
    mr	r7, r31
    bl      gcci_register_filename
_80057614:
    lwz	r0, 0x20(r27)
    slwi	r4, r0, 5
    add	r3, r27, r4
    lwz	r0, 0x50(r3)
    cmpwi	r0, 0
    bne     _800576c8
    lwz	r0, 0x24(r27)
    addi	r28, r4, 0x38
    add	r28, r27, r28
    cmpwi	r0, 0
    ble     _800576c8
    lwz	r3, 0x28(r27)
    bl      fn_8004AD84
    lwz	r3, 0x28(r27)
    bl      ADXT_StopVoice
    lwz	r3, 0x28(r27)
    lwz	r4, 4(r28)
    lwz	r5, 0xc(r28)
    lwz	r6, 0x10(r28)
    lwz	r7, 0x14(r28)
    bl      fn_8004B180
    lwz	r3, 0x28(r27)
    lwz	r4, 0x14(r28)
    bl      ADXT_GetVoiceByAxHandle
    lwz	r3, 0x14(r28)
    li	r0, 0
    stw	r3, 0x2c(r27)
    stw	r0, 0x1c(r28)
    stb	r0, 2(r27)
    lbz	r0, 2(r27)
    extsb.	r0, r0
    bne     _800576c0
    lwz	r3, 0x28(r27)
    lwz	r4, 0x14(r27)
    lwz	r5, 0x18(r27)
    bl      fn_8004A550
    lwz	r3, 0x28(r27)
    li	r4, 0
    bl      fn_8004AE94
    lwz	r3, 0x28(r27)
    bl      fn_8004ADF4
    li	r0, 1
    stb	r0, 2(r27)
_800576c0:
    li	r0, 1
    stw	r0, 0x18(r28)
_800576c8:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void svmExitCritical(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018AE10@ha
    stw	r0, 0x14(r1)
    addi	r4, r3, lbl_8018AE10@l
    lwz	r3, 0(r4)
    addi	r0, r3, -1
    stw	r0, 0(r4)
    lwz	r0, 0(r4)
    cmpwi	r0, 0
    bne     _80057718
    lis     r3, lbl_8018AE14@ha
    addi	r3, r3, lbl_8018AE14@l
    lwz	r3, 0(r3)
    bl      OSRestoreInterrupts
_80057718:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void svmEnterCritical(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, lbl_8018AE10@ha
    stw	r0, 0x14(r1)
    lwz	r0, lbl_8018AE10@l(r3)
    cmpwi	r0, 0
    bne     _80057750
    bl      OSDisableInterrupts
    lis	r4, lbl_8018AE14@ha
    stw	r3, lbl_8018AE14@l(r4)
_80057750:
    lis     r3, lbl_8018AE10@ha
    addi	r4, r3, lbl_8018AE10@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80057774(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r4
    stw	r30, 0x18(r1)
    mr	r30, r6
    stw	r29, 0x14(r1)
    mr	r29, r5
    stw	r28, 0x10(r1)
    mr	r28, r3
    bl      svmEnterCritical
    cmpwi	r31, 0
    bne     _800577b4
    li	r31, 0
    b     _800577f8
_800577b4:
    cmpwi	r31, 1
    bne     _800577d8
    lwz	r3, 0xc(r28)
    mr	r0, r29
    cmpw	r3, r29
    bge     _800577d0
    mr	r0, r3
_800577d0:
    mr	r31, r0
    b     _800577f8
_800577d8:
    lwz	r12, 0x1c(r28)
    li	r31, 0
    cmplwi	r12, 0
    beq     _800577f8
    lwz	r3, 0x20(r28)
    li	r4, -3
    mtctr	r12
    bctrl	
_800577f8:
    stw	r31, 0(r30)
    bl      svmExitCritical
    subf	r0, r31, r29
    lwz	r31, 0x1c(r1)
    cntlzw	r0, r0
    lwz	r30, 0x18(r1)
    srwi	r3, r0, 5
    lwz	r0, 0x24(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005782C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    mr	r29, r4
    lwz	r0, 4(r5)
    cmpwi	r0, 0
    ble     _80057940
    lwz	r0, 0(r30)
    cmplwi	r0, 0
    bne     _8005786c
    b     _80057940
_8005786c:
    bl      svmEnterCritical
    cmpwi	r29, 0
    bne     _80057898
    lwz	r12, 0x1c(r31)
    cmplwi	r12, 0
    beq     _8005793c
    lwz	r3, 0x20(r31)
    li	r4, -3
    mtctr	r12
    bctrl	
    b     _8005793c
_80057898:
    cmpwi	r29, 1
    bne     _80057914
    lwz	r0, 4(r30)
    lwz	r3, 0x10(r31)
    subf	r3, r0, r3
    neg	r0, r3
    andc	r0, r0, r3
    srawi	r0, r0, 0x1f
    and	r4, r3, r0
    stw	r4, 0x10(r31)
    lwz	r3, 0xc(r31)
    lwz	r0, 4(r30)
    lwz	r5, 0x18(r31)
    add	r0, r3, r0
    cmpw	r5, r0
    bge     _800578dc
    mr	r0, r5
_800578dc:
    stw	r0, 0xc(r31)
    lwz	r3, 0x14(r31)
    lwz	r0, 0(r30)
    subf	r0, r3, r0
    cmpw	r4, r0
    beq     _8005793c
    lwz	r12, 0x1c(r31)
    cmplwi	r12, 0
    beq     _8005793c
    lwz	r3, 0x20(r31)
    li	r4, -3
    mtctr	r12
    bctrl	
    b     _8005793c
_80057914:
    li	r0, 0
    stw	r0, 4(r30)
    stw	r0, 0(r30)
    lwz	r12, 0x1c(r31)
    cmplwi	r12, 0
    beq     _8005793c
    lwz	r3, 0x20(r31)
    li	r4, -3
    mtctr	r12
    bctrl	
_8005793c:
    bl      svmExitCritical
_80057940:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005795C(void)
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
    lwz	r0, 4(r5)
    cmpwi	r0, 0
    ble     _800579d4
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bne     _8005799c
    b     _800579d4
_8005799c:
    bl      svmEnterCritical
    cmplwi	r30, 1
    ble     _800579d0
    li	r0, 0
    stw	r0, 4(r31)
    stw	r0, 0(r31)
    lwz	r12, 0x1c(r29)
    cmplwi	r12, 0
    beq     _800579d0
    lwz	r3, 0x20(r29)
    li	r4, -3
    mtctr	r12
    bctrl	
_800579d0:
    bl      svmExitCritical
_800579d4:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800579F0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r6
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    mr	r29, r4
    stw	r28, 0x10(r1)
    mr	r28, r3
    bl      svmEnterCritical
    cmpwi	r29, 0
    bne     _80057a38
    li	r0, 0
    stw	r0, 4(r31)
    stw	r0, 0(r31)
    b     _80057ab4
_80057a38:
    cmpwi	r29, 1
    bne     _80057a8c
    lwz	r3, 0xc(r28)
    mr	r0, r30
    cmpw	r3, r30
    bge     _80057a54
    mr	r0, r3
_80057a54:
    stw	r0, 4(r31)
    lwz	r3, 0x14(r28)
    lwz	r0, 0x10(r28)
    add	r0, r3, r0
    stw	r0, 0(r31)
    lwz	r3, 0x10(r28)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0x10(r28)
    lwz	r3, 4(r31)
    lwz	r0, 0xc(r28)
    subf	r0, r3, r0
    stw	r0, 0xc(r28)
    b     _80057ab4
_80057a8c:
    li	r0, 0
    stw	r0, 4(r31)
    stw	r0, 0(r31)
    lwz	r12, 0x1c(r28)
    cmplwi	r12, 0
    beq     _80057ab4
    lwz	r3, 0x20(r28)
    li	r4, -3
    mtctr	r12
    bctrl	
_80057ab4:
    bl      svmExitCritical
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80057AD8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r4, 1
    stw	r0, 0x14(r1)
    bne     _80057af4
    lwz	r3, 0xc(r3)
    b     _80057b24
_80057af4:
    cmpwi	r4, 0
    bne     _80057b04
    li	r3, 0
    b     _80057b24
_80057b04:
    lwz	r12, 0x1c(r3)
    cmplwi	r12, 0
    beq     _80057b20
    lwz	r3, 0x20(r3)
    li	r4, -3
    mtctr	r12
    bctrl	
_80057b20:
    li	r3, 0
_80057b24:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_80057B34(void* p)
{
    *(int*)((char*)p + 0xc) = *(int*)((char*)p + 0x18);
    *(int*)((char*)p + 0x10) = 0;
}

// provenance: original
void fn_80057B48(void* p, int a, int b)
{
    *(int*)((char*)p + 0x1c) = a;
    *(int*)((char*)p + 0x20) = b;
}

// provenance: original
int fn_80057B54(void* p)
{
    return *(int*)((char*)p + 8);
}

asm void fn_80057B5C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    beq     _80057b88
    li	r4, 0
    li	r5, 0x24
    bl      memset
    li	r0, 0
    stw	r0, 4(r31)
_80057b88:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80057B9C(void)
{
    nofralloc
    lis     r5, lbl_8018AE1C@ha
    li	r0, 4
    addi	r5, r5, lbl_8018AE1C@l
    li	r6, 0
    mtctr	r0
_80057bb0:
    lwz	r0, 4(r5)
    cmpwi	r0, 0
    beq     _80057c54
    lwz	r0, 0x28(r5)
    addi	r6, r6, 1
    addi	r5, r5, 0x24
    cmpwi	r0, 0
    beq     _80057c54
    lwz	r0, 0x28(r5)
    addi	r6, r6, 1
    addi	r5, r5, 0x24
    cmpwi	r0, 0
    beq     _80057c54
    lwz	r0, 0x28(r5)
    addi	r6, r6, 1
    addi	r5, r5, 0x24
    cmpwi	r0, 0
    beq     _80057c54
    lwz	r0, 0x28(r5)
    addi	r6, r6, 1
    addi	r5, r5, 0x24
    cmpwi	r0, 0
    beq     _80057c54
    lwz	r0, 0x28(r5)
    addi	r6, r6, 1
    addi	r5, r5, 0x24
    cmpwi	r0, 0
    beq     _80057c54
    lwz	r0, 0x28(r5)
    addi	r6, r6, 1
    addi	r5, r5, 0x24
    cmpwi	r0, 0
    beq     _80057c54
    lwz	r0, 0x28(r5)
    addi	r6, r6, 1
    addi	r5, r5, 0x24
    cmpwi	r0, 0
    beq     _80057c54
    addi	r5, r5, 0x24
    addi	r6, r6, 1
    bdnz     _80057bb0
_80057c54:
    cmpwi	r6, 0x20
    bne     _80057c64
    li	r3, 0
    blr	
_80057c64:
    mulli	r7, r6, 0x24
    lis     r6, lbl_8018AE1C@ha
    lis     r5, lbl_801322D0@ha
    addi	r0, r6, lbl_8018AE1C@l
    add	r7, r0, r7
    li	r0, 1
    stw	r0, 4(r7)
    addi	r0, r5, lbl_801322D0@l
    lis     r6, lbl_800922E0@ha
    lis     r5, fn_80057D60@ha
    stw	r0, 0(r7)
    addi	r6, r6, lbl_800922E0@l
    addi	r5, r5, fn_80057D60@l
    li	r0, 0
    stw	r3, 0x14(r7)
    mr	r3, r7
    stw	r4, 0x18(r7)
    stw	r6, 8(r7)
    stw	r5, 0x1c(r7)
    stw	r7, 0x20(r7)
    lwz	r4, 0x18(r7)
    stw	r4, 0xc(r7)
    stw	r0, 0x10(r7)
    blr	
}

asm void fn_80057CC4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018AE18@ha
    stw	r0, 0x14(r1)
    addi	r4, r3, lbl_8018AE18@l
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _80057cfc
    lis     r3, lbl_8018AE1C@ha
    li	r4, 0
    addi	r3, r3, lbl_8018AE1C@l
    li	r5, 0x480
    bl      memset
_80057cfc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80057D0C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, lbl_8018AE18@ha
    stw	r0, 0x14(r1)
    lwz	r0, lbl_8018AE18@l(r3)
    cmpwi	r0, 0
    bne     _80057d3c
    lis     r3, lbl_8018AE1C@ha
    li	r4, 0
    addi	r3, r3, lbl_8018AE1C@l
    li	r5, 0x480
    bl      memset
_80057d3c:
    lis     r3, lbl_8018AE18@ha
    addi	r4, r3, lbl_8018AE18@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80057D60(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, SJMEM_Error_str@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, SJMEM_Error_str@l
    bl      SVM_ReportError
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
int fn_80057D88(void* p, int r4, int r5)
{
    r4 <<= 3;
    r5 <<= 2;
    p = (char*)p + r4;
    p = (char*)p + r5;
    return *(int*)((char*)p + 0x28);
}

// provenance: harvest:runs.sqlite — fn_80057DA0 recovered from hard2-adxt-80057da0.c, compiled by hard2 at 2026-08-27T08:09 and scored 100 against main/game/adxt_800570DC; original reference not recorded
signed int fn_80057DA0(ADXTState* self)
{
    return self->field24;
}

// provenance: original
int fn_80057DA8(void* p)
{
    return *(int*)((char*)p + 0x20);
}

// provenance: original
int fn_80057DB0(void* p)
{
    return *(int*)((char*)p + 0x1c);
}

asm void fn_80057DB8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r6
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    mr	r29, r4
    stw	r28, 0x10(r1)
    mr	r28, r3
    bl      svmEnterCritical
    cmpwi	r29, 0
    bne     _80057e2c
    lwz	r3, 0x14(r28)
    lwz	r0, 0x20(r28)
    lwz	r4, 0x24(r28)
    subf	r0, r3, r0
    lwz	r3, 0x10(r28)
    add	r4, r4, r0
    cmpw	r3, r4
    bge     _80057e14
    mr	r4, r3
_80057e14:
    cmpw	r4, r30
    mr	r0, r30
    bge     _80057e24
    mr	r0, r4
_80057e24:
    mr	r29, r0
    b     _80057e90
_80057e2c:
    cmpwi	r29, 1
    bne     _80057e70
    lwz	r3, 0x18(r28)
    lwz	r0, 0x20(r28)
    lwz	r4, 0x24(r28)
    subf	r0, r3, r0
    lwz	r3, 0xc(r28)
    add	r4, r4, r0
    cmpw	r3, r4
    bge     _80057e58
    mr	r4, r3
_80057e58:
    cmpw	r4, r30
    mr	r0, r30
    bge     _80057e68
    mr	r0, r4
_80057e68:
    mr	r29, r0
    b     _80057e90
_80057e70:
    lwz	r12, 0x38(r28)
    li	r29, 0
    cmplwi	r12, 0
    beq     _80057e90
    lwz	r3, 0x3c(r28)
    li	r4, -3
    mtctr	r12
    bctrl	
_80057e90:
    stw	r29, 0(r31)
    bl      svmExitCritical
    subf	r0, r29, r30
    lwz	r31, 0x1c(r1)
    cntlzw	r0, r0
    lwz	r30, 0x18(r1)
    srwi	r3, r0, 5
    lwz	r0, 0x24(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80057EC4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    mr	r29, r4
    lwz	r0, 4(r5)
    cmpwi	r0, 0
    ble     _80058054
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bne     _80057f04
    b     _80058054
_80057f04:
    bl      svmEnterCritical
    cmpwi	r29, 0
    bne     _80057f98
    lwz	r6, 0x20(r30)
    lwz	r0, 0x14(r30)
    lwz	r5, 4(r31)
    add	r4, r0, r6
    lwz	r3, 0x1c(r30)
    lwz	r0, 0(r31)
    subf	r5, r5, r4
    divw	r4, r5, r6
    subf	r3, r3, r0
    divw	r0, r3, r6
    mullw	r4, r4, r6
    mullw	r0, r0, r6
    subf	r4, r4, r5
    subf	r0, r0, r3
    cmpw	r4, r0
    bne     _80057f68
    stw	r4, 0x14(r30)
    lwz	r3, 0x10(r30)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0x10(r30)
    b     _80057f84
_80057f68:
    lwz	r12, 0x38(r30)
    cmplwi	r12, 0
    beq     _80057f84
    lwz	r3, 0x3c(r30)
    li	r4, -3
    mtctr	r12
    bctrl	
_80057f84:
    lwz	r3, 4(r31)
    lwz	r0, 0x28(r30)
    subf	r0, r3, r0
    stw	r0, 0x28(r30)
    b     _80058050
_80057f98:
    cmpwi	r29, 1
    bne     _80058028
    lwz	r6, 0x20(r30)
    lwz	r0, 0x18(r30)
    lwz	r5, 4(r31)
    add	r4, r0, r6
    lwz	r3, 0x1c(r30)
    lwz	r0, 0(r31)
    subf	r5, r5, r4
    divw	r4, r5, r6
    subf	r3, r3, r0
    divw	r0, r3, r6
    mullw	r4, r4, r6
    mullw	r0, r0, r6
    subf	r4, r4, r5
    subf	r0, r0, r3
    cmpw	r4, r0
    bne     _80057ff8
    stw	r4, 0x18(r30)
    lwz	r3, 0xc(r30)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0xc(r30)
    b     _80058014
_80057ff8:
    lwz	r12, 0x38(r30)
    cmplwi	r12, 0
    beq     _80058014
    lwz	r3, 0x3c(r30)
    li	r4, -3
    mtctr	r12
    bctrl	
_80058014:
    lwz	r3, 4(r31)
    lwz	r0, 0x30(r30)
    subf	r0, r3, r0
    stw	r0, 0x30(r30)
    b     _80058050
_80058028:
    li	r0, 0
    stw	r0, 4(r31)
    stw	r0, 0(r31)
    lwz	r12, 0x38(r30)
    cmplwi	r12, 0
    beq     _80058050
    lwz	r3, 0x3c(r30)
    li	r4, -3
    mtctr	r12
    bctrl	
_80058050:
    bl      svmExitCritical
_80058054:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80058070(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    mr	r29, r4
    lwz	r0, 4(r5)
    cmpwi	r0, 0
    ble     _800581b0
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bne     _800580b0
    b     _800581b0
_800580b0:
    bl      svmEnterCritical
    cmpwi	r29, 1
    bne     _80058158
    lwz	r3, 0xc(r30)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0xc(r30)
    lwz	r6, 0x1c(r30)
    lwz	r4, 0(r31)
    lwz	r0, 0x24(r30)
    subf	r7, r6, r4
    cmpw	r7, r0
    bge     _80058108
    lwz	r3, 4(r31)
    subf	r5, r7, r0
    cmpw	r3, r5
    bge     _800580f8
    mr	r5, r3
_800580f8:
    lwz	r0, 0x20(r30)
    add	r3, r7, r6
    add	r3, r0, r3
    bl      memcpy
_80058108:
    lwz	r3, 0x1c(r30)
    lwz	r0, 0(r31)
    lwz	r6, 4(r31)
    subf	r0, r3, r0
    lwz	r4, 0x20(r30)
    add	r0, r6, r0
    cmpw	r0, r4
    ble     _80058144
    subf	r5, r4, r0
    cmpw	r6, r5
    bge     _80058138
    mr	r5, r6
_80058138:
    subf	r0, r5, r0
    add	r4, r3, r0
    bl      memcpy
_80058144:
    lwz	r3, 0x34(r30)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0x34(r30)
    b     _800581ac
_80058158:
    cmpwi	r29, 0
    bne     _80058184
    lwz	r3, 0x10(r30)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0x10(r30)
    lwz	r3, 0x2c(r30)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0x2c(r30)
    b     _800581ac
_80058184:
    li	r0, 0
    stw	r0, 4(r31)
    stw	r0, 0(r31)
    lwz	r12, 0x38(r30)
    cmplwi	r12, 0
    beq     _800581ac
    lwz	r3, 0x3c(r30)
    li	r4, -3
    mtctr	r12
    bctrl	
_800581ac:
    bl      svmExitCritical
_800581b0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800581CC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r6
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    mr	r29, r3
    stw	r28, 0x10(r1)
    mr	r28, r4
    bl      svmEnterCritical
    cmpwi	r28, 0
    bne     _80058298
    lwz	r3, 0x14(r29)
    lwz	r0, 0x20(r29)
    lwz	r4, 0x24(r29)
    subf	r0, r3, r0
    lwz	r3, 0x10(r29)
    add	r0, r4, r0
    cmpw	r3, r0
    bge     _80058228
    mr	r0, r3
_80058228:
    stw	r0, 4(r31)
    mr	r0, r30
    lwz	r3, 4(r31)
    cmpw	r3, r30
    bge     _80058240
    mr	r0, r3
_80058240:
    stw	r0, 4(r31)
    lwz	r3, 0x1c(r29)
    lwz	r0, 0x14(r29)
    add	r0, r3, r0
    stw	r0, 0(r31)
    lwz	r4, 0x14(r29)
    lwz	r0, 4(r31)
    lwz	r3, 0x20(r29)
    add	r4, r4, r0
    divw	r0, r4, r3
    mullw	r0, r0, r3
    subf	r0, r0, r4
    stw	r0, 0x14(r29)
    lwz	r3, 4(r31)
    lwz	r0, 0x10(r29)
    subf	r0, r3, r0
    stw	r0, 0x10(r29)
    lwz	r3, 0x28(r29)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0x28(r29)
    b     _8005835c
_80058298:
    cmpwi	r28, 1
    bne     _80058334
    lwz	r3, 0x18(r29)
    lwz	r0, 0x20(r29)
    lwz	r4, 0x24(r29)
    subf	r0, r3, r0
    lwz	r3, 0xc(r29)
    add	r0, r4, r0
    cmpw	r3, r0
    bge     _800582c4
    mr	r0, r3
_800582c4:
    stw	r0, 4(r31)
    mr	r0, r30
    lwz	r3, 4(r31)
    cmpw	r3, r30
    bge     _800582dc
    mr	r0, r3
_800582dc:
    stw	r0, 4(r31)
    lwz	r3, 0x1c(r29)
    lwz	r0, 0x18(r29)
    add	r0, r3, r0
    stw	r0, 0(r31)
    lwz	r4, 0x18(r29)
    lwz	r0, 4(r31)
    lwz	r3, 0x20(r29)
    add	r4, r4, r0
    divw	r0, r4, r3
    mullw	r0, r0, r3
    subf	r0, r0, r4
    stw	r0, 0x18(r29)
    lwz	r3, 4(r31)
    lwz	r0, 0xc(r29)
    subf	r0, r3, r0
    stw	r0, 0xc(r29)
    lwz	r3, 0x30(r29)
    lwz	r0, 4(r31)
    add	r0, r3, r0
    stw	r0, 0x30(r29)
    b     _8005835c
_80058334:
    li	r0, 0
    stw	r0, 4(r31)
    stw	r0, 0(r31)
    lwz	r12, 0x38(r29)
    cmplwi	r12, 0
    beq     _8005835c
    lwz	r3, 0x3c(r29)
    li	r4, -3
    mtctr	r12
    bctrl	
_8005835c:
    bl      svmExitCritical
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80058380(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r4, 1
    stw	r0, 0x14(r1)
    bne     _8005839c
    lwz	r3, 0xc(r3)
    b     _800583cc
_8005839c:
    cmpwi	r4, 0
    bne     _800583ac
    lwz	r3, 0x10(r3)
    b     _800583cc
_800583ac:
    lwz	r12, 0x38(r3)
    cmplwi	r12, 0
    beq     _800583c8
    lwz	r3, 0x3c(r3)
    li	r4, -3
    mtctr	r12
    bctrl	
_800583c8:
    li	r3, 0
_800583cc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800583DC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      svmEnterCritical
    li	r3, 0
    stw	r3, 0xc(r31)
    lwz	r0, 0x20(r31)
    stw	r0, 0x10(r31)
    stw	r3, 0x14(r31)
    stw	r3, 0x18(r31)
    stw	r3, 0x28(r31)
    stw	r3, 0x2c(r31)
    stw	r3, 0x30(r31)
    stw	r3, 0x34(r31)
    bl      svmExitCritical
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_80058434(void* p, int a, int b)
{
    *(int*)((char*)p + 0x38) = a;
    *(int*)((char*)p + 0x3c) = b;
}

// provenance: original
int fn_80058440(void* p)
{
    return *(int*)((char*)p + 8);
}

asm void fn_80058448(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      svmEnterCritical
    cmplwi	r31, 0
    beq     _80058480
    mr	r3, r31
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r0, 0
    stw	r0, 4(r31)
_80058480:
    bl      svmExitCritical
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ADXT_ProcessStreamUpdate(void)
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
    stw	r28, 0x10(r1)
    bl      svmEnterCritical
    lis     r3, lbl_8018B2A4@ha
    li	r0, 0x20
    addi	r3, r3, lbl_8018B2A4@l
    li	r4, 0
    mtctr	r0
_800584d8:
    lwz	r0, 4(r3)
    cmpwi	r0, 0
    beq     _8005857c
    lwz	r0, 0x44(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0x40
    cmpwi	r0, 0
    beq     _8005857c
    lwz	r0, 0x44(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0x40
    cmpwi	r0, 0
    beq     _8005857c
    lwz	r0, 0x44(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0x40
    cmpwi	r0, 0
    beq     _8005857c
    lwz	r0, 0x44(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0x40
    cmpwi	r0, 0
    beq     _8005857c
    lwz	r0, 0x44(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0x40
    cmpwi	r0, 0
    beq     _8005857c
    lwz	r0, 0x44(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0x40
    cmpwi	r0, 0
    beq     _8005857c
    lwz	r0, 0x44(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0x40
    cmpwi	r0, 0
    beq     _8005857c
    addi	r3, r3, 0x40
    addi	r4, r4, 1
    bdnz     _800584d8
_8005857c:
    cmpwi	r4, 0x100
    bne     _8005858c
    li	r28, 0
    b     _80058608
_8005858c:
    lis     r3, lbl_8018B2A4@ha
    lis	r5, lbl_80132300@ha
    slwi	r6, r4, 6
    lis	r4, lbl_80092330@ha
    addi	r3, r3, lbl_8018B2A4@l
    li	r0, 1
    add	r28, r3, r6
    lis     r3, fn_800586E4@ha
    stw	r0, 4(r28)
    addi	r5, r5, lbl_80132300@l
    addi	r4, r4, lbl_80092330@l
    addi	r0, r3, fn_800586E4@l
    stw	r5, 0(r28)
    stw	r29, 0x1c(r28)
    stw	r30, 0x20(r28)
    stw	r31, 0x24(r28)
    stw	r4, 8(r28)
    stw	r0, 0x38(r28)
    stw	r28, 0x3c(r28)
    bl      svmEnterCritical
    li	r3, 0
    stw	r3, 0xc(r28)
    lwz	r0, 0x20(r28)
    stw	r0, 0x10(r28)
    stw	r3, 0x14(r28)
    stw	r3, 0x18(r28)
    stw	r3, 0x28(r28)
    stw	r3, 0x2c(r28)
    stw	r3, 0x30(r28)
    stw	r3, 0x34(r28)
    bl      svmExitCritical
_80058608:
    bl      svmExitCritical
    lwz	r0, 0x24(r1)
    mr	r3, r28
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80058630(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      svmEnterCritical
    lis     r3, lbl_8018B2A0@ha
    addi	r4, r3, lbl_8018B2A0@l
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _8005866c
    lis     r3, lbl_8018B2A4@ha
    li	r4, 0
    addi	r3, r3, lbl_8018B2A4@l
    li	r5, 0x4000
    bl      memset
_8005866c:
    bl      svmExitCritical
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80058680(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, lbl_8009232C@ha
    stw	r0, 0x14(r1)
    lwz	r0, lbl_8009232C@l(r3)
    bl      svmEnterCritical
    lis     r3, lbl_8018B2A0@ha
    lwz	r0, lbl_8018B2A0@l(r3)
    cmpwi	r0, 0
    bne     _800586bc
    lis	r3, lbl_8018B2A4@ha
    li	r4, 0
    addi	r3, r3, lbl_8018B2A4@l
    li	r5, 0x4000
    bl      memset
_800586bc:
    lis     r3, lbl_8018B2A0@ha
    addi	r4, r3, lbl_8018B2A0@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    bl      svmExitCritical
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800586E4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, SJRBF_Error_str@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, SJRBF_Error_str@l
    bl      SVM_ReportError
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005870C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018F2A8@ha
    stw	r0, 0x14(r1)
    addi	r4, r3, lbl_8018F2A8@l
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _80058744
    lis     r3, lbl_8018F2AC@ha
    li	r4, 0
    addi	r3, r3, lbl_8018F2AC@l
    li	r5, 0xc00
    bl      memset
_80058744:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80058754(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, lbl_8018F2A8@ha
    stw	r0, 0x14(r1)
    lwz	r0, lbl_8018F2A8@l(r3)
    cmpwi	r0, 0
    bne     _80058784
    lis     r3, lbl_8018F2AC@ha
    li	r4, 0
    addi	r3, r3, lbl_8018F2AC@l
    li	r5, 0xc00
    bl      memset
_80058784:
    lis     r3, lbl_8018F2A8@ha
    addi	r4, r3, lbl_8018F2A8@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800587A8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    li	r0, 0
    stmw	r26, 8(r1)
    mr	r28, r6
    mr	r26, r4
    mr	r27, r5
    stw	r0, 0(r6)
    lis     r6, lbl_80132330@ha
    addi	r31, r6, lbl_80132330@l
    stw	r0, 4(r28)
    lwz	r4, 0(r3)
    lwz	r0, 4(r3)
    mr	r30, r4
    add	r29, r4, r0
    b     _8005898c
_800587ec:
    mr	r3, r30
    mr	r4, r26
    li	r5, 7
    bl      __msl_strncmp
    cmpwi	r3, 0
    bne     _800588bc
    addi	r0, r30, 0x10
    lis     r3, lbl_80132330@ha
    stw	r0, 0(r28)
    addi	r3, r3, lbl_80132330@l
    lbz	r0, 8(r30)
    lbz	r4, 9(r30)
    extsb	r5, r0
    lbz	r0, 0xa(r30)
    slwi	r6, r5, 2
    extsb	r4, r4
    slwi	r5, r4, 2
    lwzx	r6, r3, r6
    extsb	r4, r0
    lbz	r0, 0xb(r30)
    slwi	r7, r4, 2
    lwzx	r4, r3, r5
    slwi	r5, r6, 4
    extsb	r0, r0
    add	r8, r5, r4
    lbz	r4, 0xc(r30)
    slwi	r6, r0, 2
    lbz	r0, 0xd(r30)
    extsb	r5, r4
    lwzx	r7, r3, r7
    slwi	r8, r8, 4
    extsb	r4, r0
    add	r7, r8, r7
    slwi	r5, r5, 2
    lbz	r0, 0xe(r30)
    slwi	r4, r4, 2
    lwzx	r6, r3, r6
    slwi	r7, r7, 4
    extsb	r0, r0
    lwzx	r5, r3, r5
    add	r6, r7, r6
    lwzx	r4, r3, r4
    slwi	r6, r6, 4
    slwi	r0, r0, 2
    add	r5, r6, r5
    lwzx	r0, r3, r0
    slwi	r3, r5, 4
    add	r3, r3, r4
    slwi	r3, r3, 4
    add	r0, r3, r0
    stw	r0, 4(r28)
    b     _80058994
_800588bc:
    cmplwi	r27, 0
    beq     _800588e4
    mr	r3, r30
    mr	r4, r27
    li	r5, 7
    bl      __msl_strncmp
    cmpwi	r3, 0
    bne     _800588e4
    li	r3, 0
    b     _800589a8
_800588e4:
    lbz	r0, 8(r30)
    lbz	r3, 9(r30)
    extsb	r4, r0
    lbz	r0, 0xa(r30)
    slwi	r5, r4, 2
    extsb	r3, r3
    slwi	r4, r3, 2
    lwzx	r5, r31, r5
    extsb	r3, r0
    lbz	r0, 0xb(r30)
    slwi	r6, r3, 2
    lwzx	r3, r31, r4
    slwi	r4, r5, 4
    extsb	r0, r0
    add	r7, r4, r3
    lbz	r3, 0xc(r30)
    slwi	r5, r0, 2
    lbz	r0, 0xd(r30)
    extsb	r4, r3
    lwzx	r6, r31, r6
    slwi	r7, r7, 4
    extsb	r3, r0
    add	r6, r7, r6
    slwi	r4, r4, 2
    lbz	r0, 0xe(r30)
    slwi	r3, r3, 2
    lwzx	r5, r31, r5
    slwi	r6, r6, 4
    extsb	r0, r0
    lwzx	r4, r31, r4
    add	r5, r6, r5
    lwzx	r3, r31, r3
    slwi	r5, r5, 4
    slwi	r0, r0, 2
    add	r4, r5, r4
    lwzx	r0, r31, r0
    slwi	r4, r4, 4
    add	r3, r4, r3
    slwi	r3, r3, 4
    add	r0, r3, r0
    add	r30, r0, r30
    addi	r30, r30, 0x10
_8005898c:
    cmplw	r30, r29
    blt     _800587ec
_80058994:
    cmplw	r30, r29
    bge     _800589a4
    mr	r3, r30
    b     _800589a8
_800589a4:
    li	r3, 0
_800589a8:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
