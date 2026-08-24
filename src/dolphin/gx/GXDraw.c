typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void* memset(void*, int, unsigned long);
extern void* memcpy(void*, const void*, unsigned long);
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void fn_80038878(void);
extern void __cvt_fp2unsigned(void);
extern void GXSetCPUFifo(register void* fifo);
extern void GXSaveCPUFifo(register void* fifo);
extern void GXGetCPUFifo(void);
extern void __GXSaveCPUFifoAux(void);
extern void __GXSetDirtyState(void);
extern void __GXSendFlushPrim(void);
asm void GXSetViewport(register void* p);
asm void fn_80039088(register void* p);

extern void fn_8003D42C(void);
extern unsigned char jumptable_8012B400[92];
extern unsigned char jumptable_8012B45C[144];
extern unsigned char jumptable_8012B4EC[92];
extern unsigned char lbl_8008FF50[144];
extern unsigned char lbl_801783A0[1312];

#pragma push
#pragma force_active on

asm void fn_80039954(register void* p);
asm int fn_8003A4E8(register u32 a);
asm void fn_8003A680(void);
asm int fn_8003A760(register u32 a);
asm int fn_8003A91C(register u32 a);
asm void fn_8003B63C(register u32 a);
asm int fn_8003B798(register u32 a, register int b);
asm int fn_8003B8A8(register u32 a);
asm int fn_8003B930(register u32 a);

asm void GXBeginDisplayList(register void* p1, register void* p2)
{
    nofralloc
    mflr    r0
    lis     r5, lbl_801783A0@ha
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r5, lbl_801783A0@l
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    addi    r29, r4, 0
    stw     r28, 0x10(r1)
    addi    r28, r3, 0
    bl      GXGetCPUFifo
    lwz     r4, -0x7de8(r2)
    mr      r30, r3
    lwz     r0, 0x4f4(r4)
    cmplwi  r0, 0
    beq     _800388c4
    bl      __GXSetDirtyState
_800388c4:
    lwz     r4, -0x7de8(r2)
    lbz     r0, 0x4f1(r4)
    cmplwi  r0, 0
    beq     _800388e0
    addi    r3, r31, 0x24
    li      r5, 0x4f8
    bl      memcpy
_800388e0:
    addi    r0, r29, -4
    stw     r28, 0(r31)
    add     r0, r28, r0
    stw     r0, 4(r31)
    li      r4, 0
    li      r0, 1
    stw     r29, 8(r31)
    mr      r3, r30
    stw     r4, 0x1c(r31)
    stw     r28, 0x14(r31)
    stw     r28, 0x18(r31)
    lwz     r4, -0x7de8(r2)
    stb     r0, 0x4f0(r4)
    bl      GXSaveCPUFifo
    stw     r30, -0x7798(r13)
    mr      r3, r31
    bl      GXSetCPUFifo
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr     
}

asm void GXEndDisplayList(register void* p)
{
    nofralloc
    mflr    r0
    lis     r4, lbl_801783A0@ha
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    addi    r31, r4, lbl_801783A0@l
    stw     r30, 0x10(r1)
    stw     r29, 0xc(r1)
    stw     r28, 8(r1)
    lwz     r3, -0x7de8(r2)
    lwz     r0, 0x4f4(r3)
    cmplwi  r0, 0
    beq     _8003897c
    bl      __GXSetDirtyState
_8003897c:
    lwz     r4, -0x77f8(r13)
    mr      r3, r31
    lwz     r0, 0x14(r4)
    rlwinm  r30, r0, 6, 0x1f, 0x1f
    bl      __GXSaveCPUFifoAux
    lwz     r3, -0x7798(r13)
    bl      GXSetCPUFifo
    lwz     r3, -0x7de8(r2)
    lbz     r0, 0x4f1(r3)
    cmplwi  r0, 0
    beq     _800389d8
    bl      OSDisableInterrupts
    lwz     r4, -0x7de8(r2)
    mr      r29, r3
    li      r5, 0x4f8
    lwz     r28, 8(r4)
    addi    r3, r4, 0
    addi    r4, r31, 0x24
    bl      memcpy
    lwz     r4, -0x7de8(r2)
    mr      r3, r29
    stw     r28, 8(r4)
    bl      OSRestoreInterrupts
_800389d8:
    lwz     r3, -0x7de8(r2)
    li      r0, 0
    cmplwi  r30, 0
    stb     r0, 0x4f0(r3)
    bne     _800389f4
    lwz     r3, 0x1c(r31)
    b       _800389f8
_800389f4:
    li      r3, 0
_800389f8:
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    lwz     r29, 0xc(r1)
    lwz     r28, 8(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr     
}

asm void fn_80038A18(register void* p)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    addi    r31, r4, 0
    stw     r30, 0x10(r1)
    addi    r30, r3, 0
    lwz     r5, -0x7de8(r2)
    lwz     r0, 0x4f4(r5)
    cmplwi  r0, 0
    beq     _80038a48
    bl      __GXSetDirtyState
_80038a48:
    lwz     r3, -0x7de8(r2)
    lwz     r0, 0(r3)
    cmplwi  r0, 0
    bne     _80038a5c
    bl      __GXSendFlushPrim
_80038a5c:
    li      r0, 0x40
    lis     r3, -0x33ff
    stb     r0, -0x8000(r3)
    stw     r30, -0x8000(r3)
    stw     r31, -0x8000(r3)
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr     
}

asm int fn_80038A88(register void* p)
{
    nofralloc
    lwz     r5, -0x7de8(r2)
    cmpwi   r4, 1
    stw     r4, 0x420(r5)
    lfs     f0, 0(r3)
    stfs    f0, 0x424(r5)
    lfs     f0, 0x14(r3)
    stfs    f0, 0x42c(r5)
    lfs     f0, 0x28(r3)
    stfs    f0, 0x434(r5)
    lfs     f0, 0x2c(r3)
    stfs    f0, 0x438(r5)
    bne     _80038acc
    lfs     f0, 0xc(r3)
    stfs    f0, 0x428(r5)
    lfs     f0, 0x1c(r3)
    stfs    f0, 0x430(r5)
    b       _80038adc
_80038acc:
    lfs     f0, 8(r3)
    stfs    f0, 0x428(r5)
    lfs     f0, 0x18(r3)
    stfs    f0, 0x430(r5)
_80038adc:
    li      r0, 0x10
    lwz     r4, -0x7de8(r2)
    lis     r5, -0x33ff
    lis     r3, 6
    stb     r0, -0x8000(r5)
    addi    r0, r3, 0x1020
    stw     r0, -0x8000(r5)
    li      r0, 1
    lfs     f0, 0x424(r4)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x428(r4)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x42c(r4)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x430(r4)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x434(r4)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x438(r4)
    stfs    f0, -0x8000(r5)
    lwz     r3, 0x420(r4)
    stw     r3, -0x8000(r5)
    sth     r0, 2(r4)
    blr     
}

asm void fn_80038B3C(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    mr      r31, r3
    lfs     f1, 0(r3)
    bl      __cvt_fp2unsigned
    lwz     r7, -0x7de8(r2)
    lis     r4, 6
    li      r6, 0x10
    stw     r3, 0x420(r7)
    lis     r5, -0x33ff
    addi    r3, r4, 0x1020
    lfs     f0, 4(r31)
    li      r0, 1
    stfs    f0, 0x424(r7)
    lfs     f0, 8(r31)
    stfs    f0, 0x428(r7)
    lfs     f0, 0xc(r31)
    stfs    f0, 0x42c(r7)
    lfs     f0, 0x10(r31)
    stfs    f0, 0x430(r7)
    lfs     f0, 0x14(r31)
    stfs    f0, 0x434(r7)
    lfs     f0, 0x18(r31)
    stfs    f0, 0x438(r7)
    stb     r6, -0x8000(r5)
    stw     r3, -0x8000(r5)
    lfs     f0, 0x424(r7)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x428(r7)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x42c(r7)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x430(r7)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x434(r7)
    stfs    f0, -0x8000(r5)
    lfs     f0, 0x438(r7)
    stfs    f0, -0x8000(r5)
    lwz     r3, 0x420(r7)
    stw     r3, -0x8000(r5)
    sth     r0, 2(r7)
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr     
}

asm void fn_80038BFC(register u32 a)
{
    nofralloc
    stwu    r1, -0x18(r1)
    lis     r0, 0x4330
    lwz     r5, -0x7de8(r2)
    lfd     f1, -0x7cd8(r2)
    lwz     r4, 0x420(r5)
    stw     r4, 0x14(r1)
    stw     r0, 0x10(r1)
    lfd     f0, 0x10(r1)
    fsubs   f0, f0, f1
    stfs    f0, 0(r3)
    lfs     f0, 0x424(r5)
    stfs    f0, 4(r3)
    lfs     f0, 0x428(r5)
    stfs    f0, 8(r3)
    lfs     f0, 0x42c(r5)
    stfs    f0, 0xc(r3)
    lfs     f0, 0x430(r5)
    stfs    f0, 0x10(r3)
    lfs     f0, 0x434(r5)
    stfs    f0, 0x14(r3)
    lfs     f0, 0x438(r5)
    stfs    f0, 0x18(r3)
    addi    r1, r1, 0x18
    blr     
}

asm void fn_80038C5C(register u32 a)
{
    nofralloc
    lis     r5, -0x33ff
    li      r0, 0x10
    slwi    r4, r4, 2
    stb     r0, -0x8000(r5)
    oris    r0, r4, 0xb
    stw     r0, -0x8000(r5)
    addi    r4, r5, -0x8000
    psq_l   f5, 0x0(r3), 0, 0
    psq_l   f4, 0x8(r3), 0, 0
    psq_l   f3, 0x10(r3), 0, 0
    psq_l   f2, 0x18(r3), 0, 0
    psq_l   f1, 0x20(r3), 0, 0
    psq_l   f0, 0x28(r3), 0, 0
    psq_st  f5, 0x0(r4), 0, 0
    psq_st  f4, 0x0(r4), 0, 0
    psq_st  f3, 0x0(r4), 0, 0
    psq_st  f2, 0x0(r4), 0, 0
    psq_st  f1, 0x0(r4), 0, 0
    psq_st  f0, 0x0(r4), 0, 0
    blr     
}

asm void fn_80038CAC(register u32 a)
{
    nofralloc
    mulli   r5, r4, 3
    lis     r4, -0x33ff
    li      r0, 0x10
    addi    r5, r5, 0x400
    stb     r0, -0x8000(r4)
    oris    r0, r5, 8
    stwu    r0, -0x8000(r4)
    psq_l   f5, 0x0(r3), 0, 0
    lfs     f4, 8(r3)
    psq_l   f3, 0x10(r3), 0, 0
    lfs     f2, 0x18(r3)
    psq_l   f1, 0x20(r3), 0, 0
    lfs     f0, 0x28(r3)
    psq_st  f5, 0x0(r4), 0, 0
    stfs    f4, 0(r4)
    psq_st  f3, 0x0(r4), 0, 0
    stfs    f2, 0(r4)
    psq_st  f1, 0x0(r4), 0, 0
    stfs    f0, 0(r4)
    blr     
}

asm void fn_80038CFC(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -8(r1)
    lwz     r4, -0x7de8(r2)
    lwzu    r0, 0x80(r4)
    rlwinm  r0, r0, 0, 0, 0x19
    or      r0, r0, r3
    stw     r0, 0(r4)
    li      r3, 0
    bl      fn_80039088
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr     
}

asm void GXWritePrimitiveFifo(register void* p)
{
    nofralloc
    cmplwi  r4, 0x40
    blt     _80038d4c
    addi    r0, r4, -0x40
    slwi    r4, r0, 2
    addi    r7, r4, 0x500
    b       _80038d50
_80038d4c:
    slwi    r7, r4, 2
_80038d50:
    cmpwi   r5, 1
    bne     _80038d60
    li      r4, 8
    b       _80038d64
_80038d60:
    li      r4, 0xc
_80038d64:
    addi    r0, r4, -1
    slwi    r6, r0, 0x10
    li      r0, 0x10
    lis     r4, -0x33ff
    stb     r0, -0x8000(r4)
    or      r0, r7, r6
    cmpwi   r5, 0
    stw     r0, -0x8000(r4)
    bne     _80038dc0
    addi    r4, r4, -0x8000
    psq_l   f5, 0x0(r3), 0, 0
    psq_l   f4, 0x8(r3), 0, 0
    psq_l   f3, 0x10(r3), 0, 0
    psq_l   f2, 0x18(r3), 0, 0
    psq_l   f1, 0x20(r3), 0, 0
    psq_l   f0, 0x28(r3), 0, 0
    psq_st  f5, 0x0(r4), 0, 0
    psq_st  f4, 0x0(r4), 0, 0
    psq_st  f3, 0x0(r4), 0, 0
    psq_st  f2, 0x0(r4), 0, 0
    psq_st  f1, 0x0(r4), 0, 0
    psq_st  f0, 0x0(r4), 0, 0
    blr     
_80038dc0:
    addi    r4, r4, -0x8000
    psq_l   f3, 0x0(r3), 0, 0
    psq_l   f2, 0x8(r3), 0, 0
    psq_l   f1, 0x10(r3), 0, 0
    psq_l   f0, 0x18(r3), 0, 0
    psq_st  f3, 0x0(r4), 0, 0
    psq_st  f2, 0x0(r4), 0, 0
    psq_st  f1, 0x0(r4), 0, 0
    psq_st  f0, 0x0(r4), 0, 0
    blr     
}

