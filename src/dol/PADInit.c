#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/si.h>
#include "sdk_addresses.h"

typedef unsigned int uint;

typedef struct PADStatus {
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
    s8 err;
} PADStatus;

void *memset(void *dest, int value, size_t n);

extern int __cntlzw(uint);

extern void __DVDAudioBufferConfig(struct DVDCommandBlock *block, unsigned long enable,
                                   unsigned long size,
                                   void (*callback)(long, struct DVDCommandBlock *));

void OSRegisterResetFunction(OSResetFunctionInfo *info);

void OSRegisterVersion(const char *version);

void PADSetSpec(u32 spec);

BOOL PADReset(u32 mask);

void PADTypeAndStatusCallback(s32 chan, u32 type);

extern u32 __PADSpec;

extern u32 lbl_801A6818;

extern u16 __OSWirelessPadFixMode : FZGX_ADDR___OSWirelessPadFixMode;

extern const char *lbl_801A64B0;

extern s32 lbl_801A64B4;

extern u32 lbl_801A64C0;

extern BOOL lbl_801A6978;

extern u32 lbl_801A697C;

extern u32 lbl_801A697C__fzgx_offset_4;

extern u32 lbl_801A6984;

extern u32 lbl_801A6988;

extern u32 lbl_801A698C;

extern u32 lbl_801A6990;

static void DoReset();

extern OSResetFunctionInfo lbl_801245E0;

static unsigned char lbl_8015D0B0[16];

static PADStatus lbl_8015D0C0__fzgx_offset_0[4];

static u32 lbl_8015D0C0__fzgx_offset_30[4];

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
// Hardware or OS state can change asynchronously.
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&lbl_8015D0B0;
    sink = *(unsigned char *)&lbl_8015D0C0__fzgx_offset_0;
    sink = *(unsigned char *)&lbl_8015D0C0__fzgx_offset_30;
}
#pragma section code_type ".text"

static inline void DoReset() {
    u32 chanBit;
    lbl_801A64B4 = __cntlzw(lbl_801A697C__fzgx_offset_4);
    if (lbl_801A64B4 != 32) {
        (void)0;
        chanBit = (0x80000000 >> lbl_801A64B4);
        lbl_801A697C__fzgx_offset_4 &= ~chanBit;
        memset(&lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 0, sizeof(PADStatus));
        SIGetTypeAsync(lbl_801A64B4, PADTypeAndStatusCallback);
    }
}

static inline int PADReset(u32 mask) {
    BOOL enabled;
    u32 disableBits;
    (void)0;
    enabled = OSDisableInterrupts();
    mask |= lbl_801A6990;
    lbl_801A6990 = 0;
    mask &= ~(lbl_801A6988 | lbl_801A698C);
    lbl_801A697C__fzgx_offset_4 |= mask;
    disableBits = lbl_801A697C__fzgx_offset_4 & lbl_801A697C;
    lbl_801A697C &= ~mask;
    if (lbl_801A64C0 == 4) {
        lbl_801A6984 |= mask;
    }
    SIDisablePolling(disableBits);
    if (lbl_801A64B4 == 0x20) {
        DoReset();
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL PADInit() {
    s32 chan;
    if (lbl_801A6978) {
        return 1;
    }
    OSRegisterVersion(lbl_801A64B0);
    if (__PADSpec)
        PADSetSpec(__PADSpec);
    lbl_801A6978 = 1;
    if (lbl_801A6818 != 0) {
        OSTime time = OSGetTime();
        __OSWirelessPadFixMode = (u16)((((time) & 0xffff) + ((time >> 16) & 0xffff) +
                                        ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) &
                                       0x3fffu);
        lbl_801A6984 = 0x80000000 | 0x40000000 | 0x20000000 | 0x10000000;
    }
    for (chan = 0; chan < 4; ++chan) {
        lbl_8015D0C0__fzgx_offset_30[chan] =
            (0x4D << 24) | (chan << 22) | ((__OSWirelessPadFixMode & 0x3fffu) << 8);
    }
    SIRefreshSamplingRate();
    OSRegisterResetFunction(&lbl_801245E0);
    return PADReset(0x80000000 | 0x40000000 | 0x20000000 | 0x10000000);
}
