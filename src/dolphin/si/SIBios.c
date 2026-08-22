typedef int s32;
typedef unsigned int u32;
typedef void OSContext;

extern void OSRegisterVersion(const char* version);
extern unsigned long long __OSGetSystemTime(void);
extern void OSSetAlarm(void* alarm, long long tick, void (*handler)(void*, OSContext*));
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern void __OSSetInterruptHandler(s32 interrupt, void (*handler)(s32, OSContext*));
extern void __OSUnmaskInterrupts(u32 mask);
extern void SISetSamplingRate(s32 msec);
extern void SIGetType(s32 chan);
extern void SIInterruptHandler(s32 interrupt, OSContext* context);

extern u32 Packet[32];
extern u32 Si[5];
extern u32 Type[4];
extern unsigned char lbl_80123B50[];
extern unsigned int lbl_8015CA90[];

#pragma push
#pragma force_active on
asm void SIInit(void)
{
    nofralloc
    mflr r0
    lis r4, Packet@ha
    stw r0, 0x4(r1)
    stwu r1, -0x10(r1)
    stw r31, 0xc(r1)
    addi r31, r4, Packet@l
    lwz r3, -0x7F78(r13)
    bl OSRegisterVersion
    li r5, -1
    stw r5, 0x60(r31)
    lis r3, Si@ha
    addi r4, r3, Si@l
    stw r5, 0x40(r31)
    li r0, 0
    li r3, 0
    stw r5, 0x20(r31)
    stw r5, 0x0(r31)
    stw r0, 0x4(r4)
    bl SISetSamplingRate
    lis r3, 0xcc00
_loop:
    addi r4, r3, 0x6400
    lwzu r0, 0x34(r4)
    clrlwi. r0, r0, 31
    bne _loop
    lis r0, 0x8000
    lis r3, SIInterruptHandler@ha
    stw r0, 0x0(r4)
    addi r4, r3, SIInterruptHandler@l
    li r3, 0x14
    bl __OSSetInterruptHandler
    li r3, 0x800
    bl __OSUnmaskInterrupts
    li r3, 0x0
    bl SIGetType
    li r3, 0x1
    bl SIGetType
    li r3, 0x2
    bl SIGetType
    li r3, 0x3
    bl SIGetType
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    addi r1, r1, 0x10
    mtlr r0
    blr
}
#pragma pop

