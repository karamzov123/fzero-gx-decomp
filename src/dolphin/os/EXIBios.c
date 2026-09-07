#include <dolphin/exi_private.h>

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(register int level);
extern u32 __OSMaskInterrupts(u32 mask);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void __OSSetInterruptHandler(s32 interrupt, void* handler);
extern void* __OSGetInterruptHandler(s32 interrupt);
extern void OSRegisterVersion(const char* version);
extern u32 __OSGetDIConfig(void);
extern u32 OSGetConsoleType(void);
extern OSTime OSGetTime(void);
extern u32 __div2i(register u32 hi, register u32 lo, register u32 den_hi,
                       register u32 den_lo);
extern void* memmove(void* dst, const void* src, u32 len);

/*
 * Near globals (.sbss/.sdata) are referenced through the r13 small-data
 * anchor with hand-resolved displacements (.sdata base 0x801A63C0 + 0x8000).
 */
/* Ecb lives in <dolphin/exi_private.h>: EXIControl Ecb[3] @ .bss:0x8015CCB0. */

/*
 * EXI hardware registers. Retail open-codes `lis 0xCC00 / addi 0x6800` with no
 * relocation, which is exactly what MWCC's address-placed array emits (same
 * idiom as __AIRegs/__DSPRegs in src/dolphin/ai/AI.c). Five channels' worth of
 * registers at a 5-word stride: __EXIRegs[chan * 5 + reg].
 */
volatile u32 __EXIRegs[] : 0xCC006800;

/* OS globals: __EXIProbe's per-channel probe timestamp. See exi_private.h. */
s32 __EXIProbeStartTime[] : 0x800030C0;

/* forward declarations */
extern void SetExiInterruptMask(register s32 chan, register EXIControl* exi);
extern u32 EXIClearInterrupts(register s32 chan, register int exi,
                              register int tc, register int ext);
extern int __EXIProbe(register s32 chan);
extern int EXILock(register s32 chan, register u32 dev,
                   register EXICallback unlockedCallback);
extern int EXISelect(register s32 chan, register u32 dev, register u32 freq);
extern int EXIImm(register s32 chan, register void* buf, register s32 len,
                  register u32 type, register EXICallback callback);
extern int EXISync(register s32 chan);
extern int EXIDeselect(register s32 chan);
extern int EXIUnlock(register s32 chan);
extern int EXIGetID(register s32 chan, register u32 dev, register u32* id);
extern void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext* context);
extern void TCIntrruptHandler(__OSInterrupt interrupt, OSContext* context);
extern void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext* context);
extern void UnlockedHandler(register s32 chan, register OSContext* context);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern void __OSEnableBarnacle(register s32 chan, register u32 dev);
extern int EXIProbe(register s32 chan);
extern int EXIDma(register s32 chan, register void* buf, register s32 len,
                  register u32 type, register EXICallback callback);
extern int __EXIGetID(register s32 chan, register u32 dev, register u32* id);
extern int EXIDetach(register s32 chan);

/* ---- SetExiInterruptMask ---- */
#pragma push
#pragma force_active on
extern u32 IDSerialPort1; /* .sdata, reached through @sda21 */
extern const char* __EXIVersion; /* .sdata, @sda21 */
extern BOOL __OSInIPL; /* .sdata, @sda21; retail compares it signed */
/*
 * EXI UART state (.sbss, all four reached through @sda21 as words). Named from
 * mkdd's EXIUart.c, which is the revision retail matches; InitializeUART's
 * `addis r0, r3, 0x5a01 / cmplwi r0, 0x5a` pins EXI_MAGIC to 0xA5FF005A.
 */
