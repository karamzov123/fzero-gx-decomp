#include "types.h"
#include "dolphin/types.h"
#include "sdk_addresses.h"

vu32 __PIRegs[16] : FZGX_ADDR___PIRegs;
typedef void (*InterruptCallback)(s16, void *);
extern InterruptCallback *lbl_801A6678;

void fn_8008ECE0(s16 interrupt, void *context) {
    InterruptCallback cb;
    __PIRegs[0] = (__PIRegs[0] & 0x1000) | 0x1000;
    cb = *lbl_801A6678;
    if (cb != 0) {
        cb(2, context);
    }
}
