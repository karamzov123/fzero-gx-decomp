#include "types.h"

typedef struct MovieModule {
    u8 pad_0000[0x2c];
    int field_2c;
    u8 pad_0030[0x48];
    int field_78;
    u8 pad_007c[0x78];
    int field_f4;
    u8 pad_00f8[0x854];
    int field_94c;
    u8 pad_0950[0x10];
    s32 field_960;
    u8 pad_0964[0x98];
    int field_9fc;
    u8 pad_a00[0x3a4];
    int field_da4;
    u8 pad_da8[0x1c];
    int field_dc4;
    u8 pad_dc8[0xd68];
    void *field_1b30;
    int field_1b34;
    int field_1b38;
    int field_1b3c;
    u8 pad_1b40[0x794];
    int field_22d4;
    u8 pad_22d8[0x8];
    int field_22e0;
} MovieModule;

typedef struct MovieState {
    void *field_0;
    u8 pad_4[0xe0];
    int field_e4;
} MovieState;

extern int fn_12_2D73C(MovieModule *module, int value);
extern int fn_12_21D30(MovieModule *module, int value);
extern int fn_12_23F00(MovieModule *module);
extern int fn_12_24990(MovieModule *module);
extern void fn_12_24A88(void *obj, int code);
extern int fn_12_CAE4(int value, int arg, int flag);
extern int fn_12_298AC(MovieModule *module, int *a, int *b);
extern int fn_12_28CC4(MovieModule *module, int a, int b, int *c);
extern int fn_12_21D50(MovieModule *module, int value);
extern int fn_12_2AC8C(MovieModule *module);
extern int fn_12_2ABF0(MovieModule *module);
extern int fn_12_AB00(void *obj, int *value);
extern int fn_12_21E94(MovieModule *module, int value);
extern int fn_12_2F1B4(MovieModule *module, int value);
extern int fn_12_21F38(MovieModule *module, int value);
extern void fn_12_21D60(MovieModule *module, int value, int flag);
extern void fn_12_21D40(MovieModule *module, int value, int flag);
extern void fn_12_2D7DC(MovieModule *module, int value, int flag);

#pragma opt_lifetimes off
int fn_12_29FF8(MovieModule *module) {
    int *fzgx_value;
    int local_14;
    int local_10;
    int local_c;
    int local_8;
    int result;
    int value;
    int other;
    int not;
    int flag;
    MovieState *state;
    void *state0;

    if (fn_12_2D73C(module, 5) == 0) {
        return 0;
    }
    if (fn_12_21D30(module, module->field_1b3c) == 1) {
        return 0;
    }
    if (fn_12_2D73C(module, 0x1c) != 0 && fn_12_23F00(module) != -1) {
        do {
            int v;
            if (module == 0) {
                v = 0;
            } else {
                if (fn_12_24990(module) != 0) {
                    fn_12_24A88(0, (0xff00 << 16) | 0x181);
                    break;
                }
                v = *(int *)module->field_1b30;
            }
            if (fn_12_CAE4(v, 5, 0) != 0) {
                fn_12_24A88(module, (0xff00 << 16) | 0xf12);
            }
        } while (0);
    }
    for (;;) {
        result = fn_12_298AC(module, &local_c, &local_14);
        if (result == 0) {
            result = fn_12_28CC4(module, local_c, local_14, &local_10);
            if (result == 0 && local_10 != 0) {
                continue;
            }
        }
        break;
    }
    value = module->field_1b3c;
    other = module->field_1b38;
    if (fn_12_21D50(module, value) != 1 && fn_12_21D50(module, other) == 1) {
        if (fn_12_2AC8C(module) != 0) {
            flag = 1;
        } else {
            other = module->field_9fc;
{
    int limit;
            limit = module->field_2c;
            if (other == -1) {
                other = limit;
            }
            if (limit < other) {
                other = limit;
}
            }
            if (fn_12_2ABF0(module) >= other) {
                state = module->field_1b30;
                state0 = state->field_0;
                if (fn_12_21D30(module, module->field_1b38) == 1) {
                    flag = 1;
                } else if (module->field_78 != 0 && module->field_f4 == 0) {
                    flag = 1;
                } else if (fn_12_AB00(state0, &local_8), (unsigned)(local_8 - 0x30000) == 0xffff) {
                    flag = 1;
                } else if (fn_12_21E94(module, 1) >= state->field_e4) {
                    flag = 1;
                } else {
                    not = fn_12_2F1B4(module, 1) == 0;
                    other = fn_12_21F38(module, not);
                    if (fn_12_21E94(module, not) >= other) {
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                }
                if (flag != 0) {
                    flag = 1;
                    goto done; /* retail shares the single flag = 0 fallthrough for both failing paths */
                }
            }
            flag = 0;
        }
done:
        if (flag != 0) {
            fn_12_21D60(module, value, 1);
            if (module->field_dc4 != 0x7fffffff) {
                fzgx_value = &(module->field_da4);
                *fzgx_value = 1;
            }
        }
    }
    other = fn_12_2ABF0(module);
    if (other == -1 || (fn_12_2AC8C(module) != 0 && other == 1 && module->field_960 != 0)) {
        fn_12_21D40(module, module->field_1b3c, 1);
        if (module->field_94c == 0) {
            fn_12_2D7DC(module, 5, 0);
        }
    }
    return result;
}
