#include "types.h"
#pragma use_lmw_stmw on

typedef int DSError;
typedef int MessageBufferID;
typedef int DSIOResult;

typedef enum TRKFileCommand {
    TRK_MSG_WRITE_FILE = 0xD0,
    TRK_MSG_READ_FILE = 0xD1,
    TRK_MSG_OPEN_FILE = 0xD2,
    TRK_MSG_CLOSE_FILE = 0xD3,
    TRK_MSG_POSITION_FILE = 0xD4
} TRKFileCommand;

typedef struct MessageBuffer {
    u32 mutex;
    BOOL is_in_use;
    u32 length;
    u32 position;
    u8 data[0x880];
} MessageBuffer;

struct RequestBuffer {
    u32 length;
    u8 type;
    u8 unk_5[3];
    u32 unk_8;
    u32 unk_C;
    u8 arg;
    u8 unk_11[0x2f];
};

struct fn_8008A91C_buffer {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5[3];
    void *unk_8;
    u8 unk_c[0x34];
};

struct Request {
    u32 length;
    u8 type;
    u8 unk_5[3];
    u8 arg;
    u8 unk_9[3];
    u16 string_length;
    u8 unk_E[0x32];
};

struct TRKAccessFileRequest {
    u32 length;
    u8 command;
    u8 field_0x05[3];
    u32 handle;
    u16 data_length;
    u8 field_0x0E[0x32];
};

struct TRKFileSupportReply {
    u32 length;
    u8 command;
    u8 field_0x05[3];
    u32 handle;
    u8 field_0x0C[4];
    u32 io_result;
    u16 data_length;
    u8 field_0x16[2];
    u32 position;
};

enum {
    TRK_READ_FILE_RETRIES = 5,
    TRK_WRITE_FILE_RETRIES = 5,
};

extern u8 lbl_80095A6C[];
extern u8 lbl_80095A74[];
extern void MWTRACE(u32, ...);
extern void *memset(void *dst, int value, u32 size);
extern u32 strlen(const char *str);
extern DSError fn_80089244(MessageBufferID *buffer_id, MessageBuffer **buffer);
extern MessageBuffer *TRKGetBuffer(MessageBufferID buffer_id);
extern void fn_800891B4(MessageBufferID buffer_id);
extern DSError fn_80089144(MessageBuffer *buffer, u32 position);
extern DSError TRKAppendBuffer_ui8(MessageBuffer *buffer, const u8 *data, int count);
extern DSError TRKReadBuffer_ui8(MessageBuffer *buffer, u8 *data, int count);
extern DSError fn_80088B00(MessageBuffer *message);
extern s32 fn_800894FC(void);
extern void fn_8008944C(u32);

static const char fzgx_pool_strings_lbl_80095A78_0[24] = "Calling MessageSend\n";
static const char fzgx_pool_strings_lbl_80095A78_18[40] = "msg_command : 0x%02x hdr->cmdID 0x%02x\n";
static const char fzgx_pool_strings_lbl_80095A78_40[20] = "msg_error : 0x%02x\n";
static const char fzgx_pool_strings_lbl_80095A78_54[84] = "RequestSend : Bad ack or non ack received msg_command : 0x%02x msg_error 0x%02x\n";

DSError fn_8008AB20(MessageBuffer *request, MessageBufferID *reply_id, int retries, int timeout,
                    BOOL blocking);




/* --- dol/fn_8008A5AC.c --- */
/* --- dol/fn_8008A5AC.c --- */
// fn_8008A5AC: returns a constant.
int fn_8008A5AC(void) {
    return 0;
}

/* --- dol/fn_8008A5B4.c --- */
// fn_8008A5B4: returns a constant.
int fn_8008A5B4(void) {
    return 0;
}

/* --- dol/fn_8008A5BC.c --- */
/* --- dol/fn_8008A5BC.c --- */
extern void fn_8008D398(void *arg0, u32 arg1);
extern void fn_8008D028(void);

struct Fn8008A5BCData {
    u32 field0;
    u8 field4;
    u8 padding5[3];
    u8 field8;
    u8 padding9[0x38];
};

int fn_8008A5BC(void) {
    struct Fn8008A5BCData data;
    u32 size = 0x40;

    memset(&data, 0, size);
    data.field4 = 0x80;
    data.field0 = size;
    data.field8 = 0;
    fn_8008D398(&data, size);
    fn_8008D028();
    return 0;
}

/* --- dol/fn_8008A614.c --- */
extern void fn_80005518(void);

typedef struct InitData {
    u32 size;
    u8 type;
    u8 padding0[3];
    u8 flag;
    u8 padding1[0x3b];
} InitData;

