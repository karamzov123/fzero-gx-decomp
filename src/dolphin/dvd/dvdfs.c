/* Auto-generated exact-asm transcription (scaffolding).
 * Range covered by this unit: see per-function headers. */

typedef int BOOL;
typedef unsigned int u32;

#pragma force_active on

extern unsigned char BootInfo[];
extern unsigned char FstStart[];
extern unsigned char FstStringStart[];
extern unsigned char MaxEntryNum[];
extern unsigned char __DVDLongFileNameFlag[];
extern unsigned char __DVDThreadQueue[];
extern unsigned char lbl_80123E28[];
extern unsigned char lbl_80123EF0[];
extern unsigned char lbl_80123F28[];
extern unsigned char lbl_80123F5C[];
extern unsigned char lbl_801A6470[];
extern unsigned char lbl_801A68B0[];
extern void OSDisableInterrupts(void);
extern void OSReport(void);
extern void OSRestoreInterrupts(void);
extern void fn_8000C49C(void);
extern void OSSleepThread(void);
extern void OSWakeupThread(void);
extern void fn_80016DF8(void);
extern void fn_8001724C(void);
extern void fn_800173AC(void);
extern void fn_80017590(void);
extern void fn_800176D8(void);
extern void fn_80019354(void);
extern void fn_80019B78(void);
extern void fn_8007ED90(void);

/* __DVDFSInit @0x80016DC0 | size: 0x38 */
asm void __DVDFSInit(void) {
nofralloc
	lis r3, 0x8000
	stw r3, -0x7B20(r13)
	lwz r0, 0x38(r3)
	stw r0, -0x7B1C(r13)
	lwz r3, -0x7B1C(r13)
	cmplwi r3, 0x0
	beqlr
	lwz r0, 0x8(r3)
	stw r0, -0x7B14(r13)
	lwz r0, -0x7B14(r13)
	mulli r0, r0, 0xc
	add r0, r3, r0
	stw r0, -0x7B18(r13)
	blr
}

