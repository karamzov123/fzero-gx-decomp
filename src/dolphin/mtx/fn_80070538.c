#pragma push
#pragma force_active on

extern asm void OSGetArenaLo(void);
extern asm void OSGetArenaHi(void);
extern asm void OSGetConsoleSimulatedMemSize(void);
extern asm void OSGetPhysicalMemSize(void);
extern asm void OSSetArenaLo(void);
extern asm void OSSetArenaHi(void);
extern asm void fn_80070A58(void);
extern asm void VIGetTvFormat(void);
extern asm void OSPanic(void);
extern asm void GXAdjustForOverscan(void);
extern asm void fn_8001B42C(void);
extern asm void GXSetCopyClear(void);
extern unsigned char lbl_8012AFB8[60];
extern unsigned char lbl_8012AFF4[60];
extern unsigned char lbl_8012B030[60];
extern unsigned char lbl_8012B06C[60];
extern unsigned char lbl_8012B0A8[60];
extern unsigned char lbl_8015AA78[11];
extern unsigned char lbl_8015AB24[76];
extern unsigned char lbl_8019E150[60];

asm void fn_80070538(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    bl      OSGetArenaLo
    mr	r30, r3
    bl      OSGetArenaHi
    li	r0, 0
    mr	r29, r3
    stw	r0, -0x76c8(r13)
    stw	r0, -0x76c4(r13)
    bl      OSGetConsoleSimulatedMemSize
    lbz	r0, -0x76d7(r13)
    mr	r31, r3
    cmplwi	r0, 0
    bne	_8007058c
    lis	r0, 0x180
    cmplw	r31, r0
    bgt	_80070594
_8007058c:
    lis	r3, 0x180
    b	_80070598
_80070594:
    bl      OSGetPhysicalMemSize
_80070598:
    lis	r0, 0x180
    cmplw	r3, r0
    ble	_800705e8
    lwz	r4, -0x76e0(r13)
    lbz	r0, -0x76d8(r13)
    ori	r4, r4, 8
    cmplwi	r0, 0
    stw	r4, -0x76e0(r13)
    bne	_800705d8
    addis	r0, r31, -0x180
    stw	r29, -0x76c8(r13)
    ori	r3, r4, 1
    subf	r29, r0, r29
    stw	r3, -0x76e0(r13)
    stw	r29, -0x76c4(r13)
    b	_800705e8
_800705d8:
    subf	r0, r31, r3
    stw	r29, -0x76c4(r13)
    add	r0, r29, r0
    stw	r0, -0x76c8(r13)
_800705e8:
    li	r0, 0
    mr	r3, r30
    stb	r0, -0x7d9f(r13)
    bl      OSSetArenaLo
    mr	r3, r29
    bl      OSSetArenaHi
    bl      fn_80070A58
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80070620(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      VIGetTvFormat
    cmpwi	r3, 1
    beq	_80070684
    bge	_80070650
    cmpwi	r3, 0
    bge	_8007065c
    b	_800706a4
_80070650:
    cmpwi	r3, 3
    bge	_800706a4
    b	_80070694
_8007065c:
    cmpwi	r31, 0
    beq	_80070674
    lis     r3, lbl_8012B030@ha
    addi	r0, r3, lbl_8012B030@l
    stw	r0, -0x76cc(r13)
    b	_800706c0
_80070674:
    lis     r3, lbl_8012AFB8@ha
    addi	r0, r3, lbl_8012AFB8@l
    stw	r0, -0x76cc(r13)
    b	_800706c0
_80070684:
    lis     r3, lbl_8012B0A8@ha
    addi	r0, r3, lbl_8012B0A8@l
    stw	r0, -0x76cc(r13)
    b	_800706c0
_80070694:
    lis     r3, lbl_8012B06C@ha
    addi	r0, r3, lbl_8012B06C@l
    stw	r0, -0x76cc(r13)
    b	_800706c0
_800706a4:
    lis     r3, lbl_8015AA78@ha
    lis     r5, lbl_8015AB24@ha
    addi	r3, r3, lbl_8015AA78@l
    li	r4, 0x157
    addi	r5, r5, lbl_8015AB24@l
    crxor	6, 6, 6
    bl      OSPanic
_800706c0:
    lis     r4, lbl_8019E150@ha
    lwz	r3, -0x76cc(r13)
    addi	r4, r4, lbl_8019E150@l
    li	r5, 0
    li	r6, 0x10
    bl      GXAdjustForOverscan
    lis     r3, lbl_8019E150@ha
    addi	r3, r3, lbl_8019E150@l
    stw	r3, -0x76cc(r13)
    bl      fn_8001B42C
    li	r0, 1
    stb	r0, -0x76d6(r13)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80070704(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lbz	r0, -0x76d6(r13)
    cmpw	r3, r0
    beq	_8007074c
    clrlwi.	r0, r3, 0x18
    lis     r4, lbl_8012AFF4@ha
    stb	r3, -0x76d6(r13)
    addi	r5, r4, lbl_8012AFF4@l
    beq	_80070738
    lis     r3, lbl_8012AFB8@ha
    addi	r5, r3, lbl_8012AFB8@l
_80070738:
    lbz	r3, 0x19(r5)
    addi	r4, r5, 0x1a
    addi	r6, r5, 0x32
    li	r5, 1
    bl      GXSetCopyClear
_8007074c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8007075C(void)
{
    nofralloc
    cmpwi	r3, 0
    beqlr	
    lwz	r0, -0x76e0(r13)
    ori	r0, r0, 0x30
    stw	r0, -0x76e0(r13)
    blr	
}

#pragma pop
