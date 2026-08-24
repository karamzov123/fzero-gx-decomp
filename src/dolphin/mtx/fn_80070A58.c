#pragma push
#pragma force_active on

extern asm void OSPanic(void);
extern asm void QuatNormalizeCompare(void);
extern asm void fn_8006DCDC(void);
extern asm void fn_80070CF8(void);
extern unsigned char lbl_8015AA78[11];
extern unsigned char lbl_8019E140[16];

asm void fn_80070A58(void)
{
    nofralloc
    lfs	f0, -0x7a30(r2)
    li	r5, -1
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    lfs	f2, -0x7a2c(r2)
    li	r0, 1
    stfs	f0, 0x198(r3)
    lfs	f1, -0x7a20(r2)
    lwz	r3, -0x76c0(r13)
    lfs	f0, -0x7a1c(r2)
    stfs	f2, 0x19c(r3)
    lwz	r3, -0x76c0(r13)
    stfs	f1, 0x1a0(r3)
    lwz	r3, -0x76c0(r13)
    stfs	f0, 0x1a4(r3)
    lwz	r3, -0x76c0(r13)
    stw	r5, 0x1a8(r3)
    lwz	r3, -0x76c0(r13)
    stb	r4, 0x1ac(r3)
    lwz	r3, -0x76c0(r13)
    stb	r0, 0x1ad(r3)
    lwz	r3, -0x76c0(r13)
    stb	r0, 0x1ae(r3)
    lwz	r3, -0x76c0(r13)
    stb	r4, 0x1af(r3)
    blr	
}

asm void fn_80070AC0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    or.	r29, r3, r3
    lis     r3, lbl_8015AA78@ha
    addi	r31, r3, lbl_8015AA78@l
    bne	_80070b00
    addi	r3, r31, 0
    addi	r5, r31, 0xcc
    li	r4, 0x202
    crxor	6, 6, 6
    bl      OSPanic
_80070b00:
    bl      QuatNormalizeCompare
    bl      fn_8006DCDC
    cmpwi	r30, 0
    beq	_80070b20
    lwz	r0, -0x76e0(r13)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bne	_80070b20
    li	r30, 0
_80070b20:
    cmpwi	r30, 0
    beq	_80070cb8
    mulli	r3, r29, 0x30
    lis     r4, lbl_8019E140@ha
    li	r30, 0
    addi	r8, r4, lbl_8019E140@l
    addi	r4, r3, 0x3ff
    li	r0, 0x10
    mr	r3, r30
    srwi	r4, r4, 0xa
    mtctr	r0
_80070b4c:
    lbz	r0, 0(r8)
    cmplwi	r0, 0
    bne	_80070c84
    lis     r5, lbl_8019E140@ha
    addi	r6, r3, 1
    addi	r0, r5, lbl_8019E140@l
    addi	r5, r4, -1
    add	r7, r0, r6
    b	_80070b88
_80070b70:
    lbz	r0, 0(r7)
    cmplwi	r0, 0
    bne	_80070b98
    addi	r5, r5, -1
    addi	r7, r7, 1
    addi	r6, r6, 1
_80070b88:
    cmplwi	r5, 0
    beq	_80070b98
    cmpwi	r6, 0x10
    blt	_80070b70
_80070b98:
    cmplwi	r5, 0
    bne	_80070c84
    cmplwi	r4, 0
    lwz	r6, -0x76d0(r13)
    slwi	r0, r3, 0xa
    li	r5, 0
    add	r30, r6, r0
    ble	_80070c90
    cmplwi	r4, 8
    addi	r7, r4, -8
    ble	_80070c4c
    addi	r0, r7, 7
    lis     r6, lbl_8019E140@ha
    addi	r6, r6, lbl_8019E140@l
    srwi	r0, r0, 3
    add	r10, r6, r3
    mtctr	r0
    cmplwi	r7, 0
    ble	_80070c4c
_80070be4:
    subf	r6, r5, r4
    addi	r0, r5, 1
    stb	r6, 0(r10)
    subf	r7, r0, r4
    addi	r6, r5, 2
    addi	r0, r5, 3
    stb	r7, 1(r10)
    subf	r6, r6, r4
    subf	r9, r0, r4
    addi	r0, r5, 4
    stb	r6, 2(r10)
    subf	r8, r0, r4
    addi	r7, r5, 5
    addi	r6, r5, 6
    stb	r9, 3(r10)
    addi	r0, r5, 7
    subf	r7, r7, r4
    subf	r6, r6, r4
    stb	r8, 4(r10)
    subf	r0, r0, r4
    addi	r5, r5, 8
    stb	r7, 5(r10)
    stb	r6, 6(r10)
    stb	r0, 7(r10)
    addi	r10, r10, 8
    bdnz	_80070be4
_80070c4c:
    lis     r6, lbl_8019E140@ha
    subf	r0, r5, r4
    addi	r6, r6, lbl_8019E140@l
    add	r3, r6, r3
    add	r3, r3, r5
    mtctr	r0
    cmplw	r5, r4
    bge	_80070c90
_80070c6c:
    subf	r0, r5, r4
    addi	r5, r5, 1
    stb	r0, 0(r3)
    addi	r3, r3, 1
    bdnz	_80070c6c
    b	_80070c90
_80070c84:
    addi	r8, r8, 1
    addi	r3, r3, 1
    bdnz	_80070b4c
_80070c90:
    cmplwi	r30, 0
    bne	_80070cac
    addi	r3, r31, 0
    addi	r5, r31, 0xc
    li	r4, 0x9e
    crxor	6, 6, 6
    bl      OSPanic
_80070cac:
    lwz	r3, -0x76c0(r13)
    stw	r30, 0x90(r3)
    b	_80070cc8
_80070cb8:
    mulli	r3, r29, 0x30
    bl      fn_80070CF8
    lwz	r4, -0x76c0(r13)
    stw	r3, 0x90(r4)
_80070cc8:
    lwz	r4, -0x76c0(r13)
    mulli	r0, r29, 0x30
    lwz	r3, 0x90(r4)
    add	r0, r3, r0
    stw	r0, 0x94(r4)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