asm void GXSetViewport(register void* p)
{
    nofralloc
    mflr    r0
    cmplwi  r3, 0
    stw     r0, 4(r1)
    stwu    r1, -0x60(r1)
    stfd    f31, 0x58(r1)
    stfd    f30, 0x50(r1)
    stfd    f29, 0x48(r1)
    stfd    f28, 0x40(r1)
    stfd    f27, 0x38(r1)
    stfd    f26, 0x30(r1)
    bne     _80038e1c
    lfs     f0, -0x7ce0(r2)
    fsubs   f2, f2, f0
_80038e1c:
    lfs     f11, -0x7ce0(r2)
    fneg    f10, f4
    lfs     f0, -0x7ccc(r2)
    lfs     f9, -0x7cd0(r2)
    fmuls   f31, f3, f11
    lwz     r3, -0x7de8(r2)
    fmuls   f7, f4, f11
    stfs    f1, 0x43c(r3)
    fadds   f8, f1, f31
    fmuls   f30, f0, f6
    stfs    f2, 0x440(r3)
    fadds   f1, f2, f7
    stfs    f3, 0x444(r3)
    fmuls   f0, f0, f5
    fmuls   f29, f10, f11
    stfs    f4, 0x448(r3)
    fadds   f27, f9, f8
    stfs    f5, 0x44c(r3)
    fadds   f26, f9, f1
    fsubs   f28, f30, f0
    stfs    f6, 0x450(r3)
    lbz     r0, 0x454(r3)
    cmplwi  r0, 0
    beq     _80038e88
    fmr     f1, f5
    lfs     f2, 0x458(r3)
    bl      fn_80038878
_80038e88:
    li      r0, 0x10
    lwz     r3, -0x7de8(r2)
    lis     r5, -0x33ff
    lis     r4, 5
    stb     r0, -0x8000(r5)
    addi    r0, r4, 0x101a
    stw     r0, -0x8000(r5)
    li      r0, 1
    stfs    f31, -0x8000(r5)
    stfs    f29, -0x8000(r5)
    stfs    f28, -0x8000(r5)
    stfs    f27, -0x8000(r5)
    stfs    f26, -0x8000(r5)
    stfs    f30, -0x8000(r5)
    sth     r0, 2(r3)
    lwz     r0, 0x64(r1)
    lfd     f31, 0x58(r1)
    lfd     f30, 0x50(r1)
    lfd     f29, 0x48(r1)
    lfd     f28, 0x40(r1)
    lfd     f27, 0x38(r1)
    lfd     f26, 0x30(r1)
    addi    r1, r1, 0x60
    mtlr    r0
    blr     
}

asm void fn_80038EEC(void)
{
    nofralloc
    mflr    r0
    li      r3, 1
    stw     r0, 4(r1)
    stwu    r1, -8(r1)
    bl      GXSetViewport
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr     
}

asm void fn_80038F10(register void* p)
{
    nofralloc
    lwz     r4, -0x7de8(r2)
    lfs     f0, 0x43c(r4)
    stfs    f0, 0(r3)
    lfs     f0, 0x440(r4)
    stfs    f0, 4(r3)
    lfs     f0, 0x444(r4)
    stfs    f0, 8(r3)
    lfs     f0, 0x448(r4)
    stfs    f0, 0xc(r3)
    lfs     f0, 0x44c(r4)
    stfs    f0, 0x10(r3)
    lfs     f0, 0x450(r4)
    stfs    f0, 0x14(r3)
    blr     
}

asm void fn_80038F48(register void* p)
{
    nofralloc
    lwz     r8, -0x7de8(r2)
    addi    r9, r3, 0x156
    addi    r10, r4, 0x156
    lwz     r3, 0xf8(r8)
    addi    r0, r5, -1
    slwi    r4, r9, 0xc
    rlwinm  r3, r3, 0, 0, 0x14
    or      r3, r3, r10
    stw     r3, 0xf8(r8)
    addi    r3, r6, -1
    add     r6, r10, r3
    lwz     r5, 0xf8(r8)
    add     r0, r9, r0
    rlwinm  r3, r5, 0, 0x14, 8
    or      r3, r3, r4
    stw     r3, 0xf8(r8)
    slwi    r3, r0, 0xc
    li      r5, 0x61
    lwz     r7, 0xfc(r8)
    lis     r4, -0x33ff
    li      r0, 0
    rlwinm  r7, r7, 0, 0, 0x14
    or      r6, r7, r6
    stw     r6, 0xfc(r8)
    lwz     r6, 0xfc(r8)
    rlwinm  r6, r6, 0, 0x14, 8
    or      r3, r6, r3
    stw     r3, 0xfc(r8)
    stb     r5, -0x8000(r4)
    lwz     r3, 0xf8(r8)
    stw     r3, -0x8000(r4)
    stb     r5, -0x8000(r4)
    lwz     r3, 0xfc(r8)
    stw     r3, -0x8000(r4)
    sth     r0, 2(r8)
    blr     
}

asm void fn_80038FD8(register void* p)
{
    nofralloc
    lwz     r8, -0x7de8(r2)
    lwz     r7, 0xf8(r8)
    lwz     r8, 0xfc(r8)
    rlwinm  r9, r7, 0x14, 0x15, 0x1f
    addi    r0, r9, -0x156
    stw     r0, 0(r3)
    clrlwi  r7, r7, 0x15
    addi    r3, r7, -0x156
    stw     r3, 0(r4)
    rlwinm  r0, r8, 0x14, 0x15, 0x1f
    subf    r3, r9, r0
    addi    r0, r3, 1
    clrlwi  r4, r8, 0x15
    stw     r0, 0(r5)
    subf    r3, r7, r4
    addi    r0, r3, 1
    stw     r0, 0(r6)
    blr     
}

asm void fn_80039020(register void* p)
{
    nofralloc
    addi    r5, r3, 0x156
    lwz     r3, -0x7de8(r2)
    addi    r0, r4, 0x156
    srwi    r4, r5, 1
    rlwinm  r4, r4, 0, 0x16, 0xb
    rlwinm  r0, r0, 9, 0, 0x15
    or      r0, r4, r0
    clrlwi  r5, r0, 8
    li      r0, 0x61
    lis     r4, -0x33ff
    stb     r0, -0x8000(r4)
    oris    r5, r5, 0x5900
    li      r0, 0
    stw     r5, -0x8000(r4)
    sth     r0, 2(r3)
    blr     
}

asm void fn_80039060(void)
{
    nofralloc
    li      r0, 0x10
    lwz     r4, -0x7de8(r2)
    lis     r6, -0x33ff
    stb     r0, -0x8000(r6)
    li      r5, 0x1005
    li      r0, 1
    stw     r5, -0x8000(r6)
    stw     r3, -0x8000(r6)
    sth     r0, 2(r4)
    blr     
}

asm void fn_80039088(register void* p)
{
    nofralloc
    cmpwi   r3, 5
    bge     _800390c8
    li      r0, 8
    lwz     r4, -0x7de8(r2)
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r0, 0x30
    li      r3, 0x10
    stb     r0, -0x8000(r5)
    li      r0, 0x1018
    lwz     r4, 0x80(r4)
    stw     r4, -0x8000(r5)
    stb     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    stw     r4, -0x8000(r5)
    b       _800390fc
_800390c8:
    li      r0, 8
    lwz     r4, -0x7de8(r2)
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r0, 0x40
    li      r3, 0x10
    stb     r0, -0x8000(r5)
    li      r0, 0x1019
    lwz     r4, 0x84(r4)
    stw     r4, -0x8000(r5)
    stb     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    stw     r4, -0x8000(r5)
_800390fc:
    lwz     r3, -0x7de8(r2)
    li      r0, 1
    sth     r0, 2(r3)
    blr     
}

asm void fn_8003910C(register u32 cmd)
{
    nofralloc
    lwz     r5, -0x7de8(r2)
    lwz     r0, 0x4e4(r5)
    cmpwi   r0, 0x22
    beq     _80039144
    bge     _80039190
    cmpwi   r0, 0xb
    bge     _80039134
    cmpwi   r0, 0
    bge     _80039144
    b       _80039190
_80039134:
    cmpwi   r0, 0x1b
    bge     _8003917c
    b       _80039164
    b       _80039190
_80039144:
    li      r0, 0x10
    lis     r6, -0x33ff
    stb     r0, -0x8000(r6)
    li      r5, 0x1006
    li      r0, 0
    stw     r5, -0x8000(r6)
    stw     r0, -0x8000(r6)
    b       _80039190
_80039164:
    li      r0, 0x61
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    lis     r0, 0x2300
    stw     r0, -0x8000(r5)
    b       _80039190
_8003917c:
    li      r0, 0x61
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    lis     r0, 0x2400
    stw     r0, -0x8000(r5)
_80039190:
    lwz     r7, -0x7de8(r2)
    lwz     r0, 0x4e8(r7)
    cmpwi   r0, 0x15
    beq     _800391c8
    bge     _80039218
    cmpwi   r0, 9
    bge     _800391b8
    cmpwi   r0, 0
    bge     _800391c8
    b       _80039218
_800391b8:
    cmpwi   r0, 0x11
    bge     _8003920c
    b       _800391e0
    b       _80039218
_800391c8:
    li      r0, 0x61
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    lis     r0, 0x6700
    stw     r0, -0x8000(r5)
    b       _80039218
_800391e0:
    lwz     r0, 0x4ec(r7)
    li      r6, 8
    lis     r5, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    stw     r0, 0x4ec(r7)
    li      r0, 0x20
    stb     r6, -0x8000(r5)
    stb     r0, -0x8000(r5)
    lwz     r0, 0x4ec(r7)
    stw     r0, -0x8000(r5)
    b       _80039218
_8003920c:
    lwz     r5, -0x77f4(r13)
    li      r0, 0
    sth     r0, 6(r5)
_80039218:
    lwz     r5, -0x7de8(r2)
    stw     r3, 0x4e4(r5)
    lwz     r0, 0x4e4(r5)
    cmplwi  r0, 0x23
    bgt     _80039644
    lis     r3, jumptable_8012B45C@ha
    addi    r3, r3, jumptable_8012B45C@l
    slwi    r0, r0, 2
    lwzx    r0, r3, r0
    mtctr   r0
    bctr    
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x273
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x14a
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x16b
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x84
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0xc6
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x210
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x252
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x231
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x1ad
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x1ce
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x21
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x10
    lis     r5, -0x33ff
    stb     r0, -0x8000(r5)
    li      r3, 0x1006
    li      r0, 0x153
    stw     r3, -0x8000(r5)
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5181
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x7181
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x6181
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2300
    stb     r0, -0x8000(r5)
    addi    r0, r3, 0x1e7f
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x53c1
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5381
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5341
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5301
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x52c1
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5281
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5241
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5201
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x51c1
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5d81
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5981
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2301
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x5581
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x3f3a
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x3e95
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x3f19
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x3ef8
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x3ed7
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x3eb6
    stw     r0, -0x8000(r5)
    b       _80039644
    li      r0, 0x61
    lis     r5, -0x33ff
    lis     r3, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r3, -0x3e53
    stw     r0, -0x8000(r5)
_80039644:
    lwz     r3, -0x7de8(r2)
    stw     r4, 0x4e8(r3)
    lwz     r0, 0x4e8(r3)
    cmplwi  r0, 0x16
    bgt     _80039944
    lis     r4, jumptable_8012B400@ha
    addi    r4, r4, jumptable_8012B400@l
    slwi    r0, r0, 2
    lwzx    r0, r4, r0
    mtctr   r0
    bctr    
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x42
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x84
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x63
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x129
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x252
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x21
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x14b
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x18d
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x1cf
    stw     r0, -0x8000(r4)
    b       _80039944
    li      r0, 0x61
    lis     r4, -0x33ff
    lis     r3, 0x6700
    stb     r0, -0x8000(r4)
    addi    r0, r3, 0x211
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x20
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x30
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x40
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x50
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x60
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x70
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x90
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r0, 0x4ec(r3)
    li      r5, 8
    lis     r4, -0x33ff
    rlwinm  r0, r0, 0, 0x1c, 0x17
    ori     r0, r0, 0x80
    stw     r0, 0x4ec(r3)
    li      r0, 0x20
    stb     r5, -0x8000(r4)
    stb     r0, -0x8000(r4)
    lwz     r0, 0x4ec(r3)
    stw     r0, -0x8000(r4)
    b       _80039944
    lwz     r3, -0x77f4(r13)
    li      r0, 2
    sth     r0, 6(r3)
    b       _80039944
    lwz     r3, -0x77f4(r13)
    li      r0, 3
    sth     r0, 6(r3)
    b       _80039944
    lwz     r3, -0x77f4(r13)
    li      r0, 4
    sth     r0, 6(r3)
    b       _80039944
    lwz     r3, -0x77f4(r13)
    li      r0, 5
    sth     r0, 6(r3)
_80039944:
    lwz     r3, -0x7de8(r2)
    li      r0, 0
    sth     r0, 2(r3)
    blr     
}

