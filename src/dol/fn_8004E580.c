#include "types.h"

extern struct fn_8004E580_lbl_8017E984 lbl_8017E984;

struct fn_8004E580_lbl_8017E984 {
    u32 unk_0;
};

u32 fn_8004E580(void) {
    return (((-lbl_8017E984.unk_0) | lbl_8017E984.unk_0) >> 31);
}
