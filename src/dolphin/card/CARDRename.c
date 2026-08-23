// dolphin/card/CARDRename.c -- carved from coarse/text_8002F5B8 (0x8003013C-0x80030380).
// Melee identity: extern/dolphin/src/dolphin/card/CARDRename.c
//   CARDRenameAsync, CARDRename.
// Duplicate scan compares ent->gameName/company against card->diskID (@+0x10c).
// strncpy = fn_80083D6C, memcmp = fn_8008023C, strlen global.

typedef int BOOL;
typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;

extern s32 __CARDGetControlBlock(register void* card, register void** pctrl);
extern void __CARDPutControlBlock(register void* ctrl, register s32 err);
extern s32 __CARDGetDirBlock(void);
extern s32 fn_8002E9BC(register void* ctrl, register void* ent);
extern s32 fn_8002E954(register void* ent, register char* fileName);
extern s32 fn_8008023C(register void* a, register void* b, register u32 n);
extern u32 strlen(register char* s);
extern s32 fn_80083D6C(register char* dst, register char* src, register u32 n);
extern s32 __CARDUpdateDir(register s32 chn, register void* callback);
extern s32 __CARDSync(register s32 chn);
extern unsigned long long OSGetTime(void);
extern long long __div2i(long long a, long long b);

#pragma push
#pragma force_active on

asm s32 CARDRenameAsync(register s32 chan, register char* oldName, register char* newName,
                        register void* callback)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x48(r1)
    stmw    r23, 0x24(r1)
    mr      r29, r4
    addi    r28, r3, 0
    addi    r30, r5, 0
    addi    r31, r6, 0
    lbz     r4, 0(r4)
    extsb   r0, r4
    cmpwi   r0, 0xff
    beq     _L_8003018c
    lbz     r3, 0(r30)
    extsb   r0, r3
    cmpwi   r0, 0xff
    beq     _L_8003018c
    extsb.  r0, r4
    beq     _L_8003018c
    extsb.  r0, r3
    bne     _L_80030194
_L_8003018c:
    li      r3, -0x80
    b       _L_80030324
_L_80030194:
    mr      r3, r29
    bl      strlen
    cmplwi  r3, 0x20
    bgt     _L_800301b4
    mr      r3, r30
    bl      strlen
    cmplwi  r3, 0x20
    ble     _L_800301bc
_L_800301b4:
    li      r3, -0xc
    b       _L_80030324
_L_800301bc:
    addi    r3, r28, 0
    addi    r4, r1, 0x18
    bl      __CARDGetControlBlock
    cmpwi   r3, 0
    bge     _L_800301d4
    b       _L_80030324
_L_800301d4:
    lwz     r3, 0x18(r1)
    li      r23, -1
    li      r24, -1
    bl      __CARDGetDirBlock
    addi    r26, r3, 0
    addi    r27, r26, 0
    li      r25, 0
_L_800301f0:
    lbz     r0, 0(r27)
    cmplwi  r0, 0xff
    beq     _L_80030268
    lwz     r4, 0x18(r1)
    addi    r3, r27, 0
    li      r5, 4
    lwz     r4, 0x10c(r4)
    bl      fn_8008023C
    cmpwi   r3, 0
    bne     _L_80030268
    lwz     r4, 0x18(r1)
    addi    r3, r27, 4
    li      r5, 2
    lwz     r4, 0x10c(r4)
    addi    r4, r4, 4
    bl      fn_8008023C
    cmpwi   r3, 0
    bne     _L_80030268
    addi    r3, r27, 0
    addi    r4, r29, 0
    bl      fn_8002E954
    cmpwi   r3, 0
    beq     _L_80030250
    mr      r23, r25
_L_80030250:
    addi    r3, r27, 0
    addi    r4, r30, 0
    bl      fn_8002E954
    cmpwi   r3, 0
    beq     _L_80030268
    mr      r24, r25
_L_80030268:
    addi    r25, r25, 1
    cmpwi   r25, 0x7f
    addi    r27, r27, 0x40
    blt     _L_800301f0
    cmpwi   r23, -1
    bne     _L_80030290
    lwz     r3, 0x18(r1)
    li      r4, -4
    bl      __CARDPutControlBlock
    b       _L_80030324
_L_80030290:
    cmpwi   r24, -1
    beq     _L_800302a8
    lwz     r3, 0x18(r1)
    li      r4, -7
    bl      __CARDPutControlBlock
    b       _L_80030324
_L_800302a8:
    slwi    r0, r23, 6
    lwz     r3, 0x18(r1)
    add     r27, r26, r0
    addi    r4, r27, 0
    bl      fn_8002E9BC
    or.     r4, r3, r3
    bge     _L_800302d0
    lwz     r3, 0x18(r1)
    bl      __CARDPutControlBlock
    b       _L_80030324
_L_800302d0:
    addi    r4, r30, 0
    addi    r3, r27, 8
    li      r5, 0x20
    bl      fn_80083D6C
    lis     r3, 0x8000              /* __OSBusClock */
    lwz     r0, 0xf8(r3)
    srwi    r29, r0, 2
    bl      OSGetTime
    addi    r6, r29, 0
    li      r5, 0
    bl      __div2i
    stw     r4, 0x28(r27)
    addi    r3, r28, 0
    addi    r4, r31, 0
    bl      __CARDUpdateDir
    or.     r27, r3, r3
    bge     _L_80030320
    lwz     r3, 0x18(r1)
    mr      r4, r27
    bl      __CARDPutControlBlock
_L_80030320:
    mr      r3, r27
_L_80030324:
    lmw     r23, 0x24(r1)
    lwz     r0, 0x4c(r1)
    addi    r1, r1, 0x48
    mtlr    r0
    blr
}

asm s32 CARDRename(register s32 chan, register char* oldName, register char* newName)
{
    nofralloc
    mflr    r0
    lis     r6, 0x8003
    stw     r0, 4(r1)
    addi    r6, r6, -0x67d8         /* __CARDSyncCallback */
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r3, 0
    bl      CARDRenameAsync
    cmpwi   r3, 0
    bge     _L_80030364
    b       _L_8003036c
_L_80030364:
    mr      r3, r31
    bl      __CARDSync
_L_8003036c:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

#pragma pop
