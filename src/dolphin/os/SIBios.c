typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;
typedef unsigned long long u64;
typedef struct OSContext {
    unsigned int gpr[32];
    unsigned int cr, lr, ctr, xer;
    double fpr[32];
    unsigned int fpscr_pad;
    unsigned int fpscr;
    unsigned int srr0, srr1;
    unsigned short mode, state;
    unsigned int gqr[8];
    double psf[32];
} OSContext;
typedef int BOOL;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(register int level);
extern unsigned long long __OSGetSystemTime(void);
extern u32 fn_8001BF84(void);
extern void OSSetWirelessID(s32 chan, u32 unk);
extern u32 OSGetWirelessID(s32 chan);
extern void OSCancelAlarm(void* alarm);
extern void OSSetAlarm(register void* alarm, register s64 tick,
                       register void (*handler)(void*, OSContext*));
extern void OSReport(const char* msg, ...);
extern void VIGetTvFormat(void);
extern void OSRegisterVersion(const char* version);

extern u32 CompleteTransfer(void);
extern int SITransfer(s32 chan, void* output, s32 outputBytes, void* input,
                      s32 inputBytes, void (*callback)(s32, u32, OSContext*),
                      u32 delayHi, u32 delayLo);
extern u32 SIGetResponseRaw(register s32 chan);
extern void __OSSetInterruptHandler(s32 interrupt, void* handler);
extern u32 __OSUnmaskInterrupts(u32 mask);

/* forward declarations for functions defined below */
extern s32 fn_8001191C(void);
extern s32 SIIsChanBusy(register s32 chan);
extern u32 SIGetStatus(register s32 chan);
extern void SISetCommand(register s32 chan, register u32 command);
extern void SITransferCommands(void);
extern u32 SISetXY(register u32 x, register u32 y);
extern void SIGetWirelessID(register s32 chan, register u32 unk);
extern void SIGetWirelessIDBitfield(register s32 chan, register u32 unk);
extern u32 SIGetResponse(register s32 chan, register void* data);
extern u32 SIGetType(register s32 chan);
extern u32 SIGetTypeAsync(register s32 chan, register void (*callback)(s32, u32));
extern u32 fn_8001300C(register u32 type);
extern char* fn_8001317C(register s32 chan);
extern void SISetSamplingRate(register s32 msec);
extern void fn_800133E0(register s32 chan);
extern int fn_80013428(register s32 chan, register void* callback);
extern void fn_800134DC(register s32 chan, register u32 status, register OSContext* context);
extern void GetTypeCallback(register s32 chan, register u32 status, register OSContext* context);
extern void fn_800135CC(register s32 chan, register u32 status);
extern int fn_800136E8(register s32 chan, register u32 cmd, register u32 param,
                       register void (*callback)(s32));
extern void fn_8001375C(register s32 chan);
extern int fn_800137C4(register s32 chan, register void* out);
extern void fn_80013934(register s32 interrupt, register OSContext* context);
extern void* fn_80013994(register void* handler);
extern void fn_800139E8(register s32 chan, register u32 unk, register s32 val);
extern int __SITransfer(register s32 chan, register void* output,
                        register s32 outputBytes, register void* input,
                        register s32 inputBytes,
                        register void (*callback)(s32, u32, OSContext*));
extern BOOL SIEnablePollingInterrupt(register BOOL enable);
extern BOOL SIRegisterPollingHandler(register void* handler);
extern BOOL SIUnregisterPollingHandler(register void* handler);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern void __OSReschedule(void);
extern u32 OSGetCurrentContext(void);

/*
 * Far globals (.data/.bss): absolute-addressed.
 * Near globals (.sdata/.sbss): referenced through the r13 small-data anchor
 * with hand-resolved displacements (.sdata base 0x801A63C0 + 0x8000 = r13).
 */
extern u32 Si[5];               /* .data:0x80123B94 */
extern u32 Packet[32];          /* .bss:0x8015CA10 */
extern u32 Type[4];             /* .data:0x80123BA8 */
extern u64 TypeTime[4];         /* .bss:0x8015CB30 */
extern u64 lbl_8015CB50[4];     /* .bss:0x8015CB50 */
extern u32 lbl_8015CA90[];      /* .bss:0x8015CA90 (alarms, 4 x 0x28) */
extern u32 lbl_8015CB70[];      /* .bss:0x8015CB70 (callbacks, 4 x 4) */
extern u32 lbl_8015CBB0[];      /* .bss:0x8015CBB0 (poll handlers, 0x60) */
struct SIReq {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 cmd;        /* 0x0c */
    u32 outputLen;  /* 0x10 */
    u32 active;     /* 0x14 */
    u32 result;     /* 0x18 */
    u32 unk1c;
    u32 unk20;
    void (*done)(s32 chan); /* 0x24 */
};

extern struct SIReq lbl_8015CC10[4];   /* .bss:0x8015CC10 */
extern void (* volatile lbl_801A6830)(s32 interrupt, OSContext* context); /* .sbss */
extern u32 SamplingRate;   /* .sbss:0x801A6820 */
extern u64 lbl_801A6828;   /* .sbss:0x801A6828 */
extern char lbl_80123B50[];     /* .data:0x80123B50 (device names blob) */
extern u8 XYNTSC[];             /* .data:0x80123C68 (sampling table) */

/* ---- fn_8001191C ---- */
#pragma push
#pragma force_active on
asm s32 fn_8001191C(void)
{
    nofralloc
    lis         r3, Si@ha
    lwz         r0, Si@l(r3)
    cmpwi       r0, -0x1
    beq         L_80011934
    li          r3, 0x1
    blr
L_80011934:
    li          r3, 0x0
    blr
}
#pragma pop

/* ---- SIIsChanBusy ---- */
#pragma push
#pragma force_active on
asm s32 SIIsChanBusy(register s32 chan)
{
    nofralloc
    lis         r4, Packet@ha
    slwi        r5, r3, 5
    addi        r0, r4, Packet@l
    add         r4, r0, r5
    lwz         r0, 0x0(r4)
    li          r5, 0x1
    cmpwi       r0, -0x1
    bne         L_80011970
    lis         r4, Si@ha
    lwz         r0, Si@l(r4)
    cmpw        r0, r3
    beq         L_80011970
    li          r5, 0x0
L_80011970:
    mr          r3, r5
    blr
}
#pragma pop

