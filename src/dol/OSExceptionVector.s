.include "macros.inc"
.file "OSExceptionVector.c"

# Assembly in the original: the Dolphin SDK's OS.c writes this routine as a CodeWarrior `asm`
# function. Evidence (docs/ASM_POLICY.md section 1):
# mtsprg/mfsprg, mfsrr0/mfsrr1, mtsrr0/mtsrr1 and rfi (privileged; MWCC never emits them
# from C), no MWCC prologue or epilogue; OSExceptionInit copies it to every exception vector
# between the __OSEVStart/__OSEVEnd labels and patches the word at __OSEVSetNumber.

# 0x8000AA60..0x8000AAFC | size: 0x9C
.text
.balign 4

# .text:0x0 | 0x8000AA60 | size: 0x9C
.fn OSExceptionVector, local
# .text:0x0 | 0x8000AA60 | size: 0x0
.sym __OSEVStart, global
/* 8000AA60 00007A60  7C 90 43 A6 */	mtsprg 0, r4
/* 8000AA64 00007A64  80 80 00 C0 */	lwz r4, 0xc0(r0)
/* 8000AA68 00007A68  90 64 00 0C */	stw r3, 0xc(r4)
/* 8000AA6C 00007A6C  7C 70 42 A6 */	mfsprg r3, 0
/* 8000AA70 00007A70  90 64 00 10 */	stw r3, 0x10(r4)
/* 8000AA74 00007A74  90 A4 00 14 */	stw r5, 0x14(r4)
/* 8000AA78 00007A78  A0 64 01 A2 */	lhz r3, 0x1a2(r4)
/* 8000AA7C 00007A7C  60 63 00 02 */	ori r3, r3, 0x2
/* 8000AA80 00007A80  B0 64 01 A2 */	sth r3, 0x1a2(r4)
/* 8000AA84 00007A84  7C 60 00 26 */	mfcr r3
/* 8000AA88 00007A88  90 64 00 80 */	stw r3, 0x80(r4)
/* 8000AA8C 00007A8C  7C 68 02 A6 */	mflr r3
/* 8000AA90 00007A90  90 64 00 84 */	stw r3, 0x84(r4)
/* 8000AA94 00007A94  7C 69 02 A6 */	mfctr r3
/* 8000AA98 00007A98  90 64 00 88 */	stw r3, 0x88(r4)
/* 8000AA9C 00007A9C  7C 61 02 A6 */	mfxer r3
/* 8000AAA0 00007AA0  90 64 00 8C */	stw r3, 0x8c(r4)
/* 8000AAA4 00007AA4  7C 7A 02 A6 */	mfsrr0 r3
/* 8000AAA8 00007AA8  90 64 01 98 */	stw r3, 0x198(r4)
/* 8000AAAC 00007AAC  7C 7B 02 A6 */	mfsrr1 r3
/* 8000AAB0 00007AB0  90 64 01 9C */	stw r3, 0x19c(r4)
/* 8000AAB4 00007AB4  7C 65 1B 78 */	mr r5, r3
# .text:0x58 | 0x8000AAB8 | size: 0x0
.sym __DBVECTOR, global
/* 8000AAB8 00007AB8  60 00 00 00 */	nop
/* 8000AABC 00007ABC  7C 60 00 A6 */	mfmsr r3
/* 8000AAC0 00007AC0  60 63 00 30 */	ori r3, r3, 0x30
/* 8000AAC4 00007AC4  7C 7B 03 A6 */	mtsrr1 r3
# .text:0x68 | 0x8000AAC8 | size: 0x0
.sym __OSEVSetNumber, global
/* 8000AAC8 00007AC8  38 60 00 00 */	li r3, 0x0
/* 8000AACC 00007ACC  80 80 00 D4 */	lwz r4, 0xd4(r0)
/* 8000AAD0 00007AD0  54 A5 07 BD */	rlwinm. r5, r5, 0, 30, 30
/* 8000AAD4 00007AD4  40 82 00 14 */	bne .L_8000AAE8
/* 8000AAD8 00007AD8  3C A0 80 01 */	lis r5, OSDefaultExceptionHandler@ha
/* 8000AADC 00007ADC  38 A5 AA FC */	addi r5, r5, OSDefaultExceptionHandler@l
/* 8000AAE0 00007AE0  7C BA 03 A6 */	mtsrr0 r5
/* 8000AAE4 00007AE4  4C 00 00 64 */	rfi
.L_8000AAE8:
/* 8000AAE8 00007AE8  54 65 15 BA */	clrlslwi r5, r3, 24, 2
/* 8000AAEC 00007AEC  80 A5 30 00 */	lwz r5, 0x3000(r5)
/* 8000AAF0 00007AF0  7C BA 03 A6 */	mtsrr0 r5
/* 8000AAF4 00007AF4  4C 00 00 64 */	rfi
# .text:0x98 | 0x8000AAF8 | size: 0x0
.sym __OSEVEnd, global
/* 8000AAF8 00007AF8  60 00 00 00 */	nop
.endfn OSExceptionVector
