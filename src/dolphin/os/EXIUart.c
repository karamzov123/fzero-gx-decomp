// dolphin/os/EXIUart.c -- 0x80015464-0x80015A38.
//
// A SEPARATE SDK translation unit from EXIBios.c, and it has to stay separate:
// every function here matches with MWCC's default -O4,p schedule, while every
// function in EXIBios.c only matches with `-opt noschedule`. Compiled together
// under either flag, one half or the other loses. The retail objects say the
// same thing -- the EXIBios half reloads the LR before its `lmw`, this half
// does not.
#include <dolphin/exi_private.h>

extern u32 OSGetConsoleType(void);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(register int level);

/* EXI UART state, defined in EXIBios.c's unit; see the note there. */
extern s32 Chan;
extern u32 Dev;
extern u32 Enabled;
extern u32 BarnacleEnabled;

extern int EXIGetID(register s32 chan, register u32 dev, register u32* id);
extern int __EXIGetID(register s32 chan, register u32 dev, register u32* id);
extern int EXILock(s32 chan, u32 dev, EXICallback unlockedCallback);
extern int EXIUnlock(s32 chan);
extern int EXISelect(s32 chan, u32 dev, u32 freq);
extern int EXIDeselect(s32 chan);
extern int EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
extern int EXIImmEx(s32 chan, void* buf, s32 len, u32 mode);
extern int EXISync(s32 chan);
extern int EXIAttach(s32 chan, EXICallback extCallback);
extern int EXIDetach(s32 chan);
extern int EXIProbe(s32 chan);

/* ---- __EXIGetID ---- */
#pragma push
#pragma force_active on
asm int __EXIGetID(register s32 chan, register u32 dev, register u32* id)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stw         r31, 0x24(r1)
    addi        r31, r5, 0x0
    stw         r30, 0x20(r1)
    addi        r30, r4, 0x0
    stw         r29, 0x1c(r1)
    addi        r29, r3, 0x0
    cmpwi       r29, 0x2
    stw         r28, 0x18(r1)
    beq         L_800154B8
    cmplwi      r30, 0x0
    bne         L_800154B8
    addi        r3, r29, 0x0
    li          r4, 0x0
    bl          EXIAttach
    cmpwi       r3, 0x0
    bne         L_800154B8
    li          r3, 0x0
    b           L_800155D0
L_800154B8:
    addi        r3, r29, 0x0
    addi        r4, r30, 0x0
    li          r5, 0x0
    bl          EXILock
    cntlzw      r0, r3
    srwi        r0, r0, 5
    mr.         r28, r0
    bne         L_8001558C
    addi        r3, r29, 0x0
    addi        r4, r30, 0x0
    li          r5, 0x0
    bl          EXISelect
    cntlzw      r0, r3
    srwi        r0, r0, 5
    mr.         r28, r0
    bne         L_80015584
    lis         r3, 0x2001
    addi        r0, r3, 0x1300
    stw         r0, 0x14(r1)
    addi        r3, r29, 0x0
    addi        r4, r1, 0x14
    li          r5, 0x4
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    cntlzw      r0, r3
    addi        r3, r29, 0x0
    srwi        r28, r0, 5
    bl          EXISync
    cntlzw      r0, r3
    srwi        r0, r0, 5
    addi        r3, r29, 0x0
    addi        r4, r31, 0x0
    or          r28, r28, r0
    li          r5, 0x4
    li          r6, 0x0
    li          r7, 0x0
    bl          EXIImm
    cntlzw      r0, r3
    srwi        r0, r0, 5
    addi        r3, r29, 0x0
    or          r28, r28, r0
    bl          EXISync
    cntlzw      r0, r3
    srwi        r0, r0, 5
    addi        r3, r29, 0x0
    or          r28, r28, r0
    bl          EXIDeselect
    cntlzw      r0, r3
    srwi        r0, r0, 5
    or          r28, r28, r0
L_80015584:
    mr          r3, r29
    bl          EXIUnlock
L_8001558C:
    cmpwi       r29, 0x2
    beq         L_800155A4
    cmplwi      r30, 0x0
    bne         L_800155A4
    mr          r3, r29
    bl          EXIDetach
L_800155A4:
    cmpwi       r28, 0x0
    beq         L_800155B4
    li          r3, 0x0
    b           L_800155D0
L_800155B4:
    lwz         r3, 0x0(r31)
    addis       r0, r3, 0x1
    cmplwi      r0, 0xffff
    beq         L_800155CC
    li          r3, 0x1
    b           L_800155D0
