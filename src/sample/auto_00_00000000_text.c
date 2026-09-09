extern void _savegpr_26(void);
extern void OSGetTick(void);
extern void memset(void);
extern void DVDOpen(void);
extern void OSAllocFromArenaLo(void);
extern void dvd_read_sync_wait(void);
extern void DVDCancelSync(void);
extern void OSGetArenaLo(void);
extern void fn_18_40C(void);
extern void OSSetArenaLo(void);
extern void OSInitArenaPoll(void);
extern void fn_8000E334(void);
extern void _restgpr_26(void);
extern void fn_18_444(void);
extern void _savegpr_24(void);
extern void _restgpr_24(void);

extern unsigned char lbl_18_section4_0[];

int fn_18_3FC(int a, int b, int c, int d);


asm void _prolog(void)
{
    nofralloc
    stwu r1, -0xe0(r1)
    mflr r0
    stw r0, 0xe4(r1)
    addi r11, r1, 0xe0
    bl _savegpr_26
    lis r6, lbl_18_section4_0@ha
    lis r3, 0x2
    lis r5, 0x31
    li r4, 0x2559
    addi r26, r6, lbl_18_section4_0@l
    subi r3, r3, 0x333b
    addi r6, r5, 0x1149
    li r5, 0x144
    bl fn_18_3FC
    mr r29, r3
    bl OSGetTick
    subi r0, r29, 0x1
    lis r4, 0x1
    and r5, r0, r3
    lis r3, 0x2ca
    addi r0, r5, 0x1
    lis r5, 0x68
    mullw r30, r29, r0
    subi r3, r3, 0x1d92
    subi r4, r4, 0x3226
    addi r6, r5, 0x432a
    li r5, 0x611b
    bl fn_18_3FC
    addi r0, r1, 0x47
    neg r31, r3
    clrrwi r28, r0, 2
    li r4, 0x62
    mr r3, r28
    li r5, 0x28
    bl memset
    lwz r0, 0x0(r26)
    xori r0, r0, 0x2d2e
    stwbrx r0, r0, r28
    subis r4, r31, 0x461d
    addi r4, r4, 0x4ebb
    li r0, 0x4
    lbz r3, 0x2(r28)
    addi r3, r3, 0x10
    stb r3, 0x2(r28)
    lbz r3, 0x3(r28)
    addi r3, r3, 0x27
    stb r3, 0x3(r28)
    stwbrx r4, r28, r0
    extrwi r3, r4, 8, 16
    li r0, 0xa
    stb r3, 0xf(r28)
    stb r3, 0x10(r28)
    lbz r3, 0x6(r28)
    stb r3, 0xb(r28)
    lbz r3, 0x7(r28)
    stb r3, 0xc(r28)
    lhbrx r5, r28, r0
    mr r3, r28
    addi r4, r1, 0x8
    addi r5, r5, 0x203
    sth r5, 0x8(r28)
    extrwi r0, r5, 8, 16
    stb r5, 0xe(r28)
    stb r0, 0xd(r28)
    lbz r5, 0xa(r28)
    subi r0, r5, 0x33
    stb r0, 0xa(r28)
    lbz r5, 0x11(r28)
    subi r0, r5, 0x34
    stb r0, 0x11(r28)
    lbz r5, 0x14(r28)
    addi r0, r5, 0xc
    stb r0, 0x14(r28)
    lwz r0, 0x14(r28)
    xoris r0, r0, 0x62
    xori r0, r0, 0xa782
    stw r0, 0x14(r28)
    lbz r0, 0x13(r28)
    xori r0, r0, 0xb
    stb r0, 0x13(r28)
    bl DVDOpen
    mr r3, r28
    li r4, 0x0
    li r5, 0x32
    bl memset
    lwz r0, 0x3c(r1)
    subi r3, r29, 0x1
    mr r4, r29
    add r0, r0, r3
    andc r26, r0, r3
    mr r3, r26
    bl OSAllocFromArenaLo
    mr r28, r3
    mr r5, r26
    addi r3, r1, 0x8
    li r6, 0x0
    mr r4, r28
    bl dvd_read_sync_wait
    addi r3, r1, 0x8
    bl DVDCancelSync
    srwi r8, r26, 2
    li r9, 0x0
    cmplwi r8, 0x0
    ble L_00000390
    cmplwi r8, 0x8
    subi r6, r8, 0x8
    ble L_0000032C
    addi r3, r6, 0x7
    lis r5, 0x9b37
    lis r4, 0xd
    mr r7, r28
    srwi r3, r3, 3
    subi r5, r5, 0x446c
    subi r0, r4, 0x270d
    mtctr r3
    cmplwi r6, 0x0
    ble L_0000032C
    L_000001D4:
    mullw r10, r31, r5
    li r4, 0x180a
    lwz r3, 0x0(r7)
    li r6, 0x0
    addi r9, r9, 0x8
    addc r29, r10, r0
    xor r3, r3, r29
    stw r3, 0x0(r7)
    mulhwu r12, r31, r5
    lwz r10, 0x4(r7)
    mullw r3, r6, r5
    mulhwu r11, r29, r5
    add r26, r12, r3
    mullw r27, r31, r4
    add r12, r11, r3
    add r26, r26, r27
    mullw r11, r29, r4
    adde r27, r26, r6
    mullw r27, r29, r5
    add r12, r12, r11
    addc r29, r27, r0
    adde r12, r12, r6
    mullw r12, r29, r5
    xor r10, r10, r29
    stw r10, 0x4(r7)
    lwz r10, 0x8(r7)
    addc r31, r12, r0
    mulhwu r11, r29, r5
    xor r10, r10, r31
    stw r10, 0x8(r7)
    lwz r10, 0xc(r7)
    mullw r12, r29, r4
    add r27, r11, r3
    add r12, r27, r12
    adde r12, r12, r6
    mullw r12, r31, r5
    addc r29, r12, r0
    mulhwu r11, r31, r5
    xor r10, r10, r29
    stw r10, 0xc(r7)
    lwz r10, 0x10(r7)
    mullw r12, r31, r4
    add r27, r11, r3
    add r12, r27, r12
    adde r12, r12, r6
    mullw r12, r29, r5
    addc r31, r12, r0
    mulhwu r11, r29, r5
    xor r10, r10, r31
    stw r10, 0x10(r7)
    lwz r10, 0x14(r7)
    mullw r12, r29, r4
    add r27, r11, r3
    add r12, r27, r12
    adde r12, r12, r6
    mullw r12, r31, r5
    addc r27, r12, r0
    mulhwu r11, r31, r5
    xor r10, r10, r27
    stw r10, 0x14(r7)
    lwz r10, 0x18(r7)
    mullw r12, r31, r4
    add r29, r11, r3
    add r12, r29, r12
    adde r12, r12, r6
    mullw r12, r27, r5
    addc r29, r12, r0
    mulhwu r11, r27, r5
    xor r10, r10, r29
    stw r10, 0x18(r7)
    lwz r10, 0x1c(r7)
    mullw r12, r27, r4
    add r31, r11, r3
    add r12, r31, r12
    mulhwu r11, r29, r5
    adde r12, r12, r6
    mullw r12, r29, r5
    add r11, r11, r3
    addc r31, r12, r0
    xor r3, r10, r31
    stw r3, 0x1c(r7)
    mullw r4, r29, r4
    addi r7, r7, 0x20
    add r3, r11, r4
    adde r3, r3, r6
    bdnz L_000001D4
    L_0000032C:
    lis r3, 0x9b37
    slwi r4, r9, 2
    subi r11, r3, 0x446c
    li r12, 0x0
    mullw r6, r12, r11
    lis r3, 0xd
    subf r0, r9, r8
    add r26, r28, r4
    subi r3, r3, 0x270d
    li r10, 0x180a
    mtctr r0
    cmplw r9, r8
    bge L_00000390
    L_00000360:
    mulhwu r4, r31, r11
    lwz r0, 0x0(r26)
    mullw r7, r31, r11
    add r5, r4, r6
    mullw r4, r31, r10
    addc r31, r7, r3
    xor r0, r0, r31
    stw r0, 0x0(r26)
    addi r26, r26, 0x4
    add r0, r5, r4
    adde r0, r0, r12
    bdnz L_00000360
    L_00000390:
    bl OSGetArenaLo
    add r27, r30, r3
    mr r3, r28
    mr r4, r27
    bl fn_18_40C
    lwz r4, 0x48(r27)
    mr r3, r27
    lwz r0, 0x20(r27)
    add r4, r27, r4
    addi r4, r4, 0x1f
    clrrwi r26, r4, 5
    add r0, r26, r0
    subf r27, r27, r0
    bl OSSetArenaLo
    mr r3, r27
    li r4, 0x20
    bl OSInitArenaPoll
    mr r28, r3
    mr r4, r26
    bl fn_8000E334
    lwz r3, 0x34(r28)
    addi r11, r1, 0xe0
    bl _restgpr_26
    lwz r0, 0xe4(r1)
    mtlr r0
    addi r1, r1, 0xe0
    blr
}

