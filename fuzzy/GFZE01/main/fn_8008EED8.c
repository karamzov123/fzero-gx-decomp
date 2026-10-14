/* Non-matching: best partial attempt (96.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_801A6680;
extern s32 lbl_801A6E1C;
extern s32 fn_8008EBF8(u32);
extern char lbl_8015B900[25];
extern int printf(const char *, ...);
extern u32 fn_8008E770(u32, u32, u32, u32);
extern u32 fn_8008E9B4(u32);

#define PI_REG (*(u32 *)0xCC003000)

#pragma opt_common_subs off
u32 fn_8008EED8(void) {
    u32 loc_18;
    u32 loc_14;
    u32 loc_8[3];
    s32 status;
    if ((PI_REG & 0x1000) == 0 && *(u8 *)lbl_801A6680 == 0) {
        loc_18 = 0;
    } else {
        if (lbl_801A6E1C == 0) {
            status = 0;
            while (((0) == (status))) {
                status = fn_8008EBF8(5);
            }
            if (status == 0) {
                printf("Can't select EXI2 port!\n");
            } else {
                lbl_801A6E1C = 1;
                loc_8[0] = 0;
                fn_8008E9B4(fn_8008E770((u32)loc_8, 2, 1, 0));
                fn_8008E9B4(fn_8008E770((u32)&loc_14, 2, 0, 0));
            }
        }
        fn_8008E9B4(fn_8008E770((u32)&loc_18, 4, 0, 0));
        if (*(u8 *)lbl_801A6680 == 0) {
            u16 pi = PI_REG;
            *(u8 *)lbl_801A6680 = 1;
            PI_REG = pi & 0x1000;
        }
    }
    return loc_18;
}
#pragma opt_common_subs reset
