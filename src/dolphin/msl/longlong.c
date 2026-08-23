#pragma push
#pragma force_active on

asm void __div2u(void)
{
    nofralloc
    cmpwi   r3, 0
    cntlzw  r0, r3
    cntlzw  r9, r4
    bne     _80079904
    addi    r0, r9, 0x20
_80079904:
    cmpwi   r5, 0
    cntlzw  r9, r5
    cntlzw  r10, r6
    bne     _80079918
    addi    r9, r10, 0x20
_80079918:
    cmpw    r0, r9
    subfic  r10, r0, 0x40
    bgt     _800799d0
    addi    r9, r9, 1
    subfic  r9, r9, 0x40
    add     r0, r0, r9
    subf    r9, r9, r10
    mtctr   r9
    cmpwi   r9, 0x20
    addi    r7, r9, -0x20
    blt     _80079950
    srw     r8, r3, r7
    li      r7, 0
    b       _80079964
_80079950:
    srw     r8, r4, r9
    subfic  r7, r9, 0x20
    slw     r7, r3, r7
    or      r8, r8, r7
    srw     r7, r3, r9
_80079964:
    cmpwi   r0, 0x20
    addic   r9, r0, -0x20
    blt     _8007997c
    slw     r3, r4, r9
    li      r4, 0
    b       _80079990
_8007997c:
    slw     r3, r3, r0
    subfic  r9, r0, 0x20
    srw     r9, r4, r9
    or      r3, r3, r9
    slw     r4, r4, r0
_80079990:
    li      r10, -1
_80079994:
    addic   r7, r7, 0
_80079998:
    adde    r4, r4, r4
    adde    r3, r3, r3
    adde    r8, r8, r8
    adde    r7, r7, r7
    subfc   r0, r6, r8
    subfe.  r9, r5, r7
    blt     _800799c0
    mr      r8, r0
    mr      r7, r9
    addic   r0, r10, 1
_800799c0:
    bdnz    _80079998
    adde    r4, r4, r4
    adde    r3, r3, r3
    blr
_800799d0:
    li      r4, 0
    li      r3, 0
    blr
}

asm void __div2i(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    rlwinm. r9, r3, 0, 0, 0
    beq     _800799f0
    subfic  r4, r4, 0
    subfze  r3, r3
_800799f0:
    stw     r9, 8(r1)
    rlwinm. r10, r5, 0, 0, 0
    beq     _80079a04
    subfic  r6, r6, 0
    subfze  r5, r5
_80079a04:
    stw     r10, 0xc(r1)
    cmpwi   r3, 0
    cntlzw  r0, r3
    cntlzw  r9, r4
    bne     _80079a1c
    addi    r0, r9, 0x20
_80079a1c:
    cmpwi   r5, 0
    cntlzw  r9, r5
    cntlzw  r10, r6
    bne     _80079a30
    addi    r9, r10, 0x20
_80079a30:
    cmpw    r0, r9
    subfic  r10, r0, 0x40
    bgt     _80079b04
    addi    r9, r9, 1
    subfic  r9, r9, 0x40
    add     r0, r0, r9
    subf    r9, r9, r10
    mtctr   r9
    cmpwi   r9, 0x20
    addi    r7, r9, -0x20
    blt     _80079a68
    srw     r8, r3, r7
    li      r7, 0
    b       _80079a7c
_80079a68:
    srw     r8, r4, r9
    subfic  r7, r9, 0x20
    slw     r7, r3, r7
    or      r8, r8, r7
    srw     r7, r3, r9
_80079a7c:
    cmpwi   r0, 0x20
    addic   r9, r0, -0x20
    blt     _80079a94
    slw     r3, r4, r9
    li      r4, 0
    b       _80079aa8
_80079a94:
    slw     r3, r3, r0
    subfic  r9, r0, 0x20
    srw     r9, r4, r9
    or      r3, r3, r9
    slw     r4, r4, r0
_80079aa8:
    li      r10, -1
_80079aac:
    addic   r7, r7, 0
_80079ab0:
    adde    r4, r4, r4
    adde    r3, r3, r3
    adde    r8, r8, r8
    adde    r7, r7, r7
    subfc   r0, r6, r8
    subfe.  r9, r5, r7
    blt     _80079ad8
    mr      r8, r0
    mr      r7, r9
    addic   r0, r10, 1
_80079ad8:
    bdnz    _80079ab0
    adde    r4, r4, r4
    adde    r3, r3, r3
    lwz     r9, 8(r1)
    lwz     r10, 0xc(r1)
    xor.    r7, r9, r10
    beq     _80079b0c
    cmpwi   r9, 0
    subfic  r4, r4, 0
    subfze  r3, r3
    b       _80079b0c
_80079b04:
    li      r4, 0
    li      r3, 0
_80079b0c:
    addi    r1, r1, 0x10
    blr
}

