#include "dolphin/axart.h"

void AXARTPitchEnv(AXART_PITCH_ENV *articulator) {
    if (articulator->cents == articulator->target) {
        return;
    }
    articulator->cents += articulator->delta;
    if (articulator->delta > 0) {
        if (articulator->cents > articulator->target) {
            articulator->cents = articulator->target;
        }
    } else if (articulator->delta < 0) {
        if (articulator->cents < articulator->target) {
            articulator->cents = articulator->target;
        }
    }
}

void AXARTVolumeEnv(AXART_VOLUME_ENV *articulator) {
    if (articulator->attenuation == articulator->target) {
        return;
    }
    articulator->attenuation = articulator->attenuation + articulator->delta;
    if (articulator->delta > 0) {
        if (articulator->attenuation > articulator->target) {
            articulator->attenuation = articulator->target;
        }
    } else if (articulator->delta < 0) {
        if (articulator->attenuation < articulator->target) {
            articulator->attenuation = articulator->target;
        }
    }
}