extern s32 Chan;
extern u32 Dev;
extern u32 Enabled;
extern u32 BarnacleEnabled;
// provenance: dolsdk2001:src/os/OSExi.c:63
void SetExiInterruptMask(s32 chan, EXIControl* exi)
{
    EXIControl* exi2 = &Ecb[2];

    switch (chan) {
    case 0:
        if ((exi->exiCallback == 0 && exi2->exiCallback == 0) ||
            exi->state & STATE_LOCKED) {
            __OSMaskInterrupts(0x410000U);
            return;
        }
        __OSUnmaskInterrupts(0x410000U);
        return;
    case 1:
        if (exi->exiCallback == 0 || exi->state & STATE_LOCKED) {
            __OSMaskInterrupts(0x80000U);
            return;
        }
        __OSUnmaskInterrupts(0x80000U);
        return;
    case 2:
        if ((__OSGetInterruptHandler(0x19) == 0U) ||
            (exi->state & STATE_LOCKED)) {
            __OSMaskInterrupts(0x40U);
            return;
        }
        __OSUnmaskInterrupts(0x40U);
        return;
    }
}
#pragma pop

/* ---- EXIImm ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:115
int EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
    EXIControl* exi;
    BOOL enabled;
    u32 data;
    int i;

    exi = &Ecb[chan];
    ASSERTLINE(0x13B, exi->state & STATE_SELECTED);
    ASSERTLINE(0x13C, 0 <= chan && chan < MAX_CHAN);
    ASSERTLINE(0x13D, 0 < len && len <= MAX_IMM);
    ASSERTLINE(0x13E, type < MAX_TYPE);
    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_BUSY) || !(exi->state & STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->tcCallback = callback;
    if (exi->tcCallback) {
        EXIClearInterrupts(chan, 0, 1, 0);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }
    exi->state |= STATE_IMM;
    if (type != EXI_READ) {
        data = 0;
        for (i = 0; i < len; i++) {
            data |= ((u8*)buf)[i] << ((3 - i) * 8);
        }
        __EXIRegs[(chan * 5) + 4] = data;
    }
    exi->immBuf = buf;
    exi->immLen = (type != EXI_WRITE) ? len : 0;
    __EXIRegs[(chan * 5) + 3] = (type << 2) | 1 | ((len - 1) << 4);
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma pop

/* ---- EXIImmEx ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:151
int EXIImmEx(s32 chan, void* buf, s32 len, u32 mode)
{
    s32 xLen;

    while (len) {
        xLen = (len < 4) ? len : 4;
        if (EXIImm(chan, buf, xLen, mode, 0) == 0) {
            return 0;
        }
        if (EXISync(chan) == 0) {
            return 0;
        }
        ((u8*)buf) += xLen;
        len -= xLen;
    }
    return 1;
}
#pragma pop

/* ---- EXIDma ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:168
int EXIDma(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
    EXIControl* exi;
    BOOL enabled;

    exi = &Ecb[chan];

    ASSERTLINE(0x1A4, exi->state & STATE_SELECTED);
    ASSERTLINE(0x1A6, 0 < len);
    ASSERTLINE(0x1AA, type == EXI_READ || type == EXI_WRITE);

    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_BUSY) || !(exi->state & STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->tcCallback = callback;
    if ((u32)exi->tcCallback) {
        EXIClearInterrupts(chan, 0, 1, 0);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }
    exi->state |= STATE_DMA;
    __EXIRegs[(chan * 5) + 1] = (u32)buf & 0x03FFFFE0;
    __EXIRegs[(chan * 5) + 2] = len;
    __EXIRegs[(chan * 5) + 3] = (type * 4) | 3;
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma pop

/* ---- CompleteTransfer (static; retail inlines it) ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:92
static __inline void CompleteTransfer(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    u8* buf;
    u32 data;
    int i;
    int len;

    if (exi->state & STATE_BUSY) {
        if ((exi->state & STATE_IMM) && (len = exi->immLen)) {
            buf = exi->immBuf;
            data = __EXIRegs[chan * 5 + 4];
            for (i = 0; i < len; i++) {
                *buf++ = (u8)((data >> ((3 - i) * 8)) & 0xff);
            }
        }
        exi->state &= ~STATE_BUSY;
    }
}

#pragma pop

/* ---- EXISync ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:216
int EXISync(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    BOOL rc = FALSE;
    BOOL enabled;

    while (exi->state & STATE_SELECTED) {
        if (((__EXIRegs[chan * 5 + 3] & 1) >> 0) == 0) {
            enabled = OSDisableInterrupts();
            if (exi->state & STATE_SELECTED) {
                CompleteTransfer(chan);
                if (__OSGetDIConfig() != 0xff ||
                    ((OSGetConsoleType() & OS_CONSOLE_MASK) == OS_CONSOLE_TDEV) ||
                    exi->immLen != 4 ||
                    (__EXIRegs[chan * 5] & 0x00000070) != (EXI_FREQ_1M << 4) ||
                    (__EXIRegs[chan * 5 + 4] != EXI_USB_ADAPTER &&
                     __EXIRegs[chan * 5 + 4] != EXI_IS_VIEWER &&
                     __EXIRegs[chan * 5 + 4] != 0x04220001) ||
                    __OSDeviceCode == 0x8200) {
                    rc = TRUE;
                }
            }
            OSRestoreInterrupts(enabled);
            break;
        }
    }
    return rc;
}
#pragma pop

/* ---- EXIClearInterrupts ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c (EXIClearInterrupts)
u32 EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext)
{
    u32 cpr;
    u32 prev;

    prev = cpr = __EXIRegs[chan * 5];
    cpr &= 0x7F5;
    if (exi) {
        cpr |= 0x2;
    }
    if (tc) {
        cpr |= 0x8;
    }
    if (ext) {
        cpr |= 0x800;
    }
    __EXIRegs[chan * 5] = cpr;
    return prev;
}
#pragma pop

/* ---- EXISetExiCallback ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:241
EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback)
{
    EXIControl* exi = &Ecb[chan];
    EXICallback prev;
    BOOL enabled;

    ASSERTLINE(0x220, 0 <= chan && chan < MAX_CHAN);
    enabled = OSDisableInterrupts();
    prev = exi->exiCallback;
    exi->exiCallback = exiCallback;
    if (chan != 2) {
        SetExiInterruptMask(chan, exi);
    } else {
        SetExiInterruptMask(0, &Ecb[0]);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}
#pragma pop

/* ---- __EXIProbe ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:294
int __EXIProbe(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;
    BOOL rc;
    u32 cpr;
    s32 t;

    if (chan == 2) {
        return TRUE;
    }

    rc = TRUE;
    enabled = OSDisableInterrupts();
    cpr = __EXIRegs[chan * 5];
    if (!(exi->state & STATE_ATTACHED)) {
        if (cpr & 0x00000800) {
            EXIClearInterrupts(chan, FALSE, FALSE, TRUE);
            __EXIProbeStartTime[chan] = exi->idTime = 0;
        }

        if (cpr & 0x00001000) {
            t = (s32)(OSTicksToMilliseconds(OSGetTime()) / 100) + 1;
            if (__EXIProbeStartTime[chan] == 0) {
                __EXIProbeStartTime[chan] = t;
            }
            if (t - __EXIProbeStartTime[chan] < 300 / 100) {
                rc = FALSE;
            }
        } else {
            __EXIProbeStartTime[chan] = exi->idTime = 0;
            rc = FALSE;
        }
    } else if (!(cpr & 0x00001000) || (cpr & 0x00000800)) {
        __EXIProbeStartTime[chan] = exi->idTime = 0;
        rc = FALSE;
    }
    OSRestoreInterrupts(enabled);

    return rc;
}
#pragma pop

/* ---- EXIProbe ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:346
int EXIProbe(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    BOOL rc;
    u32 id;

    rc = __EXIProbe(chan);
    if (rc && exi->idTime == 0) {
        rc = EXIGetID(chan, 0, &id) ? TRUE : FALSE;
    }
    return rc;
}
#pragma pop

/* ---- EXIProbeEx ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:360
int EXIProbeEx(s32 chan)
{
    if (EXIProbe(chan)) {
        return 1;
    } else if (__EXIProbeStartTime[chan] != 0) {
        return 0;
    } else {
        return -1;
    }
}
#pragma pop

/* ---- EXIAttach ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:376
static __inline int __EXIAttach(s32 chan, EXICallback extCallback)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_ATTACHED) || __EXIProbe(chan) == FALSE) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    EXIClearInterrupts(chan, TRUE, FALSE, FALSE);

    exi->extCallback = extCallback;
    __OSUnmaskInterrupts(0x100000U >> (3 * chan));
    exi->state |= STATE_ATTACHED;
    OSRestoreInterrupts(enabled);

    return TRUE;
}

// provenance: mkdd:libs/dolphin/exi/EXIBios.c:398
int EXIAttach(s32 chan, EXICallback extCallback)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;
    BOOL rc;

    EXIProbe(chan);

    enabled = OSDisableInterrupts();
    if (exi->idTime == 0) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    rc = __EXIAttach(chan, extCallback);
    OSRestoreInterrupts(enabled);
    return rc;
}
#pragma pop

/* ---- EXIDetach ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:340
// adapted: retail masks 0x500000 (EXI+TC), not the reference's 0x700000.
int EXIDetach(s32 chan)
{
    EXIControl* exi;
    BOOL enabled;

    exi = &Ecb[chan];
    ASSERTLINE(0x2D7, 0 <= chan && chan < 2);
    enabled = OSDisableInterrupts();
    if (!(exi->state & STATE_ATTACHED)) {
        OSRestoreInterrupts(enabled);
        return 1;
    }
    if ((exi->state & STATE_LOCKED) && (exi->dev == 0)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~STATE_ATTACHED;
    __OSMaskInterrupts(0x500000U >> (chan * 3));
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma pop

/* ---- EXISelect ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:361
// adapted: retail probes through __EXIProbe, not the public EXIProbe.
int EXISelect(s32 chan, u32 dev, u32 freq)
{
    EXIControl* exi;
    u32 cpr;
    BOOL enabled;

    exi = &Ecb[chan];

    ASSERTLINE(0x2FF, 0 <= chan && chan < MAX_CHAN);
    ASSERTLINE(0x300, chan == 0 && dev < MAX_DEV || dev == 0);
    ASSERTLINE(0x301, freq < MAX_FREQ);
    ASSERTLINE(0x302, !(exi->state & STATE_SELECTED));

    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_SELECTED) ||
        ((chan != 2) &&
         (((dev == 0) && !(exi->state & STATE_ATTACHED) && (__EXIProbe(chan) == 0)) ||
          !(exi->state & STATE_LOCKED) || (exi->dev != dev)))) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state |= STATE_SELECTED;
    cpr = __EXIRegs[(chan * 5)];
    cpr &= 0x405;
    cpr |= (((1 << dev) << 7) | (freq * 0x10));
    __EXIRegs[(chan * 5)] = cpr;
    if (exi->state & STATE_ATTACHED) {
        switch (chan) {
        case 0:
            __OSMaskInterrupts(0x100000U);
            break;
        case 1:
            __OSMaskInterrupts(0x20000U);
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma pop

/* ---- EXIDeselect ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:397
// adapted: retail guards the re-probe with `chan != 2` (the reference has
// `chan == 0`) and probes through __EXIProbe.
int EXIDeselect(s32 chan)
{
    EXIControl* exi;
    u32 cpr;
    BOOL enabled;

    exi = &Ecb[chan];
    ASSERTLINE(0x335, 0 <= chan && chan < MAX_CHAN);
    enabled = OSDisableInterrupts();
    if (!(exi->state & STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~STATE_SELECTED;
    cpr = __EXIRegs[(chan * 5)];
    __EXIRegs[(chan * 5)] = cpr & 0x405;
    if (exi->state & STATE_ATTACHED) {
        switch (chan) {
        case 0:
            __OSUnmaskInterrupts(0x100000U);
            break;
        case 1:
            __OSUnmaskInterrupts(0x20000U);
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    if ((chan != 2) && (cpr & 0x80)) {
        if (__EXIProbe(chan) != 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}
#pragma pop

/* ---- EXIIntrruptHandler ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:517
void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    s32 chan;
    EXIControl* exi;
    EXICallback callback;

    chan = (interrupt - __OS_INTERRUPT_EXI_0_EXI) / 3;
    exi = &Ecb[chan];
    EXIClearInterrupts(chan, TRUE, FALSE, FALSE);
    callback = exi->exiCallback;
    if (callback) {
        OSContext exceptionContext;

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);

        callback(chan, context);

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
#pragma pop

/* ---- TCIntrruptHandler ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:541
void TCIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    OSContext exceptionContext;
    s32 chan;
    EXIControl* exi;
    EXICallback callback;

    chan = (interrupt - __OS_INTERRUPT_EXI_0_TC) / 3;
    exi = &Ecb[chan];
    __OSMaskInterrupts(OS_INTERRUPTMASK(interrupt));
    EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
    callback = exi->tcCallback;
    if (callback) {
        exi->tcCallback = 0;
        CompleteTransfer(chan);

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);

        callback(chan, context);

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
#pragma pop

/* ---- EXTIntrruptHandler ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:568
void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    s32 chan;
    EXIControl* exi;
    EXICallback callback;

    chan = (interrupt - __OS_INTERRUPT_EXI_0_EXT) / 3;
    __OSMaskInterrupts((OS_INTERRUPTMASK_EXI_0_EXT | OS_INTERRUPTMASK_EXI_0_EXI) >> (3 * chan));
    exi = &Ecb[chan];
    callback = exi->extCallback;
    exi->state &= ~STATE_ATTACHED;
    if (callback) {
        OSContext exceptionContext;

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);

        exi->extCallback = 0;
        callback(chan, context);

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
#pragma pop

/* ---- EXIInit ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:594
void EXIInit(void)
{
    u32 id;

    while (((__EXIRegs[0 * 5 + 3] & 0x1) == 1) ||
           ((__EXIRegs[1 * 5 + 3] & 0x1) == 1) ||
           ((__EXIRegs[2 * 5 + 3] & 0x1) == 1)) {
        continue;
    }

    __OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_0_TC |
                       OS_INTERRUPTMASK_EXI_0_EXT | OS_INTERRUPTMASK_EXI_1_EXI |
                       OS_INTERRUPTMASK_EXI_1_TC | OS_INTERRUPTMASK_EXI_1_EXT |
                       OS_INTERRUPTMASK_EXI_2_EXI | OS_INTERRUPTMASK_EXI_2_TC);

    __EXIRegs[0 * 5] = 0;
    __EXIRegs[1 * 5] = 0;
    __EXIRegs[2 * 5] = 0;

    __EXIRegs[0 * 5] = 0x00002000;

    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_0_EXI, EXIIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_0_TC, TCIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_0_EXT, EXTIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_1_EXI, EXIIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_1_TC, TCIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_1_EXT, EXTIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_2_EXI, EXIIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_EXI_2_TC, TCIntrruptHandler);

    EXIGetID(0, 2, &IDSerialPort1);

    if (__OSInIPL) {
        __EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
        Ecb[0].idTime = Ecb[1].idTime = 0;
        __EXIProbe(0);
        __EXIProbe(1);
    } else if (EXIGetID(0, 0, &id) && id == 0x07010000) {
        __OSEnableBarnacle(1, 0);
    } else if (EXIGetID(1, 0, &id) && id == 0x07010000) {
        __OSEnableBarnacle(0, 2);
    }

    OSRegisterVersion(__EXIVersion);
}
#pragma pop

/* ---- EXILock ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:505
int EXILock(s32 chan, u32 dev, EXICallback unlockedCallback)
{
    EXIControl* exi;
    BOOL enabled;
    int i;

    exi = &Ecb[chan];
    ASSERTLINE(0x3F2, 0 <= chan && chan < MAX_CHAN);
    ASSERTLINE(0x3F3, chan == 0 && dev < MAX_DEV || dev == 0);
    enabled = OSDisableInterrupts();

    if (exi->state & STATE_LOCKED) {
        if (unlockedCallback) {
            ASSERTLINE(0x3F9, chan == 0 && exi->items < (MAX_DEV - 1) || exi->items == 0);
            for (i = 0; i < exi->items; i++) {
                if (exi->queue[i].dev == dev) {
                    OSRestoreInterrupts(enabled);
                    return 0;
                }
            }
            exi->queue[exi->items].callback = unlockedCallback;
            exi->queue[exi->items].dev = dev;
            exi->items++;
        }
        OSRestoreInterrupts(enabled);
        return 0;
    }
    ASSERTLINE(0x409, exi->items == 0);
    exi->state |= STATE_LOCKED;
    exi->dev = dev;
    SetExiInterruptMask(chan, exi);
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma pop

/* ---- EXIUnlock ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:539
int EXIUnlock(s32 chan)
{
    EXIControl* exi;
    BOOL enabled;
    EXICallback unlockedCallback;

    exi = &Ecb[chan];
    ASSERTLINE(0x421, 0 <= chan && chan < MAX_CHAN);
    enabled = OSDisableInterrupts();
    if (!(exi->state & STATE_LOCKED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~STATE_LOCKED;
    SetExiInterruptMask(chan, exi);
    if (exi->items > 0) {
        unlockedCallback = exi->queue[0].callback;
        if (--exi->items > 0) {
            memmove(&exi->queue[0], &exi->queue[1], exi->items * 8);
        }
        unlockedCallback(chan, 0);
    }
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma pop

/* ---- EXIGetState ---- */
#pragma push
#pragma force_active on
// provenance: dolsdk2001:src/os/OSExi.c:564
u32 EXIGetState(s32 chan)
{
    EXIControl* exi = &Ecb[chan];

    ASSERTLINE(0x446, 0 <= chan && chan < MAX_CHAN);
    return exi->state;
}
#pragma pop

