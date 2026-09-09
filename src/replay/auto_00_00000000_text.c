/* Module-scoped replay REL source. Only fn_13_A40 is natural C; all other functions are retained as literal asm. */
extern unsigned char gLanguageIndexTable[];
extern unsigned char g_currentHeapHandle[];
extern void _restgpr_15(void);
extern void _restgpr_18(void);
extern void _savegpr_15(void);
extern void _savegpr_18(void);
extern void fn_1_12F10C(void);
extern void fn_1_133DBC(void);
extern void fn_1_134AD4(void);
extern void fn_1_1380F0(void);
extern void fn_1_13ABA8(void);
extern void fn_1_154708(void);
extern void fn_1_1547FC(void);
extern void fn_1_154C84(void);
extern void fn_1_154CC4(void);
extern void fn_1_154D84(void);
extern void fn_1_154E24(void);
extern void fn_1_159440(void);
extern void fn_1_1596DC(void);
extern void fn_1_36AD0(void);
extern void fn_1_3CC4(void);
extern void fn_1_3CF0(void);
extern void fn_1_3EB78(void);
extern void fn_1_3EC88(void);
extern void fn_1_3ED8C(void);
extern void fn_1_3EF14(void);
extern void fn_1_3EF8C(void);
extern void fn_1_3EFF0(void);
extern void fn_1_3F038(void);
extern void fn_1_3FCB0(void);
extern void fn_1_3FCD4(void);
extern void fn_1_407C(void);
extern void fn_1_411A4(void);
extern void fn_1_412A0(void);
extern void fn_1_41A8(void);
extern void fn_1_435C(void);
extern void fn_1_45D0(void);
extern void fn_1_46B4(void);
extern void fn_1_479F0(void);
extern void fn_1_47A60(void);
extern void fn_1_48418(void);
extern void fn_1_484CC(void);
extern void fn_1_49F0(void);
extern void fn_1_4A00(void);
extern void fn_1_4C10(void);
extern void fn_1_4F734(void);
extern void fn_1_A0680(void);
extern void fn_1_A0AA4(void);
extern void fn_1_A1588(void);
extern void fn_1_A8F78(void);
extern void fn_1_D0790(void);
extern void fn_1_F453C(void);
extern void fn_1_F4794(void);
extern void fn_1_F47A0(void);
extern void fn_80008BA8(void);
extern void fn_80008BEC(void);
extern unsigned char lbl_13_bss_0[];
extern unsigned char lbl_13_bss_38[];
extern unsigned char lbl_13_bss_3C[];
extern unsigned char lbl_13_bss_4[];
extern unsigned char lbl_13_bss_40[];
extern unsigned char lbl_13_bss_4C[];
extern unsigned char lbl_13_bss_50[];
extern unsigned char lbl_13_data_18[];
extern unsigned char lbl_13_data_48[];
extern unsigned char lbl_13_data_98[];
extern unsigned char lbl_13_rodata_0[];
extern unsigned char lbl_13_rodata_10[];
extern unsigned char lbl_13_rodata_C[];
extern unsigned char lbl_1_bss_26B80[];
extern unsigned char lbl_1_bss_26C60[];
extern unsigned char lbl_1_bss_6EAB4[];
extern unsigned char lbl_1_bss_6EAD0[];
extern unsigned char lbl_1_bss_7167C[];
extern unsigned char lbl_1_bss_71680[];
extern unsigned char lbl_1_bss_71684[];
extern unsigned char lbl_1_bss_71688[];
extern unsigned char lbl_1_bss_7168C[];
extern unsigned char lbl_1_bss_7EFD8[];
extern unsigned char lbl_1_bss_8B3A0[];
extern unsigned char lbl_1_bss_960[];
extern unsigned char lbl_1_bss_962[];
extern unsigned char lbl_1_bss_968[];
extern unsigned char lbl_1_bss_96A[];
extern unsigned char lbl_1_bss_970[];
extern unsigned char lbl_1_rodata_26F8[];
extern unsigned char lbl_801A63C0[];
extern unsigned char lbl_801A63D0[];
extern void fn_13_0(void);
extern void fn_13_3FC(void);
extern void fn_13_A48(void);
extern void fn_13_A6C(void);
extern void _prolog(void);
extern void fn_13_AFC(void);
extern void fn_13_B00(void);
extern void _epilog(void);
extern void fn_13_B08(void);
extern void fn_13_B64(void);
extern void fn_13_B78(void);
extern void fn_13_B7C(void);
extern void fn_13_BCC(void);
extern void fn_13_CDC(void);
extern void fn_13_E8C(void);
extern void fn_13_EF0(void);
extern void fn_13_F00(void);
extern void fn_13_FA8(void);

