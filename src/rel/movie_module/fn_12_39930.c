#include "types.h"


/* --- rel/movie_module/fn_12_39930.c --- */
extern s32 fn_12_3A36C(void *object);
extern char lbl_12_rodata_2670[46];
extern void MWSFSVM_Error(const char *format, ...);
extern char lbl_12_rodata_26A0[41];
extern void fn_12_39678(void *object, void *argument, s32 arg2, s32 arg3);

void fn_12_39930(void *object, void *argument) {
    if (fn_12_3A36C(object) == 0) {
        MWSFSVM_Error(lbl_12_rodata_2670);
    } else if (argument == 0) {
        MWSFSVM_Error(lbl_12_rodata_26A0);
    } else {
        fn_12_39678(object, argument, 0, -1);
    }
}

/* --- rel/movie_module/fn_12_399B4.c --- */
typedef struct Fn12_399B4_Object {
    u8 _pad[0x40];
    u32 value;
} Fn12_399B4_Object;

extern s32 fn_12_2B138(u32 value);
extern char lbl_12_rodata_26CC[46];

s32 fn_12_399B4(Fn12_399B4_Object *object) {
    s32 result = fn_12_2B138(object->value);

    switch (result) {
    case 1:
        return 1;
    case 0:
        return 0;
    default:
        MWSFSVM_Error(lbl_12_rodata_26CC, result);
        return 0;
    }
}

/* --- rel/movie_module/fn_12_39A18.c --- */
typedef struct Fn12_39A18_Object {
    u8 unk0[0x40];
    u32 unk40;
} Fn12_39A18_Object;

extern s32 fn_12_2B634(u32 value);
extern void fn_12_38A0C(s32 value);
extern const char lbl_12_rodata_26FC[27];

s32 fn_12_39A18(Fn12_39A18_Object *object) {
    if (fn_12_2B634(object->unk40) != 0) {
        fn_12_38A0C(-0x133);
        MWSFSVM_Error(lbl_12_rodata_26FC);
        return -0x133;
    }
    return 0;
}
