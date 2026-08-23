#pragma push
#pragma force_active on

extern void __cvt_fp2unsigned(void);
extern void fn_80041460(void);
extern void fn_800414D0(void);
extern void fn_800415F4(void);
extern void fn_80041660(void);
extern void fn_80041684(void);
extern void fn_80041700(void);
extern void fn_80046718(void);
extern void fn_80046738(void);
extern void fn_80046C28(void);
extern void fn_800474E4(void);
extern void fn_80047548(void);
extern void fn_8004C164(void);
extern void fn_8004D220(void);
extern void fn_8004ED84(void);
extern void fn_8004EDC4(void);
extern void fn_8004EDE4(void);
extern void fn_8004EE44(void);
extern void fn_8004EEA4(void);
extern void fn_800589BC(void);
extern void memset(void);
extern unsigned char E02080817_ADXT_GetNumSmpl_parameter_error_str[];
extern unsigned char E02080819_ADXT_GetSfreq_parameter_error_str[];
extern unsigned char E02080820_ADXT_GetNumChan_parameter_error_str[];
extern unsigned char E02080823_ADXT_SetOutVol_parameter_error_str[];
extern unsigned char E02080824_ADXT_GetOutVol_parameter_error_str[];
extern unsigned char E02080825_ADXT_SetOutPan_parameter_error_str[];
extern unsigned char E02080826_ADXT_GetOutPan_parameter_error_str[];
extern unsigned char E02080831_ADXT_IsReadyPlayStart_parameter_error_str[];
extern unsigned char E02080840_ADXT_SetSvrFreq_parameter_error_str[];
extern unsigned char E02080843_ADXT_GetErrCode_parameter_error_str[];
extern unsigned char E02080846_ADXT_Pause_parameter_error_str[];
extern unsigned char E02080847_ADXT_GetStatPause_parameter_error_str[];
extern unsigned char E8101208_ADXT_SetOutPan_parameter_error_str[];
extern unsigned char lbl_80090A20[];
extern unsigned char lbl_80178CB8[];
extern unsigned char lbl_80178CBC[];
extern unsigned char lbl_8017E568[];
extern unsigned char lbl_8017E594[];

asm void fn_8004B7F4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    stw	r28, 0x20(r1)
    lwz	r3, 0x14(r3)
    cmplwi	r3, 0
    mr	r29, r3
    bne     _8004b828
    li	r3, 0
    b       _8004b954
_8004b828:
    mulli	r31, r4, 0x12
    srawi	r0, r5, 5
    lwz	r4, 0(r3)
    addi	r6, r1, 0x10
    addze	r0, r0
    mullw	r30, r0, r31
    lwz	r12, 0x18(r4)
    li	r4, 0
    mr	r5, r30
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    li	r4, 0
    lwz	r3, 0x10(r1)
    divw	r0, r0, r31
    mullw	r28, r31, r0
    mr	r5, r28
    bl      memset
    addi	r3, r1, 0x10
    mr	r4, r28
    mr	r5, r3
    addi	r6, r1, 8
    bl      fn_800589BC
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    lwz	r4, 0(r29)
    subf	r30, r28, r30
    mr	r3, r29
    addi	r6, r1, 0x10
    lwz	r12, 0x18(r4)
    mr	r5, r30
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    li	r4, 0
    lwz	r3, 0x10(r1)
    divw	r0, r0, r31
    mullw	r30, r31, r0
    mr	r5, r30
    bl      memset
    addi	r3, r1, 0x10
    mr	r4, r30
    mr	r5, r3
    addi	r6, r1, 8
    bl      fn_800589BC
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    add	r0, r28, r30
    divw	r0, r0, r31
    slwi	r3, r0, 5