#pragma push
#pragma force_active on
asm void fn_800122C4(s32 chan, void* output, s32 outputBytes, void* input,
                     s32 inputBytes, void (*callback)(s32, u32, OSContext*))
{
    nofralloc
    mflr r0
    lis r9, lbl_80123B50@ha
    stw r0, 0x4(r1)
    stwu r1, -0x48(r1)
    stmw r25, 0x2c(r1)
    addi r26, r3, 0x0
    addi r27, r4, 0x0
    addi r28, r5, 0x0
    addi r29, r6, 0x0
    addi r30, r7, 0x0
    addi r31, r8, 0x0
    addi r25, r9, lbl_80123B50@l
    bl OSDisableInterrupts
    lwz r0, 0x44(r25)
    cmpwi r0, -0x1
    beq _t_go
    bl OSRestoreInterrupts
    li r3, 0x0
    b _t_done
_t_go:
    lis r6, 0xcc00
    slwi r0, r26, 3
    lwz r7, 0x6438(r6)
    lis r4, 0xf00
    sraw r0, r4, r0
    and r7, r7, r0
    stw r7, 0x6438(r6)
    addi r0, r28, 0x3
    srwi r4, r0, 2
    stw r26, 0x44(r25)
    cmplwi r4, 0x0
    li r5, 0x0
    stw r31, 0x54(r25)
    stw r30, 0x4c(r25)
    stw r29, 0x50(r25)
    ble _t_poll
    cmplwi r4, 0x8
    subi r7, r4, 0x8
    ble _t_tail_setup
    addi r0, r7, 0x7
    srwi r0, r0, 3
    cmplwi r7, 0x0
    mtctr r0
    addi r7, r27, 0x0
    addi r6, r6, 0x6400
    ble _t_tail_setup
_t_bulk:
    lwz r0, 0x0(r7)
    addi r5, r5, 0x8
    stw r0, 0x80(r6)
    lwz r0, 0x4(r7)
    stw r0, 0x84(r6)
    lwz r0, 0x8(r7)
    stw r0, 0x88(r6)
    lwz r0, 0xc(r7)
    stw r0, 0x8c(r6)
    lwz r0, 0x10(r7)
    stw r0, 0x90(r6)
    lwz r0, 0x14(r7)
    stw r0, 0x94(r6)
    lwz r0, 0x18(r7)
    stw r0, 0x98(r6)
    lwz r0, 0x1c(r7)
    addi r7, r7, 0x20
    stw r0, 0x9c(r6)
    addi r6, r6, 0x20
    bdnz _t_bulk
    b _t_tail_setup
_t_tail:
    subf r0, r5, r4
    cmplw r5, r4
    mtctr r0
    bge _t_poll
_t_tail_loop:
    lwz r0, 0x0(r6)
    addi r6, r6, 0x4
    stw r0, 0x80(r7)
    addi r7, r7, 0x4
    bdnz _t_tail_loop
_t_poll:
    lis r4, 0xcc00
    addi r6, r4, 0x6400
    lwzu r0, 0x34(r6)
    li r4, 0x1
    stw r0, 0x24(r1)
    cmplwi r31, 0x0
    lbz r0, 0x24(r1)
    rlwimi r0, r4, 7, 24, 24
    stb r0, 0x24(r1)
    beq _t_no_cb
    b _t_cb
_t_no_cb:
    li r4, 0x0
_t_cb:
    lbz r0, 0x24(r1)
    rlwimi r0, r4, 6, 25, 25
    cmplwi r28, 0x80
    stb r0, 0x24(r1)
    bne _t_ylen
    li r0, 0x0
    b _t_xlen
_t_ylen:
    mr r0, r28
_t_xlen:
    clrlwi r4, r0, 24
    lbz r0, 0x25(r1)
    rlwimi r0, r4, 0, 25, 31
    cmplwi r30, 0x80
    stb r0, 0x25(r1)
    bne _t_xlen2
    li r0, 0x0
    b _t_ylen2
_t_xlen2:
    mr r0, r30
_t_ylen2:
    clrlwi r4, r0, 24
    lbz r0, 0x26(r1)
    rlwimi r0, r4, 0, 25, 31
    stb r0, 0x26(r1)
    li r4, 0x1
    lbz r0, 0x27(r1)
    rlwimi r0, r26, 1, 29, 30
    stb r0, 0x27(r1)
    lbz r0, 0x27(r1)
    rlwimi r0, r4, 0, 31, 31
    stb r0, 0x27(r1)
    lwz r0, 0x24(r1)
    stw r0, 0x0(r6)
    bl OSRestoreInterrupts
    li r3, 0x1
    b _t_done
_t_tail_setup:
    lis r6, 0xcc00
    slwi r0, r5, 2
    addi r7, r6, 0x6400
    add r6, r27, r0
    add r7, r7, r0
    b _t_tail
_t_done:
    lmw r25, 0x2c(r1)
    lwz r0, 0x4c(r1)
    addi r1, r1, 0x48
    mtlr r0
    blr
}
#pragma pop

#pragma push
#pragma force_active on
asm u32 SIGetStatus(s32 chan)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    stwu r1, -0x18(r1)
    stw r31, 0x14(r1)
    stw r30, 0x10(r1)
    mr r30, r3
    bl OSDisableInterrupts
    lis r4, 0xcc00
    subfic r0, r30, 0x3
    lwz r31, 0x6438(r4)
    slwi r0, r0, 3
    srw r31, r31, r0
    rlwinm. r0, r31, 0, 28, 28
    beq _retstatus
    lis r4, Type@ha
    slwi r5, r30, 2
    addi r0, r4, Type@l
    add r4, r0, r5
    lwz r0, 0x0(r4)
    rlwinm. r0, r0, 0, 24, 24
    bne _retstatus
    li r0, 0x8
    stw r0, 0x0(r4)
