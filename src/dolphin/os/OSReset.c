typedef int BOOL;
typedef signed char s8;
typedef short s16;
typedef long long s64;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
#pragma push
#pragma force_active on

extern void OSDisableInterrupts(void);
extern void ICFlashInvalidate(void);
extern void __OSStopAudioSystem(void);
extern s32 __PADDisableRecalibration(s32);
extern BOOL __OSSyncSram(void);
extern void* __OSLockSram(void);
extern s32 __OSUnlockSram(s32 commit);
extern void LCDisable(void);
extern void OSCancelThread(void* thread);
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern void __OSReboot(u32 resetCode, u32 bootDol);
extern void memset(void* ptr, s32 val, u32 size);

asm void OSRegisterResetFunction(register void* info)
{
    nofralloc
    lwz	r5, -0x7bf0(r13)
    b       _8000ee7c
_8000ee78:
    lwz	r5, 8(r5)
_8000ee7c:
    cmplwi	r5, 0
    beq     _8000ee94
    lwz	r4, 4(r5)
    lwz	r0, 4(r3)
    cmplw	r4, r0
    ble     _8000ee78
_8000ee94:
    cmplwi	r5, 0
    bne     _8000eecc
    addi	r5, r13, -0x7bf0
    lwzu	r4, 4(r5)
    cmplwi	r4, 0
    bne     _8000eeb4
    stw	r3, -0x7bf0(r13)
    b       _8000eeb8
_8000eeb4:
    stw	r3, 8(r4)
_8000eeb8:
    stw	r4, 0xc(r3)
    li	r0, 0
    stw	r0, 8(r3)
    stw	r3, 0(r5)
    blr	
_8000eecc:
    stw	r5, 8(r3)
    lwz	r4, 0xc(r5)
    stw	r3, 0xc(r5)
    cmplwi	r4, 0
    stw	r4, 0xc(r3)
    bne     _8000eeec
    stw	r3, -0x7bf0(r13)
    blr	
_8000eeec:
    stw	r3, 8(r4)
    blr	
}

static asm void Reset(register unsigned long resetCode)
{
    nofralloc
    b       _8000ef14
_8000eef8:
    mfspr	r8, 1008
    ori	r8, r8, 8
    mtspr	0x3f0, r8
    isync	
    sync	
    nop	
    b       _8000ef18
_8000ef14:
    b       _8000ef34
_8000ef18:
    mftb	r5, 268
_8000ef1c:
    mftb	r6, 268
    subf	r7, r5, r6
    cmplwi	r7, 0x1124
    blt     _8000ef1c
    nop	
    b       _8000ef38
_8000ef34:
    b       _8000ef54
_8000ef38:
    lis	r8, -0x3400
    ori	r8, r8, 0x3000
    li	r4, 3
    stw	r4, 0x24(r8)
    stw	r3, 0x24(r8)
    nop	
    b       _8000ef58
_8000ef54:
    b       _8000ef60
_8000ef58:
    nop	
    b       _8000ef58
_8000ef60:
    b       _8000eef8
}

asm void __OSDoHotReset(register int arg0)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lis	r3, -0x3400
    addi	r3, r3, 0x2000
    li	r0, 0
    sth	r0, 2(r3)
    bl      ICFlashInvalidate
    slwi	r3, r31, 3
    bl      Reset
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void OSResetSystem(register int reset, register unsigned long resetCode, register int forceMenu)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x40(r1)
    stmw	r26, 0x28(r1)
    mr	r26, r3
    mr	r29, r4
    mr	r30, r5
    bl      OSDisableScheduler
    bl      __OSStopAudioSystem
    cmpwi	r26, 2
    bne     _8000efe4
    li	r3, 1
    bl      __PADDisableRecalibration
    mr	r31, r3
_8000efe4:
    b       _8000efe8
_8000efe8:
    b       _8000efec
_8000efec:
    lwz	r27, -0x7bf0(r13)
    li	r28, 0
    b       _8000eff8
_8000eff8:
    b       _8000effc
_8000effc:
    b       _8000f020
_8000f000:
    li	r3, 0
    lwz	r12, 0(r27)
    mtlr	r12
    blrl	
    cntlzw	r0, r3
    lwz	r27, 8(r27)
    srwi	r0, r0, 5
    or	r28, r28, r0
_8000f020:
    cmplwi	r27, 0
    beq     _8000f030
    cmpwi	r28, 0
    beq     _8000f000
_8000f030:
    bl      __OSSyncSram
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r28, r28, r0
    cmpwi	r28, 0
    beq     _8000f050
    li	r0, 0
    b       _8000f054
