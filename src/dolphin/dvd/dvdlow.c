/* dolphin/dvd/dvdlow.c — matched from retail .text 0x80015F80..0x80016DC0.
 * Functions still in exact-asm form carry a "nofralloc transcription" comment;
 * their s64 arithmetic / register choreography resisted natural C so far.
 */

typedef int BOOL;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define NULL ((void*)0)

typedef void OSContext;

typedef struct OSAlarm {
    void (*handler)(struct OSAlarm* alarm, OSContext* context);
    u32 tag;
    s64 fire;
    struct OSAlarm* prev;
    struct OSAlarm* next;
    s64 period;
    s64 start;
} OSAlarm;

typedef void (*OSAlarmHandler)(struct OSAlarm* alarm, OSContext* context);
typedef void (*DVDCallback)(u32 result);

typedef struct DVDBlock {
    u32 state;
    u32 addr;
    u32 len;
    u32 offset;
    u32 cb;
} DVDBlock;

extern void OSInitAlarm(void);
extern void OSCreateAlarm(OSAlarm* alarm);
extern void OSSetAlarm(OSAlarm* alarm, s64 tick, OSAlarmHandler handler);
extern void OSCancelAlarm(OSAlarm* alarm);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern BOOL OSDisableInterrupts(void);
extern void OSRestoreInterrupts(BOOL level);
extern u32 __OSMaskInterrupts(u32 mask);
extern s64 __OSGetSystemTime(void);

extern DVDBlock CommandList[];
extern OSAlarm AlarmForTimeout;
extern u32 NextCommandNumber;
extern u32 StopAtNextInt;
extern DVDCallback Callback;
extern u32 WaitingCoverClose;
extern u32 WorkAroundType;
extern u32 WorkAroundSeekLocation;
extern u32 ResetOccurred;
extern s64 LastResetEnd;
extern u32 lbl_801A6468;
extern u32 lbl_801A685C;
extern u32 lbl_801A6864;
extern u32 lbl_801A6878;
extern u32 lbl_801A6888;
extern u32 lbl_801A688C;
extern u32 lbl_801A6890;
extern u32 lbl_801A6894;
extern u32 lbl_801A6898;

static void __DVDLowSetWAType(u32 type, u32 location);
extern void Read(u32 addr, u32 len, u32 offset, DVDCallback callback);
extern void SeekTwiceBeforeRead(void);
extern void DVDLowSeek(void);
extern u32 fn_80019C48(void);

#pragma force_active on

#define _DI ((volatile u32*)0xCC006000)
#define _BUS_CLOCK (*(volatile u32*)0x800000F8)


/* __DVDInitWA @0x80015F80 | size: 0x40 */
void __DVDInitWA(void)
{
    NextCommandNumber = 0;
    CommandList[0].state = -1;
    __DVDLowSetWAType(0, 0);
    OSInitAlarm();
}

