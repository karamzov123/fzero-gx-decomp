#include "types.h"


/* --- rel/movie_module/fn_12_39CA4.c --- */
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

/* --- rel/movie_module/fn_12_39E00.c --- */
/* --- rel/movie_module/fn_12_39E00.c --- */
typedef struct Fn12_39E00_Object {
    u32 unk0;
    s32 unk4;
} Fn12_39E00_Object;

extern char lbl_12_rodata_2914[44];
extern s32 fn_12_3412C(Fn12_39E00_Object *object);

s32 fn_12_39E00(Fn12_39E00_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2914);
        return 0;
    } else {
        return fn_12_3412C(object);
    }
}

/* --- rel/movie_module/fn_12_39E54.c --- */
typedef struct Fn12_39E54_Object {
    u32 unk0;
    u32 unk4;
} Fn12_39E54_Object;

extern char lbl_12_rodata_2940[44];
extern void fn_12_34150(void);

void fn_12_39E54(Fn12_39E54_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2940);
    } else {
        fn_12_34150();
    }
}

/* --- rel/movie_module/fn_12_39EA4.c --- */
typedef struct Fn12_39EA4_Object {
    u32 unk0;
    u32 unk4;
} Fn12_39EA4_Object;

extern char lbl_12_rodata_296C[44];
extern s32 fn_12_34174(void);

s32 fn_12_39EA4(Fn12_39EA4_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_296C);
        return 0;
    } else {
        return fn_12_34174();
    }
}

/* --- rel/movie_module/fn_12_39EF8.c --- */
typedef struct Fn12_39EF8_Object {
    u32 unk0;
    s32 unk4;
} Fn12_39EF8_Object;

extern char lbl_12_rodata_2998[44];
extern void fn_12_34198(void);

void fn_12_39EF8(Fn12_39EF8_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2998);
    } else {
        fn_12_34198();
    }
}

/* --- rel/movie_module/fn_12_39F48.c --- */
typedef struct Fn12_39F48_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_39F48_Object;

extern char lbl_12_rodata_29C4[42];
extern s32 fn_12_2E8C8(u32 value, u32 *result, u32 *status);
extern void fn_12_38A0C(s32 error);
extern char lbl_12_rodata_29F0[35];

void fn_12_39F48(Fn12_39F48_Object *object, s32 *result, s32 *status) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }
    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_29C4);
        *result = 0;
        *status = 1;
        return;
    }

    if (fn_12_2E8C8(object->unk40, (u32 *)result, (u32 *)status) != 0) {
        fn_12_38A0C(-0x135);
        MWSFSVM_Error(lbl_12_rodata_29F0);
        *result = 0;
        *status = 1;
    }
    if (*result < 0) {
        *result = 0;
        *status = 1;
    }
}
