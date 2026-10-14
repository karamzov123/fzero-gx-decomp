/* Non-matching: best partial attempt (86.98% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/burner.h"
extern int fn_1_58C4(void);
extern void fn_1_103058(void);
extern void fn_1_9D260(void);
extern int fn_1_9D230(void);
extern void fn_1_9AD88(void);
typedef struct State { s16 unk_00; u8 pad[0x82]; s32 unk_84; s32 unk_88; u8 pad8C[8]; f32 unk_94; f32 unk_98; } State;
typedef struct Output { u8 pad[0xC]; f32 unk_0C; u8 pad10[0xC]; f32 unk_1C; } Output;
typedef struct Entry { u8 pad[0x14]; void (*unk_14)(struct Entry *); u8 pad18[0xC]; } Entry;
#pragma opt_propagation off
void fn_1_9A7BC(void) {
 u8 *base = lbl_1_data_2A0C0;
 struct { State *value; } stateHolder;
 struct { Output *value; } outputHolder;
 int count;
 stateHolder.value = (State *)(base + 0x720);
 outputHolder.value = (Output *)(base + 0x2810);
#define state stateHolder.value
#define output outputHolder.value
 if (state->unk_84 != 0) count = 4;
 else count = fn_1_58C4();
 {
 f32 b;
 f32 a;
 a = state->unk_98;
 b = state->unk_94;
 state->unk_88 = count;
 output->unk_0C = a;
 output->unk_1C = b;
 }
 fn_1_103058();
 if (state->unk_00 <= 0) goto fallback;
 fn_1_9D260();
 if (fn_1_9D230() != 0) goto fallback;
 {
 Entry *entry = &((Entry *)(base + 0xAEC))[state->unk_00];
 entry->unk_14(entry);
 }
 return;
fallback:
 fn_1_9AD88();
}
