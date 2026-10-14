/* Non-matching: best partial attempt (91.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_fn_8003B8A8_fn_8003B8A8___table_T {
    u8 pad_0[0x10];
    u32 unk_10;
    s32 unk_14[0x12];
    u32 unk_5c[0x13];
};
struct Sig_fn_8003B8A8_fn_8003B8A8___root_T {
    u8 pad_0[0x420];
    struct Sig_fn_8003B8A8_fn_8003B8A8___table_T table[0x100];
};
typedef struct Sig_fn_8003B930_Fn8003B930Data {
    u8 pad_10[0x10];
    u32 field_10;
    u8 pad_14[0x48];
    u32 field_5c[];
} Sig_fn_8003B930_Fn8003B930Data;

typedef struct Entry {
    u8 pad_0[0x6c4];
    u8 field_6c4;
    u8 field_6c5;
    s16 field_6c6;
} Entry;

#pragma align(32)
struct OutBuf {
    s16 v[0x40];
};
#pragma align(4)

extern u32 fn_8003B798(u32, u32);
extern int fn_8003B8A8(struct Sig_fn_8003B8A8_fn_8003B8A8___root_T *, u8);
extern int fn_8003B930(int, Sig_fn_8003B930_Fn8003B930Data *);
extern u8 lbl_8008FF50[];

void fn_8003B63C(struct Sig_fn_8003B8A8_fn_8003B8A8___root_T *arg0, u32 arg1, struct OutBuf *arg2) {
    u32 off;
    Entry *e;
    s32 i;
    u8 idx;
    s32 n;
    s32 lo;
    Sig_fn_8003B930_Fn8003B930Data *tab;
    s32 v;
    s16 s;
    struct Sig_fn_8003B8A8_fn_8003B8A8___root_T *self = arg0;

    __dcbz(arg2, 0);
    off = (((arg1) & (0xFF))) * 0x30;
    e = (Entry *)((u8 *)self + off);
    idx = (e->field_6c4 & 0x7F) << 1;
    __dcbz(arg2, 0x20);
    n = fn_8003B8A8(self, idx);
    __dcbz(arg2, 0x40);
    v = 0;
    __dcbz(arg2, 0x60);
    tab = (Sig_fn_8003B930_Fn8003B930Data *)((u8 *)self + 0x420 + ((((e->field_6c5 << 1) + 1) & 0xFF) * 0xa8));
    if (n != 0) {
        v = (s16)fn_8003B798((u32)self, n & 0xFF);
        if ((s32)__cntlzw(v) > (32 - n)) {
            v = ((v) + (((-1 << n)) + (1)));
        }
    }
    e = (Entry *)((u8 *)self + off);
    s = e->field_6c6 + v;
    e->field_6c6 = s;
    arg2->v[0] = s;
    i = 1;
    while (i < 0x40) {
        s32 t;
        s32 hi;
        t = fn_8003B930((int)self, tab);
        lo = t & 0xF;
        hi = t >> 4;
        if (lo != 0) {
            i = i + hi;
            v = fn_8003B798((u32)self, lo);
            if ((s32)__cntlzw(v) > (32 - lo)) {
                v = (((1) + ((-1 << lo))) + (v));
            }
            arg2->v[lbl_8008FF50[i]] = (s16)v;
        } else {
            if (hi == 0xF) {
                i = i + 0xF;
            }
        }
        i = i + 1;
    }
}
