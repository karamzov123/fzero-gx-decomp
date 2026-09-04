typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
#pragma push
#pragma force_active on

typedef struct AdxHdr {
    char pad0[2];
    short unk2;
    char pad4[8];
    char unkC;
    char unkD;
    signed char unkE;
    signed char unkF;
    int unk10;
    int unk14;
    int unk18;
    short unk1C;
    char pad1E[2];
    int unk20;
    short unk24;
    short unk26;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    char pad38[4];
    int unk3C;
    int unk40;
    int unk44;
    char pad48[8];
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    char pad68[0x20];
    int unk88;
    int unk8C;
    char pad90[8];
    short unk98;
    short unk9A;
} AdxHdr;

extern unsigned char lbl_80090960[4];
extern unsigned char lbl_80090964[4];
extern unsigned char lbl_8009095C[4];
extern unsigned char lbl_80090948[8];
extern unsigned char lbl_80090938[4];
extern unsigned char lbl_80090968[8];
__declspec(section ".data") extern unsigned int lbl_8017B028;
__declspec(section ".data") extern unsigned int lbl_8017B020;
extern int fn_800463E4();
extern void memset();
extern void svmLockServer_wrapper(void);
extern void svmUnlockServer_wrapper(void);
extern void svmUnlockServer(void);
extern void svmLockServer(void);
extern u32 strlen();
extern void memcpy(void);
extern void fn_80087E80(void);
extern void __msl_strncat(void);
extern unsigned char c_CRI_str[];
extern unsigned char lbl_80090940[8];
extern unsigned char lbl_80090950[8];
extern unsigned char lbl_80090958[4];
extern unsigned char lbl_80090970[2];
extern unsigned char lbl_8017B038[288];

#pragma push
// provenance: original
int fn_800462F8(AdxHdr* p, void* a, void* b)
{
    short nch;

    p->unk2 = 1;
    if (fn_800463E4(a, b, &nch, &p->unkC, &p->unkD, &p->unkF, &p->unkE, &p->unk14,
                   &p->unk18, &p->unk10, &p->unk9A) < 0) {
        return 0;
    }

    p->unk1C = 0;
    p->unk26 = 0;
    p->unk24 = 0;
    p->unk34 = 0;
    p->unk30 = 0;
    p->unk2C = 0;
    p->unk28 = 0;
    p->unk20 = 0;
    p->unk50 = p->unkE;
    p->unk54 = p->unkF;
    p->unk58 = p->unk10;
    p->unk5C = p->unk3C;
    p->unk60 = p->unk40;
    p->unk64 = p->unk44;
    p->unk8C = 0;
    p->unk88 = 0;
    p->unk98 = 2;
    return nch;
}
#pragma pop

#pragma push
asm int fn_800463E4()
{
    nofralloc
    lbz	r0, 7(r3)
    lwz	r12, 8(r1)
    lwz	r11, 0xc(r1)
    slwi	r0, r0, 4
    lwz	r4, 0x10(r1)
    sth	r0, 0(r5)
    lbz	r0, 9(r3)
    clrlwi	r5, r0, 0x1e
    addi	r0, r5, 1
    stb	r0, 0(r9)
    lhz	r0, 0x2a(r3)
    stw	r0, 0(r10)
    lbz	r0, 8(r3)
    cmpwi	r0, 1
    beq     _8004647c
    bge     _80046430
    cmpwi	r0, 0
    bge     _8004643c
    b       _800464cc
_80046430:
    cmpwi	r0, 4
    bge     _800464cc
    b       _800464a4
_8004643c:
    li	r0, 0x10
    li	r5, 1
    stb	r0, 0(r7)
    li	r0, 0
    lbz	r9, 0(r9)
    extsb	r9, r9
    slwi	r9, r9, 1
    stb	r9, 0(r8)
    stw	r5, 0(r11)
    lwz	r9, 0xc(r3)
    srwi	r5, r9, 0x1f
    add	r5, r5, r9
    srawi	r5, r5, 1
    stw	r5, 0(r12)
    sth	r0, 0(r4)
    b       _800464cc
_8004647c:
    li	r0, 8
    li	r5, 1
    stb	r0, 0(r7)
    lbz	r0, 0(r9)
    stb	r0, 0(r8)
    stw	r5, 0(r11)
    lwz	r0, 0xc(r3)
    stw	r0, 0(r12)
    sth	r5, 0(r4)
    b       _800464cc
_800464a4:
    li	r0, 4
    li	r5, 2
    stb	r0, 0(r7)
    lbz	r0, 0(r9)
    stb	r0, 0(r8)
    stw	r5, 0(r11)
    lwz	r0, 0xc(r3)
    slwi	r0, r0, 1
    stw	r0, 0(r12)
    sth	r5, 0(r4)
_800464cc:
    li	r0, 2
    li	r5, 1
    stb	r0, 0(r8)
    li	r4, 0x10
    li	r0, -1
    stw	r5, 0(r11)
    lwz	r8, 0xc(r3)
    li	r3, 0
    srwi	r5, r8, 0x1f
    add	r5, r5, r8
    srawi	r5, r5, 1
    stw	r5, 0(r12)
    stb	r4, 0(r7)
    stb	r0, 0(r6)
    blr	
}
#pragma pop

