#include "types.h"
#pragma use_lmw_stmw on

/* lbl_801A6C80's sound state, with the type and member names of the view in fn_80067F68.c */
typedef struct SndMix {
    u8 pad_0[0xA];
    s8 bA;
    s8 bB;
    u8 bC;
    u8 bD;
    u8 pad_E[2];
} SndMix;

typedef struct SndSource {
    u8 pad_0[0xB];
    u8 unk_B;
    u8 pad_C;
    u8 unk_D;
    u8 unk_E;
} SndSource;

typedef struct SndSlot {
    u8 b0;
    s8 b1;
    u8 pad_2[6];
    u8 unk_8;
    u8 pad_9[4];
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 pad_16[2];
    SndSource *unk_18;
    u8 pad_1C[4];
} SndSlot;

typedef struct SndState {
    u8 pad_0[0x444];
    u32 w444;
    u8 pad_448[0x40];
    SndMix mix[16];
    SndSlot slot[64];
    u8 pair[16][16][4];
} SndState;

extern SndState *lbl_801A6C80;

static inline void fn_80063F38_slot(u16 event, u8 k, u8 channel, s8 delta) {
    s8 offset;
    u8 level;
    SndSource *src;
    s16 sum;

    switch (event) {
    case 1:
    case 0x11:
        if (lbl_801A6C80->slot[k].b1 & 1) {
            break;
        }
        lbl_801A6C80->slot[k].b11 = 0x40;
        lbl_801A6C80->slot[k].b12 = 0;
        lbl_801A6C80->slot[k].b13 = 0;
        lbl_801A6C80->slot[k].b14 = 0;
        lbl_801A6C80->slot[k].b15 = 0;
        src = lbl_801A6C80->slot[k].unk_18;
        lbl_801A6C80->slot[k].unk_8 = src->unk_B;
        lbl_801A6C80->slot[k].unk_E = src->unk_D;
        lbl_801A6C80->slot[k].unk_F = src->unk_E;
        break;
    case 0xA004:
        offset = 0;
        if (lbl_801A6C80->slot[k].b1 & 2) {
            level = lbl_801A6C80->mix[channel].bB;
            if (lbl_801A6C80->mix[channel].bD != 0x40) {
                offset = ((s8)lbl_801A6C80->mix[channel].bD - 0x40) * 2;
            }
        } else {
            level = lbl_801A6C80->mix[channel].bA;
            if (lbl_801A6C80->mix[channel].bC != 0x40) {
                offset = ((s8)lbl_801A6C80->mix[channel].bC - 0x40) * 2;
            }
        }
        sum = (s8)level + offset;
        if (sum < 0) {
            sum = 0;
        } else if (sum > 0x7F) {
            sum = 0x7F;
        }
        lbl_801A6C80->slot[k].unk_10 = sum;
        break;
    case 0xA007:
        if (lbl_801A6C80->slot[k].b1 & 1) {
            break;
        }
        lbl_801A6C80->slot[k].unk_E = lbl_801A6C80->slot[k].unk_D + delta;
        break;
    }
}

void fn_80063F38(u16 event, u8 channel) {
    u8 i;
    u8 j;
    s8 delta;
    struct { u8 value; } k;

    delta = (s8)((s8)((lbl_801A6C80->w444 >> 8) & 0x7F) - 0x40);
    for (i = 0; i < 0x10; i++) {
        for (j = 0; j < 4; j++) {
            k.value = lbl_801A6C80->pair[channel][i][j];
            if (k.value == 0xFF) {
                continue;
            }
            fn_80063F38_slot(event, k.value, channel, delta);
        }
    }
}