_retstatus:
    bl OSRestoreInterrupts
    mr r3, r31
    lwz r0, 0x1c(r1)
    lwz r31, 0x14(r1)
    lwz r30, 0x10(r1)
    addi r1, r1, 0x18
    mtlr r0
    blr
}

asm void SISetCommand(s32 chan, u32 command)
{
    nofralloc
    mulli r0, r3, 0xc
    lis r3, 0xcc00
    addi r3, r3, 0x6400
    stwx r4, r3, r0
    blr
}

asm void fn_80012560(void)
{
    nofralloc
    lis r3, 0xcc00
    lis r0, 0x8000
    stw r0, 0x6438(r3)
    blr
}

asm void SISetXY(s32 x, s32 y)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    slwi r0, r4, 8
    stwu r1, -0x18(r1)
    stw r31, 0x14(r1)
    slwi r31, r3, 16
    or r31, r31, r0
    bl OSDisableInterrupts
    lis r4, Si@ha
    addi r4, r4, Si@l
    lwz r0, 0x4(r4)
    addi r5, r4, 0x4
    lis r4, 0xcc00
    rlwinm r0, r0, 0, 24, 5
    stw r0, 0x0(r5)
    lwz r0, 0x0(r5)
    or r0, r0, r31
    stw r0, 0x0(r5)
    lwz r31, 0x0(r5)
    stw r31, 0x6430(r4)
    bl OSRestoreInterrupts
    mr r3, r31
    lwz r0, 0x1c(r1)
    lwz r31, 0x14(r1)
    addi r1, r1, 0x18
    mtlr r0
    blr
}
#pragma pop

#pragma push
#pragma force_active on
asm u32 fn_800125DC(u32 poll)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    stwu r1, -0x18(r1)
    stw r31, 0x14(r1)
    mr. r31, r3
    bne _ep_go
    lis r3, Si@ha
    addi r3, r3, Si@l
    lwz r3, 0x4(r3)
    b _ep_ret
_ep_go:
    bl OSDisableInterrupts
    lis r4, Si@ha
    addi r4, r4, Si@l
    srwi r31, r31, 24
    lwz r0, 0x4(r4)
    addi r5, r4, 0x4
    extrwi r4, r31, 4, 24
    andc r0, r0, r4
    stw r0, 0x0(r5)
    oris r0, r4, 0x3ff
    ori r0, r0, 0xfff0
    and r31, r31, r0
    lwz r0, 0x0(r5)
    rlwinm r31, r31, 0, 24, 5
    or r0, r0, r31
    stw r0, 0x0(r5)
    lis r4, 0xcc00
    addi r4, r4, 0x6400
    lwz r31, 0x0(r5)
    lis r0, 0x8000
    stw r0, 0x38(r4)
    stw r31, 0x30(r4)
    bl OSRestoreInterrupts
    mr r3, r31
_ep_ret:
    lwz r0, 0x1c(r1)
    lwz r31, 0x14(r1)
    addi r1, r1, 0x18
    mtlr r0
    blr
}

asm u32 fn_80012678(u32 poll)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    stwu r1, -0x18(r1)
    stw r31, 0x14(r1)
    mr. r31, r3
    bne _dp_go
    lis r3, Si@ha
    addi r3, r3, Si@l
    lwz r3, 0x4(r3)
    b _dp_ret
_dp_go:
    bl OSDisableInterrupts
    lis r4, Si@ha
    addi r4, r4, Si@l
    lwz r0, 0x4(r4)
    rlwinm r31, r31, 8, 24, 27
    addi r5, r4, 0x4
    lis r4, 0xcc00
    andc r31, r0, r31
    stw r31, 0x6430(r4)
    stw r31, 0x0(r5)
    bl OSRestoreInterrupts
    mr r3, r31
_dp_ret:
    lwz r0, 0x1c(r1)
    lwz r31, 0x14(r1)
    addi r1, r1, 0x18
    mtlr r0
    blr
}

