.include "macros.inc"
.file "fn_8000AA2C.c"

# Original SDK __OSDBJump assembly: absolute bla 0x60, which MWCC does not
# generate from C. OSExceptionInit copies this one-word trampoline.
# Evidence: retail 0x8000AA2C..0x8000AA30.
.text
.balign 4
.fn fn_8000AA2C, global
.sym __OSDBINTEND, global
    bla 0x60
.endfn fn_8000AA2C
