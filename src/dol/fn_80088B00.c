#include "types.h"


/* --- dol/fn_80088B00.c --- */
struct fn_80088B00_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

extern u32 MWTRACE(u32, ...);
extern u32 fn_8008D398(u32, u32);
extern u32 lbl_80095678[];

s32 fn_80088B00(struct fn_80088B00_Arg0 *arg0) {
    u32 t0;
    t0 = fn_8008D398(((u32)arg0 + 16), arg0->unk_8);
    MWTRACE(1, (u32)&lbl_80095678, t0);
    return 0;
}

/* --- dol/TRKReadBuffer_ui32.c --- */
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

DSError TRKReadBuffer1_ui32(TRKBuffer *buffer, u32 *data);

DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length);

extern BOOL gTRKBigEndian;

void *fn_800035C0(void *dst, const void *src, size_t n);

static inline DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length) {
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
    err = TRKReadBuffer(buffer, (void *)bigEndianData, sizeof(*data));
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
