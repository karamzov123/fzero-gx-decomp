#include "types.h"

typedef struct Fn12_3A600_Result {
    u8 _pad0[0x04];
    s32 start;
    u8 _pad8[0x08];
    s32 end;
    u8 _pad14[0x2c];
} Fn12_3A600_Result;

typedef struct Fn12_39A68_Result {
    u8 _pad0[4];
    s32 f04;
    u8 _pad8[8];
    s32 f10;
    u8 _pad14[8];
    s32 f1c;
    u8 _pad20[0x20];
} Fn12_39A68_Result;

typedef struct Fn12_39DA0_Result {
    u8 _pad[0x10];
    u32 value;
    u8 _tail[0x2c];
} Fn12_39DA0_Result;

typedef struct Fn12_39E00_Object {
    u32 unk0;
    s32 unk4;
} Fn12_39E00_Object;

typedef struct Fn12_3A384_Object {
    u8 _pad[0x44];
    u32 value;
} Fn12_3A384_Object;

typedef struct Fn12_3A400_Result {
    u8 _pad0[0x28];
    s32 value;
    u8 _pad2c[0x10];
} Fn12_3A400_Result;

typedef struct Fn12_3A4CC_Result {
    u8 _pad0[0x24];
    s32 value;
    u8 _pad28[0x20];
} Fn12_3A4CC_Result;

typedef struct Fn12_39A68_Object {
    u8 _pad0[4];
    s32 unk4;
    u8 _pad8[0x38];
    u32 unk40;
} Fn12_39A68_Object;
extern char lbl_12_rodata_28B0[46];
extern void MWSFSVM_Error(const char *format, ...);
extern char lbl_12_rodata_28E0[52];
extern char lbl_12_rodata_2718[304];
extern int fn_12_2D888();
extern char lbl_12_rodata_287C[52];
extern s32 fn_12_2D58C(u32 arg0, u32 arg1);
extern char lbl_12_rodata_2914[44];
extern s32 fn_12_3412C(Fn12_39E00_Object *object);
extern char lbl_12_rodata_2940[44];
extern void fn_12_34150(void);
extern char lbl_12_rodata_296C[44];
extern s32 fn_12_34174(void);
extern char lbl_12_rodata_2998[44];
extern void fn_12_34198(void);
extern char lbl_12_rodata_29C4[42];
extern s32 fn_12_2E8C8(u32 value, u32 *result, u32 *status);
extern s32 fn_12_38A0C(s32 arg);
extern char lbl_12_rodata_29F0[35];
extern char lbl_12_rodata_2A14[50];
extern char lbl_12_rodata_2A48[49];
extern int fn_12_2A55C(void *arg0, int *arg1);
extern char lbl_12_rodata_2A7C[28];
extern char lbl_12_rodata_2A98[47];
extern u32 fn_12_2D74C(u8 *base, int index, u32 *out);
extern char lbl_12_rodata_2AC8[45];
extern const char lbl_12_rodata_2AF8[47];
extern const char lbl_12_rodata_2B28[38];
extern s32 fn_12_2DA6C(u32 resource);
extern char lbl_12_rodata_2B50[48];
extern void fn_12_34FA8(void *arg);
extern void fn_12_3428C(Fn12_3A384_Object *object, u32 value);
extern char lbl_12_rodata_2B80[48];
extern int fn_12_2D664(u8 *base, u8 *out);
extern char lbl_12_rodata_2BB0[45];
extern char lbl_12_rodata_2BE0[41];
extern int fn_12_2ACA8(void *value);
extern char lbl_12_rodata_2C0C[48];
extern char lbl_12_rodata_2C3C[45];
extern int fn_12_2AD10();
extern char lbl_12_rodata_2C6C[40];
extern char lbl_12_rodata_2C94[47];
extern char lbl_12_rodata_2848[49];
extern u32 fn_12_33874(u32 arg0);
extern char lbl_12_rodata_2CC4[45];
extern char lbl_12_rodata_2CF4[45];

/* fzgx:begin fn_12_39CA4 */
/* --- rel/movie_module/fn_12_39CA4.c --- */
/* --- rel/movie_module/fn_12_39CA4.c --- */
typedef struct MovieObject {
    u8 pad0[4];
    s32 value;
    u8 pad8[0x124];
    u32 result;
} MovieObject;


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
/* fzgx:end fn_12_39CA4 */

/* fzgx:begin fn_12_39CF8 */
/* --- rel/movie_module/fn_12_39CF8.c --- */
typedef struct Fn12_39CF8_Object {
    u8 _pad0[4];
    s32 unk4;
    u8 _pad8[0x38];
    u32 unk40;
} Fn12_39CF8_Object;


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

    return fn_12_2D888( (u8 *)(u32)(resource), 7, mode != 1);
}
/* fzgx:end fn_12_39CF8 */

