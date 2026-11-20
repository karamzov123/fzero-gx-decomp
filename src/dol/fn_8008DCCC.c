#include "types.h"


/* --- dol/fn_8008DCCC.c --- */
/* --- dol/fn_8008DCCC.c --- */
extern u8 fn_8008D7B0(u32, u32, u32 *);
extern s32 fn_8008A754(void);
extern u32 fn_8008CB20(u32, u32, u32 *, u32);

s32 fn_8008DCCC(u32 arg0, u32 arg1, u32 *arg2) {
    u32 v0;
    u32 v1;

    if (fn_8008D7B0(arg0, arg1, arg2) == 0) {
        return 1;
    }
    if (fn_8008A754() == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd1, 0, &v0, arg1);
    *arg2 = v0;
    switch ((s32)(v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}

/* --- dol/udp_cc_post_stop.c --- */
/* --- dol/udp_cc_post_stop.c --- */
// udp_cc_post_stop: returns a constant.
int udp_cc_post_stop(void) {
    return -1;
}

/* --- dol/udp_cc_pre_continue.c --- */
// udp_cc_pre_continue: returns a constant.
int udp_cc_pre_continue(void) {
    return -1;
}

/* --- dol/udp_cc_peek.c --- */
// udp_cc_peek: returns a constant.
int udp_cc_peek(void) {
    return 0;
}

/* --- dol/udp_cc_write.c --- */
// udp_cc_write: returns a constant.
int udp_cc_write(void) {
    return 0;
}

/* --- dol/udp_cc_read.c --- */
// udp_cc_read: returns a constant.
int udp_cc_read(void) {
    return 0;
}

/* --- dol/udp_cc_close.c --- */
// udp_cc_close: returns a constant.
int udp_cc_close(void) {
    return -1;
}

/* --- dol/udp_cc_open.c --- */
// udp_cc_open: returns a constant.
int udp_cc_open(void) {
    return -1;
}

/* --- dol/udp_cc_shutdown.c --- */
// udp_cc_shutdown: returns a constant.
int udp_cc_shutdown(void) {
    return -1;
}

/* --- dol/udp_cc_initialize.c --- */
// udp_cc_initialize: returns a constant.
int udp_cc_initialize(void) {
    return -1;
}

/* --- dol/ddh_cc_initinterrupts.c --- */
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

/* --- dol/ddh_cc_write.c --- */
extern s32 lbl_801A6E08[2];
extern void MWTRACE(s32 level, const char *format, ...);
extern s32 fn_8008F29C(u8 *dst, s32 size);

s32 ddh_cc_write(u8 *dst, s32 size) {
    s32 left = size;
    u8 *current = dst;

    if (!lbl_801A6E08[0]) {
        MWTRACE(8, "cc not initialized\n");
        return -10001;
    }

    MWTRACE(8, "cc_write : Output data 0x%08x %ld bytes\n\000\000\000", dst, size);
    while (left > 0) {
        s32 written;

        MWTRACE(1, "cc_write sending %ld bytes\n", left);
        written = fn_8008F29C(current, left);
        if (written == 0) {
            break;
        }
        current += written;
        left -= written;
    }

    return 0;
}
