#include "types.h"

struct fn_800243C4_Arg0 {
    u32 unk_0;
    s32 unk_4;
    u32 unk_8;
};

struct fn_800243C4_Arg1 {
    u8 pad_0[0x1A8];
    f32 unk_1A8;
    u8 pad_1AC[0x18];
    u8 unk_1C4;
};

extern f32 lbl_801A6F80[];
extern f32 lbl_801A6F84;
extern f32 lbl_801A6FBC;
extern void fn_80023B70(u32, u32, f32, f32);
extern void fn_80023D00(u32, u32, u32);

#pragma peephole off
#pragma opt_common_subs off
#pragma opt_dead_assignments off

void fn_800243C4(struct fn_800243C4_Arg0 *arg0, struct fn_800243C4_Arg1 *arg1) {
    u32 i;
    s32 v5;
    s32 v4;
    s32 v3;
    f64 v1;
    f64 v0;
    f64 v2;

    if (!arg1->unk_1C4) {
        v3 = arg0->unk_8;
        v4 = arg0->unk_4;
        v5 = arg0->unk_0;

        v1 = (1.0f);
        v0 = (0.5f);
        v2 = (0.0f);
        i = 0;
        while ((((0xFF) & i)) < 3) {
            switch ((((0xFF) & i))) {
            case 0:
                if ((0.0f) != arg1->unk_1A8) {
                    f32 t = (0.5f) * arg1->unk_1A8;
                    fn_80023B70(v5, v4, t, (1.0f) - t);
                }
                fn_80023D00(v5, (u32)arg1, 0);
                break;
            case 1:
                fn_80023D00(v4, (u32)arg1, 1);
                break;
            case 2:
                fn_80023D00(v3, (u32)arg1, 2);
                break;
            }
            i++;
        }
    }
}
#pragma opt_dead_assignments reset


#pragma opt_common_subs reset

#pragma peephole reset

