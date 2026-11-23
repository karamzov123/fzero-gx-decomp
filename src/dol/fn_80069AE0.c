#include "types.h"


/* --- dol/fn_80069AE0.c --- */
extern u32 lbl_801A6C80;
extern u32 fn_8006953C(void);

u32 fn_80069AE0(void) {
    u32 flags;

    flags = *(u32 *)(lbl_801A6C80 + 0x444);
    if ((flags & 0x40) == 0) {
        return fn_8006953C();
    }
    return flags;
}
