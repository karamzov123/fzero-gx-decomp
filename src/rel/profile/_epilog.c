#include "types.h"

struct ProfileBss8B614 {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8;
    u16 unk_A;
    s16 unk_C;
    u16 unk_E;
    f32 unk_10, unk_14, unk_18, unk_1C, unk_20, unk_24;
    s16 unk_28;
    s16 unk_2A;
    u32 unk_2C;
    u16 unk_30;
    u8 pad_32[0x1A];
    u32 unk_4C;
    s16 unk_50;
    s16 unk_52;
    s16 unk_54;
    u8 pad_56[2];
    s16 unk_58;
};
extern struct ProfileBss8B614 lbl_1_bss_8B614;
extern u32 lbl_16_bss_150;
extern s32 lbl_16_bss_21C;
extern s16 lbl_16_bss_B060[41];
extern s16 lbl_16_bss_B0B2;
extern u32 lbl_16_data_82B00;
void _epilog(void);
void fn_16_910(void);
void fn_16_96C(u32 arg0);
void fn_16_9EC(void);
void fn_16_A34(void);
u32 fn_16_A38(void);
void fn_16_AA8(void);
void * fn_16_B10(void);
void fn_16_B24(void);
void fn_16_CAC(void);
void fn_16_DC8(u32 arg0);
s16 fn_16_E20(void);
extern s32 fn_1_4A00();
extern s32 fn_1_4C10();
extern s32 fn_1_F7BE4();

/* --- rel/profile/_epilog.c --- */
typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct _epilog_lbl_16_bss_0 {
    u32 unk_0;
    u8 pad_4[0x148];
    u32 unk_14C;
    u32 unk_150;
};
struct _epilog_lbl_801A6410 {
    u32 unk_0;
};

extern struct _epilog_lbl_16_bss_0 lbl_16_bss_0;
extern struct _epilog_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_412A0(u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_467F4(void);
extern u32 fn_1_A0AA4(void);
extern u32 lbl_16_data_82BF8;
extern void fn_1_3308(void);
extern void fn_1_41A8(void);
extern void fn_1_451E4(void);
extern void fn_1_469BC(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_48140(int);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);

void _epilog(void) {
    struct _epilog_lbl_16_bss_0 *p_lbl_16_bss_0;
    Sig_fn_1_8D168_Fn1_8D168State * v2;
    s16 v1;
    p_lbl_16_bss_0 = (struct _epilog_lbl_16_bss_0 *)&lbl_16_bss_0;
    v1 = 0;
    v2 = (Sig_fn_1_8D168_Fn1_8D168State *)(((u8 *)p_lbl_16_bss_0 + 0x154));
    while ((u32)v1 < 2) {
        fn_1_8D168(v2);
        v2 = (Sig_fn_1_8D168_Fn1_8D168State *)(((u8 *)v2 + 0x64));
        v1++;
    }
    fn_1_412A0(1);
    fn_1_48140(0x93);
    fn_1_48140(0x89);
    fn_1_48140(0x9a);
    fn_1_48140(0x65);
    fn_1_48140(0x6d);
    fn_1_48140(0x80);
    fn_1_48140(0x58);
    fn_1_48140(0x69);
    fn_1_48140(0x75);
    fn_1_48140(0x64);
    fn_1_48140(0x74);
    fn_1_48140(0x63);
    fn_1_48140(0x6c);
    fn_1_48140(0x5a);
    fn_1_48140(0x6e);
    fn_1_48140(0x82);
    fn_1_48140(0x6b);
    fn_1_48140(0x79);
    fn_1_48140(0x68);
    fn_1_48140(0x6a);
    fn_1_48140(0x59);
    fn_1_48140(0x6f);
    fn_1_48140(0x57);
    fn_1_48140(0x72);
    fn_1_48140(0x7e);
    fn_1_48140(0x73);
    fn_1_48140(0x71);
    fn_1_48140(0x5b);
    fn_1_48140(0x81);
    fn_1_48140(0x62);
    fn_1_48140(0x7a);
    fn_1_48140(0x5d);
    fn_1_48140(0x7c);
    fn_1_48140(0x5c);
    fn_1_48140(0x61);
    fn_1_48140(0x60);
    fn_1_48140(0x5e);
    fn_1_48140(0x7f);
    fn_1_48140(0x5f);
    fn_1_48140(0x77);
    fn_1_48140(0x70);
    fn_1_48140(0x76);
    fn_1_48140(0x78);
    fn_1_48140(0x7d);
    fn_1_A0AA4();
    fn_1_435C(p_lbl_16_bss_0->unk_14C);
    fn_1_41A8();
    fn_1_435C(p_lbl_16_bss_0->unk_150);
    fn_1_41A8();
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_16_bss_0->unk_0, (const char *)&lbl_16_data_82BF8, 0xda);
    fn_1_469BC();
    while (fn_1_467F4() != 0) {
        fn_1_451E4();
        fn_1_3308();
        fn_1_D3214();
        VIWaitForRetrace();
    }
}