int fn_8008A614(void) {

{
    InitData data;
    memset(&data, 0, 0x40);
    data.type = 0x80;
    data.size = 0x40;
    data.flag = 0;
    fn_8008D398(&data, 0x40);
}
    fn_80005518();
    return 0;
}

/* --- dol/fn_8008A66C.c --- */
__declspec(section ".data") u32 lbl_801A50B0[2] __attribute__((aligned(8)));
extern void fn_80088764(void *value, s32 arg);
extern void TRKPostEvent(void *value);

struct fn_8008A66C_Data {
    u32 size;
    u8 type;
    u8 padding0[3];
    u8 flag;
    u8 padding1[0x3b];
};

s32 fn_8008A66C(void) {
    struct fn_8008A66C_Data data;
    u32 value[3];

    lbl_801A50B0[0] = 0;
    memset(&data, 0, 0x40);
    data.type = 0x80;
    data.size = 0x40;
    data.flag = 0;
    fn_8008D398(&data, 0x40);
    fn_80088764(value, 1);
    TRKPostEvent(value);
    return 0;
}

/* --- dol/fn_8008A6E4.c --- */

struct fn_8008A6E4_local {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u8 unk_8;
    u8 pad_9[0x37];
};

s32 fn_8008A6E4(void) {
    struct fn_8008A6E4_local local;
    u32 size = 0x40;

    lbl_801A50B0[0] = 1;
    memset(&local, 0, size);
    local.unk_4 = 0x80;
    local.unk_0 = size;
    local.unk_8 = 0;
    fn_8008D398(&local, size);
    return 0;
}

/* --- dol/fn_8008A748.c --- */
void fn_8008A748(u32 arg0) {
    lbl_801A50B0[0] = arg0;
}

u32 fn_8008A754(void) {
    return lbl_801A50B0[0];
}

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

u32 fn_8008A80C(u32 arg0, u32 *arg1, u8 arg2, u32 *arg3) {
    MessageBufferID local_10;
    MessageBufferID local_c;
    MessageBuffer *local_8;
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
        result = (u32)TRKAppendBuffer_ui8(local_8, (const u8 *)&request, 0x40);
    }
    if (!result) {
        *arg3 = 0;
        *arg1 = 0xffffffff;
        result = fn_8008AB20(local_8, &local_10, 3, 3, 0);
        if (!result) {
            buf = TRKGetBuffer(local_10);
            if (buf) {
                *arg3 = *(u32 *)((u8 *)buf + 0x20);
                *arg1 = *(u32 *)((u8 *)buf + 0x28);
            }
        }
        fn_800891B4(local_10);
    }
    fn_800891B4(local_c);
    return result;
}

s32 fn_8008A91C(void *arg0, u32 *arg1) {
    MessageBufferID unk_10;
    MessageBufferID unk_c;
    MessageBuffer *unk_8;
    struct fn_8008A91C_buffer buffer;
    s32 result;
    void *buffer_ptr;

    memset(&buffer, 0, 0x40);
    buffer.unk_4 = 0xd3;
    buffer.unk_0 = 0x40;
    buffer.unk_8 = arg0;
    result = fn_80089244(&unk_c, &unk_8);
    if (!result) {
        result = (s32)TRKAppendBuffer_ui8(unk_8, (const u8 *)&buffer, 0x40);
    }
    if (!result) {
        *arg1 = 0;
        result = fn_8008AB20(unk_8, &unk_10, 3, 3, 0);
        if (!result) {
            buffer_ptr = TRKGetBuffer(unk_10);
        }
        if (!result) {
            *arg1 = *(u32 *)((u8 *)buffer_ptr + 0x20);
        }
        fn_800891B4(unk_10);
    }
    fn_800891B4(unk_c);
    return result;
}

u32 fn_8008AA04(const char *name, u8 type, u32 *status, u32 *length, void *buffer) {
    MessageBufferID local_10;
    MessageBufferID local_c;
    MessageBuffer *local_8;
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
    result = (u32)TRKAppendBuffer_ui8(local_8, (const u8 *)&request, 0x40);
    if (!result) {
        result = strlen(name);
        result = (u32)TRKAppendBuffer_ui8(local_8, (const u8 *)name, result + 1);
    }
    if (!result) {
        *length = 0;
        result = fn_8008AB20(local_8, &local_10, 7, 3, 0);
        if (!result) {
            buf = TRKGetBuffer(local_10);
        }
        *length = *(u32 *)((u8 *)buf + 0x20);
        *status = *(u32 *)((u8 *)buf + 0x18);
        fn_800891B4(local_10);
    }
    fn_800891B4(local_c);
    return result;
}

