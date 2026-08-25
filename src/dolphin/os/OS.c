// dolphin/os/OS.c -- carved from coarse/text_8000A224.c (0x8000A224-0x8000AA30).
// Melee identity: extern/dolphin/src/dolphin/os/OS.c.
// Funcs: OSGetConsoleType, ClearArena (static), InquiryCallback (static),
// OSInit, OSExceptionInit (static), __OSDBIntegrator/__OSDBJump (static,
// DB integrator blob copied to 0x80000060 by OSExceptionInit).
// All nofralloc asm transcription; raw disp(r13)/lis-addi forms per house style.

typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void* memset(register void* dst, register int val, register u32 n);
extern void* memcpy(register void* dst, register const void* src, register u32 n);
extern int OSBootInfo_801A6748;
extern unsigned char BI2DebugFlag_801A674C[4];
extern unsigned char BI2DebugFlagHolder_801A6750[4];
extern unsigned char AreWeInitialized_801A6768[4];
extern unsigned char DriveInfo_8015BF00[32];
extern unsigned char OSExceptionTable_801225B0[0x100];
extern unsigned char _stack_addr[4];
extern unsigned char OSVersionStr_801A641C[4];
extern u32 OSGetResetCode(void);
extern u64 __OSGetSystemTime(void);
extern int OSDisableInterrupts(void);
extern int OSEnableInterrupts(void);
extern void PPCMtmmcr0(register u32 v);
extern void PPCMtmmcr1(register u32 v);
extern void PPCMtpmc1(register u32 v);
extern void PPCMtpmc2(register u32 v);
extern void PPCMtpmc3(register u32 v);
extern void PPCMtpmc4(register u32 v);
extern void PPCDisableSpeculation(void);
extern void PPCSetFpNonIEEEMode(void);
extern u32 OSGetArenaHi(void);
extern u32 OSGetArenaLo(void);
extern void OSSetArenaHi(register u32 hi);
extern void OSSetArenaLo(register u32 lo);
extern void __OSInitSystemCall(void);
extern void OSInitAlarm(void);
extern void __OSModuleInit(void);
extern void __OSInterruptInit(void);
extern void __OSSetInterruptHandler(register u8 index, register void* handler);
extern void __OSContextInit(void);
extern void __OSCacheInit(void);
extern void EXIInit(void);
extern void SIInit(void);
extern void __OSInitSram(void);
extern void __OSThreadInit(void);
extern void __OSInitAudioSystem(void);
extern u32 PPCMfhid2(void);
extern void PPCMthid2(register u32 v);
extern void __OSInitMemoryProtection(void);
extern void OSReport(register const char* msg, ...);
extern void EnableMetroTRKInterrupts(void);
extern void DVDInit(void);
extern int DVDInquiryAsync(register void* drive, register void* callback, register void* userWorkArea);
extern void DCInvalidateRange(register void* addr, register u32 nBytes);
extern void DCFlushRangeNoSync(register void* addr, register u32 nBytes);
extern void ICInvalidateRange(register void* addr, register u32 nBytes);
extern void DBPrintf(register const char* msg, ...);
extern int __DBIsExceptionMarked(register u8 exception);
extern void __OSSetExceptionHandler(register u8 index, register void* handler);
extern void OSRegisterVersion(register char* version);

extern void __OSDBINTSTART(void);
extern void __OSDBINTEND(void);
extern void __OSDBJUMPEND(void);
extern void __OSEVStart(void);
extern void __OSEVEnd(void);
extern void __OSEVSetNumber(void);
extern void OSDefaultExceptionHandler(int exception, void* context);
extern void __OSResetSWInterruptHandler(int interrupt, void* context);
extern unsigned char __ArenaLo[4];
extern unsigned char __ArenaHi[4];
extern void __DBVECTOR(void);
extern void __DBVECTOR(void);
extern void __OSDBINTEND(void);
extern void __OSDBINTSTART(void);
extern void __OSDBJUMPEND(void);
extern void __OSEVEnd(void);
extern void __OSEVSetNumber(void);
extern void __OSEVStart(void);

static asm void OSExceptionInit(void);
#pragma push
#pragma force_active on

extern unsigned char OSExceptionTable[4];
extern unsigned char __DVDLongFileNameFlag[4];
extern unsigned char __OSInIPL[4];
extern unsigned char __OSIsGcam[4];
extern unsigned char __OSSavedRegionEnd[4];
extern unsigned char __OSSavedRegionStart[4];
extern unsigned char __OSStartTime[8];
extern unsigned char __OSVersion[4];
extern unsigned char __PADSpec[4];
asm void OSGetConsoleType(void)
{
    nofralloc
    lwz r3, OSBootInfo_801A6748
    cmplwi	r3, 0
    beq     _8000a23c
    lwz	r3, 0x2c(r3)
    cmplwi	r3, 0
    bne     _8000a248
_8000a23c:
    lis	r3, 0x1000
    addi	r3, r3, 2
    b       _8000a248
_8000a248:
    blr
}

