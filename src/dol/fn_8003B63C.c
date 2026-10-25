#include "types.h"
struct T_ {
    u8 pad_0[0x10];
    u32 unk_10;
    s32 unk_14[0x12];
    u32 unk_5c[0x13];
};
struct R_ {
    u8 pad_0[0x420];
    struct T_ table[0x100];
};
struct BlockState_ {
    u8 dc_table;
    u8 ac_table;
    s16 predictor;
    u8 pad_4[0x2c];
};
struct BlockStates_ {
    u8 pad_0[0x6c4];
    struct BlockState_ block[0x100];
};
typedef struct D_ {
    u8 pad_10[0x10];
    u32 field_10;
    u8 pad_14[0x48];
    u32 field_5c[];
} D_;

extern u32 fn_8003B798(u32, u32);
extern s32 fn_8003B8A8(struct R_ *, u8);
extern s32 fn_8003B930(int, D_ *);
extern u8 lbl_8008FF50[];

void fn_8003B63C(u8 *self, u8 idx, s16 *out) {
    u8 *tab;
    D_ *d;
    s32 off;
    s32 n;
    struct BlockStates_ *state;
    s16 v;
    s32 i;
    s32 r;
    s32 m;
    s32 w;
    s32 t;
    u8 selector;

    __dcbz(out, 0);
    off = idx * 0x30;
    tab = self + off;
    selector = (tab[0x6c4] & 0x7F) << 1;
    __dcbz(out, 0x20);
    n = fn_8003B8A8((struct R_ *)self, selector);
    __dcbz(out, 0x40);
    v = 0;
    __dcbz(out, 0x60);
    d = (D_ *)(self + (u8)((tab[0x6c5] << 1) + 1) * 0xa8 + 0x420);
    if (n != 0) {
        v = (s16)fn_8003B798((u32)self, n & 0xFF);
        if ((s32)__cntlzw(v) > (s32)(32 - n)) {
            v = (-1 << n) + v;
            v++;
        }
    }
    {
        state = (struct BlockStates_ *)(self + off);
        v = state->block[0].predictor + v;
        state->block[0].predictor = v;
        out[0] = v;
    }
    i = 1;
    while (i < 64) {
        r = fn_8003B930((int)self, d);
        m = r & 0xF;
        t = r >> 4;
        if (m != 0) {
            i += t;
            w = fn_8003B798((u32)self, m);
            if ((s32)__cntlzw(w) > (s32)(32 - m)) {
                w = (-1 << m) + w;
                w++;
            }
            out[(lbl_8008FF50)[i]] = w;
        } else {
            if (t == 15) {
                i += 15;
            } else {
                break;
            }
        }
        i++;
    }
}
