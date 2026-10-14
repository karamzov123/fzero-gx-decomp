/* Non-matching: best partial attempt (89.98% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

struct C489C_ent {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w1;
    u32 w2;
};

struct C489C_pool {
    u8 pad_0[0x40];
    struct C489C_ent e[41];
    u8 pad_1[0x454];
    f64 c0;
    u8 pad_2[0x10];
    f64 c52;
    u8 pad_3[0x10];
    f64 c1;
    u8 pad_4[0x40];
    f64 c02;
    f64 c100;
    f64 c20;
    f64 c16;
    f64 c21;
    f64 c15;
};

struct C489C_arg {
    u8 pad_0[6];
    s16 f6;
    u8 pad_8[0x14];
    f32 f1c;
    u8 pad_20[0xC];
    f32 f2c;
    u8 pad_30[0x200];
    f32 f230;
    u8 pad_234[0x250];
    u32 ptr484;
    u8 pad_488[0x86];
    u8 f50e;
};

struct C489C_obj {
    u32 flags;
    u8 pad_4[0x20];
    f32 f24;
    u8 b28;
    u8 pad_29;
    u8 b2a;
    u8 b2b;
    u8 pad_2C[5];
    u8 b31;
    u8 pad_32;
    u8 b33;
    u8 b34;
    u8 pad_35;
    u8 b36;
    u8 b37;
    u8 idx;
    u8 pad_39[7];
    u32 f40;
};

extern struct C489C_pool lbl_1_rodata_5168;
extern f32 lbl_1_bss_7AC64[9];
extern u32 fn_800793D4(u8 *, u32, u32);

void fn_1_C489C(struct C489C_arg *a) {
    struct C489C_pool *pool = (struct C489C_pool *)&lbl_1_rodata_5168;
    struct C489C_obj *b = (struct C489C_obj *)a->ptr484;
    u32 saved = b->f40;

    fn_800793D4((u8 *)b, 0, 0x88);
    b->f40 = saved;

    if (a->f6 >= 0x29) {
        b->idx = a->f6 % 4;
    } else {
        b->idx = a->f6;
    }

    if (a->f50e == 0) {
        b->flags |= 0x20000000;
    } else {
        a->f50e = 0;
    }

    b->b28 = 1;
    b->b2a = 0x63;
    b->b37 = 0xff;

    {
        u8 *eb = (u8 *)pool->e;
        f64 t = (f64)lbl_1_bss_7AC64[4] * (f64)((struct C489C_ent *)eb)[b->idx].b3;
        f32 v;
        f64 d;

        b->f24 = (f32)(pool->c02 * (pool->c100 - t));
        v = b->f24;
        d = pool->c0;
        d = v < d ? d : (v > pool->c20 ? pool->c20 : v);
        b->f24 = (f32)d;
    }

    if (a->f2c > pool->c1) {
        b->flags |= 0x1000000;
    }
    if (a->f2c > pool->c16) {
        b->flags |= 0x800000;
    }
    if (a->f1c < pool->c21) {
        b->flags |= 0x400000;
    }
    if (a->f230 > pool->c15) {
        b->flags |= 0x200000;
    }

    {
        u8 *eb = (u8 *)pool->e;
        u32 *wb = (u32 *)eb + 2;

        b->flags = (b->flags & 0xFFFEFFFF) | ((wb[b->idx * 3] >> 14) & 0x10000);
        b->flags = (b->flags & 0xFFFDFFFF) | ((wb[b->idx * 3] >> 14) & 0x20000);
        b->b2b = 0xff;
        b->b36 = 0xff;
        b->b31 = eb[b->idx * 12];
        b->b33 = 0xff;
        b->b34 = 0xff;
    }
}