/* ---- UnlockedHandler ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:706
void UnlockedHandler(s32 chan, OSContext* context)
{
    u32 id;

    EXIGetID(chan, 0, &id);
}
#pragma pop

/* ---- EXIGetID ---- */
#pragma push
#pragma force_active on
// provenance: mkdd:libs/dolphin/exi/EXIBios.c:713
int EXIGetID(s32 chan, u32 dev, u32* id)
{
    EXIControl* exi = &Ecb[chan];
    BOOL err;
    u32 cmd;
    s32 startTime;
    BOOL enabled;
    BOOL interrupt;

    if (chan == 0 && dev == 2 && IDSerialPort1) {
        *id = IDSerialPort1;
        return 1;
    }

    if (chan < 2 && dev == 0) {
        if (!__EXIProbe(chan)) {
            return 0;
        }

        if (exi->idTime == __EXIProbeStartTime[chan]) {
            *id = exi->id;
            return exi->idTime;
        }

        if (!__EXIAttach(chan, 0)) {
            return 0;
        }
        startTime = __EXIProbeStartTime[chan];
    }

    interrupt = OSDisableInterrupts();
    err = !EXILock(chan, dev, (chan < 2 && dev == 0) ? UnlockedHandler : 0);
    if (!err) {
        err = !EXISelect(chan, dev, EXI_FREQ_1M);
        if (!err) {
            cmd = 0;
            err |= !EXIImm(chan, &cmd, 2, EXI_WRITE, 0);
            err |= !EXISync(chan);
            err |= !EXIImm(chan, id, 4, EXI_READ, 0);
            err |= !EXISync(chan);
            err |= !EXIDeselect(chan);
        }
        EXIUnlock(chan);
    }
    OSRestoreInterrupts(interrupt);

    if (chan < 2 && dev == 0) {
        EXIDetach(chan);
        enabled = OSDisableInterrupts();
        err |= (startTime != __EXIProbeStartTime[chan]);
        if (!err) {
            exi->id = *id;
            exi->idTime = startTime;
        }
        OSRestoreInterrupts(enabled);

        return err ? 0 : exi->idTime;
    }

    return err ? 0 : !0;
}
#pragma pop

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
asm void __OSEnableBarnacle(register s32 chan, register u32 dev)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    addi        r31, r4, 0x0
    addi        r5, r1, 0x10
    stw         r30, 0x18(r1)
    addi        r30, r3, 0x0
    bl          EXIGetID
    cmpwi       r3, 0x0
    beq         L_80015794
    lwz         r4, 0x10(r1)
    lis         r0, 0x102
    cmpw        r4, r0
    beq         L_80015794
    bge         L_800156C0
    cmpwi       r4, 0x4
    beq         L_80015794
    bge         L_8001568C
    lis         r3, 0x8000
    addi        r0, r3, 0x10
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015670
    addi        r0, r3, 0x8
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    addi        r0, r3, 0x4
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015670:
    cmpwi       r4, -0x1
    beq         L_80015794
    bge         L_80015764
    addi        r0, r3, 0x20
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_8001568C:
    cmpwi       r4, 0x20
    beq         L_80015794
    bge         L_800156B0
    cmpwi       r4, 0x10
    beq         L_80015794
    bge         L_80015764
    cmpwi       r4, 0x8
    beq         L_80015794
    b           L_80015764
