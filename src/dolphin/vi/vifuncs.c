typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef volatile u16 vu16;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);

#pragma push
#pragma force_active on

asm s32 fn_8001A78C(register s32 mode)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    mr      r30, r3
    lwz     r31, -0x7a8c(r13)
    bl      OSDisableInterrupts
    stw     r30, -0x7a8c(r13)
    bl      OSRestoreInterrupts
    mr      r3, r31
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm s32 fn_8001A7D0(register s32 ntsc)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    mr      r30, r3
    lwz     r31, -0x7a88(r13)
    bl      OSDisableInterrupts
    stw     r30, -0x7a88(r13)
    bl      OSRestoreInterrupts
    mr      r3, r31
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm void* fn_8001A814(register s32 mode)
{
    nofralloc
    cmplwi  r3, 0x1a
    lis     r4, -0x7fee /* 0x8012 */
    addi    r5, r4, 0x41c8 /* lbl_801241C8 */
    bgt     _8001a8b0
    lis     r4, -0x7fee /* 0x8012 */
    addi    r4, r4, 0x43bc /* jumptable_801243BC */
    slwi    r0, r3, 2
    lwzx    r0, r4, r0
    mtctr   r0
    bctr
    addi    r3, r5, 0x44
    blr
    addi    r3, r5, 0x6a
    blr
    addi    r3, r5, 0x90
    blr
    addi    r3, r5, 0xb6
    blr
    addi    r3, r5, 0x44
    blr
    addi    r3, r5, 0x6a
    blr
    addi    r3, r5, 0xdc
    blr
    addi    r3, r5, 0x102
    blr
_8001a8ac:
    addi    r3, r5, 0x128
    blr
    addi    r3, r5, 0x14e
    blr
    addi    r3, r5, 0x90
    blr
    addi    r3, r5, 0xb6
    blr
    addi    r3, r5, 0x174
    blr
    addi    r3, r5, 0x19a
    blr
_8001a8b0:
    li      r3, 0
    blr
}

#pragma pop