/* --- rel/profile/fn_16_910.c --- */

typedef u32 (*fn_16_910_Fn0)(void);
struct fn_16_910_lbl_16_data_82C1C_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};
struct fn_16_910_lbl_16_data_82C1C {
    struct fn_16_910_lbl_16_data_82C1C_0_E44 unk_0[1];
};

extern s16 lbl_1_bss_962;
extern struct fn_16_910_lbl_16_data_82C1C lbl_16_data_82C1C;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

void fn_16_910(void) {
    struct fn_16_910_lbl_16_data_82C1C *p;
    s32 idx;
    p = (struct fn_16_910_lbl_16_data_82C1C *)&lbl_16_data_82C1C;
    idx = lbl_1_bss_962 - 190;
    lbl_1_bss_71688 = p->unk_0[idx].unk_24;
    lbl_1_bss_7168C = p->unk_0[idx].unk_28;
    ((fn_16_910_Fn0)p->unk_0[idx].unk_20)();
}

/* --- rel/profile/fn_16_96C.c --- */

struct fn_16_96C_lbl_1_bss_8B614 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern u16 lbl_1_bss_968;

void fn_16_96C(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    fn_16_AA8();
    v0 = arg0;
    if ((s32)fn_16_A38() == 0 && (s32)fn_1_4C10() == 0) {
    v1 = lbl_1_bss_8B614.unk_4;
    v2 = v1;
    if ((v1 & ~0x7FFFFFFF) != 0) {
    v2 = (v2 & 0x7FFFFFFF);
    lbl_1_bss_8B614.unk_4 = v2;
    lbl_1_bss_968 = 1;
    } else {
    if ((v2 & 0x40000000) != 0) {
    v2 = (v2 & 0xBFFFFFFF);
    lbl_1_bss_8B614.unk_4 = v2;
    lbl_1_bss_968 = 8;
    }
    }
    }
}

/* --- rel/profile/fn_16_9EC.c --- */

extern struct fn_16_9EC_lbl_16_bss_14C lbl_16_bss_14C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);

struct fn_16_9EC_lbl_16_bss_14C {
    u32 unk_0;
};
struct fn_16_9EC_lbl_16_bss_150 {
    u32 unk_0;
};

void fn_16_9EC(void) {
    u32 t0, t1, t3;
    t0 = fn_1_435C(lbl_16_bss_14C.unk_0);
    t1 = fn_1_407C(t0);
    fn_1_3CC4(t1);
    t3 = fn_1_435C(lbl_16_bss_150);
    fn_1_407C(t3);
}

/* --- rel/profile/fn_16_A34.c --- */

// fn_16_A34: empty in retail (single blr).
void fn_16_A34(void) {
}

/* --- rel/profile/fn_16_A38.c --- */

struct fn_16_A38_lbl_1_bss_8B614 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x44];
    u32 unk_4C;
};


u32 fn_16_A38(void) {
    u32 flags;
    if ((s32)lbl_16_bss_21C == -1) {
        fn_1_4C10();
    }
    flags = lbl_1_bss_8B614.unk_4C;
    if ((flags & 0x80000000) != 0 &&
        (flags & 0x1) == 0 &&
        (lbl_1_bss_8B614.unk_4 & 0x10000000) == 0) {
        return 1;
    }
    return fn_1_4C10() != 0;
}

/* --- rel/profile/fn_16_AA8.c --- */

struct fn_16_AA8_lbl_1_bss_8B614 {
    u8 pad_0[0x4C];
    u32 unk_4C;
    s16 unk_50;
    s16 unk_52;
    s16 unk_54;
};


