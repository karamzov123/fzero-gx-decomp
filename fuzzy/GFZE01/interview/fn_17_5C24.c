/* Non-matching: best partial attempt (98.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct InterviewEntry { s16 frame; u8 text[0x12]; f32 value; } InterviewEntry;
typedef struct InterviewScript {
 s16 unk_0, unk_2, unk_4, unk_6;
 InterviewEntry entries[5];
 f32 unk_80;
 s16 unk_84;
 u8 pad_86[0x10];
 s16 unk_96, unk_98;
} InterviewScript;
typedef struct InterviewGlobals {
 s32 frame; u8 pad_04[8]; s16 unk_C; u8 pad_0E[6]; InterviewScript *script;
} InterviewGlobals;
typedef struct InterviewMode { u8 pad[0x88]; s32 mode; } InterviewMode;
typedef struct InterviewState {
 u8 flag0, flag1, flag2, flag3; u8 pad_04[0x10]; void *unk_14;
 u8 pad_18[0x40]; u32 unk_58; u8 pad_5C[4]; InterviewGlobals globals;
 u8 pad_78[0x60]; InterviewMode *mode; u8 *object;
} InterviewState;
extern u8 lbl_17_bss_0;
extern u8 lbl_17_data_0[420];
extern const f32 lbl_17_rodata_1C;
extern void fn_17_750C(void *);
extern void fn_17_66C0(void *);
extern void fn_17_6848(void *, s32, f32);
extern void fn_17_6B2C(void *);
extern void fn_17_6C30(void *);
extern void fn_17_6D60(void *);
extern void fn_17_6F30(void *);
extern void fn_17_7020(void *);
extern void fn_17_69EC(void *, f32);
extern void fn_17_67C4(void *);
extern void fn_17_6078(void);
extern void fn_1_435C(void *);
extern void fn_1_40E08(u32);
extern void fn_1_935E4(void *, void *, void *, f32);
#pragma opt_propagation off
void fn_17_5C24(void) {
    InterviewMode * fzgx_live;
 InterviewState *state = (InterviewState *)&lbl_17_bss_0;
 InterviewGlobals *globals = (InterviewGlobals *)((u8 *)state + 0x60);
 u8 *data = lbl_17_data_0;
 struct { InterviewGlobals *value; } scriptGlobals;
 InterviewScript *script;
 u8 *table = data + 0x60000;
 s16 i;
 s16 frame;
 u8 *text;
 u8 *p;
 u8 *str;
 f32 value;
 u32 ref;
 u8 *object;
 u8 **strs;
 s16 *modes;
 s32 mode;
    struct { s32 value; } tmp_ra1;
 tmp_ra1.value = state->unk_58;
 if ((tmp_ra1.value & 1) == 0) fn_17_750C(globals);
 if (globals->frame == script->unk_4) fn_17_66C0(globals);
 for (i = 0; i < 5; i++) {
  switch (i) {
  case 0:
   if (script->entries[0].frame < 0) continue;
   value = script->entries[0].value;
   frame = script->entries[0].frame;
   text = script->entries[0].text;
   break;
  case 1:
   if (script->entries[1].frame < 0) continue;
   value = script->entries[1].value;
   frame = script->entries[1].frame;
   text = script->entries[1].text;
   break;
  case 2:
   if (script->entries[2].frame < 0) continue;
   value = script->entries[2].value;
   frame = script->entries[2].frame;
   text = script->entries[2].text;
   break;
  case 3:
   if (script->entries[3].frame < 0) continue;
   value = script->entries[3].value;
   frame = script->entries[3].frame;
   text = script->entries[3].text;
   break;
  case 4:
   if (script->entries[4].frame < 0) continue;
   value = script->entries[4].value;
   frame = script->entries[4].frame;
   text = script->entries[4].text;
   break;
  }
  if (*text == 0) {
   strs = (u8 **)(table + 0x3150);
   str = strs[globals->unk_C];
  } else {
   p = text;
   while (*p != '<' && *p != 0) p++;
   *p = 0;
   str = text;
  }
  if (globals->frame == frame) fn_17_6848(str, 1, value);
 }
 if (globals->frame == script->unk_96) fn_17_6B2C(globals);
 if (globals->frame == script->unk_2) fn_17_6C30(globals);
 if (globals->frame == script->unk_6) fn_17_6D60(globals);
 if (globals->frame == script->unk_84) {
  fn_17_6F30(globals);
  fn_1_435C(state->unk_14);
  fn_1_40E08(1);
 }
 if (globals->frame == script->unk_98) fn_17_7020(globals);
 if ((state->unk_58 & 0x00800000) != 0 && globals->frame == script->unk_84 + 0x122) {
  ref = (u32)state + 0xd8;
  object = *(u8 **)(ref + 4);
  fn_1_935E4(object, object + 0x148, table + 0x4328, lbl_17_rodata_1C);
  state->flag3 = 1;
 }
 if (state->flag1 == 1) fn_17_69EC(table + 0x309c, script->unk_80);
 if (state->flag2 != 0) {
  mode = state->mode->mode;
  modes = (s16 *)(table + 0x2c34);
  switch (modes[mode]) {
  case 2: fn_17_67C4(table + 0x4330); break;
  case 1: fn_17_67C4(table + 0x433c); break;
  case 0: fn_17_67C4(table + 0x4348); break;
  case 3: fn_17_67C4(table + 0x4358); break;
  case 4: fn_17_67C4(table + 0x4368); break;
  }
 }
 if (state->flag3 != 0) {
  fzgx_live = state->mode;
  mode = fzgx_live->mode;
  modes = (s16 *)(table + 0x2c34);
  switch (modes[mode]) {
  case 3:
  case 4: fn_17_67C4(table + 0x4060); break;
  default: fn_17_67C4(table + 0x309c); break;
  }
 }
 fn_17_6078();
 if (globals->frame < 0x4650) globals->frame++;
}
#pragma opt_propagation reset
