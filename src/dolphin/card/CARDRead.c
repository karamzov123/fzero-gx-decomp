// dolphin/card/CARDRead.c -- carved from coarse/text_8002F140 (0x8002F140-0x8002F5B8).
// Retail layout: CARD control blocks at .bss:0x80177960 (2 x 0x110 bytes).
// All accesses use absolute-addressed asm bodies to match retail addressing.
// Probable melee identities: fn_8002F140 = __CARDReadSegment-ish read core,
// fn_8002F2F8 = __CARDSeek, fn_8002F428 = __CARDRead internal, fn_8002F570 =
// CARDRead wrapper.

typedef int BOOL;
typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;

extern unsigned char __CARDBlock[544];
extern void fn_80029824(void);
extern void __CARDSyncCallback(register s32 chn);
extern s32 __CARDGetControlBlock(register void* card, register void** pctrl);
extern void __CARDPutControlBlock(register void* ctrl, register s32 err);
extern s32 fn_8002C0B8(register void* ctrl);
extern s32 __CARDGetDirBlock(void);
extern s32 fn_8002BEFC(register s32 chn, register void* addr, register s32 len,
                       register void* r6, register void* r7);
extern s32 fn_8002E9BC(register void* ctrl, register void* r4);
extern s32 fn_8002EA54(register void* ctrl);
extern s32 __CARDSync(register void* handle);
extern void DCInvalidateRange(register void* addr, register u32 n);
extern u32 OSGetTime(void);
extern unsigned char __CARDBlock[544];
extern void fn_80029824(void);
extern void __CARDSyncCallback(register s32 chn);

#pragma push
#pragma force_active on

asm s32 fn_8002F140(register void* r3, register void* r4, register void* r5, register void* r6)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x30(r1)
    stw     r31, 0x2c(r1)
    addi    r31, r6, 0
    stw     r30, 0x28(r1)
    addi    r30, r5, 0
    stw     r29, 0x24(r1)
    addi    r29, r4, 0
    addi    r4, r1, 0x18
    stw     r28, 0x20(r1)
    mr      r28, r3
    lwz     r3, 0(r3)
    bl      __CARDGetControlBlock
    cmpwi   r3, 0
    bge     _L_8002f184
    b       _L_8002f2d8
_L_8002f184:
    lhz     r0, 0x10(r28)
    cmplwi  r0, 5
    blt     _L_8002f1b4
    lwz     r3, 0x18(r1)
    lhz     r5, 0x10(r3)
    cmplw   r0, r5
    bge     _L_8002f1b4
    lwz     r4, 0xc(r3)
    lwz     r0, 8(r28)
    mullw   r4, r5, r4
    cmpw    r4, r0
    bgt     _L_8002f1c4
_L_8002f1b4:
    lwz     r3, 0x18(r1)
    li      r4, -0x80
    bl      __CARDPutControlBlock
    b       _L_8002f2d8
_L_8002f1c4:
    bl      __CARDGetDirBlock
    lwz     r0, 4(r28)
    lwz     r5, 0x18(r1)
    slwi    r0, r0, 6
    add     r4, r3, r0
    lwz     r3, 0xc(r5)
    lhz     r0, 0x38(r4)
    mullw   r3, r0, r3
    cmpw    r3, r30
    ble     _L_8002f1f8
    add     r0, r30, r29
    cmpw    r3, r0
    bge     _L_8002f208
_L_8002f1f8:
    addi    r3, r5, 0
    li      r4, -0xb
    bl      __CARDPutControlBlock
    b       _L_8002f2d8
_L_8002f208:
    stw     r28, 0xc0(r5)
    stw     r29, 0xc(r28)
    lwz     r0, 8(r28)
    cmpw    r30, r0
    bge     _L_8002f258
    li      r0, 0
    stw     r0, 8(r28)
    lhz     r0, 0x36(r4)
    sth     r0, 0x10(r28)
    lhz     r4, 0x10(r28)
    cmplwi  r4, 5
    blt     _L_8002f248
    lwz     r3, 0x18(r1)
    lhz     r0, 0x10(r3)
    cmplw   r4, r0
    blt     _L_8002f258
