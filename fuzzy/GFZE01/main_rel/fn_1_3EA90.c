/* Non-matching: best partial attempt (80.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"

typedef struct {
 u8 pad_2000[0x2048];
 u16 timers[0x30A];
 u8 names[0x20];
 u32 values[0x240];
 u8 count;
} NameData;

typedef struct {
 u8 num_00;
 u8 pad_01[0x163B];
 u8 letters[0x2A0C];
} LetterData;

void fn_1_3EA90(u8 count, u8 *name_src, u8 *code_src, u32 *value_src)
{
 LetterData *head = (LetterData *)&lbl_1_bss_3C00;
 struct { NameData *value; } data;
 u8 slot;
 u8 *names;
 u8 *letters;
 u16 *timers;
 s32 i;
 data.value = (NameData *)((u8 *)head + 0x20000);
 slot = head->num_00;
 names = data.value->names;
 letters = head->letters;
 timers = data.value->timers;
 for (i = 0; i < count; i++) {
  names[slot + i] = name_src[i];
  if (code_src == 0 || code_src[i] == 0xFF) {
   letters[slot + i] = 0x10;
  } else {
   letters[slot + i] = code_src[i];
  }
  if (value_src == 0) {
   struct { u32 *value; } values;
   values.value = data.value->values;
   values.value[slot + i] = 0;
  } else {
   struct { u32 *value; } values;
   values.value = data.value->values;
   values.value[slot + i] = value_src[i];
  }
  timers[slot + i] = 0x32;
 }
 data.value->count = count;
}
