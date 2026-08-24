#pragma push
#pragma force_active on

extern void fn_80041410(void);
extern void fn_80041434(void);
extern void fn_80041458(void);
extern void fn_80041460(void);
extern void fn_800414D0(void);
extern void fn_80041530(void);
extern void fn_80041554(void);
extern void fn_80041578(void);
extern void fn_800415AC(void);
extern void fn_800415D0(void);
extern void criadx_get_stream_ptr_wrapper(void);
extern void fn_80041618(void);
extern void fn_8004163C(void);
extern void criadx_set_field_48(void);
extern void criadxGetValue(void);
extern void fn_800416A8(void);
extern void fn_800416CC(void);
extern void criadx_set_field_40(void);
extern void criadx_set_field_3C(void);
extern void fn_800416E4(void);
extern void fn_800416F0(void);
extern void fn_800416F8(void);
extern void fn_80041990(void);
extern void fn_800420F4(void);
extern void fn_8004212C(void);
extern void fn_8004216C(void);
extern void fn_80042170(void);
extern void fn_800421C0(void);
extern void fn_80042228(void);
extern void fn_80046508(void);
extern void fn_80046804(void);
extern void fn_80046D18(void);
extern void fn_80046F88(void);
extern void adx_err_report(void);
extern void criErr_CallErrCallback(void);
extern void ADXT_GetVoiceByAxHandle(void);
extern void fn_8004AC4C(void);
extern void fn_8004AE94(void);
extern void ADXTGetState(void);
extern void fn_8004B4E0(void);
extern void fn_8004BBC4(void);
extern void fn_8004BBC8(void);
extern void ADXT_GetNumChan(void);
extern void ADXT_GetStat(void);
extern void ADXT_Stop(void);
extern void fn_8004C980(void);
extern void fn_8004CAC8(void);
extern void ADXT_StatDecInfo(void);
extern void adxt_trap_entry_not_enough_data(void);
extern void fn_8004ED5C(void);
extern void fn_8004ED80(void);
extern void fn_8004EDA4(void);
extern void adxtSetHandleVolume(void);
extern void fn_8004EDE4(void);
extern void fn_8004EE04(void);
extern void fn_8004EE24(void);
extern void fn_8004EE64(void);
extern void fn_8004EE84(void);
extern void ADXTServerStateRequest_wrapper(void);
void fn_8004D8DC(void);
void fn_8004DDE4(void);
void fn_8004DFF0(void);
extern void ADXT_GetResourceManager(void);
extern void fn_8004EF28(void);
extern void fn_80056C20(void);
extern void fn_8005710C(void);
extern void fn_800571EC(void);
extern void ADXT_ProcessStreamUpdate(void);
extern void svm_ringbuf_read(void);
extern void strcpy(void);
extern void memset(void);
extern unsigned char E02080804_ADXT_Create_parameter_error_str[39];
extern unsigned char E02080807_ADXT_StartFname_parameter_error_str[43];
extern unsigned char E02080842_ADXT_ExecHndl_parameter_error_str[41];
extern unsigned char E8101201_adxt_trap_entry_not_enough_data_str[42];
extern unsigned char E9081001_adxt_stat_decinfo_can_t_play_this_number_of_channel_str[63];
extern unsigned char lbl_80178CBC[3076];
extern unsigned char lbl_8017E5A8[16];

