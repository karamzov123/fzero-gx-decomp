// MSL double->float wrappers (truncf-style thunks into printf.c math
// helpers), 0x80088600-0x80088648.

#pragma push
#pragma force_active on

extern double fn_800883E8(double);
extern double fn_80087E80(double);

asm float fn_80088600(double d)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      fn_800883E8
    lwz     r0, 0x14(r1)
    frsp    f1, f1
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm float fn_80088624(double d)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      fn_80087E80
    lwz     r0, 0x14(r1)
    frsp    f1, f1
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

#pragma pop
