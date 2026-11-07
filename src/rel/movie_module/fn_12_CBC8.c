#include "types.h"
#include "ppc_ops.h"

extern s32 fn_12_A660(s32, s32);
extern u32 lbl_12_bss_5280[3];
extern u32 lbl_12_bss_528C[25];
extern void fn_12_20178(u32);

s32 fn_12_CBC8(u32 arg0) {
    u32 v0;
    s32 v1;
    s32 t0;
    u32 movie;

    movie = arg0;
    lbl_12_bss_5280[0] = movie;
    if (movie == 0) {
        t0 = -1;
    } else if (*(s32 *)((u8 *)movie + 392) != 2) {
        t0 = -1;
    } else {
        t0 = 0;
    }
    if (t0 != 0) {
        return fn_12_A660(0, 0xFF030201);
    }
    fn_12_20178(movie);
    if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
        v1 = 0;
        for (v0 = 256; v0 != 0; v0--) {
            ppc_dcbi((void *)movie, v1);
            v1 += 32;
        }
    }
    *(u32 *)((u8 *)movie + 392) = 1;
    return 0;
}
