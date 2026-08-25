#pragma push
#pragma force_active on

extern void __CARDUnlock(void);
extern void UnlockSendDspMail(void);
extern void __CARDUnlockInitCallback(void);
extern void __CARDBlockReadCallback(void);
extern void __CARDRead(void);
extern void __CARDBlockWriteCallback(void);
extern void __CARDWrite(void);
extern void __CARDGetFatBlock(void);
extern void __CARDBlockWriteCallback2(void);
extern void __CARDBlockEraseCallback(void);
extern void __CARDAllocBlock(void);
extern void __CARDFreeBlock(void);
extern void __CARDUpdateFatBlock(void);
extern void __CARDGetDirBlock(void);
extern void __CARDDirWriteCallback(void);
extern void __CARDDirEraseCallback(void);
extern void __CARDUpdateDir(void);
extern void __CARDCheckSum(void);
extern void DCFlushRange(void);
extern void DCInvalidateRange(void);
extern void DCStoreRange(void);
extern void DSPAddTask(void);
extern void DSPCheckMailToDSP(void);
extern void DSPSendMailToDSP(void);
extern void EXIProbe(void);
extern void EXIUnlock(void);
extern void OSGetTick(void);
extern void __CARDReadStatus(void);
extern void __CARDReadSegment(void);
extern void __CARDWritePage(void);
extern void __CARDEraseSector(void);
extern void __CARDPutControlBlock(void);
extern void __CARDBitRev(void);
extern void ReadArrayUnlock(void);
extern void GetInitVal(void);
extern void __CARDMountCallback(void);
extern void memcpy(void);
extern unsigned char __CARDBlock[544];
extern unsigned char card_unlock_dsp_cmd_data[32];

