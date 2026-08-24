extern void fn_8006D1C4(void);
extern void sqrtf(void);
extern void fn_8006D188(void);
extern void fn_8006D0E8(void);
extern void _savegpr_25(void);
extern void _restgpr_25(void);

#pragma push
#pragma force_active on

asm void PSMTXRotTrig(void);
asm void fn_8006E398(void);
asm void fn_8006E424(void);
asm void C_MTXQuat(void);
asm void fn_8006E540(void);
asm void fn_8006E5B4(void);
asm void fn_8006E5FC(void);
asm void fn_8006E7E4(void);
asm void fn_8006E8DC(void);
asm void PSMTXQuat_toQuat(void);

asm void PSMTXRotTrig(void)
{
    nofralloc
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    ps_merge00	f0, f2, f1
    psq_l	f3, 0x4(r4), 0, 0
    psq_l	f4, 0x14(r4), 0, 0
    psq_l	f5, 0x24(r4), 0, 0
    ps_mul	f6, f3, f0
    ps_mul	f7, f4, f0
    ps_mul	f8, f5, f0
    fneg	f1, f1
    ps_sum0	f6, f6, f6, f6
    ps_sum0	f7, f7, f7, f7
    ps_sum0	f8, f8, f8, f8
    ps_merge00	f0, f1, f2
    stfs	f6, 4(r4)
    ps_mul	f6, f3, f0
    stfs	f7, 0x14(r4)
    ps_mul	f7, f4, f0
    stfs	f8, 0x24(r4)
    ps_mul	f8, f5, f0
    ps_sum0	f6, f6, f6, f6
    stfs	f6, 8(r4)
    ps_sum0	f7, f7, f7, f7
    stfs	f7, 0x18(r4)
    ps_sum0	f8, f8, f8, f8
    stfs	f8, 0x28(r4)
    blr	
}

asm void fn_8006E398(void)
{
    nofralloc
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    ps_merge00	f0, f1, f2
    lfs	f3, 0(r4)
    lfs	f6, 8(r4)
    lfs	f4, 0x10(r4)
    lfs	f7, 0x18(r4)
    lfs	f5, 0x20(r4)
    lfs	f8, 0x28(r4)
    ps_merge00	f3, f3, f6
    ps_merge00	f4, f4, f7
    ps_merge00	f5, f5, f8
    ps_mul	f6, f3, f0
    ps_mul	f7, f4, f0
    ps_mul	f8, f5, f0
    fneg	f1, f1
    ps_sum0	f6, f6, f6, f6
    ps_sum0	f7, f7, f7, f7
    ps_sum0	f8, f8, f8, f8
    ps_merge00	f0, f2, f1
    stfs	f6, 8(r4)
    ps_mul	f6, f3, f0
    stfs	f7, 0x18(r4)
    ps_mul	f7, f4, f0
    stfs	f8, 0x28(r4)
    ps_mul	f8, f5, f0
    ps_sum0	f6, f6, f6, f6
    stfs	f6, 0(r4)
    ps_sum0	f7, f7, f7, f7
    stfs	f7, 0x10(r4)
    ps_sum0	f8, f8, f8, f8
    stfs	f8, 0x20(r4)
    blr	
}

asm void fn_8006E424(void)
{
    nofralloc
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    ps_merge00	f0, f2, f1
    psq_l	f3, 0x0(r4), 0, 0
    psq_l	f4, 0x10(r4), 0, 0
    psq_l	f5, 0x20(r4), 0, 0
    ps_mul	f6, f3, f0
    ps_mul	f7, f4, f0
    ps_mul	f8, f5, f0
    fneg	f1, f1
    ps_sum0	f6, f6, f6, f6
    ps_sum0	f7, f7, f7, f7
    ps_sum0	f8, f8, f8, f8
    ps_merge00	f0, f1, f2
    stfs	f6, 0(r4)
    ps_mul	f6, f3, f0
    stfs	f7, 0x10(r4)
    ps_mul	f7, f4, f0
    stfs	f8, 0x20(r4)
    ps_mul	f8, f5, f0
    ps_sum0	f6, f6, f6, f6
    stfs	f6, 4(r4)
    ps_sum0	f7, f7, f7, f7
    stfs	f7, 0x14(r4)
    ps_sum0	f8, f8, f8, f8
    stfs	f8, 0x24(r4)
    blr	
}

