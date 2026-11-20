#include "types.h"


/* --- rel/movie_module/fn_12_3A300.c --- */
typedef struct Fn12_3A300_Object {
    u8 _pad0[4];
    u32 unk4;
    u8 _pad8[0x38];
    u32 unk40;
} Fn12_3A300_Object;

extern char lbl_12_rodata_2B50[48];
extern void MWSFSVM_Error(char *message, ...);
extern void fn_12_2D888(u32 value, u32 type, u32 duration);

void fn_12_3A300(Fn12_3A300_Object *object, u32 value) {
    int state;
    u32 duration;
    u32 resource;

    if (object == 0) {
        state = 0;
    } else {
        state = object->unk4;
    }

    if (state == 0) {
        MWSFSVM_Error(lbl_12_rodata_2B50);
    } else {
        duration = value * 1000;
        if (object) {
            resource = object->unk40;
        } else {
            resource = 0;
        }
        fn_12_2D888(resource, 54, duration);
    }
}

/* --- rel/movie_module/fn_12_3A36C.c --- */
typedef struct Fn12_3A36C_Object {
    u32 unk0;
    u32 unk4;
} Fn12_3A36C_Object;

u32 fn_12_3A36C(Fn12_3A36C_Object *object) {
    if (object == 0) {
        return 0;
    }
    return object->unk4;
}

/* --- rel/movie_module/fn_12_3A384.c --- */
typedef struct Fn12_3A384_Object {
    u8 _pad[0x44];
    u32 value;
} Fn12_3A384_Object;

extern void fn_12_34FA8(u32 value);
extern void fn_12_3428C(Fn12_3A384_Object *object, u32 value);

void fn_12_3A384(Fn12_3A384_Object *object, u32 value) {
    fn_12_34FA8(object->value);
    fn_12_3428C(object, value);
}
