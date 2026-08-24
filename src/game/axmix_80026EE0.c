#pragma push
#pragma force_active on

extern void axmix_set_voice_volume(void);
extern void axmix_set_voice_volume_clamped(void);
extern void fn_80026FB8(void);
extern void fn_80026FE0(void);
extern void fn_8002805C(void);
extern void fn_80028090(void);
extern void fn_800280F0(void);
extern void axmix_ctrl_store_time_param(void);
extern void axmix_device_ctrl_accumulate_mix(void);
extern void axmix_device_ctrl_unlink(void);
extern void axmix_sound_alloc_init(void);
extern void axmix_ctrl_init_type2(void);
extern void axmix_ctrl_init_type5(void);
extern void axmix_ctrl_init_type7(void);
extern void axmix_ctrl_init_type8(void);
extern void axmix_ctrl_init_type9(void);
extern void axmix_ctrl_init_type10(void);
extern void axmix_ctrl_init_type11(void);
extern void axmix_ctrl_init_type14(void);
extern void axmix_update_voice_state(void);
extern void axmix_link_push(void);
extern void axmix_cent_to_ratio_lerp(void);
extern void axmix_param_ramp_step(void);
extern void axmix_param_ramp_step_dup(void);
extern void fn_80028A78(void);
extern void fn_80028B2C(void);
extern void fn_80028B34(void);
extern void axmix_mix_voice_state(void);
extern void OSDisableInterrupts(void);
extern void OSEnableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void OSWakeupThread(void);
extern void __cvt_fp2unsigned(void);
extern void DSPWriteMailHi(void);
extern void DSPWriteMailMid(void);
extern void AXSetVoiceState_cached(void);
extern void fn_800231C4(void);
extern void fn_80023228(void);
extern void AXVPBSyncChannelB(void);
extern void AXMixProcessVoiceFlags(void);
extern void AXGetMixStateWord(void);
extern void AXMixSetupVoiceEntry(void);
extern void axmix_device_ctrl_clear(void);
extern void axmix_set_voice_param_08(void);
extern void fn_80026E2C(void);
extern void fn_80026EAC(void);
extern unsigned char jumptable_80129550[68];
extern unsigned char jumptable_80129598[68];
extern unsigned char lbl_80128990[3008];
extern unsigned char lbl_801295E0[1008];
extern unsigned char lbl_801299D0[256];
extern unsigned char lbl_80129FD0[2168];
extern unsigned char lbl_80176160[6144];