L_800156B0:
    lis         r0, 0x101
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_800156C0:
    lis         r3, 0x404
    addi        r0, r3, 0x404
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015728
    lis         r3, 0x402
    addi        r0, r3, 0x100
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015708
    lis         r0, 0x301
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    lis         r0, 0x202
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015708:
    addi        r0, r3, 0x300
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    addi        r0, r3, 0x200
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015728:
    lis         r0, 0x413
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015758
    lis         r0, 0x412
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    lis         r0, 0x406
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015758:
    lis         r0, 0x422
    cmpw        r4, r0
    beq         L_80015794
L_80015764:
    addi        r3, r30, 0x0
    addi        r4, r31, 0x0
    addi        r5, r1, 0x10
    bl          __EXIGetID
    cmpwi       r3, 0x0
    beq         L_80015794
    lis         r3, 0xa5ff
    stw	r30, lbl_801A6840 /* lbl_801A6840@sda21 */
    addi        r0, r3, 0x5a
    stw	r31, lbl_801A6844 /* lbl_801A6844@sda21 */
    stw	r0, lbl_801A684C /* lbl_801A684C@sda21 */
    stw	r0, lbl_801A6848 /* lbl_801A6848@sda21 */
L_80015794:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- InitializeUART ---- */
#pragma push
#pragma force_active on
asm int InitializeUART(register unsigned long baud_rate)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x8(r1)
    lwz	r3, lbl_801A684C /* lbl_801A684C@sda21 */
    addis       r0, r3, 0x5a01
    cmplwi      r0, 0x5a
    bne         L_800157D0
    li          r3, 0x0
    b           L_8001580C
