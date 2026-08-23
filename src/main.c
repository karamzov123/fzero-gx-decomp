extern void fn_80005660(void);
extern void fn_80005738(void);
extern void OSGetResetCode(void);
extern void fn_800057F8(void);
extern void fn_8000591C(void);
extern void OSInit(void);
extern void DVDInit(void);
extern void fn_80006AFC(void);
extern void fn_80006B30(void);
extern void fn_8001AAB4(void);
extern void fn_8006CFF8(void);
extern void fn_80070158(void);
extern void fn_8007075C(void);
extern void fn_8006FF8C(void);
extern void fn_80070538(void);
extern void fn_80070620(void);
extern void fn_80070774(void);
extern void fn_8006FCB4(void);
extern void fn_8006CCC8(void);
extern void fn_8006CD40(void);
extern void fn_80070AC0(void);
extern void fn_800071B8(void);
extern void OSGetProgressiveMode(void);
extern void fn_80037518(void);
extern void fn_80037D40(void);
extern void fn_80007A44(void);
extern void fn_800057CC(void);
extern void fn_800058D8(void);
extern void fn_800063AC(void);
extern void fn_80005A08(void);
extern void fn_80005858(void);
extern void fn_800721FC(void);
extern void fn_80072BD0(void);
extern void fn_800728A8(void);
extern void fn_8006CDFC(void);
extern void fn_8006CE1C(void);

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

#pragma pop
