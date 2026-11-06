#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "sdk_addresses.h"
u32 __OSBusClock : FZGX_ADDR___OSBusClock;
#define OS_BUS_CLOCK __OSBusClock

struct fn_8006C7E8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10[10];
    u32 unk_38[10];
    u32 unk_60;
    u32 unk_64;
    u32 unk_68[16];
    u32 unk_A8[16];
    u32 unk_E8;
    u32 unk_EC;
};

extern u32 lbl_801A7390;
extern s32 OSGetTick(void);
extern f32 lbl_801327F8[];
extern s32 lbl_8019E114[];
extern volatile const f32 lbl_801A7394; // fzgx-allow: S2 retail reloads the scale on every iteration

#pragma optimize_for_size on
static inline void fn_8006C7E8_copy(struct fn_8006C7E8_Arg0 *arg0, s32 *src) {
    s32 i;
    for (i = 0; i < 10; i++) {
        arg0->unk_10[i] = src[i];
        arg0->unk_38[i] = 0;
    }
}
void fn_8006C7E8(struct fn_8006C7E8_Arg0 *arg0, u32 arg1) {
    u32 local[2];
    s32 i;

    local[0] = lbl_801A7390;
    arg0->unk_4 = 0;
    arg0->unk_60 = 0;
    arg0->unk_E8 = 0;

    for (i = 0; i < 16; i++) {
        arg0->unk_68[i] = 0;
        arg0->unk_A8[i] = 0;
    }

    arg0->unk_0 = arg1;
    arg0->unk_EC = 0;
    arg0->unk_C = 0;
    arg0->unk_8 = 0;
    arg0->unk_64 = 0;

    arg0->unk_4 = OSGetTick() / ((OS_BUS_CLOCK / 4) / 1000);

    fn_8006C7E8_copy(arg0, (s32 *)local);

    arg0->unk_60 = 0;

    {
    s32 j;
    for (j = 0; j < 10; j++) {
        lbl_8019E114[j] = lbl_801327F8[j] * lbl_801A7394;
    }
    i = j;
    }

    fn_8006C7E8_copy(arg0, lbl_8019E114);

    arg0->unk_60 = 0;
}
