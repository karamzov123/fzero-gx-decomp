// dolphin/card/CARDCreate.c -- tail of coarse/text_80029828 (0x8002EED8-0x8002F140).
// Melee identity: extern/dolphin/src/dolphin/card/CARDCreate.c
//   CARDCreateAsync (0x8002EED8), CARDCreate (0x8002F0F8 sync wrapper via
//   __CARDSyncCallback @0x80029828).
// Retail quirks: sector-size guard returns -0xC before control-block acquire;
// free-entry scan over CARD_MAX_FILE==127 entries with stride 0x40;
// iconSpeed fast-set via sth into dir entry (inlined CARDSetIconSpeed).

typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;

extern u32 strlen(register char* s);
extern s32 __CARDGetControlBlock(register void* card, register void** pctrl);      // __CARDGetControlBlock
extern void __CARDPutControlBlock(register void* ctrl, register s32 err);          // __CARDPutControlBlock
extern void* __CARDGetDirBlock(void);                                          // __CARDGetFatBlock
extern void fn_8002C0B8(register void* card);                            // __CARDGetDirBlock
extern s32 __CARDAllocBlock(register s32 chn, register u16 nBlock, register void* callback); // __CARDAllocBlock
extern s32 __CARDCompareFileName(register void* ent, register char* fileName);     // __CARDCompareFileName
extern s32 __CARDSync(register s32 chn);                                // __CARDSync
extern s32 fn_8008023C(register void* a, register void* b, register u32 n); // memcmp
extern void fn_80083D6C(register void* dst, register char* src, register u32 n); // strncpy

#pragma push
#pragma force_active on

asm s32 CARDCreateAsync(register s32 chan, register char* fileName, register u32 size,
                        register void* fileInfo, register void* callback)
{
    nofralloc
_L_8002eed8:
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x48(r1)
    stmw    r23, 0x24(r1)
    addi    r26, r4, 0
    addi    r25, r3, 0
    addi    r27, r5, 0
    addi    r28, r6, 0
    addi    r29, r7, 0
    addi    r3, r26, 0
    bl      strlen
    cmplwi  r3, 0x20
    ble     _L_8002ef14
    li      r3, -0xc
    b       _L_8002f0e4
_L_8002ef14:
    addi    r3, r25, 0
    addi    r4, r1, 0x1c
    bl      __CARDGetControlBlock
    cmpwi   r3, 0
    bge     _L_8002ef2c
    b       _L_8002f0e4
_L_8002ef2c:
    cmplwi  r27, 0
    beq     _L_8002ef4c
    lwz     r3, 0x1c(r1)
    lwz     r4, 0xc(r3)
    divwu   r0, r27, r4
    mullw   r0, r0, r4
    subf.   r0, r0, r27
    beq     _L_8002ef54
_L_8002ef4c:
    li      r3, -0x80
    b       _L_8002f0e4
_L_8002ef54:
    lis     r4, 1
    addi    r30, r4, -1
    bl      __CARDGetDirBlock
    addi    r31, r3, 0
    addi    r24, r31, 0
    li      r23, 0
    b       _L_8002eff8
_L_8002ef70:
    lbz     r0, 0(r24)
    cmplwi  r0, 0xff
    bne     _L_8002ef90
    clrlwi  r0, r30, 0x10
    cmplwi  r0, 0xffff
    bne     _L_8002eff0
    mr      r30, r23
    b       _L_8002eff0
_L_8002ef90:
    lwz     r4, 0x1c(r1)
    addi    r3, r24, 0
    li      r5, 4
    lwz     r4, 0x10c(r4)
    bl      fn_8008023C
    cmpwi   r3, 0
    bne     _L_8002eff0
    lwz     r4, 0x1c(r1)
    addi    r3, r24, 4
    li      r5, 2
    lwz     r4, 0x10c(r4)
    addi    r4, r4, 4
    bl      fn_8008023C
    cmpwi   r3, 0
    bne     _L_8002eff0
    addi    r3, r24, 0
    addi    r4, r26, 0
    bl      __CARDCompareFileName
    cmpwi   r3, 0
    beq     _L_8002eff0
    lwz     r3, 0x1c(r1)
    li      r4, -7
    bl      __CARDPutControlBlock
    b       _L_8002f0e4
_L_8002eff0:
    addi    r24, r24, 0x40
    addi    r23, r23, 1
_L_8002eff8:
    clrlwi  r0, r23, 0x10
    cmplwi  r0, 0x7f
    blt     _L_8002ef70
    clrlwi  r0, r30, 0x10
    cmplwi  r0, 0xffff
    bne     _L_8002f020
    lwz     r3, 0x1c(r1)
    li      r4, -8
    bl      __CARDPutControlBlock
    b       _L_8002f0e4
_L_8002f020:
    lwz     r3, 0x1c(r1)
    bl      fn_8002C0B8
    lwz     r4, 0x1c(r1)
    lhz     r0, 6(r3)
    lwz     r3, 0xc(r4)
    mullw   r0, r3, r0
    cmplw   r0, r27
    bge     _L_8002f050
    addi    r3, r4, 0
    li      r4, -9
    bl      __CARDPutControlBlock
    b       _L_8002f0e4
_L_8002f050:
    cmplwi  r29, 0
    beq     _L_8002f060
    mr      r0, r29
    b       _L_8002f068
_L_8002f060:
    lis     r3, 0x8003
    addi    r0, r3, -0x67dc         /* __CARDDefaultApiCallback */
_L_8002f068:
    stw     r0, 0xd0(r4)
    rlwinm  r0, r30, 6, 0xa, 0x19
    add     r7, r31, r0
    lwz     r3, 0x1c(r1)
    clrlwi  r29, r30, 0x10
    addi    r4, r26, 0
    sth     r30, 0xbc(r3)
    addi    r3, r7, 8
    li      r5, 0x20
    lwz     r6, 0x1c(r1)
    lwz     r0, 0xc(r6)
    divwu   r0, r27, r0
    sth     r0, 0x38(r7)
    bl      fn_80083D6C
    lwz     r4, 0x1c(r1)
    lis     r3, 0x8003
    addi    r5, r3, -0x1258         /* CreateCallbackFat */
    stw     r28, 0xc0(r4)
    mr      r3, r25
    stw     r25, 0(r28)
    stw     r29, 4(r28)
    lwz     r4, 0x1c(r1)
    lwz     r0, 0xc(r4)
    divwu   r4, r27, r0
    bl      __CARDAllocBlock
    or.     r4, r3, r3
    bge     _L_8002f0e0
    lwz     r3, 0x1c(r1)
    bl      __CARDPutControlBlock
    b       _L_8002f0e4
_L_8002f0e0:
    mr      r3, r4
_L_8002f0e4:
    lmw     r23, 0x24(r1)
    lwz     r0, 0x4c(r1)
    addi    r1, r1, 0x48
    mtlr    r0
    blr
}

asm s32 CARDCreate(register s32 chan, register char* fileName, register u32 size,
                   register void* fileInfo)
{
    nofralloc
    mflr    r0
    lis     r7, 0x8003
    stw     r0, 4(r1)
    addi    r7, r7, -0x67d8         /* __CARDSyncCallback */
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r3, 0
    bl      CARDCreateAsync
    cmpwi   r3, 0
    bge     _L_8002f124
    b       _L_8002f12c
_L_8002f124:
    mr      r3, r31
    bl      __CARDSync
_L_8002f12c:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

#pragma pop
