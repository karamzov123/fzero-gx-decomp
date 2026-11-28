#ifndef MATHUTIL_LC_H
#define MATHUTIL_LC_H

#include "types.h"
#include "dolphin/hw_regs.h"

/* The engine math library keeps its working matrix A at the start of the Gekko locked cache
   (LC_BASE), with matrix B after it: the layout of SMB1's struct MathutilData. A port points
   these at an ordinary buffer. */
typedef struct MathutilData {
    /* 0x00 */ f32 mtxA[3][4];
    /* 0x30 */ f32 mtxB[3][4];
} MathutilData;

#define mathutilData ((MathutilData *)LC_BASE)
/* Some callers read or write matrix A in a fixed order; retail keeps that order. */
#define mathutilDataV ((volatile MathutilData *)LC_BASE)  /* volatile: retail access order */

#endif
