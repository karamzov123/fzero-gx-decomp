#include "types.h"


/* --- rel/movie_module/fn_12_2AD88.c --- */
extern u32 fn_12_24990(u32);
extern u32 fn_12_24A88(u32, u32);

s32 fn_12_2AD88(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_24990(arg0);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_24A88(v0, (0xFF000000 + 323));
    v0 = t1;
    } else {
    v0 = 0;
    *(u32 *)((u8 *)arg0 + 76) = 3;
    }
    return v0;
}

/* --- rel/movie_module/fn_12_2ADDC.c --- */
typedef struct Sig_fn_12_2DFF0_MovieModule {
    u8 pad_0[0x920];
    s32 movie_index;
    u8 pad_924[0xF24 - 0x924];
    s32 total_a;
    u8 pad_F28[0xF48 - 0xF28];
    s32 total_b;
    u8 pad_F4C[0xF58 - 0xF4C];
    s32 total_c;
    s32 movie_id;
} Sig_fn_12_2DFF0_MovieModule;
typedef u32 (*Sig_fn_12_2F210_fn_12_2F210_Fn0)(u32, u32, u32, u32);
struct Sig_fn_12_2F210_fn_12_2F210_arg0_1A90_E68 {
    u8 pad_0[0x1C];
    Sig_fn_12_2F210_fn_12_2F210_Fn0 *unk_1C;
    u8 pad_20[0x24];
};
struct Sig_fn_12_2F210_fn_12_2F210_Arg0 {
    u8 pad_0[0x1A90];
    struct Sig_fn_12_2F210_fn_12_2F210_arg0_1A90_E68 unk_1A90[1];
};
extern u32 fn_12_2F210(struct Sig_fn_12_2F210_fn_12_2F210_Arg0 *, u32, u32, u32, u32);
extern void fn_12_2DFF0(Sig_fn_12_2DFF0_MovieModule *, s32);

static inline u32 movie_action(u32 arg0, s32 action) {
    u32 result;
    u32 t;
    if ((s32)*(u32 *)((u8 *)arg0 + 76) != 3 && (s32)*(u32 *)((u8 *)arg0 + 76) != 4) {
        result = 0;
    } else {
        fn_12_2DFF0((Sig_fn_12_2DFF0_MovieModule *)arg0, action);
        t = fn_12_2F210((struct Sig_fn_12_2F210_fn_12_2F210_Arg0 *)arg0, 7, 8, action, 0);
        result = 0;
        if ((s32)t != 0) {
            result = t;
        }
    }
    return result;
}

u32 fn_12_2ADDC(u32 arg0, u32 arg1) {
    s32 v0;
    u32 v1;
    v0 = 0;
    switch ((s32)arg1) {
    case 2:
        if ((s32)*(u32 *)((u8 *)arg0 + 72) == 4) {
            v0 = movie_action(arg0, 2);
        }
        break;
    case 1:
        v1 = *(u32 *)((u8 *)arg0 + 84);
        *(u32 *)((u8 *)arg0 + 84) = v1 + 1;
        if ((s32)v1 == 0) {
            v0 = movie_action(arg0, 1);
        }
        break;
    case 0:
        if (--*(u32 *)((u8 *)arg0 + 84) == 0) {
            v0 = movie_action(arg0, 0);
        }
        break;
    }
    return v0;
}
