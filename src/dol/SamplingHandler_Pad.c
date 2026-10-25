#include "types.h"

extern u32 lbl_801A6994;
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);

void SamplingHandler_Pad(u32 unused, void *context) {
    u8 local_context[0x2c8];

    if (lbl_801A6994 != 0) {
        OSClearContext(local_context);
        OSSetCurrentContext(local_context);
        ((void (*)(void))lbl_801A6994)();
        OSClearContext(local_context);
        OSSetCurrentContext(context);
    }
}
