#pragma push
#pragma force_active on

extern void fn_80047464(void);
extern void fn_8004A5F4(void);
extern void fn_8004A80C(void);
extern void cvFsGetStat(void);
extern void cvFsReqRd(void);
extern void cvFsSeek(void);
extern void cvFsTell(void);
extern void cvFsClose(void);
extern void fn_80054B6C(void);
extern void svm_ringbuf_read(void);
extern void fn_80058A40(void);
extern void svmUnlockServer(void);
extern void svmLockServer(void);
extern unsigned char E02110501_adxstmf_stat_exec_can_t_open_str[41];
extern unsigned char lbl_8017D6FC[4];
extern unsigned char lbl_8017D704[4];
extern unsigned char lbl_8017D708[3680];

asm void fn_8004A560(void)
{
    nofralloc
    lwz	r0, 0x18(r3)
    stw	r0, 0(r4)
    lwz	r0, 0x14(r3)
    li	r3, 1
    stw	r0, 0(r5)
    blr	
}

asm void fn_8004A578(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8017D6FC@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, lbl_8017D6FC@l
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    bl      fn_80058A40
    cmpwi	r3, 0
    beq     _8004a5dc
    lis     r3, lbl_8017D708@ha
    li	r30, 0
    addi	r31, r3, lbl_8017D708@l
_8004a5ac:
    lbz	r0, 0(r31)
    cmpwi	r0, 1
    bne     _8004a5c0
    mr	r3, r31
    bl      fn_8004A5F4
_8004a5c0:
    addi	r30, r30, 1
    addi	r31, r31, 0x5c
    cmpwi	r30, 0x28
    blt     _8004a5ac
    lis	r3, -0x7fe8
    li	r0, 0
    stw	r0, -0x2904(r3)
_8004a5dc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004A5F4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    lbz	r0, 2(r3)
    extsb.	r0, r0
    bne     _8004a7d0
    lbz	r0, 0x44(r31)
    cmpwi	r0, 1
    bne     _8004a644
    li	r0, 0
    stb	r0, 0x44(r31)
    lbz	r0, 0x43(r31)
    extsb.	r0, r0
    bne     _8004a644
    li	r0, 1
    stb	r0, 1(r31)
_8004a644:
    lbz	r0, 0x42(r31)
    cmpwi	r0, 1
    bne     _8004a674
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8004a668
    li	r0, 0
    stw	r0, 8(r31)
    bl      cvFsClose
_8004a668:
    li	r0, 0
    stb	r0, 0x42(r31)
    stb	r0, 0x45(r31)
_8004a674:
    bl      svmLockServer
    lbz	r0, 0x41(r31)
    cmpwi	r0, 1
    bne     _8004a7b8
    li	r0, 1
    stb	r0, 0x45(r31)
    bl      svmUnlockServer
    lwz	r0, 8(r31)
    cmplwi	r0, 0
    bne     _8004a7bc
    lwz	r3, 0x4c(r31)
    li	r5, 0
    lwz	r4, 0x50(r31)
    bl      fn_80054B6C
    cmplwi	r3, 0
    stw	r3, 8(r31)
    bne     _8004a6e0
    lis     r3, E02110501_adxstmf_stat_exec_can_t_open_str@ha
    lwz	r4, 0x4c(r31)
    addi	r3, r3, E02110501_adxstmf_stat_exec_can_t_open_str@l
    bl      fn_80047464
    li	r3, 4
    li	r0, 0
    stb	r3, 1(r31)
    stb	r0, 0x45(r31)
    stb	r0, 0x41(r31)
    b       _8004a7f0
_8004a6e0:
    lwz	r3, 8(r31)
    li	r4, 0
    li	r5, 2
    bl      cvFsSeek
    lwz	r3, 8(r31)
    bl      cvFsTell
    mr	r30, r3
    lwz	r3, 8(r31)
    slwi	r29, r30, 0xb
    li	r4, 0
    li	r5, 0
    bl      cvFsSeek
    lwz	r3, 0x10(r31)
    addis	r0, r3, -0x7fff
    cmplwi	r0, 0xf800
    bne     _8004a728
    stw	r29, 0x10(r31)
    b       _8004a760
_8004a728:
    lwz	r0, 0xc(r31)
    cmpw	r0, r30
    ble     _8004a738
    stw	r30, 0xc(r31)
_8004a738:
    lwz	r0, 0x10(r31)
    lwz	r3, 0xc(r31)
    srawi	r0, r0, 0xb
    addze	r0, r0
    add	r0, r0, r3
    cmpw	r0, r30
    ble     _8004a760
    subf	r0, r3, r30
    slwi	r0, r0, 0xb
    stw	r0, 0x10(r31)
_8004a760:
    li	r0, 0
    stw	r0, 0x54(r31)
    lwz	r0, 0x54(r31)
    lwz	r4, 0x10(r31)
    slwi	r0, r0, 0xb
    cmpw	r0, r4
    ble     _8004a7ac
    slwi	r0, r4, 0x15
    srwi	r3, r4, 0x1f
    subf	r0, r3, r0
    srawi	r4, r4, 0xb
    rotlwi	r0, r0, 0xb
    add	r3, r0, r3
    addze	r4, r4
    neg	r0, r3
    andc	r0, r0, r3
    srwi	r0, r0, 0x1f
    add	r0, r4, r0
    stw	r0, 0x54(r31)
_8004a7ac:
    li	r0, 0
    stb	r0, 0x41(r31)
    b       _8004a7bc
_8004a7b8:
    bl      svmUnlockServer
_8004a7bc:
    lbz	r0, 0x43(r31)
    cmpwi	r0, 1
    bne     _8004a7d0
    li	r0, 0
    stb	r0, 0x43(r31)
_8004a7d0:
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004a7f0
    lbz	r0, 0x45(r31)
    cmpwi	r0, 1
    bne     _8004a7f0
    mr	r3, r31
    bl      fn_8004A80C
_8004a7f0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004A80C(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    mr	r30, r3
    stw	r29, 0x24(r1)
    lwz	r31, 4(r3)
    lwz	r3, 8(r3)
    bl      cvFsGetStat
    mr	r29, r3
    bl      svmLockServer
    lbz	r0, 2(r30)
    cmpwi	r0, 1
    bne     _8004a9fc
    cmpwi	r29, 1
    bne     _8004a980
    li	r0, 0
    stb	r0, 2(r30)
    bl      svmUnlockServer
    lwz	r0, 0x1c(r30)
    addi	r3, r30, 0x20
    addi	r5, r1, 0x18
    addi	r6, r1, 0x10
    slwi	r29, r0, 0xb
    mr	r4, r29
    bl      svm_ringbuf_read
    lwz	r6, 0(r31)
    mr	r3, r31
    addi	r5, r1, 0x18
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r31)
    mr	r3, r31
    addi	r5, r1, 0x10
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    lwz	r4, 0x54(r30)
    li	r0, 0
    lwz	r3, 0x1c(r30)
    add	r3, r4, r3
    stw	r3, 0x54(r30)
    lwz	r3, 0x30(r30)
    add	r3, r3, r29
    stw	r3, 0x30(r30)
    stw	r0, 0x20(r30)
    stw	r0, 0x24(r30)
    lwz	r6, 0x10(r30)
    lwz	r3, 0x54(r30)
    slwi	r0, r6, 0x15
    srwi	r5, r6, 0x1f
    subf	r4, r5, r0
    lwz	r0, 0x2c(r30)
    rotlwi	r4, r4, 0xb
    srawi	r6, r6, 0xb
    add	r4, r4, r5
    cmpw	r3, r0
    neg	r0, r4
    addze	r3, r6
    andc	r0, r0, r4
    srwi	r0, r0, 0x1f
    add	r29, r3, r0
    bne     _8004a930
    lwz	r12, 0x34(r30)
    cmplwi	r12, 0
    beq     _8004a930
    lwz	r3, 0x38(r30)
    mtctr	r12
    bctrl	
_8004a930:
    lwz	r0, 0x54(r30)
    cmpw	r0, r29
    blt     _8004a948
    li	r0, 3
    stb	r0, 1(r30)
    b       _8004a974
_8004a948:
    lwz	r0, 0x30(r30)
    lwz	r4, 0x58(r30)
    srwi	r0, r0, 0xb
    cmplw	r0, r4
    blt     _8004a974
    lis	r3, 0x10
    addi	r0, r3, -1
    cmplw	r4, r0
    bge     _8004a974
    li	r0, 3
    stb	r0, 1(r30)
_8004a974:
    li	r0, 0
    stb	r0, 3(r30)
    b       _8004abe8
_8004a980:
    cmpwi	r29, 3
    bne     _8004a9f4
    li	r0, 0
    stb	r0, 2(r30)
    bl      svmUnlockServer
    lwz	r6, 0(r31)
    mr	r3, r31
    addi	r5, r30, 0x20
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    lis	r3, -0x7fe8
    stw	r0, 0x20(r30)
    stw	r0, 0x24(r30)
    lwz	r4, -0x2900(r3)
    cmpwi	r4, 0
    blt     _8004abe8
    lbz	r3, 3(r30)
    extsb	r0, r3
    cmpw	r0, r4
    blt     _8004a9e8
    li	r0, 4
    stb	r0, 1(r30)
    b       _8004abe8
_8004a9e8:
    addi	r0, r3, 1
    stb	r0, 3(r30)
    b       _8004abe8
_8004a9f4:
    bl      svmUnlockServer
    b       _8004abe8
_8004a9fc:
    li	r3, 1
    li	r0, 0
    stb	r3, 2(r30)
    stw	r0, 0x20(r30)
    stw	r0, 0x24(r30)
    bl      svmUnlockServer
    lbz	r0, 0x40(r30)
    cmpwi	r0, 1
    beq     _8004aa2c
    lbz	r0, 0x44(r30)
    cmpwi	r0, 1
    bne     _8004aa38
_8004aa2c:
    li	r0, 0
    stb	r0, 2(r30)
    b       _8004abe8
_8004aa38:
    lwz	r0, 0x10(r30)
    cmpwi	r0, 0
    bne     _8004aa5c
    li	r3, 0
    li	r0, 3
    stb	r3, 2(r30)
    stw	r3, 0x1c(r30)
    stb	r0, 1(r30)
    b       _8004abe8
_8004aa5c:
    cmplwi	r31, 0
    beq     _8004aa70
    lwz	r3, 0(r31)
    cmplwi	r3, 0
    bne     _8004aa90
_8004aa70:
    li	r0, 0
    lis     r3, lbl_8017D704@ha
    stb	r0, 2(r30)
    addi	r4, r3, lbl_8017D704@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    b       _8004abe8
_8004aa90:
    lwz	r12, 0x24(r3)
    mr	r3, r31
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r4, 0x3c(r30)
    lwz	r0, 0x18(r30)
    subf	r3, r3, r4
    cmpw	r3, r0
    blt     _8004aac4
    li	r0, 0
    stb	r0, 2(r30)
    b       _8004abe8
_8004aac4:
    lwz	r4, 0(r31)
    mr	r3, r31
    addi	r6, r1, 8
    lwz	r5, 0x14(r30)
    lwz	r12, 0x18(r4)
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r3, 0xc(r1)
    lwz	r4, 0x54(r30)
    srawi	r3, r3, 0xb
    lwz	r0, 0x2c(r30)
    addze	r5, r3
    subf	r3, r4, r0
    cmpw	r5, r3
    bge     _8004ab08
    mr	r3, r5
_8004ab08:
    lwz	r0, 0x10(r30)
    srawi	r0, r0, 0xb
    addze	r0, r0
    subf	r0, r4, r0
    cmpw	r3, r0
    bge     _8004ab24
    mr	r0, r3
_8004ab24:
    lwz	r29, 0x28(r30)
    cmpw	r0, r29
    bge     _8004ab34
    mr	r29, r0
_8004ab34:
    lwz	r0, 0xc(r30)
    li	r5, 0
    lwz	r3, 8(r30)
    add	r4, r0, r4
    bl      cvFsSeek
    lwz	r3, 8(r30)
    mr	r4, r29
    lwz	r5, 8(r1)
    bl      cvFsReqRd
    stw	r3, 0x1c(r30)
    lwz	r0, 8(r1)
    stw	r0, 0x20(r30)
    lwz	r0, 0xc(r1)
    stw	r0, 0x24(r30)
    lwz	r0, 0x1c(r30)
    cmpwi	r0, 0
    bgt     _8004abe8
    lwz	r6, 0(r31)
    mr	r3, r31
    addi	r5, r30, 0x20
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    stw	r0, 0x20(r30)
    stw	r0, 0x24(r30)
    stb	r0, 2(r30)
    lwz	r3, 8(r30)
    bl      cvFsGetStat
    cmpwi	r3, 3
    bne     _8004abe8
    lis	r3, -0x7fe8
    lwz	r4, -0x2900(r3)
    cmpwi	r4, 0
    blt     _8004abe8
    lbz	r3, 3(r30)
    extsb	r0, r3
    cmpw	r0, r4
    blt     _8004abe0
    li	r0, 4
    stb	r0, 1(r30)
    b       _8004abe8
_8004abe0:
    addi	r0, r3, 1
    stb	r0, 3(r30)
_8004abe8:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
