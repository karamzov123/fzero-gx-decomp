typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u32 hi, lo; } s64_;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);
extern s32 __shl2i(u32, u32, s32);
extern s32 __shr2u(u32, u32, s32);
extern s32 fn_8001AFB8(register void*, register void*, register void*, register void*, register void*);
extern s32 fn_8001B28C(register s32, register s32, register s32, register s32, register s32, register s32, register s32, register s32, register s32);
extern unsigned char lbl_8015CF68[];

/* VI retrace-callback waiters over the game's callback state at
   0x8016CF68 (-0x3098 from 0x8016_0000 base). */

#pragma push
#pragma force_active on

asm s32 fn_8001BC54(register void* param)
{
    nofralloc
    mflr    r0
    lis     r3, lbl_8015CF68@ha
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r3, r3, lbl_8015CF68@l
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    stw     r28, 0x10(r1)
    bl      OSDisableInterrupts
    lwz     r5, -0x7a70(r13)
    addi    r30, r3, 0
    li      r0, 0
    lwz     r4, -0x7a7c(r13)
    or      r3, r5, r4
    stw     r3, -0x7a70(r13)
    stw     r0, -0x7a7c(r13)
    lwz     r4, -0x7a68(r13)
    lwz     r5, -0x7a64(r13)
    lwz     r0, -0x7a78(r13)
    lwz     r3, -0x7a74(r13)
    or      r0, r4, r0
    or      r3, r5, r3
    stw     r3, -0x7a64(r13)
    stw     r0, -0x7a68(r13)
    b       _8001bd30
_8001bcbc:
    lwz     r3, -0x7a78(r13)
    li      r5, 0x20
    lwz     r28, -0x7a74(r13)
    addi    r4, r28, 0
    bl      __shr2u
    cntlzw  r4, r4
    cmpwi   r4, 0x20
    li      r0, -1
    and     r0, r28, r0
    bge     _8001bce8
    b       _8001bcf0
_8001bce8:
    cntlzw  r3, r0
    addi    r4, r3, 0x20
_8001bcf0:
    slwi    r3, r4, 1
    lhzx    r0, r31, r3
    add     r3, r31, r3
    subfic  r5, r4, 0x3f
    sth     r0, 0x78(r3)
    li      r3, 0
    li      r4, 1
    bl      __shl2i
    lwz     r0, -0x7a78(r13)
    nor     r5, r3, r3
    nor     r4, r4, r4
    lwz     r3, -0x7a74(r13)
    and     r0, r0, r5
    and     r3, r3, r4
    stw     r3, -0x7a74(r13)
    stw     r0, -0x7a78(r13)
_8001bd30:
    lwz     r0, -0x7a78(r13)
    li      r3, 0
    lwz     r4, -0x7a74(r13)
    xor     r0, r0, r3
    xor     r3, r4, r3
    or.     r0, r3, r0
    bne     _8001bcbc
    li      r0, 1
    stw     r0, -0x7a98(r13)
    mr      r3, r30
    lwz     r0, 0x120(r31)
    stw     r0, -0x7a58(r13)
    bl      OSRestoreInterrupts
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

asm s32 fn_8001BD84(register s32 param)
{
    nofralloc
    mflr    r0
    lis     r4, lbl_8015CF68@ha
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    addi    r4, r4, lbl_8015CF68@l
    stw     r30, 0x10(r1)
    addi    r30, r3, 0
    bl      OSDisableInterrupts
    stw     r30, 0x120(r31)
    li      r0, 1
    addi    r30, r3, 0
    stw     r0, -0x7a50(r13)
    addi    r3, r31, 0xf0
    addi    r4, r31, 0x124
    addi    r5, r31, 0x128
    addi    r6, r31, 0x13c
    addi    r7, r31, 0x140
    bl      fn_8001AFB8
    mr      r3, r30
    bl      OSRestoreInterrupts
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm s32 fn_8001BDF0(register s32 param)
{
    nofralloc
    mflr    r0
    lis     r4, lbl_8015CF68@ha
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r4, r4, lbl_8015CF68@l
    stw     r30, 0x18(r1)
    addi    r30, r3, 0
    bl      OSDisableInterrupts
    stw     r30, 0x130(r31)
    mr      r30, r3
    lwz     r10, 0x144(r31)
    lwz     r0, 0x130(r31)
    stw     r0, 8(r1)
    lhz     r3, 0xfa(r31)
    lhz     r4, 0xf6(r31)
    lbz     r5, 0(r10)
    lhz     r6, 2(r10)
    lhz     r7, 4(r10)
    lhz     r8, 6(r10)
    lhz     r9, 8(r10)
    lhz     r10, 0xa(r10)
    bl      fn_8001B28C
    mr      r3, r30
    bl      OSRestoreInterrupts
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

#pragma pop
