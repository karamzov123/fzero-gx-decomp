// dolphin/card/CARDBios.c -- carved from coarse/text_80029828 (0x80029828-0x8002A698).
// Melee identity: CARDBios/Mount EXI+alarm layer (sync/ext/tx handlers, __CARDStart,
//   read-segment/write-page/erase-sector EXI command cores).
#pragma push
#pragma force_active on

extern void __CARDSyncCallback(void);
extern void __CARDExtHandler(void);
extern void __CARDExiHandler(void);
extern void __CARDTxHandler(void);
extern void fn_80029AF4(void);
extern void __CARDReadNintendoID(void);
extern void __CARDReadStatus(void);
extern void __CARDClearStatus(void);
extern void TimeoutHandler(void);
extern void fn_80029E78(void);
extern void fn_8002A0A4(void);
extern void __CARDStart(void);
extern void __CARDReadSegment(void);
extern void __CARDWritePage(void);
extern void __CARDEraseSector(void);
extern void EXIDeselect(void);
extern void EXIDma(void);
extern void EXIImm(void);
extern void EXIImmEx(void);
extern void EXILock(void);
extern void EXIProbe(void);
extern void EXISelect(void);
extern void EXISetExiCallback(void);
extern void EXISync(void);
extern void EXIUnlock(void);
extern void OSCancelAlarm(void);
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void OSSetAlarm(void);
extern void OSWakeupThread(void);
extern void TimeoutHandler(void);
extern unsigned char __CARDBlock[544];
extern void __CARDTxHandler(void);
extern void fn_80029AF4(void);

