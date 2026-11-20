#include "types.h"


/* --- dol/fn_800589BC.c --- */
struct fn_800589BC_Arg2 {
    u32 unk_0;
    u32 unk_4;
};
struct fn_800589BC_Arg3 {
    u32 unk_0;
    u32 unk_4;
};
struct fn_800589BC_Copy8 { u32 a[2]; };

u32 fn_800589BC(u32 arg0, u32 arg1, struct fn_800589BC_Arg2 *arg2, struct fn_800589BC_Arg3 *arg3) {
    u32 v0;
    u32 v1;
    *(struct fn_800589BC_Copy8 *)(u32)arg2 = *(struct fn_800589BC_Copy8 *)arg0;
    arg3->unk_4 = arg2->unk_4;
    if ((s32)arg2->unk_4 > (s32)arg1) {
    arg2->unk_4 = arg1;
    }
    v0 = arg2->unk_4;
    arg3->unk_4 = (arg3->unk_4 - v0);
    if ((s32)arg3->unk_4 == 0) {
    arg3->unk_0 = 0;
    return v0;
    }
    v1 = arg2->unk_0;
    arg3->unk_0 = (v1 + arg2->unk_4);
    return v1;
}

/* --- dol/fn_80058A20.c --- */
extern u32 fn_800595A4(void);

void fn_80058A20(void) {
    fn_800595A4();
}
