#include "types.h"

struct fn_80077240_lbl_801A3220 {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x22];
    u32 unk_24;
};

extern struct fn_80077240_lbl_801A3220 lbl_801A3220[];
extern u32 fn_80072CC4(u32, u32, u32, u32, u32);
extern u32 fn_80072D64(u32, u32, u32, u32, u32, u32);
extern u32 fn_800734A8(u32, u32, u32, u32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);

void fn_80077240(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    if ((s8)lbl_801A3220[0].unk_1 != 0 || (s32)*(u32 *)(arg2) != 0 || (s32)*(u32 *)(arg2 + 4) != 0) {
    fn_800734A8(*(u32 *)(arg1), 255, 255, 4);
    fn_80072C24(*(u32 *)(arg1), 15, 15, 15, *(u32 *)(arg2 + 8));
    fn_80072D64(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    fn_80072CC4(*(u32 *)(arg1), 7, 7, 7, *(u32 *)(arg2 + 12));
    fn_80072E20(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    } else {
    if ((s32)*(u32 *)(arg2) != 0) {
    if ((s32)*(u32 *)(arg2) != 0) {
    fn_80072C24(*(u32 *)(arg1), 15, 15, 15, *(u32 *)(arg2 + 8));
    }
    if ((s32)*(u32 *)(arg2 + 4) != 0) {
    fn_80072CC4(*(u32 *)(arg1), 7, 7, 7, *(u32 *)(arg2 + 12));
    }
    }
    }
    lbl_801A3220[0].unk_24 = -1;
    v0 = *(u32 *)(arg1);
    *(u32 *)((u8 *)arg1 + 0) = (v0 + 1);
}
