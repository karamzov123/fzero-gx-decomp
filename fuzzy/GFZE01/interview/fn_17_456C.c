/* Non-matching: best partial attempt (96.99% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"
struct Sig_fn_80071268_fn_80071268_Entry { void *unk_0; void *unk_4; };
struct Sig_fn_80071268_fn_80071268_Arg0 { s32 count; u8 pad_4[4]; struct Sig_fn_80071268_fn_80071268_Entry *entries; };
typedef struct { f32 x,y,z; } Position;
struct InterviewState456C {
 u8 pad_0[0x88]; s32 unk_88; u32 unk_8C; u8 pad_90[0x54];
 struct Sig_fn_80071268_fn_80071268_Arg0 *unk_E4[1];
};
struct InterviewObject456C { u8 pad_0[0xA0]; s16 unk_A0; u8 pad_A2[6]; Position unk_A8; };
struct InterviewData456C { s32 unk_0; u8 pad_4[8]; s16 unk_C; };
struct fn_17_456C_lbl_17_bss_0 {
 u8 pad_0[0x58]; u32 unk_58; u8 pad_5C[4]; s32 unk_60;
 u8 pad_64[8]; s16 unk_6C; u8 pad_6E[0x6A]; struct InterviewState456C *unk_D8;
 u8 pad_DC[0xBC]; struct InterviewObject456C *unk_198;
};
struct fn_17_456C_lbl_17_rodata_0 {
 u8 pad_0[0x68]; f64 unk_68; u8 pad_70[0x154];
 Position unk_1C4; Position unk_1D0; Position unk_1DC;
 f32 unk_1E8;
 f32 unk_1EC;
 f32 unk_1F0;
 f32 unk_1F4;
 f32 unk_1F8;
 f32 unk_1FC;
};
extern struct fn_17_456C_lbl_17_rodata_0 lbl_17_rodata_0;
extern void *fn_80071268(struct Sig_fn_80071268_fn_80071268_Arg0 *, void *);
extern void lbl_8006D9D8(Position *);
extern void fn_80072558(void);
extern void **fn_1_5448C(void *);
extern s32 fn_1_548EC(void **);
extern void fn_1_556B8(void *);
extern void fn_1_92530(void *);
#pragma opt_loop_invariants off
#pragma opt_dead_assignments on
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
void fn_17_456C(void) {
 struct fn_17_456C_lbl_17_rodata_0 *p = &lbl_17_rodata_0;
 struct fn_17_456C_lbl_17_bss_0 *b = (struct fn_17_456C_lbl_17_bss_0 *)&lbl_17_bss_0;
 struct InterviewState456C *state = b->unk_D8;
 s32 mode = state->unk_88;
 if ((mode == 8 && b->unk_6C == 15) || (mode == 7 && b->unk_6C == 8) || (mode == 35 && b->unk_6C == 7)) {
  if (mode == 7) {
   void *obj = fn_80071268(((state->unk_8C)[state->unk_E4]), lbl_17_data_640A0);
   if (obj) {
    s32 i;
    for (i = 0; i < 30; i++) {
     s16 row = i / 10;
     Position pos = p->unk_1C4;
     pos.x = 1.5f - (f32)(0.3f * (f32)(i - row * 10));
     pos.z = -0.15f + (f32)(0.3f * (f32)row);
     { Position copy = pos; lbl_8006D9D8(&copy); }
     fn_80072558();
     fn_1_548EC(fn_1_5448C((u8 *)obj + 8));
     fn_1_556B8(obj);
    }
   }
  } else if (0x400000 & b->unk_58) {
   struct InterviewObject456C *obj = b->unk_198;
   if (mode == 8) {
    s16 i;
    obj->unk_A0 = -32768;
    for (i = 0; i < 144; i++) {
     s16 row = i / 18;
     Position pos = p->unk_1D0;
     pos.x = 7.200000286102295f - (f32)(0.8f * (f32)(i - row * 18));
     pos.z = -21.0f - (f32)(0.8f * (f32)row);
     obj->unk_A8 = pos;
     fn_1_92530(obj);
    }
    obj->unk_A8 = p->unk_1DC;
    fn_1_92530(obj);
   } else if (b->unk_60 > 250) {
    fn_1_92530(obj);
   }
  }
 }
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