L_800157D0:
    bl          OSGetConsoleType
    rlwinm.     r0, r3, 0, 3, 3
    bne         L_800157EC
    li          r0, 0x0
    stw	r0, lbl_801A6848 /* lbl_801A6848@sda21 */
    li          r3, 0x2
    b           L_8001580C
L_800157EC:
    lis         r3, 0xa5ff
    addi        r0, r3, 0x5a
    li          r3, 0x0
    stw	r0, lbl_801A6848 /* lbl_801A6848@sda21 */
    li          r0, 0x1
    stw	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r3, 0x0
    stw	r0, lbl_801A6844 /* lbl_801A6844@sda21 */
L_8001580C:
    lwz         r0, 0xc(r1)
    addi        r1, r1, 0x8
    mtlr        r0
    blr
}
#pragma pop

/* ---- WriteUARTN ---- */
#pragma push
#pragma force_active on
asm int WriteUARTN(register void* buffer, register s32 len)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x38(r1)
    stmw        r25, 0x1c(r1)
    addi        r30, r3, 0x0
    addi        r31, r4, 0x0
    lwz	r5, lbl_801A6848 /* lbl_801A6848@sda21 */
    addis       r0, r5, 0x5a01
    cmplwi      r0, 0x5a
    beq         L_8001584C
    li          r3, 0x2
    b           L_80015A24
