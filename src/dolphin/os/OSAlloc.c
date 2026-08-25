#pragma push
#pragma force_active on

extern int OSCheckHeap(register void* param1);
extern unsigned char lbl_801A6414[4];
extern unsigned char lbl_8015BE40[160];
extern unsigned char lbl_8015BEE0[32];

extern unsigned char gAssetBudgetA[4];
extern unsigned char gAssetBudgetB[4];
extern unsigned char g_currentHeapHandle[4];
extern unsigned char lbl_801A6738[4];
extern unsigned char lbl_801A673C[4];
extern unsigned char lbl_801A6740[4];
asm int fn_8000961C(register void* param1)
{
    nofralloc
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    lwz	r29, gAssetBudgetA
    cmpwi	r29, -1
    beq     _800096a0
    mulli	r0, r29, 0x14
    lis     r4, lbl_8015BE40@ha
    lis     r5, lbl_8015BEE0@ha
    lwz	r30, g_currentHeapHandle
    addi	r4, r4, lbl_8015BE40@l
    lwz	r12, gAssetBudgetB
    add	r7, r4, r0
    lwzx	r8, r4, r0
    addi	r31, r5, lbl_8015BEE0@l
    lwz	r11, lbl_801A6740
    lwz	r10, lbl_801A673C
    lwz	r9, lbl_801A6738
    lwz	r6, 4(r7)
    lwz	r5, 8(r7)
    lwz	r4, 0xc(r7)
    lwz	r0, 0x10(r7)
    stw	r30, 0(r31)
    stw	r12, 4(r31)
    stw	r11, 8(r31)
    stw	r10, 0xc(r31)
    stw	r9, 0x10(r31)
    stw	r8, g_currentHeapHandle
    stw	r6, gAssetBudgetB
    stw	r5, lbl_801A6740
    stw	r4, lbl_801A673C
    stw	r0, lbl_801A6738
_800096a0:
    cmpwi	r3, 0
    blt     _800096b4
    lwz	r12, lbl_801A6740
    cmpw	r3, r12
    blt     _8000972c
_800096b4:
    cmpwi	r29, -1
    beq     _80009724
    mulli	r6, r29, 0x14
    lis     r4, lbl_8015BE40@ha
    lwz	r5, g_currentHeapHandle
    lis     r3, lbl_8015BEE0@ha
    addi	r4, r4, lbl_8015BE40@l
    lwz	r0, gAssetBudgetB
    stwx	r5, r4, r6
    add	r9, r4, r6
    lwz	r4, lbl_801A6740
    addi	r7, r3, lbl_8015BEE0@l
    stw	r0, 4(r9)
    lwz	r0, lbl_801A673C
    stw	r4, 8(r9)
    lwz	r6, 0(r7)
    lwz	r5, 4(r7)
    lwz	r4, 8(r7)
    lwz	r3, 0xc(r7)
    stw	r0, 0xc(r9)
    lwz	r8, lbl_801A6738
    lwz	r0, 0x10(r7)
    stw	r8, 0x10(r9)
    stw	r6, g_currentHeapHandle
    stw	r5, gAssetBudgetB
    stw	r4, lbl_801A6740
    stw	r3, lbl_801A673C
    stw	r0, lbl_801A6738
_80009724:
    li	r3, 0
    b       _8000981c
_8000972c:
    mulli	r0, r3, 0xc
    lwz	r11, gAssetBudgetB
    add	r3, r11, r0
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    bge     _800097b4
    cmpwi	r29, -1
    beq     _800097ac
    mulli	r6, r29, 0x14
    lis     r4, lbl_8015BE40@ha
    lwz	r5, g_currentHeapHandle
    lis     r3, lbl_8015BEE0@ha
    addi	r4, r4, lbl_8015BE40@l
    lwz	r0, lbl_801A673C
    stwx	r5, r4, r6
    add	r9, r4, r6
    addi	r7, r3, lbl_8015BEE0@l
    lwz	r8, lbl_801A6738
    stw	r11, 4(r9)
    lwz	r6, 0(r7)
    stw	r12, 8(r9)
    lwz	r5, 4(r7)
    stw	r0, 0xc(r9)
    lwz	r4, 8(r7)
    lwz	r3, 0xc(r7)
    lwz	r0, 0x10(r7)
    stw	r8, 0x10(r9)
    stw	r6, g_currentHeapHandle
    stw	r5, gAssetBudgetB
    stw	r4, lbl_801A6740
    stw	r3, lbl_801A673C
    stw	r0, lbl_801A6738
_800097ac:
    li	r3, 0
    b       _8000981c
_800097b4:
    cmpwi	r29, -1
    beq     _8000981c
    mulli	r7, r29, 0x14
    lis     r5, lbl_8015BE40@ha
    lwz	r6, g_currentHeapHandle
    lis     r4, lbl_8015BEE0@ha
    addi	r5, r5, lbl_8015BE40@l
    lwz	r0, lbl_801A673C
    stwx	r6, r5, r7
    add	r10, r5, r7
    addi	r8, r4, lbl_8015BEE0@l
    lwz	r9, lbl_801A6738
    stw	r11, 4(r10)
    lwz	r7, 0(r8)
    stw	r12, 8(r10)
    lwz	r6, 4(r8)
    stw	r0, 0xc(r10)
    lwz	r5, 8(r8)
    lwz	r4, 0xc(r8)
    lwz	r0, 0x10(r8)
    stw	r9, 0x10(r10)
    stw	r7, g_currentHeapHandle
    stw	r6, gAssetBudgetB
    stw	r5, lbl_801A6740
    stw	r4, lbl_801A673C
    stw	r0, lbl_801A6738
_8000981c:
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    blr	
}

