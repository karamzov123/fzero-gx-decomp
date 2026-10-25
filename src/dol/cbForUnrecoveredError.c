#include "types.h"

extern void __DVDStoreErrorCode(s32 error);
extern void DVDReset(void);
extern void cbForStateError(s32 state);
extern void fn_80017EA8(void);
extern void cbForUnrecoveredErrorRetry(void);
extern void DVDLowRequestError(void (*callback)(void));

typedef struct ExecutingState {
    u8 _pad[0xc];
    s32 error;
} ExecutingState;

extern ExecutingState *executing_801A68C0;

void cbForUnrecoveredError(u32 state) {
    if (state == 0x10) {
        executing_801A68C0->error = -1;
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else if (state & 1) {
        fn_80017EA8();
    } else {
        DVDLowRequestError(cbForUnrecoveredErrorRetry);
    }
}
