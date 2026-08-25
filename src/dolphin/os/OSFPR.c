#pragma push
#pragma force_active on

extern unsigned char ZeroF_801A6758[8];
extern unsigned char ZeroPS_801A6760[8];

asm void __OSFPRInit(void)
{
    nofralloc
    mfmsr   r3
    ori     r3, r3, 0x2000
    mtmsr   r3
    mfspr   r3, 920
    rlwinm. r3, r3, 3, 31, 31
    beq     _nopse
    lis     r3, ZeroPS_801A6760@ha
    addi    r3, r3, ZeroPS_801A6760@l
    psq_l   f0, 0(r3), 0, 0
    ps_mr   f1, f0
    ps_mr   f2, f0
    ps_mr   f3, f0
    ps_mr   f4, f0
    ps_mr   f5, f0
    ps_mr   f6, f0
    ps_mr   f7, f0
    ps_mr   f8, f0
    ps_mr   f9, f0
    ps_mr   f10, f0
    ps_mr   f11, f0
    ps_mr   f12, f0
    ps_mr   f13, f0
    ps_mr   f14, f0
    ps_mr   f15, f0
    ps_mr   f16, f0
    ps_mr   f17, f0
    ps_mr   f18, f0
    ps_mr   f19, f0
    ps_mr   f20, f0
    ps_mr   f21, f0
    ps_mr   f22, f0
    ps_mr   f23, f0
    ps_mr   f24, f0
    ps_mr   f25, f0
    ps_mr   f26, f0
    ps_mr   f27, f0
    ps_mr   f28, f0
    ps_mr   f29, f0
    ps_mr   f30, f0
    ps_mr   f31, f0
_nopse:
    lfd     f0, ZeroF_801A6758(r13)
    fmr     f1, f0
    fmr     f2, f0
    fmr     f3, f0
    fmr     f4, f0
    fmr     f5, f0
    fmr     f6, f0
    fmr     f7, f0
    fmr     f8, f0
    fmr     f9, f0
    fmr     f10, f0
    fmr     f11, f0
    fmr     f12, f0
    fmr     f13, f0
    fmr     f14, f0
    fmr     f15, f0
    fmr     f16, f0
    fmr     f17, f0
    fmr     f18, f0
    fmr     f19, f0
    fmr     f20, f0
    fmr     f21, f0
    fmr     f22, f0
    fmr     f23, f0
    fmr     f24, f0
    fmr     f25, f0
    fmr     f26, f0
    fmr     f27, f0
    fmr     f28, f0
    fmr     f29, f0
    fmr     f30, f0
    fmr     f31, f0
    mtfsf   255, f0
    blr
}

#pragma pop