/* fn_80016DF8 @0x80016DF8 | size: 0x2F4 */
asm void fn_80016DF8(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x48(r1)
	stmw r20, 0x18(r1)
	mr r23, r3
	lis r3, lbl_80123E28@ha
	addi r25, r23, 0x0
	addi r31, r3, lbl_80123E28@l
	lwz r26, -0x7B10(r13)
lbl_80016E1C:
	lbz r3, 0x0(r23)
	extsb. r0, r3
	bne lbl_80016E30
	mr r3, r26
	b lbl_800170D8
lbl_80016E30:
	extsb r0, r3
	cmpwi r0, 0x2f
	bne lbl_80016E48
	li r26, 0x0
	addi r23, r23, 0x1
	b lbl_80016E1C
lbl_80016E48:
	cmpwi r0, 0x2e
	bne lbl_80016EC0
	lbz r3, 0x1(r23)
	extsb r0, r3
	cmpwi r0, 0x2e
	bne lbl_80016EA0
	lbz r3, 0x2(r23)
	cmpwi r3, 0x2f
	bne lbl_80016E84
	mulli r3, r26, 0xc
	lwz r4, -0x7B1C(r13)
	addi r0, r3, 0x4
	lwzx r26, r4, r0
	addi r23, r23, 0x3
	b lbl_80016E1C
lbl_80016E84:
	extsb. r0, r3
	bne lbl_80016EC0
	mulli r0, r26, 0xc
	lwz r3, -0x7B1C(r13)
	add r3, r3, r0
	lwz r3, 0x4(r3)
	b lbl_800170D8
lbl_80016EA0:
	cmpwi r0, 0x2f
	bne lbl_80016EB0
	addi r23, r23, 0x2
	b lbl_80016E1C
lbl_80016EB0:
	extsb. r0, r3
	bne lbl_80016EC0
	mr r3, r26
	b lbl_800170D8
lbl_80016EC0:
	lwz r0, -0x7B0C(r13)
	cmplwi r0, 0x0
	bne lbl_80016F74
	addi r28, r23, 0x0
	li r5, 0x0
	li r4, 0x0
	b lbl_80016F20
lbl_80016EDC:
	extsb r0, r3
	cmpwi r0, 0x2e
	bne lbl_80016F10
	subf r0, r23, r28
	cmpwi r0, 0x8
	bgt lbl_80016EFC
	cmpwi r5, 0x1
	bne lbl_80016F04
lbl_80016EFC:
	li r4, 0x1
	b lbl_80016F38
lbl_80016F04:
	addi r24, r28, 0x1
	li r5, 0x1
	b lbl_80016F1C
lbl_80016F10:
	cmpwi r0, 0x20
	bne lbl_80016F1C
	li r4, 0x1
lbl_80016F1C:
	addi r28, r28, 0x1
lbl_80016F20:
	lbz r3, 0x0(r28)
	extsb. r0, r3
	beq lbl_80016F38
	extsb r0, r3
	cmpwi r0, 0x2f
	bne lbl_80016EDC
lbl_80016F38:
	cmpwi r5, 0x1
	bne lbl_80016F50
	subf r0, r24, r28
	cmpwi r0, 0x3
	ble lbl_80016F50
	li r4, 0x1
lbl_80016F50:
	cmpwi r4, 0x0
	beq lbl_80016F98
	addi r5, r31, 0x0
	crxor 6,6,6
	addi r6, r25, 0x0
	addi r3, r13, -0x7F50
	li r4, 0x17b
	bl fn_8000C49C
	b lbl_80016F98
lbl_80016F74:
	mr r28, r23
	b lbl_80016F80
lbl_80016F7C:
	addi r28, r28, 0x1
lbl_80016F80:
	lbz r3, 0x0(r28)
	extsb. r0, r3
	beq lbl_80016F98
	extsb r0, r3
	cmpwi r0, 0x2f
	bne lbl_80016F7C
lbl_80016F98:
	lbz r0, 0x0(r28)
	extsb. r0, r0
	bne lbl_80016FAC
	li r30, 0x0
	b lbl_80016FB0
lbl_80016FAC:
	li r30, 0x1
lbl_80016FB0:
	mulli r29, r26, 0xc
	subf r27, r23, r28
	addi r26, r26, 0x1
	b lbl_800170A0
lbl_80016FC0:
	mulli r28, r26, 0xc
	lwzx r4, r3, r28
	clrrwi. r0, r4, 24
	bne lbl_80016FD8
	li r0, 0x0
	b lbl_80016FDC
lbl_80016FD8:
	li r0, 0x1
lbl_80016FDC:
	cmpwi r0, 0x0
	bne lbl_80016FEC
	cmpwi r30, 0x1
	beq lbl_80017068
lbl_80016FEC:
	lwz r3, -0x7B18(r13)
	clrlwi r0, r4, 8
	addi r21, r23, 0x0
	add r20, r3, r0
	b lbl_80017034
lbl_80017000:
	lbz r0, 0x0(r20)
	addi r20, r20, 0x1
	extsb r3, r0
	bl fn_8007ED90
	lbz r0, 0x0(r21)
	addi r22, r3, 0x0
	addi r21, r21, 0x1
	extsb r3, r0
	bl fn_8007ED90
	cmpw r3, r22
	beq lbl_80017034
	li r0, 0x0
	b lbl_80017060
lbl_80017034:
	lbz r0, 0x0(r20)
	extsb. r0, r0
	bne lbl_80017000
	lbz r3, 0x0(r21)
	cmpwi r3, 0x2f
	beq lbl_80017054
	extsb. r0, r3
	bne lbl_8001705C
lbl_80017054:
	li r0, 0x1
	b lbl_80017060
lbl_8001705C:
	li r0, 0x0
lbl_80017060:
	cmpwi r0, 0x1
	beq lbl_800170BC
lbl_80017068:
	lwz r0, -0x7B1C(r13)
	add r3, r0, r28
	lwz r0, 0x0(r3)
	clrrwi. r0, r0, 24
	bne lbl_80017084
	li r0, 0x0
	b lbl_80017088
lbl_80017084:
	li r0, 0x1
lbl_80017088:
	cmpwi r0, 0x0
	beq lbl_80017098
	lwz r0, 0x8(r3)
	b lbl_8001709C
lbl_80017098:
	addi r0, r26, 0x1
lbl_8001709C:
	mr r26, r0
lbl_800170A0:
	lwz r3, -0x7B1C(r13)
	addi r0, r3, 0x8
	lwzx r0, r29, r0
	cmplw r26, r0
	blt lbl_80016FC0
	li r3, -0x1
	b lbl_800170D8
lbl_800170BC:
	cmpwi r30, 0x0
	bne lbl_800170CC
	mr r3, r26
	b lbl_800170D8
lbl_800170CC:
	add r23, r27, r23
	addi r23, r23, 0x1
	b lbl_80016E1C
lbl_800170D8:
	lmw r20, 0x18(r1)
	lwz r0, 0x4c(r1)
	addi r1, r1, 0x48
	mtlr r0
	blr
}

