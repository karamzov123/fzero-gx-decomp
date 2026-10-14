/* Non-matching: best partial attempt (91.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

typedef struct {
    s16 unk_0;
    u8 pad_2[0x8A];
    s16 unk_8C;
    s16 unk_8E;
    u8 pad_90[4];
    u32 unk_94;
    u8 pad_98[0xC];
    u8 *unk_A4;
    u8 pad_A8[0x81];
    u8 unk_129;
} SelectionState;

extern SelectionState lbl_1_bss_8B3A0;
extern u8 lbl_1_bss_8CA24;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern void **lbl_1_bss_6EAD0;
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_10_F57C(void);
extern void fn_1_4A00(u32, u8, u32);
extern void fn_1_EB29C(void);
extern int fn_10_A7DC(s16);
extern int fn_1_F89E4(u8);
extern void fn_10_AB98(void *);
extern void fn_1_46A60(void);
extern void fn_1_159440(int, int);
extern void fn_1_12F1E8(s32);
extern void fn_1_A176C(void *, u32);

void fn_10_1F9C(void) {
    u8 *base;
    u8 *manager;
    SelectionState *selection;
    SelectionState *state;
    s16 value;
    base = (u8 *)&lbl_10_bss_0;
    manager = base + 0x50000;
    fn_1_435C(*(u32 *)(manager - 0x6C78));
    {
        s32 handle = fn_1_3F8C(lbl_10_data_65C, fn_10_F57C, 0, 8);
        value = *(s16 *)(manager - 0x6C74);
        *(s32 *)(manager + 0x1740) = handle;
    }
    fn_1_4A00(1, (u8)value, *(u32 *)(manager - 0x6C78));
    *(u32 *)(manager + 0x1744) = 0;
    if (lbl_1_bss_8B3A0.unk_0 == 2 || lbl_1_bss_8B3A0.unk_0 == 10) {
        fn_1_EB29C();
    }
    state = (SelectionState *)&lbl_1_bss_8B3A0;
    if (state->unk_94 & 0x40000000) {
        state->unk_8C = 6;
    } else {
        while (!fn_10_A7DC(state->unk_8C)) {
            int next = state->unk_8C + 1;
            state->unk_8C = next > 10 ? 0 : next < 0 ? 10 : next;
        }
    }
    selection = (SelectionState *)&lbl_1_bss_8B3A0;
    if (selection->unk_8C == 5) {
        while ((selection->unk_8E == 5 && !fn_1_F89E4(0)) ||
               (selection->unk_8E != 5 && !fn_1_F89E4((u8)(selection->unk_8E + 1)))) {
            int next = selection->unk_8E + 1;
            selection->unk_8E = next > 5 ? 0 : next < 0 ? 5 : next;
        }
    }
    if (state->unk_94 & 0x40000000) {
        selection->unk_8C = 6;
    }
    fn_10_AB98(&lbl_1_bss_8B3A0);
    if (lbl_1_bss_8B3A0.unk_0 != 1) {
        fn_1_46A60();
        fn_1_159440(3, 0);
    }
    *(s32 *)(base + 0x14) = -1;
    fn_1_12F1E8(0x2D0);
    lbl_1_bss_8B3A0.unk_A4[0x19] = 0;
    *(s16 *)(manager + 0x174E) = 0;
    *(u8 *)(manager + 0x1750) = 0;
    *(s16 *)(manager + 0x1752) = 0;
    lbl_1_bss_8B3A0.unk_A4[0x1A] = 0;
    lbl_1_bss_8B3A0.unk_129 = 1;
    lbl_1_bss_8CA24 = 0;
    lbl_1_bss_8B5F0 = 0;
    lbl_1_bss_8B5F1 = 0;
    *(u8 *)(manager + 0x1754) = 1;
    fn_1_A176C(*lbl_1_bss_6EAD0, 0x2D);
    *(s16 *)(manager + 0x174C) = 0;
}
