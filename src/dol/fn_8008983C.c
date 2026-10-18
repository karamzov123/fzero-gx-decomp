
#include "types.h"

typedef int DSError;

typedef int MessageCommandID;

typedef struct MessageBuffer {
    u32 mutex;
    BOOL is_in_use;
    u32 length;
    u32 position;
    u8 data[0x880];
} MessageBuffer;

struct TRKReplyPacket {
    u32 length;
    u8 command;
    u8 field_0x05[3];
    u8 error;
    u8 field_0x09[0x37];
};

typedef char TRKReplyPacketSizeCheck[sizeof(struct TRKReplyPacket) == 0x40 ? 1 : -1];

DSError fn_8008983C(MessageBuffer *message);

DSError fn_8008D398(const void *data, u32 length);

BOOL fn_8008963C(const char *message);

void fn_8008D7C0(u8 serial_io);

void *memset(void *destination, int value, unsigned int size);

static inline DSError TRKStandardACK(MessageBuffer *message, MessageCommandID command,
                                     int reply_error) {
    struct TRKReplyPacket reply;
    memset(&reply, 0, sizeof(reply));
    reply.command = command;
    reply.length = sizeof(reply);
    reply.error = reply_error;
    fn_8008D398(&reply, sizeof(reply));
    return 0;
}

DSError fn_8008983C(MessageBuffer *message) {
    u8 enable = message->data[0x0C];
    if (message->data[0x08] == 1) {
        fn_8008963C("\nMetroTRK Option : SerialIO - ");
        if (enable) {
            fn_8008963C("Enable\n");
        } else {
            fn_8008963C("Disable\n");
        }
        fn_8008D7C0(enable);
    }
    TRKStandardACK(message, 0x80, 0);
    return 0;
}
