typedef int s32;

extern int gAssetBudgetA; /* allocator context slot index */
extern int lbl_801A6734;
extern void *lbl_801A6738; /* ArenaEnd */
extern void *lbl_801A673C; /* ArenaStart */
extern void *gAssetBudgetB; /* HeapArray */
extern int lbl_801A6740;   /* NumHeaps */
extern int g_currentHeapHandle;   /* __OSCurrHeap */
extern unsigned char lbl_8015BE40[160];
extern unsigned char lbl_8015BEE0[32];

asm void OSAllocTableInit(void)
{
    nofralloc
    li      r3, -1
    lis     r4, 0x8016
    stwu    r3, 0xBE40(r4)
    li      r0, 0
    stw     r0, 0x04(r4)
    stw     r0, 0x08(r4)
    stw     r0, 0x0c(r4)
    stw     r0, 0x10(r4)
    stw     r3, 0x14(r4)
    stw     r0, 0x18(r4)
    stw     r0, 0x1c(r4)
    stw     r0, 0x20(r4)
    stw     r0, 0x24(r4)
    stw     r3, 0x28(r4)
    stw     r0, 0x2c(r4)
    stw     r0, 0x30(r4)
    stw     r0, 0x34(r4)
    stw     r0, 0x38(r4)
    stw     r3, 0x3c(r4)
    stw     r0, 0x40(r4)
    stw     r0, 0x44(r4)
    stw     r0, 0x48(r4)
    stw     r0, 0x4c(r4)
    stw     r3, 0x50(r4)
    stw     r0, 0x54(r4)
    stw     r0, 0x58(r4)
    stw     r0, 0x5c(r4)
    stw     r0, 0x60(r4)
    stw     r3, 0x64(r4)
    stw     r0, 0x68(r4)
    stw     r0, 0x6c(r4)
    stw     r0, 0x70(r4)
    stw     r0, 0x74(r4)
    stw     r3, 0x78(r4)
    stw     r0, 0x7c(r4)
    stw     r0, 0x80(r4)
    stw     r0, 0x84(r4)
    stw     r0, 0x88(r4)
    stw     r3, 0x8c(r4)
    stw     r0, 0x90(r4)
    stw     r0, 0x94(r4)
    stw     r0, 0x98(r4)
    stw     r0, 0x9c(r4)
    stw	r3, gAssetBudgetA
    blr
}

asm void OSHeapLockAcquire(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    stw     r31, 0xC(r1)
    lwz	r0, gAssetBudgetA   /* gAssetBudgetA */
    cmpwi   r0, -1
    beq     swapdone
    mulli   r0, r0, 0x14
    lis     r3, lbl_8015BE40@ha
    lis     r4, lbl_8015BEE0@ha
    lwz	r31, g_currentHeapHandle  /* g_currentHeapHandle */
    addi    r3, r3, lbl_8015BE40@l
    lwz	r11, gAssetBudgetB  /* gAssetBudgetB */
    add     r6, r3, r0
    lwzx    r7, r3, r0
    addi    r12, r4, lbl_8015BEE0@l
    lwz	r10, lbl_801A6740  /* lbl_801A6740 */
    lwz	r9, lbl_801A673C   /* lbl_801A673C */
    lwz	r8, lbl_801A6738   /* lbl_801A6738 */
    lwz     r5, 4(r6)
    lwz     r4, 8(r6)
    lwz     r3, 0xC(r6)
    lwz     r0, 0x10(r6)
    stw     r31, 0(r12)
    stw     r11, 4(r12)
    stw     r10, 8(r12)
    stw     r9, 0xC(r12)
    stw     r8, 0x10(r12)
    stw	r7, g_currentHeapHandle
    stw	r5, gAssetBudgetB
    stw	r4, lbl_801A6740
    stw	r3, lbl_801A673C
    stw	r0, lbl_801A6738
swapdone:
    lwz     r31, 0xC(r1)
    addi    r1, r1, 0x10
    blr
}

asm void OSHeapLockRelease(void)
{
    nofralloc
    lwz	r0, gAssetBudgetA   /* gAssetBudgetA */
    cmpwi   r0, -1
    beqlr
    mulli   r6, r0, 0x14
    lis     r4, lbl_8015BE40@ha
    lwz	r5, g_currentHeapHandle   /* g_currentHeapHandle */
    lis     r3, lbl_8015BEE0@ha
    addi    r4, r4, lbl_8015BE40@l
    lwz	r0, gAssetBudgetB   /* gAssetBudgetB */
    stwx    r5, r4, r6
    add     r9, r4, r6
    lwz	r4, lbl_801A6740   /* lbl_801A6740 */
    addi    r7, r3, lbl_8015BEE0@l
    stw     r0, 4(r9)
    lwz	r0, lbl_801A673C   /* lbl_801A673C */
    stw     r4, 8(r9)
    lwz     r6, 0(r7)
    lwz     r5, 4(r7)
    lwz     r4, 8(r7)
    lwz     r3, 0xC(r7)
    stw     r0, 0xC(r9)
    lwz	r8, lbl_801A6738   /* lbl_801A6738 */
    lwz     r0, 0x10(r7)
    stw     r8, 0x10(r9)
    stw	r6, g_currentHeapHandle
    stw	r5, gAssetBudgetB
    stw	r4, lbl_801A6740
    stw	r3, lbl_801A673C
    stw	r0, lbl_801A6738
    blr
}
