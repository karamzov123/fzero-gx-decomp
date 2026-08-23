// dolphin/card/CARDDelete.c -- carved from coarse/text_8002F5B8 (0x8002F934-0x8002FC5C).
// Melee identity: extern/dolphin/src/dolphin/card/CARDDelete.c
//   DeleteCallback (static), CARDFastDeleteAsync, CARDDeleteAsync, CARDDelete.
// Retail quirk: __CARDIsOpened is an 8-byte stub (fn_8002EDA0: li r3,0; blr).
// CARD_MAX_FILE == 127 (cmpwi rX, 0x7f range guards).

typedef int BOOL;
typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;

extern s32 fn_8002A83C(register void* card, register void** pctrl);
extern void fn_8002A8F4(register void* ctrl, register s32 err);
extern s32 fn_8002C374(register s32 chn, register u16 nBlock, register void* callback);
extern s32 fn_8002C4BC(void);
extern s32 fn_8002E9BC(register void* ctrl, register void* ent);
extern s32 fn_8002EDA0(register void* ctrl, register s32 fileNo);
extern s32 fn_8002EA84(register void* ctrl, register void* fileName, register void* pfileNo);
extern s32 fn_8002C65C(register s32 chn, register void* callback);
extern s32 fn_8002AAD8(register s32 chn);
extern void* memset(register void* dst, register int val, register u32 n);

#pragma push
#pragma force_active on

asm void DeleteCallback(register s32 chan, register s32 result)
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
    lis     r3, 0x8017              /* __CARDBlock */
    addi    r0, r3, 0x7960
    add     r31, r0, r5
    lwz     r30, 0xd0(r31)
    li      r0, 0
    stw     r0, 0xd0(r31)
    blt     _L_8002f990
    lhz     r4, 0xbe(r31)
    addi    r3, r28, 0
    addi    r5, r30, 0
    bl      fn_8002C374
    or.     r29, r3, r3
    bge     _L_8002f9b8
_L_8002f990:
    addi    r3, r31, 0
    addi    r4, r29, 0
    bl      fn_8002A8F4
    cmplwi  r30, 0
    beq     _L_8002f9b8
    addi    r12, r30, 0
    mtlr    r12
    addi    r3, r28, 0
    addi    r4, r29, 0
    blrl
_L_8002f9b8:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

asm s32 CARDFastDeleteAsync(register s32 chan, register s32 fileNo, register void* callback)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x28(r1)
    stw     r31, 0x24(r1)
    stw     r30, 0x20(r1)
    addi    r30, r5, 0
    stw     r29, 0x1c(r1)
    or.     r29, r4, r4
    stw     r28, 0x18(r1)
    addi    r28, r3, 0
    blt     _L_8002fa0c
    cmpwi   r29, 0x7f
    blt     _L_8002fa14
_L_8002fa0c:
    li      r3, -0x80
    b       _L_8002fae4
_L_8002fa14:
    addi    r3, r28, 0
    addi    r4, r1, 0x14
    bl      fn_8002A83C
    cmpwi   r3, 0
    bge     _L_8002fa2c
    b       _L_8002fae4
_L_8002fa2c:
    lwz     r3, 0x14(r1)
    bl      fn_8002C4BC
    slwi    r0, r29, 6
    add     r31, r3, r0
    lwz     r3, 0x14(r1)
    mr      r4, r31
    bl      fn_8002E9BC
    or.     r4, r3, r3
    bge     _L_8002fa5c
    lwz     r3, 0x14(r1)
    bl      fn_8002A8F4
    b       _L_8002fae4
_L_8002fa5c:
    lwz     r3, 0x14(r1)
    mr      r4, r29
    bl      fn_8002EDA0
    cmpwi   r3, 0
    beq     _L_8002fa80
    lwz     r3, 0x14(r1)
    li      r4, -1
    bl      fn_8002A8F4
    b       _L_8002fae4
_L_8002fa80:
    lhz     r0, 0x36(r31)
    mr      r3, r31
    lwz     r6, 0x14(r1)
    li      r4, 0xff
    li      r5, 0x40
    sth     r0, 0xbe(r6)
    bl      memset
    cmplwi  r30, 0
    beq     _L_8002faac
    mr      r0, r30
    b       _L_8002fab4
