#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/si.h>

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

typedef void (*SPECCallback)(s32, PADStatus *, u32 *);

void *memset(void *dest, int value, size_t n);

extern int __cntlzw(uint);

extern void __DVDAudioBufferConfig(struct DVDCommandBlock *block, unsigned long enable,
                                   unsigned long size,
                                   void (*callback)(long, struct DVDCommandBlock *));

BOOL SIIsChanBusy(s32 chan);

u32 SIGetStatus(s32 chan);

u32 SIGetType(s32 chan);

BOOL PADReset(u32 mask);

void PADOriginUpdateCallback(s32 chan, u32 error, OSContext *context);

void PADTypeAndStatusCallback(s32 chan, u32 type);

void PADReceiveCheckCallback(s32 chan, u32 type);

extern s32 lbl_801A64B4;

extern u32 lbl_801A64C0;

extern u32 lbl_801A697C;

extern u32 lbl_801A697C__fzgx_offset_4;

extern u32 lbl_801A6984;

extern u32 lbl_801A6988;

extern u32 lbl_801A698C;

extern u32 lbl_801A6990;

extern PADStatus lbl_8015D0C0[4];

static void DoReset();

static void PADDisable(s32 chan);

void PADReceiveCheckCallback(s32 chan, u32 error);

extern SPECCallback lbl_801A64C4;

extern u32 lbl_801A64C8;

static inline void PADDisable(s32 chan) {
    BOOL enabled;
    u32 chanBit;
    enabled = OSDisableInterrupts();
    chanBit = 0x80000000 >> chan;
    SIDisablePolling(chanBit);
    lbl_801A697C &= ~chanBit;
    lbl_801A6988 &= ~chanBit;
    lbl_801A698C &= ~chanBit;
    lbl_801A6990 &= ~chanBit;
    OSSetWirelessID(chan, 0);
    OSRestoreInterrupts(enabled);
}

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

u32 PADRead(PADStatus *status) {
    BOOL enabled;
    s32 chan;
    u32 data[2];
    u32 chanBit;
    u32 sr;
    int chanShift;
    u32 motor;
    enabled = OSDisableInterrupts();
    motor = 0;
    for (chan = 0; chan < 4; chan++, status++) {
        chanBit = 0x80000000 >> chan;
        chanShift = 8 * (4 - 1 - chan);
        if (lbl_801A6990 & chanBit) {
            PADReset(0);
            status->err = -2;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else if ((lbl_801A697C__fzgx_offset_4 & chanBit) || lbl_801A64B4 == chan) {
            status->err = -2;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else if (!(lbl_801A697C & chanBit)) {
            status->err = -1;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else if (SIIsChanBusy(chan)) {
            status->err = -3;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else {
            sr = SIGetStatus(chan);
            if (sr & 0x0008) {
                SIGetResponse(chan, data);
                if (lbl_801A6988 & chanBit) {
                    status->err = 0;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                    if (!(lbl_801A698C & chanBit)) {
                        lbl_801A698C |= chanBit;
                        SIGetTypeAsync(chan, PADReceiveCheckCallback);
                    }
                } else {
                    PADDisable(chan);
                    status->err = -1;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                }
            } else {
                if (!(SIGetType(chan) & 0x20000000)) {
                    motor |= chanBit;
                }
                if (!SIGetResponse(chan, &data)) {
                    status->err = -3;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                } else if (data[0] & 0x80000000) {
                    status->err = -3;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                } else {
                    lbl_801A64C4(chan, status, data);
                    if (status->button & 0x2000) {
                        status->err = -3;
                        memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                        SITransfer(chan, &lbl_801A64C8, 1, &lbl_8015D0C0[chan], 10,
                                   PADOriginUpdateCallback, 0);
                    } else {
                        status->err = 0;
                        status->button &= ~0x0080;
                    }
                }
            }
        }
    }
    OSRestoreInterrupts(enabled);
    return motor;
}
