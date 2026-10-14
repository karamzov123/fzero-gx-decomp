/* Non-matching: best partial attempt (93.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 pad_11[1];
    s16 unk_12;
    u8 unk_14;
    u8 unk_15;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    u32 unk_1C;
    u8 unk_20;
} Obj_1A0F4;

extern Obj_1A0F4 lbl_3_bss_A2438;
extern s32 lbl_3_bss_A179C;
extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32, u32, u32);
extern s32 fn_8008023C(u32, u32, u32);

void fn_3_1A0F4(u8 *arg0) {
    Obj_1A0F4 *st = &lbl_3_bss_A2438;
    if (st->unk_20 != 0) {
        fn_80008BA8(st->unk_1C, *(u32 *)(arg0 + 0x20), 0x2000);
        fn_3_BE10();
        st->unk_20 = 0;
    } else if (lbl_3_bss_A179C != 0) {
        u8 *bp = (u8 *)&lbl_3_bss_A2438;
        fn_3_BEF0();
        st->unk_20 = 1;
        *(u32 *)(bp + 4) = 0x40000000;
        bp[0xE] = 0;
        lbl_3_bss_A179C = 0;
        if (fn_8008023C(st->unk_1C, *(u32 *)(arg0 + 0x20), 0x2000) != 0) {
            fn_3_1445C();
        }
    } else {
        fn_3_BE88();
    }
}
