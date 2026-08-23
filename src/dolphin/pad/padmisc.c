typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);

/* PAD/DSP-adjacent small helpers at the tail of coarse/text_8001A8B4.c.
   fn_8001DF44 programs AI DMA registers 0xCC005030/32/36. */

#pragma push
#pragma force_active on

asm s32 fn_8001DF00(register s32 value)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    mr      r30, r3
    lwz     r31, -0x7a1c(r13)
    bl      OSDisableInterrupts
    stw     r30, -0x7a1c(r13)
    bl      OSRestoreInterrupts
    mr      r3, r31
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm void fn_8001DF44(register s32 a, register s32 b)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    addi    r31, r4, 0
    stw     r30, 0x10(r1)
    addi    r30, r3, 0
    bl      OSDisableInterrupts
    lis     r4, -0x3400
    lhz     r0, 0x5030(r4)
    addi    r5, r4, 0x5000
    addi    r6, r4, 0x5000
    addi    r7, r4, 0x5000
    rlwinm  r4, r0, 0, 0, 0x15
    srwi    r0, r30, 0x10
    or      r0, r4, r0
    sth     r0, 0x30(r5)
    clrlwi  r0, r30, 0x10
    lhz     r4, 0x32(r6)
    rlwinm  r4, r4, 0, 0x1b, 0xf
    or      r0, r4, r0
    sth     r0, 0x32(r6)
    rlwinm  r0, r31, 0x1b, 0x10, 0x1f
    lhz     r4, 0x36(r7)
    rlwinm  r4, r4, 0, 0, 0x10
    or      r0, r4, r0
    sth     r0, 0x36(r7)
    bl      OSRestoreInterrupts
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

#pragma pop
