#include "types.h"


/* --- dol/TRKInitializeMessageBuffers.c --- */
/* --- dol/TRKInitializeMessageBuffers.c --- */
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

DSError fn_8008AF50(void *);

DSError fn_8008AF48(void *);

DSError fn_8008AF40(void *);

extern TRKBuffer lbl_801A36E8[3];

static inline void TRKSetBufferUsed(TRKBuffer *msg, BOOL state) { msg->isInUse = state; }

DSError TRKInitializeMessageBuffers(void) {
    int i;
    for (i = 0; i < 3; i++) {
        fn_8008AF50(&lbl_801A36E8[i]);
        fn_8008AF48(&lbl_801A36E8[i]);
        TRKSetBufferUsed(&lbl_801A36E8[i], 0);
        fn_8008AF40(&lbl_801A36E8[i]);
    }
    return DS_NoError;
}

/* --- dol/fn_80089380.c --- */
// fn_80089380: returns a constant.
int fn_80089380(void) {
    return 0;
}

/* --- dol/TRKInitializeSerialHandler.c --- */
struct TRKInitializeSerialHandler_lbl_801A5098 {
    u32 unk_0;
    u8 pad_4[0x4];
    u32 unk_8;
    u32 unk_C;
};

extern struct TRKInitializeSerialHandler_lbl_801A5098 lbl_801A5098[];
static const char fzgx_pool_strings_lbl_800956C0_0[36] = "TRK_Packet_Header \t    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_24[36] = "TRK_CMD_ReadMemory     %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_48[36] = "TRK_CMD_WriteMemory    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_6C[32] = "TRK_CMD_Connect \t    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_8C[32] = "TRK_CMD_ReplyAck\t    %ld bytes\n";
static const char fzgx_pool_strings_lbl_800956C0_AC[36] = "TRK_CMD_ReadRegisters\t%ld bytes\n";

extern void MWTRACE(u32, ...);

s32 TRKInitializeSerialHandler(void) {
    
    lbl_801A5098[0].unk_0 = -1;
    lbl_801A5098[0].unk_8 = 0;
    lbl_801A5098[0].unk_C = 0;
    
    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_800956C0_0)), 64);
    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_800956C0_24)), 64);
    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_800956C0_48)), 64);
    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_800956C0_6C)), 64);
    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_800956C0_8C)), 64);
    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_800956C0_AC)), 64);
    return 0;
}
