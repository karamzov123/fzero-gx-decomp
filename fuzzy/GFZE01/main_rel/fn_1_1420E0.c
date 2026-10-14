/* Non-matching: best partial attempt (98.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern int fn_1_5910(void);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(int);
extern void fn_1_52088(void);
extern u8 lbl_1_bss_26B1E[46];
extern void fn_1_1421D8(u32, u32, u32);
extern void fn_1_1424E8(u32, u32, u32);
extern void fn_1_14267C(u32, u32, u32);
extern void fn_1_142BDC(u32, u32, u32);
extern void fn_1_14328C(u32, u32, u32);
extern void fn_1_143780(u32, u32, u32);
extern void fn_1_143F5C(u32, u32, u32);
extern void fn_1_144254(u32, u32, u32);

void fn_1_1420E0(void) {
    u32 v;
    u8 flag;
    u8 mask;

    v = fn_1_5910();
    flag = lbl_1_bss_3C30.unk_8;
    mask = (u8)(1 << v);
    if (flag < 1) {
        return;
    }
    if ((lbl_1_bss_26B1E[0] & mask) == 0) {
        return;
    }
    fn_1_52070(0x140);
    if (fn_1_58C4() == 1) {
        fn_1_1421D8(0x25, 0x31, v);
        fn_1_14267C(0x2c, 0x40, v);
        fn_1_14328C(0xdb, 0x14a, v);
        fn_1_142BDC(0x39, 0x128, v);
        fn_1_1424E8(0x25, 0x31, v);
        fn_1_143780(0xf2, 0x40, v);
        fn_1_143F5C(0xf2, 0x122, v);
        fn_1_144254(0x2c, 0x15a, v);
    }
    fn_1_52088();
}