asm void axmix_set_voice_volume(void)
{
    nofralloc
    mflr	r0
    cmpwi	r4, 0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    lwz	r0, 0x18(r3)
    lis     r3, lbl_80176160@ha
    mulli	r5, r0, 0x60
    addi	r0, r3, lbl_80176160@l
    add	r31, r0, r5
    bge     _80026f14
    li	r4, 0
    b       _80026f20
_80026f14:
    cmpwi	r4, 0x7f
    ble     _80026f20
    li	r4, 0x7f
_80026f20:
    stw	r4, 0x14(r31)
    mr	r3, r31
    bl      AXMixProcessVoiceFlags
    lwz	r0, 4(r31)
    oris	r0, r0, 0x4000
    stw	r0, 4(r31)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void axmix_set_voice_volume_clamped(void)
{
    nofralloc
    mflr	r0
    cmpwi	r4, 0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    lwz	r0, 0x18(r3)
    lis     r3, lbl_80176160@ha
    mulli	r5, r0, 0x60
    addi	r0, r3, lbl_80176160@l
    add	r31, r0, r5
    bge     _80026f80
    li	r4, 0
    b       _80026f8c
_80026f80:
    cmpwi	r4, 0x7f
    ble     _80026f8c
    li	r4, 0x7f
_80026f8c:
    stw	r4, 0x18(r31)
    mr	r3, r31
    bl      AXMixProcessVoiceFlags
    lwz	r0, 4(r31)
    oris	r0, r0, 0x4000
    stw	r0, 4(r31)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80026FB8(void)
{
    nofralloc
    lwz	r5, 0x18(r3)
    lis     r3, lbl_80176160@ha
    addi	r0, r3, lbl_80176160@l
    mulli	r3, r5, 0x60
    add	r3, r0, r3
    stw	r4, 0x1c(r3)
    lwz	r0, 4(r3)
    oris	r0, r0, 0x4000
    stw	r0, 4(r3)
    blr	
}

asm void fn_80026FE0(void)
{
    nofralloc
    mflr	r0
    lis     r3, lbl_80176160@ha
    stw	r0, 4(r1)
    li	r0, 0x40
    addi	r4, r3, lbl_80176160@l
    mtctr	r0
    stwu	r1, -0xc0(r1)
    lis	r3, 0x6666
    stw	r31, 0xbc(r1)
    lis     r5, lbl_80128990@ha
    addi	r0, r3, 0x6667
    addi	r31, r5, lbl_80128990@l
    lis	r3, 1
_80027014:
    lwz	r5, 0(r4)
    li	r7, 0
    li	r6, 0
    cmplwi	r5, 0
    beq     _80027fd8
    lwz	r9, 4(r4)
    li	r8, 0
    rlwinm.	r9, r9, 0, 2, 2
    beq     _80027050
    lhz	r9, 0x3a(r4)
    li	r7, 1
    sth	r9, 0x38(r4)
    lwz	r9, 4(r4)
    rlwinm	r9, r9, 0, 3, 1
    stw	r9, 4(r4)
_80027050:
    lwz	r10, 4(r4)
    rlwinm.	r9, r10, 0, 3, 3
    beq     _800270c0
    rlwinm.	r7, r10, 0, 0x1d, 0x1d
    beq     _80027070
    li	r7, 0
    sth	r7, 0x3a(r4)
    b       _800270a4
_80027070:
    lwz	r7, 8(r4)
    cmpwi	r7, -0x388
    bgt     _80027084
    li	r7, 0
    b       _800270a0
_80027084:
    cmpwi	r7, 0x3c
    blt     _80027094
    addi	r7, r3, -0x9c
    b       _800270a0
_80027094:
    slwi	r7, r7, 1
    addi	r7, r7, 0x710
    lhzx	r7, r31, r7
_800270a0:
    sth	r7, 0x3a(r4)
_800270a4:
    lwz	r9, 4(r4)
    li	r7, 1
    rlwinm	r9, r9, 0, 4, 2
    stw	r9, 4(r4)
    lwz	r9, 4(r4)
    oris	r9, r9, 0x2000
    stw	r9, 4(r4)
_800270c0:
    lwz	r9, 4(r4)
    rlwinm.	r9, r9, 0, 0, 0
    beq     _80027124
    lhz	r9, 0x3e(r4)
    li	r6, 1
    sth	r9, 0x3c(r4)
    lhz	r9, 0x42(r4)
    sth	r9, 0x40(r4)
    lhz	r9, 0x46(r4)
    sth	r9, 0x44(r4)
    lhz	r9, 0x4a(r4)
    sth	r9, 0x48(r4)
    lhz	r9, 0x4e(r4)
    sth	r9, 0x4c(r4)
    lhz	r9, 0x52(r4)
    sth	r9, 0x50(r4)
    lhz	r9, 0x56(r4)
    sth	r9, 0x54(r4)
    lhz	r9, 0x5a(r4)
    sth	r9, 0x58(r4)
    lhz	r9, 0x5e(r4)
    sth	r9, 0x5c(r4)
    lwz	r9, 4(r4)
    clrlwi	r9, r9, 1
    stw	r9, 4(r4)
_80027124:
    lwz	r9, 4(r4)
    rlwinm.	r9, r9, 0, 1, 1
    beq     _80027cf8
    lwz	r6, -0x7838(r13)
    cmpwi	r6, 3
    beq     _80027978
    bge     _80027cdc
    cmpwi	r6, 0
    beq     _80027150
    bge     _8002753c
    b       _80027cdc
_80027150:
    lwz	r9, 0x1c(r4)
    lwz	r6, 0x28(r4)
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _8002716c
    li	r6, 0
    b       _80027188
_8002716c:
    cmpwi	r6, 0x3c
    blt     _8002717c
    addi	r6, r3, -0x9c
    b       _80027188
_8002717c:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027188:
    sth	r6, 0x3e(r4)
    lwz	r9, 0x1c(r4)
    lwz	r6, 0x28(r4)
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800271a8
    li	r6, 0
    b       _800271c4
_800271a8:
    cmpwi	r6, 0x3c
    blt     _800271b8
    addi	r6, r3, -0x9c
    b       _800271c4
_800271b8:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800271c4:
    sth	r6, 0x42(r4)
    lwz	r6, 0x2c(r4)
    lwz	r9, 0x1c(r4)
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800271e8
    li	r6, 0
    b       _80027204
_800271e8:
    cmpwi	r6, 0x3c
    blt     _800271f8
    addi	r6, r3, -0x9c
    b       _80027204
_800271f8:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027204:
    sth	r6, 0x46(r4)
    lwz	r6, 4(r4)
    clrlwi.	r6, r6, 0x1f
    beq     _800272d0
    lwz	r9, 0xc(r4)
    lwz	r6, 0x28(r4)
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027230
    li	r6, 0
    b       _8002724c
_80027230:
    cmpwi	r6, 0x3c
    blt     _80027240
    addi	r6, r3, -0x9c
    b       _8002724c
_80027240:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_8002724c:
    sth	r6, 0x4a(r4)
    lwz	r9, 0xc(r4)
    lwz	r6, 0x28(r4)
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _8002726c
    li	r6, 0
    b       _80027288
_8002726c:
    cmpwi	r6, 0x3c
    blt     _8002727c
    addi	r6, r3, -0x9c
    b       _80027288
_8002727c:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027288:
    sth	r6, 0x4e(r4)
    lwz	r6, 0x2c(r4)
    lwz	r9, 0xc(r4)
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800272ac
    li	r6, 0
    b       _800272c8
_800272ac:
    cmpwi	r6, 0x3c
    blt     _800272bc
    addi	r6, r3, -0x9c
    b       _800272c8
_800272bc:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800272c8:
    sth	r6, 0x52(r4)
    b       _800273a0
_800272d0:
    lwz	r10, 0x28(r4)
    lwz	r6, 0xc(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800272f4
    li	r6, 0
    b       _80027310
_800272f4:
    cmpwi	r6, 0x3c
    blt     _80027304
    addi	r6, r3, -0x9c
    b       _80027310
_80027304:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027310:
    sth	r6, 0x4a(r4)
    lwz	r10, 0x28(r4)
    lwz	r6, 0xc(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027338
    li	r6, 0
    b       _80027354
_80027338:
    cmpwi	r6, 0x3c
    blt     _80027348
    addi	r6, r3, -0x9c
    b       _80027354
_80027348:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027354:
    sth	r6, 0x4e(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0xc(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027380
    li	r6, 0
    b       _8002739c
_80027380:
    cmpwi	r6, 0x3c
    blt     _80027390
    addi	r6, r3, -0x9c
    b       _8002739c
_80027390:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_8002739c:
    sth	r6, 0x52(r4)
_800273a0:
    lwz	r6, 4(r4)
    rlwinm.	r6, r6, 0, 0x1e, 0x1e
    beq     _80027468
    lwz	r9, 0x10(r4)
    lwz	r6, 0x28(r4)
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800273c8
    li	r6, 0
    b       _800273e4
_800273c8:
    cmpwi	r6, 0x3c
    blt     _800273d8
    addi	r6, r3, -0x9c
    b       _800273e4
_800273d8:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800273e4:
    sth	r6, 0x56(r4)
    lwz	r9, 0x10(r4)
    lwz	r6, 0x28(r4)
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027404
    li	r6, 0
    b       _80027420
_80027404:
    cmpwi	r6, 0x3c
    blt     _80027414
    addi	r6, r3, -0x9c
    b       _80027420
_80027414:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027420:
    sth	r6, 0x5a(r4)
    lwz	r6, 0x2c(r4)
    lwz	r9, 0x10(r4)
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027444
    li	r6, 0
    b       _80027460
_80027444:
    cmpwi	r6, 0x3c
    blt     _80027454
    addi	r6, r3, -0x9c
    b       _80027460
_80027454:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027460:
    sth	r6, 0x5e(r4)
    b       _80027cdc
_80027468:
    lwz	r10, 0x28(r4)
    lwz	r6, 0x10(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _8002748c
    li	r6, 0
    b       _800274a8
_8002748c:
    cmpwi	r6, 0x3c
    blt     _8002749c
    addi	r6, r3, -0x9c
    b       _800274a8
_8002749c:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800274a8:
    sth	r6, 0x56(r4)
    lwz	r10, 0x28(r4)
    lwz	r6, 0x10(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800274d0
    li	r6, 0
    b       _800274ec
_800274d0:
    cmpwi	r6, 0x3c
    blt     _800274e0
    addi	r6, r3, -0x9c
    b       _800274ec
_800274e0:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800274ec:
    sth	r6, 0x5a(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0x10(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027518
    li	r6, 0
    b       _80027534
_80027518:
    cmpwi	r6, 0x3c
    blt     _80027528
    addi	r6, r3, -0x9c
    b       _80027534
_80027528:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027534:
    sth	r6, 0x5e(r4)
    b       _80027cdc
_8002753c:
    lwz	r10, 0x28(r4)
    lwz	r6, 0x20(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027560
    li	r6, 0
    b       _8002757c
_80027560:
    cmpwi	r6, 0x3c
    blt     _80027570
    addi	r6, r3, -0x9c
    b       _8002757c
_80027570:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_8002757c:
    sth	r6, 0x3e(r4)
    lwz	r10, 0x28(r4)
    lwz	r6, 0x24(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800275a4
    li	r6, 0
    b       _800275c0
_800275a4:
    cmpwi	r6, 0x3c
    blt     _800275b4
    addi	r6, r3, -0x9c
    b       _800275c0
_800275b4:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800275c0:
    sth	r6, 0x42(r4)
    lwz	r6, 0x2c(r4)
    lwz	r9, 0x1c(r4)
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800275e4
    li	r6, 0
    b       _80027600
_800275e4:
    cmpwi	r6, 0x3c
    blt     _800275f4
    addi	r6, r3, -0x9c
    b       _80027600
_800275f4:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027600:
    sth	r6, 0x46(r4)
    lwz	r6, 4(r4)
    clrlwi.	r6, r6, 0x1f
    beq     _800276dc
    lwz	r10, 0x28(r4)
    lwz	r6, 0x20(r4)
    lwz	r9, 0xc(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027634
    li	r6, 0
    b       _80027650
_80027634:
    cmpwi	r6, 0x3c
    blt     _80027644
    addi	r6, r3, -0x9c
    b       _80027650
_80027644:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027650:
    sth	r6, 0x4a(r4)
    lwz	r10, 0x28(r4)
    lwz	r6, 0x24(r4)
    lwz	r9, 0xc(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027678
    li	r6, 0
    b       _80027694
_80027678:
    cmpwi	r6, 0x3c
    blt     _80027688
    addi	r6, r3, -0x9c
    b       _80027694
_80027688:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027694:
    sth	r6, 0x4e(r4)
    lwz	r6, 0x2c(r4)
    lwz	r9, 0xc(r4)
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800276b8
    li	r6, 0
    b       _800276d4
_800276b8:
    cmpwi	r6, 0x3c
    blt     _800276c8
    addi	r6, r3, -0x9c
    b       _800276d4
_800276c8:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800276d4:
    sth	r6, 0x52(r4)
    b       _800277bc
_800276dc:
    lwz	r9, 0x20(r4)
    lwz	r6, 0xc(r4)
    lwz	r10, 0x28(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027708
    li	r6, 0
    b       _80027724
_80027708:
    cmpwi	r6, 0x3c
    blt     _80027718
    addi	r6, r3, -0x9c
    b       _80027724
_80027718:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027724:
    sth	r6, 0x4a(r4)
    lwz	r9, 0x24(r4)
    lwz	r6, 0xc(r4)
    lwz	r10, 0x28(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027754
    li	r6, 0
    b       _80027770
_80027754:
    cmpwi	r6, 0x3c
    blt     _80027764
    addi	r6, r3, -0x9c
    b       _80027770
_80027764:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027770:
    sth	r6, 0x4e(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0xc(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _8002779c
    li	r6, 0
    b       _800277b8
_8002779c:
    cmpwi	r6, 0x3c
    blt     _800277ac
    addi	r6, r3, -0x9c
    b       _800277b8
_800277ac:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800277b8:
    sth	r6, 0x52(r4)
_800277bc:
    lwz	r6, 4(r4)
    rlwinm.	r6, r6, 0, 0x1e, 0x1e
    beq     _80027894
    lwz	r10, 0x28(r4)
    lwz	r6, 0x20(r4)
    lwz	r9, 0x10(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800277ec
    li	r6, 0
    b       _80027808
_800277ec:
    cmpwi	r6, 0x3c
    blt     _800277fc
    addi	r6, r3, -0x9c
    b       _80027808
_800277fc:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027808:
    sth	r6, 0x56(r4)
    lwz	r10, 0x28(r4)
    lwz	r6, 0x24(r4)
    lwz	r9, 0x10(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027830
    li	r6, 0
    b       _8002784c
_80027830:
    cmpwi	r6, 0x3c
    blt     _80027840
    addi	r6, r3, -0x9c
    b       _8002784c
_80027840:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_8002784c:
    sth	r6, 0x5a(r4)
    lwz	r6, 0x2c(r4)
    lwz	r9, 0x10(r4)
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027870
    li	r6, 0
    b       _8002788c
_80027870:
    cmpwi	r6, 0x3c
    blt     _80027880
    addi	r6, r3, -0x9c
    b       _8002788c
_80027880:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_8002788c:
    sth	r6, 0x5e(r4)
    b       _80027cdc
_80027894:
    lwz	r9, 0x20(r4)
    lwz	r6, 0x10(r4)
    lwz	r10, 0x28(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800278c0
    li	r6, 0
    b       _800278dc
_800278c0:
    cmpwi	r6, 0x3c
    blt     _800278d0
    addi	r6, r3, -0x9c
    b       _800278dc
_800278d0:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800278dc:
    sth	r6, 0x56(r4)
    lwz	r9, 0x24(r4)
    lwz	r6, 0x10(r4)
    lwz	r10, 0x28(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _8002790c
    li	r6, 0
    b       _80027928
_8002790c:
    cmpwi	r6, 0x3c
    blt     _8002791c
    addi	r6, r3, -0x9c
    b       _80027928
_8002791c:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027928:
    sth	r6, 0x5a(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0x10(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    addi	r6, r6, -0x1e
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027954
    li	r6, 0
    b       _80027970
_80027954:
    cmpwi	r6, 0x3c
    blt     _80027964
    addi	r6, r3, -0x9c
    b       _80027970
_80027964:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027970:
    sth	r6, 0x5e(r4)
    b       _80027cdc
_80027978:
    lwz	r10, 0x28(r4)
    lwz	r6, 0x20(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _8002799c
    li	r6, 0
    b       _800279b8
_8002799c:
    cmpwi	r6, 0x3c
    blt     _800279ac
    addi	r6, r3, -0x9c
    b       _800279b8
_800279ac:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800279b8:
    sth	r6, 0x3e(r4)
    lwz	r10, 0x28(r4)
    lwz	r6, 0x24(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _800279e0
    li	r6, 0
    b       _800279fc
_800279e0:
    cmpwi	r6, 0x3c
    blt     _800279f0
    addi	r6, r3, -0x9c
    b       _800279fc
_800279f0:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_800279fc:
    sth	r6, 0x42(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0x30(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027a24
    li	r6, 0
    b       _80027a40
_80027a24:
    cmpwi	r6, 0x3c
    blt     _80027a34
    addi	r6, r3, -0x9c
    b       _80027a40
_80027a34:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027a40:
    sth	r6, 0x56(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0x34(r4)
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027a68
    li	r6, 0
    b       _80027a84
_80027a68:
    cmpwi	r6, 0x3c
    blt     _80027a78
    addi	r6, r3, -0x9c
    b       _80027a84
_80027a78:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027a84:
    sth	r6, 0x5a(r4)
    lwz	r6, 4(r4)
    clrlwi.	r6, r6, 0x1f
    beq     _80027ba8
    lwz	r10, 0x28(r4)
    lwz	r6, 0x20(r4)
    lwz	r9, 0xc(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027ab8
    li	r6, 0
    b       _80027ad4
_80027ab8:
    cmpwi	r6, 0x3c
    blt     _80027ac8
    addi	r6, r3, -0x9c
    b       _80027ad4
_80027ac8:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027ad4:
    sth	r6, 0x4a(r4)
    lwz	r10, 0x28(r4)
    lwz	r6, 0x24(r4)
    lwz	r9, 0xc(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027afc
    li	r6, 0
    b       _80027b18
_80027afc:
    cmpwi	r6, 0x3c
    blt     _80027b0c
    addi	r6, r3, -0x9c
    b       _80027b18
_80027b0c:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027b18:
    sth	r6, 0x4e(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0x30(r4)
    lwz	r9, 0xc(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027b40
    li	r6, 0
    b       _80027b5c
_80027b40:
    cmpwi	r6, 0x3c
    blt     _80027b50
    addi	r6, r3, -0x9c
    b       _80027b5c
_80027b50:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027b5c:
    sth	r6, 0x52(r4)
    lwz	r10, 0x2c(r4)
    lwz	r6, 0x34(r4)
    lwz	r9, 0xc(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027b84
    li	r6, 0
    b       _80027ba0
_80027b84:
    cmpwi	r6, 0x3c
    blt     _80027b94
    addi	r6, r3, -0x9c
    b       _80027ba0
_80027b94:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027ba0:
    sth	r6, 0x5e(r4)
    b       _80027cd8
_80027ba8:
    lwz	r9, 0x20(r4)
    lwz	r6, 0xc(r4)
    lwz	r10, 0x28(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027bd4
    li	r6, 0
    b       _80027bf0
_80027bd4:
    cmpwi	r6, 0x3c
    blt     _80027be4
    addi	r6, r3, -0x9c
    b       _80027bf0
_80027be4:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027bf0:
    sth	r6, 0x4a(r4)
    lwz	r9, 0x24(r4)
    lwz	r6, 0xc(r4)
    lwz	r10, 0x28(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027c20
    li	r6, 0
    b       _80027c3c
_80027c20:
    cmpwi	r6, 0x3c
    blt     _80027c30
    addi	r6, r3, -0x9c
    b       _80027c3c
_80027c30:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027c3c:
    sth	r6, 0x4e(r4)
    lwz	r9, 0x30(r4)
    lwz	r6, 0xc(r4)
    lwz	r10, 0x2c(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027c6c
    li	r6, 0
    b       _80027c88
_80027c6c:
    cmpwi	r6, 0x3c
    blt     _80027c7c
    addi	r6, r3, -0x9c
    b       _80027c88
_80027c7c:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027c88:
    sth	r6, 0x52(r4)
    lwz	r9, 0x34(r4)
    lwz	r6, 0xc(r4)
    lwz	r10, 0x2c(r4)
    add	r6, r6, r9
    lwz	r9, 0x1c(r4)
    add	r6, r6, r10
    add	r6, r9, r6
    cmpwi	r6, -0x388
    bgt     _80027cb8
    li	r6, 0
    b       _80027cd4
_80027cb8:
    cmpwi	r6, 0x3c
    blt     _80027cc8
    addi	r6, r3, -0x9c
    b       _80027cd4
_80027cc8:
    slwi	r6, r6, 1
    addi	r6, r6, 0x710
    lhzx	r6, r31, r6
_80027cd4:
    sth	r6, 0x5e(r4)
_80027cd8:
    ori	r8, r8, 0x4000
_80027cdc:
    lwz	r9, 4(r4)
    li	r6, 1
    rlwinm	r9, r9, 0, 2, 0
    stw	r9, 4(r4)
    lwz	r9, 4(r4)
    oris	r9, r9, 0x8000
    stw	r9, 4(r4)
_80027cf8:
    cmpwi	r7, 0
    beq     _80027d38
    lhz	r7, 0x38(r4)
    sth	r7, 0x19c(r5)
    lhz	r9, 0x38(r4)
    lhz	r7, 0x3a(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r7, r7, r9
    extsh	r7, r7
    sth	r7, 0x19e(r5)
    lwz	r7, 0x1c(r5)
    ori	r7, r7, 0x200
    stw	r7, 0x1c(r5)
_80027d38:
    cmpwi	r6, 0
    beq     _80027fd8
    lhz	r7, 0x3c(r4)
    addi	r6, r5, 0x14a
    cmplwi	r7, 0
    sth	r7, 0x14a(r5)
    addi	r6, r6, 2
    beq     _80027d5c
    ori	r8, r8, 1
_80027d5c:
    lhz	r9, 0x3c(r4)
    lhz	r7, 0x3e(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027d8c
    ori	r8, r8, 8
_80027d8c:
    lhz	r7, 0x40(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027da4
    ori	r8, r8, 2
_80027da4:
    lhz	r9, 0x40(r4)
    lhz	r7, 0x42(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027dd4
    ori	r8, r8, 8
_80027dd4:
    lhz	r7, 0x48(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027dec
    ori	r8, r8, 0x10
_80027dec:
    lhz	r9, 0x48(r4)
    lhz	r7, 0x4a(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027e1c
    ori	r8, r8, 0x40
_80027e1c:
    lhz	r7, 0x4c(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027e34
    ori	r8, r8, 0x20
_80027e34:
    lhz	r9, 0x4c(r4)
    lhz	r7, 0x4e(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027e64
    ori	r8, r8, 0x40
_80027e64:
    lhz	r7, 0x54(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027e7c
    ori	r8, r8, 0x200
_80027e7c:
    lhz	r9, 0x54(r4)
    lhz	r7, 0x56(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027eac
    ori	r8, r8, 0x800
_80027eac:
    lhz	r7, 0x58(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027ec4
    ori	r8, r8, 0x400
_80027ec4:
    lhz	r9, 0x58(r4)
    lhz	r7, 0x5a(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027ef4
    ori	r8, r8, 0x800
_80027ef4:
    lhz	r7, 0x5c(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027f0c
    ori	r8, r8, 0x1000
_80027f0c:
    lhz	r9, 0x5c(r4)
    lhz	r7, 0x5e(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027f3c
    ori	r8, r8, 0x2000
_80027f3c:
    lhz	r7, 0x44(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027f54
    ori	r8, r8, 4
_80027f54:
    lhz	r9, 0x44(r4)
    lhz	r7, 0x46(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    sth	r9, 0(r6)
    clrlwi.	r7, r9, 0x10
    addi	r6, r6, 2
    beq     _80027f84
    ori	r8, r8, 8
_80027f84:
    lhz	r7, 0x50(r4)
    cmplwi	r7, 0
    sth	r7, 0(r6)
    addi	r6, r6, 2
    beq     _80027f9c
    ori	r8, r8, 0x80
_80027f9c:
    lhz	r9, 0x50(r4)
    lhz	r7, 0x52(r4)
    subf	r7, r9, r7
    mulhw	r7, r0, r7
    srawi	r7, r7, 6
    srwi	r9, r7, 0x1f
    add	r9, r7, r9
    clrlwi.	r7, r9, 0x10
    sth	r9, 0(r6)
    beq     _80027fc8
    ori	r8, r8, 0x100
_80027fc8:
    sth	r8, 0x144(r5)
    lwz	r6, 0x1c(r5)
    ori	r6, r6, 0x12
    stw	r6, 0x1c(r5)
_80027fd8:
    addi	r4, r4, 0x60
    bdnz    _80027014
    lwz	r0, -0x783c(r13)
    lwz	r3, -0x7840(r13)
    cmpw	r0, r3
    ble     _8002801c
    addi	r0, r3, 1
    stw	r0, -0x7840(r13)
    lwz	r0, -0x7840(r13)
    add	r3, r31, r0
    lbz	r3, 0xb8c(r3)
    bl      DSPWriteMailHi
    lwz	r0, -0x7840(r13)
    add	r3, r31, r0
    lbz	r3, 0xb8c(r3)
    bl      DSPWriteMailMid
    b       _80028048
_8002801c:
    bge     _80028048
    addi	r0, r3, -1
    stw	r0, -0x7840(r13)
    lwz	r0, -0x7840(r13)
    add	r3, r31, r0
    lbz	r3, 0xb8c(r3)
    bl      DSPWriteMailHi
    lwz	r0, -0x7840(r13)
    add	r3, r31, r0
    lbz	r3, 0xb8c(r3)
    bl      DSPWriteMailMid
_80028048:
    lwz	r0, 0xc4(r1)
    lwz	r31, 0xbc(r1)
    addi	r1, r1, 0xc0
    mtlr	r0
    blr	
}

asm void fn_8002805C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    li	r0, 0
    stwu	r1, -8(r1)
    lfs	f1, -0x7e40(r2)
    stw	r0, -0x7830(r13)
    bl      fn_80028B34
    lfs	f1, -0x7e3c(r2)
    bl      fn_80028B2C
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_80028090(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    bl      OSDisableInterrupts
    lwz	r30, -0x7830(r13)
    mr	r31, r3
    b       _800280c0
_800280b4:
    lwz	r3, 8(r30)
    bl      axmix_device_ctrl_clear
    lwz	r30, 0(r30)
_800280c0:
    cmplwi	r30, 0
    bne     _800280b4
    li	r0, 0
    stw	r0, -0x7830(r13)
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void fn_800280F0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    lwz	r31, -0x7830(r13)
    b       _80028114
_80028108:
    mr	r3, r31
    bl      axmix_update_voice_state
    lwz	r31, 0(r31)
_80028114:
    cmplwi	r31, 0
    bne     _80028108
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void axmix_ctrl_store_time_param(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    li	r6, 0
    lis	r0, 0x4330
    stw	r5, 0x1c(r1)
    stw	r6, 0x10(r3)
    stw	r4, 8(r3)
    stw	r0, 0x18(r1)
    lfd	f1, -0x7e38(r2)
    lfd	f0, 0x18(r1)
    fsubs	f0, f0, f1
    stfs	f0, 0xc(r3)
    addi	r1, r1, 0x20
    blr	
}

asm void axmix_device_ctrl_accumulate_mix(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x68(r1)
    stfd	f31, 0x60(r1)
    stfd	f30, 0x58(r1)
    stmw	r19, 0x24(r1)
    mr	r19, r3
    lwz	r3, 8(r3)
    bl      fn_800231C4
    lfs	f1, 0xc(r19)
    lis     r3, -0x7fed
    lfs	f0, -0x7e30(r2)
    addi	r30, r3, -0x6ab0
    lwz	r29, 0x10(r19)
    fdivs	f30, f1, f0
    lfd	f31, -0x7e28(r2)
    li	r25, 0
    li	r26, 0
    li	r27, 0
    li	r28, 0
    li	r24, 0x40
    li	r23, 0x7f
    li	r22, 1
    li	r20, 0
    li	r21, 0
    lis	r31, 0x4330
    b       _8002836c
_800281d0:
    lwz	r0, 4(r29)
    cmplwi	r0, 0x10
    bgt     _80028368
    slwi	r0, r0, 2
    lwzx	r0, r30, r0
    mtctr	r0
    bctr	
    mr	r3, r29
    bl      axmix_mix_voice_state
    lfs	f0, 0x24(r29)
    lwz	r0, 0x28(r29)
    fadds	f30, f30, f0
    lbz	r24, 0x1c(r29)
    lbz	r23, 0x1d(r29)
    add	r27, r27, r0
    lhz	r21, 0x20(r29)
    lhz	r20, 0x22(r29)
    lbz	r22, 0x1e(r29)
    b       _80028368
    lbz	r24, 8(r29)
    lbz	r23, 9(r29)
    b       _80028368
    lhz	r21, 8(r29)
    lhz	r20, 0xa(r29)
    b       _80028368
    lbz	r22, 8(r29)
    b       _80028368
    lwz	r0, 8(r29)
    add	r28, r28, r0
    b       _80028368
    lwz	r0, 0x10(r29)
    add	r28, r28, r0
    b       _80028368
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x1c(r1)
    stw	r31, 0x18(r1)
    lfd	f1, 0x18(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    add	r28, r28, r0
    b       _80028368
    lwz	r0, 8(r29)
    add	r27, r27, r0
    b       _80028368
    lwz	r0, 8(r29)
    add	r26, r26, r0
    b       _80028368
    lwz	r0, 8(r29)
    add	r25, r25, r0
    b       _80028368
    lwz	r0, 0x10(r29)
    add	r27, r27, r0
    b       _80028368
    lwz	r0, 0x10(r29)
    add	r26, r26, r0
    b       _80028368
    lwz	r0, 0x10(r29)
    add	r25, r25, r0
    b       _80028368
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    stw	r31, 0x10(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    add	r27, r27, r0
    b       _80028368
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    stw	r31, 0x10(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    add	r26, r26, r0
    b       _80028368
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    stw	r31, 0x10(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    add	r25, r25, r0
_80028368:
    lwz	r29, 0(r29)
_8002836c:
    cmplwi	r29, 0
    bne     _800281d0
    srawi	r3, r28, 0x10
    bl      axmix_cent_to_ratio_lerp
    lwz	r28, 8(r19)
    fmuls	f30, f30, f1
    clrlwi	r4, r22, 0x18
    addi	r3, r28, 0
    bl      AXSetVoiceState_cached
    mr	r3, r28
    fmr	f1, f30
    bl      AXVPBSyncChannelB
    addi	r3, r28, 0
    addi	r4, r21, 0
    addi	r5, r20, 0
    bl      fn_80023228
    lwz	r3, 8(r19)
    addi	r6, r26, 0
    addi	r7, r25, 0
    srawi	r5, r27, 0x10
    clrlwi	r8, r24, 0x18
    clrlwi	r9, r23, 0x18
    li	r4, 0
    li	r10, 0
    bl      AXMixSetupVoiceEntry
    bl      OSDisableInterrupts
    lwz	r4, -0x7830(r13)
    cmplwi	r4, 0
    beq     _800283f0
    stw	r19, 4(r4)
    lwz	r0, -0x7830(r13)
    stw	r0, 0(r19)
    b       _800283f8
_800283f0:
    li	r0, 0
    stw	r0, 0(r19)
_800283f8:
    li	r0, 0
    stw	r0, 4(r19)
    stw	r19, -0x7830(r13)
    bl      OSRestoreInterrupts
    lmw	r19, 0x24(r1)
    lwz	r0, 0x6c(r1)
    lfd	f31, 0x60(r1)
    lfd	f30, 0x58(r1)
    addi	r1, r1, 0x68
    mtlr	r0
    blr	
}

asm void axmix_device_ctrl_unlink(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lwz	r0, -0x7830(r13)
    cmplw	r31, r0
    bne     _80028468
    lwz	r0, 0(r31)
    stw	r0, -0x7830(r13)
    lwz	r4, -0x7830(r13)
    cmplwi	r4, 0
    beq     _80028480
    li	r0, 0
    stw	r0, 4(r4)
    b       _80028480
_80028468:
    lwz	r5, 0(r31)
    lwz	r4, 4(r31)
    cmplwi	r5, 0
    stw	r5, 0(r4)
    beq     _80028480
    stw	r4, 4(r5)
_80028480:
    bl      OSRestoreInterrupts
    lwz	r3, 8(r31)
    bl      axmix_device_ctrl_clear
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void axmix_sound_alloc_init(void)
{
    nofralloc
    stw	r4, 0(r3)
    li	r0, 0
    stw	r5, 4(r3)
    stfs	f1, 8(r3)
    stw	r0, 0xc(r3)
    lfs	f0, -0x7e20(r2)
    stfs	f0, 0x1c(r3)
    stfs	f0, 0x18(r3)
    stfs	f0, 0x14(r3)
    stfs	f0, 0x10(r3)
    blr	
}

asm void axmix_ctrl_init_type2(void)
{
    nofralloc
    li	r0, 2
    stw	r0, 4(r3)
    li	r4, 0x40
    li	r0, 0x7f
    stb	r4, 8(r3)
    stb	r0, 9(r3)
    blr	
}

asm void axmix_ctrl_init_type5(void)
{
    nofralloc
    li	r0, 5
    stw	r0, 4(r3)
    li	r0, 0
    stw	r0, 8(r3)
    blr	
}

asm void axmix_ctrl_init_type7(void)
{
    nofralloc
    li	r0, 7
    stw	r0, 4(r3)
    li	r5, 0
    lis     r4, lbl_801299D0@ha
    stw	r5, 0x28(r3)
    addi	r4, r4, lbl_801299D0@l
    li	r0, 0x40
    stw	r4, 8(r3)
    stw	r0, 0xc(r3)
    lfs	f0, -0x7e20(r2)
    stfs	f0, 0x10(r3)
    stw	r5, 0x14(r3)
    stfs	f0, 0x24(r3)
    stfs	f0, 0x20(r3)
    stfs	f0, 0x1c(r3)
    stfs	f0, 0x18(r3)
    blr	
}

asm void axmix_ctrl_init_type8(void)
{
    nofralloc
    li	r0, 8
    stw	r0, 4(r3)
    li	r0, 0
    stw	r0, 8(r3)
    blr	
}

asm void axmix_ctrl_init_type9(void)
{
    nofralloc
    li	r0, 9
    stw	r0, 4(r3)
    li	r0, 0
    stw	r0, 8(r3)
    blr	
}

asm void axmix_ctrl_init_type10(void)
{
    nofralloc
    li	r0, 0xa
    stw	r0, 4(r3)
    li	r0, 0
    stw	r0, 8(r3)
    blr	
}

asm void axmix_ctrl_init_type11(void)
{
    nofralloc
    li	r0, 0xb
    stw	r0, 4(r3)
    li	r0, 0
    stw	r0, 0x10(r3)
    stw	r0, 0xc(r3)
    stw	r0, 8(r3)
    blr	
}

asm void axmix_ctrl_init_type14(void)
{
    nofralloc
    li	r0, 0xe
    stw	r0, 4(r3)
    li	r5, 0
    lis     r4, lbl_801299D0@ha
    stw	r5, 0x28(r3)
    addi	r4, r4, lbl_801299D0@l
    li	r0, 0x40
    stw	r4, 8(r3)
    stw	r0, 0xc(r3)
    lfs	f0, -0x7e20(r2)
    stfs	f0, 0x10(r3)
    stw	r5, 0x14(r3)
    stfs	f0, 0x24(r3)
    stfs	f0, 0x20(r3)
    stfs	f0, 0x1c(r3)
    stfs	f0, 0x18(r3)
    blr	
}

asm void axmix_update_voice_state(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x68(r1)
    stfd	f31, 0x60(r1)
    stfd	f30, 0x58(r1)
    stmw	r19, 0x24(r1)
    mr	r19, r3
    li	r25, 0
    li	r26, 0
    li	r27, 0
    li	r28, 0
    li	r24, 0x40
    li	r23, 0x7f
    li	r22, 1
    li	r20, 0
    li	r21, 0
    lis	r31, 0x4330
    lfs	f1, 0xc(r3)
    lis     r3, -0x7fed
    lfs	f0, -0x7e18(r2)
    addi	r30, r3, -0x6a68
    lwz	r29, 0x10(r19)
    fdivs	f30, f1, f0
    lfd	f31, -0x7e10(r2)
    b       _8002881c
_80028640:
    lwz	r0, 4(r29)
    cmplwi	r0, 0x10
    bgt     _80028818
    slwi	r0, r0, 2
    lwzx	r0, r30, r0
    mtctr	r0
    bctr	
    mr	r3, r29
    bl      axmix_mix_voice_state
    lfs	f0, 0x24(r29)
    lwz	r0, 0x28(r29)
    fadds	f30, f30, f0
    lbz	r24, 0x1c(r29)
    lbz	r23, 0x1d(r29)
    add	r27, r27, r0
    lhz	r21, 0x20(r29)
    lhz	r20, 0x22(r29)
    lbz	r22, 0x1e(r29)
    b       _80028818
    lbz	r24, 8(r29)
    lbz	r23, 9(r29)
    b       _80028818
    lhz	r21, 8(r29)
    lhz	r20, 0xa(r29)
    b       _80028818
    lbz	r22, 8(r29)
    b       _80028818
    lwz	r0, 8(r29)
    add	r28, r28, r0
    b       _80028818
    mr	r3, r29
    bl      axmix_param_ramp_step
    lwz	r0, 0x10(r29)
    add	r28, r28, r0
    b       _80028818
    addi	r3, r29, 8
    bl      fn_80028A78
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x1c(r1)
    stw	r31, 0x18(r1)
    lfd	f1, 0x18(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    add	r28, r28, r0
    b       _80028818
    lwz	r0, 8(r29)
    add	r27, r27, r0
    b       _80028818
    lwz	r0, 8(r29)
    add	r26, r26, r0
    b       _80028818
    lwz	r0, 8(r29)
    add	r25, r25, r0
    b       _80028818
    mr	r3, r29
    bl      axmix_param_ramp_step_dup
    lwz	r0, 0x10(r29)
    add	r27, r27, r0
    b       _80028818
    mr	r3, r29
    bl      axmix_param_ramp_step_dup
    lwz	r0, 0x10(r29)
    add	r26, r26, r0
    b       _80028818
    mr	r3, r29
    bl      axmix_param_ramp_step_dup
    lwz	r0, 0x10(r29)
    add	r25, r25, r0
    b       _80028818
    addi	r3, r29, 8
    bl      fn_80028A78
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    stw	r31, 0x10(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    add	r27, r27, r0
    b       _80028818
    addi	r3, r29, 8
    bl      fn_80028A78
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    stw	r31, 0x10(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    add	r26, r26, r0
    b       _80028818
    addi	r3, r29, 8
    bl      fn_80028A78
    lwz	r0, 0x28(r29)
    lfs	f0, 0x24(r29)
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    stw	r31, 0x10(r1)
    lfd	f1, 0x10(r1)
    fsubs	f1, f1, f31
    fmuls	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    add	r25, r25, r0
_80028818:
    lwz	r29, 0(r29)
_8002881c:
    cmplwi	r29, 0
    bne     _80028640
    srawi	r3, r28, 0x10
    bl      axmix_cent_to_ratio_lerp
    lwz	r19, 8(r19)
    fmuls	f30, f30, f1
    clrlwi	r4, r22, 0x18
    addi	r3, r19, 0
    bl      AXSetVoiceState_cached
    mr	r3, r19
    fmr	f1, f30
    bl      AXVPBSyncChannelB
    addi	r3, r19, 0
    addi	r4, r21, 0
    addi	r5, r20, 0
    bl      fn_80023228
    addi	r3, r19, 0
    srawi	r4, r27, 0x10
    bl      axmix_set_voice_param_08
    addi	r3, r19, 0
    addi	r4, r26, 0
    bl      fn_80026E2C
    addi	r3, r19, 0
    addi	r4, r25, 0
    bl      fn_80026EAC
    addi	r3, r19, 0
    clrlwi	r4, r24, 0x18
    bl      axmix_set_voice_volume
    addi	r3, r19, 0
    clrlwi	r4, r23, 0x18
    bl      axmix_set_voice_volume_clamped
    lmw	r19, 0x24(r1)
    lwz	r0, 0x6c(r1)
    lfd	f31, 0x60(r1)
    lfd	f30, 0x58(r1)
    addi	r1, r1, 0x68
    mtlr	r0
    blr	
}

asm void axmix_link_push(void)
{
    nofralloc
    lwz	r0, 0x10(r3)
    stw	r0, 0(r4)
    stw	r4, 0x10(r3)
    blr	
}

asm void axmix_cent_to_ratio_lerp(void)
{
    nofralloc
    cmpwi	r3, 0
    lis     r4, lbl_801295E0@ha
    addi	r4, r4, lbl_801295E0@l
    ble     _8002895c
    lis	r5, 0x1b4f
    addi	r0, r5, -0x7e4b
    mulhw	r0, r0, r3
    srawi	r8, r0, 7
    srawi	r0, r0, 7
    srwi	r5, r0, 0x1f
    add	r0, r0, r5
    mulli	r0, r0, 0x4b0
    lis	r5, 0x51ec
    addi	r5, r5, -0x7ae1
    subf	r0, r0, r3
    mulhw	r0, r5, r0
    srawi	r6, r0, 5
    mulhw	r0, r5, r3
    srawi	r0, r0, 5
    srwi	r9, r8, 0x1f
    srwi	r7, r6, 0x1f
    srwi	r5, r0, 0x1f
    add	r8, r8, r9
    add	r6, r6, r7
    add	r0, r0, r5
    mulli	r7, r0, 0x64
    slwi	r5, r8, 2
    slwi	r0, r6, 2
    add	r6, r4, r5
    add	r5, r4, r0
    lfs	f1, 0x190(r6)
    lfs	f0, 0x1c0(r5)
    subf	r5, r7, r3
    slwi	r0, r5, 2
    fmuls	f0, f1, f0
    lfsx	f1, r4, r0
    fmuls	f1, f1, f0
    blr	
_8002895c:
    bge     _800289b8
    lis	r5, 0x51ec
    addi	r0, r5, -0x7ae1
    mulhw	r0, r0, r3
    srawi	r6, r0, 5
    srawi	r0, r0, 5
    srwi	r5, r0, 0x1f
    add	r0, r0, r5
    mulli	r0, r0, 0x64
    subf.	r5, r0, r3
    srwi	r0, r6, 0x1f
    add	r3, r6, r0
    beq     _80028998
    addi	r5, r5, 0x64
    addi	r3, r3, -1
_80028998:
    mulli	r3, r3, -1
    slwi	r0, r3, 2
    add	r3, r4, r0
    slwi	r0, r5, 2
    lfs	f1, 0x1f0(r3)
    lfsx	f0, r4, r0
    fmuls	f1, f1, f0
    blr	
_800289b8:
    lfs	f1, -0x7e08(r2)
    blr	
}

asm void axmix_param_ramp_step(void)
{
    nofralloc
    lwz	r4, 0x10(r3)
    lwz	r0, 0xc(r3)
    cmpw	r4, r0
    beqlr	
    lwz	r0, 8(r3)
    add	r0, r4, r0
    stw	r0, 0x10(r3)
    lwz	r0, 8(r3)
    cmpwi	r0, 0
    ble     _80028a00
    lwz	r0, 0x10(r3)
    lwz	r4, 0xc(r3)
    cmpw	r0, r4
    blelr	
    stw	r4, 0x10(r3)
    blr	
_80028a00:
    bgelr	
    lwz	r0, 0x10(r3)
    lwz	r4, 0xc(r3)
    cmpw	r0, r4
    bgelr	
    stw	r4, 0x10(r3)
    blr	
}

asm void axmix_param_ramp_step_dup(void)
{
    nofralloc
    lwz	r4, 0x10(r3)
    lwz	r0, 0xc(r3)
    cmpw	r4, r0
    beqlr	
    lwz	r0, 8(r3)
    add	r0, r4, r0
    stw	r0, 0x10(r3)
    lwz	r0, 8(r3)
    cmpwi	r0, 0
    ble     _80028a5c
    lwz	r0, 0x10(r3)
    lwz	r4, 0xc(r3)
    cmpw	r0, r4
    blelr	
    stw	r4, 0x10(r3)
    blr	
_80028a5c:
    bgelr	
    lwz	r0, 0x10(r3)
    lwz	r4, 0xc(r3)
    cmpw	r0, r4
    bgelr	
    stw	r4, 0x10(r3)
    blr	
}

asm void fn_80028A78(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    lfs	f1, 0x10(r3)
    lfs	f0, 8(r3)
    fadds	f0, f1, f0
    stfs	f0, 0x10(r3)
    lfs	f1, 0x10(r3)
    lfs	f0, -0x7e00(r2)
    fcmpo	cr0, f1, f0
    cror	2, 1, 2
    bne     _80028afc
    fsubs	f0, f1, f1
    stfs	f0, 0x10(r31)
    bl      __cvt_fp2unsigned
    lwz	r0, 0xc(r31)
    add	r0, r0, r3
    stw	r0, 0xc(r31)
    lwz	r4, 0xc(r31)
    lwz	r3, 4(r31)
    divwu	r0, r4, r3
    mullw	r0, r0, r3
    subf	r0, r0, r4
    stw	r0, 0xc(r31)
    lfs	f0, 0x18(r31)
    stfs	f0, 0x14(r31)
    lwz	r0, 0xc(r31)
    lwz	r3, 0(r31)
    slwi	r0, r0, 2
    lfsx	f0, r3, r0
    stfs	f0, 0x18(r31)
_80028afc:
    lfs	f2, 0x14(r31)
    lfs	f0, 0x18(r31)
    lfs	f1, 0x10(r31)
    fsubs	f0, f2, f0
    fmuls	f0, f1, f0
    fsubs	f0, f2, f0
    stfs	f0, 0x1c(r31)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_80028B2C(void)
{
    nofralloc
    stfs	f1, -0x7828(r13)
    blr	
}

asm void fn_80028B34(void)
{
    nofralloc
    stfs	f1, -0x7824(r13)
    blr	
}

asm void axmix_mix_voice_state(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    mr	r31, r3
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    stw	r28, 0x18(r1)
    lwz	r0, 0x18(r3)
    lis     r3, lbl_80129FD0@ha
    addi	r30, r3, lbl_80129FD0@l
    cmplwi	r0, 0
    beq     _80028ca0
    lfs	f2, 8(r31)
    lfs	f0, -0x7df8(r2)
    fcmpo	cr0, f2, f0
    ble     _80028b9c
    lfs	f0, -0x7df0(r2)
    lfs	f1, -0x7df4(r2)
    fdivs	f0, f2, f0
    fmuls	f1, f1, f0
    bl      __cvt_fp2unsigned
    mr	r29, r3
    b       _80028bc4
_80028b9c:
    bge     _80028bc0
    lfs	f0, -0x7df0(r2)
    lfs	f1, -0x7df4(r2)
    fdivs	f0, f2, f0
    fmuls	f0, f1, f0
    fadds	f1, f1, f0
    bl      __cvt_fp2unsigned
    mr	r29, r3
    b       _80028bc4
_80028bc0:
    li	r29, 0
_80028bc4:
    lfs	f2, 0xc(r31)
    lfs	f0, -0x7df8(r2)
    fcmpo	cr0, f2, f0
    ble     _80028bf0
    lfs	f0, -0x7df0(r2)
    lfs	f1, -0x7df4(r2)
    fdivs	f0, f2, f0
    fmuls	f1, f1, f0
    bl      __cvt_fp2unsigned
    mr	r28, r3
    b       _80028c18
_80028bf0:
    bge     _80028c14
    lfs	f0, -0x7df0(r2)
    lfs	f1, -0x7df4(r2)
    fdivs	f0, f2, f0
    fmuls	f0, f1, f0
    fadds	f1, f1, f0
    bl      __cvt_fp2unsigned
    mr	r28, r3
    b       _80028c18
_80028c14:
    li	r28, 0
_80028c18:
    li	r0, 0
    stw	r0, 0x18(r31)
    bl      AXGetMixStateWord
    cmplwi	r3, 3
    bne     _80028c3c
    add	r3, r30, r29
    lbz	r0, 0x2d0(r3)
    stb	r0, 0x1c(r31)
    b       _80028c44
_80028c3c:
    lbzx	r0, r30, r29
    stb	r0, 0x1c(r31)
_80028c44:
    add	r4, r30, r29
    lbz	r0, 0x168(r4)
    add	r3, r30, r28
    stb	r0, 0x1d(r31)
    lbz	r0, 0x438(r4)
    sth	r0, 0x20(r31)
    lbz	r0, 0x5a0(r4)
    sth	r0, 0x22(r31)
    lbz	r0, 0x708(r3)
    stb	r0, 0x1e(r31)
    lfs	f1, 0x14(r31)
    lfs	f0, -0x7828(r13)
    fdivs	f0, f1, f0
    stfs	f0, 0x24(r31)
    lfs	f1, 0x10(r31)
    lfs	f0, -0x7824(r13)
    lfs	f2, -0x7dec(r2)
    fdivs	f0, f1, f0
    fmuls	f0, f2, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    stw	r0, 0x28(r31)
_80028ca0:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    lwz	r28, 0x18(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

#pragma pop
