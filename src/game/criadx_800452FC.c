#pragma push
#pragma force_active on

typedef struct AdxHdr {
    short unk0;
    char pad2[0xb];
    signed char unkD;
    signed char unkE;
    signed char unkF;
    char pad10[0x38];
    int unk48;
    int unk4C;
    char pad50[0x24];
    int unk74;
    char pad78[0x18];
    int unk90;
    int unk94;
    short unk98;
    short unk9A;
} AdxHdr;

typedef struct AdxSpsd {
    short unk0;
    char pad2[6];
    void* unk8;
    char padC[0x2c];
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    char pad48[0x30];
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    char pad88[0x34];
    int unkBC;
    char unkC0[0x10];
    short unkD0;
    short unkD2;
    short unkD4;
    char padD6[2];
} AdxSpsd;

extern void fn_8004E198();
extern unsigned char lbl_800900A0[2184];
extern void fn_8004E1B0();
extern void fn_8004E300();
extern void fn_8004E2CC();
extern void fn_8004E2DC();
extern void fn_8004E2B0();
extern int CRI_FORM_parser();
extern int criadx_spsd_probe();
extern int fn_800462F8();
extern int criadx_wav_probe();
extern int fn_80043050();
extern int criadx_aiff_probe();
extern int fn_80043B48();
extern int CRI_WAVE_parser();
extern int criadx_snd_probe();
extern void fn_80046C28(void);
extern void adx_err_report(void);
extern void fn_80046B90(void);
extern void sprintf(void);
extern void fn_80046BE0(void);
extern void fn_80046AC0(void);
extern void fn_8004E324(void);
extern void fn_800469A4(void);
extern void fn_8004683C(void);
extern void fn_8004E278();
extern void memset();
extern void* fn_8004E354(void);
extern void fn_8004E4AC();
extern int strncmp();
extern void ADXT_GetCmdState(void);
extern const char SPSD_str[];
extern void fn_80045F58();
extern int fn_80045F74();
extern unsigned char lbl_8017A288[20];
extern AdxSpsd lbl_8017A29C[16];

// provenance: original
int fn_800452FC(void* p)
{
    return *(int*)((char*)p + 0x90);
}

// provenance: original
int fn_80045304(void* p)
{
    return *(int*)((char*)p + 0x94);
}

// provenance: original
void fn_8004530C(void* p)
{
    if (*(int*)((char*)p + 4) == 3) {
        fn_8004E198(*(void**)((char*)p + 8));
        *(int*)((char*)p + 0x8c) = 0;
        *(int*)((char*)p + 4) = 0;
    }
}

// provenance: original
void fn_80045354(void* p)
{
    fn_8004E1B0(*(void**)((char*)p + 8));
    *(int*)((char*)p + 4) = 0;
}

// provenance: original
void fn_8004538C(void* p)
{
    if (*(int*)((char*)p + 4) == 0) {
        *(int*)((char*)p + 4) = 1;
    }
}

// provenance: original
void fn_800453A4(AdxHdr* p, int a, int rate)
{
    if (p->unk98 == 0) {
        p->unk48 = a;
        p->unk4C = rate / p->unkF;
        p->unk74 = 0;
        p->unk90 = 0;
        p->unk94 = 0;
    } else {
        p->unk48 = a;
        p->unk4C = rate / (p->unkD / 8 * p->unkE);
        p->unk74 = 0;
        p->unk90 = 0;
        p->unk94 = 0;
    }
}

// provenance: original
int fn_80045414(void* p)
{
    return *(int*)((char*)p + 4);
}

// provenance: original
void fn_8004541C(void* p)
{
    fn_8004E300(*(void**)((char*)p + 8), (char*)p + 0xa8, (char*)p + 0xac);
    fn_8004E2CC(*(void**)((char*)p + 8), *(short*)((char*)p + 0xa2), *(short*)((char*)p + 0xa4), *(short*)((char*)p + 0xa6));
}

// provenance: original
void fn_80045468(void* p)
{
    fn_8004E2DC(*(void**)((char*)p + 8), (char*)p + 0xa8, (char*)p + 0xac);
    fn_8004E2B0(*(void**)((char*)p + 8), (char*)p + 0xa2, (char*)p + 0xa4, (char*)p + 0xa6);
}

// provenance: original
int fn_800454B4(void* p, int r4)
{
    p = (char*)p + (r4 * 2);
    return *(short*)((char*)p + 0xd2);
}

// provenance: original
int fn_800454C4(void* p)
{
    return *(short*)((char*)p + 0xd0);
}

// provenance: original
int fn_800454CC(void* p)
{
    return *(int*)((char*)p + 0xbc);
}

// provenance: original
int fn_800454D4(void* p)
{
    return *(int*)((char*)p + 0x34);
}

// provenance: original
int fn_800454DC(void* p)
{
    return *(int*)((char*)p + 0x30);
}