asm void fn_80039954(register void* p)
{
    nofralloc
    lwz     r10, -0x77f4(r13)
    addi    r8, r10, 0x42
    lhz     r6, 0x42(r10)
    addi    r7, r10, 0x40
_80039964:
    mr      r0, r6
    lhz     r5, 0(r7)
    lhz     r6, 0(r8)
    cmplw   r6, r0
    bne     _80039964
    slwi    r0, r6, 0x10
    or      r6, r0, r5
    addi    r9, r10, 0x46
    lhz     r7, 0x46(r10)
    addi    r8, r10, 0x44
_8003998c:
    mr      r0, r7
    lhz     r5, 0(r8)
    lhz     r7, 0(r9)
    cmplw   r7, r0
    bne     _8003998c
    slwi    r0, r7, 0x10
    or      r7, r0, r5
    addi    r11, r10, 0x4a
    lhz     r8, 0x4a(r10)
    addi    r9, r10, 0x48
_800399b4:
    mr      r0, r8
    lhz     r5, 0(r9)
    lhz     r8, 0(r11)
    cmplw   r8, r0
    bne     _800399b4
    slwi    r0, r8, 0x10
    or      r8, r0, r5
    addi    r11, r10, 0x4e
    lhz     r9, 0x4e(r10)
    addi    r10, r10, 0x4c
_800399dc:
    mr      r0, r9
    lhz     r5, 0(r10)
    lhz     r9, 0(r11)
    cmplw   r9, r0
    bne     _800399dc
    slwi    r0, r9, 0x10
    or      r9, r0, r5
    lwz     r5, -0x7de8(r2)
    lwz     r0, 0x4e4(r5)
    cmpwi   r0, 0xa
    beq     _80039a28
    bge     _80039a18
    cmpwi   r0, 0
    bge     _80039a38
    b       _80039a4c
_80039a18:
    cmpwi   r0, 0x23
    beq     _80039a40
    bge     _80039a4c
    b       _80039a38
_80039a28:
    mulli   r0, r7, 0x3e8
    divwu   r0, r0, r6
    stw     r0, 0(r3)
    b       _80039a54
_80039a38:
    stw     r6, 0(r3)
    b       _80039a54
_80039a40:
    li      r0, 0
    stw     r0, 0(r3)
    b       _80039a54
_80039a4c:
    li      r0, 0
    stw     r0, 0(r3)
_80039a54:
    lwz     r3, -0x7de8(r2)
    lwz     r0, 0x4e8(r3)
    cmplwi  r0, 0x16
    bgt     _80039af0
    lis     r3, jumptable_8012B4EC@ha
    addi    r3, r3, jumptable_8012B4EC@l
    slwi    r0, r0, 2
    lwzx    r0, r3, r0
    mtctr   r0
    bctr    
    slwi    r0, r9, 2
    stw     r0, 0(r4)
    blr     
    slwi    r0, r9, 1
    add     r0, r8, r0
    stw     r0, 0(r4)
    blr     
    mulli   r3, r8, 3
    slwi    r0, r9, 2
    add     r0, r3, r0
    stw     r0, 0(r4)
    blr     
    mulli   r3, r8, 5
    mulli   r0, r9, 6
    add     r0, r3, r0
    stw     r0, 0(r4)
    blr     
    mulli   r3, r8, 7
    slwi    r0, r9, 3
    add     r0, r3, r0
    stw     r0, 0(r4)
    blr     
    stw     r9, 0(r4)
    blr     
    stw     r8, 0(r4)
    blr     
    li      r0, 0
    stw     r0, 0(r4)
    blr     
_80039af0:
    li      r0, 0
    stw     r0, 0(r4)
    blr     
}

asm int fn_80039AFC(void)
{
    nofralloc
    lwz     r3, -0x77f4(r13)
    li      r0, 4
    sth     r0, 4(r3)
    blr     
}

asm void fn_80039B0C(register void* p)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    addi    r3, r1, 0xc
    addi    r4, r1, 8
    bl      fn_80039954
    lwz     r3, 8(r1)
    lwz     r0, 0x14(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr     
}

asm int fn_80039B38(register u32 a)
{
    nofralloc
    li      r0, 0x61
    lwz     r3, -0x7de8(r2)
    lis     r5, -0x33ff
    lis     r4, 0x2403
    stb     r0, -0x8000(r5)
    addi    r0, r4, -0x3fde
    stw     r0, -0x8000(r5)
    li      r0, 0x10
    lis     r4, 3
    stb     r0, -0x8000(r5)
    li      r0, 0x1006
    addi    r4, r4, 0x1000
    stw     r0, -0x8000(r5)
    li      r0, 1
    stw     r4, -0x8000(r5)
    sth     r0, 2(r3)
    blr     
}

asm void fn_80039B7C(register u32 a)
{
    nofralloc
    lwz     r7, -0x77f4(r13)
    addi    r10, r7, 0x42
    lhz     r8, 0x42(r7)
    addi    r9, r7, 0x40
_80039b8c:
    mr      r0, r8
    lhz     r7, 0(r9)
    lhz     r8, 0(r10)
    cmplw   r8, r0
    bne     _80039b8c
    slwi    r0, r8, 0x10
    or      r0, r0, r7
    stw     r0, 0(r5)
    lwz     r5, -0x77f4(r13)
    addi    r9, r5, 0x46
    lhz     r7, 0x46(r5)
    addi    r8, r5, 0x44
_80039bbc:
    mr      r0, r7
    lhz     r5, 0(r8)
    lhz     r7, 0(r9)
    cmplw   r7, r0
    bne     _80039bbc
    slwi    r0, r7, 0x10
    or      r0, r0, r5
    stw     r0, 0(r6)
    lwz     r5, -0x77f4(r13)
    addi    r8, r5, 0x4a
    lhz     r6, 0x4a(r5)
    addi    r7, r5, 0x48
_80039bec:
    mr      r0, r6
    lhz     r5, 0(r7)
    lhz     r6, 0(r8)
    cmplw   r6, r0
    bne     _80039bec
    slwi    r0, r6, 0x10
    or      r0, r0, r5
    stw     r0, 0(r3)
    lwz     r3, -0x77f4(r13)
    addi    r7, r3, 0x4e
    lhz     r5, 0x4e(r3)
    addi    r6, r3, 0x4c
_80039c1c:
    mr      r0, r5
    lhz     r3, 0(r6)
    lhz     r5, 0(r7)
    cmplw   r5, r0
    bne     _80039c1c
    slwi    r0, r5, 0x10
    or      r0, r0, r3
    stw     r0, 0(r4)
    blr     
}

asm int fn_80039C40(register u32 a, register u32 b)
{
    nofralloc
    lwz     r4, 0x400(r3)
    addi    r0, r4, 2
    stw     r0, 0x400(r3)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 1
    stw     r0, 0x400(r3)
    lbz     r0, 0(r4)
    cmplwi  r0, 8
    beq     _80039c6c
    li      r3, 4
    blr     
_80039c6c:
    lwz     r5, 0x400(r3)
    lbz     r4, 0(r5)
    lbz     r0, 1(r5)
    rlwimi  r0, r4, 8, 0x10, 0x17
    sth     r0, 0x40a(r3)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 2
    stw     r0, 0x400(r3)
    lwz     r5, 0x400(r3)
    lbz     r4, 0(r5)
    lbz     r0, 1(r5)
    rlwimi  r0, r4, 8, 0x10, 0x17
    sth     r0, 0x408(r3)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 2
    stw     r0, 0x400(r3)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 1
    stw     r0, 0x400(r3)
    lbz     r0, 0(r4)
    stb     r0, 0x41c(r3)
    lbz     r0, 0x41c(r3)
    cmplwi  r0, 3
    beq     _80039cdc
    cmplwi  r0, 1
    beq     _80039cdc
    li      r3, 6
    blr     
_80039cdc:
    addi    r5, r3, 0
    li      r6, 0
    b       _80039d38
_80039ce8:
    lwz     r4, 0x400(r3)
    addi    r6, r6, 1
    addi    r0, r4, 1
    stw     r0, 0x400(r3)
    lbz     r0, 0(r4)
    stb     r0, 0x6c0(r5)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 1
    stw     r0, 0x400(r3)
    lbz     r4, 0(r4)
    srawi   r0, r4, 4
    stb     r0, 0x6c1(r5)
    clrlwi  r0, r4, 0x1c
    stb     r0, 0x6c2(r5)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 1
    stw     r0, 0x400(r3)
    lbz     r0, 0(r4)
    stb     r0, 0x6c3(r5)
    addi    r5, r5, 0x30
_80039d38:
    lbz     r0, 0x41c(r3)
    clrlwi  r4, r6, 0x18
    cmplw   r4, r0
    blt     _80039ce8
    li      r0, 1
    stb     r0, 0x41a(r3)
    addi    r5, r3, 0
    li      r6, 0
    stb     r0, 0x41b(r3)
    b       _80039da4
_80039d60:
    lbz     r4, 0x41a(r3)
    addi    r7, r5, 0x6c0
    lbz     r0, 0x6c1(r5)
    cmplw   r4, r0
    ble     _80039d78
    b       _80039d7c
_80039d78:
    lbz     r4, 1(r7)
_80039d7c:
    stb     r4, 0x41a(r3)
    lbz     r0, 0x41b(r3)
    lbz     r4, 2(r7)
    cmplw   r0, r4
    ble     _80039d94
    b       _80039d98
_80039d94:
    mr      r0, r4
_80039d98:
    stb     r0, 0x41b(r3)
    addi    r5, r5, 0x30
    addi    r6, r6, 1
_80039da4:
    lbz     r0, 0x41c(r3)
    clrlwi  r4, r6, 0x18
    cmplw   r4, r0
    blt     _80039d60
    lbz     r0, 0x41b(r3)
    mr      r6, r3
    lhz     r8, 0x40a(r3)
    li      r4, 0
    slwi    r7, r0, 3
    add     r5, r7, r8
    addi    r0, r5, -1
    divw    r7, r0, r7
    add     r5, r7, r8
    addi    r0, r5, -1
    divw    r0, r0, r7
    sth     r0, 0x7a8(r3)
    b       _80039e30
_80039de8:
    lhz     r5, 0x408(r3)
    addi    r4, r4, 1
    lbz     r0, 0x6c1(r6)
    lbz     r7, 0x41a(r3)
    mullw   r0, r5, r0
    add     r5, r7, r0
    addi    r0, r5, -1
    divw    r0, r0, r7
    stw     r0, 0x6c8(r6)
    lhz     r5, 0x40a(r3)
    lbz     r0, 0x6c2(r6)
    lbz     r7, 0x41b(r3)
    mullw   r0, r5, r0
    add     r5, r7, r0
    addi    r0, r5, -1
    divw    r0, r0, r7
    stw     r0, 0x6cc(r6)
    addi    r6, r6, 0x30
_80039e30:
    lbz     r0, 0x41c(r3)
    clrlwi  r5, r4, 0x18
    cmplw   r5, r0
    blt     _80039de8
    li      r3, 0
    blr     
}