/* fzgx:begin fn_12_39DA0 */
/* --- rel/movie_module/fn_12_39DA0.c --- */
typedef struct Fn12_39DA0_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    void *unk40;
} Fn12_39DA0_Object;



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
    fn_12_2D58C( (u32)(void *)(object->unk40), (u32)(Fn12_39DA0_Result *)(&result));
    return result.value;
}
/* fzgx:end fn_12_39DA0 */

/* fzgx:begin fn_12_39E00 */
/* --- rel/movie_module/fn_12_39E00.c --- */
/* --- rel/movie_module/fn_12_39E00.c --- */


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
/* fzgx:end fn_12_39E00 */

/* fzgx:begin fn_12_39E54 */
/* --- rel/movie_module/fn_12_39E54.c --- */
typedef struct Fn12_39E54_Object {
    u32 unk0;
    u32 unk4;
} Fn12_39E54_Object;


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
/* fzgx:end fn_12_39E54 */

/* fzgx:begin fn_12_39EA4 */
/* --- rel/movie_module/fn_12_39EA4.c --- */
typedef struct Fn12_39EA4_Object {
    u32 unk0;
    u32 unk4;
} Fn12_39EA4_Object;


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
/* fzgx:end fn_12_39EA4 */

/* fzgx:begin fn_12_39EF8 */
/* --- rel/movie_module/fn_12_39EF8.c --- */
typedef struct Fn12_39EF8_Object {
    u32 unk0;
    s32 unk4;
} Fn12_39EF8_Object;


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
/* fzgx:end fn_12_39EF8 */

/* fzgx:begin fn_12_39F48 */
/* --- rel/movie_module/fn_12_39F48.c --- */
typedef struct Fn12_39F48_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_39F48_Object;


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
/* fzgx:end fn_12_39F48 */

/* fzgx:begin fn_12_3A018 */
typedef struct Fn12_3A018_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_3A018_Object;


u32 fn_12_3A018(Fn12_3A018_Object *object) {
    s32 value;
    u8 local[0x3c];

    if (object == 0) {
        value = 0;
    } else {
        value = object->unk4;
    }
    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2A14);
        return 0;
    }
    fn_12_2D58C(object->unk40, (u32)((u32 *)local));
    return *(u32 *)local;
}
/* fzgx:end fn_12_3A018 */

/* fzgx:begin fn_12_3A078 */
/* --- rel/movie_module/fn_12_3A078.c --- */
/* --- rel/movie_module/fn_12_3A078.c --- */
typedef struct Fn12_3A078_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_3A078_Object;


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

    if (fn_12_2A55C( (void *)(u32)(object->unk40), (int *)(u32 *)(&result)) != 0) {
        MWSFSVM_Error(lbl_12_rodata_2A7C);
    }
    return result;
}
/* fzgx:end fn_12_3A078 */

/* fzgx:begin fn_12_3A0F0 */
/* --- rel/movie_module/fn_12_3A0F0.c --- */
typedef struct Fn12_3A0F0_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_3A0F0_Object;


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

    fn_12_2D74C( (u8 *)(u32)(object->unk40), 15, (u32 *)(s32 *)(&result));
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
/* fzgx:end fn_12_3A0F0 */

/* fzgx:begin fn_12_3A1A4 */
/* --- rel/movie_module/fn_12_3A1A4.c --- */
typedef struct Fn12_3A1A4_Object {
    u8 _pad0[4];
    s32 unk4;
    u8 _pad8[4];
    s32 unkC;
    u8 _pad10[0x30];
    u32 unk40;
} Fn12_3A1A4_Object;


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
        fn_12_2D888( (u8 *)(u32)(resource), 15, 0);
        return;
    }

    if (mode == 1) {
        fn_12_2D888( (u8 *)(u32)(resource), 15, 1);
        return;
    }

    if (mode == 2) {
        if (object->unkC == 1) {
            fn_12_2D888( (u8 *)(u32)(resource), 15, 2);
        } else {
            fn_12_2D888( (u8 *)(u32)(resource), 15, 1);
        }
    }
}
/* fzgx:end fn_12_3A1A4 */

/* fzgx:begin fn_12_3A264 */
/* --- rel/movie_module/fn_12_3A264.c --- */
typedef struct Fn12_3A264_Object {
    u8 _pad0[4];
    s32 unk4;
    s32 unk8;
    u8 _padC[0x34];
    u32 unk40;
} Fn12_3A264_Object;


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
/* fzgx:end fn_12_3A264 */

