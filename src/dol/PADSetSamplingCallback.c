#include "types.h"

extern u32 SIRegisterPollingHandler(u32);
extern u32 SIUnregisterPollingHandler(u32);
extern u32 lbl_801A6830;
extern void SamplingHandler(void);

u32 PADSetSamplingCallback(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6830;
    lbl_801A6830 = arg0;
    if (arg0 != 0) {
    SIRegisterPollingHandler((u32)SamplingHandler);
    } else {
    SIUnregisterPollingHandler((u32)SamplingHandler);
    }
    return v0;
}
