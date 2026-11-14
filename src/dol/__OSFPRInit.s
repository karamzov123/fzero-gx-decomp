.include "macros.inc"
.file "__OSFPRInit.c"

# Assembly in the original: the Dolphin SDK's OS.c writes this routine as a CodeWarrior `asm`
# function. Evidence (docs/ASM_POLICY.md section 1):
# mfmsr/mtmsr and mfspr HID2 (privileged and special-purpose register access MWCC never emits
# from C), psq_l, and no MWCC prologue or epilogue (a nofralloc body).

# 0x8000A0FC..0x8000A224 | size: 0x128
.text
.balign 4

# .text:0x0 | 0x8000A0FC | size: 0x128
.fn __OSFPRInit, global
/* 8000A0FC 000070FC  7C 60 00 A6 */	mfmsr r3
/* 8000A100 00007100  60 63 20 00 */	ori r3, r3, 0x2000
/* 8000A104 00007104  7C 60 01 24 */	mtmsr r3
/* 8000A108 00007108  7C 78 E2 A6 */	mfspr r3, HID2
/* 8000A10C 0000710C  54 63 1F FF */	extrwi. r3, r3, 1, 2
/* 8000A110 00007110  41 82 00 8C */	beq .L_8000A19C
/* 8000A114 00007114  3C 60 80 1A */	lis r3, ZeroPS@ha
/* 8000A118 00007118  38 63 67 60 */	addi r3, r3, ZeroPS@l
/* 8000A11C 0000711C  E0 03 00 00 */	psq_l f0, 0x0(r3), 0, qr0
/* 8000A120 00007120  10 20 00 90 */	ps_mr f1, f0
/* 8000A124 00007124  10 40 00 90 */	ps_mr f2, f0
/* 8000A128 00007128  10 60 00 90 */	ps_mr f3, f0
/* 8000A12C 0000712C  10 80 00 90 */	ps_mr f4, f0
/* 8000A130 00007130  10 A0 00 90 */	ps_mr f5, f0
/* 8000A134 00007134  10 C0 00 90 */	ps_mr f6, f0
/* 8000A138 00007138  10 E0 00 90 */	ps_mr f7, f0
/* 8000A13C 0000713C  11 00 00 90 */	ps_mr f8, f0
/* 8000A140 00007140  11 20 00 90 */	ps_mr f9, f0
/* 8000A144 00007144  11 40 00 90 */	ps_mr f10, f0
/* 8000A148 00007148  11 60 00 90 */	ps_mr f11, f0
/* 8000A14C 0000714C  11 80 00 90 */	ps_mr f12, f0
/* 8000A150 00007150  11 A0 00 90 */	ps_mr f13, f0
/* 8000A154 00007154  11 C0 00 90 */	ps_mr f14, f0
/* 8000A158 00007158  11 E0 00 90 */	ps_mr f15, f0
/* 8000A15C 0000715C  12 00 00 90 */	ps_mr f16, f0
/* 8000A160 00007160  12 20 00 90 */	ps_mr f17, f0
/* 8000A164 00007164  12 40 00 90 */	ps_mr f18, f0
/* 8000A168 00007168  12 60 00 90 */	ps_mr f19, f0
/* 8000A16C 0000716C  12 80 00 90 */	ps_mr f20, f0
/* 8000A170 00007170  12 A0 00 90 */	ps_mr f21, f0
/* 8000A174 00007174  12 C0 00 90 */	ps_mr f22, f0
/* 8000A178 00007178  12 E0 00 90 */	ps_mr f23, f0
/* 8000A17C 0000717C  13 00 00 90 */	ps_mr f24, f0
/* 8000A180 00007180  13 20 00 90 */	ps_mr f25, f0
/* 8000A184 00007184  13 40 00 90 */	ps_mr f26, f0
/* 8000A188 00007188  13 60 00 90 */	ps_mr f27, f0
/* 8000A18C 0000718C  13 80 00 90 */	ps_mr f28, f0
/* 8000A190 00007190  13 A0 00 90 */	ps_mr f29, f0
/* 8000A194 00007194  13 C0 00 90 */	ps_mr f30, f0
/* 8000A198 00007198  13 E0 00 90 */	ps_mr f31, f0
.L_8000A19C:
/* 8000A19C 0000719C  C8 0D 83 98 */	lfd f0, ZeroF@sda21(r0)
/* 8000A1A0 000071A0  FC 20 00 90 */	fmr f1, f0
/* 8000A1A4 000071A4  FC 40 00 90 */	fmr f2, f0
/* 8000A1A8 000071A8  FC 60 00 90 */	fmr f3, f0
/* 8000A1AC 000071AC  FC 80 00 90 */	fmr f4, f0
/* 8000A1B0 000071B0  FC A0 00 90 */	fmr f5, f0
/* 8000A1B4 000071B4  FC C0 00 90 */	fmr f6, f0
/* 8000A1B8 000071B8  FC E0 00 90 */	fmr f7, f0
/* 8000A1BC 000071BC  FD 00 00 90 */	fmr f8, f0
/* 8000A1C0 000071C0  FD 20 00 90 */	fmr f9, f0
/* 8000A1C4 000071C4  FD 40 00 90 */	fmr f10, f0
/* 8000A1C8 000071C8  FD 60 00 90 */	fmr f11, f0
/* 8000A1CC 000071CC  FD 80 00 90 */	fmr f12, f0
/* 8000A1D0 000071D0  FD A0 00 90 */	fmr f13, f0
/* 8000A1D4 000071D4  FD C0 00 90 */	fmr f14, f0
/* 8000A1D8 000071D8  FD E0 00 90 */	fmr f15, f0
/* 8000A1DC 000071DC  FE 00 00 90 */	fmr f16, f0
/* 8000A1E0 000071E0  FE 20 00 90 */	fmr f17, f0
/* 8000A1E4 000071E4  FE 40 00 90 */	fmr f18, f0
/* 8000A1E8 000071E8  FE 60 00 90 */	fmr f19, f0
/* 8000A1EC 000071EC  FE 80 00 90 */	fmr f20, f0
/* 8000A1F0 000071F0  FE A0 00 90 */	fmr f21, f0
/* 8000A1F4 000071F4  FE C0 00 90 */	fmr f22, f0
/* 8000A1F8 000071F8  FE E0 00 90 */	fmr f23, f0
/* 8000A1FC 000071FC  FF 00 00 90 */	fmr f24, f0
/* 8000A200 00007200  FF 20 00 90 */	fmr f25, f0
/* 8000A204 00007204  FF 40 00 90 */	fmr f26, f0
/* 8000A208 00007208  FF 60 00 90 */	fmr f27, f0
/* 8000A20C 0000720C  FF 80 00 90 */	fmr f28, f0
/* 8000A210 00007210  FF A0 00 90 */	fmr f29, f0
/* 8000A214 00007214  FF C0 00 90 */	fmr f30, f0
/* 8000A218 00007218  FF E0 00 90 */	fmr f31, f0
/* 8000A21C 0000721C  FD FE 05 8E */	mtfsf 255, f0
/* 8000A220 00007220  4E 80 00 20 */	blr
.endfn __OSFPRInit
