/* Non-matching: best partial attempt (78.65% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"
typedef struct {
    u8 pad_0[0x98]; u8 unk_98; u8 pad_99[0xF];
    f32 unk_A8; f32 unk_AC; f32 unk_B0;
    u8 pad_B4[0x4E0 - 0xB4];
} Sig_fn_1_13198C_EntryObj;
typedef struct Sig_fn_8006F038_Vec3 { f32 x; f32 y; f32 z; } Sig_fn_8006F038_Vec3;
struct fn_10_19C90_lbl_1_bss_8B3A0_E_E32 { s16 unk_0; u8 pad_2[0x1E]; };
struct fn_10_19C90_lbl_1_bss_8B3A0 {
    u8 pad_0[0xE];
    struct fn_10_19C90_lbl_1_bss_8B3A0_E_E32 unk_E[1];
};
struct fn_10_19C90_Copy820 { u32 a[205]; };
extern const f32 lbl_10_rodata_158[19];
extern struct fn_10_19C90_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern f32 lbl_8006D188(u32);
extern s16 fn_10_0(s16 *, s16 *, int, int);
extern s16 fn_1_12C930(s16);
extern void fn_1_13198C(s16, Sig_fn_8006F038_Vec3, Sig_fn_8006F038_Vec3, Sig_fn_1_13198C_EntryObj *, Sig_fn_1_13198C_EntryObj *, s32);
s32 fn_10_19C90(void *arg0, u32 arg1, u32 arg2, u32 arg3) {
    const f32 *p_lbl_10_rodata_158;
    s16 index;
    s32 valid;
    u8 *v3;
    f32 v7;
    f32 v8;
    s16 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    struct fn_10_19C90_Copy820 loc_3C;
    struct { f32 a[6]; } loc_18;
    s16 loc_A;
    s16 loc_8;
    f32 t1;
    f32 t2;
    p_lbl_10_rodata_158 = lbl_10_rodata_158;
    index = fn_1_12C930(lbl_1_bss_8B3A0.unk_E[*(s16 *)arg0].unk_0);
    loc_3C = *(struct fn_10_19C90_Copy820 *)(p_lbl_10_rodata_158 + 0x83c / 4);
    if ((u32)index > 40) valid = 0;
    else valid = index >= 0;
    if (valid) v3 = (u8 *)&loc_3C + index * 20;
    else v3 = (u8 *)&loc_3C;
    t1 = lbl_8006D188((s32)(p_lbl_10_rodata_158[0x430 / 4] * (f32)*(s16 *)(v3 + 0)));
    v7 = *(f32 *)(v3 + 8);
    v8 = *(f32 *)(v3 + 4) * (-t1);
    loc_18.a[3] = v8;
    loc_18.a[4] = v7;
    t2 = lbl_8006D188((s16)((s32)(p_lbl_10_rodata_158[0x430 / 4] * (f32)*(s16 *)(v3 + 0)) + 16384));
    v11 = *(s16 *)arg0;
    v12 = *(f32 *)(v3 + 12);
    v13 = *(f32 *)(v3 + 4) * (-t2);
    v14 = *(f32 *)(v3 + 16);
    loc_18.a[5] = v13;
    loc_18.a[0] = v12;
    loc_18.a[1] = v14;
    loc_18.a[2] = p_lbl_10_rodata_158[0x4c / 4];
    if ((s32)((Obj_10_bss_5560C *)((u8 *)&lbl_10_bss_5560C + v11 * 20))->unk_12 == 4) {
        s32 flag;
        fn_10_0(&loc_A, &loc_8, lbl_1_bss_8B3A0.unk_E[v11].unk_0, 0);
        flag = ((Obj_10_bss_1C *)((u8 *)&lbl_10_bss_1C + loc_8 * 152 + (loc_A << 3)))->unk_4 >> 31;
        fn_1_13198C(*(s16 *)arg0, *(Sig_fn_8006F038_Vec3 *)&loc_18.a[3], *(Sig_fn_8006F038_Vec3 *)&loc_18.a[0],
            (Sig_fn_1_13198C_EntryObj *)lbl_10_bss_51B7C,
            (Sig_fn_1_13198C_EntryObj *)lbl_10_bss_52EFC, flag);
    }
    return 0;
}
