#pragma push
#pragma force_active on

typedef struct AdxtObj {
    unsigned char unk0;
    signed char unk1;
    signed char unk2;
    signed char unk3;
    void* unk4;
    char pad8[4];
    void* unkC;
    char pad10[0x28];
    int unk38;
    char pad3C[4];
    short unk40;
    short unk42[15];
    short unk60;
    char pad62[0xf];
    signed char unk71;
    signed char unk72;
    char pad73[0x4d];
} AdxtObj;

extern void __cvt_fp2unsigned(void);
extern int fn_80041460();
extern int fn_800414D0();
extern int criadx_get_stream_ptr_wrapper();
extern int criadx_set_field_48();
extern int criadxGetValue();
extern void fn_80041700(void);
extern void svmUnlockServer_wrapper(void);
extern void svmLockServer_wrapper(void);
extern int fn_80046C28();
extern void criErr_CallErrCallback();
extern int fn_80047548();
extern void fn_8004C164(void);
extern void ADXT_ExecHndl();
extern void fn_8004ED84(void);
extern void adxtSetHandleVolume();
extern void fn_8004EDE4();
extern void fn_8004EE44(void);
extern void ADXTServerStateRequest_wrapper(void);
extern void svm_ringbuf_read(void);
extern void memset(void);
extern unsigned char E02080817_ADXT_GetNumSmpl_parameter_error_str[100];
extern unsigned char E02080819_ADXT_GetSfreq_parameter_error_str[236];
extern unsigned char E02080820_ADXT_GetNumChan_parameter_error_str[43];
extern unsigned char E02080823_ADXT_SetOutVol_parameter_error_str[140];
extern unsigned char E02080824_ADXT_GetOutVol_parameter_error_str[42];
extern unsigned char E02080825_ADXT_SetOutPan_parameter_error_str[42];
extern unsigned char E02080826_ADXT_GetOutPan_parameter_error_str[42];
extern unsigned char E02080831_ADXT_IsReadyPlayStart_parameter_error_str[284];
extern unsigned char E02080840_ADXT_SetSvrFreq_parameter_error_str[43];
extern unsigned char E02080843_ADXT_GetErrCode_parameter_error_str[196];
extern unsigned char E02080846_ADXT_Pause_parameter_error_str[38];
extern unsigned char E02080847_ADXT_GetStatPause_parameter_error_str[45];
extern unsigned char E8101208_ADXT_SetOutPan_parameter_error_str[132];
extern int lbl_8017E56C[];
extern unsigned char lbl_80090A20[8];
extern unsigned char lbl_80178CB8[4];
extern AdxtObj lbl_80178CBC[];
extern unsigned char lbl_8017E568[4];
extern unsigned char lbl_8017E594[20];

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
    bl      svm_ringbuf_read
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
    bl      svm_ringbuf_read
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

// provenance: original
int fn_8004B974(unsigned short* p, int n, int* out)
{
    if (n < 2) {
        return 0;
    }
    if (p[0] != 0x8001) {
        return 0;
    }
    *out = n;
    return 1;
}

// provenance: original
int fn_8004B9A4(unsigned short* hdr, int size, int* out)
{
    int v20;
    int v1c;
    int v18;
    short v14;
    char c13;
    char c12;
    char c11;
    char c10;

    if (size < 2) {
        return 0;
    }
    if (hdr[0] != 0x8000) {
        return 0;
    }
    if (fn_80046C28(hdr, size, &v14, &c13, &c12, &c11, &c10, &v20, &v1c, &v18) < 0) {
        return 0;
    }
    *out = v14;
    return 1;
}

// provenance: original disassembly reconstruction fn_8004BA38
void fn_8004BA38(void *arg0, int arg1)
{
    *(int *)((char *)arg0 + 0x88) = arg1;
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
    addi	r31, r3, lbl_8017E568@l
    lbz	r0, 0x72(r29)
    extsb.	r0, r0
    bne     _8004ba70
    li	r3, 0
    b       _8004bb90
_8004ba70:
    lwz	r3, 0xc(r29)
    bl      fn_8004ED84
    mr	r30, r3
    bl      svmLockServer_wrapper
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    beq     _8004ba94
    bl      svmUnlockServer_wrapper
    b       _8004baf8
_8004ba94:
    li	r0, 1
    stw	r0, 4(r31)
    bl      svmUnlockServer_wrapper
    bl      svmLockServer_wrapper
    bl      fn_80041700
    li	r0, 2
    lis     r3, lbl_80178CBC@ha
    stw	r0, 4(r31)
    addi	r27, r3, lbl_80178CBC@l
    li	r28, 0
_8004babc:
    lbz	r0, 0(r27)
    cmpwi	r0, 1
    bne     _8004bad0
    mr	r3, r27
    bl      ADXT_ExecHndl
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
    bl      svmUnlockServer_wrapper
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
    lis	r5, lbl_80090A20@ha
    xoris	r3, r3, 0x8000
    stw	r4, 0x18(r1)
    xoris	r0, r0, 0x8000
    lfd	f2, lbl_80090A20@l(r5)
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
    addi	r4, r3, lbl_80178CB8@l
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



// provenance: original
int fn_8004BBA4(void* p)
{
    return fn_80047548(p);
}

// provenance: original fn_8004BBC4 (no-op stub: retail body is a single blr)
void fn_8004BBC4(void)
{
}

// provenance: original fn_8004BBC8 (no-op stub: retail body is a single blr)
void fn_8004BBC8(void)
{
}


// provenance: original
int fn_8004BBCC(AdxtObj* p)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080847_ADXT_GetStatPause_parameter_error_str);
        return 0;
    }
    return p->unk72;
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
    addi	r3, r3, E02080846_ADXT_Pause_parameter_error_str@l
    bl      criErr_CallErrCallback
    b       _8004bd40
