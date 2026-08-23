#pragma push
#pragma force_active on

unsigned long wcstombs(char* dst, const unsigned short* src, unsigned long n);
void fn_80080030(void);
void fn_80080150(void);
void strncmp(void);
extern int strncpy(void);

asm unsigned long wcstombs(char* dst, const unsigned short* src, unsigned long n)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r27, 0x1c(r1)
    or.	r28, r3, r3
    mr	r29, r5
    li	r31, 0
    beq     _8007ff40
    cmplwi	r4, 0
    bne     _8007ff48
_8007ff40:
    li	r3, 0
    b       _8008001c
_8007ff48:
    mr	r30, r4
    b       _80080010
_8007ff50:
    lhz	r6, 0(r30)
    cmplwi	r6, 0
    bne     _8007ff68
    li	r0, 0
    stbx	r0, r28, r31
    b       _8008001c
_8007ff68:
    lwz	r0, -0x7960(r2)
    cmplwi	r6, 0x80
    addi	r30, r30, 2
    stw	r0, 8(r1)
    bge     _8007ff84
    li	r27, 1
    b       _8007ff98
_8007ff84:
    cmplwi	r6, 0x800
    bge     _8007ff94
    li	r27, 2
    b       _8007ff98
_8007ff94:
    li	r27, 3
_8007ff98:
    cmpwi	r27, 2
    addi	r5, r1, 0xc
    add	r5, r5, r27
    beq     _8007ffd0
    bge     _8007ffb8
    cmpwi	r27, 1
    bge     _8007ffe0
    b       _8007fff0
_8007ffb8:
    cmpwi	r27, 4
    bge     _8007fff0
    clrlwi	r0, r6, 0x1a
    rlwinm	r6, r6, 0x1a, 0x16, 0x1f
    ori	r0, r0, 0x80
    stbu	r0, -1(r5)
_8007ffd0:
    clrlwi	r0, r6, 0x1a
    rlwinm	r6, r6, 0x1a, 0x16, 0x1f
    ori	r0, r0, 0x80
    stbu	r0, -1(r5)
_8007ffe0:
    addi	r4, r1, 8
    lbzx	r0, r4, r27
    or	r0, r6, r0
    stb	r0, -1(r5)
_8007fff0:
    add	r0, r31, r27
    cmplw	r0, r29
    bgt     _8008001c
    mr	r5, r27
    add	r3, r28, r31
    addi	r4, r1, 0xc
    bl      strncpy
    add	r31, r31, r27
_80080010:
    cmplw	r31, r29
    mr	r3, r31
    ble     _8007ff50
_8008001c:
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80080030(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    or.	r29, r4, r4
    bne     _8008005c
    b       _80080130
_8008005c:
    cmplwi	r5, 0
    bne     _8008006c
    li	r30, -1
    b       _80080130
_8008006c:
    mr	r3, r29
    mr	r4, r5
    bl      fn_80080150
    cmpwi	r3, 0
    bge     _80080088
    li	r30, -1
    b       _80080130
_80080088:
    cmpwi	r3, 2
    mr	r4, r29
    beq     _800800b8
    bge     _800800a4
    cmpwi	r3, 1
    bge     _800800cc
    b       _800800dc
_800800a4:
    cmpwi	r3, 4
    bge     _800800dc
    lbz	r0, 0(r29)
    addi	r4, r29, 1
    rlwinm	r30, r0, 6, 0x16, 0x19
_800800b8:
    lbz	r0, 0(r4)
    addi	r4, r4, 1
    clrlwi	r0, r0, 0x1a
    or	r0, r30, r0
    rlwinm	r30, r0, 6, 0x10, 0x19
_800800cc:
    lbz	r0, 0(r4)
    clrlwi	r0, r0, 0x19
    or	r0, r30, r0
    clrlwi	r30, r0, 0x10
_800800dc:
    clrlwi.	r0, r30, 0x10
    bne     _800800ec
    li	r0, 0
    b       _80080110
_800800ec:
    cmplwi	r0, 0x80
    bge     _800800fc
    li	r0, 1
    b       _80080110
_800800fc:
    cmplwi	r0, 0x800
    bge     _8008010c
    li	r0, 2
    b       _80080110
_8008010c:
    li	r0, 3
_80080110:
    cmpw	r0, r3
    beq     _80080120
    li	r30, -1
    b       _80080130
_80080120:
    cmplwi	r31, 0
    beq     _8008012c
    sth	r30, 0(r31)
_8008012c:
    mr	r30, r3
_80080130:
    lwz	r0, 0x24(r1)
    mr	r3, r30
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80080150(void)
{
    nofralloc
    cmplwi	r4, 0
    bne     _80080160
    li	r3, -1
    blr	
_80080160:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bne     _80080174
    li	r3, 0
    blr	
_80080174:
    extsb	r5, r5
    rlwinm.	r0, r5, 0, 0x18, 0x18
    bne     _80080188
    li	r3, 1
    blr	
_80080188:
    rlwinm	r0, r5, 0, 0x18, 0x1a
    cmpwi	r0, 0xc0
    bne     _800801c0
    cmplwi	r4, 2
    blt     _800801b8
    lbz	r0, 1(r3)
    li	r3, -1
    rlwinm	r0, r0, 0, 0x18, 0x18
    cmpwi	r0, 0x80
    bnelr	
    li	r3, 2
    blr	
_800801b8:
    li	r3, -2
    blr	
_800801c0:
    rlwinm	r0, r5, 0, 0x18, 0x1b
    cmpwi	r0, 0xe0
    bne     _80080234
    cmplwi	r4, 3
    blt     _80080204
    lbz	r0, 1(r3)
    rlwinm	r0, r0, 0, 0x18, 0x18
    cmpwi	r0, 0x80
    bne     _800801fc
    lbz	r0, 2(r3)
    rlwinm	r0, r0, 0, 0x18, 0x18
    cmpwi	r0, 0x80
    bne     _800801fc
    li	r3, 3
    blr	
_800801fc:
    li	r3, -1
    blr	
_80080204:
    cmplwi	r4, 2
    bne     _8008021c
    lbz	r0, 1(r3)
    rlwinm	r0, r0, 0, 0x18, 0x18
    cmpwi	r0, 0x80
    beq     _80080224
_8008021c:
    cmplwi	r4, 1
    bne     _8008022c
_80080224:
    li	r3, -2
    blr	
_8008022c:
    li	r3, -1
    blr	
_80080234:
    li	r3, -1
    blr	
}

asm void strncmp(void)
{
    nofralloc
    addi	r6, r3, -1
    addi	r7, r4, -1
    addi	r4, r5, 1
    b       _80080278
_8008024c:
    lbzu	r3, 1(r6)
    lbzu	r0, 1(r7)
    cmplw	r3, r0
    beq     _80080278
    lbz	r4, 0(r6)
    li	r3, 1
    lbz	r0, 0(r7)
    cmplw	r4, r0
    bgelr	
    li	r3, -1
    blr	
_80080278:
    addic.	r4, r4, -1
    bne     _8008024c
    li	r3, 0
    blr	
}

#pragma pop