_8000f050:
    li	r0, 1
_8000f054:
    cmpwi	r0, 0
    beq     _8000efec
    cmpwi	r26, 1
    bne     _8000f098
    cmpwi	r30, 0
    beq     _8000f098
    bl      __OSLockSram
    lbz	r0, 0x13(r3)
    ori	r0, r0, 0x40
    stb	r0, 0x13(r3)
    li	r3, 1
    bl      __OSUnlockSram
    b       _8000f088
_8000f088:
    b       _8000f08c
_8000f08c:
    bl      __OSSyncSram
    cmpwi	r3, 0
    beq     _8000f08c
_8000f098:
    bl      OSDisableInterrupts
    lwz	r28, -0x7bf0(r13)
    li	r27, 0
    b       _8000f0a8
_8000f0a8:
    b       _8000f0ac
_8000f0ac:
    b       _8000f0d0
_8000f0b0:
    li	r3, 1
    lwz	r12, 0(r28)
    mtlr	r12
    blrl	
    cntlzw	r0, r3
    lwz	r28, 8(r28)
    srwi	r0, r0, 5
    or	r27, r27, r0
_8000f0d0:
    cmplwi	r28, 0
    beq     _8000f0e0
    cmpwi	r27, 0
    beq     _8000f0b0
_8000f0e0:
    bl      __OSSyncSram
    bl      LCDisable
    cmpwi	r26, 1
    bne     _8000f114
    bl      OSDisableInterrupts
    lis	r3, -0x3400
    addi	r3, r3, 0x2000
    li	r0, 0
    sth	r0, 2(r3)
    bl      ICFlashInvalidate
    slwi	r3, r29, 3
    bl      Reset
    b       _8000f170
_8000f114:
    cmpwi	r26, 0
    bne     _8000f170
    lis	r3, -0x8000
    lwz	r3, 0xdc(r3)
    b       _8000f128
_8000f128:
    b       _8000f12c
_8000f12c:
    b       _8000f158
_8000f130:
    lhz	r0, 0x2c8(r3)
    lwz	r27, 0x2fc(r3)
    cmpwi	r0, 4
    beq     _8000f150
    bge     _8000f154
    cmpwi	r0, 1
    beq     _8000f150
    b       _8000f154
_8000f150:
    bl      OSCancelThread
_8000f154:
    mr	r3, r27
_8000f158:
    cmplwi	r3, 0
    bne     _8000f130
    bl      OSEnableScheduler
    mr	r3, r29
    mr	r4, r30
    bl      __OSReboot
_8000f170:
    lis	r3, -0x8000
    lwz	r3, 0xdc(r3)
    b       _8000f17c
_8000f17c:
    b       _8000f180
_8000f180:
    b       _8000f1ac
_8000f184:
    lhz	r0, 0x2c8(r3)
    lwz	r27, 0x2fc(r3)
    cmpwi	r0, 4
    beq     _8000f1a4
    bge     _8000f1a8
    cmpwi	r0, 1
    beq     _8000f1a4
    b       _8000f1a8
_8000f1a4:
    bl      OSCancelThread
_8000f1a8:
    mr	r3, r27
_8000f1ac:
    cmplwi	r3, 0
    bne     _8000f184
    lis	r29, -0x8000
    addi	r3, r29, 0x40
    li	r4, 0
    li	r5, 0x8c
    bl      memset
    addi	r3, r29, 0xd4
    li	r4, 0
    li	r5, 0x14
    bl      memset
    addi	r3, r29, 0xf4
    li	r4, 0
    li	r5, 4
    bl      memset
    addi	r3, r29, 0x3000
    li	r4, 0
    li	r5, 0xc0
    bl      memset
    addi	r3, r29, 0x30c8
    li	r4, 0
    li	r5, 0xc
    bl      memset
    addi	r3, r29, 0x30e2
    li	r4, 0
    li	r5, 1
    bl      memset
    mr	r3, r31
    bl      __PADDisableRecalibration
    lmw	r26, 0x28(r1)
    lwz	r0, 0x44(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr	
}

asm unsigned long OSGetResetCode(void)
{
    nofralloc
    lis	r3, -0x8000
    lbz	r0, 0x30e2(r3)
    cmplwi	r0, 0
    beq     _8000f24c
    lis	r3, -0x8000
    b       _8000f260
_8000f24c:
    lis	r3, -0x3400
    addi	r3, r3, 0x3000
    lwz	r0, 0x24(r3)
    rlwinm	r0, r0, 0, 0, 0x1c
    srwi	r3, r0, 3
_8000f260:
    blr	
}

#pragma pop
