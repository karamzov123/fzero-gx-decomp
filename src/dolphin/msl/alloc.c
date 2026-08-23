// MSL default-heap malloc/free pair ("GCN_Mem_Alloc.c : InitDefaultHeap").
// Lazy-init the OS heap arena on first use (flag lbl_801A6410 == -1), then
// delegate to OSAlloc/OSFree thunks.
extern void* lbl_801A6410; // sdata init-flag, -1 until InitDefaultHeap

extern void OSReport(char* fmt, ...);
extern unsigned long OSGetArenaLo(void);
extern unsigned long OSGetArenaHi(void);
extern void OSSetArenaLo(unsigned long lo);
extern void* OSInitAlloc(void* lo, void* hi, int create);
extern void fn_80008F60(void* lo, void* hi);
extern void* OSSetCurrentHeap_thunk(void* heap);
extern void* OSFree(void* heap, unsigned long size);
extern void OSAlloc(void* heap, unsigned long size);
extern unsigned char lbl_80094E48[54];
extern unsigned char lbl_80094E80[57];

#pragma push
#pragma force_active on

asm void* fn_80079EF0(register unsigned long size)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    stw     r0, 0x24(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    mr      r29, r3
    lwz     r0, -0x7FB0(r13)
    cmpwi   r0, -1
    bne     _80079f80
    lis     r3, lbl_80094E48@ha
    addi    r3, r3, lbl_80094E48@l
    crxor   6, 6, 6
    bl      OSReport
    lis     r3, lbl_80094E80@ha
    addi    r3, r3, lbl_80094E80@l
    crxor   6, 6, 6
    bl      OSReport
    bl      OSGetArenaLo
    mr      r31, r3
    bl      OSGetArenaHi
    mr      r30, r3
    mr      r3, r31
    li      r5, 1
    mr      r4, r30
    bl      OSInitAlloc
    mr      r31, r3
    bl      OSSetArenaLo
    addi    r0, r31, 0x1f
    rlwinm  r30, r30, 0, 0, 0x1a
    rlwinm  r3, r0, 0, 0, 0x1a
    mr      r4, r30
    bl      fn_80008F60
    bl      OSSetCurrentHeap_thunk
    mr      r3, r30
    bl      OSSetArenaLo
_80079f80:
    lwz     r3, -0x7FB0(r13)
    mr      r4, r29
    bl      OSFree
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

asm void fn_80079FA8(register unsigned long size)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    stw     r0, 0x24(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    mr      r29, r3
    lwz     r0, -0x7FB0(r13)
    cmpwi   r0, -1
    bne     _8007a038
    lis     r3, lbl_80094E48@ha
    addi    r3, r3, lbl_80094E48@l
    crxor   6, 6, 6
    bl      OSReport
    lis     r3, lbl_80094E80@ha
    addi    r3, r3, lbl_80094E80@l
    crxor   6, 6, 6
    bl      OSReport
    bl      OSGetArenaLo
    mr      r31, r3
    bl      OSGetArenaHi
    mr      r30, r3
    mr      r3, r31
    li      r5, 1
    mr      r4, r30
    bl      OSInitAlloc
    mr      r31, r3
    bl      OSSetArenaLo
    addi    r0, r31, 0x1f
    rlwinm  r30, r30, 0, 0, 0x1a
    rlwinm  r3, r0, 0, 0, 0x1a
    mr      r4, r30
    bl      fn_80008F60
    bl      OSSetCurrentHeap_thunk
    mr      r3, r30
    bl      OSSetArenaLo
_8007a038:
    lwz     r3, -0x7FB0(r13)
    mr      r4, r29
    bl      OSAlloc
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

#pragma pop
