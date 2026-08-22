typedef int BOOL;
typedef unsigned int u32;

extern void OSResetSystem(BOOL reset, u32 shutdown_flags, BOOL force_menu);

#pragma push
#pragma force_active on

asm __declspec(section ".init") void fn_80005518(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    li      r3, 0
    li      r4, 0
    stw     r0, 0x14(r1)
    li      r5, 0
    bl      OSResetSystem
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

#pragma pop
