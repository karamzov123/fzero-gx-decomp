#include "types.h"

extern s32 lbl_801A6E10[2];
extern void MWTRACE(u32, ...);
extern s32 fn_8008F748(void);
extern u32 fn_8008F6BC(void *buf, s32 value);
extern u8 lbl_801A6378[32];
extern void fn_8008E21C(void *table, void *buf, s32 value);
extern u32 fn_8008E374(u8 *table);
extern void fn_8008E114(u8 *table, u32 dst, u32 len);
extern char lbl_80095E0C[];
extern char lbl_80095E34[];

#pragma opt_loop_invariants off
s32 gdev_cc_read(u32 arg0, s32 arg1) {
    u8 buffer[0x500];
    struct { u8 *value; } table;
    u32 result = 0;
    struct { u32 value; } size;

    if (lbl_801A6E10[0] == 0) {
        return -10001;
    }
    MWTRACE(1, lbl_80095E0C, arg1, arg1);
    table.value = (u8 *)&lbl_801A6378;
    size.value = arg1;
    while (fn_8008E374(table.value) < size.value) {
        s32 value;
        result = 0;
        value = fn_8008F748();
        if (value != 0) {
            if ((result = fn_8008F6BC(buffer, size.value)) == 0) {
                fn_8008E21C(table.value, buffer, value);
            }
        }
    }
    if (result == 0) {
        fn_8008E114(lbl_801A6378, arg0, arg1);
    } else {
        MWTRACE(8, lbl_80095E34, result);
    }
    return result;
}
