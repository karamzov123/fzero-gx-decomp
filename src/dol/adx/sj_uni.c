#include "types.h"

struct SjUniCounter {
    u32 unk_0;
};

extern struct SjUniCounter lbl_8018F2A8[];
extern u32 lbl_8018F2AC[];
extern u32 memset(u32, u32, u32);

void fn_8005870C(void) {
    struct SjUniCounter *p;

    p = (struct SjUniCounter *)&lbl_8018F2A8;
    if (--p->unk_0 == 0) {
        memset((u32)&lbl_8018F2AC, 0, 3072);
    }
}

u32 fn_80058754(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = arg0;
    v1 = arg1;
    if ((s32)lbl_8018F2A8[0].unk_0 == 0) {
        v1 = 0;
        v0 = (u32)&lbl_8018F2AC;
        t0 = memset((u32)v0, v1, 3072);
        v0 = t0;
    }
    v1 = (u32)&lbl_8018F2A8;
    v0 = *(u32 *)((u8 *)v1 + 0);
    *(u32 *)((u8 *)v1 + 0) = (v0 + 1);
    return v0;
}