// provenance: original fn_80046508
void fn_80046508(void *p, unsigned int value)
{
    *(unsigned int *)((unsigned char *)p + 0x20) = value;
}

// provenance: original
// provenance: original — direct retail byte-store reconstruction
void fn_80046510(void* a)
{
    *(unsigned char*)((char*)a + 1) = 0;
}

#pragma push
asm void fn_8004651C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r5, 0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    mr	r4, r31
    li	r3, 0
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    b       _80046558
_8004654c:
    stw	r3, 0x14(r4)
    addi	r4, r4, 4
    addi	r5, r5, 1
_80046558:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r5, r0
    blt     _8004654c
    li	r29, 0
    mr	r30, r31
    stw	r29, 0x2c(r31)
    b       _800465fc
_80046578:
    lwz	r28, 4(r30)
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
    lwz	r5, 0(r28)
    mr	r3, r28
    li	r4, 0
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    lwz	r4, 0(r28)
    mr	r5, r3
    mr	r3, r28
    addi	r6, r1, 8
    lwz	r12, 0x18(r4)
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r3, 8(r1)
    li	r4, 0
    lwz	r5, 0xc(r1)
    bl      memset
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r30, r30, 4
    addi	r29, r29, 1
_800465fc:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _80046578
    mr	r30, r31
    li	r29, 0
    b       _8004669c
_80046618:
    lwz	r28, 0xc(r30)
    lwz	r4, 0(r28)
    mr	r3, r28
    lwz	r12, 0x14(r4)
    mtctr	r12
    bctrl	
    lwz	r5, 0(r28)
    mr	r3, r28
    li	r4, 0
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    lwz	r4, 0(r28)
    mr	r5, r3
    mr	r3, r28
    addi	r6, r1, 8
    lwz	r12, 0x18(r4)
    li	r4, 0
    mtctr	r12
    bctrl	
    lwz	r3, 8(r1)
    li	r4, 0
    lwz	r5, 0xc(r1)
    bl      memset
    lwz	r6, 0(r28)
    mr	r3, r28
    addi	r5, r1, 8
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    addi	r30, r30, 4
    addi	r29, r29, 1
_8004669c:
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpw	r29, r0
    blt     _80046618
    li	r0, 2
    stb	r0, 1(r31)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}
#pragma pop

#pragma push
// provenance: original
void fn_800466D4(void* p)
{
    if (p != 0) {
        svmLockServer_wrapper();
        memset(p, 0, 0x30);
        svmUnlockServer_wrapper();
    }
}
#pragma pop

#pragma push
// provenance: original
void svmUnlockServer_wrapper(void)
{
    svmUnlockServer();
}
#pragma pop

#pragma push
// provenance: original
void svmLockServer_wrapper(void)
{
    svmLockServer();
}
#pragma pop

// provenance: original
void fn_80046758(void)
{
    lbl_8017B020 = 0;
}

#pragma push
// provenance: original
u32 criax_cri_tag_padsize(int flag, u32 hdr, u32 used, u32 align)
{
    if (flag == 0) {
        return align * ((0x1B + hdr + strlen(c_CRI_str) + used + align) / align) - used;
    }
    return align * ((0x33 + hdr + strlen(c_CRI_str) + used + align) / align) - used;
}
#pragma pop

