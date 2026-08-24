typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void PPCMfpmc1(register u32 v);
extern void PPCMfpmc3(register u32 v);
extern void PPCMfpmc4(register u32 v);
extern void OSReport(const char* fmt, ...);
extern void* memcpy(void* dst, const void* src, unsigned long n);
extern void __cvt_fp2unsigned(register u32 a, register u32 b);
extern void OSGetTime(void* t);
extern void OSSetPeriodicAlarm(void* alarm, void* start, void* period, void (*handler)(void));
extern void OSCancelAlarm(void* alarm);
extern void fn_80015B24(register u32 a, register u32 b);
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void fn_80038BFC(register u32 a);
extern void fn_80038A88(register u32 a);
extern void GXClearVtxDesc(register u32 a);
extern void fn_80033A6C(register u32 a);
extern void fn_80037B14(register u32 a);
extern void fn_80037BF4(register u32 a);
extern void __GXSetChanAmbColor(register u32 a);
extern void fn_80035960(register u32 a);
extern void GXSetChanCtrl(register u32 a);
extern void fn_80037014(register u32 a);
extern void GXSetNumTexGens(register u32 a);
extern void fn_800377C8(register u32 a);
extern void fn_80037BC0(register u32 a);
extern void GXSetVtxDesc(register u32 a);
extern void fn_80032F80(register u32 a);
extern unsigned char perf_autosample_negative_str[48];
extern unsigned char lbl_8012B658[144];
extern unsigned char lbl_80178BF0[40];
extern unsigned char lbl_80178C18[144];

// Lives in dolphin/gx/GXFog.c
asm int fn_8003D588(register u32 a);

#pragma push
#pragma force_active on

