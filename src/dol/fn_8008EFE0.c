#include "types.h"

extern int printf(const char *, ...);
extern u32 fn_8008E770(u32, u32, u32, u32);
extern u32 fn_8008E9B4(u32);
extern u32 fn_8008EBF8(u32);
extern u32 fn_8008EC78(void);
extern char lbl_8015B900[25];
extern u32 lbl_801A6E1C;
extern u8 *lbl_801A6680;

#pragma opt_dead_assignments off
s32 fn_8008EFE0(u8 *arg0, u32 arg1) {
    u32 loc_20;
    u32 loc_1C;
    u32 loc_14[2];
    s32 i;
    s32 v1;
    struct { u32 value; } flag;
    s32 rem;
    u32 last;
    u32 off;
    u32 idx;
    u32 odd;
    u32 size;
    s32 n;
    s32 status;
    s32 v1_2;
    u32 count;
    if ((s32)lbl_801A6E1C != 0) {
        status = 1;
    } else {
        v1 = 0;
        while (0 == v1) {
            v1 = fn_8008EBF8(5);
        }
        status = v1;
        if (v1 == 0) {
            printf("Can't select EXI2 port!\n");
            status = 0;
        } else {
            lbl_801A6E1C = 1;
            loc_14[0] = 0;
            fn_8008E9B4(fn_8008E770((u32)loc_14, 2, 1, 0));
            fn_8008E9B4(fn_8008E770((u32)&loc_1C, 2, 0, 0));
        }
    }
    if (status == 0) return 1;
    if (arg1 & 3) flag.value = 1;
    else flag.value = 0;
{
    s32 fzgx_loop_rem_1266;
    u32 fzgx_loop_off_1266;
    count = (arg1 >> 2) + flag.value;
    odd = (arg1 & 3) + (arg1 & 1);
    fzgx_loop_rem_1266 = (s32)arg1 % 4;
    v1_2 = count - 1;
    last = v1_2;
    fzgx_loop_off_1266 = 0;
    idx = 0;
    while (fzgx_loop_off_1266 < arg1) {
        if (idx < last) size = 4;
        else if (odd == 2) size = 2;
        else size = 4;
        fn_8008E9B4(fn_8008E770((u32)&loc_20, size, 0, 0));
        if (arg1 - fzgx_loop_off_1266 >= 4) n = 4;
        else n = fzgx_loop_rem_1266;
        for (i = 0; i < n; i++) {
            (arg0 + fzgx_loop_off_1266)[i] = (loc_20 >> (8 * (3 - i)));
        }
        idx++;
        fzgx_loop_off_1266 += 4;
    }
    status = fzgx_loop_rem_1266;
    rem = status;
    off = fzgx_loop_off_1266;
}
    fn_8008EC78();
    lbl_801A6E1C = 0;
    *lbl_801A6680 = 0;
    return 0;
}
#pragma opt_dead_assignments reset