asm void __mod2u(void)
{
    nofralloc
    cmpwi   r3, 0
    cntlzw  r0, r3
    cntlzw  r9, r4
    bne     _80079b28
    addi    r0, r9, 0x20
_80079b28:
    cmpwi   r5, 0
    cntlzw  r9, r5
    cntlzw  r10, r6
    bne     _80079b3c
    addi    r9, r10, 0x20
_80079b3c:
    cmpw    r0, r9
    subfic  r10, r0, 0x40
    bgtlr
    addi    r9, r9, 1
    subfic  r9, r9, 0x40
    add     r0, r0, r9
    subf    r9, r9, r10
    mtctr   r9
    cmpwi   r9, 0x20
    addi    r7, r9, -0x20
    blt     _80079b74
    srw     r8, r3, r7
    li      r7, 0
    b       _80079b88
_80079b74:
    srw     r8, r4, r9
    subfic  r7, r9, 0x20
    slw     r7, r3, r7
    or      r8, r8, r7
    srw     r7, r3, r9
_80079b88:
    cmpwi   r0, 0x20
    addic   r9, r0, -0x20
    blt     _80079ba0
    slw     r3, r4, r9
    li      r4, 0
    b       _80079bb4
_80079ba0:
    slw     r3, r3, r0
    subfic  r9, r0, 0x20
    srw     r9, r4, r9
    or      r3, r3, r9
    slw     r4, r4, r0
_80079bb4:
    li      r10, -1
_80079bb8:
    addic   r7, r7, 0
_80079bbc:
    adde    r4, r4, r4
    adde    r3, r3, r3
    adde    r8, r8, r8
    adde    r7, r7, r7
    subfc   r0, r6, r8
    subfe.  r9, r5, r7
    blt     _80079be4
    mr      r8, r0
    mr      r7, r9
    addic   r0, r10, 1
_80079be4:
    bdnz    _80079bbc
    mr      r4, r8
    mr      r3, r7
    blr
    blr
}

asm void __mod2i(void)
{
    nofralloc
    cmpwi   cr7, r3, 0
    bge     cr7, _80079c08
    subfic  r4, r4, 0
    subfze  r3, r3
_80079c08:
    cmpwi   r5, 0
    bge     _80079c18
    subfic  r6, r6, 0
    subfze  r5, r5
_80079c18:
    cmpwi   r3, 0
    cntlzw  r0, r3
    cntlzw  r9, r4
    bne     _80079c2c
    addi    r0, r9, 0x20
_80079c2c:
    cmpwi   r5, 0
    cntlzw  r9, r5
    cntlzw  r10, r6
    bne     _80079c40
    addi    r9, r10, 0x20
_80079c40:
    cmpw    r0, r9
    subfic  r10, r0, 0x40
    bgt     _80079cf4
    addi    r9, r9, 1
    subfic  r9, r9, 0x40
    add     r0, r0, r9
    subf    r9, r9, r10
    mtctr   r9
    cmpwi   r9, 0x20
    addi    r7, r9, -0x20
    blt     _80079c78
    srw     r8, r3, r7
    li      r7, 0
    b       _80079c8c
_80079c78:
    srw     r8, r4, r9
    subfic  r7, r9, 0x20
    slw     r7, r3, r7
    or      r8, r8, r7
    srw     r7, r3, r9
_80079c8c:
    cmpwi   r0, 0x20
    addic   r9, r0, -0x20
    blt     _80079ca4
    slw     r3, r4, r9
    li      r4, 0
    b       _80079cb8
_80079ca4:
    slw     r3, r3, r0
    subfic  r9, r0, 0x20
    srw     r9, r4, r9
    or      r3, r3, r9
    slw     r4, r4, r0
_80079cb8:
    li      r10, -1
_80079cbc:
    addic   r7, r7, 0
_80079cc0:
    adde    r4, r4, r4
    adde    r3, r3, r3
    adde    r8, r8, r8
    adde    r7, r7, r7
    subfc   r0, r6, r8
    subfe.  r9, r5, r7
    blt     _80079ce8
    mr      r8, r0
    mr      r7, r9
    addic   r0, r10, 1
_80079ce8:
    bdnz    _80079cc0
    mr      r4, r8
    mr      r3, r7
_80079cf4:
    bgelr   cr7
    subfic  r4, r4, 0
    subfze  r3, r3
    blr
}

