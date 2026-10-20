#include "types.h"

#pragma opt_propagation off

extern u8 lbl_12_rodata_194[248];
extern void fn_12_309C(u32, u32, u32);

typedef struct Fn12_A5C_0 {
    u8 pad0[8];
    s32 field_08;
    s32 field_0C;
    u8 pad10[0x10];
    s32 field_20;
    u8 pad24[0x10];
    s32 field_34;
    s32 field_38;
} Fn12_A5C_0;

typedef struct Fn12_A5C_1 {
    u8 pad0[4];
    s32 field_04;
    s32 field_08;
    s32 field_0C;
    u8 pad10[4];
    s32 field_14;
    s32 field_18;
    u8 pad1C[8];
    s32 field_24;
    s32 field_28;
    u8 pad2C[0x20];
    s32 field_4C;
} Fn12_A5C_1;

typedef struct Fn12_A5C_2 {
    u32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
} Fn12_A5C_2;

typedef struct Fn12_A5C_3 {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
} Fn12_A5C_3;

extern void fn_12_3DCEC(Fn12_A5C_3 *, Fn12_A5C_2 *, s32);
extern void fn_12_3DBE0(Fn12_A5C_3 *, Fn12_A5C_2 *, s32);
extern void fn_12_3A64(s32, s32, s32);
extern void fn_12_3710(s32, s32, s32);

#pragma opt_common_subs off
void fn_12_A5C(Fn12_A5C_0 *param0, Fn12_A5C_1 *param1, s32 type, s32 param3) {
    s32 *fzgx_value;
    Fn12_A5C_3 var3;
    Fn12_A5C_2 var2;
    s32 product;
    s32 half;
    s32 quarter;
    s32 local1;
    s32 local2;
    s32 code;
    product = param1->field_08 * param1->field_0C;
    half = product / 2;

    var3.f00 = param1->field_04 + half;
    var3.f04 = ((quarter = half / 2) + (param1->field_14));
    var3.f08 = param1->field_24 + quarter;
    var3.f0C = param1->field_08;
    var3.f10 = param1->field_18;
    var3.f14 = param1->field_28;
    var3.f18 = 0;

    local1 = param0->field_08 == 0 ? param1->field_08 : param0->field_08;
    local2 = param0->field_0C == 0 ? param1->field_0C / 2 : param0->field_0C;

    switch (type) {
    case 0x10:
        code = 1;
        break;
    case 0x18:
        code = 2;
        break;
    case 0x20:
        code = 3;
        break;
    case 0:
    default:
        fn_12_309C(0, 0, (u32)lbl_12_rodata_194);
        code = 0;
        break;
    }

    var2.f00 = code;
    var2.f04 = param3;
    var2.f08 = local1;
    var2.f0C = local2;
    var2.f10 = param1->field_08;
    var2.f14 = param1->field_0C / 2;

    switch (type) {
    case 0x10: {
        s32 flag = (param0->field_34 != 100);
        if (flag == 1) {
            param0->field_34 = 11;
            fn_12_3A64(param0->field_20, param1->field_4C, param0->field_38);
        }
        fn_12_3DCEC(&var3, &var2, param0->field_38);
        break;
    }
    case 0x20: {
        s32 flag = (param0->field_34 != 100);
        if (flag == 1) {
            fzgx_value = &(param0->field_34);
            *fzgx_value = 13;
            fn_12_3710(param0->field_20, param1->field_4C, param0->field_38);
        }
        fn_12_3DBE0(&var3, &var2, param0->field_38);
        break;
    }
    }
}
#pragma opt_common_subs reset