asm void fn_13_0(void)
{
    nofralloc
    stwu r1, -0x50(r1)
    mflr r0
    stw r0, 0x54(r1)
    addi r11, r1, 0x50
    bl _savegpr_18
    lis r3, lbl_801A63D0@ha
    lis r4, lbl_13_bss_0@ha
    addi r3, r3, lbl_801A63D0@l
    li r0, 0x0
    lwz r3, 0x0(r3)
    addi r29, r4, lbl_13_bss_0@l
    stw r0, 0x4(r29)
    addi r4, r29, 0x4
    li r5, 0x8
    stw r3, 0x0(r29)
    bl fn_1_F453C
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x7
    bl fn_1_F453C
    clrlwi r20, r3, 24
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x6
    bl fn_1_F453C
    mr r30, r3
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x20
    bl fn_1_F453C
    bl fn_1_F47A0
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x20
    bl fn_1_F453C
    lis r5, lbl_801A63C0@ha
    addi r4, r29, 0x4
    addi r6, r5, lbl_801A63C0@l
    li r5, 0x5
    stw r3, 0x0(r6)
    lwz r3, 0x0(r29)
    bl fn_1_F453C
    mr r31, r3
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x3
    bl fn_1_F453C
    lis r4, lbl_1_bss_8B3A0@ha
    addi r5, r4, lbl_1_bss_8B3A0@l
    sth r3, 0x8(r5)
    addi r4, r29, 0x4
    lwz r3, 0x0(r29)
    li r5, 0x2
    bl fn_1_F453C
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x1
    bl fn_1_F453C
    clrlwi r21, r3, 24
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x7
    bl fn_1_F453C
    lis r4, lbl_1_bss_26B80@ha
    clrlwi r22, r3, 24
    addi r28, r4, lbl_1_bss_26B80@l
    addi r26, r29, 0x8
    li r23, 0x0
    li r24, 0x0
    li r27, 0x0
    b L_000002C0
L_0000011C:
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x1
    bl fn_1_F453C
    stb r3, 0x0(r28)
    addi r4, r29, 0x4
    lwz r3, 0x0(r29)
    li r5, 0x6
    bl fn_1_F453C
    cmplwi r20, 0x3
    stb r3, 0x1(r28)
    blt L_00000160
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x5
    bl fn_1_F453C
    stb r3, 0x4(r28)
L_00000160:
    cmplwi r20, 0x2
    blt L_0000017C
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x7
    bl fn_1_F453C
    stb r3, 0x3(r28)
L_0000017C:
    lbz r0, 0x0(r28)
    cmplwi r0, 0x0
    beq L_000002A0
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x2
    bl fn_1_F453C
    cmplwi r20, 0x2
    stb r3, 0x2(r28)
    bge L_000001B8
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x7
    bl fn_1_F453C
    stb r3, 0x3(r28)
L_000001B8:
    lbz r4, 0x1(r28)
    clrlwi r25, r23, 24
    addi r3, r1, 0xc
    lbz r0, 0x2(r28)
    addi r5, r1, 0x8
    stbx r4, r3, r25
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    stbx r0, r5, r25
    li r5, 0x1
    bl fn_1_F453C
    clrlwi. r0, r3, 24
    beq L_00000248
    li r18, 0x0
L_000001F0:
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x8
    bl fn_1_F453C
    clrlwi r19, r3, 24
    bl fn_1_36AD0
    add r0, r27, r18
    addi r18, r18, 0x1
    cmplwi r18, 0x81c0
    stbx r19, r3, r0
    blt L_000001F0
    bl fn_1_36AD0
    mulli r0, r25, 0xc
    addi r4, r27, 0x4
    li r5, 0xc
    add r4, r3, r4
    addi r3, r29, 0x8
    add r3, r3, r0
    bl fn_80008BA8
    bl fn_1_36AD0
    bl fn_1_12F10C
    b L_00000298
L_00000248:
    mulli r5, r25, 0xc
    addi r7, r29, 0x8
    lbz r6, 0x1(r28)
    li r4, 0x1
    lbz r3, 0x2(r28)
    li r0, 0x0
    add r7, r7, r5
    slw r4, r4, r3
    stb r6, 0x1(r7)
    addi r3, r26, 0x6
    lbz r6, 0x3(r28)
    li r5, 0x5
    stb r4, 0x2(r7)
    li r4, 0x41
    stb r6, 0xb(r7)
    stb r0, 0x4(r7)
    stb r0, 0x3(r7)
    stb r0, 0x5(r7)
    stb r0, 0x0(r7)
    bl fn_80008BEC
L_00000298:
    addi r23, r23, 0x1
    b L_000002AC
L_000002A0:
    li r0, 0x0
    stb r0, 0x2(r28)
    stb r0, 0x3(r28)
L_000002AC:
    addis r27, r27, 0x1
    addi r26, r26, 0xc
    subi r27, r27, 0x7e40
    addi r24, r24, 0x1
    addi r28, r28, 0x5
L_000002C0:
    cmplw r24, r31
    blt L_0000011C
    cmplwi r20, 0x4
    blt L_00000308
    lis r3, lbl_1_bss_7EFD8@ha
    clrlwi r24, r23, 24
    addi r19, r3, lbl_1_bss_7EFD8@l
    li r25, 0x0
    b L_00000300
L_000002E4:
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x1
    bl fn_1_F453C
    stb r3, 0x3c(r19)
    addi r19, r19, 0x1
    addi r25, r25, 0x1
L_00000300:
    cmpw r25, r24
    blt L_000002E4
L_00000308:
    lis r3, lbl_1_bss_7EFD8@ha
    clrlwi r24, r23, 24
    addi r19, r3, lbl_1_bss_7EFD8@l
    li r25, 0x0
    b L_0000033C
L_0000031C:
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x2
    bl fn_1_F453C
    addi r0, r3, 0x1
    addi r25, r25, 0x1
    stb r0, 0x38(r19)
    addi r19, r19, 0x1
L_0000033C:
    cmpw r25, r24
    blt L_0000031C
    cmplwi r20, 0x5
    blt L_00000368
    lwz r3, 0x0(r29)
    addi r4, r29, 0x4
    li r5, 0x14
    bl fn_1_F453C
    lis r4, lbl_1_bss_7EFD8@ha
    addi r4, r4, lbl_1_bss_7EFD8@l
    stw r3, 0x8(r4)
L_00000368:
    li r3, 0x6
    bl fn_1_3EF8C
    mr r4, r22
    clrlwi r6, r30, 24
    clrlwi r8, r31, 24
    li r3, 0x0
    li r5, 0x1
    li r7, 0xa
    li r9, 0x0
    bl fn_1_3ED8C
    mr r3, r23
    addi r4, r1, 0xc
    addi r5, r1, 0x8
    li r6, 0x0
    bl fn_1_3EB78
    mr r3, r23
    addi r4, r29, 0x8
    bl fn_1_3EC88
    lis r3, fn_13_A6C@ha
    li r4, 0x1
    addi r3, r3, fn_13_A6C@l
    bl fn_1_3EFF0
    cmplwi r21, 0x0
    beq L_000003D4
    lis r3, 0x2
    bl fn_1_3FCB0
    b L_000003DC
L_000003D4:
    lis r3, 0x2
    bl fn_1_3FCD4
L_000003DC:
    lis r3, 0x80
    bl fn_1_3FCB0
    addi r11, r1, 0x50
    bl _restgpr_18
    lwz r0, 0x54(r1)
    mtlr r0
    addi r1, r1, 0x50
    blr
}

