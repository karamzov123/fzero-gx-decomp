#include "types.h"

typedef u32 (*fn_80057774_Fn0)(s32, s32);

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);

u32 fn_80057774(u32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 var_r0;
    s32 temp_r3;
    fn_80057774_Fn0 temp_r12;
    u32 res;

    fn_80057728();
    if (arg1 == 0) {
        var_r0 = 0;
    } else if (arg1 == 1) {
        temp_r3 = *(s32 *)(arg0 + 12);
        var_r0 = (temp_r3 < arg2) ? temp_r3 : arg2;
    } else {
        var_r0 = 0;
        temp_r12 = *(fn_80057774_Fn0 *)(arg0 + 28);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)(arg0 + 32), -3);
        }
    }
    *arg3 = var_r0;
    fn_800576DC();
    return !(arg2 - var_r0);
}
