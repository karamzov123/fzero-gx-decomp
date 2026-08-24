#pragma push
#pragma force_active on

typedef unsigned int u32;
typedef int BOOL;
extern void DCInvalidateRange(register void* addr, register u32 nBytes);
extern void fn_800211F8(void);
extern void __AXGetStackHead(void);
extern void fn_80022450(void);
extern void __AXPushCallbackStack(void);
extern void DCFlushRange(register void* addr, register u32 nBytes);
extern void __AXPushFreeStack(void);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void __cvt_fp2unsigned(void);
extern unsigned char lbl_80124710[240];
extern unsigned char lbl_80164D60[70656];

asm void fn_800224E4(void)
{
    nofralloc
    lwz	r3, -0x7858(r13)
    blr	
}

asm void fn_800224EC(void)
{
    nofralloc
    lwz	r4, -0x7858(r13)
    lis     r5, lbl_80164D60@ha
    addi	r0, r5, lbl_80164D60@l
    addi	r4, r4, 1
    stw	r4, -0x7858(r13)
    addi	r6, r3, 0x138
    lwz	r5, 0x18(r3)
    lwz	r4, 0x1c(r3)
    mulli	r5, r5, 0xec
    cmplwi	r4, 0
    add	r5, r0, r5
    bne     _80022540
    lhz	r0, 0xe(r5)
    sth	r0, 0xe(r6)
    lhz	r0, 0x64(r5)
    sth	r0, 0x64(r6)
    lhz	r0, 0x7a(r5)
    sth	r0, 0x7a(r6)
    lhz	r0, 0x7c(r5)
    sth	r0, 0x7c(r6)
    blr	
_80022540:
    rlwinm.	r7, r4, 0, 0, 0
    beq     _80022788
    lwz	r4, 0(r6)
    stw	r4, 0(r5)
    lwz	r4, 4(r6)
    stw	r4, 4(r5)
    lwz	r4, 8(r6)
    stw	r4, 8(r5)
    lwz	r4, 0xc(r6)
    stw	r4, 0xc(r5)
    lwz	r4, 0x10(r6)
    stw	r4, 0x10(r5)
    lwz	r4, 0x14(r6)
    stw	r4, 0x14(r5)
    lwz	r4, 0x18(r6)
    stw	r4, 0x18(r5)
    lwz	r4, 0x1c(r6)
    stw	r4, 0x1c(r5)
    lwz	r4, 0x20(r6)
    stw	r4, 0x20(r5)
    lwz	r4, 0x24(r6)
    stw	r4, 0x24(r5)
    lwz	r4, 0x28(r6)
    stw	r4, 0x28(r5)
    lwz	r4, 0x2c(r6)
    stw	r4, 0x2c(r5)
    lwz	r4, 0x30(r6)
    stw	r4, 0x30(r5)
    lwz	r4, 0x34(r6)
    stw	r4, 0x34(r5)
    lwz	r4, 0x38(r6)
    stw	r4, 0x38(r5)
    lwz	r4, 0x3c(r6)
    stw	r4, 0x3c(r5)
    lwz	r4, 0x40(r6)
    stw	r4, 0x40(r5)
    lwz	r4, 0x44(r6)
    stw	r4, 0x44(r5)
    lwz	r4, 0x48(r6)
    stw	r4, 0x48(r5)
    lwz	r4, 0x4c(r6)
    stw	r4, 0x4c(r5)
    lwz	r4, 0x50(r6)
    stw	r4, 0x50(r5)
    lwz	r4, 0x54(r6)
    stw	r4, 0x54(r5)
    lwz	r4, 0x58(r6)
    stw	r4, 0x58(r5)
    lwz	r4, 0x5c(r6)
    stw	r4, 0x5c(r5)
    lwz	r4, 0x60(r6)
    stw	r4, 0x60(r5)
    lwz	r4, 0x64(r6)
    stw	r4, 0x64(r5)
    lwz	r4, 0x68(r6)
    stw	r4, 0x68(r5)
    lwz	r4, 0x6c(r6)
    stw	r4, 0x6c(r5)
    lwz	r4, 0x70(r6)
    stw	r4, 0x70(r5)
    lwz	r4, 0x74(r6)
    stw	r4, 0x74(r5)
    lwz	r4, 0x78(r6)
    stw	r4, 0x78(r5)
    lwz	r4, 0x7c(r6)
    stw	r4, 0x7c(r5)
    lwz	r4, 0x80(r6)
    stw	r4, 0x80(r5)
    lwz	r4, 0x84(r6)
    stw	r4, 0x84(r5)
    lwz	r4, 0x88(r6)
    stw	r4, 0x88(r5)
    lwz	r4, 0x8c(r6)
    stw	r4, 0x8c(r5)
    lwz	r4, 0x90(r6)
    stw	r4, 0x90(r5)
    lwz	r4, 0x94(r6)
    stw	r4, 0x94(r5)
    lwz	r4, 0x98(r6)
    stw	r4, 0x98(r5)
    lwz	r4, 0x9c(r6)
    stw	r4, 0x9c(r5)
    lwz	r4, 0xa0(r6)
    stw	r4, 0xa0(r5)
    lwz	r4, 0xa4(r6)
    stw	r4, 0xa4(r5)
    lwz	r4, 0xa8(r6)
    stw	r4, 0xa8(r5)
    lwz	r4, 0xac(r6)
    stw	r4, 0xac(r5)
    lwz	r4, 0xb0(r6)
    stw	r4, 0xb0(r5)
    lwz	r4, 0xb4(r6)
    stw	r4, 0xb4(r5)
    lwz	r4, 0xb8(r6)
    stw	r4, 0xb8(r5)
    lwz	r4, 0xbc(r6)
    stw	r4, 0xbc(r5)
    lwz	r4, 0xc0(r6)
    stw	r4, 0xc0(r5)
    lwz	r4, 0xc4(r6)
    stw	r4, 0xc4(r5)
    lwz	r4, 0xc8(r6)
    stw	r4, 0xc8(r5)
    lwz	r4, 0xcc(r6)
    stw	r4, 0xcc(r5)
    lwz	r4, 0x28(r3)
    cmplwi	r4, 0
    beqlr	
    lwz	r5, 0x18(r3)
    addi	r3, r3, 0x34
    slwi	r5, r5, 8
    add	r5, r0, r5
    addi	r5, r5, 0x4b00
    beqlr	
    rlwinm.	r0, r4, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _8002276c
_80022718:
    lwz	r0, 0(r5)
    stw	r0, 0(r3)
    lwz	r0, 4(r5)
    stw	r0, 4(r3)
    lwz	r0, 8(r5)
    stw	r0, 8(r3)
    lwz	r0, 0xc(r5)
    stw	r0, 0xc(r3)
    lwz	r0, 0x10(r5)
    stw	r0, 0x10(r3)
    lwz	r0, 0x14(r5)
    stw	r0, 0x14(r3)
    lwz	r0, 0x18(r5)
    stw	r0, 0x18(r3)
    lwz	r0, 0x1c(r5)
    addi	r5, r5, 0x20
    stw	r0, 0x1c(r3)
    addi	r3, r3, 0x20
    bdnz    _80022718
    andi.	r4, r4, 7
    beqlr	
_8002276c:
    mtctr	r4
_80022770:
    lwz	r0, 0(r5)
    addi	r5, r5, 4
    stw	r0, 0(r3)
    addi	r3, r3, 4
    bdnz    _80022770
    blr	
_80022788:
    clrlwi.	r7, r4, 0x1f
    beq     _800227a0
    lhz	r7, 8(r6)
    sth	r7, 8(r5)
    lhz	r7, 0xa(r6)
    sth	r7, 0xa(r5)
_800227a0:
    rlwinm.	r7, r4, 0, 0x1e, 0x1e
    beq     _800227b0
    lhz	r7, 0xc(r6)
    sth	r7, 0xc(r5)
_800227b0:
    rlwinm.	r7, r4, 0, 0x1d, 0x1d
    beq     _800227c4
    lhz	r7, 0xe(r6)
    sth	r7, 0xe(r5)
    b       _800227cc
_800227c4:
    lhz	r7, 0xe(r5)
    sth	r7, 0xe(r6)
_800227cc:
    rlwinm.	r7, r4, 0, 0x1c, 0x1c
    beq     _800227dc
    lhz	r7, 0x10(r6)
    sth	r7, 0x10(r5)
_800227dc:
    rlwinm.	r7, r4, 0, 0x1b, 0x1b
    beq     _80022874
    lhz	r7, 0x12(r6)
    sth	r7, 0x12(r5)
    lhz	r7, 0x14(r6)
    sth	r7, 0x14(r5)
    lhz	r7, 0x16(r6)
    sth	r7, 0x16(r5)
    lhz	r7, 0x18(r6)
    sth	r7, 0x18(r5)
    lhz	r7, 0x1a(r6)
    sth	r7, 0x1a(r5)
    lhz	r7, 0x1c(r6)
    sth	r7, 0x1c(r5)
    lhz	r7, 0x1e(r6)
    sth	r7, 0x1e(r5)
    lhz	r7, 0x20(r6)
    sth	r7, 0x20(r5)
    lhz	r7, 0x22(r6)
    sth	r7, 0x22(r5)
    lhz	r7, 0x24(r6)
    sth	r7, 0x24(r5)
    lhz	r7, 0x26(r6)
    sth	r7, 0x26(r5)
    lhz	r7, 0x28(r6)
    sth	r7, 0x28(r5)
    lhz	r7, 0x2a(r6)
    sth	r7, 0x2a(r5)
    lhz	r7, 0x2c(r6)
    sth	r7, 0x2c(r5)
    lhz	r7, 0x2e(r6)
    sth	r7, 0x2e(r5)
    lhz	r7, 0x30(r6)
    sth	r7, 0x30(r5)
    lhz	r7, 0x32(r6)
    sth	r7, 0x32(r5)
    lhz	r7, 0x34(r6)
    sth	r7, 0x34(r5)
_80022874:
    rlwinm.	r7, r4, 0, 0x19, 0x19
    beq     _80022890
    lhz	r7, 0x40(r6)
    sth	r7, 0x40(r5)
    lhz	r7, 0x42(r6)
    sth	r7, 0x42(r5)
    b       _80022918
_80022890:
    rlwinm.	r7, r4, 0, 0x1a, 0x1a
    beq     _80022918
    lhz	r8, 0x36(r6)
    li	r7, 0
    sth	r8, 0x36(r5)
    lhz	r8, 0x38(r6)
    sth	r8, 0x38(r5)
    lhz	r8, 0x3a(r6)
    sth	r8, 0x3a(r5)
    lhz	r8, 0x3c(r6)
    sth	r8, 0x3c(r5)
    lhz	r8, 0x3e(r6)
    sth	r8, 0x3e(r5)
    lhz	r8, 0x40(r6)
    sth	r8, 0x40(r5)
    lhz	r8, 0x42(r6)
    sth	r8, 0x42(r5)
    lwz	r8, 0x134(r3)
    stw	r7, 0(r8)
    stw	r7, 4(r8)
    stw	r7, 8(r8)
    stw	r7, 0xc(r8)
    stw	r7, 0x10(r8)
    stw	r7, 0x14(r8)
    stw	r7, 0x18(r8)
    stw	r7, 0x1c(r8)
    stw	r7, 0x20(r8)
    stw	r7, 0x24(r8)
    stw	r7, 0x28(r8)
    stw	r7, 0x2c(r8)
    stw	r7, 0x30(r8)
    stw	r7, 0x34(r8)
    stw	r7, 0x38(r8)
    stw	r7, 0x3c(r8)
_80022918:
    rlwinm.	r7, r4, 0, 0x18, 0x18
    beq     _800229e4
    lhz	r7, 0x44(r6)
    sth	r7, 0x44(r5)
    lhz	r7, 0x46(r6)
    sth	r7, 0x46(r5)
    lhz	r7, 0x48(r6)
    sth	r7, 0x48(r5)
    lhz	r7, 0x4a(r6)
    sth	r7, 0x4a(r5)
    lhz	r7, 0x4c(r6)
    sth	r7, 0x4c(r5)
    lwz	r7, 0x28(r3)
    cmplwi	r7, 0
    beq     _800229e4
    lwz	r8, 0x18(r3)
    addi	r3, r3, 0x34
    slwi	r8, r8, 8
    add	r8, r0, r8
    addi	r8, r8, 0x4b00
    beq     _800229e4
    rlwinm.	r0, r7, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _800229cc
_80022978:
    lwz	r0, 0(r3)
    stw	r0, 0(r8)
    lwz	r0, 4(r3)
    stw	r0, 4(r8)
    lwz	r0, 8(r3)
    stw	r0, 8(r8)
    lwz	r0, 0xc(r3)
    stw	r0, 0xc(r8)
    lwz	r0, 0x10(r3)
    stw	r0, 0x10(r8)
    lwz	r0, 0x14(r3)
    stw	r0, 0x14(r8)
    lwz	r0, 0x18(r3)
    stw	r0, 0x18(r8)
    lwz	r0, 0x1c(r3)
    addi	r3, r3, 0x20
    stw	r0, 0x1c(r8)
    addi	r8, r8, 0x20
    bdnz    _80022978
    andi.	r7, r7, 7
    beq     _800229e4
_800229cc:
    mtctr	r7
_800229d0:
    lwz	r0, 0(r3)
    addi	r3, r3, 4
    stw	r0, 0(r8)
    addi	r8, r8, 4
    bdnz    _800229d0
_800229e4:
    rlwinm.	r0, r4, 0, 0x17, 0x17
    beq     _80022a34
    lhz	r0, 0x52(r6)
    sth	r0, 0x52(r5)
    lhz	r0, 0x54(r6)
    sth	r0, 0x54(r5)
    lhz	r0, 0x56(r6)
    sth	r0, 0x56(r5)
    lhz	r0, 0x58(r6)
    sth	r0, 0x58(r5)
    lhz	r0, 0x5a(r6)
    sth	r0, 0x5a(r5)
    lhz	r0, 0x5c(r6)
    sth	r0, 0x5c(r5)
    lhz	r0, 0x5e(r6)
    sth	r0, 0x5e(r5)
    lhz	r0, 0x60(r6)
    sth	r0, 0x60(r5)
    lhz	r0, 0x62(r6)
    sth	r0, 0x62(r5)
_80022a34:
    rlwinm.	r0, r4, 0, 0x15, 0x15
    beq     _80022a50
    lhz	r0, 0x64(r5)
    sth	r0, 0x64(r6)
    lha	r0, 0x66(r6)
    sth	r0, 0x66(r5)
    b       _80022a68
_80022a50:
    rlwinm.	r0, r4, 0, 0x16, 0x16
    beq     _80022a68
    lhz	r0, 0x64(r6)
    sth	r0, 0x64(r5)
    lha	r0, 0x66(r6)
    sth	r0, 0x66(r5)
_80022a68:
    rlwinm.	r0, r4, 0, 0x14, 0x14
    beq     _80022a88
    lhz	r0, 0x68(r6)
    sth	r0, 0x68(r5)
    lhz	r0, 0x6a(r6)
    sth	r0, 0x6a(r5)
    lhz	r0, 0x6c(r6)
    sth	r0, 0x6c(r5)
_80022a88:
    rlwinm.	r0, r4, 0, 0xf, 0x12
    beq     _80022ae0
    rlwinm.	r0, r4, 0, 0x12, 0x12
    beq     _80022aa0
    lhz	r0, 0x6e(r6)
    sth	r0, 0x6e(r5)
_80022aa0:
    rlwinm.	r0, r4, 0, 0x11, 0x11
    beq     _80022ab0
    lwz	r0, 0x72(r6)
    stw	r0, 0x72(r5)
_80022ab0:
    rlwinm.	r0, r4, 0, 0x10, 0x10
    beq     _80022ac0
    lwz	r0, 0x76(r6)
    stw	r0, 0x76(r5)
_80022ac0:
    rlwinm.	r0, r4, 0, 0xf, 0xf
    beq     _80022ad4
    lwz	r0, 0x7a(r6)
    stw	r0, 0x7a(r5)
    b       _80022b1c
_80022ad4:
    lwz	r0, 0x7a(r5)
    stw	r0, 0x7a(r6)
    b       _80022b1c
_80022ae0:
    rlwinm.	r0, r4, 0, 0x13, 0x13
    beq     _80022b0c
    lwz	r0, 0x6e(r6)
    stw	r0, 0x6e(r5)
    lwz	r0, 0x72(r6)
    stw	r0, 0x72(r5)
    lwz	r0, 0x76(r6)
    stw	r0, 0x76(r5)
    lwz	r0, 0x7a(r6)
    stw	r0, 0x7a(r5)
    b       _80022b1c
_80022b0c:
    lhz	r0, 0x7a(r5)
    sth	r0, 0x7a(r6)
    lhz	r0, 0x7c(r5)
    sth	r0, 0x7c(r6)
_80022b1c:
    rlwinm.	r0, r4, 0, 0xe, 0xe
    beq     _80022b74
    lwz	r0, 0x7e(r6)
    stw	r0, 0x7e(r5)
    lwz	r0, 0x82(r6)
    stw	r0, 0x82(r5)
    lwz	r0, 0x86(r6)
    stw	r0, 0x86(r5)
    lwz	r0, 0x8a(r6)
    stw	r0, 0x8a(r5)
    lwz	r0, 0x8e(r6)
    stw	r0, 0x8e(r5)
    lwz	r0, 0x92(r6)
    stw	r0, 0x92(r5)
    lwz	r0, 0x96(r6)
    stw	r0, 0x96(r5)
    lwz	r0, 0x9a(r6)
    stw	r0, 0x9a(r5)
    lwz	r0, 0x9e(r6)
    stw	r0, 0x9e(r5)
    lwz	r0, 0xa2(r6)
    stw	r0, 0xa2(r5)
_80022b74:
    rlwinm.	r0, r4, 0, 0xc, 0xc
    beq     _80022b90
    lhz	r0, 0xa6(r6)
    sth	r0, 0xa6(r5)
    lhz	r0, 0xa8(r6)
    sth	r0, 0xa8(r5)
    b       _80022bd0
_80022b90:
    rlwinm.	r0, r4, 0, 0xd, 0xd
    beq     _80022bd0
    lhz	r0, 0xa6(r6)
    sth	r0, 0xa6(r5)
    lhz	r0, 0xa8(r6)
    sth	r0, 0xa8(r5)
    lhz	r0, 0xaa(r6)
    sth	r0, 0xaa(r5)
    lhz	r0, 0xac(r6)
    sth	r0, 0xac(r5)
    lhz	r0, 0xae(r6)
    sth	r0, 0xae(r5)
    lhz	r0, 0xb0(r6)
    sth	r0, 0xb0(r5)
    lhz	r0, 0xb2(r6)
    sth	r0, 0xb2(r5)
_80022bd0:
    rlwinm.	r0, r4, 0, 0xb, 0xb
    beqlr	
    lhz	r0, 0xb4(r6)
    sth	r0, 0xb4(r5)
    lhz	r0, 0xb6(r6)
    sth	r0, 0xb6(r5)
    lhz	r0, 0xb8(r6)
    sth	r0, 0xb8(r5)
    blr	
}

