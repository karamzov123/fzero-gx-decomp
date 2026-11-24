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

extern void *memcpy(void *, const void *, u32);
extern void fn_8008E73C(void *);
extern void fn_8008E718(void *);
extern u32 fn_8008E76C(u32, u32, u32);

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
