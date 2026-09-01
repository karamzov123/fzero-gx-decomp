#pragma push
#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void OSRestoreInterrupts(register s32 enabled);
extern void DCInvalidateRange(register void* addr, register unsigned long n);
extern s32 EXILock(register s32 chn, register u32 dev, register void* callback);
extern s32 EXISelect(register s32 chn, register u32 dev, register u32 freq);
extern s32 EXIUnlock(register s32 chn);
extern s32 EXIImm(register s32 chn, register void* buf, register s32 len, register u32 type, register void* callback);
extern s32 EXISync(register s32 chn);
extern s32 EXIDma(register s32 chn, register void* buf, register s32 len, register u32 type, register void* callback);
extern s32 __OSUnlockSramCore(register u32 doWrite, register u32 offset);
extern unsigned char Scb[];


/* harvest: declarations carried over from the recovered
   candidate — the converted body below needs them. */
extern s32 OSDisableInterrupts(void);
extern s32 EXIDeselect(register s32 chn);
// provenance: harvest:runs.sqlite — __OSReadROM recovered from cand1.c, compiled by natc1 at 2026-08-26T05:17 and scored 100 against main/dolphin/os/OSRtc; original reference not recorded
// provenance: dolsdk2001:src/os/OSRtc.c:227
int __OSReadROM(register void* buffer, register long length, register long offset)
{
    int err;
    unsigned long cmd;

    DCInvalidateRange(buffer, length);
    if (!EXILock(0, 1, 0)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    cmd = offset << 6;
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, 0);
    err |= !EXISync(0);
    err |= !EXIDma(0, buffer, length, 0, 0);
    err |= !EXISync(0);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

asm u32 OSGetSoundMode(void)
{
    nofralloc
    mflr	r0
    lis     r3, Scb@ha
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, Scb@l
    bl      OSDisableInterrupts
    lwz	r0, 0x48(r31)
    addi	r4, r31, 0x48
    cmpwi	r0, 0
    beq     _8000fe30
    bl      OSRestoreInterrupts
    li	r31, 0
    b       _8000fe3c
_8000fe30:
    stw	r3, 0x44(r31)
    li	r0, 1
    stw	r0, 0(r4)
_8000fe3c:
    lbz	r0, 0x13(r31)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    beq     _8000fe50
    li	r31, 1
    b       _8000fe54
_8000fe50:
    li	r31, 0
_8000fe54:
    li	r3, 0
    li	r4, 0
    bl      __OSUnlockSramCore
    mr	r3, r31
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm u32 OSGetProgressiveMode(void)
{
    nofralloc
    mflr	r0
    lis     r3, Scb@ha
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r3, Scb@l
    bl      OSDisableInterrupts
    lwz	r0, 0x48(r31)
    addi	r4, r31, 0x48
    cmpwi	r0, 0
    beq     _8000feb0
    bl      OSRestoreInterrupts
    li	r31, 0
    b       _8000febc
_8000feb0:
    stw	r3, 0x44(r31)
    li	r0, 1
    stw	r0, 0(r4)
_8000febc:
    lbz	r0, 0x13(r31)
    li	r3, 0
    li	r4, 0
    rlwinm	r31, r0, 0x19, 0x1f, 0x1f
    bl      __OSUnlockSramCore
    mr	r3, r31
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void OSSetProgressiveMode(register u32 mode)
{
    nofralloc
    mflr	r0
    lis     r4, Scb@ha
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, Scb@l
    stw	r30, 0x18(r1)
    rlwinm	r30, r3, 7, 0x18, 0x18
    bl      OSDisableInterrupts
    lwz	r0, 0x48(r31)
    addi	r4, r31, 0x48
    cmpwi	r0, 0
    beq     _8000ff28
    bl      OSRestoreInterrupts
    li	r31, 0
    b       _8000ff34
_8000ff28:
    stw	r3, 0x44(r31)
    li	r0, 1
    stw	r0, 0(r4)
_8000ff34:
    lbz	r3, 0x13(r31)
    rlwinm	r0, r3, 0, 0x18, 0x18
    cmplw	r30, r0
    bne     _8000ff54
    li	r3, 0
    li	r4, 0
    bl      __OSUnlockSramCore
    b       _8000ff74
_8000ff54:
    rlwinm	r0, r3, 0, 0x19, 0x17
    stb	r0, 0x13(r31)
    li	r3, 1
    li	r4, 0
    lbz	r0, 0x13(r31)
    or	r0, r0, r30
    stb	r0, 0x13(r31)
    bl      __OSUnlockSramCore
_8000ff74:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm u16 OSGetWirelessID(register s32 channel)
{
    nofralloc
    mflr	r0
    lis     r4, Scb@ha
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, Scb@l
    stw	r30, 0x18(r1)
    addi	r30, r3, 0
    bl      OSDisableInterrupts
    lwz	r0, 0x48(r31)
    addi	r4, r31, 0x48
    cmpwi	r0, 0
    beq     _8000ffcc
    bl      OSRestoreInterrupts
    li	r3, 0
    b       _8000ffdc
_8000ffcc:
    stw	r3, 0x44(r31)
    li	r0, 1
    addi	r3, r31, 0x14
    stw	r0, 0(r4)
_8000ffdc:
    slwi	r0, r30, 1
    add	r3, r3, r0
    lhz	r31, 0x1c(r3)
    li	r3, 0
    li	r4, 0x14
    bl      __OSUnlockSramCore
    mr	r3, r31
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void OSSetWirelessID(register s32 channel, register u16 id)
{
    nofralloc
    mflr	r0
    lis     r5, Scb@ha
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r5, Scb@l
    stw	r30, 0x20(r1)
    addi	r30, r4, 0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    bl      OSDisableInterrupts
    lwz	r0, 0x48(r31)
    addi	r4, r31, 0x48
    cmpwi	r0, 0
    beq     _80010058
    bl      OSRestoreInterrupts
    li	r3, 0
    b       _80010068
_80010058:
    stw	r3, 0x44(r31)
    li	r0, 1
    addi	r3, r31, 0x14
    stw	r0, 0(r4)
_80010068:
    slwi	r0, r29, 1
    add	r4, r3, r0
    lhzu	r3, 0x1c(r4)
    clrlwi	r0, r30, 0x10
    cmplw	r3, r0
    beq     _80010094
    sth	r30, 0(r4)
    li	r3, 1
    li	r4, 0x14
    bl      __OSUnlockSramCore
    b       _800100a0
_80010094:
    li	r3, 0
    li	r4, 0x14
    bl      __OSUnlockSramCore
_800100a0:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

#pragma pop
