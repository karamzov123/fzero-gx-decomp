#pragma push
#pragma force_active on

typedef struct SjSpan {
    unsigned int ptr;
    int len;
} SjSpan;

typedef struct SjBuf {
    char pad0[0xc];
    int unkC;
    int unk10;
    int unk14;
    char pad18[4];
    int (*unk1C)();
    void* unk20;
} SjBuf;

typedef struct GcciSub {
    char pad0[0x18];
    int unk18;
    char pad1C[4];
} GcciSub;

typedef struct GcciVtbl {
    char pad0[0x24];
    int (*fn24)(void* obj, int ch);
} GcciVtbl;

typedef struct GcciObj {
    GcciVtbl* vtbl;
} GcciObj;

typedef struct GcciSlot {
    signed char unk0;
    signed char unk1;
    unsigned char unk2;
    char pad3[5];
    void* unk8;
    char padC[8];
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* unk28;
    int unk2C;
    char pad30[4];
    int unk34;
    GcciSub sub[16];
} GcciSlot;

typedef struct SjSlot {
    void* unk0;
    int unk4;
    void* unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    void* unk1C;
    void* unk20;
} SjSlot;

typedef struct GcciCrit {
    int a;
    int b;
} GcciCrit;

typedef struct SjRing {
    void* unkPtr;
    int unk4;
    void* unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int (*unk38)();
    void* unk3C;
} SjRing;

extern int OSDisableInterrupts();
extern void OSRestoreInterrupts();
extern void fn_8004A550(void);
extern void ADXT_GetVoiceByAxHandle(void);
extern void ADXT_StartVoice();
extern void fn_8004AD84(void);
extern void fn_8004ADF4(void);
extern void fn_8004AE78(void);
extern void fn_8004AE94(void);
extern void ADXTGetState(void);
extern void ADXT_StopVoice(void);
extern void fn_8004B180(void);
extern void gcciErrPrintf(const char* fmt, ...);
extern void gcci_set_critical_value();
extern void gccicrit_leave();
extern void gccicrit_enter();
extern void fn_8005676C(void);
extern void gcci_register_filename();
extern void fn_80057114();
extern void svmExitCritical(void);
extern void svmEnterCritical(void);
extern void SVM_ReportError();
extern void __msl_strncmp(void);
extern void memcpy();
extern void memset();
extern unsigned char SJMEM_Error_str[12];
extern unsigned char SJRBF_Error_str[12];
extern unsigned char E0003_lsc_null_str[35];
extern unsigned char lbl_80092238[42];
extern volatile int lbl_800922C0[];
extern unsigned char lbl_80092264[41];
extern unsigned char lbl_800922C8[21];
extern unsigned char lbl_800922E0[16];
extern unsigned char lbl_801322D0[48];
extern unsigned char lbl_80132330[448];
extern int lbl_80188A88[];
extern int lbl_80132300[];
extern int lbl_80092330[];
extern volatile int lbl_8009232C[];
extern GcciSlot lbl_80188A8C[16];
extern volatile int lbl_8018AE10[];
extern int lbl_8018AE14[];
extern int lbl_8018AE18[];
extern SjSlot lbl_8018AE1C[32];
extern int lbl_8018B2A0[];
extern unsigned char lbl_8018B2A4[16388];
extern unsigned char lbl_8018F2A8[];
extern unsigned char lbl_8018F2AC[3076];
void fn_80057D60(void);
void fn_800586E4(void);


/* harvest: declarations carried over from the recovered
   candidate — the converted body below needs them. */
typedef struct {
    unsigned char pad0[0x24];
    signed int field24;
} ADXTState;
// provenance: original
void fn_800570DC(int a, int b)
{
    gcci_register_filename(a, b, 0, 0, 0xfffff);
}

// provenance: original
void fn_8005710C(void* p, int val)
{
    *(int*)((char*)p + 0x28) = val;
}