#pragma opt_loop_invariants off
DSError fn_8008AB20(MessageBuffer *arg0, MessageBufferID *arg1, int arg2, int arg3, BOOL arg4) {
    s32 v2;
    MessageBuffer *v5;
    u32 v3;
    s32 v1;
    u16 v6;
    u32 v9;
    s32 v10;
    s32 v4;

    v1 = arg3 + 1;
    v2 = 0;
    v4 = 1;
    *arg1 = -1;
    while (v1 != 0 && *arg1 == -1 && v2 == 0) {
        MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_0)));
        v2 = fn_80088B00(arg0);
        if (v2 == 0) {
            if (arg4 != 0) v3 = 0;
receive:
            do {
                *arg1 = fn_800894FC();
                v10 = *arg1;
                if (v10 != -1) break;
                if (arg4 == 0) continue;
                v3++;
                if (v3 >= 0x4C4B3EC) break;
            } while (1);
            if (v10 != -1) {
                v4 = 0;
                v5 = TRKGetBuffer(v10);
                fn_80089144(v5, 0);
                fn_8008A764((u32)v5 + 16, v5->length);
                v6 = *(u8 *)((u8 *)v5 + 20);
                MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_18)), v6, v6);
                if (v6 < 128) {
                    fn_8008944C((u32)*arg1);
                    *arg1 = -1;
                    goto receive; /* Keep the verified branch to receive. */
                }
            }
            if (*arg1 != -1) {
                if (v5->length < 64) v4 = 1;
                if (v2 == 0 && v4 == 0) {
                    v9 = *(u8 *)((u8 *)v5 + 24);
                    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_40)), v9);
                }
                if (v2 == 0 && v4 == 0 && ((s32)v6 != 128 || (s32)v9 != 0)) {
                    MWTRACE(8, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_54)), v6, v9);
                    v4 = 1;
                }
                if (v2 != 0 || v4 != 0) {
                    fn_800891B4(*arg1);
                    *arg1 = -1;
                }
            }
        }
        v1--;
    }
    if (*arg1 == -1) v2 = 2048;
    return v2;
}
#pragma opt_loop_invariants reset

DSError fn_8008AD00(u32 file_handle, u8 *data, u32 *count, DSIOResult *io_result, BOOL need_reply,
                    BOOL read) {
    DSError error;
    MessageBufferID reply_id;
    MessageBuffer *reply_buffer;
    u32 length;
    MessageBufferID request_id;
    MessageBuffer *request_buffer;
    u32 done;
    u8 reply_io_result;
    u32 reply_length;
    BOOL exit;
    struct TRKAccessFileRequest request;
    if (data == 0 || *count == 0) {
        return 2;
    }
    exit = 0;
    *io_result = 0;
    done = 0;
    error = 0;
    while (!exit && done < *count && error == 0 && *io_result == 0) {
        memset(&request, 0, sizeof(request));
        if (*count - done <= 0x800) {
            length = *count - done;
        } else {
            length = 0x800;
        }
        request.command = read ? TRK_MSG_READ_FILE : TRK_MSG_WRITE_FILE;
        if (read) {
            request.length = sizeof(request);
        } else {
            request.length = length + sizeof(request);
        }
        request.handle = file_handle;
        request.data_length = length;
        fn_80089244(&request_id, &request_buffer);
        error = TRKAppendBuffer_ui8(request_buffer, (u8 *)&request, sizeof(request));
        if (!read && error == 0) {
            error = TRKAppendBuffer_ui8(request_buffer, data + done, length);
        }
        if (error == 0) {
            if (need_reply) {
                BOOL poll = read && file_handle == 0;
                struct TRKFileSupportReply *reply;
                error =
                    fn_8008AB20(request_buffer, &reply_id,
                                read ? TRK_READ_FILE_RETRIES : TRK_WRITE_FILE_RETRIES, 3, !poll);
                if (error == 0) {
                    reply_buffer = TRKGetBuffer(reply_id);
                }
                reply = (struct TRKFileSupportReply *)reply_buffer->data;
                reply_io_result = (u8)reply->io_result;
                reply_length = reply->data_length;
                if (read && error == 0 && reply_length <= length) {
                    fn_80089144(reply_buffer, sizeof(request));
                    error = TRKReadBuffer_ui8(reply_buffer, data + done, reply_length);
                    if (error == 0x302) {
                        error = 0;
                    }
                }
                if (reply_length != length) {
#ifndef VERSION_GFZP01
                    if ((!read || reply_length >= length) && reply_io_result == 0) {
                        reply_io_result = 1;
                    }
#endif
                    length = reply_length;
                    exit = 1;
                }
                *io_result = reply_io_result;
                fn_800891B4(reply_id);
            } else {
                error = fn_80088B00(request_buffer);
            }
        }
        fn_800891B4(request_id);
        done += length;
    }
    *count = done;
    return error;
}
