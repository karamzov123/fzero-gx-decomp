#include "types.h"

extern void __DVDStoreErrorCode(s32 error);
extern void DVDReset(void);
extern u32 DVDLowStopMotor(u32 callback);
extern void cbForStateError(s32 state);

typedef struct ExecutingState {
    u8 _pad[0xc];
    s32 error;
} ExecutingState;

extern ExecutingState *executing_801A68C0;
typedef struct DVDRegs {
    u8 _pad[0x20];
    u32 status;
} DVDRegs;

// Hardware register block is volatile because the DVD interface is memory-mapped.
extern volatile DVDRegs __DVDRegs;

void cbForUnrecoveredErrorRetry(u32 state) {
    if (state == 0x10) {
        executing_801A68C0->error = -1;
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else {
        executing_801A68C0->error = -1;
        if (state & 2) {
            __DVDStoreErrorCode(0x01234567);
            DVDLowStopMotor((u32)cbForStateError);
        } else {
            __DVDStoreErrorCode(__DVDRegs.status);
            DVDLowStopMotor((u32)cbForStateError);
        }
    }
}
