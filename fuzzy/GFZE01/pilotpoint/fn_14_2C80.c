/* Non-matching: best partial attempt (67.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Fn14_2C80_Row {
    s16 v[4];
    s32 tag;
    u32 pad;
};

struct Fn14_2C80_Hdr {
    u32 a;
    u32 b;
};

struct Fn14_2C80_Str {
    u8 pad_0[0x24];
    void *f_24;
};

struct Fn14_2C80_Obj {
    u8 pad_0[0x148];
    void *f_148;
    u8 pad_14C[4];
    struct Fn14_2C80_Str *f_150;
    u8 pad_154[0x4E0 - 0x154];
};

struct Fn14_2C80_Bss {
    u8 pad_0[0x1C];
    void *f_1C;
    u8 pad_20[0xF0];
    u8 enttab[0x50];
    s16 cnt_160;
    s16 cnt_162;
    s16 cnt_164;
};

struct Fn14_2C80_Top {
    void *alloc[5];
    struct Fn14_2C80_Obj objs[2];
    u8 buf_1[0x64];
    u8 buf_2[0xF0];
};

struct Fn14_2C80_Data {
    u8 pad_0[0x2F30];
    u32 seed;
    u8 pad_2F34[4];
    u32 tag;
    u8 pad_2F3C[4];
    u32 f_2F40;
    u32 f_2F44;
    u8 pad_2F48[4];
    u32 tab[25];
    u8 name[0x60];
    u8 dst[0x10];
};

struct Fn14_2C80_Arena {
    u32 unk_0;
};

extern struct Fn14_2C80_Bss lbl_14_bss_0;
extern struct Fn14_2C80_Data lbl_14_data_0;
extern struct Fn14_2C80_Arena lbl_801A6410;
extern const struct Fn14_2C80_Hdr lbl_14_rodata_118;

extern void * fn_1_4630(u32, u32, u8 *, u32);
extern s16 fn_1_128B00(s16);
extern s16 fn_1_14F270(s16, s16, u32);
extern void fn_1_14D8DC(void *, void *, s16);
extern s16 fn_1_12C930(s16);
extern void fn_1_8F198(void *, s16, u32, u32);
extern void fn_1_435C(void *);
extern u32 fn_1_3F8C(void *, void *, void *, u32);
extern u64 fn_1_41488(void *, void *);
extern void fn_1_933D8(void *, void *, u32);
extern s16 fn_1_12CCB0(s16, s16);
extern s16 fn_1_12CB04(s16);
extern u32 fn_1_A5D88(void);
extern void fn_1_12BF7C(void *, s16, u16, u32);
extern void fn_1_8F62C(void);

void fn_14_2C80(void)
{
    struct Fn14_2C80_Obj *o;
    struct Fn14_2C80_Hdr hdr;
    s16 list[2];
    s16 *lp;
    struct Fn14_2C80_Row rows[6];
    u32 *ep;
    u32 *tp;
    s16 i, j, h;
    int k;
    u32 off, off2, idx, tagv;
    struct Fn14_2C80_Bss *bss = &lbl_14_bss_0;
    struct Fn14_2C80_Data *dat = &lbl_14_data_0;
    struct Fn14_2C80_Top *top = (struct Fn14_2C80_Top *)((u8 *)&lbl_14_bss_0 + 0x10000);

    top->alloc[0] = fn_1_4630(lbl_801A6410.unk_0, bss->cnt_164 * 0xA20, dat->name, 0x888);
    top->alloc[1] = fn_1_4630(lbl_801A6410.unk_0, bss->cnt_164 * 0xA20, dat->name, 0x889);
    top->alloc[2] = fn_1_4630(lbl_801A6410.unk_0, bss->cnt_160 * 0x12C, dat->name, 0x88A);
    top->alloc[3] = fn_1_4630(lbl_801A6410.unk_0, bss->cnt_162 * 0x64, dat->name, 0x88B);
    top->alloc[4] = fn_1_4630(lbl_801A6410.unk_0, bss->cnt_162 * 0xEA0, dat->name, 0x88D);

    tagv = dat->tag;
    for (i = 0; i < 3; i++)
        rows[0].v[i] = fn_1_14F270(fn_1_128B00(i), i, dat->seed);
    rows[0].tag = tagv;
    h = fn_1_128B00(i);

    ep = (u32 *)&bss->enttab[0];
    lp = list;
    i = 1;
    k = 0;
    for (j = 0; (u32)j < 8; j++) {
        if (ep[3] & 0x8) {
            *(s16 *)((u8 *)&rows[i] + k) = *(s16 *)&ep[2];
            rows[i].tag = tagv;
            if (ep[3] & 0x20) {
                i = 1;
                k += 2;
            } else {
                i++;
            }
        }
        if (ep[3] & 0x10)
            *lp++ = *(s16 *)&ep[2];
        ep += 2;
    }

    fn_1_14D8DC(&rows[0], top->alloc[0], bss->cnt_164);
    fn_1_14D8DC(&rows[0], top->alloc[1], bss->cnt_164);

    hdr = lbl_14_rodata_118;
    o = &top->objs[0];
    fn_1_8F198(o, (s16)fn_1_12C930(h), dat->f_2F40, dat->f_2F44);
    fn_1_435C(bss->f_1C);
    tp = dat->tab;
    idx = 0;
    tp[idx++] = fn_1_3F8C(dat->dst, fn_1_8F62C, o, 8);
    fn_1_933D8(o, &o->f_148, (u16)(fn_1_41488(o->f_150->f_24, &hdr) >> 16));

    off = 0;
    for (j = 0; j < fn_1_12CB04(h); j++) {
        o = (struct Fn14_2C80_Obj *)((u8 *)o + off + 0x4E0);
        off += 0x4E0;
        fn_1_8F198(o, (s16)fn_1_12CCB0(h, j), dat->f_2F40, dat->f_2F44);
        fn_1_435C(bss->f_1C);
        tp[idx++] = fn_1_3F8C(dat->dst, fn_1_8F62C, o, 8);
        fn_1_933D8(o, &o->f_148, (u16)(fn_1_41488(o->f_150->f_24, &hdr) >> 16));
    }

    off = 0;
    for (i = 0; i < bss->cnt_162; i++) {
        o = (struct Fn14_2C80_Obj *)((u8 *)top->alloc[4] + off);
        fn_1_8F198(o, (s16)fn_1_12C930(list[i]), dat->f_2F40, dat->f_2F44);
        fn_1_435C(bss->f_1C);
        tp[idx++] = fn_1_3F8C(dat->dst, fn_1_8F62C, o, 8);
        fn_1_933D8(o, &o->f_148, (u16)(fn_1_41488(o->f_150->f_24, &hdr) >> 16));
        off2 = 0;
        for (j = 0; j < fn_1_12CB04(list[i]); j++) {
            o = (struct Fn14_2C80_Obj *)((u8 *)top->alloc[4] + off + off2 + 0x4E0);
            off2 += 0x4E0;
            fn_1_8F198(o, (s16)fn_1_12CCB0(list[i], j), dat->f_2F40, dat->f_2F44);
            fn_1_435C(bss->f_1C);
            tp[idx++] = fn_1_3F8C(dat->dst, fn_1_8F62C, o, 8);
            fn_1_933D8(o, &o->f_148, (u16)(fn_1_41488(o->f_150->f_24, &hdr) >> 16));
        }
        off += 0xEA0;
    }

    fn_1_12BF7C(top->alloc[2], (s16)(bss->cnt_160 * 3), (u16)(fn_1_A5D88() >> 14), 0x78);
    fn_1_12BF7C(top->alloc[3], bss->cnt_162, (u16)(fn_1_A5D88() >> 14), 0x78);
    fn_1_12BF7C(top->buf_1, 1, (u16)fn_1_A5D88(), 0x1E0);
    fn_1_12BF7C(top->buf_2, 1, (u16)(fn_1_A5D88() >> 15), 0xF0);
}
