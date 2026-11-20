#include "types.h"
struct fn_80077488_Arg0 {
    u32 unk_0;
};
struct fn_80077488_lbl_801A3220 {
    u8 pad_0[0x2];
    u8 unk_2;    u8 pad_3[0x5D];
};
extern f32 lbl_801A7488;
extern f64 lbl_801A7490;
extern struct fn_80077488_lbl_801A3220 lbl_801A3220[];
extern u32 lbl_8019F130[];
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern u32 fn_800371F8(u32, void *);

struct FzgxCopy_4 { u32 words[1]; };
void fn_80077488(void *arg0, void *arg1) {
    struct FzgxCopy_4 loc_C;
    u32 sp8;
    s32 temp_r5;

    temp_r5 = *(s32 *)((u8 *)(arg0));
    if (temp_r5 & 0x100) {
        if (lbl_801A3220->unk_2 != 2) {
            lbl_801A3220->unk_2 = 2;
            if (lbl_801A7488 == (*(f32 *)((u8 *)(lbl_8019F130) + 12))) {
                fn_800747D0((4U), (0U), (1U), (1U), (0U), (0U), (2U));
                return;
            }
            fn_800747D0((2U), (0U), (0U), (0U), (0U), (0U), (2U));
            fn_800747D0((0U), (0U), (1U), (1U), (0U), (0U), (2U));
        }
    } else {
        lbl_801A3220->unk_2 = 1;
        if (!(temp_r5 & 0x88)) {
            (*(u8 *)(&loc_C)) = 0xFF;
            (*((u8 *)(&loc_C) + 1)) = 0xFF;
            (*((u8 *)(&loc_C) + 2)) = 0xFF;
        } else {
            loc_C.words[0] = *(u32 *)((u8 *)(arg0) + 4);
        }
        (*((u8 *)(&loc_C) + 3)) = ((*((u8 *)(arg0) + 17)) * (*(f32 *)((u8 *)(lbl_8019F130) + 12)));
        sp8 = loc_C.words[0];
        fn_800371F8((1U), &sp8);
        (*(s32 *)((u8 *)(arg1) + 8)) = 2;
        (*(s32 *)((u8 *)(arg1) + 12)) = 1;
    }
}