/* __DVDInterruptHandler @0x80015FC0 | size: 0x2E0 — nofralloc transcription */
asm void __DVDInterruptHandler(void) {
nofralloc
	mflr r0
	lis r3, CommandList@ha
	stw r0, 0x4(r1)
	stwu r1, -0x2f0(r1)
	stmw r27, 0x2dc(r1)
	addi r28, r4, 0x0
	addi r30, r3, CommandList@l
	li r29, 0x0
	lwz r0, -0x7B28(r13)
	cmpwi r0, 0x0
	beq lbl_80016028
	bl __OSGetSystemTime
	stw r4, -0x7B34(r13)
	li r0, 0x0
	stw r3, -0x7B38(r13)
	stw r0, -32600(r13)
	lwz r0, 0xc4(r30)
	stw r0, 0xb8(r30)
	lwz r0, 0xc8(r30)
	stw r0, 0xbc(r30)
	lwz r0, 0xcc(r30)
	stw r0, 0xc0(r30)
	lwz r0, -31592(r13)
	cmpwi r0, 0x1
	bne lbl_80016028
	ori r29, r29, 0x8
lbl_80016028:
	li r0, 0x0
	stw r0, -0x7B28(r13)
	lis r3, 0xcc00
	stw r0, -31592(r13)
	lwz r0, 0x6000(r3)
	andi. r31, r0, 0x2a
	andi. r3, r0, 0x54
	slwi r0, r31, 1
	and r27, r3, r0
	rlwinm. r0, r27, 0, 25, 25
	beq lbl_80016058
	ori r29, r29, 0x8
lbl_80016058:
	rlwinm. r0, r27, 0, 27, 27
	beq lbl_80016064
	ori r29, r29, 0x1
lbl_80016064:
	rlwinm. r0, r27, 0, 29, 29
	beq lbl_80016070
	ori r29, r29, 0x2
lbl_80016070:
	cmplwi r29, 0x0
	beq lbl_80016088
	li r0, 0x0
	stw r0, -31568(r13)
	addi r3, r30, 0x68
	bl OSCancelAlarm
lbl_80016088:
	or r0, r27, r31
	lis r31, 0xcc00
	stw r0, 0x6000(r31)
	lwz r0, -31568(r13)
	cmplwi r0, 0x0
	beq lbl_8001613c
	bl __OSGetSystemTime
	lis r5, 0x8000
	lwz r7, -31576(r13)
	lwz r6, 0xf8(r5)
	lis r5, 0x1062
	addi r5, r5, 0x4dd3
	lwz r8, -31572(r13)
	srwi r6, r6, 2
	mulhwu r5, r5, r6
	srwi r5, r5, 6
	mulli r5, r5, 0xc8
	subfc r6, r8, r4
	subfe r3, r7, r3
	li r0, 0x0
	xoris r4, r3, 0x8000
	xoris r3, r0, 0x8000
	subfc r0, r5, r6
	subfe r3, r3, r4
	subfe r3, r4, r4
	neg. r3, r3
	beq lbl_8001613c
	addi r27, r31, 0x6000
	lwzu r0, 0x4(r27)
	rlwinm r3, r0, 0, 29, 29
	rlwinm r0, r0, 1, 29, 29
	and r0, r3, r0
	rlwinm. r0, r0, 0, 29, 29
	beq lbl_80016130
	lwz r12, -31580(r13)
	cmplwi r12, 0x0
	beq lbl_80016128
	mtlr r12
	li r3, 0x4
	blrl
lbl_80016128:
	li r0, 0x0
	stw r0, -31580(r13)
lbl_80016130:
	lwz r0, 0x0(r27)
	stw r0, 0x0(r27)
	b lbl_80016190
lbl_8001613c:
	lwz r0, -31564(r13)
	cmpwi r0, 0x0
	beq lbl_80016184
	lis r3, 0xcc00
	addi r5, r3, 0x6000
	lwzu r0, 0x4(r5)
	rlwinm r4, r0, 0, 30, 30
	rlwinm r3, r0, 0, 29, 29
	rlwinm r0, r0, 1, 29, 29
	and r3, r3, r0
	rlwinm. r0, r3, 0, 29, 29
	beq lbl_80016170
	ori r29, r29, 0x4
lbl_80016170:
	or r0, r3, r4
	stw r0, 0x0(r5)
	li r0, 0x0
	stw r0, -31564(r13)
	b lbl_80016190
lbl_80016184:
	lis r3, 0xcc00
	li r0, 0x0
	stw r0, 0x6004(r3)
lbl_80016190:
	rlwinm. r0, r29, 0, 28, 28
	beq lbl_800161a8
	lwz r0, -31560(r13)
	cmpwi r0, 0x0
	bne lbl_800161a8
	rlwinm r29, r29, 0, 29, 27
lbl_800161a8:
	clrlwi. r0, r29, 31
	beq lbl_8001622c
	lwz r0, -31524(r13)
	mulli r0, r0, 0x14
	lwzx r3, r30, r0
	cmpwi r3, 0x1
	bne lbl_800161f0
	lwz r3, -31524(r13)
	add r6, r30, r0
	addi r0, r3, 0x1
	stw r0, -31524(r13)
	lwz r3, 0x4(r6)
	lwz r4, 0x8(r6)
	lwz r5, 0xc(r6)
	lwz r6, 0x10(r6)
	bl Read
	li r0, 0x1
	b lbl_80016220
lbl_800161f0:
	cmpwi r3, 0x2
	bne lbl_8001621c
	lwz r3, -31524(r13)
	add r4, r30, r0
	addi r0, r3, 0x1
	stw r0, -31524(r13)
	lwz r3, 0xc(r4)
	lwz r4, 0x10(r4)
	bl DVDLowSeek
	li r0, 0x1
	b lbl_80016220
lbl_8001621c:
	li r0, 0x0
lbl_80016220:
	cmpwi r0, 0x0
	beq lbl_8001623c
	b lbl_8001628c
lbl_8001622c:
	li r0, -0x1
	stw r0, 0x0(r30)
	li r0, 0x0
	stw r0, -31524(r13)
lbl_8001623c:
	addi r3, r1, 0x10
	bl OSClearContext
	addi r3, r1, 0x10
	bl OSSetCurrentContext
	cmplwi r29, 0x0
	beq lbl_8001627c
	lwz r12, -31584(r13)
	li r0, 0x0
	cmplwi r12, 0x0
	stw r0, -31584(r13)
	beq lbl_80016274
	mtlr r12
	addi r3, r29, 0x0
	blrl
lbl_80016274:
	li r0, 0x0
	stw r0, -31560(r13)
lbl_8001627c:
	addi r3, r1, 0x10
	bl OSClearContext
	mr r3, r28
	bl OSSetCurrentContext
lbl_8001628c:
	lmw r27, 0x2dc(r1)
	lwz r0, 0x2f4(r1)
	addi r1, r1, 0x2f0
	mtlr r0
	blr
}

