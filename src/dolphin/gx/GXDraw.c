typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void* memset(void*, int, unsigned long);
extern void* memcpy(void*, const void*, unsigned long);
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void fn_80038878(void);
extern void fn_80079764(void);
extern void GXSetCPUFifo(register void* fifo);
extern void GXSaveCPUFifo(register void* fifo);
extern void GXGetCPUFifo(void);
extern void __GXSaveCPUFifoAux(void);
extern void __GXSetDirtyState(void);
extern void __GXSendFlushPrim(void);
asm void fn_80038DE8(register void* p);
asm void fn_80039088(register void* p);

#pragma push
#pragma force_active on

asm void fn_8003887C(register void* p1, register void* p2)
{
    nofralloc
    mflr    r0
    lis     r5, -0x7fe8
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r5, -0x7c60
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

asm void fn_80038944(register void* p)
{
    nofralloc
    mflr    r0
    lis     r4, -0x7fe8
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    addi    r31, r4, -0x7c60
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
    bl      fn_80079764
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

asm void fn_80038D34(register void* p)
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

asm void fn_80038DE8(register void* p)
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
    bl      fn_80038DE8
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

