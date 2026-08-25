typedef signed int s32;
typedef unsigned int u32;

/* Orphan unit auto_01_8001DFFC_text (0x8001DFFC-0x8001E2AC):
   AI stream/DSP sample-rate API. Adapted from Dolphin SDK ai.c lineage
   (Melee reference), register form: __AIRegs accessed as 0xCC006C00 directly. */

#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0

typedef int BOOL;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void __AI_SRC_INIT(void);
extern s32 AIGetStreamPlayState_Leaf(void);
asm u32 AIGetStreamPlayState(void);
asm u32 AIGetDSPSampleRate(void);
extern void DSPReadMailHi(void);
extern void DSPReadMailLo(void);
extern void DSPWriteMailHi(register s32 val);
extern void DSPWriteMailMid(register s32 val);

#pragma push
#pragma force_active on

// 0x8001DFFC | size: 0xD8
asm void AISetStreamPlayState(register u32 state)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    mr      r29, r3
    bl      AIGetStreamPlayState
    cmplw   r29, r3
    beq     Lexit
    bl      AIGetStreamPlayState_Leaf
    cmplwi  r3, 0x0
    bne     Lskip_init
    cmplwi  r29, 0x1
    bne     Lskip_init
    bl      DSPReadMailHi
    mr      r30, r3
    bl      DSPReadMailLo
    addi    r29, r3, 0x0
    li      r3, 0x0
    bl      DSPWriteMailMid
    li      r3, 0x0
    bl      DSPWriteMailHi
    bl      OSDisableInterrupts
    mr      r31, r3
    bl      __AI_SRC_INIT
    lis     r4, 0xcc00
    lwz     r0, 0x6c00(r4)
    addi    r3, r31, 0x0
    rlwinm  r0, r0, 0, 27, 25
    ori     r0, r0, 0x20
    stw     r0, 0x6c00(r4)
    lwz     r0, 0x6c00(r4)
    clrrwi  r0, r0, 1
    ori     r0, r0, 0x1
    stw     r0, 0x6c00(r4)
    bl      OSRestoreInterrupts
    mr      r3, r30
    bl      DSPWriteMailHi
    mr      r3, r29
    bl      DSPWriteMailMid
    b       Lexit
Lskip_init:
    lis     r3, 0xcc00
    lwz     r0, 0x6c00(r3)
    clrrwi  r0, r0, 1
    or      r0, r0, r29
    stw     r0, 0x6c00(r3)
Lexit:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

// 0x8001E0D4 | size: 0x10
asm u32 AIGetStreamPlayState(void)
{
    nofralloc
    lis     r3, 0xcc00
    lwz     r0, 0x6c00(r3)
    clrlwi  r3, r0, 31
    blr
}

// 0x8001E0E4 | size: 0xE0
asm void AISetDSPSampleRate(register u32 rate)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x28(r1)
    stmw    r26, 0x10(r1)
    mr      r26, r3
    bl      AIGetDSPSampleRate
    cmplw   r26, r3
    beq     Lexit
    lis     r31, 0xcc00
    lwz     r0, 0x6c00(r31)
    cmplwi  r26, 0x0
    rlwinm  r0, r0, 0, 26, 24
    stw     r0, 0x6c00(r31)
    bne     Lexit
    bl      DSPReadMailLo
    mr      r30, r3
    bl      DSPReadMailHi
    lwz     r0, 0x6c00(r31)
    addi    r29, r3, 0x0
    clrlwi  r27, r0, 31
    bl      AIGetStreamPlayState_Leaf
    addi    r28, r3, 0x0
    li      r3, 0x0
    bl      DSPWriteMailHi
    li      r3, 0x0
    bl      DSPWriteMailMid
    bl      OSDisableInterrupts
    mr      r26, r3
    bl      __AI_SRC_INIT
    lwz     r4, 0x6c00(r31)
    slwi    r0, r28, 1
    addi    r3, r26, 0x0
    rlwinm  r4, r4, 0, 27, 25
    ori     r4, r4, 0x20
    stw     r4, 0x6c00(r31)
    lwz     r4, 0x6c00(r31)
    rlwinm  r4, r4, 0, 31, 29
    or      r0, r4, r0
    stw     r0, 0x6c00(r31)
    lwz     r0, 0x6c00(r31)
    clrrwi  r0, r0, 1
    or      r0, r0, r27
    stw     r0, 0x6c00(r31)
    lwz     r0, 0x6c00(r31)
    ori     r0, r0, 0x40
    stw     r0, 0x6c00(r31)
    bl      OSRestoreInterrupts
    mr      r3, r30
    bl      DSPWriteMailHi
    mr      r3, r29
    bl      DSPWriteMailMid
Lexit:
    lmw     r26, 0x10(r1)
    lwz     r0, 0x2c(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr
}

// 0x8001E1C4 | size: 0x14
asm u32 AIGetDSPSampleRate(void)
{
    nofralloc
    lis     r3, 0xcc00
    lwz     r0, 0x6c00(r3)
    extrwi  r0, r0, 1, 25
    xori    r3, r0, 0x1
    blr
}

// 0x8001E1D8 | size: 0xD4
asm void AISetStreamSampleRate(register u32 rate)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x30(r1)
    stmw    r25, 0x14(r1)
    mr      r25, r3
    bl      AIGetStreamPlayState_Leaf
    cmplw   r25, r3
    beq     Ltail
    lis     r31, 0xcc00
    lwz     r0, 0x6c00(r31)
    clrlwi  r0, r0, 31
    mr      r29, r0
    bl      DSPReadMailLo
    mr      r28, r3
    bl      DSPReadMailHi
    addi    r27, r3, 0x0
    li      r3, 0x0
    bl      DSPWriteMailMid
    li      r3, 0x0
    bl      DSPWriteMailHi
    lwz     r3, 0x6c00(r31)
    lwz     r0, 0x6c00(r31)
    rlwinm  r26, r3, 0, 25, 25
    rlwinm  r0, r0, 0, 26, 24
    stw     r0, 0x6c00(r31)
    bl      OSDisableInterrupts
    mr      r30, r3
    bl      __AI_SRC_INIT
    lwz     r4, 0x6c00(r31)
    slwi    r0, r25, 1
    addi    r3, r30, 0x0
    or      r4, r4, r26
    stw     r4, 0x6c00(r31)
    lwz     r4, 0x6c00(r31)
    rlwinm  r4, r4, 0, 27, 25
    ori     r4, r4, 0x20
    stw     r4, 0x6c00(r31)
    lwz     r4, 0x6c00(r31)
    rlwinm  r4, r4, 0, 31, 29
    or      r0, r4, r0
    stw     r0, 0x6c00(r31)
    bl      OSRestoreInterrupts
    mr      r3, r29
    bl      AISetStreamPlayState
    mr      r3, r28
    bl      DSPWriteMailHi
    mr      r3, r27
    bl      DSPWriteMailMid
Ltail:
    lmw     r25, 0x14(r1)
    lwz     r0, 0x34(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr
}

#pragma pop
