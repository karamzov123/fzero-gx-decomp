typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

// MetroTRK remainder 0x80088B00-0x8008CB20 (pm10-c region B)

extern void memset(void);
extern void fn_80003590(void);
extern void fn_800035C0(void);
extern void fn_80005518(void);
extern void OSReport(void);
extern void strlen(void);
extern void TRKConstructEvent(void);
extern void TRKPostEvent(void);
extern void TRKSaveExtended1Block(void);
extern void TRKRestoreExtended1Block(void);
extern void TRKTargetTranslate(void);
extern void fn_8008D154(void);
extern void TRKUARTInterruptHandler(void);
extern void TRKDoWrite(void);
extern void TRK_ReadUARTN(void);
extern void TRKPollUART(void);
extern void TRKTargetContinue(void);
extern void fn_8008D7C0(void);
extern void MWTRACE(void);
extern void fn_8008AF40(void);
extern void TRKTargetStopped(void);
extern void TRKTestForPacket(void);
extern void usr_puts(void);
extern void TRKDoPing(void);
extern void TRKDoVersions(void);
extern void fn_8008998C(void);
extern void TRK_serialIO_init(void);
extern void fn_80089C5C(void);
extern void fn_80089EEC(void);
extern void fn_8008A1CC(void);
extern void fn_8008A3C0(void);
extern void fn_8008A5AC(void);
extern void fn_8008A5B4(void);
extern void fn_8008A5BC(void);
extern void fn_8008A614(void);
extern void fn_8008A66C(void);
extern void fn_8008A6E4(void);
extern void fn_8008A748(void);
extern void fn_8008A754(void);
extern void TRKRequestSend(void);
extern void fn_8008AF48(void);
extern void fn_8008AF50(void);
extern void fn_8008B484(void);
extern void fn_8008B6BC(void);
extern void TRKTargetCheckStep(void);
extern void fn_8008B784(void);
extern void fn_8008B830(void);
extern void fn_8008B8B4(void);
extern void TRKTargetAccessFP(void);
extern void TRKTargetAccessExtended1(void);
extern void TRKTargetAccessExtended2(void);
extern void TRKTargetAccessDefault(void);
extern void fn_8008C6E4(void);
extern void TRKTargetAccessMemory(void);
extern void TRKValidMemory32(void);
extern void TRKInterruptHandlerEnableInterrupts(void);
extern void TRKPostInterruptEvent(void);
extern void TRKExceptionHandler(void);
extern unsigned char gTRKBigEndian[4];
extern unsigned char gTRKCPUState[1072];
extern unsigned char gTRKRestoreFlags[9];
extern unsigned char gTRKState[164];
extern unsigned char jumptable_8015B7C0[108];
extern unsigned char jumptable_8015B830[28];
extern unsigned char jumptable_8015B84C[28];
extern unsigned char lbl_80095678[37];
extern unsigned char str_NoBufferAvailable[29];
extern unsigned char lbl_800956C0[400];
extern unsigned char lbl_80095850[25];
extern unsigned char lbl_8009586C[29];
extern unsigned char gTRKOptionsBuffer[52];
extern unsigned char lbl_800958C4[44];
extern unsigned char lbl_800958F0[31];
extern unsigned char lbl_80095910[348];
extern unsigned char lbl_80095A74[2];
extern unsigned char lbl_80095A78[168];
extern unsigned char gTRKMemMap[16];
extern unsigned char lbl_80095B30[40];
extern unsigned char lbl_80095B80[40];
extern unsigned char lbl_80095BA8[16];
extern unsigned char gTRKStepStatus[20];
extern unsigned char gTRKMsgBufs[6576];
extern unsigned char lbl_801A5098[24];
extern unsigned char gTRKInputPendingPtrStore[8];
extern unsigned char lbl_801A5624[20];
extern unsigned char x_str[6];

