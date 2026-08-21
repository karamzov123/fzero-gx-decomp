typedef unsigned int u32;

extern u32 fn_8000BFC0(void);

u32 fn_80011358(char *thread)
{
    return *(u32 *)(thread + 0x2d4);
}

asm void OSClearStack(register u32 clearValue)
{
    nofralloc
    mflr        r0
    stw         r0, 4(r1)
    clrlslwi    r0, r3, 24, 16
    rlwimi      r0, r3, 24, 0, 7
    stwu        r1, -0x18(r1)
    rlwimi      r0, r3, 8, 16, 23
    stw         r31, 0x14(r1)
    mr          r31, r0
    rlwimi      r31, r3, 0, 24, 31
    bl          fn_8000BFC0
    lis         r4, 0x8000
    lwz         r5, 0xE4(r4)
    addi        r4, r3, 3
    lwz         r5, 0x308(r5)
    addi        r5, r5, 4
    cmplw       r5, r3
    subf        r4, r5, r4
    srwi        r4, r4, 2
    bge         L800113F8
    srwi.       r0, r4, 3
    mtctr       r0
    beq         L800113E8
L800113B8:
    stw         r31, 0(r5)
    stw         r31, 4(r5)
    stw         r31, 8(r5)
    stw         r31, 0xC(r5)
    stw         r31, 0x10(r5)
    stw         r31, 0x14(r5)
    stw         r31, 0x18(r5)
    stw         r31, 0x1C(r5)
    addi        r5, r5, 0x20
    bdnz        L800113B8
    andi.       r4, r4, 7
    beq         L800113F8
L800113E8:
    mtctr       r4
L800113EC:
    stw         r31, 0(r5)
    addi        r5, r5, 4
    bdnz        L800113EC
L800113F8:
    lwz         r0, 0x1C(r1)
    lwz         r31, 0x14(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
