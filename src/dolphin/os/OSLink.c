typedef unsigned int u32;
typedef int BOOL;

extern void DCFlushRange(void* addr, u32 size);
extern void ICInvalidateRange(void* addr, u32 size);
extern void OSReport(const char* fmt, ...);
extern char lbl_80123A90[]; // .data:0x80123A90 string
extern void* memset(void* ptr, int value, u32 num);
extern void OSNotifyLink(void);
extern void OSNotifyUnlink(void);
extern BOOL Relocate(void* newModule, void* module);
extern BOOL __OSLinkModule(void* module, void* bss, int flag);
extern BOOL Undo(void* newModule, void* module);

#pragma push
#pragma force_active on

asm void OSNotifyLink(void)
{
    nofralloc
    blr	
}

asm void OSNotifyUnlink(void)
{
    nofralloc
    blr	
}

asm void OSSetStringTable(register const void* stringTable)
{
    nofralloc
    lis	r4, -0x8000
    stw	r3, 0x30d0(r4)
    blr	
}

asm BOOL Relocate(register void* newModule, register void* module)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x40(r1)
    stmw	r23, 0x1c(r1)
    or.	r26, r3, r3
    addi	r27, r4, 0
    beq     _8000dd98
    lwz	r31, 0(r26)
    b       _8000dd9c
_8000dd98:
    li	r31, 0
_8000dd9c:
    lwz	r3, 0x28(r27)
    lwz	r0, 0x2c(r27)
    addi	r4, r3, 0
    add	r3, r3, r0
    addi	r0, r3, 7
    subf	r0, r4, r0
    srwi	r0, r0, 3
    cmplw	r4, r3
    mtctr	r0
    bge     _8000ddd8
_8000ddc4:
    lwz	r0, 0(r4)
    cmplw	r0, r31
    beq     _8000dde0
    addi	r4, r4, 8
    bdnz    _8000ddc4
_8000ddd8:
    li	r3, 0
    b       _8000e01c
_8000dde0:
    lis	r3, lbl_80123A90@ha
    lwz	r30, 4(r4)
    addi	r25, r3, lbl_80123A90@l
    li	r29, 0
    b       _8000dfe4
_8000ddf4:
    lhz	r0, 0(r30)
    cmplwi	r31, 0
    add	r28, r28, r0
    beq     _8000de1c
    lbz	r0, 3(r30)
    lwz	r3, 0x10(r26)
    slwi	r0, r0, 3
    lwzx	r0, r3, r0
    rlwinm	r5, r0, 0, 0, 0x1e
    b       _8000de20
_8000de1c:
    li	r5, 0
_8000de20:
    cmpwi	r4, 6
    beq     _8000dee8
    bge     _8000de58
    cmpwi	r4, 2
    beq     _8000de98
    bge     _8000de48
    cmpwi	r4, 0
    beq     _8000dfe0
    bge     _8000de88
    b       _8000dfd4
_8000de48:
    cmpwi	r4, 4
    beq     _8000dec4
    bge     _8000ded4
    b       _8000deb4
_8000de58:
    cmpwi	r4, 0xc9
    beq     _8000dfe0
    bge     _8000de7c
    cmpwi	r4, 0xa
    beq     _8000df30
    blt     _8000df14
    cmpwi	r4, 0xe
    bge     _8000dfd4
    b       _8000df50
_8000de7c:
    cmpwi	r4, 0xcb
    bge     _8000dfd4
    b       _8000df70
_8000de88:
    lwz	r0, 4(r30)
    add	r0, r5, r0
    stw	r0, 0(r28)
    b       _8000dfe0
_8000de98:
    lwz	r0, 4(r30)
    lwz	r3, 0(r28)
    add	r0, r5, r0
    rlwinm	r3, r3, 0, 0x1e, 5
    rlwimi	r3, r0, 0, 6, 0x1d
    stw	r3, 0(r28)
    b       _8000dfe0
