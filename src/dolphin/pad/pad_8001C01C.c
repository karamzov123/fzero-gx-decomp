typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

extern void memset(void);
extern unsigned char VITvMode_8012457C[28];
extern void OSRegisterVersion(void);
extern void OSSetCurrentContext(void);
extern void OSClearContext(void);
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void OSRegisterResetFunction(void);
extern void OSSetWirelessID(void);
extern void OSGetTime(void);
extern void SIChannelValid(void);
extern void SIIsChanBusy(void);
extern void SIRegisterPollingHandler(void);
extern void SIUnregisterPollingHandler(void);
extern void SIGetStatus(void);
extern void SISetCommand(void);
extern void SITransferCommands(void);
extern void SIGetWirelessID(void);
extern void SIGetWirelessIDBitfield(void);
extern void SIGetResponse(void);
extern void SITransfer(void);
extern void SIGetType(void);
extern void SIGetTypeAsync(void);
extern void SISetSamplingRateRestore(void);
extern void __shr2i(void);
extern unsigned char lbl_801245E0[16];
extern unsigned char lbl_8015D0B0[16];
extern unsigned char Origin[64];
extern unsigned char lbl_8008FF40[];

extern unsigned char CurrTvMode[4];
extern unsigned char __PADSpec[4];
extern unsigned char lbl_801A64C8[2];
extern unsigned char lbl_801A64CC[2];
extern unsigned char lbl_801A64B0[4];
extern unsigned char lbl_801A64B4[4];
extern unsigned char lbl_801A64B8[4];
extern unsigned char lbl_801A64BC[4];
extern unsigned char lbl_801A64C0[4];
extern unsigned char lbl_801A64C4[4];
extern unsigned char lbl_801A6818[8];
extern unsigned char lbl_801A6978[4];
extern unsigned char lbl_801A697C[4];
extern unsigned char lbl_801A6980[4];
extern unsigned char lbl_801A6984[4];
extern unsigned char lbl_801A6988[4];
extern unsigned char lbl_801A698C[4];
extern unsigned char lbl_801A6990[4];
extern unsigned char lbl_801A6994[4];
extern unsigned char lbl_801A6998[4];
asm void VIGetTvFormat(void);
asm void PADIsMotorEnabled(void);
asm void ClampS8(void);
asm void PadClampStatus(void);
asm void UpdateOrigin(void);
asm void PADEnable(void);
asm void PADDisable(void);
asm void PADEnableWireless(void);
asm void PADTypeAndStatusCallback(void);
asm void PADOriginUpdateCallback(void);
asm void PADReset(void);
asm void PADRecalibrate(void);
asm void PADInit(void);
asm void PADRead(void);
asm void SISetCommandByChannel(void);
asm void SISetCommandByArray(void);
asm void PADSetSpec(void);
asm void SPEC0_MakeStatus(void);
asm void SPEC1_MakeStatus(void);
asm void SPEC2_MakeStatus(void);
asm void PADSetAnalogMode(void);
asm void PADResetChannel(void);
asm void SamplingHandler(void);
asm void PADSetSamplingCallback(void);
asm void __PADDisableRecalibration(void);

asm void VIGetTvFormat(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      OSDisableInterrupts
    lwz	r5, CurrTvMode
    cmplwi	r5, 6
    bc      12, 1, _8001c068
    lis	r4, VITvMode_8012457C@ha
    addi	r4, r4, VITvMode_8012457C@l
    slwi	r0, r5, 2
    lwzx	r0, r4, r0
    mtctr	r0
    bctr
    li	r31, 0
    b       _8001c068
    li	r31, 1
    b       _8001c068
    mr	r31, r5
_8001c068:
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr
}

asm void PADIsMotorEnabled(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      OSDisableInterrupts
    lis	r4, -0x3400
    lhz	r0, 0x206e(r4)
    clrlwi	r31, r0, 0x1e
    bl      OSRestoreInterrupts
    clrlwi	r3, r31, 0x1f
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr
}

asm void ClampS8(void)
{
    nofralloc
    lbz	r0, 0(r3)
    lbz	r12, 0(r4)
    extsb.	r0, r0
    extsb	r12, r12
    mr	r11, r0
    bc      12, 0, _8001c0e0
    li	r0, 1
    b       _8001c0e8
_8001c0e0:
    li	r0, -1
    neg	r11, r11
_8001c0e8:
    cmpwi	r12, 0
    bc      12, 0, _8001c0f8
    li	r8, 1
    b       _8001c100
_8001c0f8:
    li	r8, -1
    neg	r12, r12
_8001c100:
    extsb	r7, r7
    cmpw	r11, r7
    bc      12, 1, _8001c114
    li	r11, 0
    b       _8001c118
_8001c114:
    subf	r11, r7, r11
_8001c118:
    cmpw	r12, r7
    bc      12, 1, _8001c128
    li	r12, 0
    b       _8001c12c
_8001c128:
    subf	r12, r7, r12
_8001c12c:
    cmpwi	r11, 0
    bc      4, 2, _8001c14c
    cmpwi	r12, 0
    bc      4, 2, _8001c14c
    li	r0, 0
    stb	r0, 0(r4)
    stb	r0, 0(r3)
    blr
_8001c14c:
    extsb	r6, r6
    mullw	r9, r6, r12
    mullw	r7, r6, r11
    cmpw	r9, r7
    bc      12, 1, _8001c1a0
    extsb	r9, r5
    subf	r5, r6, r9
    mullw	r5, r12, r5
    mullw	r9, r6, r9
    add	r7, r7, r5
    cmpw	r9, r7
    bc      4, 0, _8001c1dc
    mullw	r6, r11, r9
    mullw	r5, r12, r9
    divw	r6, r6, r7
    divw	r5, r5, r7
    extsb	r6, r6
    extsb	r5, r5
    addi	r11, r6, 0
    addi	r12, r5, 0
    b       _8001c1dc
_8001c1a0:
    extsb	r7, r5
    subf	r5, r6, r7
    mullw	r5, r11, r5
    mullw	r10, r6, r7
    add	r7, r9, r5
    cmpw	r10, r7
    bc      4, 0, _8001c1dc
    mullw	r6, r11, r10
    mullw	r5, r12, r10
    divw	r6, r6, r7
    divw	r5, r5, r7
    extsb	r6, r6
    extsb	r5, r5
    addi	r11, r6, 0
    addi	r12, r5, 0
_8001c1dc:
    mullw	r5, r0, r11
    mullw	r0, r8, r12
    stb	r5, 0(r3)
    stb	r0, 0(r4)
    blr
}

asm void PadClampStatus(void)
{
    nofralloc
    mflr	r0
    lis     r4, lbl_8008FF40@ha
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    li      r30, 0

    stw     r29, 0x14(r1)
    addi    r29, r3, 0
    stw     r28, 0x10(r1)
    addi    r28, r4, lbl_8008FF40@l
    addi	r31, r28, 1
_8001c220:
    lbz	r0, 0xa(r29)
    extsb.	r0, r0
    bc      4, 2, _8001c2d4
    lbz	r5, 3(r28)
    addi	r3, r29, 2
    lbz	r6, 4(r28)
    addi	r4, r29, 3
    lbz	r7, 2(r28)
    bl      ClampS8
    lbz	r5, 6(r28)
    addi	r3, r29, 4
    lbz	r6, 7(r28)
    addi	r4, r29, 5
    lbz	r7, 5(r28)
    bl      ClampS8
    lbz	r4, 6(r29)
    lbz	r0, 0(r28)
    lbz	r3, 0(r31)
    cmplw	r4, r0
    bc      12, 1, _8001c27c
    li	r0, 0
    stb	r0, 6(r29)
    b       _8001c298
_8001c27c:
    cmplw	r3, r4
    bc      4, 0, _8001c288
    stb	r3, 6(r29)
_8001c288:
    lbz	r3, 0(r28)
    lbz	r0, 6(r29)
    subf	r0, r3, r0
    stb	r0, 6(r29)
_8001c298:
    lbz	r4, 7(r29)
    lbz	r0, 0(r28)
    lbz	r3, 0(r31)
    cmplw	r4, r0
    bc      12, 1, _8001c2b8
    li	r0, 0
    stb	r0, 7(r29)
    b       _8001c2d4
_8001c2b8:
    cmplw	r3, r4
    bc      4, 0, _8001c2c4
    stb	r3, 7(r29)
_8001c2c4:
    lbz	r3, 0(r28)
    lbz	r0, 7(r29)
    subf	r0, r3, r0
    stb	r0, 7(r29)
_8001c2d4:
    addi	r30, r30, 1
    cmpwi	r30, 4
    addi	r29, r29, 0xc
    bc      12, 0, _8001c220
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr
}

