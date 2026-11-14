#include "types.h"

struct fn_8006C634_Arg2 {
    u32 unk_0;
};
struct fn_8006C634_lbl_8019E014 {
    s16 unk_0[1];
};

extern struct fn_8006C634_lbl_8019E014 lbl_8019E014[];

void fn_8006C634(u32 arg0, u32 arg1, struct fn_8006C634_Arg2 *arg2) {
    u32 v0;
    s32 v1;
    s32 unk_1;
    s32 v4;

    v0 = arg1 & 0xFF;
    if (v0 < 64) {
        v1 = lbl_8019E014[0].unk_0[v0];
    } else if (v0 < 128) {
        v1 = lbl_8019E014[0].unk_0[127 - v0];
    } else if (v0 < 192) {
        v1 = -lbl_8019E014[0].unk_0[v0 - 128];
    } else {
        v1 = -lbl_8019E014[0].unk_0[255 - v0];
    }
    unk_1 = arg0 * v1;
    v4 = 0x1FE00;
    if (unk_1 < 0) {
        v4 = -0x1FE00;
    }
    {
        s32 scaled = unk_1 * 127;
        scaled += v4;
        arg2->unk_0 = -(scaled / 0x3FC00);
    }
}
