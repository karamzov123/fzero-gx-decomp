#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSInterrupt.h>
#include "types.h"


/* --- dol/WriteUARTN.c --- */
extern s32 lbl_801A6840;

extern u32 lbl_801A6844;

extern u32 lbl_801A6848;

static inline int QueueLength(void) {
    u32 cmd;
    if (!EXISelect(lbl_801A6840, lbl_801A6844, 3))
        return -1;
    cmd = 0x800400u << 6;
    EXIImm(lbl_801A6840, &cmd, 4, 1, ((void *)0));
    EXISync(lbl_801A6840);
    EXIImm(lbl_801A6840, &cmd, 1, 0, ((void *)0));
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
        EXIImm(lbl_801A6840, &cmd, 4, 1, ((void *)0));
        EXISync(lbl_801A6840);
        while (qLen && len) {
            if (qLen < 4 && qLen < len)
                break;
            xLen = (len < 4) ? (long)len : 4;
            EXIImm(lbl_801A6840, (void *)buf, xLen, 1, ((void *)0));
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

/* --- dol/DBInit.c --- */
extern u32 __DBInterface;
extern u32 DBVerbose;
extern void __DBExceptionDestination(void);
void DBInit(void) {
    u32 *base;
    u32 t0;

    // fzgx-allow: A1 DB hardware register
    base = (u32 *)0x80000000;  /* fzgx-allow: A2 unnamed OS/hardware memory */
    t0 = (u32)base + 0x40;
    __DBInterface = t0;
    // fzgx-allow: A1 DB hardware register
    base[0x12] = (u32)__DBExceptionDestination + (u32)base;
    DBVerbose = 1;
}
