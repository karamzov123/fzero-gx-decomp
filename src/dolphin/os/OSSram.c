// dolphin/os/OSSram.c -- carved from coarse/text_8000DD60 (0x8000F7880x8000FCD4).
// Retail layout: Scb (.bss:0x8015BFC0, 0x54 bytes) is the SRAM control block.
// All accesses use absolute-addressed asm bodies to match retail addressing.

typedef int BOOL;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void DCInvalidateRange(register void* addr, register u32 n);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(register BOOL level);
extern s32 EXISelect(register s32 chn, register u32 dev, register u32 freq);
extern s32 EXIUnlock(register s32 chn);
extern s32 EXILock(register s32 chn, register u32 dev);
extern void EXIDeselect(register s32 chn);
extern s32 EXIImmEx(register s32 chn, register void* buf, register s32 len,
                    register u32 type);
extern s32 EXIImm(register s32 chn, register void* buf, register s32 len,
                  register u32 type, register void* callback);
extern s32 EXISync(register s32 chn);
extern s32 EXIDma(register s32 chn, register void* buf, register s32 len,
                  register u32 type, register void* callback);
extern void WriteSramCallback(void);
extern unsigned char Scb[];
#pragma push
#pragma force_active on

asm void __OSInitSram(void)
{
    nofralloc
    mflr    r0
    lis     r3, Scb@ha
    stw     r0, 4(r1)
    li      r4, 0x40
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    li      r31, 0
    stw     r30, 0x10(r1)
    addi    r30, r3, Scb@l
    addi    r3, r30, 0
    stw     r31, 0x44(r30)
    stw     r31, 0x48(r30)
    bl      DCInvalidateRange
    li      r3, 0
    li      r4, 1
    li      r5, 0
    bl      EXILock
    cmpwi   r3, 0
    bne     _L_8000f7d8
    b       _L_8000f898
_L_8000f7d8:
    li      r3, 0
    li      r4, 1
    li      r5, 3
    bl      EXISelect
    cmpwi   r3, 0
    bne     _L_8000f7fc
    li      r3, 0
    bl      EXIUnlock
    b       _L_8000f898
_L_8000f7fc:
    lis     r3, 0x2000
    addi    r0, r3, 0x100
    stw     r0, 8(r1)
    addi    r4, r1, 8
    li      r3, 0
    li      r5, 4
    li      r6, 1
    li      r7, 0
    bl      EXIImm
    cntlzw  r0, r3
    srwi    r31, r0, 5
    li      r3, 0
    bl      EXISync
    cntlzw  r0, r3
    srwi    r0, r0, 5
    addi    r4, r30, 0
    or      r31, r31, r0
    li      r3, 0
    li      r5, 0x40
    li      r6, 0
    li      r7, 0
    bl      EXIDma
    cntlzw  r0, r3
    srwi    r0, r0, 5
    or      r31, r31, r0
    li      r3, 0
    bl      EXISync
    cntlzw  r0, r3
    srwi    r0, r0, 5
    or      r31, r31, r0
    li      r3, 0
    bl      EXIDeselect
    cntlzw  r0, r3
    srwi    r0, r0, 5
    or      r31, r31, r0
    li      r3, 0
    bl      EXIUnlock
    cntlzw  r0, r31
    srwi    r31, r0, 5
_L_8000f898:
    stw     r31, 0x4c(r30)
    li      r0, 0x40
    stw     r0, 0x40(r30)
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm void __OSLockSram(void)
{
    nofralloc
    mflr    r0
    lis     r3, Scb@ha
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    addi    r31, r3, Scb@l
    bl      OSDisableInterrupts
    lwz     r0, 0x48(r31)
    addi    r4, r31, 0x48
    cmpwi   r0, 0
    beq     _L_8000f8f4
    bl      OSRestoreInterrupts
    li      r31, 0
    b       _L_8000f900
_L_8000f8f4:
    stw     r3, 0x44(r31)
    li      r0, 1
    stw     r0, 0(r4)
_L_8000f900:
    mr      r3, r31
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}

asm void __OSLockSramEx(void)
{
    nofralloc
    mflr    r0
    lis     r3, Scb@ha
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    addi    r31, r3, Scb@l
    bl      OSDisableInterrupts
    lwz     r0, 0x48(r31)
    addi    r4, r31, 0x48
    cmpwi   r0, 0
    beq     _L_8000f950
    bl      OSRestoreInterrupts
    li      r3, 0
    b       _L_8000f960
_L_8000f950:
    stw     r3, 0x44(r31)
    li      r0, 1
    addi    r3, r31, 0x14
    stw     r0, 0(r4)
_L_8000f960:
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}

asm s32 __OSUnlockSramCore(register u32 doWrite, register u32 offset)
{
    nofralloc
    mflr    r0
    cmpwi   r3, 0
    stw     r0, 4(r1)
    lis     r3, Scb@ha
    stwu    r1, -0x30(r1)
    stmw    r27, 0x1c(r1)
    addi    r31, r3, Scb@l
    beq     _L_8000fc54
    cmplwi  r4, 0
    bne     _L_8000fb48
    lbz     r3, 0x13(r31)
    clrlwi  r0, r3, 0x1e
    cmplwi  r0, 2
    ble     _L_8000f9b4
    rlwinm  r0, r3, 0, 0, 0x1d
    stb     r0, 0x13(r31)
_L_8000f9b4:
    li      r0, 0
    sth     r0, 2(r31)
    addi    r5, r31, 0x14
    addi    r6, r31, 0xc
    addi    r3, r5, 1
    sth     r0, 0(r31)
    subf    r3, r6, r3
    cmplw   r6, r5
    srwi    r3, r3, 1
    bge     _L_8000fb48
    rlwinm. r0, r3, 0x1d, 3, 0x1f
    mtctr   r0
    beq     _L_8000fb18
_L_8000f9e8:
    lhz     r5, 0(r31)
    lhz     r0, 0(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 0(r6)
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    lhz     r5, 0(r31)
    lhz     r0, 2(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 2(r6)
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    lhz     r5, 0(r31)
    lhz     r0, 4(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 4(r6)
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    lhz     r5, 0(r31)
    lhz     r0, 6(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 6(r6)
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    lhz     r5, 0(r31)
    lhz     r0, 8(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 8(r6)
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    lhz     r5, 0(r31)
    lhz     r0, 0xa(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 0xa(r6)
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    lhz     r5, 0(r31)
    lhz     r0, 0xc(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 0xc(r6)
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    lhz     r5, 0(r31)
    lhz     r0, 0xe(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 0xe(r6)
    addi    r6, r6, 0x10
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    bdnz    _L_8000f9e8
    andi.   r3, r3, 7
    beq     _L_8000fb48
_L_8000fb18:
    mtctr   r3
_L_8000fb1c:
    lhz     r5, 0(r31)
    lhz     r0, 0(r6)
    add     r0, r5, r0
    sth     r0, 0(r31)
    lhz     r0, 0(r6)
    addi    r6, r6, 2
    lhz     r5, 2(r31)
    nor     r0, r0, r0
    add     r0, r5, r0
    sth     r0, 2(r31)
    bdnz    _L_8000fb1c
_L_8000fb48:
    addi    r30, r31, 0x40
    lwz     r0, 0x40(r31)
    cmplw   r4, r0
    bge     _L_8000fb5c
    stw     r4, 0(r30)
_L_8000fb5c:
    lwz     r29, 0(r30)
    lis     r3, WriteSramCallback@ha
    addi    r5, r3, WriteSramCallback@l
    subfic  r27, r29, 0x40
    add     r28, r31, r29
    li      r3, 0
    li      r4, 1
    bl      EXILock
    cmpwi   r3, 0
    bne     _L_8000fb8c
    li      r0, 0
    b       _L_8000fc3c
_L_8000fb8c:
    li      r3, 0
    li      r4, 1
    li      r5, 3
    bl      EXISelect
    cmpwi   r3, 0
    bne     _L_8000fbb4
    li      r3, 0
    bl      EXIUnlock
    li      r0, 0
    b       _L_8000fc3c
_L_8000fbb4:
    slwi    r3, r29, 6
    addi    r0, r3, 0x100
    oris    r0, r0, 0xa000
    stw     r0, 0x10(r1)
    addi    r4, r1, 0x10
    li      r3, 0
    li      r5, 4
    li      r6, 1
    li      r7, 0
    bl      EXIImm
    cntlzw  r0, r3
    srwi    r29, r0, 5
    li      r3, 0
    bl      EXISync
    cntlzw  r0, r3
    srwi    r0, r0, 5
    addi    r4, r28, 0
    addi    r5, r27, 0
    or      r29, r29, r0
    li      r3, 0
    li      r6, 1
    bl      EXIImmEx
    cntlzw  r0, r3
    srwi    r0, r0, 5
    or      r29, r29, r0
    li      r3, 0
    bl      EXIDeselect
    cntlzw  r0, r3
    srwi    r0, r0, 5
    or      r29, r29, r0
    li      r3, 0
    bl      EXIUnlock
    cntlzw  r0, r29
    srwi    r0, r0, 5
_L_8000fc3c:
    stw     r0, 0x4c(r31)
    lwz     r0, 0x4c(r31)
    cmpwi   r0, 0
    beq     _L_8000fc54
    li      r0, 0x40
    stw     r0, 0(r30)
_L_8000fc54:
    li      r0, 0
    stw     r0, 0x48(r31)
    lwz     r3, 0x44(r31)
    bl      OSRestoreInterrupts
    lwz     r3, 0x4c(r31)
    lmw     r27, 0x1c(r1)
    lwz     r0, 0x34(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr
}

asm void __OSUnlockSram(void)
{
    nofralloc
    mflr    r0
    li      r4, 0
    stw     r0, 4(r1)
    stwu    r1, -8(r1)
    bl      __OSUnlockSramCore
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr
}

asm void __OSUnlockSramEx(void)
{
    nofralloc
    mflr    r0
    li      r4, 0x14
    stw     r0, 4(r1)
    stwu    r1, -8(r1)
    bl      __OSUnlockSramCore
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr
}

u32 __OSSyncSram(void)
{
    return *(volatile unsigned long*)((char*)Scb + 0x4C);
}

#pragma pop
