#include "types.h"

typedef struct TRKBuffer TRKBuffer;
struct TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
};

/* MetroTRK message command IDs (msgcmd.h) */
enum {
    kDSConnect = 0x01,
    kDSDisconnect = 0x02,
    kDSReset = 0x03,
    kDSVersions = 0x04,
    kDSSupportMask = 0x05,
    kDSOverride = 0x07,
    kDSReadMemory = 0x10,
    kDSWriteMemory = 0x11,
    kDSReadRegisters = 0x12,
    kDSWriteRegisters = 0x13,
    kDSSetOption = 0x17,
    kDSContinue = 0x18,
    kDSStep = 0x19,
    kDSStop = 0x1A
};

extern s32 fn_80089144(TRKBuffer *, u32);
extern void MWTRACE(u32, ...);
extern char lbl_80095850[];
extern char lbl_8009586C[];
extern s32 fn_8008A6E4(TRKBuffer *);
extern s32 fn_8008A66C(TRKBuffer *);
extern s32 fn_8008A614(TRKBuffer *);
extern s32 fn_8008A5BC(TRKBuffer *);
extern s32 fn_8008A5B4(TRKBuffer *);
extern s32 fn_8008A5AC(TRKBuffer *);
extern s32 fn_8008A3C0(TRKBuffer *);
extern s32 fn_8008A1CC(TRKBuffer *);
extern s32 fn_80089EEC(TRKBuffer *);
extern s32 fn_80089C5C(TRKBuffer *);
extern s32 fn_80089BAC(TRKBuffer *);
extern s32 fn_8008998C(TRKBuffer *);
extern s32 fn_800898E4(TRKBuffer *);
extern s32 fn_8008983C(TRKBuffer *);

s32 TRKDispatchMessage(TRKBuffer * arg0) {
    s32 result = 0x500;

    fn_80089144(arg0, 0);
    MWTRACE(1, lbl_80095850, arg0->data[4]);
    switch (arg0->data[4]) {
    case kDSConnect:
        result = fn_8008A6E4(arg0);
        break;
    case kDSDisconnect:
        result = fn_8008A66C(arg0);
        break;
    case kDSReset:
        result = fn_8008A614(arg0);
        break;
    case kDSOverride:
        result = fn_8008A5BC(arg0);
        break;
    case kDSVersions:
        result = fn_8008A5B4(arg0);
        break;
    case kDSSupportMask:
        result = fn_8008A5AC(arg0);
        break;
    case kDSReadMemory:
        result = fn_8008A3C0(arg0);
        break;
    case kDSWriteMemory:
        result = fn_8008A1CC(arg0);
        break;
    case kDSReadRegisters:
        result = fn_80089EEC(arg0);
        break;
    case kDSWriteRegisters:
        result = fn_80089C5C(arg0);
        break;
    case kDSContinue:
        result = fn_80089BAC(arg0);
        break;
    case kDSStep:
        result = fn_8008998C(arg0);
        break;
    case kDSStop:
        result = fn_800898E4(arg0);
        break;
    case kDSSetOption:
        result = fn_8008983C(arg0);
        break;
    }
    MWTRACE(1, lbl_8009586C, result);
    return result;
}
