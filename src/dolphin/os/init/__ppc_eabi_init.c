extern void PPCHalt(void);
static void __init_cpp(void);

__declspec(section ".ctors") extern void (*_ctors[])();

#pragma push
#pragma force_active on
asm void __init_user(void)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x8(r1)
    bl      __init_cpp
    lwz     r0, 0xc(r1)
    addi    r1, r1, 0x8
    mtlr    r0
    blr
}

asm static void __init_cpp(void)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    lis     r3, _ctors@ha
    addi    r0, r3, _ctors@l
    mr      r31, r0
    b       lbl_800118C8
lbl_800118C8:
    b       lbl_800118CC
lbl_800118CC:
    b       lbl_800118DC
lbl_800118D0:
    mtlr    r12
    blrl
    addi    r31, r31, 0x4
lbl_800118DC:
    lwz     r12, 0x0(r31)
    cmplwi  r12, 0x0
    bne     lbl_800118D0
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}

asm void _ExitProcess(void)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x8(r1)
    bl      PPCHalt
    lwz     r0, 0xc(r1)
    addi    r1, r1, 0x8
    mtlr    r0
    blr
}
#pragma pop
