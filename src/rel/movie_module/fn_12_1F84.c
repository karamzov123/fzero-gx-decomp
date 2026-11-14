#include "types.h"

// 0x00001F84..0x000023CC

typedef struct MovieArg0 {
    s32 pad_00;
    s32 format;
    s32 count;
    s32 pad_0c[11];
    u32 field_38;
} MovieArg0;

typedef struct MovieArg1 {
    s32 pad_00;
    s32 width;
    s32 height;
    s32 depth;
    s32 pad_10;
    s32 offset_x;
    s32 offset_y;
    s32 pad_1c;
    s32 pad_20;
    s32 step_x;
    s32 step_y;
    s32 pad_2c[6];
    s32 field_44;
    s32 field_48;
    s32 pad_4c[10];
    s32 field_74;
} MovieArg1;

typedef struct MovieMatrix {
    s32 x;
    s32 y;
    s32 z;
    s32 width;
    s32 height;
    s32 depth;
    s32 pad_18;
} MovieMatrix;

typedef struct MovieSource {
    s32 object;
    s32 field_04;
    s32 field_08;
    s32 field_0c;
    s32 pad_10;
    s32 pad_14;
} MovieSource;

extern s32 fn_12_308C(void);
extern void fn_12_309C(s32 code, s32 line, const char *message);
extern void fn_12_3D144(MovieMatrix *matrix, MovieSource *source);
extern void fn_12_3DCF0(MovieMatrix *matrix, MovieSource *source, u32 arg2);
extern void fn_12_3DF08(MovieMatrix *matrix, MovieSource *source);
extern const char lbl_12_rodata_60[];

void fn_12_1F84(MovieArg0 *arg0, MovieArg1 *arg1, s32 arg2)
{
    register s32 guard;
    MovieMatrix m2;
    MovieSource s2;
    MovieSource s1;
    MovieMatrix m;
    s32 flag;
    s32 half;
    s32 quarter;

    m.x = arg1->width;
    m.y = arg1->offset_x;
    m.z = arg1->step_x;
    m.width = arg1->height;
    m.height = arg1->offset_y;
    m.depth = arg1->step_y;

    s1.object = arg2;
    s1.field_04 = arg1->field_44;

    switch (arg0->format) {
    case 0x11:
    case 0x31:
    case 0x41:
    case 0xF1:
    case 0x1001:
        flag = 0;
        break;
    case 0x21:
    case 0x101:
        flag = 1;
        break;
    default:
        fn_12_309C(0, 0, lbl_12_rodata_60);
        flag = 0;
        break;
    }

    if (flag == 1) {
        s1.field_08 = arg1->field_48 / 2;
    }
    else {
        s1.field_08 = arg1->field_48;
    }

    if (arg0->count == 0) {
        s1.field_0c = arg1->height * 4;
    }
    else {
        s1.field_0c = arg0->count;
    }

    guard = 0;
    (void) guard;  /* fzgx: keeps the web at its definition */
    if (arg1->field_74 == 1) {
        if (guard != 1) {
            fn_12_3D144(&m, &s1);
        }
    }
    else {
        if (guard != 1) {
            fn_12_3D144(&m, &s1);
        }
    }

    half = (arg1->height * arg1->depth) / 2;
    quarter = half;
    quarter /= 2;
    m2.x = arg1->width + half;
    m2.y = arg1->offset_x + quarter;
    m2.z = arg1->step_x + quarter;
    m2.width = arg1->height;
    m2.height = arg1->offset_y;
    m2.depth = arg1->step_y;

    s2.object = arg2;
    s2.field_04 = arg1->field_44;
    s2.field_08 = arg1->field_48 / 2;
    if (!(arg0->count)) {
        s2.field_0c = arg1->height * 4;
    }
    else {
        s2.field_0c = arg0->count;
    }

    if (fn_12_308C() == 1) {
        fn_12_3DCF0(&m2, &s2, arg0->field_38);
    }
    else {
        fn_12_3DF08(&m2, &s2);
    }
}

