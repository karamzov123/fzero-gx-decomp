#include "types.h"


/* --- dol/TRKDestructEvent.c --- */
extern u32 fn_800891B4(u32);

struct TRKDestructEvent_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void TRKDestructEvent(struct TRKDestructEvent_Arg0 *arg0) {
    fn_800891B4(arg0->unk_8);
}

/* --- dol/fn_80088764.c --- */
struct fn_80088764_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

void fn_80088764(struct fn_80088764_Arg0 *arg0, u32 arg1) {
    arg0->unk_0 = arg1;
    arg0->unk_4 = 0;
    arg0->unk_8 = -1;
}
