.include "macros.inc"
.file "lbl_8006D118.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Stores sqrt(x) to *out and returns 1/sqrt(x).
# f1 is the result of approx_rsqrt. Only the f0 copy of x gets the multiply.
# Zero, negative or denormal x, and +inf: *out = 0, and the return value is +inf.
# -inf: *out = +inf, and the return value is 0. NaN: both results are NaN.
# - mcrfs reads the FPSCR class bits. MWCC does not emit mcrfs from C.
# - The routine does not branch to float_return_values for special values. It writes both results
#   as bit patterns. It writes the return value to the locked-cache scratch word at 0xE0000098
#   and loads it into f1.
# - It calls approx_rsqrt with a hand-saved link register (mflr r5; bl; mtlr r5) and no frame.
#   x stays in f0 across the call. A call from C always gets a frame.
# - Source: Super Monkey Ball (same engine) has only an asm version, func_8000716C,
#   under `#ifdef __MWERKS__`:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L208-L247

# 0x8006D118..0x8006D188 | size: 0x70
.text
.balign 4

# .text:0x0 | 0x8006D118 | size: 0x70
.fn lbl_8006D118, global
/* 8006D118 0006A118  FC 00 08 18 */	frsp f0, f1
/* 8006D11C 0006A11C  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D120 0006A120  FC 90 00 80 */	mcrfs cr1, cr4
/* 8006D124 0006A124  FC 0C 00 80 */	mcrfs cr0, cr3
/* 8006D128 0006A128  C0 44 01 A0 */	lfs f2, 0x1a0(r4)
/* 8006D12C 0006A12C  41 87 00 24 */	bso cr1, .L_8006D150
/* 8006D130 0006A130  41 83 00 34 */	bso .L_8006D164
/* 8006D134 0006A134  40 85 00 30 */	ble cr1, .L_8006D164
/* 8006D138 0006A138  7C A8 02 A6 */	mflr r5
/* 8006D13C 0006A13C  4B FF FF 4D */	bl approx_rsqrt
/* 8006D140 0006A140  7C A8 03 A6 */	mtlr r5
/* 8006D144 0006A144  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006D148 0006A148  D0 03 00 00 */	stfs f0, 0x0(r3)
/* 8006D14C 0006A14C  4E 80 00 20 */	blr
.L_8006D150:
/* 8006D150 0006A150  41 A5 00 14 */	bgt+ cr1, .L_8006D164
/* 8006D154 0006A154  41 A4 00 1C */	blt+ cr1, .L_8006D170
/* 8006D158 0006A158  3C A0 7F FF */	lis r5, 0x7fff
/* 8006D15C 0006A15C  3C C0 7F FF */	lis r6, 0x7fff
/* 8006D160 0006A160  48 00 00 18 */	b .L_8006D178
.L_8006D164:
/* 8006D164 0006A164  38 A0 00 00 */	li r5, 0x0
/* 8006D168 0006A168  3C C0 7F 80 */	lis r6, 0x7f80
/* 8006D16C 0006A16C  48 00 00 0C */	b .L_8006D178
.L_8006D170:
/* 8006D170 0006A170  3C A0 7F 80 */	lis r5, 0x7f80
/* 8006D174 0006A174  38 C0 00 00 */	li r6, 0x0
.L_8006D178:
/* 8006D178 0006A178  90 A3 00 00 */	stw r5, 0x0(r3)
/* 8006D17C 0006A17C  90 C4 00 98 */	stw r6, 0x98(r4)
/* 8006D180 0006A180  C0 24 00 98 */	lfs f1, 0x98(r4)
/* 8006D184 0006A184  4E 80 00 20 */	blr
.endfn lbl_8006D118
