.include "macros.inc"
.file "__restore_fpr.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# __restore_fpr: out-of-line FPR restore of the PowerPC EABI runtime (CodeWarrior Runtime.PPCEABI.H, runtime.c).
# Nothing calls __restore_fpr by name. A compiler-generated prologue/epilogue points r11 at its save area
# and calls _restfpr_N, which loads fN..f31 (register k from -8 * (32 - k)(r11)) and returns.
# - Known source: runtime.c writes this routine as a function-level `asm` (nofralloc) with one `entry`
#   label per first register (the same in TP, Pikmin 2 and MP4, and in our retail function order).
# - No MWCC prologue/epilogue, and register usage no allocation produces: it touches the caller's
#   f14-f31 through r11, which is not an argument register and which MWCC cannot bind a variable to.
# - The _restfpr_N labels are defined here (global, as in retail); mwld does not generate them. Finding 281
#   (corrected) measured this: the link warning it recorded came from carve's ldscript.tpl alias.

# 0x8007980C..0x80079858 | size: 0x4C
.text
.balign 4

# .text:0x0 | 0x8007980C | size: 0x4C
.fn __restore_fpr, global
# .text:0x0 | 0x8007980C | size: 0x0
.sym _restfpr_14, global
/* 8007980C 0007680C  C9 CB FF 70 */	lfd f14, -0x90(r11)
# .text:0x4 | 0x80079810 | size: 0x0
.sym _restfpr_15, global
/* 80079810 00076810  C9 EB FF 78 */	lfd f15, -0x88(r11)
# .text:0x8 | 0x80079814 | size: 0x0
.sym _restfpr_16, global
/* 80079814 00076814  CA 0B FF 80 */	lfd f16, -0x80(r11)
# .text:0xC | 0x80079818 | size: 0x0
.sym _restfpr_17, global
/* 80079818 00076818  CA 2B FF 88 */	lfd f17, -0x78(r11)
# .text:0x10 | 0x8007981C | size: 0x0
.sym _restfpr_18, global
/* 8007981C 0007681C  CA 4B FF 90 */	lfd f18, -0x70(r11)
# .text:0x14 | 0x80079820 | size: 0x0
.sym _restfpr_19, global
/* 80079820 00076820  CA 6B FF 98 */	lfd f19, -0x68(r11)
# .text:0x18 | 0x80079824 | size: 0x0
.sym _restfpr_20, global
/* 80079824 00076824  CA 8B FF A0 */	lfd f20, -0x60(r11)
# .text:0x1C | 0x80079828 | size: 0x0
.sym _restfpr_21, global
/* 80079828 00076828  CA AB FF A8 */	lfd f21, -0x58(r11)
# .text:0x20 | 0x8007982C | size: 0x0
.sym _restfpr_22, global
/* 8007982C 0007682C  CA CB FF B0 */	lfd f22, -0x50(r11)
# .text:0x24 | 0x80079830 | size: 0x0
.sym _restfpr_23, global
/* 80079830 00076830  CA EB FF B8 */	lfd f23, -0x48(r11)
# .text:0x28 | 0x80079834 | size: 0x0
.sym _restfpr_24, global
/* 80079834 00076834  CB 0B FF C0 */	lfd f24, -0x40(r11)
# .text:0x2C | 0x80079838 | size: 0x0
.sym _restfpr_25, global
/* 80079838 00076838  CB 2B FF C8 */	lfd f25, -0x38(r11)
# .text:0x30 | 0x8007983C | size: 0x0
.sym _restfpr_26, global
/* 8007983C 0007683C  CB 4B FF D0 */	lfd f26, -0x30(r11)
# .text:0x34 | 0x80079840 | size: 0x0
.sym _restfpr_27, global
/* 80079840 00076840  CB 6B FF D8 */	lfd f27, -0x28(r11)
# .text:0x38 | 0x80079844 | size: 0x0
.sym _restfpr_28, global
/* 80079844 00076844  CB 8B FF E0 */	lfd f28, -0x20(r11)
# .text:0x3C | 0x80079848 | size: 0x0
.sym _restfpr_29, global
/* 80079848 00076848  CB AB FF E8 */	lfd f29, -0x18(r11)
# .text:0x40 | 0x8007984C | size: 0x0
.sym _restfpr_30, global
/* 8007984C 0007684C  CB CB FF F0 */	lfd f30, -0x10(r11)
# .text:0x44 | 0x80079850 | size: 0x0
.sym _restfpr_31, global
/* 80079850 00076850  CB EB FF F8 */	lfd f31, -0x8(r11)
/* 80079854 00076854  4E 80 00 20 */	blr
.endfn __restore_fpr
