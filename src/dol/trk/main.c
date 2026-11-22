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

extern void MWTRACE(s32, const char *, ...);
extern void *memcpy(void *, const void *, u32);
extern void fn_8008E73C(void *);
extern void fn_8008E718(void *);
extern u32 fn_8008E76C(u32, u32, u32);

extern u32 fn_8008EDF0(u32, u32);
extern u32 fn_8008EED8(void);
extern u32 fn_8008EFE0(void *, u32);

extern u32 fn_8008F454(void);
extern u32 fn_8008F458(void);
extern s32 fn_8008F45C(void *, s32);
extern s32 fn_8008F6BC(void *buf, s32 value);
extern s32 fn_8008F748(void);
extern u32 fn_8008F7E4(void);
extern u32 fn_8008F838(u32, u32);

extern s32 lbl_801A6E08;
extern s32 lbl_801A6E10[2];
extern char lbl_80095D2C[];
extern char lbl_80095D54[];
extern char lbl_80095D84[];
extern char lbl_80095D98[];
extern char lbl_80095E0C[];
extern char lbl_80095E34[];
extern char lbl_80095E64[];
extern char lbl_80095E78[];
extern u8 lbl_801A5658[];
extern u8 lbl_801A5E58[];
extern u8 lbl_801A5E78[];
extern u8 lbl_801A6378[];

s32 fn_8008E114(CircleBuffer *arg0, u32 arg1, u32 arg2);
s32 fn_8008E21C(CircleBuffer *arg0, void *arg1, u32 arg2);
void fn_8008E324(CircleBuffer *arg0, u32 arg1, u32 arg2);
u32 fn_8008E374(CircleBuffer *arg0);

#pragma use_lmw_stmw on
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

    MWTRACE(1, lbl_80095D2C, len, len);
    while (fn_8008E374((CircleBuffer *)lbl_801A5E58) < len) {
        result = 0;
        chunk = fn_8008EED8();
        if (chunk != 0) {
            result = fn_8008EFE0(buffer, chunk);
            if (result == 0) {
                fn_8008E21C((CircleBuffer *)lbl_801A5E58, buffer, chunk);
            }
        }
    }

    if (result == 0) {
        fn_8008E114((CircleBuffer *)lbl_801A5E58, arg0, arg1);
    } else {
        MWTRACE(8, lbl_80095D54, result);
    }
    return result;
}
#pragma use_lmw_stmw reset

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
    MWTRACE(1, lbl_80095D84);
    fn_8008EDF0(arg0, arg1);
    MWTRACE(1, lbl_80095D98);
    fn_8008E324((CircleBuffer *)lbl_801A5E58, (u32)lbl_801A5658, 2048);
    return 0;
}

s32 fn_8008E114(CircleBuffer *arg0, u32 arg1, u32 arg2) {
    u32 v2;

    if (arg2 > arg0->bytes_to_read) {
        return -1;
    }
    fn_8008E73C(&arg0->cs);
    v2 = arg0->size - (arg0->read_ptr - arg0->start_ptr);
    if (arg2 < v2) {
        memcpy((void *)arg1, (const void *)arg0->read_ptr, arg2);
        arg0->read_ptr += arg2;
    } else {
        memcpy((void *)arg1, (const void *)arg0->read_ptr, v2);
        memcpy((void *)(arg1 + v2), (const void *)arg0->start_ptr, arg2 - v2);
        arg0->read_ptr = arg0->start_ptr + arg2 - v2;
    }
    if (arg0->size == arg0->read_ptr - arg0->start_ptr) {
        arg0->read_ptr = arg0->start_ptr;
    }
    arg0->bytes_to_write += arg2;
    arg0->bytes_to_read -= arg2;
    fn_8008E718(&arg0->cs);
    return 0;
}

s32 fn_8008E21C(CircleBuffer *arg0, void *arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    if (arg2 > arg0->bytes_to_write) {
        v0 = -1;
    } else {
        fn_8008E73C(&arg0->cs);
        v1 = arg0->size - (arg0->write_ptr - arg0->start_ptr);
        if (v1 >= arg2) {
            memcpy((void *)arg0->write_ptr, arg1, arg2);
            arg0->write_ptr += arg2;
        } else {
            memcpy((void *)arg0->write_ptr, arg1, v1);
            memcpy((void *)arg0->start_ptr, (u8 *)arg1 + v1, arg2 - v1);
            arg0->write_ptr = arg0->start_ptr + arg2 - v1;
        }
        v2 = arg0->start_ptr;
        v0 = arg0->size;
        if (v0 == arg0->write_ptr - v2) {
            arg0->write_ptr = v2;
        }
        arg0->bytes_to_write -= arg2;
        arg0->bytes_to_read += arg2;
        fn_8008E718(&arg0->cs);
        v0 = 0;
    }
    return v0;
}

void fn_8008E324(CircleBuffer *arg0, u32 arg1, u32 arg2) {
    u32 v0;
    arg0->start_ptr = arg1;
    arg0->size = arg2;
    arg0->read_ptr = arg0->start_ptr;
    v0 = arg0->start_ptr;
    arg0->write_ptr = v0;
    arg0->bytes_to_read = 0;
    arg0->bytes_to_write = arg0->size;
    fn_8008E76C((u32)&arg0->cs, v0, arg2);
}

u32 fn_8008E374(CircleBuffer *arg0) {
    return arg0->bytes_to_read;
}

#pragma use_lmw_stmw on
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
        fn_8008E21C((CircleBuffer *)lbl_801A6378, buf, value);
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

s32 gdev_cc_read(u32 arg0, s32 arg1) {
    u8 buffer[0x500];
    struct { u8 *value; } table;
    u32 result = 0;
    struct { u32 value; } size;

    if (lbl_801A6E10[0] == 0) {
        return -10001;
    }
    MWTRACE(1, lbl_80095E0C, arg1, arg1);
    table.value = lbl_801A6378;
    size.value = arg1;
    while (fn_8008E374((CircleBuffer *)table.value) < size.value) {
        s32 value;
        result = 0;
        value = fn_8008F748();
        if (value != 0) {
            if ((result = fn_8008F6BC(buffer, size.value)) == 0) {
                fn_8008E21C((CircleBuffer *)table.value, buffer, value);
            }
        }
    }
    if (result == 0) {
        fn_8008E114((CircleBuffer *)lbl_801A6378, arg0, arg1);
    } else {
        MWTRACE(8, lbl_80095E34, result);
    }
    return result;
}
#pragma opt_loop_invariants reset
#pragma use_lmw_stmw reset

int gdev_cc_close(void) {
    return 0;
}

s32 gdev_cc_open(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((s32)lbl_801A6E10[0] != 0) {
        v0 = -10005;
        return v0;
    }
    v0 = 0;
    lbl_801A6E10[0] = 1;
    return v0;
}

int gdev_cc_shutdown(void) {
    return 0;
}

s32 gdev_cc_initialize(u32 arg0, u32 arg1) {
    MWTRACE(1, lbl_80095E64);
    fn_8008F838(arg0, arg1);
    MWTRACE(1, lbl_80095E78);
    fn_8008E324((CircleBuffer *)lbl_801A6378, (u32)lbl_801A5E78, 1280);
    return 0;
}
