/* Non-matching: best partial attempt (66.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"
extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(u8);
typedef struct { u8 pad[4]; u8 value; u8 pad5; u8 other; u8 pad7; } Slot;
typedef struct { Slot slots[50]; u8 a,b,c,d; u8 indices[32]; } Table;
typedef struct { u8 pad[0x2a]; s16 mode; u8 pad2[4]; u32 flags; u8 rest[0x17f4-0x34]; u16 status; } State;
void fn_1_304A8(void) {
 State *state = (State *)&lbl_1_bss_3C00;
 u8 *sub;
 Slot *slot;
 int count;
 int i;
 int j;
 Table *table;
 u8 *order;
 u8 *car;
 if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
  sub = (u8 *)state + 0x30;
  state->status = sub[7];
  if (sub[5] == 0) {
   for(i=0; i<sub[8]; i++) {
    if (*(u32 *)(sub + 0x1480 + i*4)) {
     if (state->flags & 0x400000) break;
     fn_1_3F2A0();
     count = sub[8];
     table = (Table *)((u8 *)state + 0x165c);
     order = (u8 *)state + 0x163c;
     j = 0;
     car = sub;
     if (state->mode <= 41) {
      for (; j<count; j++, car += 0xa0, order++) {
       int id = car[0x157];
       slot = &table->slots[id];
       slot->value = car[0x154];
       slot->other = *order;
       table->indices[id] = j;
      }
     } else {
      for (; j<count; j++, car += 0xa0, order++) {
       int id = car[0xdc];
       slot = &table->slots[id];
       slot->value = car[0x154];
       slot->other = *order;
       table->indices[id] = j;
      }
     }
     table->c = count;
     table->b |= 2;
     table->a = sub[7];
     state->flags |= 0x400000;
     state->status = 14;
     break;
    }
   }
  }
  fn_1_4A00(0,30,*(void **)((u8 *)state+0x1500));
  lbl_1_bss_6EAB4.unk_0 |= 0x2c;
  lbl_1_bss_25BA0.unk_0 = 1;
  if (sub[5] == 0) lbl_1_data_5B84 = 1;
  fn_1_469BC();
  fn_1_8DBA4(0);
 }
}