asm int fn_80039E48(register u32 a)
{
    nofralloc
    stwu    r1, -0x180(r1)
    lis     r4, lbl_8008FF50@ha
    addi    r5, r4, lbl_8008FF50@l
    stmw    r24, 0x160(r1)
    lwz     r7, 0x400(r3)
    lbz     r6, 0(r7)
    addi    r0, r7, 2
    lbz     r4, 1(r7)
    addi    r7, r5, 0x50
    rlwimi  r4, r6, 8, 0x10, 0x17
    stw     r0, 0x400(r3)
    clrlwi  r8, r4, 0x10
    addi    r4, r1, 0x18
    lfd     f0, -0x7cc8(r2)
    lis     r0, 0x4330
    addi    r8, r8, -2
_80039e88:
    lwz     r11, 0x400(r3)
    addi    r6, r5, 0
    li      r10, 0
    addi    r9, r11, 1
    stw     r9, 0x400(r3)
    lbz     r9, 0(r11)
    b       _8003a044
_80039ea4:
    lwz     r12, 0x400(r3)
    addi    r27, r10, 1
    addi    r28, r10, 2
    addi    r11, r12, 1
    stw     r11, 0x400(r3)
    addi    r29, r10, 3
    addi    r30, r10, 4
    lbz     r31, 0(r12)
    addi    r12, r10, 5
    lbz     r26, 0(r6)
    addi    r11, r10, 6
    stw     r31, 0x15c(r1)
    slwi    r26, r26, 2
    stw     r0, 0x158(r1)
    clrlwi  r27, r27, 0x10
    clrlwi  r28, r28, 0x10
    lfd     f1, 0x158(r1)
    clrlwi  r29, r29, 0x10
    clrlwi  r30, r30, 0x10
    fsubs   f1, f1, f0
    clrlwi  r12, r12, 0x10
    clrlwi  r11, r11, 0x10
    stfsx   f1, r4, r26
    lwz     r26, 0x400(r3)
    addi    r31, r26, 1
    stw     r31, 0x400(r3)
    lbz     r31, 0(r26)
    lbzx    r27, r5, r27
    stw     r31, 0x154(r1)
    slwi    r27, r27, 2
    stw     r0, 0x150(r1)
    lfd     f1, 0x150(r1)
    fsubs   f1, f1, f0
    stfsx   f1, r4, r27
    lwz     r27, 0x400(r3)
    addi    r31, r27, 1
    stw     r31, 0x400(r3)
    lbz     r31, 0(r27)
    lbzx    r28, r5, r28
    stw     r31, 0x14c(r1)
    slwi    r28, r28, 2
    stw     r0, 0x148(r1)
    lfd     f1, 0x148(r1)
    fsubs   f1, f1, f0
    stfsx   f1, r4, r28
    lwz     r28, 0x400(r3)
    addi    r31, r28, 1
    stw     r31, 0x400(r3)
    lbz     r31, 0(r28)
    lbzx    r29, r5, r29
    stw     r31, 0x144(r1)
    slwi    r29, r29, 2
    stw     r0, 0x140(r1)
    lfd     f1, 0x140(r1)
    fsubs   f1, f1, f0
    stfsx   f1, r4, r29
    lwz     r29, 0x400(r3)
    addi    r31, r29, 1
    stw     r31, 0x400(r3)
    lbz     r31, 0(r29)
    lbzx    r30, r5, r30
    stw     r31, 0x13c(r1)
    slwi    r30, r30, 2
    stw     r0, 0x138(r1)
    lfd     f1, 0x138(r1)
    fsubs   f1, f1, f0
    stfsx   f1, r4, r30
    lwz     r31, 0x400(r3)
    addi    r30, r31, 1
    stw     r30, 0x400(r3)
    lbz     r30, 0(r31)
    lbzx    r12, r5, r12
    stw     r30, 0x134(r1)
    slwi    r12, r12, 2
    stw     r0, 0x130(r1)
    lfd     f1, 0x130(r1)
    fsubs   f1, f1, f0
    stfsx   f1, r4, r12
    lwz     r30, 0x400(r3)
    addi    r12, r30, 1
    stw     r12, 0x400(r3)
    lbz     r12, 0(r30)
    lbzx    r11, r5, r11
    stw     r12, 0x12c(r1)
    slwi    r11, r11, 2
    stw     r0, 0x128(r1)
    lfd     f1, 0x128(r1)
    fsubs   f1, f1, f0
    stfsx   f1, r4, r11
    lwz     r30, 0x400(r3)
    addi    r11, r10, 7
    clrlwi  r11, r11, 0x10
    addi    r12, r30, 1
    stw     r12, 0x400(r3)
    addi    r6, r6, 8
    addi    r10, r10, 8
    lbz     r12, 0(r30)
    lbzx    r11, r5, r11
    stw     r12, 0x124(r1)
    slwi    r11, r11, 2
    stw     r0, 0x120(r1)
    lfd     f1, 0x120(r1)
    fsubs   f1, f1, f0
    stfsx   f1, r4, r11
_8003a044:
    clrlwi  r11, r10, 0x10
    cmplwi  r11, 0x40
    blt     _80039ea4
    li      r6, 1
    lbz     r10, 0x419(r3)
    slw     r6, r6, r9
    or      r10, r10, r6
    slwi    r6, r9, 8
    stb     r10, 0x419(r3)
    addi    r26, r7, 0
    add     r27, r3, r6
    li      r25, 0
    li      r24, 0
    b       _8003a1a4
_8003a07c:
    rlwinm  r28, r25, 2, 0xe, 0x1d
    lfd     f1, 0(r26)
    lfsx    f2, r4, r28
    addi    r30, r25, 1
    addi    r12, r25, 3
    lfd     f3, 0(r7)
    fmul    f1, f2, f1
    addi    r11, r25, 4
    addi    r10, r25, 5
    addi    r9, r25, 6
    fmul    f1, f3, f1
    addi    r6, r25, 7
    addi    r31, r25, 2
    rlwinm  r29, r30, 2, 0xe, 0x1d
    frsp    f1, f1
    rlwinm  r12, r12, 2, 0xe, 0x1d
    rlwinm  r11, r11, 2, 0xe, 0x1d
    stfsx   f1, r27, r28
    rlwinm  r28, r31, 2, 0xe, 0x1d
    rlwinm  r10, r10, 2, 0xe, 0x1d
    lfsx    f2, r4, r29
    rlwinm  r9, r9, 2, 0xe, 0x1d
    lfd     f1, 0(r26)
    rlwinm  r6, r6, 2, 0xe, 0x1d
    lfd     f3, 8(r7)
    fmul    f1, f2, f1
    addi    r25, r25, 8
    addi    r24, r24, 1
    fmul    f1, f3, f1
    frsp    f1, f1
    stfsx   f1, r27, r29
    lfsx    f2, r4, r28
    lfd     f1, 0(r26)
    lfd     f3, 0x10(r7)
    fmul    f1, f2, f1
    fmul    f1, f3, f1
    frsp    f1, f1
    stfsx   f1, r27, r28
    lfsx    f2, r4, r12
    lfd     f1, 0(r26)
    lfd     f3, 0x18(r7)
    fmul    f1, f2, f1
    fmul    f1, f3, f1
    frsp    f1, f1
    stfsx   f1, r27, r12
    lfsx    f2, r4, r11
    lfd     f1, 0(r26)
    lfd     f3, 0x20(r7)
    fmul    f1, f2, f1
    fmul    f1, f3, f1
    frsp    f1, f1
    stfsx   f1, r27, r11
    lfsx    f2, r4, r10
    lfd     f1, 0(r26)
    lfd     f3, 0x28(r7)
    fmul    f1, f2, f1
    fmul    f1, f3, f1
    frsp    f1, f1
    stfsx   f1, r27, r10
    lfsx    f2, r4, r9
    lfd     f1, 0(r26)
    lfd     f3, 0x30(r7)
    fmul    f1, f2, f1
    fmul    f1, f3, f1
    frsp    f1, f1
    stfsx   f1, r27, r9
    lfd     f1, 0(r26)
    addi    r26, r26, 8
    lfsx    f2, r4, r6
    lfd     f3, 0x38(r7)
    fmul    f1, f2, f1
    fmul    f1, f3, f1
    frsp    f1, f1
    stfsx   f1, r27, r6
_8003a1a4:
    clrlwi  r6, r24, 0x10
    cmplwi  r6, 8
    blt     _8003a07c
    addi    r8, r8, -0x41
    clrlwi. r6, r8, 0x10
    bne     _80039e88
    li      r3, 0
    lmw     r24, 0x160(r1)
    addi    r1, r1, 0x180
    blr     
}

asm void fn_8003A1CC(register void* p)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    mr      r29, r3
    stw     r28, 0x10(r1)
    lwz     r3, 0x400(r3)
    lbz     r4, 0(r3)
    addi    r0, r3, 2
    lbz     r3, 1(r3)
    rlwimi  r3, r4, 8, 0x10, 0x17
    clrlwi  r30, r3, 0x10
    stw     r0, 0x400(r29)
    addi    r30, r30, -2
_8003a20c:
    lwz     r3, 0x400(r29)
    addi    r0, r3, 1
    stw     r0, 0x400(r29)
    lbz     r4, 0(r3)
    lwz     r5, 0x400(r29)
    srawi   r0, r4, 4
    clrlwi  r3, r0, 0x18
    cmplwi  r3, 1
    clrlwi  r0, r4, 0x1c
    bgt     _8003a23c
    cmplwi  r0, 2
    blt     _8003a244
_8003a23c:
    li      r3, 7
    b       _8003a3b4
_8003a244:
    slwi    r0, r0, 1
    add     r31, r0, r3
    li      r0, 0
    li      r3, 0
    b       _8003a2fc
_8003a258:
    lwz     r7, 0x400(r29)
    addi    r3, r3, 8
    addi    r4, r7, 1
    stw     r4, 0x400(r29)
    lwz     r6, 0x400(r29)
    lbz     r7, 0(r7)
    addi    r4, r6, 1
    stw     r4, 0x400(r29)
    add     r0, r0, r7
    lwz     r7, 0x400(r29)
    lbz     r6, 0(r6)
    addi    r4, r7, 1
    stw     r4, 0x400(r29)
    add     r0, r0, r6
    lwz     r6, 0x400(r29)
    lbz     r7, 0(r7)
    addi    r4, r6, 1
    stw     r4, 0x400(r29)
    add     r0, r0, r7
    lwz     r7, 0x400(r29)
    lbz     r6, 0(r6)
    addi    r4, r7, 1
    stw     r4, 0x400(r29)
    add     r0, r0, r6
    lwz     r6, 0x400(r29)
    lbz     r7, 0(r7)
    addi    r4, r6, 1
    stw     r4, 0x400(r29)
    add     r0, r0, r7
    lwz     r7, 0x400(r29)
    lbz     r6, 0(r6)
    addi    r4, r7, 1
    stw     r4, 0x400(r29)
    add     r0, r0, r6
    lwz     r6, 0x400(r29)
    lbz     r7, 0(r7)
    addi    r4, r6, 1
    stw     r4, 0x400(r29)
    add     r0, r0, r7
    lbz     r4, 0(r6)
    add     r0, r0, r4
_8003a2fc:
    clrlwi  r4, r3, 0x18
    cmplwi  r4, 0x10
    blt     _8003a258
    clrlwi  r3, r31, 0x18
    mulli   r3, r3, 0xa8
    add     r4, r29, r3
    stw     r5, 0x420(r4)
    clrlwi  r28, r0, 0x10
    li      r6, 0
    lwz     r3, 0x400(r29)
    stw     r3, 0x430(r4)
    sth     r0, 0x42c(r4)
    b       _8003a340
_8003a330:
    lwz     r3, 0x400(r29)
    addi    r6, r6, 1
    addi    r0, r3, 1
    stw     r0, 0x400(r29)
_8003a340:
    clrlwi  r0, r6, 0x18
    cmpw    r0, r28
    blt     _8003a330
    addi    r3, r29, 0
    addi    r4, r31, 0
    bl      fn_8003A4E8
    clrlwi. r0, r3, 0x18
    beq     _8003a364
    b       _8003a3b4
_8003a364:
    addi    r3, r29, 0
    addi    r4, r31, 0
    bl      fn_8003A680
    clrlwi. r0, r3, 0x18
    beq     _8003a37c
    b       _8003a3b4
_8003a37c:
    addi    r3, r29, 0
    addi    r4, r31, 0
    bl      fn_8003A760
    addi    r0, r28, 0x11
    lbz     r5, 0x418(r29)
    subf    r30, r0, r30
    clrlwi  r3, r31, 0x18
    li      r4, 1
    slw     r3, r4, r3
    or      r3, r5, r3
    clrlwi. r0, r30, 0x10
    stb     r3, 0x418(r29)
    bne     _8003a20c
    li      r3, 0
_8003a3b4:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr     
}

asm int fn_8003A3D4(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -8(r1)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 2
    stw     r0, 0x400(r3)
    lwz     r4, 0x400(r3)
    addi    r0, r4, 1
    stw     r0, 0x400(r3)
    lbz     r0, 0(r4)
    lbz     r4, 0x41c(r3)
    cmplw   r0, r4
    beq     _8003a410
    li      r3, 6
    b       _8003a4d8
_8003a410:
    addi    r9, r3, 0
    li      r4, 0
    b       _8003a4bc
_8003a41c:
    lwz     r5, 0x400(r3)
    li      r6, 1
    addi    r5, r5, 1
    stw     r5, 0x400(r3)
    lwz     r7, 0x400(r3)
    addi    r5, r7, 1
    stw     r5, 0x400(r3)
    lbz     r7, 0(r7)
    srawi   r5, r7, 4
    stb     r5, 0x6c4(r9)
    clrlwi  r7, r7, 0x1c
    slw     r5, r6, r5
    stb     r7, 0x6c5(r9)
    lbz     r8, 0x418(r3)
    and.    r5, r8, r5
    bne     _8003a464
    li      r3, 9
    b       _8003a4d8
_8003a464:
    addi    r5, r7, 1
    slw     r5, r6, r5
    and.    r5, r8, r5
    bne     _8003a47c
    li      r3, 9
    b       _8003a4d8
_8003a47c:
    lbz     r6, 0x6c2(r9)
    li      r7, 0x10
    lbz     r5, 0x41b(r3)
    addi    r4, r4, 1
    lwz     r8, 0x6c8(r9)
    subf    r6, r6, r5
    lwz     r5, 0x7b4(r3)
    sraw    r6, r7, r6
    stw     r5, 0x6d0(r9)
    clrlwi  r5, r6, 0x10
    clrlwi  r7, r8, 0x10
    mullw   r5, r7, r5
    lwz     r6, 0x7b4(r3)
    add     r5, r6, r5
    stw     r5, 0x7b4(r3)
    addi    r9, r9, 0x30
_8003a4bc:
    clrlwi  r5, r4, 0x18
    cmplw   r5, r0
    blt     _8003a41c
    lwz     r4, 0x400(r3)
    addi    r0, r4, 3
    stw     r0, 0x400(r3)
    bl      fn_8003A91C
_8003a4d8:
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr     
}

