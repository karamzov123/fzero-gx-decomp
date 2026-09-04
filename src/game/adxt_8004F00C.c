#pragma push
#pragma force_active on

typedef struct AdxfCtx {
    int refcount;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    char unk14[0x20];
    char unk34[0x100];
    int unk134;
    char unk138[0x400];
    char unk538[0x440];
} AdxfCtx;

typedef struct AdxfSlot {
    unsigned char unk0;
    char pad1[0x43];
} AdxfSlot;

extern void DCInvalidateRange();
extern void svmUnlockServer_wrapper(void);
extern void svmLockServer_wrapper(void);
extern void criErr_CallErrCallback(void);
extern void ADXT_StartVoice(void);
extern void fn_8004AE78(void);
extern void ADXTGetState(void);
extern void fn_8004AEF0(void);
extern void fn_8004B1DC(void);
extern void fn_8004FC38(void);
extern void ADXF_Stop_family();
extern void adxt_bitstream_refill(void);
extern void strncpy(void);
extern void memset();
extern unsigned char E9040822_adxf_is_NULL_ADXF_Stop_str[36];
extern unsigned char E9040823_adxf_stm_is_NULL_ADXF_Stop_str[41];
extern unsigned char E9040828_flid_is_range_outside_str[34];
extern unsigned char E9040828_ptid_is_range_outside_str[34];
extern unsigned char lbl_800911E0[64];
extern volatile int lbl_80091250[];
extern unsigned char lbl_801309C0[136];
extern unsigned char lbl_80186630[];
extern unsigned char lbl_80186764[4];
extern unsigned char lbl_80186640[4];
extern unsigned char lbl_80186644[32];
extern unsigned char lbl_80186664[256];
extern unsigned char lbl_80186768[1024];
extern AdxfSlot lbl_80186B68[16];
extern unsigned char lbl_80186FA8[4];

