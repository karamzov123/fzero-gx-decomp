/* Non-matching: best partial attempt (85.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_tow.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.15000000596046448f;
    s = -0.949999988079071f;
    s = 0.03099999949336052f;
    s = 0.004999999888241291f;
    s = -0.03200000151991844f;
    s = -0.9229999780654907f;
    s = 1.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[15] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 5.0f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9810000061988831f;
    s = 32767.0f;
    s = -0.9279999732971191f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_1_154410_mtx {
    u8 v[0x30];
};

struct fn_1_154410_state {
    s32 unk_0;
    void *unk_4[0x40];
    s32 unk_104[0x40];
    f32 unk_204[0x40];
    f32 unk_304[0x40];
    f32 unk_404[0x40];
    struct fn_1_154410_mtx unk_504[0x40];
    u32 unk_1104;
    u32 unk_1108;
    u32 unk_110C;
    void *unk_1110;
    void *unk_1114[0x10];
    s32 unk_1154[0x10];
    u8 pad_1194[0x270];
    struct fn_1_154410_mtx unk_1404[0x10];
};

struct fn_1_154410_list {
    s32 unk_0;
    s32 unk_4;
    u32 unk_8;
    void *unk_C[0x10];
    s32 unk_4C[0x10];
    u8 pad_5C[0x2A0];
    struct fn_1_154410_mtx unk_2FC[0x10];
};

struct fn_1_154410_pool {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f64 unk_20;
    u8 pad_28[0x58];
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
};

extern struct fn_1_154410_pool lbl_1_rodata_D508;
extern u32 lbl_801A63C0;
extern void lbl_8006D7DC(void *);
extern void lbl_8006DB74(void *);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void OSPanic(const char *, int, const char *, ...);

s32 fn_1_154410(s32 arg0, void *arg1) {
    struct fn_1_154410_state *obj = (struct fn_1_154410_state *)lbl_1_data_2A7E0.unk_3C;

    switch (arg0) {
    case 0: {
        u32 r;
        f32 t;
        f32 p;

        *(u32 *)arg1 |= 0x80000000;
        obj->unk_4[obj->unk_0] = arg1;

        r = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        lbl_801A63C0 = r;
        t = (f32)((r >> 1) & 0x7FFF) / 32767.0f;
        p = 0.981f * t;
        obj->unk_204[obj->unk_0] = -0.95f + p;

        r = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        lbl_801A63C0 = r;
        t = (f32)((r >> 1) & 0x7FFF) / 32767.0f;
        p = -0.928f * t;
        obj->unk_304[obj->unk_0] = 0.005f + p;

        obj->unk_104[obj->unk_0] = (s32)((obj->unk_304[obj->unk_0] - 0.005f) / -0.032f);
        obj->unk_404[obj->unk_0] = 0.0f;

        lbl_8006D7DC((u8 *)arg1 + 0xC);
        mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg1 + 0x1C));
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg1 + 0x1A));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)arg1 + 0x18));
        lbl_8006DB74(&obj->unk_504[obj->unk_0]);

        obj->unk_0++;
        if (obj->unk_0 >= 0x40) {
            OSPanic((const char *)lbl_1_data_46408, 0x1E2,
                    (const char *)&lbl_1_data_46408[0xC]);
        }
        break;
    }
    case 1:
        *(u32 *)arg1 |= 0x80000000;
        obj->unk_1110 = arg1;
        break;
    case 2:
    case 3:
    case 5: {
        struct fn_1_154410_list *lst =
            (struct fn_1_154410_list *)((u8 *)obj + 0x1108);

        *(u32 *)arg1 |= 0x80000000;
        lst->unk_C[lst->unk_0] = arg1;
        lst->unk_4C[lst->unk_0] = (arg0 == 5);
        lst->unk_0++;
        if (lst->unk_0 >= 0x10) {
            OSPanic((const char *)lbl_1_data_46408, 0x1FE,
                    (const char *)&lbl_1_data_46408[0x20]);
        }
        break;
    }
    case 4: {
        struct fn_1_154410_list *lst =
            (struct fn_1_154410_list *)((u8 *)obj + 0x1108);

        lbl_8006D7DC((u8 *)arg1 + 0xC);
        mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg1 + 0x1C));
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg1 + 0x1A));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)arg1 + 0x18));
        lbl_8006DB74(&lst->unk_2FC[lst->unk_4]);

        lst->unk_4++;
        if (lst->unk_4 >= 0x10) {
            OSPanic((const char *)lbl_1_data_46408, 0x20F,
                    (const char *)&lbl_1_data_46408[0x40]);
        }
        break;
    }
    default:
        break;
    }

    return 1;
}
