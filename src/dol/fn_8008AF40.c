#include "types.h"
#pragma use_lmw_stmw on

/* --- dol/fn_8008AD00.c --- */
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

DSError fn_8008AD00(u32 file_handle, u8 *data, u32 *count, DSIOResult *io_result, BOOL need_reply,
                    BOOL read);

/* --- dol/fn_8008AF40.c --- */
/* --- dol/fn_8008AF40.c --- */
// fn_8008AF40: returns a constant.
int fn_8008AF40(void) {
    return 0;
}

/* --- dol/fn_8008AF48.c --- */
// fn_8008AF48: returns a constant.
int fn_8008AF48(void) {
    return 0;
}

/* --- dol/fn_8008AF50.c --- */
// fn_8008AF50: returns a constant.
int fn_8008AF50(void) {
    return 0;
}
