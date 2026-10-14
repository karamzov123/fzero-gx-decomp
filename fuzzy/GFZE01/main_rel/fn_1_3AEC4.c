/* Non-matching: best partial attempt (92.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern void fn_1_A8F78(void);
extern s32 fn_1_1547FC(void *, u32);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32);

struct fn_1_3AEC4_C {
    u8 pad_0[0x9];
    u8 unk_9;
    u8 pad_A[0x9D];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    u8 unk_D4[0x1390];
    u32 unk_1464;
    u8 pad_1468[0x4];
    u8 unk_146C;
    u8 unk_146D;
    s16 unk_146E;
    u8 unk_1470;
};

struct fn_1_3AEC4_A {
    u8 pad_0[0x14];
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[0x14];
    u32 unk_30;
    u8 pad_34[0x5];
    u8 unk_39;
    u8 pad_3A[0x9D];
    u8 unk_D7;
    u8 pad_D8[0x2C];
    u8 pad_104[0x1390];
    u32 unk_1494;
    u8 pad_1498[0x4];
    u8 unk_149C;
    u8 unk_149D;
    s16 unk_149E;
    u8 unk_14A0;
    u8 pad_14A1[0x47];
    s16 unk_14E8;
};

struct fn_1_3AEC4_B {
    union {
        struct { u8 pad_view_unk_1F88[0x1F88]; u32 unk_1F88; };
        struct { u8 pad_view_unk_1FA8[0x1FA8]; u8 unk_1FA8[0x20]; };
        struct { u8 pad_view_unk_1FC8[0x1FC8]; u8 unk_1FC8[0x20]; };
        struct { u8 pad_view_unk_20A4[0x20A4]; u32 unk_20A4; };
        struct { u8 pad_view_unk_20A8[0x20A8]; u32 unk_20A8; };
        struct { u8 pad_view_unk_20AC[0x20AC]; u32 unk_20AC; };
        struct { u8 pad_view_unk_20B0[0x20B0]; u32 unk_20B0; };
        struct { u8 pad_view_unk_20B4[0x20B4]; u32 unk_20B4; };
        struct { u8 pad_view_unk_20B8[0x20B8]; u32 unk_20B8; };
        struct { u8 pad_view_unk_20BC[0x20BC]; u32 unk_20BC; };
        struct { u8 pad_view_unk_20C0[0x20C0]; u32 unk_20C0; };
        struct { u8 pad_view_unk_20C4[0x20C4]; u32 unk_20C4; };
        struct { u8 pad_view_unk_20CC[0x20CC]; u32 unk_20CC; };
        struct { u8 pad_view_unk_2254[0x2254]; u32 unk_2254; };
        struct { u8 pad_view_unk_2258[0x2258]; u32 unk_2258; };
        struct { u8 pad_view_unk_225C[0x225C]; u32 unk_225C; };
        struct { u8 pad_view_unk_2260[0x2260]; u32 unk_2260; };
        struct { u8 pad_view_unk_2264[0x2264]; u32 unk_2264; };
        struct { u8 pad_view_unk_226C[0x226C]; s32 unk_226C; };
        struct { u8 pad_view_unk_2270[0x2270]; s32 unk_2270; };
        struct { u8 pad_view_unk_227C[0x227C]; s32 unk_227C; };
        struct { u8 pad_view_unk_2280[0x2280]; s32 unk_2280; };
        struct { u8 pad_view_unk_2284[0x2284]; s32 unk_2284; };
    };
};

struct fn_1_3AEC4_Far {
    struct fn_1_3AEC4_B *p;
};

static inline u8 * fn_1_3AEC4_read_pointer(struct fn_1_3AEC4_C * owner) { return owner->unk_D4; }
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_1_3AEC4(void) {
    struct fn_1_3AEC4_B * fzgx_live;
    struct fn_1_3AEC4_A *a = (struct fn_1_3AEC4_A *)&lbl_1_bss_3C00;
    struct fn_1_3AEC4_Far far;
    struct fn_1_3AEC4_C *c;
    u8 *pidx;
    u8 *pcnt;
    u8 *s1;
    u8 *s2;
    s32 i;
    u32 v;
    u32 lab_t0;

    far.p = (struct fn_1_3AEC4_B *)((u8 *)a + 0x20000);

    fzgx_live = far.p;
    fn_1_435C(fzgx_live->unk_1F88);
    if (far.p->unk_227C != -1) {
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_227C;
        fn_1_426C(lab_t0);
    }
    if (far.p->unk_2280 != -1) {
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_2280;
        fn_1_426C(lab_t0);
        fn_1_105724();
    }
    fzgx_live = far.p;
    fn_1_435C(fzgx_live->unk_20A4);
    if (far.p->unk_2284 != -1) {
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_2284;
        fn_1_426C(lab_t0);
    }
    lab_t0 = a->unk_30;
    fzgx_live = far.p;
    fzgx_live->unk_227C = -1;
    fzgx_live = far.p;
    fzgx_live->unk_2280 = -1;
    fzgx_live = far.p;
    fzgx_live->unk_2284 = -1;
    if (lab_t0 & 0x100) {
        if (a->unk_14E8 != 0x2A) {
            fn_1_F2EDC();
        }
    }
    fn_1_A8F78();
    if (far.p->unk_226C != 0) {
        fzgx_live = far.p;
        fzgx_live->unk_2270 = 1;
    }
    if (far.p->unk_2270 != 0) {
        c = (struct fn_1_3AEC4_C *)((u8 *)a + 0x30);
        fzgx_live = far.p;
        s1 = fzgx_live->unk_1FA8;
        fzgx_live = far.p;
        s2 = fzgx_live->unk_1FC8;
        pidx = &c->unk_A7;
        pcnt = &c->unk_9;
        for (i = 0; i < *pcnt; i++) {
            u8 *d = fn_1_3AEC4_read_pointer(c);
            d[*pidx + 0xE] = *s1++;
            d[*pidx + 0x13] = *s2++;
            c = (struct fn_1_3AEC4_C *)((u8 *)c + 0xA0);
        }
        c->unk_1464 = 0;
        c->unk_146C = 0;
        c->unk_146D = 0;
        c->unk_1470 = 0;
        c->unk_146E = 0x5DC;
        fn_1_1547FC(c, 0);
        fn_1_C47B4();
        fzgx_live = far.p;
        fn_1_435C(fzgx_live->unk_1F88);
        if (a->unk_14 != 0) {
            lab_t0 = a->unk_14;
            fn_1_426C(lab_t0);
            a->unk_14 = 0;
        }
        fzgx_live = far.p;
        fn_1_435C(fzgx_live->unk_20A4);
        if (a->unk_18 != 0) {
            lab_t0 = a->unk_18;
            fn_1_426C(lab_t0);
            a->unk_18 = 0;
        }
        fn_1_C6F80(0);
        fzgx_live = far.p;
        v = fn_80008E84(fzgx_live->unk_20CC);
        fn_1_79100();
        fn_80008E84(v);
        fn_1_412A0(2);
        fn_1_E35F0();
        fzgx_live = far.p;
        fn_1_435C(fzgx_live->unk_1F88);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_20B4;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_20B8;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_2264;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        fn_1_435C(fzgx_live->unk_20A4);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_20A8;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_20AC;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_20B0;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        v = fzgx_live->unk_20BC;
        lab_t0 = v;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_20C0;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_20C4;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_2258;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_225C;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_2260;
        fn_1_426C(lab_t0);
        fzgx_live = far.p;
        lab_t0 = fzgx_live->unk_2254;
        fn_1_426C(lab_t0);
    }
    if (far.p->unk_226C != 0) {
        c = (struct fn_1_3AEC4_C *)((u8 *)a + 0x30);
        c->unk_A7++;
    }
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset
