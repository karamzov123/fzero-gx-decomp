/* Non-matching: best partial attempt (41.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"
#include "rel/main_rel/globals.h"

extern u32 fn_1_156754(u32);
extern u32 fn_1_F7578(void);
extern u32 fn_1_A0D20(void);
extern u32 fn_1_435C(u32);
extern void fn_1_8DAB4(void);
extern void fn_1_A8F78(void);
extern u8 lbl_1_rodata_DB38[32];
extern void fn_1_2CBAC(void);
extern s32 fn_1_1547FC(u32, u32, u32, u32);
extern void fn_1_C47B4(void);
extern s16 fn_1_426C(s16);
extern void fn_1_C6F80(u8);
extern u32 fn_80008E84(u32);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern void fn_1_D1F88(void);
extern u8 lbl_1_bss_381F4;
extern u32 lbl_1_data_5B88;
extern u32 lbl_1_data_5B8C;
extern u8 lbl_1_bss_3C00;

void fn_1_3C880(void) {
    u8 *mgr;
    u8 *base;
    s32 i;
    u32 j;
    u32 count;
    u32 index;
    u32 k;
    u32 tmp;
    u32 handle;

    base = &lbl_1_bss_3C00;
    mgr = base + 0x20000;

    for (i = 0; i < 4; i++) fn_1_156754(i);
    fn_1_F7578();
    fn_1_A0D20();
    fn_1_435C(*(u32 *)(mgr + 0x1f88));
    fn_1_8DAB4();
    fn_1_A8F78();

    if ((*(u32 *)(base + 0x30) & 0x800) == 0) {
        count = base[0x39];
        for (i = 0; i < count; i++) {
            u8 *row = base + 0x30 + i * 0xa0;
            u8 *table = row + 0xd4;
            u32 slot = row[0xa7] + 0xe;
            if (table[slot] == 0xff) {
                index = 0;
                while (index < count && row[index + 0xe] != i) index++;
                table[slot] = index;
                *(u16 *)(table + row[0xa7] * 2 + 0x4c) = 0;
                if (row[5]) {
                    if (index < 30) table[row[0xa7] + 9] = lbl_1_rodata_DB38[index];
                    else table[row[0xa7] + 9] = 0;
                }
                *(u16 *)(table + 4) += table[row[0xa7] + 9];
            }
        }
        count = base[0x39];
        for (i = 0; i < count; i++) {
            u8 *row = base + 0x30 + i * 0xa0;
            mgr[0x1fa8 + row[0xe]] = i;
        }
        for (i = 0; i < count; i++) {
            u8 *row = base + 0x30 + i * 0xa0;
            mgr[0x1fc8 + i] = row[0xe7];
        }
        fn_1_2CBAC();
    }

    if (*(u32 *)(mgr + 0x226c)) *(u32 *)(mgr + 0x2270) = 1;
    if (*(u32 *)(mgr + 0x2270)) {
        count = base[0x39];
        for (i = 0; i < count; i++) {
            u8 *row = base + 0x30 + i * 0xa0;
            row[0xd4 + row[0xa7] + 0xe] = mgr[0x1fa8 + i];
            row[0xd4 + row[0xa7] + 0x13] = mgr[0x1fc8 + i];
        }
        *(u32 *)(base + 0x30 + 0x1464) = 0;
        base[0x30 + 0x146c] = 0;
        base[0x30 + 0x146d] = 0;
        base[0x30 + 0x1470] = 0;
        *(u16 *)(base + 0x30 + 0x146e) = 1500;
        fn_1_1547FC((u32)(base + 0x30), 0, 0, 0);
        fn_1_C47B4();
        fn_1_435C(*(u32 *)(mgr + 0x1f88));
        if (*(u32 *)(base + 0x14)) { fn_1_426C(*(u32 *)(base + 0x14)); *(u32 *)(base + 0x14)=0; }
        fn_1_435C(*(u32 *)(mgr + 0x20a4));
        if (*(u32 *)(base + 0x18)) { fn_1_426C(*(u32 *)(base + 0x18)); *(u32 *)(base + 0x18)=0; }
        fn_1_C6F80(0);
        handle = fn_80008E84(*(u32 *)(mgr + 0x20cc));
        fn_1_79100();
        fn_80008E84(handle);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(*(u32 *)(mgr + 0x1f88));
        fn_1_426C(*(u32 *)(mgr + 0x20b4));
        fn_1_426C(*(u32 *)(mgr + 0x20b8));
        fn_1_426C(*(u32 *)(mgr + 0x2264));
        fn_1_435C(*(u32 *)(mgr + 0x20a4));
        fn_1_426C(*(u32 *)(mgr + 0x20a8));
        fn_1_426C(*(u32 *)(mgr + 0x20ac));
        fn_1_426C(*(u32 *)(mgr + 0x20b0));
        fn_1_426C(*(u32 *)(mgr + 0x20bc));
        fn_1_426C(*(u32 *)(mgr + 0x20c0));
        fn_1_426C(*(u32 *)(mgr + 0x20c4));
        fn_1_426C(*(u32 *)(mgr + 0x2258));
        fn_1_426C(*(u32 *)(mgr + 0x225c));
        fn_1_426C(*(u32 *)(mgr + 0x2260));
        fn_1_426C(*(u32 *)(mgr + 0x2254));
    }
    if (*(u32 *)(mgr + 0x226c)) base[0x30 + 0xa7]++;
    if (*(u32 *)(mgr + 0x2288)) {
        fn_1_435C(*(u32 *)(mgr + 0x1f88));
        if (lbl_1_data_5B88 != -1) { fn_1_426C(lbl_1_data_5B88); lbl_1_data_5B88 = -1; }
        fn_1_435C(*(u32 *)(mgr + 0x20a4));
        if (lbl_1_data_5B8C != -1) { fn_1_426C(lbl_1_data_5B8C); lbl_1_data_5B8C = -1; }
        fn_1_D1F88();
        *(u32 *)(mgr + 0x2288) = 0;
    }
    tmp = *(u32 *)(base + 0x30) & 0xfeffffff;
    *(u32 *)(base + 0x30) = tmp;
    if (lbl_1_bss_381F4) *(u32 *)(base + 0x30) = tmp | 0x100000;
}
