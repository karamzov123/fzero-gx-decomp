#include "types.h"

extern u32 SISetSamplingRate(u32);
extern u32 SamplingRate_801A6820;

u32 SIRefreshSamplingRate(void) {
    return SISetSamplingRate(SamplingRate_801A6820);
}
