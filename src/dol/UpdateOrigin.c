#include <types.h>


/* --- dol/ClampStick.c --- */
void ClampStick(s8 *px, s8 *py, s8 max, s8 xy, s8 min);

/* --- dol/PADClamp.c --- */
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

typedef struct PADClampRegion {
    u8 minTrigger;
    u8 maxTrigger;
    s8 minStick;
    s8 maxStick;
    s8 xyStick;
    s8 minSubstick;
    s8 maxSubstick;
    s8 xySubstick;
    s8 radStick;
    s8 radSubstick;
} PADClampRegion;

extern const PADClampRegion lbl_8008FF40;

void ClampStick(s8 *px, s8 *py, s8 max, s8 xy, s8 min);

static inline void ClampTrigger(u8 *trigger, u8 min, u8 max) {
    if (*trigger <= min) {
        *trigger = 0;
        return;
    } else {
        if (max < *trigger) {
            *trigger = max;
        }
        *trigger -= min;
    }
}

void PADClamp(PADStatus *status);

/* --- dol/UpdateOrigin.c --- */
u32 SIGetType(s32 chan);

extern u32 lbl_801A64B8;

extern u32 lbl_801A64BC;

extern PADStatus lbl_8015D0C0[4];

void UpdateOrigin(s32 chan) {
    PADStatus *origin;
    u32 chanBit = 0x80000000 >> chan;
    origin = &lbl_8015D0C0[chan];
    switch (lbl_801A64BC & 0x00000700u) {
    case 0x00000000u:
    case 0x00000500u:
    case 0x00000600u:
    case 0x00000700u:
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000100u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000200u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        break;
    case 0x00000300u:
        break;
    case 0x00000400u:
        break;
    }
    origin->stickX -= 128;
    origin->stickY -= 128;
    origin->substickX -= 128;
    origin->substickY -= 128;
    if (lbl_801A64B8 & chanBit) {
        if (64 < origin->stickX && (SIGetType(chan) & 0xffff0000) == (0x08000000u | 0x01000000)) {
            origin->stickX = 0;
        }
    }
}
