#include "types.h"

typedef struct CircleBuffer {
    u32 read_ptr;
    u32 write_ptr;
    u32 start_ptr;
    u32 size;
    u32 bytes_to_read;
    u32 bytes_to_write;
    u32 cs;
} CircleBuffer;

extern void MWTRACE(s32 level, const char *format, ...);

extern s32 fn_8008E114(CircleBuffer *cb, u32 data, u32 size);
extern s32 fn_8008E21C(CircleBuffer *cb, void *data, u32 size);
extern void fn_8008E324(CircleBuffer *cb, u32 buffer, u32 size);
extern u32 fn_8008E374(CircleBuffer *cb);

extern u32 fn_8008F454(void);
extern u32 fn_8008F458(void);
extern s32 fn_8008F45C(void *, s32);
extern s32 fn_8008F6BC(void *buf, s32 value);
extern s32 fn_8008F748(void);
extern u32 fn_8008F7E4(void);
extern u32 fn_8008F838(u32, u32);

extern s32 lbl_801A6E10;
extern u8 lbl_801A5E78[0x500];
extern CircleBuffer lbl_801A6378;

#pragma opt_loop_invariants off
s32 gdev_cc_initinterrupts(void) {
    fn_8008F7E4();
    return 0;
}

s32 gdev_cc_peek(void) {
    u8 buf[0x500];
    s32 value;

    value = fn_8008F748();
    if (value <= 0) {
        return 0;
    }
    if (fn_8008F6BC(buf, value) == 0) {
        fn_8008E21C(&lbl_801A6378, buf, value);
    } else {
        return -0x2719;
    }
    return value;
}

s32 gdev_cc_post_stop(void) {
    fn_8008F458();
    return 0;
}

s32 gdev_cc_pre_continue(void) {
    fn_8008F454();
    return 0;
}

u32 gdev_cc_write(void *buffer, s32 size) {
    s32 current_size = size;
    void *current_buffer = buffer;

    if (0 == lbl_801A6E10) {
        MWTRACE(8, "cc not initialized\n");
        return -10001;
    }

    MWTRACE(8, "cc_write : Output data 0x%08x %ld bytes\n", buffer, size);
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

s32 gdev_cc_read(u32 arg0, s32 arg1) {
    u8 buffer[0x500];
    struct { CircleBuffer *value; } table;
    u32 result = 0;
    struct { u32 value; } size;

    if (lbl_801A6E10 == 0) {
        return -10001;
    }
    MWTRACE(1, "Expected packet size : 0x%08x (%ld)\n", arg1, arg1);
    table.value = &lbl_801A6378;
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
        fn_8008E114(&lbl_801A6378, arg0, arg1);
    } else {
        MWTRACE(8, "cc_read : error reading bytes from EXI2 %ld\n", result);
    }
    return result;
}
#pragma opt_loop_invariants reset

int gdev_cc_close(void) {
    return 0;
}

s32 gdev_cc_open(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((s32)lbl_801A6E10 != 0) {
        v0 = -10005;
        return v0;
    }
    v0 = 0;
    lbl_801A6E10 = 1;
    return v0;
}

int gdev_cc_shutdown(void) {
    return 0;
}

s32 gdev_cc_initialize(u32 arg0, u32 arg1) {
    MWTRACE(1, "CALLING EXI2_Init\n");
    fn_8008F838(arg0, arg1);
    MWTRACE(1, "DONE CALLING EXI2_Init\n");
    fn_8008E324(&lbl_801A6378, (u32)lbl_801A5E78, 1280);
    return 0;
}
