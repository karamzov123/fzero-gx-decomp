// provenance: original
#pragma push
#pragma force_active on

typedef unsigned int u32;
extern void DCFlushRange(register void* addr, register u32 nBytes);
extern unsigned char lbl_80164D20[64];

extern unsigned char lbl_801A6B38[4];
extern unsigned char lbl_801A6B3C[4];
extern unsigned char lbl_801A6B40[4];
extern unsigned char lbl_801A6B44[4];
extern unsigned char lbl_801A6B48[4];
extern unsigned char lbl_801A6B4C[4];
extern unsigned char lbl_801A6B50[4];
extern unsigned char lbl_801A6B54[4];
extern unsigned char lbl_801A6B58[8];
// provenance: original
void* fn_8002201C(void)
{
    return &lbl_80164D20[0];
}


asm void fn_80022028(void)
{
    nofralloc
    mflr	r0
    lis	r3, 0x6666
    stw	r0, 4(r1)
    addi	r0, r3, 0x6667
    lis     r3, lbl_80164D20@ha
    stwu	r1, -8(r1)
    addi	r3, r3, lbl_80164D20@l
    lwz	r5, lbl_801A6B38
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _80022098
    cmpwi	r4, 0x14
    ble     _80022068
    li	r4, 0x14
_80022068:
    cmpwi	r4, -0x14
    bge     _80022074
    li	r4, -0x14
_80022074:
    stw	r5, 0(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B38
    subf	r4, r5, r4
    stw	r4, lbl_801A6B38
    extsh	r0, r0
    sth	r0, 4(r3)
    b       _800220a8
_80022098:
    li	r0, 0
    stw	r0, lbl_801A6B38
    stw	r0, 0(r3)
    sth	r0, 4(r3)
_800220a8:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B3C
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _80022104
    cmpwi	r4, 0x14
    ble     _800220d4
    li	r4, 0x14
_800220d4:
    cmpwi	r4, -0x14
    bge     _800220e0
    li	r4, -0x14
_800220e0:
    stw	r5, 6(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B3C
    subf	r4, r5, r4
    stw	r4, lbl_801A6B3C
    extsh	r0, r0
    sth	r0, 0xa(r3)
    b       _80022114
_80022104:
    li	r0, 0
    stw	r0, lbl_801A6B3C
    stw	r0, 6(r3)
    sth	r0, 0xa(r3)
_80022114:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B40
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _80022170
    cmpwi	r4, 0x14
    ble     _80022140
    li	r4, 0x14
_80022140:
    cmpwi	r4, -0x14
    bge     _8002214c
    li	r4, -0x14
_8002214c:
    stw	r5, 0xc(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B40
    subf	r4, r5, r4
    stw	r4, lbl_801A6B40
    extsh	r0, r0
    sth	r0, 0x10(r3)
    b       _80022180
_80022170:
    li	r0, 0
    stw	r0, lbl_801A6B40
    stw	r0, 0xc(r3)
    sth	r0, 0x10(r3)
_80022180:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B44
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _800221dc
    cmpwi	r4, 0x14
    ble     _800221ac
    li	r4, 0x14
_800221ac:
    cmpwi	r4, -0x14
    bge     _800221b8
    li	r4, -0x14
_800221b8:
    stw	r5, 0x12(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B44
    subf	r4, r5, r4
    stw	r4, lbl_801A6B44
    extsh	r0, r0
    sth	r0, 0x16(r3)
    b       _800221ec
_800221dc:
    li	r0, 0
    stw	r0, lbl_801A6B44
    stw	r0, 0x12(r3)
    sth	r0, 0x16(r3)
_800221ec:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B48
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _80022248
    cmpwi	r4, 0x14
    ble     _80022218
    li	r4, 0x14
_80022218:
    cmpwi	r4, -0x14
    bge     _80022224
    li	r4, -0x14
_80022224:
    stw	r5, 0x18(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B48
    subf	r4, r5, r4
    stw	r4, lbl_801A6B48
    extsh	r0, r0
    sth	r0, 0x1c(r3)
    b       _80022258
_80022248:
    li	r0, 0
    stw	r0, lbl_801A6B48
    stw	r0, 0x18(r3)
    sth	r0, 0x1c(r3)
_80022258:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B4C
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _800222b4
    cmpwi	r4, 0x14
    ble     _80022284
    li	r4, 0x14
_80022284:
    cmpwi	r4, -0x14
    bge     _80022290
    li	r4, -0x14
_80022290:
    stw	r5, 0x1e(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B4C
    subf	r4, r5, r4
    stw	r4, lbl_801A6B4C
    extsh	r0, r0
    sth	r0, 0x22(r3)
    b       _800222c4
_800222b4:
    li	r0, 0
    stw	r0, lbl_801A6B4C
    stw	r0, 0x1e(r3)
    sth	r0, 0x22(r3)
_800222c4:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B50
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _80022320
    cmpwi	r4, 0x14
    ble     _800222f0
    li	r4, 0x14
_800222f0:
    cmpwi	r4, -0x14
    bge     _800222fc
    li	r4, -0x14
_800222fc:
    stw	r5, 0x24(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B50
    subf	r4, r5, r4
    stw	r4, lbl_801A6B50
    extsh	r0, r0
    sth	r0, 0x28(r3)
    b       _80022330
_80022320:
    li	r0, 0
    stw	r0, lbl_801A6B50
    stw	r0, 0x24(r3)
    sth	r0, 0x28(r3)
_80022330:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B54
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _8002238c
    cmpwi	r4, 0x14
    ble     _8002235c
    li	r4, 0x14
_8002235c:
    cmpwi	r4, -0x14
    bge     _80022368
    li	r4, -0x14
_80022368:
    stw	r5, 0x2a(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B54
    subf	r4, r5, r4
    stw	r4, lbl_801A6B54
    extsh	r0, r0
    sth	r0, 0x2e(r3)
    b       _8002239c
_8002238c:
    li	r0, 0
    stw	r0, lbl_801A6B54
    stw	r0, 0x2a(r3)
    sth	r0, 0x2e(r3)
_8002239c:
    lis	r4, 0x6666
    lwz	r5, lbl_801A6B58
    addi	r0, r4, 0x6667
    mulhw	r0, r0, r5
    srawi	r0, r0, 6
    srwi	r4, r0, 0x1f
    add.	r4, r0, r4
    beq     _800223f8
    cmpwi	r4, 0x14
    ble     _800223c8
    li	r4, 0x14
_800223c8:
    cmpwi	r4, -0x14
    bge     _800223d4
    li	r4, -0x14
_800223d4:
    stw	r5, 0x30(r3)
    neg	r0, r4
    mulli	r5, r4, 0xa0
    lwz	r4, lbl_801A6B58
    subf	r4, r5, r4
    stw	r4, lbl_801A6B58
    extsh	r0, r0
    sth	r0, 0x34(r3)
    b       _80022408
_800223f8:
    li	r0, 0
    stw	r0, lbl_801A6B58
    stw	r0, 0x30(r3)
    sth	r0, 0x34(r3)
_80022408:
    li	r4, 0x36
    bl      DCFlushRange
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

// provenance: original
void fn_80022420(void)
{
    *(u32*)lbl_801A6B58 = 0;
    *(u32*)lbl_801A6B54 = 0;
    *(u32*)lbl_801A6B50 = 0;
    *(u32*)lbl_801A6B4C = 0;
    *(u32*)lbl_801A6B48 = 0;
    *(u32*)lbl_801A6B44 = 0;
    *(u32*)lbl_801A6B40 = 0;
    *(u32*)lbl_801A6B3C = 0;
    *(u32*)lbl_801A6B38 = 0;
}



void fn_8002244C(void)
{
}

asm void fn_80022450(void)
{
    nofralloc
    lwz	r4, lbl_801A6B38
    lha	r0, 0x52(r3)
    lwz	r5, lbl_801A6B44
    add	r0, r4, r0
    lwz	r4, lbl_801A6B50
    stw	r0, lbl_801A6B38
    lwz	r9, lbl_801A6B3C
    lha	r0, 0x54(r3)
    lwz	r8, lbl_801A6B48
    add	r0, r5, r0
    lwz	r7, lbl_801A6B54
    stw	r0, lbl_801A6B44
    lwz	r6, lbl_801A6B40
    lha	r0, 0x56(r3)
    lwz	r5, lbl_801A6B4C
    add	r0, r4, r0
    lwz	r4, lbl_801A6B58
    stw	r0, lbl_801A6B50
    lha	r0, 0x58(r3)
    add	r0, r9, r0
    stw	r0, lbl_801A6B3C
    lha	r0, 0x5a(r3)
    add	r0, r8, r0
    stw	r0, lbl_801A6B48
    lha	r0, 0x5c(r3)
    add	r0, r7, r0
    stw	r0, lbl_801A6B54
    lha	r0, 0x5e(r3)
    add	r0, r6, r0
    stw	r0, lbl_801A6B40
    lha	r0, 0x60(r3)
    add	r0, r5, r0
    stw	r0, lbl_801A6B4C
    lha	r0, 0x62(r3)
    add	r0, r4, r0
    stw	r0, lbl_801A6B58
    blr	
}

#pragma pop
