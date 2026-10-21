#include "types.h"

#pragma use_lmw_stmw on

typedef struct Fn80065390Header {
    u8 pad_0[0x18];
    u32 dataOffset;
    u8 pad_1C[0x3E - 0x1C];
    u16 dataSize;
} Fn80065390Header;

typedef struct Fn80065390Slot {
    u8 pad_0[8];
    Fn80065390Header *header;
    u8 pad_C[4];
} Fn80065390Slot;

typedef struct Fn80065390Track {
    u8 *ptr;
    u8 pad_4[3];
    u8 value;
    u8 pad_8[8];
} Fn80065390Track;

typedef struct Fn80065390Voice {
    u8 active;
    u8 flags;
    u8 b2;
    u8 pad_3[0x11 - 0x3];
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 pad_16[2];
    u32 w18;
    u32 w1C;
} Fn80065390Voice;

typedef struct Fn80065390State {
    Fn80065390Slot slots[16];
    u8 pad_100[0x444 - 0x100];
    u32 current;
    u8 pad_448[0x48C - 0x448];
    Fn80065390Track tracks[15];
    u8 pad_57C[0x588 - 0x57C];
    Fn80065390Voice voices[64];
    u8 voiceMap[16][16][4];
} Fn80065390State;

extern Fn80065390State *lbl_801A6C80;
extern void fn_80064FDC(u32, void *);

#define STATE lbl_801A6C80
#define VOICE(k) (&lbl_801A6C80->voices[k])
#define VOICE_MAP(idx, i, j) (lbl_801A6C80->voiceMap[idx][i][j])

static inline void fn_80065390_stopVoices(u8 idx) {
    u8 i;
    u8 j;
    u8 k;
    u8 flag;

        for (i = 0; i < 16; i++) {
            for (j = 0; j < 4; j++) {
                k = VOICE_MAP((u8)idx, i, j);
                if (k != 0xFF) {
                    flag = 0;
                    if (VOICE(k)->flags & 1) {
                        flag = 1;
                    }
                    if (flag) {
                        VOICE(k)->active = 0;
                        VOICE(k)->flags = 0;
                        VOICE(k)->w18 = 0;
                        VOICE(k)->w1C = 0;
                        VOICE(k)->b2 = 0;
                        VOICE(k)->b11 = 0x40;
                        VOICE(k)->b12 = 0;
                        VOICE(k)->b13 = 0;
                        VOICE(k)->b14 = 0;
                        VOICE(k)->b15 = 0;
                        VOICE_MAP((u8)idx, i, j) = 0xFF;
                    }
                }
            }
        }
}

void fn_80065390(void) {
    u8 idx;
    Fn80065390Header *header;
    u8 *data;
    u8 *ptr;

    idx = STATE->current & 0xF;
    header = STATE->slots[idx].header;
    data = (u8 *)header + header->dataOffset;
    if (header->dataSize != 0) {
        fn_80065390_stopVoices(idx);
        STATE->tracks[idx].ptr = data + header->dataSize;
        ptr = STATE->tracks[idx].ptr;
        if (ptr[1] != 0x80) {
            STATE->tracks[idx].value = ptr[1];
        }
        fn_80064FDC(idx, ptr);
    } else {
        STATE->tracks[idx].ptr = 0;
    }
}