_8000deb4:
    lwz	r0, 4(r30)
    add	r0, r5, r0
    sth	r0, 0(r28)
    b       _8000dfe0
_8000dec4:
    lwz	r0, 4(r30)
    add	r0, r5, r0
    sth	r0, 0(r28)
    b       _8000dfe0
_8000ded4:
    lwz	r0, 4(r30)
    add	r0, r5, r0
    srwi	r0, r0, 0x10
    sth	r0, 0(r28)
    b       _8000dfe0
_8000dee8:
    lwz	r0, 4(r30)
    add	r4, r5, r0
    rlwinm.	r0, r4, 0, 0x10, 0x10
    beq     _8000df00
    li	r3, 1
    b       _8000df04
_8000df00:
    li	r3, 0
_8000df04:
    srwi	r0, r4, 0x10
    add	r0, r0, r3
    sth	r0, 0(r28)
    b       _8000dfe0
_8000df14:
    lwz	r0, 4(r30)
    lwz	r3, 0(r28)
    add	r0, r5, r0
    rlwinm	r3, r3, 0, 0x1e, 0xf
    rlwimi	r3, r0, 0, 0x10, 0x1d
    stw	r3, 0(r28)
    b       _8000dfe0
_8000df30:
    lwz	r0, 4(r30)
    lwz	r3, 0(r28)
    add	r0, r5, r0
    subf	r0, r28, r0
    rlwinm	r3, r3, 0, 0x1e, 5
    rlwimi	r3, r0, 0, 6, 0x1d
    stw	r3, 0(r28)
    b       _8000dfe0
_8000df50:
    lwz	r0, 4(r30)
    lwz	r3, 0(r28)
    add	r0, r5, r0
    subf	r0, r28, r0
    rlwinm	r3, r3, 0, 0x1e, 0xf
    rlwimi	r3, r0, 0, 0x10, 0x1d
    stw	r3, 0(r28)
    b       _8000dfe0
_8000df70:
    lbz	r0, 3(r30)
    cmplwi	r29, 0
    lwz	r3, 0x10(r27)
    slwi	r0, r0, 3
    add	r3, r3, r0
    lwz	r0, 0(r3)
    addi	r23, r3, 0
    rlwinm	r28, r0, 0, 0, 0x1e
    beq     _8000dfb4
    lwz	r0, 0(r29)
    lwz	r4, 4(r29)
    rlwinm	r24, r0, 0, 0, 0x1e
    addi	r3, r24, 0
    bl      DCFlushRange
    mr	r3, r24
    lwz	r4, 4(r29)
    bl      ICInvalidateRange
_8000dfb4:
    lwz	r0, 0(r23)
    clrlwi.	r0, r0, 0x1f
    beq     _8000dfc8
    mr	r0, r23
    b       _8000dfcc
_8000dfc8:
    li	r0, 0
_8000dfcc:
    mr	r29, r0
    b       _8000dfe0
_8000dfd4:
    addi	r3, r25, 0
    crxor	6, 6, 6
    bl      OSReport
_8000dfe0:
    addi	r30, r30, 8
_8000dfe4:
    lbz	r4, 2(r30)
    cmplwi	r4, 0xcb
    bne     _8000ddf4
    cmplwi	r29, 0
    beq     _8000e018
    lwz	r0, 0(r29)
    lwz	r4, 4(r29)
    rlwinm	r25, r0, 0, 0, 0x1e
    addi	r3, r25, 0
    bl      DCFlushRange
    mr	r3, r25
    lwz	r4, 4(r29)
    bl      ICInvalidateRange
_8000e018:
    li	r3, 1
_8000e01c:
    lmw	r23, 0x1c(r1)
    lwz	r0, 0x44(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr	
}

