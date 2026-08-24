typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void GXBegin(register s32 prim, register s32 vtxFmt, register u16 nverts);
extern void GXSetChanMatColor(register void* p1, register int a, register int b);

#pragma push
#pragma force_active on

asm void fn_8003EC44(register void* a)
{
    nofralloc
    mflr r0
    lis r5, 0x4330
    stw r0, 4(r1)
    lis r4, -0x8000
    stwu r1, -0xe0(r1)
    stfd f31, 0xd8(r1)
    stfd f30, 0xd0(r1)
    stfd f29, 0xc8(r1)
    stfd f28, 0xc0(r1)
    stfd f27, 0xb8(r1)
    stw r31, 0xb4(r1)
    stw r30, 0xb0(r1)
    mr r30, r3
    stw r29, 0xac(r1)
    lwz r6, -0x7760(r13)
    lwz r0, 0xc(r3)
    stw r6, 0x8c(r1)
    lwz r7, 0x10(r3)
    lis r3, -0x7777
    stw r0, 0x94(r1)
    addi r3, r3, -0x7777
    subf r31, r0, r7
    stw r5, 0x90(r1)
    lfd f9, -0x7c70(r2)
    stw r5, 0x88(r1)
    lfd f1, 0x90(r1)
    lfd f0, 0x88(r1)
    fsubs f1, f1, f9
    lwz r0, 0xfc(r4)
    fsubs f0, f0, f9
    stw r7, 0x84(r1)
    mulhwu r0, r3, r0
    fdivs f0, f1, f0
    stw r6, 0x7c(r1)
    lfs f5, -0x7c78(r2)
    stw r5, 0x80(r1)
    srwi r0, r0, 5
    stw r31, 0xa4(r1)
    fmuls f10, f5, f0
    lfd f1, 0x80(r1)
    stw r5, 0x78(r1)
    fsubs f4, f1, f9
    lfs f2, -0x7750(r13)
    stw r0, 0x9c(r1)
    fmr f28, f10
    lfd f0, 0x78(r1)
    fsubs f3, f0, f9
    stw r5, 0xa0(r1)
    fsubs f1, f2, f10
    lfs f0, -0x7c5c(r2)
    stw r5, 0x98(r1)
    fdivs f3, f4, f3
    lfd f8, 0xa0(r1)
    lfd f7, 0x98(r1)
    stfs f1, 0x1c(r1)
    lfs f6, -0x7c50(r2)
    lwz r0, 0x1c(r1)
    fsubs f8, f8, f9
    fsubs f7, f7, f9
    lfs f4, -0x775c(r13)
    clrlwi r0, r0, 1
    stw r0, 0x1c(r1)
    fdivs f30, f8, f7
    lfs f1, 0x1c(r1)
    fcmpo cr0, f1, f0
    fadds f29, f6, f4
    fmuls f31, f5, f3
    bge _8003ed58
    fmr f28, f2
_8003ed58:
    lwz r0, -0x7dcc(r13)
    stfs f31, -0x7750(r13)
    cmpwi r0, 0
    beq _8003f4ac
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x40(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x44(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003ee20
    lwz r0, -0x7e00(r13)
    addi r4, r1, 0x5c
    li r3, 4
    stw r0, 0x5c(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003ee20:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x48(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x4c(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003eed8
    lwz r0, -0x7dfc(r13)
    addi r4, r1, 0x58
    li r3, 4
    stw r0, 0x58(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003eed8:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x50(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x54(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003ef90
    lwz r0, -0x7df8(r13)
    addi r4, r1, 0x54
    li r3, 4
    stw r0, 0x54(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003ef90:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x58(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x5c(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003f048
    lwz r0, -0x7df4(r13)
    addi r4, r1, 0x50
    li r3, 4
    stw r0, 0x50(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003f048:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x60(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x64(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003f100
    lwz r0, -0x7df0(r13)
    addi r4, r1, 0x4c
    li r3, 4
    stw r0, 0x4c(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003f100:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x68(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x6c(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003f1b8
    lwz r0, -0x7dec(r13)
    addi r4, r1, 0x48
    li r3, 4
    stw r0, 0x48(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003f1b8:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x70(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x74(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003f270
    lwz r0, -0x7de8(r13)
    addi r4, r1, 0x44
    li r3, 4
    stw r0, 0x44(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003f270:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x78(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x7c(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003f328
    lwz r0, -0x7de4(r13)
    addi r4, r1, 0x40
    li r3, 4
    stw r0, 0x40(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003f328:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    lwz r4, 0x80(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x84(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003f3e0
    lwz r0, -0x7de0(r13)
    addi r4, r1, 0x3c
    li r3, 4
    stw r0, 0x3c(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    fadds f29, f29, f27
    stfs f0, -0x8000(r3)
_8003f3e0:
    lwz r0, 0x88(r30)
    lis r3, 0x4330
    srwi r0, r0, 1
    stw r0, 0x88(r30)
    lwz r0, 0x8c(r30)
    srwi r0, r0, 1
    stw r0, 0x8c(r30)
    lwz r0, -0x7758(r13)
    lwz r4, 0x88(r30)
    stw r0, 0x84(r1)
    lwz r0, 0x8c(r30)
    stw r3, 0x80(r1)
    subf r0, r4, r0
    lfd f3, -0x7c70(r2)
    stw r0, 0x7c(r1)
    lfd f0, 0x80(r1)
    stw r3, 0x78(r1)
    fsubs f1, f0, f3
    lfs f4, -0x7c4c(r2)
    lfd f2, 0x78(r1)
    lfs f0, -0x7c5c(r2)
    fsubs f2, f2, f3
    fmuls f1, f1, f30
    fdivs f1, f2, f1
    fmuls f27, f4, f1
    fcmpo cr0, f27, f0
    ble _8003f4ac
    lwz r0, -0x7ddc(r13)
    addi r4, r1, 0x38
    li r3, 4
    stw r0, 0x38(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f29, f27
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f29, -0x8000(r3)
    stfs f0, -0x8000(r3)
_8003f4ac:
    lwz r0, -0x7dc8(r13)
    cmpwi r0, 0
    beq _8003f628
    lwz r4, 0x30(r30)
    lis r0, 0x4330
    lwz r3, 0x34(r30)
    stw r31, 0x84(r1)
    subf r3, r4, r3
    lfd f3, -0x7c70(r2)
    stw r3, 0x7c(r1)
    lfs f1, -0x7c40(r2)
    stw r0, 0x78(r1)
    lfs f6, -0x7c50(r2)
    stw r0, 0x80(r1)
    lfd f2, 0x78(r1)
    lfd f0, 0x80(r1)
    fsubs f2, f2, f3
    lfs f4, -0x775c(r13)
    fsubs f0, f0, f3
    lfs f3, -0x7c44(r2)
    fadds f4, f6, f4
    fdivs f2, f2, f0
    lfs f5, -0x7c4c(r2)
    lfs f0, -0x7c5c(r2)
    lwz r3, 0x20(r30)
    lwz r0, 0x24(r30)
    fmuls f1, f2, f1
    subf r29, r3, r0
    fadds f2, f5, f4
    fmuls f29, f3, f1
    fadds f27, f6, f2
    fcmpo cr0, f29, f0
    ble _8003f590
    lwz r0, -0x7e04(r13)
    addi r4, r1, 0x34
    li r3, 4
    stw r0, 0x34(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f27, f29
    stfs f27, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f27, -0x8000(r3)
    stfs f0, -0x8000(r3)
_8003f590:
    lwz r0, -0x7e18(r13)
    addi r4, r1, 0x30
    li r3, 4
    stw r0, 0x30(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    stw r29, 0x7c(r1)
    lis r0, 0x4330
    lfs f4, -0x7c44(r2)
    lis r3, -0x33ff
    stw r0, 0x78(r1)
    lfd f3, -0x7c70(r2)
    fadds f5, f4, f27
    stw r31, 0x84(r1)
    lfd f0, 0x78(r1)
    stw r0, 0x80(r1)
    fsubs f2, f0, f3
    lfs f0, -0x7c48(r2)
    lfd f1, 0x80(r1)
    stfs f28, -0x8000(r3)
    fmuls f2, f4, f2
    fsubs f1, f1, f3
    fdivs f1, f2, f1
    fsubs f1, f5, f1
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f5, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f5, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
_8003f628:
    lwz r0, -0x7dc4(r13)
    lwz r4, 0xa8(r30)
    lwz r3, 0xac(r30)
    cmpwi r0, 0
    subf r31, r4, r3
    beq _8003f728
    lfs f1, -0x7c50(r2)
    lfs f0, -0x775c(r13)
    lfs f2, -0x7c4c(r2)
    fadds f0, f1, f0
    lfs f4, -0x7c44(r2)
    lwz r4, 0x90(r30)
    lwz r0, 0x94(r30)
    fadds f0, f2, f0
    lwz r3, 0x98(r30)
    subf r4, r4, r0
    lwz r0, 0x9c(r30)
    fadds f0, f4, f0
    subf r0, r3, r0
    lfs f1, -0x7c3c(r2)
    add r0, r0, r4
    cmplw r31, r0
    fadds f27, f1, f0
    blt _8003f728
    subf r3, r0, r31
    stw r31, 0x84(r1)
    lis r0, 0x4330
    lfd f3, -0x7c70(r2)
    stw r3, 0x7c(r1)
    lfs f0, -0x7c5c(r2)
    stw r0, 0x78(r1)
    lfd f1, 0x78(r1)
    stw r0, 0x80(r1)
    fsubs f2, f1, f3
    lfd f1, 0x80(r1)
    fmuls f2, f4, f2
    fsubs f1, f1, f3
    fdivs f29, f2, f1
    fcmpo cr0, f29, f0
    ble _8003f728
    lwz r0, -0x7dd8(r13)
    addi r4, r1, 0x2c
    li r3, 4
    stw r0, 0x2c(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f27, f29
    stfs f27, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f27, -0x8000(r3)
    stfs f0, -0x8000(r3)
_8003f728:
    lwz r0, -0x7dc0(r13)
    cmpwi r0, 0
    beq _8003f804
    lwz r4, 0xa0(r30)
    lis r0, 0x4330
    lwz r3, 0xa4(r30)
    stw r31, 0x84(r1)
    subf r3, r4, r3
    lfd f3, -0x7c70(r2)
    stw r3, 0x7c(r1)
    lfs f7, -0x7c44(r2)
    stw r0, 0x78(r1)
    lfs f4, -0x7c50(r2)
    lfd f0, 0x78(r1)
    stw r0, 0x80(r1)
    fsubs f1, f0, f3
    lfs f2, -0x775c(r13)
    lfd f0, 0x80(r1)
    fadds f4, f4, f2
    lfs f5, -0x7c4c(r2)
    fmuls f2, f7, f1
    lfs f6, -0x7c38(r2)
    fsubs f1, f0, f3
    fadds f3, f5, f4
    lfs f0, -0x7c5c(r2)
    fdivs f29, f2, f1
    fadds f1, f7, f3
    fcmpo cr0, f29, f0
    fadds f0, f6, f1
    fadds f27, f7, f0
    ble _8003f804
    lwz r0, -0x7dd4(r13)
    addi r4, r1, 0x28
    li r3, 4
    stw r0, 0x28(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lis r3, -0x33ff
    lfs f0, -0x7c48(r2)
    stfs f28, -0x8000(r3)
    fadds f1, f27, f29
    stfs f27, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f28, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f27, -0x8000(r3)
    stfs f0, -0x8000(r3)
_8003f804:
    lwz r0, 0xe4(r1)
    lfd f31, 0xd8(r1)
    lfd f30, 0xd0(r1)
    lfd f29, 0xc8(r1)
    lfd f28, 0xc0(r1)
    lfd f27, 0xb8(r1)
    lwz r31, 0xb4(r1)
    lwz r30, 0xb0(r1)
    lwz r29, 0xac(r1)
    addi r1, r1, 0xe0
    mtlr r0
    blr
}

asm void fn_8003F834(register void* a)
{
    nofralloc
    mflr r0
    lis r3, -0x3333
    stw r0, 4(r1)
    addi r0, r3, -0x3333
    stwu r1, -0x78(r1)
    stfd f31, 0x70(r1)
    stfd f30, 0x68(r1)
    stw r31, 0x64(r1)
    lwz r4, -0x7758(r13)
    lfs f2, -0x7c50(r2)
    mulhwu r3, r0, r4
    lfs f0, -0x775c(r13)
    stw r4, 0x54(r1)
    lfd f3, -0x7c70(r2)
    fadds f31, f2, f0
    lis r0, 0x4330
    lfs f1, -0x7c5c(r2)
    stw r0, 0x50(r1)
    srwi r31, r3, 3
    lfs f4, -0x7c4c(r2)
    stw r31, 0x5c(r1)
    lfd f0, 0x50(r1)
    stw r0, 0x58(r1)
    fsubs f0, f0, f3
    lfd f2, 0x58(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003f91c
    lwz r0, -0x7e00(r13)
    addi r4, r1, 0x30
    li r3, 4
    stw r0, 0x30(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003f91c:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003f9d0
    lwz r0, -0x7dfc(r13)
    addi r4, r1, 0x2c
    li r3, 4
    stw r0, 0x2c(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003f9d0:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003fa84
    lwz r0, -0x7df8(r13)
    addi r4, r1, 0x28
    li r3, 4
    stw r0, 0x28(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003fa84:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003fb38
    lwz r0, -0x7df4(r13)
    addi r4, r1, 0x24
    li r3, 4
    stw r0, 0x24(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003fb38:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003fbec
    lwz r0, -0x7df0(r13)
    addi r4, r1, 0x20
    li r3, 4
    stw r0, 0x20(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003fbec:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003fca0
    lwz r0, -0x7dec(r13)
    addi r4, r1, 0x1c
    li r3, 4
    stw r0, 0x1c(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003fca0:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003fd54
    lwz r0, -0x7de8(r13)
    addi r4, r1, 0x18
    li r3, 4
    stw r0, 0x18(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003fd54:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003fe08
    lwz r0, -0x7de4(r13)
    addi r4, r1, 0x14
    li r3, 4
    stw r0, 0x14(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003fe08:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003febc
    lwz r0, -0x7de0(r13)
    addi r4, r1, 0x10
    li r3, 4
    stw r0, 0x10(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    fadds f31, f31, f30
    stfs f1, -0x8000(r3)
_8003febc:
    lwz r0, -0x7758(r13)
    lis r3, 0x4330
    stw r31, 0x54(r1)
    lfd f3, -0x7c70(r2)
    stw r0, 0x5c(r1)
    lfs f1, -0x7c5c(r2)
    stw r3, 0x58(r1)
    lfs f4, -0x7c4c(r2)
    lfd f0, 0x58(r1)
    stw r3, 0x50(r1)
    fsubs f0, f0, f3
    lfd f2, 0x50(r1)
    fsubs f2, f2, f3
    fmuls f0, f0, f1
    fdivs f0, f2, f0
    fmuls f30, f4, f0
    fcmpo cr0, f30, f1
    ble _8003ff6c
    lwz r0, -0x7ddc(r13)
    addi r4, r1, 0xc
    li r3, 4
    stw r0, 0xc(r1)
    bl GXSetChanMatColor
    li r3, 0x80
    li r4, 0
    li r5, 4
    bl GXBegin
    lfs f2, -0x7c34(r2)
    lis r3, -0x33ff
    lfs f1, -0x7c48(r2)
    fadds f3, f31, f30
    stfs f2, -0x8000(r3)
    lfs f0, -0x7c78(r2)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f2, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f3, -0x8000(r3)
    stfs f1, -0x8000(r3)
    stfs f0, -0x8000(r3)
    stfs f31, -0x8000(r3)
    stfs f1, -0x8000(r3)
_8003ff6c:
    lwz r0, 0x7c(r1)
    lfd f31, 0x70(r1)
    lfd f30, 0x68(r1)
    lwz r31, 0x64(r1)
    addi r1, r1, 0x78
    mtlr r0
    blr
}
