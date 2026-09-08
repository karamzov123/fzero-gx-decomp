#ifndef FZERO_DOLPHIN_METROTRK_H
#define FZERO_DOLPHIN_METROTRK_H

/*
 * GFZE01 MetroTRK ABI slice. Fourth header pilot after CARD, EXI and GX, and
 * grown the same way: a type is here because a conversion will not compile
 * without it, with the retail access that pins it cited alongside.
 *
 * The base typedefs keep the spellings the metrotrk units already declared
 * inline (`unsigned int` for u32) so adopting this header cannot move their
 * codegen.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long size_t;

/*
 * melee's MetroTRK/dserror.h verbatim -- an error enum is an ABI only through
 * its values, and every one of these appears as a literal in retail. The build
 * passes -enum int, so DSError is 4 bytes.
 */
typedef enum DSError {
    kUARTError = -0x0001,
    kNoError = 0x0000,
    kStepError = 0x0001,
    kParameterError = 0x0002,
    kEventQueueFull = 0x0100,
    kNoMessageBufferAvailable = 0x0300,
    kMessageBufferOverflow = 0x0301,
    kMessageBufferReadError = 0x0302,
    kDispatchError = 0x0500,
    kInvalidMemory = 0x0700,
    kInvalidRegister = 0x0701,
    kCWDSException = 0x0702,
    kUnsupportedError = 0x0703,
    kInvalidProcessId = 0x0704,
    kInvalidThreadId = 0x0705,
    kOsError = 0x0706,
    kWaitACKError = 0x0800
} DSError;

/*
 * 4 bytes here, unlike melee, where DSMutex is empty and the struct below is
 * 0x88C. Retail's is 0x890 -- `mulli r4, r3, 0x890` indexes gTRKMsgBufs in
 * TRKGetBuffer, and gTRKMsgBufs is 0x19B0 = 3 * 0x890 -- with fInUse cleared
 * by `stw r0, 4(r31)` in TRKReleaseBuffer. So the extra four bytes are at the
 * FRONT and every later field is melee's offset plus 4.
 */
typedef u32 DSMutex;

#define kMessageBufferSize (0x800 + 0x80)
#define NUM_BUFFERS 3

typedef struct MessageBuffer {
    /* 0x00 */ DSMutex fMutex;
    /* 0x04 */ int fInUse;      /* stw, not stb: a word, not melee's bool */
    /* 0x08 */ u32 fLength;     /* lwz r0, 8(r3)  in TRKSetBufferPosition */
    /* 0x0C */ u32 fPosition;   /* stw r4, 0xc(r3) in the same function */
    /* 0x10 */ u8 fData[kMessageBufferSize];
} MessageBuffer;

typedef struct TRKMsgBufs {
    /* 0x00 */ MessageBuffer buffers[NUM_BUFFERS];
} TRKMsgBufs;

/*
 * `bool` is int-sized here. TRKTargetStopped returns gTRKState.stopped with a
 * single `lwz r3, 0x98(r3)` and no narrowing, so the field -- and the return
 * type melee spells `bool` -- is a word.
 */
typedef int bool;
#define false 0
#define true 1

/* melee's MetroTRK/msgcmd.h verbatim: wire protocol command bytes. */
typedef enum MessageCommandID {
    kDSPing = 0x00,
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
    kDSStop = 0x1A,
    kDSReplyACK = 0x80,
    kDSNotifyStopped = 0x90,
    kDSNotifyException = 0x91,
    kDSWriteFile = 0xD0,
    kDSReadFile = 0xD1,
    kDSOpenFile = 0xD2,
    kDSCloseFile = 0xD3,
    kDSPositionFile = 0xD4,
    kDSReplyNAK = 0xFF
} MessageCommandID;

#ifndef NULL
#define NULL 0
#endif

/*
 * Declared here rather than in the unit because a reference body spliced
 * ABOVE the definition would otherwise implicitly declare it `int (...)`,
 * and the definition below then fails to redeclare it. That is the whole
 * error for TRKReleaseBuffer, and it has nothing to do with its body.
 */
DSError TRKAcquireMutex(void* mutex);

/* TRK's own memory helpers; melee: MetroTRK/mem_TRK.h. */
void* TRK_memcpy(void* dst, const void* src, unsigned long n);
void* TRK_memset(void* dst, int val, unsigned long n);

/* Compile-time target ABI guards. */
typedef char TRK_u32_is_4_bytes[(sizeof(u32) == 4) ? 1 : -1];
typedef char TRK_error_is_4_bytes[(sizeof(DSError) == 4) ? 1 : -1];
typedef char TRK_buffer_is_0x890_bytes[(sizeof(MessageBuffer) == 0x890) ? 1 : -1];
typedef char TRK_bufs_are_0x19B0_bytes[(sizeof(TRKMsgBufs) == 0x19B0) ? 1 : -1];
typedef char TRK_bool_is_4_bytes[(sizeof(bool) == 4) ? 1 : -1];
typedef char TRK_command_is_4_bytes[(sizeof(MessageCommandID) == 4) ? 1 : -1];

#endif