asm BOOL __OSLinkModule(register void* module, register void* bss, register int flag)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    li	r0, 0
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r3, 0
    stw	r30, 0x20(r1)
    addi	r30, r5, 0
    stw	r29, 0x1c(r1)
    addi	r29, r4, 0
    stw	r28, 0x18(r1)
    stb	r0, 0x33(r3)
    lwz	r0, 0x1c(r3)
    cmplwi	r0, 3
    bgt     _8000e0ac
    cmplwi	r0, 2
    blt     _8000e0b4
    lwz	r3, 0x40(r31)
    cmplwi	r3, 0
    beq     _8000e090
    divwu	r0, r31, r3
    mullw	r0, r0, r3
    subf.	r0, r0, r31
    bne     _8000e0ac
_8000e090:
    lwz	r3, 0x44(r31)
    cmplwi	r3, 0
    beq     _8000e0b4
    divwu	r0, r29, r3
    mullw	r0, r0, r3
    subf.	r0, r0, r29
    beq     _8000e0b4
_8000e0ac:
    li	r3, 0
    b       _8000e2f0
_8000e0b4:
    lis	r3, -0x8000
    addi	r4, r3, 0x30c8
    lwzu	r5, 4(r4)
    cmplwi	r5, 0
    bne     _8000e0d0
    stw	r31, 0x30c8(r3)
    b       _8000e0d4
_8000e0d0:
    stw	r31, 4(r5)
_8000e0d4:
    stw	r5, 8(r31)
    li	r0, 0
    stw	r0, 4(r31)
    stw	r31, 0(r4)
    lwz	r0, 0x10(r31)
    add	r0, r0, r31
    stw	r0, 0x10(r31)
    lwz	r0, 0x24(r31)
    add	r0, r0, r31
    stw	r0, 0x24(r31)
    lwz	r0, 0x28(r31)
    add	r0, r0, r31
    stw	r0, 0x28(r31)
    lwz	r0, 0x1c(r31)
    cmplwi	r0, 3
    blt     _8000e120
    lwz	r0, 0x48(r31)
    add	r0, r0, r31
    stw	r0, 0x48(r31)
_8000e120:
    li	r5, 1
    li	r3, 8
    b       _8000e168
_8000e12c:
    lwz	r0, 0x10(r31)
    add	r4, r0, r3
    lwz	r0, 0(r4)
    cmplwi	r0, 0
    beq     _8000e14c
    add	r0, r0, r31
    stw	r0, 0(r4)
    b       _8000e160
_8000e14c:
    lwz	r0, 4(r4)
    cmplwi	r0, 0
    beq     _8000e160
    stb	r5, 0x33(r31)
    stw	r29, 0(r4)
_8000e160:
    addi	r3, r3, 8
    addi	r5, r5, 1
_8000e168:
    lwz	r0, 0xc(r31)
    cmplw	r5, r0
    blt     _8000e12c
    lwz	r4, 0x28(r31)
    b       _8000e18c
_8000e17c:
    lwz	r0, 4(r4)
    add	r0, r0, r31
    stw	r0, 4(r4)
    addi	r4, r4, 8
_8000e18c:
    lwz	r3, 0x28(r31)
    lwz	r0, 0x2c(r31)
    add	r0, r3, r0
    cmplw	r4, r0
    blt     _8000e17c
    lbz	r0, 0x30(r31)
    cmplwi	r0, 0
    beq     _8000e1c8
    lwz	r3, 0x10(r31)
    slwi	r0, r0, 3
    lwz	r4, 0x34(r31)
    lwzx	r0, r3, r0
    rlwinm	r0, r0, 0, 0, 0x1e
    add	r0, r4, r0
    stw	r0, 0x34(r31)
_8000e1c8:
    lbz	r0, 0x31(r31)
    cmplwi	r0, 0
    beq     _8000e1f0
    lwz	r3, 0x10(r31)
    slwi	r0, r0, 3
    lwz	r4, 0x38(r31)
    lwzx	r0, r3, r0
    rlwinm	r0, r0, 0, 0, 0x1e
    add	r0, r4, r0
    stw	r0, 0x38(r31)
