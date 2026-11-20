#include "types.h"

extern void fn_8005A648(void);
extern void fn_8005A628(void);
extern void fn_800230A4(void *, s32);
extern void fn_80023438(void *, void *);

typedef struct AdxtSlot {
    u8 _pad0[2];
    s8 count;
    u8 _pad3[5];
    void *voice[7];
    s32 rate;
    u8 _pad28[0x78];
    s16 flagA0;
    s16 flagA2;
    u32 flagA4;
} AdxtSlot;

#pragma opt_loop_invariants off
void fn_8005A7F8(AdxtSlot *p, s32 rate) {
    s16 sync[7];
    s32 i;
    s32 adj;
    s32 v0;
    u16 v1;

    if (p != 0) {
        p->rate = rate;
        adj = (rate * 1124 + 1124) / 1125;
        v0 = rate / 32000;
        v1 = ((rate << 8) / 125);
        {
    s32 fzgx_loop_i_651;
for (fzgx_loop_i_651 = 0; fzgx_loop_i_651 < p->count; fzgx_loop_i_651++) {
            fn_8005A648();
            if (p->voice[fzgx_loop_i_651] != 0) {
                if (p->flagA0 == 1) {
                    if (rate == 32000 && p->flagA2 == 0 && p != 0) {
                        p->flagA4 = 0;
                        p->flagA2 = 1;
                    }
                    sync[0] = (u16)((u32)adj / 32000);
                    sync[1] = (u16)((u32)(adj << 8) / 125);
                } else {
                    sync[0] = v0;
                    sync[1] = v1;
                }
                sync[2] = 0;
                sync[3] = 0;
                sync[4] = 0;
                sync[5] = 0;
                sync[6] = 0;
                fn_800230A4(p->voice[fzgx_loop_i_651], p->flagA4);
                fn_80023438(p->voice[fzgx_loop_i_651], sync);
            }
            fn_8005A628();
        }
    i = fzgx_loop_i_651;
}
    }
}
#pragma opt_loop_invariants reset

