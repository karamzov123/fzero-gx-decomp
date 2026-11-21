#include <dolphin/exi.h>
#include <dolphin/exi/EXIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSInterrupt.h>

s32 EXIGetID(s32 chan, u32 dev, u32 *id);
extern int OSGetConsoleType(void);

/* UART state (.sbss): channel, device, enable magic, Barnacle enable magic */
extern s32 lbl_801A6840;
extern u32 lbl_801A6844;
extern u32 lbl_801A6848;
extern u32 lbl_801A684C;

BOOL ProbeBarnacle(s32 chan, u32 dev, u32 *revision) {
    BOOL err;
    u32 cmd;
    if (chan != 2 && dev == 0 && !EXIAttach(chan, NULL)) {
        return 0;
    }
    err = !EXILock(chan, dev, NULL);
    if (!err) {
        err = !EXISelect(chan, dev, 0);
        if (!err) {
            cmd = 0x20011300;
            err = 0;
            err |= !EXIImm(chan, &cmd, 4, 1, NULL);
            err |= !EXISync(chan);
            err |= !EXIImm(chan, revision, 4, 0, NULL);
            err |= !EXISync(chan);
            err |= !EXIDeselect(chan);
        }
        EXIUnlock(chan);
    }
    if (chan != 2 && dev == 0) {
        EXIDetach(chan);
    }
    if (err) {
        return 0;
    }
    return (*revision != 0xFFFFFFFF) ? 1 : 0;
}

void __OSEnableBarnacle(s32 chan, u32 dev) {
    u32 id;
    if (EXIGetID(chan, dev, &id)) {
        switch (id) {
        case 0xffffffff:
        case 0x00000004:
        case 0x00000008:
        case 0x00000010:
        case 0x00000020:
        case 0x01010000:
        case 0x01020000:
        case 0x02020000:
        case 0x03010000:
        case 0x04220000:
        case 0x04020100:
        case 0x04020200:
        case 0x04020300:
        case 0x04040404:
        case 0x04060000:
        case 0x04120000:
        case 0x04130000:
        case 0x80000000 | 0x00000004:
        case 0x80000000 | 0x00000008:
        case 0x80000000 | 0x00000010:
        case 0x80000000 | 0x00000020:
            break;
        default:
            if (ProbeBarnacle(chan, dev, &id)) {
                lbl_801A6840 = chan;
                lbl_801A6844 = dev;
                lbl_801A6848 = lbl_801A684C = 0xa5ff005a;
            }
            break;
        }
    }
}

int InitializeUART(void) {
    if (lbl_801A684C == 0xA5FF005A) {
        return 0;
    }

    if ((OSGetConsoleType() & 0x10000000) == 0) {
        lbl_801A6848 = 0;
        return 2;
    }

    lbl_801A6848 = 0xA5FF005A;
    lbl_801A6840 = 0;
    lbl_801A6844 = 1;
    return 0;
}

static inline int QueueLength(void) {
    u32 cmd;
    if (!EXISelect(lbl_801A6840, lbl_801A6844, 3))
        return -1;
    cmd = 0x800400u << 6;
    EXIImm(lbl_801A6840, &cmd, 4, 1, NULL);
    EXISync(lbl_801A6840);
    EXIImm(lbl_801A6840, &cmd, 1, 0, NULL);
    EXISync(lbl_801A6840);
    EXIDeselect(lbl_801A6840);
    return 16 - (int)((cmd >> 24) & 0xff);
}

u32 WriteUARTN(const void *buf, unsigned long len) {
    BOOL enabled;
    u32 cmd;
    int qLen;
    long xLen;
    char *ptr;
    BOOL locked;
    u32 error;
    if (lbl_801A6848 != 0xa5ff005a)
        return 2;
    enabled = OSDisableInterrupts();
    locked = EXILock(lbl_801A6840, lbl_801A6844, 0);
    if (!locked) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    for (ptr = (char *)buf; ptr - buf < len; ptr++) {
        if (*ptr == '\n')
            *ptr = '\r';
    }
    error = 0;
    cmd = (0x800400u | 0x2000000) << 6;
    while (len) {
        qLen = QueueLength();
        if (qLen < 0) {
            error = 3;
            break;
        }
        if (qLen < 12 && qLen < len)
            continue;
        if (!EXISelect(lbl_801A6840, lbl_801A6844, 3)) {
            error = 3;
            break;
        }
        EXIImm(lbl_801A6840, &cmd, 4, 1, NULL);
        EXISync(lbl_801A6840);
        while (qLen && len) {
            if (qLen < 4 && qLen < len)
                break;
            xLen = (len < 4) ? (long)len : 4;
            EXIImm(lbl_801A6840, (void *)buf, xLen, 1, NULL);
            (u8 *)buf += xLen;
            len -= xLen;
            qLen -= xLen;
            EXISync(lbl_801A6840);
        }
        EXIDeselect(lbl_801A6840);
    }
    EXIUnlock(lbl_801A6840);
    OSRestoreInterrupts(enabled);
    return error;
}
