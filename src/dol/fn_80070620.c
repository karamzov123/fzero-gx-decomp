#include "types.h"
extern u32 lbl_8012AFB8[];
extern u32 lbl_8012B030[];
extern u32 lbl_8012B06C[];
extern u32 lbl_8012B0A8[];
extern u32 lbl_8015AA78[];
extern u32 lbl_8015AB24[];
extern u32 lbl_8019E150[];
extern u32 lbl_801A6CF4;
extern u8 lbl_801A6CEA;
extern void OSPanic(const char *, int, const char *, ...);


s32 VIGetTvFormat();                                /* extern */
s32 VIConfigure(u32 *);                         /* extern */
s32 GXAdjustForOverscan(u32, u32 *, s32, s32);  /* extern */

void fn_80070620(s32 arg0) {
    s32 temp_r3;

    temp_r3 = VIGetTvFormat();
    switch (temp_r3) {                              /* irregular */
    case 0:
        if (arg0 != 0) {
            lbl_801A6CF4 = (u32)(lbl_8012B030);
        } else {
            lbl_801A6CF4 = (u32)(lbl_8012AFB8);
        }
        break;
    case 1:
        lbl_801A6CF4 = (u32)(lbl_8012B0A8);
        break;
    case 2:
        lbl_801A6CF4 = (u32)(lbl_8012B06C);
        break;
    default:
        OSPanic((const char *)(lbl_8015AA78), 0x157, (const char *)(lbl_8015AB24));
        break;
    }
    GXAdjustForOverscan(lbl_801A6CF4, lbl_8019E150, 0, 0x10);
    lbl_801A6CF4 = (u32)(lbl_8019E150);
    VIConfigure(lbl_8019E150);
    lbl_801A6CEA = 1;
}
