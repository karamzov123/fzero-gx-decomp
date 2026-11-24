#ifndef DOLPHIN_AXART_H
#define DOLPHIN_AXART_H

#include "types.h"

/* Dolphin SDK AX articulation library (axart.a). Layouts follow the retail accessors. */

typedef struct _AXVPB AXVPB;

enum {
    AXART_TYPE_NONE,
    AXART_TYPE_3D,
    AXART_TYPE_PANNING,
    AXART_TYPE_ITD,
    AXART_TYPE_SRC,
    AXART_TYPE_PITCH,
    AXART_TYPE_PITCH_ENV,
    AXART_TYPE_PITCH_MOD,
    AXART_TYPE_VOLUME,
    AXART_TYPE_AUX_A_VOLUME,
    AXART_TYPE_AUX_B_VOLUME,
    AXART_TYPE_VOLUME_ENV,
    AXART_TYPE_AUX_A_VOLUME_ENV,
    AXART_TYPE_AUX_B_VOLUME_ENV,
    AXART_TYPE_VOLUME_MOD,
    AXART_TYPE_AUX_A_VOLUME_MOD,
    AXART_TYPE_AUX_B_VOLUME_MOD
};

#define AXART_SINE_CNT 64

typedef struct AXART_ART {
    struct AXART_ART *next;
    u32 type;
} AXART_ART;

typedef struct AXART_LFO {
    f32 *lfo;
    u32 length;
    f32 delta;
    u32 sampleIndex;
    f32 counter;
    f32 sample1;
    f32 sample;
    f32 output;
} AXART_LFO;

typedef struct AXART_3D {
    AXART_ART art;
    f32 hAngle;
    f32 vAngle;
    f32 dist;
    f32 closingSpeed;
    u32 update;
    u8 pan;
    u8 span;
    u8 src;
    u16 itdL;
    u16 itdR;
    f32 pitch;
    s32 attenuation;
} AXART_3D;

typedef struct AXART_PANNING {
    AXART_ART art;
    u8 pan;
    u8 span;
} AXART_PANNING;

typedef struct AXART_ITD {
    AXART_ART art;
    u16 itdL;
    u16 itdR;
} AXART_ITD;

typedef struct AXART_SRC {
    AXART_ART art;
    u8 src;
} AXART_SRC;

typedef struct AXART_PITCH {
    AXART_ART art;
    s32 cents;
} AXART_PITCH;

typedef struct AXART_PITCH_ENV {
    AXART_ART art;
    s32 delta;
    s32 target;
    s32 cents;
} AXART_PITCH_ENV;

typedef struct AXART_PITCH_MOD {
    AXART_ART art;
    AXART_LFO lfo;
    s32 cents;
} AXART_PITCH_MOD;

typedef struct AXART_VOLUME {
    AXART_ART art;
    s32 attenuation;
} AXART_VOLUME;

typedef AXART_VOLUME AXART_AUXA_VOLUME;
typedef AXART_VOLUME AXART_AUXB_VOLUME;

typedef struct AXART_VOLUME_ENV {
    AXART_ART art;
    s32 delta;
    s32 target;
    s32 attenuation;
} AXART_VOLUME_ENV;

typedef AXART_VOLUME_ENV AXART_AUXA_VOLUME_ENV;
typedef AXART_VOLUME_ENV AXART_AUXB_VOLUME_ENV;

typedef struct AXART_VOLUME_MOD {
    AXART_ART art;
    AXART_LFO lfo;
    s32 attenuation;
} AXART_VOLUME_MOD;

typedef AXART_VOLUME_MOD AXART_AUXA_VOLUME_MOD;
typedef AXART_VOLUME_MOD AXART_AUXB_VOLUME_MOD;

typedef struct AXART_SOUND {
    struct AXART_SOUND *next;
    struct AXART_SOUND *prev;
    AXVPB *axvpb;
    f32 sampleRate;
    AXART_ART *articulators;
} AXART_SOUND;

extern f32 AXARTSine[AXART_SINE_CNT];

void AXARTInit(void);
void AXARTQuit(void);
void AXARTServiceSounds(void);
void AXARTInitSound(AXART_SOUND *sound, AXVPB *voice, u32 sampleRate);
void AXARTAddSound(AXART_SOUND *sound);
void AXARTRemoveSound(AXART_SOUND *sound);
void AXARTInitLfo(AXART_LFO *lfo, f32 *samples, u32 length, f32 delta);
void AXARTInitArtPanning(AXART_PANNING *articulator);
void AXARTInitArtPitch(AXART_PITCH *articulator);
void AXARTInitArtPitchMod(AXART_PITCH_MOD *articulator);
void AXARTInitArtVolume(AXART_VOLUME *articulator);
void AXARTInitArtAuxAVolume(AXART_AUXA_VOLUME *articulator);
void AXARTInitArtAuxBVolume(AXART_AUXB_VOLUME *articulator);
void AXARTInitArtVolumeEnv(AXART_VOLUME_ENV *articulator);
void AXARTInitArtVolumeMod(AXART_VOLUME_MOD *articulator);

void AXARTServiceSound(AXART_SOUND *sound);
void AXARTAddArticulator(AXART_SOUND *sound, AXART_ART *articulator);

f32 AXARTCents(s32 cents);
void AXARTPitchEnv(AXART_PITCH_ENV *articulator);
void AXARTVolumeEnv(AXART_VOLUME_ENV *articulator);
void AXARTLfo(AXART_LFO *lfo);
void AXARTSet3DDopplerScale(f32 scale);
void AXARTSet3DDistanceScale(f32 scale);
void AXART3DSound(AXART_3D *articulator);

#endif
