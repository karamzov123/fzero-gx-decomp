#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

extern void *lbl_801A6410;
extern void fn_80071718(void *value);
extern void fn_800711A8(void *value);
extern void fn_1_46B4(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void fn_1_A7E60(s32 arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E0A4(void *arg0);
extern void fn_8006F6A8(void *arg0);
extern void lbl_8006DB30(void);
extern void fn_1_A861C(void *arg0, void *arg1);
extern void fn_1_A8834(void *arg0, void *arg1);
extern void fn_1_A89B0(void *arg0, void *arg1, s32 arg2);
extern void fn_1_3920(void);
extern void fn_1_A8D4C(void);
extern void fn_1_A8D64(void);
extern void fn_8001A78C(void (*func)(void));
extern void fn_8001A7D0(void (*func)(void));
extern void fn_1_A9420(u8 value);
extern void fn_1_A948C(int);
extern void fn_1_A943C(int, int);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern void fn_1_A942C(u8 value);
extern void fn_1_A96BC(void);
extern void (*lbl_1_bss_7167C)(void);
extern void fn_1_A5C98(void *);
extern u8 lbl_1_bss_716C8[320];

extern void (*lbl_1_bss_71680)(void);

extern void (*lbl_1_bss_7167C)(void);
extern void fn_1_A9420(u8 value);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern u32 fn_1_451C(void);
extern void sprintf(void *buffer, char *format, ...);
extern void fn_1_A5AA0(void *buffer, void *destination);
extern u32 lbl_1_bss_71670;

extern void (*lbl_1_bss_71684)(void);

extern void (*lbl_1_bss_71688)(void);

extern void (*lbl_1_bss_7168C)(void);
extern void fn_1_A8528(void *arg0, void *arg1);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern u32 fn_80074918(u32, u32, u32);

/* fzgx:begin fn_1_A7294 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/prog.h"
#include "rel/main_rel/driver.h"
#include "psvec.h"

extern s16 fn_1_12C930(s16);
extern s16 fn_1_12CCB0(s16, s16);
extern void *fn_1_14DD68(u32);
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_A7E60(s8, s8, u32, u32, void *);
extern u32 lbl_801A6410;

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u8 pad_0[0x324];
    u32 unk_324;
    s8 unk_328;
    u8 pad_329[0x67];
    u32 unk_390;
    void *unk_394[3];
    u32 unk_3a0;
    u8 pad_3a4[0x9C];
} A7294Elem;

void fn_1_A7294(A7294Elem *arg0, u32 count) {
    A7294Elem *e;
    u32 i;
    s32 t;
    s32 j;
    s8 c;
    s8 v;
    void *vec;

    for (i = 0; i < count; i++) {
        e = arg0 + i;
        for (t = 0; t < 3; t++) {
            e->unk_394[t] = 0;
        }
    }

    e = arg0;
    for (i = 0; i < count; i++, e++) {
        c = e->unk_328;
        if (c < 0) {
            continue;
        }
        if (c == 0x22 || c == 0x27) {
            continue;
        }
        if (e->unk_390 & 0x100000) {
            continue;
        }
        for (j = 0; j < 3; j++) {
            if (j == 0) {
                v = (s8)fn_1_12C930(c);
            } else {
                v = (s8)fn_1_12CCB0(c, (s16)(j - 1));
            }
            if (v >= 0) {
                if (!(c >= 0x29 && e->unk_3a0 != 0)) {
                    vec = 0;
                } else {
                    s16 k = *(s16 *)(e->unk_3a0 + 0x360);
                    if (k >= 0x19 && k <= 0x31) {
                        vec = &lbl_1_data_35864[(k - 0x19) * 0xC];
                    } else {
                        vec = 0;
                    }
                }
                if (vec) {
                    Vec3 tmp;
                    psvec_add(vec, fn_1_14DD68(e->unk_3a0), &tmp);
                    vec = &tmp;
                }
                e->unk_394[j] = (void *)fn_1_4630(*(u32 *)&lbl_801A6410, 0x30c, lbl_1_data_34354, 0x9e);
                if (e->unk_394[j] != 0) {
                    fn_1_A7E60(c, v, (u32)e->unk_394[j], e->unk_324, vec);
                }
            }
        }
    }
}
/* fzgx:end fn_1_A7294 */

/* fzgx:begin fn_1_A744C noprologue */
#include "types.h"
#include "rel/main_rel/driver.h"

typedef struct Resource {
    u8 pad_0[8];
    void *unk_8;
} Resource;
typedef struct Slot {
    u8 pad_0[0x108];
    Resource *unk_108;
} Slot;
typedef struct Entry {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x6B];
    Slot *unk_394[3];
    u8 pad_3A0[0x18];
    s16 unk_3B8;
    u8 pad_3BA[0x86];
} Entry;

extern s32 fn_1_12C930(s32);
extern s16 fn_1_12CCB0(s16, s16);
extern Resource *fn_1_D3884(char *);
extern void fn_80006E10(const char *);
extern int sprintf(char *, const char *, ...);
extern u32 fn_80077D40(void);
extern u32 fn_80071470(void *, u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80071718(Resource *);

#pragma opt_common_subs off
static inline s16 fn_1_A744C_call_fn_1_12CCB0(s16 a1, s16 a0) { return fn_1_12CCB0(a0, a1); }
static inline Slot * fn_1_A744C_array_read(Slot * *array, s32 index) { return array[index]; }
void fn_1_A744C(Entry *entries, u32 count) {
    char buffer[128];
    s16 variant;
    s32 j;
    Entry *subentry;
    s32 driver;
    char * lab_t0;
    s32 variantArg;
    s8 index;
    Slot *slot;
    Resource *resource;
    s32 variantChoice;
    u32 i;
    Entry *entry;
    char *strings = (char *)&lbl_1_data_34348;
    char * lab_t0_;
    fn_80006E10(strings + 0x34);
    for (i = 0, entry = entries; i < count; i++, entry = (Entry *)((char *)entry + 0x440)) {
        variant = entry->unk_3B8 % 4;
        if (variant != 0) {
            subentry = entry;
            variantChoice = variant;
            variantArg = variant;
            driver = entry->unk_328;
            for (j = 0; j < 3; j++, subentry = (Entry *)((char *)subentry + 4)) {
                slot = fn_1_A744C_array_read(subentry->unk_394, 0);
                if (slot != 0) {
                    if (j == 0) {
                        index = fn_1_12C930(driver);
                    } else {
                        index = fn_1_A744C_call_fn_1_12CCB0(j - 1, driver);
                    }
                    if (index >= 0) {
                        if (variantChoice == 0) {
                            lab_t0 = buffer;
                            lab_t0_ = lab_t0;
                            sprintf(lab_t0_, strings + 0x18, ((char **)lbl_1_data_20D1C)[index]);
                        } else {
                            lab_t0 = buffer;
                            lab_t0_ = lab_t0;
                            sprintf(lab_t0_, strings + 0x24, ((char **)lbl_1_data_20D1C)[index], variantArg);
                        }
                        resource = fn_1_D3884(buffer);
                        fn_80008BA8(fn_80071470(slot->unk_108->unk_8, 0), (fn_80071470(resource->unk_8, 0)), (fn_80077D40()));
                        fn_80071718(resource);
                    }
                }
            }
        }
    }
    fn_80006E10(strings + 0x3C);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_A744C */

/* fzgx:begin fn_1_A75DC noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x8];
    void *unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
} Fn1A75dcResult;

typedef struct {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x6b];
    void *unk_394;
} Fn1A75dcObject;

typedef struct {
    u8 pad_0[0x108];
    Fn1A75dcResult *unk_108;
} Fn1A75dcEntry;

typedef struct {
    u8 pad_0[0x18];
    char unk_18[0xc];
    char unk_24[0x10];
    char unk_34[0x8];
    char unk_3c[0x10];
} Fn1A75dcData;

u8 lbl_1_data_34348[12] = {0x00,0x01,0x05,0x07,0x08,0x0C,0x0D,0x10,0x12,0x17,0x00,0x00};
u8 lbl_1_data_34354[12] = {0x64,0x72,0x69,0x76,0x65,0x72,0x2E,0x63,0x00,0x00,0x00,0x00};
char lbl_1_data_34354__fzgx_offset_C[12] = {0x25U,0x73U,0x5FU,0x31U,0x30U,0x30U,0x2EU,0x74U,0x70U,0x6CU,0x00U,0x00U};
char lbl_1_data_34354__fzgx_offset_18[16] = {0x25U,0x73U,0x5FU,0x31U,0x30U,0x30U,0x5FU,0x63U,0x76U,0x25U,0x64U,0x2EU,0x74U,0x70U,0x6CU,0x00U};
char lbl_1_data_34354__fzgx_offset_28[8] = {0x63U,0x68U,0x61U,0x72U,0x61U,0x2FU,0x00U,0x00U};
char lbl_1_data_34354__fzgx_offset_30[16] = {0x2EU,0x2EU,0x00U,0x00U,0x63U,0x68U,0x61U,0x72U,0x61U,0x00U,0x00U,0x00U,0x25U,0x73U,0x5FU,0x31U};
u8 lbl_1_data_34354__fzgx_offset_40[8] = {0x30,0x30,0x2E,0x67,0x6D,0x61,0x00,0x00};
extern const char *lbl_1_data_20D1C[];

extern s32 fn_1_12C930(s32);
extern s32 fn_1_12CCB0(s32, s16);
extern Fn1A75dcResult *fn_1_D3884(void *);
extern void fn_80006E10(const char *);
extern void sprintf(char *, const char *, ...);
extern void *fn_80077D40(Fn1A75dcResult *);
extern void *fn_80071470(void *, s32);
extern void fn_80008BA8(void *, void *, void *);
extern void fn_80071718(Fn1A75dcResult *);

#pragma opt_common_subs on
#pragma opt_lifetimes off
static inline Fn1A75dcResult * fn_1_A75DC_read_pointer(Fn1A75dcEntry * owner) { return owner->unk_108; }
#pragma opt_propagation off
static inline void * fn_1_A75DC_read_pointer_(Fn1A75dcObject * owner) { return owner->unk_394; }
#pragma opt_loop_invariants off
void fn_1_A75DC(Fn1A75dcObject *obj, void *arg) {
    s32 i;
    Fn1A75dcObject *entry;
    s32 index;
    s16 lab_t1;
    struct { void * value; } other;
    Fn1A75dcResult *result;
    void *first_value;
    char buffer[0x80];

    Fn1A75dcData *data;
    fn_80006E10(lbl_1_data_34354__fzgx_offset_28);
    index = obj->unk_328;
    entry = obj;
    i = 0;
    while (i < 3) {
        Fn1A75dcEntry *item = (Fn1A75dcEntry *)fn_1_A75DC_read_pointer_(entry);
        if (item != 0) {
            s8 slot;
            if (((0) == (i))) {
                slot = fn_1_12C930(index);
            } else {
                lab_t1 = (s16)(i - 1);
                slot = fn_1_12CCB0(index, lab_t1);
            }
            if (slot >= 0) {
                if ((s32)arg == 0) {
                    sprintf(buffer, lbl_1_data_34354__fzgx_offset_C,
                        (*((lbl_1_data_20D1C) + (slot))));
                } else {
                    sprintf(buffer, lbl_1_data_34354__fzgx_offset_18,
                        (*((lbl_1_data_20D1C) + (slot))), arg);
                }
                result = fn_1_D3884(buffer);
                other.value = fn_80077D40(result);
                first_value = fn_80071470(result->unk_8, 0);
                fn_80008BA8(fn_80071470(fn_1_A75DC_read_pointer(item)->unk_8, 0),
                    first_value, other.value);
                fn_80071718(result);
            }
        }
        i++;
        entry = (Fn1A75dcObject *)((u8 *)entry + 4);
    }
    fn_80006E10(lbl_1_data_34354__fzgx_offset_30);
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_A75DC */

/* fzgx:begin fn_1_A7728 */
typedef struct FnA7728Resource {
    u8 pad_104[0x104];
    void *field_104;
    void *field_108;
} FnA7728Resource;

typedef struct FnA7728Object {
    u8 pad_394[0x394];
    FnA7728Resource *field_394;
} FnA7728Object;

void fn_1_A7728(FnA7728Object *objects) {
    u8 *object;
    s32 index;

    object = (u8 *)objects;
    index = 0;
    for (;;) {
        if (((FnA7728Object *)object)->field_394 != 0) {
            if (((FnA7728Object *)object)->field_394->field_108 != 0) {
                fn_80071718(((FnA7728Object *)object)->field_394->field_108);
                ((FnA7728Object *)object)->field_394->field_108 = 0;
            }
            if (((FnA7728Object *)object)->field_394->field_104 != 0) {
                fn_800711A8(((FnA7728Object *)object)->field_394->field_104);
                ((FnA7728Object *)object)->field_394->field_104 = 0;
            }
            fn_1_46B4(lbl_801A6410, ((FnA7728Object *)object)->field_394,
                      lbl_1_data_34354, 0x115);
            ((FnA7728Object *)object)->field_394 = 0;
        }
        index++;
        object += 4;
        if (index >= 3) {
            break;
        }
    }
}
/* fzgx:end fn_1_A7728 */

/* fzgx:begin fn_1_A77DC */
typedef struct FnA77DCObject {
    u8 pad_32c[0x32c];
    void *field_32c;
    u8 pad_330[0x64];
    void *field_394[3];
    u8 pad_3a0[0x1a];
    s16 field_3ba;
} FnA77DCObject;

void fn_1_A77DC(FnA77DCObject *object) {
    s32 index;

    if (object->field_3ba == 0 || object->field_3ba == 1) {
        for (index = 0; index < 3; index++) {
            if (object->field_394[index] != 0) {
                fn_1_A8528(object->field_394[index], object->field_32c);
            }
        }
    }
}
/* fzgx:end fn_1_A77DC */

/* fzgx:begin fn_1_A7854 */
typedef struct FnA7854Object {
    u8 pad_394[0x394];
    void *item;
    u8 pad_398[0x22];
    s16 field_3ba;
} FnA7854Object;

extern void fn_1_A8270(void *arg0, void *arg1);

void fn_1_A7854(FnA7854Object *object, void *arg1) {
    FnA7854Object *cursor;
    s32 index;

    if (object->field_3ba == 0 || object->field_3ba == 1) {
        index = 0;
        cursor = object;
        do {
            if (cursor->item != 0) {
                fn_1_A8270(cursor->item, arg1);
            }
            index++;
            cursor = (FnA7854Object *)((u8 *)cursor + 4);
        } while (index < 3);
    }
}
/* fzgx:end fn_1_A7854 */

/* fzgx:begin fn_1_A78CC */
extern u8 lbl_1_data_34354[72];
extern void *lbl_801A6410;
extern void *fn_1_4630(void *arg0, s32 arg1, void *arg2, s32 arg3);

void fn_1_A78CC(void) {
    u32 **table;
    s32 offset;
    s32 index;

    lbl_1_bss_6F638 = (u32)fn_1_4630(lbl_801A6410, 0xb0, lbl_1_data_34354, 0x145);
    table = (u32 **)&lbl_1_bss_6F638;
    index = 0;
    offset = 0;
    do {
        *(u32 *)((u8 *)*table + offset) =
            (u32)fn_1_4630(lbl_801A6410, 0x30c, lbl_1_data_34354, 0x147);
        index++;
        offset += 4;
    } while (index < 0x2c);
}
/* fzgx:end fn_1_A78CC */

/* fzgx:begin fn_1_A7968 */
void fn_1_A7968(void) {
    s32 **table;
    s32 offset;
    s32 index;

    table = (s32 **)&lbl_1_bss_6F638;
    offset = 0;
    index = 0;
    do {
        fn_1_A7E60(41, (s8)index, *(s32 *)((u8 *)*table + offset), -1, 0);
        index++;
        offset += 4;
    } while (index < 44);
}
/* fzgx:end fn_1_A7968 */

/* fzgx:begin fn_1_A79D8 */
struct fn_1_A79D8_Vec {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_A79D8_Obj {
    u8 unk_0[0x114];
    struct fn_1_A79D8_Vec vec;
};

extern u32 lbl_1_bss_6F638;
extern void fn_1_A8528(void *, void *);
extern void fn_1_A8270(void *, void *);

void fn_1_A79D8(u32 arg0, struct fn_1_A79D8_Vec *arg1) {
    u32 *table = *(u32 **)&lbl_1_bss_6F638;
    struct fn_1_A79D8_Obj *obj = (struct fn_1_A79D8_Obj *)table[arg0];
    struct fn_1_A79D8_Vec old = obj->vec;

    obj->vec = *arg1;
    fn_1_A8528(obj, 0);
    fn_1_A8270(obj, 0);
    obj->vec = old;
}
/* fzgx:end fn_1_A79D8 */

/* fzgx:begin fn_1_A7A70 */
void fn_1_A7A70(void) {
    s32 index;
    u32 *entries;

    for (index = 0; index < 0x2c; index++) {
        entries = (u32 *)lbl_1_bss_6F638;
        if (entries[index] != 0) {
            fn_1_46B4(lbl_801A6410, (void *)entries[index],
                      lbl_1_data_34354, 0x168);
            entries = (u32 *)lbl_1_bss_6F638;
            entries[index] = 0;
        }
    }

    if (lbl_1_bss_6F638 != 0) {
        fn_1_46B4(lbl_801A6410, (void *)lbl_1_bss_6F638,
                  lbl_1_data_34354, 0x169);
        lbl_1_bss_6F638 = 0;
    }
}
/* fzgx:end fn_1_A7A70 */

/* fzgx:begin fn_1_A7B30 noprologue */
#include "types.h"

typedef struct FnA7B30Vector {
    s32 x;
    s32 y;
    s32 z;
} FnA7B30Vector;

extern FnA7B30Vector lbl_1_data_35864[];

void fn_1_A7B30(s32 index, FnA7B30Vector *out) {
    *out = lbl_1_data_35864[index - 25];
}
/* fzgx:end fn_1_A7B30 */

/* fzgx:begin fn_1_A7B5C noprologue */
typedef signed char s8;


typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct Vec3 {
f32 x;
f32 y;
f32 z;
} Vec3;


typedef struct {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 unk_3;
u8 unk_4;
u8 unk_5;
u8 unk_6;
u8 unk_7;
u8 unk_8;
u8 unk_9;
u8 pad_A[0x2];
} Obj_1_data_34348;
extern Obj_1_data_34348 lbl_1_data_34348;


typedef struct {
u32 unk_0;
u32 unk_4;
u32 unk_8;
u8 pad_C[0x204];
} Obj_1_data_343C4;
extern Obj_1_data_343C4 lbl_1_data_343C4;
typedef struct {
u8 pad_0[0x48];
f32 unk_48;
f32 unk_4C;
f32 unk_50;
f32 unk_54;
f32 unk_58;
u8 pad_5C[0xF74];
} Obj_1_data_345D4;
extern Obj_1_data_345D4 lbl_1_data_345D4;


typedef struct A7B5C_Mtx {
u8 pad[0x30];
} A7B5C_Mtx;
typedef struct A7B5C_Obj {
A7B5C_Mtx mtx[4];
f32 unk_c0;
f32 unk_c4;
f32 unk_c8;
f32 unk_cc;
f32 unk_d0;
f32 unk_d4;
f32 unk_d8;
f32 unk_dc;
f32 unk_e0;
f32 unk_e4;
s8 unk_e8;
u8 unk_e9;
u8 pad_ea[0x10c - 0xea];
f32 unk_10c;
f32 unk_110;
Vec3 unk_114;
f32 unk_120;
f32 unk_124;
f32 unk_128;
A7B5C_Mtx parts[10];
} A7B5C_Obj;
typedef struct A7B5C_Src {
u8 pad[8];
u8 *data;
} A7B5C_Src;


extern void fn_1_A7F84(void *, s32);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern f32 lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DB30(void);

#pragma opt_propagation off

static inline void A7B5C_init(A7B5C_Obj *obj, s8 kind, s8 type, f32 unused) {
f32 negative;
f32 positive;
f32 zero;
zero = unused;
obj->unk_e0 = zero;
obj->unk_dc = zero;
obj->unk_e4 = zero;
obj->unk_d8 = zero;
obj->unk_120 = zero;
obj->unk_124 = zero;
obj->unk_128 = zero;
obj->unk_e8 = type;
obj->unk_e9 = (kind >= 0x29);
if (obj->unk_e9 != 0) {
if (type == 0x21) {
negative = -0.1f;
obj->unk_120 = zero;
obj->unk_124 = zero;
obj->unk_128 = negative;
} else if (type == 0x2a) {
positive = 0.1f;
obj->unk_120 = positive;
obj->unk_124 = zero;
obj->unk_128 = positive;
} else if (type == 0x2b) {
negative = -0.1f;
positive = 0.1f;
obj->unk_120 = negative;
obj->unk_124 = zero;
obj->unk_128 = positive;
} else if (type == 0x15) {
positive = 0.1f;
obj->unk_120 = zero;
obj->unk_124 = zero;
obj->unk_128 = positive;
} else if (type == 0x29) {
negative = -0.1f;
obj->unk_120 = zero;
obj->unk_124 = zero;
obj->unk_128 = negative;
}
}
}
static inline void A7B5C_copy_parts(A7B5C_Mtx *parts, A7B5C_Src *src) {
s32 i;
for (i = 0; i < 10; i++) {
lbl_8006DD14(src->data + (s8)(&lbl_1_data_34348.unk_0)[i] * 0x18c + 0x88, &parts[i]);
}
}
static inline void A7B5C_default_parts(A7B5C_Mtx *parts, s32 off) {
s32 i;
for (i = 0; i < 10; i++) {
fn_1_A7F84((u8 *)&lbl_1_data_345D4 + off, i);
lbl_8006DB74(&parts[i]);
}
}
void fn_1_A7B5C(A7B5C_Obj *obj, A7B5C_Src *src, s8 kind, s8 type, Vec3 *pos) {
A7B5C_Mtx *parts;
Obj_1_data_345D4 *entry;
s32 off;
s32 i;
A7B5C_init(obj, kind, type, 0.0f);
if (pos != ((void *)0) ) {
obj->unk_114 = *pos;
} else {
obj->unk_114 = ((Vec3 *)&lbl_1_data_343C4)[type];
}
if (src != ((void *)0) ) {
parts = obj->parts;
for (i = 0; i < 10; i++, parts++) {
lbl_8006DD14(src->data + (s8)(&lbl_1_data_34348.unk_0)[i] * 0x18c + 0x88, parts);
}
obj->unk_c0 = *(f32 *)(src->data + 0xe80);
obj->unk_c4 = *(f32 *)(src->data + 0xe90);
obj->unk_c8 = *(f32 *)(src->data + 0xea0);
obj->unk_cc = *(f32 *)(src->data + 0x163c);
obj->unk_d0 = *(f32 *)(src->data + 0x164c);
obj->unk_d4 = *(f32 *)(src->data + 0x165c);
obj->unk_10c = *(f32 *)(src->data + 0xc74);
obj->unk_110 = *(f32 *)(src->data + 0xe00);
} else {
A7B5C_Mtx *defaultParts;
s32 j;
defaultParts = obj->parts;
for (j = 0; j < 10; j++, defaultParts++) {
fn_1_A7F84((void *)((u32)&lbl_1_data_345D4 + type * 0x5c), j);
lbl_8006DB74(defaultParts);
}
entry = (Obj_1_data_345D4 *)((u8 *)&lbl_1_data_345D4 + type * 0x5c);
obj->unk_c0 = entry->unk_48;
obj->unk_c4 = entry->unk_4C;
obj->unk_c8 = entry->unk_50;
obj->unk_cc = -entry->unk_48;
obj->unk_d0 = entry->unk_4C;
obj->unk_d4 = entry->unk_50;
obj->unk_10c = entry->unk_54;
obj->unk_110 = entry->unk_58;
}
lbl_8006DBAC((u8 *)obj + 0x15c);
lbl_8006DB74(&obj->mtx[0]);
lbl_8006DD7C();
lbl_8006DAEC();
lbl_8006DFC4((u8 *)obj + 0x1bc);
lbl_8006DB74(&obj->mtx[1]);
lbl_8006DB30();
lbl_8006DAEC();
lbl_8006DFC4((u8 *)obj + 0x21c);
lbl_8006DB74(&obj->mtx[2]);
lbl_8006DB30();
lbl_8006DAEC();
lbl_8006DFC4((u8 *)obj + 0x18c);
lbl_8006DB74(&obj->mtx[3]);
lbl_8006DB30();
}
/* fzgx:end fn_1_A7B5C */

/* fzgx:begin fn_1_A7F84 noprologue */
#include "types.h"

struct fn_1_A7F84_lbl_1_rodata_4A28 {
    f32 unk_0;
};
struct fn_1_A7F84_lbl_801A6D00 {
    u32 unk_0;
};
extern struct fn_1_A7F84_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern struct fn_1_A7F84_lbl_801A6D00 lbl_801A6D00;
extern u32 jumptable_1_data_3439C;
extern u32 lbl_8006D91C(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_x(u32);
extern u32 lbl_8006D998(u32);


void fn_1_A7F84(void *arg0, u32 arg1) {
    switch (arg1) {
    case 0:
        lbl_8006D91C(0U);
        mathutil_mtxA_rotate_y(0U);
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 0)));
        return;
    case 1:
        lbl_8006D91C(0x4000U);
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 2)));
        mathutil_mtxA_rotate_x(0x4000U);
        return;
    case 2:
        lbl_8006D998(0x4000U);
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 4)));
        mathutil_mtxA_rotate_x(0U);
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 12)) = (f32) lbl_1_rodata_4A28.unk_0;
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 28));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 32));
        return;
    case 3:
        lbl_8006D998((u32) (*(s16 *)((u8 *)(arg0) + 10)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 8)));
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 6)));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 12)) = (f32) (*(f32 *)((u8 *)(arg0) + 36));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 40));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 44));
        return;
    case 4:
        lbl_8006D998((u32) (*(s16 *)((u8 *)(arg0) + 16)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 14)));
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 12)));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 12)) = (f32) (*(f32 *)((u8 *)(arg0) + 48));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 52));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 56));
        return;
    case 5:
        lbl_8006D998((u32) (s16) (-0x4000 - ((*(s16 *)((u8 *)(arg0) + 10)) + 0x4000)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 8)));
        mathutil_mtxA_rotate_x((u32) (s16) (-0x4000 - ((*(s16 *)((u8 *)(arg0) + 6)) + 0x4000)));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 12)) = (f32) -(*(f32 *)((u8 *)(arg0) + 36));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 40));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 44));
        return;
    case 6:
        lbl_8006D998((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 16)) - 0x4000)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 14)));
        mathutil_mtxA_rotate_x((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 12)) - 0x4000)));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 12)) = (f32) -(*(f32 *)((u8 *)(arg0) + 48));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 52));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 56));
        return;
    case 7:
        lbl_8006D91C(-0x4000U);
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 18)));
        mathutil_mtxA_rotate_x(-0x4000U);
        return;
    case 8:
        lbl_8006D998((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 24)) - 0x4000)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 22)));
        mathutil_mtxA_rotate_x((u32) (s16) (0x4000 - ((*(s16 *)((u8 *)(arg0) + 20)) - 0x4000)));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 12)) = (f32) -(*(f32 *)((u8 *)(arg0) + 60));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 64));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 68));
        return;
    case 9:
        lbl_8006D998((u32) (*(s16 *)((u8 *)(arg0) + 24)));
        mathutil_mtxA_rotate_y((u32) (*(s16 *)((u8 *)(arg0) + 22)));
        mathutil_mtxA_rotate_x((u32) (*(s16 *)((u8 *)(arg0) + 20)));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 12)) = (f32) (*(f32 *)((u8 *)(arg0) + 60));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 28)) = (f32) (*(f32 *)((u8 *)(arg0) + 64));
        (*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 44)) = (f32) (*(f32 *)((u8 *)(arg0) + 68));
        /* fallthrough */
    default:
        return;
    }
}
/* fzgx:end fn_1_A7F84 */

