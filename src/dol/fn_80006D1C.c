#include "types.h"


/* --- dol/fn_80006D1C.c --- */
typedef u32 (*fn_80006D1C_Fn0)(u32, u32, u32, u32);
struct fn_80006D1C_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801220F0[];
extern u32 lbl_80122104[];
extern u32 lbl_801A6708;
extern void fn_80006BDC(int, ...);

u32 fn_80006D1C(struct fn_80006D1C_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u8 loc_20;
    /* frame */
    u32 t1;
    v0 = (u32)arg0;
    v1 = arg1;
    v2 = arg2;
    v3 = arg3;
    if ((s32)arg0->unk_0 != 1) {
    v0 = (u32)&lbl_801220F0;
    fn_80006BDC((u32)v0, v1);
    v1 = arg1;
    v2 = arg2;
    v3 = arg3;
    v0 = ((u32)arg0 + 4);
    t1 = ((fn_80006D1C_Fn0)lbl_801A6708)(v0, v1, v2, v3);
    v0 = t1;
    v4 = v0;
    }
    fn_80006BDC((u32)&lbl_80122104, v4);
    return v4;
}

/* --- dol/fn_80006DAC.c --- */
extern u32 DVDReadAsyncPrio(u32, u32, u32, u32, u32, u32);

struct fn_80006DAC_Arg0 {
    u32 unk_0;
};

u32 fn_80006DAC(struct fn_80006DAC_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (u32)arg0;
    v1 = arg5;
    if ((s32)arg0->unk_0 != 1) {
    v0 += 4;
    v1 = 2;
    t0 = DVDReadAsyncPrio(v0, arg1, arg2, arg3, arg4, v1);
    v0 = t0;
    v1 = v0;
    }
    v0 = v1;
    return v0;
}
