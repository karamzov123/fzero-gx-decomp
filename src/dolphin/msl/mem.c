#pragma push
#pragma force_active on

void* __memrchr(const void* s, int c, unsigned long n);
void* memchr(const void* s, int c, unsigned long n);
void* memmove(void* dst, const void* src, unsigned long n);
void fn_800803AC(void);
void fn_80080458(void);
void fn_80080518(void);
void fn_800805C0(void);

asm void* __memrchr(const void* s, int c, unsigned long n)
{
    nofralloc
    clrlwi	r4, r4, 0x18
    add	r3, r3, r5
    addi	r5, r5, 1
    b       _800802a4
_80080298:
    lbzu	r0, -1(r3)
    cmplw	r0, r4
    beqlr	
_800802a4:
    addic.	r5, r5, -1
    bne     _80080298
    li	r3, 0
    blr	
}

asm void* memchr(const void* s, int c, unsigned long n)
{
    nofralloc
    clrlwi	r4, r4, 0x18
    addi	r3, r3, -1
    addi	r5, r5, 1
    b       _800802d0
_800802c4:
    lbzu	r0, 1(r3)
    cmplw	r0, r4
    beqlr	
_800802d0:
    addic.	r5, r5, -1
    bne     _800802c4
    li	r3, 0
    blr	
}

asm void* memmove(void* dst, const void* src, unsigned long n)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r5, 0x20
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    xor	r6, r31, r4
    cntlzw	r0, r6
    slw	r0, r31, r0
    srwi	r7, r0, 0x1f
    blt     _80080348
    clrlwi.	r0, r6, 0x1e
    beq     _8008032c
    cmpwi	r7, 0
    bne     _80080324
    bl      fn_80080458
    b       _80080340
_80080324:
    bl      fn_800803AC
    b       _80080340
_8008032c:
    cmpwi	r7, 0
    bne     _8008033c
    bl      fn_800805C0
    b       _80080340
_8008033c:
    bl      fn_80080518
_80080340:
    mr	r3, r31
    b       _80080398
_80080348:
    cmpwi	r7, 0
    bne     _80080374
    addi	r3, r4, -1
    addi	r4, r31, -1
    addi	r5, r5, 1
    b       _80080368
_80080360:
    lbzu	r0, 1(r3)
    stbu	r0, 1(r4)
_80080368:
    addic.	r5, r5, -1
    bne     _80080360
    b       _80080394
_80080374:
    add	r3, r4, r5
    add	r4, r31, r5
    addi	r5, r5, 1
    b       _8008038c
_80080384:
    lbzu	r0, -1(r3)
    stbu	r0, -1(r4)
_8008038c:
    addic.	r5, r5, -1
    bne     _80080384
_80080394:
    mr	r3, r31
_80080398:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800803AC(void)
{
    nofralloc
    add	r11, r3, r5
    add	r10, r4, r5
    clrlwi.	r3, r11, 0x1e
    beq     _800803d0
    subf	r5, r3, r5
_800803c0:
    lbzu	r0, -1(r10)
    addic.	r3, r3, -1
    stbu	r0, -1(r11)
    bne     _800803c0
_800803d0:
    rlwinm	r8, r10, 3, 0x1b, 0x1c
    clrlwi	r7, r10, 0x1e
    subfic	r9, r8, 0x20
    srwi	r6, r5, 3
    subfic	r0, r7, 4
    add	r10, r10, r0
    lwzu	r4, -4(r10)
_800803ec:
    lwz	r0, -4(r10)
    srw	r3, r4, r9
    addic.	r6, r6, -1
    slw	r4, r0, r8
    srw	r0, r0, r9
    or	r3, r4, r3
    stw	r3, -4(r11)
    lwzu	r4, -8(r10)
    slw	r3, r4, r8
    or	r0, r3, r0
    stwu	r0, -8(r11)
    bne     _800803ec
    rlwinm.	r0, r5, 0, 0x1d, 0x1d
    beq     _80080438
    lwzu	r3, -4(r10)
    srw	r0, r4, r9
    slw	r3, r3, r8
    or	r0, r3, r0
    stwu	r0, -4(r11)
_80080438:
    clrlwi.	r5, r5, 0x1e
    beqlr	
    add	r10, r10, r7
_80080444:
    lbzu	r0, -1(r10)
    addic.	r5, r5, -1
    stbu	r0, -1(r11)
    bne     _80080444
    blr	
}

