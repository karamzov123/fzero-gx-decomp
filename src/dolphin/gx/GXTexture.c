typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef volatile struct GXData {
    u8 pad[0x500];
} GXData;

extern GXData *const gx;
extern unsigned char lbl_8012B368[80];

void __GXFlushTextureState(void);
void fn_800361F0(register void* dst, register void* src, register int a, register int b);
void fn_800365B4(register void* p, register int a);
void __GXInitTexObj(register void* p);

#pragma push
#pragma force_active on

asm void fn_80036070(register void* p)
{
    nofralloc
    lwz	r0, 0xc(r3)
    rlwinm	r0, r0, 5, 6, 0x1a
    stw	r0, 0(r4)
    lwz	r0, 8(r3)
    clrlwi	r4, r0, 0x16
    addi	r0, r4, 1
    sth	r0, 0(r5)
    lwz	r0, 8(r3)
    rlwinm	r4, r0, 0x16, 0x16, 0x1f
    addi	r0, r4, 1
    sth	r0, 0(r6)
    lwz	r0, 0x14(r3)
    stw	r0, 0(r7)
    lwz	r0, 0(r3)
    clrlwi	r0, r0, 0x1e
    stw	r0, 0(r8)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x1e, 0x1e, 0x1f
    stw	r0, 0(r9)
    lbz	r0, 0x1f(r3)
    clrlwi	r3, r0, 0x1f
    addi	r0, r3, -1
    cntlzw	r0, r0
    rlwinm	r0, r0, 0x1b, 0x18, 0x1f
    stb	r0, 0(r10)
    blr	
}

asm void fn_800360D8(void)
{
    nofralloc
    lwz	r0, 0xc(r3)
    rlwinm	r3, r0, 5, 6, 0x1a
    blr	
}

asm void GXXFormSetupA(register void* p)
{
    nofralloc
    lwz	r0, 8(r3)
    clrlwi	r3, r0, 0x16
    addi	r3, r3, 1
    blr	
}

asm void GXXFormSetupB(register void* p)
{
    nofralloc
    lwz	r0, 8(r3)
    rlwinm	r3, r0, 0x16, 0x16, 0x1f
    addi	r3, r3, 1
    blr	
}

asm void GXGetTexObjMipmap(void)
{
    nofralloc
    lwz	r3, 0x14(r3)
    blr	
}

asm void fn_8003610C(register void* p, register int a, register int b)
{
    nofralloc
    stwu	r1, -0x50(r1)
    lis	r12, 0x4330
    stw	r31, 0x4c(r1)
    addi	r31, r13, -0x7e48
    lwz	r11, 0x58(r1)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    lbzx	r0, r31, r0
    stw	r0, 0(r4)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x1c, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 4(r3)
    lfd	f2, -0x7d80(r2)
    clrlwi	r0, r0, 0x18
    lfs	f1, -0x7d60(r2)
    stw	r0, 0x44(r1)
    stw	r12, 0x40(r1)
    lfd	f0, 0x40(r1)
    fsubs	f0, f0, f2
    fmuls	f0, f0, f1
    stfs	f0, 0(r6)
    lwz	r0, 4(r3)
    rlwinm	r0, r0, 0x18, 0x18, 0x1f
    stw	r0, 0x3c(r1)
    stw	r12, 0x38(r1)
    lfd	f0, 0x38(r1)
    fsubs	f0, f0, f2
    fmuls	f0, f0, f1
    stfs	f0, 0(r7)
    lwz	r0, 0(r3)
    lfd	f2, -0x7d58(r2)
    rlwinm	r0, r0, 0x17, 0x18, 0x1f
    lfs	f0, -0x7d5c(r2)
    extsh	r0, r0
    extsb	r0, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0x34(r1)
    stw	r12, 0x30(r1)
    lfd	f1, 0x30(r1)
    fsubs	f1, f1, f2
    fmuls	f0, f1, f0
    stfs	f0, 0(r8)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0xb, 0x1f, 0x1f
    stb	r0, 0(r9)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x18, 0x1f, 0x1f
    cntlzw	r0, r0
    rlwinm	r0, r0, 0x1b, 0x18, 0x1f
    stb	r0, 0(r10)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0xd, 0x1e, 0x1f
    stw	r0, 0(r11)
    lwz	r31, 0x4c(r1)
    addi	r1, r1, 0x50
    blr	
}

