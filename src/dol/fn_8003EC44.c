#include "sdk_addresses.h"
#include "types.h"

struct fn_8003EC44_Color { u8 r, g, b, a; };

struct fn_8003EC44_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
};

extern f32 lbl_801A6C64;
extern f32 lbl_801A6C70;
extern const f32 lbl_801A71C8;
extern const f32 lbl_801A71E4;
extern const f32 lbl_801A71F0;
extern const f32 lbl_801A71F4;
extern const f32 lbl_801A71F8;
extern const f32 lbl_801A71FC;
extern const f32 lbl_801A7200;
extern const f32 lbl_801A7204;
extern const f32 lbl_801A7208;
extern const f64 lbl_801A71D0;
extern void fn_80035828(u32, struct fn_8003EC44_Color *);
extern struct fn_8003EC44_Color lbl_801A65A8;
extern struct fn_8003EC44_Color lbl_801A65BC;
extern struct fn_8003EC44_Color lbl_801A65C0;
extern struct fn_8003EC44_Color lbl_801A65C4;
extern struct fn_8003EC44_Color lbl_801A65C8;
extern struct fn_8003EC44_Color lbl_801A65CC;
extern struct fn_8003EC44_Color lbl_801A65D0;
extern struct fn_8003EC44_Color lbl_801A65D4;
extern struct fn_8003EC44_Color lbl_801A65D8;
extern struct fn_8003EC44_Color lbl_801A65DC;
extern struct fn_8003EC44_Color lbl_801A65E0;
extern struct fn_8003EC44_Color lbl_801A65E4;
extern struct fn_8003EC44_Color lbl_801A65E8;
extern struct fn_8003EC44_Color lbl_801A65EC;
extern u32 lbl_801A65F4;
extern u32 lbl_801A65F8;
extern u32 lbl_801A65FC;
extern u32 lbl_801A6600[2];
extern u32 lbl_801A6C60;
extern u32 lbl_801A6C68;
extern void fn_8003462C(u32, u32, u32);
/* fzgx-allow: A1 SDK absolute-addressed OS clock global */
u32 __OSCoreClock : (0x80000000 + 0xFC);
/* fzgx-allow: A1 SDK absolute-addressed GX write-gather pipe */
volatile f32 __GXWGFifo : FZGX_ADDR_GXFIFO;

