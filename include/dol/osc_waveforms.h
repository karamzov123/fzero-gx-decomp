#ifndef DOL_OSC_WAVEFORMS_H
#define DOL_OSC_WAVEFORMS_H

#include "types.h"

/* 4,200 signed 16-bit samples of concatenated oscillator waveforms: a 64-sample sine cycle
 * at the start, a sawtooth ramp at +0x440, noise, and a constant tail. No code addresses the
 * table directly, so the boundaries between the individual waveforms are not recovered.
 * Some sample pairs look like code addresses (0x8000 0x8000 is 0x80008000); the symbol is
 * marked noreloc in symbols.txt so dtk does not treat them as pointers. */
extern const s16 lbl_80092D40[4200];

#endif
