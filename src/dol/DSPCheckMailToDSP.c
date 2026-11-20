#include "types.h"


/* --- dol/DSPCheckMailToDSP.c --- */
u32 DSPCheckMailToDSP(void) {
    return ((*(u16 *)0xCC005000 >> 15) & 0x1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/DSPCheckMailFromDSP.c --- */
u32 DSPCheckMailFromDSP(void) {
    return ((*(u16 *)0xCC005004 >> 15) & 0x1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}
