#pragma push
#pragma force_active on

typedef struct AdxHandle {
    char pad0[1];
    signed char unk1;
    char pad2[1];
    signed char unk3;
    char pad4[0x28];
    int unk2C;
    int unk30;
    char pad34[8];
    int unk3C;
    char pad40[0x40];
    void* unk80;
    void* unk84;
} AdxHandle;

typedef struct AdxErr {
    void (*cb)();
    void* arg;
    char pad8[0x20];
    char msg[0x100];
} AdxErr;

typedef struct AdxSlot {
    unsigned char unk0;
    char pad1[0x2ef];
} AdxSlot;

extern void strncpy();
extern void __msl_strncat();
extern void svmErrPrintf(char* fmt, ...);
extern void fn_80058EF4();
extern void memset();
extern void svmLockServer_wrapper(void);
extern void svmUnlockServer_wrapper(void);
extern void fn_8004A578(void);
extern void fn_80054760(void);
extern void fn_8004FAA8(void);
extern void fn_800482FC();
extern void ADXT_ProcessStreamUpdate(void);
extern void fn_80057B9C(void);
extern void fn_80047C94(void);
extern void fn_80047ADC();
extern void fn_80047B04(void);
extern void fn_80047864();
extern void memcpy(void);
extern void fn_80047AF8();
extern void fn_80047C08();
extern void fn_800482B8();
extern void fn_800478C0();
extern void fn_80048340(void);
extern void CRI_SPSD_parser(void);
extern void fn_80047A50();
extern int fn_80049958();
extern int fn_80049728();
extern void criax_cri_tag_padsize(void);
extern int lbl_8017B034[];
extern int lbl_8017B158[];
extern int lbl_8017B030[];
extern unsigned char lbl_8017B160[64];
extern unsigned char lbl_8017B1A0[1024];
extern int lbl_8017B5A0[];
extern unsigned char lbl_8017B5A8[2512];
extern AdxSlot lbl_8017BF78[8];

// provenance: original
void adx_err_report(char* s1, char* s2)
{
    AdxErr* e = (AdxErr*)lbl_8017B030;

    strncpy(e->msg, s1, 0xFF);
    __msl_strncat(e->msg, s2, 0xFF);
    if (e->cb != 0) {
        e->cb(e->arg, e->msg);
    }
    svmErrPrintf(e->msg);
}

// provenance: original
void criErr_CallErrCallback(char* s)
{
    AdxErr* e = (AdxErr*)lbl_8017B030;

    strncpy(e->msg, s, 0xFF);
    if (e->cb != 0) {
        e->cb(e->arg, e->msg);
    }
    svmErrPrintf(e->msg);
}

// provenance: original
void fn_80047548(int r3, int r4)
{
    lbl_8017B030[0] = r3;
    lbl_8017B034[0] = r4;
    fn_80058EF4();
}

// provenance: original
void fn_80047578(void)
{
    int* p = (int*)lbl_8017B030;
    memset((char*)p + 0x28, 0, 0x100);
    p[0] = 0;
    p[1] = 0;
}

// provenance: original
void fn_800475C0(void)
{
    int* p = (int*)lbl_8017B030;
    memset((char*)p + 0x28, 0, 0x100);
    p[0] = 0;
    p[1] = 0;
}

// provenance: original
void fn_80047608(void)
{
    svmLockServer_wrapper();
    if (lbl_8017B158[0] != 0) {
        svmUnlockServer_wrapper();
        return;
    }
    lbl_8017B158[0] = 1;
    svmUnlockServer_wrapper();

    fn_8004A578();
    lbl_8017B158[0] = 2;
    fn_80054760();
    lbl_8017B158[0] = 5;
    fn_8004A578();
    lbl_8017B158[0] = 6;
    fn_8004FAA8();
    lbl_8017B158[0] = 0;
}