/* fzgx:begin fn_12_3A300 */
/* --- rel/movie_module/fn_12_3A300.c --- */
/* --- rel/movie_module/fn_12_3A300.c --- */
typedef struct Fn12_3A300_Object {
    u8 _pad0[4];
    u32 unk4;
    u8 _pad8[0x38];
    u32 unk40;
} Fn12_3A300_Object;


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
        fn_12_2D888( (u8 *)(u32)(resource), 54, duration);
    }
}
/* fzgx:end fn_12_3A300 */

/* fzgx:begin fn_12_3A36C */
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
/* fzgx:end fn_12_3A36C */

/* fzgx:begin fn_12_3A384 */
/* --- rel/movie_module/fn_12_3A384.c --- */


void fn_12_3A384(Fn12_3A384_Object *object, u32 value) {
    fn_12_34FA8( (void *)(u32)(object->value));
    fn_12_3428C(object, value);
}
/* fzgx:end fn_12_3A384 */

/* fzgx:begin fn_12_3A3CC */
/* --- rel/movie_module/fn_12_3A3CC.c --- */
typedef struct Fn12_3A3CC_Object {
    u8 _pad[0x40];
    u32 value;
} Fn12_3A3CC_Object;


u32 fn_12_3A3CC(Fn12_3A3CC_Object *object) {
    u32 value;

    if (object != 0) {
        value = object->value;
    } else {
        value = 0;
    }
    return ((u32)fn_12_2D888(value));
}
/* fzgx:end fn_12_3A3CC */

/* fzgx:begin fn_12_3A400 */
/* --- rel/movie_module/fn_12_3A400.c --- */
typedef struct Fn12_3A400_Object {
    u32 _pad0;
    u32 value;
    u8 _pad8[0x38];
    void *data;
} Fn12_3A400_Object;



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
    fn_12_2D664( (u8 *)(void *)(object->data), (u8 *)(Fn12_3A400_Result *)(&result));
    return result.value;
}
/* fzgx:end fn_12_3A400 */

/* fzgx:begin fn_12_3A460 */
/* --- rel/movie_module/fn_12_3A460.c --- */
typedef struct Fn12_3A460_Object {
    u32 unk0;
    s32 unk4;
    u8 _pad[0x38];
    void *unk40;
} Fn12_3A460_Object;


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
/* fzgx:end fn_12_3A460 */

/* fzgx:begin fn_12_3A4CC */
/* --- rel/movie_module/fn_12_3A4CC.c --- */
/* --- rel/movie_module/fn_12_3A4CC.c --- */
typedef struct Fn12_3A4CC_Object {
    u8 _pad0[0x04];
    s32 value;
    u8 _pad8[0x38];
    void *data;
} Fn12_3A4CC_Object;



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

    fn_12_2D664( (u8 *)(void *)(object->data), (u8 *)(Fn12_3A4CC_Result *)(&result));
    return result.value;
}
/* fzgx:end fn_12_3A4CC */

/* fzgx:begin fn_12_3A52C */
/* --- rel/movie_module/fn_12_3A52C.c --- */
typedef struct Fn12_3A52C_Object {
    u8 _pad0[0x04];
    u32 value;
    u8 _pad8[0x38];
    void *movie;
} Fn12_3A52C_Object;


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
/* fzgx:end fn_12_3A52C */

/* fzgx:begin fn_12_3A598 */
/* --- rel/movie_module/fn_12_3A598.c --- */
typedef struct Fn12_3A598_Object {
    u32 unk0;
    u32 unk4;
    u8 _pad[0x38];
    u32 unk40;
} Fn12_3A598_Object;


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
        fn_12_2D888( (u8 *)(u32)(resource), 4, value != 1);
    }
}
/* fzgx:end fn_12_3A598 */

/* fzgx:begin fn_12_3A600 */
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_3A600.c --- */
typedef struct Fn12_3A600_Object {
    u8 _pad0[0x04];
    s32 value;
    u8 _pad8[0x38];
    void *data;
} Fn12_3A600_Object;



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

    fn_12_2D58C( (u32)(void *)(data), (u32)(Fn12_3A600_Result *)(&result));
    return result.start - result.end;
}
/* fzgx:end fn_12_3A600 */

/* fzgx:begin fn_12_3A69C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_3A69C.c --- */
typedef struct Fn12_39A68_Object {
    u8 _pad0[4];
    s32 unk4;
    u8 _pad8[0x38];
    u32 unk40;
} Fn12_39A68_Object;

typedef struct Fn12_39A68_Result {
    u8 _pad0[4];
    s32 f04;
    u8 _pad8[8];
    s32 f10;
    u8 _pad14[8];
    s32 f1c;
    u8 _pad20[0x20];
} Fn12_39A68_Result;

