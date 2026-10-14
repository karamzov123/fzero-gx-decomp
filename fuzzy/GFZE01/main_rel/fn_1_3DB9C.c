/* Non-matching: best partial attempt (89.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

extern u32 fn_1_156754(u32);
extern u32 fn_1_F7578(void);
extern void fn_1_A8F78(void);
extern s32 fn_1_1547FC(u32, u32);
extern void fn_1_C47B4(void);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32 value);

struct fn_1_3DB9C_rec {
    u32 unk_0;
    u8 pad_4[5];
    u8 count;
    u8 pad_A[0x9D];
    u8 idx;
    u8 pad_A8[0x2C];
    u8 unk_D4[0x1000];
    u8 pad_10D4[0x360];
    u32 unk_1434;
    u8 pad_1438[4];
    u8 unk_143C;
    u8 unk_143D;
    u16 unk_143E;
    u8 unk_1440;
    u8 pad_1441[0xBBF];
};

struct fn_1_3DB9C_s {
    u8 pad_0[0x14];
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[0x14];
    struct fn_1_3DB9C_rec sub;
};

struct fn_1_3DB9C_t {
    u8 pad_0[0x1F88];
    u32 unk_1F88;
    u8 pad_1F8C[0x1C];
    u8 unk_1FA8[0x20];
    u8 unk_1FC8[0xDC];
    u32 unk_20A4;
    u32 unk_20A8;
    u32 unk_20AC;
    u32 unk_20B0;
    u32 unk_20B4;
    u32 unk_20B8;
    u32 unk_20BC;
    u32 unk_20C0;
    u32 unk_20C4;
    u8 pad_20C8[4];
    u32 unk_20CC;
    u8 pad_20D0[0x184];
    u32 unk_2254;
    u32 unk_2258;
    u32 unk_225C;
    u32 unk_2260;
    u32 unk_2264;
    u8 pad_2268[4];
    s32 unk_226C;
    s32 unk_2270;
};

static inline u8 * fn_1_3DB9C_read_pointer(struct fn_1_3DB9C_rec * owner) { return owner->unk_D4; }
#pragma opt_propagation off
static inline u8 *fn_1_3DB9C_array_read(u8 *array) { return array; }
void fn_1_3DB9C(void) {
    u32 tmp_call14;
    u32 fzgx_value;
    struct fn_1_3DB9C_s *s = (struct fn_1_3DB9C_s *)&lbl_1_bss_3C00;
    struct fn_1_3DB9C_t *t = (struct fn_1_3DB9C_t *)((u8 *)s + 0x20000);
    s32 i;
    u32 v;
    u32 lab_t0;

    for (i = 0; i < 4; i++) {
        fn_1_156754(i);
    }
    fn_1_F7578();
    s->sub.unk_0 &= 0xFFF1FFFF;
    fn_1_A8F78();
    if (t->unk_226C) {
        t->unk_2270 = 1;
    }
    if (t->unk_2270) {
        struct fn_1_3DB9C_rec *p = &s->sub;

        for (i = 0; i < p->count; i++) {
            fn_1_3DB9C_read_pointer(p)[p->idx + 0xE] = fn_1_3DB9C_array_read(t->unk_1FA8)[i];
            fn_1_3DB9C_read_pointer(p)[p->idx + 0x1] = fn_1_3DB9C_array_read(t->unk_1FC8)[i];
            p = (struct fn_1_3DB9C_rec *)((u8 *)p + 0xA0);
        }
        p = &s->sub;
        p->unk_143C = 0;
        fzgx_value = 0;
        p->unk_1434 = fzgx_value;
        p->unk_1440 = 0;
        p->unk_143D = 0;
        p->unk_143E = 0x0;
        fn_1_1547FC((u32)p, 0);
        fn_1_C47B4();
        fn_1_435C(t->unk_1F88);
        if (s->unk_14) {
            lab_t0 = s->unk_14;
            fn_1_426C(lab_t0);
            s->unk_14 = 0;
        }
        fn_1_435C(t->unk_20A4);
        if (s->unk_18) {
            lab_t0 = s->unk_18;
            (void) lab_t0;  /* fzgx: keeps the web at its definition */
            fn_1_426C(lab_t0);
            s->unk_18 = 0;
        }
        fn_1_C6F80(0);
        v = fn_80008E84(t->unk_20CC);
        fn_1_79100();
        tmp_call14 = fn_80008E84(v);
        tmp_call14;
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(t->unk_1F88);
        lab_t0 = t->unk_20B4;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_20B8;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_2264;
        fn_1_426C(lab_t0);
        fn_1_435C(t->unk_20A4);
        lab_t0 = t->unk_20A8;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_20AC;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_20B0;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_20BC;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_20C0;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_20C4;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_2258;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_225C;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_2260;
        fn_1_426C(lab_t0);
        lab_t0 = t->unk_2254;
        fn_1_426C(lab_t0);
    }
    if (t->unk_226C) {
        s->sub.idx++;
    }
}
#pragma opt_propagation reset

