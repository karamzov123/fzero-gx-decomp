#include "types.h"

#pragma force_active on
u8 lbl_8019F040[0x20] = {0};
#pragma force_active reset
u8 lbl_8019F040__fzgx_offset_20[0x30] = {0};
u8 lbl_8019F040__fzgx_offset_50[3][0x30] = {{0}};
u32 lbl_8019F040__fzgx_offset_E0[4] = {0};
extern u32 lbl_801A6D78;
extern void lbl_8006DD14(void *arg0, void *arg1);

void fn_800749B0(u32 index, void *transform) {
    if (index == 0) {
        if (transform != 0) {
            lbl_8006DD14(transform, lbl_8019F040__fzgx_offset_20);
            lbl_801A6D78 = 1;
        } else {
            lbl_801A6D78 = 0;
        }
    } else {
        if (transform != 0) {
            lbl_8006DD14(transform, lbl_8019F040__fzgx_offset_50[index - 1]);
            *(u32 *)((u8 *)lbl_8019F040__fzgx_offset_E0 + ((index - 1) << 2)) = 1;
        } else {
            *(u32 *)((u8 *)lbl_8019F040__fzgx_offset_E0 + ((index - 1) << 2)) = 0;
        }
    }
}
