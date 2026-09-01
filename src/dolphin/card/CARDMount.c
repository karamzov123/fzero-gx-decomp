// dolphin/card/CARDMount.c -- carved from coarse/text_80029828 (0x8002A698-0x8002AF34).
// Melee identity: CARDInit + control-block accessors + __CARDSync.
#pragma push
#pragma force_active on

extern void CARDInit(void);
extern void __CARDSetFontEncode(void);
extern void __CARDSetDiskID(void);
extern void __CARDGetDiskID(void);
extern void __CARDSetDiskIDSafe(void);
extern void __CARDGetControlBlock(void);
extern void __CARDPutControlBlock(void);
extern void CARDGetResultCode(void);
extern void CARDFreeBlocks(void);
extern void __CARDSync(void);
extern void CARDOnReset(void);
extern void __CARDBitRev(void);
extern void ReadArrayUnlock(void);
extern void GetInitVal(void);
extern void DSPInit(void);
extern void EXIDeselect(void);
extern void EXIImmEx(void);
extern void EXISelect(void);
extern void OSCreateAlarm(void);
extern void OSDisableInterrupts(void);
extern void OSGetTick(void);
extern void OSInitAlarm(void);
extern void OSInitThreadQueue(void);
extern void OSRegisterResetFunction(void);
extern void OSRegisterVersion(void);
extern void OSRestoreInterrupts(void);
extern void OSSleepThread(void);
extern void Yay0ReadyFlagUpdate(void);
extern void __CARDGetFatBlock(void);
extern void __CARDGetDirBlock(void);
extern void CARDUnmount(void);
extern void memset(void);
extern unsigned char __CARDBlock[544];
extern unsigned char lbl_8012AA50[32];

extern unsigned char lbl_801A6508[8];
extern unsigned char lbl_801A6510[8];

/* harvest: declarations carried over from the recovered
   candidate — the converted body below needs them. */
