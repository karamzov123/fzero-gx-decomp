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
extern u8 lbl_801A36E8[];
extern char lbl_800956A0[];
extern u32 lbl_80095678[];
extern u32 MWTRACE(u32, ...);
extern u32 fn_8008D398(u32, u32);
extern u32 fn_8008AF40(u32);
extern u32 fn_8008AF48(u32);
extern void fn_8008963C(const char *);

DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length);
DSError TRKAppendBuffer(TRKBuffer *msg, const void *data, size_t length);

s32 fn_80088B00(TRKBuffer *arg0) {
    u32 t0;
    t0 = fn_8008D398((u32)arg0->data, arg0->length);
    MWTRACE(1, (u32)&lbl_80095678, t0);
    return 0;
}
