#include "types.h"


/* --- dol/fn_80005A08.c --- */
extern u8 lbl_8015B920[];
extern void * OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void fn_80005AD0(u32);
extern void fn_8006FD1C(void);
extern void fn_8006FEFC(void);
extern void OSSetArenaLo(u32);
extern void OSSetArenaHi(u32);


s32 fn_80005B10(u8 *);                          /* extern */
s32 fn_80005E0C();                              /* extern */
s32 fn_8006FDEC();                              /* extern */

void fn_80005A08(void) {
    s32 var_r31;
    s32 var_r30_2;
    s32 var_r30;
    void *temp_r29;
    u32 temp_r28;

    temp_r29 = (void *)(OSGetArenaLo());
    temp_r28 = OSGetArenaHi();
    fn_80005AD0((u32)(lbl_8015B920));
    var_r30 = 0;
    do {
        fn_80005E0C();
        var_r30 += 1;
    } while (var_r30 < 0x14);
    var_r30_2 = 0;
    do {
        fn_8006FD1C();
        fn_80005B10((u8 *)(lbl_8015B920));
        fn_80005E0C();
        fn_80005E0C();
        fn_8006FDEC();
        fn_8006FEFC();
        var_r30_2 += 1;
    } while (var_r30_2 < 5);
    var_r31 = 0;
    do {
        fn_80005E0C();
        var_r31 += 1;
    } while (var_r31 < 0x14);
    OSSetArenaLo((u32)(temp_r29));
    OSSetArenaHi(temp_r28);
}

/* --- dol/fn_80005AD0.c --- */
extern u32 GXInvalidateTexAll(u32);
extern u32 GXInitTexObj(u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 lbl_801A63D0;

void fn_80005AD0(u32 arg0) {
    u32 t0;
    t0 = GXInitTexObj(arg0, lbl_801A63D0, 640, 480, 14, 0, 0, 0);
    GXInvalidateTexAll(t0);
}
