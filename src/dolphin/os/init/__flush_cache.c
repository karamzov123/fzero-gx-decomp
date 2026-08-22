typedef unsigned long u32;

#pragma push
#pragma force_active on

asm __declspec(section ".init") void __flush_cache(register void* address,
                                                   register unsigned long size)
{
    nofralloc
    lis     r5, 0xFFFF
    ori     r5, r5, 0xFFF1
    and     r5, r5, r3
    subf    r3, r5, r3
    add     r4, r4, r3
loop:
    dcbst   r0, r5
    sync
    icbi    r0, r5
    addic   r5, r5, 8
    subic.  r4, r4, 8
    bge     loop
    isync
    blr
}

#pragma pop
