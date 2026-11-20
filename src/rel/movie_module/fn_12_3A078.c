#include "types.h"


/* --- rel/movie_module/fn_12_3A078.c --- */
typedef struct Fn12_3A078_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_3A078_Object;

extern char lbl_12_rodata_2A48[49];
extern void MWSFSVM_Error(const char *fmt, ...);
extern s32 fn_12_2A55C(u32 value, u32 *result);
extern char lbl_12_rodata_2A7C[28];

u32 fn_12_3A078(Fn12_3A078_Object *object) {
    s32 value;
    u32 result;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }
    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2A48);
        return 0;
    }

    if (fn_12_2A55C(object->unk40, &result) != 0) {
        MWSFSVM_Error(lbl_12_rodata_2A7C);
    }
    return result;
}

/* --- rel/movie_module/fn_12_3A0F0.c --- */
typedef struct Fn12_3A0F0_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_3A0F0_Object;

extern char lbl_12_rodata_2A98[47];
extern void MWSFSVM_Error(const char *message, ...);
extern void fn_12_2D74C(u32 value, u32 type, s32 *result);
extern char lbl_12_rodata_2AC8[45];

s32 fn_12_3A0F0(Fn12_3A0F0_Object *object) {
    s32 value;
    s32 result;

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }
    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2A98);
        return -1;
    }

    fn_12_2D74C(object->unk40, 15, &result);
    switch (result) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        MWSFSVM_Error(lbl_12_rodata_2AC8);
        return -1;
    }
}

/* --- rel/movie_module/fn_12_3A1A4.c --- */
typedef struct Fn12_3A1A4_Object {
    u8 _pad0[4];
    s32 unk4;
    u8 _pad8[4];
    s32 unkC;
    u8 _pad10[0x30];
    u32 unk40;
} Fn12_3A1A4_Object;

extern const char lbl_12_rodata_2AF8[47];
extern void fn_12_2D888(u32 resource, s32 value, s32 mode);

void fn_12_3A1A4(Fn12_3A1A4_Object *object, s32 mode) {
    s32 state;
    u32 resource;

    if (object == 0) {
        state = 0;
    } else {
        state = object->unk4;
    }

    if (state == 0) {
        MWSFSVM_Error(lbl_12_rodata_2AF8);
        return;
    }

    resource = object->unk40;
    if (mode == 0) {
        fn_12_2D888(resource, 15, 0);
        return;
    }

    if (mode == 1) {
        fn_12_2D888(resource, 15, 1);
        return;
    }

    if (mode == 2) {
        if (object->unkC == 1) {
            fn_12_2D888(resource, 15, 2);
        } else {
            fn_12_2D888(resource, 15, 1);
        }
    }
}

/* --- rel/movie_module/fn_12_3A264.c --- */
typedef struct Fn12_3A264_Object {
    u8 _pad0[4];
    s32 unk4;
    s32 unk8;
    u8 _padC[0x34];
    u32 unk40;
} Fn12_3A264_Object;

extern const char lbl_12_rodata_2B28[38];
extern void fn_12_38A0C(s32 value);
extern s32 fn_12_2DA6C(u32 resource);

s32 fn_12_3A264(Fn12_3A264_Object *object) {
    s32 state;

    if (object == 0) {
        state = 0;
    } else {
        state = object->unk4;
    }

    if (state == 0) {
        fn_12_38A0C(-12);
        MWSFSVM_Error(lbl_12_rodata_2B28);
        return 0;
    }

    if (object->unk8 == 2) {
        state = fn_12_2DA6C(object->unk40);
        if (state == 4 || state == 6) {
            return 2;
        }
        if (state < 0) {
            return 4;
        }
        return 1;
    }

    return object->unk8;
}