/* fzgx:begin fn_1_A8270 noprologue */
#include "types.h"
#include "rel/main_rel/driver.h"

struct fn_1_A8270_Entry {
	u32 unk_0;
	u32 unk_4;
	u32 unk_8;
	u8 pad_C[0x18];
};

struct fn_1_A8270_Rec {
	u8 pad_0[4];
	u32 unk_4;
	u8 pad_8[0x16];
	u8 count;
};

struct fn_1_A8270_Arg0 {
	u8 pad_0[0xE8];
	u8 unk_E8;
	u8 unk_E9;
	s16 unk_EA;
	s16 unk_EC;
	s16 unk_EE;
	void *unk_F0;
	u8 pad_F4[8];
	struct fn_1_A8270_Entry *unk_FC;
	s32 unk_100;
	u32 unk_104;
	u8 pad_108[0x24];
	u32 *unk_12C[12];
};

extern void _savegpr_23(void);
extern void _restgpr_23(void);
extern u32 fn_80077A18(void);
extern void lbl_8006DAEC(void);
extern struct fn_1_A8270_Rec *fn_80071268(u32, u32);
extern void lbl_8006D9D8(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E0A4(u32);
extern void lbl_8006E14C(f32);
extern void fn_80077A20(struct fn_1_A8270_Rec *, void *);
extern void fn_1_55FC4(f32);
extern void fn_80072558(void);
extern void fn_1_556B8(struct fn_1_A8270_Rec *);
extern void lbl_8006DB30(void);
extern f32 lbl_1_rodata_4A34[25];

static inline s8 tab_index(s8 c) {
	const s8 *p = (const s8 *)&lbl_1_data_34348;
	s32 k;
	for (k = 0; k < 10; k++) {
		if (c == *p) {
			return k;
		}
		p++;
	}
	return 0;
}

static inline f32 *fn_1_A8270_array_read(f32 *array) { return array; }
#pragma opt_loop_invariants off
void fn_1_A8270(struct fn_1_A8270_Arg0 *self, s32 arg1) {
	s32 i;
	u32 *out;
	u32 unk_104;
	struct fn_1_A8270_Entry *ent;
	struct fn_1_A8270_Rec *rec;
	s32 ok;
    s32 lab_t0;

	unk_104 = self->unk_104;
	out = (u32 *)fn_80077A18();
	lbl_8006DAEC();
	for (i = 0; i < self->unk_100; i++) {
		ent = &self->unk_FC[i];
		rec = fn_80071268(unk_104, ent->unk_4);
		if (rec != 0) {
			lbl_8006D9D8(&self->unk_F0);
			mathutil_mtxA_rotate_z(self->unk_EE);
			lab_t0 = self->unk_EA;
			mathutil_mtxA_rotate_y(lab_t0);
			mathutil_mtxA_rotate_x(self->unk_EC);
			if (self->unk_E9 != 0) {
				lbl_8006E0A4((u32)&lbl_1_data_35654[self->unk_E8 * 12]);
			}
			if (self->unk_E9 != 0) {
				lbl_8006E14C(((const f32 *)lbl_1_data_355A4)[self->unk_E8]);
			}
			ok = 1;
			if ((rec->unk_4 & 0xC) != 0 && ent->unk_8 != 0) {
				s32 j;
				for (j = 0; j < (s32)rec->count; j++) {
					const s8 *str = (const s8 *)ent->unk_8;
					u8 c = str[j];
					s8 idx = tab_index(c);
					out[j] = (u32)(void *)&self->unk_12C[idx * 12];
				}
			} else if ((rec->unk_4 & 0xC) != 0) {
				fn_80077A20(rec, 0);
			} else {
				ok = 0;
			}
			if (ok != 0) {
				if (arg1 != 0) {
					lbl_8006E14C(fn_1_A8270_array_read(lbl_1_rodata_4A34)[0]);
					fn_1_55FC4(fn_1_A8270_array_read(lbl_1_rodata_4A34)[0]);
				}
				fn_80072558();
				fn_1_556B8(rec);
			}
		}
	}
	lbl_8006DB30();
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_A8270 */

/* fzgx:begin fn_1_A8528 */
typedef struct FnA8528Object {
    u8 pad_ea[0xea];
    s16 unk_ea;
    s16 unk_ec;
    s16 unk_ee;
    f32 unk_f0;
    f32 unk_f4;
    f32 unk_f8;
    u8 pad_fc[0x18];
    u8 unk_114[0xc];
    u8 unk_120[0x4];
} FnA8528Object;

typedef struct FnA8528Config {
    u8 pad_0c[0x0c];
    f32 unk_0c;
    u8 pad_10[0x0c];
    f32 unk_1c;
    u8 pad_20[0x0c];
    f32 unk_2c;
} FnA8528Config;

extern FnA8528Config *lbl_801A6D00;

// Initializes the driver's state from the active configuration and shared systems.
void fn_1_A8528(void *arg0, void *arg1) {
    s16 orientation[3];
    void *driver_data;

    if (arg1 != 0) {
        driver_data = (u8 *)arg1 + 0x14c;
    } else {
        driver_data = lbl_801A6D00;
    }

    lbl_8006DAEC();
    lbl_8006DBAC(driver_data);
    lbl_8006E0A4(((FnA8528Object *)arg0)->unk_114);
    lbl_8006E0A4(((FnA8528Object *)arg0)->unk_120);
    fn_8006F6A8(orientation);

    ((FnA8528Object *)arg0)->unk_f0 = lbl_801A6D00->unk_0c;
    ((FnA8528Object *)arg0)->unk_f4 = lbl_801A6D00->unk_1c;
    ((FnA8528Object *)arg0)->unk_f8 = lbl_801A6D00->unk_2c;
    ((FnA8528Object *)arg0)->unk_ec = orientation[0];
    ((FnA8528Object *)arg0)->unk_ea = orientation[1];
    ((FnA8528Object *)arg0)->unk_ee = orientation[2];

    fn_1_A861C(arg0, arg1);
    fn_1_A8834(arg0, arg1);
    fn_1_A89B0(arg0, arg1, 1);
    fn_1_A89B0(arg0, arg1, 0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_A8528 */

/* fzgx:begin fn_1_A8D4C */
void fn_1_A8D4C(void) {
    lbl_1_bss_6F640 += 1;
}
/* fzgx:end fn_1_A8D4C */

/* fzgx:begin fn_1_A8D64 */
void fn_1_A8D64(void) {
    fn_1_3920();
}
/* fzgx:end fn_1_A8D64 */

/* fzgx:begin fn_1_A8D84 */
void fn_1_A8D84(void) {
    lbl_1_bss_6F640 = 0;
    fn_8001A78C(fn_1_A8D4C);
    fn_8001A7D0(fn_1_A8D64);
}
/* fzgx:end fn_1_A8D84 */

/* fzgx:begin fn_1_A8DC4 */
// Returns the current driver state handle.
u32 fn_1_A8DC4(void) {
    return lbl_1_bss_6F640;
}
/* fzgx:end fn_1_A8DC4 */

/* fzgx:begin fn_1_A8DD4 noprologue */
#include "types.h"

typedef struct {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format_MkVaListState;
typedef Sig_parse_format_MkVaListState Sig_parse_format_va_list;

extern void fn_1_A9420(u8 value);
extern s32 fn_8008077C(u32 buffer, const char *format, Sig_parse_format_va_list *args);
extern void fn_1_A948C(char *text);

void fn_1_A8DD4(const char *format, ...) {
    char buffer[0x200];
    Sig_parse_format_va_list args;

    fn_1_A9420(0);
    __builtin_va_info(&args);
    fn_8008077C((u32)buffer, format, &args);
    fn_1_A948C(buffer);
}
/* fzgx:end fn_1_A8DD4 */

/* fzgx:begin fn_1_A8E78 */
// fn_1_A8E78: Take an argument, call fn_1_A9420(0), then fn_1_A948C with original arg.

void fn_1_A8E78(int arg) {
    fn_1_A9420(0);
    fn_1_A948C(arg);
}
/* fzgx:end fn_1_A8E78 */

/* fzgx:begin fn_1_A8EB0 */
void fn_1_A8EB0(int arg0, int arg1) {
    fn_1_A9420(0);
    fn_1_A943C(arg0, arg1);
}
/* fzgx:end fn_1_A8EB0 */

/* fzgx:begin fn_1_A8EF8 */
// Reset the current selection before applying the two provided values.
void fn_1_A8EF8(u16 arg0, u16 arg1) {
    fn_1_A9420(0);
    fn_1_A9464(arg0, arg1);
}
/* fzgx:end fn_1_A8EF8 */

/* fzgx:begin fn_1_A8F40 */
// Reset the mode before forwarding the supplied value.
void fn_1_A8F40(u8 arg0) {
    fn_1_A9420(0);
    fn_1_A942C(arg0);
}
/* fzgx:end fn_1_A8F40 */

/* fzgx:begin fn_1_A8F78 */
void fn_1_A8F78(void) {
    fn_1_A9420(0);
    fn_1_A96BC();
}
/* fzgx:end fn_1_A8F78 */

/* fzgx:begin fn_1_A9250 noprologue */
#include "types.h"

extern void fn_1_49410(void);
extern u32 lbl_1_data_35990[3];
extern void fn_1_494DC(s16);
extern void fn_1_520A0(void);
extern void fn_1_52088(void);
extern u32 lbl_1_bss_71658[6];
extern const f64 lbl_1_rodata_4A98;
extern void fn_1_49714(f32, f32, f32);
extern void fn_1_49680(f32, f32);
extern void fn_1_A93C4(u8);
extern void fn_1_4A0D8(void *);
extern void fn_1_520CC(void);

typedef struct {
    u8 kind;
    u8 callback;
    u8 flags;
    u8 pad3;
    s16 x;
    s16 y;
    s16 z;
    s16 padA;
    void *data;
} Fn1A9250Entry;

extern Fn1A9250Entry lbl_1_bss_70658[];

void fn_1_A9250(int arg) {
    int i;

    fn_1_49410();
    fn_1_494DC((s16)lbl_1_data_35990[(u8)arg]);
    fn_1_520A0();
    fn_1_52088();

    for (i = 0; i < (int)lbl_1_bss_71658[0]; i++) {
        if ((u8)arg == lbl_1_bss_70658[i].kind) {
            if (((lbl_1_bss_70658[i].flags >> 1) & 1) != 0) {
                fn_1_49714(
                    (f32)(lbl_1_bss_70658[i].x + lbl_1_bss_70658[i].z),
                    (f32)lbl_1_bss_70658[i].y,
                    (f32)lbl_1_bss_70658[i].x);
            } else {
                fn_1_49680(
                    (f32)(lbl_1_bss_70658[i].x + lbl_1_bss_70658[i].z),
                    (f32)lbl_1_bss_70658[i].y);
            }
            fn_1_A93C4(lbl_1_bss_70658[i].callback);
            fn_1_4A0D8(lbl_1_bss_70658[i].data);
        }
    }

    fn_1_49410();
    fn_1_520CC();
}
/* fzgx:end fn_1_A9250 */

/* fzgx:begin fn_1_A93C4 */
extern void fn_1_49514(u32 *);

void fn_1_A93C4(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    s8 loc_8[8];
    v0 = ((arg0 & 0xC0) | 63);
    v1 = (((arg0 << 2) & 0xC0) | 63);
    v2 = (((arg0 << 4) & 0xC0) | 63);
    loc_8[4] = v0;
    loc_8[5] = v1;
    loc_8[6] = v2;
    loc_8[7] = (((arg0 & 0x3) << 6) | 63);
    *(u32 *)&loc_8[0] = *(u32 *)&loc_8[4];
    fn_1_49514((u32 *)loc_8);
}
/* fzgx:end fn_1_A93C4 */

/* fzgx:begin fn_1_A9420 */
// Stores the current value in the driver's status byte.
void fn_1_A9420(u8 value) {
    lbl_1_bss_6F648.unk_0 = value;
}
/* fzgx:end fn_1_A9420 */

/* fzgx:begin fn_1_A942C */
// Stores the value in the driver's secondary byte-sized state field.
void fn_1_A942C(u8 value) {
    lbl_1_bss_6F648.unk_1 = value;
}
/* fzgx:end fn_1_A942C */

/* fzgx:begin fn_1_A943C noprologue */
#include "types.h"

extern void (*lbl_1_bss_7168C)(void);

extern struct fn_1_A943C_lbl_1_bss_6F648 lbl_1_bss_6F648;

struct fn_1_A943C_lbl_1_bss_6F648 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0x1];
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
};

void fn_1_A943C(u32 arg0, u32 arg1) {
    u8 v0;
    v0 = lbl_1_bss_6F648.unk_2;
    lbl_1_bss_6F648.unk_4 = arg0;
    lbl_1_bss_6F648.unk_6 = arg1;
    lbl_1_bss_6F648.unk_8 = 0;
    lbl_1_bss_6F648.unk_2 = (v0 & 0xFFFFFFFD);
}
/* fzgx:end fn_1_A943C */

/* fzgx:begin fn_1_A9464 */
// Set the two values and mark the shared state as ready.
void fn_1_A9464(u16 arg0, u16 arg1) {
    u8 flags;

    flags = lbl_1_bss_6F648.unk_2;
    lbl_1_bss_6F648.unk_4 = arg0;
    lbl_1_bss_6F648.unk_6 = arg1;
    lbl_1_bss_6F648.unk_8 = 0;
    lbl_1_bss_6F648.unk_2 = flags | 2;
}
/* fzgx:end fn_1_A9464 */

/* fzgx:begin fn_1_A96BC */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6F648[4];
u32 lbl_1_bss_6F648__fzgx_offset_10[1024];
u32 fzgx_obj_lbl_1_bss_70658[1024];
u32 fzgx_obj_lbl_1_bss_71658[6];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6F648[0];
    s = lbl_1_bss_6F648__fzgx_offset_10[0];
    s = fzgx_obj_lbl_1_bss_70658[0];
    s = fzgx_obj_lbl_1_bss_71658[0];
}
#pragma section code_type ".text"

void fn_1_A96BC(void) {
    fzgx_obj_lbl_1_bss_71658[0] = 0;
    fzgx_obj_lbl_1_bss_6F648[3] = (u32)lbl_1_bss_6F648__fzgx_offset_10;
}
/* fzgx:end fn_1_A96BC */

/* fzgx:begin fn_1_A96DC */
void fn_1_A96DC(void) {
    lbl_1_data_3599C.unk_0 = 1;
}
/* fzgx:end fn_1_A96DC */

/* fzgx:begin fn_1_A96EC */
// Clear the driver's first state field.
void fn_1_A96EC(void) {
    lbl_1_data_3599C.unk_0 = 0;
}
/* fzgx:end fn_1_A96EC */

/* fzgx:begin fn_1_A96FC */
// Initialize the driver state and format its startup data.
void fn_1_A96FC(void) {
    u8 buffer[0x48];

    lbl_1_bss_71670 = fn_1_451C();
    sprintf(buffer, (char *)lbl_1_data_35AB8,
                ((u32 *)lbl_1_data_35A70)[*(s16 *)&lbl_1_bss_960]);
    fn_1_A5AA0(buffer, &lbl_1_bss_71674);
}
/* fzgx:end fn_1_A96FC */

/* fzgx:begin fn_1_A9764 */
void fn_1_A9764(void) {
    lbl_1_bss_7167C();
}
/* fzgx:end fn_1_A9764 */

/* fzgx:begin fn_1_A9790 */
void fn_1_A9790(void) {
    lbl_1_bss_71680();
}
/* fzgx:end fn_1_A9790 */

/* fzgx:begin fn_1_A97BC */
void fn_1_A97BC(void) {
    fn_1_A5C98(&lbl_1_bss_71674);
}
/* fzgx:end fn_1_A97BC */

/* fzgx:begin fn_1_A97E4 */
void fn_1_A97E4(void) {
    lbl_1_bss_71684();
}
/* fzgx:end fn_1_A97E4 */

/* fzgx:begin fn_1_A9810 */
void fn_1_A9810(void) {
    lbl_1_bss_71688();
}
/* fzgx:end fn_1_A9810 */

/* fzgx:begin fn_1_A983C */
void fn_1_A983C(void) {
    lbl_1_bss_7168C();
}
/* fzgx:end fn_1_A983C */

/* fzgx:begin fn_1_A9868 noprologue */
#include "types.h"

typedef struct Sig_fn_80015EE8_Fn80015EE8Out {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    f32 f7;
    f32 f8;
    f32 f9;
    f32 f10;
    f32 f11;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f15;
} Sig_fn_80015EE8_Fn80015EE8Out;
struct Sig_fn_800737E4_fn_800737E4_Arg0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
};

struct fn_1_A9868_lbl_1_bss_71690 {
    u32 unk_0;
};
struct fn_1_A9868_lbl_1_rodata_4AA0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
};
struct fn_1_A9868_lbl_801A6D00 {
    u32 unk_0;
};

