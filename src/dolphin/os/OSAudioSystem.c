#pragma push
#pragma force_active on

typedef unsigned int u32;

extern void* OSGetArenaHi(void);
extern void* memcpy(register void* dst, register const void* src, register unsigned long n);
extern void DCFlushRange(register void* addr, register unsigned long n);
extern unsigned long OSGetTick(void);
extern unsigned char DSPInitCode[128];

asm void* OSInitArenaPoll(register u32 size, register u32 align)
{
    nofralloc
    lwz	r0, -0x7f98(r13)
    addi	r4, r4, -1
    nor	r5, r4, r4
    add	r0, r0, r4
    and	r6, r5, r0
    add	r0, r6, r3
    add	r0, r0, r4
    and	r0, r5, r0
    stw	r0, -0x7f98(r13)
    mr	r3, r6
    blr	
}

asm void* fn_8000B360(register u32 size, register u32 align)
{
    nofralloc
    addi	r0, r4, -1
    lwz	r4, -0x7c30(r13)
    nor	r0, r0, r0
    and	r4, r4, r0
    subf	r4, r3, r4
    and	r3, r4, r0
    stw	r3, -0x7c30(r13)
    blr	
}

asm void __OSInitAudioSystem(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stmw	r25, 0x14(r1)
    bl      OSGetArenaHi
    lis	r4, -0x7f00
    li	r5, 0x80
    addi	r3, r3, -0x80
    bl      memcpy
    lis	r3, DSPInitCode@ha
    addi	r4, r3, DSPInitCode@l
    lis	r3, -0x7f00
    li	r5, 0x80
    bl      memcpy
    lis	r3, -0x7f00
    li	r4, 0x80
    bl      DCFlushRange
    lis	r3, -0x3400
    addi	r3, r3, 0x5000
    li	r0, 0x43
    sth	r0, 0x12(r3)
    addi	r31, r3, 0xa
    li	r0, 0x8ac
    sth	r0, 0xa(r3)
    lhz	r0, 0xa(r3)
    ori	r0, r0, 1
    sth	r0, 0xa(r3)
_8000b3ec:
    lhz	r0, 0(r31)
    clrlwi.	r0, r0, 0x1f
    bne     _8000b3ec
    li	r0, 0
    lis	r4, -0x3400
    sth	r0, 0x5000(r4)
_8000b404:
    addi	r30, r4, 0x5000
    lhzu	r3, 4(r30)
    addi	r29, r4, 0x5000
    lhzu	r0, 6(r29)
    rlwimi	r0, r3, 0x10, 0, 0xf
    rlwinm.	r0, r0, 0, 0, 0
    bne     _8000b404
    lis	r3, -0x3400
    lis	r0, 0x100
    addi	r27, r3, 0x5000
    stwu	r0, 0x20(r27)
    li	r0, 0
    addi	r26, r3, 0x5000
    stwu	r0, 0x24(r26)
    li	r0, 0x20
    addi	r25, r3, 0x5000
    stwu	r0, 0x28(r25)
    lhz	r3, 0(r31)
    b       _8000b454
_8000b450:
    lhz	r3, 0(r31)
_8000b454:
    rlwinm.	r0, r3, 0, 0x1a, 0x1a
    beq     _8000b450
    sth	r3, 0(r31)
    bl      OSGetTick
    mr	r28, r3
_8000b468:
    bl      OSGetTick
    subf	r0, r28, r3
    cmpwi	r0, 0x892
    blt     _8000b468
    lis	r0, 0x100
    stw	r0, 0(r27)
    li	r3, 0
    li	r0, 0x20
    stw	r3, 0(r26)
    stw	r0, 0(r25)
    lhz	r3, 0(r31)
    b       _8000b49c
_8000b498:
    lhz	r3, 0(r31)
_8000b49c:
    rlwinm.	r0, r3, 0, 0x1a, 0x1a
    beq     _8000b498
    sth	r3, 0(r31)
    lhz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x15, 0x13
    sth	r0, 0(r31)
_8000b4b4:
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x15, 0x15
    bne     _8000b4b4
    lhz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x1e, 0x1c
    sth	r0, 0(r31)
    lhz	r0, 0(r30)
    b       _8000b4d8
_8000b4d4:
    lhz	r0, 0(r30)
_8000b4d8:
    clrlwi	r5, r0, 0x10
    rlwinm.	r0, r0, 0, 0x10, 0x10
    beq     _8000b4d4
    lhz	r0, 0(r31)
    lhz	r4, 0(r29)
    ori	r0, r0, 4
    sth	r0, 0(r31)
    li	r0, 0x8ac
    sth	r0, 0(r31)
    lhz	r0, 0(r31)
    ori	r0, r0, 1
    sth	r0, 0(r31)
_8000b508:
    lhz	r0, 0(r31)
    clrlwi.	r0, r0, 0x1f
    bne     _8000b508
    bl      OSGetArenaHi
    addi	r4, r3, -0x80
    lis	r3, -0x7f00
    li	r5, 0x80
    bl      memcpy
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void __OSStopAudioSystem(void)
{
    nofralloc
    mflr	r0
    lis	r3, -0x3400
    stw	r0, 4(r1)
    li	r0, 0x804
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, 0x5000
    addi	r3, r3, 0x5000
    stw	r30, 8(r1)
    sth	r0, 0xa(r31)
    lhz	r0, 0x36(r3)
    rlwinm	r0, r0, 0, 0x11, 0xf
    sth	r0, 0x36(r3)
    lhzu	r0, 0xa(r31)
    b       _8000b57c
_8000b578:
    lhz	r0, 0(r31)
_8000b57c:
    rlwinm.	r0, r0, 0, 0x15, 0x15
    bne     _8000b578
    lhz	r0, 0(r31)
    b       _8000b590
_8000b58c:
    lhz	r0, 0(r31)
_8000b590:
    rlwinm.	r0, r0, 0, 0x16, 0x16
    bne     _8000b58c
    li	r0, 0x8ac
    lis	r3, -0x3400
    sth	r0, 0(r31)
    li	r0, 0
    sth	r0, 0x5000(r3)
    addi	r4, r3, 0x5000
_8000b5b0:
    lhz	r3, 4(r4)
    lhz	r0, 6(r4)
    rlwimi	r0, r3, 0x10, 0, 0xf
    rlwinm.	r0, r0, 0, 0, 0
    bne     _8000b5b0
    bl      OSGetTick
    mr	r30, r3
_8000b5cc:
    bl      OSGetTick
    subf	r0, r30, r3
    cmpwi	r0, 0x2c
    blt     _8000b5cc
    lhz	r0, 0(r31)
    ori	r0, r0, 1
    sth	r0, 0(r31)
    lhz	r0, 0(r31)
    b       _8000b5f4
_8000b5f0:
    lhz	r0, 0(r31)
_8000b5f4:
    clrlwi.	r0, r0, 0x1f
    bne     _8000b5f0
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

#pragma pop
