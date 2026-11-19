.include "macros.inc"
.file "mathutil_mtxA_rotate_z.c"

# 0x8006E424..0x8006E498 | size: 0x74
.text
.balign 4

# .text:0x0 | 0x8006E424 | size: 0x74
.fn mathutil_mtxA_rotate_z, global
/* 8006E424 0006B424  7C 88 02 A6 */	mflr r4
/* 8006E428 0006B428  4B FF ED 9D */	bl lbl_8006D1C4
/* 8006E42C 0006B42C  7C 88 03 A6 */	mtlr r4
.sym mathutil_mtxA_rotate_z_s_c, global
/* 8006E430 0006B430  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E434 0006B434  10 02 0C 20 */	ps_merge00 f0, f2, f1
/* 8006E438 0006B438  E0 64 00 00 */	psq_l f3, 0x0(r4), 0, qr0
/* 8006E43C 0006B43C  E0 84 00 10 */	psq_l f4, 0x10(r4), 0, qr0
/* 8006E440 0006B440  E0 A4 00 20 */	psq_l f5, 0x20(r4), 0, qr0
/* 8006E444 0006B444  10 C3 00 32 */	ps_mul f6, f3, f0
/* 8006E448 0006B448  10 E4 00 32 */	ps_mul f7, f4, f0
/* 8006E44C 0006B44C  11 05 00 32 */	ps_mul f8, f5, f0
/* 8006E450 0006B450  FC 20 08 50 */	fneg f1, f1
/* 8006E454 0006B454  10 C6 31 94 */	ps_sum0 f6, f6, f6, f6
/* 8006E458 0006B458  10 E7 39 D4 */	ps_sum0 f7, f7, f7, f7
/* 8006E45C 0006B45C  11 08 42 14 */	ps_sum0 f8, f8, f8, f8
/* 8006E460 0006B460  10 01 14 20 */	ps_merge00 f0, f1, f2
/* 8006E464 0006B464  D0 C4 00 00 */	stfs f6, 0x0(r4)
/* 8006E468 0006B468  10 C3 00 32 */	ps_mul f6, f3, f0
/* 8006E46C 0006B46C  D0 E4 00 10 */	stfs f7, 0x10(r4)
/* 8006E470 0006B470  10 E4 00 32 */	ps_mul f7, f4, f0
/* 8006E474 0006B474  D1 04 00 20 */	stfs f8, 0x20(r4)
/* 8006E478 0006B478  11 05 00 32 */	ps_mul f8, f5, f0
/* 8006E47C 0006B47C  10 C6 31 94 */	ps_sum0 f6, f6, f6, f6
/* 8006E480 0006B480  D0 C4 00 04 */	stfs f6, 0x4(r4)
/* 8006E484 0006B484  10 E7 39 D4 */	ps_sum0 f7, f7, f7, f7
/* 8006E488 0006B488  D0 E4 00 14 */	stfs f7, 0x14(r4)
/* 8006E48C 0006B48C  11 08 42 14 */	ps_sum0 f8, f8, f8, f8
/* 8006E490 0006B490  D1 04 00 24 */	stfs f8, 0x24(r4)
/* 8006E494 0006B494  4E 80 00 20 */	blr
.endfn mathutil_mtxA_rotate_z
