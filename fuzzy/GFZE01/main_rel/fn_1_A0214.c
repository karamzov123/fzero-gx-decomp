/* Non-matching: best partial attempt (78.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"
extern u32 fn_1_A266C(void);
extern u32 fn_1_3F1AC(u32);
extern void fn_8004EBF4(void);
extern u32 fn_80023638(void);
typedef struct { u8 pad[0x30]; u32 unk_30; u32 unk_34; } SoundEntry;
typedef struct {
    u8 pad_0[0xD];
    u8 unk_D;
    u8 pad_E[0x2A];
    u32 unk_38;
    u32 unk_3C;
    SoundEntry unk_40[32];
    u8 unk_740;
    u8 pad_741[3];
    u32 unk_744;
} SoundState;
void fn_1_A0214(void) {
    SoundState *state = (SoundState *)&lbl_1_bss_6EA98;
    u32 i;
    u32 count;
    if (state->unk_D == 0) {
        state->unk_740 = fn_1_3F1AC(fn_1_A266C()) != 0;
        if (state->unk_38 != 0) {
            fn_8004EBF4();
            count = fn_80023638();
            {
                u32 value = state->unk_744;
                SoundEntry *entries = state->unk_40;
                for (i = 0; i < count; i++) {
                    value = entries[i].unk_30;
                }
                state->unk_744 = value;
            }
        }
    }
}
