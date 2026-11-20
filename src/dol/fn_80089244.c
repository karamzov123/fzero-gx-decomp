#include "types.h"

extern u32 fn_8008AF40(u32);
extern u32 fn_8008AF48(u32);
extern u32 lbl_801A36E8[];
extern char lbl_800956A0[];

struct fn_80089244_Entry {
    u8 pad_0[4];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
};

u32 fn_80089244(u32 *arg0, u32 *arg1) {
    struct fn_80089244_Entry *v2;
    s32 v0;
    s32 v1;

    *arg1 = 0;
    v0 = 0x300;
    v1 = 0;
    while (v1 < 3) {
        v2 = 0;
        if (v1 >= 0 && v1 < 3) {
            v2 = (struct fn_80089244_Entry *)((u8 *)&lbl_801A36E8 + v1 * 0x890);
        }
        fn_8008AF48((u32)v2);
        if (v2->unk_4 == 0) {
            v2->unk_8 = 0;
            v0 = 0;
            v2->unk_C = 0;
            v2->unk_4 = 1;
            *arg1 = (u32)v2;
            *arg0 = v1;
            v1 = 3;
        }
        fn_8008AF40((u32)v2);
        v1++;
    }
    if (v0 == 0x300) {
        fn_8008963C(lbl_800956A0);
    }
    return v0;
}
