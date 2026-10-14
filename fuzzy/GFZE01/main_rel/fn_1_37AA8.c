/* Non-matching: best partial attempt (90.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/os/OSTime.h"
#include "font.h"
#include "rel/main_rel/game.h"

struct fn_1_37AA8_Copy88 { u32 a[22]; };
struct fn_1_37AA8_State {
 u8 pad[0x1474]; u32 counter;
 u8 pad_1478[0x20]; OSTime elapsed; OSTime previous;
};
struct fn_1_37AA8_lbl_1_bss_3C00 {
 u8 pad_0[0x10]; u8 unk_10; u8 pad_11[0x19]; s16 unk_2A;
 u8 pad_2C[4]; u32 unk_30; u8 pad_34[0x14CC]; u32 unk_1500;
};
extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s16);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_3EFA8(void);
extern s32 camera_get_flags(void);
extern u32 fn_1_4338(void);
extern s32 fn_1_485A8(s32);
extern int fn_1_58C4(void);
extern void fn_1_5948(u32);
extern void fn_1_627C(u32);
extern u32 fn_1_C6F8C(void);
extern f32 lbl_1_rodata_26F8[22];
extern s32 fn_1_8DB94(void);
extern void fn_1_435C(void *);
extern void fn_1_86254(int);
extern void camera_update(void);
extern void fn_1_106EB0(void);
extern void fn_1_3308(void);
extern void fn_1_3CC4(void);
extern void fn_1_407C(void);
extern void fn_1_4324(u32);
extern void fn_1_9A770(void);
extern void fn_1_A96DC(void);
extern void fn_1_A96EC(void);
extern void fn_1_C7224(void);
extern void fn_1_F7578(void);

static inline void update_counter(struct fn_1_37AA8_State *state) {
 u32 count = state->counter;
 if (count < 360000) state->counter = count + 1;
}
static inline void update_time(struct fn_1_37AA8_State *state, OSTime now) {
 state->elapsed += now - state->previous;
}
static inline void save_time(struct fn_1_37AA8_State *state, OSTime now) {
 state->previous = now;
}
void fn_1_37AA8(void) {
 struct fn_1_37AA8_lbl_1_bss_3C00 *p_lbl_1_bss_3C00;
 Obj_1_bss_7EFD8 *p_lbl_1_bss_7EFD8;
 u8 *v0;
 s32 t0;
 OSTime t3;
 u32 t6;
 u32 v4;
 u8 *v3;
 u8 *v5;
 u8 *v12;
 u32 v13;
 u32 t22;
 u32 v14;
 FontDrawPacket loc_8;
 u32 v15;
 u32 v18;
 u32 v22;
 f32 v29;
 p_lbl_1_bss_3C00 = (struct fn_1_37AA8_lbl_1_bss_3C00 *)&lbl_1_bss_3C00;
 v0 = (u8 *)p_lbl_1_bss_3C00 + 0x20000;
 t0 = fn_1_3EFA8();
 fn_1_435C((void *)p_lbl_1_bss_3C00->unk_1500);
 fn_1_407C();
 t3 = OSGetTime();
 if (t0 == 0) {
  fn_1_435C(*(void **)(v0 + 0x1F88));
  fn_1_407C();
  if ((p_lbl_1_bss_3C00->unk_30 & 0x800000) != 0) {
   p_lbl_1_bss_7EFD8 = &lbl_1_bss_7EFD8;
   if (p_lbl_1_bss_7EFD8->unk_C != 0) {
    t6 = fn_1_4338();
    fn_1_4324(1);
    fn_1_A96EC();
    while (p_lbl_1_bss_7EFD8->unk_C != 0) {
     fn_1_3308();
     fn_1_435C(*(void **)(v0 + 0x1F88));
     fn_1_407C();
     p_lbl_1_bss_7EFD8->unk_C--;
    }
    fn_1_A96DC();
    fn_1_4324(t6);
   }
  }
  if (p_lbl_1_bss_3C00->unk_2A >= 41) {
   update_counter((struct fn_1_37AA8_State *)((u8 *)p_lbl_1_bss_3C00 + 48));
  }
 } else {
  fn_1_F7578();
  update_time((struct fn_1_37AA8_State *)((u8 *)p_lbl_1_bss_3C00 + 48), t3);
 }
 save_time((struct fn_1_37AA8_State *)((u8 *)p_lbl_1_bss_3C00 + 48), t3);
 fn_1_3CC4();
 fn_1_435C(*(void **)(v0 + 0x20A4));
 if (fn_1_8DB94() != 0) {
  fn_1_86254(0);
  fn_1_106EB0();
 }
 if (camera_get_flags() != 0) camera_update();
 t22 = fn_1_58C4();
 for (v13 = 0; v13 < t22; v13++) {
  fn_1_5948(v13);
  fn_1_9A770();
  if (p_lbl_1_bss_3C00->unk_10 == 0) fn_1_C7224();
  fn_1_407C();
  fn_1_627C(v13);
 }
 v14 = p_lbl_1_bss_3C00->unk_30;
 if ((v14 & 0x800000) != 0 && p_lbl_1_bss_3C00->unk_2A < 42 && (v14 & 0x800) != 0 && *(s16 *)&lbl_1_bss_960 != 12 && *(s16 *)&lbl_1_bss_960 != 10) {
  loc_8 = *(FontDrawPacket *)lbl_1_rodata_26F8;
  if (fn_1_485A8(148) != 0) loc_8.image = 0x942A;
  else {
   if (fn_1_485A8(151) == 0) goto end;
   loc_8.image = 0x9722;
  }
  loc_8.y = 470.0f;
  loc_8.scale_x = 0.0625f;
  loc_8.flags = 13;
  v13 = (lbl_801A66A0 % 60) * 1092;
  for (t22 = 0; t22 < 16; t22++) {
   v29 = 1.0f + lbl_8006D188((s16)(v13 - t22 * 2048));
   loc_8.x = 14.0f + (f32)(10.0f * (f32)t22);
   loc_8.u0 = loc_8.scale_x * (f32)t22;
   loc_8.u1 = loc_8.scale_x * (f32)(t22 + 1);
   loc_8.color_add[0] = (s32)(127.0f * (f32)(0.5f * v29));
   loc_8.color_add[2] = (s32)(127.0f * (f32)(0.25f * v29));
   fn_1_4F734(&loc_8);
  }
 }
end:
 fn_1_C6F8C();
}
