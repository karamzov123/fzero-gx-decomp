#include "types.h"
#include "psvec_quant.h"

struct ThpTable {
    u8 pad_0[0x10];
    u32 unk_10;
    s32 unk_14[0x12];
    u32 unk_5c[0x13];
};

struct ThpRoot {
    u8 pad_0[0x420];
    struct ThpTable table[0x100];
};

struct BlockState {
    u8 dc_table;
    u8 ac_table;
    s16 predictor;
    u8 pad_4[0x2c];
};

struct BlockStates {
    u8 pad_0[0x6c4];
    struct BlockState block[0x100];
};

extern u8 lbl_8008FF50[];
extern f32 lbl_801A7194;
extern f32 lbl_801A7198;
extern f32 lbl_801A719C;
extern f32 lbl_801A71A0;
extern s32 fn_8003D42C();

u32 fn_8003B798(u32 arg0, u32 arg1);
s32 fn_8003B8A8(struct ThpRoot *self, u8 index);
s32 fn_8003B930(int value, struct ThpTable *data);

void fn_8003B63C(u8 *self, u8 idx, s16 *out) {
    u8 *tab;
    struct ThpTable *d;
    s32 off;
    s32 n;
    struct BlockStates *state;
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
    n = fn_8003B8A8((struct ThpRoot *)self, selector);
    __dcbz(out, 0x40);
    v = 0;
    __dcbz(out, 0x60);
    d = (struct ThpTable *)(self + (u8)((tab[0x6c5] << 1) + 1) * 0xa8 + 0x420);
    if (n != 0) {
        v = fn_8003B798((u32)self, n & 0xFF);
        if (__cntlzw(v) > (32 - n)) {
            v = (-1 << n) + v;
            v++;
        }
    }
    {
        state = (struct BlockStates *)(self + off);
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
            if (__cntlzw(w) > (32 - m)) {
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

u32 fn_8003B798(u32 arg0, u32 arg1) {
    u32 v;
    u32 n;
    s32 i;

    v = fn_8003D42C(arg0, arg1);
    n = arg1 & 0xFF;
    if (n == 1) {
        return v;
    }
    if (n == 2) {
        return (v << 1) + fn_8003D42C(arg0);
    }
    if (n == 3) {
        v = (v << 1) + fn_8003D42C(arg0);
        return (v << 1) + fn_8003D42C(arg0);
    }
    v = (v << 1) + fn_8003D42C(arg0);
    v = (v << 1) + fn_8003D42C(arg0);
    v = (v << 1) + fn_8003D42C(arg0);
    if (n == 4) {
        return v;
    }
    for (i = 4; i < (s32)n; i++) {
        v = (v << 1) + fn_8003D42C(arg0);
    }
    return v;
}

s32 fn_8003B8A8(struct ThpRoot *self, u8 index) {
    struct ThpTable *table;
    s32 value;
    u32 i;

    table = &self->table[index];
    i = 1;
    value = fn_8003D42C(self);
    while (value > table->unk_14[i]) {
        value <<= 1;
        value |= fn_8003D42C(self);
        i++;
    }
    return ((u8 *)(value + table->unk_5c[i]))[table->unk_10];
}

s32 fn_8003B930(int value, struct ThpTable *data) {
    u8 *cursor;
    int result;
    int index;
    index = 1;
    result = fn_8003D42C(value);
    cursor = (u8 *)data + 4;

    while (result > *(int *)(cursor + 0x14)) {
        result <<= 1;
        result |= fn_8003D42C(value);
        cursor += 4;
        index += 1;
    }
    return *(u8 *)((((result) + (data->unk_5c[index])) + data->unk_10));
}

void fn_8003B9AC(register void *d, register void *a, register void *b, register void *c, u32 n) {
    register f32 k0 = lbl_801A7194;
    register f32 k1 = lbl_801A7198;
    register f32 k2 = lbl_801A719C;
    register f32 k3 = lbl_801A71A0;
    u32 i;

    for (i = 0; i < n; i += 4) {
        psq2_merge4(d, a, b, c, k0, k1, k2, k3)
    }
}

void fn_8003BB30(register void *d, register void *a, register void *b, register void *c, u32 n) {
    register f32 k0 = lbl_801A7194;
    register f32 k1 = lbl_801A7198;
    register f32 k2 = lbl_801A719C;
    register f32 k3 = lbl_801A71A0;
    register f32 t1, t2, t3;
    u32 i;

    psq27_merge2_setup(k1, k2, k3)
    for (i = 0; i < n; i += 2) {
        psq27_merge2(d, a, b, c, k0, t1, t2, t3)
    }
}
