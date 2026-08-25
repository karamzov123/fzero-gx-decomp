#pragma push
#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GXSetChanMatColor(register u32 a);
extern void GXLoadMatIdxTripleToXF(register void* p);
extern void GXBegin(void);
extern void GXSetLineWidth(register u16 width, register u32 fmt);
extern void fn_8003EC44(register u32 a);
extern void fn_8003F834(register u32 a);

extern unsigned char lbl_801A6590[4];
extern unsigned char lbl_801A6598[4];
extern unsigned char lbl_801A659C[4];
extern unsigned char lbl_801A65A0[4];
extern unsigned char lbl_801A65A4[4];
extern unsigned char lbl_801A65A8[4];
extern unsigned char lbl_801A65AC[4];
extern unsigned char lbl_801A65B0[4];
extern unsigned char lbl_801A65B4[4];
extern unsigned char lbl_801A65B8[4];
extern unsigned char lbl_801A65F0[4];
extern unsigned char lbl_801A65F4[4];
extern unsigned char lbl_801A65F8[4];
extern unsigned char lbl_801A65FC[4];
extern unsigned char lbl_801A6600[8];
extern unsigned char lbl_801A6C44[4];
extern unsigned char lbl_801A6C48[4];
extern unsigned char lbl_801A6C4C[4];
extern unsigned char lbl_801A6C60[4];
extern unsigned char lbl_801A6C6C[4];
extern unsigned char lbl_801A6C74[4];
asm void fn_8003FF88(register void* arg0)
{
    nofralloc
    mflr	r0
    lis	r3, -0x7fed
    stw	r0, 4(r1)
    stwu	r1, -0x2d0(r1)
    stfd	f31, 0x2c8(r1)
    stfd	f30, 0x2c0(r1)
    stfd	f29, 0x2b8(r1)
    stfd	f28, 0x2b0(r1)
    stmw	r17, 0x274(r1)
    addi	r28, r3, -0x49a8
    lwz	r0, lbl_801A6C74
    cmplwi	r0, 0
    beq     _80041080
    lwz	r3, lbl_801A6C44
    lwz	r0, lbl_801A65F0
    lwz	r6, lbl_801A6C4C
    slwi	r5, r3, 4
    cmpwi	r0, 0
    lwzx	r18, r6, r5
    beq     _80040004
    lis	r4, -0x8000
    lis	r3, -0x7777
    lwz	r0, 0xfc(r4)
    addi	r3, r3, -0x7777
    mulhwu	r0, r3, r0
    add	r3, r6, r5
    lwz	r3, 8(r3)
    srwi	r0, r0, 5
    divwu	r3, r3, r0
    addi	r0, r3, 1
    stw	r0, lbl_801A6590
_80040004:
    lwz	r7, lbl_801A6590
    lis	r31, -0x8000
    lis	r4, -0x7777
    lfd	f2, -0x7c70(r2)
    stw	r7, 0x26c(r1)
    lis	r30, 0x4330
    lfs	f3, -0x7c78(r2)
    stw	r30, 0x268(r1)
    addi	r29, r4, -0x7777
    lwz	r0, 0xfc(r31)
    lis	r3, -0x7fe8
    lfd	f0, 0x268(r1)
    mulhwu	r0, r29, r0
    fsubs	f0, f0, f2
    fdivs	f0, f3, f0
    srwi	r0, r0, 5
    mullw	r0, r0, r7
    stw	r0, lbl_801A6C60
    add	r5, r6, r5
    stfs	f0, -0x7e2c(r13)
    addi	r3, r3, -0x73e8
    lwz	r0, lbl_801A6C60
    li	r4, 0
    lwz	r5, 8(r5)
    stw	r0, 0x25c(r1)
    stw	r5, 0x264(r1)
    stw	r30, 0x260(r1)
    stw	r30, 0x258(r1)
    lfd	f1, 0x260(r1)
    lfd	f0, 0x258(r1)
    fsubs	f1, f1, f2
    fsubs	f0, f0, f2
    fdivs	f0, f1, f0
    fmuls	f31, f3, f0
    bl      GXLoadMatIdxTripleToXF
    lwz	r0, lbl_801A6598
    addi	r4, r1, 0x1ec
    li	r3, 4
    stw	r0, 0x1ec(r1)
    bl      GXSetChanMatColor
    li	r3, 0x80
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lfs	f2, -0x7c68(r2)
    lis	r17, -0x33ff
    lwz	r0, lbl_801A659C
    addi	r4, r1, 0x1e8
    stfs	f2, -0x8000(r17)
    lfs	f1, -0x7c48(r2)
    li	r3, 4
    stfs	f2, -0x8000(r17)
    lfs	f3, -0x775c(r13)
    stfs	f1, -0x8000(r17)
    lfs	f0, -0x7c78(r2)
    stfs	f2, -0x8000(r17)
    stfs	f3, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f3, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stw	r0, 0x1e8(r1)
    bl      GXSetChanMatColor
    li	r3, 0xc
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 8
    bl      GXBegin
    lfs	f2, 4(r28)
    lfs	f0, 0(r28)
    lwz	r3, lbl_801A6590
    stfs	f0, -0x8000(r17)
    lfs	f1, -0x7c48(r2)
    cmplwi	r3, 1
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    lfs	f2, 0xc(r28)
    lfs	f0, 8(r28)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    lfs	f2, 0x14(r28)
    lfs	f0, 0x10(r28)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    lfs	f2, 0x1c(r28)
    lfs	f0, 0x18(r28)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    lfs	f2, 0x24(r28)
    lfs	f0, 0x20(r28)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    lfs	f2, 0x2c(r28)
    lfs	f0, 0x28(r28)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    lfs	f2, 0x34(r28)
    lfs	f0, 0x30(r28)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    lfs	f2, 0x3c(r28)
    lfs	f0, 0x38(r28)
    stfs	f0, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    ble     _800403b4
    addi	r0, r3, -1
    rlwinm	r5, r0, 1, 0x10, 0x1e
    li	r3, 0xa8
    li	r4, 0
    bl      GXBegin
    lwz	r0, 0xfc(r31)
    li	r6, 1
    lwz	r3, lbl_801A6590
    mulhwu	r0, r29, r0
    lfs	f5, -0x7c78(r2)
    lfd	f4, -0x7c70(r2)
    lwz	r4, lbl_801A6C60
    lfs	f0, -0x7c48(r2)
    cmplwi	r3, 1
    srwi	r5, r0, 5
    addi	r3, r3, -1
    ble     _800403b4
    rlwinm.	r0, r3, 0x1e, 2, 0x1f
    mtctr	r0
    beq     _8004035c
_80040228:
    mullw	r0, r6, r5
    stw	r4, 0x264(r1)
    lfs	f6, 0x44(r28)
    stw	r30, 0x260(r1)
    lfd	f2, 0x260(r1)
    stw	r0, 0x25c(r1)
    addi	r6, r6, 1
    mullw	r0, r6, r5
    fsubs	f2, f2, f4
    stw	r30, 0x258(r1)
    lfd	f3, 0x258(r1)
    stw	r4, 0x264(r1)
    fsubs	f3, f3, f4
    stw	r0, 0x25c(r1)
    addi	r6, r6, 1
    mullw	r0, r6, r5
    stw	r30, 0x258(r1)
    fdivs	f1, f3, f2
    lfd	f3, 0x258(r1)
    stw	r30, 0x260(r1)
    lfd	f2, 0x260(r1)
    addi	r6, r6, 1
    fmuls	f8, f5, f1
    stw	r0, 0x25c(r1)
    fsubs	f3, f3, f4
    mullw	r0, r6, r5
    fsubs	f2, f2, f4
    stw	r4, 0x264(r1)
    fdivs	f1, f3, f2
    stfs	f8, -0x8000(r17)
    addi	r6, r6, 1
    stw	r30, 0x258(r1)
    lfd	f3, 0x258(r1)
    stw	r30, 0x260(r1)
    fsubs	f3, f3, f4
    lfd	f2, 0x260(r1)
    stfs	f6, -0x8000(r17)
    fsubs	f2, f2, f4
    stfs	f0, -0x8000(r17)
    lfs	f7, 0x4c(r28)
    stw	r0, 0x25c(r1)
    stfs	f8, -0x8000(r17)
    fmuls	f8, f5, f1
    fdivs	f1, f3, f2
    stfs	f7, -0x8000(r17)
    stw	r4, 0x264(r1)
    stfs	f0, -0x8000(r17)
    stw	r30, 0x258(r1)
    stw	r30, 0x260(r1)
    lfd	f3, 0x258(r1)
    stfs	f8, -0x8000(r17)
    lfd	f2, 0x260(r1)
    fsubs	f3, f3, f4
    stfs	f6, -0x8000(r17)
    fsubs	f2, f2, f4
    stfs	f0, -0x8000(r17)
    stfs	f8, -0x8000(r17)
    fmuls	f8, f5, f1
    fdivs	f1, f3, f2
    stfs	f7, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f8, -0x8000(r17)
    stfs	f6, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f8, -0x8000(r17)
    fmuls	f8, f5, f1
    stfs	f7, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f8, -0x8000(r17)
    stfs	f6, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f8, -0x8000(r17)
    stfs	f7, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    bdnz    _80040228
    andi.	r3, r3, 3
    beq     _800403b4
_8004035c:
    mtctr	r3
_80040360:
    mullw	r0, r6, r5
    stw	r4, 0x264(r1)
    lfs	f6, 0x44(r28)
    stw	r30, 0x260(r1)
    lfd	f2, 0x260(r1)
    stw	r0, 0x25c(r1)
    fsubs	f2, f2, f4
    addi	r6, r6, 1
    stw	r30, 0x258(r1)
    lfd	f3, 0x258(r1)
    fsubs	f3, f3, f4
    fdivs	f1, f3, f2
    fmuls	f8, f5, f1
    stfs	f8, -0x8000(r17)
    stfs	f6, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    lfs	f7, 0x4c(r28)
    stfs	f8, -0x8000(r17)
    stfs	f7, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    bdnz    _80040360
_800403b4:
    lwz	r0, lbl_801A65A0
    addi	r4, r1, 0x1e4
    li	r3, 4
    stw	r0, 0x1e4(r1)
    bl      GXSetChanMatColor
    li	r3, 0x20
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lfs	f1, -0x7c68(r2)
    lis	r17, -0x33ff
    lwz	r0, lbl_801A65A8
    addi	r4, r1, 0x1e0
    stfs	f1, -0x8000(r17)
    lfs	f0, -0x7c48(r2)
    li	r3, 4
    stfs	f1, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f31, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stw	r0, 0x1e0(r1)
    bl      GXSetChanMatColor
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lfs	f5, -0x7c68(r2)
    lis	r4, 0x4330
    lwz	r0, lbl_801A6C44
    stfs	f5, -0x8000(r17)
    lwz	r3, lbl_801A6C60
    slwi	r0, r0, 4
    stfs	f5, -0x8000(r17)
    lfs	f4, -0x7c48(r2)
    lwz	r5, lbl_801A6C4C
    stfs	f4, -0x8000(r17)
    add	r5, r5, r0
    lwz	r0, lbl_801A65F4
    lwz	r5, 0xc(r5)
    stw	r3, 0x264(r1)
    cmpwi	r0, 0
    lfd	f2, -0x7c70(r2)
    stw	r5, 0x25c(r1)
    lfs	f3, -0x7c78(r2)
    stw	r4, 0x258(r1)
    stw	r4, 0x260(r1)
    lfd	f1, 0x258(r1)
    lfd	f0, 0x260(r1)
    fsubs	f1, f1, f2
    fsubs	f0, f0, f2
    fdivs	f0, f1, f0
    fmuls	f0, f3, f0
    stfs	f0, -0x8000(r17)
    stfs	f5, -0x8000(r17)
    stfs	f4, -0x8000(r17)
    beq     _80040514
    lfs	f1, -0x7c50(r2)
    addi	r4, r1, 0x1dc
    lfs	f0, -0x775c(r13)
    li	r3, 4
    lwz	r0, lbl_801A65B0
    fadds	f28, f1, f0
    stw	r0, 0x1dc(r1)
    bl      GXSetChanMatColor
    li	r3, 0x80
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lfs	f2, -0x7c68(r2)
    lfs	f0, -0x7c4c(r2)
    stfs	f2, -0x8000(r17)
    lfs	f1, -0x7c48(r2)
    fadds	f0, f0, f28
    stfs	f28, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stfs	f31, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stfs	f31, -0x8000(r17)
    stfs	f28, -0x8000(r17)
    stfs	f1, -0x8000(r17)
_80040514:
    lwz	r0, lbl_801A65F8
    cmpwi	r0, 0
    beq     _800405f8
    lfs	f2, -0x7c50(r2)
    addi	r4, r1, 0x1d8
    lfs	f0, -0x775c(r13)
    li	r3, 4
    lwz	r0, lbl_801A65B4
    fadds	f0, f2, f0
    lfs	f1, -0x7c4c(r2)
    stw	r0, 0x1d8(r1)
    fadds	f0, f1, f0
    fadds	f28, f2, f0
    bl      GXSetChanMatColor
    li	r3, 0x80
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lfs	f1, -0x7c68(r2)
    lis	r17, -0x33ff
    lfs	f0, -0x7c44(r2)
    addi	r4, r1, 0x1d4
    stfs	f1, -0x8000(r17)
    fadds	f2, f0, f28
    lwz	r0, lbl_801A65AC
    stfs	f28, -0x8000(r17)
    li	r3, 4
    lfs	f0, -0x7c48(r2)
    stfs	f0, -0x8000(r17)
    stfs	f1, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f31, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f31, -0x8000(r17)
    stfs	f28, -0x8000(r17)
    stw	r0, 0x1d4(r1)
    stfs	f0, -0x8000(r17)
    bl      GXSetChanMatColor
    li	r3, 6
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lfs	f0, -0x7c30(r2)
    lfs	f1, -0x7c68(r2)
    fadds	f2, f0, f28
    lfs	f0, -0x7c48(r2)
    stfs	f1, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f0, -0x8000(r17)
    stfs	f31, -0x8000(r17)
    stfs	f2, -0x8000(r17)
    stfs	f0, -0x8000(r17)
_800405f8:
    lwz	r0, lbl_801A65FC
    cmpwi	r0, 0
    beq     _80040690
    lfs	f1, -0x7c50(r2)
    addi	r4, r1, 0x1d0
    lfs	f0, -0x775c(r13)
    li	r3, 4
    lwz	r0, lbl_801A65B8
    fadds	f0, f1, f0
    lfs	f1, -0x7c4c(r2)
    lfs	f2, -0x7c44(r2)
    lfs	f3, -0x7c3c(r2)
    fadds	f0, f1, f0
    stw	r0, 0x1d0(r1)
    fadds	f0, f2, f0
    fadds	f28, f3, f0
    bl      GXSetChanMatColor
    li	r3, 0x80
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lfs	f2, -0x7c68(r2)
    lis	r3, -0x33ff
    lfs	f0, -0x7c44(r2)
    stfs	f2, -0x8000(r3)
    lfs	f1, -0x7c48(r2)
    fadds	f0, f0, f28
    stfs	f28, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f1, -0x8000(r3)
_80040690:
    lwz	r0, lbl_801A6600
    cmpwi	r0, 0
    beq     _8004072c
    lfs	f1, -0x7c50(r2)
    addi	r4, r1, 0x1cc
    lfs	f0, -0x775c(r13)
    li	r3, 4
    lwz	r0, lbl_801A65B8
    fadds	f0, f1, f0
    lfs	f1, -0x7c4c(r2)
    lfs	f3, -0x7c44(r2)
    lfs	f2, -0x7c38(r2)
    fadds	f0, f1, f0
    stw	r0, 0x1cc(r1)
    fadds	f0, f3, f0
    fadds	f0, f2, f0
    fadds	f28, f3, f0
    bl      GXSetChanMatColor
    li	r3, 0x80
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lfs	f2, -0x7c68(r2)
    lis	r3, -0x33ff
    lfs	f0, -0x7c44(r2)
    stfs	f2, -0x8000(r3)
    lfs	f1, -0x7c48(r2)
    fadds	f0, f0, f28
    stfs	f28, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f28, -0x8000(r3)
    stfs	f1, -0x8000(r3)
_8004072c:
    lfs	f29, -0x7c78(r2)
    mr	r19, r18
    lfd	f30, -0x7c70(r2)
    addi	r20, r1, 0x1a4
    lfs	f31, -0x7c48(r2)
    addi	r21, r1, 0x1a8
    addi	r22, r1, 0x1ac
    addi	r23, r1, 0x1b0
    addi	r25, r1, 0x1b8
    addi	r24, r1, 0x1b4
    addi	r27, r1, 0x1c0
    addi	r26, r1, 0x1bc
    addi	r29, r1, 0x1c4
    addi	r28, r1, 0x1c8
    li	r17, 0
    lis	r30, 0x4330
    lis	r31, -0x33ff
    b       _80041054
_80040774:
    lbz	r18, 0(r19)
    cmplwi	r18, 0xff
    bne     _8004078c
    mr	r3, r19
    bl      fn_8003EC44
    b       _8004104c
_8004078c:
    lwz	r3, lbl_801A6C48
    slwi	r0, r18, 4
    add	r3, r3, r0
    lwz	r0, 4(r3)
    cmpwi	r0, 1
    beq     _800407c0
    bge     _800407b4
    cmpwi	r0, 0
    bge     _80040d44
    b       _8004104c
_800407b4:
    cmpwi	r0, 3
    bge     _8004104c
    b       _80040edc
_800407c0:
    lwz	r0, 0xc(r3)
    addi	r4, r28, 0
    li	r3, 4
    stw	r0, 0x1c8(r1)
    bl      GXSetChanMatColor
    li	r3, 0x20
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r4, lbl_801A6C60
    addi	r0, r18, 1
    lwz	r5, 4(r19)
    mulli	r18, r0, 7
    stw	r4, 0x264(r1)
    stw	r5, 0x25c(r1)
    stw	r30, 0x258(r1)
    stw	r30, 0x260(r1)
    lfd	f1, 0x258(r1)
    lfd	f0, 0x260(r1)
    fsubs	f1, f1, f30
    stw	r18, 0x26c(r1)
    fsubs	f0, f0, f30
    stw	r4, 0x24c(r1)
    fdivs	f2, f1, f0
    stw	r30, 0x268(r1)
    stw	r30, 0x248(r1)
    lfd	f1, 0x268(r1)
    stw	r18, 0x244(r1)
    fmuls	f3, f29, f2
    lfd	f0, 0x248(r1)
    fsubs	f2, f1, f30
    stw	r30, 0x240(r1)
    fsubs	f1, f0, f30
    stfs	f3, -0x8000(r31)
    lfd	f0, 0x240(r1)
    stfs	f2, -0x8000(r31)
    fsubs	f0, f0, f30
    stfs	f31, -0x8000(r31)
    lwz	r0, 8(r19)
    stw	r0, 0x254(r1)
    stw	r30, 0x250(r1)
    lfd	f2, 0x250(r1)
    fsubs	f2, f2, f30
    fdivs	f1, f2, f1
    fmuls	f1, f29, f1
    stfs	f1, -0x8000(r31)
    stfs	f0, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r3, 0x28(r19)
    lwz	r0, 0x2c(r19)
    subf.	r0, r3, r0
    beq     _80040954
    add	r3, r0, r5
    stw	r4, 0x24c(r1)
    lwz	r0, lbl_801A65A8
    mr	r4, r29
    stw	r3, 0x244(r1)
    li	r3, 4
    stw	r30, 0x240(r1)
    stw	r30, 0x248(r1)
    lfd	f1, 0x240(r1)
    lfd	f0, 0x248(r1)
    fsubs	f1, f1, f30
    stw	r0, 0x1c4(r1)
    fsubs	f0, f0, f30
    fdivs	f0, f1, f0
    fmuls	f28, f29, f0
    bl      GXSetChanMatColor
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r3, 4(r19)
    lwz	r0, lbl_801A6C60
    stw	r3, 0x254(r1)
    stw	r0, 0x25c(r1)
    stw	r30, 0x250(r1)
    stw	r30, 0x258(r1)
    lfd	f1, 0x250(r1)
    lfd	f0, 0x258(r1)
    fsubs	f1, f1, f30
    stw	r18, 0x264(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x260(r1)
    fdivs	f2, f1, f0
    lfd	f1, 0x260(r1)
    stw	r18, 0x26c(r1)
    stw	r30, 0x268(r1)
    lfd	f0, 0x268(r1)
    fmuls	f2, f29, f2
    fsubs	f1, f1, f30
    fsubs	f0, f0, f30
    stfs	f2, -0x8000(r31)
    stfs	f1, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    stfs	f28, -0x8000(r31)
    stfs	f0, -0x8000(r31)
    stfs	f31, -0x8000(r31)
_80040954:
    lwz	r0, 0x10(r19)
    cmplwi	r0, 0
    beq     _8004104c
    lwz	r0, 0x14(r19)
    cmpwi	r0, 0
    bne     _80040b58
    lwz	r0, lbl_801A65A4
    addi	r4, r27, 0
    li	r3, 4
    stw	r0, 0x1c0(r1)
    bl      GXSetChanMatColor
    li	r3, 0x20
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r0, lbl_801A6C60
    mr	r3, r19
    lwz	r4, 0xc(r19)
    stw	r0, 0x24c(r1)
    lfs	f2, -0x775c(r13)
    stw	r4, 0x244(r1)
    stw	r30, 0x240(r1)
    stw	r30, 0x248(r1)
    lfd	f1, 0x240(r1)
    lfd	f0, 0x248(r1)
    fsubs	f1, f1, f30
    stw	r0, 0x25c(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x258(r1)
    fdivs	f1, f1, f0
    lfd	f0, 0x258(r1)
    fmuls	f1, f29, f1
    fsubs	f0, f0, f30
    stfs	f1, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 0x10(r19)
    stw	r0, 0x254(r1)
    stw	r30, 0x250(r1)
    lfd	f1, 0x250(r1)
    fsubs	f1, f1, f30
    fdivs	f0, f1, f0
    fmuls	f0, f29, f0
    stfs	f0, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    bl      fn_8003EC44
    lwz	r0, lbl_801A65AC
    addi	r4, r26, 0
    li	r3, 4
    stw	r0, 0x1bc(r1)
    bl      GXSetChanMatColor
    li	r3, 6
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lwz	r3, lbl_801A6C60
    lwz	r0, 0xc(r19)
    stw	r3, 0x26c(r1)
    lfs	f5, -0x775c(r13)
    stw	r0, 0x264(r1)
    stw	r30, 0x260(r1)
    stw	r30, 0x268(r1)
    lfd	f1, 0x260(r1)
    lfd	f0, 0x268(r1)
    fsubs	f1, f1, f30
    stw	r3, 0x234(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x230(r1)
    fdivs	f2, f1, f0
    lfd	f1, 0x230(r1)
    stw	r18, 0x22c(r1)
    stw	r30, 0x228(r1)
    lfd	f0, 0x228(r1)
    fmuls	f2, f29, f2
    stw	r3, 0x21c(r1)
    fsubs	f4, f1, f30
    stw	r30, 0x218(r1)
    fsubs	f3, f0, f30
    stfs	f2, -0x8000(r31)
    lfd	f0, 0x218(r1)
    stfs	f5, -0x8000(r31)
    fsubs	f2, f0, f30
    stfs	f31, -0x8000(r31)
    lwz	r0, 4(r19)
    stw	r3, 0x20c(r1)
    stw	r0, 0x23c(r1)
    stw	r30, 0x238(r1)
    lfd	f0, 0x238(r1)
    stw	r30, 0x208(r1)
    fsubs	f0, f0, f30
    lfd	f1, 0x208(r1)
    stw	r18, 0x204(r1)
    fdivs	f4, f0, f4
    stw	r30, 0x200(r1)
    lfd	f0, 0x200(r1)
    fmuls	f4, f29, f4
    fsubs	f1, f1, f30
    fsubs	f0, f0, f30
    stfs	f4, -0x8000(r31)
    stfs	f3, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 0x10(r19)
    stw	r0, 0x224(r1)
    stw	r30, 0x220(r1)
    lfd	f3, 0x220(r1)
    fsubs	f3, f3, f30
    fdivs	f2, f3, f2
    fmuls	f2, f29, f2
    stfs	f2, -0x8000(r31)
    stfs	f5, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 8(r19)
    stw	r0, 0x214(r1)
    stw	r30, 0x210(r1)
    lfd	f2, 0x210(r1)
    fsubs	f2, f2, f30
    fdivs	f1, f2, f1
    fmuls	f1, f29, f1
    stfs	f1, -0x8000(r31)
    stfs	f0, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    b       _8004104c
_80040b58:
    lwz	r0, lbl_801A65A4
    addi	r4, r25, 0
    li	r3, 4
    stw	r0, 0x1b8(r1)
    bl      GXSetChanMatColor
    li	r3, 0x20
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r0, lbl_801A6C60
    mr	r3, r19
    lwz	r4, 0x1c(r19)
    stw	r0, 0x20c(r1)
    lfs	f2, -0x775c(r13)
    stw	r4, 0x204(r1)
    stw	r30, 0x200(r1)
    stw	r30, 0x208(r1)
    lfd	f1, 0x200(r1)
    lfd	f0, 0x208(r1)
    fsubs	f1, f1, f30
    stw	r0, 0x21c(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x218(r1)
    fdivs	f1, f1, f0
    lfd	f0, 0x218(r1)
    fmuls	f1, f29, f1
    fsubs	f0, f0, f30
    stfs	f1, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 0x10(r19)
    stw	r0, 0x214(r1)
    stw	r30, 0x210(r1)
    lfd	f1, 0x210(r1)
    fsubs	f1, f1, f30
    fdivs	f0, f1, f0
    fmuls	f0, f29, f0
    stfs	f0, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    bl      fn_8003EC44
    lwz	r0, lbl_801A65AC
    addi	r4, r24, 0
    li	r3, 4
    stw	r0, 0x1b4(r1)
    bl      GXSetChanMatColor
    li	r3, 6
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 4
    bl      GXBegin
    lwz	r3, lbl_801A6C60
    lwz	r0, 0x1c(r19)
    stw	r3, 0x22c(r1)
    lfs	f5, -0x775c(r13)
    stw	r0, 0x224(r1)
    stw	r30, 0x220(r1)
    stw	r30, 0x228(r1)
    lfd	f1, 0x220(r1)
    lfd	f0, 0x228(r1)
    fsubs	f1, f1, f30
    stw	r3, 0x23c(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x238(r1)
    fdivs	f2, f1, f0
    lfd	f1, 0x238(r1)
    stw	r18, 0x244(r1)
    stw	r30, 0x240(r1)
    lfd	f0, 0x240(r1)
    fmuls	f2, f29, f2
    stw	r3, 0x254(r1)
    fsubs	f4, f1, f30
    stw	r30, 0x250(r1)
    fsubs	f3, f0, f30
    stfs	f2, -0x8000(r31)
    lfd	f0, 0x250(r1)
    stfs	f5, -0x8000(r31)
    fsubs	f2, f0, f30
    stfs	f31, -0x8000(r31)
    lwz	r0, 0x18(r19)
    stw	r3, 0x264(r1)
    stw	r0, 0x234(r1)
    stw	r30, 0x230(r1)
    lfd	f0, 0x230(r1)
    stw	r30, 0x260(r1)
    fsubs	f0, f0, f30
    lfd	f1, 0x260(r1)
    stw	r18, 0x26c(r1)
    fdivs	f4, f0, f4
    stw	r30, 0x268(r1)
    lfd	f0, 0x268(r1)
    fmuls	f4, f29, f4
    fsubs	f1, f1, f30
    fsubs	f0, f0, f30
    stfs	f4, -0x8000(r31)
    stfs	f3, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 0x10(r19)
    stw	r0, 0x24c(r1)
    stw	r30, 0x248(r1)
    lfd	f3, 0x248(r1)
    fsubs	f3, f3, f30
    fdivs	f2, f3, f2
    fmuls	f2, f29, f2
    stfs	f2, -0x8000(r31)
    stfs	f5, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 8(r19)
    stw	r0, 0x25c(r1)
    stw	r30, 0x258(r1)
    lfd	f2, 0x258(r1)
    fsubs	f2, f2, f30
    fdivs	f1, f2, f1
    fmuls	f1, f29, f1
    stfs	f1, -0x8000(r31)
    stfs	f0, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    b       _8004104c
_80040d44:
    lwz	r0, 0xc(r3)
    addi	r4, r23, 0
    li	r3, 4
    stw	r0, 0x1b0(r1)
    bl      GXSetChanMatColor
    li	r3, 0x20
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r4, lbl_801A6C60
    addi	r0, r18, 1
    lwz	r5, 4(r19)
    mulli	r18, r0, 7
    stw	r4, 0x20c(r1)
    stw	r5, 0x204(r1)
    stw	r30, 0x200(r1)
    stw	r30, 0x208(r1)
    lfd	f1, 0x200(r1)
    lfd	f0, 0x208(r1)
    fsubs	f1, f1, f30
    stw	r18, 0x214(r1)
    fsubs	f0, f0, f30
    stw	r4, 0x224(r1)
    fdivs	f2, f1, f0
    stw	r30, 0x210(r1)
    stw	r30, 0x220(r1)
    lfd	f1, 0x210(r1)
    stw	r18, 0x22c(r1)
    fmuls	f3, f29, f2
    lfd	f0, 0x220(r1)
    fsubs	f2, f1, f30
    stw	r30, 0x228(r1)
    fsubs	f1, f0, f30
    stfs	f3, -0x8000(r31)
    lfd	f0, 0x228(r1)
    stfs	f2, -0x8000(r31)
    fsubs	f0, f0, f30
    stfs	f31, -0x8000(r31)
    lwz	r0, 8(r19)
    stw	r0, 0x21c(r1)
    stw	r30, 0x218(r1)
    lfd	f2, 0x218(r1)
    fsubs	f2, f2, f30
    fdivs	f1, f2, f1
    fmuls	f1, f29, f1
    stfs	f1, -0x8000(r31)
    stfs	f0, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r3, 0x28(r19)
    lwz	r0, 0x2c(r19)
    subf.	r0, r3, r0
    beq     _8004104c
    add	r3, r0, r5
    stw	r4, 0x20c(r1)
    lwz	r0, lbl_801A65A8
    mr	r4, r22
    stw	r3, 0x204(r1)
    li	r3, 4
    stw	r30, 0x200(r1)
    stw	r30, 0x208(r1)
    lfd	f1, 0x200(r1)
    lfd	f0, 0x208(r1)
    fsubs	f1, f1, f30
    stw	r0, 0x1ac(r1)
    fsubs	f0, f0, f30
    fdivs	f0, f1, f0
    fmuls	f28, f29, f0
    bl      GXSetChanMatColor
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r3, 4(r19)
    lwz	r0, lbl_801A6C60
    stw	r3, 0x214(r1)
    stw	r0, 0x21c(r1)
    stw	r30, 0x210(r1)
    stw	r30, 0x218(r1)
    lfd	f1, 0x210(r1)
    lfd	f0, 0x218(r1)
    fsubs	f1, f1, f30
    stw	r18, 0x224(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x220(r1)
    fdivs	f2, f1, f0
    lfd	f1, 0x220(r1)
    stw	r18, 0x22c(r1)
    stw	r30, 0x228(r1)
    lfd	f0, 0x228(r1)
    fmuls	f2, f29, f2
    fsubs	f1, f1, f30
    fsubs	f0, f0, f30
    stfs	f2, -0x8000(r31)
    stfs	f1, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    stfs	f28, -0x8000(r31)
    stfs	f0, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    b       _8004104c
_80040edc:
    lwz	r0, 0x14(r19)
    cmpwi	r0, 0
    bne     _80040f9c
    lwz	r0, lbl_801A65A4
    addi	r4, r21, 0
    li	r3, 4
    stw	r0, 0x1a8(r1)
    bl      GXSetChanMatColor
    li	r3, 0x20
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r0, lbl_801A6C60
    mr	r3, r19
    lwz	r4, 0xc(r19)
    stw	r0, 0x20c(r1)
    lfs	f2, -0x775c(r13)
    stw	r4, 0x204(r1)
    stw	r30, 0x200(r1)
    stw	r30, 0x208(r1)
    lfd	f1, 0x200(r1)
    lfd	f0, 0x208(r1)
    fsubs	f1, f1, f30
    stw	r0, 0x21c(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x218(r1)
    fdivs	f1, f1, f0
    lfd	f0, 0x218(r1)
    fmuls	f1, f29, f1
    fsubs	f0, f0, f30
    stfs	f1, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 0x10(r19)
    stw	r0, 0x214(r1)
    stw	r30, 0x210(r1)
    lfd	f1, 0x210(r1)
    fsubs	f1, f1, f30
    fdivs	f0, f1, f0
    fmuls	f0, f29, f0
    stfs	f0, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    bl      fn_8003EC44
    b       _8004104c
_80040f9c:
    lwz	r0, lbl_801A65A4
    addi	r4, r20, 0
    li	r3, 4
    stw	r0, 0x1a4(r1)
    bl      GXSetChanMatColor
    li	r3, 0x20
    li	r4, 0
    bl      GXSetLineWidth
    li	r3, 0xa8
    li	r4, 0
    li	r5, 2
    bl      GXBegin
    lwz	r0, lbl_801A6C60
    mr	r3, r19
    lwz	r4, 0x1c(r19)
    stw	r0, 0x20c(r1)
    lfs	f2, -0x775c(r13)
    stw	r4, 0x204(r1)
    stw	r30, 0x200(r1)
    stw	r30, 0x208(r1)
    lfd	f1, 0x200(r1)
    lfd	f0, 0x208(r1)
    fsubs	f1, f1, f30
    stw	r0, 0x21c(r1)
    fsubs	f0, f0, f30
    stw	r30, 0x218(r1)
    fdivs	f1, f1, f0
    lfd	f0, 0x218(r1)
    fmuls	f1, f29, f1
    fsubs	f0, f0, f30
    stfs	f1, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    lwz	r0, 0x10(r19)
    stw	r0, 0x214(r1)
    stw	r30, 0x210(r1)
    lfd	f1, 0x210(r1)
    fsubs	f1, f1, f30
    fdivs	f0, f1, f0
    fmuls	f0, f29, f0
    stfs	f0, -0x8000(r31)
    stfs	f2, -0x8000(r31)
    stfs	f31, -0x8000(r31)
    bl      fn_8003EC44
_8004104c:
    addi	r19, r19, 0xb0
    addi	r17, r17, 1
_80041054:
    lwz	r0, lbl_801A6C44
    lwz	r4, lbl_801A6C4C
    slwi	r3, r0, 4
    addi	r0, r3, 4
    lwzx	r0, r4, r0
    cmplw	r17, r0
    blt     _80040774
    lwz	r0, lbl_801A6C6C
    cmpwi	r0, 0
    beq     _80041080
    bl      fn_8003F834
_80041080:
    lmw	r17, 0x274(r1)
    lwz	r0, 0x2d4(r1)
    lfd	f31, 0x2c8(r1)
    lfd	f30, 0x2c0(r1)
    lfd	f29, 0x2b8(r1)
    lfd	f28, 0x2b0(r1)
    addi	r1, r1, 0x2d0
    mtlr	r0
    blr	
}

#pragma pop