/* ProcessNextCommand @0x800162A0 | size: 0x84 — nofralloc transcription */
asm void ProcessNextCommand(void) {
nofralloc
	mflr r0
	lis r3, CommandList@ha
	stw r0, 0x4(r1)
	addi r4, r3, CommandList@l
	stwu r1, -0x8(r1)
	lwz r0, -31524(r13)
	mulli r0, r0, 0x14
	lwzx r3, r4, r0
	cmpwi r3, 0x1
	bne lbl_800162F0
	lwz r3, -31524(r13)
	add r6, r4, r0
	addi r0, r3, 0x1
	stw r0, -31524(r13)
	lwz r3, 0x4(r6)
	lwz r4, 0x8(r6)
	lwz r5, 0xc(r6)
	lwz r6, 0x10(r6)
	bl Read
	b lbl_80016314
lbl_800162F0:
	cmpwi r3, 0x2
	bne lbl_80016314
	lwz r3, -31524(r13)
	add r4, r4, r0
	addi r0, r3, 0x1
	stw r0, -31524(r13)
	lwz r3, 0xc(r4)
	lwz r4, 0x10(r4)
	bl DVDLowSeek
lbl_80016314:
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}
/* AlarmHandlerForTimeout @0x80016324 | size: 0x70 — nofralloc transcription */
asm void AlarmHandlerForTimeout(register OSAlarm* alarm, register OSContext* context) {
nofralloc
	mflr r0
	li r3, 0x400
	stw r0, 0x4(r1)
	stwu r1, -0x2e0(r1)
	stw r31, 0x2dc(r1)
	addi r31, r4, 0x0
	bl __OSMaskInterrupts
	addi r3, r1, 0x10
	bl OSClearContext
	addi r3, r1, 0x10
	bl OSSetCurrentContext
	lwz r12, -31584(r13)
	li r0, 0x0
	cmplwi r12, 0x0
	stw r0, -31584(r13)
	beq lbl_80016370
	mtlr r12
	li r3, 0x10
	blrl
lbl_80016370:
	addi r3, r1, 0x10
	bl OSClearContext
	mr r3, r31
	bl OSSetCurrentContext
	lwz r0, 0x2e4(r1)
	lwz r31, 0x2dc(r1)
	addi r1, r1, 0x2e0
	mtlr r0
	blr
}