L_8001584C:
    bl          OSDisableInterrupts
    mr          r0, r3
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    lwz	r4, lbl_801A6844 /* lbl_801A6844@sda21 */
    mr          r27, r0
    li          r5, 0x0
    bl          EXILock
    cmpwi       r3, 0x0
    bne         L_80015880
    mr          r3, r27
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80015A24
L_80015880:
    addi        r4, r30, 0x0
    li          r3, 0xd
    b           L_800158A0
L_8001588C:
    lbz         r0, 0x0(r4)
    cmpwi       r0, 0xa
    bne         L_8001589C
    stb         r3, 0x0(r4)
L_8001589C:
    addi        r4, r4, 0x1
L_800158A0:
    subf        r0, r30, r4
    cmplw       r0, r31
    blt         L_8001588C
    lis         r0, 0xa001
    stw         r0, 0x14(r1)
    li          r25, 0x0
    lis         r29, 0x2001
    b           L_80015A08
L_800158C0:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r5, 0x3
    lwz	r4, lbl_801A6844 /* lbl_801A6844@sda21 */
    bl          EXISelect
    cmpwi       r3, 0x0
    bne         L_800158E0
    li          r0, -0x1
    b           L_80015938
L_800158E0:
    stw         r29, 0x10(r1)
    addi        r4, r1, 0x10
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r5, 0x4
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXISync
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    addi        r4, r1, 0x10
    li          r5, 0x1
    li          r6, 0x0
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXISync
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXIDeselect
    lwz         r0, 0x10(r1)
    srwi        r0, r0, 24
    subfic      r0, r0, 0x10