static asm void ClearArena(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      OSGetResetCode
    addis	r0, r3, -0x8000
    cmplwi	r0, 0
    beq     _8000a29c
    li	r0, 0
    stw	r0, __OSSavedRegionStart
    stw	r0, __OSSavedRegionEnd
    bl      OSGetArenaHi
    mr	r31, r3
    bl      OSGetArenaLo
    subf	r31, r3, r31
    bl      OSGetArenaLo
    mr	r5, r31
    li	r4, 0
    bl      memset
    b       _8000a360
_8000a29c:
    lis	r4, -0x7ed0
    lwz	r3, -0x2010(r4)
    lwz	r0, -0x2014(r4)
    cmplwi	r3, 0
    stw	r3, __OSSavedRegionStart
    stw	r0, __OSSavedRegionEnd
    bne     _8000a2dc
    bl      OSGetArenaHi
    mr	r31, r3
    bl      OSGetArenaLo
    subf	r31, r3, r31
    bl      OSGetArenaLo
    mr	r5, r31
    li	r4, 0
    bl      memset
    b       _8000a360
_8000a2dc:
    bl      OSGetArenaLo
    lwz	r0, __OSSavedRegionStart
    cmplw	r3, r0
    bge     _8000a360
    bl      OSGetArenaHi
    lwz	r0, __OSSavedRegionStart
    cmplw	r3, r0
    bgt     _8000a320
    bl      OSGetArenaHi
    mr	r31, r3
    bl      OSGetArenaLo
    subf	r31, r3, r31
    bl      OSGetArenaLo
    mr	r5, r31
    li	r4, 0
    bl      memset
    b       _8000a360
_8000a320:
    bl      OSGetArenaLo
    lwz	r0, __OSSavedRegionStart
    subf	r31, r3, r0
    bl      OSGetArenaLo
    mr	r5, r31
    li	r4, 0
    bl      memset
    bl      OSGetArenaHi
    lwz	r31, __OSSavedRegionEnd
    cmplw	r3, r31
    ble     _8000a360
    bl      OSGetArenaHi
    subf	r5, r31, r3
    mr	r3, r31
    li	r4, 0
    bl      memset
_8000a360:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr
}

static asm void InquiryCallback(register int result, register void* block)
{
    nofralloc
    lwz	r0, 0xc(r4)
    cmpwi	r0, 0
    beq     _8000a384
    b       _8000a3a0
_8000a384:
    lis     r3, DriveInfo_8015BF00@ha
    addi	r3, r3, DriveInfo_8015BF00@l
    lhz	r0, 2(r3)
    lis	r3, -0x8000
    ori	r0, r0, 0x8000
    sth	r0, 0x30e6(r3)
    b       _8000a3ac
_8000a3a0:
    li	r0, 1
    lis	r3, -0x8000
    sth	r0, 0x30e6(r3)
_8000a3ac:
    blr
}