asm int fn_8003A4E8(register u32 a)
{
    nofralloc
    stwu    r1, -0x28(r1)
    li      r0, 1
    cmpwi   r0, 0x10
    stw     r31, 0x24(r1)
    li      r31, 0
    bgt     _8003a57c
    lbz     r7, 0(r5)
    lbz     r0, 1(r5)
    lbz     r6, 2(r5)
    add     r31, r7, r0
    lbz     r0, 3(r5)
    add     r31, r31, r6
    lbz     r6, 4(r5)
    add     r31, r31, r0
    lbz     r0, 5(r5)
    add     r31, r31, r6
    lbz     r6, 6(r5)
    add     r31, r31, r0
    lbz     r0, 7(r5)
    add     r31, r31, r6
    lbz     r7, 8(r5)
    add     r31, r31, r0
    lbz     r0, 9(r5)
    add     r31, r31, r7
    lbz     r6, 0xa(r5)
    add     r31, r31, r0
    lbz     r0, 0xb(r5)
    add     r31, r31, r6
    lbz     r6, 0xc(r5)
    add     r31, r31, r0
    lbz     r0, 0xd(r5)
    add     r31, r31, r6
    lbz     r6, 0xe(r5)
    add     r31, r31, r0
    lbz     r0, 0xf(r5)
    add     r31, r31, r6
    add     r31, r31, r0
_8003a57c:
    clrlwi  r0, r4, 0x18
    lwz     r4, 0x7b4(r3)
    mulli   r9, r0, 0xa8
    add     r10, r3, r9
    stwu    r4, 0x424(r10)
    add     r8, r3, r9
    lwz     r0, 0x7b4(r3)
    li      r11, 0
    li      r12, 1
    add     r4, r31, r0
    addi    r0, r4, 1
    stw     r0, 0x7b4(r3)
_8003a5ac:
    addi    r0, r12, -1
    lbzx    r31, r5, r0
    extsb   r7, r12
    cmpwi   r31, 0
    addi    r4, r31, 0
    beq     _8003a650
    rlwinm. r0, r4, 0x1d, 3, 0x1f
    mtctr   r0
    beq     _8003a63c
_8003a5d0:
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    bdnz    _8003a5d0
    andi.   r4, r4, 7
    beq     _8003a650
_8003a63c:
    mtctr   r4
_8003a640:
    lwz     r6, 0x424(r8)
    stbx    r7, r6, r11
    addi    r11, r11, 1
    bdnz    _8003a640
_8003a650:
    addi    r12, r12, 1
    cmpwi   r12, 0x10
    ble     _8003a5ac
    lwz     r5, 0(r10)
    li      r0, 0
    add     r4, r3, r9
    stbx    r0, r5, r11
    li      r3, 0
    stw     r11, 0x4c4(r4)
    lwz     r31, 0x24(r1)
    addi    r1, r1, 0x28
    blr     
}

asm void fn_8003A680(void)
{
    nofralloc
    clrlwi  r0, r4, 0x18
    mulli   r6, r0, 0xa8
    add     r8, r3, r6
    lwzu    r4, 0x424(r8)
    add     r7, r3, r6
    lbz     r9, 0(r4)
    li      r10, 0
    lwz     r5, 0x424(r7)
    extsb   r9, r9
    b       _8003a6d4
_8003a6a8:
    lwz     r0, 0x424(r7)
    add     r4, r0, r10
    b       _8003a6c0
_8003a6b4:
    addi    r4, r4, 1
    addi    r5, r5, 1
    addi    r10, r10, 1
_8003a6c0:
    lbz     r0, 0(r4)
    extsb   r0, r0
    cmpw    r9, r0
    beq     _8003a6b4
    addi    r9, r9, 1
_8003a6d4:
    lbz     r0, 0(r5)
    extsb.  r0, r0
    bne     _8003a6a8
    lwz     r5, 0x7b4(r3)
    add     r4, r3, r6
    slwi    r0, r10, 2
    stw     r5, 0x428(r4)
    li      r5, 0
    li      r6, 0
    lwz     r4, 0x7b4(r3)
    add     r0, r4, r0
    stw     r0, 0x7b4(r3)
    lwz     r3, 0(r8)
    lbz     r4, 0(r3)
    extsb   r4, r4
    b       _8003a748
    b       _8003a72c
_8003a718:
    lwz     r3, 0x428(r7)
    slwi    r0, r5, 2
    addi    r5, r5, 1
    stwx    r6, r3, r0
    addi    r6, r6, 1
_8003a72c:
    lwz     r3, 0x424(r7)
    lbzx    r0, r3, r5
    extsb   r0, r0
    cmpw    r4, r0
    beq     _8003a718
    slwi    r6, r6, 1
    addi    r4, r4, 1
_8003a748:
    lwz     r3, 0x424(r7)
    lbzx    r0, r3, r5
    extsb.  r0, r0
    bne     _8003a72c
    li      r3, 0
    blr     
}

asm int fn_8003A760(register u32 a)
{
    nofralloc
    clrlwi  r0, r4, 0x18
    mulli   r4, r0, 0xa8
    addi    r7, r4, 0x420
    li      r0, 4
    add     r7, r3, r7
    mtctr   r0
    addi    r6, r7, 4
    li      r8, 0
    li      r9, 1
_8003a784:
    lwz     r3, 0(r7)
    addi    r5, r9, -1
    lbzx    r0, r3, r5
    cmplwi  r0, 0
    beq     _8003a7d0
    lwz     r3, 8(r7)
    slwi    r0, r8, 2
    lwzx    r0, r3, r0
    subf    r0, r0, r8
    stw     r0, 0x5c(r6)
    lwz     r3, 0(r7)
    lwz     r4, 8(r7)
    lbzx    r0, r3, r5
    add     r8, r8, r0
    slwi    r3, r8, 2
    addi    r0, r3, -4
    lwzx    r0, r4, r0
    stw     r0, 0x14(r6)
    b       _8003a7dc
_8003a7d0:
    li      r0, -1
    stw     r0, 0x14(r6)
    stw     r0, 0x5c(r6)
_8003a7dc:
    lwz     r3, 0(r7)
    addi    r5, r9, 0
    addi    r9, r9, 1
    lbzx    r0, r3, r5
    addi    r6, r6, 4
    cmplwi  r0, 0
    beq     _8003a830
    lwz     r3, 8(r7)
    slwi    r0, r8, 2
    lwzx    r0, r3, r0
    subf    r0, r0, r8
    stw     r0, 0x5c(r6)
    lwz     r3, 0(r7)
    lwz     r4, 8(r7)
    lbzx    r0, r3, r5
    add     r8, r8, r0
    slwi    r3, r8, 2
    addi    r0, r3, -4
    lwzx    r0, r4, r0
    stw     r0, 0x14(r6)
    b       _8003a83c
_8003a830:
    li      r0, -1
    stw     r0, 0x14(r6)
    stw     r0, 0x5c(r6)
_8003a83c:
    lwz     r3, 0(r7)
    addi    r5, r9, 0
    addi    r9, r9, 1
    lbzx    r0, r3, r5
    addi    r6, r6, 4
    cmplwi  r0, 0
    beq     _8003a890
    lwz     r3, 8(r7)
    slwi    r0, r8, 2
    lwzx    r0, r3, r0
    subf    r0, r0, r8
    stw     r0, 0x5c(r6)
    lwz     r3, 0(r7)
    lwz     r4, 8(r7)
    lbzx    r0, r3, r5
    add     r8, r8, r0
    slwi    r3, r8, 2
    addi    r0, r3, -4
    lwzx    r0, r4, r0
    stw     r0, 0x14(r6)
    b       _8003a89c
_8003a890:
    li      r0, -1
    stw     r0, 0x14(r6)
    stw     r0, 0x5c(r6)
_8003a89c:
    lwz     r3, 0(r7)
    addi    r5, r9, 0
    addi    r9, r9, 1
    lbzx    r0, r3, r5
    addi    r6, r6, 4
    cmplwi  r0, 0
    beq     _8003a8f0
    lwz     r3, 8(r7)
    slwi    r0, r8, 2
    lwzx    r0, r3, r0
    subf    r0, r0, r8
    stw     r0, 0x5c(r6)
    lwz     r3, 0(r7)
    lwz     r4, 8(r7)
    lbzx    r0, r3, r5
    add     r8, r8, r0
    slwi    r3, r8, 2
    addi    r0, r3, -4
    lwzx    r0, r4, r0
    stw     r0, 0x14(r6)
    b       _8003a8fc
_8003a8f0:
    li      r0, -1
    stw     r0, 0x14(r6)
    stw     r0, 0x5c(r6)
_8003a8fc:
    addi    r6, r6, 4
    addi    r9, r9, 1
    bdnz    _8003a784
    lis     r3, 0x10
    addi    r0, r3, -1
    stw     r0, 0x58(r7)
    li      r3, 0
    blr     
}

asm int fn_8003A91C(register u32 a)
{
    nofralloc
    lbz     r6, 0x41a(r3)
    li      r0, 0
    lhz     r5, 0x408(r3)
    addi    r4, r3, 0
    slwi    r6, r6, 3
    add     r5, r6, r5
    addi    r5, r5, -1
    divw    r5, r5, r6
    sth     r5, 0x7a0(r3)
    li      r5, 0
    lbz     r7, 0x41b(r3)
    lhz     r6, 0x40a(r3)
    slwi    r7, r7, 3
    add     r6, r7, r6
    addi    r6, r6, -1
    divw    r6, r6, r7
    sth     r6, 0x7a4(r3)
    sth     r0, 0x7a2(r3)
    b       _8003aaf4
_8003a968:
    addi    r6, r4, 0x6c0
    lbz     r8, 0x41a(r3)
    lhz     r7, 0x408(r3)
    lbz     r0, 0x6c1(r4)
    slwi    r8, r8, 3
    mullw   r0, r7, r0
    add     r7, r8, r0
    addi    r0, r7, -1
    divw    r0, r0, r8
    stw     r0, 0x6ec(r4)
    lhz     r7, 0x40a(r3)
    lbz     r0, 0x6c2(r4)
    lbz     r8, 0x41b(r3)
    mullw   r0, r7, r0
    slwi    r8, r8, 3
    add     r7, r8, r0
    addi    r0, r7, -1
    divw    r0, r0, r8
    stw     r0, 0x6e8(r4)
    lbz     r0, 0x6c1(r4)
    stw     r0, 0x6d8(r4)
    lbz     r0, 0x6c2(r4)
    stw     r0, 0x6dc(r4)
    lwz     r7, 0x6d8(r4)
    lwz     r0, 0x6dc(r4)
    mullw   r0, r7, r0
    stw     r0, 0x6e0(r4)
    lwz     r0, 0x6d8(r4)
    slwi    r0, r0, 3
    stw     r0, 0x6e4(r4)
    lwz     r7, 0x6e0(r4)
    lhz     r0, 0x7a2(r3)
    addi    r10, r7, 0
    add     r0, r0, r7
    cmpwi   r0, 0x10
    ble     _8003aa00
    li      r3, 0xb
    blr     
_8003aa00:
    cmpwi   r10, 0
    addi    r7, r10, 0
    clrlwi  r9, r5, 0x18
    ble     _8003aae4
    rlwinm. r0, r7, 0x1d, 3, 0x1f
    mtctr   r0
    beq     _8003aac8
_8003aa1c:
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    bdnz    _8003aa1c
    andi.   r7, r7, 7
    beq     _8003aae4
_8003aac8:
    mtctr   r7
_8003aacc:
    lhz     r8, 0x7a2(r3)
    addi    r0, r8, 1
    sth     r0, 0x7a2(r3)
    addi    r0, r8, 0x790
    stbx    r9, r3, r0
    bdnz    _8003aacc
_8003aae4:
    li      r0, 0
    sth     r0, 6(r6)
    addi    r4, r4, 0x30
    addi    r5, r5, 1
_8003aaf4:
    lbz     r0, 0x41c(r3)
    cmplw   r5, r0
    blt     _8003a968
    li      r3, 0
    blr     
}

