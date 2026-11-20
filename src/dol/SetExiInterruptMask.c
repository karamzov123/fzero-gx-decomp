#include <dolphin/exi/EXIPriv.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/os/OSTime.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os.h>
#pragma scheduling off

/* --- dol/SetExiInterruptMask.c --- */
__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt);

extern EXIControl Ecb[3];

void SetExiInterruptMask(s32 chan, EXIControl *exi) {
    EXIControl *exi2;
    exi2 = &Ecb[2];
    switch (chan) {
    case 0:
        if ((exi->exiCallback == 0 && exi2->exiCallback == 0) || (exi->state & 0x10)) {
            __OSMaskInterrupts((0x80000000u >> (9)) | (0x80000000u >> (15)));
        } else {
            __OSUnmaskInterrupts((0x80000000u >> (9)) | (0x80000000u >> (15)));
        }
        break;
    case 1:
        if (exi->exiCallback == 0 || (exi->state & 0x10)) {
            __OSMaskInterrupts((0x80000000u >> (12)));
        } else {
            __OSUnmaskInterrupts((0x80000000u >> (12)));
        }
        break;
    case 2:
        if (__OSGetInterruptHandler(25) == 0 || (exi->state & 0x10)) {
            __OSMaskInterrupts((0x80000000u >> (25)));
        } else {
            __OSUnmaskInterrupts((0x80000000u >> (25)));
        }
        break;
    }
}

/* --- dol/EXIImm.c --- */
vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;


BOOL EXIImm(s32 chan, void *buf, s32 len, u32 type, EXICallback callback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & (0x01 | 0x02)) || !(exi->state & 0x04)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->tcCallback = callback;
    if (exi->tcCallback) {
        EXIClearInterrupts(chan, 0, 1, 0);
        __OSUnmaskInterrupts((0x80000000u >> (10)) >> (3 * chan));
    }
    exi->state |= 0x02;
    if (type != 0) {
        u32 data;
        int i;
        data = 0;
        for (i = 0; i < len; i++) {
            data |= ((u8 *)buf)[i] << ((3 - i) * 8);
        }
        (__EXIRegs[((chan) * 5) + (4)]) = data;
    }
    exi->immBuf = buf;
    exi->immLen = (type != 1) ? len : 0;
    (__EXIRegs[((chan) * 5) + (3)]) =
        ((((u32)(1)) << 0) | (((u32)(0)) << 1) | (((u32)(type)) << 2) | (((u32)(len - 1)) << 4));
    OSRestoreInterrupts(enabled);
    return 1;
}

/* --- dol/EXIImmEx.c --- */
BOOL EXIImmEx(s32 chan, void *buf, s32 len, u32 mode) {
    s32 xLen;
    while (len) {
        xLen = (len < 4) ? len : 4;
        if (!EXIImm(chan, buf, xLen, mode, ((void *)0))) {
            return 0;
        }
        if (!EXISync(chan)) {
            return 0;
        }
        (u8 *)buf += xLen;
        len -= xLen;
    }
    return 1;
}

/* --- dol/EXIDma.c --- */
BOOL EXIDma(s32 chan, void *buf, s32 len, u32 type, EXICallback callback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & (0x01 | 0x02)) || !(exi->state & 0x04)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->tcCallback = callback;
    if (exi->tcCallback) {
        EXIClearInterrupts(chan, 0, 1, 0);
        __OSUnmaskInterrupts((0x80000000u >> (10)) >> (3 * chan));
    }
    exi->state |= 0x01;
    (__EXIRegs[((chan) * 5) + (1)]) = (u32)buf & 0x3ffffe0;
    (__EXIRegs[((chan) * 5) + (2)]) = (u32)len;
    (__EXIRegs[((chan) * 5) + (3)]) =
        ((((u32)(1)) << 0) | (((u32)(1)) << 1) | (((u32)(type)) << 2) | (((u32)(0)) << 4));
    OSRestoreInterrupts(enabled);
    return 1;
}

/* --- dol/EXISync.c --- */
u32 OSGetConsoleType();



static inline void CompleteTransfer(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    u8 *buf;
    u32 data;
    int i;
    int len;
    if (exi->state & (0x01 | 0x02)) {
        if ((exi->state & 0x02) && (len = exi->immLen)) {
            buf = exi->immBuf;
            data = (__EXIRegs[((chan) * 5) + (4)]);
            for (i = 0; i < len; i++) {
                *buf++ = (u8)((data >> ((3 - i) * 8)) & 0xff);
            }
        }
        exi->state &= ~(0x01 | 0x02);
    }
}

