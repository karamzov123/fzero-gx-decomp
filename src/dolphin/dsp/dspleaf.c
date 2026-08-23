typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

/* DSP-style register leaf accessors at 0xCC006C00 / 0xCC006C04.
   Carved from coarse/text_8001A8B4.c; promoted to global scope because
   the still-coarse 0x8001DFFC/0x8001E0E4/0x8001E1D8 units bl them. */

#pragma push
#pragma force_active on

asm s32 fn_8001E2AC(void)
{
    nofralloc
    lis     r3, -0x3400
    lwz     r0, 0x6c00(r3)
    rlwinm  r3, r0, 0x1f, 0x1f, 0x1f
    blr
}

asm void fn_8001E2BC(register s32 val)
{
    nofralloc
    lis     r4, -0x3400
    addi    r4, r4, 0x6c00
    lwz     r0, 4(r4)
    rlwinm  r0, r0, 0, 0, 0x17
    rlwimi  r0, r3, 0, 0x18, 0x1f
    stw     r0, 4(r4)
    blr
}

asm s32 fn_8001E2D8(void)
{
    nofralloc
    lis     r3, -0x3400
    lwz     r0, 0x6c04(r3)
    clrlwi  r3, r0, 0x18
    blr
}

asm void fn_8001E2E8(register s32 val)
{
    nofralloc
    lis     r4, -0x3400
    addi    r4, r4, 0x6c00
    lwz     r0, 4(r4)
    rlwinm  r0, r0, 0, 0x18, 0xf
    rlwimi  r0, r3, 8, 0x10, 0x17
    stw     r0, 4(r4)
    blr
}

asm s32 fn_8001E304(void)
{
    nofralloc
    lis     r3, -0x3400
    lwz     r0, 0x6c04(r3)
    rlwinm  r3, r0, 0x18, 0x18, 0x1f
    blr
}

#pragma pop
