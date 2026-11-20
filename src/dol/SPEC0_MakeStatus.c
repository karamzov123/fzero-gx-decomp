#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/si.h>


/* --- dol/SPEC0_MakeStatus.c --- */
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

void SPEC0_MakeStatus(s32 chan, PADStatus *status, u32 data[2]) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0008) ? 0x0100 : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? 0x0200 : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? 0x0400 : 0;
    status->button |= ((data[0] >> 16) & 0x0001) ? 0x0800 : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? 0x1000 : 0;
    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);
    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];
    status->analogA = 0;
    status->analogB = 0;
    if (170 <= status->triggerLeft) {
        status->button |= 0x0040;
    }
    if (170 <= status->triggerRight) {
        status->button |= 0x0020;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

/* --- dol/SPEC1_MakeStatus.c --- */
void SPEC1_MakeStatus(s32 chan, PADStatus *status, u32 data[2]) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0080) ? 0x0100 : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? 0x0200 : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? 0x0400 : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? 0x0800 : 0;
    status->button |= ((data[0] >> 16) & 0x0200) ? 0x1000 : 0;
    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);
    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];
    status->analogA = 0;
    status->analogB = 0;
    if (170 <= status->triggerLeft) {
        status->button |= 0x0040;
    }
    if (170 <= status->triggerRight) {
        status->button |= 0x0020;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

/* --- dol/SPEC2_MakeStatus.c --- */
extern u32 lbl_801A64BC;

extern PADStatus lbl_8015D0C0[4];

static s8 ClampS8(s8 var, s8 org);

static u8 ClampU8(u8 var, u8 org);

static inline s8 ClampS8(s8 var, s8 org) {
    if (0 < org) {
        s8 min = (s8)(-128 + org);
        if (var < min)
            var = min;
    } else if (org < 0) {
        s8 max = (s8)(127 + org);
        if (max < var)
            var = max;
    }
    return var -= org;
}

static inline u8 ClampU8(u8 var, u8 org) {
    if (var < org)
        var = org;
    return var -= org;
}

void SPEC2_MakeStatus(s32 chan, PADStatus *status, u32 data[2]) {
    PADStatus *origin;
    status->button =
        (u16)((data[0] >> 16) & (0x0001 | 0x0002 | 0x0004 | 0x0008 | 0x0010 | 0x0020 | 0x0040 |
                                 0x0100 | 0x0200 | 0x0400 | 0x0800 | 0x1000 | 0x2000 | 0x0080));
    status->stickX = (s8)(data[0] >> 8);
    status->stickY = (s8)(data[0]);
    switch (lbl_801A64BC & 0x00000700) {
    case 0x00000000:
    case 0x00000500:
    case 0x00000600:
    case 0x00000700:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(((data[1] >> 12) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 8) & 0x0f) << 4);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000100:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(data[1] >> 16);
        status->triggerRight = (u8)(data[1] >> 8);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000200:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(((data[1] >> 20) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 16) & 0x0f) << 4);
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    case 0x00000300:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)(data[1] >> 0);
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x00000400:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = 0;
        status->triggerRight = 0;
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
    origin = &lbl_8015D0C0[chan];
    status->stickX = ClampS8(status->stickX, origin->stickX);
    status->stickY = ClampS8(status->stickY, origin->stickY);
    status->substickX = ClampS8(status->substickX, origin->substickX);
    status->substickY = ClampS8(status->substickY, origin->substickY);
    status->triggerLeft = ClampU8(status->triggerLeft, origin->triggerLeft);
    status->triggerRight = ClampU8(status->triggerRight, origin->triggerRight);
}

/* --- dol/PADSetAnalogMode.c --- */
extern u32 lbl_801A697C;

extern u32 lbl_801A6988;

extern u32 lbl_801A698C;


void PADSetAnalogMode(u32 mode) {
    BOOL enabled;
    u32 mask;
    enabled = OSDisableInterrupts();
    lbl_801A64BC = mode << 8;
    mask = lbl_801A697C;
    lbl_801A697C &= ~mask;
    lbl_801A6988 &= ~mask;
    lbl_801A698C &= ~mask;
    SIDisablePolling(mask);
    OSRestoreInterrupts(enabled);
}