void fn_16_AA8(void) {
    s16 delta;
    s16 value;
    struct ProfileBss8B614 *p = &lbl_1_bss_8B614;

    if (!(p->unk_4C & 0x80000000)) {
        return;
    }
    delta = p->unk_50;
    value = p->unk_52;
    value += delta;
    p->unk_52 = value;
    if (delta <= 0 || value < p->unk_54) {
        if (delta >= 0) {
            return;
        }
        if (p->unk_52 > lbl_1_bss_8B614.unk_54) {
            return;
        }
    }
    p->unk_4C = 0;
}

/* --- rel/profile/fn_16_B10.c --- */


struct fn_16_B10_lbl_1_bss_8B614 {
    u8 pad_0[0x58];
    u16 unk_58;
};

void * fn_16_B10(void) {
    lbl_1_bss_8B614.unk_58 = 2;
    return &lbl_1_bss_8B614;
}

/* --- rel/profile/fn_16_B24.c --- */

struct fn_16_B24_lbl_16_bss_150 {
    u32 unk_0;
};
struct fn_16_B24_lbl_16_bss_B060 {
    u16 unk_0[41];
};
struct fn_16_B24_lbl_1_bss_8B614 {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x22];
    u16 unk_30;
    u8 pad_32[0x1A];
    u32 unk_4C;
    s16 unk_50;
    s16 unk_52;
    s16 unk_54;
    u8 pad_56[2];
    s16 unk_58;
};
struct fn_16_B24_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern struct fn_16_B24_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern void fn_16_4E90(void);
extern u32 fn_1_A1588(u32, u32);
extern u32 lbl_16_bss_B0B4;
extern u32 lbl_16_data_82D3C;

void fn_16_B24(void) {
    struct fn_16_B24_lbl_16_bss_B060 *p_lbl_16_bss_B060;
    s32 v1;
    s32 v2;
    s16 v4;
    u32 v6;
    u32 t2;
    u32 t3;

    fn_1_435C(lbl_16_bss_150);
    fn_1_4A00(1, 15, lbl_16_bss_150);
    lbl_16_bss_B0B4 = 0;
    t2 = fn_1_3F8C((u32)&lbl_16_data_82D3C, (u32)fn_16_4E90, 0, 8);
    lbl_16_data_82B00 = t2;
    lbl_16_bss_21C = -1;
    v1 = 0;
    t3 = fn_1_F7BE4(30);
    if ((s32)t3 != 0) {
        lbl_16_bss_B060[(s16)v1++] = 30;
    }
    p_lbl_16_bss_B060 = (struct fn_16_B24_lbl_16_bss_B060 *)lbl_16_bss_B060;
    v2 = 0;
    while ((u32)(s16)v2 < 41) {
        if ((s16)v2 != 30 && (s32)fn_1_F7BE4(v2) != 0) {
            v4 = v1;
            v1++;
            p_lbl_16_bss_B060->unk_0[v4] = v2;
        }
        v2++;
    }
    lbl_16_bss_B0B2 = v1;
    if (lbl_1_bss_8B614.unk_C == -1) {
        lbl_1_bss_8B614.unk_C = 6;
    }
    lbl_1_bss_8B614.unk_4C = 0;
    lbl_1_bss_8B614.unk_4C |= 0x80000000;
    v6 = lbl_1_bss_6EAD0.unk_0;
    lbl_1_bss_8B614.unk_4C |= 0x10000000;
    lbl_1_bss_8B614.unk_50 = 1;
    lbl_1_bss_8B614.unk_52 = 0;
    lbl_1_bss_8B614.unk_54 = 15;
    lbl_1_bss_8B614.unk_30 = 0;
    fn_1_A1588(*(u32 *)(v6), 32);
}

/* --- rel/profile/fn_16_CAC.c --- */
struct fn_16_CAC_lbl_16_bss_21C {
    s32 unk_0;
};
struct fn_16_CAC_lbl_1_bss_8B614 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x44];
    u32 unk_4C;
};
struct fn_16_CAC_lbl_16_bss_150 {
    u32 unk_0;
};
extern u16 lbl_1_bss_96A;


