#include "types.h"

struct fn_8008D028_lbl_801A5638 {
    u32 unk_0;
};

extern struct fn_8008D028_lbl_801A5638 lbl_801A5638[];
extern u32 gTRKCPUState[];
extern u32 lbl_8015B898[];
extern u8 gTRKInterruptVectorTable[];
extern void *fn_800035C0(void *, const void *, u32);
extern void fn_8008AFF0(u32, u32);

#pragma opt_dead_assignments off
#pragma opt_common_subs off
void fn_8008D028(void) {
    u32 addr;
    u32 *pCPU;
    s32 i;
    u32 mask;
    u32 *tbl;
    u32 v2;
    u32 v0;

    v0 = lbl_801A5638[0].unk_0;
    if (v0 <= 0x44 && (v0 + 0x4000) > 0x44 && (gTRKCPUState[0x238 / 4] & 3) != 0) {
        v2 = 0x44; /* fzgx-allow: A1 low physical word */
    } else {
        v2 = 0x80000044; /* fzgx-allow: A1 cached alias of the low physical word */
    }
    mask = *(u32 *)v2;
    tbl = lbl_8015B898;
    pCPU = gTRKCPUState;
    for (i = 0; i <= 0xe; i++) {
        u32 t0;
        if ((mask & (1 << i)) != 0 && i != 4) {
            t0 = tbl[i];
            if (t0 >= lbl_801A5638[0].unk_0 && t0 < lbl_801A5638[0].unk_0 + 0x4000 &&
                (pCPU[0x238 / 4] & 3) != 0) {
                addr = t0;
            } else if (t0 >= 0x7E000000 && t0 <= 0x80000000) {
                addr = t0;
            } else {
                addr = (t0 & 0x3FFFFFFF) | 0x80000000;
            }
            fn_800035C0((void *)addr, gTRKInterruptVectorTable + t0, 0x100);
            fn_8008AFF0(addr, 0x100);
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

