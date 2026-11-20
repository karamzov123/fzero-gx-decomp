#include "types.h"


/* --- rel/movie_module/fn_12_2D74C.c --- */
extern u32 lbl_12_bss_7C64[137];
extern int fn_12_24990(u8 *base, int index, u32 *out);
extern s32 fn_12_24A88(int arg0, u32 arg1);

u32 fn_12_2D74C(u8 *base, int index, u32 *out) {
    u8 *entry = base;

    if (base == 0) {
        *out = lbl_12_bss_7C64[index];
    } else if (fn_12_24990(base, index, out)) {
        return fn_12_24A88(0, 0xff000113u);
    } else {
        entry += index << 2;
        *out = *(u32 *)(entry + 0x9a0);
    }
    return 0;
}

/* --- rel/movie_module/fn_12_2D7DC.c --- */
extern int fn_12_2F1B4(u8 *base, int index);

void fn_12_2D7DC(u8 *base, int index, int value) {
    int allowed;

    if (index == 6 && value == 1 && fn_12_2F1B4(base, 3) == 0) {
        allowed = 0;
    } else if (index == 5 && value == 1 && fn_12_2F1B4(base, 2) == 0) {
        allowed = 0;
    } else {
        allowed = 1;
    }

    if (allowed != 0) {
        u8 *entry = base;
        entry += index << 2;
        *(int *)(entry + 0x9a0) = value;
    }
}