extern unsigned char lbl_801A6510[8];
asm void __CARDUnlock(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x120(r1)
    stmw	r22, 0xf8(r1)
    addi	r24, r3, 0
    lis     r3, __CARDBlock@ha
    mulli	r5, r24, 0x110
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    addi	r23, r4, 0
    addi	r30, r31, 0x30
    lwz	r3, 0x80(r31)
    addi	r0, r3, 0x2f
    rlwinm	r28, r0, 0, 0, 0x1a
    addi	r29, r3, 0
    addi	r22, r28, 0x20
    bl      OSGetTick
    stw	r3, lbl_801A6510
    lis	r3, 0x41c6
    lis	r5, 0x7fed
    lwz	r4, lbl_801A6510
    addi	r0, r3, 0x4e6d
    addi	r25, r5, -0x8000
    mullw	r3, r4, r0
    addi	r0, r3, 0x3039
    stw	r0, lbl_801A6510
    lwz	r0, lbl_801A6510
    rlwinm	r0, r0, 0x10, 0x11, 0x1f
    or	r25, r25, r0
    rlwinm	r25, r25, 0, 0, 0x13
    bl      GetInitVal
    addi	r26, r3, 0
    addi	r6, r26, 0
    addi	r3, r24, 0
    addi	r4, r25, 0
    addi	r5, r1, 0xa4
    li	r7, 0
    bl      ReadArrayUnlock
    cmpwi	r3, 0
    bge     _8002afdc
    li	r3, -3
    b       _8002ba78
_8002afdc:
    slwi	r3, r26, 3
    addi	r4, r3, 1
    cmplwi	r4, 0
    li	r3, 0
    ble     _8002b154
    cmplwi	r4, 8
    addi	r5, r4, -8
    ble     _8002b11c
    addi	r0, r5, 7
    srwi	r0, r0, 3
    cmplwi	r5, 0
    mtctr	r0
    ble     _8002b11c
_8002b010:
    srwi	r0, r25, 7
    srwi	r5, r25, 0xf
    xor	r0, r25, r0
    xor	r0, r5, r0
    srwi	r6, r25, 0x17
    eqv	r0, r6, r0
    srwi	r5, r25, 1
    rlwinm	r0, r0, 0x1e, 1, 1
    or	r7, r5, r0
    srwi	r0, r7, 7
    srwi	r5, r7, 0xf
    xor	r0, r7, r0
    srwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r8, r0, 0x1e, 1, 1
    rlwimi	r8, r7, 0x1f, 2, 0x1f
    srwi	r0, r8, 7
    srwi	r5, r8, 0xf
    xor	r0, r8, r0
    srwi	r6, r8, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r7, r0, 0x1e, 1, 1
    rlwimi	r7, r8, 0x1f, 2, 0x1f
    srwi	r0, r7, 7
    srwi	r5, r7, 0xf
    xor	r0, r7, r0
    srwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r8, r0, 0x1e, 1, 1
    rlwimi	r8, r7, 0x1f, 2, 0x1f
    srwi	r0, r8, 7
    srwi	r5, r8, 0xf
    xor	r0, r8, r0
    srwi	r6, r8, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r7, r0, 0x1e, 1, 1
    rlwimi	r7, r8, 0x1f, 2, 0x1f
    srwi	r0, r7, 7
    srwi	r5, r7, 0xf
    xor	r0, r7, r0
    srwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r8, r0, 0x1e, 1, 1
    rlwimi	r8, r7, 0x1f, 2, 0x1f
    srwi	r0, r8, 7
    srwi	r5, r8, 0xf
    xor	r0, r8, r0
    srwi	r6, r8, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r7, r0, 0x1e, 1, 1
    rlwimi	r7, r8, 0x1f, 2, 0x1f
    srwi	r0, r7, 7
    srwi	r5, r7, 0xf
    xor	r0, r7, r0
    srwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r25, r0, 0x1e, 1, 1
    rlwimi	r25, r7, 0x1f, 2, 0x1f
    addi	r3, r3, 8
    bdnz    _8002b010
_8002b11c:
    subf	r0, r3, r4
    cmplw	r3, r4
    mtctr	r0
    bge     _8002b154
_8002b12c:
    srwi	r0, r25, 7
    srwi	r3, r25, 0xf
    xor	r0, r25, r0
    srwi	r4, r25, 0x17
    xor	r0, r3, r0
    eqv	r0, r4, r0
    srwi	r3, r25, 1
    rlwinm	r0, r0, 0x1e, 1, 1
    or	r25, r3, r0
    bdnz    _8002b12c
_8002b154:
    srwi	r0, r25, 7
    srwi	r3, r25, 0xf
    xor	r0, r25, r0
    srwi	r4, r25, 0x17
    xor	r0, r3, r0
    eqv	r0, r4, r0
    slwi	r0, r0, 0x1f
    or	r0, r25, r0
    stw	r0, 0x2c(r31)
    lwz	r3, 0x2c(r31)
    bl      __CARDBitRev
    stw	r3, 0x2c(r31)
    bl      GetInitVal
    addi	r27, r3, 0
    addi	r6, r27, 0x14
    addi	r3, r24, 0
    addi	r5, r1, 0xa4
    li	r4, 0
    li	r7, 1
    bl      ReadArrayUnlock
    cmpwi	r3, 0
    bge     _8002b1b4
    li	r3, -3
    b       _8002ba78
_8002b1b4:
    li	r3, 4
    lwz	r7, 0x2c(r31)
    lwz	r25, 0xa4(r1)
    mtctr	r3
    lwz	r26, 0xa8(r1)
    lwz	r24, 0xac(r1)
    xor	r25, r25, r7
    lwz	r0, 0xb0(r1)
    lwz	r5, 0xb4(r1)
_8002b1d8:
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    xor	r3, r4, r3
    slwi	r6, r7, 0x17
    eqv	r3, r6, r3
    slwi	r4, r7, 1
    rlwinm	r3, r3, 2, 0x1e, 0x1e
    or	r7, r4, r3
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r9, r3, 2, 0x1e, 0x1e
    rlwimi	r9, r7, 1, 0, 0x1d
    slwi	r3, r9, 7
    slwi	r4, r9, 0xf
    xor	r3, r9, r3
    slwi	r6, r9, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r9, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    bdnz    _8002b1d8
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    srwi	r3, r3, 0x1f
    or	r3, r7, r3
    stw	r3, 0x2c(r31)
    li	r3, 4
    mtctr	r3
    lwz	r7, 0x2c(r31)
    xor	r26, r26, r7
_8002b314:
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    xor	r3, r4, r3
    slwi	r6, r7, 0x17
    eqv	r3, r6, r3
    slwi	r4, r7, 1
    rlwinm	r3, r3, 2, 0x1e, 0x1e
    or	r7, r4, r3
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r9, r3, 2, 0x1e, 0x1e
    rlwimi	r9, r7, 1, 0, 0x1d
    slwi	r3, r9, 7
    slwi	r4, r9, 0xf
    xor	r3, r9, r3
    slwi	r6, r9, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r9, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    bdnz    _8002b314
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    srwi	r3, r3, 0x1f
    or	r3, r7, r3
    stw	r3, 0x2c(r31)
    li	r3, 4
    mtctr	r3
    lwz	r7, 0x2c(r31)
    xor	r24, r24, r7
_8002b450:
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    xor	r3, r4, r3
    slwi	r6, r7, 0x17
    eqv	r3, r6, r3
    slwi	r4, r7, 1
    rlwinm	r3, r3, 2, 0x1e, 0x1e
    or	r7, r4, r3
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r9, r3, 2, 0x1e, 0x1e
    rlwimi	r9, r7, 1, 0, 0x1d
    slwi	r3, r9, 7
    slwi	r4, r9, 0xf
    xor	r3, r9, r3
    slwi	r6, r9, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r9, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    bdnz    _8002b450
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    srwi	r3, r3, 0x1f
    or	r3, r7, r3
    stw	r3, 0x2c(r31)
    li	r3, 4
    mtctr	r3
    lwz	r7, 0x2c(r31)
    xor	r0, r0, r7
_8002b58c:
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    xor	r3, r4, r3
    slwi	r6, r7, 0x17
    eqv	r3, r6, r3
    slwi	r4, r7, 1
    rlwinm	r3, r3, 2, 0x1e, 0x1e
    or	r7, r4, r3
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r9, r3, 2, 0x1e, 0x1e
    rlwimi	r9, r7, 1, 0, 0x1d
    slwi	r3, r9, 7
    slwi	r4, r9, 0xf
    xor	r3, r9, r3
    slwi	r6, r9, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r9, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    slwi	r6, r7, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r8, r3, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r3, r8, 7
    slwi	r4, r8, 0xf
    xor	r3, r8, r3
    slwi	r6, r8, 0x17
    xor	r3, r4, r3
    eqv	r3, r6, r3
    rlwinm	r7, r3, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    bdnz    _8002b58c
    slwi	r3, r7, 7
    slwi	r4, r7, 0xf
    xor	r3, r7, r3
    xor	r3, r4, r3
    slwi	r6, r7, 0x17
    eqv	r3, r6, r3
    srwi	r3, r3, 0x1f
    or	r3, r7, r3
    stw	r3, 0x2c(r31)
    slwi	r4, r27, 3
    cmplwi	r4, 0
    lwz	r6, 0x2c(r31)
    li	r3, 0
    xor	r5, r5, r6
    ble     _8002b834
    cmplwi	r4, 8
    addi	r8, r4, -8
    ble     _8002b7fc
    addi	r7, r8, 7
    srwi	r7, r7, 3
    cmplwi	r8, 0
    mtctr	r7
    ble     _8002b7fc
_8002b6f0:
    slwi	r7, r6, 7
    slwi	r8, r6, 0xf
    xor	r7, r6, r7
    xor	r7, r8, r7
    slwi	r9, r6, 0x17
    eqv	r7, r9, r7
    slwi	r8, r6, 1
    rlwinm	r6, r7, 2, 0x1e, 0x1e
    or	r9, r8, r6
    slwi	r6, r9, 7
    slwi	r7, r9, 0xf
    xor	r6, r9, r6
    slwi	r8, r9, 0x17
    xor	r6, r7, r6
    eqv	r6, r8, r6
    rlwinm	r10, r6, 2, 0x1e, 0x1e
    rlwimi	r10, r9, 1, 0, 0x1d
    slwi	r6, r10, 7
    slwi	r7, r10, 0xf
    xor	r6, r10, r6
    slwi	r8, r10, 0x17
    xor	r6, r7, r6
    eqv	r6, r8, r6
    rlwinm	r9, r6, 2, 0x1e, 0x1e
    rlwimi	r9, r10, 1, 0, 0x1d
    slwi	r6, r9, 7
    slwi	r7, r9, 0xf
    xor	r6, r9, r6
    slwi	r8, r9, 0x17
    xor	r6, r7, r6
    eqv	r6, r8, r6
    rlwinm	r10, r6, 2, 0x1e, 0x1e
    rlwimi	r10, r9, 1, 0, 0x1d
    slwi	r6, r10, 7
    slwi	r7, r10, 0xf
    xor	r6, r10, r6
    slwi	r8, r10, 0x17
    xor	r6, r7, r6
    eqv	r6, r8, r6
    rlwinm	r9, r6, 2, 0x1e, 0x1e
    rlwimi	r9, r10, 1, 0, 0x1d
    slwi	r6, r9, 7
    slwi	r7, r9, 0xf
    xor	r6, r9, r6
    slwi	r8, r9, 0x17
    xor	r6, r7, r6
    eqv	r6, r8, r6
    rlwinm	r10, r6, 2, 0x1e, 0x1e
    rlwimi	r10, r9, 1, 0, 0x1d
    slwi	r6, r10, 7
    slwi	r7, r10, 0xf
    xor	r6, r10, r6
    slwi	r8, r10, 0x17
    xor	r6, r7, r6
    eqv	r6, r8, r6
    rlwinm	r9, r6, 2, 0x1e, 0x1e
    rlwimi	r9, r10, 1, 0, 0x1d
    slwi	r6, r9, 7
    slwi	r7, r9, 0xf
    xor	r6, r9, r6
    slwi	r8, r9, 0x17
    xor	r6, r7, r6
    eqv	r6, r8, r6
    rlwinm	r6, r6, 2, 0x1e, 0x1e
    rlwimi	r6, r9, 1, 0, 0x1d
    addi	r3, r3, 8
    bdnz    _8002b6f0
_8002b7fc:
    subf	r7, r3, r4
    cmplw	r3, r4
    mtctr	r7
    bge     _8002b834
_8002b80c:
    slwi	r3, r6, 7
    slwi	r4, r6, 0xf
    xor	r3, r6, r3
    slwi	r7, r6, 0x17
    xor	r3, r4, r3
    eqv	r3, r7, r3
    slwi	r4, r6, 1
    rlwinm	r3, r3, 2, 0x1e, 0x1e
    or	r6, r4, r3
    bdnz    _8002b80c
_8002b834:
    slwi	r3, r6, 7
    slwi	r4, r6, 0xf
    xor	r3, r6, r3
    slwi	r7, r6, 0x17
    xor	r3, r4, r3
    eqv	r3, r7, r3
    srwi	r3, r3, 0x1f
    or	r3, r6, r3
    stw	r3, 0x2c(r31)
    li	r3, 4
    mtctr	r3
    li	r3, 0
    lwz	r4, 0x2c(r31)
_8002b868:
    slwi	r6, r4, 7
    slwi	r7, r4, 0xf
    xor	r6, r4, r6
    xor	r6, r7, r6
    slwi	r8, r4, 0x17
    eqv	r6, r8, r6
    slwi	r7, r4, 1
    rlwinm	r4, r6, 2, 0x1e, 0x1e
    or	r8, r7, r4
    slwi	r4, r8, 7
    slwi	r6, r8, 0xf
    xor	r4, r8, r4
    slwi	r7, r8, 0x17
    xor	r4, r6, r4
    eqv	r4, r7, r4
    rlwinm	r9, r4, 2, 0x1e, 0x1e
    rlwimi	r9, r8, 1, 0, 0x1d
    slwi	r4, r9, 7
    slwi	r6, r9, 0xf
    xor	r4, r9, r4
    slwi	r7, r9, 0x17
    xor	r4, r6, r4
    eqv	r4, r7, r4
    rlwinm	r8, r4, 2, 0x1e, 0x1e
    rlwimi	r8, r9, 1, 0, 0x1d
    slwi	r4, r8, 7
    slwi	r6, r8, 0xf
    xor	r4, r8, r4
    slwi	r7, r8, 0x17
    xor	r4, r6, r4
    eqv	r4, r7, r4
    rlwinm	r9, r4, 2, 0x1e, 0x1e
    rlwimi	r9, r8, 1, 0, 0x1d
    slwi	r4, r9, 7
    slwi	r6, r9, 0xf
    xor	r4, r9, r4
    slwi	r7, r9, 0x17
    xor	r4, r6, r4
    eqv	r4, r7, r4
    rlwinm	r8, r4, 2, 0x1e, 0x1e
    rlwimi	r8, r9, 1, 0, 0x1d
    slwi	r4, r8, 7
    slwi	r6, r8, 0xf
    xor	r4, r8, r4
    slwi	r7, r8, 0x17
    xor	r4, r6, r4
    eqv	r4, r7, r4
    rlwinm	r9, r4, 2, 0x1e, 0x1e
    rlwimi	r9, r8, 1, 0, 0x1d
    slwi	r4, r9, 7
    slwi	r6, r9, 0xf
    xor	r4, r9, r4
    slwi	r7, r9, 0x17
    xor	r4, r6, r4
    eqv	r4, r7, r4
    rlwinm	r8, r4, 2, 0x1e, 0x1e
    rlwimi	r8, r9, 1, 0, 0x1d
    slwi	r4, r8, 7
    slwi	r6, r8, 0xf
    xor	r4, r8, r4
    slwi	r7, r8, 0x17
    xor	r4, r6, r4
    eqv	r4, r7, r4
    rlwinm	r4, r4, 2, 0x1e, 0x1e
    rlwimi	r4, r8, 1, 0, 0x1d
    addi	r3, r3, 8
    bdnz    _8002b868
    subfic	r6, r3, 0x21
    cmplwi	r3, 0x21
    mtctr	r6
    bge     _8002b9ac
_8002b984:
    slwi	r3, r4, 7
    slwi	r6, r4, 0xf
    xor	r3, r4, r3
    slwi	r7, r4, 0x17
    xor	r3, r6, r3
    eqv	r3, r7, r3
    slwi	r4, r4, 1
    rlwinm	r3, r3, 2, 0x1e, 0x1e
    or	r4, r4, r3
    bdnz    _8002b984
_8002b9ac:
    slwi	r3, r4, 7
    slwi	r6, r4, 0xf
    xor	r3, r4, r3
    slwi	r7, r4, 0x17
    xor	r3, r6, r3
    eqv	r3, r7, r3
    srwi	r3, r3, 0x1f
    or	r3, r4, r3
    stw	r3, 0x2c(r31)
    li	r6, 8
    li	r27, 0
    stw	r0, 0(r28)
    addi	r3, r28, 0
    li	r4, 8
    stw	r5, 4(r28)
    stw	r28, 0(r29)
    stw	r6, 4(r29)
    stw	r22, 0xc(r29)
    stw	r27, 8(r29)
    bl      DCFlushRange
    addi	r3, r22, 0
    li	r4, 4
    bl      DCInvalidateRange
    addi	r3, r29, 0
    li	r4, 0x10
    bl      DCFlushRange
    li	r0, 0xff
    lis     r3, card_unlock_dsp_cmd_data@ha
    stw	r0, 4(r30)
    addi	r3, r3, card_unlock_dsp_cmd_data@l
    addis	r0, r3, -0x8000
    stw	r0, 0xc(r30)
    li	r0, 0x160
    lis     r4, UnlockSendDspMail@ha
    stw	r0, 0x10(r30)
    lis     r3, __CARDUnlockInitCallback@ha
    li	r5, 0x10
    stw	r27, 0x14(r30)
    addi	r4, r4, UnlockSendDspMail@l
    addi	r0, r3, __CARDUnlockInitCallback@l
    sth	r5, 0x24(r30)
    mr	r3, r30
    stw	r4, 0x28(r30)
    stw	r27, 0x2c(r30)
    stw	r0, 0x30(r30)
    stw	r27, 0x34(r30)
    bl      DSPAddTask
    stw	r25, 0(r23)
    li	r3, 0
    stw	r26, 4(r23)
    stw	r24, 8(r23)
_8002ba78:
    lmw	r22, 0xf8(r1)
    lwz	r0, 0x124(r1)
    addi	r1, r1, 0x120
    mtlr	r0
    blr	
}