asm int fn_8003AB08(register u32 a)
{
    nofralloc
    mflr    r0
    lis     r4, -0x7fe8
    stw     r0, 4(r1)
    stwu    r1, -0x58(r1)
    stfd    f31, 0x50(r1)
    stfd    f30, 0x48(r1)
    stfd    f29, 0x40(r1)
    stfd    f28, 0x38(r1)
    stfd    f27, 0x30(r1)
    stmw    r25, 0x14(r1)
    addi    r31, r4, -0x7740
    mr      r29, r3
    li      r30, 0
    lfs     f27, -0x7cc0(r2)
    lfs     f28, -0x7cbc(r2)
    lfs     f29, -0x7cb8(r2)
    lfs     f30, -0x7cb4(r2)
    lfs     f31, -0x7cb0(r2)
    b       _8003af9c
_8003ab54:
    li      r26, 0
    b       _8003ab80
_8003ab5c:
    clrlwi  r3, r26, 0x18
    rlwinm  r0, r26, 2, 0x16, 0x1d
    add     r4, r29, r3
    add     r3, r29, r0
    lbz     r4, 0x790(r4)
    lwz     r5, 0x750(r3)
    mr      r3, r29
    bl      fn_8003B63C
    addi    r26, r26, 1
_8003ab80:
    lhz     r0, 0x7a2(r29)
    clrlwi  r3, r26, 0x18
    cmpw    r3, r0
    blt     _8003ab5c
    clrlwi  r0, r30, 0x18
    li      r4, 0
    li      r3, 0
    b       _8003af24
_8003aba0:
    clrlwi  r6, r3, 0x18
    lbz     r5, 0x41b(r29)
    mulli   r6, r6, 0x30
    lhz     r8, 0x7aa(r29)
    addi    r9, r6, 0x6c0
    add     r9, r29, r9
    lbz     r7, 2(r9)
    add     r12, r29, r6
    li      r6, 0
    subf    r5, r7, r5
    sraw    r8, r8, r5
    b       _8003af10
_8003abd0:
    lwz     r7, 0x24(r9)
    clrlwi  r27, r4, 0x18
    li      r5, 0
    mullw   r7, r0, r7
    b       _8003aef0
_8003abe4:
    clrlwi  r10, r5, 0x18
    lbz     r11, 0x6c3(r12)
    add     r10, r27, r10
    slwi    r10, r10, 2
    add     r28, r29, r10
    li      r10, 8
    lwz     r25, 0x750(r28)
    slwi    r11, r11, 8
    mtctr   r10
    add     r28, r29, r11
    addi    r11, r31, -8
_8003ac10:
    lwz     r10, 0xc(r25)
    cmpwi   r10, 0
    bne     _8003ad48
    lwz     r10, 8(r25)
    cmpwi   r10, 0
    bne     _8003ad48
    lwz     r10, 4(r25)
    cmpwi   r10, 0
    bne     _8003acc4
    lhz     r10, 2(r25)
    cmpwi   r10, 0
    bne     _8003ac68
    psq_l   f9, 0x0(r25), 1, 5
    lfs     f8, 0(r28)
    addi    r25, r25, 0x10
            ps_muls0 f9, f8, f9
    addi    r28, r28, 0x20
    psq_stu f9, 0x8(r11), 0, 0
    psq_stu f9, 0x8(r11), 0, 0
    psq_stu f9, 0x8(r11), 0, 0
    psq_stu f9, 0x8(r11), 0, 0
    b       _8003adf8
_8003ac68:
    psq_l   f9, 0x0(r25), 0, 5
    psq_l   f1, 0x0(r28), 0, 0
            ps_sub f8, f28, f29
            ps_mul f9, f9, f1
    addi    r25, r25, 0x10
            ps_msub f7, f9, f28, f9
            ps_merge00 f0, f9, f9
            ps_msub f6, f9, f27, f7
            ps_merge11 f4, f9, f7
            ps_nmsub f5, f9, f8, f6
            ps_add f2, f0, f4
            ps_sub f4, f0, f4
            ps_merge11 f3, f6, f5
    psq_stu f2, 0x8(r11), 0, 0
            ps_add f1, f0, f3
            ps_sub f3, f0, f3
    psq_stu f1, 0x8(r11), 0, 0
            ps_merge10 f3, f3, f3
            ps_merge10 f4, f4, f4
    psq_stu f3, 0x8(r11), 0, 0
    addi    r28, r28, 0x20
    psq_stu f4, 0x8(r11), 0, 0
    b       _8003adf8
_8003acc4:
    psq_l   f9, 0x0(r25), 0, 5
    psq_l   f1, 0x0(r28), 0, 0
            ps_mul f9, f9, f1
    psq_l   f8, 0x4(r25), 0, 5
    psq_l   f0, 0x8(r28), 0, 0
            ps_mul f8, f8, f0
    addi    r25, r25, 0x10
            ps_sub f6, f9, f8
            ps_add f7, f9, f8
            ps_madd f5, f8, f27, f6
            ps_nmsub f4, f8, f27, f7
            ps_mul f1, f6, f28
            ps_merge00 f5, f7, f5
            ps_nmsub f3, f8, f30, f1
            ps_merge00 f4, f4, f6
            ps_sub f3, f3, f7
            ps_nmsub f2, f9, f29, f1
            ps_merge11 f7, f7, f3
            ps_msub f1, f6, f27, f3
            ps_add f0, f5, f7
            ps_sub f2, f2, f1
    psq_stu f0, 0x8(r11), 0, 0
            ps_merge11 f6, f1, f2
            ps_sub f5, f5, f7
            ps_add f9, f4, f6
            ps_sub f8, f4, f6
    psq_stu f9, 0x8(r11), 0, 0
            ps_merge10 f8, f8, f8
            ps_merge10 f5, f5, f5
    psq_stu f8, 0x8(r11), 0, 0
    addi    r28, r28, 0x20
    psq_stu f5, 0x8(r11), 0, 0
    b       _8003adf8
_8003ad48:
    psq_l   f1, 0x0(r25), 0, 5
    psq_l   f5, 0x0(r28), 0, 0
            ps_mul f1, f1, f5
    psq_l   f0, 0x4(r25), 0, 5
    psq_l   f4, 0x8(r28), 0, 0
            ps_mul f0, f0, f4
    psq_l   f7, 0x8(r25), 0, 5
    psq_l   f3, 0x10(r28), 0, 0
            ps_merge01 f9, f1, f0
    psq_l   f6, 0xc(r25), 0, 5
            ps_merge01 f8, f0, f1
    psq_l   f2, 0x18(r28), 0, 0
            ps_madd f5, f7, f3, f9
            ps_nmsub f4, f7, f3, f9
            ps_madd f3, f6, f2, f8
            ps_nmsub f2, f6, f2, f8
            ps_add f9, f5, f3
            ps_sub f6, f5, f3
            ps_msub f7, f2, f27, f3
            ps_sub f1, f2, f4
            ps_add f8, f4, f7
            ps_sub f7, f4, f7
            ps_mul f1, f1, f28
            ps_merge00 f8, f9, f8
            ps_nmsub f3, f4, f30, f1
            ps_msub f5, f2, f29, f1
            ps_merge00 f7, f7, f6
            ps_sub f3, f3, f9
    addi    r25, r25, 0x10
            ps_madd f4, f6, f27, f3
            ps_merge11 f2, f9, f3
            ps_sub f5, f5, f4
            ps_add f6, f8, f2
            ps_merge11 f5, f4, f5
            ps_sub f9, f8, f2
    psq_stu f6, 0x8(r11), 0, 0
            ps_add f4, f7, f5
            ps_sub f3, f7, f5
            ps_merge10 f4, f4, f4
    psq_stu f3, 0x8(r11), 0, 0
            ps_merge10 f9, f9, f9
    psq_stu f4, 0x8(r11), 0, 0
    addi    r28, r28, 0x20
    psq_stu f9, 0x8(r11), 0, 0
_8003adf8:
    bdnz    _8003ac10
    lwz     r28, 0x6c8(r12)
    li      r10, 4
    mtctr   r10
    lwz     r26, 0x6d4(r12)
    mullw   r10, r8, r28
    addi    r11, r31, 0
    add     r10, r7, r10
_8003ae18:
    psq_l   f9, 0x0(r11), 0, 0
    psq_l   f8, 0x80(r11), 0, 0
    add     r25, r26, r10
            ps_add f3, f9, f8
    psq_l   f7, 0x40(r11), 0, 0
            ps_sub f1, f9, f8
            ps_add f3, f3, f31
    psq_l   f6, 0xc0(r11), 0, 0
            ps_add f2, f7, f6
            ps_sub f0, f7, f6
    psq_l   f5, 0x20(r11), 0, 0
            ps_add f9, f3, f2
            ps_add f1, f1, f31
    psq_l   f4, 0x60(r11), 0, 0
            ps_msub f0, f0, f27, f2
            ps_sub f6, f3, f2
    psq_l   f3, 0xa0(r11), 0, 0
            ps_add f8, f1, f0
    psq_l   f2, 0xe0(r11), 0, 0
            ps_sub f7, f1, f0
            ps_add f1, f3, f4
            ps_sub f3, f3, f4
            ps_add f0, f5, f2
            ps_sub f5, f5, f2
            ps_add f2, f0, f1
            ps_sub f4, f0, f1
            ps_add f1, f3, f5
            ps_add f0, f9, f2
            ps_mul f1, f1, f28
            ps_sub f9, f9, f2
            ps_madd f3, f3, f30, f1
    psq_st  f0, 0x0(r25), 0, 6
            ps_sub f3, f3, f2
            ps_msub f5, f5, f29, f1
            ps_add f0, f8, f3
            ps_msub f4, f4, f27, f3
            ps_sub f8, f8, f3
            psq_stux f0, r25, r28, 0, 6
            ps_add f1, f7, f4
            ps_add f5, f5, f4
            psq_stux f1, r25, r28, 0, 6
            ps_sub f0, f6, f5
            ps_add f6, f6, f5
            psq_stux f0, r25, r28, 0, 6
            ps_sub f1, f7, f4
            psq_stux f6, r25, r28, 0, 6
    addi    r11, r11, 8
            psq_stux f1, r25, r28, 0, 6
    addi    r10, r10, 2
            psq_stux f8, r25, r28, 0, 6
            psq_stux f9, r25, r28, 0, 6
    bdnz    _8003ae18
    addi    r7, r7, 8
    addi    r5, r5, 1
_8003aef0:
    lwz     r10, 0x18(r9)
    clrlwi  r11, r5, 0x18
    cmpw    r11, r10
    blt     _8003abe4
    clrlwi  r5, r10, 0x18
    add     r4, r4, r5
    addi    r6, r6, 1
    addi    r8, r8, 8
_8003af10:
    lwz     r5, 0x1c(r9)
    clrlwi  r7, r6, 0x18
    cmpw    r7, r5
    blt     _8003abd0
    addi    r3, r3, 1
_8003af24:
    lbz     r5, 0x41c(r29)
    clrlwi  r6, r3, 0x18
    cmplw   r6, r5
    blt     _8003aba0
    lbz     r0, 0x41e(r29)
    cmplwi  r0, 0
    beq     _8003af98
    lhz     r3, 0x7b0(r29)
    addi    r0, r3, -1
    sth     r0, 0x7b0(r29)
    lhz     r0, 0x7b0(r29)
    cmplwi  r0, 0
    bne     _8003af98
    lhz     r4, 0x7ae(r29)
    li      r0, 0x21
    li      r3, 0
    sth     r4, 0x7b0(r29)
    li      r5, 0
    stw     r0, 0x414(r29)
    b       _8003af88
_8003af74:
    clrlwi  r0, r3, 0x18
    mulli   r0, r0, 0x30
    add     r4, r29, r0
    sth     r5, 0x6c6(r4)
    addi    r3, r3, 1
_8003af88:
    lbz     r0, 0x41c(r29)
    clrlwi  r4, r3, 0x18
    cmplw   r4, r0
    blt     _8003af74
_8003af98:
    addi    r30, r30, 1
_8003af9c:
    lhz     r0, 0x7a0(r29)
    clrlwi  r3, r30, 0x18
    cmpw    r3, r0
    blt     _8003ab54
    lhz     r3, 0x7a6(r29)
    addi    r0, r3, 1
    sth     r0, 0x7a6(r29)
    lhz     r3, 0x7aa(r29)
    lhz     r0, 0x7a8(r29)
    add     r0, r3, r0
    sth     r0, 0x7aa(r29)
    lhz     r3, 0x7a6(r29)
    lhz     r0, 0x7a4(r29)
    cmplw   r3, r0
    bge     _8003afe0
    li      r0, 0
    b       _8003afe4
_8003afe0:
    li      r0, 1
_8003afe4:
    lmw     r25, 0x14(r1)
    clrlwi  r3, r0, 0x18
    lwz     r0, 0x5c(r1)
    lfd     f31, 0x50(r1)
    lfd     f30, 0x48(r1)
    lfd     f29, 0x40(r1)
    lfd     f28, 0x38(r1)
    lfd     f27, 0x30(r1)
    addi    r1, r1, 0x58
    mtlr    r0
    blr     
}

