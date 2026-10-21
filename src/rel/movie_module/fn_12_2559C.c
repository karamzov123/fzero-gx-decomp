#include "types.h"
struct Sig_fn_12_21F28_MovieEntry {
    int value;
    char padding[0x70];
};
struct Sig_fn_12_21F28_MovieModule {
    char padding[0x1174];
    struct Sig_fn_12_21F28_MovieEntry entries[1];
};
struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 { u32 unk_0; u8 pad_4[0x70]; };
struct Sig_fn_12_21D30_fn_12_21D30_Arg0 {
    u8 pad_0[0x114C];
    struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 unk_114C[1];
};
struct fn_12_2559C_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x1AC0];
    u32 unk_1AEC;
    u8 pad_1AF0[0x4];
    u32 unk_1AF4;
};
extern int fn_12_21F28(struct Sig_fn_12_21F28_MovieModule *, int);
extern s32 fn_12_231F8(u32);
extern u32 fn_12_21D30(struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *, u32);
extern u32 fn_12_23250(u32);
extern u32 fn_12_67A4(const u8 *);
extern void fn_12_21D40(void *, int, int);
#pragma opt_propagation off
s32 fn_12_2559C(struct fn_12_2559C_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v2;
    u32 v0;
    u32 v1;
    struct { u32 value; } code;
    s32 v4;
    u32 v3;
    u32 t0;
    int t1;
    u32 t7;
    v0 = arg0->unk_1AEC;
    v1 = arg0->unk_1AF4;
    v2 = arg0->unk_28;
    if ((s32)arg2 >= 4) {
        code.value = fn_12_67A4((const u8 *)arg1);
        v3 = code.value;
        if ((v3 - 0x80000) == 0) {
            if ((s32)*(u32 *)((u8 *)arg0 + 6916) < 0) {
                t1 = fn_12_21F28((struct Sig_fn_12_21F28_MovieModule *)arg0, v1);
                *(u32 *)((u8 *)arg0 + 6916) = t1 + 4;
            }
            *(u32 *)((u8 *)v0 + 48) = 1;
        } else if ((s32)v3 != 0) {
            *(u32 *)((u8 *)v0 + 48) = 0;
        }
    } else {
        v3 = 0;
    }
    if ((v3 - 0x80000) != 0) {
        v4 = 0;
    } else if ((s32)fn_12_23250((u32)arg0) != 0 || fn_12_231F8((u32)arg0) != 0) {
        v4 = 0;
    } else {
        v4 = 1;
    }
    if (v4 != 0) {
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6908), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6904), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6912), 1);
        return 0;
    }
    if ((s32)arg3 < 4 && (s32)fn_12_21D30((struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *)arg0, v1) == 1) {
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6908), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6904), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6912), 1);
        return 0;
    }
    if ((s32)arg2 < (s32)v2) {
        if ((v3 - 0x10000) == 0) {
            v4 = 0;
        } else {
            v4 = 1;
            if ((v3 - 0x40000) == 0) {
                v4 = 1;
            }
            return v4;
        }
    } else {
        v4 = 1;
    }
done:
    return v4;
}
