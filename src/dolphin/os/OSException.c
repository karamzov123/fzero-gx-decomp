#pragma push
#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern void __OSUnhandledException(int exception, void *context, u32 dsisr, u32 dar);
extern void OSDefaultExceptionHandler(int exception, void *context);
extern void __OSEVStart(void);
extern void __OSEVEnd(void);
extern void __OSEVSetNumber(void);
extern void __DBVECTOR(void);
extern void __OSDBJUMPEND(void);

// OSExceptionTable's own storage is 4 bytes (one pointer): it holds the
// address of the real handler-pointer table, not the table itself.
extern void** OSExceptionTable;
asm void __OSSetExceptionHandler(register u8 index, register void *handler)
{
    nofralloc
entry __OSDBJUMPEND
    clrlwi  r0, r3, 24
    lwz	r3, OSExceptionTable
    slwi    r0, r0, 2
    add     r5, r3, r0
    lwz     r3, 0(r5)
    stw     r4, 0(r5)
    blr
}

// provenance: original __OSGetExceptionHandler
void* __OSGetExceptionHandler(u8 index)
{
    return OSExceptionTable[index];
}

asm void OSExceptionVector(void)
{
    nofralloc
entry __OSEVStart
    mtsprg  0, r4
    lwz     r4, 0xC0(r0)
    stw     r3, 0xC(r4)
    mfsprg  r3, 0
    stw     r3, 0x10(r4)
    stw     r5, 0x14(r4)
    lhz     r3, 0x1A2(r4)
    ori     r3, r3, 2
    sth     r3, 0x1A2(r4)
    mfcr    r3
    stw     r3, 0x80(r4)
    mflr    r3
    stw     r3, 0x84(r4)
    mfctr   r3
    stw     r3, 0x88(r4)
    mfxer   r3
    stw     r3, 0x8C(r4)
    mfsrr0  r3
    stw     r3, 0x198(r4)
    mfsrr1  r3
    stw     r3, 0x19C(r4)
    mr      r5, r3
entry __DBVECTOR
    nop
    mfmsr   r3
    ori     r3, r3, 0x30
    mtsrr1  r3
entry __OSEVSetNumber
    li      r3, 0
    lwz     r4, 0xD4(r0)
    rlwinm. r5, r5, 0, 30, 30
    bne     recoverable
    lis     r5, OSDefaultExceptionHandler@ha
    addi    r5, r5, OSDefaultExceptionHandler@l
    mtsrr0  r5
    rfi
recoverable:
    clrlslwi r5, r3, 24, 2
    lwz     r5, 0x3000(r5)
    mtsrr0  r5
    rfi
entry __OSEVEnd
    nop
}

asm void OSDefaultExceptionHandler(register int exception, register void *context)
{
    nofralloc
    stw     r0, 0(r4)
    stw     r1, 4(r4)
    stw     r2, 8(r4)
    stmw    r6, 0x18(r4)
    mfspr   r0, 913
    stw     r0, 0x1A8(r4)
    mfspr   r0, 914
    stw     r0, 0x1AC(r4)
    mfspr   r0, 915
    stw     r0, 0x1B0(r4)
    mfspr   r0, 916
    stw     r0, 0x1B4(r4)
    mfspr   r0, 917
    stw     r0, 0x1B8(r4)
    mfspr   r0, 918
    stw     r0, 0x1BC(r4)
    mfspr   r0, 919
    stw     r0, 0x1C0(r4)
    mfspr   r5, 18
    mfspr   r6, 19
    stwu    r1, -8(r1)
    b       __OSUnhandledException
}
#pragma pop
