typedef int BOOL;

asm BOOL OSDisableInterrupts(void)
{
    nofralloc
    mfmsr   r3
    rlwinm  r4, r3, 0, 17, 15
    mtmsr   r4
    extrwi  r3, r3, 1, 16
    blr
}

asm BOOL OSEnableInterrupts(void)
{
    nofralloc
    mfmsr   r3
    ori     r4, r3, 0x8000
    mtmsr   r4
    extrwi  r3, r3, 1, 16
    blr
}

asm BOOL OSRestoreInterrupts(register BOOL level)
{
    nofralloc
    cmpwi   level, 0
    mfmsr   r4
    beq     _disable
    ori     r5, r4, 0x8000
    b       _restore
_disable:
    rlwinm  r5, r4, 0, 17, 15
_restore:
    mtmsr   r5
    extrwi  r3, r4, 1, 16
    blr
}
