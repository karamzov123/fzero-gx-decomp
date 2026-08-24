#pragma push
#pragma force_active on

extern asm void LCEnable(void);
extern asm void OSAllocFromArena(void);
extern asm void OSPanic(void);
extern unsigned char lbl_8015AA78[11];
extern unsigned char lbl_8015AA84[160];
extern unsigned char lbl_8019E140[16];

asm void fn_80070158(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r3, 0
    stw	r0, 0x14(r1)
    beq	_80070188
    bl      LCEnable
    lwz	r0, -0x76e0(r13)
    lis	r3, -0x2000
    stw	r3, -0x76d0(r13)
    ori	r0, r0, 2
    stw	r0, -0x76e0(r13)
    b	_80070194
_80070188:
    li	r3, 0x4000
    bl      OSAllocFromArena
    stw	r3, -0x76d0(r13)
_80070194:
    li	r7, 0
    lwz	r8, -0x76d0(r13)
    stw	r7, -0x76d4(r13)
    li	r4, 0x1c0
    addi	r6, r8, 0x1c0
    li	r0, 0x1db
    stw	r4, -0x76d4(r13)
    srwi	r4, r0, 5
    li	r5, 0x1dc
    lis     r3, lbl_8019E140@ha
    addi	r0, r4, 1
    stw	r5, -0x76d4(r13)
    slwi	r4, r0, 5
    addi	r5, r3, lbl_8019E140@l
    stw	r4, -0x76d4(r13)
    addi	r3, r4, 0xca0
    add	r4, r8, r4
    addi	r0, r3, 0x3ff
    stw	r3, -0x76d4(r13)
    rlwinm	r3, r0, 0, 0, 0x15
    stw	r8, -0x76c0(r13)
    li	r0, 4
    li	r8, 0
    stw	r6, -0x7690(r13)
    stw	r4, -0x7688(r13)
    stw	r3, -0x76d4(r13)
    mtctr	r0
_80070200:
    cmpwi	r8, 0xe
    bge	_80070220
    cmplw	r7, r3
    bgt	_80070218
    li	r0, 0xff
    b	_80070224
_80070218:
    li	r0, 0
    b	_80070224
_80070220:
    li	r0, 1
_80070224:
    addi	r8, r8, 1
    stb	r0, 0(r5)
    cmpwi	r8, 0xe
    addi	r7, r7, 0x400
    addi	r5, r5, 1
    bge	_80070254
    cmplw	r7, r3
    bgt	_8007024c
    li	r0, 0xff
    b	_80070258
_8007024c:
    li	r0, 0
    b	_80070258
_80070254:
    li	r0, 1
_80070258:
    addi	r8, r8, 1
    stb	r0, 0(r5)
    cmpwi	r8, 0xe
    addi	r7, r7, 0x400
    addi	r5, r5, 1
    bge	_80070288
    cmplw	r7, r3
    bgt	_80070280
    li	r0, 0xff
    b	_8007028c
_80070280:
    li	r0, 0
    b	_8007028c
_80070288:
    li	r0, 1
_8007028c:
    addi	r8, r8, 1
    stb	r0, 0(r5)
    cmpwi	r8, 0xe
    addi	r7, r7, 0x400
    addi	r5, r5, 1
    bge	_800702bc
    cmplw	r7, r3
    bgt	_800702b4
    li	r0, 0xff
    b	_800702c0
_800702b4:
    li	r0, 0
    b	_800702c0
_800702bc:
    li	r0, 1
_800702c0:
    stb	r0, 0(r5)
    addi	r7, r7, 0x400
    addi	r5, r5, 1
    addi	r8, r8, 1
    bdnz	_80070200
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800702E4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, lbl_8019E140@ha
    li	r5, 0
    stw	r0, 0x14(r1)
    li	r0, 0x10
    addi	r6, r4, lbl_8019E140@l
    stw	r31, 0xc(r1)
    li	r31, 0
    mtctr	r0
_8007030c:
    lbz	r0, 0(r6)
    cmplwi	r0, 0
    bne	_80070444
    lis     r4, lbl_8019E140@ha
    addi	r7, r5, 1
    addi	r0, r4, lbl_8019E140@l
    addi	r8, r3, -1
    add	r4, r0, r7
    b	_80070348
_80070330:
    lbz	r0, 0(r4)
    cmplwi	r0, 0
    bne	_80070358
    addi	r8, r8, -1
    addi	r4, r4, 1
    addi	r7, r7, 1
_80070348:
    cmplwi	r8, 0
    beq	_80070358
    cmpwi	r7, 0x10
    blt	_80070330
_80070358:
    cmplwi	r8, 0
    bne	_80070444
    cmplwi	r3, 0
    lwz	r6, -0x76d0(r13)
    slwi	r0, r5, 0xa
    li	r4, 0
    add	r31, r6, r0
    ble	_80070450
    cmplwi	r3, 8
    addi	r7, r3, -8
    ble	_8007040c
    addi	r0, r7, 7
    lis     r6, lbl_8019E140@ha
    addi	r6, r6, lbl_8019E140@l
    srwi	r0, r0, 3
    add	r10, r6, r5
    mtctr	r0
    cmplwi	r7, 0
    ble	_8007040c
_800703a4:
    subf	r6, r4, r3
    addi	r0, r4, 1
    stb	r6, 0(r10)
    subf	r7, r0, r3
    addi	r6, r4, 2
    addi	r0, r4, 3
    stb	r7, 1(r10)
    subf	r6, r6, r3
    subf	r9, r0, r3
    addi	r0, r4, 4
    stb	r6, 2(r10)
    subf	r8, r0, r3
    addi	r7, r4, 5
    addi	r6, r4, 6
    stb	r9, 3(r10)
    addi	r0, r4, 7
    subf	r7, r7, r3
    subf	r6, r6, r3
    stb	r8, 4(r10)
    subf	r0, r0, r3
    addi	r4, r4, 8
    stb	r7, 5(r10)
    stb	r6, 6(r10)
    stb	r0, 7(r10)
    addi	r10, r10, 8
    bdnz	_800703a4
_8007040c:
    lis     r6, lbl_8019E140@ha
    subf	r0, r4, r3
    addi	r6, r6, lbl_8019E140@l
    add	r5, r6, r5
    add	r5, r5, r4
    mtctr	r0
    cmplw	r4, r3
    bge	_80070450
_8007042c:
    subf	r0, r4, r3
    addi	r4, r4, 1
    stb	r0, 0(r5)
    addi	r5, r5, 1
    bdnz	_8007042c
    b	_80070450
_80070444:
    addi	r6, r6, 1
    addi	r5, r5, 1
    bdnz	_8007030c
_80070450:
    cmplwi	r31, 0
    bne	_80070474
    lis     r3, lbl_8015AA78@ha
    lis     r5, lbl_8015AA84@ha
    addi	r3, r3, lbl_8015AA78@l
    li	r4, 0x9e
    addi	r5, r5, lbl_8015AA84@l
    crxor	6, 6, 6
    bl      OSPanic
_80070474:
    lwz	r0, 0x14(r1)
    mr	r3, r31
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8007048C(void)
{
    nofralloc
    lis     r3, lbl_8019E140@ha
    li	r0, 2
    addi	r3, r3, lbl_8019E140@l
    li	r5, 0
    li	r4, 0
    mtctr	r0
_800704a4:
    lbz	r0, 0(r3)
    cmplwi	r0, 0
    beq	_800704b4
    addi	r5, r5, 1
_800704b4:
    lbzu	r0, 1(r3)
    cmplwi	r0, 0
    beq	_800704c4
    addi	r5, r5, 1
_800704c4:
    lbzu	r0, 1(r3)
    cmplwi	r0, 0
    beq	_800704d4
    addi	r5, r5, 1
_800704d4:
    lbzu	r0, 1(r3)
    cmplwi	r0, 0
    beq	_800704e4
    addi	r5, r5, 1
_800704e4:
    lbzu	r0, 1(r3)
    cmplwi	r0, 0
    beq	_800704f4
    addi	r5, r5, 1
_800704f4:
    lbzu	r0, 1(r3)
    cmplwi	r0, 0
    beq	_80070504
    addi	r5, r5, 1
_80070504:
    lbzu	r0, 1(r3)
    cmplwi	r0, 0
    beq	_80070514
    addi	r5, r5, 1
_80070514:
    lbzu	r0, 1(r3)
    cmplwi	r0, 0
    beq	_80070524
    addi	r5, r5, 1
_80070524:
    addi	r3, r3, 1
    addi	r4, r4, 7
    bdnz	_800704a4
    subfic	r3, r5, 0x10
    blr	
}

#pragma pop
