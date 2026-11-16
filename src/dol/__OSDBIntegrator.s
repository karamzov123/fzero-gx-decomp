.include "macros.inc"
.file "__OSDBIntegrator.c"

# Original SDK assembly: fixed low-memory LR save slot, privileged mtmsr,
# and no compiler prologue. OSExceptionInit copies this position-independent
# fragment to 0x60. Evidence: retail 0x8000AA08..0x8000AA2C.
.text
.balign 4
.fn __OSDBIntegrator, local
.sym __OSDBINTSTART, global
    li r5, 0x40
    mflr r3
    stw r3, 0xC(r5)
    lwz r3, 0x8(r5)
    oris r3, r3, 0x8000
    mtlr r3
    li r3, 0x30
    mtmsr r3
    blr
.endfn __OSDBIntegrator
