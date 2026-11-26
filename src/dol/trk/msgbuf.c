#include "types.h"

enum {
    DS_NoError = 0x0,
    DS_StepError = 0x1,
    DS_ParameterError = 0x2,
    DS_EventQueueFull = 0x100,
    DS_NoMessageBufferAvailable = 0x300,
    DS_MessageBufferOverflow = 0x301,
    DS_MessageBufferReadError = 0x302,
    DS_DispatchError = 0x500,
    DS_InvalidMemory = 0x700,
    DS_InvalidRegister = 0x701,
    DS_CWDSException = 0x702,
    DS_UnsupportedError = 0x703,
    DS_InvalidProcessID = 0x704,
    DS_InvalidThreadID = 0x705,
    DS_OSError = 0x706,
    DS_Error800 = 0x800,
};

typedef int DSError;

typedef struct TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
} TRKBuffer;

extern BOOL gTRKBigEndian;
extern TRKBuffer lbl_801A36E8[3];
extern char lbl_800956A0[];
extern u32 lbl_80095678[];
extern u32 MWTRACE(u32, ...);
extern u32 fn_8008D398(u32, u32);
extern void *fn_800035C0(void *dst, const void *src, size_t n);
extern void *fn_80003590(void *dst, int value, size_t size);
extern u32 fn_8008AF40(u32);
extern u32 fn_8008AF48(u32);
extern void fn_8008963C(const char *);

DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length);
DSError TRKAppendBuffer(TRKBuffer *msg, const void *data, size_t length);

s32 fn_80088B00(TRKBuffer *arg0);

static inline DSError TRKReadBuffer_inline(TRKBuffer *msg, void *data, size_t length) {
    DSError error = DS_NoError;
    unsigned int bytesLeft;
    if (length == 0) {
        return DS_NoError;
    }
    bytesLeft = msg->length - msg->position;
    if (length > bytesLeft) {
        error = DS_MessageBufferReadError;
        length = bytesLeft;
    }
    fn_800035C0(data, msg->data + msg->position, length);
    msg->position += length;
    return error;
}

static inline DSError TRKReadBuffer1_ui32(TRKBuffer *buffer, u32 *data) {
    DSError err;
    u8 *bigEndianData;
    u8 *byteData;
    u8 swapBuffer[sizeof(data)];
    if (gTRKBigEndian) {
        bigEndianData = (u8 *)data;
    } else {
        bigEndianData = swapBuffer;
    }
    err = TRKReadBuffer_inline(buffer, (void *)bigEndianData, sizeof(*data));
    if (!gTRKBigEndian && err == DS_NoError) {
        byteData = (u8 *)data;
        byteData[0] = bigEndianData[3];
        byteData[1] = bigEndianData[2];
        byteData[2] = bigEndianData[1];
        byteData[3] = bigEndianData[0];
    }
    return err;
}

DSError TRKReadBuffer_ui32(TRKBuffer *buffer, u32 *data, int count) {
    DSError err;
    s32 i;
    for (i = 0, err = DS_NoError; err == DS_NoError && i < count; i++) {
        err = TRKReadBuffer1_ui32(buffer, &(data[i]));
    }
    return err;
}

static inline DSError TRKReadBuffer1_ui8(TRKBuffer *buffer, u8 *data) {
    return TRKReadBuffer_inline(buffer, (void *)data, 1);
}

DSError TRKReadBuffer_ui8(TRKBuffer *buffer, u8 *data, int count) {
    DSError err;
    int i;
    for (i = 0, err = DS_NoError; err == DS_NoError && i < count; i++) {
        err = TRKReadBuffer1_ui8(buffer, &(data[i]));
    }
    return err;
}

