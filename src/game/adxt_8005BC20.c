#pragma push
#pragma force_active on

extern void AXFreeVoice(void);
extern void ARFree(void);
extern void axmix_device_ctrl_clear(void);
extern void adxtSetNotifyCallback(void);
extern void fn_8005A614(void);
extern void svm_exit_critical_wrapper(void);
extern void svm_enter_critical_wrapper(void);
extern void ADXTServerStateRequest(void);
extern void fn_8005B264(void);
extern void fn_8005BE98(void);
extern void fn_8005BFB4(void);
extern void SndInitManager(void);
extern void memset(void);
extern unsigned char lbl_800927BC[4];
extern unsigned char lbl_80092988[36];
extern unsigned char lbl_800929AC[43];
extern unsigned char lbl_80190C78[4];
extern unsigned char lbl_80191D4C[3716];
extern unsigned char lbl_80192BD0[20];
extern unsigned char lbl_80192BE4[388];

asm void fn_8005BC20(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, lbl_80191D4C@ha
    li	r7, 0
    stw	r0, 0x14(r1)
    addi	r6, r4, lbl_80191D4C@l
    li	r0, 2
    stw	r31, 0xc(r1)
_8005bc40:
    mr	r5, r6
    li	r8, 0
    mtctr	r0
_8005bc4c:
    lwz	r4, 8(r5)
    cmplw	r3, r4
    bne     _8005bc84
    mulli	r3, r7, 0xe8
    lis     r4, lbl_80191D4C@ha
    slwi	r0, r8, 2
    addi	r4, r4, lbl_80191D4C@l
    add	r3, r4, r3
    add	r31, r3, r0
    lwzu	r3, 8(r31)
    bl      axmix_device_ctrl_clear
    li	r0, 0
    stw	r0, 0(r31)
    b     _8005bca0
_8005bc84:
    addi	r5, r5, 4
    addi	r8, r8, 1
    bdnz     _8005bc4c
    addi	r7, r7, 1
    addi	r6, r6, 0xe8
    cmpwi	r7, 0x10
    blt     _8005bc40
_8005bca0:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005BCB4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, lbl_80190C78@ha
    stw	r0, 0x24(r1)
    addi	r4, r3, lbl_80190C78@l
    stmw	r27, 0xc(r1)
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _8005bdc0
    lis     r3, lbl_80191D4C@ha
    li	r27, 0
    addi	r28, r3, lbl_80191D4C@l
_8005bce8:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8005bd98
    cmplwi	r28, 0
    beq     _8005bd98
    mr	r3, r28
    li	r4, 0
    bl      ADXTServerStateRequest
    mr	r3, r28
    li	r4, 0
    bl      fn_8005B264
    mr	r30, r28
    addi	r29, r28, 2
    li	r31, 0
    b     _8005bd78
_8005bd24:
    lwz	r3, 0x38(r30)
    cmplwi	r3, 0
    beq     _8005bd40
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8005bd40:
    lwz	r3, 0x10(r30)
    cmplwi	r3, 0
    beq     _8005bd50
    bl      fn_8005BE98
_8005bd50:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8005bd6c
    bl      axmix_device_ctrl_clear
    lwz	r3, 8(r30)
    bl      AXFreeVoice
_8005bd6c:
    bl      svm_exit_critical_wrapper
    addi	r30, r30, 4
    addi	r31, r31, 1
_8005bd78:
    lbz	r0, 0(r29)
    extsb	r0, r0
    cmpw	r31, r0
    blt     _8005bd24
    mr	r3, r28
    li	r4, 0
    li	r5, 0xe8
    bl      memset
_8005bd98:
    addi	r27, r27, 1
    addi	r28, r28, 0xe8
    cmpwi	r27, 0x10
    blt     _8005bce8
    lis     r3, lbl_80191D4C@ha
    li	r4, 0
    addi	r3, r3, lbl_80191D4C@l
    li	r5, 0xe80
    bl      memset
    bl      fn_8005BFB4
_8005bdc0:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005BDD4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_800927BC@ha
    lis     r4, lbl_80190C78@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, lbl_800927BC@l
    lwz	r3, 0(r3)
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_80190C78@l
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bne     _8005be28
    bl      SndInitManager
    addi	r3, r31, 0x10d4
    li	r4, 0
    li	r5, 0xe80
    bl      memset
    addi	r3, r31, 0x94
    addi	r0, r3, 0x1f
    rlwinm	r0, r0, 0, 0, 0x1a
    stw	r0, 4(r31)
_8005be28:
    lwz	r3, 0(r31)
    addi	r0, r3, 1
    stw	r0, 0(r31)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005BE48(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8005A614
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005BE68(void)
{
    nofralloc
    cmplwi	r3, 0
    bne     _8005be78
    li	r3, 0
    blr	
_8005be78:
    lwz	r3, 8(r3)
    blr	
}

asm void fn_8005BE80(void)
{
    nofralloc
    cmplwi	r3, 0
    bne     _8005be90
    li	r3, 0
    blr	
_8005be90:
    lwz	r3, 4(r3)
    blr	
}

asm void fn_8005BE98(void)
{
    nofralloc
    cmplwi	r3, 0
    beqlr	
    li	r0, 0
    stw	r0, 0(r3)
    blr	
}

asm void fn_8005BEAC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80192BE4@ha
    li	r4, 0
    stw	r0, 0x14(r1)
    li	r0, 4
    addi	r3, r3, lbl_80192BE4@l
    mtctr	r0
_8005becc:
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    beq     _8005bf70
    lwz	r0, 0xc(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc
    cmpwi	r0, 0
    beq     _8005bf70
    lwz	r0, 0xc(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc
    cmpwi	r0, 0
    beq     _8005bf70
    lwz	r0, 0xc(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc
    cmpwi	r0, 0
    beq     _8005bf70
    lwz	r0, 0xc(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc
    cmpwi	r0, 0
    beq     _8005bf70
    lwz	r0, 0xc(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc
    cmpwi	r0, 0
    beq     _8005bf70
    lwz	r0, 0xc(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc
    cmpwi	r0, 0
    beq     _8005bf70
    lwz	r0, 0xc(r3)
    addi	r4, r4, 1
    addi	r3, r3, 0xc
    cmpwi	r0, 0
    beq     _8005bf70
    addi	r3, r3, 0xc
    addi	r4, r4, 1
    bdnz     _8005becc
_8005bf70:
    cmpwi	r4, 0x20
    bne     _8005bf8c
    lis     r3, lbl_80092988@ha
    addi	r3, r3, lbl_80092988@l
    bl      adxtSetNotifyCallback
    li	r3, 0
    b     _8005bfa4
_8005bf8c:
    mulli	r4, r4, 0xc
    lis     r3, lbl_80192BE4@ha
    li	r0, 1
    addi	r3, r3, lbl_80192BE4@l
    add	r3, r3, r4
    stw	r0, 0(r3)
_8005bfa4:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005BFB4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, lbl_80192BD0@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, lbl_80192BD0@l
    lwz	r3, 0(r31)
    addic.	r0, r3, -1
    stw	r0, 0(r31)
    bne     _8005c10c
    li	r0, 4
    addi	r4, r31, 0x14
    li	r5, 0
    li	r3, 0
    mtctr	r0
_8005bff0:
    lwz	r0, 0(r4)
    cmpwi	r0, 1
    bne     _8005c008
    cmplwi	r4, 0
    beq     _8005c008
    stw	r3, 0(r4)
_8005c008:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c020
    cmplwi	r4, 0
    beq     _8005c020
    stw	r3, 0(r4)
_8005c020:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c038
    cmplwi	r4, 0
    beq     _8005c038
    stw	r3, 0(r4)
_8005c038:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c050
    cmplwi	r4, 0
    beq     _8005c050
    stw	r3, 0(r4)
_8005c050:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c068
    cmplwi	r4, 0
    beq     _8005c068
    stw	r3, 0(r4)
_8005c068:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c080
    cmplwi	r4, 0
    beq     _8005c080
    stw	r3, 0(r4)
_8005c080:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c098
    cmplwi	r4, 0
    beq     _8005c098
    stw	r3, 0(r4)
_8005c098:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c0b0
    cmplwi	r4, 0
    beq     _8005c0b0
    stw	r3, 0(r4)
_8005c0b0:
    addi	r4, r4, 0xc
    addi	r5, r5, 7
    bdnz     _8005bff0
    addi	r3, r31, 0x14
    li	r4, 0
    li	r5, 0x180
    bl      memset
    lwz	r0, 4(r31)
    cmplwi	r0, 0
    bne     _8005c10c
    addi	r3, r1, 8
    bl      ARFree
    lwz	r3, 8(r1)
    lwz	r0, 0xc(r31)
    cmplw	r3, r0
    beq     _8005c0fc
    lis     r3, lbl_800929AC@ha
    addi	r3, r3, lbl_800929AC@l
    bl      adxtSetNotifyCallback
_8005c0fc:
    li	r0, 0
    stw	r0, 8(r31)
    stw	r0, 0xc(r31)
    stw	r0, 0x10(r31)
_8005c10c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
