// dolphin/card/CARDStat.c -- carved from coarse/text_8002F5B8 (0x8002FC5C-0x800300F4).
// Melee identity: extern/dolphin/src/dolphin/card/CARDStat.c
extern void __CARDSyncCallback(void); // 0x80029828
//   UpdateIconOffsets (static), CARDGetStatus, CARDSetStatusAsync, CARDSetStatus.
// CARDDirEntry: gameName@0 company@4 fileName@8 bannerFormat(b)@7 iconAddr@0x2c
//   time@0x28 iconFormat(h)@0x30 iconSpeed(h)@0x32 permission(b)@0x34
//   length(u16)@0x38 commentAddr@0x3c.
// CARDStat: fileName@0 length@0x20 time@0x24 gameName@0x28 company@0x2c
//   bannerFormat(b)@0x2e iconAddr@0x30 iconFormat(h)@0x34 iconSpeed(h)@0x36
//   commentAddr@0x38 offsetBanner@0x3c offsetBannerTlut@0x40 offsetIcon[8]@0x44
//   offsetIconTlut@0x64 offsetData@0x68.

typedef int BOOL;
typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;

extern s32 __CARDGetControlBlock(register void* card, register void** pctrl);
extern void __CARDPutControlBlock(register void* ctrl, register s32 err);
extern s32 __CARDGetDirBlock(void);
extern s32 fn_8002E9BC(register void* ctrl, register void* ent);
extern s32 fn_8002EA54(register void* ent);
extern void* memcpy(register void* dst, register void* src, register u32 n);
extern s32 __CARDUpdateDir(register s32 chn, register void* callback);
extern s32 __CARDSync(register s32 chn);
extern unsigned long long OSGetTime(void);
extern long long __div2i(long long a, long long b);

#pragma push
#pragma force_active on

asm void UpdateIconOffsets(register void* ent, register void* stat)
{
    nofralloc
    lwz     r8, 0x2c(r3)
    addis   r0, r8, 1
    cmplwi  r0, 0xffff
    bne     _L_8002fc80
    li      r0, 0
    stb     r0, 0x2e(r4)
    li      r8, 0
    sth     r0, 0x34(r4)
    sth     r0, 0x36(r4)
_L_8002fc80:
    lbz     r0, 7(r3)
    li      r9, 0
    clrlwi  r0, r0, 0x1e
    cmpwi   r0, 2
    beq     _L_8002fcb8
    bge     _L_8002fccc
    cmpwi   r0, 1
    bge     _L_8002fca4
    b       _L_8002fccc
_L_8002fca4:
    stw     r8, 0x3c(r4)
    addi    r0, r8, 0xc00
    addi    r8, r8, 0xe00
    stw     r0, 0x40(r4)
    b       _L_8002fcd8
_L_8002fcb8:
    stw     r8, 0x3c(r4)
    li      r0, -1
    addi    r8, r8, 0x1800
    stw     r0, 0x40(r4)
    b       _L_8002fcd8
_L_8002fccc:
    li      r0, -1
    stw     r0, 0x3c(r4)
    stw     r0, 0x40(r4)
_L_8002fcd8:
    li      r0, 2
    mtctr   r0
    addi    r7, r4, 0
    li      r10, 0
    li      r6, 0
    li      r0, -1
_L_8002fcf0:
    lhz     r5, 0x30(r3)
    sraw    r5, r5, r6
    clrlwi  r5, r5, 0x1e
    cmpwi   r5, 2
    beq     _L_8002fd24
    bge     _L_8002fd30
    cmpwi   r5, 1
    bge     _L_8002fd14
    b       _L_8002fd30
_L_8002fd14:
    stw     r8, 0x44(r7)
    li      r9, 1
    addi    r8, r8, 0x400
    b       _L_8002fd34
_L_8002fd24:
    stw     r8, 0x44(r7)
    addi    r8, r8, 0x800
    b       _L_8002fd34
_L_8002fd30:
    stw     r0, 0x44(r7)
_L_8002fd34:
    lhz     r5, 0x30(r3)
    addi    r6, r6, 2
    addi    r7, r7, 4
    sraw    r5, r5, r6
    clrlwi  r5, r5, 0x1e
    cmpwi   r5, 2
    beq     _L_8002fd70
    bge     _L_8002fd7c
    cmpwi   r5, 1
    bge     _L_8002fd60
    b       _L_8002fd7c
_L_8002fd60:
    stw     r8, 0x44(r7)
    li      r9, 1
    addi    r8, r8, 0x400
    b       _L_8002fd80
_L_8002fd70:
    stw     r8, 0x44(r7)
    addi    r8, r8, 0x800
    b       _L_8002fd80
_L_8002fd7c:
    stw     r0, 0x44(r7)
_L_8002fd80:
    lhz     r5, 0x30(r3)
    addi    r6, r6, 2
    addi    r10, r10, 1
    sraw    r5, r5, r6
    clrlwi  r5, r5, 0x1e
    cmpwi   r5, 2
    addi    r7, r7, 4
    beq     _L_8002fdc0
    bge     _L_8002fdcc
    cmpwi   r5, 1
    bge     _L_8002fdb0
    b       _L_8002fdcc
_L_8002fdb0:
    stw     r8, 0x44(r7)
    li      r9, 1
    addi    r8, r8, 0x400
    b       _L_8002fdd0
_L_8002fdc0:
    stw     r8, 0x44(r7)
    addi    r8, r8, 0x800
    b       _L_8002fdd0
_L_8002fdcc:
    stw     r0, 0x44(r7)
_L_8002fdd0:
    lhz     r5, 0x30(r3)
    addi    r6, r6, 2
    addi    r10, r10, 1
    sraw    r5, r5, r6
    clrlwi  r5, r5, 0x1e
    cmpwi   r5, 2
    addi    r7, r7, 4
    beq     _L_8002fe10
    bge     _L_8002fe1c
    cmpwi   r5, 1
    bge     _L_8002fe00
    b       _L_8002fe1c
_L_8002fe00:
    stw     r8, 0x44(r7)
    li      r9, 1
    addi    r8, r8, 0x400
    b       _L_8002fe20
_L_8002fe10:
    stw     r8, 0x44(r7)
    addi    r8, r8, 0x800
    b       _L_8002fe20
_L_8002fe1c:
    stw     r0, 0x44(r7)
_L_8002fe20:
    addi    r6, r6, 2
    addi    r7, r7, 4
    addi    r10, r10, 1
    bdnz    _L_8002fcf0
    cmpwi   r9, 0
    beq     _L_8002fe44
    stw     r8, 0x64(r4)
    addi    r8, r8, 0x200
    b       _L_8002fe4c
_L_8002fe44:
    li      r0, -1
    stw     r0, 0x64(r4)
_L_8002fe4c:
    stw     r8, 0x68(r4)
    blr
}
asm s32 CARDGetStatus(register s32 chan, register s32 fileNo, register void* stat)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x28(r1)
    stw     r31, 0x24(r1)
    addi    r31, r5, 0
    stw     r30, 0x20(r1)
    stw     r29, 0x1c(r1)
    or.     r29, r4, r4
    blt     _L_8002fe80
    cmpwi   r29, 0x7f
    blt     _L_8002fe88
