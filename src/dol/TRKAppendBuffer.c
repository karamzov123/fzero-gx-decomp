#include "types.h"


/* --- dol/TRKAppendBuffer.c --- */
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

void *fn_800035C0(void *dst, const void *src, size_t n);

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

/* --- dol/fn_80089144.c --- */
/* --- dol/fn_80089144.c --- */
struct fn_80089144_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};

s32 fn_80089144(struct fn_80089144_Arg0 *arg0, u32 arg1) {
    s32 v0;
    v0 = 0;
    if (arg1 > 2176) {
    v0 = 769;
    } else {
    arg0->unk_C = arg1;
    if (arg1 > arg0->unk_8) {
    arg0->unk_8 = arg1;
    }
    }
    return v0;
}

/* --- dol/fn_80089174.c --- */
/* --- dol/fn_80089174.c --- */
extern u32 fn_80003590(u32, u32, u32);

struct fn_80089174_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};

u32 fn_80089174(struct fn_80089174_Arg0 *arg0, u32 arg1) {
    u32 v0;
    u32 t0;
    arg0->unk_8 = 0;
    arg0->unk_C = 0;
    v0 = (u32)arg0;
    if ((s32)arg1 == 0) {
    v0 += 16;
    t0 = fn_80003590(v0, 0, 2176);
    v0 = t0;
    }
    return v0;
}

/* --- dol/fn_800891B4.c --- */
extern u32 fn_8008AF40(u32);
extern u32 fn_8008AF48(u32);
extern u32 lbl_801A36E8[];

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