asm int fn_8003B010(register u32 a)
{
    nofralloc
    mflr    r0
    lis     r4, -0x7fe8
    stw     r0, 4(r1)
    stwu    r1, -0x60(r1)
    stfd    f31, 0x58(r1)
    stfd    f30, 0x50(r1)
    stfd    f29, 0x48(r1)
    stfd    f28, 0x40(r1)
    stfd    f27, 0x38(r1)
    stmw    r23, 0x14(r1)
    addi    r31, r4, -0x7740
    mr      r29, r3
    li      r30, 0
    lfs     f27, -0x7cc0(r2)
    lfs     f28, -0x7cbc(r2)
    lfs     f29, -0x7cb8(r2)
    lfs     f30, -0x7cb4(r2)
    lfs     f31, -0x7cb0(r2)
    b       _8003b5c8
_8003b05c:
    li      r23, 0
    b       _8003b088
_8003b064:
    clrlwi  r3, r23, 0x18
    rlwinm  r0, r23, 2, 0x16, 0x1d
    add     r4, r29, r3
    add     r3, r29, r0
    lbz     r4, 0x790(r4)
    lwz     r5, 0x750(r3)
    mr      r3, r29
    bl      fn_8003B63C
    addi    r23, r23, 1
_8003b088:
    lhz     r0, 0x7a2(r29)
    clrlwi  r3, r23, 0x18
    cmpw    r3, r0
    blt     _8003b064
    clrlwi  r28, r30, 0x18
    li      r0, 0
    li      r3, 0
    b       _8003b550
_8003b0a8:
    clrlwi  r5, r3, 0x18
    lbz     r4, 0x41b(r29)
    mulli   r5, r5, 0x30
    lhz     r8, 0x7aa(r29)
    addi    r7, r5, 0x6c0
    add     r7, r29, r7
    lbz     r6, 2(r7)
    add     r11, r29, r5
    li      r5, 0
    subf    r4, r6, r4
    sraw    r6, r8, r4
    b       _8003b53c
_8003b0d8:
    lwz     r8, 0x24(r7)
    clrlwi  r12, r0, 0x18
    li      r4, 0
    mullw   r8, r28, r8
    slwi    r8, r8, 2
    b       _8003b51c
_8003b0f0:
    clrlwi  r10, r4, 0x18
    lbz     r9, 0x6c3(r11)
    add     r10, r12, r10
    slwi    r10, r10, 2
    add     r10, r29, r10
    slwi    r9, r9, 8
    lwz     r23, 0x750(r10)
    add     r27, r29, r9
    addi    r24, r31, -8
    li      r10, 8
    mtctr   r10
_8003b11c:
    psq_l   f7, 0x0(r23), 0, 5
    psq_l   f6, 0x0(r27), 0, 0
            ps_mul f7, f7, f6
    lwz     r26, 0xc(r23)
    lwz     r9, 8(r23)
    or      r26, r26, r9
    lwz     r25, 4(r23)
    lhz     r10, 2(r23)
_8003b13c:
    cmpwi   r26, 0
    bne     _8003b288
    cmpwi   r25, 0
    bne     _8003b1ec
    cmpwi   r10, 0
    bne     _8003b178
            ps_merge00 f4, f7, f7
    addi    r27, r27, 0x20
    psq_stu f4, 0x8(r24), 0, 0
    psq_stu f4, 0x8(r24), 0, 0
    addi    r23, r23, 0x10
    psq_stu f4, 0x8(r24), 0, 0
    psq_stu f4, 0x8(r24), 0, 0
    bdnz    _8003b11c
    b       _8003b350
_8003b178:
            ps_msub f13, f7, f28, f7
    addi    r23, r23, 0x10
            ps_merge00 f2, f7, f7
    addi    r27, r27, 0x20
            ps_sub f1, f28, f29
    lwz     r25, 4(r23)
            ps_msub f12, f7, f27, f13
    lhz     r10, 2(r23)
            ps_merge11 f10, f7, f13
    psq_l   f6, 0x0(r27), 0, 0
            ps_nmsub f11, f7, f1, f12
            ps_add f8, f2, f10
    psq_l   f7, 0x0(r23), 0, 5
            ps_merge11 f9, f12, f11
            ps_sub f10, f2, f10
    lwz     r26, 0xc(r23)
            ps_add f3, f2, f9
    lwz     r9, 8(r23)
            ps_sub f9, f2, f9
    psq_stu f8, 0x8(r24), 0, 0
            ps_merge10 f9, f9, f9
    psq_stu f3, 0x8(r24), 0, 0
            ps_merge10 f10, f10, f10
    or      r26, r26, r9
    psq_stu f9, 0x8(r24), 0, 0
            ps_mul f7, f7, f6
    psq_stu f10, 0x8(r24), 0, 0
    bdnz    _8003b13c
    b       _8003b350
_8003b1ec:
    psq_l   f1, 0x4(r23), 0, 5
    psq_l   f2, 0x8(r27), 0, 0
    addi    r23, r23, 0x10
            ps_mul f1, f1, f2
    addi    r27, r27, 0x20
            ps_sub f12, f7, f1
            ps_add f13, f7, f1
    lwz     r26, 0xc(r23)
            ps_madd f11, f1, f27, f12
            ps_nmsub f10, f1, f27, f13
            ps_mul f3, f12, f28
            ps_merge00 f11, f13, f11
    lwz     r9, 8(r23)
            ps_nmsub f9, f1, f30, f3
            ps_merge00 f10, f10, f12
    lwz     r25, 4(r23)
            ps_sub f9, f9, f13
            ps_nmsub f8, f7, f29, f3
    lhz     r10, 2(r23)
            ps_merge11 f13, f13, f9
            ps_msub f3, f12, f27, f9
    psq_l   f7, 0x0(r23), 0, 5
            ps_add f2, f11, f13
            ps_sub f8, f8, f3
    psq_l   f6, 0x0(r27), 0, 0
            ps_merge11 f12, f3, f8
            ps_sub f11, f11, f13
    psq_stu f2, 0x8(r24), 0, 0
            ps_add f4, f10, f12
            ps_sub f1, f10, f12
    or      r26, r26, r9
    psq_stu f4, 0x8(r24), 0, 0
            ps_merge10 f1, f1, f1
            ps_merge10 f11, f11, f11
    psq_stu f1, 0x8(r24), 0, 0
            ps_mul f7, f7, f6
    psq_stu f11, 0x8(r24), 0, 0
    bdnz    _8003b13c
    b       _8003b350
_8003b288:
    psq_l   f2, 0x4(r23), 0, 5
    psq_l   f10, 0x8(r27), 0, 0
            ps_mul f2, f2, f10
    psq_l   f13, 0x8(r23), 0, 5
    psq_l   f9, 0x10(r27), 0, 0
            ps_merge01 f4, f7, f2
    psq_l   f12, 0xc(r23), 0, 5
            ps_merge01 f1, f2, f7
    psq_l   f8, 0x18(r27), 0, 0
    addi    r23, r23, 0x10
            ps_madd f11, f13, f9, f4
            ps_nmsub f10, f13, f9, f4
            ps_madd f9, f12, f8, f1
            ps_nmsub f8, f12, f8, f1
    addi    r27, r27, 0x20
            ps_add f4, f11, f9
            ps_sub f12, f11, f9
            ps_msub f13, f8, f27, f9
    lwz     r26, 0xc(r23)
            ps_sub f3, f8, f10
            ps_add f1, f10, f13
            ps_sub f13, f10, f13
            ps_mul f3, f3, f28
    lwz     r9, 8(r23)
            ps_merge00 f1, f4, f1
            ps_nmsub f9, f10, f30, f3
            ps_msub f11, f8, f29, f3
    lwz     r25, 4(r23)
            ps_sub f9, f9, f4
            ps_merge00 f13, f13, f12
    lhz     r10, 2(r23)
            ps_madd f10, f12, f27, f9
            ps_merge11 f8, f4, f9
    psq_l   f7, 0x0(r23), 0, 5
            ps_sub f11, f11, f10
            ps_add f12, f1, f8
    psq_l   f6, 0x0(r27), 0, 0
            ps_merge11 f11, f10, f11
            ps_sub f4, f1, f8
            ps_mul f7, f7, f6
            ps_add f10, f13, f11
            ps_sub f9, f13, f11
    psq_stu f12, 0x8(r24), 0, 0
            ps_merge10 f10, f10, f10
    psq_stu f9, 0x8(r24), 0, 0
            ps_merge10 f4, f4, f4
    psq_stu f10, 0x8(r24), 0, 0
    or      r26, r26, r9
    psq_stu f4, 0x8(r24), 0, 0
    bdnz    _8003b13c
_8003b350:
    lwz     r10, 0x6c8(r11)
    mr      r24, r31
    lwz     r23, 0x6d4(r11)
    psq_l   f7, 0x0(r24), 0, 0
    mullw   r26, r10, r6
    psq_l   f6, 0x80(r24), 0, 0
    psq_l   f5, 0x40(r24), 0, 0
    slwi    r27, r10, 2
            ps_add f9, f7, f6
    add     r26, r26, r8
    psq_l   f4, 0xc0(r24), 0, 0
            ps_sub f3, f7, f6
    add     r27, r26, r27
            ps_add f9, f9, f31
    li      r25, 3
            ps_add f8, f5, f4
    add     r10, r23, r26
            ps_sub f2, f5, f4
    add     r9, r23, r27
            ps_add f4, f9, f8
    mtctr   r25
            ps_add f3, f3, f31
_8003b3a8:
    psq_l   f11, 0x20(r24), 0, 0
            ps_msub f2, f2, f27, f8
    psq_l   f10, 0x60(r24), 0, 0
            ps_sub f12, f9, f8
            ps_add f1, f3, f2
    psq_l   f9, 0xa0(r24), 0, 0
            ps_sub f13, f3, f2
    psq_l   f8, 0xe0(r24), 0, 0
            ps_add f3, f9, f10
            ps_sub f9, f9, f10
            ps_add f2, f11, f8
            ps_sub f11, f11, f8
    addi    r24, r24, 8
            ps_add f8, f2, f3
            ps_sub f10, f2, f3
    psq_l   f7, 0x0(r24), 0, 0
            ps_add f3, f9, f11
    psq_l   f6, 0x80(r24), 0, 0
            ps_add f2, f4, f8
            ps_mul f3, f3, f28
    psq_l   f5, 0x40(r24), 0, 0
            ps_sub f0, f4, f8
            ps_madd f9, f9, f30, f3
    psq_l   f4, 0xc0(r24), 0, 0
            ps_sub f9, f9, f8
    addi    r26, r26, 2
    psq_st  f2, 0x0(r10), 0, 6
            ps_msub f11, f11, f29, f3
            ps_add f2, f1, f9
            ps_msub f10, f10, f27, f9
            ps_sub f1, f1, f9
    psq_stu f2, 0x8(r10), 0, 6
            ps_add f3, f13, f10
            ps_add f11, f11, f10
    psq_stu f3, 0x8(r10), 0, 6
    addi    r27, r27, 2
            ps_sub f2, f12, f11
            ps_add f3, f12, f11
    psq_stu f2, 0x8(r10), 0, 6
            ps_sub f2, f13, f10
            ps_add f9, f7, f6
    psq_st  f3, 0x0(r9), 0, 6
            ps_sub f3, f7, f6
            ps_add f9, f9, f31
    psq_stu f2, 0x8(r9), 0, 6
            ps_add f8, f5, f4
            ps_sub f2, f5, f4
    psq_stu f1, 0x8(r9), 0, 6
    add     r10, r23, r26
            ps_add f4, f9, f8
    psq_stu f0, 0x8(r9), 0, 6
            ps_add f3, f3, f31
    add     r9, r23, r27
    bdnz    _8003b3a8
    psq_l   f11, 0x20(r24), 0, 0
            ps_msub f2, f2, f27, f8
    psq_l   f10, 0x60(r24), 0, 0
            ps_sub f12, f9, f8
            ps_add f1, f3, f2
    psq_l   f9, 0xa0(r24), 0, 0
            ps_sub f13, f3, f2
    psq_l   f8, 0xe0(r24), 0, 0
            ps_add f3, f9, f10
            ps_sub f9, f9, f10
            ps_add f2, f11, f8
            ps_sub f11, f11, f8
            ps_add f8, f2, f3
            ps_sub f10, f2, f3
            ps_add f3, f9, f11
            ps_add f2, f4, f8
            ps_mul f3, f3, f28
            ps_sub f0, f4, f8
            ps_madd f9, f9, f30, f3
    psq_st  f2, 0x0(r10), 0, 6
            ps_sub f9, f9, f8
            ps_msub f11, f11, f29, f3
    psq_st  f0, 0x18(r9), 0, 6
            ps_add f2, f1, f9
            ps_msub f10, f10, f27, f9
            ps_sub f1, f1, f9
    psq_st  f2, 0x8(r10), 0, 6
            ps_add f3, f13, f10
            ps_add f11, f11, f10
            psq_st f3, 0x10(r10), 0, 6
            ps_sub f2, f12, f11
            psq_st f1, 0x10(r9), 0, 6
            ps_add f3, f12, f11
    psq_st  f2, 0x18(r10), 0, 6
            ps_sub f2, f13, f10
    psq_st  f3, 0x0(r9), 0, 6
    psq_st  f2, 0x8(r9), 0, 6
    addi    r8, r8, 0x20
    addi    r4, r4, 1
_8003b51c:
    lwz     r9, 0x18(r7)
    clrlwi  r10, r4, 0x18
    cmpw    r10, r9
    blt     _8003b0f0
    clrlwi  r4, r9, 0x18
    add     r0, r0, r4
    addi    r5, r5, 1
    addi    r6, r6, 8
_8003b53c:
    lwz     r4, 0x1c(r7)
    clrlwi  r8, r5, 0x18
    cmpw    r8, r4
    blt     _8003b0d8
    addi    r3, r3, 1
_8003b550:
    lbz     r4, 0x41c(r29)
    clrlwi  r5, r3, 0x18
    cmplw   r5, r4
    blt     _8003b0a8
    lbz     r0, 0x41e(r29)
    cmplwi  r0, 0
    beq     _8003b5c4
    lhz     r3, 0x7b0(r29)
    addi    r0, r3, -1
    sth     r0, 0x7b0(r29)
    lhz     r0, 0x7b0(r29)
    cmplwi  r0, 0
    bne     _8003b5c4
    lhz     r4, 0x7ae(r29)
    li      r0, 0x21
    li      r3, 0
    sth     r4, 0x7b0(r29)
    li      r5, 0
    stw     r0, 0x414(r29)
    b       _8003b5b4
_8003b5a0:
    clrlwi  r0, r3, 0x18
    mulli   r0, r0, 0x30
    add     r4, r29, r0
    sth     r5, 0x6c6(r4)
    addi    r3, r3, 1
_8003b5b4:
    lbz     r0, 0x41c(r29)
    clrlwi  r4, r3, 0x18
    cmplw   r4, r0
    blt     _8003b5a0
_8003b5c4:
    addi    r30, r30, 1
_8003b5c8:
    lhz     r0, 0x7a0(r29)
    clrlwi  r3, r30, 0x18
    cmpw    r3, r0
    blt     _8003b05c
    lhz     r3, 0x7a6(r29)
    addi    r0, r3, 1
    sth     r0, 0x7a6(r29)
    lhz     r3, 0x7aa(r29)
    lhz     r0, 0x7a8(r29)
    add     r0, r3, r0
    sth     r0, 0x7aa(r29)
    lhz     r3, 0x7a6(r29)
    lhz     r0, 0x7a4(r29)
    cmplw   r3, r0
    bge     _8003b60c
    li      r0, 0
    b       _8003b610
_8003b60c:
    li      r0, 1
_8003b610:
    lmw     r23, 0x14(r1)
    clrlwi  r3, r0, 0x18
    lwz     r0, 0x64(r1)
    lfd     f31, 0x58(r1)
    lfd     f30, 0x50(r1)
    lfd     f29, 0x48(r1)
    lfd     f28, 0x40(r1)
    lfd     f27, 0x38(r1)
    addi    r1, r1, 0x60
    mtlr    r0
    blr     
}

