/* Non-matching: best partial attempt (78.51% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"
struct Sig_fn_8003432C_fn_8003432C_Arg2 { u32 unk_0; };
struct fn_1_D0F60_lbl_1_rodata_6078 {
 f32 unk_0; u8 pad_4[4]; f64 unk_8; u32 unk_10; u32 unk_14;
 f32 unk_18; u8 pad_1C[4]; f64 unk_20;
};
extern struct fn_1_D0F60_lbl_1_rodata_6078 lbl_1_rodata_6078;
extern void fn_1_A9868(void);
extern u16 fn_1_A5DB0(void);
extern u32 fn_1_A9B70(s16, s32, s16, s32, void *);
extern u32 fn_1_A9FFC(s16, s16, s16, s16, void *);
extern u32 fn_8003432C(u16, u16, struct Sig_fn_8003432C_fn_8003432C_Arg2 *);
extern void fn_1_AA538(void);
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_D0F60(void) {
 struct fn_1_D0F60_lbl_1_rodata_6078 *p_lbl_1_rodata_6078;
 s32 v0, v1, v2, v4, v5, v6, v7;
 s32 v8, v9, v10;
 u16 *v11, *px;
 s32 v12, v13, v15, v16, v17, v18, v19;
 s16 v20, v21;
 s32 v25;
 s32 valid;
 struct { u32 c8, cC; struct {u8 r,g,b,a;} c10, c14; struct Sig_fn_8003432C_fn_8003432C_Arg2 c18; } frame;
#define loc_10 frame.c10
#define temp frame.c14
#define loc_18 frame.c18
#define loc_C frame.cC
#define loc_8 frame.c8
 v0 = lbl_1_data_3D648.unk_10;
 p_lbl_1_rodata_6078 = &lbl_1_rodata_6078;
 v1 = lbl_1_data_3D648.unk_12;
 v2 = lbl_1_data_3D648.unk_16;
 v4 = v0 / 2;
 v5 = lbl_1_data_3D648.unk_18;
 v6 = lbl_1_data_3D648.unk_14;
 v7 = v1 / 2;
 fn_1_A9868();
 v12 = -v4;
 v13 = v12 * v6;
 v10 = -v7;
 px = (u16 *)&lbl_1_data_3D648.unk_4;
 v11 = (u16 *)&lbl_1_data_3D648.unk_6;
 while (v12 <= v4) {
  v17 = v10 * v6;
  v15 = v13 + 1;
  v16 = v10;
  v15 = v2 + v15;
  while (v16 <= v7) {
   v18 = *px + v12;
   if ((f32)v18 > 639.0f) valid = 0;
   else valid = v18 >= 0;
   if (valid) {
    s32 bound = fn_1_A5DB0() - 1;
    v19 = *v11 + v16;
    if (v19 > bound) valid = 0;
    else valid = v19 >= 0;
    if (valid) {
     fn_8003432C((u16)(*px + v12), (u16)v19, &loc_18);
     v19 = v17 + 1;
     v19 = v5 + v19;
     temp.a = loc_18.unk_0 >> 24;
     v20 = v6 - 1;
     temp.r = loc_18.unk_0 >> 16;
     temp.g = loc_18.unk_0 >> 8;
     temp.b = loc_18.unk_0;
     loc_10 = temp;
     fn_1_A9FFC((s16)v15, (s16)v19, v20, v20, &loc_10);
     if (v12 == 0 && v16 == 0) {
      v21 = v6 + 2;
      loc_C = p_lbl_1_rodata_6078->unk_10;
      fn_1_A9B70((s16)(v2 - 1), (s16)(v5 - 1), v21, v21, &loc_C);
     }
    }
   }
   v17 += v6;
   v16++;
  }
  v13 += v6;
  v12++;
 }
 loc_8 = p_lbl_1_rodata_6078->unk_14;
 v25 = (s32)(480.0f * (f32)(v1 + 2) / (f32)(u32)fn_1_A5DB0());
 fn_1_A9B70((s16)(*px - v4 - 1),
 (s32)(480.0f * (f32)(*v11 - v7 - 1) / (f32)(u32)fn_1_A5DB0()),
 (s16)(v0 + 2), v25, &loc_8);
 fn_1_AA538();
}