asm void* OSAllocFromHeap(register int heap, register unsigned long size)
{
    nofralloc
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    lwz	r28, gAssetBudgetA
    cmpwi	r28, -1
    beq     _800098b8
    mulli	r0, r28, 0x14
    lis     r5, lbl_8015BE40@ha
    lis     r6, lbl_8015BEE0@ha
    lwz	r29, g_currentHeapHandle
    addi	r5, r5, lbl_8015BE40@l
    lwz	r31, gAssetBudgetB
    add	r8, r5, r0
    lwzx	r9, r5, r0
    addi	r30, r6, lbl_8015BEE0@l
    lwz	r12, lbl_801A6740
    lwz	r11, lbl_801A673C
    lwz	r10, lbl_801A6738
    lwz	r7, 4(r8)
    lwz	r6, 8(r8)
    lwz	r5, 0xc(r8)
    lwz	r0, 0x10(r8)
    stw	r29, 0(r30)
    stw	r31, 4(r30)
    stw	r12, 8(r30)
    stw	r11, 0xc(r30)
    stw	r10, 0x10(r30)
    stw	r9, g_currentHeapHandle
    stw	r7, gAssetBudgetB
    stw	r6, lbl_801A6740
    stw	r5, lbl_801A673C
    stw	r0, lbl_801A6738
_800098b8:
    mulli	r3, r3, 0xc
    lwz	r6, gAssetBudgetB
    addi	r0, r4, 0x3f
    add	r7, r6, r3
    rlwinm	r4, r0, 0, 0, 0x1a
    lwz	r5, 4(r7)
    mr	r3, r5
    b       _800098e8
_800098d8:
    lwz	r0, 8(r3)
    cmpw	r4, r0
    ble     _800098f0
    lwz	r3, 4(r3)
_800098e8:
    cmplwi	r3, 0
    bne     _800098d8
_800098f0:
    cmplwi	r3, 0
    bne     _8000996c
    cmpwi	r28, -1
    beq     _80009964
    mulli	r7, r28, 0x14
    lis     r4, lbl_8015BE40@ha
    lwz	r0, g_currentHeapHandle
    lis     r3, lbl_8015BEE0@ha
    addi	r5, r4, lbl_8015BE40@l
    lwz	r4, lbl_801A6740
    stwx	r0, r5, r7
    add	r9, r5, r7
    addi	r7, r3, lbl_8015BEE0@l
    lwz	r0, lbl_801A673C
    stw	r6, 4(r9)
    lwz	r6, 0(r7)
    stw	r4, 8(r9)
    lwz	r5, 4(r7)
    lwz	r4, 8(r7)
    lwz	r3, 0xc(r7)
    stw	r0, 0xc(r9)
    lwz	r8, lbl_801A6738
    lwz	r0, 0x10(r7)
    stw	r8, 0x10(r9)
    stw	r6, g_currentHeapHandle
    stw	r5, gAssetBudgetB
    stw	r4, lbl_801A6740
    stw	r3, lbl_801A673C
    stw	r0, lbl_801A6738
_80009964:
    li	r3, 0
    b       _80009a90
_8000996c:
    lwz	r0, 8(r3)
    subf	r0, r4, r0
    cmplwi	r0, 0x40
    bge     _800099b4
    lwz	r4, 4(r3)
    cmplwi	r4, 0
    beq     _80009990
    lwz	r0, 0(r3)
    stw	r0, 0(r4)
_80009990:
    lwz	r4, 0(r3)
    cmplwi	r4, 0
    bne     _800099a4
    lwz	r5, 4(r3)
    b       _800099ac
_800099a4:
    lwz	r0, 4(r3)
    stw	r0, 4(r4)
_800099ac:
    stw	r5, 4(r7)
    b       _800099f8
_800099b4:
    stw	r4, 8(r3)
    add	r5, r3, r4
    stw	r0, 8(r5)
    lwz	r0, 0(r3)
    stw	r0, 0(r5)
    lwz	r0, 4(r3)
    stw	r0, 4(r5)
    lwz	r4, 4(r5)
    cmplwi	r4, 0
    beq     _800099e0
    stw	r5, 0(r4)
_800099e0:
    lwz	r4, 0(r5)
    cmplwi	r4, 0
    beq     _800099f4
    stw	r5, 4(r4)
    b       _800099f8
_800099f4:
    stw	r5, 4(r7)
_800099f8:
    lwz	r4, 8(r7)
    li	r0, 0
    stw	r4, 4(r3)
    cmplwi	r4, 0
    stw	r0, 0(r3)
    beq     _80009a14
    stw	r3, 0(r4)
_80009a14:
    stw	r3, 8(r7)
    lwz	r0, gAssetBudgetA
    cmpwi	r0, -1
    beq     _80009a8c
    mulli	r7, r0, 0x14
    lis     r5, lbl_8015BE40@ha
    lwz	r6, g_currentHeapHandle
    lis     r4, lbl_8015BEE0@ha
    addi	r5, r5, lbl_8015BE40@l
    lwz	r0, gAssetBudgetB
    stwx	r6, r5, r7
    add	r10, r5, r7
    lwz	r5, lbl_801A6740
    addi	r8, r4, lbl_8015BEE0@l
    stw	r0, 4(r10)
    lwz	r0, lbl_801A673C
    stw	r5, 8(r10)
    lwz	r7, 0(r8)
    lwz	r6, 4(r8)
    lwz	r5, 8(r8)
    lwz	r4, 0xc(r8)
    stw	r0, 0xc(r10)
    lwz	r9, lbl_801A6738
    lwz	r0, 0x10(r8)
    stw	r9, 0x10(r10)
    stw	r7, g_currentHeapHandle
    stw	r6, gAssetBudgetB
    stw	r5, lbl_801A6740
    stw	r4, lbl_801A673C
    stw	r0, lbl_801A6738
_80009a8c:
    addi	r3, r3, 0x20
_80009a90:
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    blr	
}

