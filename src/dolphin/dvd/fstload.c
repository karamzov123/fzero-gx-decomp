/* Auto-generated exact-asm transcription (scaffolding).
 * Range covered by this unit: see per-function headers. */

typedef int BOOL;
typedef unsigned int u32;

#pragma force_active on

extern unsigned char CurrTvMode[];
extern unsigned char bb2[];
extern unsigned char bb2Buf[];
extern unsigned char blockBuf[];
extern unsigned char idTmp[];
extern unsigned char lbl_8015CF68[];
extern unsigned char lbl_801A6910[];
extern unsigned char lbl_801A6924[];
extern unsigned char lbl_801A6928[];
extern unsigned char lbl_801A692C[];
extern unsigned char lbl_801A6934[];
extern unsigned char lbl_801A6938[];
extern unsigned char lbl_801A6950[];
extern unsigned char lbl_801A6958[];
extern unsigned char lbl_801A695C[];
extern unsigned char lbl_801A6960[];
extern unsigned char lbl_801A6968[];
extern unsigned char lbl_801A696C[];
extern unsigned char str_80124158[];
extern unsigned char str_801A6490[];
extern unsigned char str_801A6494[];
extern unsigned char str_801A6498[];
extern void DVDGetDriveStatus(void);
extern void DVDReadDiskID(void);
extern void DVDReset(void);
extern void OSClearContext(void);
extern void OSGetArenaHi(void);
extern void OSReport(void);
extern void OSSetArenaHi(void);
extern void OSSetCurrentContext(void);
extern void cb(void);
extern void OSWakeupThread(void);
extern void fn_800133B8(void);
extern void fn_80019430(void);
extern void fn_8001BE74(void);
extern void fn_80079D04(void);
extern void fn_80079D28(void);
extern void memcpy(void);

