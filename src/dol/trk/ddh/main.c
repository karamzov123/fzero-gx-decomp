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

extern u32 fn_8008EDF0(u32, u32);
extern u32 fn_8008EEAC(void);
extern s32 fn_8008EED8(void);
extern s32 fn_8008EFE0(void *data, s32 size);
extern s32 fn_8008F29C(u8 *dst, s32 size);
extern u32 fn_8008F44C(void);
extern u32 fn_8008F450(void);

extern s32 lbl_801A6E08;
extern u8 lbl_801A5658[0x800];
extern CircleBuffer lbl_801A5E58;

s32 ddh_cc_initinterrupts(void) {
    fn_8008EEAC();
    return 0;
}

s32 ddh_cc_peek(void) {
    u8 data[0x800];
    s32 value;

    value = fn_8008EED8();
    if (value <= 0) {
        return 0;
    }
    if (fn_8008EFE0(data, value) == 0) {
        fn_8008E21C(&lbl_801A5E58, data, value);
    } else {
        return -0x2719;
    }
    return value;
}

s32 ddh_cc_post_stop(void) {
    fn_8008F44C();
    return 0;
}

s32 ddh_cc_pre_continue(void) {
    fn_8008F450();
    return 0;
}

s32 ddh_cc_write(u8 *dst, s32 size) {
    s32 left = size;
    u8 *current = dst;

    if (!lbl_801A6E08) {
        MWTRACE(8, "cc not initialized\n");
        return -10001;
    }

    MWTRACE(8, "cc_write : Output data 0x%08x %ld bytes\n", dst, size);
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

s32 ddh_cc_read(u32 arg0, s32 arg1) {
    u8 buffer[0x800];
    s32 len;
    u32 result;
    u32 chunk;

    len = arg1;
    result = 0;
    if (lbl_801A6E08 == 0) {
        return -10001;
    }

    MWTRACE(1, "Expected packet size : 0x%08x (%ld)\n", len, len);
    while (fn_8008E374(&lbl_801A5E58) < len) {
        result = 0;
        chunk = fn_8008EED8();
        if (chunk != 0) {
            result = fn_8008EFE0(buffer, chunk);
            if (result == 0) {
                fn_8008E21C(&lbl_801A5E58, buffer, chunk);
            }
        }
    }

    if (result == 0) {
        fn_8008E114(&lbl_801A5E58, arg0, arg1);
    } else {
        MWTRACE(8, "cc_read : error reading bytes from EXI2 %ld\n", result);
    }
    return result;
}

int ddh_cc_close(void) {
    return 0;
}

s32 ddh_cc_open(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((s32)lbl_801A6E08 != 0) {
        v0 = -10005;
        return v0;
    }
    v0 = 0;
    lbl_801A6E08 = 1;
    return v0;
}

int ddh_cc_shutdown(void) {
    return 0;
}

s32 ddh_cc_initialize(u32 arg0, u32 arg1) {
    MWTRACE(1, "CALLING EXI2_Init\n");
    fn_8008EDF0(arg0, arg1);
    MWTRACE(1, "DONE CALLING EXI2_Init\n");
    fn_8008E324(&lbl_801A5E58, (u32)lbl_801A5658, 2048);
    return 0;
}
