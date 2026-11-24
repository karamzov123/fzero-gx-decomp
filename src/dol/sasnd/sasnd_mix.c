#include "sasnd/sasnd.h"
#pragma use_lmw_stmw on

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_80020ABC(void *);
extern u32 fn_80026D70(void *);
extern void fn_80023168(void *, u16);
extern void AXARTRemoveSound(void *);
extern f32 fn_80088578(f32 x);

s32 fn_80069FCC(SndNote *note, u8 channel);

static inline void stop_voice(u8 i) {
    fn_80023168(lbl_801A6C80->voice[i].obj, 0);
    fn_80026D70(lbl_801A6C80->voice[i].obj);
    fn_80020ABC(lbl_801A6C80->voice[i].obj);
    lbl_801A6C80->voice[i].obj = 0;
    AXARTRemoveSound(lbl_801A6C80->voice[i].env);
    if (lbl_801A6C80->voice[i].state != 0xFF) {
        lbl_801A6C80->voice[i].state = 0xFF;
        lbl_801A6C80->voice[i].time = 0;
        lbl_801A6C80->voice[i].active = 0;
        lbl_801A6C80->voice[i].unk_28 = 0;
    }
}

void fn_80069B10(u32 kind, u32 target) {
    u8 i;

    for (i = 0; i < 64; i++) {
        if (kind + 0x60000000 == 0x500) {
            if (lbl_801A6C80->voice[i].state == 4) {
                stop_voice(i);
            }
        } else if (kind + 0x60000000 == 0x1500) {
            if (lbl_801A6C80->voice[i].state == 4) {
                if (lbl_801A6C80->voice[i].channel == (s32)(target & 0xF)) {
                    stop_voice(i);
                }
            }
        }
    }
}

static inline void retune(s32 all, s32 ch) {
    u32 i;
    s32 r;

    for (i = 0; i < 64; i++) {
        if (lbl_801A6C80->voice[i].state == 4) {
            if (all == 0x10 || ch == lbl_801A6C80->voice[i].channel) {
                r = fn_80069FCC(lbl_801A6C80->voice[i].note, lbl_801A6C80->voice[i].channel);
                lbl_801A6C80->voice[i].volDelta = (r - (lbl_801A6C80->voice[i].volEnv >> 16)) << 16;
                lbl_801A6C80->voice[i].vol = r;
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
                lbl_801A6C80->mix[i].volume = value & 0x7F;
            }
        } else {
            lbl_801A6C80->mix[t & 0xF].volume = value & 0x7F;
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
                lbl_801A6C80->chanLevel[i] = value;
            }
        } else {
            lbl_801A6C80->chanLevel[t & 0xF] = value;
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

s32 fn_80069FCC(SndNote *note, u8 channel) {
    SndBank *bank;
    u8 *p;
    u8 count;
    u8 i;
    u8 v;
    f32 level;
    s32 result;

    bank = lbl_801A6C80->chan[lbl_801A6C80->curChan].bank;
    count = note->unk_9;
    p = (u8 *)(bank->levelOffset + (u32)bank + note->unk_2C * 0x80 + 4);
    for (i = 0; i < count; i++) {
        p++;
    }
    v = *p;
    if (v != 0) {
        level = 20.0 * fn_80088578(v / 255.0f);
    } else {
        level = -960.0f;
    }
    if (lbl_801A6C80->volume != 0) {
        level += (f32)(20.0 * fn_80088578(lbl_801A6C80->volume / 127.0f));
    } else {
        level = -960.0f;
    }
    if (lbl_801A6C80->mix[channel].volume != 0) {
        level += (f32)(20.0 * fn_80088578(lbl_801A6C80->mix[channel].volume / 127.0f));
    } else {
        level = -960.0f;
    }
    result = lbl_801A6C80->chanLevel[channel];
    if (lbl_801A6C80->masterVolume != 0) {
        level += (f32)(20.0 * fn_80088578(lbl_801A6C80->masterVolume / 127.0f));
    } else {
        level = -960.0f;
    }
    result += lbl_801A6C80->unk_5A10;
    result += (s16)(10.0f * level);
    if (result < -960) {
        result = -960;
    }
    return result;
}

void fn_8006A1F8(void) {
    u32 i;

    lbl_801A6C80->volume = 0x7F;
    lbl_801A6C80->unk_5A0C = 1;
    for (i = 0; i < 16; i++) {
        lbl_801A6C80->mix[i].volume = 0x7F;
        lbl_801A6C80->mix[i].pan = 0x40;
    }
    for (i = 0; i < 64; i++) {
        lbl_801A6C80->voice[i].unk_28 = 0;
        lbl_801A6C80->voice[i].channel = 0xFF;
    }
}
