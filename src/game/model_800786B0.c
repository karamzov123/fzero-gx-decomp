typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void DCFlushRange(void);
extern void DCFlushRangeNoSync(void);
extern void OSReport(void);
extern void __GXSetDirtyState(void);
extern void _restgpr_22(void);
extern void _restgpr_23(void);
extern void _restgpr_25(void);
extern void _restgpr_26(void);
extern void _savegpr_22(void);
extern void _savegpr_23(void);
extern void _savegpr_25(void);
extern void _savegpr_26(void);
extern void fn_8000B864(void);
extern void fn_8000B888(void);
extern void fn_8000B8AC(void);
extern void fn_8000C49C(void);
extern void fn_80033A6C(void);
extern void fn_80038CFC(void);
extern void fn_800702E4(void);
extern void fn_8007048C(void);
extern void fn_80071794(void);
extern void fn_80071C04(void);
extern void fn_8007245C(void);
extern void fn_800724CC(void);
extern void fn_8007264C(void);
extern void fn_80075908(void);
extern void fn_80078344(void);
extern void fn_80078360(void);
extern void fn_800794F0(void);
extern void lbl_8006DFFC(void);
extern void memset(void);
asm void fn_800786B0(void);
asm void fn_80078768(void);
asm void fn_80078884(void);
asm void fn_80078944(void);
asm void fn_800789D8(void);
asm void fn_80078BC4(void);
asm void fn_80078C28(void);
asm void fn_80078CDC(void);
asm void fn_80078D48(void);
asm void fn_80078D60(void);
asm void fn_80078DA8(void);
asm void fn_80078F0C(void);
asm void fn_800791A4(void);
asm void fn_800791E8(void);
asm void fn_800793D4(void);
#pragma push
#pragma force_active on

