.include "macros.inc"
.file "__save_gpr.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# __save_gpr: out-of-line GPR save of the PowerPC EABI runtime (CodeWarrior Runtime.PPCEABI.H, runtime.c).
# Nothing calls __save_gpr by name. A compiler-generated prologue/epilogue points r11 at its save area
# and calls _savegpr_N, which stores rN..r31 (register k at -4 * (32 - k)(r11)) and returns.
# - Known source: runtime.c writes this routine as a function-level `asm` (nofralloc) with one `entry`
#   label per first register (the same in TP, Pikmin 2 and MP4, and in our retail function order).
# - No MWCC prologue/epilogue, and register usage no allocation produces: it touches the caller's
#   r14-r31 through r11, which is not an argument register and which MWCC cannot bind a variable to.
# - The _savegpr_N labels are defined here (global, as in retail); mwld does not generate them. Finding 281
#   (corrected) measured this: the link warning it recorded came from carve's ldscript.tpl alias.

# 0x80079858..0x800798A4 | size: 0x4C
.text
.balign 4

# .text:0x0 | 0x80079858 | size: 0x4C
.fn __save_gpr, global
# .text:0x0 | 0x80079858 | size: 0x0
.sym _savegpr_14, global
/* 80079858 00076858  91 CB FF B8 */	stw r14, -0x48(r11)
# .text:0x4 | 0x8007985C | size: 0x0
.sym _savegpr_15, global
/* 8007985C 0007685C  91 EB FF BC */	stw r15, -0x44(r11)
# .text:0x8 | 0x80079860 | size: 0x0
.sym _savegpr_16, global
/* 80079860 00076860  92 0B FF C0 */	stw r16, -0x40(r11)
# .text:0xC | 0x80079864 | size: 0x0
.sym _savegpr_17, global
/* 80079864 00076864  92 2B FF C4 */	stw r17, -0x3c(r11)
# .text:0x10 | 0x80079868 | size: 0x0
.sym _savegpr_18, global
/* 80079868 00076868  92 4B FF C8 */	stw r18, -0x38(r11)
# .text:0x14 | 0x8007986C | size: 0x0
.sym _savegpr_19, global
/* 8007986C 0007686C  92 6B FF CC */	stw r19, -0x34(r11)
# .text:0x18 | 0x80079870 | size: 0x0
.sym _savegpr_20, global
/* 80079870 00076870  92 8B FF D0 */	stw r20, -0x30(r11)
# .text:0x1C | 0x80079874 | size: 0x0
.sym _savegpr_21, global
/* 80079874 00076874  92 AB FF D4 */	stw r21, -0x2c(r11)
# .text:0x20 | 0x80079878 | size: 0x0
.sym _savegpr_22, global
/* 80079878 00076878  92 CB FF D8 */	stw r22, -0x28(r11)
# .text:0x24 | 0x8007987C | size: 0x0
.sym _savegpr_23, global
/* 8007987C 0007687C  92 EB FF DC */	stw r23, -0x24(r11)
# .text:0x28 | 0x80079880 | size: 0x0
.sym _savegpr_24, global
/* 80079880 00076880  93 0B FF E0 */	stw r24, -0x20(r11)
# .text:0x2C | 0x80079884 | size: 0x0
.sym _savegpr_25, global
/* 80079884 00076884  93 2B FF E4 */	stw r25, -0x1c(r11)
# .text:0x30 | 0x80079888 | size: 0x0
.sym _savegpr_26, global
/* 80079888 00076888  93 4B FF E8 */	stw r26, -0x18(r11)
# .text:0x34 | 0x8007988C | size: 0x0
.sym _savegpr_27, global
/* 8007988C 0007688C  93 6B FF EC */	stw r27, -0x14(r11)
# .text:0x38 | 0x80079890 | size: 0x0
.sym _savegpr_28, global
/* 80079890 00076890  93 8B FF F0 */	stw r28, -0x10(r11)
# .text:0x3C | 0x80079894 | size: 0x0
.sym _savegpr_29, global
/* 80079894 00076894  93 AB FF F4 */	stw r29, -0xc(r11)
# .text:0x40 | 0x80079898 | size: 0x0
.sym _savegpr_30, global
/* 80079898 00076898  93 CB FF F8 */	stw r30, -0x8(r11)
# .text:0x44 | 0x8007989C | size: 0x0
.sym _savegpr_31, global
/* 8007989C 0007689C  93 EB FF FC */	stw r31, -0x4(r11)
/* 800798A0 000768A0  4E 80 00 20 */	blr
.endfn __save_gpr