L_80015938:
    cmpwi       r0, 0x0
    mr          r26, r0
    bge         L_8001594C
    li          r25, 0x3
    b           L_80015A10
L_8001594C:
    cmpwi       r0, 0xc
    bge         L_8001595C
    cmplw       r0, r31
    blt         L_80015A08
L_8001595C:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r5, 0x3
    lwz	r4, lbl_801A6844 /* lbl_801A6844@sda21 */
    bl          EXISelect
    cmpwi       r3, 0x0
    bne         L_8001597C
    li          r25, 0x3
    b           L_80015A10
L_8001597C:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    addi        r4, r1, 0x14
    li          r5, 0x4
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXISync
    b           L_800159F0
L_800159A0:
    cmpwi       r26, 0x4
    bge         L_800159B0
    cmplw       r26, r31
    blt         L_80015A00
L_800159B0:
    cmplwi      r31, 0x4
    bge         L_800159C0
    mr          r28, r31
    b           L_800159C4
L_800159C0:
    li          r28, 0x4
L_800159C4:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    mr          r5, r28
    addi        r4, r30, 0x0
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    add         r30, r30, r28
    subf        r31, r28, r31
    subf        r26, r28, r26
    bl          EXISync
L_800159F0:
    cmpwi       r26, 0x0
    beq         L_80015A00
    cmplwi      r31, 0x0
    bne         L_800159A0
L_80015A00:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXIDeselect
L_80015A08:
    cmplwi      r31, 0x0
    bne         L_800158C0
L_80015A10:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXIUnlock
    mr          r3, r27
    bl          OSRestoreInterrupts
    mr          r3, r25
L_80015A24:
    lmw         r25, 0x1c(r1)
    lwz         r0, 0x3c(r1)
    addi        r1, r1, 0x38
    mtlr        r0
    blr
}
#pragma pop