DSError TRKReadBuffer1_ui64(TRKBuffer *buffer, u64 *data) {
    DSError err;
    u8 *bigEndianData;
    u8 *byteData;
    u8 swapBuffer[sizeof(data)];
    if (gTRKBigEndian) {
        bigEndianData = (u8 *)data;
    } else {
        bigEndianData = swapBuffer;
    }
    err = TRKReadBuffer_inline(buffer, (void *)bigEndianData, sizeof(*data));
    if (!gTRKBigEndian && err == 0) {
        byteData = (u8 *)data;
        byteData[0] = bigEndianData[7];
        byteData[1] = bigEndianData[6];
        byteData[2] = bigEndianData[5];
        byteData[3] = bigEndianData[4];
        byteData[4] = bigEndianData[3];
        byteData[5] = bigEndianData[2];
        byteData[6] = bigEndianData[1];
        byteData[7] = bigEndianData[0];
    }
    return err;
}

static inline DSError TRKAppendBuffer_inline(TRKBuffer *msg, const void *data, size_t length) {
    DSError error = DS_NoError;
    u32 bytesLeft;
    if (length == 0) {
        return DS_NoError;
    }
    bytesLeft = 0x880 - msg->position;
    if (bytesLeft < length) {
        error = DS_MessageBufferOverflow;
        length = bytesLeft;
    }
    if (length == 1) {
        msg->data[msg->position] = ((u8 *)data)[0];
    } else {
        fn_800035C0(msg->data + msg->position, data, length);
    }
    msg->position += length;
    msg->length = msg->position;
    return error;
}

static inline DSError TRKAppendBuffer1_ui32(TRKBuffer *buffer, const u32 data) {
    u8 *bigEndianData;
    u8 *byteData;
    u8 swapBuffer[sizeof(data)];
    if (gTRKBigEndian) {
        bigEndianData = (u8 *)&data;
    } else {
        byteData = (u8 *)&data;
        bigEndianData = swapBuffer;
        bigEndianData[0] = byteData[3];
        bigEndianData[1] = byteData[2];
        bigEndianData[2] = byteData[1];
        bigEndianData[3] = byteData[0];
    }
    return TRKAppendBuffer_inline(buffer, (const void *)bigEndianData, sizeof(data));
}

DSError TRKAppendBuffer_ui32(TRKBuffer *buffer, const u32 *data, int count) {
    DSError err;
    int i;
    for (i = 0, err = DS_NoError; err == DS_NoError && i < count; i++) {
        err = TRKAppendBuffer1_ui32(buffer, data[i]);
    }
    return err;
}

static inline DSError TRKAppendBuffer1_ui8(TRKBuffer *buffer, const u8 data) {
    if (buffer->position >= (0x800 + 0x80)) {
        return DS_MessageBufferOverflow;
    }
    buffer->data[buffer->position++] = data;
    buffer->length++;
    return DS_NoError;
}

DSError TRKAppendBuffer_ui8(TRKBuffer *buffer, const u8 *data, int count) {
    DSError err;
    int i;
    for (i = 0, err = DS_NoError; err == DS_NoError && i < count; i++) {
        err = TRKAppendBuffer1_ui8(buffer, data[i]);
    }
    return err;
}

DSError TRKAppendBuffer1_ui64(TRKBuffer *buffer, const u64 data) {
    u8 *bigEndianData;
    u8 *byteData;
    u8 swapBuffer[sizeof(data)];
    if (gTRKBigEndian) {
        bigEndianData = (u8 *)&data;
    } else {
        byteData = (u8 *)&data;
        bigEndianData = swapBuffer;
        bigEndianData[0] = byteData[7];
        bigEndianData[1] = byteData[6];
        bigEndianData[2] = byteData[5];
        bigEndianData[3] = byteData[4];
        bigEndianData[4] = byteData[3];
        bigEndianData[5] = byteData[2];
        bigEndianData[6] = byteData[1];
        bigEndianData[7] = byteData[0];
    }
    return TRKAppendBuffer_inline(buffer, (const void *)bigEndianData, sizeof(data));
}

DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length) {
    DSError error = DS_NoError;
    unsigned int bytesLeft;
    if (length == 0) {
        return DS_NoError;
    }
    bytesLeft = msg->length - msg->position;
    if (length > bytesLeft) {
        error = DS_MessageBufferReadError;
        length = bytesLeft;
    }
    fn_800035C0(data, msg->data + msg->position, length);
    msg->position += length;
    return error;
}