// provenance: original
int fn_80046804(const u8* data, int size, u16* out)
{
    if (size < 0x10) {
        return -1;
    }
    if (*(u16*)(data + 0) != 0x8001) {
        return -2;
    }
    *out = *(s16*)(data + 2) + 4;
    return 0;
}

#pragma push
asm void fn_8004683C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r9, 0
    cmpwi	r4, 0x14
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r8
    stw	r30, 0x18(r1)
    mr	r30, r7
    stw	r29, 0x14(r1)
    mr	r29, r3
    stw	r28, 0x10(r1)
    stw	r9, 0(r5)
    bge     _8004687c
    li	r9, -1
    b       _800468a8
_8004687c:
    lhz	r0, 0(r29)
    cmplwi	r0, 0x8000
    beq     _80046890
    li	r9, -2
    b       _800468a8
_80046890:
    lha	r0, 2(r29)
    cmpwi	r0, 0x10
    bge     _800468a4
    li	r9, -1
    b       _800468a8
_800468a4:
    lbz	r8, 0x12(r29)
_800468a8:
    cmpwi	r9, 0
    beq     _800468b8
    mr	r3, r9
    b       _80046984
_800468b8:
    cmplwi	r8, 4
    li	r7, 0x3c
    bne     _800468c8
    li	r7, 0x48
_800468c8:
    cmpw	r4, r7
    bge     _800468d8
    li	r3, -1
    b       _80046984
_800468d8:
    lhz	r0, 0(r29)
    cmplwi	r0, 0x8000
    beq     _800468ec
    li	r3, -2
    b       _80046984
_800468ec:
    lha	r3, 2(r29)
    addi	r0, r7, -4
    cmpw	r3, r0
    bge     _80046904
    li	r3, -1
    b       _80046984
_80046904:
    cmplwi	r8, 4
    li	r28, 0x14
    bne     _80046914
    li	r28, 0x20
_80046914:
    add	r4, r28, r29
    lbz	r0, 5(r4)
    lbz	r3, 4(r4)
    slwi	r0, r0, 0x10
    lbz	r7, 6(r4)
    rlwimi	r0, r3, 0x18, 0, 7
    lbz	r8, 7(r4)
    rlwimi	r0, r7, 8, 0x10, 0x17
    or	r3, r8, r0
    addis	r0, r3, -0x4149
    cmplwi	r0, 0x4e46
    beq     _8004694c
    li	r3, -2
    b       _80046984
_8004694c:
    lwz	r0, 8(r4)
    mr	r3, r6
    addi	r4, r4, 0xc
    stw	r0, 0(r5)
    li	r5, 0x10
    bl      memcpy
    add	r4, r28, r29
    li	r3, 0
    lha	r0, 0x1c(r4)
    sth	r0, 0(r30)
    lha	r0, 0x20(r4)
    sth	r0, 0(r31)
    lha	r0, 0x22(r4)
    sth	r0, 2(r31)
_80046984:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}
#pragma pop

#pragma push
asm void fn_800469A4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    li	r11, 0
    cmpwi	r4, 0x14
    stw	r31, 0xc(r1)
    lwz	r31, 0x18(r1)
    sth	r11, 0(r6)
    bge     _800469c8
    li	r11, -1
    b       _800469f4
_800469c8:
    lhz	r0, 0(r3)
    cmplwi	r0, 0x8000
    beq     _800469dc
    li	r11, -2
    b       _800469f4
_800469dc:
    lha	r0, 2(r3)
    cmpwi	r0, 0x10
    bge     _800469f0
    li	r11, -1
    b       _800469f4
_800469f0:
    lbz	r12, 0x12(r3)
_800469f4:
    cmpwi	r11, 0
    beq     _80046a04
    mr	r3, r11
    b       _80046ab4
_80046a04:
    cmplwi	r12, 4
    li	r11, 0x30
    bne     _80046a14
    li	r11, 0x3c
_80046a14:
    cmpw	r4, r11
    bge     _80046a24
    li	r3, -1
    b       _80046ab4