asm void fn_13_3FC(void)
{
    nofralloc
    stwu r1, -0x1590(r1)
    mflr r0
    stw r0, 0x1594(r1)
    addi r11, r1, 0x1590
    bl _savegpr_15
    addi r3, r1, 0x68
    bl fn_1_3EF14
    lis r4, lbl_13_bss_0@ha
    lis r3, lbl_13_bss_4@ha
    addi r6, r4, lbl_13_bss_0@l
    li r5, 0x8
    addi r4, r3, lbl_13_bss_4@l
    lwz r3, 0x0(r6)
    bl fn_1_F453C
    lis r5, lbl_1_bss_7EFD8@ha
    lis r4, lbl_13_bss_4@ha
    addi r6, r5, lbl_1_bss_7EFD8@l
    li r20, 0x0
    addi r15, r4, lbl_13_bss_4@l
    lwz r4, 0x40(r6)
    lis r5, lbl_13_bss_0@ha
    stw r15, 0x1520(r1)
    addis r4, r4, 0x1
    addi r22, r6, 0x40
    sth r3, -0x110(r4)
    addi r21, r6, 0x18
    mr r16, r15
    mr r17, r15
    lbz r0, 0x70(r1)
    mr r18, r15
    stw r15, 0x1524(r1)
    mr r25, r15
    mr r26, r15
    mr r27, r15
    stb r0, 0x18(r6)
    mr r28, r15
    mr r29, r15
    mr r30, r15
    stw r15, 0x1528(r1)
    addi r31, r5, lbl_13_bss_0@l
    li r23, 0x0
    stw r15, 0x152c(r1)
    stw r15, 0x1530(r1)
    stw r15, 0x1534(r1)
    stw r15, 0x1538(r1)
    stw r15, 0x153c(r1)
    b L_000008D8
L_000004B8:
    lwz r3, 0x0(r31)
    mr r4, r25
    li r5, 0xe
    bl fn_1_F453C
    addis r6, r23, 0x1
    lwz r7, 0x0(r22)
    subi r6, r6, 0xb4
    mr r4, r26
    lhzx r0, r7, r6
    rlwimi r0, r3, 1, 16, 30
    li r5, 0xe
    sthx r0, r7, r6
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    addis r6, r23, 0x1
    lwz r7, 0x0(r22)
    subi r6, r6, 0xb0
    mr r4, r27
    lhzx r0, r7, r6
    rlwimi r0, r3, 1, 16, 30
    li r5, 0x4
    sthx r0, r7, r6
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    addis r6, r23, 0x1
    lwz r7, 0x0(r22)
    subi r6, r6, 0xb4
    mr r4, r28
    lwzx r0, r7, r6
    rlwimi r0, r3, 14, 15, 17
    li r5, 0x5
    stwx r0, r7, r6
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    addis r6, r23, 0x1
    lwz r7, 0x0(r22)
    subi r6, r6, 0xb2
    mr r4, r29
    lbzx r0, r7, r6
    rlwimi r0, r3, 1, 26, 30
    li r5, 0x5
    stbx r0, r7, r6
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    addis r6, r23, 0x1
    lwz r7, 0x0(r22)
    subi r6, r6, 0xb2
    mr r4, r30
    lhzx r0, r7, r6
    rlwimi r0, r3, 4, 23, 27
    li r5, 0x5
    sthx r0, r7, r6
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    addis r6, r23, 0x1
    lwz r7, 0x0(r22)
    subi r6, r6, 0xb0
    lwz r4, 0x1520(r1)
    lwzx r0, r7, r6
    rlwimi r0, r3, 12, 15, 19
    li r5, 0x5
    stwx r0, r7, r6
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    addis r6, r23, 0x1
    lwz r7, 0x0(r22)
    subi r6, r6, 0xae
    lwz r4, 0x1524(r1)
    lhzx r0, r7, r6
    rlwimi r0, r3, 7, 20, 24
    li r5, 0x5
    sthx r0, r7, r6
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    addis r4, r23, 0x1
    lwz r5, 0x0(r22)
    subi r4, r4, 0xad
    li r19, 0x0
    lbzx r0, r5, r4
    rlwimi r0, r3, 2, 25, 29
    li r24, 0x0
    stbx r0, r5, r4
    b L_00000774
L_00000604:
    lwz r3, 0x0(r31)
    mr r4, r15
    li r5, 0x20
    bl fn_1_F453C
    stw r3, 0x60(r1)
    addi r3, r1, 0x64
    addi r4, r1, 0x60
    li r5, 0x4
    bl fn_80008BA8
    lwz r0, 0x0(r22)
    mr r4, r15
    lfs f0, 0x64(r1)
    li r5, 0x20
    add r3, r0, r24
    addis r3, r3, 0x1
    subi r3, r3, 0xac
    stfsx f0, r23, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x58(r1)
    addi r3, r1, 0x5c
    addi r4, r1, 0x58
    li r5, 0x4
    bl fn_80008BA8
    lwz r0, 0x0(r22)
    mr r4, r15
    lfs f0, 0x5c(r1)
    li r5, 0x20
    add r3, r0, r24
    addis r3, r3, 0x1
    subi r3, r3, 0xa8
    stfsx f0, r23, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x50(r1)
    addi r3, r1, 0x54
    addi r4, r1, 0x50
    li r5, 0x4
    bl fn_80008BA8
    lwz r0, 0x0(r22)
    mr r4, r16
    lfs f0, 0x54(r1)
    li r5, 0x20
    add r3, r0, r24
    addis r3, r3, 0x1
    subi r3, r3, 0xa4
    stfsx f0, r23, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x48(r1)
    addi r3, r1, 0x4c
    addi r4, r1, 0x48
    li r5, 0x4
    bl fn_80008BA8
    lwz r0, 0x0(r22)
    mr r4, r17
    lfs f0, 0x4c(r1)
    li r5, 0x20
    add r3, r0, r24
    addis r3, r3, 0x1
    subi r3, r3, 0x7c
    stfsx f0, r23, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x40(r1)
    addi r3, r1, 0x44
    addi r4, r1, 0x40
    li r5, 0x4
    bl fn_80008BA8
    lwz r0, 0x0(r22)
    mr r4, r18
    lfs f0, 0x44(r1)
    li r5, 0x20
    add r3, r0, r24
    addis r3, r3, 0x1
    subi r3, r3, 0x78
    stfsx f0, r23, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x38(r1)
    addi r3, r1, 0x3c
    addi r4, r1, 0x38
    li r5, 0x4
    bl fn_80008BA8
    lwz r0, 0x0(r22)
    addi r19, r19, 0x1
    lfs f0, 0x3c(r1)
    add r3, r0, r24
    addi r24, r24, 0xc
    addis r3, r3, 0x1
    subi r3, r3, 0x74
    stfsx f0, r23, r3
L_00000774:
    lbz r0, 0x0(r21)
    cmpw r19, r0
    blt L_00000604
    lwz r3, 0x0(r31)
    li r5, 0x20
    lwz r4, 0x1528(r1)
    bl fn_1_F453C
    stw r3, 0x30(r1)
    addi r3, r1, 0x34
    addi r4, r1, 0x30
    li r5, 0x4
    bl fn_80008BA8
    addis r3, r23, 0x1
    lfs f0, 0x34(r1)
    lwz r6, 0x0(r22)
    subi r3, r3, 0x4c
    lwz r4, 0x152c(r1)
    li r5, 0x20
    stfsx f0, r6, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x28(r1)
    addi r3, r1, 0x2c
    addi r4, r1, 0x28
    li r5, 0x4
    bl fn_80008BA8
    addis r3, r23, 0x1
    lfs f0, 0x2c(r1)
    lwz r6, 0x0(r22)
    subi r3, r3, 0x48
    lwz r4, 0x1530(r1)
    li r5, 0x20
    stfsx f0, r6, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x20(r1)
    addi r3, r1, 0x24
    addi r4, r1, 0x20
    li r5, 0x4
    bl fn_80008BA8
    addis r3, r23, 0x1
    lfs f0, 0x24(r1)
    lwz r6, 0x0(r22)
    subi r3, r3, 0x44
    lwz r4, 0x1534(r1)
    li r5, 0x20
    stfsx f0, r6, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x18(r1)
    addi r3, r1, 0x1c
    addi r4, r1, 0x18
    li r5, 0x4
    bl fn_80008BA8
    addis r3, r23, 0x1
    lfs f0, 0x1c(r1)
    lwz r6, 0x0(r22)
    subi r3, r3, 0x40
    lwz r4, 0x1538(r1)
    li r5, 0x20
    stfsx f0, r6, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x10(r1)
    addi r3, r1, 0x14
    addi r4, r1, 0x10
    li r5, 0x4
    bl fn_80008BA8
    addis r3, r23, 0x1
    lfs f0, 0x14(r1)
    lwz r6, 0x0(r22)
    subi r3, r3, 0x3c
    lwz r4, 0x153c(r1)
    li r5, 0x20
    stfsx f0, r6, r3
    lwz r3, 0x0(r31)
    bl fn_1_F453C
    stw r3, 0x8(r1)
    addi r3, r1, 0xc
    addi r4, r1, 0x8
    li r5, 0x4
    bl fn_80008BA8
    addis r3, r23, 0x1
    lfs f0, 0xc(r1)
    lwz r4, 0x0(r22)
    subi r3, r3, 0x38
    addi r23, r23, 0x80
    addi r20, r20, 0x1
    stfsx f0, r4, r3
L_000008D8:
    lwz r3, 0x0(r22)
    addis r3, r3, 0x1
    lhz r0, -0x110(r3)
    cmpw r20, r0
    blt L_000004B8
    lis r4, lbl_13_bss_0@ha
    lis r3, lbl_13_bss_4@ha
    addi r6, r4, lbl_13_bss_0@l
    li r5, 0xe
    addi r4, r3, lbl_13_bss_4@l
    lwz r3, 0x0(r6)
    bl fn_1_F453C
    lwz r5, 0x0(r22)
    lis r4, lbl_13_bss_4@ha
    addi r20, r4, lbl_13_bss_4@l
    li r16, 0x0
    lis r4, lbl_13_bss_0@ha
    sth r3, 0xa0(r5)
    mr r15, r16
    mr r19, r20
    mr r23, r20
    mr r18, r20
    mr r17, r20
    addi r21, r4, lbl_13_bss_0@l
    b L_00000A08
L_0000093C:
    lwz r3, 0x0(r21)
    mr r4, r20
    li r5, 0x8
    bl fn_1_F453C
    lwz r5, 0x0(r22)
    addi r0, r15, 0xa4
    mr r4, r20
    stbx r3, r5, r0
    li r5, 0x8
    lwz r3, 0x0(r21)
    bl fn_1_F453C
    lwz r5, 0x0(r22)
    addi r0, r15, 0xa7
    mr r4, r20
    stbx r3, r5, r0
    li r5, 0x7
    lwz r3, 0x0(r21)
    bl fn_1_F453C
    lwz r5, 0x0(r22)
    addi r0, r15, 0xa8
    mr r4, r19
    stbx r3, r5, r0
    li r5, 0x7
    lwz r3, 0x0(r21)
    bl fn_1_F453C
    lwz r5, 0x0(r22)
    addi r0, r15, 0xa9
    mr r4, r23
    stbx r3, r5, r0
    li r5, 0x8
    lwz r3, 0x0(r21)
    bl fn_1_F453C
    lwz r5, 0x0(r22)
    addi r0, r15, 0xaa
    mr r4, r18
    stbx r3, r5, r0
    li r5, 0x8
    lwz r3, 0x0(r21)
    bl fn_1_F453C
    lwz r5, 0x0(r22)
    addi r0, r15, 0xa5
    mr r4, r17
    stbx r3, r5, r0
    li r5, 0x8
    lwz r3, 0x0(r21)
    bl fn_1_F453C
    lwz r4, 0x0(r22)
    addi r0, r15, 0xa6
    addi r16, r16, 0x1
    addi r15, r15, 0x7
    stbx r3, r4, r0
L_00000A08:
    lwz r3, 0x0(r22)
    lhz r3, 0xa0(r3)
    cmpw r16, r3
    ble L_0000093C
    bl fn_1_F4794
    lwz r3, 0x0(r22)
    li r0, 0x0
    sth r0, 0xa0(r3)
    addi r11, r1, 0x1590
    bl _restgpr_15
    lwz r0, 0x1594(r1)
    mtlr r0
    addi r1, r1, 0x1590
    blr
}