asm void TRKMessageSend(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r4, 8(r3)
    addi	r3, r3, 0x10
    bl      TRKDoWrite
    lis     r4, lbl_80095678@ha
    mr	r5, r3
    li	r3, 1
    addi	r4, r4, lbl_80095678@l
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void TRKAppendBuffer_ui32(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r6, gTRKBigEndian@ha
    stw	r0, 0x34(r1)
    stmw	r24, 0x10(r1)
    mr	r28, r3
    mr	r29, r5
    mr	r31, r4
    addi	r27, r6, gTRKBigEndian@l
    li	r30, 0
    li	r3, 0
    b       _80088c10
_80088b74:
    lwz	r0, 0(r27)
    cmpwi	r0, 0
    bc      12, 2, _80088b88
    mr	r25, r31
    b       _80088b8c
_80088b88:
    addi	r25, r1, 8
_80088b8c:
    lwz	r3, 0xc(r28)
    li	r24, 4
    lwz	r0, 8(r28)
    li	r26, 0
    subf	r0, r3, r0
    cmplw	r24, r0
    bc      4, 1, _80088bb0
    li	r26, 0x302
    mr	r24, r0
_80088bb0:
    addi	r4, r3, 0x10
    mr	r3, r25
    mr	r5, r24
    add	r4, r28, r4
    bl      fn_800035C0
    lwz	r0, 0xc(r28)
    add	r0, r0, r24
    stw	r0, 0xc(r28)
    lwz	r0, 0(r27)
    cmpwi	r0, 0
    bc      4, 2, _80088c04
    cmpwi	r26, 0
    bc      4, 2, _80088c04
    lbz	r0, 3(r25)
    stb	r0, 0(r31)
    lbz	r0, 2(r25)
    stb	r0, 1(r31)
    lbz	r0, 1(r25)
    stb	r0, 2(r31)
    lbz	r0, 0(r25)
    stb	r0, 3(r31)
_80088c04:
    mr	r3, r26
    addi	r31, r31, 4
    addi	r30, r30, 1
_80088c10:
    cmpwi	r3, 0
    bc      4, 2, _80088c20
    cmpw	r30, r29
    bc      12, 0, _80088b74
_80088c20:
    lmw	r24, 0x10(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void TRKReadBuffer(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r26, 8(r1)
    mr	r26, r3
    mr	r27, r4
    mr	r28, r5
    li	r29, 0
    li	r3, 0
    b       _80088ca8
_80088c5c:
    lwz	r3, 0xc(r26)
    li	r30, 1
    lwz	r0, 8(r26)
    li	r31, 0
    subf	r0, r3, r0
    cmplw	r30, r0
    bc      4, 1, _80088c80
    li	r31, 0x302
    mr	r30, r0
_80088c80:
    addi	r4, r3, 0x10
    mr	r5, r30
    add	r3, r27, r29
    add	r4, r26, r4
    bl      fn_800035C0
    lwz	r0, 0xc(r26)
    mr	r3, r31
    addi	r29, r29, 1
    add	r0, r0, r30
    stw	r0, 0xc(r26)
_80088ca8:
    cmpwi	r3, 0
    bc      4, 2, _80088cb8
    cmpw	r29, r28
    bc      12, 0, _80088c5c
_80088cb8:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKAppendBuffer1_ui64(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis	r5, -0x7fe6
    stw	r0, 0x34(r1)
    stmw	r27, 0x1c(r1)
    mr	r27, r3
    mr	r30, r4
    lwz	r0, 0x36e0(r5)
    cmpwi	r0, 0
    bc      12, 2, _80088cfc
    mr	r31, r30
    b       _80088d00
_80088cfc:
    addi	r31, r1, 8
_80088d00:
    lwz	r3, 0xc(r27)
    li	r28, 8
    lwz	r0, 8(r27)
    li	r29, 0
    subf	r0, r3, r0
    cmplw	r28, r0
    bc      4, 1, _80088d24
    li	r29, 0x302
    mr	r28, r0
_80088d24:
    addi	r4, r3, 0x10
    mr	r3, r31
    mr	r5, r28
    add	r4, r27, r4
    bl      fn_800035C0
    lwz	r0, 0xc(r27)
    lis	r3, -0x7fe6
    add	r0, r0, r28
    stw	r0, 0xc(r27)
    lwz	r0, 0x36e0(r3)
    cmpwi	r0, 0
    bc      4, 2, _80088d9c
    cmpwi	r29, 0
    bc      4, 2, _80088d9c
    lbz	r0, 7(r31)
    stb	r0, 0(r30)
    lbz	r0, 6(r31)
    stb	r0, 1(r30)
    lbz	r0, 5(r31)
    stb	r0, 2(r30)
    lbz	r0, 4(r31)
    stb	r0, 3(r30)
    lbz	r0, 3(r31)
    stb	r0, 4(r30)
    lbz	r0, 2(r31)
    stb	r0, 5(r30)
    lbz	r0, 1(r31)
    stb	r0, 6(r30)
    lbz	r0, 0(r31)
    stb	r0, 7(r30)
_80088d9c:
    mr	r3, r29
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void TRKReadBuffer_ui32(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r6, gTRKBigEndian@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    mr	r27, r3
    mr	r28, r5
    mr	r30, r4
    addi	r31, r6, gTRKBigEndian@l
    li	r29, 0
    li	r3, 0
    b       _80088e8c
_80088de4:
    lwz	r0, 0(r31)
    lwz	r3, 0(r30)
    cmpwi	r0, 0
    stw	r3, 8(r1)
    bc      12, 2, _80088e00
    addi	r4, r1, 8
    b       _80088e24
_80088e00:
    lbz	r6, 0xb(r1)
    addi	r4, r1, 0xc
    lbz	r5, 0xa(r1)
    lbz	r3, 9(r1)
    lbz	r0, 8(r1)
    stb	r6, 0xc(r1)
    stb	r5, 0xd(r1)
    stb	r3, 0xe(r1)
    stb	r0, 0xf(r1)
_80088e24:
    lwz	r5, 0xc(r27)
    li	r25, 4
    li	r26, 0
    subfic	r0, r5, 0x880
    cmplwi	r0, 4
    bc      4, 0, _80088e44
    li	r26, 0x301
    mr	r25, r0
_80088e44:
    cmplwi	r25, 1
    bc      4, 2, _80088e5c
    lbz	r3, 0(r4)
    addi	r0, r5, 0x10
    stbx	r3, r27, r0
    b       _80088e6c
_80088e5c:
    addi	r3, r5, 0x10
    mr	r5, r25
    add	r3, r27, r3
    bl      fn_800035C0
_80088e6c:
    lwz	r0, 0xc(r27)
    mr	r3, r26
    addi	r30, r30, 4
    addi	r29, r29, 1
    add	r0, r0, r25
    stw	r0, 0xc(r27)
    lwz	r0, 0xc(r27)
    stw	r0, 8(r27)
_80088e8c:
    cmpwi	r3, 0
    bc      4, 2, _80088e9c
    cmpw	r29, r28
    bc      12, 0, _80088de4
_80088e9c:
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void TRKAppendBuffer(void)
{
    nofralloc
    li	r9, 0
    li	r0, 0
    b       _80088f00
_80088ebc:
    lwz	r7, 0xc(r3)
    lbz	r8, 0(r4)
    cmplwi	r7, 0x880
    bc      12, 0, _80088ed4
    li	r7, 0x301
    b       _80088ef4
_80088ed4:
    addi	r6, r7, 1
    addi	r0, r7, 0x10
    stw	r6, 0xc(r3)
    li	r7, 0
    stbx	r8, r3, r0
    lwz	r6, 8(r3)
    addi	r0, r6, 1
    stw	r0, 8(r3)
_80088ef4:
    mr	r0, r7
    addi	r9, r9, 1
    addi	r4, r4, 1
_80088f00:
    cmpwi	r0, 0
    bc      4, 2, _80088f10
    cmpw	r9, r5
    bc      12, 0, _80088ebc
_80088f10:
    mr	r3, r0
    blr
}

asm void TRKReadBuffer1_ui64(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis	r4, -0x7fe6
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    mr	r31, r3
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    lwz	r0, 0x36e0(r4)
    stw	r5, 8(r1)
    cmpwi	r0, 0
    stw	r6, 0xc(r1)
    bc      12, 2, _80088f54
    addi	r4, r1, 8
    b       _80088f98
_80088f54:
    lbz	r10, 0xf(r1)
    addi	r4, r1, 0x10
    lbz	r9, 0xe(r1)
    lbz	r8, 0xd(r1)
    lbz	r7, 0xc(r1)
    lbz	r6, 0xb(r1)
    lbz	r5, 0xa(r1)
    lbz	r3, 9(r1)
    lbz	r0, 8(r1)
    stb	r10, 0x10(r1)
    stb	r9, 0x11(r1)
    stb	r8, 0x12(r1)
    stb	r7, 0x13(r1)
    stb	r6, 0x14(r1)
    stb	r5, 0x15(r1)
    stb	r3, 0x16(r1)
    stb	r0, 0x17(r1)
_80088f98:
    lwz	r3, 0xc(r31)
    li	r29, 8
    li	r30, 0
    subfic	r0, r3, 0x880
    cmplwi	r0, 8
    bc      4, 0, _80088fb8
    li	r30, 0x301
    mr	r29, r0
_80088fb8:
    cmplwi	r29, 1
    bc      4, 2, _80088fd0
    lbz	r0, 0(r4)
    add	r3, r31, r3
    stb	r0, 0x10(r3)
    b       _80088fe0
_80088fd0:
    addi	r3, r3, 0x10
    mr	r5, r29
    add	r3, r31, r3
    bl      fn_800035C0
_80088fe0:
    lwz	r0, 0xc(r31)
    mr	r3, r30
    add	r0, r0, r29
    stw	r0, 0xc(r31)
    lwz	r0, 0xc(r31)
    stw	r0, 8(r31)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void TRKAppendBuffer1_ui32(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    or.	r30, r5, r5
    stw	r29, 0x14(r1)
    mr	r29, r3
    mr	r3, r4
    bc      4, 2, _80089048
    li	r3, 0
    b       _80089084
_80089048:
    lwz	r4, 0xc(r29)
    lwz	r0, 8(r29)
    subf	r0, r4, r0
    cmplw	r30, r0
    bc      4, 1, _80089064
    li	r31, 0x302
    mr	r30, r0
_80089064:
    addi	r4, r4, 0x10
    mr	r5, r30
    add	r4, r29, r4
    bl      fn_800035C0
    lwz	r0, 0xc(r29)
    mr	r3, r31
    add	r0, r0, r30
    stw	r0, 0xc(r29)
_80089084:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKAppendBuffer1_ui16(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    or.	r30, r5, r5
    stw	r29, 0x14(r1)
    mr	r29, r3
    bc      4, 2, _800890d0
    li	r3, 0
    b       _80089128
_800890d0:
    lwz	r3, 0xc(r29)
    subfic	r0, r3, 0x880
    cmplw	r0, r30
    bc      4, 0, _800890e8
    li	r31, 0x301
    mr	r30, r0
_800890e8:
    cmplwi	r30, 1
    bc      4, 2, _80089100
    lbz	r0, 0(r4)
    add	r3, r29, r3
    stb	r0, 0x10(r3)
    b       _80089110
_80089100:
    addi	r3, r3, 0x10
    mr	r5, r30
    add	r3, r29, r3
    bl      fn_800035C0
_80089110:
    lwz	r0, 0xc(r29)
    mr	r3, r31
    add	r0, r0, r30
    stw	r0, 0xc(r29)
    lwz	r0, 0xc(r29)
    stw	r0, 8(r29)
_80089128:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKSetBufferPosition(void)
{
    nofralloc
    cmplwi	r4, 0x880
    li	r5, 0
    bc      4, 1, _80089158
    li	r5, 0x301
    b       _8008916c
_80089158:
    stw	r4, 0xc(r3)
    lwz	r0, 8(r3)
    cmplw	r4, r0
    bc      4, 1, _8008916c
    stw	r4, 8(r3)
_8008916c:
    mr	r3, r5
    blr
}

asm void TRKMessageIntoReply(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r4, 0
    stw	r0, 0x14(r1)
    li	r0, 0
    stw	r0, 8(r3)
    stw	r0, 0xc(r3)
    bc      4, 2, _800891a4
    addi	r3, r3, 0x10
    li	r4, 0
    li	r5, 0x880
    bl      fn_80003590
_800891a4:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void TRKReleaseBuffer(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r3, -1
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    bc      12, 2, _80089204
    cmpwi	r3, 0
    bc      12, 0, _80089204
    cmpwi	r3, 3
    bc      4, 0, _80089204
    mulli	r4, r3, 0x890
    lis     r3, gTRKMsgBufs@ha
    addi	r0, r3, gTRKMsgBufs@l
    add	r31, r0, r4
    mr	r3, r31
    bl      fn_8008AF48
    li	r0, 0
    mr	r3, r31
    stw	r0, 4(r31)
    bl      fn_8008AF40
_80089204:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void TRKGetBuffer(void)
{
    nofralloc
    cmpwi	r3, 0
    li	r0, 0
    bc      12, 0, _8008923c
    cmpwi	r3, 3
    bc      4, 0, _8008923c
    mulli	r4, r3, 0x890
    lis     r3, gTRKMsgBufs@ha
    addi	r0, r3, gTRKMsgBufs@l
    add	r0, r0, r4
_8008923c:
    mr	r3, r0
    blr
}

asm void TRKGetFreeBuffer(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    li	r0, 0
    stmw	r27, 0xc(r1)
    mr	r28, r4
    mr	r27, r3
    li	r30, 0x300
    li	r29, 0
    stw	r0, 0(r4)
    b       _800892d8
_80089270:
    cmpwi	r29, 0
    li	r31, 0
    bc      12, 0, _80089294
    cmpwi	r29, 3
    bc      4, 0, _80089294
    mulli	r4, r29, 0x890
    lis     r3, gTRKMsgBufs@ha
    addi	r0, r3, gTRKMsgBufs@l
    add	r31, r0, r4
_80089294:
    mr	r3, r31
    bl      fn_8008AF48
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bc      4, 2, _800892cc
    li	r3, 0
    li	r0, 1
    stw	r3, 8(r31)
    li	r30, 0
    stw	r3, 0xc(r31)
    stw	r0, 4(r31)
    stw	r31, 0(r28)
    stw	r29, 0(r27)
    li	r29, 3
_800892cc:
    mr	r3, r31
    bl      fn_8008AF40
    addi	r29, r29, 1
_800892d8:
    cmpwi	r29, 3
    bc      12, 0, _80089270
    cmpwi	r30, 0x300
    bc      4, 2, _800892f4
    lis     r3, str_NoBufferAvailable@ha
    addi	r3, r3, str_NoBufferAvailable@l
    bl      usr_puts
_800892f4:
    mr	r3, r30
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKInitializeMessageBuffers(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, gTRKMsgBufs@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    addi	r30, r3, gTRKMsgBufs@l
    stw	r29, 0x14(r1)
    li	r29, 0
_80089334:
    mr	r3, r30
    bl      fn_8008AF50
    mr	r3, r30
    bl      fn_8008AF48
    stw	r31, 4(r30)
    mr	r3, r30
    bl      fn_8008AF40
    addi	r29, r29, 1
    addi	r30, r30, 0x890
    cmpwi	r29, 3
    bc      12, 0, _80089334
    lwz	r0, 0x24(r1)
    li	r3, 0
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKAcquireMutex(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void TRKInitializeSerialHandler(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_801A5098@ha
    lis     r4, lbl_800956C0@ha
    stw	r0, 0x14(r1)
    addi	r6, r3, lbl_801A5098@l
    li	r0, 0
    li	r3, -1
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_800956C0@l
    addi	r4, r31, 0
    li	r5, 0x40
    stw	r3, 0(r6)
    li	r3, 1
    stw	r0, 8(r6)
    stw	r0, 0xc(r6)
    crxor	6, 6, 6
    bl      MWTRACE
    addi	r4, r31, 0x24
    li	r3, 1
    li	r5, 0x40
    crxor	6, 6, 6
    bl      MWTRACE
    addi	r4, r31, 0x48
    li	r3, 1
    li	r5, 0x40
    crxor	6, 6, 6
    bl      MWTRACE
    addi	r4, r31, 0x6c
    li	r3, 1
    li	r5, 0x40
    crxor	6, 6, 6
    bl      MWTRACE
    addi	r4, r31, 0x8c
    li	r3, 1
    li	r5, 0x40
    crxor	6, 6, 6
    bl      MWTRACE
    addi	r4, r31, 0xac
    li	r3, 1
    li	r5, 0x40
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r0, 0x14(r1)
    li	r3, 0
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void TRKProcessInput(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r4, 2
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    addi	r3, r1, 8
    bl      TRKConstructEvent
    lis     r3, lbl_801A5098@ha
    li	r0, -1
    addi	r4, r3, lbl_801A5098@l
    stw	r31, 0x10(r1)
    addi	r3, r1, 8
    stw	r0, 0(r4)
    bl      TRKPostEvent
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKGetInput(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    bl      TRKTestForPacket
    mr	r31, r3
    cmpwi	r31, -1
    bc      12, 2, _800894e8
    bl      TRKGetBuffer
    addi	r3, r1, 8
    li	r4, 2
    bl      TRKConstructEvent
    lis     r3, lbl_801A5098@ha
    li	r0, -1
    addi	r4, r3, lbl_801A5098@l
    stw	r31, 0x10(r1)
    addi	r3, r1, 8
    stw	r0, 0(r4)
    bl      TRKPostEvent
_800894e8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKTestForPacket(void)
{
    nofralloc
    stwu	r1, -0x8e0(r1)
    mflr	r0
    lis     r3, lbl_800956C0@ha
    stw	r0, 0x8e4(r1)
    stw	r31, 0x8dc(r1)
    addi	r31, r3, lbl_800956C0@l
    stw	r30, 0x8d8(r1)
    bl      TRKPollUART
    cmpwi	r3, 0
    bc      12, 1, _8008952c
    li	r3, -1
    b       _80089620
_8008952c:
    addi	r3, r1, 0xc
    addi	r4, r1, 8
    bl      TRKGetFreeBuffer
    mr	r30, r3
    addi	r4, r31, 0xd0
    li	r3, 4
    mr	r5, r30
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r3, 8(r1)
    li	r4, 0
    bl      TRKSetBufferPosition
    addi	r3, r1, 0x10
    li	r4, 0x40
    bl      TRK_ReadUARTN
    cmpwi	r3, 0
    bc      4, 2, _800895ec
    lwz	r3, 8(r1)
    addi	r4, r1, 0x10
    li	r5, 0x40
    bl      TRKAppendBuffer
    lwz	r3, 0x10(r1)
    lwz	r30, 0xc(r1)
    addic.	r5, r3, -0x40
    bc      4, 1, _80089608
    addi	r4, r31, 0xf4
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r4, 0x10(r1)
    addi	r3, r1, 0x50
    addi	r4, r4, -0x40
    bl      TRK_ReadUARTN
    cmpwi	r3, 0
    bc      4, 2, _800895cc
    lwz	r3, 8(r1)
    addi	r4, r1, 0x50
    lwz	r5, 0x10(r1)
    bl      TRKAppendBuffer
    b       _80089608
_800895cc:
    addi	r4, r31, 0x110
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r30
    bl      TRKReleaseBuffer
    li	r30, -1
    b       _80089608
_800895ec:
    addi	r4, r31, 0x144
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r30
    bl      TRKReleaseBuffer
    li	r30, -1
_80089608:
    mr	r5, r30
    addi	r4, r31, 0x16c
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r30
_80089620:
    lwz	r0, 0x8e4(r1)
    lwz	r31, 0x8dc(r1)
    lwz	r30, 0x8d8(r1)
    mtlr	r0
    addi	r1, r1, 0x8e0
    blr
}

asm void usr_put_initialize(void)
{
    nofralloc
    blr
}

asm void usr_puts(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    li	r3, 0
    b       _80089690
_80089664:
    bl      fn_8008A754
    stb	r30, 8(r1)
    mr	r30, r3
    li	r3, 0
    stb	r31, 9(r1)
    bl      fn_8008A748
    addi	r3, r1, 8
    bl      OSReport
    mr	r3, r30
    bl      fn_8008A748
    li	r3, 0
_80089690:
    cmpwi	r3, 0
    bc      4, 2, _800896a8
    lbz	r0, 0(r29)
    addi	r29, r29, 1
    extsb.	r30, r0
    bc      4, 2, _80089664
_800896a8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKDispatchMessage(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r4, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    li	r31, 0x500
    stw	r30, 8(r1)
    mr	r30, r3
    bl      TRKSetBufferPosition
    lis     r3, lbl_80095850@ha
    lbz	r5, 0x14(r30)
    addi	r4, r3, lbl_80095850@l
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    lbz	r0, 0x14(r30)
    cmplwi	r0, 0x1a
    bc      12, 1, _80089800
    lis     r3, -0x7fea
    slwi	r0, r0, 2
    addi	r3, r3, -0x4840
    lwzx	r0, r3, r0
    mtctr	r0
    bctr
    mr	r3, r30
    bl      fn_8008A6E4
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008A66C
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008A614
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008A5BC
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008A5B4
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008A5AC
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008A3C0
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008A1CC
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_80089EEC
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_80089C5C
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      TRK_serialIO_init
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      fn_8008998C
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      TRKDoVersions
    mr	r31, r3
    b       _80089800
    mr	r3, r30
    bl      TRKDoPing
    mr	r31, r3
_80089800:
    lis     r3, lbl_8009586C@ha
    mr	r5, r31
    addi	r4, r3, lbl_8009586C@l
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r0, 0x14(r1)
    mr	r3, r31
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void TRKInitializeDispatcher(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void TRKDoPing(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    lis     r4, gTRKOptionsBuffer@ha
    stw	r0, 0x54(r1)
    stw	r31, 0x4c(r1)
    addi	r31, r4, gTRKOptionsBuffer@l
    stw	r30, 0x48(r1)
    lbz	r0, 0x18(r3)
    lbz	r30, 0x1c(r3)
    cmplwi	r0, 1
    bc      4, 2, _80089894
    addi	r3, r31, 0
    bl      usr_puts
    cmplwi	r30, 0
    bc      12, 2, _80089884
    addi	r3, r31, 0x20
    bl      usr_puts
    b       _8008988c
_80089884:
    addi	r3, r31, 0x28
    bl      usr_puts
_8008988c:
    mr	r3, r30
    bl      fn_8008D7C0
_80089894:
    addi	r3, r1, 8
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0
    stb	r3, 0xc(r1)
    addi	r3, r1, 8
    li	r4, 0x40
    stw	r5, 8(r1)
    stb	r0, 0x10(r1)
    bl      TRKDoWrite
    lwz	r0, 0x54(r1)
    li	r3, 0
    lwz	r31, 0x4c(r1)
    lwz	r30, 0x48(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void TRKDoVersions(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stw	r31, 0x4c(r1)
    bl      fn_8008B484
    cmpwi	r3, 0x704
    bc      12, 2, _80089928
    bc      4, 0, _80089910
    cmpwi	r3, 0
    bc      12, 2, _80089920
    b       _80089940
_80089910:
    cmpwi	r3, 0x706
    bc      12, 2, _80089938
    bc      4, 0, _80089940
    b       _80089930
_80089920:
    li	r31, 0
    b       _80089944
_80089928:
    li	r31, 0x21
    b       _80089944
_80089930:
    li	r31, 0x22
    b       _80089944
_80089938:
    li	r31, 0x20
    b       _80089944
_80089940:
    li	r31, 1
_80089944:
    addi	r3, r1, 8
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r0, 0x40
    stb	r3, 0xc(r1)
    addi	r3, r1, 8
    li	r4, 0x40
    stw	r0, 8(r1)
    stb	r31, 0x10(r1)
    bl      TRKDoWrite
    lwz	r0, 0x54(r1)
    li	r3, 0
    lwz	r31, 0x4c(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_8008998C(void)
{
    nofralloc
    stwu	r1, -0x160(r1)
    mflr	r0
    li	r4, 0
    stw	r0, 0x164(r1)
    stmw	r27, 0x14c(r1)
    mr	r27, r3
    bl      TRKSetBufferPosition
    lbz	r31, 0x18(r27)
    lwz	r29, 0x20(r27)
    cmpwi	r31, 0x10
    lwz	r28, 0x24(r27)
    bc      12, 2, _800899e4
    bc      4, 0, _800899d8
    cmpwi	r31, 1
    bc      12, 2, _80089a2c
    bc      4, 0, _80089a7c
    cmpwi	r31, 0
    bc      4, 0, _800899e4
    b       _80089a7c
_800899d8:
    cmpwi	r31, 0x12
    bc      4, 0, _80089a7c
    b       _80089a2c
_800899e4:
    lbz	r30, 0x1c(r27)
    cmplwi	r30, 1
    bc      4, 0, _80089ab8
    addi	r3, r1, 0x108
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x11
    stb	r3, 0x10c(r1)
    addi	r3, r1, 0x108
    li	r4, 0x40
    stw	r5, 0x108(r1)
    stb	r0, 0x110(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _80089b98
_80089a2c:
    bl      fn_8008B6BC
    cmplw	r3, r29
    bc      12, 0, _80089a40
    cmplw	r3, r28
    bc      4, 1, _80089ab8
_80089a40:
    addi	r3, r1, 0xc8
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x11
    stb	r3, 0xcc(r1)
    addi	r3, r1, 0xc8
    li	r4, 0x40
    stw	r5, 0xc8(r1)
    stb	r0, 0xd0(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _80089b98
_80089a7c:
    addi	r3, r1, 0x88
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x12
    stb	r3, 0x8c(r1)
    addi	r3, r1, 0x88
    li	r4, 0x40
    stw	r5, 0x88(r1)
    stb	r0, 0x90(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _80089b98
_80089ab8:
    bl      TRKTargetStopped
    cmpwi	r3, 0
    bc      4, 2, _80089b00
    addi	r3, r1, 0x48
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x16
    stb	r3, 0x4c(r1)
    addi	r3, r1, 0x48
    li	r4, 0x40
    stw	r5, 0x48(r1)
    stb	r0, 0x50(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _80089b98
_80089b00:
    addi	r3, r1, 8
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0
    stb	r3, 0xc(r1)
    addi	r3, r1, 8
    li	r4, 0x40
    stw	r5, 8(r1)
    stb	r0, 0x10(r1)
    bl      TRKDoWrite
    cmpwi	r31, 0x10
    li	r3, 0
    bc      12, 2, _80089b68
    bc      4, 0, _80089b5c
    cmpwi	r31, 1
    bc      12, 2, _80089b80
    bc      4, 0, _80089b98
    cmpwi	r31, 0
    bc      4, 0, _80089b68
    b       _80089b98
_80089b5c:
    cmpwi	r31, 0x12
    bc      4, 0, _80089b98
    b       _80089b80
_80089b68:
    subfic	r0, r31, 0x10
    mr	r3, r30
    cntlzw	r0, r0
    srwi	r4, r0, 5
    bl      fn_8008B784
    b       _80089b98
_80089b80:
    subfic	r0, r31, 0x11
    mr	r3, r29
    cntlzw	r0, r0
    mr	r4, r28
    srwi	r5, r0, 5
    bl      TRKTargetCheckStep
_80089b98:
    lmw	r27, 0x14c(r1)
    lwz	r0, 0x164(r1)
    mtlr	r0
    addi	r1, r1, 0x160
    blr
}

asm void TRK_serialIO_init(void)
{
    nofralloc
    stwu	r1, -0x90(r1)
    mflr	r0
    lis     r4, lbl_800958C4@ha
    li	r3, 1
    stw	r0, 0x94(r1)
    addi	r4, r4, lbl_800958C4@l
    crxor	6, 6, 6
    bl      MWTRACE
    bl      TRKTargetStopped
    cmpwi	r3, 0
    bc      4, 2, _80089c14
    addi	r3, r1, 0x48
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x16
    stb	r3, 0x4c(r1)
    addi	r3, r1, 0x48
    li	r4, 0x40
    stw	r5, 0x48(r1)
    stb	r0, 0x50(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _80089c4c
_80089c14:
    addi	r3, r1, 8
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0
    stb	r3, 0xc(r1)
    addi	r3, r1, 8
    li	r4, 0x40
    stw	r5, 8(r1)
    stb	r0, 0x10(r1)
    bl      TRKDoWrite
    bl      TRKTargetContinue
_80089c4c:
    lwz	r0, 0x94(r1)
    mtlr	r0
    addi	r1, r1, 0x90
    blr
}

asm void fn_80089C5C(void)
{
    nofralloc
    stwu	r1, -0xe0(r1)
    mflr	r0
    li	r4, 0
    stw	r0, 0xe4(r1)
    stw	r31, 0xdc(r1)
    stw	r30, 0xd8(r1)
    stw	r29, 0xd4(r1)
    stw	r28, 0xd0(r1)
    mr	r28, r3
    lbz	r31, 0x18(r3)
    lhz	r30, 0x1c(r3)
    lhz	r29, 0x20(r3)
    bl      TRKSetBufferPosition
    cmplw	r30, r29
    bc      4, 1, _80089cd4
    addi	r3, r1, 0x4c
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x14
    stb	r3, 0x50(r1)
    addi	r3, r1, 0x4c
    li	r4, 0x40
    stw	r5, 0x4c(r1)
    stb	r0, 0x54(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _80089ecc
_80089cd4:
    mr	r3, r28
    li	r4, 0x40
    bl      TRKSetBufferPosition
    cmpwi	r31, 2
    bc      12, 2, _80089d48
    bc      4, 0, _80089cfc
    cmpwi	r31, 0
    bc      12, 2, _80089d08
    bc      4, 0, _80089d28
    b       _80089d88
_80089cfc:
    cmpwi	r31, 4
    bc      4, 0, _80089d88
    b       _80089d68
_80089d08:
    mr	r3, r30
    mr	r4, r29
    mr	r5, r28
    addi	r6, r1, 8
    li	r7, 0
    bl      TRKTargetAccessDefault
    mr	r31, r3
    b       _80089d8c
_80089d28:
    mr	r3, r30
    mr	r4, r29
    mr	r5, r28
    addi	r6, r1, 8
    li	r7, 0
    bl      TRKTargetAccessExtended2
    mr	r31, r3
    b       _80089d8c
_80089d48:
    mr	r3, r30
    mr	r4, r29
    mr	r5, r28
    addi	r6, r1, 8
    li	r7, 0
    bl      TRKTargetAccessExtended1
    mr	r31, r3
    b       _80089d8c
_80089d68:
    mr	r3, r30
    mr	r4, r29
    mr	r5, r28
    addi	r6, r1, 8
    li	r7, 0
    bl      TRKTargetAccessFP
    mr	r31, r3
    b       _80089d8c
_80089d88:
    li	r31, 0x703
_80089d8c:
    mr	r3, r28
    li	r4, 0
    bl      TRKMessageIntoReply
    cmpwi	r31, 0
    bc      4, 2, _80089dd8
    addi	r3, r1, 0x8c
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x40
    li	r0, 0x80
    stw	r3, 0x8c(r1)
    mr	r3, r28
    addi	r4, r1, 0x8c
    li	r5, 0x40
    stb	r0, 0x90(r1)
    stb	r31, 0x94(r1)
    bl      TRKAppendBuffer1_ui16
    mr	r31, r3
_80089dd8:
    cmpwi	r31, 0
    bc      12, 2, _80089e90
    cmpwi	r31, 0x703
    bc      12, 2, _80089e1c
    bc      4, 0, _80089e04
    cmpwi	r31, 0x701
    bc      12, 2, _80089e24
    bc      4, 0, _80089e34
    cmpwi	r31, 0x302
    bc      12, 2, _80089e2c
    b       _80089e54
_80089e04:
    cmpwi	r31, 0x706
    bc      12, 2, _80089e4c
    bc      4, 0, _80089e54
    cmpwi	r31, 0x705
    bc      4, 0, _80089e44
    b       _80089e3c
_80089e1c:
    li	r31, 0x12
    b       _80089e58
_80089e24:
    li	r31, 0x14
    b       _80089e58
_80089e2c:
    li	r31, 2
    b       _80089e58
_80089e34:
    li	r31, 0x15
    b       _80089e58
_80089e3c:
    li	r31, 0x21
    b       _80089e58
_80089e44:
    li	r31, 0x22
    b       _80089e58
_80089e4c:
    li	r31, 0x20
    b       _80089e58
_80089e54:
    li	r31, 3
_80089e58:
    addi	r3, r1, 0xc
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r0, 0x40
    stb	r3, 0x10(r1)
    addi	r3, r1, 0xc
    li	r4, 0x40
    stw	r0, 0xc(r1)
    stb	r31, 0x14(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _80089ecc
_80089e90:
    lis     r4, lbl_800958F0@ha
    li	r3, 1
    addi	r4, r4, lbl_800958F0@l
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r28
    bl      TRKMessageSend
    mr	r31, r3
    lis     r4, lbl_80095910@ha
    li	r3, 1
    addi	r4, r4, lbl_80095910@l
    mr	r5, r31
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r31
_80089ecc:
    lwz	r0, 0xe4(r1)
    lwz	r31, 0xdc(r1)
    lwz	r30, 0xd8(r1)
    lwz	r29, 0xd4(r1)
    lwz	r28, 0xd0(r1)
    mtlr	r0
    addi	r1, r1, 0xe0
    blr
}

asm void fn_80089EEC(void)
{
    nofralloc
    stwu	r1, -0xe0(r1)
    mflr	r0
    lis     r5, gTRKOptionsBuffer@ha
    stw	r0, 0xe4(r1)
    stw	r31, 0xdc(r1)
    addi	r31, r5, gTRKOptionsBuffer@l
    stw	r30, 0xd8(r1)
    stw	r29, 0xd4(r1)
    mr	r29, r3
    lhz	r4, 0x1c(r3)
    lhz	r0, 0x20(r3)
    cmplw	r4, r0
    bc      4, 1, _80089f5c
    addi	r3, r1, 0x4c
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x14
    stb	r3, 0x50(r1)
    addi	r3, r1, 0x4c
    li	r4, 0x40
    stw	r5, 0x4c(r1)
    stb	r0, 0x54(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _8008a1b0
_80089f5c:
    li	r4, 0x80
    li	r0, 0x468
    stb	r4, 0x90(r1)
    li	r4, 0
    stw	r0, 0x8c(r1)
    bl      TRKMessageIntoReply
    lwz	r5, 8(r29)
    addi	r4, r31, 0x98
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r29
    addi	r4, r1, 0x8c
    li	r5, 0x40
    bl      TRKAppendBuffer
    lwz	r5, 8(r29)
    addi	r4, r31, 0x98
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r5, r29
    addi	r6, r1, 8
    li	r3, 0
    li	r4, 0x24
    li	r7, 1
    bl      TRKTargetAccessDefault
    mr	r30, r3
    addi	r4, r31, 0xc0
    li	r3, 4
    mr	r5, r30
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r5, 8(r29)
    addi	r4, r31, 0x98
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    cmpwi	r30, 0
    bc      4, 2, _8008a014
    mr	r5, r29
    addi	r6, r1, 8
    li	r3, 0
    li	r4, 0x21
    li	r7, 1
    bl      TRKTargetAccessExtended2
    mr	r30, r3
_8008a014:
    mr	r5, r30
    addi	r4, r31, 0xf8
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r5, 8(r29)
    addi	r4, r31, 0x98
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    cmpwi	r30, 0
    bc      4, 2, _8008a060
    mr	r5, r29
    addi	r6, r1, 8
    li	r3, 0
    li	r4, 0x60
    li	r7, 1
    bl      TRKTargetAccessExtended1
    mr	r30, r3
_8008a060:
    mr	r5, r30
    addi	r4, r31, 0x120
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r5, 8(r29)
    addi	r4, r31, 0x98
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    cmpwi	r30, 0
    bc      4, 2, _8008a0ac
    mr	r5, r29
    addi	r6, r1, 8
    li	r3, 0
    li	r4, 0x1f
    li	r7, 1
    bl      TRKTargetAccessFP
    mr	r30, r3
_8008a0ac:
    mr	r5, r30
    addi	r4, r31, 0x150
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    lwz	r5, 8(r29)
    addi	r4, r31, 0x98
    li	r3, 4
    crxor	6, 6, 6
    bl      MWTRACE
    cmpwi	r30, 0
    bc      12, 2, _8008a17c
    cmpwi	r30, 0x704
    bc      12, 2, _8008a128
    bc      4, 0, _8008a100
    cmpwi	r30, 0x702
    bc      12, 2, _8008a120
    bc      4, 0, _8008a110
    cmpwi	r30, 0x701
    bc      4, 0, _8008a118
    b       _8008a140
_8008a100:
    cmpwi	r30, 0x706
    bc      12, 2, _8008a138
    bc      4, 0, _8008a140
    b       _8008a130
_8008a110:
    li	r30, 0x12
    b       _8008a144
_8008a118:
    li	r30, 0x14
    b       _8008a144
_8008a120:
    li	r30, 0x15
    b       _8008a144
_8008a128:
    li	r30, 0x21
    b       _8008a144
_8008a130:
    li	r30, 0x22
    b       _8008a144
_8008a138:
    li	r30, 0x20
    b       _8008a144
_8008a140:
    li	r30, 3
_8008a144:
    addi	r3, r1, 0xc
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r0, 0x40
    stb	r3, 0x10(r1)
    addi	r3, r1, 0xc
    li	r4, 0x40
    stw	r0, 0xc(r1)
    stb	r30, 0x14(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _8008a1b0
_8008a17c:
    addi	r4, r31, 0x60
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r29
    bl      TRKMessageSend
    addi	r4, r31, 0x80
    mr	r31, r3
    li	r3, 1
    mr	r5, r31
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r31
_8008a1b0:
    lwz	r0, 0xe4(r1)
    lwz	r31, 0xdc(r1)
    lwz	r30, 0xd8(r1)
    lwz	r29, 0xd4(r1)
    mtlr	r0
    addi	r1, r1, 0xe0
    blr
}

asm void fn_8008A1CC(void)
{
    nofralloc
    stwu	r1, -0x8f0(r1)
    mflr	r0
    stw	r0, 0x8f4(r1)
    stmw	r27, 0x8dc(r1)
    mr	r27, r3
    lis     r3, gTRKOptionsBuffer@ha
    addi	r31, r3, gTRKOptionsBuffer@l
    addi	r4, r31, 0x180
    li	r3, 1
    lwz	r28, 0x20(r27)
    lhz	r29, 0x1c(r27)
    lbz	r30, 0x18(r27)
    mr	r6, r28
    lbz	r5, 0x14(r27)
    mr	r7, r29
    mr	r8, r30
    crxor	6, 6, 6
    bl      MWTRACE
    rlwinm.	r0, r30, 0, 0x1e, 0x1e
    bc      12, 2, _8008a258
    addi	r3, r1, 0x4c
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x12
    stb	r3, 0x50(r1)
    addi	r3, r1, 0x4c
    li	r4, 0x40
    stw	r5, 0x4c(r1)
    stb	r0, 0x54(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _8008a3ac
_8008a258:
    stw	r29, 8(r1)
    mr	r3, r27
    li	r4, 0x40
    bl      TRKSetBufferPosition
    lwz	r5, 8(r1)
    mr	r3, r27
    addi	r4, r1, 0xcc
    bl      TRKAppendBuffer1_ui32
    rlwinm	r0, r30, 0x1d, 0x1f, 0x1f
    mr	r4, r28
    addi	r3, r1, 0xcc
    addi	r5, r1, 8
    xori	r6, r0, 1
    li	r7, 0
    bl      TRKTargetAccessMemory
    mr	r0, r3
    mr	r3, r27
    mr	r30, r0
    li	r4, 0
    bl      TRKMessageIntoReply
    cmpwi	r30, 0
    bc      4, 2, _8008a2e8
    addi	r3, r1, 0x8c
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x40
    li	r0, 0x80
    stw	r3, 0x8c(r1)
    mr	r3, r27
    addi	r4, r1, 0x8c
    li	r5, 0x40
    stb	r0, 0x90(r1)
    stb	r30, 0x94(r1)
    bl      TRKAppendBuffer1_ui16
    mr	r30, r3
_8008a2e8:
    cmpwi	r30, 0
    bc      12, 2, _8008a378
    addi	r0, r30, -0x700
    cmplwi	r0, 6
    bc      12, 1, _8008a33c
    lis     r3, -0x7fea
    slwi	r0, r0, 2
    addi	r3, r3, -0x47d0
    lwzx	r0, r3, r0
    mtctr	r0
    bctr
    li	r30, 0x15
    b       _8008a340
    li	r30, 0x13
    b       _8008a340
    li	r30, 0x21
    b       _8008a340
    li	r30, 0x22
    b       _8008a340
    li	r30, 0x20
    b       _8008a340
_8008a33c:
    li	r30, 3
_8008a340:
    addi	r3, r1, 0xc
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r0, 0x40
    stb	r3, 0x10(r1)
    addi	r3, r1, 0xc
    li	r4, 0x40
    stw	r0, 0xc(r1)
    stb	r30, 0x14(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _8008a3ac
_8008a378:
    addi	r4, r31, 0x60
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r27
    bl      TRKMessageSend
    addi	r4, r31, 0x80
    mr	r31, r3
    li	r3, 1
    mr	r5, r31
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r31
_8008a3ac:
    lmw	r27, 0x8dc(r1)
    lwz	r0, 0x8f4(r1)
    mtlr	r0
    addi	r1, r1, 0x8f0
    blr
}

asm void fn_8008A3C0(void)
{
    nofralloc
    stwu	r1, -0x8f0(r1)
    mflr	r0
    stw	r0, 0x8f4(r1)
    stmw	r27, 0x8dc(r1)
    mr	r27, r3
    lis     r3, gTRKOptionsBuffer@ha
    addi	r31, r3, gTRKOptionsBuffer@l
    addi	r4, r31, 0x1b0
    li	r3, 1
    lwz	r28, 0x20(r27)
    lhz	r29, 0x1c(r27)
    lbz	r30, 0x18(r27)
    mr	r6, r28
    lbz	r5, 0x14(r27)
    mr	r7, r29
    mr	r8, r30
    crxor	6, 6, 6
    bl      MWTRACE
    rlwinm.	r0, r30, 0, 0x1e, 0x1e
    bc      12, 2, _8008a44c
    addi	r3, r1, 0x4c
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0x12
    stb	r3, 0x50(r1)
    addi	r3, r1, 0x4c
    li	r4, 0x40
    stw	r5, 0x4c(r1)
    stb	r0, 0x54(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _8008a598
_8008a44c:
    rlwinm	r0, r30, 0x1d, 0x1f, 0x1f
    stw	r29, 8(r1)
    mr	r4, r28
    addi	r3, r1, 0xcc
    addi	r5, r1, 8
    xori	r6, r0, 1
    li	r7, 1
    bl      TRKTargetAccessMemory
    mr	r0, r3
    mr	r3, r27
    mr	r30, r0
    li	r4, 0
    bl      TRKMessageIntoReply
    cmpwi	r30, 0
    bc      4, 2, _8008a4d4
    addi	r3, r1, 0x8c
    li	r4, 0
    li	r5, 0x40
    bl      memset
    lwz	r4, 8(r1)
    li	r0, 0x80
    stb	r30, 0x94(r1)
    mr	r3, r27
    addi	r4, r4, 0x40
    li	r5, 0x40
    stw	r4, 0x8c(r1)
    addi	r4, r1, 0x8c
    stb	r0, 0x90(r1)
    bl      TRKAppendBuffer1_ui16
    lwz	r5, 8(r1)
    mr	r3, r27
    addi	r4, r1, 0xcc
    bl      TRKAppendBuffer1_ui16
    mr	r30, r3
_8008a4d4:
    cmpwi	r30, 0
    bc      12, 2, _8008a564
    addi	r0, r30, -0x700
    cmplwi	r0, 6
    bc      12, 1, _8008a528
    lis     r3, -0x7fea
    slwi	r0, r0, 2
    addi	r3, r3, -0x47b4
    lwzx	r0, r3, r0
    mtctr	r0
    bctr
    li	r30, 0x15
    b       _8008a52c
    li	r30, 0x13
    b       _8008a52c
    li	r30, 0x21
    b       _8008a52c
    li	r30, 0x22
    b       _8008a52c
    li	r30, 0x20
    b       _8008a52c
_8008a528:
    li	r30, 3
_8008a52c:
    addi	r3, r1, 0xc
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0x80
    li	r0, 0x40
    stb	r3, 0x10(r1)
    addi	r3, r1, 0xc
    li	r4, 0x40
    stw	r0, 0xc(r1)
    stb	r30, 0x14(r1)
    bl      TRKDoWrite
    li	r3, 0
    b       _8008a598
_8008a564:
    addi	r4, r31, 0x60
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r27
    bl      TRKMessageSend
    addi	r4, r31, 0x80
    mr	r31, r3
    li	r3, 1
    mr	r5, r31
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r31
_8008a598:
    lmw	r27, 0x8dc(r1)
    lwz	r0, 0x8f4(r1)
    mtlr	r0
    addi	r1, r1, 0x8f0
    blr
}

asm void fn_8008A5AC(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void fn_8008A5B4(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void fn_8008A5BC(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    li	r4, 0
    li	r5, 0x40
    stw	r0, 0x54(r1)
    addi	r3, r1, 8
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0
    stb	r3, 0xc(r1)
    addi	r3, r1, 8
    li	r4, 0x40
    stw	r5, 8(r1)
    stb	r0, 0x10(r1)
    bl      TRKDoWrite
    bl      TRKTargetTranslate
    lwz	r0, 0x54(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_8008A614(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    li	r4, 0
    li	r5, 0x40
    stw	r0, 0x54(r1)
    addi	r3, r1, 8
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0
    stb	r3, 0xc(r1)
    addi	r3, r1, 8
    li	r4, 0x40
    stw	r5, 8(r1)
    stb	r0, 0x10(r1)
    bl      TRKDoWrite
    bl      fn_80005518
    lwz	r0, 0x54(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_8008A66C(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    lis     r3, gTRKInputPendingPtrStore@ha
    li	r5, 0x40
    stw	r0, 0x64(r1)
    addi	r4, r3, gTRKInputPendingPtrStore@l
    li	r0, 0
    addi	r3, r1, 0x14
    stw	r0, 0(r4)
    li	r4, 0
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0
    stb	r3, 0x18(r1)
    addi	r3, r1, 0x14
    li	r4, 0x40
    stw	r5, 0x14(r1)
    stb	r0, 0x1c(r1)
    bl      TRKDoWrite
    addi	r3, r1, 8
    li	r4, 1
    bl      TRKConstructEvent
    addi	r3, r1, 8
    bl      TRKPostEvent
    lwz	r0, 0x64(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x60
    blr
}

asm void fn_8008A6E4(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    lis     r3, gTRKInputPendingPtrStore@ha
    li	r5, 0x40
    stw	r0, 0x54(r1)
    addi	r4, r3, gTRKInputPendingPtrStore@l
    li	r0, 1
    addi	r3, r1, 8
    stw	r0, 0(r4)
    li	r4, 0
    bl      memset
    li	r3, 0x80
    li	r5, 0x40
    li	r0, 0
    stb	r3, 0xc(r1)
    addi	r3, r1, 8
    li	r4, 0x40
    stw	r5, 8(r1)
    stb	r0, 0x10(r1)
    bl      TRKDoWrite
    lwz	r0, 0x54(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_8008A748(void)
{
    nofralloc
    lis	r4, -0x7fe6
    stw	r3, 0x50b0(r4)
    blr
}

asm void fn_8008A754(void)
{
    nofralloc
    lis     r3, gTRKInputPendingPtrStore@ha
    addi	r3, r3, gTRKInputPendingPtrStore@l
    lwz	r3, 0(r3)
    blr
}

asm void fn_8008A764(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r6, x_str@ha
    lis     r5, lbl_80095A74@ha
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r27, r4
    mr	r31, r3
    addi	r29, r6, x_str@l
    addi	r30, r5, lbl_80095A74@l
    li	r28, 0
    b       _8008a7dc
_8008a794:
    lbz	r5, 0(r31)
    mr	r4, r29
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    slwi	r0, r28, 0x1c
    srwi	r3, r28, 0x1f
    subf	r0, r3, r0
    rotlwi	r0, r0, 4
    add	r0, r0, r3
    cmpwi	r0, 0xf
    bc      4, 2, _8008a7d4
    mr	r4, r30
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
_8008a7d4:
    addi	r28, r28, 1
    addi	r31, r31, 1
_8008a7dc:
    cmpw	r28, r27
    bc      12, 0, _8008a794
    lis     r4, lbl_80095A74@ha
    li	r3, 8
    addi	r4, r4, lbl_80095A74@l
    crxor	6, 6, 6
    bl      MWTRACE
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8008A80C(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    stw	r0, 0x74(r1)
    stw	r31, 0x6c(r1)
    mr	r31, r5
    li	r5, 0x40
    stw	r30, 0x68(r1)
    mr	r30, r6
    stw	r29, 0x64(r1)
    mr	r29, r4
    li	r4, 0
    stw	r28, 0x60(r1)
    mr	r28, r3
    addi	r3, r1, 0x14
    bl      memset
    li	r3, 0xd4
    li	r0, 0x40
    stb	r3, 0x18(r1)
    addi	r3, r1, 0xc
    addi	r4, r1, 8
    stw	r0, 0x14(r1)
    stw	r28, 0x1c(r1)
    lwz	r0, 0(r29)
    stw	r0, 0x20(r1)
    stb	r31, 0x24(r1)
    bl      TRKGetFreeBuffer
    or.	r31, r3, r3
    bc      4, 2, _8008a890
    lwz	r3, 8(r1)
    addi	r4, r1, 0x14
    li	r5, 0x40
    bl      TRKAppendBuffer
    mr	r31, r3
_8008a890:
    cmpwi	r31, 0
    bc      4, 2, _8008a8f0
    li	r3, 0
    li	r0, -1
    stw	r3, 0(r30)
    addi	r4, r1, 0x10
    li	r5, 3
    li	r6, 3
    stw	r0, 0(r29)
    li	r7, 0
    lwz	r3, 8(r1)
    bl      TRKRequestSend
    or.	r31, r3, r3
    bc      4, 2, _8008a8e8
    lwz	r3, 0x10(r1)
    bl      TRKGetBuffer
    cmplwi	r3, 0
    bc      12, 2, _8008a8e8
    lwz	r0, 0x20(r3)
    stw	r0, 0(r30)
    lwz	r0, 0x28(r3)
    stw	r0, 0(r29)
_8008a8e8:
    lwz	r3, 0x10(r1)
    bl      TRKReleaseBuffer
_8008a8f0:
    lwz	r3, 0xc(r1)
    bl      TRKReleaseBuffer
    lwz	r0, 0x74(r1)
    mr	r3, r31
    lwz	r31, 0x6c(r1)
    lwz	r30, 0x68(r1)
    lwz	r29, 0x64(r1)
    lwz	r28, 0x60(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr
}

asm void fn_8008A91C(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    li	r5, 0x40
    stw	r0, 0x74(r1)
    stw	r31, 0x6c(r1)
    mr	r31, r3
    addi	r3, r1, 0x14
    stw	r30, 0x68(r1)
    stw	r29, 0x64(r1)
    mr	r29, r4
    li	r4, 0
    bl      memset
    li	r3, 0xd3
    li	r0, 0x40
    stb	r3, 0x18(r1)
    addi	r3, r1, 0xc
    addi	r4, r1, 8
    stw	r0, 0x14(r1)
    stw	r31, 0x1c(r1)
    bl      TRKGetFreeBuffer
    or.	r31, r3, r3
    bc      4, 2, _8008a988
    lwz	r3, 8(r1)
    addi	r4, r1, 0x14
    li	r5, 0x40
    bl      TRKAppendBuffer
    mr	r31, r3
_8008a988:
    cmpwi	r31, 0
    bc      4, 2, _8008a9dc
    li	r0, 0
    addi	r4, r1, 0x10
    stw	r0, 0(r29)
    li	r5, 3
    li	r6, 3
    li	r7, 0
    lwz	r3, 8(r1)
    bl      TRKRequestSend
    or.	r31, r3, r3
    bc      4, 2, _8008a9c4
    lwz	r3, 0x10(r1)
    bl      TRKGetBuffer
    mr	r30, r3
_8008a9c4:
    cmpwi	r31, 0
    bc      4, 2, _8008a9d4
    lwz	r0, 0x20(r30)
    stw	r0, 0(r29)
_8008a9d4:
    lwz	r3, 0x10(r1)
    bl      TRKReleaseBuffer
_8008a9dc:
    lwz	r3, 0xc(r1)
    bl      TRKReleaseBuffer
    lwz	r0, 0x74(r1)
    mr	r3, r31
    lwz	r31, 0x6c(r1)
    lwz	r30, 0x68(r1)
    lwz	r29, 0x64(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr
}

asm void fn_8008AA04(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    stw	r0, 0x74(r1)
    stmw	r27, 0x5c(r1)
    mr	r27, r3
    mr	r31, r4
    mr	r28, r5
    mr	r29, r6
    addi	r3, r1, 0x14
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r3, 0
    li	r0, 0xd2
    stw	r3, 0(r28)
    mr	r3, r27
    stb	r0, 0x18(r1)
    bl      strlen
    addi	r0, r3, 0x41
    stb	r31, 0x1c(r1)
    mr	r3, r27
    stw	r0, 0x14(r1)
    bl      strlen
    addi	r0, r3, 1
    addi	r3, r1, 0xc
    sth	r0, 0x20(r1)
    addi	r4, r1, 8
    bl      TRKGetFreeBuffer
    lwz	r3, 8(r1)
    addi	r4, r1, 0x14
    li	r5, 0x40
    bl      TRKAppendBuffer
    or.	r31, r3, r3
    bc      4, 2, _8008aaac
    mr	r3, r27
    bl      strlen
    mr	r5, r3
    lwz	r3, 8(r1)
    mr	r4, r27
    addi	r5, r5, 1
    bl      TRKAppendBuffer
    mr	r31, r3
_8008aaac:
    cmpwi	r31, 0
    bc      4, 2, _8008ab00
    li	r0, 0
    addi	r4, r1, 0x10
    stw	r0, 0(r29)
    li	r5, 7
    li	r6, 3
    li	r7, 0
    lwz	r3, 8(r1)
    bl      TRKRequestSend
    or.	r31, r3, r3
    bc      4, 2, _8008aae8
    lwz	r3, 0x10(r1)
    bl      TRKGetBuffer
    mr	r30, r3
_8008aae8:
    lwz	r0, 0x20(r30)
    stw	r0, 0(r29)
    lwz	r0, 0x18(r30)
    stw	r0, 0(r28)
    lwz	r3, 0x10(r1)
    bl      TRKReleaseBuffer
_8008ab00:
    lwz	r3, 0xc(r1)
    bl      TRKReleaseBuffer
    mr	r3, r31
    lmw	r27, 0x5c(r1)
    lwz	r0, 0x74(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr
}

asm void TRKRequestSend(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    li	r0, -1
    stmw	r21, 0x14(r1)
    mr	r22, r4
    lis     r4, lbl_80095A78@ha
    mr	r21, r3
    mr	r23, r7
    addi	r27, r6, 1
    addi	r31, r4, lbl_80095A78@l
    li	r30, 0
    li	r24, 1
    stw	r0, 0(r22)
    b       _8008acbc
_8008ab5c:
    addi	r4, r31, 0
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r21
    bl      TRKMessageSend
    or.	r30, r3, r3
    bc      4, 2, _8008acb8
    cmpwi	r23, 0
    bc      12, 2, _8008ab88
    li	r28, 0
_8008ab88:
    bl      TRKTestForPacket
    stw	r3, 0(r22)
    lwz	r3, 0(r22)
    cmpwi	r3, -1
    bc      4, 2, _8008abb8
    cmpwi	r23, 0
    bc      12, 2, _8008ab88
    lis	r4, 0x4c5
    addi	r28, r28, 1
    addi	r0, r4, -0x4c14
    cmplw	r28, r0
    bc      12, 0, _8008ab88
_8008abb8:
    cmpwi	r3, -1
    bc      12, 2, _8008ac18
    li	r24, 0
    bl      TRKGetBuffer
    li	r4, 0
    mr	r29, r3
    bl      TRKSetBufferPosition
    lwz	r4, 8(r29)
    addi	r3, r29, 0x10
    bl      fn_8008A764
    lbz	r26, 0x14(r29)
    addi	r4, r31, 0x18
    li	r3, 1
    mr	r5, r26
    mr	r6, r26
    crxor	6, 6, 6
    bl      MWTRACE
    cmplwi	r26, 0x80
    bc      4, 0, _8008ac18
    lwz	r3, 0(r22)
    bl      TRKProcessInput
    li	r0, -1
    stw	r0, 0(r22)
    b       _8008ab88
_8008ac18:
    lwz	r0, 0(r22)
    cmpwi	r0, -1
    bc      12, 2, _8008acb8
    lwz	r0, 8(r29)
    cmplwi	r0, 0x40
    bc      4, 0, _8008ac34
    li	r24, 1
_8008ac34:
    cmpwi	r30, 0
    bc      4, 2, _8008ac5c
    cmpwi	r24, 0
    bc      4, 2, _8008ac5c
    lbz	r25, 0x18(r29)
    addi	r4, r31, 0x40
    li	r3, 1
    mr	r5, r25
    crxor	6, 6, 6
    bl      MWTRACE
_8008ac5c:
    cmpwi	r30, 0
    bc      4, 2, _8008ac98
    cmpwi	r24, 0
    bc      4, 2, _8008ac98
    cmpwi	r26, 0x80
    mr	r5, r26
    bc      4, 2, _8008ac80
    cmpwi	r25, 0
    bc      12, 2, _8008ac98
_8008ac80:
    mr	r6, r25
    addi	r4, r31, 0x54
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    li	r24, 1
_8008ac98:
    cmpwi	r30, 0
    bc      4, 2, _8008aca8
    cmpwi	r24, 0
    bc      12, 2, _8008acb8
_8008aca8:
    lwz	r3, 0(r22)
    bl      TRKReleaseBuffer
    li	r0, -1
    stw	r0, 0(r22)
_8008acb8:
    addi	r27, r27, -1
_8008acbc:
    cmpwi	r27, 0
    bc      12, 2, _8008acd8
    lwz	r0, 0(r22)
    cmpwi	r0, -1
    bc      4, 2, _8008acd8
    cmpwi	r30, 0
    bc      12, 2, _8008ab5c
_8008acd8:
    lwz	r0, 0(r22)
    cmpwi	r0, -1
    bc      4, 2, _8008ace8
    li	r30, 0x800
_8008ace8:
    mr	r3, r30
    lmw	r21, 0x14(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr
}

asm void TRKSuppAccessFile(void)
{
    nofralloc
    stwu	r1, -0x90(r1)
    mflr	r0
    stw	r0, 0x94(r1)
    stmw	r19, 0x5c(r1)
    or.	r24, r4, r4
    mr	r23, r3
    mr	r25, r5
    mr	r26, r6
    mr	r27, r7
    mr	r28, r8
    bc      12, 2, _8008ad38
    lwz	r0, 0(r25)
    cmplwi	r0, 0
    bc      4, 2, _8008ad40
_8008ad38:
    li	r3, 2
    b       _8008af2c
_8008ad40:
    li	r0, 0
    li	r29, 0
    stw	r0, 0(r26)
    li	r30, 0
    li	r21, 0
    b       _8008aefc
_8008ad58:
    addi	r3, r1, 0x14
    li	r4, 0
    li	r5, 0x40
    bl      memset
    lwz	r0, 0(r25)
    li	r3, 0x800
    subf	r0, r30, r0
    cmplwi	r0, 0x800
    bc      12, 1, _8008ad80
    mr	r3, r0
_8008ad80:
    cmpwi	r28, 0
    mr	r31, r3
    li	r0, 0xd0
    bc      12, 2, _8008ad94
    li	r0, 0xd1
_8008ad94:
    cmpwi	r28, 0
    stb	r0, 0x18(r1)
    li	r0, 0x40
    bc      4, 2, _8008ada8
    addi	r0, r31, 0x40
_8008ada8:
    stw	r0, 0x14(r1)
    addi	r3, r1, 0xc
    addi	r4, r1, 8
    stw	r23, 0x1c(r1)
    sth	r31, 0x20(r1)
    bl      TRKGetFreeBuffer
    lwz	r3, 8(r1)
    addi	r4, r1, 0x14
    li	r5, 0x40
    bl      TRKAppendBuffer
    cmpwi	r28, 0
    mr	r21, r3
    bc      4, 2, _8008adf8
    cmpwi	r21, 0
    bc      4, 2, _8008adf8
    lwz	r3, 8(r1)
    mr	r5, r31
    add	r4, r24, r30
    bl      TRKAppendBuffer
    mr	r21, r3
_8008adf8:
    cmpwi	r21, 0
    bc      4, 2, _8008aef0
    cmpwi	r27, 0
    bc      12, 2, _8008aee4
    cmpwi	r28, 0
    li	r0, 0
    bc      12, 2, _8008ae20
    cmplwi	r23, 0
    bc      4, 2, _8008ae20
    li	r0, 1
_8008ae20:
    cmpwi	r28, 0
    lwz	r3, 8(r1)
    addi	r4, r1, 0x10
    li	r5, 5
    cntlzw	r0, r0
    li	r6, 3
    srwi	r7, r0, 5
    bl      TRKRequestSend
    or.	r21, r3, r3
    bc      4, 2, _8008ae54
    lwz	r3, 0x10(r1)
    bl      TRKGetBuffer
    mr	r22, r3
_8008ae54:
    lwz	r0, 0x20(r22)
    cmpwi	r28, 0
    lhz	r19, 0x24(r22)
    clrlwi	r20, r0, 0x18
    bc      12, 2, _8008aea4
    cmpwi	r21, 0
    bc      4, 2, _8008aea4
    cmplw	r19, r31
    bc      12, 1, _8008aea4
    mr	r3, r22
    li	r4, 0x40
    bl      TRKSetBufferPosition
    mr	r3, r22
    mr	r5, r19
    add	r4, r24, r30
    bl      TRKReadBuffer
    mr	r21, r3
    cmpwi	r21, 0x302
    bc      4, 2, _8008aea4
    li	r21, 0
_8008aea4:
    cmplw	r19, r31
    bc      12, 2, _8008aed0
    cmpwi	r28, 0
    bc      12, 2, _8008aebc
    cmplw	r19, r31
    bc      12, 0, _8008aec8
_8008aebc:
    cmplwi	r20, 0
    bc      4, 2, _8008aec8
    li	r20, 1
_8008aec8:
    mr	r31, r19
    li	r29, 1
_8008aed0:
    clrlwi	r0, r20, 0x18
    stw	r0, 0(r26)
    lwz	r3, 0x10(r1)
    bl      TRKReleaseBuffer
    b       _8008aef0
_8008aee4:
    lwz	r3, 8(r1)
    bl      TRKMessageSend
    mr	r21, r3
_8008aef0:
    lwz	r3, 0xc(r1)
    bl      TRKReleaseBuffer
    add	r30, r30, r31
_8008aefc:
    cmpwi	r29, 0
    bc      4, 2, _8008af24
    lwz	r0, 0(r25)
    cmplw	r30, r0
    bc      4, 0, _8008af24
    cmpwi	r21, 0
    bc      4, 2, _8008af24
    lwz	r0, 0(r26)
    cmpwi	r0, 0
    bc      12, 2, _8008ad58
_8008af24:
    stw	r30, 0(r25)
    mr	r3, r21
_8008af2c:
    lmw	r19, 0x5c(r1)
    lwz	r0, 0x94(r1)
    mtlr	r0
    addi	r1, r1, 0x90
    blr
}

asm void fn_8008AF40(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void fn_8008AF48(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void fn_8008AF50(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void TRKDoNotifyStopped(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r4, r1, 8
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r3
    addi	r3, r1, 0xc
    bl      TRKGetFreeBuffer
    or.	r31, r3, r3
    bc      4, 2, _8008afd4
    bc      4, 2, _8008afa4
    cmpwi	r30, 0x90
    bc      4, 2, _8008af9c
    lwz	r3, 8(r1)
    bl      fn_8008B8B4
    b       _8008afa4
_8008af9c:
    lwz	r3, 8(r1)
    bl      fn_8008B830
_8008afa4:
    lwz	r3, 8(r1)
    addi	r4, r1, 0x10
    li	r5, 2
    li	r6, 3
    li	r7, 1
    bl      TRKRequestSend
    or.	r31, r3, r3
    bc      4, 2, _8008afcc
    lwz	r3, 0x10(r1)
    bl      TRKReleaseBuffer
_8008afcc:
    lwz	r3, 0xc(r1)
    bl      TRKReleaseBuffer
_8008afd4:
    lwz	r0, 0x24(r1)
    mr	r3, r31
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8008AFF0(void)
{
    nofralloc
    lis	r5, -1
    ori	r5, r5, 0xfff1
    and	r5, r5, r3
    subf	r3, r5, r3
    add	r4, r4, r3
_8008b004:
    dcbst	0, r5
    dcbf	0, r5
    sync	
    icbi	0, r5
    addic	r5, r5, 8
    addic.	r4, r4, -8
    bc      4, 0, _8008b004
    isync	
    blr
}

asm void fn_8008B028(void)
{
    nofralloc
    cmplwi	r5, 0x20
    clrlwi	r4, r4, 0x18
    addi	r6, r3, -1
    mr	r7, r4
    bc      12, 0, _8008b0c8
    nor	r0, r6, r6
    clrlwi.	r3, r0, 0x1e
    bc      12, 2, _8008b058
    subf	r5, r3, r5
_8008b04c:
    addic.	r3, r3, -1
    stbu	r7, 1(r6)
    bc      4, 2, _8008b04c
_8008b058:
    cmplwi	r7, 0
    bc      12, 2, _8008b078
    slwi	r3, r7, 0x18
    slwi	r0, r7, 0x10
    slwi	r4, r7, 8
    or	r0, r3, r0
    or	r0, r4, r0
    or	r7, r7, r0
_8008b078:
    rlwinm.	r4, r5, 0x1b, 5, 0x1f
    addi	r3, r6, -3
    bc      12, 2, _8008b0ac
_8008b084:
    stw	r7, 4(r3)
    addic.	r4, r4, -1
    stw	r7, 8(r3)
    stw	r7, 0xc(r3)
    stw	r7, 0x10(r3)
    stw	r7, 0x14(r3)
    stw	r7, 0x18(r3)
    stw	r7, 0x1c(r3)
    stwu	r7, 0x20(r3)
    bc      4, 2, _8008b084
_8008b0ac:
    rlwinm.	r4, r5, 0x1e, 0x1d, 0x1f
    bc      12, 2, _8008b0c0
_8008b0b4:
    addic.	r4, r4, -1
    stwu	r7, 4(r3)
    bc      4, 2, _8008b0b4
_8008b0c0:
    addi	r6, r3, 3
    clrlwi	r5, r5, 0x1e
_8008b0c8:
    cmplwi	r5, 0
    beqlr	
_8008b0d0:
    addic.	r5, r5, -1
    stbu	r7, 1(r6)
    bc      4, 2, _8008b0d0
    blr
}

asm void fn_8008B0E0(void)
{
    nofralloc
    mfmsr	r3
    blr
}

asm void fn_8008B0E8(void)
{
    nofralloc
    mtmsr	r3
    blr
}

asm void fn_8008B0F0(void)
{
    nofralloc
    mfmsr	r8
    li	r10, 0
_8008b0f8:
    cmpw	r10, r5
    bc      12, 2, _8008b120
    mtmsr	r7
    sync	
    lbzx	r9, r10, r4
    mtmsr	r6
    sync	
    stbx	r9, r10, r3
    addi	r10, r10, 1
    b       _8008b0f8
_8008b120:
    mtmsr	r8
    sync	
    blr
}

asm void TRKInterruptHandler(void)
{
    nofralloc
    mtspr   26, r2
    mtspr   27, r4
    mfspr   r4, 275
    mfcr	r2
    mtspr   275, r2
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50bc
    lwz	r2, 0x8c(r2)
    ori	r2, r2, 0x8002
    xori	r2, r2, 0x8002
    sync	
    mtmsr	r2
    sync	
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50b8
    sth	r3, 0(r2)
    cmpwi	r3, 0x500
    bc      4, 2, _8008b1f4
    lis	r2, -0x7fe6
    ori	r2, r2, 0x5160
    mflr	r3
    stw	r3, 0x42c(r2)
    bl      TRKUARTInterruptHandler
    lis	r2, -0x7fe6
    ori	r2, r2, 0x5160
    lwz	r3, 0x42c(r2)
    mtlr	r3
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50bc
    lwz	r2, 0xa0(r2)
    lbz	r2, 0(r2)
    cmpwi	r2, 0
    bc      12, 2, _8008b1d8
    lis	r2, -0x7feb
    ori	r2, r2, 0xb874
    lbz	r2, 0xc(r2)
    cmpwi	r2, 1
    bc      12, 2, _8008b1d8
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50bc
    li	r3, 1
    stb	r3, 0x9c(r2)
    b       _8008b1f4
_8008b1d8:
    lis	r2, -0x7fe6
    ori	r2, r2, 0x5590
    lwz	r3, 0x88(r2)
    mtcrf   255, r3
    lwz	r3, 0xc(r2)
    lwz	r2, 8(r2)
    rfi	
_8008b1f4:
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50b8
    lhz	r3, 0(r2)
    lis	r2, -0x7feb
    ori	r2, r2, 0xb874
    lbz	r2, 0xc(r2)
    cmpwi	r2, 0
    bc      4, 2, TRKExceptionHandler
    lis	r2, -0x7fe6
    ori	r2, r2, 0x5160
    stw	r0, 0(r2)
    stw	r1, 4(r2)
    mfspr   r0, 273
    stw	r0, 8(r2)
    sth	r3, 0x2f8(r2)
    sth	r3, 0x2fa(r2)
    mfspr   r0, 274
    stw	r0, 0xc(r2)
    stmw	r4, 0x10(r2)
    mfspr   r27, 26
    mflr	r28
    mfspr   r29, 275
    mfctr	r30
    mfxer	r31
    stmw	r27, 0x80(r2)
    bl      TRKSaveExtended1Block
    lis	r2, -0x7feb
    ori	r2, r2, 0xb874
    li	r3, 1
    stb	r3, 0xc(r2)
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50bc
    lwz	r0, 0x8c(r2)
    sync	
    mtmsr	r0
    sync	
    lwz	r0, 0x80(r2)
    mtlr	r0
    lwz	r0, 0x84(r2)
    mtctr	r0
    lwz	r0, 0x88(r2)
    mtxer	r0
    lwz	r0, 0x94(r2)
    mtspr   18, r0
    lwz	r0, 0x90(r2)
    mtspr   19, r0
    lmw	r3, 0xc(r2)
    lwz	r0, 0(r2)
    lwz	r1, 4(r2)
    lwz	r2, 8(r2)
    b       TRKPostInterruptEvent
}

asm void TRKExceptionHandler(void)
{
    nofralloc
    lis	r2, -0x7feb
    ori	r2, r2, 0xb874
    sth	r3, 8(r2)
    mfspr   r3, 26
    stw	r3, 0(r2)
    lhz	r3, 8(r2)
    cmpwi	r3, 0x200
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x300
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x400
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x600
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x700
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x800
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x1000
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x1100
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x1200
    bc      12, 2, _8008b32c
    cmpwi	r3, 0x1300
    bc      12, 2, _8008b32c
    b       _8008b338
_8008b32c:
    mfspr   r3, 26
    addi	r3, r3, 4
    mtspr   26, r3
_8008b338:
    lis	r2, -0x7feb
    ori	r2, r2, 0xb874
    li	r3, 1
    stb	r3, 0xd(r2)
    mfspr   r3, 275
    mtcrf   255, r3
    mfspr   r2, 273
    mfspr   r3, 274
    rfi	
}

asm void TRKSwapAndGo(void)
{
    nofralloc
    lis	r3, -0x7fe6
    ori	r3, r3, 0x50bc
    stmw	r0, 0(r3)
    mfmsr	r0
    stw	r0, 0x8c(r3)
    mflr	r0
    stw	r0, 0x80(r3)
    mfctr	r0
    stw	r0, 0x84(r3)
    mfxer	r0
    stw	r0, 0x88(r3)
    mfspr   r0, 18
    stw	r0, 0x94(r3)
    mfspr   r0, 19
    stw	r0, 0x90(r3)
    li	r1, -0x7ffe
    nor	r1, r1, r1
    mfmsr	r3
    and	r3, r3, r1
    mtmsr	r3
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50bc
    lwz	r2, 0xa0(r2)
    lbz	r2, 0(r2)
    cmpwi	r2, 0
    bc      12, 2, _8008b3d8
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50bc
    li	r3, 1
    stb	r3, 0x9c(r2)
    b       TRKInterruptHandlerEnableInterrupts
_8008b3d8:
    lis	r2, -0x7feb
    ori	r2, r2, 0xb874
    li	r3, 0
    stb	r3, 0xc(r2)
    bl      TRKRestoreExtended1Block
    lis	r2, -0x7fe6
    ori	r2, r2, 0x5160
    lmw	r27, 0x80(r2)
    mtspr   26, r27
    mtlr	r28
    mtcrf   255, r29
    mtctr	r30
    mtxer	r31
    lmw	r3, 0xc(r2)
    lwz	r0, 0(r2)
    lwz	r1, 4(r2)
    lwz	r2, 8(r2)
    rfi	
}

asm void TRKInterruptHandlerEnableInterrupts(void)
{
    nofralloc
    lis	r2, -0x7fe6
    ori	r2, r2, 0x50bc
    lwz	r0, 0x8c(r2)
    sync	
    mtmsr	r0
    sync	
    lwz	r0, 0x80(r2)
    mtlr	r0
    lwz	r0, 0x84(r2)
    mtctr	r0
    lwz	r0, 0x88(r2)
    mtxer	r0
    lwz	r0, 0x94(r2)
    mtspr   18, r0
    lwz	r0, 0x90(r2)
    mtspr   19, r0
    lmw	r3, 0xc(r2)
    lwz	r0, 0(r2)
    lwz	r1, 4(r2)
    lwz	r2, 8(r2)
    b       TRKPostInterruptEvent
}

asm void TRKTargetSetInputPendingPtr(void)
{
    nofralloc
    lis     r4, gTRKState@ha
    addi	r4, r4, gTRKState@l
    stw	r3, 0xa0(r4)
    blr
}

asm void fn_8008B484(void)
{
    nofralloc
    lis     r3, gTRKState@ha
    li	r0, 1
    addi	r4, r3, gTRKState@l
    li	r3, 0
    stw	r0, 0x98(r4)
    blr
}

asm void TRKTargetSetStopped(void)
{
    nofralloc
    lis     r4, gTRKState@ha
    addi	r4, r4, gTRKState@l
    stw	r3, 0x98(r4)
    blr
}

asm void TRKTargetStopped(void)
{
    nofralloc
    lis     r3, gTRKState@ha
    addi	r3, r3, gTRKState@l
    lwz	r3, 0x98(r3)
    blr
}

asm void TRKTargetSupportRequest(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    lis     r3, gTRKCPUState@ha
    stw	r0, 0x44(r1)
    stmw	r27, 0x2c(r1)
    addi	r31, r3, gTRKCPUState@l
    lwz	r27, 0xc(r31)
    cmpwi	r27, 0xd1
    bc      12, 2, _8008b51c
    cmpwi	r27, 0xd0
    bc      12, 2, _8008b51c
    cmpwi	r27, 0xd2
    bc      12, 2, _8008b51c
    cmpwi	r27, 0xd3
    bc      12, 2, _8008b51c
    cmpwi	r27, 0xd4
    bc      12, 2, _8008b51c
    addi	r3, r1, 0x10
    li	r4, 4
    bl      TRKConstructEvent
    addi	r3, r1, 0x10
    bl      TRKPostEvent
    li	r3, 0
    b       _8008b6a8
_8008b51c:
    cmpwi	r27, 0xd2
    bc      4, 2, _8008b570
    lis     r3, gTRKCPUState@ha
    addi	r6, r1, 0xc
    addi	r4, r3, gTRKCPUState@l
    lwz	r0, 0x14(r4)
    lwz	r3, 0x10(r4)
    lwz	r5, 0x18(r4)
    clrlwi	r4, r0, 0x18
    bl      fn_8008AA04
    lwz	r0, 0xc(r1)
    mr	r30, r3
    cmpwi	r0, 0
    bc      4, 2, _8008b564
    cmpwi	r30, 0
    bc      12, 2, _8008b564
    li	r0, 1
    stw	r0, 0xc(r1)
_8008b564:
    lwz	r0, 0xc(r1)
    stw	r0, 0xc(r31)
    b       _8008b690
_8008b570:
    cmpwi	r27, 0xd3
    bc      4, 2, _8008b5b8
    lis     r3, gTRKCPUState@ha
    addi	r4, r1, 0xc
    addi	r3, r3, gTRKCPUState@l
    lwz	r3, 0x10(r3)
    bl      fn_8008A91C
    lwz	r0, 0xc(r1)
    mr	r30, r3
    cmpwi	r0, 0
    bc      4, 2, _8008b5ac
    cmpwi	r30, 0
    bc      12, 2, _8008b5ac
    li	r0, 1
    stw	r0, 0xc(r1)
_8008b5ac:
    lwz	r0, 0xc(r1)
    stw	r0, 0xc(r31)
    b       _8008b690
_8008b5b8:
    cmpwi	r27, 0xd4
    bc      4, 2, _8008b624
    lis     r3, gTRKCPUState@ha
    addi	r4, r1, 8
    addi	r29, r3, gTRKCPUState@l
    addi	r6, r1, 0xc
    lwz	r3, 0x14(r29)
    lwz	r0, 0x18(r29)
    lwz	r7, 0(r3)
    lwz	r3, 0x10(r29)
    clrlwi	r5, r0, 0x18
    stw	r7, 8(r1)
    bl      fn_8008A80C
    lwz	r0, 0xc(r1)
    mr	r30, r3
    cmpwi	r0, 0
    bc      4, 2, _8008b60c
    cmpwi	r30, 0
    bc      12, 2, _8008b60c
    li	r0, 1
    stw	r0, 0xc(r1)
_8008b60c:
    lwz	r3, 0xc(r1)
    lwz	r0, 8(r1)
    stw	r3, 0xc(r31)
    lwz	r3, 0x14(r29)
    stw	r0, 0(r3)
    b       _8008b690
_8008b624:
    lis     r3, gTRKCPUState@ha
    subfic	r0, r27, 0xd1
    addi	r29, r3, gTRKCPUState@l
    addi	r6, r1, 0xc
    lwz	r28, 0x14(r29)
    cntlzw	r0, r0
    lwz	r3, 0x10(r29)
    srwi	r8, r0, 5
    lwz	r4, 0x18(r29)
    mr	r5, r28
    li	r7, 1
    bl      TRKSuppAccessFile
    lwz	r0, 0xc(r1)
    mr	r30, r3
    cmpwi	r0, 0
    bc      4, 2, _8008b674
    cmpwi	r30, 0
    bc      12, 2, _8008b674
    li	r0, 1
    stw	r0, 0xc(r1)
_8008b674:
    lwz	r0, 0xc(r1)
    cmpwi	r27, 0xd1
    stw	r0, 0xc(r31)
    bc      4, 2, _8008b690
    lwz	r3, 0x18(r29)
    lwz	r4, 0(r28)
    bl      fn_8008AFF0
_8008b690:
    lis     r4, gTRKCPUState@ha
    mr	r3, r30
    addi	r5, r4, gTRKCPUState@l
    lwz	r4, 0x80(r5)
    addi	r0, r4, 4
    stw	r0, 0x80(r5)
_8008b6a8:
    lmw	r27, 0x2c(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr
}

asm void fn_8008B6BC(void)
{
    nofralloc
    lis     r3, gTRKCPUState@ha
    addi	r3, r3, gTRKCPUState@l
    lwz	r3, 0x80(r3)
    blr
}

asm void TRKTargetCheckStep(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r5, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    bc      12, 2, _8008b6ec
    li	r3, 0x703
    b       _8008b770
_8008b6ec:
    lis     r6, gTRKStepStatus@ha
    lis     r5, lbl_80095BA8@ha
    addi	r31, r6, gTRKStepStatus@l
    li	r6, 1
    stw	r3, 0xc(r31)
    addi	r0, r5, lbl_80095BA8@l
    li	r3, 1
    stw	r4, 0x10(r31)
    mr	r4, r0
    stw	r6, 4(r31)
    stw	r6, 0(r31)
    crxor	6, 6, 6
    bl      MWTRACE
    lis     r3, gTRKCPUState@ha
    lwz	r4, 4(r31)
    addi	r3, r3, gTRKCPUState@l
    lwz	r0, 0x1f8(r3)
    cmpwi	r4, 0
    ori	r0, r0, 0x400
    stw	r0, 0x1f8(r3)
    bc      12, 2, _8008b748
    cmpwi	r4, 0x10
    bc      4, 2, _8008b75c
_8008b748:
    lis     r3, gTRKStepStatus@ha
    addi	r4, r3, gTRKStepStatus@l
    lwz	r3, 8(r4)
    addi	r0, r3, -1
    stw	r0, 8(r4)
_8008b75c:
    lis     r3, gTRKState@ha
    li	r0, 0
    addi	r4, r3, gTRKState@l
    li	r3, 0
    stw	r0, 0x98(r4)
_8008b770:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8008B784(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmpwi	r4, 0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    bc      12, 2, _8008b7a4
    li	r3, 0x703
    b       _8008b81c
_8008b7a4:
    lis     r5, gTRKStepStatus@ha
    lis     r4, lbl_80095BA8@ha
    addi	r31, r5, gTRKStepStatus@l
    li	r0, 1
    li	r5, 0
    stw	r3, 8(r31)
    addi	r4, r4, lbl_80095BA8@l
    li	r3, 1
    stw	r5, 4(r31)
    stw	r0, 0(r31)
    crxor	6, 6, 6
    bl      MWTRACE
    lis     r3, gTRKCPUState@ha
    lwz	r4, 4(r31)
    addi	r3, r3, gTRKCPUState@l
    lwz	r0, 0x1f8(r3)
    cmpwi	r4, 0
    ori	r0, r0, 0x400
    stw	r0, 0x1f8(r3)
    bc      12, 2, _8008b7fc
    cmpwi	r4, 0x10
    bc      4, 2, _8008b808
_8008b7fc:
    lwz	r3, 8(r31)
    addi	r0, r3, -1
    stw	r0, 8(r31)
_8008b808:
    lis     r3, gTRKState@ha
    li	r0, 0
    addi	r4, r3, gTRKState@l
    li	r3, 0
    stw	r0, 0x98(r4)
_8008b81c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8008B830(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    li	r4, 0
    li	r5, 0x40
    stw	r0, 0x64(r1)
    stw	r31, 0x5c(r1)
    mr	r31, r3
    addi	r3, r1, 0xc
    bl      memset
    lis	r3, -0x7fea
    li	r5, 0x40
    lwz	r4, -0x478c(r3)
    li	r0, 0x91
    stw	r5, 0xc(r1)
    addi	r3, r1, 8
    stb	r0, 0x10(r1)
    stw	r4, 0x14(r1)
    bl      fn_8008C6E4
    lis     r3, -0x7fea
    lwz	r5, 8(r1)
    addi	r4, r3, -0x478c
    mr	r3, r31
    lhz	r0, 8(r4)
    addi	r4, r1, 0xc
    stw	r5, 0x18(r1)
    li	r5, 0x40
    stw	r0, 0x1c(r1)
    bl      TRKAppendBuffer
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr
}

asm void fn_8008B8B4(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    li	r4, 0
    li	r5, 0x40
    stw	r0, 0x64(r1)
    stw	r31, 0x5c(r1)
    mr	r31, r3
    addi	r3, r1, 0xc
    bl      memset
    lis     r3, gTRKCPUState@ha
    li	r5, 0x40
    addi	r3, r3, gTRKCPUState@l
    li	r0, 0x90
    lwz	r4, 0x80(r3)
    addi	r3, r1, 8
    stw	r5, 0xc(r1)
    stb	r0, 0x10(r1)
    stw	r4, 0x14(r1)
    bl      fn_8008C6E4
    lis     r3, gTRKCPUState@ha
    lwz	r5, 8(r1)
    addi	r4, r3, gTRKCPUState@l
    mr	r3, r31
    lwz	r0, 0x2f8(r4)
    addi	r4, r1, 0xc
    stw	r5, 0x18(r1)
    li	r5, 0x40
    clrlwi	r0, r0, 0x10
    stw	r0, 0x1c(r1)
    bl      TRKAppendBuffer
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr
}

asm void TRKTargetInterrupt(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    li	r30, 0
    lwz	r0, 0(r3)
    cmpwi	r0, 5
    bc      4, 0, _8008bab4
    cmpwi	r0, 3
    bc      4, 0, _8008b970
    b       _8008bab4
_8008b970:
    lis     r3, gTRKStepStatus@ha
    addi	r4, r3, gTRKStepStatus@l
    lwz	r0, 0(r4)
    cmpwi	r0, 0
    bc      12, 2, _8008ba88
    lis     r3, gTRKCPUState@ha
    li	r5, 1
    addi	r31, r3, gTRKCPUState@l
    lwz	r0, 0x1f8(r31)
    rlwinm	r0, r0, 0, 0x16, 0x14
    stw	r0, 0x1f8(r31)
    bc      12, 2, _8008ba00
    lwz	r0, 0x2f8(r31)
    clrlwi	r0, r0, 0x10
    cmplwi	r0, 0xd00
    bc      4, 2, _8008ba00
    lwz	r0, 4(r4)
    cmpwi	r0, 1
    bc      12, 2, _8008b9e0
    bc      4, 0, _8008ba00
    cmpwi	r0, 0
    bc      4, 0, _8008b9cc
    b       _8008ba00
_8008b9cc:
    lwz	r0, 8(r4)
    cmplwi	r0, 0
    bc      12, 2, _8008ba00
    li	r5, 0
    b       _8008ba00
_8008b9e0:
    lwz	r3, 0x80(r31)
    lwz	r0, 0xc(r4)
    cmplw	r3, r0
    bc      12, 0, _8008ba00
    lwz	r0, 0x10(r4)
    cmplw	r3, r0
    bc      12, 1, _8008ba00
    li	r5, 0
_8008ba00:
    cmpwi	r5, 0
    bc      12, 2, _8008ba18
    lis	r3, -0x7fea
    li	r0, 0
    stw	r0, -0x477c(r3)
    b       _8008ba88
_8008ba18:
    lis     r4, gTRKStepStatus@ha
    li	r0, 1
    addi	r5, r4, gTRKStepStatus@l
    lis     r3, lbl_80095BA8@ha
    stw	r0, 0(r5)
    addi	r4, r3, lbl_80095BA8@l
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    lis     r3, gTRKStepStatus@ha
    lwz	r0, 0x1f8(r31)
    addi	r3, r3, gTRKStepStatus@l
    lwz	r3, 4(r3)
    ori	r0, r0, 0x400
    stw	r0, 0x1f8(r31)
    cmpwi	r3, 0
    bc      12, 2, _8008ba64
    cmpwi	r3, 0x10
    bc      4, 2, _8008ba78
_8008ba64:
    lis     r3, gTRKStepStatus@ha
    addi	r4, r3, gTRKStepStatus@l
    lwz	r3, 8(r4)
    addi	r0, r3, -1
    stw	r0, 8(r4)
_8008ba78:
    lis     r3, gTRKState@ha
    li	r0, 0
    addi	r3, r3, gTRKState@l
    stw	r0, 0x98(r3)
_8008ba88:
    lis	r3, -0x7fea
    lwz	r0, -0x477c(r3)
    cmpwi	r0, 0
    bc      4, 2, _8008bab4
    lis     r3, gTRKState@ha
    li	r0, 1
    addi	r4, r3, gTRKState@l
    li	r3, 0x90
    stw	r0, 0x98(r4)
    bl      TRKDoNotifyStopped
    mr	r30, r3
_8008bab4:
    lwz	r0, 0x14(r1)
    mr	r3, r30
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void TRKPostInterruptEvent(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, gTRKState@ha
    stw	r0, 0x24(r1)
    addi	r3, r3, gTRKState@l
    lwz	r0, 0x9c(r3)
    cmpwi	r0, 0
    bc      12, 2, _8008bafc
    li	r0, 0
    stw	r0, 0x9c(r3)
    b       _8008bb6c
_8008bafc:
    lis     r3, gTRKCPUState@ha
    addi	r3, r3, gTRKCPUState@l
    lwz	r0, 0x2f8(r3)
    clrlwi	r0, r0, 0x10
    cmpwi	r0, 0xd00
    bc      12, 2, _8008bb24
    bc      4, 0, _8008bb58
    cmpwi	r0, 0x700
    bc      12, 2, _8008bb24
    b       _8008bb58
_8008bb24:
    lis     r4, gTRKCPUState@ha
    addi	r3, r1, 8
    addi	r4, r4, gTRKCPUState@l
    lwz	r4, 0x80(r4)
    bl      fn_8008C6E4
    lwz	r3, 8(r1)
    addis	r0, r3, -0xfe0
    cmplwi	r0, 0
    bc      4, 2, _8008bb50
    li	r4, 5
    b       _8008bb5c
_8008bb50:
    li	r4, 3
    b       _8008bb5c
_8008bb58:
    li	r4, 4
_8008bb5c:
    addi	r3, r1, 0xc
    bl      TRKConstructEvent
    addi	r3, r1, 0xc
    bl      TRKPostEvent
_8008bb6c:
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKTargetAccessFP(void)
{
    nofralloc
    stwu	r1, -0x130(r1)
    mflr	r0
    stw	r0, 0x134(r1)
    stmw	r19, 0xfc(r1)
    mr	r23, r4
    cmplwi	r23, 0x1f
    mr	r27, r3
    mr	r24, r5
    mr	r25, r6
    mr	r26, r7
    bc      4, 1, _8008bbb0
    li	r3, 0x701
    b       _8008bfa0
_8008bbb0:
    lis     r3, lbl_80095B30@ha
    lis     r5, -0x7fea
    addi	r29, r3, lbl_80095B30@l
    lis	r4, 0x7c99
    lwz	r0, 0(r29)
    addi	r31, r5, -0x478c
    lwz	r8, 4(r29)
    lis	r3, 0x4e80
    lwz	r7, 0x24(r29)
    addi	r6, r4, -0x1d5a
    stw	r0, 0xc4(r1)
    addi	r0, r3, 0x20
    lwz	r19, 0(r31)
    li	r30, 0
    lwz	r22, 0xc(r31)
    lis	r5, -0x6f7d
    stw	r8, 0xc8(r1)
    addi	r3, r1, 0xc4
    lwz	r20, 4(r31)
    li	r4, 0x28
    stw	r7, 0xe8(r1)
    lwz	r21, 8(r31)
    lwz	r28, 8(r29)
    lwz	r12, 0xc(r29)
    lwz	r11, 0x10(r29)
    lwz	r10, 0x14(r29)
    lwz	r9, 0x18(r29)
    lwz	r8, 0x1c(r29)
    lwz	r7, 0x20(r29)
    stw	r19, 0x14(r1)
    stw	r20, 0x18(r1)
    stw	r21, 0x1c(r1)
    stw	r22, 0x20(r1)
    stb	r30, 0xd(r31)
    stw	r28, 0xcc(r1)
    stw	r12, 0xd0(r1)
    stw	r11, 0xd4(r1)
    stw	r10, 0xd8(r1)
    stw	r9, 0xdc(r1)
    stw	r8, 0xe0(r1)
    stw	r7, 0xe4(r1)
    stw	r6, 0xc4(r1)
    stw	r5, 0xc8(r1)
    stw	r0, 0xe8(r1)
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0xc4
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 8
    mtctr	r12
    bctrl
    lis     r3, lbl_80095B30@ha
    lwz	r5, 8(r1)
    addi	r29, r3, lbl_80095B30@l
    lis	r4, 0x7c99
    lwz	r8, 0(r29)
    lis	r3, 0x4e80
    lwz	r0, 4(r29)
    oris	r30, r5, 0xa000
    lwz	r7, 0x24(r29)
    addi	r5, r4, -0x1c5a
    stw	r0, 0xa0(r1)
    addi	r0, r3, 0x20
    lwz	r28, 8(r29)
    lis	r6, -0x7f7d
    stw	r8, 0x9c(r1)
    addi	r3, r1, 0x9c
    lwz	r12, 0xc(r29)
    li	r4, 0x28
    stw	r7, 0xc0(r1)
    lwz	r11, 0x10(r29)
    lwz	r10, 0x14(r29)
    lwz	r9, 0x18(r29)
    lwz	r8, 0x1c(r29)
    lwz	r7, 0x20(r29)
    stw	r30, 8(r1)
    stw	r28, 0xa4(r1)
    stw	r12, 0xa8(r1)
    stw	r11, 0xac(r1)
    stw	r10, 0xb0(r1)
    stw	r9, 0xb4(r1)
    stw	r8, 0xb8(r1)
    stw	r7, 0xbc(r1)
    stw	r6, 0x9c(r1)
    stw	r5, 0xa0(r1)
    stw	r0, 0xc0(r1)
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x9c
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 8
    mtctr	r12
    bctrl
    lis     r3, lbl_80095B30@ha
    lis	r4, 0x7c91
    addi	r29, r3, lbl_80095B30@l
    lis	r3, 0x4e80
    lwz	r8, 0(r29)
    li	r30, 0
    lwz	r6, 4(r29)
    addi	r5, r4, -0x1c5a
    lwz	r7, 0x24(r29)
    addi	r0, r3, 0x20
    stw	r6, 0x78(r1)
    lis	r6, -0x7f7d
    lwz	r28, 8(r29)
    addi	r3, r1, 0x74
    stw	r8, 0x74(r1)
    li	r4, 0x28
    lwz	r12, 0xc(r29)
    stw	r7, 0x98(r1)
    lwz	r11, 0x10(r29)
    lwz	r10, 0x14(r29)
    lwz	r9, 0x18(r29)
    lwz	r8, 0x1c(r29)
    lwz	r7, 0x20(r29)
    stw	r30, 8(r1)
    stw	r28, 0x7c(r1)
    stw	r12, 0x80(r1)
    stw	r11, 0x84(r1)
    stw	r10, 0x88(r1)
    stw	r9, 0x8c(r1)
    stw	r8, 0x90(r1)
    stw	r7, 0x94(r1)
    stw	r6, 0x74(r1)
    stw	r5, 0x78(r1)
    stw	r0, 0x98(r1)
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x74
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 8
    mtctr	r12
    bctrl
    li	r0, 0
    slwi	r30, r27, 0x15
    stw	r0, 0(r25)
    addi	r29, r1, 0x4c
    addi	r28, r1, 0x24
    li	r3, 0
    b       _8008bf50
_8008bde4:
    cmpwi	r26, 0
    bc      12, 2, _8008be94
    lis	r3, -0x7ff7
    lwzu	r12, 0x5b58(r3)
    oris	r0, r30, 0xe003
    lwz	r11, 4(r3)
    lwz	r10, 8(r3)
    lwz	r9, 0xc(r3)
    lwz	r8, 0x10(r3)
    lwz	r7, 0x14(r3)
    lwz	r6, 0x18(r3)
    lwz	r5, 0x1c(r3)
    lwz	r4, 0x20(r3)
    lwz	r3, 0x24(r3)
    stw	r12, 0x4c(r1)
    stw	r11, 0x50(r1)
    stw	r10, 0x54(r1)
    stw	r9, 0x58(r1)
    stw	r8, 0x5c(r1)
    stw	r7, 0x60(r1)
    stw	r6, 0x64(r1)
    stw	r5, 0x68(r1)
    stw	r4, 0x6c(r1)
    stw	r3, 0x70(r1)
    bc      12, 2, _8008be4c
    oris	r0, r30, 0xf003
_8008be4c:
    lis	r3, 0x4e80
    stw	r0, 0x4c(r1)
    addi	r0, r3, 0x20
    mr	r3, r29
    stw	r0, 0x70(r1)
    li	r4, 0x28
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x4c
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 0xc
    mtctr	r12
    bctrl
    lwz	r5, 0xc(r1)
    mr	r3, r24
    lwz	r6, 0x10(r1)
    bl      TRKReadBuffer1_ui64
    b       _8008bf3c
_8008be94:
    mr	r3, r24
    addi	r4, r1, 0xc
    bl      TRKAppendBuffer1_ui64
    lis	r3, -0x7ff7
    lwzu	r12, 0x5b58(r3)
    cmpwi	r26, 0
    oris	r0, r30, 0xe003
    lwz	r11, 4(r3)
    lwz	r10, 8(r3)
    lwz	r9, 0xc(r3)
    lwz	r8, 0x10(r3)
    lwz	r7, 0x14(r3)
    lwz	r6, 0x18(r3)
    lwz	r5, 0x1c(r3)
    lwz	r4, 0x20(r3)
    lwz	r3, 0x24(r3)
    stw	r12, 0x24(r1)
    stw	r11, 0x28(r1)
    stw	r10, 0x2c(r1)
    stw	r9, 0x30(r1)
    stw	r8, 0x34(r1)
    stw	r7, 0x38(r1)
    stw	r6, 0x3c(r1)
    stw	r5, 0x40(r1)
    stw	r4, 0x44(r1)
    stw	r3, 0x48(r1)
    bc      12, 2, _8008bf04
    oris	r0, r30, 0xf003
_8008bf04:
    lis	r3, 0x4e80
    stw	r0, 0x24(r1)
    addi	r0, r3, 0x20
    mr	r3, r28
    stw	r0, 0x48(r1)
    li	r4, 0x28
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x24
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 0xc
    mtctr	r12
    bctrl
    li	r3, 0
_8008bf3c:
    lwz	r4, 0(r25)
    addis	r30, r30, 0x20
    addi	r27, r27, 1
    addi	r0, r4, 8
    stw	r0, 0(r25)
_8008bf50:
    cmplw	r27, r23
    bc      12, 1, _8008bf60
    cmpwi	r3, 0
    bc      12, 2, _8008bde4
_8008bf60:
    lbz	r0, 0xd(r31)
    cmplwi	r0, 0
    bc      12, 2, _8008bf78
    li	r0, 0
    li	r3, 0x702
    stw	r0, 0(r25)
_8008bf78:
    lis     r4, -0x7fea
    lwz	r6, 0x14(r1)
    addi	r7, r4, -0x478c
    lwz	r5, 0x18(r1)
    lwz	r4, 0x1c(r1)
    lwz	r0, 0x20(r1)
    stw	r6, 0(r7)
    stw	r5, 4(r7)
    stw	r4, 8(r7)
    stw	r0, 0xc(r7)
_8008bfa0:
    lmw	r19, 0xfc(r1)
    lwz	r0, 0x134(r1)
    mtlr	r0
    addi	r1, r1, 0x130
    blr
}

asm void TRKTargetAccessExtended1(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    cmplwi	r4, 0x60
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r6
    bc      4, 1, _8008bfdc
    li	r3, 0x701
    b       _8008c10c
_8008bfdc:
    lis     r6, -0x7fea
    li	r0, 0
    addi	r31, r6, -0x478c
    cmplw	r3, r4
    lwz	r6, 0xc(r31)
    lwz	r10, 0(r31)
    lwz	r9, 4(r31)
    lwz	r8, 8(r31)
    stb	r0, 0xd(r31)
    stw	r10, 8(r1)
    stw	r9, 0xc(r1)
    stw	r8, 0x10(r1)
    stw	r6, 0x14(r1)
    stw	r0, 0(r30)
    bc      12, 1, _8008c0cc
    subf	r4, r3, r4
    lis     r8, gTRKCPUState@ha
    addi	r0, r4, 1
    lwz	r4, 0(r30)
    slwi	r6, r0, 2
    cmpwi	r7, 0
    add	r4, r4, r6
    addi	r7, r8, gTRKCPUState@l
    slwi	r3, r3, 2
    stw	r4, 0(r30)
    add	r4, r7, r3
    addi	r4, r4, 0x1a8
    bc      12, 2, _8008c05c
    mr	r3, r5
    mr	r5, r0
    bl      TRKReadBuffer_ui32
    b       _8008c0cc
_8008c05c:
    addi	r3, r7, 0x1ec
    cmplw	r4, r3
    bc      12, 1, _8008c088
    addi	r6, r6, -4
    addi	r3, r7, 0x1e8
    add	r6, r4, r6
    cmplw	r6, r3
    bc      12, 0, _8008c088
    lis	r3, -0x7fea
    li	r6, 1
    stb	r6, -0x4798(r3)
_8008c088:
    lis     r3, gTRKCPUState@ha
    addi	r3, r3, gTRKCPUState@l
    addi	r6, r3, 0x278
    cmplw	r4, r6
    bc      12, 1, _8008c0c0
    slwi	r3, r0, 2
    addi	r3, r3, -4
    add	r3, r4, r3
    cmplw	r3, r6
    bc      12, 0, _8008c0c0
    lis     r3, gTRKRestoreFlags@ha
    li	r6, 1
    addi	r3, r3, gTRKRestoreFlags@l
    stb	r6, 1(r3)
_8008c0c0:
    mr	r3, r5
    mr	r5, r0
    bl      TRKAppendBuffer_ui32
_8008c0cc:
    lbz	r0, 0xd(r31)
    cmplwi	r0, 0
    bc      12, 2, _8008c0e4
    li	r0, 0
    li	r3, 0x702
    stw	r0, 0(r30)
_8008c0e4:
    lis     r4, -0x7fea
    lwz	r6, 8(r1)
    addi	r7, r4, -0x478c
    lwz	r5, 0xc(r1)
    lwz	r4, 0x10(r1)
    lwz	r0, 0x14(r1)
    stw	r6, 0(r7)
    stw	r5, 4(r7)
    stw	r4, 8(r7)
    stw	r0, 0xc(r7)
_8008c10c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void TRKTargetAccessExtended2(void)
{
    nofralloc
    stwu	r1, -0xf0(r1)
    mflr	r0
    stw	r0, 0xf4(r1)
    stmw	r20, 0xc0(r1)
    mr	r28, r4
    cmplwi	r28, 0x21
    mr	r20, r3
    mr	r29, r5
    mr	r30, r6
    mr	r31, r7
    bc      4, 1, _8008c158
    li	r3, 0x701
    b       _8008c5dc
_8008c158:
    lis     r3, -0x7fea
    li	r0, 0
    addi	r27, r3, -0x478c
    lwz	r3, 0xc(r27)
    lwz	r6, 0(r27)
    lwz	r5, 4(r27)
    lwz	r4, 8(r27)
    stw	r6, 0x10(r1)
    stw	r5, 0x14(r1)
    stw	r4, 0x18(r1)
    stw	r3, 0x1c(r1)
    stb	r0, 0xd(r27)
    bl      fn_8008B0E0
    ori	r3, r3, 0x2000
    bl      fn_8008B0E8
    li	r0, 0
    mr	r22, r20
    stw	r0, 0(r30)
    slwi	r26, r20, 0x15
    addi	r21, r1, 0x98
    addi	r25, r1, 0x48
    addi	r24, r1, 0x70
    addi	r23, r1, 0x20
    li	r3, 0
    b       _8008c58c
_8008c1bc:
    cmpwi	r31, 0
    bc      12, 2, _8008c3a0
    lis     r3, lbl_80095B80@ha
    cmplwi	r22, 0x20
    addi	r12, r3, lbl_80095B80@l
    lwz	r11, 0(r12)
    lwz	r10, 4(r12)
    lwz	r9, 8(r12)
    lwz	r8, 0xc(r12)
    lwz	r7, 0x10(r12)
    lwz	r6, 0x14(r12)
    lwz	r5, 0x18(r12)
    lwz	r4, 0x1c(r12)
    lwz	r3, 0x20(r12)
    lwz	r0, 0x24(r12)
    stw	r11, 0x98(r1)
    stw	r10, 0x9c(r1)
    stw	r9, 0xa0(r1)
    stw	r8, 0xa4(r1)
    stw	r7, 0xa8(r1)
    stw	r6, 0xac(r1)
    stw	r5, 0xb0(r1)
    stw	r4, 0xb4(r1)
    stw	r3, 0xb8(r1)
    stw	r0, 0xbc(r1)
    bc      4, 0, _8008c26c
    cmpwi	r31, 0
    oris	r0, r26, 0xc803
    bc      12, 2, _8008c234
    oris	r0, r26, 0xd803
_8008c234:
    lis	r3, 0x4e80
    stw	r0, 0x98(r1)
    addi	r0, r3, 0x20
    mr	r3, r21
    stw	r0, 0xbc(r1)
    li	r4, 0x28
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x98
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 8
    mtctr	r12
    bctrl
    b       _8008c38c
_8008c26c:
    bc      4, 2, _8008c294
    lwz	r4, 8(r1)
    li	r0, 0
    lwz	r5, 0xc(r1)
    li	r3, -1
    and	r0, r4, r0
    and	r3, r5, r3
    stw	r0, 8(r1)
    stw	r3, 0xc(r1)
    b       _8008c38c
_8008c294:
    cmplwi	r22, 0x21
    bc      4, 2, _8008c38c
    cmpwi	r31, 0
    bc      4, 2, _8008c2ac
    lwz	r0, 0xc(r1)
    stw	r0, 8(r1)
_8008c2ac:
    lis     r3, lbl_80095B30@ha
    cmpwi	r31, 0
    addi	r12, r3, lbl_80095B30@l
    lwz	r11, 0(r12)
    lwz	r10, 4(r12)
    lwz	r9, 8(r12)
    lwz	r8, 0xc(r12)
    lwz	r7, 0x10(r12)
    lwz	r6, 0x14(r12)
    lwz	r5, 0x18(r12)
    lwz	r4, 0x1c(r12)
    lwz	r3, 0x20(r12)
    lwz	r0, 0x24(r12)
    stw	r11, 0x48(r1)
    stw	r10, 0x4c(r1)
    stw	r9, 0x50(r1)
    stw	r8, 0x54(r1)
    stw	r7, 0x58(r1)
    stw	r6, 0x5c(r1)
    stw	r5, 0x60(r1)
    stw	r4, 0x64(r1)
    stw	r3, 0x68(r1)
    stw	r0, 0x6c(r1)
    bc      12, 2, _8008c324
    lis	r3, 0x7c9f
    lis	r0, -0x6f7d
    addi	r3, r3, -0x55a
    stw	r0, 0x4c(r1)
    stw	r3, 0x48(r1)
    b       _8008c338
_8008c324:
    lis	r3, 0x7c9f
    lis	r4, -0x7f7d
    addi	r0, r3, -0x45a
    stw	r4, 0x48(r1)
    stw	r0, 0x4c(r1)
_8008c338:
    lis	r4, 0x4e80
    mr	r3, r25
    addi	r0, r4, 0x20
    li	r4, 0x28
    stw	r0, 0x6c(r1)
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x48
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 8
    mtctr	r12
    bctrl
    cmpwi	r31, 0
    bc      12, 2, _8008c38c
    lwz	r3, 8(r1)
    li	r4, 0
    li	r0, -1
    and	r3, r3, r0
    and	r0, r4, r4
    stw	r3, 0xc(r1)
    stw	r0, 8(r1)
_8008c38c:
    lwz	r5, 8(r1)
    mr	r3, r29
    lwz	r6, 0xc(r1)
    bl      TRKReadBuffer1_ui64
    b       _8008c578
_8008c3a0:
    mr	r3, r29
    addi	r4, r1, 8
    bl      TRKAppendBuffer1_ui64
    lis     r3, lbl_80095B80@ha
    cmplwi	r22, 0x20
    addi	r20, r3, lbl_80095B80@l
    li	r3, 0
    lwz	r12, 0(r20)
    lwz	r11, 4(r20)
    lwz	r10, 8(r20)
    lwz	r9, 0xc(r20)
    lwz	r8, 0x10(r20)
    lwz	r7, 0x14(r20)
    lwz	r6, 0x18(r20)
    lwz	r5, 0x1c(r20)
    lwz	r4, 0x20(r20)
    lwz	r0, 0x24(r20)
    stw	r12, 0x70(r1)
    stw	r11, 0x74(r1)
    stw	r10, 0x78(r1)
    stw	r9, 0x7c(r1)
    stw	r8, 0x80(r1)
    stw	r7, 0x84(r1)
    stw	r6, 0x88(r1)
    stw	r5, 0x8c(r1)
    stw	r4, 0x90(r1)
    stw	r0, 0x94(r1)
    bc      4, 0, _8008c45c
    cmpwi	r31, 0
    oris	r0, r26, 0xc803
    bc      12, 2, _8008c420
    oris	r0, r26, 0xd803
_8008c420:
    lis	r3, 0x4e80
    stw	r0, 0x70(r1)
    addi	r0, r3, 0x20
    mr	r3, r24
    stw	r0, 0x94(r1)
    li	r4, 0x28
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x70
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 8
    mtctr	r12
    bctrl
    li	r3, 0
    b       _8008c578
_8008c45c:
    bc      4, 2, _8008c480
    lwz	r0, 8(r1)
    li	r4, -1
    lwz	r5, 0xc(r1)
    and	r0, r0, r3
    and	r4, r5, r4
    stw	r0, 8(r1)
    stw	r4, 0xc(r1)
    b       _8008c578
_8008c480:
    cmplwi	r22, 0x21
    bc      4, 2, _8008c578
    cmpwi	r31, 0
    bc      4, 2, _8008c498
    lwz	r0, 0xc(r1)
    stw	r0, 8(r1)
_8008c498:
    lis     r3, lbl_80095B30@ha
    cmpwi	r31, 0
    addi	r12, r3, lbl_80095B30@l
    lwz	r11, 0(r12)
    lwz	r10, 4(r12)
    lwz	r9, 8(r12)
    lwz	r8, 0xc(r12)
    lwz	r7, 0x10(r12)
    lwz	r6, 0x14(r12)
    lwz	r5, 0x18(r12)
    lwz	r4, 0x1c(r12)
    lwz	r3, 0x20(r12)
    lwz	r0, 0x24(r12)
    stw	r11, 0x20(r1)
    stw	r10, 0x24(r1)
    stw	r9, 0x28(r1)
    stw	r8, 0x2c(r1)
    stw	r7, 0x30(r1)
    stw	r6, 0x34(r1)
    stw	r5, 0x38(r1)
    stw	r4, 0x3c(r1)
    stw	r3, 0x40(r1)
    stw	r0, 0x44(r1)
    bc      12, 2, _8008c510
    lis	r3, 0x7c9f
    lis	r0, -0x6f7d
    addi	r3, r3, -0x55a
    stw	r0, 0x24(r1)
    stw	r3, 0x20(r1)
    b       _8008c524
_8008c510:
    lis	r3, 0x7c9f
    lis	r4, -0x7f7d
    addi	r0, r3, -0x45a
    stw	r4, 0x20(r1)
    stw	r0, 0x24(r1)
_8008c524:
    lis	r4, 0x4e80
    mr	r3, r23
    addi	r0, r4, 0x20
    li	r4, 0x28
    stw	r0, 0x44(r1)
    bl      fn_8008AFF0
    lis     r3, lbl_801A5624@ha
    addi	r12, r1, 0x20
    addi	r4, r3, lbl_801A5624@l
    addi	r3, r1, 8
    mtctr	r12
    bctrl
    cmpwi	r31, 0
    li	r3, 0
    bc      12, 2, _8008c578
    lwz	r5, 8(r1)
    li	r4, -1
    and	r0, r3, r3
    and	r4, r5, r4
    stw	r0, 8(r1)
    stw	r4, 0xc(r1)
_8008c578:
    lwz	r4, 0(r30)
    addis	r26, r26, 0x20
    addi	r22, r22, 1
    addi	r0, r4, 8
    stw	r0, 0(r30)
_8008c58c:
    cmplw	r22, r28
    bc      12, 1, _8008c59c
    cmpwi	r3, 0
    bc      12, 2, _8008c1bc
_8008c59c:
    lbz	r0, 0xd(r27)
    cmplwi	r0, 0
    bc      12, 2, _8008c5b4
    li	r0, 0
    li	r3, 0x702
    stw	r0, 0(r30)
_8008c5b4:
    lis     r4, -0x7fea
    lwz	r6, 0x10(r1)
    addi	r7, r4, -0x478c
    lwz	r5, 0x14(r1)
    lwz	r4, 0x18(r1)
    lwz	r0, 0x1c(r1)
    stw	r6, 0(r7)
    stw	r5, 4(r7)
    stw	r4, 8(r7)
    stw	r0, 0xc(r7)
_8008c5dc:
    lmw	r20, 0xc0(r1)
    lwz	r0, 0xf4(r1)
    mtlr	r0
    addi	r1, r1, 0xf0
    blr
}

asm void TRKTargetAccessDefault(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    cmplwi	r4, 0x24
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r6
    stw	r30, 0x18(r1)
    bc      4, 1, _8008c618
    li	r3, 0x701
    b       _8008c6cc
_8008c618:
    lis     r6, -0x7fea
    subf	r4, r3, r4
    addi	r30, r6, -0x478c
    lis	r6, -0x7fe6
    lwz	r9, 0xc(r30)
    li	r8, 0
    addi	r12, r4, 1
    lwz	r11, 0(r30)
    lwz	r10, 4(r30)
    cmpwi	r7, 0
    lwz	r7, 8(r30)
    slwi	r0, r12, 2
    stb	r8, 0xd(r30)
    slwi	r4, r3, 2
    addi	r3, r6, 0x5160
    stw	r11, 8(r1)
    add	r4, r3, r4
    stw	r10, 0xc(r1)
    stw	r7, 0x10(r1)
    stw	r9, 0x14(r1)
    stw	r0, 0(r31)
    bc      12, 2, _8008c680
    mr	r3, r5
    mr	r5, r12
    bl      TRKReadBuffer_ui32
    b       _8008c68c
_8008c680:
    mr	r3, r5
    mr	r5, r12
    bl      TRKAppendBuffer_ui32
_8008c68c:
    lbz	r0, 0xd(r30)
    cmplwi	r0, 0
    bc      12, 2, _8008c6a4
    li	r0, 0
    li	r3, 0x702
    stw	r0, 0(r31)
_8008c6a4:
    lis     r4, -0x7fea
    lwz	r6, 8(r1)
    addi	r7, r4, -0x478c
    lwz	r5, 0xc(r1)
    lwz	r4, 0x10(r1)
    lwz	r0, 0x14(r1)
    stw	r6, 0(r7)
    stw	r5, 4(r7)
    stw	r4, 8(r7)
    stw	r0, 0xc(r7)
_8008c6cc:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8008C6E4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r6, 0
    li	r7, 1
    stw	r0, 0x14(r1)
    li	r0, 4
    addi	r5, r1, 8
    stw	r0, 8(r1)
    bl      TRKTargetAccessMemory
    cmpwi	r3, 0
    bc      4, 2, _8008c720
    lwz	r0, 8(r1)
    cmplwi	r0, 4
    bc      12, 2, _8008c720
    li	r3, 0x700
_8008c720:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void TRKTargetAccessMemory(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    lis     r6, -0x7fea
    stw	r0, 0x44(r1)
    li	r0, 0
    stmw	r25, 0x24(r1)
    addi	r31, r6, -0x478c
    mr	r27, r4
    mr	r28, r5
    mr	r26, r3
    mr	r29, r7
    mr	r3, r27
    lwz	r4, 0xc(r31)
    lwz	r8, 0(r31)
    lwz	r6, 4(r31)
    lwz	r5, 8(r31)
    stw	r8, 8(r1)
    stw	r6, 0xc(r1)
    stw	r5, 0x10(r1)
    stw	r4, 0x14(r1)
    stb	r0, 0xd(r31)
    bl      fn_8008D154
    cntlzw	r0, r29
    lwz	r4, 0(r28)
    mr	r25, r3
    srwi	r5, r0, 5
    bl      TRKValidMemory32
    or.	r30, r3, r3
    bc      12, 2, _8008c7b0
    li	r0, 0
    stw	r0, 0(r28)
    b       _8008c824
_8008c7b0:
    bl      fn_8008B0E0
    lis     r4, gTRKCPUState@ha
    cmpwi	r29, 0
    addi	r4, r4, gTRKCPUState@l
    mr	r8, r3
    lwz	r0, 0x1f8(r4)
    rlwinm	r0, r0, 0, 0x1b, 0x1b
    or	r7, r8, r0
    bc      12, 2, _8008c7ec
    lwz	r5, 0(r28)
    mr	r3, r26
    mr	r4, r25
    mr	r6, r8
    bl      fn_8008B0F0
    b       _8008c824
_8008c7ec:
    lwz	r5, 0(r28)
    mr	r3, r25
    mr	r4, r26
    mr	r6, r7
    mr	r7, r8
    bl      fn_8008B0F0
    lwz	r4, 0(r28)
    mr	r3, r25
    bl      fn_8008AFF0
    cmplw	r27, r25
    bc      12, 2, _8008c824
    lwz	r4, 0(r28)
    mr	r3, r27
    bl      fn_8008AFF0
_8008c824:
    lbz	r0, 0xd(r31)
    cmplwi	r0, 0
    bc      12, 2, _8008c83c
    li	r0, 0
    li	r30, 0x702
    stw	r0, 0(r28)
_8008c83c:
    lis     r3, -0x7fea
    lwz	r6, 8(r1)
    addi	r7, r3, -0x478c
    lwz	r5, 0xc(r1)
    lwz	r4, 0x10(r1)
    mr	r3, r30
    lwz	r0, 0x14(r1)
    stw	r6, 0(r7)
    stw	r5, 4(r7)
    stw	r4, 8(r7)
    stw	r0, 0xc(r7)
    lmw	r25, 0x24(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr
}

asm void TRKValidMemory32(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r26, 8(r1)
    add	r27, r4, r3
    addi	r27, r27, -1
    mr	r26, r5
    cmplw	r27, r3
    li	r5, 0x700
    bc      4, 0, _8008c8ac
    li	r3, 0x700
    b       _8008cb0c
_8008c8ac:
    lis     r4, gTRKMemMap@ha
    li	r6, 0
    addi	r31, r4, gTRKMemMap@l
    lwz	r0, 4(r31)
    cmplw	r3, r0
    bc      12, 1, _8008cb08
    lwz	r0, 0(r31)
    cmplw	r27, r0
    bc      12, 0, _8008cb08
    cmpwi	r26, 0
    bc      4, 2, _8008c8ec
    slwi	r0, r6, 4
    add	r4, r31, r0
    lwz	r0, 8(r4)
    cmpwi	r0, 0
    bc      12, 2, _8008c910
_8008c8ec:
    cmpwi	r26, 1
    bc      4, 2, _8008c918
    lis     r4, gTRKMemMap@ha
    slwi	r0, r6, 4
    addi	r4, r4, gTRKMemMap@l
    add	r4, r4, r0
    lwz	r0, 0xc(r4)
    cmpwi	r0, 0
    bc      4, 2, _8008c918
_8008c910:
    li	r5, 0x700
    b       _8008cb08
_8008c918:
    lis     r4, gTRKMemMap@ha
    slwi	r29, r6, 4
    addi	r4, r4, gTRKMemMap@l
    li	r5, 0
    lwzx	r0, r4, r29
    cmplw	r3, r0
    bc      4, 0, _8008ca14
    subf	r0, r3, r0
    li	r6, 0x700
    add	r30, r0, r3
    addi	r30, r30, -1
    cmplw	r30, r3
    bc      4, 0, _8008c950
    b       _8008ca10
_8008c950:
    lwz	r0, 4(r31)
    li	r5, 0
    cmplw	r3, r0
    bc      12, 1, _8008ca10
    lwz	r0, 0(r31)
    cmplw	r30, r0
    bc      12, 0, _8008ca10
    cmpwi	r26, 0
    bc      4, 2, _8008c988
    slwi	r0, r5, 4
    add	r4, r4, r0
    lwz	r0, 8(r4)
    cmpwi	r0, 0
    bc      12, 2, _8008c9ac
_8008c988:
    cmpwi	r26, 1
    bc      4, 2, _8008c9b4
    lis     r4, gTRKMemMap@ha
    slwi	r0, r5, 4
    addi	r4, r4, gTRKMemMap@l
    add	r4, r4, r0
    lwz	r0, 0xc(r4)
    cmpwi	r0, 0
    bc      4, 2, _8008c9b4
_8008c9ac:
    li	r6, 0x700
    b       _8008ca10
_8008c9b4:
    lis     r4, gTRKMemMap@ha
    slwi	r28, r5, 4
    addi	r4, r4, gTRKMemMap@l
    li	r6, 0
    lwzx	r0, r4, r28
    cmplw	r3, r0
    bc      4, 0, _8008c9e0
    mr	r5, r26
    subf	r4, r3, r0
    bl      TRKValidMemory32
    mr	r6, r3
_8008c9e0:
    cmpwi	r6, 0
    bc      4, 2, _8008ca10
    lis     r3, gTRKMemMap@ha
    addi	r0, r3, gTRKMemMap@l
    add	r3, r0, r28
    lwz	r3, 4(r3)
    cmplw	r30, r3
    bc      4, 1, _8008ca10
    mr	r5, r26
    subf	r4, r3, r30
    bl      TRKValidMemory32
    mr	r6, r3
_8008ca10:
    mr	r5, r6
_8008ca14:
    cmpwi	r5, 0
    bc      4, 2, _8008cb08
    lis     r3, gTRKMemMap@ha
    addi	r4, r3, gTRKMemMap@l
    addi	r28, r4, 4
    lwzx	r3, r28, r29
    cmplw	r27, r3
    bc      4, 1, _8008cb08
    subf	r0, r3, r27
    li	r6, 0x700
    add	r30, r0, r3
    addi	r30, r30, -1
    cmplw	r30, r3
    bc      4, 0, _8008ca50
    b       _8008cb04
_8008ca50:
    lwz	r0, 4(r31)
    li	r5, 0
    cmplw	r3, r0
    bc      12, 1, _8008cb04
    lwz	r0, 0(r31)
    cmplw	r30, r0
    bc      12, 0, _8008cb04
    cmpwi	r26, 0
    bc      4, 2, _8008ca88
    slwi	r0, r5, 4
    add	r4, r4, r0
    lwz	r0, 8(r4)
    cmpwi	r0, 0
    bc      12, 2, _8008caac
_8008ca88:
    cmpwi	r26, 1
    bc      4, 2, _8008cab4
    lis     r4, gTRKMemMap@ha
    slwi	r0, r5, 4
    addi	r4, r4, gTRKMemMap@l
    add	r4, r4, r0
    lwz	r0, 0xc(r4)
    cmpwi	r0, 0
    bc      4, 2, _8008cab4
_8008caac:
    li	r6, 0x700
    b       _8008cb04
_8008cab4:
    lis     r4, gTRKMemMap@ha
    slwi	r27, r5, 4
    addi	r4, r4, gTRKMemMap@l
    li	r6, 0
    lwzx	r0, r4, r27
    cmplw	r3, r0
    bc      4, 0, _8008cae0
    mr	r5, r26
    subf	r4, r3, r0
    bl      TRKValidMemory32
    mr	r6, r3
_8008cae0:
    cmpwi	r6, 0
    bc      4, 2, _8008cb04
    lwzx	r3, r28, r27
    cmplw	r30, r3
    bc      4, 1, _8008cb04
    mr	r5, r26
    subf	r4, r3, r30
    bl      TRKValidMemory32
    mr	r6, r3
_8008cb04:
    mr	r5, r6
_8008cb08:
    mr	r3, r5
_8008cb0c:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

#pragma force_active off