asm void fn_80022BF4(void)
{
    nofralloc
    mflr	r0
    lis     r4, lbl_80164D60@ha
    stw	r0, 4(r1)
    li	r0, 0
    stwu	r1, -0x28(r1)
    stmw	r26, 0x10(r1)
    addi	r30, r4, lbl_80164D60@l
    lis     r4, lbl_80124710@ha
    addi	r26, r3, 0
    addi	r31, r4, lbl_80124710@l
    addi	r3, r30, 0
    li	r4, 0x3b00
    stw	r0, -0x7858(r13)
    bl      DCInvalidateRange
    addi	r3, r30, 0x3b00
    li	r4, 0x1000
    bl      DCInvalidateRange
    bl      fn_800211F8
    addis	r0, r3, 1
    add	r29, r0, r26
    li	r28, 0x1f
    addi	r29, r29, -0x55f0
_80022c4c:
    mr	r3, r28
    bl      __AXGetStackHead
    mr	r27, r3
    b       _80022d70
_80022c5c:
    lwz	r0, 0x20(r27)
    cmplwi	r0, 0
    beq     _80022c78
    lwz	r0, 0x18(r27)
    mulli	r0, r0, 0xec
    add	r3, r30, r0
    bl      fn_80022450
_80022c78:
    lhz	r0, 0x146(r27)
    cmplwi	r0, 1
    beq     _80022c90
    lwz	r0, 0x28(r27)
    cmplwi	r0, 0
    beq     _80022d48
_80022c90:
    lhz	r0, 0x140(r27)
    cmplwi	r0, 2
    beq     _80022cac
    lhz	r0, 0x1de(r27)
    slwi	r0, r0, 2
    lwzx	r0, r31, r0
    add	r29, r29, r0
_80022cac:
    lhz	r6, 0x144(r27)
    lwz	r0, -0x7860(r13)
    rlwinm	r4, r6, 0x19, 0x19, 0x1d
    rlwinm	r3, r6, 0x1e, 0x19, 0x1d
    add	r4, r31, r4
    add	r3, r31, r3
    lwz	r5, 0x54(r4)
    lwz	r3, 0x54(r3)
    rlwinm	r4, r6, 2, 0x1a, 0x1d
    add	r4, r31, r4
    add	r3, r3, r5
    lwz	r4, 0x14(r4)
    addi	r3, r3, 0x8c
    add	r29, r3, r29
    add	r29, r4, r29
    cmplw	r0, r29
    ble     _80022cfc
    mr	r3, r27
    bl      fn_800224EC
    b       _80022d50
_80022cfc:
    lwz	r0, 0x18(r27)
    mulli	r0, r0, 0xec
    add	r26, r30, r0
    lhz	r0, 0xe(r26)
    cmplwi	r0, 1
    bne     _80022d1c
    mr	r3, r26
    bl      fn_80022450
_80022d1c:
    li	r0, 0
    sth	r0, 0x4c(r26)
    mr	r3, r27
    sth	r0, 0x4a(r26)
    sth	r0, 0x48(r26)
    sth	r0, 0x46(r26)
    sth	r0, 0x44(r26)
    sth	r0, 0xe(r26)
    sth	r0, 0x146(r27)
    bl      __AXPushCallbackStack
    b       _80022d50
_80022d48:
    mr	r3, r27
    bl      fn_800224EC
_80022d50:
    li	r3, 0
    stw	r3, 0x1c(r27)
    addi	r0, r27, 0x34
    stw	r3, 0x20(r27)
    stw	r3, 0x28(r27)
    stw	r3, 0x24(r27)
    stw	r0, 0x30(r27)
    lwz	r27, 0(r27)
_80022d70:
    cmplwi	r27, 0
    bne     _80022c5c
    addic.	r28, r28, -1
    bne     _80022c4c
    stw	r29, -0x785c(r13)
    li	r3, 0
    bl      __AXGetStackHead
    mr	r31, r3
    b       _80022e1c
_80022d94:
    lwz	r0, 0x20(r31)
    cmplwi	r0, 0
    beq     _80022db0
    lwz	r0, 0x18(r31)
    mulli	r0, r0, 0xec
    add	r3, r30, r0
    bl      fn_80022450
_80022db0:
    li	r4, 0
    stw	r4, 0x20(r31)
    lwz	r0, 0x18(r31)
    mulli	r3, r0, 0xec
    addi	r0, r3, 0x4c
    sthx	r4, r30, r0
    lwz	r0, 0x18(r31)
    mulli	r3, r0, 0xec
    addi	r0, r3, 0x4a
    sthx	r4, r30, r0
    lwz	r0, 0x18(r31)
    mulli	r3, r0, 0xec
    addi	r0, r3, 0x48
    sthx	r4, r30, r0
    lwz	r0, 0x18(r31)
    mulli	r3, r0, 0xec
    addi	r0, r3, 0x46
    sthx	r4, r30, r0
    lwz	r0, 0x18(r31)
    mulli	r3, r0, 0xec
    addi	r0, r3, 0x44
    sthx	r4, r30, r0
    lwz	r0, 0x18(r31)
    mulli	r3, r0, 0xec
    addi	r0, r3, 0xe
    sthx	r4, r30, r0
    lwz	r31, 0(r31)
_80022e1c:
    cmplwi	r31, 0
    bne     _80022d94
    addi	r3, r30, 0
    li	r4, 0x3b00
    bl      DCFlushRange
    addi	r3, r30, 0x3b00
    li	r4, 0x1000
    bl      DCFlushRange
    addi	r3, r30, 0x4b00
    li	r4, 0x4000
    bl      DCFlushRange
    lmw	r26, 0x10(r1)
    lwz	r0, 0x2c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void fn_80022E5C(void)
{
    nofralloc
    lis     r3, lbl_80164D60@ha
    addi	r3, r3, lbl_80164D60@l
    blr	
}

asm void fn_80022E68(void)
{
    nofralloc
    li	r5, 0
    sth	r5, 0x146(r3)
    li	r4, 0xa4
    addi	r0, r3, 0x34
    sth	r5, 0x16e(r3)
    stw	r4, 0x1c(r3)
    stw	r5, 0x28(r3)
    stw	r5, 0x24(r3)
    stw	r0, 0x30(r3)
    sth	r5, 0x184(r3)
    sth	r5, 0x182(r3)
    sth	r5, 0x180(r3)
    sth	r5, 0x17e(r3)
    sth	r5, 0x17c(r3)
    blr	
}

asm void fn_80022EA4(void)
{
    nofralloc
    mflr	r0
    lis	r3, 0x51ec
    stw	r0, 4(r1)
    lis	r4, -0x8000
    addi	r3, r3, -0x7ae1
    stwu	r1, -0x30(r1)
    stmw	r26, 0x18(r1)
    lwz	r0, 0xf8(r4)
    mulhwu	r0, r3, r0
    lis     r3, lbl_80164D60@ha
    addi	r31, r3, lbl_80164D60@l
    srwi	r0, r0, 7
    li	r3, 0
    stw	r0, -0x7860(r13)
    li	r0, 0x1d8
    stw	r3, -0x785c(r13)
    mtctr	r0
    addi	r4, r31, 0
_80022eec:
    stw	r3, 0(r4)
    stw	r3, 4(r4)
    stw	r3, 8(r4)
    stw	r3, 0xc(r4)
    stw	r3, 0x10(r4)
    stw	r3, 0x14(r4)
    stw	r3, 0x18(r4)
    stw	r3, 0x1c(r4)
    addi	r4, r4, 0x20
    bdnz    _80022eec
    li	r0, 0x80
    mtctr	r0
    addi	r3, r31, 0x3b00
    li	r0, 0
_80022f24:
    stw	r0, 0(r3)
    stw	r0, 4(r3)
    stw	r0, 8(r3)
    stw	r0, 0xc(r3)
    stw	r0, 0x10(r3)
    stw	r0, 0x14(r3)
    stw	r0, 0x18(r3)
    stw	r0, 0x1c(r3)
    addi	r3, r3, 0x20
    bdnz    _80022f24
    li	r0, 0x448
    addis	r3, r31, 1
    mtctr	r0
    li	r0, 0
    addi	r3, r3, -0x7500
_80022f60:
    stw	r0, 0(r3)
    stw	r0, 4(r3)
    stw	r0, 8(r3)
    stw	r0, 0xc(r3)
    stw	r0, 0x10(r3)
    stw	r0, 0x14(r3)
    stw	r0, 0x18(r3)
    stw	r0, 0x1c(r3)
    addi	r3, r3, 0x20
    bdnz    _80022f60
    addis	r27, r31, 1
    addi	r30, r31, 0
    addi	r29, r31, 0x3b00
    addi	r28, r31, 0x4b00
    li	r26, 0
    addi	r27, r27, -0x7500
_80022fa0:
    stw	r26, 0x18(r27)
    addi	r5, r27, 0x34
    li	r4, 0
    stw	r5, 0x30(r27)
    li	r0, 0xa4
    cmplwi	r26, 0x3f
    stw	r29, 0x134(r27)
    mr	r3, r27
    sth	r4, 0x146(r27)
    sth	r4, 0x16e(r27)
    stw	r0, 0x1c(r27)
    stw	r4, 0x28(r27)
    stw	r4, 0x24(r27)
    stw	r5, 0x30(r27)
    sth	r4, 0x184(r27)
    sth	r4, 0x182(r27)
    sth	r4, 0x180(r27)
    sth	r4, 0x17e(r27)
    sth	r4, 0x17c(r27)
    bne     _80023004
    sth	r4, 2(r30)
    sth	r4, 0(r30)
    sth	r4, 0x13a(r27)
    sth	r4, 0x138(r27)
    b       _8002301c
_80023004:
    addi	r0, r30, 0xec
    srwi	r4, r0, 0x10
    sth	r4, 0x138(r27)
    sth	r0, 0x13a(r27)
    sth	r4, 0(r30)
    sth	r0, 2(r30)
_8002301c:
    srwi	r0, r30, 0x10
    sth	r0, 0x13c(r27)
    srwi	r4, r29, 0x10
    srwi	r5, r28, 0x10
    sth	r30, 0x13e(r27)
    sth	r0, 4(r30)
    li	r0, 1
    sth	r30, 6(r30)
    sth	r4, 0x170(r27)
    sth	r29, 0x172(r27)
    sth	r4, 0x38(r30)
    sth	r29, 0x3a(r30)
    sth	r5, 0x186(r27)
    sth	r28, 0x188(r27)
    sth	r5, 0x4e(r30)
    sth	r28, 0x50(r30)
    stw	r0, 0xc(r27)
    bl      __AXPushFreeStack
    addi	r26, r26, 1
    cmplwi	r26, 0x40
    addi	r30, r30, 0xec
    addi	r29, r29, 0x40
    addi	r28, r28, 0x100
    addi	r27, r27, 0x224
    blt     _80022fa0
    addi	r3, r31, 0
    li	r4, 0x3b00
    bl      DCFlushRange
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void fn_800230A0(void)
{
    nofralloc
    blr	
}

asm void AXSetVoiceState_cached(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, 0
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    bl      OSDisableInterrupts
    cmpwi	r31, 2
    addi	r4, r30, 0x138
    beq     _8002310c
    bge     _800230e4
    cmpwi	r31, 0
    beq     _800230f4
    bge     _80023100
    b       _80023140
_800230e4:
    cmpwi	r31, 4
    beq     _80023130
    bge     _80023140
    b       _8002311c
_800230f4:
    li	r0, 2
    sth	r0, 8(r4)
    b       _80023140
_80023100:
    li	r0, 1
    sth	r0, 8(r4)
    b       _80023140
_8002310c:
    li	r0, 0
    sth	r0, 8(r4)
    sth	r0, 0xa(r4)
    b       _80023140
_8002311c:
    li	r0, 0
    sth	r0, 8(r4)
    li	r0, 1
    sth	r0, 0xa(r4)
    b       _80023140
_80023130:
    li	r0, 0
    sth	r0, 8(r4)
    li	r0, 2
    sth	r0, 0xa(r4)
_80023140:
    lwz	r0, 0x1c(r30)
    ori	r0, r0, 1
    stw	r0, 0x1c(r30)
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void AXSetVoiceType_cached(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, 0
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    bl      OSDisableInterrupts
    sth	r31, 0x146(r30)
    clrlwi.	r0, r31, 0x10
    lwz	r4, 0x1c(r30)
    ori	r0, r4, 4
    stw	r0, 0x1c(r30)
    bne     _800231a8
    li	r0, 1
    stw	r0, 0x20(r30)
_800231a8:
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_800231C4(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    li	r0, 1
    sth	r0, 0x16e(r31)
    li	r0, 0
    sth	r0, 0x17a(r31)
    sth	r0, 0x178(r31)
    sth	r0, 0x176(r31)
    sth	r0, 0x174(r31)
    lwz	r0, 0x1c(r31)
    rlwinm	r0, r0, 0, 0x1a, 0x18
    stw	r0, 0x1c(r31)
    lwz	r0, 0x1c(r31)
    ori	r0, r0, 0x20
    stw	r0, 0x1c(r31)
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80023228(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r5, 0
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    bl      OSDisableInterrupts
    sth	r30, 0x178(r29)
    sth	r31, 0x17a(r29)
    lwz	r0, 0x1c(r29)
    ori	r0, r0, 0x40
    stw	r0, 0x1c(r29)
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_80023284(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    addi	r31, r29, 0x1a6
    bl      OSDisableInterrupts
    lwz	r0, 0(r30)
    stw	r0, 0(r31)
    lwz	r0, 4(r30)
    stw	r0, 4(r31)
    lwz	r0, 8(r30)
    stw	r0, 8(r31)
    lwz	r0, 0xc(r30)
    stw	r0, 0xc(r31)
    lhz	r0, 2(r30)
    cmpwi	r0, 0xa
    beq     _800232f4
    bge     _800232e8
    cmpwi	r0, 0
    beq     _80023358
    b       _80023358
_800232e8:
    cmpwi	r0, 0x19
    beq     _80023328
    b       _80023358
_800232f4:
    li	r4, 0
    stw	r4, 0x10(r31)
    lis	r0, 0x800
    stw	r4, 0x14(r31)
    stw	r4, 0x18(r31)
    stw	r4, 0x1c(r31)
    stw	r4, 0x20(r31)
    stw	r4, 0x24(r31)
    stw	r4, 0x28(r31)
    stw	r4, 0x2c(r31)
    stw	r0, 0x30(r31)
    stw	r4, 0x34(r31)
    b       _80023358
_80023328:
    li	r4, 0
    stw	r4, 0x10(r31)
    lis	r0, 0x100
    stw	r4, 0x14(r31)
    stw	r4, 0x18(r31)
    stw	r4, 0x1c(r31)
    stw	r4, 0x20(r31)
    stw	r4, 0x24(r31)
    stw	r4, 0x28(r31)
    stw	r4, 0x2c(r31)
    stw	r0, 0x30(r31)
    stw	r4, 0x34(r31)
_80023358:
    lwz	r0, 0x1c(r29)
    rlwinm	r0, r0, 0, 0x13, 0xe
    stw	r0, 0x1c(r29)
    lwz	r0, 0x1c(r29)
    oris	r0, r0, 2
    ori	r0, r0, 0x1000
    stw	r0, 0x1c(r29)
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_80023394(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    addi	r31, r29, 0x1b6
    bl      OSDisableInterrupts
    lwz	r0, 0(r30)
    stw	r0, 0(r31)
    lwz	r0, 4(r30)
    stw	r0, 4(r31)
    lwz	r0, 8(r30)
    stw	r0, 8(r31)
    lwz	r0, 0xc(r30)
    stw	r0, 0xc(r31)
    lwz	r0, 0x10(r30)
    stw	r0, 0x10(r31)
    lwz	r0, 0x14(r30)
    stw	r0, 0x14(r31)
    lwz	r0, 0x18(r30)
    stw	r0, 0x18(r31)
    lwz	r0, 0x1c(r30)
    stw	r0, 0x1c(r31)
    lwz	r0, 0x20(r30)
    stw	r0, 0x20(r31)
    lwz	r0, 0x24(r30)
    stw	r0, 0x24(r31)
    lwz	r0, 0x1c(r29)
    oris	r0, r0, 2
    stw	r0, 0x1c(r29)
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_80023438(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    addi	r31, r29, 0x1de
    bl      OSDisableInterrupts
    lhz	r0, 0(r30)
    sth	r0, 0(r31)
    lhz	r0, 2(r30)
    sth	r0, 2(r31)
    lhz	r0, 4(r30)
    sth	r0, 4(r31)
    lhz	r0, 6(r30)
    sth	r0, 6(r31)
    lhz	r0, 8(r30)
    sth	r0, 8(r31)
    lhz	r0, 0xa(r30)
    sth	r0, 0xa(r31)
    lhz	r0, 0xc(r30)
    sth	r0, 0xc(r31)
    lwz	r0, 0x1c(r29)
    rlwinm	r0, r0, 0, 0xd, 0xb
    stw	r0, 0x1c(r29)
    lwz	r0, 0x1c(r29)
    oris	r0, r0, 4
    stw	r0, 0x1c(r29)
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_800234D0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stfd	f31, 0x20(r1)
    fmr	f31, f1
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    bl      OSDisableInterrupts
    lfs	f0, -0x7ec8(r2)
    mr	r30, r3
    fmuls	f31, f0, f31
    fmr	f1, f31
    bl      __cvt_fp2unsigned
    fmr	f1, f31
    mr	r31, r3
    bl      __cvt_fp2unsigned
    lis	r0, 4
    cmplw	r3, r0
    ble     _80023528
    lis	r31, 4
_80023528:
    srwi	r0, r31, 0x10
    sth	r0, 0x1de(r29)
    mr	r3, r30
    sth	r31, 0x1e0(r29)
    lwz	r0, 0x1c(r29)
    oris	r0, r0, 8
    stw	r0, 0x1c(r29)
    bl      OSRestoreInterrupts
    lwz	r0, 0x2c(r1)
    lfd	f31, 0x20(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void fn_80023568(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    addi	r31, r29, 0x1ec
    bl      OSDisableInterrupts
    lhz	r0, 0(r30)
    sth	r0, 0(r31)
    lhz	r0, 2(r30)
    sth	r0, 2(r31)
    lhz	r0, 4(r30)
    sth	r0, 4(r31)
    lwz	r0, 0x1c(r29)
    oris	r0, r0, 0x10
    stw	r0, 0x1c(r29)
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_800235D4(void)
{
    nofralloc
    lwz	r0, -0x7844(r13)
    cmplwi	r0, 0
    beq     _80023614
    lwz	r3, -0x7848(r13)
    lwz	r4, -0x784c(r13)
    addi	r0, r3, 1
    lwz	r6, -0x7850(r13)
    stw	r0, -0x7848(r13)
    mulli	r0, r3, 0x38
    lwz	r5, -0x7848(r13)
    add	r3, r6, r0
    divwu	r0, r5, r4
    mullw	r0, r0, r4
    subf	r0, r0, r5
    stw	r0, -0x7848(r13)
    blr	
_80023614:
    li	r3, 0
    blr	
}

asm void fn_8002361C(void)
{
    nofralloc
    li	r5, 0
    stw	r3, -0x7850(r13)
    li	r0, 1
    stw	r4, -0x784c(r13)
    stw	r5, -0x7848(r13)
    stw	r0, -0x7844(r13)
    blr	
}

asm void fn_80023638(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      OSDisableInterrupts
    lwz	r0, -0x7848(r13)
    cmplwi	r0, 0
    mr	r31, r0
    beq     _80023660
    addi	r31, r31, -1
_80023660:
    li	r0, 0
    stw	r0, -0x7848(r13)
    bl      OSRestoreInterrupts
    mr	r3, r31
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

#pragma pop
