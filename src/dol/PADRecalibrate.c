#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSInterrupt.h>
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

extern u8 __gUnknown800030E3 : FZGX_ADDR___gUnknown800030E3;

void PADTypeAndStatusCallback(s32 chan, u32 type);

extern s32 lbl_801A64B4;

extern u32 lbl_801A697C;

extern u32 lbl_801A697C__fzgx_offset_4;

extern u32 lbl_801A6984;

extern u32 lbl_801A6988;

extern u32 lbl_801A698C;

extern u32 lbl_801A6990;

extern PADStatus lbl_8015D0C0[4];

static void DoReset();

static inline void DoReset() {
    u32 chanBit;
    lbl_801A64B4 = __cntlzw(lbl_801A697C__fzgx_offset_4);
    if (lbl_801A64B4 != 32) {
        (void)0;
        chanBit = (0x80000000 >> lbl_801A64B4);
        lbl_801A697C__fzgx_offset_4 &= ~chanBit;
        memset(&lbl_8015D0C0[lbl_801A64B4], 0, sizeof(PADStatus));
        SIGetTypeAsync(lbl_801A64B4, PADTypeAndStatusCallback);
    }
}

BOOL PADRecalibrate(u32 mask) {
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
    if (!(__gUnknown800030E3 & 0x40)) {
        lbl_801A6984 |= mask;
    }
    SIDisablePolling(disableBits);
    if (lbl_801A64B4 == 32)
        DoReset();
    OSRestoreInterrupts(enabled);
    return 1;
}