_80046a24:
    lhz	r0, 0(r3)
    cmplwi	r0, 0x8000
    beq     _80046a38
    li	r3, -2
    b       _80046ab4
_80046a38:
    lha	r4, 2(r3)
    addi	r0, r11, -4
    cmpw	r4, r0
    bge     _80046a50
    li	r3, -1
    b       _80046ab4
_80046a50:
    cmplwi	r12, 4
    li	r4, 0x14
    bne     _80046a60
    li	r4, 0x20
_80046a60:
    lhax	r0, r3, r4
    add	r4, r4, r3
    stw	r0, 0(r5)
    lha	r0, 2(r4)
    sth	r0, 0(r6)
    lha	r0, 0(r6)
    cmpwi	r0, 1
    beq     _80046a88
    li	r3, -2
    b       _80046ab4
_80046a88:
    lha	r0, 6(r4)
    li	r3, 0
    sth	r0, 0(r7)
    lwz	r0, 8(r4)
    stw	r0, 0(r8)
    lwz	r0, 0xc(r4)
    stw	r0, 0(r9)
    lwz	r0, 0x10(r4)
    stw	r0, 0(r10)
    lwz	r0, 0x14(r4)
    stw	r0, 0(r31)
_80046ab4:
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    blr	
}
#pragma pop

// provenance: original
int fn_80046AC0(const u8* data, int size, u16* out1, u16* out2)
{
    int ret;
    u32 val;

    if (size < 0x14) {
        ret = -1;
    } else if (*(u16*)(data + 0) != 0x8000) {
        ret = -2;
    } else if (*(s16*)(data + 2) < 0x10) {
        ret = -1;
    } else {
        val = data[0x12];
        ret = 0;
    }

    if (ret != 0) {
        return -1;
    }

    if (val >= 4) {
        if (size < 0x20) {
            return -1;
        }
        if (*(u16*)(data + 0) != 0x8000) {
            return -2;
        }
        if (*(s16*)(data + 2) < 0x1c) {
            return -1;
        }
        out1[0] = *(u16*)(data + 0x18);
        out2[0] = *(u16*)(data + 0x1a);
        out1[1] = *(u16*)(data + 0x1c);
        out2[1] = *(u16*)(data + 0x1e);
    } else {
        out2[1] = 0;
        out1[1] = 0;
        out2[0] = 0;
        out1[0] = 0;
    }
    return 0;
}

// provenance: original
int fn_80046B90(const u8* data, int size, u8* out1, u8* out2)
{
    if (size < 0x14) {
        return -1;
    }
    if (*(u16*)(data + 0) != 0x8000) {
        return -2;
    }
    if (*(s16*)(data + 2) < 0x10) {
        return -1;
    }
    *out1 = data[0x12];
    *out2 = data[0x13];
    return 0;
}

// provenance: original
int fn_80046BE0(const u8* data, int size, u16* out)
{
    if (size < 0x12) {
        return -1;
    }
    if (*(u16*)(data + 0) != 0x8000) {
        return -2;
    }
    if (*(s16*)(data + 2) < 0xe) {
        return -1;
    }
    *out = *(u16*)(data + 0x10);
    return 0;
}

