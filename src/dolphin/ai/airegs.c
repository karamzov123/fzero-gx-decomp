typedef signed int s32;
typedef unsigned int u32;

/* AI control-register (0xCC005036) bit set/clear helpers.
   Carved from coarse/text_8001A8B4.c. */

#pragma push
#pragma force_active on

asm void fn_8001DFCC(void)
{
    nofralloc
    lis     r3, -0x3400
    addi    r3, r3, 0x5000
    lhz     r0, 0x36(r3)
    ori     r0, r0, 0x8000
    sth     r0, 0x36(r3)
    blr
}

asm void fn_8001DFE4(void)
{
    nofralloc
    lis     r3, -0x3400
    addi    r3, r3, 0x5000
    lhz     r0, 0x36(r3)
    rlwinm  r0, r0, 0, 0x11, 0xf
    sth     r0, 0x36(r3)
    blr
}

#pragma pop
