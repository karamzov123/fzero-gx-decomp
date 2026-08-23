#pragma push
#pragma force_active on

typedef int BOOL;
extern BOOL OSDisableInterrupts(void);
extern void axmix_heap_init(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void fn_8002420C(void);
extern void fn_80023B70(void);
extern void fn_80023D00(void);
extern void memset(void);
extern void fn_800885B8(void);
extern void fn_800244C8(void);
extern void fn_80024C88(void);
extern void fn_800248D4(void);
extern void fn_80025440(void);
extern unsigned char lbl_80128180[16];
extern unsigned char lbl_80128190[2048];

asm void fn_80024308(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    li	r0, 0
    stb	r0, 0x1c4(r31)
    mr	r30, r3
    mr	r3, r31
    lfs	f1, 0x1c8(r31)
    lfs	f2, 0x1d0(r31)
    lfs	f3, 0x1cc(r31)
    lfs	f4, 0x1d4(r31)
    lfs	f5, 0x1d8(r31)
    lfs	f6, 0x1dc(r31)
    bl      axmix_heap_init
    mr	r31, r3
    mr	r3, r30
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80024378(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    mr	r31, r3
    mr	r3, r30
    bl      fn_8002420C
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 1
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_800243C4(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x40(r1)
    stfd	f31, 0x38(r1)
    stfd	f30, 0x30(r1)
    stfd	f29, 0x28(r1)
    stmw	r27, 0x14(r1)
    mr	r27, r4
    lbz	r0, 0x1c4(r27)
    cmplwi	r0, 0
    bne     _800244a8
    lwz	r28, 8(r3)
    li	r31, 0
    lwz	r29, 4(r3)
    lwz	r30, 0(r3)
    b       _80024404
_80024404:
    lfs	f30, -0x7e84(r2)
    lfs	f31, -0x7ebc(r2)
    lfs	f29, -0x7ec0(r2)
    b       _80024414
_80024414:
    b       _8002449c
_80024418:
    clrlwi	r0, r31, 0x18
    cmpwi	r0, 1
    beq     _80024474
    bge     _80024434
    cmpwi	r0, 0
    bge     _80024440
    b       _80024498
_80024434:
    cmpwi	r0, 3
    bge     _80024498
    b       _80024488
_80024440:
    lfs	f0, 0x1a8(r27)
    fcmpu	cr0, f29, f0
    beq     _80024460
    fmuls	f1, f30, f0
    mr	r3, r30
    mr	r4, r29
    fsubs	f2, f31, f1
    bl      fn_80023B70
_80024460:
    mr	r3, r30
    mr	r4, r27
    li	r5, 0
    bl      fn_80023D00
    b       _80024498
_80024474:
    mr	r3, r29
    mr	r4, r27
    li	r5, 1
    bl      fn_80023D00
    b       _80024498
_80024488:
    mr	r3, r28
    mr	r4, r27
    li	r5, 2
    bl      fn_80023D00
_80024498:
    addi	r31, r31, 1
_8002449c:
    clrlwi	r0, r31, 0x18
    cmplwi	r0, 3
    blt     _80024418
_800244a8:
    lmw	r27, 0x14(r1)
    lwz	r0, 0x44(r1)
    lfd	f31, 0x38(r1)
    lfd	f30, 0x30(r1)
    lfd	f29, 0x28(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr	
}

asm void fn_800244C8(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0xa8(r1)
    stfd	f31, 0xa0(r1)
    fmr	f31, f5
    stfd	f30, 0x98(r1)
    stfd	f29, 0x90(r1)
    stfd	f28, 0x88(r1)
    fmr	f28, f2
    stfd	f27, 0x80(r1)
    fmr	f27, f4
    stfd	f26, 0x78(r1)
    fmr	f26, f3
    stfd	f25, 0x70(r1)
    fmr	f25, f1
    stmw	r19, 0x3c(r1)
    mr	r23, r3
    lfs	f6, -0x7e80(r2)
    fcmpo	cr0, f25, f6
    blt     _80024570
    lfs	f1, -0x7e7c(r2)
    fcmpo	cr0, f25, f1
    bgt     _80024570
    lfs	f0, -0x7e78(r2)
    fcmpo	cr0, f28, f0
    blt     _80024570
    lfs	f0, -0x7e74(r2)
    fcmpo	cr0, f28, f0
    bgt     _80024570
    fcmpo	cr0, f26, f6
    blt     _80024570
    fcmpo	cr0, f26, f1
    bgt     _80024570
    fcmpo	cr0, f27, f6
    blt     _80024570
    fcmpo	cr0, f27, f1
    bgt     _80024570
    fcmpo	cr0, f31, f6
    blt     _80024570
    lfs	f0, -0x7e70(r2)
    fcmpo	cr0, f31, f0
    ble     _80024578
_80024570:
    li	r3, 0
    b       _800248a4
_80024578:
    addi	r3, r23, 0
    li	r4, 0
    li	r5, 0x13c
    bl      memset
    lfs	f0, -0x7e6c(r2)
    lis     r3, lbl_80128180@ha
    lfs	f30, -0x7e80(r2)
    addi	r30, r3, lbl_80128180@l
    fmuls	f28, f0, f28
    lfd	f29, -0x7e60(r2)
    addi	r27, r23, 0
    li	r24, 0
    li	r28, 0
    lis	r31, 0x4330
    b       _800247b8
_800245b4:
    mulli	r21, r28, 0x14
    addi	r29, r30, 0
    slwi	r22, r28, 2
    li	r25, 0
    b       _800246c0
_800245c8:
    lwz	r3, 0(r29)
    add	r26, r23, r21
    addi	r20, r3, 2
    slwi	r19, r20, 2
    stw	r19, 0x80(r26)
    mr	r3, r19
    lwz	r12, -0x7ec8(r13)
    mtlr	r12
    blrl	
    stw	r3, 0x84(r26)
    addi	r5, r19, 0
    li	r4, 0
    lwz	r3, 0x84(r26)
    bl      memset
    stfs	f30, 0x88(r26)
    addi	r4, r26, 0x78
    srawi	r3, r20, 1
    lwz	r0, 0x78(r26)
    slwi	r3, r3, 2
    addi	r5, r26, 0x7c
    subf	r0, r3, r0
    stw	r0, 0x7c(r26)
    b       _80024634
_80024624:
    lwz	r3, 0x7c(r26)
    lwz	r0, 0x80(r26)
    add	r0, r3, r0
    stw	r0, 0x7c(r26)
_80024634:
    lwz	r0, 0x7c(r26)
    cmpwi	r0, 0
    blt     _80024624
    li	r0, 0
    stw	r0, 0(r4)
    stw	r0, 0(r5)
    lwz	r3, 0(r29)
    lwz	r0, 0(r4)
    slwi	r3, r3, 2
    subf	r0, r3, r0
    stw	r0, 0(r5)
    b       _80024674
_80024664:
    lwz	r3, 0x7c(r26)
    lwz	r0, 0x80(r26)
    add	r0, r3, r0
    stw	r0, 0x7c(r26)
_80024674:
    lwz	r0, 0x7c(r26)
    cmpwi	r0, 0
    blt     _80024664
    lwz	r0, 0(r29)
    lfs	f1, -0x7e74(r2)
    mulli	r0, r0, -3
    xoris	r0, r0, 0x8000
    stw	r0, 0x34(r1)
    stw	r31, 0x30(r1)
    lfd	f0, 0x30(r1)
    fsubs	f0, f0, f29
    fdivs	f2, f0, f28
    bl      fn_800885B8
    addi	r0, r22, 0xf4
    stfsx	f1, r23, r0
    addi	r29, r29, 4
    addi	r22, r22, 4
    addi	r21, r21, 0x14
    addi	r25, r25, 1
_800246c0:
    clrlwi	r0, r25, 0x18
    cmplwi	r0, 2
    blt     _800245c8
    mulli	r22, r28, 0x14
    addi	r29, r30, 0
    li	r25, 0
    b       _8002479c
_800246dc:
    lwz	r3, 8(r29)
    add	r26, r23, r22
    addi	r20, r3, 2
    slwi	r19, r20, 2
    stw	r19, 8(r26)
    mr	r3, r19
    lwz	r12, -0x7ec8(r13)
    mtlr	r12
    blrl	
    stw	r3, 0xc(r26)
    addi	r5, r19, 0
    li	r4, 0
    lwz	r3, 0xc(r26)
    bl      memset
    stfs	f30, 0x10(r26)
    srawi	r0, r20, 1
    slwi	r3, r0, 2
    lwz	r0, 0(r26)
    addi	r4, r26, 4
    subf	r0, r3, r0
    stw	r0, 4(r26)
    b       _80024744
_80024734:
    lwz	r3, 4(r26)
    lwz	r0, 8(r26)
    add	r0, r3, r0
    stw	r0, 4(r26)
_80024744:
    lwz	r0, 4(r26)
    cmpwi	r0, 0
    blt     _80024734
    li	r0, 0
    stw	r0, 0(r26)
    stw	r0, 0(r4)
    lwz	r3, 8(r29)
    lwz	r0, 0(r26)
    slwi	r3, r3, 2
    subf	r0, r3, r0
    stw	r0, 0(r4)
    b       _80024784
_80024774:
    lwz	r3, 4(r26)
    lwz	r0, 8(r26)
    add	r0, r3, r0
    stw	r0, 4(r26)
_80024784:
    lwz	r0, 4(r26)
    cmpwi	r0, 0
    blt     _80024774
    addi	r29, r29, 4
    addi	r22, r22, 0x14
    addi	r25, r25, 1
_8002479c:
    clrlwi	r0, r25, 0x18
    cmplwi	r0, 2
    blt     _800246dc
    stfs	f30, 0x10c(r27)
    addi	r28, r28, 2
    addi	r27, r27, 4
    addi	r24, r24, 1
_800247b8:
    clrlwi	r0, r24, 0x18
    cmplwi	r0, 3
    blt     _800245b4
    stfs	f25, 0xf0(r23)
    stfs	f26, 0x118(r23)
    stfs	f27, 0x11c(r23)
    lfs	f1, 0x11c(r23)
    lfs	f0, -0x7e68(r2)
    fcmpo	cr0, f1, f0
    bge     _800247e4
    stfs	f0, 0x11c(r23)
_800247e4:
    lfs	f1, -0x7e64(r2)
    lfs	f0, 0x11c(r23)
    lfs	f2, -0x7e68(r2)
    fmuls	f0, f1, f0
    lfs	f1, -0x7e7c(r2)
    fadds	f0, f2, f0
    fsubs	f0, f1, f0
    stfs	f0, 0x11c(r23)
    lfs	f0, -0x7e80(r2)
    fcmpu	cr0, f0, f31
    beq     _80024880
    lfs	f0, -0x7e6c(r2)
    addi	r20, r23, 0
    li	r19, 0
    fmuls	f0, f0, f31
    fctiwz	f0, f0
    stfd	f0, 0x30(r1)
    lwz	r0, 0x34(r1)
    stw	r0, 0x120(r23)
    b       _80024870
_80024834:
    lwz	r12, -0x7ec8(r13)
    lwz	r0, 0x120(r23)
    mtlr	r12
    slwi	r3, r0, 2
    blrl	
    stw	r3, 0x124(r20)
    li	r4, 0
    lwz	r0, 0x120(r23)
    lwz	r3, 0x124(r20)
    slwi	r5, r0, 2
    bl      memset
    lwz	r0, 0x124(r20)
    addi	r19, r19, 1
    stw	r0, 0x130(r20)
    addi	r20, r20, 4
_80024870:
    clrlwi	r0, r19, 0x18
    cmplwi	r0, 3
    blt     _80024834
    b       _800248a0
_80024880:
    li	r0, 0
    stw	r0, 0x120(r23)
    stw	r0, 0x130(r23)
    stw	r0, 0x124(r23)
    stw	r0, 0x134(r23)
    stw	r0, 0x128(r23)
    stw	r0, 0x138(r23)
    stw	r0, 0x12c(r23)
_800248a0:
    li	r3, 1
_800248a4:
    lmw	r19, 0x3c(r1)
    lwz	r0, 0xac(r1)
    lfd	f31, 0xa0(r1)
    lfd	f30, 0x98(r1)
    lfd	f29, 0x90(r1)
    lfd	f28, 0x88(r1)
    lfd	f27, 0x80(r1)
    lfd	f26, 0x78(r1)
    lfd	f25, 0x70(r1)
    addi	r1, r1, 0xa8
    mtlr	r0
    blr	
}

asm void fn_800248D4(void)
{
    nofralloc
    stwu	r1, -0x90(r1)
    stmw	r17, 8(r1)
    stfd	f14, 0x58(r1)
    stfd	f15, 0x60(r1)
    stfd	f16, 0x68(r1)
    stfd	f17, 0x70(r1)
    stfd	f18, 0x78(r1)
    stfd	f19, 0x80(r1)
    stfd	f20, 0x88(r1)
    lis	r31, -0x7fe6
    lfs	f6, 0x6fe8(r31)
    lis	r31, -0x7fe6
    lfs	f9, 0x6fec(r31)
    lis	r31, -0x7fe6
    lfd	f5, 0x6ff0(r31)
    lfs	f2, 0xf0(r4)
    lfs	f11, 0x11c(r4)
    lfs	f8, 0x118(r4)
    fmuls	f3, f8, f9
    fsubs	f4, f9, f3
    lis	r30, 0x4330
    stw	r30, 0x50(r1)
    li	r5, 0
_80024930:
    slwi	r31, r5, 3
    add	r31, r31, r4
    lfs	f19, 0xf4(r31)
    lfs	f20, 0xf8(r31)
    slwi	r31, r5, 2
    add	r31, r31, r4
    lfs	f7, 0x10c(r31)
    lwz	r27, 0x124(r31)
    lwz	r28, 0x130(r31)
    lwz	r31, 0x120(r4)
    addi	r22, r31, -1
    slwi	r22, r22, 2
    add	r22, r22, r27
    cmpwi	cr7, r31, 0
    mulli	r31, r5, 0x28
    addi	r29, r4, 0x78
    add	r29, r29, r31
    addi	r30, r4, 0
    add	r30, r30, r31
    lwz	r21, 0(r29)
    lwz	r20, 4(r29)
    lwz	r19, 0x14(r29)
    lwz	r18, 0x18(r29)
    lfs	f15, 0x10(r29)
    lfs	f16, 0x24(r29)
    lwz	r26, 8(r29)
    lwz	r25, 0x1c(r29)
    lwz	r7, 0xc(r29)
    lwz	r8, 0x20(r29)
    lwz	r12, 0(r30)
    lwz	r11, 4(r30)
    lwz	r10, 0x14(r30)
    lwz	r9, 0x18(r30)
    lfs	f17, 0x10(r30)
    lfs	f18, 0x24(r30)
    lwz	r24, 8(r30)
    lwz	r23, 0x1c(r30)
    lwz	r17, 0xc(r30)
    lwz	r6, 0x20(r30)
    lwz	r30, 0(r3)
    xoris	r30, r30, 0x8000
    stw	r30, 0x54(r1)
    lfd	f12, 0x50(r1)
    fsubs	f12, f12, f5
    li	r31, 0x9f
    mtctr	r31
_800249e8:
    fmr	f13, f12
    beq      cr7, _80024a08
    lfs	f13, 0(r28)
    addi	r28, r28, 4
    cmpw	r28, r22
    stfs	f12, -4(r28)
    bne+     cr0, _80024a08
    mr	r28, r27
_80024a08:
    fmadds	f8, f19, f15, f13
    lwzu	r29, 4(r3)
    fmadds	f9, f20, f16, f13
    stfsx	f8, r7, r21
    addi	r21, r21, 4
    stfsx	f9, r8, r19
    lfsx	f14, r7, r20
    addi	r20, r20, 4
    lfsx	f16, r8, r18
    cmpw	r21, r26
    cmpw	cr1, r20, r26
    addi	r19, r19, 4
    addi	r18, r18, 4
    fmr	f15, f14
    cmpw	cr5, r19, r25
    fadds	f14, f14, f16
    cmpw	cr6, r18, r25
    bne+     cr0, _80024a54
    li	r21, 0
_80024a54:
    xoris	r29, r29, 0x8000
    fmadds	f9, f2, f17, f14
    bne+     cr1, _80024a64
    li	r20, 0
_80024a64:
    stw	r29, 0x54(r1)
    bne+     cr5, _80024a70
    li	r19, 0
_80024a70:
    stfsx	f9, r17, r12
    fnmsubs	f14, f2, f9, f17
    addi	r12, r12, 4
    bne+     cr6, _80024a84
    li	r18, 0
_80024a84:
    lfsx	f17, r17, r11
    cmpw	cr5, r12, r24
    addi	r11, r11, 4
    cmpw	cr6, r11, r24
    bne+     cr5, _80024a9c
    li	r12, 0
_80024a9c:
    bne+     cr6, _80024aa4
    li	r11, 0
_80024aa4:
    fmuls	f14, f14, f6
    lfd	f10, 0x50(r1)
    fmadds	f14, f11, f7, f14
    fmadds	f9, f2, f18, f14
    fmr	f7, f14
    stfsx	f9, r6, r10
    fnmsubs	f14, f2, f9, f18
    fmuls	f8, f4, f12
    lfsx	f18, r6, r9
    addi	r10, r10, 4
    addi	r9, r9, 4
    fmadds	f14, f3, f14, f8
    cmpw	cr5, r10, r23
    cmpw	cr6, r9, r23
    fctiwz	f14, f14
    bne+     cr5, _80024ae8
    li	r10, 0
_80024ae8:
    bne+     cr6, _80024af0
    li	r9, 0
_80024af0:
    li	r31, -4
    fsubs	f12, f10, f5
    stfiwx	f14, r3, r31
    bdnz    _800249e8
    fmr	f13, f12
    beq      cr7, _80024b20
    lfs	f13, 0(r28)
    addi	r28, r28, 4
    cmpw	r28, r22
    stfs	f12, -4(r28)
    bne+     cr0, _80024b20
    mr	r28, r27
_80024b20:
    fmadds	f8, f19, f15, f13
    fmadds	f9, f20, f16, f13
    stfsx	f8, r7, r21
    addi	r21, r21, 4
    stfsx	f9, r8, r19
    lfsx	f14, r7, r20
    addi	r20, r20, 4
    lfsx	f16, r8, r18
    cmpw	r21, r26
    cmpw	cr1, r20, r26
    addi	r19, r19, 4
    addi	r18, r18, 4
    fmr	f15, f14
    cmpw	cr5, r19, r25
    fadds	f14, f14, f16
    cmpw	cr6, r18, r25
    bne+     cr0, _80024b68
    li	r21, 0
_80024b68:
    fmadds	f9, f2, f17, f14
    bne+     cr1, _80024b74
    li	r20, 0
_80024b74:
    bne+     cr5, _80024b7c
    li	r19, 0
_80024b7c:
    stfsx	f9, r17, r12
    fnmsubs	f14, f2, f9, f17
    addi	r12, r12, 4
    bne+     cr6, _80024b90
    li	r18, 0
_80024b90:
    lfsx	f17, r17, r11
    cmpw	cr5, r12, r24
    addi	r11, r11, 4
    cmpw	cr6, r11, r24
    bne+     cr5, _80024ba8
    li	r12, 0
_80024ba8:
    bne+     cr6, _80024bb0
    li	r11, 0
_80024bb0:
    fmuls	f14, f14, f6
    fmadds	f14, f11, f7, f14
    mulli	r31, r5, 0x28
    fmadds	f9, f2, f18, f14
    fmr	f7, f14
    addi	r29, r4, 0x78
    add	r29, r29, r31
    stfsx	f9, r6, r10
    fnmsubs	f14, f2, f9, f18
    fmuls	f8, f4, f12
    lfsx	f18, r6, r9
    addi	r10, r10, 4
    addi	r9, r9, 4
    fmadds	f14, f3, f14, f8
    cmpw	cr5, r10, r23
    cmpw	cr6, r9, r23
    fctiwz	f14, f14
    bne+     cr5, _80024bfc
    li	r10, 0
_80024bfc:
    bne+     cr6, _80024c04
    li	r9, 0
_80024c04:
    addi	r30, r4, 0
    add	r30, r30, r31
    stfiwx	f14, 0, r3
    stw	r21, 0(r29)
    stw	r20, 4(r29)
    stw	r19, 0x14(r29)
    stw	r18, 0x18(r29)
    addi	r3, r3, 4
    stfs	f15, 0x10(r29)
    stfs	f16, 0x24(r29)
    slwi	r31, r5, 2
    add	r31, r31, r4
    addi	r5, r5, 1
    stw	r12, 0(r30)
    stw	r11, 4(r30)
    stw	r10, 0x14(r30)
    stw	r9, 0x18(r30)
    cmpwi	r5, 3
    stfs	f17, 0x10(r30)
    stfs	f18, 0x24(r30)
    stfs	f7, 0x10c(r31)
    stw	r28, 0x130(r31)
    bne     _80024930
    lfd	f14, 0x58(r1)
    lfd	f15, 0x60(r1)
    lfd	f16, 0x68(r1)
    lfd	f17, 0x70(r1)
    lfd	f18, 0x78(r1)
    lfd	f19, 0x80(r1)
    lfd	f20, 0x88(r1)
    lmw	r17, 8(r1)
    addi	r1, r1, 0x90
    blr	
}

asm void fn_80024C88(void)
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
    b       _80024cb8
_80024cb8:
    b       _80024cbc
_80024cbc:
    b       _80024cd8
_80024cc0:
    lwz	r3, 0xc(r31)
    lwz	r12, -0x7ec4(r13)
    mtlr	r12
    blrl	
    addi	r31, r31, 0x14
    addi	r30, r30, 1
_80024cd8:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 6
    blt     _80024cc0
    li	r30, 0
    mulli	r0, r30, 0x14
    add	r31, r29, r0
    b       _80024cf4
_80024cf4:
    b       _80024cf8
_80024cf8:
    b       _80024d14
_80024cfc:
    lwz	r3, 0x84(r31)
    lwz	r12, -0x7ec4(r13)
    mtlr	r12
    blrl	
    addi	r31, r31, 0x14
    addi	r30, r30, 1
_80024d14:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 6
    blt     _80024cfc
    lwz	r0, 0x120(r29)
    cmpwi	r0, 0
    beq     _80024d68
    li	r30, 0
    slwi	r0, r30, 2
    add	r31, r29, r0
    b       _80024d3c
_80024d3c:
    b       _80024d40
_80024d40:
    b       _80024d5c
_80024d44:
    lwz	r3, 0x124(r31)
    lwz	r12, -0x7ec4(r13)
    mtlr	r12
    blrl	
    addi	r31, r31, 4
    addi	r30, r30, 1
_80024d5c:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 3
    blt     _80024d44
_80024d68:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_80024D84(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    li	r0, 0
    stb	r0, 0x13c(r31)
    mr	r30, r3
    mr	r3, r31
    lfs	f1, 0x140(r31)
    lfs	f2, 0x148(r31)
    lfs	f3, 0x144(r31)
    lfs	f4, 0x14c(r31)
    lfs	f5, 0x150(r31)
    bl      fn_800244C8
    mr	r31, r3
    mr	r3, r30
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80024DF0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    mr	r31, r3
    mr	r3, r30
    bl      fn_80024C88
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 1
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80024E3C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lbz	r0, 0x13c(r4)
    cmplwi	r0, 0
    bne     _80024e5c
    lwz	r3, 0(r3)
    bl      fn_800248D4
_80024e5c:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_80024E6C(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    stmw	r26, 0x28(r1)
    lwz	r4, 0xc(r3)
    lwz	r5, 0x10(r3)
    lwz	r6, 0x14(r3)
    lwz	r8, 0x1c(r3)
    lwz	r7, 0x20(r3)
    lwz	r31, 4(r3)
    lwz	r30, 0(r3)
    lwz	r9, 8(r3)
    lis	r10, 0x4330
    stw	r10, 8(r1)
    stw	r10, 0x10(r1)
    stw	r10, 0x18(r1)
    stw	r10, 0x20(r1)
    lis	r10, -0x7fe6
    lfd	f9, 0x6ff8(r10)
    slwi	r10, r5, 2
    lwz	r11, 0(r9)
    lwz	r29, 4(r9)
    lwz	r28, 8(r9)
    lwzx	r27, r31, r10
    xoris	r11, r11, 0x8000
    xoris	r29, r29, 0x8000
    stw	r11, 0xc(r1)
    xoris	r28, r28, 0x8000
    stw	r29, 0x14(r1)
    xoris	r27, r27, 0x8000
    stw	r28, 0x1c(r1)
    lfd	f1, 8(r1)
    stw	r27, 0x24(r1)
    lfd	f2, 0x10(r1)
    fsubs	f1, f1, f9
    lfd	f3, 0x18(r1)
    fsubs	f2, f2, f9
    lfd	f4, 0x20(r1)
    fsubs	f3, f3, f9
    fsubs	f4, f4, f9
    li	r26, -4
    lis     r12, lbl_80128190@ha
    addi	r12, r12, lbl_80128190@l
    li	r9, 0xa0
    mtctr	r9
_80024f18:
    rlwinm	r10, r4, 7, 0x15, 0x1b
    addc	r4, r4, r6
    add	r10, r10, r12
    mcrxr	cr0
    lfs	f5, 0(r10)
    beq     _80024f60
    lfs	f6, 4(r10)
    fmuls	f10, f1, f5
    lfs	f7, 8(r10)
    fmadds	f10, f2, f6, f10
    lfs	f8, 0xc(r10)
    fmadds	f10, f3, f7, f10
    addi	r30, r30, 4
    fmadds	f10, f4, f8, f10
    fctiwz	f10, f10
    stfiwx	f10, r26, r30
    bdnz    _80024f18
    b       _80024fcc
_80024f60:
    addi	r5, r5, 1
    lfs	f6, 4(r10)
    fmuls	f10, f1, f5
    cmpw	r5, r8
    fmr	f1, f2
    lfs	f7, 8(r10)
    fmadds	f10, f2, f6, f10
    fmr	f2, f3
    lfs	f8, 0xc(r10)
    fmadds	f10, f3, f7, f10
    addi	r30, r30, 4
    fmr	f3, f4
    bne+     cr0, _80024f98
    mr	r5, r7
_80024f98:
    fmadds	f10, f4, f8, f10
    slwi	r9, r5, 2
    bdz     _80024fc4
    lwzx	r10, r9, r31
    fctiwz	f10, f10
    xoris	r10, r10, 0x8000
    stw	r10, 0xc(r1)
    stfiwx	f10, r26, r30
    lfd	f4, 8(r1)
    fsubs	f4, f4, f9
    b       _80024f18
_80024fc4:
    fctiwz	f10, f10
    stfiwx	f10, r26, r30
_80024fcc:
    lwz	r9, 8(r3)
    fctiwz	f1, f1
    fctiwz	f2, f2
    fctiwz	f3, f3
    stfiwx	f1, 0, r9
    addi	r10, r9, 4
    stfiwx	f2, 0, r10
    addi	r10, r9, 8
    stfiwx	f3, 0, r10
    stw	r4, 0xc(r3)
    stw	r5, 0x10(r3)
    lmw	r26, 0x28(r1)
    addi	r1, r1, 0x40
    blr	
}

asm void fn_80025004(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    stmw	r26, 0x28(r1)
    lwz	r4, 0xc(r3)
    lwz	r5, 0x10(r3)
    lwz	r6, 0x14(r3)
    lwz	r8, 0x1c(r3)
    lwz	r7, 0x20(r3)
    lwz	r31, 4(r3)
    lwz	r30, 0(r3)
    lwz	r9, 8(r3)
    lis	r10, 0x4330
    stw	r10, 8(r1)
    stw	r10, 0x10(r1)
    stw	r10, 0x18(r1)
    stw	r10, 0x20(r1)
    lis	r10, -0x7fe6
    lfd	f9, 0x6ff8(r10)
    slwi	r10, r5, 2
    lwz	r11, 0(r9)
    lwz	r29, 4(r9)
    lwz	r28, 8(r9)
    lwzx	r27, r31, r10
    xoris	r11, r11, 0x8000
    xoris	r29, r29, 0x8000
    stw	r11, 0xc(r1)
    xoris	r28, r28, 0x8000
    stw	r29, 0x14(r1)
    xoris	r27, r27, 0x8000
    stw	r28, 0x1c(r1)
    lfd	f1, 8(r1)
    stw	r27, 0x24(r1)
    lfd	f2, 0x10(r1)
    fsubs	f1, f1, f9
    lfd	f3, 0x18(r1)
    fsubs	f2, f2, f9
    lfd	f4, 0x20(r1)
    fsubs	f3, f3, f9
    fsubs	f4, f4, f9
    li	r26, -4
    lis     r12, lbl_80128190@ha
    addi	r12, r12, lbl_80128190@l
    li	r9, 0xa0
    mtctr	r9
_800250b0:
    rlwinm	r10, r4, 7, 0x15, 0x1b
    addc	r4, r4, r6
    add	r10, r10, r12
    mcrxr	cr0
    addi	r5, r5, 1
    lfs	f5, 0(r10)
    beq     _8002512c
    lfs	f6, 4(r10)
    fmuls	f10, f1, f5
    cmpw	r5, r8
    fmr	f1, f2
    lfs	f7, 8(r10)
    fmadds	f10, f2, f6, f10
    fmr	f2, f3
    lfs	f8, 0xc(r10)
    fmadds	f10, f3, f7, f10
    addi	r30, r30, 4
    fmr	f3, f4
    bne+     cr0, _80025100
    mr	r5, r7
_80025100:
    fmadds	f10, f4, f8, f10
    slwi	r9, r5, 2
    bdz     _800251b0
    lwzx	r10, r9, r31
    fctiwz	f10, f10
    xoris	r10, r10, 0x8000
    stw	r10, 0xc(r1)
    stfiwx	f10, r26, r30
    lfd	f4, 8(r1)
    fsubs	f4, f4, f9
    b       _800250b0
_8002512c:
    cmpw	r5, r8
    lfs	f6, 4(r10)
    bne+     cr0, _8002513c
    mr	r5, r7
_8002513c:
    slwi	r11, r5, 2
    addi	r5, r5, 1
    lwzx	r29, r11, r31
    fmuls	f10, f1, f5
    cmpw	r5, r8
    xoris	r29, r29, 0x8000
    fmr	f1, f3
    lfs	f7, 8(r10)
    stw	r29, 0xc(r1)
    fmadds	f10, f2, f6, f10
    lfs	f8, 0xc(r10)
    fmadds	f10, f3, f7, f10
    lfd	f3, 8(r1)
    fmr	f2, f4
    addi	r30, r30, 4
    fsubs	f3, f3, f9
    bne+     cr0, _80025184
    mr	r5, r7
_80025184:
    fmadds	f10, f4, f8, f10
    slwi	r9, r5, 2
    bdz     _800251b0
    lwzx	r10, r9, r31
    fctiwz	f10, f10
    xoris	r10, r10, 0x8000
    stw	r10, 0xc(r1)
    stfiwx	f10, r26, r30
    lfd	f4, 8(r1)
    fsubs	f4, f4, f9
    b       _800250b0
_800251b0:
    fctiwz	f10, f10
    stfiwx	f10, r26, r30
    lwz	r9, 8(r3)
    fctiwz	f1, f1
    fctiwz	f2, f2
    fctiwz	f3, f3
    stfiwx	f1, 0, r9
    addi	r10, r9, 4
    stfiwx	f2, 0, r10
    addi	r10, r9, 8
    stfiwx	f3, 0, r10
    stw	r4, 0xc(r3)
    stw	r5, 0x10(r3)
    lmw	r26, 0x28(r1)
    addi	r1, r1, 0x40
    blr	
}

asm void fn_800251F0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lwz	r12, -0x7ec8(r13)
    mr	r31, r3
    li	r3, 0x1680
    mtlr	r12
    blrl	
    stw	r3, 0(r30)
    lwz	r3, 0(r30)
    cmplwi	r3, 0
    beq     _800253cc
    addi	r0, r3, 0x780
    stw	r0, 0xc(r30)
    lwz	r3, 0xc(r30)
    addi	r0, r3, 0x780
    stw	r0, 0x18(r30)
    lwz	r3, 0(r30)
    addi	r0, r3, 0x280
    stw	r0, 4(r30)
    lwz	r3, 0xc(r30)
    addi	r0, r3, 0x280
    stw	r0, 0x10(r30)
    lwz	r3, 0x18(r30)
    addi	r0, r3, 0x280
    stw	r0, 0x1c(r30)
    lwz	r3, 0(r30)
    addi	r0, r3, 0x500
    stw	r0, 8(r30)
    lwz	r3, 0xc(r30)
    addi	r0, r3, 0x500
    stw	r0, 0x14(r30)
    lwz	r3, 0x18(r30)
    addi	r0, r3, 0x500
    stw	r0, 0x20(r30)
    lwz	r3, 0(r30)
    lwz	r5, 0xc(r30)
    lwz	r6, 0x18(r30)
    b       _8002529c
_8002529c:
    li	r0, 0x28
    mtctr	r0
    b       _800252a8
_800252a8:
    b       _800252ac
_800252ac:
    li	r4, 0
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    stw	r4, 0(r3)
    addi	r3, r3, 4
    stw	r4, 0(r5)
    addi	r5, r5, 4
    stw	r4, 0(r6)
    addi	r6, r6, 4
    bdnz    _800252ac
    li	r0, 1
    stb	r0, 0x24(r30)
    li	r0, 0x1e0
    mr	r3, r31
    stw	r4, 0x34(r30)
    stw	r4, 0x30(r30)
    stw	r4, 0x2c(r30)
    stw	r4, 0x28(r30)
    stw	r4, 0x44(r30)
    stw	r4, 0x40(r30)
    stw	r4, 0x3c(r30)
    stw	r4, 0x38(r30)
    stw	r4, 0x54(r30)
    stw	r4, 0x50(r30)
    stw	r4, 0x4c(r30)
    stw	r4, 0x48(r30)
    stw	r0, 0x88(r30)
    stw	r4, 0x8c(r30)
    bl      OSRestoreInterrupts
    mr	r3, r30
    bl      fn_80025440
    b       _800253d8
_800253cc:
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 0
_800253d8:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void fn_800253F0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, 0(r31)
    lwz	r12, -0x7ec4(r13)
    mr	r31, r0
    mtlr	r12
    blrl	
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 1
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80025440(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lwz	r6, 0x90(r31)
    lis	r4, -0x3333
    lis	r5, -0x7777
    addi	r0, r6, -5
    slwi	r0, r0, 5
    subfic	r0, r0, 0x140
    stw	r0, 0x5c(r31)
    li	r0, 0
    addi	r4, r4, -0x3333
    stw	r0, 0x58(r31)
    addi	r0, r5, -0x7777
    lbz	r5, 0x24(r31)
    lwz	r6, 0x5c(r31)
    addi	r5, r5, -1
    mulli	r5, r5, 0xa0
    add	r5, r6, r5
    mulhwu	r0, r0, r5
    srwi	r0, r0, 8
    mulli	r0, r0, 0x1e0
    subf	r0, r0, r5
    stw	r0, 0x5c(r31)
    lwz	r0, 0x98(r31)
    mulhwu	r0, r4, r0
    srwi	r4, r0, 2
    addi	r0, r4, 1
    rlwinm	r0, r0, 0, 0, 0x1e
    stw	r0, 0x68(r31)
    lwz	r0, 0x68(r31)
    srwi	r0, r0, 1
    stw	r0, 0x64(r31)
    lwz	r0, 0x68(r31)
    lwz	r4, 0x94(r31)
    mulli	r0, r0, 5
    slwi	r4, r4, 0x10
    divwu	r0, r4, r0
    stw	r0, 0x60(r31)
    bl      OSRestoreInterrupts
    li	r3, 1
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

#pragma pop