asm void fn_8003B63C(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x30(r1)
    stmw    r26, 0x18(r1)
    addi    r28, r3, 0
    addi    r29, r5, 0
    dcbz    0, r29
    clrlwi  r0, r4, 0x18
    mulli   r31, r0, 0x30
    add     r30, r28, r31
    lbz     r3, 0x6c4(r30)
    li      r0, 0x20
    rlwinm  r4, r3, 1, 0x18, 0x1e
    dcbz    r29, r0
    mr      r3, r28
    bl      fn_8003B8A8
    addi    r27, r3, 0
    li      r0, 0x40
    dcbz    r29, r0
    li      r5, 0
    li      r0, 0x60
    dcbz    r29, r0
    lbz     r0, 0x6c5(r30)
    cmpwi   r27, 0
    slwi    r3, r0, 1
    addi    r0, r3, 1
    clrlwi  r0, r0, 0x18
    mulli   r3, r0, 0xa8
    addi    r30, r3, 0x420
    add     r30, r28, r30
    beq     _8003b6e8
    addi    r3, r28, 0
    clrlwi  r4, r27, 0x18
    bl      fn_8003B798
    extsh   r5, r3
    cntlzw  r3, r5
    subfic  r0, r27, 0x20
    cmpw    r3, r0
    ble     _8003b6e8
    li      r0, -1
    slw     r0, r0, r27
    add     r5, r0, r5
    addi    r5, r5, 1
_8003b6e8:
    add     r4, r28, r31
    lha     r0, 0x6c6(r4)
    lis     r3, lbl_8008FF50@ha
    addi    r31, r3, lbl_8008FF50@l
    add     r0, r0, r5
    sth     r0, 0x6c6(r4)
    li      r27, 1
    sth     r0, 0(r29)
    b       _8003b77c
_8003b70c:
    addi    r3, r28, 0
    addi    r4, r30, 0
    bl      fn_8003B930
    clrlwi. r26, r3, 0x1c
    srawi   r0, r3, 4
    beq     _8003b76c
    addi    r3, r28, 0
    addi    r4, r26, 0
    add     r27, r27, r0
    bl      fn_8003B798
    cntlzw  r4, r3
    subfic  r0, r26, 0x20
    cmpw    r4, r0
    ble     _8003b754
    li      r0, -1
    slw     r0, r0, r26
    add     r3, r0, r3
    addi    r3, r3, 1
_8003b754:
    add     r4, r31, r27
    lbz     r0, 0(r4)
    extsh   r3, r3
    slwi    r0, r0, 1
    sthx    r3, r29, r0
    b       _8003b778
_8003b76c:
    cmpwi   r0, 0xf
    bne     _8003b784
    addi    r27, r27, 0xf
_8003b778:
    addi    r27, r27, 1
_8003b77c:
    cmpwi   r27, 0x40
    blt     _8003b70c
_8003b784:
    lmw     r26, 0x18(r1)
    lwz     r0, 0x34(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr     
}

asm int fn_8003B798(register u32 a, register int b)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    addi    r29, r4, 0
    stw     r28, 0x10(r1)
    addi    r28, r3, 0
    bl      fn_8003D42C
    clrlwi  r31, r29, 0x18
    cmplwi  r31, 1
    addi    r30, r3, 0
    bne     _8003b7d8
    mr      r3, r30
    b       _8003b888
_8003b7d8:
    cmplwi  r31, 2
    bne     _8003b7f4
    mr      r3, r28
    bl      fn_8003D42C
    slwi    r0, r30, 1
    add     r3, r0, r3
    b       _8003b888
_8003b7f4:
    cmplwi  r31, 3
    bne     _8003b820
    mr      r3, r28
    bl      fn_8003D42C
    slwi    r0, r30, 1
    add     r30, r0, r3
    addi    r3, r28, 0
    bl      fn_8003D42C
    slwi    r0, r30, 1
    add     r3, r0, r3
    b       _8003b888
_8003b820:
    mr      r3, r28
    bl      fn_8003D42C
    slwi    r0, r30, 1
    add     r30, r0, r3
    addi    r3, r28, 0
    bl      fn_8003D42C
    slwi    r0, r30, 1
    add     r30, r0, r3
    addi    r3, r28, 0
    bl      fn_8003D42C
    cmplwi  r31, 4
    slwi    r0, r30, 1
    add     r30, r0, r3
    bne     _8003b860
    mr      r3, r30
    b       _8003b888
_8003b860:
    li      r29, 4
    b       _8003b87c
_8003b868:
    mr      r3, r28
    bl      fn_8003D42C
    slwi    r0, r30, 1
    add     r30, r0, r3
    addi    r29, r29, 1
_8003b87c:
    cmpw    r29, r31
    blt     _8003b868
    mr      r3, r30
_8003b888:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr     
}

asm int fn_8003B8A8(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    clrlwi  r0, r4, 0x18
    mulli   r4, r0, 0xa8
    stwu    r1, -0x28(r1)
    stmw    r27, 0x14(r1)
    addi    r27, r3, 0
    addi    r30, r4, 0x420
    add     r30, r27, r30
    li      r28, 1
    bl      fn_8003D42C
    addi    r29, r3, 0
    addi    r31, r30, 4
    b       _8003b8f8
_8003b8e0:
    slwi    r29, r29, 1
    addi    r3, r27, 0
    bl      fn_8003D42C
    or      r29, r29, r3
    addi    r31, r31, 4
    addi    r28, r28, 1
_8003b8f8:
    lwz     r0, 0x14(r31)
    cmpw    r29, r0
    bgt     _8003b8e0
    slwi    r0, r28, 2
    lwz     r4, 0x10(r30)
    add     r3, r30, r0
    lwz     r0, 0x5c(r3)
    add     r0, r0, r4
    lbzx    r3, r29, r0
    lwz     r0, 0x2c(r1)
    lmw     r27, 0x14(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr     
}

asm int fn_8003B930(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x28(r1)
    stmw    r27, 0x14(r1)
    addi    r27, r3, 0
    addi    r28, r4, 0
    li      r29, 1
    bl      fn_8003D42C
    addi    r30, r3, 0
    addi    r31, r28, 4
    b       _8003b974
_8003b95c:
    slwi    r30, r30, 1
    addi    r3, r27, 0
    bl      fn_8003D42C
    or      r30, r30, r3
    addi    r31, r31, 4
    addi    r29, r29, 1
_8003b974:
    lwz     r0, 0x14(r31)
    cmpw    r30, r0
    bgt     _8003b95c
    slwi    r0, r29, 2
    lwz     r4, 0x10(r28)
    add     r3, r28, r0
    lwz     r0, 0x5c(r3)
    add     r0, r0, r4
    lbzx    r3, r30, r0
    lwz     r0, 0x2c(r1)
    lmw     r27, 0x14(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr     
}

asm int fn_8003B9AC(register u32 a)
{
    nofralloc
    cmplwi  r7, 0
    lfs     f0, -0x7cac(r2)
    addi    r7, r7, 3
    lfs     f1, -0x7ca8(r2)
    lfs     f2, -0x7ca4(r2)
    srwi    r7, r7, 2
    lfs     f3, -0x7ca0(r2)
    blelr   
    rlwinm. r0, r7, 0x1e, 2, 0x1f
    mtctr   r0
    beq     _8003bae4
_8003b9d8:
            psq_lu f4, 0x2(r4), 0, 2
            psq_lu f6, 0x2(r5), 0, 2
            ps_madd f4, f4, f1, f0
            ps_madd f6, f6, f2, f0
            psq_lu f5, 0x2(r4), 0, 2
            psq_lu f7, 0x2(r6), 0, 2
            ps_madd f5, f5, f1, f0
            ps_madd f7, f7, f3, f0
            ps_merge00 f8, f4, f6
            ps_merge10 f4, f4, f7
            psq_stu f8, 0x2(r3), 0, 2
            psq_stu f4, 0x2(r3), 0, 2
            ps_merge01 f4, f5, f6
            ps_merge11 f5, f5, f7
            psq_stu f4, 0x2(r3), 0, 2
            psq_stu f5, 0x2(r3), 0, 2
            psq_lu f4, 0x2(r4), 0, 2
            psq_lu f6, 0x2(r5), 0, 2
            ps_madd f4, f4, f1, f0
            ps_madd f6, f6, f2, f0
            psq_lu f5, 0x2(r4), 0, 2
            psq_lu f7, 0x2(r6), 0, 2
            ps_madd f5, f5, f1, f0
            ps_madd f7, f7, f3, f0
            ps_merge00 f8, f4, f6
            ps_merge10 f4, f4, f7
            psq_stu f8, 0x2(r3), 0, 2
            psq_stu f4, 0x2(r3), 0, 2
            ps_merge01 f4, f5, f6
            ps_merge11 f5, f5, f7
            psq_stu f4, 0x2(r3), 0, 2
            psq_stu f5, 0x2(r3), 0, 2
            psq_lu f4, 0x2(r4), 0, 2
            psq_lu f6, 0x2(r5), 0, 2
            ps_madd f4, f4, f1, f0
            ps_madd f6, f6, f2, f0
            psq_lu f5, 0x2(r4), 0, 2
            psq_lu f7, 0x2(r6), 0, 2
            ps_madd f5, f5, f1, f0
            ps_madd f7, f7, f3, f0
            ps_merge00 f8, f4, f6
            ps_merge10 f4, f4, f7
            psq_stu f8, 0x2(r3), 0, 2
            psq_stu f4, 0x2(r3), 0, 2
            ps_merge01 f4, f5, f6
            ps_merge11 f5, f5, f7
            psq_stu f4, 0x2(r3), 0, 2
            psq_stu f5, 0x2(r3), 0, 2
            psq_lu f4, 0x2(r4), 0, 2
            psq_lu f6, 0x2(r5), 0, 2
            ps_madd f4, f4, f1, f0
            ps_madd f6, f6, f2, f0
            psq_lu f5, 0x2(r4), 0, 2
            psq_lu f7, 0x2(r6), 0, 2
            ps_madd f5, f5, f1, f0
            ps_madd f7, f7, f3, f0
            ps_merge00 f8, f4, f6
            ps_merge10 f4, f4, f7
            psq_stu f8, 0x2(r3), 0, 2
            psq_stu f4, 0x2(r3), 0, 2
            ps_merge01 f4, f5, f6
            ps_merge11 f5, f5, f7
            psq_stu f4, 0x2(r3), 0, 2
            psq_stu f5, 0x2(r3), 0, 2
    bdnz    _8003b9d8
    andi.   r7, r7, 3
    beqlr   
_8003bae4:
    mtctr   r7
_8003bae8:
            psq_lu f4, 0x2(r4), 0, 2
            psq_lu f6, 0x2(r5), 0, 2
            ps_madd f4, f4, f1, f0
            ps_madd f6, f6, f2, f0
            psq_lu f5, 0x2(r4), 0, 2
            psq_lu f7, 0x2(r6), 0, 2
            ps_madd f5, f5, f1, f0
            ps_madd f7, f7, f3, f0
            ps_merge00 f8, f4, f6
            ps_merge10 f4, f4, f7
            psq_stu f8, 0x2(r3), 0, 2
            psq_stu f4, 0x2(r3), 0, 2
            ps_merge01 f4, f5, f6
            ps_merge11 f5, f5, f7
            psq_stu f4, 0x2(r3), 0, 2
            psq_stu f5, 0x2(r3), 0, 2
    bdnz    _8003bae8
    blr     
}


