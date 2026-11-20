#include "types.h"


/* --- dol/fn_80006C4C.c --- */
extern u32 fn_80006BDC(u32, ...);
extern u32 DVDFastOpen(u32, u32);
extern u32 lbl_801220E0[];
extern u32 lbl_801220CC[];

u32 fn_80006C4C(s32 arg0, u32 arg1) {
    u32 result = 0;

    if (arg0 < 0) {
        return 0;
    }

    fn_80006BDC((u32)&lbl_801220E0, arg0);
    if ((arg0 & 0x7fff0000) == 0) {
        fn_80006BDC((u32)&lbl_801220CC);
        result = DVDFastOpen(arg0, arg1 + 4);
        if (result != 0) {
            *(u32 *)arg1 = 0;
        }
    }

    return result;
}

/* --- dol/fn_80006CE4.c --- */
extern u32 DVDClose(u32);

struct fn_80006CE4_Arg0 {
    u32 unk_0;
};

u32 fn_80006CE4(struct fn_80006CE4_Arg0 *arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (u32)arg0;
    v1 = arg1;
    if ((s32)arg0->unk_0 != 1) {
    v0 += 4;
    t0 = DVDClose(v0);
    v0 = t0;
    v1 = v0;
    }
    v0 = v1;
    return v0;
}