_L_8002f248:
    lwz     r3, 0x18(r1)
    li      r4, -6
    bl      __CARDPutControlBlock
    b       _L_8002f2d8
_L_8002f258:
    lwz     r3, 0x18(r1)
    bl      fn_8002C0B8
    b       _L_8002f2ac
_L_8002f264:
    lwz     r0, 8(r28)
    add     r0, r0, r4
    stw     r0, 8(r28)
    lhz     r0, 0x10(r28)
    slwi    r0, r0, 1
    lhzx    r0, r3, r0
    sth     r0, 0x10(r28)
    lhz     r5, 0x10(r28)
    cmplwi  r5, 5
    blt     _L_8002f29c
    lwz     r4, 0x18(r1)
    lhz     r0, 0x10(r4)
    cmplw   r5, r0
    blt     _L_8002f2ac
_L_8002f29c:
    lwz     r3, 0x18(r1)
    li      r4, -6
    bl      __CARDPutControlBlock
    b       _L_8002f2d8
_L_8002f2ac:
    lwz     r4, 0x18(r1)
    lwz     r5, 8(r28)
    lwz     r4, 0xc(r4)
    addi    r0, r4, -1
    andc    r0, r30, r0
    cmplw   r5, r0
    blt     _L_8002f264
    stw     r30, 8(r28)
    li      r3, 0
    lwz     r0, 0x18(r1)
    stw     r0, 0(r31)
_L_8002f2d8:
    lwz     r0, 0x34(r1)
    lwz     r31, 0x2c(r1)
    lwz     r30, 0x28(r1)
    lwz     r29, 0x24(r1)
    lwz     r28, 0x20(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr
}

asm s32 fn_8002F2F8(register s32 chn, register BOOL sync)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x28(r1)
    stmw    r27, 0x14(r1)
    addi    r29, r3, 0
    lis     r3, __CARDBlock@ha
    mulli   r5, r29, 0x110
    addi    r0, r3, __CARDBlock@l
    or.     r30, r4, r4
    add     r31, r0, r5
    blt     _L_8002f3e8
    lwz     r28, 0xc0(r31)
    lwz     r4, 0xc(r28)
    cmpwi   r4, 0
    bge     _L_8002f33c
    li      r30, -0xe
    b       _L_8002f3e8
_L_8002f33c:
    lwz     r5, 0xc(r31)
    lwz     r6, 8(r28)
    addi    r0, r5, -1
    nor     r3, r0, r0
    add     r0, r6, r5
    and     r0, r3, r0
    subf    r27, r6, r0
    subf    r0, r27, r4
    stw     r0, 0xc(r28)
    lwz     r0, 0xc(r28)
    cmpwi   r0, 0
    ble     _L_8002f3e8
    mr      r3, r31
    bl      fn_8002C0B8
    lwz     r0, 8(r28)
    add     r0, r0, r27
    stw     r0, 8(r28)
    lhz     r0, 0x10(r28)
    slwi    r0, r0, 1
    lhzx    r0, r3, r0
    sth     r0, 0x10(r28)
    lhz     r3, 0x10(r28)
    cmplwi  r3, 5
    blt     _L_8002f3a8
    lhz     r0, 0x10(r31)
    cmplw   r3, r0
    blt     _L_8002f3b0
_L_8002f3a8:
    li      r30, -6
    b       _L_8002f3e8
_L_8002f3b0:
    lwz     r5, 0xc(r28)
    lwz     r0, 0xc(r31)
    cmpw    r5, r0
    bge     _L_8002f3c4
    b       _L_8002f3c8
_L_8002f3c4:
    mr      r5, r0
_L_8002f3c8:
    mullw   r4, r0, r3
    lwz     r6, 0xb4(r31)
    lis     r3, fn_8002F2F8@ha
    addi    r7, r3, fn_8002F2F8@l
    addi    r3, r29, 0
    bl      fn_8002BEFC
    or.     r30, r3, r3
    bge     _L_8002f414
