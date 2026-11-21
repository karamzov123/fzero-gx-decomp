#include "types.h"


/* --- dol/fn_80057D0C.c --- */
/* --- dol/fn_80057D0C.c --- */
struct fn_80057D0C_lbl_8018AE18 {
    u32 unk_0;
};

extern struct fn_80057D0C_lbl_8018AE18 lbl_8018AE18[];
extern u32 lbl_8018AE1C[];
extern u32 memset(u32, u32, u32);

u32 fn_80057D0C(u32 arg0, u32 arg1);

/* --- dol/fn_80057D60.c --- */
extern u32 fn_80058A20(u32);
extern u32 lbl_800922F0[];

void fn_80057D60(void);

/* --- dol/fn_80057D88.c --- */
u32 fn_80057D88(u32 arg0, u32 arg1, u32 arg2) {
    u8 *ptr = (u8 *)arg0 + (arg1 << 3);
    ptr += arg2 << 2;
    return *(u32 *)(ptr + 0x28);
}

/* --- dol/fn_80057DA0.c --- */
/* --- dol/fn_80057DA0.c --- */
struct fn_80057DA0_Arg0 {
    u8 pad_0[0x24];
    u32 unk_24;
};

u32 fn_80057DA0(struct fn_80057DA0_Arg0 *arg0) {
    return arg0->unk_24;
}

/* --- dol/fn_80057DA8.c --- */
struct fn_80057DA8_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

u32 fn_80057DA8(struct fn_80057DA8_Arg0 *arg0) {
    return arg0->unk_20;
}

/* --- dol/fn_80057DB0.c --- */
struct fn_80057DB0_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};

u32 fn_80057DB0(struct fn_80057DB0_Arg0 *arg0) {
    return arg0->unk_1C;
}

/* --- dol/fn_80057DB8.c --- */
typedef struct Fn80057DB8Object Fn80057DB8Object;
typedef void (*Fn80057DB8Callback)(void *, int);

struct Fn80057DB8Object {
    u8 pad_0x00[0x0c];
    int value_0c;
    int value_10;
    int value_14;
    int value_18;
    u8 pad_0x1c[0x04];
    int value_20;
    int value_24;
    u8 pad_0x28[0x10];
    Fn80057DB8Callback callback_38;
    void *callback_arg_3c;
};

extern void fn_80057728(Fn80057DB8Object *, int, int, int *);
extern void fn_800576DC(void);

int fn_80057DB8(Fn80057DB8Object *object, int mode, int limit, int *result) {
    int value;
    int clamped;

    fn_80057728(object, mode, limit, result);
    if (mode == 0) {
        value = object->value_24;
        value += object->value_20 - object->value_14;
        if (object->value_10 < value) {
            value = object->value_10;
        }
        clamped = limit;
        if (value < limit) {
            clamped = value;
        }
        mode = clamped;
    } else if (mode == 1) {
        value = object->value_24;
        value += object->value_20 - object->value_18;
        if (object->value_0c < value) {
            value = object->value_0c;
        }
        clamped = limit;
        if (value < limit) {
            clamped = value;
        }
        mode = clamped;
    } else {
        mode = 0;
        if (object->callback_38 != 0) {
            object->callback_38(object->callback_arg_3c, -3);
        }
    }
    *result = mode;
    fn_800576DC();
    return !(limit - mode);
}
