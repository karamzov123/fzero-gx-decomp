/* Non-matching: best partial attempt (98.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/avline.h"

extern u32 lbl_801A6410;
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_9F7DC(void);
extern void fn_1_58114(void);

typedef struct {
    u8 unk_0[2];
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[0xe2];
} AvlineInitEntry;

typedef struct {
    AvlineInitEntry *unk_0;
    AvlineInitEntry *unk_4;
    s16 unk_8;
    u8 pad_A[2];
    u32 unk_C;
    u32 unk_10;
} AvlineInitState;

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("effect.c");
}
#pragma section code_type ".text"

void fn_1_584D4(void) {
    AvlineInitEntry * fzgx_live;
    AvlineInitState *state = (AvlineInitState *)&lbl_1_bss_6C848;
    s32 i;
    AvlineInitEntry *entry;
    state->unk_0 = (AvlineInitEntry *)fn_1_4630(lbl_801A6410, 0xac30, (u8 *)"effect.c", 0xc1);
    state->unk_4 = (AvlineInitEntry *)fn_1_4630(lbl_801A6410, 0xb540, (u8 *)"effect.c", 0xc2);
    fzgx_live = state->unk_0;
    entry = fzgx_live;
    state->unk_8 = 0;
    {
        s32 count = 0xbe;
        i = 0;
        while (count > 0) {
            entry->unk_2 = i++;
            entry->unk_4 = -1;
            entry++;
            count--;
        }
    }
    entry = state->unk_4;
    (void) entry;  /* fzgx: keeps the web at its definition */
    {
        s32 count = 0xc8;
        i = 0;
        while (count > 0) {
            entry->unk_2 = i++;
            entry->unk_4 = -1;
            entry++;
            count--;
        }
    }
    fn_1_9F7DC();
    fn_1_58114();
    state->unk_C = 0;
    state->unk_10 = 0;
}
