typedef unsigned int u32;
#pragma push
#pragma force_active on
// provenance: original

// provenance: original
void DCEnable(void)
{
    asm
    {
    sync
    mfspr    r3, 1008
    ori      r3, r3, 0x4000
    mtspr    1008, r3
    }
}

asm void DCInvalidateRange(register void *addr, register u32 nBytes)
{
    nofralloc
    cmplwi   r4, 0
    blelr
    clrlwi   r5, r3, 27
    add      r4, r4, r5
    addi     r4, r4, 0x1f
    srwi     r4, r4, 5
    mtctr    r4
L8000B644:
    dcbi     r0, r3
    addi     r3, r3, 0x20
    bdnz     L8000B644
    blr
}

asm void DCFlushRange(register void *addr, register u32 nBytes)
{
    nofralloc
    cmplwi   r4, 0
    blelr
    clrlwi   r5, r3, 27
    add      r4, r4, r5
    addi     r4, r4, 0x1f
    srwi     r4, r4, 5
    mtctr    r4
L8000B670:
    dcbf     r0, r3
    addi     r3, r3, 0x20
    bdnz     L8000B670
    sc
    blr
}

asm void DCStoreRange(register void *addr, register u32 nBytes)
{
    nofralloc
    cmplwi   r4, 0
    blelr
    clrlwi   r5, r3, 27
    add      r4, r4, r5
    addi     r4, r4, 0x1f
    srwi     r4, r4, 5
    mtctr    r4
L8000B6A0:
    dcbst    r0, r3
    addi     r3, r3, 0x20
    bdnz     L8000B6A0
    sc
    blr
}

asm void DCFlushRangeNoSync(register void *addr, register u32 nBytes)
{
    nofralloc
    cmplwi   r4, 0
    blelr
    clrlwi   r5, r3, 27
    add      r4, r4, r5
    addi     r4, r4, 0x1f
    srwi     r4, r4, 5
    mtctr    r4
L8000B6D0:
    dcbf     r0, r3
    addi     r3, r3, 0x20
    bdnz     L8000B6D0
    blr
}

asm void ICInvalidateRange(register void *addr, register u32 nBytes)
{
    nofralloc
    cmplwi   r4, 0
    blelr
    clrlwi   r5, r3, 27
    add      r4, r4, r5
    addi     r4, r4, 0x1f
    srwi     r4, r4, 5
    mtctr    r4
L8000B6FC:
    icbi     r0, r3
    addi     r3, r3, 0x20
    bdnz     L8000B6FC
    sync
    isync
    blr
}

// provenance: original
void ICFlashInvalidate(void)
{
    asm
    {
    mfspr    r3, 1008
    ori      r3, r3, 0x800
    mtspr    1008, r3
    }
}

// provenance: original
void ICEnable(void)
{
    asm
    {
    isync
    mfspr    r3, 1008
    ori      r3, r3, 0x8000
    mtspr    1008, r3
    }
}
#pragma pop