asm int OSFreeToHeap(register void* param1)
{
    nofralloc
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    lwz	r0, gAssetBudgetA
    cmpwi	r0, -1
    beq     _80009b2c
    mulli	r0, r0, 0x14
    lis     r5, lbl_8015BE40@ha
    lis     r6, lbl_8015BEE0@ha
    lwz	r29, g_currentHeapHandle
    addi	r5, r5, lbl_8015BE40@l
    lwz	r31, gAssetBudgetB
    add	r8, r5, r0
    lwzx	r9, r5, r0
    addi	r30, r6, lbl_8015BEE0@l
    lwz	r12, lbl_801A6740
    lwz	r11, lbl_801A673C
    lwz	r10, lbl_801A6738
    lwz	r7, 4(r8)
    lwz	r6, 8(r8)
    lwz	r5, 0xc(r8)
    lwz	r0, 0x10(r8)
    stw	r29, 0(r30)
    stw	r31, 4(r30)
    stw	r12, 8(r30)
    stw	r11, 0xc(r30)
    stw	r10, 0x10(r30)
    stw	r9, g_currentHeapHandle
    stw	r7, gAssetBudgetB
    stw	r6, lbl_801A6740
    stw	r5, lbl_801A673C
    stw	r0, lbl_801A6738
_80009b2c:
    addi	r8, r4, -0x20
    lwz	r4, gAssetBudgetB
    mulli	r0, r3, 0xc
    lwz	r5, 4(r8)
    cmplwi	r5, 0
    add	r7, r4, r0
    lwz	r3, 8(r7)
    beq     _80009b54
    lwz	r0, 0(r8)
    stw	r0, 0(r5)
_80009b54:
    lwz	r4, 0(r8)
    cmplwi	r4, 0
    bne     _80009b68
    lwz	r3, 4(r8)
    b       _80009b70
_80009b68:
    lwz	r0, 4(r8)
    stw	r0, 4(r4)
_80009b70:
    stw	r3, 8(r7)
    li	r5, 0
    lwz	r6, 4(r7)
    mr	r4, r6
    b       _80009b94
_80009b84:
    cmplw	r8, r4
    ble     _80009b9c
    mr	r5, r4
    lwz	r4, 4(r4)
_80009b94:
    cmplwi	r4, 0
    bne     _80009b84
_80009b9c:
    stw	r4, 4(r8)
    cmplwi	r4, 0
    stw	r5, 0(r8)
    beq     _80009be0
    stw	r8, 0(r4)
    lwz	r3, 8(r8)
    add	r0, r8, r3
    cmplw	r0, r4
    bne     _80009be0
    lwz	r0, 8(r4)
    add	r0, r3, r0
    stw	r0, 8(r8)
    lwz	r4, 4(r4)
    cmplwi	r4, 0
    stw	r4, 4(r8)
    beq     _80009be0
    stw	r8, 0(r4)
_80009be0:
    cmplwi	r5, 0
    beq     _80009c1c
    stw	r8, 4(r5)
    lwz	r3, 8(r5)
    add	r0, r5, r3
    cmplw	r0, r8
    bne     _80009c20
    lwz	r0, 8(r8)
    cmplwi	r4, 0
    add	r0, r3, r0
    stw	r0, 8(r5)
    stw	r4, 4(r5)
    beq     _80009c20
    stw	r5, 0(r4)
    b       _80009c20
_80009c1c:
    mr	r6, r8
_80009c20:
    stw	r6, 4(r7)
    lwz	r0, gAssetBudgetA
    cmpwi	r0, -1
    beq     _80009c98
    mulli	r6, r0, 0x14
    lis     r4, lbl_8015BE40@ha
    lwz	r5, g_currentHeapHandle
    lis     r3, lbl_8015BEE0@ha
    addi	r4, r4, lbl_8015BE40@l
    lwz	r0, gAssetBudgetB
    stwx	r5, r4, r6
    add	r9, r4, r6
    lwz	r4, lbl_801A6740
    addi	r7, r3, lbl_8015BEE0@l
    stw	r0, 4(r9)
    lwz	r0, lbl_801A673C
    stw	r4, 8(r9)
    lwz	r6, 0(r7)
    lwz	r5, 4(r7)
    lwz	r4, 8(r7)
    lwz	r3, 0xc(r7)
    stw	r0, 0xc(r9)
    lwz	r8, lbl_801A6738
    lwz	r0, 0x10(r7)
    stw	r8, 0x10(r9)
    stw	r6, g_currentHeapHandle
    stw	r5, gAssetBudgetB
    stw	r4, lbl_801A6740
    stw	r3, lbl_801A673C
    stw	r0, lbl_801A6738
_80009c98:
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    blr	
}

