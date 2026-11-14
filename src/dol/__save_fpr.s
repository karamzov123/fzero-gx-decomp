.include "macros.inc"
.file "__save_fpr.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# __save_fpr: out-of-line FPR save of the PowerPC EABI runtime (CodeWarrior Runtime.PPCEABI.H, runtime.c).
# Nothing calls __save_fpr by name. A compiler-generated prologue/epilogue points r11 at its save area
# and calls _savefpr_N, which stores fN..f31 (register k at -8 * (32 - k)(r11)) and returns.
# - Known source: runtime.c writes this routine as a function-level `asm` (nofralloc) with one `entry`
#   label per first register (the same in TP, Pikmin 2 and MP4, and in our retail function order).
# - No MWCC prologue/epilogue, and register usage no allocation produces: it touches the caller's
#   f14-f31 through r11, which is not an argument register and which MWCC cannot bind a variable to.
# - The _savefpr_N labels are defined here (global, as in retail); mwld does not generate them. Finding 281
#   (corrected) measured this: the link warning it recorded came from carve's ldscript.tpl alias.

# 0x800797C0..0x8007980C | size: 0x4C
.text
.balign 4

# .text:0x0 | 0x800797C0 | size: 0x4C
.fn __save_fpr, global
# .text:0x0 | 0x800797C0 | size: 0x0
.sym _savefpr_14, global
/* 800797C0 000767C0  D9 CB FF 70 */	stfd f14, -0x90(r11)
# .text:0x4 | 0x800797C4 | size: 0x0
.sym _savefpr_15, global
/* 800797C4 000767C4  D9 EB FF 78 */	stfd f15, -0x88(r11)
# .text:0x8 | 0x800797C8 | size: 0x0
.sym _savefpr_16, global
/* 800797C8 000767C8  DA 0B FF 80 */	stfd f16, -0x80(r11)
# .text:0xC | 0x800797CC | size: 0x0
.sym _savefpr_17, global
/* 800797CC 000767CC  DA 2B FF 88 */	stfd f17, -0x78(r11)
# .text:0x10 | 0x800797D0 | size: 0x0
.sym _savefpr_18, global
/* 800797D0 000767D0  DA 4B FF 90 */	stfd f18, -0x70(r11)
# .text:0x14 | 0x800797D4 | size: 0x0
.sym _savefpr_19, global
/* 800797D4 000767D4  DA 6B FF 98 */	stfd f19, -0x68(r11)
# .text:0x18 | 0x800797D8 | size: 0x0
.sym _savefpr_20, global
/* 800797D8 000767D8  DA 8B FF A0 */	stfd f20, -0x60(r11)
# .text:0x1C | 0x800797DC | size: 0x0
.sym _savefpr_21, global
/* 800797DC 000767DC  DA AB FF A8 */	stfd f21, -0x58(r11)
# .text:0x20 | 0x800797E0 | size: 0x0
.sym _savefpr_22, global
/* 800797E0 000767E0  DA CB FF B0 */	stfd f22, -0x50(r11)
# .text:0x24 | 0x800797E4 | size: 0x0
.sym _savefpr_23, global
/* 800797E4 000767E4  DA EB FF B8 */	stfd f23, -0x48(r11)
# .text:0x28 | 0x800797E8 | size: 0x0
.sym _savefpr_24, global
/* 800797E8 000767E8  DB 0B FF C0 */	stfd f24, -0x40(r11)
# .text:0x2C | 0x800797EC | size: 0x0
.sym _savefpr_25, global
/* 800797EC 000767EC  DB 2B FF C8 */	stfd f25, -0x38(r11)
# .text:0x30 | 0x800797F0 | size: 0x0
.sym _savefpr_26, global
/* 800797F0 000767F0  DB 4B FF D0 */	stfd f26, -0x30(r11)
# .text:0x34 | 0x800797F4 | size: 0x0
.sym _savefpr_27, global
/* 800797F4 000767F4  DB 6B FF D8 */	stfd f27, -0x28(r11)
# .text:0x38 | 0x800797F8 | size: 0x0
.sym _savefpr_28, global
/* 800797F8 000767F8  DB 8B FF E0 */	stfd f28, -0x20(r11)
# .text:0x3C | 0x800797FC | size: 0x0
.sym _savefpr_29, global
/* 800797FC 000767FC  DB AB FF E8 */	stfd f29, -0x18(r11)
# .text:0x40 | 0x80079800 | size: 0x0
.sym _savefpr_30, global
/* 80079800 00076800  DB CB FF F0 */	stfd f30, -0x10(r11)
# .text:0x44 | 0x80079804 | size: 0x0
.sym _savefpr_31, global
/* 80079804 00076804  DB EB FF F8 */	stfd f31, -0x8(r11)
/* 80079808 00076808  4E 80 00 20 */	blr
.endfn __save_fpr
