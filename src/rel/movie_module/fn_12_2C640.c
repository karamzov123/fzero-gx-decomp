#include "types.h"

struct fn_12_2C640_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
    u32 unk_4C;
};

extern int fn_12_21E94(void *, int);
extern int fn_12_21F28(void *, int);
extern int fn_12_2D73C(void *, int);
extern int fn_12_2F1D0(void *, int);
extern int fn_12_2F1F0(void *, int);
extern u32 fn_12_2F210(void *, u32, u32, u32, u32);
extern void fn_12_2D420(void *, u32, u32);
extern void fn_12_2D7DC(void *, int, int);

#define FIELD(off) (*(s32 *)((u8 *)arg0 + (off)))

#pragma opt_dead_assignments off
s32 fn_12_2C640(struct fn_12_2C640_Arg0 *arg0) {
    s32 tmp_fn_12_2D73C;
    struct { s32 value; } v0;
    int v4;
    int v2;
    int v3;
    struct { u32 value; } v1;
    u32 v5;
    int v6;
    int v7;
    int t1;
    int t2;
    int t15;
    int t1_2;
    int t16;
    int ready;
    s32 tmp_fn_12_2F1D0;
    s32 tmp_call7;
    v0.value = arg0->unk_48;
    v1.value = arg0->unk_4C;
    tmp_fn_12_2D73C = fn_12_2D73C(arg0, 5);
    if (tmp_fn_12_2D73C == 0) {
        v2 = 1;
    } else {
        t1 = fn_12_2F1F0(arg0, 6);
        tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 6);
        t2 = tmp_fn_12_2F1D0;
        v2 = t1 | t2;
    }
    tmp_fn_12_2D73C = fn_12_2D73C(arg0, 6);
    if (tmp_fn_12_2D73C == 0) {
        v3 = 1;
    } else {
        t1_2 = fn_12_2F1F0(arg0, 7);
        tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 7);
        t2 = tmp_fn_12_2F1D0;
        v3 = t1_2 | t2;
    }
    if (v2 == 0 || v3 == 0) ready = 0;
    else ready = 1;
    if (ready == 0) {
        return v0.value;
    }
    tmp_call7 = FIELD(0x9b4);
    if (tmp_call7 == 1 && fn_12_21E94(arg0, 1) == 0 && fn_12_21F28(arg0, 1) == 0) {
        FIELD(0x9b4) = 0;
    }
    if (FIELD(0x9b8) == 1 && fn_12_21E94(arg0, 2) == 0 && fn_12_21F28(arg0, 2) == 0) {
        FIELD(0x9b8) = 0;
    }
    fn_12_2D420(arg0, FIELD(0x9b4), FIELD(0x9b8));
    if (FIELD(0x9b8) == 0 && FIELD(0x9dc) == 2) {
        fn_12_2D7DC(arg0, 15, 1);
    }
    if (FIELD(0x9b4) == 0 && FIELD(0x9dc) == 1) {
        fn_12_2D7DC(arg0, 15, 2);
    }
    v3 = 0;
    if (FIELD(0x9b8) == 1) v3 |= 1;
    if (FIELD(0x9b4) == 1) v3 |= 2;
    switch (v3) {
    case 1: v4 = 1; break;
    case 2: v4 = 2; break;
    case 3: v4 = fn_12_2D73C(arg0, 25); break;
    default: v4 = 3; break;
    }
    fn_12_2D7DC(arg0, 25, v4);
    switch ((s32)v1.value) {
    case 2: v0.value = 2; break;
    case 3: v0.value = 3; break;
    case 4:
    case 6:
        if (FIELD(0x9d8) == 0) {
            ready = 1;
        } else if (FIELD(0x9b4) == 0) {
            ready = 1;
        } else if (FIELD(0xf2c) != 0) {
            ready = 1;
        } else if (FIELD(0xf48) >= FIELD(0xa54)) {
            ready = 1;
        } else {
            if (FIELD(0x9b8) == 0 && FIELD(0x9b4) == 0) {
                v6 = 1;
            } else {
                v6 = 0;
                tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 6);
                v0.value = tmp_fn_12_2F1D0;
                tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 7);
                v2 = tmp_fn_12_2F1D0;
                v7 = v2;
                tmp_fn_12_2D73C = fn_12_2D73C(arg0, 25);
                switch (tmp_fn_12_2D73C) {
                case 1: v6 = v7; break;
                case 2: v6 = v0.value; break;
                case 3: v6 = v7 | v0.value; break;
                case 0: v6 = v7 & v0.value; break;
                }
            }
            if (v6 != 0) ready = 1;
            else ready = 0;
        }
        if (ready) {
            fn_12_2F210(arg0, 7, 6, 0, 0);
            v0.value = 4;
        } else {
            v0.value = 3;
        }
        break;
    }
    return v0.value;
}
#pragma opt_dead_assignments reset

