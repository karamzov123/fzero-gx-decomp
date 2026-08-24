typedef unsigned int u32;

extern unsigned char lbl_801A6DA4[];

#pragma push
#pragma force_active on

asm void fn_80078538(register void* mdl)
{
    nofralloc
    lwz     r4, 4(r3)
    lwz     r5, 8(r3)
    add     r4, r3, r4
    add     r5, r3, r5
    lis     r10, -0x2000
    ori     r10, r10, 0x3800
    rlwinm  r11, r4, 0, 4, 0x1a
    ori     r11, r11, 0x10
    rlwinm  r12, r10, 0, 0, 0x1a
    ori     r12, r12, 0x12
    mtspr   0x39a, r11
    mtspr   0x39b, r12
    addi    r4, r4, 0x800
    lis     r6, lbl_801A6DA4@ha
    ori     r6, r6, lbl_801A6DA4@l
    lwz     r6, 0(r6)
    lwz     r7, 0(r3)
    li      r8, 0x20
    dcbt    0, r5
_80078584:
    mfspr   r0, 0x398
    rlwinm. r0, r0, 8, 0x1c, 0x1f
    bne     _80078584
    li      r3, 0
_80078594:
    addi    r5, r5, 0x40
    dcbt    0, r5
    lbz     r9, -0xc(r5)
    subf.   r8, r9, r8
    mcrf    cr5, cr0
    ps_sub  f5, f5, f5
    ps_sub  f7, f7, f7
    ps_mr   f6, f5
    ps_sub  f8, f8, f8
_800785b8:
    add     r12, r10, r3
    lfs     f4, 0x1c(r12)
    psq_l   f0, 0x0(r12), 0, 0
    psq_l   f1, 0x8(r12), 1, 0
    psq_l   f2, 0xc(r12), 0, 0
    psq_l   f3, 0x14(r12), 1, 0
    lhz     r11, 0x18(r12)
    slwi    r11, r11, 2
    lwzx    r11, r6, r11
    psq_l   f9, 0x0(r11), 0, 0
    psq_l   f10, 0x8(r11), 0, 0
    ps_mul  f11, f9, f0
    ps_madd f11, f10, f1, f11
    ps_sum0 f11, f11, f11, f11
    ps_mul  f13, f9, f2
    ps_mul  f10, f10, f3
    ps_sum1 f13, f13, f10, f13
    psq_l   f9, 0x10(r11), 0, 0
    psq_l   f10, 0x18(r11), 0, 0
    ps_mul  f12, f9, f0
    ps_madd f12, f10, f1, f12
    ps_sum1 f11, f12, f11, f12
    ps_mul  f9, f9, f2
    ps_mul  f10, f10, f3
    ps_sum1 f10, f9, f10, f9
    ps_sum1 f10, f10, f13, f10
    ps_sum0 f13, f13, f10, f13
    psq_l   f9, 0x20(r11), 0, 0
    psq_l   f10, 0x28(r11), 0, 0
    ps_mul  f0, f9, f0
    ps_madd f1, f10, f1, f0
    ps_sum0 f1, f1, f1, f1
    ps_mul  f9, f9, f2
    ps_mul  f10, f10, f3
    ps_sum1 f3, f9, f10, f9
    ps_sum0 f3, f3, f3, f3
    ps_madds0 f5, f11, f4, f5
    ps_madds0 f6, f1, f4, f6
    ps_add  f7, f13, f7
    ps_add  f8, f3, f8
    addi    r3, r3, 0x20
    andi.   r3, r3, 0x7ff
    subic.  r9, r9, 1
    bgt     _800785b8
    psq_st  f5, -0x40(r5), 0, 0
    psq_st  f6, -0x38(r5), 1, 0
    psq_st  f7, -0x34(r5), 0, 0
    psq_st  f8, -0x2c(r5), 1, 0
    bgt     cr5, _800786a4
    addi    r8, r8, 0x20
    rlwinm  r11, r4, 0, 4, 0x1a
    ori     r11, r11, 8
    xori    r12, r3, 0x400
    add     r12, r10, r12
    rlwinm  r12, r12, 0, 0, 0x16
    ori     r12, r12, 0x12
    mtspr   0x39a, r11
    addi    r4, r4, 0x400
    mtspr   0x39b, r12
_800786a4:
    subic.  r7, r7, 1
    bne     _80078594
    blr
}

#pragma pop
