#include "types.h"
#include "dolphin/types.h"
#include "sdk_addresses.h"


/* --- dol/fn_8008ECE0.c --- */
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

/* --- dol/fn_8008ED30.c --- */
extern u32 __OSMaskInterrupts(u32);
extern u32 __OSSetInterruptHandler(u32, u32);
extern u32 __OSUnmaskInterrupts(u32);

u32 fn_8008ED30(void) {
    __OSMaskInterrupts((0x10000 + -32768));
    __OSSetInterruptHandler(25, (u32)fn_8008ECE0);
    return __OSUnmaskInterrupts(64);
}

/* --- dol/fn_8008ED70.c --- */
vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;
vu32 __SIRegs[16] : FZGX_ADDR___SIRegs;
extern u8 lbl_801A6398[24];
extern void *memset(void *, int, u32);

void fn_8008ED70(void) {
    memset(lbl_801A6398, 0, 0x18);
    __EXIRegs[10] = 0;
    __SIRegs[15] = 0;
}

/* --- dol/fn_8008EDB0.c --- */
extern u8 *lbl_801A6680;
extern void (*lbl_801A6E20)(u32);

void fn_8008EDB0(void) {
    *lbl_801A6680 = 1;
    if (lbl_801A6E20 != 0) {
        lbl_801A6E20(0);
    }
}
