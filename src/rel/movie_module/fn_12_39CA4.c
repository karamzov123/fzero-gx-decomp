#include "types.h"


/* --- rel/movie_module/fn_12_39CA4.c --- */
typedef struct MovieObject {
    u8 pad0[4];
    s32 value;
    u8 pad8[0x124];
    u32 result;
} MovieObject;

extern char lbl_12_rodata_28B0[46];
extern void MWSFSVM_Error(const char *message, ...);

s32 fn_12_39CA4(MovieObject *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_28B0);
        return 0;
    }

    return object->result;
}

/* --- rel/movie_module/fn_12_39CF8.c --- */
typedef struct Fn12_39CF8_Object {
    u8 _pad0[4];
    s32 unk4;
    u8 _pad8[0x38];
    u32 unk40;
} Fn12_39CF8_Object;

extern char lbl_12_rodata_28E0[52];
extern char lbl_12_rodata_2718[304];
extern s32 fn_12_2D888(u32 resource, s32 arg, s32 flag);

s32 fn_12_39CF8(Fn12_39CF8_Object *object, s32 mode) {
    s32 state;
    u32 resource;

    if (object == 0) {
        state = 0;
    } else {
        state = object->unk4;
    }

    if (state == 0) {
        MWSFSVM_Error(lbl_12_rodata_28E0);
        return;
    }

    if (object == 0) {
        state = 0;
    } else {
        state = object->unk4;
    }

    if (state == 0) {
        MWSFSVM_Error(lbl_12_rodata_2718);
        resource = 0;
    } else {
        resource = object->unk40;
    }

    return fn_12_2D888(resource, 7, mode != 1);
}

/* --- rel/movie_module/fn_12_39DA0.c --- */
typedef struct Fn12_39DA0_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    void *unk40;
} Fn12_39DA0_Object;

typedef struct Fn12_39DA0_Result {
    u8 _pad[0x10];
    u32 value;
    u8 _tail[0x2c];
} Fn12_39DA0_Result;

extern char lbl_12_rodata_287C[52];
extern void MWSFSVM_Error(const char *format, ...);
extern void fn_12_2D58C(void *object, Fn12_39DA0_Result *result);

u32 fn_12_39DA0(Fn12_39DA0_Object *object) {
    s32 valid;
    Fn12_39DA0_Result result;

    if (object == 0) {
        valid = 0;
    } else {
        valid = object->unk4;
    }
    if (valid == 0) {
        MWSFSVM_Error(lbl_12_rodata_287C);
        return 0;
    }
    fn_12_2D58C(object->unk40, &result);
    return result.value;
}
