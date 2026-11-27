#include "types.h"

/* --- rel/movie_module/fn_12_3A4CC.c --- */
/* --- rel/movie_module/fn_12_3A4CC.c --- */
typedef struct Fn12_3A4CC_Object {
    u8 _pad0[0x04];
    s32 value;
    u8 _pad8[0x38];
    void *data;
} Fn12_3A4CC_Object;

typedef struct Fn12_3A4CC_Result {
    u8 _pad0[0x24];
    s32 value;
    u8 _pad28[0x20];
} Fn12_3A4CC_Result;

extern char lbl_12_rodata_2C0C[48];
extern void MWSFSVM_Error(const char *format, ...);
extern void fn_12_2D664(void *data, Fn12_3A4CC_Result *result);

s32 fn_12_3A4CC(Fn12_3A4CC_Object *object) {
    s32 value;
    Fn12_3A4CC_Result result;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2C0C);
        return -1;
    }

    fn_12_2D664(object->data, &result);
    return result.value;
}

/* --- rel/movie_module/fn_12_3A52C.c --- */
typedef struct Fn12_3A52C_Object {
    u8 _pad0[0x04];
    u32 value;
    u8 _pad8[0x38];
    void *movie;
} Fn12_3A52C_Object;

extern char lbl_12_rodata_2C3C[45];
extern int fn_12_2AD10(void *movie);
extern char lbl_12_rodata_2C6C[40];

void fn_12_3A52C(Fn12_3A52C_Object *object) {
    int value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2C3C);
    } else if (fn_12_2AD10(object->movie) != 0) {
        MWSFSVM_Error(lbl_12_rodata_2C6C);
    }
}

/* --- rel/movie_module/fn_12_3A598.c --- */
typedef struct Fn12_3A598_Object {
    u32 unk0;
    u32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_3A598_Object;

extern char lbl_12_rodata_2C94[47];
extern void fn_12_2D888(u32 value, u32 arg, u32 flag);

#pragma opt_propagation off
void fn_12_3A598(Fn12_3A598_Object *object, s32 value) {
    int status;
    u32 resource;

    if (object == 0) {
        status = 0;
    } else {
        status = object->unk4;
    }
    if (status == 0) {
        MWSFSVM_Error(lbl_12_rodata_2C94);
    } else {
        resource = object->unk40;
        fn_12_2D888(resource, 4, value != 1);
    }
}
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_3A600.c --- */
typedef struct Fn12_3A600_Object {
    u8 _pad0[0x04];
    s32 value;
    u8 _pad8[0x38];
    void *data;
} Fn12_3A600_Object;

typedef struct Fn12_3A600_Result {
    u8 _pad0[0x04];
    s32 start;
    u8 _pad8[0x08];
    s32 end;
    u8 _pad14[0x2c];
} Fn12_3A600_Result;

extern char lbl_12_rodata_2848[49];
extern char lbl_12_rodata_2718[304];
extern void fn_12_2D58C(void *data, Fn12_3A600_Result *result);

s32 fn_12_3A600(Fn12_3A600_Object *object) {
    s32 value;
    Fn12_3A600_Result result;
    void *data;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2848);
        return 0;
    }

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2718);
        data = 0;
    } else {
        data = object->data;
    }

    fn_12_2D58C(data, &result);
    return result.start - result.end;
}
