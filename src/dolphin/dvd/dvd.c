/* Auto-generated exact-asm transcription (scaffolding).
 * Range covered by this unit: see per-function headers. */

typedef int BOOL;
typedef unsigned int u32;

#pragma force_active on

extern unsigned char BB2[];
extern unsigned char CancelLastError[];
extern unsigned char CurrCommand[];
extern unsigned char DVDInitialized[];
extern unsigned char DummyCommandBlock[];
extern unsigned char FatalErrorFlag[];
extern unsigned char FirstTimeInBootrom[];
extern unsigned char IDShouldBe[];
extern unsigned char PauseFlag[];
extern unsigned char PausingFlag[];
extern unsigned char ResetRequired[];
extern unsigned char ResumeFromHere[];
extern unsigned char __DVDThreadQueue[];
extern unsigned char __DVDVersion[];
extern unsigned char autoInvalidation[];
extern unsigned char bootInfo[];
extern unsigned char executing[];
extern unsigned char jumptable_80124018[];
extern unsigned char jumptable_801240A8[];
extern unsigned char jumptable_801240DC[];
extern unsigned char lbl_80123FE4[];
extern unsigned char lbl_80124058[];
extern unsigned char lbl_8015CE60[];
extern unsigned char lbl_801A6480[];
extern unsigned char lbl_801A6484[];
extern unsigned char lbl_801A648C[];
extern unsigned char lbl_801A68D4[];
extern unsigned char lbl_801A68E0[];
extern unsigned char lbl_801A68E4[];
extern unsigned char lbl_801A68F0[];
extern unsigned char lbl_801A68F4[];
extern unsigned char lbl_801A6904[];
extern unsigned char str_80123FD8[];
extern void AlarmHandler(void);
extern void DCInvalidateRange(void);
extern void DVDLowReset(void);
extern void DVDLowStopMotor(void);
extern void DVDLowWaitCoverClose(void);
extern void DVDReset(void);
extern void OSCreateAlarm(void);
extern void OSDisableInterrupts(void);
extern void OSInitThreadQueue(void);
extern void OSRegisterVersion(void);
extern void OSReport(void);
extern void OSRestoreInterrupts(void);
extern void OSSetAlarm(void);
extern void __DVDCheckWaitingQueue(void);
extern void __DVDClearWaitingQueue(void);
extern void __DVDFSInit(void);
extern void __DVDInitWA(void);
extern void __DVDInterruptHandler(void);
extern void __DVDPopWaitingQueue(void);
extern void __DVDPushWaitingQueue(void);
extern void __DVDStoreErrorCode(void);
extern void __OSSetInterruptHandler(void);
extern void __OSUnmaskInterrupts(void);
extern void __fstLoad(void);
extern void cbForStateError(void);
extern void cbForStateMotorStopped(void);
extern void OSPanic(void);
extern void OSSleepThread(void);
extern void OSWakeupThread(void);
extern void fn_80016524(void);
extern void fn_800167BC(void);
extern void fn_8001687C(void);
extern void fn_800169AC(void);
extern void fn_80016A38(void);
extern void fn_80016AD4(void);
extern void fn_80016B6C(void);
extern void fn_80016BF8(void);
extern void fn_80016D50(void);
extern void fn_80016D64(void);
extern void stateReadingFST(void);
extern void cbForStateReadingFST(void);
extern void stateTimeout(void);
extern void cbForRetryRequestError(void);
extern void CategorizeError(void);
extern void cbForStateGettingError(void);
extern void cbForUnrecoveredError(void);
extern void cbForUnrecoveredErrorRetry(void);
extern void stateGoToRetry(void);
extern void cbForStateGoToRetry(void);
extern void stateCheckID(void);
extern void cbForStateCheckID2(void);
extern void cbForStateCheckID3(void);
extern void cbForStateCheckID1(void);
extern void stateCheckID2(void);
extern void cbForStateCoverClosed(void);
extern void cbForStateCheckID2a(void);
extern void cbForStateCheckID2b(void);
extern void stateCoverClosed(void);
extern void cbForStateCoverClosed_CMD(void);
extern void cbForCoverClosedCheckID(void);
extern void fn_800186C0(void);
extern void cbForStateBusy(void);
extern void __DVDDequeueWaitingQueue(void);
extern void cbForCancelSync(void);
extern void fn_80019FFC(void);
extern void fn_8001A1F4(void);
extern void fn_8001A2EC(void);
extern void strncmp(void);
extern void memcpy(void);
extern void stateBusy(void);
extern void stateReady(void);

