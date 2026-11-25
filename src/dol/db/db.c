#include "types.h"
#include <dolphin/os.h>

/* Dolphin SDK db/db.c. __DBExceptionDestination is a CodeWarrior asm function in the
 * original (it turns address translation back on with mtmsr and branches to the C handler,
 * no compiler frame); the rest is C. */

typedef struct DBInterface {
    u32 bPresent;
    u32 exceptionMask;
    void (*ExceptionDestination)(void);
    void *exceptionReturn;
} DBInterface;

extern DBInterface *__DBInterface;
extern BOOL DBVerbose;

void __DBExceptionDestination(void);

void DBInit(void) {
    u32 *base;
    u32 t0;

    // fzgx-allow: A1 DB hardware register
    base = (u32 *)0x80000000;  /* fzgx-allow: A2 unnamed OS/hardware memory */
    t0 = (u32)base + 0x40;
    __DBInterface = (DBInterface *)t0;
    // fzgx-allow: A1 DB hardware register
    base[0x12] = (u32)__DBExceptionDestination + (u32)base;
    DBVerbose = 1;
}

extern char lbl_80123E10[24];
extern void PPCHalt(void);
void OSReport(const char *msg, ...);

void __DBExceptionDestinationAux(void) {
    u32 context = *(u32 *)0xc0; /* fzgx-allow: A2 zero-page context pointer */
    void *exception_context = (void *)(context + 0x80000000);
    u8 pad[1] __attribute__((aligned(8)));

    OSReport(lbl_80123E10, context);
    OSDumpContext(exception_context);
    PPCHalt();
}

asm void __DBExceptionDestination(void) {
    nofralloc
    mfmsr r3
    ori r3, r3, 0x30
    mtmsr r3
    b __DBExceptionDestinationAux
}

u32 __DBIsExceptionMarked(u32 arg0) {
    return (__DBInterface->exceptionMask & (1 << (arg0 & 0xFF)));
}

void DBPrintf(const char *format, ...) {
}
