#include "types.h"


/* --- rel/movie_module/fn_12_2A308.c --- */
extern void fn_12_29FF8(void);

void fn_12_2A308(void) {
    fn_12_29FF8();
}

/* --- rel/movie_module/fn_12_2A328.c --- */
extern void fn_12_D038(void);

int fn_12_2A328(void) {
    fn_12_D038();
    return 0;
}

/* --- rel/movie_module/fn_12_2A34C.c --- */
extern u32 lbl_12_bss_96A0[28];
extern u8 lbl_12_bss_9710[73760];
extern s32 fn_12_24A88(void *module, u32 code);
extern s32 fn_12_D0B8(s32 id, void *buf);
extern void *memset(void *dst, int c, u32 n);

s32 fn_12_2A34C(void) {
    u32 *state;
    s32 a;
    s32 b;
    s32 err;

    state = lbl_12_bss_96A0;
    a = 0x50;
    b = 0x204;

    if (a != 0x50) {
        err = fn_12_24A88(0, 0xff000f1a);
    } else if (b > 0x204) {
        err = fn_12_24A88(0, 0xff000f1a);
    } else {
        err = 0;
    }

    if (err != 0) {
        for (;;) {
        }
    }

    err = fn_12_D0B8(8, lbl_12_bss_9710);
    if (err != 0) {
        fn_12_24A88(0, err == 0xff03ff05 ? 0xff000f13 : 0xff000f01);
    } else {
        memset((u8 *)state + 0x4c, 0, 0x24);
        memset((u8 *)state + 0x44, 0, 8);
        memset((u8 *)state + 4, 0, 0x40);
        state[0] = 0;
        return 0;
    }
}
