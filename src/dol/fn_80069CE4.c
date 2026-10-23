#include "types.h"
#pragma use_lmw_stmw on

typedef struct {
    u32 w0;
    u32 w4;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} SndMix;

typedef struct {
    u8 b0;
    u8 pad1[0xA];
    u8 bB;
    u8 padC[8];
    s32 w14;
    u8 pad18[4];
    u32 w1C;
    u8 pad20[0x64];
    s32 w84;
    u8 pad88[0x8C];
    s32 w114;
} SndVoice;

typedef struct {
    u8 pad0[0x488];
    SndMix mix[16];         /* 0x0488 */
    u8 pad588[0x1408 - 0x588];
    SndVoice voice[64];     /* 0x1408 */
    u8 pad5A08[0x5A14 - 0x5A08];
    s16 h5A14[16];
} SndState;

extern SndState *lbl_801A6C80;
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_80069B10(s32, u32);
extern s32 fn_80069FCC(u32, u8);

static inline void retune(s32 all, s32 ch) {
    u32 i;
    s32 r;

    for (i = 0; i < 64; i++) {
        if (lbl_801A6C80->voice[i].b0 == 4) {
            if (all == 0x10 || ch == lbl_801A6C80->voice[i].bB) {
                r = fn_80069FCC(lbl_801A6C80->voice[i].w1C, lbl_801A6C80->voice[i].bB);
                lbl_801A6C80->voice[i].w84 = (r - (lbl_801A6C80->voice[i].w114 >> 16)) << 16;
                lbl_801A6C80->voice[i].w14 = r;
            }
        }
    }
}

s32 fn_80069CE4(u32 target, s32 kind, s16 value) {
    s32 intr;
    s32 all;
    u16 t;
    u8 i;

    intr = OSDisableInterrupts();
    switch (kind) {
    case 0xA0120000:
        all = target & 0x10;
        t = target;
        if (all == 0x10) {
            for (i = 0; i < 16; i++) {
                lbl_801A6C80->mix[i].bE = value & 0x7F;
            }
        } else {
            lbl_801A6C80->mix[t & 0xF].bE = value & 0x7F;
        }
        retune(all, t & 0xF);
        break;
    case 0xA0000500:
    case 0xA0001500:
        fn_80069B10(kind, target);
        break;
    case 0xA0220000:
        all = target & 0x10;
        t = target;
        if (all == 0x10) {
            for (i = 0; i < 16; i++) {
                lbl_801A6C80->h5A14[i] = value;
            }
        } else {
            lbl_801A6C80->h5A14[t & 0xF] = value;
        }
        retune(all, t & 0xF);
        break;
    default:
        OSRestoreInterrupts(intr);
        return -1;
    }
    OSRestoreInterrupts(intr);
    return 0;
}
