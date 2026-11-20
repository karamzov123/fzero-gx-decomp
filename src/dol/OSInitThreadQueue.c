#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSThread.h>


/* --- dol/OSInitThreadQueue.c --- */
/* --- dol/OSInitThreadQueue.c --- */
struct OSInitThreadQueue_Arg0 {
    u32 unk_0;
    u32 unk_4;
};

void OSInitThreadQueue(struct OSInitThreadQueue_Arg0 *arg0) {
    arg0->unk_4 = 0;
    arg0->unk_0 = 0;
}

/* --- dol/fn_800102AC.c --- */
u32 fn_800102AC(void) {
    return *(u32 *)0x800000E4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/OSIsThreadTerminated.c --- */
BOOL OSIsThreadTerminated(OSThread *thread) {
    return thread->state == 8 || thread->state == 0 ? 1 : 0;
}