asm int fn_800126E4(s32 chan, void* data)
{
    nofralloc
    mflr r0
    lis r4, Packet@ha
    stw r0, 0x4(r1)
    stwu r1, -0x28(r1)
    stw r31, 0x24(r1)
    addi r31, r4, Packet@l
    stw r30, 0x20(r1)
    addi r30, r3, 0x0
    stw r29, 0x1c(r1)
    bl OSDisableInterrupts
    lis r4, 0xcc00
    subfic r0, r30, 0x3
    lwz r29, 0x6438(r4)
    slwi r0, r0, 3
    srw r29, r29, r0
    rlwinm. r0, r29, 0, 28, 28
    beq _gr_nostat
    lis r4, Type@ha
    slwi r5, r30, 2
    addi r0, r4, Type@l
    add r4, r0, r5
    lwz r0, 0x0(r4)
    rlwinm. r0, r0, 0, 24, 24
    bne _gr_nostat
    li r0, 0x8
    stw r0, 0x0(r4)
_gr_nostat:
    bl OSRestoreInterrupts
    rlwinm. r0, r29, 0, 26, 26
    beq _gr_zero
    mulli r4, r30, 0xc
    lis r3, 0xcc00
    addi r0, r3, 0x6400
    add r3, r0, r4
    slwi r4, r30, 3
    lwz r0, 0x4(r3)
    add r6, r31, r4
    stw r0, 0x1c0(r6)
    slwi r0, r30, 2
    add r4, r31, r0
    lwz r5, 0x8(r3)
    li r0, 0x1
    li r3, 0x1
    stw r5, 0x1c4(r6)
    stw r0, 0x1b0(r4)
    b _gr_ret
_gr_zero:
    li r3, 0x0
_gr_ret:
    lwz r0, 0x2c(r1)
    lwz r31, 0x24(r1)
    lwz r30, 0x20(r1)
    lwz r29, 0x1c(r1)
    addi r1, r1, 0x28
    mtlr r0
    blr
}

asm int SIGetResponse(s32 chan, void* data)
{
    nofralloc
    mflr r0
    lis r5, Packet@ha
    stw r0, 0x4(r1)
    stwu r1, -0x28(r1)
    stmw r27, 0x14(r1)
    addi r29, r3, 0x0
    addi r30, r4, 0x0
    addi r28, r5, Packet@l
    bl OSDisableInterrupts
    addi r31, r3, 0x0
    addi r3, r29, 0x0
    bl SIGetStatus
    rlwinm. r0, r3, 0, 26, 26
    beq _sr_nordst
    mulli r4, r29, 0xc
    lis r3, 0xcc00
    addi r0, r3, 0x6400
    add r4, r0, r4
    slwi r3, r29, 3
    lwz r0, 0x4(r4)
    add r5, r28, r3
    stw r0, 0x1c0(r5)
    slwi r0, r29, 2
    add r3, r28, r0
    lwz r4, 0x8(r4)
    li r0, 0x1
    stw r4, 0x1c4(r5)
    stw r0, 0x1b0(r3)
_sr_nordst:
    slwi r0, r29, 2
    add r3, r28, r0
    lwz r27, 0x1b0(r3)
    li r0, 0x0
    cmpwi r27, 0x0
    stw r0, 0x1b0(r3)
    beq _sr_empty
    slwi r0, r29, 3
    add r3, r28, r0
    lwz r0, 0x1c0(r3)
    stw r0, 0x0(r30)
    lwz r0, 0x1c4(r3)
    stw r0, 0x4(r30)
_sr_empty:
    mr r3, r31
    bl OSRestoreInterrupts
    mr r3, r27
    lmw r27, 0x14(r1)
    lwz r0, 0x2c(r1)
    addi r1, r1, 0x28
    mtlr r0
    blr
}