asm void fn_800361F0(register void* dst, register void* src, register int a, register int b)
{
    nofralloc
    mflr	r0
    addi	r7, r13, -0x7e78
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    lis	r31, -0x33ff
    stw	r30, 0x20(r1)
    li	r30, 0x61
    stw	r29, 0x1c(r1)
    addi	r29, r5, 0
    addi	r5, r13, -0x7e68
    stw	r28, 0x18(r1)
    mr	r28, r3
    lwz	r6, 0(r3)
    addi	r3, r13, -0x7e88
    lbzx	r0, r3, r29
    addi	r3, r13, -0x7e80
    slwi	r0, r0, 0x18
    rlwimi	r0, r6, 0, 8, 0x1f
    stw	r0, 0(r28)
    addi	r6, r13, -0x7e70
    lbzx	r0, r3, r29
    addi	r3, r13, -0x7e60
    lwz	r8, 4(r28)
    slwi	r0, r0, 0x18
    rlwimi	r0, r8, 0, 8, 0x1f
    stw	r0, 4(r28)
    lbzx	r0, r7, r29
    lwz	r8, 8(r28)
    slwi	r0, r0, 0x18
    rlwimi	r0, r8, 0, 8, 0x1f
    stw	r0, 8(r28)
    lbzx	r0, r6, r29
    lwz	r7, 0(r4)
    slwi	r0, r0, 0x18
    rlwimi	r0, r7, 0, 8, 0x1f
    stw	r0, 0(r4)
    lbzx	r0, r5, r29
    lwz	r6, 4(r4)
    slwi	r0, r0, 0x18
    rlwimi	r0, r6, 0, 8, 0x1f
    stw	r0, 4(r4)
    lbzx	r0, r3, r29
    lwz	r5, 0xc(r28)
    slwi	r0, r0, 0x18
    rlwimi	r0, r5, 0, 8, 0x1f
    stw	r0, 0xc(r28)
    stb	r30, -0x8000(r31)
    lwz	r0, 0(r28)
    stw	r0, -0x8000(r31)
    stb	r30, -0x8000(r31)
    lwz	r0, 4(r28)
    stw	r0, -0x8000(r31)
    stb	r30, -0x8000(r31)
    lwz	r0, 8(r28)
    stw	r0, -0x8000(r31)
    stb	r30, -0x8000(r31)
    lwz	r0, 0(r4)
    stw	r0, -0x8000(r31)
    stb	r30, -0x8000(r31)
    lwz	r0, 4(r4)
    stw	r0, -0x8000(r31)
    stb	r30, -0x8000(r31)
    lwz	r0, 0xc(r28)
    stw	r0, -0x8000(r31)
    lbz	r0, 0x1f(r28)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bne     _80036338
    lwz	r4, -0x7de8(r2)
    lwz	r3, 0x18(r28)
    lwz	r12, 0x414(r4)
    mtlr	r12
    blrl	
    addi	r4, r13, -0x7e58
    lwz	r5, 4(r3)
    lbzx	r0, r4, r29
    slwi	r0, r0, 0x18
    rlwimi	r0, r5, 0, 8, 0x1f
    stw	r0, 4(r3)
    stb	r30, -0x8000(r31)
    lwz	r0, 4(r3)
    stw	r0, -0x8000(r31)
_80036338:
    lwz	r5, -0x7de8(r2)
    slwi	r4, r29, 2
    lwz	r3, 8(r28)
    li	r0, 0
    add	r4, r5, r4
    stw	r3, 0x45c(r4)
    lwz	r3, 0(r28)
    stw	r3, 0x47c(r4)
    lwz	r3, 0x4f4(r5)
    ori	r3, r3, 1
    stw	r3, 0x4f4(r5)
    sth	r0, 2(r5)
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    lwz	r28, 0x18(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void fn_80036388(register void* p)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, 0
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    lwz	r5, -0x7de8(r2)
    lwz	r12, 0x410(r5)
    mtlr	r12
    blrl	
    addi	r4, r3, 0
    addi	r3, r30, 0
    addi	r5, r31, 0
    bl      fn_800361F0
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void* GXInitTexCacheRegion(register void* obj, register unsigned long size, register void* buf, register int b)
{
    nofralloc
    cmpwi	r6, 1
    beq     _80036408
    bge     _800363f4
    cmpwi	r6, 0
    bge     _80036400
    b       _80036414
_800363f4:
    cmpwi	r6, 3
    bge     _80036414
    b       _80036410
_80036400:
    li	r10, 3
    b       _80036414
_80036408:
    li	r10, 4
    b       _80036414
_80036410:
    li	r10, 5
_80036414:
    li	r0, 0
    stw	r0, 0(r3)
    srwi	r6, r5, 5
    slwi	r5, r10, 0xf
    lwz	r9, 0(r3)
    slwi	r0, r10, 0x12
    cmpwi	r8, 2
    rlwinm	r9, r9, 0, 0, 0x10
    or	r6, r9, r6
    stw	r6, 0(r3)
    lwz	r6, 0(r3)
    rlwinm	r6, r6, 0, 0x11, 0xd
    or	r5, r6, r5
    stw	r5, 0(r3)
    lwz	r5, 0(r3)
    rlwinm	r5, r5, 0, 0xe, 0xa
    or	r0, r5, r0
    stw	r0, 0(r3)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0, 0xb, 9
    stw	r0, 0(r3)
    beq     _8003649c
    bge     _80036480
    cmpwi	r8, 0
    beq     _8003648c
    bge     _80036494
    b       _800364a8
_80036480:
    cmpwi	r8, 4
    bge     _800364a8
    b       _800364a4
_8003648c:
    li	r10, 3
    b       _800364a8
_80036494:
    li	r10, 4
    b       _800364a8
_8003649c:
    li	r10, 5
    b       _800364a8
_800364a4:
    li	r10, 0
_800364a8:
    li	r0, 0
    stw	r0, 4(r3)
    srwi	r7, r7, 5
    slwi	r6, r10, 0xf
    lwz	r8, 4(r3)
    slwi	r5, r10, 0x12
    li	r0, 1
    rlwinm	r8, r8, 0, 0, 0x10
    or	r7, r8, r7
    stw	r7, 4(r3)
    lwz	r7, 4(r3)
    rlwinm	r7, r7, 0, 0x11, 0xd
    or	r6, r7, r6
    stw	r6, 4(r3)
    lwz	r6, 4(r3)
    rlwinm	r6, r6, 0, 0xe, 0xa
    or	r5, r6, r5
    stw	r5, 4(r3)
    stb	r4, 0xc(r3)
    stb	r0, 0xd(r3)
    blr	
}

asm void* GXInitTlutRegion(register void* obj, register void* p2, register int id, register void* p4)
{
    nofralloc
    li	r0, 0
    stw	r0, 0(r3)
    addis	r0, r4, -8
    srwi	r4, r0, 9
    lwz	r6, 0(r3)
    slwi	r0, r5, 0xa
    rlwinm	r5, r6, 0, 0, 0x15
    or	r4, r5, r4
    stw	r4, 0(r3)
    lwz	r4, 0(r3)
    rlwinm	r4, r4, 0, 0x16, 0xa
    or	r0, r4, r0
    stw	r0, 0(r3)
    lwz	r0, 0(r3)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x6500
    stw	r0, 0(r3)
    blr	
}

asm void __GXInitTexMapPreload(register void* p)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    bl      __GXFlushTextureState
    li	r6, 0x61
    lis	r3, 0x6600
    lis	r5, -0x33ff
    stb	r6, -0x8000(r5)
    addi	r4, r3, 0x1000
    addi	r0, r3, 0x1100
    stw	r4, -0x8000(r5)
    stb	r6, -0x8000(r5)
    stw	r0, -0x8000(r5)
    bl      __GXFlushTextureState
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_8003658C(register void* p)
{
    nofralloc
    lwz	r4, -0x7de8(r2)
    lwzu	r0, 0x410(r4)
    stw	r3, 0(r4)
    mr	r3, r0
    blr	
}

asm void fn_800365A0(register void* p)
{
    nofralloc
    lwz	r4, -0x7de8(r2)
    lwzu	r0, 0x414(r4)
    stw	r3, 0(r4)
    mr	r3, r0
    blr	
}

asm void fn_800365B4(register void* p, register int a)
{
    nofralloc
    lwz	r5, -0x7de8(r2)
    slwi	r8, r4, 2
    slwi	r0, r3, 2
    add	r3, r5, r0
    add	r6, r5, r8
    lwz	r4, 0x45c(r3)
    lwz	r0, 0xb8(r6)
    add	r7, r5, r8
    add	r9, r5, r8
    rlwinm	r0, r0, 0, 0, 0xf
    rlwimi	r0, r4, 0, 0x16, 0x1f
    stw	r0, 0xb8(r6)
    add	r10, r5, r8
    lwz	r0, 0xd8(r7)
    rlwinm	r0, r0, 0, 0, 0xf
    rlwimi	r0, r4, 0x16, 0x16, 0x1f
    stw	r0, 0xd8(r7)
    li	r7, 0x61
    lwz	r6, 0x47c(r3)
    lwz	r3, 0xb8(r9)
    rlwinm	r0, r6, 0x1e, 0x1e, 0x1f
    subfic	r4, r0, 1
    clrlwi	r0, r6, 0x1e
    subfic	r0, r0, 1
    cntlzw	r0, r0
    rlwinm	r3, r3, 0, 0x10, 0xe
    rlwinm	r0, r0, 0xb, 8, 0xf
    or	r0, r3, r0
    stw	r0, 0xb8(r9)
    cntlzw	r0, r4
    rlwinm	r0, r0, 0xb, 8, 0xf
    lwz	r3, 0xd8(r10)
    lis	r6, -0x33ff
    add	r4, r5, r8
    rlwinm	r3, r3, 0, 0x10, 0xe
    or	r0, r3, r0
    stw	r0, 0xd8(r10)
    li	r0, 0
    stb	r7, -0x8000(r6)
    lwz	r3, 0xb8(r4)
    stw	r3, -0x8000(r6)
    stb	r7, -0x8000(r6)
    lwz	r3, 0xd8(r4)
    stw	r3, -0x8000(r6)
    sth	r0, 2(r5)
    blr	
}

asm void fn_8003666C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stmw	r27, 0x14(r1)
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4dc(r3)
    cmplwi	r0, 0xff
    beq     _800367d4
    lwz	r0, 0x204(r3)
    li	r31, 0
    rlwinm	r3, r0, 0x16, 0x1c, 0x1f
    addi	r30, r3, 1
    rlwinm	r27, r0, 0x10, 0x1d, 0x1f
    b       _80036740
_800366a4:
    cmpwi	r31, 2
    beq     _800366f4
    bge     _800366c0
    cmpwi	r31, 0
    beq     _800366cc
    bge     _800366e0
    b       _80036718
_800366c0:
    cmpwi	r31, 4
    bge     _80036718
    b       _80036708
_800366cc:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x120(r3)
    clrlwi	r29, r0, 0x1d
    rlwinm	r28, r0, 0x1d, 0x1d, 0x1f
    b       _80036718
_800366e0:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x120(r3)
    rlwinm	r29, r0, 0x1a, 0x1d, 0x1f
    rlwinm	r28, r0, 0x17, 0x1d, 0x1f
    b       _80036718
_800366f4:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x120(r3)
    rlwinm	r29, r0, 0x14, 0x1d, 0x1f
    rlwinm	r28, r0, 0x11, 0x1d, 0x1f
    b       _80036718
_80036708:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x120(r3)
    rlwinm	r29, r0, 0xe, 0x1d, 0x1f
    rlwinm	r28, r0, 0xb, 0x1d, 0x1f
_80036718:
    lwz	r3, -0x7de8(r2)
    li	r0, 1
    slw	r0, r0, r28
    lwz	r3, 0x4dc(r3)
    and.	r0, r3, r0
    bne     _8003673c
    addi	r3, r29, 0
    addi	r4, r28, 0
    bl      fn_800365B4
_8003673c:
    addi	r31, r31, 1
_80036740:
    cmplw	r31, r27
    blt     _800366a4
    li	r31, 0
    addi	r27, r31, 0
    b       _800367cc
_80036754:
    lwz	r5, -0x7de8(r2)
    addi	r3, r27, 0x49c
    rlwinm	r4, r31, 1, 0, 0x1d
    lwzx	r3, r5, r3
    clrlwi.	r0, r31, 0x1f
    addi	r4, r4, 0x100
    add	r4, r5, r4
    rlwinm	r29, r3, 0, 0x18, 0x16
    beq     _80036784
    lwz	r0, 0(r4)
    rlwinm	r28, r0, 0x11, 0x1d, 0x1f
    b       _8003678c
_80036784:
    lwz	r0, 0(r4)
    rlwinm	r28, r0, 0x1d, 0x1d, 0x1f
_8003678c:
    cmplwi	r29, 0xff
    beq     _800367c4
    li	r4, 1
    lwz	r3, 0x4dc(r5)
    slw	r0, r4, r28
    and.	r0, r3, r0
    bne     _800367c4
    lwz	r3, 0x4e0(r5)
    slw	r0, r4, r31
    and.	r0, r3, r0
    beq     _800367c4
    addi	r3, r29, 0
    addi	r4, r28, 0
    bl      fn_800365B4
_800367c4:
    addi	r27, r27, 4
    addi	r31, r31, 1
_800367cc:
    cmplw	r31, r30
    blt     _80036754
_800367d4:
    lmw	r27, 0x14(r1)
    lwz	r0, 0x2c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __GXSetTmemConfig(register int mode)
{
    nofralloc
    stwu	r1, -0x18(r1)
    cmpwi	r3, 1
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    beq     _80036804
    bge     _80036910
    b       _80036910
_80036804:
    li	r0, 0x61
    lis	r3, -0x33ff
    lis	r4, -0x73f2
    stb	r0, -0x8000(r3)
    addi	r4, r4, -0x8000
    stw	r4, -0x8000(r3)
    lis	r4, -0x6ff2
    lis	r7, -0x72f2
    stb	r0, -0x8000(r3)
    addi	r4, r4, -0x4000
    lis	r6, -0x6ef2
    stw	r4, -0x8000(r3)
    lis	r5, -0x71f2
    lis	r4, -0x6df2
    stb	r0, -0x8000(r3)
    addi	r7, r7, -0x7800
    lis	r30, -0x70f2
    stw	r7, -0x8000(r3)
    lis	r12, -0x6cf2
    lis	r11, -0x53f2
    stb	r0, -0x8000(r3)
    addi	r6, r6, -0x3800
    lis	r10, -0x4ff2
    stw	r6, -0x8000(r3)
    lis	r9, -0x52f2
    lis	r8, -0x4ef2
    stb	r0, -0x8000(r3)
    addi	r5, r5, -0x7000
    lis	r7, -0x51f2
    stw	r5, -0x8000(r3)
    lis	r6, -0x4df2
    lis	r5, -0x50f2
    stb	r0, -0x8000(r3)
    addi	r31, r4, -0x3000
    lis	r4, -0x4cf2
    stw	r31, -0x8000(r3)
    addi	r30, r30, -0x6800
    addi	r12, r12, -0x2800
    stb	r0, -0x8000(r3)
    addi	r11, r11, -0x6000
    addi	r10, r10, -0x2000
    stw	r30, -0x8000(r3)
    addi	r9, r9, -0x5800
    addi	r8, r8, -0x1800
    stb	r0, -0x8000(r3)
    addi	r7, r7, -0x5000
    addi	r6, r6, -0x1000
    stw	r12, -0x8000(r3)
    addi	r5, r5, -0x4800
    addi	r4, r4, -0x800
    stb	r0, -0x8000(r3)
    stw	r11, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r10, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r9, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r8, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r7, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r6, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r5, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r4, -0x8000(r3)
    b       _80036a18
_80036910:
    li	r0, 0x61
    lis	r3, -0x33ff
    lis	r4, -0x73f2
    stb	r0, -0x8000(r3)
    addi	r4, r4, -0x8000
    stw	r4, -0x8000(r3)
    lis	r4, -0x6ff2
    lis	r7, -0x72f2
    stb	r0, -0x8000(r3)
    addi	r4, r4, -0x4000
    lis	r6, -0x6ef2
    stw	r4, -0x8000(r3)
    lis	r5, -0x71f2
    lis	r4, -0x6df2
    stb	r0, -0x8000(r3)
    addi	r7, r7, -0x7c00
    lis	r31, -0x70f2
    stw	r7, -0x8000(r3)
    lis	r12, -0x6cf2
    lis	r11, -0x53f2
    stb	r0, -0x8000(r3)
    addi	r6, r6, -0x3c00
    lis	r10, -0x4ff2
    stw	r6, -0x8000(r3)
    lis	r9, -0x52f2
    lis	r8, -0x4ef2
    stb	r0, -0x8000(r3)
    addi	r5, r5, -0x7800
    lis	r7, -0x51f2
    stw	r5, -0x8000(r3)
    lis	r6, -0x4df2
    lis	r5, -0x50f2
    stb	r0, -0x8000(r3)
    addi	r30, r4, -0x3800
    lis	r4, -0x4cf2
    stw	r30, -0x8000(r3)
    addi	r31, r31, -0x7400
    addi	r12, r12, -0x3400
    stb	r0, -0x8000(r3)
    addi	r11, r11, -0x7000
    addi	r10, r10, -0x3000
    stw	r31, -0x8000(r3)
    addi	r9, r9, -0x6c00
    addi	r8, r8, -0x2c00
    stb	r0, -0x8000(r3)
    addi	r7, r7, -0x6800
    addi	r6, r6, -0x2800
    stw	r12, -0x8000(r3)
    addi	r5, r5, -0x6400
    addi	r4, r4, -0x2400
    stb	r0, -0x8000(r3)
    stw	r11, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r10, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r9, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r8, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r7, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r6, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r5, -0x8000(r3)
    stb	r0, -0x8000(r3)
    stw	r4, -0x8000(r3)
_80036a18:
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    blr	
}

asm void __GXInitTexObj(register void* p)
{
    nofralloc
    stwu	r1, -0x28(r1)
    rlwinm	r4, r4, 0, 0x1e, 0x1b
    slwi	r0, r5, 2
    or	r0, r4, r0
    lwz	r11, 0x34(r1)
    rlwinm	r5, r0, 0, 0x1c, 0x18
    lbz	r12, 0x33(r1)
    slwi	r0, r6, 4
    lwz	r4, -0x7de8(r2)
    or	r0, r5, r0
    rlwinm	r5, r0, 0, 0x19, 0x16
    slwi	r0, r11, 7
    or	r0, r5, r0
    rlwinm	r5, r0, 0, 0x17, 0x12
    slwi	r0, r7, 9
    or	r0, r5, r0
    rlwinm	r5, r0, 0, 0x13, 0xf
    slwi	r0, r8, 0xd
    or	r0, r5, r0
    addi	r5, r3, 0x10
    rlwinm	r3, r0, 0, 0x10, 0xc
    slwi	r0, r9, 0x10
    or	r0, r3, r0
    rlwinm	r3, r0, 0, 0xd, 0xb
    slwi	r0, r12, 0x13
    or	r0, r3, r0
    rlwinm	r3, r0, 0, 0xc, 0xa
    rlwinm	r0, r10, 0x14, 4, 0xb
    or	r6, r3, r0
    li	r0, 0x61
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    slwi	r0, r5, 0x18
    rlwimi	r0, r6, 0, 8, 0x1f
    stw	r0, -0x8000(r3)
    li	r0, 0
    sth	r0, 2(r4)
    addi	r1, r1, 0x28
    blr	
}

asm void fn_80036AC4(register void* p, register int a)
{
    nofralloc
    cmpwi	r3, 8
    stwu	r1, -0x78(r1)
    beq     _80036b10
    bge     _80036aec
    cmpwi	r3, 4
    beq     _80036b10
    bge     _80036b00
    cmpwi	r3, 1
    bge     _80036af8
    b       _80036b10
_80036aec:
    cmpwi	r3, 0xc
    bge     _80036b10
    b       _80036b08
_80036af8:
    addi	r0, r3, -1
    b       _80036b14
_80036b00:
    addi	r0, r3, -5
    b       _80036b14
_80036b08:
    addi	r0, r3, -9
    b       _80036b14
_80036b10:
    li	r0, 0
_80036b14:
    lfs	f2, -0x7d50(r2)
    mulli	r3, r0, 3
    lfs	f1, 0(r4)
    lfs	f0, 0xc(r4)
    fmuls	f1, f2, f1
    addi	r11, r5, 0x11
    fmuls	f0, f2, f0
    addi	r0, r3, 6
    extsb	r11, r11
    fctiwz	f1, f1
    li	r10, 0x61
    fctiwz	f0, f0
    lis	r9, -0x33ff
    stb	r10, -0x8000(r9)
    stfd	f1, 0x70(r1)
    slwi	r0, r0, 0x18
    addi	r6, r3, 7
    stfd	f0, 0x68(r1)
    addi	r5, r3, 8
    lwz	r8, 0x74(r1)
    lwz	r7, 0x6c(r1)
    lwz	r3, -0x7de8(r2)
    rlwinm	r7, r7, 0xb, 0xa, 0x14
    rlwimi	r7, r8, 0, 0x15, 0x1f
    rlwinm	r7, r7, 0, 0xa, 7
    rlwimi	r7, r11, 0x16, 8, 9
    rlwimi	r0, r7, 0, 8, 0x1f
    stw	r0, -0x8000(r9)
    li	r0, 0
    lfs	f1, 4(r4)
    lfs	f0, 0x10(r4)
    fmuls	f1, f2, f1
    fmuls	f0, f2, f0
    stb	r10, -0x8000(r9)
    fctiwz	f1, f1
    fctiwz	f0, f0
    stfd	f1, 0x60(r1)
    stfd	f0, 0x58(r1)
    lwz	r8, 0x64(r1)
    lwz	r7, 0x5c(r1)
    rlwinm	r7, r7, 0xb, 0xa, 0x14
    rlwimi	r7, r8, 0, 0x15, 0x1f
    rlwinm	r7, r7, 0, 0xa, 7
    rlwimi	r7, r11, 0x14, 8, 9
    clrlwi	r7, r7, 8
    rlwimi	r7, r6, 0x18, 0, 7
    stw	r7, -0x8000(r9)
    lfs	f1, 8(r4)
    lfs	f0, 0x14(r4)
    fmuls	f1, f2, f1
    fmuls	f0, f2, f0
    stb	r10, -0x8000(r9)
    fctiwz	f1, f1
    fctiwz	f0, f0
    stfd	f1, 0x50(r1)
    stfd	f0, 0x48(r1)
    lwz	r6, 0x54(r1)
    lwz	r4, 0x4c(r1)
    rlwinm	r4, r4, 0xb, 0xa, 0x14
    rlwimi	r4, r6, 0, 0x15, 0x1f
    rlwinm	r4, r4, 0, 0xa, 7
    rlwimi	r4, r11, 0x12, 8, 9
    clrlwi	r4, r4, 8
    rlwimi	r4, r5, 0x18, 0, 7
    stw	r4, -0x8000(r9)
    sth	r0, 2(r3)
    addi	r1, r1, 0x78
    blr	
}

asm void __GXInitTexCacheRegs(register void* p, register int a, register int b)
{
    nofralloc
    cmpwi	r3, 2
    beq     _80036cf0
    bge     _80036c40
    cmpwi	r3, 0
    beq     _80036c4c
    bge     _80036c9c
    b       _80036d90
_80036c40:
    cmpwi	r3, 4
    bge     _80036d90
    b       _80036d40
_80036c4c:
    lwz	r7, -0x7de8(r2)
    slwi	r5, r5, 4
    li	r0, 0x61
    lwz	r6, 0x128(r7)
    lis	r3, -0x33ff
    rlwinm	r6, r6, 0, 0, 0x1b
    or	r4, r6, r4
    stw	r4, 0x128(r7)
    lwz	r4, 0x128(r7)
    rlwinm	r4, r4, 0, 0x1c, 0x17
    or	r4, r4, r5
    stw	r4, 0x128(r7)
    lwz	r4, 0x128(r7)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x2500
    stw	r4, 0x128(r7)
    stb	r0, -0x8000(r3)
    lwz	r0, 0x128(r7)
    stw	r0, -0x8000(r3)
    b       _80036d90
_80036c9c:
    lwz	r7, -0x7de8(r2)
    slwi	r6, r4, 8
    slwi	r4, r5, 0xc
    lwz	r5, 0x128(r7)
    li	r0, 0x61
    lis	r3, -0x33ff
    rlwinm	r5, r5, 0, 0x18, 0x13
    or	r5, r5, r6
    stw	r5, 0x128(r7)
    lwz	r5, 0x128(r7)
    rlwinm	r5, r5, 0, 0x14, 0xf
    or	r4, r5, r4
    stw	r4, 0x128(r7)
    lwz	r4, 0x128(r7)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x2500
    stw	r4, 0x128(r7)
    stb	r0, -0x8000(r3)
    lwz	r0, 0x128(r7)
    stw	r0, -0x8000(r3)
    b       _80036d90
_80036cf0:
    lwz	r7, -0x7de8(r2)
    slwi	r5, r5, 4
    li	r0, 0x61
    lwz	r6, 0x12c(r7)
    lis	r3, -0x33ff
    rlwinm	r6, r6, 0, 0, 0x1b
    or	r4, r6, r4
    stw	r4, 0x12c(r7)
    lwz	r4, 0x12c(r7)
    rlwinm	r4, r4, 0, 0x1c, 0x17
    or	r4, r4, r5
    stw	r4, 0x12c(r7)
    lwz	r4, 0x12c(r7)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x2600
    stw	r4, 0x12c(r7)
    stb	r0, -0x8000(r3)
    lwz	r0, 0x12c(r7)
    stw	r0, -0x8000(r3)
    b       _80036d90
_80036d40:
    lwz	r7, -0x7de8(r2)
    slwi	r6, r4, 8
    slwi	r4, r5, 0xc
    lwz	r5, 0x12c(r7)
    li	r0, 0x61
    lis	r3, -0x33ff
    rlwinm	r5, r5, 0, 0x18, 0x13
    or	r5, r5, r6
    stw	r5, 0x12c(r7)
    lwz	r5, 0x12c(r7)
    rlwinm	r5, r5, 0, 0x14, 0xf
    or	r4, r5, r4
    stw	r4, 0x12c(r7)
    lwz	r4, 0x12c(r7)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x2600
    stw	r4, 0x12c(r7)
    stb	r0, -0x8000(r3)
    lwz	r0, 0x12c(r7)
    stw	r0, -0x8000(r3)
_80036d90:
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    sth	r0, 2(r3)
    blr	
}

asm void fn_80036DA0(register void* p, register int a)
{
    nofralloc
    cmpwi	r3, 2
    beq     _80036e28
    bge     _80036dbc
    cmpwi	r3, 0
    beq     _80036dc8
    bge     _80036df8
    b       _80036e84
_80036dbc:
    cmpwi	r3, 4
    bge     _80036e84
    b       _80036e58
_80036dc8:
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 3
    addi	r4, r3, 0x120
    lwz	r3, 0x120(r3)
    rlwinm	r3, r3, 0, 0, 0x1c
    or	r3, r3, r5
    stw	r3, 0(r4)
    lwz	r3, 0(r4)
    rlwinm	r3, r3, 0, 0x1d, 0x19
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _80036e84
_80036df8:
    lwz	r6, -0x7de8(r2)
    slwi	r0, r4, 9
    slwi	r3, r5, 6
    lwz	r4, 0x120(r6)
    rlwinm	r4, r4, 0, 0x1a, 0x16
    or	r3, r4, r3
    stw	r3, 0x120(r6)
    lwz	r3, 0x120(r6)
    rlwinm	r3, r3, 0, 0x17, 0x13
    or	r0, r3, r0
    stw	r0, 0x120(r6)
    b       _80036e84
_80036e28:
    lwz	r6, -0x7de8(r2)
    slwi	r0, r4, 0xf
    slwi	r3, r5, 0xc
    lwz	r4, 0x120(r6)
    rlwinm	r4, r4, 0, 0x14, 0x10
    or	r3, r4, r3
    stw	r3, 0x120(r6)
    lwz	r3, 0x120(r6)
    rlwinm	r3, r3, 0, 0x11, 0xd
    or	r0, r3, r0
    stw	r0, 0x120(r6)
    b       _80036e84
_80036e58:
    lwz	r6, -0x7de8(r2)
    slwi	r0, r4, 0x15
    slwi	r3, r5, 0x12
    lwz	r4, 0x120(r6)
    rlwinm	r4, r4, 0, 0xe, 0xa
    or	r3, r4, r3
    stw	r3, 0x120(r6)
    lwz	r3, 0x120(r6)
    rlwinm	r3, r3, 0, 0xb, 7
    or	r0, r3, r0
    stw	r0, 0x120(r6)
_80036e84:
    li	r0, 0x61
    lwz	r4, -0x7de8(r2)
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    li	r0, 0
    lwz	r3, 0x120(r4)
    stw	r3, -0x8000(r5)
    lwz	r3, 0x4f4(r4)
    ori	r3, r3, 3
    stw	r3, 0x4f4(r4)
    sth	r0, 2(r4)
    blr	
}

asm void fn_80036EB4(register void* p)
{
    nofralloc
    lwz	r4, -0x7de8(r2)
    rlwinm	r0, r3, 0x10, 8, 0xf
    lwz	r3, 0x204(r4)
    rlwinm	r3, r3, 0, 0x10, 0xc
    or	r0, r3, r0
    stw	r0, 0x204(r4)
    lwz	r0, 0x4f4(r4)
    ori	r0, r0, 6
    stw	r0, 0x4f4(r4)
    blr	
}

asm void fn_80036EDC(register void* p)
{
    nofralloc
    mflr	r0
    li	r4, 0
    stw	r0, 4(r1)
    li	r0, 0
    li	r5, 0
    stwu	r1, -0x18(r1)
    li	r6, 0
    li	r7, 0
    stw	r0, 8(r1)
    li	r8, 0
    li	r9, 0
    stw	r0, 0xc(r1)
    li	r10, 0
    bl      __GXInitTexObj
    lwz	r0, 0x1c(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80036F24(void)
{
    nofralloc
    lwz	r3, -0x7de8(r2)
    li	r6, 0
    li	r4, 0
    lwz	r0, 0x204(r3)
    rlwinm	r0, r0, 0x10, 0x1d, 0x1f
    cmplwi	r0, 0
    mtctr	r0
    ble     _80036fac
_80036f44:
    cmpwi	r4, 2
    beq     _80036f84
    bge     _80036f60
    cmpwi	r4, 0
    beq     _80036f6c
    bge     _80036f78
    b       _80036f98
_80036f60:
    cmpwi	r4, 4
    bge     _80036f98
    b       _80036f90
_80036f6c:
    lwz	r0, 0x120(r3)
    clrlwi	r5, r0, 0x1d
    b       _80036f98
_80036f78:
    lwz	r0, 0x120(r3)
    rlwinm	r5, r0, 0x1a, 0x1d, 0x1f
    b       _80036f98
_80036f84:
    lwz	r0, 0x120(r3)
    rlwinm	r5, r0, 0x14, 0x1d, 0x1f
    b       _80036f98
_80036f90:
    lwz	r0, 0x120(r3)
    rlwinm	r5, r0, 0xe, 0x1d, 0x1f
_80036f98:
    li	r0, 1
    slw	r0, r0, r5
    or	r6, r6, r0
    addi	r4, r4, 1
    bdnz    _80036f44
_80036fac:
    addi	r4, r3, 0x124
    lwz	r3, 0x124(r3)
    clrlwi	r0, r3, 0x18
    cmplw	r0, r6
    beqlr	
    rlwinm	r0, r3, 0, 0, 0x17
    or	r0, r0, r6
    stw	r0, 0(r4)
    li	r0, 0x61
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    li	r0, 0
    lwz	r4, -0x7de8(r2)
    lwz	r3, 0x124(r4)
    stw	r3, -0x8000(r5)
    sth	r0, 2(r4)
    blr	
}

asm void __GXFlushTextureState(void)
{
    nofralloc
    li	r0, 0x61
    lwz	r4, -0x7de8(r2)
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    li	r0, 0
    lwz	r3, 0x124(r4)
    stw	r3, -0x8000(r5)
    sth	r0, 2(r4)
    blr	
}

asm void fn_80037014(register void* p)
{
    nofralloc
    cmpwi	r3, 0
    lis     r5, lbl_8012B368@ha
    addi	r0, r5, lbl_8012B368@l
    bne     _80037034
    slwi	r4, r4, 2
    add	r5, r0, r4
    addi	r9, r5, 0x28
    b       _80037048
_80037034:
    slwi	r4, r4, 2
    add	r5, r0, r4
    add	r9, r0, r4
    addi	r5, r5, 0x14
    addi	r9, r9, 0x3c
_80037048:
    lwz	r7, -0x7de8(r2)
    slwi	r3, r3, 2
    lwz	r0, 0(r5)
    li	r5, 0x61
    add	r6, r7, r3
    lwz	r3, 0x130(r6)
    lis	r4, -0x33ff
    stb	r5, -0x8000(r4)
    rlwinm	r3, r3, 0, 0, 7
    rlwimi	r3, r0, 0, 8, 0x1f
    stw	r3, -0x8000(r4)
    li	r0, 0
    stw	r3, 0x130(r6)
    lwz	r8, 0x170(r6)
    lwz	r3, 0(r9)
    rlwinm	r8, r8, 0, 0x1c, 7
    stb	r5, -0x8000(r4)
    rlwimi	r8, r3, 0, 8, 0x1b
    stw	r8, -0x8000(r4)
    stw	r8, 0x170(r6)
    sth	r0, 2(r7)
    blr	
}

asm void GXWriteCachedParamF0(register void* p)
{
    nofralloc
    lwz	r9, -0x7de8(r2)
    slwi	r3, r3, 2
    li	r0, 0x61
    add	r8, r9, r3
    lwz	r10, 0x130(r8)
    lis	r3, -0x33ff
    rlwimi	r10, r4, 0xc, 0x10, 0x13
    stb	r0, -0x8000(r3)
    addi	r4, r10, 0
    rlwimi	r4, r5, 8, 0x14, 0x17
    rlwimi	r4, r6, 4, 0x18, 0x1b
    rlwimi	r4, r7, 0, 0x1c, 0x1f
    stw	r4, -0x8000(r3)
    li	r0, 0
    stw	r4, 0x130(r8)
    sth	r0, 2(r9)
    blr	
}

asm void GXWriteCachedParam1F0(register void* p)
{
    nofralloc
    lwz	r9, -0x7de8(r2)
    slwi	r3, r3, 2
    li	r0, 0x61
    add	r8, r9, r3
    lwz	r10, 0x170(r8)
    lis	r3, -0x33ff
    rlwimi	r10, r4, 0xd, 0x10, 0x12
    stb	r0, -0x8000(r3)
    addi	r4, r10, 0
    rlwimi	r4, r5, 0xa, 0x13, 0x15
    rlwimi	r4, r6, 7, 0x16, 0x18
    rlwimi	r4, r7, 4, 0x19, 0x1b
    stw	r4, -0x8000(r3)
    li	r0, 0
    stw	r4, 0x170(r8)
    sth	r0, 2(r9)
    blr	
}

asm void fn_80037128(register void* p)
{
    nofralloc
    lwz	r0, -0x7de8(r2)
    slwi	r9, r3, 2
    cmpwi	r4, 1
    add	r3, r0, r9
    lwz	r3, 0x130(r3)
    rlwimi	r3, r4, 0x12, 0xd, 0xd
    addi	r10, r3, 0
    bgt     _80037154
    rlwimi	r10, r6, 0x14, 0xa, 0xb
    rlwimi	r10, r5, 0x10, 0xe, 0xf
    b       _80037160
_80037154:
    li	r0, 3
    rlwimi	r10, r4, 0x13, 0xa, 0xb
    rlwimi	r10, r0, 0x10, 0xe, 0xf
_80037160:
    li	r0, 0x61
    lwz	r4, -0x7de8(r2)
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    rlwimi	r10, r7, 0x13, 0xc, 0xc
    rlwimi	r10, r8, 0x16, 8, 9
    stw	r10, -0x8000(r5)
    add	r3, r4, r9
    li	r0, 0
    stw	r10, 0x130(r3)
    sth	r0, 2(r4)
    blr	
}

asm void fn_80037190(register void* p)
{
    nofralloc
    lwz	r0, -0x7de8(r2)
    slwi	r9, r3, 2
    cmpwi	r4, 1
    add	r3, r0, r9
    lwz	r3, 0x170(r3)
    rlwimi	r3, r4, 0x12, 0xd, 0xd
    addi	r10, r3, 0
    bgt     _800371bc
    rlwimi	r10, r6, 0x14, 0xa, 0xb
    rlwimi	r10, r5, 0x10, 0xe, 0xf
    b       _800371c8
_800371bc:
    li	r0, 3
    rlwimi	r10, r4, 0x13, 0xa, 0xb
    rlwimi	r10, r0, 0x10, 0xe, 0xf
_800371c8:
    li	r0, 0x61
    lwz	r4, -0x7de8(r2)
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    rlwimi	r10, r7, 0x13, 0xc, 0xc
    rlwimi	r10, r8, 0x16, 8, 9
    stw	r10, -0x8000(r5)
    add	r3, r4, r9
    li	r0, 0
    stw	r10, 0x170(r3)
    sth	r0, 2(r4)
    blr	
}

asm void __GXSetTexRegion(register void* p, register int a)
{
    nofralloc
    lbz	r0, 3(r4)
    slwi	r8, r3, 1
    lbz	r5, 0(r4)
    addi	r7, r8, 0xe0
    slwi	r9, r0, 0xc
    rlwimi	r9, r5, 0, 0x18, 0x1f
    lbz	r10, 2(r4)
    lbz	r6, 1(r4)
    slwi	r7, r7, 0x18
    li	r5, 0x61
    lwz	r3, -0x7de8(r2)
    lis	r4, -0x33ff
    stb	r5, -0x8000(r4)
    rlwimi	r7, r9, 0, 0xc, 0x1f
    addi	r0, r8, 0xe1
    stw	r7, -0x8000(r4)
    slwi	r7, r6, 0xc
    slwi	r6, r0, 0x18
    rlwimi	r7, r10, 0, 0x18, 0x1f
    stb	r5, -0x8000(r4)
    rlwimi	r6, r7, 0, 0xc, 0x1f
    stw	r6, -0x8000(r4)
    li	r0, 0
    stb	r5, -0x8000(r4)
    stw	r6, -0x8000(r4)
    stb	r5, -0x8000(r4)
    stw	r6, -0x8000(r4)
    sth	r0, 2(r3)
    blr	
}

asm void fn_8003726C(register void* p)
{
    nofralloc
    lha	r0, 6(r4)
    slwi	r9, r3, 1
    lha	r5, 0(r4)
    addi	r8, r9, 0xe0
    rlwinm	r10, r0, 0xc, 9, 0x13
    rlwimi	r10, r5, 0, 0x15, 0x1f
    lha	r7, 4(r4)
    lha	r6, 2(r4)
    slwi	r8, r8, 0x18
    li	r5, 0x61
    lwz	r3, -0x7de8(r2)
    lis	r4, -0x33ff
    stb	r5, -0x8000(r4)
    rlwimi	r8, r10, 0, 9, 0x1f
    addi	r0, r9, 0xe1
    stw	r8, -0x8000(r4)
    rlwinm	r8, r6, 0xc, 9, 0x13
    slwi	r6, r0, 0x18
    rlwimi	r8, r7, 0, 0x15, 0x1f
    stb	r5, -0x8000(r4)
    rlwimi	r6, r8, 0, 9, 0x1f
    stw	r6, -0x8000(r4)
    li	r0, 0
    stb	r5, -0x8000(r4)
    stw	r6, -0x8000(r4)
    stb	r5, -0x8000(r4)
    stw	r6, -0x8000(r4)
    sth	r0, 2(r3)
    blr	
}


#pragma pop
