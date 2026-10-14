/* Non-matching: best partial attempt (96.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieSubInfo {
    s32 field_0;
    s32 field_4;
} MovieSubInfo;

typedef struct MovieModuleSubState {
    u8 pad_00[4];
    s32 field_4;
    s32 field_8;
    u8 pad_0c[0xd88];
    s32 field_d94;
    s32 field_d98;
    s32 field_d9c;
    s32 field_da0;
    s32 field_da4;
    u8 pad_da8[8];
    s32 field_db0;
    s32 field_db4;
    s32 field_db8;
    s32 field_dbc;
    s32 field_dc0;
} MovieModuleSubState;

typedef struct MovieIndex74 {
    s32 field_0;
    u8 pad_04[0x70];
} MovieIndex74;

typedef struct MovieIndex44 {
    u8 pad_00[0x14];
    s32 field_14;
    u8 pad_18[8];
    s32 field_20;
    u8 pad_24[0x20];
} MovieIndex44;

typedef struct MovieModuleState {
    u8 pad_00[0xd4c];
    s32 field_d4c;
    s32 field_d50;
    u8 pad_d54[0x43c];
    MovieIndex74 index74[20];
    MovieIndex44 index44[54];
    u8 pad_28f8[0x10];
    MovieModuleSubState *field_2908;
    MovieSubInfo info;
} MovieModuleState;

extern void fn_12_2D008(MovieModuleState *arg0);
extern s32 fn_12_23250(MovieModuleState *arg0);
extern s32 UTY_MulDiv(s32 a, s32 b, s32 c);

void fn_12_2D288(MovieModuleState *arg0) {
    s32 k;
    s32 w;
    s32 div;
    s32 w_2;
    s32 den;
    s32 num;
    s32 j;
    s32 k_2;
    s32 v;
    s32 flag;
    s32 idx;
    MovieModuleSubState *st;
    s32 value;
    MovieModuleSubState *st_2;
    MovieSubInfo *sub;

    if (arg0->field_2908 == 0) {
        return;
    }
    sub = (MovieSubInfo *)((u8 *)arg0 + 0x290c);
    fn_12_2D008(arg0);
    st = arg0->field_2908;
    if (fn_12_23250(arg0) != 0) {
        return;
    }
    flag = 0;
    if (st->field_d98 <= 0) {
        if (sub->field_4 == -3) {
            v = flag;
        } else {
            v = st->field_dc0;
        }
        if (v >= 0) {
            MovieIndex44 *base;

            base = arg0->index44;
            k = -1;
            idx = base[0].field_14;
            j = arg0->index74[idx].field_0;
            value = *(s32 *)(((j * 0x44) + ((u8 *)base)) + 0x20);
            if (value >= 0) {
                k_2 = value;
            }
            if (k_2 != -1) {
                st->field_d98 = v + k_2;
                flag = 1;
            }
        }
    }
    if (st->field_d9c <= 0) {
        if (arg0->field_d4c > 0) {
            st->field_d9c = arg0->field_d4c;
            flag = 1;
            st->field_da0 = arg0->field_d50;
        }
    }
    if (flag == 0) {
        return;
    }
    st_2 = arg0->field_2908;
    w = st_2->field_dbc;
    if (w > 0) {
        st_2->field_d94 = w;
        return;
    }
    num = st_2->field_db0;
    den = st_2->field_db4;
    div = st_2->field_db8;
    if (num > 0 && den > 0) {
        st_2->field_d94 = UTY_MulDiv(num, div, den);
        return;
    }
    if (st_2->field_4 > 0) {
        st_2->field_d94 = st_2->field_4;
        return;
    }
    if (num <= 0) {
        num = st_2->field_d98;
    }
    if (den <= 0) {
        den = st_2->field_d9c;
        w_2 = st_2->field_da0;
        div = w_2;
    }
    if (num > 0 && den > 0) {
        st_2->field_d94 = UTY_MulDiv(num, div, den);
    } else {
        st_2->field_d94 = st_2->field_4;
    }
}
