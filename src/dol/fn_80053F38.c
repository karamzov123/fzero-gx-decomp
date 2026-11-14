#include "types.h"

typedef u32 (*fn_80053F38_Fn0)(u32, u32);
typedef u32 (*fn_80053F38_Fn1)(u32, u32);
typedef u32 (*fn_80053F38_Fn2)(u32, u32, u32, void *);
typedef u32 (*fn_80053F38_Fn3)(u32, u32, void *);
typedef u32 (*fn_80053F38_Fn4)(u32, u32, void *);
typedef u32 (*fn_80053F38_Fn5)(u32);

struct Sig_fn_80050180_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};
struct Sig_fn_800510C4_Arg0 {
    u8 pad_0[0x348];
    u32 unk_348;
};
struct Sig_fn_80050F74_Arg0 {
    u8 pad_0[0x345];
    u8 unk_345;
};
struct Sig_fn_800501EC_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};
struct Sig_fn_800589BC_Arg2 {
    u32 unk_0;
    u32 unk_4;
};
struct Sig_fn_800589BC_Arg3 {
    s32 unk_0;
    u32 unk_4;
};
struct fn_80053F38_Arg0 {
    u32 unk_0;
    u8 pad_4[1];
    u8 unk_5;
    u8 pad_6[1];
    u8 unk_7;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10[3];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 pad_28;
    s32 unk_2C;
    u32 unk_30;
    u32 pad_34[2];
    u32 unk_3C;
    u32 unk_40;
};

extern int fn_80050F64(u32);
extern int fn_80050F6C(u32);
extern s32 fn_80050180(struct Sig_fn_80050180_Arg0 *);
extern s32 fn_800510C4(struct Sig_fn_800510C4_Arg0 *);
extern u32 fn_800510D8(u32);
extern u32 fn_80050F74(struct Sig_fn_80050F74_Arg0 *);
extern u32 fn_80050F90(u32, u32, u32, u32);
extern int fn_80053A30(void);
extern void *memset(void *, int, u32);
extern u32 lbl_801873DC[4];
extern u32 fn_800589BC(u32, u32, struct Sig_fn_800589BC_Arg2 *, struct Sig_fn_800589BC_Arg3 *);
extern u32 fn_800501EC(struct Sig_fn_800501EC_Arg0 *);

void fn_80053F38(struct fn_80053F38_Arg0 *arg0) {
    struct Sig_fn_800589BC_Arg2 items[2];
    struct Sig_fn_800589BC_Arg3 temps[2];
    s32 total_2;
    struct { s32 value; } count;
    u32 stream;
    u32 *list;
    s32 size;
    s32 n;
    u32 second;
    u32 obj;
    u32 obj2;
    s32 i;
    struct { s32 value; } j;
    s32 total;
    u32 lo;
    s32 t;
    s32 lim;

    second = 0;
    list = arg0->unk_10;
    stream = arg0->unk_0;
    obj2 = arg0->unk_C;
    if ((s8)arg0->unk_7 == 1) {
        t = ((fn_80053F38_Fn0) * (u32 *)(*(u32 *)obj2 + 0x24))(obj2, 1);
        if (!(t)) {
            t = fn_80050180((struct Sig_fn_80050180_Arg0 *)arg0->unk_8);
            if (t == 1) {
                arg0->unk_5 = 3;
                return;
            }
        }
    }
    count.value = fn_80050F64(arg0->unk_0);
    size = fn_80050F6C(arg0->unk_0) / 8;
    obj = arg0->unk_10[0];
    t = ((fn_80053F38_Fn1) * (u32 *)(*(u32 *)obj + 0x24))(obj, 0);
    if (t / size < count.value) {
        return;
    }
    if (fn_800510C4((struct Sig_fn_800510C4_Arg0 *)stream) != 0) {
        lbl_801873DC[2] = fn_80053A30();
        t = fn_800510D8(stream);
        if (t == 1) {
            arg0->unk_5 = 3;
            return;
        }
        lbl_801873DC[3] = fn_80053A30();
    }
    n = fn_80050F74((struct Sig_fn_80050F74_Arg0 *)arg0->unk_0);
    memset(items, 0, 0x10);
    total = count.value * size;
    for (i = 0; i < n; i++) {
        ((fn_80053F38_Fn2) * (u32 *)(*(u32 *)list[i] + 0x18))(list[i], 0, total, &items[i]);
    }
    lo = items[0].unk_0;
    if (n == 2) {
        second = items[1].unk_0;
    }
    if ((s32)(items[0].unk_4 >> 1) != count.value) {
        while (1) {
        }
    }
    lbl_801873DC[0] = fn_80053A30();
    count.value = fn_80050F90(stream, lo, second, count.value);
    lbl_801873DC[1] = fn_80053A30();
    total = count.value * size;
    for (j.value = 0; j.value < n; j.value++) {
        fn_800589BC((u32)&items[j.value], total, &items[j.value], &temps[j.value]);
        ((fn_80053F38_Fn3) * (u32 *)(*(u32 *)list[j.value] + 0x20))(list[j.value], 1, &items[j.value]);
        ((fn_80053F38_Fn4) * (u32 *)(*(u32 *)list[j.value] + 0x1C))(list[j.value], 0, &temps[j.value]);
    }
    arg0->unk_1C += count.value;
    arg0->unk_20 = ((s32)fn_800501EC((struct Sig_fn_800501EC_Arg0 *)arg0->unk_8) + 7) / 8;
    arg0->unk_24 += count.value;
    arg0->unk_30 += count.value;
    total_2 = arg0->unk_2C;
    lim = total_2;
    if (lim < 0) {
        return;
    }
    if ((s32)arg0->unk_30 < lim) {
        return;
    }
    if (arg0->unk_3C == 0) {
        return;
    }
    ((fn_80053F38_Fn5)arg0->unk_3C)(arg0->unk_40);
}

