#pragma push
#pragma force_active on

// __msl_strcpy: byte-copy loop (strncpy-like inner copy)
asm void __msl_strcpy(void* dst, const void* src)
{
    nofralloc
    addi    r4, r4, -1
    addi    r5, r3, -1
lbl_80083D48:
    lbzu    r0, 1(r5)
    cmplwi  r0, 0
    bne     lbl_80083D48
    addi    r5, r5, -1
lbl_80083D58:
    lbzu    r0, 1(r4)
    cmplwi  r0, 0
    stbu    r0, 1(r5)
    bne     lbl_80083D58
    blr
}

// strncpy: padded copy (copy src then zero-fill n bytes)
asm void strncpy(void* dst, const void* src, int n)
{
    nofralloc
    addi    r4, r4, -1
    addi    r6, r3, -1
    addi    r5, r5, 1
    b       lbl_80083DA4
lbl_80083D7C:
    lbzu    r0, 1(r4)
    cmplwi  r0, 0
    stbu    r0, 1(r6)
    bne     lbl_80083DA4
    li      r0, 0
    b       lbl_80083D98
lbl_80083D94:
    stbu    r0, 1(r6)
lbl_80083D98:
    addic.  r5, r5, -1
    bne     lbl_80083D94
    blr
lbl_80083DA4:
    addic.  r5, r5, -1
    bne     lbl_80083D7C
    blr
}

// strcpy: word-optimized strcpy
asm char* strcpy(char* dst, const char* src)
{
    nofralloc
    clrlwi  r0, r3, 0x1e
    clrlwi  r5, r4, 0x1e
    cmplw   r0, r5
    mr      r7, r3
    bne     lbl_80083E44
    cmplwi  r5, 0
    beq     lbl_80083E08
    lbz     r0, 0(r4)
    cmplwi  r0, 0
    stb     r0, 0(r7)
    beqlr
    subfic  r0, r5, 3
    mtctr   r0
    cmplwi  r0, 0
    beq     lbl_80083E00
lbl_80083DEC:
    lbzu    r0, 1(r4)
    cmplwi  r0, 0
    stbu    r0, 1(r7)
    beqlr
    bdnz    lbl_80083DEC
lbl_80083E00:
    addi    r7, r7, 1
    addi    r4, r4, 1
lbl_80083E08:
    lwz     r8, 0(r4)
    lis     r5, 0x8081
    addi    r6, r5, -0x7f80
    addis   r5, r8, -0x101
    addi    r0, r5, -0x101
    and.    r0, r0, r6
    bne     lbl_80083E44
    addi    r7, r7, -4
lbl_80083E28:
    stwu    r8, 4(r7)
    lwzu    r8, 4(r4)
    addis   r5, r8, -0x101
    addi    r0, r5, -0x101
    and.    r0, r0, r6
    beq     lbl_80083E28
    addi    r7, r7, 4
lbl_80083E44:
    lbz     r0, 0(r4)
    cmplwi  r0, 0
    stb     r0, 0(r7)
    beqlr
lbl_80083E54:
    lbzu    r0, 1(r4)
    cmplwi  r0, 0
    stbu    r0, 1(r7)
    bne     lbl_80083E54
    blr
}

// provenance: sms:src/PowerPC_EABI_Support/Msl/MSL_C/MSL_Common/string.c:6
int strlen(const char* s) {
    const unsigned char* p = (const unsigned char*)s - 1;
    int len = -1;
    do { ++len; } while (*++p);
    return len;
}

#pragma pop