/* Read @0x80016394 | size: 0x110 — nofralloc transcription */
asm void Read(register u32 addr, register u32 len, register u32 offset,
                     register DVDCallback callback) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x0
	stwu r1, -0x28(r1)
	stw r31, 0x24(r1)
	stw r30, 0x20(r1)
	addi r30, r5, 0x0
	stw r29, 0x1c(r1)
	addi r29, r4, 0x0
	stw r28, 0x18(r1)
	addi r28, r3, 0x0
	stw r0, -31592(r13)
	li r0, 0x1
	stw r6, -31584(r13)
	lis r6, CommandList@ha
	addi r31, r6, CommandList@l
	stw r0, -31528(r13)
	bl __OSGetSystemTime
	stw r4, -31532(r13)
	lis r4, 0xcc00
	lis r0, 0xa0
	stw r3, -31536(r13)
	addi r4, r4, 0x6000
	lis r3, 0xa800
	stw r3, 0x8(r4)
	srwi r3, r30, 2
	cmplw r29, r0
	stw r3, 0xc(r4)
	li r0, 0x3
	stw r29, 0x10(r4)
	stw r28, 0x14(r4)
	stw r29, 0x18(r4)
	stw r29, -0x7B64(r13)
	stw r0, 0x1c(r4)
	ble lbl_80016454
	lis r3, 0x8000
	lwz r0, 0xf8(r3)
	addi r3, r31, 0x68
	srwi r0, r0, 2
	mulli r30, r0, 0x14
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r6, r30, 0x0
	addi r3, r31, 0x68
	li r5, 0x0
	bl OSSetAlarm
	b lbl_80016484
lbl_80016454:
	lis r3, 0x8000
	lwz r0, 0xf8(r3)
	addi r3, r31, 0x68
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r6, r30, 0x0
	addi r3, r31, 0x68
	li r5, 0x0
	bl OSSetAlarm
lbl_80016484:
	lwz r0, 0x2c(r1)
	lwz r31, 0x24(r1)
	lwz r30, 0x20(r1)
	lwz r29, 0x1c(r1)
	lwz r28, 0x18(r1)
	addi r1, r1, 0x28
	mtlr r0
	blr
}

