/* Non-matching: best partial attempt (93.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 fn_1_3F7D0(void);
extern u32 fn_1_101C0(void);
extern void fn_1_3EF14(void *);
extern u32 fn_1_3F114(void);
extern void fn_1_12EF80(s16, s16 *, s16 *);
typedef struct {
 u8 field_0; u8 field_1; u16 field_2;
 u8 field_4; u8 pad_5[3]; u8 field_8; u8 field_9;
 u16 field_a; u8 field_c[3]; u8 field_f;
 u8 field_10; u8 field_11; u8 field_12; u8 pad_13;
 u16 field_14; u8 pad_16[2]; u16 field_18;
} TimeData;
typedef struct {
 u8 pad_0[5]; u8 mode; u8 id; u8 pad_7[0x145d];
 u32 time; u8 pad_1468[0x50];
} ResultData;
extern void fn_1_128E8C(u32, TimeData *);
extern void fn_1_52070(int);
extern void fn_1_CFB28(s16, f32);
extern s16 fn_1_7B054(void);
extern char *lbl_1_data_2BD54[111][6];
extern u32 lbl_801A66B4;
extern void fn_1_CFCA4(f32, f32, const char *, f32);
extern void fn_1_CFF94(u32, u8, f32);
extern void fn_1_D01B0(u32, s16, f32);
extern void fn_1_52088(void);
extern const f32 lbl_1_rodata_5C38, lbl_1_rodata_5CCC, lbl_1_rodata_5CFC, lbl_1_rodata_5D90, lbl_1_rodata_6020, lbl_1_rodata_6028;
extern const f64 lbl_1_rodata_6018;
#pragma fp_contract off
static inline int milliseconds(int minute, int second, int ms) {
 int value = minute * 60000;
 value += ms;
 return (second * 1000 + value);
}
static inline int range(int x, int low, int high) {
 if (x > high) return 0;
 return x >= low;
}
void fn_1_D0428(void) {
 s32 tmp_call7;
    u32 lab_t0;
 ResultData result;
 TimeData time;
 s16 a, b;
 int flag;
 int now;
 int end;
 u32 status;
 int currentTime;
 int recordTime;
 int index;
 const char *text;
 f32 alpha;
 now = fn_1_3F7D0();
 end = fn_1_101C0();
 if (range(now, 20, end)) {
  fn_1_3EF14(&result);
  status = fn_1_3F114();
  fn_1_12EF80(result.id, &a, &b);
  flag = 0;
  fn_1_128E8C((u8)b, &time);
  lab_t0 = time.field_0;
  tmp_call7 = milliseconds(lab_t0, time.field_1, time.field_2);
  recordTime = milliseconds((result.time >> 20) & 255, (result.time >> 12) & 255, result.time & 4095);
  currentTime = tmp_call7;
  if (time.field_18 == 0 || currentTime == 0x7ffff) flag = 1;
  if (currentTime > recordTime) flag = 1;
  if (range(now, end - 120, end)) alpha = (f32)(end - now) / lbl_1_rodata_5C38;
  else if (range(now, 10, 40)) alpha = lbl_1_rodata_5CFC - (f32)(40 - now) / lbl_1_rodata_5CCC;
  else if (now < 10) alpha = lbl_1_rodata_5D90;
  else alpha = lbl_1_rodata_5CFC;
  fn_1_52070(0x60);
  fn_1_CFB28(now, alpha);
  lbl_1_data_3D558.unk_0 = lbl_1_data_3D558.unk_0 + lbl_1_rodata_6018 * (lbl_1_rodata_6020 - lbl_1_data_3D558.unk_0);
  index = fn_1_7B054() < 0 ? 0 : fn_1_7B054() > 110 ? 110 : fn_1_7B054();
  text = lbl_1_data_2BD54[index][lbl_801A66B4];
  fn_1_CFCA4(lbl_1_data_3D558.unk_0, lbl_1_rodata_6028, text, alpha);
  fn_1_52070(0x220);
  fn_1_CFF94(flag, (u8)status, alpha);
  if (result.mode == 2) fn_1_D01B0(flag, b, alpha);
  fn_1_52088();
 }
}