L_800155CC:
    li          r3, 0x0
L_800155D0:
    lwz         r0, 0x2c(r1)
    lwz         r31, 0x24(r1)
    lwz         r30, 0x20(r1)
    lwz         r29, 0x1c(r1)
    lwz         r28, 0x18(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop
/* ---- __OSEnableBarnacle ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIUart.c:51
// adapted: retail re-reads the ID through __EXIGetID in the default arm,
// where the reference calls its ProbeBarnacle helper.
void __OSEnableBarnacle(s32 chan, u32 dev)
{
    u32 id;

    if (EXIGetID(chan, dev, &id)) {
        switch (id) {
        case 0xffffffff:
        case EXI_MEMORY_CARD_59:
        case EXI_MEMORY_CARD_123:
        case EXI_MEMORY_CARD_251:
        case EXI_MEMORY_CARD_507:
        case EXI_USB_ADAPTER:
        case EXI_NPDP_GDEV:
        case EXI_MODEM:
        case EXI_MARLIN:
        case 0x04020100:
        case 0x04020200:
        case 0x04020300:
        case 0x04040404:
        case 0x04060000:
        case 0x04120000:
        case 0x04130000:
        case 0x04220000:
        case 0x80000000 | EXI_MEMORY_CARD_59:
        case 0x80000000 | EXI_MEMORY_CARD_123:
        case 0x80000000 | EXI_MEMORY_CARD_251:
        case 0x80000000 | EXI_MEMORY_CARD_507:
            break;
        default:
            if (__EXIGetID(chan, dev, &id)) {
                Chan = chan;
                Dev = dev;
                Enabled = BarnacleEnabled = EXI_MAGIC;
            }
            break;
        }
    }
}
#pragma pop
/* ---- InitializeUART ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIUart.c:93
u32 InitializeUART(void)
{
    if (BarnacleEnabled == EXI_MAGIC) {
        return 0;
    }

    if (!(OSGetConsoleType() & OS_CONSOLE_DEVELOPMENT)) {
        Enabled = 0;
        return 2;
    }
    Enabled = EXI_MAGIC;
    Chan = 0;
    Dev = 1;
    return 0;
}
#pragma pop
/* ---- WriteUARTN ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIUart.c:116
static __inline int QueueLength(void)
{
    u32 cmd;

    if (!EXISelect(Chan, Dev, EXI_FREQ_8M)) {
        return -1;
    }

    cmd = EXI_TX << 6;
    EXIImm(Chan, &cmd, 4, EXI_WRITE, 0);
    EXISync(Chan);

    EXIImm(Chan, &cmd, 1, EXI_READ, 0);
    EXISync(Chan);
    EXIDeselect(Chan);

    return 16 - (int)((cmd >> 24) & 0xff);
}

// provenance: mkdd:libs/dolphin/exi/EXIUart.c:134
u32 WriteUARTN(const void* buf, unsigned long len)
{
    BOOL enabled;
    u32 cmd;
    int qLen;
    long xLen;
    char* ptr;
    BOOL locked;
    u32 error;

    if (Enabled != EXI_MAGIC) {
        return 2;
    }

    enabled = OSDisableInterrupts();

    locked = EXILock(Chan, Dev, 0);
    if (!locked) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    for (ptr = (char*)buf; ptr - (char*)buf < len; ptr++) {
        if (*ptr == '\n') {
            *ptr = '\r';
        }
    }

    error = 0;
    cmd = (EXI_TX | 0x2000000) << 6;
    while (len) {
        qLen = QueueLength();
        if (qLen < 0) {
            error = 3;
            break;
        }

        if (qLen < 12 && qLen < len) {
            continue;
        }

        if (!EXISelect(Chan, Dev, EXI_FREQ_8M)) {
            error = 3;
            break;
        }

        EXIImm(Chan, &cmd, 4, EXI_WRITE, 0);
        EXISync(Chan);

        while (qLen && len) {
            if (qLen < 4 && qLen < len) {
                break;
            }
            xLen = (len < 4) ? (long)len : 4;
            EXIImm(Chan, (void*)buf, xLen, EXI_WRITE, 0);
            (u8*)buf += xLen;
            len -= xLen;
            qLen -= xLen;
            EXISync(Chan);
        }
        EXIDeselect(Chan);
    }

    EXIUnlock(Chan);
    OSRestoreInterrupts(enabled);
    return error;
}
#pragma pop
