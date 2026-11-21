#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSInterrupt.h>
#include "types.h"

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

u32 WriteUARTN(const void *buf, unsigned long len);

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

extern char lbl_80123E10[24];
extern void OSReport(const char *, u32, ...);
extern void PPCHalt(void);

void __DBExceptionDestinationAux(void) {
    u32 context = *(u32 *)0xc0; /* fzgx-allow: A2 zero-page context pointer */
    void *exception_context = (void *)(context + 0x80000000);
    u8 pad[1] __attribute__((aligned(8)));

    OSReport(lbl_80123E10, context);
    OSDumpContext(exception_context);
    PPCHalt();
}