DSError TRKAppendBuffer(TRKBuffer *msg, const void *data, size_t length) {
    DSError error = DS_NoError;
    u32 bytesLeft;
    if (length == 0) {
        return DS_NoError;
    }
    bytesLeft = 0x880 - msg->position;
    if (bytesLeft < length) {
        error = DS_MessageBufferOverflow;
        length = bytesLeft;
    }
    if (length == 1) {
        msg->data[msg->position] = ((u8 *)data)[0];
    } else {
        fn_800035C0(msg->data + msg->position, data, length);
    }
    msg->position += length;
    msg->length = msg->position;
    return error;
}

s32 fn_80089144(TRKBuffer *arg0, u32 arg1) {
    s32 v0;
    v0 = 0;
    if (arg1 > 2176) {
        v0 = 769;
    } else {
        arg0->position = arg1;
        if (arg1 > arg0->length) {
            arg0->length = arg1;
        }
    }
    return v0;
}

u32 fn_80089174(TRKBuffer *arg0, u32 arg1) {
    arg0->length = 0;
    arg0->position = 0;
    if ((s32)arg1 == 0) {
        return (u32)fn_80003590(arg0->data, 0, sizeof(arg0->data));
    }
    return (u32)arg0;
}

u32 fn_800891B4(u32 arg0) {
    u32 v0;
    s32 v1;
    u32 t0, t1;
    v0 = arg0;
    if ((s32)arg0 != -1) {
        if ((s32)v0 >= 0) {
            if ((s32)v0 < 3) {
                v1 = (v0 * 2192);
                v0 = (u32)((u8 *)&lbl_801A36E8 + v1);
                t0 = fn_8008AF48((u32)v0);
                v0 = t0;
                v0 = (u32)((u8 *)&lbl_801A36E8 + v1);
                *(u32 *)((u8 *)((u8 *)&lbl_801A36E8 + v1) + 4) = 0;
                t1 = fn_8008AF40((u32)v0);
                v0 = t1;
            }
        }
    }
    return v0;
}

u32 TRKGetBuffer(s32 arg0) {
    u32 v0;

    v0 = 0;
    if (arg0 >= 0 && arg0 < 3) {
        v0 = (u32)((u8 *)&lbl_801A36E8 + arg0 * 0x890);
    }
    return v0;
}

u32 fn_80089244(u32 *arg0, u32 *arg1) {
    TRKBuffer *v2;
    s32 v0;
    s32 v1;

    *arg1 = 0;
    v0 = 0x300;
    v1 = 0;
    while (v1 < 3) {
        v2 = 0;
        if (v1 >= 0 && v1 < 3) {
            v2 = (TRKBuffer *)((u8 *)&lbl_801A36E8 + v1 * 0x890);
        }
        fn_8008AF48((u32)v2);
        if (v2->isInUse == 0) {
            v2->length = 0;
            v0 = 0;
            v2->position = 0;
            v2->isInUse = 1;
            *arg1 = (u32)v2;
            *arg0 = v1;
            v1 = 3;
        }
        fn_8008AF40((u32)v2);
        v1++;
    }
    if (v0 == 0x300) {
        fn_8008963C(lbl_800956A0);
    }
    return v0;
}

extern DSError fn_8008AF50(void *mutex);

static inline void TRKSetBufferUsed(TRKBuffer *msg, BOOL state) { msg->isInUse = state; }

DSError TRKInitializeMessageBuffers(void) {
    int i;
    for (i = 0; i < 3; i++) {
        fn_8008AF50(&lbl_801A36E8[i]);
        fn_8008AF48((u32)&lbl_801A36E8[i]);
        TRKSetBufferUsed(&lbl_801A36E8[i], 0);
        fn_8008AF40((u32)&lbl_801A36E8[i]);
    }
    return 0;
}
