#include "types.h"


/* --- rel/movie_module/fn_12_80BC.c --- */
/* --- rel/movie_module/fn_12_80BC.c --- */
typedef struct MovieDecodeContext {
    u8 *lookup;
    s16 *table;
    u8 *data;
    u8 *ref;
} MovieDecodeContext;

void fn_12_80BC(f64 *output, MovieDecodeContext *context, s32 mask) {
    u8 *data;
    u8 *ref;
    s16 *table;
    u8 *lookup;
    s32 count;
    s32 i;
    u8 last;

    table = context->table;
    data = context->data;
    ref = context->ref;
    lookup = context->lookup;
    count = 0;
    do {
        if (mask >= 0) {
            table += 0x40;
            for (i = 0; i < 8; i++) {
                data[0] = (data[0] + ref[0] + 1) >> 1;
                data[1] = (data[1] + ref[1] + 1) >> 1;
                data[2] = (data[2] + ref[2] + 1) >> 1;
                data[3] = (data[3] + ref[3] + 1) >> 1;
                data[4] = (data[4] + ref[4] + 1) >> 1;
                data[5] = (data[5] + ref[5] + 1) >> 1;
                data[6] = (data[6] + ref[6] + 1) >> 1;
                last = ref[7];
                data[7] = (data[7] + last + 1) >> 1;
                ref += 8;
                data += 8;
            }
        } else {
            for (i = 0; i < 8; i++) {
                data[0] = lookup[((data[0] + ref[0] + 1) >> 1) + table[0]];
                data[1] = lookup[((data[1] + ref[1] + 1) >> 1) + table[1]];
                data[2] = lookup[((data[2] + ref[2] + 1) >> 1) + table[2]];
                data[3] = lookup[((data[3] + ref[3] + 1) >> 1) + table[3]];
                data[4] = lookup[((data[4] + ref[4] + 1) >> 1) + table[4]];
                data[5] = lookup[((data[5] + ref[5] + 1) >> 1) + table[5]];
                data[6] = lookup[((data[6] + ref[6] + 1) >> 1) + table[6]];
                last = ref[7];
                data[7] = lookup[((data[7] + last + 1) >> 1) + table[7]];
                ref += 8;
                data += 8;
                table += 8;
            }
        }
        {
            s32 j;
            for (j = 0; j < 8; j++) {
                output[j] = ((f64 *)data)[j - 8];
            }
        }
        output += 8;
        mask <<= 1;
        count++;
    } while (count < 6);
}

/* --- rel/movie_module/fn_12_8344.c --- */
typedef struct MovieDecodeContext_u1 {
    u8 *lookup;
    s16 *table;
    u8 *data;
} MovieDecodeContext_u1;

void fn_12_8344(f64 *output, MovieDecodeContext_u1 *context, s32 mask) {
    u8 *data;
    s16 *table;
    s32 i;
    u8 *lookup;
    s32 count;
    u8 *next;

    table = context->table;
    data = context->data;
    lookup = context->lookup;
    count = 0;
    do {
        if (mask >= 0) {
            table += 0x40;
        } else {
            for (i = 0; i < 8; i++) {
                data[0] = lookup[data[0] + table[0]];
                data[1] = lookup[data[1] + table[1]];
                data[2] = lookup[data[2] + table[2]];
                data[3] = lookup[data[3] + table[3]];
                data[4] = lookup[data[4] + table[4]];
                data[5] = lookup[data[5] + table[5]];
                data[6] = lookup[data[6] + table[6]];
                data[7] = lookup[data[7] + table[7]];
                data += 8;
                table += 8;
            }
            data -= 0x40;
        }
        next = data + 0x40;
        for (i = 0; i < 8; i++) {
            output[i] = ((f64 *)data)[i];
        }
        data = next;
        output += 8;
        mask <<= 1;
        count++;
    } while (count < 6);
}

/* --- rel/movie_module/fn_12_847C.c --- */
typedef struct Fn847C_Dest {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1c[4];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
} Fn847C_Dest;

extern void (*lbl_12_bss_4E40[2][4])(void *);

void fn_12_847C(void *obj, u32 arg1, s32 *arg2, u8 *arg3, s32 *arg4) {
    s32 ah;
    s32 al;
    s32 h;
    s32 w;
    s32 x;
    s32 y;
    Fn847C_Dest *d;
    void (*f)(void *);
    void (*g)(void *);
    s32 sel;
    s32 a;
    s32 b;
    s32 v;

    sel = *(s32 *)((u8 *)obj + 0x19C);
    w = *(s16 *)(arg3 + 0xE);
    h = *(s16 *)(arg3 + 0xC);
    (*(void (**)(void *, u32))((u8 *)obj + 0x290))((void *)obj, *(u32 *)((u8 *)obj + 0x308));
    a = arg4[6];
    b = arg4[7];
    ah = (a / 2) & 1;
    al = a & 1;
    x = ((((b / 2) >> 1) * h) + ((arg2[0]) + (((a / 2) >> 1))));
    y = (((b >> 1) * w) + ((arg2[1]) + ((a >> 1))));
    f = lbl_12_bss_4E40[sel][(((b / 2) & 1) << 1) + ah];
    g = lbl_12_bss_4E40[sel][((b & 1) << 1) + al];
    d = (Fn847C_Dest *)((u8 *)obj + 0xCC);
    d->unk_20 = h;
    d->unk_18 = arg1;
    v = *(s32 *)arg3 + x;
    d->unk_24 = v;
    d->unk_28 = (h + (ah & (sel != 0 ? -1 : 0))) + v;
    f(d);
    d->unk_18 = arg1 + 0x40;
    v = *(s32 *)(arg3 + 4) + x;
    d->unk_24 = v;
    d->unk_28 = (h + (ah & (sel != 0 ? -1 : 0))) + v;
    f(d);
    d->unk_20 = w;
    d->unk_18 = arg1 + 0x80;
    v = *(s32 *)(arg3 + 8) + y;
    d->unk_24 = v;
    d->unk_28 = (w + (al & (sel != 0 ? -1 : 0))) + v;
    g(d);
    d->unk_18 = arg1 + 0xC0;
    d->unk_24 = d->unk_24 + 8;
    d->unk_28 = d->unk_28 + 8;
    g(d);
    d->unk_18 = arg1 + 0x100;
    d->unk_24 = d->unk_24 + (w - 1) * 8;
    d->unk_28 = d->unk_28 + (w - 1) * 8;
    g(d);
    d->unk_18 = arg1 + 0x140;
    d->unk_24 = d->unk_24 + 8;
    d->unk_28 = d->unk_28 + 8;
    g(d);
}