asm void UpdateOrigin(void)
{
    nofralloc
    mflr	r0
    lis     r5, Origin@ha
    stw	r0, 4(r1)
    mulli	r6, r3, 0xc
    stwu	r1, -0x18(r1)
    addi	r5, r5, Origin@l
    stw	r31, 0x14(r1)
    add	r31, r5, r6
    lwz	r0, lbl_801A64BC
    rlwinm	r4, r0, 0, 0x15, 0x17
    cmpwi	r4, 0x400
    lis	r0, -0x8000
    srw	r0, r0, r3
    bc      12, 2, _8001c42c
    bc      4, 0, _8001c370
    cmpwi	r4, 0x200
    bc      12, 2, _8001c3fc
    bc      4, 0, _8001c364
    cmpwi	r4, 0x100
    bc      12, 2, _8001c3c8
    bc      4, 0, _8001c42c
    cmpwi	r4, 0
    bc      12, 2, _8001c394
    b       _8001c42c
_8001c364:
    cmpwi	r4, 0x300
    bc      12, 2, _8001c42c
    b       _8001c42c
_8001c370:
    cmpwi	r4, 0x600
    bc      12, 2, _8001c394
    bc      4, 0, _8001c388
    cmpwi	r4, 0x500
    bc      12, 2, _8001c394
    b       _8001c42c
_8001c388:
    cmpwi	r4, 0x700
    bc      12, 2, _8001c394
    b       _8001c42c
_8001c394:
    lbz	r4, 6(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 6(r31)
    lbz	r4, 7(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 7(r31)
    lbz	r4, 8(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 8(r31)
    lbz	r4, 9(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 9(r31)
    b       _8001c42c
_8001c3c8:
    lbz	r4, 4(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 4(r31)
    lbz	r4, 5(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 5(r31)
    lbz	r4, 8(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 8(r31)
    lbz	r4, 9(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 9(r31)
    b       _8001c42c
_8001c3fc:
    lbz	r4, 4(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 4(r31)
    lbz	r4, 5(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 5(r31)
    lbz	r4, 6(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 6(r31)
    lbz	r4, 7(r31)
    rlwinm	r4, r4, 0, 0, 0x1b
    stb	r4, 7(r31)
_8001c42c:
    lbz	r4, 2(r31)
    addi	r4, r4, -0x80
    stb	r4, 2(r31)
    lbz	r4, 3(r31)
    addi	r4, r4, -0x80
    stb	r4, 3(r31)
    lbz	r4, 4(r31)
    addi	r4, r4, -0x80
    stb	r4, 4(r31)
    lbz	r4, 5(r31)
    addi	r4, r4, -0x80
    stb	r4, 5(r31)
    lwz	r4, lbl_801A64B8
    and.	r0, r4, r0
    bc      12, 2, _8001c494
    lbz	r0, 2(r31)
    extsb	r0, r0
    cmpwi	r0, 0x40
    bc      4, 1, _8001c494
    bl      SIGetType
    rlwinm	r3, r3, 0, 0, 0xf
    addis	r0, r3, -0x900
    cmplwi	r0, 0
    bc      4, 2, _8001c494
    li	r0, 0
    stb	r0, 2(r31)
_8001c494:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void PADEnable(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    clrlwi.	r0, r4, 0x1c
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    bc      4, 2, _8001c504
    lwz	r3, lbl_801A64B4
    bl      UpdateOrigin
    lwz	r31, lbl_801A64B4
    lis	r0, -0x8000
    lwz	r3, lbl_801A697C
    addi	r4, r1, 0x1c
    srw	r0, r0, r31
    or	r0, r3, r0
    stw	r0, lbl_801A697C
    mr	r3, r31
    bl      SIGetResponse
    lwz	r0, lbl_801A64BC
    addi	r3, r31, 0
    oris	r4, r0, 0x40
    bl      SISetCommand
    lwz	r3, lbl_801A697C
    bl      SIGetWirelessID
_8001c504:
    lwz	r5, lbl_801A6980
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    lwz	r4, lbl_801A64B4
    cmpwi	r4, 0x20
    bc      12, 2, _8001c558
    lis	r0, -0x8000
    srw	r0, r0, r4
    andc	r0, r5, r0
    mulli	r4, r4, 0xc
    stw	r0, lbl_801A6980
    lis     r3, Origin@ha
    addi	r0, r3, Origin@l
    add	r3, r0, r4
    li	r4, 0
    li	r5, 0xc
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
_8001c558:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr
}

asm void PADDisable(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    lis	r0, -0x8000
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r4, 0
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    mr	r29, r3
    srw	r30, r0, r29
    lwz	r3, lbl_801A697C
    and.	r0, r3, r30
    bc      12, 2, _8001c610
    clrlwi.	r0, r31, 0x1c
    bc      4, 2, _8001c5b0
    mr	r3, r29
    bl      UpdateOrigin
_8001c5b0:
    rlwinm.	r0, r31, 0, 0x1c, 0x1c
    bc      12, 2, _8001c610
    bl      OSDisableInterrupts
    addi	r31, r3, 0
    addi	r3, r30, 0
    bl      SIGetWirelessIDBitfield
    lwz	r6, lbl_801A697C
    nor	r8, r30, r30
    lwz	r5, lbl_801A6988
    mr	r3, r29
    lwz	r4, lbl_801A698C
    lwz	r0, lbl_801A6990
    and	r7, r6, r8
    and	r6, r5, r8
    stw	r7, lbl_801A697C
    and	r5, r4, r8
    and	r0, r0, r8
    stw	r6, lbl_801A6988
    li	r4, 0
    stw	r5, lbl_801A698C
    stw	r0, lbl_801A6990
    bl      OSSetWirelessID
    mr	r3, r31
    bl      OSRestoreInterrupts
_8001c610:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr
}

asm void PADEnableWireless(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    clrlwi.	r0, r4, 0x1c
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    bc      4, 2, _8001c698
    lwz	r30, lbl_801A64B4
    lis	r31, -0x8000
    lwz	r3, lbl_801A697C
    addi	r4, r1, 0x1c
    srw	r0, r31, r30
    or	r0, r3, r0
    stw	r0, lbl_801A697C
    mr	r3, r30
    bl      SIGetResponse
    lwz	r0, lbl_801A64BC
    addi	r3, r30, 0
    oris	r4, r0, 0x40
    bl      SISetCommand
    lwz	r3, lbl_801A697C
    bl      SIGetWirelessID
    lwz	r0, lbl_801A64B4
    lwz	r3, lbl_801A6988
    srw	r0, r31, r0
    or	r0, r3, r0
    stw	r0, lbl_801A6988
_8001c698:
    lwz	r5, lbl_801A6980
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    lwz	r4, lbl_801A64B4
    cmpwi	r4, 0x20
    bc      12, 2, _8001c6ec
    lis	r0, -0x8000
    srw	r0, r0, r4
    andc	r0, r5, r0
    mulli	r4, r4, 0xc
    stw	r0, lbl_801A6980
    lis     r3, Origin@ha
    addi	r0, r3, Origin@l
    add	r3, r0, r4
    li	r4, 0
    li	r5, 0xc
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
_8001c6ec:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr
}

asm void PADTypeAndStatusCallback(void)
{
    nofralloc
    mflr	r0
    lis	r6, lbl_8015D0B0@ha
    stw	r0, 4(r1)
    clrlwi.	r0, r4, 0x1c
    stwu	r1, -0x40(r1)
    stw	r31, 0x3c(r1)
    lis	r31, -0x8000
    stw	r30, 0x38(r1)
    addi	r30, r6, lbl_8015D0B0@l
    stw	r29, 0x34(r1)
    stw	r28, 0x30(r1)
    lwz	r29, lbl_801A64B4
    lwz	r5, lbl_801A6984
    srw	r28, r31, r29
    andc	r3, r5, r28
    stw	r3, lbl_801A6984
    and	r5, r5, r28
    li	r3, 1
    bc      12, 2, _8001c7a0
    lwz	r4, lbl_801A6980
    cntlzw	r0, r4
    stw	r0, lbl_801A64B4
    lwz	r3, lbl_801A64B4
    cmpwi	r3, 0x20
    bc      12, 2, _8001ca10
    mulli	r0, r3, 0xc
    srw	r3, r31, r3
    andc	r4, r4, r3
    add	r3, r30, r0
    stw	r4, lbl_801A6980
    li	r4, 0
    li	r5, 0xc
    addi	r3, r3, 0x10
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
    b       _8001ca10
_8001c7a0:
    rlwinm	r6, r4, 0, 0, 0x17
    rlwinm	r4, r4, 0, 3, 4
    addis	r0, r4, -0x800
    slwi	r4, r29, 2
    cmplwi	r0, 0
    stwx	r6, r30, r4
    bc      4, 2, _8001c7c4
    rlwinm.	r0, r6, 0, 7, 7
    bc      4, 2, _8001c818
_8001c7c4:
    lwz	r5, lbl_801A6980
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    lwz	r4, lbl_801A64B4
    cmpwi	r4, 0x20
    bc      12, 2, _8001ca10
    lis	r3, -0x8000
    mulli	r0, r4, 0xc
    srw	r3, r3, r4
    andc	r4, r5, r3
    add	r3, r30, r0
    stw	r4, lbl_801A6980
    li	r4, 0
    li	r5, 0xc
    addi	r3, r3, 0x10
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
    b       _8001ca10
_8001c818:
    lwz	r0, lbl_801A64C0
    cmplwi	r0, 2
    bc      4, 0, _8001c8a4
    lwz	r0, lbl_801A697C
    addi	r3, r29, 0
    addi	r4, r1, 0x1c
    or	r0, r0, r28
    stw	r0, lbl_801A697C
    bl      SIGetResponse
    lwz	r0, lbl_801A64BC
    addi	r3, r29, 0
    oris	r4, r0, 0x40
    bl      SISetCommand
    lwz	r3, lbl_801A697C
    bl      SIGetWirelessID
    lwz	r4, lbl_801A6980
    cntlzw	r0, r4
    stw	r0, lbl_801A64B4
    lwz	r3, lbl_801A64B4
    cmpwi	r3, 0x20
    bc      12, 2, _8001ca10
    mulli	r0, r3, 0xc
    srw	r3, r31, r3
    andc	r4, r4, r3
    add	r3, r30, r0
    stw	r4, lbl_801A6980
    li	r4, 0
    li	r5, 0xc
    addi	r3, r3, 0x10
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
    b       _8001ca10
_8001c8a4:
    rlwinm.	r0, r6, 0, 0, 0
    bc      12, 2, _8001c8b4
    rlwinm.	r0, r6, 0, 5, 5
    bc      12, 2, _8001c924
_8001c8b4:
    cmplwi	r5, 0
    bc      12, 2, _8001c8f0
    mulli	r0, r29, 0xc
    lis     r3, PADEnable@ha
    add	r6, r30, r0
    addi	r8, r3, PADEnable@l
    addi	r3, r29, 0
    li	r4, lbl_801A64CC
    li	r5, 3
    li	r7, 0xa
    li	r10, 0
    li	r9, 0
    addi	r6, r6, 0x10
    bl      SITransfer
    b       _8001c9ac
_8001c8f0:
    mulli	r0, r29, 0xc
    lis     r3, PADEnable@ha
    add	r6, r30, r0
    addi	r8, r3, PADEnable@l
    addi	r3, r29, 0
    li	r4, lbl_801A64C8
    li	r5, 1
    li	r7, 0xa
    li	r10, 0
    li	r9, 0
    addi	r6, r6, 0x10
    bl      SITransfer
    b       _8001c9ac
_8001c924:
    rlwinm.	r0, r6, 0, 0xb, 0xb
    bc      12, 2, _8001c9ac
    rlwinm.	r0, r6, 0, 0xc, 0xc
    bc      4, 2, _8001c9ac
    rlwinm.	r0, r6, 0, 0xd, 0xd
    bc      4, 2, _8001c9ac
    rlwinm.	r0, r6, 0, 1, 1
    bc      12, 2, _8001c978
    mulli	r0, r29, 0xc
    lis     r3, PADEnable@ha
    add	r6, r30, r0
    addi	r8, r3, PADEnable@l
    addi	r3, r29, 0
    li	r4, lbl_801A64C8
    li	r5, 1
    li	r7, 0xa
    li	r10, 0
    li	r9, 0
    addi	r6, r6, 0x10
    bl      SITransfer
    b       _8001c9ac
_8001c978:
    mulli	r0, r29, 0xc
    lis     r3, PADEnableWireless@ha
    add	r4, r30, r4
    add	r6, r30, r0
    addi	r8, r3, PADEnableWireless@l
    addi	r3, r29, 0
    li	r5, 3
    li	r7, 8
    li	r10, 0
    li	r9, 0
    addi	r4, r4, 0x40
    addi	r6, r6, 0x10
    bl      SITransfer
_8001c9ac:
    cmpwi	r3, 0
    bc      4, 2, _8001ca10
    lwz	r5, lbl_801A6980
    lwz	r3, lbl_801A6990
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    or	r0, r3, r28
    lwz	r4, lbl_801A64B4
    stw	r0, lbl_801A6990
    cmpwi	r4, 0x20
    bc      12, 2, _8001ca10
    lis	r3, -0x8000
    mulli	r0, r4, 0xc
    srw	r3, r3, r4
    andc	r4, r5, r3
    add	r3, r30, r0
    stw	r4, lbl_801A6980
    li	r4, 0
    li	r5, 0xc
    addi	r3, r3, 0x10
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
_8001ca10:
    lwz	r0, 0x44(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    lwz	r29, 0x34(r1)
    lwz	r28, 0x30(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr
}

asm void PADOriginUpdateCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    lis	r3, -0x8000
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    srw	r29, r3, r31
    lwz	r0, lbl_801A697C
    and.	r0, r0, r29
    bc      12, 2, _8001cb48
    lwz	r5, lbl_801A6988
    nor	r6, r29, r29
    lwz	r3, lbl_801A698C
    clrlwi.	r0, r4, 0x1c
    and	r5, r5, r6
    and	r3, r3, r6
    stw	r5, lbl_801A6988
    stw	r3, lbl_801A698C
    rlwinm	r3, r4, 0, 0, 0x17
    bc      4, 2, _8001caf0
    rlwinm.	r0, r3, 0, 0, 0
    bc      12, 2, _8001caf0
    rlwinm.	r0, r3, 0, 0xb, 0xb
    bc      12, 2, _8001caf0
    rlwinm.	r0, r3, 0, 1, 1
    bc      12, 2, _8001caf0
    rlwinm.	r0, r3, 0, 5, 5
    bc      4, 2, _8001caf0
    rlwinm.	r0, r3, 0, 0xc, 0xc
    bc      4, 2, _8001caf0
    rlwinm.	r0, r3, 0, 0xd, 0xd
    bc      4, 2, _8001caf0
    mulli	r4, r31, 0xc
    lis     r3, Origin@ha
    addi	r0, r3, Origin@l
    lis     r3, PADDisable@ha
    add	r6, r0, r4
    addi	r8, r3, PADDisable@l
    addi	r3, r31, 0
    li	r4, lbl_801A64C8
    li	r5, 1
    li	r7, 0xa
    li	r10, 0
    li	r9, 0
    bl      SITransfer
    b       _8001cb48
_8001caf0:
    bl      OSDisableInterrupts
    addi	r30, r3, 0
    addi	r3, r29, 0
    bl      SIGetWirelessIDBitfield
    lwz	r6, lbl_801A697C
    nor	r8, r29, r29
    lwz	r5, lbl_801A6988
    mr	r3, r31
    lwz	r4, lbl_801A698C
    lwz	r0, lbl_801A6990
    and	r7, r6, r8
    and	r6, r5, r8
    stw	r7, lbl_801A697C
    and	r5, r4, r8
    and	r0, r0, r8
    stw	r6, lbl_801A6988
    li	r4, 0
    stw	r5, lbl_801A698C
    stw	r0, lbl_801A6990
    bl      OSSetWirelessID
    mr	r3, r30
    bl      OSRestoreInterrupts
_8001cb48:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr
}

asm void PADReset(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lwz	r4, lbl_801A6990
    li	r7, 0
    lwz	r5, lbl_801A6988
    addi	r31, r3, 0
    lwz	r0, lbl_801A698C
    or	r30, r30, r4
    lwz	r4, lbl_801A6980
    or	r5, r5, r0
    lwz	r0, lbl_801A64C0
    andc	r30, r30, r5
    lwz	r5, lbl_801A697C
    or	r6, r4, r30
    stw	r7, lbl_801A6990
    andc	r4, r5, r30
    stw	r6, lbl_801A6980
    cmplwi	r0, 4
    lwz	r0, lbl_801A6980
    stw	r4, lbl_801A697C
    and	r3, r0, r5
    bc      4, 2, _8001cbdc
    lwz	r0, lbl_801A6984
    or	r0, r0, r30
    stw	r0, lbl_801A6984
_8001cbdc:
    bl      SIGetWirelessIDBitfield
    lwz	r0, lbl_801A64B4
    cmpwi	r0, 0x20
    bc      4, 2, _8001cc40
    lwz	r5, lbl_801A6980
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    lwz	r4, lbl_801A64B4
    cmpwi	r4, 0x20
    bc      12, 2, _8001cc40
    lis	r0, -0x8000
    srw	r0, r0, r4
    andc	r0, r5, r0
    mulli	r4, r4, 0xc
    stw	r0, lbl_801A6980
    lis     r3, Origin@ha
    addi	r0, r3, Origin@l
    add	r3, r0, r4
    li	r4, 0
    li	r5, 0xc
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
_8001cc40:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    li	r3, 1
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void PADRecalibrate(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lwz	r6, lbl_801A6990
    li	r7, 0
    lwz	r5, lbl_801A6988
    lis	r4, -0x8000
    lwz	r0, lbl_801A698C
    or	r30, r30, r6
    lwz	r6, lbl_801A6980
    or	r5, r5, r0
    lbz	r0, 0x30e3(r4)
    andc	r30, r30, r5
    lwz	r5, lbl_801A697C
    or	r4, r6, r30
    stw	r7, lbl_801A6990
    rlwinm.	r0, r0, 0, 0x19, 0x19
    stw	r4, lbl_801A6980
    andc	r4, r5, r30
    addi	r31, r3, 0
    lwz	r6, lbl_801A6980
    stw	r4, lbl_801A697C
    and	r3, r6, r5
    bc      4, 2, _8001cce0
    lwz	r0, lbl_801A6984
    or	r0, r0, r30
    stw	r0, lbl_801A6984
_8001cce0:
    bl      SIGetWirelessIDBitfield
    lwz	r0, lbl_801A64B4
    cmpwi	r0, 0x20
    bc      4, 2, _8001cd44
    lwz	r5, lbl_801A6980
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    lwz	r4, lbl_801A64B4
    cmpwi	r4, 0x20
    bc      12, 2, _8001cd44
    lis	r0, -0x8000
    srw	r0, r0, r4
    andc	r0, r5, r0
    mulli	r4, r4, 0xc
    stw	r0, lbl_801A6980
    lis     r3, Origin@ha
    addi	r0, r3, Origin@l
    add	r3, r0, r4
    li	r4, 0
    li	r5, 0xc
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
_8001cd44:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    li	r3, 1
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void PADInit(void)
{
    nofralloc
    mflr	r0
    lis     r3, lbl_8015D0B0@ha
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stmw	r25, 0x1c(r1)
    addi	r31, r3, lbl_8015D0B0@l
    lwz	r0, lbl_801A6978
    cmpwi	r0, 0
    bc      12, 2, _8001cd94
    li	r3, 1
    b       _8001cf6c
_8001cd94:
    lwz	r3, lbl_801A64B0
    bl      OSRegisterVersion
    lwz	r3, __PADSpec
    cmplwi	r3, 0
    bc      12, 2, _8001cdac
    bl      PADSetSpec
_8001cdac:
    lwz	r0, lbl_801A6818
    li	r3, 1
    stw	r3, lbl_801A6978
    cmplwi	r0, 0
    bc      12, 2, _8001ce48
    bl      OSGetTime
    addi	r25, r4, 0
    addi	r26, r3, 0
    li	r5, 0x10
    bl      __shr2i
    lis	r5, 1
    addi	r27, r5, -1
    li	r28, 0
    and	r6, r4, r27
    and	r4, r25, r27
    and	r5, r3, r28
    and	r0, r26, r28
    addc	r29, r4, r6
    addi	r3, r26, 0
    addi	r4, r25, 0
    adde	r30, r0, r5
    li	r5, 0x20
    bl      __shr2i
    and	r4, r4, r27
    and	r0, r3, r28
    addc	r29, r4, r29
    addi	r3, r26, 0
    addi	r4, r25, 0
    adde	r30, r0, r30
    li	r5, 0x30
    bl      __shr2i
    and	r0, r4, r27
    addc	r5, r0, r29
    lis	r0, -0x1000
    li	r4, 0x3fff
    stw	r0, lbl_801A6984
    and	r0, r5, r4
    lis	r3, -0x8000
    sth	r0, 0x30e0(r3)
_8001ce48:
    lis	r3, -0x8000
    lhz	r0, 0x30e0(r3)
    rlwinm	r0, r0, 8, 0xa, 0x17
    oris	r0, r0, 0x4d00
    stw	r0, 0x40(r31)
    lhz	r0, 0x30e0(r3)
    rlwinm	r0, r0, 8, 0xa, 0x17
    oris	r0, r0, 0x4d40
    stw	r0, 0x44(r31)
    lhz	r0, 0x30e0(r3)
    rlwinm	r0, r0, 8, 0xa, 0x17
    oris	r0, r0, 0x4d80
    stw	r0, 0x48(r31)
    lhz	r0, 0x30e0(r3)
    rlwinm	r0, r0, 8, 0xa, 0x17
    oris	r0, r0, 0x4dc0
    stw	r0, 0x4c(r31)
    bl      SISetSamplingRateRestore
    lis     r3, lbl_801245E0@ha
    addi	r3, r3, lbl_801245E0@l
    bl      OSRegisterResetFunction
    lis	r28, -0x1000
    bl      OSDisableInterrupts
    lwz	r4, lbl_801A6990
    li	r7, 0
    lwz	r5, lbl_801A6988
    addi	r27, r3, 0
    lwz	r0, lbl_801A698C
    or	r28, r28, r4
    lwz	r4, lbl_801A6980
    or	r5, r5, r0
    lwz	r0, lbl_801A64C0
    andc	r28, r28, r5
    lwz	r5, lbl_801A697C
    or	r6, r4, r28
    stw	r7, lbl_801A6990
    andc	r4, r5, r28
    stw	r6, lbl_801A6980
    cmplwi	r0, 4
    lwz	r0, lbl_801A6980
    stw	r4, lbl_801A697C
    and	r3, r0, r5
    bc      4, 2, _8001cf00
    lwz	r0, lbl_801A6984
    or	r0, r0, r28
    stw	r0, lbl_801A6984
_8001cf00:
    bl      SIGetWirelessIDBitfield
    lwz	r0, lbl_801A64B4
    cmpwi	r0, 0x20
    bc      4, 2, _8001cf60
    lwz	r5, lbl_801A6980
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    lwz	r4, lbl_801A64B4
    cmpwi	r4, 0x20
    bc      12, 2, _8001cf60
    lis	r3, -0x8000
    mulli	r0, r4, 0xc
    srw	r3, r3, r4
    andc	r4, r5, r3
    add	r3, r31, r0
    stw	r4, lbl_801A6980
    li	r4, 0
    li	r5, 0xc
    addi	r3, r3, 0x10
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
_8001cf60:
    mr	r3, r27
    bl      OSRestoreInterrupts
    li	r3, 1
_8001cf6c:
    lmw	r25, 0x1c(r1)
    lwz	r0, 0x3c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr
}

asm void PADRead(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x50(r1)
    stmw	r20, 0x20(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    li	r21, 0
    mulli	r0, r21, 0xc
    lis     r4, Origin@ha
    addi	r26, r4, Origin@l
    lis     r4, PADDisable@ha
    lis     r5, PADOriginUpdateCallback@ha
    lis     r6, PADTypeAndStatusCallback@ha
    add	r24, r26, r0
    addi	r22, r3, 0
    addi	r30, r4, PADDisable@l
    addi	r29, r5, PADOriginUpdateCallback@l
    addi	r28, r6, PADTypeAndStatusCallback@l
    li	r20, 0
    lis	r27, -0x8000
_8001cfd0:
    lwz	r0, lbl_801A6990
    srw	r23, r27, r21
    and.	r0, r0, r23
    bc      12, 2, _8001d0b4
    bl      OSDisableInterrupts
    lwz	r4, lbl_801A6988
    li	r6, 0
    lwz	r0, lbl_801A698C
    mr	r25, r3
    lwz	r5, lbl_801A6990
    or	r4, r4, r0
    lwz	r0, lbl_801A6980
    andc	r7, r5, r4
    lwz	r5, lbl_801A697C
    or	r4, r0, r7
    lwz	r0, lbl_801A64C0
    stw	r4, lbl_801A6980
    andc	r4, r5, r7
    cmplwi	r0, 4
    lwz	r0, lbl_801A6980
    stw	r6, lbl_801A6990
    and	r3, r0, r5
    stw	r4, lbl_801A697C
    bc      4, 2, _8001d03c
    lwz	r0, lbl_801A6984
    or	r0, r0, r7
    stw	r0, lbl_801A6984
_8001d03c:
    bl      SIGetWirelessIDBitfield
    lwz	r0, lbl_801A64B4
    cmpwi	r0, 0x20
    bc      4, 2, _8001d090
    lwz	r4, lbl_801A6980
    cntlzw	r0, r4
    stw	r0, lbl_801A64B4
    lwz	r3, lbl_801A64B4
    cmpwi	r3, 0x20
    bc      12, 2, _8001d090
    mulli	r0, r3, 0xc
    srw	r3, r27, r3
    andc	r4, r4, r3
    stw	r4, lbl_801A6980
    add	r3, r26, r0
    li	r4, 0
    li	r5, 0xc
    bl      memset
    lwz	r3, lbl_801A64B4
    mr	r4, r28
    bl      SIGetTypeAsync
_8001d090:
    mr	r3, r25
    bl      OSRestoreInterrupts
    li	r0, -2
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    b       _8001d2f8
_8001d0b4:
    lwz	r0, lbl_801A6980
    and.	r0, r0, r23
    bc      4, 2, _8001d0cc
    lwz	r0, lbl_801A64B4
    cmpw	r0, r21
    bc      4, 2, _8001d0e8
_8001d0cc:
    li	r0, -2
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    b       _8001d2f8
_8001d0e8:
    lwz	r0, lbl_801A697C
    and.	r0, r0, r23
    bc      4, 2, _8001d110
    li	r0, -1
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    b       _8001d2f8
_8001d110:
    mr	r3, r21
    bl      SIIsChanBusy
    cmpwi	r3, 0
    bc      12, 2, _8001d13c
    li	r0, -3
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    b       _8001d2f8
_8001d13c:
    mr	r3, r21
    bl      SIGetStatus
    rlwinm.	r0, r3, 0, 0x1c, 0x1c
    bc      12, 2, _8001d214
    addi	r3, r21, 0
    addi	r4, r1, 0x14
    bl      SIGetResponse
    lwz	r0, lbl_801A6988
    and.	r0, r0, r23
    bc      12, 2, _8001d1a0
    li	r0, 0
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    lwz	r3, lbl_801A698C
    and.	r0, r3, r23
    bc      4, 2, _8001d2f8
    or	r0, r3, r23
    stw	r0, lbl_801A698C
    addi	r3, r21, 0
    addi	r4, r29, 0
    bl      SIGetTypeAsync
    b       _8001d2f8
_8001d1a0:
    bl      OSDisableInterrupts
    addi	r25, r3, 0
    addi	r3, r23, 0
    bl      SIGetWirelessIDBitfield
    lwz	r6, lbl_801A697C
    nor	r8, r23, r23
    lwz	r5, lbl_801A6988
    mr	r3, r21
    lwz	r4, lbl_801A698C
    lwz	r0, lbl_801A6990
    and	r7, r6, r8
    and	r6, r5, r8
    stw	r7, lbl_801A697C
    and	r5, r4, r8
    and	r0, r0, r8
    stw	r6, lbl_801A6988
    li	r4, 0
    stw	r5, lbl_801A698C
    stw	r0, lbl_801A6990
    bl      OSSetWirelessID
    mr	r3, r25
    bl      OSRestoreInterrupts
    li	r0, -1
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    b       _8001d2f8
_8001d214:
    mr	r3, r21
    bl      SIGetType
    rlwinm.	r0, r3, 0, 2, 2
    bc      4, 2, _8001d228
    or	r20, r20, r23
_8001d228:
    addi	r3, r21, 0
    addi	r4, r1, 0x14
    bl      SIGetResponse
    cmpwi	r3, 0
    bc      4, 2, _8001d258
    li	r0, -3
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    b       _8001d2f8
_8001d258:
    lwz	r0, 0x14(r1)
    rlwinm.	r0, r0, 0, 0, 0
    bc      12, 2, _8001d280
    li	r0, -3
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    b       _8001d2f8
_8001d280:
    lwz	r12, lbl_801A64C4
    addi	r3, r21, 0
    addi	r4, r31, 0
    mtlr	r12
    addi	r5, r1, 0x14
    blrl
    lhz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0x12, 0x12
    bc      12, 2, _8001d2e4
    li	r0, -3
    stb	r0, 0xa(r31)
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0xa
    bl      memset
    addi	r3, r21, 0
    addi	r6, r24, 0
    addi	r8, r30, 0
    li	r4, lbl_801A64C8
    li	r5, 1
    li	r7, 0xa
    li	r10, 0
    li	r9, 0
    bl      SITransfer
    b       _8001d2f8
_8001d2e4:
    li	r0, 0
    stb	r0, 0xa(r31)
    lhz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x19, 0x17
    sth	r0, 0(r31)
_8001d2f8:
    addi	r21, r21, 1
    cmpwi	r21, 4
    addi	r24, r24, 0xc
    addi	r31, r31, 0xc
    bc      12, 0, _8001cfd0
    mr	r3, r22
    bl      OSRestoreInterrupts
    mr	r3, r20
    lmw	r20, 0x20(r1)
    lwz	r0, 0x54(r1)
    addi	r1, r1, 0x50
    mtlr	r0
    blr
}

asm void SISetCommandByChannel(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stmw	r27, 0x14(r1)
    mr	r27, r3
    bl      OSDisableInterrupts
    addi	r30, r3, 0
    li	r28, 0
    li	r29, 0
    lis	r31, -0x8000
_8001d354:
    lwz	r3, lbl_801A697C
    srw	r0, r31, r29
    and.	r0, r3, r0
    bc      12, 2, _8001d3ac
    mr	r3, r29
    bl      SIGetType
    rlwinm.	r0, r3, 0, 2, 2
    bc      4, 2, _8001d3ac
    lwz	r0, lbl_801A64C0
    lwz	r3, 0(r27)
    cmplwi	r0, 2
    bc      4, 0, _8001d390
    cmplwi	r3, 2
    bc      4, 2, _8001d390
    li	r3, 0
_8001d390:
    lwz	r4, lbl_801A64BC
    clrlwi	r0, r3, 0x1e
    addi	r3, r29, 0
    oris	r4, r4, 0x40
    or	r4, r4, r0
    bl      SISetCommand
    li	r28, 1
_8001d3ac:
    addi	r29, r29, 1
    cmpwi	r29, 4
    addi	r27, r27, 4
    bc      12, 0, _8001d354
    cmpwi	r28, 0
    bc      12, 2, _8001d3c8
    bl      SITransferCommands
_8001d3c8:
    mr	r3, r30
    bl      OSRestoreInterrupts
    lmw	r27, 0x14(r1)
    lwz	r0, 0x2c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr
}

asm void SISetCommandByArray(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    addi	r30, r4, 0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    bl      OSDisableInterrupts
    lis	r0, -0x8000
    lwz	r4, lbl_801A697C
    srw	r0, r0, r29
    and.	r0, r4, r0
    addi	r31, r3, 0
    bc      12, 2, _8001d464
    mr	r3, r29
    bl      SIGetType
    rlwinm.	r0, r3, 0, 2, 2
    bc      4, 2, _8001d464
    lwz	r0, lbl_801A64C0
    cmplwi	r0, 2
    bc      4, 0, _8001d448
    cmplwi	r30, 2
    bc      4, 2, _8001d448
    li	r30, 0
_8001d448:
    lwz	r4, lbl_801A64BC
    clrlwi	r0, r30, 0x1e
    addi	r3, r29, 0
    oris	r4, r4, 0x40
    or	r4, r4, r0
    bl      SISetCommand
    bl      SITransferCommands
_8001d464:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr
}

asm void PADSetSpec(void)
{
    nofralloc
    li	r0, 0
    cmpwi	r3, 1
    stw	r0, __PADSpec
    bc      12, 2, _8001d4c4
    bc      4, 0, _8001d4a8
    cmpwi	r3, 0
    bc      4, 0, _8001d4b4
    b       _8001d4e0
_8001d4a8:
    cmpwi	r3, 6
    bc      4, 0, _8001d4e0
    b       _8001d4d4
_8001d4b4:
    lis     r4, SPEC0_MakeStatus@ha
    addi	r0, r4, SPEC0_MakeStatus@l
    stw	r0, lbl_801A64C4
    b       _8001d4e0
_8001d4c4:
    lis     r4, SPEC1_MakeStatus@ha
    addi	r0, r4, SPEC1_MakeStatus@l
    stw	r0, lbl_801A64C4
    b       _8001d4e0
_8001d4d4:
    lis     r4, SPEC2_MakeStatus@ha
    addi	r0, r4, SPEC2_MakeStatus@l
    stw	r0, lbl_801A64C4
_8001d4e0:
    stw	r3, lbl_801A64C0
    blr
}

asm void SPEC0_MakeStatus(void)
{
    nofralloc
    li	r3, 0
    sth	r3, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x1c, 0x1c
    bc      12, 2, _8001d500
    li	r3, 0x100
_8001d500:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x1a, 0x1a
    bc      12, 2, _8001d520
    li	r3, 0x200
    b       _8001d524
_8001d520:
    li	r3, 0
_8001d524:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x17, 0x17
    bc      12, 2, _8001d544
    li	r3, 0x400
    b       _8001d548
_8001d544:
    li	r3, 0
_8001d548:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x1f, 0x1f
    bc      12, 2, _8001d568
    li	r3, 0x800
    b       _8001d56c
_8001d568:
    li	r3, 0
_8001d56c:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x1b, 0x1b
    bc      12, 2, _8001d58c
    li	r6, 0x1000
    b       _8001d590
_8001d58c:
    li	r6, 0
_8001d590:
    lhz	r3, 0(r4)
    li	r0, 0
    or	r3, r3, r6
    sth	r3, 0(r4)
    lwz	r3, 4(r5)
    srwi	r3, r3, 0x10
    extsb	r3, r3
    stb	r3, 2(r4)
    lwz	r3, 4(r5)
    srwi	r3, r3, 0x18
    extsb	r3, r3
    stb	r3, 3(r4)
    lwz	r3, 4(r5)
    extsb	r3, r3
    stb	r3, 4(r4)
    lwz	r3, 4(r5)
    srwi	r3, r3, 8
    extsb	r3, r3
    stb	r3, 5(r4)
    lwz	r3, 0(r5)
    rlwinm	r3, r3, 0x18, 0x18, 0x1f
    stb	r3, 6(r4)
    lwz	r3, 0(r5)
    stb	r3, 7(r4)
    stb	r0, 8(r4)
    stb	r0, 9(r4)
    lbz	r0, 6(r4)
    cmplwi	r0, 0xaa
    bc      12, 0, _8001d610
    lhz	r0, 0(r4)
    ori	r0, r0, 0x40
    sth	r0, 0(r4)
_8001d610:
    lbz	r0, 7(r4)
    cmplwi	r0, 0xaa
    bc      12, 0, _8001d628
    lhz	r0, 0(r4)
    ori	r0, r0, 0x20
    sth	r0, 0(r4)
_8001d628:
    lbz	r3, 2(r4)
    addi	r0, r3, -0x80
    stb	r0, 2(r4)
    lbz	r3, 3(r4)
    addi	r0, r3, -0x80
    stb	r0, 3(r4)
    lbz	r3, 4(r4)
    addi	r0, r3, -0x80
    stb	r0, 4(r4)
    lbz	r3, 5(r4)
    addi	r0, r3, -0x80
    stb	r0, 5(r4)
    blr
}

asm void SPEC1_MakeStatus(void)
{
    nofralloc
    li	r3, 0
    sth	r3, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x18, 0x18
    bc      12, 2, _8001d674
    li	r3, 0x100
_8001d674:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x17, 0x17
    bc      12, 2, _8001d694
    li	r3, 0x200
    b       _8001d698
_8001d694:
    li	r3, 0
_8001d698:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x1a, 0x1a
    bc      12, 2, _8001d6b8
    li	r3, 0x400
    b       _8001d6bc
_8001d6b8:
    li	r3, 0
_8001d6bc:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x1b, 0x1b
    bc      12, 2, _8001d6dc
    li	r3, 0x800
    b       _8001d6e0
_8001d6dc:
    li	r3, 0
_8001d6e0:
    lhz	r0, 0(r4)
    or	r0, r0, r3
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    rlwinm.	r0, r0, 0x10, 0x16, 0x16
    bc      12, 2, _8001d700
    li	r6, 0x1000
    b       _8001d704
_8001d700:
    li	r6, 0
_8001d704:
    lhz	r3, 0(r4)
    li	r0, 0
    or	r3, r3, r6
    sth	r3, 0(r4)
    lwz	r3, 4(r5)
    srwi	r3, r3, 0x10
    extsb	r3, r3
    stb	r3, 2(r4)
    lwz	r3, 4(r5)
    srwi	r3, r3, 0x18
    extsb	r3, r3
    stb	r3, 3(r4)
    lwz	r3, 4(r5)
    extsb	r3, r3
    stb	r3, 4(r4)
    lwz	r3, 4(r5)
    srwi	r3, r3, 8
    extsb	r3, r3
    stb	r3, 5(r4)
    lwz	r3, 0(r5)
    rlwinm	r3, r3, 0x18, 0x18, 0x1f
    stb	r3, 6(r4)
    lwz	r3, 0(r5)
    stb	r3, 7(r4)
    stb	r0, 8(r4)
    stb	r0, 9(r4)
    lbz	r0, 6(r4)
    cmplwi	r0, 0xaa
    bc      12, 0, _8001d784
    lhz	r0, 0(r4)
    ori	r0, r0, 0x40
    sth	r0, 0(r4)
_8001d784:
    lbz	r0, 7(r4)
    cmplwi	r0, 0xaa
    bc      12, 0, _8001d79c
    lhz	r0, 0(r4)
    ori	r0, r0, 0x20
    sth	r0, 0(r4)
_8001d79c:
    lbz	r3, 2(r4)
    addi	r0, r3, -0x80
    stb	r0, 2(r4)
    lbz	r3, 3(r4)
    addi	r0, r3, -0x80
    stb	r0, 3(r4)
    lbz	r3, 4(r4)
    addi	r0, r3, -0x80
    stb	r0, 4(r4)
    lbz	r3, 5(r4)
    addi	r0, r3, -0x80
    stb	r0, 5(r4)
    blr
}

asm void SPEC2_MakeStatus(void)
{
    nofralloc
    lwz	r0, 0(r5)
    rlwinm	r0, r0, 0x10, 0x12, 0x1f
    sth	r0, 0(r4)
    lwz	r0, 0(r5)
    srwi	r0, r0, 8
    extsb	r0, r0
    stb	r0, 2(r4)
    lwz	r0, 0(r5)
    extsb	r0, r0
    stb	r0, 3(r4)
    lwz	r0, lbl_801A64BC
    rlwinm	r0, r0, 0, 0x15, 0x17
    cmpwi	r0, 0x400
    bc      12, 2, _8001d99c
    bc      4, 0, _8001d83c
    cmpwi	r0, 0x200
    bc      12, 2, _8001d908
    bc      4, 0, _8001d830
    cmpwi	r0, 0x100
    bc      12, 2, _8001d8b4
    bc      4, 0, _8001d9dc
    cmpwi	r0, 0
    bc      12, 2, _8001d860
    b       _8001d9dc
_8001d830:
    cmpwi	r0, 0x300
    bc      12, 2, _8001d958
    b       _8001d9dc
_8001d83c:
    cmpwi	r0, 0x600
    bc      12, 2, _8001d860
    bc      4, 0, _8001d854
    cmpwi	r0, 0x500
    bc      12, 2, _8001d860
    b       _8001d9dc
_8001d854:
    cmpwi	r0, 0x700
    bc      12, 2, _8001d860
    b       _8001d9dc
_8001d860:
    lwz	r0, 4(r5)
    srwi	r0, r0, 0x18
    extsb	r0, r0
    stb	r0, 4(r4)
    lwz	r0, 4(r5)
    srwi	r0, r0, 0x10
    extsb	r0, r0
    stb	r0, 5(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x18, 0x18, 0x1b
    stb	r0, 6(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x1c, 0x18, 0x1b
    stb	r0, 7(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0, 0x18, 0x1b
    stb	r0, 8(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 4, 0x18, 0x1b
    stb	r0, 9(r4)
    b       _8001d9dc
_8001d8b4:
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 8, 0x18, 0x1b
    extsb	r0, r0
    stb	r0, 4(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0xc, 0x18, 0x1b
    extsb	r0, r0
    stb	r0, 5(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x10, 0x18, 0x1f
    stb	r0, 6(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x18, 0x18, 0x1f
    stb	r0, 7(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0, 0x18, 0x1b
    stb	r0, 8(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 4, 0x18, 0x1b
    stb	r0, 9(r4)
    b       _8001d9dc
_8001d908:
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 8, 0x18, 0x1b
    extsb	r0, r0
    stb	r0, 4(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0xc, 0x18, 0x1b
    extsb	r0, r0
    stb	r0, 5(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x10, 0x18, 0x1b
    stb	r0, 6(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x14, 0x18, 0x1b
    stb	r0, 7(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x18, 0x18, 0x1f
    stb	r0, 8(r4)
    lwz	r0, 4(r5)
    stb	r0, 9(r4)
    b       _8001d9dc
_8001d958:
    lwz	r6, 4(r5)
    li	r0, 0
    srwi	r6, r6, 0x18
    extsb	r6, r6
    stb	r6, 4(r4)
    lwz	r6, 4(r5)
    srwi	r6, r6, 0x10
    extsb	r6, r6
    stb	r6, 5(r4)
    lwz	r6, 4(r5)
    rlwinm	r6, r6, 0x18, 0x18, 0x1f
    stb	r6, 6(r4)
    lwz	r5, 4(r5)
    stb	r5, 7(r4)
    stb	r0, 8(r4)
    stb	r0, 9(r4)
    b       _8001d9dc
_8001d99c:
    lwz	r6, 4(r5)
    li	r0, 0
    srwi	r6, r6, 0x18
    extsb	r6, r6
    stb	r6, 4(r4)
    lwz	r6, 4(r5)
    srwi	r6, r6, 0x10
    extsb	r6, r6
    stb	r6, 5(r4)
    stb	r0, 6(r4)
    stb	r0, 7(r4)
    lwz	r0, 4(r5)
    rlwinm	r0, r0, 0x18, 0x18, 0x1f
    stb	r0, 8(r4)
    lwz	r0, 4(r5)
    stb	r0, 9(r4)
_8001d9dc:
    lbz	r6, 2(r4)
    lis     r5, Origin@ha
    mulli	r3, r3, 0xc
    addi	r0, r6, -0x80
    stb	r0, 2(r4)
    addi	r0, r5, Origin@l
    add	r3, r0, r3
    lbz	r5, 3(r4)
    addi	r0, r5, -0x80
    stb	r0, 3(r4)
    lbz	r5, 4(r4)
    addi	r0, r5, -0x80
    stb	r0, 4(r4)
    lbz	r5, 5(r4)
    addi	r0, r5, -0x80
    stb	r0, 5(r4)
    lbz	r7, 2(r3)
    lbz	r6, 2(r4)
    extsb.	r0, r7
    bc      4, 1, _8001da4c
    extsb	r5, r7
    addi	r0, r5, -0x80
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r0, r5
    bc      4, 0, _8001da70
    mr	r6, r5
    b       _8001da70
_8001da4c:
    extsb.	r0, r7
    bc      4, 0, _8001da70
    extsb	r5, r7
    addi	r0, r5, 0x7f
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r5, r0
    bc      4, 0, _8001da70
    mr	r6, r5
_8001da70:
    subf	r6, r7, r6
    stb	r6, 2(r4)
    lbz	r7, 3(r3)
    lbz	r6, 3(r4)
    extsb.	r0, r7
    bc      4, 1, _8001daa8
    extsb	r5, r7
    addi	r0, r5, -0x80
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r0, r5
    bc      4, 0, _8001dacc
    mr	r6, r5
    b       _8001dacc
_8001daa8:
    extsb.	r0, r7
    bc      4, 0, _8001dacc
    extsb	r5, r7
    addi	r0, r5, 0x7f
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r5, r0
    bc      4, 0, _8001dacc
    mr	r6, r5
_8001dacc:
    subf	r6, r7, r6
    stb	r6, 3(r4)
    lbz	r7, 4(r3)
    lbz	r6, 4(r4)
    extsb.	r0, r7
    bc      4, 1, _8001db04
    extsb	r5, r7
    addi	r0, r5, -0x80
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r0, r5
    bc      4, 0, _8001db28
    mr	r6, r5
    b       _8001db28
_8001db04:
    extsb.	r0, r7
    bc      4, 0, _8001db28
    extsb	r5, r7
    addi	r0, r5, 0x7f
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r5, r0
    bc      4, 0, _8001db28
    mr	r6, r5
_8001db28:
    subf	r6, r7, r6
    stb	r6, 4(r4)
    lbz	r7, 5(r3)
    lbz	r6, 5(r4)
    extsb.	r0, r7
    bc      4, 1, _8001db60
    extsb	r5, r7
    addi	r0, r5, -0x80
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r0, r5
    bc      4, 0, _8001db84
    mr	r6, r5
    b       _8001db84
_8001db60:
    extsb.	r0, r7
    bc      4, 0, _8001db84
    extsb	r5, r7
    addi	r0, r5, 0x7f
    extsb	r5, r0
    extsb	r0, r6
    cmpw	r5, r0
    bc      4, 0, _8001db84
    mr	r6, r5
_8001db84:
    subf	r6, r7, r6
    stb	r6, 5(r4)
    lbz	r0, 6(r3)
    lbz	r5, 6(r4)
    cmplw	r5, r0
    bc      4, 0, _8001dba0
    mr	r5, r0
_8001dba0:
    subf	r5, r0, r5
    stb	r5, 6(r4)
    lbz	r0, 7(r3)
    lbz	r3, 7(r4)
    cmplw	r3, r0
    bc      4, 0, _8001dbbc
    mr	r3, r0
_8001dbbc:
    subf	r3, r0, r3
    stb	r3, 7(r4)
    blr
}

asm void PADSetAnalogMode(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lwz	r5, lbl_801A697C
    slwi	r6, r31, 8
    lwz	r4, lbl_801A6988
    mr	r31, r3
    addi	r8, r5, 0
    nor	r7, r8, r8
    lwz	r0, lbl_801A698C
    andc	r5, r5, r5
    stw	r6, lbl_801A64BC
    and	r4, r4, r7
    and	r0, r0, r7
    stw	r5, lbl_801A697C
    mr	r3, r8
    stw	r4, lbl_801A6988
    stw	r0, lbl_801A698C
    bl      SIGetWirelessIDBitfield
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void PADResetChannel(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    addi	r30, r3, 0
    lwz	r0, lbl_801A6994
    cmplwi	r0, 0
    bc      12, 2, _8001dc68
    li	r3, 0
    bl      PADSetSamplingCallback
_8001dc68:
    cmpwi	r30, 0
    bc      4, 2, _8001ddac
    lwz	r0, lbl_801A6980
    li	r30, 0
    addi	r3, r30, 0
    cmplwi	r0, 0
    bc      4, 2, _8001dc94
    lwz	r0, lbl_801A64B4
    cmpwi	r0, 0x20
    bc      4, 2, _8001dc94
    li	r3, 1
_8001dc94:
    cmpwi	r3, 0
    bc      12, 2, _8001dcac
    bl      SIChannelValid
    cmpwi	r3, 0
    bc      4, 2, _8001dcac
    li	r30, 1
_8001dcac:
    lwz	r0, lbl_801A6998
    cmpwi	r0, 0
    bc      4, 2, _8001dda4
    cmpwi	r30, 0
    bc      12, 2, _8001dda4
    lis	r30, -0x1000
    bl      OSDisableInterrupts
    lwz	r6, lbl_801A6990
    li	r7, 0
    lwz	r5, lbl_801A6988
    lis	r4, -0x8000
    lwz	r0, lbl_801A698C
    or	r30, r30, r6
    lwz	r6, lbl_801A6980
    or	r5, r5, r0
    lbz	r0, 0x30e3(r4)
    andc	r30, r30, r5
    lwz	r5, lbl_801A697C
    or	r4, r6, r30
    stw	r7, lbl_801A6990
    rlwinm.	r0, r0, 0, 0x19, 0x19
    stw	r4, lbl_801A6980
    andc	r4, r5, r30
    addi	r31, r3, 0
    lwz	r6, lbl_801A6980
    stw	r4, lbl_801A697C
    and	r3, r6, r5
    bc      4, 2, _8001dd28
    lwz	r0, lbl_801A6984
    or	r0, r0, r30
    stw	r0, lbl_801A6984
_8001dd28:
    bl      SIGetWirelessIDBitfield
    lwz	r0, lbl_801A64B4
    cmpwi	r0, 0x20
    bc      4, 2, _8001dd8c
    lwz	r5, lbl_801A6980
    cntlzw	r0, r5
    stw	r0, lbl_801A64B4
    lwz	r4, lbl_801A64B4
    cmpwi	r4, 0x20
    bc      12, 2, _8001dd8c
    lis	r0, -0x8000
    srw	r0, r0, r4
    andc	r0, r5, r0
    mulli	r4, r4, 0xc
    stw	r0, lbl_801A6980
    lis     r3, Origin@ha
    addi	r0, r3, Origin@l
    add	r3, r0, r4
    li	r4, 0
    li	r5, 0xc
    bl      memset
    lis     r4, PADTypeAndStatusCallback@ha
    lwz	r3, lbl_801A64B4
    addi	r4, r4, PADTypeAndStatusCallback@l
    bl      SIGetTypeAsync
_8001dd8c:
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r0, 1
    stw	r0, lbl_801A6998
    li	r3, 0
    b       _8001ddb8
_8001dda4:
    mr	r3, r30
    b       _8001ddb8
_8001ddac:
    li	r0, 0
    stw	r0, lbl_801A6998
    li	r3, 1
_8001ddb8:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr
}

asm void SamplingHandler(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x2e0(r1)
    stw	r31, 0x2dc(r1)
    addi	r31, r4, 0
    lwz	r0, lbl_801A6994
    cmplwi	r0, 0
    bc      12, 2, _8001de1c
    addi	r3, r1, 0x10
    bl      OSClearContext
    addi	r3, r1, 0x10
    bl      OSSetCurrentContext
    lwz	r12, lbl_801A6994
    mtlr	r12
    blrl
    addi	r3, r1, 0x10
    bl      OSClearContext
    mr	r3, r31
    bl      OSSetCurrentContext
_8001de1c:
    lwz	r0, 0x2e4(r1)
    lwz	r31, 0x2dc(r1)
    addi	r1, r1, 0x2e0
    mtlr	r0
    blr
}

asm void PADSetSamplingCallback(void)
{
    nofralloc
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    lwz	r31, lbl_801A6994
    stw	r3, lbl_801A6994
    bc      12, 2, _8001de60
    lis     r3, SamplingHandler@ha
    addi	r3, r3, SamplingHandler@l
    bl      SIRegisterPollingHandler
    b       _8001de6c
_8001de60:
    lis     r3, SamplingHandler@ha
    addi	r3, r3, SamplingHandler@l
    bl      SIUnregisterPollingHandler
_8001de6c:
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

asm void __PADDisableRecalibration(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lis	r4, -0x8000
    lbz	r0, 0x30e3(r4)
    rlwinm.	r0, r0, 0, 0x19, 0x19
    bc      12, 2, _8001deb8
    li	r31, 1
    b       _8001debc
_8001deb8:
    li	r31, 0
_8001debc:
    lis	r4, -0x8000
    lbz	r0, 0x30e3(r4)
    andi.	r0, r0, 0xbf
    cmpwi	r30, 0
    stb	r0, 0x30e3(r4)
    bc      12, 2, _8001dee0
    lbz	r0, 0x30e3(r4)
    ori	r0, r0, 0x40
    stb	r0, 0x30e3(r4)
_8001dee0:
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

#pragma force_active off