asm void fn_8001287C(void* alarm, OSContext* context)
{
    nofralloc
    mflr r0
    lis r4, lbl_8015CA90@ha
    stw r0, 0x4(r1)
    addi r0, r4, lbl_8015CA90@l
    lis r4, 0x6666
    subf r0, r0, r3
    stwu r1, -0x20(r1)
    addi r3, r4, 0x6667
    mulhw r0, r3, r0
    stw r31, 0x1c(r1)
    srawi r0, r0, 4
    srwi r3, r0, 31
    add r0, r0, r3
    lis r3, Packet@ha
    slwi r4, r0, 5
    addi r0, r3, Packet@l
    add r31, r0, r4
    lwz r3, 0x0(r31)
    cmpwi r3, -0x1
    beq _ah_out
    lwz r4, 0x4(r31)
    lwz r5, 0x8(r31)
    lwz r6, 0xc(r31)
    lwz r7, 0x10(r31)
    lwz r8, 0x14(r31)
    bl fn_800122C4
    cmpwi r3, 0x0
    beq _ah_out
    li r0, -0x1
    stw r0, 0x0(r31)
_ah_out:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    addi r1, r1, 0x20
    mtlr r0
    blr
}
#pragma pop

#pragma push
#pragma force_active on
asm int SITransfer(s32 chan, void* output, s32 outputBytes, void* input,
                   s32 inputBytes, void (*callback)(s32, u32, OSContext*),
                   u32 delayHi, u32 delayLo)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    stwu r1, -0x60(r1)
    stmw r19, 0x2c(r1)
    addi r24, r3, 0x0
    lis r3, Packet@ha
    addi r23, r3, Packet@l
    slwi r0, r24, 5
    addi r25, r4, 0x0
    addi r26, r5, 0x0
    addi r27, r6, 0x0
    addi r28, r7, 0x0
    addi r29, r8, 0x0
    addi r31, r9, 0x0
    addi r30, r10, 0x0
    add r22, r23, r0
    bl OSDisableInterrupts
    lwz r0, 0x0(r22)
    addi r21, r3, 0x0
    cmpwi r0, -0x1
    bne _tr_busy
    lis r3, Si@ha
    lwz r0, Si@l(r3)
    cmpw r0, r24
    bne _tr_go
_tr_busy:
    mr r3, r21
    bl OSRestoreInterrupts
    li r3, 0x0
    b _tr_ret
_tr_go:
    bl __OSGetSystemTime
    li r0, 0x0
    xor r5, r30, r0
    xor r0, r31, r0
    or. r0, r5, r0
    bne _tr_delayed
    addi r19, r4, 0x0
    addi r20, r3, 0x0
    b _tr_cmp
_tr_delayed:
    slwi r0, r24, 3
    add r6, r23, r0
    lwz r5, 0x144(r6)
    lwz r0, 0x140(r6)
    addc r19, r30, r5
    adde r20, r31, r0
_tr_cmp:
    xoris r6, r3, 0x8000
    xoris r5, r20, 0x8000
    subfc r0, r19, r4
    subfe r5, r5, r6
    subfe r5, r6, r6
    neg. r5, r5
    beq _tr_now
    mulli r0, r24, 0x28
    subfc r30, r4, r19
    subfe r31, r3, r20
    lis r4, fn_8001287C@ha
    add r3, r23, r0
    addi r7, r4, fn_8001287C@l
    addi r6, r30, 0x0
    addi r5, r31, 0x0
    addi r3, r3, 0x80
    bl OSSetAlarm
    b _tr_save
_tr_now:
    addi r3, r24, 0x0
    addi r4, r25, 0x0
    addi r5, r26, 0x0
    addi r6, r27, 0x0
    addi r7, r28, 0x0
    addi r8, r29, 0x0
    bl fn_800122C4
    cmpwi r3, 0x0
    beq _tr_save
    mr r3, r21
    bl OSRestoreInterrupts
    li r3, 0x1
    b _tr_ret
_tr_save:
    stw r24, 0x0(r22)
    mr r3, r21
    stw r25, 0x4(r22)
    stw r26, 0x8(r22)
    stw r27, 0xc(r22)
    stw r28, 0x10(r22)
    stw r29, 0x14(r22)
    stw r19, 0x1c(r22)
    stw r20, 0x18(r22)
    bl OSRestoreInterrupts
    li r3, 0x1
_tr_ret:
    lmw r19, 0x2c(r1)
    lwz r0, 0x64(r1)
    addi r1, r1, 0x60
    mtlr r0
    blr
}
#pragma pop
