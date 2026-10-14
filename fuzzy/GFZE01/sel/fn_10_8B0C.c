/* Non-matching: best partial attempt (85.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/sel/sel.h"

extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, u32 (*)(void), u32, u32);
extern u32 fn_10_1B2F4(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_12F1E8(s32);
extern void fn_1_A2D84(u32);
typedef struct { u8 pad[0x94]; u32 flags; } SelGlobal;
extern SelGlobal lbl_1_bss_8B3A0;

void fn_10_8B0C(void) {
    u8 *base = (u8 *)&lbl_10_bss_0;
    u8 *high = base + 0x50000;
    fn_1_435C(*(u32 *)(high - 0x6c78));
    *(s32 *)(high + 0x1740) = fn_1_3F8C(lbl_10_data_7A0, fn_10_1B2F4, 0, 8);
    fn_1_4A00(1, (u8)*(s16 *)(high - 0x6c74), *(u32 *)(high - 0x6c78));
    *(u32 *)(high + 0x1744) = 0;
    *(s32 *)(base + 0x14) = -1;
    fn_1_12F1E8(0x1e0);
    lbl_1_bss_8B3A0.flags |= 0x800;
    fn_1_A2D84(0xa9121500);
}