asm void fn_8004F00C(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    srwi	r0, r4, 0x1f
    extsh	r10, r10
    extsh	r9, r9
    stmw	r19, 0xc(r1)
    add	r19, r0, r4
    lis     r20, lbl_800911E0@ha
    li	r27, 0
    srawi	r19, r19, 1
    addi	r22, r20, lbl_800911E0@l
    lwz	r12, 0x48(r1)
    lha	r11, 0x4e(r1)
    lha	r0, 0x52(r1)
    lha	r28, 0(r6)
    lha	r31, 2(r6)
    lha	r29, 0(r8)
    lha	r30, 2(r8)
    b       _8004f244
_8004f054:
    lha	r21, 0(r3)
    rlwinm.	r20, r21, 0, 0x10, 0x10
    beq     _8004f068
    slwi	r3, r27, 1
    b       _8004f260
_8004f068:
    lha	r23, 0(r12)
    mullw	r20, r23, r11
    xor	r21, r21, r23
    clrlwi	r21, r21, 0x13
    addi	r21, r21, 1
    add	r20, r0, r20
    sth	r20, 0(r12)
    extsh	r24, r21
    lha	r20, 0(r12)
    clrlwi	r20, r20, 0x11
    sth	r20, 0(r12)
    lha	r23, 0x12(r3)
    rlwinm.	r20, r23, 0, 0x10, 0x10
    beq     _8004f0a8
    slwi	r3, r27, 1
    b       _8004f260
_8004f0a8:
    lha	r25, 0(r12)
    li	r20, 0x10
    mullw	r21, r25, r11
    xor	r23, r23, r25
    clrlwi	r23, r23, 0x13
    addi	r23, r23, 1
    add	r21, r0, r21
    sth	r21, 0(r12)
    extsh	r23, r23
    lha	r21, 0(r12)
    clrlwi	r21, r21, 0x11
    sth	r21, 0(r12)
    mtctr	r20
    addi	r3, r3, 2
_8004f0e0:
    lbz	r26, 0(r3)
    mullw	r20, r9, r28
    lbz	r25, 0x12(r3)
    addi	r3, r3, 1
    extsb	r26, r26
    extsb	r25, r25
    srawi	r21, r26, 4
    mullw	r31, r10, r31
    add	r20, r20, r31
    mullw	r21, r21, r24
    srawi	r20, r20, 0xc
    add	r31, r21, r20
    cmpwi	r31, 0x7fff
    bgt     _8004f120
    cmpwi	r31, -0x8000
    bge     _8004f13c
_8004f120:
    cmpwi	r31, -0x8000
    bge     _8004f130
    li	r31, -0x8000
    b       _8004f13c
_8004f130:
    cmpwi	r31, 0x7fff
    ble     _8004f13c
    li	r31, 0x7fff
_8004f13c:
    mullw	r21, r9, r29
    srawi	r20, r25, 4
    mullw	r30, r10, r30
    add	r21, r21, r30
    mullw	r20, r20, r23
    srawi	r21, r21, 0xc
    add	r20, r20, r21
    cmpwi	r20, 0x7fff
    bgt     _8004f168
    cmpwi	r20, -0x8000
    bge     _8004f184
_8004f168:
    cmpwi	r20, -0x8000
    bge     _8004f178
    li	r20, -0x8000
    b       _8004f184
_8004f178:
    cmpwi	r20, 0x7fff
    ble     _8004f184
    li	r20, 0x7fff
_8004f184:
    rlwinm	r21, r26, 2, 0x1a, 0x1d
    sth	r31, 0(r5)
    lwzx	r26, r22, r21
    mullw	r21, r9, r31
    rlwinm	r25, r25, 2, 0x1a, 0x1d
    sth	r20, 0(r7)
    lwzx	r25, r22, r25
    mullw	r28, r10, r28
    add	r21, r21, r28
    mullw	r26, r26, r24
    srawi	r21, r21, 0xc
    add	r28, r26, r21
    cmpwi	r28, 0x7fff
    bgt     _8004f1c4
    cmpwi	r28, -0x8000
    bge     _8004f1e0
_8004f1c4:
    cmpwi	r28, -0x8000
    bge     _8004f1d4
    li	r28, -0x8000
    b       _8004f1e0
_8004f1d4:
    cmpwi	r28, 0x7fff
    ble     _8004f1e0
    li	r28, 0x7fff
_8004f1e0:
    mullw	r21, r9, r20
    mullw	r26, r10, r29
    add	r21, r21, r26
    mullw	r25, r25, r23
    srawi	r21, r21, 0xc
    add	r29, r25, r21
    cmpwi	r29, 0x7fff
    bgt     _8004f208
    cmpwi	r29, -0x8000
    bge     _8004f224
_8004f208:
    cmpwi	r29, -0x8000
    bge     _8004f218
    li	r29, -0x8000
    b       _8004f224
_8004f218:
    cmpwi	r29, 0x7fff
    ble     _8004f224
    li	r29, 0x7fff
_8004f224:
    sth	r28, 2(r5)
    mr	r30, r20
    addi	r5, r5, 4
    sth	r29, 2(r7)
    addi	r7, r7, 4
    bdnz    _8004f0e0
    addi	r3, r3, 0x12
    addi	r27, r27, 1
_8004f244:
    cmpw	r27, r19
    blt     _8004f054
    sth	r28, 0(r6)
    mr	r3, r4
    sth	r31, 2(r6)
    sth	r29, 0(r8)
    sth	r30, 2(r8)
_8004f260:
    lmw	r19, 0xc(r1)
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8004F26C(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    srwi	r0, r4, 0x1f
    add	r12, r0, r4
    extsh	r10, r10
    stmw	r18, 8(r1)
    lis	r20, 0x6666
    lis     r21, lbl_800911E0@ha
    srawi	r18, r12, 1
    extsh	r9, r9
    addi	r22, r20, 0x6667
    addi	r23, r21, lbl_800911E0@l
    li	r28, 0
    lwz	r11, 0x48(r1)
    lha	r19, 0x4e(r1)
    lha	r0, 0x52(r1)
    lha	r29, 0(r6)
    lha	r12, 2(r6)
    lha	r30, 0(r8)
    lha	r31, 2(r8)
    b       _8004f534
_8004f2bc:
    lha	r21, 0(r3)
    rlwinm.	r20, r21, 0, 0x10, 0x10
    beq     _8004f2d0
    slwi	r3, r28, 1
    b       _8004f550
_8004f2d0:
    lha	r24, 0(r11)
    mullw	r20, r24, r19
    xor	r21, r21, r24
    clrlwi	r21, r21, 0x13
    addi	r21, r21, 1
    add	r20, r0, r20
    sth	r20, 0(r11)
    extsh	r25, r21
    lha	r20, 0(r11)
    clrlwi	r20, r20, 0x11
    sth	r20, 0(r11)
    lha	r21, 0x12(r3)
    rlwinm.	r20, r21, 0, 0x10, 0x10
    beq     _8004f310
    slwi	r3, r28, 1
    b       _8004f550
_8004f310:
    lha	r24, 0(r11)
    li	r26, 0x10
    mullw	r20, r24, r19
    xor	r21, r21, r24
    clrlwi	r21, r21, 0x13
    addi	r21, r21, 1
    add	r20, r0, r20
    sth	r20, 0(r11)
    extsh	r24, r21
    lha	r20, 0(r11)
    clrlwi	r20, r20, 0x11
    sth	r20, 0(r11)
    mtctr	r26
    addi	r3, r3, 2
_8004f348:
    mullw	r20, r9, r29
    lbz	r27, 0(r3)
    lbz	r26, 0x12(r3)
    addi	r3, r3, 1
    extsb	r27, r27
    extsb	r26, r26
    mullw	r12, r10, r12
    srawi	r21, r27, 4
    add	r12, r20, r12
    mullw	r20, r21, r25
    srawi	r12, r12, 0xc
    add	r12, r20, r12
    cmpwi	r12, 0x7fff
    bgt     _8004f388
    cmpwi	r12, -0x8000
    bge     _8004f3a4
_8004f388:
    cmpwi	r12, -0x8000
    bge     _8004f398
    li	r12, -0x8000
    b       _8004f3a4
_8004f398:
    cmpwi	r12, 0x7fff
    ble     _8004f3a4
    li	r12, 0x7fff
_8004f3a4:
    mullw	r21, r9, r30
    srawi	r20, r26, 4
    mullw	r31, r10, r31
    add	r21, r21, r31
    mullw	r20, r20, r24
    srawi	r21, r21, 0xc
    add	r21, r20, r21
    cmpwi	r21, 0x7fff
    bgt     _8004f3d0
    cmpwi	r21, -0x8000
    bge     _8004f3ec
_8004f3d0:
    cmpwi	r21, -0x8000
    bge     _8004f3e0
    li	r21, -0x8000
    b       _8004f3ec
_8004f3e0:
    cmpwi	r21, 0x7fff
    ble     _8004f3ec
    li	r21, 0x7fff
_8004f3ec:
    add	r20, r12, r21
    mr	r31, r21
    mulli	r20, r20, 7
    mulhw	r20, r22, r20
    srawi	r20, r20, 2
    srwi	r21, r20, 0x1f
    add	r21, r20, r21
    cmpwi	r21, 0x7fff
    bgt     _8004f418
    cmpwi	r21, -0x8000
    bge     _8004f434
_8004f418:
    cmpwi	r21, -0x8000
    bge     _8004f428
    li	r21, -0x8000
    b       _8004f434
_8004f428:
    cmpwi	r21, 0x7fff
    ble     _8004f434
    li	r21, 0x7fff
_8004f434:
    sth	r21, 0(r7)
    rlwinm	r20, r27, 2, 0x1a, 0x1d
    rlwinm	r26, r26, 2, 0x1a, 0x1d
    lwzx	r20, r23, r20
    sth	r21, 0(r5)
    mullw	r27, r9, r12
    lwzx	r21, r23, r26
    mullw	r26, r10, r29
    add	r26, r27, r26
    mullw	r27, r20, r25
    srawi	r20, r26, 0xc
    add	r29, r27, r20
    cmpwi	r29, 0x7fff
    bgt     _8004f474
    cmpwi	r29, -0x8000
    bge     _8004f490
_8004f474:
    cmpwi	r29, -0x8000
    bge     _8004f484
    li	r29, -0x8000
    b       _8004f490
_8004f484:
    cmpwi	r29, 0x7fff
    ble     _8004f490
    li	r29, 0x7fff
_8004f490:
    mullw	r20, r9, r31
    mullw	r26, r10, r30
    add	r20, r20, r26
    mullw	r21, r21, r24
    srawi	r20, r20, 0xc
    add	r30, r21, r20
    cmpwi	r30, 0x7fff
    bgt     _8004f4b8
    cmpwi	r30, -0x8000
    bge     _8004f4d4
_8004f4b8:
    cmpwi	r30, -0x8000
    bge     _8004f4c8
    li	r30, -0x8000
    b       _8004f4d4
_8004f4c8:
    cmpwi	r30, 0x7fff
    ble     _8004f4d4
    li	r30, 0x7fff
_8004f4d4:
    add	r20, r29, r30
    mulli	r20, r20, 7
    mulhw	r20, r22, r20
    srawi	r20, r20, 2
    srwi	r21, r20, 0x1f
    add	r20, r20, r21
    cmpwi	r20, 0x7fff
    bgt     _8004f4fc
    cmpwi	r20, -0x8000
    bge     _8004f518
_8004f4fc:
    cmpwi	r20, -0x8000
    bge     _8004f50c
    li	r20, -0x8000
    b       _8004f518
_8004f50c:
    cmpwi	r20, 0x7fff
    ble     _8004f518
    li	r20, 0x7fff
_8004f518:
    sth	r20, 2(r7)
    addi	r7, r7, 4
    sth	r20, 2(r5)
    addi	r5, r5, 4
    bdnz    _8004f348
    addi	r3, r3, 0x12
    addi	r28, r28, 1
_8004f534:
    cmpw	r28, r18
    blt     _8004f2bc
    sth	r29, 0(r6)
    mr	r3, r4
    sth	r12, 2(r6)
    sth	r30, 0(r8)
    sth	r31, 2(r8)
_8004f550:
    lmw	r18, 8(r1)
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8004F55C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    extsh	r0, r10
    extsh	r8, r8
    extsh	r7, r7
    stmw	r26, 8(r1)
    lis     r28, lbl_800911E0@ha
    addi	r28, r28, lbl_800911E0@l
    li	r10, 0
    lha	r30, 0x2a(r1)
    lha	r12, 0(r6)
    lha	r11, 2(r6)
    b       _8004f690
_8004f58c:
    lha	r31, 0(r3)
    rlwinm.	r27, r31, 0, 0x10, 0x10
    beq     _8004f5a0
    mr	r3, r10
    b       _8004f6a4
_8004f5a0:
    lha	r26, 0(r9)
    li	r29, 0x10
    mullw	r27, r26, r0
    xor	r31, r31, r26
    clrlwi	r31, r31, 0x13
    addi	r31, r31, 1
    add	r27, r30, r27
    sth	r27, 0(r9)
    extsh	r31, r31
    lha	r27, 0(r9)
    clrlwi	r27, r27, 0x11
    sth	r27, 0(r9)
    mtctr	r29
    addi	r3, r3, 2
_8004f5d8:
    mullw	r29, r7, r12
    lbz	r26, 0(r3)
    addi	r3, r3, 1
    extsb	r26, r26
    srawi	r27, r26, 4
    mullw	r11, r8, r11
    add	r11, r29, r11
    mullw	r29, r27, r31
    srawi	r11, r11, 0xc
    add	r27, r29, r11
    cmpwi	r27, 0x7fff
    bgt     _8004f610
    cmpwi	r27, -0x8000
    bge     _8004f62c
_8004f610:
    cmpwi	r27, -0x8000
    bge     _8004f620
    li	r27, -0x8000
    b       _8004f62c
_8004f620:
    cmpwi	r27, 0x7fff
    ble     _8004f62c
    li	r27, 0x7fff
_8004f62c:
    rlwinm	r11, r26, 2, 0x1a, 0x1d
    sth	r27, 0(r5)
    lwzx	r26, r28, r11
    mullw	r11, r8, r12
    mullw	r29, r7, r27
    add	r11, r29, r11
    mullw	r12, r26, r31
    srawi	r11, r11, 0xc
    add	r12, r12, r11
    cmpwi	r12, 0x7fff
    bgt     _8004f660
    cmpwi	r12, -0x8000
    bge     _8004f67c
_8004f660:
    cmpwi	r12, -0x8000
    bge     _8004f670
    li	r12, -0x8000
    b       _8004f67c
_8004f670:
    cmpwi	r12, 0x7fff
    ble     _8004f67c
    li	r12, 0x7fff
_8004f67c:
    sth	r12, 2(r5)
    mr	r11, r27
    addi	r5, r5, 4
    bdnz    _8004f5d8
    addi	r10, r10, 1
_8004f690:
    cmpw	r10, r4
    blt     _8004f58c
    sth	r12, 0(r6)
    mr	r3, r4
    sth	r11, 2(r6)
_8004f6a4:
    lmw	r26, 8(r1)
    addi	r1, r1, 0x20
    blr	
}

// provenance: original
void fn_8004F6B0(void)
{
    AdxfCtx* g = (AdxfCtx*)lbl_80186630;

    if (--g->refcount == 0) {
        fn_8004FC38();
        g->unk4 = -1;
        g->unk8 = 0;
        g->unkC = 0;
        g->unk134 = 0;
        g->unk10 = 0;
        memset(g->unk14, 0, 0x20);
        memset(g->unk34, 0xFF, 0x100);
        memset(g->unk138, 0, 0x400);
        memset(g->unk538, 0, 0x440);
    }
}

asm void fn_8004F74C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80091250@ha
    lis     r4, lbl_80186630@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, lbl_80091250@l
    lwz	r3, 0(r3)
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_80186630@l
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _8004f7d8
    addi	r3, r31, 0x538
    li	r4, 0
    li	r5, 0x440
    bl      memset
    addi	r3, r31, 0x138
    li	r4, 0
    li	r5, 0x400
    bl      memset
    addi	r3, r31, 0x34
    li	r4, 0xff
    li	r5, 0x100
    bl      memset
    addi	r3, r31, 0x14
    li	r4, 0
    li	r5, 0x20
    bl      memset
    li	r3, 0
    li	r0, -1
    stw	r3, 0x10(r31)
    stw	r3, 0x134(r31)
    stw	r3, 0xc(r31)
    stw	r3, 8(r31)
    stw	r0, 4(r31)
_8004f7d8:
    lwz	r3, 0(r31)
    addi	r0, r3, 1
    stw	r0, 0(r31)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_8004F7F8(void* p, unsigned int size)
{
    DCInvalidateRange(p, size);
}

asm void ADXF_SetPtdId_family(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r24, 0x10(r1)
    or.	r29, r3, r3
    mr	r24, r4
    mr	r25, r5
    mr	r26, r6
    mr	r27, r7
    mr	r28, r8
    blt     _8004f84c
    cmpwi	r29, 0x100
    blt     _8004f860
_8004f84c:
    lis     r3, E9040828_ptid_is_range_outside_str@ha
    addi	r3, r3, E9040828_ptid_is_range_outside_str@l
    bl      criErr_CallErrCallback
    li	r31, -3
    b       _8004f8b8
_8004f860:
    lis     r3, lbl_80186768@ha
    slwi	r0, r29, 2
    addi	r3, r3, lbl_80186768@l
    lwzx	r3, r3, r0
    cmplwi	r3, 0
    bne     _8004f88c
    lis     r3, E9040828_ptid_is_range_outside_str@ha
    addi	r3, r3, E9040828_ptid_is_range_outside_str@l
    bl      criErr_CallErrCallback
    li	r31, -3
    b       _8004f8b8
_8004f88c:
    cmpwi	r24, 0
    blt     _8004f8a0
    lwz	r0, 8(r3)
    cmpw	r24, r0
    blt     _8004f8b4
_8004f8a0:
    lis     r3, E9040828_flid_is_range_outside_str@ha
    addi	r3, r3, E9040828_flid_is_range_outside_str@l
    bl      criErr_CallErrCallback
    li	r31, -3
    b       _8004f8b8
_8004f8b4:
    li	r31, 0
_8004f8b8:
    cmpwi	r31, 0
    bge     _8004f8dc
    li	r3, 0
    li	r0, -1
    stw	r3, 0(r26)
    mr	r3, r31
    stw	r0, 0(r27)
    stw	r0, 0(r28)
    b       _8004fa94
_8004f8dc:
    lis     r3, lbl_80186768@ha
    slwi	r0, r29, 2
    addi	r3, r3, lbl_80186768@l
    lwzx	r30, r3, r0
    lbz	r0, 0xf(r30)
    cmpwi	r0, 1
    bne     _8004f9b4
    cmpwi	r24, 0
    lwz	r29, 0x118(r30)
    addi	r5, r30, 0x11c
    li	r6, 0
    ble     _8004f9a4
    cmpwi	r24, 8
    addi	r3, r24, -8
    ble     _8004f97c
    addi	r0, r3, 7
    mr	r4, r5
    srwi	r0, r0, 3
    mtctr	r0
    cmpwi	r3, 0
    ble     _8004f97c
_8004f930:
    lwz	r3, 0(r4)
    addi	r6, r6, 8
    lwz	r0, 4(r4)
    add	r29, r29, r3
    lwz	r3, 8(r4)
    add	r29, r29, r0
    lwz	r0, 0xc(r4)
    add	r29, r29, r3
    lwz	r3, 0x10(r4)
    add	r29, r29, r0
    lwz	r0, 0x14(r4)
    add	r29, r29, r3
    lwz	r3, 0x18(r4)
    add	r29, r29, r0
    lwz	r0, 0x1c(r4)
    add	r29, r29, r3
    addi	r4, r4, 0x20
    add	r29, r29, r0
    bdnz    _8004f930
_8004f97c:
    slwi	r3, r6, 2
    subf	r0, r6, r24
    add	r3, r5, r3
    mtctr	r0
    cmpw	r6, r24
    bge     _8004f9a4
_8004f994:
    lwz	r0, 0(r3)
    addi	r3, r3, 4
    add	r29, r29, r0
    bdnz    _8004f994
_8004f9a4:
    slwi	r0, r24, 2
    lwzx	r0, r5, r0
    stw	r0, 0(r28)
    b       _8004fa6c
_8004f9b4:
    cmpwi	r24, 0
    lhz	r29, 0x118(r30)
    addi	r6, r30, 0x11a
    li	r5, 0
    ble     _8004fa60
    cmpwi	r24, 8
    addi	r3, r24, -8
    ble     _8004fa38
    addi	r0, r3, 7
    mr	r4, r6
    srwi	r0, r0, 3
    mtctr	r0
    cmpwi	r3, 0
    ble     _8004fa38
_8004f9ec:
    lhz	r3, 0(r4)
    addi	r5, r5, 8
    lhz	r0, 2(r4)
    add	r29, r29, r3
    lhz	r3, 4(r4)
    add	r29, r29, r0
    lhz	r0, 6(r4)
    add	r29, r29, r3
    lhz	r3, 8(r4)
    add	r29, r29, r0
    lhz	r0, 0xa(r4)
    add	r29, r29, r3
    lhz	r3, 0xc(r4)
    add	r29, r29, r0
    lhz	r0, 0xe(r4)
    add	r29, r29, r3
    addi	r4, r4, 0x10
    add	r29, r29, r0
    bdnz    _8004f9ec
_8004fa38:
    slwi	r3, r5, 1
    subf	r0, r5, r24
    add	r3, r6, r3
    mtctr	r0
    cmpw	r5, r24
    bge     _8004fa60
_8004fa50:
    lhz	r0, 0(r3)
    addi	r3, r3, 2
    add	r29, r29, r0
    bdnz    _8004fa50
_8004fa60:
    slwi	r0, r24, 1
    lhzx	r0, r6, r0
    stw	r0, 0(r28)
_8004fa6c:
    mr	r3, r25
    addi	r4, r30, 0x10
    li	r5, 0x100
    bl      strncpy
    lwz	r0, 0x110(r30)
    mr	r3, r31
    stw	r0, 0(r26)
    lwz	r0, 0x114(r30)
    add	r0, r0, r29
    stw	r0, 0(r27)
_8004fa94:
    lmw	r24, 0x10(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8004FAA8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    bl      svmLockServer_wrapper
    lis     r3, lbl_80186B68@ha
    li	r30, 0
    addi	r31, r3, lbl_80186B68@l
_8004facc:
    lbz	r0, 0(r31)
    cmpwi	r0, 1
    bne     _8004fc0c
    lbz	r0, 1(r31)
    cmpwi	r0, 2
    bne     _8004fb7c
    lwz	r3, 4(r31)
    bl      ADXTGetState
    stb	r3, 1(r31)
    lwz	r3, 4(r31)
    bl      fn_8004AE78
    lwz	r0, 0x14(r31)
    subf	r0, r0, r3
    stw	r0, 0x20(r31)
    lbz	r0, 1(r31)
    extsb	r0, r0
    cmpwi	r0, 3
    beq     _8004fb1c
    cmpwi	r0, 4
    bne     _8004fb7c
_8004fb1c:
    lwz	r3, 0x14(r31)
    lwz	r0, 0x20(r31)
    add	r0, r3, r0
    stw	r0, 0x14(r31)
    lwz	r0, 8(r31)
    cmplwi	r0, 0
    beq     _8004fb7c
    lbz	r0, 2(r31)
    extsb.	r0, r0
    bne     _8004fb7c
    lis	r3, lbl_80186764@ha
    lwz	r0, lbl_80186764@l(r3)
    cmpwi	r0, 1
    bne     _8004fb60
    lwz	r3, 0x24(r31)
    lwz	r4, 0x28(r31)
    bl      fn_8004F7F8
_8004fb60:
    lwz	r3, 8(r31)
    li	r0, 0
    stw	r0, 8(r31)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004fb7c:
    lbz	r0, 3(r31)
    cmpwi	r0, 1
    bne     _8004fc0c
    lwz	r3, 4(r31)
    bl      ADXTGetState
    cmpwi	r3, 1
    bne     _8004fc0c
    lwz	r3, 4(r31)
    bl      fn_8004AE78
    lwz	r0, 0x14(r31)
    subf	r0, r0, r3
    stw	r0, 0x20(r31)
    lwz	r0, 8(r31)
    cmplwi	r0, 0
    beq     _8004fbfc
    lbz	r0, 2(r31)
    extsb.	r0, r0
    bne     _8004fbfc
    lis	r3, lbl_80186764@ha
    lwz	r0, lbl_80186764@l(r3)
    cmpwi	r0, 1
    bne     _8004fbe0
    lwz	r3, 0x24(r31)
    lwz	r4, 0x28(r31)
    bl      fn_8004F7F8
_8004fbe0:
    lwz	r3, 8(r31)
    li	r0, 0
    stw	r0, 8(r31)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004fbfc:
    li	r3, 1
    li	r0, 0
    stb	r3, 1(r31)
    stb	r0, 3(r31)
_8004fc0c:
    addi	r30, r30, 1
    addi	r31, r31, 0x44
    cmpwi	r30, 0x10
    blt     _8004facc
    bl      svmUnlockServer_wrapper
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_8004FC38(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        int st = lbl_80186B68[i].unk0;
        if (st == 1) {
            ADXF_Stop_family(&lbl_80186B68[i]);
        }
    }
}

asm void ADXF_Stop_family()
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r6, lbl_80186664@ha
    lis	r4, lbl_80186640@ha
    stw	r0, 0x24(r1)
    addi	r9, r6, lbl_80186664@l
    lis     r5, lbl_80186644@ha
    li	r8, 0
    stw	r31, 0x1c(r1)
    addi	r31, r5, lbl_80186644@l
    stw	r30, 0x18(r1)
    or.	r30, r3, r3
    stw	r29, 0x14(r1)
    lwzu	r7, lbl_80186640@l(r4)
    lhz	r5, 6(r31)
    slwi	r0, r7, 0x1c
    srwi	r3, r7, 0x1f
    subf	r0, r3, r0
    addi	r5, r5, 1
    rotlwi	r0, r0, 4
    li	r7, -1
    add	r6, r0, r3
    sth	r5, 6(r31)
    slwi	r3, r6, 4
    li	r0, 3
    add	r10, r9, r3
    stw	r6, 0(r4)
    addi	r3, r6, 1
    stb	r0, 0(r10)
    stb	r8, 1(r10)
    sth	r5, 2(r10)
    stw	r30, 4(r10)
    stw	r7, 8(r10)
    stw	r7, 0xc(r10)
    stw	r3, 0(r4)
    beq     _8004ff4c
    lbz	r0, 1(r30)
    cmpwi	r0, 2
    bne     _8004feb4
    slwi	r0, r3, 0x1c
    srwi	r6, r3, 0x1f
    subf	r0, r6, r0
    lhz	r5, 0xa(r31)
    rotlwi	r0, r0, 4
    li	r3, 5
    add	r6, r0, r6
    addi	r5, r5, 1
    slwi	r0, r6, 4
    stw	r6, 0(r4)
    add	r9, r9, r0
    cmplwi	r30, 0
    stb	r3, 0(r9)
    addi	r0, r6, 1
    stb	r8, 1(r9)
    sth	r5, 2(r9)
    stw	r30, 4(r9)
    stw	r7, 8(r9)
    sth	r5, 0xa(r31)
    stw	r7, 0xc(r9)
    stw	r0, 0(r4)
    bne     _8004fd98
    lis     r3, E9040822_adxf_is_NULL_ADXF_Stop_str@ha
    addi	r3, r3, E9040822_adxf_is_NULL_ADXF_Stop_str@l
    bl      criErr_CallErrCallback
    b       _8004feb4
_8004fd98:
    lbz	r0, 1(r30)
    extsb	r0, r0
    cmpwi	r0, 1
    beq     _8004feb4
    cmpwi	r0, 3
    bne     _8004fdbc
    li	r0, 1
    stb	r0, 1(r30)
    b       _8004feb4
_8004fdbc:
    lwz	r3, 4(r30)
    cmplwi	r3, 0
    bne     _8004fdd8
    lis     r3, E9040823_adxf_stm_is_NULL_ADXF_Stop_str@ha
    addi	r3, r3, E9040823_adxf_stm_is_NULL_ADXF_Stop_str@l
    bl      criErr_CallErrCallback
    b       _8004feb4
_8004fdd8:
    bl      ADXT_StartVoice
    bl      svmLockServer_wrapper
    lwz	r3, 4(r30)
    bl      fn_8004AE78
    lwz	r0, 0x14(r30)
    subf	r0, r0, r3
    stw	r0, 0x20(r30)
    lwz	r0, 8(r30)
    cmplwi	r0, 0
    beq     _8004fe44
    lbz	r0, 2(r30)
    extsb.	r0, r0
    bne     _8004fe44
    lis	r3, lbl_80186764@ha
    lwz	r0, lbl_80186764@l(r3)
    cmpwi	r0, 1
    bne     _8004fe28
    lwz	r3, 0x24(r30)
    lwz	r4, 0x28(r30)
    bl      fn_8004F7F8
_8004fe28:
    lwz	r3, 8(r30)
    li	r0, 0
    stw	r0, 8(r30)
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8004fe44:
    li	r0, 1
    stb	r0, 1(r30)
    bl      svmUnlockServer_wrapper
    lis     r4, lbl_80186640@ha
    lis     r3, lbl_80186664@ha
    addi	r9, r4, lbl_80186640@l
    li	r6, 5
    lwz	r7, 0(r9)
    addi	r0, r3, lbl_80186664@l
    li	r5, 1
    lhz	r4, 0xa(r31)
    slwi	r3, r7, 0x1c
    srwi	r8, r7, 0x1f
    subf	r7, r8, r3
    li	r3, -1
    rotlwi	r7, r7, 4
    add	r8, r7, r8
    slwi	r7, r8, 4
    stw	r8, 0(r9)
    add	r7, r0, r7
    addi	r0, r8, 1
    stb	r6, 0(r7)
    stb	r5, 1(r7)
    sth	r4, 2(r7)
    stw	r30, 4(r7)
    stw	r3, 8(r7)
    stw	r3, 0xc(r7)
    stw	r0, 0(r9)
_8004feb4:
    lwz	r29, 4(r30)
    cmplwi	r29, 0
    beq     _8004fed8
    li	r0, 0
    mr	r3, r29
    stw	r0, 4(r30)
    bl      fn_8004AEF0
    mr	r3, r29
    bl      fn_8004B1DC
_8004fed8:
    mr	r3, r30
    li	r4, 0
    li	r5, 0x44
    bl      memset
    lis     r4, lbl_80186640@ha
    lis     r3, lbl_80186664@ha
    addi	r9, r4, lbl_80186640@l
    li	r6, 3
    lwz	r7, 0(r9)
    addi	r0, r3, lbl_80186664@l
    li	r5, 1
    lhz	r4, 6(r31)
    slwi	r3, r7, 0x1c
    srwi	r8, r7, 0x1f
    subf	r7, r8, r3
    li	r3, -1
    rotlwi	r7, r7, 4
    add	r8, r7, r8
    slwi	r7, r8, 4
    stw	r8, 0(r9)
    add	r7, r0, r7
    addi	r0, r8, 1
    stb	r6, 0(r7)
    stb	r5, 1(r7)
    sth	r4, 2(r7)
    stw	r30, 4(r7)
    stw	r3, 8(r7)
    stw	r3, 0xc(r7)
    stw	r0, 0(r9)
_8004ff4c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8004FF68(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r4, lbl_801309C0@ha
    stw	r0, 0x24(r1)
    addi	r4, r4, lbl_801309C0@l
    stmw	r27, 0xc(r1)
    mr	r27, r3
    lwz	r0, 0x10(r3)
    lwz	r28, 0x30(r4)
    clrlwi.	r0, r0, 0x1d
    beq     _8004fff4
    lis     r4, lbl_80186FA8@ha
    subfic	r29, r0, 8
    addi	r5, r4, lbl_80186FA8@l
    lwz	r4, 0(r5)
    addi	r0, r4, 1
    stw	r0, 0(r5)
    lwz	r0, 0xc(r27)
    cmpw	r0, r29
    bge     _8004ffbc
    bl      adxt_bitstream_refill
_8004ffbc:
    lwz	r4, 0xc(r27)
    cmpw	r29, r4
    ble     _8004ffe0
    lwz	r3, 0x10(r27)
    li	r0, 0
    add	r3, r3, r4
    stw	r3, 0x10(r27)
    stw	r0, 0xc(r27)
    b       _8004fff4
_8004ffe0:
    subf	r0, r29, r4
    stw	r0, 0xc(r27)
    lwz	r0, 0x10(r27)
    add	r0, r0, r29
    stw	r0, 0x10(r27)
_8004fff4:
    lis     r3, lbl_80186FA8@ha
    addi	r4, r3, lbl_80186FA8@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    lwz	r0, 0xc(r27)
    cmpwi	r0, 0xc
    bge     _8005001c
    mr	r3, r27
    bl      adxt_bitstream_refill
_8005001c:
    lwz	r4, 0xc(r27)
    cmpwi	r4, 0xc
    bge     _80050040
    lwz	r0, 0x10(r27)
    li	r5, 0
    add	r0, r0, r4
    stw	r0, 0x10(r27)
    stw	r5, 0xc(r27)
    b       _8005006c
_80050040:
    lis     r3, lbl_801309C0@ha
    lwz	r5, 8(r27)
    addi	r3, r3, lbl_801309C0@l
    addi	r4, r4, -0xc
    lwz	r0, 0x30(r3)
    sraw	r5, r5, r4
    stw	r4, 0xc(r27)
    and	r5, r5, r0
    lwz	r3, 0x10(r27)
    addi	r0, r3, 0xc
    stw	r0, 0x10(r27)
_8005006c:
    lis     r4, lbl_801309C0@ha
    lis     r3, lbl_80186FA8@ha
    mr	r29, r5
    addi	r30, r4, lbl_801309C0@l
    addi	r31, r3, lbl_80186FA8@l
    b       _8005011c
_80050084:
    and	r0, r29, r28
    cmplwi	r0, 0xfff
    bne     _80050098
    li	r3, 1
    b       _8005016c
_80050098:
    addis	r0, r29, 0x7fff
    cmplwi	r0, 0xc
    bne     _800500ac
    li	r3, 2
    b       _8005016c
_800500ac:
    lwz	r3, 0(r31)
    slwi	r29, r29, 4
    addi	r0, r3, 1
    stw	r0, 0(r31)
    lwz	r0, 0xc(r27)
    cmpwi	r0, 4
    bge     _800500d0
    mr	r3, r27
    bl      adxt_bitstream_refill
_800500d0:
    lwz	r3, 0xc(r27)
    cmpwi	r3, 4
    bge     _800500f4
    lwz	r0, 0x10(r27)
    li	r4, 0
    add	r0, r0, r3
    stw	r0, 0x10(r27)
    stw	r4, 0xc(r27)
    b       _80050118
_800500f4:
    lwz	r4, 8(r27)
    addi	r3, r3, -4
    lwz	r0, 0x10(r30)
    sraw	r4, r4, r3
    stw	r3, 0xc(r27)
    and	r4, r4, r0
    lwz	r3, 0x10(r27)
    addi	r0, r3, 4
    stw	r0, 0x10(r27)
_80050118:
    or	r29, r29, r4
_8005011c:
    lwz	r3, 4(r27)
    li	r4, 1
    lwz	r5, 0(r3)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bne     _8005015c
    lwz	r0, 0xc(r27)
    cmpwi	r0, 0
    bne     _8005015c
    lwz	r0, 0x24(r27)
    cmpwi	r0, 0
    bne     _8005015c
    li	r0, 1
    b       _80050160
_8005015c:
    li	r0, 0
_80050160:
    cmpwi	r0, 0
    beq     _80050084
    li	r3, 0
_8005016c:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
