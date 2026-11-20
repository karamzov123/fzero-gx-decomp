#include "types.h"


/* --- dol/fn_8008D154.c --- */
struct fn_8008D154_lbl_801A5638 {
    u32 unk_0;
};

extern struct fn_8008D154_lbl_801A5638 lbl_801A5638[];
extern u32 gTRKCPUState[];

u32 fn_8008D154(u32 arg0) {
    u32 v0;
    u32 v1;
    v0 = lbl_801A5638[0].unk_0;
    v1 = v0;
    if (arg0 >= v0) {
    if (arg0 < (v1 + 16384)) {
    v1 = (u32)&gTRKCPUState;
    if ((*(u32 *)(v1 + 568) & 0x3) != 0) { return arg0; }
    }
    }
    if (arg0 >= 0x7E000000) {
    if (arg0 <= 0x80000000) { return arg0; }
    }
    return ((arg0 & 0x3FFFFFFF) | 0x80000000);
}

/* --- dol/EnableMetroTRKInterrupts.c --- */
extern u32 fn_8008D440(void);

void EnableMetroTRKInterrupts(void) {
    fn_8008D440();
}