extern u32 __OSGetDIConfig(void);

vu16 __OSDeviceCode : FZGX_ADDR___OSDeviceCode;

BOOL EXISync(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL rc = 0;
    BOOL enabled;
    while (exi->state & 0x04) {
        if ((((__EXIRegs[((chan) * 5) + (3)]) & 1) >> 0) == 0) {
            enabled = OSDisableInterrupts();
            if (exi->state & 0x04) {
                CompleteTransfer(chan);
                if (__OSGetDIConfig() != 0xff || ((OSGetConsoleType() & 0xf0000000) == 0x20000000) ||
                    exi->immLen != 4 ||
                    ((__EXIRegs[((chan) * 5) + (0)]) & 0x00000070) != (0 << 4) ||
                    ((__EXIRegs[((chan) * 5) + (4)]) != 0x01010000 &&
                     (__EXIRegs[((chan) * 5) + (4)]) != 0x05070000 &&
                     (__EXIRegs[((chan) * 5) + (4)]) != 0x04220001) ||
                    __OSDeviceCode == 0x8200) {
                    rc = 1;
                }
            }
            OSRestoreInterrupts(enabled);
            break;
        }
    }
    return rc;
}

/* --- dol/EXIClearInterrupts.c --- */
u32 EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext) {
    u32 cpr;
    u32 prev;
    prev = cpr = (__EXIRegs[((chan) * 5) + (0)]);
    cpr &= 0x7f5;
    if (exi)
        cpr |= 2;
    if (tc)
        cpr |= 8;
    if (ext)
        cpr |= 0x800;
    (__EXIRegs[((chan) * 5) + (0)]) = cpr;
    return prev;
}

/* --- dol/EXISetExiCallback.c --- */
void SetExiInterruptMask(s32 chan, EXIControl *exi);

EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback) {
    EXIControl *exi = &Ecb[chan];
    EXICallback prev;
    BOOL enabled;
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

/* --- dol/__EXIProbe.c --- */
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

OSTime OSGetTime(void);



s32 __EXIProbeStartTime[2] : FZGX_ADDR___EXIProbeStartTime;



BOOL __EXIProbe(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    BOOL rc;
    u32 cpr;
    s32 t;
    if (chan == 2) {
        return 1;
    }
    rc = 1;
    enabled = OSDisableInterrupts();
    cpr = (__EXIRegs[((chan) * 5) + (0)]);
    if (!(exi->state & 0x08)) {
        if (cpr & 0x00000800) {
            EXIClearInterrupts(chan, 0, 0, 1);
            __EXIProbeStartTime[chan] = exi->idTime = 0;
        }
        if (cpr & 0x00001000) {
            t = (s32)(((OSGetTime()) / (((u32)__OSBusClock / 4) / 1000)) / 100) + 1;
            if (__EXIProbeStartTime[chan] == 0) {
                __EXIProbeStartTime[chan] = t;
            }
            if (t - __EXIProbeStartTime[chan] < 300 / 100) {
                rc = 0;
            }
        } else {
            __EXIProbeStartTime[chan] = exi->idTime = 0;
            rc = 0;
        }
    } else if (!(cpr & 0x00001000) || (cpr & 0x00000800)) {
        __EXIProbeStartTime[chan] = exi->idTime = 0;
        rc = 0;
    }
    OSRestoreInterrupts(enabled);
    return rc;
}

/* --- dol/EXIProbe.c --- */
s32 EXIGetID(s32 chan, u32 dev, u32 *id);


BOOL __EXIProbe(s32 chan);

BOOL EXIProbe(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL rc;
    u32 id;
    rc = __EXIProbe(chan);
    if (rc && exi->idTime == 0) {
        rc = EXIGetID(chan, 0, &id) ? 1 : 0;
    }
    return rc;
}

/* --- dol/EXIProbeEx.c --- */
s32 EXIGetID(s32 chan, u32 dev, u32 *id);



BOOL __EXIProbe(s32 chan);



s32 EXIProbeEx(s32 chan) {
    if (EXIProbe(chan)) {
        return 1;
    } else if (__EXIProbeStartTime[chan] != 0) {
        return 0;
    } else {
        return -1;
    }
}

/* --- dol/EXIAttach.c --- */
s32 EXIGetID(s32 chan, u32 dev, u32 *id);


BOOL __EXIProbe(s32 chan);


static inline BOOL __EXIAttach(s32 chan, EXICallback extCallback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & 0x08) || __EXIProbe(chan) == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    EXIClearInterrupts(chan, 1, 0, 0);
    exi->extCallback = extCallback;
    __OSUnmaskInterrupts((0x80000000u >> (11)) >> (3 * chan));
    exi->state |= 0x08;
    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL EXIAttach(s32 chan, EXICallback extCallback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    BOOL rc;
    EXIProbe(chan);
    enabled = OSDisableInterrupts();
    if (exi->idTime == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    rc = __EXIAttach(chan, extCallback);
    OSRestoreInterrupts(enabled);
    return rc;
}

/* --- dol/EXIDetach.c --- */
BOOL EXIDetach(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x08)) {
        OSRestoreInterrupts(enabled);
        return 1;
    }
    if ((exi->state & 0x10) && exi->dev == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~0x08;
    __OSMaskInterrupts(((0x80000000u >> (11)) | (0x80000000u >> (9))) >> (3 * chan));
    OSRestoreInterrupts(enabled);
    return 1;
}

/* --- dol/EXISelect.c --- */
BOOL __EXIProbe(s32 chan);

BOOL EXISelect(s32 chan, u32 dev, u32 freq) {
    EXIControl *exi = &Ecb[chan];
    u32 cpr;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & 0x04) ||
        chan != 2 && (dev == 0 && !(exi->state & 0x08) && !__EXIProbe(chan) ||
                      !(exi->state & 0x10) || (exi->dev != dev))) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state |= 0x04;
    cpr = (__EXIRegs[((chan) * 5) + (0)]);
    cpr &= 0x405;
    cpr |= ((1u << (dev)) << 7) | ((freq) << 4);
    (__EXIRegs[((chan) * 5) + (0)]) = cpr;
    if (exi->state & 0x08) {
        switch (chan) {
        case 0:
            __OSMaskInterrupts((0x80000000u >> (11)));
            break;
        case 1:
            __OSMaskInterrupts((0x80000000u >> (14)));
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

/* --- dol/EXIDeselect.c --- */
BOOL __EXIProbe(s32 chan);

BOOL EXIDeselect(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    u32 cpr;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x04)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~0x04;
    cpr = (__EXIRegs[((chan) * 5) + (0)]);
    (__EXIRegs[((chan) * 5) + (0)]) = cpr & 0x405;
    if (exi->state & 0x08) {
        switch (chan) {
        case 0:
            __OSUnmaskInterrupts((0x80000000u >> (11)));
            break;
        case 1:
            __OSUnmaskInterrupts((0x80000000u >> (14)));
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    if (chan != 2 && (cpr & ((1u << (0)) << 7))) {
        return __EXIProbe(chan) ? 1 : 0;
    }
    return 1;
}

/* --- dol/EXIIntrruptHandler.c --- */
void OSSetCurrentContext(OSContext *context);




void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    s32 chan;
    EXIControl *exi;
    EXICallback callback;
    chan = (interrupt - 9) / 3;
    exi = &Ecb[chan];
    EXIClearInterrupts(chan, 1, 0, 0);
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

/* --- dol/TCIntrruptHandler.c --- */
void OSSetCurrentContext(OSContext *context);





void TCIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    OSContext exceptionContext;
    s32 chan;
    EXIControl *exi;
    EXICallback callback;
    chan = (interrupt - 10) / 3;
    exi = &Ecb[chan];
    __OSMaskInterrupts((0x80000000u >> (interrupt)));
    EXIClearInterrupts(chan, 0, 1, 0);
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

/* --- dol/EXTIntrruptHandler.c --- */
void OSSetCurrentContext(OSContext *context);


void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    s32 chan;
    EXIControl *exi;
    EXICallback callback;
    chan = (interrupt - 11) / 3;
    __OSMaskInterrupts(((0x80000000u >> (11)) | (0x80000000u >> (9))) >> (3 * chan));
    exi = &Ecb[chan];
    callback = exi->extCallback;
    exi->state &= ~0x08;
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

/* --- dol/EXIInit.c --- */
void OSRegisterVersion(const char *id);

extern BOOL __OSInIPL;

s32 EXIGetID(s32 chan, u32 dev, u32 *id);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);


extern const char *__EXIVersion;


extern u32 IDSerialPort1;


BOOL __EXIProbe(s32 chan);

void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext *context);

void TCIntrruptHandler(__OSInterrupt interrupt, OSContext *context);

void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext *context);

