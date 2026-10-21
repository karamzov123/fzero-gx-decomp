#include "types.h"

/*types*/

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
DSError fn_80089244(MessageBufferID *buffer_id, MessageBuffer **buffer);
MessageBuffer *TRKGetBuffer(MessageBufferID buffer_id);
void fn_800891B4(MessageBufferID buffer_id);
DSError fn_80089144(MessageBuffer *buffer, u32 position);
DSError TRKAppendBuffer_ui8(MessageBuffer *buffer, const u8 *data, int count);
DSError TRKReadBuffer_ui8(MessageBuffer *buffer, u8 *data, int count);
DSError fn_80088B00(MessageBuffer *message);
DSError fn_8008AB20(MessageBuffer *request, MessageBufferID *reply_id, int retries, int timeout,
                       BOOL blocking);
void *memset(void *destination, int value, unsigned int size);
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

DSError fn_8008AB20(MessageBuffer *request, MessageBufferID *reply_id, int retries, int timeout,
                       BOOL blocking);

#pragma use_lmw_stmw on
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
                reply_io_result = reply->io_result;
                reply_length = reply->data_length;
                if (read && error == 0 && reply_length <= length) {
                    fn_80089144(reply_buffer, sizeof(request));
                    error = TRKReadBuffer_ui8(reply_buffer, data + done, reply_length);
                    if (error == 0x302) {
                        error = 0;
                    }
                }
                if (reply_length != length) {
                    if ((!read || reply_length >= length) && reply_io_result == 0) {
                        reply_io_result = 1;
                    }
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