asm void fn_8004768C(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stmw	r27, 0x2c(r1)
    mr	r30, r3
    mr	r29, r4
    mr	r27, r5
    mr	r28, r6
    bl      fn_800482FC
    lis     r3, lbl_8017B1A0@ha
    li	r4, 0x400
    addi	r3, r3, lbl_8017B1A0@l
    li	r5, 0
    bl      ADXT_ProcessStreamUpdate
    lis     r4, lbl_8017B160@ha
    mr	r31, r3
    addi	r0, r4, lbl_8017B160@l
    li	r4, 0x20
    mr	r3, r0
    bl      fn_80057B9C
    lis     r4, lbl_8017B160@ha
    stw	r3, 0x18(r1)
    addi	r3, r4, lbl_8017B160@l
    li	r4, 0x20
    addi	r3, r3, 0x20
    bl      fn_80057B9C
    stw	r3, 0x1c(r1)
    mr	r5, r31
    addi	r4, r1, 0x18
    li	r3, 2
    lwz	r30, 0x14(r30)
    bl      fn_80047C94
    mr	r4, r29
    mr	r29, r3
    mr	r5, r27
    mr	r6, r28
    bl      fn_80047ADC
    mr	r3, r29
    bl      fn_80047B04
    bl      fn_80047864
    lwz	r5, 0(r31)
    mr	r3, r31
    addi	r6, r1, 0x10
    li	r4, 1
    lwz	r12, 0x18(r5)
    li	r5, 0x400
    mtctr	r12
    bctrl	
    lwz	r5, 0x14(r1)
    cmpwi	r5, 0
    bne     _8004775c
_80047758:
    b       _80047758
_8004775c:
    lwz	r4, 0(r30)
    mr	r3, r30
    addi	r6, r1, 8
    lwz	r12, 0x18(r4)
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r0, 0xc(r1)
    lwz	r5, 0x14(r1)
    cmpw	r0, r5
    bge     _8004778c
_80047788:
    b       _80047788
_8004778c:
    lwz	r3, 8(r1)
    lwz	r4, 0x10(r1)
    bl      memcpy
    lwz	r6, 0(r31)
    mr	r3, r31
    addi	r5, r1, 0x10
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r1, 8
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    mr	r3, r29
    bl      fn_80047AF8
    mr	r3, r29
    bl      fn_80047C08
    lwz	r4, 0(r31)
    mr	r3, r31
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
    lwz	r3, 0x1c(r1)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
    lwz	r3, 0x18(r1)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
    bl      fn_800482B8
    lmw	r27, 0x2c(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

// provenance: original
void fn_80047834(void)
{
    lbl_8017B5A0[0]--;
}

// provenance: original
void fn_8004784C(void)
{
    lbl_8017B5A0[0]++;
}

// provenance: original
void fn_80047864(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        int st = lbl_8017BF78[i].unk0;
        if (st == 1) {
            fn_800478C0(&lbl_8017BF78[i]);
        }
    }
}

asm void fn_800478C0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r27, 0x1c(r1)
    mr	r31, r3
    lbz	r0, 1(r3)
    extsb	r0, r0
    cmpwi	r0, 1
    bne     _80047a30
    lwz	r29, 0xc(r31)
    mr	r28, r31
    mr	r27, r31
    li	r30, 0
    b       _8004795c
_800478f8:
    lwz	r3, 4(r28)
    addi	r6, r1, 0xc
    li	r4, 1
    li	r5, 2
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0x10(r1)
    cmpwi	r0, 0
    beq     _80047968
    lwz	r3, 0xc(r1)
    addi	r5, r1, 0xc
    li	r4, 1
    lha	r0, 0(r3)
    sth	r0, 0x2cc(r27)
    sth	r0, 0x2c8(r27)
    lwz	r3, 4(r28)
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r28, r28, 4
    addi	r27, r27, 2
    addi	r30, r30, 1
_8004795c:
    lwz	r0, 0x58(r31)
    cmpw	r30, r0
    blt     _800478f8
_80047968:
    lwz	r0, 0x58(r31)
    cmpw	r30, r0
    blt     _80047a3c
    mr	r3, r31
    li	r4, 0
    b       _80047998
_80047980:
    lha	r0, 0x2c8(r3)
    addi	r4, r4, 1
    sth	r0, 0x88(r3)
    lha	r0, 0x2cc(r3)
    sth	r0, 0x8c(r3)
    addi	r3, r3, 2
_80047998:
    lwz	r0, 0x58(r31)
    cmpw	r4, r0
    blt     _80047980
    mr	r3, r31
    mr	r4, r29
    bl      fn_80048340
    cmpwi	r3, 0
    beq     _80047a3c
    lwz	r0, 0x2c(r31)
    mr	r27, r31
    li	r28, 0
    add	r0, r0, r3
    stw	r0, 0x2c(r31)
    b       _80047a18
_800479d0:
    lwz	r0, 0x64(r31)
    addi	r5, r1, 8
    lwz	r29, 0x80(r27)
    addi	r6, r1, 0xa
    lwz	r4, 0x5c(r31)
    extsh	r3, r0
    bl      CRI_SPSD_parser
    lha	r3, 0xa(r1)
    addi	r27, r27, 4
    lha	r0, 8(r1)
    addi	r28, r28, 1
    sth	r0, 4(r29)
    sth	r3, 6(r29)
    lha	r4, 0xa(r1)
    lwz	r3, 0x88(r29)
    lha	r0, 8(r1)
    sth	r0, 4(r3)
    sth	r4, 6(r3)
_80047a18:
    lwz	r0, 0x58(r31)
    cmpw	r28, r0
    blt     _800479d0
    li	r0, 2
    stb	r0, 1(r31)
    b       _80047a3c
_80047a30:
    cmpwi	r0, 2
    bne     _80047a3c
    bl      fn_80047A50
_80047a3c:
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

// provenance: original
void fn_80047A50(AdxHandle* p)
{
    int n;

    for (;;) {
        if (p->unk3 != 0) {
            break;
        }
        do {
            n = fn_80049958(p);
            if (n == 0) {
                return;
            }
            p->unk2C += n;
        } while (p->unk30 < p->unk3C);
        p->unk3 = 1;
    }

    if (fn_80049728(p) > 0) {
        p->unk1 = 3;
    }
}

// provenance: original
void fn_80047ADC(void *p, int r4, int r5, int r6)
{
    *(int *)((char *)p + 0x58) = r4;
    *(int *)((char *)p + 0x5c) = r5;
    *(int *)((char *)p + 0x3c) = r6;
    *(int *)((char *)p + 0x60) = r6;
    *(int *)((char *)p + 0x48) = 0x11c;
}

// provenance: original
void fn_80047AF8(void *p)
{
    *(unsigned char *)((char *)p + 3) = 1;
}

asm void fn_80047B04(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    mr	r28, r3
    mr	r31, r28
    b       _80047bc0
_80047b30:
    lwz	r0, 0x68(r28)
    rlwinm.	r29, r0, 1, 0, 0x1e
    ble     _80047bb8
    lwz	r3, 4(r31)
    mr	r5, r29
    addi	r6, r1, 8
    li	r4, 0
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r5, 0xc(r1)
    cmpw	r5, r29
    beq     _80047b90
    slwi	r0, r30, 2
    addi	r5, r1, 8
    add	r3, r28, r0
    li	r4, 0
    lwz	r3, 4(r3)
    lwz	r6, 0(r3)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
_80047b8c:
    b       _80047b8c
_80047b90:
    lwz	r3, 8(r1)
    li	r4, 0
    bl      memset
    lwz	r3, 4(r31)
    addi	r5, r1, 8
    li	r4, 1
    lwz	r6, 0(r3)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_80047bb8:
    addi	r31, r31, 4
    addi	r30, r30, 1
_80047bc0:
    lwz	r0, 0x58(r28)
    cmpw	r30, r0
    blt     _80047b30
    li	r3, 0
    li	r0, 1
    stw	r3, 0x28(r28)
    stw	r3, 0x2c(r28)
    stw	r3, 0x30(r28)
    stb	r3, 3(r28)
    stb	r0, 1(r28)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

// provenance: original
void fn_80047C08(AdxHandle* p)
{
    void* q;

    if (p == 0) {
        return;
    }
    svmLockServer_wrapper();

    q = p->unk80;
    if (q != 0) {
        if (q != 0) {
            *(char*)q = 0;
            memset(q, 0, 0x90);
        }
    }

    q = p->unk84;
    if (q != 0) {
        if (q != 0) {
            *(char*)q = 0;
            memset(q, 0, 0x90);
        }
    }

    memset(p, 0, 4);
    svmUnlockServer_wrapper();
}

asm void fn_80047C94(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r6, lbl_8017B5A8@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r6, lbl_8017B5A8@l
    li	r6, 0
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    addi	r3, r31, 0x9d0
    lbz	r0, 0(r3)
    extsb.	r0, r0
    beq     _80047d58
    lbz	r0, 0x2f0(r3)
    li	r6, 1
    addi	r3, r3, 0x2f0
    extsb.	r0, r0
    beq     _80047d58
    lbz	r0, 0x2f0(r3)
    li	r6, 2
    addi	r3, r3, 0x2f0
    extsb.	r0, r0
    beq     _80047d58
    lbz	r0, 0x2f0(r3)
    li	r6, 3
    addi	r3, r3, 0x2f0
    extsb.	r0, r0
    beq     _80047d58
    lbz	r0, 0x2f0(r3)
    li	r6, 4
    addi	r3, r3, 0x2f0
    extsb.	r0, r0
    beq     _80047d58
    lbz	r0, 0x2f0(r3)
    li	r6, 5
    addi	r3, r3, 0x2f0
    extsb.	r0, r0
    beq     _80047d58
    lbz	r0, 0x2f0(r3)
    li	r6, 6
    addi	r3, r3, 0x2f0
    extsb.	r0, r0
    beq     _80047d58
    lbz	r0, 0x2f0(r3)
    li	r6, 7
    extsb.	r0, r0
    beq     _80047d58
    li	r6, 8
_80047d58:
    cmpwi	r6, 8
    bne     _80047d68
    li	r3, 0
    b       _8004829c
_80047d68:
    mulli	r0, r6, 0x2f0
    addi	r30, r31, 0x9d0
    cmpwi	r29, 0
    li	r8, 0
    add	r30, r30, r0
    stb	r29, 2(r30)
    ble     _80047e24
    cmpwi	r29, 8
    addi	r3, r29, -8
    ble     _80047df8
    addi	r0, r3, 7
    mr	r6, r4
    srwi	r0, r0, 3
    mr	r7, r30
    mtctr	r0
    cmpwi	r3, 0
    ble     _80047df8
_80047dac:
    lwz	r0, 0(r6)
    addi	r8, r8, 8
    stw	r0, 4(r7)
    lwz	r0, 4(r6)
    stw	r0, 8(r7)
    lwz	r0, 8(r6)
    stw	r0, 0xc(r7)
    lwz	r0, 0xc(r6)
    stw	r0, 0x10(r7)
    lwz	r0, 0x10(r6)
    stw	r0, 0x14(r7)
    lwz	r0, 0x14(r6)
    stw	r0, 0x18(r7)
    lwz	r0, 0x18(r6)
    stw	r0, 0x1c(r7)
    lwz	r0, 0x1c(r6)
    addi	r6, r6, 0x20
    stwu	r0, 0x20(r7)
    bdnz    _80047dac
_80047df8:
    slwi	r6, r8, 2
    subf	r0, r8, r29
    add	r3, r4, r6
    add	r4, r30, r6
    mtctr	r0
    cmpw	r8, r29
    bge     _80047e24
_80047e14:
    lwz	r0, 0(r3)
    addi	r3, r3, 4
    stwu	r0, 4(r4)
    bdnz    _80047e14
_80047e24:
    stw	r5, 0xc(r30)
    li	r7, 0
    lis	r0, 0x7fff
    li	r3, 0
    stb	r7, 1(r30)
    li	r4, 0
    li	r5, 4
    li	r6, 4
    stw	r7, 0x28(r30)
    stw	r7, 0x2c(r30)
    stw	r7, 0x30(r30)
    stw	r0, 0x34(r30)
    bl      criax_cri_tag_padsize
    stw	r3, 0x48(r30)
    li	r0, 3
    addi	r3, r31, 0x910
    lis	r4, 1
    stw	r0, 0x4c(r30)
    addi	r0, r4, -0x53bc
    li	r7, 4
    li	r6, 0x12
    stw	r29, 0x58(r30)
    lis	r5, 0x7fff
    li	r4, 0x1f4
    li	r8, 0
    stw	r0, 0x5c(r30)
    li	r0, 2
    mr	r9, r3
    stw	r7, 0x54(r30)
    stw	r6, 0x50(r30)
    lwz	r7, 0x50(r30)
    lwz	r6, 0x54(r30)
    addi	r7, r7, -2
    slwi	r7, r7, 3
    divw	r6, r7, r6
    stw	r6, 0x44(r30)
    stw	r5, 0x60(r30)
    stw	r4, 0x64(r30)
    stw	r8, 0x68(r30)
    stw	r8, 0x6c(r30)
    stw	r8, 0x70(r30)
    stw	r8, 0x74(r30)
    stw	r8, 0x78(r30)
    stw	r8, 0x7c(r30)
    stw	r8, 0x38(r30)
    stw	r8, 0x3c(r30)
    lwz	r4, 0x60(r30)
    lwz	r5, 0x44(r30)
    addi	r4, r4, -1
    divw	r4, r4, r5
    addi	r4, r4, 1
    mullw	r4, r5, r4
    stw	r4, 0x40(r30)
    lwz	r6, 0x44(r30)
    mtctr	r0
_80047f00:
    lbz	r0, 0(r9)
    mr	r7, r9
    extsb.	r0, r0
    beq     _80047fa8
    lbzu	r0, 0xc(r9)
    addi	r8, r8, 1
    extsb.	r0, r0
    mr	r7, r9
    beq     _80047fa8
    lbzu	r0, 0xc(r9)
    addi	r8, r8, 1
    extsb.	r0, r0
    mr	r7, r9
    beq     _80047fa8
    lbzu	r0, 0xc(r9)
    addi	r8, r8, 1
    extsb.	r0, r0
    mr	r7, r9
    beq     _80047fa8
    lbzu	r0, 0xc(r9)
    addi	r8, r8, 1
    extsb.	r0, r0
    mr	r7, r9
    beq     _80047fa8
    lbzu	r0, 0xc(r9)
    addi	r8, r8, 1
    extsb.	r0, r0
    mr	r7, r9
    beq     _80047fa8
    lbzu	r0, 0xc(r9)
    addi	r8, r8, 1
    extsb.	r0, r0
    mr	r7, r9
    beq     _80047fa8
    lbzu	r0, 0xc(r9)
    addi	r8, r8, 1
    extsb.	r0, r0
    mr	r7, r9
    beq     _80047fa8
    addi	r9, r9, 0xc
    addi	r8, r8, 1
    bdnz    _80047f00
_80047fa8:
    cmpwi	r8, 0x10
    bge     _80047fb4
    b       _80047fb8
_80047fb4:
    li	r7, 0
_80047fb8:
    cmplwi	r7, 0
    bne     _80047fc8
    li	r5, 0
    b       _800480a0
_80047fc8:
    li	r0, 2
    addi	r8, r31, 0x10
    li	r4, 0
    mtctr	r0
_80047fd8:
    lbz	r0, 0(r8)
    mr	r5, r8
    extsb.	r0, r0
    beq     _80048080
    lbzu	r0, 0x90(r8)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r5, r8
    beq     _80048080
    lbzu	r0, 0x90(r8)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r5, r8
    beq     _80048080
    lbzu	r0, 0x90(r8)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r5, r8
    beq     _80048080
    lbzu	r0, 0x90(r8)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r5, r8
    beq     _80048080
    lbzu	r0, 0x90(r8)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r5, r8
    beq     _80048080
    lbzu	r0, 0x90(r8)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r5, r8
    beq     _80048080
    lbzu	r0, 0x90(r8)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r5, r8
    beq     _80048080
    addi	r8, r8, 0x90
    addi	r4, r4, 1
    bdnz    _80047fd8
_80048080:
    stw	r6, 0x14(r5)
    cmpwi	r4, 0x10
    stw	r7, 0x88(r5)
    bge     _8004809c
    li	r0, 1
    stb	r0, 0(r5)
    b       _800480a0
_8004809c:
    li	r5, 0
_800480a0:
    stw	r5, 0x80(r30)
    li	r0, 2
    li	r4, 0
    lwz	r5, 0x44(r30)
    mtctr	r0
_800480b4:
    lbz	r0, 0(r3)
    mr	r6, r3
    extsb.	r0, r0
    beq     _8004815c
    lbzu	r0, 0xc(r3)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r6, r3
    beq     _8004815c
    lbzu	r0, 0xc(r3)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r6, r3
    beq     _8004815c
    lbzu	r0, 0xc(r3)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r6, r3
    beq     _8004815c
    lbzu	r0, 0xc(r3)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r6, r3
    beq     _8004815c
    lbzu	r0, 0xc(r3)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r6, r3
    beq     _8004815c
    lbzu	r0, 0xc(r3)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r6, r3
    beq     _8004815c
    lbzu	r0, 0xc(r3)
    addi	r4, r4, 1
    extsb.	r0, r0
    mr	r6, r3
    beq     _8004815c
    addi	r3, r3, 0xc
    addi	r4, r4, 1
    bdnz    _800480b4
_8004815c:
    cmpwi	r4, 0x10
    bge     _80048168
    b       _8004816c
_80048168:
    li	r6, 0
_8004816c:
    cmplwi	r6, 0
    bne     _8004817c
    li	r4, 0
    b       _80048254
_8004817c:
    li	r0, 2
    addi	r7, r31, 0x10
    li	r3, 0
    mtctr	r0
_8004818c:
    lbz	r0, 0(r7)
    mr	r4, r7
    extsb.	r0, r0
    beq     _80048234
    lbzu	r0, 0x90(r7)
    addi	r3, r3, 1
    extsb.	r0, r0
    mr	r4, r7
    beq     _80048234
    lbzu	r0, 0x90(r7)
    addi	r3, r3, 1
    extsb.	r0, r0
    mr	r4, r7
    beq     _80048234
    lbzu	r0, 0x90(r7)
    addi	r3, r3, 1
    extsb.	r0, r0
    mr	r4, r7
    beq     _80048234
    lbzu	r0, 0x90(r7)
    addi	r3, r3, 1
    extsb.	r0, r0
    mr	r4, r7
    beq     _80048234
    lbzu	r0, 0x90(r7)
    addi	r3, r3, 1
    extsb.	r0, r0
    mr	r4, r7
    beq     _80048234
    lbzu	r0, 0x90(r7)
    addi	r3, r3, 1
    extsb.	r0, r0
    mr	r4, r7
    beq     _80048234
    lbzu	r0, 0x90(r7)
    addi	r3, r3, 1
    extsb.	r0, r0
    mr	r4, r7
    beq     _80048234
    addi	r7, r7, 0x90
    addi	r3, r3, 1
    bdnz    _8004818c
_80048234:
    stw	r5, 0x14(r4)
    cmpwi	r3, 0x10
    stw	r6, 0x88(r4)
    bge     _80048250
    li	r0, 1
    stb	r0, 0(r4)
    b       _80048254
_80048250:
    li	r4, 0
_80048254:
    stw	r4, 0x84(r30)
    li	r6, 0
    li	r0, -0x80
    addi	r3, r30, 0x2d7
    sth	r6, 0x2cc(r30)
    li	r4, 0
    li	r5, 0x10
    sth	r6, 0x2c8(r30)
    sth	r6, 0x2ce(r30)
    sth	r6, 0x2ca(r30)
    stb	r6, 0x2d6(r30)
    sth	r6, 0x2e8(r30)
    sth	r0, 0x2ea(r30)
    sth	r0, 0x2ec(r30)
    bl      memset
    li	r0, 1
    mr	r3, r30
    stb	r0, 0(r30)
_8004829c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

// provenance: original
void fn_800482B8(void)
{
    (*(int*)lbl_8017B5A8)--;
    memset(lbl_8017BF78, 0, 0x1780);
}

// provenance: original
void fn_800482FC(void)
{
    (*(int*)lbl_8017B5A8)++;
    memset(lbl_8017BF78, 0, 0x1780);
}

#pragma pop
