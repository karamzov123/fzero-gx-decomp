#pragma push
#pragma force_active on

extern void memset(void);
extern void fn_800885B8(void);
extern unsigned char lbl_80128160[32];

asm void axmix_heap_init(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0xc0(r1)
    stfd	f31, 0xb8(r1)
    fmr	f31, f5
    stfd	f30, 0xb0(r1)
    stfd	f29, 0xa8(r1)
    stfd	f28, 0xa0(r1)
    fmr	f28, f2
    stfd	f27, 0x98(r1)
    fmr	f27, f6
    stfd	f26, 0x90(r1)
    fmr	f26, f4
    stfd	f25, 0x88(r1)
    fmr	f25, f3
    stfd	f24, 0x80(r1)
    fmr	f24, f1
    stmw	r16, 0x40(r1)
    mr	r30, r3
    lfs	f7, -0x7ec0(r2)
    fcmpo	cr0, f24, f7
    blt     _80023744
    lfs	f1, -0x7ebc(r2)
    fcmpo	cr0, f24, f1
    bgt     _80023744
    lfs	f0, -0x7eb8(r2)
    fcmpo	cr0, f28, f0
    blt     _80023744
    lfs	f0, -0x7eb4(r2)
    fcmpo	cr0, f28, f0
    bgt     _80023744
    fcmpo	cr0, f25, f7
    blt     _80023744
    fcmpo	cr0, f25, f1
    bgt     _80023744
    fcmpo	cr0, f27, f7
    blt     _80023744
    fcmpo	cr0, f27, f1
    bgt     _80023744
    fcmpo	cr0, f26, f7
    blt     _80023744
    fcmpo	cr0, f26, f1
    bgt     _80023744
    fcmpo	cr0, f31, f7
    blt     _80023744
    lfs	f0, -0x7eb0(r2)
    fcmpo	cr0, f31, f0
    ble     _8002374c
_80023744:
    li	r3, 0
    b       _80023b3c
_8002374c:
    addi	r3, r30, 0
    li	r4, 0
    li	r5, 0x1c4
    bl      memset
    lfs	f0, -0x7eac(r2)
    lis     r3, lbl_80128160@ha
    addi	r21, r3, lbl_80128160@l
    lfs	f30, -0x7ec0(r2)
    fmuls	f28, f0, f28
    lfd	f29, -0x7ea0(r2)
    addi	r25, r21, 0
    addi	r24, r30, 0
    addi	r23, r30, 0
    addi	r28, r21, 0
    li	r31, 0
    li	r26, 0
    lis	r29, 0x4330
    b       _80023a4c
_80023794:
    mulli	r18, r26, 0x14
    addi	r27, r28, 0
    slwi	r19, r26, 2
    li	r20, 0
    b       _800238a0
_800237a8:
    lwz	r3, 0(r27)
    add	r22, r30, r18
    addi	r17, r3, 2
    slwi	r16, r17, 2
    stw	r16, 0xbc(r22)
    mr	r3, r16
    lwz	r12, -0x7ec8(r13)
    mtlr	r12
    blrl	
    stw	r3, 0xc0(r22)
    addi	r5, r16, 0
    li	r4, 0
    lwz	r3, 0xc0(r22)
    bl      memset
    stfs	f30, 0xc4(r22)
    addi	r5, r22, 0xb4
    srawi	r3, r17, 1
    lwz	r0, 0xb4(r22)
    slwi	r4, r3, 2
    addi	r3, r22, 0xb8
    subf	r0, r4, r0
    stw	r0, 0xb8(r22)
    b       _80023814
_80023804:
    lwz	r4, 0xb8(r22)
    lwz	r0, 0xbc(r22)
    add	r0, r4, r0
    stw	r0, 0xb8(r22)
_80023814:
    lwz	r0, 0xb8(r22)
    cmpwi	r0, 0
    blt     _80023804
    li	r0, 0
    stw	r0, 0(r5)
    stw	r0, 0(r3)
    lwz	r4, 0(r27)
    lwz	r0, 0(r5)
    slwi	r4, r4, 2
    subf	r0, r4, r0
    stw	r0, 0(r3)
    b       _80023854
_80023844:
    lwz	r3, 0xb8(r22)
    lwz	r0, 0xbc(r22)
    add	r0, r3, r0
    stw	r0, 0xb8(r22)
_80023854:
    lwz	r0, 0xb8(r22)
    cmpwi	r0, 0
    blt     _80023844
    lwz	r0, 0(r27)
    lfs	f1, -0x7eb4(r2)
    mulli	r0, r0, -3
    xoris	r0, r0, 0x8000
    stw	r0, 0x3c(r1)
    stw	r29, 0x38(r1)
    lfd	f0, 0x38(r1)
    fsubs	f0, f0, f29
    fdivs	f2, f0, f28
    bl      fn_800885B8
    addi	r0, r19, 0x16c
    stfsx	f1, r30, r0
    addi	r27, r27, 4
    addi	r19, r19, 4
    addi	r18, r18, 0x14
    addi	r20, r20, 1
_800238a0:
    clrlwi	r0, r20, 0x18
    cmplwi	r0, 3
    blt     _800237a8
    mulli	r19, r26, 0x14
    addi	r27, r21, 0
    li	r20, 0
    b       _8002397c
_800238bc:
    lwz	r3, 0xc(r27)
    add	r22, r30, r19
    addi	r17, r3, 2
    slwi	r16, r17, 2
    stw	r16, 8(r22)
    mr	r3, r16
    lwz	r12, -0x7ec8(r13)
    mtlr	r12
    blrl	
    stw	r3, 0xc(r22)
    addi	r5, r16, 0
    li	r4, 0
    lwz	r3, 0xc(r22)
    bl      memset
    stfs	f30, 0x10(r22)
    srawi	r0, r17, 1
    slwi	r3, r0, 2
    lwz	r0, 0(r22)
    addi	r4, r22, 4
    subf	r0, r3, r0
    stw	r0, 4(r22)
    b       _80023924
_80023914:
    lwz	r3, 4(r22)
    lwz	r0, 8(r22)
    add	r0, r3, r0
    stw	r0, 4(r22)
_80023924:
    lwz	r0, 4(r22)
    cmpwi	r0, 0
    blt     _80023914
    li	r0, 0
    stw	r0, 0(r22)
    stw	r0, 0(r4)
    lwz	r3, 0xc(r27)
    lwz	r0, 0(r22)
    slwi	r3, r3, 2
    subf	r0, r3, r0
    stw	r0, 0(r4)
    b       _80023964
_80023954:
    lwz	r3, 4(r22)
    lwz	r0, 8(r22)
    add	r0, r3, r0
    stw	r0, 4(r22)
_80023964:
    lwz	r0, 4(r22)
    cmpwi	r0, 0
    blt     _80023954
    addi	r27, r27, 4
    addi	r19, r19, 0x14
    addi	r20, r20, 1
_8002397c:
    clrlwi	r0, r20, 0x18
    cmplwi	r0, 2
    blt     _800238bc
    lwz	r3, 0x14(r25)
    addi	r17, r3, 2
    slwi	r16, r17, 2
    stw	r16, 0x30(r24)
    mr	r3, r16
    lwz	r12, -0x7ec8(r13)
    mtlr	r12
    blrl	
    stw	r3, 0x34(r24)
    addi	r5, r16, 0
    li	r4, 0
    lwz	r3, 0x34(r24)
    bl      memset
    stfs	f30, 0x38(r24)
    srawi	r0, r17, 1
    slwi	r3, r0, 2
    lwz	r0, 0x28(r24)
    subf	r0, r3, r0
    stw	r0, 0x2c(r24)
    b       _800239e8
_800239d8:
    lwz	r3, 0x2c(r24)
    lwz	r0, 0x30(r24)
    add	r0, r3, r0
    stw	r0, 0x2c(r24)
_800239e8:
    lwz	r0, 0x2c(r24)
    cmpwi	r0, 0
    blt     _800239d8
    li	r0, 0
    stw	r0, 0x28(r24)
    stw	r0, 0x2c(r24)
    lwz	r3, 0x14(r25)
    lwz	r0, 0x28(r24)
    slwi	r3, r3, 2
    subf	r0, r3, r0
    stw	r0, 0x2c(r24)
    b       _80023a28
_80023a18:
    lwz	r3, 0x2c(r24)
    lwz	r0, 0x30(r24)
    add	r0, r3, r0
    stw	r0, 0x2c(r24)
_80023a28:
    lwz	r0, 0x2c(r24)
    cmpwi	r0, 0
    blt     _80023a18
    stfs	f30, 0x190(r23)
    addi	r26, r26, 3
    addi	r25, r25, 4
    addi	r24, r24, 0x3c
    addi	r23, r23, 4
    addi	r31, r31, 1
_80023a4c:
    clrlwi	r0, r31, 0x18
    cmplwi	r0, 3
    blt     _80023794
    stfs	f24, 0x168(r30)
    stfs	f25, 0x19c(r30)
    stfs	f27, 0x1a8(r30)
    stfs	f26, 0x1a0(r30)
    lfs	f1, 0x1a0(r30)
    lfs	f0, -0x7ea8(r2)
    fcmpo	cr0, f1, f0
    bge     _80023a7c
    stfs	f0, 0x1a0(r30)
_80023a7c:
    lfs	f1, -0x7ea4(r2)
    lfs	f0, 0x1a0(r30)
    lfs	f2, -0x7ea8(r2)
    fmuls	f0, f1, f0
    lfs	f1, -0x7ebc(r2)
    fadds	f0, f2, f0
    fsubs	f0, f1, f0
    stfs	f0, 0x1a0(r30)
    lfs	f0, -0x7ec0(r2)
    fcmpu	cr0, f0, f31
    beq     _80023b18
    lfs	f0, -0x7eac(r2)
    addi	r17, r30, 0
    li	r16, 0
    fmuls	f0, f0, f31
    fctiwz	f0, f0
    stfd	f0, 0x38(r1)
    lwz	r0, 0x3c(r1)
    stw	r0, 0x1a4(r30)
    b       _80023b08
_80023acc:
    lwz	r12, -0x7ec8(r13)
    lwz	r0, 0x1a4(r30)
    mtlr	r12
    slwi	r3, r0, 2
    blrl	
    stw	r3, 0x1ac(r17)
    li	r4, 0
    lwz	r0, 0x1a4(r30)
    lwz	r3, 0x1ac(r17)
    slwi	r5, r0, 2
    bl      memset
    lwz	r0, 0x1ac(r17)
    addi	r16, r16, 1
    stw	r0, 0x1b8(r17)
    addi	r17, r17, 4
_80023b08:
    clrlwi	r0, r16, 0x18
    cmplwi	r0, 3
    blt     _80023acc
    b       _80023b38
_80023b18:
    li	r0, 0
    stw	r0, 0x1a4(r30)
    stw	r0, 0x1b8(r30)
    stw	r0, 0x1ac(r30)
    stw	r0, 0x1bc(r30)
    stw	r0, 0x1b0(r30)
    stw	r0, 0x1c0(r30)
    stw	r0, 0x1b4(r30)
_80023b38:
    li	r3, 1
_80023b3c:
    lmw	r16, 0x40(r1)
    lwz	r0, 0xc4(r1)
    lfd	f31, 0xb8(r1)
    lfd	f30, 0xb0(r1)
    lfd	f29, 0xa8(r1)
    lfd	f28, 0xa0(r1)
    lfd	f27, 0x98(r1)
    lfd	f26, 0x90(r1)
    lfd	f25, 0x88(r1)
    lfd	f24, 0x80(r1)
    addi	r1, r1, 0xc0
    mtlr	r0
    blr	
}

