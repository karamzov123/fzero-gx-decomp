#include "types.h"


/* --- dol/fn_80050180.c --- */
typedef u32 (*fn_80050180_Fn0)(u32, u32);
struct fn_80050180_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};


s32 fn_80050180(struct fn_80050180_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    v0 = arg0->unk_4;
    if ((s32)((fn_80050180_Fn0)*(u32 *)((u8 *)*(u32 *)((u8 *)v0 + 0) + 36))(v0, 1) == 0 && (s32)*(u32 *)((u8 *)(u32)arg0 + 12) == 0 && (s32)*(u32 *)((u8 *)(u32)arg0 + 36) == 0) {
    v1 = 1;
    } else {
    v1 = 0;
    }
    return v1;
}

/* --- dol/fn_800501EC.c --- */
struct fn_800501EC_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

u32 fn_800501EC(struct fn_800501EC_Arg0 *arg0) {
    return arg0->unk_10;
}