/* cb @0x8001A31C | size: 0xD8 */
asm void cb(void) {
nofralloc
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	addi r31, r4, 0x0
	ble lbl_8001A3B0
	lwz r0, -0x7AB0(r13)
	cmpwi r0, 0x1
	beq lbl_8001A37C
	bge lbl_8001A3E0
	cmpwi r0, 0x0
	bge lbl_8001A354
	b lbl_8001A3E0
lbl_8001A354:
	li r0, 0x1
	lwz r4, -0x7AAC(r13)
	lis r3, cb@ha
	stw r0, -0x7AB0(r13)
	addi r7, r3, cb@l
	addi r3, r31, 0x0
	li r5, 0x20
	li r6, 0x420
	bl fn_80019430
	b lbl_8001A3E0
lbl_8001A37C:
	li r0, 0x2
	lwz r6, -0x7AAC(r13)
	stw r0, -0x7AB0(r13)
	lis r3, cb@ha
	addi r7, r3, cb@l
	lwz r5, 0x8(r6)
	mr r3, r31
	lwz r4, 0x10(r6)
	addi r0, r5, 0x1f
	lwz r6, 0x4(r6)
	clrrwi r5, r0, 5
	bl fn_80019430
	b lbl_8001A3E0
lbl_8001A3B0:
	cmpwi r3, -0x1
	beq lbl_8001A3E0
	cmpwi r3, -0x4
	bne lbl_8001A3E0
	li r0, 0x0
	stw r0, -0x7AB0(r13)
	bl DVDReset
	lis r3, cb@ha
	lwz r4, -0x7AA8(r13)
	addi r5, r3, cb@l
	addi r3, r31, 0x0
	bl DVDReadDiskID
lbl_8001A3E0:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* __fstLoad @0x8001A3F4 | size: 0x168 */
asm void __fstLoad(void) {
nofralloc
	mflr r0
	lis r3, str_80124158@ha
	stw r0, 0x4(r1)
	stwu r1, -0x60(r1)
	stw r31, 0x5c(r1)
	addi r31, r3, str_80124158@l
	stw r30, 0x58(r1)
	stw r29, 0x54(r1)
	bl OSGetArenaHi
	lis r3, bb2Buf@ha
	addi r3, r3, bb2Buf@l
	addi r4, r1, 0x2b
	addi r0, r3, 0x1f
	clrrwi r3, r4, 5
	clrrwi r0, r0, 5
	stw r3, -0x7AA8(r13)
	stw r0, -0x7AAC(r13)
	bl DVDReset
	lis r3, blockBuf@ha
	lwz r4, -0x7AA8(r13)
	lis r5, cb@ha
	addi r3, r3, blockBuf@l
	addi r5, r5, cb@l
	bl DVDReadDiskID
lbl_8001A454:
	bl DVDGetDriveStatus
	cmpwi r3, 0x0
	bne lbl_8001A454
	lwz r3, -0x7AAC(r13)
	lis r29, 0x8000
	lis r30, 0x8000
	lwz r0, 0x10(r3)
	addi r3, r29, 0x0
	li r5, 0x20
	stw r0, 0x38(r30)
	lwz r4, -0x7AAC(r13)
	lwz r0, 0xc(r4)
	stw r0, 0x3c(r30)
	lwz r4, -0x7AA8(r13)
	bl memcpy
	addi r3, r13, -0x7F30
	crxor 6,6,6
	bl OSReport
	lbz r4, 0x0(r29)
	mr r3, r31
	lbz r5, 0x1(r29)
	crxor 6,6,6
	lbz r6, 0x2(r29)
	lbz r7, 0x3(r29)
	extsb r4, r4
	extsb r5, r5
	extsb r6, r6
	extsb r7, r7
	bl OSReport
	lbz r4, 0x4(r29)
	addi r3, r31, 0x1c
	lbz r5, 0x5(r29)
	crxor 6,6,6
	extsb r4, r4
	extsb r5, r5
	bl OSReport
	lbz r4, 0x6(r29)
	addi r3, r31, 0x34
	crxor 6,6,6
	bl OSReport
	lbz r4, 0x7(r29)
	addi r3, r31, 0x48
	crxor 6,6,6
	bl OSReport
	lbz r0, 0x8(r30)
	cmplwi r0, 0x0
	bne lbl_8001A518
	addi r4, r13, -0x7F2C
	b lbl_8001A51C
lbl_8001A518:
	addi r4, r13, -0x7F28
lbl_8001A51C:
	crxor 6,6,6
	addi r3, r31, 0x5c
	bl OSReport
	addi r3, r13, -0x7F30
	crxor 6,6,6
	bl OSReport
	lwz r3, -0x7AAC(r13)
	lwz r3, 0x10(r3)
	bl OSSetArenaHi
	lwz r0, 0x64(r1)
	lwz r31, 0x5c(r1)
	lwz r30, 0x58(r1)
	lwz r29, 0x54(r1)
	addi r1, r1, 0x60
	mtlr r0
	blr
}

/* fn_8001A55C @0x8001A55C | size: 0x230 */
asm void fn_8001A55C(void) {
nofralloc
	mflr r0
	lis r3, 0xcc00
	stw r0, 0x4(r1)
	addi r5, r3, 0x2000
	lis r3, lbl_8015CF68@ha
	stwu r1, -0x2f8(r1)
	li r7, 0x0
	stmw r27, 0x2e4(r1)
	addi r30, r4, 0x0
	addi r31, r3, lbl_8015CF68@l
	lhzu r6, 0x30(r5)
	rlwinm. r0, r6, 0, 16, 16
	beq lbl_8001A59C
	rlwinm r0, r6, 0, 17, 15
	sth r0, 0x0(r5)
	ori r7, r7, 0x1
lbl_8001A59C:
	lis r3, 0xcc00
	lhzu r4, 0x2034(r3)
	rlwinm. r0, r4, 0, 16, 16
	beq lbl_8001A5B8
	rlwinm r0, r4, 0, 17, 15
	sth r0, 0x0(r3)
	ori r7, r7, 0x2
lbl_8001A5B8:
	lis r3, 0xcc00
	lhzu r4, 0x2038(r3)
	rlwinm. r0, r4, 0, 16, 16
	beq lbl_8001A5D4
	rlwinm r0, r4, 0, 17, 15
	sth r0, 0x0(r3)
	ori r7, r7, 0x4
lbl_8001A5D4:
	lis r3, 0xcc00
	lhzu r4, 0x203c(r3)
	rlwinm. r0, r4, 0, 16, 16
	beq lbl_8001A5F0
	rlwinm r0, r4, 0, 17, 15
	sth r0, 0x0(r3)
	ori r7, r7, 0x8
lbl_8001A5F0:
	rlwinm. r0, r7, 0, 29, 29
	bne lbl_8001A600
	rlwinm. r0, r7, 0, 28, 28
	beq lbl_8001A60C
lbl_8001A600:
	mr r3, r30
	bl OSSetCurrentContext
	b lbl_8001A778
lbl_8001A60C:
	lwz r4, -0x7A9C(r13)
	addi r3, r1, 0x18
	addi r0, r4, 0x1
	stw r0, -0x7A9C(r13)
	bl OSClearContext
	addi r3, r1, 0x18
	bl OSSetCurrentContext
	lwz r12, -0x7A8C(r13)
	cmplwi r12, 0x0
	beq lbl_8001A640
	lwz r3, -0x7A9C(r13)
	mtlr r12
	blrl
lbl_8001A640:
	lwz r0, -0x7A98(r13)
	cmplwi r0, 0x0
	beq lbl_8001A73C
	lwz r0, -0x7A70(r13)
	cmplwi r0, 0x1
	bne lbl_8001A664
	bl fn_8001BE74
	cmplwi r3, 0x0
	beq lbl_8001A724
lbl_8001A664:
	lis r3, 0xcc00
	addi r29, r3, 0x2000
	b lbl_8001A6E4
lbl_8001A670:
	lwz r3, -0x7A68(r13)
	li r5, 0x20
	lwz r27, -0x7A64(r13)
	addi r4, r27, 0x0
	bl fn_80079D28
	cntlzw r4, r4
	cmpwi r4, 0x20
	li r0, -0x1
	and r0, r27, r0
	bge lbl_8001A69C
	b lbl_8001A6A4
lbl_8001A69C:
	cntlzw r3, r0
	addi r4, r3, 0x20
lbl_8001A6A4:
	slwi r6, r4, 1
	add r3, r31, r6
	lhz r0, 0x78(r3)
	subfic r5, r4, 0x3f
	li r3, 0x0
	sthx r0, r29, r6
	li r4, 0x1
	bl fn_80079D04
	lwz r0, -0x7A68(r13)
	nor r5, r3, r3
	nor r4, r4, r4
	lwz r3, -0x7A64(r13)
	and r0, r0, r5
	and r3, r3, r4
	stw r3, -0x7A64(r13)
	stw r0, -0x7A68(r13)
lbl_8001A6E4:
	lwz r0, -0x7A68(r13)
	li r4, 0x0
	lwz r3, -0x7A64(r13)
	xor r0, r0, r4
	xor r3, r3, r4
	or. r0, r3, r0
	bne lbl_8001A670
	stw r4, -0x7A70(r13)
	li r4, 0x1
	lwz r0, -0x7A58(r13)
	lwz r3, 0x144(r31)
	stw r3, -0x7A60(r13)
	lwz r3, 0x118(r31)
	stw r3, -0x7A5C(r13)
	stw r0, -0x7A54(r13)
	b lbl_8001A728
lbl_8001A724:
	li r4, 0x0
lbl_8001A728:
	cmpwi r4, 0x0
	beq lbl_8001A73C
	li r0, 0x0
	stw r0, -0x7A98(r13)
	bl fn_800133B8
lbl_8001A73C:
	lwz r0, -0x7A88(r13)
	cmplwi r0, 0x0
	beq lbl_8001A760
	addi r3, r1, 0x18
	bl OSClearContext
	lwz r12, -0x7A88(r13)
	lwz r3, -0x7A9C(r13)
	mtlr r12
	blrl
lbl_8001A760:
	addi r3, r13, -0x7A94
	bl OSWakeupThread
	addi r3, r1, 0x18
	bl OSClearContext
	mr r3, r30
	bl OSSetCurrentContext
lbl_8001A778:
	lmw r27, 0x2e4(r1)
	lwz r0, 0x2fc(r1)
	addi r1, r1, 0x2f8
	mtlr r0
	blr
}
