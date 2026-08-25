typedef signed int s32;
typedef unsigned int u32;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);
extern void OSReport(const char*, ...);
extern void OSPanic(void);
extern void* fn_8001A814(register s32 mode);
extern unsigned char lbl_801241C8[500];
extern unsigned char lbl_8015CF68[240];

/* VI mode-config glue between vi_8001A8B4 and viretrace: pan/word-conversion
   helpers over the game's callback state at 0x8016CF68 (-0x3098 from the
   0x8016_0000 base). */

#pragma push
#pragma force_active on

extern unsigned char lbl_801A693C[4];
extern unsigned char lbl_801A6944[4];
extern unsigned char lbl_801A6948[4];
extern unsigned char lbl_801A694C[4];
extern unsigned char lbl_801A6970[4];
extern unsigned char lbl_801A6974[4];
asm void fn_8001AFB8(register void* a, register void* b, register void* c, register void* d, register void* e)
{
    nofralloc
    stwu r1, -0x48(r1)
    lis     r9, lbl_8015CF68@ha
    addi r9, r9, lbl_8015CF68@l
    stw r31, 0x44(r1)
    lbz r8, 0x2c(r3)
    lhz r0, 0xe(r3)
    slwi r31, r8, 5
    lhz r8, 0x16(r3)
    mullw r0, r31, r0
    lwz r11, 0x20(r3)
    lwz r10, 0x30(r3)
    lhz r12, 0xa(r3)
    rlwinm r8, r8, 1, 0, 0x1a
    add r0, r8, r0
    add r0, r10, r0
    cmpwi r11, 0
    stw r0, 0(r4)
    bne _8001b008
    lwz r8, 0(r4)
    b _8001b010
_8001b008:
    lwz r0, 0(r4)
    add r8, r0, r31
_8001b010:
    srawi r0, r12, 1
    stw r8, 0(r5)
    addze r0, r0
    slwi r0, r0, 1
    subfc r0, r0, r12
    cmpwi r0, 1
    bne _8001b03c
    lwz r8, 0(r4)
    lwz r0, 0(r5)
    stw r0, 0(r4)
    stw r8, 0(r5)
_8001b03c:
    lwz r0, 0(r4)
    clrlwi r0, r0, 2
    stw r0, 0(r4)
    lwz r0, 0(r5)
    clrlwi r0, r0, 2
    stw r0, 0(r5)
    lwz r0, 0x44(r3)
    cmpwi r0, 0
    beq _8001b0ec
    lbz r8, 0x2c(r3)
    lhz r0, 0xe(r3)
    slwi r31, r8, 5
    lhz r8, 0x16(r3)
    mullw r0, r31, r0
    lwz r11, 0x20(r3)
    lwz r10, 0x48(r3)
    lhz r12, 0xa(r3)
    rlwinm r8, r8, 1, 0, 0x1a
    add r0, r8, r0
    add r0, r10, r0
    cmpwi r11, 0
    stw r0, 0(r6)
    bne _8001b0a0
    lwz r8, 0(r6)
    b _8001b0a8
_8001b0a0:
    lwz r0, 0(r6)
    add r8, r0, r31
_8001b0a8:
    srawi r0, r12, 1
    stw r8, 0(r7)
    addze r0, r0
    slwi r0, r0, 1
    subfc r0, r0, r12
    cmpwi r0, 1
    bne _8001b0d4
    lwz r8, 0(r6)
    lwz r0, 0(r7)
    stw r0, 0(r6)
    stw r8, 0(r7)
_8001b0d4:
    lwz r0, 0(r6)
    clrlwi r0, r0, 2
    stw r0, 0(r6)
    lwz r0, 0(r7)
    clrlwi r0, r0, 2
    stw r0, 0(r7)
_8001b0ec:
    lwz r0, 0(r4)
    lis r8, 0x100
    cmplw r0, r8
    bge _8001b128
    lwz r0, 0(r5)
    cmplw r0, r8
    bge _8001b128
    lwz r0, 0(r6)
    cmplw r0, r8
    bge _8001b128
    lwz r0, 0(r7)
    cmplw r0, r8
    bge _8001b128
    li r10, 0
    b _8001b12c
_8001b128:
    li r10, 1
_8001b12c:
    cmplwi r10, 0
    beq _8001b164
    lwz r0, 0(r4)
    srwi r0, r0, 5
    stw r0, 0(r4)
    lwz r0, 0(r5)
    srwi r0, r0, 5
    stw r0, 0(r5)
    lwz r0, 0(r6)
    srwi r0, r0, 5
    stw r0, 0(r6)
    lwz r0, 0(r7)
    srwi r0, r0, 5
    stw r0, 0(r7)
_8001b164:
    lwz r0, 0(r4)
    slwi r11, r10, 0xc
    lis r8, 1
    sth r0, 0x1e(r9)
    lis r0, 2
    lwz	r10, lbl_801A6948
    lwz	r12, lbl_801A694C
    or r10, r10, r8
    stw	r12, lbl_801A694C
    stw	r10, lbl_801A6948
    lwz r10, 0(r4)
    lbz r4, 0x3c(r3)
    srwi r10, r10, 0x10
    slwi r4, r4, 8
    or r4, r10, r4
    or r4, r11, r4
    sth r4, 0x1c(r9)
    lwz	r4, lbl_801A6948
    lwz	r10, lbl_801A694C
    or r0, r4, r0
    stw	r10, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r0, 0(r5)
    sth r0, 0x26(r9)
    lwz	r0, lbl_801A6948
    lwz	r4, lbl_801A694C
    ori r0, r0, 0x1000
    stw	r4, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r0, 0(r5)
    srwi r0, r0, 0x10
    sth r0, 0x24(r9)
    lwz	r0, lbl_801A6948
    lwz	r4, lbl_801A694C
    ori r0, r0, 0x2000
    stw	r4, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r0, 0x44(r3)
    cmpwi r0, 0
    beq _8001b280
    lwz r3, 0(r6)
    addi r0, r8, -0x8000
    sth r3, 0x22(r9)
    lwz	r3, lbl_801A6948
    lwz	r4, lbl_801A694C
    ori r3, r3, 0x4000
    stw	r4, lbl_801A694C
    stw	r3, lbl_801A6948
    lwz r3, 0(r6)
    srwi r3, r3, 0x10
    sth r3, 0x20(r9)
    lwz	r3, lbl_801A6948
    lwz	r4, lbl_801A694C
    or r0, r3, r0
    stw	r4, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r0, 0(r7)
    sth r0, 0x2a(r9)
    lwz	r0, lbl_801A6948
    lwz	r3, lbl_801A694C
    ori r0, r0, 0x400
    stw	r3, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r0, 0(r7)
    srwi r0, r0, 0x10
    sth r0, 0x28(r9)
    lwz	r0, lbl_801A6948
    lwz	r3, lbl_801A694C
    ori r0, r0, 0x800
    stw	r3, lbl_801A694C
    stw	r0, lbl_801A6948
_8001b280:
    lwz r31, 0x44(r1)
    addi r1, r1, 0x48
    blr
}

