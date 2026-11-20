#include "types.h"


/* --- rel/movie_module/fn_12_670C.c --- */
s32 fn_12_670C(const u8 *data) {
    s32 value = (data[0] << 8) | data[1];

    value <<= 8;
    value |= data[2];
    value <<= 8;
    value |= data[3];

    switch (value - 0x1b9) {
    case 1:
        return 0x10000;
    case 2:
        return 0x20000;
    case 0:
        return 0x80000;
    case 4:
        return 0x40000;
    case 6:
        return 0x40000;
    case 5:
        return 0x40000;
    default:
        if (value >= 0x1c0 && value <= 0x1ef)
            return 0x40000;
        return 0;
    }
}

u32 fn_12_67A4(const u8 *data) {
    s32 value = (data[0] << 8) | data[1];

    value <<= 8;
    value |= data[2];
    value <<= 8;
    value |= data[3];

    switch (value) {
    case 0x1ba:
        return 0x10000;
    case 0x1bb:
        return 0x20000;
    case 0x1b9:
        return 0x80000;
    case 0x1bd:
        return 0x40000;
    case 0x1bf:
        return 0x40000;
    case 0x1be:
        return 0x40000;
    default:
        if (value >= 0x1c0 && value <= 0x1ef)
            return 0x40000;
        return 0;
    }
}

/* --- rel/movie_module/fn_12_683C.c --- */
typedef struct MovieValues {
    u32 value_00;
    u32 value_04;
    u32 value_08;
    u32 value_0c;
    u32 value_10;
    u32 value_14;
    u32 value_18;
    u32 value_1c;
} MovieValues;

typedef struct MovieModule {
    u8 _pad00[0xa0];
    MovieValues values;
} MovieModule;

extern int fn_12_6C78(MovieModule *);
extern int fn_12_6D5C(int, int);

int fn_12_683C(MovieModule *module, MovieValues *result) {
    if (fn_12_6C78(module)) {
        return fn_12_6D5C(0, 0xff020203);
    }
    *result = module->values;
    return 0;
}