static const char lbl_12_rodata_2718[212] = { 69, 49, 49, 50, 50, 54, 52, 48, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 83, 102, 100, 72, 110, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 69, 50, 48, 57, 51, 48, 48, 49, 32, 109, 119, 80, 108, 121, 65, 116, 116, 97, 99, 104, 77, 50, 118, 58, 32, 119, 111, 114, 107, 115, 105, 122, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 0, 0, 69, 50, 49, 49, 48, 53, 49, 58, 32, 109, 119, 80, 108, 121, 83, 101, 116, 70, 108, 111, 97, 116, 83, 112, 101, 101, 100, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 0, 0, 0, 0, 63, -32, 0, 0, 0, 0, 0, 0, 68, 122, 0, 0, 0, 0, 0, 0, 67, 48, 0, 0, -128, 0, 0, 0, 69, 51, 48, 50, 50, 53, 49, 58, 32, 109, 119, 80, 108, 121, 83, 101, 116, 83, 112, 101, 101, 100, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 0 };
static const char lbl_12_rodata_2718__fzgx_offset_D4[44] = { 69, 50, 48, 50, 49, 57, 49, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 80, 108, 121, 73, 110, 102, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0 };
static const char lbl_12_rodata_2718__fzgx_offset_100[48] = { 69, 50, 48, 50, 50, 51, 50, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 78, 117, 109, 68, 114, 111, 112, 70, 114, 109, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0 };
static const char lbl_12_rodata_2848[49] = { 69, 49, 49, 50, 50, 54, 49, 57, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 78, 117, 109, 83, 107, 105, 112, 68, 101, 99, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0 };
extern void MWSFSVM_Error(const char *format, ...);
extern void fn_12_2D58C(void *data, Fn12_39A68_Result *result);
extern u32 fn_12_33874(Fn12_39A68_Object *object);

static inline s32 ply_is_valid(Fn12_39A68_Object *object) {
    if (object == 0) return 0;
    return object->unk4;
}

static inline void *ply_get_stream(Fn12_39A68_Object *object) {
    if (!ply_is_valid(object)) {
        MWSFSVM_Error(lbl_12_rodata_2718);
        return 0;
    }
    return (void *)object->unk40;
}

static inline s32 ply_get_skip_dec(Fn12_39A68_Object *object) {
    Fn12_39A68_Result result;
    if (!ply_is_valid(object)) {
        MWSFSVM_Error(lbl_12_rodata_2848);
        return 0;
    }
    fn_12_2D58C(ply_get_stream(object), &result);
    return result.f04 - result.f10;
}

s32 fn_12_3A69C(Fn12_39A68_Object *object) {
    s32 skipped;
    if (!ply_is_valid(object)) {
        MWSFSVM_Error(lbl_12_rodata_2718__fzgx_offset_100);
        return 0;
    }
    skipped = ply_get_skip_dec(object);
    return skipped + fn_12_33874(object);
}
/* fzgx:end fn_12_3A69C */

/* fzgx:begin fn_12_3A784 noprologue */
/* --- rel/movie_module/fn_12_3A784.c --- */
typedef struct Fn12_3A784_Object {
    u8 _pad0[0x4];
    s32 value;
    u8 _pad8[0x40];
    u32 result;
} Fn12_3A784_Object;

extern char lbl_12_rodata_2CC4[45];

u32 fn_12_3A784(Fn12_3A784_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }

    if (value == 0) {
        MWSFSVM_Error(lbl_12_rodata_2CC4);
        return 0;
    }

    return object->result;
}
/* fzgx:end fn_12_3A784 */

/* fzgx:begin fn_12_3A7D8 */
/* --- rel/movie_module/fn_12_3A7D8.c --- */
/* --- rel/movie_module/fn_12_3A7D8.c --- */
typedef struct Fn12_3A7D8_Object {
    u32 _pad0;
    s32 value;
    u8 _pad8[0x38];
    void *result;
} Fn12_3A7D8_Object;


void *fn_12_3A7D8(Fn12_3A7D8_Object *object) {
    s32 value;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }
    if (value == 0) {
        MWSFSVM_Error((const char *)((u8 *)&lbl_12_rodata_2718));
        return 0;
    }
    return object->result;
}
/* fzgx:end fn_12_3A7D8 */

/* fzgx:begin fn_12_3A82C */
/* --- rel/movie_module/fn_12_3A82C.c --- */
typedef struct Fn12_3A82C_Object {
    u8 _pad0[4];
    s32 value;
    u8 _pad1[0x38];
    void *target;
} Fn12_3A82C_Object;


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
        fn_12_2D888( (u8 *)(void *)(object->target), 6, (int)(void *)(argument));
    }
}
/* fzgx:end fn_12_3A82C */
