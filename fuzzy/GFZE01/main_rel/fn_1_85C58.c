/* Non-matching: best partial attempt (95.99% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"
extern const f32 lbl_1_rodata_3508[4];
extern int fn_1_20994(void *, f32 *);
extern s16 fn_1_7B054(void);
extern void *fn_1_14F04(void);
extern void lbl_8006DBAC(void *);
extern void fn_1_17920(int, int, f32);
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32, f32, f32);
typedef struct { f32 a[5]; } FloatTable;
typedef struct { u8 a[5]; } ByteTable;
struct fn_1_85C58_lbl_1_rodata_3508 {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x64];
    f64 unk_78;
    u8 pad_80[0x4E8];
    f32 unk_568;
    u8 pad_56C[0x3C];
    f32 unk_5A8;
    u8 pad_5AC[0xDC];
    FloatTable unk_688;
    FloatTable unk_69C;
    ByteTable unk_6B0;
    u8 pad_6B5[3];
    FloatTable unk_6B8;
    FloatTable unk_6CC;
};
#pragma opt_propagation on
static inline f32 fn_1_85C58_array_read(s32 index, f32 *array) { return array[index]; }
#pragma opt_loop_invariants on
static inline f32 fn_1_85C58_operand(f32 left, f32 right) { return left * right; }
#pragma opt_strength_reduction off
static inline f32 fn_1_85C58_operand_(f32 left, f32 right) { left *= right; return left; }
void fn_1_85C58(s32 arg0, f32 arg1) {
    f32 fzgx_live;
    struct fn_1_85C58_lbl_1_rodata_3508 *p_lbl_1_rodata_3508;
    FloatTable loc_5C;
    FloatTable loc_48;
    FloatTable loc_34;
    FloatTable loc_20;
    f32 loc_14[3];
    ByteTable loc_C;
    f32 loc_8;
    u16 v8;
    u32 v11;
    struct { f32 value; } v16;
    f32 v9_2;
    u8 *v13;
    int v17;
    f32 fzgx_live_2;
    u8 v18;
    f32 v22;
    f32 v9;
    f32 * lab_t1;
    p_lbl_1_rodata_3508 = (struct fn_1_85C58_lbl_1_rodata_3508 *)lbl_1_rodata_3508;
    loc_5C = p_lbl_1_rodata_3508->unk_688;
    loc_48 = p_lbl_1_rodata_3508->unk_69C;
    loc_C = p_lbl_1_rodata_3508->unk_6B0;
    loc_34 = p_lbl_1_rodata_3508->unk_6B8;
    loc_20 = p_lbl_1_rodata_3508->unk_6CC;
    if (*(s16 *)&lbl_1_bss_960 == 9 && fn_1_7B054() == 37) {
        v8 = 1;
    } else if (*(s16 *)&lbl_1_bss_960 == 9 && fn_1_7B054() == 39) {
        v8 = 2;
    } else if (*(s16 *)&lbl_1_bss_960 == 9 && fn_1_7B054() == 43) {
        v8 = 3;
    } else if (fn_1_7B054() == 45) {
        v8 = 4;
    } else {
        v8 = 0;
    }
    if (lbl_1_bss_3BE0 != 0) {
        v13 = (u8 *)fn_1_14F04() + 0x48;
        v11 = v8;
        v16.value = fn_1_85C58_array_read(v11, loc_5C.a) + (f32)((f32)arg0 * fn_1_85C58_array_read(v11, loc_48.a));
        fzgx_live = p_lbl_1_rodata_3508->unk_10;
        loc_14[0] = fzgx_live;
        fzgx_live = p_lbl_1_rodata_3508->unk_10;
        loc_14[1] = fzgx_live;
        loc_14[2] = v16.value;
        lab_t1 = &loc_8;
        v17 = fn_1_20994(loc_14, lab_t1);
        fn_1_17920(v17, 0, loc_8);
        lbl_8006DBAC(v13);
        if (lbl_1_bss_3BE0->unk_7D != 0 && v17 == 0 && loc_8 < p_lbl_1_rodata_3508->unk_10) {
            fzgx_live = p_lbl_1_rodata_3508->unk_10;
            v9 = fzgx_live;
            lbl_8006E0B4(v9, v9, v16.value);
        }
        v18 = loc_C.a[v8];
        if (v18 > 1) {
            fzgx_live = p_lbl_1_rodata_3508->unk_10;
            v22 = fn_1_85C58_operand_((fzgx_live), ((*(f32 *)(v13 + 104) - arg1)));
            v9 = (f32)(arg0 % (s32)v18) / (f32)(v18 - 1);
            v9 = v22 + (f32)(fn_1_85C58_array_read(v11, loc_20.a) * (f32)(fn_1_85C58_array_read(v11, loc_34.a) * (f32)(fn_1_85C58_operand((arg1), ((p_lbl_1_rodata_3508->unk_5A8 - v9))))));
            fzgx_live = p_lbl_1_rodata_3508->unk_10;
            (void) fzgx_live;  /* fzgx: keeps the web at its definition */
            lbl_8006E0B4(v9, p_lbl_1_rodata_3508->unk_568, fzgx_live);
        } else {
            fzgx_live_2 = p_lbl_1_rodata_3508->unk_10;
            v9_2 = fzgx_live_2;
            lbl_8006E0B4(v9_2, p_lbl_1_rodata_3508->unk_568, v9_2);
        }
    } else {
        lbl_8006D758();
    }
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

#pragma opt_propagation reset