/* SeekTwiceBeforeRead @0x800164A4 | size: 0x80 — nofralloc transcription */
asm void SeekTwiceBeforeRead(void) {
nofralloc
	mflr r0
	lis r7, CommandList@ha
	stw r0, 0x4(r1)
	clrrwi. r8, r5, 15
	addi r9, r7, CommandList@l
	stwu r1, -0x8(r1)
	bne lbl_800164C8
	li r10, 0x0
	b lbl_800164D0
lbl_800164C8:
	lwz r0, -31552(r13)
	add r10, r8, r0
lbl_800164D0:
	li r0, 0x2
	stw r0, 0x0(r9)
	li r8, 0x1
	li r7, -0x1
	stw r10, 0xc(r9)
	li r0, 0x0
	stw r6, 0x10(r9)
	stw r8, 0x14(r9)
	stw r3, 0x18(r9)
	mr r3, r10
	stw r4, 0x1c(r9)
	mr r4, r6
	stw r5, 0x20(r9)
	stw r6, 0x24(r9)
	stw r7, 0x28(r9)
	stw r0, -31524(r13)
	bl DVDLowSeek
	lwz r0, 0xc(r1)
	addi r1, r1, 0x8
	mtlr r0
	blr
}
/* DVDLowRead @0x80016524 | size: 0x298 — nofralloc transcription */
asm void DVDLowRead(register u32 addr, register u32 len, register u32 offset,
                     register DVDCallback callback) {
nofralloc
	mflr r0
	lis r7, 0xcc00
	stw r0, 0x4(r1)
	stwu r1, -0x40(r1)
	stmw r22, 0x18(r1)
	addi r25, r4, 0x0
	addi r4, r7, 0x6000
	lis r7, CommandList@ha
	addi r31, r7, CommandList@l
	addi r24, r3, 0x0
	addi r26, r5, 0x0
	addi r30, r31, 0xcc
	mr r27, r6
	stw r25, 0x18(r4)
	stw r24, 0xc4(r31)
	stw r25, 0xc8(r31)
	stw r26, 0xcc(r31)
	lwz r0, -31556(r13)
	cmplwi r0, 0x0
	bne lbl_8001659c
	li r0, -0x1
	stw r0, 0x0(r31)
	li r0, 0x0
	addi r3, r24, 0x0
	stw r0, -31524(r13)
	addi r4, r25, 0x0
	addi r5, r26, 0x0
	addi r6, r27, 0x0
	bl Read
	b lbl_800167a4
lbl_8001659c:
	lwz r0, -31556(r13)
	cmplwi r0, 0x1
	bne lbl_800167a4
	lwz r0, -32600(r13)
	cmpwi r0, 0x0
	beq lbl_800165cc
	addi r3, r24, 0x0
	addi r4, r25, 0x0
	addi r5, r26, 0x0
	addi r6, r27, 0x0
	bl SeekTwiceBeforeRead
	b lbl_800167a4
lbl_800165cc:
	addi r29, r31, 0xbc
	lwz r0, 0x0(r30)
	addi r28, r31, 0xc0
	lwz r3, 0xbc(r31)
	lwz r4, 0xc0(r31)
	srwi r23, r0, 15
	subi r0, r3, 0x1
	add r0, r4, r0
	srwi r22, r0, 15
	bl fn_80019C48
	lbz r0, 0x8(r3)
	cmplwi r0, 0x0
	beq lbl_80016608
	li r0, 0x1
	b lbl_8001660c
lbl_80016608:
	li r0, 0x0
lbl_8001660c:
	cmpwi r0, 0x0
	beq lbl_8001661c
	li r3, 0x5
	b lbl_80016620
lbl_8001661c:
	li r3, 0xf
lbl_80016620:
	subi r0, r22, 0x2
	cmplw r23, r0
	bgt lbl_8001663c
	addi r0, r3, 0x3
	add r0, r22, r0
	cmplw r23, r0
	bge lbl_80016644
lbl_8001663c:
	li r0, 0x1
	b lbl_80016648
lbl_80016644:
	li r0, 0x0
lbl_80016648:
	cmpwi r0, 0x0
	bne lbl_80016678
	li r0, -0x1
	stw r0, 0x0(r31)
	li r0, 0x0
	addi r3, r24, 0x0
	stw r0, -31524(r13)
	addi r4, r25, 0x0
	addi r5, r26, 0x0
	addi r6, r27, 0x0
	bl Read
	b lbl_800167a4
lbl_80016678:
	lwz r3, 0x0(r29)
	lwz r4, 0x0(r28)
	subi r3, r3, 0x1
	lwz r0, 0x0(r30)
	add r3, r4, r3
	srwi r3, r3, 15
	srwi r4, r0, 15
	cmplw r3, r4
	beq lbl_800166a8
	addi r0, r3, 0x1
	cmplw r0, r4
	bne lbl_80016790
lbl_800166a8:
	bl __OSGetSystemTime
	lis r5, 0x8000
	lwz r8, -31544(r13)
	lwz r0, 0xf8(r5)
	lis r5, 0x1062
	lwz r9, -31540(r13)
	li r6, 0x0
	srwi r7, r0, 2
	addi r0, r5, 0x4dd3
	mulhwu r0, r0, r7
	srwi r0, r0, 6
	subfc r9, r9, r4
	subfe r8, r8, r3
	mulli r5, r0, 0x5
	xoris r4, r6, 0x8000
	xoris r3, r8, 0x8000
	subfc r0, r9, r5
	subfe r3, r3, r4
	subfe r3, r4, r4
	neg. r3, r3
	beq lbl_80016720
	li r0, -0x1
	stw r0, 0x0(r31)
	addi r3, r24, 0x0
	addi r4, r25, 0x0
	stw r6, -31524(r13)
	addi r5, r26, 0x0
	addi r6, r27, 0x0
	bl Read
	b lbl_800167a4
lbl_80016720:
	li r0, 0x1
	stw r0, 0x0(r31)
	lis r3, 0x431c
	subi r0, r3, 0x217d
	stw r24, 0x4(r31)
	mulhwu r0, r0, r7
	stw r25, 0x8(r31)
	stw r26, 0xc(r31)
	srwi r0, r0, 15
	mulli r3, r0, 0x1f4
	stw r27, 0x10(r31)
	li r0, -0x1
	stw r0, 0x14(r31)
	subfc r5, r9, r5
	subfe r4, r8, r6
	srwi r0, r3, 3
	stw r6, -31524(r13)
	addc r23, r5, r0
	adde r22, r4, r6
	addi r3, r31, 0x40
	bl OSCreateAlarm
	lis r3, ProcessNextCommand@ha
	addi r7, r3, ProcessNextCommand@l
	addi r6, r23, 0x0
	addi r5, r22, 0x0
	addi r3, r31, 0x40
	bl OSSetAlarm
	b lbl_800167a4
lbl_80016790:
	addi r3, r24, 0x0
	addi r4, r25, 0x0
	addi r5, r26, 0x0
	addi r6, r27, 0x0
	bl SeekTwiceBeforeRead
lbl_800167a4:
	lmw r22, 0x18(r1)
	li r3, 0x1
	lwz r0, 0x44(r1)
	addi r1, r1, 0x40
	mtlr r0
	blr
}

