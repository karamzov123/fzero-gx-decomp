typedef unsigned char u8;
typedef unsigned int u32;
extern void fn_80032F80(void);
extern void* memset(void*, int, unsigned long);
extern void GXSetCullMode(void);
extern void fn_800370A0(void);
extern void fn_800370E4(void);
extern void fn_80037128(void);
extern void fn_80037190(void);
extern void fn_8003742C(void);
extern void fn_80037480(void);
extern void fn_80037B14(void);
extern void fn_80037B68(void);
extern void fn_80037B94(void);
extern void fn_80037BF4(void);
extern void fn_80072A50(void);
extern void _savegpr_26(void);
extern void _savegpr_27(void);
extern void _restgpr_26(void);
extern void _restgpr_27(void);

asm void fn_8007264C(void);
asm void fn_800726C0(void);
asm void fn_80072778(void);
asm void fn_80072808(void);
asm void fn_80072864(void);
asm void fn_800728A8(void);
asm void fn_800729B0(void);
asm void fn_80072A50(void);
asm void fn_80072AB0(void);
asm void fn_80072B28(void);
asm void fn_80072B7C(void);
asm void fn_80072BD0(void);
asm void fn_80072C24(void);
asm void fn_80072CC4(void);
asm void fn_80072D64(void);
asm void fn_80072E20(void);
#pragma push
#pragma force_active on

