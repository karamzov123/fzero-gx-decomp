#pragma push
#pragma force_active on

extern asm void fn_8001BE6C(void);
extern asm void fn_8001BD84(void);
extern asm void fn_8001BC54(void);
extern asm void VIWaitForRetrace(void);
extern asm void GXSetDrawSync(void);

asm void fn_8006FEFC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
_8006ff08:
    bl      fn_8001BE6C
    lwz	r0, -0x76f4(r13)
    lwz	r4, -0x76f0(r13)
    subf	r3, r0, r3
    addi	r0, r4, -1
    cmplw	r3, r0
    blt	_8006ff08
    lwz	r3, -0x7690(r13)
    lwz	r3, 0(r3)
    bl      fn_8001BD84
    bl      fn_8001BC54
    bl      VIWaitForRetrace
    lwz	r0, -0x76e0(r13)
    rlwinm.	r0, r0, 0, 0x1a, 0x1a
    bne	_8006ff6c
    lwz	r4, -0x7690(r13)
    lwz	r0, 0x10(r4)
    slwi	r0, r0, 2
    add	r3, r4, r0
    lwz	r0, 4(r3)
    stw	r0, 0(r4)
    lwz	r3, -0x7690(r13)
    lwz	r0, 0x10(r3)
    xori	r0, r0, 1
    stw	r0, 0x10(r3)
_8006ff6c:
    lwz	r4, -0x7690(r13)
    lwz	r3, 0xc(r4)
    addi	r0, r3, 1
    stw	r0, 0xc(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8006FF8C(void)
{
    nofralloc
    cmpwi	r3, 0
    bne	_8006ffa0
    lwz	r3, -0x76e0(r13)
    rlwinm.	r0, r3, 0, 0x1b, 0x1b
    beq	_8006ffb0
_8006ffa0:
    lwz	r0, -0x76e0(r13)
    ori	r0, r0, 0x20
    stw	r0, -0x76e0(r13)
    blr	
_8006ffb0:
    rlwinm	r0, r3, 0, 0x1b, 0x19
    stw	r0, -0x76e0(r13)
    blr	
}

asm void fn_8006FFBC(void)
{
    nofralloc
    lwz	r3, -0x76ec(r13)
    blr	
}

asm void fn_8006FFC4(void)
{
    nofralloc
    stw	r3, -0x76f0(r13)
    blr	
}

asm void fn_8006FFCC(void)
{
    nofralloc
    lwz	r0, -0x7710(r13)
    stw	r3, -0x7710(r13)
    mr	r3, r0
    blr	
}

asm void fn_8006FFDC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    lhz	r3, -0x76fc(r13)
    mr	r31, r3
    bl      GXSetDrawSync
    lhz	r4, -0x76fc(r13)
    mr	r3, r31
    addi	r0, r4, 1
    sth	r0, -0x76fc(r13)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