int fn_13_A40(void) {
    return 0;
}

asm void fn_13_A48(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    bl fn_1_D0790
    lwz r0, 0x14(r1)
    li r3, 0x0
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_13_A6C(void)
{
    nofralloc
    lis r4, fn_13_A40@ha
    lis r5, fn_13_A48@ha
    addi r0, r4, fn_13_A40@l
    stw r0, 0xcc(r3)
    addi r5, r5, fn_13_A48@l
    lis r4, lbl_13_bss_38@ha
    li r0, 0x0
    stw r5, 0xac(r3)
    stw r0, lbl_13_bss_38@l(r4)
    blr
}

asm void _prolog(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    lis r9, fn_13_AFC@ha
    lis r7, fn_13_B00@ha
    stw r0, 0x14(r1)
    lis r5, fn_13_B08@ha
    lis r8, lbl_1_bss_7167C@ha
    addi r9, r9, fn_13_AFC@l
    lis r6, lbl_1_bss_71680@ha
    addi r7, r7, fn_13_B00@l
    lis r4, lbl_1_bss_71684@ha
    addi r5, r5, fn_13_B08@l
    lis r3, lbl_1_bss_96A@ha
    li r0, 0xa7
    stw r9, lbl_1_bss_7167C@l(r8)
    stw r7, lbl_1_bss_71680@l(r6)
    stw r5, lbl_1_bss_71684@l(r4)
    sth r0, lbl_1_bss_96A@l(r3)
    bl fn_1_A8F78
    lis r3, lbl_13_bss_3C@ha
    li r0, 0x0
    stb r0, lbl_13_bss_3C@l(r3)
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

void fn_13_AFC(void) {}

void fn_13_B00(void) {}

asm void _epilog(void)
{
    nofralloc
    blr
}

asm void fn_13_B08(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    lis r6, lbl_13_data_18@ha
    lis r3, lbl_1_bss_962@ha
    stw r0, 0x14(r1)
    addi r6, r6, lbl_13_data_18@l
    lis r4, lbl_1_bss_71688@ha
    lha r5, lbl_1_bss_962@l(r3)
    lis r3, lbl_1_bss_7168C@ha
    subi r0, r5, 0xa7
    slwi r0, r0, 4
    add r6, r6, r0
    lwz r5, 0x8(r6)
    lwz r0, 0xc(r6)
    lwz r12, 0x4(r6)
    stw r5, lbl_1_bss_71688@l(r4)
    stw r0, lbl_1_bss_7168C@l(r3)
    mtctr r12
    bctrl
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_13_B64(void)
{
    nofralloc
    lis r4, fn_13_3FC@ha
    lis r3, lbl_1_bss_26C60@ha
    addi r0, r4, fn_13_3FC@l
    stw r0, lbl_1_bss_26C60@l(r3)
    blr
}

void fn_13_B78(void) {}

asm void fn_13_B7C(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r0, 0x14(r1)
    bl fn_1_3F038
    cmpwi r3, 0x0
    beq L_00000BBC
    lis r5, lbl_13_bss_3C@ha
    lis r4, lbl_1_bss_96A@ha
    addi r6, r5, lbl_13_bss_3C@l
    li r7, 0x1
    li r5, 0xa9
    lis r3, lbl_13_bss_40@ha
    li r0, 0xa7
    stb r7, 0x0(r6)
    sth r5, lbl_1_bss_96A@l(r4)
    stw r0, lbl_13_bss_40@l(r3)
L_00000BBC:
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_13_BCC(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    lis r3, lbl_13_data_48@ha
    lis r4, g_currentHeapHandle@ha
    stw r0, 0x24(r1)
    lis r6, lbl_13_bss_0@ha
    addi r5, r3, lbl_13_data_48@l
    stw r31, 0x1c(r1)
    addi r31, r6, lbl_13_bss_0@l
    li r6, 0x244
    lwz r3, g_currentHeapHandle@l(r4)
    li r4, 0x173c
    bl fn_1_45D0
    stw r3, 0x44(r31)
    li r4, 0x80
    bl fn_1_3CF0
    bl fn_1_A8F78
    lbz r0, 0x3c(r31)
    cmplwi r0, 0x0
    beq L_00000C34
    lis r4, lbl_13_rodata_C@ha
    addi r3, r1, 0xc
    lwz r0, lbl_13_rodata_C@l(r4)
    stw r0, 0xc(r1)
    bl fn_1_49F0
    b L_00000C48
L_00000C34:
    lis r4, lbl_13_rodata_10@ha
    addi r3, r1, 0x8
    lwz r0, lbl_13_rodata_10@l(r4)
    stw r0, 0x8(r1)
    bl fn_1_49F0
L_00000C48:
    lwz r5, 0x44(r31)
    li r3, 0x1
    li r4, 0x1e
    bl fn_1_4A00
    lis r3, lbl_1_bss_970@ha
    li r0, 0x4b0
    addi r4, r3, lbl_1_bss_970@l
    lwz r3, 0x44(r31)
    stw r0, 0x0(r4)
    bl fn_1_154708
    li r3, 0x0
    bl fn_1_154CC4
    li r3, 0x1
    bl fn_1_411A4
    lis r3, lbl_1_bss_960@ha
    addi r3, r3, lbl_1_bss_960@l
    lha r3, 0x0(r3)
    bl fn_1_479F0
    bl fn_1_A0680
    lis r3, lbl_1_bss_6EAD0@ha
    li r4, 0x2e
    addi r3, r3, lbl_1_bss_6EAD0@l
    lwz r3, 0x0(r3)
    lwz r3, 0x0(r3)
    bl fn_1_A1588
    li r0, 0xf
    li r3, 0x2
    stb r0, 0x48(r31)
    bl fn_1_48418
    li r3, 0x2
    li r4, 0x0
    bl fn_1_159440
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_13_CDC(void)
{
    nofralloc
    stwu r1, -0x70(r1)
    mflr r0
    lis r3, lbl_13_rodata_0@ha
    lis r4, lbl_13_bss_0@ha
    stw r0, 0x74(r1)
    stw r31, 0x6c(r1)
    addi r31, r4, lbl_13_bss_0@l
    stw r30, 0x68(r1)
    addi r30, r3, lbl_13_rodata_0@l
    li r3, 0x0
    bl fn_1_133DBC
    bl fn_1_134AD4
    lis r3, lbl_1_rodata_26F8@ha
    li r0, 0xb
    addi r3, r3, lbl_1_rodata_26F8@l
    addi r5, r1, 0xc
    subi r4, r3, 0x4
    mtctr r0
L_00000D24:
    lwz r3, 0x4(r4)
    lwzu r0, 0x8(r4)
    stw r3, 0x4(r5)
    stwu r0, 0x8(r5)
    bdnz L_00000D24
    lfs f2, 0x0(r30)
    lis r3, 0x1
    lfs f1, 0x4(r30)
    subi r3, r3, 0x69fc
    lfs f0, 0x8(r30)
    li r0, 0xa
    stw r3, 0x10(r1)
    addi r3, r1, 0x10
    stfs f2, 0x14(r1)
    stfs f1, 0x18(r1)
    stfs f0, 0x1c(r1)
    stw r0, 0x40(r1)
    bl fn_1_4F734
    lis r4, gLanguageIndexTable@ha
    lis r3, lbl_13_data_98@ha
    lwz r0, gLanguageIndexTable@l(r4)
    addi r3, r3, lbl_13_data_98@l
    slwi r0, r0, 2
    lwzx r3, r3, r0
    bl fn_1_1380F0
    lis r3, 0x2800
    bl fn_1_13ABA8
    lwz r3, 0x44(r31)
    bl fn_1_435C
    bl fn_1_407C
    bl fn_1_154C84
    cmpwi r3, 0x0
    bne L_00000E74
    bl fn_1_154E24
    clrlwi. r0, r3, 24
    beq L_00000E00
    lwz r0, 0x14(r30)
    addi r3, r1, 0xc
    stw r0, 0xc(r1)
    bl fn_1_49F0
    lwz r5, 0x44(r31)
    li r3, 0x0
    li r4, 0xf
    bl fn_1_4A00
    lis r3, lbl_1_bss_6EAB4@ha
    lwzu r0, lbl_1_bss_6EAB4@l(r3)
    ori r0, r0, 0x24
    stw r0, 0x0(r3)
    bl fn_1_4C10
    cmpwi r3, 0x0
    bne L_00000E64
    lis r3, lbl_1_bss_968@ha
    li r0, 0x1
    sth r0, lbl_1_bss_968@l(r3)
    b L_00000E64
L_00000E00:
    lbz r3, 0x48(r31)
    cmpwi r3, 0xf
    bne L_00000E3C
    lwz r0, 0x18(r30)
    addi r3, r1, 0x8
    stw r0, 0x8(r1)
    bl fn_1_49F0
    lwz r5, 0x44(r31)
    li r3, 0x0
    li r4, 0xf
    bl fn_1_4A00
    lbz r3, 0x48(r31)
    subi r0, r3, 0x1
    stb r0, 0x48(r31)
    b L_00000E64
L_00000E3C:
    extsb. r0, r3
    ble L_00000E50
    subi r0, r3, 0x1
    stb r0, 0x48(r31)
    b L_00000E74
L_00000E50:
    li r0, 0xa8
    lis r3, lbl_1_bss_96A@ha
    li r4, 0xa9
    stw r0, 0x40(r31)
    sth r4, lbl_1_bss_96A@l(r3)
L_00000E64:
    bl fn_1_3CC4
    lwz r3, 0x44(r31)
    bl fn_1_435C
    bl fn_1_407C
L_00000E74:
    lwz r0, 0x74(r1)
    lwz r31, 0x6c(r1)
    lwz r30, 0x68(r1)
    mtlr r0
    addi r1, r1, 0x70
    blr
}

asm void fn_13_E8C(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    li r3, 0x2
    stw r0, 0x14(r1)
    bl fn_1_1596DC
    li r3, 0x2
    bl fn_1_484CC
    bl fn_1_A0AA4
    lis r3, lbl_1_bss_960@ha
    addi r3, r3, lbl_1_bss_960@l
    lha r3, 0x0(r3)
    bl fn_1_47A60
    li r3, 0x1
    bl fn_1_412A0
    lis r3, lbl_801A63D0@ha
    addi r3, r3, lbl_801A63D0@l
    lwz r3, 0x0(r3)
    bl fn_1_154D84
    lis r4, lbl_13_bss_4C@ha
    stw r3, lbl_13_bss_4C@l(r4)
    bl fn_1_1547FC
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

asm void fn_13_EF0(void)
{
    nofralloc
    lis r3, lbl_13_bss_50@ha
    li r0, 0x3
    stw r0, lbl_13_bss_50@l(r3)
    blr
}

asm void fn_13_F00(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    lis r3, lbl_13_bss_0@ha
    stw r0, 0x14(r1)
    stw r31, 0xc(r1)
    addi r31, r3, lbl_13_bss_0@l
    lwz r3, 0x50(r31)
    subi r0, r3, 0x1
    cmpwi r3, 0x0
    stw r0, 0x50(r31)
    bgt L_00000F94
    lis r3, lbl_1_bss_968@ha
    lha r0, lbl_1_bss_968@l(r3)
    cmpwi r0, 0x1
    beq L_00000F4C
    lwz r0, 0x40(r31)
    cmpwi r0, 0xa7
    beq L_00000F4C
    bl fn_13_0
L_00000F4C:
    lwz r3, 0x44(r31)
    cmplwi r3, 0x0
    beq L_00000F88
    bl fn_1_435C
    bl fn_1_41A8
    lis r4, g_currentHeapHandle@ha
    lis r3, lbl_13_data_48@ha
    addi r6, r4, g_currentHeapHandle@l
    lwz r4, 0x44(r31)
    addi r5, r3, lbl_13_data_48@l
    lwz r3, 0x0(r6)
    li r6, 0x2c9
    bl fn_1_46B4
    li r0, 0x0
    stw r0, 0x44(r31)
L_00000F88:
    lwz r0, 0x40(r31)
    lis r3, lbl_1_bss_96A@ha
    sth r0, lbl_1_bss_96A@l(r3)
L_00000F94:
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}

void fn_13_FA8(void) {}