// provenance: original
int fn_800454E4(void* p)
{
    if (p == 0) return 0;
    return *(int*)((char*)p + 0x2c);
}

// provenance: original
int fn_800454FC(void* p)
{
    return *(int*)((char*)p + 0x28);
}

// provenance: original
int fn_80045504(void* p)
{
    return *(short*)((char*)p + 0x24);
}

// provenance: original
void* criadx_get_stream_ptr(void* p)
{
    return *(void**)((char*)p + 0x18);
}

// provenance: original
int fn_80045514(void* p)
{
    return *(int*)((char*)p + 0x10);
}

// provenance: original
int fn_8004551C(AdxHdr* p)
{
    short fmt = p->unk98;

    if (fmt == 0) {
        return 0x10;
    }
    if (fmt == 2) {
        short bits = p->unk9A;
        if (bits == 2) {
            return 4;
        }
        if (bits == 1) {
            return 8;
        }
        return 0x10;
    }
    if (fmt == 1) {
        short bits = p->unk9A;
        if (bits == 2) {
            return 4;
        }
        return 0x10;
    }
    return 0x10;
}

// provenance: original
int criadx_get_field_0E(void* p)
{
    return *(signed char*)((char*)p + 0xe);
}

// provenance: original
int criadx_get_field_14(void* p)
{
    return *(int*)((char*)p + 0x14);
}

// provenance: original
int criadx_get_status(void* p)
{
    return *(short*)((char*)p + 0x98);
}

// provenance: original
int fn_800455A4(void* p)
{
    return *(int*)((char*)p + 0x3c);
}

// provenance: original
void fn_800455AC(void* p, int a, int b)
{
    *(int*)((char*)p + 0x78) = a;
    *(int*)((char*)p + 0x7c) = b;
}

// provenance: original
int criadx_format_dispatch(void* ctx, unsigned short* hdr, void* arg)
{
    if (hdr[0] == 0x8000) {
        return CRI_FORM_parser(ctx, hdr, arg);
    }
    if (criadx_spsd_probe(hdr) != 0) {
        return fn_800462F8(ctx, hdr, arg);
    }
    if (criadx_wav_probe(hdr) != 0) {
        return fn_80043050(ctx, hdr, arg);
    }
    if (criadx_aiff_probe(hdr) != 0) {
        return fn_80043B48(ctx, hdr, arg);
    }
    if (CRI_WAVE_parser(hdr) != 0) {
        return criadx_snd_probe(ctx, hdr, arg);
    }
    return -1;
}

asm int CRI_FORM_parser()
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    lis	r6, lbl_800900A0@ha
    stw	r0, 0x54(r1)
    li	r0, 1
    stmw	r26, 0x38(r1)
    mr	r29, r3
    mr	r31, r5
    mr	r30, r4
    lis     r5, lbl_8017A288@ha
    addi	r27, r6, lbl_800900A0@l
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

// provenance: original
void fn_80045D3C(AdxSpsd* p)
{
    if (p != 0) {
        void* old = p->unk8;
        p->unk8 = 0;
        fn_8004E278(old);
        memset(p, 0, 0xD8);
        p->unk0 = 0;
    }
}

// provenance: original
AdxSpsd* fn_80045D90(int a0, int a1, int a2, int a3)
{
    int i;
    AdxSpsd* p;

    for (i = 0; i < 16; i++) {
        if (lbl_8017A29C[i].unk0 == 0) {
            break;
        }
    }
    if (i == 16) {
        return 0;
    }
    p = &lbl_8017A29C[i];
    memset(p, 0, 0xD8);
    p->unk0 = 1;
    p->unk8 = fn_8004E354();
    if (p->unk8 == 0) {
        fn_80045D3C(p);
        return 0;
    }
    p->unk38 = a0;
    p->unk3C = a1;
    p->unk40 = a2;
    p->unk44 = a3;
    p->unk78 = fn_80045F74;
    p->unk7C = p;
    p->unk80 = fn_80045F58;
    p->unk84 = p;
    p->unkBC = 0;
    p->unkD0 = 0;
    p->unkD2 = -0x80;
    p->unkD4 = -0x80;
    memset(p->unkC0, 0, 0x10);
    return p;
}
// provenance: original
void fn_80045F58(void* p, int unused, int r5)
{
    *(int*)((char*)p + 0x8c) += r5;
    *(int*)((char*)p + 0x88) += r5;
}

// provenance: original
int fn_80045F74(int *p, int *r4, int *r5, int *r6)
{
    *r4 = p[35];
    *r5 = p[16] - p[35];
    *r6 = p[6] - p[34];
    return p[15];
}

// provenance: original
void fn_80045FA4(void)
{
    fn_8004E4AC();
    (*(int*)lbl_8017A288)++;
    memset(lbl_8017A29C, 0, 0xd80);
}

// provenance: original
int criadx_spsd_probe(void* p)
{
    return strncmp(p, SPSD_str, 4) == 0;
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
