#include "types.h"

struct fn_800721FC_lbl_8019E250 {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
};

extern f32 lbl_801A745C;
extern struct fn_800721FC_lbl_8019E250 lbl_8019E250[];
extern f32 lbl_8019F008[];
extern void C_MTXPerspective(void *, f32, f32, f32, f32);
extern void GXSetProjectionv(void);

void fn_800721FC(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 v0;
    struct { f32 a[18]; } loc_8;

    lbl_8019E250[0].unk_4 = arg2;
    lbl_8019E250[0].unk_8 = arg3;
    C_MTXPerspective((void *)&loc_8, arg0, arg1, arg2, arg3);
    v0 = loc_8.a[0];
    lbl_8019F008[0] = lbl_801A745C;
    lbl_8019F008[1] = v0;
    lbl_8019F008[2] = loc_8.a[2];
    lbl_8019F008[3] = loc_8.a[5];
    lbl_8019F008[4] = loc_8.a[6];
    lbl_8019F008[5] = loc_8.a[10];
    lbl_8019F008[6] = loc_8.a[11];
    GXSetProjectionv();
}
