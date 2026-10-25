#include "types.h"

extern u32 SIRegisterPollingHandler(u32);
extern u32 SIUnregisterPollingHandler(u32);
extern u32 lbl_801A6994;
extern void SamplingHandler_Pad(void);

u32 PADSetSamplingCallback_Pad(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6994;
    lbl_801A6994 = arg0;
    if (arg0 != 0) {
    SIRegisterPollingHandler((u32)SamplingHandler_Pad);
    } else {
    SIUnregisterPollingHandler((u32)SamplingHandler_Pad);
    }
    return v0;
}
