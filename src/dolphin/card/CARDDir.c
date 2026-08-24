// dolphin/card/CARDDir.c -- tail of coarse/text_80029828 (0x8002C8D0-0x8002EED8).
// Melee identity: sram CRC, dir writeback, DoMount/Mount/Unmount, filename helpers.
#pragma push
#pragma force_active on

extern void fn_8002C8D0(void);
extern void VerifyDir(void);
extern void VerifyFAT(void);
extern void __CARDVerify(void);
extern void CARDCheckExAsync(void);
extern void CARDCheckAsync(void);
extern void CARDCheck(void);
extern void fn_8002D6B0(void);
extern void fn_8002D77C(void);
extern void fn_8002D8F8(void);
extern void fn_8002DD08(void);
extern void fn_8002DE40(void);
extern void CARDMount(void);
extern void fn_8002E028(void);
extern void fn_8002E0C4(void);
extern void fn_8002E170(void);
extern unsigned char __CARDBlock[544];
extern void __CARDSyncCallback(int chn);
extern void fn_80029824(void);
extern void fn_80029AF4(int chn);
extern void __CARDExiHandler(int chn, void* ctx);
extern void __CARDExtHandler(int chn, void* ctx);
extern unsigned char card_sector_size_table[32];
extern unsigned char card_block_count_table[32];
extern unsigned char lbl_80177B80[32];

extern void fn_8002E2B4(void);
extern void CARDFormatAsync(void);
extern void __CARDCompareFileName(void);
extern void __CARDAccess(void);
extern void fn_8002EA54(void);
extern void __CARDGetFileNo(void);
extern void CARDOpen(void);
extern void CARDClose(void);
extern void CreateCallbackFat(void);
extern void CARDCreateAsync(void);
extern void DCInvalidateRange(void);
extern void DCStoreRange(void);
extern void EXIAttach(void);
extern void EXIDetach(void);
extern void EXIGetID(void);
extern void EXIGetState(void);
extern void EXILock(void);
extern void EXIProbe(void);
extern void EXIProbeEx(void);
extern void EXISetExiCallback(void);
extern void EXIUnlock(void);
extern void OSCancelAlarm(void);
extern void OSDisableInterrupts(void);
extern void OSGetTime(void);
extern void OSRestoreInterrupts(void);
extern void __OSLockSram(void);
extern void __OSLockSramEx(void);
extern void __OSUnlockSramEx(void);
extern void __shr2i(void);
extern void __OSUnlockSram(void);
extern void __CARDReadNintendoID(void);
extern void __CARDReadStatus(void);
extern void __CARDClearStatus(void);
extern void __CARDEraseSector(void);
extern void fn_8002A744(void);
extern void __CARDGetControlBlock(void);
extern void __CARDPutControlBlock(void);
extern void __CARDSync(void);
extern void __CARDUnlock(void);
extern void __CARDRead(void);
extern void __CARDWrite(void);
extern void __CARDGetFatBlock(void);
extern void __CARDAllocBlock(void);
extern void __CARDUpdateFatBlock(void);
extern void __CARDGetDirBlock(void);
extern void __CARDUpdateDir(void);
extern void __CARDCheckSum(void);
extern void __div2i(void);
extern void strncmp(void);
extern void strncpy(void);
extern void strlen(void);
extern void memcpy(void);
extern void memset(void);

asm void fn_8002C8D0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stmw	r25, 0x14(r1)
    mr	r26, r3
    lwz	r3, 0x80(r3)
    lhz	r0, 0x20(r3)
    addi	r27, r3, 0
    cmplwi	r0, 0
    bne     _8002c908
    lhz	r3, 0x22(r27)
    lhz	r0, 8(r26)
    cmplw	r3, r0
    beq     _8002c910
_8002c908:
    li	r3, -6
    b       _8002cb40
_8002c910:
    li	r0, 0x1fc
    srawi	r0, r0, 1
    addze.	r0, r0
    addi	r4, r27, 0
    li	r7, 0
    mr	r3, r0
    li	r6, 0
    ble     _8002c9e8
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _8002c9cc
_8002c93c:
    lhz	r5, 0(r4)
    nor	r0, r5, r5
    add	r6, r6, r5
    lhz	r5, 2(r4)
    add	r7, r7, r0
    nor	r0, r5, r5
    add	r6, r6, r5
    lhz	r5, 4(r4)
    add	r7, r7, r0
    nor	r0, r5, r5
    add	r6, r6, r5
    lhz	r5, 6(r4)
    add	r7, r7, r0
    nor	r0, r5, r5
    add	r6, r6, r5
    lhz	r5, 8(r4)
    add	r7, r7, r0
    nor	r0, r5, r5
    add	r6, r6, r5
    lhz	r5, 0xa(r4)
    add	r7, r7, r0
    nor	r0, r5, r5
    add	r6, r6, r5
    lhz	r5, 0xc(r4)
    add	r7, r7, r0
    nor	r0, r5, r5
    add	r6, r6, r5
    lhz	r5, 0xe(r4)
    add	r7, r7, r0
    nor	r0, r5, r5
    add	r6, r6, r5
    add	r7, r7, r0
    addi	r4, r4, 0x10
    bdnz    _8002c93c
    andi.	r3, r3, 7
    beq     _8002c9e8
_8002c9cc:
    mtctr	r3
_8002c9d0:
    lhz	r5, 0(r4)
    addi	r4, r4, 2
    nor	r0, r5, r5
    add	r6, r6, r5
    add	r7, r7, r0
    bdnz    _8002c9d0
_8002c9e8:
    clrlwi	r0, r6, 0x10
    cmplwi	r0, 0xffff
    bne     _8002c9f8
    li	r6, 0
_8002c9f8:
    clrlwi	r0, r7, 0x10
    cmplwi	r0, 0xffff
    bne     _8002ca08
    li	r7, 0
_8002ca08:
    lhz	r3, 0x1fc(r27)
    clrlwi	r0, r6, 0x10
    cmplw	r3, r0
    bne     _8002ca28
    lhz	r3, 0x1fe(r27)
    clrlwi	r0, r7, 0x10
    cmplw	r3, r0
    beq     _8002ca30
_8002ca28:
    li	r3, -6
    b       _8002cb40
_8002ca30:
    lwz	r31, 0xc(r27)
    lwz	r28, 0x10(r27)
    bl      __OSLockSramEx
    lis     r4, __CARDBlock@ha
    addi	r0, r4, __CARDBlock@l
    lis	r4, 0x7878
    subf	r0, r0, r26
    addi	r4, r4, 0x7879
    mulhw	r0, r4, r0
    srawi	r0, r0, 7
    srwi	r4, r0, 0x1f
    add	r0, r0, r4
    mulli	r0, r0, 0xc
    lis	r4, 0x41c6
    addi	r25, r27, 0
    add	r29, r3, r0
    addi	r30, r4, 0x4e6d
    li	r26, 0
_8002ca78:
    mullw	r5, r31, r30
    mulhwu	r3, r28, r30
    li	r31, 0
    add	r5, r5, r3
    mullw	r3, r28, r31
    mullw	r0, r28, r30
    li	r28, 0x3039
    addc	r4, r0, r28
    add	r0, r5, r3
    adde	r3, r0, r31
    li	r5, 0x10
    bl      __shr2i
    lbz	r0, 0(r29)
    lbz	r6, 0(r25)
    addc	r0, r4, r0
    clrlwi	r0, r0, 0x18
    cmplw	r6, r0
    beq     _8002cad0
    li	r3, 0
    bl      __OSUnlockSramEx
    li	r3, -6
    b       _8002cb40
_8002cad0:
    mullw	r5, r3, r30
    mulhwu	r3, r4, r30
    add	r5, r5, r3
    mullw	r3, r4, r31
    mullw	r0, r4, r30
    addc	r4, r0, r28
    add	r0, r5, r3
    adde	r3, r0, r31
    li	r5, 0x10
    bl      __shr2i
    addi	r26, r26, 1
    cmpwi	r26, 0xc
    li	r0, 0x7fff
    and	r28, r4, r0
    and	r31, r3, r31
    addi	r29, r29, 1
    addi	r25, r25, 1
    blt     _8002ca78
    li	r3, 0
    bl      __OSUnlockSramEx
    bl      fn_8002A744
    lhz	r0, 0x24(r27)
    clrlwi	r3, r3, 0x10
    cmplw	r0, r3
    beq     _8002cb3c
    li	r3, -0xd
    b       _8002cb40
_8002cb3c:
    li	r3, 0