typedef int s32;
typedef unsigned short u16;
extern u16 lbl_801A6BC0;
asm void CARDInit(void)
{
    nofralloc
    mflr	r0
    lis     r3, __CARDBlock@ha
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    addi	r30, r3, __CARDBlock@l
    stw	r29, 0xc(r1)
    lwz	r0, 0x10c(r30)
    cmplwi	r0, 0
    beq     _8002a6d0
    lwz	r0, 0x21c(r30)
    cmplwi	r0, 0
    bne     _8002a728
_8002a6d0:
    bl      Yay0ReadyFlagUpdate
    sth	r3, lbl_801A6BC0
    lwz	r3, lbl_801A6508
    bl      OSRegisterVersion
    bl      DSPInit
    bl      OSInitAlarm
    li	r29, 0
    li	r31, -3
_8002a6f0:
    stw	r31, 4(r30)
    addi	r3, r30, 0x8c
    bl      OSInitThreadQueue
    addi	r3, r30, 0xe0
    bl      OSCreateAlarm
    addi	r29, r29, 1
    cmpwi	r29, 2
    addi	r30, r30, 0x110
    blt     _8002a6f0
    lis	r3, -0x8000
    bl      __CARDSetDiskID
    lis     r3, lbl_8012AA50@ha
    addi	r3, r3, lbl_8012AA50@l
    bl      OSRegisterResetFunction
_8002a728:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    lwz	r29, 0xc(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

// provenance: harvest:runs.sqlite — __CARDGetFontEncode recovered from __CARDGetFontEncode_verify.c, compiled by natc3 at 2026-08-28T04:46 and scored 100 against main/dolphin/card/CARDMount; original reference not recorded
s32 __CARDGetFontEncode(void) {
    return lbl_801A6BC0;
}

asm void __CARDSetFontEncode(void)
{
    nofralloc
    clrlwi	r0, r3, 0x10
    lhz	r4, lbl_801A6BC0
    cmpwi	r0, 2
    bge     _8002a76c
    cmpwi	r0, 0
    bge     _8002a768
    b       _8002a76c
_8002a768:
    sth	r3, lbl_801A6BC0
_8002a76c:
    mr	r3, r4
    blr	
}

asm void __CARDSetDiskID(void)
{
    nofralloc
    cmplwi	r3, 0
    lis     r4, __CARDBlock@ha
    addi	r4, r4, __CARDBlock@l
    beq     _8002a78c
    mr	r0, r3
    b       _8002a790
_8002a78c:
    addi	r0, r4, 0x220
_8002a790:
    cmplwi	r3, 0
    stw	r0, 0x10c(r4)
    beq     _8002a7a0
    b       _8002a7a4
_8002a7a0:
    addi	r3, r4, 0x220
_8002a7a4:
    stw	r3, 0x21c(r4)
    blr	
}

asm void __CARDGetDiskID(void)
{
    nofralloc
    mulli	r0, r3, 0x110
    lis     r3, __CARDBlock@ha
    addi	r3, r3, __CARDBlock@l
    add	r3, r3, r0
    lwz	r3, 0x10c(r3)
    blr	
}

asm void __CARDSetDiskIDSafe(void)
{
    nofralloc
    mflr	r0
    mulli	r5, r3, 0x110
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    stw	r31, 0x14(r1)
    add	r31, r0, r5
    stw	r30, 0x10(r1)
    addi	r30, r4, 0
    bl      OSDisableInterrupts
    lwz	r0, 4(r31)
    cmpwi	r0, -1
    bne     _8002a804
    li	r3, -1
    b       _8002a824
_8002a804:
    cmplwi	r30, 0
    beq     _8002a814
    mr	r0, r30
    b       _8002a818
_8002a814:
    lis	r0, -0x8000
_8002a818:
    stw	r0, 0x10c(r31)
    bl      OSRestoreInterrupts
    li	r3, 0
_8002a824:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __CARDGetControlBlock(void)
{
    nofralloc
    mflr	r0
    mulli	r6, r3, 0x110
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    lis     r5, __CARDBlock@ha
    cmpwi	r3, 0
    stw	r31, 0x1c(r1)
    addi	r0, r5, __CARDBlock@l
    stw	r30, 0x18(r1)
    add	r30, r0, r6
    stw	r29, 0x14(r1)
    addi	r29, r4, 0
    blt     _8002a884
    cmpwi	r3, 2
    bge     _8002a884
    lwz	r0, 0x10c(r30)
    cmplwi	r0, 0
    bne     _8002a88c
_8002a884:
    li	r3, -0x80
    b       _8002a8d8
_8002a88c:
    bl      OSDisableInterrupts
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    bne     _8002a8a4
    li	r31, -3
    b       _8002a8d0
_8002a8a4:
    lwz	r0, 4(r30)
    cmpwi	r0, -1
    bne     _8002a8b8
    li	r31, -1
    b       _8002a8d0
_8002a8b8:
    li	r0, -1
    stw	r0, 4(r30)
    li	r0, 0
    li	r31, 0
    stw	r0, 0xd0(r30)
    stw	r30, 0(r29)
_8002a8d0:
    bl      OSRestoreInterrupts
    mr	r3, r31
_8002a8d8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __CARDPutControlBlock(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, 0
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    bl      OSDisableInterrupts
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    beq     _8002a928
    stw	r31, 4(r30)
    b       _8002a938
_8002a928:
    lwz	r0, 4(r30)
    cmpwi	r0, -1
    bne     _8002a938
    stw	r31, 4(r30)
_8002a938:
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void CARDGetResultCode(void)
{
    nofralloc
    cmpwi	r3, 0
    blt     _8002a968
    cmpwi	r3, 2
    blt     _8002a970
_8002a968:
    li	r3, -0x80
    blr	
_8002a970:
    mulli	r4, r3, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r3, r0, r4
    lwz	r3, 4(r3)
    blr	
}

asm void CARDFreeBlocks(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    addi	r31, r5, 0
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    addi	r29, r4, 0
    addi	r4, r1, 0x18
    bl      __CARDGetControlBlock
    cmpwi	r3, 0
    bge     _8002a9bc
    b       _8002aabc
_8002a9bc:
    lwz	r3, 0x18(r1)
    bl      __CARDGetFatBlock
    mr	r30, r3
    lwz	r3, 0x18(r1)
    bl      __CARDGetDirBlock
    cmplwi	r30, 0
    beq     _8002a9e0
    cmplwi	r3, 0
    bne     _8002aa20
_8002a9e0:
    lwz	r30, 0x18(r1)
    bl      OSDisableInterrupts
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    beq     _8002aa00
    li	r0, -6
    stw	r0, 4(r30)
    b       _8002aa14
_8002aa00:
    lwz	r0, 4(r30)
    cmpwi	r0, -1
    bne     _8002aa14
    li	r0, -6
    stw	r0, 4(r30)
_8002aa14:
    bl      OSRestoreInterrupts
    li	r3, -6
    b       _8002aabc
_8002aa20:
    cmplwi	r29, 0
    beq     _8002aa3c
    lwz	r4, 0x18(r1)
    lhz	r0, 6(r30)
    lwz	r4, 0xc(r4)
    mullw	r0, r4, r0
    stw	r0, 0(r29)
_8002aa3c:
    cmplwi	r31, 0
    beq     _8002aa80
    li	r0, 0
    stw	r0, 0(r31)
    li	r5, 0
    b       _8002aa74
_8002aa54:
    lbz	r0, 8(r3)
    cmplwi	r0, 0xff
    bne     _8002aa6c
    lwz	r4, 0(r31)
    addi	r0, r4, 1
    stw	r0, 0(r31)
_8002aa6c:
    addi	r3, r3, 0x40
    addi	r5, r5, 1
_8002aa74:
    clrlwi	r0, r5, 0x10
    cmplwi	r0, 0x7f
    blt     _8002aa54
_8002aa80:
    lwz	r30, 0x18(r1)
    bl      OSDisableInterrupts
    lwz	r0, 0(r30)
    cmpwi	r0, 0
    beq     _8002aaa0
    li	r0, 0
    stw	r0, 4(r30)
    b       _8002aab4
_8002aaa0:
    lwz	r0, 4(r30)
    cmpwi	r0, -1
    bne     _8002aab4
    li	r0, 0
    stw	r0, 4(r30)
_8002aab4:
    bl      OSRestoreInterrupts
    li	r3, 0
_8002aabc:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void __CARDSync(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    addi	r28, r3, 0
    mulli	r4, r28, 0x110
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    add	r31, r0, r4
    bl      OSDisableInterrupts
    mr	r29, r3
    b       _8002ab1c
_8002ab14:
    addi	r3, r31, 0x8c
    bl      OSSleepThread
_8002ab1c:
    cmpwi	r28, 0
    blt     _8002ab2c
    cmpwi	r28, 2
    blt     _8002ab34
_8002ab2c:
    li	r0, -0x80
    b       _8002ab38
_8002ab34:
    lwz	r0, 4(r31)
_8002ab38:
    mr	r30, r0
    cmpwi	r30, -1
    beq     _8002ab14
    mr	r3, r29
    bl      OSRestoreInterrupts
    mr	r3, r30
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void CARDOnReset(void)
{
    nofralloc
    mflr	r0
    cmpwi	r3, 0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    bne     _8002abac
    li	r3, 0
    bl      CARDUnmount
    cmpwi	r3, -1
    beq     _8002aba4
    li	r3, 1
    bl      CARDUnmount
    cmpwi	r3, -1
    bne     _8002abac
_8002aba4:
    li	r3, 0
    b       _8002abb0
_8002abac:
    li	r3, 1
_8002abb0:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void __CARDBitRev(void)
{
    nofralloc
    li	r0, 8
    mtctr	r0
    srwi	r6, r3, 0x1f
    li	r9, 0
    li	r10, 1
    li	r7, 0
    li	r8, 0
    li	r5, 1
_8002abe0:
    cmplwi	r8, 0xf
    ble     _8002ac10
    cmplwi	r8, 0x1f
    bne     _8002abf8
    or	r7, r7, r6
    b       _8002ac2c
_8002abf8:
    slw	r0, r5, r8
    and	r0, r3, r0
    srw	r0, r0, r10
    or	r7, r7, r0
    addi	r10, r10, 2
    b       _8002ac2c
_8002ac10:
    slw	r4, r5, r8
    subfic	r0, r8, 0x1f
    subf	r0, r9, r0
    and	r4, r3, r4
    slw	r0, r4, r0
    or	r7, r7, r0
    addi	r9, r9, 1
_8002ac2c:
    addi	r8, r8, 1
    cmplwi	r8, 0xf
    ble     _8002ac60
    cmplwi	r8, 0x1f
    bne     _8002ac48
    or	r7, r7, r6
    b       _8002ac7c
_8002ac48:
    slw	r0, r5, r8
    and	r0, r3, r0
    srw	r0, r0, r10
    or	r7, r7, r0
    addi	r10, r10, 2
    b       _8002ac7c
_8002ac60:
    slw	r4, r5, r8
    subfic	r0, r8, 0x1f
    subf	r0, r9, r0
    and	r4, r3, r4
    slw	r0, r4, r0
    or	r7, r7, r0
    addi	r9, r9, 1
_8002ac7c:
    addi	r8, r8, 1
    cmplwi	r8, 0xf
    ble     _8002acb0
    cmplwi	r8, 0x1f
    bne     _8002ac98
    or	r7, r7, r6
    b       _8002accc
_8002ac98:
    slw	r0, r5, r8
    and	r0, r3, r0
    srw	r0, r0, r10
    or	r7, r7, r0
    addi	r10, r10, 2
    b       _8002accc
_8002acb0:
    slw	r4, r5, r8
    subfic	r0, r8, 0x1f
    subf	r0, r9, r0
    and	r4, r3, r4
    slw	r0, r4, r0
    or	r7, r7, r0
    addi	r9, r9, 1
_8002accc:
    addi	r8, r8, 1
    cmplwi	r8, 0xf
    ble     _8002ad00
    cmplwi	r8, 0x1f
    bne     _8002ace8
    or	r7, r7, r6
    b       _8002ad1c
_8002ace8:
    slw	r0, r5, r8
    and	r0, r3, r0
    srw	r0, r0, r10
    or	r7, r7, r0
    addi	r10, r10, 2
    b       _8002ad1c
_8002ad00:
    slw	r4, r5, r8
    subfic	r0, r8, 0x1f
    subf	r0, r9, r0
    and	r4, r3, r4
    slw	r0, r4, r0
    or	r7, r7, r0
    addi	r9, r9, 1
_8002ad1c:
    addi	r8, r8, 1
    bdnz    _8002abe0
    mr	r3, r7
    blr	
}

asm void ReadArrayUnlock(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x40(r1)
    stmw	r26, 0x28(r1)
    addi	r29, r3, 0
    lis     r3, __CARDBlock@ha
    addi	r0, r3, __CARDBlock@l
    mulli	r8, r29, 0x110
    addi	r26, r4, 0
    addi	r30, r5, 0
    addi	r31, r6, 0
    addi	r27, r7, 0
    addi	r3, r29, 0
    add	r28, r0, r8
    li	r4, 0
    li	r5, 4
    bl      EXISelect
    cmpwi	r3, 0
    bne     _8002ad80
    li	r3, -3
    b       _8002ae5c
_8002ad80:
    rlwinm	r26, r26, 0, 0, 0x13
    addi	r3, r1, 0x1c
    li	r4, 0
    li	r5, 5
    bl      memset
    li	r0, 0x52
    cmpwi	r27, 0
    stb	r0, 0x1c(r1)
    bne     _8002adc8
    rlwinm	r0, r26, 3, 0x1e, 0x1f
    stb	r0, 0x1d(r1)
    rlwinm	r0, r26, 0xb, 0x18, 0x1f
    rlwinm	r3, r26, 0xd, 0x1e, 0x1f
    stb	r0, 0x1e(r1)
    rlwinm	r0, r26, 0x14, 0x19, 0x1f
    stb	r3, 0x1f(r1)
    stb	r0, 0x20(r1)
    b       _8002add8
_8002adc8:
    srwi	r0, r26, 0x18
    stb	r0, 0x1d(r1)
    rlwinm	r0, r26, 0x10, 0x18, 0x1f
    stb	r0, 0x1e(r1)
_8002add8:
    addi	r3, r29, 0
    addi	r4, r1, 0x1c
    li	r5, 5
    li	r6, 1
    bl      EXIImmEx
    lwz	r4, 0x80(r28)
    cntlzw	r0, r3
    lwz	r5, 0x14(r28)
    addi	r3, r29, 0
    srwi	r28, r0, 5
    addi	r4, r4, 0x200
    li	r6, 1
    bl      EXIImmEx
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r3, r29, 0
    addi	r4, r30, 0
    addi	r5, r31, 0
    or	r28, r28, r0
    li	r6, 0
    bl      EXIImmEx
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r3, r29, 0
    or	r28, r28, r0
    bl      EXIDeselect
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or.	r28, r28, r0
    beq     _8002ae58
    li	r3, -3
    b       _8002ae5c
_8002ae58:
    li	r3, 0
_8002ae5c:
    lmw	r26, 0x28(r1)
    lwz	r0, 0x44(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr	
}

asm void GetInitVal(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    li	r30, 1
    stw	r29, 0x1c(r1)
    li	r29, 0
    bl      OSGetTick
    stw	r3, lbl_801A6510
    lis	r3, 0x41c6
    addi	r31, r3, 0x4e6d
    lwz	r0, lbl_801A6510
    mullw	r3, r0, r31
    addi	r0, r3, 0x3039
    stw	r0, lbl_801A6510
    lwz	r0, lbl_801A6510
    rlwinm	r3, r0, 0x10, 0x1b, 0x1f
    addi	r3, r3, 1
    b       _8002aefc
_8002aec0:
    bl      OSGetTick
    slw	r0, r3, r30
    addi	r30, r30, 1
    cmplwi	r30, 0x10
    ble     _8002aed8
    li	r30, 1
_8002aed8:
    stw	r0, lbl_801A6510
    addi	r29, r29, 1
    lwz	r0, lbl_801A6510
    mullw	r3, r0, r31
    addi	r0, r3, 0x3039
    stw	r0, lbl_801A6510
    lwz	r0, lbl_801A6510
    rlwinm	r3, r0, 0x10, 0x1b, 0x1f
    addi	r3, r3, 1
_8002aefc:
    cmpwi	r3, 4
    bge     _8002af0c
    cmplwi	r29, 0xa
    blt     _8002aec0
_8002af0c:
    cmpwi	r3, 4
    bge     _8002af18
    li	r3, 4
_8002af18:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

#pragma pop