_L_8002faac:
    lis     r3, 0x8003
    addi    r0, r3, -0x67dc         /* __CARDDefaultApiCallback */
_L_8002fab4:
    lwz     r5, 0x14(r1)
    lis     r3, 0x8003
    addi    r4, r3, -0x6cc          /* DeleteCallback */
    stw     r0, 0xd0(r5)
    mr      r3, r28
    bl      fn_8002C65C
    or.     r31, r3, r3
    bge     _L_8002fae0
    lwz     r3, 0x14(r1)
    mr      r4, r31
    bl      fn_8002A8F4
_L_8002fae0:
    mr      r3, r31
_L_8002fae4:
    lwz     r0, 0x2c(r1)
    lwz     r31, 0x24(r1)
    lwz     r30, 0x20(r1)
    lwz     r29, 0x1c(r1)
    lwz     r28, 0x18(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr
}

asm s32 CARDDeleteAsync(register s32 chan, register char* fileName, register void* callback)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x30(r1)
    stw     r31, 0x2c(r1)
    addi    r31, r3, 0
    stw     r30, 0x28(r1)
    addi    r30, r5, 0
    stw     r29, 0x24(r1)
    addi    r29, r4, 0
    addi    r4, r1, 0x18
    bl      fn_8002A83C
    cmpwi   r3, 0
    bge     _L_8002fb3c
    b       _L_8002fbf8
_L_8002fb3c:
    lwz     r3, 0x18(r1)
    addi    r4, r29, 0
    addi    r5, r1, 0x14
    bl      fn_8002EA84
    or.     r4, r3, r3
    bge     _L_8002fb60
    lwz     r3, 0x18(r1)
    bl      fn_8002A8F4
    b       _L_8002fbf8
_L_8002fb60:
    lwz     r3, 0x18(r1)
    lwz     r4, 0x14(r1)
    bl      fn_8002EDA0
    cmpwi   r3, 0
    beq     _L_8002fb84
    lwz     r3, 0x18(r1)
    li      r4, -1
    bl      fn_8002A8F4
    b       _L_8002fbf8
_L_8002fb84:
    lwz     r3, 0x18(r1)
    bl      fn_8002C4BC
    lwz     r0, 0x14(r1)
    li      r4, 0xff
    lwz     r6, 0x18(r1)
    li      r5, 0x40
    slwi    r0, r0, 6
    add     r3, r3, r0
    lhz     r0, 0x36(r3)
    sth     r0, 0xbe(r6)
    bl      memset
    cmplwi  r30, 0
    beq     _L_8002fbc0
    mr      r0, r30
    b       _L_8002fbc8
_L_8002fbc0:
    lis     r3, 0x8003
    addi    r0, r3, -0x67dc         /* __CARDDefaultApiCallback */
_L_8002fbc8:
    lwz     r5, 0x18(r1)
    lis     r3, 0x8003
    addi    r4, r3, -0x6cc          /* DeleteCallback */
    stw     r0, 0xd0(r5)
    mr      r3, r31
    bl      fn_8002C65C
    or.     r31, r3, r3
    bge     _L_8002fbf4
    lwz     r3, 0x18(r1)
    mr      r4, r31
    bl      fn_8002A8F4
_L_8002fbf4:
    mr      r3, r31
_L_8002fbf8:
    lwz     r0, 0x34(r1)
    lwz     r31, 0x2c(r1)
    lwz     r30, 0x28(r1)
    lwz     r29, 0x24(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr
}

asm s32 CARDDelete(register s32 chan, register char* fileName)
{
    nofralloc
    mflr    r0
    lis     r5, 0x8003
    stw     r0, 4(r1)
    addi    r5, r5, -0x67d8         /* __CARDSyncCallback */
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    addi    r31, r3, 0
    bl      CARDDeleteAsync
    cmpwi   r3, 0
    bge     _L_8002fc40
    b       _L_8002fc48
_L_8002fc40:
    mr      r3, r31
    bl      fn_8002AAD8
_L_8002fc48:
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

#pragma pop
