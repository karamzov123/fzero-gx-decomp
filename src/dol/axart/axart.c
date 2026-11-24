#include "dolphin/axart.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);

/* AX voice and MIX channel controls (ax.c, mix.c). */
extern void fn_800230A4(AXVPB *voice, u32 type);
extern void fn_800231C4(AXVPB *voice);
extern void fn_80023228(AXVPB *voice, u16 itdL, u16 itdR);
extern void fn_800234D0(AXVPB *voice, f32 ratio);
extern void fn_80025EF4(AXVPB *voice, u32 mode, s32 input, s32 auxA, s32 auxB, u32 pan, u32 span, u32 fader);
extern void fn_80026D70(AXVPB *voice);

static AXART_SOUND *__AXARTSoundList;

void AXARTInit(void) {
    __AXARTSoundList = 0;
    AXARTSet3DDistanceScale(40.0f);
    AXARTSet3DDopplerScale(20.0f);
}

void AXARTQuit(void) {
    BOOL old;
    AXART_SOUND *sound;

    old = OSDisableInterrupts();
    for (sound = __AXARTSoundList; sound != 0; sound = sound->next) {
        fn_80026D70(sound->axvpb);
    }
    __AXARTSoundList = 0;
    OSRestoreInterrupts(old);
}

void AXARTServiceSounds(void) {
    AXART_SOUND *sound;

    for (sound = __AXARTSoundList; sound != 0; sound = sound->next) {
        AXARTServiceSound(sound);
    }
}

void AXARTInitSound(AXART_SOUND *sound, AXVPB *voice, u32 sampleRate) {
    sound->articulators = 0;
    sound->axvpb = voice;
    sound->sampleRate = sampleRate;
}

void AXARTAddSound(AXART_SOUND *sound) {
    AXART_ART *articulator;
    AXVPB *axvpb;
    s32 cents;
    s32 atten;
    s32 auxA;
    s32 auxB;
    f32 pitch;
    u8 pan;
    u8 span;
    u8 src;
    u16 itdL;
    u16 itdR;
    BOOL old;

    fn_800231C4(sound->axvpb);
    cents = atten = auxA = auxB = 0;
    pitch = sound->sampleRate / 32000.0f;
    pan = 0x40;
    span = 0x7F;
    src = 1;
    itdL = itdR = 0;
    articulator = sound->articulators;

    while (articulator != 0) {
        switch (articulator->type) {
        case AXART_TYPE_3D:
            AXART3DSound((AXART_3D *)articulator);
            pitch += ((AXART_3D *)articulator)->pitch;
            pan = ((AXART_3D *)articulator)->pan;
            span = ((AXART_3D *)articulator)->span;
            atten += ((AXART_3D *)articulator)->attenuation;
            itdL = ((AXART_3D *)articulator)->itdL;
            itdR = ((AXART_3D *)articulator)->itdR;
            src = ((AXART_3D *)articulator)->src;
            break;
        case AXART_TYPE_PANNING:
            pan = ((AXART_PANNING *)articulator)->pan;
            span = ((AXART_PANNING *)articulator)->span;
            break;
        case AXART_TYPE_ITD:
            itdL = ((AXART_ITD *)articulator)->itdL;
            itdR = ((AXART_ITD *)articulator)->itdR;
            break;
        case AXART_TYPE_SRC:
            src = ((AXART_SRC *)articulator)->src;
            break;
        case AXART_TYPE_PITCH:
            cents += ((AXART_PITCH *)articulator)->cents;
            break;
        case AXART_TYPE_PITCH_ENV:
            cents += ((AXART_PITCH_ENV *)articulator)->cents;
            break;
        case AXART_TYPE_PITCH_MOD:
            cents += (s32)(((AXART_PITCH_MOD *)articulator)->cents * ((AXART_PITCH_MOD *)articulator)->lfo.output);
            break;
        case AXART_TYPE_VOLUME:
            atten += ((AXART_VOLUME *)articulator)->attenuation;
            break;
        case AXART_TYPE_AUX_A_VOLUME:
            auxA += ((AXART_AUXA_VOLUME *)articulator)->attenuation;
            break;
        case AXART_TYPE_AUX_B_VOLUME:
            auxB += ((AXART_AUXB_VOLUME *)articulator)->attenuation;
            break;
        case AXART_TYPE_VOLUME_ENV:
            atten += ((AXART_VOLUME_ENV *)articulator)->attenuation;
            break;
        case AXART_TYPE_AUX_A_VOLUME_ENV:
            auxA += ((AXART_AUXA_VOLUME_ENV *)articulator)->attenuation;
            break;
        case AXART_TYPE_AUX_B_VOLUME_ENV:
            auxB += ((AXART_AUXB_VOLUME_ENV *)articulator)->attenuation;
            break;
        case AXART_TYPE_VOLUME_MOD:
            atten += (s32)(((AXART_VOLUME_MOD *)articulator)->attenuation * ((AXART_VOLUME_MOD *)articulator)->lfo.output);
            break;
        case AXART_TYPE_AUX_A_VOLUME_MOD:
            auxA += (s32)(((AXART_AUXA_VOLUME_MOD *)articulator)->attenuation * ((AXART_AUXA_VOLUME_MOD *)articulator)->lfo.output);
            break;
        case AXART_TYPE_AUX_B_VOLUME_MOD:
            auxB += (s32)(((AXART_AUXB_VOLUME_MOD *)articulator)->attenuation * ((AXART_AUXB_VOLUME_MOD *)articulator)->lfo.output);
            break;
        }
        articulator = articulator->next;
    }

    pitch *= AXARTCents(cents >> 16);
    axvpb = sound->axvpb;
    fn_800230A4(axvpb, src);
    fn_800234D0(axvpb, pitch);
    fn_80023228(axvpb, itdL, itdR);
    fn_80025EF4(sound->axvpb, 0, atten >> 16, auxA, auxB, pan, span, 0);

    old = OSDisableInterrupts();
    if (__AXARTSoundList != 0) {
        __AXARTSoundList->prev = sound;
        sound->next = __AXARTSoundList;
    } else {
        sound->next = 0;
    }
    sound->prev = 0;
    __AXARTSoundList = sound;
    OSRestoreInterrupts(old);
}