void fn_16_CAC(void) {
    s16 temp_r3;
    s32 var_r0;
    u32 temp_r4;

    if (lbl_16_bss_21C == -1) {
        fn_1_4C10();
    }
    if ((lbl_1_bss_8B614.unk_4C & 0x80000000) && !(lbl_1_bss_8B614.unk_4C & 1) && !(lbl_1_bss_8B614.unk_4 & 0x10000000)) {
        var_r0 = 1;
    } else if (fn_1_4C10() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        if (lbl_16_bss_21C != -1) {
            temp_r4 = lbl_16_bss_21C;
            lbl_16_bss_21C = -1U;
            lbl_1_bss_96A = temp_r4;
            return;
        }
        temp_r3 = fn_16_E20();
        if (temp_r3 != 0) {
            fn_1_4A00(0, 0xF, lbl_16_bss_150);
            lbl_16_bss_B0B4 = 0;
        }
        if (temp_r3 == -1) {
            lbl_1_bss_8B614.unk_4 |= 0x80000000;
        }
        if (temp_r3 == 1) {
            lbl_16_bss_21C = 0xC0;
        }
    }
}

/* --- rel/profile/fn_16_DC8.c --- */

struct fn_16_DC8_lbl_16_data_82B00 {
    u32 unk_0;
};

extern u32 fn_1_426C(u32);

void fn_16_DC8(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if ((s32)lbl_16_data_82B00 != -1) {
    v0 = (u32)&lbl_16_bss_150;
    v0 = *(u32 *)(v0);
    t0 = fn_1_435C(v0);
    v0 = t0;
    v0 = (u32)&lbl_16_data_82B00;
    v0 = *(u32 *)(v0);
    t1 = fn_1_426C(v0);
    v0 = t1;
    lbl_16_data_82B00 = -1;
    }
}

/* --- rel/profile/fn_16_E20.c --- */

/* Flag words that retail reloads on every read. */
struct fn_16_E20_entry {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    volatile u16 unk_8; // fzgx-allow: S2 retail reloads this field on every read
    u16 unk_A;
    u8 pad_C[4];
    volatile u16 unk_10; // fzgx-allow: S2 retail reloads this field on every read
    volatile u16 unk_12; // fzgx-allow: S2 retail reloads this field on every read
};
struct fn_16_E20_state {
    u8 pad_0[8];
    s16 unk_8;
    u16 unk_A;
    s16 unk_C;
    u8 pad_E[0x3E];
    u32 unk_4C;
    s16 unk_50;
    s16 unk_52;
    s16 unk_54;
    u8 pad_56[2];
    s16 unk_58;
};
extern struct fn_16_E20_entry lbl_1_bss_9F8[];
extern void fn_1_A2D84(u32);

s16 fn_16_E20(void) {
    s16 idx;
    s16 v;
    s16 i;
    s16 found;
    s32 t;
    s32 max;

    idx = lbl_1_bss_8B614.unk_8;
    v = 0;
    if ((lbl_1_bss_9F8[idx].unk_10 & 1) || (lbl_1_bss_9F8[idx].unk_12 & 1)) {
        v = -1;
    }
    if (((lbl_1_bss_9F8[idx].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[idx].unk_12 >> 1) & 1)) {
        v++;
    }
    if (v != 0) {
        fn_1_A2D84(0xA9010000);
        if (v < 0) {
            lbl_1_bss_8B614.unk_4C = 0;
            lbl_1_bss_8B614.unk_4C |= 0x80000000;
            lbl_1_bss_8B614.unk_50 = v;
            lbl_1_bss_8B614.unk_4C |= 0x20000001;
            lbl_1_bss_8B614.unk_52 = 0;
            lbl_1_bss_8B614.unk_54 = v * 5;
        } else {
            lbl_1_bss_8B614.unk_4C = 0;
            lbl_1_bss_8B614.unk_4C |= 0x80000000;
            lbl_1_bss_8B614.unk_50 = v;
            lbl_1_bss_8B614.unk_4C |= 0x40000001;
            lbl_1_bss_8B614.unk_52 = 0;
            lbl_1_bss_8B614.unk_54 = v * 5;
        }
        for (i = 0; i < 41; i++) {
            if (lbl_16_bss_B060[i] == lbl_1_bss_8B614.unk_C) {
                found = i;
                break;
            }
        }
        do {
            max = lbl_16_bss_B0B2 - 1;
            t = found + v;
            found = (t > max) ? 0 : ((t < 0) ? max : t);
        } while (fn_1_F7BE4(lbl_16_bss_B060[found]) == 0);
        lbl_1_bss_8B614.unk_C = lbl_16_bss_B060[found];
    }
    if ((lbl_1_bss_9F8[idx].unk_8 >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    if ((lbl_1_bss_9F8[idx].unk_8 >> 8) & 1) {
        fn_1_A2D84(0xA9010100);
        return 1;
    }
    return 0;
}
