extern void DVDInit(void);
extern void OSGetArenaHi(void);
extern void OSGetArenaLo(void);
extern void OSGetProgressiveMode(void);
extern void OSGetResetCode(void);
extern void OSGetSaveRegion(void);
extern void OSGetTick(void);
extern void OSInit(void);
extern void OSLink(void);
extern void OSSetArenaHi(void);
extern void OSSetArenaLo(void);
extern void OSSetStringTable(void);
extern void OSUnlink(void);
extern void fn_80005660(void);
extern void fn_80005738(void);
extern void fn_800057CC(void);
extern void fn_800057F8(void);
extern void fn_80005858(void);
extern void fn_800058D8(void);
extern void fn_8000591C(void);
extern void fn_80005A08(void);
extern void fn_80005AD0(void);
extern void fn_80005B10(void);
extern void fn_80005E0C(void);
extern void fn_80006354(void);
extern void fn_800063AC(void);
extern void fn_80006AFC(void);
extern void fn_80006B30(void);
extern void fn_800071B8(void);
extern void fn_80007A44(void);
extern void fn_8000B360(void);
extern void fn_80017160(void);
extern void fn_80017228(void);
extern void fn_8001AAB4(void);
extern void fn_8001CD68(void);
extern void fn_8001DBC8(void);
extern void fn_80037518(void);
extern void fn_80037D40(void);
extern void fn_8006B188(void);
extern void fn_8006CCC8(void);
extern void fn_8006CD40(void);
extern void fn_8006CDFC(void);
extern void fn_8006CE1C(void);
extern void fn_8006CFF8(void);
extern void fn_8006FCB4(void);
extern void fn_8006FD1C(void);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FF8C(void);
extern void fn_80070158(void);
extern void fn_800702E4(void);
extern void fn_80070538(void);
extern void fn_80070620(void);
extern void fn_8007075C(void);
extern void fn_80070774(void);
extern void fn_80070AC0(void);
extern void fn_800721FC(void);
extern void fn_800728A8(void);
extern void fn_80072BD0(void);
extern void fn_800791A4(void);
extern void fn_800793D4(void);
extern void main(void);
extern void memcpy(void);
extern void memset(void);

#pragma push
#pragma force_active on

