#include "types.h"
#pragma opt_loop_invariants off

/* --- dol/gdev_cc_initinterrupts.c --- */
/* --- dol/gdev_cc_initinterrupts.c --- */
extern u32 fn_8008F7E4(void);

s32 gdev_cc_initinterrupts(void) {
    fn_8008F7E4();
    return 0;
}

/* --- dol/gdev_cc_peek.c --- */
extern s32 fn_8008F748(void);
extern s32 fn_8008F6BC(void *buf, s32 value);
extern u8 lbl_801A6378[32];
extern void fn_8008E21C(void *table, void *buf, s32 value);

s32 gdev_cc_peek(void) {
    u8 buf[0x500];
    s32 value;

    value = fn_8008F748();
    if (value <= 0) {
        return 0;
    }
    if (fn_8008F6BC(buf, value) == 0) {
        fn_8008E21C(lbl_801A6378, buf, value);
    } else {
        return -0x2719;
    }
    return value;
}

/* --- dol/gdev_cc_post_stop.c --- */
extern u32 fn_8008F458(void);

s32 gdev_cc_post_stop(void) {
    fn_8008F458();
    return 0;
}

/* --- dol/gdev_cc_pre_continue.c --- */
extern u32 fn_8008F454(void);

s32 gdev_cc_pre_continue(void) {
    fn_8008F454();
    return 0;
}

/* --- dol/gdev_cc_write.c --- */
extern s32 lbl_801A6E10[2];
extern void MWTRACE(s32, const char *, ...);
extern s32 fn_8008F45C(void *, s32);

u32 gdev_cc_write(void *buffer, s32 size) {
    s32 current_size = size;
    void *current_buffer = buffer;

    if (0 == lbl_801A6E10[0]) {
        MWTRACE(8, "cc not initialized\n");
        return -10001;
    }

    MWTRACE(8, "cc_write : Output data 0x%08x %ld bytes\n\000\000\000", buffer, size);
    while (current_size > 0) {
        MWTRACE(1, "cc_write sending %ld bytes\n", current_size);
        {
            s32 written = fn_8008F45C(current_buffer, current_size);
            if (written == 0) {
                break;
            }
            current_buffer = ((written) + ((u8 *)current_buffer));
            current_size -= written;
        }
    }
    return 0;
}

/* --- dol/gdev_cc_read.c --- */
extern u32 fn_8008E374(u8 *table);
extern void fn_8008E114(u8 *table, u32 dst, u32 len);
extern char lbl_80095E0C[];
extern char lbl_80095E34[];

s32 gdev_cc_read(u32 arg0, s32 arg1) {
    u8 buffer[0x500];
    struct { u8 *value; } table;
    u32 result = 0;
    struct { u32 value; } size;

    if (lbl_801A6E10[0] == 0) {
        return -10001;
    }
    MWTRACE(1, lbl_80095E0C, arg1, arg1);
    table.value = (u8 *)&lbl_801A6378;
    size.value = arg1;
    while (fn_8008E374(table.value) < size.value) {
        s32 value;
        result = 0;
        value = fn_8008F748();
        if (value != 0) {
            if ((result = fn_8008F6BC(buffer, size.value)) == 0) {
                fn_8008E21C(table.value, buffer, value);
            }
        }
    }
    if (result == 0) {
        fn_8008E114(lbl_801A6378, arg0, arg1);
    } else {
        MWTRACE(8, lbl_80095E34, result);
    }
    return result;
}