asm void OSDumpHeap(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r5, lbl_801A6414
    li	r6, 0
    stw	r0, 0x14(r1)
    bl      OSCheckHeap
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm int OSCheckHeap(register void* param1)
{
    nofralloc
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    lwz	r0, gAssetBudgetA
    lwz	r28, g_currentHeapHandle
    cmpwi	r0, -1
    beq     _80009d60
    mulli	r0, r0, 0x14
    lis     r5, lbl_8015BE40@ha
    lis     r6, 0x8016
    lwz	r29, g_currentHeapHandle
    addi	r5, r5, lbl_8015BE40@l
    lwz	r31, gAssetBudgetB
    add	r8, r5, r0
    lwzx	r9, r5, r0
    addi	r30, r6, -0x4120
    lwz	r12, lbl_801A6740
    lwz	r11, lbl_801A673C
    lwz	r10, lbl_801A6738
    lwz	r7, 4(r8)
    lwz	r6, 8(r8)
    lwz	r5, 0xc(r8)
    lwz	r0, 0x10(r8)
    stw	r29, 0(r30)
    stw	r31, 4(r30)
    stw	r12, 8(r30)
    stw	r11, 0xc(r30)
    stw	r10, 0x10(r30)
    stw	r9, g_currentHeapHandle
    stw	r7, gAssetBudgetB
    stw	r6, lbl_801A6740
    stw	r5, lbl_801A673C
    stw	r0, lbl_801A6738
_80009d60:
    mulli	r0, r28, 0xc
    lwz	r6, gAssetBudgetB
    addi	r5, r3, -0x20
    lwz	r10, -0x18(r3)
    add	r3, r6, r0
    lwz	r6, 4(r3)
    add	r0, r5, r10
    b       _80009d90
_80009d80:
    cmplw	r6, r0
    bne     _80009d8c
    b       _80009d9c
_80009d8c:
    lwz	r6, 4(r6)
_80009d90:
    cmplwi	r6, 0
    bne     _80009d80
    li	r6, 0
_80009d9c:
    cmplwi	r6, 0
    bne     _80009db8
    addi	r0, r4, 0x40
    cmplw	r10, r0
    bgt     _80009db8
    li	r3, 0
    b       _80009f8c
_80009db8:
    lwz	r7, 4(r5)
    lwz	r6, 8(r3)
    cmplwi	r7, 0
    beq     _80009dd0
    lwz	r0, 0(r5)
    stw	r0, 0(r7)
_80009dd0:
    lwz	r7, 0(r5)
    cmplwi	r7, 0
    bne     _80009de4
    lwz	r6, 4(r5)
    b       _80009dec
_80009de4:
    lwz	r0, 4(r5)
    stw	r0, 4(r7)
_80009dec:
    stw	r6, 8(r3)
    li	r8, 0
    lwz	r9, 4(r3)
    mr	r7, r9
    b       _80009e10
_80009e00:
    cmplw	r5, r7
    ble     _80009e18
    mr	r8, r7
    lwz	r7, 4(r7)
_80009e10:
    cmplwi	r7, 0
    bne     _80009e00
_80009e18:
    stw	r7, 4(r5)
    cmplwi	r7, 0
    stw	r8, 0(r5)
    beq     _80009e5c
    stw	r5, 0(r7)
    lwz	r6, 8(r5)
    add	r0, r5, r6
    cmplw	r0, r7
    bne     _80009e5c
    lwz	r0, 8(r7)
    add	r0, r6, r0
    stw	r0, 8(r5)
    lwz	r7, 4(r7)
    cmplwi	r7, 0
    stw	r7, 4(r5)
    beq     _80009e5c
    stw	r5, 0(r7)
_80009e5c:
    cmplwi	r8, 0
    beq     _80009e98
    stw	r5, 4(r8)
    lwz	r6, 8(r8)
    add	r0, r8, r6
    cmplw	r0, r5
    bne     _80009e9c
    lwz	r0, 8(r5)
    cmplwi	r7, 0
    add	r0, r6, r0
    stw	r0, 8(r8)
    stw	r7, 4(r8)
    beq     _80009e9c
    stw	r8, 0(r7)
    b       _80009e9c
_80009e98:
    mr	r9, r5
_80009e9c:
    stw	r9, 4(r3)
    addi	r0, r4, 0x3f
    rlwinm	r6, r0, 0, 0, 0x1a
    lwz	r4, 8(r5)
    add	r7, r5, r6
    subf	r0, r6, r10
    stw	r6, 8(r5)
    subf	r4, r6, r4
    stw	r4, 8(r7)
    lwz	r4, 0(r5)
    stw	r4, 0(r7)
    lwz	r4, 4(r5)
    stw	r4, 4(r7)
    lwz	r4, 4(r7)
    cmplwi	r4, 0
    beq     _80009ee0
    stw	r7, 0(r4)
_80009ee0:
    lwz	r4, 0(r7)
    cmplwi	r4, 0
    beq     _80009ef4
    stw	r7, 4(r4)
    b       _80009ef8
_80009ef4:
    stw	r7, 4(r3)
_80009ef8:
    lwz	r6, 8(r3)
    li	r4, 0
    stw	r6, 4(r5)
    cmplwi	r6, 0
    stw	r4, 0(r5)
    beq     _80009f14
    stw	r5, 0(r6)
_80009f14:
    stw	r5, 8(r3)
    lwz	r3, gAssetBudgetA
    cmpwi	r3, -1
    beq     _80009f88
    mulli	r7, r3, 0x14
    lis     r4, lbl_8015BE40@ha
    lwz	r6, g_currentHeapHandle
    lis	r3, -0x7fea
    addi	r4, r4, lbl_8015BE40@l
    lwz	r5, gAssetBudgetB
    stwx	r6, r4, r7
    add	r9, r4, r7
    lwz	r4, lbl_801A6740
    stw	r5, 4(r9)
    lwzu	r7, -0x4120(r3)
    stw	r4, 8(r9)
    lwz	r8, lbl_801A673C
    lwz	r6, 4(r3)
    lwz	r5, 8(r3)
    lwz	r4, 0xc(r3)
    stw	r8, 0xc(r9)
    lwz	r8, lbl_801A6738
    lwz	r3, 0x10(r3)
    stw	r8, 0x10(r9)
    stw	r7, g_currentHeapHandle
    stw	r6, gAssetBudgetB
    stw	r5, lbl_801A6740
    stw	r4, lbl_801A673C
    stw	r3, lbl_801A6738
_80009f88:
    neg	r3, r0
_80009f8c:
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
