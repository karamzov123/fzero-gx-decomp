.include "macros.inc"
.file "OSDefaultExceptionHandler.c"

# Original SDK assembly: saves incoming registers without a compiler prologue,
# reads GQR1-GQR7/DSISR/DAR, and builds a frame for the tail branch.
# These special-register operations cannot be ordinary C.
# Evidence: retail 0x8000AAFC..0x8000AB54.
.text
.balign 4
.fn OSDefaultExceptionHandler, global
    stw r0, 0x0(r4)
    stw r1, 0x4(r4)
    stw r2, 0x8(r4)
    stmw r6, 0x18(r4)
    mfspr r0, GQR1
    stw r0, 0x1A8(r4)
    mfspr r0, GQR2
    stw r0, 0x1AC(r4)
    mfspr r0, GQR3
    stw r0, 0x1B0(r4)
    mfspr r0, GQR4
    stw r0, 0x1B4(r4)
    mfspr r0, GQR5
    stw r0, 0x1B8(r4)
    mfspr r0, GQR6
    stw r0, 0x1BC(r4)
    mfspr r0, GQR7
    stw r0, 0x1C0(r4)
    mfdsisr r5
    mfdar r6
    stwu r1, -8(r1)
    b __OSUnhandledException
.endfn OSDefaultExceptionHandler
