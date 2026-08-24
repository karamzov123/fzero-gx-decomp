#pragma push
#pragma force_active on

extern void __cvt_fp2unsigned(void);
extern void criadx_get_stream_ptr_wrapper(void);
extern void fn_8004163C(void);
extern void criadxGetValue(void);
extern void fn_800416F8(void);
extern void fn_800420F4(void);
extern void fn_8004212C(void);
extern void fn_80042198(void);
extern void fn_800421CC(void);
extern void fn_80046510(void);
extern void fn_8004651C(void);
extern void fn_800466D4(void);
extern void svmUnlockServer_wrapper(void);
extern void svmLockServer_wrapper(void);
extern void criErr_CallErrCallback(void);
extern void fn_8004A550(void);
extern void ADXT_GetVoiceByAxHandle(void);
extern void fn_8004AC4C(void);
extern void fn_8004AD84(void);
extern void fn_8004ADF4(void);
extern void fn_8004AE94(void);
extern void ADXT_StopVoice(void);
extern void fn_8004B180(void);
extern void fn_8004B1DC(void);
extern void fn_8004EE84(void);
extern void ADXTServerStateRequest_wrapper(void);
extern void ADXT_GetResourceManager(void);
extern void fn_8004EEE4(void);
extern void fn_80056CD0(void);
extern void fn_80057114(void);
extern void memset(void);
extern unsigned char E02080805_ADXT_Destroy_parameter_error_str[40];
extern unsigned char E02080812_ADXT_StartSj_parameter_error_str[40];
extern unsigned char E02080813_ADXT_Stop_parameter_error_str[37];
extern unsigned char E02080814_ADXT_GetStat_parameter_error_str[40];
extern unsigned char lbl_8017E568[4];