/* ---- CompleteTransfer ---- */
#pragma push
#pragma force_active on
asm u32 CompleteTransfer(void)
{
    nofralloc
    mflr        r0
    lis         r3, 0xCC00
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    stw         r30, 0x18(r1)
    addi        r30, r3, 0x6400
    stw         r29, 0x14(r1)
    addi        r29, r30, 0x34
    stw         r28, 0x10(r1)
    lwz         r0, 0x6434(r3)
    lwz         r28, 0x6438(r3)
    lis         r3, lbl_80123B50@ha
    oris        r0, r0, 0x8000
    clrrwi      r0, r0, 1
    stw         r0, 0x34(r30)
    addi        r31, r3, lbl_80123B50@l
    lwz         r0, 0x44(r31)
    cmpwi       r0, -0x1
    beq         L_80011C38
    bl          __OSGetSystemTime
    lwz         r6, 0x44(r31)
    lis         r5, lbl_8015CB50@ha
    addi        r0, r5, lbl_8015CB50@l
    slwi        r5, r6, 3
    add         r5, r0, r5
    stw         r4, 0x4(r5)
    addi        r6, r31, 0x4c
    li          r4, 0x0
    stw         r3, 0x0(r5)
    lwz         r0, 0x4c(r31)
    lwz         r5, 0x50(r31)
    srwi        r7, r0, 2
    cmplwi      r7, 0x0
    ble         L_80011AA0
    cmplwi      r7, 0x8
    subi        r3, r7, 0x8
    ble         L_80011C40
    addi        r0, r3, 0x7
    srwi        r0, r0, 3
    cmplwi      r3, 0x0
    mtctr       r0
    ble         L_80011C40
L_80011A24:
    lwz         r0, 0x80(r30)
    addi        r4, r4, 0x8
    stw         r0, 0x0(r5)
    lwz         r0, 0x84(r30)
    stw         r0, 0x4(r5)
    lwz         r0, 0x88(r30)
    stw         r0, 0x8(r5)
    lwz         r0, 0x8c(r30)
    stw         r0, 0xc(r5)
    lwz         r0, 0x90(r30)
    stw         r0, 0x10(r5)
    lwz         r0, 0x94(r30)
    stw         r0, 0x14(r5)
    lwz         r0, 0x98(r30)
    stw         r0, 0x18(r5)
    lwz         r0, 0x9c(r30)
    addi        r30, r30, 0x20
    stw         r0, 0x1c(r5)
    addi        r5, r5, 0x20
    bdnz        L_80011A24
    b           L_80011C40
L_80011A78:
    subf        r0, r4, r7
    cmplw       r4, r7
    mtctr       r0
    bge         L_80011AA0
L_80011A88:
    lwz         r0, 0x80(r3)
    addi        r3, r3, 0x4
    addi        r4, r4, 0x1
    stw         r0, 0x0(r5)
    addi        r5, r5, 0x4
    bdnz        L_80011A88
L_80011AA0:
    lwz         r0, 0x0(r6)
    clrlwi.     r3, r0, 30
    beq         L_80011BB8
    lis         r6, 0xCC00
    addi        r6, r6, 0x6400
    slwi        r0, r4, 2
    add         r4, r6, r0
    lwz         r6, 0x80(r4)
    li          r4, 0x0
    ble         L_80011BB8
    cmplwi      r3, 0x8
    subi        r7, r3, 0x8
    ble         L_80011B8C
    addi        r0, r7, 0x7
    srwi        r0, r0, 3
    cmplwi      r7, 0x0
    mtctr       r0
    ble         L_80011B8C
L_80011AE8:
    subfic      r0, r4, 0x3
    slwi        r7, r0, 3
    addi        r0, r4, 0x1
    srw         r7, r6, r7
    subfic      r0, r0, 0x3
    stb         r7, 0x0(r5)
    slwi        r0, r0, 3
    addi        r7, r4, 0x2
    srw         r0, r6, r0
    subfic      r7, r7, 0x3
    stb         r0, 0x1(r5)
    slwi        r7, r7, 3
    srw         r12, r6, r7
    neg         r7, r4
    stb         r12, 0x2(r5)
    slwi        r8, r7, 3
    addi        r7, r4, 0x4
    srw         r11, r6, r8
    subfic      r7, r7, 0x3
    stb         r11, 0x3(r5)
    slwi        r8, r7, 3
    addi        r7, r4, 0x5
    srw         r10, r6, r8
    subfic      r7, r7, 0x3
    stb         r10, 0x4(r5)
    slwi        r8, r7, 3
    srw         r9, r6, r8
    addi        r7, r4, 0x6
    stb         r9, 0x5(r5)
    subfic      r8, r7, 0x3
    addi        r7, r4, 0x7
    slwi        r8, r8, 3
    srw         r8, r6, r8
    subfic      r7, r7, 0x3
    stb         r8, 0x6(r5)
    slwi        r7, r7, 3
    srw         r7, r6, r7
    stb         r7, 0x7(r5)
    addi        r5, r5, 0x8
    addi        r4, r4, 0x8
    bdnz        L_80011AE8
L_80011B8C:
    subf        r0, r4, r3
    cmplw       r4, r3
    mtctr       r0
    bge         L_80011BB8
L_80011B9C:
    subfic      r0, r4, 0x3
    slwi        r0, r0, 3
    srw         r0, r6, r0
    stb         r0, 0x0(r5)
    addi        r5, r5, 0x1
    addi        r4, r4, 0x1
    bdnz        L_80011B9C
L_80011BB8:
    lwz         r0, 0x0(r29)
    rlwinm.     r0, r0, 0, 2, 2
    beq         L_80011C0C
    lwz         r3, 0x44(r31)
    subfic      r0, r3, 0x3
    slwi        r0, r0, 3
    srw         r28, r28, r0
    clrlwi      r28, r28, 28
    rlwinm.     r0, r28, 0, 28, 28
    beq         L_80011BFC
    slwi        r0, r3, 2
    add         r3, r31, r0
    lwzu        r0, 0x58(r3)
    rlwinm.     r0, r0, 0, 24, 24
    bne         L_80011BFC
    li          r0, 0x8
    stw         r0, 0x0(r3)
L_80011BFC:
    cmplwi      r28, 0x0
    bne         L_80011C30
    li          r28, 0x4
    b           L_80011C30
L_80011C0C:
    bl          __OSGetSystemTime
    lwz         r6, 0x44(r31)
    lis         r5, TypeTime@ha
    addi        r0, r5, TypeTime@l
    slwi        r5, r6, 3
    add         r5, r0, r5
    stw         r4, 0x4(r5)
    li          r28, 0x0
    stw         r3, 0x0(r5)
L_80011C30:
    li          r0, -0x1
    stw         r0, 0x44(r31)
L_80011C38:
    mr          r3, r28
    b           L_80011C54
L_80011C40:
    lis         r3, 0xCC00
    slwi        r0, r4, 2
    addi        r3, r3, 0x6400
    add         r3, r3, r0
    b           L_80011A78
L_80011C54:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    lwz         r29, 0x14(r1)
    lwz         r28, 0x10(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIInterruptHandler ---- */
#pragma push
#pragma force_active on
asm void SIInterruptHandler(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr        r0
    lis         r5, 0xCC00
    stw         r0, 0x4(r1)
    lis         r7, Packet@ha
    lis         r6, lbl_80123B50@ha
    stwu        r1, -0x48(r1)
    stmw        r21, 0x1c(r1)
    addi        r30, r3, 0x0
    addi        r31, r4, 0x0
    addi        r28, r7, Packet@l
    addi        r29, r6, lbl_80123B50@l
    lwz         r24, 0x6434(r5)
    clrrwi      r5, r24, 30
    addis       r0, r5, 0x4000
    cmplwi      r0, 0x0
    bne         L_80011E34
    lwz         r23, 0x44(r29)
    bl          CompleteTransfer
    lwz         r21, 0x54(r29)
    li          r27, 0x0
    addi        r22, r3, 0x0
    stw         r27, 0x54(r29)
    addi        r26, r23, 0x0
L_80011CD0:
    addi        r26, r26, 0x1
    srawi       r0, r26, 2
    addze       r0, r0
    slwi        r0, r0, 2
    subfc       r0, r0, r26
    mr          r26, r0
    slwi        r0, r0, 5
    add         r25, r28, r0
    lwz         r0, 0x0(r25)
    cmpwi       r0, -0x1
    beq         L_80011D64
    bl          __OSGetSystemTime
    lwz         r0, 0x18(r25)
    xoris       r5, r3, 0x8000
    lwz         r6, 0x1c(r25)
    xoris       r3, r0, 0x8000
    subfc       r0, r6, r4
    subfe       r3, r3, r5
    subfe       r3, r5, r5
    neg.        r3, r3
    bne         L_80011D64
    lwz         r3, 0x0(r25)
    lwz         r4, 0x4(r25)
    lwz         r5, 0x8(r25)
    lwz         r6, 0xc(r25)
    lwz         r7, 0x10(r25)
    lwz         r8, 0x14(r25)
    bl          __SITransfer
    cmpwi       r3, 0x0
    beq         L_80011D70
    mulli       r0, r26, 0x28
    add         r3, r28, r0
    addi        r3, r3, 0x80
    bl          OSCancelAlarm
    li          r0, -0x1
    stw         r0, 0x0(r25)
    b           L_80011D70
L_80011D64:
    addi        r27, r27, 0x1
    cmpwi       r27, 0x4
    blt         L_80011CD0
L_80011D70:
    cmplwi      r21, 0x0
    beq         L_80011D90
    addi        r12, r21, 0x0
    mtlr        r12
    addi        r3, r23, 0x0
    addi        r4, r22, 0x0
    addi        r5, r31, 0x0
    blrl
L_80011D90:
    lis         r3, 0xCC00
    addi        r4, r3, 0x6400
    lwz         r5, 0x6438(r3)
    slwi        r0, r23, 3
    lis         r3, 0xf00
    sraw        r0, r3, r0
    and         r5, r5, r0
    slwi        r0, r23, 2
    stw         r5, 0x38(r4)
    add         r6, r29, r0
    lwzu        r0, 0x58(r6)
    cmplwi      r0, 0x80
    bne         L_80011E34
    slwi        r0, r23, 5
    lwzx        r0, r28, r0
    li          r3, 0x1
    cmpwi       r0, -0x1
    bne         L_80011DE8
    lwz         r0, 0x44(r29)
    cmpw        r0, r23
    beq         L_80011DE8
    li          r3, 0x0
L_80011DE8:
    cmpwi       r3, 0x0
    bne         L_80011E34
    lis         r3, 0x8000
    lwz         r0, 0xf8(r3)
    lis         r3, 0x431c
    lis         r4, GetTypeCallback@ha
    srwi        r0, r0, 2
    subi        r3, r3, 0x217d
    mulhwu      r0, r3, r0
    srwi        r0, r0, 15
    mulli       r0, r0, 0x41
    addi        r8, r4, GetTypeCallback@l
    srwi        r10, r0, 3
    addi        r3, r23, 0x0
    addi        r4, r13, -0x7BB0 /* lbl_801A6810@sda21 */
    li          r5, 0x1
    li          r7, 0x3
    li          r9, 0x0
    bl          SITransfer
L_80011E34:
    rlwinm      r3, r24, 0, 3, 4
    subis       r0, r3, 0x1800
    cmplwi      r0, 0x0
    bne         L_80011FA4
    bl          fn_8001BF84
    lwz         r0, 0x48(r29)
    addi        r23, r28, 0x1e0
    addi        r24, r29, 0x48
    addi        r22, r23, 0x0
    addi        r21, r3, 0x1
    extrwi      r26, r0, 10, 6
    li          r25, 0x0
L_80011E64:
    mr          r3, r25
    bl          SIGetResponseRaw
    cmpwi       r3, 0x0
    beq         L_80011E78
    stw         r21, 0x0(r22)
L_80011E78:
    addi        r25, r25, 0x1
    cmpwi       r25, 0x4
    addi        r22, r22, 0x4
    blt         L_80011E64
    lwz         r5, 0x0(r24)
    lis         r3, 0x8000
    li          r0, 0x18
    srw         r0, r3, r0
    and.        r0, r5, r0
    srwi        r6, r26, 1
    beq         L_80011EC4
    lwz         r0, 0x0(r23)
    cmplwi      r0, 0x0
    beq         L_80011FA4
    lwz         r0, 0x0(r23)
    add         r0, r6, r0
    cmplw       r0, r21
    bge         L_80011EC4
    b           L_80011FA4
L_80011EC4:
    li          r0, 0x19
    srw         r0, r3, r0
    and.        r0, r5, r0
    addi        r4, r23, 0x4
    beq         L_80011EF8
    lwz         r0, 0x0(r4)
    cmplwi      r0, 0x0
    beq         L_80011FA4
    lwz         r0, 0x0(r4)
    add         r0, r6, r0
    cmplw       r0, r21
    bge         L_80011EF8
    b           L_80011FA4
L_80011EF8:
    li          r0, 0x1a
    srw         r0, r3, r0
    and.        r0, r5, r0
    addi        r4, r4, 0x4
    beq         L_80011F2C
    lwz         r0, 0x0(r4)
    cmplwi      r0, 0x0
    beq         L_80011FA4
    lwz         r0, 0x0(r4)
    add         r0, r6, r0
    cmplw       r0, r21
    bge         L_80011F2C
    b           L_80011FA4
L_80011F2C:
    li          r0, 0x1b
    srw         r0, r3, r0
    and.        r0, r5, r0
    addi        r4, r4, 0x4
    beq         L_80011F60
    lwz         r0, 0x0(r4)
    cmplwi      r0, 0x0
    beq         L_80011FA4
    lwz         r0, 0x0(r4)
    add         r0, r6, r0
    cmplw       r0, r21
    bge         L_80011F60
    b           L_80011FA4
L_80011F60:
    li          r22, 0x0
    stw         r22, 0x0(r23)
    addi        r21, r28, 0x1a0
    stw         r22, 0x1e4(r28)
    stw         r22, 0x1e8(r28)
    stw         r22, 0x1ec(r28)
L_80011F78:
    lwz         r12, 0x0(r21)
    cmplwi      r12, 0x0
    beq         L_80011F94
    mtlr        r12
    addi        r3, r30, 0x0
    addi        r4, r31, 0x0
    blrl
L_80011F94:
    addi        r22, r22, 0x1
    cmpwi       r22, 0x4
    addi        r21, r21, 0x4
    blt         L_80011F78
L_80011FA4:
    lmw         r21, 0x1c(r1)
    lwz         r0, 0x4c(r1)
    addi        r1, r1, 0x48
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIEnablePollingInterrupt ---- */
#pragma push
#pragma force_active on
asm BOOL SIEnablePollingInterrupt(register BOOL enable)
{
    nofralloc
    mflr        r0
    lis         r4, Packet@ha
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stw         r31, 0x2c(r1)
    addi        r31, r4, Packet@l
    stw         r30, 0x28(r1)
    stw         r29, 0x24(r1)
    addi        r29, r3, 0x0
    bl          OSDisableInterrupts
    lis         r4, 0xCC00
    lwzu        r5, 0x6434(r4)
    rlwinm.     r0, r5, 0, 4, 4
    beq         L_80011FF8
    li          r30, 0x1
    b           L_80011FFC
L_80011FF8:
    li          r30, 0x0
L_80011FFC:
    cmpwi       r29, 0x0
    beq         L_80012020
    li          r0, 0x0
    stw         r0, 0x1e0(r31)
    oris        r5, r5, 0x800
    stw         r0, 0x1e4(r31)
    stw         r0, 0x1e8(r31)
    stw         r0, 0x1ec(r31)
    b           L_80012024
L_80012020:
    rlwinm      r5, r5, 0, 5, 3
L_80012024:
    rlwinm      r5, r5, 0, 1, 30
    stw         r5, 0x0(r4)
    bl          OSRestoreInterrupts
    mr          r3, r30
    lwz         r0, 0x34(r1)
    lwz         r31, 0x2c(r1)
    lwz         r30, 0x28(r1)
    lwz         r29, 0x24(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIRegisterPollingHandler ---- */
#pragma push
#pragma force_active on
asm BOOL SIRegisterPollingHandler(register void* handler)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    stw         r30, 0x10(r1)
    mr          r30, r3
    bl          OSDisableInterrupts
    lis         r4, lbl_8015CBB0@ha
    li          r0, 0x4
    addi        r4, r4, lbl_8015CBB0@l
    mtctr       r0
    addi        r31, r3, 0x0
    addi        r3, r4, 0x0
L_80012084:
    lwz         r0, 0x0(r3)
    cmplw       r0, r30
    bne         L_800120A0
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r3, 0x1
    b           L_80012104
L_800120A0:
    addi        r3, r3, 0x4
    bdnz        L_80012084
    li          r0, 0x4
    mtctr       r0
    li          r5, 0x0
L_800120B4:
    lwz         r0, 0x0(r4)
    cmplwi      r0, 0x0
    bne         L_800120EC
    lis         r3, lbl_8015CBB0@ha
    slwi        r4, r5, 2
    addi        r0, r3, lbl_8015CBB0@l
    add         r3, r0, r4
    stw         r30, 0x0(r3)
    li          r3, 0x1
    bl          SIEnablePollingInterrupt
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r3, 0x1
    b           L_80012104
L_800120EC:
    addi        r4, r4, 0x4
    addi        r5, r5, 0x1
    bdnz        L_800120B4
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r3, 0x0
L_80012104:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    lwz         r30, 0x10(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIUnregisterPollingHandler ---- */
#pragma push
#pragma force_active on
asm BOOL SIUnregisterPollingHandler(register void* handler)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    stw         r30, 0x10(r1)
    mr          r30, r3
    bl          OSDisableInterrupts
    lis         r4, lbl_8015CBB0@ha
    li          r0, 0x4
    addi        r5, r4, lbl_8015CBB0@l
    mtctr       r0
    addi        r31, r3, 0x0
    addi        r3, r5, 0x0
    li          r4, 0x0
L_80012154:
    lwz         r0, 0x0(r3)
    cmplw       r0, r30
    bne         L_800121E0
    lis         r3, lbl_8015CBB0@ha
    slwi        r4, r4, 2
    addi        r0, r3, lbl_8015CBB0@l
    add         r3, r0, r4
    li          r0, 0x0
    stw         r0, 0x0(r3)
    li          r4, 0x0
    lwz         r0, 0x0(r5)
    cmplwi      r0, 0x0
    bne         L_800121C0
    addi        r3, r5, 0x4
    lwz         r0, 0x4(r5)
    li          r4, 0x1
    cmplwi      r0, 0x0
    bne         L_800121C0
    lwzu        r0, 0x4(r3)
    li          r4, 0x2
    cmplwi      r0, 0x0
    bne         L_800121C0
    lwz         r0, 0x4(r3)
    li          r4, 0x3
    cmplwi      r0, 0x0
    bne         L_800121C0
    li          r4, 0x4
L_800121C0:
    cmpwi       r4, 0x4
    bne         L_800121D0
    li          r3, 0x0
    bl          SIEnablePollingInterrupt
L_800121D0:
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r3, 0x1
    b           L_800121F8
L_800121E0:
    addi        r3, r3, 0x4
    addi        r4, r4, 0x1
    bdnz        L_80012154
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r3, 0x0
L_800121F8:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    lwz         r30, 0x10(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIInit ---- */
#pragma push
#pragma force_active on
asm void SIInit(void)
{
    nofralloc
    mflr        r0
    lis         r4, Packet@ha
    stw         r0, 0x4(r1)
    stwu        r1, -0x10(r1)
    stw         r31, 0xc(r1)
    addi        r31, r4, Packet@l
    lwz         r3, -0x7F78(r13) /* __SIVersion@sda21 */
    bl          OSRegisterVersion
    li          r5, -0x1
    stw         r5, 0x60(r31)
    lis         r3, Si@ha
    addi        r4, r3, Si@l
    stw         r5, 0x40(r31)
    li          r0, 0x0
    li          r3, 0x0
    stw         r5, 0x20(r31)
    stw         r5, 0x0(r31)
    stw         r0, 0x4(r4)
    bl          SISetSamplingRate
    lis         r3, 0xCC00
L_80012260:
    addi        r4, r3, 0x6400
    lwzu        r0, 0x34(r4)
    clrlwi.     r0, r0, 31
    bne         L_80012260
    lis         r0, 0x8000
    lis         r3, SIInterruptHandler@ha
    stw         r0, 0x0(r4)
    addi        r4, r3, SIInterruptHandler@l
    li          r3, 0x14
    bl          __OSSetInterruptHandler
    li          r3, 0x800
    bl          __OSUnmaskInterrupts
    li          r3, 0x0
    bl          SIGetType
    li          r3, 0x1
    bl          SIGetType
    li          r3, 0x2
    bl          SIGetType
    li          r3, 0x3
    bl          SIGetType
    lwz         r0, 0x14(r1)
    lwz         r31, 0xc(r1)
    addi        r1, r1, 0x10
    mtlr        r0
    blr
}
#pragma pop

/* ---- __SITransfer ---- */
#pragma push
#pragma force_active on
asm int __SITransfer(register s32 chan, register void* output,
                     register s32 outputBytes, register void* input,
                     register s32 inputBytes,
                     register void (*callback)(s32, u32, OSContext*))
{
    nofralloc
    mflr        r0
    lis         r9, lbl_80123B50@ha
    stw         r0, 0x4(r1)
    stwu        r1, -0x48(r1)
    stmw        r25, 0x2c(r1)
    addi        r26, r3, 0x0
    addi        r27, r4, 0x0
    addi        r28, r5, 0x0
    addi        r29, r6, 0x0
    addi        r30, r7, 0x0
    addi        r31, r8, 0x0
    addi        r25, r9, lbl_80123B50@l
    bl          OSDisableInterrupts
    lwz         r0, 0x44(r25)
    cmpwi       r0, -0x1
    beq         L_80012310
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_800124BC
L_80012310:
    lis         r6, 0xCC00
    slwi        r0, r26, 3
    lwz         r7, 0x6438(r6)
    lis         r4, 0xf00
    sraw        r0, r4, r0
    and         r7, r7, r0
    stw         r7, 0x6438(r6)
    addi        r0, r28, 0x3
    srwi        r4, r0, 2
    stw         r26, 0x44(r25)
    cmplwi      r4, 0x0
    li          r5, 0x0
    stw         r31, 0x54(r25)
    stw         r30, 0x4c(r25)
    stw         r29, 0x50(r25)
    ble         L_800123F0
    cmplwi      r4, 0x8
    subi        r7, r4, 0x8
    ble         L_800124A4
    addi        r0, r7, 0x7
    srwi        r0, r0, 3
    cmplwi      r7, 0x0
    mtctr       r0
    addi        r7, r27, 0x0
    addi        r6, r6, 0x6400
    ble         L_800124A4
L_80012378:
    lwz         r0, 0x0(r7)
    addi        r5, r5, 0x8
    stw         r0, 0x80(r6)
    lwz         r0, 0x4(r7)
    stw         r0, 0x84(r6)
    lwz         r0, 0x8(r7)
    stw         r0, 0x88(r6)
    lwz         r0, 0xc(r7)
    stw         r0, 0x8c(r6)
    lwz         r0, 0x10(r7)
    stw         r0, 0x90(r6)
    lwz         r0, 0x14(r7)
    stw         r0, 0x94(r6)
    lwz         r0, 0x18(r7)
    stw         r0, 0x98(r6)
    lwz         r0, 0x1c(r7)
    addi        r7, r7, 0x20
    stw         r0, 0x9c(r6)
    addi        r6, r6, 0x20
    bdnz        L_80012378
    b           L_800124A4
L_800123CC:
    subf        r0, r5, r4
    cmplw       r5, r4
    mtctr       r0
    bge         L_800123F0
L_800123DC:
    lwz         r0, 0x0(r6)
    addi        r6, r6, 0x4
    stw         r0, 0x80(r7)
    addi        r7, r7, 0x4
    bdnz        L_800123DC
L_800123F0:
    lis         r4, 0xCC00
    addi        r6, r4, 0x6400
    lwzu        r0, 0x34(r6)
    li          r4, 0x1
    stw         r0, 0x24(r1)
    cmplwi      r31, 0x0
    lbz         r0, 0x24(r1)
    rlwimi      r0, r4, 7, 24, 24
    stb         r0, 0x24(r1)
    beq         L_8001241C
    b           L_80012420
L_8001241C:
    li          r4, 0x0
L_80012420:
    lbz         r0, 0x24(r1)
    rlwimi      r0, r4, 6, 25, 25
    cmplwi      r28, 0x80
    stb         r0, 0x24(r1)
    bne         L_8001243C
    li          r0, 0x0
    b           L_80012440
L_8001243C:
    mr          r0, r28
L_80012440:
    clrlwi      r4, r0, 24
    lbz         r0, 0x25(r1)
    rlwimi      r0, r4, 0, 25, 31
    cmplwi      r30, 0x80
    stb         r0, 0x25(r1)
    bne         L_80012460
    li          r0, 0x0
    b           L_80012464
L_80012460:
    mr          r0, r30
L_80012464:
    clrlwi      r4, r0, 24
    lbz         r0, 0x26(r1)
    rlwimi      r0, r4, 0, 25, 31
    stb         r0, 0x26(r1)
    li          r4, 0x1
    lbz         r0, 0x27(r1)
    rlwimi      r0, r26, 1, 29, 30
    stb         r0, 0x27(r1)
    lbz         r0, 0x27(r1)
    rlwimi      r0, r4, 0, 31, 31
    stb         r0, 0x27(r1)
    lwz         r0, 0x24(r1)
    stw         r0, 0x0(r6)
    bl          OSRestoreInterrupts
    li          r3, 0x1
    b           L_800124BC
L_800124A4:
    lis         r6, 0xCC00
    slwi        r0, r5, 2
    addi        r7, r6, 0x6400
    add         r6, r27, r0
    add         r7, r7, r0
    b           L_800123CC
L_800124BC:
    lmw         r25, 0x2c(r1)
    lwz         r0, 0x4c(r1)
    addi        r1, r1, 0x48
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIGetStatus ---- */
#pragma push
#pragma force_active on
asm u32 SIGetStatus(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    stw         r30, 0x10(r1)
    mr          r30, r3
    bl          OSDisableInterrupts
    lis         r4, 0xCC00
    subfic      r0, r30, 0x3
    lwz         r31, 0x6438(r4)
    slwi        r0, r0, 3
    srw         r31, r31, r0
    rlwinm.     r0, r31, 0, 28, 28
    beq         L_8001252C
    lis         r4, Type@ha
    slwi        r5, r30, 2
    addi        r0, r4, Type@l
    add         r4, r0, r5
    lwz         r0, 0x0(r4)
    rlwinm.     r0, r0, 0, 24, 24
    bne         L_8001252C
    li          r0, 0x8
    stw         r0, 0x0(r4)
L_8001252C:
    bl          OSRestoreInterrupts
    mr          r3, r31
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    lwz         r30, 0x10(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- SISetCommand ---- */
#pragma push
#pragma force_active on
asm void SISetCommand(register s32 chan, register u32 command)
{
    nofralloc
    mulli       r0, r3, 0xc
    lis         r3, 0xCC00
    addi        r3, r3, 0x6400
    stwx        r4, r3, r0
    blr
}
#pragma pop

/* ---- SITransferCommands ---- */
#pragma push
#pragma force_active on
asm void SITransferCommands(void)
{
    nofralloc
    lis         r3, 0xCC00
    lis         r0, 0x8000
    stw         r0, 0x6438(r3)
    blr
}
#pragma pop

/* ---- SISetXY ---- */
#pragma push
#pragma force_active on
asm u32 SISetXY(register u32 x, register u32 y)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    slwi        r0, y, 8
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    slwi        r31, x, 16
    or          r31, r31, r0
    bl          OSDisableInterrupts
    lis         r4, Si@ha
    addi        r4, r4, Si@l
    lwz         r0, 0x4(r4)
    addi        r5, r4, 0x4
    lis         r4, 0xCC00
    rlwinm      r0, r0, 0, 24, 5
    stw         r0, 0x0(r5)
    lwz         r0, 0x0(r5)
    or          r0, r0, r31
    stw         r0, 0x0(r5)
    lwz         r31, 0x0(r5)
    stw         r31, 0x6430(r4)
    bl          OSRestoreInterrupts
    mr          r3, r31
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIGetWirelessID ---- */
#pragma push
#pragma force_active on
asm void SIGetWirelessID(register s32 chan, register u32 unk)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    mr.         r31, r3
    bne         L_80012604
    lis         r3, Si@ha
    addi        r3, r3, Si@l
    lwz         r3, 0x4(r3)
    b           L_80012664
L_80012604:
    bl          OSDisableInterrupts
    lis         r4, Si@ha
    addi        r4, r4, Si@l
    srwi        r31, r31, 24
    lwz         r0, 0x4(r4)
    addi        r5, r4, 0x4
    extrwi      r4, r31, 4, 24
    andc        r0, r0, r4
    stw         r0, 0x0(r5)
    oris        r0, r4, 0x3ff
    ori         r0, r0, 0xfff0
    and         r31, r31, r0
    lwz         r0, 0x0(r5)
    rlwinm      r31, r31, 0, 24, 5
    or          r0, r0, r31
    stw         r0, 0x0(r5)
    lis         r4, 0xCC00
    addi        r4, r4, 0x6400
    lwz         r31, 0x0(r5)
    lis         r0, 0x8000
    stw         r0, 0x38(r4)
    stw         r31, 0x30(r4)
    bl          OSRestoreInterrupts
    mr          r3, r31
L_80012664:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIGetWirelessIDBitfield ---- */
#pragma push
#pragma force_active on
asm void SIGetWirelessIDBitfield(register s32 chan, register u32 unk)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    mr.         r31, r3
    bne         L_800126A0
    lis         r3, Si@ha
    addi        r3, r3, Si@l
    lwz         r3, 0x4(r3)
    b           L_800126D0
L_800126A0:
    bl          OSDisableInterrupts
    lis         r4, Si@ha
    addi        r4, r4, Si@l
    lwz         r0, 0x4(r4)
    rlwinm      r31, r31, 8, 24, 27
    addi        r5, r4, 0x4
    lis         r4, 0xCC00
    andc        r31, r0, r31
    stw         r31, 0x6430(r4)
    stw         r31, 0x0(r5)
    bl          OSRestoreInterrupts
    mr          r3, r31
L_800126D0:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIGetResponseRaw ---- */
#pragma push
#pragma force_active on
asm u32 SIGetResponseRaw(register s32 chan)
{
    nofralloc
    mflr        r0
    lis         r4, Packet@ha
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stw         r31, 0x24(r1)
    addi        r31, r4, Packet@l
    stw         r30, 0x20(r1)
    addi        r30, r3, 0x0
    stw         r29, 0x1c(r1)
    bl          OSDisableInterrupts
    lis         r4, 0xCC00
    subfic      r0, r30, 0x3
    lwz         r29, 0x6438(r4)
    slwi        r0, r0, 3
    srw         r29, r29, r0
    rlwinm.     r0, r29, 0, 28, 28
    beq         L_8001274C
    lis         r4, Type@ha
    slwi        r5, r30, 2
    addi        r0, r4, Type@l
    add         r4, r0, r5
    lwz         r0, 0x0(r4)
    rlwinm.     r0, r0, 0, 24, 24
    bne         L_8001274C
    li          r0, 0x8
    stw         r0, 0x0(r4)
L_8001274C:
    bl          OSRestoreInterrupts
    rlwinm.     r0, r29, 0, 26, 26
    beq         L_80012798
    mulli       r4, r30, 0xc
    lis         r3, 0xCC00
    addi        r0, r3, 0x6400
    add         r3, r0, r4
    slwi        r4, r30, 3
    lwz         r0, 0x4(r3)
    add         r6, r31, r4
    stw         r0, 0x1c0(r6)
    slwi        r0, r30, 2
    add         r4, r31, r0
    lwz         r5, 0x8(r3)
    li          r0, 0x1
    li          r3, 0x1
    stw         r5, 0x1c4(r6)
    stw         r0, 0x1b0(r4)
    b           L_8001279C
L_80012798:
    li          r3, 0x0
L_8001279C:
    lwz         r0, 0x2c(r1)
    lwz         r31, 0x24(r1)
    lwz         r30, 0x20(r1)
    lwz         r29, 0x1c(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIGetResponse ---- */
#pragma push
#pragma force_active on
asm u32 SIGetResponse(register s32 chan, register void* data)
{
    nofralloc
    mflr        r0
    lis         r5, Packet@ha
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stmw        r27, 0x14(r1)
    addi        r29, r3, 0x0
    addi        r30, r4, 0x0
    addi        r28, r5, Packet@l
    bl          OSDisableInterrupts
    addi        r31, r3, 0x0
    addi        r3, r29, 0x0
    bl          SIGetStatus
    rlwinm.     r0, r3, 0, 26, 26
    beq         L_80012828
    mulli       r4, r29, 0xc
    lis         r3, 0xCC00
    addi        r0, r3, 0x6400
    add         r4, r0, r4
    slwi        r3, r29, 3
    lwz         r0, 0x4(r4)
    add         r5, r28, r3
    stw         r0, 0x1c0(r5)
    slwi        r0, r29, 2
    add         r3, r28, r0
    lwz         r4, 0x8(r4)
    li          r0, 0x1
    stw         r4, 0x1c4(r5)
    stw         r0, 0x1b0(r3)
L_80012828:
    slwi        r0, r29, 2
    add         r3, r28, r0
    lwz         r27, 0x1b0(r3)
    li          r0, 0x0
    cmpwi       r27, 0x0
    stw         r0, 0x1b0(r3)
    beq         L_8001285C
    slwi        r0, r29, 3
    add         r3, r28, r0
    lwz         r0, 0x1c0(r3)
    stw         r0, 0x0(r30)
    lwz         r0, 0x1c4(r3)
    stw         r0, 0x4(r30)
L_8001285C:
    mr          r3, r31
    bl          OSRestoreInterrupts
    mr          r3, r27
    lmw         r27, 0x14(r1)
    lwz         r0, 0x2c(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop

/* ---- AlarmHandler ---- */
#pragma push
#pragma force_active on
asm void fn_8001287C(register void* alarm, register OSContext* context)
{
    nofralloc
    mflr        r0
    lis         r4, lbl_8015CA90@ha
    stw         r0, 0x4(r1)
    addi        r0, r4, lbl_8015CA90@l
    lis         r4, 0x6666
    subf        r0, r0, r3
    stwu        r1, -0x20(r1)
    addi        r3, r4, 0x6667
    mulhw       r0, r3, r0
    stw         r31, 0x1c(r1)
    srawi       r0, r0, 4
    srwi        r3, r0, 31
    add         r0, r0, r3
    lis         r3, Packet@ha
    slwi        r4, r0, 5
    addi        r0, r3, Packet@l
    add         r31, r0, r4
    lwz         r3, 0x0(r31)
    cmpwi       r3, -0x1
    beq         L_800128F4
    lwz         r4, 0x4(r31)
    lwz         r5, 0x8(r31)
    lwz         r6, 0xc(r31)
    lwz         r7, 0x10(r31)
    lwz         r8, 0x14(r31)
    bl          __SITransfer
    cmpwi       r3, 0x0
    beq         L_800128F4
    li          r0, -0x1
    stw         r0, 0x0(r31)
L_800128F4:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- SITransfer ---- */
#pragma push
#pragma force_active on
asm int SITransfer(register s32 chan, register void* output,
                   register s32 outputBytes, register void* input,
                   register s32 inputBytes,
                   register void (*callback)(s32, u32, OSContext*),
                   register u32 delayHi, register u32 delayLo)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x60(r1)
    stmw        r19, 0x2c(r1)
    addi        r24, r3, 0x0
    lis         r3, Packet@ha
    addi        r23, r3, Packet@l
    slwi        r0, r24, 5
    addi        r25, r4, 0x0
    addi        r26, r5, 0x0
    addi        r27, r6, 0x0
    addi        r28, r7, 0x0
    addi        r29, r8, 0x0
    addi        r31, r9, 0x0
    addi        r30, r10, 0x0
    add         r22, r23, r0
    bl          OSDisableInterrupts
    lwz         r0, 0x0(r22)
    addi        r21, r3, 0x0
    cmpwi       r0, -0x1
    bne         L_8001296C
    lis         r3, Si@ha
    lwz         r0, Si@l(r3)
    cmpw        r0, r24
    bne         L_8001297C
L_8001296C:
    mr          r3, r21
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80012A60
L_8001297C:
    bl          __OSGetSystemTime
    li          r0, 0x0
    xor         r5, r30, r0
    xor         r0, r31, r0
    or.         r0, r5, r0
    bne         L_800129A0
    addi        r19, r4, 0x0
    addi        r20, r3, 0x0
    b           L_800129B8
L_800129A0:
    slwi        r0, r24, 3
    add         r6, r23, r0
    lwz         r5, 0x144(r6)
    lwz         r0, 0x140(r6)
    addc        r19, r30, r5
    adde        r20, r31, r0
L_800129B8:
    xoris       r6, r3, 0x8000
    xoris       r5, r20, 0x8000
    subfc       r0, r19, r4
    subfe       r5, r5, r6
    subfe       r5, r6, r6
    neg.        r5, r5
    beq         L_80012A00
    mulli       r0, r24, 0x28
    subfc       r30, r4, r19
    subfe       r31, r3, r20
    lis         r4, fn_8001287C@ha
    add         r3, r23, r0
    addi        r7, r4, fn_8001287C@l
    addi        r6, r30, 0x0
    addi        r5, r31, 0x0
    addi        r3, r3, 0x80
    bl          OSSetAlarm
    b           L_80012A34
L_80012A00:
    addi        r3, r24, 0x0
    addi        r4, r25, 0x0
    addi        r5, r26, 0x0
    addi        r6, r27, 0x0
    addi        r7, r28, 0x0
    addi        r8, r29, 0x0
    bl          __SITransfer
    cmpwi       r3, 0x0
    beq         L_80012A34
    mr          r3, r21
    bl          OSRestoreInterrupts
    li          r3, 0x1
    b           L_80012A60
L_80012A34:
    stw         r24, 0x0(r22)
    mr          r3, r21
    stw         r25, 0x4(r22)
    stw         r26, 0x8(r22)
    stw         r27, 0xc(r22)
    stw         r28, 0x10(r22)
    stw         r29, 0x14(r22)
    stw         r19, 0x1c(r22)
    stw         r20, 0x18(r22)
    bl          OSRestoreInterrupts
    li          r3, 0x1
L_80012A60:
    lmw         r19, 0x2c(r1)
    lwz         r0, 0x64(r1)
    addi        r1, r1, 0x60
    mtlr        r0
    blr
}
#pragma pop

/* ---- GetTypeCallback ---- */
#pragma push
#pragma force_active on
asm void GetTypeCallback(register s32 chan, register u32 status,
                         register OSContext* context)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stmw        r26, 0x18(r1)
    addi        r27, r3, 0x0
    lis         r3, Type@ha
    addi        r0, r3, Type@l
    slwi        r29, r27, 2
    add         r30, r0, r29
    lis         r3, Packet@ha
    addi        r26, r4, 0x0
    addi        r31, r3, Packet@l
    lwz         r0, 0x0(r30)
    rlwinm      r0, r0, 0, 25, 23
    stw         r0, 0x0(r30)
    lwz         r0, 0x0(r30)
    or          r0, r0, r26
    stw         r0, 0x0(r30)
    bl          __OSGetSystemTime
    slwi        r0, r27, 3
    add         r5, r31, r0
    stw         r4, 0x124(r5)
    lis         r4, 0x8000
    clrlwi.     r0, r26, 28
    stw         r3, 0x120(r5)
    srw         r4, r4, r27
    lwz         r3, -0x7BA8(r13) /* lbl_801A6818@sda21 */
    lwz         r28, 0x0(r30)
    andc        r0, r3, r4
    stw         r0, -0x7BA8(r13) /* lbl_801A6818@sda21 */
    and         r26, r3, r4
    bne         L_80012B14
    rlwinm      r3, r28, 0, 3, 4
    subis       r0, r3, 0x800
    cmplwi      r0, 0x0
    bne         L_80012B14
    clrrwi.     r0, r28, 31
    beq         L_80012B14
    rlwinm.     r0, r28, 0, 5, 5
    beq         L_80012B6C
L_80012B14:
    addi        r3, r27, 0x0
    li          r4, 0x0
    bl          OSSetWirelessID
    slwi        r0, r27, 4
    lwz         r30, 0x0(r30)
    add         r31, r31, r0
    li          r29, 0x0
    addi        r28, r29, 0x0
    addi        r31, r31, 0x160
L_80012B38:
    lwz         r12, 0x0(r31)
    cmplwi      r12, 0x0
    beq         L_80012B58
    stw         r28, 0x0(r31)
    mtlr        r12
    addi        r3, r27, 0x0
    addi        r4, r30, 0x0
    blrl
L_80012B58:
    addi        r29, r29, 0x1
    cmpwi       r29, 0x4
    addi        r31, r31, 0x4
    blt         L_80012B38
    b           L_80012CF8
L_80012B6C:
    mr          r3, r27
    bl          OSGetWirelessID
    cmpwi       r26, 0x0
    clrlslwi    r26, r3, 16, 8
    beq         L_80012BD0
    rlwinm.     r0, r26, 0, 11, 11
    beq         L_80012BD0
    lis         r3, 0xd0
    subi        r0, r3, 0x100
    and         r0, r26, r0
    oris        r0, r0, 0x4e10
    add         r4, r31, r29
    stwu        r0, 0x1f0(r4)
    li          r0, 0x80
    lis         r3, GetTypeCallback@ha
    stw         r0, 0x0(r30)
    addi        r8, r3, GetTypeCallback@l
    addi        r3, r27, 0x0
    addi        r6, r30, 0x0
    li          r5, 0x3
    li          r7, 0x3
    li          r10, 0x0
    li          r9, 0x0
    bl          SITransfer
    b           L_80012CF8
L_80012BD0:
    rlwinm.     r0, r28, 0, 11, 11
    beq         L_80012C44
    lis         r3, 0xd0
    subi        r3, r3, 0x100
    and         r0, r26, r3
    and         r3, r28, r3
    cmplw       r0, r3
    beq         L_80012CB0
    rlwinm.     r0, r26, 0, 11, 11
    bne         L_80012C08
    oris        r26, r3, 0x10
    addi        r3, r27, 0x0
    extrwi      r4, r26, 16, 8
    bl          OSSetWirelessID
L_80012C08:
    oris        r0, r26, 0x4e00
    add         r4, r31, r29
    stwu        r0, 0x1f0(r4)
    li          r0, 0x80
    lis         r3, GetTypeCallback@ha
    stw         r0, 0x0(r30)
    addi        r8, r3, GetTypeCallback@l
    addi        r3, r27, 0x0
    addi        r6, r30, 0x0
    li          r5, 0x3
    li          r7, 0x3
    li          r10, 0x0
    li          r9, 0x0
    bl          SITransfer
    b           L_80012CF8
L_80012C44:
    rlwinm.     r0, r28, 0, 1, 1
    beq         L_80012CA4
    lis         r3, 0xd0
    subi        r0, r3, 0x100
    and         r28, r28, r0
    oris        r28, r28, 0x10
    addi        r3, r27, 0x0
    extrwi      r4, r28, 16, 8
    bl          OSSetWirelessID
    oris        r0, r28, 0x4e00
    add         r4, r31, r29
    stwu        r0, 0x1f0(r4)
    li          r0, 0x80
    lis         r3, GetTypeCallback@ha
    stw         r0, 0x0(r30)
    addi        r8, r3, GetTypeCallback@l
    addi        r3, r27, 0x0
    addi        r6, r30, 0x0
    li          r5, 0x3
    li          r7, 0x3
    li          r10, 0x0
    li          r9, 0x0
    bl          SITransfer
    b           L_80012CF8
L_80012CA4:
    addi        r3, r27, 0x0
    li          r4, 0x0
    bl          OSSetWirelessID
L_80012CB0:
    slwi        r0, r27, 4
    lwz         r30, 0x0(r30)
    add         r31, r31, r0
    li          r29, 0x0
    addi        r28, r29, 0x0
    addi        r31, r31, 0x160
L_80012CC8:
    lwz         r12, 0x0(r31)
    cmplwi      r12, 0x0
    beq         L_80012CE8
    stw         r28, 0x0(r31)
    mtlr        r12
    addi        r3, r27, 0x0
    addi        r4, r30, 0x0
    blrl
L_80012CE8:
    addi        r29, r29, 0x1
    cmpwi       r29, 0x4
    addi        r31, r31, 0x4
    blt         L_80012CC8
L_80012CF8:
    lmw         r26, 0x18(r1)
    lwz         r0, 0x34(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIGetType ---- */
#pragma push
#pragma force_active on
asm u32 SIGetType(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stmw        r27, 0x14(r1)
    mr          r27, r3
    bl          OSDisableInterrupts
    lis         r4, Type@ha
    slwi        r5, r27, 2
    addi        r0, r4, Type@l
    add         r30, r0, r5
    lwz         r28, 0x0(r30)
    mr          r29, r3
    bl          __OSGetSystemTime
    lis         r5, TypeTime@ha
    slwi        r6, r27, 3
    addi        r0, r5, TypeTime@l
    add         r31, r0, r6
    lwz         r6, 0x4(r31)
    lis         r5, Si@ha
    addi        r5, r5, Si@l
    lwz         r0, 0x0(r31)
    subfc       r4, r6, r4
    subfe       r0, r0, r3
    lwz         r6, 0x4(r5)
    li          r5, 0x80
    sraw        r3, r5, r27
    and.        r3, r6, r3
    beq         L_80012DAC
    cmplwi      r28, 0x8
    beq         L_80012DA0
    bl          __OSGetSystemTime
    stw         r4, 0x4(r31)
    stw         r3, 0x0(r31)
    mr          r3, r29
    bl          OSRestoreInterrupts
    mr          r3, r28
    b           L_80012EBC
L_80012DA0:
    stw         r5, 0x0(r30)
    li          r28, 0x80
    b           L_80012E5C
L_80012DAC:
    lis         r3, 0x8000
    lwz         r6, 0xf8(r3)
    lis         r5, 0x1062
    addi        r5, r5, 0x4dd3
    srwi        r6, r6, 2
    mulhwu      r5, r5, r6
    srwi        r5, r5, 6
    mulli       r7, r5, 0x32
    li          r3, 0x0
    xoris       r6, r3, 0x8000
    xoris       r5, r0, 0x8000
    subfc       r3, r4, r7
    subfe       r5, r5, r6
    subfe       r5, r6, r6
    neg.        r5, r5
    bne         L_80012E04
    cmplwi      r28, 0x8
    beq         L_80012E04
    mr          r3, r29
    bl          OSRestoreInterrupts
    mr          r3, r28
    b           L_80012EBC
L_80012E04:
    lis         r3, 0x8000
    lwz         r6, 0xf8(r3)
    lis         r5, 0x1062
    addi        r5, r5, 0x4dd3
    srwi        r6, r6, 2
    mulhwu      r5, r5, r6
    srwi        r5, r5, 6
    mulli       r6, r5, 0x4b
    li          r3, 0x0
    xoris       r5, r3, 0x8000
    xoris       r3, r0, 0x8000
    subfc       r0, r4, r6
    subfe       r3, r3, r5
    subfe       r3, r5, r5
    neg.        r3, r3
    bne         L_80012E50
    li          r0, 0x80
    stw         r0, 0x0(r30)
    b           L_80012E5C
L_80012E50:
    li          r0, 0x80
    stw         r0, 0x0(r30)
    li          r28, 0x80
L_80012E5C:
    bl          __OSGetSystemTime
    stw         r4, 0x4(r31)
    lis         r4, 0x431c
    lis         r5, GetTypeCallback@ha
    stw         r3, 0x0(r31)
    lis         r3, 0x8000
    addi        r8, r5, GetTypeCallback@l
    lwz         r0, 0xf8(r3)
    subi        r4, r4, 0x217d
    addi        r3, r27, 0x0
    srwi        r0, r0, 2
    mulhwu      r0, r4, r0
    srwi        r0, r0, 15
    mulli       r0, r0, 0x41
    srwi        r10, r0, 3
    addi        r6, r30, 0x0
    addi        r4, r13, -0x7BAC /* cmdTypeAndStatus$371@sda21 */
    li          r5, 0x1
    li          r7, 0x3
    li          r9, 0x0
    bl          SITransfer
    mr          r3, r29
    bl          OSRestoreInterrupts
    mr          r3, r28
L_80012EBC:
    lmw         r27, 0x14(r1)
    lwz         r0, 0x2c(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop

/* ---- SIGetTypeAsync ---- */
#pragma push
#pragma force_active on
asm u32 SIGetTypeAsync(register s32 chan,
                       register void (*callback)(s32, u32))
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    addi        r31, r4, 0x0
    stw         r30, 0x18(r1)
    stw         r29, 0x14(r1)
    stw         r28, 0x10(r1)
    addi        r28, r3, 0x0
    bl          OSDisableInterrupts
    addi        r30, r3, 0x0
    addi        r3, r28, 0x0
    bl          SIGetType
    lis         r4, Type@ha
    slwi        r5, r28, 2
    addi        r0, r4, Type@l
    add         r4, r0, r5
    lwz         r0, 0x0(r4)
    addi        r29, r3, 0x0
    rlwinm.     r0, r0, 0, 24, 24
    beq         L_80012FCC
    lis         r3, lbl_8015CB70@ha
    slwi        r4, r28, 4
    addi        r0, r3, lbl_8015CB70@l
    add         r4, r0, r4
    lwz         r0, 0x0(r4)
    li          r5, 0x0
    cmplw       r0, r31
    beq         L_80012FE0
    cmplwi      r0, 0x0
    bne         L_80012F58
    slwi        r0, r5, 2
    stwx        r31, r4, r0
    b           L_80012FE0
L_80012F58:
    addi        r3, r4, 0x4
    lwz         r0, 0x4(r4)
    li          r5, 0x1
    cmplw       r0, r31
    beq         L_80012FE0
    cmplwi      r0, 0x0
    bne         L_80012F80
    slwi        r0, r5, 2
    stwx        r31, r4, r0
    b           L_80012FE0
L_80012F80:
    lwzu        r0, 0x4(r3)
    li          r5, 0x2
    cmplw       r0, r31
    beq         L_80012FE0
    cmplwi      r0, 0x0
    bne         L_80012FA4
    slwi        r0, r5, 2
    stwx        r31, r4, r0
    b           L_80012FE0
L_80012FA4:
    lwz         r0, 0x4(r3)
    li          r5, 0x3
    cmplw       r0, r31
    beq         L_80012FE0
    cmplwi      r0, 0x0
    bne         L_80012FE0
    slwi        r0, r5, 2
    stwx        r31, r4, r0
    b           L_80012FE0
    b           L_80012FE0
L_80012FCC:
    addi        r12, r31, 0x0
    mtlr        r12
    addi        r3, r28, 0x0
    addi        r4, r29, 0x0
    blrl
L_80012FE0:
    mr          r3, r30
    bl          OSRestoreInterrupts
    mr          r3, r29
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    lwz         r29, 0x14(r1)
    lwz         r28, 0x10(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_8001300C: map raw type to device code ---- */
#pragma push
#pragma force_active on
asm u32 fn_8001300C(register u32 type)
{
    nofralloc
    rlwinm.     r0, r3, 0, 28, 28
    clrlwi      r4, r3, 24
    clrrwi      r5, r3, 8
    beq         L_80013024
    li          r3, 0x8
    blr
L_80013024:
    andi.       r0, r4, 0x47
    beq         L_80013034
    li          r3, 0x40
    blr
L_80013034:
    cmplwi      r4, 0x0
    beq         L_80013044
    li          r3, 0x80
    blr
L_80013044:
    rlwinm.     r3, r5, 0, 3, 4
    bne         L_800130AC
    clrrwi      r3, r5, 16
    lis         r0, 0x4
    cmpw        r3, r0
    beqlr
    bge         L_80013080
    lis         r0, 0x2
    cmpw        r3, r0
    beqlr
    bge         L_800130A4
    lis         r0, 0x1
    cmpw        r3, r0
    beqlr
    b           L_800130A4
L_80013080:
    lis         r0, 0x500
    cmpw        r3, r0
    beqlr
    bge         L_800130A4
    lis         r0, 0x200
    cmpw        r3, r0
    beqlr
    b           L_800130A4
    blr
L_800130A4:
    li          r3, 0x40
    blr
L_800130AC:
    subis       r0, r3, 0x800
    cmplwi      r0, 0x0
    beq         L_800130C0
    li          r3, 0x40
    blr
L_800130C0:
    clrrwi      r3, r5, 16
    lis         r0, 0x900
    cmpw        r3, r0
    beqlr
    bge         L_800130E8
    lis         r0, 0x800
    cmpw        r3, r0
    beqlr
    b           L_800130E8
    blr
L_800130E8:
    clrrwi      r3, r5, 21
    subis       r0, r3, 0x820
    cmplwi      r0, 0x0
    bne         L_80013100
    lis         r3, 0x820
    blr
L_80013100:
    clrrwi.     r0, r5, 31
    beq         L_80013138
    rlwinm.     r0, r5, 0, 5, 5
    bne         L_80013138
    andis.      r3, r5, 0x8b10
    addis       r0, r3, 0x74f0
    cmplwi      r0, 0x0
    bne         L_80013128
    lis         r3, 0x8b10
    blr
L_80013128:
    rlwinm.     r0, r5, 0, 6, 6
    bne         L_80013138
    lis         r3, 0x8800
    blr
L_80013138:
    andis.      r3, r5, 0x900
    subis       r0, r3, 0x900
    cmplwi      r0, 0x0
    bne         L_80013150
    lis         r3, 0x900
    blr
L_80013150:
    li          r3, 0x40
    blr
}
#pragma pop

/* ---- fn_80013158 ---- */
#pragma push
#pragma force_active on
asm u32 fn_80013158(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x8(r1)
    bl          SIGetType
    bl          fn_8001300C
    lwz         r0, 0xc(r1)
    addi        r1, r1, 0x8
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_8001317C: device name lookup ---- */
#pragma push
#pragma force_active on
asm char* fn_8001317C(register s32 chan)
{
    nofralloc
    mflr        r0
    lis         r4, lbl_80123B50@ha
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    addi        r31, r4, lbl_80123B50@l
    bl          fn_8001300C
    lis         r0, 0x2
    cmpw        r3, r0
    beq         L_8001327C
    bge         L_800131FC
    cmpwi       r3, 0x40
    beq         L_800132BC
    bge         L_800131E0
    lis         r0, 0x8b10
    cmpw        r3, r0
    beq         L_800132A4
    bge         L_800131D4
    lis         r0, 0x8800
    cmpw        r3, r0
    beq         L_8001329C
    b           L_800132BC
L_800131D4:
    cmpwi       r3, 0x8
    beq         L_8001325C
    b           L_800132BC
L_800131E0:
    lis         r0, 0x1
    cmpw        r3, r0
    beq         L_80013274
    bge         L_800132BC
    cmpwi       r3, 0x80
    beq         L_80013264
    b           L_800132BC
L_800131FC:
    lis         r0, 0x800
    cmpw        r3, r0
    beq         L_800132B4
    bge         L_8001323C
    lis         r0, 0x200
    cmpw        r3, r0
    beq         L_80013284
    bge         L_8001322C
    lis         r0, 0x4
    cmpw        r3, r0
    beq         L_8001328C
    b           L_800132BC
L_8001322C:
    lis         r0, 0x500
    cmpw        r3, r0
    beq         L_8001326C
    b           L_800132BC
L_8001323C:
    lis         r0, 0x900
    cmpw        r3, r0
    beq         L_80013294
    bge         L_800132BC
    lis         r0, 0x820
    cmpw        r3, r0
    beq         L_800132AC
    b           L_800132BC
L_8001325C:
    addi        r3, r31, 0x68
    b           L_800132C0
L_80013264:
    addi        r3, r13, -0x7F74 /* lbl_801A644C@sda21 */
    b           L_800132C0
L_8001326C:
    addi        r3, r31, 0x74
    b           L_800132C0
L_80013274:
    addi        r3, r31, 0x84
    b           L_800132C0
L_8001327C:
    addi        r3, r31, 0x94
    b           L_800132C0
L_80013284:
    addi        r3, r31, 0xa4
    b           L_800132C0
L_8001328C:
    addi        r3, r31, 0xb0
    b           L_800132C0
L_80013294:
    addi        r3, r31, 0xc0
    b           L_800132C0
L_8001329C:
    addi        r3, r31, 0xd4
    b           L_800132C0
L_800132A4:
    addi        r3, r31, 0xe8
    b           L_800132C0
L_800132AC:
    addi        r3, r31, 0xfc
    b           L_800132C0
L_800132B4:
    addi        r3, r31, 0x108
    b           L_800132C0
L_800132BC:
    addi        r3, r13, -0x7F6C /* lbl_801A6454@sda21 */
L_800132C0:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- SISetSamplingRate ---- */
#pragma push
#pragma force_active on
asm void SISetSamplingRate(register s32 msec)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    stw         r30, 0x18(r1)
    stw         r29, 0x14(r1)
    addi        r29, r3, 0x0
    cmplwi      r29, 0xb
    lis         r3, XYNTSC@ha
    addi        r31, r3, XYNTSC@l
    ble         L_80013304
    li          r29, 0xb
L_80013304:
    bl          OSDisableInterrupts
    stw         r29, -0x7BA0(r13) /* SamplingRate@sda21 */
    mr          r30, r3
    bl          VIGetTvFormat
    cmpwi       r3, 0x2
    beq         L_8001333C
    bge         L_80013330
    cmpwi       r3, 0x0
    beq         L_8001333C
    bge         L_80013344
    b           L_8001334C
L_80013330:
    cmpwi       r3, 0x5
    beq         L_8001333C
    b           L_8001334C
L_8001333C:
    mr          r4, r31
    b           L_80013360
L_80013344:
    addi        r4, r31, 0x30
    b           L_80013360
L_8001334C:
    addi        r3, r31, 0x60
    crclr       6
    bl          OSReport
    li          r29, 0x0
    addi        r4, r31, 0x0
L_80013360:
    lis         r3, 0xCC00
    lhz         r0, 0x206c(r3)
    clrlwi.     r0, r0, 31
    beq         L_80013378
    li          r5, 0x2
    b           L_8001337C
L_80013378:
    li          r5, 0x1
L_8001337C:
    slwi        r3, r29, 2
    lhzx        r0, r4, r3
    add         r3, r4, r3
    lbz         r4, 0x2(r3)
    mullw       r3, r5, r0
    bl          SISetXY
    mr          r3, r30
    bl          OSRestoreInterrupts
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    lwz         r29, 0x14(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_800133B8 ---- */
#pragma push
#pragma force_active on
void fn_800133B8(void)
{
    SISetSamplingRate(SamplingRate);
}
#pragma pop

static void dummy(void)
{
}

/* ---- fn_800133E0 ---- */
#pragma push
#pragma force_active on
asm void fn_800133E0(register s32 chan)
{
    nofralloc
    mflr        r0
    mulli       r5, r3, 0x28
    stw         r0, 0x4(r1)
    lis         r4, lbl_8015CC10@ha
    stwu        r1, -0x8(r1)
    addi        r0, r4, lbl_8015CC10@l
    add         r4, r0, r5
    lwz         r0, 0x18(r4)
    cmpwi       r0, 0x0
    bne         L_80013418
    lwz         r0, -0x7B98(r13) /* lbl_801A6828@sda21 */
    cmpwi       r0, 0x0
    bne         L_80013418
    bl          fn_8001375C
L_80013418:
    lwz         r0, 0xc(r1)
    addi        r1, r1, 0x8
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_80013428 ---- */
#pragma push
#pragma force_active on
asm int fn_80013428(register s32 chan, register void* callback)
{
    nofralloc
    mflr        r0
    cmplwi      r4, 0x0
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stw         r31, 0x24(r1)
    stw         r30, 0x20(r1)
    stw         r29, 0x1c(r1)
    addi        r29, r3, 0x0
    mulli       r5, r29, 0x28
    lis         r3, lbl_8015CC10@ha
    addi        r0, r3, lbl_8015CC10@l
    add         r30, r0, r5
    beq         L_80013464
    mr          r31, r4
    b           L_8001346C
L_80013464:
    lis         r3, dummy@ha
    addi        r31, r3, dummy@l
L_8001346C:
    bl          OSDisableInterrupts
    lwz         r0, 0x14(r30)
    cmplwi      r0, 0x0
    beq         L_80013484
    li          r31, -0x2
    b           L_8001348C
L_80013484:
    stw         r31, 0x14(r30)
    li          r31, 0x0
L_8001348C:
    bl          OSRestoreInterrupts
    cmpwi       r31, 0x0
    beq         L_800134A0
    mr          r3, r31
    b           L_800134C0
L_800134A0:
    li          r0, 0xff
    lis         r3, fn_800133E0@ha
    stb         r0, 0x0(r30)
    addi        r6, r3, fn_800133E0@l
    addi        r3, r29, 0x0
    li          r4, 0x1
    li          r5, 0x3
    bl          fn_800136E8
L_800134C0:
    lwz         r0, 0x2c(r1)
    lwz         r31, 0x24(r1)
    lwz         r30, 0x20(r1)
    lwz         r29, 0x1c(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_800134DC ---- */
#pragma push
#pragma force_active on
asm void fn_800134DC(register s32 chan, register u32 status,
                     register OSContext* context)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x2f8(r1)
    stw         r31, 0x2f4(r1)
    stw         r30, 0x2f0(r1)
    addi        r30, r5, 0x0
    stw         r29, 0x2ec(r1)
    mr          r29, r3
    lis         r3, lbl_8015CC10@ha
    lwz         r0, -0x7B98(r13) /* lbl_801A6828@sda21 */
    mulli       r6, r29, 0x28
    addi        r3, r3, lbl_8015CC10@l
    cmpwi       r0, 0x0
    add         r31, r3, r6
    bne         L_800135B0
    rlwinm.     r0, r4, 0, 28, 28
    beq         L_8001352C
    li          r0, -0x1
    stw         r0, 0x18(r31)
    b           L_80013548
L_8001352C:
    clrlwi.     r0, r4, 29
    beq         L_80013540
    li          r0, -0x3
    stw         r0, 0x18(r31)
    b           L_80013548
L_80013540:
    li          r0, 0x0
    stw         r0, 0x18(r31)
L_80013548:
    lwz         r12, 0x24(r31)
    cmplwi      r12, 0x0
    beq         L_80013568
    li          r0, 0x0
    mtlr        r12
    stw         r0, 0x24(r31)
    mr          r3, r29
    blrl
L_80013568:
    lwz         r0, 0x14(r31)
    cmplwi      r0, 0x0
    beq         L_800135B0
    addi        r3, r1, 0x18
    bl          OSClearContext
    addi        r3, r1, 0x18
    bl          OSSetCurrentContext
    lwz         r12, 0x14(r31)
    li          r0, 0x0
    addi        r3, r29, 0x0
    stw         r0, 0x14(r31)
    mtlr        r12
    lwz         r4, 0x18(r31)
    blrl
    addi        r3, r1, 0x18
    bl          OSClearContext
    mr          r3, r30
    bl          OSSetCurrentContext
L_800135B0:
    lwz         r0, 0x2fc(r1)
    lwz         r31, 0x2f4(r1)
    lwz         r30, 0x2f0(r1)
    lwz         r29, 0x2ec(r1)
    addi        r1, r1, 0x2f8
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_800135CC ---- */
#pragma push
#pragma force_active on
asm void fn_800135CC(register s32 chan, register u32 status)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x2f0(r1)
    stw         r31, 0x2ec(r1)
    mr          r31, r3
    lis         r3, lbl_8015CC10@ha
    stw         r30, 0x2e8(r1)
    mulli       r5, r31, 0x28
    stw         r29, 0x2e4(r1)
    addi        r3, r3, lbl_8015CC10@l
    lwz         r0, -0x7B98(r13) /* lbl_801A6828@sda21 */
    add         r30, r3, r5
    cmpwi       r0, 0x0
    bne         L_800136CC
    clrrwi      r3, r4, 16
    subis       r0, r3, 0x800
    cmplwi      r0, 0x0
    bne         L_80013650
    lis         r3, fn_800134DC@ha
    lwz         r5, 0xc(r30)
    addi        r8, r3, fn_800134DC@l
    lwz         r7, 0x10(r30)
    addi        r3, r31, 0x0
    addi        r4, r30, 0x0
    addi        r6, r30, 0x3
    li          r10, 0x0
    li          r9, 0x0
    bl          SITransfer
    cmpwi       r3, 0x0
    bne         L_800136CC
    li          r0, -0x2
    stw         r0, 0x18(r30)
    b           L_80013658
L_80013650:
    li          r0, -0x1
    stw         r0, 0x18(r30)
L_80013658:
    lwz         r12, 0x24(r30)
    cmplwi      r12, 0x0
    beq         L_80013678
    li          r0, 0x0
    mtlr        r12
    stw         r0, 0x24(r30)
    mr          r3, r31
    blrl
L_80013678:
    lwz         r0, 0x14(r30)
    cmplwi      r0, 0x0
    beq         L_800136CC
    bl          OSGetCurrentContext
    addi        r29, r3, 0x0
    addi        r3, r1, 0x10
    bl          OSClearContext
    addi        r3, r1, 0x10
    bl          OSSetCurrentContext
    lwz         r12, 0x14(r30)
    li          r0, 0x0
    addi        r3, r31, 0x0
    stw         r0, 0x14(r30)
    mtlr        r12
    lwz         r4, 0x18(r30)
    blrl
    addi        r3, r1, 0x10
    bl          OSClearContext
    mr          r3, r29
    bl          OSSetCurrentContext
    bl          __OSReschedule
L_800136CC:
    lwz         r0, 0x2f4(r1)
    lwz         r31, 0x2ec(r1)
    lwz         r30, 0x2e8(r1)
    lwz         r29, 0x2e4(r1)
    addi        r1, r1, 0x2f0
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_800136E8 ---- */
#pragma push
#pragma force_active on
asm int fn_800136E8(register s32 chan, register u32 cmd, register u32 param,
                    register void (*callback)(s32))
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stmw        r27, 0x1c(r1)
    addi        r27, r3, 0x0
    lis         r3, lbl_8015CC10@ha
    mulli       r7, r27, 0x28
    addi        r0, r3, lbl_8015CC10@l
    addi        r28, r4, 0x0
    addi        r29, r5, 0x0
    addi        r31, r6, 0x0
    add         r30, r0, r7
    bl          OSDisableInterrupts
    stw         r31, 0x24(r30)
    lis         r4, fn_800135CC@ha
    addi        r31, r3, 0x0
    stw         r28, 0xc(r30)
    addi        r4, r4, fn_800135CC@l
    mr          r3, r27
    stw         r29, 0x10(r30)
    bl          SIGetTypeAsync
    mr          r3, r31
    bl          OSRestoreInterrupts
    lmw         r27, 0x1c(r1)
    li          r3, 0x0
    lwz         r0, 0x34(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_8001375C ---- */
#pragma push
#pragma force_active on
asm void fn_8001375C(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    lis         r0, 0x8000
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    mr          r31, r3
    srw         r4, r0, r31
    lwz         r3, -0x7B8C(r13) /* lbl_801A6834@sda21 */
    and.        r0, r3, r4
    bne         L_800137B0
    or          r0, r3, r4
    stw         r0, -0x7B8C(r13) /* lbl_801A6834@sda21 */
    addi        r3, r31, 0x0
    addi        r4, r1, 0xc
    bl          SIGetResponse
    lis         r3, 0x30
    addi        r4, r3, 0x680
    addi        r3, r31, 0x0
    bl          SISetCommand
    lwz         r3, -0x7B8C(r13) /* lbl_801A6834@sda21 */
    bl          SIGetWirelessID
L_800137B0:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_800137C4 ---- */
#pragma push
#pragma force_active on
asm int fn_800137C4(register s32 chan, register void* out)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stmw        r27, 0x1c(r1)
    addi        r27, r3, 0x0
    addi        r29, r4, 0x0
    bl          OSDisableInterrupts
    mulli       r5, r27, 0x28
    lis         r4, lbl_8015CC10@ha
    addi        r4, r4, lbl_8015CC10@l
    lis         r0, 0x8000
    addi        r31, r3, 0x0
    addi        r3, r27, 0x0
    add         r30, r4, r5
    srw         r28, r0, r27
    bl          SIIsChanBusy
    cmpwi       r3, 0x0
    beq         L_80013818
    li          r0, -0x2
    stw         r0, 0x18(r30)
    b           L_800138FC
L_80013818:
    lwz         r0, -0x7B8C(r13) /* lbl_801A6834@sda21 */
    and.        r0, r0, r28
    bne         L_80013830
    li          r0, -0x1
    stw         r0, 0x18(r30)
    b           L_800138FC
L_80013830:
    mr          r3, r27
    bl          SIGetStatus
    rlwinm.     r0, r3, 0, 28, 28
    beq         L_8001386C
    addi        r3, r27, 0x0
    addi        r4, r1, 0x10
    bl          SIGetResponse
    mr          r3, r28
    bl          SIGetWirelessIDBitfield
    lwz         r3, -0x7B8C(r13) /* lbl_801A6834@sda21 */
    li          r0, -0x1
    andc        r3, r3, r28
    stw         r3, -0x7B8C(r13) /* lbl_801A6834@sda21 */
    stw         r0, 0x18(r30)
    b           L_800138FC
L_8001386C:
    addi        r3, r27, 0x0
    addi        r4, r1, 0x10
    bl          SIGetResponse
    cmpwi       r3, 0x0
    beq         L_8001388C
    lwz         r0, 0x10(r1)
    clrrwi.     r0, r0, 31
    beq         L_80013898
L_8001388C:
    li          r0, -0x3
    stw         r0, 0x18(r30)
    b           L_800138FC
L_80013898:
    li          r0, 0x0
    cmplwi      r29, 0x0
    stw         r0, 0x18(r30)
    beq         L_800138FC
    lwz         r0, 0x10(r1)
    srwi        r0, r0, 16
    sth         r0, 0x0(r29)
    lwz         r0, 0x10(r1)
    extrwi      r0, r0, 8, 16
    stb         r0, 0x2(r29)
    lwz         r0, 0x10(r1)
    clrlwi      r3, r0, 24
    subi        r0, r3, 0x80
    stb         r0, 0x3(r29)
    lwz         r0, 0x14(r1)
    srwi        r0, r0, 24
    stb         r0, 0x4(r29)
    lwz         r0, 0x14(r1)
    extrwi      r0, r0, 8, 8
    stb         r0, 0x5(r29)
    lwz         r0, 0x14(r1)
    extrwi      r0, r0, 8, 16
    stb         r0, 0x6(r29)
    lwz         r0, 0x14(r1)
    stb         r0, 0x7(r29)
L_800138FC:
    cmplwi      r29, 0x0
    beq         L_80013910
    lwz         r0, 0x18(r30)
    extsb       r0, r0
    stb         r0, 0x8(r29)
L_80013910:
    lwz         r28, 0x18(r30)
    mr          r3, r31
    bl          OSRestoreInterrupts
    mr          r3, r28
    lmw         r27, 0x1c(r1)
    lwz         r0, 0x34(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_80013934 ---- */
#pragma push
#pragma force_active on
asm void fn_80013934(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x2e0(r1)
    stw         r31, 0x2dc(r1)
    addi        r31, r4, 0x0
    lwz         r0, -0x7B90(r13) /* lbl_801A6830@sda21 */
    cmplwi      r0, 0x0
    beq         L_80013980
    addi        r3, r1, 0x10
    bl          OSClearContext
    addi        r3, r1, 0x10
    bl          OSSetCurrentContext
    lwz         r12, -0x7B90(r13) /* lbl_801A6830@sda21 */
    mtlr        r12
    blrl
    addi        r3, r1, 0x10
    bl          OSClearContext
    mr          r3, r31
    bl          OSSetCurrentContext
L_80013980:
    lwz         r0, 0x2e4(r1)
    lwz         r31, 0x2dc(r1)
    addi        r1, r1, 0x2e0
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_80013994 ---- */
#pragma push
#pragma force_active on
asm void* fn_80013994(register void* handler)
{
    nofralloc
    mflr        r0
    cmplwi      r3, 0x0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    lwz         r31, -0x7B90(r13) /* lbl_801A6830@sda21 */
    stw         r3, -0x7B90(r13) /* lbl_801A6830@sda21 */
    beq         L_800139C4
    lis         r3, fn_80013934@ha
    addi        r3, r3, fn_80013934@l
    bl          SIRegisterPollingHandler
    b           L_800139D0
L_800139C4:
    lis         r3, fn_80013934@ha
    addi        r3, r3, fn_80013934@l
    bl          SIUnregisterPollingHandler
L_800139D0:
    mr          r3, r31
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- fn_800139E8 ---- */
#pragma push
#pragma force_active on
asm void fn_800139E8(register s32 chan, register u32 unk, register s32 val)
{
    nofralloc
    mflr        r0
    cmpwi       r5, -0x80
    stw         r0, 0x4(r1)
    rlwinm      r0, r4, 0, 21, 22
    stwu        r1, -0x28(r1)
    stw         r31, 0x24(r1)
    stw         r30, 0x20(r1)
    stw         r29, 0x1c(r1)
    addi        r29, r3, 0x0
    bgt         L_80013A18
    li          r30, 0x0
    b           L_80013A2C
L_80013A18:
    cmpwi       r5, 0x80
    blt         L_80013A28
    li          r30, 0x100
    b           L_80013A2C
L_80013A28:
    addi        r30, r5, 0x80
L_80013A2C:
    or          r30, r30, r0
    clrlwi      r30, r30, 21
    bl          OSDisableInterrupts
    lis         r0, 0x8000
    lwz         r4, -0x7B8C(r13) /* lbl_801A6834@sda21 */
    srw         r0, r0, r29
    and.        r0, r4, r0
    addi        r31, r3, 0x0
    beq         L_80013A64
    oris        r30, r30, 0x30
    addi        r3, r29, 0x0
    addi        r4, r30, 0x0
    bl          SISetCommand
    bl          SITransferCommands
L_80013A64:
    mr          r3, r31
    bl          OSRestoreInterrupts
    lwz         r0, 0x2c(r1)
    lwz         r31, 0x24(r1)
    lwz         r30, 0x20(r1)
    lwz         r29, 0x1c(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop
