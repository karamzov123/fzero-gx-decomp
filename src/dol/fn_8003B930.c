#include "types.h"
#include "psvec_quant.h"


/* --- dol/fn_8003B930.c --- */
typedef struct Fn8003B930Data {
    u8 pad_10[0x10];
    u32 field_10;
    u8 pad_14[0x48];
    u32 field_5c[];
} Fn8003B930Data;

extern int fn_8003D42C();

u8 fn_8003B930(int value, Fn8003B930Data* data) {
    u8* cursor;
    int result;
    int index;
    index = 1;
    result = fn_8003D42C(value);
    cursor = (u8*)data + 4;

    while (result > *(int*)(cursor + 0x14)) {
        result <<= 1;
        result |= fn_8003D42C(value);
        cursor += 4;
        index += 1;
    }
    return *(u8*)((((result) + (data->field_5c[index])) + (data->field_10)));
}

/* --- dol/fn_8003B9AC.c --- */
extern f32 lbl_801A7194;
extern f32 lbl_801A7198;
extern f32 lbl_801A719C;
extern f32 lbl_801A71A0;

void fn_8003B9AC(register void *d, register void *a, register void *b, register void *c, u32 n) {
    register f32 k0 = lbl_801A7194;
    register f32 k1 = lbl_801A7198;
    register f32 k2 = lbl_801A719C;
    register f32 k3 = lbl_801A71A0;
    u32 i;

    for (i = 0; i < n; i += 4) {
        psq2_merge4(d, a, b, c, k0, k1, k2, k3)
    }
}
