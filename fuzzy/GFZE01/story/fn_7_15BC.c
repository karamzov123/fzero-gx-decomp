/* Non-matching: best partial attempt (86.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/story/story_mode.h"

extern u8 fn_1_8623C(void);
extern s8 *fn_1_3F0D8(u32, u8 *, f32 *);

extern u8 lbl_1_bss_7F0C0[];
extern u8 lbl_1_bss_9C[];

typedef struct {
    u8 pad_0[0x6c];
    u8 unk_6c;
    u8 unk_6d;
    u16 unk_6e;
} StoryTime_T;

typedef struct {
    u8 pad_0[0x1e0];
    u8 unk_1e0;
    s8 unk_1e1;
    u16 unk_1e2;
} StoryClock_T;

#define CELL ((StoryTime_T *)((u8 *)lbl_1_bss_7F0C0 + (s8)target->unk_1 * 0x30 + col))

#pragma peephole on
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
void fn_7_15BC(void) {
    f32 f;
    u8 buf[16];
    StoryClock_T *clock;
    Obj_7_bss_10_Target *target;
    s32 col;
    u8 f0;
    u8 *u;

    clock = (StoryClock_T *)fn_1_3F0D8((u8)fn_1_8623C(), buf, &f);
    target = lbl_7_bss_10;
    col = (s8)target->unk_0 * 4;
    u = (u8 *)CELL + 0x6c;
    col = *u;
    f0 = col;
    if (f0 || CELL->unk_6d || CELL->unk_6e) {
        if (clock->unk_1e1 * 1000 + clock->unk_1e0 * 60000 + clock->unk_1e2
            >= ((CELL->unk_6d * 1000) + ((CELL->unk_6e) + (f0 * 60000)))) {
            return;
        }
    }
    *u = clock->unk_1e0;
    CELL->unk_6d = clock->unk_1e1;
    CELL->unk_6e = clock->unk_1e2;
    lbl_1_bss_9C[3] = 1;
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma peephole reset