asm void ADXT_Create(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    addi	r0, r4, 0x3f
    stmw	r27, 0x1c(r1)
    rlwinm	r30, r0, 0, 0, 0x19
    subf	r0, r4, r30
    or.	r28, r3, r3
    subf	r29, r0, r5
    blt     _8004cda8
    cmplwi	r4, 0
    beq     _8004cda8
    cmpwi	r5, 0
    bge     _8004cdbc
_8004cda8:
    lis     r3, E02080804_ADXT_Create_parameter_error_str@ha
    addi	r3, r3, E02080804_ADXT_Create_parameter_error_str@l
    bl      criErr_CallErrCallback
    li	r3, 0
    b       _8004d178
_8004cdbc:
    lis     r3, lbl_80178CBC@ha
    li	r0, 2
    addi	r3, r3, lbl_80178CBC@l
    li	r4, 0
    mtctr	r0
_8004cdd0:
    lbz	r0, 0(r3)
    extsb.	r0, r0
    beq     _8004ce74
    lbz	r0, 0xc0(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc0
    extsb.	r0, r0
    beq     _8004ce74
    lbz	r0, 0xc0(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc0
    extsb.	r0, r0
    beq     _8004ce74
    lbz	r0, 0xc0(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc0
    extsb.	r0, r0
    beq     _8004ce74
    lbz	r0, 0xc0(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc0
    extsb.	r0, r0
    beq     _8004ce74
    lbz	r0, 0xc0(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc0
    extsb.	r0, r0
    beq     _8004ce74
    lbz	r0, 0xc0(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc0
    extsb.	r0, r0
    beq     _8004ce74
    lbz	r0, 0xc0(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc0
    extsb.	r0, r0
    beq     _8004ce74
    addi	r3, r3, 0xc0
    addi	r4, r4, 1
    bdnz    _8004cdd0
_8004ce74:
    cmpwi	r4, 0x10
    bne     _8004ce84
    li	r3, 0
    b       _8004d178
_8004ce84:
    mulli	r5, r4, 0xc0
    lis     r3, lbl_80178CBC@ha
    li	r4, 0
    addi	r0, r3, lbl_80178CBC@l
    add	r31, r0, r5
    li	r5, 0xc0
    mr	r3, r31
    bl      memset
    mulli	r0, r28, 0x3060
    stb	r28, 3(r31)
    li	r5, 0x24
    li	r4, 0x2000
    slwi	r7, r0, 1
    li	r3, 0x2060
    subf	r6, r7, r29
    li	r0, 0
    addi	r6, r6, -0x124
    add	r7, r30, r7
    srawi	r6, r6, 0xb
    stw	r7, 0x20(r31)
    addze	r6, r6
    slwi	r6, r6, 0xb
    stw	r6, 0x24(r31)
    stw	r5, 0x28(r31)
    lwz	r7, 0x20(r31)
    lwz	r5, 0x28(r31)
    lwz	r6, 0x24(r31)
    add	r5, r5, r7
    add	r5, r6, r5
    stw	r5, 0xac(r31)
    stw	r30, 0x2c(r31)
    stw	r4, 0x30(r31)
    stw	r3, 0x34(r31)
    stw	r0, 0x14(r31)
    lwz	r3, 0x20(r31)
    lwz	r4, 0x24(r31)
    lwz	r5, 0x28(r31)
    bl      ADXT_ProcessStreamUpdate
    stw	r3, 0x10(r31)
    lwz	r3, 0x10(r31)
    cmplwi	r3, 0
    bne     _8004cf3c
    mr	r3, r31
    bl      fn_8004CAC8
    li	r3, 0
    b       _8004d178
_8004cf3c:
    li	r4, 0
    bl      fn_8004B4E0
    cmplwi	r3, 0
    stw	r3, 8(r31)
    bne     _8004cf60
    mr	r3, r31
    bl      fn_8004CAC8
    li	r3, 0
    b       _8004d178
_8004cf60:
    mr	r29, r31
    li	r27, 0
    b       _8004cfbc
_8004cf6c:
    lwz	r0, 0x34(r31)
    lwz	r4, 0x30(r31)
    mullw	r3, r0, r27
    lwz	r6, 0x2c(r31)
    subf	r0, r4, r0
    slwi	r4, r4, 1
    slwi	r5, r0, 1
    slwi	r0, r3, 1
    add	r3, r6, r0
    bl      ADXT_ProcessStreamUpdate
    stw	r3, 0x18(r29)
    lwz	r0, 0x18(r29)
    cmplwi	r0, 0
    bne     _8004cfb4
    mr	r3, r31
    bl      fn_8004CAC8
    li	r3, 0
    b       _8004d178
_8004cfb4:
    addi	r29, r29, 4
    addi	r27, r27, 1
_8004cfbc:
    cmpw	r27, r28
    blt     _8004cf6c
    lwz	r3, 0x10(r31)
    mr	r4, r28
    addi	r5, r31, 0x18
    bl      fn_80042228
    cmplwi	r3, 0
    stw	r3, 4(r31)
    bne     _8004cff0
    mr	r3, r31
    bl      fn_8004CAC8
    li	r3, 0
    b       _8004d178
_8004cff0:
    mulli	r0, r28, 0x40c0
    mr	r4, r28
    addi	r3, r31, 0x18
    add	r5, r30, r0
    bl      fn_8004EF28
    cmplwi	r3, 0
    stw	r3, 0xc(r31)
    bne     _8004d020
    mr	r3, r31
    bl      fn_8004CAC8
    li	r3, 0
    b       _8004d178
_8004d020:
    lwz	r3, 0x10(r31)
    bl      fn_800571EC
    cmplwi	r3, 0
    stw	r3, 0x94(r31)
    bne     _8004d044
    mr	r3, r31
    bl      fn_8004CAC8
    li	r3, 0
    b       _8004d178
_8004d044:
    lwz	r3, 0x94(r31)
    lwz	r4, 8(r31)
    bl      fn_8005710C
    li	r3, 0x3c
    lis	r0, 0x4330
    stw	r3, 0x38(r31)
    lis	r3, -0x7ff7
    lis	r4, -0x7ff7
    lfd	f1, 0xa20(r3)
    lwz	r5, 0x24(r31)
    li	r6, 0
    stw	r0, 8(r1)
    cmpwi	r28, 0
    srawi	r0, r5, 0xb
    lfs	f2, 0x1064(r4)
    addze	r0, r0
    sth	r0, 0x3c(r31)
    lha	r0, 0x3c(r31)
    xoris	r0, r0, 0x8000
    stw	r0, 0xc(r1)
    lfd	f0, 8(r1)
    fsubs	f0, f0, f1
    fmuls	f0, f2, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    sth	r0, 0x3e(r31)
    sth	r6, 0x40(r31)
    ble     _8004d134
    cmpwi	r28, 8
    addi	r4, r28, -8
    ble     _8004d10c
    addi	r0, r4, 7
    mr	r5, r31
    srwi	r0, r0, 3
    li	r3, -0x80
    mtctr	r0
    cmpwi	r4, 0
    ble     _8004d10c
_8004d0e0:
    sth	r3, 0x42(r5)
    addi	r6, r6, 8
    sth	r3, 0x44(r5)
    sth	r3, 0x46(r5)
    sth	r3, 0x48(r5)
    sth	r3, 0x4a(r5)
    sth	r3, 0x4c(r5)
    sth	r3, 0x4e(r5)
    sth	r3, 0x50(r5)
    addi	r5, r5, 0x10
    bdnz    _8004d0e0
_8004d10c:
    slwi	r3, r6, 1
    subf	r0, r6, r28
    add	r4, r31, r3
    li	r3, -0x80
    mtctr	r0
    cmpw	r6, r28
    bge     _8004d134
_8004d128:
    sth	r3, 0x42(r4)
    addi	r4, r4, 2
    bdnz    _8004d128
_8004d134:
    li	r4, 0
    li	r0, 1
    sth	r4, 0x46(r31)
    mr	r3, r31
    stb	r0, 0x6c(r31)
    stw	r4, 0x54(r31)
    stw	r4, 0x58(r31)
    stw	r4, 0x5c(r31)
    sth	r4, 0x60(r31)
    stw	r4, 0x64(r31)
    sth	r4, 0x68(r31)
    sth	r4, 0x6a(r31)
    stb	r0, 0x6d(r31)
    stb	r4, 0x72(r31)
    stw	r4, 0x88(r31)
    stb	r4, 0x98(r31)
    stb	r0, 0(r31)
_8004d178:
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void ADXT_StartFname(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r4
    stw	r30, 8(r1)
    or.	r30, r3, r3
    beq     _8004d1b4
    cmplwi	r31, 0
    bne     _8004d1c4
_8004d1b4:
    lis     r3, E02080807_ADXT_StartFname_parameter_error_str@ha
    addi	r3, r3, E02080807_ADXT_StartFname_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004d208
_8004d1c4:
    bl      ADXT_Stop
    lwz	r3, 0xac(r30)
    mr	r4, r31
    bl      strcpy
    lwz	r5, 0xac(r30)
    lis	r3, 0x10
    li	r4, 0
    li	r0, 1
    stw	r5, 0xb0(r30)
    addi	r3, r3, -1
    stw	r4, 0xb4(r30)
    stw	r4, 0xb8(r30)
    stw	r3, 0xbc(r30)
    stb	r0, 1(r30)
    stb	r0, 0xa8(r30)
    stb	r4, 2(r30)
    stb	r4, 0x98(r30)
_8004d208:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ADXT_ExecHndl(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r4, lbl_8017E5A8@ha
    stw	r0, 0x34(r1)
    stmw	r26, 0x18(r1)
    or.	r31, r3, r3
    addi	r30, r4, lbl_8017E5A8@l
    bne     _8004d250
    lis     r3, E02080842_ADXT_ExecHndl_parameter_error_str@ha
    addi	r3, r3, E02080842_ADXT_ExecHndl_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004d514
_8004d250:
    lbz	r0, 1(r31)
    extsb	r0, r0
    cmpwi	r0, 3
    bne     _8004d2e0
    lwz	r3, 4(r31)
    bl      fn_800421C0
    cmpwi	r3, 3
    bne     _8004d460
    lwz	r3, 4(r31)
    bl      criadx_set_field_48
    mr	r29, r3
    mr	r27, r31
    stw	r29, 8(r30)
    li	r28, 0
    b       _8004d2b8
_8004d28c:
    lwz	r3, 0x18(r27)
    li	r4, 1
    lwz	r5, 0(r3)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    cmpwi	r3, 0x40
    stw	r3, 4(r30)
    bge     _8004d2c0
    addi	r27, r27, 4
    addi	r28, r28, 1
_8004d2b8:
    cmpw	r28, r29
    blt     _8004d28c
_8004d2c0:
    cmpw	r28, r29
    bne     _8004d460
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      ADXT_GetResourceManager
    li	r0, 4
    stb	r0, 1(r31)
    b       _8004d460
_8004d2e0:
    cmpwi	r0, 1
    bne     _8004d2f0
    bl      ADXT_StatDecInfo
    b       _8004d460
_8004d2f0:
    cmpwi	r0, 2
    bne     _8004d428
    lwz	r28, 0xc(r31)
    lwz	r27, 4(r31)
    mr	r3, r28
    bl      fn_8004EE84
    mr	r29, r3
    mr	r3, r28
    bl      fn_8004EE64
    lwz	r0, 0x48(r31)
    mr	r30, r3
    slwi	r0, r0, 1
    cmpw	r29, r0
    bge     _8004d348
    mr	r3, r27
    bl      fn_80041618
    cmpw	r30, r3
    ble     _8004d348
    lwz	r3, 4(r31)
    bl      fn_800421C0
    cmpwi	r3, 3
    bne     _8004d390
_8004d348:
    lbz	r0, 0x70(r31)
    extsb.	r0, r0
    bne     _8004d388
    lbz	r0, 0x72(r31)
    extsb.	r0, r0
    bne     _8004d380
    mr	r3, r28
    li	r4, 1
    bl      ADXTServerStateRequest_wrapper
    li	r0, 0
    lis	r3, -0x7fe8
    stw	r0, 0x9c(r31)
    lwz	r0, -0x7348(r3)
    stw	r0, 0xa0(r31)
_8004d380:
    li	r0, 3
    stb	r0, 1(r31)
_8004d388:
    li	r0, 1
    stb	r0, 0x71(r31)
_8004d390:
    lwz	r3, 4(r31)
    bl      fn_800421C0
    cmpwi	r3, 3
    bne     _8004d460
    mr	r3, r31
    bl      ADXT_GetNumChan
    lwz	r0, 0x48(r31)
    mr	r30, r3
    mr	r26, r31
    li	r27, 0
    mullw	r0, r0, r30
    slwi	r29, r0, 1
    b       _8004d41c
_8004d3c4:
    lwz	r28, 0x18(r26)
    mr	r5, r29
    addi	r6, r1, 8
    li	r4, 0
    lwz	r7, 0(r28)
    mr	r3, r28
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r3, 8(r1)
    li	r4, 0
    lwz	r5, 0xc(r1)
    bl      memset
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 8
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    addi	r26, r26, 4
    addi	r27, r27, 1
_8004d41c:
    cmpw	r27, r30
    blt     _8004d3c4
    b       _8004d460
_8004d428:
    cmpwi	r0, 4
    bne     _8004d460
    lwz	r3, 0xc(r31)
    bl      fn_8004EE84
    stw	r3, 0(r30)
    lwz	r3, 0xc(r31)
    bl      fn_8004EE84
    cmpwi	r3, 0
    bgt     _8004d460
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      ADXTServerStateRequest_wrapper
    li	r0, 5
    stb	r0, 1(r31)
_8004d460:
    lwz	r0, 8(r31)
    cmplwi	r0, 0
    beq     _8004d4c4
    mr	r3, r31
    bl      ADXT_GetStat
    cmpwi	r3, 0
    beq     _8004d4c4
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpwi	r0, 2
    beq     _8004d4bc
    bge     _8004d4c4
    cmpwi	r0, 0
    bge     _8004d4a0
    b       _8004d4c4
    b       _8004d4c4
_8004d4a0:
    lwz	r3, 8(r31)
    bl      ADXTGetState
    cmpwi	r3, 3
    bne     _8004d4c4
    lwz	r3, 4(r31)
    bl      fn_8004216C
    b       _8004d4c4
_8004d4bc:
    lwz	r3, 4(r31)
    bl      fn_8004216C
_8004d4c4:
    lwz	r3, 8(r31)
    cmplwi	r3, 0
    beq     _8004d4ec
    bl      ADXTGetState
    cmpwi	r3, 4
    bne     _8004d4ec
    li	r3, -1
    li	r0, 6
    sth	r3, 0x60(r31)
    stb	r0, 1(r31)
_8004d4ec:
    lwz	r3, 0x94(r31)
    cmplwi	r3, 0
    beq     _8004d514
    bl      fn_80056C20
    cmpwi	r3, 3
    bne     _8004d514
    li	r3, -1
    li	r0, 6
    sth	r3, 0x60(r31)
    stb	r0, 1(r31)
_8004d514:
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void ADXT_StatDecInfo(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    li	r0, 0
    stmw	r27, 0x3c(r1)
    mr	r30, r3
    lwz	r31, 4(r3)
    stw	r0, 0xc(r1)
    stw	r0, 8(r1)
    lbz	r3, 2(r3)
    extsb.	r0, r3
    beq     _8004d564
    extsb	r0, r3
    cmpwi	r0, 1
    bne     _8004d5bc
_8004d564:
    lbz	r0, 0xa8(r30)
    cmpwi	r0, 1
    bne     _8004d5bc
    lwz	r3, 8(r30)
    bl      ADXTGetState
    cmpwi	r3, 2
    beq     _8004d8c8
    lwz	r3, 0x10(r30)
    cmplwi	r3, 0
    beq     _8004d59c
    lwz	r4, 0(r3)
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
_8004d59c:
    lwz	r4, 0xb0(r30)
    mr	r3, r30
    lwz	r5, 0xb4(r30)
    lwz	r6, 0xb8(r30)
    lwz	r7, 0xbc(r30)
    bl      fn_8004C980
    li	r0, 0
    stb	r0, 0xa8(r30)
_8004d5bc:
    mr	r3, r31
    bl      fn_800421C0
    cmpwi	r3, 2
    bne     _8004d8c8
    mr	r3, r31
    bl      criadx_set_field_48
    lbz	r0, 3(r30)
    extsb	r4, r0
    cmpw	r3, r4
    ble     _8004d60c
    addi	r5, r1, 0x10
    li	r6, 0x10
    bl      fn_80046F88
    lis     r3, E9081001_adxt_stat_decinfo_can_t_play_this_number_of_channel_str@ha
    addi	r4, r1, 0x10
    addi	r3, r3, E9081001_adxt_stat_decinfo_can_t_play_this_number_of_channel_str@l
    bl      adx_err_report
    mr	r3, r30
    bl      ADXT_Stop
    b       _8004d8c8
_8004d60c:
    mr	r3, r31
    bl      criadxGetValue
    mr	r28, r3
    mr	r3, r31
    bl      fn_800415D0
    or.	r29, r3, r3
    ble     _8004d63c
    lwz	r0, 0x38(r30)
    divw	r0, r28, r0
    mulli	r0, r0, 3
    stw	r0, 0x48(r30)
    b       _8004d658
_8004d63c:
    lwz	r0, 0x38(r30)
    divw	r0, r28, r0
    mulli	r3, r0, 3
    srwi	r0, r3, 0x1f
    add	r0, r0, r3
    srawi	r0, r0, 1
    stw	r0, 0x48(r30)
_8004d658:
    mr	r3, r31
    bl      fn_80041618
    lwz	r0, 0x48(r30)
    slwi	r4, r3, 1
    mr	r3, r31
    add	r0, r0, r4
    divw	r0, r0, r4
    mullw	r0, r4, r0
    stw	r0, 0x48(r30)
    lwz	r4, 0x48(r30)
    bl      fn_80042170
    cmpwi	r29, 0
    ble     _8004d760
    lbz	r0, 2(r30)
    cmpwi	r0, 2
    bne     _8004d6a4
    li	r0, 0
    stw	r0, 0x50(r30)
    b       _8004d710
_8004d6a4:
    mr	r3, r31
    bl      fn_80041530
    slwi	r0, r3, 0x15
    srwi	r5, r3, 0x1f
    subf	r4, r5, r0
    addi	r0, r3, 0x7ff
    rotlwi	r3, r4, 0xb
    add	r3, r3, r5
    subfic	r3, r3, 0x800
    stw	r3, 0x50(r30)
    srawi	r0, r0, 0xb
    addze	r4, r0
    lwz	r3, 0x50(r30)
    slwi	r0, r3, 0x15
    srwi	r3, r3, 0x1f
    subf	r0, r3, r0
    rotlwi	r0, r0, 0xb
    add	r0, r0, r3
    stw	r0, 0x50(r30)
    stw	r4, 0x8c(r30)
    lwz	r3, 8(r30)
    bl      ADXT_GetVoiceByAxHandle
    lis     r4, fn_8004DDE4@ha
    lwz	r3, 8(r30)
    addi	r4, r4, fn_8004DDE4@l
    mr	r5, r30
    bl      fn_8004AC4C
_8004d710:
    mr	r3, r31
    bl      fn_80041554
    mr	r3, r31
    bl      fn_800415AC
    stw	r3, 0x90(r30)
    mr	r3, r31
    lwz	r4, 0x90(r30)
    bl      criadx_set_field_3C
    mr	r3, r31
    li	r4, 0
    bl      fn_800416CC
    mr	r3, r31
    li	r4, 0
    bl      criadx_set_field_40
    lis     r4, fn_8004DFF0@ha
    mr	r3, r31
    addi	r4, r4, fn_8004DFF0@l
    mr	r5, r30
    bl      fn_800416E4
    b       _8004d7b8
_8004d760:
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8004d778
    lis	r4, -0x8000
    addi	r4, r4, -1
    bl      ADXT_GetVoiceByAxHandle
_8004d778:
    mr	r3, r31
    bl      criadx_get_stream_ptr_wrapper
    mr	r4, r3
    mr	r3, r31
    bl      criadx_set_field_3C
    mr	r3, r31
    li	r4, 0
    bl      fn_800416CC
    mr	r3, r31
    li	r4, 0
    bl      criadx_set_field_40
    lis     r4, fn_8004D8DC@ha
    mr	r3, r31
    addi	r4, r4, fn_8004D8DC@l
    mr	r5, r30
    bl      fn_800416E4
_8004d7b8:
    mr	r3, r31
    bl      criadxGetValue
    mr	r29, r3
    mr	r3, r31
    bl      criadx_set_field_48
    mr	r28, r3
    mr	r3, r31
    bl      criadx_get_stream_ptr_wrapper
    mr	r0, r3
    mr	r3, r31
    mr	r27, r0
    bl      fn_8004163C
    mr	r0, r3
    lwz	r3, 0xc(r30)
    mr	r4, r0
    bl      fn_8004EDA4
    lwz	r3, 0xc(r30)
    mr	r4, r29
    bl      fn_8004EE04
    lwz	r3, 0xc(r30)
    mr	r4, r28
    bl      fn_8004EE24
    lwz	r3, 0xc(r30)
    mr	r4, r27
    bl      fn_8004ED80
    lwz	r3, 4(r30)
    bl      fn_800414D0
    lha	r0, 0x40(r30)
    extsh	r4, r3
    lwz	r3, 0xc(r30)
    add	r4, r0, r4
    bl      fn_8004EDE4
    mr	r3, r30
    addi	r4, r1, 0xc
    addi	r5, r1, 8
    bl      fn_8004BBC4
    lwz	r0, 0xc(r1)
    cmpwi	r0, 0
    bne     _8004d860
    lwz	r0, 8(r1)
    cmpwi	r0, 0
    beq     _8004d870
_8004d860:
    lwz	r4, 0xc(r1)
    mr	r3, r30
    lwz	r5, 8(r1)
    bl      fn_8004BBC8
_8004d870:
    mr	r3, r30
    bl      adxt_trap_entry_not_enough_data
    lwz	r3, 0x74(r30)
    cmplwi	r3, 0
    beq     _8004d88c
    mr	r4, r29
    bl      fn_80046508
_8004d88c:
    mr	r3, r31
    bl      fn_800416A8
    cmpwi	r3, 2
    bne     _8004d8b4
    mr	r3, r31
    bl      fn_80041458
    mr	r0, r3
    lwz	r3, 0xc(r30)
    mr	r4, r0
    bl      fn_8004ED5C
_8004d8b4:
    lwz	r3, 0xc(r30)
    li	r4, 1
    bl      ADXT_GetResourceManager
    li	r0, 2
    stb	r0, 1(r30)
_8004d8c8:
    lmw	r27, 0x3c(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_8004D8DC(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stmw	r26, 0x38(r1)
    mr	r29, r3
    lbz	r0, 0x98(r3)
    lwz	r31, 4(r3)
    extsb.	r0, r0
    lwz	r30, 0x14(r3)
    beq     _8004dba8
    li	r0, 0
    lis	r4, -0x8000
    sth	r0, 8(r1)
    mr	r3, r30
    addi	r5, r4, -1
    addi	r6, r1, 0x24
    lwz	r7, 0(r30)
    li	r4, 1
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r4, 0(r30)
    lis	r5, -0x8000
    mr	r3, r30
    addi	r6, r1, 0x14
    lwz	r12, 0x18(r4)
    addi	r5, r5, -1
    li	r4, 1
    mtctr	r12
    bctrl	
    lwz	r3, 0x24(r1)
    addi	r5, r1, 0xa
    lwz	r4, 0x28(r1)
    bl      fn_80046804
    cmpwi	r3, 0
    beq     _8004d9b0
    li	r0, 0
    mr	r3, r30
    stb	r0, 0x98(r29)
    addi	r5, r1, 0x14
    li	r4, 1
    lwz	r6, 0(r30)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x24
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _8004dba8
_8004d9b0:
    lha	r27, 0xa(r1)
    addi	r5, r1, 0xa
    lwz	r3, 0x24(r1)
    lwz	r0, 0x28(r1)
    add	r3, r3, r27
    subf	r4, r27, r0
    bl      fn_80046D18
    or.	r28, r3, r3
    bne     _8004d9dc
    li	r3, -1
    b       _8004d9ec
_8004d9dc:
    lwz	r3, 0x14(r1)
    addi	r5, r1, 8
    lwz	r4, 0x18(r1)
    bl      fn_80046D18
_8004d9ec:
    lha	r4, 0xa(r1)
    cmpwi	r28, 0
    lha	r26, 8(r1)
    add	r27, r27, r4
    beq     _8004da4c
    cmpwi	r3, 0
    beq     _8004da4c
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x14
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x24
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    li	r0, 0
    stb	r0, 0x98(r29)
    b       _8004dba8
_8004da4c:
    cmpwi	r28, 0
    bne     _8004dac0
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x14
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r3, r1, 0x24
    mr	r4, r27
    mr	r5, r3
    addi	r6, r1, 0x1c
    bl      svm_ringbuf_read
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x24
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x1c
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _8004db28
_8004dac0:
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x24
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    addi	r3, r1, 0x14
    mr	r4, r26
    mr	r5, r3
    addi	r6, r1, 0xc
    bl      svm_ringbuf_read
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0x14
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 0xc
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
_8004db28:
    mr	r3, r31
    bl      fn_800416F8
    lwz	r0, 0xa4(r29)
    add	r0, r0, r3
    mr	r3, r31
    stw	r0, 0xa4(r29)
    bl      fn_800420F4
    mr	r3, r31
    bl      fn_8004212C
    mr	r3, r31
    bl      fn_80041990
    mr	r3, r31
    bl      fn_800421C0
    cmpwi	r3, 2
    beq     _8004db70
    li	r0, 0
    stb	r0, 0x98(r29)
    b       _8004dba8
_8004db70:
    lwz	r4, 0x48(r29)
    mr	r3, r31
    bl      fn_80042170
    mr	r3, r31
    bl      criadx_get_stream_ptr_wrapper
    mr	r4, r3
    mr	r3, r31
    bl      criadx_set_field_3C
    mr	r3, r31
    li	r4, 0
    bl      fn_800416CC
    mr	r3, r31
    li	r4, 0
    bl      criadx_set_field_40
_8004dba8:
    lmw	r26, 0x38(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void adxt_trap_entry_not_enough_data(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    lwz	r3, 4(r3)
    bl      criadx_set_field_48
    mr	r30, r3
    addi	r29, r1, 8
    li	r28, 0
_8004dbf0:
    lwz	r3, 4(r31)
    mr	r4, r28
    bl      fn_80041460
    addi	r28, r28, 1
    extsh	r0, r3
    cmpwi	r28, 2
    stw	r0, 0(r29)
    addi	r29, r29, 4
    blt     _8004dbf0
    cmpwi	r30, 1
    bne     _8004dcac
    lha	r5, 0x42(r31)
    cmpwi	r5, -0x80
    bne     _8004dc48
    lwz	r0, 8(r1)
    cmpwi	r0, -0x80
    bne     _8004dc48
    lwz	r3, 0xc(r31)
    li	r4, 0
    li	r5, 0
    bl      adxtSetHandleVolume
    b       _8004ddc4
_8004dc48:
    cmpwi	r5, -0x80
    beq     _8004dc6c
    lwz	r0, 8(r1)
    cmpwi	r0, -0x80
    bne     _8004dc6c
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      adxtSetHandleVolume
    b       _8004ddc4
_8004dc6c:
    cmpwi	r5, -0x80
    bne     _8004dc94
    lwz	r0, 8(r1)
    cmpwi	r0, -0x80
    beq     _8004dc94
    lwz	r3, 0xc(r31)
    mr	r5, r0
    li	r4, 0
    bl      adxtSetHandleVolume
    b       _8004ddc4
_8004dc94:
    lwz	r0, 8(r1)
    li	r4, 0
    lwz	r3, 0xc(r31)
    add	r5, r5, r0
    bl      adxtSetHandleVolume
    b       _8004ddc4
_8004dcac:
    lha	r5, 0x42(r31)
    cmpwi	r5, -0x80
    bne     _8004dcd8
    lwz	r0, 8(r1)
    cmpwi	r0, -0x80
    bne     _8004dcd8
    lwz	r3, 0xc(r31)
    li	r4, 0
    li	r5, -0xf
    bl      adxtSetHandleVolume
    b       _8004dd38
_8004dcd8:
    cmpwi	r5, -0x80
    beq     _8004dcfc
    lwz	r0, 8(r1)
    cmpwi	r0, -0x80
    bne     _8004dcfc
    lwz	r3, 0xc(r31)
    li	r4, 0
    bl      adxtSetHandleVolume
    b       _8004dd38
_8004dcfc:
    cmpwi	r5, -0x80
    bne     _8004dd24
    lwz	r0, 8(r1)
    cmpwi	r0, -0x80
    beq     _8004dd24
    lwz	r3, 0xc(r31)
    mr	r5, r0
    li	r4, 0
    bl      adxtSetHandleVolume
    b       _8004dd38
_8004dd24:
    lwz	r0, 8(r1)
    li	r4, 0
    lwz	r3, 0xc(r31)
    add	r5, r5, r0
    bl      adxtSetHandleVolume
_8004dd38:
    lha	r5, 0x44(r31)
    cmpwi	r5, -0x80
    bne     _8004dd64
    lwz	r0, 0xc(r1)
    cmpwi	r0, -0x80
    bne     _8004dd64
    lwz	r3, 0xc(r31)
    li	r4, 1
    li	r5, 0xf
    bl      adxtSetHandleVolume
    b       _8004ddc4
_8004dd64:
    cmpwi	r5, -0x80
    beq     _8004dd88
    lwz	r0, 0xc(r1)
    cmpwi	r0, -0x80
    bne     _8004dd88
    lwz	r3, 0xc(r31)
    li	r4, 1
    bl      adxtSetHandleVolume
    b       _8004ddc4
_8004dd88:
    cmpwi	r5, -0x80
    bne     _8004ddb0
    lwz	r0, 0xc(r1)
    cmpwi	r0, -0x80
    beq     _8004ddb0
    lwz	r3, 0xc(r31)
    mr	r5, r0
    li	r4, 1
    bl      adxtSetHandleVolume
    b       _8004ddc4
_8004ddb0:
    lwz	r0, 0xc(r1)
    li	r4, 1
    lwz	r3, 0xc(r31)
    add	r5, r5, r0
    bl      adxtSetHandleVolume
_8004ddc4:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004DDE4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r31, 8(r3)
    lwz	r3, 4(r3)
    cmplwi	r31, 0
    beq     _8004de58
    cmplwi	r3, 0
    bne     _8004de18
    b       _8004de58
_8004de18:
    bl      fn_80041578
    lbz	r0, 0x6c(r30)
    extsb.	r0, r0
    bne     _8004de48
    lwz	r3, 4(r30)
    li	r4, -1
    bl      criadx_set_field_3C
    lis	r4, -0x8000
    lwz	r3, 8(r30)
    addi	r4, r4, -1
    bl      ADXT_GetVoiceByAxHandle
    b       _8004de58
_8004de48:
    srawi	r0, r3, 0xb
    mr	r3, r31
    addze	r4, r0
    bl      fn_8004AE94
_8004de58:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004DE70(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r26, 0x18(r1)
    mr	r28, r3
    lwz	r31, 4(r3)
    lwz	r30, 0x14(r3)
    mr	r3, r31
    bl      fn_800415AC
    mr	r0, r3
    mr	r3, r31
    mr	r26, r0
    bl      fn_80041578
    mr	r0, r3
    mr	r3, r31
    mr	r29, r0
    bl      fn_80041554
    lwz	r0, 8(r28)
    mr	r27, r3
    cmplwi	r0, 0
    bne     _8004dee0
    lbz	r0, 0x6c(r28)
    extsb.	r0, r0
    bne     _8004dee0
    lwz	r3, 4(r28)
    li	r4, -1
    bl      criadx_set_field_3C
    b       _8004dfdc
_8004dee0:
    lwz	r4, 0(r30)
    mr	r3, r30
    addi	r6, r1, 8
    lwz	r5, 0x50(r28)
    lwz	r12, 0x18(r4)
    li	r4, 1
    mtctr	r12
    bctrl	
    lwz	r3, 0xc(r1)
    lwz	r0, 0x50(r28)
    cmpw	r3, r0
    bge     _8004df1c
    lis     r3, E8101201_adxt_trap_entry_not_enough_data_str@ha
    addi	r3, r3, E8101201_adxt_trap_entry_not_enough_data_str@l
    bl      criErr_CallErrCallback
_8004df1c:
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    mr	r3, r31
    li	r4, 0
    bl      criadx_set_field_40
    subf	r4, r26, r27
    mr	r3, r31
    stw	r4, 0x90(r28)
    bl      criadx_set_field_3C
    mr	r3, r31
    mr	r4, r29
    bl      fn_800416CC
    mr	r3, r31
    mr	r4, r26
    bl      fn_800416F0
    lbz	r0, 2(r28)
    cmpwi	r0, 2
    bne     _8004dfc8
    lwz	r4, 0(r30)
    mr	r3, r30
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
    lwz	r4, 0(r30)
    mr	r3, r30
    mr	r5, r29
    addi	r6, r1, 8
    lwz	r12, 0x18(r4)
    li	r4, 1
    mtctr	r12
    bctrl	
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_8004dfc8:
    mr	r3, r31
    bl      fn_80041410
    lwz	r3, 0x4c(r28)
    addi	r0, r3, 1
    stw	r0, 0x4c(r28)
_8004dfdc:
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8004DFF0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r30, r3
    lwz	r29, 4(r3)
    mr	r3, r29
    bl      fn_800415AC
    mr	r0, r3
    mr	r3, r29
    mr	r28, r0
    bl      fn_80041578
    mr	r0, r3
    mr	r3, r29
    mr	r27, r0
    bl      fn_80041554
    mr	r31, r3
    mr	r3, r29
    bl      fn_80041434
    mr	r3, r29
    li	r4, 0
    bl      criadx_set_field_40
    subf	r4, r28, r31
    mr	r3, r29
    stw	r4, 0x90(r30)
    bl      criadx_set_field_3C
    mr	r3, r29
    mr	r4, r27
    bl      fn_800416CC
    mr	r3, r29
    mr	r4, r28
    bl      fn_800416F0
    lis     r4, fn_8004DE70@ha
    mr	r3, r29
    addi	r4, r4, fn_8004DE70@l
    mr	r5, r30
    bl      fn_800416E4
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
