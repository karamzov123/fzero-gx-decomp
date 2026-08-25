extern unsigned char lbl_80091330[8];
#pragma push
#pragma force_active on

asm void fn_80051F38(void)
{
    nofralloc
    stwu	r1, -0x90(r1)
    stfd	f31, 0x80(r1)
    psq_st	f31, 0x88(r1), 0, 0
    stfd	f30, 0x70(r1)
    psq_st	f30, 0x78(r1), 0, 0
    stfd	f29, 0x60(r1)
    psq_st	f29, 0x68(r1), 0, 0
    stfd	f28, 0x50(r1)
    psq_st	f28, 0x58(r1), 0, 0
    stfd	f27, 0x40(r1)
    psq_st	f27, 0x48(r1), 0, 0
    stfd	f26, 0x30(r1)
    psq_st	f26, 0x38(r1), 0, 0
    stfd	f25, 0x20(r1)
    psq_st	f25, 0x28(r1), 0, 0
    stfd	f24, 0x10(r1)
    psq_st	f24, 0x18(r1), 0, 0
    li	r6, 0x10
    mr	r7, r4
    mr	r8, r5
    addi	r9, r5, 0x80
    addi	r10, r5, 0x84
    addi	r11, r5, 0xfc
_80051f94:
    lfs	f1, 0(r3)
    lfs	f0, 0(r4)
    lfs	f3, 4(r3)
    fmuls	f0, f1, f0
    lfs	f2, 4(r4)
    lfs	f4, 8(r3)
    lfs	f1, 8(r4)
    fmadds	f0, f3, f2, f0
    lfs	f3, 0xc(r3)
    lfs	f2, 0xc(r4)
    lfs	f6, 0x10(r3)
    fmadds	f0, f4, f1, f0
    lfs	f1, 0x10(r4)
    lfs	f5, 0x14(r3)
    lfs	f4, 0x14(r4)
    fmadds	f0, f3, f2, f0
    lfs	f3, 0x18(r3)
    lfs	f2, 0x18(r4)
    lfs	f10, 0x1c(r3)
    fmadds	f0, f6, f1, f0
    lfs	f1, 0x1c(r4)
    lfs	f9, 0x20(r3)
    lfs	f8, 0x20(r4)
    fmadds	f0, f5, f4, f0
    lfs	f7, 0x24(r3)
    lfs	f6, 0x24(r4)
    lfs	f5, 0x28(r3)
    fmadds	f0, f3, f2, f0
    lfs	f4, 0x28(r4)
    lfs	f3, 0x2c(r3)
    lfs	f2, 0x2c(r4)
    fmadds	f0, f10, f1, f0
    lfs	f26, 0x30(r3)
    lfs	f1, 0x30(r4)
    lfs	f25, 0x34(r3)
    fmadds	f0, f9, f8, f0
    lfs	f13, 0x34(r4)
    lfs	f12, 0x38(r3)
    lfs	f11, 0x38(r4)
    fmadds	f0, f7, f6, f0
    lfs	f10, 0x3c(r3)
    lfs	f9, 0x3c(r4)
    lfs	f8, 0x40(r3)
    fmadds	f0, f5, f4, f0
    lfs	f7, 0x40(r4)
    lfs	f6, 0x44(r3)
    lfs	f5, 0x44(r4)
    fmadds	f0, f3, f2, f0
    lfs	f4, 0x48(r3)
    lfs	f3, 0x48(r4)
    lfs	f2, 0x4c(r3)
    fmadds	f0, f26, f1, f0
    lfs	f1, 0x4c(r4)
    fmadds	f0, f25, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f3, f0
    fmadds	f0, f2, f1, f0
    lfs	f3, 0x50(r3)
    addic.	r6, r6, -1
    lfs	f1, 0x50(r4)
    lfs	f2, 0x54(r3)
    fmadds	f0, f3, f1, f0
    lfs	f1, 0x54(r4)
    lfs	f4, 0x58(r3)
    lfs	f3, 0x58(r4)
    fmadds	f0, f2, f1, f0
    lfs	f2, 0x5c(r3)
    lfs	f1, 0x5c(r4)
    lfs	f6, 0x60(r3)
    fmadds	f0, f4, f3, f0
    lfs	f5, 0x60(r4)
    lfs	f4, 0x64(r3)
    lfs	f3, 0x64(r4)
    fmadds	f0, f2, f1, f0
    lfs	f2, 0x68(r3)
    lfs	f1, 0x68(r4)
    lfs	f10, 0x6c(r3)
    fmadds	f0, f6, f5, f0
    lfs	f9, 0x6c(r4)
    lfs	f8, 0x70(r3)
    lfs	f7, 0x70(r4)
    fmadds	f0, f4, f3, f0
    lfs	f6, 0x74(r3)
    lfs	f5, 0x74(r4)
    lfs	f4, 0x78(r3)
    fmadds	f0, f2, f1, f0
    lfs	f3, 0x78(r4)
    lfs	f1, 0x7c(r4)
    addi	r4, r4, 0x80
    lfs	f2, 0x7c(r3)
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f3, f0
    fmadds	f0, f2, f1, f0
    stfs	f0, 0(r8)
    fneg	f0, f0
    addi	r8, r8, 4
    stfs	f0, 0(r9)
    addi	r9, r9, -4
    bne     _80051f94
    lis	r6, lbl_80091330@ha
    addi	r4, r7, 0x1080
    lfs	f0, lbl_80091330@l(r6)
    li	r7, 0xf
    stfs	f0, 0x40(r5)
_80052148:
    lfs	f1, 0(r3)
    lfs	f0, 0(r4)
    lfs	f3, 4(r3)
    fmuls	f0, f1, f0
    lfs	f2, 4(r4)
    lfs	f4, 8(r3)
    lfs	f1, 8(r4)
    fmadds	f0, f3, f2, f0
    lfs	f3, 0xc(r3)
    lfs	f2, 0xc(r4)
    lfs	f6, 0x10(r3)
    fmadds	f0, f4, f1, f0
    lfs	f1, 0x10(r4)
    lfs	f5, 0x14(r3)
    lfs	f4, 0x14(r4)
    fmadds	f0, f3, f2, f0
    lfs	f3, 0x18(r3)
    lfs	f2, 0x18(r4)
    lfs	f10, 0x1c(r3)
    fmadds	f0, f6, f1, f0
    lfs	f1, 0x1c(r4)
    lfs	f9, 0x20(r3)
    lfs	f8, 0x20(r4)
    fmadds	f0, f5, f4, f0
    lfs	f7, 0x24(r3)
    lfs	f6, 0x24(r4)
    lfs	f5, 0x28(r3)
    fmadds	f0, f3, f2, f0
    lfs	f4, 0x28(r4)
    lfs	f3, 0x2c(r3)
    lfs	f2, 0x2c(r4)
    fmadds	f0, f10, f1, f0
    lfs	f26, 0x30(r3)
    lfs	f1, 0x30(r4)
    lfs	f25, 0x34(r3)
    fmadds	f0, f9, f8, f0
    lfs	f13, 0x34(r4)
    lfs	f12, 0x38(r3)
    lfs	f11, 0x38(r4)
    fmadds	f0, f7, f6, f0
    lfs	f10, 0x3c(r3)
    lfs	f9, 0x3c(r4)
    lfs	f8, 0x40(r3)
    fmadds	f0, f5, f4, f0
    lfs	f7, 0x40(r4)
    lfs	f6, 0x44(r3)
    lfs	f5, 0x44(r4)
    fmadds	f0, f3, f2, f0
    lfs	f4, 0x48(r3)
    lfs	f3, 0x48(r4)
    lfs	f2, 0x4c(r3)
    fmadds	f0, f26, f1, f0
    lfs	f1, 0x4c(r4)
    fmadds	f0, f25, f13, f0
    fmadds	f0, f12, f11, f0
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f3, f0
    fmadds	f0, f2, f1, f0
    lfs	f3, 0x50(r3)
    addic.	r7, r7, -1
    lfs	f1, 0x50(r4)
    lfs	f2, 0x54(r3)
    fmadds	f0, f3, f1, f0
    lfs	f1, 0x54(r4)
    lfs	f4, 0x58(r3)
    lfs	f3, 0x58(r4)
    fmadds	f0, f2, f1, f0
    lfs	f2, 0x5c(r3)
    lfs	f1, 0x5c(r4)
    lfs	f6, 0x60(r3)
    fmadds	f0, f4, f3, f0
    lfs	f5, 0x60(r4)
    lfs	f4, 0x64(r3)
    lfs	f3, 0x64(r4)
    fmadds	f0, f2, f1, f0
    lfs	f2, 0x68(r3)
    lfs	f1, 0x68(r4)
    lfs	f10, 0x6c(r3)
    fmadds	f0, f6, f5, f0
    lfs	f9, 0x6c(r4)
    lfs	f8, 0x70(r3)
    lfs	f7, 0x70(r4)
    fmadds	f0, f4, f3, f0
    lfs	f6, 0x74(r3)
    lfs	f5, 0x74(r4)
    lfs	f4, 0x78(r3)
    fmadds	f0, f2, f1, f0
    lfs	f3, 0x78(r4)
    lfs	f1, 0x7c(r4)
    addi	r4, r4, 0x80
    lfs	f2, 0x7c(r3)
    fmadds	f0, f10, f9, f0
    fmadds	f0, f8, f7, f0
    fmadds	f0, f6, f5, f0
    fmadds	f0, f4, f3, f0
    fmadds	f0, f2, f1, f0
    stfs	f0, 0(r10)
    addi	r10, r10, 4
    stfs	f0, 0(r11)
    addi	r11, r11, -4
    bne     _80052148
    lfs	f24, 0(r3)
    lfs	f0, 4(r3)
    lfs	f1, 8(r3)
    fadds	f24, f24, f0
    lfs	f0, 0xc(r3)
    lfs	f6, 0x10(r3)
    lfs	f5, 0x14(r3)
    fadds	f24, f24, f1
    lfs	f4, 0x18(r3)
    lfs	f3, 0x1c(r3)
    lfs	f2, 0x20(r3)
    fadds	f24, f24, f0
    lfs	f1, 0x24(r3)
    lfs	f0, 0x28(r3)
    lfs	f25, 0x2c(r3)
    fadds	f24, f24, f6
    lfs	f26, 0x30(r3)
    lfs	f27, 0x34(r3)
    lfs	f28, 0x38(r3)
    fadds	f24, f24, f5
    lfs	f29, 0x3c(r3)
    lfs	f30, 0x40(r3)
    lfs	f31, 0x44(r3)
    fadds	f24, f24, f4
    lfs	f13, 0x48(r3)
    lfs	f12, 0x4c(r3)
    lfs	f11, 0x50(r3)
    fadds	f24, f24, f3
    lfs	f10, 0x54(r3)
    lfs	f9, 0x58(r3)
    lfs	f8, 0x5c(r3)
    fadds	f24, f24, f2
    lfs	f7, 0x60(r3)
    lfs	f6, 0x64(r3)
    lfs	f5, 0x68(r3)
    fadds	f24, f24, f1
    lfs	f4, 0x6c(r3)
    lfs	f3, 0x70(r3)
    lfs	f2, 0x74(r3)
    fadds	f24, f24, f0
    lfs	f1, 0x78(r3)
    lfs	f0, 0x7c(r3)
    fadds	f24, f24, f25
    fadds	f24, f24, f26
    fadds	f24, f24, f27
    fadds	f24, f24, f28
    fadds	f24, f24, f29
    fadds	f24, f24, f30
    fadds	f24, f24, f31
    fadds	f24, f24, f13
    fadds	f24, f24, f12
    fadds	f24, f24, f11
    fadds	f24, f24, f10
    fadds	f24, f24, f9
    fadds	f24, f24, f8
    fadds	f24, f24, f7
    fadds	f24, f24, f6
    fadds	f24, f24, f5
    fadds	f24, f24, f4
    fadds	f24, f24, f3
    fadds	f24, f24, f2
    fadds	f24, f24, f1
    fadds	f24, f24, f0
    fneg	f0, f24
    stfs	f0, 0xc0(r5)
    psq_l	f31, 0x88(r1), 0, 0
    lfd	f31, 0x80(r1)
    psq_l	f30, 0x78(r1), 0, 0
    lfd	f30, 0x70(r1)
    psq_l	f29, 0x68(r1), 0, 0
    lfd	f29, 0x60(r1)
    psq_l	f28, 0x58(r1), 0, 0
    lfd	f28, 0x50(r1)
    psq_l	f27, 0x48(r1), 0, 0
    lfd	f27, 0x40(r1)
    psq_l	f26, 0x38(r1), 0, 0
    lfd	f26, 0x30(r1)
    psq_l	f25, 0x28(r1), 0, 0
    lfd	f25, 0x20(r1)
    psq_l	f24, 0x18(r1), 0, 0
    lfd	f24, 0x10(r1)
    addi	r1, r1, 0x90
    blr	
}

#pragma pop
