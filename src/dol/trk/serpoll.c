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
u32 lbl_801A5098[6] __attribute__((aligned(8)));
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

static inline void TRKSetBufferUsed(TRKBuffer *msg, BOOL state);
DSError TRKInitializeMessageBuffers(void);

int fn_80089380(void) {
    return 0;
}

s32 TRKInitializeSerialHandler(void) {
    lbl_801A5098[0] = (u32)-1;
    lbl_801A5098[2] = 0;
    lbl_801A5098[3] = 0;

    MWTRACE(1, "TRK_Packet_Header \t    %ld bytes\n", 64);
    MWTRACE(1, "TRK_CMD_ReadMemory     %ld bytes\n", 64);
    MWTRACE(1, "TRK_CMD_WriteMemory    %ld bytes\n", 64);
    MWTRACE(1, "TRK_CMD_Connect \t    %ld bytes\n", 64);
    MWTRACE(1, "TRK_CMD_ReplyAck\t    %ld bytes\n", 64);
    MWTRACE(1, "TRK_CMD_ReadRegisters\t%ld bytes\n", 64);
    return 0;
}

void fn_8008944C(u32 value) {
    InitData data;
    fn_80088764(&data, 2);
    data.unk8 = value;
    lbl_801A5098[0] = (u32)-1;
    TRKPostEvent(&data);
}

void TRKGetInput(void) {
    InitData buffer;
    s32 result;

    result = fn_800894FC();
    if (result != -1) {
        TRKGetBuffer();
        fn_80088764(&buffer, 2);
        lbl_801A5098[0] = -1;
        buffer.unk8 = result;
        TRKPostEvent(&buffer);
    }
}

s32 fn_800894FC(void) {
    u8 local_50[0x888];
    s32 local_10[0x10];
    u32 local_C;
    s32 diff;
    u32 local_8;
    s32 result;

    if (fn_8008D410() <= 0) {
        return -1;
    }
    result = fn_80089244(&local_C, &local_8);
    MWTRACE(4, "TestForPacket : FreeBuffer is  %ld\n", result);
    fn_80089144((void *)local_8, 0);
    if (fn_8008D3D4(local_10, 0x40) == 0) {
        TRKAppendBuffer_ui8((void *)local_8, local_10, 0x40);
        result = local_C;
        if ((diff = local_10[0] - 0x40) > 0) {
            MWTRACE(1, "Reading payload %ld bytes\n", diff);
            if (fn_8008D3D4(local_50, local_10[0] - 0x40) == 0) {
                TRKAppendBuffer_ui8((void *)local_8, local_50, local_10[0]);
            } else {
                MWTRACE(8, "TestForPacket : Invalid size of packet hdr.size\n");
                fn_800891B4((void *)result);
                result = -1;
            }
        }
    } else {
        MWTRACE(8, "TestForPacket : Invalid size of packet\n");
        fn_800891B4((void *)result);
        result = -1;
    }
    MWTRACE(1, "TestForPacket returning %ld\n", result);
    return result;
}
void usr_put_initialize(void);
s32 fn_8008963C(const char *arg0);
s32 TRKDispatchMessage(TRKBuffer *arg0);
