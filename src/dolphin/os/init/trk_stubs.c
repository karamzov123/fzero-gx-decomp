extern void fn_8008B028(void* arg);

#pragma push
#pragma force_active on

asm __declspec(section ".init") void* fn_80003590(void* arg)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    stw     r31, 0xc(r1)
    mr      r31, r3
    bl      fn_8008B028
    lwz     r0, 0x14(r1)
    mr      r3, r31
    lwz     r31, 0xc(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm __declspec(section ".init") void fn_800035C0(void* dst, const void* src,
                                                 unsigned long n)
{
    nofralloc
    subi    r4, r4, 1
    subi    r6, r3, 1
    addi    r5, r5, 1
    b       lbl_800035D8
lbl_800035D0:
    lbzu    r0, 0x1(r4)
    stbu    r0, 0x1(r6)
lbl_800035D8:
    subic.  r5, r5, 1
    bne     lbl_800035D0
    blr
}

#pragma pop
