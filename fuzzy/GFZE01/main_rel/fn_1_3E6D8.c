/* Non-matching: best partial attempt (41.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"

typedef struct {
    u8 pad_0[0x2A];
    s16 unk_2A;
    u8 pad_2C[4];
    u32 unk_30;
    u8 pad_34[0x14CC];
    u32 unk_1500;
    u8 pad_1504[0x138];
    u8 src[0x20];
    u8 tab[0x194];
    u16 unk_17F4;
} Obj_3C00;

extern void fn_1_3F2A0(void);
extern void fn_1_469BC(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_8DBA4(u8);

void fn_1_3E6D8(void) {
    Obj_3C00 *p = (Obj_3C00 *)&lbl_1_bss_3C00;
    u8 *q = (u8 *)p + 0x30;
    u8 *tab = p->tab;
    u8 idx;
    s32 i;
    s32 j;
    s32 k;

    if (lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }
    if ((lbl_1_bss_D58.unk_8 & 0x8000) == 0) {
        return;
    }
    if (lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }
    p->unk_17F4 = q[7];
    if (q[5] != 0) {
        goto tail;
    }
    for (i = 0; i < q[8]; i++) {
        if (*(u32 *)(q + 0x1480 + i * 4) == 0) {
            continue;
        }
        if (p->unk_30 & 0x200) {
            break;
        }
        fn_1_3F2A0();
        k = 0;
        if (p->unk_2A > 0x29) {
            for (j = 0; j < q[8]; j++) {
                idx = q[j * 0xA0 + 0xDC];
                tab[idx * 8 + 4] = q[j * 0xA0 + 0x154];
                tab[idx * 8 + 6] = p->src[j];
                tab[idx + 0x194] = k++;
            }
        } else {
            for (j = 0; j < q[8]; j++) {
                idx = q[j * 0xA0 + 0x157];
                tab[idx * 8 + 4] = q[j * 0xA0 + 0x154];
                tab[idx * 8 + 6] = p->src[j];
                tab[idx + 0x194] = k++;
            }
        }
        tab[0x190] = q[7];
        tab[0x191] |= 2;
        tab[0x192] = q[8];
        p->unk_30 |= 0x40000;
        p->unk_17F4 = 14;
        break;
    }
tail:
    fn_1_4A00(0, 0x1E, (void *)p->unk_1500);
    lbl_1_bss_6EAB4.unk_0 |= 0x2C;
    lbl_1_bss_25BA0.unk_0 = 1;
    if (q[5] == 0) {
        lbl_1_data_5B84 = 1;
    }
    fn_1_469BC();
    fn_1_8DBA4(0);
}
