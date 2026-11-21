#include "types.h"

extern u32 fn_800285DC(u32);
extern u32 lbl_801A6B90;

void fn_800280F0(void) {
    u32 v0;
    v0 = lbl_801A6B90;
    while (v0 != 0) {
    fn_800285DC(v0);
    v0 = *(u32 *)(v0);
    }
}

typedef struct Fn80028130Data_u1 Fn80028130Data_u1;

struct Fn80028130Data_u1 {
    u8 pad0[8];
    u32 value0;
    f32 value1;
    u32 value2;
};

extern f64 lbl_801A7008;

void fn_80028130(Fn80028130Data_u1 *data, u32 value0, u32 value1) {
    data->value2 = 0;
    data->value0 = value0;
    data->value1 = value1;
}
