#include "types.h"

/* fzgx:begin _prolog */
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern struct _prolog_lbl_8_bss_0 lbl_8_bss_0;
extern struct _prolog_lbl_1_bss_58 lbl_1_bss_58;
extern struct _prolog_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct _prolog_lbl_1_bss_960 lbl_1_bss_960;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern s16 lbl_1_bss_964;
extern u32 lbl_8_data_434;

extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_479F0(u32);
extern u32 fn_8_954(void);
extern void fn_8_AA8(void);
extern void fn_8_B7C(void);
extern void fn_1_A8F78(void);

struct _prolog_lbl_8_bss_0 {
    u8 pad_0[0x234];
    u32 unk_234;
    u32 unk_238;
    u8 unk_23C;
    u8 unk_23D;
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_960 {
    s16 unk_0;
};
struct _prolog_lbl_1_bss_58 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};
struct _prolog_lbl_1_bss_8B3A0 {
    u8 pad_0[0x9E];
    u8 unk_9E;
};

void _prolog(void) {
    struct _prolog_lbl_8_bss_0 *p_lbl_8_bss_0;
    s32 t0;
    s32 t1;
    p_lbl_8_bss_0 = (struct _prolog_lbl_8_bss_0 *)&lbl_8_bss_0;
    t0 = fn_1_45D0(lbl_801A6410.unk_0, 0x173c, &lbl_8_data_434, 0x2f1);
    p_lbl_8_bss_0->unk_234 = t0;
    t1 = fn_1_45D0(lbl_801A6410.unk_0, 0x173c, &lbl_8_data_434, 0x2f2);
    p_lbl_8_bss_0->unk_238 = t1;
    fn_1_3CF0(p_lbl_8_bss_0->unk_234, 0x80);
    fn_1_3CF0(p_lbl_8_bss_0->unk_238, 0x80);
    fn_1_479F0(lbl_1_bss_960.unk_0);
    lbl_1_bss_7167C = (u32)fn_8_954;
    lbl_1_bss_71680 = (u32)fn_8_AA8;
    lbl_1_bss_71684 = (u32)fn_8_B7C;
    p_lbl_8_bss_0->unk_23C = 0;
    if (lbl_1_bss_964 == 8 && (s32)lbl_1_bss_58.unk_1C != 0) {
    lbl_1_bss_8B3A0.unk_9E = 0;
    lbl_1_bss_968 = 1;
    } else {
    lbl_1_bss_96A = 158;
    }
    p_lbl_8_bss_0->unk_23D = 0;
    fn_1_A8F78();
}
/* fzgx:end _prolog */

/* fzgx:begin fn_8_954 */
extern struct fn_8_954_lbl_8_bss_0 lbl_8_bss_0;
extern struct fn_8_954_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern struct fn_8_954_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_8_954_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern u8 lbl_801A66B8;
extern u8 lbl_801A66BA;
extern s32 fn_1_4C10(void);
extern s32 fn_1_4CAC(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_A5EFC(void);

struct fn_8_954_lbl_8_bss_0 {
    u8 pad_0[1];
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x235];
    u32 unk_238;
    u8 pad_23C[1];
    u8 unk_23D;
};
struct fn_8_954_lbl_1_bss_9C8 {
    u8 pad_0[0xA];
    s8 unk_A;
};
struct fn_8_954_lbl_1_bss_9F8 {
    u8 pad_0[8];
    u16 unk_8;
};
struct fn_8_954_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[6];
    u8 unk_9E;
};

#pragma opt_dead_code off
#pragma opt_dead_assignments off
#pragma opt_propagation off
static inline s32 check_input(struct fn_8_954_lbl_1_bss_9F8 *unused,
                             struct fn_8_954_lbl_1_bss_9C8 *unused2, s32 unused3) {
    struct fn_8_954_lbl_1_bss_9C8 *q;
    struct fn_8_954_lbl_1_bss_9F8 *w;
    s32 zero;
    s32 result;
    q = &lbl_1_bss_9C8;
    w = &lbl_1_bss_9F8;
    zero = 0;
    if (q->unk_A == 0 && (w->unk_8 & 0x1000) != 0) {
        result = 1;
        lbl_1_bss_8B3A0.unk_9E = zero;
    } else {
        result = 0;
    }
    return result;
}

void fn_8_954(void) {
    struct fn_8_954_lbl_8_bss_0 *p;
    p = &lbl_8_bss_0;
    if (lbl_1_bss_968 != -1 || lbl_1_bss_96A != -1) {
        return;
    }
    {
        if (p->unk_2 == 0 || p->unk_1 == 0) {
            if (p->unk_23D == 0) {
                if (p->unk_2 == 0) {
                    return;
                }
                if (check_input(&lbl_1_bss_9F8, &lbl_1_bss_9C8, 0) == 0) {
                    return;
                }
                if (fn_1_4C10() == 0 || fn_1_4CAC() != 0) {
                    fn_1_4A00(0, 0xF, (void *)p->unk_238);
                }
                p->unk_23D = 1;
                return;
            }
            if (fn_1_4C10() != 0) {
                return;
            }
        }
        if (!lbl_801A66B8) {
            fn_1_A5EFC();
            lbl_801A66B8 = 1;
        }
        lbl_1_bss_8B3A0.unk_94 = 0;
        lbl_1_bss_968 = 1;
        p->unk_23D = 0;
        p->unk_1 = 0;
        lbl_801A66BA = 0;
    }
}
/* fzgx:end fn_8_954 */

/* fzgx:begin fn_8_AA8 */
extern struct fn_8_AA8_lbl_8_bss_234 lbl_8_bss_234;
extern struct fn_8_AA8_lbl_8_bss_238 lbl_8_bss_238;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);

struct fn_8_AA8_lbl_8_bss_234 {
    u32 unk_0;
};
struct fn_8_AA8_lbl_8_bss_238 {
    u32 unk_0;
};

void fn_8_AA8(void) {
    u32 t0, t1, t3;
    t0 = fn_1_435C(lbl_8_bss_234.unk_0);
    t1 = fn_1_407C(t0);
    fn_1_3CC4(t1);
    t3 = fn_1_435C(lbl_8_bss_238.unk_0);
    fn_1_407C(t3);
}
/* fzgx:end fn_8_AA8 */

/* fzgx:begin _epilog */
extern u8 lbl_801A66B9;
extern u32 lbl_8_bss_234;
extern u32 lbl_8_bss_238;
extern s16 lbl_1_bss_960;

extern void fn_1_4FEC(void);
extern void fn_1_C3378(void);
extern void fn_1_F7A20(void);
extern s32 fn_1_3FC38(void);
extern void fn_1_37E98(void);
extern void fn_1_435C(u32);
extern void fn_1_41A8(void);
extern void fn_1_47A60(s16);

#pragma opt_dead_assignments off
void _epilog(void) {
    if (!lbl_801A66B9) {
        fn_1_4FEC();
        fn_1_C3378();
        fn_1_F7A20();
        lbl_801A66B9 = 1;
    }
    if (fn_1_3FC38()) {
        fn_1_37E98();
    }
    fn_1_435C(lbl_8_bss_234);
    fn_1_41A8();
    fn_1_435C(lbl_8_bss_238);
    fn_1_41A8();
    fn_1_47A60(lbl_1_bss_960);
}
#pragma opt_dead_assignments reset
/* fzgx:end _epilog */

/* fzgx:begin fn_8_B7C */
typedef u32 (*fn_8_B7C_Fn0)(void);
struct fn_8_B7C_lbl_8_data_318_0_E16 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_8_B7C_lbl_8_data_318 {
    struct fn_8_B7C_lbl_8_data_318_0_E16 unk_0[1];
};

extern s16 lbl_1_bss_962;
extern struct fn_8_B7C_lbl_8_data_318 lbl_8_data_318;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

void fn_8_B7C(void) {
    struct fn_8_B7C_lbl_8_data_318_0_E16 *p;
    s16 idx;
    p = (struct fn_8_B7C_lbl_8_data_318_0_E16 *)&lbl_8_data_318;
    idx = lbl_1_bss_962;
    p += idx - 153;
    lbl_1_bss_71688 = p->unk_8;
    lbl_1_bss_7168C = p->unk_C;
    ((fn_8_B7C_Fn0)p->unk_4)();
}
/* fzgx:end fn_8_B7C */

/* fzgx:begin fn_8_BD8 */
// fn_8_BD8: empty in retail (single blr).
void fn_8_BD8(void) {
}
/* fzgx:end fn_8_BD8 */

/* fzgx:begin fn_8_BDC */
// fn_8_BDC: empty in retail (single blr).
void fn_8_BDC(void) {
}
/* fzgx:end fn_8_BDC */

/* fzgx:begin fn_8_BE0 */
// fn_8_BE0: empty in retail (single blr).
void fn_8_BE0(void) {
}
/* fzgx:end fn_8_BE0 */

/* fzgx:begin fn_8_BE4 */
struct TitleState {
    u8 unk0[0x2];
    u8 unk2;
    u8 unk3[0x221];
    s16 unk224;
    u8 unk226[0x18];
    u16 unk23e;
    u8 unk240;
};

struct Prng {
    u32 unk0;
};

struct Bss58 {
    u8 unk0[0x15];
    u8 unk15;
};

extern u8 lbl_8_bss_0;
extern char lbl_8_data_0[4];
extern u16 jumptable_8_data_494[15];
extern f32 lbl_8_rodata_C[85];
extern s16 lbl_1_bss_966;
extern u8 lbl_801A66BA;
extern struct Prng lbl_801A63C0;
extern struct Bss58 lbl_1_bss_58;

extern void fn_1_47F74(s32);
extern u32 fn_1_4706C(void);
extern void fn_1_46A60(void);
extern u32 fn_1_47E54(u32);
extern void fn_1_7B084(s16, s32);
extern void fn_1_9A958(s16, s32);
extern void fn_1_7FFF0(void);
extern void fn_1_8001C(void);
extern void *fn_1_7F518(s16, void *, s32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_4100C(void);
extern void fn_1_41104(s32);
extern void fn_8006CE1C(f32);
extern void fn_1_A1340(void);

void fn_8_BE4(void) {
    struct TitleState *state = (struct TitleState *)&lbl_8_bss_0;
    char *data = lbl_8_data_0;
    s32 i;
    int v;

    if (lbl_1_bss_966 != 0xa1) {
        fn_1_47F74(0x8e);
    }

    state->unk23e = 0x1e;

    if (lbl_801A66BA == 0) {
        state->unk2 = 1;
        state->unk240 = 0;
    } else {
        state->unk240 = 1;
    }

    {
        u32 tmp = lbl_801A63C0.unk0 * 0x676a4b6b + 0x33cb;
        s32 t;
        s32 c;
        s32 q;
        s32 idx;

        lbl_801A63C0.unk0 = tmp;
        t = (tmp >> 16) & 0x7fff;
        c = t >> 8;
        q = c / 14;
        idx = c - q * 14;
        switch (idx) {
        case 0: state->unk224 = 1; break;
        case 1: state->unk224 = 16; break;
        case 2: state->unk224 = 8; break;
        case 3: state->unk224 = 26; break;
        case 4: state->unk224 = 5; break;
        case 5: state->unk224 = 14; break;
        case 6: state->unk224 = 7; break;
        case 7: state->unk224 = 11; break;
        case 8: state->unk224 = 13; break;
        case 9: state->unk224 = 3; break;
        case 10: state->unk224 = 15; break;
        case 11: state->unk224 = 10; break;
        case 12: state->unk224 = 29; break;
        case 13: state->unk224 = 9; break;
        case 14: state->unk224 = 27; break;
        default: state->unk224 = 1; break;
        }
    }

    v = lbl_1_bss_58.unk15;
    if ((s8)v == 0 || (s8)v == 2) {
        char buf[0x20];
        s8 i;
        fn_1_4706C();
        fn_1_46A60();
        fn_1_47E54(1);
        fn_1_47E54(3);
        fn_1_7B084(state->unk224, 0);
        fn_1_9A958(state->unk224, 0);
        fn_1_7FFF0();
        fn_1_8001C();
        for (i = 0; i < 41; i++) {
            char tmp[0x20];
            sprintf(buf, data + 0x43c, fn_1_7F518(i, tmp, 0));
            fn_1_465D0(buf, 1);
        }
        fn_1_4100C();
        fn_1_41104(2);
    } else {
        fn_1_4706C();
        fn_1_47E54(1);
        fn_1_47E54(0x87);
        fn_1_465D0(data + 0x450, 1);
        fn_1_465D0(data + 0x464, 1);
        fn_1_465D0(data + 0x478, 1);
        fn_1_41104(1);
        fn_1_47E54(0x9a);
        fn_1_47E54(0x9b);
        fn_1_47E54(0x9d);
        fn_1_47E54(0xa1);
        fn_1_47E54(0x9c);
        fn_1_47E54(0xa2);
    }

    fn_8006CE1C(lbl_8_rodata_C[0]);
    fn_1_A1340();
}
/* fzgx:end fn_8_BE4 */

/* fzgx:begin fn_8_EC4 */
#include "font.h"

typedef struct TitleEntry {
    s32 image;
    u8 flags;
    u8 pad;
    u16 y;
} TitleEntry;

typedef struct TitleColor {
    u8 r, g, b, a;
} TitleColor;

struct Bss58 {
    u8 unk0[0x15];
    s8 unk15;
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 362.0f;
    s = 1.0f;
    s = 0.0f;
    s = 0.4000000059604645f;
    s = 3.5f;
    s = 0.6700000166893005f;
    s = 120.0f;
    s = 2.0f;
    s = 0.75f;
    s = 3.0f;
    s = 16.0f;
    s = 464.0f;
    s = 0.009999999776482582f;
    s = 0.10000000149011612f;
    s = 360.0f;
    s = 240.0f;
    s = 200.0f;
}
#pragma section code_type ".text"

/* title logo lines, two text images per step: -2 = none, -1 = end */
static const TitleEntry fzgx_pool_fn_8_EC4_lines[4][2] = {
    { { -2, 0, 0, 0 }, { -2, 0, 0, 0 } },
    { { 0x8E00, 6, 0, 0x63 }, { 0x8E01, 6, 0, 0x100 } },
    { { 0x8E03, 10, 0, 0xF0 }, { -1, 0, 0, 0 } },
    { { -1, 0, 0, 0 }, { -1, 0, 0, 0 } },
};

extern u8 lbl_801A66BA;
extern s16 lbl_1_bss_96A;
extern struct Bss58 lbl_1_bss_58;
extern FontDrawPacket lbl_1_rodata_26F8;

extern void fn_8_784(u32);
extern f32 fn_1_52070(u32);
extern void fn_80005E0C(void);
extern void fn_1_A1360(void);
extern void fn_80007AB4(TitleColor *);
extern s32 fn_1_4E724(FontDrawPacket *);
extern int fn_1_4C10(void);
extern u32 fn_1_52088(void);
extern void fn_1_3EF8C(u8);
extern u32 fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern u32 fn_1_3EB78(u32, u32, u32, u32);
extern void fn_1_3EFF0(void (*)(u32), u8);
extern void fn_8006CE1C(f32);
extern void fn_1_3EF08(u8);
extern void fn_1_4A00(s32, u8, void *);

/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_8_bss_0;
u8 fzgx_pool_lbl_8_bss_0_gap_1;
u8 fzgx_obj_lbl_8_bss_2;
u8 fzgx_pool_lbl_8_bss_0_gap_3;
u32 lbl_8_bss_4[2];
u32 lbl_8_bss_C[5];
u32 lbl_8_bss_20[129];
s16 lbl_8_bss_224;
u16 fzgx_pool_lbl_8_bss_0_gap_226;
u32 lbl_8_bss_228;
u32 lbl_8_bss_22C;
u8 lbl_8_bss_230;
u8 fzgx_pool_lbl_8_bss_0_gap_231;
u16 fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
u32 fzgx_obj_lbl_8_bss_234;
u32 fzgx_obj_lbl_8_bss_238;
u8 lbl_8_bss_238__fzgx_offset_4;
u8 fzgx_obj_lbl_8_bss_23D;
u16 fzgx_pool_lbl_8_bss_0_gap_23E;
u8 fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
u8 lbl_8_bss_241;
u16 lbl_8_bss_242__fzgx_offset_0;
s32 lbl_8_bss_242__fzgx_offset_2;
u8 lbl_8_bss_242__fzgx_offset_6;
u8 lbl_8_bss_242__fzgx_offset_7;
u16 lbl_8_bss_242__fzgx_offset_8;
u32 lbl_8_bss_242__fzgx_offset_A;
u8 lbl_8_bss_242__fzgx_offset_E;
u8 lbl_8_bss_242__fzgx_offset_F;
u8 lbl_8_bss_242__fzgx_offset_10;
u8 lbl_8_bss_242__fzgx_offset_11;
s32 lbl_8_bss_242__fzgx_offset_12;
s32 lbl_8_bss_242__fzgx_offset_16;
s32 lbl_8_bss_242__fzgx_offset_1A;
u8 lbl_8_bss_242__fzgx_offset_1E;
u8 lbl_8_bss_242__fzgx_offset_1F;
u16 lbl_8_bss_242__fzgx_offset_20;
s32 lbl_8_bss_242__fzgx_offset_22;
u8 lbl_8_bss_242__fzgx_offset_26;
u8 lbl_8_bss_242__fzgx_offset_27;
u16 lbl_8_bss_242__fzgx_offset_28;
u32 lbl_8_bss_242__fzgx_offset_2A[15];
u16 fzgx_obj_lbl_8_bss_2A8;
u16 fzgx_pool_lbl_8_bss_0_gap_2AA;
u32 fzgx_obj_lbl_8_bss_2AC;
u32 fzgx_obj_lbl_8_bss_2B0;
u32 lbl_8_bss_2B4;
u32 lbl_8_bss_2B8;
u32 lbl_8_bss_2BC;
u32 fzgx_obj_lbl_8_bss_2C0[67];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_0;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_1;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_3;
    s = *(u8 *)&lbl_8_bss_4;
    s = *(u8 *)&lbl_8_bss_C;
    s = *(u8 *)&lbl_8_bss_20;
    s = *(u8 *)&lbl_8_bss_224;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_226;
    s = *(u8 *)&lbl_8_bss_228;
    s = *(u8 *)&lbl_8_bss_22C;
    s = *(u8 *)&lbl_8_bss_230;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_234;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_238;
    s = *(u8 *)&lbl_8_bss_238__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_23D;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    s = *(u8 *)&lbl_8_bss_241;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_0;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_2;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_6;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_7;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_8;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_A;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_E;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_F;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_10;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_11;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_12;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_16;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1A;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1E;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1F;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_20;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_22;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_26;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_27;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_28;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_2A;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2A8;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_2AA;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2AC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2B0;
    s = *(u8 *)&lbl_8_bss_2B4;
    s = *(u8 *)&lbl_8_bss_2B8;
    s = *(u8 *)&lbl_8_bss_2BC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2C0;
}
#pragma section code_type ".text"


void fn_8_EC4(void) {
    s32 step;
    u16 timer;
    s32 mode;
    FontDrawPacket packet;

    fn_1_52070(320);
    fn_80005E0C();
    fn_80005E0C();
    if (fzgx_pool_lbl_8_bss_0_gap_23E != 0) {
        fzgx_pool_lbl_8_bss_0_gap_23E--;
    }
    fn_1_A1360();
    {
        TitleColor color = { 0, 0, 0, 0 };
        fn_80007AB4(&color);
    }

    step = fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    if (fzgx_pool_fn_8_EC4_lines[step][0].image != -2) {
        packet = lbl_1_rodata_26F8;
        packet.x = 320.0f;
        packet.z = 3.0f;
        if (fzgx_pool_lbl_8_bss_0_gap_23E > 30) {
            packet.alpha = 1.0f;
        } else {
            packet.alpha = (f32)fzgx_pool_lbl_8_bss_0_gap_23E / 30.0f;
        }
        packet.image = fzgx_pool_fn_8_EC4_lines[step][0].image;
        packet.flags = fzgx_pool_fn_8_EC4_lines[step][0].flags;
        packet.y = fzgx_pool_fn_8_EC4_lines[step][0].y;
        fn_1_4E724(&packet);
        if (fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].image != -1) {
            packet.image = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].image;
            packet.flags = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].flags;
            packet.y = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].y;
            fn_1_4E724(&packet);
        }
    }

    if (lbl_8_bss_241) {
        if (fn_1_4C10()) {
            fn_1_52088();
            return;
        }
        if (lbl_801A66BA) {
            lbl_1_bss_96A = 0x99;
            lbl_801A66BA = 0;
        } else {
            mode = lbl_1_bss_58.unk15;
            switch (mode) {
            case 1:
            case 3:
                lbl_1_bss_96A = 0xa4;
                break;
            case 0:
            case 2:
            default:
                lbl_1_bss_96A = 0x9c;
                break;
            }
            lbl_1_bss_58.unk15 = (mode + 1) & 3;
            if (lbl_1_bss_96A == 0x9c) {
                fn_1_3EF8C(6);
                fn_1_3ED8C(0, 3, 1, (u8)lbl_8_bss_224, 10, 30, 0);
                fn_1_3EB78(0, 0, 0, 0);
                fn_1_3EFF0(fn_8_784, 1);
                fn_8006CE1C(1.0f);
                fn_1_3EF08(1);
            }
        }
        fn_1_52088();
        return;
    }

    timer = fzgx_pool_lbl_8_bss_0_gap_23E;
    if (timer > 30) {
        fn_1_52088();
        return;
    }
    step = fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    if (fzgx_pool_fn_8_EC4_lines[step + 1][0].image == -1) {
        if (fn_1_4C10()) {
            fn_1_52088();
            return;
        }
        fn_1_4A00(0, 0xf, (void *)fzgx_obj_lbl_8_bss_238);
        lbl_8_bss_241 = 1;
        fn_1_52088();
        return;
    }
    packet = lbl_1_rodata_26F8;
    packet.z = 2.0f;
    packet.x = 320.0f;
    packet.alpha = (f32)(30 - timer) / 30.0f;
    packet.image = fzgx_pool_fn_8_EC4_lines[step + 1][0].image;
    packet.flags = fzgx_pool_fn_8_EC4_lines[step + 1][0].flags;
    packet.y = fzgx_pool_fn_8_EC4_lines[step + 1][0].y;
    fn_1_4E724(&packet);
    if (fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].image != -1) {
        packet.image = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].image;
        packet.flags = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].flags;
        packet.y = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].y;
        fn_1_4E724(&packet);
    }
    if (fzgx_pool_lbl_8_bss_0_gap_23E == 0) {
        fzgx_pool_lbl_8_bss_0_gap_23E = 0x118;
        fzgx_pool_lbl_8_bss_0_gap_23E_fill_240++;
    }
    fn_1_52088();
}
/* fzgx:end fn_8_EC4 */

/* fzgx:begin fn_8_1304 */
extern u32 fn_1_48140(u32);
extern u32 fn_1_A1364(u32);
extern u32 fn_1_A8F78(void);
extern u8 lbl_8_bss_241;
extern u8 lbl_8_bss_2;

void fn_8_1304(void) {
    u32 t1;
    lbl_8_bss_2 = 0;
    lbl_8_bss_241 = 0;
    fn_1_A8F78();
    t1 = fn_1_48140(142);
    fn_1_A1364(t1);
}
/* fzgx:end fn_8_1304 */

/* fzgx:begin fn_8_1344 */
struct fn_8_1344_lbl_8_bss_4 {
    f32 unk_0;
};
extern struct fn_8_1344_lbl_8_bss_4 lbl_8_bss_4;
extern u8 lbl_8_bss_242;
extern u32 fn_1_47F74(u32);

void fn_8_1344(void) {
    lbl_8_bss_242 = 0;
    lbl_8_bss_4.unk_0 = 0.0f;
    fn_1_47F74(1);
    fn_1_47F74(3);
}
/* fzgx:end fn_8_1344 */

/* fzgx:begin fn_8_1394 */
#include "font.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 362.0f;
    s = 1.0f;
    s = 0.0f;
    s = 0.4000000059604645f;
    s = 3.5f;
    s = 0.6700000166893005f;
    s = 120.0f;
    s = 2.0f;
    s = 0.75f;
    s = 3.0f;
    s = 16.0f;
    s = 464.0f;
    s = 0.009999999776482582f;
    s = 0.10000000149011612f;
    s = 360.0f;
    s = 240.0f;
    s = 200.0f;
}
static const u32 fzgx_pool_table2[17] = {0xFFFFFFFE, 0x00000000, 0xFFFFFFFE, 0x00000000, 0x00008E00, 0x06000063, 0x00008E01, 0x06000100, 0x00008E03, 0x0A0000F0, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 180.0f;
    s = 10860.0f;
    s = 1020.0f;
}
#pragma section code_type ".text"

struct fn_8_1394_Copy88 { u32 a[22]; };
struct fn_8_1394_lbl_8_bss_0 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x1];
    f32 unk_4;
    u8 pad_8[0x218];
    f32 unk_220;
    u8 pad_224[0x4];
    u32 unk_228;
    u8 pad_22C[0x16];
    u8 unk_242;
};
extern f32 fn_1_52070(u32);
extern int fn_1_3F038(void);
extern int fn_1_4C10(void);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_465D0(s32, s32);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u16 lbl_1_bss_96A;
extern u32 fn_1_47E54(u32);
extern u32 fn_1_52088(void);
extern u32 fn_1_5370(s8, u32);
extern u32 fn_8_0();
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A0;
extern int fn_1_3FC38(void);
extern void fn_1_3EF14(void *);
extern void fn_1_3FC68(s32);
extern void fn_1_41104(void *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_8_bss_0;
u8 fzgx_pool_lbl_8_bss_0_gap_1;
u8 fzgx_obj_lbl_8_bss_2;
u8 fzgx_pool_lbl_8_bss_0_gap_3;
f32 lbl_8_bss_4;
u32 lbl_8_bss_4__fzgx_offset_4;
u32 lbl_8_bss_C[5];
u32 lbl_8_bss_20__fzgx_offset_0[128];
f32 lbl_8_bss_20__fzgx_offset_200;
u16 lbl_8_bss_224;
u16 fzgx_pool_lbl_8_bss_0_gap_226;
u32 lbl_8_bss_228;
u32 lbl_8_bss_22C;
u8 lbl_8_bss_230;
u8 fzgx_pool_lbl_8_bss_0_gap_231;
u16 fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
u32 fzgx_obj_lbl_8_bss_234;
u32 fzgx_obj_lbl_8_bss_238;
u8 lbl_8_bss_238__fzgx_offset_4;
u8 fzgx_obj_lbl_8_bss_23D;
u16 fzgx_pool_lbl_8_bss_0_gap_23E;
u8 fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
u8 lbl_8_bss_241;
u8 fzgx_obj_lbl_8_bss_242;
u8 lbl_8_bss_242__fzgx_offset_1;
u32 lbl_8_bss_242__fzgx_offset_2[25];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_0;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_1;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_3;
    s = *(u8 *)&lbl_8_bss_4;
    s = *(u8 *)&lbl_8_bss_4__fzgx_offset_4;
    s = *(u8 *)&lbl_8_bss_C;
    s = *(u8 *)&lbl_8_bss_20__fzgx_offset_0;
    s = *(u8 *)&lbl_8_bss_20__fzgx_offset_200;
    s = *(u8 *)&lbl_8_bss_224;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_226;
    s = *(u8 *)&lbl_8_bss_228;
    s = *(u8 *)&lbl_8_bss_22C;
    s = *(u8 *)&lbl_8_bss_230;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_234;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_238;
    s = *(u8 *)&lbl_8_bss_238__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_23D;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    s = *(u8 *)&lbl_8_bss_241;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_242;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_2;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("vehicle/vehicle_sel.arc.lz");
}
#pragma section code_type ".text"

#pragma opt_common_subs off
u32 fn_8_1394(void) {
    f32 fn_8_1394_zero;
    u32 v1;
    f32 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    f32 v8;
    u32 v9;
    f32 v10;
    f32 v11;
    f32 v14;
    u32 v15;
    u32 v16;
    f32 v18;
    f32 v19;
    f32 v20;
    f32 v21;
    f32 v22;
    f32 v24;
    u32 v25;
    u32 v26;
    f32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v33;
    u32 v34;
    f32 v35;
    f32 v36;
    u32 v40;
    u32 v41;
    s16 v50;
    s16 v49;
    s32 v51;
    f32 v52;
    f32 unk_4;
    f32 unk_1;
    struct { u32 a[1326]; } loc_270;
    FontDrawPacket loc_218;
    FontDrawPacket loc_1C0;
    FontDrawPacket loc_168;
    FontDrawPacket loc_110;
    FontDrawPacket loc_B8;
    struct fn_8_1394_Copy88 loc_60;
    struct fn_8_1394_Copy88 loc_8;
    /* frame */
    int t25;
    u32 t26;
    f32 t27;
    int t29;
    u32 t30;
    f32 t31;
    u32 t32;
    f32 t33;
    u16 t34;
    u16 t35;
    u16 t36;
    int t38;
    u32 t39;
    int t40;
    u32 t41;
    s32 t42;
    u32 t44;
    u32 v45;
    f32 v46;
    f32 v47;

    
    v1 = lbl_8_bss_228;
    lbl_8_bss_20__fzgx_offset_200 = 1.0f;
    if ((s32)v1 > 10980 && (s32)v1 <= 11040) {
    v3 = (f32)(s32)(11040 - v1);
    v4 = (v3 / 60.0f);
    fn_1_52070(320);
    loc_218 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v5 = 320.0f;
    v6 = 120.0f;
    loc_218.image = 768;
    loc_218.x = v5;
    loc_218.y = v6;
    loc_218.z = 2.0f;
    loc_218.flags = 6;
    loc_218.color[0] = 255;
    loc_218.color[1] = 255;
    loc_218.color[2] = 255;
    loc_218.alpha = v4;
    loc_218.flags = loc_218.flags | 0x4000000;
    loc_218.vertex_callback = (void (*)(FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_218);
    v8 = (0.75f * v4);
    v9 = (loc_218.flags & 0xFBFFFFFF);
    loc_218.image = 770;
    loc_218.flags = v9;
    loc_218.alpha = v8;
    loc_218.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_218);
    lbl_8_bss_20__fzgx_offset_200 = (1.0f - v4);
    fn_1_52088();
    }
    if ((s32)lbl_8_bss_228 > 10680 && (s32)lbl_8_bss_228 <= 10980) {
    fn_1_52070(320);
    loc_1C0 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v10 = 320.0f;
    v11 = 120.0f;
    loc_1C0.image = 768;
    loc_1C0.x = v10;
    loc_1C0.y = v11;
    loc_1C0.z = 2.0f;
    loc_1C0.flags = 6;
    loc_1C0.color[0] = 255;
    loc_1C0.color[1] = 255;
    loc_1C0.color[2] = 255;
    loc_1C0.alpha = 1.0f;
    loc_1C0.flags = loc_1C0.flags | 0x4000000;
    loc_1C0.vertex_callback = (void (*)(FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_1C0);
    v14 = 0.75f;
    v15 = (loc_1C0.flags & 0xFBFFFFFF);
    loc_1C0.flags = v15;
    loc_1C0.image = 770;
    loc_1C0.alpha = v14;
    loc_1C0.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_1C0);
    lbl_8_bss_20__fzgx_offset_200 = 0.0f;
    fn_1_52088();
    }
    v16 = lbl_8_bss_228;
    if ((s32)v16 > 10620 && (s32)v16 <= 10680) {
    v18 = 1.0f;
    v19 = (f32)(s32)(10680 - v16);
    v20 = (v18 - (v19 / 60.0f));
    fn_1_52070(320);
    loc_168 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v21 = 320.0f;
    v22 = 120.0f;
    loc_168.image = 768;
    loc_168.x = v21;
    loc_168.y = v22;
    loc_168.z = 2.0f;
    loc_168.flags = 6;
    loc_168.color[0] = 255;
    loc_168.color[1] = 255;
    loc_168.color[2] = 255;
    loc_168.alpha = v20;
    loc_168.flags = loc_168.flags | 0x4000000;
    loc_168.vertex_callback = (void (*)(FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_168);
    v24 = (0.75f * v20);
    v25 = (loc_168.flags & 0xFBFFFFFF);
    loc_168.image = 770;
    loc_168.flags = v25;
    loc_168.alpha = v24;
    loc_168.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_168);
    lbl_8_bss_20__fzgx_offset_200 = (1.0f - v20);
    fn_1_52088();
    }
    if ((s32)fn_1_3FC38() != 0 && (s32)lbl_8_bss_228 == 1200) {
    fn_1_5370(4, 0);
    fn_1_3FC68(0);
    }
    v26 = lbl_8_bss_228;
    if ((s32)v26 > 1020 && (s32)v26 <= 1200) {
    v28 = (f32)(s32)(1200 - v26);
    v29 = (v28 / 180.0f);
    fn_1_52070(320);
    loc_110 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v30 = 320.0f;
    v31 = 120.0f;
    loc_110.image = 768;
    loc_110.x = v30;
    loc_110.y = v31;
    loc_110.z = 2.0f;
    loc_110.flags = 6;
    loc_110.color[0] = 255;
    loc_110.color[1] = 255;
    loc_110.color[2] = 255;
    loc_110.alpha = v29;
    loc_110.flags = loc_110.flags | 0x4000000;
    loc_110.vertex_callback = (void (*)(FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_110);
    v33 = (0.75f * v29);
    v34 = (loc_110.flags & 0xFBFFFFFF);
    loc_110.image = 770;
    loc_110.flags = v34;
    loc_110.alpha = v33;
    loc_110.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_110);
    lbl_8_bss_20__fzgx_offset_200 = (1.0f - v29);
    fn_1_52088();
    }
    if ((s32)lbl_8_bss_228 <= 1020) {
    fn_1_52070(320);
    loc_B8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v35 = 320.0f;
    v36 = 120.0f;
    loc_B8.image = 768;
    loc_B8.x = v35;
    loc_B8.y = v36;
    loc_B8.z = 2.0f;
    loc_B8.flags = 6;
    loc_B8.color[0] = 255;
    loc_B8.color[1] = 255;
    loc_B8.color[2] = 255;
    loc_B8.alpha = 1.0f;
    loc_B8.flags = loc_B8.flags | 0x4000000;
    loc_B8.vertex_callback = (void (*)(FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_B8);
    v40 = (loc_B8.flags & 0xFBFFFFFF);
    loc_B8.flags = v40;
    loc_B8.image = 770;
    loc_B8.alpha = 0.75f;
    loc_B8.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_B8);
    lbl_8_bss_20__fzgx_offset_200 = 0.0f;
    fn_1_52088();
    }
    fn_1_3EF14((void *)&loc_270);
    v41 = lbl_8_bss_228;
    if (10860.0f <= (f32)(s32)v41) {
    fzgx_obj_lbl_8_bss_2 = 0;
    loc_270.a[0] = (loc_270.a[0] & 0xFFFFFFFB);
    } else {
    if (1020.0f <= (f32)(s32)v41 && (s32)v41 <= 1200) {
    fzgx_obj_lbl_8_bss_2 = 0;
    loc_270.a[0] = (loc_270.a[0] & 0xFFFFFFFB);
    } else {
    fzgx_obj_lbl_8_bss_2 = 1;
    loc_270.a[0] = (loc_270.a[0] | 4);
    }
    }
    if ((s32)v41 == 15 && (s32)fn_1_4C10() == 0) {
    fzgx_obj_lbl_8_bss_242 = 1;
    }
    if (fzgx_obj_lbl_8_bss_242 != 0) {
    t25 = fn_1_3F038();
    v45 = t25;
    if ((s32)v45 != 0) {
    if (fzgx_obj_lbl_8_bss_0 != 0) {
    fzgx_pool_lbl_8_bss_0_gap_1 = 1;
    fzgx_obj_lbl_8_bss_0 = 0;
    } else {
    lbl_1_bss_96A = 158;
    }
    }
    t26 = fn_1_52088();
    v45 = t26;
    } else {
    t27 = fn_1_52070(96);
    v46 = t27;
    loc_60 = *(struct fn_8_1394_Copy88 *)&lbl_1_rodata_26F8;
    v47 = 16.0f;
    v46 = 464.0f;
    loc_60.a[0] = 256;
    *(f32 *)((u8 *)&loc_60 + 4) = v47;
    *(f32 *)((u8 *)&loc_60 + 8) = v46;
    *(f32 *)((u8 *)&loc_60 + 12) = 0.01f;
    loc_60.a[12] = 13;
    fn_1_51678((FontDrawPacket *)&loc_60, 256, 0, 0, 250, 34);
    t29 = fn_1_4F734((FontDrawPacket *)&loc_60);
    v45 = t29;
    t30 = fn_1_52088();
    v45 = t30;
    t31 = fn_1_52070(544);
    v46 = t31;
    lbl_8_bss_20__fzgx_offset_200 = 1.0f;
    t32 = fn_1_52088();
    v45 = t32;
    t33 = fn_1_52070(320);
    v46 = t33;
    if (fzgx_obj_lbl_8_bss_2 != 0 && (lbl_801A66A0 & 0x18) != 0) {
    loc_8 = *(struct fn_8_1394_Copy88 *)&lbl_1_rodata_26F8;
    loc_8.a[0] = 258;
    v49 = (s16)((fn_1_486C4(loc_8.a[0]) >> 2) & 0x3FFF);
    v50 = (s16)fn_1_48690(loc_8.a[0]);
    v51 = (s16)(((fn_1_486C4(loc_8.a[0]) >> 2) & 0x3FFF) * 3);
    fn_1_51678((FontDrawPacket *)&loc_8, loc_8.a[0], 0, (s16)v51, v50, v49);
    v52 = 320.0f;
    v46 = 362.0f;
    *(f32 *)((u8 *)&loc_8 + 4) = v52;
    *(f32 *)((u8 *)&loc_8 + 8) = v46;
    *(f32 *)((u8 *)&loc_8 + 12) = 1.0f;
    loc_8.a[12] = 6;
    t38 = fn_1_4F734((FontDrawPacket *)&loc_8);
    v45 = t38;
    }
    t39 = fn_1_52088();
    v45 = t39;
    t40 = fn_1_3F038();
    v45 = t40;
    if ((s32)v45 != 0) {
    if (fzgx_obj_lbl_8_bss_0 != 0) {
    fzgx_pool_lbl_8_bss_0_gap_1 = 1;
    fzgx_obj_lbl_8_bss_0 = 0;
    } else {
    lbl_1_bss_96A = 155;
    }
    }
    t41 = fn_1_52088();
    v45 = t41;
    unk_4 = lbl_8_bss_4;
    if ((fn_8_1394_zero = 0.0f, unk_4 == fn_8_1394_zero)) {
    t42 = fn_1_465D0((s32)(u8 *)"vehicle/vehicle_sel.arc.lz", 1);
    v45 = t42;
    fn_1_41104((void *)1);
    fn_1_47E54(154);
    fn_1_47E54(155);
    fn_1_47E54(157);
    fn_1_47E54(161);
    v45 = fn_1_47E54(156);
    v45 = fn_1_47E54(162);
    lbl_8_bss_4 = 1.0f;
    }
    }
    return v45;
}
#pragma opt_common_subs reset
/* fzgx:end fn_8_1394 */

/* fzgx:begin fn_8_1C08 */
// fn_8_1C08: empty in retail (single blr).
void fn_8_1C08(void) {
}
/* fzgx:end fn_8_1C08 */

/* fzgx:begin fn_8_1C0C */
// fn_8_1C0C: empty in retail (single blr).
void fn_8_1C0C(void) {
}
/* fzgx:end fn_8_1C0C */

/* fzgx:begin fn_8_1C10 */
// fn_8_1C10: empty in retail (single blr).
void fn_8_1C10(void) {
}
/* fzgx:end fn_8_1C10 */

/* fzgx:begin fn_8_1C14 */
// fn_8_1C14: empty in retail (single blr).
void fn_8_1C14(void) {
}
/* fzgx:end fn_8_1C14 */

/* fzgx:begin fn_8_1C18 */
struct fn_8_1C18_lbl_8_bss_0 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0x221];
    s16 unk_224;
    u8 pad_226[0x12];
    u32 unk_238;
};

extern f32 lbl_8_rodata_C;
extern struct fn_8_1C18_lbl_8_bss_0 lbl_8_bss_0;
extern u32 fn_1_4706C(void);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_9A958(u32, u32);
extern u32 lbl_1_bss_970;
extern void fn_1_7B084(void *, int);
extern void fn_8006CE1C(f32);

#pragma opt_loop_invariants off
void fn_8_1C18(void) {
    struct fn_8_1C18_lbl_8_bss_0 *p_lbl_8_bss_0;
    p_lbl_8_bss_0 = (struct fn_8_1C18_lbl_8_bss_0 *)&lbl_8_bss_0;
    fn_8006CE1C((0.0f));
    fn_1_4A00(1, 15, p_lbl_8_bss_0->unk_238);
    lbl_1_bss_970 = 600;
    fn_1_4706C();
    fn_1_7B084((void *)p_lbl_8_bss_0->unk_224, 0);
    fn_1_9A958(p_lbl_8_bss_0->unk_224, 0);
    p_lbl_8_bss_0->unk_2 = 1;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_8_1C18 */

/* fzgx:begin fn_8_1C90 */
#include "font.h"

struct fn_8_1C90_Copy88 { u32 a[22]; };
struct fn_8_1C90_lbl_8_rodata_0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0xC];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
};
struct fn_8_1C90_lbl_8_bss_0 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0x21D];
    f32 unk_220;
    u8 pad_224[0x14];
    u32 unk_238;
};
struct fn_8_1C90_lbl_1_bss_970 {
    s32 unk_0;
};

extern int fn_1_4C10(void);
extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_8_1C90_lbl_1_bss_970 lbl_1_bss_970;
extern struct fn_8_1C90_lbl_8_bss_0 lbl_8_bss_0;
extern struct fn_8_1C90_lbl_8_rodata_0 lbl_8_rodata_0;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u16 lbl_1_bss_96A;
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_8_0();
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A0;
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_1_52070(u32);
extern void fn_1_52088(void);

void fn_8_1C90(void) {
    struct fn_8_1C90_lbl_8_bss_0 *p_lbl_8_bss_0;
    struct fn_8_1C90_lbl_8_rodata_0 *p_lbl_8_rodata_0;
    struct fn_8_1C90_lbl_1_bss_970 *p_bss_970;
    f32 v1;
    f32 v0;
    s16 v3;
    s16 v2;
    f32 v5;
    f32 v4;
    f32 v7;
    f32 v6;
    f32 v8;
    u32 v9;
    f32 v10;
    u16 t7;
    u16 t8;
    u16 t9;
    u32 v11;
    s32 v12;
    s32 v13;
    FontDrawPacket loc_B8;
    FontDrawPacket loc_60;
    FontDrawPacket loc_8;
    p_lbl_8_bss_0 = (struct fn_8_1C90_lbl_8_bss_0 *)&lbl_8_bss_0;
    p_lbl_8_rodata_0 = (struct fn_8_1C90_lbl_8_rodata_0 *)&lbl_8_rodata_0;
    fn_1_52070(96);
    loc_B8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = p_lbl_8_rodata_0->unk_2C;
    v1 = p_lbl_8_rodata_0->unk_30;
    loc_B8.image = 256;
    loc_B8.x = v0;
    loc_B8.y = v1;
    loc_B8.z = p_lbl_8_rodata_0->unk_34;
    loc_B8.flags = 13;
    fn_1_51678((FontDrawPacket *)&loc_B8, 256, 0, 0, 250, 34);
    fn_1_4F734((FontDrawPacket *)&loc_B8);
    fn_1_52088();
    fn_1_52070(544);
    p_lbl_8_bss_0->unk_220 = p_lbl_8_rodata_0->unk_8;
    fn_1_52088();
    fn_1_52070(320);
    if (p_lbl_8_bss_0->unk_2 != 0 && (lbl_801A66A0 & 0x18) != 0) {
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_8.image = 258;
        v2 = (s16)((fn_1_486C4((u32)loc_8.image) >> 2) & 0x3FFF);
        v3 = (s16)fn_1_48690((u32)loc_8.image);
        fn_1_51678((FontDrawPacket *)&loc_8, (u32)loc_8.image, 0,
                   (s16)(((fn_1_486C4((u32)loc_8.image) >> 2) & 0x3FFF) * 3),
                   v3, v2);
        loc_8.x = p_lbl_8_rodata_0->unk_0;
        loc_8.y = p_lbl_8_rodata_0->unk_4;
        loc_8.z = p_lbl_8_rodata_0->unk_8;
        loc_8.flags = 6;
        fn_1_4F734((FontDrawPacket *)&loc_8);
    }
    fn_1_52088();
    fn_1_52070(320);
    loc_60 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v6 = p_lbl_8_rodata_0->unk_0;
    v7 = p_lbl_8_rodata_0->unk_1C;
    v8 = p_lbl_8_rodata_0->unk_20;
    loc_60.image = 768;
    loc_60.flags = 6;
    loc_60.x = p_lbl_8_rodata_0->unk_0;
    loc_60.y = p_lbl_8_rodata_0->unk_1C;
    loc_60.z = p_lbl_8_rodata_0->unk_20;
    loc_60.color[0] = 255;
    loc_60.color[1] = 255;
    loc_60.color[2] = 255;
    loc_60.alpha = p_lbl_8_rodata_0->unk_8;
    loc_60.flags |= 0x4000000;
    loc_60.vertex_callback = (void (*)(FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_60);
    v10 = p_lbl_8_rodata_0->unk_24;
    v11 = (loc_60.flags & 0xFBFFFFFF);
    loc_60.flags = v11;
    loc_60.image = 770;
    loc_60.alpha = v10;
    loc_60.z = p_lbl_8_rodata_0->unk_28;
    fn_1_4F734((FontDrawPacket *)&loc_60);
    p_lbl_8_bss_0->unk_220 = p_lbl_8_rodata_0->unk_C;
    fn_1_52088();
    p_bss_970 = &lbl_1_bss_970;
    if (p_bss_970->unk_0 != 0) {
        v13 = --p_bss_970->unk_0;
        if (v13 == 15 && fn_1_4C10() == 0) {
            fn_1_4A00(0, 15, p_lbl_8_bss_0->unk_238);
        }
    } else {
        if (fn_1_4C10() == 0) {
            lbl_1_bss_96A = 158;
        }
    }
}
/* fzgx:end fn_8_1C90 */

/* fzgx:begin fn_8_1F64 */
extern u8 lbl_8_bss_2;

void fn_8_1F64(void) {
    lbl_8_bss_2 = 0;
}
/* fzgx:end fn_8_1F64 */

/* fzgx:begin fn_8_1F74 */
extern f32 lbl_8_rodata_C;
extern u32 fn_1_A5EFC(void);
extern u32 fn_8006CE1C(f32);
extern u8 lbl_801A66B8;

void fn_8_1F74(void) {
    fn_8006CE1C(lbl_8_rodata_C);
    if (lbl_801A66B8 == 0) {
    fn_1_A5EFC();
    }
}
/* fzgx:end fn_8_1F74 */

/* fzgx:begin fn_8_1FB0 */
extern const f32 lbl_8_rodata_8;

extern s32 fn_1_A66FC(s32);
extern void fn_1_4FEC(void);
extern u32 fn_1_C3378(void);
extern u32 fn_1_F7A20(void);
extern void fn_1_3EF8C(u8);
extern u32 fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern u32 fn_1_3EB78(u32, u32, u32, u32);
extern void fn_1_3EFF0(void (*)(u32), u8);
extern void fn_8006CE1C(f32);
extern void fn_1_3EF08(u8);
extern void fn_8_784(u32);

extern u8 lbl_801A66B8;
extern u8 lbl_801A66B9;
extern s32 lbl_1_bss_7180C;
extern s16 lbl_1_bss_96A;

struct fn_8_1FB0_lbl_1_bss_58 {
    u8 pad_0[0x15];
    s8 unk_15;
};
extern struct fn_8_1FB0_lbl_1_bss_58 lbl_1_bss_58;

struct fn_8_1FB0_lbl_8_bss_224 {
    s16 unk_0;
};
extern struct fn_8_1FB0_lbl_8_bss_224 lbl_8_bss_224;

struct fn_8_1FB0_lbl_8_bss_238 {
    u32 unk_0;
};
extern struct fn_8_1FB0_lbl_8_bss_238 lbl_8_bss_238;

f32 fn_8_1FB0(f32 arg0) {
    s32 v2;

    if (lbl_801A66B8 != 0 || fn_1_A66FC(lbl_8_bss_238.unk_0) != 0) {
        if (lbl_1_bss_7180C == 0) {
            if (lbl_801A66B9 == 0) {
                fn_1_4FEC();
                fn_1_C3378();
                fn_1_F7A20();
                lbl_801A66B9 = 1;
            }
            v2 = lbl_1_bss_58.unk_15;
            switch (v2) {
            case 1:
            case 3:
                lbl_1_bss_96A = 0xa4;
                break;
            case 0:
            case 2:
            default:
                lbl_1_bss_96A = 0x9c;
                break;
            }
            lbl_1_bss_58.unk_15 = (v2 + 1) & 3;
            if (lbl_1_bss_96A == 0x9c) {
                fn_1_3EF8C(6);
                fn_1_3ED8C(0, 3, 1, lbl_8_bss_224.unk_0 & 0xff, 10, 30, 0);
                fn_1_3EB78(0, 0, 0, 0);
                fn_1_3EFF0(&fn_8_784, 1);
                fn_8006CE1C(lbl_8_rodata_8);
                fn_1_3EF08(1);
            }
        } else {
            lbl_1_bss_96A = 0x9a;
        }
        lbl_801A66B8 = 1;
    }
}
/* fzgx:end fn_8_1FB0 */

/* fzgx:begin fn_8_2120 */
// fn_8_2120: empty in retail (single blr).
void fn_8_2120(void) {
}
/* fzgx:end fn_8_2120 */

/* fzgx:begin fn_8_2124 */
#include "rel/title/title.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 362.0f;
    s = 1.0f;
    s = 0.0f;
    s = 0.4000000059604645f;
    s = 3.5f;
    s = 0.6700000166893005f;
    s = 120.0f;
    s = 2.0f;
    s = 0.75f;
    s = 3.0f;
    s = 16.0f;
    s = 464.0f;
    s = 0.009999999776482582f;
    s = 0.10000000149011612f;
    s = 360.0f;
    s = 240.0f;
    s = 200.0f;
}
static const u32 fzgx_pool_table2[17] = {0xFFFFFFFE, 0x00000000, 0xFFFFFFFE, 0x00000000, 0x00008E00, 0x06000063, 0x00008E01, 0x06000100, 0x00008E03, 0x0A0000F0, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static inline void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 180.0f;
    s = 10860.0f;
    s = 1020.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 500.0f;
    s = 400.0f;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table6[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 300.0f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -1.0f;
    s = 8.0f;
    s = 0.5f;
    s = 4.0f;
    s = 190.0f;
    s = 0.07000000029802322f;
    s = 0.550000011920929f;
    s = 150.0f;
}
static const u32 fzgx_pool_table10[1] = {0xA0505000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table11[1] = {0xA0A0A000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table12[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table13[1] = {0x70707000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table15[1] = {0x70707000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table17[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 288.0f;
    s = 10.0f;
    s = 352.0f;
}
static const u32 fzgx_pool_table19[1] = {0xA0505000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_8_2124_pool {
    u8 pad_0[8];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x14];
    f32 unk_24;
    u8 pad_28[0x70];
    f64 unk_98;
    u8 pad_A0[0x38];
    f32 unk_D8;
    f32 unk_DC;
    u8 pad_E0[0x10];
    u32 unk_F0, unk_F4, unk_F8, unk_FC;
    u32 unk_100, unk_104, unk_108, unk_10C;
    f32 unk_110, unk_114, unk_118;
};
const u8 fzgx_pool_lbl_8_rodata_0[8] = {0x43,0xA0,0x00,0x00,0x43,0xB5,0x00,0x00};
const f32 fzgx_pool_lbl_8_rodata_8 = 1.0f;
const f32 fzgx_pool_lbl_8_rodata_C = 0.0f;
const u8 fzgx_pool_lbl_8_rodata_C__fzgx_offset_4[20] = {0x3E,0xCC,0xCC,0xCD,0x40,0x60,0x00,0x00,0x3F,0x2B,0x85,0x1F,0x42,0xF0,0x00,0x00,0x40,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_8_rodata_C__fzgx_offset_18 = 0.75f;
const u8 fzgx_pool_lbl_8_rodata_C__fzgx_offset_1C[112] = {0x40,0x40,0x00,0x00,0x41,0x80,0x00,0x00,0x43,0xE8,0x00,0x00,0x3C,0x23,0xD7,0x0A,0x3D,0xCC,0xCC,0xCD,0x43,0xB4,0x00,0x00,0x43,0x70,0x00,0x00,0x43,0x48,0x00,0x00,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x8E,0x00,0x06,0x00,0x00,0x63,0x00,0x00,0x8E,0x01,0x06,0x00,0x01,0x00,0x00,0x00,0x8E,0x03,0x0A,0x00,0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0xF0,0x00,0x00,0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f64 fzgx_pool_lbl_8_rodata_C__fzgx_offset_8C = 4503601774854144.0;
const u8 fzgx_pool_lbl_8_rodata_C__fzgx_offset_94[56] = {0x42,0x70,0x00,0x00,0x43,0x34,0x00,0x00,0x46,0x29,0xB0,0x00,0x44,0x7F,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x43,0xFA,0x00,0x00,0x43,0xC8,0x00,0x00,0x3D,0xA3,0xD7,0x0A,0xFF,0xFF,0xFF,0xFF,0x43,0x96,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x3F,0xC0,0x00,0x00,0xBF,0x80,0x00,0x00,0x41,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_8_rodata_C__fzgx_offset_CC = 0.5f;
const f32 fzgx_pool_lbl_8_rodata_C__fzgx_offset_D0 = 4.0f;
const u8 fzgx_pool_lbl_8_rodata_C__fzgx_offset_D4[16] = {0x43,0x3E,0x00,0x00,0x3D,0x8F,0x5C,0x29,0x3F,0x0C,0xCC,0xCD,0x43,0x16,0x00,0x00};
const f32 fzgx_pool_lbl_8_rodata_C__fzgx_offset_104 = 288.0f;
const f32 fzgx_pool_lbl_8_rodata_C__fzgx_offset_108 = 10.0f;
const f32 fzgx_pool_lbl_8_rodata_C__fzgx_offset_10C = 352.0f;
const u8 fzgx_pool_lbl_8_rodata_C__fzgx_offset_110[68] = {0xA0,0x50,0x50,0x00,0xA0,0xA0,0xA0,0x00,0xFF,0xFF,0xFF,0x00,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0x43,0x8C,0x00,0x00,0x43,0x52,0x00,0x00,0x3C,0xA3,0xD7,0x0C,0x43,0x5C,0x00,0x00,0x3C,0xF5,0xC2,0x90,0x42,0x20,0x00,0x00,0x43,0xAC,0x80,0x00,0x43,0x82,0x00,0x00};
extern s32 lbl_801A66B4;
extern u32 fn_800081C8(void *, void *, f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4D4C8(void *, f32, f32);

void fn_8_2124(u32 arg0, u8 *arg1, f32 arg2) {
    const struct fn_8_2124_pool *p_lbl_8_rodata_0;
    f32 v1;
    struct { u32 a[2]; } loc_2C;
    u32 loc_28, loc_24, loc_20, loc_1C, loc_18;
    u32 loc_14, loc_10, loc_C, loc_8;
    
    loc_28 = fzgx_pool_table11[0];
    loc_2C.a[0] = fzgx_pool_table10[0];
    loc_2C.a[1] = fn_800081C8(&loc_2C, &loc_28, fzgx_pool_lbl_8_rodata_8);
    fn_1_49410();
    v1 = fzgx_pool_lbl_8_rodata_C__fzgx_offset_18;
    fn_1_4955C(v1, v1);
    fn_1_4954C(arg2);
    fn_1_495C8(9);
    if (5 != lbl_801A66B4) {
        fn_1_49590(fzgx_pool_lbl_8_rodata_C__fzgx_offset_CC);
        fn_1_495B0(0x80000000);
        fn_1_4966C(fzgx_pool_lbl_8_rodata_C, fzgx_pool_lbl_8_rodata_C__fzgx_offset_D0);
    }
    fn_1_496FC(fzgx_pool_lbl_8_rodata_C__fzgx_offset_104, (f32)(s32)arg0);
    fn_1_495C8(10);
    if (*arg1 == 0) {
        fn_1_4D494();
        loc_24 = fzgx_pool_table12[0];
        fn_1_49514(&loc_24);
        fn_1_4AE0C((const char *)lbl_8_data_7C14, lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
        loc_20 = loc_2C.a[1];
        fn_1_4D4C8(&loc_20, arg2, fzgx_pool_lbl_8_rodata_C__fzgx_offset_108);
    } else {
        loc_1C = fzgx_pool_table13[0];
        fn_1_49514(&loc_1C);
        loc_18 = fzgx_pool_table14[0];
        fn_1_49528(&loc_18);
        fn_1_4AE0C((const char *)lbl_8_data_7C14, lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
    }
    fn_1_496FC(fzgx_pool_lbl_8_rodata_C__fzgx_offset_10C, (f32)(s32)arg0);
    fn_1_495C8(8);
    if (*arg1 == 0) {
        loc_14 = fzgx_pool_table15[0];
        fn_1_49514(&loc_14);
        loc_10 = fzgx_pool_table16[0];
        fn_1_49528(&loc_10);
        fn_1_4AE0C((const char *)lbl_8_data_7C14, lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
    } else {
        fn_1_4D494();
        loc_C = fzgx_pool_table17[0];
        fn_1_49514(&loc_C);
        fn_1_4AE0C((const char *)lbl_8_data_7C14, lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
        loc_8 = loc_2C.a[1];
        fn_1_4D4C8(&loc_8, arg2, fzgx_pool_lbl_8_rodata_C__fzgx_offset_108);
    }
}
/* fzgx:end fn_8_2124 */

/* fzgx:begin fn_8_23AC */
#include "rel/title/title.h"
struct fn_8_23AC_lbl_8_rodata_0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x14];
    f32 unk_24;
    u8 pad_28[0xB0];
    f32 unk_D8;
    f32 unk_DC;
    u8 pad_E0[0x30];
    f32 unk_110;
    f32 unk_114;
    f32 unk_118;
    u32 unk_11C;
    u32 unk_120;
    u32 unk_124;
    u32 unk_128;
    u32 unk_12C;
    u32 unk_130;
    u32 unk_134;
    u32 unk_138;
};

extern struct fn_8_23AC_lbl_8_rodata_0 lbl_8_rodata_0;
extern u32 fn_1_4D4C8(void *, f32, f32);
extern u32 fn_800081C8(void *, void *, f32);
extern u32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D494(void);

void fn_8_23AC(void * arg0, f32 arg1) {
    struct fn_8_23AC_lbl_8_rodata_0 *p_lbl_8_rodata_0;
    u32 v0;
    f32 v1;
    s32 v2;
    f32 v3;
    struct { u32 a[3]; } loc_2C;
    u32 loc_28;
    u32 loc_24;
    u32 loc_20;
    u32 loc_1C;
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;
    /* frame */
    u32 t0;
    u32 t25;
    p_lbl_8_rodata_0 = (struct fn_8_23AC_lbl_8_rodata_0 *)&lbl_8_rodata_0;
    v0 = p_lbl_8_rodata_0->unk_120;
    loc_28 = v0;
    loc_2C.a[0] = p_lbl_8_rodata_0->unk_11C;
    t0 = fn_800081C8((void *)&loc_2C, (void *)&loc_28, p_lbl_8_rodata_0->unk_8);
    loc_2C.a[1] = t0;
    fn_1_49410();
    v1 = p_lbl_8_rodata_0->unk_24;
    fn_1_4955C(v1, v1);
    fn_1_4954C(arg1);
    fn_1_495C8(9);
    if ((s32)lbl_801A66B4 != 5) {
    fn_1_49590(p_lbl_8_rodata_0->unk_D8);
    fn_1_495B0(0x80000000);
    fn_1_4966C(p_lbl_8_rodata_0->unk_C, p_lbl_8_rodata_0->unk_DC);
    }
    fn_1_496FC(p_lbl_8_rodata_0->unk_110, p_lbl_8_rodata_0->unk_0);
    fn_1_495C8(10);
    if (*(u8 *)((u8 *)arg0 + 0) == 0) {
    fn_1_4D494();
    loc_24 = p_lbl_8_rodata_0->unk_124;
    fn_1_49514((u32 *)&loc_24);
    fn_1_4AE0C((const char *)(u32)&lbl_8_data_7C14, lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
    loc_20 = loc_2C.a[1];
    fn_1_4D4C8((void *)&loc_20, arg1, p_lbl_8_rodata_0->unk_114);
    } else {
    loc_1C = p_lbl_8_rodata_0->unk_128;
    fn_1_49514((u32 *)&loc_1C);
    loc_18 = p_lbl_8_rodata_0->unk_12C;
    fn_1_49528((u32 *)&loc_18);
    fn_1_4AE0C((const char *)(u32)&lbl_8_data_7C14, lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
    }
    fn_1_496FC(p_lbl_8_rodata_0->unk_118, p_lbl_8_rodata_0->unk_0);
    fn_1_495C8(8);
    if (*(u8 *)((u8 *)arg0 + 0) == 0) {
    v2 = (u32)&loc_14;
    loc_14 = p_lbl_8_rodata_0->unk_130;
    fn_1_49514((u32 *)v2);
    v2 = (u32)&loc_10;
    loc_10 = p_lbl_8_rodata_0->unk_134;
    fn_1_49528((u32 *)v2);
    v2 = (u32)&lbl_8_data_7C14;
    fn_1_4AE0C((const char *)(u32)v2, lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
    } else {
    fn_1_4D494();
    v2 = (u32)&loc_C;
    loc_C = p_lbl_8_rodata_0->unk_138;
    fn_1_49514((u32 *)v2);
    v2 = (u32)&lbl_8_data_7C14;
    fn_1_4AE0C((const char *)(u32)v2, lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
    v3 = arg1;
    v2 = (u32)&loc_8;
    loc_8 = loc_2C.a[1];
    t25 = fn_1_4D4C8((void *)v2, v3, p_lbl_8_rodata_0->unk_114);
    v2 = t25;
    }
}
/* fzgx:end fn_8_23AC */

/* fzgx:begin fn_8_25F8 */
struct fn_8_25F8_lbl_8_bss_0 {
    u8 pad_0[0x244];
    u32 unk_244;
    u8 unk_248;
    u8 pad_249[0x3];
    u32 unk_24C;
};

extern struct fn_8_25F8_lbl_8_bss_0 lbl_8_bss_0;
extern u32 fn_1_4FEC(void);
extern u32 fn_1_C3378(void);
extern u32 fn_1_F7A20(void);
extern u8 lbl_801A66B9;

void fn_8_25F8(void) {
    struct fn_8_25F8_lbl_8_bss_0 *p_lbl_8_bss_0;
    u32 v0;
    u32 t0, t1, t2;
    p_lbl_8_bss_0 = (struct fn_8_25F8_lbl_8_bss_0 *)&lbl_8_bss_0;
    if (lbl_801A66B9 == 0) {
    t0 = fn_1_4FEC();
    v0 = t0;
    t1 = fn_1_C3378();
    v0 = t1;
    t2 = fn_1_F7A20();
    v0 = t2;
    lbl_801A66B9 = 1;
    }
    p_lbl_8_bss_0->unk_244 = 0;
    p_lbl_8_bss_0->unk_248 = 255;
    p_lbl_8_bss_0->unk_24C = 0;
}
/* fzgx:end fn_8_25F8 */

/* fzgx:begin fn_8_2660 */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 362.0f;
    s = 1.0f;
    s = 0.0f;
    s = 0.4000000059604645f;
    s = 3.5f;
    s = 0.6700000166893005f;
    s = 120.0f;
    s = 2.0f;
    s = 0.75f;
    s = 3.0f;
    s = 16.0f;
    s = 464.0f;
    s = 0.009999999776482582f;
    s = 0.10000000149011612f;
    s = 360.0f;
    s = 240.0f;
    s = 200.0f;
}
static const u32 fzgx_pool_table2[17] = {0xFFFFFFFE, 0x00000000, 0xFFFFFFFE, 0x00000000, 0x00008E00, 0x06000063, 0x00008E01, 0x06000100, 0x00008E03, 0x0A0000F0, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 180.0f;
    s = 10860.0f;
    s = 1020.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 500.0f;
    s = 400.0f;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table6[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 300.0f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -1.0f;
    s = 8.0f;
    s = 0.5f;
    s = 4.0f;
    s = 190.0f;
    s = 0.07000000029802322f;
    s = 0.550000011920929f;
    s = 150.0f;
}
static const u32 fzgx_pool_table10[8] = {0xA0505000, 0xA0A0A000, 0xFFFFFF00, 0x70707000, 0x00000000, 0x70707000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 288.0f;
    s = 10.0f;
    s = 352.0f;
}
static const u32 fzgx_pool_table12[8] = {0xA0505000, 0xA0A0A000, 0xFFFFFF00, 0x70707000, 0x00000000, 0x70707000, 0x00000000, 0xFFFFFF00};
static const u32 fzgx_pool_tail13C[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; cp = fzgx_pool_tail13C; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 280.0f;
    s = 210.0f;
    s = 0.020000003278255463f;
    s = 220.0f;
    s = 0.030000001192092896f;
    s = 40.0f;
    s = 345.0f;
    s = 260.0f;
}
#pragma section code_type ".text"


/* title state machine, base lbl_8_bss_0 */
struct TitleState {
u8 pad_0[0x224];
s16 unk_224;
u8 pad_226[0xE];
u32 unk_234;
u32 unk_238;
u8 pad_23C[0x8];
s32 unk_244;
u8 unk_248;
u8 pad_249[0x3];
u32 unk_24C;
u8 unk_250;
u8 pad_251;
u8 unk_252;
u8 pad_253;
s32 unk_254;
s32 unk_258;
s32 unk_25C;
u8 unk_260;
u8 pad_261[0x3];
s32 unk_264;
u8 unk_268[0x100];
};
/* resource/format tables, base lbl_8_data_0 */
struct TitleData {
u8 pad_0[0x6E30];
void *unk_6E30[8];
u8 pad_6E50[0x6EC4 - 0x6E50];
void *unk_6EC4[8];
u8 pad_6EE4[0x6F24 - 0x6EE4];
void *unk_6F24[8];
u8 pad_6F44[0x7200 - 0x6F44];
void *unk_7200[8];
u8 pad_7220[0x7270 - 0x7220];
void *unk_7270[8];
u8 pad_7290[0x7318 - 0x7290];
void *unk_7318[8];
u8 pad_7338[0x7398 - 0x7338];
void *unk_7398[8];
u8 pad_73B8[0x7438 - 0x73B8];
void *unk_7438[8];
u8 pad_7458[0x747C - 0x7458];
void *unk_747C[8];
u8 pad_749C[0x750C - 0x749C];
void *unk_750C[8];
u8 pad_752C[0x759C - 0x752C];
void *unk_759C[8];
u8 pad_75BC[0x76A0 - 0x75BC];
void *unk_76A0[8];
u8 pad_76C0[0x77A0 - 0x76C0];
void *unk_77A0[8];
u8 pad_77C0[0x7900 - 0x77C0];
void *unk_7900[8];
u8 pad_7920[0x7980 - 0x7920];
void *unk_7980[8];
u8 pad_79A0[0x7A18 - 0x79A0];
void *unk_7A18[8];
u8 pad_7A38[0x7AB0 - 0x7A38];
void *unk_7AB0[8];
u8 pad_7AD0[0x7B28 - 0x7AD0];
void *unk_7B28[8];
u8 pad_7B48[0x7B78 - 0x7B48];
void *unk_7B78[8];
u8 pad_7B98[0x7BFC - 0x7B98];
void *unk_7BFC[7];
char str_7C18[0x10];
char str_7C28[0xC];
};
/* shared literal pool */
struct TitleRodata {
f32 unk_0;
u8 pad_4[4];
f32 unk_8;
f32 unk_C;
u8 pad_10[0x14];
f32 unk_24;
u8 pad_28[0x18];
f32 unk_40;
u8 pad_44[0x48];
f32 unk_8C;
u8 pad_90[8];
f64 unk_98;
u8 pad_A0[0x10];
u32 unk_B0;
f32 unk_B4;
f32 unk_B8;
f32 unk_BC;
u32 unk_C0;
f32 unk_C4;
u32 unk_C8;
f32 unk_CC;
f32 unk_D0;
f32 unk_D4;
f32 unk_D8;
f32 unk_DC;
f32 unk_E0;
f32 unk_E4;
f32 unk_E8;
f32 unk_EC;
u8 pad_F0[0x24];
f32 unk_114;
u8 pad_118[0x24];
u32 unk_13C;
f32 unk_140;
f32 unk_144;
f32 unk_148;
f32 unk_14C;
f32 unk_150;
f32 unk_154;
f32 unk_158;
f32 unk_15C;
};
struct TitleInput {
u8 pad_0[0x8];
u16 unk_8;
u8 pad_A[0x6];
u16 unk_10;
u16 unk_12;
};
struct TitleTrans {
u8 unk0;
u8 pad1[3];
u32 unk4;
u32 unk8;
u32 unkC;
u8 pad10[0x14];
};
struct Title8B3A0 {
u8 pad_0[0x9E];
u8 unk_9E;
};
struct Title858 {
u8 pad_0[0x15];
s8 unk_15;
};
extern struct TitleData lbl_8_data_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct TitleInput lbl_1_bss_9F8;
extern struct Title8B3A0 lbl_1_bss_8B3A0;
extern struct Title858 lbl_1_bss_58;
extern u8 lbl_1_bss_718E0;
extern u32 *lbl_1_bss_718C0;
extern u8 lbl_1_bss_7AC40;
extern s16 lbl_1_bss_96A;
extern s32 lbl_801A66B4;
extern void fn_1_54278(s32, s32);
extern void fn_1_5428C(f32);
extern void *memset(void *, int, u32);
extern s32 fn_1_B800C(s32);
extern void fn_1_B80F0(s32);
extern u8 fn_1_B7C00(void);
extern u32 fn_1_AA6D8(u32, u32, void *);
extern s32 fn_1_B7C5C(void);
extern void fn_1_5104(void);
extern u32 fn_1_B7CE4(u32, void *);
extern s32 fn_1_509C(void);
extern s32 fn_1_B7EC4(s32);
extern void fn_1_B8338(s32);
extern void fn_1_B8E84(u32, void *, void *, void *);
extern s32 fn_1_B7E98(s32);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_4AEC0(u32);
extern void fn_1_4AEB4(f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_53C9C(void *, void *, f32, f32, f32, f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_C3378(void);
extern void fn_1_F7A20(void);
extern void fn_1_C34F0(void);
extern int sprintf(char *, const char *, ...);
extern void fn_1_4FD64(void);
extern void fn_1_4D0A0(void);
extern void fn_1_4D2AC(void *, f32, f32);
extern void OSReport(const char *, ...);
extern void fn_80083DB0(u32, u32);
extern s32 fn_1_F7954(void);
extern char *strcat(char *, const char *);
extern void fn_1_B7E14(void *);
extern u32 fn_1_C3688(void);
extern s32 fn_1_B88C4(void);
extern s32 fn_1_B8EDC(u32);
extern void fn_1_3EF8C(u32);
extern void fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern void fn_1_3EB78(u32, u32, u32, u32);
extern void fn_1_3EFF0(u32, u32);
extern void fn_8006CE1C(f32);
extern void fn_1_3EF08(u32);
extern void fn_8_23AC(void *, f32);
extern u32 fn_8_F9E4(void *, void *, u32);
extern void fn_8_FF9C(void);
extern s32 fn_8_FC5C(void);
extern void fn_8_10084(u32);
extern void fn_8_100B4(void);
extern void *fn_8_5840(void *);
extern void fn_8_2124(u32, void *, f32);
extern void fn_8_784(u32);
static inline void *fn_8_2660_array_read(void **array, s32 *index) { return array[*index]; }
#pragma opt_propagation on
#pragma opt_lifetimes on
extern u8 fn_8_1304__fzgx_offset_0[];
extern u8 fn_8_1344__fzgx_offset_0[];
extern u8 fn_8_1394__fzgx_offset_0[];
extern u8 fn_8_1C08__fzgx_offset_0[];
extern u8 fn_8_1C0C__fzgx_offset_0[];
extern u8 fn_8_1C10__fzgx_offset_0[];
extern u8 fn_8_1C14__fzgx_offset_0[];
extern u8 fn_8_1C18__fzgx_offset_0[];
extern u8 fn_8_1C90__fzgx_offset_0[];
extern u8 fn_8_1F64__fzgx_offset_0[];
extern u8 fn_8_1F74__fzgx_offset_0[];
extern u8 fn_8_1FB0__fzgx_offset_0[];
extern u8 fn_8_2120__fzgx_offset_0[];
extern u8 fn_8_25F8__fzgx_offset_0[];
extern u8 fn_8_2660__fzgx_offset_0[];
extern u8 fn_8_4E8C__fzgx_offset_0[];
extern u8 fn_8_4E90__fzgx_offset_0[];
extern u8 fn_8_4F64__fzgx_offset_0[];
extern u8 fn_8_516C__fzgx_offset_0[];
extern u8 fn_8_520C__fzgx_offset_0[];
extern u8 fn_8_5210__fzgx_offset_0[];
extern u8 fn_8_5214__fzgx_offset_0[];
extern u8 fn_8_5218__fzgx_offset_0[];
extern u8 fn_8_530C__fzgx_offset_0[];
extern u8 fn_8_5514__fzgx_offset_0[];
extern u8 fn_8_55CC__fzgx_offset_0[];
extern u8 fn_8_5608__fzgx_offset_0[];
extern u8 fn_8_5810__fzgx_offset_0[];
extern u8 fn_8_5B44__fzgx_offset_0[];
extern u8 fn_8_5C4C__fzgx_offset_0[];
extern u8 fn_8_5C50__fzgx_offset_0[];
extern u8 fn_8_BD8__fzgx_offset_0[];
extern u8 fn_8_BDC__fzgx_offset_0[];
extern u8 fn_8_BE0__fzgx_offset_0[];
extern u8 fn_8_BE4__fzgx_offset_0[];
extern u8 fn_8_BE4__fzgx_offset_100[];
extern u8 fn_8_BE4__fzgx_offset_10C[];
extern u8 fn_8_BE4__fzgx_offset_118[];
extern u8 fn_8_BE4__fzgx_offset_124[];
extern u8 fn_8_BE4__fzgx_offset_130[];
extern u8 fn_8_BE4__fzgx_offset_13C[];
extern u8 fn_8_BE4__fzgx_offset_148[];
extern u8 fn_8_BE4__fzgx_offset_154[];
extern u8 fn_8_BE4__fzgx_offset_160[];
extern u8 fn_8_BE4__fzgx_offset_16C[];
extern u8 fn_8_BE4__fzgx_offset_178[];
extern u8 fn_8_BE4__fzgx_offset_184[];
extern u8 fn_8_BE4__fzgx_offset_DC[];
extern u8 fn_8_BE4__fzgx_offset_E8[];
extern u8 fn_8_BE4__fzgx_offset_F4[];
extern u8 fn_8_EC4__fzgx_offset_0[];
extern u8 lbl_8_data_0__fzgx_offset_0[];
extern u8 lbl_8_data_1010__fzgx_offset_0[];
extern u8 lbl_8_data_1030__fzgx_offset_0[];
extern u8 lbl_8_data_1050__fzgx_offset_0[];
extern u8 lbl_8_data_108__fzgx_offset_0[];
extern u8 lbl_8_data_1094__fzgx_offset_0[];
extern u8 lbl_8_data_10D8__fzgx_offset_0[];
extern u8 lbl_8_data_10F8__fzgx_offset_0[];
extern u8 lbl_8_data_10__fzgx_offset_0[];
extern u8 lbl_8_data_1118__fzgx_offset_0[];
extern u8 lbl_8_data_1138__fzgx_offset_0[];
extern u8 lbl_8_data_1158__fzgx_offset_0[];
extern u8 lbl_8_data_118__fzgx_offset_0[];
extern u8 lbl_8_data_119C__fzgx_offset_0[];
extern u8 lbl_8_data_11CC__fzgx_offset_0[];
extern u8 lbl_8_data_11EC__fzgx_offset_0[];
extern u8 lbl_8_data_120C__fzgx_offset_0[];
extern u8 lbl_8_data_120__fzgx_offset_0[];
extern u8 lbl_8_data_122C__fzgx_offset_0[];
extern u8 lbl_8_data_124C__fzgx_offset_0[];
extern u8 lbl_8_data_127C__fzgx_offset_0[];
extern u8 lbl_8_data_12C0__fzgx_offset_0[];
extern u8 lbl_8_data_12C__fzgx_offset_0[];
extern u8 lbl_8_data_12E0__fzgx_offset_0[];
extern u8 lbl_8_data_1300__fzgx_offset_0[];
extern u8 lbl_8_data_1320__fzgx_offset_0[];
extern u8 lbl_8_data_1340__fzgx_offset_0[];
extern u8 lbl_8_data_134__fzgx_offset_0[];
extern u8 lbl_8_data_1384__fzgx_offset_0[];
extern u8 lbl_8_data_13C8__fzgx_offset_0[];
extern u8 lbl_8_data_13E8__fzgx_offset_0[];
extern u8 lbl_8_data_1408__fzgx_offset_0[];
extern u8 lbl_8_data_140__fzgx_offset_0[];
extern u8 lbl_8_data_1428__fzgx_offset_0[];
extern u8 lbl_8_data_1448__fzgx_offset_0[];
extern u8 lbl_8_data_148C__fzgx_offset_0[];
extern u8 lbl_8_data_14AC__fzgx_offset_0[];
extern u8 lbl_8_data_14BC__fzgx_offset_0[];
extern u8 lbl_8_data_14CC__fzgx_offset_0[];
extern u8 lbl_8_data_14DC__fzgx_offset_0[];
extern u8 lbl_8_data_14EC__fzgx_offset_0[];
extern u8 lbl_8_data_1508__fzgx_offset_0[];
extern u8 lbl_8_data_150__fzgx_offset_0[];
extern u8 lbl_8_data_151C__fzgx_offset_0[];
extern u8 lbl_8_data_152C__fzgx_offset_0[];
extern u8 lbl_8_data_153C__fzgx_offset_0[];
extern u8 lbl_8_data_154C__fzgx_offset_0[];
extern u8 lbl_8_data_155C__fzgx_offset_0[];
extern u8 lbl_8_data_156C__fzgx_offset_0[];
extern u8 lbl_8_data_15A0__fzgx_offset_0[];
extern u8 lbl_8_data_15B8__fzgx_offset_0[];
extern u8 lbl_8_data_15C__fzgx_offset_0[];
extern u8 lbl_8_data_15D0__fzgx_offset_0[];
extern u8 lbl_8_data_15E8__fzgx_offset_0[];
extern u8 lbl_8_data_1600__fzgx_offset_0[];
extern u8 lbl_8_data_1634__fzgx_offset_0[];
extern u8 lbl_8_data_1668__fzgx_offset_0[];
extern u8 lbl_8_data_1680__fzgx_offset_0[];
extern u8 lbl_8_data_168__fzgx_offset_0[];
extern u8 lbl_8_data_1698__fzgx_offset_0[];
extern u8 lbl_8_data_16B0__fzgx_offset_0[];
extern u8 lbl_8_data_16C8__fzgx_offset_0[];
extern u8 lbl_8_data_16FC__fzgx_offset_0[];
extern u8 lbl_8_data_170__fzgx_offset_0[];
extern u8 lbl_8_data_171C__fzgx_offset_0[];
extern u8 lbl_8_data_1734__fzgx_offset_0[];
extern u8 lbl_8_data_174C__fzgx_offset_0[];
extern u8 lbl_8_data_1764__fzgx_offset_0[];
extern u8 lbl_8_data_177C__fzgx_offset_0[];
extern u8 lbl_8_data_17A0__fzgx_offset_0[];
extern u8 lbl_8_data_17D4__fzgx_offset_0[];
extern u8 lbl_8_data_17F0__fzgx_offset_0[];
extern u8 lbl_8_data_180C__fzgx_offset_0[];
extern u8 lbl_8_data_1828__fzgx_offset_0[];
extern u8 lbl_8_data_1844__fzgx_offset_0[];
extern u8 lbl_8_data_184__fzgx_offset_0[];
extern u8 lbl_8_data_1874__fzgx_offset_0[];
extern u8 lbl_8_data_18AC__fzgx_offset_0[];
extern u8 lbl_8_data_18C8__fzgx_offset_0[];
extern u8 lbl_8_data_18E4__fzgx_offset_0[];
extern u8 lbl_8_data_1900__fzgx_offset_0[];
extern u8 lbl_8_data_191C__fzgx_offset_0[];
extern u8 lbl_8_data_194__fzgx_offset_0[];
extern u8 lbl_8_data_1954__fzgx_offset_0[];
extern u8 lbl_8_data_1994__fzgx_offset_0[];
extern u8 lbl_8_data_19B4__fzgx_offset_0[];
extern u8 lbl_8_data_19D4__fzgx_offset_0[];
extern u8 lbl_8_data_19F4__fzgx_offset_0[];
extern u8 lbl_8_data_1A14__fzgx_offset_0[];
extern u8 lbl_8_data_1A4__fzgx_offset_0[];
extern u8 lbl_8_data_1A54__fzgx_offset_0[];
extern u8 lbl_8_data_1A90__fzgx_offset_0[];
extern u8 lbl_8_data_1AB0__fzgx_offset_0[];
extern u8 lbl_8_data_1AD0__fzgx_offset_0[];
extern u8 lbl_8_data_1AF0__fzgx_offset_0[];
extern u8 lbl_8_data_1B0__fzgx_offset_0[];
extern u8 lbl_8_data_1B10__fzgx_offset_0[];
extern u8 lbl_8_data_1B50__fzgx_offset_0[];
extern u8 lbl_8_data_1B8C__fzgx_offset_0[];
extern u8 lbl_8_data_1BAC__fzgx_offset_0[];
extern u8 lbl_8_data_1BCC__fzgx_offset_0[];
extern u8 lbl_8_data_1BC__fzgx_offset_0[];
extern u8 lbl_8_data_1BEC__fzgx_offset_0[];
extern u8 lbl_8_data_1C0C__fzgx_offset_0[];
extern u8 lbl_8_data_1C50__fzgx_offset_0[];
extern u8 lbl_8_data_1C90__fzgx_offset_0[];
extern u8 lbl_8_data_1CB0__fzgx_offset_0[];
extern u8 lbl_8_data_1CC__fzgx_offset_0[];
extern u8 lbl_8_data_1CD0__fzgx_offset_0[];
extern u8 lbl_8_data_1CF0__fzgx_offset_0[];
extern u8 lbl_8_data_1C__fzgx_offset_0[];
extern u8 lbl_8_data_1D10__fzgx_offset_0[];
extern u8 lbl_8_data_1D4C__fzgx_offset_0[];
extern u8 lbl_8_data_1D4__fzgx_offset_0[];
extern u8 lbl_8_data_1D8C__fzgx_offset_0[];
extern u8 lbl_8_data_1DAC__fzgx_offset_0[];
extern u8 lbl_8_data_1DCC__fzgx_offset_0[];
extern u8 lbl_8_data_1DEC__fzgx_offset_0[];
extern u8 lbl_8_data_1E0C__fzgx_offset_0[];
extern u8 lbl_8_data_1E0__fzgx_offset_0[];
extern u8 lbl_8_data_1E4C__fzgx_offset_0[];
extern u8 lbl_8_data_1E78__fzgx_offset_0[];
extern u8 lbl_8_data_1E8__fzgx_offset_0[];
extern u8 lbl_8_data_1E90__fzgx_offset_0[];
extern u8 lbl_8_data_1EA8__fzgx_offset_0[];
extern u8 lbl_8_data_1EC0__fzgx_offset_0[];
extern u8 lbl_8_data_1ED8__fzgx_offset_0[];
extern u8 lbl_8_data_1F04__fzgx_offset_0[];
extern u8 lbl_8_data_1F0__fzgx_offset_0[];
extern u8 lbl_8_data_1F60__fzgx_offset_0[];
extern u8 lbl_8_data_1F78__fzgx_offset_0[];
extern u8 lbl_8_data_1F8__fzgx_offset_0[];
extern u8 lbl_8_data_1F90__fzgx_offset_0[];
extern u8 lbl_8_data_1FA8__fzgx_offset_0[];
extern u8 lbl_8_data_1FC0__fzgx_offset_0[];
extern u8 lbl_8_data_202C__fzgx_offset_0[];
extern u8 lbl_8_data_205C__fzgx_offset_0[];
extern u8 lbl_8_data_206C__fzgx_offset_0[];
extern u8 lbl_8_data_207C__fzgx_offset_0[];
extern u8 lbl_8_data_208C__fzgx_offset_0[];
extern u8 lbl_8_data_209C__fzgx_offset_0[];
extern u8 lbl_8_data_20D4__fzgx_offset_0[];
extern u8 lbl_8_data_2128__fzgx_offset_0[];
extern u8 lbl_8_data_213C__fzgx_offset_0[];
extern u8 lbl_8_data_2150__fzgx_offset_0[];
extern u8 lbl_8_data_2164__fzgx_offset_0[];
extern u8 lbl_8_data_2178__fzgx_offset_0[];
extern u8 lbl_8_data_21C0__fzgx_offset_0[];
extern u8 lbl_8_data_2204__fzgx_offset_0[];
extern u8 lbl_8_data_2214__fzgx_offset_0[];
extern u8 lbl_8_data_2224__fzgx_offset_0[];
extern u8 lbl_8_data_2234__fzgx_offset_0[];
extern u8 lbl_8_data_2244__fzgx_offset_0[];
extern u8 lbl_8_data_2288__fzgx_offset_0[];
extern u8 lbl_8_data_22C0__fzgx_offset_0[];
extern u8 lbl_8_data_22D4__fzgx_offset_0[];
extern u8 lbl_8_data_22E8__fzgx_offset_0[];
extern u8 lbl_8_data_22FC__fzgx_offset_0[];
extern u8 lbl_8_data_2310__fzgx_offset_0[];
extern u8 lbl_8_data_2354__fzgx_offset_0[];
extern u8 lbl_8_data_238C__fzgx_offset_0[];
extern u8 lbl_8_data_239C__fzgx_offset_0[];
extern u8 lbl_8_data_23AC__fzgx_offset_0[];
extern u8 lbl_8_data_23BC__fzgx_offset_0[];
extern u8 lbl_8_data_23CC__fzgx_offset_0[];
extern u8 lbl_8_data_2410__fzgx_offset_0[];
extern u8 lbl_8_data_2470__fzgx_offset_0[];
extern u8 lbl_8_data_2480__fzgx_offset_0[];
extern u8 lbl_8_data_2490__fzgx_offset_0[];
extern u8 lbl_8_data_24A0__fzgx_offset_0[];
extern u8 lbl_8_data_24B0__fzgx_offset_0[];
extern u8 lbl_8_data_2508__fzgx_offset_0[];
extern u8 lbl_8_data_2544__fzgx_offset_0[];
extern u8 lbl_8_data_2554__fzgx_offset_0[];
extern u8 lbl_8_data_2564__fzgx_offset_0[];
extern u8 lbl_8_data_2574__fzgx_offset_0[];
extern u8 lbl_8_data_2584__fzgx_offset_0[];
extern u8 lbl_8_data_25DC__fzgx_offset_0[];
extern u8 lbl_8_data_263C__fzgx_offset_0[];
extern u8 lbl_8_data_2650__fzgx_offset_0[];
extern u8 lbl_8_data_2664__fzgx_offset_0[];
extern u8 lbl_8_data_2678__fzgx_offset_0[];
extern u8 lbl_8_data_268C__fzgx_offset_0[];
extern u8 lbl_8_data_26F8__fzgx_offset_0[];
extern u8 lbl_8_data_2720__fzgx_offset_0[];
extern u8 lbl_8_data_2734__fzgx_offset_0[];
extern u8 lbl_8_data_2748__fzgx_offset_0[];
extern u8 lbl_8_data_275C__fzgx_offset_0[];
extern u8 lbl_8_data_2770__fzgx_offset_0[];
extern u8 lbl_8_data_27AC__fzgx_offset_0[];
extern u8 lbl_8_data_27B4__fzgx_offset_0[];
extern u8 lbl_8_data_27C0__fzgx_offset_0[];
extern u8 lbl_8_data_27CC__fzgx_offset_0[];
extern u8 lbl_8_data_27D8__fzgx_offset_0[];
extern u8 lbl_8_data_27E4__fzgx_offset_0[];
extern u8 lbl_8_data_27F0__fzgx_offset_0[];
extern u8 lbl_8_data_27F8__fzgx_offset_0[];
extern u8 lbl_8_data_2804__fzgx_offset_0[];
extern u8 lbl_8_data_2810__fzgx_offset_0[];
extern u8 lbl_8_data_281C__fzgx_offset_0[];
extern u8 lbl_8_data_2828__fzgx_offset_0[];
extern u8 lbl_8_data_2834__fzgx_offset_0[];
extern u8 lbl_8_data_2838__fzgx_offset_0[];
extern u8 lbl_8_data_2840__fzgx_offset_0[];
extern u8 lbl_8_data_2848__fzgx_offset_0[];
extern u8 lbl_8_data_2850__fzgx_offset_0[];
extern u8 lbl_8_data_2858__fzgx_offset_0[];
extern u8 lbl_8_data_2860__fzgx_offset_0[];
extern u8 lbl_8_data_2864__fzgx_offset_0[];
extern u8 lbl_8_data_286C__fzgx_offset_0[];
extern u8 lbl_8_data_2874__fzgx_offset_0[];
extern u8 lbl_8_data_287C__fzgx_offset_0[];
extern u8 lbl_8_data_2884__fzgx_offset_0[];
extern u8 lbl_8_data_288C__fzgx_offset_0[];
extern u8 lbl_8_data_28C8__fzgx_offset_0[];
extern u8 lbl_8_data_28DC__fzgx_offset_0[];
extern u8 lbl_8_data_28F0__fzgx_offset_0[];
extern u8 lbl_8_data_28__fzgx_offset_0[];
extern u8 lbl_8_data_2904__fzgx_offset_0[];
extern u8 lbl_8_data_2918__fzgx_offset_0[];
extern u8 lbl_8_data_2958__fzgx_offset_0[];
extern u8 lbl_8_data_2AE8__fzgx_offset_0[];
extern u8 lbl_8_data_2AF4__fzgx_offset_0[];
extern u8 lbl_8_data_2B00__fzgx_offset_0[];
extern u8 lbl_8_data_2B0C__fzgx_offset_0[];
extern u8 lbl_8_data_2B18__fzgx_offset_0[];
extern u8 lbl_8_data_2B4__fzgx_offset_0[];
extern u8 lbl_8_data_2BC__fzgx_offset_0[];
extern u8 lbl_8_data_2C4__fzgx_offset_0[];
extern u8 lbl_8_data_2CC__fzgx_offset_0[];
extern u8 lbl_8_data_2D4__fzgx_offset_0[];
extern u8 lbl_8_data_2D68__fzgx_offset_0[];
extern u8 lbl_8_data_2DC__fzgx_offset_0[];
extern u8 lbl_8_data_2E4C__fzgx_offset_0[];
extern u8 lbl_8_data_2E4__fzgx_offset_0[];
extern u8 lbl_8_data_2E58__fzgx_offset_0[];
extern u8 lbl_8_data_2E64__fzgx_offset_0[];
extern u8 lbl_8_data_2E70__fzgx_offset_0[];
extern u8 lbl_8_data_2E7C__fzgx_offset_0[];
extern u8 lbl_8_data_2EC__fzgx_offset_0[];
extern u8 lbl_8_data_2F8__fzgx_offset_0[];
extern u8 lbl_8_data_2FD8__fzgx_offset_0[];
extern u8 lbl_8_data_300__fzgx_offset_0[];
extern u8 lbl_8_data_308__fzgx_offset_0[];
extern u8 lbl_8_data_310__fzgx_offset_0[];
extern u8 lbl_8_data_3168__fzgx_offset_0[];
extern u8 lbl_8_data_3178__fzgx_offset_0[];
extern u8 lbl_8_data_3188__fzgx_offset_0[];
extern u8 lbl_8_data_3198__fzgx_offset_0[];
extern u8 lbl_8_data_31A8__fzgx_offset_0[];
extern u8 lbl_8_data_33F8__fzgx_offset_0[];
extern u8 lbl_8_data_34DC__fzgx_offset_0[];
extern u8 lbl_8_data_34F0__fzgx_offset_0[];
extern u8 lbl_8_data_34__fzgx_offset_0[];
extern u8 lbl_8_data_3504__fzgx_offset_0[];
extern u8 lbl_8_data_3518__fzgx_offset_0[];
extern u8 lbl_8_data_352C__fzgx_offset_0[];
extern u8 lbl_8_data_3688__fzgx_offset_0[];
extern u8 lbl_8_data_36DC__fzgx_offset_0[];
extern u8 lbl_8_data_36F0__fzgx_offset_0[];
extern u8 lbl_8_data_3704__fzgx_offset_0[];
extern u8 lbl_8_data_3718__fzgx_offset_0[];
extern u8 lbl_8_data_372C__fzgx_offset_0[];
extern u8 lbl_8_data_378C__fzgx_offset_0[];
extern u8 lbl_8_data_37B4__fzgx_offset_0[];
extern u8 lbl_8_data_37CC__fzgx_offset_0[];
extern u8 lbl_8_data_37E4__fzgx_offset_0[];
extern u8 lbl_8_data_37FC__fzgx_offset_0[];
extern u8 lbl_8_data_3814__fzgx_offset_0[];
extern u8 lbl_8_data_3850__fzgx_offset_0[];
extern u8 lbl_8_data_3884__fzgx_offset_0[];
extern u8 lbl_8_data_3894__fzgx_offset_0[];
extern u8 lbl_8_data_38A4__fzgx_offset_0[];
extern u8 lbl_8_data_38B4__fzgx_offset_0[];
extern u8 lbl_8_data_38C4__fzgx_offset_0[];
extern u8 lbl_8_data_3904__fzgx_offset_0[];
extern u8 lbl_8_data_391C__fzgx_offset_0[];
extern u8 lbl_8_data_3930__fzgx_offset_0[];
extern u8 lbl_8_data_3944__fzgx_offset_0[];
extern u8 lbl_8_data_3958__fzgx_offset_0[];
extern u8 lbl_8_data_396C__fzgx_offset_0[];
extern u8 lbl_8_data_3988__fzgx_offset_0[];
extern u8 lbl_8_data_3990__fzgx_offset_0[];
extern u8 lbl_8_data_399C__fzgx_offset_0[];
extern u8 lbl_8_data_39A8__fzgx_offset_0[];
extern u8 lbl_8_data_39B4__fzgx_offset_0[];
extern u8 lbl_8_data_39C0__fzgx_offset_0[];
extern u8 lbl_8_data_39CC__fzgx_offset_0[];
extern u8 lbl_8_data_3A04__fzgx_offset_0[];
extern u8 lbl_8_data_3A14__fzgx_offset_0[];
extern u8 lbl_8_data_3A24__fzgx_offset_0[];
extern u8 lbl_8_data_3A34__fzgx_offset_0[];
extern u8 lbl_8_data_3A44__fzgx_offset_0[];
extern u8 lbl_8_data_3A88__fzgx_offset_0[];
extern u8 lbl_8_data_3AB4__fzgx_offset_0[];
extern u8 lbl_8_data_3AC4__fzgx_offset_0[];
extern u8 lbl_8_data_3AD4__fzgx_offset_0[];
extern u8 lbl_8_data_3AE4__fzgx_offset_0[];
extern u8 lbl_8_data_3AF4__fzgx_offset_0[];
extern u8 lbl_8_data_3B2C__fzgx_offset_0[];
extern u8 lbl_8_data_3B6C__fzgx_offset_0[];
extern u8 lbl_8_data_3B7C__fzgx_offset_0[];
extern u8 lbl_8_data_3B8C__fzgx_offset_0[];
extern u8 lbl_8_data_3B9C__fzgx_offset_0[];
extern u8 lbl_8_data_3BAC__fzgx_offset_0[];
extern u8 lbl_8_data_3BF0__fzgx_offset_0[];
extern u8 lbl_8_data_3C48__fzgx_offset_0[];
extern u8 lbl_8_data_3C58__fzgx_offset_0[];
extern u8 lbl_8_data_3C68__fzgx_offset_0[];
extern u8 lbl_8_data_3C78__fzgx_offset_0[];
extern u8 lbl_8_data_3C88__fzgx_offset_0[];
extern u8 lbl_8_data_3CCC__fzgx_offset_0[];
extern u8 lbl_8_data_3C__fzgx_offset_0[];
extern u8 lbl_8_data_3D14__fzgx_offset_0[];
extern u8 lbl_8_data_3D20__fzgx_offset_0[];
extern u8 lbl_8_data_3D2C__fzgx_offset_0[];
extern u8 lbl_8_data_3D38__fzgx_offset_0[];
extern u8 lbl_8_data_3D44__fzgx_offset_0[];
extern u8 lbl_8_data_3D98__fzgx_offset_0[];
extern u8 lbl_8_data_3DCC__fzgx_offset_0[];
extern u8 lbl_8_data_3DD8__fzgx_offset_0[];
extern u8 lbl_8_data_3DE4__fzgx_offset_0[];
extern u8 lbl_8_data_3DF0__fzgx_offset_0[];
extern u8 lbl_8_data_3DFC__fzgx_offset_0[];
extern u8 lbl_8_data_3E30__fzgx_offset_0[];
extern u8 lbl_8_data_3E68__fzgx_offset_0[];
extern u8 lbl_8_data_3E74__fzgx_offset_0[];
extern u8 lbl_8_data_3E80__fzgx_offset_0[];
extern u8 lbl_8_data_3E8C__fzgx_offset_0[];
extern u8 lbl_8_data_3E98__fzgx_offset_0[];
extern u8 lbl_8_data_3ECC__fzgx_offset_0[];
extern u8 lbl_8_data_3F00__fzgx_offset_0[];
extern u8 lbl_8_data_3F0C__fzgx_offset_0[];
extern u8 lbl_8_data_3F18__fzgx_offset_0[];
extern u8 lbl_8_data_3F24__fzgx_offset_0[];
extern u8 lbl_8_data_3F30__fzgx_offset_0[];
extern u8 lbl_8_data_3F64__fzgx_offset_0[];
extern u8 lbl_8_data_3F9C__fzgx_offset_0[];
extern u8 lbl_8_data_3FA8__fzgx_offset_0[];
extern u8 lbl_8_data_3FB4__fzgx_offset_0[];
extern u8 lbl_8_data_3FC0__fzgx_offset_0[];
extern u8 lbl_8_data_3FCC__fzgx_offset_0[];
extern u8 lbl_8_data_4000__fzgx_offset_0[];
extern u8 lbl_8_data_403C__fzgx_offset_0[];
extern u8 lbl_8_data_404C__fzgx_offset_0[];
extern u8 lbl_8_data_405C__fzgx_offset_0[];
extern u8 lbl_8_data_406C__fzgx_offset_0[];
extern u8 lbl_8_data_407C__fzgx_offset_0[];
extern u8 lbl_8_data_40A4__fzgx_offset_0[];
extern u8 lbl_8_data_40D4__fzgx_offset_0[];
extern u8 lbl_8_data_40E8__fzgx_offset_0[];
extern u8 lbl_8_data_40FC__fzgx_offset_0[];
extern u8 lbl_8_data_4110__fzgx_offset_0[];
extern u8 lbl_8_data_4124__fzgx_offset_0[];
extern u8 lbl_8_data_4160__fzgx_offset_0[];
extern u8 lbl_8_data_419C__fzgx_offset_0[];
extern u8 lbl_8_data_41AC__fzgx_offset_0[];
extern u8 lbl_8_data_41BC__fzgx_offset_0[];
extern u8 lbl_8_data_41CC__fzgx_offset_0[];
extern u8 lbl_8_data_41DC__fzgx_offset_0[];
extern u8 lbl_8_data_4218__fzgx_offset_0[];
extern u8 lbl_8_data_4240__fzgx_offset_0[];
extern u8 lbl_8_data_4250__fzgx_offset_0[];
extern u8 lbl_8_data_4260__fzgx_offset_0[];
extern u8 lbl_8_data_4270__fzgx_offset_0[];
extern u8 lbl_8_data_4280__fzgx_offset_0[];
extern u8 lbl_8_data_42C4__fzgx_offset_0[];
extern u8 lbl_8_data_4304__fzgx_offset_0[];
extern u8 lbl_8_data_4314__fzgx_offset_0[];
extern u8 lbl_8_data_4324__fzgx_offset_0[];
extern u8 lbl_8_data_4334__fzgx_offset_0[];
extern u8 lbl_8_data_4344__fzgx_offset_0[];
extern u8 lbl_8_data_4384__fzgx_offset_0[];
extern u8 lbl_8_data_43BC__fzgx_offset_0[];
extern u8 lbl_8_data_43CC__fzgx_offset_0[];
extern u8 lbl_8_data_43DC__fzgx_offset_0[];
extern u8 lbl_8_data_43EC__fzgx_offset_0[];
extern u8 lbl_8_data_43FC__fzgx_offset_0[];
extern u8 lbl_8_data_4424__fzgx_offset_0[];
extern u8 lbl_8_data_4434__fzgx_offset_0[];
extern u8 lbl_8_data_4444__fzgx_offset_0[];
extern u8 lbl_8_data_4454__fzgx_offset_0[];
extern u8 lbl_8_data_4464__fzgx_offset_0[];
extern u8 lbl_8_data_4474__fzgx_offset_0[];
extern u8 lbl_8_data_4484__fzgx_offset_0[];
extern u8 lbl_8_data_4490__fzgx_offset_0[];
extern u8 lbl_8_data_44A0__fzgx_offset_0[];
extern u8 lbl_8_data_44B0__fzgx_offset_0[];
extern u8 lbl_8_data_44C0__fzgx_offset_0[];
extern u8 lbl_8_data_44D0__fzgx_offset_0[];
extern u8 lbl_8_data_44DC__fzgx_offset_0[];
extern u8 lbl_8_data_44EC__fzgx_offset_0[];
extern u8 lbl_8_data_44FC__fzgx_offset_0[];
extern u8 lbl_8_data_44__fzgx_offset_0[];
extern u8 lbl_8_data_450C__fzgx_offset_0[];
extern u8 lbl_8_data_451C__fzgx_offset_0[];
extern u8 lbl_8_data_452C__fzgx_offset_0[];
extern u8 lbl_8_data_453C__fzgx_offset_0[];
extern u8 lbl_8_data_454C__fzgx_offset_0[];
extern u8 lbl_8_data_455C__fzgx_offset_0[];
extern u8 lbl_8_data_456C__fzgx_offset_0[];
extern u8 lbl_8_data_457C__fzgx_offset_0[];
extern u8 lbl_8_data_458C__fzgx_offset_0[];
extern u8 lbl_8_data_459C__fzgx_offset_0[];
extern u8 lbl_8_data_45F0__fzgx_offset_0[];
extern u8 lbl_8_data_45FC__fzgx_offset_0[];
extern u8 lbl_8_data_4608__fzgx_offset_0[];
extern u8 lbl_8_data_4614__fzgx_offset_0[];
extern u8 lbl_8_data_4620__fzgx_offset_0[];
extern u8 lbl_8_data_4688__fzgx_offset_0[];
extern u8 lbl_8_data_46DC__fzgx_offset_0[];
extern u8 lbl_8_data_46E8__fzgx_offset_0[];
extern u8 lbl_8_data_46F4__fzgx_offset_0[];
extern u8 lbl_8_data_4700__fzgx_offset_0[];
extern u8 lbl_8_data_470C__fzgx_offset_0[];
extern u8 lbl_8_data_4774__fzgx_offset_0[];
extern u8 lbl_8_data_47A0__fzgx_offset_0[];
extern u8 lbl_8_data_47B0__fzgx_offset_0[];
extern u8 lbl_8_data_47C0__fzgx_offset_0[];
extern u8 lbl_8_data_47D0__fzgx_offset_0[];
extern u8 lbl_8_data_47E0__fzgx_offset_0[];
extern u8 lbl_8_data_480C__fzgx_offset_0[];
extern u8 lbl_8_data_483C__fzgx_offset_0[];
extern u8 lbl_8_data_484C__fzgx_offset_0[];
extern u8 lbl_8_data_485C__fzgx_offset_0[];
extern u8 lbl_8_data_486C__fzgx_offset_0[];
extern u8 lbl_8_data_487C__fzgx_offset_0[];
extern u8 lbl_8_data_48B0__fzgx_offset_0[];
extern u8 lbl_8_data_4948__fzgx_offset_0[];
extern u8 lbl_8_data_4960__fzgx_offset_0[];
extern u8 lbl_8_data_4978__fzgx_offset_0[];
extern u8 lbl_8_data_4990__fzgx_offset_0[];
extern u8 lbl_8_data_49A8__fzgx_offset_0[];
extern u8 lbl_8_data_4A34__fzgx_offset_0[];
extern u8 lbl_8_data_4A78__fzgx_offset_0[];
extern u8 lbl_8_data_4A90__fzgx_offset_0[];
extern u8 lbl_8_data_4AA8__fzgx_offset_0[];
extern u8 lbl_8_data_4AC0__fzgx_offset_0[];
extern u8 lbl_8_data_4AD8__fzgx_offset_0[];
extern u8 lbl_8_data_4B28__fzgx_offset_0[];
extern u8 lbl_8_data_4B9C__fzgx_offset_0[];
extern u8 lbl_8_data_4BA0__fzgx_offset_0[];
extern u8 lbl_8_data_4BA4__fzgx_offset_0[];
extern u8 lbl_8_data_4BA8__fzgx_offset_0[];
extern u8 lbl_8_data_4BAC__fzgx_offset_0[];
extern u8 lbl_8_data_4C68__fzgx_offset_0[];
extern u8 lbl_8_data_4CE0__fzgx_offset_0[];
extern u8 lbl_8_data_4CE4__fzgx_offset_0[];
extern u8 lbl_8_data_4CE8__fzgx_offset_0[];
extern u8 lbl_8_data_4CEC__fzgx_offset_0[];
extern u8 lbl_8_data_4CF0__fzgx_offset_0[];
extern u8 lbl_8_data_4C__fzgx_offset_0[];
extern u8 lbl_8_data_4D0__fzgx_offset_0[];
extern u8 lbl_8_data_4D4C__fzgx_offset_0[];
extern u8 lbl_8_data_4D54__fzgx_offset_0[];
extern u8 lbl_8_data_4D60__fzgx_offset_0[];
extern u8 lbl_8_data_4D6C__fzgx_offset_0[];
extern u8 lbl_8_data_4D78__fzgx_offset_0[];
extern u8 lbl_8_data_4D84__fzgx_offset_0[];
extern u8 lbl_8_data_4D8C__fzgx_offset_0[];
extern u8 lbl_8_data_4D94__fzgx_offset_0[];
extern u8 lbl_8_data_4DA0__fzgx_offset_0[];
extern u8 lbl_8_data_4DAC__fzgx_offset_0[];
extern u8 lbl_8_data_4DB8__fzgx_offset_0[];
extern u8 lbl_8_data_4DC4__fzgx_offset_0[];
extern u8 lbl_8_data_4DCC__fzgx_offset_0[];
extern u8 lbl_8_data_4DC__fzgx_offset_0[];
extern u8 lbl_8_data_4DD4__fzgx_offset_0[];
extern u8 lbl_8_data_4DE0__fzgx_offset_0[];
extern u8 lbl_8_data_4DEC__fzgx_offset_0[];
extern u8 lbl_8_data_4DF8__fzgx_offset_0[];
extern u8 lbl_8_data_4E04__fzgx_offset_0[];
extern u8 lbl_8_data_4E10__fzgx_offset_0[];
extern u8 lbl_8_data_4E18__fzgx_offset_0[];
extern u8 lbl_8_data_4E24__fzgx_offset_0[];
extern u8 lbl_8_data_4E30__fzgx_offset_0[];
extern u8 lbl_8_data_4E3C__fzgx_offset_0[];
extern u8 lbl_8_data_4E48__fzgx_offset_0[];
extern u8 lbl_8_data_4E54__fzgx_offset_0[];
extern u8 lbl_8_data_4E5C__fzgx_offset_0[];
extern u8 lbl_8_data_4E68__fzgx_offset_0[];
extern u8 lbl_8_data_4E74__fzgx_offset_0[];
extern u8 lbl_8_data_4E80__fzgx_offset_0[];
extern u8 lbl_8_data_4E8C__fzgx_offset_0[];
extern u8 lbl_8_data_4E98__fzgx_offset_0[];
extern u8 lbl_8_data_4EA0__fzgx_offset_0[];
extern u8 lbl_8_data_4EAC__fzgx_offset_0[];
extern u8 lbl_8_data_4EB8__fzgx_offset_0[];
extern u8 lbl_8_data_4EC4__fzgx_offset_0[];
extern u8 lbl_8_data_4ED0__fzgx_offset_0[];
extern u8 lbl_8_data_4EDC__fzgx_offset_0[];
extern u8 lbl_8_data_4EE4__fzgx_offset_0[];
extern u8 lbl_8_data_4EF0__fzgx_offset_0[];
extern u8 lbl_8_data_4EFC__fzgx_offset_0[];
extern u8 lbl_8_data_4F08__fzgx_offset_0[];
extern u8 lbl_8_data_4F14__fzgx_offset_0[];
extern u8 lbl_8_data_4F20__fzgx_offset_0[];
extern u8 lbl_8_data_4F28__fzgx_offset_0[];
extern u8 lbl_8_data_4F34__fzgx_offset_0[];
extern u8 lbl_8_data_4F40__fzgx_offset_0[];
extern u8 lbl_8_data_4F4C__fzgx_offset_0[];
extern u8 lbl_8_data_4F58__fzgx_offset_0[];
extern u8 lbl_8_data_4F60__fzgx_offset_0[];
extern u8 lbl_8_data_4FC__fzgx_offset_0[];
extern u8 lbl_8_data_4__fzgx_offset_0[];
extern u8 lbl_8_data_508__fzgx_offset_0[];
extern u8 lbl_8_data_50A4__fzgx_offset_0[];
extern u8 lbl_8_data_50A8__fzgx_offset_0[];
extern u8 lbl_8_data_50AC__fzgx_offset_0[];
extern u8 lbl_8_data_50B0__fzgx_offset_0[];
extern u8 lbl_8_data_50B4__fzgx_offset_0[];
extern u8 lbl_8_data_5224__fzgx_offset_0[];
extern u8 lbl_8_data_524__fzgx_offset_0[];
extern u8 lbl_8_data_5268__fzgx_offset_0[];
extern u8 lbl_8_data_526C__fzgx_offset_0[];
extern u8 lbl_8_data_5270__fzgx_offset_0[];
extern u8 lbl_8_data_5274__fzgx_offset_0[];
extern u8 lbl_8_data_5278__fzgx_offset_0[];
extern u8 lbl_8_data_52BC__fzgx_offset_0[];
extern u8 lbl_8_data_5300__fzgx_offset_0[];
extern u8 lbl_8_data_5304__fzgx_offset_0[];
extern u8 lbl_8_data_5308__fzgx_offset_0[];
extern u8 lbl_8_data_530C__fzgx_offset_0[];
extern u8 lbl_8_data_530__fzgx_offset_0[];
extern u8 lbl_8_data_5310__fzgx_offset_0[];
extern u8 lbl_8_data_5358__fzgx_offset_0[];
extern u8 lbl_8_data_5390__fzgx_offset_0[];
extern u8 lbl_8_data_5394__fzgx_offset_0[];
extern u8 lbl_8_data_5398__fzgx_offset_0[];
extern u8 lbl_8_data_539C__fzgx_offset_0[];
extern u8 lbl_8_data_53A0__fzgx_offset_0[];
extern u8 lbl_8_data_53F8__fzgx_offset_0[];
extern u8 lbl_8_data_5400__fzgx_offset_0[];
extern u8 lbl_8_data_5404__fzgx_offset_0[];
extern u8 lbl_8_data_5408__fzgx_offset_0[];
extern u8 lbl_8_data_540C__fzgx_offset_0[];
extern u8 lbl_8_data_5410__fzgx_offset_0[];
extern u8 lbl_8_data_5418__fzgx_offset_0[];
extern u8 lbl_8_data_5420__fzgx_offset_0[];
extern u8 lbl_8_data_5424__fzgx_offset_0[];
extern u8 lbl_8_data_5428__fzgx_offset_0[];
extern u8 lbl_8_data_542C__fzgx_offset_0[];
extern u8 lbl_8_data_5430__fzgx_offset_0[];
extern u8 lbl_8_data_5438__fzgx_offset_0[];
extern u8 lbl_8_data_5440__fzgx_offset_0[];
extern u8 lbl_8_data_5444__fzgx_offset_0[];
extern u8 lbl_8_data_5448__fzgx_offset_0[];
extern u8 lbl_8_data_544C__fzgx_offset_0[];
extern u8 lbl_8_data_5450__fzgx_offset_0[];
extern u8 lbl_8_data_5458__fzgx_offset_0[];
extern u8 lbl_8_data_5460__fzgx_offset_0[];
extern u8 lbl_8_data_5464__fzgx_offset_0[];
extern u8 lbl_8_data_5468__fzgx_offset_0[];
extern u8 lbl_8_data_546C__fzgx_offset_0[];
extern u8 lbl_8_data_5470__fzgx_offset_0[];
extern u8 lbl_8_data_5478__fzgx_offset_0[];
extern u8 lbl_8_data_548__fzgx_offset_0[];
extern u8 lbl_8_data_54AC__fzgx_offset_0[];
extern u8 lbl_8_data_54B0__fzgx_offset_0[];
extern u8 lbl_8_data_54B4__fzgx_offset_0[];
extern u8 lbl_8_data_54B8__fzgx_offset_0[];
extern u8 lbl_8_data_54BC__fzgx_offset_0[];
extern u8 lbl_8_data_54__fzgx_offset_0[];
extern u8 lbl_8_data_5510__fzgx_offset_0[];
extern u8 lbl_8_data_5564__fzgx_offset_0[];
extern u8 lbl_8_data_5568__fzgx_offset_0[];
extern u8 lbl_8_data_556C__fzgx_offset_0[];
extern u8 lbl_8_data_5570__fzgx_offset_0[];
extern u8 lbl_8_data_5574__fzgx_offset_0[];
extern u8 lbl_8_data_558__fzgx_offset_0[];
extern u8 lbl_8_data_55C0__fzgx_offset_0[];
extern u8 lbl_8_data_55C8__fzgx_offset_0[];
extern u8 lbl_8_data_55CC__fzgx_offset_0[];
extern u8 lbl_8_data_55D0__fzgx_offset_0[];
extern u8 lbl_8_data_55D4__fzgx_offset_0[];
extern u8 lbl_8_data_55D8__fzgx_offset_0[];
extern u8 lbl_8_data_55E4__fzgx_offset_0[];
extern u8 lbl_8_data_5624__fzgx_offset_0[];
extern u8 lbl_8_data_5638__fzgx_offset_0[];
extern u8 lbl_8_data_564C__fzgx_offset_0[];
extern u8 lbl_8_data_5660__fzgx_offset_0[];
extern u8 lbl_8_data_5674__fzgx_offset_0[];
extern u8 lbl_8_data_56C__fzgx_offset_0[];
extern u8 lbl_8_data_5750__fzgx_offset_0[];
extern u8 lbl_8_data_57CC__fzgx_offset_0[];
extern u8 lbl_8_data_57C__fzgx_offset_0[];
extern u8 lbl_8_data_57DC__fzgx_offset_0[];
extern u8 lbl_8_data_57EC__fzgx_offset_0[];
extern u8 lbl_8_data_57FC__fzgx_offset_0[];
extern u8 lbl_8_data_580C__fzgx_offset_0[];
extern u8 lbl_8_data_58EC__fzgx_offset_0[];
extern u8 lbl_8_data_595C__fzgx_offset_0[];
extern u8 lbl_8_data_5970__fzgx_offset_0[];
extern u8 lbl_8_data_5984__fzgx_offset_0[];
extern u8 lbl_8_data_598__fzgx_offset_0[];
extern u8 lbl_8_data_5998__fzgx_offset_0[];
extern u8 lbl_8_data_59AC__fzgx_offset_0[];
extern u8 lbl_8_data_59B0__fzgx_offset_0[];
extern u8 lbl_8_data_5A58__fzgx_offset_0[];
extern u8 lbl_8_data_5A68__fzgx_offset_0[];
extern u8 lbl_8_data_5A78__fzgx_offset_0[];
extern u8 lbl_8_data_5A88__fzgx_offset_0[];
extern u8 lbl_8_data_5A98__fzgx_offset_0[];
extern u8 lbl_8_data_5A9C__fzgx_offset_0[];
extern u8 lbl_8_data_5AC__fzgx_offset_0[];
extern u8 lbl_8_data_5B44__fzgx_offset_0[];
extern u8 lbl_8_data_5B54__fzgx_offset_0[];
extern u8 lbl_8_data_5B64__fzgx_offset_0[];
extern u8 lbl_8_data_5B74__fzgx_offset_0[];
extern u8 lbl_8_data_5B84__fzgx_offset_0[];
extern u8 lbl_8_data_5C0__fzgx_offset_0[];
extern u8 lbl_8_data_5C3C__fzgx_offset_0[];
extern u8 lbl_8_data_5C64__fzgx_offset_0[];
extern u8 lbl_8_data_5C74__fzgx_offset_0[];
extern u8 lbl_8_data_5C84__fzgx_offset_0[];
extern u8 lbl_8_data_5C94__fzgx_offset_0[];
extern u8 lbl_8_data_5CA4__fzgx_offset_0[];
extern u8 lbl_8_data_5CD4__fzgx_offset_0[];
extern u8 lbl_8_data_5D1C__fzgx_offset_0[];
extern u8 lbl_8_data_5D2C__fzgx_offset_0[];
extern u8 lbl_8_data_5D3C__fzgx_offset_0[];
extern u8 lbl_8_data_5D4C__fzgx_offset_0[];
extern u8 lbl_8_data_5D4__fzgx_offset_0[];
extern u8 lbl_8_data_5D5C__fzgx_offset_0[];
extern u8 lbl_8_data_5DC4__fzgx_offset_0[];
extern u8 lbl_8_data_5DFC__fzgx_offset_0[];
extern u8 lbl_8_data_5E0C__fzgx_offset_0[];
extern u8 lbl_8_data_5E1C__fzgx_offset_0[];
extern u8 lbl_8_data_5E2C__fzgx_offset_0[];
extern u8 lbl_8_data_5E3C__fzgx_offset_0[];
extern u8 lbl_8_data_5E84__fzgx_offset_0[];
extern u8 lbl_8_data_5EB0__fzgx_offset_0[];
extern u8 lbl_8_data_5EC4__fzgx_offset_0[];
extern u8 lbl_8_data_5ED8__fzgx_offset_0[];
extern u8 lbl_8_data_5EEC__fzgx_offset_0[];
extern u8 lbl_8_data_5F00__fzgx_offset_0[];
extern u8 lbl_8_data_5F30__fzgx_offset_0[];
extern u8 lbl_8_data_5F44__fzgx_offset_0[];
extern u8 lbl_8_data_5F4__fzgx_offset_0[];
extern u8 lbl_8_data_5F54__fzgx_offset_0[];
extern u8 lbl_8_data_5F64__fzgx_offset_0[];
extern u8 lbl_8_data_5F74__fzgx_offset_0[];
extern u8 lbl_8_data_5F84__fzgx_offset_0[];
extern u8 lbl_8_data_5F90__fzgx_offset_0[];
extern u8 lbl_8_data_5FA4__fzgx_offset_0[];
extern u8 lbl_8_data_5FB8__fzgx_offset_0[];
extern u8 lbl_8_data_5FCC__fzgx_offset_0[];
extern u8 lbl_8_data_5FE0__fzgx_offset_0[];
extern u8 lbl_8_data_5FF4__fzgx_offset_0[];
extern u8 lbl_8_data_600__fzgx_offset_0[];
extern u8 lbl_8_data_6014__fzgx_offset_0[];
extern u8 lbl_8_data_6030__fzgx_offset_0[];
extern u8 lbl_8_data_6044__fzgx_offset_0[];
extern u8 lbl_8_data_6058__fzgx_offset_0[];
extern u8 lbl_8_data_606C__fzgx_offset_0[];
extern u8 lbl_8_data_6080__fzgx_offset_0[];
extern u8 lbl_8_data_60A4__fzgx_offset_0[];
extern u8 lbl_8_data_60C4__fzgx_offset_0[];
extern u8 lbl_8_data_60D4__fzgx_offset_0[];
extern u8 lbl_8_data_60E4__fzgx_offset_0[];
extern u8 lbl_8_data_60F4__fzgx_offset_0[];
extern u8 lbl_8_data_60__fzgx_offset_0[];
extern u8 lbl_8_data_6104__fzgx_offset_0[];
extern u8 lbl_8_data_6118__fzgx_offset_0[];
extern u8 lbl_8_data_614C__fzgx_offset_0[];
extern u8 lbl_8_data_6160__fzgx_offset_0[];
extern u8 lbl_8_data_6174__fzgx_offset_0[];
extern u8 lbl_8_data_6188__fzgx_offset_0[];
extern u8 lbl_8_data_618__fzgx_offset_0[];
extern u8 lbl_8_data_619C__fzgx_offset_0[];
extern u8 lbl_8_data_61C0__fzgx_offset_0[];
extern u8 lbl_8_data_61D0__fzgx_offset_0[];
extern u8 lbl_8_data_61E0__fzgx_offset_0[];
extern u8 lbl_8_data_61F0__fzgx_offset_0[];
extern u8 lbl_8_data_6200__fzgx_offset_0[];
extern u8 lbl_8_data_6210__fzgx_offset_0[];
extern u8 lbl_8_data_6220__fzgx_offset_0[];
extern u8 lbl_8_data_624C__fzgx_offset_0[];
extern u8 lbl_8_data_624__fzgx_offset_0[];
extern u8 lbl_8_data_6260__fzgx_offset_0[];
extern u8 lbl_8_data_6274__fzgx_offset_0[];
extern u8 lbl_8_data_6288__fzgx_offset_0[];
extern u8 lbl_8_data_629C__fzgx_offset_0[];
extern u8 lbl_8_data_63C__fzgx_offset_0[];
extern u8 lbl_8_data_650__fzgx_offset_0[];
extern u8 lbl_8_data_66C__fzgx_offset_0[];
extern u8 lbl_8_data_67C__fzgx_offset_0[];
extern u8 lbl_8_data_688__fzgx_offset_0[];
extern u8 lbl_8_data_69C__fzgx_offset_0[];
extern u8 lbl_8_data_6B4__fzgx_offset_0[];
extern u8 lbl_8_data_6C4__fzgx_offset_0[];
extern u8 lbl_8_data_6D68__fzgx_offset_0[];
extern u8 lbl_8_data_6DB8__fzgx_offset_0[];
extern u8 lbl_8_data_6DBC__fzgx_offset_0[];
extern u8 lbl_8_data_6E48__fzgx_offset_0[];
extern u8 lbl_8_data_6E88__fzgx_offset_0[];
extern u8 lbl_8_data_6EDC__fzgx_offset_0[];
extern u8 lbl_8_data_6EFC__fzgx_offset_0[];
extern u8 lbl_8_data_6F3C__fzgx_offset_0[];
extern u8 lbl_8_data_70__fzgx_offset_0[];
extern u8 lbl_8_data_7120__fzgx_offset_0[];
extern u8 lbl_8_data_7218__fzgx_offset_0[];
extern u8 lbl_8_data_7254__fzgx_offset_0[];
extern u8 lbl_8_data_7288__fzgx_offset_0[];
extern u8 lbl_8_data_72C4__fzgx_offset_0[];
extern u8 lbl_8_data_7330__fzgx_offset_0[];
extern u8 lbl_8_data_735C__fzgx_offset_0[];
extern u8 lbl_8_data_73B0__fzgx_offset_0[];
extern u8 lbl_8_data_73F4__fzgx_offset_0[];
extern u8 lbl_8_data_7450__fzgx_offset_0[];
extern u8 lbl_8_data_7494__fzgx_offset_0[];
extern u8 lbl_8_data_74CC__fzgx_offset_0[];
extern u8 lbl_8_data_7524__fzgx_offset_0[];
extern u8 lbl_8_data_755C__fzgx_offset_0[];
extern u8 lbl_8_data_75B4__fzgx_offset_0[];
extern u8 lbl_8_data_761C__fzgx_offset_0[];
extern u8 lbl_8_data_76B8__fzgx_offset_0[];
extern u8 lbl_8_data_771C__fzgx_offset_0[];
extern u8 lbl_8_data_778__fzgx_offset_0[];
extern u8 lbl_8_data_77B8__fzgx_offset_0[];
extern u8 lbl_8_data_784C__fzgx_offset_0[];
extern u8 lbl_8_data_7918__fzgx_offset_0[];
extern u8 lbl_8_data_7944__fzgx_offset_0[];
extern u8 lbl_8_data_7998__fzgx_offset_0[];
extern u8 lbl_8_data_79E0__fzgx_offset_0[];
extern u8 lbl_8_data_7A30__fzgx_offset_0[];
extern u8 lbl_8_data_7A74__fzgx_offset_0[];
extern u8 lbl_8_data_7AC8__fzgx_offset_0[];
extern u8 lbl_8_data_7AF0__fzgx_offset_0[];
extern u8 lbl_8_data_7B40__fzgx_offset_0[];
extern u8 lbl_8_data_7B60__fzgx_offset_0[];
extern u8 lbl_8_data_7B90__fzgx_offset_0[];
extern u8 lbl_8_data_7BC4__fzgx_offset_0[];
extern u8 lbl_8_data_7C8__fzgx_offset_0[];
extern u8 lbl_8_data_7D4__fzgx_offset_0[];
extern u8 lbl_8_data_7E0__fzgx_offset_0[];
extern u8 lbl_8_data_7EC__fzgx_offset_0[];
extern u8 lbl_8_data_7F8__fzgx_offset_0[];
extern u8 lbl_8_data_80__fzgx_offset_0[];
extern u8 lbl_8_data_864__fzgx_offset_0[];
extern u8 lbl_8_data_88__fzgx_offset_0[];
extern u8 lbl_8_data_8A8__fzgx_offset_0[];
extern u8 lbl_8_data_8B8__fzgx_offset_0[];
extern u8 lbl_8_data_8C8__fzgx_offset_0[];
extern u8 lbl_8_data_8D8__fzgx_offset_0[];
extern u8 lbl_8_data_8E8__fzgx_offset_0[];
extern u8 lbl_8_data_90__fzgx_offset_0[];
extern u8 lbl_8_data_948__fzgx_offset_0[];
extern u8 lbl_8_data_9B8__fzgx_offset_0[];
extern u8 lbl_8_data_9C4__fzgx_offset_0[];
extern u8 lbl_8_data_9C__fzgx_offset_0[];
extern u8 lbl_8_data_9D0__fzgx_offset_0[];
extern u8 lbl_8_data_9DC__fzgx_offset_0[];
extern u8 lbl_8_data_9E8__fzgx_offset_0[];
extern u8 lbl_8_data_A8__fzgx_offset_0[];
extern u8 lbl_8_data_AD0__fzgx_offset_0[];
extern u8 lbl_8_data_B28__fzgx_offset_0[];
extern u8 lbl_8_data_B34__fzgx_offset_0[];
extern u8 lbl_8_data_B40__fzgx_offset_0[];
extern u8 lbl_8_data_B4C__fzgx_offset_0[];
extern u8 lbl_8_data_B58__fzgx_offset_0[];
extern u8 lbl_8_data_B8__fzgx_offset_0[];
extern u8 lbl_8_data_BC0__fzgx_offset_0[];
extern u8 lbl_8_data_BF4__fzgx_offset_0[];
extern u8 lbl_8_data_C0C__fzgx_offset_0[];
extern u8 lbl_8_data_C0__fzgx_offset_0[];
extern u8 lbl_8_data_C24__fzgx_offset_0[];
extern u8 lbl_8_data_C3C__fzgx_offset_0[];
extern u8 lbl_8_data_C54__fzgx_offset_0[];
extern u8 lbl_8_data_C7C__fzgx_offset_0[];
extern u8 lbl_8_data_CAC__fzgx_offset_0[];
extern u8 lbl_8_data_CC4__fzgx_offset_0[];
extern u8 lbl_8_data_CC__fzgx_offset_0[];
extern u8 lbl_8_data_CDC__fzgx_offset_0[];
extern u8 lbl_8_data_CF4__fzgx_offset_0[];
extern u8 lbl_8_data_D0C__fzgx_offset_0[];
extern u8 lbl_8_data_D34__fzgx_offset_0[];
extern u8 lbl_8_data_D64__fzgx_offset_0[];
extern u8 lbl_8_data_D7C__fzgx_offset_0[];
extern u8 lbl_8_data_D8__fzgx_offset_0[];
extern u8 lbl_8_data_D94__fzgx_offset_0[];
extern u8 lbl_8_data_DAC__fzgx_offset_0[];
extern u8 lbl_8_data_DC4__fzgx_offset_0[];
extern u8 lbl_8_data_DF4__fzgx_offset_0[];
extern u8 lbl_8_data_E24__fzgx_offset_0[];
extern u8 lbl_8_data_E40__fzgx_offset_0[];
extern u8 lbl_8_data_E5C__fzgx_offset_0[];
extern u8 lbl_8_data_E78__fzgx_offset_0[];
extern u8 lbl_8_data_E8__fzgx_offset_0[];
extern u8 lbl_8_data_E94__fzgx_offset_0[];
extern u8 lbl_8_data_EBC__fzgx_offset_0[];
extern u8 lbl_8_data_EF0__fzgx_offset_0[];
extern u8 lbl_8_data_F0C__fzgx_offset_0[];
extern u8 lbl_8_data_F0__fzgx_offset_0[];
extern u8 lbl_8_data_F28__fzgx_offset_0[];
extern u8 lbl_8_data_F44__fzgx_offset_0[];
extern u8 lbl_8_data_F60__fzgx_offset_0[];
extern u8 lbl_8_data_F8C__fzgx_offset_0[];
extern u8 lbl_8_data_FC__fzgx_offset_0[];
extern u8 lbl_8_data_FD0__fzgx_offset_0[];
extern u8 lbl_8_data_FF0__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_8_data_0_gap_0[7052] = {0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_8_data_0__fzgx_offset_0, (u32)lbl_8_data_4__fzgx_offset_0, (u32)lbl_8_data_10__fzgx_offset_0, (u32)lbl_8_data_1C__fzgx_offset_0, (u32)lbl_8_data_28__fzgx_offset_0, (u32)lbl_8_data_34__fzgx_offset_0, (u32)lbl_8_data_3C__fzgx_offset_0, (u32)lbl_8_data_44__fzgx_offset_0, (u32)lbl_8_data_4C__fzgx_offset_0, (u32)lbl_8_data_54__fzgx_offset_0, (u32)lbl_8_data_60__fzgx_offset_0, (u32)lbl_8_data_70__fzgx_offset_0, (u32)lbl_8_data_80__fzgx_offset_0, (u32)lbl_8_data_88__fzgx_offset_0, (u32)lbl_8_data_90__fzgx_offset_0, (u32)lbl_8_data_9C__fzgx_offset_0, (u32)lbl_8_data_A8__fzgx_offset_0, (u32)lbl_8_data_B8__fzgx_offset_0, (u32)lbl_8_data_C0__fzgx_offset_0, (u32)lbl_8_data_CC__fzgx_offset_0, (u32)lbl_8_data_D8__fzgx_offset_0, (u32)lbl_8_data_E8__fzgx_offset_0, (u32)lbl_8_data_F0__fzgx_offset_0, (u32)lbl_8_data_FC__fzgx_offset_0, (u32)lbl_8_data_108__fzgx_offset_0, (u32)lbl_8_data_118__fzgx_offset_0, (u32)lbl_8_data_120__fzgx_offset_0, (u32)lbl_8_data_12C__fzgx_offset_0, (u32)lbl_8_data_134__fzgx_offset_0, (u32)lbl_8_data_140__fzgx_offset_0, (u32)lbl_8_data_150__fzgx_offset_0, (u32)lbl_8_data_15C__fzgx_offset_0, (u32)lbl_8_data_168__fzgx_offset_0, (u32)lbl_8_data_170__fzgx_offset_0, (u32)lbl_8_data_184__fzgx_offset_0, (u32)lbl_8_data_194__fzgx_offset_0, (u32)lbl_8_data_1A4__fzgx_offset_0, (u32)lbl_8_data_1B0__fzgx_offset_0, (u32)lbl_8_data_1BC__fzgx_offset_0, (u32)lbl_8_data_1CC__fzgx_offset_0, (u32)lbl_8_data_1D4__fzgx_offset_0, (u32)lbl_8_data_1E0__fzgx_offset_0, (u32)lbl_8_data_1E8__fzgx_offset_0, (u32)lbl_8_data_1F0__fzgx_offset_0, (u32)lbl_8_data_1F8__fzgx_offset_0, 0x70726F67, 0x00000000, 0x6D656D63, 0x61726400, 0x7469746C, 0x65000000, 0x64656D6F, 0x00000000, 0x6D656E75, 0x00000000, 0x6C6F676F, 0x00000000, 0x7761726E, 0x696E6700, 0x6F706572, 0x6174696F, 0x6E000000, 0x72617469, 0x6E670000, 0x63617264, 0x00000000, 0x72616E6B, 0x696E6700, 0x6D6F7669, 0x65000000, (u32)lbl_8_data_2B4__fzgx_offset_0, (u32)fn_8_1F74__fzgx_offset_0, (u32)fn_8_1FB0__fzgx_offset_0, (u32)fn_8_2120__fzgx_offset_0, (u32)lbl_8_data_2BC__fzgx_offset_0, (u32)fn_8_25F8__fzgx_offset_0, (u32)fn_8_2660__fzgx_offset_0, (u32)fn_8_4E8C__fzgx_offset_0, (u32)lbl_8_data_2C4__fzgx_offset_0, (u32)fn_8_1C18__fzgx_offset_0, (u32)fn_8_1C90__fzgx_offset_0, (u32)fn_8_1F64__fzgx_offset_0, (u32)lbl_8_data_2CC__fzgx_offset_0, (u32)fn_8_1344__fzgx_offset_0, (u32)fn_8_1394__fzgx_offset_0, (u32)fn_8_1C08__fzgx_offset_0, (u32)lbl_8_data_2D4__fzgx_offset_0, (u32)fn_8_1C0C__fzgx_offset_0, (u32)fn_8_1C10__fzgx_offset_0, (u32)fn_8_1C14__fzgx_offset_0, (u32)lbl_8_data_2DC__fzgx_offset_0, (u32)fn_8_BE4__fzgx_offset_0, (u32)fn_8_EC4__fzgx_offset_0, (u32)fn_8_1304__fzgx_offset_0, (u32)lbl_8_data_2E4__fzgx_offset_0, (u32)fn_8_BD8__fzgx_offset_0, (u32)fn_8_BDC__fzgx_offset_0, (u32)fn_8_BE0__fzgx_offset_0, (u32)lbl_8_data_2EC__fzgx_offset_0, (u32)fn_8_4E90__fzgx_offset_0, (u32)fn_8_4F64__fzgx_offset_0, (u32)fn_8_516C__fzgx_offset_0, (u32)lbl_8_data_2F8__fzgx_offset_0, (u32)fn_8_520C__fzgx_offset_0, (u32)fn_8_5210__fzgx_offset_0, (u32)fn_8_5214__fzgx_offset_0, (u32)lbl_8_data_300__fzgx_offset_0, (u32)fn_8_5218__fzgx_offset_0, (u32)fn_8_530C__fzgx_offset_0, (u32)fn_8_5514__fzgx_offset_0, (u32)lbl_8_data_308__fzgx_offset_0, (u32)fn_8_55CC__fzgx_offset_0, (u32)fn_8_5608__fzgx_offset_0, (u32)fn_8_5810__fzgx_offset_0, (u32)lbl_8_data_310__fzgx_offset_0, (u32)fn_8_5B44__fzgx_offset_0, (u32)fn_8_5C4C__fzgx_offset_0, (u32)fn_8_5C50__fzgx_offset_0, 0x2B200000, 0x012C0006, 0x4E494E54, 0x454E444F, 0x00000000, 0x414D5553, 0x454D454E, 0x54205649, 0x53494F4E, 0x00000000, 0x462D5A45, 0x524F2066, 0x6F722047, 0x43000000, 0x57454C43, 0x4F4D4520, 0x544F0000, 0x4F564552, 0x20323030, 0x306B6D2F, 0x6820574F, 0x524C4421, 0x00000000, 0x7469746C, 0x652E6300, 0x76656869, 0x636C652F, 0x25735F65, 0x2E617263, 0x2E6C7A00, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x302E7478, 0x74000000, 0x6D6F7669, 0x652F7374, 0x6F727930, 0x31412E74, 0x78740000, 0x76656869, 0x636C652F, 0x76656869, 0x636C655F, 0x73656C2E, 0x6172632E, 0x6C7A0000, (u32)fn_8_BE4__fzgx_offset_DC, (u32)fn_8_BE4__fzgx_offset_E8, (u32)fn_8_BE4__fzgx_offset_F4, (u32)fn_8_BE4__fzgx_offset_100, (u32)fn_8_BE4__fzgx_offset_10C, (u32)fn_8_BE4__fzgx_offset_118, (u32)fn_8_BE4__fzgx_offset_124, (u32)fn_8_BE4__fzgx_offset_130, (u32)fn_8_BE4__fzgx_offset_13C, (u32)fn_8_BE4__fzgx_offset_148, (u32)fn_8_BE4__fzgx_offset_154, (u32)fn_8_BE4__fzgx_offset_160, (u32)fn_8_BE4__fzgx_offset_16C, (u32)fn_8_BE4__fzgx_offset_178, (u32)fn_8_BE4__fzgx_offset_184, 0x835A838C, 0x834E835E, 0x00000000, 0x83668374, 0x8348838B, 0x8367835A, 0x838C834E, 0x835E82C9, 0x93FC82E8, 0x82DC82B7, 0x00000000, 0x835A838C, 0x834E835E, 0x32000000, 0x835A834A, 0x83938368, 0x835A838C, 0x834E835E, 0x82C993FC, 0x82E882DC, 0x82B70000, 0x4143835A, 0x838C834E, 0x835E0000, 0x4143835A, 0x838C834E, 0x835E82C9, 0x93FC82E8, 0x82DC82B7, 0x00000000, 0x8380815B, 0x8372815B, 0x83658358, 0x83670000, 0x8380815B, 0x8372815B, 0x82F082DD, 0x82DC82B7, 0x00000000, 0x834A8358, 0x835E837D, 0x83438359, 0x00000000, 0x834A8358, 0x835E837D, 0x83438359, 0x82F082A8, 0x82B182C8, 0x82A282DC, 0x82B70000, 0x82AD82E9, 0x82DC82A2, 0x82EB4368, 0x616E6765, 0x00000000, 0x8ED482CC, 0x904682F0, 0x95CF82A6, 0x82DC82B7, 0x00000000, 0x83588367, 0x815B838A, 0x815B8382, 0x815B8368, 0x00000000, 0x83588367, 0x815B838A, 0x815B8382, 0x815B8368, 0x82F082CD, 0x82B682DF, 0x82DC82B7, 0x00000000, 0x838A8376, 0x838C8343, 0x00000000, 0x838A8376, 0x838C8343, 0x8AD38FDC, 0x8382815B, 0x836882C5, 0x82B70000, 0x83498376, 0x83568387, 0x83930000, 0x8351815B, 0x838082CC, 0x90DD92E8, 0x82F095CF, 0x82A682DC, 0x82B70000, 0x83708343, 0x838D8362, 0x83678382, 0x815B8368, 0x00000000, 0x83708343, 0x838D8362, 0x83678382, 0x815B8368, 0x82C993FC, 0x82E882DC, 0x82B70000, 0x955C8FB2, 0x91E48382, 0x815B8368, 0x00000000, 0x955C8FB2, 0x91E482C5, 0x82B70000, 0x83438393, 0x835E8372, 0x8385815B, 0x8382815B, 0x83680000, 0x83438393, 0x835E8372, 0x8385815B, 0x8382815B, 0x836882C5, 0x82B70000, 0x83658358, 0x83678382, 0x815B8368, 0x00000000, 0x83658358, 0x83678382, 0x815B8368, 0x82C993FC, 0x82E882DC, 0x82B70000, (u32)lbl_8_data_4D0__fzgx_offset_0, (u32)lbl_8_data_4DC__fzgx_offset_0, 0x00000001, (u32)lbl_8_data_4FC__fzgx_offset_0, (u32)lbl_8_data_508__fzgx_offset_0, 0xFFFFFFFE, (u32)lbl_8_data_524__fzgx_offset_0, (u32)lbl_8_data_530__fzgx_offset_0, 0xFFFFFFFC, (u32)lbl_8_data_548__fzgx_offset_0, (u32)lbl_8_data_558__fzgx_offset_0, 0x00000008, (u32)lbl_8_data_56C__fzgx_offset_0, (u32)lbl_8_data_57C__fzgx_offset_0, 0x00000005, (u32)lbl_8_data_598__fzgx_offset_0, (u32)lbl_8_data_5AC__fzgx_offset_0, 0x00000006, (u32)lbl_8_data_5C0__fzgx_offset_0, (u32)lbl_8_data_5D4__fzgx_offset_0, 0x00000009, (u32)lbl_8_data_5F4__fzgx_offset_0, (u32)lbl_8_data_600__fzgx_offset_0, 0x0000000C, (u32)lbl_8_data_618__fzgx_offset_0, (u32)lbl_8_data_624__fzgx_offset_0, 0x00000003, (u32)lbl_8_data_63C__fzgx_offset_0, (u32)lbl_8_data_650__fzgx_offset_0, 0x0000000D, (u32)lbl_8_data_66C__fzgx_offset_0, (u32)lbl_8_data_67C__fzgx_offset_0, 0x0000000E, (u32)lbl_8_data_688__fzgx_offset_0, (u32)lbl_8_data_69C__fzgx_offset_0, 0x00000010, (u32)lbl_8_data_6B4__fzgx_offset_0, (u32)lbl_8_data_6C4__fzgx_offset_0, 0x00000004, 0x41204D65, 0x6D6F7279, 0x20436172, 0x64206973, 0x206E6F74, 0x20696E73, 0x65727465, 0x6420696E, 0x20534C4F, 0x542E0A50, 0x6C656173, 0x65207072, 0x6F706572, 0x6C792069, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x6172642E, 0x00000000, 0x4E4F4341, 0x52442047, 0x45520000, 0x4E4F4341, 0x52442046, 0x52410000, 0x4E4F4341, 0x52442053, 0x50410000, 0x4E4F4341, 0x52442049, 0x54410000, 0x534C4F54, 0x82C98381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82AA8CA9, 0x5B82DD5D, 0x82C282A9, 0x82E882DC, 0x82B982F1, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CC90, 0xDA5B82B9, 0x82C25D91, 0xB15B82BC, 0x82AD5D82, 0xF08A6D5B, 0x82A982AD, 0x5D94465B, 0x82C982F1, 0x5D82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x64657669, 0x63652069, 0x6E20534C, 0x4F542069, 0x73206E6F, 0x74207375, 0x70706F72, 0x7465642E, 0x0A506C65, 0x61736520, 0x696E7365, 0x72742061, 0x204D656D, 0x6F727920, 0x43617264, 0x2E000000, 0x57524F4E, 0x47444556, 0x49434520, 0x47455200, 0x57524F4E, 0x47444556, 0x49434520, 0x46524100, 0x57524F4E, 0x47444556, 0x49434520, 0x53504100, 0x57524F4E, 0x47444556, 0x49434520, 0x49544100, 0x534C4F54, 0x82C982CD, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836888, 0xC85B82A2, 0x5D8A4F5B, 0x82AA82A2, 0x5D82CC82, 0xE082CC82, 0xAA82B382, 0xB382C182, 0xC482A282, 0xDC82B781, 0x420A8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82F082B3, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x41206661, 0x74616C20, 0x6572726F, 0x72206861, 0x73206F63, 0x63757265, 0x642E0A54, 0x75726E20, 0x74686520, 0x706F7765, 0x72206F66, 0x6620616E, 0x64207265, 0x66657220, 0x746F2074, 0x6865204E, 0x696E7465, 0x6E646F20, 0x47616D65, 0x43756265, 0x0A686172, 0x64776172, 0x65206D61, 0x6E75616C, 0x20666F72, 0x20646574, 0x61696C73, 0x2E200000, 0x46415441, 0x4C204745, 0x52000000, 0x46415441, 0x4C204652, 0x41000000, 0x46415441, 0x4C205350, 0x41000000, 0x46415441, 0x4C204954, 0x41000000, 0x92765B82, 0xBF5D96BD, 0x5B82DF82, 0xA25D9349, 0x5B82C482, 0xAB5D82C8, 0x83478389, 0x815B82AA, 0x8B4E5B82, 0xA85D82B1, 0x82E882DC, 0x82B582BD, 0x81420A0A, 0x967B5B82, 0xD982F15D, 0x91CC5B82, 0xBD82A25D, 0x82CC8370, 0x838F815B, 0x837B835E, 0x839382F0, 0x899F5B82, 0xA85D82B5, 0x82C40A93, 0x645B82C5, 0x82F15D8C, 0xB95B82B0, 0x82F15D82, 0xF0826E82, 0x65826582, 0xC982B581, 0x410A967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D82CC, 0x8EE65B82, 0xC65D82E8, 0x88B55B82, 0xA082C282, 0xA95D82A2, 0x90E05B82, 0xB982C25D, 0x96BE5B82, 0xDF82A25D, 0x8F915B82, 0xB582E55D, 0x82CC0A8E, 0x775B82B5, 0x5D8EA65B, 0x82B65D82, 0xC98F5D5B, 0x82B582BD, 0x82AA5D82, 0xC182C482, 0xAD82BE82, 0xB382A281, 0x42000000, 0x54686973, 0x20646174, 0x61207665, 0x7273696F, 0x6E206973, 0x20696E63, 0x6F727265, 0x63742E0A, 0x53617665, 0x2067616D, 0x65206461, 0x74612061, 0x6761696E, 0x20696E20, 0x74686520, 0x47616D65, 0x20446174, 0x61206D65, 0x6E752069, 0x6E204F70, 0x74696F6E, 0x732E2000, 0x56455253, 0x494F4E20, 0x47455200, 0x56455253, 0x494F4E20, 0x46524100, 0x56455253, 0x494F4E20, 0x53504100, 0x56455253, 0x494F4E20, 0x49544100, 0x8366815B, 0x835E82CC, 0x836F815B, 0x83578387, 0x839382AA, 0x88E15B82, 0xBF82AA5D, 0x82A282DC, 0x82B78142, 0x0A834983, 0x76835683, 0x87839382, 0xCC835181, 0x5B838083, 0x66815B83, 0x5E82C50A, 0x8366815B, 0x835E82F0, 0x835A815B, 0x837582B5, 0x92BC5B82, 0xC882A85D, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x7574206C, 0x6F616469, 0x6E670A20, 0x2083B220, 0x81632054, 0x72792061, 0x6761696E, 0x20000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083, 0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E200000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083, 0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163, 0x838A8358, 0x836782F0, 0x8EE65B82, 0xC65D82E7, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083, 0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742065, 0x72617369, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E2000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20474552, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20465241, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20535041, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20495441, 0x00000000, 0x839F8163, 0x8FC15B82, 0xAF5D82B3, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083, 0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742063, 0x6865636B, 0x696E670A, 0x83B22081, 0x63205472, 0x79206167, 0x61696E20, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20474552, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20465241, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20535041, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20495441, 0x00000000, 0x839F8163, 0x83608346, 0x8362834E, 0x82B982B8, 0x82C98F49, 0x5B82A85D, 0x82ED82E9, 0x2083B281, 0x63838A83, 0x67838983, 0x43000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x7574206C, 0x6F616469, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x2043686F, 0x6F736520, 0x536C6F74, 0x20000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204954, 0x41000000, 0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x8358838D, 0x83628367, 0x82F09149, 0x5B82A682, 0xE75D82D4, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E0A83B4, 0x20816320, 0x43686F6F, 0x73652053, 0x6C6F7420, 0x00000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204954, 0x41000000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x8358838D, 0x83628367, 0x82F09149, 0x5B82A682, 0xE75D82D4, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E200000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204954, 0x41000000, 0x839F8163, 0x838A8358, 0x836782F0, 0x8EE65B82, 0xC65D82E7, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742065, 0x72617369, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x2043686F, 0x6F736520, 0x536C6F74, 0x20000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x8FC15B82, 0xAF5D82B3, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x8358838D, 0x83628367, 0x82F09149, 0x5B82A682, 0xE75D82D4, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742063, 0x6865636B, 0x696E670A, 0x83B22081, 0x63205472, 0x79206167, 0x61696E0A, 0x83B42081, 0x63204368, 0x6F6F7365, 0x20536C6F, 0x74200000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x83608346, 0x8362834E, 0x82B982B8, 0x82C98F49, 0x5B82A85D, 0x82ED82E9, 0x0A83B281, 0x63838A83, 0x67838983, 0x432083B4, 0x81638358, 0x838D8362, 0x836782F0, 0x91495B82, 0xA682E75D, 0x82D40000, 0x506C6561, 0x73652070, 0x72657373, 0x20746865, 0x20839F20, 0x42757474, 0x6F6E2E20, 0x00000000, 0x43415054, 0x494F4E5F, 0x41204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x41204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x41205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x41204954, 0x41000000, 0x839F82F0, 0x899F5B82, 0xA85D82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x839F2081, 0x63204465, 0x6C657465, 0x2066696C, 0x65000000, 0x43415054, 0x494F4E5F, 0x41204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x41204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x41205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x41204954, 0x41000000, 0x839F8163, 0x8FC15B82, 0xAF5D82B7, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x7574206C, 0x6F616469, 0x6E670A83, 0xB4208163, 0x2043686F, 0x6F736520, 0x6120536C, 0x6F742000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB4816383, 0x58838D83, 0x62836782, 0xF091495B, 0x82A682E7, 0x5D82D400, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B4, 0x20816320, 0x43686F6F, 0x73652061, 0x20536C6F, 0x74200000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB4816383, 0x58838D83, 0x62836782, 0xF091495B, 0x82A682E7, 0x5D82D400, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x67000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x838A8358, 0x836782F0, 0x8EE65B82, 0xC65D82E7, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742065, 0x72617369, 0x6E670A83, 0xB4208163, 0x2043686F, 0x6F736520, 0x6120536C, 0x6F742000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204954, 0x41000000, 0x839F8163, 0x82AF82B3, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB4816383, 0x58838D83, 0x62836782, 0xF091495B, 0x82A682E7, 0x5D82D400, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742063, 0x6865636B, 0x696E670A, 0x83B42081, 0x63204368, 0x6F6F7365, 0x20612053, 0x6C6F7420, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204954, 0x41000000, 0x839F8163, 0x83608346, 0x8362834E, 0x82B982B8, 0x82C98F49, 0x5B82A85D, 0x82ED82E9, 0x0A83B481, 0x63835883, 0x8D836283, 0x6782F091, 0x495B82A6, 0x82E75D82, 0xD4000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x7574206C, 0x6F616469, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x20466F72, 0x6D617420, 0x00000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204954, 0x41000000, 0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E0A83B4, 0x20816320, 0x466F726D, 0x61742000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204954, 0x41000000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E0A83B4, 0x20816320, 0x466F726D, 0x61742000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204954, 0x41000000, 0x839F8163, 0x838A8358, 0x836782F0, 0x82C682E7, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742065, 0x72617369, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x20466F72, 0x6D617420, 0x00000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x47455200, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x46524100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x53504100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x49544100, 0x839F8163, 0x82AF82B3, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9, 0x00000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742063, 0x6865636B, 0x696E670A, 0x83B22081, 0x63205472, 0x79206167, 0x61696E0A, 0x83B42081, 0x6320466F, 0x726D6174, 0x20000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x47455200, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x46524100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x53504100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x49544100, 0x839F8163, 0x83608346, 0x8362834E, 0x82B982B8, 0x82C98F49, 0x5B82A85D, 0x82ED82E9, 0x0A83B281, 0x63838A83, 0x67838983, 0x432083B4, 0x81638374, 0x8348815B, 0x837D8362, 0x836782B7, 0x82E90000, 0x839F2081, 0x63204265, 0x67696E20, 0x77697468, 0x6F757420, 0x73617665, 0x696E670A, 0x83B22081, 0x63205472, 0x79206167, 0x61696E00, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8E6E5B82, 0xCD82B65D, 0x82DF82E9, 0x2083B281, 0x63838A83, 0x67838983, 0x43000000, 0x839F2081, 0x63204265, 0x67696E20, 0x77697468, 0x6F757420, 0x73617669, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x20526573, 0x65742061, 0x6E642061, 0x63636573, 0x73207379, 0x7374656D, 0x204D656D, 0x6F727920, 0x43617264, 0x20736372, 0x65656E00, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8E6E5B82, 0xCD82B65D, 0x82DF82E9, 0x2083B281, 0x63838A83, 0x67838983, 0x430A83B4, 0x8163838A, 0x835A8362, 0x836782B5, 0x82C4967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x89E65B82, 0xAA5D96CA, 0x5B82DF82, 0xF15D82D6, 0x00000000, 0x43686F6F, 0x73652074, 0x68652053, 0x6C6F7420, 0x77697468, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E73, 0x65727465, 0x642E2000, 0x43484F49, 0x43455F53, 0x4C4F5420, 0x47455200, 0x43484F49, 0x43455F53, 0x4C4F5420, 0x46524100, 0x43484F49, 0x43455F53, 0x4C4F5420, 0x53504100, 0x43484F49, 0x43455F53, 0x4C4F5420, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x82B382B5, 0x82BD8358, 0x838D8362, 0x836782F0, 0x0A91495B, 0x82A682E7, 0x5D82F182, 0xC582AD82, 0xBE82B382, 0xA2814200, 0x55736520, 0x2083AD20, 0x6F722083, 0xB5746F20, 0x73656C65, 0x63742E0A, 0x50726573, 0x73207468, 0x6520839F, 0x20427574, 0x746F6E20, 0x746F2063, 0x6F6E6669, 0x726D2061, 0x6E642074, 0x68652083, 0xA0204275, 0x74746F6E, 0x2063616E, 0x63656C2E, 0x20000000, 0x43415054, 0x494F4E5F, 0x43484F49, 0x43452047, 0x45520000, 0x43415054, 0x494F4E5F, 0x43484F49, 0x43452046, 0x52410000, 0x43415054, 0x494F4E5F, 0x43484F49, 0x43452053, 0x50410000, 0x43415054, 0x494F4E5F, 0x43484F49, 0x43452049, 0x54410000, 0x83AD82A9, 0x83B582C5, 0x91495B82, 0xA682E75D, 0x82F182C5, 0x8141839F, 0x82C58C88, 0x5B82AB5D, 0x82DF82C4, 0x82AD82BE, 0x82B382A2, 0x81420A83, 0xA082C583, 0x4C838383, 0x93835A83, 0x8B82B582, 0xDC82B781, 0x42000000, 0x54686520, 0x46494C45, 0x20446174, 0x61207361, 0x76652074, 0x6F207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x640A696E, 0x20534C4F, 0x54206861, 0x73206265, 0x656E2063, 0x616E6365, 0x6C6C6564, 0x2E000000, 0x4E4F5341, 0x56455F45, 0x58495420, 0x47455200, 0x4E4F5341, 0x56455F45, 0x58495420, 0x46524100, 0x4E4F5341, 0x56455F45, 0x58495420, 0x53504100, 0x4E4F5341, 0x56455F45, 0x58495420, 0x49544100, 0x46494C45, 0x8366815B, 0x835E82CC, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xD682CC83, 0x5A815B83, 0x7582F092, 0x865B82BF, 0x82E382A4, 0x5D8E7E5B, 0x82B55D82, 0xB582DC82, 0xB582BD81, 0x42000000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732064, 0x616D6167, 0x65642061, 0x6E642063, 0x616E6E6F, 0x74206265, 0x20757365, 0x642E0000, 0x57524F4E, 0x475F5345, 0x43544F52, 0x20474552, 0x00000000, 0x57524F4E, 0x475F5345, 0x43544F52, 0x20465241, 0x00000000, 0x57524F4E, 0x475F5345, 0x43544F52, 0x20535041, 0x00000000, 0x57524F4E, 0x475F5345, 0x43544F52, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD0A82, 0xB182ED82, 0xEA82C482, 0xA282E982, 0xCC82C58E, 0x675B82B5, 0x5D97705B, 0x82E682A4, 0x5D82C582, 0xAB82DC82, 0xB982F181, 0x42000000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732064, 0x616D6167, 0x65642061, 0x6E642063, 0x616E6E6F, 0x74206265, 0x20757365, 0x642E0000, 0x57524F4E, 0x475F4341, 0x52442047, 0x45520000, 0x57524F4E, 0x475F4341, 0x52442046, 0x52410000, 0x57524F4E, 0x475F4341, 0x52442053, 0x50410000, 0x57524F4E, 0x475F4341, 0x52442049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD0A82, 0xB182ED82, 0xEA82C482, 0xA282E982, 0xCC82C58E, 0x675B82B5, 0x5D97705B, 0x82E682A4, 0x5D82C582, 0xAB82DC82, 0xB982F181, 0x42000000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732063, 0x6F727275, 0x70746564, 0x20616E64, 0x206D7573, 0x74206265, 0x20666F72, 0x6D617474, 0x65642E0A, 0x4F4B2074, 0x6F20666F, 0x726D6174, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x206E6F77, 0x3F000000, 0x454E434F, 0x44494E47, 0x20474552, 0x00000000, 0x454E434F, 0x44494E47, 0x20465241, 0x00000000, 0x454E434F, 0x44494E47, 0x20535041, 0x00000000, 0x454E434F, 0x44494E47, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD8E67, 0x5B82C282, 0xA95D82A6, 0x82DC82B9, 0x82F18142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF093FC5B, 0x82A25D82, 0xEA92BC5B, 0x82C882A8, 0x5D82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732063, 0x6F727275, 0x70746564, 0x20616E64, 0x206D7573, 0x74206265, 0x20666F72, 0x6D617474, 0x65642E00, 0x454E434F, 0x44494E47, 0x20474552, 0x00000000, 0x454E434F, 0x44494E47, 0x20465241, 0x00000000, 0x454E434F, 0x44494E47, 0x20535041, 0x00000000, 0x454E434F, 0x44494E47, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD8E67, 0x5B82C282, 0xA95D82A6, 0x82DC82B9, 0x82F18142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF093FC5B, 0x82A25D82, 0xEA92BC5B, 0x82C882A8, 0x5D82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732063, 0x6F727275, 0x70746564, 0x20616E64, 0x206D7573, 0x74206265, 0x20666F72, 0x6D617474, 0x65642E0A, 0x4F4B2074, 0x6F20666F, 0x726D6174, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x206E6F77, 0x3F000000, 0x464F524D, 0x41545F51, 0x55455259, 0x20474552, 0x00000000, 0x464F524D, 0x41545F51, 0x55455259, 0x20465241, 0x00000000, 0x464F524D, 0x41545F51, 0x55455259, 0x20535041, 0x00000000, 0x464F524D, 0x41545F51, 0x55455259, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD8366, 0x815B835E, 0x82AA0A82, 0xB182ED82, 0xEA82C482, 0xA282E982, 0xCC82C583, 0x74834881, 0x5B837D83, 0x62836782, 0xAA954B97, 0x7682C582, 0xB781420A, 0x83748348, 0x815B837D, 0x83628367, 0x82B582C4, 0x82E082E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000, 0x4F4B2074, 0x6F20666F, 0x726D6174, 0x20746865, 0x0A4D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x534C4F54, 0x3F000000, 0x464F524D, 0x41545F51, 0x55455259, 0x32204745, 0x52000000, 0x464F524D, 0x41545F51, 0x55455259, 0x32204652, 0x41000000, 0x464F524D, 0x41545F51, 0x55455259, 0x32205350, 0x41000000, 0x464F524D, 0x41545F51, 0x55455259, 0x32204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82F00A83, 0x74834881, 0x5B837D83, 0x62836782, 0xB582C482, 0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A981, 0x48000000, 0x536C6F74, 0x20410000, 0x534C4F54, 0x5F412047, 0x45520000, 0x534C4F54, 0x5F412046, 0x52410000, 0x534C4F54, 0x5F412053, 0x50410000, 0x534C4F54, 0x5F412049, 0x54410000, 0x8358838D, 0x83628367, 0x82600000, 0x536C6F74, 0x20420000, 0x534C4F54, 0x5F422047, 0x45520000, 0x534C4F54, 0x5F422046, 0x52410000, 0x534C4F54, 0x5F422053, 0x50410000, 0x534C4F54, 0x5F422049, 0x54410000, 0x8358838D, 0x83628367, 0x82610000, 0x59455300, 0x48414920, 0x47455200, 0x48414920, 0x46524100, 0x48414920, 0x53504100, 0x48414920, 0x49544100, 0x82CD82A2, 0x00000000, 0x4E4F0000, 0x49494520, 0x47455200, 0x49494520, 0x46524100, 0x49494520, 0x53504100, 0x49494520, 0x49544100, 0x82A282A2, 0x82A60000, 0x466F726D, 0x61747469, 0x6E67206F, 0x66207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x540A6861, 0x73206265, 0x656E2063, 0x616E6365, 0x6C6C6564, 0x2E000000, 0x464F524D, 0x41545F43, 0x414E4345, 0x4C204745, 0x52000000, 0x464F524D, 0x41545F43, 0x414E4345, 0x4C204652, 0x41000000, 0x464F524D, 0x41545F43, 0x414E4345, 0x4C205350, 0x41000000, 0x464F524D, 0x41545F43, 0x414E4345, 0x4C204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83, 0x74834881, 0x5B837D83, 0x62836782, 0xF092865B, 0x82BF82E3, 0x5D8E7E5B, 0x82A482B5, 0x5D82B582, 0xDC82B582, 0xBD814200, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x646F6573, 0x206E6F74, 0x20686176, 0x650A656E, 0x6F756768, 0x20667265, 0x65207370, 0x6163652E, 0x20462D5A, 0x45524F20, 0x47582072, 0x65717569, 0x72657320, 0x7468650A, 0x666F6C6C, 0x6F77696E, 0x6720746F, 0x20736176, 0x65206974, 0x73206469, 0x66666572, 0x656E7420, 0x74797065, 0x73206F66, 0x20646174, 0x613A0A28, 0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642C0A, 0x706C6561, 0x73652067, 0x6F20746F, 0x20746865, 0x204E696E, 0x74656E64, 0x6F204761, 0x6D654375, 0x62650A4D, 0x656D6F72, 0x79204361, 0x7264206D, 0x616E6167, 0x656D656E, 0x74207363, 0x7265656E, 0x2E290A47, 0x616D6520, 0x44617461, 0x3A203120, 0x46696C65, 0x20616E64, 0x20342042, 0x6C6F636B, 0x730A4761, 0x72616765, 0x20446174, 0x613A2031, 0x2046696C, 0x6520616E, 0x64203138, 0x20426C6F, 0x636B730A, 0x47686F73, 0x74204461, 0x74613A20, 0x31204669, 0x6C652061, 0x6E642033, 0x20426C6F, 0x636B730A, 0x456D626C, 0x656D2044, 0x6174613A, 0x20312046, 0x696C6520, 0x616E6420, 0x3320426C, 0x6F636B73, 0x0A526570, 0x6C617920, 0x44617461, 0x3A203120, 0x46696C65, 0x20616E64, 0x20338160, 0x31332042, 0x6C6F636B, 0x73000000, 0x4E4F454E, 0x54204745, 0x52000000, 0x4E4F454E, 0x54204652, 0x41000000, 0x4E4F454E, 0x54205350, 0x41000000, 0x4E4F454E, 0x54204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C98BF3, 0x5B82A05D, 0x82AB9765, 0x5B82E682, 0xA4205D97, 0xCA5B82E8, 0x82E582A4, 0x5D82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A46, 0x2D5A4552, 0x4F204758, 0x82CC8A65, 0x5B82A982, 0xAD5D8374, 0x83408343, 0x838B82F0, 0x835A815B, 0x837582B7, 0x82E982C9, 0x82CD0A8F, 0xAD5B82B7, 0x82AD5D82, 0xC882AD82, 0xC682E088, 0xC85B82A2, 0x5D89BA5B, 0x82A95D82, 0xCC8BF35B, 0x82A05D82, 0xAB97655B, 0x82E682A4, 0x205D97CA, 0x5B82E882, 0xE582A45D, 0x82AA954B, 0x5B82D082, 0xC25D9776, 0x5B82E682, 0xA45D82C5, 0x82B78142, 0x0A288381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC93E0, 0x5B82C882, 0xA25D9765, 0x5B82E682, 0xA45D82F0, 0x90AE5B82, 0xB982A25D, 0x979D5B82, 0xE85D82B7, 0x82E982C9, 0x82CD8141, 0x0A967B5B, 0x82D982F1, 0x5D91CC5B, 0x82BD82A2, 0x5D82CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6889E65B, 0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC58D735B, 0x82A882B1, 0x5D82C882, 0xC182C482, 0xAD82BE82, 0xB382A229, 0x0A202083, 0x51815B83, 0x80836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68253, 0x8375838D, 0x8362834E, 0x0A20834B, 0x838C815B, 0x83578366, 0x815B835E, 0x3A837483, 0x40834383, 0x8B825082, 0xC282C682, 0x50825783, 0x75838D83, 0x62834E0A, 0x20835381, 0x5B835883, 0x67836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68252, 0x8375838D, 0x8362834E, 0x0A834783, 0x93837583, 0x8C838083, 0x66815B83, 0x5E3A8374, 0x83408343, 0x838B8250, 0x82C282C6, 0x82528375, 0x838D8362, 0x834E0A20, 0x20838A83, 0x76838C83, 0x43836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68252, 0x81608250, 0x82528375, 0x838D8362, 0x834E0A00, 0x54686572, 0x65206973, 0x206E6F74, 0x20656E6F, 0x75676820, 0x66726565, 0x20737061, 0x6365206F, 0x6E207468, 0x650A4D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E2054, 0x6F207361, 0x76652046, 0x494C4520, 0x44617461, 0x2C0A796F, 0x75206E65, 0x65642061, 0x74206C65, 0x61737420, 0x31206669, 0x6C652061, 0x6E642052, 0x45515549, 0x52454420, 0x626C6F63, 0x6B732E0A, 0x28546F20, 0x6D616E61, 0x67652066, 0x696C6573, 0x206F6E20, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642C, 0x0A706C65, 0x61736520, 0x676F2074, 0x6F207468, 0x65204E69, 0x6E74656E, 0x646F2047, 0x616D6543, 0x7562650A, 0x4D656D6F, 0x72792043, 0x61726420, 0x6D616E61, 0x67656D65, 0x6E742073, 0x63726565, 0x6E2E2900, 0x4E4F454E, 0x54204745, 0x52000000, 0x4E4F454E, 0x54204652, 0x41000000, 0x4E4F454E, 0x54205350, 0x41000000, 0x4E4F454E, 0x54204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C98BF3, 0x5B82A05D, 0x82AB9765, 0x5B82E682, 0xA4205D97, 0xCA5B82E8, 0x82E582A4, 0x5D82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A46, 0x494C4583, 0x66815B83, 0x5E82F083, 0x5A815B83, 0x7582B782, 0xE982C982, 0xCD0A8FAD, 0x5B82B782, 0xAD5D82C8, 0x82AD82C6, 0x82E08374, 0x83408343, 0x838B3182, 0xC282C652, 0x45515549, 0x52454483, 0x75838D83, 0x62834E95, 0x4B5B82D0, 0x82C25D97, 0x765B82E6, 0x82A45D82, 0xC582B781, 0x420A2883, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CC93, 0xE05B82C8, 0x82A25D97, 0x655B82E6, 0x82A45D82, 0xF090AE5B, 0x82B982A2, 0x5D979D5B, 0x82E85D82, 0xB782E982, 0xC982CD81, 0x410A967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D82CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836889E6, 0x5B82AA5D, 0x96CA5B82, 0xDF82F15D, 0x82C58D73, 0x5B82A882, 0xB15D82C8, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x290A0000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x646F6573, 0x206E6F74, 0x20686176, 0x650A656E, 0x6F756768, 0x20667265, 0x65207370, 0x6163652E, 0x20462D5A, 0x45524F20, 0x47582072, 0x65717569, 0x72657320, 0x7468650A, 0x666F6C6C, 0x6F77696E, 0x6720746F, 0x20736176, 0x65206974, 0x73206469, 0x66666572, 0x656E7420, 0x74797065, 0x73206F66, 0x20646174, 0x613A0A28, 0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642C0A, 0x706C6561, 0x73652067, 0x6F20746F, 0x20746865, 0x204E696E, 0x74656E64, 0x6F204761, 0x6D654375, 0x62650A4D, 0x656D6F72, 0x79204361, 0x7264206D, 0x616E6167, 0x656D656E, 0x74207363, 0x7265656E, 0x2E290A47, 0x616D6520, 0x44617461, 0x3A203120, 0x46696C65, 0x20616E64, 0x20342042, 0x6C6F636B, 0x730A4761, 0x72616765, 0x20446174, 0x613A2031, 0x2046696C, 0x6520616E, 0x64203138, 0x20426C6F, 0x636B730A, 0x47686F73, 0x74204461, 0x74613A20, 0x31204669, 0x6C652061, 0x6E642033, 0x20426C6F, 0x636B730A, 0x456D626C, 0x656D2044, 0x6174613A, 0x20312046, 0x696C6520, 0x616E6420, 0x3320426C, 0x6F636B73, 0x0A526570, 0x6C617920, 0x44617461, 0x3A203120, 0x46696C65, 0x20616E64, 0x20338160, 0x31332042, 0x6C6F636B, 0x73000000, 0x494E5353, 0x50414345, 0x20474552, 0x00000000, 0x494E5353, 0x50414345, 0x20465241, 0x00000000, 0x494E5353, 0x50414345, 0x20535041, 0x00000000, 0x494E5353, 0x50414345, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C98BF3, 0x5B82A05D, 0x82AB9765, 0x5B82E682, 0xA4205D97, 0xCA5B82E8, 0x82E582A4, 0x5D82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A46, 0x2D5A4552, 0x4F204758, 0x82CC8A65, 0x5B82A982, 0xAD5D8374, 0x83408343, 0x838B82F0, 0x835A815B, 0x837582B7, 0x82E982C9, 0x82CD0A8F, 0xAD5B82B7, 0x82AD5D82, 0xC882AD82, 0xC682E088, 0xC85B82A2, 0x5D89BA5B, 0x82A95D82, 0xCC8BF35B, 0x82A05D82, 0xAB97655B, 0x82E682A4, 0x205D97CA, 0x5B82E882, 0xE582A45D, 0x82AA954B, 0x5B82D082, 0xC25D9776, 0x5B82E682, 0xA45D82C5, 0x82B78142, 0x0A288381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC93E0, 0x5B82C882, 0xA25D9765, 0x5B82E682, 0xA45D82F0, 0x90AE5B82, 0xB982A25D, 0x979D5B82, 0xE85D82B7, 0x82E982C9, 0x82CD8141, 0x0A967B5B, 0x82D982F1, 0x5D91CC5B, 0x82BD82A2, 0x5D82CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6889E65B, 0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC58D735B, 0x82A882B1, 0x5D82C882, 0xC182C482, 0xAD82BE82, 0xB382A229, 0x0A202083, 0x51815B83, 0x80836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68253, 0x8375838D, 0x8362834E, 0x0A20834B, 0x838C815B, 0x83578366, 0x815B835E, 0x3A837483, 0x40834383, 0x8B825082, 0xC282C682, 0x50825783, 0x75838D83, 0x62834E0A, 0x20835381, 0x5B835883, 0x67836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68252, 0x8375838D, 0x8362834E, 0x0A834783, 0x93837583, 0x8C838083, 0x66815B83, 0x5E3A8374, 0x83408343, 0x838B8250, 0x82C282C6, 0x82528375, 0x838D8362, 0x834E0A20, 0x20838A83, 0x76838C83, 0x43836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68252, 0x81608250, 0x82528375, 0x838D8362, 0x834E0A00, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x646F6573, 0x206E6F74, 0x0A686176, 0x6520656E, 0x6F756768, 0x20667265, 0x65207370, 0x6163652E, 0x20417420, 0x6C656173, 0x74203120, 0x66696C65, 0x0A616E64, 0x20524551, 0x55495245, 0x4420626C, 0x6F636B73, 0x20617265, 0x206E6565, 0x64656420, 0x746F2073, 0x6176650A, 0x46494C45, 0x20446174, 0x612E2028, 0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x790A4361, 0x72642C20, 0x706C6561, 0x73652067, 0x6F20746F, 0x20746865, 0x204E696E, 0x74656E64, 0x6F204761, 0x6D654375, 0x62650A4D, 0x656D6F72, 0x79204361, 0x7264206D, 0x616E6167, 0x656D656E, 0x74207363, 0x7265656E, 0x2E290000, 0x494E5353, 0x50414345, 0x5F524550, 0x4C415920, 0x47455200, 0x494E5353, 0x50414345, 0x5F524550, 0x4C415920, 0x46524100, 0x494E5353, 0x50414345, 0x5F524550, 0x4C415920, 0x53504100, 0x494E5353, 0x50414345, 0x5F524550, 0x4C415920, 0x49544100, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C98BF3, 0x5B82A05D, 0x82AB9765, 0x5B82E682, 0xA4205D97, 0xCA5B82E8, 0x82E582A4, 0x5D82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A46, 0x494C4583, 0x66815B83, 0x5E82F083, 0x5A815B83, 0x7582B782, 0xE982C982, 0xCD0A8FAD, 0x5B82B782, 0xAD5D82C8, 0x82AD82C6, 0x82E08374, 0x83408343, 0x838B3182, 0xC282C652, 0x45515549, 0x52454483, 0x75838D83, 0x62834E95, 0x4B5B82D0, 0x82C25D97, 0x765B82E6, 0x82A45D82, 0xC582B781, 0x420A2883, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CC93, 0xE05B82C8, 0x82A25D97, 0x655B82E6, 0x82A45D82, 0xF090AE5B, 0x82B982A2, 0x5D979D5B, 0x82E85D82, 0xB782E982, 0xC982CD81, 0x410A967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D82CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836889E6, 0x5B82AA5D, 0x96CA5B82, 0xDF82F15D, 0x82C58D73, 0x5B82A882, 0xB15D82C8, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x290A0000, 0x54686572, 0x65206973, 0x20616C72, 0x65616479, 0x2046494C, 0x45204461, 0x74610A6F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E0A4F, 0x4B20746F, 0x20736176, 0x65206F76, 0x65722074, 0x68697320, 0x64617461, 0x3F000000, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x47455200, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x46524100, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x53504100, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x49544100, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x0A82B782, 0xC582C946, 0x494C4583, 0x66815B83, 0x5E82AA82, 0xA082E882, 0xDC82B781, 0x420A8FE3, 0x5B82A482, 0xED5D8F91, 0x5B82AA5D, 0x82AB82B5, 0x82C482E0, 0x82E682EB, 0x82B582A2, 0x82C582B7, 0x82A98148, 0x00000000, 0x54686520, 0x46494C45, 0x20446174, 0x61206F76, 0x65727772, 0x6974650A, 0x77617320, 0x63616E63, 0x656C6564, 0x2E000000, 0x4F564552, 0x57524954, 0x455F4341, 0x4E43454C, 0x20474552, 0x00000000, 0x4F564552, 0x57524954, 0x455F4341, 0x4E43454C, 0x20465241, 0x00000000, 0x4F564552, 0x57524954, 0x455F4341, 0x4E43454C, 0x20535041, 0x00000000, 0x4F564552, 0x57524954, 0x455F4341, 0x4E43454C, 0x20495441, 0x00000000, 0x46494C45, 0x8366815B, 0x835E82CC, 0x0A8FE35B, 0x82A482ED, 0x5D8F915B, 0x82AA5D82, 0xAB82F092, 0x865B82BF, 0x82E35D8E, 0x7E5B82A4, 0x82B55D82, 0xB582DC82, 0xB582BD81, 0x42000000, 0x46494C45, 0x20446174, 0x61207761, 0x73207361, 0x76656420, 0x746F0A74, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x00000000, 0x53415645, 0x5F454E44, 0x20474552, 0x00000000, 0x53415645, 0x5F454E44, 0x20465241, 0x00000000, 0x53415645, 0x5F454E44, 0x20535041, 0x00000000, 0x53415645, 0x5F454E44, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82D60A46, 0x494C4583, 0x66815B83, 0x5E82CC83, 0x5A815B83, 0x7582AA8F, 0x495B82A8, 0x5D82ED82, 0xE882DC82, 0xB582BD81, 0x42000000, 0x46726565, 0x20626C6F, 0x636B7320, 0x696E2053, 0x4C4F543A, 0x00000000, 0x52454D41, 0x494E5F42, 0x4C4F434B, 0x53204745, 0x52000000, 0x52454D41, 0x494E5F42, 0x4C4F434B, 0x53204652, 0x41000000, 0x52454D41, 0x494E5F42, 0x4C4F434B, 0x53205350, 0x41000000, 0x52454D41, 0x494E5F42, 0x4C4F434B, 0x53204954, 0x41000000, 0x534C4F54, 0x82CC8BF3, 0x5B82A05D, 0x82AB8375, 0x838D8362, 0x834E8146, 0x00000000, 0x426C6F63, 0x6B733A00, 0x424C4F43, 0x4B532047, 0x45520000, 0x424C4F43, 0x4B532046, 0x52410000, 0x424C4F43, 0x4B532053, 0x50410000, 0x424C4F43, 0x4B532049, 0x54410000, 0x8375838D, 0x8362834E, 0x81460000, 0x4C6F6164, 0x696E6720, 0x46494C45, 0x20446174, 0x61206672, 0x6F6D0A74, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642077, 0x61732063, 0x616E6365, 0x6C6C6564, 0x2E200000, 0x4E4F4C4F, 0x41445F45, 0x58495420, 0x47455200, 0x4E4F4C4F, 0x41445F45, 0x58495420, 0x46524100, 0x4E4F4C4F, 0x41445F45, 0x58495420, 0x53504100, 0x4E4F4C4F, 0x41445F45, 0x58495420, 0x49544100, 0x46494C45, 0x8366815B, 0x835E82CC, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xA982E782, 0xCC838D81, 0x5B836882, 0xF092865B, 0x82BF82E3, 0x82A45D8E, 0x7E5B82B5, 0x5D82B582, 0xDC82B582, 0xBD814200, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x68617320, 0x6265656E, 0x20666F72, 0x6D617474, 0x65642E00, 0x464F524D, 0x41545F45, 0x4E442047, 0x45520000, 0x464F524D, 0x41545F45, 0x4E442046, 0x52410000, 0x464F524D, 0x41545F45, 0x4E442053, 0x50410000, 0x464F524D, 0x41545F45, 0x4E442049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83, 0x74834881, 0x5B837D83, 0x62836782, 0xAA8F495B, 0x82A85D82, 0xED82E882, 0xDC82B582, 0xBD814200, 0x54686520, 0x46494C45, 0x20446174, 0x61206861, 0x73206265, 0x656E206C, 0x6F616465, 0x640A6672, 0x6F6D2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x00000000, 0x4C4F4144, 0x5F454E44, 0x20474552, 0x00000000, 0x4C4F4144, 0x5F454E44, 0x20465241, 0x00000000, 0x4C4F4144, 0x5F454E44, 0x20535041, 0x00000000, 0x4C4F4144, 0x5F454E44, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82A982E7, 0x82CC0A46, 0x494C4583, 0x66815B83, 0x5E82CC83, 0x8D815B83, 0x6882AA8F, 0x495B82A8, 0x5D82ED82, 0xE882DC82, 0xB582BD81, 0x42000000, 0x54686520, 0x462D5A45, 0x524F2047, 0x58204649, 0x4C452044, 0x61746120, 0x6F6E0A74, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F540A69, 0x7320636F, 0x72727570, 0x74656420, 0x616E6420, 0x6D757374, 0x20626520, 0x64656C65, 0x7465642E, 0x00000000, 0x44415441, 0x5F42524F, 0x4B454E20, 0x47455200, 0x44415441, 0x5F42524F, 0x4B454E20, 0x46524100, 0x44415441, 0x5F42524F, 0x4B454E20, 0x53504100, 0x44415441, 0x5F42524F, 0x4B454E20, 0x49544100, 0x46494C45, 0x8366815B, 0x835E82AA, 0x82B182ED, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0x0A837483, 0x40834383, 0x8B82F08F, 0xC15B82B5, 0x82E582A4, 0x5D8B8E5B, 0x2082AB82, 0xE55D82B5, 0x82DC82B7, 0x81420000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x77617320, 0x72656D6F, 0x7665642E, 0x0A4D656D, 0x6F727920, 0x43617264, 0x20616363, 0x65737320, 0x77617320, 0x73746F70, 0x7065642E, 0x20000000, 0x44455441, 0x43482047, 0x45520000, 0x44455441, 0x43482046, 0x52410000, 0x44455441, 0x43482053, 0x50410000, 0x44455441, 0x43482049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82AA94B2, 0x5B82CA5D, 0x82A982EA, 0x82DC82B5, 0x82BD8142, 0x0A8DEC5B, 0x82B382AC, 0x5D8BC65B, 0x82E582A4, 0x5D82F092, 0x865B82BF, 0x82E35D8E, 0x7E5B82A4, 0x82B55D82, 0xB582DC82, 0xB7814200, 0x54686572, 0x65206973, 0x206E6F20, 0x46494C45, 0x20446174, 0x61206F6E, 0x0A746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x534C4F54, 0x2E200000, 0x4E4F4649, 0x4C452047, 0x45520000, 0x4E4F4649, 0x4C452046, 0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000, 0x4E4F4649, 0x4C452049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x0A46494C, 0x45836681, 0x5B835E82, 0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000, 0x54686572, 0x65206973, 0x206E6F20, 0x5265706C, 0x61792044, 0x61746120, 0x6F6E0A74, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x00000000, 0x4E4F4649, 0x4C452047, 0x45520000, 0x4E4F4649, 0x4C452046, 0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000, 0x4E4F4649, 0x4C452049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x0A46494C, 0x45836681, 0x5B835E82, 0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000, 0x54686572, 0x65206973, 0x206E6F20, 0x47686F73, 0x74204461, 0x7461206F, 0x6E0A7468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E2000, 0x4E4F4649, 0x4C452047, 0x45520000, 0x4E4F4649, 0x4C452046, 0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000, 0x4E4F4649, 0x4C452049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x0A46494C, 0x45836681, 0x5B835E82, 0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000, 0x54686572, 0x65206973, 0x206E6F20, 0x456D626C, 0x656D2044, 0x61746120, 0x6F6E0A74, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x00000000, 0x4E4F4649, 0x4C452047, 0x45520000, 0x4E4F4649, 0x4C452046, 0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000, 0x4E4F4649, 0x4C452049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x0A46494C, 0x45836681, 0x5B835E82, 0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000, 0x556E6162, 0x6C652074, 0x6F206765, 0x74207468, 0x65206461, 0x7461206C, 0x6973740A, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x00000000, 0x4E4F4C49, 0x53545F45, 0x58495420, 0x47455200, 0x4E4F4C49, 0x53545F45, 0x58495420, 0x46524100, 0x4E4F4C49, 0x53545F45, 0x58495420, 0x53504100, 0x4E4F4C49, 0x53545F45, 0x58495420, 0x49544100, 0x534C4F54, 0x82CC8366, 0x815B835E, 0x838A8358, 0x836782AA, 0x0A82C682, 0xEA82DC82, 0xB982F182, 0xC582B582, 0xBD814200, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x206F6E0A, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F542E, 0x20000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204745, 0x52000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204652, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54205350, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x0A836681, 0x5B835E82, 0xAA3182C2, 0x82E082A0, 0x82E882DC, 0x82B982F1, 0x82C582B5, 0x82BD8142, 0x00000000, 0x54686520, 0x64617461, 0x206C6973, 0x74206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x0A696E20, 0x534C4F54, 0x20686173, 0x20626565, 0x6E206C6F, 0x61646564, 0x2E000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x00000000, 0x4C495354, 0x5F454E44, 0x20465241, 0x00000000, 0x4C495354, 0x5F454E44, 0x20535041, 0x00000000, 0x4C495354, 0x5F454E44, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83, 0x66815B83, 0x5E838A83, 0x58836782, 0xF093C75B, 0x82E65D82, 0xDD82B182, 0xDD82DC82, 0xB582BD81, 0x42000000, 0x446F6E65, 0x20636865, 0x636B696E, 0x67207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E0000, 0x43484543, 0x4B5F454E, 0x44204745, 0x52000000, 0x43484543, 0x4B5F454E, 0x44204652, 0x41000000, 0x43484543, 0x4B5F454E, 0x44205350, 0x41000000, 0x43484543, 0x4B5F454E, 0x44204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83, 0x60834683, 0x62834E82, 0xAA5B82B5, 0x5D8F495B, 0x82E382A4, 0x5D97B95B, 0x82E882E5, 0x5D82B55B, 0x82A45D82, 0xDC82B582, 0xBD814200, 0x46494C45, 0x20446174, 0x61206465, 0x6C657469, 0x6F6E206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x640A696E, 0x20534C4F, 0x54207761, 0x73206361, 0x6E63656C, 0x6C65642E, 0x00000000, 0x4E4F4445, 0x4C5F4558, 0x49542047, 0x45520000, 0x4E4F4445, 0x4C5F4558, 0x49542046, 0x52410000, 0x4E4F4445, 0x4C5F4558, 0x49542053, 0x50410000, 0x4E4F4445, 0x4C5F4558, 0x49542049, 0x54410000, 0x534C4F54, 0x82CC4649, 0x4C458366, 0x815B835E, 0x82CC8DED, 0x5B82B382, 0xAD5D8F9C, 0x5B82B682, 0xE55D82F0, 0x92865B82, 0xBF82E382, 0xA45D8E7E, 0x5B82B55D, 0x82B582DC, 0x82B582BD, 0x81420000, 0x31204649, 0x4C452044, 0x61746120, 0x77617320, 0x65726173, 0x65642066, 0x726F6D20, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F542E, 0x00000000, 0x44454C45, 0x54455F45, 0x4E442047, 0x45520000, 0x44454C45, 0x54455F45, 0x4E442046, 0x52410000, 0x44454C45, 0x54455F45, 0x4E442053, 0x50410000, 0x44454C45, 0x54455F45, 0x4E442049, 0x54410000, 0x534C4F54, 0x82CC4649, 0x4C458366, 0x815B835E, 0x82F08250, 0x82C28FC1, 0x5B82AF5D, 0x82B582DC, 0x82B582BD, 0x81420000, 0x4E4F5720, 0x464F524D, 0x41545449, 0x4E470000, 0x464F524D, 0x41545F4E, 0x4F572047, 0x45520000, 0x464F524D, 0x41545F4E, 0x4F572046, 0x52410000, 0x464F524D, 0x41545F4E, 0x4F572053, 0x50410000, 0x464F524D, 0x41545F4E, 0x4F572049, 0x54410000, 0x4E4F5720, 0x464F524D, 0x41545449, 0x4E470000, 0x4E4F5720, 0x53415649, 0x4E470000, 0x53415645, 0x5F4E4F57, 0x20474552, 0x00000000, 0x53415645, 0x5F4E4F57, 0x20465241, 0x00000000, 0x53415645, 0x5F4E4F57, 0x20535041, 0x00000000, 0x53415645, 0x5F4E4F57, 0x20495441, 0x00000000, 0x4E4F5720, 0x53415649, 0x4E470000, 0x4E4F5720, 0x4D414B49, 0x4E47204C, 0x49535400, 0x4C495354, 0x5F4E4F57, 0x20474552, 0x00000000, 0x4C495354, 0x5F4E4F57, 0x20465241, 0x00000000, 0x4C495354, 0x5F4E4F57, 0x20535041, 0x00000000, 0x4C495354, 0x5F4E4F57, 0x20495441, 0x00000000, 0x4E4F5720, 0x4D414B49, 0x4E47204C, 0x49535400, 0x4E4F5720, 0x43484543, 0x4B494E47, 0x00000000, 0x4C495354, 0x5F4E4F57, 0x20474552, 0x00000000, 0x4C495354, 0x5F4E4F57, 0x20465241, 0x00000000, 0x4C495354, 0x5F4E4F57, 0x20535041, 0x00000000, 0x4C495354, 0x5F4E4F57, 0x20495441, 0x00000000, 0x4E4F5720, 0x43484543, 0x4B494E47, 0x00000000, 0x41636365, 0x7373696E, 0x67207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E0A44, 0x6F206E6F, 0x7420746F, 0x75636820, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x6F722050, 0x4F574552, 0x20427574, 0x746F6E2E, 0x00000000, 0x41434345, 0x53532047, 0x45520000, 0x41434345, 0x53532046, 0x52410000, 0x41434345, 0x53532053, 0x50410000, 0x41434345, 0x53532049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8341834E, 0x835A8358, 0x92865B82, 0xBF82E382, 0xA45D82C5, 0x82B78142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xE293645B, 0x82C582F1, 0x5D8CB95B, 0x82B082F1, 0x5D82C990, 0x475B82B3, 0x82ED5D82, 0xE782C882, 0xA282C582, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x41636365, 0x7373696E, 0x67207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E0A44, 0x6F206E6F, 0x7420746F, 0x75636820, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x6F722050, 0x4F574552, 0x20427574, 0x746F6E2E, 0x00000000, 0x41434345, 0x53532047, 0x45520000, 0x41434345, 0x53532046, 0x52410000, 0x41434345, 0x53532053, 0x50410000, 0x41434345, 0x53532049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8341834E, 0x835A8358, 0x92865B82, 0xBF82E382, 0xA45D82C5, 0x82B78142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xE293645B, 0x82C582F1, 0x5D8CB95B, 0x82B082F1, 0x5D82C990, 0x475B82B3, 0x82ED5D82, 0xE782C882, 0xA282C582, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x4F4B2074, 0x6F207361, 0x76652046, 0x494C4520, 0x746F2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F543F00, 0x53415645, 0x5F515545, 0x52592047, 0x45520000, 0x53415645, 0x5F515545, 0x52592046, 0x52410000, 0x53415645, 0x5F515545, 0x52592053, 0x50410000, 0x53415645, 0x5F515545, 0x52592049, 0x54410000, 0x534C4F54, 0x82C94649, 0x4C4582F0, 0x835A815B, 0x837582B5, 0x82C482E0, 0x0A82E682, 0xEB82B582, 0xA282C582, 0xB782A981, 0x48000000, 0x49662079, 0x6F752073, 0x74617274, 0x206E6F77, 0x2C0A796F, 0x75207769, 0x6C6C206E, 0x6F742062, 0x65206162, 0x6C652074, 0x6F207361, 0x76652E00, 0x43414E4E, 0x4F545F53, 0x41564520, 0x47455200, 0x43414E4E, 0x4F545F53, 0x41564520, 0x46524100, 0x43414E4E, 0x4F545F53, 0x41564520, 0x53504100, 0x43414E4E, 0x4F545F53, 0x41564520, 0x49544100, 0x82B182CC, 0x82DC82DC, 0x8E6E5B82, 0xCD82B65D, 0x82DF82BD, 0x8FEA5B82, 0xCE5D8D87, 0x5B82A082, 0xA25D0A83, 0x5A815B83, 0x7582C582, 0xAB82DC82, 0xB982F100, 0x54686572, 0x65206172, 0x65206E6F, 0x204D656D, 0x6F727920, 0x43617264, 0x7320696E, 0x73657274, 0x65642070, 0x726F7065, 0x726C792E, 0x0A506C65, 0x61736520, 0x63686563, 0x6B20636F, 0x6E6E6563, 0x74696F6E, 0x73206F72, 0x20696E73, 0x65727420, 0x61204D65, 0x6D6F7279, 0x20436172, 0x642E0A49, 0x6620796F, 0x75207374, 0x61727420, 0x6E6F772C, 0x20796F75, 0x2077696C, 0x6C206E6F, 0x74206265, 0x2061626C, 0x6520746F, 0x20736176, 0x65207468, 0x65206761, 0x6D652E00, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442047, 0x45520000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442046, 0x52410000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442053, 0x50410000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA95B82, 0xDD5D82C2, 0x82A982E8, 0x82DC82B9, 0x82F18142, 0x0A90DA5B, 0x82B982C2, 0x5D91B15B, 0x82BC82AD, 0x5D82F08A, 0x6D5B82A9, 0x82AD5D94, 0x465B82C9, 0x82F15D82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A82B1, 0x82CC82DC, 0x82DC8E6E, 0x5B82CD82, 0xB65D82DF, 0x82BD8FEA, 0x5B82CE5D, 0x8D875B82, 0xA082A25D, 0x0A835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF1000000, 0x54686520, 0x64657669, 0x63652069, 0x6E20534C, 0x4F542069, 0x73206E6F, 0x74207375, 0x70706F72, 0x7465642E, 0x0A506C65, 0x61736520, 0x696E7365, 0x72742061, 0x204D656D, 0x6F727920, 0x43617264, 0x2E000000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442047, 0x45520000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442046, 0x52410000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442053, 0x50410000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x836888C8, 0x8A4F82CC, 0x82E082CC, 0x82AA8CA9, 0x5B82DD5D, 0x82C282A9, 0x82E882DC, 0x82B582BD, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F082, 0xB382B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x45697468, 0x65722047, 0x616D6520, 0x44617461, 0x20776173, 0x206E6F74, 0x206C6F61, 0x6465640A, 0x6F722074, 0x6865206F, 0x72696769, 0x6E616C20, 0x4D656D6F, 0x72792043, 0x6172642C, 0x0A66726F, 0x6D207768, 0x69636820, 0x74686520, 0x47616D65, 0x20646174, 0x61207761, 0x73206C6F, 0x61646564, 0x2C0A6861, 0x73206265, 0x656E2072, 0x656D6F76, 0x65642E00, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA838D, 0x815B8368, 0x82B382EA, 0x82C482A2, 0x82C882A2, 0x82A90A83, 0x51815B83, 0x80836681, 0x5B835E82, 0xF0838D81, 0x5B836882, 0xB582BD83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x680A82C5, 0x82CD82A0, 0x82E882DC, 0x82B982F1, 0x81422883, 0x51815B83, 0x80836681, 0x5B835E82, 0xCC835A81, 0x5B837581, 0x410A838D, 0x815B8368, 0x82CD8141, 0x83498376, 0x83568387, 0x839382CC, 0x83818382, 0x838A815B, 0x834A815B, 0x83680A83, 0x81836A83, 0x85815B82, 0xA982E789, 0xC25B82A9, 0x5D945C5B, 0x82CC82A4, 0x5D82C582, 0xB7814229, 0x00000000, 0x45697468, 0x65722047, 0x616D6520, 0x44617461, 0x20776173, 0x206E6F74, 0x206C6F61, 0x6465640A, 0x6F722074, 0x6865206F, 0x72696769, 0x6E616C20, 0x4D656D6F, 0x72792043, 0x6172642C, 0x0A66726F, 0x6D207768, 0x69636820, 0x74686520, 0x47616D65, 0x20646174, 0x61207761, 0x73206C6F, 0x61646564, 0x2C0A2068, 0x61732062, 0x65656E20, 0x72656D6F, 0x7665642E, 0x00000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA838D, 0x815B8368, 0x82B382EA, 0x82C482A2, 0x82C882A2, 0x82A90A83, 0x51815B83, 0x80836681, 0x5B835E82, 0xF0838D81, 0x5B836882, 0xB582BD83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x680A82C5, 0x82CD82A0, 0x82E882DC, 0x82B982F1, 0x81420000, 0x44617461, 0x00000000, 0x46696C65, 0x20474552, 0x00000000, 0x46696C65, 0x20465241, 0x00000000, 0x46696C65, 0x20535041, 0x00000000, 0x46696C65, 0x20495441, 0x00000000, 0x8366815B, 0x835E0000, 0x47616D65, 0x00000000, 0x53797374, 0x656D2047, 0x45520000, 0x53797374, 0x656D2046, 0x52410000, 0x53797374, 0x656D2053, 0x50410000, 0x53797374, 0x656D2049, 0x54410000, 0x8351815B, 0x83800000, 0x44656275, 0x67000000, 0x44656275, 0x67204745, 0x52000000, 0x44656275, 0x67204652, 0x41000000, 0x44656275, 0x67205350, 0x41000000, 0x44656275, 0x67204954, 0x41000000, 0x8366836F, 0x8362834F, 0x00000000, 0x5265706C, 0x61790000, 0x5265706C, 0x61792047, 0x45520000, 0x5265706C, 0x61792046, 0x52410000, 0x5265706C, 0x61792053, 0x50410000, 0x5265706C, 0x61792049, 0x54410000, 0x838A8376, 0x838C8343, 0x00000000, 0x456D626C, 0x656D0000, 0x456D626C, 0x656D2047, 0x45520000, 0x456D626C, 0x656D2046, 0x52410000, 0x456D626C, 0x656D2053, 0x50410000, 0x456D626C, 0x656D2049, 0x54410000, 0x83478393, 0x8375838C, 0x83800000, 0x47686F73, 0x74000000, 0x47686F73, 0x74204745, 0x52000000, 0x47686F73, 0x74204652, 0x41000000, 0x47686F73, 0x74205350, 0x41000000, 0x47686F73, 0x74204954, 0x41000000, 0x8353815B, 0x83588367, 0x00000000, 0x47617261, 0x67650000, 0x43757374, 0x6F6D2047, 0x45520000, 0x43757374, 0x6F6D2046, 0x52410000, 0x43757374, 0x6F6D2053, 0x50410000, 0x43757374, 0x6F6D2049, 0x54410000, 0x834B838C, 0x815B8357, 0x00000000, 0x47616D65, 0x00000000, 0x47616D65, 0x20474552, 0x00000000, 0x47616D65, 0x20465241, 0x00000000, 0x47616D65, 0x20535041, 0x00000000, 0x47616D65, 0x20495441, 0x00000000, 0x8351815B, 0x83800000, 0x54686572, 0x65206973, 0x206E6F74, 0x20656E6F, 0x75676820, 0x66726565, 0x20737061, 0x6365206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x640A696E, 0x20257320, 0x746F2073, 0x61766520, 0x616C6C20, 0x74797065, 0x73206F66, 0x206E6577, 0x2066696C, 0x65732E0A, 0x45786973, 0x74696E67, 0x20462D5A, 0x45524F20, 0x47582066, 0x696C6573, 0x206D6179, 0x20626520, 0x65726173, 0x6564206F, 0x72206F76, 0x65727772, 0x69747465, 0x6E2E0A28, 0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642C20, 0x706C6561, 0x73652067, 0x6F20746F, 0x0A746865, 0x204D656D, 0x6F727920, 0x43617264, 0x206D616E, 0x6167656D, 0x656E7420, 0x73637265, 0x656E2E29, 0x20496E20, 0x6F726465, 0x7220746F, 0x20736176, 0x650A6120, 0x6E657720, 0x66696C65, 0x2C207468, 0x6520666F, 0x6C6C6F77, 0x696E6720, 0x6E756D62, 0x6572206F, 0x66206672, 0x65652066, 0x696C6573, 0x0A616E64, 0x20626C6F, 0x636B7320, 0x6D757374, 0x20626520, 0x61766169, 0x6C61626C, 0x653A0000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x82A282AD, 0x82C282A9, 0x82CC8366, 0x815B835E, 0x82CD835A, 0x815B8375, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0A257382, 0xCC838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xC98BF35B, 0x82A05D82, 0xAB976597, 0xCA82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A83, 0x5A815B83, 0x7582B782, 0xE982C982, 0xCD8FAD5B, 0x82B782AD, 0x5D82C882, 0xAD82C682, 0xE088C85B, 0x82A25D89, 0xBA5B82A9, 0x5D82CC8B, 0xF35B82A0, 0x5D82AB97, 0x655B82E6, 0x82A4205D, 0x97CA5B82, 0xE882E582, 0xA45D82AA, 0x954B5B82, 0xD082C25D, 0x97765B82, 0xE682A45D, 0x82C582B7, 0x81420A28, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x93E05B82, 0xC882A25D, 0x97655B82, 0xE682A45D, 0x82F090AE, 0x5B82B982, 0xA25D979D, 0x5B82E85D, 0x82B782E9, 0x82C982CD, 0x81410A96, 0x7B5B82D9, 0x82F15D91, 0xCC5B82BD, 0x82A25D82, 0xCC838183, 0x82838A81, 0x5B834A81, 0x5B836889, 0xE65B82AA, 0x5D96CA5B, 0x82DF82F1, 0x5D82C58D, 0x735B82A8, 0x82B15D82, 0xC882C182, 0xC482AD82, 0xBE82B382, 0xA2290A00, 0x2F626366, 0x66613061, 0x302F312F, 0x62636666, 0x66666666, 0x2F204669, 0x6C652061, 0x6E64202F, 0x62636666, 0x61306130, 0x2F202020, 0x20202020, 0x202F6263, 0x66666666, 0x66662F20, 0x426C6F63, 0x6B730000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x83748340, 0x8343838B, 0x2F626366, 0x66613061, 0x302F312F, 0x62636666, 0x66666666, 0x2F82C220, 0x82C62F62, 0x63666661, 0x3061302F, 0x2534642F, 0x62636666, 0x66666666, 0x2F837583, 0x8D836283, 0x4E000000, 0x2F626366, 0x66613061, 0x302F312F, 0x62636666, 0x66666666, 0x2F204669, 0x6C652061, 0x6E64202F, 0x62636666, 0x61306130, 0x2F825281, 0x60253264, 0x2F626366, 0x66666666, 0x662F2042, 0x6C6F636B, 0x73000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x83748340, 0x8343838B, 0x2F626366, 0x66613061, 0x302F312F, 0x62636666, 0x66666666, 0x2F82C220, 0x82C62F62, 0x63666661, 0x3061302F, 0x82528160, 0x2532642F, 0x62636666, 0x66666666, 0x2F837583, 0x8D836283, 0x4E000000, 0x4E6F204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E0A, 0x506C6561, 0x73652069, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x6172642E, 0x00000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA95B82, 0xDD5D82C2, 0x82A982E8, 0x82DC82B9, 0x82F18142, 0x0A90DA5B, 0x82B982C2, 0x5D91B15B, 0x82BC82AD, 0x5D82F08A, 0x6D5B82A9, 0x82AD5D94, 0x465B82C9, 0x82F15D82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, 0x53415645, 0x00000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x835A815B, 0x83750000, 0x4C4F4144, 0x00000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x838D815B, 0x83680000, 0x434F5059, 0x00000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x83528373, 0x815B0000, 0x45524153, 0x45000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x82AF2082, 0xB7000000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x6E6F7420, 0x62652075, 0x7365642E, 0x0A506C65, 0x61736520, 0x72656D6F, 0x76652069, 0x742E2000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD, 0x8E675B82, 0xB55D9770, 0x5B82E682, 0xA45D82C5, 0x82AB82DC, 0x82B982F1, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB25B82CA, 0x5D82A282, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x41636365, 0x7373696E, 0x67207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E, 0x20446F20, 0x6E6F7420, 0x746F7563, 0x68207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x64206F72, 0x20504F57, 0x45522042, 0x7574746F, 0x6E2E0000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8341834E, 0x835A8358, 0x928682C5, 0x82B78142, 0x83818382, 0x838A815B, 0x834A815B, 0x836882E2, 0x93648CB9, 0x82C99047, 0x82E782C8, 0x82A282C5, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53617669, 0x6E670000, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x835A815B, 0x83759286, 0x00000000, 0x536F6D65, 0x20462D5A, 0x45524F20, 0x47582066, 0x696C6573, 0x206F6E0A, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x61726520, 0x636F7272, 0x75707465, 0x642E0A00, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204745, 0x52000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204652, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54205350, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x0A836681, 0x5B835E82, 0xAA3182C2, 0x82E082A0, 0x82E882DC, 0x82B982F1, 0x82C582B5, 0x82BD8142, 0x0A2882B1, 0x82ED82EA, 0x82BD8366, 0x815B835E, 0x82AA91B6, 0x5B82BB82, 0xF15D8DDD, 0x5B82B482, 0xA25D82B5, 0x82C482A2, 0x82DC82B7, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CC93, 0xE05B82C8, 0x82A25D97, 0x655B82E6, 0x82A45D82, 0xF090AE5B, 0x82B982A2, 0x5D979D5B, 0x82E85D82, 0xB782E982, 0xC982CD81, 0x410A967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D82CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836889E6, 0x96CA82C5, 0x82A882B1, 0x82C882C1, 0x82C482AD, 0x82BE82B3, 0x82A22900, 0x54686520, 0x64617461, 0x206C6973, 0x74206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x534C4F54, 0x0A686173, 0x20626565, 0x6E207265, 0x61642E20, 0x28536F6D, 0x6520462D, 0x5A45524F, 0x20475820, 0x66696C65, 0x73206F6E, 0x0A746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x534C4F54, 0x20617265, 0x20636F72, 0x72757074, 0x65642E29, 0x00000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x00000000, 0x4C495354, 0x5F454E44, 0x20465241, 0x00000000, 0x4C495354, 0x5F454E44, 0x20535041, 0x00000000, 0x4C495354, 0x5F454E44, 0x20495441, 0x00000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83, 0x66815B83, 0x5E838A83, 0x58836782, 0xF093C75B, 0x82E65D82, 0xDD82B182, 0xDD82DC82, 0xB582BD81, 0x420A2882, 0xB182ED82, 0xEA82BD83, 0x66815B83, 0x5E82AA91, 0xB65B82BB, 0x82F15D8D, 0xDD5B82B4, 0x82A25D82, 0xB582C482, 0xA282DC82, 0xB781420A, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x93E05B82, 0xC882A25D, 0x97655B82, 0xE682A45D, 0x82F090AE, 0x5B82B982, 0xA25D979D, 0x5B82E85D, 0x82B782E9, 0x82C982CD, 0x81410A96, 0x7B5B82D9, 0x82F15D91, 0xCC5B82BD, 0x82A25D82, 0xCC838183, 0x82838A81, 0x5B834A81, 0x5B836889, 0xE696CA82, 0xC582A882, 0xB182C882, 0xC182C482, 0xAD82BE82, 0xB382A229, 0x00000000, 0x536F6D65, 0x20462D5A, 0x45524F20, 0x47582066, 0x696C6573, 0x206F6E0A, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x61726520, 0x636F7272, 0x75707465, 0x642E0A50, 0x6C656173, 0x6520676F, 0x20746F20, 0x4F707469, 0x6F6E7320, 0x746F206D, 0x616E6167, 0x65207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E0000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204745, 0x52000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204652, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54205350, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204954, 0x41000000, 0x00000000, 0x54686520, 0x64617461, 0x206C6973, 0x74206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x534C4F54, 0x0A686173, 0x20626565, 0x6E207265, 0x61642E20, 0x28536F6D, 0x6520462D, 0x5A45524F, 0x20475820, 0x66696C65, 0x73206F6E, 0x0A746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x534C4F54, 0x20617265, 0x20636F72, 0x72757074, 0x65642E0A, 0x506C6561, 0x73652067, 0x6F20746F, 0x204F7074, 0x696F6E73, 0x206D616E, 0x61676520, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642E, 0x29000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x00000000, 0x4C495354, 0x5F454E44, 0x20465241, 0x00000000, 0x4C495354, 0x5F454E44, 0x20535041, 0x00000000, 0x4C495354, 0x5F454E44, 0x20495441, 0x00000000, 0x00000000, 0x4E6F204D, 0x656D6F72, 0x79204361, 0x72642066, 0x6F756E64, 0x20696E20, 0x536C6F74, 0x20412E20, 0x506C6561, 0x73652072, 0x652D696E, 0x73657274, 0x20746865, 0x0A6F7269, 0x67696E61, 0x6C204D65, 0x6D6F7279, 0x20436172, 0x64206672, 0x6F6D2077, 0x68696368, 0x20746865, 0x2047616D, 0x65206461, 0x74612077, 0x6173206C, 0x6F616465, 0x642E0A83, 0x9F204275, 0x74746F6E, 0x20816320, 0x52657472, 0x790A83A0, 0x20427574, 0x746F6E20, 0x81632043, 0x6F6E7469, 0x6E756520, 0x77697468, 0x6F757420, 0x73617669, 0x6E670000, 0x4C495354, 0x5F454E44, 0x20474552, 0x00000000, 0x4C495354, 0x5F454E44, 0x20465241, 0x00000000, 0x4C495354, 0x5F454E44, 0x20535041, 0x00000000, 0x4C495354, 0x5F454E44, 0x20495441, 0x00000000, 0x8358838D, 0x83628367, 0x826082CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x94B25B82, 0xCA5D82A9, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0x0A835181, 0x5B838083, 0x66815B83, 0x5E82F083, 0x8D815B83, 0x6882B582, 0xBD838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF00A8358, 0x838D8362, 0x83678260, 0x82C982B3, 0x82B582C4, 0x839F837B, 0x835E8393, 0x82F0899F, 0x5B82A85D, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A83, 0x4C838383, 0x93835A83, 0x8B82B782, 0xE982C982, 0xCD83A082, 0xF0899F5B, 0x82A85D82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, 0x41726520, 0x796F7520, 0x73757265, 0x20796F75, 0x0A77616E, 0x7420746F, 0x2064656C, 0x65746520, 0x74686973, 0x3F000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x00000000, 0x4C495354, 0x5F454E44, 0x20465241, 0x00000000, 0x4C495354, 0x5F454E44, 0x20535041, 0x00000000, 0x4C495354, 0x5F454E44, 0x20495441, 0x00000000, 0x967B5B82, 0xD982F15D, 0x93965B82, 0xC682A45D, 0x82C98FC1, 0x5B82AF5D, 0x82B582C4, 0x82E00A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, 0x54686520, 0x64657669, 0x63652069, 0x6E20534C, 0x4F542069, 0x73206E6F, 0x74206120, 0x4D656D6F, 0x72792043, 0x6172642E, 0x0A506C65, 0x61736520, 0x696E7365, 0x72742061, 0x204D656D, 0x6F727920, 0x43617264, 0x2E000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x00000000, 0x4C495354, 0x5F454E44, 0x20465241, 0x00000000, 0x4C495354, 0x5F454E44, 0x20535041, 0x00000000, 0x4C495354, 0x5F454E44, 0x20495441, 0x00000000, 0x83818382, 0x838A815B, 0x834A815B, 0x836888C8, 0x8A4F82CC, 0x82E082CC, 0x82AA8CA9, 0x5B82DD5D, 0x82C282A9, 0x82E882DC, 0x82B582BD, 0x81420A82, 0xB182CC82, 0xDC82DC82, 0xC582CD8D, 0xEC5B82B3, 0x82AC5D8B, 0xC65B82E5, 0x82A45D82, 0xAA95DB5B, 0x82D95D91, 0xB65B82BC, 0x82F15D82, 0xC582AB82, 0xDC82B982, 0xF1814200, 0x43726561, 0x74656420, 0x456D626C, 0x656D7320, 0x63616E6E, 0x6F742062, 0x650A7361, 0x76656420, 0x746F2074, 0x68697320, 0x4D656D6F, 0x72792043, 0x6172642E, 0x00000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x00000000, 0x4C495354, 0x5F454E44, 0x20465241, 0x00000000, 0x4C495354, 0x5F454E44, 0x20535041, 0x00000000, 0x4C495354, 0x5F454E44, 0x20495441, 0x00000000, 0x82B182CC, 0x82DC82DC, 0x82C582CD, 0x83478393, 0x8375838C, 0x838082CC, 0x8DEC5B82, 0xB382AC5D, 0x8BC65B82, 0xE582A45D, 0x82AA95DB, 0x5B82D95D, 0x91B65B82, 0xBC82F15D, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x00000000, 0x54686520, 0x46494C45, 0x20446174, 0x61206578, 0x69737473, 0x20696E20, 0x534C4F54, 0x2E200A4F, 0x76657277, 0x72697465, 0x3F000000, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x47455200, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x46524100, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x53504100, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x49544100, 0x20202020, 0x8FE35B82, 0xA482ED5D, 0x8F915B82, 0xAA5D82AB, 0x82B582C4, 0x82E082E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81482020, 0x20200000, 0x43726561, 0x74652061, 0x204E6577, 0x2046696C, 0x65000000, 0x4E45575F, 0x43524541, 0x54452047, 0x45520000, 0x4E45575F, 0x43524541, 0x54452046, 0x52410000, 0x4E45575F, 0x43524541, 0x54452053, 0x50410000, 0x4E45575F, 0x43524541, 0x54452049, 0x54410000, 0x90568B4B, 0x8DEC90AC, 0x00000000, 0x43726561, 0x74652061, 0x206E6577, 0x2066696C, 0x652E0000, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F204745, 0x52000000, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F204652, 0x41000000, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F205350, 0x41000000, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F204954, 0x41000000, 0x90568B4B, 0x82C98374, 0x83408343, 0x838B82F0, 0x8DEC90AC, 0x82B582DC, 0x82B78142, 0x00000000, 0x43616E6E, 0x6F742063, 0x72656174, 0x65206120, 0x6E657720, 0x66696C65, 0x2E000000, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F4E5420, 0x47455200, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F4E5420, 0x46524100, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F4E5420, 0x53504100, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F4E5420, 0x49544100, 0x90568B4B, 0x82C98374, 0x83408343, 0x838B82F0, 0x8DEC90AC, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x00000000, 0x25642062, 0x6C6F636B, 0x28732920, 0x6F662073, 0x70616365, 0x20617661, 0x696C6162, 0x6C652E00, 0x46524545, 0x5F535041, 0x43452047, 0x45520000, 0x46524545, 0x5F535041, 0x43452046, 0x52410000, 0x46524545, 0x5F535041, 0x43452053, 0x50410000, 0x46524545, 0x5F535041, 0x43452049, 0x54410000, 0x8BF382AB, 0x976597CA, 0x20256483, 0x75838D83, 0x62834E00, 0x25642062, 0x6C6F636B, 0x28732920, 0x6E656564, 0x65642E20, 0x28256420, 0x66726565, 0x20626C6F, 0x636B2873, 0x29206176, 0x61696C61, 0x626C6529, 0x00000000, 0x46524545, 0x5F4E4545, 0x445F5350, 0x41434520, 0x47455200, 0x46524545, 0x5F4E4545, 0x445F5350, 0x41434520, 0x46524100, 0x46524545, 0x5F4E4545, 0x445F5350, 0x41434520, 0x53504100, 0x46524545, 0x5F4E4545, 0x445F5350, 0x41434520, 0x49544100, 0x25648375, 0x838D8362, 0x834E954B, 0x9776288B, 0xF382AB97, 0x6597CA20, 0x25648375, 0x838D8362, 0x834E2900, 0x436F7272, 0x75707420, 0x46696C65, 0x00000000, 0x42524F4B, 0x454E5F46, 0x494C4520, 0x47455200, 0x42524F4B, 0x454E5F46, 0x494C4520, 0x46524100, 0x42524F4B, 0x454E5F46, 0x494C4520, 0x53504100, 0x42524F4B, 0x454E5F46, 0x494C4520, 0x49544100, 0x89F382EA, 0x82BD8374, 0x83408343, 0x838B0000, 0x54686973, 0x2066696C, 0x65206973, 0x20636F72, 0x72757074, 0x65642061, 0x6E64206D, 0x75737420, 0x62652064, 0x656C6574, 0x65642E00, 0x42524F4B, 0x454E5F46, 0x494C455F, 0x44454C20, 0x47455200, 0x42524F4B, 0x454E5F46, 0x494C455F, 0x44454C20, 0x46524100, 0x42524F4B, 0x454E5F46, 0x494C455F, 0x44454C20, 0x53504100, 0x42524F4B, 0x454E5F46, 0x494C455F, 0x44454C20, 0x49544100, 0x82B182CC, 0x83748340, 0x8343838B, 0x82CD89F3, 0x82EA82C4, 0x82A282E9, 0x82CC82C5, 0x8FC182B7, 0x954B9776, 0x82AA82A0, 0x82E882DC, 0x82B78142, 0x00000000, (u32)lbl_8_data_778__fzgx_offset_0, (u32)lbl_8_data_7C8__fzgx_offset_0, (u32)lbl_8_data_7D4__fzgx_offset_0, (u32)lbl_8_data_7E0__fzgx_offset_0, (u32)lbl_8_data_7EC__fzgx_offset_0, (u32)lbl_8_data_7F8__fzgx_offset_0, (u32)lbl_8_data_864__fzgx_offset_0, (u32)lbl_8_data_8A8__fzgx_offset_0, (u32)lbl_8_data_8B8__fzgx_offset_0, (u32)lbl_8_data_8C8__fzgx_offset_0, (u32)lbl_8_data_8D8__fzgx_offset_0, (u32)lbl_8_data_8E8__fzgx_offset_0, (u32)lbl_8_data_948__fzgx_offset_0, (u32)lbl_8_data_9B8__fzgx_offset_0, (u32)lbl_8_data_9C4__fzgx_offset_0, (u32)lbl_8_data_9D0__fzgx_offset_0, (u32)lbl_8_data_9DC__fzgx_offset_0, (u32)lbl_8_data_9E8__fzgx_offset_0, (u32)lbl_8_data_AD0__fzgx_offset_0, (u32)lbl_8_data_B28__fzgx_offset_0, (u32)lbl_8_data_B34__fzgx_offset_0, (u32)lbl_8_data_B40__fzgx_offset_0, (u32)lbl_8_data_B4C__fzgx_offset_0, (u32)lbl_8_data_B58__fzgx_offset_0, (u32)lbl_8_data_BC0__fzgx_offset_0, (u32)lbl_8_data_BF4__fzgx_offset_0, (u32)lbl_8_data_C0C__fzgx_offset_0, (u32)lbl_8_data_C24__fzgx_offset_0, (u32)lbl_8_data_C3C__fzgx_offset_0, (u32)lbl_8_data_C54__fzgx_offset_0, (u32)lbl_8_data_C7C__fzgx_offset_0, (u32)lbl_8_data_CAC__fzgx_offset_0, (u32)lbl_8_data_CC4__fzgx_offset_0, (u32)lbl_8_data_CDC__fzgx_offset_0, (u32)lbl_8_data_CF4__fzgx_offset_0, (u32)lbl_8_data_D0C__fzgx_offset_0, (u32)lbl_8_data_D34__fzgx_offset_0, (u32)lbl_8_data_D64__fzgx_offset_0, (u32)lbl_8_data_D7C__fzgx_offset_0, (u32)lbl_8_data_D94__fzgx_offset_0, (u32)lbl_8_data_DAC__fzgx_offset_0, (u32)lbl_8_data_DC4__fzgx_offset_0, (u32)lbl_8_data_DF4__fzgx_offset_0, (u32)lbl_8_data_E24__fzgx_offset_0, (u32)lbl_8_data_E40__fzgx_offset_0, (u32)lbl_8_data_E5C__fzgx_offset_0, (u32)lbl_8_data_E78__fzgx_offset_0, (u32)lbl_8_data_E94__fzgx_offset_0, (u32)lbl_8_data_EBC__fzgx_offset_0, (u32)lbl_8_data_EF0__fzgx_offset_0, (u32)lbl_8_data_F0C__fzgx_offset_0, (u32)lbl_8_data_F28__fzgx_offset_0, (u32)lbl_8_data_F44__fzgx_offset_0, (u32)lbl_8_data_F60__fzgx_offset_0, (u32)lbl_8_data_F8C__fzgx_offset_0, (u32)lbl_8_data_FD0__fzgx_offset_0, (u32)lbl_8_data_FF0__fzgx_offset_0, (u32)lbl_8_data_1010__fzgx_offset_0, (u32)lbl_8_data_1030__fzgx_offset_0, (u32)lbl_8_data_1050__fzgx_offset_0, (u32)lbl_8_data_1094__fzgx_offset_0, (u32)lbl_8_data_10D8__fzgx_offset_0, (u32)lbl_8_data_10F8__fzgx_offset_0, (u32)lbl_8_data_1118__fzgx_offset_0, (u32)lbl_8_data_1138__fzgx_offset_0, (u32)lbl_8_data_1158__fzgx_offset_0, (u32)lbl_8_data_119C__fzgx_offset_0, (u32)lbl_8_data_11CC__fzgx_offset_0, (u32)lbl_8_data_11EC__fzgx_offset_0, (u32)lbl_8_data_120C__fzgx_offset_0, (u32)lbl_8_data_122C__fzgx_offset_0, (u32)lbl_8_data_124C__fzgx_offset_0, (u32)lbl_8_data_127C__fzgx_offset_0, (u32)lbl_8_data_12C0__fzgx_offset_0, (u32)lbl_8_data_12E0__fzgx_offset_0, (u32)lbl_8_data_1300__fzgx_offset_0, (u32)lbl_8_data_1320__fzgx_offset_0, (u32)lbl_8_data_1340__fzgx_offset_0, (u32)lbl_8_data_1384__fzgx_offset_0, (u32)lbl_8_data_13C8__fzgx_offset_0, (u32)lbl_8_data_13E8__fzgx_offset_0, (u32)lbl_8_data_1408__fzgx_offset_0, (u32)lbl_8_data_1428__fzgx_offset_0, (u32)lbl_8_data_1448__fzgx_offset_0, (u32)lbl_8_data_148C__fzgx_offset_0, (u32)lbl_8_data_14AC__fzgx_offset_0, (u32)lbl_8_data_14BC__fzgx_offset_0, (u32)lbl_8_data_14CC__fzgx_offset_0, (u32)lbl_8_data_14DC__fzgx_offset_0, (u32)lbl_8_data_14EC__fzgx_offset_0, (u32)lbl_8_data_1508__fzgx_offset_0, (u32)lbl_8_data_151C__fzgx_offset_0, (u32)lbl_8_data_152C__fzgx_offset_0, (u32)lbl_8_data_153C__fzgx_offset_0, (u32)lbl_8_data_154C__fzgx_offset_0, (u32)lbl_8_data_155C__fzgx_offset_0, (u32)lbl_8_data_156C__fzgx_offset_0, (u32)lbl_8_data_15A0__fzgx_offset_0, (u32)lbl_8_data_15B8__fzgx_offset_0, (u32)lbl_8_data_15D0__fzgx_offset_0, (u32)lbl_8_data_15E8__fzgx_offset_0, (u32)lbl_8_data_1600__fzgx_offset_0, (u32)lbl_8_data_1634__fzgx_offset_0, (u32)lbl_8_data_1668__fzgx_offset_0, (u32)lbl_8_data_1680__fzgx_offset_0, (u32)lbl_8_data_1698__fzgx_offset_0, (u32)lbl_8_data_16B0__fzgx_offset_0, (u32)lbl_8_data_16C8__fzgx_offset_0, (u32)lbl_8_data_16FC__fzgx_offset_0, (u32)lbl_8_data_171C__fzgx_offset_0, (u32)lbl_8_data_1734__fzgx_offset_0, (u32)lbl_8_data_174C__fzgx_offset_0, (u32)lbl_8_data_1764__fzgx_offset_0, (u32)lbl_8_data_177C__fzgx_offset_0, (u32)lbl_8_data_17A0__fzgx_offset_0, (u32)lbl_8_data_17D4__fzgx_offset_0, (u32)lbl_8_data_17F0__fzgx_offset_0, (u32)lbl_8_data_180C__fzgx_offset_0, (u32)lbl_8_data_1828__fzgx_offset_0, (u32)lbl_8_data_1844__fzgx_offset_0, (u32)lbl_8_data_1874__fzgx_offset_0, (u32)lbl_8_data_18AC__fzgx_offset_0, (u32)lbl_8_data_18C8__fzgx_offset_0, (u32)lbl_8_data_18E4__fzgx_offset_0, (u32)lbl_8_data_1900__fzgx_offset_0, (u32)lbl_8_data_191C__fzgx_offset_0, (u32)lbl_8_data_1954__fzgx_offset_0, (u32)lbl_8_data_1994__fzgx_offset_0, (u32)lbl_8_data_19B4__fzgx_offset_0, (u32)lbl_8_data_19D4__fzgx_offset_0, (u32)lbl_8_data_19F4__fzgx_offset_0, (u32)lbl_8_data_1A14__fzgx_offset_0, (u32)lbl_8_data_1A54__fzgx_offset_0, (u32)lbl_8_data_1A90__fzgx_offset_0, (u32)lbl_8_data_1AB0__fzgx_offset_0, (u32)lbl_8_data_1AD0__fzgx_offset_0, (u32)lbl_8_data_1AF0__fzgx_offset_0, (u32)lbl_8_data_1B10__fzgx_offset_0, (u32)lbl_8_data_1B50__fzgx_offset_0, (u32)lbl_8_data_1B8C__fzgx_offset_0, (u32)lbl_8_data_1BAC__fzgx_offset_0, (u32)lbl_8_data_1BCC__fzgx_offset_0, (u32)lbl_8_data_1BEC__fzgx_offset_0, (u32)lbl_8_data_1C0C__fzgx_offset_0, (u32)lbl_8_data_1C50__fzgx_offset_0, (u32)lbl_8_data_1C90__fzgx_offset_0, (u32)lbl_8_data_1CB0__fzgx_offset_0, (u32)lbl_8_data_1CD0__fzgx_offset_0, (u32)lbl_8_data_1CF0__fzgx_offset_0, (u32)lbl_8_data_1D10__fzgx_offset_0, (u32)lbl_8_data_1D4C__fzgx_offset_0, (u32)lbl_8_data_1D8C__fzgx_offset_0, (u32)lbl_8_data_1DAC__fzgx_offset_0, (u32)lbl_8_data_1DCC__fzgx_offset_0, (u32)lbl_8_data_1DEC__fzgx_offset_0, (u32)lbl_8_data_1E0C__fzgx_offset_0, (u32)lbl_8_data_1E4C__fzgx_offset_0, (u32)lbl_8_data_1E78__fzgx_offset_0, (u32)lbl_8_data_1E90__fzgx_offset_0, (u32)lbl_8_data_1EA8__fzgx_offset_0, (u32)lbl_8_data_1EC0__fzgx_offset_0, (u32)lbl_8_data_1ED8__fzgx_offset_0, (u32)lbl_8_data_1F04__fzgx_offset_0, (u32)lbl_8_data_1F60__fzgx_offset_0, (u32)lbl_8_data_1F78__fzgx_offset_0, (u32)lbl_8_data_1F90__fzgx_offset_0, (u32)lbl_8_data_1FA8__fzgx_offset_0, (u32)lbl_8_data_1FC0__fzgx_offset_0, (u32)lbl_8_data_202C__fzgx_offset_0, (u32)lbl_8_data_205C__fzgx_offset_0, (u32)lbl_8_data_206C__fzgx_offset_0, (u32)lbl_8_data_207C__fzgx_offset_0, (u32)lbl_8_data_208C__fzgx_offset_0, (u32)lbl_8_data_209C__fzgx_offset_0, (u32)lbl_8_data_20D4__fzgx_offset_0, (u32)lbl_8_data_2128__fzgx_offset_0, (u32)lbl_8_data_213C__fzgx_offset_0, (u32)lbl_8_data_2150__fzgx_offset_0, (u32)lbl_8_data_2164__fzgx_offset_0, (u32)lbl_8_data_2178__fzgx_offset_0, (u32)lbl_8_data_21C0__fzgx_offset_0, (u32)lbl_8_data_2204__fzgx_offset_0, (u32)lbl_8_data_2214__fzgx_offset_0, (u32)lbl_8_data_2224__fzgx_offset_0, (u32)lbl_8_data_2234__fzgx_offset_0, (u32)lbl_8_data_2244__fzgx_offset_0, (u32)lbl_8_data_2288__fzgx_offset_0, (u32)lbl_8_data_22C0__fzgx_offset_0, (u32)lbl_8_data_22D4__fzgx_offset_0, (u32)lbl_8_data_22E8__fzgx_offset_0, (u32)lbl_8_data_22FC__fzgx_offset_0, (u32)lbl_8_data_2310__fzgx_offset_0, (u32)lbl_8_data_2354__fzgx_offset_0, (u32)lbl_8_data_238C__fzgx_offset_0, (u32)lbl_8_data_239C__fzgx_offset_0, (u32)lbl_8_data_23AC__fzgx_offset_0, (u32)lbl_8_data_23BC__fzgx_offset_0, (u32)lbl_8_data_23CC__fzgx_offset_0, (u32)lbl_8_data_2410__fzgx_offset_0, (u32)lbl_8_data_2470__fzgx_offset_0, (u32)lbl_8_data_2480__fzgx_offset_0, (u32)lbl_8_data_2490__fzgx_offset_0, (u32)lbl_8_data_24A0__fzgx_offset_0, (u32)lbl_8_data_24B0__fzgx_offset_0, (u32)lbl_8_data_2508__fzgx_offset_0, (u32)lbl_8_data_2544__fzgx_offset_0, (u32)lbl_8_data_2554__fzgx_offset_0, (u32)lbl_8_data_2564__fzgx_offset_0, (u32)lbl_8_data_2574__fzgx_offset_0, (u32)lbl_8_data_2584__fzgx_offset_0, (u32)lbl_8_data_25DC__fzgx_offset_0, (u32)lbl_8_data_263C__fzgx_offset_0, (u32)lbl_8_data_2650__fzgx_offset_0, (u32)lbl_8_data_2664__fzgx_offset_0, (u32)lbl_8_data_2678__fzgx_offset_0, (u32)lbl_8_data_268C__fzgx_offset_0, (u32)lbl_8_data_26F8__fzgx_offset_0, (u32)lbl_8_data_2720__fzgx_offset_0, (u32)lbl_8_data_2734__fzgx_offset_0, (u32)lbl_8_data_2748__fzgx_offset_0, (u32)lbl_8_data_275C__fzgx_offset_0, (u32)lbl_8_data_2770__fzgx_offset_0, (u32)lbl_8_data_27AC__fzgx_offset_0, (u32)lbl_8_data_27B4__fzgx_offset_0, (u32)lbl_8_data_27C0__fzgx_offset_0, (u32)lbl_8_data_27CC__fzgx_offset_0, (u32)lbl_8_data_27D8__fzgx_offset_0, (u32)lbl_8_data_27E4__fzgx_offset_0, (u32)lbl_8_data_27F0__fzgx_offset_0, (u32)lbl_8_data_27F8__fzgx_offset_0, (u32)lbl_8_data_2804__fzgx_offset_0, (u32)lbl_8_data_2810__fzgx_offset_0, (u32)lbl_8_data_281C__fzgx_offset_0, (u32)lbl_8_data_2828__fzgx_offset_0, (u32)lbl_8_data_2834__fzgx_offset_0, (u32)lbl_8_data_2838__fzgx_offset_0, (u32)lbl_8_data_2840__fzgx_offset_0, (u32)lbl_8_data_2848__fzgx_offset_0, (u32)lbl_8_data_2850__fzgx_offset_0, (u32)lbl_8_data_2858__fzgx_offset_0, (u32)lbl_8_data_2860__fzgx_offset_0, (u32)lbl_8_data_2864__fzgx_offset_0, (u32)lbl_8_data_286C__fzgx_offset_0, (u32)lbl_8_data_2874__fzgx_offset_0, (u32)lbl_8_data_287C__fzgx_offset_0, (u32)lbl_8_data_2884__fzgx_offset_0, (u32)lbl_8_data_288C__fzgx_offset_0, (u32)lbl_8_data_28C8__fzgx_offset_0, (u32)lbl_8_data_28DC__fzgx_offset_0, (u32)lbl_8_data_28F0__fzgx_offset_0, (u32)lbl_8_data_2904__fzgx_offset_0, (u32)lbl_8_data_2918__fzgx_offset_0, (u32)lbl_8_data_2958__fzgx_offset_0, (u32)lbl_8_data_2AE8__fzgx_offset_0, (u32)lbl_8_data_2AF4__fzgx_offset_0, (u32)lbl_8_data_2B00__fzgx_offset_0, (u32)lbl_8_data_2B0C__fzgx_offset_0, (u32)lbl_8_data_2B18__fzgx_offset_0, (u32)lbl_8_data_2D68__fzgx_offset_0, (u32)lbl_8_data_2E4C__fzgx_offset_0, (u32)lbl_8_data_2E58__fzgx_offset_0, (u32)lbl_8_data_2E64__fzgx_offset_0, (u32)lbl_8_data_2E70__fzgx_offset_0, (u32)lbl_8_data_2E7C__fzgx_offset_0, (u32)lbl_8_data_2FD8__fzgx_offset_0, (u32)lbl_8_data_3168__fzgx_offset_0, (u32)lbl_8_data_3178__fzgx_offset_0, (u32)lbl_8_data_3188__fzgx_offset_0, (u32)lbl_8_data_3198__fzgx_offset_0, (u32)lbl_8_data_31A8__fzgx_offset_0, (u32)lbl_8_data_33F8__fzgx_offset_0, (u32)lbl_8_data_34DC__fzgx_offset_0, (u32)lbl_8_data_34F0__fzgx_offset_0, (u32)lbl_8_data_3504__fzgx_offset_0, (u32)lbl_8_data_3518__fzgx_offset_0, (u32)lbl_8_data_352C__fzgx_offset_0, (u32)lbl_8_data_3688__fzgx_offset_0, (u32)lbl_8_data_36DC__fzgx_offset_0, (u32)lbl_8_data_36F0__fzgx_offset_0, (u32)lbl_8_data_3704__fzgx_offset_0, (u32)lbl_8_data_3718__fzgx_offset_0, (u32)lbl_8_data_372C__fzgx_offset_0, (u32)lbl_8_data_378C__fzgx_offset_0, (u32)lbl_8_data_37B4__fzgx_offset_0, (u32)lbl_8_data_37CC__fzgx_offset_0, (u32)lbl_8_data_37E4__fzgx_offset_0, (u32)lbl_8_data_37FC__fzgx_offset_0, (u32)lbl_8_data_3814__fzgx_offset_0, (u32)lbl_8_data_3850__fzgx_offset_0, (u32)lbl_8_data_3884__fzgx_offset_0, (u32)lbl_8_data_3894__fzgx_offset_0, (u32)lbl_8_data_38A4__fzgx_offset_0, (u32)lbl_8_data_38B4__fzgx_offset_0, (u32)lbl_8_data_38C4__fzgx_offset_0, (u32)lbl_8_data_3904__fzgx_offset_0, (u32)lbl_8_data_391C__fzgx_offset_0, (u32)lbl_8_data_3930__fzgx_offset_0, (u32)lbl_8_data_3944__fzgx_offset_0, (u32)lbl_8_data_3958__fzgx_offset_0, (u32)lbl_8_data_396C__fzgx_offset_0, (u32)lbl_8_data_3988__fzgx_offset_0, (u32)lbl_8_data_3990__fzgx_offset_0, (u32)lbl_8_data_399C__fzgx_offset_0, (u32)lbl_8_data_39A8__fzgx_offset_0, (u32)lbl_8_data_39B4__fzgx_offset_0, (u32)lbl_8_data_39C0__fzgx_offset_0, (u32)lbl_8_data_39CC__fzgx_offset_0, (u32)lbl_8_data_3A04__fzgx_offset_0, (u32)lbl_8_data_3A14__fzgx_offset_0, (u32)lbl_8_data_3A24__fzgx_offset_0, (u32)lbl_8_data_3A34__fzgx_offset_0, (u32)lbl_8_data_3A44__fzgx_offset_0, (u32)lbl_8_data_3A88__fzgx_offset_0, (u32)lbl_8_data_3AB4__fzgx_offset_0, (u32)lbl_8_data_3AC4__fzgx_offset_0, (u32)lbl_8_data_3AD4__fzgx_offset_0, (u32)lbl_8_data_3AE4__fzgx_offset_0, (u32)lbl_8_data_3AF4__fzgx_offset_0, (u32)lbl_8_data_3B2C__fzgx_offset_0, (u32)lbl_8_data_3B6C__fzgx_offset_0, (u32)lbl_8_data_3B7C__fzgx_offset_0, (u32)lbl_8_data_3B8C__fzgx_offset_0, (u32)lbl_8_data_3B9C__fzgx_offset_0, (u32)lbl_8_data_3BAC__fzgx_offset_0, (u32)lbl_8_data_3BF0__fzgx_offset_0, (u32)lbl_8_data_3C48__fzgx_offset_0, (u32)lbl_8_data_3C58__fzgx_offset_0, (u32)lbl_8_data_3C68__fzgx_offset_0, (u32)lbl_8_data_3C78__fzgx_offset_0, (u32)lbl_8_data_3C88__fzgx_offset_0, (u32)lbl_8_data_3CCC__fzgx_offset_0, (u32)lbl_8_data_3D14__fzgx_offset_0, (u32)lbl_8_data_3D20__fzgx_offset_0, (u32)lbl_8_data_3D2C__fzgx_offset_0, (u32)lbl_8_data_3D38__fzgx_offset_0, (u32)lbl_8_data_3D44__fzgx_offset_0, (u32)lbl_8_data_3D98__fzgx_offset_0, (u32)lbl_8_data_3DCC__fzgx_offset_0, (u32)lbl_8_data_3DD8__fzgx_offset_0, (u32)lbl_8_data_3DE4__fzgx_offset_0, (u32)lbl_8_data_3DF0__fzgx_offset_0, (u32)lbl_8_data_3DFC__fzgx_offset_0, (u32)lbl_8_data_3E30__fzgx_offset_0, (u32)lbl_8_data_3E68__fzgx_offset_0, (u32)lbl_8_data_3E74__fzgx_offset_0, (u32)lbl_8_data_3E80__fzgx_offset_0, (u32)lbl_8_data_3E8C__fzgx_offset_0, (u32)lbl_8_data_3E98__fzgx_offset_0, (u32)lbl_8_data_3ECC__fzgx_offset_0, (u32)lbl_8_data_3F00__fzgx_offset_0, (u32)lbl_8_data_3F0C__fzgx_offset_0, (u32)lbl_8_data_3F18__fzgx_offset_0, (u32)lbl_8_data_3F24__fzgx_offset_0, (u32)lbl_8_data_3F30__fzgx_offset_0, (u32)lbl_8_data_3F64__fzgx_offset_0, (u32)lbl_8_data_3F9C__fzgx_offset_0, (u32)lbl_8_data_3FA8__fzgx_offset_0, (u32)lbl_8_data_3FB4__fzgx_offset_0, (u32)lbl_8_data_3FC0__fzgx_offset_0, (u32)lbl_8_data_3FCC__fzgx_offset_0, (u32)lbl_8_data_4000__fzgx_offset_0, (u32)lbl_8_data_403C__fzgx_offset_0, (u32)lbl_8_data_404C__fzgx_offset_0, (u32)lbl_8_data_405C__fzgx_offset_0, (u32)lbl_8_data_406C__fzgx_offset_0, (u32)lbl_8_data_407C__fzgx_offset_0, (u32)lbl_8_data_40A4__fzgx_offset_0, (u32)lbl_8_data_40D4__fzgx_offset_0, (u32)lbl_8_data_40E8__fzgx_offset_0, (u32)lbl_8_data_40FC__fzgx_offset_0, (u32)lbl_8_data_4110__fzgx_offset_0, (u32)lbl_8_data_4124__fzgx_offset_0, (u32)lbl_8_data_4160__fzgx_offset_0, (u32)lbl_8_data_419C__fzgx_offset_0, (u32)lbl_8_data_41AC__fzgx_offset_0, (u32)lbl_8_data_41BC__fzgx_offset_0, (u32)lbl_8_data_41CC__fzgx_offset_0, (u32)lbl_8_data_41DC__fzgx_offset_0, (u32)lbl_8_data_4218__fzgx_offset_0, (u32)lbl_8_data_4240__fzgx_offset_0, (u32)lbl_8_data_4250__fzgx_offset_0, (u32)lbl_8_data_4260__fzgx_offset_0, (u32)lbl_8_data_4270__fzgx_offset_0, (u32)lbl_8_data_4280__fzgx_offset_0, (u32)lbl_8_data_42C4__fzgx_offset_0, (u32)lbl_8_data_4304__fzgx_offset_0, (u32)lbl_8_data_4314__fzgx_offset_0, (u32)lbl_8_data_4324__fzgx_offset_0, (u32)lbl_8_data_4334__fzgx_offset_0, (u32)lbl_8_data_4344__fzgx_offset_0, (u32)lbl_8_data_4384__fzgx_offset_0, (u32)lbl_8_data_43BC__fzgx_offset_0, (u32)lbl_8_data_43CC__fzgx_offset_0, (u32)lbl_8_data_43DC__fzgx_offset_0, (u32)lbl_8_data_43EC__fzgx_offset_0, (u32)lbl_8_data_43FC__fzgx_offset_0, (u32)lbl_8_data_4424__fzgx_offset_0, (u32)lbl_8_data_4434__fzgx_offset_0, (u32)lbl_8_data_4444__fzgx_offset_0, (u32)lbl_8_data_4454__fzgx_offset_0, (u32)lbl_8_data_4464__fzgx_offset_0, (u32)lbl_8_data_4474__fzgx_offset_0, (u32)lbl_8_data_4484__fzgx_offset_0, (u32)lbl_8_data_4490__fzgx_offset_0, (u32)lbl_8_data_44A0__fzgx_offset_0, (u32)lbl_8_data_44B0__fzgx_offset_0, (u32)lbl_8_data_44C0__fzgx_offset_0, (u32)lbl_8_data_44D0__fzgx_offset_0, (u32)lbl_8_data_44DC__fzgx_offset_0, (u32)lbl_8_data_44EC__fzgx_offset_0, (u32)lbl_8_data_44FC__fzgx_offset_0, (u32)lbl_8_data_450C__fzgx_offset_0, (u32)lbl_8_data_451C__fzgx_offset_0, (u32)lbl_8_data_452C__fzgx_offset_0, (u32)lbl_8_data_453C__fzgx_offset_0, (u32)lbl_8_data_454C__fzgx_offset_0, (u32)lbl_8_data_455C__fzgx_offset_0, (u32)lbl_8_data_456C__fzgx_offset_0, (u32)lbl_8_data_457C__fzgx_offset_0, (u32)lbl_8_data_458C__fzgx_offset_0, (u32)lbl_8_data_459C__fzgx_offset_0, (u32)lbl_8_data_45F0__fzgx_offset_0, (u32)lbl_8_data_45FC__fzgx_offset_0, (u32)lbl_8_data_4608__fzgx_offset_0, (u32)lbl_8_data_4614__fzgx_offset_0, (u32)lbl_8_data_4620__fzgx_offset_0, (u32)lbl_8_data_4688__fzgx_offset_0, (u32)lbl_8_data_46DC__fzgx_offset_0, (u32)lbl_8_data_46E8__fzgx_offset_0, (u32)lbl_8_data_46F4__fzgx_offset_0, (u32)lbl_8_data_4700__fzgx_offset_0, (u32)lbl_8_data_470C__fzgx_offset_0, (u32)lbl_8_data_4774__fzgx_offset_0, (u32)lbl_8_data_47A0__fzgx_offset_0, (u32)lbl_8_data_47B0__fzgx_offset_0, (u32)lbl_8_data_47C0__fzgx_offset_0, (u32)lbl_8_data_47D0__fzgx_offset_0, (u32)lbl_8_data_47E0__fzgx_offset_0, (u32)lbl_8_data_480C__fzgx_offset_0, (u32)lbl_8_data_483C__fzgx_offset_0, (u32)lbl_8_data_484C__fzgx_offset_0, (u32)lbl_8_data_485C__fzgx_offset_0, (u32)lbl_8_data_486C__fzgx_offset_0, (u32)lbl_8_data_487C__fzgx_offset_0, (u32)lbl_8_data_48B0__fzgx_offset_0, (u32)lbl_8_data_4948__fzgx_offset_0, (u32)lbl_8_data_4960__fzgx_offset_0, (u32)lbl_8_data_4978__fzgx_offset_0, (u32)lbl_8_data_4990__fzgx_offset_0, (u32)lbl_8_data_49A8__fzgx_offset_0, (u32)lbl_8_data_4A34__fzgx_offset_0, (u32)lbl_8_data_4A78__fzgx_offset_0, (u32)lbl_8_data_4A90__fzgx_offset_0, (u32)lbl_8_data_4AA8__fzgx_offset_0, (u32)lbl_8_data_4AC0__fzgx_offset_0, (u32)lbl_8_data_4AD8__fzgx_offset_0, (u32)lbl_8_data_4B28__fzgx_offset_0, (u32)lbl_8_data_4B9C__fzgx_offset_0, (u32)lbl_8_data_4BA0__fzgx_offset_0, (u32)lbl_8_data_4BA4__fzgx_offset_0, (u32)lbl_8_data_4BA8__fzgx_offset_0, (u32)lbl_8_data_4BAC__fzgx_offset_0, (u32)lbl_8_data_4C68__fzgx_offset_0, (u32)lbl_8_data_4CE0__fzgx_offset_0, (u32)lbl_8_data_4CE4__fzgx_offset_0, (u32)lbl_8_data_4CE8__fzgx_offset_0, (u32)lbl_8_data_4CEC__fzgx_offset_0, (u32)lbl_8_data_4CF0__fzgx_offset_0, (u32)lbl_8_data_4D4C__fzgx_offset_0, (u32)lbl_8_data_4D54__fzgx_offset_0, (u32)lbl_8_data_4D60__fzgx_offset_0, (u32)lbl_8_data_4D6C__fzgx_offset_0, (u32)lbl_8_data_4D78__fzgx_offset_0, (u32)lbl_8_data_4D84__fzgx_offset_0, (u32)lbl_8_data_4D8C__fzgx_offset_0, (u32)lbl_8_data_4D94__fzgx_offset_0, (u32)lbl_8_data_4DA0__fzgx_offset_0, (u32)lbl_8_data_4DAC__fzgx_offset_0, (u32)lbl_8_data_4DB8__fzgx_offset_0, (u32)lbl_8_data_4DC4__fzgx_offset_0, (u32)lbl_8_data_4DCC__fzgx_offset_0, (u32)lbl_8_data_4DD4__fzgx_offset_0, (u32)lbl_8_data_4DE0__fzgx_offset_0, (u32)lbl_8_data_4DEC__fzgx_offset_0, (u32)lbl_8_data_4DF8__fzgx_offset_0, (u32)lbl_8_data_4E04__fzgx_offset_0, (u32)lbl_8_data_4E10__fzgx_offset_0, (u32)lbl_8_data_4E18__fzgx_offset_0, (u32)lbl_8_data_4E24__fzgx_offset_0, (u32)lbl_8_data_4E30__fzgx_offset_0, (u32)lbl_8_data_4E3C__fzgx_offset_0, (u32)lbl_8_data_4E48__fzgx_offset_0, (u32)lbl_8_data_4E54__fzgx_offset_0, (u32)lbl_8_data_4E5C__fzgx_offset_0, (u32)lbl_8_data_4E68__fzgx_offset_0, (u32)lbl_8_data_4E74__fzgx_offset_0, (u32)lbl_8_data_4E80__fzgx_offset_0, (u32)lbl_8_data_4E8C__fzgx_offset_0, (u32)lbl_8_data_4E98__fzgx_offset_0, (u32)lbl_8_data_4EA0__fzgx_offset_0, (u32)lbl_8_data_4EAC__fzgx_offset_0, (u32)lbl_8_data_4EB8__fzgx_offset_0, (u32)lbl_8_data_4EC4__fzgx_offset_0, (u32)lbl_8_data_4ED0__fzgx_offset_0, (u32)lbl_8_data_4EDC__fzgx_offset_0, (u32)lbl_8_data_4EE4__fzgx_offset_0, (u32)lbl_8_data_4EF0__fzgx_offset_0, (u32)lbl_8_data_4EFC__fzgx_offset_0, (u32)lbl_8_data_4F08__fzgx_offset_0, (u32)lbl_8_data_4F14__fzgx_offset_0, (u32)lbl_8_data_4F20__fzgx_offset_0, (u32)lbl_8_data_4F28__fzgx_offset_0, (u32)lbl_8_data_4F34__fzgx_offset_0, (u32)lbl_8_data_4F40__fzgx_offset_0, (u32)lbl_8_data_4F4C__fzgx_offset_0, (u32)lbl_8_data_4F58__fzgx_offset_0, (u32)lbl_8_data_4F60__fzgx_offset_0, (u32)lbl_8_data_50A4__fzgx_offset_0, (u32)lbl_8_data_50A8__fzgx_offset_0, (u32)lbl_8_data_50AC__fzgx_offset_0, (u32)lbl_8_data_50B0__fzgx_offset_0, (u32)lbl_8_data_50B4__fzgx_offset_0, (u32)lbl_8_data_5224__fzgx_offset_0, (u32)lbl_8_data_5268__fzgx_offset_0, (u32)lbl_8_data_526C__fzgx_offset_0, (u32)lbl_8_data_5270__fzgx_offset_0, (u32)lbl_8_data_5274__fzgx_offset_0, (u32)lbl_8_data_5278__fzgx_offset_0, (u32)lbl_8_data_52BC__fzgx_offset_0, (u32)lbl_8_data_5300__fzgx_offset_0, (u32)lbl_8_data_5304__fzgx_offset_0, (u32)lbl_8_data_5308__fzgx_offset_0, (u32)lbl_8_data_530C__fzgx_offset_0, (u32)lbl_8_data_5310__fzgx_offset_0, (u32)lbl_8_data_5358__fzgx_offset_0, (u32)lbl_8_data_5390__fzgx_offset_0, (u32)lbl_8_data_5394__fzgx_offset_0, (u32)lbl_8_data_5398__fzgx_offset_0, (u32)lbl_8_data_539C__fzgx_offset_0, (u32)lbl_8_data_53A0__fzgx_offset_0, (u32)lbl_8_data_53F8__fzgx_offset_0, (u32)lbl_8_data_5400__fzgx_offset_0, (u32)lbl_8_data_5404__fzgx_offset_0, (u32)lbl_8_data_5408__fzgx_offset_0, (u32)lbl_8_data_540C__fzgx_offset_0, (u32)lbl_8_data_5410__fzgx_offset_0, (u32)lbl_8_data_5418__fzgx_offset_0, (u32)lbl_8_data_5420__fzgx_offset_0, (u32)lbl_8_data_5424__fzgx_offset_0, (u32)lbl_8_data_5428__fzgx_offset_0, (u32)lbl_8_data_542C__fzgx_offset_0, (u32)lbl_8_data_5430__fzgx_offset_0, (u32)lbl_8_data_5438__fzgx_offset_0, (u32)lbl_8_data_5440__fzgx_offset_0, (u32)lbl_8_data_5444__fzgx_offset_0, (u32)lbl_8_data_5448__fzgx_offset_0, (u32)lbl_8_data_544C__fzgx_offset_0, (u32)lbl_8_data_5450__fzgx_offset_0, (u32)lbl_8_data_5458__fzgx_offset_0, (u32)lbl_8_data_5460__fzgx_offset_0, (u32)lbl_8_data_5464__fzgx_offset_0, (u32)lbl_8_data_5468__fzgx_offset_0, (u32)lbl_8_data_546C__fzgx_offset_0, (u32)lbl_8_data_5470__fzgx_offset_0, (u32)lbl_8_data_5478__fzgx_offset_0, (u32)lbl_8_data_54AC__fzgx_offset_0, (u32)lbl_8_data_54B0__fzgx_offset_0, (u32)lbl_8_data_54B4__fzgx_offset_0, (u32)lbl_8_data_54B8__fzgx_offset_0, (u32)lbl_8_data_54BC__fzgx_offset_0, (u32)lbl_8_data_5510__fzgx_offset_0, (u32)lbl_8_data_5564__fzgx_offset_0, (u32)lbl_8_data_5568__fzgx_offset_0, (u32)lbl_8_data_556C__fzgx_offset_0, (u32)lbl_8_data_5570__fzgx_offset_0, (u32)lbl_8_data_5574__fzgx_offset_0, (u32)lbl_8_data_55C0__fzgx_offset_0, (u32)lbl_8_data_55C8__fzgx_offset_0, (u32)lbl_8_data_55CC__fzgx_offset_0, (u32)lbl_8_data_55D0__fzgx_offset_0, (u32)lbl_8_data_55D4__fzgx_offset_0, (u32)lbl_8_data_55D8__fzgx_offset_0, (u32)lbl_8_data_55E4__fzgx_offset_0, (u32)lbl_8_data_5624__fzgx_offset_0, (u32)lbl_8_data_5638__fzgx_offset_0, (u32)lbl_8_data_564C__fzgx_offset_0, (u32)lbl_8_data_5660__fzgx_offset_0, (u32)lbl_8_data_5674__fzgx_offset_0, (u32)lbl_8_data_5750__fzgx_offset_0, (u32)lbl_8_data_57CC__fzgx_offset_0, (u32)lbl_8_data_57DC__fzgx_offset_0, (u32)lbl_8_data_57EC__fzgx_offset_0, (u32)lbl_8_data_57FC__fzgx_offset_0, (u32)lbl_8_data_580C__fzgx_offset_0, (u32)lbl_8_data_58EC__fzgx_offset_0, (u32)lbl_8_data_595C__fzgx_offset_0, (u32)lbl_8_data_5970__fzgx_offset_0, (u32)lbl_8_data_5984__fzgx_offset_0, (u32)lbl_8_data_5998__fzgx_offset_0, (u32)lbl_8_data_59AC__fzgx_offset_0, (u32)lbl_8_data_59B0__fzgx_offset_0, (u32)lbl_8_data_5A58__fzgx_offset_0, (u32)lbl_8_data_5A68__fzgx_offset_0, (u32)lbl_8_data_5A78__fzgx_offset_0, (u32)lbl_8_data_5A88__fzgx_offset_0, (u32)lbl_8_data_5A98__fzgx_offset_0, (u32)lbl_8_data_5A9C__fzgx_offset_0, (u32)lbl_8_data_5B44__fzgx_offset_0, (u32)lbl_8_data_5B54__fzgx_offset_0, (u32)lbl_8_data_5B64__fzgx_offset_0, (u32)lbl_8_data_5B74__fzgx_offset_0, (u32)lbl_8_data_5B84__fzgx_offset_0, (u32)lbl_8_data_5C3C__fzgx_offset_0, (u32)lbl_8_data_5C64__fzgx_offset_0, (u32)lbl_8_data_5C74__fzgx_offset_0, (u32)lbl_8_data_5C84__fzgx_offset_0, (u32)lbl_8_data_5C94__fzgx_offset_0, (u32)lbl_8_data_5CA4__fzgx_offset_0, (u32)lbl_8_data_5CD4__fzgx_offset_0, (u32)lbl_8_data_5D1C__fzgx_offset_0, (u32)lbl_8_data_5D2C__fzgx_offset_0, (u32)lbl_8_data_5D3C__fzgx_offset_0, (u32)lbl_8_data_5D4C__fzgx_offset_0, (u32)lbl_8_data_5D5C__fzgx_offset_0, (u32)lbl_8_data_5DC4__fzgx_offset_0, (u32)lbl_8_data_5DFC__fzgx_offset_0, (u32)lbl_8_data_5E0C__fzgx_offset_0, (u32)lbl_8_data_5E1C__fzgx_offset_0, (u32)lbl_8_data_5E2C__fzgx_offset_0, (u32)lbl_8_data_5E3C__fzgx_offset_0, (u32)lbl_8_data_5E84__fzgx_offset_0, (u32)lbl_8_data_5EB0__fzgx_offset_0, (u32)lbl_8_data_5EC4__fzgx_offset_0, (u32)lbl_8_data_5ED8__fzgx_offset_0, (u32)lbl_8_data_5EEC__fzgx_offset_0, (u32)lbl_8_data_5F00__fzgx_offset_0, (u32)lbl_8_data_5F30__fzgx_offset_0, (u32)lbl_8_data_5F44__fzgx_offset_0, (u32)lbl_8_data_5F54__fzgx_offset_0, (u32)lbl_8_data_5F64__fzgx_offset_0, (u32)lbl_8_data_5F74__fzgx_offset_0, (u32)lbl_8_data_5F84__fzgx_offset_0, (u32)lbl_8_data_5F90__fzgx_offset_0, (u32)lbl_8_data_5FA4__fzgx_offset_0, (u32)lbl_8_data_5FB8__fzgx_offset_0, (u32)lbl_8_data_5FCC__fzgx_offset_0, (u32)lbl_8_data_5FE0__fzgx_offset_0, (u32)lbl_8_data_5FF4__fzgx_offset_0, (u32)lbl_8_data_6014__fzgx_offset_0, (u32)lbl_8_data_6030__fzgx_offset_0, (u32)lbl_8_data_6044__fzgx_offset_0, (u32)lbl_8_data_6058__fzgx_offset_0, (u32)lbl_8_data_606C__fzgx_offset_0, (u32)lbl_8_data_6080__fzgx_offset_0, (u32)lbl_8_data_60A4__fzgx_offset_0, (u32)lbl_8_data_60C4__fzgx_offset_0, (u32)lbl_8_data_60D4__fzgx_offset_0, (u32)lbl_8_data_60E4__fzgx_offset_0, (u32)lbl_8_data_60F4__fzgx_offset_0, (u32)lbl_8_data_6104__fzgx_offset_0, (u32)lbl_8_data_6118__fzgx_offset_0, (u32)lbl_8_data_614C__fzgx_offset_0, (u32)lbl_8_data_6160__fzgx_offset_0, (u32)lbl_8_data_6174__fzgx_offset_0, (u32)lbl_8_data_6188__fzgx_offset_0, (u32)lbl_8_data_619C__fzgx_offset_0, (u32)lbl_8_data_61C0__fzgx_offset_0, (u32)lbl_8_data_61D0__fzgx_offset_0, (u32)lbl_8_data_61E0__fzgx_offset_0, (u32)lbl_8_data_61F0__fzgx_offset_0, (u32)lbl_8_data_6200__fzgx_offset_0, (u32)lbl_8_data_6210__fzgx_offset_0, (u32)lbl_8_data_6220__fzgx_offset_0, (u32)lbl_8_data_624C__fzgx_offset_0, (u32)lbl_8_data_6260__fzgx_offset_0, (u32)lbl_8_data_6274__fzgx_offset_0, (u32)lbl_8_data_6288__fzgx_offset_0, (u32)lbl_8_data_629C__fzgx_offset_0, 0x41204D65, 0x6D6F7279, 0x20436172, 0x64206973, 0x206E6F74, 0x20696E73, 0x65727465, 0x6420696E, 0x20536C6F, 0x7420412E, 0x0A506C65, 0x61736520, 0x70726F70, 0x65726C79, 0x20696E73, 0x65727420, 0x61204D65, 0x6D6F7279, 0x20436172, 0x642E0000, 0x00000000, 0x8358838D, 0x83628367, 0x4182C983, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882AA8C, 0xA95B82DD, 0x5D82C282, 0xA982E882, 0xDC82B982, 0xF181420A, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x90DA5B82, 0xB982C25D, 0x91B15B82, 0xBC82AD5D, 0x82F08A6D, 0x5B82A982, 0xAD5D9446, 0x5B82C982, 0xF15D82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_6E30 = {{(u32)lbl_8_data_6D68__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DBC__fzgx_offset_0, 0x54686572, 0x65206172}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_6E50[29] = {0x65202564, 0x20626C6F, 0x636B7320, 0x6F662066, 0x72656520, 0x73706163, 0x650A6F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x536C6F74, 0x20412E00, 0x8358838D, 0x83628367, 0x4182CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CD0A, 0x25648375, 0x838D8362, 0x834E82CC, 0x8BF35B82, 0xA05D82AB, 0x82AA82A0, 0x82E882DC, 0x82B70000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_6EC4 = {{(u32)lbl_8_data_6E48__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6E88__fzgx_offset_0, 0x54686520, 0x67616D65}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_6EE4[16] = {0x20636F75, 0x6C64206E, 0x6F742062, 0x65207361, 0x7665642E, 0x00000000, 0x8351815B, 0x83808366, 0x815B835E, 0x82CD835A, 0x815B8375, 0x82B382EA, 0x82DC82B9, 0x82F182C5, 0x82B582BD, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_6F24 = {{(u32)lbl_8_data_6EDC__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6EFC__fzgx_offset_0, 0x54686572, 0x65206973}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_6F44[175] = {0x206E6F74, 0x20656E6F, 0x75676820, 0x66726565, 0x20737061, 0x6365206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x640A696E, 0x20536C6F, 0x74204120, 0x746F2073, 0x61766520, 0x616C6C20, 0x74797065, 0x73206F66, 0x206E6577, 0x2066696C, 0x6573202E, 0x0A457869, 0x7374696E, 0x6720462D, 0x5A45524F, 0x20475820, 0x66696C65, 0x73206D61, 0x79206265, 0x20657261, 0x73656420, 0x6F72206F, 0x76657277, 0x72697474, 0x656E2E0A, 0x28546F20, 0x6D616E61, 0x67652066, 0x696C6573, 0x206F6E20, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642C, 0x20706C65, 0x61736520, 0x676F2074, 0x6F207468, 0x650A4E69, 0x6E74656E, 0x646F2047, 0x616D6543, 0x75626520, 0x4D656D6F, 0x72792043, 0x61726420, 0x6D616E61, 0x67656D65, 0x6E742073, 0x63726565, 0x6E2E290A, 0x496E206F, 0x72646572, 0x20746F20, 0x73617665, 0x2061206E, 0x65772066, 0x696C652C, 0x20746865, 0x20666F6C, 0x6C6F7769, 0x6E67206E, 0x756D6265, 0x72206F66, 0x0A667265, 0x65206669, 0x6C657320, 0x616E6420, 0x626C6F63, 0x6B73206D, 0x75737420, 0x62652061, 0x7661696C, 0x61626C65, 0x3A0A4761, 0x6D652031, 0x2066696C, 0x6520616E, 0x64203420, 0x626C6F63, 0x6B730A47, 0x61726167, 0x65203120, 0x66696C65, 0x20616E64, 0x20313820, 0x626C6F63, 0x6B730A47, 0x686F7374, 0x20312066, 0x696C6520, 0x616E6420, 0x3320626C, 0x6F636B73, 0x0A456D62, 0x6C656D20, 0x31206669, 0x6C652061, 0x6E642033, 0x20626C6F, 0x636B730A, 0x5265706C, 0x61792031, 0x2066696C, 0x6520616E, 0x64203381, 0x60313320, 0x626C6F63, 0x6B730A00, 0x8358838D, 0x83628367, 0x4182CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882C98B, 0xF382AB97, 0x6597CA82, 0xAA82C882, 0xA282A981, 0x41837483, 0x40834383, 0x8B909482, 0xCC90A78C, 0xC082F00A, 0x897A82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x8142835A, 0x815B8375, 0x82B782E9, 0x82C982CD, 0x8FAD82C8, 0x82AD82C6, 0x82E08374, 0x83408343, 0x838B3182, 0xC282C60A, 0x34837583, 0x8D836283, 0x4E954B97, 0x7682C582, 0xB7814228, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x93E09765, 0x82F090AE, 0x979D82B7, 0x82E982C9, 0x82CD8141, 0x0A967B91, 0xCC82CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6889E696, 0xCA82C58D, 0x7382C882, 0xC182C482, 0xAD82BE82, 0xB382A229, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7200 = {{(u32)lbl_8_data_6F3C__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_7120__fzgx_offset_0, 0x54686520, 0x4D656D6F}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7220[20] = {0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x410A6973, 0x20636F72, 0x72757074, 0x65642061, 0x6E642063, 0x616E6E6F, 0x74206265, 0x20757365, 0x642E0000, 0x83478393, 0x8352815B, 0x836882AA, 0x82A882A9, 0x82B582A2, 0x82C582B7, 0x82E60000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7270 = {{(u32)lbl_8_data_7218__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_7254__fzgx_offset_0, 0x54686520, 0x4D656D6F}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7290[34] = {0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x41206973, 0x2064616D, 0x61676564, 0x0A616E64, 0x2063616E, 0x6E6F7420, 0x62652075, 0x7365642E, 0x20000000, 0x8358838D, 0x83628367, 0x4182CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CD81, 0x41836681, 0x5B835E82, 0xAA0A82B1, 0x82ED82EA, 0x82C482A2, 0x82E982CC, 0x82C58E67, 0x5B82B55D, 0x97705B82, 0xE682A45D, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7318 = {{(u32)lbl_8_data_7288__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_72C4__fzgx_offset_0, 0x506C6561, 0x73652069}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7338[24] = {0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E746F, 0x20536C6F, 0x7420412E, 0x20000000, 0x8358838D, 0x83628367, 0x4182C98E, 0x675B82B5, 0x5D97705B, 0x82E682A4, 0x5D82B782, 0xE9838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF082B382, 0xB582C482, 0xAD82BE82, 0xB382A200}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7398 = {{(u32)lbl_8_data_7330__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_735C__fzgx_offset_0, 0x54686520, 0x64657669}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_73B8[32] = {0x63652069, 0x6E20536C, 0x6F742041, 0x20697320, 0x6E6F7420, 0x73757070, 0x6F727465, 0x642E0A50, 0x6C656173, 0x6520696E, 0x73657274, 0x2061204D, 0x656D6F72, 0x79204361, 0x72642E00, 0x8358838D, 0x83628367, 0x4182C982, 0xCD0A8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x88C85B82, 0xA25D8A4F, 0x5B82AA82, 0xA25D82CC, 0x82E082CC, 0x82AA82B3, 0x82B382C1, 0x82C482A2, 0x82DC82B7, 0x81420000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7438 = {{(u32)lbl_8_data_73B0__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_73F4__fzgx_offset_0, 0x839F8163, 0x436F6E74}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7458[9] = {0x696E7565, 0x20776974, 0x686F7574, 0x20736176, 0x696E670A, 0x83B28163, 0x54727920, 0x61676169, 0x6E000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_747C = {{(u32)lbl_8_data_7450__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, 0x47616D65, 0x20446174}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_749C[28] = {0x61206361, 0x6E6E6F74, 0x20626520, 0x6C6F6164, 0x65642E0A, 0x436F6E74, 0x696E7565, 0x20776974, 0x686F7574, 0x20736176, 0x696E673F, 0x20000000, 0x82B182CC, 0x82DC82DC, 0x82C582CD, 0x81418351, 0x815B8380, 0x8366815B, 0x835E82F0, 0x0A838D81, 0x5B836882, 0xC582AB82, 0xDC82B982, 0xF182AA82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_750C = {{(u32)lbl_8_data_7494__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_74CC__fzgx_offset_0, 0x47616D65, 0x20446174}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_752C[28] = {0x61206361, 0x6E6E6F74, 0x20626520, 0x73617665, 0x642E0A20, 0x436F6E74, 0x696E7565, 0x20776974, 0x686F7574, 0x20736176, 0x696E673F, 0x20000000, 0x82B182CC, 0x82DC82DC, 0x82C582CD, 0x81418351, 0x815B8380, 0x8366815B, 0x835E82F0, 0x0A835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF182AA82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_759C = {{(u32)lbl_8_data_7524__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_755C__fzgx_offset_0, 0x47616D65, 0x20446174}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_75BC[57] = {0x6120636F, 0x756C6420, 0x6E6F7420, 0x62652073, 0x61766564, 0x2E0A2059, 0x6F752063, 0x616E2073, 0x61766520, 0x616E6420, 0x6C6F6164, 0x20646174, 0x61206672, 0x6F6D0A20, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x6D656E75, 0x20756E64, 0x6572204F, 0x7074696F, 0x6E732E20, 0x00000000, 0x8351815B, 0x83808366, 0x815B835E, 0x82CD838D, 0x815B8368, 0x82B382EA, 0x82DC82B9, 0x82F182C5, 0x82B582BD, 0x81420A83, 0x51815B83, 0x80836681, 0x5B835E82, 0xCC835A81, 0x5B837581, 0x41838D81, 0x5B836882, 0xCD81410A, 0x83498376, 0x83568387, 0x839382CC, 0x83818382, 0x838A815B, 0x834A815B, 0x83688381, 0x836A8385, 0x815B82A9, 0x82E789C2, 0x5B82A95D, 0x945C5B82, 0xCC82A45D, 0x82C582B7, 0x81420000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_76A0 = {{(u32)lbl_8_data_75B4__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_761C__fzgx_offset_0, 0x47616D65, 0x20446174}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_76C0[56] = {0x6120636F, 0x756C6420, 0x6E6F7420, 0x62652073, 0x61766564, 0x2E0A596F, 0x75206361, 0x6E207361, 0x76652061, 0x6E64206C, 0x6F616420, 0x64617461, 0x2066726F, 0x6D0A7468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x64206D65, 0x6E752075, 0x6E646572, 0x204F7074, 0x696F6E73, 0x2E000000, 0x8351815B, 0x83808366, 0x815B835E, 0x82CD835A, 0x815B8375, 0x82B382EA, 0x82DC82B9, 0x82F182C5, 0x82B582BD, 0x81420A83, 0x51815B83, 0x80836681, 0x5B835E82, 0xCC835A81, 0x5B837581, 0x41838D81, 0x5B836882, 0xCD81410A, 0x83498376, 0x83568387, 0x839382CC, 0x83818382, 0x838A815B, 0x834A815B, 0x83688381, 0x836A8385, 0x815B82A9, 0x82E789C2, 0x5B82A95D, 0x945C5B82, 0xCC82A45D, 0x82C582B7, 0x81420000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_77A0 = {{(u32)lbl_8_data_76B8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_771C__fzgx_offset_0, 0x54686572, 0x65206973}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_77C0[80] = {0x206E6F20, 0x462D5A45, 0x524F2047, 0x58207361, 0x76652066, 0x696C650A, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20536C, 0x6F742041, 0x2E0A576F, 0x756C6420, 0x796F7520, 0x6C696B65, 0x20746F20, 0x63726561, 0x74652061, 0x20736176, 0x65206669, 0x6C65206E, 0x6F773F20, 0x0A283120, 0x73617665, 0x2066696C, 0x65207573, 0x65732034, 0x20626C6F, 0x636B7320, 0x6F66206D, 0x656D6F72, 0x792E290A, 0x00000000, 0x8358838D, 0x83628367, 0x4182CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882C982, 0xCD462D5A, 0x45524F20, 0x475882CC, 0x0A835181, 0x5B838083, 0x66815B83, 0x5E82AA82, 0xA082E882, 0xDC82B982, 0xF1814283, 0x58838D83, 0x62836741, 0x82CC0A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882C983, 0x51815B83, 0x80836681, 0x5B835E82, 0xF08DEC5B, 0x82B382AD, 0x5D90AC5B, 0x82B982A2, 0x5D82B582, 0xC482E00A, 0x82E682EB, 0x82B582A2, 0x82C582B7, 0x82A93F28, 0x34837583, 0x8D836283, 0x4E8E675B, 0x82B55D97, 0x705B82E6, 0x82A45D82, 0xB582DC82, 0xB7290000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7900 = {{(u32)lbl_8_data_77B8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_784C__fzgx_offset_0, 0x41647661, 0x6E63696E}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7920[24] = {0x6720746F, 0x20757365, 0x72206E61, 0x6D650A72, 0x65676973, 0x74726174, 0x696F6E20, 0x73637265, 0x656E2E00, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8386815B, 0x8355815B, 0x96BC5B82, 0xDF82A25D, 0x82F0936F, 0x5B82C682, 0xA45D985E, 0x5B82EB82, 0xAD5D82B5, 0x82DC82B7, 0x81420000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7980 = {{(u32)lbl_8_data_7918__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_7944__fzgx_offset_0, 0x54686520, 0x4D656D6F}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_79A0[30] = {0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x41207761, 0x73207265, 0x6D6F7665, 0x642E0A20, 0x54686520, 0x70726F63, 0x65737320, 0x68617320, 0x6265656E, 0x2063616E, 0x63656C6C, 0x65642E00, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x94B282A9, 0x82EA82DC, 0x82B582BD, 0x81420A8D, 0xEC8BC682, 0xF0834C83, 0x83839383, 0x5A838B82, 0xB582DC82, 0xB7814200}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7A18 = {{(u32)lbl_8_data_7998__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_79E0__fzgx_offset_0, 0x50726573, 0x73207468}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7A38[30] = {0x6520839F, 0x20427574, 0x746F6E20, 0x7768656E, 0x20726561, 0x64792E0A, 0x20507265, 0x73732074, 0x68652083, 0xA0204275, 0x74746F6E, 0x20746F20, 0x63616E63, 0x656C2E20, 0x00000000, 0x8F8094F5, 0x82AA82C5, 0x82AB82BD, 0x82E7839F, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A83, 0xA082C583, 0x4C838383, 0x93835A83, 0x8B82B582, 0xDC82B781, 0x42000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7AB0 = {{(u32)lbl_8_data_7A30__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_7A74__fzgx_offset_0, 0x54686520, 0x4D656D6F}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7AD0[22] = {0x72792043, 0x61726420, 0x70726F63, 0x65737320, 0x77617320, 0x63616E63, 0x656C6C65, 0x642E2000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8DEC5B82, 0xB382AC5D, 0x8BC65B82, 0xE582A45D, 0x82F0834C, 0x83838393, 0x835A838B, 0x82B582DC, 0x82B582BD, 0x81420000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7B28 = {{(u32)lbl_8_data_7AC8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_7AF0__fzgx_offset_0, 0x506C6561, 0x73652070}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7B48[12] = {0x72657373, 0x20746865, 0x20839F20, 0x42757474, 0x6F6E2E20, 0x00000000, 0x839F82F0, 0x899F82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[8]; void *view[8]; } fzgx_pool_native_lbl_8_data_0_unk_7B78 = {{(u32)lbl_8_data_7B40__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_7B60__fzgx_offset_0, 0x52656769, 0x73746572}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_0_gap_7B98[25] = {0x20746869, 0x73206E61, 0x6D65206F, 0x6E207468, 0x650A4D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F, 0x7420413F, 0x20000000, 0x82B182CC, 0x96BC914F, 0x82C58381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93, 0x6F985E82, 0xB582C482, 0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A93F, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union { u32 words[7]; void *view[7]; } fzgx_pool_native_lbl_8_data_0_unk_7BFC = {{(u32)lbl_8_data_7B90__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_6DB8__fzgx_offset_0, (u32)lbl_8_data_7BC4__fzgx_offset_0, 0x25730000}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_8_data_0_str_7C18[0x10] = {0x40, 0x23, 0x24, 0x40, 0x23, 0x24, 0x40, 0x24, 0x20, 0x20, 0x25, 0x73, 0x0A, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_8_data_0_str_7C28[0xC] = {0x83, 0x47, 0x83, 0x74, 0x83, 0x5B, 0x83, 0x8D, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_8_bss_0;
u8 fzgx_pool_lbl_8_bss_0_gap_1;
u8 fzgx_obj_lbl_8_bss_2;
u8 fzgx_pool_lbl_8_bss_0_gap_3;
u32 lbl_8_bss_4[2];
u32 lbl_8_bss_C[5];
u32 lbl_8_bss_20[129];
s16 lbl_8_bss_224;
u16 fzgx_pool_lbl_8_bss_0_gap_226;
u32 lbl_8_bss_228;
u32 lbl_8_bss_22C;
u8 lbl_8_bss_230;
u8 fzgx_pool_lbl_8_bss_0_gap_231;
u16 fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
u32 fzgx_obj_lbl_8_bss_234;
u32 fzgx_obj_lbl_8_bss_238;
u8 lbl_8_bss_238__fzgx_offset_4;
u8 fzgx_obj_lbl_8_bss_23D;
u16 fzgx_pool_lbl_8_bss_0_gap_23E;
u8 fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
u8 lbl_8_bss_241;
u16 lbl_8_bss_242__fzgx_offset_0;
s32 lbl_8_bss_242__fzgx_offset_2;
u8 lbl_8_bss_242__fzgx_offset_6;
u8 lbl_8_bss_242__fzgx_offset_7;
u16 lbl_8_bss_242__fzgx_offset_8;
u32 lbl_8_bss_242__fzgx_offset_A;
u8 lbl_8_bss_242__fzgx_offset_E;
u8 lbl_8_bss_242__fzgx_offset_F;
u8 lbl_8_bss_242__fzgx_offset_10;
u8 lbl_8_bss_242__fzgx_offset_11;
s32 lbl_8_bss_242__fzgx_offset_12;
s32 lbl_8_bss_242__fzgx_offset_16;
s32 lbl_8_bss_242__fzgx_offset_1A;
u8 lbl_8_bss_242__fzgx_offset_1E;
u8 lbl_8_bss_242__fzgx_offset_1F;
u16 lbl_8_bss_242__fzgx_offset_20;
s32 lbl_8_bss_242__fzgx_offset_22;
u8 lbl_8_bss_242__fzgx_offset_26;
u8 lbl_8_bss_242__fzgx_offset_27;
u16 lbl_8_bss_242__fzgx_offset_28;
u32 lbl_8_bss_242__fzgx_offset_2A[15];
u16 fzgx_obj_lbl_8_bss_2A8;
u16 fzgx_pool_lbl_8_bss_0_gap_2AA;
u32 fzgx_obj_lbl_8_bss_2AC;
u32 fzgx_obj_lbl_8_bss_2B0;
u32 lbl_8_bss_2B4;
u32 lbl_8_bss_2B8;
u32 lbl_8_bss_2BC;
u32 fzgx_obj_lbl_8_bss_2C0[67];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_data_first_access(void) { void *volatile sink; /* fzgx-allow: S2 section-base primer sink */
sink = (*((fzgx_pool_native_lbl_8_data_0_unk_6E30.view) + (0)));
sink = (*((fzgx_pool_native_lbl_8_data_0_unk_6EC4.view) + (0)));
sink = (*((fzgx_pool_native_lbl_8_data_0_unk_6F24.view) + (0)));
} /* fzgx-allow: S2 section-base primer sink */
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_0;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_1;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_3;
    s = *(u8 *)&lbl_8_bss_4;
    s = *(u8 *)&lbl_8_bss_C;
    s = *(u8 *)&lbl_8_bss_20;
    s = *(u8 *)&lbl_8_bss_224;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_226;
    s = *(u8 *)&lbl_8_bss_228;
    s = *(u8 *)&lbl_8_bss_22C;
    s = *(u8 *)&lbl_8_bss_230;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_234;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_238;
    s = *(u8 *)&lbl_8_bss_238__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_23D;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    s = *(u8 *)&lbl_8_bss_241;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_0;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_2;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_6;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_7;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_8;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_A;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_E;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_F;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_10;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_11;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_12;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_16;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1A;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1E;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1F;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_20;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_22;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_26;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_27;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_28;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_2A;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2A8;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_2AA;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2AC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2B0;
    s = *(u8 *)&lbl_8_bss_2B4;
    s = *(u8 *)&lbl_8_bss_2B8;
    s = *(u8 *)&lbl_8_bss_2BC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2C0;
}
#pragma section code_type ".text"

void fn_8_2660(f32 arg0, f32 arg1, f32 arg2) {

struct TitleInput *p_lbl_1_bss_9F8;
u32 loc_60, loc_5C, loc_58, loc_54, loc_50, loc_4C, loc_48, loc_44, loc_40, loc_3C;
u32 loc_38, loc_34, loc_30, loc_2C, loc_28, loc_24, loc_20, loc_1C, loc_18, loc_14;
u32 loc_10, loc_C, loc_8;
u32 buf84[8];
u32 buf64[8];
struct TitleTrans args;
u32 bufC8[256];
void **title_formats;
void **title_names;
void **p_data_tbl;
s32 *p_idx;
void *item;
u32 cnt;
s32 ret;
u16 vHalf;
s32 vByte;
f32 fTmp;
u8 *src;
u8 *dst;
u8 *cp;



lbl_8_bss_242__fzgx_offset_2 = lbl_8_bss_242__fzgx_offset_2 + 1;
if (lbl_8_bss_242__fzgx_offset_E != lbl_8_bss_242__fzgx_offset_6) {
lbl_8_bss_242__fzgx_offset_6 = lbl_8_bss_242__fzgx_offset_E;
lbl_8_bss_242__fzgx_offset_2 = 0;
}
if (lbl_8_bss_242__fzgx_offset_2 < 10) {
f32 f = (f32)lbl_8_bss_242__fzgx_offset_2 / (10.0f);
fn_1_54278((s32)((320.0f) * ((1.0f) - f) * ((1.0f) - f)), 0);
fn_1_5428C(f * f);
} else {
fn_1_54278(0, 0);
fn_1_5428C((1.0f));
}
memset(&args, 0, 36);
switch (lbl_8_bss_242__fzgx_offset_E) {
case 0:
lbl_8_bss_242__fzgx_offset_10 = 0;
lbl_8_bss_242__fzgx_offset_12 = 0;
lbl_8_bss_242__fzgx_offset_16 = 0;
lbl_8_bss_242__fzgx_offset_E = 1;
lbl_8_bss_242__fzgx_offset_A = lbl_8_bss_242__fzgx_offset_A + 1;
break;
case 1:
lbl_8_bss_242__fzgx_offset_1A = fn_1_B800C(0);
fn_1_B80F0(0);
if (lbl_8_bss_242__fzgx_offset_1A == -6 || lbl_8_bss_242__fzgx_offset_1A == -13) {
if (lbl_8_bss_242__fzgx_offset_A >= 2) {
lbl_8_bss_242__fzgx_offset_E = 33;
} else {
lbl_8_bss_242__fzgx_offset_E = 15;
}
} else if (lbl_8_bss_242__fzgx_offset_1A == 0 || lbl_8_bss_242__fzgx_offset_1A == -3) {
lbl_8_bss_242__fzgx_offset_E = 4;
} else if (lbl_8_bss_242__fzgx_offset_1A == -2) {
lbl_8_bss_242__fzgx_offset_E = 35;
} else {
lbl_8_bss_242__fzgx_offset_E = 33;
}
break;
case 2:
lbl_8_bss_242__fzgx_offset_E = 5;
break;
case 3:
if (fn_1_B7C00() == 0) {
args.unk0 = 0;
args.unk4 = 0x104;
args.unkC = (u32)&lbl_1_bss_7AC40;
fn_1_AA6D8(2, 0, &args);
lbl_8_bss_242__fzgx_offset_E = 3;
}
break;
case 4:
if (fn_1_B7C00() == 0) {
ret = fn_1_B7C5C();
lbl_8_bss_242__fzgx_offset_1A = ret;
if (ret == 0) {
fn_1_5104();
lbl_8_bss_242__fzgx_offset_E = 5;
} else if (ret == -4 || ret == -121 || ret == -122) {
args.unk0 = 0;
fn_1_B7CE4(0, buf84);
args.unk8 = (u32)buf84;
fn_1_509C();
args.unkC = (u32)&lbl_1_bss_7AC40;
args.unk4 = 0x14000;
fn_1_AA6D8(0, 0, &args);
} else {
lbl_8_bss_242__fzgx_offset_E = 5;
}
}
break;
case 5:
if (fn_1_B7EC4(0) == 0) {
lbl_8_bss_242__fzgx_offset_E = 8;
} else if (fn_1_B7EC4(0) != 0) {
fn_1_B8338(0);
fn_1_B8E84(1, &lbl_8_bss_242__fzgx_offset_10, &lbl_8_bss_242__fzgx_offset_12, &lbl_8_bss_242__fzgx_offset_16);
if (lbl_8_bss_242__fzgx_offset_10 != 0) {
lbl_8_bss_242__fzgx_offset_E = 15;
} else if (lbl_8_bss_242__fzgx_offset_12 >= 4 && lbl_8_bss_242__fzgx_offset_16 > 0) {
lbl_8_bss_242__fzgx_offset_E = 19;
} else {
lbl_8_bss_242__fzgx_offset_E = 21;
}
}
break;
case 6:
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_A = 0;
lbl_8_bss_242__fzgx_offset_E = 0x22;
break;
case 7:
if (fn_1_B7C00() != 0) {
break;
}
if (fn_1_B7E98(0) == 0) {
lbl_8_bss_242__fzgx_offset_E = 11;
break;
}
do { loc_5C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_5C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
if (lbl_8_bss_242__fzgx_offset_1A == -13 || lbl_8_bss_242__fzgx_offset_1A == -6) {
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7270.view; p_idx = &lbl_801A66B4; item = (*((p_data_tbl) + (*p_idx))); loc_58 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_58, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_58, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
} else {
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7318.view; p_idx = &lbl_801A66B4; item = (*((p_data_tbl) + (*p_idx))); loc_54 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_54, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_54, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
}
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_750C.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&lbl_1_bss_9F8; if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 10;
fn_1_C3378();
fn_1_F7A20();
} else {
fn_1_A2D84(0xA9011000);
lbl_8_bss_242__fzgx_offset_E = 11;
}
}
break;
case 8:
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x24;
break;
case 9:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_50 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_50, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7438.view; p_idx = &lbl_801A66B4; item = (*((p_data_tbl) + (*p_idx))); loc_4C = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_4C, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_4C, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_747C.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (280.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
vHalf = lbl_1_bss_9F8.unk_8;
if ((vHalf >> 8) & 1) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 10;
fn_1_C3378();
fn_1_F7A20();
} else if ((vHalf >> 11) & 1) {
fn_1_A2D84(0xA9011000);
lbl_8_bss_242__fzgx_offset_E = 11;
}
break;
case 10:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 9;
break;
case 11:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_48 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_48, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_6E30.view; p_idx = &lbl_801A66B4; item = (*((p_data_tbl) + (*p_idx))); loc_44 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_44, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_44, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_750C.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&lbl_1_bss_9F8; if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 10;
fn_1_C3378();
fn_1_F7A20();
} else {
fn_1_A2D84(0xA9011000);
lbl_8_bss_242__fzgx_offset_E = 11;
}
}
break;
case 12:
do { loc_40 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_40, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_76A0.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7B78.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 0x25;
}
break;
case 13:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_E = 7;
break;
case 14:
if (fn_1_B7C00() != 0) {
break;
}
if (lbl_8_bss_242__fzgx_offset_10 != 0) {
lbl_8_bss_242__fzgx_offset_E = 15;
} else {
lbl_8_bss_242__fzgx_offset_E = 17;
}
break;
case 15:
if (fn_1_B7C00() != 0) {
break;
}
args.unk0 = 1;
args.unk4 = 0x104;
args.unkC = (u32)&lbl_1_bss_718E0;
fn_1_AA6D8(2, 0, &args);
lbl_8_bss_242__fzgx_offset_E = 0x10;
break;
case 16:
if (fn_1_B7C00() != 0) {
break;
}
ret = fn_1_B7C5C();
lbl_8_bss_242__fzgx_offset_1A = ret;
if (ret != 0) {
lbl_8_bss_242__fzgx_offset_E = 0;
} else if (ret == 0) {
fn_1_C34F0();
lbl_8_bss_242__fzgx_offset_E = 0x25;
} else {
lbl_8_bss_242__fzgx_offset_E = 0x25;
}
break;
case 17:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_E = 0x12;
break;
case 18:
if (fn_1_B7C00() != 0) {
break;
}
if (lbl_8_bss_242__fzgx_offset_12 >= 4 && lbl_8_bss_242__fzgx_offset_16 > 0) {
lbl_8_bss_242__fzgx_offset_E = 0x13;
} else {
lbl_8_bss_242__fzgx_offset_E = 0x15;
}
break;
case 19:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 0;
lbl_8_bss_242__fzgx_offset_E = 0x14;
break;
case 20:
if (fn_1_B7C00() != 0) {
break;
}
if (fn_1_B7E98(0) == 0) {
lbl_8_bss_242__fzgx_offset_E = 11;
break;
}
do { loc_3C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_3C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
title_formats = fzgx_pool_native_lbl_8_data_0_unk_6EC4.view;
sprintf((char *)bufC8, (const char *)(*((title_formats) + (lbl_801A66B4 ))), lbl_8_bss_242__fzgx_offset_12);
loc_38 = (*((fzgx_pool_table8) + (0)));
fn_1_49410();
do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0) ;
title_names = fzgx_pool_native_lbl_8_data_0_unk_7200.view;
if ((void *)bufC8 == (*((title_names) + (lbl_801A66B4 )))) {
fn_1_53C9C((void *)&loc_38, (void *)bufC8, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f));
} else {
fn_1_53C9C((void *)&loc_38, (void *)bufC8, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f));
}
do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7900.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&lbl_1_bss_9F8; if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
lbl_8_bss_242__fzgx_offset_22 = 60;
lbl_8_bss_242__fzgx_offset_E = 0x19;
fn_1_A2D84(0xA9011100);
} else {
lbl_8_bss_242__fzgx_offset_E = 0x1e;
fn_1_A2D84(0xA9011000);
}
}
break;
case 21:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_34 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_34, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7980.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
cnt = lbl_8_bss_242__fzgx_offset_22;
lbl_8_bss_242__fzgx_offset_22 = cnt - 1;
if ((s32)cnt < 0) {
lbl_8_bss_242__fzgx_offset_E = 0x1a;
}
break;
case 22:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_30 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_30, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7A18.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
cnt = lbl_8_bss_242__fzgx_offset_22;
lbl_8_bss_242__fzgx_offset_22 = cnt - 1;
if ((s32)cnt < 0) {
lbl_8_bss_242__fzgx_offset_E = 0;
}
break;
case 23:
fn_8_F9E4((void *)fzgx_obj_lbl_8_bss_234, (void *)fzgx_obj_lbl_8_bss_238, lbl_1_bss_8B3A0.unk_9E);
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x1b;
break;
case 24:
if (fn_1_B7C00() != 0) {
break;
}
if (fn_1_B7E98(0) == 0) {
fn_8_FF9C();
lbl_8_bss_242__fzgx_offset_22 = 120;
lbl_8_bss_242__fzgx_offset_E = 0x1c;
} else if (fn_8_FC5C() != 0) {
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&lbl_1_bss_9F8; if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
p_lbl_1_bss_9F8 = (struct TitleInput *)&lbl_1_bss_9F8;
if ((p_lbl_1_bss_9F8->unk_8 >> 9) & 1) {
lbl_8_bss_242__fzgx_offset_1E = 1;
fn_1_A2D84(0xA9011300);
}
vHalf = p_lbl_1_bss_9F8->unk_8;
if (((vHalf >> 8) & 1) || ((vHalf >> 9) & 1)) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
fn_8_10084((u32)(*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
fn_8_FF9C();
lbl_8_bss_242__fzgx_offset_E = 0x18;
} else {
fn_8_100B4();
}
}
fn_1_4FD64();
fn_1_4D0A0();
fn_1_4AEC0(1);
fn_1_4AEB4((1.5f));
fn_1_49410();
fTmp = (0.75f);
fn_1_4955C(fTmp, fTmp);
fn_1_4954C((0.0200000033f));
fn_1_495C8(9);
fn_1_496FC((320.0f), (220.0f));
fn_1_4966C((-1.0f), (8.0f));
if (lbl_801A66B4 != 5) {
fn_1_495B0(0x80000000);
fn_1_49590((0.5f));
fn_1_4966C((-1.0f), (4.0f));
}
p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7BFC.view;
p_idx = &lbl_801A66B4 ;
fn_1_4A0D8((const char *)(*((p_data_tbl) + (*p_idx))));
fn_1_4AEC0(0);
fn_1_4AEB4((0.0f));
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0200000033f));
loc_60 = (*((fzgx_pool_tail13C) + (0)));
fn_1_4D2AC((void *)&loc_60, (0.0300000012f), (40.0f));
}
break;
case 25:
if (fn_1_B7C00() != 0) {
break;
}
OSReport((const char *)fzgx_pool_native_lbl_8_data_0_str_7C18, (const char *)(*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
if (lbl_801A66B4 != 5) {
fn_80083DB0((u32)buf64, (u32)(*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
src = (u8 *)buf64;
dst = (*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26);
while (*src != 0) {
if (*src < 0x80) {
*dst = *src;
src++;
dst++;
} else {
cp = (u8 *)fn_8_5840(src);
if (cp != 0) {
*dst = *cp;
dst++;
}
src += 2;
}
}
*dst = 0;
}
OSReport((const char *)fzgx_pool_native_lbl_8_data_0_str_7C18, (const char *)(*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
if ((*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26)[0] == 0) {
sprintf((char *)(*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26), (const char *)fzgx_pool_native_lbl_8_data_0_str_7C28);
}
fn_80083DB0((u32)((u8 *)&lbl_1_bss_718E0 + 0x5522), (u32)(*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
fn_1_F7954();
fn_1_B7CE4(1, buf84);
((u8 *)buf84)[8] = 0x20;
((u8 *)buf84)[9] = 0;
strcat((char *)buf84, (char *)(*(u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
fn_1_B7E14(buf84);
*lbl_1_bss_718C0 = fn_1_C3688();
args.unk0 = 1;
args.unk8 = (u32)buf84;
args.unkC = (u32)&lbl_1_bss_718E0;
args.unk4 = 0x14000;
fn_1_AA6D8(0, 0, &args);
lbl_8_bss_242__fzgx_offset_E = 0x1d;
break;
case 26:
if (fn_1_B7C00() != 0) {
break;
}
ret = fn_1_B7C5C();
if (ret == 0) {
fn_1_C34F0();
lbl_8_bss_242__fzgx_offset_E = 0x25;
} else {
lbl_8_bss_242__fzgx_offset_E = 0;
}
break;
case 27:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x1f;
break;
case 28:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_2C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_2C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_6F24.view; p_idx = &lbl_801A66B4; item = (*((p_data_tbl) + (*p_idx))); loc_28 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_28, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_28, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_759C.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&lbl_1_bss_9F8; if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
lbl_8_bss_242__fzgx_offset_E = 0x20;
fn_1_C3378();
fn_1_F7A20();
fn_1_A2D84(0xA9011100);
} else {
lbl_8_bss_242__fzgx_offset_E = 0xb;
fn_1_A2D84(0xA9011000);
}
}
break;
case 29:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_24 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_24, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_76A0.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7B78.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0x25;
fn_1_A2D84(0xA9011100);
}
break;
case 30:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x16;
break;
case 31:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_20 = (*((fzgx_pool_table4) + (0))); fn_1_53BD8((void *)&loc_20, (320.0f), (240.0f), (500.0f), (400.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; item = (*((p_data_tbl) + (*p_idx))); loc_1C = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_1C, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_1C, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_759C.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (345.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_2124(400, &lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&lbl_1_bss_9F8; if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
lbl_8_bss_242__fzgx_offset_E = 0x17;
fn_1_C3378();
fn_1_F7A20();
fn_1_A2D84(0xA9011100);
} else {
lbl_8_bss_242__fzgx_offset_E = 0xb;
fn_1_A2D84(0xA9011000);
}
}
break;
case 32:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_18 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_18, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_77A0.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7B78.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0x25;
fn_1_A2D84(0xA9011100);
}
break;
case 33:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_E = 0xc;
break;
case 34:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_14 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_14, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7398.view; p_idx = &lbl_801A66B4; item = (*((p_data_tbl) + (*p_idx))); loc_10 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7200.view; p_idx = &lbl_801A66B4; if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_10, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_10, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7AB0.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (260.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
vHalf = lbl_1_bss_9F8.unk_8;
if ((vHalf >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0;
fn_1_A2D84(0xA9011100);
} else if ((vHalf >> 9) & 1) {
lbl_8_bss_242__fzgx_offset_22 = 60;
lbl_8_bss_242__fzgx_offset_E = 0xd;
fn_1_A2D84(0xA9011000);
}
break;
case 35:
do { loc_C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7B28.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
cnt = lbl_8_bss_242__fzgx_offset_22;
lbl_8_bss_242__fzgx_offset_22 = cnt - 1;
if ((s32)cnt < 0) {
lbl_8_bss_242__fzgx_offset_E = 0xe;
fn_1_C3378();
fn_1_F7A20();
}
break;
case 36:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_8 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_8, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_76A0.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = fzgx_pool_native_lbl_8_data_0_unk_7B78.view; item = (*((p_data_tbl) + (lbl_801A66B4))); fn_1_49410(); do { if (lbl_801A66B4 == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if (lbl_801A66B4 == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0x25;
fn_1_A2D84(0xA9011100);
}
break;
case 37:
if (fn_1_B88C4() != 0) {
lbl_8_bss_242__fzgx_offset_E = 0x26;
} else {
lbl_8_bss_242__fzgx_offset_E = 0x27;
}
break;
case 38:
if (fn_1_B8EDC(0) != 0) {
lbl_8_bss_242__fzgx_offset_E = 0x27;
}
break;
case 39:
lbl_8_bss_242__fzgx_offset_E = 0x28;
break;
case 40:
lbl_8_bss_242__fzgx_offset_E = 0x29;
break;
case 41:
vByte = lbl_1_bss_58.unk_15;
switch (vByte) {
case 1:
case 3:
lbl_1_bss_96A = 0xa4;
break;
case 0:
case 2:
default:
lbl_1_bss_96A = 0x9c;
break;
}
lbl_1_bss_58.unk_15 = (vByte + 1) & 3;
if (lbl_1_bss_96A == 0x9c) {
fn_1_3EF8C(6);
fn_1_3ED8C(0, 3, 1, lbl_8_bss_224 & 0xFF, 10, 30, 0);
fn_1_3EB78(0, 0, 0, 0);
fn_1_3EFF0((u32)fn_8_784, 1);
fn_8006CE1C((1.0f));
fn_1_3EF08(1);
}
break;
}
fn_1_54278(0, 0);
fn_1_5428C((1.0f));
}
#pragma opt_lifetimes on
#pragma opt_propagation reset
/* fzgx:end fn_8_2660 */

/* fzgx:begin fn_8_4E8C */
// fn_8_4E8C: empty in retail (single blr).
void fn_8_4E8C(void) {
}
/* fzgx:end fn_8_4E8C */

/* fzgx:begin fn_8_4E90 */
extern struct fn_8_4E90_lbl_801A6410 lbl_801A6410;
extern struct fn_8_4E90_lbl_8_bss_0 lbl_8_bss_0;
extern u32 fn_1_3F8C(void *, void *, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_1_7BA08(u32, u32, u32);
extern u32 fn_1_7BA48(u32);
extern u32 fn_8_68D8(void);
extern u32 lbl_8_data_434;
extern u32 lbl_8_data_7CDC;
extern void fn_1_7BAF8(void);

struct fn_8_4E90_lbl_8_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x22C];
    u32 unk_238;
    u8 pad_23C[0x1];
    u8 unk_23D;
    u8 pad_23E[0x4];
    u8 unk_242;
    u8 pad_243[0x45];
    u32 unk_288;
};
struct fn_8_4E90_lbl_801A6410 {
    u32 unk_0;
};

void fn_8_4E90(void) {
    struct fn_8_4E90_lbl_8_bss_0 *p_lbl_8_bss_0;
    u32 t2, t3, t6;
    p_lbl_8_bss_0 = (struct fn_8_4E90_lbl_8_bss_0 *)&lbl_8_bss_0;
    if (p_lbl_8_bss_0->unk_23D == 0) {
    p_lbl_8_bss_0->unk_242 = 0;
    fn_8_68D8();
    if (p_lbl_8_bss_0->unk_8 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_8_bss_0->unk_8, &lbl_8_data_434, 3359);
    p_lbl_8_bss_0->unk_8 = 0;
    }
    t2 = fn_1_7BA08(32, 32, 64);
    t3 = fn_1_45D0(lbl_801A6410.unk_0, t2, &lbl_8_data_434, 3362);
    p_lbl_8_bss_0->unk_8 = t3;
    fn_1_7BA48(t3);
    fn_1_435C(p_lbl_8_bss_0->unk_238);
    t6 = fn_1_3F8C(&lbl_8_data_7CDC, fn_1_7BAF8, p_lbl_8_bss_0->unk_8, 2);
    p_lbl_8_bss_0->unk_288 = t6;
    }
}
/* fzgx:end fn_8_4E90 */

/* fzgx:begin fn_8_4F64 */
typedef signed short s16;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
struct TitleState {
u8 unk0;
u8 unk1;
u8 unk2;
u8 pad3[0x21d];
f32 unk220;
u8 pad224[0x19];
u8 unk23d;
u8 pad23e[4];
u8 unk242;
};
struct TitleRodata {
f32 unk0;
f32 unk4;
f32 unk8;
u8 padC[0x20];
f32 unk2c;
f32 unk30;
f32 unk34;
};
struct FzgxCopy88 { u32 words[22]; };
extern struct TitleState lbl_8_bss_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct FzgxCopy88 lbl_1_rodata_26F8;
extern u16 lbl_1_bss_96A;
extern u32 lbl_801A66A0;
extern int fn_1_3F038(void);
extern void fn_1_52070(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_52088(void);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_8_68F4(void);
void fn_8_4F64(void) {
struct TitleState *state = (struct TitleState *) &lbl_8_bss_0;
struct TitleRodata *rodata = (struct TitleRodata *) &lbl_8_rodata_0;
struct FzgxCopy88 loc_60;
struct FzgxCopy88 loc_8;
s16 temp_r30;
s16 temp_r29;
if (state->unk23d != 0) {
fn_1_3F038();
return;
}
if (state->unk242 != 0) {
if (fn_1_3F038() != 0) {
if (state->unk0 != 0) {
state->unk1 = 1;
state->unk0 = 0;
return;
}
lbl_1_bss_96A = 0xA3;
}
return;
}
fn_1_52070(0x60);
loc_60 = lbl_1_rodata_26F8;
loc_60.words[0] = 0x100;
*(f32 *) ((u8 *) &loc_60 + 4) = rodata->unk2c;
*(f32 *) ((u8 *) &loc_60 + 8) = rodata->unk30;
*(f32 *) ((u8 *) &loc_60 + 12) = rodata->unk34;
*(u32 *) ((u8 *) &loc_60 + 0x30) = 0xD;
fn_1_51678((FontDrawPacket *) &loc_60, 0x100, 0, 0, 0xFA, 0x22);
fn_1_4F734((FontDrawPacket *) &loc_60);
fn_1_52088();
fn_1_52070(0x220);
state->unk220 = rodata->unk8;
fn_1_52088();
fn_1_52070(0x140);
if (state->unk2 != 0 && (lbl_801A66A0 & 0x18)) {
loc_8 = lbl_1_rodata_26F8;
loc_8.words[0] = 0x102;
fn_1_51678((FontDrawPacket *) &loc_8, loc_8.words[0], 0,
(s16) (((fn_1_486C4(loc_8.words[0]) >> 2) & 0x3FFF) * 3),
(fn_1_48690(loc_8.words[0])), ((fn_1_486C4(0x102) >> 2) & 0x3FFF));
*(f32 *) ((u8 *) &loc_8 + 4) = rodata->unk0;
*(f32 *) ((u8 *) &loc_8 + 8) = rodata->unk4;
*(f32 *) ((u8 *) &loc_8 + 12) = rodata->unk8;
*(u32 *) ((u8 *) &loc_8 + 0x30) = 6;
fn_1_4F734((FontDrawPacket *) &loc_8);
}
fn_1_52088();
fn_8_68F4();
}
/* fzgx:end fn_8_4F64 */

/* fzgx:begin fn_8_516C */
extern struct fn_8_516C_lbl_1_bss_7C850 lbl_1_bss_7C850;
extern struct fn_8_516C_lbl_801A6410 lbl_801A6410;
extern struct fn_8_516C_lbl_8_bss_0 lbl_8_bss_0;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_8_69D8(u32, u32);
extern u32 lbl_8_data_434;

struct fn_8_516C_lbl_8_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x22C];
    u32 unk_238;
    u8 pad_23C[0x1];
    u8 unk_23D;
    u8 pad_23E[0x4A];
    u32 unk_288;
};
struct fn_8_516C_lbl_801A6410 {
    u32 unk_0;
};
struct fn_8_516C_lbl_1_bss_7C850 {
    u32 unk_0;
};

void fn_8_516C(void) {
    struct fn_8_516C_lbl_8_bss_0 *p_lbl_8_bss_0;
    u32 v0;
    p_lbl_8_bss_0 = (struct fn_8_516C_lbl_8_bss_0 *)&lbl_8_bss_0;
    fn_1_435C(p_lbl_8_bss_0->unk_238);
    if ((s32)p_lbl_8_bss_0->unk_288 != 0) {
    fn_1_426C(p_lbl_8_bss_0->unk_288);
    p_lbl_8_bss_0->unk_288 = 0;
    }
    if (p_lbl_8_bss_0->unk_8 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_8_bss_0->unk_8, (u32)&lbl_8_data_434, 3405);
    p_lbl_8_bss_0->unk_8 = 0;
    }
    v0 = lbl_1_bss_7C850.unk_0;
    lbl_1_bss_7C850.unk_0 = (v0 + 1);
    if (p_lbl_8_bss_0->unk_23D == 0) {
    fn_8_69D8(v0, (u32)&lbl_1_bss_7C850);
    }
}
/* fzgx:end fn_8_516C */

/* fzgx:begin fn_8_520C */
// fn_8_520C: empty in retail (single blr).
void fn_8_520C(void) {
}
/* fzgx:end fn_8_520C */

/* fzgx:begin fn_8_5210 */
// fn_8_5210: empty in retail (single blr).
void fn_8_5210(void) {
}
/* fzgx:end fn_8_5210 */

/* fzgx:begin fn_8_5214 */
// fn_8_5214: empty in retail (single blr).
void fn_8_5214(void) {
}
/* fzgx:end fn_8_5214 */

/* fzgx:begin fn_8_5218 */
extern u8 lbl_8_bss_0;
extern char lbl_8_data_0[4];
extern void *lbl_801A6410;
extern void fn_8_6A50(void);
extern void fn_8_C038(void);
extern void *fn_1_7BA08(u32, u32, u32);
extern void fn_1_7BA48(void);
extern void fn_1_435C(void *);
extern void *fn_1_46B4(void *, void *, void *, u32);
extern void *fn_1_45D0(void *, void *, void *, u32);
extern void *fn_1_3F8C(void *, void *, void *, u32);
extern void fn_1_7BAF8(void);

typedef struct TitleState {
    u8 unk0[0x8];
    void *resource;
    u8 unkC[0x22c];
    void *unk238;
    u8 unk23c[1];
    u8 initialized;
    u8 unk23e[3];
    u8 unk241;
    u8 reset;
    u8 unk243[0x45];
    void *unk288;
    void *unk28c;
} TitleState;

typedef struct TitleData {
    u8 unk0[0x7cdc];
    u8 unk7cdc[0xc];
} TitleData;

void fn_8_5218(void) {
    TitleState *state = (TitleState *)&lbl_8_bss_0;
    TitleData *data = (TitleData *)&lbl_8_data_0;

    if (!state->initialized) {
        state->reset = 0;
        fn_8_6A50();
        if (state->resource != 0) {
            fn_1_46B4(lbl_801A6410, state->resource, &data->unk0[0x434], 0xdb2);
            state->resource = 0;
        }
        state->resource = fn_1_45D0(lbl_801A6410, fn_1_7BA08(0x20, 0x20, 0x40),
                                    &data->unk0[0x434], 0xdb5);
        fn_1_7BA48();
        fn_1_435C(state->unk238);
        state->unk288 = fn_1_3F8C(&data->unk0[0x7cdc], fn_1_7BAF8,
                                  state->resource, 2);
        state->unk28c = fn_1_3F8C(&data->unk0[0x7ce8], fn_8_C038, 0, 0x1c);
    }
}
/* fzgx:end fn_8_5218 */

/* fzgx:begin fn_8_530C */
#include "font.h"

struct TitleState {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x21d];
    f32 unk220;
    u8 pad224[0x19];
    u8 unk23d;
    u8 pad23e[4];
    u8 unk242;
};

struct TitleRodata {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x20];
    f32 unk2c;
    f32 unk30;
    f32 unk34;
};

struct FzgxCopy88 { u32 words[22]; };

extern struct TitleState lbl_8_bss_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct FzgxCopy88 lbl_1_rodata_26F8;
extern u16 lbl_1_bss_96A;
extern u32 lbl_801A66A0;
extern int fn_1_3F038(void);
extern void fn_1_52070(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_52088(void);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_8_6A70(void);

void fn_8_530C(void) {
    struct TitleState *state = (struct TitleState *) &lbl_8_bss_0;
    struct TitleRodata *rodata = (struct TitleRodata *) &lbl_8_rodata_0;
    struct FzgxCopy88 loc_60;
    struct FzgxCopy88 loc_8;
    s16 temp_r30;
    s16 temp_r29;

    if (state->unk23d != 0) {
        fn_1_3F038();
        return;
    }
    if (state->unk242 != 0) {
        if (fn_1_3F038() != 0) {
            if (state->unk0 != 0) {
                state->unk1 = 1;
                state->unk0 = 0;
                return;
            }
            lbl_1_bss_96A = 0xA3;
        }
        return;
    }
    fn_1_52070(0x60);
    loc_60 = lbl_1_rodata_26F8;
    loc_60.words[0] = 0x100;
    *(f32 *) ((u8 *) &loc_60 + 4) = rodata->unk2c;
    *(f32 *) ((u8 *) &loc_60 + 8) = rodata->unk30;
    *(f32 *) ((u8 *) &loc_60 + 12) = rodata->unk34;
    *(u32 *) ((u8 *) &loc_60 + 0x30) = 0xD;
    fn_1_51678((FontDrawPacket *) &loc_60, 0x100, 0, 0, 0xFA, 0x22);
    fn_1_4F734((FontDrawPacket *) &loc_60);
    fn_1_52088();
    fn_1_52070(0x220);
    state->unk220 = rodata->unk8;
    fn_1_52088();
    fn_1_52070(0x140);
    if (state->unk2 != 0 && (lbl_801A66A0 & 0x18)) {
        loc_8 = lbl_1_rodata_26F8;
        loc_8.words[0] = 0x102;
        fn_1_51678((FontDrawPacket *) &loc_8, loc_8.words[0], 0,
                   (s16) (((fn_1_486C4(loc_8.words[0]) >> 2) & 0x3FFF) * 3),
                   (fn_1_48690(loc_8.words[0])), ((fn_1_486C4(0x102) >> 2) & 0x3FFF));
        *(f32 *) ((u8 *) &loc_8 + 4) = rodata->unk0;
        *(f32 *) ((u8 *) &loc_8 + 8) = rodata->unk4;
        *(f32 *) ((u8 *) &loc_8 + 12) = rodata->unk8;
        *(u32 *) ((u8 *) &loc_8 + 0x30) = 6;
        fn_1_4F734((FontDrawPacket *) &loc_8);
    }
    fn_1_52088();
    fn_8_6A70();
}
/* fzgx:end fn_8_530C */

/* fzgx:begin fn_8_5514 */
extern struct fn_8_5514_lbl_1_bss_7C850 lbl_1_bss_7C850;
extern struct fn_8_5514_lbl_801A6410 lbl_801A6410;
extern struct fn_8_5514_lbl_8_bss_0 lbl_8_bss_0;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_8_6C50(u32, u32);
extern u32 lbl_8_data_434;

struct fn_8_5514_lbl_8_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x22C];
    u32 unk_238;
    u8 pad_23C[0x1];
    u8 unk_23D;
    u8 pad_23E[0x4A];
    u32 unk_288;
    u32 unk_28C;
};
struct fn_8_5514_lbl_801A6410 {
    u32 unk_0;
};
struct fn_8_5514_lbl_1_bss_7C850 {
    u32 unk_0;
};

void fn_8_5514(void) {
    struct fn_8_5514_lbl_8_bss_0 *p_lbl_8_bss_0;
    u32 v0;
    p_lbl_8_bss_0 = (struct fn_8_5514_lbl_8_bss_0 *)&lbl_8_bss_0;
    fn_1_435C(p_lbl_8_bss_0->unk_238);
    if ((s32)p_lbl_8_bss_0->unk_28C != 0) {
    fn_1_426C(p_lbl_8_bss_0->unk_28C);
    p_lbl_8_bss_0->unk_28C = 0;
    }
    if ((s32)p_lbl_8_bss_0->unk_288 != 0) {
    fn_1_426C(p_lbl_8_bss_0->unk_288);
    p_lbl_8_bss_0->unk_288 = 0;
    }
    if (p_lbl_8_bss_0->unk_8 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_8_bss_0->unk_8, (u32)&lbl_8_data_434, 3560);
    p_lbl_8_bss_0->unk_8 = 0;
    }
    v0 = lbl_1_bss_7C850.unk_0;
    lbl_1_bss_7C850.unk_0 = (v0 + 1);
    if (p_lbl_8_bss_0->unk_23D == 0) {
    fn_8_6C50(v0, (u32)&lbl_1_bss_7C850);
    }
}
/* fzgx:end fn_8_5514 */

/* fzgx:begin fn_8_55CC */
extern u32 fn_8_D024(void);
extern u8 lbl_8_bss_23D;
extern u8 lbl_8_bss_242;

void fn_8_55CC(void) {
    if (lbl_8_bss_23D == 0) {
    lbl_8_bss_242 = 0;
    fn_8_D024();
    }
}
/* fzgx:end fn_8_55CC */

/* fzgx:begin fn_8_5608 */
#include "font.h"

struct TitleState {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x21d];
    f32 unk220;
    u8 pad224[0x19];
    u8 unk23d;
    u8 pad23e[4];
    u8 unk242;
};

struct TitleRodata {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x20];
    f32 unk2c;
    f32 unk30;
    f32 unk34;
};

struct FzgxCopy88 { u32 words[22]; };

extern struct TitleState lbl_8_bss_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct FzgxCopy88 lbl_1_rodata_26F8;
extern u16 lbl_1_bss_96A;
extern u32 lbl_801A66A0;
extern int fn_1_3F038(void);
extern void fn_1_52070(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_52088(void);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_8_D034(void);

void fn_8_5608(void) {
    struct TitleState *state = (struct TitleState *)&lbl_8_bss_0;
    struct TitleRodata *rodata = (struct TitleRodata *)&lbl_8_rodata_0;
    struct FzgxCopy88 loc_60;
    struct FzgxCopy88 loc_8;

    if (state->unk23d != 0) {
        fn_1_3F038();
        return;
    }
    if (state->unk242 != 0) {
        if (fn_1_3F038() != 0) {
            if (state->unk0 != 0) {
                state->unk1 = 1;
                state->unk0 = 0;
                return;
            }
            lbl_1_bss_96A = 0x9E;
        }
        return;
    }
    fn_1_52070(0x60);
    loc_60 = lbl_1_rodata_26F8;
    loc_60.words[0] = 0x100;
    *(f32 *)((u8 *)&loc_60 + 4) = rodata->unk2c;
    *(f32 *)((u8 *)&loc_60 + 8) = rodata->unk30;
    *(f32 *)((u8 *)&loc_60 + 12) = rodata->unk34;
    *(u32 *)((u8 *)&loc_60 + 0x30) = 0xD;
    fn_1_51678((FontDrawPacket *)&loc_60, 0x100, 0, 0, 0xFA, 0x22);
    fn_1_4F734((FontDrawPacket *)&loc_60);
    fn_1_52088();
    fn_1_52070(0x220);
    state->unk220 = rodata->unk8;
    fn_1_52088();
    fn_1_52070(0x140);
    if (state->unk2 != 0 && (lbl_801A66A0 & 0x18)) {
        loc_8 = lbl_1_rodata_26F8;
        loc_8.words[0] = 0x102;
        fn_1_51678((FontDrawPacket *)&loc_8, loc_8.words[0], 0,
                   (s16)(((fn_1_486C4(loc_8.words[0]) >> 2) & 0x3FFF) * 3),
                   (s16)fn_1_48690(loc_8.words[0]),
                   (s16)((fn_1_486C4(0x102) >> 2) & 0x3FFF));
        *(f32 *)((u8 *)&loc_8 + 4) = rodata->unk0;
        *(f32 *)((u8 *)&loc_8 + 8) = rodata->unk4;
        *(f32 *)((u8 *)&loc_8 + 12) = rodata->unk8;
        *(u32 *)((u8 *)&loc_8 + 0x30) = 6;
        fn_1_4F734((FontDrawPacket *)&loc_8);
    }
    fn_1_52088();
    fn_8_D034();
}
/* fzgx:end fn_8_5608 */

/* fzgx:begin fn_8_5810 */
extern u32 fn_8_D5F4(void);
extern u8 lbl_8_bss_23D;

void fn_8_5810(void) {
    if (lbl_8_bss_23D == 0) {
    fn_8_D5F4();
    }
}
/* fzgx:end fn_8_5810 */

/* fzgx:begin fn_8_5840 */
/*
 * title.c's .data section up to the code tables: the function addresses the
 * tables off the TU's section base (lbl_8_data_0), so they are defined here in
 * retail layout. The leading block stands in for the TU's earlier data.
 */
static char fzgx_obj_lbl_8_data_0[4] = "NON";
static char fzgx_pool_fzgx_title_data_rest[0x7cfc - 4] = "TU data";
static u8 fzgx_pool_fzgx_codes0[27][2] = { 0 };
static u8 fzgx_pool_fzgx_codes1[27][2] = { 0 };
static u8 fzgx_pool_fzgx_codes2[32][2] = { 0 };
static u8 fzgx_pool_fzgx_codes3[11][2] = { 0 };
static u8 fzgx_pool_fzgx_res0[27] = { 0 };
static u8 fzgx_pool_fzgx_res1[27] = { 0 };
static u8 fzgx_pool_fzgx_res2[36] = { 0 };
static u8 fzgx_pool_fzgx_res3[11] = { 0 };

/* Find the two-byte code KEY in CODES; return its entry in RES. */
#define FIND_CODE(key, codes, res)                                         \
    for (i = 0; i < sizeof(codes); i += 2) {                               \
        if ((key)[0] == ((u8 *)(codes))[i] && (key)[1] == ((u8 *)(codes))[i + 1]) { \
            return &(res)[i / 2];                                          \
        }                                                                  \
    }

/* Map a two-byte code to its entry in one of four lookup tables (code pairs -> result bytes). */
u8 *fn_8_5840(u8 *key) {
    s32 i;

    FIND_CODE(key, fzgx_pool_fzgx_codes0, fzgx_pool_fzgx_res0)
    FIND_CODE(key, fzgx_pool_fzgx_codes1, fzgx_pool_fzgx_res1)
    FIND_CODE(key, fzgx_pool_fzgx_codes2, fzgx_pool_fzgx_res2)
    FIND_CODE(key, fzgx_pool_fzgx_codes3, fzgx_pool_fzgx_res3)
    return 0;
}
/* fzgx:end fn_8_5840 */

/* fzgx:begin fn_8_5B44 */
#include "rel/title/title.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    s8 unk_15;
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
} TitleDisplayState;

extern TitleDisplayState lbl_1_bss_58;
extern char lbl_1_bss_198[];
extern u16 lbl_1_bss_968;
extern u32 lbl_801A66B4;
extern const f32 lbl_8_rodata_8;  // = 1.0f (retail literal pool)
extern char *fn_80083DB0(char *, const char *);

void fn_8_5B44(void) {
    struct { const char *value; } data;  // TU .data base held across the copies
    f32 one;

    data.value = (const char *)&lbl_8_data_0;
    lbl_1_bss_58.unk_0 = lbl_801A66B4;
    one = lbl_8_rodata_8;
    lbl_1_bss_58.unk_1 = 1;
    lbl_1_bss_58.unk_2 = 0;
    lbl_1_bss_58.unk_3 = 0;
    lbl_1_bss_58.unk_4 = 0x280;
    lbl_1_bss_58.unk_6 = 0x150;
    lbl_1_bss_58.unk_8 = 0;
    lbl_1_bss_58.unk_A = 0;
    lbl_1_bss_58.unk_C = one;
    lbl_1_bss_58.unk_10 = one;
    lbl_1_bss_58.unk_14 = 7;
    lbl_1_bss_58.unk_16 = 0;
    lbl_1_bss_58.unk_17 = -1;
    lbl_1_bss_58.unk_18 = -1;
    lbl_1_bss_58.unk_1C = 0;

    if (lbl_1_bss_58.unk_15 == 2) {
        fn_80083DB0(lbl_1_bss_198, data.value + 0x7e2c);
    } else {
        fn_80083DB0(lbl_1_bss_198, data.value + 0x7e3c);
    }
    fn_80083DB0(lbl_1_bss_198 + 0x40, data.value + 0x7e4c);

    lbl_1_bss_58.unk_14 = 4;
    lbl_1_bss_58.unk_16 = 1;
    lbl_1_bss_58.unk_17 = 0;
    lbl_1_bss_968 = 8;
}
/* fzgx:end fn_8_5B44 */

/* fzgx:begin fn_8_5C4C */
// fn_8_5C4C: empty in retail (single blr).
void fn_8_5C4C(void) {
}
/* fzgx:end fn_8_5C4C */

/* fzgx:begin fn_8_5C50 */
// fn_8_5C50: empty in retail (single blr).
void fn_8_5C50(void) {
}
/* fzgx:end fn_8_5C50 */

/* fzgx:begin fn_8_5C54 */
#include "rel/title/title.h"

struct Sig_fn_1_F453C_fn_1_F453C_Arg0 {
    u8 unk_0[1];
};
struct Sig_fn_1_F453C_fn_1_F453C_Arg1 {
    u32 unk_0;
};

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
} Fn5C54Entry;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6[5];
    u8 unk_B;
} Fn5C54Info;

struct fn_8_5C54_lbl_1_bss_8B3A0 {
    u8 pad_0[0x8];
    u16 unk_8;
};

typedef struct {
    u8 unk_0[4];
    u8 unk_4[0x81BC];
} Fn5C54Big;

extern struct fn_8_5C54_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u32 lbl_801A63C0;
extern Fn5C54Entry lbl_1_bss_26B80[];
extern u8 lbl_1_bss_7EFD8[];
extern u32 fn_1_F453C(struct Sig_fn_1_F453C_fn_1_F453C_Arg0 *, struct Sig_fn_1_F453C_fn_1_F453C_Arg1 *, u32);
extern u8 *fn_1_36AD0(void);
extern void fn_1_3EF8C(u8);
extern void fn_1_3ED8C(s32, s32, s32, u8, s32, u8, s32);
extern void fn_1_3EB78(s32, u8 *, u8 *, s32);
extern void fn_1_3EC88(s32, Fn5C54Info *);
extern void fn_1_3EFF0(void *, s32);
extern void fn_1_3F02C(void *);
extern void fn_1_F47A0(u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8_6594(void *);
extern void fn_8_67B0(void);

#define RD(n) fn_1_F453C((struct Sig_fn_1_F453C_fn_1_F453C_Arg0 *)lbl_8_bss_2B0, (struct Sig_fn_1_F453C_fn_1_F453C_Arg1 *)&lbl_8_bss_2AC, (n))

void fn_8_5C54(s32 arg0) {
    u8 locC[4];
    Fn5C54Info info[4];
    u8 loc8[4];
    u32 a;
    u32 count;
    s32 k;
    u32 i;
    u32 j;
    u8 v;
    u8 *src;
    s32 tmp_RD;
    s32 n;

    lbl_8_bss_2AC = 0;
    tmp_RD = RD(8);
    tmp_RD;
    tmp_RD = RD(6);
    a = tmp_RD;
    fn_1_F47A0(RD(32));
    tmp_RD = RD(32);
    lbl_801A63C0 = tmp_RD;
    tmp_RD = RD(5);
    count = tmp_RD;
    tmp_RD = RD(3);
    lbl_1_bss_8B3A0.unk_8 = tmp_RD;
    tmp_RD = RD(2);
    tmp_RD;
    n = 0;
    for (i = 0; i < count; i++) {
        tmp_RD = RD(1);
        lbl_1_bss_26B80[i].unk_0 = tmp_RD;
        tmp_RD = RD(6);
        lbl_1_bss_26B80[i].unk_1 = tmp_RD;
        if (lbl_1_bss_26B80[i].unk_0 != 0) {
            tmp_RD = RD(2);
            lbl_1_bss_26B80[i].unk_2 = tmp_RD;
            tmp_RD = RD(7);
            lbl_1_bss_26B80[i].unk_3 = tmp_RD;
            k = n & 0xFF;
            locC[k] = lbl_1_bss_26B80[i].unk_1;
            loc8[k] = lbl_1_bss_26B80[i].unk_2;
            tmp_RD = RD(1);
            if ((u8)tmp_RD) {
                for (j = 0; j < 0x81C0; j++) {
                    tmp_RD = RD(8);
                    v = tmp_RD;
                    ((u8 *)&((Fn5C54Big *)fn_1_36AD0())[i])[j] = v;
                }
                src = ((Fn5C54Big *)fn_1_36AD0())[i].unk_4;
                fn_80008BA8(&info[k], src, 12);
            } else {
                info[k].unk_1 = lbl_1_bss_26B80[i].unk_1;
                info[k].unk_2 = 1 << lbl_1_bss_26B80[i].unk_2;
                info[k].unk_B = lbl_1_bss_26B80[i].unk_3;
                info[k].unk_4 = 0;
                info[k].unk_3 = 0;
                info[k].unk_5 = 0;
                info[k].unk_0 = 0;
                fn_80008BEC(info[i].unk_6, 0x41, 5);
            }
            n++;
        } else {
            lbl_1_bss_26B80[i].unk_2 = 0;
            lbl_1_bss_26B80[i].unk_3 = 0;
        }
    }
    for (k = 0; k < (n & 0xFF); k++) {
        tmp_RD = RD(2);
        lbl_1_bss_7EFD8[k + 0x38] = tmp_RD + 1;
    }
    if (arg0 != 0) {
        fn_1_3EF8C(6);
        fn_1_3ED8C(0, 3, 1, a, 10, count, 0);
        fn_1_3EB78(n, locC, loc8, 0);
        fn_1_3EC88(n, info);
        fn_1_3EFF0(fn_8_6594, 1);
        fn_1_3F02C(fn_8_67B0);
    }
}
/* fzgx:end fn_8_5C54 */

/* fzgx:begin fn_8_5FD4 */
#include "rel/title/title.h"

struct Sig_fn_1_F453C_fn_1_F453C_Arg0 { u8 unk_0[1]; };
struct Sig_fn_1_F453C_fn_1_F453C_Arg1 { u32 unk_0; };
extern u32 fn_1_F453C(struct Sig_fn_1_F453C_fn_1_F453C_Arg0 *, struct Sig_fn_1_F453C_fn_1_F453C_Arg1 *, u32);
extern void fn_1_3EF14(void *);
extern void fn_1_F4794(u16);

typedef struct {
    f32 x, y, z;
} TitleVec;

/* 0x80-byte record read from the title bitstream */
typedef struct {
    u32 a : 15;
    u32 c : 3;
    u32 d : 5;
    u32 e : 5;
    u32 : 4;
    u32 b : 15;
    u32 f : 5;
    u32 g : 5;
    u32 h : 5;
    u32 : 2;
    TitleVec va[4];
    TitleVec vb[4];
    TitleVec vc;
    TitleVec vd;
} TitleEntry;

typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6;
} TitleRec7;

typedef struct {
    u8 pad_0[0xA0];
    u16 recCount;
    u8 pad_A2[2];
    TitleRec7 recs[(0xFEF0 - 0xA4) / 7];
    u16 count;
    u8 pad_FEF2[0x5A];
    TitleEntry entries[1];
} TitleData;

struct fn_8_5FD4_lbl_1_bss_7EFD8 {
    u8 pad_0[0x18];
    u8 unk_18;
    u8 pad_19[0x27];
    TitleData *unk_40;
};
extern struct fn_8_5FD4_lbl_1_bss_7EFD8 lbl_1_bss_7EFD8;

#define TITLE_READ(n) fn_1_F453C((struct Sig_fn_1_F453C_fn_1_F453C_Arg0 *)lbl_8_bss_2B0, \
                                 (struct Sig_fn_1_F453C_fn_1_F453C_Arg1 *)&lbl_8_bss_2AC, (n))

static inline f32 title_read_f32(void) {
    u32 bits = TITLE_READ(32);
    return *(f32 *)&bits;
}

void fn_8_5FD4(void) {
    u8 buf[0x14B8];
    s32 i;
    s32 j;

    fn_1_3EF14(buf);
    lbl_1_bss_7EFD8.unk_40->count = TITLE_READ(8);
    lbl_1_bss_7EFD8.unk_18 = buf[8];
    for (i = 0; i < lbl_1_bss_7EFD8.unk_40->count; i++) {
        lbl_1_bss_7EFD8.unk_40->entries[i].a = TITLE_READ(14);
        lbl_1_bss_7EFD8.unk_40->entries[i].b = TITLE_READ(14);
        lbl_1_bss_7EFD8.unk_40->entries[i].c = TITLE_READ(4);
        lbl_1_bss_7EFD8.unk_40->entries[i].d = TITLE_READ(5);
        lbl_1_bss_7EFD8.unk_40->entries[i].e = TITLE_READ(5);
        lbl_1_bss_7EFD8.unk_40->entries[i].f = TITLE_READ(5);
        lbl_1_bss_7EFD8.unk_40->entries[i].g = TITLE_READ(5);
        lbl_1_bss_7EFD8.unk_40->entries[i].h = TITLE_READ(5);
        for (j = 0; j < lbl_1_bss_7EFD8.unk_18; j++) {
            lbl_1_bss_7EFD8.unk_40->entries[i].va[j].x = title_read_f32();
            lbl_1_bss_7EFD8.unk_40->entries[i].va[j].y = title_read_f32();
            lbl_1_bss_7EFD8.unk_40->entries[i].va[j].z = title_read_f32();
            lbl_1_bss_7EFD8.unk_40->entries[i].vb[j].x = title_read_f32();
            lbl_1_bss_7EFD8.unk_40->entries[i].vb[j].y = title_read_f32();
            lbl_1_bss_7EFD8.unk_40->entries[i].vb[j].z = title_read_f32();
        }
        lbl_1_bss_7EFD8.unk_40->entries[i].vc.x = title_read_f32();
        lbl_1_bss_7EFD8.unk_40->entries[i].vc.y = title_read_f32();
        lbl_1_bss_7EFD8.unk_40->entries[i].vc.z = title_read_f32();
        lbl_1_bss_7EFD8.unk_40->entries[i].vd.x = title_read_f32();
        lbl_1_bss_7EFD8.unk_40->entries[i].vd.y = title_read_f32();
        lbl_1_bss_7EFD8.unk_40->entries[i].vd.z = title_read_f32();
    }

    lbl_1_bss_7EFD8.unk_40->recCount = TITLE_READ(13);
    for (i = 0; i <= lbl_1_bss_7EFD8.unk_40->recCount; i++) {
        lbl_1_bss_7EFD8.unk_40->recs[i].b0 = TITLE_READ(8);
        lbl_1_bss_7EFD8.unk_40->recs[i].b3 = TITLE_READ(8);
        lbl_1_bss_7EFD8.unk_40->recs[i].b4 = TITLE_READ(7);
        lbl_1_bss_7EFD8.unk_40->recs[i].b5 = TITLE_READ(7);
        lbl_1_bss_7EFD8.unk_40->recs[i].b6 = TITLE_READ(8);
        lbl_1_bss_7EFD8.unk_40->recs[i].b1 = TITLE_READ(8);
        lbl_1_bss_7EFD8.unk_40->recs[i].b2 = TITLE_READ(8);
    }
    fn_1_F4794(lbl_1_bss_7EFD8.unk_40->recCount);
    lbl_1_bss_7EFD8.unk_40->recCount = 0;
}
/* fzgx:end fn_8_5FD4 */

/* fzgx:begin fn_8_6558 */
// fn_8_6558: returns a constant.
int fn_8_6558(void) {
    return 0;
}
/* fzgx:end fn_8_6558 */

/* fzgx:begin fn_8_6560 */
// fn_8_6560: returns a constant.
int fn_8_6560(void) {
    return 0;
}
/* fzgx:end fn_8_6560 */

/* fzgx:begin fn_8_6568 */
// fn_8_6568: returns a constant.
int fn_8_6568(void) {
    return 2;
}
/* fzgx:end fn_8_6568 */

/* fzgx:begin fn_8_6570 */
extern u32 fn_1_D0790(void);

s32 fn_8_6570(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_8_6570 */

/* fzgx:begin fn_8_6594 */
extern u32 fn_1_3F8C0(void);
extern u32 fn_1_47F74(u32);
extern u32 fn_1_5370(u32, u32);
extern u32 fn_80008E84(u32);
extern u32 lbl_8_bss_2B4;
extern void fn_8_6558(void);
extern void fn_8_6560(void);
extern void fn_8_6568(void);
extern void fn_8_6570(void);

void fn_8_6594(u32 arg0) {
    u32 v0;
    u32 t1, t2;
    *(u32 *)((u8 *)arg0 + 168) = (u32)fn_8_6558;
    *(u32 *)((u8 *)arg0 + 196) = (u32)fn_8_6568;
    *(u32 *)((u8 *)arg0 + 204) = (u32)fn_8_6560;
    *(u32 *)((u8 *)arg0 + 172) = (u32)fn_8_6570;
    fn_1_5370(0, 0);
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) | 513);
    v0 = (*(u32 *)((u8 *)arg0 + 0) | 0x800000);
    *(u32 *)((u8 *)arg0 + 0) = v0;
    lbl_8_bss_2B4 = 0;
    t1 = fn_1_3F8C0();
    t2 = fn_80008E84(t1);
    fn_1_47F74(148);
    fn_80008E84(t2);
}
/* fzgx:end fn_8_6594 */

/* fzgx:begin fn_8_663C */
struct fn_8_663C_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u8 pad_B0[0x14];
    u32 unk_C4;
    u8 pad_C8[0x4];
    u32 unk_CC;
};
struct fn_8_663C_lbl_8_bss_2A8 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};
struct fn_8_663C_lbl_801A6410 {
    u32 unk_0;
};

extern void fn_8_6558(void);
extern void fn_8_6560(void);
extern void fn_8_6568(void);
extern s32 fn_8_6570(void);
extern struct fn_8_663C_lbl_801A6410 lbl_801A6410[];
extern u16 lbl_8_bss_2A8[];
extern u32 lbl_8_data_7E50[];
extern void fn_1_14D728(void *, u32);
extern u32 fn_1_3F8C0(void);
extern u32 fn_1_4630(u32, u32, void *, u32);
extern u32 fn_1_5370(u32, u32);
extern u32 fn_80006E10(u32);
extern u32 fn_80008E84(u32);

void fn_8_663C(struct fn_8_663C_Arg0 *arg0) {
    u32 fzgx_value_;
    u32 fzgx_value;
    u8 *p_lbl_8_data_7E50;
    struct fn_8_663C_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    u32 v0;
    struct { u32 a[3]; } loc_18;
    struct { u32 a[4]; } loc_8;
    u32 t1;
    u32 t2;

    p_lbl_8_data_7E50 = (u8 *)&lbl_8_data_7E50;
    p_lbl_8_bss_2A8 = (struct fn_8_663C_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    fzgx_value = (u32)(fn_8_6558);
    arg0->unk_A8 = fzgx_value;
    arg0->unk_C4 = (u32)(fn_8_6568);
    arg0->unk_CC = (u32)(fn_8_6560);
    arg0->unk_AC = (u32)(fn_8_6570);
    arg0->unk_0 = (arg0->unk_0 | 513);
    fzgx_value_ = ((arg0->unk_0 | 0x200000) | 256);
    arg0->unk_0 = fzgx_value_;
    arg0->unk_0 = (arg0->unk_0 | 32768);
    v0 = (arg0->unk_0 | 0x1000000);
    arg0->unk_0 = v0;
    p_lbl_8_bss_2A8->unk_C = 0;
    fn_1_5370(1, 0);
    t1 = fn_1_3F8C0();
    t2 = fn_80008E84(t1);
    p_lbl_8_bss_2A8->unk_10 = fn_1_4630(lbl_801A6410[0].unk_0, 2592, p_lbl_8_data_7E50 + 3204, 985);
    p_lbl_8_bss_2A8->unk_14 = fn_1_4630(lbl_801A6410[0].unk_0, 2592, p_lbl_8_data_7E50 + 3204, 986);
    loc_18.a[2] = 2;
    *(u16 *)((u8 *)&loc_18 + 0) = 7;
    *(u16 *)((u8 *)&loc_18 + 2) = 31;
    *(u16 *)((u8 *)&loc_18 + 4) = 50;
    loc_8.a[2] = 2;
    *(u16 *)((u8 *)&loc_8 + 0) = 7;
    *(u16 *)((u8 *)&loc_8 + 2) = 27;
    *(u16 *)((u8 *)&loc_8 + 4) = 59;
    fn_80006E10((u32)(p_lbl_8_data_7E50 + 3216));
    fn_1_14D728((void *)&loc_18, p_lbl_8_bss_2A8->unk_10);
    fn_1_14D728((void *)&loc_8, p_lbl_8_bss_2A8->unk_14);
    fn_80006E10((u32)(p_lbl_8_data_7E50 + 3232));
    fn_80008E84(t2);
}
/* fzgx:end fn_8_663C */

/* fzgx:begin fn_8_67B0 */
extern u32 fn_1_3F8C0(void);
extern u32 fn_1_48140(u32);
extern u32 fn_80008E84(u32);
extern u32 fn_8_8C80(u32);

void fn_8_67B0(void) {
    u32 t0, t1, t3;
    t0 = fn_1_3F8C0();
    t1 = fn_80008E84(t0);
    fn_1_48140(148);
    t3 = fn_80008E84(t1);
    fn_8_8C80(t3);
}
/* fzgx:end fn_8_67B0 */

/* fzgx:begin fn_8_6C90 */
#include "rel/title/title.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f64);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(void *, f32);
extern void fn_1_5233C(void);
extern u32 lbl_801A66B4;

#define PF(o) ((o)==0x08 ? 320.0f : (o)==0x0C ? 640.0f : (o)==0x18 ? 150.0f : (o)==0x20 ? 20.0f : (o)==0x24 ? 0.8333333134651184f : (o)==0x34 ? 0.0f : (o)==0x38 ? 1.0f : (o)==0x3C ? 0.5f : (o)==0x40 ? 0.09f : (o)==0x44 ? 5.0f : 255.0f)
#define PD(o) ((o)==0x00 ? 15.0 : 1.0)
#define PU(o) (*(const u32 *)(pool + (o)))

#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_8_bss_3D0;
u32 fzgx_pool_lbl_8_bss_3D0_fill_3D4[91];
u8 lbl_8_bss_540;
u8 fzgx_pool_lbl_8_bss_3D0_gap_541;
u16 fzgx_pool_lbl_8_bss_3D0_gap_541_fill_542;
u32 lbl_8_bss_544[3];
u32 fzgx_obj_lbl_8_bss_550;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_3D0;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_3D0_fill_3D4;
    s = *(u8 *)&lbl_8_bss_540;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_3D0_gap_541;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_3D0_gap_541_fill_542;
    s = *(u8 *)&lbl_8_bss_544;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_550;
}
#pragma section code_type ".text"

void fn_8_6C90(void) {
    struct { s32 value; } n;
    f64 sq;
    f32 t;
    f32 k;
    u32 p;
    union {
        u32 w;
        u8 b[4];
    } u;

    if ((s32)lbl_8_bss_3CC == (s32)fzgx_obj_lbl_8_bss_3D0 - 0x1e) {
        fn_1_A2D84(0xA9120E00);
    }
    if ((f64)(s32)lbl_8_bss_3CC < PD(0x00)) {
        t = (f32)(PD(0x10) - (f32)(s32)lbl_8_bss_3CC / PD(0x00));
        n.value = (s32)(PF(0x08) + (f32)(PF(0x0C) * t));
    } else if ((f64)(s32)lbl_8_bss_3CC > (f64)(s32)fzgx_obj_lbl_8_bss_3D0 - PD(0x00)) {
        t = (f32)(PD(0x10) - (f32)(s32)(fzgx_obj_lbl_8_bss_3D0 - lbl_8_bss_3CC) / PD(0x00));
        n.value = (s32)(PF(0x08) - (f32)(PF(0x0C) * t));
    } else {
        t = PF(0x34);
        n.value = 320;
    }
    sq = (PF(0x38) - t) * (PF(0x38) - t);
    fn_1_49410();
    fn_1_495B0(0x8000u << 16);
    fn_1_49590(PF(0x3C));
    fn_1_495C8(9);
    fn_1_496FC(n.value, PF(0x18));
    fn_1_4954C(PF(0x40));
    if ((s32)lbl_801A66B4 == 5) {
        k = PF(0x38);
        fn_1_4955C(k, k);
    } else {
        k = PF(0x24);
        fn_1_4955C(k, k);
    }
    fn_1_495A0(sq);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(PF(0x44));
    fn_1_4AE0C(*(const char **)(lbl_8_data_81BC + lbl_801A66B4 * 4));
    fn_1_49738(0);
    fn_1_4AE0C(*(const char **)(lbl_8_data_81F0 + lbl_801A66B4 * 4));
    u.w = fzgx_pool_table2[0];
    u.b[3] = (u8)(PF(0x48) * (f32)sq);
    p = u.w;
    fn_1_4D0D4(&p, PF(0x20));
}
#pragma opt_common_subs reset
/* fzgx:end fn_8_6C90 */

/* fzgx:begin fn_8_6F1C */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_8_6F1C_lbl_8_rodata_160 {
    f64 unk_0;
    f32 unk_8;
    f32 unk_C;
    f64 unk_10;
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    f32 unk_24;
    f64 unk_28;
    u8 pad_30[0x4];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    u32 unk_4C;
};

extern struct fn_8_6F1C_lbl_8_rodata_160 lbl_8_rodata_160;
extern s32 lbl_8_bss_3D0[92];
extern s32 lbl_8_bss_3CC;
extern u32 lbl_8_data_8224[6];
extern u32 lbl_8_data_8258[6];
extern s32 lbl_801A66B4;
extern void fn_1_A2D84(u32);
extern u32 fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern u32 fn_1_4D0A0(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);
extern s32 fn_1_5233C;

void fn_8_6F1C(void) {
    struct fn_8_6F1C_lbl_8_rodata_160 *p;
    u32 buf_C;
    u32 buf_8;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f31;
    s32 var_r30;
    s32 count;

    p = &lbl_8_rodata_160;
    if (lbl_8_bss_3CC == lbl_8_bss_3D0[0] - 1) {
        fn_1_A2D84(0xA9120D00U);
    }
    count = lbl_8_bss_3CC;
    if (count < (15.0)) {
        temp_f2 = (f32)((1.0) - (f64)(f32)count / (15.0));
        temp_f0 = (640.0f) * temp_f2;
        var_r30 = (s32)((320.0f) + temp_f0);
    } else if ((f64)count > (f64)lbl_8_bss_3D0[0] - (15.0)) {
        temp_f2 = (f32)((1.0) - (f64)(f32)(lbl_8_bss_3D0[0] - count) / (15.0));
        temp_f0 = (640.0f) * temp_f2;
        var_r30 = (s32)((320.0f) - temp_f0);
    } else {
        temp_f2 = (0.0f);
        var_r30 = 0x140;
    }
    temp_f0 = (1.0f) - temp_f2;
    temp_f31 = temp_f0 * temp_f0;
    fn_1_49410();
    fn_1_495B0(0x80000000U);
    fn_1_49590((0.5f));
    fn_1_495C8(9);
    fn_1_496FC((f32)var_r30, (150.0f));
    fn_1_4954C((0.0900000036f));
    if (lbl_801A66B4 == 5) {
        fn_1_4955C((1.0f), (1.0f));
    } else {
        fn_1_4955C((0.833333313f), (0.833333313f));
    }
    fn_1_495A0(temp_f31);
    fn_1_4D0A0();
    fn_1_49738((u32)&fn_1_5233C);
    fn_1_49748((5.0f));
    fn_1_4AE0C((const char *)lbl_8_data_8224[lbl_801A66B4]);
    fn_1_49738(0);
    fn_1_4AE0C((const char *)lbl_8_data_8258[lbl_801A66B4]);
    buf_8 = fzgx_pool_table4[0];
    *(u8 *)((u8 *)&buf_8 + 3) = (u8)((255.0f) * temp_f31);
    buf_C = buf_8;
    fn_1_4D0D4(&buf_C, (20.0f));
}
/* fzgx:end fn_8_6F1C */

/* fzgx:begin fn_8_7734 */
#include "rel/title/title.h"

typedef struct { u8 r, g, b, a; } Color_8_7734;

extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(Color_8_7734 *, f32);
extern void fn_1_5233C(void);
extern u32 lbl_801A66B4;

#pragma section code_type ".fzgxpool"
void fn_8_7734_primer_a(f64 *o, f32 *p, s32 i) {
    o[0] = 15.0;
    p[0] = 320.0f;
    p[1] = 640.0f;
    o[1] = 1.0;
    p[2] = 150.0f;
    p[3] = 0.1f;
    p[4] = 20.0f;
    p[5] = 0.8333333f;
    p[6] = i;
}
static const u32 fzgx_pool_table_b0[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_b0(void) { const u32 *volatile cp; cp = fzgx_pool_table_b0; }  /* fzgx-allow: S2 pool primer sink */
void fn_8_7734_primer_b(f32 *p) {
    p[0] = 0.0f;
    p[1] = 1.0f;
    p[2] = 0.5f;
    p[3] = 0.09f;
    p[4] = 5.0f;
    p[5] = 255.0f;
}
static const u32 fzgx_pool_table_tail[3] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_tail(void) { const u32 *volatile cp; cp = fzgx_pool_table_tail; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

void fn_8_7734(void) {
    s32 x;
    f32 t;
    f32 a;
    Color_8_7734 c;
    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0 - 1) {
        fn_1_A2D84(0xA9120600);
    }
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - (s32)lbl_8_bss_3CC) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    a = (1.0f - t) * (1.0f - t);
    fn_1_49410();
    fn_1_495B0((u32)1 << 31);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x, 150.0f);
    fn_1_4954C(0.09f);
    if ((s32)lbl_801A66B4 == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(a);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((const char **)lbl_8_data_8458)[lbl_801A66B4]);
    fn_1_49738(0);
    fn_1_4AE0C(((const char **)lbl_8_data_84B8)[lbl_801A66B4]);
    {
        Color_8_7734 base = { 0xFF, 0xFF, 0xFF, 0x00 };
        base.a = 255.0f * a;
        c = base;
        fn_1_4D0D4(&c, 20.0f);
    }
}
/* fzgx:end fn_8_7734 */

/* fzgx:begin fn_8_79C0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[4] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table5[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
struct fn_8_79C0_lbl_8_bss_3D0 {
    u32 unk_0;
};
struct fn_8_79C0_lbl_8_bss_3CC {
    u32 unk_0;
};
struct fn_8_79C0_lbl_8_rodata_160 {
    f64 unk_0;
    f32 unk_8;
    f32 unk_C;
    f64 unk_10;
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    f32 unk_24;
    f64 unk_28;
    u8 pad_30[0x4];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    u8 pad_4C[0x10];
    u32 unk_5C;
};
struct fn_8_79C0_lbl_8_data_84EC {
    u32 unk_0[1];
};
struct fn_8_79C0_lbl_8_data_8554 {
    u32 unk_0[1];
};
extern struct fn_8_79C0_lbl_8_bss_3CC lbl_8_bss_3CC;
extern struct fn_8_79C0_lbl_8_bss_3D0 lbl_8_bss_3D0;
extern struct fn_8_79C0_lbl_8_data_84EC lbl_8_data_84EC;
extern struct fn_8_79C0_lbl_8_data_8554 lbl_8_data_8554;
extern struct fn_8_79C0_lbl_8_rodata_160 lbl_8_rodata_160;
extern u32 lbl_801A66B4;
extern void fn_1_A2D84(u32);
extern u32 fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern u32 fn_1_4D0A0(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);

struct FzgxCopy_4 { u32 words[1]; };
extern s32 fn_1_5233C;

void fn_8_79C0(void) {
    struct fn_8_79C0_lbl_8_rodata_160 *r;
    u32 spC;
    struct FzgxCopy_4 loc_8;
    f32 temp_f0;
    f32 temp_f31;
    f32 var_f2;
    f32 tmp;
    s32 var_r30;

    r = &lbl_8_rodata_160;
    if ((s32) lbl_8_bss_3CC.unk_0 == (s32) (lbl_8_bss_3D0.unk_0 - 1)) {
        fn_1_A2D84((u32)(0xA9120800U));
    }
    if ((f64)(s32) lbl_8_bss_3CC.unk_0 < (15.0)) {
        var_f2 = (f32) ((1.0) - (f32)(s32) lbl_8_bss_3CC.unk_0 / (15.0));
        tmp = (640.0f) * var_f2;
        var_r30 = (s32) ((320.0f) + tmp);
    } else if ((f64)(s32) lbl_8_bss_3CC.unk_0 > (f64)(s32) lbl_8_bss_3D0.unk_0 - (15.0)) {
        var_f2 = (f32) ((1.0) - (f32)(s32) (lbl_8_bss_3D0.unk_0 - lbl_8_bss_3CC.unk_0) / (15.0));
        tmp = (640.0f) * var_f2;
        var_r30 = (s32) ((320.0f) - tmp);
    } else {
        var_f2 = (0.0f);
        var_r30 = 0x140;
    }
    temp_f0 = (1.0f) - var_f2;
    temp_f31 = temp_f0 * temp_f0;
    fn_1_49410();
    fn_1_495B0((u32)(0x80000000U));
    fn_1_49590((f32)((0.5f)));
    fn_1_495C8((u8)(9U));
    fn_1_496FC((f32)((f32) var_r30), (f32)((150.0f)));
    fn_1_4954C((f32)((0.0900000036f)));
    if ((s32) lbl_801A66B4 == 5) {
        fn_1_4955C((f32)((1.0f)), (f32)((1.0f)));
    } else {
        fn_1_4955C((f32)((0.833333313f)), (f32)((0.833333313f)));
    }
    fn_1_495A0((f32)(temp_f31));
    fn_1_4D0A0();
    fn_1_49738((u32)((u32)(&fn_1_5233C)));
    fn_1_49748((f32)((5.0f)));
    fn_1_4AE0C((const char *)(((u32 *)&lbl_8_data_84EC)[lbl_801A66B4]));
    fn_1_49738((u32)(0U));
    fn_1_4AE0C((const char *)(((u32 *)&lbl_8_data_8554)[lbl_801A66B4]));
    loc_8.words[0] = fzgx_pool_table5[0];
    (*(s8 *)((u8 *)(&loc_8) + 3)) = (s8) ((255.0f) * temp_f31);
    spC = loc_8.words[0];
    fn_1_4D0D4((u32 *)(&spC), (f32)((20.0f)));
}
/* fzgx:end fn_8_79C0 */

/* fzgx:begin fn_8_81AC */
#include "rel/title/title.h"

typedef struct { u8 r, g, b, a; } Color8;
extern s32 lbl_801A66B4;
extern u32 fn_8_CC4C(u32, u32);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(Color8 *, f32);

#pragma section code_type ".fzgxpool"
void fn_8_81AC_primerA(f64 *d, f32 *f, s32 i) {
    d[0] = 15.0;
    f[0] = 320.0f;
    f[1] = 640.0f;
    d[1] = 1.0;
    f[2] = 150.0f;
    f[3] = 0.1f;
    f[4] = 20.0f;
    f[5] = 0.8333333f;
    f[6] = i;
}
static const u32 fzgx_pool_table81AC_b0[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep81AC_b0(void) { const u32 *volatile cp; cp = fzgx_pool_table81AC_b0; }  /* fzgx-allow: S2 pool primer sink */
void fn_8_81AC_primerB(f32 *f) {
    f[0] = 0.0f;
    f[1] = 1.0f;
    f[2] = 0.5f;
    f[3] = 0.09f;
    f[4] = 5.0f;
    f[5] = 255.0f;
}
static const u32 fzgx_pool_table81AC_mid[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep81AC_mid(void) { const u32 *volatile cp; cp = fzgx_pool_table81AC_mid; }  /* fzgx-allow: S2 pool primer sink */
void fn_8_81AC_primerC(f32 *f) {
    f[0] = 0.3f;
}
static const u32 fzgx_pool_table81AC_tail[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep81AC_tail(void) { const u32 *volatile cp; cp = fzgx_pool_table81AC_tail; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
void fn_8_81AC(void) {
    f32 t;
    f32 alpha;
    s32 x;
    if ((s32)lbl_8_bss_3CC == (s32)(lbl_8_bss_3D0.unk_0 - 1)) {
        fn_1_A2D84(0xA9120C00);
    }
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)(s32)(lbl_8_bss_3D0.unk_0 - lbl_8_bss_3CC) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    alpha = (1.0f - t) * (1.0f - t);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x, 150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_4AE0C(((const char **)lbl_8_data_87DC)[lbl_801A66B4]);
    fn_1_4AE0C(((const char **)lbl_8_data_8840)[lbl_801A66B4]);
    {
        Color8 c2;
        Color8 init = { 0xFF, 0xFF, 0xFF, 0x00 };
        init.a = 255.0f * alpha;
        c2 = init;
        fn_1_4D0D4(&c2, 20.0f);
    }
    if ((s32)lbl_8_bss_3CC < 240 && (s32)lbl_8_bss_3CC > 0) {
        fn_8_CC4C(505, 394);
    }
}
/* fzgx:end fn_8_81AC */
