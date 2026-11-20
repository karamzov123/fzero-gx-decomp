#include <types.h>
#include "types.h"


/* --- dol/misc_io.c --- */
void __stdio_atexit(void);

extern void (*__stdio_exit)(void);

void __close_all(void);

void __stdio_atexit(void) { __stdio_exit = __close_all; }

/* --- dol/fn_8008068C.c --- */
struct fn_8008068C_Arg0 {
    u8 pad_0[0x9];
    u8 unk_9;
    u8 unk_A;
};

void fn_8008068C(struct fn_8008068C_Arg0 *arg0) {
    arg0->unk_9 = 0;
    arg0->unk_A = 0;
}
