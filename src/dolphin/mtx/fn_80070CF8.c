#pragma push
#pragma force_active on

extern asm void OSGetArenaHi(void);
extern asm void OSSetArenaHi(void);
extern asm void OSGetArenaLo(void);
extern asm void OSSetArenaLo(void);
extern void fn_80071C64(void);
extern void fn_80071C8C(void);
extern void fn_80071CB4(void);
extern void fn_80071CC0(void);
extern void fn_80071CE0(void);
extern void fn_80071CE8(void);
extern void fn_80071D0C(void);
extern void fn_80071D2C(void);
extern void fn_80071C64(void);
extern void fn_80071C8C(void);
extern void fn_80071CB4(void);
extern void fn_80071CC0(void);
extern void fn_80071CE0(void);
extern void fn_80071CE8(void);
extern void fn_80071D0C(void);
extern void fn_80071D2C(void);

asm void OSAllocFromArena(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    addi	r3, r3, 0x1f
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    rlwinm	r30, r3, 0, 0, 0x1a
    lbz	r0, -0x7da0(r13)
    cmplwi	r0, 0
    beq	_80070d34
    bl      OSGetArenaHi
    subf	r31, r30, r3
    mr	r3, r31
    bl      OSSetArenaHi
    b	_80070d44
_80070d34:
    bl      OSGetArenaLo
    mr	r31, r3
    add	r3, r31, r30
    bl      OSSetArenaLo
_80070d44:
    lwz	r0, 0x14(r1)
    mr	r3, r31
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80070D60(void)
{
    nofralloc
    lwz	r0, 0(r3)
    stw	r0, -0x769c(r13)
    lwz	r0, 4(r3)
    stw	r0, -0x76a0(r13)
    lwz	r0, 8(r3)
    stw	r0, -0x76a4(r13)
    lwz	r0, 0xc(r3)
    stw	r0, -0x76a8(r13)
    lwz	r0, 0x10(r3)
    stw	r0, -0x76ac(r13)
    lwz	r0, 0x14(r3)
    stw	r0, -0x76b0(r13)
    blr	
}

asm void fn_80070D94(void)
{
    nofralloc
    lis     r8, fn_80071CB4@ha
    lis     r7, fn_80071CC0@ha
    lis     r6, fn_80071CE0@ha
    lis     r5, fn_80071CE8@ha
    lis     r4, fn_80071D0C@ha
    lis     r3, fn_80071D2C@ha
    addi	r8, r8, fn_80071CB4@l
    addi	r7, r7, fn_80071CC0@l
    addi	r6, r6, fn_80071CE0@l
    addi	r5, r5, fn_80071CE8@l
    addi	r4, r4, fn_80071D0C@l
    addi	r0, r3, fn_80071D2C@l
    stw	r8, -0x769c(r13)
    stw	r7, -0x76a0(r13)
    stw	r6, -0x76a4(r13)
    stw	r5, -0x76a8(r13)
    stw	r4, -0x76ac(r13)
    stw	r0, -0x76b0(r13)
    blr	
}

asm void fn_80070DE0(void)
{
    nofralloc
    lwz	r0, -0x76b4(r13)
    stw	r3, -0x76b4(r13)
    mr	r3, r0
    blr	
}

asm void fn_80070DF0(void)
{
    nofralloc
    lwz	r0, -0x76b8(r13)
    stw	r3, -0x76b8(r13)
    mr	r3, r0
    blr	
}

asm void fn_80070E00(void)
{
    nofralloc
    lis     r4, fn_80071C64@ha
    lis     r3, fn_80071C8C@ha
    addi	r4, r4, fn_80071C64@l
    addi	r0, r3, fn_80071C8C@l
    stw	r4, -0x76b4(r13)
    stw	r0, -0x76b8(r13)
    blr	
}

#pragma pop
