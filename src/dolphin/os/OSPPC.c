typedef unsigned int u32;

extern u32 PPCMfhid0(void);
extern void PPCMthid0(u32 newHID0);

asm u32 PPCMfmsr(void)
{
    nofralloc
    mfmsr   r3
    blr
}

asm void PPCMtmsr(register u32 newMSR)
{
    nofralloc
    mtmsr   r3
    blr
}

asm u32 PPCMfhid0(void)
{
    nofralloc
    mfspr   r3, 1008
    blr
}

asm void PPCMthid0(register u32 newHID0)
{
    nofralloc
    mtspr   1008, r3
    blr
}

asm u32 PPCMfl2cr(void)
{
    nofralloc
    mfspr   r3, 1017
    blr
}

asm void PPCMtl2cr(register u32 newL2cr)
{
    nofralloc
    mtspr   1017, r3
    blr
}

asm void PPCMtdec(register u32 newDec)
{
    nofralloc
    mtdec   r3
    blr
}

asm void PPCSync(void)
{
    nofralloc
    sc
    blr
}

asm void PPCHalt(void)
{
    nofralloc
    sync
loop:
    nop
    li      r3, 0
    nop
    b       loop
}

asm void PPCMtmmcr0(register u32 newMmcr0)
{
    nofralloc
    mtspr   952, r3
    blr
}

asm void PPCMtmmcr1(register u32 newMmcr1)
{
    nofralloc
    mtspr   956, r3
    blr
}

asm u32 PPCMfpmc1(void)
{
    nofralloc
    mfspr   r3, 953
    blr
}

asm void PPCMtpmc1(register u32 newPmc1)
{
    nofralloc
    mtspr   953, r3
    blr
}

asm u32 PPCMfpmc2(void)
{
    nofralloc
    mfspr   r3, 954
    blr
}

asm void PPCMtpmc2(register u32 newPmc2)
{
    nofralloc
    mtspr   954, r3
    blr
}

asm u32 PPCMfpmc3(void)
{
    nofralloc
    mfspr   r3, 957
    blr
}

asm void PPCMtpmc3(register u32 newPmc3)
{
    nofralloc
    mtspr   957, r3
    blr
}

asm u32 PPCMfpmc4(void)
{
    nofralloc
    mfspr   r3, 958
    blr
}

asm void PPCMtpmc4(register u32 newPmc4)
{
    nofralloc
    mtspr   958, r3
    blr
}

asm u32 PPCMffpscr(void)
{
    nofralloc
    stwu    r1, -0x18(r1)
    stfd    f31, 0x10(r1)
    mffs    f31
    stfd    f31, 8(r1)
    lwz     r3, 0xc(r1)
    lfd     f31, 0x10(r1)
    addi    r1, r1, 0x18
    blr
}

asm void PPCMtfpscr(register u32 newFpscr)
{
    nofralloc
    stwu    r1, -0x20(r1)
    stfd    f31, 0x18(r1)
    li      r4, 0
    stw     r4, 0x10(r1)
    stw     r3, 0x14(r1)
    lfd     f31, 0x10(r1)
    mtfsf   255, f31
    lfd     f31, 0x18(r1)
    addi    r1, r1, 0x20
    blr
}

asm u32 PPCMfhid2(void)
{
    nofralloc
    mfspr   r3, 920
    blr
}

asm void PPCMthid2(register u32 newhid2)
{
    nofralloc
    mtspr   920, r3
    blr
}

asm u32 PPCMfwpar(void)
{
    nofralloc
    sync
    mfspr   r3, 921
    blr
}

asm void PPCMtwpar(register u32 newwpar)
{
    nofralloc
    mtspr   921, r3
    blr
}

asm void PPCDisableSpeculation(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -8(r1)
    bl      PPCMfhid0
    ori     r3, r3, 0x200
    bl      PPCMthid0
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr
}

asm void PPCSetFpNonIEEEMode(void)
{
    nofralloc
    mtfsb1  29
    blr
}