_8002cb40:
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void VerifyDir(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stw	r31, 0x34(r1)
    addi	r7, r1, 0x1c
    addi	r8, r1, 0x14
    stw	r30, 0x30(r1)
    li	r31, 0
    li	r30, 0
    stw	r29, 0x2c(r1)
    addi	r29, r4, 0
    li	r4, 0
_8002cb84:
    addi	r0, r4, 1
    lwz	r5, 0x80(r3)
    slwi	r0, r0, 0xd
    add	r0, r5, r0
    stw	r0, 0(r7)
    li	r6, 0x1ffc
    srawi	r6, r6, 1
    lwz	r5, 0(r7)
    addze.	r6, r6
    li	r11, 0
    addi	r0, r5, 0x1fc0
    stw	r0, 0(r8)
    li	r10, 0
    lwz	r5, 0(r7)
    ble     _8002cc78
    rlwinm.	r0, r6, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _8002cc5c
_8002cbcc:
    lhz	r9, 0(r5)
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 2(r5)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 4(r5)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 6(r5)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 8(r5)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 0xa(r5)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 0xc(r5)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 0xe(r5)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    add	r11, r11, r0
    addi	r5, r5, 0x10
    bdnz    _8002cbcc
    andi.	r6, r6, 7
    beq     _8002cc78
_8002cc5c:
    mtctr	r6
_8002cc60:
    lhz	r9, 0(r5)
    addi	r5, r5, 2
    nor	r0, r9, r9
    add	r10, r10, r9
    add	r11, r11, r0
    bdnz    _8002cc60
_8002cc78:
    clrlwi	r0, r10, 0x10
    cmplwi	r0, 0xffff
    bne     _8002cc88
    li	r10, 0
_8002cc88:
    clrlwi	r0, r11, 0x10
    cmplwi	r0, 0xffff
    bne     _8002cc98
    li	r11, 0
_8002cc98:
    lwz	r6, 0(r8)
    clrlwi	r5, r10, 0x10
    lhz	r0, 0x3c(r6)
    cmplw	r5, r0
    bne     _8002ccbc
    lhz	r0, 0x3e(r6)
    clrlwi	r5, r11, 0x10
    cmplw	r5, r0
    beq     _8002cccc
_8002ccbc:
    li	r0, 0
    stw	r0, 0x84(r3)
    addi	r30, r4, 0
    addi	r31, r31, 1
_8002cccc:
    addi	r4, r4, 1
    cmpwi	r4, 2
    addi	r7, r7, 4
    addi	r8, r8, 4
    blt     _8002cb84
    cmpwi	r31, 0
    bne     _8002cd68
    lwz	r4, 0x84(r3)
    cmplwi	r4, 0
    bne     _8002cd4c
    lwz	r5, 0x18(r1)
    lwz	r4, 0x14(r1)
    lha	r5, 0x3a(r5)
    lha	r0, 0x3a(r4)
    subf.	r0, r5, r0
    bge     _8002cd14
    li	r30, 0
    b       _8002cd18
_8002cd14:
    li	r30, 1
_8002cd18:
    slwi	r0, r30, 2
    addi	r6, r1, 0x1c
    add	r6, r6, r0
    lwz	r4, 0(r6)
    xori	r0, r30, 1
    slwi	r0, r0, 2
    stw	r4, 0x84(r3)
    addi	r4, r1, 0x1c
    li	r5, 0x2000
    lwz	r3, 0(r6)
    lwzx	r4, r4, r0
    bl      memcpy
    b       _8002cd68
_8002cd4c:
    lwz	r0, 0x1c(r1)
    cmplw	r4, r0
    bne     _8002cd60
    li	r0, 0
    b       _8002cd64
_8002cd60:
    li	r0, 1
_8002cd64:
    mr	r30, r0
_8002cd68:
    cmplwi	r29, 0
    beq     _8002cd74
    stw	r30, 0(r29)
_8002cd74:
    mr	r3, r31
    lwz	r0, 0x3c(r1)
    lwz	r31, 0x34(r1)
    lwz	r30, 0x30(r1)
    lwz	r29, 0x2c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm void VerifyFAT(void)
{
    nofralloc
    mflr	r0
    li	r5, 0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    li	r31, 0
    stw	r30, 0x20(r1)
    li	r30, 0
    stw	r29, 0x1c(r1)
    addi	r29, r4, 0
    addi	r4, r1, 0x10
_8002cdc0:
    li	r8, 0x1ffc
    lwz	r6, 0x80(r3)
    addi	r0, r5, 3
    srawi	r8, r8, 1
    slwi	r0, r0, 0xd
    add	r7, r6, r0
    addze.	r8, r8
    stw	r7, 0(r4)
    addi	r6, r7, 4
    li	r11, 0
    li	r10, 0
    ble     _8002cea8
    rlwinm.	r0, r8, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _8002ce8c
_8002cdfc:
    lhz	r9, 0(r6)
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 2(r6)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 4(r6)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 6(r6)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 8(r6)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 0xa(r6)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 0xc(r6)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    lhz	r9, 0xe(r6)
    add	r11, r11, r0
    nor	r0, r9, r9
    add	r10, r10, r9
    add	r11, r11, r0
    addi	r6, r6, 0x10
    bdnz    _8002cdfc
    andi.	r8, r8, 7
    beq     _8002cea8
_8002ce8c:
    mtctr	r8
_8002ce90:
    lhz	r9, 0(r6)
    addi	r6, r6, 2
    nor	r0, r9, r9
    add	r10, r10, r9
    add	r11, r11, r0
    bdnz    _8002ce90
_8002cea8:
    clrlwi	r0, r10, 0x10
    cmplwi	r0, 0xffff
    bne     _8002ceb8
    li	r10, 0
_8002ceb8:
    clrlwi	r0, r11, 0x10
    cmplwi	r0, 0xffff
    bne     _8002cec8
    li	r11, 0
_8002cec8:
    lhz	r6, 0(r7)
    clrlwi	r0, r10, 0x10
    cmplw	r6, r0
    bne     _8002cee8
    lhz	r6, 2(r7)
    clrlwi	r0, r11, 0x10
    cmplw	r6, r0
    beq     _8002cefc
_8002cee8:
    li	r0, 0
    stw	r0, 0x88(r3)
    addi	r30, r5, 0
    addi	r31, r31, 1
    b       _8002cf54
_8002cefc:
    lhz	r8, 0x10(r3)
    addi	r6, r7, 0xa
    li	r10, 0
    li	r9, 5
    b       _8002cf28
_8002cf10:
    lhz	r0, 0(r6)
    cmplwi	r0, 0
    bne     _8002cf20
    addi	r10, r10, 1
_8002cf20:
    addi	r6, r6, 2
    addi	r9, r9, 1
_8002cf28:
    clrlwi	r0, r9, 0x10
    cmplw	r0, r8
    blt     _8002cf10
    lhz	r0, 6(r7)
    clrlwi	r6, r10, 0x10
    cmplw	r6, r0
    beq     _8002cf54
    li	r0, 0
    stw	r0, 0x88(r3)
    addi	r30, r5, 0
    addi	r31, r31, 1
_8002cf54:
    addi	r5, r5, 1
    cmpwi	r5, 2
    addi	r4, r4, 4
    blt     _8002cdc0
    cmpwi	r31, 0
    bne     _8002cfec
    lwz	r4, 0x88(r3)
    cmplwi	r4, 0
    bne     _8002cfd0
    lwz	r5, 0x14(r1)
    lwz	r4, 0x10(r1)
    lha	r5, 4(r5)
    lha	r0, 4(r4)
    subf.	r0, r5, r0
    bge     _8002cf98
    li	r30, 0
    b       _8002cf9c
_8002cf98:
    li	r30, 1
_8002cf9c:
    slwi	r0, r30, 2
    addi	r6, r1, 0x10
    add	r6, r6, r0
    lwz	r4, 0(r6)
    xori	r0, r30, 1
    slwi	r0, r0, 2
    stw	r4, 0x88(r3)
    addi	r4, r1, 0x10
    li	r5, 0x2000
    lwz	r3, 0(r6)
    lwzx	r4, r4, r0
    bl      memcpy
    b       _8002cfec
_8002cfd0:
    lwz	r0, 0x10(r1)
    cmplw	r4, r0
    bne     _8002cfe4
    li	r0, 0
    b       _8002cfe8
_8002cfe4:
    li	r0, 1
_8002cfe8:
    mr	r30, r0
_8002cfec:
    cmplwi	r29, 0
    beq     _8002cff8
    stw	r30, 0(r29)
_8002cff8:
    mr	r3, r31
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __CARDVerify(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      fn_8002C8D0
    cmpwi	r3, 0
    bge     _8002d040
    b       _8002d08c
_8002d040:
    addi	r3, r30, 0
    li	r4, 0
    bl      VerifyDir
    addi	r31, r3, 0
    addi	r3, r30, 0
    li	r4, 0
    bl      VerifyFAT
    add	r0, r31, r3
    cmpwi	r0, 1
    beq     _8002d080
    bge     _8002d088
    cmpwi	r0, 0
    bge     _8002d078
    b       _8002d088
_8002d078:
    li	r3, 0
    b       _8002d08c
_8002d080:
    li	r3, -6
    b       _8002d08c
_8002d088:
    li	r3, -6
_8002d08c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void CARDCheckExAsync(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x58(r1)
    stmw	r25, 0x3c(r1)
    or.	r26, r4, r4
    addi	r25, r3, 0
    addi	r27, r5, 0
    li	r30, 0
    li	r29, 0
    li	r28, 0
    beq     _8002d0d8
    li	r0, 0
    stw	r0, 0(r26)
_8002d0d8:
    addi	r3, r25, 0
    addi	r4, r1, 0x30
    bl      __CARDGetControlBlock
    cmpwi	r3, 0
    bge     _8002d0f0
    b       _8002d620
_8002d0f0:
    lwz	r3, 0x30(r1)
    bl      fn_8002C8D0
    or.	r4, r3, r3
    bge     _8002d10c
    lwz	r3, 0x30(r1)
    bl      __CARDPutControlBlock
    b       _8002d620
_8002d10c:
    lwz	r3, 0x30(r1)
    addi	r4, r1, 0x18
    bl      VerifyDir
    mr	r31, r3
    lwz	r3, 0x30(r1)
    addi	r4, r1, 0x1c
    bl      VerifyFAT
    add	r5, r31, r3
    cmpwi	r5, 1
    ble     _8002d144
    lwz	r3, 0x30(r1)
    li	r4, -6
    bl      __CARDPutControlBlock
    b       _8002d620
_8002d144:
    lwz	r6, 0x30(r1)
    lwz	r4, 0x80(r6)
    addi	r3, r4, 0x2000
    addi	r0, r4, 0x6000
    stw	r3, 0x28(r1)
    addis	r3, r4, 1
    addi	r4, r4, 0x4000
    stw	r0, 0x20(r1)
    addi	r0, r3, -0x8000
    stw	r4, 0x2c(r1)
    stw	r0, 0x24(r1)
    beq     _8002d17c
    bge     _8002d200
    b       _8002d200
_8002d17c:
    addi	r3, r6, 0x84
    lwz	r0, 0x84(r6)
    cmplwi	r0, 0
    bne     _8002d1c8
    lwz	r0, 0x18(r1)
    addi	r4, r1, 0x28
    li	r5, 0x2000
    slwi	r0, r0, 2
    lwzx	r0, r4, r0
    stw	r0, 0(r3)
    lwz	r3, 0x18(r1)
    xori	r0, r3, 1
    slwi	r3, r3, 2
    slwi	r0, r0, 2
    lwzx	r3, r4, r3
    lwzx	r4, r4, r0
    bl      memcpy
    li	r29, 1
    b       _8002d200
_8002d1c8:
    lwz	r0, 0x1c(r1)
    addi	r4, r1, 0x20
    li	r5, 0x2000
    slwi	r0, r0, 2
    lwzx	r0, r4, r0
    stw	r0, 0x88(r6)
    lwz	r3, 0x1c(r1)
    xori	r0, r3, 1
    slwi	r3, r3, 2
    slwi	r0, r0, 2
    lwzx	r3, r4, r3
    lwzx	r4, r4, r0
    bl      memcpy
    li	r30, 1
_8002d200:
    lwz	r0, 0x1c(r1)
    addi	r3, r1, 0x20
    li	r4, 0
    xori	r0, r0, 1
    slwi	r0, r0, 2
    lwzx	r31, r3, r0
    li	r5, 0x2000
    addi	r3, r31, 0
    bl      memset
    li	r0, 0x7f
    lwz	r5, 0x30(r1)
    mtctr	r0
    li	r6, 0
_8002d234:
    lwz	r0, 0x84(r5)
    add	r7, r0, r6
    lbz	r0, 0(r7)
    cmplwi	r0, 0xff
    beq     _8002d2ec
    lhz	r4, 0x36(r7)
    li	r8, 0
    b       _8002d2a4
_8002d254:
    clrlwi	r3, r4, 0x10
    cmplwi	r3, 5
    blt     _8002d288
    lhz	r0, 0x10(r5)
    cmplw	r3, r0
    bge     _8002d288
    slwi	r4, r3, 1
    lhzx	r3, r31, r4
    addi	r3, r3, 1
    clrlwi	r0, r3, 0x10
    sthx	r3, r31, r4
    cmplwi	r0, 1
    ble     _8002d298
_8002d288:
    lwz	r3, 0x30(r1)
    li	r4, -6
    bl      __CARDPutControlBlock
    b       _8002d620
_8002d298:
    lwz	r3, 0x88(r5)
    addi	r8, r8, 1
    lhzx	r4, r3, r4
_8002d2a4:
    clrlwi	r0, r4, 0x10
    cmplwi	r0, 0xffff
    beq     _8002d2c0
    lhz	r0, 0x38(r7)
    clrlwi	r3, r8, 0x10
    cmplw	r3, r0
    blt     _8002d254
_8002d2c0:
    lhz	r0, 0x38(r7)
    clrlwi	r3, r8, 0x10
    cmplw	r3, r0
    bne     _8002d2dc
    clrlwi	r0, r4, 0x10
    cmplwi	r0, 0xffff
    beq     _8002d2ec
_8002d2dc:
    lwz	r3, 0x30(r1)
    li	r4, -6
    bl      __CARDPutControlBlock
    b       _8002d620
_8002d2ec:
    addi	r6, r6, 0x40
    bdnz    _8002d234
    lwz	r3, 0x30(r1)
    addi	r6, r31, 0xa
    li	r9, 0
    li	r8, 5
    li	r5, 0xa
    b       _8002d370
_8002d30c:
    lwz	r4, 0x88(r3)
    lhz	r0, 0(r6)
    add	r4, r4, r5
    cmplwi	r0, 0
    lhz	r0, 0(r4)
    bne     _8002d340
    cmplwi	r0, 0
    beq     _8002d338
    li	r0, 0
    sth	r0, 0(r4)
    li	r28, 1
_8002d338:
    addi	r9, r9, 1
    b       _8002d364
_8002d340:
    cmplwi	r0, 5
    blt     _8002d350
    cmplw	r0, r7
    blt     _8002d364
_8002d350:
    cmplwi	r0, 0xffff
    beq     _8002d364
    li	r4, -6
    bl      __CARDPutControlBlock
    b       _8002d620
_8002d364:
    addi	r5, r5, 2
    addi	r6, r6, 2
    addi	r8, r8, 1
_8002d370:
    lhz	r7, 0x10(r3)
    clrlwi	r0, r8, 0x10
    cmplw	r0, r7
    blt     _8002d30c
    lwz	r3, 0x88(r3)
    clrlwi	r4, r9, 0x10
    lhzu	r0, 6(r3)
    cmplw	r4, r0
    beq     _8002d39c
    sth	r9, 0(r3)
    li	r28, 1
_8002d39c:
    cmpwi	r28, 0
    beq     _8002d568
    lwz	r3, 0x30(r1)
    li	r4, 0x1ffc
    srawi	r4, r4, 1
    lwz	r6, 0x88(r3)
    li	r0, 0
    addze.	r4, r4
    sth	r0, 2(r6)
    addi	r7, r6, 2
    addi	r5, r6, 4
    sth	r0, 0(r6)
    addi	r3, r4, 0
    ble     _8002d540
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _8002d510
_8002d3e0:
    lhz	r4, 0(r6)
    lhz	r0, 0(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 0(r5)
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    lhz	r4, 0(r6)
    lhz	r0, 2(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 2(r5)
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    lhz	r4, 0(r6)
    lhz	r0, 4(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 4(r5)
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    lhz	r4, 0(r6)
    lhz	r0, 6(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 6(r5)
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    lhz	r4, 0(r6)
    lhz	r0, 8(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 8(r5)
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    lhz	r4, 0(r6)
    lhz	r0, 0xa(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 0xa(r5)
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    lhz	r4, 0(r6)
    lhz	r0, 0xc(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 0xc(r5)
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    lhz	r4, 0(r6)
    lhz	r0, 0xe(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 0xe(r5)
    addi	r5, r5, 0x10
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    bdnz    _8002d3e0
    andi.	r3, r3, 7
    beq     _8002d540
_8002d510:
    mtctr	r3
_8002d514:
    lhz	r4, 0(r6)
    lhz	r0, 0(r5)
    add	r0, r4, r0
    sth	r0, 0(r6)
    lhz	r0, 0(r5)
    addi	r5, r5, 2
    lhz	r4, 0(r7)
    nor	r0, r0, r0
    add	r0, r4, r0
    sth	r0, 0(r7)
    bdnz    _8002d514
_8002d540:
    lhz	r0, 0(r6)
    cmplwi	r0, 0xffff
    bne     _8002d554
    li	r0, 0
    sth	r0, 0(r6)
_8002d554:
    lhz	r0, 0(r7)
    cmplwi	r0, 0xffff
    bne     _8002d568
    li	r0, 0
    sth	r0, 0(r7)
_8002d568:
    lwz	r6, 0x1c(r1)
    addi	r4, r1, 0x20
    li	r5, 0x2000
    xori	r0, r6, 1
    slwi	r3, r0, 2
    slwi	r0, r6, 2
    lwzx	r3, r4, r3
    lwzx	r4, r4, r0
    bl      memcpy
    cmpwi	r29, 0
    beq     _8002d5b4
    cmplwi	r26, 0
    beq     _8002d5a4
    li	r0, 0x2000
    stw	r0, 0(r26)
_8002d5a4:
    addi	r3, r25, 0
    addi	r4, r27, 0
    bl      __CARDUpdateDir
    b       _8002d620
_8002d5b4:
    or.	r0, r30, r28
    beq     _8002d5e4
    cmplwi	r26, 0
    beq     _8002d5cc
    li	r0, 0x2000
    stw	r0, 0(r26)
_8002d5cc:
    lwz	r4, 0x30(r1)
    addi	r3, r25, 0
    addi	r5, r27, 0
    lwz	r4, 0x88(r4)
    bl      __CARDUpdateFatBlock
    b       _8002d620
_8002d5e4:
    lwz	r3, 0x30(r1)
    li	r4, 0
    bl      __CARDPutControlBlock
    cmplwi	r27, 0
    beq     _8002d61c
    bl      OSDisableInterrupts
    addi	r12, r27, 0
    mtlr	r12
    addi	r26, r3, 0
    addi	r3, r25, 0
    li	r4, 0
    blrl	
    mr	r3, r26
    bl      OSRestoreInterrupts
_8002d61c:
    li	r3, 0
_8002d620:
    lmw	r25, 0x3c(r1)
    lwz	r0, 0x5c(r1)
    addi	r1, r1, 0x58
    mtlr	r0
    blr	
}

asm void CARDCheckAsync(void)
{
    nofralloc
    mflr	r0
    addi	r5, r4, 0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    addi	r4, r1, 0x10
    bl      CARDCheckExAsync
    lwz	r0, 0x1c(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void CARDCheck(void)
{
    nofralloc
    mflr	r0
    lis     r4, __CARDSyncCallback@ha
    stw	r0, 4(r1)
    addi	r5, r4, __CARDSyncCallback@l
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r3, 0
    addi	r4, r1, 0xc
    bl      CARDCheckExAsync
    cmpwi	r3, 0
    blt     _8002d69c
    addic.	r0, r1, 0xc
    bne     _8002d694
    b       _8002d69c
_8002d694:
    mr	r3, r31
    bl      __CARDSync
_8002d69c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_8002D6B0(void)
{
    nofralloc
    rlwinm.	r0, r3, 0, 0, 0xf
    beq     _8002d6d8
    addis	r0, r3, -0x8000
    cmplwi	r0, 4
    bne     _8002d6d0
    lhz	r0, -0x7ea8(r13)
    cmplwi	r0, 0xffff
    bne     _8002d6d8
_8002d6d0:
    li	r3, 0
    blr	
_8002d6d8:
    clrlwi.	r0, r3, 0x1e
    beq     _8002d6e8
    li	r3, 0
    blr	
_8002d6e8:
    rlwinm	r5, r3, 0, 0x18, 0x1d
    cmpwi	r5, 0x20
    beq     _8002d738
    bge     _8002d71c
    cmpwi	r5, 8
    beq     _8002d738
    bge     _8002d710
    cmpwi	r5, 4
    beq     _8002d738
    b       _8002d730
_8002d710:
    cmpwi	r5, 0x10
    beq     _8002d738
    b       _8002d730
_8002d71c:
    cmpwi	r5, 0x80
    beq     _8002d738
    bge     _8002d730
    cmpwi	r5, 0x40
    beq     _8002d738
_8002d730:
    li	r3, 0
    blr	
_8002d738:
    lis     r4, card_sector_size_table@ha
    rlwinm	r3, r3, 0x17, 0x1b, 0x1d
    addi	r0, r4, card_sector_size_table@l
    add	r3, r0, r3
    lwz	r3, 0(r3)
    cmpwi	r3, 0
    bne     _8002d75c
    li	r3, 0
    blr	
_8002d75c:
    rlwinm	r0, r5, 0x11, 3, 0xe
    divwu	r0, r0, r3
    cmplwi	r0, 8
    bge     _8002d774
    li	r3, 0
    blr	
_8002d774:
    li	r3, 1
    blr	
}

asm void fn_8002D77C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stmw	r27, 0x1c(r1)
    or.	r27, r3, r3
    addi	r28, r4, 0
    addi	r31, r5, 0
    blt     _8002d7a4
    cmpwi	r27, 2
    blt     _8002d7ac
_8002d7a4:
    li	r3, -0x80
    b       _8002d8e4
_8002d7ac:
    lis	r3, -0x8000
    lbz	r0, 0x30e3(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    beq     _8002d7c4
    li	r3, -3
    b       _8002d8e4
_8002d7c4:
    mulli	r4, r27, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r30, r0, r4
    bl      OSDisableInterrupts
    addi	r29, r3, 0
    addi	r3, r27, 0
    bl      EXIProbeEx
    cmpwi	r3, -1
    bne     _8002d7f4
    li	r30, -3
    b       _8002d8d8
_8002d7f4:
    cmpwi	r3, 0
    bne     _8002d804
    li	r30, -1
    b       _8002d8d8
_8002d804:
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    beq     _8002d84c
    lwz	r0, 0x24(r30)
    cmpwi	r0, 1
    bge     _8002d824
    li	r30, -1
    b       _8002d8d8
_8002d824:
    cmplwi	r28, 0
    beq     _8002d834
    lhz	r0, 8(r30)
    stw	r0, 0(r28)
_8002d834:
    cmplwi	r31, 0
    beq     _8002d844
    lwz	r0, 0xc(r30)
    stw	r0, 0(r31)
_8002d844:
    li	r30, 0
    b       _8002d8d8
_8002d84c:
    mr	r3, r27
    bl      EXIGetState
    rlwinm.	r0, r3, 0, 0x1c, 0x1c
    beq     _8002d864
    li	r30, -2
    b       _8002d8d8
_8002d864:
    addi	r3, r27, 0
    addi	r5, r1, 0x14
    li	r4, 0
    bl      EXIGetID
    cmpwi	r3, 0
    bne     _8002d884
    li	r30, -1
    b       _8002d8d8
_8002d884:
    lwz	r3, 0x14(r1)
    bl      fn_8002D6B0
    cmpwi	r3, 0
    beq     _8002d8d4
    cmplwi	r28, 0
    beq     _8002d8a8
    lwz	r0, 0x14(r1)
    rlwinm	r0, r0, 0, 0x18, 0x1d
    stw	r0, 0(r28)
_8002d8a8:
    cmplwi	r31, 0
    beq     _8002d8cc
    lwz	r4, 0x14(r1)
    lis     r3, card_sector_size_table@ha
    addi	r0, r3, card_sector_size_table@l
    rlwinm	r3, r4, 0x17, 0x1b, 0x1d
    add	r3, r0, r3
    lwz	r0, 0(r3)
    stw	r0, 0(r31)
_8002d8cc:
    li	r30, 0
    b       _8002d8d8
_8002d8d4:
    li	r30, -2
_8002d8d8:
    mr	r3, r29
    bl      OSRestoreInterrupts
    mr	r3, r30
_8002d8e4:
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void fn_8002D8F8(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    addi	r29, r3, 0
    mulli	r4, r29, 0x110
    stw	r28, 0x20(r1)
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r3, r0, r4
    lwz	r0, 0x24(r3)
    addi	r31, r3, 0
    cmpwi	r0, 0
    bne     _8002dbe0
    addi	r3, r29, 0
    addi	r5, r1, 0x18
    li	r4, 0
    bl      EXIGetID
    cmpwi	r3, 0
    bne     _8002d958
    li	r30, -3
    b       _8002d974
_8002d958:
    lwz	r3, 0x18(r1)
    bl      fn_8002D6B0
    cmpwi	r3, 0
    beq     _8002d970
    li	r30, 0
    b       _8002d974
_8002d970:
    li	r30, -2
_8002d974:
    cmpwi	r30, 0
    blt     _8002dcbc
    lwz	r0, 0x18(r1)
    lis     r4, card_sector_size_table@ha
    addi	r4, r4, card_sector_size_table@l
    stw	r0, 0x108(r31)
    lis     r3, card_block_count_table@ha
    addi	r0, r3, card_block_count_table@l
    lwz	r5, 0x18(r1)
    addi	r3, r29, 0
    rlwinm	r5, r5, 0, 0x18, 0x1d
    sth	r5, 8(r31)
    lwz	r5, 0x18(r1)
    rlwinm	r5, r5, 0x17, 0x1b, 0x1d
    add	r4, r4, r5
    lwz	r4, 0(r4)
    stw	r4, 0xc(r31)
    lhz	r5, 8(r31)
    lwz	r4, 0xc(r31)
    slwi	r5, r5, 0x14
    srawi	r5, r5, 3
    addze	r5, r5
    divw	r4, r5, r4
    sth	r4, 0x10(r31)
    lwz	r4, 0x18(r1)
    rlwinm	r4, r4, 0x1a, 0x1b, 0x1d
    add	r4, r0, r4
    lwz	r0, 0(r4)
    stw	r0, 0x14(r31)
    bl      __CARDClearStatus
    or.	r30, r3, r3
    blt     _8002dcbc
    addi	r3, r29, 0
    addi	r4, r1, 0x14
    bl      __CARDReadStatus
    or.	r30, r3, r3
    blt     _8002dcbc
    mr	r3, r29
    bl      EXIProbe
    cmpwi	r3, 0
    bne     _8002da20
    li	r30, -3
    b       _8002dcbc
_8002da20:
    lbz	r0, 0x14(r1)
    rlwinm.	r0, r0, 0, 0x19, 0x19
    bne     _8002db3c
    addi	r3, r29, 0
    addi	r4, r31, 0x18
    bl      __CARDUnlock
    or.	r30, r3, r3
    blt     _8002dcbc
    bl      __OSLockSramEx
    mulli	r0, r29, 0xc
    add	r4, r3, r0
    lbz	r0, 0x18(r31)
    addi	r5, r31, 0x18
    stb	r0, 0(r4)
    addi	r8, r5, 2
    addi	r9, r5, 3
    lbz	r7, 0x18(r31)
    addi	r10, r5, 4
    lbz	r0, 0x19(r31)
    addi	r11, r5, 5
    addi	r12, r5, 6
    stb	r0, 1(r4)
    addi	r28, r5, 7
    li	r5, 8
    lbz	r0, 0x19(r31)
    lbz	r6, 0(r8)
    add	r0, r7, r0
    stb	r6, 2(r4)
    lbz	r7, 0(r8)
    lbz	r6, 0(r9)
    add	r0, r0, r7
    stb	r6, 3(r4)
    lbz	r7, 0(r9)
    lbz	r6, 0(r10)
    add	r0, r0, r7
    stb	r6, 4(r4)
    lbz	r7, 0(r10)
    lbz	r6, 0(r11)
    add	r0, r0, r7
    stb	r6, 5(r4)
    lbz	r7, 0(r11)
    lbz	r6, 0(r12)
    add	r0, r0, r7
    stb	r6, 6(r4)
    lbz	r7, 0(r12)
    lbz	r6, 0(r28)
    add	r0, r0, r7
    stb	r6, 7(r4)
    lbz	r6, 0(r28)
    add	r0, r0, r6
    b       _8002dcd8
_8002daec:
    subfic	r4, r5, 0xc
    cmpwi	r5, 0xc
    mtctr	r4
    bge     _8002db20
_8002dafc:
    addi	r7, r5, 0x18
    add	r7, r31, r7
    lbz	r4, 0(r7)
    addi	r5, r5, 1
    stb	r4, 0(r6)
    addi	r6, r6, 1
    lbz	r4, 0(r7)
    add	r0, r0, r4
    bdnz    _8002dafc
_8002db20:
    add	r3, r3, r29
    nor	r0, r0, r0
    stb	r0, 0x26(r3)
    li	r3, 1
    bl      __OSUnlockSramEx
    mr	r3, r30
    b       _8002dce8
_8002db3c:
    li	r0, 1
    stw	r0, 0x24(r31)
    bl      __OSLockSramEx
    mulli	r0, r29, 0xc
    addi	r30, r3, 0
    add	r5, r30, r0
    lbz	r4, 0(r5)
    li	r6, 8
    lbz	r0, 1(r5)
    lbz	r3, 2(r5)
    add	r28, r4, r0
    lbz	r0, 3(r5)
    add	r28, r28, r3
    lbz	r3, 4(r5)
    add	r28, r28, r0
    lbz	r0, 5(r5)
    add	r28, r28, r3
    lbz	r3, 6(r5)
    add	r28, r28, r0
    lbz	r0, 7(r5)
    add	r28, r28, r3
    add	r28, r28, r0
    b       _8002dce0
_8002db98:
    subfic	r0, r6, 0xc
    cmpwi	r6, 0xc
    mtctr	r0
    bge     _8002dbb8
_8002dba8:
    lbz	r0, 0(r3)
    addi	r3, r3, 1
    add	r28, r28, r0
    bdnz    _8002dba8
_8002dbb8:
    li	r3, 0
    bl      __OSUnlockSramEx
    add	r3, r30, r29
    nor	r0, r28, r28
    lbz	r3, 0x26(r3)
    clrlwi	r0, r0, 0x18
    cmplw	r3, r0
    beq     _8002dbe0
    li	r30, -5
    b       _8002dcbc
_8002dbe0:
    lwz	r0, 0x24(r31)
    cmpwi	r0, 1
    bne     _8002dc70
    lwz	r3, 0x108(r31)
    addis	r0, r3, -0x8000
    cmplwi	r0, 4
    bne     _8002dc2c
    bl      __OSLockSramEx
    mulli	r0, r29, 0xc
    lhzx	r28, r3, r0
    li	r3, 0
    bl      __OSUnlockSramEx
    lhz	r0, -0x7ea8(r13)
    cmplwi	r0, 0xffff
    beq     _8002dc24
    cmplw	r28, r0
    beq     _8002dc2c
_8002dc24:
    li	r30, -2
    b       _8002dcbc
_8002dc2c:
    li	r0, 2
    stw	r0, 0x24(r31)
    addi	r3, r29, 0
    li	r4, 1
    bl      __CARDReadNintendoID
    or.	r30, r3, r3
    blt     _8002dcbc
    lis     r3, __CARDExiHandler@ha
    addi	r4, r3, __CARDExiHandler@l
    addi	r3, r29, 0
    bl      EXISetExiCallback
    mr	r3, r29
    bl      EXIUnlock
    lis	r4, 1
    lwz	r3, 0x80(r31)
    addi	r4, r4, -0x6000
    bl      DCInvalidateRange
_8002dc70:
    lwz	r4, 0x24(r31)
    lis     r3, fn_8002DD08@ha
    lwz	r0, 0xc(r31)
    addi	r7, r3, fn_8002DD08@l
    addi	r3, r4, -2
    mullw	r4, r0, r3
    lwz	r5, 0x80(r31)
    slwi	r0, r3, 0xd
    add	r6, r5, r0
    addi	r3, r29, 0
    li	r5, 0x2000
    bl      __CARDRead
    or.	r28, r3, r3
    bge     _8002dcb4
    addi	r3, r31, 0
    addi	r4, r28, 0
    bl      __CARDPutControlBlock
_8002dcb4:
    mr	r3, r28
    b       _8002dce8
_8002dcbc:
    mr	r3, r29
    bl      EXIUnlock
    addi	r3, r29, 0
    addi	r4, r30, 0
    bl      fn_8002E028
    mr	r3, r30
    b       _8002dce8
_8002dcd8:
    addi	r6, r4, 8
    b       _8002daec
_8002dce0:
    addi	r3, r5, 8
    b       _8002db98
_8002dce8:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    lwz	r28, 0x20(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void fn_8002DD08(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    addi	r29, r4, 0
    cmpwi	r29, -3
    stw	r28, 0x10(r1)
    addi	r28, r3, 0
    mulli	r5, r28, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    beq     _8002dde8
    bge     _8002dd54
    cmpwi	r29, -5
    beq     _8002dde8
    b       _8002ddf4
_8002dd54:
    cmpwi	r29, 1
    beq     _8002dda4
    bge     _8002ddf4
    cmpwi	r29, 0
    bge     _8002dd6c
    b       _8002ddf4
_8002dd6c:
    lwz	r3, 0x24(r31)
    addi	r0, r3, 1
    cmpwi	r0, 7
    stw	r0, 0x24(r31)
    bge     _8002dd94
    mr	r3, r28
    bl      fn_8002D8F8
    or.	r29, r3, r3
    blt     _8002ddf4
    b       _8002de20
_8002dd94:
    mr	r3, r31
    bl      __CARDVerify
    mr	r29, r3
    b       _8002ddf4
_8002dda4:
    lis     r3, fn_8002DD08@ha
    addi	r0, r3, fn_8002DD08@l
    lis     r3, fn_80029AF4@ha
    stw	r0, 0xdc(r31)
    addi	r5, r3, fn_80029AF4@l
    addi	r3, r28, 0
    li	r4, 0
    bl      EXILock
    cmpwi	r3, 0
    beq     _8002de20
    li	r0, 0
    stw	r0, 0xdc(r31)
    mr	r3, r28
    bl      fn_8002D8F8
    or.	r29, r3, r3
    blt     _8002ddf4
    b       _8002de20
_8002dde8:
    addi	r3, r28, 0
    addi	r4, r29, 0
    bl      fn_8002E028
_8002ddf4:
    lwz	r30, 0xd0(r31)
    li	r0, 0
    addi	r3, r31, 0
    stw	r0, 0xd0(r31)
    mr	r4, r29
    bl      __CARDPutControlBlock
    addi	r12, r30, 0
    mtlr	r12
    addi	r3, r28, 0
    addi	r4, r29, 0
    blrl	
_8002de20:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_8002DE40(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stmw	r26, 0x18(r1)
    or.	r30, r3, r3
    addi	r26, r4, 0
    addi	r27, r5, 0
    addi	r29, r6, 0
    blt     _8002de6c
    cmpwi	r30, 2
    blt     _8002de74
_8002de6c:
    li	r3, -0x80
    b       _8002dfcc
_8002de74:
    lis	r3, -0x8000
    lbz	r0, 0x30e3(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    beq     _8002de8c
    li	r3, -3
    b       _8002dfcc
_8002de8c:
    mulli	r4, r30, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r4
    bl      OSDisableInterrupts
    lwz	r0, 4(r31)
    addi	r28, r3, 0
    cmpwi	r0, -1
    bne     _8002dec0
    mr	r3, r28
    bl      OSRestoreInterrupts
    li	r3, -1
    b       _8002dfcc
_8002dec0:
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _8002deec
    mr	r3, r30
    bl      EXIGetState
    rlwinm.	r0, r3, 0, 0x1c, 0x1c
    beq     _8002deec
    mr	r3, r28
    bl      OSRestoreInterrupts
    li	r3, -2
    b       _8002dfcc
_8002deec:
    li	r0, -1
    stw	r0, 4(r31)
    cmplwi	r29, 0
    stw	r26, 0x80(r31)
    stw	r27, 0xc4(r31)
    beq     _8002df0c
    mr	r0, r29
    b       _8002df14
_8002df0c:
    lis     r3, fn_80029824@ha
    addi	r0, r3, fn_80029824@l
_8002df14:
    stw	r0, 0xd0(r31)
    li	r0, 0
    stw	r0, 0xcc(r31)
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _8002df5c
    lis     r3, __CARDExtHandler@ha
    addi	r4, r3, __CARDExtHandler@l
    addi	r3, r30, 0
    bl      EXIAttach
    cmpwi	r3, 0
    bne     _8002df5c
    li	r0, -3
    stw	r0, 4(r31)
    mr	r3, r28
    bl      OSRestoreInterrupts
    li	r3, -3
    b       _8002dfcc
_8002df5c:
    li	r29, 0
    stw	r29, 0x24(r31)
    li	r0, 1
    addi	r3, r30, 0
    stw	r0, 0(r31)
    li	r4, 0
    bl      EXISetExiCallback
    addi	r3, r31, 0xe0
    bl      OSCancelAlarm
    stw	r29, 0x84(r31)
    mr	r3, r28
    stw	r29, 0x88(r31)
    bl      OSRestoreInterrupts
    lis     r3, fn_8002DD08@ha
    addi	r0, r3, fn_8002DD08@l
    lis     r3, fn_80029AF4@ha
    stw	r0, 0xdc(r31)
    addi	r5, r3, fn_80029AF4@l
    addi	r3, r30, 0
    li	r4, 0
    bl      EXILock
    cmpwi	r3, 0
    bne     _8002dfc0
    li	r3, 0
    b       _8002dfcc
_8002dfc0:
    stw	r29, 0xdc(r31)
    mr	r3, r30
    bl      fn_8002D8F8
_8002dfcc:
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void CARDMount(void)
{
    nofralloc
    mflr	r0
    lis     r6, __CARDSyncCallback@ha
    stw	r0, 4(r1)
    addi	r6, r6, __CARDSyncCallback@l
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, 0
    bl      fn_8002DE40
    cmpwi	r3, 0
    bge     _8002e00c
    b       _8002e014
_8002e00c:
    mr	r3, r31
    bl      __CARDSync
_8002e014:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_8002E028(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    addi	r29, r4, 0
    stw	r28, 0x10(r1)
    addi	r28, r3, 0
    mulli	r5, r28, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    bl      OSDisableInterrupts
    lwz	r0, 0(r31)
    addi	r30, r3, 0
    cmpwi	r0, 0
    beq     _8002e09c
    addi	r3, r28, 0
    li	r4, 0
    bl      EXISetExiCallback
    mr	r3, r28
    bl      EXIDetach
    addi	r3, r31, 0xe0
    bl      OSCancelAlarm
    li	r0, 0
    stw	r0, 0(r31)
    stw	r29, 4(r31)
    stw	r0, 0x24(r31)
_8002e09c:
    mr	r3, r30
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_8002E0C4(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r4, r1, 0xc
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    bl      __CARDGetControlBlock
    cmpwi	r3, 0
    bge     _8002e0f4
    b       _8002e154
_8002e0f4:
    mulli	r4, r29, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r30, r0, r4
    bl      OSDisableInterrupts
    lwz	r0, 0(r30)
    addi	r31, r3, 0
    cmpwi	r0, 0
    beq     _8002e148
    addi	r3, r29, 0
    li	r4, 0
    bl      EXISetExiCallback
    mr	r3, r29
    bl      EXIDetach
    addi	r3, r30, 0xe0
    bl      OSCancelAlarm
    li	r3, 0
    stw	r3, 0(r30)
    li	r0, -3
    stw	r0, 4(r30)
    stw	r3, 0x24(r30)
_8002e148:
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 0
_8002e154:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_8002E170(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r3, 0
    lis     r3, __CARDBlock@ha
    stw	r29, 0x14(r1)
    mulli	r5, r30, 0x110
    stw	r28, 0x10(r1)
    addi	r0, r3, __CARDBlock@l
    or.	r28, r4, r4
    add	r31, r0, r5
    blt     _8002e268
    lwz	r3, 0x28(r31)
    addi	r0, r3, 1
    stw	r0, 0x28(r31)
    lwz	r4, 0x28(r31)
    cmpwi	r4, 5
    bge     _8002e1e4
    lwz	r0, 0xc(r31)
    lis     r3, fn_8002E170@ha
    addi	r5, r3, fn_8002E170@l
    mullw	r4, r0, r4
    addi	r3, r30, 0
    bl      __CARDEraseSector
    or.	r28, r3, r3
    blt     _8002e268
    b       _8002e294
_8002e1e4:
    cmpwi	r4, 0xa
    bge     _8002e224
    lwz	r0, 0xc(r31)
    addi	r6, r4, -5
    lis     r3, fn_8002E170@ha
    lwz	r5, 0x80(r31)
    mullw	r4, r0, r6
    slwi	r0, r6, 0xd
    addi	r7, r3, fn_8002E170@l
    add	r6, r5, r0
    addi	r3, r30, 0
    li	r5, 0x2000
    bl      __CARDWrite
    or.	r28, r3, r3
    blt     _8002e268
    b       _8002e294
_8002e224:
    lwz	r3, 0x80(r31)
    li	r5, 0x2000
    addi	r0, r3, 0x2000
    stw	r0, 0x84(r31)
    lwz	r4, 0x80(r31)
    lwz	r3, 0x84(r31)
    addi	r4, r4, 0x4000
    bl      memcpy
    lwz	r3, 0x80(r31)
    li	r5, 0x2000
    addi	r0, r3, 0x6000
    stw	r0, 0x88(r31)
    lwz	r4, 0x80(r31)
    lwz	r3, 0x88(r31)
    addis	r4, r4, 1
    addi	r4, r4, -0x8000
    bl      memcpy
_8002e268:
    lwz	r29, 0xd0(r31)
    li	r0, 0
    addi	r3, r31, 0
    stw	r0, 0xd0(r31)
    mr	r4, r28
    bl      __CARDPutControlBlock
    addi	r12, r29, 0
    mtlr	r12
    addi	r3, r30, 0
    addi	r4, r28, 0
    blrl	
_8002e294:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_8002E2B4(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x58(r1)
    stmw	r18, 0x20(r1)
    addi	r20, r4, 0
    addi	r22, r3, 0
    addi	r19, r5, 0
    addi	r4, r1, 0x18
    bl      __CARDGetControlBlock
    cmpwi	r3, 0
    bge     _8002e2e4
    b       _8002e8f8
_8002e2e4:
    lwz	r3, 0x18(r1)
    li	r4, 0xff
    li	r5, 0x2000
    lwz	r27, 0x80(r3)
    mr	r3, r27
    bl      memset
    lis	r3, -0x3400
    lhz	r18, 0x206e(r3)
    sth	r20, 0x24(r27)
    bl      __OSLockSram
    lwz	r0, 0xc(r3)
    stw	r0, 0x14(r27)
    lbz	r0, 0x12(r3)
    li	r3, 0
    stw	r0, 0x18(r27)
    bl      __OSUnlockSram
    bl      OSGetTime
    addi	r21, r4, 0
    addi	r20, r3, 0
    addi	r26, r21, 0
    addi	r30, r20, 0
    bl      __OSLockSramEx
    mulli	r0, r22, 0xc
    add	r25, r3, r0
    lis	r3, 0x41c6
    addi	r24, r25, 0
    addi	r31, r3, 0x4e6d
    li	r28, 0
    li	r23, 4
    b       _8002e6cc
_8002e35c:
    mullw	r5, r30, r31
    mulhwu	r3, r26, r31
    li	r30, 0
    add	r5, r5, r3
    mullw	r3, r26, r30
    mullw	r0, r26, r31
    li	r29, 0x3039
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    lbz	r0, 0(r24)
    mulhwu	r5, r4, r31
    add	r6, r6, r5
    addc	r8, r4, r0
    extsh	r7, r28
    mullw	r5, r4, r30
    stbx	r8, r27, r7
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    li	r26, 0x7fff
    and	r0, r3, r30
    and	r4, r4, r26
    mullw	r5, r0, r31
    mulhwu	r3, r4, r31
    add	r5, r5, r3
    mullw	r3, r4, r30
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    mulhwu	r5, r4, r31
    addi	r9, r28, 1
    extsh	r9, r9
    lbzx	r0, r25, r9
    add	r6, r6, r5
    mullw	r5, r4, r30
    addc	r7, r4, r0
    mullw	r0, r4, r31
    stbx	r7, r27, r9
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    and	r0, r3, r30
    and	r4, r4, r26
    mullw	r5, r0, r31
    mulhwu	r3, r4, r31
    add	r5, r5, r3
    mullw	r3, r4, r30
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    mulhwu	r5, r4, r31
    addi	r9, r28, 2
    extsh	r9, r9
    lbzx	r0, r25, r9
    add	r6, r6, r5
    mullw	r5, r4, r30
    addc	r7, r4, r0
    mullw	r0, r4, r31
    stbx	r7, r27, r9
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    and	r0, r3, r30
    and	r4, r4, r26
    mullw	r5, r0, r31
    mulhwu	r3, r4, r31
    add	r5, r5, r3
    mullw	r3, r4, r30
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    mulhwu	r5, r4, r31
    addi	r9, r28, 3
    extsh	r9, r9
    lbzx	r0, r25, r9
    add	r6, r6, r5
    mullw	r5, r4, r30
    addc	r7, r4, r0
    mullw	r0, r4, r31
    stbx	r7, r27, r9
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    and	r0, r3, r30
    and	r4, r4, r26
    mullw	r5, r0, r31
    mulhwu	r3, r4, r31
    add	r5, r5, r3
    mullw	r3, r4, r30
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    mulhwu	r5, r4, r31
    addi	r9, r28, 4
    extsh	r9, r9
    lbzx	r0, r25, r9
    add	r6, r6, r5
    mullw	r5, r4, r30
    addc	r7, r4, r0
    mullw	r0, r4, r31
    stbx	r7, r27, r9
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    and	r0, r3, r30
    and	r4, r4, r26
    mullw	r5, r0, r31
    mulhwu	r3, r4, r31
    add	r5, r5, r3
    mullw	r3, r4, r30
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    mulhwu	r5, r4, r31
    addi	r9, r28, 5
    extsh	r9, r9
    lbzx	r0, r25, r9
    add	r6, r6, r5
    mullw	r5, r4, r30
    addc	r7, r4, r0
    mullw	r0, r4, r31
    stbx	r7, r27, r9
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    and	r0, r3, r30
    and	r4, r4, r26
    mullw	r5, r0, r31
    mulhwu	r3, r4, r31
    add	r5, r5, r3
    mullw	r3, r4, r30
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    mulhwu	r5, r4, r31
    addi	r9, r28, 6
    extsh	r9, r9
    lbzx	r0, r25, r9
    add	r6, r6, r5
    mullw	r5, r4, r30
    addc	r7, r4, r0
    mullw	r0, r4, r31
    stbx	r7, r27, r9
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    and	r0, r3, r30
    and	r4, r4, r26
    mullw	r5, r0, r31
    mulhwu	r3, r4, r31
    add	r5, r5, r3
    mullw	r3, r4, r30
    mullw	r0, r4, r31
    addc	r4, r0, r29
    add	r0, r5, r3
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r31
    mulhwu	r5, r4, r31
    addi	r9, r28, 7
    extsh	r9, r9
    lbzx	r0, r25, r9
    add	r6, r6, r5
    mullw	r5, r4, r30
    addc	r7, r4, r0
    mullw	r0, r4, r31
    stbx	r7, r27, r9
    addc	r4, r0, r29
    add	r0, r6, r5
    adde	r3, r0, r30
    li	r5, 0x10
    bl      __shr2i
    and	r26, r4, r26
    and	r30, r3, r30
    addi	r24, r24, 8
    addi	r28, r28, 8
_8002e6cc:
    extsh	r0, r28
    cmpw	r0, r23
    blt     _8002e35c
    b       _8002e8f0
_8002e6dc:
    lis	r3, 0x41c6
    addi	r25, r3, 0x4e6d
    b       _8002e764
_8002e6e8:
    mullw	r5, r30, r25
    mulhwu	r3, r26, r25
    li	r24, 0
    add	r5, r5, r3
    mullw	r3, r26, r24
    mullw	r0, r26, r25
    li	r23, 0x3039
    addc	r4, r0, r23
    add	r0, r5, r3
    adde	r3, r0, r24
    li	r5, 0x10
    bl      __shr2i
    mullw	r6, r3, r25
    lbz	r0, 0(r29)
    mulhwu	r5, r4, r25
    add	r6, r6, r5
    addc	r8, r4, r0
    extsh	r7, r28
    mullw	r5, r4, r24
    stbx	r8, r27, r7
    mullw	r0, r4, r25
    addc	r4, r0, r23
    add	r0, r6, r5
    adde	r3, r0, r24
    li	r5, 0x10
    bl      __shr2i
    li	r0, 0x7fff
    and	r26, r4, r0
    and	r30, r3, r24
    addi	r29, r29, 1
    addi	r28, r28, 1
_8002e764:
    extsh	r0, r28
    cmpwi	r0, 0xc
    blt     _8002e6e8
    li	r3, 0
    bl      __OSUnlockSramEx
    stw	r18, 0x1c(r27)
    li	r18, 0
    addi	r3, r27, 0
    stw	r21, 0x10(r27)
    addi	r5, r27, 0x1fc
    addi	r6, r27, 0x1fe
    stw	r20, 0xc(r27)
    li	r4, 0x1fc
    sth	r18, 0x20(r27)
    lwz	r7, 0x18(r1)
    lhz	r0, 8(r7)
    sth	r0, 0x22(r27)
    bl      __CARDCheckSum
    b       _8002e7f8
_8002e7b0:
    lwz	r4, 0x18(r1)
    extsh	r3, r18
    addi	r0, r3, 1
    lwz	r3, 0x80(r4)
    slwi	r0, r0, 0xd
    li	r4, 0xff
    add	r20, r3, r0
    addi	r3, r20, 0
    li	r5, 0x2000
    bl      memset
    addi	r4, r20, 0x1fc0
    sth	r18, 0x1ffa(r20)
    addi	r3, r20, 0
    addi	r5, r4, 0x3c
    addi	r6, r4, 0x3e
    li	r4, 0x1ffc
    bl      __CARDCheckSum
    addi	r18, r18, 1
_8002e7f8:
    extsh	r0, r18
    cmpwi	r0, 2
    blt     _8002e7b0
    li	r18, 0
    b       _8002e868
_8002e80c:
    lwz	r4, 0x18(r1)
    extsh	r3, r18
    addi	r0, r3, 3
    lwz	r3, 0x80(r4)
    slwi	r0, r0, 0xd
    li	r4, 0
    add	r20, r3, r0
    addi	r3, r20, 0
    li	r5, 0x2000
    bl      memset
    sth	r18, 4(r20)
    li	r0, 4
    addi	r5, r20, 0
    lwz	r4, 0x18(r1)
    addi	r3, r20, 4
    addi	r6, r20, 2
    lhz	r7, 0x10(r4)
    li	r4, 0x1ffc
    addi	r7, r7, -5
    sth	r7, 6(r20)
    sth	r0, 8(r20)
    bl      __CARDCheckSum
    addi	r18, r18, 1
_8002e868:
    extsh	r0, r18
    cmpwi	r0, 2
    blt     _8002e80c
    cmplwi	r19, 0
    beq     _8002e884
    mr	r0, r19
    b       _8002e88c
_8002e884:
    lis     r3, fn_80029824@ha
    addi	r0, r3, fn_80029824@l
_8002e88c:
    lwz	r5, 0x18(r1)
    lis	r3, 1
    addi	r4, r3, -0x6000
    stw	r0, 0xd0(r5)
    lwz	r3, 0x18(r1)
    lwz	r3, 0x80(r3)
    bl      DCStoreRange
    lwz	r4, 0x18(r1)
    li	r0, 0
    lis     r3, fn_8002E170@ha
    stw	r0, 0x28(r4)
    addi	r5, r3, fn_8002E170@l
    addi	r3, r22, 0
    lwz	r6, 0x18(r1)
    lwz	r4, 0xc(r6)
    lwz	r0, 0x28(r6)
    mullw	r4, r4, r0
    bl      __CARDEraseSector
    or.	r18, r3, r3
    bge     _8002e8e8
    lwz	r3, 0x18(r1)
    mr	r4, r18
    bl      __CARDPutControlBlock
_8002e8e8:
    mr	r3, r18
    b       _8002e8f8
_8002e8f0:
    add	r29, r25, r0
    b       _8002e6dc
_8002e8f8:
    lmw	r18, 0x20(r1)
    lwz	r0, 0x5c(r1)
    addi	r1, r1, 0x58
    mtlr	r0
    blr	
}

asm void CARDFormatAsync(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, 0
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    bl      fn_8002A744
    addi	r4, r3, 0
    addi	r3, r30, 0
    addi	r5, r31, 0
    bl      fn_8002E2B4
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __CARDCompareFileName(void)
{
    nofralloc
    addi	r5, r3, 8
    li	r7, 0x20
    b       _8002e998
_8002e960:
    lbz	r0, 0(r5)
    addi	r5, r5, 1
    lbz	r6, 0(r4)
    addi	r4, r4, 1
    extsb	r3, r0
    extsb	r0, r6
    cmpw	r3, r0
    beq     _8002e988
    li	r3, 0
    blr	
_8002e988:
    extsb.	r0, r6
    bne     _8002e998
    li	r3, 1
    blr	
_8002e998:
    addic.	r7, r7, -1
    bge     _8002e960
    lbz	r0, 0(r4)
    extsb.	r0, r0
    bne     _8002e9b4
    li	r3, 1
    blr	
_8002e9b4:
    li	r3, 0
    blr	
}

asm void __CARDAccess(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r4
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    lbz	r0, 0(r4)
    cmplwi	r0, 0xff
    bne     _8002e9ec
    li	r3, -4
    b       _8002ea3c
_8002e9ec:
    lis     r3, lbl_80177B80@ha
    lwz	r4, 0x10c(r30)
    addi	r0, r3, lbl_80177B80@l
    cmplw	r4, r0
    beq     _8002ea30
    addi	r3, r31, 0
    li	r5, 4
    bl      strncmp
    cmpwi	r3, 0
    bne     _8002ea38
    lwz	r4, 0x10c(r30)
    addi	r3, r31, 4
    li	r5, 2
    addi	r4, r4, 4
    bl      strncmp
    cmpwi	r3, 0
    bne     _8002ea38
_8002ea30:
    li	r3, 0
    b       _8002ea3c
_8002ea38:
    li	r3, -0xa
_8002ea3c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_8002EA54(void)
{
    nofralloc
    lbz	r0, 0(r3)
    cmplwi	r0, 0xff
    bne     _8002ea68
    li	r3, -4
    blr	
_8002ea68:
    lbz	r0, 0x34(r3)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    beq     _8002ea7c
    li	r3, 0
    blr	
_8002ea7c:
    li	r3, -0xa
    blr	
}

asm void __CARDGetFileNo(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stmw	r26, 0x18(r1)
    mr	r27, r3
    addi	r28, r4, 0
    addi	r29, r5, 0
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    bne     _8002eab4
    li	r3, -3
    b       _8002ebc0
_8002eab4:
    mr	r3, r27
    bl      __CARDGetDirBlock
    lis     r4, lbl_80177B80@ha
    addi	r31, r3, 0
    addi	r26, r4, lbl_80177B80@l
    li	r30, 0
_8002eacc:
    lbz	r0, 0(r31)
    cmplwi	r0, 0xff
    bne     _8002eae0
    li	r0, -4
    b       _8002eb28
_8002eae0:
    lwz	r4, 0x10c(r27)
    cmplw	r4, r26
    beq     _8002eb1c
    addi	r3, r31, 0
    li	r5, 4
    bl      strncmp
    cmpwi	r3, 0
    bne     _8002eb24
    lwz	r4, 0x10c(r27)
    addi	r3, r31, 4
    li	r5, 2
    addi	r4, r4, 4
    bl      strncmp
    cmpwi	r3, 0
    bne     _8002eb24
_8002eb1c:
    li	r0, 0
    b       _8002eb28
_8002eb24:
    li	r0, -0xa
_8002eb28:
    cmpwi	r0, 0
    blt     _8002ebac
    addi	r7, r28, 0
    addi	r6, r31, 8
    li	r4, 0x20
    b       _8002eb78
_8002eb40:
    lbz	r0, 0(r6)
    addi	r6, r6, 1
    lbz	r5, 0(r7)
    addi	r7, r7, 1
    extsb	r3, r0
    extsb	r0, r5
    cmpw	r3, r0
    beq     _8002eb68
    li	r0, 0
    b       _8002eb98
_8002eb68:
    extsb.	r0, r5
    bne     _8002eb78
    li	r0, 1
    b       _8002eb98
_8002eb78:
    addic.	r4, r4, -1
    bge     _8002eb40
    lbz	r0, 0(r7)
    extsb.	r0, r0
    bne     _8002eb94
    li	r0, 1
    b       _8002eb98
_8002eb94:
    li	r0, 0
_8002eb98:
    cmpwi	r0, 0
    beq     _8002ebac
    stw	r30, 0(r29)
    li	r3, 0
    b       _8002ebc0
_8002ebac:
    addi	r30, r30, 1
    cmpwi	r30, 0x7f
    addi	r31, r31, 0x40
    blt     _8002eacc
    li	r3, -4
_8002ebc0:
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void CARDOpen(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    li	r0, -1
    stwu	r1, -0x40(r1)
    stmw	r23, 0x1c(r1)
    addi	r28, r4, 0
    addi	r29, r5, 0
    addi	r27, r3, 0
    addi	r4, r1, 0x14
    stw	r0, 0(r5)
    bl      __CARDGetControlBlock
    cmpwi	r3, 0
    bge     _8002ec0c
    b       _8002ed38
_8002ec0c:
    lwz	r31, 0x14(r1)
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _8002ec24
    li	r23, -3
    b       _8002ecd8
_8002ec24:
    mr	r3, r31
    bl      __CARDGetDirBlock
    lis     r4, lbl_80177B80@ha
    addi	r23, r3, 0
    addi	r26, r4, lbl_80177B80@l
    li	r25, 0
_8002ec3c:
    lbz	r0, 0(r23)
    addi	r24, r23, 0
    cmplwi	r0, 0xff
    bne     _8002ec54
    li	r0, -4
    b       _8002ec9c
_8002ec54:
    lwz	r4, 0x10c(r31)
    cmplw	r4, r26
    beq     _8002ec90
    addi	r3, r24, 0
    li	r5, 4
    bl      strncmp
    cmpwi	r3, 0
    bne     _8002ec98
    lwz	r4, 0x10c(r31)
    addi	r3, r24, 4
    li	r5, 2
    addi	r4, r4, 4
    bl      strncmp
    cmpwi	r3, 0
    bne     _8002ec98
_8002ec90:
    li	r0, 0
    b       _8002ec9c
_8002ec98:
    li	r0, -0xa
_8002ec9c:
    cmpwi	r0, 0
    blt     _8002ecc4
    addi	r3, r23, 0
    addi	r4, r28, 0
    bl      __CARDCompareFileName
    cmpwi	r3, 0
    beq     _8002ecc4
    addi	r30, r25, 0
    li	r23, 0
    b       _8002ecd8
_8002ecc4:
    addi	r25, r25, 1
    cmpwi	r25, 0x7f
    addi	r23, r23, 0x40
    blt     _8002ec3c
    li	r23, -4
_8002ecd8:
    cmpwi	r23, 0
    blt     _8002ed2c
    lwz	r3, 0x14(r1)
    bl      __CARDGetDirBlock
    slwi	r0, r30, 6
    add	r5, r3, r0
    lhz	r4, 0x36(r5)
    cmplwi	r4, 5
    blt     _8002ed0c
    lwz	r3, 0x14(r1)
    lhz	r0, 0x10(r3)
    cmplw	r4, r0
    blt     _8002ed14
_8002ed0c:
    li	r23, -6
    b       _8002ed2c
_8002ed14:
    stw	r27, 0(r29)
    li	r0, 0
    stw	r30, 4(r29)
    stw	r0, 8(r29)
    lhz	r0, 0x36(r5)
    sth	r0, 0x10(r29)
_8002ed2c:
    lwz	r3, 0x14(r1)
    mr	r4, r23
    bl      __CARDPutControlBlock
_8002ed38:
    lmw	r23, 0x1c(r1)
    lwz	r0, 0x44(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr	
}

asm void CARDClose(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    addi	r4, r1, 0xc
    lwz	r3, 0(r3)
    bl      __CARDGetControlBlock
    cmpwi	r3, 0
    bge     _8002ed78
    b       _8002ed8c
_8002ed78:
    li	r0, -1
    stw	r0, 0(r31)
    li	r4, 0
    lwz	r3, 0xc(r1)
    bl      __CARDPutControlBlock
_8002ed8c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_8002EDA0(void)
{
    nofralloc
    li      r3, 0
    blr	
}

asm void CreateCallbackFat(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stmw	r27, 0x14(r1)
    addi	r28, r3, 0
    lis     r3, __CARDBlock@ha
    mulli	r5, r28, 0x110
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    lwz	r29, 0xd0(r31)
    li	r27, 0
    or.	r30, r4, r4
    stw	r27, 0xd0(r31)
    blt     _8002ee9c
    mr	r3, r31
    bl      __CARDGetDirBlock
    lhz	r0, 0xbc(r31)
    li	r5, 4
    lwz	r4, 0x10c(r31)
    slwi	r0, r0, 6
    add	r30, r3, r0
    addi	r3, r30, 0
    bl      memcpy
    lwz	r4, 0x10c(r31)
    addi	r3, r30, 4
    li	r5, 2
    addi	r4, r4, 4
    bl      memcpy
    li	r0, 4
    stb	r0, 0x34(r30)
    li	r0, -1
    lis	r3, -0x8000
    stb	r27, 0x35(r30)
    lhz	r4, 0xbe(r31)
    sth	r4, 0x36(r30)
    stb	r27, 7(r30)
    stw	r0, 0x2c(r30)
    sth	r27, 0x30(r30)
    sth	r27, 0x32(r30)
    stw	r0, 0x3c(r30)
    lhz	r0, 0x32(r30)
    rlwinm	r0, r0, 0, 0, 0x1d
    ori	r0, r0, 1
    sth	r0, 0x32(r30)
    lwz	r4, 0xc0(r31)
    stw	r27, 8(r4)
    lhz	r0, 0x36(r30)
    lwz	r4, 0xc0(r31)
    sth	r0, 0x10(r4)
    lwz	r0, 0xf8(r3)
    srwi	r27, r0, 2
    bl      OSGetTime
    addi	r6, r27, 0
    li	r5, 0
    bl      __div2i
    stw	r4, 0x28(r30)
    addi	r3, r28, 0
    addi	r4, r29, 0
    bl      __CARDUpdateDir
    or.	r30, r3, r3
    bge     _8002eec4
_8002ee9c:
    addi	r3, r31, 0
    addi	r4, r30, 0
    bl      __CARDPutControlBlock
    cmplwi	r29, 0
    beq     _8002eec4
    addi	r12, r29, 0
    mtlr	r12
    addi	r3, r28, 0
    addi	r4, r30, 0
    blrl	
_8002eec4:
    lmw	r27, 0x14(r1)
    lwz	r0, 0x2c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

#pragma pop
