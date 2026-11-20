#include "types.h"


/* --- rel/movie_module/fn_12_3A7D8.c --- */
typedef struct Fn12_3A7D8_Object {
    u32 _pad0;
    s32 value;
    u8 _pad8[0x38];
    void *result;
} Fn12_3A7D8_Object;

extern u8 lbl_12_rodata_2718[304];
extern void MWSFSVM_Error(const char *, ...);

void *fn_12_3A7D8(Fn12_3A7D8_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }
    if (value == 0) {
        MWSFSVM_Error((const char *)&lbl_12_rodata_2718);
        return 0;
    }
    return object->result;
}

/* --- rel/movie_module/fn_12_3A82C.c --- */
typedef struct Fn12_3A82C_Object {
    u8 _pad0[4];
    s32 value;
    u8 _pad1[0x38];
    void *target;
} Fn12_3A82C_Object;

extern char lbl_12_rodata_2CF4[45];
extern void fn_12_2D888(void *target, s32 value, void *argument);

void fn_12_3A82C(Fn12_3A82C_Object *object, void *argument) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }
    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2CF4);
    } else {
        fn_12_2D888(object->target, 6, argument);
    }
}