asm void __shl2i(void)
{
    nofralloc
    subfic  r8, r5, 0x20
    addic   r9, r5, -0x20
    slw     r3, r3, r5
    srw     r10, r4, r8
    or      r3, r3, r10
    slw     r10, r4, r9
    or      r3, r3, r10
    slw     r4, r4, r5
    blr
}

asm void __shr2u(void)
{
    nofralloc
    subfic  r8, r5, 0x20
    addic   r9, r5, -0x20
    srw     r4, r4, r5
    slw     r10, r3, r8
    or      r4, r4, r10
    srw     r10, r3, r9
    or      r4, r4, r10
    srw     r3, r3, r5
    blr
}

asm void __shr2i(void)
{
    nofralloc
    subfic  r8, r5, 0x20
    addic.  r9, r5, -0x20
    srw     r4, r4, r5
    slw     r10, r3, r8
    or      r4, r4, r10
    sraw    r10, r3, r9
    ble     _80079d6c
    or      r4, r4, r10
_80079d6c:
    sraw    r3, r3, r5
    blr
}

asm void __cvt_sll_dbl(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    rlwinm. r5, r3, 0, 0, 0
    beq     _80079d88
    subfic  r4, r4, 0
    subfze  r3, r3
_80079d88:
    or.     r7, r3, r4
    li      r6, 0
    beq     _80079e10
    cntlzw  r7, r3
    cntlzw  r8, r4
    rlwinm  r9, r7, 0x1a, 0, 4
    srawi   r9, r9, 0x1f
    and     r9, r9, r8
    add     r7, r7, r9
    subfic  r8, r7, 0x20
    addic   r9, r7, -0x20
    slw     r3, r3, r7
    srw     r10, r4, r8
    or      r3, r3, r10
    slw     r10, r4, r9
    or      r3, r3, r10
    slw     r4, r4, r7
    subf    r6, r7, r6
    clrlwi  r7, r4, 0x15
    cmpwi   r7, 0x400
    addi    r6, r6, 0x43e
    blt     _80079df8
    bgt     _80079dec
    rlwinm. r7, r4, 0, 0x14, 0x14
    beq     _80079df8
_80079dec:
    addic   r4, r4, 0x800
    addze   r3, r3
    addze   r6, r6
_80079df8:
    rotlwi  r4, r4, 0x15
    rlwimi  r4, r3, 0x15, 0, 0xa
    rlwinm  r3, r3, 0x15, 0xc, 0x1f
    slwi    r6, r6, 0x14
    or      r3, r6, r3
    or      r3, r5, r3
_80079e10:
    stw     r3, 8(r1)
    stw     r4, 0xc(r1)
    lfd     f1, 8(r1)
    addi    r1, r1, 0x10
    blr
}

asm void __cvt_dbl_usll(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    stfd    f1, 8(r1)
    lwz     r3, 8(r1)
    lwz     r4, 0xc(r1)
    rlwinm  r5, r3, 0xc, 0x15, 0x1f
    cmplwi  r5, 0x3ff
    bge     _80079e4c
    li      r3, 0
    li      r4, 0
    b       _80079ee8
_80079e4c:
    mr      r6, r3
    clrlwi  r3, r3, 0xc
    oris    r3, r3, 0x10
    addi    r5, r5, -0x433
    cmpwi   r5, 0
    bge     _80079e8c
    neg     r5, r5
    subfic  r8, r5, 0x20
    addic   r9, r5, -0x20
    srw     r4, r4, r5
    slw     r10, r3, r8
    or      r4, r4, r10
    srw     r10, r3, r9
    or      r4, r4, r10
    srw     r3, r3, r5
    b       _80079ed8
_80079e8c:
    cmpwi   r5, 0xa
    bc      5, 1, _80079eb8
    rlwinm. r6, r6, 0, 0, 0
    beq     _80079ea8
    lis     r3, -0x8000
    li      r4, 0
    b       _80079ee8
_80079ea8:
    lis     r3, 0x7fff
    ori     r3, r3, 0xffff
    li      r4, -1
    b       _80079ee8
_80079eb8:
    subfic  r8, r5, 0x20
    addic   r9, r5, -0x20
    slw     r3, r3, r5
    srw     r10, r4, r8
    or      r3, r3, r10
    slw     r10, r4, r9
    or      r3, r3, r10
    slw     r4, r4, r5
_80079ed8:
    rlwinm. r6, r6, 0, 0, 0
    beq     _80079ee8
    subfic  r4, r4, 0
    subfze  r3, r3
_80079ee8:
    addi    r1, r1, 0x10
    blr
}

#pragma pop
