/* Retained Japan/PAL compiler inputs pending a verified whole-TU regional build. */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void fn_80072558(void);
extern void fn_800720B0(int);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern u8 *lbl_801A66CC;
extern void lbl_8006E1B0();
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);

/* fzgx:begin fn_1_54DCC */
void fn_1_54DCC(u8 *data) {
    fn_800794F0(data, lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_54DCC */

/* fzgx:begin fn_1_54E00 */
void fn_1_54E00(void *value) {
    fn_800794F0(lbl_801A66CC + 0x50, value, 0x84);
}
/* fzgx:end fn_1_54E00 */

/* fzgx:begin fn_1_54E34 */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
} Fn154E34Data;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vector;



s32 fn_1_54E34(void *arg0, f32 arg1) {
    Vector vector;
    Fn154E34Data *data;
    f32 *p;
    f32 x;
    f32 y;
    f32 z;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    lbl_8006E1B0(arg0, &vector, arg1);
    z = vector.z;
    x = vector.x;
    y = vector.y;
    if (z > arg1) {
        return 0;
    }
    arg1 = -arg1;
    data = (Fn154E34Data *)(*(void * *)&lbl_801A66CC);
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = x * p[0];
        m1 = y * p[1];
        m2 = z * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54E34 */

/* fzgx:begin fn_1_54F5C */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
    u8 pad_bc[0x18];
    f32 value_d4;
    f32 value_d8;
    f32 value_dc;
} Fn154F5CData;



s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2) {
    Fn154F5CData *data;
    f32 *p;
    f32 d4;
    f32 d8;
    f32 dc;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    lbl_8006E1B0(arg0, (Vec3 *)(&data->value_d4));
    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    arg1 = arg1 * arg2;
    dc = data->value_dc;
    if (dc > arg1) {
        return 0;
    }
    d4 = data->value_d4;
    d8 = data->value_d8;
    arg1 = -arg1;
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = d4 * p[0];
        m1 = d8 * p[1];
        m2 = dc * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54F5C */

/* fzgx:begin fn_1_550A8 */
void fn_1_550A8(void) {
    fn_800794F0(lbl_1_bss_6C710, lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_550A8 */

/* fzgx:begin fn_1_550E0 */
void fn_1_550E0(void) {
    fn_800794F0(lbl_801A66CC + 0x50, lbl_1_bss_6C710, 0x84);
}
/* fzgx:end fn_1_550E0 */

/* fzgx:begin fn_1_55118 */
extern u32 lbl_801A6410;
extern const f32 lbl_1_rodata_28A8;
extern void fn_800777D4(void);
extern void fn_1_565F8(void);
extern void fn_80072808(void);
extern void fn_1_56664(void *);
extern void fn_1_566A0(void *);
extern u32 fn_80070DE0(u32);
extern u32 fn_80070DF0(u32);
extern void *memset(void *, int, u32);
extern void fn_1_566EC(int, int);
extern void fn_800749B0(s32, void *);

typedef struct {
    u8 color[4];
    u8 shadow[4];
    f32 scale;
    u8 flags[6];
    u8 pad[0x16];
} InitSettings;
typedef struct {
    u32 initial;
    u32 count;
    f32 scale;
    InitSettings settings;
    u32 last;
} InitState;

static inline void init_settings(InitSettings *settings) {
    memset(settings, 0, 0x28);
    settings->color[0] = 255;
    settings->color[1] = 255;
    settings->color[2] = 255;
    settings->color[3] = 255;
    settings->shadow[0] = 0;
    settings->shadow[1] = 0;
    settings->shadow[2] = 0;
    settings->shadow[3] = 0;
    settings->scale = lbl_1_rodata_28A8;
    settings->flags[0] = 1;
    settings->flags[1] = 3;
    settings->flags[2] = 1;
    settings->flags[3] = 0;
    settings->flags[4] = 0;
    settings->flags[5] = 0;
}

typedef struct lbl_1_bss_6C7CC_t {
    u32 last;
    u8 pad_4[0xc];
} lbl_1_bss_6C7CC_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_6C798;
u32 lbl_1_bss_6C79C;
f32 fzgx_obj_lbl_1_bss_6C7A0;
InitSettings fzgx_obj_lbl_1_bss_6C7A4;
lbl_1_bss_6C7CC_t fzgx_obj_lbl_1_bss_6C7CC;
u8 lbl_1_bss_6C7DC[100];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6C798;
    s = *(u8 *)&lbl_1_bss_6C79C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7CC;
    s = *(u8 *)&lbl_1_bss_6C7DC;
}
#pragma section code_type ".text"

void fn_1_55118(void) {
    
    InitSettings *settings;
    lbl_1_bss_6C798 = lbl_801A6410;
    fn_800777D4();
    fn_1_565F8();
    fn_80072808();
    fn_80070DE0((u32)fn_1_56664);
    fn_80070DF0((u32)fn_1_566A0);
    lbl_1_bss_6C79C = 0x60;
    fzgx_obj_lbl_1_bss_6C7A0 = lbl_1_rodata_28A8;
    init_settings(&fzgx_obj_lbl_1_bss_6C7A4);
    fn_1_566EC(0, 0);
    fn_800749B0(0, 0);
    fzgx_obj_lbl_1_bss_6C7CC.last = 0;
}
/* fzgx:end fn_1_55118 */

/* fzgx:begin fn_1_55210 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_5448C(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_557C4(void *value);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_55210_Object;

void fn_1_55210(void *value) {
    s32 offset;
    Fn1_55210_Object *obj;
    void *result;
    s32 ok;
    s32 i;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if ((0) != (*(u16 *)((u8 *)value + 0x1a))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_5448C((u8 *)value + 8);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (((obj->entry)[i]) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + offset) + (((0xe0)))))), ((obj->entry)[i]));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_557C4(value);
    }
}
/* fzgx:end fn_1_55210 */

/* fzgx:begin fn_1_553C4 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_54448(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_55924(void *value, void *arg);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_553C4_Object;

void fn_1_553C4(void *value, void *arg) {
    s32 offset;
    Fn1_553C4_Object *obj;
    void *result;
    s32 ok;
    s32 i;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if (((0) != (*(u16 *)((u8 *)value + 0x1a)))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_54448(arg);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (((obj->entry)[i]) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + offset) + (((0xe0)))))), ((obj->entry)[i]));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_55924(value, arg);
    }
}
/* fzgx:end fn_1_553C4 */

/* fzgx:begin fn_1_5557C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5557CObject;

void fn_1_5557C(Fn1_5557CObject *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5557C */

/* fzgx:begin fn_1_555D0 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_555D0Object;

void fn_1_555D0(Fn1_555D0Object *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_555D0 */

/* fzgx:begin fn_1_55628 */
typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Fn1_55628Object;

void fn_1_55628(Fn1_55628Object *value) {
    if (value->unk_1C != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        fn_1_557C4(value);
    } else {
        fn_1_556B8(value);
    }
}
/* fzgx:end fn_1_55628 */

/* fzgx:begin fn_1_55678 */
void fn_1_55678(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
    fn_80077E7C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_55678 */

/* fzgx:begin fn_1_556B8 */
/* Completes the font operation for the supplied value. */
void fn_1_556B8(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
    fn_80077F8C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_556B8 */

/* fzgx:begin fn_1_556F8 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_556F8Object;

/* Finishes the current font operation after testing its scale threshold. */
void fn_1_556F8(Fn1_556F8Object *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_556F8 */

/* fzgx:begin fn_1_5575C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5575CObject;

void fn_1_5575C(Fn1_5575CObject *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5575C */

/* fzgx:begin fn_1_557C4 */
typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1C;
    u32 w20;
    u32 w24;
} Words28;

typedef struct {
    u8 pad_00[4];
    u32 unk_04;
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *unk_68[4];
} Fn1_557C4Object;

void fn_1_557C4(void *value) {
    s32 offset;
    Fn1_557C4Object *object;
    void *resource;
    s32 valid;
    s32 i;
    Obj_1_bss_6C7CC *bits;

    resource = (void *)fn_1_5448C((u8 *)value + 8);
    object = fn_1_548AC(0x78);
    if (object != 0) {
        valid = 1;
        object->unk_04 = (u32)fn_1_55C48;
        object->unk_08 = value;
        lbl_8006DB74(((0xC) + ((u8 *)object)));
        object->unk_3C = fn_1_7BE94();
        object->unk_40 = lbl_1_bss_6C7A4;
        bits = &lbl_1_bss_6C7CC;
        for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
            if ((__rlwnm(bits->unk_0, ((i + 1) & 0x1f), 31, 31) != 0)) {
                object->unk_68[i] = fn_1_548AC(0x30);
                if ((*((object->unk_68) + i)) != 0) {
                    lbl_8006DD14(lbl_801A66CC + offset + 0xE0, (*((object->unk_68) + i)));
                } else {
                    valid = 0;
                }
            } else {
                object->unk_68[i] = 0;
            }
        }
        if (valid != 0) {
            fn_1_5489C( (void **)(resource), (void **)(object));
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_557C4 */

/* fzgx:begin fn_1_55924 */
typedef struct {
    u8 pad_00[0x4];
    void *vtable;
    void *owner;
    u8 pad_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[0x2];
    Obj_1_bss_6C7A4 settings;
    void *items[4];
} Fn1_55924Object;

void fn_1_55924(void *value, void *arg) {
    Fn1_55924Object *object;
    void *handle;
    s32 ok;
    s32 i;
    Obj_1_bss_6C7CC *flags;

    handle = fn_1_54448( (s32)(arg));
    object = (Fn1_55924Object *)fn_1_548AC(0x78);
    if (object != 0) {
        object->vtable = fn_1_55C48;
        object->owner = value;
        ok = 1;
        lbl_8006DB74((u8 *)object + 0xC);
        object->unk_3C = fn_1_7BE94();
        object->settings = lbl_1_bss_6C7A4;
        flags = &lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (__rlwnm(flags->unk_0, (i + 1) & 31, 31, 31)) {
                object->items[i] = fn_1_548AC(0x30);
                if (object->items[i] != 0) {
                    lbl_8006DD14((((i * 0x30) + lbl_801A66CC) + (0xE0)), object->items[i]);
                } else {
                    ok = 0;
                }
            } else {
                object->items[i] = 0;
            }
        }
        if (ok != 0) {
            fn_1_5489C( (void **)(handle), (void **)(object));
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_55924 */

/* fzgx:begin fn_1_55A84 */
typedef struct {
    u8 pad_00[0x1c];
    u16 unk_1c;
} FontInput;

typedef struct {
    u8 pad_00[0x4];
    void (*destroy)(void);
    void *owner;
    u8 pad_0c[0x30];
    u16 unk_3c;
    u8 pad_3e[0x2];
    Obj_1_bss_6C7A4 settings;
    void *unk_68;
    u8 pad_6c[0xc];
    void *unk_78;
    void *unk_7c;
    void *unk_80;
} FontObject;

typedef void (*FontCallback)(void *, void *, void *);

void fn_1_55A84(FontCallback callback, FontInput *value, void *arg2, void *arg3) {
    u16 fzgx_value;
    FontObject *cursor;
    int offset;
    FontObject *object;
    void *data;
    int ok;
    int i;
    u32 shift;
    u32 *flags;

    if (value->unk_1c != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        data = (void *)fn_1_5448C((u8 *)value + 8);
        object = (FontObject *)fn_1_548AC(0x84);
        if (object != 0) {
            ok = 1;
            object->destroy = fn_1_55D6C;
            object->owner = value;
            lbl_8006DB74((u8 *)object + 0xc);
            fzgx_value = fn_1_7BE94();
            object->unk_3c = fzgx_value;
            object->settings = lbl_1_bss_6C7A4;
            i = 0;
            offset = 0;
            cursor = object;
            flags = (u32 *)&lbl_1_bss_6C7CC;
            while (i < 4) {
                shift = (i + 1) & 31;
                if ((__rlwnm(*flags, shift, 31, 31) != 0)) {
                    cursor->unk_68 = fn_1_548AC(0x30);
                    if (cursor->unk_68 != 0) {
                        lbl_8006DD14(lbl_801A66CC + offset + 0xe0, cursor->unk_68);
                    } else {
                        ok = 0;
                    }
                } else {
                    cursor->unk_68 = 0;
                }
                i++;
                cursor = (FontObject *)((u8 *)cursor + 4);
                offset += 0x30;
            }
            object->unk_78 = arg2;
            object->unk_7c = arg3;
            object->unk_80 = callback;
            if (ok != 0) {
                fn_1_5489C( (void **)(data), (void **)(object));
            }
        }
        fn_1_56530();
    } else {
        fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
        callback(value, arg2, arg3);
        fn_1_56530();
    }
}
/* fzgx:end fn_1_55A84 */

/* fzgx:begin fn_1_55C48 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern void fn_80077F8C(void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55C48Object;


void fn_1_55C48(Fn1_55C48Object *value) {
    Fn1_55C48Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55C48Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != entry->unk_68)) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, entry->unk_68);
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55C48Object *)((u8 *)entry + 4);
        }
    }

    fn_80077F8C(value->unk_08);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55C48Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + offset));
            } else if ((entry_2->unk_68) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
/* fzgx:end fn_1_55C48 */

/* fzgx:begin fn_1_55D6C noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
    u8 unk_70[0xC];
    u32 unk_78;
    u32 unk_7C;
    void (*unk_80)(void *, u32, u32);
} Fn1_55D6CObject;


void fn_1_55D6C(Fn1_55D6CObject *value) {
    Fn1_55D6CObject * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55D6CObject * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != entry->unk_68)) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, entry->unk_68);
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55D6CObject *)((u8 *)entry + 4);
        }
    }

    value->unk_80(value->unk_08, value->unk_78, value->unk_7C);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55D6CObject *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + offset));
            } else if ((entry_2->unk_68) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
/* fzgx:end fn_1_55D6C */

/* fzgx:begin fn_1_55EA0 */
extern void lbl_8006DBAC(void *value);
extern void fn_800781B8(void *value);

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55EA0Object;


void fn_1_55EA0(Fn1_55EA0Object *value) {
    Fn1_55EA0Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55EA0Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != entry->unk_68)) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, entry->unk_68);
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55EA0Object *)((u8 *)entry + 4);
        }
    }

    fn_800781B8(value->unk_08);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55EA0Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + offset));
            } else if ((entry_2->unk_68) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
/* fzgx:end fn_1_55EA0 */
