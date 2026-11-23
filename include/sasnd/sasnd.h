#ifndef SASND_SASND_H
#define SASND_SASND_H

/* sasnd Ver 1.13h: state shared by the library's translation units. Member offsets and widths
 * are measured from retail accesses; names stay offset-based until a role is established. */

#include "types.h"
#include "layout_check.h"
#include "version.h"

/* PAL's bank header keeps the level table offset 0x40 bytes later than USA and Japan. */
typedef struct SndBank {
#if VERSION == VERSION_PAL
    u8 pad_0[0x38];
    u32 waveOffset;
    u8 pad_3C[0x60 - 0x3C];
    u32 levelOffset;
#else
    u8 pad_0[0x20];
    u32 levelOffset;
    u8 pad_24[0x38 - 0x24];
    u32 waveOffset;
#endif
} SndBank;

typedef struct SndChan {
    u32 unk_0;
    u32 base;
    SndBank *bank;
    u8 unk_C;
    u8 id;
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

/* key zone: split point, base value and slope (8.8 fixed point per key) */
typedef struct SndZone {
    u8 key;
    u8 val;
    s16 slope;
} SndZone;

typedef struct SndZoneList {
    u8 count;
    u8 offset;
} SndZoneList;

typedef struct SndRegion {
    u8 size;
    u8 mode;
    u16 sample;
    u8 lo;
    u8 hi;
    u8 pad_6;
    u8 unk_7;
    u8 fader;
    u8 pad_9;
    u8 flags;
    u8 pad_B;
#if VERSION == VERSION_PAL
    u8 pad_C[4];
#endif
    SndZoneList zone[6]; /* volume, pan, surround pan, pitch, aux A, aux B */
} SndRegion;

/* One step of a track's current record, indexed by the SND_STEP_* fields. */
enum {
    SND_STEP_STATE,
    SND_STEP_FLAGS,
    SND_STEP_VOICE,
    SND_STEP_VOICE2,
    SND_STEP_SIZE
};

typedef struct SndTrack {
    u8 bank;
    u8 active;
    u8 id;
    u8 volume;
    u8 pan;
    u8 span;
    u8 auxA;
    u8 auxB;
    u8 unk_8;
    u8 coarse;
    u8 fine;
    u8 program;
    u8 count;
    u8 unk_D;
    u8 fader;
    u8 prio;
    SndRegion *regions;
    u8 voices[16][SND_STEP_SIZE];
} SndTrack;

typedef struct SndNote {
    u8 key;
    u8 flags;
    u16 sample;
    u8 pad_4[2];
    u8 pan;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    s8 unk_A;
    s8 unk_B;
    s16 unk_C;
    u8 pad_E[4];
    s16 unk_12;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18;
    u8 pad_19[2];
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u8 unk_2C;
    u8 pad_2D[3];
} SndNote;

typedef struct SndHeader {
    u16 count;
    u8 lo;
    u8 hi;
    u8 pad_4[2];
    u8 unk_6;
    u8 pad_7[6];
    s8 unk_D;
    u8 pad_E;
    s8 unk_F;
    u8 pad_10[9];
    u8 unk_19;
    u8 unk_1A;
    u8 pad_1B[5];
    u8 min;
    u8 max;
    u16 offs[1];
} SndHeader;

typedef struct SndSlot {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3[3];
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 pad_D;
    s8 unk_E;
    s8 unk_F;
    u8 unk_10;
    u8 pad_11;
    u8 unk_12;
    u8 unk_13;
    u8 pad_14[8];
    u8 *seq;
} SndSlot;

typedef struct SndWave {
    u32 offset;
    u32 loop_start;
    u32 loop_end;
    u16 coef[16];
    u16 gain;
    u16 ps;
    u16 yn1;
    u16 yn2;
    u16 loop_ps;
    u16 loop_yn1;
    u16 loop_yn2;
    u8 format;
    u8 stereo;
    u16 rate;
    u8 pad_3E[2];
    u32 offset2;
} SndWave;

typedef struct SndVoiceParams {
    u16 loop;
    u16 format;
    u16 loop_hi;
    u16 loop_lo;
    u16 end_hi;
    u16 end_lo;
    u16 cur_hi;
    u16 cur_lo;
} SndVoiceParams;

typedef struct SndAdpcm {
    u16 coef[16];
    u16 gain;
    u16 ps;
    u16 yn1;
    u16 yn2;
} SndAdpcm;

typedef struct SndVoice {
    u8 state;
    u8 active;
    u8 slot;
    u8 flags;
    u8 unk_4;
    u8 unk_5;
    u8 track;
    u8 index;
    u8 prio;
    u8 link0;
    u8 link1;
    u8 channel;
    s16 rnd;
    u16 unk_E;
    s32 step;
    s32 vol;
    u32 time;
    SndNote *note;
    SndHeader *hdr;
    u32 unk_24;
    u32 unk_28;
    void *obj;
    u8 env[0x40];
    u8 unk_70[8];
    s32 unk_78;
    u8 unk_7C[8];
    s32 volDelta;
    u8 unk_88[8];
    u8 unk_90;
    u8 unk_91;
    u8 pad_92[2];
    u8 unk_94[8];
    s32 unk_9C;
    u8 unk_A0[8];
    s32 unk_A8;
    u8 unk_AC[8];
    s32 unk_B4;
    s32 unk_B8;
    s32 unk_BC;
    u8 unk_C0[8];
    u8 unk_C8[0x20];
    s32 unk_E8;
    u8 unk_EC[8];
    u8 unk_F4[0x20];
    s32 volEnv;
} SndVoice;

typedef struct SndState {
    SndChan chan[16];
    u8 pad_100[0x1A4 - 0x100];
    u32 unk_1A4;
    u32 unk_1A8;
    u8 pad_1AC[0x444 - 0x1AC];
    u32 command;
    u8 pad_448[0x45B - 0x448];
    u8 curChan;
    u8 pad_45C[2];
    u8 unk_45E;
    u8 pad_45F[2];
    u8 masterVolume;
    u8 unk_462;
    u8 unk_463;
    u8 pad_464[0x46C - 0x464];
    u32 unk_46C;
    u8 pad_470[0x474 - 0x470];
    u8 unk_474;
    u8 pad_475[0x488 - 0x475];
    SndMix mix[16];
    SndSlot slot[64];
    u8 voiceMap[16][16][4];
    u8 pad_1188[0x1408 - 0x1188];
    SndVoice voice[64];
    u8 volume;
    u8 pad_5A09[3];
    u32 unk_5A0C;
    s16 unk_5A10;
    s16 unk_5A12;
    s16 chanLevel[16];
    s16 unk_5A34[16];
    s16 unk_5A54[16];
    s16 trackLevel[16];
    u8 pad_5A94[0x5AF4 - 0x5A94];
    s16 trackLevelInit[16];
    u8 pad_5B14[4];
    void (*unk_5B18)(u32, u32);
    void (*callback)(s32, u32);
    u8 pad_5B20[8];
} SndState;

CHECK_SIZE(SndChan, 0x10);
CHECK_SIZE(SndMix, 0x10);
CHECK_SIZE(SndTrack, 0x54);
CHECK_SIZE(SndSlot, 0x20);
CHECK_SIZE(SndWave, 0x44);
CHECK_SIZE(SndVoice, 0x118);
CHECK_SIZE(SndState, 0x5B28);
CHECK_OFFSET(SndNote, unk_2C, 0x2C);
CHECK_OFFSET(SndHeader, min, 0x20);
CHECK_OFFSET(SndSlot, seq, 0x1C);
CHECK_OFFSET(SndVoice, env, 0x30);
CHECK_OFFSET(SndVoice, volDelta, 0x84);
CHECK_OFFSET(SndVoice, volEnv, 0x114);
CHECK_OFFSET(SndState, unk_1A4, 0x1A4);
CHECK_OFFSET(SndState, command, 0x444);
CHECK_OFFSET(SndState, curChan, 0x45B);
CHECK_OFFSET(SndState, masterVolume, 0x461);
CHECK_OFFSET(SndState, mix, 0x488);
CHECK_OFFSET(SndState, slot, 0x588);
CHECK_OFFSET(SndState, voiceMap, 0xD88);
CHECK_OFFSET(SndState, voice, 0x1408);
CHECK_OFFSET(SndState, volume, 0x5A08);
CHECK_OFFSET(SndState, chanLevel, 0x5A14);
CHECK_OFFSET(SndState, trackLevel, 0x5A74);
CHECK_OFFSET(SndState, trackLevelInit, 0x5AF4);
CHECK_OFFSET(SndState, callback, 0x5B1C);

extern SndState *lbl_801A6C80;
extern SndTrack lbl_80192D68[16];

#endif
