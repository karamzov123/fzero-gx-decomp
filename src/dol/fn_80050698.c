#include "types.h"
#pragma optimize_for_size on
/* this TU keeps its constants out of small data (lis/lfd, not r2-relative) */
#pragma section sconst_type ".rodata" ".rodata" data_mode=far_abs
struct Sig_fn_800501F4_fn_800501F4_Arg0 {
    u8 pad_0[0x8]; s32 unk_8; s32 unk_C; s32 unk_10;
};
struct fn_80050698_Arg1 {
    u8 pad_0[4]; s32 unk_4; u8 pad_8[8]; s32 unk_10; s32 unk_14; u32 unk_18;
};
struct fn_80050698_lbl_80130A48 { f32 unk_0[1]; };
struct fn_80050698_lbl_80130B98 { u32 unk_0[1]; };
extern s32 fn_800501F4(struct Sig_fn_800501F4_fn_800501F4_Arg0 *, s32);
extern struct fn_80050698_lbl_80130A48 lbl_80130A48[];
extern struct fn_80050698_lbl_80130B98 lbl_80130B98[];
extern s8 lbl_80130C00[];
extern s8 lbl_80130C60[];
extern s8 lbl_80130DE0[];
extern u32 lbl_80186FA8[];
extern u32 lbl_80187114[];
void fn_80050698(void *arg0, struct fn_80050698_Arg1 *arg1, void *arg2, void *arg3, s32 arg4, void *arg5) {
    void *v13, *v12, *v11;
    void *v9, *v8, *v7;
    u32 v6;
    s32 v5;
    s32 v10;
    s32 v20;
    s32 v1, v2, v3;
    u32 v0;
    void *v4;
    s32 v14;
    u32 v16;
    f32 v17, v18, v19;
    u32 v22;
    s32 v26;
    f32 v30, v31;
    void *v36, *v33;
    s32 v34, v35;
    s32 t0, t1, t2, t3, t4;
    s8 *tp;
    s32 b;
    v0 = arg1->unk_18;
    v1 = arg1->unk_4;
    v2 = arg1->unk_10;
    v3 = arg1->unk_14;
    lbl_80187114[0] = 0;
    v4 = (u8 *)arg3 + (arg4 << 7);
    lbl_80186FA8[0] = 0;
    v5 = 0;
    v6 = v0;
    v9 = arg2;
    v7 = arg5;
    v8 = v4;
    while (v5 < v2) {
        v13 = v9;
        v12 = v8;
        v11 = v7;
        v10 = 0;
        while (v10 < (v5 < v3 ? v1 : 1)) {
            v14 = *(s32 *)v13;
            if (v14 != 0) {
                v16 = v6 + v14 * 24;
                v17 = lbl_80130A48[0].unk_0[*(u32 *)v12];
                v18 = *(f32 *)(v16 + 16) * v17;
                v19 = *(f32 *)(v16 + 20) * v17;
                if (*(s32 *)(v16 + 8) == 3) {
                    v20 = *(s32 *)(v16 + 4);
                    if (v20 <= 8) {
                        t0 = fn_800501F4(arg0, v20 + (v20 + v20));
                        v22 = lbl_80130B98[0].unk_0[v20];
                        *(f32 *)((u8 *)v11 + 256) = v18 * (f32)(s32)(t0 & v22) + v19;
                        t0 >>= v20;
                        *(f32 *)((u8 *)v11 + 128) = v18 * (f32)(s32)(t0 & v22) + v19;
                        t0 >>= v20;
                        *(f32 *)v11 = (f32)t0 * v18 + v19;
                    } else {
                        t1 = fn_800501F4(arg0, v20);
                        *(f32 *)v11 = (f32)t1 * v18 + v19;
                        t2 = fn_800501F4(arg0, v20);
                        *(f32 *)((u8 *)v11 + 128) = (f32)t2 * v18 + v19;
                        t3 = fn_800501F4(arg0, v20);
                        *(f32 *)((u8 *)v11 + 256) = (f32)t3 * v18 + v19;
                    }
                } else {
                    v26 = *(s32 *)v16;
                    t4 = fn_800501F4(arg0, *(s32 *)(v16 + 4));
                    if (v26 == 3) {
                        tp = &lbl_80130C00[t4];
                        b = tp[0];
                        *(f32 *)v11 = (f32)b * v18 + v19;
                        b = tp[32];
                        *(f32 *)((u8 *)v11 + 128) = (f32)b * v18 + v19;
                        b = tp[64];
                        *(f32 *)((u8 *)v11 + 256) = (f32)b * v18 + v19;
                    } else if (v26 == 5) {
                        tp = &lbl_80130C60[t4];
                        b = tp[0];
                        *(f32 *)v11 = (f32)b * v18 + v19;
                        b = tp[128];
                        *(f32 *)((u8 *)v11 + 128) = (f32)b * v18 + v19;
                        b = tp[256];
                        *(f32 *)((u8 *)v11 + 256) = (f32)b * v18 + v19;
                    } else if (v26 == 9) {
                        tp = &lbl_80130DE0[t4];
                        b = tp[0];
                        *(f32 *)v11 = (f32)b * v18 + v19;
                        b = tp[1024];
                        *(f32 *)((u8 *)v11 + 128) = (f32)b * v18 + v19;
                        b = tp[2048];
                        *(f32 *)((u8 *)v11 + 256) = (f32)b * v18 + v19;
                    } else {
                        t1 = t4 % v26;
                        *(f32 *)v11 = (f32)t1 * v18 + v19;
                        t4 /= v26;
                        t1 = t4 % v26;
                        *(f32 *)((u8 *)v11 + 128) = (f32)t1 * v18 + v19;
                        t4 /= v26;
                        t1 = t4 % v26;
                        *(f32 *)((u8 *)v11 + 256) = (f32)t1 * v18 + v19;
                    }
                }
            } else {
                v30 = 0.0f;
                *(f32 *)v11 = v30;
                *(f32 *)((u8 *)v11 + 128) = v30;
                *(f32 *)((u8 *)v11 + 256) = v30;
            }
            if (v1 == 2 && v5 >= v3) {
                *(f32 *)((u8 *)v7 + 384) = *(f32 *)v7;
                *(f32 *)((u8 *)v7 + 512) = *(f32 *)((u8 *)v7 + 128);
                *(f32 *)((u8 *)v7 + 640) = *(f32 *)((u8 *)v7 + 256);
            }
            v13 = (u8 *)v13 + 128;
            v12 = (u8 *)v12 + 384;
            v11 = (u8 *)v11 + 384;
            v10++;
        }
        v9 = (u8 *)v9 + 4;
        v8 = (u8 *)v8 + 4;
        v7 = (u8 *)v7 + 4;
        v6 += 384;
        v5++;
    }
    v31 = 0.0f;
    v33 = (u8 *)arg5 + v2 * 4;
    for (v34 = v2; v34 < 32; v34++) {
        v36 = v33;
        for (v35 = 0; v35 < v1; v35++) {
            *(f32 *)v36 = v31;
            *(f32 *)((u8 *)v36 + 128) = v31;
            *(f32 *)((u8 *)v36 + 256) = v31;
            v36 = (u8 *)v36 + 384;
        }
        v33 = (u8 *)v33 + 4;
    }
}
