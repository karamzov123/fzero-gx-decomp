// MetroTRK nub event-queue functions (0x80088648-0x80088910).
// Semantic reference: melee src/MetroTRK (bytes differ).

#pragma push
#pragma force_active on

extern int TRKGetNextEvent(void*);
extern void fn_800035C0(void*, const void*, unsigned long);
extern void TRKDestructEvent(void*);
extern void TRKGetBuffer(void);
extern void TRKDispatchMessage(void);
extern void TRKTargetInterrupt(void);
extern void TRKTargetSupportRequest(void);
extern void TRKGetInput(void);
extern void TRKTargetStopped(void);
extern void TRKTargetContinue(void);
extern void TRKReleaseBuffer(void*, void*);
extern void fn_8008AF48(unsigned long);
extern void fn_8008AF40(unsigned long);
extern unsigned char gTRKInputPendingPtr[];
extern unsigned char lbl_801A36B8[];

asm void TRKNubMainLoop(void)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    stw     r0, 0x24(r1)
    stw     r31, 0x1c(r1)
    li      r31, 0
    stw     r30, 0x18(r1)
    li      r30, 0
    b       lbl_80088720
lbl_80088668:
    addi    r3, r1, 8
    bl      TRKGetNextEvent
    cmpwi   r3, 0
    beq     lbl_800886E0
    lwz     r0, 8(r1)
    li      r30, 0
    cmpwi   r0, 2
    beq     lbl_800886AC
    bge     lbl_8008869C
    cmpwi   r0, 0
    beq     lbl_800886D4
    bge     lbl_800886BC
    b       lbl_800886D4
lbl_8008869C:
    cmpwi   r0, 5
    beq     lbl_800886D0
    bge     lbl_800886D4
    b       lbl_800886C4
lbl_800886AC:
    lwz     r3, 0x10(r1)
    bl      TRKGetBuffer
    bl      TRKDispatchMessage
    b       lbl_800886D4
lbl_800886BC:
    li      r31, 1
    b       lbl_800886D4
lbl_800886C4:
    addi    r3, r1, 8
    bl      TRKTargetInterrupt
    b       lbl_800886D4
lbl_800886D0:
    bl      TRKTargetSupportRequest
lbl_800886D4:
    addi    r3, r1, 8
    bl      TRKDestructEvent
    b       lbl_80088720
lbl_800886E0:
    cmpwi   r30, 0
    beq     lbl_80088700
    lis     r3, gTRKInputPendingPtr@ha
    addi    r3, r3, gTRKInputPendingPtr@l
    lwz     r3, 0(r3)
    lbz     r0, 0(r3)
    cmplwi  r0, 0
    beq     lbl_8008870C
lbl_80088700:
    li      r30, 1
    bl      TRKGetInput
    b       lbl_80088720
lbl_8008870C:
    bl      TRKTargetStopped
    cmpwi   r3, 0
    bne     lbl_8008871C
    bl      TRKTargetContinue
lbl_8008871C:
    li      r30, 0
lbl_80088720:
    cmpwi   r31, 0
    beq     lbl_80088668
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

asm void TRKDestructEvent(void* msg)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    lwz     r3, 8(r3)
    bl      TRKReleaseBuffer
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_80088764(void* ev)
{
    nofralloc
    stw     r4, 0(r3)
    li      r4, 0
    li      r0, -1
    stw     r4, 4(r3)
    stw     r0, 8(r3)
    blr
}

asm int fn_8008877C(void* msg)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    lis     r4, 0x801A
    stw     r0, 0x24(r1)
    stw     r31, 0x1c(r1)
    li      r31, 0
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    mr      r29, r3
    addi    r3, r4, 0x36B8
    bl      fn_8008AF48
    lis     r3, 0x801A
    addi    r30, r3, 0x36B8
    lwz     r3, 4(r30)
    cmpwi   r3, 2
    bne     lbl_800887C4
    li      r31, 0x100
    b       lbl_80088830
lbl_800887C4:
    lwz     r0, 8(r30)
    mr      r4, r29
    li      r5, 0xC
    add     r0, r0, r3
    srwi    r3, r0, 0x1F
    clrlwi  r0, r0, 0x1F
    xor     r0, r0, r3
    subf    r0, r3, r0
    mulli   r29, r0, 0xC
    add     r3, r30, r29
    addi    r3, r3, 0xC
    bl      fn_800035C0
    lis     r3, 0x801A
    addi    r4, r3, 0x36B8
    lwz     r0, 0x24(r4)
    add     r3, r4, r29
    stw     r0, 0x10(r3)
    lwz     r3, 0x24(r4)
    addi    r0, r3, 1
    cmplwi  r0, 0x100
    stw     r0, 0x24(r4)
    bge     lbl_80088824
    li      r0, 0x100
    stw     r0, 0x24(r4)
lbl_80088824:
    lwz     r3, 4(r30)
    addi    r0, r3, 1
    stw     r0, 4(r30)
lbl_80088830:
    lis     r3, lbl_801A36B8@ha
    addi    r3, r3, lbl_801A36B8@l
    bl      fn_8008AF40
    lwz     r0, 0x24(r1)
    mr      r3, r31
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

asm int TRKGetNextEvent(void* msg)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    lis     r4, 0x801A
    stw     r0, 0x24(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    li      r30, 0
    stw     r29, 0x14(r1)
    mr      r29, r3
    addi    r3, r4, 0x36B8
    bl      fn_8008AF48
    lis     r3, 0x801A
    addi    r31, r3, 0x36B8
    lwz     r0, 4(r31)
    cmpwi   r0, 0
    ble     lbl_800888E4
    lwz     r0, 8(r31)
    mr      r3, r29
    li      r5, 0xC
    mulli   r0, r0, 0xC
    add     r4, r31, r0
    addi    r4, r4, 0xC
    bl      fn_800035C0
    lwz     r3, 8(r31)
    lwz     r4, 4(r31)
    addi    r0, r3, 1
    addi    r3, r4, -1
    stw     r0, 8(r31)
    cmpwi   r0, 2
    stw     r3, 4(r31)
    bne     lbl_800888E0
    li      r0, 0
    stw     r0, 8(r31)
lbl_800888E0:
    li      r30, 1
lbl_800888E4:
    lis     r3, lbl_801A36B8@ha
    addi    r3, r3, lbl_801A36B8@l
    bl      fn_8008AF40
    lwz     r0, 0x24(r1)
    mr      r3, r30
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

// fn_80088764: event init/clear
#pragma pop