// provenance: original
void fn_80057114(GcciSlot* p)
{
    if (p == 0) {
        return;
    }

    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
    } else if (p->unk1 != 0) {
        int mode;

        p->unk1 = 0;
        if (p->unk28 != 0) {
            mode = p->unk2;
            if (mode == 1) {
                ADXT_StartVoice(p->unk28);
                p->unk2 = 0;
            }
        }

        p->unk2C = 0;
        if (p == 0) {
            gcciErrPrintf((char*)E0003_lsc_null_str);
        } else if (p->unk1 == 0) {
            p->unk1C = 0;
            p->unk20 = 0;
            p->unk24 = 0;
        }
        p->unk34 = 0;
    }

    p->unk0 = 0;
    memset(p, 0, 0x238);
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

// provenance: original
void fn_80057378(void)
{
    GcciCrit crit;
    int i;

    gccicrit_enter(&crit);
    if (--lbl_80188A88[0] == 0) {
        for (i = 0; i < 16; i++) {
            int st = lbl_80188A8C[i].unk0;
            if (st == 1) {
                fn_80057114(&lbl_80188A8C[i]);
            }
        }
        memset(lbl_80188A8C, 0, 0x2380);
        gcci_set_critical_value(0, 0);
    }
    gccicrit_leave(&crit);
}

