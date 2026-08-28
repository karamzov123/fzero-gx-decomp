/* hard2 candidate: adapted from dolsdk2001 dvdqueue.c:13 */
typedef int BOOL;
typedef unsigned int u32;
typedef struct DVDCommandBlock DVDCommandBlock;
struct DVDCommandBlock {
    DVDCommandBlock *next;
    DVDCommandBlock *prev;
};

#pragma force_active on

extern unsigned char WaitingQueue[];
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);

void __DVDClearWaitingQueue(void) {
    // provenance: dolsdk2001:src/dvd/dvdqueue.c:13
    unsigned int i;
    DVDCommandBlock *q;

    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock *)(WaitingQueue + i * 8);
        q->next = q;
        q->prev = q;
    }
}

/* __DVDPushWaitingQueue @0x80019E9C | size: 0x68 */
asm void __DVDPushWaitingQueue(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	addi r31, r4, 0x0
	stw r30, 0x10(r1)
	addi r30, r3, 0x0
	bl OSDisableInterrupts
	lis r4, WaitingQueue@ha
	slwi r5, r30, 3
	addi r0, r4, WaitingQueue@l
	add r5, r0, r5
	lwz r4, 0x4(r5)
	stw r31, 0x0(r4)
	lwz r0, 0x4(r5)
	stw r0, 0x4(r31)
	stw r5, 0x0(r31)
	stw r31, 0x4(r5)
	bl OSRestoreInterrupts
	lwz r0, 0x1c(r1)
	li r3, 0x1
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* __DVDPopWaitingQueue @0x80019F04 | size: 0xA0 */
asm void __DVDPopWaitingQueue(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x10(r1)
	stw r31, 0xc(r1)
	bl OSDisableInterrupts
	li r0, 0x4
	lis r4, WaitingQueue@ha
	mtctr r0
	addi r4, r4, WaitingQueue@l
	li r31, 0x0
lbl_80019F2C:
	lwz r0, 0x0(r4)
	cmplw r0, r4
	beq lbl_80019F7C
	bl OSRestoreInterrupts
	bl OSDisableInterrupts
	lis r4, WaitingQueue@ha
	slwi r5, r31, 3
	addi r0, r4, WaitingQueue@l
	add r5, r0, r5
	lwz r31, 0x0(r5)
	lwz r0, 0x0(r31)
	stw r0, 0x0(r5)
	lwz r4, 0x0(r31)
	stw r5, 0x4(r4)
	bl OSRestoreInterrupts
	li r0, 0x0
	stw r0, 0x0(r31)
	mr r3, r31
	stw r0, 0x4(r31)
	b lbl_80019F90
lbl_80019F7C:
	addi r4, r4, 0x8
	addi r31, r31, 0x1
	bdnz lbl_80019F2C
	bl OSRestoreInterrupts
	li r3, 0x0
lbl_80019F90:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* __DVDCheckWaitingQueue @0x80019FA4 | size: 0x58 */
asm void __DVDCheckWaitingQueue(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bl OSDisableInterrupts
	li r0, 0x4
	lis r4, WaitingQueue@ha
	mtctr r0
	addi r4, r4, WaitingQueue@l
lbl_80019FC4:
	lwz r0, 0x0(r4)
	cmplw r0, r4
	beq lbl_80019FDC
	bl OSRestoreInterrupts
	li r3, 0x1
	b lbl_80019FEC
lbl_80019FDC:
	addi r4, r4, 0x8
	bdnz lbl_80019FC4
	bl OSRestoreInterrupts
	li r3, 0x0
lbl_80019FEC:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* fn_80019FFC @0x80019FFC | size: 0x60 */
asm void fn_80019FFC(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	mr r31, r3
	bl OSDisableInterrupts
	lwz r4, 0x4(r31)
	lwz r5, 0x0(r31)
	cmplwi r4, 0x0
	beq lbl_8001A02C
	cmplwi r5, 0x0
	bne lbl_8001A038
lbl_8001A02C:
	bl OSRestoreInterrupts
	li r3, 0x0
	b lbl_8001A048
lbl_8001A038:
	stw r5, 0x0(r4)
	stw r4, 0x4(r5)
	bl OSRestoreInterrupts
	li r3, 0x1
lbl_8001A048:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
