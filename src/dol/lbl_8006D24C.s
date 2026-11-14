.include "macros.inc"
.file "lbl_8006D24C.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# atan2(y, x) returning an s16 angle; entry lbl_8006D2AC is atan of one operand (called by
# lbl_8006D3D0, lbl_8006D46C and main_rel's font.c). The atan table lbl_80152860 is addressed with
# addis/addi on an offset already in r4 (config.yml add_relocations records the reference).
# - Saves and restores the whole condition register (mfcr/mtcrf 255), classifies operands with mcrfs
#   and builds the octant from cr bits; the second entry follows an unconditional `b`.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D24C..0x8006D3D0 | size: 0x184
.text
.balign 4

# .text:0x0 | 0x8006D24C | size: 0x184
.fn lbl_8006D24C, global
/* 8006D24C 0006A24C  7C C0 00 26 */	mfcr r6
/* 8006D250 0006A250  FC 40 10 18 */	frsp f2, f2
/* 8006D254 0006A254  FF 90 00 80 */	mcrfs cr7, cr4
/* 8006D258 0006A258  FF 0C 00 80 */	mcrfs cr6, cr3
/* 8006D25C 0006A25C  FC 20 08 18 */	frsp f1, f1
/* 8006D260 0006A260  41 9F 01 00 */	bso cr7, .L_8006D360
/* 8006D264 0006A264  FE 90 00 80 */	mcrfs cr5, cr4
/* 8006D268 0006A268  FE 0C 00 80 */	mcrfs cr4, cr3
/* 8006D26C 0006A26C  41 97 00 FC */	bso cr5, .L_8006D368
/* 8006D270 0006A270  40 BE 00 0C */	bne+ cr7, .L_8006D27C
/* 8006D274 0006A274  40 B6 00 08 */	bne+ cr5, .L_8006D27C
/* 8006D278 0006A278  48 00 01 34 */	b .L_8006D3AC
.L_8006D27C:
/* 8006D27C 0006A27C  4D 94 E1 82 */	crxor cr3lt, cr5lt, cr7lt
/* 8006D280 0006A280  FC 60 12 10 */	fabs f3, f2
/* 8006D284 0006A284  FC 80 0A 10 */	fabs f4, f1
/* 8006D288 0006A288  FC 03 20 00 */	fcmpu cr0, f3, f4
/* 8006D28C 0006A28C  41 82 01 28 */	beq .L_8006D3B4
/* 8006D290 0006A290  41 81 00 0C */	bgt .L_8006D29C
/* 8006D294 0006A294  FC 60 0A 10 */	fabs f3, f1
/* 8006D298 0006A298  FC 80 12 10 */	fabs f4, f2
.L_8006D29C:
/* 8006D29C 0006A29C  4D E0 03 82 */	crmove cr3un, lt
/* 8006D2A0 0006A2A0  3C E0 E0 00 */	lis r7, 0xe000
/* 8006D2A4 0006A2A4  EC A4 18 24 */	fdivs f5, f4, f3
/* 8006D2A8 0006A2A8  48 00 00 48 */	b .L_8006D2F0
# .text:0x60 | 0x8006D2AC | size: 0x0
.sym lbl_8006D2AC, global
/* 8006D2AC 0006A2AC  FC 20 08 18 */	frsp f1, f1
/* 8006D2B0 0006A2B0  3C E0 E0 00 */	lis r7, 0xe000
/* 8006D2B4 0006A2B4  FE 90 00 80 */	mcrfs cr5, cr4
/* 8006D2B8 0006A2B8  FE 0C 00 80 */	mcrfs cr4, cr3
/* 8006D2BC 0006A2BC  40 B7 00 10 */	bns+ cr5, .L_8006D2CC
/* 8006D2C0 0006A2C0  4D 33 BA 02 */	crand cr2gt, cr4un, cr5un
/* 8006D2C4 0006A2C4  41 89 00 E8 */	bgt cr2, .L_8006D3AC
/* 8006D2C8 0006A2C8  48 00 00 C0 */	b .L_8006D388
.L_8006D2CC:
/* 8006D2CC 0006A2CC  41 96 00 E0 */	beq cr5, .L_8006D3AC
/* 8006D2D0 0006A2D0  C0 67 01 9C */	lfs f3, 0x19c(r7)
/* 8006D2D4 0006A2D4  FC A0 0A 10 */	fabs f5, f1
/* 8006D2D8 0006A2D8  4D 94 A3 82 */	crmove cr3lt, cr5lt
/* 8006D2DC 0006A2DC  FC 05 18 00 */	fcmpu cr0, f5, f3
/* 8006D2E0 0006A2E0  41 82 00 D4 */	beq .L_8006D3B4
/* 8006D2E4 0006A2E4  41 80 00 08 */	blt .L_8006D2EC
/* 8006D2E8 0006A2E8  EC A3 28 24 */	fdivs f5, f3, f5
.L_8006D2EC:
/* 8006D2EC 0006A2EC  4D E1 0B 82 */	crmove cr3un, gt
.L_8006D2F0:
/* 8006D2F0 0006A2F0  D0 A7 00 98 */	stfs f5, 0x98(r7)
/* 8006D2F4 0006A2F4  80 67 00 98 */	lwz r3, 0x98(r7)
/* 8006D2F8 0006A2F8  54 65 02 7E */	clrlwi r5, r3, 9
/* 8006D2FC 0006A2FC  64 A5 00 80 */	oris r5, r5, 0x80
/* 8006D300 0006A300  54 64 4E 3E */	extrwi r4, r3, 8, 1
/* 8006D304 0006A304  20 84 00 87 */	subfic r4, r4, 0x87
/* 8006D308 0006A308  54 80 00 35 */	clrrwi. r0, r4, 5
/* 8006D30C 0006A30C  41 82 00 08 */	beq .L_8006D314
/* 8006D310 0006A310  60 84 00 20 */	ori r4, r4, 0x20
.L_8006D314:
/* 8006D314 0006A314  7C A4 24 30 */	srw r4, r5, r4
/* 8006D318 0006A318  54 84 04 78 */	rlwinm r4, r4, 0, 17, 28
/* 8006D31C 0006A31C  3C 84 80 15 */	addis r4, r4, lbl_80152860@ha
/* 8006D320 0006A320  38 84 28 60 */	addi r4, r4, lbl_80152860@l
/* 8006D324 0006A324  C0 64 00 00 */	lfs f3, 0x0(r4)
/* 8006D328 0006A328  C0 84 00 04 */	lfs f4, 0x4(r4)
/* 8006D32C 0006A32C  EC A5 20 FA */	fmadds f5, f5, f3, f4
/* 8006D330 0006A330  FC A0 28 1C */	fctiw f5, f5
/* 8006D334 0006A334  D8 A7 00 98 */	stfd f5, 0x98(r7)
/* 8006D338 0006A338  80 67 00 9C */	lwz r3, 0x9c(r7)
/* 8006D33C 0006A33C  40 8F 00 08 */	bns cr3, .L_8006D344
/* 8006D340 0006A340  20 63 40 00 */	subfic r3, r3, 0x4000
.L_8006D344:
/* 8006D344 0006A344  40 8C 00 10 */	bge cr3, .L_8006D354
/* 8006D348 0006A348  7C 63 00 D0 */	neg r3, r3
/* 8006D34C 0006A34C  38 63 80 00 */	addi r3, r3, -0x8000
/* 8006D350 0006A350  3C 63 00 01 */	addis r3, r3, 0x1
.L_8006D354:
/* 8006D354 0006A354  40 94 00 70 */	bge cr5, .L_8006D3C4
/* 8006D358 0006A358  38 63 80 00 */	addi r3, r3, -0x8000
/* 8006D35C 0006A35C  48 00 00 68 */	b .L_8006D3C4
.L_8006D360:
/* 8006D360 0006A360  FE 90 00 80 */	mcrfs cr5, cr4
/* 8006D364 0006A364  FE 0C 00 80 */	mcrfs cr4, cr3
.L_8006D368:
/* 8006D368 0006A368  4D 1B FA 02 */	crand cr2lt, cr6un, cr7un
/* 8006D36C 0006A36C  41 88 00 40 */	blt cr2, .L_8006D3AC
/* 8006D370 0006A370  4D 33 BA 02 */	crand cr2gt, cr4un, cr5un
/* 8006D374 0006A374  41 89 00 38 */	bgt cr2, .L_8006D3AC
/* 8006D378 0006A378  40 9F 00 10 */	bns cr7, .L_8006D388
/* 8006D37C 0006A37C  40 97 00 20 */	bns cr5, .L_8006D39C
/* 8006D380 0006A380  4D 94 E1 82 */	crxor cr3lt, cr5lt, cr7lt
/* 8006D384 0006A384  48 00 00 30 */	b .L_8006D3B4
.L_8006D388:
/* 8006D388 0006A388  4D 94 E1 82 */	crxor cr3lt, cr5lt, cr7lt
/* 8006D38C 0006A38C  7C 60 00 26 */	mfcr r3
/* 8006D390 0006A390  54 63 E4 20 */	rlwinm r3, r3, 28, 16, 16
/* 8006D394 0006A394  60 63 40 00 */	ori r3, r3, 0x4000
/* 8006D398 0006A398  48 00 00 2C */	b .L_8006D3C4
.L_8006D39C:
/* 8006D39C 0006A39C  4D 94 E1 82 */	crxor cr3lt, cr5lt, cr7lt
/* 8006D3A0 0006A3A0  7C 60 00 26 */	mfcr r3
/* 8006D3A4 0006A3A4  54 63 E4 20 */	rlwinm r3, r3, 28, 16, 16
/* 8006D3A8 0006A3A8  48 00 00 1C */	b .L_8006D3C4
.L_8006D3AC:
/* 8006D3AC 0006A3AC  38 60 00 00 */	li r3, 0x0
/* 8006D3B0 0006A3B0  48 00 00 18 */	b .L_8006D3C8
.L_8006D3B4:
/* 8006D3B4 0006A3B4  4E AC 63 82 */	crmove cr5gt, cr3lt
/* 8006D3B8 0006A3B8  7C 60 00 26 */	mfcr r3
/* 8006D3BC 0006A3BC  54 63 24 22 */	rlwinm r3, r3, 4, 16, 17
/* 8006D3C0 0006A3C0  60 63 20 00 */	ori r3, r3, 0x2000
.L_8006D3C4:
/* 8006D3C4 0006A3C4  7C 63 07 34 */	extsh r3, r3
.L_8006D3C8:
/* 8006D3C8 0006A3C8  7C CF F1 20 */	mtcrf 255, r6
/* 8006D3CC 0006A3CC  4E 80 00 20 */	blr
.endfn lbl_8006D24C
