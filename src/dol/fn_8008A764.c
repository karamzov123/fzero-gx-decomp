#include "types.h"


/* --- dol/fn_8008A764.c --- */
extern u8 lbl_80095A6C[];
extern u8 lbl_80095A74[];
extern void MWTRACE(u32, ...);

void fn_8008A764(u32 arg0, u32 arg1) {
    s32 v0;
    u8 *v1;
    v0 = 0;
    v1 = (u8 *)arg0;
    while (v0 < (s32)arg1) {
        MWTRACE(8, lbl_80095A6C, v1[v0]);
        if (v0 % 16 == 15) {
            MWTRACE(8, lbl_80095A74);
        }
        v0++;
    }
    MWTRACE(8, lbl_80095A74);
}

/* --- dol/fn_8008A80C.c --- */
/* --- dol/fn_8008A80C.c --- */
extern void *memset(void *dst, int value, u32 size);
extern s32 fn_80089244(void *out_a, void *out_b);
extern void *TRKAppendBuffer_ui8(void *buffer, const void *data, u32 length);
extern u32 fn_8008AB20(void *buffer, void *out, u32 a2, u32 a3, u32 a4);
extern void *TRKGetBuffer(u32 handle);
extern void fn_800891B4(void *value);

struct RequestBuffer {
    u32 length;
    u8 type;
    u8 unk_5[3];
    u32 unk_8;
    u32 unk_C;
    u8 arg;
    u8 unk_11[0x2f];
};

u32 fn_8008A80C(u32 arg0, u32 *arg1, u8 arg2, u32 *arg3) {
    u32 local_10;
    u32 local_c;
    u32 local_8;
    struct RequestBuffer request;
    s32 result;
    void *buf;

    memset(&request, 0, 0x40);
    request.type = 0xd4;
    request.length = 0x40;
    request.unk_8 = arg0;
    request.unk_C = *arg1;
    request.arg = arg2;
    result = fn_80089244(&local_c, &local_8);
    if (!result) {
        result = (u32)TRKAppendBuffer_ui8((void *)local_8, &request, 0x40);
    }
    if (!result) {
        *arg3 = 0;
        *arg1 = 0xffffffff;
        result = fn_8008AB20((void *)local_8, &local_10, 3, 3, 0);
        if (!result) {
            buf = TRKGetBuffer(local_10);
            if (buf) {
                *arg3 = *(u32 *)((u8 *)buf + 0x20);
                *arg1 = *(u32 *)((u8 *)buf + 0x28);
            }
        }
        fn_800891B4((void *)local_10);
    }
    fn_800891B4((void *)local_c);
    return result;
}

/* --- dol/fn_8008A91C.c --- */
struct fn_8008A91C_buffer {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5[3];
    void *unk_8;
    u8 unk_c[0x34];
};

s32 fn_8008A91C(void *arg0, u32 *arg1) {
    u32 unk_10;
    u32 unk_c;
    u32 unk_8;
    struct fn_8008A91C_buffer buffer;
    s32 result;
    void *buffer_ptr;

    memset(&buffer, 0, 0x40);
    buffer.unk_4 = 0xd3;
    buffer.unk_0 = 0x40;
    buffer.unk_8 = arg0;
    result = fn_80089244(&unk_c, &unk_8);
    if (!result) {
        result = (s32)TRKAppendBuffer_ui8((void *)unk_8, &buffer, 0x40);
    }
    if (!result) {
        *arg1 = 0;
        result = fn_8008AB20((void *)unk_8, &unk_10, 3, 3, 0);
        if (!result) {
            buffer_ptr = TRKGetBuffer(unk_10);
        }
        if (!result) {
            *arg1 = *(u32 *)((u8 *)buffer_ptr + 0x20);
        }
        fn_800891B4((void *)unk_10);
    }
    fn_800891B4((void *)unk_c);
    return result;
}

/* --- dol/fn_8008AA04.c --- */
extern u32 strlen(const char *str);

struct Request {
    u32 length;
    u8 type;
    u8 unk_5[3];
    u8 arg;
    u8 unk_9[3];
    u16 string_length;
    u8 unk_E[0x32];
};

u32 fn_8008AA04(const char *name, u8 type, u32 *status, u32 *length, void *buffer) {
    u32 local_10;
    u32 local_c;
    u32 local_8;
    struct Request request;
    s32 result;
    void *buf;

    memset(&request, 0, 0x40);
    *status = 0;
    request.type = 0xd2;
    request.length = strlen(name) + 0x41;
    request.arg = type;
    request.string_length = strlen(name) + 1;
    fn_80089244(&local_c, &local_8);
    result = (u32)TRKAppendBuffer_ui8((void *)local_8, &request, 0x40);
    if (!result) {
        result = strlen(name);
        result = (u32)TRKAppendBuffer_ui8((void *)local_8, name, result + 1);
    }
    if (!result) {
        *length = 0;
        result = fn_8008AB20((void *)local_8, &local_10, 7, 3, 0);
        if (!result) {
            buf = TRKGetBuffer(local_10);
        }
        *length = *(u32 *)((u8 *)buf + 0x20);
        *status = *(u32 *)((u8 *)buf + 0x18);
        fn_800891B4((void *)local_10);
    }
    fn_800891B4((void *)local_c);
    return result;
}
