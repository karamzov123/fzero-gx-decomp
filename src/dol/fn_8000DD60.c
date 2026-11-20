#include "types.h"


/* --- dol/fn_8000DD60.c --- */
// fn_8000DD60: empty in retail (single blr).
void fn_8000DD60(void) {
}

/* --- dol/fn_8000DD64.c --- */
// fn_8000DD64: empty in retail (single blr).
void fn_8000DD64(void) {
}

/* --- dol/fn_8000DD68.c --- */
void fn_8000DD68(u32 arg0) {
    *(u32 *)0x800030D0 = arg0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}
