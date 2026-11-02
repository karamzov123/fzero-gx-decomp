#include "types.h"

typedef struct SndBank {
    u8 pad_0[0x20];
    u32 unk_20;
} SndBank;

typedef struct SndChan {
    u8 pad_0[8];
    SndBank *unk_8;
    u8 pad_C[4];
} SndChan;

typedef struct SndMix {
    u8 pad_0[0xE];
    u8 unk_E;
    u8 pad_F;
} SndMix;

typedef struct SndState {
    SndChan chan[16];
    u8 pad_100[0x45B - 0x100];
    u8 unk_45B;
    u8 pad_45C[0x461 - 0x45C];
    u8 unk_461;
    u8 pad_462[0x488 - 0x462];
    SndMix mix[16];
    u8 pad_588[0x5A08 - 0x588];
    u8 unk_5A08;
    u8 pad_5A09[0x5A10 - 0x5A09];
    s16 unk_5A10;
    u8 pad_5A12[2];
    s16 unk_5A14[16];
} SndState;

typedef struct SndNote {
    u8 pad_0[9];
    u8 unk_9;
    u8 pad_A[0x2C - 0xA];
    u8 unk_2C;
} SndNote;

extern SndState *lbl_801A6C80;
extern f32 fn_80088578(f32 x);

s32 fn_80069FCC(SndNote *note, u8 channel) {
    SndBank *bank;
    u8 *p;
    u8 count;
    u8 i;
    u8 v;
    f32 level;
    s32 result;

    bank = lbl_801A6C80->chan[lbl_801A6C80->unk_45B].unk_8;
    count = note->unk_9;
    p = (u8 *)(bank->unk_20 + (u32)bank + note->unk_2C * 0x80 + 4);
    for (i = 0; i < count; i++) {
        p++;
    }
    v = *p;
    if (v != 0) {
        level = 20.0 * fn_80088578((f32)v / 255.0f);
    } else {
        level = -960.0f;
    }
    if (lbl_801A6C80->unk_5A08 != 0) {
        level += (f32)(20.0 * fn_80088578((f32)lbl_801A6C80->unk_5A08 / 127.0f));
    } else {
        level = -960.0f;
    }
    if (lbl_801A6C80->mix[channel].unk_E != 0) {
        level += (f32)(20.0 * fn_80088578((f32)lbl_801A6C80->mix[channel].unk_E / 127.0f));
    } else {
        level = -960.0f;
    }
    result = lbl_801A6C80->unk_5A14[channel];
    if (lbl_801A6C80->unk_461 != 0) {
        level += (f32)(20.0 * fn_80088578((f32)lbl_801A6C80->unk_461 / 127.0f));
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
