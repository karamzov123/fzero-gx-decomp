typedef signed int s32;
#pragma push
#pragma force_active on
extern unsigned char lbl_80095CD0[92];
extern unsigned char lbl_80095D2C[37];
extern unsigned char lbl_80095D54[45];
extern unsigned char lbl_80095D84[19];
extern unsigned char lbl_80095D98[24];
extern unsigned char lbl_801A5658[2048];
extern unsigned char lbl_801A5E58[32];

extern unsigned char lbl_801A6E08[8];
asm void EXI2_ReadN(register void* a, register void* b, register void* c, register void* d);
asm void EXI2_WriteN(register void* a, register void* b, register void* c, register void* d);
asm void EXI2_Init(register void* a, register void* b, register void* c, register void* d);
asm void EXI2_Poll(register void* a, register void* b, register void* c, register void* d);
asm void MWTRACE(register void* a, register void* b, register void* c, register void* d);
asm void EXI2_InitSequence(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008EEAC(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008EED8(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008EFE0(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F29C(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F44C(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F450(register void* a, register void* b, register void* c, register void* d);

asm void udp_cc_post_stop(void)
{
    nofralloc
    li	r3, -1
    blr	
}

asm void udp_cc_pre_continue(void)
{
    nofralloc
    li	r3, -1
    blr	
}

s32 udp_cc_peek(void) { return 0; }

s32 udp_cc_write(void) { return 0; }

s32 udp_cc_read(void) { return 0; }

asm void udp_cc_close(void)
{
    nofralloc
    li	r3, -1
    blr	
}

asm void udp_cc_open(void)
{
    nofralloc
    li	r3, -1
    blr	
}

asm void udp_cc_shutdown(void)
{
    nofralloc
    li	r3, -1
    blr	
}

asm void udp_cc_initialize(void)
{
    nofralloc
    li	r3, -1
    blr	
}

asm void ddh_cc_initinterrupts(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8008EEAC
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ddh_cc_peek(void)
{
    nofralloc
    stwu	r1, -0x810(r1)
    mflr	r0
    stw	r0, 0x814(r1)
    stw	r31, 0x80c(r1)
    bl      fn_8008EED8
    or.	r31, r3, r3
    bgt     _8008de18
    li	r3, 0
    b       _8008de50
_8008de18:
    mr	r4, r31
    addi	r3, r1, 8
    bl      fn_8008EFE0
    cmpwi	r3, 0
    bne     _8008de44
    lis     r3, lbl_801A5E58@ha
    mr	r5, r31
    addi	r3, r3, lbl_801A5E58@l
    addi	r4, r1, 8
    bl      EXI2_WriteN
    b       _8008de4c
_8008de44:
    li	r3, -0x2719
    b       _8008de50
_8008de4c:
    mr	r3, r31
_8008de50:
    lwz	r0, 0x814(r1)
    lwz	r31, 0x80c(r1)
    mtlr	r0
    addi	r1, r1, 0x810
    blr	
}

asm void ddh_cc_post_stop(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8008F44C
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ddh_cc_pre_continue(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8008F450
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ddh_cc_write(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r5, lbl_80095CD0@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r5, lbl_80095CD0@l
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    mr	r29, r3
    lwz	r0, lbl_801A6E08
    cmpwi	r0, 0
    bne     _8008def8
    addi	r4, r31, 0
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    li	r3, -0x2711
    b       _8008df50
_8008def8:
    mr	r5, r3
    mr	r6, r4
    addi	r4, r31, 0x14
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    b       _8008df44
_8008df14:
    mr	r5, r30
    addi	r4, r31, 0x40
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r29
    mr	r4, r30
    bl      fn_8008F29C
    cmpwi	r3, 0
    beq     _8008df4c
    add	r29, r29, r3
    subf	r30, r3, r30
_8008df44:
    cmpwi	r30, 0
    bgt     _8008df14
_8008df4c:
    li	r3, 0
_8008df50:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void ddh_cc_read(void)
{
    nofralloc
    stwu	r1, -0x820(r1)
    mflr	r0
    stw	r0, 0x824(r1)
    stmw	r27, 0x80c(r1)
    mr	r27, r3
    mr	r30, r4
    li	r29, 0
    lwz	r0, lbl_801A6E08
    cmpwi	r0, 0
    bne     _8008df9c
    li	r3, -0x2711
    b       _8008e044
_8008df9c:
    lis     r3, lbl_80095D2C@ha
    mr	r5, r30
    addi	r4, r3, lbl_80095D2C@l
    mr	r6, r30
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    lis     r3, lbl_801A5E58@ha
    addi	r31, r3, lbl_801A5E58@l
    b       _8008dff8
_8008dfc4:
    li	r29, 0
    bl      fn_8008EED8
    or.	r28, r3, r3
    beq     _8008dff8
    mr	r4, r28
    addi	r3, r1, 8
    bl      fn_8008EFE0
    or.	r29, r3, r3
    bne     _8008dff8
    mr	r3, r31
    mr	r5, r28
    addi	r4, r1, 8
    bl      EXI2_WriteN
_8008dff8:
    mr	r3, r31
    bl      EXI2_Poll
    cmplw	r3, r30
    blt     _8008dfc4
    cmplwi	r29, 0
    bne     _8008e028
    lis     r3, lbl_801A5E58@ha
    mr	r4, r27
    addi	r3, r3, lbl_801A5E58@l
    mr	r5, r30
    bl      EXI2_ReadN
    b       _8008e040
_8008e028:
    lis     r3, lbl_80095D54@ha
    mr	r5, r29
    addi	r4, r3, lbl_80095D54@l
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
_8008e040:
    mr	r3, r29
_8008e044:
    lmw	r27, 0x80c(r1)
    lwz	r0, 0x824(r1)
    mtlr	r0
    addi	r1, r1, 0x820
    blr	
}

s32 ddh_cc_close(void) { return 0; }

asm void ddh_cc_open(void)
{
    nofralloc
    lwz	r0, lbl_801A6E08
    cmpwi	r0, 0
    beq     _8008e074
    li	r3, -0x2715
    blr	
_8008e074:
    li	r0, 1
    li	r3, 0
    stw	r0, lbl_801A6E08
    blr	
}

s32 ddh_cc_shutdown(void) { return 0; }

asm void ddh_cc_initialize(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, lbl_80095D84@ha
    stw	r0, 0x14(r1)
    addi	r0, r5, lbl_80095D84@l
    stw	r31, 0xc(r1)
    mr	r31, r4
    mr	r4, r0
    stw	r30, 8(r1)
    mr	r30, r3
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r30
    mr	r4, r31
    bl      EXI2_InitSequence
    lis     r4, lbl_80095D98@ha
    li	r3, 1
    addi	r4, r4, lbl_80095D98@l
    crxor	6, 6, 6
    bl      MWTRACE
    lis     r3, lbl_801A5E58@ha
    lis     r4, lbl_801A5658@ha
    addi	r3, r3, lbl_801A5E58@l
    li	r5, 0x800
    addi	r4, r4, lbl_801A5658@l
    bl      EXI2_Init
    lwz	r0, 0x14(r1)
    li	r3, 0
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