_8004bc40:
    lbz	r0, 0x72(r31)
    lbz	r30, 1(r31)
    extsb	r0, r0
    cmpw	r29, r0
    extsb	r30, r30
    beq     _8004bd40
    bl      svmLockServer_wrapper
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
    bl      ADXTServerStateRequest_wrapper
    b       _8004bca0
_8004bc88:
    lwz	r3, 0xc(r31)
    li	r4, 1
    bl      ADXTServerStateRequest_wrapper
    lis     r3, lbl_80178CB8@ha
    lwz	r0, lbl_80178CB8@l(r3)
    stw	r0, 0xa0(r31)
_8004bca0:
    lis	r3, lbl_8017E568@ha
    li	r0, 0
    addi	r6, r3, lbl_8017E568@l
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
    addi	r3, r5, lbl_80090A20@l
    lfd	f2, 0(r3)
    addi	r5, r6, lbl_8017E594@l
    lfd	f0, 0x18(r1)
    lis	r6, lbl_8017E568@ha
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
    stw	r30, lbl_8017E568@l(r6)
    fsubs	f1, f1, f2
    fmuls	f1, f1, f0
    bl      __cvt_fp2unsigned
    stw	r3, 0x9c(r31)
_8004bd3c:
    bl      svmUnlockServer_wrapper
_8004bd40:
    lwz	r0, 0x44(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    lwz	r29, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

// provenance: original
int fn_8004BD5C(AdxtObj* p)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080831_ADXT_IsReadyPlayStart_parameter_error_str);
        return -1;
    }
    return p->unk71;
}

// provenance: original
int fn_8004BD9C(AdxtObj* p)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080843_ADXT_GetErrCode_parameter_error_str);
        return -1;
    }
    return p->unk60;
}

// provenance: original
void fn_8004BDD8(void)
{
    int i;

    svmLockServer_wrapper();
    if (lbl_8017E56C[0] != 0) {
        svmUnlockServer_wrapper();
        return;
    }
    lbl_8017E56C[0] = 1;
    svmUnlockServer_wrapper();

    svmLockServer_wrapper();
    fn_80041700();
    lbl_8017E56C[0] = 2;

    for (i = 0; i < 16; i++) {
        int st = lbl_80178CBC[i].unk0;
        if (st == 1) {
            ADXT_ExecHndl(&lbl_80178CBC[i]);
        }
    }

    lbl_8017E56C[0] = 3;
    fn_8004EE44();
    lbl_8017E56C[0] = 0;
    svmUnlockServer_wrapper();
}

// provenance: original disassembly reconstruction fn_8004BE90
void fn_8004BE90(void *arg0, char arg1)
{
    *(char *)((char *)arg0 + 0x6d) = arg1;
}

// provenance: original
void fn_8004BE98(AdxtObj* p, int freq)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080840_ADXT_SetSvrFreq_parameter_error_str);
        return;
    }
    p->unk38 = freq;
}

// provenance: original
int fn_8004BED0(AdxtObj* p)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080824_ADXT_GetOutVol_parameter_error_str);
        return 0;
    }
    return p->unk40;
}

// provenance: original
void ADXT_SetOutVol(AdxtObj* p, short vol)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080823_ADXT_SetOutVol_parameter_error_str);
        return;
    }
    p->unk40 = vol;
    fn_8004EDE4(p->unkC, p->unk40 + (short)fn_800414D0(p->unk4));
}

// provenance: original
int ADXT_GetOutPan(AdxtObj* p, int ch)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080826_ADXT_GetOutPan_parameter_error_str);
        return 0;
    }
    return p->unk42[ch];
}

// provenance: original
void ADXT_SetOutPan(AdxtObj* p, int ch, int pan)
{
    int v;

    if (p == 0) {
        criErr_CallErrCallback(E02080825_ADXT_SetOutPan_parameter_error_str);
        return;
    }

    v = fn_80041460(p->unk4);
    if ((short)v == -128) {
        v = 0;
    }
    p->unk42[ch] = pan + (short)v;

    if (ch < p->unk3) {
        adxtSetHandleVolume(p->unkC, ch, pan);
    } else {
        criErr_CallErrCallback(E8101208_ADXT_SetOutPan_parameter_error_str);
    }
}

// provenance: original
int ADXT_GetNumChan(AdxtObj* p)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080820_ADXT_GetNumChan_parameter_error_str);
        return -1;
    }
    if (p->unk1 >= 2) {
        return criadx_set_field_48(p->unk4);
    }
    return 0;
}

// provenance: original
int ADXT_GetSfreq(AdxtObj* p)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080819_ADXT_GetSfreq_parameter_error_str);
        return -1;
    }
    if (p->unk1 >= 2) {
        return criadxGetValue(p->unk4);
    }
    return 0;
}

// provenance: original
int ADXT_GetNumSmpl(AdxtObj* p)
{
    if (p == 0) {
        criErr_CallErrCallback(E02080817_ADXT_GetNumSmpl_parameter_error_str);
        return -1;
    }
    if (p->unk1 >= 2) {
        return criadx_get_stream_ptr_wrapper(p->unk4);
    }
    return 0;
}

#pragma pop
