#include <dolphin/si/SIPriv.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/si.h>

u32 SIGetType(s32 chan);

extern u32 Type[4];

extern SITypeAndStatusCallback lbl_8015CB70[4][4];

u32 SIGetTypeAsync(s32 chan, SITypeAndStatusCallback callback) {
    BOOL enabled;
    u32 type;
    enabled = OSDisableInterrupts();
    type = SIGetType(chan);
    if (Type[chan] & 0x0080) {
        int i;
        for (i = 0; i < 4; ++i) {
            if (lbl_8015CB70[chan][i] == callback) {
                break;
            }
            if (lbl_8015CB70[chan][i] == 0) {
                lbl_8015CB70[chan][i] = callback;
                break;
            }
        }
    } else {
        callback(chan, type);
    }
    OSRestoreInterrupts(enabled);
    return type;
}