_L_8002fe80:
    li      r3, -0x80
    b       _L_8002ff64
_L_8002fe88:
    addi    r4, r1, 0x14
    bl      __CARDGetControlBlock
    cmpwi   r3, 0
    bge     _L_8002fe9c
    b       _L_8002ff64
_L_8002fe9c:
    lwz     r3, 0x14(r1)
    bl      __CARDGetDirBlock
    slwi    r0, r29, 6
    add     r29, r3, r0
    lwz     r3, 0x14(r1)
    mr      r4, r29
    bl      fn_8002E9BC
    addi    r30, r3, 0
    cmpwi   r30, -0xa
    bne     _L_8002fed0
    mr      r3, r29
    bl      fn_8002EA54
    mr      r30, r3
_L_8002fed0:
    cmpwi   r30, 0
    blt     _L_8002ff58
    addi    r4, r29, 0
    addi    r3, r31, 0x28
    li      r5, 4
    bl      memcpy
    addi    r3, r31, 0x2c
    addi    r4, r29, 4
    li      r5, 2
    bl      memcpy
    lwz     r5, 0x14(r1)
    mr      r3, r31
    lhz     r6, 0x38(r29)
    addi    r4, r29, 8
    lwz     r0, 0xc(r5)
    li      r5, 0x20
    mullw   r0, r6, r0
    stw     r0, 0x20(r31)
    bl      memcpy
    lwz     r0, 0x28(r29)
    addi    r3, r29, 0
    addi    r4, r31, 0
    stw     r0, 0x24(r31)
    lbz     r0, 7(r29)
    stb     r0, 0x2e(r31)
    lwz     r0, 0x2c(r29)
    stw     r0, 0x30(r31)
    lhz     r0, 0x30(r29)
    sth     r0, 0x34(r31)
    lhz     r0, 0x32(r29)
    sth     r0, 0x36(r31)
    lwz     r0, 0x3c(r29)
    stw     r0, 0x38(r31)
    bl      UpdateIconOffsets