#pragma push
asm void fn_80046C28(void)
{
    nofralloc
    cmpwi	r4, 0x10
    lwz	r11, 8(r1)
    lwz	r4, 0xc(r1)
    bge     _80046c40
    li	r3, -1
    blr	
_80046c40:
    lbz	r12, 0(r3)
    lbz	r0, 1(r3)
    rlwimi	r0, r12, 8, 0x10, 0x17
    clrlwi	r0, r0, 0x10
    cmplwi	r0, 0x8000
    beq     _80046c60
    li	r3, -2
    blr	
_80046c60:
    lbz	r0, 2(r3)
    lbz	r12, 3(r3)
    rlwimi	r12, r0, 8, 0x10, 0x17
    addi	r0, r12, 4
    sth	r0, 0(r5)
    lbz	r0, 4(r3)
    stb	r0, 0(r6)
    lbz	r0, 5(r3)
    stb	r0, 0(r8)
    lbz	r0, 6(r3)
    stb	r0, 0(r7)
    lbz	r0, 7(r3)
    stb	r0, 0(r9)
    lbz	r0, 9(r3)
    lbz	r5, 8(r3)
    slwi	r0, r0, 0x10
    lbz	r6, 0xa(r3)
    rlwimi	r0, r5, 0x18, 0, 7
    lbz	r9, 0xb(r3)
    rlwimi	r0, r6, 8, 0x10, 0x17
    or	r0, r9, r0
    stw	r0, 0(r10)
    lbz	r0, 0xd(r3)
    lbz	r5, 0xc(r3)
    lbz	r6, 0xe(r3)
    slwi	r0, r0, 0x10
    rlwimi	r0, r5, 0x18, 0, 7
    lbz	r3, 0xf(r3)
    rlwimi	r0, r6, 8, 0x10, 0x17
    or	r0, r3, r0
    stw	r0, 0(r11)
    lbz	r5, 0(r7)
    extsb.	r0, r5
    bne     _80046cf4
    li	r0, 0
    stw	r0, 0(r4)
    b       _80046d10
_80046cf4:
    lbz	r3, 0(r8)
    extsb	r0, r5
    extsb	r3, r3
    addi	r3, r3, -2
    slwi	r3, r3, 3
    divw	r0, r3, r0
    stw	r0, 0(r4)
_80046d10:
    li	r3, 0
    blr	
}
#pragma pop

#pragma push
// provenance: original
int fn_80046D18(short* p, int n, short* out)
{
    int pos;
    int found = 0x7FFFFFFF;

    for (pos = 0; pos < n - 1; pos += 2, p++) {
        if (*p == -32768) {
            found = pos < found ? pos : found;
            break;
        }
    }

    if (found != 0x7FFFFFFF) {
        *out = found;
        return 0;
    }
    *out = 0;
    return -1;
}
#pragma pop

#pragma push
asm void CRI_SPSD_parser(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis	r7, 0x4330
    stw	r0, 0x34(r1)
    xoris	r0, r3, 0x8000
    lis	r3, lbl_80090968@ha
    stw	r0, 0x1c(r1)
    xoris	r0, r4, 0x8000
    lfd	f2, lbl_80090968@l(r3)
    lis	r4, lbl_80090938@ha
    stw	r7, 0x18(r1)
    lfs	f3, lbl_80090938@l(r4)
    lfd	f0, 0x18(r1)
    stw	r0, 0x24(r1)
    fsubs	f1, f0, f2
    stw	r7, 0x20(r1)
    lfd	f0, 0x20(r1)
    fmuls	f1, f3, f1
    stw	r31, 0x2c(r1)
    mr	r31, r6
    fsubs	f0, f0, f2
    stw	r30, 0x28(r1)
    mr	r30, r5
    fdivs	f1, f1, f0
    bl      fn_80087E80
    lis     r3, lbl_80090940@ha
    lis	r4, lbl_80090948@ha
    addi	r5, r3, lbl_80090940@l
    lfd	f2, lbl_80090948@l(r4)
    lfd	f9, 0(r5)
    lis     r3, lbl_80090950@ha
    addi	r5, r3, lbl_80090950@l
    frsqrte	f7, f9
    lis     r3, lbl_80090958@ha
    addi	r4, r3, lbl_80090958@l
    frsqrte	f10, f9
    lis	r3, lbl_8009095C@ha
    lfd	f0, 0(r5)
    fmul	f6, f7, f7
    lfs	f4, 0(r4)
    lfs	f3, lbl_8009095C@l(r3)
    fmul	f5, f10, f10
    fmul	f8, f2, f7
    fnmsub	f7, f9, f6, f0
    fmul	f6, f2, f10
    fnmsub	f5, f9, f5, f0
    fmul	f8, f8, f7
    fmul	f6, f6, f5
    fmul	f7, f8, f8
    fmul	f5, f6, f6
    fmul	f8, f2, f8
    fnmsub	f7, f9, f7, f0
    fmul	f6, f2, f6
    fnmsub	f5, f9, f5, f0
    fmul	f8, f8, f7
    fmul	f6, f6, f5
    fmul	f7, f8, f8
    fmul	f5, f6, f6
    fmul	f8, f2, f8
    fnmsub	f7, f9, f7, f0
    fmul	f6, f2, f6
    fnmsub	f5, f9, f5, f0
    fmul	f7, f8, f7
    fmul	f5, f6, f5
    fmul	f6, f9, f7
    fmul	f5, f9, f5
    frsp	f6, f6
    frsp	f7, f1
    frsp	f1, f5
    stfs	f6, 0x10(r1)
    lfs	f5, 0x10(r1)
    stfs	f1, 0xc(r1)
    fsubs	f5, f5, f7
    lfs	f1, 0xc(r1)
    fsubs	f6, f1, f4
    fadds	f4, f5, f6
    fsubs	f1, f5, f6
    fmuls	f4, f4, f1
    fcmpo	cr0, f4, f3
    ble     _80046f18
    frsqrte	f3, f4
    fmul	f1, f3, f3
    fmul	f3, f2, f3
    fnmsub	f1, f4, f1, f0
    fmul	f3, f3, f1
    fmul	f1, f3, f3
    fmul	f3, f2, f3
    fnmsub	f1, f4, f1, f0
    fmul	f3, f3, f1
    fmul	f1, f3, f3
    fmul	f2, f2, f3
    fnmsub	f0, f4, f1, f0
    fmul	f0, f2, f0
    fmul	f0, f4, f0
    frsp	f0, f0
    stfs	f0, 8(r1)
    lfs	f4, 8(r1)
_80046f18:
    fsubs	f0, f5, f4
    lis	r3, lbl_80090964@ha
    lis	r4, lbl_80090960@ha
    lfs	f1, lbl_80090964@l(r3)
    lfs	f2, lbl_80090960@l(r4)
    fdivs	f3, f0, f6
    fneg	f0, f3
    fmuls	f1, f1, f3
    fmuls	f0, f0, f3
    fmuls	f1, f2, f1
    fmuls	f0, f2, f0
    fctiwz	f1, f1
    fctiwz	f0, f0
    stfd	f1, 0x20(r1)
    stfd	f0, 0x18(r1)
    lwz	r3, 0x24(r1)
    lwz	r0, 0x1c(r1)
    sth	r3, 0(r30)
    sth	r0, 0(r31)
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}
#pragma pop