asm void fn_8004C164(void)
{
    nofralloc
_8004c164:
    stwu	r1, -0x50(r1)
    mflr	r0
    lis	r6, -0x7ff7
    stw	r0, 0x54(r1)
    stmw	r25, 0x34(r1)
    or.	r27, r3, r3
    lis     r3, lbl_8017E568@ha
    mr	r28, r4
    mr	r29, r5
    addi	r30, r6, 0x9c0
    addi	r31, r3, lbl_8017E568@l
    beq     _8004c1a4
    cmplwi	r28, 0
    beq     _8004c1a4
    cmplwi	r29, 0
    bne     _8004c1b0
_8004c1a4:
    addi	r3, r30, 0x5d0
    bl      criErr_CallErrCallback
    b       _8004c644
_8004c1b0:
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _8004c2cc
    lbz	r0, 1(r27)
    extsb	r0, r0
    cmpwi	r0, 3
    beq     _8004c1d4
    cmpwi	r0, 4
    bne     _8004c258
_8004c1d4:
    lwz	r3, 4(r27)
    bl      criadxGetValue
    stw	r3, 0(r29)
    lwz	r3, 4(r27)
    bl      fn_800416F8
    cmplwi	r27, 0
    mr	r26, r3
    bne     _8004c204
    addi	r3, r30, 0x320
    bl      criErr_CallErrCallback
    li	r29, -1
    b       _8004c238
_8004c204:
    lwz	r3, 0x18(r27)
    cmplwi	r3, 0
    beq     _8004c234
    lwz	r5, 0(r3)
    li	r4, 1
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    srwi	r0, r3, 0x1f
    add	r0, r0, r3
    srawi	r29, r0, 1
    b       _8004c238
_8004c234:
    li	r29, 0
_8004c238:
    lwz	r3, 0xc(r27)
    bl      fn_8004EE84
    add	r3, r3, r29
    lwz	r0, 0xa4(r27)
    subf	r3, r3, r26
    add	r0, r0, r3
    stw	r0, 0(r28)
    b       _8004c2b8
_8004c258:
    cmpwi	r0, 5
    bne     _8004c2a8
    lwz	r3, 4(r27)
    bl      criadx_get_stream_ptr_wrapper
    stw	r3, 0(r28)
    lwz	r3, 4(r27)
    bl      criadxGetValue
    stw	r3, 0(r29)
    lwz	r3, 4(r27)
    bl      fn_8004163C
    li	r4, 0x10
    lwz	r0, 0(r28)
    divw	r3, r4, r3
    mullw	r0, r0, r3
    stw	r0, 0(r28)
    lwz	r3, 0(r28)
    lwz	r0, 0xa4(r27)
    add	r0, r3, r0
    stw	r0, 0(r28)
    b       _8004c2b8
_8004c2a8:
    li	r3, 0
    li	r0, 1
    stw	r3, 0(r28)
    stw	r0, 0(r29)
_8004c2b8:
    lwz	r3, 0(r28)
    lwz	r0, 0x88(r27)
    add	r0, r3, r0
    stw	r0, 0(r28)
    b       _8004c644
_8004c2cc:
    lfs	f0, 0x264(r30)
    stfs	f0, 0x28(r31)
    lbz	r0, 1(r27)
    extsb	r0, r0
    cmpwi	r0, 3
    beq     _8004c2ec
    cmpwi	r0, 4
    bne     _8004c56c
_8004c2ec:
    lbz	r0, 0x72(r27)
    extsb.	r0, r0
    bne     _8004c31c
    lis	r3, -0x7fe8
    lwz	r4, 0xa0(r27)
    lwz	r0, -0x7348(r3)
    lwz	r5, 0x9c(r27)
    subf	r0, r4, r0
    mulli	r0, r0, 0x64
    add	r0, r5, r0
    stw	r0, 0(r28)
    b       _8004c324
_8004c31c:
    lwz	r0, 0x9c(r27)
    stw	r0, 0(r28)
_8004c324:
    lbz	r0, 1(r27)
    extsb	r0, r0
    cmpwi	r0, 3
    beq     _8004c33c
    cmpwi	r0, 4
    bne     _8004c3c0
_8004c33c:
    lwz	r3, 4(r27)
    bl      criadxGetValue
    stw	r3, 8(r1)
    lwz	r3, 4(r27)
    bl      fn_800416F8
    cmplwi	r27, 0
    mr	r26, r3
    bne     _8004c36c
    addi	r3, r30, 0x320
    bl      criErr_CallErrCallback
    li	r25, -1
    b       _8004c3a0
_8004c36c:
    lwz	r3, 0x18(r27)
    cmplwi	r3, 0
    beq     _8004c39c
    lwz	r5, 0(r3)
    li	r4, 1
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    srwi	r0, r3, 0x1f
    add	r0, r0, r3
    srawi	r25, r0, 1
    b       _8004c3a0
_8004c39c:
    li	r25, 0
_8004c3a0:
    lwz	r3, 0xc(r27)
    bl      fn_8004EE84
    add	r3, r3, r25
    lwz	r0, 0xa4(r27)
    subf	r3, r3, r26
    add	r0, r0, r3
    stw	r0, 0xc(r1)
    b       _8004c41c
_8004c3c0:
    cmpwi	r0, 5
    bne     _8004c40c
    lwz	r3, 4(r27)
    bl      criadx_get_stream_ptr_wrapper
    stw	r3, 0xc(r1)
    lwz	r3, 4(r27)
    bl      criadxGetValue
    stw	r3, 8(r1)
    lwz	r3, 4(r27)
    bl      fn_8004163C
    li	r4, 0x10
    lwz	r0, 0xc(r1)
    divw	r3, r4, r3
    mullw	r3, r0, r3
    stw	r3, 0xc(r1)
    lwz	r0, 0xa4(r27)
    add	r0, r3, r0
    stw	r0, 0xc(r1)
    b       _8004c41c
_8004c40c:
    li	r3, 0
    li	r0, 1
    stw	r3, 0xc(r1)
    stw	r0, 8(r1)
_8004c41c:
    lwz	r4, 0xc(r1)
    lis	r5, 0x4330
    lwz	r0, 0x88(r27)
    lwz	r3, 8(r1)
    add	r4, r4, r0
    lwz	r0, 0x2c(r31)
    stw	r4, 0xc(r1)
    xoris	r6, r4, 0x8000
    xoris	r4, r3, 0x8000
    xoris	r0, r0, 0x8000
    lwz	r3, 0(r28)
    stw	r6, 0x14(r1)
    xoris	r3, r3, 0x8000
    lfd	f4, 0x60(r30)
    stw	r5, 0x10(r1)
    lfs	f5, 0x5f8(r30)
    lfd	f0, 0x10(r1)
    stw	r4, 0x1c(r1)
    fsubs	f3, f0, f4
    lfs	f0, 0x5fc(r30)
    stw	r5, 0x18(r1)
    lfd	f1, 0x18(r1)
    stw	r3, 0x24(r1)
    fsubs	f1, f1, f4
    stw	r5, 0x20(r1)
    lfd	f2, 0x20(r1)
    fdivs	f3, f3, f1
    stw	r0, 0x2c(r1)
    stw	r5, 0x28(r1)
    lfd	f1, 0x28(r1)
    fsubs	f2, f2, f4
    fsubs	f1, f1, f4
    fdivs	f1, f2, f1
    fsubs	f1, f3, f1
    fmuls	f1, f5, f1
    fcmpo	cr0, f1, f0
    stfs	f1, 0x28(r31)
    bgt     _8004c4c0
    lfs	f0, 0x600(r30)
    fcmpo	cr0, f1, f0
    bge     _8004c62c
_8004c4c0:
    lis	r3, -0x7fed
    lwz	r0, -0x46f0(r3)
    cmplwi	r0, 1
    bne     _8004c4fc
    lwz	r25, 0(r31)
    li	r0, 0
    mr	r3, r27
    addi	r4, r1, 0xc
    stw	r0, 0(r31)
    addi	r5, r1, 8
    bl      fn_8004C164
    lwz	r3, 8(r31)
    stw	r25, 0(r31)
    addi	r0, r3, 1
    stw	r0, 8(r31)
_8004c4fc:
    lwz	r3, 0xc(r1)
    lis	r4, 0x4330
    lwz	r0, 8(r1)
    xoris	r3, r3, 0x8000
    lwz	r5, 0x2c(r31)
    xoris	r0, r0, 0x8000
    stw	r3, 0x24(r1)
    xoris	r3, r5, 0x8000
    lfd	f2, 0x60(r30)
    stw	r4, 0x20(r1)
    lfd	f0, 0x20(r1)
    stw	r0, 0x1c(r1)
    fsubs	f1, f0, f2
    stw	r4, 0x18(r1)
    lfd	f0, 0x18(r1)
    stw	r3, 0x2c(r1)
    fsubs	f0, f0, f2
    stw	r4, 0x28(r1)
    fdivs	f0, f1, f0
    lfd	f1, 0x28(r1)
    fsubs	f1, f1, f2
    fmuls	f1, f1, f0
    bl      __cvt_fp2unsigned
    stw	r3, 0x9c(r27)
    lis	r4, -0x7fe8
    lwz	r0, -0x7348(r4)
    stw	r0, 0xa0(r27)
    b       _8004c62c
_8004c56c:
    cmpwi	r0, 5
    bne     _8004c624
    lwz	r3, 4(r27)
    bl      criadx_get_stream_ptr_wrapper
    stw	r3, 0xc(r1)
    lwz	r3, 4(r27)
    bl      criadxGetValue
    stw	r3, 8(r1)
    lwz	r3, 4(r27)
    bl      fn_8004163C
    li	r0, 0x10
    lis	r4, 0x4330
    divw	r6, r0, r3
    lwz	r5, 0xc(r1)
    lwz	r0, 8(r1)
    lwz	r3, 0x2c(r31)
    xoris	r0, r0, 0x8000
    stw	r4, 0x20(r1)
    mullw	r5, r5, r6
    xoris	r3, r3, 0x8000
    stw	r0, 0x1c(r1)
    lfd	f2, 0x60(r30)
    stw	r4, 0x18(r1)
    xoris	r0, r5, 0x8000
    stw	r0, 0x24(r1)
    lfd	f0, 0x18(r1)
    lfd	f1, 0x20(r1)
    fsubs	f0, f0, f2
    stw	r3, 0x2c(r1)
    fsubs	f1, f1, f2
    stw	r4, 0x28(r1)
    fdivs	f0, f1, f0
    lfd	f1, 0x28(r1)
    stw	r5, 0xc(r1)
    fsubs	f1, f1, f2
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    stw	r0, 0(r28)
    lwz	r3, 0(r28)
    lwz	r0, 0x9c(r27)
    add	r3, r0, r3
    addi	r0, r3, 1
    stw	r0, 0(r28)
    b       _8004c62c
_8004c624:
    li	r0, 0
    stw	r0, 0(r28)
_8004c62c:
    lwz	r3, 0(r28)
    lwz	r0, 0x88(r27)
    add	r0, r3, r0
    stw	r0, 0(r28)
    lwz	r0, 0x2c(r31)
    stw	r0, 0(r29)
_8004c644:
    lmw	r25, 0x34(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void ADXT_GetStat(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004c680
    lis     r3, E02080814_ADXT_GetStat_parameter_error_str@ha
    addi	r3, r3, E02080814_ADXT_GetStat_parameter_error_str@l
    bl      criErr_CallErrCallback
    li	r3, -1
    b       _8004c688
_8004c680:
    lbz	r3, 1(r3)
    extsb	r3, r3
_8004c688:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ADXT_Stop(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    bne     _8004c6c0
    lis     r3, E02080813_ADXT_Stop_parameter_error_str@ha
    addi	r3, r3, E02080813_ADXT_Stop_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004c780
_8004c6c0:
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8004c6d0
    bl      ADXT_StopVoice
_8004c6d0:
    bl      svmLockServer_wrapper
    lbz	r0, 2(r31)
    cmpwi	r0, 4
    bne     _8004c704
    lwz	r3, 0x94(r31)
    bl      fn_80056CD0
    lwz	r3, 0x14(r31)
    cmplwi	r3, 0
    beq     _8004c704
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
_8004c704:
    bl      svmLockServer_wrapper
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      ADXT_GetResourceManager
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      ADXTServerStateRequest_wrapper
    lwz	r3, 4(r31)
    bl      fn_800420F4
    lbz	r0, 2(r31)
    cmpwi	r0, 2
    bne     _8004c758
    lwz	r3, 0x14(r31)
    cmplwi	r3, 0
    beq     _8004c758
    li	r0, 0
    stw	r0, 0x14(r31)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004c758:
    lwz	r3, 0x74(r31)
    cmplwi	r3, 0
    beq     _8004c768
    bl      fn_80046510
_8004c768:
    li	r0, 0
    stw	r0, 0x14(r31)
    stb	r0, 1(r31)
    stb	r0, 0xa8(r31)
    bl      svmUnlockServer_wrapper
    bl      svmUnlockServer_wrapper
_8004c780:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ADXT_StartSj(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r4
    stw	r30, 0x18(r1)
    or.	r30, r3, r3
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    beq     _8004c7c4
    cmplwi	r31, 0
    bne     _8004c7d4
_8004c7c4:
    lis     r3, E02080812_ADXT_StartSj_parameter_error_str@ha
    addi	r3, r3, E02080812_ADXT_StartSj_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004c960
_8004c7d4:
    cmplwi	r30, 0
    bne     _8004c7ec
    lis     r3, E02080813_ADXT_Stop_parameter_error_str@ha
    addi	r3, r3, E02080813_ADXT_Stop_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004c8ac
_8004c7ec:
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8004c7fc
    bl      ADXT_StopVoice
_8004c7fc:
    bl      svmLockServer_wrapper
    lbz	r0, 2(r30)
    cmpwi	r0, 4
    bne     _8004c830
    lwz	r3, 0x94(r30)
    bl      fn_80056CD0
    lwz	r3, 0x14(r30)
    cmplwi	r3, 0
    beq     _8004c830
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
_8004c830:
    bl      svmLockServer_wrapper
    lwz	r3, 0xc(r30)
    li	r4, 0
    bl      ADXT_GetResourceManager
    lwz	r3, 0xc(r30)
    li	r4, 0
    bl      ADXTServerStateRequest_wrapper
    lwz	r3, 4(r30)
    bl      fn_800420F4
    lbz	r0, 2(r30)
    cmpwi	r0, 2
    bne     _8004c884
    lwz	r3, 0x14(r30)
    cmplwi	r3, 0
    beq     _8004c884
    li	r0, 0
    stw	r0, 0x14(r30)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004c884:
    lwz	r3, 0x74(r30)
    cmplwi	r3, 0
    beq     _8004c894
    bl      fn_80046510
_8004c894:
    li	r0, 0
    stw	r0, 0x14(r30)
    stb	r0, 1(r30)
    stb	r0, 0xa8(r30)
    bl      svmUnlockServer_wrapper
    bl      svmUnlockServer_wrapper
_8004c8ac:
    bl      svmLockServer_wrapper
    mr	r28, r30
    li	r29, 0
    b       _8004c8d8
_8004c8bc:
    lwz	r3, 0x18(r28)
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
    addi	r28, r28, 4
    addi	r29, r29, 1
_8004c8d8:
    lbz	r0, 3(r30)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8004c8bc
    lwz	r3, 4(r30)
    mr	r4, r31
    bl      fn_80042198
    stw	r31, 0x14(r30)
    lwz	r3, 4(r30)
    bl      fn_8004212C
    li	r0, 1
    lis	r4, -0x8000
    stb	r0, 1(r30)
    li	r5, 0
    addi	r4, r4, -1
    li	r0, -1
    stw	r5, 0x4c(r30)
    lis	r3, -0x7fe8
    stb	r5, 0x71(r30)
    stw	r4, 0x8c(r30)
    stw	r0, 0x90(r30)
    stw	r5, 0x9c(r30)
    stw	r5, 0xa4(r30)
    lwz	r0, -0x7348(r3)
    stw	r0, 0xa0(r30)
    lwz	r3, 0x74(r30)
    cmplwi	r3, 0
    beq     _8004c94c
    bl      fn_8004651C
_8004c94c:
    li	r3, 3
    li	r0, 1
    stb	r3, 2(r30)
    stb	r0, 0x98(r30)
    bl      svmUnlockServer_wrapper
_8004c960:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004C980(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r27, r4
    mr	r31, r3
    mr	r30, r5
    mr	r29, r6
    mr	r28, r7
    lha	r4, 0x3e(r3)
    lha	r0, 0x3c(r3)
    lwz	r3, 8(r3)
    slwi	r4, r4, 0xb
    slwi	r5, r0, 0xb
    bl      fn_8004A550
    lwz	r3, 8(r31)
    li	r4, 0x19
    bl      ADXT_GetVoiceByAxHandle
    lwz	r3, 8(r31)
    li	r4, 0
    li	r5, 0
    bl      fn_8004AC4C
    lwz	r3, 8(r31)
    li	r4, 0
    bl      fn_8004AE94
    lwz	r3, 8(r31)
    bl      fn_8004AD84
    lwz	r3, 8(r31)
    bl      ADXT_StopVoice
    lwz	r3, 8(r31)
    mr	r4, r27
    mr	r5, r30
    mr	r6, r29
    mr	r7, r28
    bl      fn_8004B180
    lwz	r3, 8(r31)
    bl      fn_8004ADF4
    lwz	r29, 0x10(r31)
    mr	r28, r31
    li	r30, 0
    b       _8004ca40
_8004ca24:
    lwz	r3, 0x18(r28)
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
    addi	r28, r28, 4
    addi	r30, r30, 1
_8004ca40:
    lbz	r0, 3(r31)
    extsb	r0, r0
    cmpw	r30, r0
    blt     _8004ca24
    lwz	r3, 4(r31)
    mr	r4, r29
    bl      fn_80042198
    stw	r29, 0x14(r31)
    lwz	r3, 4(r31)
    bl      fn_8004212C
    li	r0, 1
    lis	r4, -0x8000
    stb	r0, 1(r31)
    li	r5, 0
    addi	r4, r4, -1
    li	r0, -1
    stw	r5, 0x4c(r31)
    lis	r3, -0x7fe8
    stb	r5, 0x71(r31)
    stw	r4, 0x8c(r31)
    stw	r0, 0x90(r31)
    stw	r5, 0x9c(r31)
    stw	r5, 0xa4(r31)
    lwz	r0, -0x7348(r3)
    stw	r0, 0xa0(r31)
    lwz	r3, 0x74(r31)
    cmplwi	r3, 0
    beq     _8004cab4
    bl      fn_8004651C
_8004cab4:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004CAC8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    or.	r31, r3, r3
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    bne     _8004caf8
    lis     r3, E02080805_ADXT_Destroy_parameter_error_str@ha
    addi	r3, r3, E02080805_ADXT_Destroy_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004cd54
_8004caf8:
    lis	r4, -0x7fe8
    lwz	r12, -0x1a74(r4)
    cmplwi	r12, 0
    beq     _8004cb10
    mtctr	r12
    bctrl	
_8004cb10:
    lbz	r0, 0(r31)
    cmpwi	r0, 1
    bne     _8004cbf4
    cmplwi	r31, 0
    bne     _8004cb34
    lis     r3, E02080813_ADXT_Stop_parameter_error_str@ha
    addi	r3, r3, E02080813_ADXT_Stop_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004cbf4
_8004cb34:
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8004cb44
    bl      ADXT_StopVoice
_8004cb44:
    bl      svmLockServer_wrapper
    lbz	r0, 2(r31)
    cmpwi	r0, 4
    bne     _8004cb78
    lwz	r3, 0x94(r31)
    bl      fn_80056CD0
    lwz	r3, 0x14(r31)
    cmplwi	r3, 0
    beq     _8004cb78
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
_8004cb78:
    bl      svmLockServer_wrapper
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      ADXT_GetResourceManager
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      ADXTServerStateRequest_wrapper
    lwz	r3, 4(r31)
    bl      fn_800420F4
    lbz	r0, 2(r31)
    cmpwi	r0, 2
    bne     _8004cbcc
    lwz	r3, 0x14(r31)
    cmplwi	r3, 0
    beq     _8004cbcc
    li	r0, 0
    stw	r0, 0x14(r31)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004cbcc:
    lwz	r3, 0x74(r31)
    cmplwi	r3, 0
    beq     _8004cbdc
    bl      fn_80046510
_8004cbdc:
    li	r0, 0
    stw	r0, 0x14(r31)
    stb	r0, 1(r31)
    stb	r0, 0xa8(r31)
    bl      svmUnlockServer_wrapper
    bl      svmUnlockServer_wrapper
_8004cbf4:
    lwz	r3, 0xc(r31)
    cmplwi	r3, 0
    beq     _8004cc0c
    li	r0, 0
    stw	r0, 0xc(r31)
    bl      fn_8004EEE4
_8004cc0c:
    lwz	r3, 4(r31)
    cmplwi	r3, 0
    beq     _8004cc24
    li	r0, 0
    stw	r0, 4(r31)
    bl      fn_800421CC
_8004cc24:
    lwz	r30, 8(r31)
    cmplwi	r30, 0
    beq     _8004cc50
    li	r0, 0
    mr	r3, r30
    stw	r0, 8(r31)
    li	r4, 0
    li	r5, 0
    bl      fn_8004AC4C
    mr	r3, r30
    bl      fn_8004B1DC
_8004cc50:
    lwz	r3, 0x94(r31)
    cmplwi	r3, 0
    beq     _8004cc68
    li	r0, 0
    stw	r0, 0x94(r31)
    bl      fn_80057114
_8004cc68:
    bl      svmLockServer_wrapper
    lwz	r3, 0x10(r31)
    cmplwi	r3, 0
    beq     _8004cc90
    li	r0, 0
    stw	r0, 0x10(r31)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004cc90:
    mr	r30, r31
    li	r29, 0
    b       _8004cd10
_8004cc9c:
    lwz	r3, 0x18(r30)
    cmplwi	r3, 0
    beq     _8004ccc0
    li	r0, 0
    stw	r0, 0x18(r30)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004ccc0:
    lwz	r3, 0x78(r30)
    cmplwi	r3, 0
    beq     _8004cce4
    li	r0, 0
    stw	r0, 0x78(r30)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004cce4:
    lwz	r3, 0x80(r30)
    cmplwi	r3, 0
    beq     _8004cd08
    li	r0, 0
    stw	r0, 0x80(r30)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004cd08:
    addi	r30, r30, 4
    addi	r29, r29, 1
_8004cd10:
    lbz	r0, 3(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _8004cc9c
    lwz	r3, 0x74(r31)
    cmplwi	r3, 0
    beq     _8004cd38
    li	r0, 0
    stw	r0, 0x74(r31)
    bl      fn_800466D4
_8004cd38:
    mr	r3, r31
    li	r4, 0
    li	r5, 0xc0
    bl      memset
    li	r0, 0
    stb	r0, 0(r31)
    bl      svmUnlockServer_wrapper
_8004cd54:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
