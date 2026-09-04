#pragma push
#pragma force_active on

typedef struct AhxCtx {
    void* unk0;
    char pad4[0x340];
    unsigned char unk344;
    unsigned char unk345;
    signed char unk346;
    char pad347[1];
    int unk348;
    void* unk34C;
    void* unk350;
    char unk354[0x30];
    char unk384[0x34];
    char unk3B8[0x100];
    char unk4B8[0x100];
    char unk5B8[0x300];
    char unk8B8[0x300];
} AhxCtx;

typedef struct AhxState {
    char pad0[4];
    int unk4;
    char pad8[0x80];
    int unk88;
    char pad8C[4];
    int unk90;
    int unk94;
    char pad98[0x18];
    void* unkB0;
    char padB4[4];
    int unkB8;
} AhxState;

typedef struct AhxOwner {
    char pad0[4];
    AhxState* unk4;
} AhxOwner;

typedef struct AhxHandle {
    char pad0[4];
    AhxOwner* unk4;
    char pad8[8];
    void* unk10;
    char pad14[4];
    char unk18;
} AhxHandle;

extern void adx_err_report();
extern void fn_800542B4(void);
extern void ADXT_Stop();
extern void fn_8004EBB4(void);
extern void fn_8004EBD4(void);
extern void svm_ringbuf_skip(void);
extern void fn_800519B0(void);
extern void fn_80053A38();
extern void* fn_80053A84();
extern void fn_80053BB4(void);
extern void fn_80053BFC(void);
extern int fn_80053EA0();
extern int fn_80053EA8();
extern void fn_80053EB0();
extern void fn_800541EC();
extern void fn_80054224();
extern int fn_800542BC();
extern void fn_800542C8();
extern void* fn_80054354();
extern void fn_800545B0(void);
extern void fn_80054608(void);
extern void memset();
extern unsigned char E1052501_ADXT_AttachAHX_str[24];
extern unsigned char can_not_attach_AHX_str[20];
extern void (*lbl_8017E58C[])();
extern void (*lbl_8017A280[])();
extern void (*lbl_8017A284[])();
extern int lbl_80187110[];
extern unsigned char lbl_80187130[512];
extern AhxCtx* lbl_80187330[16];

