#include "types.h"


/* --- dol/SIRefreshSamplingRate.c --- */
extern u32 SISetSamplingRate(u32);
extern u32 SamplingRate;

u32 SIRefreshSamplingRate(void) {
    return SISetSamplingRate(SamplingRate);
}
