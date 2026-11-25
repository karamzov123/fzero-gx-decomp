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

typedef struct InitData {
    u32 unk0;
    u32 unk4;
    s32 unk8;
} InitData;

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

extern TRKBuffer lbl_801A36E8[3];
extern u32 lbl_801A5098[6];
extern u8 lbl_800956C0[400];
extern char lbl_80095850[];
extern char lbl_8009586C[];

extern DSError fn_8008AF50(void *);
extern DSError fn_8008AF48(void *);
extern DSError fn_8008AF40(void *);
extern void MWTRACE(u32, ...);
extern void fn_80088764(InitData *data, int value);
extern void TRKPostEvent(InitData *data);
extern void TRKGetBuffer(void);
extern s32 fn_8008D410(void);
extern s32 fn_80089244(u32 *out_a, u32 *out_b);
extern s32 fn_80089144(void *value, u32 arg1);
extern s32 fn_8008D3D4(void *dst, u32 size);
extern s32 TRKAppendBuffer_ui8(void *buffer, const void *data, u32 length);
extern void fn_800891B4(void *value);
extern u32 fn_8008A754(void);
extern void OSReport(const char *);
extern void fn_8008A748(u32);
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

s32 fn_800894FC(void);

static const char fzgx_pool_strings_lbl_800956C0_0[36] = "TRK_Packet_Header \t    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_24[36] = "TRK_CMD_ReadMemory     %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_48[36] = "TRK_CMD_WriteMemory    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_6C[32] = "TRK_CMD_Connect \t    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_8C[32] = "TRK_CMD_ReplyAck\t    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_AC[36] = "TRK_CMD_ReadRegisters\t%ld bytes\n";
static inline void TRKSetBufferUsed(TRKBuffer *msg, BOOL state);
DSError TRKInitializeMessageBuffers(void);
int fn_80089380(void);
s32 TRKInitializeSerialHandler(void);
void fn_8008944C(u32 value);
void TRKGetInput(void);
s32 fn_800894FC(void);
void usr_put_initialize(void);
s32 fn_8008963C(const char *arg0);

s32 TRKDispatchMessage(TRKBuffer *arg0) {
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

int TRKInitializeDispatcher(void) {
    return 0;
}