asm void fn_80080458(void)
{
    nofralloc
    neg	r0, r3
    addi	r8, r4, -1
    clrlwi.	r6, r0, 0x1e
    addi	r3, r3, -1
    beq     _80080480
    subf	r5, r6, r5
_80080470:
    lbzu	r0, 1(r8)
    addic.	r6, r6, -1
    stbu	r0, 1(r3)
    bne     _80080470
_80080480:
    addi	r0, r8, 1
    addi	r6, r3, -3
    clrlwi	r9, r0, 0x1e
    srwi	r7, r5, 3
    subf	r8, r9, r8
    rlwinm	r10, r0, 3, 0x1b, 0x1c
    lwzu	r4, 1(r8)
    subfic	r11, r10, 0x20
_800804a0:
    lwz	r3, 4(r8)
    slw	r4, r4, r10
    addic.	r7, r7, -1
    srw	r0, r3, r11
    slw	r3, r3, r10
    or	r0, r4, r0
    stw	r0, 4(r6)
    lwzu	r4, 8(r8)
    srw	r0, r4, r11
    or	r0, r3, r0
    stwu	r0, 8(r6)
    bne     _800804a0
    rlwinm.	r0, r5, 0, 0x1d, 0x1d
    beq     _800804ec
    lwzu	r0, 4(r8)
    slw	r3, r4, r10
    srw	r0, r0, r11
    or	r0, r3, r0
    stwu	r0, 4(r6)
_800804ec:
    clrlwi.	r5, r5, 0x1e
    addi	r4, r8, 3
    addi	r3, r6, 3
    beqlr	
    subfic	r0, r9, 4
    subf	r4, r0, r4
_80080504:
    lbzu	r0, 1(r4)
    addic.	r5, r5, -1
    stbu	r0, 1(r3)
    bne     _80080504
    blr	
}

asm void fn_80080518(void)
{
    nofralloc
    add	r7, r3, r5
    add	r6, r4, r5
    clrlwi.	r3, r7, 0x1e
    beq     _8008053c
    subf	r5, r3, r5
_8008052c:
    lbzu	r0, -1(r6)
    addic.	r3, r3, -1
    stbu	r0, -1(r7)
    bne     _8008052c
_8008053c:
    rlwinm.	r4, r5, 0x1b, 5, 0x1f
    beq     _8008058c
_80080544:
    lwz	r3, -4(r6)
    addic.	r4, r4, -1
    lwz	r0, -8(r6)
    stw	r3, -4(r7)
    lwz	r3, -0xc(r6)
    stw	r0, -8(r7)
    lwz	r0, -0x10(r6)
    stw	r3, -0xc(r7)
    lwz	r3, -0x14(r6)
    stw	r0, -0x10(r7)
    lwz	r0, -0x18(r6)
    stw	r3, -0x14(r7)
    lwz	r3, -0x1c(r6)
    stw	r0, -0x18(r7)
    lwzu	r0, -0x20(r6)
    stw	r3, -0x1c(r7)
    stwu	r0, -0x20(r7)
    bne     _80080544
_8008058c:
    rlwinm.	r3, r5, 0x1e, 0x1d, 0x1f
    beq     _800805a4
_80080594:
    lwzu	r0, -4(r6)
    addic.	r3, r3, -1
    stwu	r0, -4(r7)
    bne     _80080594
_800805a4:
    clrlwi.	r5, r5, 0x1e
    beqlr	
_800805ac:
    lbzu	r0, -1(r6)
    addic.	r5, r5, -1
    stbu	r0, -1(r7)
    bne     _800805ac
    blr	
}

asm void fn_800805C0(void)
{
    nofralloc
    neg	r0, r3
    addi	r4, r4, -1
    clrlwi.	r6, r0, 0x1e
    addi	r3, r3, -1
    beq     _800805e8
    subf	r5, r6, r5
_800805d8:
    lbzu	r0, 1(r4)
    addic.	r6, r6, -1
    stbu	r0, 1(r3)
    bne     _800805d8
_800805e8:
    rlwinm.	r6, r5, 0x1b, 5, 0x1f
    addi	r7, r4, -3
    addi	r4, r3, -3
    beq     _80080640
_800805f8:
    lwz	r3, 4(r7)
    addic.	r6, r6, -1
    lwz	r0, 8(r7)
    stw	r3, 4(r4)
    lwz	r3, 0xc(r7)
    stw	r0, 8(r4)
    lwz	r0, 0x10(r7)
    stw	r3, 0xc(r4)
    lwz	r3, 0x14(r7)
    stw	r0, 0x10(r4)
    lwz	r0, 0x18(r7)
    stw	r3, 0x14(r4)
    lwz	r3, 0x1c(r7)
    stw	r0, 0x18(r4)
    lwzu	r0, 0x20(r7)
    stw	r3, 0x1c(r4)
    stwu	r0, 0x20(r4)
    bne     _800805f8
_80080640:
    rlwinm.	r3, r5, 0x1e, 0x1d, 0x1f
    beq     _80080658
_80080648:
    lwzu	r0, 4(r7)
    addic.	r3, r3, -1
    stwu	r0, 4(r4)
    bne     _80080648
_80080658:
    clrlwi.	r5, r5, 0x1e
    addi	r6, r7, 3
    addi	r3, r4, 3
    beqlr	
_80080668:
    lbzu	r0, 1(r6)
    addic.	r5, r5, -1
    stbu	r0, 1(r3)
    bne     _80080668
    blr	
}

#pragma pop