asm void fn_80051448(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    stw	r0, 0x64(r1)
    stw	r31, 0x5c(r1)
    mr	r31, r3
    stw	r30, 0x58(r1)
    stw	r29, 0x54(r1)
    stw	r28, 0x50(r1)
    lwz	r0, 0x34c(r3)
    cmplwi	r0, 0
    mr	r28, r0
    beq     _80051574
    addi	r3, r1, 0xc
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r0, 0
    lis     r3, lbl_80187130@ha
    addi	r3, r3, lbl_80187130@l
    stw	r0, 8(r1)
    mr	r30, r3
    addi	r29, r3, 4
    b       _800514b8
_800514a4:
    mr	r3, r28
    li	r4, 8
    bl      svm_ringbuf_skip
    stb	r3, 0(r30)
    addi	r30, r30, 1
_800514b8:
    cmplw	r30, r29
    bne     _800514a4
    lis     r3, lbl_80187130@ha
    addi	r5, r1, 8
    addi	r3, r3, lbl_80187130@l
    li	r4, 4
    li	r6, 0
    bl      fn_800519B0
    lwz	r0, 8(r1)
    add	r29, r29, r0
    b       _800514f8
_800514e4:
    mr	r3, r28
    li	r4, 8
    bl      svm_ringbuf_skip
    stb	r3, 0(r30)
    addi	r30, r30, 1
_800514f8:
    cmplw	r30, r29
    bne     _800514e4
    lis     r3, lbl_80187130@ha
    addi	r5, r1, 8
    addi	r3, r3, lbl_80187130@l
    addi	r6, r1, 0xc
    li	r4, 0x200
    bl      fn_800519B0
    cmpwi	r3, 0
    blt     _80051574
    lbz	r3, 0xf(r1)
    li	r0, 1
    extsb	r3, r3
    stw	r3, 0x388(r31)
    lwz	r3, 0x10(r1)
    stw	r3, 0x38c(r31)
    lwz	r3, 0x14(r1)
    stw	r3, 0x390(r31)
    lwz	r4, 0x30(r1)
    lwz	r3, 0x34(r1)
    stw	r4, 0x3a0(r31)
    stw	r3, 0x3a4(r31)
    lwz	r3, 0x38(r1)
    stw	r3, 0x3a8(r31)
    lwz	r4, 0x3c(r1)
    lwz	r3, 0x40(r1)
    stw	r4, 0x3ac(r31)
    stw	r3, 0x3b0(r31)
    lwz	r3, 0x44(r1)
    stw	r3, 0x3b4(r31)
    stw	r0, 0x384(r31)
_80051574:
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    lwz	r30, 0x58(r1)
    lwz	r29, 0x54(r1)
    lwz	r28, 0x50(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr	
}

// provenance: original
void fn_80051594(AhxCtx* p, void* arg)
{
    void* prev = p->unk350;

    memset(p->unk354, 0, 0x30);
    memset(p->unk384, 0, 0x34);
    memset(p->unk3B8, 0, 0x100);
    memset(p->unk4B8, 0, 0x100);
    memset(p->unk5B8, 0, 0x300);
    memset(p->unk0, 0, 0x300);
    memset(p->unk8B8, 0, 0x300);
    p->unk345 = 0;
    p->unk348 = 0;

    if (p->unk350 != 0) {
        void* cur = p->unk350;
        p->unk350 = 0;
        fn_80053A38(cur);
        p->unk350 = fn_80053A84(prev, 0x2014);
    }
    p->unk34C = arg;
}

// provenance: original
void fn_80051678(AhxCtx* p)
{
    void* prev = p->unk350;

    memset(p->unk354, 0, 0x30);
    memset(p->unk384, 0, 0x34);
    memset(p->unk3B8, 0, 0x100);
    memset(p->unk4B8, 0, 0x100);
    memset(p->unk5B8, 0, 0x300);
    memset(p->unk0, 0, 0x300);
    memset(p->unk8B8, 0, 0x300);
    p->unk345 = 0;
    p->unk348 = 0;

    if (p->unk350 != 0) {
        void* cur = p->unk350;
        p->unk350 = 0;
        fn_80053A38(cur);
        p->unk350 = fn_80053A84(prev, 0x2014);
    }
}

// provenance: original
void fn_8005174C(AhxCtx* p)
{
    int slot = p->unk346;

    if (p->unk350 != 0) {
        void* cur = p->unk350;
        p->unk350 = 0;
        fn_80053A38(cur);
    }
    memset(p, 0, 0xBB8);
    lbl_80187330[slot] = 0;
}

// provenance: original
AhxCtx* fn_800517C0(AhxCtx* buf, int size)
{
    AhxCtx* p;
    int i;

    for (i = 0; i < 16; i++) {
        if (lbl_80187330[i] == 0) {
            break;
        }
    }
    if (i == 16) {
        return 0;
    }

    memset(buf, 0, size);
    lbl_80187330[i] = buf;
    p = lbl_80187330[i];
    p->unk346 = i;
    if ((p->unk350 = fn_80053A84((char*)p + 0xBB8, 0x2014)) == 0) {
        return 0;
    }

    p->unk0 = (void*)(((unsigned int)p + 0x23) & ~0x1F);
    if (((unsigned int)p->unk0 & 0x1F) != 0) {
        while (1) {
        }
    }
    p->unk344 = 1;
    return p;
}

// provenance: original
void fn_8005190C(void)
{
    if (--lbl_80187110[0] == 0) {
        memset(lbl_80187330, 0, 0x40);
        fn_80053BB4();
    }
}

// provenance: original
void fn_80051958(void)
{
    if (lbl_80187110[0] == 0) {
        fn_80053BFC();
        memset(lbl_80187330, 0, 0x40);
    }
    lbl_80187110[0]++;
}

asm void fn_800519B0(void)
{
    nofralloc
    cmplwi	r5, 0
    beq     _800519c0
    li	r0, 0
    stw	r0, 0(r5)
_800519c0:
    cmpwi	r4, 4
    bge     _800519d0
    li	r3, -1
    blr	
_800519d0:
    lbz	r7, 0(r3)
    lbz	r0, 1(r3)
    rlwimi	r0, r7, 8, 0x10, 0x17
    clrlwi	r0, r0, 0x10
    cmplwi	r0, 0x8000
    beq     _800519f0
    li	r3, -4
    blr	
_800519f0:
    lbz	r8, 2(r3)
    cmplwi	r5, 0
    lbz	r7, 3(r3)
    rlwimi	r7, r8, 8, 0x10, 0x17
    beq     _80051a08
    stw	r7, 0(r5)
_80051a08:
    cmplwi	r6, 0
    bne     _80051a18
    li	r3, 0
    blr	
_80051a18:
    addi	r0, r7, 4
    cmpw	r4, r0
    bge     _80051a2c
    li	r3, -2
    blr	
_80051a2c:
    addi	r7, r7, -6
    cmpwi	r7, 0x10
    bge     _80051a40
    li	r3, -2
    blr	
_80051a40:
    lbz	r0, 4(r3)
    addi	r7, r7, -0x10
    cmpwi	r7, 4
    stb	r0, 0(r6)
    lbz	r0, 5(r3)
    stb	r0, 1(r6)
    lbz	r0, 6(r3)
    stb	r0, 2(r6)
    lbz	r0, 7(r3)
    stb	r0, 3(r6)
    lbz	r0, 9(r3)
    lbz	r4, 8(r3)
    slwi	r0, r0, 0x10
    lbz	r5, 0xa(r3)
    rlwimi	r0, r4, 0x18, 0, 7
    lbz	r8, 0xb(r3)
    rlwimi	r0, r5, 8, 0x10, 0x17
    or	r0, r8, r0
    stw	r0, 4(r6)
    lbz	r0, 0xd(r3)
    lbz	r4, 0xc(r3)
    slwi	r0, r0, 0x10
    lbz	r5, 0xe(r3)
    rlwimi	r0, r4, 0x18, 0, 7
    lbz	r8, 0xf(r3)
    rlwimi	r0, r5, 8, 0x10, 0x17
    or	r0, r8, r0
    stw	r0, 8(r6)
    lbz	r4, 0x10(r3)
    lbz	r0, 0x11(r3)
    rlwimi	r0, r4, 8, 0x10, 0x17
    sth	r0, 0xc(r6)
    lbz	r0, 0x12(r3)
    stb	r0, 0x3c(r6)
    lbz	r0, 0x13(r3)
    stb	r0, 0x3d(r6)
    bge     _80051adc
    li	r3, -2
    blr	
_80051adc:
    lbz	r4, 0x16(r3)
    addi	r5, r3, 0x18
    lbz	r0, 0x17(r3)
    rlwimi	r0, r4, 8, 0x10, 0x17
    sth	r0, 0xe(r6)
    lha	r0, 0xe(r6)
    mulli	r0, r0, 0x14
    cmpw	r7, r0
    bge     _80051b08
    li	r3, -3
    blr	
_80051b08:
    mr	r3, r6
    li	r4, 0
    b       _80051bcc
_80051b14:
    lbz	r8, 0(r5)
    addi	r4, r4, 1
    lbz	r0, 1(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x10(r3)
    lbz	r8, 2(r5)
    lbz	r0, 3(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x12(r3)
    lbz	r0, 5(r5)
    lbz	r8, 4(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 6(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 7(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x14(r3)
    lbz	r0, 9(r5)
    lbz	r8, 8(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 0xa(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 0xb(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x18(r3)
    lbz	r0, 0xd(r5)
    lbz	r8, 0xc(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 0xe(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 0xf(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x1c(r3)
    lbz	r0, 0x11(r5)
    lbz	r8, 0x10(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 0x12(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 0x13(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x20(r3)
    addi	r3, r3, 0x14
_80051bcc:
    lha	r0, 0xe(r6)
    cmpw	r4, r0
    blt     _80051b14
    mulli	r0, r0, 0x14
    mr	r3, r6
    li	r4, 0
    subf	r7, r0, r7
    b       _80051ca8
_80051bec:
    cmpwi	r7, 0xc
    bge     _80051bfc
    li	r3, 0
    blr	
_80051bfc:
    lbz	r8, 0(r5)
    lbz	r0, 1(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x24(r3)
    lha	r0, 0x24(r3)
    cmpwi	r0, 0
    ble     _80051c28
    lbz	r8, 2(r5)
    lbz	r0, 3(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x26(r3)
_80051c28:
    lbz	r0, 4(r5)
    stb	r0, 0x28(r3)
    lbz	r0, 0x28(r3)
    extsb.	r0, r0
    ble     _80051c44
    lbz	r0, 5(r5)
    stb	r0, 0x29(r3)
_80051c44:
    lbz	r0, 6(r5)
    stb	r0, 0x2a(r3)
    lbz	r0, 0x2a(r3)
    extsb.	r0, r0
    ble     _80051c60
    lbz	r0, 7(r5)
    stb	r0, 0x2b(r3)
_80051c60:
    lbz	r0, 8(r5)
    stb	r0, 0x2c(r3)
    lbz	r0, 0x2c(r3)
    extsb.	r0, r0
    ble     _80051c7c
    lbz	r0, 9(r5)
    stb	r0, 0x2d(r3)
_80051c7c:
    lbz	r0, 0xa(r5)
    stb	r0, 0x2e(r3)
    lbz	r0, 0x2e(r3)
    extsb.	r0, r0
    ble     _80051c98
    lbz	r0, 0xb(r5)
    stb	r0, 0x2f(r3)
_80051c98:
    addi	r5, r5, 0xc
    addi	r7, r7, -0xc
    addi	r3, r3, 0xc
    addi	r4, r4, 1
_80051ca8:
    lbz	r0, 3(r6)
    extsb	r0, r0
    cmpw	r4, r0
    blt     _80051bec
    li	r3, 0
    blr	
}

// provenance: original
void ADXT_AHXExecCallback(AhxState* s)
{
    int i;
    void* obj;

    fn_8004EBD4();
    obj = s->unkB0;
    if (fn_800542BC(obj) == 0) {
        s->unk88 = 0;
        fn_800541EC(obj);
    }

    if (s->unk4 == 1) {
        s->unk88 = 0;
        fn_80054224(obj);
        s->unk4 = 2;
    } else if (s->unk4 == 2) {
        for (i = 0; i < s->unkB8; i++) {
            fn_80053EB0(obj);
        }
        s->unk90 = fn_80053EA0(obj) - s->unk88;
        s->unk88 = s->unk88 + s->unk90;
        s->unk94 = fn_80053EA8(obj);
        if (fn_800542BC(obj) == 3) {
            fn_800541EC(obj);
            s->unk4 = 0;
        }
    }
    fn_8004EBB4();
}

// provenance: original
void ADXT_AHXStopCallback(AhxHandle* p)
{
    AhxState* st;
    void* obj;

    ADXT_Stop(p);
    st = p->unk4->unk4;
    obj = st->unkB0;
    if (obj != 0) {
        fn_8004EBD4();
        fn_800541EC(obj);
        fn_800542C8(obj);
        st->unkB0 = 0;
        fn_8004EBB4();
        fn_800545B0();
    }
}

// provenance: original
void fn_80051E30(void* arg)
{
    if (lbl_8017E58C[0] != 0) {
        lbl_8017E58C[0](arg);
    }
}

// provenance: original
void ADXT_AttachAHX(AhxHandle* p, int a, int b)
{
    AhxState* st;
    void* h;
    void* obj;

    ADXT_Stop(p);
    if (lbl_8017E58C[0] != 0) {
        lbl_8017E58C[0](p);
    }
    fn_80054608();

    st = p->unk4->unk4;
    h = p->unk10;
    fn_8004EBD4();

    obj = fn_80054354(h, 1, &p->unk18, a, b);
    if (obj == 0) {
        adx_err_report(E1052501_ADXT_AttachAHX_str, can_not_attach_AHX_str);
        return;
    }

    st->unkB0 = obj;
    lbl_8017E58C[0] = ADXT_AHXStopCallback;
    lbl_8017A280[0] = ADXT_AHXExecCallback;
    lbl_8017A284[0] = fn_800542B4;
    fn_8004EBB4();
}

#pragma pop