asm void UnlockSendDspMail(void)
{
    nofralloc
    mflr	r0
    lis     r4, __CARDBlock@ha
    stw	r0, 4(r1)
    addi	r4, r4, __CARDBlock@l
    addi	r0, r4, 0x30
    stwu	r1, -0x18(r1)
    cmplw	r0, r3
    stw	r31, 0x14(r1)
    beq     _8002babc
    addi	r0, r4, 0x140
    cmplw	r0, r3
    addi	r4, r4, 0x110
_8002babc:
    lwz	r31, 0x80(r4)
    lis	r3, -0x100
    bl      DSPSendMailToDSP
_8002bac8:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002bac8
    mr	r3, r31
    bl      DSPSendMailToDSP
_8002badc:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002badc
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __CARDUnlockInitCallback(void)
{
    nofralloc
    mflr	r0
    lis     r4, __CARDBlock@ha
    stw	r0, 4(r1)
    addi	r4, r4, __CARDBlock@l
    addi	r0, r4, 0x30
    stwu	r1, -0x88(r1)
    cmplw	r0, r3
    stw	r31, 0x84(r1)
    li	r31, 0
    stw	r30, 0x80(r1)
    stw	r29, 0x7c(r1)
    addi	r29, r4, 0
    stw	r28, 0x78(r1)
    beq     _8002bb50
    addi	r0, r4, 0x140
    cmplw	r0, r3
    addi	r4, r4, 0x110
    addi	r29, r4, 0
    li	r31, 1
    beq     _8002bb50
    li	r31, 2
_8002bb50:
    lwz	r3, 0x80(r29)
    addi	r0, r3, 0x2f
    rlwinm	r3, r0, 0, 0, 0x1a
    lwz	r30, 0x20(r3)
    bl      GetInitVal
    lwz	r0, 0x2c(r29)
    addi	r28, r3, 0
    addi	r6, r28, 0
    xor	r0, r30, r0
    rlwinm	r4, r0, 0, 0, 0xf
    addi	r3, r31, 0
    addi	r5, r1, 0x34
    li	r7, 1
    bl      ReadArrayUnlock
    cmpwi	r3, 0
    bge     _8002bba8
    mr	r3, r31
    bl      EXIUnlock
    addi	r3, r31, 0
    li	r4, -3
    bl      __CARDMountCallback
    b       _8002be00
_8002bba8:
    lwz	r4, 0x14(r29)
    li	r3, 0
    lwz	r0, 0x2c(r29)
    add	r4, r28, r4
    addi	r4, r4, 4
    slwi	r4, r4, 3
    addi	r4, r4, 1
    cmplwi	r4, 0
    ble     _8002bd30
    cmplwi	r4, 8
    addi	r6, r4, -8
    ble     _8002bcf8
    addi	r5, r6, 7
    srwi	r5, r5, 3
    cmplwi	r6, 0
    mtctr	r5
    ble     _8002bcf8
_8002bbec:
    slwi	r5, r0, 7
    slwi	r6, r0, 0xf
    xor	r5, r0, r5
    xor	r5, r6, r5
    slwi	r7, r0, 0x17
    eqv	r5, r7, r5
    slwi	r6, r0, 1
    rlwinm	r0, r5, 2, 0x1e, 0x1e
    or	r7, r6, r0
    slwi	r0, r7, 7
    slwi	r5, r7, 0xf
    xor	r0, r7, r0
    slwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r8, r0, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r0, r8, 7
    slwi	r5, r8, 0xf
    xor	r0, r8, r0
    slwi	r6, r8, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r7, r0, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r0, r7, 7
    slwi	r5, r7, 0xf
    xor	r0, r7, r0
    slwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r8, r0, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r0, r8, 7
    slwi	r5, r8, 0xf
    xor	r0, r8, r0
    slwi	r6, r8, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r7, r0, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r0, r7, 7
    slwi	r5, r7, 0xf
    xor	r0, r7, r0
    slwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r8, r0, 2, 0x1e, 0x1e
    rlwimi	r8, r7, 1, 0, 0x1d
    slwi	r0, r8, 7
    slwi	r5, r8, 0xf
    xor	r0, r8, r0
    slwi	r6, r8, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r7, r0, 2, 0x1e, 0x1e
    rlwimi	r7, r8, 1, 0, 0x1d
    slwi	r0, r7, 7
    slwi	r5, r7, 0xf
    xor	r0, r7, r0
    slwi	r6, r7, 0x17
    xor	r0, r5, r0
    eqv	r0, r6, r0
    rlwinm	r0, r0, 2, 0x1e, 0x1e
    rlwimi	r0, r7, 1, 0, 0x1d
    addi	r3, r3, 8
    bdnz    _8002bbec
_8002bcf8:
    subf	r5, r3, r4
    cmplw	r3, r4
    mtctr	r5
    bge     _8002bd30
_8002bd08:
    slwi	r3, r0, 7
    slwi	r4, r0, 0xf
    xor	r3, r0, r3
    slwi	r5, r0, 0x17
    xor	r3, r4, r3
    eqv	r3, r5, r3
    slwi	r4, r0, 1
    rlwinm	r0, r3, 2, 0x1e, 0x1e
    or	r0, r4, r0
    bdnz    _8002bd08
_8002bd30:
    slwi	r3, r0, 7
    slwi	r4, r0, 0xf
    xor	r3, r0, r3
    slwi	r5, r0, 0x17
    xor	r3, r4, r3
    eqv	r3, r5, r3
    srwi	r3, r3, 0x1f
    or	r0, r0, r3
    stw	r0, 0x2c(r29)
    bl      GetInitVal
    lwz	r0, 0x2c(r29)
    slwi	r4, r30, 0x10
    addi	r6, r3, 0
    xor	r0, r4, r0
    rlwinm	r4, r0, 0, 0, 0xf
    addi	r3, r31, 0
    addi	r5, r1, 0x34
    li	r7, 1
    bl      ReadArrayUnlock
    cmpwi	r3, 0
    bge     _8002bd9c
    mr	r3, r31
    bl      EXIUnlock
    addi	r3, r31, 0
    li	r4, -3
    bl      __CARDMountCallback
    b       _8002be00
_8002bd9c:
    addi	r3, r31, 0
    addi	r4, r1, 0x30
    bl      __CARDReadStatus
    addi	r28, r3, 0
    addi	r3, r31, 0
    bl      EXIProbe
    cmpwi	r3, 0
    bne     _8002bdd4
    mr	r3, r31
    bl      EXIUnlock
    addi	r3, r31, 0
    li	r4, -3
    bl      __CARDMountCallback
    b       _8002be00
_8002bdd4:
    cmpwi	r28, 0
    bne     _8002bdf4
    lbz	r0, 0x30(r1)
    rlwinm.	r0, r0, 0, 0x19, 0x19
    bne     _8002bdf4
    mr	r3, r31
    bl      EXIUnlock
    li	r28, -5
_8002bdf4:
    addi	r3, r31, 0
    addi	r4, r28, 0
    bl      __CARDMountCallback
_8002be00:
    lwz	r0, 0x8c(r1)
    lwz	r31, 0x84(r1)
    lwz	r30, 0x80(r1)
    lwz	r29, 0x7c(r1)
    lwz	r28, 0x78(r1)
    addi	r1, r1, 0x88
    mtlr	r0
    blr	
}

asm void __CARDBlockReadCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, 0
    lis     r3, __CARDBlock@ha
    stw	r30, 0x18(r1)
    mulli	r5, r31, 0x110
    stw	r29, 0x14(r1)
    addi	r0, r3, __CARDBlock@l
    or.	r29, r4, r4
    add	r30, r0, r5
    blt     _8002bea0
    lwz	r3, 0xb8(r30)
    addi	r0, r3, 0x200
    stw	r0, 0xb8(r30)
    lwz	r3, 0xb0(r30)
    addi	r0, r3, 0x200
    stw	r0, 0xb0(r30)
    lwz	r3, 0xb4(r30)
    addi	r0, r3, 0x200
    stw	r0, 0xb4(r30)
    lwz	r3, 0xac(r30)
    addic.	r0, r3, -1
    stw	r0, 0xac(r30)
    ble     _8002bea0
    lis     r3, __CARDBlockReadCallback@ha
    addi	r4, r3, __CARDBlockReadCallback@l
    addi	r3, r31, 0
    bl      __CARDReadSegment
    or.	r29, r3, r3
    bge     _8002bee0
_8002bea0:
    lwz	r0, 0xd0(r30)
    cmplwi	r0, 0
    bne     _8002beb8
    addi	r3, r30, 0
    addi	r4, r29, 0
    bl      __CARDPutControlBlock
_8002beb8:
    lwz	r0, 0xd4(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _8002bee0
    li	r0, 0
    mtlr	r12
    stw	r0, 0xd4(r30)
    addi	r3, r31, 0
    addi	r4, r29, 0
    blrl	
_8002bee0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDRead(void)
{
    nofralloc
    mflr	r0
    mulli	r9, r3, 0x110
    stw	r0, 4(r1)
    lis     r8, __CARDBlock@ha
    stwu	r1, -8(r1)
    addi	r0, r8, __CARDBlock@l
    add	r8, r0, r9
    lwz	r0, 0(r8)
    cmpwi	r0, 0
    bne     _8002bf2c
    li	r3, -3
    b       _8002bf50
_8002bf2c:
    stw	r7, 0xd4(r8)
    srwi	r0, r5, 9
    lis     r5, __CARDBlockReadCallback@ha
    stw	r0, 0xac(r8)
    addi	r0, r5, __CARDBlockReadCallback@l
    stw	r4, 0xb0(r8)
    mr	r4, r0
    stw	r6, 0xb4(r8)
    bl      __CARDReadSegment
_8002bf50:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void __CARDBlockWriteCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, 0
    lis     r3, __CARDBlock@ha
    stw	r30, 0x18(r1)
    mulli	r5, r31, 0x110
    stw	r29, 0x14(r1)
    addi	r0, r3, __CARDBlock@l
    or.	r29, r4, r4
    add	r30, r0, r5
    blt     _8002bfe0
    lwz	r3, 0xb8(r30)
    addi	r0, r3, 0x80
    stw	r0, 0xb8(r30)
    lwz	r3, 0xb0(r30)
    addi	r0, r3, 0x80
    stw	r0, 0xb0(r30)
    lwz	r3, 0xb4(r30)
    addi	r0, r3, 0x80
    stw	r0, 0xb4(r30)
    lwz	r3, 0xac(r30)
    addic.	r0, r3, -1
    stw	r0, 0xac(r30)
    ble     _8002bfe0
    lis     r3, __CARDBlockWriteCallback@ha
    addi	r4, r3, __CARDBlockWriteCallback@l
    addi	r3, r31, 0
    bl      __CARDWritePage
    or.	r29, r3, r3
    bge     _8002c020
_8002bfe0:
    lwz	r0, 0xd0(r30)
    cmplwi	r0, 0
    bne     _8002bff8
    addi	r3, r30, 0
    addi	r4, r29, 0
    bl      __CARDPutControlBlock
_8002bff8:
    lwz	r0, 0xd4(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _8002c020
    li	r0, 0
    mtlr	r12
    stw	r0, 0xd4(r30)
    addi	r3, r31, 0
    addi	r4, r29, 0
    blrl	
_8002c020:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDWrite(void)
{
    nofralloc
    mflr	r0
    mulli	r9, r3, 0x110
    stw	r0, 4(r1)
    lis     r8, __CARDBlock@ha
    stwu	r1, -8(r1)
    addi	r0, r8, __CARDBlock@l
    add	r8, r0, r9
    lwz	r0, 0(r8)
    cmpwi	r0, 0
    bne     _8002c06c
    li	r3, -3
    b       _8002c090
_8002c06c:
    stw	r7, 0xd4(r8)
    srwi	r0, r5, 7
    lis     r5, __CARDBlockWriteCallback@ha
    stw	r0, 0xac(r8)
    addi	r0, r5, __CARDBlockWriteCallback@l
    stw	r4, 0xb0(r8)
    mr	r4, r0
    stw	r6, 0xb4(r8)
    bl      __CARDWritePage
_8002c090:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
    mulli	r0, r3, 0x110
    lis     r3, __CARDBlock@ha
    addi	r3, r3, __CARDBlock@l
    add	r3, r3, r0
    lwz	r3, 0xb8(r3)
    blr	
}

asm void __CARDGetFatBlock(void)
{
    nofralloc
    lwz	r3, 0x88(r3)
    blr	
}

asm void __CARDBlockWriteCallback2(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    or.	r30, r4, r4
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    mulli	r5, r29, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    blt     _8002c138
    lwz	r3, 0x80(r31)
    lwz	r0, 0x88(r31)
    addi	r4, r3, 0x6000
    cmplw	r0, r4
    addis	r5, r3, 1
    addi	r5, r5, -0x8000
    bne     _8002c124
    stw	r5, 0x88(r31)
    addi	r3, r5, 0
    li	r5, 0x2000
    bl      memcpy
    b       _8002c138
_8002c124:
    stw	r4, 0x88(r31)
    addi	r3, r4, 0
    addi	r4, r5, 0
    li	r5, 0x2000
    bl      memcpy
_8002c138:
    lwz	r0, 0xd0(r31)
    cmplwi	r0, 0
    bne     _8002c150
    addi	r3, r31, 0
    addi	r4, r30, 0
    bl      __CARDPutControlBlock
_8002c150:
    lwz	r0, 0xd8(r31)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _8002c178
    li	r0, 0
    mtlr	r12
    stw	r0, 0xd8(r31)
    addi	r3, r29, 0
    addi	r4, r30, 0
    blrl	
_8002c178:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDBlockEraseCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r3, 0
    lis     r3, __CARDBlock@ha
    stw	r30, 0x20(r1)
    mulli	r5, r31, 0x110
    stw	r29, 0x1c(r1)
    addi	r0, r3, __CARDBlock@l
    or.	r29, r4, r4
    add	r30, r0, r5
    blt     _8002c200
    lwz	r5, 0x88(r30)
    lis     r3, __CARDBlockWriteCallback2@ha
    lwz	r0, 0x80(r30)
    addi	r7, r3, __CARDBlockWriteCallback2@l
    lwz	r3, 0xc(r30)
    subf	r0, r0, r5
    srwi	r0, r0, 0xd
    mullw	r4, r3, r0
    addi	r6, r5, 0
    addi	r3, r31, 0
    li	r5, 0x2000
    bl      __CARDWrite
    or.	r29, r3, r3
    bge     _8002c240
_8002c200:
    lwz	r0, 0xd0(r30)
    cmplwi	r0, 0
    bne     _8002c218
    addi	r3, r30, 0
    addi	r4, r29, 0
    bl      __CARDPutControlBlock
_8002c218:
    lwz	r0, 0xd8(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _8002c240
    li	r0, 0
    mtlr	r12
    stw	r0, 0xd8(r30)
    addi	r3, r31, 0
    addi	r4, r29, 0
    blrl	
_8002c240:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __CARDAllocBlock(void)
{
    nofralloc
    mflr	r0
    mulli	r7, r3, 0x110
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    lis     r6, __CARDBlock@ha
    addi	r0, r6, __CARDBlock@l
    stw	r31, 0x1c(r1)
    add	r9, r0, r7
    stw	r30, 0x18(r1)
    lwz	r0, 0(r9)
    cmpwi	r0, 0
    bne     _8002c294
    li	r3, -3
    b       _8002c35c
_8002c294:
    lwz	r8, 0x88(r9)
    lhz	r0, 6(r8)
    cmplw	r0, r4
    bge     _8002c2ac
    li	r3, -9
    b       _8002c35c
_8002c2ac:
    subf	r0, r4, r0
    sth	r0, 6(r8)
    lis	r6, 1
    addi	r12, r6, -1
    lhz	r11, 8(r8)
    addi	r0, r12, 0
    li	r30, 0
    b       _8002c344
_8002c2cc:
    lhz	r10, 0x10(r9)
    addi	r30, r30, 1
    clrlwi	r6, r30, 0x10
    addi	r7, r10, -5
    cmpw	r7, r6
    bge     _8002c2ec
    li	r3, -6
    b       _8002c35c
_8002c2ec:
    addi	r11, r11, 1
    clrlwi	r6, r11, 0x10
    cmplwi	r6, 5
    blt     _8002c304
    cmplw	r6, r10
    blt     _8002c308
_8002c304:
    li	r11, 5
_8002c308:
    rlwinm	r6, r11, 1, 0xf, 0x1e
    add	r7, r8, r6
    lhz	r6, 0(r7)
    cmplwi	r6, 0
    bne     _8002c344
    clrlwi	r6, r12, 0x10
    cmplwi	r6, 0xffff
    bne     _8002c330
    mr	r12, r11
    b       _8002c338
_8002c330:
    rlwinm	r6, r31, 1, 0xf, 0x1e
    sthx	r11, r8, r6
_8002c338:
    sth	r0, 0(r7)
    addi	r31, r11, 0
    addi	r4, r4, -1
_8002c344:
    cmplwi	r4, 0
    bne     _8002c2cc
    sth	r11, 8(r8)
    mr	r4, r8
    sth	r12, 0xbe(r9)
    bl      __CARDUpdateFatBlock
_8002c35c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDFreeBlock(void)
{
    nofralloc
    mflr	r0
    mulli	r7, r3, 0x110
    stw	r0, 4(r1)
    lis     r6, __CARDBlock@ha
    stwu	r1, -8(r1)
    addi	r0, r6, __CARDBlock@l
    add	r9, r0, r7
    lwz	r0, 0(r9)
    cmpwi	r0, 0
    bne     _8002c3a4
    li	r3, -3
    b       _8002c400
_8002c3a4:
    lwz	r8, 0x88(r9)
    li	r7, 0
    b       _8002c3ec
_8002c3b0:
    clrlwi	r4, r4, 0x10
    cmplwi	r4, 5
    blt     _8002c3c8
    lhz	r0, 0x10(r9)
    cmplw	r4, r0
    blt     _8002c3d0
_8002c3c8:
    li	r3, -6
    b       _8002c400
_8002c3d0:
    slwi	r0, r4, 1
    add	r6, r8, r0
    lhz	r4, 0(r6)
    sth	r7, 0(r6)
    lhz	r6, 6(r8)
    addi	r0, r6, 1
    sth	r0, 6(r8)
_8002c3ec:
    clrlwi	r0, r4, 0x10
    cmplwi	r0, 0xffff
    bne     _8002c3b0
    mr	r4, r8
    bl      __CARDUpdateFatBlock
_8002c400:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void __CARDUpdateFatBlock(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    addi	r30, r5, 0
    stw	r29, 0x1c(r1)
    addi	r29, r4, 0
    addi	r5, r29, 0
    stw	r28, 0x18(r1)
    addi	r28, r3, 0
    addi	r6, r29, 2
    lhz	r3, 4(r4)
    mulli	r4, r28, 0x110
    addi	r0, r3, 1
    lis     r3, __CARDBlock@ha
    sth	r0, 4(r29)
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r4
    addi	r3, r29, 4
    li	r4, 0x1ffc
    bl      __CARDCheckSum
    addi	r3, r29, 0
    li	r4, 0x2000
    bl      DCStoreRange
    stw	r30, 0xd8(r31)
    lis     r3, __CARDBlockEraseCallback@ha
    addi	r5, r3, __CARDBlockEraseCallback@l
    lwz	r0, 0x80(r31)
    mr	r3, r28
    lwz	r4, 0xc(r31)
    subf	r0, r0, r29
    srwi	r0, r0, 0xd
    mullw	r4, r4, r0
    bl      __CARDEraseSector
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    lwz	r28, 0x18(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __CARDGetDirBlock(void)
{
    nofralloc
    lwz	r3, 0x84(r3)
    blr	
}

asm void __CARDDirWriteCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    or.	r30, r4, r4
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    mulli	r5, r29, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    blt     _8002c538
    lwz	r3, 0x80(r31)
    lwz	r0, 0x84(r31)
    addi	r4, r3, 0x2000
    cmplw	r0, r4
    addi	r0, r3, 0x4000
    bne     _8002c524
    stw	r0, 0x84(r31)
    mr	r3, r0
    li	r5, 0x2000
    bl      memcpy
    b       _8002c538
_8002c524:
    stw	r4, 0x84(r31)
    addi	r3, r4, 0
    mr	r4, r0
    li	r5, 0x2000
    bl      memcpy
_8002c538:
    lwz	r0, 0xd0(r31)
    cmplwi	r0, 0
    bne     _8002c550
    addi	r3, r31, 0
    addi	r4, r30, 0
    bl      __CARDPutControlBlock
_8002c550:
    lwz	r0, 0xd8(r31)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _8002c578
    li	r0, 0
    mtlr	r12
    stw	r0, 0xd8(r31)
    addi	r3, r29, 0
    addi	r4, r30, 0
    blrl	
_8002c578:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDDirEraseCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r3, 0
    lis     r3, __CARDBlock@ha
    stw	r30, 0x20(r1)
    mulli	r5, r31, 0x110
    stw	r29, 0x1c(r1)
    addi	r0, r3, __CARDBlock@l
    or.	r29, r4, r4
    add	r30, r0, r5
    blt     _8002c600
    lwz	r5, 0x84(r30)
    lis     r3, __CARDDirWriteCallback@ha
    lwz	r0, 0x80(r30)
    addi	r7, r3, __CARDDirWriteCallback@l
    lwz	r3, 0xc(r30)
    subf	r0, r0, r5
    srwi	r0, r0, 0xd
    mullw	r4, r3, r0
    addi	r6, r5, 0
    addi	r3, r31, 0
    li	r5, 0x2000
    bl      __CARDWrite
    or.	r29, r3, r3
    bge     _8002c640
_8002c600:
    lwz	r0, 0xd0(r30)
    cmplwi	r0, 0
    bne     _8002c618
    addi	r3, r30, 0
    addi	r4, r29, 0
    bl      __CARDPutControlBlock
_8002c618:
    lwz	r0, 0xd8(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _8002c640
    li	r0, 0
    mtlr	r12
    stw	r0, 0xd8(r30)
    addi	r3, r31, 0
    addi	r4, r29, 0
    blrl	
_8002c640:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __CARDUpdateDir(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    addi	r29, r4, 0
    stw	r28, 0x18(r1)
    addi	r28, r3, 0
    mulli	r5, r28, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r30, r0, r5
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    bne     _8002c6a4
    li	r3, -3
    b       _8002c700
_8002c6a4:
    lwz	r31, 0x84(r30)
    li	r4, 0x1ffc
    lha	r5, 0x1ffa(r31)
    addi	r6, r31, 0x1fc0
    addi	r3, r31, 0
    addi	r0, r5, 1
    sth	r0, 0x1ffa(r31)
    addi	r5, r6, 0x3c
    addi	r6, r6, 0x3e
    bl      __CARDCheckSum
    addi	r3, r31, 0
    li	r4, 0x2000
    bl      DCStoreRange
    stw	r29, 0xd8(r30)
    lis     r3, __CARDDirEraseCallback@ha
    addi	r5, r3, __CARDDirEraseCallback@l
    lwz	r0, 0x80(r30)
    mr	r3, r28
    lwz	r4, 0xc(r30)
    subf	r0, r0, r31
    srwi	r0, r0, 0xd
    mullw	r4, r4, r0
    bl      __CARDEraseSector
_8002c700:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    lwz	r28, 0x18(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __CARDCheckSum(void)
{
    nofralloc
    li	r0, 0
    srawi	r4, r4, 1
    sth	r0, 0(r6)
    addze.	r4, r4
    sth	r0, 0(r5)
    ble     _8002c8a4
    rlwinm.	r0, r4, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _8002c874
_8002c744:
    lhz	r7, 0(r5)
    lhz	r0, 0(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 0(r3)
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    lhz	r7, 0(r5)
    lhz	r0, 2(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 2(r3)
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    lhz	r7, 0(r5)
    lhz	r0, 4(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 4(r3)
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    lhz	r7, 0(r5)
    lhz	r0, 6(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 6(r3)
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    lhz	r7, 0(r5)
    lhz	r0, 8(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 8(r3)
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    lhz	r7, 0(r5)
    lhz	r0, 0xa(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 0xa(r3)
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    lhz	r7, 0(r5)
    lhz	r0, 0xc(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 0xc(r3)
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    lhz	r7, 0(r5)
    lhz	r0, 0xe(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 0xe(r3)
    addi	r3, r3, 0x10
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    bdnz    _8002c744
    andi.	r4, r4, 7
    beq     _8002c8a4
_8002c874:
    mtctr	r4
_8002c878:
    lhz	r7, 0(r5)
    lhz	r0, 0(r3)
    add	r0, r7, r0
    sth	r0, 0(r5)
    lhz	r0, 0(r3)
    addi	r3, r3, 2
    lhz	r7, 0(r6)
    nor	r0, r0, r0
    add	r0, r7, r0
    sth	r0, 0(r6)
    bdnz    _8002c878
_8002c8a4:
    lhz	r0, 0(r5)
    cmplwi	r0, 0xffff
    bne     _8002c8b8
    li	r0, 0
    sth	r0, 0(r5)
_8002c8b8:
    lhz	r0, 0(r6)
    cmplwi	r0, 0xffff
    bnelr	
    li	r0, 0
    sth	r0, 0(r6)
    blr	
}

#pragma pop
