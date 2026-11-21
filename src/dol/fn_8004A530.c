#include "types.h"

struct fn_8004A530_Arg0 {
    u8 pad_0[0x2];
    u8 unk_2;
};

s32 fn_8004A530(struct fn_8004A530_Arg0 *arg0) {
    return (s8)arg0->unk_2;
}

struct fn_8004A53C_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

u32 fn_8004A53C(struct fn_8004A53C_Arg0 *arg0) {
    return arg0->unk_10;
}

struct fn_8004A544_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
};

s32 fn_8004A544(struct fn_8004A544_Arg0 *arg0, u32 arg1) {
    arg0->unk_28 = arg1;
    return 1;
}

typedef struct Fn8004A550Data {
    u8 _pad14[0x14];
    s32 field14;
    s32 field18;
} Fn8004A550Data;

s32 fn_8004A550(Fn8004A550Data *data, s32 value4, s32 value5) {
    data->field18 = value4;
    data->field14 = value5;
    return 1;
}

struct fn_8004A560_Arg0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u32 unk_18;
};
struct fn_8004A560_Arg1 {
    u32 unk_0;
};
struct fn_8004A560_Arg2 {
    u32 unk_0;
};

s32 fn_8004A560(struct fn_8004A560_Arg0 *arg0, struct fn_8004A560_Arg1 *arg1, struct fn_8004A560_Arg2 *arg2) {
    arg1->unk_0 = arg0->unk_18;
    arg2->unk_0 = arg0->unk_14;
    return 1;
}
