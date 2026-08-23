extern void DCStoreRange(void);
extern void DVDInit(void);
extern void GXBegin(void);
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
extern void _restgpr_23(void);
extern void _savegpr_23(void);
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
extern void fn_80005EDC(void);
extern void fn_800060D8(void);
extern void fn_80006334(void);
extern void fn_80006340(void);
extern void fn_80006354(void);
extern void fn_800063AC(void);
extern void fn_8000659C(void);
extern void fn_80006914(void);
extern void fn_80006AEC(void);
extern void fn_80006AFC(void);
extern void fn_80006B30(void);
extern void fn_800071B8(void);
extern void fn_80007A44(void);
extern void fn_8000B334(void);
extern void fn_8000B360(void);
extern void fn_8000CDD8(void);
extern void fn_8000CEBC(void);
extern void fn_8000D1F0(void);
extern void fn_80015EE8(void);
extern void fn_80017160(void);
extern void fn_80017228(void);
extern void fn_800174D0(void);
extern void fn_8001AAB4(void);
extern void fn_8001CD68(void);
extern void fn_8001DBC8(void);
extern void fn_80035C50(void);
extern void fn_80036544(void);
extern void fn_800371F8(void);
extern void fn_80037518(void);
extern void fn_800377F8(void);
extern void fn_80037D40(void);
extern void fn_80038C5C(void);
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
extern void fn_80071ED4(void);
extern void fn_800721FC(void);
extern void fn_800723F8(void);
extern void fn_8007245C(void);
extern void fn_80072864(void);
extern void fn_800728A8(void);
extern void fn_80072AB0(void);
extern void fn_80072BD0(void);
extern void fn_80072C24(void);
extern void fn_80072CC4(void);
extern void fn_80072D64(void);
extern void fn_80072E20(void);
extern void fn_80072EDC(void);
extern void fn_800734A8(void);
extern void fn_80073678(void);
extern void fn_80073778(void);
extern void fn_800737E4(void);
extern void fn_80073898(void);
extern void fn_80073C6C(void);
extern void fn_800745A4(void);
extern void fn_80074660(void);
extern void fn_80074788(void);
extern void fn_800747D0(void);
extern void fn_80074918(void);
extern void fn_800791A4(void);
extern void fn_800793D4(void);
extern void lbl_8006D758(void);
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
    bc      12, 2, _80005608
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
    bc      12, 2, _800056dc
    bl      OSGetProgressiveMode
    cmplwi	r3, 0
    bc      12, 2, _800056dc
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
    bc      12, 2, _80005828
    lwz	r0, 8(r1)
    cmplwi	r0, 0
    bc      4, 2, _8000583c
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
    bc      12, 2, _800058c4
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
    bc      12, 2, _800058bc
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
    bc      4, 2, _8000590c
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
    bc      12, 0, _80005a48
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
    bc      12, 0, _80005a64
    li	r31, 0
_80005a90:
    bl      fn_80005E0C
    addi	r31, r31, 1
    cmpwi	r31, 0x14
    bc      12, 0, _80005a90
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