_L_8002ff58:
    lwz     r3, 0x14(r1)
    mr      r4, r30
    bl      __CARDPutControlBlock
_L_8002ff64:
    lwz     r0, 0x2c(r1)
    lwz     r31, 0x24(r1)
    lwz     r30, 0x20(r1)
    lwz     r29, 0x1c(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr
}

asm s32 CARDSetStatusAsync(register s32 chan, register s32 fileNo, register void* stat,
                           register void* callback)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x30(r1)
    stw     r31, 0x2c(r1)
    or.     r31, r4, r4
    stw     r30, 0x28(r1)
    addi    r30, r6, 0
    stw     r29, 0x24(r1)
    addi    r29, r5, 0
    stw     r28, 0x20(r1)
    addi    r28, r3, 0
    blt     _L_8002ffec
    cmpwi   r31, 0x7f
    bge     _L_8002ffec
    lwz     r3, 0x30(r29)
    addis   r0, r3, 1
    cmplwi  r0, 0xffff
    beq     _L_8002ffd0
    cmplwi  r3, 0x200
    bge     _L_8002ffec
_L_8002ffd0:
    lwz     r3, 0x38(r29)
    addis   r0, r3, 1
    cmplwi  r0, 0xffff
    beq     _L_8002fff4
    clrlwi  r0, r3, 0x13
    cmplwi  r0, 0x1fc0
    ble     _L_8002fff4
_L_8002ffec:
    li      r3, -0x80
    b       _L_800300d4
_L_8002fff4:
    addi    r3, r28, 0
    addi    r4, r1, 0x18
    bl      __CARDGetControlBlock
    cmpwi   r3, 0
    bge     _L_8003000c
    b       _L_800300d4
_L_8003000c:
    lwz     r3, 0x18(r1)
    bl      __CARDGetDirBlock
    slwi    r0, r31, 6
    add     r31, r3, r0
    lwz     r3, 0x18(r1)
    mr      r4, r31
    bl      fn_8002E9BC
    or.     r4, r3, r3
    bge     _L_8003003c
    lwz     r3, 0x18(r1)
    bl      __CARDPutControlBlock
    b       _L_800300d4
_L_8003003c:
    lbz     r0, 0x2e(r29)
    addi    r3, r31, 0
    addi    r4, r29, 0
    stb     r0, 7(r31)
    lwz     r0, 0x30(r29)
    stw     r0, 0x2c(r31)
    lhz     r0, 0x34(r29)
    sth     r0, 0x30(r31)
    lhz     r0, 0x36(r29)
    sth     r0, 0x32(r31)
    lwz     r0, 0x38(r29)
    stw     r0, 0x3c(r31)
    bl      UpdateIconOffsets
    lwz     r3, 0x2c(r31)
    addis   r0, r3, 1
    cmplwi  r0, 0xffff
    bne     _L_80030090
    lhz     r0, 0x32(r31)
    rlwinm  r0, r0, 0, 0, 0x1d
    ori     r0, r0, 1
    sth     r0, 0x32(r31)
_L_80030090:
    lis     r3, 0x8000              /* __OSBusClock */
    lwz     r0, 0xf8(r3)
    srwi    r29, r0, 2
    bl      OSGetTime
    addi    r6, r29, 0
    li      r5, 0
    bl      __div2i
    stw     r4, 0x28(r31)
    addi    r3, r28, 0
    addi    r4, r30, 0
    bl      __CARDUpdateDir
    or.     r28, r3, r3
    bge     _L_800300d0
    lwz     r3, 0x18(r1)
    mr      r4, r28
    bl      __CARDPutControlBlock
_L_800300d0:
    mr      r3, r28
_L_800300d4:
    lwz     r0, 0x34(r1)
    lwz     r31, 0x2c(r1)
    lwz     r30, 0x28(r1)
    lwz     r29, 0x24(r1)
    lwz     r28, 0x20(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr
}

asm s32 CARDSetStatus(register s32 chan, register s32 fileNo, register void* stat)
{
    nofralloc
    mflr    r0
    lis     r6, __CARDSyncCallback@ha
    stw     r0, 4(r1)
    addi    r6, r6, __CARDSyncCallback@l /* __CARDSyncCallback */
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r3, 0
    bl      CARDSetStatusAsync
    cmpwi   r3, 0
    bge     _L_80030120
    b       _L_80030128
_L_80030120:
    mr      r3, r31
    bl      __CARDSync
_L_80030128:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}
#pragma pop
