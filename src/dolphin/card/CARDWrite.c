// dolphin/card/CARDWrite.c -- carved from coarse/text_8002F5B8 (0x8002F5B8-0x8002F8EC).
// Melee identity: extern/dolphin/src/dolphin/card/CARDWrite.c
//   WriteCallback / EraseCallback (static callbacks), CARDWriteAsync, CARDWrite.
// __CARDBlock[2] x 0x110 at .bss:0x80177960; apiCallback@0xd0, buffer@0xb4,
// fileInfo@0xc0, ent->time@0x28, card->startBlock@0xbe.
// Timestamps: OSGetTime()/(__OSBusClock/4) -> bl OSGetTime + bl __div2i.

#include <dolphin/card_private.h>

extern void DCStoreRange(register void* addr, register u32 n);
extern unsigned long long OSGetTime(void);
extern long long __div2i(long long a, long long b);
extern void CARDWrite_WriteCallback(register s32 chan, register s32 result);
extern void CARDWrite_EraseCallback(register s32 chan, register s32 result);

#pragma push
#pragma force_active on

asm void CARDWrite_WriteCallback(register s32 chan, register s32 result)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    addi    r30, r3, 0
    lis     r3, __CARDBlock@ha
    stw     r29, 0x14(r1)
    mulli   r5, r30, 0x110
    stw     r28, 0x10(r1)
    addi    r0, r3, __CARDBlock@l
    or.     r28, r4, r4
    add     r31, r0, r5
    blt     _L_8002f6dc
    lwz     r29, 0xc0(r31)
    lwz     r3, 0xc(r29)
    cmpwi   r3, 0
    bge     _L_8002f608
    li      r28, -0xe
    b       _L_8002f6dc
_L_8002f608:
    lwz     r0, 0xc(r31)
    subf    r0, r0, r3
    stw     r0, 0xc(r29)
    lwz     r0, 0xc(r29)
    cmpwi   r0, 0
    bgt     _L_8002f670
    mr      r3, r31
    bl      __CARDGetDirBlock
    lwz     r5, 4(r29)
    lis     r4, 0x8000              /* __OSBusClock */
    lwz     r0, 0xf8(r4)
    slwi    r4, r5, 6
    add     r28, r3, r4
    srwi    r29, r0, 2
    bl      OSGetTime
    addi    r6, r29, 0
    li      r5, 0
    bl      __div2i
    stw     r4, 0x28(r28)
    li      r0, 0
    addi    r3, r30, 0
    lwz     r4, 0xd0(r31)
    stw     r0, 0xd0(r31)
    bl      __CARDUpdateDir
    mr      r28, r3
    b       _L_8002f6d4
_L_8002f670:
    mr      r3, r31
    bl      __CARDGetFatBlock
    lwz     r4, 8(r29)
    lwz     r0, 0xc(r31)
    add     r0, r4, r0
    stw     r0, 8(r29)
    lhz     r0, 0x10(r29)
    slwi    r0, r0, 1
    lhzx    r0, r3, r0
    sth     r0, 0x10(r29)
    lhz     r4, 0x10(r29)
    cmplwi  r4, 5
    blt     _L_8002f6b0
    lhz     r0, 0x10(r31)
    cmplw   r4, r0
    blt     _L_8002f6b8
_L_8002f6b0:
    li      r28, -6
    b       _L_8002f6dc
_L_8002f6b8:
    lwz     r0, 0xc(r31)
    lis     r3, CARDWrite_EraseCallback@ha
    addi    r5, r3, CARDWrite_EraseCallback@l          /* EraseCallback */
    mullw   r4, r0, r4
    addi    r3, r30, 0
    bl      __CARDEraseSector
    mr      r28, r3
_L_8002f6d4:
    cmpwi   r28, 0
    bge     _L_8002f708
_L_8002f6dc:
    lwz     r29, 0xd0(r31)
    li      r0, 0
    addi    r3, r31, 0
    stw     r0, 0xd0(r31)
    mr      r4, r28
    bl      __CARDPutControlBlock
    addi    r12, r29, 0
    mtlr    r12
    addi    r3, r30, 0
    addi    r4, r28, 0
    blrl
_L_8002f708:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

asm void CARDWrite_EraseCallback(register s32 chan, register s32 result)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    or.     r29, r4, r4
    stw     r28, 0x10(r1)
    addi    r28, r3, 0
    mulli   r5, r28, 0x110
    lis     r3, __CARDBlock@ha
    addi    r0, r3, __CARDBlock@l
    add     r31, r0, r5
    blt     _L_8002f78c
    lwz     r4, 0xc0(r31)
    lis     r3, CARDWrite_WriteCallback@ha
    addi    r7, r3, CARDWrite_WriteCallback@l          /* WriteCallback */
    lwz     r5, 0xc(r31)
    lhz     r0, 0x10(r4)
    lwz     r6, 0xb4(r31)
    addi    r3, r28, 0
    mullw   r4, r5, r0
    bl      __CARDWrite
    or.     r29, r3, r3
    bge     _L_8002f7b8
_L_8002f78c:
    lwz     r30, 0xd0(r31)
    li      r0, 0
    addi    r3, r31, 0
    stw     r0, 0xd0(r31)
    mr      r4, r29
    bl      __CARDPutControlBlock
    addi    r12, r30, 0
    mtlr    r12
    addi    r3, r28, 0
    addi    r4, r29, 0
    blrl
_L_8002f7b8:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

// provenance: dolsdk2001:src/card/CARDWrite.c:82
s32 CARDWriteAsync(CARDFileInfo *fileInfo, void *buf, s32 length,
                   s32 offset, CARDCallback callback)
{
    CARDControl *card;
    s32 result;
    CARDDir *dir;
    CARDDir *ent;

    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0)
        return result;
    if ((offset & (card->sectorSize - 1)) != 0 ||
        (length & (card->sectorSize - 1)) != 0)
        return __CARDPutControlBlock(card, CARD_RESULT_FATAL_ERROR);

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0)
        return __CARDPutControlBlock(card, result);

    DCStoreRange(buf, (u32)length);
    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
    card->buffer = buf;
    result = __CARDEraseSector(fileInfo->chan,
                                card->sectorSize * (u32)fileInfo->iBlock,
                                (void *)CARDWrite_EraseCallback);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

asm s32 CARDWrite(register void* fileInfo, register void* buf, register s32 length,
                  register s32 offset)
{
    nofralloc
    mflr    r0
    lis     r7, __CARDSyncCallback@ha
    stw     r0, 4(r1)
    addi    r7, r7, __CARDSyncCallback@l         /* __CARDSyncCallback */
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r3, 0
        bl      CARDWriteAsync
    cmpwi   r3, 0
    bge     _L_8002f918
    b       _L_8002f920
_L_8002f918:
    lwz     r3, 0(r31)
    bl      __CARDSync
_L_8002f920:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

#pragma pop