static inline f32 fn_8003EC44_Height(u32 ticks, f32 scale) {
    return lbl_801A71F4 * ((f32)ticks / ((f32)lbl_801A6C68 * scale));
}

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_8003EC44(struct fn_8003EC44_Arg0 *arg0) {
    f32 v18;
    u32 v0;
    u32 total;
    u32 v1;
    u32 v2;
    f32 v5;
    u32 v6;
    u32 v9;
    f32 v12;
    f32 v10;
    f32 v11;
    f32 v13;
    f32 v14;
    u32 v15;
    u32 v52;
    u32 v59;
    f32 v64;
    f32 v65;
    u32 v68;
    u32 v69;
    u32 v70;
    u32 v72;
    u32 fzgx_frame_pad_a[6];  /* fzgx: retail frame home */
    struct fn_8003EC44_Color c0;
    struct fn_8003EC44_Color c1;
    struct fn_8003EC44_Color c2;
    struct fn_8003EC44_Color c3;
    struct fn_8003EC44_Color c4;
    struct fn_8003EC44_Color c5;
    struct fn_8003EC44_Color c6;
    struct fn_8003EC44_Color c7;
    struct fn_8003EC44_Color c8;
    struct fn_8003EC44_Color c9;
    struct fn_8003EC44_Color c10;
    struct fn_8003EC44_Color c11;
    struct fn_8003EC44_Color c12;
    struct fn_8003EC44_Color c13;
    u32 fzgx_frame_pad_b[2];  /* fzgx: retail frame home */
    f32 loc_1C;
    u32 fzgx_frame_pad_c[4];  /* fzgx: retail frame home */
    v0 = arg0->unk_C;
    total = lbl_801A6C60;
    v1 = arg0->unk_10;
    v2 = (v1 - v0);
    v10 = (f32)(u32)v2 / (f32)(u32)(__OSCoreClock / 60);
    v11 = (f32)(lbl_801A71F0 + lbl_801A6C64);
    v5 = (f32)(lbl_801A71C8 * (f32)((f32)(u32)v0 / (f32)(u32)total));
    v12 = (f32)(lbl_801A71C8 * (f32)((f32)(u32)v1 / (f32)(u32)total));
    v13 = v5;
    loc_1C = (f32)(lbl_801A6C70 - v5);
    v6 = (*(u32 *)&loc_1C);
    v9 = (v6 & 0x7FFFFFFF);
    (*(u32 *)&loc_1C) = v9;
    if (loc_1C < lbl_801A71E4) {
        v13 = lbl_801A6C70;
    }
    lbl_801A6C70 = v12;
    v14 = loc_1C;
    v15 = 0x43300000;
    if ((s32)lbl_801A65F4 != 0) {
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 68) - *(u32 *)((u8 *)arg0 + 64), v10);
        if (v18 > lbl_801A71E4) {
            c0 = lbl_801A65C0;
            fn_80035828(4, &c0);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 76) - *(u32 *)((u8 *)arg0 + 72), v10);
        if (v18 > lbl_801A71E4) {
            c1 = lbl_801A65C4;
            fn_80035828(4, &c1);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 84) - *(u32 *)((u8 *)arg0 + 80), v10);
        if (v18 > lbl_801A71E4) {
            c2 = lbl_801A65C8;
            fn_80035828(4, &c2);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 92) - *(u32 *)((u8 *)arg0 + 88), v10);
        if (v18 > lbl_801A71E4) {
            c3 = lbl_801A65CC;
            fn_80035828(4, &c3);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 100) - *(u32 *)((u8 *)arg0 + 96), v10);
        if (v18 > lbl_801A71E4) {
            c4 = lbl_801A65D0;
            fn_80035828(4, &c4);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 108) - *(u32 *)((u8 *)arg0 + 104), v10);
        if (v18 > lbl_801A71E4) {
            c5 = lbl_801A65D4;
            fn_80035828(4, &c5);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 116) - *(u32 *)((u8 *)arg0 + 112), v10);
        if (v18 > lbl_801A71E4) {
            c6 = lbl_801A65D8;
            fn_80035828(4, &c6);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 124) - *(u32 *)((u8 *)arg0 + 120), v10);
        if (v18 > lbl_801A71E4) {
            c7 = lbl_801A65DC;
            fn_80035828(4, &c7);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 132) - *(u32 *)((u8 *)arg0 + 128), v10);
        if (v18 > lbl_801A71E4) {
            c8 = lbl_801A65E0;
            fn_80035828(4, &c8);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            v11 = (f32)(v11 + v18);
            __GXWGFifo = lbl_801A71F8;
        }
        *(u32 *)((u8 *)arg0 + 136) = ((u32)*(u32 *)((u8 *)arg0 + 136) >> 1);
        v52 = ((u32)*(u32 *)((u8 *)arg0 + 140) >> 1);
        *(u32 *)((u8 *)arg0 + 140) = v52;
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 140) - *(u32 *)((u8 *)arg0 + 136), v10);
        if (v18 > lbl_801A71E4) {
            c9 = lbl_801A65E4;
            fn_80035828(4, &c9);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo = v13;
            v14 = (f32)(v11 + v18);
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v11;
            __GXWGFifo = lbl_801A71F8;
        }
    }
    if ((s32)lbl_801A65F8 != 0) {
        v18 = (f32)(lbl_801A71F0 + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64)));
        v59 = (*(u32 *)((u8 *)arg0 + 36) - *(u32 *)((u8 *)arg0 + 32));
        v11 = lbl_801A71FC * (((f32)(u32)(*(u32 *)((u8 *)arg0 + 52) - *(u32 *)((u8 *)arg0 + 48)) / (f32)(u32)v2) / 2.0f);
        if (v11 > lbl_801A71E4) {
            c10 = lbl_801A65BC;
            fn_80035828(4, &c10);
            fn_8003462C(128, 0, 4);
            __GXWGFifo = v13;
            v14 = v18 + v11;
            __GXWGFifo = v18;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v18;
            __GXWGFifo = lbl_801A71F8;
        }
        c11 = lbl_801A65A8;
        fn_80035828(4, &c11);
        fn_8003462C(128, 0, 4);
        v64 = lbl_801A71FC + v18;
        v65 = v64 - (lbl_801A71FC * (f32)(u32)v59) / (f32)(u32)v2;
        __GXWGFifo = v13;
        __GXWGFifo = v65;
        __GXWGFifo = lbl_801A71F8;
        __GXWGFifo = v13;
        __GXWGFifo = v64;
        __GXWGFifo = lbl_801A71F8;
        __GXWGFifo = v12;
        __GXWGFifo = v64;
        __GXWGFifo = lbl_801A71F8;
        __GXWGFifo = v12;
        __GXWGFifo = v65;
        __GXWGFifo = lbl_801A71F8;
    }
    v2 = (*(u32 *)((u8 *)arg0 + 172) - *(u32 *)((u8 *)arg0 + 168));
    if ((s32)lbl_801A65FC != 0) {
        v18 = lbl_801A7204 + (lbl_801A71FC + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64)));
        v68 = (*(u32 *)((u8 *)arg0 + 148) - *(u32 *)((u8 *)arg0 + 144));
        v69 = (*(u32 *)((u8 *)arg0 + 156) - *(u32 *)((u8 *)arg0 + 152));
        v70 = v69 + v68;
        if (v2 >= v70) {
            v11 = (lbl_801A71FC * (f32)(u32)(v2 - v70)) / (f32)(u32)v2;
            if (v11 > lbl_801A71E4) {
                c12 = lbl_801A65E8;
                fn_80035828(4, &c12);
                fn_8003462C(128, 0, 4);
                __GXWGFifo = v13;
                v14 = v18 + v11;
                __GXWGFifo = v18;
                __GXWGFifo = lbl_801A71F8;
                __GXWGFifo = v13;
                __GXWGFifo = v14;
                __GXWGFifo = lbl_801A71F8;
                __GXWGFifo = v12;
                __GXWGFifo = v14;
                __GXWGFifo = lbl_801A71F8;
                __GXWGFifo = v12;
                __GXWGFifo = v18;
                __GXWGFifo = lbl_801A71F8;
            }
        }
    }
    if ((s32)lbl_801A6600[0] != 0) {
        v18 = lbl_801A71FC + (lbl_801A7208 + (lbl_801A71FC + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64))));
        v72 = (*(u32 *)((u8 *)arg0 + 164) - *(u32 *)((u8 *)arg0 + 160));
        v11 = (lbl_801A71FC * (f32)(u32)v72) / (f32)(u32)v2;
        if (v11 > lbl_801A71E4) {
            c13 = lbl_801A65EC;
            fn_80035828(4, &c13);
            fn_8003462C(128, 0, 4);
            __GXWGFifo = v13;
            v14 = v18 + v11;
            __GXWGFifo = v18;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v13;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v14;
            __GXWGFifo = lbl_801A71F8;
            __GXWGFifo = v12;
            __GXWGFifo = v18;
            __GXWGFifo = lbl_801A71F8;
        }
    }
}
