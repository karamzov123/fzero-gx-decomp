#include "types.h"

typedef struct SndNote {
    u8 key;
    u8 flags;
    u16 sample;
    u8 pad_4[2];
    u8 pan;
    u8 unk_7;
    u8 unk_8;
    u8 pad_9;
    s8 unk_A;
    s8 unk_B;
    s16 unk_C;
    u8 pad_E[6];
    u8 unk_14;
} SndNote;

typedef struct SndHeader {
    u16 count;
    u8 lo;
    u8 hi;
    u8 pad_4[0x19 - 0x4];
    u8 unk_19;
    u8 unk_1A;
} SndHeader;

typedef struct SndSlot {
    u8 pad_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0xE - 0x3];
    s8 unk_E;
    s8 unk_F;
    u8 pad_10[0x1C - 0x10];
    u8 *seq;
} SndSlot;

typedef struct SndVoice {
    u8 state;
    u8 active;
    u8 slot;
    u8 flags;
    u8 pad_4[0xC - 0x4];
    s16 rnd;
    u16 unk_E;
    u32 unk_10;
    s32 vol;
    u32 time;
    SndNote *note;
    SndHeader *hdr;
    u8 pad_24[0x78 - 0x24];
    s32 unk_78;
    u8 pad_7C[0x118 - 0x7C];
} SndVoice;

typedef struct SndState {
    u8 pad_0[0x588];
    SndSlot slot[64];
    u8 pad_D88[0x1408 - 0xD88];
    SndVoice voice[64];
} SndState;

extern SndState *lbl_801A6C80;
extern s32 fn_80063EF4(u8, u8, u8);


static inline s16 Pitch(u8 slot, u8 *seq, u8 key, SndHeader *hdr, s16 *rnd, SndNote *note) {
    s32 fine;
    s32 coarse;
    s32 detune;

    coarse = seq[0] != 0 ? 0 : key - 60;
    coarse += note->unk_A + lbl_801A6C80->slot[slot].unk_E;
    fine = note->unk_B + lbl_801A6C80->slot[slot].unk_F;
    if (note->unk_14 != 0) {
        fine += *rnd;
    } else {
        *rnd = 0;
    }
    detune = fn_80063EF4(slot, hdr->unk_19, hdr->unk_1A);
    fine += (detune >> 2) & 0x3F;
    coarse += detune >> 8;
    return 100.0 * coarse + 1.5625 * fine;
}

void fn_8005C478(u32 voice) {
    u8 slot;
    u8 *seq;
    SndNote *note;
    SndHeader *hdr;

    slot = lbl_801A6C80->voice[voice].slot;
    seq = lbl_801A6C80->slot[slot].seq;
    if (seq == NULL) {
        return;
    }
    hdr = lbl_801A6C80->voice[voice].hdr;
    note = lbl_801A6C80->voice[voice].note;
    lbl_801A6C80->voice[voice].unk_78 = Pitch(slot, seq, lbl_801A6C80->voice[voice].time >> 16, hdr, &lbl_801A6C80->voice[voice].rnd, note) << 16;
}