asm void fn_8007264C(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    mulli r9, r3, 0x1a0
    lis r8, -0x7fe6
    stw r0, 0x14(r1)
    addi r0, r8, -0x1cf8
    add r9, r0, r9
    lwz r0, 0(r9)
    cmpw r0, r4
    bne _8007269C
    lwz r0, 4(r9)
    cmpw r0, r5
    bne _8007269C
    lwz r0, 8(r9)
    cmpw r0, r6
    bne _8007269C
    lbz r8, 0xc(r9)
    clrlwi r0, r7, 0x18
    cmplw r8, r0
    beq _800726B0
_8007269C:
    stw r4, 0(r9)
    stw r5, 4(r9)
    stw r6, 8(r9)
    stb r7, 0xc(r9)
    bl fn_80032F80
_800726B0:
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_800726C0(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    mr r30, r4
    stw r29, 0x14(r1)
    mr r29, r3
    mulli r5, r29, 0x1a0
    lis r3, -0x7fe6
    addi r0, r3, -0x1cf8
    add r31, r0, r5
    b _80072750
_800726F4:
    lwz r4, 0(r30)
    lwz r0, 0(r31)
    lbz r7, 0xc(r30)
    cmpw r0, r4
    lwz r6, 8(r30)
    lwz r5, 4(r30)
    bne _80072734
    lwz r0, 4(r31)
    cmpw r0, r5
    bne _80072734
    lwz r0, 8(r31)
    cmpw r0, r6
    bne _80072734
    lbz r0, 0xc(r31)
    cmplw r0, r7
    beq _8007274C
_80072734:
    stw r4, 0(r31)
    mr r3, r29
    stw r5, 4(r31)
    stw r6, 8(r31)
    stb r7, 0xc(r31)
    bl fn_80032F80
_8007274C:
    addi r30, r30, 0x10
_80072750:
    lwz r0, 0(r30)
    cmpwi r0, 0x1a
    blt _800726F4
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80072778(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    li r4, 0xff
    li r5, 0xca0
    stw r0, 0x14(r1)
    lwz r3, -0x7688(r13)
    bl memset
    li r3, 0
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 3
    bl fn_80072A50
    li r3, 1
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 0
    bl fn_80072A50
    li r3, 2
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 1
    bl fn_80072A50
    li r3, 3
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 2
    bl fn_80072A50
    lwz r0, 0x14(r1)
    li r3, 1
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80072808(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    li r4, 0xff
    li r5, 0xca0
    stw r0, 0x14(r1)
    lwz r3, -0x7688(r13)
    bl memset
    li r3, 0
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 3
    bl fn_80072A50
    li r3, 1
    li r4, 0
    li r5, 1
    li r6, 2
    li r7, 0
    bl fn_80072A50
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80072864(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, -0x7688(r13)
    lwz r0, 0x18(r4)
    cmpw r31, r0
    beq _80072894
    bl GXSetCullMode
    lwz r3, -0x7688(r13)
    stw r31, 0x18(r3)
_80072894:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_800728A8(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    mr r31, r6
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    stw r28, 0x10(r1)
    mr r28, r3
    cmpwi r28, 2
    bne _80072934
    lwz r3, -0x7688(r13)
    lwz r0, 0x1c(r3)
    cmpwi r0, 2
    bne _800728F8
    lwz r0, 0x28(r3)
    cmpw r0, r31
    beq _80072990
_800728F8:
    mr r4, r29
    mr r5, r30
    mr r6, r31
    li r3, 2
    bl fn_80037B14
    lwz r3, -0x7688(r13)
    li r0, 2
    stw r0, 0x1c(r3)
    lwz r3, -0x7688(r13)
    stw r29, 0x20(r3)
    lwz r3, -0x7688(r13)
    stw r30, 0x24(r3)
    lwz r3, -0x7688(r13)
    stw r31, 0x28(r3)
    b _80072990
_80072934:
    lwz r3, -0x7688(r13)
    lwz r0, 0x1c(r3)
    cmpw r0, r28
    bne _8007295C
    lwz r0, 0x20(r3)
    cmpw r0, r29
    bne _8007295C
    lwz r0, 0x24(r3)
    cmpw r0, r30
    beq _80072990
_8007295C:
    mr r3, r28
    mr r4, r29
    mr r5, r30
    mr r6, r31
    bl fn_80037B14
    lwz r3, -0x7688(r13)
    stw r28, 0x1c(r3)
    lwz r3, -0x7688(r13)
    stw r29, 0x20(r3)
    lwz r3, -0x7688(r13)
    stw r30, 0x24(r3)
    lwz r3, -0x7688(r13)
    stw r31, 0x28(r3)
_80072990:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_800729B0(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    slwi r8, r3, 4
    lwz r0, -0x7688(r13)
    addi r31, r8, 0x2c
    mr r27, r4
    add r31, r0, r31
    mr r28, r5
    lwz r0, 0(r31)
    mr r29, r6
    mr r30, r7
    cmpw r0, r27
    bne _80072A14
    lwz r0, 4(r31)
    cmpw r0, r28
    bne _80072A14
    lwz r0, 8(r31)
    cmpw r0, r29
    bne _80072A14
    lwz r0, 0xc(r31)
    cmpw r0, r30
    beq _80072A38
_80072A14:
    mr r4, r27
    mr r5, r28
    mr r6, r29
    mr r7, r30
    bl fn_80037480
    stw r27, 0(r31)
    stw r28, 4(r31)
    stw r29, 8(r31)
    stw r30, 0xc(r31)
_80072A38:
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80072A50(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    slwi r8, r3, 4
    lwz r0, -0x7688(r13)
    addi r31, r8, 0x2c
    mr r27, r4
    mr r28, r5
    mr r29, r6
    mr r30, r7
    add r31, r0, r31
    bl fn_80037480
    stw r27, 0(r31)
    stw r28, 4(r31)
    stw r29, 8(r31)
    stw r30, 0xc(r31)
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80072AB0(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    slwi r6, r3, 3
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    addi r31, r6, 0x6c
    stw r30, 0x18(r1)
    mr r30, r5
    stw r29, 0x14(r1)
    mr r29, r4
    lwz r0, -0x7688(r13)
    add r31, r0, r31
    lwz r0, 0(r31)
    cmpw r0, r29
    bne _80072AF8
    lwz r0, 4(r31)
    cmpw r0, r30
    beq _80072B0C
_80072AF8:
    mr r4, r29
    mr r5, r30
    bl fn_8003742C
    stw r29, 0(r31)
    stw r30, 4(r31)
_80072B0C:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80072B28(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, -0x7688(r13)
    lbz r3, 0xec(r4)
    cmplwi r3, 0xff
    beq _80072B58
    clrlwi r0, r31, 0x18
    cmplw r3, r0
    beq _80072B68
_80072B58:
    mr r3, r31
    bl fn_80037B68
    lwz r3, -0x7688(r13)
    stb r31, 0xec(r3)
_80072B68:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80072B7C(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, -0x7688(r13)
    lbz r3, 0xed(r4)
    cmplwi r3, 0xff
    beq _80072BAC
    clrlwi r0, r31, 0x18
    cmplw r3, r0
    beq _80072BBC
_80072BAC:
    mr r3, r31
    bl fn_80037B94
    lwz r3, -0x7688(r13)
    stb r31, 0xed(r3)
_80072BBC:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80072BD0(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r3
    lwz r4, -0x7688(r13)
    lbz r3, 0xee(r4)
    cmplwi r3, 0xff
    beq _80072C00
    clrlwi r0, r31, 0x18
    cmplw r3, r0
    beq _80072C10
_80072C00:
    mr r3, r31
    bl fn_80037BF4
    lwz r3, -0x7688(r13)
    stb r31, 0xee(r3)
_80072C10:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80072C24(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    slwi r8, r3, 4
    lwz r0, -0x7688(r13)
    addi r31, r8, 0xf0
    mr r27, r4
    add r31, r0, r31
    mr r28, r5
    lwz r0, 0(r31)
    mr r29, r6
    mr r30, r7
    cmpw r0, r27
    bne _80072C88
    lwz r0, 4(r31)
    cmpw r0, r28
    bne _80072C88
    lwz r0, 8(r31)
    cmpw r0, r29
    bne _80072C88
    lwz r0, 0xc(r31)
    cmpw r0, r30
    beq _80072CAC
_80072C88:
    mr r4, r27
    mr r5, r28
    mr r6, r29
    mr r7, r30
    bl fn_800370A0
    stw r27, 0(r31)
    stw r28, 4(r31)
    stw r29, 8(r31)
    stw r30, 0xc(r31)
_80072CAC:
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80072CC4(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_27
    slwi r8, r3, 4
    lwz r0, -0x7688(r13)
    addi r31, r8, 0x1f0
    mr r27, r4
    add r31, r0, r31
    mr r28, r5
    lwz r0, 0(r31)
    mr r29, r6
    mr r30, r7
    cmpw r0, r27
    bne _80072D28
    lwz r0, 4(r31)
    cmpw r0, r28
    bne _80072D28
    lwz r0, 8(r31)
    cmpw r0, r29
    bne _80072D28
    lwz r0, 0xc(r31)
    cmpw r0, r30
    beq _80072D4C
_80072D28:
    mr r4, r27
    mr r5, r28
    mr r6, r29
    mr r7, r30
    bl fn_800370E4
    stw r27, 0(r31)
    stw r28, 4(r31)
    stw r29, 8(r31)
    stw r30, 0xc(r31)
_80072D4C:
    addi r11, r1, 0x20
    bl _restgpr_27
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80072D64(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_26
    mulli r9, r3, 0x14
    lwz r0, -0x7688(r13)
    mr r30, r8
    mr r26, r4
    addi r31, r9, 0x2f0
    mr r27, r5
    add r31, r0, r31
    mr r28, r6
    lwz r0, 0x10(r31)
    mr r29, r7
    cmpw r0, r30
    bne _80072DDC
    lwz r0, 8(r31)
    cmpw r0, r28
    bne _80072DDC
    lbz r4, 0xc(r31)
    clrlwi r0, r29, 0x18
    cmplw r4, r0
    bne _80072DDC
    lwz r0, 0(r31)
    cmpw r0, r26
    bne _80072DDC
    lwz r0, 4(r31)
    cmpw r0, r27
    beq _80072E08
_80072DDC:
    mr r4, r26
    mr r5, r27
    mr r6, r28
    mr r7, r29
    mr r8, r30
    bl fn_80037128
    stw r26, 0(r31)
    stw r27, 4(r31)
    stw r28, 8(r31)
    stb r29, 0xc(r31)
    stw r30, 0x10(r31)
_80072E08:
    addi r11, r1, 0x20
    bl _restgpr_26
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80072E20(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_26
    mulli r9, r3, 0x14
    lwz r0, -0x7688(r13)
    mr r30, r8
    mr r26, r4
    addi r31, r9, 0x430
    mr r27, r5
    add r31, r0, r31
    mr r28, r6
    lwz r0, 0x10(r31)
    mr r29, r7
    cmpw r0, r30
    bne _80072E98
    lwz r0, 8(r31)
    cmpw r0, r28
    bne _80072E98
    lbz r4, 0xc(r31)
    clrlwi r0, r29, 0x18
    cmplw r4, r0
    bne _80072E98
    lwz r0, 0(r31)
    cmpw r0, r26
    bne _80072E98
    lwz r0, 4(r31)
    cmpw r0, r27
    beq _80072EC4
_80072E98:
    mr r4, r26
    mr r5, r27
    mr r6, r28
    mr r7, r29
    mr r8, r30
    bl fn_80037190
    stw r26, 0(r31)
    stw r27, 4(r31)
    stw r28, 8(r31)
    stb r29, 0xc(r31)
    stw r30, 0x10(r31)
_80072EC4:
    addi r11, r1, 0x20
    bl _restgpr_26
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

#pragma pop
