typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

extern void memset(void);
extern void memcpy(void);
extern void OSAlloc(void);
extern void OSFree(void);
extern void fn_800090A4(void);
extern void DCInvalidateRange(void);
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void OSGetTick(void);
extern void DVDOpen(void);
extern void DVDCancelSync(void);
extern void DVDReadAsync(void);
extern void ARAlloc(void);
extern void ARFree(void);
extern void ARQPostRequest(void);
extern void AXFreeVoice(void);
extern void AXAcquireVoice(void);
extern void AXSetVoicePriority(void);
extern void fn_800211E0(void);
extern void fn_800211EC(void);
extern void fn_80021914(void);
extern void fn_80021928(void);
extern void fn_800230A4(void);
extern void fn_80023168(void);
extern void fn_80023284(void);
extern void fn_80023394(void);
extern void fn_80023438(void);
extern void fn_800234D0(void);
extern void fn_80023568(void);
extern void fn_80024308(void);
extern void fn_80024378(void);
extern void fn_80024D84(void);
extern void fn_80024DF0(void);
extern void fn_800251F0(void);
extern void fn_800253F0(void);
extern void fn_80025C28(void);
extern void fn_80025C70(void);
extern void fn_80025EE4(void);
extern void fn_80025EEC(void);
extern void fn_80025EF4(void);
extern void fn_80026D70(void);
extern void fn_80026D90(void);
extern void fn_80026DB8(void);
extern void fn_80026DD4(void);
extern void fn_80026E04(void);
extern void fn_80026E2C(void);
extern void fn_80026E54(void);
extern void fn_80026E84(void);
extern void fn_80026EAC(void);
extern void fn_80026EE0(void);
extern void fn_80026F4C(void);
extern void fn_80026FB8(void);
extern void fn_80028130(void);
extern void fn_80028164(void);
extern void fn_80028424(void);
extern void fn_800284A0(void);
extern void fn_800284CC(void);
extern void fn_800284E8(void);
extern void fn_800284FC(void);
extern void fn_80028540(void);
extern void fn_80028554(void);
extern void fn_80028568(void);
extern void fn_8002857C(void);
extern void fn_80028598(void);
extern void fn_800288B4(void);
extern void fn_80069AE0(void);
extern void fn_80069CE4(void);
extern void fn_8006A1F8(void);
extern void __cvt_fp2unsigned(void);
extern void sprintf(void);
extern void fn_80082908(void);
extern void fn_80087F54(void);
extern void expf(void);
extern void fn_80088598(void);
extern unsigned char Cannot_open_s_str[15];
extern unsigned char Not_Sound_Allocation_Size_d_str[29];
extern void fn_800243C4(void);
extern void fn_80024E3C(void);
extern void fn_80025504(void);
extern void fn_80025854(void);
extern unsigned char jumptable_801325D8[168];
extern unsigned char jumptable_80132680[260];
extern unsigned char lbl_800929D8[32];
extern unsigned char lbl_800929F8[32];
extern unsigned char lbl_80092A18[160];
extern unsigned char lbl_80092AB8[128];
extern unsigned char lbl_80092B38[32];
extern unsigned char lbl_80092B58[128];
extern unsigned char lbl_80092C38[264];
extern unsigned char lbl_801299D0[256];
extern unsigned char lbl_80129AD0[256];
extern unsigned char lbl_80129BD0[256];
extern unsigned char lbl_80129CD0[256];
extern unsigned char lbl_80129DD0[256];
extern unsigned char lbl_80129ED0[256];
extern unsigned char lbl_80192BD0[20];
extern unsigned char lbl_80192D68[1344];
extern unsigned char lbl_801932A8[96];
extern unsigned char lbl_80193308[96];
extern unsigned char lbl_80193368[156];
extern unsigned char lbl_80193404[156];
extern unsigned char lbl_801934A0[480];
extern unsigned char lbl_80193680[480];
extern unsigned char lbl_80193860[340];
extern unsigned char lbl_801939B4[340];
extern unsigned char lbl_80193B08[32];
extern unsigned char lbl_80193B28[32];
extern unsigned char lbl_80193B48[23336];

asm void SndInitManager(void);
asm void fn_8005C298(void);
asm void SndApplyChannelPan(void);
asm void fn_8005C5C8(void);
asm void fn_8005C7C0(void);
asm void fn_8005C9D8(void);
asm void SndStopAllChannelVoices(void);
asm void fn_8005D258(void);
asm void fn_8005D5A4(void);
asm void fn_8005DB68(void);
asm void fn_8005DCEC(void);
asm void SndSetVoicePriority(void);
asm void SndKillChannelVoice(void);
asm void SndDispatchCommand(void);
asm void SndBoostVoicePriority(void);
asm void fn_80060724(void);
asm void SndCalcVoiceEnvelope(void);
asm void SndClearVoiceSlot(void);
asm void fn_80060C54(void);
asm void fn_800622B0(void);
asm void SndStartVoice(void);
asm void SndPlaySequenceNotes(void);
asm void fn_80063094(void);
asm void SndInitProcTable(void);
asm void fn_8006331C(void);
asm void fn_80063EF4(void);
asm void SndSendParamToChannelVoices(void);
asm void fn_8006413C(void);
asm void fn_800641A8(void);
asm void fn_80064230(void);
asm void SndTickChannels(void);
asm void SndRefreshChannelVoices(void);
asm void fn_800647F0(void);
asm void SndSwapVoice(void);
asm void SndUpdateVoices(void);
asm void SndReleaseProcsForVoices(void);
asm void fn_80064E84(void);
asm void fn_80064FDC(void);
asm void fn_80065390(void);
asm void fn_80065528(void);
asm void SndStartChannelSequence(void);
asm void SndSetCallback2(void);
asm void SndSetCallback1(void);
asm void SndSetCallback0(void);
asm void fn_800658B4(void);
asm void fn_80065A7C(void);
asm void fn_80065AC4(void);
asm void fn_80065AD0(void);
asm void fn_80065B08(void);
asm void SndFreeChannel(void);
asm void SndLoadSamplesARQ(void);
asm void fn_80066C14(void);
asm void SndGetSequenceStatus(void);
asm void fn_80067344(void);
asm void fn_800674FC(void);
asm void fn_80067898(void);
asm void SndTimerUpdate(void);
asm void SndCheckAllocSize(void);
asm void fn_80067F68(void);
asm void fn_80068BFC(void);
asm void fn_80068EB4(void);
asm void fn_800692A4(void);
asm void SndAllocBankEntry(void);

asm void SndInitManager(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80192BD0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_80192BD0@l
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bc      4, 2, _8005c278
    lwz	r0, 4(r31)
    cmplwi	r0, 0
    bc      4, 2, _8005c16c
    li	r3, 0x20
    lis	r0, 4
    stw	r3, 8(r31)
    lis	r3, 4
    stw	r0, 0xc(r31)
    bl      ARAlloc
    stw	r3, 0x10(r31)
_8005c16c:
    addi	r3, r31, 0x14
    li	r4, 0
    li	r5, 0x180
    bl      memset
    lwz	r0, 8(r31)
    addi	r8, r31, 0x14
    lwz	r7, 0x10(r31)
    li	r4, 0
    cmplwi	r0, 0
    mr	r3, r0
    li	r5, 0x1000
    bc      4, 1, _8005c278
    rlwinm.	r0, r0, 0x1d, 3, 0x1f
    mtctr	r0
    bc      12, 2, _8005c258
_8005c1a8:
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    srwi	r0, r6, 1
    stw	r0, 4(r8)
    add	r6, r7, r4
    srwi	r0, r6, 1
    addi	r4, r4, 0x2000
    stw	r5, 8(r8)
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    stw	r0, 0x10(r8)
    srwi	r0, r6, 1
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    stw	r5, 0x14(r8)
    stw	r0, 0x1c(r8)
    srwi	r0, r6, 1
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    stw	r5, 0x20(r8)
    stw	r0, 0x28(r8)
    srwi	r0, r6, 1
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    stw	r5, 0x2c(r8)
    stw	r0, 0x34(r8)
    srwi	r0, r6, 1
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    stw	r5, 0x38(r8)
    stw	r0, 0x40(r8)
    srwi	r0, r6, 1
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    stw	r5, 0x44(r8)
    stw	r0, 0x4c(r8)
    srwi	r0, r6, 1
    stw	r5, 0x50(r8)
    stw	r0, 0x58(r8)
    stw	r5, 0x5c(r8)
    addi	r8, r8, 0x60
    bc      16, 0, _8005c1a8
    andi.	r3, r3, 7
    bc      12, 2, _8005c278
_8005c258:
    mtctr	r3
_8005c25c:
    add	r6, r7, r4
    addi	r4, r4, 0x2000
    srwi	r0, r6, 1
    stw	r0, 4(r8)
    stw	r5, 8(r8)
    addi	r8, r8, 0xc
    bc      16, 0, _8005c25c
_8005c278:
    lwz	r3, 0(r31)
    addi	r0, r3, 1
    stw	r0, 0(r31)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8005C298(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mulli	r0, r3, 0x118
    lwz	r6, -0x7740(r13)
    add	r5, r6, r0
    lbz	r3, 0x140a(r5)
    rlwinm	r3, r3, 5, 0x13, 0x1a
    add	r6, r6, r3
    lwz	r3, 0x5a4(r6)
    cmplwi	r3, 0
    bc      12, 2, _8005c470
    clrlwi	r3, r4, 0x18
    lwz	r7, 0x1428(r5)
    cmplwi	r3, 1
    lwz	r3, 0x1424(r5)
    bc      4, 2, _8005c470
    lbz	r5, 0xd(r7)
    extsb.	r4, r5
    bc      4, 1, _8005c314
    extsb	r4, r5
    lbz	r5, 0x59b(r6)
    addi	r6, r4, 1
    lhz	r4, 0x28(r3)
    mulli	r6, r6, 0x4b0
    srawi	r6, r6, 7
    mullw	r6, r6, r5
    srawi	r6, r6, 7
    add	r6, r6, r4
    cmpwi	r6, 0x4b0
    bc      4, 1, _8005c378
    li	r6, 0x4b0
    b       _8005c378
_8005c314:
    extsb.	r4, r5
    bc      4, 0, _8005c374
    extsb	r5, r5
    lis	r4, 0x4330
    xoris	r5, r5, 0x8000
    stw	r4, 8(r1)
    lfd	f1, -0x7c28(r2)
    stw	r5, 0xc(r1)
    lbz	r5, 0x59b(r6)
    lfd	f0, 8(r1)
    lhz	r4, 0x28(r3)
    fsub	f0, f0, f1
    fabs	f0, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r6, 0x14(r1)
    mulli	r6, r6, 0x4b0
    srawi	r6, r6, 7
    mullw	r6, r6, r5
    srawi	r5, r6, 7
    subf.	r6, r5, r4
    bc      4, 0, _8005c378
    li	r6, 0
    b       _8005c378
_8005c374:
    lhz	r6, 0x28(r3)
_8005c378:
    lwz	r4, -0x7740(r13)
    slwi	r5, r6, 0x10
    add	r4, r4, r0
    stw	r5, 0x14f0(r4)
    lwz	r8, -0x7740(r13)
    lbz	r6, 0xf(r7)
    add	r5, r8, r0
    extsb.	r4, r6
    lbz	r7, 0x140a(r5)
    bc      4, 1, _8005c3dc
    extsb	r4, r6
    rlwinm	r5, r7, 5, 0x13, 0x1a
    addi	r6, r4, 1
    lhz	r4, 0x2a(r3)
    mulli	r6, r6, 0x78
    add	r3, r8, r5
    lbz	r3, 0x59b(r3)
    srawi	r6, r6, 7
    mullw	r6, r6, r3
    srawi	r3, r6, 7
    add	r5, r4, r3
    cmpwi	r5, 0x78
    bc      4, 1, _8005c448
    li	r5, 0x78
    b       _8005c448
_8005c3dc:
    extsb.	r4, r6
    bc      4, 0, _8005c444
    extsb	r4, r6
    lis	r5, 0x4330
    xoris	r6, r4, 0x8000
    rlwinm	r4, r7, 5, 0x13, 0x1a
    stw	r6, 0x14(r1)
    add	r4, r8, r4
    lfd	f1, -0x7c28(r2)
    stw	r5, 0x10(r1)
    lbz	r4, 0x59b(r4)
    lfd	f0, 0x10(r1)
    lhz	r3, 0x2a(r3)
    fsub	f0, f0, f1
    fabs	f0, f0
    fctiwz	f0, f0
    stfd	f0, 8(r1)
    lwz	r5, 0xc(r1)
    mulli	r5, r5, 0x78
    srawi	r5, r5, 7
    mullw	r5, r5, r4
    srawi	r4, r5, 7
    subf.	r5, r4, r3
    bc      4, 0, _8005c448
    li	r5, 0
    b       _8005c448
_8005c444:
    lhz	r5, 0x2a(r3)
_8005c448:
    lwz	r3, -0x7740(r13)
    slwi	r4, r5, 0x10
    add	r3, r3, r0
    stw	r4, 0x151c(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r0
    lwz	r0, 0x141c(r3)
    subf	r0, r5, r0
    slwi	r0, r0, 0x10
    stw	r0, 0x148c(r3)
_8005c470:
    addi	r1, r1, 0x20
    blr
}

asm void SndApplyChannelPan(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    mulli	r30, r3, 0x118
    stw	r29, 0x24(r1)
    stw	r28, 0x20(r1)
    lwz	r28, -0x7740(r13)
    add	r11, r28, r30
    lbz	r3, 0x140a(r11)
    rlwinm	r0, r3, 5, 0x13, 0x1a
    add	r10, r28, r0
    lwz	r4, 0x5a4(r10)
    cmplwi	r4, 0
    bc      12, 2, _8005c5a8
    lbz	r4, 0(r4)
    addi	r12, r30, 0x1414
    lwz	r29, 0x1424(r11)
    lwz	r5, 0x1420(r11)
    neg	r0, r4
    or	r4, r0, r4
    lbz	r0, 0x14(r29)
    rlwinm	r5, r5, 0x10, 0x18, 0x1f
    lbz	r6, 0x596(r10)
    srawi	r9, r4, 0x1f
    cmplwi	r0, 0
    addi	r8, r5, -0x3c
    lbz	r5, 0xb(r29)
    lbz	r7, 0xa(r29)
    extsb	r0, r6
    andc	r31, r8, r9
    lbz	r4, 0x597(r10)
    extsb	r6, r7
    extsb	r5, r5
    add	r31, r0, r31
    extsb	r0, r4
    lwz	r7, 0x1428(r11)
    add	r31, r6, r31
    add	r29, r5, r0
    bc      12, 2, _8005c528
    lhax	r0, r28, r12
    add	r29, r29, r0
    b       _8005c530
_8005c528:
    li	r0, 0
    sthx	r0, r28, r12
_8005c530:
    lbz	r4, 0x19(r7)
    lbz	r5, 0x1a(r7)
    bl      fn_80063EF4
    rlwinm	r0, r3, 0x1e, 0x1a, 0x1f
    lis	r4, 0x4330
    add	r29, r29, r0
    srawi	r5, r3, 8
    xoris	r3, r29, 0x8000
    stw	r4, 0x10(r1)
    add	r31, r31, r5
    lfd	f3, -0x7c28(r2)
    stw	r3, 0x14(r1)
    xoris	r5, r31, 0x8000
    lwz	r0, -0x7740(r13)
    lfd	f0, 0x10(r1)
    stw	r5, 0xc(r1)
    add	r3, r0, r30
    fsub	f0, f0, f3
    lfd	f1, -0x7c18(r2)
    stw	r4, 8(r1)
    lfd	f4, -0x7c20(r2)
    lfd	f2, 8(r1)
    fmul	f0, f1, f0
    fsub	f1, f2, f3
    fmadd	f0, f4, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    slwi	r0, r0, 0x10
    stw	r0, 0x1480(r3)
_8005c5a8:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    lwz	r28, 0x20(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_8005C5C8(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    mulli	r31, r3, 0x118
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    lwz	r5, -0x7740(r13)
    add	r4, r5, r31
    lbz	r6, 0x140a(r4)
    rlwinm	r0, r6, 5, 0x13, 0x1a
    add	r3, r5, r0
    lwz	r3, 0x5a4(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005c7a4
    lwz	r30, 0x1424(r4)
    lbz	r3, 0(r3)
    lbz	r0, 0x15(r30)
    cmplwi	r0, 0
    bc      4, 2, _8005c620
    cmplwi	r3, 0
    bc      4, 2, _8005c6e0
_8005c620:
    rlwinm	r30, r6, 5, 0x13, 0x1a
    add	r3, r5, r30
    lbz	r3, 0x593(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005c678
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 8(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 8(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r3, 0x14(r1)
    b       _8005c67c
_8005c678:
    li	r3, -0x388
_8005c67c:
    lwz	r0, -0x7740(r13)
    mr	r29, r3
    add	r3, r0, r30
    lbz	r3, 0x594(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005c6d8
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x10(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 8(r1)
    lwz	r4, 0xc(r1)
    b       _8005c78c
_8005c6d8:
    li	r4, -0x388
    b       _8005c78c
_8005c6e0:
    lbz	r3, 0x17(r30)
    cmplwi	r3, 0
    bc      12, 2, _8005c730
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x10(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    b       _8005c734
_8005c730:
    li	r0, -0x388
_8005c734:
    lbz	r3, 0x18(r30)
    mr	r29, r0
    cmplwi	r3, 0
    bc      12, 2, _8005c788
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x10(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 8(r1)
    lwz	r4, 0xc(r1)
    b       _8005c78c
_8005c788:
    li	r4, -0x388
_8005c78c:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stw	r29, 0x14a4(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stw	r4, 0x14b0(r3)
_8005c7a4:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_8005C7C0(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    stfd	f31, 0x70(r1)
    psq_st	f31, 0x78(r1), 0, 0
    stfd	f30, 0x60(r1)
    psq_st	f30, 0x68(r1), 0, 0
    stmw	r27, 0x4c(r1)
    mr	r29, r3
    lis     r3, lbl_800929D8@ha
    mulli	r30, r29, 0x118
    lwz	r0, -0x7740(r13)
    addi	r31, r3, lbl_800929D8@l
    addi	r7, r1, 0xc
    add	r4, r0, r30
    addi	r8, r1, 8
    lwz	r0, 0x1420(r4)
    lwz	r27, 0x1424(r4)
    lwz	r3, 0x1428(r4)
    rlwinm	r6, r0, 0x18, 0x18, 0x1f
    lbz	r5, 0x140a(r4)
    mr	r4, r27
    bl      fn_8005D258
    lbz	r5, 6(r27)
    lwz	r4, -0x7740(r13)
    rlwinm.	r0, r5, 0, 0x18, 0x18
    add	r3, r4, r30
    lbz	r0, 0x140a(r3)
    bc      12, 2, _8005c840
    rlwinm	r0, r0, 5, 0x13, 0x1a
    add	r3, r4, r0
    lbz	r5, 0x590(r3)
_8005c840:
    add	r3, r4, r30
    clrlwi	r5, r5, 0x18
    lbz	r0, 0x1411(r3)
    addi	r4, r31, 0x60
    lbzx	r4, r4, r5
    cmplwi	r0, 0xff
    bc      4, 2, _8005c868
    lbz	r0, 0x1412(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _8005c9b0
_8005c868:
    extsh	r3, r4
    lis	r0, 0x4330
    srawi	r4, r3, 2
    addi	r3, r31, 0x20
    addze	r4, r4
    stw	r0, 0x10(r1)
    addi	r0, r4, -1
    lfd	f2, -0x7bf8(r2)
    clrlwi	r28, r0, 0x18
    lfs	f0, -0x7bf0(r2)
    lbzx	r0, r3, r28
    lha	r27, 8(r1)
    stw	r0, 0x14(r1)
    lfs	f31, 0xc(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    addi	r3, r31, 0x40
    lis	r0, 0x4330
    lbzx	r3, r3, r28
    lfd	f0, -0x7c08(r2)
    stw	r3, 0x1c(r1)
    fmul	f3, f0, f1
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x18(r1)
    lfs	f0, -0x7bf0(r2)
    lfd	f1, 0x18(r1)
    frsp	f3, f3
    fsubs	f1, f1, f2
    fadds	f30, f31, f3
    fdivs	f1, f1, f0
    bl      expf
    xoris	r3, r27, 0x8000
    lis	r0, 0x4330
    lfd	f0, -0x7c08(r2)
    stw	r3, 0x24(r1)
    fmul	f1, f0, f1
    lfd	f2, -0x7c28(r2)
    stw	r0, 0x20(r1)
    lfs	f3, -0x7bec(r2)
    lfd	f0, 0x20(r1)
    frsp	f1, f1
    fsubs	f0, f0, f2
    stw	r3, 0x34(r1)
    stw	r0, 0x30(r1)
    fadds	f4, f31, f1
    fmadds	f1, f3, f30, f0
    lfd	f0, 0x30(r1)
    fsubs	f0, f0, f2
    fctiwz	f1, f1
    fmadds	f0, f3, f4, f0
    stfd	f1, 0x28(r1)
    fctiwz	f0, f0
    lwz	r6, 0x2c(r1)
    extsh	r0, r6
    stfd	f0, 0x38(r1)
    cmpwi	r0, -0x3c0
    lwz	r3, 0x3c(r1)
    bc      4, 0, _8005c95c
    li	r6, -0x3c0
_8005c95c:
    extsh	r0, r3
    cmpwi	r0, -0x3c0
    bc      4, 0, _8005c96c
    li	r3, -0x3c0
_8005c96c:
    lwz	r5, -0x7740(r13)
    extsh	r4, r3
    add	r3, r5, r30
    lbz	r0, 0x1411(r3)
    cmplw	r0, r29
    bc      4, 2, _8005c988
    extsh	r4, r6
_8005c988:
    add	r3, r5, r30
    lwz	r0, 0x151c(r3)
    srawi	r0, r0, 0x10
    subf	r0, r0, r4
    slwi	r0, r0, 0x10
    stw	r0, 0x148c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r30
    stw	r4, 0x141c(r3)
    b       _8005c9b4
_8005c9b0:
    stb	r4, 0x1498(r3)
_8005c9b4:
    psq_l	f31, 0x78(r1), 0, 0
    lfd	f31, 0x70(r1)
    psq_l	f30, 0x68(r1), 0, 0
    lfd	f30, 0x60(r1)
    lmw	r27, 0x4c(r1)
    lwz	r0, 0x84(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr
}

asm void fn_8005C9D8(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    stfd	f31, 0x70(r1)
    psq_st	f31, 0x78(r1), 0, 0
    stfd	f30, 0x60(r1)
    psq_st	f30, 0x68(r1), 0, 0
    stmw	r27, 0x4c(r1)
    mr	r29, r3
    lis     r3, lbl_800929D8@ha
    mulli	r30, r29, 0x118
    lwz	r0, -0x7740(r13)
    addi	r31, r3, lbl_800929D8@l
    addi	r7, r1, 0xc
    add	r4, r0, r30
    addi	r8, r1, 8
    lwz	r0, 0x1420(r4)
    lwz	r27, 0x1424(r4)
    lwz	r3, 0x1428(r4)
    rlwinm	r6, r0, 0x18, 0x18, 0x1f
    lbz	r5, 0x140a(r4)
    mr	r4, r27
    bl      fn_8005D258
    lwz	r4, -0x7740(r13)
    extsh	r5, r3
    add	r3, r4, r30
    lbz	r0, 0x1411(r3)
    cmplwi	r0, 0xff
    bc      4, 2, _8005ca58
    lbz	r0, 0x1412(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _8005cba8
_8005ca58:
    lbz	r5, 6(r27)
    add	r3, r4, r30
    lbz	r3, 0x140a(r3)
    rlwinm.	r0, r5, 0, 0x18, 0x18
    bc      12, 2, _8005ca78
    rlwinm	r0, r3, 5, 0x13, 0x1a
    add	r3, r4, r0
    lbz	r5, 0x590(r3)
_8005ca78:
    clrlwi	r0, r5, 0x18
    addi	r3, r31, 0x60
    lbzx	r4, r3, r0
    lis	r0, 0x4330
    addi	r3, r31, 0x20
    stw	r0, 0x10(r1)
    extsh	r0, r4
    lfd	f2, -0x7bf8(r2)
    srawi	r0, r0, 2
    lfs	f0, -0x7bf0(r2)
    addze	r4, r0
    lha	r27, 8(r1)
    addi	r0, r4, -1
    lfs	f31, 0xc(r1)
    clrlwi	r28, r0, 0x18
    lbzx	r0, r3, r28
    stw	r0, 0x14(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    addi	r3, r31, 0x40
    lis	r0, 0x4330
    lbzx	r3, r3, r28
    lfd	f0, -0x7c08(r2)
    stw	r3, 0x1c(r1)
    fmul	f3, f0, f1
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x18(r1)
    lfs	f0, -0x7bf0(r2)
    lfd	f1, 0x18(r1)
    frsp	f3, f3
    fsubs	f1, f1, f2
    fadds	f30, f31, f3
    fdivs	f1, f1, f0
    bl      expf
    xoris	r3, r27, 0x8000
    lis	r0, 0x4330
    lfd	f0, -0x7c08(r2)
    stw	r3, 0x24(r1)
    fmul	f1, f0, f1
    lfd	f2, -0x7c28(r2)
    stw	r0, 0x20(r1)
    lfs	f3, -0x7bec(r2)
    lfd	f0, 0x20(r1)
    frsp	f1, f1
    fsubs	f0, f0, f2
    stw	r3, 0x34(r1)
    stw	r0, 0x30(r1)
    fadds	f4, f31, f1
    fmadds	f1, f3, f30, f0
    lfd	f0, 0x30(r1)
    fsubs	f0, f0, f2
    fctiwz	f1, f1
    fmadds	f0, f3, f4, f0
    stfd	f1, 0x28(r1)
    fctiwz	f0, f0
    lwz	r4, 0x2c(r1)
    extsh	r0, r4
    stfd	f0, 0x38(r1)
    cmpwi	r0, -0x3c0
    lwz	r5, 0x3c(r1)
    bc      4, 0, _8005cb78
    li	r4, -0x3c0
_8005cb78:
    extsh	r0, r5
    cmpwi	r0, -0x3c0
    bc      4, 0, _8005cb88
    li	r5, -0x3c0
_8005cb88:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r30
    lbz	r0, 0x1411(r3)
    cmplw	r0, r29
    bc      4, 2, _8005cba4
    extsh	r5, r4
    b       _8005cba8
_8005cba4:
    extsh	r5, r5
_8005cba8:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r30
    lwz	r0, 0x151c(r3)
    srawi	r0, r0, 0x10
    subf	r0, r0, r5
    slwi	r0, r0, 0x10
    stw	r0, 0x148c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r30
    stw	r5, 0x141c(r3)
    psq_l	f31, 0x78(r1), 0, 0
    lfd	f31, 0x70(r1)
    psq_l	f30, 0x68(r1), 0, 0
    lfd	f30, 0x60(r1)
    lmw	r27, 0x4c(r1)
    lwz	r0, 0x84(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr
}

asm void SndStopAllChannelVoices(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r26, 8(r1)
    mr	r26, r3
    addis	r31, r26, 0x6000
    li	r28, 0
    lwz	r4, -0x7740(r13)
    lwz	r0, 0x444(r4)
    clrlwi	r27, r0, 0x1b
    b       _8005d1f8
_8005cc20:
    cmplwi	r31, 0x100
    bc      4, 2, _8005cd10
    clrlwi	r29, r28, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r30, r29, 0x118
    add	r3, r0, r30
    lbz	r0, 0x1410(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      4, 2, _8005d1f4
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _8005d1f4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r3, -0x7740(r13)
    addi	r0, r30, 0x1434
    lwzx	r3, r3, r0
    bl      fn_80026D70
    lwz	r3, -0x7740(r13)
    addi	r0, r30, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r3, -0x7740(r13)
    addi	r0, r30, 0x1434
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r30
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005ccac
    mr	r3, r29
    bl      SndClearVoiceSlot
    b       _8005ccb4
_8005ccac:
    addi	r3, r3, 0x1438
    bl      fn_80028424
_8005ccb4:
    lwz	r4, -0x7740(r13)
    addi	r0, r30, 0x1408
    li	r6, 0xff
    addi	r3, r30, 0x1420
    stbx	r6, r4, r0
    li	r5, 0
    addi	r0, r30, 0x1409
    lwz	r4, -0x7740(r13)
    stwx	r5, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r30
    lbz	r0, 0x1411(r3)
    cmplw	r0, r29
    bc      4, 2, _8005ccfc
    stb	r6, 0x1411(r3)
    b       _8005d1f4
_8005ccfc:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r29
    bc      4, 2, _8005d1f4
    stb	r6, 0x1412(r3)
    b       _8005d1f4
_8005cd10:
    cmplwi	r31, 0x200
    bc      4, 2, _8005cdfc
    clrlwi	r30, r28, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r29, r30, 0x118
    add	r3, r0, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 1
    bc      4, 2, _8005d1f4
    cmplwi	r0, 0xff
    bc      12, 2, _8005d1f4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      fn_80026D70
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005cd98
    mr	r3, r30
    bl      SndClearVoiceSlot
    b       _8005cda0
_8005cd98:
    addi	r3, r3, 0x1438
    bl      fn_80028424
_8005cda0:
    lwz	r4, -0x7740(r13)
    addi	r0, r29, 0x1408
    li	r6, 0xff
    addi	r3, r29, 0x1420
    stbx	r6, r4, r0
    li	r5, 0
    addi	r0, r29, 0x1409
    lwz	r4, -0x7740(r13)
    stwx	r5, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1411(r3)
    cmplw	r0, r30
    bc      4, 2, _8005cde8
    stb	r6, 0x1411(r3)
    b       _8005d1f4
_8005cde8:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r30
    bc      4, 2, _8005d1f4
    stb	r6, 0x1412(r3)
    b       _8005d1f4
_8005cdfc:
    cmplwi	r31, 0x300
    bc      4, 2, _8005cef4
    clrlwi	r30, r28, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r29, r30, 0x118
    add	r3, r0, r29
    lbz	r4, 0x1408(r3)
    cmplwi	r4, 2
    bc      4, 2, _8005d1f4
    lbz	r0, 0x1410(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      4, 2, _8005d1f4
    cmplwi	r4, 0xff
    bc      12, 2, _8005d1f4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      fn_80026D70
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005ce90
    mr	r3, r30
    bl      SndClearVoiceSlot
    b       _8005ce98
_8005ce90:
    addi	r3, r3, 0x1438
    bl      fn_80028424
_8005ce98:
    lwz	r4, -0x7740(r13)
    addi	r0, r29, 0x1408
    li	r6, 0xff
    addi	r3, r29, 0x1420
    stbx	r6, r4, r0
    li	r5, 0
    addi	r0, r29, 0x1409
    lwz	r4, -0x7740(r13)
    stwx	r5, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1411(r3)
    cmplw	r0, r30
    bc      4, 2, _8005cee0
    stb	r6, 0x1411(r3)
    b       _8005d1f4
_8005cee0:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r30
    bc      4, 2, _8005d1f4
    stb	r6, 0x1412(r3)
    b       _8005d1f4
_8005cef4:
    cmplwi	r31, 0x1100
    bc      4, 2, _8005cff4
    clrlwi	r30, r28, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r29, r30, 0x118
    add	r3, r0, r29
    lwz	r0, 0x1420(r3)
    clrlwi	r0, r0, 0x1c
    cmplw	r0, r27
    bc      4, 2, _8005d1f4
    lbz	r0, 0x1410(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      4, 2, _8005d1f4
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _8005d1f4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      fn_80026D70
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005cf90
    mr	r3, r30
    bl      SndClearVoiceSlot
    b       _8005cf98
_8005cf90:
    addi	r3, r3, 0x1438
    bl      fn_80028424
_8005cf98:
    lwz	r4, -0x7740(r13)
    addi	r0, r29, 0x1408
    li	r6, 0xff
    addi	r3, r29, 0x1420
    stbx	r6, r4, r0
    li	r5, 0
    addi	r0, r29, 0x1409
    lwz	r4, -0x7740(r13)
    stwx	r5, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1411(r3)
    cmplw	r0, r30
    bc      4, 2, _8005cfe0
    stb	r6, 0x1411(r3)
    b       _8005d1f4
_8005cfe0:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r30
    bc      4, 2, _8005d1f4
    stb	r6, 0x1412(r3)
    b       _8005d1f4
_8005cff4:
    cmplwi	r31, 0x1200
    bc      4, 2, _8005d0f0
    clrlwi	r30, r28, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r29, r30, 0x118
    add	r3, r0, r29
    lbz	r4, 0x1408(r3)
    cmplwi	r4, 1
    bc      4, 2, _8005d1f4
    lwz	r0, 0x1420(r3)
    clrlwi	r0, r0, 0x1c
    cmplw	r0, r27
    bc      4, 2, _8005d1f4
    cmplwi	r4, 0xff
    bc      12, 2, _8005d1f4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      fn_80026D70
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005d08c
    mr	r3, r30
    bl      SndClearVoiceSlot
    b       _8005d094
_8005d08c:
    addi	r3, r3, 0x1438
    bl      fn_80028424
_8005d094:
    lwz	r4, -0x7740(r13)
    addi	r0, r29, 0x1408
    li	r6, 0xff
    addi	r3, r29, 0x1420
    stbx	r6, r4, r0
    li	r5, 0
    addi	r0, r29, 0x1409
    lwz	r4, -0x7740(r13)
    stwx	r5, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1411(r3)
    cmplw	r0, r30
    bc      4, 2, _8005d0dc
    stb	r6, 0x1411(r3)
    b       _8005d1f4
_8005d0dc:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r30
    bc      4, 2, _8005d1f4
    stb	r6, 0x1412(r3)
    b       _8005d1f4
_8005d0f0:
    cmplwi	r31, 0x1300
    bc      4, 2, _8005d1f4
    clrlwi	r30, r28, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r29, r30, 0x118
    add	r3, r0, r29
    lbz	r4, 0x1408(r3)
    cmplwi	r4, 2
    bc      4, 2, _8005d1f4
    lwz	r0, 0x1420(r3)
    clrlwi	r0, r0, 0x1c
    cmplw	r0, r27
    bc      4, 2, _8005d1f4
    lbz	r0, 0x1410(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      4, 2, _8005d1f4
    cmplwi	r4, 0xff
    bc      12, 2, _8005d1f4
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      fn_80026D70
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    lwzx	r3, r3, r0
    bl      AXFreeVoice
    lwz	r3, -0x7740(r13)
    addi	r0, r29, 0x1434
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005d194
    mr	r3, r30
    bl      SndClearVoiceSlot
    b       _8005d19c
_8005d194:
    addi	r3, r3, 0x1438
    bl      fn_80028424
_8005d19c:
    lwz	r4, -0x7740(r13)
    addi	r0, r29, 0x1408
    li	r6, 0xff
    addi	r3, r29, 0x1420
    stbx	r6, r4, r0
    li	r5, 0
    addi	r0, r29, 0x1409
    lwz	r4, -0x7740(r13)
    stwx	r5, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    lbz	r0, 0x1411(r3)
    cmplw	r0, r30
    bc      4, 2, _8005d1e4
    stb	r6, 0x1411(r3)
    b       _8005d1f4
_8005d1e4:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r30
    bc      4, 2, _8005d1f4
    stb	r6, 0x1412(r3)
_8005d1f4:
    addi	r28, r28, 1
_8005d1f8:
    clrlwi	r0, r28, 0x18
    cmplwi	r0, 0x40
    bc      12, 0, _8005cc20
    addis	r0, r26, 0x6000
    cmplwi	r0, 0x100
    bc      4, 2, _8005d21c
    li	r3, 1
    bl      fn_8006413C
    b       _8005d230
_8005d21c:
    cmplwi	r0, 0x1100
    bc      4, 2, _8005d230
    mr	r4, r27
    li	r3, 0x11
    bl      SndSendParamToChannelVoices
_8005d230:
    lwz	r3, -0x7740(r13)
    lwz	r3, 0x444(r3)
    rlwinm.	r0, r3, 0, 0x19, 0x19
    bc      4, 2, _8005d244
    bl      SndAllocBankEntry
_8005d244:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8005D258(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stfd	f31, 0x40(r1)
    psq_st	f31, 0x48(r1), 0, 0
    stw	r31, 0x3c(r1)
    stw	r30, 0x38(r1)
    stw	r29, 0x34(r1)
    stw	r28, 0x30(r1)
    lwz	r9, -0x7740(r13)
    mr	r28, r4
    mr	r29, r5
    mr	r30, r7
    lbz	r0, 0x45b(r9)
    mr	r31, r8
    slwi	r0, r0, 4
    add	r4, r9, r0
    lwz	r5, 8(r4)
    cmplwi	r5, 0
    bc      12, 2, _8005d568
    lbz	r3, 6(r3)
    clrlwi	r0, r6, 0x18
    cmplwi	r0, 0
    lwz	r4, 0x20(r5)
    slwi	r3, r3, 7
    li	r7, 0
    add	r3, r5, r3
    addi	r5, r3, 4
    add	r5, r4, r5
    bc      4, 1, _8005d314
    cmplwi	r0, 8
    addi	r0, r6, -8
    bc      4, 1, _8005d2f8
    clrlwi	r0, r0, 0x18
    b       _8005d2ec
_8005d2e4:
    addi	r5, r5, 8
    addi	r7, r7, 8
_8005d2ec:
    clrlwi	r3, r7, 0x18
    cmplw	r3, r0
    bc      12, 0, _8005d2e4
_8005d2f8:
    clrlwi	r0, r6, 0x18
    b       _8005d308
_8005d300:
    addi	r5, r5, 1
    addi	r7, r7, 1
_8005d308:
    clrlwi	r3, r7, 0x18
    cmplw	r3, r0
    bc      12, 0, _8005d300
_8005d314:
    lbz	r3, 0(r5)
    cmplwi	r3, 0
    bc      12, 2, _8005d354
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 8(r1)
    lfs	f0, -0x7bf0(r2)
    lfd	f1, 8(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7c08(r2)
    fmul	f31, f0, f1
    frsp	f31, f31
    b       _8005d358
_8005d354:
    lfs	f31, -0x7be8(r2)
_8005d358:
    lbz	r3, 9(r28)
    cmplwi	r3, 0
    bc      12, 2, _8005d39c
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x10(r1)
    lfs	f0, -0x7bf0(r2)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7c08(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f31, f31, f0
    b       _8005d3a0
_8005d39c:
    lfs	f31, -0x7be8(r2)
_8005d3a0:
    lwz	r0, -0x7740(r13)
    rlwinm	r28, r29, 5, 0x13, 0x1a
    add	r3, r0, r28
    lbz	r3, 0x58f(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005d3f0
    lis	r0, 0x4330
    stw	r3, 0x1c(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x18(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0x18(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7c08(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f31, f31, f0
    b       _8005d3f4
_8005d3f0:
    lfs	f31, -0x7be8(r2)
_8005d3f4:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r28
    lbz	r3, 0x598(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005d440
    lis	r0, 0x4330
    stw	r3, 0x24(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x20(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0x20(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7c08(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f31, f31, f0
    b       _8005d444
_8005d440:
    lfs	f31, -0x7be8(r2)
_8005d444:
    lwz	r4, -0x7740(r13)
    add	r3, r4, r28
    lbz	r0, 0x589(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8005d46c
    lbz	r0, 0x45b(r4)
    slwi	r0, r0, 1
    add	r3, r4, r0
    lha	r28, 0x5a54(r3)
    b       _8005d4d8
_8005d46c:
    lbz	r0, 0x45b(r4)
    slwi	r0, r0, 4
    add	r3, r4, r0
    lbz	r3, 0x491(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005d4bc
    lis	r0, 0x4330
    stw	r3, 0x24(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x20(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0x20(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7c08(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f0, f31, f0
    b       _8005d4c0
_8005d4bc:
    lfs	f0, -0x7be8(r2)
_8005d4c0:
    lwz	r3, -0x7740(r13)
    fmr	f31, f0
    lbz	r0, 0x45b(r3)
    slwi	r0, r0, 1
    add	r3, r3, r0
    lha	r28, 0x5a34(r3)
_8005d4d8:
    lwz	r3, -0x7740(r13)
    lbz	r3, 0x461(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005d520
    lis	r0, 0x4330
    stw	r3, 0x24(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0x20(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0x20(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7c08(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f1, f31, f0
    b       _8005d524
_8005d520:
    lfs	f1, -0x7be8(r2)
_8005d524:
    lfs	f0, -0x7bec(r2)
    lwz	r3, -0x7740(r13)
    fmuls	f0, f0, f1
    lha	r0, 0x5a10(r3)
    fctiwz	f0, f0
    stfs	f1, 0(r30)
    add	r28, r28, r0
    sth	r28, 0(r31)
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    add	r28, r28, r0
    extsh	r0, r28
    cmpwi	r0, -0x3c0
    bc      4, 0, _8005d560
    li	r28, -0x3c0
_8005d560:
    mr	r3, r28
    b       _8005d57c
_8005d568:
    lfs	f0, -0x7be8(r2)
    li	r0, -0x3c0
    li	r3, -0x3c0
    stfs	f0, 0(r30)
    sth	r0, 0(r31)
_8005d57c:
    psq_l	f31, 0x48(r1), 0, 0
    lwz	r0, 0x54(r1)
    lfd	f31, 0x40(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    lwz	r29, 0x34(r1)
    lwz	r28, 0x30(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_8005D5A4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    li	r29, 0
    stw	r28, 0x10(r1)
    mr	r28, r3
    lbz	r0, 0x1b(r3)
    andi.	r3, r0, 0x8f
    bc      12, 2, _8005db44
    cmplwi	r3, 0x80
    bc      4, 2, _8005d710
    li	r30, 0
    li	r31, 0
_8005d5e4:
    lwz	r8, -0x7740(r13)
    add	r7, r8, r31
    lbz	r6, 0x1408(r7)
    cmplwi	r6, 1
    bc      12, 2, _8005d600
    cmplwi	r6, 2
    bc      4, 2, _8005d6fc
_8005d600:
    lbz	r0, 0x140d(r7)
    cmplwi	r0, 0x80
    bc      4, 2, _8005d6fc
    lis	r3, 0xf7f
    lwz	r5, 0x1420(r7)
    addi	r4, r3, 0xff
    lwz	r0, 0x444(r8)
    and	r3, r5, r4
    and	r0, r0, r4
    cmplw	r3, r0
    bc      4, 2, _8005d6fc
    cmplwi	r6, 0xff
    bc      12, 2, _8005d6fc
    li	r0, 2
    stb	r0, 0x1409(r7)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    lbz	r0, 0x1408(r4)
    cmplwi	r0, 3
    bc      4, 2, _8005d680
    lhz	r0, 0x1416(r4)
    li	r3, -0x3c0
    addi	r5, r31, 0x1418
    divw	r0, r3, r0
    stw	r0, 0x1418(r4)
    lwz	r3, -0x7740(r13)
    lwzx	r0, r3, r5
    cmpwi	r0, 0
    bc      4, 2, _8005d6c4
    li	r0, -1
    stwx	r0, r3, r5
    b       _8005d6c4
_8005d680:
    lwz	r3, 0x1424(r4)
    lha	r3, 0x12(r3)
    extsh.	r0, r3
    bc      12, 2, _8005d69c
    slwi	r0, r3, 0x10
    stw	r0, 0x14bc(r4)
    b       _8005d6a4
_8005d69c:
    lis	r0, -0x3c0
    stw	r0, 0x14bc(r4)
_8005d6a4:
    lwz	r4, -0x7740(r13)
    addi	r3, r31, 0x14c0
    lis	r5, -0x3c0
    addi	r0, r31, 0x1416
    stwx	r5, r4, r3
    li	r4, 2
    lwz	r3, -0x7740(r13)
    sthx	r4, r3, r0
_8005d6c4:
    lwz	r3, -0x7740(r13)
    addi	r5, r31, 0x1410
    lbzx	r4, r3, r5
    cmplwi	r4, 2
    bc      12, 0, _8005d6fc
    rlwinm.	r0, r4, 0, 0x18, 0x18
    bc      4, 2, _8005d6fc
    addi	r0, r4, -1
    stbx	r0, r3, r5
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    lwz	r3, 0x1434(r4)
    lbz	r4, 0x1410(r4)
    bl      AXSetVoicePriority
_8005d6fc:
    addi	r30, r30, 1
    addi	r31, r31, 0x118
    cmplwi	r30, 0x40
    bc      12, 0, _8005d5e4
    b       _8005db44
_8005d710:
    clrlwi.	r0, r3, 0x1f
    bc      12, 2, _8005d85c
    li	r30, 0
    mr	r31, r30
_8005d720:
    lwz	r8, -0x7740(r13)
    add	r7, r8, r31
    lbz	r6, 0x1408(r7)
    cmplwi	r6, 1
    bc      12, 2, _8005d73c
    cmplwi	r6, 2
    bc      4, 2, _8005d848
_8005d73c:
    lbz	r0, 0x140d(r7)
    cmplwi	r0, 0x81
    bc      4, 2, _8005d848
    lis	r3, 0xf00
    lwz	r5, 0x1420(r7)
    addi	r4, r3, 0xf
    lwz	r0, 0x444(r8)
    and	r3, r5, r4
    and	r0, r0, r4
    cmplw	r3, r0
    bc      4, 2, _8005d848
    lbz	r3, 0x140c(r7)
    lbz	r0, 0x1c(r28)
    cmplw	r3, r0
    bc      4, 2, _8005d848
    cmplwi	r6, 0xff
    bc      12, 2, _8005d848
    li	r0, 2
    stb	r0, 0x1409(r7)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    lbz	r0, 0x1408(r4)
    cmplwi	r0, 3
    bc      4, 2, _8005d7cc
    lhz	r0, 0x1416(r4)
    li	r3, -0x3c0
    addi	r5, r31, 0x1418
    divw	r0, r3, r0
    stw	r0, 0x1418(r4)
    lwz	r3, -0x7740(r13)
    lwzx	r0, r3, r5
    cmpwi	r0, 0
    bc      4, 2, _8005d810
    li	r0, -1
    stwx	r0, r3, r5
    b       _8005d810
_8005d7cc:
    lwz	r3, 0x1424(r4)
    lha	r3, 0x12(r3)
    extsh.	r0, r3
    bc      12, 2, _8005d7e8
    slwi	r0, r3, 0x10
    stw	r0, 0x14bc(r4)
    b       _8005d7f0
_8005d7e8:
    lis	r0, -0x3c0
    stw	r0, 0x14bc(r4)
_8005d7f0:
    lwz	r4, -0x7740(r13)
    addi	r3, r31, 0x14c0
    lis	r5, -0x3c0
    addi	r0, r31, 0x1416
    stwx	r5, r4, r3
    li	r4, 2
    lwz	r3, -0x7740(r13)
    sthx	r4, r3, r0
_8005d810:
    lwz	r3, -0x7740(r13)
    addi	r5, r31, 0x1410
    lbzx	r4, r3, r5
    cmplwi	r4, 2
    bc      12, 0, _8005d848
    rlwinm.	r0, r4, 0, 0x18, 0x18
    bc      4, 2, _8005d848
    addi	r0, r4, -1
    stbx	r0, r3, r5
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    lwz	r3, 0x1434(r4)
    lbz	r4, 0x1410(r4)
    bl      AXSetVoicePriority
_8005d848:
    addi	r30, r30, 1
    addi	r31, r31, 0x118
    cmplwi	r30, 0x40
    bc      12, 0, _8005d720
    b       _8005db44
_8005d85c:
    rlwinm.	r0, r3, 0, 0x1e, 0x1e
    bc      12, 2, _8005d938
    lwz	r7, -0x7740(r13)
    li	r0, 0x20
    li	r8, 0
    mr	r6, r7
    mtctr	r0
_8005d878:
    lbz	r0, 0x1408(r6)
    cmplwi	r0, 1
    bc      12, 2, _8005d88c
    cmplwi	r0, 2
    bc      4, 2, _8005d8d0
_8005d88c:
    lbz	r0, 0x140d(r6)
    cmplwi	r0, 0x82
    bc      4, 2, _8005d8d0
    lis	r3, 0xf00
    lwz	r5, 0x1420(r6)
    addi	r4, r3, 0xf
    lwz	r0, 0x444(r7)
    and	r3, r5, r4
    and	r0, r0, r4
    cmplw	r3, r0
    bc      4, 2, _8005d8d0
    lbz	r3, 0x140c(r6)
    lbz	r0, 0x1c(r28)
    cmplw	r3, r0
    bc      4, 2, _8005d8d0
    li	r29, 1
    b       _8005db44
_8005d8d0:
    lbz	r0, 0x1520(r6)
    cmplwi	r0, 1
    bc      12, 2, _8005d8e4
    cmplwi	r0, 2
    bc      4, 2, _8005d928
_8005d8e4:
    lbz	r0, 0x1525(r6)
    cmplwi	r0, 0x82
    bc      4, 2, _8005d928
    lis	r3, 0xf00
    lwz	r5, 0x1538(r6)
    addi	r4, r3, 0xf
    lwz	r0, 0x444(r7)
    and	r3, r5, r4
    and	r0, r0, r4
    cmplw	r3, r0
    bc      4, 2, _8005d928
    lbz	r3, 0x1524(r6)
    lbz	r0, 0x1c(r28)
    cmplw	r3, r0
    bc      4, 2, _8005d928
    li	r29, 1
    b       _8005db44
_8005d928:
    addi	r6, r6, 0x230
    addi	r8, r8, 1
    bc      16, 0, _8005d878
    b       _8005db44
_8005d938:
    rlwinm.	r0, r3, 0, 0x1d, 0x1d
    bc      12, 2, _8005da7c
    li	r30, 0
    mr	r31, r30
_8005d948:
    lwz	r6, -0x7740(r13)
    add	r5, r6, r31
    lbz	r4, 0x1408(r5)
    cmplwi	r4, 1
    bc      12, 2, _8005d964
    cmplwi	r4, 2
    bc      4, 2, _8005da68
_8005d964:
    lbz	r0, 0x140d(r5)
    cmplwi	r0, 0x84
    bc      4, 2, _8005da68
    lwz	r3, 0x1420(r5)
    lwz	r0, 0x444(r6)
    rlwinm	r3, r3, 0, 4, 7
    rlwinm	r0, r0, 0, 4, 7
    cmplw	r3, r0
    bc      4, 2, _8005da68
    lbz	r3, 0x140c(r5)
    lbz	r0, 0x1c(r28)
    cmplw	r3, r0
    bc      4, 2, _8005da68
    cmplwi	r4, 0xff
    bc      12, 2, _8005da68
    li	r0, 2
    stb	r0, 0x1409(r5)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    lbz	r0, 0x1408(r4)
    cmplwi	r0, 3
    bc      4, 2, _8005d9ec
    lhz	r0, 0x1416(r4)
    li	r3, -0x3c0
    addi	r5, r31, 0x1418
    divw	r0, r3, r0
    stw	r0, 0x1418(r4)
    lwz	r3, -0x7740(r13)
    lwzx	r0, r3, r5
    cmpwi	r0, 0
    bc      4, 2, _8005da30
    li	r0, -1
    stwx	r0, r3, r5
    b       _8005da30
_8005d9ec:
    lwz	r3, 0x1424(r4)
    lha	r3, 0x12(r3)
    extsh.	r0, r3
    bc      12, 2, _8005da08
    slwi	r0, r3, 0x10
    stw	r0, 0x14bc(r4)
    b       _8005da10
_8005da08:
    lis	r0, -0x3c0
    stw	r0, 0x14bc(r4)
_8005da10:
    lwz	r4, -0x7740(r13)
    addi	r3, r31, 0x14c0
    lis	r5, -0x3c0
    addi	r0, r31, 0x1416
    stwx	r5, r4, r3
    li	r4, 2
    lwz	r3, -0x7740(r13)
    sthx	r4, r3, r0
_8005da30:
    lwz	r3, -0x7740(r13)
    addi	r5, r31, 0x1410
    lbzx	r4, r3, r5
    cmplwi	r4, 2
    bc      12, 0, _8005da68
    rlwinm.	r0, r4, 0, 0x18, 0x18
    bc      4, 2, _8005da68
    addi	r0, r4, -1
    stbx	r0, r3, r5
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    lwz	r3, 0x1434(r4)
    lbz	r4, 0x1410(r4)
    bl      AXSetVoicePriority
_8005da68:
    addi	r30, r30, 1
    addi	r31, r31, 0x118
    cmplwi	r30, 0x40
    bc      12, 0, _8005d948
    b       _8005db44
_8005da7c:
    rlwinm.	r0, r3, 0, 0x1c, 0x1c
    bc      12, 2, _8005db44
    lwz	r5, -0x7740(r13)
    li	r0, 0x20
    li	r6, 0
    mr	r4, r5
    mtctr	r0
_8005da98:
    lbz	r0, 0x1408(r4)
    cmplwi	r0, 1
    bc      12, 2, _8005daac
    cmplwi	r0, 2
    bc      4, 2, _8005dae8
_8005daac:
    lbz	r0, 0x140d(r4)
    cmplwi	r0, 0x88
    bc      4, 2, _8005dae8
    lwz	r3, 0x1420(r4)
    lwz	r0, 0x444(r5)
    rlwinm	r3, r3, 0, 4, 7
    rlwinm	r0, r0, 0, 4, 7
    cmplw	r3, r0
    bc      4, 2, _8005dae8
    lbz	r3, 0x140c(r4)
    lbz	r0, 0x1c(r28)
    cmplw	r3, r0
    bc      4, 2, _8005dae8
    li	r29, 1
    b       _8005db44
_8005dae8:
    lbz	r0, 0x1520(r4)
    cmplwi	r0, 1
    bc      12, 2, _8005dafc
    cmplwi	r0, 2
    bc      4, 2, _8005db38
_8005dafc:
    lbz	r0, 0x1525(r4)
    cmplwi	r0, 0x88
    bc      4, 2, _8005db38
    lwz	r3, 0x1538(r4)
    lwz	r0, 0x444(r5)
    rlwinm	r3, r3, 0, 4, 7
    rlwinm	r0, r0, 0, 4, 7
    cmplw	r3, r0
    bc      4, 2, _8005db38
    lbz	r3, 0x1524(r4)
    lbz	r0, 0x1c(r28)
    cmplw	r3, r0
    bc      4, 2, _8005db38
    li	r29, 1
    b       _8005db44
_8005db38:
    addi	r4, r4, 0x230
    addi	r6, r6, 1
    bc      16, 0, _8005da98
_8005db44:
    lwz	r0, 0x24(r1)
    mr	r3, r29
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8005DB68(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    stw	r0, 0x74(r1)
    stfd	f31, 0x60(r1)
    psq_st	f31, 0x68(r1), 0, 0
    stfd	f30, 0x50(r1)
    psq_st	f30, 0x58(r1), 0, 0
    stw	r31, 0x4c(r1)
    stw	r30, 0x48(r1)
    stw	r29, 0x44(r1)
    stw	r28, 0x40(r1)
    extsh	r0, r3
    lis     r3, lbl_800929F8@ha
    srawi	r7, r0, 2
    lis	r0, 0x4330
    addze	r7, r7
    addi	r3, r3, lbl_800929F8@l
    addi	r7, r7, -1
    stw	r0, 8(r1)
    clrlwi	r31, r7, 0x18
    lfd	f2, -0x7bf8(r2)
    lbzx	r0, r3, r31
    fmr	f31, f1
    lfs	f0, -0x7bf0(r2)
    mr	r28, r4
    stw	r0, 0xc(r1)
    mr	r29, r5
    mr	r30, r6
    lfd	f1, 8(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lis     r3, lbl_80092A18@ha
    lis	r0, 0x4330
    addi	r3, r3, lbl_80092A18@l
    lfd	f0, -0x7c08(r2)
    lbzx	r3, r3, r31
    fmul	f3, f0, f1
    stw	r0, 0x10(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r3, 0x14(r1)
    lfs	f0, -0x7bf0(r2)
    lfd	f1, 0x10(r1)
    frsp	f3, f3
    fsubs	f1, f1, f2
    fadds	f30, f31, f3
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7c08(r2)
    lis	r0, 0x4330
    extsh	r3, r28
    stw	r0, 0x18(r1)
    xoris	r3, r3, 0x8000
    fmul	f1, f0, f1
    stw	r3, 0x1c(r1)
    lfd	f2, -0x7c28(r2)
    lfd	f0, 0x18(r1)
    frsp	f4, f1
    stw	r3, 0x2c(r1)
    fsubs	f1, f0, f2
    lfs	f3, -0x7bec(r2)
    stw	r0, 0x28(r1)
    fadds	f4, f31, f4
    lfd	f0, 0x28(r1)
    fmadds	f1, f3, f30, f1
    fsubs	f0, f0, f2
    fctiwz	f1, f1
    fmadds	f0, f3, f4, f0
    stfd	f1, 0x20(r1)
    fctiwz	f0, f0
    lwz	r0, 0x24(r1)
    sth	r0, 0(r29)
    stfd	f0, 0x30(r1)
    lwz	r0, 0x34(r1)
    sth	r0, 0(r30)
    lha	r0, 0(r29)
    cmpwi	r0, -0x3c0
    bc      4, 0, _8005dca8
    li	r0, -0x3c0
    sth	r0, 0(r29)
_8005dca8:
    lha	r0, 0(r30)
    cmpwi	r0, -0x3c0
    bc      4, 0, _8005dcbc
    li	r0, -0x3c0
    sth	r0, 0(r30)
_8005dcbc:
    psq_l	f31, 0x68(r1), 0, 0
    lfd	f31, 0x60(r1)
    psq_l	f30, 0x58(r1), 0, 0
    lfd	f30, 0x50(r1)
    lwz	r31, 0x4c(r1)
    lwz	r30, 0x48(r1)
    lwz	r29, 0x44(r1)
    lwz	r0, 0x74(r1)
    lwz	r28, 0x40(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr
}

asm void fn_8005DCEC(void)
{
    nofralloc
    stwu	r1, -0x150(r1)
    mflr	r0
    stw	r0, 0x154(r1)
    stfd	f31, 0x140(r1)
    psq_st	f31, 0x148(r1), 0, 0
    stfd	f30, 0x130(r1)
    psq_st	f30, 0x138(r1), 0, 0
    stmw	r14, 0xe8(r1)
    lhz	r5, 0(r3)
    li	r0, 1
    lis     r3, lbl_800929D8@ha
    stw	r0, 0xdc(r1)
    cmplwi	r5, 0
    mr	r22, r4
    li	r31, 0
    addi	r14, r3, lbl_800929D8@l
    li	r30, -1
    bc      12, 2, _8005fbb8
    lwz	r4, -0x7740(r13)
    rlwinm	r20, r22, 5, 0x13, 0x1a
    add	r3, r4, r20
    lwz	r16, 0x5a4(r3)
    cmplwi	r16, 0
    bc      12, 2, _8005fbb8
    lbz	r6, 0(r16)
    add	r15, r16, r5
    lwz	r0, 0x444(r4)
    cmpwi	r6, 0
    rlwinm	r3, r0, 0x18, 0x18, 0x1f
    rlwinm	r17, r0, 0x10, 0x18, 0x1f
    mr	r19, r3
    bc      4, 2, _8005ddb0
    lbz	r0, 2(r15)
    cmplw	r3, r0
    bc      12, 0, _8005de0c
    lbz	r0, 3(r15)
    cmplw	r3, r0
    bc      12, 1, _8005de0c
    lhz	r0, 0(r15)
    addi	r31, r15, 0x20
    mtctr	r0
    cmplwi	r0, 0
    bc      4, 1, _8005de0c
_8005dd98:
    lbz	r0, 0(r31)
    cmplw	r0, r17
    bc      4, 0, _8005de0c
    addi	r31, r31, 0x30
    bc      16, 0, _8005dd98
    b       _8005de0c
_8005ddb0:
    cmplwi	r6, 1
    bc      4, 2, _8005ddec
    lbz	r0, 0x21(r15)
    cmpw	r17, r0
    bc      12, 1, _8005de0c
    lbz	r0, 0x20(r15)
    subf.	r0, r0, r17
    bc      12, 0, _8005de0c
    slwi	r0, r0, 1
    add	r3, r15, r0
    lhz	r0, 0x22(r3)
    cmpwi	r0, 0
    bc      12, 2, _8005de0c
    add	r31, r15, r0
    b       _8005de0c
_8005ddec:
    rlwinm	r3, r0, 3, 0x15, 0x18
    lhz	r0, 0(r15)
    or	r3, r3, r17
    cmpw	r3, r0
    bc      12, 1, _8005de0c
    mulli	r0, r3, 0x30
    add	r31, r15, r0
    addi	r31, r31, 0x20
_8005de0c:
    cmplwi	r31, 0
    bc      12, 2, _8005de5c
    cmpwi	r6, 0
    bc      12, 2, _8005de5c
    lbz	r0, 2(r15)
    clrlwi	r3, r19, 0x18
    cmplw	r3, r0
    bc      12, 0, _8005de58
    lbz	r0, 3(r15)
    cmplw	r3, r0
    bc      12, 1, _8005de50
    mr	r3, r31
    bl      fn_8005D5A4
    cmpwi	r3, 0
    bc      12, 2, _8005de5c
    li	r31, 0
    b       _8005de5c
_8005de50:
    li	r31, 0
    b       _8005de5c
_8005de58:
    li	r31, 0
_8005de5c:
    cmplwi	r31, 0
    bc      12, 2, _8005fbb8
    lwz	r3, -0x7740(r13)
    li	r5, 1
    add	r4, r3, r20
    lbz	r0, 0x58a(r4)
    cmplwi	r0, 0
    bc      12, 2, _8005deb4
    lbz	r0, 0x461(r3)
    cmplwi	r0, 0
    bc      4, 2, _8005de8c
    li	r5, 0
_8005de8c:
    add	r4, r3, r20
    lbz	r0, 0x598(r4)
    cmplwi	r0, 0
    bc      4, 2, _8005dea0
    li	r5, 0
_8005dea0:
    add	r4, r3, r20
    lbz	r0, 0x58f(r4)
    cmplwi	r0, 0
    bc      4, 2, _8005deb4
    li	r5, 0
_8005deb4:
    clrlwi.	r0, r5, 0x18
    bc      12, 2, _8005fbb8
    lhz	r0, 2(r31)
    cmplwi	r0, 0
    bc      12, 2, _8005fbb8
    add	r4, r3, r20
    lbz	r0, 0x589(r4)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8005def8
    lbz	r4, 0x1d(r31)
    cmplwi	r4, 0xa
    bc      4, 2, _8005deec
    li	r23, 0xb
    b       _8005df04
_8005deec:
    addi	r0, r4, 0xb
    clrlwi	r23, r0, 0x18
    b       _8005df04
_8005def8:
    lbz	r4, 0x1d(r31)
    addi	r0, r4, 0xb
    clrlwi	r23, r0, 0x18
_8005df04:
    lbz	r6, 0(r16)
    add	r5, r3, r20
    lbz	r4, 0x596(r5)
    addi	r7, r17, -0x3c
    neg	r0, r6
    lbz	r25, 0x14(r31)
    or	r0, r0, r6
    lbz	r6, 0xa(r31)
    srawi	r8, r0, 0x1f
    lbz	r3, 0xb(r31)
    lbz	r0, 0x597(r5)
    cmplwi	r25, 0
    andc	r24, r7, r8
    extsb	r4, r4
    extsb	r5, r6
    extsb	r3, r3
    add	r24, r4, r24
    extsb	r0, r0
    add	r24, r5, r24
    add	r17, r3, r0
    bc      12, 2, _8005df7c
    bl      fn_80082908
    slwi	r4, r25, 1
    divw	r0, r3, r4
    mullw	r0, r0, r4
    subf	r0, r0, r3
    subf	r0, r25, r0
    extsh	r25, r0
    add	r17, r17, r25
    b       _8005df80
_8005df7c:
    li	r25, 0
_8005df80:
    lbz	r4, 0x19(r15)
    mr	r3, r22
    lbz	r5, 0x1a(r15)
    bl      fn_80063EF4
    rlwinm	r0, r3, 0x1e, 0x1a, 0x1f
    lis	r4, 0x4330
    add	r17, r17, r0
    srawi	r3, r3, 8
    xoris	r0, r17, 0x8000
    stw	r4, 0xb0(r1)
    add	r24, r24, r3
    lfd	f3, -0x7c28(r2)
    stw	r0, 0xb4(r1)
    xoris	r3, r24, 0x8000
    lfd	f1, -0x7c18(r2)
    lis	r0, 0x960
    lfd	f0, 0xb0(r1)
    stw	r3, 0xac(r1)
    fsub	f0, f0, f3
    lfd	f4, -0x7c20(r2)
    stw	r4, 0xa8(r1)
    lfd	f2, 0xa8(r1)
    fmul	f0, f1, f0
    fsub	f1, f2, f3
    fmadd	f0, f4, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xb8(r1)
    lwz	r3, 0xbc(r1)
    slwi	r29, r3, 0x10
    cmpw	r29, r0
    bc      4, 1, _8005e00c
    lwz	r3, -0x7740(r13)
    lwz	r0, 0x444(r3)
    stw	r0, 0x46c(r3)
    b       _8005e018
_8005e00c:
    mr	r3, r23
    bl      SndSwapVoice
    mr	r30, r3
_8005e018:
    cmpwi	r30, -1
    bc      12, 2, _8005fbb8
    lwz	r5, -0x7740(r13)
    add	r3, r5, r20
    lbz	r0, 0x589(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8005e048
    mulli	r0, r30, 0x118
    li	r4, 2
    add	r3, r5, r0
    stb	r4, 0x1408(r3)
    b       _8005e058
_8005e048:
    mulli	r0, r30, 0x118
    li	r4, 1
    add	r3, r5, r0
    stb	r4, 0x1408(r3)
_8005e058:
    lwz	r3, -0x7740(r13)
    mulli	r24, r30, 0x118
    li	r0, 0x80
    lwz	r4, 0x444(r3)
    add	r3, r3, r24
    stw	r4, 0x1420(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stb	r22, 0x140a(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stw	r31, 0x1424(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stw	r15, 0x1428(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    sth	r25, 0x1414(r3)
    lwz	r4, -0x7740(r13)
    add	r3, r4, r20
    lbz	r3, 0x589(r3)
    clrlwi.	r3, r3, 0x1f
    bc      12, 2, _8005e0bc
    ori	r0, r0, 0x40
    clrlwi	r0, r0, 0x18
_8005e0bc:
    lbz	r3, 1(r31)
    rlwinm.	r3, r3, 0, 0x18, 0x18
    bc      12, 2, _8005e0d0
    ori	r0, r0, 8
    clrlwi	r0, r0, 0x18
_8005e0d0:
    add	r3, r4, r24
    stb	r0, 0x140b(r3)
    lwz	r4, -0x7740(r13)
    add	r3, r4, r20
    lbz	r0, 0x59a(r3)
    cmplwi	r0, 0
    bc      12, 2, _8005e0fc
    add	r3, r4, r24
    lbz	r0, 0x140b(r3)
    ori	r0, r0, 1
    stb	r0, 0x140b(r3)
_8005e0fc:
    lwz	r0, -0x7740(r13)
    lbz	r4, 0x1c(r31)
    add	r3, r0, r24
    stb	r4, 0x140c(r3)
    lwz	r4, -0x7740(r13)
    add	r3, r4, r20
    lbz	r0, 0x589(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8005e148
    lbz	r0, 0x1d(r31)
    cmplwi	r0, 0xa
    bc      4, 2, _8005e13c
    add	r3, r4, r24
    li	r0, 0x8b
    stb	r0, 0x1410(r3)
    b       _8005e150
_8005e13c:
    add	r3, r4, r24
    stb	r23, 0x1410(r3)
    b       _8005e150
_8005e148:
    add	r3, r4, r24
    stb	r23, 0x1410(r3)
_8005e150:
    lbz	r4, 0x1b(r31)
    li	r3, 0
    lwz	r0, -0x7740(r13)
    andi.	r5, r4, 0xcf
    add	r4, r0, r24
    stb	r5, 0x140d(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    sth	r3, 0x1416(r4)
    lhz	r5, 2(r31)
    cmplwi	r5, 0x100
    bc      12, 0, _8005e1f8
    lwz	r4, -0x7740(r13)
    addi	r6, r5, -0x100
    cmplwi	r6, 0
    lbz	r0, 0x45b(r4)
    slwi	r0, r0, 4
    add	r4, r4, r0
    lwz	r4, 8(r4)
    lwz	r0, 0x38(r4)
    addi	r4, r4, 4
    add	r4, r0, r4
    bc      4, 1, _8005e1f0
    cmplwi	r6, 8
    addi	r5, r6, -8
    bc      4, 1, _8005e1d8
    addi	r0, r5, 7
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r5, 0
    bc      4, 1, _8005e1d8
_8005e1cc:
    addi	r4, r4, 0x220
    addi	r3, r3, 8
    bc      16, 0, _8005e1cc
_8005e1d8:
    subf	r0, r3, r6
    mtctr	r0
    cmplw	r3, r6
    bc      4, 0, _8005e1f0
_8005e1e8:
    addi	r4, r4, 0x44
    bc      16, 0, _8005e1e8
_8005e1f0:
    mr	r17, r4
    b       _8005e284
_8005e1f8:
    lis	r4, 1
    li	r0, 4
    addi	r4, r4, -0x53bc
    cmplwi	r5, 0x2a
    sth	r4, 0x9c(r1)
    stb	r3, 0x9b(r1)
    stb	r0, 0x9a(r1)
    stw	r3, 0x64(r1)
    bc      12, 1, _8005e23c
    addi	r0, r5, -1
    li	r4, 0xc8
    mulli	r0, r0, 0xc8
    li	r3, 0x63
    stw	r4, 0xa0(r1)
    stw	r3, 0x68(r1)
    stw	r0, 0x60(r1)
    b       _8005e280
_8005e23c:
    cmplwi	r5, 0x54
    bc      12, 1, _8005e264
    addi	r0, r5, -0x2b
    li	r4, 0x190
    mulli	r0, r0, 0xc8
    li	r3, 0xc7
    stw	r4, 0xa0(r1)
    stw	r3, 0x68(r1)
    stw	r0, 0x60(r1)
    b       _8005e280
_8005e264:
    addi	r0, r5, -0x55
    li	r4, 0x64
    mulli	r0, r0, 0x64
    li	r3, 0x31
    stw	r4, 0xa0(r1)
    stw	r3, 0x68(r1)
    stw	r0, 0x60(r1)
_8005e280:
    addi	r17, r1, 0x60
_8005e284:
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x1438
    li	r5, 0x7d00
    add	r4, r0, r24
    add	r3, r0, r3
    lwz	r4, 0x1434(r4)
    bl      fn_80028130
    mr	r3, r15
    mr	r4, r31
    mr	r5, r22
    mr	r6, r19
    addi	r7, r1, 0xc
    addi	r8, r1, 8
    bl      fn_8005D258
    lbz	r0, 0x3b(r17)
    extsh	r28, r3
    cmplwi	r0, 1
    bc      4, 2, _8005e400
    lbz	r3, 6(r31)
    li	r27, 4
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      12, 2, _8005e2e8
    lwz	r0, -0x7740(r13)
    add	r3, r0, r20
    lbz	r3, 0x590(r3)
_8005e2e8:
    clrlwi	r0, r3, 0x18
    addi	r3, r14, 0x60
    lbzx	r4, r3, r0
    lis	r0, 0x4330
    addi	r3, r14, 0x20
    stw	r0, 0xb8(r1)
    extsh	r0, r4
    lfd	f2, -0x7bf8(r2)
    srawi	r0, r0, 2
    lfs	f0, -0x7bf0(r2)
    addze	r4, r0
    lha	r18, 8(r1)
    addi	r0, r4, -1
    lfs	f31, 0xc(r1)
    clrlwi	r19, r0, 0x18
    lbzx	r0, r3, r19
    stw	r0, 0xbc(r1)
    lfd	f1, 0xb8(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    addi	r3, r14, 0x40
    lis	r0, 0x4330
    lbzx	r3, r3, r19
    lfd	f0, -0x7c08(r2)
    stw	r3, 0xb4(r1)
    fmul	f3, f0, f1
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0xb0(r1)
    lfs	f0, -0x7bf0(r2)
    lfd	f1, 0xb0(r1)
    frsp	f3, f3
    fsubs	f1, f1, f2
    fadds	f30, f31, f3
    fdivs	f1, f1, f0
    bl      expf
    xoris	r3, r18, 0x8000
    lis	r0, 0x4330
    lfd	f0, -0x7c08(r2)
    stw	r3, 0xac(r1)
    fmul	f1, f0, f1
    lfd	f2, -0x7c28(r2)
    stw	r0, 0xa8(r1)
    lfs	f3, -0x7bec(r2)
    lfd	f0, 0xa8(r1)
    frsp	f1, f1
    fsubs	f0, f0, f2
    stw	r3, 0xcc(r1)
    stw	r0, 0xc8(r1)
    fadds	f4, f31, f1
    fmadds	f1, f3, f30, f0
    lfd	f0, 0xc8(r1)
    fsubs	f0, f0, f2
    fctiwz	f1, f1
    fmadds	f0, f3, f4, f0
    stfd	f1, 0xc0(r1)
    fctiwz	f0, f0
    lwz	r21, 0xc4(r1)
    extsh	r0, r21
    stfd	f0, 0xd0(r1)
    cmpwi	r0, -0x3c0
    lwz	r18, 0xd4(r1)
    bc      4, 0, _8005e3e8
    li	r21, -0x3c0
_8005e3e8:
    extsh	r0, r18
    cmpwi	r0, -0x3c0
    bc      4, 0, _8005e3f8
    li	r18, -0x3c0
_8005e3f8:
    extsh	r28, r21
    b       _8005e424
_8005e400:
    lbz	r3, 6(r31)
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      12, 2, _8005e418
    lwz	r0, -0x7740(r13)
    add	r3, r0, r20
    lbz	r3, 0x590(r3)
_8005e418:
    clrlwi	r0, r3, 0x18
    addi	r3, r14, 0x60
    lbzx	r27, r3, r0
_8005e424:
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x462(r3)
    cmplwi	r0, 0
    bc      4, 2, _8005e7ac
    lbz	r0, 0x3b(r17)
    cmplwi	r0, 1
    bc      4, 2, _8005e49c
    extsh	r3, r21
    extsh	r0, r18
    add	r0, r3, r0
    lis	r3, 0x4330
    xoris	r4, r0, 0x8000
    xoris	r0, r28, 0x8000
    stw	r4, 0xd4(r1)
    li	r27, 0x40
    lfd	f2, -0x7c28(r2)
    stw	r3, 0xd0(r1)
    lfs	f3, -0x7be4(r2)
    lfd	f0, 0xd0(r1)
    stw	r0, 0xcc(r1)
    fsubs	f1, f0, f2
    stw	r3, 0xc8(r1)
    lfd	f0, 0xc8(r1)
    fsubs	f0, f0, f2
    fmadds	f0, f3, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xc0(r1)
    lwz	r0, 0xc4(r1)
    extsh	r28, r0
    b       _8005e7ac
_8005e49c:
    clrlwi	r18, r27, 0x18
    lis	r3, -0x7efe
    subfic	r4, r18, 0x7f
    lis	r0, 0x4330
    addi	r3, r3, 0x409
    stw	r0, 0xd0(r1)
    mulhw	r3, r3, r4
    lfd	f8, -0x7c28(r2)
    lfd	f1, -0x7be0(r2)
    add	r3, r3, r4
    srawi	r3, r3, 6
    srwi	r4, r3, 0x1f
    add	r3, r3, r4
    xoris	r3, r3, 0x8000
    stw	r3, 0xd4(r1)
    lfd	f0, 0xd0(r1)
    fsubs	f0, f0, f8
    fcmpo	cr0, f0, f1
    bc      4, 1, _8005e59c
    stw	r3, 0xd4(r1)
    lfd	f7, -0x7bd8(r2)
    stw	r0, 0xd0(r1)
    lfd	f6, -0x7bd0(r2)
    lfd	f0, 0xd0(r1)
    stw	r3, 0xcc(r1)
    fsubs	f0, f0, f8
    stw	r0, 0xc8(r1)
    frsqrte	f3, f0
    lfd	f0, 0xc8(r1)
    stw	r3, 0xc4(r1)
    fsubs	f2, f0, f8
    fmul	f1, f3, f3
    stw	r0, 0xc0(r1)
    fmul	f3, f7, f3
    lfd	f0, 0xc0(r1)
    stw	r3, 0xbc(r1)
    fnmsub	f1, f2, f1, f6
    stw	r0, 0xb8(r1)
    fsubs	f2, f0, f8
    lfd	f0, 0xb8(r1)
    fmul	f4, f3, f1
    stw	r3, 0xb4(r1)
    stw	r0, 0xb0(r1)
    fsubs	f3, f0, f8
    fmul	f0, f4, f4
    lfd	f1, 0xb0(r1)
    stw	r3, 0xac(r1)
    fmul	f5, f7, f4
    stw	r0, 0xa8(r1)
    fnmsub	f4, f2, f0, f6
    lfd	f0, 0xa8(r1)
    fsubs	f2, f1, f8
    fsubs	f0, f0, f8
    fmul	f4, f5, f4
    fmul	f1, f4, f4
    fmul	f4, f7, f4
    fnmsub	f1, f3, f1, f6
    fmul	f3, f4, f1
    fmul	f1, f3, f3
    fmul	f3, f7, f3
    fnmsub	f1, f2, f1, f6
    fmul	f1, f3, f1
    fmul	f1, f0, f1
    b       _8005e5e4
_8005e59c:
    stw	r3, 0xd4(r1)
    stw	r0, 0xd0(r1)
    lfd	f0, 0xd0(r1)
    fsubs	f0, f0, f8
    fcmpu	cr0, f1, f0
    bc      4, 2, _8005e5b8
    b       _8005e5e4
_8005e5b8:
    stw	r3, 0xd4(r1)
    stw	r0, 0xd0(r1)
    lfd	f0, 0xd0(r1)
    fsubs	f0, f0, f8
    fcmpu	cr0, f0, f1
    bc      12, 2, _8005e5dc
    lis	r3, -0x7fe6
    lfs	f1, 0x6648(r3)
    b       _8005e5e4
_8005e5dc:
    lis	r3, -0x7fe6
    lfs	f1, 0x664c(r3)
_8005e5e4:
    bl      expf
    lis	r3, -0x7efe
    lfd	f0, -0x7bc8(r2)
    addi	r3, r3, 0x409
    lis	r0, 0x4330
    mulhw	r3, r3, r18
    fmul	f0, f0, f1
    stw	r0, 0xc8(r1)
    lfd	f8, -0x7c28(r2)
    lfd	f1, -0x7be0(r2)
    fctiwz	f0, f0
    add	r3, r3, r18
    srawi	r3, r3, 6
    stfd	f0, 0xd0(r1)
    srwi	r4, r3, 0x1f
    add	r3, r3, r4
    lwz	r21, 0xd4(r1)
    xoris	r3, r3, 0x8000
    stw	r3, 0xcc(r1)
    lfd	f0, 0xc8(r1)
    fsubs	f0, f0, f8
    fcmpo	cr0, f0, f1
    bc      4, 1, _8005e6f4
    stw	r3, 0xd4(r1)
    lfd	f7, -0x7bd8(r2)
    stw	r0, 0xd0(r1)
    lfd	f6, -0x7bd0(r2)
    lfd	f0, 0xd0(r1)
    stw	r3, 0xcc(r1)
    fsubs	f0, f0, f8
    stw	r0, 0xc8(r1)
    frsqrte	f3, f0
    lfd	f0, 0xc8(r1)
    stw	r3, 0xc4(r1)
    fsubs	f2, f0, f8
    fmul	f1, f3, f3
    stw	r0, 0xc0(r1)
    fmul	f3, f7, f3
    lfd	f0, 0xc0(r1)
    stw	r3, 0xbc(r1)
    fnmsub	f1, f2, f1, f6
    stw	r0, 0xb8(r1)
    fsubs	f2, f0, f8
    lfd	f0, 0xb8(r1)
    fmul	f4, f3, f1
    stw	r3, 0xb4(r1)
    stw	r0, 0xb0(r1)
    fsubs	f3, f0, f8
    fmul	f0, f4, f4
    lfd	f1, 0xb0(r1)
    stw	r3, 0xac(r1)
    fmul	f5, f7, f4
    stw	r0, 0xa8(r1)
    fnmsub	f4, f2, f0, f6
    lfd	f0, 0xa8(r1)
    fsubs	f2, f1, f8
    fsubs	f0, f0, f8
    fmul	f4, f5, f4
    fmul	f1, f4, f4
    fmul	f4, f7, f4
    fnmsub	f1, f3, f1, f6
    fmul	f3, f4, f1
    fmul	f1, f3, f3
    fmul	f3, f7, f3
    fnmsub	f1, f2, f1, f6
    fmul	f1, f3, f1
    fmul	f1, f0, f1
    b       _8005e73c
_8005e6f4:
    stw	r3, 0xd4(r1)
    stw	r0, 0xd0(r1)
    lfd	f0, 0xd0(r1)
    fsubs	f0, f0, f8
    fcmpu	cr0, f1, f0
    bc      4, 2, _8005e710
    b       _8005e73c
_8005e710:
    stw	r3, 0xd4(r1)
    stw	r0, 0xd0(r1)
    lfd	f0, 0xd0(r1)
    fsubs	f0, f0, f8
    fcmpu	cr0, f0, f1
    bc      12, 2, _8005e734
    lis	r3, -0x7fe6
    lfs	f1, 0x6648(r3)
    b       _8005e73c
_8005e734:
    lis	r3, -0x7fe6
    lfs	f1, 0x664c(r3)
_8005e73c:
    bl      expf
    lfd	f0, -0x7c08(r2)
    lis	r3, 0x4330
    xoris	r0, r28, 0x8000
    extsh	r4, r21
    fmul	f0, f0, f1
    stw	r3, 0xc8(r1)
    lfd	f2, -0x7c28(r2)
    li	r27, 0x40
    stw	r0, 0xc4(r1)
    lfs	f3, -0x7be4(r2)
    fctiwz	f1, f0
    stw	r3, 0xc0(r1)
    lfd	f0, 0xc0(r1)
    stfd	f1, 0xd0(r1)
    fsubs	f0, f0, f2
    lwz	r18, 0xd4(r1)
    extsh	r0, r18
    add	r0, r4, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0xcc(r1)
    lfd	f1, 0xc8(r1)
    fsubs	f1, f1, f2
    fmadds	f0, f3, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xb8(r1)
    lwz	r0, 0xbc(r1)
    extsh	r28, r0
_8005e7ac:
    lbz	r3, 8(r31)
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      12, 2, _8005e7d8
    lwz	r0, -0x7740(r13)
    addi	r3, r14, 0
    add	r4, r0, r20
    lbz	r0, 0x58e(r4)
    slwi	r0, r0, 1
    lhax	r0, r3, r0
    sth	r0, 0xe0(r1)
    b       _8005e7e8
_8005e7d8:
    rlwinm	r0, r3, 1, 0x17, 0x1e
    addi	r3, r14, 0
    lhax	r0, r3, r0
    sth	r0, 0xe0(r1)
_8005e7e8:
    lbz	r0, 0x15(r31)
    lbz	r3, 0(r16)
    cmplwi	r0, 0
    bc      4, 2, _8005e800
    cmplwi	r3, 0
    bc      4, 2, _8005e8c4
_8005e800:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r20
    lbz	r4, 0x593(r3)
    lbz	r19, 0x592(r3)
    cmplwi	r4, 0
    bc      12, 2, _8005e85c
    lis	r0, 0x4330
    stw	r4, 0xd4(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0xd0(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0xd0(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0xc8(r1)
    lwz	r3, 0xcc(r1)
    b       _8005e860
_8005e85c:
    li	r3, -0x388
_8005e860:
    lwz	r0, -0x7740(r13)
    stw	r3, 0xd8(r1)
    add	r3, r0, r20
    lbz	r3, 0x594(r3)
    cmplwi	r3, 0
    bc      12, 2, _8005e8bc
    lis	r0, 0x4330
    stw	r3, 0xd4(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0xd0(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0xd0(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0xc8(r1)
    lwz	r26, 0xcc(r1)
    b       _8005e974
_8005e8bc:
    li	r26, -0x388
    b       _8005e974
_8005e8c4:
    lbz	r3, 0x17(r31)
    lbz	r19, 0x16(r31)
    cmplwi	r3, 0
    bc      12, 2, _8005e918
    lis	r0, 0x4330
    stw	r3, 0xd4(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0xd0(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0xd0(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0xc8(r1)
    lwz	r0, 0xcc(r1)
    b       _8005e91c
_8005e918:
    li	r0, -0x388
_8005e91c:
    lbz	r3, 0x18(r31)
    stw	r0, 0xd8(r1)
    cmplwi	r3, 0
    bc      12, 2, _8005e970
    lis	r0, 0x4330
    stw	r3, 0xd4(r1)
    lfd	f2, -0x7bf8(r2)
    stw	r0, 0xd0(r1)
    lfs	f0, -0x7c00(r2)
    lfd	f1, 0xd0(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7c08(r2)
    lfd	f0, -0x7c10(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0xc8(r1)
    lwz	r26, 0xcc(r1)
    b       _8005e974
_8005e970:
    li	r26, -0x388
_8005e974:
    lbz	r3, 7(r31)
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      12, 2, _8005e98c
    lwz	r0, -0x7740(r13)
    add	r3, r0, r20
    lbz	r3, 0x591(r3)
_8005e98c:
    lbz	r0, 0x3a(r17)
    clrlwi	r4, r3, 0x18
    addi	r3, r14, 0x60
    clrlwi.	r5, r0, 0x1e
    lbzx	r0, r3, r4
    stw	r0, 0xe4(r1)
    bc      4, 2, _8005ea10
    li	r0, 0
    li	r4, 0xa
    li	r3, 0x800
    sth	r4, 0x2a(r1)
    li	r16, 2
    sth	r3, 0x58(r1)
    sth	r0, 0x38(r1)
    sth	r0, 0x3a(r1)
    sth	r0, 0x3c(r1)
    sth	r0, 0x3e(r1)
    sth	r0, 0x40(r1)
    sth	r0, 0x42(r1)
    sth	r0, 0x44(r1)
    sth	r0, 0x46(r1)
    sth	r0, 0x48(r1)
    sth	r0, 0x4a(r1)
    sth	r0, 0x4c(r1)
    sth	r0, 0x4e(r1)
    sth	r0, 0x50(r1)
    sth	r0, 0x52(r1)
    sth	r0, 0x54(r1)
    sth	r0, 0x56(r1)
    sth	r0, 0x5a(r1)
    sth	r0, 0x5c(r1)
    sth	r0, 0x5e(r1)
    b       _8005eb4c
_8005ea10:
    cmpwi	r5, 1
    bc      4, 2, _8005ea80
    li	r0, 0
    li	r4, 0x19
    li	r3, 0x100
    sth	r4, 0x2a(r1)
    li	r16, 1
    sth	r3, 0x58(r1)
    sth	r0, 0x38(r1)
    sth	r0, 0x3a(r1)
    sth	r0, 0x3c(r1)
    sth	r0, 0x3e(r1)
    sth	r0, 0x40(r1)
    sth	r0, 0x42(r1)
    sth	r0, 0x44(r1)
    sth	r0, 0x46(r1)
    sth	r0, 0x48(r1)
    sth	r0, 0x4a(r1)
    sth	r0, 0x4c(r1)
    sth	r0, 0x4e(r1)
    sth	r0, 0x50(r1)
    sth	r0, 0x52(r1)
    sth	r0, 0x54(r1)
    sth	r0, 0x56(r1)
    sth	r0, 0x5a(r1)
    sth	r0, 0x5c(r1)
    sth	r0, 0x5e(r1)
    b       _8005eb4c
_8005ea80:
    li	r8, 0
    li	r0, 2
    sth	r8, 0x2a(r1)
    mr	r3, r8
    addi	r9, r1, 0x38
    li	r16, 4
    lhz	r4, 0x2c(r17)
    sth	r4, 0x58(r1)
    mtctr	r0
_8005eaa4:
    addi	r7, r3, 0xc
    addi	r6, r8, 1
    lhzx	r0, r17, r7
    slwi	r5, r6, 1
    addi	r4, r5, 0xc
    addi	r6, r8, 3
    sth	r0, 0(r9)
    slwi	r5, r6, 1
    addi	r7, r3, 0x10
    addi	r6, r8, 5
    lhzx	r0, r17, r4
    addi	r4, r5, 0xc
    slwi	r5, r6, 1
    addi	r6, r8, 7
    sth	r0, 2(r9)
    addi	r8, r8, 8
    lhzx	r0, r17, r7
    addi	r7, r3, 0x14
    sth	r0, 4(r9)
    lhzx	r0, r17, r4
    addi	r4, r5, 0xc
    slwi	r5, r6, 1
    sth	r0, 6(r9)
    lhzx	r0, r17, r7
    addi	r7, r3, 0x18
    addi	r3, r3, 0x10
    sth	r0, 8(r9)
    lhzx	r0, r17, r4
    addi	r4, r5, 0xc
    sth	r0, 0xa(r9)
    lhzx	r0, r17, r7
    sth	r0, 0xc(r9)
    lhzx	r0, r17, r4
    sth	r0, 0xe(r9)
    addi	r9, r9, 0x10
    bc      16, 0, _8005eaa4
    lhz	r0, 0x2e(r17)
    sth	r0, 0x5a(r1)
    lhz	r0, 0x30(r17)
    sth	r0, 0x5c(r1)
    lhz	r0, 0x32(r17)
    sth	r0, 0x5e(r1)
_8005eb4c:
    lhz	r0, 2(r31)
    cmplwi	r0, 0x100
    bc      12, 0, _8005eb78
    lwz	r3, -0x7740(r13)
    lwz	r4, 0(r17)
    lbz	r0, 0x45b(r3)
    slwi	r0, r0, 4
    add	r3, r3, r0
    lwz	r0, 4(r3)
    add	r3, r4, r0
    b       _8005eb88
_8005eb78:
    lwz	r3, -0x7740(r13)
    lwz	r0, 0(r17)
    lwz	r3, 0x1a8(r3)
    add	r3, r3, r0
_8005eb88:
    clrlwi	r0, r16, 0x18
    cmplwi	r0, 4
    bc      12, 2, _8005eba0
    divwu	r3, r3, r0
    mr	r14, r3
    b       _8005eba8
_8005eba0:
    slwi	r3, r3, 1
    addi	r14, r3, 2
_8005eba8:
    lbz	r0, 0x3a(r17)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    bc      12, 2, _8005ec2c
    clrlwi	r0, r16, 0x18
    li	r4, 1
    cmplwi	r0, 4
    sth	r4, 0x28(r1)
    bc      12, 2, _8005ebec
    lwz	r5, 4(r17)
    li	r0, 0
    lwz	r4, 8(r17)
    add	r22, r3, r5
    sth	r0, 0x10(r1)
    add	r21, r3, r4
    sth	r0, 0x12(r1)
    sth	r0, 0x14(r1)
    b       _8005ec14
_8005ebec:
    lwz	r5, 4(r17)
    lwz	r4, 8(r17)
    lhz	r0, 0x34(r17)
    add	r22, r3, r5
    add	r21, r3, r4
    sth	r0, 0x10(r1)
    lhz	r0, 0x36(r17)
    sth	r0, 0x12(r1)
    lhz	r0, 0x38(r17)
    sth	r0, 0x14(r1)
_8005ec14:
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x10
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80023568
    b       _8005ec70
_8005ec2c:
    clrlwi	r5, r16, 0x18
    li	r0, 0
    cmplwi	r5, 4
    sth	r0, 0x28(r1)
    bc      12, 2, _8005ec58
    lwz	r4, -0x7740(r13)
    lwz	r0, 8(r17)
    lwz	r4, 0x1a4(r4)
    add	r21, r3, r0
    divwu	r22, r4, r5
    b       _8005ec70
_8005ec58:
    lwz	r4, -0x7740(r13)
    lwz	r0, 8(r17)
    lwz	r4, 0x1a4(r4)
    add	r21, r3, r0
    slwi	r3, r4, 1
    addi	r22, r3, 2
_8005ec70:
    srwi	r3, r22, 0x10
    srwi	r6, r21, 0x10
    srwi	r5, r14, 0x10
    lwz	r0, -0x7740(r13)
    sth	r3, 0x2c(r1)
    addi	r4, r1, 0x28
    add	r3, r0, r24
    sth	r22, 0x2e(r1)
    sth	r6, 0x30(r1)
    sth	r21, 0x32(r1)
    sth	r5, 0x34(r1)
    sth	r14, 0x36(r1)
    lwz	r3, 0x1434(r3)
    bl      fn_80023284
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x38
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80023394
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_800230A4
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x1490
    add	r3, r0, r3
    bl      fn_800284CC
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x1478
    add	r3, r0, r3
    bl      fn_800284E8
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x1484
    add	r3, r0, r3
    bl      fn_80028540
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x149c
    add	r3, r0, r3
    bl      fn_80028554
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x14a8
    add	r3, r0, r3
    bl      fn_80028568
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x14b4
    add	r3, r0, r3
    bl      fn_8002857C
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x14c8
    add	r3, r0, r3
    bl      fn_800284FC
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x14f4
    add	r3, r0, r3
    bl      fn_80028598
    lbz	r0, 0x1e(r31)
    cmplwi	r0, 0
    bc      4, 2, _8005ed80
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_801299D0@ha
    addi	r3, r24, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_801299D0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ee58
_8005ed80:
    cmplwi	r0, 1
    bc      4, 2, _8005edac
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129AD0@ha
    addi	r3, r24, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129AD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ee58
_8005edac:
    cmplwi	r0, 2
    bc      4, 2, _8005edd8
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129BD0@ha
    addi	r3, r24, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129BD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ee58
_8005edd8:
    cmplwi	r0, 3
    bc      4, 2, _8005ee04
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129CD0@ha
    addi	r3, r24, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129CD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ee58
_8005ee04:
    cmplwi	r0, 4
    bc      4, 2, _8005ee30
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129DD0@ha
    addi	r3, r24, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129DD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ee58
_8005ee30:
    cmplwi	r0, 5
    bc      4, 2, _8005ee58
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129ED0@ha
    addi	r3, r24, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129ED0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
_8005ee58:
    lbz	r0, 0x1f(r31)
    cmplwi	r0, 0
    bc      4, 2, _8005ee88
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_801299D0@ha
    addi	r3, r24, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_801299D0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ef60
_8005ee88:
    cmplwi	r0, 1
    bc      4, 2, _8005eeb4
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129AD0@ha
    addi	r3, r24, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129AD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ef60
_8005eeb4:
    cmplwi	r0, 2
    bc      4, 2, _8005eee0
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129BD0@ha
    addi	r3, r24, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129BD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ef60
_8005eee0:
    cmplwi	r0, 3
    bc      4, 2, _8005ef0c
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129CD0@ha
    addi	r3, r24, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129CD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ef60
_8005ef0c:
    cmplwi	r0, 4
    bc      4, 2, _8005ef38
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129DD0@ha
    addi	r3, r24, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129DD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005ef60
_8005ef38:
    cmplwi	r0, 5
    bc      4, 2, _8005ef60
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129ED0@ha
    addi	r3, r24, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129ED0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
_8005ef60:
    lbz	r3, 0xd(r15)
    extsb.	r0, r3
    bc      4, 1, _8005efa8
    extsb	r4, r3
    lwz	r3, -0x7740(r13)
    addi	r4, r4, 1
    lhz	r0, 0x28(r31)
    mulli	r4, r4, 0x4b0
    add	r3, r3, r20
    lbz	r3, 0x59b(r3)
    srawi	r4, r4, 7
    mullw	r4, r4, r3
    srawi	r4, r4, 7
    add	r4, r4, r0
    cmpwi	r4, 0x4b0
    bc      4, 1, _8005f014
    li	r4, 0x4b0
    b       _8005f014
_8005efa8:
    extsb.	r0, r3
    bc      4, 0, _8005f010
    extsb	r0, r3
    lis	r4, 0x4330
    xoris	r3, r0, 0x8000
    lwz	r0, -0x7740(r13)
    stw	r3, 0xd4(r1)
    add	r3, r0, r20
    lfd	f1, -0x7c28(r2)
    stw	r4, 0xd0(r1)
    lbz	r3, 0x59b(r3)
    lfd	f0, 0xd0(r1)
    lhz	r0, 0x28(r31)
    fsub	f0, f0, f1
    fabs	f0, f0
    fctiwz	f0, f0
    stfd	f0, 0xc8(r1)
    lwz	r4, 0xcc(r1)
    mulli	r4, r4, 0x4b0
    srawi	r4, r4, 7
    mullw	r4, r4, r3
    srawi	r3, r4, 7
    subf.	r4, r3, r0
    bc      4, 0, _8005f014
    li	r4, 0
    b       _8005f014
_8005f010:
    lhz	r4, 0x28(r31)
_8005f014:
    lwz	r0, -0x7740(r13)
    slwi	r14, r4, 0x10
    add	r3, r0, r24
    stw	r14, 0x14f0(r3)
    lbz	r3, 0xf(r15)
    extsb.	r0, r3
    bc      4, 1, _8005f06c
    extsb	r3, r3
    lwz	r0, -0x7740(r13)
    addi	r4, r3, 1
    lhz	r3, 0x2a(r31)
    mulli	r5, r4, 0x78
    add	r4, r0, r20
    lbz	r0, 0x59b(r4)
    srawi	r5, r5, 7
    mullw	r5, r5, r0
    srawi	r0, r5, 7
    add	r15, r3, r0
    cmpwi	r15, 0x78
    bc      4, 1, _8005f0d8
    li	r15, 0x78
    b       _8005f0d8
_8005f06c:
    extsb.	r0, r3
    bc      4, 0, _8005f0d4
    extsb	r0, r3
    lis	r4, 0x4330
    xoris	r3, r0, 0x8000
    lwz	r0, -0x7740(r13)
    stw	r3, 0xd4(r1)
    add	r3, r0, r20
    lfd	f1, -0x7c28(r2)
    stw	r4, 0xd0(r1)
    lbz	r3, 0x59b(r3)
    lfd	f0, 0xd0(r1)
    lhz	r0, 0x2a(r31)
    fsub	f0, f0, f1
    fabs	f0, f0
    fctiwz	f0, f0
    stfd	f0, 0xc8(r1)
    lwz	r4, 0xcc(r1)
    mulli	r4, r4, 0x78
    srawi	r4, r4, 7
    mullw	r4, r4, r3
    srawi	r3, r4, 7
    subf.	r15, r3, r0
    bc      4, 0, _8005f0d8
    li	r15, 0
    b       _8005f0d8
_8005f0d4:
    lhz	r15, 0x2a(r31)
_8005f0d8:
    lwz	r3, -0x7740(r13)
    subf	r0, r15, r28
    slwi	r22, r15, 0x10
    add	r3, r3, r24
    slwi	r4, r0, 0x10
    stw	r22, 0x151c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r28, 0x141c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r4, 0x148c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stb	r27, 0x1498(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    lwz	r0, 0xe4(r1)
    stb	r0, 0x1499(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r29, 0x1480(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    lwz	r0, 0xd8(r1)
    stw	r0, 0x14a4(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r26, 0x14b0(r3)
    lha	r3, 0xc(r31)
    extsh.	r0, r3
    bc      12, 2, _8005f18c
    lwz	r0, -0x7740(r13)
    slwi	r6, r3, 0x10
    li	r5, 0
    lis	r4, -0x3c0
    add	r3, r0, r24
    stw	r6, 0x14bc(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r5, 0x14c0(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r4, 0x14c4(r3)
    b       _8005f1b4
_8005f18c:
    lwz	r0, -0x7740(r13)
    li	r4, 0
    add	r3, r0, r24
    stw	r4, 0x14bc(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r4, 0x14c0(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stw	r4, 0x14c4(r3)
_8005f1b4:
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x1478
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x1484
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x149c
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14a8
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14b4
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x1490
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14c8
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14f4
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    addi	r3, r24, 0x1438
    add	r3, r0, r3
    bl      fn_80028164
    clrlwi.	r21, r19, 0x1f
    bc      12, 2, _8005f280
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80026E04
    b       _8005f290
_8005f280:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80026DD4
_8005f290:
    rlwinm.	r20, r19, 0, 0x1e, 0x1e
    bc      12, 2, _8005f2ac
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80026E84
    b       _8005f2bc
_8005f2ac:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80026E54
_8005f2bc:
    lwz	r3, -0x7740(r13)
    lha	r19, 0xe0(r1)
    add	r3, r3, r24
    lwz	r3, 0x1434(r3)
    mr	r4, r19
    bl      fn_80026FB8
    lbz	r0, 0x3b(r17)
    cmplwi	r0, 1
    bc      4, 2, _8005fa70
    mr	r3, r23
    bl      SndSwapVoice
    mr	r25, r3
    cmpwi	r25, -1
    bc      12, 2, _8005fa68
    lwz	r3, -0x7740(r13)
    mulli	r23, r25, 0x118
    addi	r3, r3, 0x1408
    lbzx	r0, r3, r24
    stbx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x1420
    lwzx	r0, r3, r24
    stwx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x140a
    lbzx	r0, r3, r24
    stbx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x1424
    lwzx	r0, r3, r24
    stwx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x1428
    lwzx	r0, r3, r24
    stwx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x140b
    lbzx	r0, r3, r24
    stbx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x140c
    lbzx	r0, r3, r24
    stbx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x1410
    lbzx	r0, r3, r24
    stbx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x140d
    lbzx	r0, r3, r24
    stbx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x1416
    lhzx	r0, r3, r24
    sthx	r0, r3, r23
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x1418
    lwzx	r0, r3, r24
    stwx	r0, r3, r23
    lwz	r5, -0x7740(r13)
    lbz	r0, 0x462(r5)
    cmplwi	r0, 0
    bc      12, 2, _8005f3c0
    extsh	r28, r18
    li	r27, 0x7c
_8005f3c0:
    add	r4, r5, r23
    addi	r3, r23, 0x1438
    lwz	r4, 0x1434(r4)
    add	r3, r5, r3
    li	r5, 0x7d00
    bl      fn_80028130
    lbz	r0, 0x3a(r17)
    clrlwi.	r0, r0, 0x1e
    bc      4, 2, _8005f3f0
    li	r0, 0xa
    sth	r0, 0x1a(r1)
    b       _8005f40c
_8005f3f0:
    cmpwi	r0, 1
    bc      4, 2, _8005f404
    li	r0, 0x19
    sth	r0, 0x1a(r1)
    b       _8005f40c
_8005f404:
    li	r0, 0
    sth	r0, 0x1a(r1)
_8005f40c:
    lwz	r3, -0x7740(r13)
    clrlwi	r0, r16, 0x18
    lwz	r6, 0x40(r17)
    cmplwi	r0, 4
    lbz	r4, 0x45b(r3)
    lwz	r5, 0(r17)
    slwi	r4, r4, 4
    add	r4, r3, r4
    lwz	r4, 4(r4)
    add	r18, r4, r6
    add	r18, r5, r18
    bc      12, 2, _8005f444
    divwu	r18, r18, r0
    b       _8005f448
_8005f444:
    slwi	r18, r18, 1
_8005f448:
    lbz	r0, 0x3a(r17)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    bc      12, 2, _8005f4a0
    clrlwi	r0, r16, 0x18
    li	r4, 1
    cmplwi	r0, 4
    sth	r4, 0x18(r1)
    bc      12, 2, _8005f47c
    lwz	r4, 4(r17)
    lwz	r0, 8(r17)
    add	r17, r18, r4
    add	r16, r18, r0
    b       _8005f48c
_8005f47c:
    lwz	r4, 4(r17)
    lwz	r0, 8(r17)
    add	r17, r18, r4
    add	r16, r18, r0
_8005f48c:
    add	r3, r3, r23
    addi	r4, r1, 0x10
    lwz	r3, 0x1434(r3)
    bl      fn_80023568
    b       _8005f4d8
_8005f4a0:
    clrlwi	r4, r16, 0x18
    li	r0, 0
    cmplwi	r4, 4
    sth	r0, 0x18(r1)
    bc      12, 2, _8005f4c8
    lwz	r3, 0x1a4(r3)
    lwz	r0, 8(r17)
    divwu	r17, r3, r4
    add	r16, r18, r0
    b       _8005f4d8
_8005f4c8:
    lwz	r3, 0x1a4(r3)
    lwz	r0, 8(r17)
    slwi	r17, r3, 1
    add	r16, r18, r0
_8005f4d8:
    srwi	r6, r17, 0x10
    srwi	r5, r16, 0x10
    srwi	r4, r18, 0x10
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x1490
    sth	r6, 0x1c(r1)
    add	r3, r0, r3
    sth	r17, 0x1e(r1)
    sth	r5, 0x20(r1)
    sth	r16, 0x22(r1)
    sth	r4, 0x24(r1)
    sth	r18, 0x26(r1)
    bl      fn_800284CC
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x1478
    add	r3, r0, r3
    bl      fn_800284E8
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x1484
    add	r3, r0, r3
    bl      fn_80028540
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x149c
    add	r3, r0, r3
    bl      fn_80028554
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x14a8
    add	r3, r0, r3
    bl      fn_80028568
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x14b4
    add	r3, r0, r3
    bl      fn_8002857C
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x14c8
    add	r3, r0, r3
    bl      fn_800284FC
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x14f4
    add	r3, r0, r3
    bl      fn_80028598
    lbz	r0, 0x1e(r31)
    cmplwi	r0, 0
    bc      4, 2, _8005f5ac
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_801299D0@ha
    addi	r3, r23, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_801299D0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f684
_8005f5ac:
    cmplwi	r0, 1
    bc      4, 2, _8005f5d8
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129AD0@ha
    addi	r3, r23, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129AD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f684
_8005f5d8:
    cmplwi	r0, 2
    bc      4, 2, _8005f604
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129BD0@ha
    addi	r3, r23, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129BD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f684
_8005f604:
    cmplwi	r0, 3
    bc      4, 2, _8005f630
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129CD0@ha
    addi	r3, r23, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129CD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f684
_8005f630:
    cmplwi	r0, 4
    bc      4, 2, _8005f65c
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129DD0@ha
    addi	r3, r23, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129DD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f684
_8005f65c:
    cmplwi	r0, 5
    bc      4, 2, _8005f684
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129ED0@ha
    addi	r3, r23, 0x14d0
    lfs	f1, 0x20(r31)
    addi	r4, r4, lbl_80129ED0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
_8005f684:
    lbz	r0, 0x1f(r31)
    cmplwi	r0, 0
    bc      4, 2, _8005f6b4
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_801299D0@ha
    addi	r3, r23, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_801299D0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f78c
_8005f6b4:
    cmplwi	r0, 1
    bc      4, 2, _8005f6e0
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129AD0@ha
    addi	r3, r23, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129AD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f78c
_8005f6e0:
    cmplwi	r0, 2
    bc      4, 2, _8005f70c
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129BD0@ha
    addi	r3, r23, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129BD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f78c
_8005f70c:
    cmplwi	r0, 3
    bc      4, 2, _8005f738
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129CD0@ha
    addi	r3, r23, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129CD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f78c
_8005f738:
    cmplwi	r0, 4
    bc      4, 2, _8005f764
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129DD0@ha
    addi	r3, r23, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129DD0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
    b       _8005f78c
_8005f764:
    cmplwi	r0, 5
    bc      4, 2, _8005f78c
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80129ED0@ha
    addi	r3, r23, 0x14fc
    lfs	f1, 0x24(r31)
    addi	r4, r4, lbl_80129ED0@l
    li	r5, 0x40
    add	r3, r0, r3
    bl      fn_800284A0
_8005f78c:
    lwz	r3, -0x7740(r13)
    subf	r0, r15, r28
    slwi	r5, r0, 0x10
    slwi	r4, r28, 0x10
    add	r3, r3, r23
    stw	r14, 0x14f0(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r22, 0x151c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r28, 0x141c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r5, 0x148c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r4, 0x148c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stb	r27, 0x1498(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    lwz	r0, 0xe4(r1)
    stb	r0, 0x1499(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r29, 0x1480(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    lwz	r0, 0xd8(r1)
    stw	r0, 0x14a4(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r26, 0x14b0(r3)
    lha	r3, 0xc(r31)
    extsh.	r0, r3
    bc      12, 2, _8005f858
    lwz	r0, -0x7740(r13)
    slwi	r6, r3, 0x10
    li	r5, 0
    lis	r4, -0x3c0
    add	r3, r0, r23
    stw	r6, 0x14bc(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r5, 0x14c0(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r4, 0x14c4(r3)
    b       _8005f880
_8005f858:
    lwz	r0, -0x7740(r13)
    li	r4, 0
    add	r3, r0, r23
    stw	r4, 0x14bc(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r4, 0x14c0(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stw	r4, 0x14c4(r3)
_8005f880:
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x1478
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x1484
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x149c
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14a8
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14b4
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x1490
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14c8
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    addi	r3, r4, 0x1438
    addi	r4, r4, 0x14f4
    bl      fn_800288B4
    lwz	r0, -0x7740(r13)
    addi	r3, r23, 0x1438
    add	r3, r0, r3
    bl      fn_80028164
    cmplwi	r21, 0
    bc      12, 2, _8005f94c
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80026E04
    b       _8005f95c
_8005f94c:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80026DD4
_8005f95c:
    cmplwi	r20, 0
    bc      12, 2, _8005f978
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80026E84
    b       _8005f988
_8005f978:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80026E54
_8005f988:
    lwz	r0, -0x7740(r13)
    mr	r4, r19
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80026FB8
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x18
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80023284
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x38
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80023394
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_800230A4
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r23
    lwz	r3, 0x1434(r3)
    bl      fn_80023168
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r23
    stb	r4, 0x1409(r3)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    lbz	r3, 0x1410(r4)
    cmplwi	r3, 2
    bc      12, 0, _8005fa34
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      4, 2, _8005fa34
    addi	r0, r3, -1
    stb	r0, 0x1410(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r23
    lwz	r3, 0x1434(r4)
    lbz	r4, 0x1410(r4)
    bl      AXSetVoicePriority
_8005fa34:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stb	r30, 0x1411(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stb	r25, 0x1412(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stb	r30, 0x1411(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r23
    stb	r25, 0x1412(r3)
    b       _8005fa70
_8005fa68:
    li	r0, 0
    stw	r0, 0xdc(r1)
_8005fa70:
    lwz	r0, 0xdc(r1)
    cmplwi	r0, 0
    bc      12, 2, _8005fadc
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80023168
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r24
    stb	r4, 0x1409(r3)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    lbz	r3, 0x1410(r4)
    cmplwi	r3, 2
    bc      12, 0, _8005fbb8
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      4, 2, _8005fbb8
    addi	r0, r3, -1
    stb	r0, 0x1410(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    lwz	r3, 0x1434(r4)
    lbz	r4, 0x1410(r4)
    bl      AXSetVoicePriority
    b       _8005fbb8
_8005fadc:
    clrlwi	r15, r30, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r14, r15, 0x118
    add	r3, r0, r14
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _8005fbb8
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r0, -0x7740(r13)
    add	r3, r0, r14
    lwz	r3, 0x1434(r3)
    bl      fn_80026D70
    lwz	r0, -0x7740(r13)
    add	r3, r0, r14
    lwz	r3, 0x1434(r3)
    bl      AXFreeVoice
    lwz	r0, -0x7740(r13)
    li	r4, 0
    add	r3, r0, r14
    stw	r4, 0x1434(r3)
    lwz	r4, -0x7740(r13)
    add	r3, r4, r14
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005fb54
    mr	r3, r15
    bl      SndClearVoiceSlot
    b       _8005fb60
_8005fb54:
    addi	r3, r14, 0x1438
    add	r3, r4, r3
    bl      fn_80028424
_8005fb60:
    lwz	r0, -0x7740(r13)
    li	r5, 0xff
    li	r4, 0
    add	r3, r0, r14
    stb	r5, 0x1408(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r14
    stw	r4, 0x1420(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r14
    stb	r4, 0x1409(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r14
    lbz	r0, 0x1411(r3)
    cmplw	r0, r15
    bc      4, 2, _8005fba8
    stb	r5, 0x1411(r3)
    b       _8005fbb8
_8005fba8:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r15
    bc      4, 2, _8005fbb8
    stb	r5, 0x1412(r3)
_8005fbb8:
    psq_l	f31, 0x148(r1), 0, 0
    lfd	f31, 0x140(r1)
    psq_l	f30, 0x138(r1), 0, 0
    lfd	f30, 0x130(r1)
    lmw	r14, 0xe8(r1)
    lwz	r0, 0x154(r1)
    mtlr	r0
    addi	r1, r1, 0x150
    blr
}

asm void SndSetVoicePriority(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    mulli	r6, r3, 0x118
    stw	r0, 0x14(r1)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r6
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _8005fcc8
    li	r0, 2
    stb	r0, 0x1409(r3)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r6
    lbz	r0, 0x1408(r4)
    cmplwi	r0, 3
    bc      4, 2, _8005fc4c
    lhz	r0, 0x1416(r4)
    li	r3, -0x3c0
    divw	r0, r3, r0
    stw	r0, 0x1418(r4)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r6
    lwz	r0, 0x1418(r3)
    cmpwi	r0, 0
    bc      4, 2, _8005fc90
    li	r0, -1
    stw	r0, 0x1418(r3)
    b       _8005fc90
_8005fc4c:
    lwz	r3, 0x1424(r4)
    lha	r3, 0x12(r3)
    extsh.	r0, r3
    bc      12, 2, _8005fc68
    slwi	r0, r3, 0x10
    stw	r0, 0x14bc(r4)
    b       _8005fc70
_8005fc68:
    lis	r0, -0x3c0
    stw	r0, 0x14bc(r4)
_8005fc70:
    lwz	r0, -0x7740(r13)
    lis	r5, -0x3c0
    li	r4, 2
    add	r3, r0, r6
    stw	r5, 0x14c0(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r6
    sth	r4, 0x1416(r3)
_8005fc90:
    lwz	r0, -0x7740(r13)
    add	r4, r0, r6
    lbz	r3, 0x1410(r4)
    cmplwi	r3, 2
    bc      12, 0, _8005fcc8
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      4, 2, _8005fcc8
    addi	r0, r3, -1
    stb	r0, 0x1410(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r6
    lwz	r3, 0x1434(r4)
    lbz	r4, 0x1410(r4)
    bl      AXSetVoicePriority
_8005fcc8:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void SndKillChannelVoice(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    mulli	r31, r30, 0x118
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _8005fdc8
    lwz	r3, 0x1434(r3)
    li	r4, 0
    bl      fn_80023168
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lwz	r3, 0x1434(r3)
    bl      fn_80026D70
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lwz	r3, 0x1434(r3)
    bl      AXFreeVoice
    lwz	r0, -0x7740(r13)
    li	r4, 0
    add	r3, r0, r31
    stw	r4, 0x1434(r3)
    lwz	r4, -0x7740(r13)
    add	r3, r4, r31
    lbz	r0, 0x1408(r3)
    cmplwi	r0, 3
    bc      4, 2, _8005fd64
    mr	r3, r30
    bl      SndClearVoiceSlot
    b       _8005fd70
_8005fd64:
    addi	r3, r31, 0x1438
    add	r3, r4, r3
    bl      fn_80028424
_8005fd70:
    lwz	r0, -0x7740(r13)
    li	r5, 0xff
    li	r4, 0
    add	r3, r0, r31
    stb	r5, 0x1408(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stw	r4, 0x1420(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stb	r4, 0x1409(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lbz	r0, 0x1411(r3)
    cmplw	r0, r30
    bc      4, 2, _8005fdb8
    stb	r5, 0x1411(r3)
    b       _8005fdc8
_8005fdb8:
    lbz	r0, 0x1412(r3)
    cmplw	r0, r30
    bc      4, 2, _8005fdc8
    stb	r5, 0x1412(r3)
_8005fdc8:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void SndDispatchCommand(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    srwi	r4, r29, 0x18
    lwz	r3, -0x7740(r13)
    andis.	r6, r29, 0xff70
    cmplwi	r4, 0x80
    rlwinm	r5, r29, 0x10, 0x19, 0x1f
    stw	r29, 0x444(r3)
    rlwinm	r7, r29, 0x18, 0x18, 0x1f
    clrlwi	r3, r29, 0x1c
    bc      12, 0, _800605f0
    rlwinm	r0, r4, 0, 0x18, 0x1b
    cmpwi	r0, 0xb0
    bc      12, 2, _800602cc
    bc      4, 0, _8005fe54
    cmpwi	r0, 0x90
    bc      12, 2, _8005fe84
    bc      4, 0, _8005fe48
    cmpwi	r0, 0x80
    bc      12, 2, _8005fe6c
    b       _800605f0
_8005fe48:
    cmpwi	r0, 0xa0
    bc      12, 2, _8005feb4
    b       _800605f0
_8005fe54:
    cmpwi	r0, 0xe0
    bc      12, 2, _800605d0
    bc      4, 0, _800605f0
    cmpwi	r0, 0xc0
    bc      12, 2, _800604b4
    b       _800605f0
_8005fe6c:
    lis	r3, 1
    lis	r4, 0xf7f
    addi	r3, r3, -0x8000
    addi	r4, r4, 0xff
    bl      SndUpdateVoices
    b       _800605f0
_8005fe84:
    cmplwi	r7, 0
    bc      12, 2, _8005fe9c
    lis	r3, 1
    addi	r3, r3, -0x7000
    bl      SndTickChannels
    b       _800605f0
_8005fe9c:
    lis	r3, 1
    lis	r4, 0xf7f
    addi	r3, r3, -0x8000
    addi	r4, r4, 0xff
    bl      SndUpdateVoices
    b       _800605f0
_8005feb4:
    clrlwi	r0, r4, 0x1c
    cmpwi	r0, 4
    bc      12, 2, _8006027c
    bc      4, 0, _8005fed0
    cmpwi	r0, 0
    bc      12, 2, _8005fee4
    b       _800605f0
_8005fed0:
    cmpwi	r0, 0xe
    bc      4, 0, _800605f0
    cmpwi	r0, 8
    bc      4, 0, _800602c4
    b       _800602bc
_8005fee4:
    cmplwi	r5, 0x40
    bc      12, 1, _800605f0
    lis     r4, -0x7fed
    slwi	r0, r5, 2
    addi	r4, r4, 0x2680
    lwzx	r0, r4, r0
    mtctr	r0
    bctr
    cmplwi	r7, 0x29
    bc      12, 1, _800605f0
    lis     r3, -0x7fed
    slwi	r0, r7, 2
    addi	r3, r3, 0x25d8
    lwzx	r0, r3, r0
    mtctr	r0
    bctr
    lis	r3, -0x6000
    addi	r3, r3, 0x100
    bl      SndStopAllChannelVoices
    bl      fn_800622B0
    b       _800605f0
    lis	r3, -0x6000
    addi	r3, r3, 0x200
    bl      SndStopAllChannelVoices
    b       _800605f0
    lis	r3, -0x6000
    addi	r3, r3, 0x300
    bl      SndStopAllChannelVoices
    b       _800605f0
    bl      fn_800622B0
    b       _800605f0
    lwz	r3, -0x7740(r13)
    li	r0, 1
    stb	r0, 0x462(r3)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x463(r3)
    bl      fn_80021928
    cmplwi	r3, 0
    bc      12, 2, _8005ff88
    li	r3, 0
    bl      fn_80021914
_8005ff88:
    bl      fn_80025EEC
    cmplwi	r3, 1
    bc      12, 2, _800605f0
    li	r3, 1
    bl      fn_80025EE4
    b       _800605f0
    lwz	r3, -0x7740(r13)
    li	r0, 0
    stb	r0, 0x462(r3)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x463(r3)
    bl      fn_80021928
    cmplwi	r3, 0
    bc      12, 2, _8005ffc8
    li	r3, 0
    bl      fn_80021914
_8005ffc8:
    bl      fn_80025EEC
    cmplwi	r3, 1
    bc      12, 2, _800605f0
    li	r3, 1
    bl      fn_80025EE4
    b       _800605f0
    lis	r3, -0x6000
    addi	r3, r3, 0x1100
    bl      SndStopAllChannelVoices
    b       _800605f0
    lis	r3, -0x6000
    addi	r3, r3, 0x1200
    bl      SndStopAllChannelVoices
    b       _800605f0
    lis	r3, -0x6000
    addi	r3, r3, 0x1300
    bl      SndStopAllChannelVoices
    b       _800605f0
    rlwinm.	r0, r29, 0, 0x19, 0x19
    bc      4, 2, _800605f0
    mr	r3, r29
    bl      SndAllocBankEntry
    b       _800605f0
    lwz	r3, -0x7740(r13)
    li	r4, 1
    li	r0, 2
    stb	r4, 0x462(r3)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x463(r3)
    bl      fn_80021928
    cmplwi	r3, 1
    bc      12, 2, _80060050
    li	r3, 1
    bl      fn_80021914
_80060050:
    bl      fn_80025EEC
    cmplwi	r3, 2
    bc      12, 2, _800605f0
    li	r3, 2
    bl      fn_80025EE4
    b       _800605f0
    lwz	r3, -0x7740(r13)
    li	r4, 1
    li	r0, 3
    stb	r4, 0x462(r3)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x463(r3)
    bl      fn_80021928
    cmplwi	r3, 2
    bc      12, 2, _80060094
    li	r3, 2
    bl      fn_80021914
_80060094:
    bl      fn_80025EEC
    cmplwi	r3, 3
    bc      12, 2, _800605f0
    li	r3, 3
    bl      fn_80025EE4
    b       _800605f0
    lwz	r5, -0x7740(r13)
    lis	r3, 1
    addi	r3, r3, -0x5fff
    li	r4, 0
    stb	r7, 0x461(r5)
    bl      SndUpdateVoices
    b       _800605f0
    lis	r3, 1
    addi	r3, r3, -0x5ffe
    bl      SndRefreshChannelVoices
    rlwinm.	r0, r29, 0, 0x19, 0x19
    bc      4, 2, _800605f0
    mr	r3, r29
    bl      SndAllocBankEntry
    b       _800605f0
    bl      fn_80069AE0
    b       _800605f0
    addis	r29, r5, 1
    lis	r4, 1
    addi	r29, r29, -0x6000
    clrlwi	r3, r29, 0x10
    addi	r4, r4, -0x5ffc
    bl      fn_80064230
    lis	r3, 1
    addi	r3, r3, -0x5ffc
    bl      fn_800641A8
    clrlwi	r3, r29, 0x10
    bl      SndRefreshChannelVoices
    b       _800605f0
    lis	r3, 1
    addi	r3, r3, -0x5ff9
    bl      fn_800641A8
    lis	r3, 1
    addi	r3, r3, -0x5ff9
    bl      SndRefreshChannelVoices
    b       _800605f0
    bl      fn_80069AE0
    b       _800605f0
    bl      fn_80069AE0
    b       _800605f0
    li	r3, 0
    bl      fn_80065528
    b       _800605f0
    lis     r5, lbl_80092AB8@ha
    lis	r4, 1
    addi	r6, r5, lbl_80092AB8@l
    lwz	r5, -0x7740(r13)
    rlwinm	r0, r3, 4, 0x14, 0x1b
    lbzx	r6, r6, r7
    add	r5, r5, r0
    addi	r3, r4, -0x5fe4
    stb	r6, 0x491(r5)
    li	r4, 0xf
    bl      SndUpdateVoices
    b       _800605f0
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b18(r4)
    cmplwi	r12, 0
    bc      12, 2, _800605f0
    mr	r4, r7
    mtctr	r12
    bctrl
    b       _800605f0
    rlwinm	r0, r7, 2, 0x16, 0x1d
    rlwinm	r3, r3, 6, 0x12, 0x19
    subfic	r5, r5, 0x29
    li	r7, 0
    add	r4, r3, r0
    b       _800601ec
_800601c0:
    lwz	r6, -0x7740(r13)
    clrlwi	r0, r7, 0x18
    add	r3, r6, r0
    addi	r0, r3, 0xd88
    lbzx	r0, r4, r0
    cmplwi	r0, 0xff
    bc      12, 2, _800601e8
    rlwinm	r3, r0, 5, 0x13, 0x1a
    addi	r0, r3, 0x58a
    stbx	r5, r6, r0
_800601e8:
    addi	r7, r7, 1
_800601ec:
    clrlwi	r0, r7, 0x18
    cmplwi	r0, 4
    bc      12, 0, _800601c0
    b       _800605f0
    lwz	r3, -0x7740(r13)
    stb	r7, 0x45e(r3)
    b       _800605f0
    lwz	r5, -0x7740(r13)
    lis	r3, 1
    addi	r3, r3, -0x5fff
    li	r4, 0
    lha	r0, 0x5a12(r5)
    sth	r0, 0x5a10(r5)
    bl      SndUpdateVoices
    b       _800605f0
    lis	r3, 1
    addi	r3, r3, -0x5fcc
    mr	r4, r3
    bl      fn_80064230
    lis	r3, 1
    addi	r3, r3, -0x5fcc
    bl      SndRefreshChannelVoices
    b       _800605f0
    bl      fn_80065390
    b       _800605f0
    li	r3, 1
    bl      fn_80065528
    b       _800605f0
    lis	r4, 1
    addi	r3, r4, -0x5fc0
    addi	r4, r4, -0x5fcc
    bl      fn_80064230
    lis	r3, 1
    addi	r3, r3, -0x5fc0
    bl      SndRefreshChannelVoices
    b       _800605f0
_8006027c:
    lis	r0, -0x5b90
    cmpw	r6, r0
    bc      12, 2, _800602b0
    bc      4, 0, _800605f0
    lis	r0, -0x5c00
    cmpw	r6, r0
    bc      12, 2, _8006029c
    b       _800605f0
_8006029c:
    lwz	r3, -0x7740(r13)
    mr	r4, r7
    lbz	r3, 0x474(r3)
    bl      fn_8006331C
    b       _800605f0
_800602b0:
    lwz	r3, -0x7740(r13)
    stb	r7, 0x474(r3)
    b       _800605f0
_800602bc:
    bl      SndPlaySequenceNotes
    b       _800605f0
_800602c4:
    bl      fn_80069AE0
    b       _800605f0
_800602cc:
    cmpwi	r5, 0x27
    bc      12, 2, _8006043c
    bc      4, 0, _80060324
    cmpwi	r5, 0xa
    bc      12, 2, _800603d0
    bc      4, 0, _80060308
    cmpwi	r5, 3
    bc      4, 0, _800602fc
    cmpwi	r5, 0
    bc      12, 2, _80060378
    bc      4, 0, _80060388
    b       _800605f0
_800602fc:
    cmpwi	r5, 7
    bc      12, 2, _800603ac
    b       _800605f0
_80060308:
    cmpwi	r5, 0xd
    bc      12, 2, _800603f4
    bc      4, 0, _80060318
    b       _800605f0
_80060318:
    cmpwi	r5, 0xf
    bc      4, 0, _800605f0
    b       _80060418
_80060324:
    cmpwi	r5, 0x2e
    bc      12, 2, _8006046c
    bc      4, 0, _80060354
    cmpwi	r5, 0x2b
    bc      12, 2, _800605f0
    bc      4, 0, _80060348
    cmpwi	r5, 0x2a
    bc      4, 0, _8006044c
    b       _800605f0
_80060348:
    cmpwi	r5, 0x2d
    bc      4, 0, _8006045c
    b       _800605f0
_80060354:
    cmpwi	r5, 0x41
    bc      12, 2, _800605f0
    bc      4, 0, _8006036c
    cmpwi	r5, 0x40
    bc      4, 0, _8006047c
    b       _800605f0
_8006036c:
    cmpwi	r5, 0x78
    bc      12, 2, _800604a0
    b       _800605f0
_80060378:
    lis	r3, 1
    addi	r3, r3, -0x5000
    bl      SndTickChannels
    b       _800605f0
_80060388:
    addis	r29, r5, 1
    addi	r29, r29, -0x5000
    clrlwi	r3, r29, 0x10
    bl      SndTickChannels
    lis	r4, 0xf00
    clrlwi	r3, r29, 0x10
    addi	r4, r4, 0xf
    bl      SndUpdateVoices
    b       _800605f0
_800603ac:
    lis	r3, 1
    addi	r3, r3, -0x4ff9
    bl      SndTickChannels
    lis	r3, 1
    lis	r4, 0xf00
    addi	r3, r3, -0x4ff9
    addi	r4, r4, 0xf
    bl      SndUpdateVoices
    b       _800605f0
_800603d0:
    lis	r3, 1
    addi	r3, r3, -0x4ff6
    bl      SndTickChannels
    lis	r3, 1
    lis	r4, 0xf00
    addi	r3, r3, -0x4ff6
    addi	r4, r4, 0xf
    bl      SndUpdateVoices
    b       _800605f0
_800603f4:
    lis	r3, 1
    addi	r3, r3, -0x4ff3
    bl      SndTickChannels
    lis	r3, 1
    lis	r4, 0xf00
    addi	r3, r3, -0x4ff3
    addi	r4, r4, 0xf
    bl      SndUpdateVoices
    b       _800605f0
_80060418:
    lis	r3, 1
    addi	r3, r3, -0x4ff2
    bl      SndTickChannels
    lis	r3, 1
    lis	r4, 0xf00
    addi	r3, r3, -0x4ff3
    addi	r4, r4, 0xf
    bl      SndUpdateVoices
    b       _800605f0
_8006043c:
    lis	r3, 1
    addi	r3, r3, -0x4ff9
    bl      SndTickChannels
    b       _800605f0
_8006044c:
    lis	r3, 1
    addi	r3, r3, -0x4ff6
    bl      SndTickChannels
    b       _800605f0
_8006045c:
    lis	r3, 1
    addi	r3, r3, -0x4ff3
    bl      SndTickChannels
    b       _800605f0
_8006046c:
    lis	r3, 1
    addi	r3, r3, -0x4ff2
    bl      SndTickChannels
    b       _800605f0
_8006047c:
    lis	r3, 1
    addi	r3, r3, -0x4fc0
    bl      SndTickChannels
    lis	r3, 1
    lis	r4, 0xf00
    addi	r3, r3, -0x4fc0
    addi	r4, r4, 0xf
    bl      SndUpdateVoices
    b       _800605f0
_800604a0:
    lis	r3, 1
    li	r4, 0xf
    addi	r3, r3, -0x4f88
    bl      SndUpdateVoices
    b       _800605f0
_800604b4:
    lwz	r7, -0x7740(r13)
    lwz	r6, 0x444(r7)
    rlwinm	r30, r6, 6, 0x16, 0x19
    rlwinm	r4, r6, 4, 0x18, 0x1b
    add	r0, r7, r30
    rlwinm	r29, r6, 0xa, 0x1a, 0x1d
    add	r3, r0, r29
    add	r4, r7, r4
    lbz	r0, 0xd88(r3)
    clrlwi	r31, r6, 0x1c
    lwz	r4, 8(r4)
    cmpwi	r0, 0xff
    bc      12, 2, _800605f0
    rlwinm	r8, r0, 5, 0x13, 0x1a
    add	r3, r7, r8
    lbz	r0, 0x589(r3)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bc      4, 2, _800605f0
    lbz	r3, 0x58c(r3)
    li	r5, 0
    lwz	r0, 0x1c(r4)
    cmplwi	r3, 0
    add	r9, r4, r0
    mr	r4, r9
    bc      12, 0, _80060568
    addi	r0, r3, 1
    addi	r3, r3, -8
    clrlwi	r0, r0, 0x18
    cmplwi	r0, 8
    bc      4, 1, _80060548
    clrlwi	r0, r3, 0x18
    b       _8006053c
_80060534:
    addi	r4, r4, 0x10
    addi	r5, r5, 8
_8006053c:
    clrlwi	r3, r5, 0x18
    cmplw	r3, r0
    bc      4, 1, _80060534
_80060548:
    addi	r0, r8, 0x58c
    lbzx	r3, r7, r0
    b       _8006055c
_80060554:
    addi	r4, r4, 2
    addi	r5, r5, 1
_8006055c:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r3
    bc      4, 1, _80060554
_80060568:
    lhz	r3, 0(r4)
    rlwinm	r0, r6, 0x10, 0x19, 0x1f
    lhzx	r3, r9, r3
    srawi	r3, r3, 8
    cmplw	r3, r0
    bc      12, 0, _800605f0
    lis	r3, 1
    addi	r3, r3, -0x4000
    bl      SndTickChannels
    add	r29, r30, r29
    li	r30, 0
    b       _800605c0
_80060598:
    lwz	r3, -0x7740(r13)
    clrlwi	r0, r30, 0x18
    add	r3, r3, r0
    addi	r0, r3, 0xd88
    lbzx	r4, r29, r0
    cmpwi	r4, 0xff
    bc      12, 2, _800605bc
    mr	r3, r31
    bl      fn_80064E84
_800605bc:
    addi	r30, r30, 1
_800605c0:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 4
    bc      12, 0, _80060598
    b       _800605f0
_800605d0:
    lis	r3, 1
    addi	r3, r3, -0x2000
    bl      SndTickChannels
    lis	r3, 1
    lis	r4, 0xf00
    addi	r3, r3, -0x2000
    addi	r4, r4, 0xf
    bl      SndUpdateVoices
_800605f0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void SndBoostVoicePriority(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r4, lbl_80192D68@ha
    stw	r0, 0x34(r1)
    stmw	r23, 0xc(r1)
    mr	r29, r3
    addi	r31, r4, lbl_80192D68@l
    li	r30, 0
_8006062c:
    lbz	r0, 0(r31)
    cmplw	r29, r0
    bc      4, 2, _80060700
    lbz	r0, 1(r31)
    cmplwi	r0, 0
    bc      12, 2, _800606d0
    clrlwi	r0, r30, 0x18
    lis     r3, lbl_80192D68@ha
    mulli	r4, r0, 0x54
    lwz	r28, 0x10(r31)
    addi	r0, r3, lbl_80192D68@l
    addi	r25, r31, 0xc
    add	r26, r0, r4
    li	r27, 0
    b       _800606b4
_80060668:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r26, r0
    lbz	r0, 0x14(r24)
    addi	r23, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _800606a8
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80060690
    bl      SndSetVoicePriority
_80060690:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _800606a0
    bl      SndSetVoicePriority
_800606a0:
    li	r0, 0
    stb	r0, 0(r23)
_800606a8:
    lbz	r0, 0(r28)
    addi	r27, r27, 1
    add	r28, r28, r0
_800606b4:
    lbz	r0, 0(r25)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80060668
    li	r0, 0
    stb	r0, 0xb(r31)
    b       _800606f0
_800606d0:
    lwz	r3, -0x7740(r13)
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _800606f0
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
_800606f0:
    li	r3, 0xff
    li	r0, 0
    stb	r3, 0(r31)
    stb	r0, 1(r31)
_80060700:
    addi	r30, r30, 1
    addi	r31, r31, 0x54
    cmplwi	r30, 0x10
    bc      12, 0, _8006062c
    lmw	r23, 0xc(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_80060724(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stmw	r25, 0x24(r1)
    mr	r27, r8
    addi	r29, r3, 0xc
    mr	r25, r5
    mr	r26, r7
    li	r8, 0
    lbz	r28, 4(r3)
    lbz	r0, 1(r3)
    clrlwi	r3, r5, 0x18
    stw	r0, 0(r6)
    lbz	r0, 9(r29)
    lbz	r5, 8(r29)
    add	r7, r29, r0
    b       _80060784
_80060768:
    lbz	r6, 0(r7)
    cmplw	r3, r6
    bc      4, 1, _80060790
    addi	r0, r6, 1
    addi	r8, r8, 1
    clrlwi	r28, r0, 0x18
    addi	r7, r7, 4
_80060784:
    clrlwi	r0, r8, 0x18
    cmplw	r0, r5
    bc      12, 0, _80060768
_80060790:
    clrlwi	r0, r4, 0x18
    lis	r3, -0x7fe7
    clrlwi	r4, r28, 0x18
    clrlwi	r31, r25, 0x18
    mulli	r30, r0, 0x54
    lha	r6, 2(r7)
    subf	r5, r4, r31
    lbz	r4, 1(r7)
    addi	r0, r3, 0x2d68
    mullw	r5, r6, r5
    add	r3, r0, r30
    lbz	r3, 6(r3)
    addi	r0, r3, -0x40
    srawi	r3, r5, 8
    slwi	r0, r0, 1
    add	r3, r0, r3
    add	r3, r4, r3
    cmpwi	r3, 0x7f
    bc      4, 1, _800607e4
    li	r3, 0x7f
    b       _800607f0
_800607e4:
    cmpwi	r3, 0
    bc      4, 0, _800607f0
    li	r3, 0
_800607f0:
    cmpwi	r3, 0
    bc      12, 2, _80060844
    xoris	r3, r3, 0x8000
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lfd	f2, -0x7bb0(r2)
    stw	r0, 8(r1)
    lfs	f0, -0x7b98(r2)
    lfd	f1, 8(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7ba0(r2)
    lfd	f0, -0x7ba8(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    stw	r0, 0(r26)
    b       _8006084c
_80060844:
    li	r0, -0x388
    stw	r0, 0(r26)
_8006084c:
    lbz	r0, 0xb(r29)
    clrlwi	r3, r25, 0x18
    lbz	r4, 0xa(r29)
    li	r6, 0
    add	r7, r29, r0
    b       _80060880
_80060864:
    lbz	r5, 0(r7)
    cmplw	r3, r5
    bc      4, 1, _8006088c
    addi	r0, r5, 1
    addi	r6, r6, 1
    clrlwi	r28, r0, 0x18
    addi	r7, r7, 4
_80060880:
    clrlwi	r0, r6, 0x18
    cmplw	r0, r4
    bc      12, 0, _80060864
_8006088c:
    clrlwi	r0, r28, 0x18
    lha	r4, 2(r7)
    subf	r0, r0, r31
    lis     r3, lbl_80192D68@ha
    mullw	r5, r4, r0
    lbz	r4, 1(r7)
    addi	r0, r3, lbl_80192D68@l
    add	r3, r0, r30
    lbz	r3, 7(r3)
    srawi	r5, r5, 8
    addi	r0, r3, -0x40
    slwi	r0, r0, 1
    add	r5, r0, r5
    add	r5, r4, r5
    cmpwi	r5, 0x7f
    bc      4, 1, _800608d4
    li	r5, 0x7f
    b       _800608e0
_800608d4:
    cmpwi	r5, 0
    bc      4, 0, _800608e0
    li	r5, 0
_800608e0:
    cmpwi	r5, 0
    bc      12, 2, _80060934
    xoris	r3, r5, 0x8000
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f2, -0x7bb0(r2)
    stw	r0, 0x10(r1)
    lfs	f0, -0x7b98(r2)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f2, -0x7ba0(r2)
    lfd	f0, -0x7ba8(r2)
    fmul	f1, f2, f1
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 8(r1)
    lwz	r0, 0xc(r1)
    stw	r0, 0(r27)
    b       _8006093c
_80060934:
    li	r0, -0x388
    stw	r0, 0(r27)
_8006093c:
    lmw	r25, 0x24(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr
}

asm void SndCalcVoiceEnvelope(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stfd	f31, 0x40(r1)
    psq_st	f31, 0x48(r1), 0, 0
    stw	r31, 0x3c(r1)
    stw	r30, 0x38(r1)
    stw	r29, 0x34(r1)
    stw	r28, 0x30(r1)
    addi	r8, r3, 0xc
    lbz	r10, 4(r3)
    lbz	r0, 0xd(r3)
    mr	r28, r6
    lbz	r6, 0xc(r3)
    mr	r29, r7
    add	r8, r8, r0
    clrlwi	r3, r4, 0x18
    li	r9, 0
    b       _800609b8
_8006099c:
    lbz	r7, 0(r8)
    cmplw	r3, r7
    bc      4, 1, _800609c4
    addi	r0, r7, 1
    addi	r9, r9, 1
    clrlwi	r10, r0, 0x18
    addi	r8, r8, 4
_800609b8:
    clrlwi	r0, r9, 0x18
    cmplw	r0, r6
    bc      12, 0, _8006099c
_800609c4:
    clrlwi	r30, r5, 0x18
    lis     r3, lbl_80192D68@ha
    mulli	r31, r30, 0x54
    clrlwi	r5, r10, 0x18
    addi	r3, r3, lbl_80192D68@l
    lha	r6, 2(r8)
    clrlwi	r0, r4, 0x18
    lwz	r4, -0x7740(r13)
    lbzx	r3, r3, r31
    subf	r0, r5, r0
    mullw	r5, r6, r0
    lbz	r0, 1(r8)
    slwi	r3, r3, 4
    li	r6, 0
    add	r3, r4, r3
    lwz	r4, 8(r3)
    srawi	r5, r5, 8
    lwz	r3, 0x20(r4)
    addi	r4, r4, 0x84
    add	r4, r3, r4
    add	r5, r5, r0
    b       _80060a24
_80060a1c:
    addi	r4, r4, 1
    addi	r6, r6, 1
_80060a24:
    clrlwi	r0, r6, 0x18
    cmplw	r0, r5
    bc      12, 0, _80060a1c
    lbz	r3, 0(r4)
    cmplwi	r3, 0
    bc      12, 2, _80060a70
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lfd	f2, -0x7bb8(r2)
    stw	r0, 8(r1)
    lfs	f0, -0x7b94(r2)
    lfd	f1, 8(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7ba0(r2)
    fmul	f31, f0, f1
    frsp	f31, f31
    b       _80060a74
_80060a70:
    lfs	f31, -0x7b90(r2)
_80060a74:
    lis     r3, lbl_80192D68@ha
    addi	r0, r3, lbl_80192D68@l
    add	r3, r0, r31
    lbz	r3, 3(r3)
    cmplwi	r3, 0
    bc      12, 2, _80060ac4
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f2, -0x7bb8(r2)
    stw	r0, 0x10(r1)
    lfs	f0, -0x7b98(r2)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7ba0(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f31, f31, f0
    b       _80060ac8
_80060ac4:
    lfs	f31, -0x7b90(r2)
_80060ac8:
    lis     r3, lbl_80192D68@ha
    addi	r0, r3, lbl_80192D68@l
    add	r3, r0, r31
    lbz	r3, 0xe(r3)
    cmplwi	r3, 0
    bc      12, 2, _80060b18
    lis	r0, 0x4330
    stw	r3, 0x1c(r1)
    lfd	f2, -0x7bb8(r2)
    stw	r0, 0x18(r1)
    lfs	f0, -0x7b98(r2)
    lfd	f1, 0x18(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7ba0(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f31, f31, f0
    b       _80060b1c
_80060b18:
    lfs	f31, -0x7b90(r2)
_80060b1c:
    lwz	r3, -0x7740(r13)
    slwi	r0, r30, 1
    lbz	r4, 0x461(r3)
    add	r3, r3, r0
    lha	r30, 0x5a74(r3)
    cmplwi	r4, 0
    bc      12, 2, _80060b70
    lis	r0, 0x4330
    stw	r4, 0x24(r1)
    lfd	f2, -0x7bb8(r2)
    stw	r0, 0x20(r1)
    lfs	f0, -0x7b98(r2)
    lfd	f1, 0x20(r1)
    fsubs	f1, f1, f2
    fdivs	f1, f1, f0
    bl      expf
    lfd	f0, -0x7ba0(r2)
    fmul	f0, f0, f1
    frsp	f0, f0
    fadds	f1, f31, f0
    b       _80060b74
_80060b70:
    lfs	f1, -0x7b90(r2)
_80060b74:
    lfs	f0, -0x7b8c(r2)
    lwz	r3, -0x7740(r13)
    fmuls	f0, f0, f1
    lha	r0, 0x5a10(r3)
    fctiwz	f0, f0
    stfs	f1, 0(r28)
    add	r30, r30, r0
    sth	r30, 0(r29)
    stfd	f0, 0x28(r1)
    lwz	r0, 0x2c(r1)
    add	r30, r30, r0
    extsh	r0, r30
    cmpwi	r0, -0x3c0
    bc      4, 0, _80060bb0
    li	r30, -0x3c0
_80060bb0:
    mr	r3, r30
    psq_l	f31, 0x48(r1), 0, 0
    lwz	r0, 0x54(r1)
    lfd	f31, 0x40(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    lwz	r29, 0x34(r1)
    lwz	r28, 0x30(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void SndClearVoiceSlot(void)
{
    nofralloc
    mulli	r0, r3, 0x118
    lwz	r5, -0x7740(r13)
    lis     r4, lbl_80192D68@ha
    add	r5, r5, r0
    addi	r4, r4, lbl_80192D68@l
    lbz	r6, 0x140e(r5)
    lbz	r0, 0x140f(r5)
    mulli	r5, r6, 0x54
    slwi	r6, r0, 2
    add	r4, r4, r5
    add	r5, r4, r6
    lbzu	r0, 0x16(r5)
    cmplw	r3, r0
    bc      4, 2, _80060c2c
    li	r0, 0xff
    add	r3, r4, r6
    stb	r0, 0(r5)
    li	r0, 0
    stb	r0, 0x14(r3)
    blr
_80060c2c:
    add	r5, r4, r6
    lbzu	r0, 0x17(r5)
    cmplw	r3, r0
    bnelr	
    li	r0, 0xff
    add	r3, r4, r6
    stb	r0, 0(r5)
    li	r0, 0
    stb	r0, 0x14(r3)
    blr
}

asm void fn_80060C54(void)
{
    nofralloc
    stwu	r1, -0x180(r1)
    mflr	r0
    stw	r0, 0x184(r1)
    stfd	f31, 0x170(r1)
    psq_st	f31, 0x178(r1), 0, 0
    stmw	r14, 0x128(r1)
    lhz	r7, 2(r4)
    li	r0, 1
    stw	r0, 0x110(r1)
    mr	r16, r4
    cmplwi	r7, 0x100
    mr	r15, r3
    mr	r17, r5
    mr	r18, r6
    li	r20, -1
    bc      12, 0, _80060d20
    clrlwi	r0, r17, 0x18
    lis     r3, lbl_80192D68@ha
    mulli	r0, r0, 0x54
    addi	r6, r7, -0x100
    addi	r3, r3, lbl_80192D68@l
    lwz	r4, -0x7740(r13)
    cmplwi	r6, 0
    lbzx	r0, r3, r0
    li	r5, 0
    slwi	r0, r0, 4
    add	r3, r4, r0
    lwz	r3, 8(r3)
    lwz	r0, 0x38(r3)
    addi	r3, r3, 4
    add	r3, r0, r3
    bc      4, 1, _80060d18
    cmplwi	r6, 8
    addi	r4, r6, -8
    bc      4, 1, _80060d00
    addi	r0, r4, 7
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r4, 0
    bc      4, 1, _80060d00
_80060cf4:
    addi	r3, r3, 0x220
    addi	r5, r5, 8
    bc      16, 0, _80060cf4
_80060d00:
    subf	r0, r5, r6
    mtctr	r0
    cmplw	r5, r6
    bc      4, 0, _80060d18
_80060d10:
    addi	r3, r3, 0x44
    bc      16, 0, _80060d10
_80060d18:
    mr	r25, r3
    b       _80060db0
_80060d20:
    lis	r4, 1
    li	r3, 0
    addi	r4, r4, -0x53bc
    li	r0, 4
    cmplwi	r7, 0x2a
    sth	r4, 0xcc(r1)
    stb	r3, 0xcb(r1)
    stb	r0, 0xca(r1)
    stw	r3, 0x94(r1)
    bc      12, 1, _80060d68
    addi	r0, r7, -1
    li	r4, 0xc8
    mulli	r0, r0, 0xc8
    li	r3, 0x63
    stw	r4, 0xd0(r1)
    stw	r3, 0x98(r1)
    stw	r0, 0x90(r1)
    b       _80060dac
_80060d68:
    cmplwi	r7, 0x54
    bc      12, 1, _80060d90
    addi	r0, r7, -0x2b
    li	r4, 0x190
    mulli	r0, r0, 0xc8
    li	r3, 0xc7
    stw	r4, 0xd0(r1)
    stw	r3, 0x98(r1)
    stw	r0, 0x90(r1)
    b       _80060dac
_80060d90:
    addi	r0, r7, -0x55
    li	r4, 0x64
    mulli	r0, r0, 0x64
    li	r3, 0x31
    stw	r4, 0xd0(r1)
    stw	r3, 0x98(r1)
    stw	r0, 0x90(r1)
_80060dac:
    addi	r25, r1, 0x90
_80060db0:
    clrlwi	r0, r17, 0x18
    lis     r3, lbl_80192D68@ha
    mulli	r31, r0, 0x54
    rlwinm	r30, r18, 2, 0x16, 0x1d
    addi	r0, r3, lbl_80192D68@l
    add	r3, r0, r31
    add	r27, r3, r30
    lbzu	r4, 0x14(r27)
    cmplwi	r4, 0
    bc      12, 2, _80060de8
    lbz	r0, 0xa(r16)
    rlwinm	r0, r0, 0, 0x1e, 0x1e
    cmpwi	r0, 2
    bc      4, 2, _80061d24
_80060de8:
    lbz	r3, 0xa(r16)
    rlwinm.	r0, r3, 0, 0x1e, 0x1e
    bc      12, 2, _80060e04
    clrlwi.	r0, r3, 0x1f
    bc      12, 2, _80060e04
    cmplwi	r4, 1
    bc      12, 2, _80060e1c
_80060e04:
    lis     r3, lbl_80192D68@ha
    addi	r0, r3, lbl_80192D68@l
    add	r3, r0, r31
    lbz	r3, 0xf(r3)
    bl      SndSwapVoice
    mr	r20, r3
_80060e1c:
    cmpwi	r20, 0
    bc      12, 0, _80062294
    mr	r3, r16
    mr	r4, r15
    mr	r5, r17
    addi	r6, r1, 0x1c
    addi	r7, r1, 8
    bl      SndCalcVoiceEnvelope
    lbz	r0, 0x3b(r25)
    mr	r19, r3
    cmplwi	r0, 1
    bc      4, 2, _80060f58
    addi	r5, r16, 0xc
    lbz	r4, 4(r16)
    lbz	r0, 0xf(r16)
    clrlwi	r3, r15, 0x18
    lbz	r7, 0xe(r16)
    li	r26, 4
    add	r6, r5, r0
    li	r5, 0
    b       _80060e8c
_80060e70:
    lbz	r8, 0(r6)
    cmplw	r3, r8
    bc      4, 1, _80060e98
    addi	r0, r8, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r6, r6, 4
_80060e8c:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r7
    bc      12, 0, _80060e70
_80060e98:
    clrlwi	r3, r4, 0x18
    clrlwi	r0, r15, 0x18
    lha	r4, 2(r6)
    subf	r0, r3, r0
    lis	r5, 0x4330
    lbz	r6, 1(r6)
    mullw	r4, r4, r0
    lis     r3, lbl_80192D68@ha
    stw	r5, 0xe0(r1)
    addi	r0, r3, lbl_80192D68@l
    lfd	f2, -0x7bb0(r2)
    stw	r6, 0xdc(r1)
    xoris	r4, r4, 0x8000
    stw	r5, 0xd8(r1)
    add	r3, r0, r31
    lfd	f0, -0x7bc0(r2)
    stw	r4, 0xe4(r1)
    lfd	f4, -0x7bb8(r2)
    lfd	f1, 0xe0(r1)
    lfd	f3, 0xd8(r1)
    fsub	f1, f1, f2
    lbz	r0, 4(r3)
    fsub	f2, f3, f4
    fmul	f0, f1, f0
    fadd	f0, f2, f0
    fctiwz	f0, f0
    stfd	f0, 0xe8(r1)
    lwz	r4, 0xec(r1)
    add	r3, r0, r4
    addi	r0, r3, -0x40
    extsh.	r4, r0
    bc      4, 0, _80060f20
    li	r4, 0
    b       _80060f2c
_80060f20:
    cmpwi	r4, 0x7f
    bc      4, 1, _80060f2c
    li	r4, 0x7f
_80060f2c:
    lis     r3, lbl_80092B58@ha
    extsh	r0, r4
    addi	r3, r3, lbl_80092B58@l
    lfs	f1, 0x1c(r1)
    lbzx	r3, r3, r0
    addi	r5, r1, 0xc
    lha	r4, 8(r1)
    addi	r6, r1, 0xa
    bl      fn_8005DB68
    lha	r19, 0xc(r1)
    b       _80061044
_80060f58:
    addi	r6, r16, 0xc
    lbz	r4, 4(r16)
    lbz	r0, 0xf(r16)
    clrlwi	r3, r15, 0x18
    lbz	r7, 0xe(r16)
    li	r5, 0
    add	r6, r6, r0
    b       _80060f94
_80060f78:
    lbz	r8, 0(r6)
    cmplw	r3, r8
    bc      4, 1, _80060fa0
    addi	r0, r8, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r6, r6, 4
_80060f94:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r7
    bc      12, 0, _80060f78
_80060fa0:
    clrlwi	r3, r4, 0x18
    clrlwi	r0, r15, 0x18
    lha	r4, 2(r6)
    subf	r0, r3, r0
    lis	r5, 0x4330
    lbz	r6, 1(r6)
    mullw	r4, r4, r0
    lis     r3, lbl_80192D68@ha
    stw	r5, 0xe0(r1)
    addi	r0, r3, lbl_80192D68@l
    lfd	f2, -0x7bb0(r2)
    stw	r6, 0xec(r1)
    xoris	r4, r4, 0x8000
    stw	r5, 0xe8(r1)
    add	r3, r0, r31
    lfd	f0, -0x7bc0(r2)
    stw	r4, 0xe4(r1)
    lfd	f4, -0x7bb8(r2)
    lfd	f1, 0xe0(r1)
    lfd	f3, 0xe8(r1)
    fsub	f1, f1, f2
    lbz	r0, 4(r3)
    fsub	f2, f3, f4
    fmul	f0, f1, f0
    fadd	f0, f2, f0
    fctiwz	f0, f0
    stfd	f0, 0xd8(r1)
    lwz	r4, 0xdc(r1)
    add	r3, r0, r4
    addi	r0, r3, -0x40
    extsh.	r4, r0
    bc      4, 0, _80061028
    li	r4, 0
    b       _80061034
_80061028:
    cmpwi	r4, 0x7f
    bc      4, 1, _80061034
    li	r4, 0x7f
_80061034:
    lis     r3, lbl_80092B58@ha
    extsh	r0, r4
    addi	r3, r3, lbl_80092B58@l
    lbzx	r26, r3, r0
_80061044:
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x462(r3)
    cmplwi	r0, 0
    bc      4, 2, _800612d4
    lbz	r0, 0x3b(r25)
    cmplwi	r0, 1
    bc      4, 2, _800610bc
    lha	r5, 0xc(r1)
    lis	r3, 0x4330
    lha	r4, 0xa(r1)
    extsh	r0, r19
    xoris	r0, r0, 0x8000
    stw	r3, 0xe8(r1)
    add	r4, r5, r4
    lfd	f2, -0x7bb0(r2)
    xoris	r4, r4, 0x8000
    stw	r0, 0xe4(r1)
    lfs	f3, -0x7b50(r2)
    li	r26, 0x40
    stw	r4, 0xec(r1)
    stw	r3, 0xe0(r1)
    lfd	f1, 0xe8(r1)
    lfd	f0, 0xe0(r1)
    fsubs	f1, f1, f2
    fsubs	f0, f0, f2
    fmadds	f0, f3, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xd8(r1)
    lwz	r19, 0xdc(r1)
    b       _800612d4
_800610bc:
    extsh	r14, r26
    lis	r3, -0x7efe
    subfic	r4, r14, 0x7f
    lis	r0, 0x4330
    addi	r3, r3, 0x409
    stw	r0, 0xe8(r1)
    mulhw	r0, r3, r4
    lfd	f2, -0x7bb0(r2)
    lfd	f1, -0x7b68(r2)
    add	r0, r0, r4
    srawi	r0, r0, 6
    srwi	r3, r0, 0x1f
    add	r0, r0, r3
    xoris	r0, r0, 0x8000
    stw	r0, 0xec(r1)
    lfd	f0, 0xe8(r1)
    fsubs	f4, f0, f2
    fcmpo	cr0, f4, f1
    bc      4, 1, _8006115c
    frsqrte	f1, f4
    lfd	f3, -0x7b48(r2)
    lfd	f2, -0x7b40(r2)
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f0, f1, f0
    fmul	f1, f4, f0
    b       _80061184
_8006115c:
    fcmpu	cr0, f1, f4
    bc      4, 2, _80061168
    b       _80061184
_80061168:
    fcmpu	cr0, f4, f1
    bc      12, 2, _8006117c
    lis	r3, -0x7fe6
    lfs	f1, 0x6648(r3)
    b       _80061184
_8006117c:
    lis	r3, -0x7fe6
    lfs	f1, 0x664c(r3)
_80061184:
    bl      expf
    lis	r3, -0x7efe
    lfd	f0, -0x7b38(r2)
    addi	r3, r3, 0x409
    lis	r0, 0x4330
    mulhw	r3, r3, r14
    fmul	f0, f0, f1
    stw	r0, 0xe0(r1)
    lfd	f2, -0x7bb0(r2)
    lfd	f1, -0x7b68(r2)
    fctiwz	f0, f0
    add	r0, r3, r14
    srawi	r0, r0, 6
    stfd	f0, 0xe8(r1)
    srwi	r3, r0, 0x1f
    add	r0, r0, r3
    lwz	r3, 0xec(r1)
    xoris	r0, r0, 0x8000
    stw	r0, 0xe4(r1)
    lfd	f0, 0xe0(r1)
    sth	r3, 0xc(r1)
    fsubs	f4, f0, f2
    fcmpo	cr0, f4, f1
    bc      4, 1, _80061238
    frsqrte	f1, f4
    lfd	f3, -0x7b48(r2)
    lfd	f2, -0x7b40(r2)
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f0, f1, f0
    fmul	f1, f4, f0
    b       _80061260
_80061238:
    fcmpu	cr0, f1, f4
    bc      4, 2, _80061244
    b       _80061260
_80061244:
    fcmpu	cr0, f4, f1
    bc      12, 2, _80061258
    lis	r3, -0x7fe6
    lfs	f1, 0x6648(r3)
    b       _80061260
_80061258:
    lis	r3, -0x7fe6
    lfs	f1, 0x664c(r3)
_80061260:
    bl      expf
    lfd	f0, -0x7ba0(r2)
    lis	r3, 0x4330
    extsh	r0, r19
    lha	r4, 0xc(r1)
    fmul	f0, f0, f1
    xoris	r0, r0, 0x8000
    stw	r3, 0xe0(r1)
    li	r26, 0x40
    lfd	f2, -0x7bb0(r2)
    stw	r0, 0xdc(r1)
    fctiwz	f1, f0
    stw	r3, 0xd8(r1)
    lfs	f3, -0x7b50(r2)
    lfd	f0, 0xd8(r1)
    stfd	f1, 0xe8(r1)
    fsubs	f0, f0, f2
    lwz	r3, 0xec(r1)
    extsh	r0, r3
    sth	r3, 0xa(r1)
    add	r0, r4, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0xe4(r1)
    lfd	f1, 0xe0(r1)
    fsubs	f1, f1, f2
    fmadds	f0, f3, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xf0(r1)
    lwz	r19, 0xf4(r1)
_800612d4:
    lbz	r0, 8(r16)
    lis     r3, lbl_80092B38@ha
    addi	r5, r3, lbl_80092B38@l
    mr	r3, r16
    slwi	r0, r0, 1
    mr	r4, r17
    lhax	r14, r5, r0
    mr	r5, r15
    addi	r6, r1, 0x10
    addi	r7, r1, 0x18
    addi	r8, r1, 0x14
    bl      fn_80060724
    addi	r6, r16, 0xc
    lbz	r4, 4(r16)
    lbz	r0, 0x11(r16)
    clrlwi	r3, r15, 0x18
    lbz	r7, 0x10(r16)
    li	r5, 0
    add	r6, r6, r0
    b       _80061340
_80061324:
    lbz	r8, 0(r6)
    cmplw	r3, r8
    bc      4, 1, _8006134c
    addi	r0, r8, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r6, r6, 4
_80061340:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r7
    bc      12, 0, _80061324
_8006134c:
    clrlwi	r3, r4, 0x18
    clrlwi	r0, r15, 0x18
    lha	r4, 2(r6)
    lis	r5, 0x4330
    stw	r0, 0x118(r1)
    subf	r0, r3, r0
    mullw	r4, r4, r0
    lbz	r6, 1(r6)
    lis     r3, lbl_80192D68@ha
    stw	r5, 0xe8(r1)
    lfd	f2, -0x7bb0(r2)
    addi	r0, r3, lbl_80192D68@l
    xoris	r4, r4, 0x8000
    add	r3, r0, r31
    stw	r4, 0xec(r1)
    lfd	f0, -0x7bc0(r2)
    lfd	f1, 0xe8(r1)
    stw	r6, 0xf4(r1)
    fsub	f1, f1, f2
    lfd	f4, -0x7bb8(r2)
    stw	r5, 0xf0(r1)
    lbz	r0, 5(r3)
    lfd	f3, 0xf0(r1)
    fmul	f0, f1, f0
    fsub	f2, f3, f4
    fadd	f0, f2, f0
    fctiwz	f0, f0
    stfd	f0, 0xe0(r1)
    lwz	r8, 0xe4(r1)
    add	r3, r0, r8
    addi	r0, r3, -0x40
    extsh.	r8, r0
    bc      4, 0, _800613d8
    li	r8, 0
    b       _800613e4
_800613d8:
    cmpwi	r8, 0x7f
    bc      4, 1, _800613e4
    li	r8, 0x7f
_800613e4:
    lis     r3, lbl_80192D68@ha
    extsh	r14, r14
    addi	r0, r3, lbl_80192D68@l
    lwz	r3, -0x7740(r13)
    add	r0, r0, r31
    lis	r6, -0x7ff7
    add	r11, r0, r30
    li	r7, 3
    stb	r20, 0x16(r11)
    mulli	r29, r20, 0x118
    li	r0, 0
    lbz	r5, 0xa(r16)
    li	r4, 0x1e
    add	r3, r3, r29
    extsh	r8, r8
    stb	r5, 0x15(r11)
    addi	r5, r6, 0x2b58
    lbzx	r5, r5, r8
    mr	r10, r14
    stw	r0, 0x1420(r3)
    addi	r3, r11, 0x15
    extsh	r28, r5
    extsh	r5, r19
    lwz	r6, -0x7740(r13)
    mr	r9, r28
    stw	r3, 0x114(r1)
    extsh	r8, r26
    add	r3, r6, r29
    stb	r7, 0x1408(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r29
    stb	r0, 0x140b(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r29
    stb	r0, 0x140c(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r29
    stb	r4, 0x1410(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r29
    stb	r0, 0x140d(r3)
    lwz	r3, -0x7740(r13)
    lbz	r4, 7(r16)
    add	r3, r3, r29
    sth	r4, 0x1416(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r29
    stw	r0, 0x1418(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    stb	r17, 0x140e(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    stb	r18, 0x140f(r3)
    lwz	r0, -0x7740(r13)
    lwz	r4, 0x10(r1)
    add	r3, r0, r29
    lwz	r6, 0x18(r1)
    lwz	r3, 0x1434(r3)
    lwz	r7, 0x14(r1)
    bl      fn_80025EF4
    lbz	r0, 0x3a(r25)
    clrlwi.	r0, r0, 0x1e
    bc      4, 2, _8006154c
    li	r0, 0
    li	r4, 0xa
    li	r3, 0x800
    sth	r4, 0x5a(r1)
    li	r21, 2
    sth	r3, 0x88(r1)
    sth	r0, 0x68(r1)
    sth	r0, 0x6a(r1)
    sth	r0, 0x6c(r1)
    sth	r0, 0x6e(r1)
    sth	r0, 0x70(r1)
    sth	r0, 0x72(r1)
    sth	r0, 0x74(r1)
    sth	r0, 0x76(r1)
    sth	r0, 0x78(r1)
    sth	r0, 0x7a(r1)
    sth	r0, 0x7c(r1)
    sth	r0, 0x7e(r1)
    sth	r0, 0x80(r1)
    sth	r0, 0x82(r1)
    sth	r0, 0x84(r1)
    sth	r0, 0x86(r1)
    sth	r0, 0x8a(r1)
    sth	r0, 0x8c(r1)
    sth	r0, 0x8e(r1)
    b       _80061688
_8006154c:
    cmpwi	r0, 1
    bc      4, 2, _800615bc
    li	r0, 0
    li	r4, 0x19
    li	r3, 0x100
    sth	r4, 0x5a(r1)
    li	r21, 1
    sth	r3, 0x88(r1)
    sth	r0, 0x68(r1)
    sth	r0, 0x6a(r1)
    sth	r0, 0x6c(r1)
    sth	r0, 0x6e(r1)
    sth	r0, 0x70(r1)
    sth	r0, 0x72(r1)
    sth	r0, 0x74(r1)
    sth	r0, 0x76(r1)
    sth	r0, 0x78(r1)
    sth	r0, 0x7a(r1)
    sth	r0, 0x7c(r1)
    sth	r0, 0x7e(r1)
    sth	r0, 0x80(r1)
    sth	r0, 0x82(r1)
    sth	r0, 0x84(r1)
    sth	r0, 0x86(r1)
    sth	r0, 0x8a(r1)
    sth	r0, 0x8c(r1)
    sth	r0, 0x8e(r1)
    b       _80061688
_800615bc:
    li	r8, 0
    li	r0, 2
    sth	r8, 0x5a(r1)
    mr	r3, r8
    addi	r9, r1, 0x68
    li	r21, 4
    lhz	r4, 0x2c(r25)
    sth	r4, 0x88(r1)
    mtctr	r0
_800615e0:
    addi	r7, r3, 0xc
    addi	r6, r8, 1
    lhzx	r0, r25, r7
    slwi	r5, r6, 1
    addi	r4, r5, 0xc
    addi	r6, r8, 3
    sth	r0, 0(r9)
    slwi	r5, r6, 1
    addi	r7, r3, 0x10
    addi	r6, r8, 5
    lhzx	r0, r25, r4
    addi	r4, r5, 0xc
    slwi	r5, r6, 1
    addi	r6, r8, 7
    sth	r0, 2(r9)
    addi	r8, r8, 8
    lhzx	r0, r25, r7
    addi	r7, r3, 0x14
    sth	r0, 4(r9)
    lhzx	r0, r25, r4
    addi	r4, r5, 0xc
    slwi	r5, r6, 1
    sth	r0, 6(r9)
    lhzx	r0, r25, r7
    addi	r7, r3, 0x18
    addi	r3, r3, 0x10
    sth	r0, 8(r9)
    lhzx	r0, r25, r4
    addi	r4, r5, 0xc
    sth	r0, 0xa(r9)
    lhzx	r0, r25, r7
    sth	r0, 0xc(r9)
    lhzx	r0, r25, r4
    sth	r0, 0xe(r9)
    addi	r9, r9, 0x10
    bc      16, 0, _800615e0
    lhz	r0, 0x2e(r25)
    sth	r0, 0x8a(r1)
    lhz	r0, 0x30(r25)
    sth	r0, 0x8c(r1)
    lhz	r0, 0x32(r25)
    sth	r0, 0x8e(r1)
_80061688:
    lhz	r0, 2(r16)
    cmplwi	r0, 0x100
    bc      12, 0, _800616bc
    lis     r3, lbl_80192D68@ha
    lwz	r4, -0x7740(r13)
    addi	r3, r3, lbl_80192D68@l
    lwz	r5, 0(r25)
    lbzx	r0, r3, r31
    slwi	r0, r0, 4
    add	r3, r4, r0
    lwz	r0, 4(r3)
    add	r3, r5, r0
    b       _800616cc
_800616bc:
    lwz	r3, -0x7740(r13)
    lwz	r0, 0(r25)
    lwz	r3, 0x1a8(r3)
    add	r3, r3, r0
_800616cc:
    clrlwi	r0, r21, 0x18
    cmplwi	r0, 4
    bc      12, 2, _800616e4
    divwu	r3, r3, r0
    mr	r22, r3
    b       _800616ec
_800616e4:
    slwi	r3, r3, 1
    addi	r22, r3, 2
_800616ec:
    lbz	r0, 0x3a(r25)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    bc      12, 2, _80061770
    clrlwi	r0, r21, 0x18
    li	r4, 1
    cmplwi	r0, 4
    sth	r4, 0x58(r1)
    bc      12, 2, _80061730
    lwz	r5, 4(r25)
    li	r0, 0
    lwz	r4, 8(r25)
    add	r23, r3, r5
    sth	r0, 0x20(r1)
    add	r24, r3, r4
    sth	r0, 0x22(r1)
    sth	r0, 0x24(r1)
    b       _80061758
_80061730:
    lwz	r5, 4(r25)
    lwz	r4, 8(r25)
    lhz	r0, 0x34(r25)
    add	r23, r3, r5
    add	r24, r3, r4
    sth	r0, 0x20(r1)
    lhz	r0, 0x36(r25)
    sth	r0, 0x22(r1)
    lhz	r0, 0x38(r25)
    sth	r0, 0x24(r1)
_80061758:
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x20
    add	r3, r0, r29
    lwz	r3, 0x1434(r3)
    bl      fn_80023568
    b       _800617b4
_80061770:
    clrlwi	r5, r21, 0x18
    li	r0, 0
    cmplwi	r5, 4
    sth	r0, 0x58(r1)
    bc      12, 2, _8006179c
    lwz	r4, -0x7740(r13)
    lwz	r0, 8(r25)
    lwz	r4, 0x1a4(r4)
    add	r24, r3, r0
    divwu	r23, r4, r5
    b       _800617b4
_8006179c:
    lwz	r4, -0x7740(r13)
    lwz	r0, 8(r25)
    lwz	r4, 0x1a4(r4)
    add	r24, r3, r0
    slwi	r3, r4, 1
    addi	r23, r3, 2
_800617b4:
    srwi	r3, r23, 0x10
    srwi	r4, r24, 0x10
    srwi	r0, r22, 0x10
    sth	r3, 0x5c(r1)
    addi	r6, r16, 0xc
    clrlwi	r3, r15, 0x18
    sth	r23, 0x5e(r1)
    li	r5, 0
    sth	r4, 0x60(r1)
    sth	r24, 0x62(r1)
    sth	r0, 0x64(r1)
    sth	r22, 0x66(r1)
    lbz	r0, 0x13(r16)
    lbz	r4, 4(r16)
    lbz	r8, 0x12(r16)
    add	r7, r6, r0
    b       _80061814
_800617f8:
    lbz	r6, 0(r7)
    cmplw	r3, r6
    bc      4, 1, _80061820
    addi	r0, r6, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r7, r7, 6
_80061814:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r8
    bc      12, 0, _800617f8
_80061820:
    lwz	r0, 0x118(r1)
    lis	r6, 0x4330
    clrlwi	r3, r4, 0x18
    lha	r4, 4(r7)
    subf	r0, r3, r0
    stw	r6, 0xe8(r1)
    mullw	r5, r4, r0
    lis     r3, lbl_80192D68@ha
    lhz	r4, 2(r7)
    addi	r0, r3, lbl_80192D68@l
    lfd	f6, -0x7bb0(r2)
    addi	r7, r4, -0xc00
    add	r4, r0, r31
    xoris	r0, r5, 0x8000
    stw	r0, 0xec(r1)
    xoris	r5, r7, 0x8000
    lbz	r3, 0xa(r4)
    lfd	f0, 0xe8(r1)
    addi	r0, r3, -0x40
    lbz	r3, 9(r4)
    xoris	r0, r0, 0x8000
    fsub	f3, f0, f6
    lfd	f2, -0x7bc0(r2)
    addi	r3, r3, -0x40
    xoris	r3, r3, 0x8000
    stw	r0, 0xdc(r1)
    fmul	f3, f3, f2
    stw	r6, 0xd8(r1)
    lfd	f1, -0x7b78(r2)
    lfd	f0, 0xd8(r1)
    stw	r5, 0xf4(r1)
    fsub	f0, f0, f6
    lfd	f7, -0x7b88(r2)
    stw	r6, 0xf0(r1)
    lfd	f4, -0x7b80(r2)
    lfd	f2, 0xf0(r1)
    fmul	f1, f1, f0
    stw	r3, 0xe4(r1)
    fsub	f5, f2, f6
    lfd	f0, -0x7b68(r2)
    stw	r6, 0xe0(r1)
    lfd	f2, 0xe0(r1)
    fadd	f5, f5, f3
    fsub	f3, f2, f6
    fmul	f2, f7, f5
    fmadd	f1, f4, f3, f1
    fadd	f2, f2, f1
    fcmpu	cr0, f2, f0
    bc      12, 2, _800618ec
    lfd	f0, -0x7b70(r2)
    fdiv	f2, f2, f0
_800618ec:
    lfd	f1, -0x7b60(r2)
    bl      fn_80088598
    fmr	f31, f1
    lfd	f1, -0x7b60(r2)
    lfd	f2, -0x7b58(r2)
    fabs	f0, f31
    fctiwz	f0, f0
    stfd	f0, 0xf8(r1)
    lwz	r15, 0xfc(r1)
    bl      fn_80088598
    clrlwi	r3, r15, 0x10
    lis	r0, 0x4330
    stw	r3, 0x104(r1)
    cmplwi	r3, 4
    lfd	f2, -0x7bb8(r2)
    stw	r0, 0x100(r1)
    lfd	f0, 0x100(r1)
    fsub	f0, f0, f2
    fsub	f0, f31, f0
    fmul	f0, f0, f1
    fctiwz	f0, f0
    stfd	f0, 0x108(r1)
    lwz	r22, 0x10c(r1)
    bc      12, 0, _8006195c
    clrlwi.	r0, r22, 0x10
    bc      12, 2, _8006195c
    li	r15, 4
    li	r22, 0
_8006195c:
    li	r5, 0
    lwz	r0, -0x7740(r13)
    sth	r15, 0x48(r1)
    addi	r4, r1, 0x48
    add	r3, r0, r29
    sth	r22, 0x4a(r1)
    sth	r5, 0x4c(r1)
    sth	r5, 0x4e(r1)
    sth	r5, 0x50(r1)
    sth	r5, 0x52(r1)
    sth	r5, 0x54(r1)
    lwz	r3, 0x1434(r3)
    bl      fn_80023438
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x58
    add	r3, r0, r29
    lwz	r3, 0x1434(r3)
    bl      fn_80023284
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x68
    add	r3, r0, r29
    lwz	r3, 0x1434(r3)
    bl      fn_80023394
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r29
    lwz	r3, 0x1434(r3)
    bl      fn_800230A4
    lbz	r0, 0x3b(r25)
    cmplwi	r0, 1
    bc      4, 2, _80061ce0
    lis     r3, lbl_80192D68@ha
    addi	r0, r3, lbl_80192D68@l
    add	r3, r0, r31
    lbz	r3, 0xf(r3)
    bl      SndSwapVoice
    mr	r23, r3
    cmpwi	r23, -1
    bc      12, 2, _80061cd8
    lis     r4, lbl_80192D68@ha
    lwz	r3, -0x7740(r13)
    addi	r4, r4, lbl_80192D68@l
    li	r0, 0
    add	r4, r4, r31
    li	r5, 3
    add	r6, r4, r30
    stb	r23, 0x17(r6)
    mulli	r24, r23, 0x118
    li	r4, 0x1e
    lbz	r7, 0xa(r16)
    add	r6, r3, r24
    lwz	r3, 0x114(r1)
    stb	r7, 0(r3)
    stw	r0, 0x1420(r6)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stb	r5, 0x1408(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stb	r0, 0x140b(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stb	r0, 0x140c(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stb	r4, 0x1410(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stb	r0, 0x140d(r3)
    lwz	r3, -0x7740(r13)
    lbz	r4, 7(r16)
    add	r3, r3, r24
    sth	r4, 0x1416(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r24
    stw	r0, 0x1418(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stb	r17, 0x140e(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stb	r18, 0x140f(r3)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x462(r3)
    cmplwi	r0, 0
    bc      12, 2, _80061abc
    lha	r19, 0xa(r1)
    li	r26, 0x7c
_80061abc:
    add	r3, r3, r24
    lwz	r4, 0x10(r1)
    lwz	r3, 0x1434(r3)
    mr	r9, r28
    lwz	r6, 0x18(r1)
    mr	r10, r14
    lwz	r7, 0x14(r1)
    extsh	r5, r19
    extsh	r8, r26
    bl      fn_80025EF4
    lbz	r0, 0x3a(r25)
    clrlwi.	r0, r0, 0x1e
    bc      4, 2, _80061afc
    li	r0, 0xa
    sth	r0, 0x3a(r1)
    b       _80061b18
_80061afc:
    cmpwi	r0, 1
    bc      4, 2, _80061b10
    li	r0, 0x19
    sth	r0, 0x3a(r1)
    b       _80061b18
_80061b10:
    li	r0, 0
    sth	r0, 0x3a(r1)
_80061b18:
    lis     r3, lbl_80192D68@ha
    clrlwi	r0, r21, 0x18
    addi	r4, r3, lbl_80192D68@l
    lwz	r3, -0x7740(r13)
    lbzx	r4, r4, r31
    cmplwi	r0, 4
    lwz	r6, 0x40(r25)
    slwi	r4, r4, 4
    lwz	r5, 0(r25)
    add	r4, r3, r4
    lwz	r4, 4(r4)
    add	r14, r4, r6
    add	r14, r5, r14
    bc      12, 2, _80061b58
    divwu	r14, r14, r0
    b       _80061b5c
_80061b58:
    slwi	r14, r14, 1
_80061b5c:
    lbz	r0, 0x3a(r25)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    bc      12, 2, _80061bb4
    clrlwi	r0, r21, 0x18
    li	r4, 1
    cmplwi	r0, 4
    sth	r4, 0x38(r1)
    bc      12, 2, _80061b90
    lwz	r4, 4(r25)
    lwz	r0, 8(r25)
    add	r16, r14, r4
    add	r17, r14, r0
    b       _80061ba0
_80061b90:
    lwz	r4, 4(r25)
    lwz	r0, 8(r25)
    add	r16, r14, r4
    add	r17, r14, r0
_80061ba0:
    add	r3, r3, r24
    addi	r4, r1, 0x20
    lwz	r3, 0x1434(r3)
    bl      fn_80023568
    b       _80061bec
_80061bb4:
    clrlwi	r4, r21, 0x18
    li	r0, 0
    cmplwi	r4, 4
    sth	r0, 0x38(r1)
    bc      12, 2, _80061bdc
    lwz	r3, 0x1a4(r3)
    lwz	r0, 8(r25)
    divwu	r16, r3, r4
    add	r17, r14, r0
    b       _80061bec
_80061bdc:
    lwz	r3, 0x1a4(r3)
    lwz	r0, 8(r25)
    slwi	r16, r3, 1
    add	r17, r14, r0
_80061bec:
    li	r5, 0
    srwi	r3, r16, 0x10
    srwi	r7, r17, 0x10
    srwi	r6, r14, 0x10
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x38
    sth	r3, 0x3c(r1)
    add	r3, r0, r24
    sth	r16, 0x3e(r1)
    sth	r7, 0x40(r1)
    sth	r17, 0x42(r1)
    sth	r6, 0x44(r1)
    sth	r14, 0x46(r1)
    sth	r15, 0x28(r1)
    sth	r22, 0x2a(r1)
    sth	r5, 0x2c(r1)
    sth	r5, 0x2e(r1)
    sth	r5, 0x30(r1)
    sth	r5, 0x32(r1)
    sth	r5, 0x34(r1)
    lwz	r3, 0x1434(r3)
    bl      fn_80023284
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x68
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80023394
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_800230A4
    lwz	r0, -0x7740(r13)
    addi	r4, r1, 0x28
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80023438
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r24
    lwz	r3, 0x1434(r3)
    bl      fn_80023168
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r24
    stb	r4, 0x1409(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    stb	r20, 0x1411(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r29
    stb	r23, 0x1412(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stb	r20, 0x1411(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r24
    stb	r23, 0x1412(r3)
    b       _80061ce0
_80061cd8:
    li	r0, 0
    stw	r0, 0x110(r1)
_80061ce0:
    lwz	r0, 0x110(r1)
    cmplwi	r0, 0
    bc      12, 2, _80061d18
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r29
    lwz	r3, 0x1434(r3)
    bl      fn_80023168
    lwz	r0, -0x7740(r13)
    li	r4, 1
    add	r3, r0, r29
    stb	r4, 0x1409(r3)
    stb	r4, 0(r27)
    b       _80062294
_80061d18:
    clrlwi	r3, r20, 0x18
    bl      SndKillChannelVoice
    b       _80062294
_80061d24:
    addi	r6, r16, 0xc
    add	r4, r3, r30
    lbz	r0, 0x13(r16)
    clrlwi	r3, r15, 0x18
    lbz	r14, 0x16(r4)
    li	r5, 0
    lbz	r4, 4(r16)
    add	r7, r6, r0
    lbz	r6, 6(r6)
    b       _80061d68
_80061d4c:
    lbz	r8, 0(r7)
    cmplw	r3, r8
    bc      4, 1, _80061d74
    addi	r0, r8, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r7, r7, 6
_80061d68:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r6
    bc      12, 0, _80061d4c
_80061d74:
    clrlwi	r0, r4, 0x18
    clrlwi	r18, r15, 0x18
    lha	r4, 4(r7)
    subf	r0, r0, r18
    lis	r6, 0x4330
    lis     r3, lbl_80192D68@ha
    mullw	r5, r4, r0
    lhz	r4, 2(r7)
    addi	r0, r3, lbl_80192D68@l
    stw	r6, 0x100(r1)
    addi	r7, r4, -0xc00
    lfd	f6, -0x7bb0(r2)
    add	r4, r0, r31
    xoris	r0, r5, 0x8000
    lbz	r3, 0xa(r4)
    xoris	r5, r7, 0x8000
    stw	r0, 0x104(r1)
    addi	r0, r3, -0x40
    lbz	r3, 9(r4)
    xoris	r0, r0, 0x8000
    lfd	f0, 0x100(r1)
    addi	r3, r3, -0x40
    stw	r0, 0xf4(r1)
    xoris	r0, r3, 0x8000
    fsub	f2, f0, f6
    stw	r6, 0xf0(r1)
    lfd	f1, -0x7bc0(r2)
    lfd	f0, 0xf0(r1)
    stw	r5, 0x10c(r1)
    fmul	f3, f2, f1
    lfd	f1, -0x7b78(r2)
    stw	r6, 0x108(r1)
    fsub	f0, f0, f6
    lfd	f7, -0x7b88(r2)
    lfd	f2, 0x108(r1)
    stw	r0, 0xfc(r1)
    fmul	f1, f1, f0
    lfd	f4, -0x7b80(r2)
    stw	r6, 0xf8(r1)
    fsub	f5, f2, f6
    lfd	f0, -0x7b68(r2)
    lfd	f2, 0xf8(r1)
    fadd	f5, f5, f3
    fsub	f3, f2, f6
    fmul	f2, f7, f5
    fmadd	f1, f4, f3, f1
    fadd	f2, f2, f1
    fcmpu	cr0, f2, f0
    bc      12, 2, _80061e40
    lfd	f0, -0x7b70(r2)
    fdiv	f2, f2, f0
_80061e40:
    lfd	f1, -0x7b60(r2)
    bl      fn_80088598
    frsp	f31, f1
    lfs	f0, -0x7b30(r2)
    fcmpo	cr0, f31, f0
    bc      4, 1, _80061e5c
    fmr	f31, f0
_80061e5c:
    mulli	r19, r14, 0x118
    lwz	r0, -0x7740(r13)
    fmr	f1, f31
    add	r3, r0, r19
    lwz	r3, 0x1434(r3)
    bl      fn_800234D0
    mr	r3, r16
    mr	r4, r15
    mr	r5, r17
    addi	r6, r1, 0x1c
    addi	r7, r1, 8
    bl      SndCalcVoiceEnvelope
    addi	r5, r16, 0xc
    lbz	r4, 4(r16)
    lbz	r0, 0x11(r16)
    mr	r14, r3
    lbz	r7, 0x10(r16)
    clrlwi	r3, r15, 0x18
    add	r6, r5, r0
    li	r5, 0
    b       _80061ecc
_80061eb0:
    lbz	r8, 0(r6)
    cmplw	r3, r8
    bc      4, 1, _80061ed8
    addi	r0, r8, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r6, r6, 4
_80061ecc:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r7
    bc      12, 0, _80061eb0
_80061ed8:
    clrlwi	r0, r4, 0x18
    lha	r3, 2(r6)
    subf	r0, r0, r18
    lis	r5, 0x4330
    mullw	r4, r3, r0
    lbz	r6, 1(r6)
    lis     r3, lbl_80192D68@ha
    stw	r5, 0x100(r1)
    lfd	f2, -0x7bb0(r2)
    addi	r0, r3, lbl_80192D68@l
    xoris	r4, r4, 0x8000
    add	r3, r0, r31
    stw	r4, 0x104(r1)
    lfd	f0, -0x7bc0(r2)
    lfd	f1, 0x100(r1)
    stw	r6, 0x10c(r1)
    fsub	f1, f1, f2
    lfd	f3, -0x7bb8(r2)
    stw	r5, 0x108(r1)
    lbz	r0, 5(r3)
    lfd	f2, 0x108(r1)
    fmul	f0, f1, f0
    fsub	f1, f2, f3
    fadd	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xf8(r1)
    lwz	r4, 0xfc(r1)
    add	r3, r0, r4
    addi	r0, r3, -0x40
    extsh.	r4, r0
    bc      4, 0, _80061f5c
    li	r4, 0
    b       _80061f68
_80061f5c:
    cmpwi	r4, 0x7f
    bc      4, 1, _80061f68
    li	r4, 0x7f
_80061f68:
    lis     r3, lbl_80092B58@ha
    extsh	r0, r4
    addi	r4, r3, lbl_80092B58@l
    mr	r3, r16
    lbzx	r20, r4, r0
    mr	r4, r17
    mr	r5, r15
    addi	r6, r1, 0x10
    addi	r7, r1, 0x18
    addi	r8, r1, 0x14
    bl      fn_80060724
    lwz	r0, -0x7740(r13)
    lwz	r4, 0x18(r1)
    add	r3, r0, r19
    lwz	r3, 0x1434(r3)
    bl      fn_80026E2C
    lwz	r0, -0x7740(r13)
    lwz	r4, 0x14(r1)
    add	r3, r0, r19
    lwz	r3, 0x1434(r3)
    bl      fn_80026EAC
    lis     r3, lbl_80192D68@ha
    addi	r0, r3, lbl_80192D68@l
    add	r0, r0, r31
    add	r17, r0, r30
    lbzu	r0, 0x17(r17)
    cmplwi	r0, 0xff
    bc      4, 2, _80062100
    lwz	r0, -0x7740(r13)
    extsh	r4, r14
    add	r3, r0, r19
    lwz	r3, 0x1434(r3)
    bl      fn_80026D90
    addi	r6, r16, 0xc
    lbz	r4, 4(r16)
    lbz	r0, 0xf(r16)
    clrlwi	r3, r15, 0x18
    lbz	r7, 0xe(r16)
    li	r5, 0
    add	r6, r6, r0
    b       _80062028
_8006200c:
    lbz	r8, 0(r6)
    cmplw	r3, r8
    bc      4, 1, _80062034
    addi	r0, r8, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r6, r6, 4
_80062028:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r7
    bc      12, 0, _8006200c
_80062034:
    clrlwi	r0, r4, 0x18
    lha	r3, 2(r6)
    subf	r0, r0, r18
    lis	r5, 0x4330
    mullw	r4, r3, r0
    lbz	r6, 1(r6)
    lis     r3, lbl_80192D68@ha
    stw	r5, 0x100(r1)
    lfd	f2, -0x7bb0(r2)
    addi	r0, r3, lbl_80192D68@l
    xoris	r4, r4, 0x8000
    add	r3, r0, r31
    stw	r4, 0x104(r1)
    lfd	f0, -0x7bc0(r2)
    lfd	f1, 0x100(r1)
    stw	r6, 0x10c(r1)
    fsub	f1, f1, f2
    lfd	f3, -0x7bb8(r2)
    stw	r5, 0x108(r1)
    lbz	r0, 4(r3)
    lfd	f2, 0x108(r1)
    fmul	f0, f1, f0
    fsub	f1, f2, f3
    fadd	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xf8(r1)
    lwz	r4, 0xfc(r1)
    add	r3, r0, r4
    addi	r0, r3, -0x40
    extsh.	r4, r0
    bc      4, 0, _800620b8
    li	r4, 0
    b       _800620c4
_800620b8:
    cmpwi	r4, 0x7f
    bc      4, 1, _800620c4
    li	r4, 0x7f
_800620c4:
    lwz	r0, -0x7740(r13)
    lis     r3, lbl_80092B58@ha
    extsh	r5, r4
    addi	r4, r3, lbl_80092B58@l
    add	r3, r0, r19
    lbzx	r0, r4, r5
    lwz	r3, 0x1434(r3)
    extsh	r4, r0
    bl      fn_80026EE0
    lwz	r0, -0x7740(r13)
    extsh	r4, r20
    add	r3, r0, r19
    lwz	r3, 0x1434(r3)
    bl      fn_80026F4C
    b       _80062294
_80062100:
    addi	r6, r16, 0xc
    lbz	r4, 4(r16)
    lbz	r0, 0xf(r16)
    clrlwi	r3, r15, 0x18
    lbz	r7, 0xe(r16)
    li	r5, 0
    add	r6, r6, r0
    b       _8006213c
_80062120:
    lbz	r8, 0(r6)
    cmplw	r3, r8
    bc      4, 1, _80062148
    addi	r0, r8, 1
    addi	r5, r5, 1
    clrlwi	r4, r0, 0x18
    addi	r6, r6, 4
_8006213c:
    clrlwi	r0, r5, 0x18
    cmplw	r0, r7
    bc      12, 0, _80062120
_80062148:
    clrlwi	r0, r4, 0x18
    lha	r3, 2(r6)
    subf	r0, r0, r18
    lis	r5, 0x4330
    mullw	r4, r3, r0
    lbz	r6, 1(r6)
    lis     r3, lbl_80192D68@ha
    stw	r5, 0x100(r1)
    lfd	f2, -0x7bb0(r2)
    addi	r0, r3, lbl_80192D68@l
    xoris	r4, r4, 0x8000
    add	r3, r0, r31
    stw	r4, 0x104(r1)
    lfd	f0, -0x7bc0(r2)
    lfd	f1, 0x100(r1)
    stw	r6, 0x10c(r1)
    fsub	f1, f1, f2
    lfd	f3, -0x7bb8(r2)
    stw	r5, 0x108(r1)
    lbz	r0, 4(r3)
    lfd	f2, 0x108(r1)
    fmul	f0, f1, f0
    fsub	f1, f2, f3
    fadd	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0xf8(r1)
    lwz	r4, 0xfc(r1)
    add	r3, r0, r4
    addi	r0, r3, -0x40
    extsh.	r4, r0
    bc      4, 0, _800621cc
    li	r4, 0
    b       _800621d8
_800621cc:
    cmpwi	r4, 0x7f
    bc      4, 1, _800621d8
    li	r4, 0x7f
_800621d8:
    lis     r3, lbl_80092B58@ha
    extsh	r0, r4
    addi	r3, r3, lbl_80092B58@l
    lfs	f1, 0x1c(r1)
    lbzx	r3, r3, r0
    addi	r5, r1, 0xc
    lha	r4, 8(r1)
    addi	r6, r1, 0xa
    bl      fn_8005DB68
    lwz	r0, -0x7740(r13)
    lha	r4, 0xc(r1)
    add	r3, r0, r19
    lwz	r3, 0x1434(r3)
    bl      fn_80026D90
    lwz	r0, -0x7740(r13)
    extsh	r15, r20
    mr	r4, r15
    add	r3, r0, r19
    lwz	r3, 0x1434(r3)
    bl      fn_80026F4C
    lbz	r0, 0(r17)
    fmr	f1, f31
    lwz	r3, -0x7740(r13)
    mulli	r14, r0, 0x118
    add	r3, r3, r14
    lwz	r3, 0x1434(r3)
    bl      fn_800234D0
    lwz	r0, -0x7740(r13)
    lha	r4, 0xa(r1)
    add	r3, r0, r14
    lwz	r3, 0x1434(r3)
    bl      fn_80026D90
    lwz	r0, -0x7740(r13)
    mr	r4, r15
    add	r3, r0, r14
    lwz	r3, 0x1434(r3)
    bl      fn_80026F4C
    lwz	r0, -0x7740(r13)
    lwz	r4, 0x18(r1)
    add	r3, r0, r14
    lwz	r3, 0x1434(r3)
    bl      fn_80026E2C
    lwz	r0, -0x7740(r13)
    lwz	r4, 0x14(r1)
    add	r3, r0, r14
    lwz	r3, 0x1434(r3)
    bl      fn_80026EAC
_80062294:
    psq_l	f31, 0x178(r1), 0, 0
    lfd	f31, 0x170(r1)
    lmw	r14, 0x128(r1)
    lwz	r0, 0x184(r1)
    mtlr	r0
    addi	r1, r1, 0x180
    blr
}

asm void fn_800622B0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r3, lbl_80192D68@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    li	r26, 0
    addi	r30, r3, lbl_80192D68@l
    b       _80062340
_800622d0:
    clrlwi	r0, r26, 0x18
    li	r25, 0
    mulli	r0, r0, 0x54
    li	r31, 0
    add	r27, r30, r0
    b       _80062328
_800622e8:
    rlwinm	r0, r25, 2, 0x16, 0x1d
    add	r29, r27, r0
    lbz	r0, 0x14(r29)
    addi	r28, r29, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062324
    lbz	r3, 0x16(r29)
    cmplwi	r3, 0xff
    bc      12, 2, _80062310
    bl      SndSetVoicePriority
_80062310:
    lbz	r3, 0x17(r29)
    cmplwi	r3, 0xff
    bc      12, 2, _80062320
    bl      SndSetVoicePriority
_80062320:
    stb	r31, 0(r28)
_80062324:
    addi	r25, r25, 1
_80062328:
    clrlwi	r0, r25, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800622e8
    li	r0, 0
    addi	r26, r26, 1
    stb	r0, 0xb(r27)
_80062340:
    clrlwi	r0, r26, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800622d0
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void SndStartVoice(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    li	r7, 0
    stw	r0, 0x44(r1)
    stmw	r19, 0xc(r1)
    mr	r31, r3
    lis     r3, lbl_80192D68@ha
    mr	r21, r4
    mulli	r26, r31, 0x54
    li	r23, -1
    addi	r0, r3, lbl_80192D68@l
    add	r25, r0, r26
    addi	r5, r25, 2
    lwz	r6, -0x7740(r13)
    mr	r4, r6
    b       _800623c0
_800623a0:
    lbz	r3, 0(r5)
    lbz	r0, 0xd(r4)
    cmplw	r3, r0
    bc      4, 2, _800623b8
    mr	r23, r7
    b       _800623cc
_800623b8:
    addi	r4, r4, 0x10
    addi	r7, r7, 1
_800623c0:
    extsb	r0, r7
    cmpwi	r0, 0x10
    bc      12, 0, _800623a0
_800623cc:
    extsb	r0, r23
    cmpwi	r0, -1
    bc      12, 2, _80062624
    lis     r3, lbl_80192D68@ha
    addi	r4, r3, lbl_80192D68@l
    add	r24, r4, r26
    lbzu	r22, 0xb(r24)
    cmplwi	r22, 0
    bc      12, 2, _800624a0
    add	r3, r4, r26
    lbz	r0, 1(r3)
    cmplwi	r0, 0
    bc      12, 2, _80062484
    clrlwi	r0, r31, 0x18
    lwz	r30, 0x10(r3)
    mulli	r0, r0, 0x54
    addi	r27, r25, 0xc
    li	r29, 0
    add	r28, r4, r0
    b       _80062468
_8006241c:
    rlwinm	r0, r29, 2, 0x16, 0x1d
    add	r20, r28, r0
    lbz	r0, 0x14(r20)
    addi	r19, r20, 0x14
    cmplwi	r0, 1
    bc      4, 2, _8006245c
    lbz	r3, 0x16(r20)
    cmplwi	r3, 0xff
    bc      12, 2, _80062444
    bl      SndSetVoicePriority
_80062444:
    lbz	r3, 0x17(r20)
    cmplwi	r3, 0xff
    bc      12, 2, _80062454
    bl      SndSetVoicePriority
_80062454:
    li	r0, 0
    stb	r0, 0(r19)
_8006245c:
    lbz	r0, 0(r30)
    addi	r29, r29, 1
    add	r30, r30, r0
_80062468:
    lbz	r0, 0(r27)
    clrlwi	r3, r29, 0x18
    cmplw	r3, r0
    bc      4, 1, _8006241c
    li	r0, 0
    stb	r0, 0(r24)
    b       _800624a0
_80062484:
    lwz	r12, 0x5b1c(r6)
    cmplwi	r12, 0
    bc      12, 2, _800624a0
    lwz	r4, 0x444(r6)
    li	r3, -5
    mtctr	r12
    bctrl
_800624a0:
    lis     r3, lbl_80192D68@ha
    extsb	r0, r23
    addi	r4, r3, lbl_80192D68@l
    lwz	r3, -0x7740(r13)
    add	r7, r4, r26
    slwi	r0, r0, 4
    li	r4, 1
    stbu	r4, 1(r7)
    add	r4, r3, r0
    lwz	r5, 8(r4)
    li	r4, 0
    lwz	r0, 0x2c(r5)
    add	r8, r5, r0
    mr	r5, r8
    b       _800624e4
_800624dc:
    addi	r5, r5, 4
    addi	r4, r4, 1
_800624e4:
    extsb	r0, r4
    cmplw	r0, r21
    bc      4, 1, _800624dc
    lwz	r0, 0(r5)
    lis     r4, lbl_80192D68@ha
    addi	r6, r4, lbl_80192D68@l
    cmplwi	r22, 0
    add	r9, r8, r0
    lbz	r4, 0(r9)
    add	r5, r6, r26
    addi	r0, r9, 8
    stb	r4, 0xc(r5)
    addi	r8, r5, 0x10
    lbz	r4, 1(r9)
    stb	r4, 0xd(r5)
    lbz	r4, 2(r9)
    stb	r4, 0xe(r5)
    lbz	r4, 3(r9)
    addi	r4, r4, 0x15
    stb	r4, 0xf(r5)
    stw	r0, 0x10(r5)
    stb	r23, 0(r25)
    bc      12, 2, _80062640
    lbz	r0, 0(r7)
    cmplwi	r0, 0
    bc      12, 2, _80062604
    clrlwi	r0, r31, 0x18
    lwz	r29, 0(r8)
    mulli	r0, r0, 0x54
    addi	r27, r25, 0xc
    li	r21, 0
    add	r23, r6, r0
    b       _800625ec
_80062568:
    lbz	r0, 4(r29)
    cmplw	r0, r22
    bc      12, 1, _800625a0
    lbz	r0, 5(r29)
    cmplw	r0, r22
    bc      12, 0, _800625a0
    cmplwi	r22, 0
    bc      12, 2, _800625a0
    mr	r4, r29
    mr	r6, r21
    clrlwi	r3, r22, 0x18
    clrlwi	r5, r31, 0x18
    bl      fn_80060C54
    b       _800625e0
_800625a0:
    rlwinm	r0, r21, 2, 0x16, 0x1d
    add	r19, r23, r0
    lbz	r0, 0x14(r19)
    addi	r20, r19, 0x14
    cmplwi	r0, 1
    bc      4, 2, _800625e0
    lbz	r3, 0x16(r19)
    cmplwi	r3, 0xff
    bc      12, 2, _800625c8
    bl      SndSetVoicePriority
_800625c8:
    lbz	r3, 0x17(r19)
    cmplwi	r3, 0xff
    bc      12, 2, _800625d8
    bl      SndSetVoicePriority
_800625d8:
    li	r0, 0
    stb	r0, 0(r20)
_800625e0:
    lbz	r0, 0(r29)
    addi	r21, r21, 1
    add	r29, r29, r0
_800625ec:
    lbz	r0, 0(r27)
    clrlwi	r3, r21, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062568
    stb	r22, 0(r24)
    b       _80062640
_80062604:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80062640
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80062640
_80062624:
    lwz	r12, 0x5b1c(r6)
    cmplwi	r12, 0
    bc      12, 2, _80062640
    lwz	r4, 0x444(r6)
    li	r3, -4
    mtctr	r12
    bctrl
_80062640:
    lmw	r19, 0xc(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr
}

asm void SndPlaySequenceNotes(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    lis	r0, -0x5a90
    stmw	r23, 0xc(r1)
    lwz	r3, -0x7740(r13)
    lwz	r4, 0x444(r3)
    andis.	r5, r4, 0xff70
    rlwinm	r31, r4, 0x10, 0x1c, 0x1f
    rlwinm	r29, r4, 0x18, 0x19, 0x1f
    cmpw	r5, r0
    bc      12, 2, _80062c5c
    bc      4, 0, _800626e8
    lis	r0, -0x5ad0
    cmpw	r5, r0
    bc      12, 2, _80062950
    bc      4, 0, _800626c8
    lis	r0, -0x5af0
    cmpw	r5, r0
    bc      12, 2, _80062748
    bc      4, 0, _800626b8
    lis	r0, -0x5b00
    cmpw	r5, r0
    bc      12, 2, _80062738
    b       _80063080
_800626b8:
    lis	r0, -0x5ae0
    cmpw	r5, r0
    bc      12, 2, _8006284c
    b       _80063080
_800626c8:
    lis	r0, -0x5ab0
    cmpw	r5, r0
    bc      12, 2, _80062b58
    bc      4, 0, _80063080
    lis	r0, -0x5ac0
    cmpw	r5, r0
    bc      12, 2, _80062a54
    b       _80063080
_800626e8:
    lis	r0, -0x5900
    cmpw	r5, r0
    bc      12, 2, _80062c74
    bc      4, 0, _80062718
    lis	r0, -0x59f0
    cmpw	r5, r0
    bc      12, 2, _80062e7c
    bc      4, 0, _80063080
    lis	r0, -0x5a00
    cmpw	r5, r0
    bc      12, 2, _80062e80
    b       _80063080
_80062718:
    lis	r0, -0x58e0
    cmpw	r5, r0
    bc      12, 2, _80062f70
    bc      4, 0, _80063080
    lis	r0, -0x58f0
    cmpw	r5, r0
    bc      12, 2, _80062d78
    b       _80063080
_80062738:
    mr	r3, r31
    mr	r4, r29
    bl      SndStartVoice
    b       _80063080
_80062748:
    mulli	r5, r31, 0x54
    lis     r4, lbl_80192D68@ha
    addi	r0, r4, lbl_80192D68@l
    add	r28, r0, r5
    stb	r29, 3(r28)
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r25, 0xb(r28)
    addi	r30, r28, 0xb
    cmplwi	r25, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _8006282c
    lwz	r26, 0x10(r28)
    addi	r29, r28, 0xc
    li	r27, 0
    b       _80062814
_80062790:
    lbz	r0, 4(r26)
    cmplw	r0, r25
    bc      12, 1, _800627c8
    lbz	r0, 5(r26)
    cmplw	r0, r25
    bc      12, 0, _800627c8
    cmplwi	r25, 0
    bc      12, 2, _800627c8
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r25, 0x18
    bl      fn_80060C54
    b       _80062808
_800627c8:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r28, r0
    lbz	r0, 0x14(r24)
    addi	r23, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062808
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _800627f0
    bl      SndSetVoicePriority
_800627f0:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062800
    bl      SndSetVoicePriority
_80062800:
    li	r0, 0
    stb	r0, 0(r23)
_80062808:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80062814:
    lbz	r0, 0(r29)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062790
    stb	r25, 0(r30)
    b       _80063080
_8006282c:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_8006284c:
    mulli	r5, r31, 0x54
    lis     r4, lbl_80192D68@ha
    addi	r0, r4, lbl_80192D68@l
    add	r28, r0, r5
    stb	r29, 4(r28)
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r23, 0xb(r28)
    addi	r30, r28, 0xb
    cmplwi	r23, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _80062930
    lwz	r26, 0x10(r28)
    addi	r29, r28, 0xc
    li	r27, 0
    b       _80062918
_80062894:
    lbz	r0, 4(r26)
    cmplw	r0, r23
    bc      12, 1, _800628cc
    lbz	r0, 5(r26)
    cmplw	r0, r23
    bc      12, 0, _800628cc
    cmplwi	r23, 0
    bc      12, 2, _800628cc
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r23, 0x18
    bl      fn_80060C54
    b       _8006290c
_800628cc:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r28, r0
    lbz	r0, 0x14(r24)
    addi	r25, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _8006290c
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _800628f4
    bl      SndSetVoicePriority
_800628f4:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062904
    bl      SndSetVoicePriority
_80062904:
    li	r0, 0
    stb	r0, 0(r25)
_8006290c:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80062918:
    lbz	r0, 0(r29)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062894
    stb	r23, 0(r30)
    b       _80063080
_80062930:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_80062950:
    mulli	r5, r31, 0x54
    lis     r4, lbl_80192D68@ha
    addi	r0, r4, lbl_80192D68@l
    add	r28, r0, r5
    stb	r29, 5(r28)
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r23, 0xb(r28)
    addi	r30, r28, 0xb
    cmplwi	r23, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _80062a34
    lwz	r26, 0x10(r28)
    addi	r29, r28, 0xc
    li	r27, 0
    b       _80062a1c
_80062998:
    lbz	r0, 4(r26)
    cmplw	r0, r23
    bc      12, 1, _800629d0
    lbz	r0, 5(r26)
    cmplw	r0, r23
    bc      12, 0, _800629d0
    cmplwi	r23, 0
    bc      12, 2, _800629d0
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r23, 0x18
    bl      fn_80060C54
    b       _80062a10
_800629d0:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r28, r0
    lbz	r0, 0x14(r24)
    addi	r25, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062a10
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _800629f8
    bl      SndSetVoicePriority
_800629f8:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062a08
    bl      SndSetVoicePriority
_80062a08:
    li	r0, 0
    stb	r0, 0(r25)
_80062a10:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80062a1c:
    lbz	r0, 0(r29)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062998
    stb	r23, 0(r30)
    b       _80063080
_80062a34:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_80062a54:
    mulli	r5, r31, 0x54
    lis     r4, lbl_80192D68@ha
    addi	r0, r4, lbl_80192D68@l
    add	r28, r0, r5
    stb	r29, 6(r28)
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r23, 0xb(r28)
    addi	r30, r28, 0xb
    cmplwi	r23, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _80062b38
    lwz	r26, 0x10(r28)
    addi	r29, r28, 0xc
    li	r27, 0
    b       _80062b20
_80062a9c:
    lbz	r0, 4(r26)
    cmplw	r0, r23
    bc      12, 1, _80062ad4
    lbz	r0, 5(r26)
    cmplw	r0, r23
    bc      12, 0, _80062ad4
    cmplwi	r23, 0
    bc      12, 2, _80062ad4
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r23, 0x18
    bl      fn_80060C54
    b       _80062b14
_80062ad4:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r28, r0
    lbz	r0, 0x14(r24)
    addi	r25, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062b14
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062afc
    bl      SndSetVoicePriority
_80062afc:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062b0c
    bl      SndSetVoicePriority
_80062b0c:
    li	r0, 0
    stb	r0, 0(r25)
_80062b14:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80062b20:
    lbz	r0, 0(r29)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062a9c
    stb	r23, 0(r30)
    b       _80063080
_80062b38:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_80062b58:
    mulli	r5, r31, 0x54
    lis     r4, lbl_80192D68@ha
    addi	r0, r4, lbl_80192D68@l
    add	r28, r0, r5
    stb	r29, 7(r28)
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r23, 0xb(r28)
    addi	r30, r28, 0xb
    cmplwi	r23, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _80062c3c
    lwz	r26, 0x10(r28)
    addi	r29, r28, 0xc
    li	r27, 0
    b       _80062c24
_80062ba0:
    lbz	r0, 4(r26)
    cmplw	r0, r23
    bc      12, 1, _80062bd8
    lbz	r0, 5(r26)
    cmplw	r0, r23
    bc      12, 0, _80062bd8
    cmplwi	r23, 0
    bc      12, 2, _80062bd8
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r23, 0x18
    bl      fn_80060C54
    b       _80062c18
_80062bd8:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r28, r0
    lbz	r0, 0x14(r24)
    addi	r25, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062c18
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062c00
    bl      SndSetVoicePriority
_80062c00:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062c10
    bl      SndSetVoicePriority
_80062c10:
    li	r0, 0
    stb	r0, 0(r25)
_80062c18:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80062c24:
    lbz	r0, 0(r29)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062ba0
    stb	r23, 0(r30)
    b       _80063080
_80062c3c:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_80062c5c:
    mulli	r0, r31, 0x54
    lis     r3, lbl_80192D68@ha
    addi	r3, r3, lbl_80192D68@l
    add	r3, r3, r0
    stb	r29, 2(r3)
    b       _80063080
_80062c74:
    mulli	r5, r31, 0x54
    lis     r4, lbl_80192D68@ha
    addi	r0, r4, lbl_80192D68@l
    add	r28, r0, r5
    stb	r29, 9(r28)
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r23, 0xb(r28)
    addi	r30, r28, 0xb
    cmplwi	r23, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _80062d58
    lwz	r26, 0x10(r28)
    addi	r29, r28, 0xc
    li	r27, 0
    b       _80062d40
_80062cbc:
    lbz	r0, 4(r26)
    cmplw	r0, r23
    bc      12, 1, _80062cf4
    lbz	r0, 5(r26)
    cmplw	r0, r23
    bc      12, 0, _80062cf4
    cmplwi	r23, 0
    bc      12, 2, _80062cf4
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r23, 0x18
    bl      fn_80060C54
    b       _80062d34
_80062cf4:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r28, r0
    lbz	r0, 0x14(r24)
    addi	r25, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062d34
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062d1c
    bl      SndSetVoicePriority
_80062d1c:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062d2c
    bl      SndSetVoicePriority
_80062d2c:
    li	r0, 0
    stb	r0, 0(r25)
_80062d34:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80062d40:
    lbz	r0, 0(r29)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062cbc
    stb	r23, 0(r30)
    b       _80063080
_80062d58:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_80062d78:
    mulli	r5, r31, 0x54
    lis     r4, lbl_80192D68@ha
    addi	r0, r4, lbl_80192D68@l
    add	r28, r0, r5
    stb	r29, 0xa(r28)
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r23, 0xb(r28)
    addi	r30, r28, 0xb
    cmplwi	r23, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _80062e5c
    lwz	r26, 0x10(r28)
    addi	r29, r28, 0xc
    li	r27, 0
    b       _80062e44
_80062dc0:
    lbz	r0, 4(r26)
    cmplw	r0, r23
    bc      12, 1, _80062df8
    lbz	r0, 5(r26)
    cmplw	r0, r23
    bc      12, 0, _80062df8
    cmplwi	r23, 0
    bc      12, 2, _80062df8
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r23, 0x18
    bl      fn_80060C54
    b       _80062e38
_80062df8:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r28, r0
    lbz	r0, 0x14(r24)
    addi	r25, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062e38
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062e20
    bl      SndSetVoicePriority
_80062e20:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80062e30
    bl      SndSetVoicePriority
_80062e30:
    li	r0, 0
    stb	r0, 0(r25)
_80062e38:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80062e44:
    lbz	r0, 0(r29)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062dc0
    stb	r23, 0(r30)
    b       _80063080
_80062e5c:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_80062e7c:
    addi	r29, r29, 0x80
_80062e80:
    mulli	r30, r31, 0x54
    lis     r5, lbl_80192D68@ha
    addi	r0, r5, lbl_80192D68@l
    add	r28, r0, r30
    lbz	r0, 1(r28)
    cmplwi	r0, 0
    bc      12, 2, _80062f54
    lwz	r27, 0x10(r28)
    addi	r25, r28, 0xc
    li	r26, 0
    b       _80062f30
_80062eac:
    lbz	r0, 4(r27)
    cmplw	r0, r29
    bc      12, 1, _80062ee4
    lbz	r0, 5(r27)
    cmplw	r0, r29
    bc      12, 0, _80062ee4
    cmplwi	r29, 0
    bc      12, 2, _80062ee4
    mr	r4, r27
    mr	r5, r31
    mr	r6, r26
    clrlwi	r3, r29, 0x18
    bl      fn_80060C54
    b       _80062f24
_80062ee4:
    rlwinm	r0, r26, 2, 0x16, 0x1d
    add	r23, r28, r0
    lbz	r0, 0x14(r23)
    addi	r24, r23, 0x14
    cmplwi	r0, 1
    bc      4, 2, _80062f24
    lbz	r3, 0x16(r23)
    cmplwi	r3, 0xff
    bc      12, 2, _80062f0c
    bl      SndSetVoicePriority
_80062f0c:
    lbz	r3, 0x17(r23)
    cmplwi	r3, 0xff
    bc      12, 2, _80062f1c
    bl      SndSetVoicePriority
_80062f1c:
    li	r0, 0
    stb	r0, 0(r24)
_80062f24:
    lbz	r0, 0(r27)
    addi	r26, r26, 1
    add	r27, r27, r0
_80062f30:
    lbz	r0, 0(r25)
    clrlwi	r3, r26, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062eac
    lis     r3, lbl_80192D68@ha
    addi	r0, r3, lbl_80192D68@l
    add	r3, r0, r30
    stb	r29, 0xb(r3)
    b       _80063080
_80062f54:
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    li	r3, -5
    mtctr	r12
    bctrl
    b       _80063080
_80062f70:
    slwi	r0, r31, 1
    lis     r4, lbl_80192D68@ha
    add	r5, r3, r0
    lha	r3, 0x5af4(r5)
    mulli	r6, r31, 0x54
    addi	r0, r4, lbl_80192D68@l
    sth	r3, 0x5a74(r5)
    add	r29, r0, r6
    lbz	r0, 1(r29)
    cmplwi	r0, 0
    bc      12, 2, _80063080
    lbz	r23, 0xb(r29)
    addi	r30, r29, 0xb
    cmplwi	r23, 0
    bc      12, 2, _80063080
    cmplwi	r0, 0
    bc      12, 2, _80063060
    lwz	r26, 0x10(r29)
    addi	r25, r29, 0xc
    li	r27, 0
    b       _80063048
_80062fc4:
    lbz	r0, 4(r26)
    cmplw	r0, r23
    bc      12, 1, _80062ffc
    lbz	r0, 5(r26)
    cmplw	r0, r23
    bc      12, 0, _80062ffc
    cmplwi	r23, 0
    bc      12, 2, _80062ffc
    mr	r4, r26
    mr	r5, r31
    mr	r6, r27
    clrlwi	r3, r23, 0x18
    bl      fn_80060C54
    b       _8006303c
_80062ffc:
    rlwinm	r0, r27, 2, 0x16, 0x1d
    add	r24, r29, r0
    lbz	r0, 0x14(r24)
    addi	r28, r24, 0x14
    cmplwi	r0, 1
    bc      4, 2, _8006303c
    lbz	r3, 0x16(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80063024
    bl      SndSetVoicePriority
_80063024:
    lbz	r3, 0x17(r24)
    cmplwi	r3, 0xff
    bc      12, 2, _80063034
    bl      SndSetVoicePriority
_80063034:
    li	r0, 0
    stb	r0, 0(r28)
_8006303c:
    lbz	r0, 0(r26)
    addi	r27, r27, 1
    add	r26, r26, r0
_80063048:
    lbz	r0, 0(r25)
    clrlwi	r3, r27, 0x18
    cmplw	r3, r0
    bc      4, 1, _80062fc4
    stb	r23, 0(r30)
    b       _80063080
_80063060:
    lwz	r3, -0x7740(r13)
    lwz	r12, 0x5b1c(r3)
    cmplwi	r12, 0
    bc      12, 2, _80063080
    lwz	r4, 0x444(r3)
    li	r3, -5
    mtctr	r12
    bctrl
_80063080:
    lmw	r23, 0xc(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_80063094(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lis	r0, -0x5ab0
    cmpw	r4, r0
    stw	r31, 0xc(r1)
    mr	r31, r5
    clrlwi	r5, r3, 0x1c
    stw	r30, 8(r1)
    rlwinm	r30, r3, 0x10, 0xc, 0xf
    add	r3, r30, r4
    bc      12, 2, _80063190
    bc      4, 0, _80063118
    lis	r0, -0x5ae0
    cmpw	r4, r0
    bc      12, 2, _80063190
    bc      4, 0, _800630f8
    lis	r0, -0x5af0
    cmpw	r4, r0
    bc      12, 2, _80063184
    bc      4, 0, _800631c8
    lis	r0, -0x5b00
    cmpw	r4, r0
    bc      12, 2, _80063158
    b       _800631c8
_800630f8:
    lis	r0, -0x5ac0
    cmpw	r4, r0
    bc      12, 2, _80063190
    bc      4, 0, _800631c8
    lis	r0, -0x5ad0
    cmpw	r4, r0
    bc      12, 2, _80063190
    b       _800631c8
_80063118:
    lis	r0, -0x58f0
    cmpw	r4, r0
    bc      12, 2, _80063190
    bc      4, 0, _80063148
    lis	r0, -0x5900
    cmpw	r4, r0
    bc      12, 2, _80063190
    bc      4, 0, _800631c8
    lis	r0, -0x5a00
    cmpw	r4, r0
    bc      12, 2, _800631a0
    b       _800631c8
_80063148:
    lis	r0, -0x58e0
    cmpw	r4, r0
    bc      12, 2, _800631b4
    b       _800631c8
_80063158:
    addis	r3, r30, -0x5a90
    rlwinm	r0, r31, 0, 0x11, 0x17
    add	r3, r3, r0
    bl      fn_80067898
    cmpwi	r3, 0
    bc      12, 2, _80063174
    b       _800631d4
_80063174:
    addis	r3, r30, -0x5b00
    rlwinm	r0, r31, 8, 0x11, 0x17
    add	r3, r3, r0
    b       _800631d0
_80063184:
    rlwinm	r0, r31, 8, 0x11, 0x17
    add	r3, r3, r0
    b       _800631d0
_80063190:
    addi	r0, r31, 0x40
    rlwinm	r0, r0, 8, 0x11, 0x17
    add	r3, r3, r0
    b       _800631d0
_800631a0:
    rlwinm	r0, r31, 0xd, 0xb, 0xb
    rlwinm	r4, r31, 8, 0x11, 0x17
    add	r3, r0, r3
    add	r3, r4, r3
    b       _800631d0
_800631b4:
    lwz	r4, -0x7740(r13)
    slwi	r0, r5, 1
    add	r4, r4, r0
    sth	r31, 0x5af4(r4)
    b       _800631d0
_800631c8:
    li	r3, -2
    b       _800631d4
_800631d0:
    bl      fn_80067898
_800631d4:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void SndInitProcTable(void)
{
    nofralloc
    lis     r3, lbl_80192D68@ha
    li	r10, 0
    addi	r5, r3, lbl_80192D68@l
    b       _8006330c
_800631fc:
    clrlwi	r0, r10, 0x18
    li	r7, 0xff
    mulli	r6, r0, 0x54
    li	r4, 0
    li	r3, 0x7f
    li	r0, 0x40
    add	r6, r5, r6
    li	r11, 0
    stb	r7, 0(r6)
    stb	r4, 1(r6)
    stb	r3, 3(r6)
    stb	r0, 4(r6)
    stb	r0, 5(r6)
    stb	r0, 6(r6)
    stb	r0, 7(r6)
    stb	r0, 9(r6)
    stb	r0, 0xa(r6)
    stb	r4, 0xb(r6)
    stb	r4, 0xc(r6)
    stb	r4, 0xd(r6)
    stb	r4, 0xe(r6)
    stb	r4, 0xf(r6)
    stw	r4, 0x10(r6)
    b       _800632fc
_8006325c:
    rlwinm	r0, r11, 2, 0x16, 0x1d
    li	r3, 0
    add	r4, r6, r0
    addi	r11, r11, 8
    stb	r3, 0x14(r4)
    li	r0, 0xff
    addi	r7, r4, 0x14
    addi	r8, r4, 0x15
    stb	r3, 0x15(r4)
    addi	r9, r4, 0x16
    stb	r0, 0x16(r4)
    stbu	r0, 0x17(r4)
    stb	r3, 4(r7)
    stb	r3, 4(r8)
    stb	r0, 4(r9)
    stb	r0, 4(r4)
    stb	r3, 8(r7)
    stb	r3, 8(r8)
    stb	r0, 8(r9)
    stb	r0, 8(r4)
    stb	r3, 0xc(r7)
    stb	r3, 0xc(r8)
    stb	r0, 0xc(r9)
    stb	r0, 0xc(r4)
    stb	r3, 0x10(r7)
    stb	r3, 0x10(r8)
    stb	r0, 0x10(r9)
    stb	r0, 0x10(r4)
    stb	r3, 0x14(r7)
    stb	r3, 0x14(r8)
    stb	r0, 0x14(r9)
    stb	r0, 0x14(r4)
    stb	r3, 0x18(r7)
    stb	r3, 0x18(r8)
    stb	r0, 0x18(r9)
    stb	r0, 0x18(r4)
    stb	r3, 0x1c(r7)
    stb	r3, 0x1c(r8)
    stb	r0, 0x1c(r9)
    stb	r0, 0x1c(r4)
_800632fc:
    clrlwi	r0, r11, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _8006325c
    addi	r10, r10, 1
_8006330c:
    clrlwi	r0, r10, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800631fc
    blr
}

asm void fn_8006331C(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    li	r8, 0xff
    stw	r0, 0x54(r1)
    clrlwi	r0, r3, 0x18
    cmplwi	r0, 0xff
    stw	r31, 0x4c(r1)
    stw	r30, 0x48(r1)
    stw	r29, 0x44(r1)
    mr	r29, r4
    stw	r28, 0x40(r1)
    mr	r28, r3
    bc      4, 2, _80063360
    bc      4, 2, _80063ed4
    clrlwi	r0, r29, 0x18
    cmplwi	r0, 0x7f
    bc      4, 2, _80063ed4
_80063360:
    clrlwi	r0, r29, 0x18
    cmplwi	r0, 0xff
    bc      12, 2, _80063ed4
    cmplwi	r0, 0x7f
    bc      12, 2, _80063dc0
    lwz	r6, -0x7740(r13)
    li	r0, 4
    clrlwi	r3, r28, 0x18
    li	r7, 0
    mr	r5, r6
    mtctr	r0
_8006338c:
    lwz	r4, 0(r5)
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _800633b0
    lbz	r0, 0xe(r5)
    cmplw	r3, r0
    bc      4, 2, _800633b0
    mr	r8, r7
    b       _80063434
_800633b0:
    lwz	r4, 0x10(r5)
    addi	r7, r7, 1
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _800633d8
    lbz	r0, 0x1e(r5)
    cmplw	r3, r0
    bc      4, 2, _800633d8
    mr	r8, r7
    b       _80063434
_800633d8:
    lwz	r4, 0x20(r5)
    addi	r7, r7, 1
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _80063400
    lbz	r0, 0x2e(r5)
    cmplw	r3, r0
    bc      4, 2, _80063400
    mr	r8, r7
    b       _80063434
_80063400:
    lwz	r4, 0x30(r5)
    addi	r7, r7, 1
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _80063428
    lbz	r0, 0x3e(r5)
    cmplw	r3, r0
    bc      4, 2, _80063428
    mr	r8, r7
    b       _80063434
_80063428:
    addi	r5, r5, 0x40
    addi	r7, r7, 1
    bc      16, 0, _8006338c
_80063434:
    cmplwi	r8, 0xff
    bc      12, 2, _80063ed4
    lbz	r3, 0x472(r6)
    clrlwi	r0, r28, 0x18
    cmplw	r3, r0
    bc      4, 2, _8006345c
    lbz	r3, 0x473(r6)
    clrlwi	r0, r29, 0x18
    cmplw	r3, r0
    bc      12, 2, _80063ed4
_8006345c:
    slwi	r0, r8, 4
    clrlwi	r4, r29, 0x18
    add	r3, r6, r0
    li	r5, 0
    lwz	r3, 8(r3)
    cmplwi	r4, 0
    lwz	r0, 0x30(r3)
    add	r8, r3, r0
    mr	r7, r8
    bc      12, 0, _800634d0
    addi	r0, r4, 1
    addi	r3, r4, -8
    cmplwi	r0, 8
    bc      4, 1, _800634b4
    addi	r0, r3, 8
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r3, 0
    bc      12, 0, _800634b4
_800634a8:
    addi	r7, r7, 0x20
    addi	r5, r5, 8
    bc      16, 0, _800634a8
_800634b4:
    addi	r0, r4, 1
    subf	r0, r5, r0
    mtctr	r0
    cmplw	r5, r4
    bc      12, 1, _800634d0
_800634c8:
    addi	r7, r7, 4
    bc      16, 0, _800634c8
_800634d0:
    lbz	r0, 0x470(r6)
    lwz	r3, 0(r7)
    cmpwi	r0, 2
    add	r31, r8, r3
    bc      12, 2, _80063524
    bc      4, 0, _800634f8
    cmpwi	r0, 0
    bc      12, 2, _80063504
    bc      4, 0, _80063514
    b       _80063540
_800634f8:
    cmpwi	r0, 4
    bc      4, 0, _80063540
    b       _80063534
_80063504:
    lis     r3, lbl_801939B4@ha
    addi	r3, r3, lbl_801939B4@l
    bl      fn_80024DF0
    b       _80063540
_80063514:
    lis     r3, lbl_80193680@ha
    addi	r3, r3, lbl_80193680@l
    bl      fn_80024378
    b       _80063540
_80063524:
    lis     r3, lbl_80193404@ha
    addi	r3, r3, lbl_80193404@l
    bl      fn_800253F0
    b       _80063540
_80063534:
    lis     r3, lbl_80193308@ha
    addi	r3, r3, lbl_80193308@l
    bl      fn_80025C70
_80063540:
    li	r3, 0
    li	r4, 0
    bl      fn_800211E0
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x471(r3)
    cmpwi	r0, 2
    bc      12, 2, _8006359c
    bc      4, 0, _80063570
    cmpwi	r0, 0
    bc      12, 2, _8006357c
    bc      4, 0, _8006358c
    b       _800635b8
_80063570:
    cmpwi	r0, 4
    bc      4, 0, _800635b8
    b       _800635ac
_8006357c:
    lis     r3, lbl_80193860@ha
    addi	r3, r3, lbl_80193860@l
    bl      fn_80024DF0
    b       _800635b8
_8006358c:
    lis     r3, lbl_801934A0@ha
    addi	r3, r3, lbl_801934A0@l
    bl      fn_80024378
    b       _800635b8
_8006359c:
    lis     r3, lbl_80193368@ha
    addi	r3, r3, lbl_80193368@l
    bl      fn_800253F0
    b       _800635b8
_800635ac:
    lis     r3, lbl_801932A8@ha
    addi	r3, r3, lbl_801932A8@l
    bl      fn_80025C70
_800635b8:
    li	r3, 0
    li	r4, 0
    bl      fn_800211EC
    lwz	r0, 0(r31)
    lwz	r3, -0x7740(r13)
    srwi	r0, r0, 0x18
    stb	r0, 0x470(r3)
    lwz	r0, 0(r31)
    lwz	r3, -0x7740(r13)
    rlwinm	r0, r0, 0x10, 0x18, 0x1f
    stb	r0, 0x471(r3)
    lwz	r3, -0x7740(r13)
    stb	r28, 0x472(r3)
    lwz	r3, -0x7740(r13)
    stb	r29, 0x473(r3)
    lwz	r3, -0x7740(r13)
    lwz	r3, 0x5b20(r3)
    cmpwi	r3, -1
    bc      4, 2, _80063610
    lwz	r3, -0x7fb0(r13)
    bl      fn_800090A4
    b       _80063614
_80063610:
    bl      fn_800090A4
_80063614:
    lwz	r5, -0x7740(r13)
    lbz	r0, 0x470(r5)
    cmpwi	r0, 2
    bc      12, 2, _80063878
    bc      4, 0, _80063638
    cmpwi	r0, 0
    bc      12, 2, _80063644
    bc      4, 0, _80063750
    b       _800639d8
_80063638:
    cmpwi	r0, 4
    bc      4, 0, _800639d8
    b       _800638f0
_80063644:
    lis     r4, lbl_801939B4@ha
    lis	r0, 0x4330
    addi	r6, r4, lbl_801939B4@l
    li	r4, 0
    stb	r4, 0x13c(r6)
    lfd	f2, -0x7b20(r2)
    lwz	r4, 4(r31)
    stw	r0, 8(r1)
    lfs	f1, -0x7b28(r2)
    stw	r4, 0xc(r1)
    lfd	f0, 8(r1)
    stw	r0, 0x10(r1)
    fsubs	f0, f0, f2
    stw	r0, 0x18(r1)
    fdivs	f0, f0, f1
    stw	r0, 0x20(r1)
    stw	r0, 0x28(r1)
    stfs	f0, 0x148(r6)
    lwz	r0, 8(r31)
    stw	r0, 0x14(r1)
    mulli	r4, r0, 0x180
    lfd	f0, 0x10(r1)
    addis	r7, r4, 1
    fsubs	f0, f0, f2
    addi	r7, r7, -0x32c8
    cmpw	r7, r3
    fdivs	f0, f0, f1
    stfs	f0, 0x150(r6)
    lwz	r0, 0xc(r31)
    stw	r0, 0x1c(r1)
    lfd	f0, 0x18(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x14c(r6)
    lwz	r0, 0x10(r31)
    stw	r0, 0x24(r1)
    lfd	f0, 0x20(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x140(r6)
    lwz	r0, 0x14(r31)
    stw	r0, 0x2c(r1)
    lfd	f0, 0x28(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x144(r6)
    bc      12, 1, _80063720
    mr	r3, r6
    bl      fn_80024D84
    lis     r3, fn_80024E3C@ha
    lis     r4, lbl_801939B4@ha
    addi	r3, r3, fn_80024E3C@l
    addi	r4, r4, lbl_801939B4@l
    bl      fn_800211E0
    b       _80063748
_80063720:
    li	r0, 0xff
    stb	r0, 0x470(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _80063748
    subf	r4, r3, r7
    li	r3, -1
    mtctr	r12
    bctrl
_80063748:
    li	r30, 0x14
    b       _800639d8
_80063750:
    lis     r4, lbl_80193680@ha
    lis	r0, 0x4330
    addi	r6, r4, lbl_80193680@l
    li	r4, 0
    stb	r4, 0x1c4(r6)
    lfd	f2, -0x7b20(r2)
    lwz	r4, 4(r31)
    stw	r0, 0x28(r1)
    lfs	f1, -0x7b28(r2)
    stw	r4, 0x2c(r1)
    lfd	f0, 0x28(r1)
    stw	r0, 0x20(r1)
    fsubs	f0, f0, f2
    stw	r0, 0x18(r1)
    fdivs	f0, f0, f1
    stw	r0, 0x10(r1)
    stw	r0, 8(r1)
    stw	r0, 0x30(r1)
    stfs	f0, 0x1d0(r6)
    lwz	r0, 8(r31)
    stw	r0, 0x24(r1)
    mulli	r4, r0, 0x180
    lfd	f0, 0x20(r1)
    addis	r7, r4, 1
    fsubs	f0, f0, f2
    addi	r7, r7, 0x3db0
    cmpw	r7, r3
    fdivs	f0, f0, f1
    stfs	f0, 0x1d8(r6)
    lwz	r0, 0xc(r31)
    stw	r0, 0x1c(r1)
    lfd	f0, 0x18(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1d4(r6)
    lwz	r0, 0x10(r31)
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1c8(r6)
    lwz	r0, 0x14(r31)
    stw	r0, 0xc(r1)
    lfd	f0, 8(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1cc(r6)
    lwz	r0, 0x18(r31)
    stw	r0, 0x34(r1)
    lfd	f0, 0x30(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1dc(r6)
    bc      12, 1, _80063848
    mr	r3, r6
    bl      fn_80024308
    lis     r3, fn_800243C4@ha
    lis     r4, lbl_80193680@ha
    addi	r3, r3, fn_800243C4@l
    addi	r4, r4, lbl_80193680@l
    bl      fn_800211E0
    b       _80063870
_80063848:
    li	r0, 0xff
    stb	r0, 0x470(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _80063870
    subf	r4, r3, r7
    li	r3, -1
    mtctr	r12
    bctrl
_80063870:
    li	r30, 0x18
    b       _800639d8
_80063878:
    lis     r4, lbl_80193404@ha
    lwz	r0, 4(r31)
    addi	r4, r4, lbl_80193404@l
    cmpwi	r3, 0x1680
    stw	r0, 0x90(r4)
    lwz	r0, 8(r31)
    stw	r0, 0x94(r4)
    lwz	r0, 0xc(r31)
    stw	r0, 0x98(r4)
    bc      12, 0, _800638c0
    mr	r3, r4
    bl      fn_800251F0
    lis     r3, fn_80025504@ha
    lis     r4, lbl_80193404@ha
    addi	r3, r3, fn_80025504@l
    addi	r4, r4, lbl_80193404@l
    bl      fn_800211E0
    b       _800638e8
_800638c0:
    li	r0, 0xff
    stb	r0, 0x470(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _800638e8
    subfic	r4, r3, 0x1680
    li	r3, -1
    mtctr	r12
    bctrl
_800638e8:
    li	r30, 0xc
    b       _800639d8
_800638f0:
    lwz	r0, 4(r31)
    lis     r4, lbl_80193308@ha
    addi	r4, r4, lbl_80193308@l
    lis	r7, -0x3333
    stw	r0, 0x3c(r4)
    slwi	r6, r0, 5
    addi	r9, r7, -0x3333
    lwz	r8, 8(r31)
    addi	r0, r6, -1
    mulhwu	r7, r9, r0
    stw	r8, 0x40(r4)
    slwi	r6, r8, 5
    lwz	r8, 0xc(r31)
    addi	r0, r6, -1
    stw	r8, 0x44(r4)
    slwi	r8, r8, 5
    srwi	r6, r7, 7
    lwz	r10, 0x10(r31)
    addi	r7, r8, -1
    mulhwu	r7, r9, r7
    stw	r10, 0x48(r4)
    lwz	r8, 0x14(r31)
    stw	r8, 0x4c(r4)
    mulhwu	r0, r9, r0
    srwi	r7, r7, 7
    lwz	r8, 0x18(r31)
    stw	r8, 0x50(r4)
    lwz	r8, 0x1c(r31)
    srwi	r0, r0, 7
    add	r0, r0, r7
    stw	r8, 0x54(r4)
    add	r0, r6, r0
    mulli	r6, r0, 0x280
    lwz	r0, 0x20(r31)
    stw	r0, 0x58(r4)
    cmpw	r6, r3
    lwz	r0, 0x24(r31)
    stw	r0, 0x5c(r4)
    bc      12, 1, _800639ac
    mr	r3, r4
    bl      fn_80025C28
    lis     r3, fn_80025854@ha
    lis     r4, lbl_80193308@ha
    addi	r3, r3, fn_80025854@l
    addi	r4, r4, lbl_80193308@l
    bl      fn_800211E0
    b       _800639d4
_800639ac:
    li	r0, 0xff
    stb	r0, 0x470(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _800639d4
    subf	r4, r3, r6
    li	r3, -1
    mtctr	r12
    bctrl
_800639d4:
    li	r30, 0x24
_800639d8:
    lwz	r3, -0x7740(r13)
    lwz	r3, 0x5b20(r3)
    cmpwi	r3, -1
    bc      4, 2, _800639f4
    lwz	r3, -0x7fb0(r13)
    bl      fn_800090A4
    b       _800639f8
_800639f4:
    bl      fn_800090A4
_800639f8:
    lwz	r5, -0x7740(r13)
    lbz	r0, 0x471(r5)
    cmpwi	r0, 2
    bc      12, 2, _80063c5c
    bc      4, 0, _80063a1c
    cmpwi	r0, 0
    bc      12, 2, _80063a28
    bc      4, 0, _80063b34
    b       _80063ed4
_80063a1c:
    cmpwi	r0, 4
    bc      4, 0, _80063ed4
    b       _80063cd4
_80063a28:
    lis     r4, lbl_80193860@ha
    lis	r0, 0x4330
    addi	r6, r4, lbl_80193860@l
    li	r4, 0
    stb	r4, 0x13c(r6)
    add	r8, r31, r30
    lfd	f2, -0x7b20(r2)
    lwz	r4, 4(r8)
    stw	r0, 0x30(r1)
    lfs	f1, -0x7b28(r2)
    stw	r4, 0x34(r1)
    lfd	f0, 0x30(r1)
    stw	r0, 0x28(r1)
    fsubs	f0, f0, f2
    stw	r0, 0x20(r1)
    fdivs	f0, f0, f1
    stw	r0, 0x18(r1)
    stw	r0, 0x10(r1)
    stfs	f0, 0x148(r6)
    lwz	r0, 8(r8)
    stw	r0, 0x2c(r1)
    mulli	r4, r0, 0x180
    lfd	f0, 0x28(r1)
    addis	r7, r4, 1
    fsubs	f0, f0, f2
    addi	r7, r7, -0x32c8
    cmpw	r7, r3
    fdivs	f0, f0, f1
    stfs	f0, 0x150(r6)
    lwz	r0, 0xc(r8)
    stw	r0, 0x24(r1)
    lfd	f0, 0x20(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x14c(r6)
    lwz	r0, 0x10(r8)
    stw	r0, 0x1c(r1)
    lfd	f0, 0x18(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x140(r6)
    lwz	r0, 0x14(r8)
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x144(r6)
    bc      12, 1, _80063b08
    mr	r3, r6
    bl      fn_80024D84
    lis     r3, fn_80024E3C@ha
    lis     r4, lbl_80193860@ha
    addi	r3, r3, fn_80024E3C@l
    addi	r4, r4, lbl_80193860@l
    bl      fn_800211EC
    b       _80063ed4
_80063b08:
    li	r0, 0xff
    stb	r0, 0x471(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _80063ed4
    subf	r4, r3, r7
    li	r3, -2
    mtctr	r12
    bctrl
    b       _80063ed4
_80063b34:
    lis     r4, lbl_801934A0@ha
    lis	r0, 0x4330
    addi	r6, r4, lbl_801934A0@l
    li	r4, 0
    stb	r4, 0x1c4(r6)
    add	r8, r31, r30
    lfd	f2, -0x7b20(r2)
    lwz	r4, 4(r8)
    stw	r0, 0x30(r1)
    lfs	f1, -0x7b28(r2)
    stw	r4, 0x34(r1)
    lfd	f0, 0x30(r1)
    stw	r0, 0x28(r1)
    fsubs	f0, f0, f2
    stw	r0, 0x20(r1)
    fdivs	f0, f0, f1
    stw	r0, 0x18(r1)
    stw	r0, 0x10(r1)
    stw	r0, 8(r1)
    stfs	f0, 0x1d0(r6)
    lwz	r0, 8(r8)
    stw	r0, 0x2c(r1)
    mulli	r4, r0, 0x180
    lfd	f0, 0x28(r1)
    addis	r7, r4, 1
    fsubs	f0, f0, f2
    addi	r7, r7, 0x3db0
    cmpw	r7, r3
    fdivs	f0, f0, f1
    stfs	f0, 0x1d8(r6)
    lwz	r0, 0xc(r8)
    stw	r0, 0x24(r1)
    lfd	f0, 0x20(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1d4(r6)
    lwz	r0, 0x10(r8)
    stw	r0, 0x1c(r1)
    lfd	f0, 0x18(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1c8(r6)
    lwz	r0, 0x14(r8)
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1cc(r6)
    lwz	r0, 0x18(r8)
    stw	r0, 0xc(r1)
    lfd	f0, 8(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f0, f1
    stfs	f0, 0x1dc(r6)
    bc      12, 1, _80063c30
    mr	r3, r6
    bl      fn_80024308
    lis     r3, fn_800243C4@ha
    lis     r4, lbl_801934A0@ha
    addi	r3, r3, fn_800243C4@l
    addi	r4, r4, lbl_801934A0@l
    bl      fn_800211EC
    b       _80063ed4
_80063c30:
    li	r0, 0xff
    stb	r0, 0x471(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _80063ed4
    subf	r4, r3, r7
    li	r3, -2
    mtctr	r12
    bctrl
    b       _80063ed4
_80063c5c:
    add	r6, r31, r30
    lis     r4, lbl_80193368@ha
    lwz	r0, 4(r6)
    addi	r4, r4, lbl_80193368@l
    cmpwi	r3, 0x1680
    stw	r0, 0x90(r4)
    lwz	r0, 8(r6)
    stw	r0, 0x94(r4)
    lwz	r0, 0xc(r6)
    stw	r0, 0x98(r4)
    bc      12, 0, _80063ca8
    mr	r3, r4
    bl      fn_800251F0
    lis     r3, fn_80025504@ha
    lis     r4, lbl_80193368@ha
    addi	r3, r3, fn_80025504@l
    addi	r4, r4, lbl_80193368@l
    bl      fn_800211EC
    b       _80063ed4
_80063ca8:
    li	r0, 0xff
    stb	r0, 0x471(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _80063ed4
    subfic	r4, r3, 0x1680
    li	r3, -2
    mtctr	r12
    bctrl
    b       _80063ed4
_80063cd4:
    add	r6, r31, r30
    lis     r4, lbl_801932A8@ha
    lwz	r0, 4(r6)
    addi	r4, r4, lbl_801932A8@l
    lis	r8, -0x3333
    stw	r0, 0x3c(r4)
    slwi	r7, r0, 5
    addi	r10, r8, -0x3333
    lwz	r9, 8(r6)
    addi	r0, r7, -1
    mulhwu	r8, r10, r0
    stw	r9, 0x40(r4)
    slwi	r7, r9, 5
    lwz	r9, 0xc(r6)
    addi	r0, r7, -1
    stw	r9, 0x44(r4)
    slwi	r9, r9, 5
    srwi	r7, r8, 7
    lwz	r11, 0x10(r6)
    addi	r8, r9, -1
    mulhwu	r8, r10, r8
    stw	r11, 0x48(r4)
    lwz	r9, 0x14(r6)
    stw	r9, 0x4c(r4)
    mulhwu	r0, r10, r0
    srwi	r8, r8, 7
    lwz	r9, 0x18(r6)
    stw	r9, 0x50(r4)
    lwz	r9, 0x1c(r6)
    srwi	r0, r0, 7
    add	r0, r0, r8
    stw	r9, 0x54(r4)
    add	r0, r7, r0
    mulli	r7, r0, 0x280
    lwz	r0, 0x20(r6)
    stw	r0, 0x58(r4)
    cmpw	r7, r3
    lwz	r0, 0x24(r6)
    stw	r0, 0x5c(r4)
    bc      12, 1, _80063d94
    mr	r3, r4
    bl      fn_80025C28
    lis     r3, fn_80025854@ha
    lis     r4, lbl_801932A8@ha
    addi	r3, r3, fn_80025854@l
    addi	r4, r4, lbl_801932A8@l
    bl      fn_800211EC
    b       _80063ed4
_80063d94:
    li	r0, 0xff
    stb	r0, 0x471(r5)
    lwz	r4, -0x7740(r13)
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _80063ed4
    subf	r4, r3, r7
    li	r3, -2
    mtctr	r12
    bctrl
    b       _80063ed4
_80063dc0:
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x470(r3)
    cmpwi	r0, 2
    bc      12, 2, _80063e10
    bc      4, 0, _80063de4
    cmpwi	r0, 0
    bc      12, 2, _80063df0
    bc      4, 0, _80063e00
    b       _80063e2c
_80063de4:
    cmpwi	r0, 4
    bc      4, 0, _80063e2c
    b       _80063e20
_80063df0:
    lis     r3, lbl_801939B4@ha
    addi	r3, r3, lbl_801939B4@l
    bl      fn_80024DF0
    b       _80063e2c
_80063e00:
    lis     r3, lbl_80193680@ha
    addi	r3, r3, lbl_80193680@l
    bl      fn_80024378
    b       _80063e2c
_80063e10:
    lis     r3, lbl_80193404@ha
    addi	r3, r3, lbl_80193404@l
    bl      fn_800253F0
    b       _80063e2c
_80063e20:
    lis     r3, lbl_80193308@ha
    addi	r3, r3, lbl_80193308@l
    bl      fn_80025C70
_80063e2c:
    li	r3, 0
    li	r4, 0
    bl      fn_800211E0
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x471(r3)
    cmpwi	r0, 2
    bc      12, 2, _80063e88
    bc      4, 0, _80063e5c
    cmpwi	r0, 0
    bc      12, 2, _80063e68
    bc      4, 0, _80063e78
    b       _80063ea4
_80063e5c:
    cmpwi	r0, 4
    bc      4, 0, _80063ea4
    b       _80063e98
_80063e68:
    lis     r3, lbl_80193860@ha
    addi	r3, r3, lbl_80193860@l
    bl      fn_80024DF0
    b       _80063ea4
_80063e78:
    lis     r3, lbl_801934A0@ha
    addi	r3, r3, lbl_801934A0@l
    bl      fn_80024378
    b       _80063ea4
_80063e88:
    lis     r3, lbl_80193368@ha
    addi	r3, r3, lbl_80193368@l
    bl      fn_800253F0
    b       _80063ea4
_80063e98:
    lis     r3, lbl_801932A8@ha
    addi	r3, r3, lbl_801932A8@l
    bl      fn_80025C70
_80063ea4:
    li	r3, 0
    li	r4, 0
    bl      fn_800211EC
    lwz	r3, -0x7740(r13)
    li	r0, 0xff
    stb	r0, 0x470(r3)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x471(r3)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x472(r3)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x473(r3)
_80063ed4:
    lwz	r0, 0x54(r1)
    lwz	r31, 0x4c(r1)
    lwz	r30, 0x48(r1)
    lwz	r29, 0x44(r1)
    lwz	r28, 0x40(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_80063EF4(void)
{
    nofralloc
    lwz	r6, -0x7740(r13)
    rlwinm	r0, r3, 5, 0x13, 0x1a
    add	r3, r6, r0
    lbz	r3, 0x599(r3)
    addic.	r3, r3, -0x40
    bc      4, 1, _80063f1c
    extsb	r0, r4
    addi	r3, r3, 1
    slwi	r4, r0, 8
    b       _80063f2c
_80063f1c:
    cmpwi	r3, 0
    bc      4, 0, _80063f2c
    extsb	r0, r5
    slwi	r4, r0, 8
_80063f2c:
    mullw	r0, r3, r4
    srawi	r3, r0, 6
    blr
}

asm void SndSendParamToChannelVoices(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    rlwinm	r5, r4, 6, 0x12, 0x19
    clrlwi	r6, r3, 0x10
    rlwinm	r4, r4, 4, 0x14, 0x1b
    stmw	r27, 0xc(r1)
    li	r8, 0
    lwz	r7, -0x7740(r13)
    lwz	r0, 0x444(r7)
    rlwinm	r0, r0, 0x18, 0x19, 0x1f
    extsb	r3, r0
    addi	r0, r3, -0x40
    extsb	r0, r0
    b       _80064124
_80063f6c:
    rlwinm	r3, r8, 2, 0x16, 0x1d
    li	r9, 0
    add	r3, r5, r3
    b       _80064114
_80063f7c:
    lwz	r28, -0x7740(r13)
    clrlwi	r7, r9, 0x18
    add	r7, r28, r7
    addi	r7, r7, 0xd88
    lbzx	r11, r3, r7
    cmplwi	r11, 0xff
    bc      12, 2, _80064110
    lis	r7, 1
    addi	r10, r7, -0x5ffc
    cmpw	r6, r10
    bc      12, 2, _8006405c
    bc      4, 0, _80063fc4
    cmpwi	r6, 0x11
    bc      12, 2, _80063fd4
    bc      4, 0, _80064110
    cmpwi	r6, 1
    bc      12, 2, _80063fd4
    b       _80064110
_80063fc4:
    addi	r7, r7, -0x5ff9
    cmpw	r6, r7
    bc      12, 2, _800640f0
    b       _80064110
_80063fd4:
    rlwinm	r27, r11, 5, 0x13, 0x1a
    add	r10, r28, r27
    lbz	r7, 0x589(r10)
    clrlwi.	r7, r7, 0x1f
    bc      4, 2, _80064110
    li	r7, 0x40
    addi	r30, r27, 0x59a
    stb	r7, 0x599(r10)
    li	r28, 0
    addi	r31, r27, 0x59b
    addi	r12, r27, 0x59c
    lwz	r29, -0x7740(r13)
    addi	r11, r27, 0x59d
    addi	r10, r27, 0x596
    addi	r7, r27, 0x597
    stbx	r28, r29, r30
    lwz	r30, -0x7740(r13)
    stbx	r28, r30, r31
    lwz	r31, -0x7740(r13)
    stbx	r28, r31, r12
    lwz	r12, -0x7740(r13)
    stbx	r28, r12, r11
    lwz	r11, -0x7740(r13)
    add	r12, r11, r27
    lwz	r28, 0x5a0(r12)
    lbz	r11, 0xb(r28)
    stb	r11, 0x590(r12)
    lbz	r12, 0xd(r28)
    lwz	r11, -0x7740(r13)
    stbx	r12, r11, r10
    lbz	r11, 0xe(r28)
    lwz	r10, -0x7740(r13)
    stbx	r11, r10, r7
    b       _80064110
_8006405c:
    rlwinm	r7, r11, 5, 0x13, 0x1a
    li	r12, 0
    add	r7, r28, r7
    lbz	r10, 0x589(r7)
    rlwinm.	r10, r10, 0, 0x1e, 0x1e
    bc      12, 2, _8006409c
    add	r10, r4, r28
    lbz	r27, 0x495(r10)
    lbz	r11, 0x493(r10)
    cmplwi	r27, 0x40
    bc      12, 2, _800640c0
    extsb	r10, r27
    addi	r10, r10, -0x40
    slwi	r10, r10, 1
    extsb	r12, r10
    b       _800640c0
_8006409c:
    add	r10, r4, r28
    lbz	r27, 0x494(r10)
    lbz	r11, 0x492(r10)
    cmplwi	r27, 0x40
    bc      12, 2, _800640c0
    extsb	r10, r27
    addi	r10, r10, -0x40
    slwi	r10, r10, 1
    extsb	r12, r10
_800640c0:
    extsb	r11, r11
    extsb	r10, r12
    add	r10, r11, r10
    extsh.	r10, r10
    bc      4, 0, _800640dc
    li	r10, 0
    b       _800640e8
_800640dc:
    cmpwi	r10, 0x7f
    bc      4, 1, _800640e8
    li	r10, 0x7f
_800640e8:
    stb	r10, 0x598(r7)
    b       _80064110
_800640f0:
    rlwinm	r7, r11, 5, 0x13, 0x1a
    add	r10, r28, r7
    lbz	r7, 0x589(r10)
    clrlwi.	r7, r7, 0x1f
    bc      4, 2, _80064110
    lbz	r7, 0x595(r10)
    add	r7, r7, r0
    stb	r7, 0x596(r10)
_80064110:
    addi	r9, r9, 1
_80064114:
    clrlwi	r7, r9, 0x18
    cmplwi	r7, 4
    bc      12, 0, _80063f7c
    addi	r8, r8, 1
_80064124:
    clrlwi	r3, r8, 0x18
    cmplwi	r3, 0x10
    bc      12, 0, _80063f6c
    lmw	r27, 0xc(r1)
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006413C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    li	r31, 0
    stw	r30, 8(r1)
    mr	r30, r3
    b       _80064184
_8006415c:
    lwz	r3, -0x7740(r13)
    rlwinm	r0, r31, 4, 0x14, 0x1b
    lwzx	r3, r3, r0
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _80064180
    mr	r3, r30
    mr	r4, r31
    bl      SndSendParamToChannelVoices
_80064180:
    addi	r31, r31, 1
_80064184:
    clrlwi	r0, r31, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _8006415c
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_800641A8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r4, -0x7740(r13)
    lwz	r4, 0x444(r4)
    rlwinm.	r0, r4, 0, 0x1b, 0x1b
    bc      12, 2, _80064210
    li	r31, 0
    b       _80064200
_800641d8:
    lwz	r3, -0x7740(r13)
    rlwinm	r0, r31, 4, 0x14, 0x1b
    lwzx	r3, r3, r0
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _800641fc
    mr	r3, r30
    mr	r4, r31
    bl      SndSendParamToChannelVoices
_800641fc:
    addi	r31, r31, 1
_80064200:
    clrlwi	r0, r31, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800641d8
    b       _80064218
_80064210:
    clrlwi	r4, r4, 0x1c
    bl      SndSendParamToChannelVoices
_80064218:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_80064230(void)
{
    nofralloc
    lwz	r8, -0x7740(r13)
    lwz	r7, 0x444(r8)
    rlwinm.	r0, r7, 0, 0x1b, 0x1b
    bc      12, 2, _80064328
    clrlwi	r5, r4, 0x10
    li	r9, 0
    b       _80064318
_8006424c:
    lwz	r6, -0x7740(r13)
    rlwinm	r0, r9, 4, 0x14, 0x1b
    clrlwi	r8, r9, 0x18
    add	r7, r6, r0
    lwz	r4, 0(r7)
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _80064314
    lis	r4, 1
    addi	r0, r4, -0x5fcc
    cmpw	r5, r0
    bc      12, 2, _800642dc
    bc      4, 0, _80064314
    addi	r0, r4, -0x5ffc
    cmpw	r5, r0
    bc      12, 2, _80064290
    b       _80064314
_80064290:
    clrlwi	r0, r3, 0x10
    lwz	r4, 0x444(r6)
    cmplwi	r0, 4
    rlwinm	r4, r4, 0x18, 0x19, 0x1f
    bc      4, 2, _800642ac
    stb	r4, 0x492(r7)
    b       _80064314
_800642ac:
    cmplwi	r0, 0xa005
    bc      4, 2, _800642bc
    stb	r4, 0x494(r7)
    b       _80064314
_800642bc:
    cmplwi	r0, 0xa010
    bc      4, 2, _800642cc
    stb	r4, 0x493(r7)
    b       _80064314
_800642cc:
    cmplwi	r0, 0xa011
    bc      4, 2, _80064314
    stb	r4, 0x495(r7)
    b       _80064314
_800642dc:
    clrlwi	r0, r3, 0x10
    cmplwi	r0, 0xa034
    bc      4, 2, _800642fc
    slwi	r0, r8, 1
    add	r4, r6, r0
    lha	r0, 0x5ab4(r4)
    sth	r0, 0x5a34(r4)
    b       _80064314
_800642fc:
    cmplwi	r0, 0xa040
    bc      4, 2, _80064314
    slwi	r0, r8, 1
    add	r4, r6, r0
    lha	r0, 0x5ad4(r4)
    sth	r0, 0x5a54(r4)
_80064314:
    addi	r9, r9, 1
_80064318:
    clrlwi	r0, r9, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _8006424c
    blr
_80064328:
    lis	r5, 1
    clrlwi	r4, r4, 0x10
    addi	r0, r5, -0x5fcc
    clrlwi	r6, r7, 0x1c
    cmpw	r4, r0
    bc      12, 2, _800643b8
    bgelr	
    addi	r0, r5, -0x5ffc
    cmpw	r4, r0
    bnelr	
    clrlwi	r0, r3, 0x10
    rlwinm	r4, r7, 0x18, 0x19, 0x1f
    cmplwi	r0, 4
    bc      4, 2, _80064370
    rlwinm	r0, r6, 4, 0x14, 0x1b
    add	r3, r8, r0
    stb	r4, 0x492(r3)
    blr
_80064370:
    cmplwi	r0, 0xa005
    bc      4, 2, _80064388
    rlwinm	r0, r6, 4, 0x14, 0x1b
    add	r3, r8, r0
    stb	r4, 0x494(r3)
    blr
_80064388:
    cmplwi	r0, 0xa010
    bc      4, 2, _800643a0
    rlwinm	r0, r6, 4, 0x14, 0x1b
    add	r3, r8, r0
    stb	r4, 0x493(r3)
    blr
_800643a0:
    cmplwi	r0, 0xa011
    bnelr	
    rlwinm	r0, r6, 4, 0x14, 0x1b
    add	r3, r8, r0
    stb	r4, 0x495(r3)
    blr
_800643b8:
    clrlwi	r0, r3, 0x10
    cmplwi	r0, 0xa034
    bc      4, 2, _800643d8
    rlwinm	r0, r6, 1, 0x17, 0x1e
    add	r3, r8, r0
    lha	r0, 0x5ab4(r3)
    sth	r0, 0x5a34(r3)
    blr
_800643d8:
    cmplwi	r0, 0xa040
    bnelr	
    rlwinm	r0, r6, 1, 0x17, 0x1e
    add	r3, r8, r0
    lha	r0, 0x5ad4(r3)
    sth	r0, 0x5a54(r3)
    blr
}

asm void SndTickChannels(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r23, 0xc(r1)
    clrlwi	r31, r3, 0x10
    li	r24, 0
    lwz	r4, -0x7740(r13)
    lwz	r4, 0x444(r4)
    rlwinm	r3, r4, 6, 0x16, 0x19
    rlwinm	r0, r4, 0xa, 0x1a, 0x1d
    clrlwi	r23, r4, 0x1c
    rlwinm	r29, r4, 0x18, 0x19, 0x1f
    rlwinm	r30, r4, 0x10, 0x19, 0x1f
    add	r28, r3, r0
    rlwinm	r27, r4, 4, 0x18, 0x1b
_80064430:
    lwz	r4, -0x7740(r13)
    add	r3, r4, r24
    addi	r0, r3, 0xd88
    lbzx	r26, r28, r0
    cmpwi	r26, 0xff
    bc      12, 2, _80064798
    lis	r3, 1
    stb	r23, 0x45b(r4)
    addi	r0, r3, -0x4ff6
    cmpw	r31, r0
    bc      12, 2, _80064704
    bc      4, 0, _800644b0
    addi	r0, r3, -0x4fff
    cmpw	r31, r0
    bc      12, 2, _800646c8
    bc      4, 0, _80064490
    addi	r0, r3, -0x7000
    cmpw	r31, r0
    bc      12, 2, _80064500
    bc      12, 0, _80064798
    addi	r0, r3, -0x5000
    cmpw	r31, r0
    bc      4, 0, _8006457c
    b       _80064798
_80064490:
    addi	r0, r3, -0x4ff9
    cmpw	r31, r0
    bc      12, 2, _800646f0
    bc      4, 0, _80064798
    addi	r0, r3, -0x4ffd
    cmpw	r31, r0
    bc      4, 0, _80064798
    b       _800646dc
_800644b0:
    addi	r0, r3, -0x4fc0
    cmpw	r31, r0
    bc      12, 2, _80064740
    bc      4, 0, _800644e0
    addi	r0, r3, -0x4ff2
    cmpw	r31, r0
    bc      12, 2, _8006472c
    bc      4, 0, _80064798
    addi	r0, r3, -0x4ff3
    cmpw	r31, r0
    bc      4, 0, _80064718
    b       _80064798
_800644e0:
    addi	r0, r3, -0x2000
    cmpw	r31, r0
    bc      12, 2, _80064788
    bc      4, 0, _80064798
    addi	r0, r3, -0x4000
    cmpw	r31, r0
    bc      12, 2, _80064774
    b       _80064798
_80064500:
    lwz	r0, -0x7740(r13)
    rlwinm	r25, r26, 5, 0x13, 0x1a
    add	r3, r0, r25
    lbz	r0, 0x589(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      12, 2, _80064798
    lwz	r3, 0x5a4(r3)
    cmplwi	r3, 0
    bc      12, 2, _80064798
    addi	r3, r3, 8
    mr	r4, r26
    bl      fn_8005DCEC
    lwz	r3, -0x7740(r13)
    addi	r0, r25, 0x5a4
    mr	r4, r26
    lwzx	r3, r3, r0
    addi	r3, r3, 0xa
    bl      fn_8005DCEC
    lwz	r3, -0x7740(r13)
    addi	r0, r25, 0x5a4
    mr	r4, r26
    lwzx	r3, r3, r0
    addi	r3, r3, 0xc
    bl      fn_8005DCEC
    lwz	r3, -0x7740(r13)
    addi	r0, r25, 0x5a4
    mr	r4, r26
    lwzx	r3, r3, r0
    addi	r3, r3, 0xe
    bl      fn_8005DCEC
    b       _80064798
_8006457c:
    rlwinm	r5, r26, 5, 0x13, 0x1a
    lwz	r3, -0x7740(r13)
    addi	r0, r5, 0x58c
    stbx	r29, r3, r0
    lwz	r4, -0x7740(r13)
    add	r3, r4, r5
    addi	r4, r4, 8
    lbz	r0, 0x589(r3)
    lwzx	r4, r27, r4
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bc      12, 2, _800645cc
    lwz	r0, 0x28(r4)
    cmplwi	r0, 0
    bc      12, 2, _800645c0
    add	r0, r4, r0
    stw	r0, 0x5a4(r3)
    b       _80064798
_800645c0:
    li	r0, 0
    stw	r0, 0x5a4(r3)
    b       _80064798
_800645cc:
    lbz	r7, 0x58c(r3)
    li	r5, 0
    lwz	r0, 0x1c(r4)
    cmplwi	r7, 0
    add	r8, r4, r0
    mr	r4, r8
    bc      12, 0, _80064638
    addi	r0, r7, 1
    addi	r6, r7, -8
    cmplwi	r0, 8
    bc      4, 1, _80064618
    addi	r0, r6, 8
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r6, 0
    bc      12, 0, _80064618
_8006460c:
    addi	r4, r4, 0x10
    addi	r5, r5, 8
    bc      16, 0, _8006460c
_80064618:
    addi	r0, r7, 1
    subf	r0, r5, r0
    mtctr	r0
    cmplw	r5, r7
    bc      12, 1, _80064638
_8006462c:
    addi	r4, r4, 2
    addi	r5, r5, 1
    bc      16, 0, _8006462c
_80064638:
    lbz	r6, 0x58d(r3)
    li	r9, 0
    lhz	r0, 0(r4)
    cmplwi	r6, 0
    add	r4, r8, r0
    mr	r7, r4
    bc      12, 0, _800646a4
    addi	r0, r6, 1
    addi	r5, r6, -8
    cmplwi	r0, 8
    bc      4, 1, _80064684
    addi	r0, r5, 8
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r5, 0
    bc      12, 0, _80064684
_80064678:
    addi	r7, r7, 0x10
    addi	r9, r9, 8
    bc      16, 0, _80064678
_80064684:
    addi	r0, r6, 1
    subf	r0, r9, r0
    mtctr	r0
    cmplw	r9, r6
    bc      12, 1, _800646a4
_80064698:
    addi	r7, r7, 2
    addi	r9, r9, 1
    bc      16, 0, _80064698
_800646a4:
    lhz	r0, 0(r7)
    cmplwi	r0, 0
    bc      12, 2, _800646bc
    add	r0, r0, r4
    stw	r0, 0x5a4(r3)
    b       _80064798
_800646bc:
    li	r0, 0
    stw	r0, 0x5a4(r3)
    b       _80064798
_800646c8:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x59b
    stbx	r29, r4, r0
    b       _80064798
_800646dc:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x59c
    stbx	r29, r4, r0
    b       _80064798
_800646f0:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x58f
    stbx	r29, r4, r0
    b       _80064798
_80064704:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x590
    stbx	r29, r4, r0
    b       _80064798
_80064718:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x593
    stbx	r29, r4, r0
    b       _80064798
_8006472c:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x594
    stbx	r29, r4, r0
    b       _80064798
_80064740:
    cmplwi	r29, 0x40
    bc      12, 0, _8006475c
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x59a
    stbx	r29, r4, r0
    b       _80064798
_8006475c:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x59a
    li	r3, 0
    stbx	r3, r4, r0
    b       _80064798
_80064774:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x58d
    stbx	r30, r4, r0
    b       _80064798
_80064788:
    rlwinm	r3, r26, 5, 0x13, 0x1a
    lwz	r4, -0x7740(r13)
    addi	r0, r3, 0x599
    stbx	r29, r4, r0
_80064798:
    addi	r24, r24, 1
    cmplwi	r24, 4
    bc      12, 0, _80064430
    lmw	r23, 0xc(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void SndRefreshChannelVoices(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    li	r0, 0xf
    lwz	r4, -0x7740(r13)
    lwz	r4, 0x444(r4)
    rlwinm	r4, r4, 0x1c, 0x1f, 0x1f
    neg	r4, r4
    andc	r4, r0, r4
    bl      SndUpdateVoices
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_800647F0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    li	r30, 0
    lwz	r6, -0x7740(r13)
    b       _80064944
_80064810:
    clrlwi	r7, r30, 0x18
    lwz	r0, 0x14(r3)
    mulli	r31, r7, 0x118
    add	r5, r6, r31
    lwz	r4, 0x142c(r5)
    cmplw	r4, r0
    bc      4, 2, _80064940
    lbz	r0, 0x1408(r5)
    cmplwi	r0, 0xff
    bc      12, 2, _80064940
    cmplwi	r0, 3
    bc      4, 2, _8006484c
    mr	r3, r7
    bl      SndClearVoiceSlot
    b       _80064858
_8006484c:
    addi	r3, r31, 0x1438
    add	r3, r6, r3
    bl      fn_80028424
_80064858:
    lwz	r0, -0x7740(r13)
    li	r5, 0
    li	r4, 0xff
    add	r3, r0, r31
    stw	r5, 0x1434(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stb	r4, 0x1408(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stw	r5, 0x1420(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stb	r5, 0x1409(r3)
    lwz	r5, -0x7740(r13)
    addi	r7, r5, 0x1411
    lbzx	r6, r7, r31
    cmplwi	r6, 0xff
    bc      4, 2, _800648b4
    add	r3, r5, r31
    lbz	r0, 0x1412(r3)
    cmplwi	r0, 0xff
    bc      12, 2, _80064920
_800648b4:
    clrlwi	r4, r30, 0x18
    cmplw	r6, r4
    bc      4, 2, _800648ec
    add	r3, r5, r31
    li	r4, 0xff
    lbz	r0, 0x1412(r3)
    mulli	r0, r0, 0x118
    stbx	r4, r7, r0
    lwz	r3, -0x7740(r13)
    addi	r3, r3, 0x1412
    lbzx	r0, r3, r31
    mulli	r0, r0, 0x118
    stbx	r4, r3, r0
    b       _80064920
_800648ec:
    add	r3, r5, r31
    lbz	r0, 0x1412(r3)
    cmplw	r0, r4
    bc      4, 2, _80064920
    mulli	r0, r6, 0x118
    li	r4, 0xff
    stbx	r4, r7, r0
    lwz	r5, -0x7740(r13)
    add	r3, r5, r31
    lbz	r0, 0x1411(r3)
    mulli	r0, r0, 0x118
    add	r3, r5, r0
    stb	r4, 0x1412(r3)
_80064920:
    lwz	r0, -0x7740(r13)
    li	r4, 0xff
    add	r3, r0, r31
    stb	r4, 0x1411(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    stb	r4, 0x1412(r3)
    b       _80064950
_80064940:
    addi	r30, r30, 1
_80064944:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 0x40
    bc      12, 0, _80064810
_80064950:
    lwz	r0, 0x14(r1)
    li	r3, 0
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void SndSwapVoice(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, fn_800647F0@ha
    clrlwi	r3, r3, 0x18
    stw	r0, 0x14(r1)
    addi	r4, r4, fn_800647F0@l
    stw	r31, 0xc(r1)
    li	r31, -1
    lwz	r5, -0x7740(r13)
    lwz	r5, 0x44c(r5)
    bl      AXAcquireVoice
    cmplwi	r3, 0
    bc      12, 2, _800649f4
    lwz	r4, -0x7740(r13)
    li	r7, 0
    b       _800649e8
_800649ac:
    clrlwi	r5, r7, 0x18
    mulli	r6, r5, 0x118
    addi	r0, r6, 0x1408
    lbzx	r0, r4, r0
    cmplwi	r0, 0xff
    bc      4, 2, _800649e4
    add	r4, r4, r6
    mr	r31, r5
    stw	r3, 0x1434(r4)
    lwz	r4, -0x7740(r13)
    lwz	r0, 0x44c(r4)
    add	r4, r4, r6
    stw	r0, 0x142c(r4)
    b       _800649f4
_800649e4:
    addi	r7, r7, 1
_800649e8:
    clrlwi	r0, r7, 0x18
    cmplwi	r0, 0x40
    bc      12, 0, _800649ac
_800649f4:
    lwz	r5, -0x7740(r13)
    cmplwi	r3, 0
    lwz	r4, 0x44c(r5)
    addi	r0, r4, 1
    stw	r0, 0x44c(r5)
    bc      12, 2, _80064a18
    cmpwi	r31, -1
    bc      4, 2, _80064a18
    bl      AXFreeVoice
_80064a18:
    lwz	r0, 0x14(r1)
    mr	r3, r31
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void SndUpdateVoices(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    clrlwi	r30, r3, 0x10
    stw	r29, 0x14(r1)
    li	r29, 0
    stw	r28, 0x10(r1)
    mr	r28, r4
_80064a5c:
    lwz	r3, -0x7740(r13)
    add	r5, r3, r31
    lbz	r4, 0x1408(r5)
    cmplwi	r4, 0xff
    bc      12, 2, _80064d1c
    cmplwi	r4, 3
    bc      12, 2, _80064d1c
    cmplwi	r4, 4
    bc      12, 2, _80064d1c
    lwz	r6, 0x444(r3)
    lwz	r7, 0x1420(r5)
    and	r3, r6, r28
    and	r0, r7, r28
    cmplw	r3, r0
    bc      4, 2, _80064d1c
    lis	r3, 1
    addi	r0, r3, -0x5fc0
    cmpw	r30, r0
    bc      12, 2, _80064c00
    bc      4, 0, _80064b44
    addi	r0, r3, -0x5ff9
    cmpw	r30, r0
    bc      12, 2, _80064c20
    bc      4, 0, _80064b08
    addi	r0, r3, -0x5ffe
    cmpw	r30, r0
    bc      12, 2, _80064c0c
    bc      4, 0, _80064aec
    addi	r0, r3, -0x8000
    cmpw	r30, r0
    bc      12, 2, _80064bc4
    bc      12, 0, _80064d1c
    addi	r0, r3, -0x5fff
    cmpw	r30, r0
    bc      4, 0, _80064c00
    b       _80064d1c
_80064aec:
    addi	r0, r3, -0x5ffa
    cmpw	r30, r0
    bc      4, 0, _80064d1c
    addi	r0, r3, -0x5ffc
    cmpw	r30, r0
    bc      4, 0, _80064c00
    b       _80064d1c
_80064b08:
    addi	r0, r3, -0x5fe4
    cmpw	r30, r0
    bc      12, 2, _80064c2c
    bc      4, 0, _80064b34
    addi	r0, r3, -0x5fee
    cmpw	r30, r0
    bc      4, 0, _80064d1c
    addi	r0, r3, -0x5ff0
    cmpw	r30, r0
    bc      4, 0, _80064c00
    b       _80064d1c
_80064b34:
    addi	r0, r3, -0x5fcc
    cmpw	r30, r0
    bc      12, 2, _80064c00
    b       _80064d1c
_80064b44:
    addi	r0, r3, -0x4ff3
    cmpw	r30, r0
    bc      12, 2, _80064c88
    bc      4, 0, _80064b94
    addi	r0, r3, -0x4ff9
    cmpw	r30, r0
    bc      12, 2, _80064c60
    bc      4, 0, _80064b84
    addi	r0, r3, -0x4ffe
    cmpw	r30, r0
    bc      12, 2, _80064c50
    bc      4, 0, _80064d1c
    addi	r0, r3, -0x4fff
    cmpw	r30, r0
    bc      4, 0, _80064c40
    b       _80064d1c
_80064b84:
    addi	r0, r3, -0x4ff6
    cmpw	r30, r0
    bc      12, 2, _80064c6c
    b       _80064d1c
_80064b94:
    addi	r0, r3, -0x4f88
    cmpw	r30, r0
    bc      12, 2, _80064cf8
    bc      4, 0, _80064bb4
    addi	r0, r3, -0x4fc0
    cmpw	r30, r0
    bc      12, 2, _80064ca4
    b       _80064d1c
_80064bb4:
    addi	r0, r3, -0x2000
    cmpw	r30, r0
    bc      12, 2, _80064d14
    b       _80064d1c
_80064bc4:
    lbz	r0, 0x1409(r5)
    cmplwi	r0, 1
    bc      4, 2, _80064d1c
    lbz	r3, 0x140b(r5)
    rlwinm	r0, r3, 0, 0x1c, 0x1c
    cmpwi	r0, 8
    bc      12, 2, _80064d1c
    clrlwi.	r0, r3, 0x1f
    bc      12, 2, _80064bf4
    ori	r0, r3, 2
    stb	r0, 0x140b(r5)
    b       _80064d1c
_80064bf4:
    mr	r3, r29
    bl      SndSetVoicePriority
    b       _80064d1c
_80064c00:
    mr	r3, r29
    bl      fn_8005C9D8
    b       _80064d1c
_80064c0c:
    cmplwi	r4, 1
    bc      4, 2, _80064d1c
    mr	r3, r29
    bl      SndKillChannelVoice
    b       _80064d1c
_80064c20:
    mr	r3, r29
    bl      SndApplyChannelPan
    b       _80064d1c
_80064c2c:
    cmplwi	r4, 1
    bc      4, 2, _80064d1c
    mr	r3, r29
    bl      fn_8005C9D8
    b       _80064d1c
_80064c40:
    mr	r3, r29
    li	r4, 1
    bl      fn_8005C298
    b       _80064d1c
_80064c50:
    mr	r3, r29
    li	r4, 2
    bl      fn_8005C298
    b       _80064d1c
_80064c60:
    mr	r3, r29
    bl      fn_8005C9D8
    b       _80064d1c
_80064c6c:
    lwz	r3, 0x1424(r5)
    lbz	r0, 6(r3)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      12, 2, _80064d1c
    mr	r3, r29
    bl      fn_8005C7C0
    b       _80064d1c
_80064c88:
    lwz	r3, 0x1424(r5)
    lbz	r0, 0x15(r3)
    cmplwi	r0, 0
    bc      12, 2, _80064d1c
    mr	r3, r29
    bl      fn_8005C5C8
    b       _80064d1c
_80064ca4:
    lbz	r0, 0x140b(r5)
    rlwinm	r0, r0, 0, 0x18, 0x1e
    stb	r0, 0x140b(r5)
    lwz	r4, -0x7740(r13)
    add	r5, r4, r31
    lbz	r0, 0x140a(r5)
    slwi	r3, r0, 5
    addi	r0, r3, 0x59a
    lbzx	r0, r4, r0
    cmplwi	r0, 0
    bc      12, 2, _80064ce0
    lbz	r0, 0x140b(r5)
    ori	r0, r0, 1
    stb	r0, 0x140b(r5)
    b       _80064d1c
_80064ce0:
    lbz	r0, 0x140b(r5)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bc      12, 2, _80064d1c
    mr	r3, r29
    bl      SndSetVoicePriority
    b       _80064d1c
_80064cf8:
    rlwinm	r3, r7, 0, 4, 7
    rlwinm	r0, r6, 0, 4, 7
    cmplw	r3, r0
    bc      4, 2, _80064d1c
    mr	r3, r29
    bl      SndKillChannelVoice
    b       _80064d1c
_80064d14:
    mr	r3, r29
    bl      SndApplyChannelPan
_80064d1c:
    addi	r29, r29, 1
    addi	r31, r31, 0x118
    cmplwi	r29, 0x40
    bc      12, 0, _80064a5c
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void SndReleaseProcsForVoices(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    rlwinm	r0, r3, 6, 0x12, 0x19
    li	r6, 0
    stmw	r25, 0x14(r1)
    b       _80064e6c
_80064d60:
    rlwinm	r3, r6, 2, 0x16, 0x1d
    li	r7, 0
    add	r3, r0, r3
    b       _80064e5c
_80064d70:
    lwz	r9, -0x7740(r13)
    clrlwi	r5, r7, 0x18
    add	r8, r9, r5
    addi	r8, r8, 0xd88
    lbzx	r8, r3, r8
    cmplwi	r8, 0xff
    bc      12, 2, _80064e58
    rlwinm	r26, r8, 5, 0x13, 0x1a
    li	r10, 0
    add	r9, r9, r26
    lbz	r8, 0x589(r9)
    clrlwi.	r8, r8, 0x1f
    bc      12, 2, _80064db4
    clrlwi.	r8, r4, 0x18
    bc      4, 2, _80064dc4
    li	r10, 1
    b       _80064dc4
_80064db4:
    clrlwi	r8, r4, 0x18
    cmplwi	r8, 1
    bc      4, 2, _80064dc4
    li	r10, 1
_80064dc4:
    clrlwi.	r8, r10, 0x18
    bc      12, 2, _80064e58
    li	r25, 0
    addi	r8, r26, 0x589
    stb	r25, 0x588(r9)
    addi	r27, r26, 0x5a0
    addi	r28, r26, 0x5a4
    addi	r30, r26, 0x58a
    lwz	r9, -0x7740(r13)
    addi	r31, r26, 0x599
    li	r29, 0x40
    addi	r12, r26, 0x59a
    stbx	r25, r9, r8
    addi	r11, r26, 0x59b
    addi	r10, r26, 0x59c
    addi	r8, r26, 0x59d
    lwz	r26, -0x7740(r13)
    li	r9, 0xff
    stwx	r25, r26, r27
    lwz	r27, -0x7740(r13)
    stwx	r25, r27, r28
    lwz	r28, -0x7740(r13)
    stbx	r25, r28, r30
    lwz	r30, -0x7740(r13)
    stbx	r29, r30, r31
    lwz	r31, -0x7740(r13)
    stbx	r25, r31, r12
    lwz	r12, -0x7740(r13)
    stbx	r25, r12, r11
    lwz	r11, -0x7740(r13)
    stbx	r25, r11, r10
    lwz	r10, -0x7740(r13)
    stbx	r25, r10, r8
    lwz	r8, -0x7740(r13)
    add	r5, r8, r5
    addi	r5, r5, 0xd88
    stbx	r9, r3, r5
_80064e58:
    addi	r7, r7, 1
_80064e5c:
    clrlwi	r5, r7, 0x18
    cmplwi	r5, 4
    bc      12, 0, _80064d70
    addi	r6, r6, 1
_80064e6c:
    clrlwi	r3, r6, 0x18
    cmplwi	r3, 0x10
    bc      12, 0, _80064d60
    lmw	r25, 0x14(r1)
    addi	r1, r1, 0x30
    blr
}

asm void fn_80064E84(void)
{
    nofralloc
    lwz	r5, -0x7740(r13)
    rlwinm	r6, r4, 5, 0x13, 0x1a
    rlwinm	r4, r3, 4, 0x14, 0x1b
    add	r3, r5, r6
    lbz	r0, 0x589(r3)
    add	r4, r5, r4
    lwz	r4, 8(r4)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bc      12, 2, _80064ecc
    lwz	r0, 0x28(r4)
    cmplwi	r0, 0
    bc      12, 2, _80064ec0
    add	r0, r4, r0
    stw	r0, 0x5a4(r3)
    blr
_80064ec0:
    li	r0, 0
    stw	r0, 0x5a4(r3)
    blr
_80064ecc:
    lbz	r3, 0x58c(r3)
    li	r7, 0
    lwz	r0, 0x1c(r4)
    cmplwi	r3, 0
    add	r4, r4, r0
    mr	r8, r4
    bc      12, 0, _80064f3c
    addi	r0, r3, 1
    addi	r3, r3, -8
    cmplwi	r0, 8
    bc      4, 1, _80064f18
    addi	r0, r3, 8
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r3, 0
    bc      12, 0, _80064f18
_80064f0c:
    addi	r8, r8, 0x10
    addi	r7, r7, 8
    bc      16, 0, _80064f0c
_80064f18:
    addi	r0, r6, 0x58c
    lbzx	r3, r5, r0
    addi	r0, r3, 1
    subf	r0, r7, r0
    mtctr	r0
    cmplw	r7, r3
    bc      12, 1, _80064f3c
_80064f34:
    addi	r8, r8, 2
    bc      16, 0, _80064f34
_80064f3c:
    add	r3, r5, r6
    lhz	r0, 0(r8)
    lbz	r3, 0x58d(r3)
    li	r7, 0
    add	r8, r4, r0
    cmplwi	r3, 0
    mr	r4, r8
    bc      12, 0, _80064fb0
    addi	r0, r3, 1
    addi	r3, r3, -8
    cmplwi	r0, 8
    bc      4, 1, _80064f8c
    addi	r0, r3, 8
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r3, 0
    bc      12, 0, _80064f8c
_80064f80:
    addi	r4, r4, 0x10
    addi	r7, r7, 8
    bc      16, 0, _80064f80
_80064f8c:
    addi	r0, r6, 0x58d
    lbzx	r3, r5, r0
    addi	r0, r3, 1
    subf	r0, r7, r0
    mtctr	r0
    cmplw	r7, r3
    bc      12, 1, _80064fb0
_80064fa8:
    addi	r4, r4, 2
    bc      16, 0, _80064fa8
_80064fb0:
    lhz	r0, 0(r4)
    cmplwi	r0, 0
    bc      12, 2, _80064fcc
    add	r0, r0, r8
    add	r3, r5, r6
    stw	r0, 0x5a4(r3)
    blr
_80064fcc:
    add	r3, r5, r6
    li	r0, 0
    stw	r0, 0x5a4(r3)
    blr
}

asm void fn_80064FDC(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    addi	r10, r4, 8
    li	r7, 0
    stmw	r18, 8(r1)
    lbz	r8, 0(r4)
    rlwinm	r4, r3, 4, 0x14, 0x1b
    rlwinm	r3, r3, 6, 0x12, 0x19
    b       _80065378
_80064ffc:
    lbz	r0, 0(r10)
    li	r9, 0xff
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      12, 2, _80065310
    lwz	r12, -0x7740(r13)
    li	r6, 0
    b       _80065038
_80065018:
    rlwinm	r5, r6, 5, 0x13, 0x1a
    addi	r0, r5, 0x588
    lbzx	r0, r12, r0
    cmplwi	r0, 0
    bc      4, 2, _80065034
    mr	r9, r6
    b       _80065044
_80065034:
    addi	r6, r6, 1
_80065038:
    clrlwi	r0, r6, 0x18
    cmplwi	r0, 0x40
    bc      12, 0, _80065018
_80065044:
    rlwinm	r5, r6, 5, 0x13, 0x1a
    li	r11, 1
    addi	r0, r5, 0x588
    rlwinm	r6, r9, 5, 0x13, 0x1a
    stbx	r11, r12, r0
    addi	r11, r5, 0x589
    addi	r0, r5, 0x58c
    addi	r19, r5, 0x58d
    lbz	r18, 0(r10)
    addi	r20, r5, 0x58e
    lwz	r12, -0x7740(r13)
    addi	r21, r5, 0x58f
    addi	r22, r5, 0x590
    addi	r23, r5, 0x591
    stbx	r18, r12, r11
    addi	r24, r5, 0x592
    addi	r25, r5, 0x593
    addi	r26, r5, 0x594
    lbz	r12, 2(r10)
    addi	r27, r5, 0x595
    lwz	r11, -0x7740(r13)
    addi	r28, r5, 0x596
    addi	r29, r5, 0x597
    addi	r31, r5, 0x58b
    stbx	r12, r11, r0
    addi	r12, r5, 0x5a0
    addi	r11, r6, 0x589
    li	r0, 0
    lbz	r18, 3(r10)
    lwz	r30, -0x7740(r13)
    stbx	r18, r30, r19
    lbz	r19, 0xa(r10)
    lwz	r30, -0x7740(r13)
    stbx	r19, r30, r20
    lbz	r20, 9(r10)
    lwz	r30, -0x7740(r13)
    stbx	r20, r30, r21
    lbz	r21, 0xb(r10)
    lwz	r30, -0x7740(r13)
    stbx	r21, r30, r22
    lbz	r22, 0xc(r10)
    lwz	r30, -0x7740(r13)
    stbx	r22, r30, r23
    lbz	r23, 6(r10)
    lwz	r30, -0x7740(r13)
    stbx	r23, r30, r24
    lbz	r24, 7(r10)
    lwz	r30, -0x7740(r13)
    stbx	r24, r30, r25
    lbz	r25, 8(r10)
    lwz	r30, -0x7740(r13)
    stbx	r25, r30, r26
    lbz	r26, 0xd(r10)
    lwz	r30, -0x7740(r13)
    stbx	r26, r30, r27
    lbz	r27, 0xd(r10)
    lwz	r30, -0x7740(r13)
    stbx	r27, r30, r28
    lbz	r28, 0xe(r10)
    lwz	r30, -0x7740(r13)
    stbx	r28, r30, r29
    lbz	r29, 1(r10)
    lwz	r30, -0x7740(r13)
    stbx	r29, r30, r31
    lwz	r31, -0x7740(r13)
    stwx	r10, r31, r12
    lwz	r18, -0x7740(r13)
    lbzx	r11, r18, r11
    rlwinm.	r11, r11, 0, 0x1e, 0x1e
    bc      12, 2, _80065184
    add	r11, r4, r18
    lbz	r19, 0x495(r11)
    lbz	r12, 0x493(r11)
    cmplwi	r19, 0x40
    bc      12, 2, _800651a8
    extsb	r11, r19
    addi	r0, r11, -0x40
    slwi	r0, r0, 1
    extsb	r0, r0
    b       _800651a8
_80065184:
    add	r11, r4, r18
    lbz	r19, 0x494(r11)
    lbz	r12, 0x492(r11)
    cmplwi	r19, 0x40
    bc      12, 2, _800651a8
    extsb	r11, r19
    addi	r0, r11, -0x40
    slwi	r0, r0, 1
    extsb	r0, r0
_800651a8:
    extsb	r11, r12
    extsb	r0, r0
    add	r0, r11, r0
    extsh.	r11, r0
    bc      4, 0, _800651c4
    li	r11, 0
    b       _800651d0
_800651c4:
    cmpwi	r11, 0x7f
    bc      4, 1, _800651d0
    li	r11, 0x7f
_800651d0:
    addi	r0, r5, 0x598
    stbx	r11, r18, r0
    lwz	r11, -0x7740(r13)
    add	r5, r11, r6
    addi	r6, r11, 8
    lbz	r0, 0x589(r5)
    lwzx	r6, r4, r6
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bc      12, 2, _80065218
    lwz	r0, 0x28(r6)
    cmplwi	r0, 0
    bc      12, 2, _8006520c
    add	r0, r6, r0
    stw	r0, 0x5a4(r5)
    b       _80065310
_8006520c:
    li	r0, 0
    stw	r0, 0x5a4(r5)
    b       _80065310
_80065218:
    lbz	r18, 0x58c(r5)
    li	r11, 0
    lwz	r0, 0x1c(r6)
    cmplwi	r18, 0
    add	r19, r6, r0
    mr	r6, r19
    bc      12, 0, _80065284
    addi	r0, r18, 1
    addi	r12, r18, -8
    cmplwi	r0, 8
    bc      4, 1, _80065264
    addi	r0, r12, 8
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r12, 0
    bc      12, 0, _80065264
_80065258:
    addi	r6, r6, 0x10
    addi	r11, r11, 8
    bc      16, 0, _80065258
_80065264:
    addi	r0, r18, 1
    subf	r0, r11, r0
    mtctr	r0
    cmplw	r11, r18
    bc      12, 1, _80065284
_80065278:
    addi	r6, r6, 2
    addi	r11, r11, 1
    bc      16, 0, _80065278
_80065284:
    lbz	r12, 0x58d(r5)
    li	r20, 0
    lhz	r0, 0(r6)
    cmplwi	r12, 0
    add	r6, r19, r0
    mr	r18, r6
    bc      12, 0, _800652f0
    addi	r0, r12, 1
    addi	r11, r12, -8
    cmplwi	r0, 8
    bc      4, 1, _800652d0
    addi	r0, r11, 8
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r11, 0
    bc      12, 0, _800652d0
_800652c4:
    addi	r18, r18, 0x10
    addi	r20, r20, 8
    bc      16, 0, _800652c4
_800652d0:
    addi	r0, r12, 1
    subf	r0, r20, r0
    mtctr	r0
    cmplw	r20, r12
    bc      12, 1, _800652f0
_800652e4:
    addi	r18, r18, 2
    addi	r20, r20, 1
    bc      16, 0, _800652e4
_800652f0:
    lhz	r0, 0(r18)
    cmplwi	r0, 0
    bc      12, 2, _80065308
    add	r0, r0, r6
    stw	r0, 0x5a4(r5)
    b       _80065310
_80065308:
    li	r0, 0
    stw	r0, 0x5a4(r5)
_80065310:
    clrlwi	r0, r9, 0x18
    cmplwi	r0, 0xff
    bc      12, 2, _80065370
    lwz	r11, -0x7740(r13)
    li	r19, 0
    add	r6, r11, r3
    b       _80065364
_8006532c:
    lbz	r0, 1(r10)
    clrlwi	r18, r19, 0x18
    slwi	r12, r0, 2
    add	r5, r12, r18
    addi	r0, r5, 0xd88
    lbzx	r0, r6, r0
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _80065360
    add	r0, r11, r12
    add	r5, r0, r18
    addi	r0, r5, 0xd88
    stbx	r9, r3, r0
    b       _80065370
_80065360:
    addi	r19, r19, 1
_80065364:
    clrlwi	r0, r19, 0x18
    cmplwi	r0, 4
    bc      12, 0, _8006532c
_80065370:
    addi	r10, r10, 0x10
    addi	r7, r7, 1
_80065378:
    clrlwi	r0, r7, 0x18
    cmplw	r0, r8
    bc      4, 1, _80064ffc
    lmw	r18, 8(r1)
    addi	r1, r1, 0x40
    blr
}

asm void fn_80065390(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r22, 8(r1)
    lwz	r4, -0x7740(r13)
    lwz	r0, 0x444(r4)
    rlwinm	r9, r0, 4, 0x18, 0x1b
    clrlwi	r3, r0, 0x1c
    add	r5, r4, r9
    lwz	r10, 8(r5)
    lhz	r0, 0x3e(r10)
    lwz	r4, 0x18(r10)
    cmplwi	r0, 0
    add	r11, r10, r4
    bc      12, 2, _8006550c
    rlwinm	r7, r3, 6, 0x12, 0x19
    li	r5, 0
    b       _800654c8
_800653d8:
    rlwinm	r0, r5, 2, 0x16, 0x1d
    li	r4, 0
    add	r6, r7, r0
    b       _800654b8
_800653e8:
    lwz	r22, -0x7740(r13)
    clrlwi	r8, r4, 0x18
    add	r12, r22, r8
    addi	r0, r12, 0xd88
    lbzx	r0, r6, r0
    cmplwi	r0, 0xff
    bc      12, 2, _800654b4
    rlwinm	r31, r0, 5, 0x13, 0x1a
    li	r12, 0
    add	r22, r22, r31
    lbz	r0, 0x589(r22)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _80065420
    li	r12, 1
_80065420:
    clrlwi.	r0, r12, 0x18
    bc      12, 2, _800654b4
    li	r0, 0
    addi	r12, r31, 0x589
    stb	r0, 0x588(r22)
    addi	r23, r31, 0x5a0
    addi	r24, r31, 0x5a4
    addi	r26, r31, 0x58a
    lwz	r22, -0x7740(r13)
    addi	r27, r31, 0x599
    li	r25, 0x40
    addi	r28, r31, 0x59a
    stbx	r0, r22, r12
    addi	r29, r31, 0x59b
    addi	r30, r31, 0x59c
    addi	r31, r31, 0x59d
    lwz	r22, -0x7740(r13)
    li	r12, 0xff
    stwx	r0, r22, r23
    lwz	r23, -0x7740(r13)
    stwx	r0, r23, r24
    lwz	r24, -0x7740(r13)
    stbx	r0, r24, r26
    lwz	r26, -0x7740(r13)
    stbx	r25, r26, r27
    lwz	r27, -0x7740(r13)
    stbx	r0, r27, r28
    lwz	r28, -0x7740(r13)
    stbx	r0, r28, r29
    lwz	r29, -0x7740(r13)
    stbx	r0, r29, r30
    lwz	r30, -0x7740(r13)
    stbx	r0, r30, r31
    lwz	r0, -0x7740(r13)
    add	r8, r0, r8
    addi	r0, r8, 0xd88
    stbx	r12, r6, r0
_800654b4:
    addi	r4, r4, 1
_800654b8:
    clrlwi	r0, r4, 0x18
    cmplwi	r0, 4
    bc      12, 0, _800653e8
    addi	r5, r5, 1
_800654c8:
    clrlwi	r0, r5, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800653d8
    lhz	r4, 0x3e(r10)
    lwz	r0, -0x7740(r13)
    add	r5, r11, r4
    add	r4, r0, r9
    stw	r5, 0x48c(r4)
    lwz	r0, -0x7740(r13)
    add	r5, r0, r9
    lwz	r4, 0x48c(r5)
    lbz	r0, 1(r4)
    cmplwi	r0, 0x80
    bc      12, 2, _80065504
    stb	r0, 0x493(r5)
_80065504:
    bl      fn_80064FDC
    b       _80065514
_8006550c:
    li	r0, 0
    stw	r0, 0x48c(r5)
_80065514:
    lmw	r22, 8(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_80065528(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r24, 0x10(r1)
    lwz	r5, -0x7740(r13)
    lwz	r0, 0x444(r5)
    rlwinm	r6, r0, 4, 0x18, 0x1b
    clrlwi	r7, r0, 0x1c
    add	r4, r5, r6
    rlwinm	r9, r0, 0x18, 0x18, 0x1f
    lwz	r8, 8(r4)
    cmplwi	r8, 0
    bc      12, 2, _80065714
    lbz	r0, 0x490(r4)
    cmplw	r9, r0
    bc      4, 2, _80065570
    cmplwi	r3, 0
    bc      12, 2, _80065714
_80065570:
    addi	r10, r8, 0x3c
    lwz	r3, 0x18(r8)
    lhz	r0, 0x3c(r8)
    add	r4, r8, r3
    srawi	r3, r0, 8
    addi	r0, r3, -1
    cmplw	r9, r0
    bc      12, 1, _800657e0
    addi	r0, r9, 1
    li	r8, 0
    b       _800655a4
_8006559c:
    addi	r10, r10, 2
    addi	r8, r8, 1
_800655a4:
    clrlwi	r3, r8, 0x18
    cmplw	r3, r0
    bc      4, 1, _8006559c
    lhz	r0, 0(r10)
    cmplwi	r0, 0
    bc      12, 2, _800657e0
    add	r4, r4, r0
    add	r3, r5, r6
    stw	r4, 0x488(r3)
    mr	r31, r4
    lwz	r0, -0x7740(r13)
    add	r3, r0, r6
    stb	r9, 0x490(r3)
    lbz	r4, 1(r4)
    cmplwi	r4, 0x80
    bc      12, 2, _800655f0
    lwz	r0, -0x7740(r13)
    add	r3, r0, r6
    stb	r4, 0x492(r3)
_800655f0:
    rlwinm	r0, r7, 6, 0x12, 0x19
    li	r4, 0
    b       _800656ec
_800655fc:
    rlwinm	r3, r4, 2, 0x16, 0x1d
    add	r5, r0, r3
    li	r3, 0
    b       _800656dc
_8006560c:
    lwz	r10, -0x7740(r13)
    clrlwi	r6, r3, 0x18
    add	r8, r10, r6
    addi	r8, r8, 0xd88
    lbzx	r8, r5, r8
    cmplwi	r8, 0xff
    bc      12, 2, _800656d8
    rlwinm	r25, r8, 5, 0x13, 0x1a
    li	r9, 0
    add	r10, r10, r25
    lbz	r8, 0x589(r10)
    clrlwi.	r8, r8, 0x1f
    bc      4, 2, _80065644
    li	r9, 1
_80065644:
    clrlwi.	r8, r9, 0x18
    bc      12, 2, _800656d8
    li	r24, 0
    addi	r8, r25, 0x589
    stb	r24, 0x588(r10)
    addi	r26, r25, 0x5a0
    addi	r27, r25, 0x5a4
    addi	r29, r25, 0x58a
    lwz	r9, -0x7740(r13)
    addi	r30, r25, 0x599
    li	r28, 0x40
    addi	r12, r25, 0x59a
    stbx	r24, r9, r8
    addi	r11, r25, 0x59b
    addi	r10, r25, 0x59c
    addi	r8, r25, 0x59d
    lwz	r25, -0x7740(r13)
    li	r9, 0xff
    stwx	r24, r25, r26
    lwz	r26, -0x7740(r13)
    stwx	r24, r26, r27
    lwz	r27, -0x7740(r13)
    stbx	r24, r27, r29
    lwz	r29, -0x7740(r13)
    stbx	r28, r29, r30
    lwz	r30, -0x7740(r13)
    stbx	r24, r30, r12
    lwz	r12, -0x7740(r13)
    stbx	r24, r12, r11
    lwz	r11, -0x7740(r13)
    stbx	r24, r11, r10
    lwz	r10, -0x7740(r13)
    stbx	r24, r10, r8
    lwz	r8, -0x7740(r13)
    add	r6, r8, r6
    addi	r6, r6, 0xd88
    stbx	r9, r5, r6
_800656d8:
    addi	r3, r3, 1
_800656dc:
    clrlwi	r6, r3, 0x18
    cmplwi	r6, 4
    bc      12, 0, _8006560c
    addi	r4, r4, 1
_800656ec:
    clrlwi	r3, r4, 0x18
    cmplwi	r3, 0x10
    bc      12, 0, _800655fc
    mr	r3, r7
    mr	r4, r31
    bl      fn_80064FDC
    lbz	r3, 3(r31)
    lbz	r4, 4(r31)
    bl      fn_8006331C
    b       _800657e0
_80065714:
    cmplwi	r8, 0
    bc      12, 2, _800657e0
    slwi	r11, r7, 6
    li	r24, 0
    b       _800657d4
_80065728:
    rlwinm	r0, r24, 2, 0x16, 0x1d
    li	r25, 0
    add	r10, r11, r0
    b       _800657c4
_80065738:
    lwz	r4, -0x7740(r13)
    clrlwi	r0, r25, 0x18
    add	r3, r4, r0
    addi	r0, r3, 0xd88
    lbzx	r0, r10, r0
    cmplwi	r0, 0xff
    bc      12, 2, _800657c0
    rlwinm	r12, r0, 5, 0x13, 0x1a
    li	r5, 0
    add	r3, r4, r12
    lbz	r0, 0x589(r3)
    clrlwi.	r0, r0, 0x1f
    bc      4, 2, _80065770
    li	r5, 1
_80065770:
    clrlwi.	r0, r5, 0x18
    bc      12, 2, _800657c0
    li	r9, 0
    addi	r6, r12, 0x599
    stb	r9, 0x58a(r3)
    li	r8, 0x40
    addi	r5, r12, 0x59a
    addi	r4, r12, 0x59b
    lwz	r7, -0x7740(r13)
    addi	r3, r12, 0x59c
    addi	r0, r12, 0x59d
    stbx	r8, r7, r6
    lwz	r6, -0x7740(r13)
    stbx	r9, r6, r5
    lwz	r5, -0x7740(r13)
    stbx	r9, r5, r4
    lwz	r4, -0x7740(r13)
    stbx	r9, r4, r3
    lwz	r3, -0x7740(r13)
    stbx	r9, r3, r0
_800657c0:
    addi	r25, r25, 1
_800657c4:
    clrlwi	r0, r25, 0x18
    cmplwi	r0, 4
    bc      12, 0, _80065738
    addi	r24, r24, 1
_800657d4:
    clrlwi	r0, r24, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80065728
_800657e0:
    lmw	r24, 0x10(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void SndStartChannelSequence(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    rlwinm	r7, r3, 4, 0x14, 0x1b
    li	r5, 0x7f
    stw	r0, 0x14(r1)
    li	r0, 0xff
    lwz	r4, -0x7740(r13)
    add	r6, r4, r7
    lwz	r8, 8(r6)
    lwz	r4, 0x18(r8)
    stb	r0, 0x490(r6)
    add	r6, r8, r4
    lwz	r0, -0x7740(r13)
    add	r4, r0, r7
    stb	r5, 0x491(r4)
    lhz	r4, 0x3e(r8)
    cmplwi	r4, 0
    bc      12, 2, _80065870
    lwz	r0, -0x7740(r13)
    add	r5, r6, r4
    add	r4, r0, r7
    stw	r5, 0x48c(r4)
    lwz	r0, -0x7740(r13)
    add	r5, r0, r7
    lwz	r4, 0x48c(r5)
    lbz	r0, 1(r4)
    cmplwi	r0, 0x80
    bc      12, 2, _80065868
    stb	r0, 0x493(r5)
_80065868:
    bl      fn_80064FDC
    b       _80065880
_80065870:
    lwz	r0, -0x7740(r13)
    li	r4, 0
    add	r3, r0, r7
    stw	r4, 0x48c(r3)
_80065880:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void SndSetCallback2(void)
{
    nofralloc
    lwz	r4, -0x7740(r13)
    stw	r3, 0x5b20(r4)
    blr
}

asm void SndSetCallback1(void)
{
    nofralloc
    lwz	r4, -0x7740(r13)
    stw	r3, 0x5b1c(r4)
    blr
}

asm void SndSetCallback0(void)
{
    nofralloc
    lwz	r4, -0x7740(r13)
    stw	r3, 0x5b18(r4)
    blr
}

asm void fn_800658B4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    lis	r0, -0x5c00
    cmpw	r3, r0
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    bc      12, 2, _800658e0
    b       _800659ac
_800658e0:
    lwz	r4, -0x7740(r13)
    rlwinm	r3, r30, 0, 0x11, 0x17
    addis	r29, r3, -0x5b90
    li	r31, 0
    lbz	r0, 0x464(r4)
    extsb.	r0, r0
    bc      12, 2, _80065904
    li	r31, -3
    b       _80065990
_80065904:
    li	r3, -1
    rlwinm.	r0, r29, 0, 0, 0
    stb	r3, 0x464(r4)
    bc      4, 2, _8006591c
    li	r31, -2
    b       _80065984
_8006591c:
    bl      OSDisableInterrupts
    stw	r3, -0x7748(r13)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x441(r3)
    cmplwi	r0, 0x40
    bc      4, 0, _80065978
    lbz	r0, 0x443(r3)
    slwi	r0, r0, 2
    add	r3, r3, r0
    lwz	r0, 0x240(r3)
    cmplwi	r0, 0
    bc      4, 2, _80065978
    stw	r29, 0x240(r3)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x443(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x443(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x441(r4)
    addi	r0, r3, 1
    stb	r0, 0x441(r4)
    b       _8006597c
_80065978:
    li	r31, -1
_8006597c:
    lwz	r3, -0x7748(r13)
    bl      OSRestoreInterrupts
_80065984:
    lwz	r3, -0x7740(r13)
    li	r0, 0
    stb	r0, 0x464(r3)
_80065990:
    cmpwi	r31, 0
    bc      12, 2, _800659a0
    mr	r3, r31
    b       _80065a60
_800659a0:
    rlwinm	r3, r30, 8, 0x11, 0x17
    addis	r30, r3, -0x5c00
    b       _800659b4
_800659ac:
    li	r3, -2
    b       _80065a60
_800659b4:
    lwz	r4, -0x7740(r13)
    li	r31, 0
    lbz	r0, 0x464(r4)
    extsb.	r0, r0
    bc      12, 2, _800659d0
    li	r31, -3
    b       _80065a5c
_800659d0:
    li	r3, -1
    rlwinm.	r0, r30, 0, 0, 0
    stb	r3, 0x464(r4)
    bc      4, 2, _800659e8
    li	r31, -2
    b       _80065a50
_800659e8:
    bl      OSDisableInterrupts
    stw	r3, -0x7748(r13)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x441(r3)
    cmplwi	r0, 0x40
    bc      4, 0, _80065a44
    lbz	r0, 0x443(r3)
    slwi	r0, r0, 2
    add	r3, r3, r0
    lwz	r0, 0x240(r3)
    cmplwi	r0, 0
    bc      4, 2, _80065a44
    stw	r30, 0x240(r3)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x443(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x443(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x441(r4)
    addi	r0, r3, 1
    stb	r0, 0x441(r4)
    b       _80065a48
_80065a44:
    li	r31, -1
_80065a48:
    lwz	r3, -0x7748(r13)
    bl      OSRestoreInterrupts
_80065a50:
    lwz	r3, -0x7740(r13)
    li	r0, 0
    stb	r0, 0x464(r3)
_80065a5c:
    mr	r3, r31
_80065a60:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_80065A7C(void)
{
    nofralloc
    lwz	r4, -0x7740(r13)
    lbz	r0, 0x440(r4)
    cmplwi	r0, 0x40
    bgelr	
    lbz	r0, 0x459(r4)
    slwi	r0, r0, 2
    add	r4, r4, r0
    stw	r3, 0x340(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x459(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x459(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x440(r4)
    addi	r0, r3, 1
    stb	r0, 0x440(r4)
    blr
}

asm void fn_80065AC4(void)
{
    nofralloc
    li	r0, 0
    stw	r0, -0x7744(r13)
    blr
}

asm void fn_80065AD0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r4, 0x10(r3)
    cmplwi	r4, 0
    bc      12, 2, _80065af0
    lwz	r3, -0x7fb0(r13)
    bl      OSFree
_80065af0:
    li	r0, 0
    stw	r0, -0x7744(r13)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_80065B08(void)
{
    nofralloc
    li	r4, 5
    li	r0, 0
    li	r10, 0
    li	r8, 1
    li	r6, 4
    mtctr	r4
_80065b20:
    lwz	r4, -0x7740(r13)
    lwz	r5, 0(r3)
    add	r7, r4, r6
    lwz	r4, 0x100(r7)
    add	r10, r10, r5
    stw	r5, 0x140(r7)
    add	r9, r4, r5
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x104(r7)
    lwz	r4, 0x194(r7)
    add	r4, r5, r4
    cmplw	r9, r4
    bc      12, 1, _80065b60
    addi	r4, r6, 0x104
    stwx	r9, r7, r4
    b       _80065b68
_80065b60:
    li	r0, -1
    b       _80065c10
_80065b68:
    lwz	r4, -0x7740(r13)
    addi	r6, r6, 4
    lwzu	r5, 4(r3)
    add	r7, r4, r6
    lwz	r4, 0x100(r7)
    add	r10, r10, r5
    stw	r5, 0x140(r7)
    add	r9, r4, r5
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x104(r7)
    lwz	r4, 0x194(r7)
    add	r4, r5, r4
    cmplw	r9, r4
    bc      12, 1, _80065bac
    addi	r4, r6, 0x104
    stwx	r9, r7, r4
    b       _80065bb4
_80065bac:
    li	r0, -1
    b       _80065c10
_80065bb4:
    lwz	r4, -0x7740(r13)
    addi	r6, r6, 4
    lwzu	r5, 4(r3)
    add	r7, r4, r6
    lwz	r4, 0x100(r7)
    add	r10, r10, r5
    stw	r5, 0x140(r7)
    add	r9, r4, r5
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x104(r7)
    lwz	r4, 0x194(r7)
    add	r4, r5, r4
    cmplw	r9, r4
    bc      12, 1, _80065bf8
    addi	r4, r6, 0x104
    stwx	r9, r7, r4
    b       _80065c00
_80065bf8:
    li	r0, -1
    b       _80065c10
_80065c00:
    addi	r3, r3, 4
    addi	r6, r6, 4
    addi	r8, r8, 2
    bc      16, 0, _80065b20
_80065c10:
    cmpwi	r0, 0
    bc      4, 2, _80065d54
    lwz	r6, 0(r3)
    li	r4, 5
    lwz	r5, -0x7740(r13)
    li	r8, 1
    add	r10, r10, r6
    stw	r6, 0x180(r5)
    li	r6, 4
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x104(r7)
    add	r5, r5, r10
    stw	r5, 0x198(r7)
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x194(r7)
    subf	r5, r10, r5
    stw	r5, 0x19c(r7)
    mtctr	r4
    addi	r3, r3, 4
_80065c5c:
    lwz	r4, -0x7740(r13)
    lwz	r5, 0(r3)
    add	r7, r4, r6
    lwz	r4, 0x1a8(r7)
    stw	r5, 0x1e8(r7)
    add	r9, r4, r5
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x1ac(r7)
    lwz	r4, 0x23c(r7)
    add	r4, r5, r4
    cmplw	r9, r4
    bc      12, 1, _80065c98
    addi	r4, r6, 0x1ac
    stwx	r9, r7, r4
    b       _80065ca0
_80065c98:
    li	r0, -1
    b       _80065d40
_80065ca0:
    lwz	r4, -0x7740(r13)
    addi	r6, r6, 4
    lwzu	r5, 4(r3)
    add	r7, r4, r6
    lwz	r4, 0x1a8(r7)
    stw	r5, 0x1e8(r7)
    add	r9, r4, r5
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x1ac(r7)
    lwz	r4, 0x23c(r7)
    add	r4, r5, r4
    cmplw	r9, r4
    bc      12, 1, _80065ce0
    addi	r4, r6, 0x1ac
    stwx	r9, r7, r4
    b       _80065ce8
_80065ce0:
    li	r0, -1
    b       _80065d40
_80065ce8:
    lwz	r4, -0x7740(r13)
    addi	r6, r6, 4
    lwzu	r5, 4(r3)
    add	r7, r4, r6
    lwz	r4, 0x1a8(r7)
    stw	r5, 0x1e8(r7)
    add	r9, r4, r5
    lwz	r7, -0x7740(r13)
    lwz	r5, 0x1ac(r7)
    lwz	r4, 0x23c(r7)
    add	r4, r5, r4
    cmplw	r9, r4
    bc      12, 1, _80065d28
    addi	r4, r6, 0x1ac
    stwx	r9, r7, r4
    b       _80065d30
_80065d28:
    li	r0, -1
    b       _80065d40
_80065d30:
    addi	r3, r3, 4
    addi	r6, r6, 4
    addi	r8, r8, 2
    bc      16, 0, _80065c5c
_80065d40:
    cmpwi	r0, 0
    bc      4, 2, _80065d54
    lwz	r4, 0(r3)
    lwz	r3, -0x7740(r13)
    stw	r4, 0x228(r3)
_80065d54:
    cmpwi	r0, 0
    bc      4, 2, _80065d68
    lwz	r3, -0x7740(r13)
    li	r4, 1
    stb	r4, 0x45f(r3)
_80065d68:
    mr	r3, r0
    blr
}

asm void SndFreeChannel(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    mr	r29, r3
    cmplwi	r29, 0x10
    bc      12, 0, _80065da0
    li	r30, -1
    b       _80065f14
_80065da0:
    lwz	r4, -0x7740(r13)
    slwi	r31, r29, 4
    lwzx	r4, r4, r31
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _80065f10
    bl      SndBoostVoicePriority
    clrlwi	r3, r29, 0x18
    li	r4, 0
    bl      SndReleaseProcsForVoices
    clrlwi	r3, r29, 0x18
    li	r4, 1
    bl      SndReleaseProcsForVoices
    lwz	r9, -0x7740(r13)
    li	r7, -1
    li	r6, 0xff
    li	r3, 0
    add	r4, r9, r31
    lbz	r5, 0x460(r9)
    lbz	r8, 0xc(r4)
    li	r0, 8
    li	r4, 0
    subf	r5, r8, r5
    stb	r5, 0x460(r9)
    lwz	r5, -0x7740(r13)
    stwx	r7, r5, r31
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xe(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xd(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r3, 0xc(r5)
    mtctr	r0
_80065e30:
    lwz	r7, -0x7740(r13)
    addi	r5, r3, 0x104
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80065e64
    addi	r0, r4, 0x184
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80065e64:
    lwz	r7, -0x7740(r13)
    addi	r5, r3, 0x1ac
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80065e98
    addi	r0, r4, 0x22c
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_80065e98:
    lwz	r7, -0x7740(r13)
    addi	r5, r3, 0x108
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80065ecc
    addi	r0, r4, 0x185
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80065ecc:
    lwz	r7, -0x7740(r13)
    addi	r5, r3, 0x1b0
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80065f00
    addi	r0, r4, 0x22d
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_80065f00:
    addi	r3, r3, 8
    addi	r4, r4, 2
    bc      16, 0, _80065e30
    b       _80065f14
_80065f10:
    li	r30, -2
_80065f14:
    lwz	r0, 0x24(r1)
    mr	r3, r30
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void SndLoadSamplesARQ(void)
{
    nofralloc
    stwu	r1, -0x480(r1)
    mflr	r0
    stw	r0, 0x484(r1)
    stmw	r20, 0x450(r1)
    mr	r27, r4
    cmplwi	r27, 0x10
    mr	r20, r3
    li	r26, 0
    bc      12, 0, _80065f60
    li	r3, -1
    b       _80066c00
_80065f60:
    lwz	r4, -0x7740(r13)
    slwi	r31, r27, 4
    lwzx	r4, r4, r31
    addis	r0, r4, 1
    cmplwi	r0, 0xffff
    bc      4, 2, _80066bf8
    addi	r4, r1, 8
    bl      DVDOpen
    cmpwi	r3, 0
    bc      4, 2, _80065fa8
    lis     r3, Cannot_open_s_str@ha
    mr	r5, r20
    addi	r4, r3, Cannot_open_s_str@l
    addi	r3, r1, 0x44
    crxor	6, 6, 6
    bl      sprintf
    li	r3, -1
    b       _80066c00
_80065fa8:
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, -0x7fb0(r13)
    mr	r20, r0
    li	r4, 0x20
    bl      OSAlloc
    mr	r0, r3
    mr	r3, r20
    mr	r28, r0
    bl      OSRestoreInterrupts
    mr	r4, r28
    addi	r3, r1, 8
    li	r5, 0x20
    li	r6, 0
    li	r7, 2
    bl      DVDReadAsync
    mr	r0, r3
    mr	r3, r28
    mr	r4, r0
    mr	r30, r4
    bl      DCInvalidateRange
    lwz	r3, 0(r28)
    addis	r0, r3, -0x6763
    cmplwi	r0, 0x6178
    bc      4, 2, _80066bdc
    lwz	r3, 4(r28)
    addis	r0, r3, -0x4454
    cmplwi	r0, 0x504b
    bc      4, 2, _800660c0
    lwz	r3, 8(r28)
    lis	r0, 0x228
    cmplw	r3, r0
    bc      12, 0, _800660b8
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x45f(r3)
    cmplwi	r0, 0
    bc      4, 2, _800660b0
    lwz	r3, -0x7fb0(r13)
    mr	r4, r28
    bl      OSFree
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, -0x7fb0(r13)
    mr	r20, r0
    li	r4, 0x80
    bl      OSAlloc
    mr	r0, r3
    mr	r3, r20
    mr	r28, r0
    bl      OSRestoreInterrupts
    mr	r4, r28
    mr	r6, r30
    addi	r3, r1, 8
    li	r5, 0x80
    li	r7, 2
    bl      DVDReadAsync
    mr	r4, r3
    mr	r3, r28
    add	r30, r30, r4
    bl      DCInvalidateRange
    mr	r3, r28
    bl      fn_80065B08
    cmpwi	r3, 0
    bc      12, 2, _800660c4
    li	r26, -4
    b       _800660c4
_800660b0:
    addi	r30, r30, 0x80
    b       _800660c4
_800660b8:
    li	r26, -9
    b       _800660c4
_800660c0:
    li	r26, -2
_800660c4:
    lwz	r3, -0x7fb0(r13)
    mr	r4, r28
    bl      OSFree
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, -0x7fb0(r13)
    mr	r20, r0
    li	r4, 0x40
    bl      OSAlloc
    mr	r0, r3
    mr	r3, r20
    mr	r28, r0
    bl      OSRestoreInterrupts
    mr	r4, r28
    mr	r6, r30
    addi	r3, r1, 8
    li	r5, 0x40
    li	r7, 2
    bl      DVDReadAsync
    mr	r4, r3
    mr	r3, r28
    addi	r30, r30, 0x20
    bl      DCInvalidateRange
    lwz	r3, 4(r28)
    addis	r0, r3, -0x5442
    cmplwi	r0, 0x4c44
    bc      4, 2, _800662e4
    cmpwi	r26, 0
    bc      4, 2, _800662e4
    lwz	r6, -0x7740(r13)
    li	r24, -1
    lwz	r3, 0x28(r28)
    lbz	r0, 0x460(r6)
    rlwinm	r25, r3, 0x10, 0x18, 0x1f
    lwz	r5, 0xc(r28)
    add	r0, r0, r25
    lwz	r8, 0x20(r28)
    cmpwi	r0, 0x40
    lwz	r23, 0x24(r28)
    bc      12, 1, _800662e0
    li	r0, 4
    mr	r3, r6
    mr	r4, r6
    li	r7, 0
    mtctr	r0
_80066178:
    lwz	r0, 0x144(r3)
    cmplw	r0, r8
    bc      4, 2, _80066198
    lbz	r0, 0x184(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066198
    mr	r24, r7
    b       _80066214
_80066198:
    lwz	r0, 0x148(r3)
    addi	r7, r7, 1
    cmplw	r0, r8
    bc      4, 2, _800661bc
    lbz	r0, 0x185(r4)
    cmplwi	r0, 0
    bc      4, 2, _800661bc
    mr	r24, r7
    b       _80066214
_800661bc:
    lwz	r0, 0x14c(r3)
    addi	r7, r7, 1
    cmplw	r0, r8
    bc      4, 2, _800661e0
    lbz	r0, 0x186(r4)
    cmplwi	r0, 0
    bc      4, 2, _800661e0
    mr	r24, r7
    b       _80066214
_800661e0:
    lwz	r0, 0x150(r3)
    addi	r7, r7, 1
    cmplw	r0, r8
    bc      4, 2, _80066204
    lbz	r0, 0x187(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066204
    mr	r24, r7
    b       _80066214
_80066204:
    addi	r3, r3, 0x10
    addi	r4, r4, 4
    addi	r7, r7, 1
    bc      16, 0, _80066178
_80066214:
    cmpwi	r24, 0
    bc      12, 0, _800662d8
    slwi	r0, r24, 2
    li	r7, 2
    add	r3, r6, r0
    mr	r6, r30
    lwz	r20, 0x104(r3)
    addi	r3, r1, 8
    mr	r4, r20
    bl      DVDReadAsync
    mr	r4, r3
    mr	r3, r20
    add	r30, r30, r4
    bl      DCInvalidateRange
    lwz	r0, -0x7740(r13)
    li	r5, 1
    clrlwi	r3, r27, 0x18
    add	r4, r0, r24
    stb	r5, 0x184(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    stw	r20, 8(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    stb	r25, 0xc(r4)
    lwz	r4, -0x7740(r13)
    stwx	r23, r4, r31
    lwz	r4, 0x2c(r28)
    lwz	r0, -0x7740(r13)
    srwi	r5, r4, 0x18
    add	r4, r0, r31
    stb	r5, 0xd(r4)
    lwz	r4, 0x2c(r28)
    lwz	r0, -0x7740(r13)
    rlwinm	r5, r4, 0x10, 0x18, 0x1f
    add	r4, r0, r31
    stb	r5, 0xe(r4)
    lwz	r0, 0x30(r28)
    lwz	r4, -0x7740(r13)
    stw	r0, 0x478(r4)
    lwz	r0, 0x34(r28)
    lwz	r4, -0x7740(r13)
    stw	r0, 0x47c(r4)
    lwz	r4, -0x7740(r13)
    lbz	r0, 0x460(r4)
    add	r0, r0, r25
    stb	r0, 0x460(r4)
    bl      SndStartChannelSequence
    b       _800662e4
_800662d8:
    li	r26, -6
    b       _800662e4
_800662e0:
    li	r26, -5
_800662e4:
    cmpwi	r26, 0
    li	r24, -1
    bc      4, 2, _80066be0
    lwz	r3, -0x7fb0(r13)
    mr	r4, r28
    bl      OSFree
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, -0x7fb0(r13)
    mr	r20, r0
    li	r4, 0x40
    bl      OSAlloc
    mr	r0, r3
    mr	r3, r20
    mr	r28, r0
    bl      OSRestoreInterrupts
    mr	r4, r28
    mr	r6, r30
    addi	r3, r1, 8
    li	r5, 0x40
    li	r7, 2
    bl      DVDReadAsync
    mr	r4, r3
    mr	r3, r28
    addi	r30, r30, 0x20
    bl      DCInvalidateRange
    lwz	r3, 4(r28)
    addis	r0, r3, -0x5043
    cmplwi	r0, 0x4d44
    bc      4, 2, _80066a60
    lwz	r5, -0x7740(r13)
    li	r0, 4
    lwz	r23, 0xc(r28)
    li	r6, 0
    mr	r3, r5
    mr	r4, r5
    lwz	r7, 0x20(r28)
    mtctr	r0
_8006637c:
    lwz	r0, 0x1ec(r3)
    cmplw	r0, r7
    bc      4, 2, _8006639c
    lbz	r0, 0x22c(r4)
    cmplwi	r0, 0
    bc      4, 2, _8006639c
    mr	r24, r6
    b       _80066418
_8006639c:
    lwz	r0, 0x1f0(r3)
    addi	r6, r6, 1
    cmplw	r0, r7
    bc      4, 2, _800663c0
    lbz	r0, 0x22d(r4)
    cmplwi	r0, 0
    bc      4, 2, _800663c0
    mr	r24, r6
    b       _80066418
_800663c0:
    lwz	r0, 0x1f4(r3)
    addi	r6, r6, 1
    cmplw	r0, r7
    bc      4, 2, _800663e4
    lbz	r0, 0x22e(r4)
    cmplwi	r0, 0
    bc      4, 2, _800663e4
    mr	r24, r6
    b       _80066418
_800663e4:
    lwz	r0, 0x1f8(r3)
    addi	r6, r6, 1
    cmplw	r0, r7
    bc      4, 2, _80066408
    lbz	r0, 0x22f(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066408
    mr	r24, r6
    b       _80066418
_80066408:
    addi	r3, r3, 0x10
    addi	r4, r4, 4
    addi	r6, r6, 1
    bc      16, 0, _8006637c
_80066418:
    cmpwi	r24, 0
    bc      12, 0, _800668e8
    add	r3, r5, r24
    li	r0, 1
    stb	r0, 0x22c(r3)
    slwi	r24, r24, 2
    cmplwi	r23, 0
    lwz	r0, -0x7740(r13)
    add	r4, r0, r24
    add	r3, r0, r31
    lwz	r0, 0x1ac(r4)
    stw	r0, 4(r3)
    bc      12, 2, _80066be0
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, -0x7fb0(r13)
    mr	r20, r0
    mr	r4, r23
    bl      OSAlloc
    mr	r0, r3
    mr	r3, r20
    mr	r25, r0
    bl      OSRestoreInterrupts
    cmplwi	r25, 0
    bc      12, 2, _800664ec
    mr	r4, r25
    mr	r5, r23
    mr	r6, r30
    addi	r3, r1, 8
    li	r7, 2
    bl      DVDReadAsync
    mr	r4, r3
    mr	r3, r25
    bl      DCInvalidateRange
    lwz	r0, -0x7740(r13)
    li	r3, 1
    stw	r3, -0x7744(r13)
    lis     r3, lbl_80193B08@ha
    add	r5, r0, r24
    lis     r4, fn_80065AD0@ha
    lwz	r8, 0x1ac(r5)
    addi	r10, r4, fn_80065AD0@l
    addi	r3, r3, lbl_80193B08@l
    mr	r7, r25
    mr	r9, r23
    li	r4, 0
    li	r5, 0
    li	r6, 1
    bl      ARQPostRequest
_800664dc:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      12, 2, _80066be0
    b       _800664dc
_800664ec:
    lis	r0, 2
    mr	r29, r23
    cmplw	r23, r0
    bc      12, 0, _80066540
    bl      OSDisableInterrupts
    lis	r4, 1
    mr	r22, r3
    li	r20, 0x14
    addi	r21, r4, 0x4000
_80066510:
    lwz	r3, -0x7fb0(r13)
    mr	r23, r21
    mr	r4, r21
    bl      OSAlloc
    or.	r25, r3, r3
    bc      4, 2, _80066534
    addic.	r20, r20, -1
    addi	r21, r21, -0x1000
    bc      4, 2, _80066510
_80066534:
    mr	r3, r22
    bl      OSRestoreInterrupts
    b       _80066544
_80066540:
    li	r25, 0
_80066544:
    cmplwi	r25, 0
    bc      12, 2, _80066654
    lwz	r0, -0x7740(r13)
    lis     r4, lbl_80193B08@ha
    lis     r3, fn_80065AC4@ha
    add	r5, r0, r24
    mr	r24, r25
    lwz	r27, 0x1ac(r5)
    addi	r22, r4, lbl_80193B08@l
    addi	r21, r3, fn_80065AC4@l
    b       _800665dc
_80066570:
    mr	r4, r25
    mr	r5, r23
    mr	r6, r30
    addi	r3, r1, 8
    li	r7, 2
    bl      DVDReadAsync
    mr	r20, r3
    mr	r3, r25
    mr	r4, r20
    add	r30, r30, r20
    subf	r29, r20, r29
    bl      DCInvalidateRange
    li	r0, 1
    mr	r3, r22
    stw	r0, -0x7744(r13)
    mr	r7, r25
    mr	r8, r27
    mr	r9, r23
    mr	r10, r21
    li	r4, 0
    li	r5, 0
    li	r6, 1
    bl      ARQPostRequest
_800665cc:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      4, 2, _800665cc
    add	r27, r27, r20
_800665dc:
    subf.	r0, r23, r29
    bc      12, 1, _80066570
    cmpwi	r29, 0
    bc      12, 0, _80066be0
    mr	r4, r25
    mr	r5, r29
    mr	r6, r30
    addi	r3, r1, 8
    li	r7, 2
    bl      DVDReadAsync
    mr	r4, r3
    mr	r3, r25
    bl      DCInvalidateRange
    li	r0, 1
    lis     r3, lbl_80193B08@ha
    lis     r4, fn_80065AD0@ha
    stw	r0, -0x7744(r13)
    addi	r10, r4, fn_80065AD0@l
    addi	r3, r3, lbl_80193B08@l
    mr	r7, r24
    mr	r8, r27
    mr	r9, r29
    li	r4, 0
    li	r5, 0
    li	r6, 1
    bl      ARQPostRequest
_80066644:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      12, 2, _80066be0
    b       _80066644
_80066654:
    lwz	r3, -0x7740(r13)
    lwz	r23, 0x19c(r3)
    cmplwi	r23, 0
    bc      12, 2, _80066770
    lwz	r31, 0x198(r3)
    add	r5, r3, r24
    lis     r4, lbl_80193B08@ha
    lis     r3, fn_80065AC4@ha
    lwz	r24, 0x1ac(r5)
    mr	r25, r23
    mr	r27, r31
    addi	r21, r4, lbl_80193B08@l
    addi	r22, r3, fn_80065AC4@l
    b       _800666f8
_8006668c:
    mr	r4, r31
    mr	r5, r25
    mr	r6, r30
    addi	r3, r1, 8
    li	r7, 2
    bl      DVDReadAsync
    mr	r20, r3
    mr	r3, r31
    mr	r4, r20
    add	r30, r30, r20
    subf	r29, r20, r29
    bl      DCInvalidateRange
    li	r0, 1
    mr	r3, r21
    stw	r0, -0x7744(r13)
    mr	r7, r27
    mr	r8, r24
    mr	r9, r23
    mr	r10, r22
    li	r4, 0
    li	r5, 0
    li	r6, 1
    bl      ARQPostRequest
_800666e8:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      4, 2, _800666e8
    add	r24, r24, r20
_800666f8:
    subf.	r0, r23, r29
    bc      4, 0, _8006668c
    cmpwi	r29, 0
    bc      12, 2, _80066be0
    mr	r4, r31
    mr	r5, r29
    mr	r6, r30
    addi	r3, r1, 8
    li	r7, 2
    bl      DVDReadAsync
    mr	r4, r3
    mr	r3, r31
    bl      DCInvalidateRange
    li	r0, 1
    lis     r3, lbl_80193B08@ha
    lis     r4, fn_80065AC4@ha
    stw	r0, -0x7744(r13)
    addi	r10, r4, fn_80065AC4@l
    addi	r3, r3, lbl_80193B08@l
    mr	r7, r31
    mr	r8, r24
    mr	r9, r29
    li	r4, 0
    li	r5, 0
    li	r6, 1
    bl      ARQPostRequest
_80066760:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      12, 2, _80066be0
    b       _80066760
_80066770:
    cmplwi	r27, 0x10
    bc      4, 0, _800668e0
    lwzx	r3, r3, r31
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _800668e0
    mr	r3, r27
    bl      SndBoostVoicePriority
    clrlwi	r3, r27, 0x18
    li	r4, 0
    bl      SndReleaseProcsForVoices
    clrlwi	r3, r27, 0x18
    li	r4, 1
    bl      SndReleaseProcsForVoices
    lwz	r9, -0x7740(r13)
    li	r7, -1
    li	r6, 0xff
    li	r3, 0
    add	r4, r9, r31
    lbz	r5, 0x460(r9)
    lbz	r8, 0xc(r4)
    li	r0, 8
    mr	r4, r3
    subf	r5, r8, r5
    stb	r5, 0x460(r9)
    lwz	r5, -0x7740(r13)
    stwx	r7, r5, r31
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xe(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xd(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r3, 0xc(r5)
    mtctr	r0
_80066804:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x104
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80066838
    addi	r0, r3, 0x184
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80066838:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1ac
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _8006686c
    addi	r0, r3, 0x22c
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_8006686c:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x108
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _800668a0
    addi	r0, r3, 0x185
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_800668a0:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1b0
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _800668d4
    addi	r0, r3, 0x22d
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_800668d4:
    addi	r4, r4, 8
    addi	r3, r3, 2
    bc      16, 0, _80066804
_800668e0:
    li	r26, -8
    b       _80066be0
_800668e8:
    cmplwi	r27, 0x10
    bc      4, 0, _80066a58
    lwzx	r3, r5, r31
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _80066a58
    mr	r3, r27
    bl      SndBoostVoicePriority
    clrlwi	r3, r27, 0x18
    li	r4, 0
    bl      SndReleaseProcsForVoices
    clrlwi	r3, r27, 0x18
    li	r4, 1
    bl      SndReleaseProcsForVoices
    lwz	r9, -0x7740(r13)
    li	r7, -1
    li	r6, 0xff
    li	r3, 0
    add	r4, r9, r31
    lbz	r5, 0x460(r9)
    lbz	r8, 0xc(r4)
    li	r0, 8
    mr	r4, r3
    subf	r5, r8, r5
    stb	r5, 0x460(r9)
    lwz	r5, -0x7740(r13)
    stwx	r7, r5, r31
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xe(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xd(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r3, 0xc(r5)
    mtctr	r0
_8006697c:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x104
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _800669b0
    addi	r0, r3, 0x184
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_800669b0:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1ac
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _800669e4
    addi	r0, r3, 0x22c
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_800669e4:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x108
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80066a18
    addi	r0, r3, 0x185
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80066a18:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1b0
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80066a4c
    addi	r0, r3, 0x22d
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_80066a4c:
    addi	r4, r4, 8
    addi	r3, r3, 2
    bc      16, 0, _8006697c
_80066a58:
    li	r26, -7
    b       _80066be0
_80066a60:
    cmplwi	r27, 0x10
    bc      4, 0, _80066bd4
    lwz	r3, -0x7740(r13)
    lwzx	r3, r3, r31
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _80066bd4
    mr	r3, r27
    bl      SndBoostVoicePriority
    clrlwi	r3, r27, 0x18
    li	r4, 0
    bl      SndReleaseProcsForVoices
    clrlwi	r3, r27, 0x18
    li	r4, 1
    bl      SndReleaseProcsForVoices
    lwz	r9, -0x7740(r13)
    li	r7, -1
    li	r6, 0xff
    li	r3, 0
    add	r4, r9, r31
    lbz	r5, 0x460(r9)
    lbz	r8, 0xc(r4)
    li	r0, 8
    mr	r4, r3
    subf	r5, r8, r5
    stb	r5, 0x460(r9)
    lwz	r5, -0x7740(r13)
    stwx	r7, r5, r31
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xe(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xd(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r3, 0xc(r5)
    mtctr	r0
_80066af8:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x104
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80066b2c
    addi	r0, r3, 0x184
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80066b2c:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1ac
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80066b60
    addi	r0, r3, 0x22c
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_80066b60:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x108
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80066b94
    addi	r0, r3, 0x185
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80066b94:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1b0
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80066bc8
    addi	r0, r3, 0x22d
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_80066bc8:
    addi	r4, r4, 8
    addi	r3, r3, 2
    bc      16, 0, _80066af8
_80066bd4:
    li	r26, -2
    b       _80066be0
_80066bdc:
    li	r26, -2
_80066be0:
    lwz	r3, -0x7fb0(r13)
    mr	r4, r28
    bl      OSFree
    addi	r3, r1, 8
    bl      DVDCancelSync
    b       _80066bfc
_80066bf8:
    li	r26, -3
_80066bfc:
    mr	r3, r26
_80066c00:
    lmw	r20, 0x450(r1)
    lwz	r0, 0x484(r1)
    mtlr	r0
    addi	r1, r1, 0x480
    blr
}

asm void fn_80066C14(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r22, 8(r1)
    mr	r24, r4
    cmplwi	r24, 0x10
    mr	r23, r3
    li	r28, 0
    bc      12, 0, _80066c40
    li	r3, -1
    b       _800672d0
_80066c40:
    lwz	r4, -0x7740(r13)
    slwi	r31, r24, 4
    lwzx	r3, r4, r31
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      4, 2, _800672c8
    lwz	r3, 0(r23)
    li	r27, 0x20
    addis	r0, r3, -0x6763
    cmplwi	r0, 0x6178
    bc      4, 2, _800672c0
    lwz	r3, 4(r23)
    addis	r0, r3, -0x4454
    cmplwi	r0, 0x504b
    bc      4, 2, _80066cc4
    lwz	r3, 8(r23)
    lis	r0, 0x228
    cmplw	r3, r0
    bc      12, 0, _80066cbc
    lbz	r0, 0x45f(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066cb4
    addi	r3, r23, 0x20
    li	r27, 0xa0
    bl      fn_80065B08
    cmpwi	r3, 0
    bc      12, 2, _80066cc8
    li	r28, -4
    b       _80066cc8
_80066cb4:
    li	r27, 0xa0
    b       _80066cc8
_80066cbc:
    li	r28, -9
    b       _80066cc8
_80066cc4:
    li	r28, -2
_80066cc8:
    lwz	r3, 0xa4(r23)
    addi	r27, r27, 0x20
    addis	r0, r3, -0x5442
    cmplwi	r0, 0x4c44
    bc      4, 2, _80066e74
    cmpwi	r28, 0
    bc      4, 2, _80066e74
    lwz	r6, -0x7740(r13)
    li	r26, -1
    lbz	r25, 0xc9(r23)
    lbz	r0, 0x460(r6)
    lwz	r30, 0xac(r23)
    add	r0, r0, r25
    lwz	r7, 0xc0(r23)
    cmpwi	r0, 0x40
    lwz	r29, 0xc4(r23)
    bc      12, 1, _80066e70
    li	r0, 4
    mr	r3, r6
    mr	r4, r6
    li	r5, 0
    mtctr	r0
_80066d20:
    lwz	r0, 0x144(r3)
    cmplw	r0, r7
    bc      4, 2, _80066d40
    lbz	r0, 0x184(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066d40
    mr	r26, r5
    b       _80066dbc
_80066d40:
    lwz	r0, 0x148(r3)
    addi	r5, r5, 1
    cmplw	r0, r7
    bc      4, 2, _80066d64
    lbz	r0, 0x185(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066d64
    mr	r26, r5
    b       _80066dbc
_80066d64:
    lwz	r0, 0x14c(r3)
    addi	r5, r5, 1
    cmplw	r0, r7
    bc      4, 2, _80066d88
    lbz	r0, 0x186(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066d88
    mr	r26, r5
    b       _80066dbc
_80066d88:
    lwz	r0, 0x150(r3)
    addi	r5, r5, 1
    cmplw	r0, r7
    bc      4, 2, _80066dac
    lbz	r0, 0x187(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066dac
    mr	r26, r5
    b       _80066dbc
_80066dac:
    addi	r3, r3, 0x10
    addi	r4, r4, 4
    addi	r5, r5, 1
    bc      16, 0, _80066d20
_80066dbc:
    cmpwi	r26, 0
    bc      12, 0, _80066e68
    slwi	r0, r26, 2
    mr	r5, r30
    add	r3, r6, r0
    add	r4, r23, r27
    lwz	r22, 0x104(r3)
    mr	r3, r22
    bl      memcpy
    lwz	r0, -0x7740(r13)
    li	r5, 1
    add	r27, r27, r30
    clrlwi	r3, r24, 0x18
    add	r4, r0, r26
    stb	r5, 0x184(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    stw	r22, 8(r4)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    stb	r25, 0xc(r4)
    lwz	r4, -0x7740(r13)
    stwx	r29, r4, r31
    lwz	r0, -0x7740(r13)
    lbz	r5, 0xcc(r23)
    add	r4, r0, r31
    stb	r5, 0xd(r4)
    lwz	r0, -0x7740(r13)
    lbz	r5, 0xcd(r23)
    add	r4, r0, r31
    stb	r5, 0xe(r4)
    lwz	r0, 0xd0(r23)
    lwz	r4, -0x7740(r13)
    stw	r0, 0x478(r4)
    lwz	r0, 0xd4(r23)
    lwz	r4, -0x7740(r13)
    stw	r0, 0x47c(r4)
    lwz	r4, -0x7740(r13)
    lbz	r0, 0x460(r4)
    add	r0, r0, r25
    stb	r0, 0x460(r4)
    bl      SndStartChannelSequence
    b       _80066e74
_80066e68:
    li	r28, -6
    b       _80066e74
_80066e70:
    li	r28, -5
_80066e74:
    cmpwi	r28, 0
    li	r8, -1
    bc      4, 2, _800672cc
    add	r6, r23, r27
    lwz	r3, 4(r6)
    addis	r0, r3, -0x5043
    cmplwi	r0, 0x4d44
    bc      4, 2, _80067144
    lwz	r5, -0x7740(r13)
    li	r0, 4
    lwz	r9, 0xc(r6)
    li	r7, 0
    mr	r3, r5
    mr	r4, r5
    lwz	r6, 0x20(r6)
    mtctr	r0
_80066eb4:
    lwz	r0, 0x1ec(r3)
    cmplw	r0, r6
    bc      4, 2, _80066ed4
    lbz	r0, 0x22c(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066ed4
    mr	r8, r7
    b       _80066f50
_80066ed4:
    lwz	r0, 0x1f0(r3)
    addi	r7, r7, 1
    cmplw	r0, r6
    bc      4, 2, _80066ef8
    lbz	r0, 0x22d(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066ef8
    mr	r8, r7
    b       _80066f50
_80066ef8:
    lwz	r0, 0x1f4(r3)
    addi	r7, r7, 1
    cmplw	r0, r6
    bc      4, 2, _80066f1c
    lbz	r0, 0x22e(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066f1c
    mr	r8, r7
    b       _80066f50
_80066f1c:
    lwz	r0, 0x1f8(r3)
    addi	r7, r7, 1
    cmplw	r0, r6
    bc      4, 2, _80066f40
    lbz	r0, 0x22f(r4)
    cmplwi	r0, 0
    bc      4, 2, _80066f40
    mr	r8, r7
    b       _80066f50
_80066f40:
    addi	r3, r3, 0x10
    addi	r4, r4, 4
    addi	r7, r7, 1
    bc      16, 0, _80066eb4
_80066f50:
    cmpwi	r8, 0
    bc      12, 0, _80066fcc
    add	r3, r5, r8
    li	r5, 1
    stb	r5, 0x22c(r3)
    add	r7, r27, r23
    slwi	r6, r8, 2
    cmplwi	r9, 0
    lwz	r0, -0x7740(r13)
    addi	r7, r7, 0x20
    add	r4, r0, r6
    add	r3, r0, r31
    lwz	r0, 0x1ac(r4)
    stw	r0, 4(r3)
    bc      12, 2, _800672cc
    lwz	r0, -0x7740(r13)
    lis     r3, lbl_80193B08@ha
    stw	r5, -0x7744(r13)
    lis     r4, fn_80065AC4@ha
    add	r5, r0, r6
    addi	r3, r3, lbl_80193B08@l
    lwz	r8, 0x1ac(r5)
    addi	r10, r4, fn_80065AC4@l
    li	r4, 0
    li	r5, 0
    li	r6, 1
    bl      ARQPostRequest
_80066fbc:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      12, 2, _800672cc
    b       _80066fbc
_80066fcc:
    cmplwi	r24, 0x10
    bc      4, 0, _8006713c
    lwzx	r3, r5, r31
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _8006713c
    mr	r3, r24
    bl      SndBoostVoicePriority
    clrlwi	r3, r24, 0x18
    li	r4, 0
    bl      SndReleaseProcsForVoices
    clrlwi	r3, r24, 0x18
    li	r4, 1
    bl      SndReleaseProcsForVoices
    lwz	r9, -0x7740(r13)
    li	r7, -1
    li	r6, 0xff
    li	r3, 0
    add	r4, r9, r31
    lbz	r5, 0x460(r9)
    lbz	r8, 0xc(r4)
    li	r0, 8
    mr	r4, r3
    subf	r5, r8, r5
    stb	r5, 0x460(r9)
    lwz	r5, -0x7740(r13)
    stwx	r7, r5, r31
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xe(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xd(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r3, 0xc(r5)
    mtctr	r0
_80067060:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x104
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80067094
    addi	r0, r3, 0x184
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80067094:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1ac
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _800670c8
    addi	r0, r3, 0x22c
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_800670c8:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x108
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _800670fc
    addi	r0, r3, 0x185
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_800670fc:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1b0
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80067130
    addi	r0, r3, 0x22d
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_80067130:
    addi	r4, r4, 8
    addi	r3, r3, 2
    bc      16, 0, _80067060
_8006713c:
    li	r28, -7
    b       _800672cc
_80067144:
    cmplwi	r24, 0x10
    bc      4, 0, _800672b8
    lwz	r3, -0x7740(r13)
    lwzx	r3, r3, r31
    addis	r0, r3, 1
    cmplwi	r0, 0xffff
    bc      12, 2, _800672b8
    mr	r3, r24
    bl      SndBoostVoicePriority
    clrlwi	r3, r24, 0x18
    li	r4, 0
    bl      SndReleaseProcsForVoices
    clrlwi	r3, r24, 0x18
    li	r4, 1
    bl      SndReleaseProcsForVoices
    lwz	r9, -0x7740(r13)
    li	r7, -1
    li	r6, 0xff
    li	r3, 0
    add	r4, r9, r31
    lbz	r5, 0x460(r9)
    lbz	r8, 0xc(r4)
    li	r0, 8
    mr	r4, r3
    subf	r5, r8, r5
    stb	r5, 0x460(r9)
    lwz	r5, -0x7740(r13)
    stwx	r7, r5, r31
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xe(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r6, 0xd(r5)
    lwz	r5, -0x7740(r13)
    add	r5, r5, r31
    stb	r3, 0xc(r5)
    mtctr	r0
_800671dc:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x104
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80067210
    addi	r0, r3, 0x184
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80067210:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1ac
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80067244
    addi	r0, r3, 0x22c
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_80067244:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x108
    addi	r0, r7, 8
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _80067278
    addi	r0, r3, 0x185
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 8
    stwx	r6, r31, r0
_80067278:
    lwz	r7, -0x7740(r13)
    addi	r5, r4, 0x1b0
    addi	r0, r7, 4
    lwzx	r5, r7, r5
    lwzx	r0, r31, r0
    cmplw	r5, r0
    bc      4, 2, _800672ac
    addi	r0, r3, 0x22d
    li	r6, 0
    stbx	r6, r7, r0
    lwz	r5, -0x7740(r13)
    addi	r0, r5, 4
    stwx	r6, r31, r0
_800672ac:
    addi	r4, r4, 8
    addi	r3, r3, 2
    bc      16, 0, _800671dc
_800672b8:
    li	r28, -2
    b       _800672cc
_800672c0:
    li	r28, -2
    b       _800672cc
_800672c8:
    li	r28, -3
_800672cc:
    mr	r3, r28
_800672d0:
    lmw	r22, 8(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void SndGetSequenceStatus(void)
{
    nofralloc
    cmplwi	r3, 0x10
    bc      12, 0, _800672f4
    li	r3, -0x80
    blr
_800672f4:
    lis	r0, -0x5ff0
    cmpw	r4, r0
    bc      12, 2, _80067328
    bc      4, 0, _8006733c
    lis	r0, -0x5ffc
    cmpw	r4, r0
    bc      12, 2, _80067314
    b       _8006733c
_80067314:
    lwz	r4, -0x7740(r13)
    slwi	r0, r3, 4
    add	r3, r4, r0
    lbz	r3, 0x492(r3)
    blr
_80067328:
    lwz	r4, -0x7740(r13)
    slwi	r0, r3, 4
    add	r3, r4, r0
    lbz	r3, 0x493(r3)
    blr
_8006733c:
    li	r3, -0x80
    blr
}

asm void fn_80067344(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r5, 0
    clrlwi	r3, r3, 0x1b
    stw	r0, 0x14(r1)
    addi	r0, r4, -1
    rlwinm	r0, r0, 0x18, 4, 7
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    add	r30, r0, r5
    add	r30, r3, r30
    bc      12, 2, _80067438
    lis	r0, -0x4fd9
    cmpw	r5, r0
    bc      12, 2, _80067414
    bc      4, 0, _800673d4
    lis	r0, -0x4ff6
    cmpw	r5, r0
    bc      12, 2, _80067420
    bc      4, 0, _800673b4
    lis	r0, -0x4ff9
    cmpw	r5, r0
    bc      12, 2, _80067414
    bc      4, 0, _80067430
    lis	r0, -0x5fef
    cmpw	r5, r0
    bc      12, 2, _80067420
    b       _80067430
_800673b4:
    lis	r0, -0x4ff2
    cmpw	r5, r0
    bc      12, 2, _80067414
    bc      4, 0, _80067430
    lis	r0, -0x4ff3
    cmpw	r5, r0
    bc      12, 2, _80067414
    b       _80067430
_800673d4:
    lis	r0, -0x4fd2
    cmpw	r5, r0
    bc      12, 2, _80067414
    bc      4, 0, _80067404
    lis	r0, -0x4fd3
    cmpw	r5, r0
    bc      12, 2, _80067414
    bc      4, 0, _80067430
    lis	r0, -0x4fd6
    cmpw	r5, r0
    bc      12, 2, _80067420
    b       _80067430
_80067404:
    lis	r0, -0x4f88
    cmpw	r5, r0
    bc      12, 2, _80067438
    b       _80067430
_80067414:
    rlwinm	r0, r6, 8, 0x11, 0x17
    add	r30, r30, r0
    b       _80067438
_80067420:
    addi	r0, r6, 0x40
    rlwinm	r0, r0, 8, 0x11, 0x17
    add	r30, r30, r0
    b       _80067438
_80067430:
    li	r3, -2
    b       _800674e4
_80067438:
    lwz	r4, -0x7740(r13)
    li	r31, 0
    lbz	r0, 0x464(r4)
    extsb.	r0, r0
    bc      12, 2, _80067454
    li	r31, -3
    b       _800674e0
_80067454:
    li	r3, -1
    rlwinm.	r0, r30, 0, 0, 0
    stb	r3, 0x464(r4)
    bc      4, 2, _8006746c
    li	r31, -2
    b       _800674d4
_8006746c:
    bl      OSDisableInterrupts
    stw	r3, -0x7748(r13)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x441(r3)
    cmplwi	r0, 0x40
    bc      4, 0, _800674c8
    lbz	r0, 0x443(r3)
    slwi	r0, r0, 2
    add	r3, r3, r0
    lwz	r0, 0x240(r3)
    cmplwi	r0, 0
    bc      4, 2, _800674c8
    stw	r30, 0x240(r3)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x443(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x443(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x441(r4)
    addi	r0, r3, 1
    stb	r0, 0x441(r4)
    b       _800674cc
_800674c8:
    li	r31, -1
_800674cc:
    lwz	r3, -0x7748(r13)
    bl      OSRestoreInterrupts
_800674d4:
    lwz	r3, -0x7740(r13)
    li	r0, 0
    stb	r0, 0x464(r3)
_800674e0:
    mr	r3, r31
_800674e4:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_800674FC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    clrlwi	r6, r3, 0x1b
    clrlwi	r7, r3, 0x10
    stw	r0, 0x14(r1)
    rlwinm.	r0, r4, 0, 8, 0xf
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    add	r30, r6, r4
    bc      12, 2, _800677d4
    lis	r0, -0x5ff0
    cmpw	r4, r0
    bc      12, 2, _80067634
    bc      4, 0, _800675b4
    lis	r0, -0x5ffb
    cmpw	r4, r0
    bc      12, 2, _80067640
    bc      4, 0, _80067584
    lis	r0, -0x5ffd
    cmpw	r4, r0
    bc      12, 2, _800677d4
    bc      4, 0, _80067574
    lis	r0, -0x5ffe
    cmpw	r4, r0
    bc      12, 2, _800677d4
    bc      4, 0, _800677cc
    lis	r0, -0x5fff
    cmpw	r4, r0
    bc      12, 2, _80067634
    b       _800677cc
_80067574:
    lis	r0, -0x5ffc
    cmpw	r4, r0
    bc      12, 2, _80067634
    b       _800677cc
_80067584:
    lis	r0, -0x5ff7
    cmpw	r4, r0
    bc      12, 2, _80067634
    bc      4, 0, _800675a4
    lis	r0, -0x5ff9
    cmpw	r4, r0
    bc      12, 2, _80067640
    b       _800677cc
_800675a4:
    lis	r0, -0x5ff6
    cmpw	r4, r0
    bc      12, 2, _80067634
    b       _800677cc
_800675b4:
    lis	r0, -0x5fd7
    cmpw	r4, r0
    bc      12, 2, _80067654
    bc      4, 0, _80067604
    lis	r0, -0x5fe4
    cmpw	r4, r0
    bc      12, 2, _80067634
    bc      4, 0, _800675f4
    lis	r0, -0x5fe7
    cmpw	r4, r0
    bc      12, 2, _80067634
    bc      4, 0, _800677cc
    lis	r0, -0x5fef
    cmpw	r4, r0
    bc      12, 2, _80067640
    b       _800677cc
_800675f4:
    lis	r0, -0x5fd8
    cmpw	r4, r0
    bc      12, 2, _80067654
    b       _800677cc
_80067604:
    lis	r0, -0x5fcc
    cmpw	r4, r0
    bc      12, 2, _80067674
    bc      4, 0, _80067624
    lis	r0, -0x5fcf
    cmpw	r4, r0
    bc      12, 2, _80067668
    b       _800677cc
_80067624:
    lis	r0, -0x5fc0
    cmpw	r4, r0
    bc      12, 2, _80067720
    b       _800677cc
_80067634:
    rlwinm	r0, r5, 8, 0x11, 0x17
    add	r30, r30, r0
    b       _800677d4
_80067640:
    extsh	r3, r5
    addi	r0, r3, 0x40
    rlwinm	r0, r0, 8, 0x11, 0x17
    add	r30, r30, r0
    b       _800677d4
_80067654:
    extsh	r3, r5
    addi	r0, r3, -1
    rlwinm	r0, r0, 8, 0x14, 0x17
    add	r30, r30, r0
    b       _800677d4
_80067668:
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5a12(r3)
    b       _800677d4
_80067674:
    rlwinm.	r0, r7, 0, 0x1b, 0x1b
    bc      12, 2, _8006770c
    li	r0, 0
    cmpwi	r0, 0x10
    bc      4, 0, _800677d4
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ab4(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ab6(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ab8(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5aba(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5abc(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5abe(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ac0(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ac2(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ac4(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ac6(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ac8(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5aca(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5acc(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ace(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ad0(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ad2(r3)
    b       _800677d4
_8006770c:
    lwz	r4, -0x7740(r13)
    rlwinm	r0, r3, 1, 0xf, 0x1e
    add	r3, r4, r0
    sth	r5, 0x5ab4(r3)
    b       _800677d4
_80067720:
    rlwinm.	r0, r7, 0, 0x1b, 0x1b
    bc      12, 2, _800677b8
    li	r0, 0
    cmpwi	r0, 0x10
    bc      4, 0, _800677d4
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ad4(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ad6(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ad8(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ada(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5adc(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ade(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ae0(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ae2(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ae4(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ae6(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5ae8(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5aea(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5aec(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5aee(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5af0(r3)
    lwz	r3, -0x7740(r13)
    sth	r5, 0x5af2(r3)
    b       _800677d4
_800677b8:
    lwz	r4, -0x7740(r13)
    rlwinm	r0, r3, 1, 0xf, 0x1e
    add	r3, r4, r0
    sth	r5, 0x5ad4(r3)
    b       _800677d4
_800677cc:
    li	r3, -2
    b       _80067880
_800677d4:
    lwz	r4, -0x7740(r13)
    li	r31, 0
    lbz	r0, 0x464(r4)
    extsb.	r0, r0
    bc      12, 2, _800677f0
    li	r31, -3
    b       _8006787c
_800677f0:
    li	r3, -1
    rlwinm.	r0, r30, 0, 0, 0
    stb	r3, 0x464(r4)
    bc      4, 2, _80067808
    li	r31, -2
    b       _80067870
_80067808:
    bl      OSDisableInterrupts
    stw	r3, -0x7748(r13)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x441(r3)
    cmplwi	r0, 0x40
    bc      4, 0, _80067864
    lbz	r0, 0x443(r3)
    slwi	r0, r0, 2
    add	r3, r3, r0
    lwz	r0, 0x240(r3)
    cmplwi	r0, 0
    bc      4, 2, _80067864
    stw	r30, 0x240(r3)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x443(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x443(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x441(r4)
    addi	r0, r3, 1
    stb	r0, 0x441(r4)
    b       _80067868
_80067864:
    li	r31, -1
_80067868:
    lwz	r3, -0x7748(r13)
    bl      OSRestoreInterrupts
_80067870:
    lwz	r3, -0x7740(r13)
    li	r0, 0
    stb	r0, 0x464(r3)
_8006787c:
    mr	r3, r31
_80067880:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_80067898(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    li	r31, 0
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r4, -0x7740(r13)
    lbz	r0, 0x464(r4)
    extsb.	r0, r0
    bc      12, 2, _800678cc
    li	r3, -3
    b       _8006795c
_800678cc:
    li	r3, -1
    rlwinm.	r0, r30, 0, 0, 0
    stb	r3, 0x464(r4)
    bc      4, 2, _800678e4
    li	r31, -2
    b       _8006794c
_800678e4:
    bl      OSDisableInterrupts
    stw	r3, -0x7748(r13)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x441(r3)
    cmplwi	r0, 0x40
    bc      4, 0, _80067940
    lbz	r0, 0x443(r3)
    slwi	r0, r0, 2
    add	r3, r3, r0
    lwz	r0, 0x240(r3)
    cmplwi	r0, 0
    bc      4, 2, _80067940
    stw	r30, 0x240(r3)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x443(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x443(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x441(r4)
    addi	r0, r3, 1
    stb	r0, 0x441(r4)
    b       _80067944
_80067940:
    li	r31, -1
_80067944:
    lwz	r3, -0x7748(r13)
    bl      OSRestoreInterrupts
_8006794c:
    lwz	r4, -0x7740(r13)
    li	r0, 0
    mr	r3, r31
    stb	r0, 0x464(r4)
_8006795c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void SndTimerUpdate(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x45d(r3)
    cmplwi	r0, 1
    bc      4, 2, _80067dc8
    li	r0, 0
    stb	r0, 0x45d(r3)
    bl      OSGetTick
    lis	r5, -0x8000
    lis	r4, 0x431c
    lwz	r5, 0xf8(r5)
    lis	r0, 0x4330
    lwz	r7, -0x7740(r13)
    addi	r6, r4, -0x217d
    srwi	r4, r5, 2
    mr	r31, r3
    mulhwu	r3, r6, r4
    lwz	r4, 0x5b14(r7)
    stw	r0, 8(r1)
    subf	r0, r4, r31
    lfd	f2, -0x7b00(r2)
    lfd	f0, -0x7b08(r2)
    slwi	r4, r0, 3
    srwi	r0, r3, 0xf
    divwu	r0, r4, r0
    lfd	f3, -0x7b10(r2)
    stw	r0, 0xc(r1)
    lfd	f1, 8(r1)
    fsubs	f1, f1, f2
    fdiv	f0, f1, f0
    fadd	f1, f3, f0
    frsp	f1, f1
    bl      fn_80087F54
    bl      __cvt_fp2unsigned
    lwz	r4, -0x7740(r13)
    cmplwi	r3, 0
    stw	r3, 0x450(r4)
    bc      12, 2, _80067a70
    li	r6, 0
    b       _80067a64
_80067a28:
    clrlwi	r0, r6, 0x18
    lwz	r4, -0x7740(r13)
    mulli	r0, r0, 0x28
    add	r5, r4, r0
    lbz	r0, 0x1188(r5)
    cmpwi	r0, 0
    bc      12, 2, _80067a60
    clrlwi.	r0, r0, 0x1f
    bc      4, 2, _80067a60
    lwz	r4, 0x118c(r5)
    lwz	r0, 0x1194(r5)
    mullw	r4, r4, r3
    subf	r0, r4, r0
    stw	r0, 0x1194(r5)
_80067a60:
    addi	r6, r6, 1
_80067a64:
    clrlwi	r0, r6, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80067a28
_80067a70:
    lwz	r3, -0x7740(r13)
    li	r30, 0
    stw	r31, 0x5b14(r3)
    b       _80067bb0
_80067a80:
    clrlwi	r31, r30, 0x18
    lwz	r0, -0x7740(r13)
    mulli	r29, r31, 0x118
    add	r6, r0, r29
    lbz	r4, 0x1408(r6)
    cmplwi	r4, 0xff
    bc      12, 2, _80067bac
    lwz	r3, 0x1434(r6)
    lhz	r0, 0x146(r3)
    cmplwi	r0, 0
    bc      4, 2, _80067acc
    cmplwi	r4, 4
    bc      4, 2, _80067ac0
    lbz	r0, 0x1409(r6)
    cmplwi	r0, 0
    bc      12, 2, _80067bac
_80067ac0:
    mr	r3, r31
    bl      SndKillChannelVoice
    b       _80067bac
_80067acc:
    lbz	r0, 0x1409(r6)
    cmplwi	r0, 2
    bc      4, 2, _80067b58
    cmplwi	r4, 3
    bc      4, 2, _80067b30
    bl      fn_80026DB8
    lwz	r5, -0x7740(r13)
    addi	r6, r29, 0x1416
    lhzx	r4, r5, r6
    cmplwi	r4, 0
    bc      12, 2, _80067b00
    cmpwi	r3, -0x1c2
    bc      12, 1, _80067b0c
_80067b00:
    mr	r3, r31
    bl      SndKillChannelVoice
    b       _80067bac
_80067b0c:
    addi	r0, r4, -1
    sthx	r0, r5, r6
    lwz	r0, -0x7740(r13)
    add	r5, r0, r29
    lwz	r0, 0x1418(r5)
    add	r4, r3, r0
    lwz	r3, 0x1434(r5)
    bl      fn_80026D90
    b       _80067bac
_80067b30:
    lhz	r0, 0x1416(r6)
    cmplwi	r0, 2
    bc      4, 2, _80067bac
    lwz	r3, 0x14c4(r6)
    addis	r0, r3, 0x3c0
    cmplwi	r0, 0
    bc      4, 2, _80067bac
    mr	r3, r31
    bl      SndKillChannelVoice
    b       _80067bac
_80067b58:
    cmplwi	r0, 1
    bc      4, 2, _80067bac
    lhz	r0, 0x1416(r6)
    cmplwi	r0, 0
    bc      4, 2, _80067bac
    lwz	r0, 0x14c4(r6)
    cmpwi	r0, 0
    bc      4, 2, _80067bac
    lwz	r7, 0x1424(r6)
    addi	r3, r29, 0x14c0
    addi	r0, r29, 0x1416
    li	r4, 1
    lha	r5, 0xe(r7)
    slwi	r5, r5, 0x10
    stw	r5, 0x14bc(r6)
    lha	r6, 0x10(r7)
    lwz	r5, -0x7740(r13)
    slwi	r6, r6, 0x10
    stwx	r6, r5, r3
    lwz	r3, -0x7740(r13)
    sthx	r4, r3, r0
_80067bac:
    addi	r30, r30, 1
_80067bb0:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 0x40
    bc      12, 0, _80067a80
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x441(r3)
    lbz	r30, 0x45e(r3)
    cmplwi	r0, 0
    bc      12, 2, _80067d34
_80067bd0:
    lwz	r6, -0x7740(r13)
    lbz	r0, 0x45a(r6)
    slwi	r3, r0, 2
    addi	r0, r3, 0x240
    lwzx	r3, r6, r0
    srwi	r0, r3, 0x18
    cmplwi	r0, 0xa0
    bc      4, 2, _80067c40
    lbz	r0, 0x440(r6)
    cmplwi	r0, 0x40
    bc      4, 0, _80067c34
    lbz	r0, 0x459(r6)
    ori	r5, r3, 0x40
    slwi	r4, r0, 2
    addi	r0, r4, 0x340
    stwx	r5, r6, r0
    lwz	r5, -0x7740(r13)
    lbz	r4, 0x459(r5)
    addi	r0, r4, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x459(r5)
    lwz	r5, -0x7740(r13)
    lbz	r4, 0x440(r5)
    addi	r0, r4, 1
    stb	r0, 0x440(r5)
_80067c34:
    ori	r3, r3, 0x40
    bl      SndAllocBankEntry
    b       _80067cdc
_80067c40:
    cmplwi	r0, 0xa8
    bc      4, 0, _80067c8c
    lbz	r0, 0x440(r6)
    cmplwi	r0, 0x40
    bc      4, 0, _80067cdc
    lbz	r0, 0x459(r6)
    slwi	r4, r0, 2
    addi	r0, r4, 0x340
    stwx	r3, r6, r0
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x459(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x459(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x440(r4)
    addi	r0, r3, 1
    stb	r0, 0x440(r4)
    b       _80067cdc
_80067c8c:
    cmplwi	r0, 0xad
    bc      4, 0, _80067c9c
    bl      SndAllocBankEntry
    b       _80067cdc
_80067c9c:
    lbz	r0, 0x440(r6)
    cmplwi	r0, 0x40
    bc      4, 0, _80067cdc
    lbz	r0, 0x459(r6)
    slwi	r4, r0, 2
    addi	r0, r4, 0x340
    stwx	r3, r6, r0
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x459(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x459(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x440(r4)
    addi	r0, r3, 1
    stb	r0, 0x440(r4)
_80067cdc:
    lwz	r5, -0x7740(r13)
    li	r4, 0
    addi	r30, r30, -1
    lbz	r0, 0x45a(r5)
    slwi	r3, r0, 2
    addi	r0, r3, 0x240
    stwx	r4, r5, r0
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x45a(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x45a(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x441(r4)
    addi	r0, r3, -1
    stb	r0, 0x441(r4)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x441(r3)
    cmplwi	r0, 0
    bc      12, 2, _80067d34
    clrlwi.	r0, r30, 0x18
    bc      4, 2, _80067bd0
_80067d34:
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x440(r3)
    cmplwi	r0, 0
    bc      12, 2, _80067da8
    li	r30, 0
_80067d48:
    lwz	r4, -0x7740(r13)
    lbz	r0, 0x442(r4)
    slwi	r3, r0, 2
    addi	r0, r3, 0x340
    lwzx	r3, r4, r0
    bl      SndDispatchCommand
    lwz	r4, -0x7740(r13)
    lbz	r0, 0x442(r4)
    slwi	r3, r0, 2
    addi	r0, r3, 0x340
    stwx	r30, r4, r0
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x442(r4)
    addi	r0, r3, 1
    clrlwi	r0, r0, 0x1a
    stb	r0, 0x442(r4)
    lwz	r4, -0x7740(r13)
    lbz	r3, 0x440(r4)
    addi	r0, r3, -1
    stb	r0, 0x440(r4)
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x440(r3)
    cmplwi	r0, 0
    bc      4, 2, _80067d48
_80067da8:
    bl      fn_80068EB4
    lwz	r4, -0x7740(r13)
    li	r0, 1
    lwz	r3, 0x468(r4)
    addi	r3, r3, 1
    stw	r3, 0x468(r4)
    lwz	r3, -0x7740(r13)
    stb	r0, 0x45d(r3)
_80067dc8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void SndCheckAllocSize(void)
{
    nofralloc
    stwu	r1, -0x420(r1)
    mflr	r0
    lis	r4, -0x6000
    lis     r5, lbl_801932A8@ha
    stw	r0, 0x424(r1)
    addi	r0, r4, 0x110
    stw	r31, 0x41c(r1)
    addi	r31, r5, lbl_801932A8@l
    lwz	r3, -0x7740(r13)
    stw	r0, 0x444(r3)
    addi	r3, r4, 0x100
    bl      SndStopAllChannelVoices
    bl      fn_800622B0
    lis	r4, -0x6000
    li	r3, 0x10
    addi	r4, r4, 0x500
    li	r5, 0
    bl      fn_80069CE4
    lwz	r4, -0x7740(r13)
    lwz	r0, 0x454(r4)
    cmplwi	r0, 0
    bc      4, 2, _80067e80
    lwz	r3, -0x7fb0(r13)
    lwz	r4, 0x100(r4)
    bl      OSFree
    addi	r3, r1, 8
    bl      ARFree
    lwz	r3, -0x7740(r13)
    lwz	r5, 8(r1)
    lwz	r0, 0x23c(r3)
    cmplw	r0, r5
    bc      12, 2, _80067e80
    lis     r3, Not_Sound_Allocation_Size_d_str@ha
    addi	r4, r3, Not_Sound_Allocation_Size_d_str@l
    addi	r3, r1, 0xc
    crxor	6, 6, 6
    bl      sprintf
    lwz	r3, 8(r1)
    b       _80067f54
_80067e80:
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x470(r3)
    cmpwi	r0, 2
    bc      12, 2, _80067ec8
    bc      4, 0, _80067ea4
    cmpwi	r0, 0
    bc      12, 2, _80067eb0
    bc      4, 0, _80067ebc
    b       _80067edc
_80067ea4:
    cmpwi	r0, 4
    bc      4, 0, _80067edc
    b       _80067ed4
_80067eb0:
    addi	r3, r31, 0x70c
    bl      fn_80024DF0
    b       _80067edc
_80067ebc:
    addi	r3, r31, 0x3d8
    bl      fn_80024378
    b       _80067edc
_80067ec8:
    addi	r3, r31, 0x15c
    bl      fn_800253F0
    b       _80067edc
_80067ed4:
    addi	r3, r31, 0x60
    bl      fn_80025C70
_80067edc:
    li	r3, 0
    li	r4, 0
    bl      fn_800211E0
    lwz	r3, -0x7740(r13)
    lbz	r0, 0x471(r3)
    cmpwi	r0, 2
    bc      12, 2, _80067f30
    bc      4, 0, _80067f0c
    cmpwi	r0, 0
    bc      12, 2, _80067f18
    bc      4, 0, _80067f24
    b       _80067f44
_80067f0c:
    cmpwi	r0, 4
    bc      4, 0, _80067f44
    b       _80067f3c
_80067f18:
    addi	r3, r31, 0x5b8
    bl      fn_80024DF0
    b       _80067f44
_80067f24:
    addi	r3, r31, 0x1f8
    bl      fn_80024378
    b       _80067f44
_80067f30:
    addi	r3, r31, 0xc0
    bl      fn_800253F0
    b       _80067f44
_80067f3c:
    addi	r3, r31, 0
    bl      fn_80025C70
_80067f44:
    li	r3, 0
    li	r4, 0
    bl      fn_800211EC
    li	r3, 0
_80067f54:
    lwz	r0, 0x424(r1)
    lwz	r31, 0x41c(r1)
    mtlr	r0
    addi	r1, r1, 0x420
    blr
}

asm void fn_80067F68(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    li	r3, 0
    li	r9, 1
    stw	r0, 0x54(r1)
    li	r8, 0x7f
    li	r7, 0x40
    li	r6, 0xff
    stmw	r14, 8(r1)
    li	r5, -1
    li	r0, 8
    lwz	r4, -0x7740(r13)
    stb	r3, 0x440(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x441(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x442(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x443(r4)
    lwz	r4, -0x7740(r13)
    stw	r3, 0x444(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x459(r4)
    lwz	r4, -0x7740(r13)
    stw	r9, 0x44c(r4)
    lwz	r4, -0x7740(r13)
    stb	r9, 0x45d(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x45a(r4)
    lwz	r4, -0x7740(r13)
    stw	r3, 0x448(r4)
    lwz	r4, -0x7740(r13)
    stw	r3, 0x468(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x45f(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x460(r4)
    lwz	r4, -0x7740(r13)
    stb	r8, 0x461(r4)
    lwz	r4, -0x7740(r13)
    stb	r9, 0x462(r4)
    lwz	r4, -0x7740(r13)
    stb	r9, 0x463(r4)
    lwz	r4, -0x7740(r13)
    stb	r7, 0x45e(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x464(r4)
    lwz	r4, -0x7740(r13)
    stb	r6, 0x470(r4)
    lwz	r4, -0x7740(r13)
    stb	r6, 0x471(r4)
    lwz	r4, -0x7740(r13)
    stb	r6, 0x472(r4)
    lwz	r4, -0x7740(r13)
    stb	r6, 0x473(r4)
    lwz	r4, -0x7740(r13)
    stw	r3, 0x46c(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x465(r4)
    lwz	r4, -0x7740(r13)
    stw	r3, 0x5b18(r4)
    lwz	r4, -0x7740(r13)
    stw	r3, 0x5b1c(r4)
    lwz	r4, -0x7740(r13)
    stw	r5, 0x5b20(r4)
    mtctr	r0
_80068070:
    lwz	r6, -0x7740(r13)
    addi	r0, r3, 0x240
    li	r4, 0
    addi	r5, r3, 0x340
    stwx	r4, r6, r0
    addi	r0, r3, 0x244
    addi	r17, r3, 0x344
    addi	r16, r3, 0x248
    lwz	r6, -0x7740(r13)
    addi	r15, r3, 0x348
    addi	r14, r3, 0x24c
    addi	r12, r3, 0x34c
    stwx	r4, r6, r5
    addi	r11, r3, 0x250
    addi	r10, r3, 0x350
    addi	r9, r3, 0x254
    lwz	r5, -0x7740(r13)
    addi	r8, r3, 0x354
    addi	r7, r3, 0x258
    addi	r6, r3, 0x358
    stwx	r4, r5, r0
    addi	r5, r3, 0x25c
    addi	r0, r3, 0x35c
    addi	r3, r3, 0x20
    lwz	r18, -0x7740(r13)
    stwx	r4, r18, r17
    lwz	r17, -0x7740(r13)
    stwx	r4, r17, r16
    lwz	r16, -0x7740(r13)
    stwx	r4, r16, r15
    lwz	r15, -0x7740(r13)
    stwx	r4, r15, r14
    lwz	r14, -0x7740(r13)
    stwx	r4, r14, r12
    lwz	r12, -0x7740(r13)
    stwx	r4, r12, r11
    lwz	r11, -0x7740(r13)
    stwx	r4, r11, r10
    lwz	r10, -0x7740(r13)
    stwx	r4, r10, r9
    lwz	r9, -0x7740(r13)
    stwx	r4, r9, r8
    lwz	r8, -0x7740(r13)
    stwx	r4, r8, r7
    lwz	r7, -0x7740(r13)
    stwx	r4, r7, r6
    lwz	r6, -0x7740(r13)
    stwx	r4, r6, r5
    lwz	r5, -0x7740(r13)
    stwx	r4, r5, r0
    bc      16, 0, _80068070
    li	r0, 8
    mtctr	r0
_80068144:
    lwz	r5, -0x7740(r13)
    addi	r3, r4, 0x1408
    li	r0, 0xff
    addi	r8, r4, 0x1424
    stbx	r0, r5, r3
    li	r5, 0
    addi	r7, r4, 0x1428
    addi	r6, r4, 0x1434
    lwz	r9, -0x7740(r13)
    addi	r3, r4, 0x1409
    addi	r26, r4, 0x1411
    addi	r25, r4, 0x1412
    stwx	r5, r9, r8
    addi	r24, r4, 0x1520
    addi	r23, r4, 0x153c
    addi	r22, r4, 0x1540
    lwz	r8, -0x7740(r13)
    addi	r21, r4, 0x154c
    addi	r20, r4, 0x1521
    addi	r19, r4, 0x1529
    stwx	r5, r8, r7
    addi	r18, r4, 0x152a
    addi	r17, r4, 0x1638
    addi	r16, r4, 0x1654
    lwz	r7, -0x7740(r13)
    addi	r15, r4, 0x1658
    addi	r14, r4, 0x1664
    addi	r12, r4, 0x1639
    stwx	r5, r7, r6
    addi	r11, r4, 0x1641
    addi	r10, r4, 0x1642
    addi	r9, r4, 0x1750
    lwz	r27, -0x7740(r13)
    addi	r8, r4, 0x176c
    addi	r7, r4, 0x1770
    addi	r6, r4, 0x177c
    stbx	r5, r27, r3
    addi	r3, r4, 0x1751
    lwz	r27, -0x7740(r13)
    stbx	r0, r27, r26
    lwz	r26, -0x7740(r13)
    stbx	r0, r26, r25
    lwz	r25, -0x7740(r13)
    stbx	r0, r25, r24
    lwz	r24, -0x7740(r13)
    stwx	r5, r24, r23
    lwz	r23, -0x7740(r13)
    stwx	r5, r23, r22
    lwz	r22, -0x7740(r13)
    stwx	r5, r22, r21
    lwz	r21, -0x7740(r13)
    stbx	r5, r21, r20
    lwz	r20, -0x7740(r13)
    stbx	r0, r20, r19
    lwz	r19, -0x7740(r13)
    stbx	r0, r19, r18
    lwz	r18, -0x7740(r13)
    stbx	r0, r18, r17
    lwz	r17, -0x7740(r13)
    stwx	r5, r17, r16
    lwz	r16, -0x7740(r13)
    stwx	r5, r16, r15
    lwz	r15, -0x7740(r13)
    stwx	r5, r15, r14
    lwz	r14, -0x7740(r13)
    stbx	r5, r14, r12
    lwz	r12, -0x7740(r13)
    stbx	r0, r12, r11
    lwz	r11, -0x7740(r13)
    stbx	r0, r11, r10
    lwz	r10, -0x7740(r13)
    stbx	r0, r10, r9
    lwz	r9, -0x7740(r13)
    stwx	r5, r9, r8
    lwz	r8, -0x7740(r13)
    stwx	r5, r8, r7
    lwz	r7, -0x7740(r13)
    stwx	r5, r7, r6
    lwz	r6, -0x7740(r13)
    stbx	r5, r6, r3
    lwz	r6, -0x7740(r13)
    addi	r3, r4, 0x1759
    addi	r8, r4, 0x175a
    addi	r7, r4, 0x1868
    stbx	r0, r6, r3
    addi	r6, r4, 0x1884
    addi	r3, r4, 0x1888
    addi	r15, r4, 0x1894
    lwz	r9, -0x7740(r13)
    addi	r16, r4, 0x1869
    addi	r17, r4, 0x1871
    addi	r18, r4, 0x1872
    stbx	r0, r9, r8
    addi	r19, r4, 0x1980
    addi	r20, r4, 0x199c
    addi	r21, r4, 0x19a0
    lwz	r8, -0x7740(r13)
    addi	r22, r4, 0x19ac
    addi	r23, r4, 0x1981
    addi	r24, r4, 0x1989
    stbx	r0, r8, r7
    addi	r25, r4, 0x198a
    addi	r26, r4, 0x1a98
    addi	r27, r4, 0x1ab4
    lwz	r7, -0x7740(r13)
    addi	r28, r4, 0x1ab8
    addi	r29, r4, 0x1ac4
    addi	r30, r4, 0x1a99
    stwx	r5, r7, r6
    addi	r31, r4, 0x1aa1
    addi	r12, r4, 0x1aa2
    addi	r11, r4, 0x1bb0
    lwz	r6, -0x7740(r13)
    addi	r10, r4, 0x1bcc
    addi	r9, r4, 0x1bd0
    addi	r8, r4, 0x1bdc
    stwx	r5, r6, r3
    addi	r7, r4, 0x1bb1
    addi	r6, r4, 0x1bb9
    addi	r14, r4, 0x1bba
    lwz	r3, -0x7740(r13)
    addi	r4, r4, 0x8c0
    stwx	r5, r3, r15
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r16
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r17
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r18
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r19
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r20
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r21
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r22
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r23
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r24
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r25
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r26
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r27
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r28
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r29
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r30
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r31
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r12
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r11
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r10
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r9
    lwz	r3, -0x7740(r13)
    stwx	r5, r3, r8
    lwz	r3, -0x7740(r13)
    stbx	r5, r3, r7
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r6
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r14
    bc      16, 0, _80068144
    li	r0, 8
    mtctr	r0
_800683fc:
    lwz	r3, -0x7740(r13)
    addi	r0, r5, 0x588
    li	r4, 0
    addi	r8, r5, 0x58a
    stbx	r4, r3, r0
    addi	r7, r5, 0x599
    li	r0, 0x40
    addi	r6, r5, 0x59a
    lwz	r9, -0x7740(r13)
    addi	r3, r5, 0x59b
    addi	r26, r5, 0x59c
    addi	r25, r5, 0x59d
    stbx	r4, r9, r8
    addi	r24, r5, 0x5a8
    addi	r23, r5, 0x5aa
    addi	r22, r5, 0x5b9
    lwz	r8, -0x7740(r13)
    addi	r21, r5, 0x5ba
    addi	r20, r5, 0x5bb
    addi	r19, r5, 0x5bc
    stbx	r0, r8, r7
    addi	r18, r5, 0x5bd
    addi	r17, r5, 0x5c8
    addi	r16, r5, 0x5ca
    lwz	r7, -0x7740(r13)
    addi	r15, r5, 0x5d9
    addi	r14, r5, 0x5da
    addi	r12, r5, 0x5db
    stbx	r4, r7, r6
    addi	r11, r5, 0x5dc
    addi	r10, r5, 0x5dd
    addi	r9, r5, 0x5e8
    lwz	r27, -0x7740(r13)
    addi	r8, r5, 0x5ea
    addi	r7, r5, 0x5f9
    addi	r6, r5, 0x5fa
    stbx	r4, r27, r3
    addi	r3, r5, 0x5fb
    lwz	r27, -0x7740(r13)
    stbx	r4, r27, r26
    lwz	r26, -0x7740(r13)
    stbx	r4, r26, r25
    lwz	r25, -0x7740(r13)
    stbx	r4, r25, r24
    lwz	r24, -0x7740(r13)
    stbx	r4, r24, r23
    lwz	r23, -0x7740(r13)
    stbx	r0, r23, r22
    lwz	r22, -0x7740(r13)
    stbx	r4, r22, r21
    lwz	r21, -0x7740(r13)
    stbx	r4, r21, r20
    lwz	r20, -0x7740(r13)
    stbx	r4, r20, r19
    lwz	r19, -0x7740(r13)
    stbx	r4, r19, r18
    lwz	r18, -0x7740(r13)
    stbx	r4, r18, r17
    lwz	r17, -0x7740(r13)
    stbx	r4, r17, r16
    lwz	r16, -0x7740(r13)
    stbx	r0, r16, r15
    lwz	r15, -0x7740(r13)
    stbx	r4, r15, r14
    lwz	r14, -0x7740(r13)
    stbx	r4, r14, r12
    lwz	r12, -0x7740(r13)
    stbx	r4, r12, r11
    lwz	r11, -0x7740(r13)
    stbx	r4, r11, r10
    lwz	r10, -0x7740(r13)
    stbx	r4, r10, r9
    lwz	r9, -0x7740(r13)
    stbx	r4, r9, r8
    lwz	r8, -0x7740(r13)
    stbx	r0, r8, r7
    lwz	r7, -0x7740(r13)
    stbx	r4, r7, r6
    lwz	r6, -0x7740(r13)
    stbx	r4, r6, r3
    lwz	r6, -0x7740(r13)
    addi	r3, r5, 0x5fc
    addi	r8, r5, 0x5fd
    addi	r7, r5, 0x608
    stbx	r4, r6, r3
    addi	r6, r5, 0x60a
    addi	r3, r5, 0x619
    addi	r30, r5, 0x61a
    lwz	r9, -0x7740(r13)
    addi	r29, r5, 0x61b
    addi	r28, r5, 0x61c
    addi	r27, r5, 0x61d
    stbx	r4, r9, r8
    addi	r26, r5, 0x628
    addi	r25, r5, 0x62a
    addi	r24, r5, 0x639
    lwz	r8, -0x7740(r13)
    addi	r23, r5, 0x63a
    addi	r22, r5, 0x63b
    addi	r21, r5, 0x63c
    stbx	r4, r8, r7
    addi	r20, r5, 0x63d
    addi	r19, r5, 0x648
    addi	r18, r5, 0x64a
    lwz	r7, -0x7740(r13)
    addi	r17, r5, 0x659
    addi	r16, r5, 0x65a
    addi	r15, r5, 0x65b
    stbx	r4, r7, r6
    addi	r14, r5, 0x65c
    addi	r12, r5, 0x65d
    addi	r11, r5, 0x668
    lwz	r6, -0x7740(r13)
    addi	r10, r5, 0x66a
    addi	r9, r5, 0x679
    addi	r8, r5, 0x67a
    stbx	r0, r6, r3
    addi	r7, r5, 0x67b
    addi	r6, r5, 0x67c
    addi	r31, r5, 0x67d
    lwz	r3, -0x7740(r13)
    addi	r5, r5, 0x100
    stbx	r4, r3, r30
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r29
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r28
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r27
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r26
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r25
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r24
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r23
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r22
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r21
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r20
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r19
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r18
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r17
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r16
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r15
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r14
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r12
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r11
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r10
    lwz	r3, -0x7740(r13)
    stbx	r0, r3, r9
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r8
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r7
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r6
    lwz	r3, -0x7740(r13)
    stbx	r4, r3, r31
    bc      16, 0, _800683fc
    mr	r5, r4
    mr	r6, r4
    mr	r7, r4
_800686b8:
    lwz	r8, -0x7740(r13)
    li	r0, -1
    li	r3, 0
    addi	r9, r5, 8
    stwx	r0, r8, r5
    addi	r8, r5, 0xd
    li	r0, 0xff
    addi	r23, r5, 0xe
    lwz	r10, -0x7740(r13)
    addi	r21, r5, 0x490
    addi	r20, r5, 0x492
    li	r22, 0x7f
    stwx	r3, r10, r9
    addi	r18, r5, 0x493
    addi	r17, r5, 0x494
    li	r19, 0x40
    lwz	r9, -0x7740(r13)
    addi	r16, r5, 0x495
    addi	r15, r4, 0x184
    addi	r14, r6, 0x104
    stbx	r0, r9, r8
    addi	r12, r6, 0x144
    addi	r11, r4, 0x22c
    addi	r10, r6, 0x1ac
    lwz	r24, -0x7740(r13)
    addi	r9, r6, 0x1ec
    li	r8, 8
    stbx	r0, r24, r23
    lwz	r23, -0x7740(r13)
    stbx	r0, r23, r21
    lwz	r21, -0x7740(r13)
    stbx	r22, r21, r20
    lwz	r20, -0x7740(r13)
    stbx	r22, r20, r18
    lwz	r18, -0x7740(r13)
    stbx	r19, r18, r17
    lwz	r17, -0x7740(r13)
    stbx	r19, r17, r16
    lwz	r16, -0x7740(r13)
    stbx	r3, r16, r15
    lwz	r15, -0x7740(r13)
    stwx	r3, r15, r14
    lwz	r14, -0x7740(r13)
    stwx	r3, r14, r12
    lwz	r12, -0x7740(r13)
    stbx	r3, r12, r11
    lwz	r11, -0x7740(r13)
    stwx	r3, r11, r10
    lwz	r10, -0x7740(r13)
    stwx	r3, r10, r9
    mtctr	r8
_80068784:
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r8, r8, 0xd88
    stbx	r0, r7, r8
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r8, r8, 0xd89
    stbx	r0, r7, r8
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r8, r8, 0xd8a
    stbx	r0, r7, r8
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r3, r3, 4
    addi	r8, r8, 0xd8b
    stbx	r0, r7, r8
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r8, r8, 0xd88
    stbx	r0, r7, r8
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r8, r8, 0xd89
    stbx	r0, r7, r8
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r8, r8, 0xd8a
    stbx	r0, r7, r8
    lwz	r8, -0x7740(r13)
    add	r8, r8, r3
    addi	r3, r3, 4
    addi	r8, r8, 0xd8b
    stbx	r0, r7, r8
    bc      16, 0, _80068784
    addi	r4, r4, 1
    addi	r6, r6, 4
    cmplwi	r4, 0x10
    addi	r7, r7, 0x40
    addi	r5, r5, 0x10
    bc      12, 0, _800686b8
    lwz	r4, -0x7740(r13)
    li	r3, 0
    li	r0, 2
    stb	r3, 0x1188(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x11b0(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x11d8(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1200(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1228(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1250(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1278(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x12a0(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x12c8(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x12f0(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1318(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1340(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1368(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x1390(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x13b8(r4)
    lwz	r4, -0x7740(r13)
    stb	r3, 0x13e0(r4)
    lwz	r4, -0x7740(r13)
    sth	r3, 0x5a10(r4)
    lwz	r4, -0x7740(r13)
    sth	r3, 0x5a12(r4)
    mtctr	r0
_800688c4:
    lwz	r5, -0x7740(r13)
    addi	r0, r3, 0x5a14
    li	r4, 0
    addi	r6, r3, 0x5a34
    sthx	r4, r5, r0
    addi	r5, r3, 0x5a54
    addi	r0, r3, 0x5ab4
    addi	r26, r3, 0x5ad4
    lwz	r7, -0x7740(r13)
    addi	r25, r3, 0x5a16
    addi	r24, r3, 0x5a36
    addi	r23, r3, 0x5a56
    sthx	r4, r7, r6
    addi	r22, r3, 0x5ab6
    addi	r21, r3, 0x5ad6
    addi	r20, r3, 0x5a18
    lwz	r6, -0x7740(r13)
    addi	r19, r3, 0x5a38
    addi	r18, r3, 0x5a58
    addi	r17, r3, 0x5ab8
    sthx	r4, r6, r5
    addi	r16, r3, 0x5ad8
    addi	r15, r3, 0x5a1a
    addi	r14, r3, 0x5a3a
    lwz	r5, -0x7740(r13)
    addi	r12, r3, 0x5a5a
    addi	r11, r3, 0x5aba
    addi	r10, r3, 0x5ada
    sthx	r4, r5, r0
    addi	r9, r3, 0x5a1c
    addi	r8, r3, 0x5a3c
    addi	r7, r3, 0x5a5c
    lwz	r27, -0x7740(r13)
    addi	r6, r3, 0x5abc
    addi	r5, r3, 0x5adc
    addi	r0, r3, 0x5a1e
    sthx	r4, r27, r26
    lwz	r26, -0x7740(r13)
    sthx	r4, r26, r25
    lwz	r25, -0x7740(r13)
    sthx	r4, r25, r24
    lwz	r24, -0x7740(r13)
    sthx	r4, r24, r23
    lwz	r23, -0x7740(r13)
    sthx	r4, r23, r22
    lwz	r22, -0x7740(r13)
    sthx	r4, r22, r21
    lwz	r21, -0x7740(r13)
    sthx	r4, r21, r20
    lwz	r20, -0x7740(r13)
    sthx	r4, r20, r19
    lwz	r19, -0x7740(r13)
    sthx	r4, r19, r18
    lwz	r18, -0x7740(r13)
    sthx	r4, r18, r17
    lwz	r17, -0x7740(r13)
    sthx	r4, r17, r16
    lwz	r16, -0x7740(r13)
    sthx	r4, r16, r15
    lwz	r15, -0x7740(r13)
    sthx	r4, r15, r14
    lwz	r14, -0x7740(r13)
    sthx	r4, r14, r12
    lwz	r12, -0x7740(r13)
    sthx	r4, r12, r11
    lwz	r11, -0x7740(r13)
    sthx	r4, r11, r10
    lwz	r10, -0x7740(r13)
    sthx	r4, r10, r9
    lwz	r9, -0x7740(r13)
    sthx	r4, r9, r8
    lwz	r8, -0x7740(r13)
    sthx	r4, r8, r7
    lwz	r7, -0x7740(r13)
    sthx	r4, r7, r6
    lwz	r6, -0x7740(r13)
    sthx	r4, r6, r5
    lwz	r5, -0x7740(r13)
    sthx	r4, r5, r0
    lwz	r6, -0x7740(r13)
    addi	r5, r3, 0x5a3e
    addi	r0, r3, 0x5a5e
    addi	r16, r3, 0x5abe
    sthx	r4, r6, r5
    addi	r15, r3, 0x5ade
    addi	r14, r3, 0x5a20
    addi	r12, r3, 0x5a40
    lwz	r5, -0x7740(r13)
    addi	r11, r3, 0x5a60
    addi	r10, r3, 0x5ac0
    addi	r9, r3, 0x5ae0
    sthx	r4, r5, r0
    addi	r8, r3, 0x5a22
    addi	r7, r3, 0x5a42
    addi	r6, r3, 0x5a62
    lwz	r17, -0x7740(r13)
    addi	r5, r3, 0x5ac2
    addi	r0, r3, 0x5ae2
    addi	r3, r3, 0x10
    sthx	r4, r17, r16
    lwz	r16, -0x7740(r13)
    sthx	r4, r16, r15
    lwz	r15, -0x7740(r13)
    sthx	r4, r15, r14
    lwz	r14, -0x7740(r13)
    sthx	r4, r14, r12
    lwz	r12, -0x7740(r13)
    sthx	r4, r12, r11
    lwz	r11, -0x7740(r13)
    sthx	r4, r11, r10
    lwz	r10, -0x7740(r13)
    sthx	r4, r10, r9
    lwz	r9, -0x7740(r13)
    sthx	r4, r9, r8
    lwz	r8, -0x7740(r13)
    sthx	r4, r8, r7
    lwz	r7, -0x7740(r13)
    sthx	r4, r7, r6
    lwz	r6, -0x7740(r13)
    sthx	r4, r6, r5
    lwz	r5, -0x7740(r13)
    sthx	r4, r5, r0
    bc      16, 0, _800688c4
    li	r0, 2
    mtctr	r0
_80068ab8:
    lwz	r5, -0x7740(r13)
    addi	r3, r4, 0x5a74
    li	r0, 0
    addi	r6, r4, 0x5a94
    sthx	r0, r5, r3
    addi	r5, r4, 0x5af4
    addi	r3, r4, 0x5a76
    addi	r24, r4, 0x5a96
    lwz	r7, -0x7740(r13)
    addi	r23, r4, 0x5af6
    addi	r22, r4, 0x5a78
    addi	r21, r4, 0x5a98
    sthx	r0, r7, r6
    addi	r20, r4, 0x5af8
    addi	r19, r4, 0x5a7a
    addi	r18, r4, 0x5a9a
    lwz	r6, -0x7740(r13)
    addi	r17, r4, 0x5afa
    addi	r16, r4, 0x5a7c
    addi	r15, r4, 0x5a9c
    sthx	r0, r6, r5
    addi	r14, r4, 0x5afc
    addi	r12, r4, 0x5a7e
    addi	r11, r4, 0x5a9e
    lwz	r5, -0x7740(r13)
    addi	r10, r4, 0x5afe
    addi	r9, r4, 0x5a80
    addi	r8, r4, 0x5aa0
    sthx	r0, r5, r3
    addi	r7, r4, 0x5b00
    addi	r6, r4, 0x5a82
    addi	r5, r4, 0x5aa2
    lwz	r25, -0x7740(r13)
    addi	r3, r4, 0x5b02
    addi	r4, r4, 0x10
    sthx	r0, r25, r24
    lwz	r24, -0x7740(r13)
    sthx	r0, r24, r23
    lwz	r23, -0x7740(r13)
    sthx	r0, r23, r22
    lwz	r22, -0x7740(r13)
    sthx	r0, r22, r21
    lwz	r21, -0x7740(r13)
    sthx	r0, r21, r20
    lwz	r20, -0x7740(r13)
    sthx	r0, r20, r19
    lwz	r19, -0x7740(r13)
    sthx	r0, r19, r18
    lwz	r18, -0x7740(r13)
    sthx	r0, r18, r17
    lwz	r17, -0x7740(r13)
    sthx	r0, r17, r16
    lwz	r16, -0x7740(r13)
    sthx	r0, r16, r15
    lwz	r15, -0x7740(r13)
    sthx	r0, r15, r14
    lwz	r14, -0x7740(r13)
    sthx	r0, r14, r12
    lwz	r12, -0x7740(r13)
    sthx	r0, r12, r11
    lwz	r11, -0x7740(r13)
    sthx	r0, r11, r10
    lwz	r10, -0x7740(r13)
    sthx	r0, r10, r9
    lwz	r9, -0x7740(r13)
    sthx	r0, r9, r8
    lwz	r8, -0x7740(r13)
    sthx	r0, r8, r7
    lwz	r7, -0x7740(r13)
    sthx	r0, r7, r6
    lwz	r6, -0x7740(r13)
    sthx	r0, r6, r5
    lwz	r5, -0x7740(r13)
    sthx	r0, r5, r3
    bc      16, 0, _80068ab8
    bl      fn_8006A1F8
    lmw	r14, 8(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void fn_80068BFC(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r8, lbl_80193B48@ha
    li	r9, 0
    stw	r0, 0x24(r1)
    addi	r0, r8, lbl_80193B48@l
    lwz	r8, -0x7b18(r2)
    stmw	r27, 0xc(r1)
    mr	r27, r3
    mr	r28, r4
    mr	r29, r5
    mr	r30, r6
    mr	r31, r7
    stw	r9, -0x7748(r13)
    stw	r9, -0x7744(r13)
    stw	r0, -0x7740(r13)
    bl      fn_80067F68
    bl      SndInitProcTable
    cmplwi	r28, 0
    bc      4, 2, _80068c54
    li	r3, -1
    b       _80068ea0
_80068c54:
    cmplwi	r29, 0
    bc      4, 2, _80068c64
    li	r3, -2
    b       _80068ea0
_80068c64:
    lwz	r3, -0x7740(r13)
    addi	r0, r29, -0x21e0
    cmplwi	r27, 0
    stw	r28, 0x194(r3)
    lwz	r3, -0x7740(r13)
    stw	r0, 0x23c(r3)
    lwz	r3, -0x7740(r13)
    stw	r27, 0x454(r3)
    bc      12, 2, _80068cc8
    cmplwi	r30, 0
    bc      4, 2, _80068c98
    li	r3, -3
    b       _80068ea0
_80068c98:
    cmplwi	r31, 0
    bc      4, 2, _80068ca8
    li	r3, -4
    b       _80068ea0
_80068ca8:
    lwz	r3, -0x7740(r13)
    stw	r31, 0x1a0(r3)
    lwz	r3, -0x7740(r13)
    lwz	r0, 0x1a0(r3)
    stw	r0, 0x1a4(r3)
    lwz	r3, -0x7740(r13)
    stw	r30, 0x100(r3)
    b       _80068d0c
_80068cc8:
    mr	r3, r29
    bl      ARAlloc
    lwz	r4, -0x7740(r13)
    stw	r3, 0x1a0(r4)
    lwz	r3, -0x7740(r13)
    lwz	r0, 0x1a0(r3)
    stw	r0, 0x1a4(r3)
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, -0x7fb0(r13)
    mr	r31, r0
    mr	r4, r28
    bl      OSAlloc
    lwz	r4, -0x7740(r13)
    stw	r3, 0x100(r4)
    mr	r3, r31
    bl      OSRestoreInterrupts
_80068d0c:
    bl      OSDisableInterrupts
    mr	r0, r3
    lwz	r3, -0x7fb0(r13)
    mr	r31, r0
    li	r4, 0x100
    bl      OSAlloc
    mr	r0, r3
    mr	r3, r31
    mr	r31, r0
    bl      OSRestoreInterrupts
    li	r0, 2
    mr	r4, r31
    li	r3, 0
    mtctr	r0
_80068d44:
    stw	r3, 0(r4)
    stw	r3, 4(r4)
    stw	r3, 8(r4)
    stw	r3, 0xc(r4)
    stw	r3, 0x10(r4)
    stw	r3, 0x14(r4)
    stw	r3, 0x18(r4)
    stw	r3, 0x1c(r4)
    stw	r3, 0x20(r4)
    stw	r3, 0x24(r4)
    stw	r3, 0x28(r4)
    stw	r3, 0x2c(r4)
    stw	r3, 0x30(r4)
    stw	r3, 0x34(r4)
    stw	r3, 0x38(r4)
    stw	r3, 0x3c(r4)
    stw	r3, 0x40(r4)
    stw	r3, 0x44(r4)
    stw	r3, 0x48(r4)
    stw	r3, 0x4c(r4)
    stw	r3, 0x50(r4)
    stw	r3, 0x54(r4)
    stw	r3, 0x58(r4)
    stw	r3, 0x5c(r4)
    stw	r3, 0x60(r4)
    stw	r3, 0x64(r4)
    stw	r3, 0x68(r4)
    stw	r3, 0x6c(r4)
    stw	r3, 0x70(r4)
    stw	r3, 0x74(r4)
    stw	r3, 0x78(r4)
    stw	r3, 0x7c(r4)
    addi	r4, r4, 0x80
    bc      16, 0, _80068d44
    li	r0, 1
    lis     r3, lbl_80193B28@ha
    stw	r0, -0x7744(r13)
    lis     r4, fn_80065AD0@ha
    lwz	r5, -0x7740(r13)
    addi	r10, r4, fn_80065AD0@l
    addi	r3, r3, lbl_80193B28@l
    mr	r7, r31
    lwz	r8, 0x1a4(r5)
    li	r4, 0
    li	r5, 0
    li	r6, 1
    li	r9, 0x100
    bl      ARQPostRequest
_80068e04:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      4, 2, _80068e04
    li	r0, 1
    lis     r3, lbl_80193B28@ha
    stw	r0, -0x7744(r13)
    lis     r4, fn_80065AC4@ha
    lwz	r5, -0x7740(r13)
    addi	r10, r4, fn_80065AC4@l
    lwz	r7, -0x7af8(r2)
    addi	r3, r3, lbl_80193B28@l
    lwz	r5, 0x1a4(r5)
    li	r4, 0
    li	r6, 1
    li	r9, 0x20e0
    addi	r8, r5, 0x100
    li	r5, 0
    bl      ARQPostRequest
_80068e4c:
    lwz	r0, -0x7744(r13)
    cmpwi	r0, 0
    bc      4, 2, _80068e4c
    lwz	r6, -0x7740(r13)
    li	r3, 0
    li	r4, 0
    lwz	r5, 0x1a4(r6)
    addi	r0, r5, 0x21e0
    stw	r0, 0x1ac(r6)
    lwz	r6, -0x7740(r13)
    lwz	r5, 0x1a4(r6)
    addi	r0, r5, 0x100
    stw	r0, 0x1a8(r6)
    lwz	r5, -0x7740(r13)
    lwz	r0, 0x100(r5)
    stw	r0, 0x104(r5)
    bl      fn_800211E0
    li	r3, 0
    li	r4, 0
    bl      fn_800211EC
    li	r3, 0
_80068ea0:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_80068EB4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    b       _80069278
_80068ed8:
    clrlwi	r0, r30, 0x18
    lwz	r3, -0x7740(r13)
    mulli	r31, r0, 0x28
    add	r4, r3, r31
    lbz	r0, 0x1188(r4)
    cmpwi	r0, 0
    bc      12, 2, _80069274
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bc      12, 2, _80068f3c
    lwz	r3, 0x11a4(r4)
    addi	r5, r31, 0x11a4
    lwz	r0, 0x11ac(r4)
    add	r0, r3, r0
    stw	r0, 0x11a4(r4)
    lwz	r3, -0x7740(r13)
    lwzx	r4, r3, r5
    cmpwi	r4, 0
    bc      4, 0, _80068f2c
    li	r0, 0
    stwx	r0, r3, r5
    b       _80068f3c
_80068f2c:
    lis	r0, 0x7f
    cmpw	r4, r0
    bc      4, 1, _80068f3c
    stwx	r0, r3, r5
_80068f3c:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lbz	r0, 0x1188(r3)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bc      12, 2, _80068fe8
    lwz	r0, 0x11a4(r3)
    rlwinm	r0, r0, 0, 9, 0xf
    stw	r0, 0x11a4(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lwz	r4, 0x11a4(r3)
    lwz	r0, 0x11a8(r3)
    cmpw	r4, r0
    bc      12, 2, _80068fe8
    stw	r4, 0x11a8(r3)
    lwz	r0, -0x7740(r13)
    add	r4, r0, r31
    lwz	r3, 0x11a4(r4)
    lbz	r0, 0x118a(r4)
    slwi	r3, r3, 8
    oris	r3, r3, 0xa01c
    or	r3, r3, r0
    bl      fn_80065A7C
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lwz	r4, 0x11a4(r3)
    cmpwi	r4, 0
    bc      4, 2, _80068fd0
    lbz	r0, 0x118a(r3)
    oris	r3, r0, 0xa000
    ori	r3, r3, 0x1200
    bl      fn_80065A7C
    lwz	r3, -0x7740(r13)
    addi	r0, r31, 0x1188
    li	r4, 0
    stbx	r4, r3, r0
    b       _80068fe8
_80068fd0:
    addis	r0, r4, -0x7f
    cmplwi	r0, 0
    bc      4, 2, _80068fe8
    lbz	r0, 0x1188(r3)
    andi.	r0, r0, 0xf9
    stb	r0, 0x1188(r3)
_80068fe8:
    lwz	r0, -0x7740(r13)
    add	r3, r0, r31
    lwz	r0, 0x1194(r3)
    srawi.	r0, r0, 0x10
    bc      12, 1, _80069274
    lwz	r28, 0x11a0(r3)
_80069000:
    lbz	r4, 0(r28)
    mr	r29, r28
    cmpwi	r4, 0xff
    bc      4, 2, _80069118
    lwz	r4, -0x7740(r13)
    addi	r0, r4, 0x119c
    lwzx	r28, r31, r0
    addis	r0, r28, 0x100
    cmplwi	r0, 0
    bc      4, 2, _80069038
    addi	r0, r31, 0x1188
    li	r3, 0
    stbx	r3, r4, r0
    b       _80069274
_80069038:
    lwz	r0, 0(r28)
    addi	r28, r28, 4
    rlwinm.	r3, r0, 8, 0x18, 0x1f
    clrlwi	r5, r0, 8
    bc      12, 2, _800690f8
    cmplwi	r3, 0x80
    bc      12, 2, _80069090
    lwz	r4, -0x7740(r13)
    cmplwi	r3, 0x90
    add	r3, r31, r4
    lwz	r0, 0x1198(r3)
    add	r28, r0, r5
    bc      12, 2, _80069038
    cmplwi	r5, 0
    bc      4, 2, _80069084
    addi	r0, r31, 0x1188
    li	r3, 0
    stbx	r3, r4, r0
    b       _80069274
_80069084:
    lis	r0, -0x100
    stw	r0, 0x119c(r3)
    b       _80069000
_80069090:
    lwz	r3, -0x7740(r13)
    addi	r0, r3, 0x118a
    lbzx	r0, r31, r0
    rlwimi	r0, r5, 8, 0, 0x17
    ori	r3, r0, 0x80
    bl      fn_80065A7C
    lwz	r3, -0x7740(r13)
    addi	r5, r3, 0x1188
    lbzx	r4, r31, r5
    rlwinm.	r0, r4, 0, 0x1b, 0x1c
    bc      12, 2, _80069038
    rlwinm.	r0, r4, 0, 0x1c, 0x1c
    lis	r3, -0x5fe4
    bc      12, 2, _800690d4
    andi.	r0, r4, 0xf5
    stbx	r0, r31, r5
    b       _800690e0
_800690d4:
    andi.	r0, r4, 0xef
    ori	r3, r3, 0x7f00
    stbx	r0, r31, r5
_800690e0:
    lwz	r4, -0x7740(r13)
    addi	r0, r4, 0x118a
    lbzx	r0, r31, r0
    or	r3, r3, r0
    bl      fn_80065A7C
    b       _80069038
_800690f8:
    lwz	r3, -0x7740(r13)
    addi	r0, r3, 0x119c
    stwx	r28, r31, r0
    lwz	r3, -0x7740(r13)
    addi	r0, r3, 0x1198
    lwzx	r0, r31, r0
    add	r28, r0, r5
    b       _80069000
_80069118:
    rlwinm.	r0, r4, 0, 0x18, 0x18
    bc      12, 2, _80069138
    lwz	r3, -0x7740(r13)
    addi	r29, r28, 1
    addi	r0, r3, 0x118b
    stbx	r4, r31, r0
    lbz	r5, 0(r28)
    b       _80069144
_80069138:
    lwz	r3, -0x7740(r13)
    addi	r0, r3, 0x118b
    lbzx	r5, r31, r0
_80069144:
    rlwinm	r0, r5, 0, 0x18, 0x1b
    lbz	r4, 0(r29)
    cmpwi	r0, 0xd0
    addi	r29, r29, 1
    rlwinm	r3, r4, 0x10, 9, 0xf
    clrlwi	r6, r4, 0x19
    rlwinm	r28, r4, 0, 0x18, 0x18
    rlwimi	r3, r5, 0x18, 0, 7
    bc      12, 2, _800691d0
    bc      4, 0, _80069190
    cmpwi	r0, 0xa0
    bc      12, 2, _800691a8
    bc      4, 0, _80069184
    cmpwi	r0, 0x90
    bc      12, 2, _800691a8
    b       _80069208
_80069184:
    cmpwi	r0, 0xb0
    bc      12, 2, _800691a8
    b       _80069208
_80069190:
    cmpwi	r0, 0xf0
    bc      12, 2, _800691a8
    bc      4, 0, _80069208
    cmpwi	r0, 0xe0
    bc      12, 2, _800691c0
    b       _80069208
_800691a8:
    lbz	r4, 0(r29)
    addi	r29, r29, 1
    rlwinm	r0, r4, 8, 0x11, 0x17
    rlwinm	r28, r4, 0, 0x18, 0x18
    or	r3, r3, r0
    b       _80069208
_800691c0:
    rlwinm	r3, r3, 0, 0x10, 7
    slwi	r0, r6, 8
    or	r3, r3, r0
    b       _80069208
_800691d0:
    lwz	r4, -0x7740(r13)
    addi	r0, r4, 0x1189
    lbzx	r0, r31, r0
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      12, 2, _80069208
    lbz	r5, 1(r29)
    rlwinm	r3, r3, 0, 2, 0
    lbz	r4, 0(r29)
    addi	r29, r29, 2
    rlwinm	r0, r5, 4, 0x15, 0x1b
    rlwinm	r28, r5, 0, 0x18, 0x18
    rlwinm	r4, r4, 8, 0x11, 0x17
    or	r0, r4, r0
    or	r3, r3, r0
_80069208:
    lwz	r4, -0x7740(r13)
    addi	r0, r4, 0x118a
    lbzx	r0, r31, r0
    or	r3, r3, r0
    bl      fn_80065A7C
    rlwinm.	r0, r28, 0, 0x18, 0x18
    bc      12, 2, _8006922c
    mr	r28, r29
    b       _80069000
_8006922c:
    lbz	r3, 0(r29)
    addi	r29, r29, 1
    rlwinm.	r0, r3, 0, 0x18, 0x18
    bc      12, 2, _80069250
    lbz	r0, 0(r29)
    rlwinm	r3, r3, 7, 0x12, 0x18
    addi	r29, r29, 1
    rlwimi	r3, r0, 0, 0x19, 0x1f
    clrlwi	r3, r3, 0x12
_80069250:
    lwz	r6, -0x7740(r13)
    addi	r5, r31, 0x1194
    slwi	r3, r3, 0x10
    addi	r0, r31, 0x11a0
    lwzx	r4, r6, r5
    add	r3, r4, r3
    stwx	r3, r6, r5
    lwz	r3, -0x7740(r13)
    stwx	r29, r3, r0
_80069274:
    addi	r30, r30, 1
_80069278:
    clrlwi	r0, r30, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80068ed8
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_800692A4(void)
{
    nofralloc
    rlwinm	r0, r3, 0, 0x10, 0x17
    cmplwi	r0, 0x1900
    bgtlr	
    lis	r5, -0x6000
    rlwinm	r6, r3, 0, 0, 0x17
    addi	r0, r5, 0x1100
    clrlwi	r4, r3, 0x1c
    cmpw	r6, r0
    rlwinm	r0, r3, 0, 0x18, 0x18
    bc      12, 2, _8006943c
    bc      4, 0, _80069300
    addi	r3, r5, 0x200
    cmpw	r6, r3
    bc      12, 2, _8006939c
    bc      4, 0, _800692f0
    addi	r3, r5, 0x100
    cmpw	r6, r3
    bc      12, 2, _80069320
    blr
_800692f0:
    addi	r0, r5, 0x300
    cmpw	r6, r0
    bc      12, 2, _800693fc
    blr
_80069300:
    addi	r3, r5, 0x1300
    cmpw	r6, r3
    bc      12, 2, _800694f0
    bgelr	
    addi	r3, r5, 0x1200
    cmpw	r6, r3
    bc      12, 2, _8006949c
    blr
_80069320:
    li	r7, 0
    b       _8006938c
_80069328:
    cmplwi	r0, 0
    bc      4, 2, _8006934c
    clrlwi	r3, r7, 0x18
    lwz	r5, -0x7740(r13)
    mulli	r3, r3, 0x28
    li	r6, 0
    addi	r3, r3, 0x1188
    stbx	r6, r5, r3
    b       _80069388
_8006934c:
    clrlwi	r3, r7, 0x18
    lwz	r5, -0x7740(r13)
    mulli	r3, r3, 0x28
    add	r5, r5, r3
    lbz	r3, 0x118a(r5)
    cmplw	r4, r3
    bc      4, 2, _80069380
    lbz	r3, 0x1189(r5)
    rlwinm.	r3, r3, 0, 0x18, 0x18
    bc      12, 2, _80069388
    li	r3, 0
    stb	r3, 0x1188(r5)
    b       _80069388
_80069380:
    li	r3, 0
    stb	r3, 0x1188(r5)
_80069388:
    addi	r7, r7, 1
_8006938c:
    clrlwi	r3, r7, 0x18
    cmplwi	r3, 0x10
    bc      12, 0, _80069328
    blr
_8006939c:
    li	r8, 0
    mr	r6, r8
    mr	r5, r8
    b       _800693ec
_800693ac:
    clrlwi	r3, r8, 0x18
    lwz	r7, -0x7740(r13)
    mulli	r3, r3, 0x28
    add	r7, r7, r3
    lbz	r3, 0x1189(r7)
    rlwinm.	r3, r3, 0, 0x18, 0x18
    bc      4, 2, _800693e8
    cmplwi	r0, 0
    bc      4, 2, _800693d8
    stb	r6, 0x1188(r7)
    b       _800693e8
_800693d8:
    lbz	r3, 0x118a(r7)
    cmplw	r4, r3
    bc      12, 2, _800693e8
    stb	r5, 0x1188(r7)
_800693e8:
    addi	r8, r8, 1
_800693ec:
    clrlwi	r3, r8, 0x18
    cmplwi	r3, 0x10
    bc      12, 0, _800693ac
    blr
_800693fc:
    li	r5, 0
    mr	r3, r5
    b       _8006942c
_80069408:
    clrlwi	r0, r5, 0x18
    lwz	r4, -0x7740(r13)
    mulli	r0, r0, 0x28
    add	r4, r4, r0
    lbz	r0, 0x1189(r4)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      12, 2, _80069428
    stb	r3, 0x1188(r4)
_80069428:
    addi	r5, r5, 1
_8006942c:
    clrlwi	r0, r5, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80069408
    blr
_8006943c:
    li	r8, 0
    mr	r6, r8
    mr	r5, r8
    b       _8006948c
_8006944c:
    clrlwi	r3, r8, 0x18
    lwz	r7, -0x7740(r13)
    mulli	r3, r3, 0x28
    add	r7, r7, r3
    lbz	r3, 0x118a(r7)
    cmplw	r4, r3
    bc      4, 2, _80069488
    cmplwi	r0, 0
    bc      4, 2, _80069478
    stb	r6, 0x1188(r7)
    b       _80069488
_80069478:
    lbz	r3, 0x1189(r7)
    rlwinm.	r3, r3, 0, 0x18, 0x18
    bc      12, 2, _80069488
    stb	r5, 0x1188(r7)
_80069488:
    addi	r8, r8, 1
_8006948c:
    clrlwi	r3, r8, 0x18
    cmplwi	r3, 0x10
    bc      12, 0, _8006944c
    blr
_8006949c:
    cmplwi	r0, 0
    bnelr	
    li	r6, 0
    mr	r3, r6
    b       _800694e0
_800694b0:
    clrlwi	r0, r6, 0x18
    lwz	r5, -0x7740(r13)
    mulli	r0, r0, 0x28
    add	r5, r5, r0
    lbz	r0, 0x118a(r5)
    cmplw	r4, r0
    bc      4, 2, _800694dc
    lbz	r0, 0x1189(r5)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      4, 2, _800694dc
    stb	r3, 0x1188(r5)
_800694dc:
    addi	r6, r6, 1
_800694e0:
    clrlwi	r0, r6, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800694b0
    blr
_800694f0:
    li	r6, 0
    mr	r3, r6
    b       _8006952c
_800694fc:
    clrlwi	r0, r6, 0x18
    lwz	r5, -0x7740(r13)
    mulli	r0, r0, 0x28
    add	r5, r5, r0
    lbz	r0, 0x118a(r5)
    cmplw	r4, r0
    bc      4, 2, _80069528
    lbz	r0, 0x1189(r5)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      12, 2, _80069528
    stb	r3, 0x1188(r5)
_80069528:
    addi	r6, r6, 1
_8006952c:
    clrlwi	r0, r6, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800694fc
    blr
}

asm void SndAllocBankEntry(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r6, -1
    stw	r0, 0x14(r1)
    srwi	r0, r3, 0x18
    cmplwi	r0, 0xa0
    stw	r31, 0xc(r1)
    bc      4, 2, _8006973c
    rlwinm	r5, r3, 0, 8, 0xf
    lis	r4, 0xa
    cmplw	r5, r4
    bc      12, 1, _80069acc
    lis	r0, 6
    cmpw	r5, r0
    bc      12, 2, _80069acc
    bc      4, 0, _800695a8
    lis	r0, 2
    cmpw	r5, r0
    bc      12, 2, _800695cc
    bc      4, 0, _80069598
    cmpwi	r5, 0
    bc      12, 2, _800695c4
    b       _80069acc
_80069598:
    lis	r0, 3
    cmpw	r5, r0
    bc      12, 2, _80069628
    b       _80069acc
_800695a8:
    cmpw	r5, r4
    bc      12, 2, _800696ac
    bc      4, 0, _80069acc
    lis	r0, 9
    cmpw	r5, r0
    bc      12, 2, _80069684
    b       _80069acc
_800695c4:
    bl      fn_800692A4
    b       _80069acc
_800695cc:
    clrlwi	r5, r3, 0x1c
    li	r4, 0
    b       _80069618
_800695d8:
    clrlwi	r0, r4, 0x18
    lwz	r3, -0x7740(r13)
    mulli	r0, r0, 0x28
    add	r6, r3, r0
    lbz	r0, 0x118a(r6)
    cmplw	r5, r0
    bc      4, 2, _80069614
    lbz	r3, 0x1188(r6)
    cmpwi	r3, 0
    bc      12, 2, _80069614
    lbz	r0, 0x1189(r6)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      4, 2, _80069614
    ori	r0, r3, 1
    stb	r0, 0x1188(r6)
_80069614:
    addi	r4, r4, 1
_80069618:
    clrlwi	r0, r4, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800695d8
    b       _80069acc
_80069628:
    clrlwi	r5, r3, 0x1c
    li	r4, 0
    b       _80069674
_80069634:
    clrlwi	r0, r4, 0x18
    lwz	r3, -0x7740(r13)
    mulli	r0, r0, 0x28
    add	r6, r3, r0
    lbz	r0, 0x118a(r6)
    cmplw	r5, r0
    bc      4, 2, _80069670
    lbz	r3, 0x1188(r6)
    cmpwi	r3, 0
    bc      12, 2, _80069670
    lbz	r0, 0x1189(r6)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      4, 2, _80069670
    rlwinm	r0, r3, 0, 0x18, 0x1e
    stb	r0, 0x1188(r6)
_80069670:
    addi	r4, r4, 1
_80069674:
    clrlwi	r0, r4, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80069634
    b       _80069acc
_80069684:
    lwz	r5, -0x7740(r13)
    clrlwi	r6, r3, 0x1c
    lis     r4, lbl_80092C38@ha
    rlwinm	r0, r3, 0x19, 0x18, 0x1e
    stb	r6, 0x458(r5)
    addi	r3, r4, lbl_80092C38@l
    lhzx	r0, r3, r0
    lwz	r3, -0x7740(r13)
    stw	r0, 0x448(r3)
    b       _80069acc
_800696ac:
    lis     r4, lbl_80092C38@ha
    clrlwi	r9, r3, 0x1c
    rlwinm	r7, r3, 0x19, 0x18, 0x1e
    li	r8, 0
    addi	r6, r4, lbl_80092C38@l
    b       _8006972c
_800696c4:
    clrlwi	r0, r8, 0x18
    lwz	r3, -0x7740(r13)
    mulli	r5, r0, 0x28
    add	r4, r3, r5
    lbz	r3, 0x1188(r4)
    cmpwi	r3, 0
    bc      12, 2, _80069728
    lbz	r0, 0x1189(r4)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    bc      12, 2, _80069728
    lbz	r0, 0x118a(r4)
    cmplw	r9, r0
    bc      4, 2, _80069728
    ori	r3, r3, 6
    lhzx	r0, r6, r7
    stb	r3, 0x1188(r4)
    addi	r5, r5, 0x11ac
    lwz	r3, -0x7740(r13)
    stwx	r0, r3, r5
    lwz	r4, -0x7740(r13)
    lwzx	r0, r4, r5
    xoris	r3, r0, 0xffff
    xori	r3, r3, 0xffff
    addi	r0, r3, 1
    stwx	r0, r4, r5
_80069728:
    addi	r8, r8, 1
_8006972c:
    clrlwi	r0, r8, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _800696c4
    b       _80069acc
_8006973c:
    lwz	r4, -0x7740(r13)
    srwi	r8, r3, 0x10
    li	r11, 0
    li	r9, 0
    b       _800697c4
_80069750:
    rlwinm	r7, r9, 4, 0x14, 0x1b
    addi	r0, r7, 8
    lwzx	r7, r4, r0
    cmplwi	r7, 0
    bc      12, 2, _800697c0
    addi	r12, r7, 0x24
    li	r31, 4
    lwz	r0, 0x24(r7)
    li	r10, 0
    add	r5, r0, r7
    lbz	r7, 0(r5)
    b       _800697a4
_80069780:
    add	r12, r5, r31
    lwz	r0, 0(r12)
    srwi	r0, r0, 0x10
    cmplw	r0, r8
    bc      4, 2, _8006979c
    li	r11, 1
    b       _800697b0
_8006979c:
    addi	r31, r31, 4
    addi	r10, r10, 1
_800697a4:
    clrlwi	r0, r10, 0x18
    cmplw	r0, r7
    bc      4, 1, _80069780
_800697b0:
    clrlwi.	r0, r11, 0x18
    bc      12, 2, _800697c0
    extsb	r6, r9
    b       _800697d0
_800697c0:
    addi	r9, r9, 1
_800697c4:
    clrlwi	r0, r9, 0x18
    cmplwi	r0, 0x10
    bc      12, 0, _80069750
_800697d0:
    extsb	r8, r6
    cmpwi	r8, -1
    bc      12, 2, _80069ab0
    lwz	r0, 0(r12)
    rlwinm	r9, r3, 0x18, 0x18, 0x1f
    clrlwi	r0, r0, 0x10
    add	r7, r5, r0
    lbz	r0, 0(r7)
    cmplw	r9, r0
    bc      12, 1, _80069acc
    slwi	r0, r9, 2
    add	r7, r0, r7
    lwz	r0, 4(r7)
    cmplwi	r0, 0
    bc      12, 2, _80069acc
    add	r7, r5, r0
    li	r0, 0x7f
    lbz	r9, 0(r7)
    rlwinm.	r5, r9, 0, 0x18, 0x18
    bc      4, 2, _80069874
    li	r10, 0
    b       _80069864
_80069828:
    clrlwi	r5, r10, 0x18
    mulli	r5, r5, 0x28
    add	r9, r4, r5
    lbz	r5, 0x1188(r9)
    cmpwi	r5, 0
    bc      12, 2, _80069860
    lbz	r5, 0x118a(r9)
    cmpw	r5, r8
    bc      4, 2, _80069860
    lbz	r5, 0x1189(r9)
    rlwinm.	r5, r5, 0, 0x18, 0x18
    bc      4, 2, _80069860
    mr	r0, r10
    b       _800698cc
_80069860:
    addi	r10, r10, 1
_80069864:
    clrlwi	r5, r10, 0x18
    cmplwi	r5, 0x10
    bc      12, 0, _80069828
    b       _800698cc
_80069874:
    rlwinm	r5, r9, 0, 0x1b, 0x1b
    cmpwi	r5, 0x10
    bc      4, 2, _800698cc
    clrlwi	r8, r9, 0x1c
    li	r10, 0
    b       _800698c0
_8006988c:
    clrlwi	r5, r10, 0x18
    mulli	r5, r5, 0x28
    add	r9, r4, r5
    lbz	r5, 0x1188(r9)
    cmpwi	r5, 0
    bc      12, 2, _800698bc
    lbz	r5, 0x1189(r9)
    clrlwi	r5, r5, 0x1c
    cmpw	r5, r8
    bc      4, 2, _800698bc
    mr	r0, r10
    b       _800698cc
_800698bc:
    addi	r10, r10, 1
_800698c0:
    clrlwi	r5, r10, 0x18
    cmplwi	r5, 0x10
    bc      12, 0, _8006988c
_800698cc:
    clrlwi	r5, r0, 0x18
    cmplwi	r5, 0x7f
    bc      4, 2, _80069910
    li	r8, 0
    b       _80069904
_800698e0:
    clrlwi	r5, r8, 0x18
    mulli	r5, r5, 0x28
    addi	r5, r5, 0x1188
    lbzx	r5, r4, r5
    cmpwi	r5, 0
    bc      4, 2, _80069900
    mr	r0, r8
    b       _80069910
_80069900:
    addi	r8, r8, 1
_80069904:
    clrlwi	r5, r8, 0x18
    cmplwi	r5, 0x10
    bc      12, 0, _800698e0
_80069910:
    clrlwi	r5, r0, 0x18
    cmplwi	r5, 0x7f
    bc      4, 2, _80069954
    li	r8, 0
    b       _80069948
_80069924:
    clrlwi	r5, r8, 0x18
    mulli	r5, r5, 0x28
    addi	r5, r5, 0x1189
    lbzx	r5, r4, r5
    rlwinm.	r5, r5, 0, 0x18, 0x18
    bc      12, 2, _80069944
    mr	r0, r8
    b       _80069954
_80069944:
    addi	r8, r8, 1
_80069948:
    clrlwi	r5, r8, 0x18
    cmplwi	r5, 0x10
    bc      12, 0, _80069924
_80069954:
    clrlwi	r0, r0, 0x18
    lis	r8, 1
    mulli	r5, r0, 0x28
    li	r0, 0
    add	r4, r4, r5
    stb	r6, 0x118a(r4)
    lwz	r4, -0x7740(r13)
    add	r4, r4, r5
    stw	r8, 0x118c(r4)
    lwz	r4, -0x7740(r13)
    add	r4, r4, r5
    stw	r3, 0x1190(r4)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r5
    stw	r0, 0x1194(r3)
    lwz	r3, -0x7740(r13)
    lbz	r4, 0(r7)
    add	r3, r3, r5
    stb	r4, 0x1189(r3)
    lwz	r3, -0x7740(r13)
    add	r4, r3, r5
    lbz	r3, 0x1189(r4)
    rlwinm.	r3, r3, 0, 0x18, 0x18
    bc      4, 2, _80069a80
    li	r3, 0x90
    addi	r8, r7, 4
    stb	r3, 0x1188(r4)
    addi	r4, r13, -0x7db8
    lwz	r3, -0x7740(r13)
    add	r3, r3, r5
    stw	r7, 0x1198(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r5
    stw	r8, 0x119c(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r5
    stw	r4, 0x11a0(r3)
    lwz	r7, -0x7740(r13)
    lwz	r8, 0x448(r7)
    cmplwi	r8, 0
    bc      4, 2, _80069a14
    add	r3, r7, r5
    lis	r4, 0x7f
    stw	r4, 0x11a4(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r5
    stw	r4, 0x11a8(r3)
    b       _80069aa8
_80069a14:
    lbz	r4, 0x458(r7)
    extsb	r3, r6
    cmpw	r4, r3
    bc      4, 2, _80069a64
    add	r3, r7, r5
    stw	r8, 0x11ac(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r5
    stw	r0, 0x11a4(r3)
    lwz	r3, -0x7740(r13)
    add	r3, r3, r5
    stw	r0, 0x11a8(r3)
    lwz	r3, -0x7740(r13)
    add	r4, r3, r5
    lbz	r3, 0x1188(r4)
    xori	r3, r3, 0x98
    stb	r3, 0x1188(r4)
    lwz	r3, -0x7740(r13)
    stw	r0, 0x448(r3)
    b       _80069aa8
_80069a64:
    add	r3, r7, r5
    lis	r4, 0x7f
    stw	r4, 0x11a4(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r5
    stw	r4, 0x11a8(r3)
    b       _80069aa8
_80069a80:
    li	r0, 0x80
    lis	r6, -0x100
    stb	r0, 0x1188(r4)
    addi	r4, r7, 1
    lwz	r0, -0x7740(r13)
    add	r3, r0, r5
    stw	r6, 0x119c(r3)
    lwz	r0, -0x7740(r13)
    add	r3, r0, r5
    stw	r4, 0x11a0(r3)
_80069aa8:
    bl      fn_80068EB4
    b       _80069acc
_80069ab0:
    lwz	r12, 0x5b1c(r4)
    cmplwi	r12, 0
    bc      12, 2, _80069acc
    mr	r4, r3
    li	r3, -3
    mtctr	r12
    bctrl
_80069acc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

#pragma force_active off