/* fn_800170EC @0x800170EC | size: 0x74 */
asm void fn_800170EC(void) {
nofralloc
	cmpwi r3, 0x0
	blt lbl_80017128
	lwz r0, -0x7B14(r13)
	cmplw r3, r0
	bge lbl_80017128
	mulli r6, r3, 0xc
	lwz r3, -0x7B1C(r13)
	lwzx r0, r3, r6
	clrrwi. r0, r0, 24
	bne lbl_8001711C
	li r0, 0x0
	b lbl_80017120
lbl_8001711C:
	li r0, 0x1
lbl_80017120:
	cmpwi r0, 0x0
	beq lbl_80017130
lbl_80017128:
	li r3, 0x0
	blr
lbl_80017130:
	add r3, r3, r6
	lwz r5, 0x4(r3)
	li r0, 0x0
	li r3, 0x1
	stw r5, 0x30(r4)
	lwz r5, -0x7B1C(r13)
	add r5, r5, r6
	lwz r5, 0x8(r5)
	stw r5, 0x34(r4)
	stw r0, 0x38(r4)
	stw r0, 0xc(r4)
	blr
}

/* fn_80017160 @0x80017160 | size: 0xC8 */
asm void fn_80017160(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x98(r1)
	stw r31, 0x94(r1)
	addi r31, r4, 0x0
	stw r30, 0x90(r1)
	addi r30, r3, 0x0
	bl fn_80016DF8
	cmpwi r3, 0x0
	bge lbl_800171B4
	addi r3, r1, 0x10
	li r4, 0x80
	bl fn_800173AC
	lis r3, lbl_80123EF0@ha
	crxor 6,6,6
	addi r3, r3, lbl_80123EF0@l
	addi r4, r30, 0x0
	addi r5, r1, 0x10
	bl OSReport
	li r3, 0x0
	b lbl_80017210
lbl_800171B4:
	mulli r5, r3, 0xc
	lwz r3, -0x7B1C(r13)
	lwzx r0, r3, r5
	clrrwi. r0, r0, 24
	bne lbl_800171D0
	li r0, 0x0
	b lbl_800171D4
lbl_800171D0:
	li r0, 0x1
lbl_800171D4:
	cmpwi r0, 0x0
	beq lbl_800171E4
	li r3, 0x0
	b lbl_80017210
lbl_800171E4:
	add r3, r3, r5
	lwz r4, 0x4(r3)
	li r0, 0x0
	li r3, 0x1
	stw r4, 0x30(r31)
	lwz r4, -0x7B1C(r13)
	add r4, r4, r5
	lwz r4, 0x8(r4)
	stw r4, 0x34(r31)
	stw r0, 0x38(r31)
	stw r0, 0xc(r31)
lbl_80017210:
	lwz r0, 0x9c(r1)
	lwz r31, 0x94(r1)
	lwz r30, 0x90(r1)
	addi r1, r1, 0x98
	mtlr r0
	blr
}

