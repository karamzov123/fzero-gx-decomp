/* Non-matching: best partial attempt (83.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/sel/sel.h"

extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, u32 (*)(void), u32, u32);
extern u32 fn_10_21E30(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_47F74(s32);
extern void fn_1_34E08(void);

struct SelectionState {
    u8 pad0[0x49388];
    u32 unk_49388;
    s16 unk_4938C;
    u8 pad1[0x51740 - 0x4938E];
    u32 unk_51740;
    u32 unk_51744;
};

void fn_10_4568(void) {
    struct LowState { Obj_10_bss_0 head; s32 unk_14; };
    struct LowState *base = (struct LowState *)&lbl_10_bss_0;
    u8 *state = (u8 *)base + 0x50000;
    fn_1_435C(*(u32 *)(state - 0x6c78));
    *(u32 *)(state + 0x1740) = fn_1_3F8C(lbl_10_data_67C, fn_10_21E30, 0, 8);
    fn_1_4A00(1, (u8)*(s16 *)(state - 0x6c74), *(u32 *)(state - 0x6c78));
    *(u32 *)(state + 0x1744) = 0;
    *(s32 *)((u8 *)base + 0x14) = -1;
    fn_1_47F74(0x8b);
    fn_1_47F74(0xa1);
    fn_1_34E08();
}
