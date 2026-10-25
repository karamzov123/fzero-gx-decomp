#include "types.h"

extern f32 fn_8006CD40(f32);
extern f32 lbl_801A6E40;
extern u32 DVDInit(void);
extern u32 OSGetProgressiveMode(void);
extern u32 OSGetResetCode(void);
extern u32 OSInit(void);
extern u32 fn_80005738(void);
extern u32 fn_80005858(void);
extern u32 fn_80005A08(void);
extern u32 fn_800063AC(void);
extern u32 fn_80006B30(u32);
extern u32 fn_800071B8(void);
extern u32 VIInit(void);
extern u32 fn_8006CCC8(void);
extern void mathutil_init(void);
extern u32 fn_80070158(u32);
extern u32 fn_80070538(void);
extern u32 fn_80070620(u32);
extern u32 fn_80070774(u32, u32, u32);
extern u32 fn_80070AC0(u32, u32);
extern u8 fn_800058D8(void);
extern void fn_800057CC(void);
extern void fn_80006354(void);
extern void fn_80006AFC(void);
extern void fn_8006FCB4(void);
extern void fn_8006FF8C(s32);
extern void fn_8007075C(u32);
extern int __cntlzw(unsigned int value);

void fn_80005660(void) {
    u32 reset_code;
    u32 reset_match;
    u32 v1;
    u32 t1, t12, t13;

    OSInit();
    DVDInit();
    fn_80006AFC();
    fn_80006B30((u32)fn_80006354);
    VIInit();
    mathutil_init();
    fn_80070158(1);
    fn_8007075C(1);
    fn_8006FF8C(1);
    fn_80070538();
    fn_800071B8();
    reset_code = OSGetResetCode();
    reset_match = (u32)__cntlzw(((u32)1 << 31) - reset_code) >> 5;
    if (reset_match && OSGetProgressiveMode() != 0) {
        v1 = 1;
        t12 = fn_80070620(v1);
        v1 = t12;
    } else {
        v1 = 0;
        t13 = fn_80070620(v1);
        v1 = t13;
    }
    fn_80070774(1, 0xC0000, 1);
    fn_8006FCB4();
    fn_8006CCC8();
    fn_8006CD40(lbl_801A6E40);
    fn_80070AC0(32, 1);
    fn_80005738();
    fn_800057CC();
    fn_800058D8();
    fn_800063AC();
    fn_80005A08();
    fn_80005858();
}