void AXARTRemoveSound(AXART_SOUND *sound) {
    BOOL old;

    old = OSDisableInterrupts();
    if (sound == __AXARTSoundList) {
        __AXARTSoundList = sound->next;
        if (__AXARTSoundList != 0) {
            __AXARTSoundList->prev = 0;
        }
    } else {
        AXART_SOUND *next = sound->next;
        AXART_SOUND *prev = sound->prev;

        prev->next = next;
        if (next != 0) {
            next->prev = prev;
        }
    }
    OSRestoreInterrupts(old);
    fn_80026D70(sound->axvpb);
}

void AXARTInitLfo(AXART_LFO *lfo, f32 *samples, u32 length, f32 delta) {
    lfo->lfo = samples;
    lfo->length = length;
    lfo->delta = delta;
    lfo->sampleIndex = 0;
    lfo->counter = lfo->sample1 = lfo->sample = lfo->output = 0.0f;
}

void AXARTInitArtPanning(AXART_PANNING *articulator) {
    articulator->art.type = AXART_TYPE_PANNING;
    articulator->pan = 64;
    articulator->span = 127;
}

void AXARTInitArtPitch(AXART_PITCH *articulator) {
    articulator->art.type = AXART_TYPE_PITCH;
    articulator->cents = 0;
}

void AXARTInitArtPitchMod(AXART_PITCH_MOD *articulator) {
    articulator->art.type = AXART_TYPE_PITCH_MOD;
    articulator->cents = 0;
    AXARTInitLfo(&articulator->lfo, AXARTSine, AXART_SINE_CNT, 0.0f);
}

void AXARTInitArtVolume(AXART_VOLUME *articulator) {
    articulator->art.type = AXART_TYPE_VOLUME;
    articulator->attenuation = 0;
}

void AXARTInitArtAuxAVolume(AXART_AUXA_VOLUME *articulator) {
    articulator->art.type = AXART_TYPE_AUX_A_VOLUME;
    articulator->attenuation = 0;
}

void AXARTInitArtAuxBVolume(AXART_AUXB_VOLUME *articulator) {
    articulator->art.type = AXART_TYPE_AUX_B_VOLUME;
    articulator->attenuation = 0;
}

void AXARTInitArtVolumeEnv(AXART_VOLUME_ENV *articulator) {
    articulator->art.type = AXART_TYPE_VOLUME_ENV;
    articulator->delta = articulator->target = articulator->attenuation = 0;
}

void AXARTInitArtVolumeMod(AXART_VOLUME_MOD *articulator) {
    articulator->art.type = AXART_TYPE_VOLUME_MOD;
    articulator->attenuation = 0;
    AXARTInitLfo(&articulator->lfo, AXARTSine, AXART_SINE_CNT, 0.0f);
}
