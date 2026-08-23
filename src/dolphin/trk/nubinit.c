// MetroTRK nub init functions (0x80088910-0x80088B00).

#pragma push
#pragma force_active on

extern void fn_8008AF50(unsigned long);
extern void fn_8008AF48(unsigned long);
extern void fn_8008AF40(unsigned long);
extern void TRK_board_display(char*);
extern void TRKAcquireMutex(void);
extern int usr_put_initialize(void);
extern int TRKInitializeEventQueue(void);
extern int TRKInitializeMessageBuffers(void);
extern int TRKInitializeDispatcher(void);
extern void InitializeProgramEndTrap(void);
extern int TRKInitializeSerialHandler(void);
extern int TRKInitializeTarget(void);
extern unsigned long TRKInitializeIntDrivenUART(unsigned long, unsigned long,
                                               unsigned long, void**);
extern void TRKTargetSetInputPendingPtr(void*, void*);
extern void MWTRACE(unsigned long, char*);
extern unsigned char gTRKInputPendingPtr[4];
extern unsigned char lbl_801A36B8[40];

asm int TRKInitializeEventQueue(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lis     r3, lbl_801A36B8@ha
    stw     r0, 0x14(r1)
    addi    r3, r3, lbl_801A36B8@l
    bl      fn_8008AF50
    lis     r3, lbl_801A36B8@ha
    addi    r3, r3, lbl_801A36B8@l
    bl      fn_8008AF48
    lis     r3, lbl_801A36B8@ha
    li      r4, 0
    addi    r3, r3, lbl_801A36B8@l
    li      r0, 0x100
    stw     r4, 4(r3)
    stw     r4, 8(r3)
    stw     r0, 0x24(r3)
    bl      fn_8008AF40
    lwz     r0, 0x14(r1)
    li      r3, 0
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int TRKNubWelcome(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lis     r3, 0x8009
    stw     r0, 0x14(r1)
    addi    r3, r3, 0x5648
    bl      TRK_board_display
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int TRKTerminateNub(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      TRKAcquireMutex
    lwz     r0, 0x14(r1)
    li      r3, 0
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int TRKInitializeNub(void)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    li      r5, 0x12
    li      r4, 0x34
    stw     r0, 0x24(r1)
    li      r3, 0x56
    li      r0, 0x78
    li      r6, 1
    stb     r5, 8(r1)
    lis     r5, 0x801A
    stw     r31, 0x1c(r1)
    li      r31, 0
    stw     r30, 0x18(r1)
    stb     r4, 9(r1)
    stb     r3, 0xa(r1)
    stb     r0, 0xb(r1)
    lwz     r3, 8(r1)
    stwu    r6, 0x36E0(r5)
    addis   r0, r3, -0x1234
    cmplwi  r0, 0x5678
    bne     lbl_80088A10
    stw     r6, 0(r5)
    b       lbl_80088A28
lbl_80088A10:
    addis   r0, r3, -0x7856
    cmplwi  r0, 0x3412
    bne     lbl_80088A24
    stw     r31, 0(r5)
    b       lbl_80088A28
lbl_80088A24:
    mr      r31, r6
lbl_80088A28:
    lis     r3, 0x8009
    addi    r4, r3, 0x5664
    li      r3, 1
    crxor   6, 6, 6
    bl      MWTRACE
    cmpwi   r31, 0
    bne     lbl_80088A48
    bl      usr_put_initialize
lbl_80088A48:
    cmpwi   r31, 0
    bne     lbl_80088A58
    bl      TRKInitializeEventQueue
    mr      r31, r3
lbl_80088A58:
    cmpwi   r31, 0
    bne     lbl_80088A68
    bl      TRKInitializeMessageBuffers
    mr      r31, r3
lbl_80088A68:
    cmpwi   r31, 0
    bne     lbl_80088A78
    bl      TRKInitializeDispatcher
    mr      r31, r3
lbl_80088A78:
    bl      InitializeProgramEndTrap
    cmpwi   r31, 0
    bne     lbl_80088A8C
    bl      TRKInitializeSerialHandler
    mr      r31, r3
lbl_80088A8C:
    cmpwi   r31, 0
    bne     lbl_80088A9C
    bl      TRKInitializeTarget
    mr      r31, r3
lbl_80088A9C:
    cmpwi   r31, 0
    bne     lbl_80088AE4
    lis     r3, gTRKInputPendingPtr@ha
    lis     r5, 1
    addi    r6, r3, gTRKInputPendingPtr@l
    li      r4, 1
    addi    r3, r5, -0x1F00
    li      r5, 0
    bl      TRKInitializeIntDrivenUART
    lis     r4, gTRKInputPendingPtr@ha
    mr      r0, r3
    addi    r3, r4, gTRKInputPendingPtr@l
    lwz     r3, 0(r3)
    mr      r30, r0
    bl      TRKTargetSetInputPendingPtr
    cmpwi   r30, 0
    beq     lbl_80088AE4
    mr      r31, r30
lbl_80088AE4:
    lwz     r0, 0x24(r1)
    mr      r3, r31
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

#pragma pop
