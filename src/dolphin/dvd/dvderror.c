/* Auto-generated exact-asm transcription (scaffolding).
 * Range covered by this unit: see per-function headers. */

typedef int BOOL;
typedef unsigned int u32;

#pragma force_active on

extern unsigned char lbl_80124110[];
extern unsigned char lbl_801A6908[4];
extern void ErrorCode2Num(void);
extern void __OSLockSramEx(void);
extern void __OSUnlockSramEx(void);
extern void __msl_strncmp(void);

/* ErrorCode2Num @0x8001A05C | size: 0x11C */
asm void ErrorCode2Num(void) {
nofralloc
	li r0, 0x2
	lis r4, lbl_80124110@ha
	mtctr r0
	addi r4, r4, lbl_80124110@l
	li r5, 0x0
lbl_8001A070:
	lwz r0, 0x0(r4)
	cmplw r3, r0
	bne lbl_8001A084
	clrlwi r3, r5, 24
	blr
lbl_8001A084:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A09C
	clrlwi r3, r5, 24
	blr
lbl_8001A09C:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A0B4
	clrlwi r3, r5, 24
	blr
lbl_8001A0B4:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A0CC
	clrlwi r3, r5, 24
	blr
lbl_8001A0CC:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A0E4
	clrlwi r3, r5, 24
	blr
lbl_8001A0E4:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A0FC
	clrlwi r3, r5, 24
	blr
lbl_8001A0FC:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A114
	clrlwi r3, r5, 24
	blr
lbl_8001A114:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A12C
	clrlwi r3, r5, 24
	blr
lbl_8001A12C:
	lwzu r0, 0x4(r4)
	addi r5, r5, 0x1
	cmplw r3, r0
	bne lbl_8001A144
	clrlwi r3, r5, 24
	blr
lbl_8001A144:
	addi r4, r4, 0x4
	addi r5, r5, 0x1
	bdnz lbl_8001A070
	lis r4, 0x10
	cmplw r3, r4
	blt lbl_8001A170
	addi r0, r4, 0x8
	cmplw r3, r0
	bgt lbl_8001A170
	li r3, 0x11
	blr
lbl_8001A170:
	li r3, 0x1d
	blr
}

/* __DVDStoreErrorCode @0x8001A178 | size: 0x7C */
asm void __DVDStoreErrorCode(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	subis r0, r3, 0x123
	cmplwi r0, 0x4567
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	bne lbl_8001A19C
	li r31, 0xff
	b lbl_8001A1D0
lbl_8001A19C:
	cmplwi r0, 0x4568
	bne lbl_8001A1AC
	li r31, 0xfe
	b lbl_8001A1D0
lbl_8001A1AC:
	srwi r31, r3, 24
	clrlwi r3, r3, 8
	bl ErrorCode2Num
	cmplwi r31, 0x6
	blt lbl_8001A1C4
	li r31, 0x6
lbl_8001A1C4:
	mulli r0, r31, 0x1e
	clrlwi r3, r3, 24
	add r31, r3, r0
lbl_8001A1D0:
	bl __OSLockSramEx
	stb r31, 0x24(r3)
	li r3, 0x1
	bl __OSUnlockSramEx
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* fn_8001A1F4 @0x8001A1F4 | size: 0xF8 */
asm void fn_8001A1F4(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	addi r31, r4, 0x0
	stw r30, 0x10(r1)
	mr r30, r3
	lbz r0, 0x0(r3)
	extsb. r0, r0
	beq lbl_8001A248
	lbz r0, 0x0(r31)
	extsb. r0, r0
	beq lbl_8001A248
	addi r3, r30, 0x0
	addi r4, r31, 0x0
	li r5, 0x4
	bl __msl_strncmp
	cmpwi r3, 0x0
	beq lbl_8001A248
	li r3, 0x0
	b lbl_8001A2D4
lbl_8001A248:
	lbz r0, 0x4(r30)
	extsb. r0, r0
	beq lbl_8001A278
	lbz r0, 0x4(r31)
	extsb. r0, r0
	beq lbl_8001A278
	addi r3, r30, 0x4
	addi r4, r31, 0x4
	li r5, 0x2
	bl __msl_strncmp
	cmpwi r3, 0x0
	beq lbl_8001A280
lbl_8001A278:
	li r3, 0x0
	b lbl_8001A2D4
lbl_8001A280:
	lbz r3, 0x6(r30)
	cmplwi r3, 0xff
	beq lbl_8001A2A8
	lbz r0, 0x6(r31)
	cmplwi r0, 0xff
	beq lbl_8001A2A8
	cmplw r3, r0
	beq lbl_8001A2A8
	li r3, 0x0
	b lbl_8001A2D4
lbl_8001A2A8:
	lbz r3, 0x7(r30)
	cmplwi r3, 0xff
	beq lbl_8001A2D0
	lbz r0, 0x7(r31)
	cmplwi r0, 0xff
	beq lbl_8001A2D0
	cmplw r3, r0
	beq lbl_8001A2D0
	li r3, 0x0
	b lbl_8001A2D4
lbl_8001A2D0:
	li r3, 0x1
lbl_8001A2D4:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* fn_8001A2EC @0x8001A2EC | size: 0x30
 * Declaration-shape: head declares `extern unsigned char lbl_801A6908[4]`
 *   (array); access the 4-byte fn-ptr via a correctly typed pointer (recipe).
 * Shape: fn-ptr read directly into both predicate and call keeps it in r12 for
 *   `mtlr r12; blrl` (matches retail; avoids spilling to r0). */
typedef void (*fn_8001A2EC_cb)(void);

// provenance: original (retail asm reconstruction; callback-forwarder shape shared with dolsdk2001:src/dvd/dvdfs.c __DVDReadDoneCallback) fn_8001A2EC
void fn_8001A2EC(void) {
    if (*(fn_8001A2EC_cb *)lbl_801A6908 != 0) {
        (*(fn_8001A2EC_cb *)lbl_801A6908)();
    }
}
