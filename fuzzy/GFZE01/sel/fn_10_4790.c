/* Non-matching: best partial attempt (87.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

extern void fn_10_2228C(void);
extern void fn_10_25E1C(void);
extern u8 lbl_10_data_54C[8];
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_1_15BB34(void *);
extern u8 lbl_1_bss_8B3A0[];

typedef struct {
    u8 pad_0[0x14];
    s32 unk_14;
} SelBase;

void fn_10_4790(void) {
    struct { u8 *value; } mgr;
    SelBase *base = (SelBase *)&lbl_10_bss_0;

    mgr.value = (u8 *)base + 0x50000;
    fn_1_435C(*(u32 *)(mgr.value - 0x6C78));
    *(s32 *)(mgr.value + 0x1740) = fn_1_3F8C(lbl_10_data_694, fn_10_2228C, 0, 8);
    fn_1_4A00(1, *(u8 *)(mgr.value - 0x6C74), *(u32 *)(mgr.value - 0x6C78));
    *(u32 *)(mgr.value + 0x1744) = 0;
    base->unk_14 = -1;
    fn_10_25E1C();
    fn_1_15BB34(lbl_10_data_54C);
    (*(u8 **)(lbl_1_bss_8B3A0 + 0xA4))[0x22] = 0;
}
