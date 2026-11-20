#include "types.h"


/* --- dol/fn_8006B92C.c --- */
typedef struct Fn8006B92CData {
    u8 pad_0[0xF4];
    void *items[64];
    u8 pad_1F4[0x1000];
    u32 unk_11F4;
} Fn8006B92CData;

extern u32 lbl_801A6C8C;
extern void fn_8006C7E8(void *arg0, void *arg1);
extern void fn_8006B99C(void);

void fn_8006B92C(Fn8006B92CData *arg0) {
    s32 i;

    fn_8006C7E8(arg0, arg0);
    arg0->unk_11F4 = 0xFF;
    for (i = 0; i < 64; i++) {
        arg0->items[i] = 0;
    }
    if ((s32)lbl_801A6C8C == 0) {
        fn_8006B99C();
        lbl_801A6C8C = 1;
    }
}

/* --- dol/fn_8006B99C.c --- */
extern const f32 lbl_801A7370;
extern const f32 lbl_801A7374;
extern const f32 lbl_801A7378;
extern const f32 lbl_801A737C;
extern const f64 lbl_801A7380;
extern u8 lbl_8019DF90[132];
extern f64 fn_80088598(f64, f64);

/* Power curve sample at x / 128; the conversions share one stack slot only when inlined. */
static inline f32 curve(s32 x) {
    return (f32)fn_80088598((f32)x * lbl_801A7370, lbl_801A7374);
}

void fn_8006B99C(void) {
    s32 v0;
    f32 v1;
    for (v0 = 0; v0 < 129; v0++) {
        if (v0 < 0) {
            v1 = -(lbl_801A7378 + lbl_801A737C * curve(-v0));
        } else {
            v1 = lbl_801A7378 + lbl_801A737C * curve(v0);
        }
        lbl_8019DF90[v0] = (s32)v1;
    }
}
