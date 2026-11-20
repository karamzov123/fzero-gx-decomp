#include "types.h"

struct fn_16_DC8_lbl_16_data_82B00 {
    u32 unk_0;
};

extern struct fn_16_DC8_lbl_16_data_82B00 lbl_16_data_82B00;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 lbl_16_bss_150;

void fn_16_DC8(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if ((s32)lbl_16_data_82B00.unk_0 != -1) {
    v0 = (u32)&lbl_16_bss_150;
    v0 = *(u32 *)((u8 *)v0);
    t0 = fn_1_435C(v0);
    v0 = t0;
    v0 = (u32)&lbl_16_data_82B00;
    v0 = *(u32 *)((u8 *)v0);
    t1 = fn_1_426C(v0);
    v0 = t1;
    lbl_16_data_82B00.unk_0 = -1;
    }
}
