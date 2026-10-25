#include <types.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/si.h>

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

void PADTypeAndStatusCallback(s32 chan, u32 type);

void SISetCommand(s32 chan, u32 command);

void PADOriginCallback(s32 chan, u32 error, OSContext *context);

void PADProbeCallback(s32 chan, u32 error, OSContext *context);

extern u32 lbl_801A697C;

extern u32 lbl_801A697C__fzgx_offset_4;

extern s32 lbl_801A64B4;

extern u32 lbl_801A6984;

extern u32 lbl_801A6990;

extern u32 lbl_801A64BC;

extern u32 lbl_801A64C0;

extern u32 lbl_801A64C8;

extern u32 lbl_801A64CC;

static u32 lbl_8015D0B0[4];

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

static inline void PADEnable(s32 chan) {
    u32 cmd;
    u32 chanBit;
    u32 data[2];
    chanBit = 0x80000000 >> chan;
    lbl_801A697C |= chanBit;
    SIGetResponse(chan, data);
    cmd = (0x40 << 16) | lbl_801A64BC;
    SISetCommand(chan, cmd);
    SIEnablePolling(lbl_801A697C);
}

static inline void DoReset(void) {
    u32 chanBit;
    lbl_801A64B4 = __cntlzw(lbl_801A697C__fzgx_offset_4);
    if (lbl_801A64B4 == 32) {
        return;
    }
    chanBit = 0x80000000 >> lbl_801A64B4;
    lbl_801A697C__fzgx_offset_4 &= ~chanBit;
    memset(&lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 0, sizeof(PADStatus));
    SIGetTypeAsync(lbl_801A64B4, PADTypeAndStatusCallback);
}

void PADTypeAndStatusCallback(s32 chan, u32 type) {
    u32 chanBit;
    u32 recalibrate;
    BOOL rc = 1;
    u32 error;
    chanBit = 0x80000000 >> lbl_801A64B4;
    error = type & 0xFF;
    recalibrate = lbl_801A6984 & chanBit;
    lbl_801A6984 &= ~chanBit;
    if (error & (0x0001 | 0x0002 | 0x0008 | 0x0004)) {
        DoReset();
        return;
    }
    type &= ~0xFF;
    lbl_8015D0B0[lbl_801A64B4] = type;
    if ((type & 0x18000000u) != 0x08000000u || !(type & 0x01000000)) {
        DoReset();
        return;
    }
    if (lbl_801A64C0 < 2) {
        PADEnable(lbl_801A64B4);
        DoReset();
        return;
    }
    if (!(type & 0x80000000) || (type & 0x04000000)) {
        if (recalibrate) {
            rc = SITransfer(lbl_801A64B4, &lbl_801A64CC, 3, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 10, PADOriginCallback,
                            0);
        } else {
            rc = SITransfer(lbl_801A64B4, &lbl_801A64C8, 1, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 10, PADOriginCallback,
                            0);
        }
    } else if ((type & 0x00100000) && (type & 0x00080000) == 0x00000000 && !(type & 0x00040000)) {
        if (type & 0x40000000) {
            rc = SITransfer(lbl_801A64B4, &lbl_801A64C8, 1, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 10, PADOriginCallback,
                            0);
        } else {
            rc = SITransfer(lbl_801A64B4, &lbl_8015D0C0__fzgx_offset_30[lbl_801A64B4], 3, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4],
                            8, PADProbeCallback, 0);
        }
    }
    if (!rc) {
        lbl_801A6990 |= chanBit;
        DoReset();
        return;
    }
}