asm void C_MTXQuat(void)
{
    nofralloc
    lis	r4, -0x2000
    lfs	f0, 0(r3)
    lfs	f1, 4(r3)
    lfs	f5, 0x19c(r4)
    lfs	f2, 8(r3)
    fsubs	f4, f5, f5
    lfs	f3, 0xc(r3)
    fadds	f6, f5, f5
    stfs	f4, 0xc(r4)
    stfs	f4, 0x1c(r4)
    stfs	f4, 0x2c(r4)
    fmuls	f9, f0, f0
    fmuls	f7, f1, f1
    fmuls	f8, f2, f2
    fmadds	f9, f2, f2, f9
    fmadds	f7, f0, f0, f7
    fmadds	f8, f1, f1, f8
    fnmsubs	f9, f9, f6, f5
    stfs	f9, 0x14(r4)
    fnmsubs	f7, f7, f6, f5
    stfs	f7, 0x28(r4)
    fnmsubs	f8, f8, f6, f5
    stfs	f8, 0(r4)
    fadds	f6, f0, f0
    fadds	f4, f1, f1
    fadds	f5, f2, f2
    fmuls	f6, f3, f6
    fmuls	f7, f3, f4
    fmuls	f8, f3, f5
    fmsubs	f9, f1, f5, f6
    stfs	f9, 0x18(r4)
    fmadds	f10, f1, f5, f6
    stfs	f10, 0x24(r4)
    fmsubs	f11, f0, f5, f7
    stfs	f11, 0x20(r4)
    fmadds	f12, f0, f5, f7
    stfs	f12, 8(r4)
    fmsubs	f13, f0, f4, f8
    stfs	f13, 4(r4)
    fmadds	f2, f0, f4, f8
    stfs	f2, 0x10(r4)
    blr	
}

asm void fn_8006E540(void)
{
    nofralloc
    lfs	f4, 0(r4)
    lfs	f5, 4(r4)
    lfs	f6, 8(r4)
    lfs	f7, 0xc(r4)
    lfs	f8, 0(r5)
    lfs	f9, 4(r5)
    lfs	f10, 8(r5)
    lfs	f11, 0xc(r5)
    fmul	f0, f6, f9
    fmul	f1, f4, f10
    fmul	f2, f5, f8
    fmul	f3, f6, f10
    fmsubs	f0, f5, f10, f0
    fmsubs	f1, f6, f8, f1
    fmsubs	f2, f4, f9, f2
    fmadds	f3, f5, f9, f3
    fmadds	f0, f4, f11, f0
    fmadds	f1, f5, f11, f1
    fmadds	f2, f6, f11, f2
    fmadds	f3, f4, f8, f3
    fmadds	f0, f7, f8, f0
    fmadds	f1, f7, f9, f1
    fmadds	f2, f7, f10, f2
    fmsubs	f3, f7, f11, f3
    stfs	f0, 0(r3)
    stfs	f1, 4(r3)
    stfs	f2, 8(r3)
    stfs	f3, 0xc(r3)
    blr	
}

asm void fn_8006E5B4(void)
{
    nofralloc
    ps_merge00	f0, f0, f1
    ps_merge00	f1, f2, f3
    b       _8006e5c8
    psq_l	f0, 0x0(r3), 0, 0
    psq_l	f1, 0x8(r3), 0, 0
_8006e5c8:
    lis	r5, -0x2000
    ps_mul	f2, f0, f0
    ps_madd	f2, f1, f1, f2
    ps_sum0	f2, f2, f2, f2
    lfs	f4, 0x198(r5)
    fcmpu	cr0, f2, f4
    blt     _8006e5f0
    ps_merge00	f2, f2, f2
    ps_mul	f0, f0, f2
    ps_mul	f1, f1, f2
_8006e5f0:
    psq_st	f0, 0x0(r3), 0, 0
    psq_st	f1, 0x8(r3), 0, 0
    blr	
}