int fn_18_3FC(int a, int b, int c, int d) {
    return a + (c * b - d);
}


asm void fn_18_40C(void)
{
    nofralloc
    stwu r1, -0x20(r1)
    mflr r0
    stw r0, 0x24(r1)
    li r0, 0x0
    stw r3, 0x8(r1)
    addi r3, r1, 0x8
    stw r4, 0xc(r1)
    stw r0, 0x10(r1)
    bl fn_18_444
    lwz r0, 0x24(r1)
    lwz r3, 0x0(r3)
    mtlr r0
    addi r1, r1, 0x20
    blr
}

asm void fn_18_444(void)
{
    nofralloc
    stwu r1, -0x1040(r1)
    mflr r0
    stw r0, 0x1044(r1)
    addi r11, r1, 0x1040
    bl _savegpr_24
    lwz r10, 0x0(r3)
    lwz r12, 0x8(r3)
    lwz r4, 0x4(r3)
    lwbrx r3, r0, r10
    li r0, 0x4
    addic. r9, r3, 0x8
    lwbrx r0, r10, r0
    stw r0, 0x8(r1)
    beq L_00000484
    cmplwi r0, 0x0
    bne L_0000048C
    L_00000484:
    li r3, 0x0
    b L_00000718
    L_0000048C:
    li r5, 0x0
    mr r7, r4
    cmpwi r5, 0xfee
    addi r6, r10, 0x8
    bge L_00000504
    li r0, 0x1fd
    addi r4, r1, 0xc
    li r3, 0x0
    mtctr r0
    L_000004B0:
    stb r3, 0x0(r4)
    addi r5, r5, 0x8
    stb r3, 0x1(r4)
    stb r3, 0x2(r4)
    stb r3, 0x3(r4)
    stb r3, 0x4(r4)
    stb r3, 0x5(r4)
    stb r3, 0x6(r4)
    stb r3, 0x7(r4)
    addi r4, r4, 0x8
    bdnz L_000004B0
    addi r4, r1, 0xc
    subfic r0, r5, 0xfee
    add r4, r4, r5
    li r3, 0x0
    mtctr r0
    cmpwi r5, 0xfee
    bge L_00000504
    L_000004F8:
    stb r3, 0x0(r4)
    addi r4, r4, 0x1
    bdnz L_000004F8
    L_00000504:
    li r5, 0xfee
    li r8, 0x0
    L_0000050C:
    srwi r8, r8, 1
    rlwinm. r0, r8, 0, 23, 23
    bne L_00000530
    subf r0, r10, r6
    cmplw r0, r9
    bge L_00000700
    lbz r0, 0x0(r6)
    addi r6, r6, 0x1
    ori r8, r0, 0xff00
    L_00000530:
    clrlwi. r0, r8, 31
    beq L_00000568
    subf r0, r10, r6
    cmplw r0, r9
    bge L_00000700
    lbz r0, 0x0(r6)
    addi r3, r1, 0xc
    addi r6, r6, 0x1
    stb r0, 0x0(r7)
    addi r7, r7, 0x1
    stbx r0, r3, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    b L_0000050C
    L_00000568:
    subf r0, r10, r6
    cmplw r0, r9
    bge L_00000700
    addi r3, r6, 0x1
    lbz r0, 0x0(r6)
    subf r3, r10, r3
    cmplw r3, r9
    bge L_00000700
    lbz r11, 0x1(r6)
    li r4, 0x0
    addi r6, r6, 0x2
    clrlwi r3, r11, 28
    rlwinm r11, r11, 4, 20, 23
    addic. r3, r3, 0x2
    or r0, r0, r11
    blt L_0000050C
    addi r11, r3, 0x1
    subi r25, r3, 0x8
    cmpwi r11, 0x8
    ble L_000006BC
    addi r11, r25, 0x8
    addi r26, r1, 0xc
    srwi r11, r11, 3
    mtctr r11
    cmpwi r25, 0x0
    blt L_000006BC
    L_000005D0:
    add r25, r0, r4
    addi r4, r4, 0x8
    clrlwi r11, r25, 20
    lbzx r30, r26, r11
    addi r11, r25, 0x1
    addi r27, r25, 0x2
    addi r28, r25, 0x3
    stbx r30, r26, r5
    clrlwi r11, r11, 20
    addi r5, r5, 0x1
    addi r29, r25, 0x4
    lbzx r24, r26, r11
    clrlwi r5, r5, 20
    stb r30, 0x0(r7)
    addi r30, r25, 0x5
    addi r31, r25, 0x6
    addi r11, r25, 0x7
    stbx r24, r26, r5
    clrlwi r27, r27, 20
    addi r5, r5, 0x1
    clrlwi r28, r28, 20
    lbzx r25, r26, r27
    clrlwi r5, r5, 20
    stb r24, 0x1(r7)
    clrlwi r29, r29, 20
    clrlwi r30, r30, 20
    clrlwi r31, r31, 20
    stbx r25, r26, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    clrlwi r11, r11, 20
    lbzx r27, r26, r28
    stb r25, 0x2(r7)
    stbx r27, r26, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    lbzx r25, r26, r29
    stb r27, 0x3(r7)
    stbx r25, r26, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    lbzx r27, r26, r30
    stb r25, 0x4(r7)
    stbx r27, r26, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    lbzx r25, r26, r31
    stb r27, 0x5(r7)
    stbx r25, r26, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    lbzx r11, r26, r11
    stb r25, 0x6(r7)
    stb r11, 0x7(r7)
    addi r7, r7, 0x8
    stbx r11, r26, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    bdnz L_000005D0
    L_000006BC:
    addi r11, r3, 0x1
    addi r31, r1, 0xc
    subf r11, r4, r11
    mtctr r11
    cmpw r4, r3
    bgt L_0000050C
    L_000006D4:
    add r3, r0, r4
    addi r4, r4, 0x1
    clrlwi r3, r3, 20
    lbzx r3, r31, r3
    stb r3, 0x0(r7)
    addi r7, r7, 0x1
    stbx r3, r31, r5
    addi r5, r5, 0x1
    clrlwi r5, r5, 20
    bdnz L_000006D4
    b L_0000050C
    L_00000700:
    cmplwi r12, 0x0
    beq L_00000714
    lwz r3, 0x8(r1)
    mtctr r12
    bctrl
    L_00000714:
    addi r3, r1, 0x8
    L_00000718:
    addi r11, r1, 0x1040
    bl _restgpr_24
    lwz r0, 0x1044(r1)
    mtlr r0
    addi r1, r1, 0x1040
    blr
}
