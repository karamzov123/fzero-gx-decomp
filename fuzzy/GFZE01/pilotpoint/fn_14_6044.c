/* Non-matching: best partial attempt (75.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/pilotpoint/pilotpoint.h"

struct fn_14_6044_lbl_14_rodata_0 {
    u8 pad_0[0x30];
    f32 unk_30;
    u8 pad_34[0x2C];
    f64 unk_60;
    u8 pad_68[0xA8];
    f64 unk_110;
    u8 pad_118[0xB8];
    u32 unk_1D0;
    u32 unk_1D4;
    f32 unk_1D8;
    f32 unk_1DC;
    f32 unk_1E0;
    f32 unk_1E4;
    f32 unk_1E8;
};
struct fn_14_6044_data {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x18];
    u32 unk_30;
    u8 pad_34[8];
    u32 unk_3C;
    u8 pad_40[0x10];
    u32 unk_50;
    u32 unk_54;
};
extern struct fn_14_6044_lbl_14_rodata_0 lbl_14_rodata_0;
extern struct fn_14_6044_data lbl_1_rodata_26F8;
extern u16 fn_1_A5DB0(void);
extern s16 fn_1_14F344(s16);
extern void fn_1_8D3F8(void *, void *, void *, void *);
extern void fn_14_3AE8(void);
extern void fn_14_3DF0(void);
extern void fn_14_600C(void);
extern void fn_14_46D4(s32, s32, s32, s32);
extern void *lbl_14_bss_8348;
extern void *lbl_14_bss_834C;

void fn_14_6044(s32 arg0, s32 arg1) {
    struct fn_14_6044_lbl_14_rodata_0 *p_lbl_14_rodata_0;
    s16 v0;
    s16 v1;
    u32 v2;
    f32 v3;
    f64 v4;
    u32 v5;
    f32 v6;
    f32 v7;
    u32 v8;
    u32 v9;
    struct fn_14_6044_data loc_C;
    s16 loc_A;
    s16 loc_8;
    u16 t0;
    s16 i;
    Obj_14_bss_110 *p;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    f32 f50;
    f32 f1;
    f64 bias;
    f32 save;
    u8 *q;
    s32 choice;
    loc_A = 0;
    p_lbl_14_rodata_0 = (struct fn_14_6044_lbl_14_rodata_0 *)&lbl_14_rodata_0;
    loc_8 = 0;
    t0 = fn_1_A5DB0();
    v0 = (s16)arg1;
    v1 = (s16)arg0;
    v2 = v1 + 514;
    v3 = (f32)((f32)(u32)t0 / p_lbl_14_rodata_0->unk_1D8);
    v4 = p_lbl_14_rodata_0->unk_60;
    v5 = (u32)&lbl_1_rodata_26F8;
    v6 = p_lbl_14_rodata_0->unk_1DC * v3;
    lbl_14_bss_92E8.unk_0 = v2;
    lbl_14_bss_92E8.unk_4 = 62;
    v7 = (f32)(v0 + 16) * v3;
    lbl_14_bss_92E8.unk_6 = (s32)v6;
    lbl_14_bss_92E8.unk_2 = (s32)v7;
    loc_C = lbl_1_rodata_26F8;
    a = v0 + 49;
    b = v1 + 46;
    c = v1 + 545;
    d = v0 + 121;
    f50 = p_lbl_14_rodata_0->unk_1E0;
    f1 = p_lbl_14_rodata_0->unk_30;
    bias = p_lbl_14_rodata_0->unk_60;
    loc_C.unk_8 = (f32)a;
    p = (Obj_14_bss_110 *)&lbl_14_bss_110;
    q = (u8 *)p;
    i = 0;
    while ((u16)i < 8) {
        s32 n = (s16)i - 1;
        s32 pos = b + n * 78 + (n / 2) * 10;
        loc_C.unk_4 = (f32)pos;
        loc_C.unk_C = f50;
        loc_C.unk_14 = f1;
        loc_C.unk_10 = f1;
        if (i == p->unk_4) loc_C.unk_C = f50 - f1;
        loc_C.unk_3C = p_lbl_14_rodata_0->unk_1D0;
        if ((*(u32 *)(q + 12) & 1) || !((*(u32 *)(q + 12) & 4) ? 1 : ((*(u32 *)(q + 12) & 8) ? (choice = 15000) : ((*(u32 *)(q + 12) & 16) ? (choice = 20000) : (choice = -1)), (s16)choice <= 99900))) {
            loc_C.unk_3C = p_lbl_14_rodata_0->unk_1D4;
        }
        if (*(u32 *)(q + 12) & 8) {
            save = loc_C.unk_8;
            if (fn_1_14F344(*(s16 *)(q + 8)) == 0) loc_C.unk_8 += p_lbl_14_rodata_0->unk_1E4;
            if (fn_1_14F344(*(s16 *)(q + 8)) == 1) loc_C.unk_8 += p_lbl_14_rodata_0->unk_1E8;
            fn_1_8D3F8((u8 *)lbl_14_bss_8348 + loc_A * 100, &loc_C, (void *)fn_14_3AE8, &loc_A);
            loc_C.unk_8 = save;
            loc_A++;
        }
        if (*(u32 *)(q + 12) & 16) {
            loc_C.unk_4 = (f32)c;
            loc_C.unk_30 |= 0x4000000;
            loc_C.unk_50 = (u32)fn_14_600C;
            fn_1_8D3F8((u8 *)lbl_14_bss_834C + loc_8 * 100, &loc_C, (void *)fn_14_3DF0, &loc_8);
            loc_8++;
        }
        if (i == p->unk_4) {
            if (*(u32 *)(q + 12) & 4) {
                fn_14_46D4((s16)(v1 + 167), (s16)d, (s32)(f1 + loc_C.unk_C), 1);
            } else {
                fn_14_46D4((s32)loc_C.unk_4, (s32)loc_C.unk_8, (s32)(f1 + loc_C.unk_C), 0);
            }
        }
        q += 8;
        i++;
    }
}