asm void __CARDSyncCallback(void)
{
    nofralloc
    mflr	r0
    mulli	r4, r3, 0x110
    stw	r0, 4(r1)
    lis     r3, __CARDBlock@ha
    stwu	r1, -8(r1)
    addi	r0, r3, __CARDBlock@l
    add	r3, r0, r4
    addi	r3, r3, 0x8c
    bl      OSWakeupThread
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void __CARDExtHandler(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    mulli	r4, r29, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r30, r0, r4
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    beq     _80029918
    li	r31, 0
    stw	r31, 0(r30)
    addi	r3, r29, 0
    li	r4, 0
    bl      EXISetExiCallback
    addi	r3, r30, 0xe0
    bl      OSCancelAlarm
    lwz	r0, 0xcc(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _800298d4
    stw	r31, 0xcc(r30)
    mtlr	r12
    addi	r3, r29, 0
    li	r4, -3
    blrl	
_800298d4:
    lwz	r0, 4(r30)
    cmpwi	r0, -1
    beq     _800298e8
    li	r0, -3
    stw	r0, 4(r30)
_800298e8:
    lwz	r12, 0xc4(r30)
    cmplwi	r12, 0
    beq     _80029918
    lwz	r0, 0x24(r30)
    cmpwi	r0, 7
    blt     _80029918
    li	r0, 0
    mtlr	r12
    stw	r0, 0xc4(r30)
    addi	r3, r29, 0
    li	r4, -3
    blrl	
_80029918:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDExiHandler(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r3, 0
    mulli	r4, r31, 0x110
    stw	r30, 0x20(r1)
    lis     r3, __CARDBlock@ha
    stw	r29, 0x1c(r1)
    addi	r0, r3, __CARDBlock@l
    add	r30, r0, r4
    addi	r3, r30, 0xe0
    bl      OSCancelAlarm
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    beq     _80029a30
    addi	r3, r31, 0
    li	r4, 0
    li	r5, 0
    bl      EXILock
    cmpwi	r3, 0
    bne     _80029994
    li	r29, -0x80
    b       _80029a08
_80029994:
    addi	r3, r31, 0
    addi	r4, r1, 0x10
    bl      __CARDReadStatus
    or.	r29, r3, r3
    blt     _80029a00
    mr	r3, r31
    bl      __CARDClearStatus
    or.	r29, r3, r3
    blt     _80029a00
    lbz	r0, 0x10(r1)
    rlwinm.	r0, r0, 0, 0x1b, 0x1c
    beq     _800299cc
    li	r0, -5
    b       _800299d0
_800299cc:
    li	r0, 0
_800299d0:
    mr	r29, r0
    cmpwi	r29, -5
    bne     _80029a00
    lwz	r3, 0xa8(r30)
    addic.	r0, r3, -1
    stw	r0, 0xa8(r30)
    ble     _80029a00
    mr	r3, r31
    bl      fn_80029E78
    or.	r29, r3, r3
    blt     _80029a08
    b       _80029a30
_80029a00:
    mr	r3, r31
    bl      EXIUnlock
_80029a08:
    lwz	r0, 0xcc(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _80029a30
    li	r0, 0
    mtlr	r12
    stw	r0, 0xcc(r30)
    addi	r3, r31, 0
    addi	r4, r29, 0
    blrl	
_80029a30:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __CARDTxHandler(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stmw	r27, 0x14(r1)
    addi	r27, r3, 0
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    mulli	r4, r27, 0x110
    addi	r3, r27, 0
    add	r29, r0, r4
    bl      EXIDeselect
    cntlzw	r0, r3
    addi	r3, r27, 0
    srwi	r31, r0, 5
    bl      EXIUnlock
    lwz	r0, 0xc8(r29)
    cmplwi	r0, 0
    mr	r28, r0
    beq     _80029ae0
    li	r30, 0
    cmpwi	r31, 0
    stw	r30, 0xc8(r29)
    bne     _80029abc
    mr	r3, r27
    bl      EXIProbe
    cmpwi	r3, 0
    beq     _80029abc
    li	r30, 1
_80029abc:
    cmpwi	r30, 0
    beq     _80029acc
    li	r4, 0
    b       _80029ad0
_80029acc:
    li	r4, -3
_80029ad0:
    addi	r12, r28, 0
    mtlr	r12
    addi	r3, r27, 0
    blrl	
_80029ae0:
    lmw	r27, 0x14(r1)
    lwz	r0, 0x2c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void fn_80029AF4(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    mulli	r4, r30, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r3, r0, r4
    lwz	r0, 0xdc(r3)
    cmplwi	r0, 0
    mr	r31, r0
    beq     _80029b60
    li	r0, 0
    stw	r0, 0xdc(r3)
    mr	r3, r30
    bl      EXIProbe
    cmpwi	r3, 0
    beq     _80029b4c
    li	r4, 1
    b       _80029b50
_80029b4c:
    li	r4, -3
_80029b50:
    addi	r12, r31, 0
    mtlr	r12
    addi	r3, r30, 0
    blrl	
_80029b60:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __CARDReadNintendoID(void)
{
    nofralloc
    mflr	r0
    li	r5, 4
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, 0
    li	r4, 0
    stw	r30, 0x18(r1)
    addi	r30, r3, 0
    bl      EXISelect
    cmpwi	r3, 0
    bne     _80029bb0
    li	r3, -3
    b       _80029c20
_80029bb0:
    cmpwi	r31, 0
    beq     _80029bc0
    lis	r0, -0x7eff
    b       _80029bc4
_80029bc0:
    lis	r0, -0x7f00
_80029bc4:
    stw	r0, 0x10(r1)
    addi	r3, r30, 0
    addi	r4, r1, 0x10
    li	r5, 2
    li	r6, 1
    li	r7, 0
    bl      EXIImm
    cntlzw	r0, r3
    addi	r3, r30, 0
    srwi	r31, r0, 5
    bl      EXISync
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r3, r30, 0
    or	r31, r31, r0
    bl      EXIDeselect
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or.	r31, r31, r0
    beq     _80029c1c
    li	r3, -3
    b       _80029c20
_80029c1c:
    li	r3, 0
_80029c20:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDReadStatus(void)
{
    nofralloc
    mflr	r0
    li	r5, 4
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    addi	r30, r4, 0
    li	r4, 0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    bl      EXISelect
    cmpwi	r3, 0
    bne     _80029c74
    li	r3, -3
    b       _80029d0c
_80029c74:
    lis	r0, -0x7d00
    stw	r0, 0x10(r1)
    addi	r3, r29, 0
    addi	r4, r1, 0x10
    li	r5, 2
    li	r6, 1
    li	r7, 0
    bl      EXIImm
    cntlzw	r0, r3
    addi	r3, r29, 0
    srwi	r31, r0, 5
    bl      EXISync
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r3, r29, 0
    addi	r4, r30, 0
    or	r31, r31, r0
    li	r5, 1
    li	r6, 0
    li	r7, 0
    bl      EXIImm
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r3, r29, 0
    or	r31, r31, r0
    bl      EXISync
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r3, r29, 0
    or	r31, r31, r0
    bl      EXIDeselect
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or.	r31, r31, r0
    beq     _80029d08
    li	r3, -3
    b       _80029d0c
_80029d08:
    li	r3, 0
_80029d0c:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __CARDClearStatus(void)
{
    nofralloc
    mflr	r0
    li	r4, 0
    stw	r0, 4(r1)
    li	r5, 4
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    bl      EXISelect
    cmpwi	r3, 0
    bne     _80029d5c
    li	r3, -3
    b       _80029dbc
_80029d5c:
    lis	r0, -0x7700
    stw	r0, 0xc(r1)
    addi	r3, r30, 0
    addi	r4, r1, 0xc
    li	r5, 1
    li	r6, 1
    li	r7, 0
    bl      EXIImm
    cntlzw	r0, r3
    addi	r3, r30, 0
    srwi	r31, r0, 5
    bl      EXISync
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r3, r30, 0
    or	r31, r31, r0
    bl      EXIDeselect
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or.	r31, r31, r0
    beq     _80029db8
    li	r3, -3
    b       _80029dbc
_80029db8:
    li	r3, 0
_80029dbc:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void TimeoutHandler(void)
{
    nofralloc
    mflr	r0
    lis     r4, __CARDBlock@ha
    stw	r0, 4(r1)
    addi	r4, r4, __CARDBlock@l
    addi	r0, r4, 0xe0
    stwu	r1, -0x18(r1)
    cmplw	r3, r0
    stw	r31, 0x14(r1)
    li	r31, 0
    stw	r30, 0x10(r1)
    addi	r30, r4, 0
    beq     _80029e20
    addi	r0, r4, 0x1f0
    cmplw	r3, r0
    addi	r4, r4, 0x110
    addi	r30, r4, 0
    li	r31, 1
    beq     _80029e20
    li	r31, 2
_80029e20:
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    beq     _80029e60
    addi	r3, r31, 0
    li	r4, 0
    bl      EXISetExiCallback
    lwz	r0, 0xcc(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _80029e60
    li	r0, 0
    mtlr	r12
    stw	r0, 0xcc(r30)
    addi	r3, r31, 0
    li	r4, -5
    blrl	
_80029e60:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80029E78(void)
{
    nofralloc
    mflr	r0
    li	r5, 4
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    mulli	r4, r30, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r4
    addi	r3, r30, 0
    li	r4, 0
    bl      EXISelect
    cmpwi	r3, 0
    bne     _80029ec8
    mr	r3, r30
    bl      EXIUnlock
    li	r3, -3
    b       _8002a08c
_80029ec8:
    addi	r3, r31, 0xe0
    bl      OSCancelAlarm
    lbz	r0, 0x94(r31)
    cmpwi	r0, 0xf3
    beq     _80029f98
    bge     _80029ef0
    cmpwi	r0, 0xf1
    beq     _80029f34
    bge     _80029efc
    b       _80029f98
_80029ef0:
    cmpwi	r0, 0xf5
    bge     _80029f98
    b       _80029f34
_80029efc:
    lis	r3, -0x8000
    lwz	r0, 0xf8(r3)
    lis	r4, 0x1062
    lis     r3, TimeoutHandler@ha
    srwi	r0, r0, 2
    addi	r4, r4, 0x4dd3
    mulhwu	r0, r4, r0
    srwi	r0, r0, 6
    mulli	r6, r0, 0x64
    addi	r7, r3, TimeoutHandler@l
    addi	r3, r31, 0xe0
    li	r5, 0
    bl      OSSetAlarm
    b       _80029f98
_80029f34:
    lis	r3, -0x8000
    lwz	r4, 0xc(r31)
    lwz	r0, 0xf8(r3)
    lis	r3, -0x7ffd
    srawi	r9, r4, 0xd
    srwi	r7, r0, 2
    li	r0, 2
    li	r4, 0
    mullw	r8, r4, r0
    mulhwu	r6, r7, r0
    add	r8, r8, r6
    mullw	r5, r7, r0
    addze	r9, r9
    mullw	r6, r7, r4
    srawi	r0, r9, 0x1f
    mullw	r4, r0, r5
    mulhwu	r0, r9, r5
    addi	r7, r3, -0x622c
    add	r3, r8, r6
    add	r4, r4, r0
    mullw	r0, r9, r3
    mullw	r6, r9, r5
    addi	r3, r31, 0xe0
    add	r5, r4, r0
    bl      OSSetAlarm
_80029f98:
    lwz	r5, 0xa0(r31)
    addi	r3, r30, 0
    addi	r4, r31, 0x94
    li	r6, 1
    bl      EXIImmEx
    cmpwi	r3, 0
    bne     _80029fcc
    mr	r3, r30
    bl      EXIDeselect
    mr	r3, r30
    bl      EXIUnlock
    li	r3, -3
    b       _8002a08c
_80029fcc:
    lbz	r0, 0x94(r31)
    cmplwi	r0, 0x52
    bne     _8002a010
    lwz	r4, 0x80(r31)
    mr	r3, r30
    lwz	r5, 0x14(r31)
    li	r6, 1
    addi	r4, r4, 0x200
    bl      EXIImmEx
    cmpwi	r3, 0
    bne     _8002a010
    mr	r3, r30
    bl      EXIDeselect
    mr	r3, r30
    bl      EXIUnlock
    li	r3, -3
    b       _8002a08c
_8002a010:
    lwz	r3, 0xa4(r31)
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bne     _8002a038
    mr	r3, r30
    bl      EXIDeselect
    mr	r3, r30
    bl      EXIUnlock
    li	r3, 0
    b       _8002a08c
_8002a038:
    lbz	r0, 0x94(r31)
    cmplwi	r0, 0x52
    bne     _8002a04c
    li	r5, 0x200
    b       _8002a050
_8002a04c:
    li	r5, 0x80
_8002a050:
    lis     r3, __CARDTxHandler@ha
    lwz	r4, 0xb4(r31)
    addi	r7, r3, __CARDTxHandler@l
    lwz	r6, 0xa4(r31)
    mr	r3, r30
    bl      EXIDma
    cmpwi	r3, 0
    bne     _8002a088
    mr	r3, r30
    bl      EXIDeselect
    mr	r3, r30
    bl      EXIUnlock
    li	r3, -3
    b       _8002a08c
_8002a088:
    li	r3, 0
_8002a08c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_8002A0A4(void)
{
    nofralloc
    mflr	r0
    cmpwi	r4, 0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r3, 0
    mulli	r5, r31, 0x110
    stw	r30, 0x10(r1)
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r30, r0, r5
    blt     _8002a118
    lis     r3, fn_8002A0A4@ha
    addi	r0, r3, fn_8002A0A4@l
    lis     r3, fn_80029AF4@ha
    stw	r0, 0xdc(r30)
    addi	r5, r3, fn_80029AF4@l
    addi	r3, r31, 0
    li	r4, 0
    bl      EXILock
    cmpwi	r3, 0
    bne     _8002a104
    li	r4, 0
    b       _8002a118
_8002a104:
    li	r0, 0
    stw	r0, 0xdc(r30)
    mr	r3, r31
    bl      fn_80029E78
    mr	r4, r3
_8002a118:
    cmpwi	r4, 0
    bge     _8002a19c
    lbz	r0, 0x94(r30)
    cmpwi	r0, 0xf3
    beq     _8002a19c
    bge     _8002a148
    cmpwi	r0, 0x52
    beq     _8002a154
    blt     _8002a19c
    cmpwi	r0, 0xf1
    bge     _8002a17c
    b       _8002a19c
_8002a148:
    cmpwi	r0, 0xf5
    bge     _8002a19c
    b       _8002a17c
_8002a154:
    lwz	r0, 0xc8(r30)
    cmplwi	r0, 0
    mr	r12, r0
    beq     _8002a19c
    li	r0, 0
    mtlr	r12
    stw	r0, 0xc8(r30)
    mr	r3, r31
    blrl	
    b       _8002a19c
_8002a17c:
    lwz	r12, 0xcc(r30)
    cmplwi	r12, 0
    beq     _8002a19c
    li	r0, 0
    mtlr	r12
    stw	r0, 0xcc(r30)
    mr	r3, r31
    blrl	
_8002a19c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __CARDStart(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stmw	r27, 0x1c(r1)
    addi	r27, r3, 0
    addi	r28, r4, 0
    addi	r29, r5, 0
    bl      OSDisableInterrupts
    mulli	r5, r27, 0x110
    lis     r4, __CARDBlock@ha
    addi	r0, r4, __CARDBlock@l
    add	r31, r0, r5
    lwz	r0, 0(r31)
    addi	r30, r3, 0
    cmpwi	r0, 0
    bne     _8002a1fc
    li	r31, -3
    b       _8002a348
_8002a1fc:
    cmplwi	r28, 0
    beq     _8002a208
    stw	r28, 0xc8(r31)
_8002a208:
    cmplwi	r29, 0
    beq     _8002a214
    stw	r29, 0xcc(r31)
_8002a214:
    lis     r3, fn_8002A0A4@ha
    addi	r0, r3, fn_8002A0A4@l
    lis     r3, fn_80029AF4@ha
    stw	r0, 0xdc(r31)
    addi	r5, r3, fn_80029AF4@l
    addi	r3, r27, 0
    li	r4, 0
    bl      EXILock
    cmpwi	r3, 0
    bne     _8002a244
    li	r31, -1
    b       _8002a348
_8002a244:
    li	r0, 0
    stw	r0, 0xdc(r31)
    addi	r3, r27, 0
    li	r4, 0
    li	r5, 4
    bl      EXISelect
    cmpwi	r3, 0
    bne     _8002a274
    mr	r3, r27
    bl      EXIUnlock
    li	r31, -3
    b       _8002a348
_8002a274:
    addi	r3, r31, 0xe0
    bl      OSCancelAlarm
    lbz	r0, 0x94(r31)
    cmpwi	r0, 0xf3
    beq     _8002a344
    bge     _8002a29c
    cmpwi	r0, 0xf1
    beq     _8002a2e0
    bge     _8002a2a8
    b       _8002a344
_8002a29c:
    cmpwi	r0, 0xf5
    bge     _8002a344
    b       _8002a2e0
_8002a2a8:
    lis	r3, -0x8000
    lwz	r0, 0xf8(r3)
    lis	r4, 0x1062
    lis     r3, TimeoutHandler@ha
    srwi	r0, r0, 2
    addi	r4, r4, 0x4dd3
    mulhwu	r0, r4, r0
    srwi	r0, r0, 6
    mulli	r6, r0, 0x64
    addi	r7, r3, TimeoutHandler@l
    addi	r3, r31, 0xe0
    li	r5, 0
    bl      OSSetAlarm
    b       _8002a344
_8002a2e0:
    lis	r3, -0x8000
    lwz	r4, 0xc(r31)
    lwz	r0, 0xf8(r3)
    lis	r3, -0x7ffd
    srawi	r9, r4, 0xd
    srwi	r7, r0, 2
    li	r0, 2
    li	r4, 0
    mullw	r8, r4, r0
    mulhwu	r6, r7, r0
    add	r8, r8, r6
    mullw	r5, r7, r0
    addze	r9, r9
    mullw	r6, r7, r4
    srawi	r0, r9, 0x1f
    mullw	r4, r0, r5
    mulhwu	r0, r9, r5
    addi	r7, r3, -0x622c
    add	r3, r8, r6
    add	r4, r4, r0
    mullw	r0, r9, r3
    mullw	r6, r9, r5
    addi	r3, r31, 0xe0
    add	r5, r4, r0
    bl      OSSetAlarm
_8002a344:
    li	r31, 0
_8002a348:
    mr	r3, r30
    bl      OSRestoreInterrupts
    mr	r3, r31
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void __CARDReadSegment(void)
{
    nofralloc
    mflr	r0
    li	r6, 5
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    mulli	r5, r30, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    li	r0, 0x52
    stb	r0, 0x94(r31)
    li	r0, 0
    addi	r3, r30, 0
    lwz	r5, 0xb0(r31)
    rlwinm	r5, r5, 0xf, 0x19, 0x1f
    stb	r5, 0x95(r31)
    li	r5, 0
    lwz	r7, 0xb0(r31)
    rlwinm	r7, r7, 0x17, 0x18, 0x1f
    stb	r7, 0x96(r31)
    lwz	r7, 0xb0(r31)
    rlwinm	r7, r7, 0x19, 0x1e, 0x1f
    stb	r7, 0x97(r31)
    lwz	r7, 0xb0(r31)
    clrlwi	r7, r7, 0x19
    stb	r7, 0x98(r31)
    stw	r6, 0xa0(r31)
    stw	r0, 0xa4(r31)
    stw	r0, 0xa8(r31)
    bl      __CARDStart
    cmpwi	r3, -1
    bne     _8002a3f8
    li	r3, 0
    b       _8002a484
_8002a3f8:
    cmpwi	r3, 0
    blt     _8002a484
    lwz	r5, 0xa0(r31)
    addi	r3, r30, 0
    addi	r4, r31, 0x94
    li	r6, 1
    bl      EXIImmEx
    cmpwi	r3, 0
    beq     _8002a460
    lwz	r4, 0x80(r31)
    mr	r3, r30
    lwz	r5, 0x14(r31)
    li	r6, 1
    addi	r4, r4, 0x200
    bl      EXIImmEx
    cmpwi	r3, 0
    beq     _8002a460
    lis     r3, __CARDTxHandler@ha
    lwz	r4, 0xb4(r31)
    addi	r7, r3, __CARDTxHandler@l
    lwz	r6, 0xa4(r31)
    addi	r3, r30, 0
    li	r5, 0x200
    bl      EXIDma
    cmpwi	r3, 0
    bne     _8002a480
_8002a460:
    li	r0, 0
    stw	r0, 0xc8(r31)
    mr	r3, r30
    bl      EXIDeselect
    mr	r3, r30
    bl      EXIUnlock
    li	r3, -3
    b       _8002a484
_8002a480:
    li	r3, 0
_8002a484:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __CARDWritePage(void)
{
    nofralloc
    mflr	r0
    li	r7, 5
    stw	r0, 4(r1)
    li	r6, 1
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    mulli	r5, r30, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r5
    li	r0, 0xf2
    stb	r0, 0x94(r31)
    addi	r5, r4, 0
    li	r0, 3
    lwz	r3, 0xb0(r31)
    li	r4, 0
    rlwinm	r3, r3, 0xf, 0x19, 0x1f
    stb	r3, 0x95(r31)
    addi	r3, r30, 0
    lwz	r8, 0xb0(r31)
    rlwinm	r8, r8, 0x17, 0x18, 0x1f
    stb	r8, 0x96(r31)
    lwz	r8, 0xb0(r31)
    rlwinm	r8, r8, 0x19, 0x1e, 0x1f
    stb	r8, 0x97(r31)
    lwz	r8, 0xb0(r31)
    clrlwi	r8, r8, 0x19
    stb	r8, 0x98(r31)
    stw	r7, 0xa0(r31)
    stw	r6, 0xa4(r31)
    stw	r0, 0xa8(r31)
    bl      __CARDStart
    cmpwi	r3, -1
    bne     _8002a534
    li	r3, 0
    b       _8002a5a0
_8002a534:
    cmpwi	r3, 0
    blt     _8002a5a0
    lwz	r5, 0xa0(r31)
    addi	r3, r30, 0
    addi	r4, r31, 0x94
    li	r6, 1
    bl      EXIImmEx
    cmpwi	r3, 0
    beq     _8002a57c
    lis     r3, __CARDTxHandler@ha
    lwz	r4, 0xb4(r31)
    addi	r7, r3, __CARDTxHandler@l
    lwz	r6, 0xa4(r31)
    addi	r3, r30, 0
    li	r5, 0x80
    bl      EXIDma
    cmpwi	r3, 0
    bne     _8002a59c
_8002a57c:
    li	r0, 0
    stw	r0, 0xcc(r31)
    mr	r3, r30
    bl      EXIDeselect
    mr	r3, r30
    bl      EXIUnlock
    li	r3, -3
    b       _8002a5a0
_8002a59c:
    li	r3, 0
_8002a5a0:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __CARDEraseSector(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    mulli	r6, r29, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r6
    li	r0, 0xf1
    stb	r0, 0x94(r31)
    rlwinm	r3, r4, 0xf, 0x19, 0x1f
    rlwinm	r0, r4, 0x17, 0x18, 0x1f
    stb	r3, 0x95(r31)
    li	r6, 3
    addi	r3, r29, 0
    stb	r0, 0x96(r31)
    li	r0, -1
    li	r4, 0
    stw	r6, 0xa0(r31)
    stw	r0, 0xa4(r31)
    stw	r6, 0xa8(r31)
    bl      __CARDStart
    addi	r30, r3, 0
    cmpwi	r30, -1
    bne     _8002a630
    li	r30, 0
    b       _8002a678
_8002a630:
    cmpwi	r30, 0
    blt     _8002a678
    lwz	r5, 0xa0(r31)
    addi	r3, r29, 0
    addi	r4, r31, 0x94
    li	r6, 1
    bl      EXIImmEx
    cmpwi	r3, 0
    bne     _8002a664
    li	r0, 0
    stw	r0, 0xcc(r31)
    li	r30, -3
    b       _8002a668
_8002a664:
    li	r30, 0
_8002a668:
    mr	r3, r29
    bl      EXIDeselect
    mr	r3, r29
    bl      EXIUnlock
_8002a678:
    mr	r3, r30
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

#pragma pop