_8000e1f0:
    lbz	r0, 0x32(r31)
    cmplwi	r0, 0
    beq     _8000e218
    lwz	r3, 0x10(r31)
    slwi	r0, r0, 3
    lwz	r4, 0x3c(r31)
    lwzx	r0, r3, r0
    rlwinm	r0, r0, 0, 0, 0x1e
    add	r0, r4, r0
    stw	r0, 0x3c(r31)
_8000e218:
    lis	r3, -0x8000
    lwz	r3, 0x30d0(r3)
    cmplwi	r3, 0
    beq     _8000e234
    lwz	r0, 0x14(r31)
    add	r0, r0, r3
    stw	r0, 0x14(r31)
_8000e234:
    li	r3, 0
    addi	r4, r31, 0
    bl      Relocate
    lis	r3, -0x8000
    lwz	r28, 0x30c8(r3)
    b       _8000e270
_8000e24c:
    addi	r3, r31, 0
    addi	r4, r28, 0
    bl      Relocate
    cmplw	r28, r31
    beq     _8000e26c
    addi	r3, r28, 0
    addi	r4, r31, 0
    bl      Relocate
_8000e26c:
    lwz	r28, 4(r28)
_8000e270:
    cmplwi	r28, 0
    bne     _8000e24c
    cmpwi	r30, 0
    beq     _8000e2d4
    lwz	r4, 0x28(r31)
    lwz	r0, 0x2c(r31)
    addi	r5, r4, 0
    add	r3, r4, r0
    addi	r0, r3, 7
    subf	r0, r5, r0
    srwi	r0, r0, 3
    cmplw	r5, r3
    mtctr	r0
    bge     _8000e2d4
_8000e2a8:
    lwz	r3, 0(r5)
    cmplwi	r3, 0
    beq     _8000e2c0
    lwz	r0, 0(r31)
    cmplw	r3, r0
    bne     _8000e2cc
_8000e2c0:
    subf	r0, r4, r5
    stw	r0, 0x2c(r31)
    b       _8000e2d4
_8000e2cc:
    addi	r5, r5, 8
    bdnz    _8000e2a8
_8000e2d4:
    lwz	r5, 0x20(r31)
    addi	r3, r29, 0
    li	r4, 0
    bl      memset
    mr	r3, r31
    bl      OSNotifyLink
    li	r3, 1
