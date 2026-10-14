/* Non-matching: best partial attempt (75.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

typedef struct SoundFlags {
    u32 a, b, c, d;
} SoundFlags;
typedef struct SoundState {
    u8 pad_00[0x2E];
    u8 unk_2E;
    u8 pad_2F[0x779];
    u8 unk_7A8;
    u8 pad_7A9[3];
    u8 unk_7AC;
    u8 pad_7AD[0x83];
    SoundFlags unk_830;
} SoundState;

void fn_1_A0D20(void) {
    SoundState *state = (SoundState *)&lbl_1_bss_6EA98;
    if (state->unk_2E != 0) {
        SoundFlags *flags = &state->unk_830;
        u32 a = flags->a & ~0x80;
        u32 b = flags->b & ~0x80;
        u32 c = flags->c & ~0x80;
        u32 d = flags->d & ~0x80;
        state->unk_7AC = 1;
        state->unk_7A8 = 0;
        flags->a = a;
        flags->b = b;
        flags->c = c;
        flags->d = d;
    }
}