asm void fn_80023B70(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    stfd	f14, 0x28(r1)
    lis	r5, -0x7fe6
    lfd	f0, 0x6fa8(r5)
    lis	r5, 0x4330
    stw	r5, 8(r1)
    stw	r5, 0x10(r1)
    stw	r5, 0x18(r1)
    stw	r5, 0x20(r1)
    ps_merge00 f3, f2, f1
    ps_merge00 f4, f1, f2
    lis	r5, -0x7fe6
    lfs	f5, 0x6fb0(r5)
    li	r5, 0x4f
    mtctr	r5
    li	r10, -8
    li	r11, -4
    ps_muls0	f4, f4, f5
    lwz	r6, 0(r3)
    lwz	r7, 0(r4)
    xoris	r6, r6, 0x8000
    lwz	r8, 4(r3)
    xoris	r7, r7, 0x8000
    lwz	r9, 4(r4)
    xoris	r8, r8, 0x8000
    stw	r6, 0xc(r1)
    xoris	r9, r9, 0x8000
    stw	r7, 0x14(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x24(r1)
    lfd	f5, 8(r1)
    lfd	f6, 0x10(r1)
    fsubs	f5, f5, f0
    lfd	f7, 0x18(r1)
    fsubs	f6, f6, f0
    lfd	f8, 0x20(r1)
    fsubs	f7, f7, f0
    fsubs	f8, f8, f0
_80023c08:
    ps_merge00 f9, f5, f6
    lwzu	r6, 8(r3)
    ps_merge00 f10, f7, f8
    lwzu	r7, 8(r4)
    xoris	r6, r6, 0x8000
    lwz	r8, 4(r3)
    ps_mul	f11, f9, f3
    xoris	r7, r7, 0x8000
    ps_mul	f12, f9, f4
    lwz	r9, 4(r4)
    ps_mul	f13, f10, f3
    xoris	r8, r8, 0x8000
    ps_mul	f14, f10, f4
    stw	r6, 0xc(r1)
    ps_sum0	f11, f11, f11, f11
    xoris	r9, r9, 0x8000
    ps_sum0	f12, f12, f12, f12
    stw	r7, 0x14(r1)
    ps_sum0	f13, f13, f13, f13
    stw	r8, 0x1c(r1)
    ps_sum0	f14, f14, f14, f14
    stw	r9, 0x24(r1)
    fctiw	f11, f11
    lfd	f5, 8(r1)
    fctiw	f12, f12
    lfd	f6, 0x10(r1)
    fctiw	f13, f13
    fsubs	f5, f5, f0
    fctiw	f14, f14
    lfd	f7, 0x18(r1)
    stfiwx	f11, r10, r3
    fsubs	f6, f6, f0
    stfiwx	f12, r10, r4
    lfd	f8, 0x20(r1)
    stfiwx	f13, r11, r3
    fsubs	f7, f7, f0
    stfiwx	f14, r11, r4
    fsubs	f8, f8, f0
    bdnz    _80023c08
    ps_merge00 f9, f5, f6
    addi	r3, r3, 8
    ps_merge00 f10, f7, f8
    addi	r4, r4, 8
    ps_mul	f11, f9, f3
    ps_mul	f12, f9, f4
    ps_mul	f13, f10, f3
    ps_mul	f14, f10, f4
    ps_sum0	f11, f11, f11, f11
    ps_sum0	f12, f12, f12, f12
    ps_sum0	f13, f13, f13, f13
    ps_sum0	f14, f14, f14, f14
    fctiw	f11, f11
    fctiw	f12, f12
    fctiw	f13, f13
    fctiw	f14, f14
    stfiwx	f11, r10, r3
    stfiwx	f12, r10, r4
    stfiwx	f13, r11, r3
    stfiwx	f14, r11, r4
    lfd	f14, 0x28(r1)
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80023D00(void)
{
    nofralloc
    stwu	r1, -0xc0(r1)
    stmw	r14, 8(r1)
    stfd	f14, 0x60(r1)
    stfd	f15, 0x68(r1)
    stfd	f16, 0x70(r1)
    stfd	f17, 0x78(r1)
    stfd	f18, 0x80(r1)
    stfd	f19, 0x88(r1)
    stfd	f20, 0x90(r1)
    stfd	f21, 0x98(r1)
    stfd	f22, 0xa0(r1)
    stfd	f23, 0xa8(r1)
    stfd	f24, 0xb0(r1)
    stfd	f25, 0xb8(r1)
    stw	r5, 0x50(r1)
    stw	r4, 0x54(r1)
    lis	r31, -0x7fe6
    lfs	f6, 0x6fb4(r31)
    lis	r31, -0x7fe6
    lfs	f9, 0x6fb8(r31)
    lis	r31, -0x7fe6
    lfd	f5, 0x6fa8(r31)
    lfs	f2, 0x168(r4)
    lfs	f15, 0x1a0(r4)
    lfs	f8, 0x19c(r4)
    fmuls	f3, f8, f9
    fsubs	f4, f9, f3
    slwi	r30, r5, 1
    add	r30, r30, r5
    mulli	r31, r30, 0x14
    addi	r29, r4, 0xb4
    add	r29, r29, r31
    addi	r27, r4, 0
    add	r27, r27, r31
    slwi	r31, r30, 2
    add	r31, r31, r4
    lfs	f22, 0x16c(r31)
    lfs	f23, 0x170(r31)
    lfs	f24, 0x174(r31)
    slwi	r31, r5, 2
    add	r31, r31, r4
    lfs	f25, 0x190(r31)
    lwz	r31, 0x1a4(r4)
    lis	r30, 0x4330
    stw	r30, 0x58(r1)
    addi	r22, r31, -1
    slwi	r22, r22, 2
    slwi	r28, r5, 2
    add	r28, r28, r4
    cmpwi	cr7, r31, 0
    lwz	r21, 0(r29)
    lwz	r20, 4(r29)
    lwz	r19, 0x14(r29)
    lwz	r18, 0x18(r29)
    lwz	r17, 0x28(r29)
    lwz	r16, 0x2c(r29)
    lfs	f16, 0x10(r29)
    lfs	f17, 0x24(r29)
    lfs	f18, 0x38(r29)
    lwz	r25, 8(r29)
    lwz	r24, 0x1c(r29)
    lwz	r23, 0x30(r29)
    lwz	r4, 0xc(r29)
    lwz	r5, 0x20(r29)
    lwz	r6, 0x34(r29)
    lwz	r12, 0(r27)
    lwz	r11, 4(r27)
    lwz	r10, 0x14(r27)
    lwz	r9, 0x18(r27)
    lwz	r8, 0x28(r27)
    lwz	r7, 0x2c(r27)
    lfs	f19, 0x10(r27)
    lfs	f20, 0x24(r27)
    lfs	f21, 0x38(r27)
    lwz	r15, 8(r27)
    lwz	r14, 0x1c(r27)
    lwz	r30, 0(r3)
    xoris	r30, r30, 0x8000
    stw	r30, 0x5c(r1)
    lfd	f12, 0x58(r1)
    fsubs	f12, f12, f5
    li	r31, 0x9f
    mtctr	r31
_80023e4c:
    fmr	f13, f12
    beq      cr7, _80023e7c
    lwz	r30, 0x1ac(r28)
    lwz	r29, 0x1b8(r28)
    add	r31, r22, r30
    addi	r29, r29, 4
    lfs	f13, -4(r29)
    cmpw	r29, r31
    stfs	f12, -4(r29)
    bne+     cr0, _80023e78
    mr	r29, r30
_80023e78:
    stw	r29, 0x1b8(r30)
_80023e7c:
    fmadds	f8, f22, f16, f13
    lwzu	r29, 4(r3)
    fmadds	f9, f23, f17, f13
    stfsx	f8, r4, r21
    addi	r21, r21, 4
    stfsx	f9, r5, r19
    lfsx	f14, r4, r20
    addi	r20, r20, 4
    lfsx	f17, r5, r18
    cmpw	r21, r25
    cmpw	cr1, r20, r25
    addi	r19, r19, 4
    addi	r18, r18, 4
    fmr	f16, f14
    cmpw	cr5, r19, r24
    fadds	f14, f14, f17
    cmpw	cr6, r18, r24
    bne+     cr0, _80023ec8
    li	r21, 0
_80023ec8:
    fmadds	f8, f24, f18, f13
    bne+     cr1, _80023ed4
    li	r20, 0
_80023ed4:
    stfsx	f8, r6, r17
    addi	r17, r17, 4
    bne+     cr5, _80023ee4
    li	r19, 0
_80023ee4:
    lfsx	f18, r6, r16
    addi	r16, r16, 4
    cmpw	r17, r23
    bne+     cr6, _80023ef8
    li	r18, 0
_80023ef8:
    fadds	f14, f14, f18
    cmpw	cr1, r16, r23
    lwz	r26, 0xc(r27)
    fmadds	f9, f2, f19, f14
    bne+     cr0, _80023f10
    li	r17, 0
_80023f10:
    bne+     cr1, _80023f18
    li	r16, 0
_80023f18:
    xoris	r29, r29, 0x8000
    stfsx	f9, r26, r12
    fnmsubs	f14, f2, f9, f19
    addi	r12, r12, 4
    lfsx	f19, r26, r11
    cmpw	cr5, r12, r15
    addi	r11, r11, 4
    lwz	r26, 0x20(r27)
    cmpw	cr6, r11, r15
    fmadds	f8, f2, f20, f14
    bne+     cr5, _80023f48
    li	r12, 0
_80023f48:
    stw	r29, 0x5c(r1)
    stfsx	f8, r26, r10
    fnmsubs	f14, f2, f8, f20
    addi	r10, r10, 4
    bne+     cr6, _80023f60
    li	r11, 0
_80023f60:
    lfsx	f20, r26, r9
    cmpw	r10, r14
    fmuls	f14, f14, f6
    addi	r9, r9, 4
    cmpw	cr1, r9, r14
    lfd	f10, 0x58(r1)
    fmadds	f14, f15, f25, f14
    bne+     cr0, _80023f84
    li	r10, 0
_80023f84:
    lwz	r26, 0x34(r27)
    fmadds	f9, f2, f21, f14
    fmr	f25, f14
    bne+     cr1, _80023f98
    li	r9, 0
_80023f98:
    stfsx	f9, r26, r8
    fnmsubs	f14, f2, f9, f21
    lwz	r31, 0x30(r27)
    fmuls	f8, f4, f12
    lfsx	f21, r26, r7
    addi	r8, r8, 4
    addi	r7, r7, 4
    fmadds	f14, f3, f14, f8
    cmpw	cr5, r8, r31
    cmpw	cr6, r7, r31
    fctiwz	f14, f14
    bne+     cr5, _80023fcc
    li	r8, 0
_80023fcc:
    bne+     cr6, _80023fd4
    li	r7, 0
_80023fd4:
    li	r31, -4
    fsubs	f12, f10, f5
    stfiwx	f14, r3, r31
    bdnz    _80023e4c
    fmr	f13, f12
    beq      cr7, _80024014
    lwz	r30, 0x1ac(r28)
    lwz	r29, 0x1b8(r28)
    add	r31, r22, r30
    addi	r29, r29, 4
    lfs	f13, -4(r29)
    cmpw	r29, r31
    stfs	f12, -4(r29)
    bne+     cr0, _80024010
    mr	r29, r30
_80024010:
    stw	r29, 0x1b8(r30)
_80024014:
    fmadds	f8, f22, f16, f13
    fmadds	f9, f23, f17, f13
    stfsx	f8, r4, r21
    addi	r21, r21, 4
    stfsx	f9, r5, r19
    lfsx	f14, r4, r20
    addi	r20, r20, 4
    lfsx	f17, r5, r18
    cmpw	r21, r25
    cmpw	cr1, r20, r25
    addi	r19, r19, 4
    addi	r18, r18, 4
    fmr	f16, f14
    cmpw	cr5, r19, r24
    fadds	f14, f14, f17
    cmpw	cr6, r18, r24
    bne+     cr0, _8002405c
    li	r21, 0
_8002405c:
    fmadds	f8, f24, f18, f13
    bne+     cr1, _80024068
    li	r20, 0
_80024068:
    stfsx	f8, r6, r17
    addi	r17, r17, 4
    bne+     cr5, _80024078
    li	r19, 0
_80024078:
    lfsx	f18, r6, r16
    addi	r16, r16, 4
    cmpw	r17, r23
    bne+     cr6, _8002408c
    li	r18, 0
_8002408c:
    fadds	f14, f14, f18
    cmpw	cr1, r16, r23
    lwz	r26, 0xc(r27)
    fmadds	f9, f2, f19, f14
    bne+     cr0, _800240a4
    li	r17, 0
_800240a4:
    bne+     cr1, _800240ac
    li	r16, 0
_800240ac:
    stfsx	f9, r26, r12
    fnmsubs	f14, f2, f9, f19
    addi	r12, r12, 4
    lfsx	f19, r26, r11
    cmpw	cr5, r12, r15
    addi	r11, r11, 4
    lwz	r26, 0x20(r27)
    cmpw	cr6, r11, r15
    fmadds	f8, f2, f20, f14
    bne+     cr5, _800240d8
    li	r12, 0
_800240d8:
    stfsx	f8, r26, r10
    fnmsubs	f14, f2, f8, f20
    addi	r10, r10, 4
    bne+     cr6, _800240ec
    li	r11, 0
_800240ec:
    lfsx	f20, r26, r9
    cmpw	r10, r14
    fmuls	f14, f14, f6
    addi	r9, r9, 4
    cmpw	cr1, r9, r14
    fmadds	f14, f15, f25, f14
    bne+     cr0, _8002410c
    li	r10, 0
_8002410c:
    lwz	r26, 0x34(r27)
    lwz	r5, 0x50(r1)
    lwz	r4, 0x54(r1)
    fmadds	f9, f2, f21, f14
    fmr	f25, f14
    bne+     cr1, _80024128
    li	r9, 0
_80024128:
    stfsx	f9, r26, r8
    fnmsubs	f14, f2, f9, f21
    lwz	r29, 0x30(r27)
    fmuls	f8, f4, f12
    lfsx	f21, r26, r7
    addi	r8, r8, 4
    addi	r7, r7, 4
    fmadds	f14, f3, f14, f8
    cmpw	cr5, r8, r29
    cmpw	cr6, r7, r29
    fctiwz	f14, f14
    bne+     cr5, _8002415c
    li	r8, 0
_8002415c:
    bne+     cr6, _80024164
    li	r7, 0
_80024164:
    slwi	r30, r5, 1
    add	r30, r30, r5
    mulli	r31, r30, 0x14
    stfiwx	f14, 0, r3
    addi	r29, r4, 0xb4
    add	r29, r29, r31
    stw	r21, 0(r29)
    stw	r20, 4(r29)
    stw	r19, 0x14(r29)
    stw	r18, 0x18(r29)
    stw	r17, 0x28(r29)
    stw	r16, 0x2c(r29)
    stfs	f16, 0x10(r29)
    stfs	f17, 0x24(r29)
    stfs	f18, 0x38(r29)
    stw	r12, 0(r27)
    stw	r11, 4(r27)
    stw	r10, 0x14(r27)
    stw	r9, 0x18(r27)
    stw	r8, 0x28(r27)
    stw	r7, 0x2c(r27)
    stfs	f19, 0x10(r27)
    stfs	f20, 0x24(r27)
    stfs	f21, 0x38(r27)
    slwi	r31, r5, 2
    add	r31, r31, r4
    stfs	f25, 0x190(r31)
    lfd	f14, 0x60(r1)
    lfd	f15, 0x68(r1)
    lfd	f16, 0x70(r1)
    lfd	f17, 0x78(r1)
    lfd	f18, 0x80(r1)
    lfd	f19, 0x88(r1)
    lfd	f20, 0x90(r1)
    lfd	f21, 0x98(r1)
    lfd	f22, 0xa0(r1)
    lfd	f23, 0xa8(r1)
    lfd	f24, 0xb0(r1)
    lfd	f25, 0xb8(r1)
    lmw	r14, 8(r1)
    addi	r1, r1, 0xc0
    blr	
}

asm void fn_8002420C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    li	r0, 0
    mulli	r0, r0, 0x14
    add	r31, r29, r0
    li	r30, 0
    b       _8002423c
_8002423c:
    b       _80024240
_80024240:
    b       _8002425c
_80024244:
    lwz	r3, 0xc(r31)
    lwz	r12, -0x7ec4(r13)
    mtlr	r12
    blrl	
    addi	r31, r31, 0x14
    addi	r30, r30, 1
_8002425c:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 9
    blt     _80024244
    li	r30, 0
    mulli	r0, r30, 0x14
    add	r31, r29, r0
    b       _80024278
_80024278:
    b       _8002427c
_8002427c:
    b       _80024298
_80024280:
    lwz	r3, 0xc0(r31)
    lwz	r12, -0x7ec4(r13)
    mtlr	r12
    blrl	
    addi	r31, r31, 0x14
    addi	r30, r30, 1
_80024298:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 9
    blt     _80024280
    lwz	r0, 0x1a4(r29)
    cmpwi	r0, 0
    beq     _800242ec
    li	r30, 0
    slwi	r0, r30, 2
    add	r31, r29, r0
    b       _800242c0
_800242c0:
    b       _800242c4
_800242c4:
    b       _800242e0
_800242c8:
    lwz	r3, 0x1ac(r31)
    lwz	r12, -0x7ec4(r13)
    mtlr	r12
    blrl	
    addi	r31, r31, 4
    addi	r30, r30, 1
_800242e0:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 3
    blt     _800242c8
_800242ec:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

#pragma pop