asm void fn_800786B0(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_26
    mr r27, r4
    mr r26, r3
    lwz r0, 0xc(r4)
    mr r28, r5
    addi r30, r27, 0x20
    add r29, r27, r0
    bl fn_80033A6C
    li r31, 0
    b _8007870C
_800786E8:
    mr r3, r30
    mr r4, r28
    mr r5, r27
    mr r6, r29
    mr r7, r26
    bl fn_80078360
    mr r29, r3
    addi r31, r31, 1
    addi r30, r30, 0x60
_8007870C:
    lhz r0, 0x1a(r26)
    cmpw r31, r0
    blt _800786E8
    li r31, 0
    b _80078744
_80078720:
    mr r3, r30
    mr r4, r28
    mr r5, r27
    mr r6, r29
    mr r7, r26
    bl fn_80078360
    mr r29, r3
    addi r31, r31, 1
    addi r30, r30, 0x60
_80078744:
    lhz r0, 0x1c(r26)
    cmpw r31, r0
    blt _80078720
    addi r11, r1, 0x20
    bl _restgpr_26
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80078768(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    addi r11, r1, 0x20
    bl _savegpr_26
    mr r27, r4
    mr r26, r3
    lwz r0, 0xc(r4)
    mr r28, r5
    mr r31, r6
    addi r30, r27, 0x20
    add r29, r27, r0
    bl fn_80033A6C
    cmpwi r31, 0
    beq _800787E0
    li r31, 0
    b _800787D0
_800787AC:
    mr r3, r30
    mr r4, r28
    mr r5, r27
    mr r6, r29
    mr r7, r26
    bl fn_80078360
    mr r29, r3
    addi r31, r31, 1
    addi r30, r30, 0x60
_800787D0:
    lhz r0, 0x1a(r26)
    cmpw r31, r0
    blt _800787AC
    b _8007886C
_800787E0:
    lhz r4, 0x1a(r26)
    li r5, 0
    cmpwi r4, 0
    ble _80078834
    cmpwi r4, 8
    addi r3, r4, -8
    ble _8007881C
    addi r0, r3, 7
    srwi r0, r0, 3
    mtctr r0
    cmpwi r3, 0
    ble _8007881C
_80078810:
    addi r30, r30, 0x300
    addi r5, r5, 8
    bdnz _80078810
_8007881C:
    subf r0, r5, r4
    mtctr r0
    cmpw r5, r4
    bge _80078834
_8007882C:
    addi r30, r30, 0x60
    bdnz _8007882C
_80078834:
    li r31, 0
    b _80078860
_8007883C:
    mr r3, r30
    mr r4, r28
    mr r5, r27
    mr r6, r29
    mr r7, r26
    bl fn_80078360
    mr r29, r3
    addi r31, r31, 1
    addi r30, r30, 0x60
_80078860:
    lhz r0, 0x1c(r26)
    cmpw r31, r0
    blt _8007883C
_8007886C:
    addi r11, r1, 0x20
    bl _restgpr_26
    lwz r0, 0x24(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80078884(void)
{
    nofralloc
    lis r9, -0x3400
    ori r9, r9, 0x8000
_8007888C:
    lwz r7, 0(r5)
    addi r8, r7, 1
    li r10, 0x98
    stb r10, 0(r9)
    sth r7, 0(r9)
    lwzu r11, 4(r5)
    dcbt r4, r11
    add r0, r4, r11
_800788AC:
    lwzu r11, 4(r5)
    mr r10, r0
    addic. r7, r7, -1
    ble _800788C4
    dcbt r4, r11
    add r0, r4, r11
_800788C4:
    mcrf cr1, cr0
    psq_l f0, 0x0(r10), 0, 0
    psq_l f1, 0x8(r10), 1, 0
    psq_l f2, 0xc(r10), 0, 0
    psq_l f3, 0x14(r10), 1, 0
    rlwinm. r12, r3, 0x15, 0x1f, 0x1f
    mcrf cr5, cr0
    rlwinm. r12, r3, 0x13, 0x1f, 0x1f
    mcrf cr6, cr0
    rlwinm. r12, r3, 0x12, 0x1f, 0x1f
    mcrf cr7, cr0
    rlwinm. r12, r3, 0x11, 0x1f, 0x1f
    psq_st f0, 0x0(r9), 0, 0
    psq_st f1, 0x0(r9), 1, 0
    psq_st f2, 0x0(r9), 0, 0
    psq_st f3, 0x0(r9), 1, 0
    bc 13, 22, _80078910
    lwz r11, 0x30(r10)
    stw r11, 0(r9)
_80078910:
    beq cr6, _8007891C
    psq_l f0, 0x18(r10), 0, 0
    psq_st f0, 0x0(r9), 0, 0
_8007891C:
    bc 13, 30, _80078928
    psq_l f1, 0x20(r10), 0, 0
    psq_st f1, 0x0(r9), 0, 0
_80078928:
    bc 13, 2, _80078934
    psq_l f2, 0x28(r10), 0, 0
    psq_st f2, 0x0(r9), 0, 0
_80078934:
    bgt cr1, _800788AC
    subf. r6, r8, r6
    bgt _8007888C
    blr
}

asm void fn_80078944(void)
{
    nofralloc
    lis r9, -0x3400
    ori r9, r9, 0x8000
    addi r5, r5, -2
_80078950:
    lhzu r7, 2(r5)
    addi r8, r7, 1
    li r10, 0x99
    stb r10, 0(r9)
    sth r7, 0(r9)
_80078964:
    lhzu r11, 2(r5)
    add r10, r4, r11
    lwz r12, 0(r10)
    stw r12, 0(r9)
    lwz r12, 4(r10)
    stw r12, 0(r9)
    lwz r12, 8(r10)
    stw r12, 0(r9)
    rlwinm. r12, r3, 0x14, 0x1f, 0x1f
    bc 13, 2, _80078994
    lwz r11, 0x30(r10)
    stw r11, 0(r9)
_80078994:
    rlwinm. r12, r3, 0x13, 0x1f, 0x1f
    beq _800789A4
    lwz r11, 0xc(r10)
    stw r11, 0(r9)
_800789A4:
    rlwinm. r12, r3, 0x12, 0x1f, 0x1f
    beq _800789B4
    lwz r11, 0x10(r10)
    stw r11, 0(r9)
_800789B4:
    rlwinm. r12, r3, 0x11, 0x1f, 0x1f
    beq _800789C4
    lwz r11, 0x14(r10)
    stw r11, 0(r9)
_800789C4:
    addic. r7, r7, -1
    bgt _80078964
    subf. r6, r8, r6
    bgt _80078950
    blr
}

asm void fn_800789D8(void)
{
    nofralloc
    stwu r1, -0x60(r1)
    mflr r0
    stw r0, 0x64(r1)
    addi r11, r1, 0x60
    bl _savegpr_26
    mr r30, r4
    lwz r0, -0x7628(r13)
    lwz r4, 0(r4)
    mr r27, r5
    xori r5, r0, 2
    rlwinm. r0, r4, 0, 0x1e, 0x1e
    beq _80078A0C
    li r5, 0
_80078A0C:
    lwz r0, 4(r3)
    mr r26, r5
    rlwinm. r0, r0, 0, 0x1d, 0x1d
    beq _80078A24
    addi r3, r30, 0x20
    bl fn_80078BC4
_80078A24:
    lwz r3, 0x1c(r30)
    bl fn_8007245C
    lwz r12, -0x7630(r13)
    addi r31, r30, 0x60
    cmplwi r12, 0
    beq _80078A58
    stw r30, 0xc(r1)
    addi r3, r1, 8
    stw r27, 0x10(r1)
    mtctr r12
    bctrl
    clrlwi r0, r3, 0x18
    b _80078A74
_80078A58:
    lwz r0, -0x762c(r13)
    cmpwi r0, 0
    bne _80078A70
    mr r3, r30
    mr r4, r27
    bl fn_80075908
_80078A70:
    li r0, 1
_80078A74:
    clrlwi. r0, r0, 0x18
    beq _80078B44
    bl __GXSetDirtyState
    mr r28, r30
    li r27, 0
    li r29, 1
_80078A8C:
    lbz r3, 0x13(r30)
    slw r0, r29, r27
    and. r0, r3, r0
    beq _80078AB8
    mr r3, r26
    bl fn_80078D60
    lwz r4, 0x28(r28)
    mr r3, r31
    bl fn_80078344
    lwz r0, 0x28(r28)
    add r31, r31, r0
_80078AB8:
    cmpwi r26, 0
    beq _80078AC8
    lwz r0, -0x7628(r13)
    xori r26, r0, 1
_80078AC8:
    addi r27, r27, 1
    addi r28, r28, 4
    cmpwi r27, 2
    blt _80078A8C
    lbz r0, 0x13(r30)
    rlwinm. r0, r0, 0, 0x1c, 0x1d
    beq _80078BA8
    mr r3, r31
    bl fn_80078BC4
    mr r28, r31
    li r29, 0
    addi r31, r31, 0x20
_80078AF8:
    cmpwi r29, 0
    bne _80078B10
    lwz r0, -0x7628(r13)
    xori r3, r0, 2
    bl fn_80078D60
    b _80078B1C
_80078B10:
    lwz r0, -0x7628(r13)
    xori r3, r0, 1
    bl fn_80078D60
_80078B1C:
    lwz r4, 8(r28)
    mr r3, r31
    bl fn_80078344
    addi r29, r29, 1
    lwz r0, 8(r28)
    cmpwi r29, 2
    addi r28, r28, 4
    add r31, r31, r0
    blt _80078AF8
    b _80078BA8
_80078B44:
    lbz r5, 0x13(r30)
    li r0, 0
    li r4, 1
    addi r3, r30, 0x60
    slw r0, r4, r0
    and. r0, r5, r0
    beq _80078B68
    lwz r0, 0x28(r30)
    add r3, r3, r0
_80078B68:
    li r0, 1
    lbz r5, 0x13(r30)
    slw r0, r4, r0
    and. r0, r5, r0
    beq _80078B84
    lwz r0, 0x2c(r30)
    add r3, r3, r0
_80078B84:
    lbz r0, 0x13(r30)
    rlwinm. r0, r0, 0, 0x1c, 0x1d
    beq _80078BAC
    lwz r4, 8(r3)
    lwz r0, 0xc(r3)
    addi r3, r3, 0x20
    add r3, r3, r4
    add r3, r3, r0
    b _80078BAC
_80078BA8:
    mr r3, r31
_80078BAC:
    addi r11, r1, 0x60
    bl _restgpr_26
    lwz r0, 0x64(r1)
    mtlr r0
    addi r1, r1, 0x60
    blr
}

asm void fn_80078BC4(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    mr r31, r3
    stw r30, 8(r1)
    li r30, 0
_80078BE0:
    lbz r0, 0(r31)
    cmpwi r0, 0xff
    beq _80078C00
    mulli r0, r0, 0x30
    lwz r3, -0x7618(r13)
    addi r4, r30, 1
    add r3, r3, r0
    bl fn_800724CC
_80078C00:
    addi r30, r30, 1
    addi r31, r31, 1
    cmpwi r30, 8
    blt _80078BE0
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    lwz r30, 8(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80078C28(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    stw r31, 0x1c(r1)
    li r31, 0
    stw r30, 0x18(r1)
    mr r30, r31
    stw r29, 0x14(r1)
    li r29, 0
    stw r28, 0x10(r1)
    mr r28, r3
    b _80078C7C
_80078C58:
    lwz r4, -0x761c(r13)
    lwz r0, -0x7618(r13)
    lwz r3, -0x76c0(r13)
    lwzx r4, r4, r30
    add r5, r0, r31
    bl lbl_8006DFFC
    addi r31, r31, 0x30
    addi r30, r30, 4
    addi r29, r29, 1
_80078C7C:
    lbz r0, 0x1e(r28)
    cmplw r29, r0
    blt _80078C58
    li r31, 0
_80078C8C:
    addi r0, r31, 0x28
    lbzx r0, r28, r0
    cmpwi r0, 0xff
    beq _80078CB0
    mulli r0, r0, 0x30
    lwz r3, -0x7618(r13)
    addi r4, r31, 1
    add r3, r3, r0
    bl fn_800724CC
_80078CB0:
    addi r31, r31, 1
    cmpwi r31, 8
    blt _80078C8C
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    lwz r28, 0x10(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_80078CDC(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    cmpwi r3, 0
    stw r0, 0x14(r1)
    beq _80078CF8
    li r3, 0
    bl fn_80038CFC
_80078CF8:
    lwz r0, -0x7624(r13)
    lis r3, -0x7fe6
    lfs f0, -0x7998(r2)
    addi r3, r3, -0xed0
    cmpwi r0, 0
    stfs f0, 0xc(r3)
    beq _80078D18
    xori r0, r0, 3
_80078D18:
    lwz r6, -0x7688(r13)
    li r3, 0
    li r4, 0xa
    li r5, 0
    stw r0, 0x18(r6)
    li r6, 4
    li r7, 0
    bl fn_8007264C
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80078D48(void)
{
    nofralloc
    lis r5, -0x3400
    li r4, 0x61
    ori r5, r5, 0x8000
    stb r4, 0(r5)
    stw r3, 0(r5)
    blr
}

asm void fn_80078D60(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    lwz r0, -0x7624(r13)
    cmpw r0, r3
    beq _80078D98
    stw r3, -0x7624(r13)
    slwi r0, r3, 0xe
    lwz r4, -0x7de8(r2)
    lwz r3, 0x204(r4)
    rlwinm r3, r3, 0, 0x12, 0xf
    or r3, r3, r0
    stw r3, 0x204(r4)
    bl fn_80078D48
_80078D98:
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_80078DA8(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_25
    lwz r7, 0(r4)
    mr r29, r3
    li r6, 0
    addi r0, r4, 8
    stw r7, 0(r3)
    mr r30, r5
    mr r5, r6
    li r31, 0
    lwz r3, 4(r4)
    li r7, 0
    add r3, r4, r3
    stw r3, 4(r29)
    stw r0, 8(r29)
    lwz r0, 0(r4)
    lwz r3, 8(r29)
    slwi r0, r0, 3
    add r0, r3, r0
    stw r0, 0xc(r29)
    stw r6, 0x10(r29)
    stw r6, 0x14(r29)
    b _80078E64
_80078E10:
    lwz r0, 8(r29)
    add r8, r0, r5
    lwz r3, 0(r8)
    addis r0, r3, 1
    cmplwi r0, 0xffff
    bne _80078E38
    stw r6, 0(r8)
    lwz r0, -0x7d98(r13)
    stw r0, 4(r8)
    b _80078E5C
_80078E38:
    lwz r0, 4(r29)
    add r4, r0, r3
    stw r4, 0(r8)
    lwz r3, 0xc(r29)
    lwz r0, 4(r8)
    add r0, r3, r0
    stw r0, 4(r8)
    lhz r0, 0x18(r4)
    add r31, r31, r0
_80078E5C:
    addi r5, r5, 8
    addi r7, r7, 1
_80078E64:
    lwz r0, 0(r29)
    cmplw r7, r0
    blt _80078E10
    cmplwi r30, 0
    beq _80078E90
    cmplwi r31, 0
    beq _80078E90
    slwi r3, r31, 5
    bl fn_80071794
    stw r3, 0x14(r29)
    b _80078E94
_80078E90:
    li r31, 0
_80078E94:
    li r27, 0
    lwz r26, 0x14(r29)
    mr r28, r27
    b _80078EE8
_80078EA4:
    lwz r0, 8(r29)
    add r25, r0, r28
    lwz r3, 0(r25)
    cmplwi r3, 0
    beq _80078EE0
    lwz r6, 4(r25)
    mr r4, r30
    mr r5, r26
    bl fn_80078F0C
    cmplwi r31, 0
    beq _80078EE0
    lwz r3, 0(r25)
    lhz r0, 0x18(r3)
    slwi r0, r0, 5
    add r26, r26, r0
_80078EE0:
    addi r28, r28, 8
    addi r27, r27, 1
_80078EE8:
    lwz r0, 0(r29)
    cmplw r27, r0
    blt _80078EA4
    addi r11, r1, 0x30
    bl _restgpr_25
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_80078F0C(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_23
    or. r27, r4, r4
    mr r26, r3
    lis r3, -0x7fea
    mr r28, r5
    mr r29, r6
    addi r24, r26, 0x40
    addi r31, r3, -0x52c8
    li r30, 0
    bne _80078F88
    lhz r4, 0x18(r26)
    mr r3, r24
    li r5, 0
    mtctr r4
    cmpwi r4, 0
    ble _80078F74
_80078F5C:
    lwz r0, 0(r3)
    rlwinm. r0, r0, 0, 0xa, 0xa
    beq _80078F6C
    addi r5, r5, 1
_80078F6C:
    addi r3, r3, 0x20
    bdnz _80078F5C
_80078F74:
    cmpw r5, r4
    beq _80078F88
    li r0, 0
    li r30, 1
    sth r0, 0x18(r26)
_80078F88:
    lhz r0, 0x18(r26)
    cmplwi r0, 0
    beq _80078FF0
    cmplwi r28, 0
    beq _80078FB0
    stw r28, 0x24(r26)
    lhz r0, 0x18(r26)
    slwi r0, r0, 5
    add r28, r28, r0
    b _80078FBC
_80078FB0:
    rlwinm r3, r0, 5, 0xb, 0x1a
    bl fn_80071794
    stw r3, 0x24(r26)
_80078FBC:
    lwz r0, 0x24(r26)
    cmplwi r0, 0
    bne _80078FF8
    mr r4, r29
    addi r3, r31, 0xa4
    crxor 6, 6, 6
    bl OSReport
    addi r3, r31, 0xb0
    addi r5, r31, 0xbc
    li r4, 0x96b
    crxor 6, 6, 6
    bl fn_8000C49C
    b _80078FF8
_80078FF0:
    li r0, 0
    stw r0, 0x24(r26)
_80078FF8:
    li r23, 0
    mr r25, r23
    b _80079054
_80079004:
    lwz r0, 0x24(r26)
    mr r3, r24
    mr r4, r27
    add r0, r0, r25
    stw r0, 8(r24)
    bl fn_80071C04
    lwz r0, 0(r24)
    rlwinm. r0, r0, 0, 0xa, 0xa
    bne _80079048
    lwz r0, 8(r24)
    cmplwi r0, 0
    bne _80079048
    lhz r5, 4(r24)
    mr r4, r29
    addi r3, r31, 0xd8
    crxor 6, 6, 6
    bl OSReport
_80079048:
    addi r25, r25, 0x20
    addi r24, r24, 0x20
    addi r23, r23, 1
_80079054:
    lhz r0, 0x18(r26)
    cmpw r23, r0
    blt _80079004
    lwz r5, 4(r26)
    lwz r3, 0x20(r26)
    rlwinm. r0, r5, 0, 0x1b, 0x1c
    add r4, r26, r3
    beq _8007907C
    stw r5, 0x1c(r4)
    addi r4, r4, 0x20
_8007907C:
    li r3, 0
    b _80079174
_80079084:
    cmpwi r30, 0
    beq _80079094
    li r0, 0
    stb r0, 0x12(r4)
_80079094:
    lwz r0, 4(r26)
    rlwinm. r0, r0, 0, 0x1b, 0x1c
    beq _800790DC
    lwz r0, 0x1c(r4)
    mr r5, r4
    addi r4, r4, 0x60
    rlwinm. r0, r0, 0, 0x14, 0x14
    beq _800790C0
    lwz r0, 0(r5)
    ori r0, r0, 0x100
    stw r0, 0(r5)
_800790C0:
    lbz r0, 0x12(r5)
    cmplwi r0, 0
    bne _80079170
    lwz r0, 0(r5)
    ori r0, r0, 0x80
    stw r0, 0(r5)
    b _80079170
_800790DC:
    lwz r0, 0x1c(r4)
    rlwinm. r0, r0, 0, 0x14, 0x14
    beq _800790F4
    lwz r0, 0(r4)
    ori r0, r0, 0x100
    stw r0, 0(r4)
_800790F4:
    lbz r0, 0x12(r4)
    cmplwi r0, 0
    bne _8007910C
    lwz r0, 0(r4)
    ori r0, r0, 0x80
    stw r0, 0(r4)
_8007910C:
    lbz r6, 0x13(r4)
    li r0, 0
    li r5, 1
    addi r7, r4, 0x60
    slw r0, r5, r0
    and. r0, r6, r0
    beq _80079130
    lwz r0, 0x28(r4)
    add r7, r7, r0
_80079130:
    li r0, 1
    lbz r6, 0x13(r4)
    slw r0, r5, r0
    and. r0, r6, r0
    beq _8007914C
    lwz r0, 0x2c(r4)
    add r7, r7, r0
_8007914C:
    lbz r0, 0x13(r4)
    rlwinm. r0, r0, 0, 0x1c, 0x1d
    beq _8007916C
    lwz r4, 8(r7)
    lwz r0, 0xc(r7)
    addi r7, r7, 0x20
    add r7, r7, r4
    add r7, r7, r0
_8007916C:
    mr r4, r7
_80079170:
    addi r3, r3, 1
_80079174:
    lhz r5, 0x1a(r26)
    lhz r0, 0x1c(r26)
    add r0, r5, r0
    cmpw r3, r0
    blt _80079084
    mr r3, r28
    addi r11, r1, 0x30
    bl _restgpr_23
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_800791A4(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    bl fn_8007048C
    stb r3, -0x760c(r13)
    clrlwi r3, r3, 0x18
    bl fn_800702E4
    lbz r0, -0x760c(r13)
    stw r3, -0x7610(r13)
    cmplwi r0, 0
    beq _800791D8
    li r0, 1
    stw r0, -0x7608(r13)
_800791D8:
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_800791E8(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_22
    lwz r0, -0x7608(r13)
    mr r29, r3
    mr r30, r4
    mr r22, r5
    cmpwi r0, 0
    bne _8007921C
    bl fn_800794F0
    b _800793BC
_8007921C:
    lbz r5, -0x760c(r13)
    srwi r25, r22, 0xa
    rlwinm r0, r22, 0, 0, 0x15
    clrlwi r31, r22, 0x1b
    divwu r28, r25, r5
    mr r3, r30
    subf r0, r0, r22
    mr r4, r22
    subf r0, r31, r0
    srwi r24, r0, 5
    mullw r0, r28, r5
    subf r25, r0, r25
    bl DCFlushRange
    mr r3, r29
    mr r4, r22
    bl DCFlushRangeNoSync
    li r27, 0
    b _800792E0
_80079264:
    lwz r22, -0x7610(r13)
    li r26, 0
    mr r23, r22
    b _80079298
_80079274:
    li r3, 0xe
    bl fn_8000B8AC
    mr r3, r22
    mr r4, r30
    li r5, 0x20
    bl fn_8000B864
    addi r22, r22, 0x400
    addi r30, r30, 0x400
    addi r26, r26, 1
_80079298:
    lbz r0, -0x760c(r13)
    cmplw r26, r0
    blt _80079274
    li r26, 0
    b _800792D0
_800792AC:
    li r3, 0xe
    bl fn_8000B8AC
    mr r3, r29
    mr r4, r23
    li r5, 0x20
    bl fn_8000B888
    addi r29, r29, 0x400
    addi r23, r23, 0x400
    addi r26, r26, 1
_800792D0:
    lbz r0, -0x760c(r13)
    cmplw r26, r0
    blt _800792AC
    addi r27, r27, 1
_800792E0:
    cmplw r27, r28
    blt _80079264
    lwz r28, -0x7610(r13)
    li r26, 0
    mr r27, r28
    b _8007931C
_800792F8:
    li r3, 0xe
    bl fn_8000B8AC
    mr r3, r28
    mr r4, r30
    li r5, 0x20
    bl fn_8000B864
    addi r28, r28, 0x400
    addi r30, r30, 0x400
    addi r26, r26, 1
_8007931C:
    cmplw r26, r25
    blt _800792F8
    li r26, 0
    b _80079350
_8007932C:
    li r3, 0xe
    bl fn_8000B8AC
    mr r3, r29
    mr r4, r27
    li r5, 0x20
    bl fn_8000B888
    addi r29, r29, 0x400
    addi r27, r27, 0x400
    addi r26, r26, 1
_80079350:
    cmplw r26, r25
    blt _8007932C
    cmplwi r24, 0
    beq _8007939C
    li r3, 0xe
    bl fn_8000B8AC
    mr r3, r28
    mr r4, r30
    mr r5, r24
    bl fn_8000B864
    slwi r28, r24, 5
    li r3, 0xe
    add r30, r30, r28
    bl fn_8000B8AC
    mr r3, r29
    mr r4, r27
    mr r5, r24
    bl fn_8000B888
    add r29, r29, r28
_8007939C:
    cmplwi r31, 0
    beq _800793B4
    mr r3, r29
    mr r4, r30
    mr r5, r31
    bl fn_800794F0
_800793B4:
    li r3, 0
    bl fn_8000B8AC
_800793BC:
    addi r11, r1, 0x30
    bl _restgpr_22
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

asm void fn_800793D4(void)
{
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    stw r0, 0x34(r1)
    addi r11, r1, 0x30
    bl _savegpr_25
    lwz r0, -0x7608(r13)
    mr r25, r3
    mr r26, r4
    li r27, 0
    cmpwi r0, 0
    bne _8007940C
    clrlwi r4, r26, 0x18
    bl memset
    b _800794D8
_8007940C:
    rlwinm r0, r5, 0, 0, 0x15
    clrlwi r29, r5, 0x1b
    subf r0, r0, r5
    mr r4, r5
    subf r0, r29, r0
    srwi r30, r5, 0xa
    srwi r28, r0, 5
    bl DCFlushRangeNoSync
    cmplwi r30, 0
    beq _80079478
    lwz r3, -0x7610(r13)
    clrlwi r4, r26, 0x18
    li r5, 0x400
    bl memset
    li r27, 1
    li r31, 0
    b _80079470
_80079450:
    li r3, 0xe
    bl fn_8000B8AC
    lwz r4, -0x7610(r13)
    mr r3, r25
    li r5, 0x20
    bl fn_8000B888
    addi r25, r25, 0x400
    addi r31, r31, 1
_80079470:
    cmplw r31, r30
    blt _80079450
_80079478:
    cmplwi r28, 0
    beq _800794B8
    cmpwi r27, 0
    bne _80079498
    lwz r3, -0x7610(r13)
    clrlwi r4, r26, 0x18
    slwi r5, r28, 5
    bl memset
_80079498:
    li r3, 0xe
    bl fn_8000B8AC
    lwz r4, -0x7610(r13)
    mr r3, r25
    mr r5, r28
    bl fn_8000B888
    slwi r0, r28, 5
    add r25, r25, r0
_800794B8:
    cmplwi r29, 0
    beq _800794D0
    mr r3, r25
    mr r5, r29
    clrlwi r4, r26, 0x18
    bl memset
_800794D0:
    li r3, 0
    bl fn_8000B8AC
_800794D8:
    addi r11, r1, 0x30
    bl _restgpr_25
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}

#pragma pop
