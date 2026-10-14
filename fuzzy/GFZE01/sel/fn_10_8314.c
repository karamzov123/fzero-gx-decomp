/* Non-matching: best partial attempt (82.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/sel/sel.h"

typedef struct SelWork {
    u8 pad_0[0x14];
    s32 unk_14;
    u8 pad_18[0x49384 - 0x18];
    u32 unk_49384;
    u32 unk_49388;
    s16 unk_4938C;
    u8 pad_4938E[0x51740 - 0x4938E];
    s32 unk_51740;
    u32 unk_51744;
} SelWork;
typedef struct SelState {
    u8 pad_0[0x9E];
    u8 unk_9E;
    u8 pad_9F[0x129 - 0x9F];
    u8 unk_129;
} SelState;
extern SelState lbl_1_bss_8B3A0;
extern void fn_10_1B664(void);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_1_12F1E8(s32);
extern void fn_1_4A00(s32, u32, u32);
extern u32 fn_10_25610(u32, u32, u32);

void fn_10_8314(void) {
    SelWork *work = (SelWork *)&lbl_10_bss_0;
    struct { u8 *value; } high;
    volatile SelState *state;
    u32 arg0;
    u32 arg1;
    high.value = (u8 *)work + 0x50000;
    fn_1_435C(*(u32 *)(high.value - 0x6C78));
    *(s32 *)(high.value + 0x1740) = fn_1_3F8C(lbl_10_data_758, fn_10_1B664, 0, 8);
    fn_1_12F1E8(3600);
    fn_1_4A00(1, (u8)*(s16 *)(high.value - 0x6C74), *(u32 *)(high.value - 0x6C78));
    state = &lbl_1_bss_8B3A0;
    *(u32 *)(high.value + 0x1744) = 0;
    arg0 = *(u32 *)(high.value - 0x6C7C);
    work->unk_14 = -1;
    arg1 = *(u32 *)(high.value - 0x6C78);
    state->unk_129 = 1;
    fn_10_25610(arg0, arg1, state->unk_9E);
}