asm void fn_80005AD0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r5, 0x280
    li	r6, 0x1e0
    stw	r0, 0x14(r1)
    li	r7, 0xe
    li	r8, 0
    li	r9, 0
    lwz	r4, -0x7ff0(r13)
    li	r10, 0
    bl      fn_80035C50
    bl      fn_80036544
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80005B10(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    stw	r0, 0x74(r1)
    stw	r31, 0x6c(r1)
    mr	r31, r3
    lwz	r0, -0x7fe8(r2)
    stw	r0, 0x18(r1)
    bl      fn_800723F8
    li	r3, 0x2200
    bl      fn_8007245C
    bl      fn_800723F8
    li	r3, 0
    bl      fn_80074788
    li	r3, 1
    bl      fn_80074660
    li	r3, 1
    bl      fn_80073678
    li	r3, 0
    bl      fn_80073898
    li	r3, 0
    bl      fn_80073C6C
    li	r3, 0
    li	r4, 0
    bl      fn_80072EDC
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl      fn_800745A4
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0xff
    bl      fn_800734A8
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      fn_80072AB0
    li	r3, 0
    li	r4, 0xf
    li	r5, 2
    li	r6, 8
    li	r7, 4
    bl      fn_80072C24
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      fn_80072D64
    li	r3, 0
    li	r4, 7
    li	r5, 1
    li	r6, 4
    li	r7, 2
    bl      fn_80072CC4
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      fn_80072E20
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 0
    li	r8, 2
    li	r9, 2
    bl      fn_800747D0
    lwz	r0, 0x18(r1)
    addi	r4, r1, 0x14
    li	r3, 1
    stw	r0, 0x14(r1)
    bl      fn_800371F8
    li	r3, 1
    li	r4, 1
    li	r5, 1
    bl      fn_80074918
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      fn_800728A8
    lfs	f1, -0x7fe4(r2)
    addi	r4, r1, 0x10
    lfs	f2, -0x7fe0(r2)
    li	r3, 0
    lwz	r0, -0x7538(r2)
    fmr	f3, f1
    fmr	f4, f2
    stw	r0, 0x10(r1)
    bl      fn_800377F8
    li	r3, 2
    bl      fn_80072864
    bl      lbl_8006D758
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      fn_80038C5C
    lfs	f1, -0x7fe4(r2)
    addi	r3, r1, 0x1c
    lfs	f2, -0x7fdc(r2)
    fmr	f3, f1
    lfs	f4, -0x7fd8(r2)
    fmr	f5, f1
    lfs	f6, -0x7fd4(r2)
    bl      fn_80015EE8
    addi	r3, r1, 0x1c
    li	r4, 1
    bl      fn_800737E4
    li	r0, 0xff
    addi	r4, r1, 0xc
    stb	r0, 0x18(r1)
    li	r3, 1
    stb	r0, 0x19(r1)
    stb	r0, 0x1a(r1)
    stb	r0, 0x1b(r1)
    lwz	r0, 0x18(r1)
    stw	r0, 0xc(r1)
    bl      fn_800371F8
    li	r0, 0
    addi	r4, r1, 8
    stb	r0, 0x18(r1)
    li	r3, 2
    stb	r0, 0x19(r1)
    stb	r0, 0x1a(r1)
    stb	r0, 0x1b(r1)
    lwz	r0, 0x18(r1)
    stw	r0, 8(r1)
    bl      fn_800371F8
    mr	r3, r31
    li	r4, 0
    bl      fn_80073778
    li	r3, 0x80
    li	r4, 7
    li	r5, 4
    bl      GXBegin
    lfs	f3, -0x7fd0(r2)
    lis	r3, -0x33ff
    lfd	f2, -0x7fc8(r2)
    lfs	f1, -0x7fc0(r2)
    lfd	f0, -0x7fb8(r2)
    fsub	f4, f3, f2
    fadd	f5, f2, f3
    fsub	f2, f1, f0
    frsp	f4, f4
    fadd	f0, f0, f1
    frsp	f3, f2
    stfs	f4, -0x8000(r3)
    frsp	f2, f5
    frsp	f1, f0
    stfs	f3, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    stfs	f4, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, -0x7fb0(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fe4(r2)
    stfs	f0, -0x8000(r3)
    lfs	f0, -0x7fac(r2)
    stfs	f0, -0x8000(r3)
    lwz	r31, 0x6c(r1)
    lwz	r0, 0x74(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr	
}

asm void fn_80005E0C(void)
{
    nofralloc
    addi	r3, r13, -0x7cf0
    li	r0, 0x32
    addis	r3, r3, 0x4000
    li	r4, 0
    mtctr	r0
_80005e20:
    mr	r0, r3
    li	r5, 0xc8
_80005e28:
    stw	r5, 0(r3)
    addic.	r5, r5, -1
    bc      4, 2, _80005e28
    li	r5, 0x76c
_80005e38:
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    addic.	r5, r5, -1
    bc      4, 2, _80005e38
    li	r5, 0x76c
_80005e60:
    mfibatu	r0, 0
    ps_sub	f0, f0, f0
    mfibatu	r0, 0
    ps_sub	f1, f1, f1
    addic.	r5, r5, -1
    bc      5, 2, _80005e60
    mr	r0, r3
    li	r5, 0xc8
_80005e80:
    stw	r5, 0(r3)
    addic.	r5, r5, -1
    bc      4, 2, _80005e80
    li	r5, 0x76c
_80005e90:
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    add	r0, r0, r0
    addic.	r5, r5, -1
    bc      4, 2, _80005e90
    li	r5, 0x76c
_80005eb8:
    mfibatu	r0, 0
    ps_sub	f0, f0, f0
    mfibatu	r0, 0
    ps_sub	f1, f1, f1
    addic.	r5, r5, -1
    bc      5, 2, _80005eb8
    addi	r4, r4, 1
    bc      16, 0, _80005e20
    blr	
}

asm void fn_80005EDC(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    li	r3, 0x2200
    stw	r0, 0x64(r1)
    lwz	r0, -0x7fa8(r2)
    stw	r0, 0x14(r1)
    bl      fn_8007245C
    li	r3, 0
    bl      fn_80074788
    li	r3, 1
    bl      fn_80074660
    li	r3, 1
    bl      fn_80073678
    li	r3, 0
    bl      fn_80073C6C
    li	r3, 0
    li	r4, 0
    bl      fn_80072EDC
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl      fn_800745A4
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0xff
    bl      fn_800734A8
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      fn_80072AB0
    li	r3, 0
    li	r4, 0xf
    li	r5, 2
    li	r6, 8
    li	r7, 4
    bl      fn_80072C24
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      fn_80072D64
    li	r3, 0
    li	r4, 7
    li	r5, 1
    li	r6, 4
    li	r7, 2
    bl      fn_80072CC4
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 1
    li	r8, 0
    bl      fn_80072E20
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 0
    li	r8, 2
    li	r9, 2
    bl      fn_800747D0
    lwz	r0, 0x14(r1)
    addi	r4, r1, 0x10
    li	r3, 1
    stw	r0, 0x10(r1)
    bl      fn_800371F8
    li	r3, 1
    li	r4, 7
    li	r5, 0
    bl      fn_80074918
    li	r3, 1
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl      fn_800728A8
    lfs	f1, -0x7fa4(r2)
    li	r3, 0
    lfs	f2, -0x7fa0(r2)
    bl      fn_80071ED4
    li	r3, 2
    bl      fn_80072864
    bl      lbl_8006D758
    lwz	r3, -0x76c0(r13)
    li	r4, 0
    bl      fn_80038C5C
    lfs	f1, -0x7fa4(r2)
    addi	r3, r1, 0x18
    lfs	f2, -0x7f9c(r2)
    fmr	f3, f1
    lfs	f4, -0x7f98(r2)
    fmr	f5, f1
    lfs	f6, -0x7fa0(r2)
    bl      fn_80015EE8
    addi	r3, r1, 0x18
    li	r4, 1
    bl      fn_800737E4
    li	r0, 0xff
    addi	r4, r1, 0xc
    stb	r0, 0x14(r1)
    li	r3, 1
    stb	r0, 0x15(r1)
    stb	r0, 0x16(r1)
    stb	r0, 0x17(r1)
    lwz	r0, 0x14(r1)
    stw	r0, 0xc(r1)
    bl      fn_800371F8
    li	r0, 0
    addi	r4, r1, 8
    stb	r0, 0x14(r1)
    li	r3, 2
    stb	r0, 0x15(r1)
    stb	r0, 0x16(r1)
    stb	r0, 0x17(r1)
    lwz	r0, 0x14(r1)
    stw	r0, 8(r1)
    bl      fn_800371F8
    lwz	r0, 0x64(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr	
}

asm void fn_800060D8(void)
{
    nofralloc
    stwu	r1, -0xb0(r1)
    mflr	r0
    stw	r0, 0xb4(r1)
    stfd	f31, 0xa0(r1)
    psq_st	f31, 0xa8(r1), 0, 0
    stfd	f30, 0x90(r1)
    psq_st	f30, 0x98(r1), 0, 0
    stfd	f29, 0x80(r1)
    psq_st	f29, 0x88(r1), 0, 0
    stfd	f28, 0x70(r1)
    psq_st	f28, 0x78(r1), 0, 0
    stfd	f27, 0x60(r1)
    psq_st	f27, 0x68(r1), 0, 0
    stfd	f26, 0x50(r1)
    psq_st	f26, 0x58(r1), 0, 0
    stw	r31, 0x4c(r1)
    stw	r30, 0x48(r1)
    fmr	f28, f2
    lfd	f0, -0x7f90(r2)
    fmr	f27, f1
    mr	r30, r3
    fneg	f30, f3
    fadd	f31, f0, f28
    b       _800062e0
_80006138:
    mr	r3, r30
    bl      fn_80006334
    cmpwi	r3, 0
    bc      12, 2, _80006154
    lhz	r4, 0(r30)
    addi	r30, r30, 2
    b       _8000615c
_80006154:
    lbz	r4, 0(r30)
    addi	r30, r30, 1
_8000615c:
    cmplwi	r4, 0x20
    bc      4, 2, _80006174
    lfd	f0, -0x7f88(r2)
    fadd	f27, f27, f0
    frsp	f27, f27
    b       _800062e0
_80006174:
    lha	r0, -0x7cd4(r13)
    lis	r3, -0x7fea
    addi	r31, r3, -0x46c0
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _800061a4
_8000618c:
    lhz	r0, 4(r31)
    cmpw	r0, r4
    bc      4, 2, _8000619c
    b       _800061a8
_8000619c:
    addi	r31, r31, 8
    bc      16, 0, _8000618c
_800061a4:
    li	r31, 0
_800061a8:
    cmplwi	r31, 0
    bc      12, 2, _800062e0
    lwz	r4, 0(r31)
    addi	r3, r1, 8
    li	r5, 0x18
    li	r6, 0x18
    li	r7, 0
    li	r8, 0
    li	r9, 0
    li	r10, 0
    bl      fn_80035C50
    bl      fn_80036544
    addi	r3, r1, 8
    li	r4, 0
    bl      fn_80073778
    lhz	r4, 6(r31)
    lis	r0, 0x4330
    stw	r0, 0x28(r1)
    frsp	f29, f31
    lfd	f1, -0x7f78(r2)
    li	r3, 0x80
    stw	r4, 0x2c(r1)
    li	r4, 7
    li	r5, 4
    lfd	f0, 0x28(r1)
    fsubs	f0, f0, f1
    fadds	f26, f27, f0
    bl      GXBegin
    lis	r4, -0x33ff
    lis	r0, 0x4330
    stfs	f27, -0x8000(r4)
    lfd	f2, -0x7f78(r2)
    stfs	f28, -0x8000(r4)
    lfd	f1, -0x7f90(r2)
    stfs	f30, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stw	r0, 0x30(r1)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stw	r0, 0x38(r1)
    stfs	f0, -0x8000(r4)
    stfs	f26, -0x8000(r4)
    stfs	f28, -0x8000(r4)
    stfs	f30, -0x8000(r4)
    lhz	r3, 6(r31)
    stw	r0, 0x40(r1)
    stw	r3, 0x34(r1)
    lfd	f0, 0x30(r1)
    fsub	f0, f0, f2
    fdiv	f0, f0, f1
    frsp	f0, f0
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stfs	f0, -0x8000(r4)
    stfs	f26, -0x8000(r4)
    stfs	f29, -0x8000(r4)
    stfs	f30, -0x8000(r4)
    lhz	r0, 6(r31)
    stw	r0, 0x3c(r1)
    lfd	f0, 0x38(r1)
    fsub	f0, f0, f2
    fdiv	f0, f0, f1
    frsp	f0, f0
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f80(r2)
    stfs	f0, -0x8000(r4)
    stfs	f27, -0x8000(r4)
    stfs	f29, -0x8000(r4)
    stfs	f30, -0x8000(r4)
    lfs	f0, -0x7fa4(r2)
    stfs	f0, -0x8000(r4)
    lfs	f0, -0x7f80(r2)
    stfs	f0, -0x8000(r4)
    lhz	r0, 6(r31)
    stw	r0, 0x44(r1)
    lfd	f0, 0x40(r1)
    fsubs	f0, f0, f2
    fadds	f27, f27, f0
_800062e0:
    lbz	r0, 0(r30)
    cmplwi	r0, 0
    bc      4, 2, _80006138
    psq_l	f31, 0xa8(r1), 0, 0
    lfd	f31, 0xa0(r1)
    psq_l	f30, 0x98(r1), 0, 0
    lfd	f30, 0x90(r1)
    psq_l	f29, 0x88(r1), 0, 0
    lfd	f29, 0x80(r1)
    psq_l	f28, 0x78(r1), 0, 0
    lfd	f28, 0x70(r1)
    psq_l	f27, 0x68(r1), 0, 0
    lfd	f27, 0x60(r1)
    psq_l	f26, 0x58(r1), 0, 0
    lfd	f26, 0x50(r1)
    lwz	r31, 0x4c(r1)
    lwz	r0, 0xb4(r1)
    lwz	r30, 0x48(r1)
    mtlr	r0
    addi	r1, r1, 0xb0
    blr	
}

asm void fn_80006334(void)
{
    nofralloc
    lbz	r0, 0(r3)
    rlwinm	r3, r0, 0x19, 0x1f, 0x1f
    blr	
}

asm void fn_80006340(void)
{
    nofralloc
    cmpwi	r3, -1
    beqlr	
    li	r0, 0
    stb	r0, -0x7ce5(r13)
    blr	
}

asm void fn_80006354(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r7, -0x8000
    li	r8, 2
    stw	r0, 0x14(r1)
    li	r0, 1
    addi	r7, r7, 0x6340
    stw	r31, 0xc(r1)
    mr	r31, r3
    stb	r0, -0x7ce5(r13)
    bl      fn_800174D0
    b       _80006388
_80006384:
    bl      fn_8000659C
_80006388:
    lbz	r0, -0x7ce5(r13)
    extsb.	r0, r0
    bc      4, 2, _80006384
    lwz	r0, 0x14(r1)
    lwz	r3, 0x34(r31)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800063AC(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    addi	r11, r1, 0x40
    bl      _savegpr_23
    bl      fn_8000CDD8
    clrlwi	r0, r3, 0x10
    cmplwi	r0, 1
    bc      4, 2, _800063e8
    lis	r3, -0x7fee
    li	r0, 6
    addi	r3, r3, 0x205c
    stw	r0, -0x7cd0(r13)
    stw	r3, -0x7ccc(r13)
    b       _800063fc
_800063e8:
    lis	r3, -0x7fee
    li	r0, 6
    addi	r3, r3, 0x205c
    stw	r0, -0x7cd0(r13)
    stw	r3, -0x7ccc(r13)
_800063fc:
    bl      OSGetArenaHi
    mr	r31, r3
    bl      fn_8000CDD8
    clrlwi	r0, r3, 0x10
    cmplwi	r0, 1
    bc      4, 2, _80006440
    lis	r3, 9
    li	r4, 0x20
    addi	r3, r3, 0xee4
    bl      fn_8000B360
    lis	r5, 5
    mr	r27, r3
    li	r4, 0x20
    addi	r3, r5, -0x3000
    bl      fn_8000B360
    mr	r4, r3
    b       _80006464
_80006440:
    lis	r3, 1
    li	r4, 0x20
    addi	r3, r3, 0x120
    bl      fn_8000B360
    mr	r27, r3
    li	r3, 0x3000
    li	r4, 0x20
    bl      fn_8000B360
    mr	r4, r3
_80006464:
    mr	r3, r27
    bl      fn_8000CEBC
    lwz	r27, -0x7ccc(r13)
    li	r28, 0
    b       _8000655c
_80006478:
    lwz	r29, 0(r27)
    li	r30, 0
    b       _80006548
_80006484:
    lwz	r23, 0(r29)
    lha	r24, -0x7cd4(r13)
    b       _80006530
_80006490:
    rlwinm.	r0, r5, 0, 0x18, 0x18
    mr	r26, r23
    bc      12, 2, _800064a8
    lhz	r5, 0(r23)
    addi	r23, r23, 2
    b       _800064ac
_800064a8:
    addi	r23, r23, 1
_800064ac:
    cmplwi	r5, 0x20
    bc      12, 2, _80006530
    lis	r3, -0x7fea
    li	r4, 0
    addi	r25, r3, -0x46c0
    mtctr	r24
    cmpwi	r24, 0
    bc      4, 1, _800064e4
_800064cc:
    lhz	r0, 4(r25)
    cmplw	r0, r5
    bc      12, 2, _800064e4
    addi	r4, r4, 1
    addi	r25, r25, 8
    bc      16, 0, _800064cc
_800064e4:
    cmpw	r4, r24
    bc      12, 0, _80006530
    sth	r5, 4(r25)
    li	r3, 0x120
    li	r4, 0x20
    bl      fn_8000B334
    stw	r3, 0(r25)
    mr	r3, r26
    addi	r7, r1, 8
    li	r5, 0
    lwz	r4, 0(r25)
    li	r6, 6
    bl      fn_8000D1F0
    lwz	r3, 0(r25)
    li	r4, 0x120
    bl      DCStoreRange
    lwz	r0, 8(r1)
    addi	r24, r24, 1
    sth	r0, 6(r25)
_80006530:
    lbz	r5, 0(r23)
    cmplwi	r5, 0
    bc      4, 2, _80006490
    sth	r24, -0x7cd4(r13)
    addi	r30, r30, 1
    addi	r29, r29, 4
_80006548:
    lwz	r0, 4(r27)
    cmpw	r30, r0
    bc      12, 0, _80006484
    addi	r28, r28, 1
    addi	r27, r27, 8
_8000655c:
    lwz	r0, -0x7cd0(r13)
    cmpw	r28, r0
    bc      12, 0, _80006478
    mr	r3, r31
    bl      OSSetArenaHi
    lis	r3, -0x8000
    addi	r3, r3, 0x691c
    bl      fn_80006914
    li	r3, 0
    bl      fn_80006AEC
    addi	r11, r1, 0x40
    bl      _restgpr_23
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

#pragma pop
