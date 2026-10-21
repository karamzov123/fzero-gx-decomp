#include "types.h"

typedef struct Fn8006B3F0Data {
    u8 pad_0[4];
    struct {
        u8 enabled:1;
        u8 active:1;
        u8 rest:6;
    } flags;
    u8 pad_5[3];
    s32 status;
    u8 pad_c[0x44];
    u8 data_50[1];
} Fn8006B3F0Data;

extern s32 lbl_801A6C88;
extern u8 lbl_80199670[0x4920];
extern s32 fn_8006B3F0(Fn8006B3F0Data *);
extern void fn_800139E8(u32, u32, s32);

#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma use_lmw_stmw on
#pragma optimize_for_size on
void fn_8006B224(void) {
    s32 i;
    u8 *base;
    s32 off;

    if (lbl_801A6C88 != 0) {
        base = lbl_80199670;
        for (i = 0; i < 4; i++) {
            fn_8006B3F0((Fn8006B3F0Data *)(base + i * 0x1248));
            fn_800139E8(i, 0x400, 0);
        }
        lbl_801A6C88 = 0;
    }
}