// provenance: original
void fn_80046F7C(unsigned int val)
{
    lbl_8017B028 = val;
}

#pragma push
asm void fn_80046F88(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r8, 0
    stw	r0, 0x24(r1)
    li	r0, 8
    stw	r31, 0x1c(r1)
    mr	r31, r5
    lis	r5, 0x6666
    stw	r30, 0x18(r1)
    mr	r30, r6
    addi	r7, r5, 0x6667
    stw	r29, 0x14(r1)
    mr	r29, r4
    mr	r4, r31
    stw	r28, 0x10(r1)
    mtctr	r0
_80046fc8:
    mulhw	r0, r7, r3
    srawi	r5, r0, 2
    srwi	r6, r5, 0x1f
    srawi	r0, r0, 2
    add	r5, r5, r6
    mulli	r6, r5, 0xa
    srwi	r5, r0, 0x1f
    subf	r6, r6, r3
    add.	r3, r0, r5
    stb	r6, 0(r4)
    bne     _80047000
    li	r0, 0
    stbx	r0, r31, r8
    b       _800470c0
_80047000:
    mulhw	r0, r7, r3
    addi	r8, r8, 1
    srawi	r5, r0, 2
    srwi	r6, r5, 0x1f
    srawi	r0, r0, 2
    add	r5, r5, r6
    mulli	r6, r5, 0xa
    srwi	r5, r0, 0x1f
    subf	r6, r6, r3
    add.	r3, r0, r5
    stb	r6, 1(r4)
    bne     _8004703c
    li	r0, 0
    stbx	r0, r31, r8
    b       _800470c0
_8004703c:
    mulhw	r0, r7, r3
    addi	r8, r8, 1
    srawi	r5, r0, 2
    srwi	r6, r5, 0x1f
    srawi	r0, r0, 2
    add	r5, r5, r6
    mulli	r6, r5, 0xa
    srwi	r5, r0, 0x1f
    subf	r6, r6, r3
    add.	r3, r0, r5
    stb	r6, 2(r4)
    bne     _80047078
    li	r0, 0
    stbx	r0, r31, r8
    b       _800470c0
_80047078:
    mulhw	r0, r7, r3
    addi	r8, r8, 1
    srawi	r5, r0, 2
    srwi	r6, r5, 0x1f
    srawi	r0, r0, 2
    add	r5, r5, r6
    mulli	r6, r5, 0xa
    srwi	r5, r0, 0x1f
    subf	r6, r6, r3
    add.	r3, r0, r5
    stb	r6, 3(r4)
    bne     _800470b4
    li	r0, 0
    stbx	r0, r31, r8
    b       _800470c0
_800470b4:
    addi	r8, r8, 1
    addi	r4, r4, 4
    bdnz    _80046fc8
_800470c0:
    lis     r3, lbl_8017B038@ha
    addi	r3, r3, lbl_8017B038@l
    bl      strlen
    addi	r4, r30, -1
    cmpw	r3, r4
    bge     _800470dc
    mr	r4, r3
_800470dc:
    cmpwi	r4, 0
    li	r6, 0
    ble     _800471d4
    cmpwi	r4, 8
    addi	r7, r4, -8
    ble     _8004719c
    addi	r5, r7, 7
    lis     r3, lbl_8017B038@ha
    srwi	r5, r5, 3
    addi	r0, r4, -1
    addi	r3, r3, lbl_8017B038@l
    mtctr	r5
    cmpwi	r7, 0
    ble     _8004719c
_80047114:
    subf	r5, r6, r0
    addi	r7, r6, 1
    lbzx	r8, r3, r5
    add	r5, r31, r6
    addi	r12, r6, 2
    addi	r11, r6, 3
    stb	r8, 0(r5)
    subf	r7, r7, r0
    addi	r10, r6, 4
    addi	r9, r6, 5
    lbzx	r28, r3, r7
    addi	r8, r6, 6
    addi	r7, r6, 7
    subf	r12, r12, r0
    stb	r28, 1(r5)
    subf	r11, r11, r0
    subf	r10, r10, r0
    subf	r9, r9, r0
    lbzx	r12, r3, r12
    subf	r8, r8, r0
    subf	r7, r7, r0
    addi	r6, r6, 8
    stb	r12, 2(r5)
    lbzx	r11, r3, r11
    stb	r11, 3(r5)
    lbzx	r10, r3, r10
    stb	r10, 4(r5)
    lbzx	r9, r3, r9
    stb	r9, 5(r5)
    lbzx	r8, r3, r8
    stb	r8, 6(r5)
    lbzx	r7, r3, r7
    stb	r7, 7(r5)
    bdnz    _80047114
_8004719c:
    lis     r5, lbl_8017B038@ha
    subf	r0, r6, r4
    addi	r7, r4, -1
    add	r3, r31, r6
    addi	r5, r5, lbl_8017B038@l
    mtctr	r0
    cmpw	r6, r4
    bge     _800471d4
_800471bc:
    subf	r0, r6, r7
    addi	r6, r6, 1
    lbzx	r0, r5, r0
    stb	r0, 0(r3)
    addi	r3, r3, 1
    bdnz    _800471bc
_800471d4:
    li	r0, 0
    mr	r3, r31
    stbx	r0, r31, r6
    bl      strlen
    subf	r5, r3, r30
    lis     r4, lbl_80090970@ha
    addi	r4, r4, lbl_80090970@l
    mr	r3, r31
    addi	r5, r5, -1
    bl      __msl_strncat
    mr	r3, r31
    bl      strlen
    subfic	r30, r3, 4
    mr	r3, r31
    bl      strlen
    add	r31, r31, r3
    lis	r4, 0x6666
    li	r0, 8
    mr	r8, r29
    mr	r3, r31
    addi	r6, r4, 0x6667
    li	r7, 0
    mtctr	r0
_80047230:
    mulhw	r0, r6, r8
    srawi	r4, r0, 2
    srwi	r5, r4, 0x1f
    srawi	r0, r0, 2
    add	r4, r4, r5
    mulli	r5, r4, 0xa
    srwi	r4, r0, 0x1f
    subf	r5, r5, r8
    add.	r8, r0, r4
    stb	r5, 0(r3)
    bne     _80047268
    li	r0, 0
    stbx	r0, r31, r7
    b       _80047328
_80047268:
    mulhw	r0, r6, r8
    addi	r7, r7, 1
    srawi	r4, r0, 2
    srwi	r5, r4, 0x1f
    srawi	r0, r0, 2
    add	r4, r4, r5
    mulli	r5, r4, 0xa
    srwi	r4, r0, 0x1f
    subf	r5, r5, r8
    add.	r8, r0, r4
    stb	r5, 1(r3)
    bne     _800472a4
    li	r0, 0
    stbx	r0, r31, r7
    b       _80047328
_800472a4:
    mulhw	r0, r6, r8
    addi	r7, r7, 1
    srawi	r4, r0, 2
    srwi	r5, r4, 0x1f
    srawi	r0, r0, 2
    add	r4, r4, r5
    mulli	r5, r4, 0xa
    srwi	r4, r0, 0x1f
    subf	r5, r5, r8
    add.	r8, r0, r4
    stb	r5, 2(r3)
    bne     _800472e0
    li	r0, 0
    stbx	r0, r31, r7
    b       _80047328
_800472e0:
    mulhw	r0, r6, r8
    addi	r7, r7, 1
    srawi	r4, r0, 2
    srwi	r5, r4, 0x1f
    srawi	r0, r0, 2
    add	r4, r4, r5
    mulli	r5, r4, 0xa
    srwi	r4, r0, 0x1f
    subf	r5, r5, r8
    add.	r8, r0, r4
    stb	r5, 3(r3)
    bne     _8004731c
    li	r0, 0
    stbx	r0, r31, r7
    b       _80047328
_8004731c:
    addi	r7, r7, 1
    addi	r3, r3, 4
    bdnz    _80047230
_80047328:
    lis     r3, lbl_8017B038@ha
    addi	r3, r3, lbl_8017B038@l
    bl      strlen
    addi	r4, r30, -1
    cmpw	r3, r4
    bge     _80047344
    mr	r4, r3
_80047344:
    cmpwi	r4, 0
    li	r3, 0
    ble     _8004743c
    cmpwi	r4, 8
    addi	r7, r4, -8
    ble     _80047404
    addi	r5, r7, 7
    lis     r6, lbl_8017B038@ha
    srwi	r5, r5, 3
    addi	r0, r4, -1
    addi	r12, r6, lbl_8017B038@l
    mtctr	r5
    cmpwi	r7, 0
    ble     _80047404
_8004737c:
    subf	r6, r3, r0
    addi	r5, r3, 1
    lbzx	r6, r12, r6
    add	r28, r31, r3
    addi	r10, r3, 2
    addi	r9, r3, 3
    stb	r6, 0(r28)
    subf	r5, r5, r0
    addi	r8, r3, 4
    addi	r7, r3, 5
    lbzx	r11, r12, r5
    addi	r6, r3, 6
    addi	r5, r3, 7
    subf	r10, r10, r0
    stb	r11, 1(r28)
    subf	r9, r9, r0
    subf	r8, r8, r0
    subf	r7, r7, r0
    lbzx	r10, r12, r10
    subf	r6, r6, r0
    subf	r5, r5, r0
    addi	r3, r3, 8
    stb	r10, 2(r28)
    lbzx	r9, r12, r9
    stb	r9, 3(r28)
    lbzx	r8, r12, r8
    stb	r8, 4(r28)
    lbzx	r7, r12, r7
    stb	r7, 5(r28)
    lbzx	r6, r12, r6
    stb	r6, 6(r28)
    lbzx	r5, r12, r5
    stb	r5, 7(r28)
    bdnz    _8004737c
_80047404:
    lis     r6, lbl_8017B038@ha
    subf	r0, r3, r4
    addi	r7, r4, -1
    add	r5, r31, r3
    addi	r6, r6, lbl_8017B038@l
    mtctr	r0
    cmpw	r3, r4
    bge     _8004743c
_80047424:
    subf	r0, r3, r7
    addi	r3, r3, 1
    lbzx	r0, r6, r0
    stb	r0, 0(r5)
    addi	r5, r5, 1
    bdnz    _80047424
_8004743c:
    li	r0, 0
    stbx	r0, r31, r3
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}
#pragma pop

#pragma pop