asm void fn_8003E344(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    lwz	r0, -0x7780(r13)
    cmpwi	r0, 0
    beq     _8003e8b4
    lwz	r0, -0x7e38(r13)
    cmplwi	r0, 0xffff
    bge     _8003e6cc
    lwz	r0, -0x7e38(r13)
    lwz	r3, -0x7e38(r13)
    clrlwi	r4, r0, 0x18
    lbz	r0, -0x7790(r13)
    rlwinm	r3, r3, 0x18, 0x1c, 0x1f
    cmpw	r3, r0
    beq     _8003e558
    lwz	r0, -0x7e3c(r13)
    cmpwi	r0, 0
    blt     _8003e428
    bl      PPCMfpmc4
    lwz	r5, -0x777c(r13)
    li	r4, 1
    lwz	r0, -0x7e3c(r13)
    lwz	r6, -0x7774(r13)
    slwi	r5, r5, 4
    mulli	r0, r0, 0xb0
    lwzx	r5, r6, r5
    add	r5, r5, r0
    stw	r3, 0x10(r5)
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r5, r3
    add	r3, r3, r0
    bl      fn_8003D588
    bl      PPCMfpmc3
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x24(r4)
    bl      PPCMfpmc1
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x34(r4)
_8003e428:
    li	r0, -1
    lwz	r3, -0x7770(r13)
    stw	r0, -0x7e3c(r13)
    addi	r3, r3, -1
    lwz	r0, -0x7780(r13)
    cmplw	r0, r3
    blt     _8003e450
    stw	r3, -0x7780(r13)
    lwz	r3, -0x7780(r13)
    b       _8003e45c
_8003e450:
    lwz	r3, -0x7780(r13)
    addi	r0, r3, 1
    stw	r0, -0x7780(r13)
_8003e45c:
    stw	r3, -0x7e3c(r13)
    li	r5, 0xff
    lwz	r3, -0x777c(r13)
    li	r31, 0
    lwz	r0, -0x7e3c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r4, r3
    stbx	r5, r3, r0
    li	r4, 0
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r5, r3
    add	r3, r3, r0
    stw	r31, 0x14(r3)
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r5, r3
    add	r3, r3, r0
    bl      fn_8003D588
    bl      PPCMfpmc4
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0xc(r4)
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r4, r3
    add	r3, r3, r0
    stw	r31, 0x10(r3)
    bl      PPCMfpmc3
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x20(r4)
    bl      PPCMfpmc1
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x30(r4)
    b       _8003e8b4
_8003e558:
    lwz	r3, -0x7770(r13)
    lwz	r0, -0x7780(r13)
    addi	r3, r3, -1
    cmplw	r0, r3
    blt     _8003e578
    stw	r3, -0x7780(r13)
    lwz	r3, -0x7780(r13)
    b       _8003e584
_8003e578:
    lwz	r3, -0x7780(r13)
    addi	r0, r3, 1
    stw	r0, -0x7780(r13)
_8003e584:
    lwz	r0, -0x777c(r13)
    mulli	r31, r3, 0xb0
    lwz	r3, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r3, r0
    mulli	r30, r4, 0xb0
    add	r3, r0, r31
    add	r4, r0, r30
    li	r5, 0xb0
    bl      memcpy
    bl      PPCMfpmc4
    lwz	r0, -0x777c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r4, r0
    add	r4, r0, r31
    stw	r3, 0x10(r4)
    bl      PPCMfpmc3
    lwz	r0, -0x777c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r4, r0
    add	r4, r0, r31
    stw	r3, 0x24(r4)
    bl      PPCMfpmc1
    lwz	r0, -0x777c(r13)
    li	r4, 1
    lwz	r5, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r5, r0
    add	r5, r0, r31
    stw	r3, 0x34(r5)
    lwz	r0, -0x777c(r13)
    lwz	r3, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r3, r0
    add	r3, r0, r31
    bl      fn_8003D588
    lwz	r0, -0x777c(r13)
    li	r4, 0xff
    lwz	r3, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r3, r3, r0
    stbx	r4, r3, r31
    bl      PPCMfpmc4
    lwz	r0, -0x777c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r4, r0
    add	r4, r0, r30
    stw	r3, 0xc(r4)
    bl      PPCMfpmc3
    lwz	r0, -0x777c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r4, r0
    add	r4, r0, r30
    stw	r3, 0x20(r4)
    bl      PPCMfpmc1
    lwz	r0, -0x777c(r13)
    li	r4, 0
    lwz	r5, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r5, r0
    add	r5, r0, r30
    stw	r3, 0x30(r5)
    lwz	r0, -0x777c(r13)
    lwz	r3, -0x7774(r13)
    slwi	r0, r0, 4
    lwzx	r0, r3, r0
    add	r3, r0, r30
    bl      fn_8003D588
    lwz	r3, -0x777c(r13)
    li	r5, 1
    lwz	r4, -0x7774(r13)
    li	r0, -1
    slwi	r3, r3, 4
    lwzx	r3, r4, r3
    add	r3, r3, r30
    stw	r5, 0x14(r3)
    stw	r0, -0x7e3c(r13)
    b       _8003e8b4
_8003e6cc:
    lwz	r0, -0x7e3c(r13)
    cmpwi	r0, 0
    bge     _8003e6ec
    lis     r3, perf_autosample_negative_str@ha
    crxor	6, 6, 6
    addi	r3, r3, perf_autosample_negative_str@l
    bl      OSReport
    b       _8003e8b4
_8003e6ec:
    lwz	r0, -0x7e3c(r13)
    cmpwi	r0, 0
    blt     _8003e788
    bl      PPCMfpmc4
    lwz	r5, -0x777c(r13)
    li	r4, 1
    lwz	r0, -0x7e3c(r13)
    lwz	r6, -0x7774(r13)
    slwi	r5, r5, 4
    mulli	r0, r0, 0xb0
    lwzx	r5, r6, r5
    add	r5, r5, r0
    stw	r3, 0x10(r5)
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r5, r3
    add	r3, r3, r0
    bl      fn_8003D588
    bl      PPCMfpmc3
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x24(r4)
    bl      PPCMfpmc1
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x34(r4)
_8003e788:
    li	r0, -1
    lwz	r3, -0x7770(r13)
    stw	r0, -0x7e3c(r13)
    addi	r3, r3, -1
    lwz	r0, -0x7780(r13)
    cmplw	r0, r3
    blt     _8003e7b0
    stw	r3, -0x7780(r13)
    lwz	r3, -0x7780(r13)
    b       _8003e7bc
_8003e7b0:
    lwz	r3, -0x7780(r13)
    addi	r0, r3, 1
    stw	r0, -0x7780(r13)
_8003e7bc:
    stw	r3, -0x7e3c(r13)
    li	r5, 0xff
    lwz	r3, -0x777c(r13)
    li	r31, 0
    lwz	r0, -0x7e3c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r4, r3
    stbx	r5, r3, r0
    li	r4, 0
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r5, r3
    add	r3, r3, r0
    stw	r31, 0x14(r3)
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r5, r3
    add	r3, r3, r0
    bl      fn_8003D588
    bl      PPCMfpmc4
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0xc(r4)
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r4, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r4, r3
    add	r3, r3, r0
    stw	r31, 0x10(r3)
    bl      PPCMfpmc3
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x20(r4)
    bl      PPCMfpmc1
    lwz	r4, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r4, r4, 4
    mulli	r0, r0, 0xb0
    lwzx	r4, r5, r4
    add	r4, r4, r0
    stw	r3, 0x30(r4)
_8003e8b4:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void fn_8003E8CC(register u32 a)
{
    nofralloc
    mflr	r0
    lis	r3, -0x8000
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    lwz	r0, 0xf8(r3)
    lis	r3, 0x1062
    addi	r3, r3, 0x4dd3
    lfd	f2, -0x7c80(r2)
    srwi	r0, r0, 2
    mulhwu	r0, r3, r0
    srwi	r0, r0, 6
    stw	r0, 0x14(r1)
    lis	r0, 0x4330
    stw	r0, 0x10(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f2
    fmuls	f1, f1, f0
    bl      __cvt_fp2unsigned
    mr	r31, r3
    bl      OSGetTime
    lis     r6, fn_8003E344@ha
    addi	r9, r6, fn_8003E344@l
    lis     r7, lbl_80178BF0@ha
    addi	r5, r3, 0
    addi	r3, r7, lbl_80178BF0@l
    addi	r6, r4, 0
    addi	r8, r31, 0
    li	r7, 0
    bl      OSSetPeriodicAlarm
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr
}

asm int fn_8003E958(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      OSDisableInterrupts
    lwz	r0, -0x7e3c(r13)
    addi	r31, r3, 0
    cmpwi	r0, 0
    blt     _8003e9c4
    bl      PPCMfpmc4
    lwz	r5, -0x777c(r13)
    li	r4, 1
    lwz	r0, -0x7e3c(r13)
    lwz	r6, -0x7774(r13)
    slwi	r5, r5, 4
    mulli	r0, r0, 0xb0
    lwzx	r5, r6, r5
    add	r5, r5, r0
    stw	r3, 0x10(r5)
    lwz	r3, -0x777c(r13)
    lwz	r0, -0x7e3c(r13)
    lwz	r5, -0x7774(r13)
    slwi	r3, r3, 4
    mulli	r0, r0, 0xb0
    lwzx	r3, r5, r3
    add	r3, r3, r0
    bl      fn_8003D588
_8003e9c4:
    lis     r3, lbl_80178BF0@ha
    addi	r3, r3, lbl_80178BF0@l
    bl      OSCancelAlarm
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr
}

asm void fn_8003E9EC(void)
{
    nofralloc
    mflr	r0
    lis     r4, lbl_80178C18@ha
    stw	r0, 4(r1)
    lis     r5, lbl_8012B658@ha
    addi	r0, r4, lbl_80178C18@l
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r5, lbl_8012B658@l
    stw	r30, 0x20(r1)
    addi	r30, r3, 0
    mr	r3, r0
    bl      fn_80015B24
    lwz	r7, -0x776c(r13)
    lis	r6, -0x8000
    lis	r4, -0x7777
    lwz	r5, 0xfc(r6)
    addi	r0, r7, 1
    mulli	r3, r0, 7
    lwz	r0, 0xf8(r6)
    lfd	f2, -0x7c70(r2)
    stw	r30, -0x774c(r13)
    addi	r6, r4, -0x7777
    stw	r3, 0x1c(r1)
    lis	r4, 0x4330
    mulhwu	r3, r6, r5
    stw	r4, 0x18(r1)
    lfd	f0, 0x18(r1)
    fsubs	f0, f0, f2
    srwi	r3, r3, 5
    mulli	r5, r3, 3
    stfs	f0, -0x775c(r13)
    mulhwu	r0, r6, r0
    lfs	f0, -0x775c(r13)
    stw	r5, -0x7760(r13)
    srwi	r3, r0, 6
    stw	r3, -0x7758(r13)
    addi	r0, r7, 2
    mulli	r0, r0, 0x13
    stfs	f0, 0x5c(r31)
    stfs	f0, 0x4c(r31)
    stfs	f0, 0x3c(r31)
    stfs	f0, 0x34(r31)
    stfs	f0, 0x2c(r31)
    stfs	f0, 0xc(r31)
    lfs	f1, -0x7c78(r2)
    stw	r0, 0x14(r1)
    stfs	f1, 0x38(r31)
    stw	r4, 0x10(r1)
    stfs	f1, 0x28(r31)
    lfd	f0, 0x10(r1)
    stfs	f1, 0x20(r31)
    fsubs	f0, f0, f2
    stfs	f1, 0x18(r31)
    stfs	f0, 0x84(r31)
    lfs	f0, 0x84(r31)
    stfs	f0, 0x8c(r31)
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr
}

asm int fn_8003EAE4(register u32 a)
{
    nofralloc
    mflr	r0
    lis     r3, lbl_80178C18@ha
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, lbl_80178C18@l
    addi	r3, r31, 0x70
    bl      fn_80038BFC
    lfs	f0, -0x7c68(r2)
    addi	r3, r31, 0x30
    li	r4, 1
    stfs	f0, 0x30(r31)
    stfs	f0, 0x34(r31)
    stfs	f0, 0x38(r31)
    stfs	f0, 0x3c(r31)
    stfs	f0, 0x40(r31)
    stfs	f0, 0x44(r31)
    stfs	f0, 0x48(r31)
    stfs	f0, 0x4c(r31)
    stfs	f0, 0x50(r31)
    stfs	f0, 0x54(r31)
    stfs	f0, 0x58(r31)
    stfs	f0, 0x5c(r31)
    stfs	f0, 0x60(r31)
    stfs	f0, 0x64(r31)
    stfs	f0, 0x68(r31)
    stfs	f0, 0x6c(r31)
    lfs	f0, -0x7c64(r2)
    stfs	f0, 0x30(r31)
    lfs	f0, -0x7c60(r2)
    stfs	f0, 0x44(r31)
    lfs	f0, -0x7c5c(r2)
    stfs	f0, 0x58(r31)
    stfs	f0, 0x6c(r31)
    lfs	f0, -0x7c58(r2)
    stfs	f0, 0x3c(r31)
    lfs	f0, -0x7c54(r2)
    stfs	f0, 0x4c(r31)
    bl      fn_80038A88
    bl      GXClearVtxDesc
    bl      fn_80033A6C
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      fn_80037B14
    li	r3, 0
    bl      fn_80037BF4
    li	r3, 1
    bl      __GXSetChanAmbColor
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 0
    li	r8, 0
    li	r9, 2
    bl      fn_80035960
    li	r3, 0
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 4
    bl      GXSetChanCtrl
    li	r3, 0
    li	r4, 4
    bl      fn_80037014
    li	r3, 0
    bl      GXSetNumTexGens
    li	r3, 1
    bl      fn_800377C8
    li	r3, 0
    li	r4, 7
    li	r5, 0
    bl      fn_80037BC0
    li	r3, 9
    li	r4, 1
    bl      GXSetVtxDesc
    li	r3, 0
    li	r4, 9
    li	r5, 1
    li	r6, 4
    li	r7, 0
    bl      fn_80032F80
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr
}

#pragma pop
