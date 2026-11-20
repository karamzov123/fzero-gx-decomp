#include "types.h"


/* --- dol/SIRefreshSamplingRate.c --- */
extern u32 SISetSamplingRate(u32);
extern u32 SamplingRate;

u32 SIRefreshSamplingRate(void) {
    return SISetSamplingRate(SamplingRate);
}

/* --- dol/fn_800133DC.c --- */
/* --- dol/fn_800133DC.c --- */
// fn_800133DC: empty in retail (single blr).
void fn_800133DC(void) {
}

/* --- dol/fn_800133E0.c --- */
extern u32 fn_8001375C(u32);
extern u32 lbl_8015CC10[];
extern u32 lbl_801A6828;

void fn_800133E0(u32 arg0) {
    s32 v0;
    u32 v1;
    v0 = (arg0 * 40);
    v1 = *(u32 *)((u8 *)((u8 *)&lbl_8015CC10 + v0) + 24);
    if ((s32)v1 == 0) {
    if ((s32)lbl_801A6828 == 0) {
    fn_8001375C(arg0);
    }
    }
}
