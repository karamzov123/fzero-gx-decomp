#include "types.h"

struct fn_80047578_lbl_8017B030 {
    u32 unk_0;
    u32 unk_4;
};

extern struct fn_80047578_lbl_8017B030 lbl_8017B030[];
extern u32 memset(u32, u32, u32);

void fn_80047578(void) {
    struct fn_80047578_lbl_8017B030 *p_lbl_8017B030;
    p_lbl_8017B030 = (struct fn_80047578_lbl_8017B030 *)&lbl_8017B030;
    memset((u32)((u8 *)p_lbl_8017B030 + 40), 0, 256);
    p_lbl_8017B030->unk_0 = 0;
    p_lbl_8017B030->unk_4 = 0;
}
