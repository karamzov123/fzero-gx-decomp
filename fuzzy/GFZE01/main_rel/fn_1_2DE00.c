/* Non-matching: best partial attempt (71.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_2DE00_State {
    u8 pad_00[0x30];
    u32 unk_30;
    u8 pad_34[0x1608];
    u8 unk_163C[0x20];
    u8 unk_165C[0x19C];
    u32 unk_17F8[0x40];
};

struct fn_1_2DE00_5480 {
    u8 pad_00[0x81C0];
};

extern u8 lbl_1_bss_3C00;
extern struct fn_1_2DE00_5480 lbl_1_bss_5480[4];
extern u32 fn_1_3F2A0(void);
extern int fn_1_8623C(void);
extern void fn_80008BA8(void *, void *, u32);

void fn_1_2DE00(s32 arg0) {
    struct fn_1_2DE00_State *state = (struct fn_1_2DE00_State *)&lbl_1_bss_3C00;
    u8 *rows;
    u8 *tab;
    u8 *ids;
    u32 *flags;
    u8 *e;
    u8 *rec;
    u32 f;
    s32 count;
    s32 i;
    s32 j;
    s32 n;

    if (state->unk_30 & 0x200) {
        return;
    }
    fn_1_3F2A0();
    rows = (u8 *)state + 0x30;
    tab = (u8 *)state + 0x165C;
    ids = (u8 *)state + 0x163C;
    flags = (u32 *)((u8 *)state + 0x17F8);
    count = rows[9];
    tab[0x192] = 0;
    for (i = 0, j = 0; j < 0x1E && i < count; i++, j++) {
        f = flags[i];
        e = tab + rows[i * 0xA0 + 0xDC] * 8;
        e[4] = rows[i * 0xA0 + 0x154];
        e[5] = rows[i * 0xA0 + 0x156];
        e[6] = ids[i];
        *(u32 *)e = f ? (u32)&lbl_1_bss_5480[i] : 0;
    }
    n = fn_1_8623C();
    rec = rows + n * 0xA0 + 0xD4;
    *(u16 *)(rec + 6) = 0;
    *(u16 *)(rec + 6) += *(u8 *)(rec + 0x13);
    *(u16 *)(rec + 6) += *(u8 *)(rec + 0x14);
    *(u16 *)(rec + 6) += *(u8 *)(rec + 0x15);
    *(u16 *)(rec + 6) += *(u8 *)(rec + 0x16);
    *(u16 *)(rec + 6) += *(u8 *)(rec + 0x17);
    fn_80008BA8(tab + 0xF0, rec, 0xA0);
    tab[0x191] = 0;
    if (arg0) {
        tab[0x190] = rows[7];
        state->unk_30 |= 0x400000;
    }
}
