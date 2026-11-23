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
    s16 unk_E;
    s16 unk_10;
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
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[6];
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

/* One sequence player. */
typedef struct SndSeq {
    u8 flags;
    u8 flags2;
    u8 chan;
    u8 status;
    u32 tempo;
    u32 cmd;
    s32 wait;
    u8 *base;
    u32 loop;
    u8 *cur;
    s32 vol;
    s32 prevVol;
    s32 volStep;
} SndSeq;

typedef struct SndState {
    SndChan chan[16];
    u32 unk_100;
    u32 unk_104[16];
    u32 unk_144[16];
    u8 unk_184[16];
    u32 unk_194;
    u8 *unk_198;
    s32 unk_19C;
    u32 unk_1A0;
    u32 unk_1A4;
    u32 unk_1A8;
    u32 unk_1AC[16];
    u32 unk_1EC[16];
    u8 unk_22C[16];
    u32 unk_23C;
    u32 inQueue[64];
    u32 outQueue[64];
    u8 outCount;
    u8 inCount;
    u8 outRead;
    u8 inWrite;
    u32 command;
    u32 unk_448;
    u32 unk_44C;
    u32 elapsed;
    u32 unk_454;
    u8 unk_458;
    u8 outWrite;
    u8 inRead;
    u8 curChan;
    u8 pad_45C;
    u8 ready;
    u8 budget;
    u8 unk_45F;
    u8 unk_460;
    u8 masterVolume;
    u8 unk_462;
    u8 unk_463;
    s8 busy;
    u8 unk_465;
    u8 pad_466[2];
    u32 frames;
    u32 unk_46C;
    u8 unk_470;
    u8 unk_471;
    u8 unk_472;
    u8 unk_473;
    u8 unk_474;
    u8 pad_475[3];
    u32 unk_478;
    u32 unk_47C;
    u8 pad_480[8];
    SndMix mix[16];
    SndSlot slot[64];
    u8 voiceMap[16][16][4];
    SndSeq seq[16];
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
    s16 unk_5A94[16];
    s16 unk_5AB4[16];
    s16 unk_5AD4[16];
    s16 trackLevelInit[16];
    u32 lastTick;
    void (*unk_5B18)(u32, u32);
    void (*callback)(s32, u32);
    s32 unk_5B20;
    u8 pad_5B24[4];
} SndState;

/* Two instances of each of the four AX effect work areas (A/B sends). */
typedef struct SndFxState {
    u8 fx3B[0x60];
    u8 fx3A[0x60];
    u8 fx2B[0x9C];
    u8 fx2A[0x9C];
    u8 fx1B[0x1E0];
    u8 fx1A[0x1E0];
    u8 fx0B[0x154];
    u8 fx0A[0x154];
} SndFxState;

CHECK_SIZE(SndFxState, 0x860);
CHECK_SIZE(SndChan, 0x10);
CHECK_SIZE(SndMix, 0x10);
CHECK_SIZE(SndTrack, 0x54);
CHECK_SIZE(SndSlot, 0x20);
CHECK_SIZE(SndWave, 0x44);
CHECK_SIZE(SndVoice, 0x118);
CHECK_SIZE(SndSeq, 0x28);
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
CHECK_OFFSET(SndState, seq, 0x1188);
CHECK_OFFSET(SndState, inQueue, 0x240);
CHECK_OFFSET(SndState, outCount, 0x440);
CHECK_OFFSET(SndState, elapsed, 0x450);
CHECK_OFFSET(SndState, busy, 0x464);
CHECK_OFFSET(SndState, frames, 0x468);
CHECK_OFFSET(SndState, unk_478, 0x478);
CHECK_OFFSET(SndState, lastTick, 0x5B14);
CHECK_OFFSET(SndState, voice, 0x1408);
CHECK_OFFSET(SndState, volume, 0x5A08);
CHECK_OFFSET(SndState, chanLevel, 0x5A14);
CHECK_OFFSET(SndState, trackLevel, 0x5A74);
CHECK_OFFSET(SndState, trackLevelInit, 0x5AF4);
CHECK_OFFSET(SndState, callback, 0x5B1C);

/* ARAM request block; layout of the SDK's ARQRequest. */
typedef void (*ARQCallback)(u32 pointerToARQRequest);
typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

extern SndState *lbl_801A6C80;
extern SndTrack lbl_80192D68[16];

#endif