asm void OSInit(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    stw	r29, 0xc(r1)
    lwz r0, AreWeInitialized_801A6768
    lis     r3, DriveInfo_8015BF00@ha
    addi	r30, r3, DriveInfo_8015BF00@l
    cmpwi	r0, 0
    lis	r3, OSExceptionTable_801225B0@ha
    addi	r31, r3, OSExceptionTable_801225B0@l
    bne     _8000a76c
    li	r0, 1
    stw r0, AreWeInitialized_801A6768
    bl      __OSGetSystemTime
    stw r4, -0x7c3c(r13)
    stw	r3, __OSStartTime
    bl      OSDisableInterrupts
    li	r3, 0
    bl      PPCMtmmcr0
    li	r3, 0
    bl      PPCMtmmcr1
    li	r3, 0
    bl      PPCMtpmc1
    li	r3, 0
    bl      PPCMtpmc2
    li	r3, 0
    bl      PPCMtpmc3
    li	r3, 0
    bl      PPCMtpmc4
    bl      PPCDisableSpeculation
    bl      PPCSetFpNonIEEEMode
    li	r0, 0
    lis	r4, -0x8000
    stw r0, BI2DebugFlag_801A674C
    stw r4, OSBootInfo_801A6748
    stw	r0, __DVDLongFileNameFlag
    lwz	r3, 0xf4(r4)
    cmplwi	r3, 0
    beq     _8000a484
    addi	r0, r3, 0xc
    stw r0, BI2DebugFlag_801A674C
    lwz	r0, 0x24(r3)
    lwz r3, BI2DebugFlag_801A674C
    stw	r0, __PADSpec
    lwz	r0, 0(r3)
    clrlwi	r0, r0, 0x18
    stb	r0, 0x30e8(r4)
    lwz	r0, __PADSpec
    clrlwi	r0, r0, 0x18
    stb	r0, 0x30e9(r4)
    b       _8000a4a8
_8000a484:
    lwz	r0, 0x34(r4)
    cmplwi	r0, 0
    beq     _8000a4a8
    lbz	r3, 0x30e8(r4)
    li	r0, BI2DebugFlagHolder_801A6750
    stw r3, BI2DebugFlagHolder_801A6750
    stw r0, BI2DebugFlag_801A674C
    lbz	r0, 0x30e9(r4)
    stw	r0, __PADSpec
_8000a4a8:
    li	r0, 1
    lwz r3, OSBootInfo_801A6748
    stw	r0, __DVDLongFileNameFlag
    lwz	r3, 0x30(r3)
    cmplwi	r3, 0
    bne     _8000a4cc
    lis	r3, __ArenaLo@ha
    addi	r3, r3, __ArenaLo@l
    b       _8000a4cc
_8000a4cc:
    bl      OSSetArenaLo
    lwz r3, OSBootInfo_801A6748
    lwz	r0, 0x30(r3)
    cmplwi	r0, 0
    bne     _8000a50c
    lwz r3, BI2DebugFlag_801A674C
    cmplwi	r3, 0
    beq     _8000a50c
    lwz	r0, 0(r3)
    cmplwi	r0, 2
    bge     _8000a50c
    lis	r3, _stack_addr@ha
    addi	r3, r3, _stack_addr@l
    addi	r0, r3, 0x1f
    rlwinm	r3, r0, 0, 0, 0x1a
    bl      OSSetArenaLo
_8000a50c:
    lwz r3, OSBootInfo_801A6748
    lwz	r3, 0x34(r3)
    cmplwi	r3, 0
    bne     _8000a528
    lis	r3, __ArenaHi@ha
    addi	r3, r3, __ArenaHi@l
    b       _8000a528
_8000a528:
    bl      OSSetArenaHi
    bl      OSExceptionInit
    bl      __OSInitSystemCall
    bl      OSInitAlarm
    bl      __OSModuleInit
    bl      __OSInterruptInit
    lis	r3, __OSResetSWInterruptHandler@ha
    addi	r4, r3, __OSResetSWInterruptHandler@l
    li	r3, 0x16
    bl      __OSSetInterruptHandler
    bl      __OSContextInit
    bl      __OSCacheInit
    bl      EXIInit
    bl      SIInit
    bl      __OSInitSram
    bl      __OSThreadInit
    bl      __OSInitAudioSystem
    bl      PPCMfhid2
    rlwinm	r3, r3, 0, 2, 0
    bl      PPCMthid2
    lwz	r0, __OSInIPL
    cmpwi	r0, 0
    bne     _8000a588
    bl      __OSInitMemoryProtection
_8000a588:
    addi	r3, r31, 0x44
    crxor	6, 6, 6
    bl      OSReport
    addi	r3, r31, 0x54
    crxor	6, 6, 6
    addi	r4, r31, 0x6c
    addi	r5, r31, 0x78
    bl      OSReport
    addi	r3, r31, 0x84
    crxor	6, 6, 6
    bl      OSReport
    lwz r3, OSBootInfo_801A6748
    cmplwi	r3, 0
    beq     _8000a5cc
    lwz	r4, 0x2c(r3)
    cmplwi	r4, 0
    bne     _8000a5d8
_8000a5cc:
    lis	r3, 0x1000
    addi	r4, r3, 2
    b       _8000a5d8
_8000a5d8:
    rlwinm	r3, r4, 0, 0, 3
    lis	r0, 0x1000
    cmpw	r3, r0
    beq     _8000a618
    bge     _8000a5f8
    cmpwi	r3, 0
    beq     _8000a608
    b       _8000a6ac
_8000a5f8:
    lis	r0, 0x2000
    cmpw	r3, r0
    beq     _8000a618
    b       _8000a6ac
_8000a608:
    crxor	6, 6, 6
    addi	r3, r31, 0x94
    bl      OSReport
    b       _8000a6b8
_8000a618:
    lis	r3, 0x1000
    clrlwi	r5, r4, 4
    addi	r0, r3, 2
    cmpw	r5, r0
    beq     _8000a670
    bge     _8000a640
    cmpw	r5, r3
    beq     _8000a650
    bge     _8000a660
    b       _8000a690
_8000a640:
    addi	r0, r3, 4
    cmpw	r5, r0
    bge     _8000a690
    b       _8000a680
_8000a650:
    addi	r3, r31, 0xa0
    crxor	6, 6, 6
    bl      OSReport
    b       _8000a6b8
_8000a660:
    addi	r3, r31, 0xb0
    crxor	6, 6, 6
    bl      OSReport
    b       _8000a6b8
_8000a670:
    addi	r3, r31, 0xc0
    crxor	6, 6, 6
    bl      OSReport
    b       _8000a6b8
_8000a680:
    addi	r3, r31, 0xd0
    crxor	6, 6, 6
    bl      OSReport
    b       _8000a6b8
_8000a690:
    clrlwi	r6, r4, 4
    crxor	6, 6, 6
    mr	r5, r4
    addi	r3, r31, 0xe0
    addi	r4, r6, -3
    bl      OSReport
    b       _8000a6b8
_8000a6ac:
    crxor	6, 6, 6
    addi	r3, r13, -0x7fa4
    bl      OSReport
_8000a6b8:
    lwz r4, OSBootInfo_801A6748
    addi	r3, r31, 0xfc
    crxor	6, 6, 6
    lwz	r0, 0x28(r4)
    srwi	r4, r0, 0x14
    bl      OSReport
    bl      OSGetArenaHi
    mr	r29, r3
    bl      OSGetArenaLo
    mr	r4, r3
    crxor	6, 6, 6
    mr	r5, r29
    addi	r3, r31, 0x10c
    bl      OSReport
    lwz	r3, __OSVersion
    bl      OSRegisterVersion
    lwz r3, BI2DebugFlag_801A674C
    cmplwi	r3, 0
    beq     _8000a714
    lwz	r0, 0(r3)
    cmplwi	r0, 2
    blt     _8000a714
    bl      EnableMetroTRKInterrupts
_8000a714:
    bl      ClearArena
    bl      OSEnableInterrupts
    lwz	r0, __OSInIPL
    cmpwi	r0, 0
    bne     _8000a76c
    bl      DVDInit
    lwz	r0, __OSIsGcam
    cmpwi	r0, 0
    beq     _8000a74c
    lis	r3, 1
    addi	r0, r3, -0x7000
    lis	r3, -0x8000
    sth	r0, 0x30e6(r3)
    b       _8000a76c
_8000a74c:
    mr	r3, r30
    li	r4, 0x20
    bl      DCInvalidateRange
    lis     r3, InquiryCallback@ha
    addi	r5, r3, InquiryCallback@l
    mr	r4, r30
    addi	r3, r30, 0x20
    bl      DVDInquiryAsync
_8000a76c:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    lwz	r29, 0xc(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr
}

static asm void OSExceptionInit(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stmw	r20, 8(r1)
    lis	r3, -0x8000
    lwz	r0, 0x60(r3)
    lis	r4, __OSEVSetNumber@ha
    addi	r30, r4, __OSEVSetNumber@l
    lis	r5, __OSEVStart@ha
    lwz	r25, 0(r30)
    lis	r4, __OSEVEnd@ha
    addi	r5, r5, __OSEVStart@l
    addi	r4, r4, __OSEVEnd@l
    lis	r6, OSExceptionTable_801225B0@ha
    cmplwi	r0, 0
    mr	r24, r5
    addi	r29, r6, OSExceptionTable_801225B0@l
    subf	r23, r5, r4
    addi	r20, r3, 0x60
    bne     _8000a820
    addi	r3, r29, 0x160
    crxor	6, 6, 6
    bl      DBPrintf
    lis	r4, __OSDBINTSTART@ha
    lis	r3, __OSDBINTEND@ha
    addi	r0, r3, __OSDBINTEND@l
    addi	r4, r4, __OSDBINTSTART@l
    subf	r21, r4, r0
    mr	r3, r20
    mr	r5, r21
    bl      memcpy
    mr	r3, r20
    mr	r4, r21
    bl      DCFlushRangeNoSync
    sync
    mr	r3, r20
    mr	r4, r21
    bl      ICInvalidateRange
_8000a820:
    lis	r4, __OSDBINTEND@ha
    lis	r3, __OSDBJUMPEND@ha
    addi	r31, r4, __OSDBINTEND@l
    addi	r0, r3, __OSDBJUMPEND@l
    addi	r28, r29, 0x124
    subf	r27, r31, r0
    li	r26, 0
    b       _8000a840
_8000a840:
    lis     r3, __DBVECTOR@ha
    addi	r21, r3, __DBVECTOR@l
    lis	r22, 0x6000
    b       _8000a850
_8000a850:
    b       _8000a998
_8000a854:
    lwz r3, BI2DebugFlag_801A674C
    cmplwi	r3, 0
    beq     _8000a890
    lwz	r0, 0(r3)
    cmplwi	r0, 2
    blt     _8000a890
    mr	r3, r26
    bl      __DBIsExceptionMarked
    cmpwi	r3, 0
    beq     _8000a890
    addi	r3, r29, 0x17c
    crxor	6, 6, 6
    clrlwi	r4, r26, 0x18
    bl      DBPrintf
    b       _8000a990
_8000a890:
    clrlwi	r20, r26, 0x18
    or	r0, r25, r20
    stw	r0, 0(r30)
    mr	r3, r26
    bl      __DBIsExceptionMarked
    cmpwi	r3, 0
    beq     _8000a8d0
    mr	r4, r20
    crxor	6, 6, 6
    addi	r3, r29, 0x1ac
    bl      DBPrintf
    mr	r3, r21
    mr	r4, r31
    mr	r5, r27
    bl      memcpy
    b       _8000a95c
_8000a8d0:
    mr	r4, r21
    b       _8000a8d8
_8000a8d8:
    cmplwi	r27, 0
    addi	r3, r27, 3
    srwi	r3, r3, 2
    ble     _8000a95c
    srwi	r0, r3, 3
    cmplwi	r0, 0
    mtctr	r0
    beq     _8000a948
    b       _8000a8fc
_8000a8fc:
    stw	r22, 0(r4)
    addi	r4, r4, 4
    stw	r22, 0(r4)
    addi	r4, r4, 4
    stw	r22, 0(r4)
    addi	r4, r4, 4
    stw	r22, 0(r4)
    addi	r4, r4, 4
    stw	r22, 0(r4)
    addi	r4, r4, 4
    stw	r22, 0(r4)
    addi	r4, r4, 4
    stw	r22, 0(r4)
    addi	r4, r4, 4
    stw	r22, 0(r4)
    addi	r4, r4, 4
    bdnz    _8000a8fc
    andi.	r3, r3, 7
    beq     _8000a95c
_8000a948:
    mtctr	r3
    b       _8000a950
_8000a950:
    stw	r22, 0(r4)
    addi	r4, r4, 4
    bdnz    _8000a950
_8000a95c:
    lwz	r3, 0(r28)
    mr	r4, r24
    mr	r5, r23
    addis	r20, r3, -0x8000
    mr	r3, r20
    bl      memcpy
    mr	r3, r20
    mr	r4, r23
    bl      DCFlushRangeNoSync
    sync
    mr	r3, r20
    mr	r4, r23
    bl      ICInvalidateRange
_8000a990:
    addi	r28, r28, 4
    addi	r26, r26, 1
_8000a998:
    clrlwi	r0, r26, 0x18
    cmplwi	r0, 0xf
    blt     _8000a854
    lis	r3, -0x8000
    addi	r0, r3, 0x3000
    stw	r0, OSExceptionTable
    li	r20, 0
    b       _8000a9b8
_8000a9b8:
    lis	r3, OSDefaultExceptionHandler@ha
    addi	r23, r3, OSDefaultExceptionHandler@l
    b       _8000a9c4
_8000a9c4:
    b       _8000a9d8
_8000a9c8:
    mr	r3, r20
    mr	r4, r23
    bl      __OSSetExceptionHandler
    addi	r20, r20, 1
_8000a9d8:
    clrlwi	r0, r20, 0x18
    cmplwi	r0, 0xf
    blt     _8000a9c8
    stw	r25, 0(r30)
    addi	r3, r29, 0x1dc
    crxor	6, 6, 6
    bl      DBPrintf
    lmw	r20, 8(r1)
    lwz	r0, 0x3c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr
}

static asm void __OSDBIntegrator(void)
{
    nofralloc
entry __OSDBINTSTART
    li	r5, 0x40
    mflr	r3
    stw	r3, 0xc(r5)
    lwz	r3, 8(r5)
    oris	r3, r3, 0x8000
    mtlr	r3
    li	r3, 0x30
    mtmsr	r3
    blr
entry __OSDBINTEND
}

static asm void __OSDBJump(void)
{
    nofralloc
    bla     0x60
}
#pragma pop