asm void fn_8001B28C(void)
{
    nofralloc
    stwu r1, -0x28(r1)
    lis     r11, lbl_8015CF68@ha
    addi r11, r11, lbl_8015CF68@l
    stw r31, 0x24(r1)
    lwz r31, 0x30(r1)
    stw r30, 0x20(r1)
    stw r29, 0x1c(r1)
    lhz r0, 0x6c(r11)
    clrlwi. r0, r0, 0x1f
    beq _8001b2c0
    li r12, 1
    li r29, 2
    b _8001b2c8
_8001b2c0:
    li r12, 2
    li r29, 1
_8001b2c8:
    clrlwi r30, r3, 0x10
    srawi r0, r30, 1
    addze r0, r0
    slwi r0, r0, 1
    subfc. r0, r0, r30
    bne _8001b318
    clrlwi r3, r12, 0x10
    clrlwi r0, r6, 0x10
    mullw r0, r3, r0
    clrlwi r3, r4, 0x10
    subf r0, r3, r0
    clrlwi r3, r29, 0x10
    mullw r29, r3, r30
    subf r0, r30, r0
    mullw r30, r3, r0
    add r0, r7, r29
    add r6, r9, r30
    add r3, r8, r29
    add r7, r10, r30
    b _8001b34c
_8001b318:
    clrlwi r3, r12, 0x10
    clrlwi r0, r6, 0x10
    mullw r0, r3, r0
    clrlwi r3, r4, 0x10
    subf r0, r3, r0
    clrlwi r3, r29, 0x10
    mullw r29, r3, r30
    subf r0, r30, r0
    mullw r30, r3, r0
    add r0, r8, r29
    add r6, r10, r30
    add r3, r7, r29
    add r7, r9, r30
_8001b34c:
    clrlwi r8, r4, 0x10
    clrlwi r4, r12, 0x10
    divw r4, r8, r4
    cmpwi r31, 0
    clrlwi r4, r4, 0x10
    beq _8001b380
    slwi r4, r4, 1
    addi r4, r4, -2
    add r0, r0, r4
    add r3, r3, r4
    li r4, 0
    addi r6, r6, 2
    addi r7, r7, 2
_8001b380:
    clrlwi r5, r5, 0x18
    rlwinm r4, r4, 4, 0xc, 0x1b
    or r4, r5, r4
    sth r4, 0(r11)
    lis r4, -0x8000
    lis r9, 0x100
    lwz	r5, lbl_801A6948
    lis r8, 0x200
    lwz	r10, lbl_801A694C
    or r4, r5, r4
    lis r5, 0x40
    stw	r10, lbl_801A694C
    stw	r4, lbl_801A6948
    lis r4, 0x80
    sth r0, 0xe(r11)
    lwz	r0, lbl_801A6948
    lwz	r10, lbl_801A694C
    or r0, r0, r9
    stw	r10, lbl_801A694C
    stw	r0, lbl_801A6948
    sth r6, 0xc(r11)
    lwz	r0, lbl_801A6948
    lwz	r6, lbl_801A694C
    or r0, r0, r8
    stw	r6, lbl_801A694C
    stw	r0, lbl_801A6948
    sth r3, 0x12(r11)
    lwz	r0, lbl_801A6948
    lwz	r3, lbl_801A694C
    or r0, r0, r5
    stw	r3, lbl_801A694C
    stw	r0, lbl_801A6948
    sth r7, 0x10(r11)
    lwz	r0, lbl_801A6948
    lwz	r3, lbl_801A694C
    or r0, r0, r4
    stw	r3, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r31, 0x24(r1)
    lwz r30, 0x20(r1)
    lwz r29, 0x1c(r1)
    addi r1, r1, 0x28
    blr
}

