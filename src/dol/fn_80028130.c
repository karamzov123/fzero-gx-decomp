#include "types.h"

typedef struct Fn80028130Data Fn80028130Data;

struct Fn80028130Data {
    u8 pad0[8];
    u32 value0;
    f32 value1;
    u32 value2;
};

extern f64 lbl_801A7008;

void fn_80028130(Fn80028130Data *data, u32 value0, u32 value1) {
    data->value2 = 0;
    data->value0 = value0;
    data->value1 = value1;
}
