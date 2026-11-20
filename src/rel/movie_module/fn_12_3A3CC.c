#include "types.h"


/* --- rel/movie_module/fn_12_3A3CC.c --- */
typedef struct Fn12_3A3CC_Object {
    u8 _pad[0x40];
    u32 value;
} Fn12_3A3CC_Object;

extern u32 fn_12_2D888(u32 value);

u32 fn_12_3A3CC(Fn12_3A3CC_Object *object) {
    u32 value;

    if (object != 0) {
        value = object->value;
    } else {
        value = 0;
    }
    return fn_12_2D888(value);
}

/* --- rel/movie_module/fn_12_3A400.c --- */
typedef struct Fn12_3A400_Object {
    u32 _pad0;
    u32 value;
    u8 _pad8[0x38];
    void *data;
} Fn12_3A400_Object;

typedef struct Fn12_3A400_Result {
    u8 _pad0[0x28];
    s32 value;
    u8 _pad2c[0x10];
} Fn12_3A400_Result;

extern char lbl_12_rodata_2B80[48];
extern void MWSFSVM_Error(char *message, ...);
extern void fn_12_2D664(void *data, Fn12_3A400_Result *result);

s32 fn_12_3A400(Fn12_3A400_Object *object) {
    Fn12_3A400_Result result;
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }
    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2B80);
        return -1;
    }
    fn_12_2D664(object->data, &result);
    return result.value;
}

/* --- rel/movie_module/fn_12_3A460.c --- */
typedef struct Fn12_3A460_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    void *unk40;
} Fn12_3A460_Object;

extern char lbl_12_rodata_2BB0[45];
extern char lbl_12_rodata_2BE0[41];
extern int fn_12_2ACA8(void *value);

void fn_12_3A460(Fn12_3A460_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2BB0);
    } else if (fn_12_2ACA8(object->unk40) != 0) {
        MWSFSVM_Error(lbl_12_rodata_2BE0);
    }
}
