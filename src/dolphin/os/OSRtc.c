#pragma push
#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(register s32 enabled);
extern void DCInvalidateRange(register void* addr, register unsigned long n);
extern s32 EXILock(register s32 chn, register u32 dev, register void* callback);
extern s32 EXISelect(register s32 chn, register u32 dev, register u32 freq);
extern s32 EXIUnlock(register s32 chn);
extern s32 EXIImm(register s32 chn, register void* buf, register s32 len, register u32 type, register void* callback);
extern s32 EXISync(register s32 chn);
extern s32 EXIDma(register s32 chn, register void* buf, register s32 len, register u32 type, register void* callback);
extern void EXIDeselect(register s32 chn);
extern s32 fn_8000F974(register u32 doWrite, register u32 offset);

asm int __OSReadROM(register void* buffer, register long length, register long offset)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r5, 0
    stw	r30, 0x20(r1)
    addi	r30, r4, 0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    bl      DCInvalidateRange
    li	r3, 0
    li	r4, 1
    li	r5, 0
    bl      EXILock
    cmpwi	r3, 0
    bne     _8000fd1c
    li	r3, 0
    b       _8000fddc
_8000fd1c:
    li	r3, 0
    li	r4, 1
    li	r5, 3
    bl      EXISelect
    cmpwi	r3, 0
    bne     _8000fd44
    li	r3, 0
    bl      EXIUnlock
    li	r3, 0
    b       _8000fddc
_8000fd44:
    slwi	r0, r31, 6
    stw	r0, 0x14(r1)
    addi	r4, r1, 0x14
    li	r3, 0
    li	r5, 4
    li	r6, 1
    li	r7, 0
    bl      EXIImm
    cntlzw	r0, r3
    srwi	r31, r0, 5
    li	r3, 0
    bl      EXISync
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r4, r29, 0
    addi	r5, r30, 0
    or	r31, r31, r0
    li	r3, 0
    li	r6, 0
    li	r7, 0
    bl      EXIDma
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r31, r31, r0
    li	r3, 0
    bl      EXISync
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r31, r31, r0
    li	r3, 0
    bl      EXIDeselect
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r31, r31, r0
    li	r3, 0
    bl      EXIUnlock
    cntlzw	r0, r31
    srwi	r3, r0, 5
_8000fddc:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm u32 OSGetSoundMode(void)
{
    nofralloc
    mflr	r0
    lis     r3, -0x7fea
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, -0x4040
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
    bl      fn_8000F974
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
    lis     r3, -0x7fea
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r3, -0x4040
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
    bl      fn_8000F974
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
    lis     r4, -0x7fea
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, -0x4040
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
    bl      fn_8000F974
    b       _8000ff74
_8000ff54:
    rlwinm	r0, r3, 0, 0x19, 0x17
    stb	r0, 0x13(r31)
    li	r3, 1
    li	r4, 0
    lbz	r0, 0x13(r31)
    or	r0, r0, r30
    stb	r0, 0x13(r31)
    bl      fn_8000F974
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
    lis     r4, -0x7fea
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, -0x4040
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
    bl      fn_8000F974
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
    lis     r5, -0x7fea
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r5, -0x4040
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
    bl      fn_8000F974
    b       _800100a0
_80010094:
    li	r3, 0
    li	r4, 0x14
    bl      fn_8000F974
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