/* fn_80017228 @0x80017228 | size: 0x24 */
asm void fn_80017228(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bl fn_80019B78
	li r3, 0x1
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* fn_8001724C @0x8001724C | size: 0x160 */
asm void fn_8001724C(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x0
	stw r0, 0x4(r1)
	stwu r1, -0x30(r1)
	stw r31, 0x2c(r1)
	stw r30, 0x28(r1)
	addi r30, r5, 0x0
	stw r29, 0x24(r1)
	addi r29, r4, 0x0
	stw r28, 0x20(r1)
	bne lbl_80017280
	li r3, 0x0
	b lbl_8001738C
lbl_80017280:
	lwz r4, -0x7B1C(r13)
	mulli r3, r3, 0xc
	lwz r6, -0x7B18(r13)
	addi r5, r4, 0x4
	lwzx r0, r4, r3
	lwzx r3, r5, r3
	clrlwi r0, r0, 8
	cmplwi r3, 0x0
	add r31, r6, r0
	bne lbl_800172B0
	li r3, 0x0
	b lbl_8001732C
lbl_800172B0:
	mulli r3, r3, 0xc
	lwzx r0, r4, r3
	mr r4, r29
	lwzx r3, r5, r3
	addi r5, r30, 0x0
	clrlwi r0, r0, 8
	add r28, r6, r0
	bl fn_8001724C
	cmplw r3, r30
	bne lbl_800172DC
	b lbl_8001732C
lbl_800172DC:
	addi r0, r3, 0x0
	addi r3, r3, 0x1
	li r4, 0x2f
	subf r6, r3, r30
	stbx r4, r29, r0
	addi r4, r6, 0x0
	add r5, r29, r3
	b lbl_80017310
lbl_800172FC:
	lbz r0, 0x0(r28)
	addi r28, r28, 0x1
	subi r4, r4, 0x1
	stb r0, 0x0(r5)
	addi r5, r5, 0x1
lbl_80017310:
	cmplwi r4, 0x0
	beq lbl_80017324
	lbz r0, 0x0(r28)
	extsb. r0, r0
	bne lbl_800172FC
lbl_80017324:
	subf r0, r4, r6
	add r3, r3, r0
lbl_8001732C:
	cmplw r3, r30
	bne lbl_80017338
	b lbl_8001738C
lbl_80017338:
	addi r0, r3, 0x0
	addi r3, r3, 0x1
	li r4, 0x2f
	subf r7, r3, r30
	stbx r4, r29, r0
	addi r6, r31, 0x0
	addi r4, r7, 0x0
	add r5, r29, r3
	b lbl_80017370
lbl_8001735C:
	lbz r0, 0x0(r6)
	addi r6, r6, 0x1
	subi r4, r4, 0x1
	stb r0, 0x0(r5)
	addi r5, r5, 0x1
lbl_80017370:
	cmplwi r4, 0x0
	beq lbl_80017384
	lbz r0, 0x0(r6)
	extsb. r0, r0
	bne lbl_8001735C
lbl_80017384:
	subf r0, r4, r7
	add r3, r3, r0
lbl_8001738C:
	lwz r0, 0x34(r1)
	lwz r31, 0x2c(r1)
	lwz r30, 0x28(r1)
	lwz r29, 0x24(r1)
	lwz r28, 0x20(r1)
	addi r1, r1, 0x30
	mtlr r0
	blr
}

/* fn_800173AC @0x800173AC | size: 0xC4 */
asm void fn_800173AC(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x20(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	addi r30, r4, 0x0
	addi r5, r30, 0x0
	stw r29, 0x14(r1)
	addi r29, r3, 0x0
	addi r4, r29, 0x0
	lwz r31, -0x7B10(r13)
	addi r3, r31, 0x0
	bl fn_8001724C
	cmplw r3, r30
	bne lbl_800173F8
	li r0, 0x0
	add r3, r29, r30
	stb r0, -0x1(r3)
	b lbl_80017450
lbl_800173F8:
	mulli r0, r31, 0xc
	lwz r4, -0x7B1C(r13)
	lwzx r0, r4, r0
	clrrwi. r0, r0, 24
	bne lbl_80017414
	li r0, 0x0
	b lbl_80017418
lbl_80017414:
	li r0, 0x1
lbl_80017418:
	cmpwi r0, 0x0
	beq lbl_80017444
	subi r0, r30, 0x1
	cmplw r3, r0
	bne lbl_80017438
	li r0, 0x0
	stbx r0, r29, r3
	b lbl_80017450
lbl_80017438:
	li r0, 0x2f
	stbx r0, r29, r3
	addi r3, r3, 0x1
lbl_80017444:
	li r0, 0x0
	stbx r0, r29, r3
	li r0, 0x1
lbl_80017450:
	mr r3, r0
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	addi r1, r1, 0x20
	mtlr r0
	blr
}

/* fn_80017470 @0x80017470 | size: 0x60 */
asm void fn_80017470(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bl fn_80016DF8
	cmpwi r3, 0x0
	blt lbl_800174B0
	mulli r0, r3, 0xc
	lwz r4, -0x7B1C(r13)
	lwzx r0, r4, r0
	clrrwi. r0, r0, 24
	bne lbl_800174A4
	li r0, 0x0
	b lbl_800174A8
lbl_800174A4:
	li r0, 0x1
lbl_800174A8:
	cmpwi r0, 0x0
	bne lbl_800174B8
lbl_800174B0:
	li r3, 0x0
	b lbl_800174C0
lbl_800174B8:
	stw r3, -0x7B10(r13)
	li r3, 0x1
lbl_800174C0:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* fn_800174D0 @0x800174D0 | size: 0xC0 */
asm void fn_800174D0(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x38(r1)
	stmw r26, 0x20(r1)
	mr. r29, r6
	addi r26, r3, 0x0
	addi r27, r4, 0x0
	addi r28, r5, 0x0
	addi r30, r7, 0x0
	addi r31, r8, 0x0
	blt lbl_80017508
	lwz r0, 0x34(r26)
	cmplw r29, r0
	blt lbl_80017520
lbl_80017508:
	lis r3, lbl_80123F28@ha
	crxor 6,6,6
	addi r5, r3, lbl_80123F28@l
	addi r3, r13, -0x7F50
	li r4, 0x2e6
	bl fn_8000C49C
lbl_80017520:
	add. r4, r29, r28
	blt lbl_80017538
	lwz r3, 0x34(r26)
	addi r0, r3, 0x20
	cmplw r4, r0
	blt lbl_80017550
lbl_80017538:
	lis r3, lbl_80123F28@ha
	crxor 6,6,6
	addi r5, r3, lbl_80123F28@l
	addi r3, r13, -0x7F50
	li r4, 0x2ec
	bl fn_8000C49C
lbl_80017550:
	stw r30, 0x38(r26)
	lis r3, fn_80017590@ha
	addi r7, r3, fn_80017590@l
	lwz r0, 0x30(r26)
	addi r3, r26, 0x0
	addi r4, r27, 0x0
	addi r5, r28, 0x0
	addi r8, r31, 0x0
	add r6, r0, r29
	bl fn_80019354
	lmw r26, 0x20(r1)
	li r3, 0x1
	lwz r0, 0x3c(r1)
	addi r1, r1, 0x38
	mtlr r0
	blr
}

/* fn_80017590 @0x80017590 | size: 0x30 */
asm void fn_80017590(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	lwz r12, 0x38(r4)
	cmplwi r12, 0x0
	beq lbl_800175B0
	mtlr r12
	blrl
lbl_800175B0:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* fn_800175C0 @0x800175C0 | size: 0x118 */
asm void fn_800175C0(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x38(r1)
	stmw r27, 0x24(r1)
	mr. r29, r6
	addi r31, r3, 0x0
	addi r27, r4, 0x0
	addi r28, r5, 0x0
	addi r30, r7, 0x0
	blt lbl_800175F4
	lwz r0, 0x34(r31)
	cmplw r29, r0
	blt lbl_8001760C
lbl_800175F4:
	lis r3, lbl_80123F5C@ha
	crxor 6,6,6
	addi r5, r3, lbl_80123F5C@l
	addi r3, r13, -0x7F50
	li r4, 0x32c
	bl fn_8000C49C
lbl_8001760C:
	add. r4, r29, r28
	blt lbl_80017624
	lwz r3, 0x34(r31)
	addi r0, r3, 0x20
	cmplw r4, r0
	blt lbl_8001763C
lbl_80017624:
	lis r3, lbl_80123F5C@ha
	crxor 6,6,6
	addi r5, r3, lbl_80123F5C@l
	addi r3, r13, -0x7F50
	li r4, 0x332
	bl fn_8000C49C
lbl_8001763C:
	lwz r0, 0x30(r31)
	lis r4, fn_800176D8@ha
	addi r7, r4, fn_800176D8@l
	addi r3, r31, 0x0
	addi r4, r27, 0x0
	addi r5, r28, 0x0
	addi r8, r30, 0x0
	add r6, r0, r29
	bl fn_80019354
	cmpwi r3, 0x0
	bne lbl_80017670
	li r3, -0x1
	b lbl_800176C4
lbl_80017670:
	bl OSDisableInterrupts
	mr r30, r3
lbl_80017678:
	lwz r0, 0xc(r31)
	cmpwi r0, 0x0
	bne lbl_8001768C
	lwz r31, 0x20(r31)
	b lbl_800176B8
lbl_8001768C:
	cmpwi r0, -0x1
	bne lbl_8001769C
	li r31, -0x1
	b lbl_800176B8
lbl_8001769C:
	cmpwi r0, 0xa
	bne lbl_800176AC
	li r31, -0x3
	b lbl_800176B8
lbl_800176AC:
	addi r3, r13, -0x7B08
	bl OSSleepThread
	b lbl_80017678
lbl_800176B8:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
lbl_800176C4:
	lmw r27, 0x24(r1)
	lwz r0, 0x3c(r1)
	addi r1, r1, 0x38
	mtlr r0
	blr
}

/* fn_800176D8 @0x800176D8 | size: 0x24 */
asm void fn_800176D8(void) {
nofralloc
	mflr r0
	addi r3, r13, -0x7B08
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bl OSWakeupThread
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* fn_800176FC @0x800176FC | size: 0x6C */
asm void fn_800176FC(void) {
nofralloc
	lwz r0, 0xc(r3)
	cmpwi r0, 0x2
	beq lbl_80017744
	bge lbl_80017720
	cmpwi r0, 0x1
	bge lbl_8001774C
	cmpwi r0, -0x1
	bge lbl_8001773C
	blr
lbl_80017720:
	cmpwi r0, 0xa
	bge lbl_80017734
	cmpwi r0, 0x8
	bgelr
	b lbl_8001773C
lbl_80017734:
	cmpwi r0, 0xc
	bgelr
lbl_8001773C:
	lwz r3, 0x20(r3)
	blr
lbl_80017744:
	li r3, 0x0
	blr
lbl_8001774C:
	lis r4, 0xcc00
	lwz r0, 0x1c(r3)
	lwz r5, 0x20(r3)
	lwz r3, 0x6018(r4)
	subf r0, r3, r0
	add r3, r5, r0
	blr
}

/* fn_80017768 @0x80017768 | size: 0x4 */
asm void fn_80017768(void) {
nofralloc
	blr
}
