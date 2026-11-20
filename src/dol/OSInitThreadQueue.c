#include "types.h"


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
