/* Non-matching: best partial attempt (62.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"
extern f32 lbl_1_rodata_3518[6];
extern f32 lbl_1_rodata_3530[22];
extern u8 lbl_1_bss_26B80[168];
extern s32 fn_1_858A8(s16 *, s16 *);
extern void *fn_1_14F04(void);
extern void fn_1_17920(int, int, f32);
extern void fn_1_85C58(s32, f32);
extern void fn_1_85F70(void *, f32);
extern void fn_1_8B880(void);
extern void qsort(void *, u32, u32, int (*)(const void *, const void *));
typedef struct {
 u8 pad0[0x18];
 u8 *cars;
 u8 *other;
 u8 pad20[0xa];
 s8 count;
 u8 pad2b[0x19];
 u8 *bytes;
 u8 pad48[0x1d4];
 u8 order[32];
 u8 inverse[32];
} Manager;
typedef struct { u8 pad[0x468]; f32 value; } Fn14F04Result;
void fn_1_85934(f32 arg) {
 s16 order[48];
 Manager *manager;
 s32 i;
 u8 *car;
 f32 value;
 Fn14F04Result *result;
 s32 count;
 manager = (Manager *)&lbl_1_bss_6D820;
 value = lbl_1_rodata_3518[0];
 if (*(s16 *)&lbl_1_bss_960 == 12) {
  for (i = 0; i < manager->count; i++) order[i] = lbl_1_bss_26B80[i*5+4];
 } else {
  for (i = 0; i < manager->count; i++) order[i] = i;
  qsort(order, manager->count, 2, (int (*)(const void *, const void *))fn_1_858A8);
 }
 if (lbl_1_bss_3BE0 != 0) {
  result = (Fn14F04Result *)fn_1_14F04();
  count = lbl_1_bss_3BE0->unk_8;
  if (count > 0) count--; else count = 0;
  fn_1_17920(count, 0, lbl_1_rodata_3530[0]);
  value = result->value;
 }
 for (i = 0; i < manager->count; i++) {
  car = manager->cars + order[i]*0x620;
  if (manager->other != 0) {
   *(u32 *)(manager->other + order[i]*0x440 + 0x390) &= ~(1 << 21);
   *(u32 *)(manager->other + order[i]*0x440 + 0x390) &= ~(1 << 24);
  }
  if (manager->bytes != 0) manager->bytes[order[i]+14] = i;
  manager->order[i] = order[i];
  manager->inverse[order[i]] = i;
  fn_1_85C58(i, value);
  fn_1_85F70(car, arg);
 }
 fn_1_8B880();
}
