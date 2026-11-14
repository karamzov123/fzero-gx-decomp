.include "macros.inc"
.file "fn_8000AA2C.c"

# Assembly in the original: the Dolphin SDK's OS.c writes this routine as a CodeWarrior `asm`
# function. Evidence (docs/ASM_POLICY.md section 1):
# `bla 0x60`, an absolute branch MWCC never emits from C (the SDK's __OSDBJump: a one-word
# trampoline copied into the exception vectors between __OSDBINTEND and __OSDBJUMPEND).

# 0x8000AA2C..0x8000AA30 | size: 0x4
.text
.balign 4

# .text:0x0 | 0x8000AA2C | size: 0x4
.fn fn_8000AA2C, global
# .text:0x0 | 0x8000AA2C | size: 0x0
.sym __OSDBINTEND, global
/* 8000AA2C 00007A2C  48 00 00 63 */	bla 0x60
.endfn fn_8000AA2C
