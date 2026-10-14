/* Non-matching: best partial attempt (90.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_A8F78(void);
extern s32 fn_1_1547FC(u8 *, u32);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern u32 fn_80008E84(u32);

#pragma opt_propagation off
void fn_1_3A044(void) {
    u8 *p = &lbl_1_bss_3C00 + 0x20000;
    u8 *base = &lbl_1_bss_3C00;
    s32 i;
    s32 t;
    u32 h;
    u32 lab_t0;

    if ((s32) lbl_1_bss_381F8 != -1) {
        fn_1_435C(*(u32 *) (p + 0x20a4));
        lab_t0 = lbl_1_bss_381F8;
        fn_1_426C(lab_t0);
    }
    fn_1_A8F78();
    if (*(s32 *) (p + 0x226c) != 0) {
        *(u32 *) (p + 0x2270) = 1;
    }
    if (*(s32 *) (p + 0x2270) != 0) {
        u8 *row = base + 0x30;
        u8 *cnt = row + 9;
        u8 *ix = row + 0xa7;
        u8 *sa = p + 0x1fa8;
        u8 *sb = p + 0x1fc8;
        for (i = 0; i < *cnt; i++) {
            u8 *d = row + 0xd4;
            d[*ix + 0xe] = *sa++;
            d[*ix + 0x13] = *sb++;
            row += 0xa0;
        }
        *(u32 *) (row + 0x1464) = 0;
        *(u8 *) (row + 0x146c) = 0;
        *(u8 *) (row + 0x146d) = 0;
        *(u8 *) (row + 0x1470) = 0;
        *(u16 *) (row + 0x146e) = 0x5dc;
        fn_1_1547FC(row, 0);
        fn_1_C47B4();
        fn_1_435C(*(u32 *) (p + 0x1f88));
        if (*(u32 *) (base + 0x14) != 0) {
            lab_t0 = *(u32 *) (base + 0x14);
            fn_1_426C(lab_t0);
            *(u32 *) (base + 0x14) = 0;
        }
        fn_1_435C(*(u32 *) (p + 0x20a4));
        if (*(u32 *) (base + 0x18) != 0) {
            lab_t0 = *(u32 *) (base + 0x18);
            fn_1_426C(lab_t0);
            *(u32 *) (base + 0x18) = 0;
        }
        fn_1_C6F80(0);
        h = fn_80008E84(*(u32 *) (p + 0x20cc));
        fn_1_79100();
        fn_80008E84(h);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(*(u32 *) (p + 0x1f88));
        lab_t0 = *(u32 *) (p + 0x20b4);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x20b8);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x2264);
        fn_1_426C(lab_t0);
        fn_1_435C(*(u32 *) (p + 0x20a4));
        lab_t0 = *(u32 *) (p + 0x20a8);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x20ac);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x20b0);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x20bc);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x20c0);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x20c4);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x2258);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x225c);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x2260);
        fn_1_426C(lab_t0);
        lab_t0 = *(u32 *) (p + 0x2254);
        fn_1_426C(lab_t0);
    }
    if (*(s32 *) (p + 0x226c) != 0) {
        base[0xd7]++;
    }
    if (*(s16 *) (base + 0x14e8) == 0x29) {
        return;
    }
    fn_1_435C(*(u32 *) (p + 0x1f88));
    t = *(s32 *) (p + 0x227c);
    if (t != -1) {
        lab_t0 = t;
        fn_1_426C(lab_t0);
    }
    t = *(s32 *) (p + 0x2280);
    if (t != -1) {
        lab_t0 = t;
        fn_1_426C(lab_t0);
        fn_1_105724();
    }
    fn_1_435C(*(u32 *) (p + 0x20a4));
    t = *(s32 *) (p + 0x2284);
    if (t != -1) {
        lab_t0 = t;
        fn_1_426C(lab_t0);
    }
    t = *(u32 *) (base + 0x30);
    lab_t0 = -1;
    *(u32 *) (p + 0x227c) = lab_t0;
    if (t & 0x100) {
        fn_1_F2EDC();
    }
    *(u32 *) (p + 0x2280) = lab_t0;
    *(u32 *) (p + 0x2284) = lab_t0;
}
#pragma opt_propagation reset