void EXIInit(void) {
    u32 id;
    while ((((__EXIRegs[((0) * 5) + (3)]) & 0x1) == 1) ||
           (((__EXIRegs[((1) * 5) + (3)]) & 0x1) == 1) ||
           (((__EXIRegs[((2) * 5) + (3)]) & 0x1) == 1)) {
        continue;
    }
    __OSMaskInterrupts((0x80000000u >> (9)) | (0x80000000u >> (10)) | (0x80000000u >> (11)) |
                       (0x80000000u >> (12)) | (0x80000000u >> (13)) | (0x80000000u >> (14)) |
                       (0x80000000u >> (15)) | (0x80000000u >> (16)));
    (__EXIRegs[((0) * 5) + (0)]) = 0;
    (__EXIRegs[((1) * 5) + (0)]) = 0;
    (__EXIRegs[((2) * 5) + (0)]) = 0;
    (__EXIRegs[((0) * 5) + (0)]) = 0x00002000;
    __OSSetInterruptHandler(9, EXIIntrruptHandler);
    __OSSetInterruptHandler(10, TCIntrruptHandler);
    __OSSetInterruptHandler(11, EXTIntrruptHandler);
    __OSSetInterruptHandler(12, EXIIntrruptHandler);
    __OSSetInterruptHandler(13, TCIntrruptHandler);
    __OSSetInterruptHandler(14, EXTIntrruptHandler);
    __OSSetInterruptHandler(15, EXIIntrruptHandler);
    __OSSetInterruptHandler(16, TCIntrruptHandler);
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

/* --- dol/EXILock.c --- */
void SetExiInterruptMask(s32 chan, EXIControl *exi);

BOOL EXILock(s32 chan, u32 dev, EXICallback unlockedCallback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    int i;
    enabled = OSDisableInterrupts();
    if (exi->state & 0x10) {
        if (unlockedCallback) {
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
    exi->state |= 0x10;
    exi->dev = dev;
    SetExiInterruptMask(chan, exi);
    OSRestoreInterrupts(enabled);
    return 1;
}

/* --- dol/EXIUnlock.c --- */
void SetExiInterruptMask(s32 chan, EXIControl *exi);

BOOL EXIUnlock(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    EXICallback unlockedCallback;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x10)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~0x10;
    SetExiInterruptMask(chan, exi);
    if (0 < exi->items) {
        unlockedCallback = exi->queue[0].callback;
        if (0 < --exi->items) {
            memmove(&exi->queue[0], &exi->queue[1], sizeof(exi->queue[0]) * exi->items);
        }
        unlockedCallback(chan, 0);
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

/* --- dol/EXIGetState.c --- */
u32 EXIGetState(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    return (u32)exi->state;
}

/* --- dol/UnlockedHandler.c --- */
s32 EXIGetID(s32 chan, u32 dev, u32 *id);

void UnlockedHandler(s32 chan, OSContext *context) {
    u32 id;
    EXIGetID(chan, 0, &id);
}

/* --- dol/EXIGetID.c --- */
void SetExiInterruptMask(s32 chan, EXIControl *exi);

BOOL __EXIProbe(s32 chan);






void UnlockedHandler(s32 chan, OSContext *context);

s32 EXIGetID(s32 chan, u32 dev, u32 *id) {
    EXIControl *exi = &Ecb[chan];
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
        if (!__EXIAttach(chan, ((void *)0))) {
            return 0;
        }
        startTime = __EXIProbeStartTime[chan];
    }
    interrupt = OSDisableInterrupts();
    err = !EXILock(chan, dev, (chan < 2 && dev == 0) ? UnlockedHandler : ((void *)0));
    if (!err) {
        err = !EXISelect(chan, dev, 0);
        if (!err) {
            cmd = 0;
            err |= !EXIImm(chan, &cmd, 2, 1, ((void *)0));
            err |= !EXISync(chan);
            err |= !EXIImm(chan, id, 4, 0, ((void *)0));
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