/* DVDLowSeek @0x800167BC | size: 0x94 — nofralloc transcription */
asm void DVDLowSeek(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x0
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	stw r4, -31584(r13)
	lis r4, 0xcc00
	addi r4, r4, 0x6000
	stw r0, -31592(r13)
	lis r0, 0xab00
	stw r0, 0x8(r4)
	srwi r0, r3, 2
	lis r3, AlarmForTimeout@ha
	stw r0, 0xc(r4)
	li r0, 0x1
	addi r31, r3, AlarmForTimeout@l
	stw r0, 0x1c(r4)
	lis r4, 0x8000
	addi r3, r31, 0x0
	lwz r0, 0xf8(r4)
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x1c(r1)
	li r3, 0x1
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
/* DVDLowWaitCoverClose @0x80016850 | size: 0x2C — nofralloc transcription */
asm void DVDLowWaitCoverClose(void) {
nofralloc
	li r0, 0x1
	stw r3, -31584(r13)
	lis r3, 0xcc00
	stw r0, -31564(r13)
	li r0, 0x0
	addi r4, r3, 0x6000
	stw r0, -31592(r13)
	li r0, 0x2
	li r3, 0x1
	stw r0, 0x4(r4)
	blr
}
/* DVDLowReadDiskID @0x8001687C | size: 0xA4 — nofralloc transcription */
asm void DVDLowReadDiskID(void) {
nofralloc
	mflr r0
	li r8, 0x0
	stw r0, 0x4(r1)
	lis r5, 0xa800
	addi r0, r5, 0x40
	stwu r1, -0x18(r1)
	li r6, 0x20
	lis r5, 0x8000
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	stw r4, -31584(r13)
	lis r4, 0xcc00
	addi r7, r4, 0x6000
	stw r8, -31592(r13)
	stw r0, 0x6008(r4)
	lis r4, AlarmForTimeout@ha
	li r0, 0x3
	stw r8, 0xc(r7)
	addi r31, r4, AlarmForTimeout@l
	stw r6, 0x10(r7)
	stw r3, 0x14(r7)
	mr r3, r31
	stw r6, 0x18(r7)
	stw r0, 0x1c(r7)
	lwz r0, 0xf8(r5)
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x1c(r1)
	li r3, 0x1
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
/* DVDLowStopMotor @0x80016920 | size: 0x8C — nofralloc transcription */
asm void DVDLowStopMotor(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x0
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	stw r3, -31584(r13)
	lis r3, 0xcc00
	addi r4, r3, 0x6000
	stw r0, -31592(r13)
	lis r0, 0xe300
	stw r0, 0x6008(r3)
	li r0, 0x1
	lis r3, AlarmForTimeout@ha
	stw r0, 0x1c(r4)
	lis r4, 0x8000
	addi r31, r3, AlarmForTimeout@l
	lwz r0, 0xf8(r4)
	addi r3, r31, 0x0
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x1c(r1)
	li r3, 0x1
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
/* DVDLowRequestError @0x800169AC | size: 0x8C — nofralloc transcription */
asm void DVDLowRequestError(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x0
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	stw r3, -31584(r13)
	lis r3, 0xcc00
	addi r4, r3, 0x6000
	stw r0, -31592(r13)
	lis r0, 0xe000
	stw r0, 0x6008(r3)
	li r0, 0x1
	lis r3, AlarmForTimeout@ha
	stw r0, 0x1c(r4)
	lis r4, 0x8000
	addi r31, r3, AlarmForTimeout@l
	lwz r0, 0xf8(r4)
	addi r3, r31, 0x0
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x1c(r1)
	li r3, 0x1
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
/* DVDLowInquiry @0x80016A38 | size: 0x9C — nofralloc transcription */
asm void DVDLowInquiry(void) {
nofralloc
	mflr r0
	li r6, 0x20
	stw r0, 0x4(r1)
	li r0, 0x0
	lis r5, 0x8000
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	stw r4, -31584(r13)
	lis r4, 0xcc00
	addi r7, r4, 0x6000
	stw r0, -31592(r13)
	lis r0, 0x1200
	stw r0, 0x6008(r4)
	lis r4, AlarmForTimeout@ha
	li r0, 0x3
	stw r6, 0x10(r7)
	addi r31, r4, AlarmForTimeout@l
	stw r3, 0x14(r7)
	addi r3, r31, 0x0
	stw r6, 0x18(r7)
	stw r0, 0x1c(r7)
	lwz r0, 0xf8(r5)
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x1c(r1)
	li r3, 0x1
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
/* DVDLowAudioStream @0x80016AD4 | size: 0x98 — nofralloc transcription */
asm void DVDLowAudioStream(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x0
	stwu r1, -0x20(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	stw r6, -31584(r13)
	lis r6, 0xcc00
	addi r6, r6, 0x6000
	stw r0, -31592(r13)
	oris r0, r3, 0xe100
	lis r3, AlarmForTimeout@ha
	stw r0, 0x8(r6)
	srwi r0, r5, 2
	addi r31, r3, AlarmForTimeout@l
	stw r0, 0xc(r6)
	li r0, 0x1
	addi r3, r31, 0x0
	stw r4, 0x10(r6)
	lis r4, 0x8000
	stw r0, 0x1c(r6)
	lwz r0, 0xf8(r4)
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x24(r1)
	li r3, 0x1
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	addi r1, r1, 0x20
	mtlr r0
	blr
}
/* DVDLowRequestAudioStatus @0x80016B6C | size: 0x8C — nofralloc transcription */
asm void DVDLowRequestAudioStatus(void) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	li r0, 0x0
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	stw r30, 0x10(r1)
	stw r4, -31584(r13)
	lis r4, 0xcc00
	addi r4, r4, 0x6000
	stw r0, -31592(r13)
	oris r0, r3, 0xe200
	lis r3, AlarmForTimeout@ha
	stw r0, 0x8(r4)
	li r0, 0x1
	addi r31, r3, AlarmForTimeout@l
	stw r0, 0x1c(r4)
	lis r4, 0x8000
	addi r3, r31, 0x0
	lwz r0, 0xf8(r4)
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x1c(r1)
	li r3, 0x1
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
/* DVDLowAudioBufferConfig @0x80016BF8 | size: 0x9C — nofralloc transcription */
asm void DVDLowAudioBufferConfig(void) {
nofralloc
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x4(r1)
	li r0, 0x0
	stwu r1, -0x20(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	stw r5, -31584(r13)
	stw r0, -31592(r13)
	beq lbl_80016C24
	lis r0, 0x1
lbl_80016C24:
	oris r0, r0, 0xe400
	lis r3, 0xcc00
	or r0, r4, r0
	addi r3, r3, 0x6000
	stw r0, 0x8(r3)
	li r0, 0x1
	lis r4, 0x8000
	stw r0, 0x1c(r3)
	lis r3, AlarmForTimeout@ha
	addi r31, r3, AlarmForTimeout@l
	lwz r0, 0xf8(r4)
	addi r3, r31, 0x0
	srwi r0, r0, 2
	mulli r30, r0, 0xa
	bl OSCreateAlarm
	lis r3, AlarmHandlerForTimeout@ha
	addi r7, r3, AlarmHandlerForTimeout@l
	addi r3, r31, 0x0
	addi r6, r30, 0x0
	li r5, 0x0
	bl OSSetAlarm
	lwz r0, 0x24(r1)
	li r3, 0x1
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	addi r1, r1, 0x20
	mtlr r0
	blr
}
/* DVDLowReset @0x80016C94 | size: 0xBC — nofralloc transcription */
asm void DVDLowReset(void) {
nofralloc
	mflr r0
	lis r4, 0xcc00
	stw r0, 0x4(r1)
	li r0, 0x2
	stwu r1, -0x20(r1)
	stmw r26, 0x8(r1)
	addi r31, r4, 0x3000
	stw r0, 0x6004(r4)
	lwz r30, 0x3024(r4)
	rlwinm r0, r30, 0, 30, 28
	ori r0, r0, 0x1
	stwu r0, 0x24(r31)
	bl __OSGetSystemTime
	lis r5, 0x8000
	lwz r0, 0xf8(r5)
	lis r5, 0x431c
	subi r5, r5, 0x217d
	srwi r0, r0, 2
	mulhwu r0, r5, r0
	srwi r0, r0, 15
	mulli r0, r0, 0xc
	addi r26, r4, 0x0
	addi r27, r3, 0x0
	srwi r28, r0, 3
	li r29, 0x0
lbl_80016cf8:
	bl __OSGetSystemTime
	subfc r5, r26, r4
	subfe r0, r27, r3
	xoris r4, r0, 0x8000
	xoris r3, r29, 0x8000
	subfc r0, r28, r5
	subfe r3, r3, r4
	subfe r3, r4, r4
	neg. r3, r3
	bne lbl_80016cf8
	ori r0, r30, 0x5
	stw r0, 0x0(r31)
	li r0, 0x1
	stw r0, -31568(r13)
	bl __OSGetSystemTime
	stw r4, -31572(r13)
	stw r3, -31576(r13)
	lmw r26, 0x8(r1)
	lwz r0, 0x24(r1)
	addi r1, r1, 0x20
	mtlr r0
	blr
}

/* fn_80016D50 @0x80016D50 | size: 0x14 — nofralloc transcription */
asm void fn_80016D50(void) {
nofralloc
	li r0, 0x1
	stw r0, -31592(r13)
	li r3, 0x1
	stw r0, -31560(r13)
	blr
}
/* fn_80016D64 @0x80016D64 | size: 0x18 — nofralloc transcription */
asm void fn_80016D64(void) {
nofralloc
	lis r3, 0xcc00
	li r0, 0x0
	stw r0, 0x6004(r3)
	lwz r3, -31584(r13)
	stw r0, -31584(r13)
	blr
}
/* __DVDLowSetWAType @0x80016D7C | size: 0x44 — nofralloc transcription */
asm void __DVDLowSetWAType(register u32 type, register u32 location) {
nofralloc
	mflr r0
	stw r0, 0x4(r1)
	stwu r1, -0x18(r1)
	stw r31, 0x14(r1)
	addi r31, r4, 0x0
	stw r30, 0x10(r1)
	addi r30, r3, 0x0
	bl OSDisableInterrupts
	stw r30, -31556(r13)
	stw r31, -31552(r13)
	bl OSRestoreInterrupts
	lwz r0, 0x1c(r1)
	lwz r31, 0x14(r1)
	lwz r30, 0x10(r1)
	addi r1, r1, 0x18
	mtlr r0
	blr
}
