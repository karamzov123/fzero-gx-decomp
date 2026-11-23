#ifndef SASND_SASND_H
#define SASND_SASND_H

/* sasnd Ver 1.13h: state shared by the library's translation units. Member offsets and widths
 * are measured from retail accesses; names stay offset-based until a role is established. */

#include "types.h"
#include "layout_check.h"
#include "version.h"

/* PAL's bank header places this offset 0x40 bytes later than USA and Japan. */
typedef struct SndBank {
    u8 pad_0[VERSION_SELECT(0x20, 0x60, 0x20)];
    u32 unk_20;
} SndBank;

typedef struct SndChan {
    u32 unk_0;
    u32 unk_4;
    SndBank *bank;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
} SndChan;

typedef struct SndMix {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 volume;
    u8 pan;
} SndMix;

typedef struct SndVoice {
    u8 state;
    u8 active;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 channel;
    s16 unk_C;
    u16 unk_E;
    u32 unk_10;
    s32 pitch;
    u32 time;
    u32 note;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 axvpb;
    u8 env[0x54];
    s32 pitchDelta;
    u8 pad_88[0x8C];
    s32 pitchEnv;
} SndVoice;

typedef struct SndState {
    SndChan chan[16];
    u8 pad_100[0x45B - 0x100];
    u8 curChan;
    u8 pad_45C[0x461 - 0x45C];
    u8 masterVolume;
    u8 pad_462[0x444 + 0x44 - 0x462];
    SndMix mix[16];
    u8 pad_588[0x1408 - 0x588];
    SndVoice voice[64];
    u8 volume;
    u8 pad_5A09[3];
    u32 unk_5A0C;
    s16 unk_5A10;
    s16 unk_5A12;
    s16 chanPitch[16];
    u8 pad_5A34[0x5B28 - 0x5A34];
} SndState;

CHECK_SIZE(SndChan, 0x10);
CHECK_SIZE(SndMix, 0x10);
CHECK_SIZE(SndVoice, 0x118);
CHECK_SIZE(SndState, 0x5B28);
CHECK_OFFSET(SndVoice, env, 0x30);
CHECK_OFFSET(SndVoice, pitchDelta, 0x84);
CHECK_OFFSET(SndVoice, pitchEnv, 0x114);
CHECK_OFFSET(SndState, curChan, 0x45B);
CHECK_OFFSET(SndState, masterVolume, 0x461);
CHECK_OFFSET(SndState, mix, 0x488);
CHECK_OFFSET(SndState, voice, 0x1408);
CHECK_OFFSET(SndState, volume, 0x5A08);
CHECK_OFFSET(SndState, chanPitch, 0x5A14);

extern SndState *lbl_801A6C80;

#endif