asm void fn_8006E5FC(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    addi	r11, r1, 0x50
    bl      _savegpr_25
    lwz	r6, -0x76c0(r13)
    lis	r4, -0x7ff7
    addi	r5, r4, 0x4e10
    lfs	f0, -0x7a6c(r2)
    lfs	f2, 0(r6)
    mr	r31, r3
    lfs	f3, 0x14(r6)
    lwz	r4, 0(r5)
    fadds	f1, f2, f3
    lfs	f4, 0x28(r6)
    lwz	r3, 4(r5)
    lwz	r0, 8(r5)
    fadds	f1, f4, f1
    stw	r4, 8(r1)
    stw	r3, 0xc(r1)
    fcmpo	cr0, f1, f0
    stw	r0, 0x10(r1)
    ble     _8006e6c0
    lfs	f0, -0x7a68(r2)
    fadds	f1, f0, f1
    bl      sqrtf
    lfs	f0, -0x7a64(r2)
    fdivs	f2, f0, f1
    fmuls	f0, f0, f1
    stfs	f0, 0xc(r31)
    lwz	r3, -0x76c0(r13)
    lfs	f1, 0x24(r3)
    lfs	f0, 0x18(r3)
    fsubs	f0, f1, f0
    fmuls	f0, f2, f0
    stfs	f0, 0(r31)
    lwz	r3, -0x76c0(r13)
    lfs	f1, 8(r3)
    lfs	f0, 0x20(r3)
    fsubs	f0, f1, f0
    fmuls	f0, f2, f0
    stfs	f0, 4(r31)
    lwz	r3, -0x76c0(r13)
    lfs	f1, 0x10(r3)
    lfs	f0, 4(r3)
    fsubs	f0, f1, f0
    fmuls	f0, f2, f0
    stfs	f0, 8(r31)
    b       _8006e7cc
_8006e6c0:
    fcmpo	cr0, f3, f2
    li	r5, 0
    ble     _8006e6d0
    li	r5, 1
_8006e6d0:
    slwi	r3, r5, 4
    slwi	r0, r5, 2
    add	r0, r3, r0
    lfsx	f0, r6, r0
    fcmpo	cr0, f4, f0
    ble     _8006e6ec
    li	r5, 2
_8006e6ec:
    slwi	r29, r5, 2
    addi	r4, r1, 8
    lwzx	r0, r4, r29
    slwi	r25, r5, 4
    add	r3, r25, r29
    lfs	f3, -0x7a68(r2)
    slwi	r30, r0, 2
    slwi	r27, r0, 4
    lwzx	r4, r4, r30
    add	r0, r27, r30
    lfsx	f1, r6, r0
    slwi	r26, r4, 4
    slwi	r28, r4, 2
    add	r0, r26, r28
    lfsx	f2, r6, r3
    lfsx	f0, r6, r0
    fadds	f0, f1, f0
    fsubs	f0, f2, f0
    fadds	f1, f3, f0
    bl      sqrtf
    lfs	f3, -0x7a64(r2)
    addi	r3, r1, 0x14
    lfs	f0, -0x7a6c(r2)
    fmuls	f2, f3, f1
    fcmpu	cr0, f0, f1
    stfsx	f2, r3, r29
    beq     _8006e75c
    fdivs	f1, f3, f1
_8006e75c:
    lwz	r0, -0x76c0(r13)
    addi	r3, r1, 0x14
    add	r6, r0, r26
    add	r4, r0, r27
    lfsx	f2, r6, r30
    add	r5, r0, r25
    lfsx	f0, r4, r28
    lfsx	f3, r4, r29
    fsubs	f4, f2, f0
    lfsx	f0, r5, r30
    lfsx	f2, r6, r29
    fadds	f3, f3, f0
    lfsx	f0, r5, r28
    fmuls	f4, f1, f4
    fadds	f0, f2, f0
    fmuls	f2, f1, f3
    stfs	f4, 0x20(r1)
    fmuls	f0, f1, f0
    stfsx	f2, r3, r30
    stfsx	f0, r3, r28
    lfs	f1, 0x14(r1)
    lfs	f0, 0x18(r1)
    stfs	f1, 0(r31)
    lfs	f1, 0x1c(r1)
    stfs	f0, 4(r31)
    lfs	f0, 0x20(r1)
    stfs	f1, 8(r31)
    stfs	f0, 0xc(r31)
_8006e7cc:
    addi	r11, r1, 0x50
    bl      _restgpr_25
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_8006E7E4(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stfd	f31, 0x30(r1)
    psq_st	f31, 0x38(r1), 0, 0
    stfd	f30, 0x20(r1)
    psq_st	f30, 0x28(r1), 0, 0
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r30, r4
    lfs	f0, -0x7a70(r2)
    lfs	f1, 0(r4)
    mr	r29, r3
    lfs	f2, 4(r4)
    fmuls	f30, f1, f1
    lfs	f1, 8(r4)
    fmadds	f30, f2, f2, f30
    fmadds	f30, f1, f1, f30
    fcmpo	cr0, f30, f0
    bge     _8006e854
    lfs	f1, -0x7a6c(r2)
    lfs	f0, -0x7a68(r2)
    stfs	f1, 0(r29)
    stfs	f1, 4(r29)
    stfs	f1, 8(r29)
    stfs	f0, 0xc(r29)
    b       _8006e8b0
_8006e854:
    extsh	r31, r5
    srawi	r0, r31, 1
    extsh	r3, r0
    bl      fn_8006D188
    fmr	f31, f1
    fmr	f1, f30
    bl      fn_8006D0E8
    fmuls	f1, f1, f31
    lfs	f0, 0(r30)
    srawi	r0, r31, 1
    extsh	r3, r0
    fmuls	f0, f0, f1
    addi	r0, r3, 0x4000
    extsh	r3, r0
    stfs	f0, 0(r29)
    lfs	f0, 4(r30)
    fmuls	f0, f0, f1
    stfs	f0, 4(r29)
    lfs	f0, 8(r30)
    fmuls	f0, f0, f1
    stfs	f0, 8(r29)
    bl      fn_8006D188
    stfs	f1, 0xc(r29)
_8006e8b0:
    psq_l	f31, 0x38(r1), 0, 0
    lfd	f31, 0x30(r1)
    psq_l	f30, 0x28(r1), 0, 0
    lfd	f30, 0x20(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r0, 0x44(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8006E8DC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lfs	f0, -0x7a6c(r2)
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lfs	f2, 0(r3)
    lfs	f1, 4(r3)
    fmuls	f2, f2, f2
    lfs	f3, 8(r3)
    fmuls	f1, f1, f1
    lfs	f4, 0xc(r3)
    fmuls	f3, f3, f3
    fmuls	f4, f4, f4
    fadds	f1, f2, f1
    fadds	f1, f3, f1
    fadds	f1, f4, f1
    fcmpo	cr0, f1, f0
    ble     _8006e930
    bl      fn_8006D0E8
    b       _8006e934
_8006e930:
    lfs	f1, -0x7a68(r2)
_8006e934:
    lfs	f0, 0(r31)
    fmuls	f0, f0, f1
    stfs	f0, 0(r31)
    lfs	f0, 4(r31)
    fmuls	f0, f0, f1
    stfs	f0, 4(r31)
    lfs	f0, 8(r31)
    fmuls	f0, f0, f1
    stfs	f0, 8(r31)
    lfs	f0, 0xc(r31)
    fmuls	f0, f0, f1
    stfs	f0, 0xc(r31)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void PSMTXQuat_toQuat(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stfd	f31, 0x40(r1)
    psq_st	f31, 0x48(r1), 0, 0
    stfd	f30, 0x30(r1)
    psq_st	f30, 0x38(r1), 0, 0
    stfd	f29, 0x20(r1)
    psq_st	f29, 0x28(r1), 0, 0
    stfd	f28, 0x10(r1)
    psq_st	f28, 0x18(r1), 0, 0
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r31, r4
    lfs	f9, 0(r5)
    lfs	f4, 0(r4)
    mr	r30, r3
    lfs	f5, 4(r4)
    lfs	f6, 4(r5)
    fmuls	f2, f4, f9
    lfs	f7, 8(r4)
    fmuls	f1, f5, f6
    lfs	f8, 8(r5)
    lfs	f0, -0x7a60(r2)
    fmuls	f3, f7, f8
    fadds	f1, f2, f1
    fadds	f30, f3, f1
    fcmpo	cr0, f30, f0
    ble     _8006ea08
    lfs	f1, -0x7a6c(r2)
    lfs	f0, -0x7a68(r2)
    stfs	f1, 8(r30)
    stfs	f1, 4(r30)
    stfs	f1, 0(r30)
    stfs	f0, 0xc(r30)
    b       _8006eb14
_8006ea08:
    lfs	f0, -0x7a5c(r2)
    fcmpo	cr0, f30, f0
    bge     _8006ea88
    fneg	f30, f5
    lfs	f28, -0x7a6c(r2)
    fmuls	f1, f4, f4
    fmr	f29, f4
    fmuls	f0, f30, f30
    fadds	f1, f1, f0
    bl      sqrtf
    lfd	f0, -0x7a58(r2)
    fcmpo	cr0, f1, f0
    bge     _8006ea4c
    lfs	f0, 8(r31)
    lfs	f29, -0x7a6c(r2)
    fneg	f28, f0
    lfs	f30, 0(r31)
_8006ea4c:
    fmuls	f1, f28, f28
    fmuls	f0, f29, f29
    fmuls	f2, f30, f30
    fadds	f0, f1, f0
    fadds	f1, f2, f0
    bl      fn_8006D0E8
    fmuls	f28, f28, f1
    lfs	f0, -0x7a6c(r2)
    fmuls	f29, f29, f1
    fmuls	f30, f30, f1
    stfs	f28, 0(r30)
    stfs	f29, 4(r30)
    stfs	f30, 8(r30)
    stfs	f0, 0xc(r30)
    b       _8006eb14
_8006ea88:
    fmuls	f3, f5, f8
    fmuls	f2, f7, f6
    fmuls	f1, f7, f9
    fmuls	f0, f4, f8
    fsubs	f31, f3, f2
    fmuls	f3, f4, f6
    fsubs	f29, f1, f0
    fmuls	f2, f5, f9
    fmuls	f1, f31, f31
    fmuls	f0, f29, f29
    fsubs	f28, f3, f2
    fadds	f0, f1, f0
    fmuls	f1, f28, f28
    fadds	f1, f1, f0
    bl      fn_8006D0E8
    lfs	f0, -0x7a68(r2)
    fmuls	f31, f31, f1
    lfs	f2, -0x7a64(r2)
    fmuls	f29, f29, f1
    fsubs	f0, f0, f30
    fmuls	f28, f28, f1
    fmuls	f1, f2, f0
    bl      sqrtf
    fmuls	f31, f31, f1
    lfs	f0, -0x7a68(r2)
    fmuls	f29, f29, f1
    lfs	f2, -0x7a64(r2)
    fadds	f0, f0, f30
    stfs	f31, 0(r30)
    fmuls	f28, f28, f1
    stfs	f29, 4(r30)
    fmuls	f1, f2, f0
    stfs	f28, 8(r30)
    bl      sqrtf
    stfs	f1, 0xc(r30)
_8006eb14:
    psq_l	f31, 0x48(r1), 0, 0
    lfd	f31, 0x40(r1)
    psq_l	f30, 0x38(r1), 0, 0
    lfd	f30, 0x30(r1)
    psq_l	f29, 0x28(r1), 0, 0
    lfd	f29, 0x20(r1)
    psq_l	f28, 0x18(r1), 0, 0
    lfd	f28, 0x10(r1)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x54(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

#pragma pop
