// dolphin/card/CARDWrite.c -- carved from coarse/text_8002F5B8 (0x8002F5B8-0x8002F8EC).
// Melee identity: extern/dolphin/src/dolphin/card/CARDWrite.c
//   WriteCallback / EraseCallback (static callbacks), CARDWriteAsync, CARDWrite.
// __CARDBlock[2] x 0x110 at .bss:0x80177960; apiCallback@0xd0, buffer@0xb4,
// fileInfo@0xc0, ent->time@0x28, card->startBlock@0xbe.
// Timestamps: OSGetTime()/(__OSBusClock/4) -> bl OSGetTime + bl __div2i.

typedef int BOOL;
typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;

extern s32 __CARDGetControlBlock(register void* card, register void** pctrl);
extern void __CARDPutControlBlock(register void* ctrl, register s32 err);
extern s32 fn_8002C0B8(register void* ctrl);
extern s32 __CARDGetDirBlock(void);
extern s32 __CARDEraseSector(register s32 chn, register s32 addr, register void* callback);
extern s32 __CARDWrite(register s32 chn, register s32 addr, register s32 len,
                       register void* buf, register void* callback);
extern s32 __CARDAccess(register void* ctrl, register void* ent);
extern s32 __CARDSeek(register void* fileInfo, register s32 length, register s32 offset,
                       register void** pcard);
extern s32 __CARDUpdateDir(register s32 chn, register void* callback);
extern s32 __CARDSync(register s32 chn);
extern void DCStoreRange(register void* addr, register u32 n);
extern unsigned long long OSGetTime(void);
extern long long __div2i(long long a, long long b);
extern void __CARDSyncCallback(void);
extern void fn_80029824(void);
extern void fn_8002F5B8(register s32 chan, register s32 result);
extern void fn_8002F728(register s32 chan, register s32 result);
extern unsigned char __CARDBlock[544];

#pragma push
#pragma force_active on

asm void fn_8002F5B8(register s32 chan, register s32 result)
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
    bl      fn_8002C0B8
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
    lis     r3, fn_8002F728@ha
    addi    r5, r3, fn_8002F728@l          /* EraseCallback */
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

asm void fn_8002F728(register s32 chan, register s32 result)
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
    lis     r3, fn_8002F5B8@ha
    addi    r7, r3, fn_8002F5B8@l          /* WriteCallback */
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

asm s32 fn_8002F7D8(register void* fileInfo, register void* buf, register s32 length,
                       register s32 offset, register void* callback)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x38(r1)
    stmw    r27, 0x24(r1)
    addi    r28, r6, 0
    addi    r27, r5, 0
    addi    r31, r4, 0
    addi    r30, r3, 0
    addi    r29, r7, 0
    addi    r4, r27, 0
    addi    r5, r28, 0
    addi    r6, r1, 0x1c
    bl      __CARDSeek
    cmpwi   r3, 0
    bge     _L_8002f818
    b       _L_8002f8d8
_L_8002f818:
    lwz     r3, 0x1c(r1)
    lwz     r4, 0xc(r3)
    addi    r4, r4, -1
    and.    r0, r28, r4
    bne     _L_8002f834
    and.    r0, r27, r4
    beq     _L_8002f840
_L_8002f834:
    li      r4, -0x80
    bl      __CARDPutControlBlock
    b       _L_8002f8d8
_L_8002f840:
    bl      __CARDGetDirBlock
    lwz     r0, 4(r30)
    slwi    r0, r0, 6
    add     r4, r3, r0
    lwz     r3, 0x1c(r1)
    bl      __CARDAccess
    or.     r4, r3, r3
    bge     _L_8002f86c
    lwz     r3, 0x1c(r1)
    bl      __CARDPutControlBlock
    b       _L_8002f8d8
_L_8002f86c:
    addi    r3, r31, 0
    addi    r4, r27, 0
    bl      DCStoreRange
    cmplwi  r29, 0
    beq     _L_8002f888
    mr      r0, r29
    b       _L_8002f890
_L_8002f888:
    lis     r3, fn_80029824@ha
    addi    r0, r3, fn_80029824@l         /* __CARDDefaultApiCallback */
_L_8002f890:
    lwz     r4, 0x1c(r1)
    lis     r3, fn_8002F728@ha
    addi    r5, r3, fn_8002F728@l          /* EraseCallback */
    stw     r0, 0xd0(r4)
    lwz     r3, 0x1c(r1)
    stw     r31, 0xb4(r3)
    lwz     r3, 0x1c(r1)
    lhz     r0, 0x10(r30)
    lwz     r4, 0xc(r3)
    lwz     r3, 0(r30)
    mullw   r4, r4, r0
    bl      __CARDEraseSector
    or.     r30, r3, r3
    bge     _L_8002f8d4
    lwz     r3, 0x1c(r1)
    mr      r4, r30
    bl      __CARDPutControlBlock
_L_8002f8d4:
    mr      r3, r30
_L_8002f8d8:
    lmw     r27, 0x24(r1)
    lwz     r0, 0x3c(r1)
    addi    r1, r1, 0x38
    mtlr    r0
    blr
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
        bl      fn_8002F7D8
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