extern struct fn_1_A9868_lbl_1_bss_71690 lbl_1_bss_71690;
extern struct fn_1_A9868_lbl_1_rodata_4AA0 lbl_1_rodata_4AA0;
extern struct fn_1_A9868_lbl_801A6D00 lbl_801A6D00;
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800720B0(u32);
extern u32 fn_80072EDC(u32, u32);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern f32 fn_80015EE8(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void fn_80038CFC(u32);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_8007245C(u32);
extern void fn_8007264C(u32, s32, s32, s32, u8);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_800746A8(u8, s32);
extern void fn_80074718(u8, s32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *, s32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);

void fn_1_A9868(u32 arg0, u32 arg1, u32 arg2, f32 arg3) {
    struct fn_1_A9868_lbl_1_rodata_4AA0 *p_lbl_1_rodata_4AA0;
    struct fn_1_A9868_lbl_1_bss_71690 *p_lbl_1_bss_71690;
    Sig_fn_80015EE8_Fn80015EE8Out loc_2C;
    u32 loc_20[3];
    u32 loc_14[3];
    u32 loc_8[3];
    f32 zero;
    p_lbl_1_rodata_4AA0 = (struct fn_1_A9868_lbl_1_rodata_4AA0 *)&lbl_1_rodata_4AA0;
    p_lbl_1_bss_71690 = (struct fn_1_A9868_lbl_1_bss_71690 *)&lbl_1_bss_71690;
    fn_1_A714C((f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 4), (f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 8), (f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 12), (f32 *)((u8 *)(u32)p_lbl_1_bss_71690 + 16));
    fn_8007245C(2560);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_8007264C(0, 9, 1, 4, 8);
    fn_80074718(6, 0);
    fn_800746A8(6, 0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
    lbl_8006DAEC();
    loc_20[0] = p_lbl_1_rodata_4AA0->unk_0;
    loc_20[1] = p_lbl_1_rodata_4AA0->unk_4;
    loc_20[2] = p_lbl_1_rodata_4AA0->unk_8;
    loc_14[0] = p_lbl_1_rodata_4AA0->unk_C;
    loc_14[1] = p_lbl_1_rodata_4AA0->unk_10;
    loc_14[2] = p_lbl_1_rodata_4AA0->unk_14;
    loc_8[0] = p_lbl_1_rodata_4AA0->unk_18;
    loc_8[1] = p_lbl_1_rodata_4AA0->unk_1C;
    loc_8[2] = p_lbl_1_rodata_4AA0->unk_20;
    fn_8006F1F0((void *)loc_20, (void *)loc_14, (void *)loc_8);
    fn_80038CFC(0);
    GXLoadPosMtxImm(lbl_801A6D00.unk_0, 0);
    lbl_8006DB30();
    zero = fn_80015EE8((Sig_fn_80015EE8_Fn80015EE8Out *)&loc_2C, p_lbl_1_rodata_4AA0->unk_24, p_lbl_1_rodata_4AA0->unk_28, p_lbl_1_rodata_4AA0->unk_24, p_lbl_1_rodata_4AA0->unk_2C, p_lbl_1_rodata_4AA0->unk_24, p_lbl_1_rodata_4AA0->unk_30);
    fn_800737E4((struct Sig_fn_800737E4_fn_800737E4_Arg0 *)&loc_2C, 1, zero);
    fn_80074918(1, 7, 0);
    p_lbl_1_bss_71690->unk_0 = 1;
}
/* fzgx:end fn_1_A9868 */

/* fzgx:begin fn_1_AA538 */
// Initialize the shared rendering state and submit the associated configuration.
void fn_1_AA538(void) {
    Obj_1_bss_71690 *state = (Obj_1_bss_71690 *)&lbl_1_bss_71690;

    fn_1_A7024(state->unk_4, state->unk_8, state->unk_C, state->unk_10);
    fn_80074918(1, 3, 1);
    state->unk_0 = 1;
}
/* fzgx:end fn_1_AA538 */

/* fzgx:begin fn_1_AAEB0 noprologue */
#include "types.h"

struct fn_1_AAEB0_Arg0 {
    u8 unk_0;
    u8 pad_1[0x4];
    u8 unk_5;
    u8 pad_6[0x1E];
    u32 unk_24;
};
struct fn_1_AAEB0_lbl_1_data_35AC8 {
    u8 pad_0[0x6AC4];
    u32 unk_6AC4[1];
};

extern struct fn_1_AAEB0_lbl_1_data_35AC8 lbl_1_data_35AC8;
extern void OSPanic(const char *, int, const char *, ...);
extern void OSReport(const char *, ...);

static inline u32 *fn_1_AAEB0_array_read(u32 *array) { return array; }
#pragma opt_propagation off
void fn_1_AAEB0(struct fn_1_AAEB0_Arg0 *arg0) {
    struct fn_1_AAEB0_lbl_1_data_35AC8 *p_lbl_1_data_35AC8;
    p_lbl_1_data_35AC8 = (struct fn_1_AAEB0_lbl_1_data_35AC8 *)&lbl_1_data_35AC8;
    OSReport((const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 28000), arg0->unk_0, *(u32 *)((u8 *)arg0->unk_24 + 4), fn_1_AAEB0_array_read(p_lbl_1_data_35AC8->unk_6AC4)[arg0->unk_5]);
    OSPanic((const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 27888), 1322, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 28044));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_AAEB0 */

/* fzgx:begin fn_1_AAF18 */
// fn_1_AAF18: empty in retail (single blr).
void fn_1_AAF18(void) {
}
/* fzgx:end fn_1_AAF18 */

/* fzgx:begin fn_1_AAF1C noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


extern s16 lbl_1_bss_960;


extern u32 lbl_1_data_35AC8;


extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
typedef struct {
u8 pad_0[0x3F];
u8 unk_3F;
} AAF1C_Info;
typedef struct {
u8 pad_0[0x2];
s16 unk_2;
s32 unk_4;
u32 unk_8;
u8 pad_C[0x80];
AAF1C_Info *unk_8C;
} AAF1C_State;
typedef struct {
u8 pad_0[0x2];
u8 unk_2;
u8 pad_3[0x5];
s16 unk_8;
s16 unk_A;
u8 pad_C[0x18];
AAF1C_State *unk_24;
u8 pad_28[0x2];
u8 unk_2A;
} AAF1C_Obj;
void fn_1_AAF1C(AAF1C_Obj *obj)
{
char *str = (char *)&lbl_1_data_35AC8;
switch (obj->unk_24 ->unk_4) {
case -2:
obj->unk_8 = 1;
break;
case -3:
obj->unk_8 = 0;
break;
case -6:
case -5:
obj->unk_8 = 0x20;
break;
case -0xd:
obj->unk_8 = 0x21;
break;
case -8:
switch (obj->unk_24 ->unk_8C->unk_3F) {
case 0x50:
default:
obj->unk_8 = 0x2b;
break;
case 0x4F:
case 0x51:
case 0x52:
case 0x53:
case 0x54:
obj->unk_8 = 0x2a;
break;
}
break;
case -9:
switch (obj->unk_24 ->unk_8C->unk_3F) {
case 0x50:
default:
obj->unk_8 = 0x2d;
break;
case 0x4F:
case 0x51:
case 0x52:
case 0x53:
case 0x54:
obj->unk_8 = 0x2c;
break;
}
break;
case -4:
obj->unk_8 = 0x38;
break;
case -0x7b:
obj->unk_8 = 0x37;
break;
case -0x7c:
obj->unk_8 = 0x36;
break;
case -0x7d:
obj->unk_8 = 0x2f;
break;
case -0x7e:
obj->unk_8 = 0x29;
break;
case -0x7f:
obj->unk_8 = 0x1f;
break;
case -0x77:
if (lbl_1_bss_960 == 3) {
obj->unk_8 = 0x4d;
} else {
obj->unk_8 = 0x4c;
}
break;
case -0x80:
obj->unk_8 = 2;
break;
case -0x7a:
obj->unk_8 = 3;
break;
default:
OSReport(str + 0x6d94, obj->unk_24 ->unk_4);
OSPanic(str + 0x6cf0, 0x5a3, str + 0x6da0);
break;
}
switch (obj->unk_2) {
case 2:
switch (obj->unk_24->unk_8 & 0xc03) {
case 0x802:
obj->unk_A = 0xf;
break;
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 4;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x15;
break;
default:
obj->unk_A = 4;
break;
}
break;
case 0:
case 1:
switch (obj->unk_24->unk_8 & 0x403) {
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 5;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x16;
break;
default:
obj->unk_A = 5;
break;
}
break;
case 3:
case 4:
switch (obj->unk_24->unk_8 & 0x403) {
case 0x800:
obj->unk_A = 0xf;
break;
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 6;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x17;
break;
default:
obj->unk_A = 6;
break;
}
break;
case 5:
switch (obj->unk_24->unk_8 & 0x403) {
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 7;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x18;
break;
default:
obj->unk_A = 7;
break;
}
break;
case 6:
switch (obj->unk_24->unk_8 & 0x403) {
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 8;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x19;
break;
default:
obj->unk_A = 8;
break;
}
break;
default:
OSPanic(str + 0x6cf0, 0x627, str + 0x6db8);
break;
}
obj->unk_2A |= 4;
obj->unk_24->unk_8 &= ~4;
obj->unk_24->unk_2 = 0;
}
/* fzgx:end fn_1_AAF1C */

/* fzgx:begin fn_1_AB434 */
// fn_1_AB434: empty in retail (single blr).
void fn_1_AB434(void) {
}
/* fzgx:end fn_1_AB434 */

/* fzgx:begin fn_1_AB438 */
typedef struct Fn1AB438Data {
    u8 pad_00[8];
    s16 field_08;
    s16 field_0A;
    u8 pad_0C[0x1e];
    u8 field_2A;
} Fn1AB438Data;

void fn_1_AB438(Fn1AB438Data *data) {
    data->field_08 = 30;
    data->field_0A = 14;
    data->field_2A |= 4;
}
/* fzgx:end fn_1_AB438 */

/* fzgx:begin fn_1_AB458 */
// fn_1_AB458: empty in retail (single blr).
void fn_1_AB458(void) {
}
/* fzgx:end fn_1_AB458 */

/* fzgx:begin fn_1_AB45C */
void fn_1_AB45C(int index) {
    lbl_1_bss_716C8[index * 0xa0 + 7] = 1;
}
/* fzgx:end fn_1_AB45C */
