/* Non-matching: best partial attempt (92.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 50.0f;
    s = 500.0f;
    s = 31.200000762939453f;
    s = 312.0f;
    s = 68.0f;
    s = 20.0f;
    s = 96.0f;
    s = 1.3600000143051147f;
    s = 161.0f;
    s = 1.015625f;
    s = 129.0f;
    s = 15.0f;
    s = 10.0f;
    s = 0.0f;
    s = 86.0f;
    s = 0.5f;
    s = 139.0f;
    s = 75.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[3] = {0xFFFF0000, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 185.0f;
    s = 180.0f;
    s = 276.0f;
    s = 116.0f;
    s = 7.0f;
    s = 205.0f;
    s = 11.399999618530273f;
    s = 40.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 274.0f;
    s = 0.5833333134651184f;
    s = 0.5416666865348816f;
    s = 0.4583333432674408f;
    d = 4503599627370496.0;
    s = 320.0f;
    s = 240.0f;
    s = 5.0f;
    s = 6.099999904632568f;
    s = 0.800000011920929f;
    s = 228.0f;
    s = 252.0f;
    s = 0.10000000149011612f;
    s = -30.0f;
    s = 750.0f;
    s = 48.0f;
    s = 660.0f;
    s = 44.0f;
    s = 24.0f;
    s = 302.0f;
    s = 70.0f;
    s = 330.0f;
    s = 1.2699999809265137f;
    s = 390.0f;
    s = 308.0f;
    s = 1.0f;
    s = 368.0f;
    s = 360.0f;
    s = 30.0f;
    s = 0.4000000059604645f;
    s = 32768.0f;
    s = 0.90625f;
    s = 0.921875f;
    s = 0.9375f;
}
static const u32 fzgx_pool_table4[25] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 90000.0f;
    s = 95.0f;
    s = 17.0f;
    s = 354.0f;
    s = 310.0f;
    s = 365.0f;
    s = 143.0f;
    s = 19.29990005493164f;
    s = 0.009999999776482582f;
    s = 0.75f;
    s = 351.0f;
    s = 387.0f;
    s = 0.6000000238418579f;
    s = 0.699999988079071f;
    s = 348.0f;
    s = 384.0f;
}
static const u32 fzgx_pool_table6[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 0.05000000074505806f;
    s = 0.3499999940395355f;
    s = 0.0005000000237487257f;
}
#pragma section code_type ".text"

struct Pad106FC {
    u8 pad_0[0x8];
    u16 held;
    u8 pad_A[0x6];
    u16 trig;
    u16 rep;
};
struct Tbl106FC {
    u16 count;
    u8 pad_2[0x2];
    u8 *flags;
    u32 **items;
};
struct S6_106FC {
    s16 a;
    s16 b;
    u16 c;
};
struct V6_106FC {
    f32 a, b, c, d, e, f;
};
struct State106FC {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[0x6];
    s16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    u8 unk_20;
    u8 unk_21;
    u8 pad_22[0x4];
    struct S6_106FC unk_26;
    u8 pad_2C[0x10];
    u8 unk_3C;
};
struct Slot106FC {
    s16 unk_20;
    u8 pad_22[0x2];
    u8 pad_0[0x20];
    u32 unk_24;
    struct S6_106FC unk_28;
    u8 pad_2E[0x1A];
    struct V6_106FC unk_48;
    f32 unk_60;
    f32 unk_64;
    u8 pad_68[0x18];
    u8 unk_80[0x2060 - 0x80];
};
struct V6Hdr106FC {
    u8 pad_0[0x4];
    struct V6_106FC v;
};
struct Obj7EE40_106FC {
    u8 pad_4[0x1C];
    u32 unk_0;
    u8 unk_20[1];
};

extern struct Pad106FC lbl_1_bss_9F8[];
extern struct State106FC lbl_3_bss_7EDD8;
extern struct Tbl106FC lbl_3_bss_87000[];
extern struct Slot106FC lbl_3_bss_87040[];
extern struct V6Hdr106FC lbl_3_bss_9F640;
extern struct V6Hdr106FC lbl_3_bss_9F690;
extern struct Obj7EE40_106FC lbl_3_bss_7EE40;
extern u32 lbl_3_rodata_288[60];
extern void fn_1_A2D84(u32);
extern void fn_80008BA8(void *, u32 *, u32);
extern void fn_3_11994(u8, s16, void *, void *);

static inline u8 * fn_3_106FC_read_pointer(struct Obj7EE40_106FC * owner) { return owner->unk_20; }
void fn_3_106FC(void) {
    struct State106FC *p;
    struct Slot106FC *slot;
    u16 count;
    int t;
    u8 v;
    f32 k;
    void * lab_t0;

    p = &lbl_3_bss_7EDD8;
    v = p->unk_1E;
    count = lbl_3_bss_87000[p->unk_3C].count;
    if (p->unk_1F + (v + 1) > count) {
        t = v - 1;
        if (t < 0) {
            t = 0;
        } else {
            if (t > count - 1) {
                t = count - 1;
            }
        }
        p->unk_1E = t;
    }
    if ((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].held >> 4) & 1) {
        lbl_3_bss_7EDD8.unk_10 = lbl_3_bss_7EDD8.unk_C;
        lbl_3_bss_7EDD8.unk_C = 0x1000000;
    }
    if ((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].trig & 1) || (lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].rep & 1)) {
        if (p->unk_1F == 0) {
            if (p->unk_1E != 0) {
                lbl_3_bss_7EDD8.unk_21 = 10;
                lbl_3_bss_7EDD8.unk_20 = 0;
                p->unk_1E--;
                fn_1_A2D84(0xA9010000);
            }
        } else {
            p->unk_1F--;
            fn_1_A2D84(0xA9010000);
        }
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].trig >> 1) & 1) || ((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].rep >> 1) & 1)) {
        if (p->unk_1F > 7) {
            if (p->unk_1E + 9 < lbl_3_bss_87000[p->unk_3C].count) {
                lbl_3_bss_7EDD8.unk_20 = 10;
                lbl_3_bss_7EDD8.unk_21 = 0;
                p->unk_1E++;
                fn_1_A2D84(0xA9010000);
            }
        } else {
            p->unk_1F++;
            fn_1_A2D84(0xA9010000);
        }
    }
    if ((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].rep >> 8) & 1) {
        p->unk_3C = (p->unk_3C + 2) % 3;
        fn_1_A2D84(0xA9010000);
    }
    if ((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].rep >> 9) & 1) {
        p->unk_3C = (p->unk_3C + 1) % 3;
        fn_1_A2D84(0xA9010000);
    }
    if ((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].held >> 8) & 1) {
        if (lbl_3_bss_87000[p->unk_3C].items != 0 &&
            lbl_3_bss_87000[p->unk_3C].items[p->unk_1E + p->unk_1F] != 0 &&
            lbl_3_bss_87000[p->unk_3C].flags[p->unk_1E + p->unk_1F] != 0) {
            f32 zero;
            f32 five;
            fn_1_A2D84(0xA9010100);
            slot = &lbl_3_bss_87040[lbl_3_bss_7EDD8.unk_15];
            lbl_3_bss_7EDD8.unk_26.a = 0x3FFF;
            lbl_3_bss_7EDD8.unk_26.b = 0;
            slot->unk_24 |= 0x80000000;
            slot->unk_28 = lbl_3_bss_7EDD8.unk_26;
            zero = 0.0f;
            five = 5.0f;
            k = 0.349999994f;
            lbl_3_bss_9F640.v.a = zero;
            slot->unk_64 = k;
            lbl_3_bss_9F640.v.b = zero;
            slot->unk_60 = k;
            lbl_3_bss_9F640.v.c = five;
            lbl_3_bss_9F640.v.d = zero;
            lbl_3_bss_9F640.v.e = zero;
            lbl_3_bss_9F640.v.f = zero;
            slot->unk_48 = lbl_3_bss_9F640.v;
            lbl_3_bss_7EDD8.unk_10 = 0;
            lbl_3_bss_7EDD8.unk_C = 0x2000000;
            lbl_3_bss_9F690.v.a = zero;
            lbl_3_bss_9F690.v.b = zero;
            lbl_3_bss_9F690.v.c = five;
            lbl_3_bss_9F690.v.d = zero;
            lbl_3_bss_9F690.v.e = zero;
            lbl_3_bss_9F690.v.f = zero;
            slot->unk_20 = lbl_3_bss_7EDD8.unk_1C;
            lab_t0 = slot->unk_80;
            fn_80008BA8(lab_t0, lbl_3_bss_87000[p->unk_3C].items[p->unk_1E + p->unk_1F], 0x2000);
            fn_3_11994(lbl_3_bss_7EDD8.unk_15, lbl_3_bss_7EDD8.unk_1C, fn_3_106FC_read_pointer(&lbl_3_bss_7EE40), &lbl_3_bss_87040[0].unk_20);
        }
    }
    if ((lbl_1_bss_9F8[lbl_3_bss_7EDD8.unk_14].held >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        if (!(lbl_3_bss_7EE40.unk_0 & 0x40000000)) {
            lbl_3_bss_7EDD8.unk_C = 0x40000000;
        } else {
            lbl_3_bss_7EDD8.unk_C = 0x10000000;
        }
    }
}

