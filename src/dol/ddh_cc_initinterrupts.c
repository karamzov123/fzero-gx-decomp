#include "types.h"


/* --- dol/ddh_cc_initinterrupts.c --- */
extern u32 fn_8008EEAC(void);

s32 ddh_cc_initinterrupts(void) {
    fn_8008EEAC();
    return 0;
}

/* --- dol/ddh_cc_peek.c --- */
extern s32 fn_8008EED8(void);
extern s32 fn_8008EFE0(void *data, s32 value);
extern u8 lbl_801A5E58[32];
extern void fn_8008E21C(u8 *table, void *data, s32 value);

s32 ddh_cc_peek(void) {
    u8 data[0x800];
    s32 value;
    
    value = fn_8008EED8();
    if (value <= 0) {
        return 0;
    }
    if (fn_8008EFE0(data, value) == 0) {
        fn_8008E21C(lbl_801A5E58, data, value);
    } else {
        return -0x2719;
    }
    return value;
}

/* --- dol/ddh_cc_post_stop.c --- */
extern u32 fn_8008F44C(void);

s32 ddh_cc_post_stop(void) {
    fn_8008F44C();
    return 0;
}

/* --- dol/ddh_cc_pre_continue.c --- */
extern u32 fn_8008F450(void);

s32 ddh_cc_pre_continue(void) {
    fn_8008F450();
    return 0;
}
