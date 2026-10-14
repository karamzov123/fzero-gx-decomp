/* Non-matching: best partial attempt (97.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

struct State {
    s16 current;
    s16 previous;
    u8 pad4[0x90];
    u32 flags;
    u8 pad98[0xC];
    u8 *entries;
    u8 padA8[0x81];
    u8 active;
};
extern struct State lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_964;
extern u8 *lbl_1_bss_6EAD0;
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_1_4A00(u32, u32, u32);
extern u32 fn_8004CD70(u32, void *, u32);
extern void fn_1_A176C(u32, u32);
extern void fn_1_12F1E8(s32);
extern void fn_10_E294(void);

#pragma opt_strength_reduction off

#pragma opt_dead_assignments off
void fn_10_12D8(void) {
    u8 * fzgx_live;
    u8 *base;
    struct State *state;
    u32 high;
    u32 flags;
    u8 *entries;
    s32 offset;
    s16 result;
    s16 value;
    s16 finalValue;
    s32 handle;
    u8 *audio;
    u32 finalAddress;
    base = (u8 *)&lbl_10_bss_0;
    high = (u32)base + 0x50000;
    fn_1_435C(*(u32 *)((u8 *)high - 0x6C78));
    handle = fn_1_3F8C(lbl_10_data_61C, fn_10_E294, 0, 8);
    *(s32 *)((u8 *)high + 0x1740) = handle;
    fn_1_4A00(1, (((s16)(*(s16 *)((u8 *)high - 0x6C74))) & 0xFF), *(u32 *)((u8 *)high - 0x6C78));
    audio = lbl_1_bss_6EAD0;
    *(u32 *)((u8 *)high + 0x1744) = 0;
    if (audio != 0) {
        if (*(u32 *)audio == 0) {
            *(u32 *)lbl_1_bss_6EAD0 = fn_8004CD70(2, audio + 0x10, 0x25124);
        }
        if (*(u32 *)(lbl_1_bss_6EAD0 + 4) == 0) {
            *(u32 *)(lbl_1_bss_6EAD0 + 4) = fn_8004CD70(2, lbl_1_bss_6EAD0 + 0x4A258, 0x25124);
        }
        fn_1_A176C(*(u32 *)lbl_1_bss_6EAD0, 45);
    }
    state = (struct State *)&lbl_1_bss_8B3A0;
    flags = state->flags;
    state->flags = flags & 0xFFBFFFFF;
    if (0x40000000 & flags) {
        entries = state->entries;
        high = (lbl_1_bss_962 - 14) * 148;
        offset = high;
        value = *(s16 *)(entries + offset);
        result = lbl_1_bss_962;
        if (value < 9) {
            result = 9;
        } else {
            result = 10;
            if (value <= 10) result = value;
        }
        *(s16 *)(entries + offset) = result;
    } else {
        entries = state->entries;
        offset = (lbl_1_bss_962 - 14) * 148;
        if ((s16)*(s16 *)(entries + offset) < 0 || *(s16 *)(entries + offset) > 8) {
            *(s16 *)(entries + offset) = 1;
            switch (lbl_1_bss_964) {
            case 12: *(s16 *)(entries + offset) = 7; break;
            case 15: *(s16 *)(entries + offset) = 8; break;
            case 3: *(s16 *)(entries + offset) = 6; break;
            case 5: *(s16 *)(entries + offset) = 5; break;
            case 9: *(s16 *)(entries + offset) = 4; break;
            }
        }
    }
    *(s32 *)(base + 0x14) = -1;
    lbl_1_bss_8B3A0.current = -1;
    lbl_1_bss_8B3A0.active = 1;
    fn_1_12F1E8(360);
    finalValue = lbl_1_bss_8B3A0.previous;
    state->flags &= 0xFFFFFFFB;
    if (finalValue != -1) {
        fzgx_live = lbl_1_bss_8B3A0.entries;
        finalAddress = (u32)fzgx_live + lbl_1_bss_962 * 148;
        *(s16 *)((u8 *)finalAddress - 0x818) = finalValue;
    }
}
#pragma opt_dead_assignments reset


