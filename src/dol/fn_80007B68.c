#include "types.h"


/* --- dol/fn_80007B68.c --- */
extern u32 fn_800744F8(void *value, u32 mask);
extern void fn_80008204(u32 *value);

extern u32 lbl_801A6F04;
extern u32 lbl_801A6408;
extern u32 lbl_801A6728;

void fn_80007B68(void) {
    u32 loc_8[5];
    u8 *src;
    u8 *dst;

    loc_8[4] = lbl_801A6F04;
    loc_8[0] = lbl_801A6F04;
    loc_8[3] = lbl_801A6F04;
    if (((u8 *)&lbl_801A6408)[0] != ((u8 *)&loc_8[4])[0] ||
        ((u8 *)&lbl_801A6408)[1] != ((u8 *)&loc_8[4])[1] ||
        ((u8 *)&lbl_801A6408)[2] != ((u8 *)&loc_8[4])[2] ||
        ((u8 *)&lbl_801A6408)[3] != ((u8 *)&loc_8[4])[3]) {
        loc_8[2] = loc_8[3];
        ((u8 *)&lbl_801A6408)[0] = ((u8 *)&loc_8[2])[0];
        ((u8 *)&lbl_801A6408)[1] = ((u8 *)&loc_8[2])[1];
        ((u8 *)&lbl_801A6408)[2] = ((u8 *)&loc_8[2])[2];
        ((u8 *)&lbl_801A6408)[3] = ((u8 *)&loc_8[2])[3];
        loc_8[1] = lbl_801A6408;
        fn_800744F8(&loc_8[1], (0x1000000 - 1));
        fn_80008204(&lbl_801A6408);
    }
    lbl_801A6728 = 1;
}

/* --- dol/fn_80007C2C.c --- */
extern u32 fn_800744F8(void *, u32);

void fn_80007C2C(void) {
    u32 loc_8[2];
    /* frame */
    loc_8[0] = lbl_801A6408;
    fn_800744F8(loc_8, (0x1000000 - 1));
}
