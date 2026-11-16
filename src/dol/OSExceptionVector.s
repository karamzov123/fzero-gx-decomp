.include "macros.inc"
.file "OSExceptionVector.c"

# Original SDK assembly: privileged exception SPRs and rfi, no compiler
# prologue. OSExceptionInit copies and patches the labelled fragment.
# Evidence: retail 0x8000AA60..0x8000AAFC.
.text
.balign 4
.fn OSExceptionVector, local
.sym __OSEVStart, global
    mtsprg 0, r4
    lwz r4, 0xC0(r0)
    stw r3, 0xC(r4)
    mfsprg r3, 0
    stw r3, 0x10(r4)
    stw r5, 0x14(r4)
    lhz r3, 0x1A2(r4)
    ori r3, r3, 2
    sth r3, 0x1A2(r4)
    mfcr r3
    stw r3, 0x80(r4)
    mflr r3
    stw r3, 0x84(r4)
    mfctr r3
    stw r3, 0x88(r4)
    mfxer r3
    stw r3, 0x8C(r4)
    mfsrr0 r3
    stw r3, 0x198(r4)
    mfsrr1 r3
    stw r3, 0x19C(r4)
    mr r5, r3
.sym __DBVECTOR, global
    nop
    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3
.sym __OSEVSetNumber, global
    li r3, 0
    lwz r4, 0xD4(r0)
    rlwinm. r5, r5, 0, 30, 30
    bne .L_recoverable
    lis r5, OSDefaultExceptionHandler@ha
    addi r5, r5, OSDefaultExceptionHandler@l
    mtsrr0 r5
    rfi
.L_recoverable:
    rlwinm r5, r3, 2, 22, 29
    lwz r5, 0x3000(r5)
    mtsrr0 r5
    rfi
.sym __OSEVEnd, global
    nop
.endfn OSExceptionVector