asm void fn_8001B42C(register void* param)
{
    nofralloc
    mflr r0
    lis     r5, lbl_801241C8@ha
    stw r0, 4(r1)
    lis     r4, lbl_8015CF68@ha
    stwu r1, -0x78(r1)
    stmw r14, 0x30(r1)
    addi r31, r3, 0
    addi r15, r5, lbl_801241C8@l
    addi r29, r4, lbl_8015CF68@l
    bl OSDisableInterrupts
    lwz r4, 0(r31)
    addi r28, r29, 0x114
    lwz r0, 0x114(r29)
    addi r14, r3, 0
    clrlwi r4, r4, 0x1e
    cmplw r0, r4
    beq _8001b47c
    li r0, 1
    stw	r0, lbl_801A6944
    stw r4, 0(r28)
_8001b47c:
    lwz r0, 0(r31)
    lis r3, -0x8000
    lwz r16, 0xcc(r3)
    srwi r0, r0, 2
    cmplwi r0, 4
    mr r17, r0
    bne _8001b500
    lwz	r0, lbl_801A6974
    cmplwi r0, 0
    bne _8001b500
    li r0, 1
    crxor 6, 6, 6
    stw	r0, lbl_801A6974
    addi r3, r15, 0x260
    bl OSReport
    addi r3, r15, 0x28c
    crxor 6, 6, 6
    bl OSReport
    addi r3, r15, 0x2b8
    crxor 6, 6, 6
    bl OSReport
    addi r3, r15, 0x2e4
    crxor 6, 6, 6
    bl OSReport
    addi r3, r15, 0x310
    crxor 6, 6, 6
    bl OSReport
    addi r3, r15, 0x33c
    crxor 6, 6, 6
    bl OSReport
    addi r3, r15, 0x260
    crxor 6, 6, 6
    bl OSReport
_8001b500:
    cmpwi r16, 2
    beq _8001b534
    bge _8001b51c
    cmpwi r16, 0
    beq _8001b534
    bge _8001b550
    b _8001b560
_8001b51c:
    cmpwi r16, 6
    beq _8001b534
    bge _8001b560
    cmpwi r16, 5
    bge _8001b550
    b _8001b560
_8001b534:
    cmplwi r17, 0
    beq _8001b57c
    cmplwi r17, 2
    beq _8001b57c
    cmplwi r17, 6
    bne _8001b560
    b _8001b57c
_8001b550:
    cmplwi r17, 1
    beq _8001b57c
    cmplwi r17, 5
    beq _8001b57c
_8001b560:
    addi r6, r16, 0
    crxor 6, 6, 6
    addi r7, r17, 0
    addi r5, r15, 0x368
    addi r3, r13, -0x7f1c
    li r4, 0x75c
    bl OSPanic
_8001b57c:
    cmplwi r17, 0
    beq _8001b58c
    cmplwi r17, 2
    bne _8001b594
_8001b58c:
    stw r16, 0x118(r29)
    b _8001b598
_8001b594:
    stw r17, 0x118(r29)
_8001b598:
    lhz r0, 0xa(r31)
    sth r0, 0xf0(r29)
    lwz r0, 0(r28)
    cmplwi r0, 1
    bne _8001b5b8
    lhz r0, 0xc(r31)
    rlwinm r0, r0, 1, 0x10, 0x1e
    b _8001b5bc
_8001b5b8:
    lhz r0, 0xc(r31)
_8001b5bc:
    sth r0, 0xf2(r29)
    addi r23, r29, 0xf2
    addi r24, r29, 0xf4
    lhz r0, 0xe(r31)
    addi r27, r29, 0x102
    addi r25, r29, 0x110
    sth r0, 0xf4(r29)
    li r0, 0
    addi r16, r29, 0x10a
    lhz r3, 4(r31)
    addi r26, r29, 0x10c
    addi r15, r29, 0x106
    sth r3, 0x102(r29)
    addi r17, r29, 0x108
    lhz r3, 8(r31)
    sth r3, 0x104(r29)
    lwz r3, 0x14(r31)
    stw r3, 0x110(r29)
    lhz r3, 0x102(r29)
    sth r3, 0x10a(r29)
    lhz r3, 0x104(r29)
    sth r3, 0x10c(r29)
    sth r0, 0x106(r29)
    sth r0, 0x108(r29)
    lwz r0, 0(r28)
    cmplwi r0, 2
    bne _8001b630
    lhz r0, 0(r26)
    b _8001b65c
_8001b630:
    cmplwi r0, 3
    bne _8001b640
    lhz r0, 0(r26)
    b _8001b65c
_8001b640:
    lwz r0, 0(r25)
    cmpwi r0, 0
    bne _8001b658
    lhz r0, 0(r26)
    rlwinm r0, r0, 1, 0x10, 0x1e
    b _8001b65c
_8001b658:
    lhz r0, 0(r26)
_8001b65c:
    addi r22, r29, 0xf6
    sth r0, 0xf6(r29)
    lwz r0, 0(r28)
    cmplwi r0, 3
    bne _8001b678
    li r0, 1
    b _8001b67c
_8001b678:
    li r0, 0
_8001b67c:
    addi r18, r29, 0x134
    stw r0, 0x134(r29)
    addi r21, r29, 0x118
    lwz r3, 0x118(r29)
    lwz r0, 0(r28)
    slwi r3, r3, 2
    add r3, r3, r0
    bl fn_8001A814
    mr r30, r3
    stw r30, 0x144(r29)
    lhz r0, 0(r24)
    lha r4, 0xf0(r29)
    lha r3, -0x7a80(r13)
    subfic r5, r0, 0x2d0
    lhz r0, 2(r30)
    add r3, r4, r3
    cmpw r3, r5
    ble _8001b6c8
    b _8001b6d8
_8001b6c8:
    cmpwi r3, 0
    bge _8001b6d4
    li r3, 0
_8001b6d4:
    mr r5, r3
_8001b6d8:
    sth r5, 0xf8(r29)
    addi r3, r29, 0xf8
    lwz r4, 0(r25)
    cmpwi r4, 0
    bne _8001b6f4
    li r4, 2
    b _8001b6f8
_8001b6f4:
    li r4, 1
_8001b6f8:
    lhz r5, 0(r23)
    lha r6, -0x7a7e(r13)
    extsh r7, r5
    clrlwi r5, r5, 0x1f
    add r7, r7, r6
    cmpw r7, r5
    ble _8001b718
    b _8001b71c
_8001b718:
    mr r7, r5
_8001b71c:
    sth r7, 0xfa(r29)
    extsh r0, r0
    slwi r0, r0, 1
    lhz r8, 0(r22)
    subf r0, r5, r0
    lha r7, 0(r23)
    addi r19, r29, 0xfa
    extsh r9, r8
    add r10, r9, r6
    add r10, r7, r10
    subf. r9, r0, r10
    ble _8001b754
    subf r9, r0, r10
    b _8001b758
_8001b754:
    li r9, 0
_8001b758:
    add r10, r7, r6
    subf. r7, r5, r10
    bge _8001b76c
    subf r7, r5, r10
    b _8001b770
_8001b76c:
    li r7, 0
_8001b770:
    add r7, r8, r7
    subf r7, r9, r7
    addi r20, r29, 0xfc
    sth r7, 0xfc(r29)
    lha r7, 0(r23)
    add r8, r7, r6
    subf. r7, r5, r8
    bge _8001b798
    subf r7, r5, r8
    b _8001b79c
_8001b798:
    li r7, 0
_8001b79c:
    divw r8, r7, r4
    lhz r7, 0(r17)
    subf r7, r8, r7
    sth r7, 0xfe(r29)
    lha r7, 0(r22)
    lha r9, 0(r23)
    add r8, r7, r6
    add r8, r9, r8
    subf. r7, r0, r8
    ble _8001b7cc
    subf r7, r0, r8
    b _8001b7d0
_8001b7cc:
    li r7, 0
_8001b7d0:
    add r6, r9, r6
    subf. r0, r5, r6
    bge _8001b7e4
    subf r0, r5, r6
    b _8001b7e8
_8001b7e4:
    li r0, 0
_8001b7e8:
    divw r0, r0, r4
    lhz r5, 0(r26)
    divw r4, r7, r4
    add r0, r5, r0
    subf r0, r4, r0
    sth r0, 0x100(r29)
    lwz	r0, lbl_801A693C
    cmplwi r0, 0
    bne _8001b814
    li r0, 3
    stw r0, 0(r21)
_8001b814:
    lhz r5, 0x18(r30)
    srawi r4, r5, 1
    addze r4, r4
    srawi r0, r5, 1
    addze r0, r0
    slwi r0, r0, 1
    subfc r0, r0, r5
    clrlwi. r0, r0, 0x10
    clrlwi r4, r4, 0x10
    beq _8001b844
    lhz r5, 0x1a(r30)
    b _8001b848
_8001b844:
    li r5, 0
_8001b848:
    addi r0, r5, 1
    sth r0, 0x32(r29)
    addi r0, r4, 1
    ori r0, r0, 0x1000
    lwz	r5, lbl_801A6948
    addi r4, r29, 2
    lwz	r6, lbl_801A694C
    ori r5, r5, 0x40
    stw	r6, lbl_801A694C
    stw	r5, lbl_801A6948
    sth r0, 0x30(r29)
    lwz	r0, lbl_801A6948
    lwz	r5, lbl_801A694C
    ori r0, r0, 0x80
    stw	r5, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r0, 0(r28)
    lhz r5, 2(r29)
    cmplwi r0, 2
    beq _8001b8a0
    cmplwi r0, 3
    bne _8001b8ac
_8001b8a0:
    rlwinm r0, r5, 0, 0x1e, 0x1c
    ori r5, r0, 4
    b _8001b8b4
_8001b8ac:
    rlwinm r5, r5, 0, 0x1e, 0x1c
    rlwimi r5, r0, 2, 0x1d, 0x1d
_8001b8b4:
    lwz r6, 0(r21)
    rlwinm r5, r5, 0, 0x1d, 0x1b
    lwz r7, 0(r18)
    cmplwi r6, 4
    slwi r0, r7, 3
    or r5, r5, r0
    beq _8001b8dc
    addi r0, r6, -5
    cmplwi r0, 1
    bgt _8001b8e4
_8001b8dc:
    rlwinm r0, r5, 0, 0x18, 0x15
    b _8001b8f0
_8001b8e4:
    rlwinm r5, r5, 0, 0x18, 0x15
    slwi r0, r6, 8
    or r0, r5, r0
_8001b8f0:
    sth r0, 0(r4)
    lis r0, 0x4000
    addi r6, r29, 0x6c
    lwz	r4, lbl_801A6948
    lwz	r5, lbl_801A694C
    or r0, r4, r0
    stw	r5, lbl_801A694C
    stw	r0, lbl_801A6948
    lwz r0, 0(r31)
    lhz r4, 0x6c(r29)
    cmpwi r0, 2
    beq _8001b930
    cmpwi r0, 3
    beq _8001b930
    cmpwi r0, 0x1a
    bne _8001b93c
_8001b930:
    rlwinm r0, r4, 0, 0, 0x1e
    ori r0, r0, 1
    b _8001b940
_8001b93c:
    rlwinm r0, r4, 0, 0, 0x1e
_8001b940:
    sth r0, 0(r6)
    cmpwi r7, 0
    lwz	r4, lbl_801A6948
    lwz	r0, lbl_801A694C
    ori r0, r0, 0x200
    stw	r0, lbl_801A694C
    stw	r4, lbl_801A6948
    lhz r4, 0(r24)
    lhz r5, 0(r16)
    beq _8001b970
    slwi r0, r5, 1
    b _8001b974
_8001b970:
    mr r0, r5
_8001b974:
    clrlwi r8, r0, 0x10
    cmplw r8, r4
    bge _8001b9cc
    slwi r6, r8, 8
    addi r0, r6, -1
    add r0, r4, r0
    divwu r0, r0, r4
    ori r0, r0, 0x1000
    sth r0, 0x4a(r29)
    lis r0, 0x400
    lwz	r6, lbl_801A6948
    lwz	r7, lbl_801A694C
    or r0, r7, r0
    stw	r0, lbl_801A694C
    stw	r6, lbl_801A6948
    sth r8, 0x70(r29)
    lwz	r6, lbl_801A6948
    lwz	r0, lbl_801A694C
    ori r0, r0, 0x80
    stw	r0, lbl_801A694C
    stw	r6, lbl_801A6948
    b _8001b9ec
_8001b9cc:
    li r0, 0x100
    sth r0, 0x4a(r29)
    lis r0, 0x400
    lwz	r6, lbl_801A6948
    lwz	r7, lbl_801A694C
    or r0, r7, r0
    stw	r0, lbl_801A694C
    stw	r6, lbl_801A6948
_8001b9ec:
    lhz r0, 0(r3)
    subfic r12, r4, 0x2d0
    lhz r6, 0x1a(r30)
    lis r3, 0x1000
    lis r8, 0x2000
    sth r6, 6(r29)
    lis r9, 0x400
    lis r7, 0x800
    lwz	r10, lbl_801A6948
    lis r6, 0x10
    lis r4, 0x20
    lwz	r11, lbl_801A694C
    or r10, r10, r3
    lis r3, 4
    stw	r11, lbl_801A694C
    stw	r10, lbl_801A6948
    lbz r10, 0x1d(r30)
    lbz r11, 0x1e(r30)
    rlwimi r11, r10, 8, 0x10, 0x17
    sth r11, 4(r29)
    lwz	r10, lbl_801A6948
    lwz	r11, lbl_801A694C
    or r8, r10, r8
    stw	r11, lbl_801A694C
    stw	r8, lbl_801A6948
    lbz r8, 0x1f(r30)
    lbz r10, 0x1c(r30)
    add r16, r8, r0
    lhz r11, 0x20(r30)
    addi r16, r16, -0x28
    rlwinm r8, r16, 7, 0x10, 0x18
    or r8, r10, r8
    sth r8, 0xa(r29)
    add r8, r11, r0
    addi r0, r8, 0x28
    lwz	r10, lbl_801A6948
    subf r0, r12, r0
    srwi r8, r16, 9
    lwz	r11, lbl_801A694C
    slwi r0, r0, 1
    or r9, r10, r9
    stw	r11, lbl_801A694C
    or r0, r8, r0
    stw	r9, lbl_801A6948
    sth r0, 8(r29)
    lwz	r0, lbl_801A6948
    lwz	r8, lbl_801A694C
    or r0, r0, r7
    stw	r8, lbl_801A694C
    stw	r0, lbl_801A6948
    lhz r0, 0x10(r30)
    lbz r7, 0xc(r30)
    slwi r0, r0, 5
    or r0, r7, r0
    sth r0, 0x16(r29)
    lwz	r0, lbl_801A6948
    lwz	r7, lbl_801A694C
    or r0, r0, r6
    stw	r7, lbl_801A694C
    stw	r0, lbl_801A6948
    lhz r0, 0x14(r30)
    lbz r6, 0xe(r30)
    slwi r0, r0, 5
    or r0, r6, r0
    sth r0, 0x14(r29)
    lwz	r0, lbl_801A6948
    lwz	r6, lbl_801A694C
    or r0, r0, r4
    stw	r6, lbl_801A694C
    stw	r0, lbl_801A6948
    lhz r0, 0x12(r30)
    lbz r4, 0xd(r30)
    slwi r0, r0, 5
    or r0, r4, r0
    sth r0, 0x1a(r29)
    lwz	r0, lbl_801A6948
    lwz	r4, lbl_801A694C
    or r0, r0, r3
    stw	r4, lbl_801A694C
    stw	r0, lbl_801A6948
    lhz r0, 0x16(r30)
    lbz r3, 0xf(r30)
    slwi r0, r0, 5
    or r0, r3, r0
    sth r0, 0x18(r29)
    lwz	r3, lbl_801A6948
    lis r0, 8
    addi r6, r29, 0x11c
    lwz	r4, lbl_801A694C
    or r0, r3, r0
    stw	r4, lbl_801A694C
    stw	r0, lbl_801A6948
    lhz r3, 0(r27)
    lwz r4, 0(r25)
    addi r0, r3, 0xf
    lhz r3, 0(r15)
    srawi r0, r0, 4
    addze r0, r0
    cmpwi r4, 0
    stb r0, 0x11c(r29)
    bne _8001bb88
    lbz r4, 0(r6)
    b _8001bb90
_8001bb88:
    lbz r0, 0(r6)
    rlwinm r4, r0, 1, 0x18, 0x1e
_8001bb90:
    srawi r0, r3, 4
    stb r4, 0x11d(r29)
    addze r0, r0
    slwi r0, r0, 4
    subfc r0, r0, r3
    stb r0, 0x12c(r29)
    addi r0, r5, 0xf
    lis r3, 0x800
    lbz r4, 0x12c(r29)
    add r0, r4, r0
    srawi r0, r0, 4
    addze r0, r0
    stb r0, 0x11e(r29)
    lbz r0, 0x11e(r29)
    lbz r4, 0x11d(r29)
    rlwimi r4, r0, 8, 0x10, 0x17
    sth r4, 0x48(r29)
    lwz	r4, lbl_801A6948
    lwz	r0, lbl_801A6970
    lwz	r5, lbl_801A694C
    cmplwi r0, 0
    or r0, r5, r3
    stw	r0, lbl_801A694C
    stw	r4, lbl_801A6948
    beq _8001bc0c
    addi r3, r29, 0xf0
    addi r4, r29, 0x124
    addi r5, r29, 0x128
    addi r6, r29, 0x13c
    addi r7, r29, 0x140
    bl fn_8001AFB8
_8001bc0c:
    lwz r0, 0x130(r29)
    stw r0, 8(r1)
    lhz r3, 0(r19)
    lhz r4, 0(r20)
    lbz r5, 0(r30)
    lhz r6, 2(r30)
    lhz r7, 4(r30)
    lhz r8, 6(r30)
    lhz r9, 8(r30)
    lhz r10, 0xa(r30)
    bl fn_8001B28C
    mr r3, r14
    bl OSRestoreInterrupts
    lmw r14, 0x30(r1)
    lwz r0, 0x7c(r1)
    addi r1, r1, 0x78
    mtlr r0
    blr
}

#pragma pop
