#include "types.h"

typedef struct MovieObject {
    u8 pad_0000[0xf24];
    s32 field_f24;
    u8 pad_f28[0x24];
    s32 field_f4c;
    u8 pad_f50[0x8];
    s32 field_f58;
    s32 field_f5c;
} MovieObject;

extern int fn_12_2D73C(MovieObject *obj, int id);
extern u32 lbl_12_bss_7C64[137];
extern int fn_12_24A88(MovieObject *obj, int value);

#pragma opt_propagation off
int fn_12_2EAC4(MovieObject *obj) {
    u32 *table;
    int result;
    int num;
    int den;
    int flag;

    if (!fn_12_2D73C(obj, 6)) {
        flag = 0;
    } else {
        result = fn_12_2D73C(obj, 0x33);
        if (!result) {
            flag = 0;
        } else {
            table = (u32 *)&lbl_12_bss_7C64[0];

            if (fn_12_2D73C(obj, 0x47) == 1) {
                num = obj->field_f24 - obj->field_f4c;
                den = ((table)[110]);
            } else {
                s32 a = obj->field_f58;
                s32 b = obj->field_f4c;
                num = a - b;
                den = obj->field_f5c;
            }

            num = num / den;

            if (num > result) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
    }

    if (flag) {
        fn_12_24A88(obj, 0xff000222);
        return 1;
    }

    return 0;
}
#pragma opt_propagation reset

