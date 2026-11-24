#include "dolphin/axart.h"

/* AX voice and MIX channel controls (ax.c, mix.c). */
extern void fn_800230A4(AXVPB *voice, u32 type);
extern void fn_80023228(AXVPB *voice, u16 itdL, u16 itdR);
extern void fn_800234D0(AXVPB *voice, f32 ratio);
extern void fn_80026D90(AXVPB *voice, s32 input);
extern void fn_80026E2C(AXVPB *voice, s32 auxA);
extern void fn_80026EAC(AXVPB *voice, s32 auxB);
extern void fn_80026EE0(AXVPB *voice, u32 pan);
extern void fn_80026F4C(AXVPB *voice, u32 span);

void AXARTServiceSound(AXART_SOUND *sound) {
    AXART_ART *articulator;
    s32 cents;
    s32 atten;
    s32 auxA;
    s32 auxB;
    u8 pan;
    u8 span;
    u8 src;
    u16 itdL;
    u16 itdR;
    f32 pitch;
    AXVPB *axvpb;

    cents = atten = auxA = auxB = 0;
    pan = 0x40;
    span = 0x7F;
    src = 1;
    itdL = itdR = 0;
    pitch = sound->sampleRate / 32000.0f;
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
            AXARTPitchEnv((AXART_PITCH_ENV *)articulator);
            cents += ((AXART_PITCH_ENV *)articulator)->cents;
            break;
        case AXART_TYPE_PITCH_MOD:
            AXARTLfo(&((AXART_PITCH_MOD *)articulator)->lfo);
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
            AXARTVolumeEnv((AXART_VOLUME_ENV *)articulator);
            atten += ((AXART_VOLUME_ENV *)articulator)->attenuation;
            break;
        case AXART_TYPE_AUX_A_VOLUME_ENV:
            AXARTVolumeEnv((AXART_VOLUME_ENV *)articulator);
            auxA += ((AXART_AUXA_VOLUME_ENV *)articulator)->attenuation;
            break;
        case AXART_TYPE_AUX_B_VOLUME_ENV:
            AXARTVolumeEnv((AXART_VOLUME_ENV *)articulator);
            auxB += ((AXART_AUXB_VOLUME_ENV *)articulator)->attenuation;
            break;
        case AXART_TYPE_VOLUME_MOD:
            AXARTLfo(&((AXART_VOLUME_MOD *)articulator)->lfo);
            atten += (s32)(((AXART_VOLUME_MOD *)articulator)->attenuation * ((AXART_VOLUME_MOD *)articulator)->lfo.output);
            break;
        case AXART_TYPE_AUX_A_VOLUME_MOD:
            AXARTLfo(&((AXART_AUXA_VOLUME_MOD *)articulator)->lfo);
            auxA += (s32)(((AXART_AUXA_VOLUME_MOD *)articulator)->attenuation * ((AXART_AUXA_VOLUME_MOD *)articulator)->lfo.output);
            break;
        case AXART_TYPE_AUX_B_VOLUME_MOD:
            AXARTLfo(&((AXART_AUXB_VOLUME_MOD *)articulator)->lfo);
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
    fn_80026D90(axvpb, atten >> 16);
    fn_80026E2C(axvpb, auxA);
    fn_80026EAC(axvpb, auxB);
    fn_80026EE0(axvpb, pan);
    fn_80026F4C(axvpb, span);
}

void AXARTAddArticulator(AXART_SOUND *sound, AXART_ART *articulator) {
    articulator->next = sound->articulators;
    sound->articulators = articulator;
}
