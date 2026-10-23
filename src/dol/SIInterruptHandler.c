#include <dolphin/si/SIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/si.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

u32 VIGetCurrentLine();

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

void OSCancelAlarm(OSAlarm *alarm);

BOOL SIIsChanBusy(s32 chan);

vu32 __SIRegs[64] : FZGX_ADDR___SIRegs;

BOOL __SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                  SICallback callback);

void GetTypeCallback(s32 chan, u32 error, OSContext *context);

static unsigned char lbl_80123B50[68] = {
    60, 60, 32,  68,  111, 108, 112, 104, 105, 110, 32, 83, 68,  75,  32,  45,  32,
    83, 73, 9,   114, 101, 108, 101, 97,  115, 101, 32, 98, 117, 105, 108, 100, 58,
    32, 83, 101, 112, 32,  32,  53,  32,  50,  48,  48, 50, 32,  48,  53,  58,  51,
    51, 58, 48,  56,  32,  40,  48,  120, 50,  51,  48, 49, 41,  32,  62,  62,  0};

static SIControl Si = {
    -1, 0, 0, ((void *)0), ((void *)0),
};

static u32 Type[4] = {
    0x0008,
    0x0008,
    0x0008,
    0x0008,
};

/* Retail addresses .data through its section base before .bss. This
 * layout-only primer is discarded with .fzgxpool during integration. */
#pragma section code_type ".fzgxpool"
static void sdk_layout____data_0(void) {
    const void *volatile sink; /* fzgx-allow: S2 section-base layout primer */
    sink = lbl_80123B50;
    sink = &Si;
    sink = Type;
}
#pragma section code_type ".text"

static SIPacket Packet[4];

static OSAlarm lbl_8015CA90__fzgx_offset_0[4];

static unsigned char fzgx_pool_sdk_gap____bss_0_120[128];

static __OSInterruptHandler lbl_8015CBB0__fzgx_offset_0[4];

static unsigned char lbl_8015CBB0__fzgx_offset_10[48];

static vu32 lbl_8015CBB0__fzgx_offset_40[4];

#pragma section code_type ".fzgxpool"
static void sdk_layout____bss_0(void) {
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&Packet;
    sink = *(unsigned char *)&lbl_8015CA90__fzgx_offset_0;
    sink = *(unsigned char *)&fzgx_pool_sdk_gap____bss_0_120;
    sink = *(unsigned char *)&lbl_8015CBB0__fzgx_offset_0;
    sink = *(unsigned char *)&lbl_8015CBB0__fzgx_offset_10;
    sink = *(unsigned char *)&lbl_8015CBB0__fzgx_offset_40;
}
#pragma section code_type ".text"

static inline BOOL SIIsChanBusy(s32 chan) { return (Packet[chan].chan != -1 || Si.chan == chan); }

u32 CompleteTransfer();

static inline void SITransferNext(s32 chan) {
    int i;
    SIPacket *packet;
    for (i = 0; i < 4; ++i) {
        ++chan;
        chan %= 4;
        packet = &Packet[chan];
        if (packet->chan != -1 && packet->fire <= __OSGetSystemTime()) {
            if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input,
                             packet->inputBytes, packet->callback)) {
                OSCancelAlarm(&lbl_8015CA90__fzgx_offset_0[chan]);
                packet->chan = -1;
            }
            break;
        }
    }
}

void SIInterruptHandler(__OSInterrupt interrupt, OSContext *context) {
    u32 reg;
    reg = __SIRegs[13];
    if ((reg & 0xc0000000) == 0xc0000000) { /* fzgx-allow: A1 SI transfer-complete interrupt and mask bits, not an address */
        s32 chan;
        u32 sr;
        SICallback callback;
        chan = Si.chan;
        sr = CompleteTransfer();
        callback = Si.callback;
        Si.callback = 0;
        SITransferNext(chan);
        if (callback) {
            callback(chan, sr, context);
        }
        sr = __SIRegs[14];
        sr &= 0xf000000 >> (8 * chan);
        __SIRegs[14] = sr;
        if (Type[chan] == 0x0080 && !SIIsChanBusy(chan)) {
            extern u32 lbl_801A6810;
            SITransfer(chan, &lbl_801A6810, 1, &Type[chan], 3, GetTypeCallback,
                       (((65) * (((u32)__OSBusClock / 4) / 125000)) / 8));
        }
    }
    if ((reg & 0x18000000) == 0x18000000) {
        int i;
        u32 vcount;
        u32 x;
        vcount = VIGetCurrentLine() + 1;
        x = (Si.poll & 0x03ff0000) >> 16;
        for (i = 0; i < 4; ++i) {
            if (SIGetResponseRaw(i)) {
                lbl_8015CBB0__fzgx_offset_40[i] = vcount;
            }
        }
        for (i = 0; i < 4; ++i) {
            if (!(Si.poll & (0x80000000 >> (31 - 7 + i)))) {
                continue;
            }
            if (lbl_8015CBB0__fzgx_offset_40[i] == 0 || lbl_8015CBB0__fzgx_offset_40[i] + (x / 2) < vcount) {
                return;
            }
        }
        for (i = 0; i < 4; ++i) {
            lbl_8015CBB0__fzgx_offset_40[i] = 0;
        }
        for (i = 0; i < 4; ++i) {
            if (lbl_8015CBB0__fzgx_offset_0[i]) {
                lbl_8015CBB0__fzgx_offset_0[i](interrupt, context);
            }
        }
    }
}