_8004b954:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    lwz	r28, 0x20(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8004B974(void)
{
    nofralloc
    cmpwi	r4, 2
    bge     _8004b984
    li	r3, 0
    blr	
_8004b984:
    lhz	r0, 0(r3)
    cmplwi	r0, 0x8001
    beq     _8004b998
    li	r3, 0
    blr	
_8004b998:
    stw	r4, 0(r5)
    li	r3, 1
    blr	
}

asm void fn_8004B9A4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    cmpwi	r4, 2
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    mr	r31, r5
    bge     _8004b9c8
    li	r3, 0
    b       _8004ba24
_8004b9c8:
    lhz	r0, 0(r3)
    cmplwi	r0, 0x8000
    beq     _8004b9dc
    li	r3, 0
    b       _8004ba24
_8004b9dc:
    addi	r5, r1, 0x1c
    addi	r0, r1, 0x18
    stw	r5, 8(r1)
    addi	r5, r1, 0x14
    addi	r6, r1, 0x13
    addi	r7, r1, 0x12
    stw	r0, 0xc(r1)
    addi	r8, r1, 0x11
    addi	r9, r1, 0x10
    addi	r10, r1, 0x20
    bl      fn_80046C28
    cmpwi	r3, 0
    bge     _8004ba18
    li	r3, 0
    b       _8004ba24
_8004ba18:
    lha	r0, 0x14(r1)
    li	r3, 1
    stw	r0, 0(r31)
_8004ba24:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8004BA38(void)
{
    nofralloc
    stw	r4, 0x88(r3)
    blr	
}

asm void ADXT_GetDecNumSmpl(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stmw	r27, 0x2c(r1)
    mr	r29, r3
    lis     r3, lbl_8017E568@ha
    addi    r3, r3, lbl_8017E568@l
    lbz	r0, 0x72(r29)
    extsb.	r0, r0
    bne     _8004ba70
    li	r3, 0
    b       _8004bb90
_8004ba70:
    lwz	r3, 0xc(r29)
    bl      fn_8004ED84
    mr	r30, r3
    bl      fn_80046738
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    beq     _8004ba94
    bl      fn_80046718
    b       _8004baf8
_8004ba94:
    li	r0, 1
    stw	r0, 4(r31)
    bl      fn_80046718
    bl      fn_80046738
    bl      fn_80041700
    li	r0, 2
    lis     r3, lbl_80178CBC@ha
    stw	r0, 4(r31)
    addi    r3, r3, lbl_80178CBC@l
    li	r28, 0
_8004babc:
    lbz	r0, 0(r27)
    cmpwi	r0, 1
    bne     _8004bad0
    mr	r3, r27
    bl      fn_8004D220
_8004bad0:
    addi	r28, r28, 1
    addi	r27, r27, 0xc0
    cmpwi	r28, 0x10
    blt     _8004babc
    li	r0, 3
    stw	r0, 4(r31)
    bl      fn_8004EE44
    li	r0, 0
    stw	r0, 4(r31)
    bl      fn_80046718
_8004baf8:
    lwz	r27, 0(r31)
    li	r0, 0
    mr	r3, r29
    addi	r4, r1, 0xc
    stw	r0, 0(r31)
    addi	r5, r1, 8
    bl      fn_8004C164
    lwz	r3, 0xc(r1)
    lis	r4, 0x4330
    lwz	r0, 8(r1)
    lis	r5, -0x7ff7
    xoris	r3, r3, 0x8000
    stw	r4, 0x18(r1)
    xoris	r0, r0, 0x8000
    lfd	f2, 0xa20(r5)
    stw	r3, 0x1c(r1)
    lwz	r6, 0x2c(r31)
    lfd	f0, 0x18(r1)
    stw	r0, 0x24(r1)
    xoris	r3, r6, 0x8000
    fsubs	f1, f0, f2
    stw	r4, 0x20(r1)
    lfd	f0, 0x20(r1)
    stw	r3, 0x14(r1)
    fsubs	f0, f0, f2
    stw	r4, 0x10(r1)
    fdivs	f0, f1, f0
    lfd	f1, 0x10(r1)
    stw	r27, 0(r31)
    fsubs	f1, f1, f2
    fmuls	f1, f1, f0
    bl      __cvt_fp2unsigned
    stw	r3, 0x9c(r29)
    lis     r3, lbl_80178CB8@ha
    addi    r3, r3, lbl_80178CB8@l
    mr	r3, r30
    lwz	r0, 0(r4)
    stw	r0, 0xa0(r29)
_8004bb90:
    lmw	r27, 0x2c(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8004BBA4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80047548
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BBC4(void)
{
    nofralloc
    blr	
}

asm void fn_8004BBC8(void)
{
    nofralloc
    blr	
}

asm void fn_8004BBCC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004bbf4
    lis     r3, E02080847_ADXT_GetStatPause_parameter_error_str@ha
    addi    r3, r3, E02080847_ADXT_GetStatPause_parameter_error_str@l
    bl      fn_800474E4
    li	r3, 0
    b       _8004bbfc
_8004bbf4:
    lbz	r3, 0x72(r3)
    extsb	r3, r3
_8004bbfc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BC0C(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stw	r31, 0x3c(r1)
    or.	r31, r3, r3
    stw	r30, 0x38(r1)
    stw	r29, 0x34(r1)
    mr	r29, r4
    bne     _8004bc40
    lis     r3, E02080846_ADXT_Pause_parameter_error_str@ha
    addi    r3, r3, E02080846_ADXT_Pause_parameter_error_str@l
    bl      fn_800474E4
    b       _8004bd40
_8004bc40:
    lbz	r0, 0x72(r31)
    lbz	r30, 1(r31)
    extsb	r0, r0
    cmpw	r29, r0
    extsb	r30, r30
    beq     _8004bd40
    bl      fn_80046738
    cmpwi	r30, 3
    stb	r29, 0x72(r31)
    beq     _8004bc70
    cmpwi	r30, 4
    bne     _8004bd3c
_8004bc70:
    cmpwi	r29, 1
    bne     _8004bc88
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      fn_8004EEA4
    b       _8004bca0
_8004bc88:
    lwz	r3, 0xc(r31)
    li	r4, 1
    bl      fn_8004EEA4
    lis	r3, -0x7fe8
    lwz	r0, -0x7348(r3)
    stw	r0, 0xa0(r31)
_8004bca0:
    lis     r3, lbl_8017E568@ha
    li	r0, 0
    addi    r3, r3, lbl_8017E568@l
    mr	r3, r31
    lwz	r30, 0(r6)
    addi	r4, r1, 0xc
    addi	r5, r1, 8
    stw	r0, 0(r6)
    bl      fn_8004C164
    lwz	r3, 0xc(r1)
    lis	r4, 0x4330
    lwz	r0, 8(r1)
    lis     r5, lbl_80090A20@ha
    xoris	r3, r3, 0x8000
    stw	r4, 0x18(r1)
    xoris	r0, r0, 0x8000
    lis     r6, lbl_8017E594@ha
    stw	r3, 0x1c(r1)
    addi    r5, r5, lbl_80090A20@l
    lfd	f2, 0(r3)
    addi    r6, r6, lbl_8017E594@l
    lfd	f0, 0x18(r1)
    lis	r6, -0x7fe8
    stw	r0, 0x24(r1)
    fsubs	f1, f0, f2
    lwz	r0, 0(r5)
    stw	r4, 0x20(r1)
    xoris	r0, r0, 0x8000
    lfd	f0, 0x20(r1)
    stw	r0, 0x14(r1)
    fsubs	f0, f0, f2
    stw	r4, 0x10(r1)
    fdivs	f0, f1, f0
    lfd	f1, 0x10(r1)
    stw	r30, -0x1a98(r6)
    fsubs	f1, f1, f2
    fmuls	f1, f1, f0
    bl      __cvt_fp2unsigned
    stw	r3, 0x9c(r31)
_8004bd3c:
    bl      fn_80046718
_8004bd40:
    lwz	r0, 0x44(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    lwz	r29, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8004BD5C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004bd84
    lis     r3, E02080831_ADXT_IsReadyPlayStart_parameter_error_str@ha
    addi    r3, r3, E02080831_ADXT_IsReadyPlayStart_parameter_error_str@l
    bl      fn_800474E4
    li	r3, -1
    b       _8004bd8c
_8004bd84:
    lbz	r3, 0x71(r3)
    extsb	r3, r3
_8004bd8c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BD9C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004bdc4
    lis     r3, E02080843_ADXT_GetErrCode_parameter_error_str@ha
    addi    r3, r3, E02080843_ADXT_GetErrCode_parameter_error_str@l
    bl      fn_800474E4
    li	r3, -1
    b       _8004bdc8
_8004bdc4:
    lha	r3, 0x60(r3)
_8004bdc8:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BDD8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    bl      fn_80046738
    lis	r3, -0x7fe8
    lwzu	r0, -0x1a94(r3)
    cmpwi	r0, 0
    beq     _8004be08
    bl      fn_80046718
    b       _8004be78
_8004be08:
    li	r0, 1
    stw	r0, 0(r3)
    bl      fn_80046718
    bl      fn_80046738
    bl      fn_80041700
    lis	r4, -0x7fe8
    li	r0, 2
    lis     r3, lbl_80178CBC@ha
    stw	r0, -0x1a94(r4)
    addi    r3, r3, lbl_80178CBC@l
    li	r30, 0
_8004be34:
    lbz	r0, 0(r31)
    cmpwi	r0, 1
    bne     _8004be48
    mr	r3, r31
    bl      fn_8004D220
_8004be48:
    addi	r30, r30, 1
    addi	r31, r31, 0xc0
    cmpwi	r30, 0x10
    blt     _8004be34
    lis	r3, -0x7fe8
    li	r0, 3
    stw	r0, -0x1a94(r3)
    bl      fn_8004EE44
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x1a94(r3)
    bl      fn_80046718
_8004be78:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BE90(void)
{
    nofralloc
    stb	r4, 0x6d(r3)
    blr	
}

asm void fn_8004BE98(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004bebc
    lis     r3, E02080840_ADXT_SetSvrFreq_parameter_error_str@ha
    addi    r3, r3, E02080840_ADXT_SetSvrFreq_parameter_error_str@l
    bl      fn_800474E4
    b       _8004bec0
_8004bebc:
    stw	r4, 0x38(r3)
_8004bec0:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BED0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004bef8
    lis     r3, E02080824_ADXT_GetOutVol_parameter_error_str@ha
    addi    r3, r3, E02080824_ADXT_GetOutVol_parameter_error_str@l
    bl      fn_800474E4
    li	r3, 0
    b       _8004befc
_8004bef8:
    lha	r3, 0x40(r3)
_8004befc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BF0C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    bne     _8004bf34
    lis     r3, E02080823_ADXT_SetOutVol_parameter_error_str@ha
    addi    r3, r3, E02080823_ADXT_SetOutVol_parameter_error_str@l
    bl      fn_800474E4
    b       _8004bf54
_8004bf34:
    sth	r4, 0x40(r31)
    lwz	r3, 4(r31)
    bl      fn_800414D0
    lha	r0, 0x40(r31)
    extsh	r4, r3
    lwz	r3, 0xc(r31)
    add	r4, r0, r4
    bl      fn_8004EDE4
_8004bf54:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BF68(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004bf90
    lis     r3, E02080826_ADXT_GetOutPan_parameter_error_str@ha
    addi    r3, r3, E02080826_ADXT_GetOutPan_parameter_error_str@l
    bl      fn_800474E4
    li	r3, 0
    b       _8004bf9c
_8004bf90:
    slwi	r0, r4, 1
    add	r3, r3, r0
    lha	r3, 0x42(r3)
_8004bf9c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004BFAC(void)
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
    or.	r29, r3, r3
    bne     _8004bfe4
    lis     r3, E02080825_ADXT_SetOutPan_parameter_error_str@ha
    addi    r3, r3, E02080825_ADXT_SetOutPan_parameter_error_str@l
    bl      fn_800474E4
    b       _8004c040
_8004bfe4:
    lwz	r3, 4(r29)
    bl      fn_80041460
    extsh	r0, r3
    cmpwi	r0, -0x80
    bne     _8004bffc
    li	r3, 0
_8004bffc:
    extsh	r3, r3
    slwi	r0, r30, 1
    add	r4, r31, r3
    add	r3, r29, r0
    sth	r4, 0x42(r3)
    lbz	r0, 3(r29)
    extsb	r0, r0
    cmpw	r30, r0
    bge     _8004c034
    lwz	r3, 0xc(r29)
    mr	r4, r30
    mr	r5, r31
    bl      fn_8004EDC4
    b       _8004c040
_8004c034:
    lis     r3, E8101208_ADXT_SetOutPan_parameter_error_str@ha
    addi    r3, r3, E8101208_ADXT_SetOutPan_parameter_error_str@l
    bl      fn_800474E4
_8004c040:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004C05C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004c084
    lis     r3, E02080820_ADXT_GetNumChan_parameter_error_str@ha
    addi    r3, r3, E02080820_ADXT_GetNumChan_parameter_error_str@l
    bl      fn_800474E4
    li	r3, -1
    b       _8004c0a4
_8004c084:
    lbz	r0, 1(r3)
    extsb	r0, r0
    cmpwi	r0, 2
    blt     _8004c0a0
    lwz	r3, 4(r3)
    bl      fn_80041660
    b       _8004c0a4
_8004c0a0:
    li	r3, 0
_8004c0a4:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004C0B4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004c0dc
    lis     r3, E02080819_ADXT_GetSfreq_parameter_error_str@ha
    addi    r3, r3, E02080819_ADXT_GetSfreq_parameter_error_str@l
    bl      fn_800474E4
    li	r3, -1
    b       _8004c0fc
_8004c0dc:
    lbz	r0, 1(r3)
    extsb	r0, r0
    cmpwi	r0, 2
    blt     _8004c0f8
    lwz	r3, 4(r3)
    bl      fn_80041684
    b       _8004c0fc
_8004c0f8:
    li	r3, 0
_8004c0fc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004C10C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8004c134
    lis     r3, E02080817_ADXT_GetNumSmpl_parameter_error_str@ha
    addi    r3, r3, E02080817_ADXT_GetNumSmpl_parameter_error_str@l
    bl      fn_800474E4
    li	r3, -1
    b       _8004c154
_8004c134:
    lbz	r0, 1(r3)
    extsb	r0, r0
    cmpwi	r0, 2
    blt     _8004c150
    lwz	r3, 4(r3)
    bl      fn_800415F4
    b       _8004c154
_8004c150:
    li	r3, 0
_8004c154:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