/* DVDInit @0x8001776C | size: 0xCC */
asm void DVDInit(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x10(r1)
	stw r31, 0xc(r1)
	lwz r0, -0x7AC0(r13)
	cmpwi r0, 0x0
	bne lbl_80017824
	lwz r3, -0x7F48(r13)
	bl OSRegisterVersion
	li r31, 0x1
	stw r31, -0x7AC0(r13)
	bl __DVDFSInit
	bl __DVDClearWaitingQueue
	bl __DVDInitWA
	lis r0, 0x8000
	lis r3, __DVDInterruptHandler@ha
	stw r0, -0x7AF8(r13)
	addi r4, r3, __DVDInterruptHandler@l
	stw r0, -0x7AFC(r13)
	li r3, 0x15
	bl __OSSetInterruptHandler
	li r3, 0x400
	bl __OSUnmaskInterrupts
	addi r3, r13, -0x7B08
	bl OSInitThreadQueue
	lis r3, 0xcc00
	li r0, 0x2a
	stw r0, 0x6000(r3)
	li r0, 0x0
	stw r0, 0x6004(r3)
	lwz r3, -0x7AF8(r13)
	addi r3, r3, 0x20
	lwz r3, 0x0(r3)
	addis r0, r3, 0x1ae0
	cmplwi r0, 0x7c22
	bne lbl_80017814
	lis r3, str_80123FD8@ha
	crxor 6,6,6
	addi r3, r3, str_80123FD8@l
	bl OSReport
	bl __fstLoad
	b lbl_80017824
lbl_80017814:
	subis r0, r3, 0xd15
	cmplwi r0, 0xea5e
	beq lbl_80017824
	stw r31, -0x7AC4(r13)
lbl_80017824:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* stateReadingFST @0x80017838 | size: 0x94 */
asm void stateReadingFST(void) {
nofralloc
	mflr r0
	lis r3, stateReadingFST@ha
	stw r0, 0x4(r1)
	addi r0, r3, stateReadingFST@l
	lis r3, BB2@ha
	stwu r1, -0x10(r1)
	addi r3, r3, BB2@l
	stw r31, 0xc(r1)
	addi r31, r3, 0x8
	stw r0, -0x7ABC(r13)
	lwz r4, -0x7AF8(r13)
	lwz r0, 0x0(r31)
	lwz r3, 0x3c(r4)
	cmplw r3, r0
	bge lbl_8001788C
	lis r3, lbl_80123FE4@ha
	crxor 6,6,6
	addi r5, r3, lbl_80123FE4@l
	addi r3, r13, -0x7F3C
	li r4, 0x287
	bl OSPanic
lbl_8001788C:
	lis r3, BB2@ha
	lwz r6, 0x0(r31)
	addi r5, r3, BB2@l
	lwz r7, -0x7AF8(r13)
	lis r4, cbForStateReadingFST@ha
	lwz r5, 0x4(r5)
	addi r0, r6, 0x1f
	lwz r3, 0x38(r7)
	addi r6, r4, cbForStateReadingFST@l
	clrrwi r4, r0, 5
	bl fn_80016524
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* cbForStateReadingFST @0x800178CC | size: 0x8C */
asm void cbForStateReadingFST(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	bne lbl_800178F8
	lwz r3, -0x7B00(r13)
	li r0, -0x1
	stw r0, 0xc(r3)
	bl stateTimeout
	b lbl_80017944
lbl_800178F8:
	clrlwi. r0, r3, 31
	beq lbl_80017940
	li r31, 0x0
	stw r31, -0x7ACC(r13)
	bl __DVDFSInit
	lis r3, DummyCommandBlock@ha
	lwz r4, -0x7B00(r13)
	addi r0, r3, DummyCommandBlock@l
	stw r0, -0x7B00(r13)
	stw r31, 0xc(r4)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80017938
	mtlr r12
	li r3, 0x0
	blrl
lbl_80017938:
	bl stateReady
	b lbl_80017944
lbl_80017940:
	bl cbForRetryRequestError
lbl_80017944:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* cbForStateError @0x80017958 | size: 0xAC */
asm void cbForStateError(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	bne lbl_80017984
	lwz r3, -0x7B00(r13)
	li r0, -0x1
	stw r0, 0xc(r3)
	bl stateTimeout
	b lbl_800179F0
lbl_80017984:
	bl fn_8001A2EC
	lis r3, DummyCommandBlock@ha
	lwz r31, -0x7B00(r13)
	addi r0, r3, DummyCommandBlock@l
	li r3, 0x1
	stw r0, -0x7B00(r13)
	stw r3, -0x7AE8(r13)
	lwz r12, 0x28(r31)
	cmplwi r12, 0x0
	beq lbl_800179BC
	mtlr r12
	addi r4, r31, 0x0
	li r3, -0x1
	blrl
lbl_800179BC:
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_800179EC
	lwz r12, -0x7ADC(r13)
	li r0, 0x0
	stw r0, -0x7AE0(r13)
	cmplwi r12, 0x0
	beq lbl_800179EC
	mtlr r12
	addi r4, r31, 0x0
	li r3, 0x0
	blrl
lbl_800179EC:
	bl stateReady
lbl_800179F0:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* stateTimeout @0x80017A04 | size: 0x34 */
asm void stateTimeout(void) {
nofralloc
	mflr r0
	lis r3, 0x123
	stw r0, 0x4(r1)
	addi r3, r3, 0x4568
	stwu r1, -0x8(r1)
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForRetryRequestError @0x80017A38 | size: 0x28 */
asm void cbForRetryRequestError(void) {
nofralloc
	mflr r0
	lis r3, cbForStateGettingError@ha
	stw r0, 0x4(r1)
	addi r3, r3, cbForStateGettingError@l
	stwu r1, -0x8(r1)
	bl fn_800169AC
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* CategorizeError @0x80017A60 | size: 0xB4 */
asm void CategorizeError(void) {
nofralloc
	subis r0, r3, 0x2
	cmplwi r0, 0x400
	bne lbl_80017A78
	stw r3, -0x7AD0(r13)
	li r3, 0x1
	blr
lbl_80017A78:
	clrlwi r4, r3, 8
	subis r0, r4, 0x6
	cmplwi r0, 0x2800
	beq lbl_80017AA0
	subis r0, r4, 0x2
	cmplwi r0, 0x3a00
	beq lbl_80017AA0
	subis r0, r4, 0xb
	cmplwi r0, 0x5a01
	bne lbl_80017AA8
lbl_80017AA0:
	li r3, 0x0
	blr
lbl_80017AA8:
	lwz r3, -0x7ACC(r13)
	addi r0, r3, 0x1
	stw r0, -0x7ACC(r13)
	lwz r0, -0x7ACC(r13)
	cmpwi r0, 0x2
	bne lbl_80017AE4
	lwz r0, -0x7AD0(r13)
	cmplw r4, r0
	bne lbl_80017AD8
	stw r4, -0x7AD0(r13)
	li r3, 0x1
	blr
lbl_80017AD8:
	stw r4, -0x7AD0(r13)
	li r3, 0x2
	blr
lbl_80017AE4:
	subis r0, r4, 0x3
	stw r4, -0x7AD0(r13)
	cmplwi r0, 0x1100
	beq lbl_80017B04
	lwz r3, -0x7B00(r13)
	lwz r0, 0x8(r3)
	cmplwi r0, 0x5
	bne lbl_80017B0C
lbl_80017B04:
	li r3, 0x2
	blr
lbl_80017B0C:
	li r3, 0x3
	blr
}

/* cbForStateGettingError @0x80017B14 | size: 0x294 */
asm void cbForStateGettingError(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x20(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	stw r29, 0x14(r1)
	stw r28, 0x10(r1)
	bne lbl_80017B60
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_80017D88
lbl_80017B60:
	rlwinm. r0, r3, 0, 30, 30
	beq lbl_80017B90
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4567
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
	b lbl_80017D88
lbl_80017B90:
	lis r3, 0xcc00
	lwz r29, 0x6020(r3)
	addi r3, r29, 0x0
	clrrwi r28, r29, 24
	bl CategorizeError
	addi r31, r3, 0x0
	cmplwi r31, 0x1
	bne lbl_80017BD4
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	addi r3, r29, 0x0
	stw r0, 0xc(r4)
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
	b lbl_80017D88
lbl_80017BD4:
	subi r0, r31, 0x2
	cmplwi r0, 0x1
	bgt lbl_80017BE8
	li r4, 0x0
	b lbl_80017C28
lbl_80017BE8:
	subis r0, r28, 0x100
	cmplwi r0, 0x0
	bne lbl_80017BFC
	li r4, 0x4
	b lbl_80017C28
lbl_80017BFC:
	subis r0, r28, 0x200
	cmplwi r0, 0x0
	bne lbl_80017C10
	li r4, 0x6
	b lbl_80017C28
lbl_80017C10:
	subis r0, r28, 0x300
	cmplwi r0, 0x0
	bne lbl_80017C24
	li r4, 0x3
	b lbl_80017C28
lbl_80017C24:
	li r4, 0x5
lbl_80017C28:
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80017C9C
	lis r3, DummyCommandBlock@ha
	stw r4, -0x7AD8(r13)
	li r0, 0x0
	lwz r30, -0x7B00(r13)
	addi r3, r3, DummyCommandBlock@l
	stw r0, -0x7AE0(r13)
	li r0, 0xa
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r30)
	lwz r12, 0x28(r30)
	cmplwi r12, 0x0
	beq lbl_80017C74
	mtlr r12
	addi r4, r30, 0x0
	li r3, -0x3
	blrl
lbl_80017C74:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_80017C90
	mtlr r12
	addi r4, r30, 0x0
	li r3, 0x0
	blrl
lbl_80017C90:
	bl stateReady
	li r0, 0x1
	b lbl_80017CA0
lbl_80017C9C:
	li r0, 0x0
lbl_80017CA0:
	cmpwi r0, 0x0
	bne lbl_80017D88
	cmplwi r31, 0x2
	bne lbl_80017CC0
	mr r3, r29
	bl __DVDStoreErrorCode
	bl stateGoToRetry
	b lbl_80017D88
lbl_80017CC0:
	cmplwi r31, 0x3
	bne lbl_80017D04
	clrlwi r3, r29, 8
	subis r0, r3, 0x3
	cmplwi r0, 0x1100
	bne lbl_80017CF0
	lwz r5, -0x7B00(r13)
	lis r3, cbForUnrecoveredError@ha
	addi r4, r3, cbForUnrecoveredError@l
	lwz r3, 0x10(r5)
	bl fn_800167BC
	b lbl_80017D88
lbl_80017CF0:
	lwz r12, -0x7ABC(r13)
	lwz r3, -0x7B00(r13)
	mtlr r12
	blrl
	b lbl_80017D88
lbl_80017D04:
	subis r0, r28, 0x100
	cmplwi r0, 0x0
	bne lbl_80017D24
	lwz r3, -0x7B00(r13)
	li r0, 0x5
	stw r0, 0xc(r3)
	bl fn_800186C0
	b lbl_80017D88
lbl_80017D24:
	subis r0, r28, 0x200
	cmplwi r0, 0x0
	bne lbl_80017D44
	lwz r3, -0x7B00(r13)
	li r0, 0x3
	stw r0, 0xc(r3)
	bl stateCoverClosed
	b lbl_80017D88
lbl_80017D44:
	subis r0, r28, 0x300
	cmplwi r0, 0x0
	bne lbl_80017D64
	lwz r3, -0x7B00(r13)
	li r0, 0x4
	stw r0, 0xc(r3)
	bl fn_800186C0
	b lbl_80017D88
lbl_80017D64:
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4567
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
lbl_80017D88:
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	lwz r28, 0x10(r1)
	addi r1, r1, 0x20
	mtlr r0
	blr
}

/* cbForUnrecoveredError @0x80017DA8 | size: 0x68 */
asm void cbForUnrecoveredError(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bne lbl_80017DE4
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_80017E00
lbl_80017DE4:
	clrlwi. r0, r3, 31
	beq lbl_80017DF4
	bl stateGoToRetry
	b lbl_80017E00
lbl_80017DF4:
	lis r3, cbForUnrecoveredErrorRetry@ha
	addi r3, r3, cbForUnrecoveredErrorRetry@l
	bl fn_800169AC
lbl_80017E00:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForUnrecoveredErrorRetry @0x80017E10 | size: 0x98 */
asm void cbForUnrecoveredErrorRetry(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bne lbl_80017E4C
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_80017E98
lbl_80017E4C:
	rlwinm. r0, r3, 0, 30, 30
	lwz r3, -0x7B00(r13)
	li r4, -0x1
	stw r4, 0xc(r3)
	beq lbl_80017E7C
	lis r3, 0x123
	addi r3, r3, 0x4567
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
	b lbl_80017E98
lbl_80017E7C:
	lis r3, 0xcc00
	addi r3, r3, 0x6000
	lwz r3, 0x20(r3)
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
lbl_80017E98:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* stateGoToRetry @0x80017EA8 | size: 0x28 */
asm void stateGoToRetry(void) {
nofralloc
	mflr r0
	lis r3, cbForStateGoToRetry@ha
	stw r0, 0x4(r1)
	addi r3, r3, cbForStateGoToRetry@l
	stwu r1, -0x8(r1)
	bl DVDLowStopMotor
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForStateGoToRetry @0x80017ED0 | size: 0x158 */
asm void cbForStateGoToRetry(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	bne lbl_80017F10
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_80018014
lbl_80017F10:
	rlwinm. r0, r3, 0, 30, 30
	beq lbl_80017F40
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4567
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
	b lbl_80018014
lbl_80017F40:
	li r0, 0x0
	stw r0, -0x7ACC(r13)
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0x4
	beq lbl_80017F78
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0x5
	beq lbl_80017F78
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xd
	beq lbl_80017F78
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xf
	bne lbl_80017F80
lbl_80017F78:
	li r0, 0x1
	stw r0, -0x7AC8(r13)
lbl_80017F80:
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80017FF8
	li r0, 0x2
	lwz r31, -0x7B00(r13)
	lis r3, DummyCommandBlock@ha
	stw r0, -0x7AD8(r13)
	addi r0, r3, DummyCommandBlock@l
	li r3, 0x0
	stw r0, -0x7B00(r13)
	li r0, 0xa
	stw r3, -0x7AE0(r13)
	stw r0, 0xc(r31)
	lwz r12, 0x28(r31)
	cmplwi r12, 0x0
	beq lbl_80017FD0
	mtlr r12
	addi r4, r31, 0x0
	li r3, -0x3
	blrl
lbl_80017FD0:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_80017FEC
	mtlr r12
	addi r4, r31, 0x0
	li r3, 0x0
	blrl
lbl_80017FEC:
	bl stateReady
	li r0, 0x1
	b lbl_80017FFC
lbl_80017FF8:
	li r0, 0x0
lbl_80017FFC:
	cmpwi r0, 0x0
	bne lbl_80018014
	lwz r3, -0x7B00(r13)
	li r0, 0xb
	stw r0, 0xc(r3)
	bl fn_800186C0
lbl_80018014:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* stateCheckID @0x80018028 | size: 0xE0 */
asm void stateCheckID(void) {
nofralloc
	mflr r0
	lis r3, BB2@ha
	stw r0, 0x4(r1)
	stwu r1, -0x10(r1)
	stw r31, 0xc(r1)
	addi r31, r3, BB2@l
	lwz r0, -0x7AE4(r13)
	cmpwi r0, 0x3
	beq lbl_80018050
	b lbl_800180B8
lbl_80018050:
	lwz r4, -0x7B00(r13)
	addi r3, r31, 0x20
	lwz r4, 0x24(r4)
	bl fn_8001A1F4
	cmpwi r3, 0x0
	beq lbl_800180A8
	lwz r3, -0x7AFC(r13)
	addi r4, r31, 0x20
	li r5, 0x20
	bl memcpy
	lwz r4, -0x7B00(r13)
	li r0, 0x1
	addi r3, r31, 0x0
	stw r0, 0xc(r4)
	li r4, 0x20
	bl DCInvalidateRange
	lis r4, cbForStateCheckID3@ha
	lwz r3, -0x7B00(r13)
	addi r0, r4, cbForStateCheckID3@l
	stw r0, -0x7ABC(r13)
	bl cbForStateCheckID3
	b lbl_800180F4
lbl_800180A8:
	lis r3, cbForStateCoverClosed@ha
	addi r3, r3, cbForStateCoverClosed@l
	bl DVDLowStopMotor
	b lbl_800180F4
lbl_800180B8:
	lwz r4, -0x7AFC(r13)
	addi r3, r31, 0x20
	li r5, 0x20
	bl strncmp
	cmpwi r3, 0x0
	beq lbl_800180E0
	lis r3, cbForStateCoverClosed@ha
	addi r3, r3, cbForStateCoverClosed@l
	bl DVDLowStopMotor
	b lbl_800180F4
lbl_800180E0:
	lis r4, cbForStateCheckID2@ha
	lwz r3, -0x7B00(r13)
	addi r0, r4, cbForStateCheckID2@l
	stw r0, -0x7ABC(r13)
	bl cbForStateCheckID2
lbl_800180F4:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* cbForStateCheckID2 @0x80018108 | size: 0x34 */
asm void cbForStateCheckID2(void) {
nofralloc
	mflr r0
	lis r3, cbForStateCheckID2b@ha
	stw r0, 0x4(r1)
	addi r5, r3, cbForStateCheckID2b@l
	stwu r1, -0x8(r1)
	lwz r4, -0x7AFC(r13)
	lbz r3, 0x8(r4)
	li r4, 0xa
	bl fn_80016BF8
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForStateCheckID3 @0x8001813C | size: 0x34 */
asm void cbForStateCheckID3(void) {
nofralloc
	mflr r0
	lis r3, cbForStateCheckID1@ha
	stw r0, 0x4(r1)
	addi r5, r3, cbForStateCheckID1@l
	stwu r1, -0x8(r1)
	lwz r4, -0x7AFC(r13)
	lbz r3, 0x8(r4)
	li r4, 0xa
	bl fn_80016BF8
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForStateCheckID1 @0x80018170 | size: 0x74 */
asm void cbForStateCheckID1(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bne lbl_800181AC
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_800181D4
lbl_800181AC:
	clrlwi. r0, r3, 31
	beq lbl_800181C8
	li r0, 0x0
	lwz r3, -0x7B00(r13)
	stw r0, -0x7ACC(r13)
	bl stateCheckID2
	b lbl_800181D4
lbl_800181C8:
	lis r3, cbForStateGettingError@ha
	addi r3, r3, cbForStateGettingError@l
	bl fn_800169AC
lbl_800181D4:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* stateCheckID2 @0x800181E4 | size: 0x38 */
asm void stateCheckID2(void) {
nofralloc
	mflr r0
	lis r3, BB2@ha
	stw r0, 0x4(r1)
	lis r4, cbForStateCheckID2a@ha
	addi r6, r4, cbForStateCheckID2a@l
	stwu r1, -0x8(r1)
	addi r3, r3, BB2@l
	li r4, 0x20
	li r5, 0x420
	bl fn_80016524
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForStateCoverClosed @0x8001821C | size: 0x114 */
asm void cbForStateCoverClosed(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	bne lbl_8001825C
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_8001831C
lbl_8001825C:
	rlwinm. r0, r3, 0, 30, 30
	beq lbl_8001828C
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4567
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
	b lbl_8001831C
lbl_8001828C:
	li r4, 0x0
	stw r4, -0x7ACC(r13)
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80018304
	li r0, 0x1
	lwz r31, -0x7B00(r13)
	stw r0, -0x7AD8(r13)
	lis r3, DummyCommandBlock@ha
	addi r3, r3, DummyCommandBlock@l
	stw r4, -0x7AE0(r13)
	li r0, 0xa
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r31)
	lwz r12, 0x28(r31)
	cmplwi r12, 0x0
	beq lbl_800182E0
	mtlr r12
	addi r4, r31, 0x0
	li r3, -0x3
	blrl
lbl_800182E0:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_800182FC
	mtlr r12
	addi r4, r31, 0x0
	li r3, 0x0
	blrl
lbl_800182FC:
	bl stateReady
	li r4, 0x1
lbl_80018304:
	cmpwi r4, 0x0
	bne lbl_8001831C
	lwz r3, -0x7B00(r13)
	li r0, 0x6
	stw r0, 0xc(r3)
	bl fn_800186C0
lbl_8001831C:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* cbForStateCheckID2a @0x80018330 | size: 0xE4 */
asm void cbForStateCheckID2a(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	bne lbl_80018370
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_80018400
lbl_80018370:
	clrlwi. r0, r3, 31
	beq lbl_800183F4
	lis r3, stateReadingFST@ha
	lwz r4, -0x7AF8(r13)
	addi r0, r3, stateReadingFST@l
	li r5, 0x0
	stw r0, -0x7ABC(r13)
	lis r3, BB2@ha
	stw r5, -0x7ACC(r13)
	addi r3, r3, BB2@l
	addi r31, r3, 0x8
	lwz r3, 0x3c(r4)
	lwz r0, 0x0(r31)
	cmplw r3, r0
	bge lbl_800183C4
	lis r3, lbl_80123FE4@ha
	crxor 6,6,6
	addi r5, r3, lbl_80123FE4@l
	addi r3, r13, -0x7F3C
	li r4, 0x287
	bl OSPanic
lbl_800183C4:
	lis r3, BB2@ha
	lwz r6, 0x0(r31)
	addi r5, r3, BB2@l
	lwz r7, -0x7AF8(r13)
	lis r4, cbForStateReadingFST@ha
	lwz r5, 0x4(r5)
	addi r0, r6, 0x1f
	lwz r3, 0x38(r7)
	addi r6, r4, cbForStateReadingFST@l
	clrrwi r4, r0, 5
	bl fn_80016524
	b lbl_80018400
lbl_800183F4:
	lis r3, cbForStateGettingError@ha
	addi r3, r3, cbForStateGettingError@l
	bl fn_800169AC
lbl_80018400:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* cbForStateCheckID2b @0x80018414 | size: 0xFC */
asm void cbForStateCheckID2b(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	bne lbl_80018454
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_800184FC
lbl_80018454:
	clrlwi. r0, r3, 31
	beq lbl_800184F0
	li r4, 0x0
	stw r4, -0x7ACC(r13)
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_800184D0
	stw r4, -0x7AD8(r13)
	lis r3, DummyCommandBlock@ha
	lwz r31, -0x7B00(r13)
	addi r3, r3, DummyCommandBlock@l
	stw r4, -0x7AE0(r13)
	li r0, 0xa
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r31)
	lwz r12, 0x28(r31)
	cmplwi r12, 0x0
	beq lbl_800184AC
	mtlr r12
	addi r4, r31, 0x0
	li r3, -0x3
	blrl
lbl_800184AC:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_800184C8
	mtlr r12
	addi r4, r31, 0x0
	li r3, 0x0
	blrl
lbl_800184C8:
	bl stateReady
	li r4, 0x1
lbl_800184D0:
	cmpwi r4, 0x0
	bne lbl_800184FC
	lwz r3, -0x7B00(r13)
	li r0, 0x1
	stw r0, 0xc(r3)
	lwz r3, -0x7B00(r13)
	bl stateBusy
	b lbl_800184FC
lbl_800184F0:
	lis r3, cbForStateGettingError@ha
	addi r3, r3, cbForStateGettingError@l
	bl fn_800169AC
lbl_800184FC:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* AlarmHandler @0x80018510 | size: 0x44 */
asm void AlarmHandler(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bl DVDReset
	lis r3, lbl_8015CE60@ha
	addi r3, r3, lbl_8015CE60@l
	li r4, 0x20
	bl DCInvalidateRange
	lis r4, cbForStateCoverClosed_CMD@ha
	lwz r3, -0x7B00(r13)
	addi r0, r4, cbForStateCoverClosed_CMD@l
	stw r0, -0x7ABC(r13)
	bl cbForStateCoverClosed_CMD
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* stateCoverClosed @0x80018554 | size: 0xCC */
asm void stateCoverClosed(void) {
nofralloc
	mflr r0
	lis r3, BB2@ha
	stw r0, 0x4(r1)
	stwu r1, -0x10(r1)
	stw r31, 0xc(r1)
	addi r31, r3, BB2@l
	lwz r0, -0x7AE4(r13)
	cmpwi r0, 0xd
	beq lbl_8001859C
	bge lbl_80018590
	cmpwi r0, 0x6
	bge lbl_800185CC
	cmpwi r0, 0x4
	bge lbl_8001859C
	b lbl_800185CC
lbl_80018590:
	cmpwi r0, 0xf
	beq lbl_8001859C
	b lbl_800185CC
lbl_8001859C:
	bl __DVDClearWaitingQueue
	lwz r4, -0x7B00(r13)
	addi r0, r31, 0x40
	stw r0, -0x7B00(r13)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_800185C4
	mtlr r12
	li r3, -0x4
	blrl
lbl_800185C4:
	bl stateReady
	b lbl_8001860C
lbl_800185CC:
	bl DVDReset
	addi r3, r31, 0x70
	bl OSCreateAlarm
	lis r3, 0x8000
	lwz r0, 0xf8(r3)
	lis r4, 0x1062
	lis r3, AlarmHandler@ha
	srwi r0, r0, 2
	addi r4, r4, 0x4dd3
	mulhwu r0, r4, r0
	srwi r0, r0, 6
	mulli r6, r0, 0x47e
	addi r7, r3, AlarmHandler@l
	addi r3, r31, 0x70
	li r5, 0x0
	bl OSSetAlarm
lbl_8001860C:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* cbForStateCoverClosed_CMD @0x80018620 | size: 0x30 */
asm void cbForStateCoverClosed_CMD(void) {
nofralloc
	mflr r0
	lis r3, lbl_8015CE60@ha
	stw r0, 0x4(r1)
	lis r4, cbForCoverClosedCheckID@ha
	addi r3, r3, lbl_8015CE60@l
	stwu r1, -0x8(r1)
	addi r4, r4, cbForCoverClosedCheckID@l
	bl fn_8001687C
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForCoverClosedCheckID @0x80018650 | size: 0x70 */
asm void cbForCoverClosedCheckID(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bne lbl_8001868C
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_800186B0
lbl_8001868C:
	clrlwi. r0, r3, 31
	beq lbl_800186A4
	li r0, 0x0
	stw r0, -0x7ACC(r13)
	bl stateCheckID
	b lbl_800186B0
lbl_800186A4:
	lis r3, cbForStateGettingError@ha
	addi r3, r3, cbForStateGettingError@l
	bl fn_800169AC
lbl_800186B0:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* fn_800186C0 @0x800186C0 | size: 0x28 */
asm void fn_800186C0(void) {
nofralloc
	mflr r0
	lis r3, cbForStateMotorStopped@ha
	stw r0, 0x4(r1)
	addi r3, r3, cbForStateMotorStopped@l
	stwu r1, -0x8(r1)
	bl DVDLowWaitCoverClose
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForStateMotorStopped @0x800186E8 | size: 0xE4 */
asm void cbForStateMotorStopped(void) {
nofralloc
	mflr r0
	lis r3, 0xcc00
	stw r0, 0x4(r1)
	li r0, 0x0
	lis r4, BB2@ha
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	addi r31, r4, BB2@l
	stw r0, 0x6004(r3)
	li r0, 0x3
	lwz r3, -0x7B00(r13)
	stw r0, 0xc(r3)
	lwz r0, -0x7AE4(r13)
	cmpwi r0, 0xd
	beq lbl_80018748
	bge lbl_8001873C
	cmpwi r0, 0x6
	bge lbl_80018778
	cmpwi r0, 0x4
	bge lbl_80018748
	b lbl_80018778
lbl_8001873C:
	cmpwi r0, 0xf
	beq lbl_80018748
	b lbl_80018778
lbl_80018748:
	bl __DVDClearWaitingQueue
	lwz r4, -0x7B00(r13)
	addi r0, r31, 0x40
	stw r0, -0x7B00(r13)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80018770
	mtlr r12
	li r3, -0x4
	blrl
lbl_80018770:
	bl stateReady
	b lbl_800187B8
lbl_80018778:
	bl DVDReset
	addi r3, r31, 0x70
	bl OSCreateAlarm
	lis r3, 0x8000
	lwz r0, 0xf8(r3)
	lis r4, 0x1062
	lis r3, AlarmHandler@ha
	srwi r0, r0, 2
	addi r4, r4, 0x4dd3
	mulhwu r0, r4, r0
	srwi r0, r0, 6
	mulli r6, r0, 0x47e
	addi r7, r3, AlarmHandler@l
	addi r3, r31, 0x70
	li r5, 0x0
	bl OSSetAlarm
lbl_800187B8:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* stateReady @0x800187CC | size: 0x230 */
asm void stateReady(void) {
nofralloc
	mflr r0
	lis r3, BB2@ha
	stw r0, 0x4(r1)
	stwu r1, -0x10(r1)
	stw r31, 0xc(r1)
	addi r31, r3, BB2@l
	bl __DVDCheckWaitingQueue
	cmpwi r3, 0x0
	bne lbl_800187FC
	li r0, 0x0
	stw r0, -0x7B00(r13)
	b lbl_800189E8
lbl_800187FC:
	lwz r0, -0x7AF4(r13)
	cmpwi r0, 0x0
	beq lbl_8001881C
	li r3, 0x1
	li r0, 0x0
	stw r3, -0x7AF0(r13)
	stw r0, -0x7B00(r13)
	b lbl_800189E8
lbl_8001881C:
	bl __DVDPopWaitingQueue
	lwz r0, -0x7AE8(r13)
	stw r3, -0x7B00(r13)
	cmpwi r0, 0x0
	beq lbl_80018868
	lwz r3, -0x7B00(r13)
	li r4, -0x1
	addi r0, r31, 0x40
	stw r4, 0xc(r3)
	lwz r4, -0x7B00(r13)
	stw r0, -0x7B00(r13)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80018860
	mtlr r12
	li r3, -0x1
	blrl
lbl_80018860:
	bl stateReady
	b lbl_800189E8
lbl_80018868:
	lwz r4, -0x7B00(r13)
	lwz r0, 0x8(r4)
	stw r0, -0x7AE4(r13)
	lwz r0, -0x7AD8(r13)
	cmplwi r0, 0x0
	beq lbl_800189D8
	lwz r0, -0x7AD8(r13)
	cmpwi r0, 0x4
	beq lbl_800188EC
	bge lbl_800188A8
	cmpwi r0, 0x2
	beq lbl_800188BC
	bge lbl_800188D4
	cmpwi r0, 0x1
	bge lbl_80018904
	b lbl_800189CC
lbl_800188A8:
	cmpwi r0, 0x8
	bge lbl_800189CC
	cmpwi r0, 0x6
	bge lbl_80018904
	b lbl_800189B0
lbl_800188BC:
	li r0, 0xb
	lis r3, cbForStateMotorStopped@ha
	stw r0, 0xc(r4)
	addi r3, r3, cbForStateMotorStopped@l
	bl DVDLowWaitCoverClose
	b lbl_800189CC
lbl_800188D4:
	li r0, 0x4
	lis r3, cbForStateMotorStopped@ha
	stw r0, 0xc(r4)
	addi r3, r3, cbForStateMotorStopped@l
	bl DVDLowWaitCoverClose
	b lbl_800189CC
lbl_800188EC:
	li r0, 0x5
	lis r3, cbForStateMotorStopped@ha
	stw r0, 0xc(r4)
	addi r3, r3, cbForStateMotorStopped@l
	bl DVDLowWaitCoverClose
	b lbl_800189CC
lbl_80018904:
	li r0, 0x3
	stw r0, 0xc(r4)
	lwz r0, -0x7AE4(r13)
	cmpwi r0, 0xd
	beq lbl_8001893C
	bge lbl_80018930
	cmpwi r0, 0x6
	bge lbl_8001896C
	cmpwi r0, 0x4
	bge lbl_8001893C
	b lbl_8001896C
lbl_80018930:
	cmpwi r0, 0xf
	beq lbl_8001893C
	b lbl_8001896C
lbl_8001893C:
	bl __DVDClearWaitingQueue
	lwz r4, -0x7B00(r13)
	addi r0, r31, 0x40
	stw r0, -0x7B00(r13)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80018964
	mtlr r12
	li r3, -0x4
	blrl
lbl_80018964:
	bl stateReady
	b lbl_800189CC
lbl_8001896C:
	bl DVDReset
	addi r3, r31, 0x70
	bl OSCreateAlarm
	lis r3, 0x8000
	lwz r0, 0xf8(r3)
	lis r4, 0x1062
	lis r3, AlarmHandler@ha
	srwi r0, r0, 2
	addi r4, r4, 0x4dd3
	mulhwu r0, r4, r0
	srwi r0, r0, 6
	mulli r6, r0, 0x47e
	addi r7, r3, AlarmHandler@l
	addi r3, r31, 0x70
	li r5, 0x0
	bl OSSetAlarm
	b lbl_800189CC
lbl_800189B0:
	li r0, -0x1
	stw r0, 0xc(r4)
	lwz r3, -0x7AD4(r13)
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
lbl_800189CC:
	li r0, 0x0
	stw r0, -0x7AD8(r13)
	b lbl_800189E8
lbl_800189D8:
	li r0, 0x1
	stw r0, 0xc(r4)
	lwz r3, -0x7B00(r13)
	bl stateBusy
lbl_800189E8:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* stateBusy @0x800189FC | size: 0x320 */
asm void stateBusy(void) {
nofralloc
	mflr r0
	lis r4, stateBusy@ha
	stw r0, 0x4(r1)
	addi r0, r4, stateBusy@l
	mr r7, r3
	stwu r1, -0x8(r1)
	stw r0, -0x7ABC(r13)
	lwz r0, 0x8(r3)
	cmplwi r0, 0xf
	bgt lbl_80018CF4
	lis r3, jumptable_80124018@ha
	addi r3, r3, jumptable_80124018@l
	slwi r0, r0, 2
	lwzx r0, r3, r0
	mtctr r0
	bctr
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r5, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r5)
	li r0, 0x20
	addi r4, r3, cbForStateBusy@l
	stw r0, 0x1c(r7)
	lwz r3, 0x18(r7)
	bl fn_8001687C
	b lbl_80018D0C
	lwz r0, 0x14(r7)
	cmplwi r0, 0x0
	bne lbl_80018AAC
	lis r3, DummyCommandBlock@ha
	lwz r4, -0x7B00(r13)
	addi r0, r3, DummyCommandBlock@l
	stw r0, -0x7B00(r13)
	li r0, 0x0
	stw r0, 0xc(r4)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80018AA4
	mtlr r12
	li r3, 0x0
	blrl
lbl_80018AA4:
	bl stateReady
	b lbl_80018D0C
lbl_80018AAC:
	lis r3, 0xcc00
	addi r3, r3, 0x6000
	lwz r0, 0x4(r3)
	lis r4, 0x8
	stw r0, 0x4(r3)
	lwz r3, 0x20(r7)
	lwz r0, 0x14(r7)
	subf r0, r3, r0
	cmplw r0, r4
	ble lbl_80018AD8
	b lbl_80018ADC
lbl_80018AD8:
	mr r4, r0
lbl_80018ADC:
	stw r4, 0x1c(r7)
	lis r3, cbForStateBusy@ha
	addi r6, r3, cbForStateBusy@l
	lwz r5, 0x20(r7)
	lwz r3, 0x18(r7)
	lwz r0, 0x10(r7)
	add r3, r3, r5
	lwz r4, 0x1c(r7)
	add r5, r0, r5
	bl fn_80016524
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r5, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r5)
	addi r4, r3, cbForStateBusy@l
	lwz r3, 0x10(r7)
	bl fn_800167BC
	b lbl_80018D0C
	lis r3, cbForStateBusy@ha
	addi r3, r3, cbForStateBusy@l
	bl DVDLowStopMotor
	b lbl_80018D0C
	lis r3, cbForStateBusy@ha
	addi r3, r3, cbForStateBusy@l
	bl DVDLowStopMotor
	b lbl_80018D0C
	lis r3, 0xcc00
	addi r3, r3, 0x6000
	lwz r0, 0x4(r3)
	stw r0, 0x4(r3)
	lwz r0, -0x7AEC(r13)
	cmpwi r0, 0x0
	beq lbl_80018B88
	lwz r5, -0x7B00(r13)
	li r0, 0x0
	lis r3, cbForStateBusy@ha
	stw r0, 0x1c(r5)
	addi r4, r3, cbForStateBusy@l
	li r3, 0x0
	bl fn_80016B6C
	b lbl_80018D0C
lbl_80018B88:
	lwz r4, -0x7B00(r13)
	li r0, 0x1
	lis r3, cbForStateBusy@ha
	stw r0, 0x1c(r4)
	addi r6, r3, cbForStateBusy@l
	li r3, 0x0
	lwz r4, 0x14(r7)
	lwz r5, 0x10(r7)
	bl fn_80016AD4
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r4, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r4)
	addi r6, r3, cbForStateBusy@l
	lis r3, 0x1
	li r4, 0x0
	li r5, 0x0
	bl fn_80016AD4
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r4, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r4)
	li r0, 0x1
	addi r6, r3, cbForStateBusy@l
	stw r0, -0x7AEC(r13)
	li r3, 0x0
	li r4, 0x0
	li r5, 0x0
	bl fn_80016AD4
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r5, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r5)
	addi r4, r3, cbForStateBusy@l
	li r3, 0x0
	bl fn_80016B6C
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r5, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r5)
	addi r4, r3, cbForStateBusy@l
	lis r3, 0x1
	bl fn_80016B6C
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r5, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r5)
	addi r4, r3, cbForStateBusy@l
	lis r3, 0x2
	bl fn_80016B6C
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r5, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r5)
	addi r4, r3, cbForStateBusy@l
	lis r3, 0x3
	bl fn_80016B6C
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r4, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r4)
	addi r5, r3, cbForStateBusy@l
	lwz r3, 0x10(r7)
	lwz r4, 0x14(r7)
	bl fn_80016BF8
	b lbl_80018D0C
	lis r3, 0xcc00
	lwz r0, 0x6004(r3)
	addi r5, r3, 0x6000
	lis r3, cbForStateBusy@ha
	stw r0, 0x4(r5)
	li r0, 0x20
	addi r4, r3, cbForStateBusy@l
	stw r0, 0x1c(r7)
	lwz r3, 0x18(r7)
	bl fn_80016A38
	b lbl_80018D0C
lbl_80018CF4:
	lwz r12, -0x7F40(r13)
	lis r3, cbForStateBusy@ha
	addi r4, r3, cbForStateBusy@l
	mtlr r12
	addi r3, r7, 0x0
	blrl
lbl_80018D0C:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* cbForStateBusy @0x80018D1C | size: 0x638 */
asm void cbForStateBusy(void) {
nofralloc
	mflr r0
	cmplwi r3, 0x10
	stw r0, 0x4(r1)
	lis r4, BB2@ha
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	addi r31, r4, BB2@l
	stw r30, 0x10(r1)
	bne lbl_80018D68
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4568
	bl __DVDStoreErrorCode
	bl DVDReset
	li r3, 0x0
	bl cbForStateError
	b lbl_8001933C
lbl_80018D68:
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0x3
	beq lbl_80018D80
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xf
	bne lbl_80018E68
lbl_80018D80:
	rlwinm. r0, r3, 0, 30, 30
	beq lbl_80018DB0
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4567
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
	b lbl_8001933C
lbl_80018DB0:
	li r0, 0x0
	stw r0, -0x7ACC(r13)
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xf
	bne lbl_80018DCC
	li r0, 0x1
	stw r0, -0x7AC8(r13)
lbl_80018DCC:
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80018E40
	li r0, 0x7
	lwz r30, -0x7B00(r13)
	stw r0, -0x7AD8(r13)
	addi r3, r31, 0x40
	li r0, 0x0
	stw r0, -0x7AE0(r13)
	li r0, 0xa
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r30)
	lwz r12, 0x28(r30)
	cmplwi r12, 0x0
	beq lbl_80018E18
	mtlr r12
	addi r4, r30, 0x0
	li r3, -0x3
	blrl
lbl_80018E18:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_80018E34
	mtlr r12
	addi r4, r30, 0x0
	li r3, 0x0
	blrl
lbl_80018E34:
	bl stateReady
	li r0, 0x1
	b lbl_80018E44
lbl_80018E40:
	li r0, 0x0
lbl_80018E44:
	cmpwi r0, 0x0
	bne lbl_8001933C
	lwz r4, -0x7B00(r13)
	li r0, 0x7
	lis r3, cbForStateMotorStopped@ha
	stw r0, 0xc(r4)
	addi r3, r3, cbForStateMotorStopped@l
	bl DVDLowWaitCoverClose
	b lbl_8001933C
lbl_80018E68:
	lwz r4, -0x7AE4(r13)
	cmplwi r4, 0x1
	beq lbl_80018E88
	subi r0, r4, 0x4
	cmplwi r0, 0x1
	ble lbl_80018E88
	cmplwi r4, 0xe
	bne lbl_80018E90
lbl_80018E88:
	li r0, 0x1
	b lbl_80018EA8
lbl_80018E90:
	lwz r0, -0x7F34(r13)
	cmplw r4, r0
	bne lbl_80018EA4
	li r0, 0x1
	b lbl_80018EA8
lbl_80018EA4:
	li r0, 0x0
lbl_80018EA8:
	cmpwi r0, 0x0
	beq lbl_80018ED4
	lwz r6, -0x7B00(r13)
	lis r4, 0xcc00
	addi r4, r4, 0x6000
	lwz r4, 0x18(r4)
	lwz r0, 0x1c(r6)
	lwz r5, 0x20(r6)
	subf r0, r4, r0
	add r0, r5, r0
	stw r0, 0x20(r6)
lbl_80018ED4:
	rlwinm. r0, r3, 0, 28, 28
	beq lbl_80018F38
	lwz r30, -0x7B00(r13)
	addi r3, r31, 0x40
	li r0, 0x0
	stw r0, -0x7AE0(r13)
	li r0, 0xa
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r30)
	lwz r12, 0x28(r30)
	cmplwi r12, 0x0
	beq lbl_80018F14
	mtlr r12
	addi r4, r30, 0x0
	li r3, -0x3
	blrl
lbl_80018F14:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_80018F30
	mtlr r12
	addi r4, r30, 0x0
	li r3, 0x0
	blrl
lbl_80018F30:
	bl stateReady
	b lbl_8001933C
lbl_80018F38:
	clrlwi. r0, r3, 31
	beq lbl_8001920C
	li r4, 0x0
	stw r4, -0x7ACC(r13)
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80018FB0
	stw r4, -0x7AD8(r13)
	addi r3, r31, 0x40
	lwz r30, -0x7B00(r13)
	li r0, 0xa
	stw r4, -0x7AE0(r13)
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r30)
	lwz r12, 0x28(r30)
	cmplwi r12, 0x0
	beq lbl_80018F8C
	mtlr r12
	addi r4, r30, 0x0
	li r3, -0x3
	blrl
lbl_80018F8C:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_80018FA8
	mtlr r12
	addi r4, r30, 0x0
	li r3, 0x0
	blrl
lbl_80018FA8:
	bl stateReady
	li r4, 0x1
lbl_80018FB0:
	cmpwi r4, 0x0
	bne lbl_8001933C
	lwz r3, -0x7AE4(r13)
	cmplwi r3, 0x1
	beq lbl_80018FD8
	subi r0, r3, 0x4
	cmplwi r0, 0x1
	ble lbl_80018FD8
	cmplwi r3, 0xe
	bne lbl_80018FE0
lbl_80018FD8:
	li r0, 0x1
	b lbl_80018FF8
lbl_80018FE0:
	lwz r0, -0x7F34(r13)
	cmplw r3, r0
	bne lbl_80018FF4
	li r0, 0x1
	b lbl_80018FF8
lbl_80018FF4:
	li r0, 0x0
lbl_80018FF8:
	cmpwi r0, 0x0
	beq lbl_80019050
	lwz r3, -0x7B00(r13)
	lwz r4, 0x20(r3)
	lwz r0, 0x14(r3)
	cmplw r4, r0
	beq lbl_8001901C
	bl stateBusy
	b lbl_8001933C
lbl_8001901C:
	addi r0, r31, 0x40
	stw r0, -0x7B00(r13)
	li r0, 0x0
	addi r4, r3, 0x0
	stw r0, 0xc(r3)
	lwz r12, 0x28(r3)
	cmplwi r12, 0x0
	beq lbl_80019048
	lwz r3, 0x20(r4)
	mtlr r12
	blrl
lbl_80019048:
	bl stateReady
	b lbl_8001933C
lbl_80019050:
	lwz r4, -0x7AE4(r13)
	subi r0, r4, 0x9
	cmplwi r0, 0x3
	bgt lbl_80019068
	li r0, 0x1
	b lbl_800190AC
lbl_80019068:
	lis r3, lbl_80124058@ha
	lwzu r0, lbl_80124058@l(r3)
	cmplw r4, r0
	bne lbl_80019080
	li r0, 0x1
	b lbl_800190AC
lbl_80019080:
	lwzu r0, 0x4(r3)
	cmplw r4, r0
	bne lbl_80019094
	li r0, 0x1
	b lbl_800190AC
lbl_80019094:
	lwz r0, 0x4(r3)
	cmplw r4, r0
	bne lbl_800190A8
	li r0, 0x1
	b lbl_800190AC
lbl_800190A8:
	li r0, 0x0
lbl_800190AC:
	cmpwi r0, 0x0
	beq lbl_80019118
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xb
	beq lbl_800190CC
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xa
	bne lbl_800190DC
lbl_800190CC:
	lis r3, 0xcc00
	lwz r0, 0x6020(r3)
	slwi r3, r0, 2
	b lbl_800190E8
lbl_800190DC:
	lis r3, 0xcc00
	addi r3, r3, 0x6000
	lwz r3, 0x20(r3)
lbl_800190E8:
	lwz r4, -0x7B00(r13)
	addi r5, r31, 0x40
	li r0, 0x0
	stw r5, -0x7B00(r13)
	stw r0, 0xc(r4)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80019110
	mtlr r12
	blrl
lbl_80019110:
	bl stateReady
	b lbl_8001933C
lbl_80019118:
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0x6
	bne lbl_800191D8
	lwz r4, -0x7B00(r13)
	addi r5, r4, 0x1c
	lwz r0, 0x1c(r4)
	cmplwi r0, 0x0
	bne lbl_800191A8
	lis r3, 0xcc00
	lwz r0, 0x6020(r3)
	clrlwi. r0, r0, 31
	beq lbl_80019178
	addi r0, r31, 0x40
	stw r0, -0x7B00(r13)
	li r0, 0x9
	stw r0, 0xc(r4)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80019170
	mtlr r12
	li r3, -0x2
	blrl
lbl_80019170:
	bl stateReady
	b lbl_8001933C
lbl_80019178:
	li r0, 0x0
	stw r0, -0x7AEC(r13)
	li r0, 0x1
	lis r3, cbForStateBusy@ha
	stw r0, 0x0(r5)
	addi r6, r3, cbForStateBusy@l
	li r3, 0x0
	lwz r5, -0x7B00(r13)
	lwz r4, 0x14(r5)
	lwz r5, 0x10(r5)
	bl fn_80016AD4
	b lbl_8001933C
lbl_800191A8:
	addi r0, r31, 0x40
	stw r0, -0x7B00(r13)
	li r0, 0x0
	stw r0, 0xc(r4)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_800191D0
	mtlr r12
	li r3, 0x0
	blrl
lbl_800191D0:
	bl stateReady
	b lbl_8001933C
lbl_800191D8:
	lwz r4, -0x7B00(r13)
	addi r3, r31, 0x40
	li r0, 0x0
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r4)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80019204
	mtlr r12
	li r3, 0x0
	blrl
lbl_80019204:
	bl stateReady
	b lbl_8001933C
lbl_8001920C:
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xe
	bne lbl_80019240
	lwz r4, -0x7B00(r13)
	li r0, -0x1
	lis r3, 0x123
	stw r0, 0xc(r4)
	addi r3, r3, 0x4567
	bl __DVDStoreErrorCode
	lis r3, cbForStateError@ha
	addi r3, r3, cbForStateError@l
	bl DVDLowStopMotor
	b lbl_8001933C
lbl_80019240:
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0x1
	beq lbl_80019270
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0x4
	beq lbl_80019270
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0x5
	beq lbl_80019270
	lwz r0, -0x7AE4(r13)
	cmplwi r0, 0xe
	bne lbl_80019330
lbl_80019270:
	lwz r30, -0x7B00(r13)
	lwz r3, 0x20(r30)
	lwz r0, 0x14(r30)
	cmplw r3, r0
	bne lbl_80019330
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_800192F0
	li r4, 0x0
	stw r4, -0x7AD8(r13)
	addi r3, r31, 0x40
	li r0, 0xa
	stw r4, -0x7AE0(r13)
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r30)
	lwz r12, 0x28(r30)
	cmplwi r12, 0x0
	beq lbl_800192C8
	mtlr r12
	addi r4, r30, 0x0
	li r3, -0x3
	blrl
lbl_800192C8:
	lwz r12, -0x7ADC(r13)
	cmplwi r12, 0x0
	beq lbl_800192E4
	mtlr r12
	addi r4, r30, 0x0
	li r3, 0x0
	blrl
lbl_800192E4:
	bl stateReady
	li r0, 0x1
	b lbl_800192F4
lbl_800192F0:
	li r0, 0x0
lbl_800192F4:
	cmpwi r0, 0x0
	bne lbl_8001933C
	lwz r4, -0x7B00(r13)
	addi r3, r31, 0x40
	li r0, 0x0
	stw r3, -0x7B00(r13)
	stw r0, 0xc(r4)
	lwz r12, 0x28(r4)
	cmplwi r12, 0x0
	beq lbl_80019328
	lwz r3, 0x20(r4)
	mtlr r12
	blrl
lbl_80019328:
	bl stateReady
	b lbl_8001933C
lbl_80019330:
	lis r3, cbForStateGettingError@ha
	addi r3, r3, cbForStateGettingError@l
	bl fn_800169AC
lbl_8001933C:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* DVDReadAbsAsyncPrio @0x80019354 | size: 0xDC */
asm void DVDReadAbsAsyncPrio(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x1
	stwu r1, -0x38(r1)
	stw r31, 0x34(r1)
	addi r31, r8, 0x0
	stw r30, 0x30(r1)
	stw r29, 0x2c(r1)
	addi r29, r3, 0x0
	stw r0, 0x8(r3)
	li r0, 0x0
	stw r4, 0x18(r3)
	stw r5, 0x14(r3)
	stw r6, 0x10(r3)
	stw r0, 0x20(r3)
	stw r7, 0x28(r3)
	lwz r0, -0x7F44(r13)
	cmpwi r0, 0x0
	beq lbl_800193CC
	lwz r3, 0x8(r29)
	cmplwi r3, 0x1
	beq lbl_800193C0
	subi r0, r3, 0x4
	cmplwi r0, 0x1
	ble lbl_800193C0
	cmplwi r3, 0xe
	bne lbl_800193CC
lbl_800193C0:
	lwz r3, 0x18(r29)
	lwz r4, 0x14(r29)
	bl DCInvalidateRange
lbl_800193CC:
	bl OSDisableInterrupts
	li r0, 0x2
	stw r0, 0xc(r29)
	addi r30, r3, 0x0
	addi r3, r31, 0x0
	addi r4, r29, 0x0
	bl __DVDPushWaitingQueue
	lwz r0, -0x7B00(r13)
	addi r31, r3, 0x0
	cmplwi r0, 0x0
	bne lbl_80019408
	lwz r0, -0x7AF4(r13)
	cmpwi r0, 0x0
	bne lbl_80019408
	bl stateReady
lbl_80019408:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x3c(r1)
	lwz r31, 0x34(r1)
	lwz r30, 0x30(r1)
	lwz r29, 0x2c(r1)
	addi r1, r1, 0x38
	mtlr r0
	blr
}

/* DVDReadAbsAsyncForBS @0x80019430 | size: 0xD0 */
asm void DVDReadAbsAsyncForBS(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x4
	stwu r1, -0x30(r1)
	stw r31, 0x2c(r1)
	addi r31, r3, 0x0
	stw r30, 0x28(r1)
	stw r0, 0x8(r3)
	li r0, 0x0
	stw r4, 0x18(r3)
	stw r5, 0x14(r3)
	stw r6, 0x10(r3)
	stw r0, 0x20(r3)
	stw r7, 0x28(r3)
	lwz r0, -0x7F44(r13)
	cmpwi r0, 0x0
	beq lbl_800194A0
	lwz r3, 0x8(r31)
	cmplwi r3, 0x1
	beq lbl_80019494
	subi r0, r3, 0x4
	cmplwi r0, 0x1
	ble lbl_80019494
	cmplwi r3, 0xe
	bne lbl_800194A0
lbl_80019494:
	lwz r3, 0x18(r31)
	lwz r4, 0x14(r31)
	bl DCInvalidateRange
lbl_800194A0:
	bl OSDisableInterrupts
	li r0, 0x2
	stw r0, 0xc(r31)
	addi r30, r3, 0x0
	addi r4, r31, 0x0
	li r3, 0x2
	bl __DVDPushWaitingQueue
	lwz r0, -0x7B00(r13)
	addi r31, r3, 0x0
	cmplwi r0, 0x0
	bne lbl_800194DC
	lwz r0, -0x7AF4(r13)
	cmpwi r0, 0x0
	bne lbl_800194DC
	bl stateReady
lbl_800194DC:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x34(r1)
	lwz r31, 0x2c(r1)
	lwz r30, 0x28(r1)
	addi r1, r1, 0x30
	mtlr r0
	blr
}

/* DVDReadDiskID @0x80019500 | size: 0xD4 */
asm void DVDReadDiskID(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x5
	stwu r1, -0x28(r1)
	stw r31, 0x24(r1)
	addi r31, r3, 0x0
	stw r30, 0x20(r1)
	stw r0, 0x8(r3)
	li r3, 0x20
	li r0, 0x0
	stw r4, 0x18(r31)
	stw r3, 0x14(r31)
	stw r0, 0x10(r31)
	stw r0, 0x20(r31)
	stw r5, 0x28(r31)
	lwz r0, -0x7F44(r13)
	cmpwi r0, 0x0
	beq lbl_80019574
	lwz r3, 0x8(r31)
	cmplwi r3, 0x1
	beq lbl_80019568
	subi r0, r3, 0x4
	cmplwi r0, 0x1
	ble lbl_80019568
	cmplwi r3, 0xe
	bne lbl_80019574
lbl_80019568:
	lwz r3, 0x18(r31)
	lwz r4, 0x14(r31)
	bl DCInvalidateRange
lbl_80019574:
	bl OSDisableInterrupts
	li r0, 0x2
	stw r0, 0xc(r31)
	addi r30, r3, 0x0
	addi r4, r31, 0x0
	li r3, 0x2
	bl __DVDPushWaitingQueue
	lwz r0, -0x7B00(r13)
	addi r31, r3, 0x0
	cmplwi r0, 0x0
	bne lbl_800195B0
	lwz r0, -0x7AF4(r13)
	cmpwi r0, 0x0
	bne lbl_800195B0
	bl stateReady
lbl_800195B0:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x2c(r1)
	lwz r31, 0x24(r1)
	lwz r30, 0x20(r1)
	addi r1, r1, 0x28
	mtlr r0
	blr
}

/* DVDBSChangeDiskAsync @0x800195D4 | size: 0xBC */
asm void DVDBSChangeDiskAsync(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x7
	stwu r1, -0x20(r1)
	stw r31, 0x1c(r1)
	addi r31, r3, 0x0
	stw r30, 0x18(r1)
	stw r0, 0x8(r3)
	stw r4, 0x28(r3)
	lwz r0, -0x7F44(r13)
	cmpwi r0, 0x0
	beq lbl_80019630
	lwz r3, 0x8(r31)
	cmplwi r3, 0x1
	beq lbl_80019624
	subi r0, r3, 0x4
	cmplwi r0, 0x1
	ble lbl_80019624
	cmplwi r3, 0xe
	bne lbl_80019630
lbl_80019624:
	lwz r3, 0x18(r31)
	lwz r4, 0x14(r31)
	bl DCInvalidateRange
lbl_80019630:
	bl OSDisableInterrupts
	li r0, 0x2
	stw r0, 0xc(r31)
	addi r30, r3, 0x0
	addi r4, r31, 0x0
	li r3, 0x1
	bl __DVDPushWaitingQueue
	lwz r0, -0x7B00(r13)
	addi r31, r3, 0x0
	cmplwi r0, 0x0
	bne lbl_8001966C
	lwz r0, -0x7AF4(r13)
	cmpwi r0, 0x0
	bne lbl_8001966C
	bl stateReady
lbl_8001966C:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	addi r1, r1, 0x20
	mtlr r0
	blr
}

/* DVDInquiryAsync @0x80019690 | size: 0xD0 */
asm void DVDInquiryAsync(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0xe
	stwu r1, -0x28(r1)
	stw r31, 0x24(r1)
	addi r31, r3, 0x0
	stw r30, 0x20(r1)
	stw r0, 0x8(r3)
	li r3, 0x20
	li r0, 0x0
	stw r4, 0x18(r31)
	stw r3, 0x14(r31)
	stw r0, 0x20(r31)
	stw r5, 0x28(r31)
	lwz r0, -0x7F44(r13)
	cmpwi r0, 0x0
	beq lbl_80019700
	lwz r3, 0x8(r31)
	cmplwi r3, 0x1
	beq lbl_800196F4
	subi r0, r3, 0x4
	cmplwi r0, 0x1
	ble lbl_800196F4
	cmplwi r3, 0xe
	bne lbl_80019700
lbl_800196F4:
	lwz r3, 0x18(r31)
	lwz r4, 0x14(r31)
	bl DCInvalidateRange
lbl_80019700:
	bl OSDisableInterrupts
	li r0, 0x2
	stw r0, 0xc(r31)
	addi r30, r3, 0x0
	addi r4, r31, 0x0
	li r3, 0x2
	bl __DVDPushWaitingQueue
	lwz r0, -0x7B00(r13)
	addi r31, r3, 0x0
	cmplwi r0, 0x0
	bne lbl_8001973C
	lwz r0, -0x7AF4(r13)
	cmpwi r0, 0x0
	bne lbl_8001973C
	bl stateReady
lbl_8001973C:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x2c(r1)
	lwz r31, 0x24(r1)
	lwz r30, 0x20(r1)
	addi r1, r1, 0x28
	mtlr r0
	blr
}

/* DVDReset @0x80019760 | size: 0x44 */
asm void DVDReset(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x8(r1)
	bl DVDLowReset
	lis r3, 0xcc00
	li r0, 0x2a
	stw r0, 0x6000(r3)
	addi r4, r3, 0x6000
	li r0, 0x0
	lwz r3, 0x6004(r3)
	stw r3, 0x4(r4)
	stw r0, -0x7AC8(r13)
	stw r0, -0x7AD8(r13)
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}

/* fn_800197A4 @0x800197A4 | size: 0x4C */
asm void fn_800197A4(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	mr r31, r3
	bl OSDisableInterrupts
	lwz r0, 0xc(r31)
	cmpwi r0, 0x3
	bne lbl_800197D0
	li r31, 0x1
	b lbl_800197D4
lbl_800197D0:
	mr r31, r0
lbl_800197D4:
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* DVDGetDriveStatus @0x800197F0 | size: 0xAC */
asm void DVDGetDriveStatus(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	bl OSDisableInterrupts
	lwz r0, -0x7AE8(r13)
	addi r30, r3, 0x0
	cmpwi r0, 0x0
	beq lbl_80019820
	li r31, -0x1
	b lbl_80019878
lbl_80019820:
	lwz r0, -0x7AF0(r13)
	cmpwi r0, 0x0
	beq lbl_80019834
	li r31, 0x8
	b lbl_80019878
lbl_80019834:
	lwz r31, -0x7B00(r13)
	cmplwi r31, 0x0
	bne lbl_80019848
	li r31, 0x0
	b lbl_80019878
lbl_80019848:
	lis r3, DummyCommandBlock@ha
	addi r0, r3, DummyCommandBlock@l
	cmplw r31, r0
	bne lbl_80019860
	li r31, 0x0
	b lbl_80019878
lbl_80019860:
	bl OSDisableInterrupts
	lwz r31, 0xc(r31)
	cmpwi r31, 0x3
	bne lbl_80019874
	li r31, 0x1
lbl_80019874:
	bl OSRestoreInterrupts
lbl_80019878:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* fn_8001989C @0x8001989C | size: 0x10 */
asm void fn_8001989C(void) {
nofralloc
	lwz r0, -0x7F44(r13)
	stw r3, -0x7F44(r13)
	mr r3, r0
	blr
}

/* fn_800198AC @0x800198AC | size: 0x50 */
asm void fn_800198AC(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x10(r1)
	stw r31, 0xc(r1)
	bl OSDisableInterrupts
	li r4, 0x0
	stw r4, -0x7AF4(r13)
	mr r31, r3
	lwz r0, -0x7AF0(r13)
	cmpwi r0, 0x0
	beq lbl_800198E0
	stw r4, -0x7AF0(r13)
	bl stateReady
lbl_800198E0:
	mr r3, r31
	bl OSRestoreInterrupts
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* __DVDDequeueWaitingQueue @0x800198FC | size: 0x27C */
asm void __DVDDequeueWaitingQueue(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x28(r1)
	stw r31, 0x24(r1)
	stw r30, 0x20(r1)
	addi r30, r4, 0x0
	stw r29, 0x1c(r1)
	addi r29, r3, 0x0
	bl OSDisableInterrupts
	lwz r4, 0xc(r29)
	addi r31, r3, 0x0
	addi r0, r4, 0x1
	cmplwi r0, 0xc
	bgt lbl_80019B50
	lis r3, jumptable_801240A8@ha
	addi r3, r3, jumptable_801240A8@l
	slwi r0, r0, 2
	lwzx r0, r3, r0
	mtctr r0
	bctr
	cmplwi r30, 0x0
	beq lbl_80019B50
	addi r12, r30, 0x0
	mtlr r12
	addi r4, r29, 0x0
	li r3, 0x0
	blrl
	b lbl_80019B50
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80019988
	mr r3, r31
	bl OSRestoreInterrupts
	li r3, 0x0
	b lbl_80019B5C
lbl_80019988:
	li r0, 0x1
	stw r30, -0x7ADC(r13)
	stw r0, -0x7AE0(r13)
	lwz r0, 0x8(r29)
	cmplwi r0, 0x4
	beq lbl_800199A8
	cmplwi r0, 0x1
	bne lbl_80019B50
lbl_800199A8:
	bl fn_80016D50
	b lbl_80019B50
	mr r3, r29
	bl fn_80019FFC
	li r0, 0xa
	stw r0, 0xc(r29)
	lwz r12, 0x28(r29)
	cmplwi r12, 0x0
	beq lbl_800199DC
	mtlr r12
	addi r4, r29, 0x0
	li r3, -0x3
	blrl
lbl_800199DC:
	cmplwi r30, 0x0
	beq lbl_80019B50
	addi r12, r30, 0x0
	mtlr r12
	addi r4, r29, 0x0
	li r3, 0x0
	blrl
	b lbl_80019B50
	lwz r0, 0x8(r29)
	cmpwi r0, 0xd
	beq lbl_80019A2C
	bge lbl_80019A20
	cmpwi r0, 0x6
	bge lbl_80019A4C
	cmpwi r0, 0x4
	bge lbl_80019A2C
	b lbl_80019A4C
lbl_80019A20:
	cmpwi r0, 0xf
	beq lbl_80019A2C
	b lbl_80019A4C
lbl_80019A2C:
	cmplwi r30, 0x0
	beq lbl_80019B50
	addi r12, r30, 0x0
	mtlr r12
	addi r4, r29, 0x0
	li r3, 0x0
	blrl
	b lbl_80019B50
lbl_80019A4C:
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80019A68
	mr r3, r31
	bl OSRestoreInterrupts
	li r3, 0x0
	b lbl_80019B5C
lbl_80019A68:
	li r0, 0x1
	stw r30, -0x7ADC(r13)
	stw r0, -0x7AE0(r13)
	b lbl_80019B50
	bl fn_80016D64
	lis r4, cbForStateMotorStopped@ha
	addi r0, r4, cbForStateMotorStopped@l
	cmplw r3, r0
	beq lbl_80019A9C
	mr r3, r31
	bl OSRestoreInterrupts
	li r3, 0x0
	b lbl_80019B5C
lbl_80019A9C:
	lwz r0, 0xc(r29)
	cmpwi r0, 0x4
	bne lbl_80019AB0
	li r0, 0x3
	stw r0, -0x7AD8(r13)
lbl_80019AB0:
	lwz r0, 0xc(r29)
	cmpwi r0, 0x5
	bne lbl_80019AC4
	li r0, 0x4
	stw r0, -0x7AD8(r13)
lbl_80019AC4:
	lwz r0, 0xc(r29)
	cmpwi r0, 0x6
	bne lbl_80019AD8
	li r0, 0x1
	stw r0, -0x7AD8(r13)
lbl_80019AD8:
	lwz r0, 0xc(r29)
	cmpwi r0, 0xb
	bne lbl_80019AEC
	li r0, 0x2
	stw r0, -0x7AD8(r13)
lbl_80019AEC:
	lwz r0, 0xc(r29)
	cmpwi r0, 0x7
	bne lbl_80019B00
	li r0, 0x7
	stw r0, -0x7AD8(r13)
lbl_80019B00:
	lis r3, DummyCommandBlock@ha
	addi r0, r3, DummyCommandBlock@l
	stw r0, -0x7B00(r13)
	li r0, 0xa
	stw r0, 0xc(r29)
	lwz r12, 0x28(r29)
	cmplwi r12, 0x0
	beq lbl_80019B30
	mtlr r12
	addi r4, r29, 0x0
	li r3, -0x3
	blrl
lbl_80019B30:
	cmplwi r30, 0x0
	beq lbl_80019B4C
	addi r12, r30, 0x0
	mtlr r12
	addi r4, r29, 0x0
	li r3, 0x0
	blrl
lbl_80019B4C:
	bl stateReady
lbl_80019B50:
	mr r3, r31
	bl OSRestoreInterrupts
	li r3, 0x1
lbl_80019B5C:
	lwz r0, 0x2c(r1)
	lwz r31, 0x24(r1)
	lwz r30, 0x20(r1)
	lwz r29, 0x1c(r1)
	addi r1, r1, 0x28
	mtlr r0
	blr
}

/* DVDCancel @0x80019B78 | size: 0xAC */
asm void DVDCancel(void) {
nofralloc
	mflr r0
	lis r4, cbForCancelSync@ha
	stw r0, 0x4(r1)
	addi r4, r4, cbForCancelSync@l
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	addi r30, r3, 0x0
	bl __DVDDequeueWaitingQueue
	cmpwi r3, 0x0
	bne lbl_80019BAC
	li r3, -0x1
	b lbl_80019C0C
lbl_80019BAC:
	bl OSDisableInterrupts
	mr r31, r3
lbl_80019BB4:
	lwz r3, 0xc(r30)
	addi r0, r3, 0x1
	cmplwi r0, 0x1
	ble lbl_80019C00
	cmpwi r3, 0xa
	beq lbl_80019C00
	cmpwi r3, 0x3
	bne lbl_80019BF4
	lwz r3, 0x8(r30)
	subi r0, r3, 0x4
	cmplwi r0, 0x1
	ble lbl_80019C00
	cmplwi r3, 0xd
	beq lbl_80019C00
	cmplwi r3, 0xf
	beq lbl_80019C00
lbl_80019BF4:
	addi r3, r13, -0x7B08
	bl OSSleepThread
	b lbl_80019BB4
lbl_80019C00:
	mr r3, r31
	bl OSRestoreInterrupts
	li r3, 0x0
lbl_80019C0C:
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}

/* cbForCancelSync @0x80019C24 | size: 0x24 */
asm void cbForCancelSync(void) {
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

/* fn_80019C48 @0x80019C48 | size: 0x8 */
asm void fn_80019C48(void) {
nofralloc
	lis r3, 0x8000
	blr
}

/* fn_80019C50 @0x80019C50 | size: 0xF8 */
asm void fn_80019C50(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x10(r1)
	stw r31, 0xc(r1)
	bl OSDisableInterrupts
	lwz r0, -0x7AE8(r13)
	cmpwi r0, 0x0
	beq lbl_80019C78
	li r4, -0x1
	b lbl_80019CBC
lbl_80019C78:
	lwz r0, -0x7AF0(r13)
	cmpwi r0, 0x0
	beq lbl_80019C8C
	li r4, 0x8
	b lbl_80019CBC
lbl_80019C8C:
	lwz r5, -0x7B00(r13)
	cmplwi r5, 0x0
	bne lbl_80019CA0
	li r4, 0x0
	b lbl_80019CBC
lbl_80019CA0:
	lis r4, DummyCommandBlock@ha
	addi r0, r4, DummyCommandBlock@l
	cmplw r5, r0
	bne lbl_80019CB8
	li r4, 0x0
	b lbl_80019CBC
lbl_80019CB8:
	lwz r4, 0xc(r5)
lbl_80019CBC:
	addi r0, r4, 0x1
	cmplwi r0, 0xc
	bgt lbl_80019D2C
	lis r4, jumptable_801240DC@ha
	addi r4, r4, jumptable_801240DC@l
	slwi r0, r0, 2
	lwzx r0, r4, r0
	mtctr r0
	bctr
	li r31, 0x1
	b lbl_80019D2C
	li r31, 0x0
	b lbl_80019D2C
	lis r4, 0xcc00
	addi r4, r4, 0x6000
	lwz r4, 0x4(r4)
	extrwi. r0, r4, 1, 29
	bne lbl_80019D0C
	clrlwi. r0, r4, 31
	beq lbl_80019D14
lbl_80019D0C:
	li r31, 0x0
	b lbl_80019D2C
lbl_80019D14:
	lwz r0, -0x7AD8(r13)
	cmplwi r0, 0x0
	beq lbl_80019D28
	li r31, 0x0
	b lbl_80019D2C
lbl_80019D28:
	li r31, 0x1
lbl_80019D2C:
	bl OSRestoreInterrupts
	mr r3, r31
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	addi r1, r1, 0x10
	mtlr r0
	blr
}

/* DVDCancelAllAsync @0x80019D48 | size: 0x11C */
asm void DVDCancelAllAsync(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x20(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	mr r30, r3
	stw r29, 0x14(r1)
	bl OSDisableInterrupts
	mr r29, r3
	bl __DVDClearWaitingQueue
	lwz r0, -0x7AE0(r13)
	cmplwi r0, 0x0
	beq lbl_80019D84
	stw r30, -0x7ADC(r13)
	b lbl_80019E40
lbl_80019D84:
	lwz r3, -0x7B00(r13)
	cmplwi r3, 0x0
	beq lbl_80019D98
	li r0, 0x0
	stw r0, 0x28(r3)
lbl_80019D98:
	bl OSDisableInterrupts
	mr r31, r3
	bl OSDisableInterrupts
	lwz r0, -0x7B00(r13)
	li r4, 0x1
	stw r4, -0x7AF4(r13)
	cmplwi r0, 0x0
	bne lbl_80019DBC
	stw r4, -0x7AF0(r13)
lbl_80019DBC:
	bl OSRestoreInterrupts
	b lbl_80019DCC
lbl_80019DC4:
	li r4, 0x0
	bl __DVDDequeueWaitingQueue
lbl_80019DCC:
	bl __DVDPopWaitingQueue
	cmplwi r3, 0x0
	bne lbl_80019DC4
	lwz r3, -0x7B00(r13)
	cmplwi r3, 0x0
	beq lbl_80019DF0
	mr r4, r30
	bl __DVDDequeueWaitingQueue
	b lbl_80019E0C
lbl_80019DF0:
	cmplwi r30, 0x0
	beq lbl_80019E0C
	addi r12, r30, 0x0
	mtlr r12
	li r3, 0x0
	li r4, 0x0
	blrl
lbl_80019E0C:
	bl OSDisableInterrupts
	li r4, 0x0
	stw r4, -0x7AF4(r13)
	mr r30, r3
	lwz r0, -0x7AF0(r13)
	cmpwi r0, 0x0
	beq lbl_80019E30
	stw r4, -0x7AF0(r13)
	bl stateReady
lbl_80019E30:
	mr r3, r30
	bl OSRestoreInterrupts
	mr r3, r31
	bl OSRestoreInterrupts
lbl_80019E40:
	mr r3, r29
	bl OSRestoreInterrupts
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	addi r1, r1, 0x20
	mtlr r0
	blr
}
