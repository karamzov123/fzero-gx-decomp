#include "types.h"

/* lbl_801A6C80's sound state, with the type names of the views in fn_80069FCC.c and fn_80063F38.c */
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
    u8 pad_0[9];
    u8 unk_9;
    u8 pad_A[6];
} SndMix;

typedef struct SndSlot {
    u8 pad_0;
    u8 unk_1;
    u8 pad_2[5];
    u8 unk_7;
    u8 pad_8[8];
    u8 unk_10;
    u8 pad_11[0xF];
} SndSlot;

typedef struct SndState {
    SndChan chan[16];
    u8 pad_100[0x45B - 0x100];
    u8 unk_45B;
    u8 pad_45C[0x461 - 0x45C];
    u8 unk_461;
    u8 pad_462[0x488 - 0x462];
    SndMix mix[16];
    SndSlot slot[64];
    u8 pad_D88[0x5A10 - 0xD88];
    s16 unk_5A10;
    u8 pad_5A12[0x5A34 - 0x5A12];
    s16 unk_5A34[16];
    s16 unk_5A54[16];
} SndState;

typedef struct {
    u8 pad_0[6];
    u8 unk_6;
} Fn8005D258Arg0;

typedef struct {
    u8 pad_0[9];
    u8 unk_9;
} Fn8005D258Info;

extern SndState *lbl_801A6C80;
extern f32 fn_80088578(f32 x);

/* s16 return and u8 count as retail compiles them: the s32/u32 prototype in fn_8005C7C0.c and fn_8005C9D8.c
 * adds an extsh on return and unrolls the skip loop from the masked count */
s16 fn_8005D258(Fn8005D258Arg0 *arg0, Fn8005D258Info *info, u8 slot, u8 count, f32 *out_db, s16 *out_level) {
    SndBank *bank;
    u8 *p;
    u8 i;
    u8 v;
    f32 level;
    s16 result;

    bank = lbl_801A6C80->chan[lbl_801A6C80->unk_45B].unk_8;
    if (bank != NULL) {
        /* the record address spelled as integers, as in fn_80069FCC.c */
        p = (u8 *)(bank->unk_20 + (u32)bank + arg0->unk_6 * 0x80 + 4);
        for (i = 0; i < count; i++) {
            p++;
        }
        v = *p;
        if (v != 0) {
            level = 20.0 * fn_80088578((f32)v / 255.0f);
        } else {
            level = -960.0f;
        }
        v = info->unk_9;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578((f32)v / 255.0f));
        } else {
            level = -960.0f;
        }
        v = lbl_801A6C80->slot[slot].unk_7;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578((f32)v / 127.0f));
        } else {
            level = -960.0f;
        }
        v = lbl_801A6C80->slot[slot].unk_10;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578((f32)v / 127.0f));
        } else {
            level = -960.0f;
        }
        if (lbl_801A6C80->slot[slot].unk_1 & 1) {
            result = lbl_801A6C80->unk_5A54[lbl_801A6C80->unk_45B];
        } else {
            v = lbl_801A6C80->mix[lbl_801A6C80->unk_45B].unk_9;
            if (v != 0) {
                level += (f32)(20.0 * fn_80088578((f32)v / 127.0f));
            } else {
                level = -960.0f;
            }
            result = lbl_801A6C80->unk_5A34[lbl_801A6C80->unk_45B];
        }
        v = lbl_801A6C80->unk_461;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578((f32)v / 127.0f));
        } else {
            level = -960.0f;
        }
        result += lbl_801A6C80->unk_5A10;
        *out_db = level;
        *out_level = result;
        result += (s16)(10.0f * level);
        if (result < -960) {
            result = -960;
        }
        return result;
    } else {
        *out_db = -960.0f;
        *out_level = -960;
        return -960;
    }
}