asm void main(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      OSGetResetCode
    lis	r0, -0x8000
    subf	r0, r3, r0
    cntlzw	r0, r0
    rlwinm.	r0, r0, 0x1b, 5, 0x1f
    beq     _80005608
    bl      fn_800057F8
_80005608:
    lis	r4, 0x4c00
    lis	r3, -0x8000
    addi	r4, r4, 0x64
    li	r0, 0
    stw	r4, 0x200(r3)
    stw	r4, 0x300(r3)
    stw	r4, 0x400(r3)
    stw	r4, 0x600(r3)
    stw	r4, 0x700(r3)
    stw	r4, 0xc00(r3)
    stw	r4, 0xd00(r3)
    stw	r4, 0x1000(r3)
    stw	r4, 0x1100(r3)
    stw	r4, 0x1200(r3)
    stw	r4, 0x1300(r3)
    stw	r0, -0x7d0c(r13)
    bl      fn_80005660
    bl      fn_8000591C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80005660(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      OSInit
    bl      DVDInit
    bl      fn_80006AFC
    lis	r3, -0x8000
    addi	r3, r3, 0x6354
    bl      fn_80006B30
    bl      fn_8001AAB4
    bl      fn_8006CFF8
    li	r3, 1
    bl      fn_80070158
    li	r3, 1
    bl      fn_8007075C
    li	r3, 1
    bl      fn_8006FF8C
    bl      fn_80070538
    bl      fn_800071B8
    bl      OSGetResetCode
    lis	r0, -0x8000
    subf	r0, r3, r0
    cntlzw	r0, r0
    rlwinm.	r0, r0, 0x1b, 5, 0x1f
    beq     _800056dc
    bl      OSGetProgressiveMode
    cmplwi	r3, 0
    beq     _800056dc
    li	r3, 1
    bl      fn_80070620
    b       _800056e4
_800056dc:
    li	r3, 0
    bl      fn_80070620
_800056e4:
    li	r3, 1
    lis	r4, 0xc
    li	r5, 1
    bl      fn_80070774
    bl      fn_8006FCB4
    bl      fn_8006CCC8
    lfs	f1, -0x8000(r2)
    bl      fn_8006CD40
    li	r3, 0x20
    li	r4, 1
    bl      fn_80070AC0
    bl      fn_80005738
    bl      fn_800057CC
    bl      fn_800058D8
    bl      fn_800063AC
    bl      fn_80005A08
    bl      fn_80005858
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80005738(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lfs	f1, -0x7ffc(r2)
    stw	r0, 0x14(r1)
    lfs	f2, -0x7ff8(r2)
    lwz	r0, -0x7540(r2)
    lfs	f3, -0x7ff4(r2)
    stw	r0, 0xc(r1)
    lfs	f4, -0x7ff0(r2)
    bl      fn_800721FC
    li	r3, 1
    bl      fn_80072BD0
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      fn_800728A8
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 4
    li	r7, 0
    bl      fn_80037518
    li	r3, 0
    li	r4, 0
    bl      fn_80037D40
    bl      fn_80007A44
    lwz	r0, 0xc(r1)
    addi	r3, r1, 8
    stw	r0, 8(r1)
    bl      fn_8006CDFC
    lfs	f1, -0x7fec(r2)
    bl      fn_8006CE1C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800057CC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r3, 3
    stw	r0, 0x14(r1)
    bl      fn_800702E4
    stw	r3, -0x7cf4(r13)
    bl      fn_800791A4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800057F8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    addi	r3, r1, 0xc
    addi	r4, r1, 8
    bl      OSGetSaveRegion
    lwz	r4, 0xc(r1)
    cmplwi	r4, 0
    beq     _80005828
    lwz	r0, 8(r1)
    cmplwi	r0, 0
    bne     _8000583c
_80005828:
    addi	r3, r13, -0x7d10
    li	r4, 0
    li	r5, 4
    bl      memset
    b       _80005848
_8000583c:
    addi	r3, r13, -0x7d10
    li	r5, 4
    bl      memcpy
_80005848:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80005858(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    addi	r3, r13, -0x7ffc
    stw	r0, 0x54(r1)
    addi	r4, r1, 8
    stw	r31, 0x4c(r1)
    bl      fn_80017160
    cmpwi	r3, 0
    beq     _800058c4
    lwz	r3, 0x3c(r1)
    li	r4, 0x20
    addi	r0, r3, 0x1f
    rlwinm	r31, r0, 0, 0, 0x1a
    mr	r3, r31
    bl      fn_8000B360
    mr	r5, r31
    mr	r31, r3
    addi	r3, r1, 8
    li	r6, 0
    mr	r4, r31
    bl      fn_80006354
    cmpwi	r3, 0
    beq     _800058bc
    mr	r3, r31
    bl      OSSetStringTable
_800058bc:
    addi	r3, r1, 8
    bl      fn_80017228
_800058c4:
    lwz	r0, 0x54(r1)
    lwz	r31, 0x4c(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_800058D8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lbz	r0, -0x7d14(r13)
    cmplwi	r0, 0
    bne     _8000590c
    bl      fn_8001CD68
    li	r3, 3
    bl      fn_8001DBC8
    bl      fn_8006B188
    lbz	r3, -0x7d14(r13)
    addi	r0, r3, 1
    stb	r0, -0x7d14(r13)
_8000590c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8000591C(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    stw	r0, 0x64(r1)
    stw	r31, 0x5c(r1)
    stw	r30, 0x58(r1)
    stw	r29, 0x54(r1)
    stw	r28, 0x50(r1)
    bl      OSGetArenaHi
    mr	r29, r3
    bl      OSGetTick
    clrlwi	r4, r3, 0x1b
    lis	r3, -0x7ff7
    addi	r0, r4, 1
    addi	r4, r1, 8
    addi	r3, r3, 0x5ea0
    slwi	r30, r0, 5
    bl      fn_80017160
    lwz	r3, 0x3c(r1)
    li	r4, 0x20
    addi	r0, r3, 0x1f
    rlwinm	r28, r0, 0, 0, 0x1a
    add	r31, r28, r30
    mr	r3, r31
    bl      fn_8000B360
    mr	r30, r3
    mr	r5, r28
    addi	r3, r1, 8
    li	r6, 0
    mr	r4, r30
    bl      fn_80006354
    addi	r3, r1, 8
    bl      fn_80017228
    mr	r3, r30
    li	r4, 0
    bl      OSLink
    lwz	r12, 0x34(r30)
    mtctr	r12
    bctrl	
    mr	r0, r3
    mr	r3, r30
    mr	r28, r0
    bl      OSUnlink
    mr	r3, r30
    clrlwi	r4, r31, 0x18
    li	r5, 0
    bl      fn_800793D4
    mr	r3, r29
    bl      OSSetArenaHi
    mr	r12, r28
    mtctr	r12
    bctrl	
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    lwz	r30, 0x58(r1)
    lwz	r29, 0x54(r1)
    lwz	r28, 0x50(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr	
}

asm void fn_80005A08(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    bl      OSGetArenaLo
    mr	r29, r3
    bl      OSGetArenaHi
    lis	r4, -0x7fea
    mr	r28, r3
    addi	r0, r4, -0x46e0
    mr	r3, r0
    bl      fn_80005AD0
    li	r30, 0
_80005a48:
    bl      fn_80005E0C
    addi	r30, r30, 1
    cmpwi	r30, 0x14
    blt     _80005a48
    lis	r3, -0x7fea
    li	r30, 0
    addi	r31, r3, -0x46e0
_80005a64:
    bl      fn_8006FD1C
    mr	r3, r31
    bl      fn_80005B10
    bl      fn_80005E0C
    bl      fn_80005E0C
    bl      fn_8006FDEC
    bl      fn_8006FEFC
    addi	r30, r30, 1
    cmpwi	r30, 5
    blt     _80005a64
    li	r31, 0
_80005a90:
    bl      fn_80005E0C
    addi	r31, r31, 1
    cmpwi	r31, 0x14
    blt     _80005a90
    mr	r3, r29
    bl      OSSetArenaLo
    mr	r3, r28
    bl      OSSetArenaHi
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