// provenance: original
void fn_8005741C(void)
{
    GcciCrit crit;

    lbl_800922C0[0];
    gccicrit_enter(&crit);
    if (lbl_80188A88[0] == 0) {
        memset(lbl_80188A8C, 0, 0x2380);
        gcci_set_critical_value(0, 0);
    }
    lbl_80188A88[0]++;
    gccicrit_leave(&crit);
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

// The critical-section counter is shared with the interrupt handler, and
// retail keeps both primitives out of line.
#pragma dont_inline on
// provenance: original
void svmExitCritical(void)
{
    lbl_8018AE10[0]--;
    if (lbl_8018AE10[0] == 0) {
        OSRestoreInterrupts(lbl_8018AE14[0]);
    }
}

// provenance: original
void svmEnterCritical(void)
{
    if (lbl_8018AE10[0] == 0) {
        lbl_8018AE14[0] = OSDisableInterrupts();
    }
    lbl_8018AE10[0]++;
}
#pragma dont_inline reset

// provenance: original
int fn_80057774(SjBuf* p, int mode, int want, int* got)
{
    int n;

    svmEnterCritical();
    if (mode == 0) {
        n = 0;
    } else if (mode == 1) {
        n = p->unkC < want ? p->unkC : want;
    } else {
        n = 0;
        if (p->unk1C != 0) {
            p->unk1C(p->unk20, -3);
        }
    }
    *got = n;
    svmExitCritical();
    return !(want - n);
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

// provenance: original
void fn_8005795C(SjBuf* p, unsigned int mode, SjRing* r)
{
    if (r->unk4 <= 0 || r->unkPtr == 0) {
        return;
    }
    svmEnterCritical();
    if (mode > 1) {
        r->unk4 = 0;
        r->unkPtr = 0;
        if (p->unk1C != 0) {
            p->unk1C(p->unk20, -3);
        }
    }
    svmExitCritical();
}

// provenance: original
void fn_800579F0(SjBuf* p, int mode, int want, SjSpan* out)
{
    svmEnterCritical();

    if (mode == 0) {
        out->len = 0;
        out->ptr = 0;
    } else if (mode == 1) {
        out->len = p->unkC < want ? p->unkC : want;
        out->ptr = p->unk14 + p->unk10;
        p->unk10 = p->unk10 + out->len;
        p->unkC = p->unkC - out->len;
    } else {
        out->len = 0;
        out->ptr = 0;
        if (p->unk1C != 0) {
            p->unk1C(p->unk20, -3);
        }
    }

    svmExitCritical();
}

// provenance: original
int fn_80057AD8(SjBuf* p, int n)
{
    if (n == 1) {
        return p->unkC;
    }
    if (n == 0) {
        return 0;
    }
    if (p->unk1C != 0) {
        p->unk1C(p->unk20, -3);
    }
    return 0;
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

// provenance: original
void fn_80057B5C(void* p)
{
    if (p != 0) {
        memset(p, 0, 0x24);
        *(int*)((char*)p + 4) = 0;
    }
}

// provenance: original
SjSlot* fn_80057B9C(int a, int b)
{
    SjSlot* s;
    int i;

    for (i = 0; i < 32; i++) {
        if (lbl_8018AE1C[i].unk4 == 0) {
            break;
        }
    }
    if (i == 32) {
        return 0;
    }

    s = &lbl_8018AE1C[i];
    s->unk4 = 1;
    s->unk0 = lbl_801322D0;
    s->unk14 = a;
    s->unk18 = b;
    s->unk8 = lbl_800922E0;
    s->unk1C = fn_80057D60;
    s->unk20 = s;
    s->unkC = s->unk18;
    s->unk10 = 0;
    return s;
}

// provenance: original
void fn_80057CC4(void)
{
    if (--lbl_8018AE18[0] == 0) {
        memset(lbl_8018AE1C, 0, 0x480);
    }
}

// provenance: original
void fn_80057D0C(void)
{
    if (lbl_8018AE18[0] == 0) {
        memset(lbl_8018AE1C, 0, 0x480);
    }
    lbl_8018AE18[0]++;
}

// provenance: original
void fn_80057D60(void)
{
    SVM_ReportError(SJMEM_Error_str);
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

// provenance: original
int fn_80057DB8(SjRing* p, int mode, int want, int* got)
{
    svmEnterCritical();

    if (mode == 0) {
        int avail = p->unk24 + (p->unk20 - p->unk14);
        if (p->unk10 < avail) {
            avail = p->unk10;
        }
        mode = avail < want ? avail : want;
    } else if (mode == 1) {
        int avail = p->unk24 + (p->unk20 - p->unk18);
        if (p->unkC < avail) {
            avail = p->unkC;
        }
        mode = avail < want ? avail : want;
    } else {
        mode = 0;
        if (p->unk38 != 0) {
            p->unk38(p->unk3C, -3);
        }
    }

    *got = mode;
    svmExitCritical();
    return !(want - mode);
}

// provenance: original
void fn_80057EC4(SjRing* p, int mode, SjSpan* span)
{
    if (span->len <= 0 || span->ptr == 0) {
        return;
    }

    svmEnterCritical();

    if (mode == 0) {
        int rem1 = (p->unk14 + p->unk20 - span->len) % p->unk20;
        int rem2 = ((int)span->ptr - p->unk1C) % p->unk20;

        if (rem1 == rem2) {
            p->unk14 = rem1;
            p->unk10 += span->len;
        } else if (p->unk38 != 0) {
            p->unk38(p->unk3C, -3);
        }
        p->unk28 -= span->len;
    } else if (mode == 1) {
        int rem1 = (p->unk18 + p->unk20 - span->len) % p->unk20;
        int rem2 = ((int)span->ptr - p->unk1C) % p->unk20;

        if (rem1 == rem2) {
            p->unk18 = rem1;
            p->unkC += span->len;
        } else if (p->unk38 != 0) {
            p->unk38(p->unk3C, -3);
        }
        p->unk30 -= span->len;
    } else {
        span->len = 0;
        span->ptr = 0;
        if (p->unk38 != 0) {
            p->unk38(p->unk3C, -3);
        }
    }

    svmExitCritical();
}

// provenance: original
void fn_80058070(SjRing* p, int mode, SjSpan* span)
{
    if (span->len <= 0 || span->ptr == 0) {
        return;
    }

    svmEnterCritical();

    if (mode == 1) {
        p->unkC += span->len;

        {
            int offset = (int)span->ptr - (int)p->unk1C;
            if (offset < p->unk24) {
                int n = p->unk24 - offset;
                if (span->len < n) {
                    n = span->len;
                }
                {
    {
    char* d = (char*)offset + p->unk1C;
    d = (char*)p->unk20 + (int)d;
    memcpy(d, (void*)span->ptr, n);
}
}
            }
        }

        {
            int end_offset = (int)span->ptr - (int)p->unk1C + span->len;
            if (end_offset > p->unk20) {
                int n = end_offset - p->unk20;
                if (span->len < n) {
                    n = span->len;
                }
                memcpy((void*)p->unk1C, (char*)p->unk1C + (end_offset - n), n);
            }
        }

        p->unk34 += span->len;
    } else if (mode == 0) {
        p->unk10 += span->len;
        p->unk2C += span->len;
    } else {
        span->len = 0;
        span->ptr = 0;
        if (p->unk38 != 0) {
            p->unk38(p->unk3C, -3);
        }
    }

    svmExitCritical();
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

// provenance: original
int fn_80058380(SjRing* p, int n)
{
    if (n == 1) {
        return p->unkC;
    }
    if (n == 0) {
        return p->unk10;
    }
    if (p->unk38 != 0) {
        p->unk38(p->unk3C, -3);
    }
    return 0;
}

// provenance: original
void fn_800583DC(SjRing* p)
{
    svmEnterCritical();
    p->unkC = 0;
    p->unk10 = p->unk20;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk28 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    svmExitCritical();
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

// provenance: original
void fn_80058448(void* p)
{
    svmEnterCritical();
    if (p != 0) {
        memset(p, 0, 0x40);
        *(int*)((char*)p + 4) = 0;
    }
    svmExitCritical();
}

// provenance: original
SjRing* ADXT_ProcessStreamUpdate(void* a0, int a1, int a2)
{
    int i;
    SjRing* entry;

    svmEnterCritical();

    for (i = 0; i < 256; i++) {
        if (((SjRing*)lbl_8018B2A4)[i].unk4 == 0) {
            break;
        }
    }

    if (i == 256) {
        entry = 0;
    } else {
        entry = &((SjRing*)lbl_8018B2A4)[i];
        entry->unk4 = 1;
        entry->unkPtr = lbl_80132300;
        entry->unk1C = (int)a0;
        entry->unk20 = a1;
        entry->unk24 = a2;
        entry->unk8 = (void*)lbl_80092330;
        entry->unk38 = (int (*)())fn_800586E4;
        entry->unk3C = entry;

        svmEnterCritical();
        entry->unkC = 0;
        entry->unk10 = entry->unk20;
        entry->unk14 = 0;
        entry->unk18 = 0;
        entry->unk28 = 0;
        entry->unk2C = 0;
        entry->unk30 = 0;
        entry->unk34 = 0;
        svmExitCritical();
    }

    svmExitCritical();
    return entry;
}

// provenance: original
void fn_80058630(void)
{
    int* p = (int*)lbl_8018B2A0;
    svmEnterCritical();
    if (--*p == 0) {
        memset(lbl_8018B2A4, 0, 0x4000);
    }
    svmExitCritical();
}

// provenance: original
void fn_80058680(void)
{
    lbl_8009232C[0];
    svmEnterCritical();
    if (lbl_8018B2A0[0] == 0) {
        memset(lbl_8018B2A4, 0, 0x4000);
    }
    lbl_8018B2A0[0]++;
    svmExitCritical();
}

// provenance: original
void fn_800586E4(void)
{
    SVM_ReportError(SJRBF_Error_str);
}

// provenance: original
void fn_8005870C(void)
{
    int* p = (int*)lbl_8018F2A8;
    if (--*p == 0) {
        memset(lbl_8018F2AC, 0, 0xc00);
    }
}

// provenance: original
void fn_80058754(void)
{
    if (*(int*)lbl_8018F2A8 == 0) {
        memset(lbl_8018F2AC, 0, 0xc00);
    }
    (*(int*)lbl_8018F2A8)++;
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
