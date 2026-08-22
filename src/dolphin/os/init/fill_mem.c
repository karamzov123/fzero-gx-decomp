void* memset(void* dst, int val, unsigned long n);
void __fill_mem(void* dst, int val, unsigned long n);

#pragma push
#pragma force_active on

asm __declspec(section ".init") void* memset(void* dst, int val, unsigned long n)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    stw     r31, 0xc(r1)
    mr      r31, r3
    bl      __fill_mem
    lwz     r0, 0x14(r1)
    mr      r3, r31
    lwz     r31, 0xc(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm __declspec(section ".init") void __fill_mem(void* dst, int val,
                                                unsigned long n)
{
    nofralloc
    cmplwi  r5, 0x20
    clrlwi  r4, r4, 24
    subi    r6, r3, 1
    mr      r7, r4
    blt     lbl_80003528
    nor     r0, r6, r6
    clrlwi. r3, r0, 30
    beq     lbl_800034B8
    subf    r5, r3, r5
lbl_800034AC:
    subic.  r3, r3, 1
    stbu    r7, 0x1(r6)
    bne     lbl_800034AC
lbl_800034B8:
    cmplwi  r7, 0
    beq     lbl_800034D8
    slwi    r3, r7, 24
    slwi    r0, r7, 16
    slwi    r4, r7, 8
    or      r0, r3, r0
    or      r0, r4, r0
    or      r7, r7, r0
lbl_800034D8:
    srwi.   r3, r5, 5
    subi    r4, r6, 3
    beq     lbl_8000350C
lbl_800034E4:
    stw     r7, 0x4(r4)
    subic.  r3, r3, 1
    stw     r7, 0x8(r4)
    stw     r7, 0xc(r4)
    stw     r7, 0x10(r4)
    stw     r7, 0x14(r4)
    stw     r7, 0x18(r4)
    stw     r7, 0x1c(r4)
    stwu    r7, 0x20(r4)
    bne     lbl_800034E4
lbl_8000350C:
    extrwi. r3, r5, 3, 27
    beq     lbl_80003520
lbl_80003514:
    subic.  r3, r3, 1
    stwu    r7, 0x4(r4)
    bne     lbl_80003514
lbl_80003520:
    addi    r6, r4, 3
    clrlwi  r5, r5, 30
lbl_80003528:
    cmplwi  r5, 0
    beqlr
lbl_80003530:
    subic.  r5, r5, 1
    stbu    r7, 0x1(r6)
    bne     lbl_80003530
    blr
}

#pragma pop
