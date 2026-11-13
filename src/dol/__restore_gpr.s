.include "macros.inc"
.file "__restore_gpr.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# __restore_gpr: out-of-line GPR restore of the PowerPC EABI runtime (CodeWarrior Runtime.PPCEABI.H, runtime.c).
# Nothing calls __restore_gpr by name. A compiler-generated prologue/epilogue points r11 at its save area
# and calls _restgpr_N, which loads rN..r31 (register k from -4 * (32 - k)(r11)) and returns.
# - Known source: runtime.c writes this routine as a function-level `asm` (nofralloc) with one `entry`
#   label per first register (the same in TP, Pikmin 2 and MP4, and in our retail function order).
# - No MWCC prologue/epilogue, and register usage no allocation produces: it touches the caller's
#   r14-r31 through r11, which is not an argument register and which MWCC cannot bind a variable to.
# - The _restgpr_N labels are defined here (global, as in retail); mwld does not generate them. Finding 281
#   (corrected) measured this: the link warning it recorded came from carve's ldscript.tpl alias.

# 0x800798A4..0x800798F0 | size: 0x4C
.text
.balign 4

# .text:0x0 | 0x800798A4 | size: 0x4C
.fn __restore_gpr, global
# .text:0x0 | 0x800798A4 | size: 0x0
.sym _restgpr_14, global
/* 800798A4 000768A4  81 CB FF B8 */	lwz r14, -0x48(r11)
# .text:0x4 | 0x800798A8 | size: 0x0
.sym _restgpr_15, global
/* 800798A8 000768A8  81 EB FF BC */	lwz r15, -0x44(r11)
# .text:0x8 | 0x800798AC | size: 0x0
.sym _restgpr_16, global
/* 800798AC 000768AC  82 0B FF C0 */	lwz r16, -0x40(r11)
# .text:0xC | 0x800798B0 | size: 0x0
.sym _restgpr_17, global
/* 800798B0 000768B0  82 2B FF C4 */	lwz r17, -0x3c(r11)
# .text:0x10 | 0x800798B4 | size: 0x0
.sym _restgpr_18, global
/* 800798B4 000768B4  82 4B FF C8 */	lwz r18, -0x38(r11)
# .text:0x14 | 0x800798B8 | size: 0x0
.sym _restgpr_19, global
/* 800798B8 000768B8  82 6B FF CC */	lwz r19, -0x34(r11)
# .text:0x18 | 0x800798BC | size: 0x0
.sym _restgpr_20, global
/* 800798BC 000768BC  82 8B FF D0 */	lwz r20, -0x30(r11)
# .text:0x1C | 0x800798C0 | size: 0x0
.sym _restgpr_21, global
/* 800798C0 000768C0  82 AB FF D4 */	lwz r21, -0x2c(r11)
# .text:0x20 | 0x800798C4 | size: 0x0
.sym _restgpr_22, global
/* 800798C4 000768C4  82 CB FF D8 */	lwz r22, -0x28(r11)
# .text:0x24 | 0x800798C8 | size: 0x0
.sym _restgpr_23, global
/* 800798C8 000768C8  82 EB FF DC */	lwz r23, -0x24(r11)
# .text:0x28 | 0x800798CC | size: 0x0
.sym _restgpr_24, global
/* 800798CC 000768CC  83 0B FF E0 */	lwz r24, -0x20(r11)
# .text:0x2C | 0x800798D0 | size: 0x0
.sym _restgpr_25, global
/* 800798D0 000768D0  83 2B FF E4 */	lwz r25, -0x1c(r11)
# .text:0x30 | 0x800798D4 | size: 0x0
.sym _restgpr_26, global
/* 800798D4 000768D4  83 4B FF E8 */	lwz r26, -0x18(r11)
# .text:0x34 | 0x800798D8 | size: 0x0
.sym _restgpr_27, global
/* 800798D8 000768D8  83 6B FF EC */	lwz r27, -0x14(r11)
# .text:0x38 | 0x800798DC | size: 0x0
.sym _restgpr_28, global
/* 800798DC 000768DC  83 8B FF F0 */	lwz r28, -0x10(r11)
# .text:0x3C | 0x800798E0 | size: 0x0
.sym _restgpr_29, global
/* 800798E0 000768E0  83 AB FF F4 */	lwz r29, -0xc(r11)
# .text:0x40 | 0x800798E4 | size: 0x0
.sym _restgpr_30, global
/* 800798E4 000768E4  83 CB FF F8 */	lwz r30, -0x8(r11)
# .text:0x44 | 0x800798E8 | size: 0x0
.sym _restgpr_31, global
/* 800798E8 000768E8  83 EB FF FC */	lwz r31, -0x4(r11)
/* 800798EC 000768EC  4E 80 00 20 */	blr
.endfn __restore_gpr
