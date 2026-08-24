#pragma push
#pragma force_active on
extern void PPCHalt(void);
extern void ddh_cc_initialize(void);
extern unsigned char gDBCommTable[40];
extern unsigned char gTRKCPUState[1072];
extern void gTRKInterruptVectorTable(void);
extern unsigned char gTRKState[164];
extern void gdev_cc_initialize(void);
extern unsigned char lbl_80095BCC[260];
extern unsigned char lbl_8015B898[64];
extern unsigned char lbl_801A5638[8];
extern unsigned char lbl_801A5650[8];
extern void PPCHalt(void);
extern void ddh_cc_initialize(void);
extern void gTRKInterruptVectorTable(void);
extern void gdev_cc_initialize(void);
void TRKEXICallBack(void);

asm void TRK_memcpy(register void* a, register void* b, register void* c, register void* d);
asm void DCFlushRange(register void* a, register void* b, register void* c, register void* d);
asm void ICInvalidateRange(register void* a, register void* b, register void* c, register void* d);
asm void OSReport(register void* a, register void* b, register void* c, register void* d);
asm void OSEnableScheduler(register void* a, register void* b, register void* c, register void* d);
asm void TRKNubMainLoop(register void* a, register void* b, register void* c, register void* d);
asm void TRKNubWelcome(register void* a, register void* b, register void* c, register void* d);
asm void TRKTerminateNub(register void* a, register void* b, register void* c, register void* d);
asm void TRKInitializeNub(register void* a, register void* b, register void* c, register void* d);
asm void TRK_IsInputPending(register void* a, register void* b, register void* c, register void* d);
asm void TRK_flush_cache(register void* a, register void* b, register void* c, register void* d);
asm void __TRK_get_MSR(register void* a, register void* b, register void* c, register void* d);
asm void TRKInterruptHandler(register void* a, register void* b, register void* c, register void* d);
asm void TRKSwapAndGo(register void* a, register void* b, register void* c, register void* d);
asm void TRKTargetSetStopped(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008CB20(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008CB28(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008CB30(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008CB38(register void* a, register void* b, register void* c, register void* d);
asm void MWTRACE(register void* a, register void* b, register void* c, register void* d);
asm void AMC_IsStub(register void* a, register void* b, register void* c, register void* d);
asm void Hu_IsStub(register void* a, register void* b, register void* c, register void* d);
asm void EnableEXI2Interrupts(register void* a, register void* b, register void* c, register void* d);

asm void TRKInitializeTarget(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, gTRKState@ha
    stw	r0, 0x14(r1)
    li	r0, 1
    addi	r3, r3, gTRKState@l
    stw	r0, 0x98(r3)
    bl      __TRK_get_MSR
    lis     r5, gTRKState@ha
    lis	r4, -0x7fe6
    addi	r5, r5, gTRKState@l
    lis	r0, -0x2000
    stw	r3, 0x8c(r5)
    li	r3, 0
    stw	r0, 0x5638(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRKTargetTranslate(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, lbl_801A5638@ha
    stw	r0, 0x24(r1)
    addi	r3, r3, lbl_801A5638@l
    stmw	r27, 0xc(r1)
    lwz	r3, 0(r3)
    cmplwi	r3, 0x44
    bgt     _8008d074
    addi	r0, r3, 0x4000
    cmplwi	r0, 0x44
    ble     _8008d074
    lis     r3, gTRKCPUState@ha
    addi	r3, r3, gTRKCPUState@l
    lwz	r0, 0x238(r3)
    clrlwi.	r0, r0, 0x1e
    beq     _8008d074
    li	r5, 0x44
    b       _8008d07c
_8008d074:
    lis	r3, -0x8000
    addi	r5, r3, 0x44
_8008d07c:
    lis     r4, lbl_8015B898@ha
    lis     r3, gTRKCPUState@ha
    lwz	r29, 0(r5)
    addi	r31, r4, lbl_8015B898@l
    addi	r28, r3, gTRKCPUState@l
    li	r30, 0
_8008d094:
    li	r0, 1
    slw	r0, r0, r30
    and.	r0, r29, r0
    beq     _8008d130
    cmpwi	r30, 4
    beq     _8008d130
    lis     r3, lbl_801A5638@ha
    lwz	r6, 0(r31)
    addi	r3, r3, lbl_801A5638@l
    lwz	r3, 0(r3)
    cmplw	r6, r3
    blt     _8008d0e4
    addi	r0, r3, 0x4000
    cmplw	r6, r0
    bge     _8008d0e4
    lwz	r0, 0x238(r28)
    clrlwi.	r0, r0, 0x1e
    beq     _8008d0e4
    mr	r27, r6
    b       _8008d10c
_8008d0e4:
    lis	r0, 0x7e00
    cmplw	r6, r0
    blt     _8008d104
    lis	r0, -0x8000
    cmplw	r6, r0
    bgt     _8008d104
    mr	r27, r6
    b       _8008d10c
_8008d104:
    clrlwi	r0, r6, 2
    oris	r27, r0, 0x8000
_8008d10c:
    lis     r4, gTRKInterruptVectorTable@ha
    mr	r3, r27
    addi	r0, r4, gTRKInterruptVectorTable@l
    li	r5, 0x100
    add	r4, r0, r6
    bl      TRK_memcpy
    mr	r3, r27
    li	r4, 0x100
    bl      TRK_flush_cache
_8008d130:
    addi	r30, r30, 1
    addi	r31, r31, 4
    cmpwi	r30, 0xe
    ble     _8008d094
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void TRKFlushCache(void)
{
    nofralloc
    lis     r4, lbl_801A5638@ha
    addi	r4, r4, lbl_801A5638@l
    lwz	r4, 0(r4)
    cmplw	r3, r4
    blt     _8008d188
    addi	r0, r4, 0x4000
    cmplw	r3, r0
    bge     _8008d188
    lis     r4, gTRKCPUState@ha
    addi	r4, r4, gTRKCPUState@l
    lwz	r0, 0x238(r4)
    clrlwi.	r0, r0, 0x1e
    bnelr	
_8008d188:
    lis	r0, 0x7e00
    cmplw	r3, r0
    blt     _8008d1a0
    lis	r0, -0x8000
    cmplw	r3, r0
    blelr	
_8008d1a0:
    clrlwi	r0, r3, 2
    oris	r3, r0, 0x8000
    blr	
}

asm void EnableMetroTRKInterrupts(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      EnableEXI2Interrupts
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRK_main(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r4, -0x7ff7
    li	r3, 1
    stw	r0, 0x14(r1)
    addi	r4, r4, 0x5bb8
    crxor	6, 6, 6
    bl      MWTRACE
    bl      TRKInitializeNub
    lis	r4, -0x7fe6
    cmpwi	r3, 0
    stw	r3, 0x5640(r4)
    bne     _8008d208
    bl      TRKNubWelcome
    bl      TRKNubMainLoop
_8008d208:
    bl      TRKTerminateNub
    lis	r4, -0x7fe6
    stw	r3, 0x5640(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRKLoadContext(void)
{
    nofralloc
    lwz	r0, 0(r3)
    lwz	r1, 4(r3)
    lwz	r2, 8(r3)
    lhz	r5, 0x1a2(r3)
    rlwinm.	r6, r5, 0, 0x1e, 0x1e
    beq     _8008d24c
    rlwinm	r5, r5, 0, 0x1f, 0x1d
    sth	r5, 0x1a2(r3)
    lmw	r5, 0x14(r3)
    b       _8008d250
_8008d24c:
    lmw	r13, 0x34(r3)
_8008d250:
    mr	r31, r3
    mr	r3, r4
    lwz	r4, 0x80(r31)
    mtcrf	0xff, r4
    lwz	r4, 0x84(r31)
    mtlr	r4
    lwz	r4, 0x88(r31)
    mtctr	r4
    lwz	r4, 0x8c(r31)
    mtxer	r4
    mfmsr	r4
    rlwinm	r4, r4, 0, 0x11, 0xf
    rlwinm	r4, r4, 0, 0x1f, 0x1d
    mtmsr	r4
    mtspr	0x111, r2
    lwz	r4, 0xc(r31)
    mtspr	0x112, r4
    lwz	r4, 0x10(r31)
    mtspr	0x113, r4
    lwz	r2, 0x198(r31)
    lwz	r4, 0x19c(r31)
    lwz	r31, 0x7c(r31)
    b       TRKInterruptHandler
}

asm void TRKUARTInterruptHandler(void)
{
    nofralloc
    blr	
}

asm void InitializeProgramEndTrap(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, PPCHalt@ha
    lis	r3, -0x7ff7
    stw	r0, 0x14(r1)
    li	r5, 4
    stw	r31, 0xc(r1)
    addi	r31, r4, PPCHalt@l
    addi	r4, r3, 0x5bc8
    addi	r3, r31, 4
    bl      TRK_memcpy
    addi	r3, r31, 4
    li	r4, 4
    bl      ICInvalidateRange
    addi	r3, r31, 4
    li	r4, 4
    bl      DCFlushRange
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRK_board_display(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, lbl_80095BCC@ha
    mr	r4, r3
    stw	r0, 0x14(r1)
    addi	r3, r5, lbl_80095BCC@l
    crxor	6, 6, 6
    bl      OSReport
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void UnreserveEXI2Port(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, gDBCommTable@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, gDBCommTable@l
    lwz	r12, 0x20(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ReserveEXI2Port(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, gDBCommTable@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, gDBCommTable@l
    lwz	r12, 0x24(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRKDoWrite(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, gDBCommTable@ha
    stw	r0, 0x14(r1)
    addi	r5, r5, gDBCommTable@l
    lwz	r12, 0x14(r5)
    mtctr	r12
    bctrl	
    neg	r0, r3
    or	r0, r0, r3
    srawi	r3, r0, 0x1f
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRK_ReadUARTN(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, gDBCommTable@ha
    stw	r0, 0x14(r1)
    addi	r5, r5, gDBCommTable@l
    lwz	r12, 0x10(r5)
    mtctr	r12
    bctrl	
    neg	r0, r3
    or	r0, r0, r3
    srawi	r3, r0, 0x1f
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRKPollUART(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, gDBCommTable@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, gDBCommTable@l
    lwz	r12, 0xc(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void EnableEXI2Interrupts(register void* a, register void* b, register void* c, register void* d) // forward-declared
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe6
    stw	r0, 0x14(r1)
    lbz	r0, 0x5648(r3)
    cmplwi	r0, 0
    bne     _8008d478
    lis     r3, gDBCommTable@ha
    addi	r3, r3, gDBCommTable@l
    lwz	r12, 4(r3)
    cmplwi	r12, 0
    beq     _8008d478
    mtctr	r12
    bctrl	
_8008d478:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRKInitializeIntDrivenUART(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, TRKEXICallBack@ha
    lis	r3, -0x7fea
    stw	r0, 0x14(r1)
    addi	r4, r4, TRKEXICallBack@l
    lwz	r12, -0x4728(r3)
    mr	r3, r6
    mtctr	r12
    bctrl	
    lis     r3, gDBCommTable@ha
    addi	r3, r3, gDBCommTable@l
    lwz	r12, 0x18(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void InitMetroTRKCommTable(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r4, -0x7ff7
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 1
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    addi	r29, r4, 0x5bc8
    mr	r4, r30
    addi	r3, r29, 8
    crxor	6, 6, 6
    bl      OSReport
    lis	r3, -0x7fe6
    li	r0, 0
    cmpwi	r30, 2
    stb	r0, 0x5648(r3)
    bne     _8008d5c4
    addi	r3, r29, 0x20
    crxor	6, 6, 6
    bl      OSReport
    lis	r30, -0x7fe6
    lis	r12, -0x7ff7
    lis	r11, -0x7fea
    lis	r10, -0x7ff7
    lis	r9, -0x7ff7
    lis	r8, -0x7ff7
    lis	r7, -0x7ff7
    lis	r6, -0x7ff7
    lis	r5, -0x7ff7
    lis	r4, -0x7ff7
    lis	r3, -0x7ff7
    addi	r31, r30, 0x5648
    li	r29, 1
    addi	r30, r12, -0x2238
    addi	r12, r11, -0x4728
    addi	r11, r10, -0x2248
    addi	r10, r9, -0x2250
    addi	r9, r8, -0x2258
    addi	r8, r7, -0x2260
    addi	r7, r6, -0x2240
    addi	r6, r5, -0x2268
    addi	r5, r4, -0x2270
    addi	r4, r3, -0x2278
    li	r0, 0
    stb	r29, 0(r31)
    li	r3, 0
    stw	r30, 0(r12)
    stw	r11, 0x18(r12)
    stw	r10, 0x1c(r12)
    stw	r9, 0x10(r12)
    stw	r8, 0x14(r12)
    stw	r7, 8(r12)
    stw	r6, 0xc(r12)
    stw	r5, 0x20(r12)
    stw	r4, 0x24(r12)
    stw	r0, 4(r12)
    b       _8008d728
_8008d5c4:
    cmpwi	r30, 1
    bne     _8008d660
    addi	r3, r29, 0x38
    crxor	6, 6, 6
    bl      OSReport
    bl      Hu_IsStub
    lis     r31, gdev_cc_initialize@ha
    lis	r12, -0x7ff7
    addi	r31, r31, gdev_cc_initialize@l
    lis	r30, -0x7fea
    lis	r11, -0x7ff7
    lis	r10, -0x7ff7
    lis	r9, -0x7ff7
    lis	r8, -0x7ff7
    lis	r7, -0x7ff7
    lis	r6, -0x7ff7
    lis	r5, -0x7ff7
    lis	r4, -0x7ff7
    stwu	r31, -0x4728(r30)
    addi	r12, r12, -0x19ec
    addi	r11, r11, -0x19f4
    addi	r10, r10, -0x1ae8
    addi	r9, r9, -0x1ba8
    addi	r8, r8, -0x19c8
    addi	r7, r7, -0x1c60
    addi	r6, r6, -0x1bcc
    addi	r5, r5, -0x1bf0
    addi	r0, r4, -0x1c84
    stw	r12, 0x18(r30)
    mr	r31, r3
    stw	r11, 0x1c(r30)
    stw	r10, 0x10(r30)
    stw	r9, 0x14(r30)
    stw	r8, 8(r30)
    stw	r7, 0xc(r30)
    stw	r6, 0x20(r30)
    stw	r5, 0x24(r30)
    stw	r0, 4(r30)
    b       _8008d724
_8008d660:
    cmpwi	r30, 0
    bne     _8008d6fc
    addi	r3, r29, 0x5c
    crxor	6, 6, 6
    bl      OSReport
    bl      AMC_IsStub
    lis     r31, ddh_cc_initialize@ha
    lis	r12, -0x7ff7
    addi	r31, r31, ddh_cc_initialize@l
    lis	r30, -0x7fea
    lis	r11, -0x7ff7
    lis	r10, -0x7ff7
    lis	r9, -0x7ff7
    lis	r8, -0x7ff7
    lis	r7, -0x7ff7
    lis	r6, -0x7ff7
    lis	r5, -0x7ff7
    lis	r4, -0x7ff7
    stwu	r31, -0x4728(r30)
    addi	r12, r12, -0x1fa0
    addi	r11, r11, -0x1fa8
    addi	r10, r10, -0x2094
    addi	r9, r9, -0x2154
    addi	r8, r8, -0x1f7c
    addi	r7, r7, -0x220c
    addi	r6, r6, -0x2178
    addi	r5, r5, -0x219c
    addi	r0, r4, -0x2230
    stw	r12, 0x18(r30)
    mr	r31, r3
    stw	r11, 0x1c(r30)
    stw	r10, 0x10(r30)
    stw	r9, 0x14(r30)
    stw	r8, 8(r30)
    stw	r7, 0xc(r30)
    stw	r6, 0x20(r30)
    stw	r5, 0x24(r30)
    stw	r0, 4(r30)
    b       _8008d724
_8008d6fc:
    mr	r4, r30
    addi	r3, r29, 0x80
    crxor	6, 6, 6
    bl      OSReport
    addi	r3, r29, 0xac
    crxor	6, 6, 6
    bl      OSReport
    addi	r3, r29, 0xdc
    crxor	6, 6, 6
    bl      OSReport
_8008d724:
    mr	r3, r31
_8008d728:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void TRKEXICallBack(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r4
    bl      OSEnableScheduler
    mr	r3, r31
    li	r4, 0x500
    bl      TRKLoadContext
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRKTargetContinue(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r3, 0
    stw	r0, 0x14(r1)
    bl      TRKTargetSetStopped
    bl      UnreserveEXI2Port
    bl      TRKSwapAndGo
    bl      ReserveEXI2Port
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void AMC_IsStub_Game(void)
{
    nofralloc
    lis     r3, lbl_801A5650@ha
    addi	r3, r3, lbl_801A5650@l
    lbz	r3, 0(r3)
    blr	
}

asm void AMC_SetStub_Game(void)
{
    nofralloc
    lis	r4, -0x7fe6
    stb	r3, 0x5650(r4)
    blr	
}

asm void TRK_PositionFile_Game(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    mr	r29, r4
    stw	r28, 0x10(r1)
    mr	r28, r3
    bl      TRK_IsInputPending
    cmpwi	r3, 0
    bne     _8008d80c
    li	r3, 1
    b       _8008d888
_8008d80c:
    cmpwi	r30, 0
    bne     _8008d81c
    li	r31, 0
    b       _8008d838
_8008d81c:
    cmpwi	r30, 1
    bne     _8008d82c
    li	r31, 1
    b       _8008d838
_8008d82c:
    cmpwi	r30, 2
    bne     _8008d838
    li	r31, 2
_8008d838:
    mr	r4, r28
    mr	r5, r29
    clrlwi	r6, r31, 0x18
    li	r3, 0xd4
    bl      fn_8008CB38
    clrlwi	r0, r3, 0x18
    cmpwi	r0, 1
    beq     _8008d884
    bge     _8008d868
    cmpwi	r0, 0
    bge     _8008d874
    b       _8008d884
_8008d868:
    cmpwi	r0, 3
    bge     _8008d884
    b       _8008d87c
_8008d874:
    li	r3, 0
    b       _8008d888
_8008d87c:
    li	r3, 2
    b       _8008d888
_8008d884:
    li	r3, 1
_8008d888:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void TRK_CloseFile_Game(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      TRK_IsInputPending
    cmpwi	r3, 0
    bne     _8008d8d0
    li	r3, 1
    b       _8008d918
_8008d8d0:
    mr	r4, r31
    li	r3, 0xd3
    bl      fn_8008CB30
    clrlwi	r0, r3, 0x18
    cmpwi	r0, 1
    beq     _8008d914
    bge     _8008d8f8
    cmpwi	r0, 0
    bge     _8008d904
    b       _8008d914
_8008d8f8:
    cmpwi	r0, 3
    bge     _8008d914
    b       _8008d90c
_8008d904:
    li	r3, 0
    b       _8008d918
_8008d90c:
    li	r3, 2
    b       _8008d918
_8008d914:
    li	r3, 1
_8008d918:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRK_OpenFile_Game(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    mr	r29, r3
    bl      TRK_IsInputPending
    cmpwi	r3, 0
    bne     _8008d964
    li	r3, 1
    b       _8008da8c
_8008d964:
    lbz	r4, 0(r30)
    li	r5, 0
    lbz	r3, 1(r30)
    rlwinm	r0, r4, 0x1a, 0x1e, 0x1f
    rlwinm	r4, r4, 0x1d, 0x1d, 0x1f
    cmpwi	r0, 1
    rlwinm	r3, r3, 0x1d, 0x1f, 0x1f
    beq     _8008d9b8
    bge     _8008d994
    cmpwi	r0, 0
    bge     _8008d9a0
    b       _8008d9c0
_8008d994:
    cmpwi	r0, 3
    bge     _8008d9c0
    b       _8008d9ac
_8008d9a0:
    ori	r0, r5, 1
    clrlwi	r5, r0, 0x18
    b       _8008d9c0
_8008d9ac:
    ori	r0, r5, 2
    clrlwi	r5, r0, 0x18
    b       _8008d9c0
_8008d9b8:
    ori	r0, r5, 4
    clrlwi	r5, r0, 0x18
_8008d9c0:
    cmpwi	r4, 3
    beq     _8008da18
    bge     _8008d9dc
    cmpwi	r4, 1
    beq     _8008d9f4
    bge     _8008da00
    b       _8008da2c
_8008d9dc:
    cmpwi	r4, 7
    beq     _8008da24
    bge     _8008da2c
    cmpwi	r4, 6
    bge     _8008da0c
    b       _8008da2c
_8008d9f4:
    ori	r0, r5, 1
    clrlwi	r5, r0, 0x18
    b       _8008da2c
_8008da00:
    ori	r0, r5, 2
    clrlwi	r5, r0, 0x18
    b       _8008da2c
_8008da0c:
    ori	r0, r5, 4
    clrlwi	r5, r0, 0x18
    b       _8008da2c
_8008da18:
    ori	r0, r5, 0x12
    clrlwi	r5, r0, 0x18
    b       _8008da2c
_8008da24:
    ori	r0, r5, 7
    clrlwi	r5, r0, 0x18
_8008da2c:
    cmplwi	r3, 1
    bne     _8008da3c
    ori	r0, r5, 8
    clrlwi	r5, r0, 0x18
_8008da3c:
    mr	r4, r29
    mr	r6, r31
    clrlwi	r5, r5, 0x18
    li	r3, 0xd2
    bl      fn_8008CB28
    clrlwi	r0, r3, 0x18
    cmpwi	r0, 1
    beq     _8008da88
    bge     _8008da6c
    cmpwi	r0, 0
    bge     _8008da78
    b       _8008da88
_8008da6c:
    cmpwi	r0, 3
    bge     _8008da88
    b       _8008da80
_8008da78:
    li	r3, 0
    b       _8008da8c
_8008da80:
    li	r3, 2
    b       _8008da8c
_8008da88:
    li	r3, 1
_8008da8c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void TRK_WriteFile_Game(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    mr	r29, r3
    bl      TRK_IsInputPending
    cmpwi	r3, 0
    bne     _8008dae0
    li	r3, 1
    b       _8008db40
_8008dae0:
    lwz	r0, 0(r31)
    mr	r4, r29
    mr	r6, r30
    addi	r5, r1, 8
    stw	r0, 8(r1)
    li	r3, 0xd0
    bl      fn_8008CB20
    clrlwi	r0, r3, 0x18
    lwz	r3, 8(r1)
    cmpwi	r0, 1
    stw	r3, 0(r31)
    beq     _8008db3c
    bge     _8008db20
    cmpwi	r0, 0
    bge     _8008db2c
    b       _8008db3c
_8008db20:
    cmpwi	r0, 3
    bge     _8008db3c
    b       _8008db34
_8008db2c:
    li	r3, 0
    b       _8008db40
_8008db34:
    li	r3, 2
    b       _8008db40
_8008db3c:
    li	r3, 1
_8008db40:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void TRK_ReadFile_Game(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    mr	r29, r3
    bl      TRK_IsInputPending
    cmpwi	r3, 0
    bne     _8008db94
    li	r3, 1
    b       _8008dbf4
_8008db94:
    lwz	r0, 0(r31)
    mr	r4, r29
    mr	r6, r30
    addi	r5, r1, 8
    stw	r0, 8(r1)
    li	r3, 0xd1
    bl      fn_8008CB20
    clrlwi	r0, r3, 0x18
    lwz	r3, 8(r1)
    cmpwi	r0, 1
    stw	r3, 0(r31)
    beq     _8008dbf0
    bge     _8008dbd4
    cmpwi	r0, 0
    bge     _8008dbe0
    b       _8008dbf0
_8008dbd4:
    cmpwi	r0, 3
    bge     _8008dbf0
    b       _8008dbe8
_8008dbe0:
    li	r3, 0
    b       _8008dbf4
_8008dbe8:
    li	r3, 2
    b       _8008dbf4
_8008dbf0:
    li	r3, 1
_8008dbf4:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void TRKWriteFileChecked(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r4
    bl      AMC_IsStub_Game
    clrlwi.	r0, r3, 0x18
    bne     _8008dc40
    li	r3, 1
    b       _8008dcb4
_8008dc40:
    bl      TRK_IsInputPending
    cmpwi	r3, 0
    bne     _8008dc54
    li	r3, 1
    b       _8008dcb4
_8008dc54:
    lwz	r0, 0(r31)
    mr	r6, r30
    addi	r5, r1, 8
    li	r3, 0xd0
    stw	r0, 8(r1)
    li	r4, 1
    bl      fn_8008CB20
    clrlwi	r0, r3, 0x18
    lwz	r3, 8(r1)
    cmpwi	r0, 1
    stw	r3, 0(r31)
    beq     _8008dcb0
    bge     _8008dc94
    cmpwi	r0, 0
    bge     _8008dca0
    b       _8008dcb0
_8008dc94:
    cmpwi	r0, 3
    bge     _8008dcb0
    b       _8008dca8
_8008dca0:
    li	r3, 0
    b       _8008dcb4
_8008dca8:
    li	r3, 2
    b       _8008dcb4
_8008dcb0:
    li	r3, 1
_8008dcb4:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void TRKReadFileChecked(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r4
    bl      AMC_IsStub_Game
    clrlwi.	r0, r3, 0x18
    bne     _8008dcfc
    li	r3, 1
    b       _8008dd70
_8008dcfc:
    bl      TRK_IsInputPending
    cmpwi	r3, 0
    bne     _8008dd10
    li	r3, 1
    b       _8008dd70
_8008dd10:
    lwz	r0, 0(r31)
    mr	r6, r30
    addi	r5, r1, 8
    li	r3, 0xd1
    stw	r0, 8(r1)
    li	r4, 0
    bl      fn_8008CB20
    clrlwi	r0, r3, 0x18
    lwz	r3, 8(r1)
    cmpwi	r0, 1
    stw	r3, 0(r31)
    beq     _8008dd6c
    bge     _8008dd50
    cmpwi	r0, 0
    bge     _8008dd5c
    b       _8008dd6c
_8008dd50:
    cmpwi	r0, 3
    bge     _8008dd6c
    b       _8008dd64
_8008dd5c:
    li	r3, 0
    b       _8008dd70
_8008dd64:
    li	r3, 2
    b       _8008dd70
_8008dd6c:
    li	r3, 1
_8008dd70:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