_L_8002f3e8:
    lwz     r27, 0xd0(r31)
    li      r0, 0
    addi    r3, r31, 0
    stw     r0, 0xd0(r31)
    mr      r4, r30
    bl      __CARDPutControlBlock
    addi    r12, r27, 0
    mtlr    r12
    addi    r3, r29, 0
    addi    r4, r30, 0
    blrl
_L_8002f414:
    lmw     r27, 0x14(r1)
    lwz     r0, 0x2c(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr
}

asm s32 fn_8002F428(register s32 chn, register void* addr, register s32 len,
                    register void* callback)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    clrlwi. r0, r6, 0x17
    stwu    r1, -0x38(r1)
    stmw    r27, 0x24(r1)
    addi    r29, r3, 0
    addi    r30, r4, 0
    addi    r31, r5, 0
    addi    r27, r7, 0
    bne     _L_8002f458
    clrlwi. r0, r31, 0x17
    beq     _L_8002f460
_L_8002f458:
    li      r3, -0x80
    b       _L_8002f55c
_L_8002f460:
    addi    r3, r29, 0
    addi    r4, r31, 0
    addi    r5, r6, 0
    addi    r6, r1, 0x1c
    bl      fn_8002F140
    cmpwi   r3, 0
    bge     _L_8002f480
    b       _L_8002f55c
_L_8002f480:
    lwz     r3, 0x1c(r1)
    bl      __CARDGetDirBlock
    lwz     r0, 4(r29)
    slwi    r0, r0, 6
    add     r28, r3, r0
    lwz     r3, 0x1c(r1)
    mr      r4, r28
    bl      fn_8002E9BC
    addi    r4, r3, 0
    cmpwi   r4, -0xa
    bne     _L_8002f4b8
    mr      r3, r28
    bl      fn_8002EA54
    mr      r4, r3
_L_8002f4b8:
    cmpwi   r4, 0
    bge     _L_8002f4cc
    lwz     r3, 0x1c(r1)
    bl      __CARDPutControlBlock
    b       _L_8002f55c
_L_8002f4cc:
    addi    r3, r30, 0
    addi    r4, r31, 0
    bl      DCInvalidateRange
    cmplwi  r27, 0
    beq     _L_8002f4e8
    mr      r0, r27
    b       _L_8002f4f0
_L_8002f4e8:
    lis     r3, fn_80029824@ha
    addi    r0, r3, fn_80029824@l
_L_8002f4f0:
    lwz     r3, 0x1c(r1)
    stw     r0, 0xd0(r3)
    lwz     r3, 0x1c(r1)
    lwz     r4, 8(r29)
    lwz     r5, 0xc(r3)
    addi    r0, r5, -1
    and     r8, r4, r0
    subf    r3, r8, r5
    cmpw    r31, r3
    bge     _L_8002f51c
    mr      r3, r31
_L_8002f51c:
    lhz     r0, 0x10(r29)
    lis     r4, fn_8002F2F8@ha
    addi    r31, r3, 0
    lwz     r3, 0(r29)
    mullw   r0, r5, r0
    addi    r7, r4, fn_8002F2F8@l
    addi    r5, r31, 0
    addi    r6, r30, 0
    add     r4, r8, r0
    bl      fn_8002BEFC
    or.     r29, r3, r3
    bge     _L_8002f558
    lwz     r3, 0x1c(r1)
    mr      r4, r29
    bl      __CARDPutControlBlock
_L_8002f558:
    mr      r3, r29
_L_8002f55c:
    lmw     r27, 0x24(r1)
    lwz     r0, 0x3c(r1)
    addi    r1, r1, 0x38
    mtlr    r0
    blr
}

asm s32 CARDRead(register void** handle, register void* addr, register s32 len)
{
    nofralloc
    mflr    r0
    lis     r7, __CARDSyncCallback@ha
    stw     r0, 4(r1)
    addi    r7, r7, __CARDSyncCallback@l
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r3, 0
    bl      fn_8002F428
    cmpwi   r3, 0
    bge     _L_8002f59c
    b       _L_8002f5a4
_L_8002f59c:
    lwz     r3, 0(r31)
    bl      __CARDSync
_L_8002f5a4:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

#pragma pop