_8000e2f0:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    lwz	r28, 0x18(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm BOOL OSLink(register void* module, register void* bss)
{
    nofralloc
    mflr	r0
    li	r5, 0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    bl      __OSLinkModule
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm BOOL fn_8000E334(register void* module, register void* bss)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r0, 0x1c(r3)
    cmplwi	r0, 3
    bgt     _8000e350
    bge     _8000e358
_8000e350:
    li	r3, 0
    b       _8000e360
_8000e358:
    li	r5, 1
    bl      __OSLinkModule
_8000e360:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm BOOL Undo(register void* newModule, register void* module)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stmw	r25, 0x1c(r1)
    mr	r28, r4
    lwz	r4, 0(r3)
    lwz	r3, 0x28(r28)
    lwz	r0, 0x2c(r28)
    addi	r5, r3, 0
    add	r3, r3, r0
    addi	r0, r3, 7
    subf	r0, r5, r0
    srwi	r0, r0, 3
    cmplw	r5, r3
    mtctr	r0
    bge     _8000e3c4
_8000e3b0:
    lwz	r0, 0(r5)
    cmplw	r0, r4
    beq     _8000e3cc
    addi	r5, r5, 8
    bdnz    _8000e3b0
_8000e3c4:
    li	r3, 0
    b       _8000e594
_8000e3cc:
    lis	r3, -0x7fee
    lwz	r31, 4(r5)
    addi	r27, r3, 0x3ab8
    li	r30, 0
    b       _8000e55c
_8000e3e0:
    lhz	r0, 0(r31)
    cmpwi	r4, 6
    li	r3, 0
    add	r29, r29, r0
    beq     _8000e494
    bge     _8000e424
    cmpwi	r4, 2
    beq     _8000e460
    bge     _8000e414
    cmpwi	r4, 0
    beq     _8000e558
    bge     _8000e454
    b       _8000e54c
_8000e414:
    cmpwi	r4, 4
    beq     _8000e47c
    bge     _8000e488
    b       _8000e470
_8000e424:
    cmpwi	r4, 0xc9
    beq     _8000e558
    bge     _8000e448
    cmpwi	r4, 0xa
    beq     _8000e4b0
    blt     _8000e4a0
    cmpwi	r4, 0xe
    bge     _8000e54c
    b       _8000e4d8
_8000e448:
    cmpwi	r4, 0xcb
    bge     _8000e54c
    b       _8000e4e8
_8000e454:
    li	r0, 0
    stw	r0, 0(r29)
    b       _8000e558
_8000e460:
    lwz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1e, 5
    stw	r0, 0(r29)
    b       _8000e558
_8000e470:
    li	r0, 0
    sth	r0, 0(r29)
    b       _8000e558
_8000e47c:
    li	r0, 0
    sth	r0, 0(r29)
    b       _8000e558
_8000e488:
    li	r0, 0
    sth	r0, 0(r29)
    b       _8000e558
_8000e494:
    li	r0, 0
    sth	r0, 0(r29)
    b       _8000e558
_8000e4a0:
    lwz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1e, 0xf
    stw	r0, 0(r29)
    b       _8000e558
_8000e4b0:
    lbz	r0, 0x32(r28)
    cmplwi	r0, 0
    beq     _8000e4c4
    lwz	r0, 0x3c(r28)
    subf	r3, r29, r0
_8000e4c4:
    lwz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1e, 5
    rlwimi	r0, r3, 0, 6, 0x1d
    stw	r0, 0(r29)
    b       _8000e558
_8000e4d8:
    lwz	r0, 0(r29)
    rlwinm	r0, r0, 0, 0x1e, 0xf
    stw	r0, 0(r29)
    b       _8000e558
_8000e4e8:
    lbz	r0, 3(r31)
    cmplwi	r30, 0
    lwz	r3, 0x10(r28)
    slwi	r0, r0, 3
    add	r3, r3, r0
    lwz	r0, 0(r3)
    addi	r26, r3, 0
    rlwinm	r29, r0, 0, 0, 0x1e
    beq     _8000e52c
    lwz	r0, 0(r30)
    lwz	r4, 4(r30)
    rlwinm	r25, r0, 0, 0, 0x1e
    addi	r3, r25, 0
    bl      DCFlushRange
    mr	r3, r25
    lwz	r4, 4(r30)
    bl      ICInvalidateRange
_8000e52c:
    lwz	r0, 0(r26)
    clrlwi.	r0, r0, 0x1f
    beq     _8000e540
    mr	r0, r26
    b       _8000e544
_8000e540:
    li	r0, 0
_8000e544:
    mr	r30, r0
    b       _8000e558
_8000e54c:
    addi	r3, r27, 0
    crxor	6, 6, 6
    bl      OSReport
_8000e558:
    addi	r31, r31, 8
_8000e55c:
    lbz	r4, 2(r31)
    cmplwi	r4, 0xcb
    bne     _8000e3e0
    cmplwi	r30, 0
    beq     _8000e590
    lwz	r0, 0(r30)
    lwz	r4, 4(r30)
    rlwinm	r27, r0, 0, 0, 0x1e
    addi	r3, r27, 0
    bl      DCFlushRange
    mr	r3, r27
    lwz	r4, 4(r30)
    bl      ICInvalidateRange
_8000e590:
    li	r3, 1
_8000e594:
    lmw	r25, 0x1c(r1)
    lwz	r0, 0x3c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm BOOL OSUnlink(register void* module)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    stw	r30, 0x10(r1)
    lwz	r4, 4(r3)
    lwz	r5, 8(r3)
    cmplwi	r4, 0
    bne     _8000e5dc
    lis	r3, -0x8000
    stw	r5, 0x30cc(r3)
    b       _8000e5e0
_8000e5dc:
    stw	r5, 8(r4)
_8000e5e0:
    cmplwi	r5, 0
    bne     _8000e5f4
    lis	r3, -0x8000
    stw	r4, 0x30c8(r3)
    b       _8000e5f8
_8000e5f4:
    stw	r4, 4(r5)
_8000e5f8:
    lis	r3, -0x8000
    lwz	r30, 0x30c8(r3)
    b       _8000e614
_8000e604:
    addi	r3, r31, 0
    addi	r4, r30, 0
    bl      Undo
    lwz	r30, 4(r30)
_8000e614:
    cmplwi	r30, 0
    bne     _8000e604
    mr	r3, r31
    bl      OSNotifyUnlink
    lis	r3, -0x8000
    lwz	r3, 0x30d0(r3)
    cmplwi	r3, 0
    beq     _8000e640
    lwz	r0, 0x14(r31)
    subf	r0, r3, r0
    stw	r0, 0x14(r31)
_8000e640:
    lbz	r0, 0x30(r31)
    cmplwi	r0, 0
    beq     _8000e668
    lwz	r4, 0x10(r31)
    slwi	r3, r0, 3
    lwz	r0, 0x34(r31)
    lwzx	r3, r4, r3
    rlwinm	r3, r3, 0, 0, 0x1e
    subf	r0, r3, r0
    stw	r0, 0x34(r31)
_8000e668:
    lbz	r0, 0x31(r31)
    cmplwi	r0, 0
    beq     _8000e690
    lwz	r4, 0x10(r31)
    slwi	r3, r0, 3
    lwz	r0, 0x38(r31)
    lwzx	r3, r4, r3
    rlwinm	r3, r3, 0, 0, 0x1e
    subf	r0, r3, r0
    stw	r0, 0x38(r31)
_8000e690:
    lbz	r0, 0x32(r31)
    cmplwi	r0, 0
    beq     _8000e6b8
    lwz	r4, 0x10(r31)
    slwi	r3, r0, 3
    lwz	r0, 0x3c(r31)
    lwzx	r3, r4, r3
    rlwinm	r3, r3, 0, 0, 0x1e
    subf	r0, r3, r0
    stw	r0, 0x3c(r31)
_8000e6b8:
    lwz	r4, 0x28(r31)
    b       _8000e6d0
_8000e6c0:
    lwz	r0, 4(r4)
    subf	r0, r31, r0
    stw	r0, 4(r4)
    addi	r4, r4, 8
_8000e6d0:
    lwz	r3, 0x28(r31)
    lwz	r0, 0x2c(r31)
    add	r0, r3, r0
    cmplw	r4, r0
    blt     _8000e6c0
    li	r6, 1
    li	r5, 8
    li	r3, 0
    b       _8000e730
_8000e6f4:
    lbz	r0, 0x33(r31)
    lwz	r4, 0x10(r31)
    cmplw	r6, r0
    add	r4, r4, r5
    bne     _8000e714
    stb	r3, 0x33(r31)
    stw	r3, 0(r4)
    b       _8000e728
_8000e714:
    lwz	r0, 0(r4)
    cmplwi	r0, 0
    beq     _8000e728
    subf	r0, r31, r0
    stw	r0, 0(r4)
_8000e728:
    addi	r5, r5, 8
    addi	r6, r6, 1
_8000e730:
    lwz	r0, 0xc(r31)
    cmplw	r6, r0
    blt     _8000e6f4
    lwz	r0, 0x24(r31)
    li	r3, 1
    subf	r0, r31, r0
    stw	r0, 0x24(r31)
    lwz	r0, 0x28(r31)
    subf	r0, r31, r0
    stw	r0, 0x28(r31)
    lwz	r0, 0x10(r31)
    subf	r0, r31, r0
    stw	r0, 0x10(r31)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

#pragma pop
