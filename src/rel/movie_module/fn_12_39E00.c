#include "types.h"


/* --- rel/movie_module/fn_12_39E00.c --- */
typedef struct Fn12_39E00_Object {
    u32 unk0;
    s32 unk4;
} Fn12_39E00_Object;

extern char lbl_12_rodata_2914[44];
extern void MWSFSVM_Error(char *message, ...);
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
extern void MWSFSVM_Error(char *, ...);
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
