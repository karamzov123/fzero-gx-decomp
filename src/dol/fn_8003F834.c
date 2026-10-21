#include "types.h"

typedef enum Sig_fn_80035828__GXChannelID {
    Sig_fn_80035828_GX_COLOR0,
    Sig_fn_80035828_GX_COLOR1,
    Sig_fn_80035828_GX_ALPHA0,
    Sig_fn_80035828_GX_ALPHA1,
    Sig_fn_80035828_GX_COLOR0A0,
    Sig_fn_80035828_GX_COLOR1A1,
    Sig_fn_80035828_GX_COLOR_ZERO,
    Sig_fn_80035828_GX_ALPHA_BUMP,
    Sig_fn_80035828_GX_ALPHA_BUMPN,
    Sig_fn_80035828_GX_COLOR_NULL = 0xFF,
} Sig_fn_80035828_GXChannelID;
typedef struct Sig_fn_80035828__GXColor {
    u8 r, g, b, a;
} Sig_fn_80035828_GXColor;

extern f32 lbl_801A6C64;
extern const f32 lbl_801A71C8;
extern const f32 lbl_801A71E4;
extern const f32 lbl_801A71F0;
extern const f32 lbl_801A71F4;
extern const f32 lbl_801A71F8;
extern const f32 lbl_801A720C;
extern const f64 lbl_801A71D0;
extern u32 lbl_801A65C0;
extern u32 lbl_801A65C4;
extern u32 lbl_801A65C8;
extern u32 lbl_801A65CC;
extern u32 lbl_801A65D0;
extern u32 lbl_801A65D4;
extern u32 lbl_801A65D8;
extern u32 lbl_801A65DC;
extern u32 lbl_801A65E0;
extern u32 lbl_801A65E4;
extern u32 lbl_801A6C68;
extern void fn_80035828(Sig_fn_80035828_GXChannelID, Sig_fn_80035828_GXColor);
extern void fn_8003462C(u32, u32, u32);
volatile f32 GXWGFifo : 0xCC008000; /* fzgx-allow: A1 SDK absolute-addressed write-gather FIFO */


static inline void setBarColor(Sig_fn_80035828_GXColor color) {
    (void)color;
}

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_8003F834(void) {
    u8 scratch[24];
    u32 v0;
    u32 v2;
    f32 v4;
    f32 v6;
    f32 v7;
    f32 v12;
    f32 v17;
    f32 v22;
    f32 v27;
    f32 v32;
    f32 v37;
    f32 v42;
    f32 v47;
    f32 v52;
    v6 = (f32)(lbl_801A71F0 + lbl_801A6C64);
    v0 = lbl_801A6C68;
    v2 = v0 / 10;
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)v0 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65C0);
        fn_8003462C(128, 0, 4);
        v7 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v7;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v7;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65C4);
        fn_8003462C(128, 0, 4);
        v12 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v12;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v12;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65C8);
        fn_8003462C(128, 0, 4);
        v17 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v17;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v17;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65CC);
        fn_8003462C(128, 0, 4);
        v22 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v22;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v22;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65D0);
        fn_8003462C(128, 0, 4);
        v27 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v27;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v27;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65D4);
        fn_8003462C(128, 0, 4);
        v32 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v32;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v32;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65D8);
        fn_8003462C(128, 0, 4);
        v37 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v37;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v37;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65DC);
        fn_8003462C(128, 0, 4);
        v42 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v42;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v42;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65E0);
        fn_8003462C(128, 0, 4);
        v47 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v47;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v47;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        v6 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * ((f32)v2 / ((f32)lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(Sig_fn_80035828_GX_COLOR0A0, *(Sig_fn_80035828_GXColor *)&lbl_801A65E4);
        fn_8003462C(128, 0, 4);
        v52 = (f32)(v6 + v4);
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A720C;
        GXWGFifo = v52;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v52;
        GXWGFifo = lbl_801A71F8;
        GXWGFifo = lbl_801A71C8;
        GXWGFifo = v6;
        GXWGFifo = lbl_801A71F8;
    }
    {
        u8 padding[4];
    }
    if (0) {
        setBarColor(*(Sig_fn_80035828_GXColor *)&lbl_801A65E4);
    }
}
