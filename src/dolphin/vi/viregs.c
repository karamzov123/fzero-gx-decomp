typedef signed int s32;
typedef unsigned int u32;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);
extern unsigned char lbl_8015D058[88];

/* VI register pollers over 0xCC002000 (vertical counter / current line).
   Carved from coarse/text_8001A8B4.c. */

#pragma push
#pragma force_active on

extern unsigned char lbl_801A6924[4];
extern unsigned char lbl_801A6960[4];
asm u32 fn_8001BE6C(void)
{
    nofralloc
    lwz	r3, lbl_801A6924
    blr
}

asm s32 fn_8001BE74(register void* retraceCountPtr)
{
    nofralloc
    lis     r3, -0x3400
    addi    r7, r3, 0x2000
    lhzu    r0, 0x2c(r7)
    addi    r4, r3, 0x2000
    clrlwi  r5, r0, 0x15
_8001be88:
    lhz     r0, 0(r7)
    mr      r6, r5
    lhz     r3, 0x2e(r4)
    clrlwi  r5, r0, 0x15
    cmplw   r6, r5
    clrlwi  r3, r3, 0x15
    bne     _8001be88
    lwz	r6, lbl_801A6960
    addi    r0, r5, -1
    addi    r4, r3, -1
    lhz     r3, 0x1a(r6)
    slwi    r5, r0, 1
    lhz     r0, 0x18(r6)
    divwu   r3, r4, r3
    add     r3, r5, r3
    cmplw   r3, r0
    bge     _8001bed4
    li      r3, 1
    blr
_8001bed4:
    li      r3, 0
    blr
}

asm s32 fn_8001BEDC(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    bl      OSDisableInterrupts
    lis     r4, -0x3400
    addi    r8, r4, 0x2000
    lhzu    r0, 0x2c(r8)
    addi    r5, r4, 0x2000
    clrlwi  r6, r0, 0x15
_8001bf04:
    lhz     r0, 0(r8)
    mr      r7, r6
    lhz     r4, 0x2e(r5)
    clrlwi  r6, r0, 0x15
    cmplw   r7, r6
    clrlwi  r4, r4, 0x15
    bne     _8001bf04
    lwz	r7, lbl_801A6960
    addi    r0, r6, -1
    addi    r5, r4, -1
    lhz     r4, 0x1a(r7)
    slwi    r6, r0, 1
    lhz     r0, 0x18(r7)
    divwu   r4, r5, r4
    add     r4, r6, r4
    cmplw   r4, r0
    bge     _8001bf50
    li      r31, 1
    b       _8001bf54
_8001bf50:
    li      r31, 0
_8001bf54:
    bl      OSRestoreInterrupts
    lis     r3, lbl_8015D058@ha
    addi    r3, r3, lbl_8015D058@l
    lhz     r0, 0xa(r3)
    xori    r3, r31, 1
    clrlwi  r0, r0, 0x1f
    xor     r3, r3, r0
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

asm u32 fn_8001BF84(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    stw     r30, 8(r1)
    lwz	r31, lbl_801A6960
    bl      OSDisableInterrupts
    lis     r4, -0x3400
    addi    r8, r4, 0x2000
_8001bfa8:
    lhzu    r0, 0x2c(r8)
    addi    r5, r4, 0x2000
    clrlwi  r6, r0, 0x15
_8001bfb4:
    lhz     r0, 0(r8)
    mr      r7, r6
    lhz     r4, 0x2e(r5)
    clrlwi  r6, r0, 0x15
    cmplw   r7, r6
    clrlwi  r7, r4, 0x15
    bne     _8001bfb4
    lwz	r4, lbl_801A6960
    addi    r5, r7, -1
    addi    r6, r6, -1
    lhz     r0, 0x1a(r4)
    slwi    r4, r6, 1
    divwu   r0, r5, r0
    add     r30, r4, r0
    bl      OSRestoreInterrupts
    lhz     r0, 0x18(r31)
    cmplw   r30, r0
    blt     _8001c000
    subf    r30, r0, r30
_8001c000:
    srwi    r3, r30, 1
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    lwz     r30, 8(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}

#pragma pop
