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

/* fzgx:begin fn_1_A861C noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "types.h"

/* begin game/main_rel/driver_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_DRIVER_TYPES_H
#define GAME_MAIN_REL_DRIVER_TYPES_H

// Types (and the externs that name them) of driver.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} DriverAsset;

struct fn_1_A7F84_lbl_1_rodata_4A28 {
    f32 unk_0;
};

typedef struct FnA8528Config {
    u8 pad_0c[0x0c];
    f32 unk_0c;
    u8 pad_10[0x0c];
    f32 unk_1c;
    u8 pad_20[0x0c];
    f32 unk_2c;
} FnA8528Config;

struct fn_1_A7F84_lbl_801A6D00 {
    u32 unk_0;
};

struct fn_1_A9868_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct FnA861CCamera {
    u8 pad_0[0xdc];
    f32 yaw;      /* 0xdc */
    f32 roll;     /* 0xe0 */
    f32 pitch;    /* 0xe4 */
    u8 unk_e8;
    u8 unk_e9;
    u8 pad_ea[0x15c - 0xea];
    u8 unk_15c[4];
} FnA861CCamera;

typedef struct {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format_MkVaListState;

typedef Sig_parse_format_MkVaListState Sig_parse_format_va_list;

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

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SHARED_TYPES_H
#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so
// the TU headers can be included together. Hand-owned (librarian).


typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

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

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

struct FzgxCopy_88 { u32 words[22]; };

#endif  // GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/shared_types.h */

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

typedef struct FnA861CVehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xb8 - 0xb4];
    f32 unk_b8;
    u8 pad_bc[0xc0 - 0xbc];
    f32 unk_c0;
} FnA861CVehicle;

typedef struct FnA8834Camera {
    u8 pad_0[0x90];
    u8 unk_90[0x48];
    f32 unk_d8;
    f32 unk_dc;
    u8 pad_e0[4];
    f32 unk_e4;
    u8 pad_e8[0x18c - 0xe8];
    u8 unk_18c[4];
} FnA8834Camera;

typedef struct FnA8834Vehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xc0 - 0xb4];
    f32 unk_c0;
    u8 pad_c4[0x1fc - 0xc4];
    f32 unk_1fc;
} FnA8834Vehicle;

extern struct fn_1_A7F84_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern FnA8528Config *lbl_801A6D00;
extern Fn1A9250Entry lbl_1_bss_70658[];
extern struct fn_1_A9868_lbl_1_rodata_4AA0 lbl_1_rodata_4AA0;
extern f32 fn_80015EE8(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *, s32, f32);
extern void fn_1_A861C(FnA861CCamera *cam, FnA861CVehicle *veh);
extern void fn_1_A8834(FnA8834Camera *cam, FnA8834Vehicle *veh);

#endif  // GAME_MAIN_REL_DRIVER_TYPES_H

/* end game/main_rel/driver_types.h */

extern void fn_80006E10(u32 arg0);
extern s32 fn_1_12C930(s8);
extern s16 fn_1_12CCB0(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_D3884();
extern u32 fn_80077D40(void);
extern u32 fn_80071470(u32, u32);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80071718(void *value);
extern void fn_1_A8270(void *, void *);
extern void *lbl_801A6410;
extern u32 fn_1_4630();
extern void fn_1_A8528(void *, void *);
extern u32 lbl_8006D91C(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_x(u32);
extern u32 lbl_8006D998(u32);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DB74(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *pos);
extern void lbl_8006DB30(void);
extern void fn_1_A9420(u8 value);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_A948C(int);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_520A0(void);
extern void fn_1_52088(void);
extern u32 lbl_1_bss_71658[6];
extern const f64 lbl_1_rodata_4A98;
extern void fn_1_49714(f32 value1, f32 value2, f32 value3);
extern void fn_1_49680(f32 value1, f32 value2);
extern void fn_1_A93C4(u32 arg0);
extern void fn_1_4A0D8(void *);
extern void fn_1_520CC(void);
extern void fn_1_49514(u32 *value);
extern void (*lbl_1_bss_7168C)(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800720B0(u32);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern void fn_80038CFC(u32 value);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_8007245C(u32 value);
extern void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_80074660(u32 arg0);
extern void fn_800746A8();
extern void fn_80074718(u8 value, s32 arg);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void OSReport(const char *format, ...);
extern void fn_800711A8(void *value);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_A7E60(s32 arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void lbl_8006E0A4(void *arg0);
extern void fn_8006F6A8(void *arg0);
extern void fn_1_A89B0(void *arg0, void *arg1, s32 arg2);
extern void fn_1_3920(void);
extern void fn_1_A8D4C(void);
extern void fn_1_A8D64(void);
extern u32 fn_8001A78C(u32 arg0);
extern u32 fn_8001A7D0(u32 arg0);
extern void fn_1_A943C(u32 arg0, u32 arg1);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern void fn_1_A942C(u8 value);
extern void fn_1_A96BC(void);
extern void (*lbl_1_bss_7167C)(void);
extern void fn_1_A5C98(void *);
extern u8 lbl_1_bss_716C8[320];
extern void (*lbl_1_bss_71680)(void);
extern u32 fn_1_451C(void);
extern void fn_1_A5AA0(void *buffer, void *destination);
extern u32 lbl_1_bss_71670;
extern void (*lbl_1_bss_71684)(void);
extern void (*lbl_1_bss_71688)(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern f32 lbl_1_rodata_4AC4[4];
extern void fn_8003462C(u32, u32, u32);

/* The TU's shared literal pool (lbl_1_rodata_4A28 .. +0x40) in retail order, so the
 * function's own literals dedupe onto retail's displacements. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime_a861c(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
    s = -0.1f;
    s = 0.1f;
    s = 5.0f;
    s = 0.5f;
    s = 50.0f;
    s = 10.0f;
    s = 57.2957763671875f;
    s = -10.0f;
    s = 0.2f;
    s = -30.0f;
    s = 1.8518518209457397f;
    s = -1.8518518209457397f;
    s = 4.166666507720947f;
    s = 25.0f;
    s = 30.0f;
    s = 182.04444885253906f;
}
#pragma section code_type ".text"

void fn_1_A861C(FnA861CCamera *cam, FnA861CVehicle *veh)
{
    lbl_8006DBAC( (void *)(FnA861CCamera *)(cam));
    if (veh == NULL) {
        cam->pitch = 0.0f;
        cam->yaw = 0.0f;
        cam->roll = 0.0f;
    } else {
        f32 rad = -veh->unk_a4 / veh->unk_b0;
        f32 turn = 0.5f * (veh->unk_b8 / veh->unk_8);
        f32 yaw = (f32)(50.0f * turn) + (f32)(10.0f * (57.2957763671875f * rad));
        f32 roll = -10.0f * (turn + 57.2957763671875f * rad);
        f32 lift;
        f32 limit;
        s32 locked;

        lift = veh->unk_c0 / veh->unk_8;

        cam->pitch += (f32)(0.2f * (f32)((f32)(-30.0f * ((lift < -1.8518518209457397f ? -(1.8518518209457397f + lift) : 0.0f) / 4.166666507720947f)) - cam->pitch));

        locked = 0;
        if (cam->unk_e9 != 0) {
            u8 state = cam->unk_e8;
            if (state == 0x21 || state == 0x2a || state == 0x2b) {
                locked = 1;
            }
        }
        limit = locked ? 0.0f : 25.0f;
        if (yaw > limit) {
            yaw = limit;
        } else if (yaw < -limit) {
            yaw = -limit;
        }
        cam->yaw += (f32)(0.2f * (yaw - cam->yaw));

        if (roll > 30.0f) {
            roll = 30.0f;
        } else if (roll < -30.0f) {
            roll = -30.0f;
        }
        cam->roll += (f32)(0.2f * (roll - cam->roll));
    }
    mathutil_mtxA_rotate_z((s32)(182.04444885253906f * cam->pitch));
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * cam->yaw));
    mathutil_mtxA_rotate_x((s32)(182.04444885253906f * cam->roll));
    lbl_8006DB74(cam->unk_15c);
}
/* fzgx:end fn_1_A861C */

/* fzgx:begin fn_1_A8834 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "types.h"

/* begin game/main_rel/driver_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_DRIVER_TYPES_H
#define GAME_MAIN_REL_DRIVER_TYPES_H

// Types (and the externs that name them) of driver.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} DriverAsset;

struct fn_1_A7F84_lbl_1_rodata_4A28 {
    f32 unk_0;
};

typedef struct FnA8528Config {
    u8 pad_0c[0x0c];
    f32 unk_0c;
    u8 pad_10[0x0c];
    f32 unk_1c;
    u8 pad_20[0x0c];
    f32 unk_2c;
} FnA8528Config;

struct fn_1_A7F84_lbl_801A6D00 {
    u32 unk_0;
};

struct fn_1_A9868_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct FnA861CCamera {
    u8 pad_0[0xdc];
    f32 yaw;      /* 0xdc */
    f32 roll;     /* 0xe0 */
    f32 pitch;    /* 0xe4 */
    u8 unk_e8;
    u8 unk_e9;
    u8 pad_ea[0x15c - 0xea];
    u8 unk_15c[4];
} FnA861CCamera;

typedef struct {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format_MkVaListState;

typedef Sig_parse_format_MkVaListState Sig_parse_format_va_list;

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

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SHARED_TYPES_H
#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so
// the TU headers can be included together. Hand-owned (librarian).


typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

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

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

struct FzgxCopy_88 { u32 words[22]; };

#endif  // GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/shared_types.h */

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

typedef struct FnA861CVehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xb8 - 0xb4];
    f32 unk_b8;
    u8 pad_bc[0xc0 - 0xbc];
    f32 unk_c0;
} FnA861CVehicle;

typedef struct FnA8834Camera {
    u8 pad_0[0x90];
    u8 unk_90[0x48];
    f32 unk_d8;
    f32 unk_dc;
    u8 pad_e0[4];
    f32 unk_e4;
    u8 pad_e8[0x18c - 0xe8];
    u8 unk_18c[4];
} FnA8834Camera;

typedef struct FnA8834Vehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xc0 - 0xb4];
    f32 unk_c0;
    u8 pad_c4[0x1fc - 0xc4];
    f32 unk_1fc;
} FnA8834Vehicle;

extern struct fn_1_A7F84_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern FnA8528Config *lbl_801A6D00;
extern Fn1A9250Entry lbl_1_bss_70658[];
extern struct fn_1_A9868_lbl_1_rodata_4AA0 lbl_1_rodata_4AA0;
extern f32 fn_80015EE8(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *, s32, f32);
extern void fn_1_A861C(FnA861CCamera *cam, FnA861CVehicle *veh);
extern void fn_1_A8834(FnA8834Camera *cam, FnA8834Vehicle *veh);

#endif  // GAME_MAIN_REL_DRIVER_TYPES_H

/* end game/main_rel/driver_types.h */

extern void fn_80006E10(u32 arg0);
extern s32 fn_1_12C930(s8);
extern s16 fn_1_12CCB0(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_D3884();
extern u32 fn_80077D40(void);
extern u32 fn_80071470(u32, u32);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80071718(void *value);
extern void fn_1_A8270(void *, void *);
extern void *lbl_801A6410;
extern u32 fn_1_4630();
extern void fn_1_A8528(void *, void *);
extern u32 lbl_8006D91C(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_x(u32);
extern u32 lbl_8006D998(u32);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DB74(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *pos);
extern void lbl_8006DB30(void);
extern void fn_1_A9420(u8 value);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_A948C(int);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_520A0(void);
extern void fn_1_52088(void);
extern u32 lbl_1_bss_71658[6];
extern const f64 lbl_1_rodata_4A98;
extern void fn_1_49714(f32 value1, f32 value2, f32 value3);
extern void fn_1_49680(f32 value1, f32 value2);
extern void fn_1_A93C4(u32 arg0);
extern void fn_1_4A0D8(void *);
extern void fn_1_520CC(void);
extern void fn_1_49514(u32 *value);
extern void (*lbl_1_bss_7168C)(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800720B0(u32);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern void fn_80038CFC(u32 value);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_8007245C(u32 value);
extern void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_80074660(u32 arg0);
extern void fn_800746A8();
extern void fn_80074718(u8 value, s32 arg);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void OSReport(const char *format, ...);
extern void fn_800711A8(void *value);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_A7E60(s32 arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void lbl_8006E0A4(void *arg0);
extern void fn_8006F6A8(void *arg0);
extern void fn_1_A89B0(void *arg0, void *arg1, s32 arg2);
extern void fn_1_3920(void);
extern void fn_1_A8D4C(void);
extern void fn_1_A8D64(void);
extern u32 fn_8001A78C(u32 arg0);
extern u32 fn_8001A7D0(u32 arg0);
extern void fn_1_A943C(u32 arg0, u32 arg1);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern void fn_1_A942C(u8 value);
extern void fn_1_A96BC(void);
extern void (*lbl_1_bss_7167C)(void);
extern void fn_1_A5C98(void *);
extern u8 lbl_1_bss_716C8[320];
extern void (*lbl_1_bss_71680)(void);
extern u32 fn_1_451C(void);
extern void fn_1_A5AA0(void *buffer, void *destination);
extern u32 lbl_1_bss_71670;
extern void (*lbl_1_bss_71684)(void);
extern void (*lbl_1_bss_71688)(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern f32 lbl_1_rodata_4AC4[4];
extern void fn_8003462C(u32, u32, u32);

/* The TU's shared literal pool (lbl_1_rodata_4A28 .. +0x58) in retail order, so the
 * function's own literals dedupe onto retail's displacements. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
    s = -0.1f;
    s = 0.1f;
    s = 5.0f;
    s = 0.5f;
    s = 50.0f;
    s = 10.0f;
    s = 57.2957763671875f;
    s = -10.0f;
    s = 0.2f;
    s = -30.0f;
    s = 1.8518518f;
    s = -1.8518518f;
    s = 4.166666507720947f;
    s = 25.0f;
    s = 30.0f;
    s = 182.04444885253906f;
    s = 0.46296295523643494f;
    s = 1.0f;
    s = 15.0f;
    s = 45.0f;
    s = -45.0f;
    s = 0.75f;
}
#pragma section code_type ".text"

void fn_1_A8834(FnA8834Camera *cam, FnA8834Vehicle *veh) {
    lbl_8006DAEC();
    if (veh == NULL) {
        cam->unk_d8 = 0.0f;
    } else {
        f32 lateral;
        f32 speed;
        f32 yaw;
        f32 roll;

        lateral = -veh->unk_a4 / veh->unk_b0;
        speed = -veh->unk_c0 / veh->unk_8;
        speed = speed - 0.46296295523643494f;
        if (speed < 0.0f) {
            speed = 0.0f;
        }
        speed = speed / 4.166666507720947f;
        if (speed > 1.0f) {
            speed = 1.0f;
        }
        yaw = 15.0f * (57.2957763671875f * lateral);
        speed = speed * (-30.0f * veh->unk_1fc);
        roll = yaw + speed;
        if (roll > 45.0f) {
            roll = 45.0f;
        } else if (roll < -45.0f) {
            roll = -45.0f;
        }
        cam->unk_d8 = cam->unk_d8 + (f32)(0.1f * (roll - cam->unk_d8));
    }
    lbl_8006DFC4(cam->unk_90);
    mathutil_mtxA_rotate_x((s32)(182.04444885253906f * (0.75f * cam->unk_dc)));
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * cam->unk_e4));
    mathutil_mtxA_rotate_z((s32)(182.04444885253906f * cam->unk_d8));
    lbl_8006DB74(cam->unk_18c);
    lbl_8006DB30();
}
/* fzgx:end fn_1_A8834 */

/* fzgx:begin fn_1_A89B0 noprologue */
#include "types.h"
#include "psvec.h"

typedef f32 fzgx_Mtx[3][4];
typedef struct { f32 x, y, z; } fzgx_Vec;

typedef struct fn_1_A89B0_Obj {
    fzgx_Mtx mtx;           /* 0x000 */
    fzgx_Vec pos[2][4];     /* 0x030, 0x060 */
    u8 pad_90[0xC0 - 0x90];
    fzgx_Vec ofs[2];        /* 0x0C0, 0x0CC */
    u8 pad_d8[0x10C - 0xD8];
    f32 len1;               /* 0x10C */
    f32 len2;               /* 0x110 */
    u8 pad_114[0x12C - 0x114];
    fzgx_Mtx joints[7];     /* 0x12C */
} fn_1_A89B0_Obj;

typedef struct fn_1_A89B0_Arg1 {
    u8 pad_0[0x1FC];
    f32 unk_1FC;
} fn_1_A89B0_Arg1;

extern fzgx_Mtx *lbl_801A6D00;

extern void lbl_8006DAEC(void);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D668(void *);
extern u32 fn_1_44884(void *);

/* primes the shared literal pool lbl_1_rodata_4A28 in retail order */
#pragma section code_type ".fzgxpool"
void fzgx_pool_A89B0(f32 *o) {
    o[0] = 0.0f;
    o[1] = -0.1f;
    o[2] = 0.1f;
    o[3] = 5.0f;
    o[4] = 0.5f;
    o[5] = 50.0f;
    o[6] = 10.0f;
    o[7] = 57.295776f;
    o[8] = -10.0f;
    o[9] = 0.2f;
    o[10] = -30.0f;
    o[11] = 1.8518518f;
    o[12] = -1.8518518f;
    o[13] = 4.1666667f;
    o[14] = 25.0f;
    o[15] = 30.0f;
    o[16] = 182.04445f;
    o[17] = 0.46296296f;
    o[18] = 1.0f;
    o[19] = 15.0f;
    o[20] = 45.0f;
    o[21] = -45.0f;
    o[22] = 0.75f;
    o[23] = 0.05f;
    o[24] = -0.05f;
    o[25] = -60.0f;
    o[26] = 0.02f;
    o[27] = 2.0f;
}
#pragma section code_type ".text"

#define MTXA ((f32 (*)[4])0xE0000000)

/* Keep the source translation loads ordered before locked-cache writes. */
static inline void mtxA_set_translate(volatile fzgx_Vec *p) {
    MTXA[0][3] = p->x;
    MTXA[1][3] = p->y;
    MTXA[2][3] = p->z;
}

static inline void mtxA_translate_x(f32 scale) {
    f32 x;
    f32 y;
    f32 z;
    x = MTXA[0][0];
    y = MTXA[1][0];
    z = MTXA[2][0];
    x = x * scale + MTXA[0][3];
    y = y * scale + MTXA[1][3];
    z = z * scale + MTXA[2][3];
    MTXA[0][3] = x;
    MTXA[1][3] = y;
    MTXA[2][3] = z;
}
#pragma opt_propagation off
#pragma opt_lifetimes off

void fn_1_A89B0(fn_1_A89B0_Obj *obj, fn_1_A89B0_Arg1 *arg1, s32 side) {
    fzgx_Vec tip;
    fzgx_Vec dir;
    fzgx_Vec bend;
    fzgx_Vec mid;
    f32 tz;
    f32 ty;
    f32 tx;
    f32 a;
    f32 b;
    f32 scale;
    f32 *vec;
    fzgx_Vec *ofs;
    s32 j1;
    s32 j2;
    f32 *m2;
    f32 v;
    f32 r1sq;
    f32 x;
    f32 y;
    f32 r1;
    f32 lenDiff;
    f32 dist;
    f32 distsq;
    f32 tipz;
    f32 tipy;
    f32 delta;

    if (arg1 != NULL) {
        v = arg1->unk_1FC;
    } else {
        v = 0.0f;
    }
    if (side != 0) {
        vec = &obj->pos[0][0].x;
        scale = 0.05f;
        ofs = &obj->ofs[0];
        j1 = 3;
        j2 = 4;
        if (v > 0.0f) {
            a = v;
            b = 0.0f;
        } else {
            a = 0.0f;
            b = v;
        }
    } else {
        vec = &obj->pos[1][0].x;
        scale = -0.05f;
        ofs = &obj->ofs[1];
        j1 = 5;
        j2 = 6;
        if (v > 0.0f) {
            a = 0.0f;
            b = v;
        } else {
            a = v;
            b = 0.0f;
        }
    }

    lbl_8006DAEC();
    mathutil_mtxA_rotate_x((s32)(182.04445f * (25.0f * b)));
    lbl_8006DFC4(vec);
    mathutil_mtxA_rotate_x((s32)(182.04445f * (25.0f * a)));
    vec = &obj->joints[j1][0][0];
    lbl_8006DB74(vec);

    lbl_8006D758();
    /* Keep the source translation loads ordered before locked-cache writes. */
    tx = *(volatile f32 *)&ofs->x;
    ty = ofs->y;
    tz = ofs->z;
    MTXA[0][3] = tx;
    MTXA[1][3] = ty;
    MTXA[2][3] = tz;
    mtxA_translate_x(scale);
    mathutil_mtxA_rotate_z((s32)(182.04445f * (-60.0f * v)));
    lbl_8006E0B4(-scale, 0.0f, 0.02f);
    psvec_set(&tip.x, MTXA[2][3], MTXA[1][3], MTXA[0][3]);
    m2 = &obj->joints[j2][0][0];
    lbl_8006DBAC(vec);

    tipy = tip.y;
    tipz = tip.z;
    distsq = tip.x;
    dir.x = delta = distsq - (*lbl_801A6D00)[0][3];
    distsq = (f32)(delta * delta);
    dir.y = delta = tipy - (*lbl_801A6D00)[1][3];
    distsq = delta * delta + distsq;
    dir.z = delta = tipz - (*lbl_801A6D00)[2][3];
    dist = lbl_8006D0B4(delta * delta + distsq);
    lbl_8006D668(&dir);
    fn_1_44884(&dir);

    r1 = obj->len1;
    r1sq = r1 * r1;
    lenDiff = r1sq - (f32)(obj->len2 * obj->len2);
    x = (lenDiff + (f32)(dist * dist)) / (2.0f * dist);
    if (r1 > x) {
        distsq = lbl_8006D0B4(r1sq - (f32)(x * x));
    } else {
        distsq = 0.0f;
        x = r1;
    }
    y = -distsq;
    lbl_8006E1F0(&bend, x, y, 0.0f);
    mid.x = vec[3] + bend.x;
    mid.y = vec[7] + bend.y;
    mid.z = vec[11] + bend.z;
    lbl_8006D668(&bend);
    fn_1_44884(&bend);
    lbl_8006DB74(vec);

    bend.x = tip.x - mid.x;
    bend.y = tip.y - mid.y;
    bend.z = tip.z - mid.z;
    lbl_8006D668(&bend);
    fn_1_44884(&bend);
    mtxA_set_translate(&mid);
    lbl_8006DB74(m2);
    lbl_8006DB30();
}
/* fzgx:end fn_1_A89B0 */

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

/* fzgx:begin fn_1_A8FA0 noprologue */
#include "types.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    u8 pad_A[2];
    char *name;
} fn_1_A8FA0_Entry;

typedef struct {
    u8 pad_0[0xC];
    char *strPtr;
} fn_1_A8FA0_Header;

extern char *fn_80083DB0(char *, const char *);
extern size_t strlen(const char *);

/* lbl_1_bss_6F648 heads a cluster of this TU's .bss objects addressed off one base */
static fn_1_A8FA0_Header lbl_1_bss_6F648;
static char lbl_1_bss_6F648__fzgx_offset_10[0x1000];
static fn_1_A8FA0_Entry lbl_1_bss_70658__fzgx_offset_0[0x100];
static s32 lbl_1_bss_71658__fzgx_offset_0;

void fn_1_A8FA0(void) {
    s32 dup[0x100];
    s32 i;
    s32 n;
    size_t len;
    char *name;
    s32 j;

    lbl_1_bss_6F648.strPtr = lbl_1_bss_6F648__fzgx_offset_10;
    n = 0;
    for (i = 0; i < lbl_1_bss_71658__fzgx_offset_0; i++) {
        if (lbl_1_bss_70658__fzgx_offset_0[i].unk_2 & 1) {
            name = lbl_1_bss_70658__fzgx_offset_0[i].name;
            len = strlen(name);
            if (i != 0) {
                lbl_1_bss_70658__fzgx_offset_0[n] = lbl_1_bss_70658__fzgx_offset_0[i];
                fn_80083DB0(lbl_1_bss_6F648.strPtr, name);
            }
            lbl_1_bss_70658__fzgx_offset_0[n].name = lbl_1_bss_6F648.strPtr;
            n++;
            lbl_1_bss_6F648.strPtr += len + 1;
        }
    }
    lbl_1_bss_71658__fzgx_offset_0 = n;

    for (i = n - 1; i >= 0; i--) {
        dup[i] = 0;
    }

    for (i = n - 1; i >= 1; i--) {
        if (dup[i] == 0) {
            for (j = i - 1; j >= 0; j--) {
                if (lbl_1_bss_70658__fzgx_offset_0[i].unk_4 == lbl_1_bss_70658__fzgx_offset_0[j].unk_4 &&
                    lbl_1_bss_70658__fzgx_offset_0[i].unk_6 == lbl_1_bss_70658__fzgx_offset_0[j].unk_6 &&
                    lbl_1_bss_70658__fzgx_offset_0[i].unk_2 == lbl_1_bss_70658__fzgx_offset_0[j].unk_2 &&
                    lbl_1_bss_70658__fzgx_offset_0[i].unk_0 == lbl_1_bss_70658__fzgx_offset_0[j].unk_0) {
                    dup[j] = 1;
                }
            }
        }
    }

    lbl_1_bss_6F648.strPtr = lbl_1_bss_6F648__fzgx_offset_10;
    n = 0;
    for (i = 0; i < lbl_1_bss_71658__fzgx_offset_0; i++) {
        if (dup[i] == 0) {
            len = strlen(lbl_1_bss_70658__fzgx_offset_0[i].name);
            name = lbl_1_bss_70658__fzgx_offset_0[i].name;
            if (i != 0) {
                lbl_1_bss_70658__fzgx_offset_0[n] = lbl_1_bss_70658__fzgx_offset_0[i];
                fn_80083DB0(lbl_1_bss_6F648.strPtr, name);
            }
            lbl_1_bss_70658__fzgx_offset_0[n].name = lbl_1_bss_6F648.strPtr;
            n++;
            lbl_1_bss_6F648.strPtr += len + 1;
        }
    }
    lbl_1_bss_71658__fzgx_offset_0 = n;
}
/* fzgx:end fn_1_A8FA0 */

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

/* fzgx:begin fn_1_AA350 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "types.h"
#include "dolphin/hw_regs.h"
#include "types.h"
#include "rel/main_rel/driver.h"

/* begin game/main_rel/driver_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_DRIVER_TYPES_H
#define GAME_MAIN_REL_DRIVER_TYPES_H

// Types (and the externs that name them) of driver.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} DriverAsset;

struct fn_1_A7F84_lbl_1_rodata_4A28 {
    f32 unk_0;
};

typedef struct FnA8528Config {
    u8 pad_0c[0x0c];
    f32 unk_0c;
    u8 pad_10[0x0c];
    f32 unk_1c;
    u8 pad_20[0x0c];
    f32 unk_2c;
} FnA8528Config;

struct fn_1_A7F84_lbl_801A6D00 {
    u32 unk_0;
};

struct fn_1_A9868_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct FnA861CCamera {
    u8 pad_0[0xdc];
    f32 yaw;      /* 0xdc */
    f32 roll;     /* 0xe0 */
    f32 pitch;    /* 0xe4 */
    u8 unk_e8;
    u8 unk_e9;
    u8 pad_ea[0x15c - 0xea];
    u8 unk_15c[4];
} FnA861CCamera;

typedef struct {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format_MkVaListState;

typedef Sig_parse_format_MkVaListState Sig_parse_format_va_list;

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

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SHARED_TYPES_H
#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so
// the TU headers can be included together. Hand-owned (librarian).


typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

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

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

struct FzgxCopy_88 { u32 words[22]; };

#endif  // GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/shared_types.h */

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

typedef struct FnA861CVehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xb8 - 0xb4];
    f32 unk_b8;
    u8 pad_bc[0xc0 - 0xbc];
    f32 unk_c0;
} FnA861CVehicle;

typedef struct FnA8834Camera {
    u8 pad_0[0x90];
    u8 unk_90[0x48];
    f32 unk_d8;
    f32 unk_dc;
    u8 pad_e0[4];
    f32 unk_e4;
    u8 pad_e8[0x18c - 0xe8];
    u8 unk_18c[4];
} FnA8834Camera;

typedef struct FnA8834Vehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xc0 - 0xb4];
    f32 unk_c0;
    u8 pad_c4[0x1fc - 0xc4];
    f32 unk_1fc;
} FnA8834Vehicle;

extern struct fn_1_A7F84_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern FnA8528Config *lbl_801A6D00;
extern Fn1A9250Entry lbl_1_bss_70658[];
extern struct fn_1_A9868_lbl_1_rodata_4AA0 lbl_1_rodata_4AA0;
extern f32 fn_80015EE8(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *, s32, f32);
extern void fn_1_A861C(FnA861CCamera *cam, FnA861CVehicle *veh);
extern void fn_1_A8834(FnA8834Camera *cam, FnA8834Vehicle *veh);

#endif  // GAME_MAIN_REL_DRIVER_TYPES_H

/* end game/main_rel/driver_types.h */

extern void fn_80006E10(u32 arg0);
extern s32 fn_1_12C930(s8);
extern s16 fn_1_12CCB0(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_D3884();
extern u32 fn_80077D40(void);
extern u32 fn_80071470(u32, u32);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80071718(void *value);
extern void fn_1_A8270(void *, void *);
extern void *lbl_801A6410;
extern u32 fn_1_4630();
extern void fn_1_A8528(void *, void *);
extern u32 lbl_8006D91C(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_x(u32);
extern u32 lbl_8006D998(u32);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DB74(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *pos);
extern void lbl_8006DB30(void);
extern void fn_1_A9420(u8 value);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_A948C(int);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_520A0(void);
extern void fn_1_52088(void);
extern u32 lbl_1_bss_71658[6];
extern const f64 lbl_1_rodata_4A98;
extern void fn_1_49714(f32 value1, f32 value2, f32 value3);
extern void fn_1_49680(f32 value1, f32 value2);
extern void fn_1_A93C4(u32 arg0);
extern void fn_1_4A0D8(void *);
extern void fn_1_520CC(void);
extern void fn_1_49514(u32 *value);
extern void (*lbl_1_bss_7168C)(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800720B0(u32);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern void fn_80038CFC(u32 value);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_8007245C(u32 value);
extern void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_80074660(u32 arg0);
extern void fn_800746A8();
extern void fn_80074718(u8 value, s32 arg);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void OSReport(const char *format, ...);
extern void fn_800711A8(void *value);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_A7E60(s32 arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void lbl_8006E0A4(void *arg0);
extern void fn_8006F6A8(void *arg0);
extern void fn_1_A89B0(void *arg0, void *arg1, s32 arg2);
extern void fn_1_3920(void);
extern void fn_1_A8D4C(void);
extern void fn_1_A8D64(void);
extern u32 fn_8001A78C(u32 arg0);
extern u32 fn_8001A7D0(u32 arg0);
extern void fn_1_A943C(u32 arg0, u32 arg1);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern void fn_1_A942C(u8 value);
extern void fn_1_A96BC(void);
extern void (*lbl_1_bss_7167C)(void);
extern void fn_1_A5C98(void *);
extern u8 lbl_1_bss_716C8[320];
extern void (*lbl_1_bss_71680)(void);
extern u32 fn_1_451C(void);
extern void fn_1_A5AA0(void *buffer, void *destination);
extern u32 lbl_1_bss_71670;
extern void (*lbl_1_bss_71684)(void);
extern void (*lbl_1_bss_71688)(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern f32 lbl_1_rodata_4AC4[4];
extern void fn_8003462C(u32, u32, u32);


#define WG_F32 (*(volatile f32 *)(GX_FIFO_BASE + 0x0)) /* Hardware access must remain ordered. */
#define WG_U8 (*(volatile u8 *)(GX_FIFO_BASE + 0x0)) /* Hardware access must remain ordered. */

static inline void pos3(f32 x, f32 y) {
    WG_F32 = x;
    WG_F32 = y;
    WG_F32 = lbl_1_rodata_4AC4[0];
}

static inline void col4(u8 r, u8 g, u8 b, u8 a) {
    WG_U8 = r;
    WG_U8 = g;
    WG_U8 = b;
    WG_U8 = a;
}

static inline u16 fn_1_AA350_array_read(s32 index, u8 *array) { return array[index]; }
void fn_1_AA350(s16 *a, s16 *b, u8 *c, u32 n) {
    u32 i;
    if ((s32)lbl_1_bss_71690.unk_0 != 0) {
        fn_8003462C(0x98, 0, (u16)n);
        for (i = 0; i < n; i++) {
            pos3((f32)*a++, (f32)*b++);
            col4(fn_1_AA350_array_read(0, c), fn_1_AA350_array_read(1, c), fn_1_AA350_array_read(2, c), fn_1_AA350_array_read(3, c));
            c += 4;
        }
    }
}
/* fzgx:end fn_1_AA350 */

/* fzgx:begin fn_1_AA538 */
// Initialize the shared rendering state and submit the associated configuration.
void fn_1_AA538(void) {
    Obj_1_bss_71690 *state = (Obj_1_bss_71690 *)&lbl_1_bss_71690;

    fn_1_A7024(state->unk_4, state->unk_8, state->unk_C, state->unk_10);
    fn_80074918(1, 3, 1);
    state->unk_0 = 1;
}
/* fzgx:end fn_1_AA538 */

/* fzgx:begin fn_1_AA590 */
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


typedef struct Ent {
    u8 a0; s8 a1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7;
    s16 s8_; s16 sa; s32 c; u8 pad10[0x14];
    s32 w24; u8 pad28[2]; u8 b2a; s8 b2b; s32 w2c0;
    s32 w30; f32 f34; f32 f38; s32 w3c; s32 w40; u8 pad44[4];
    s32 w48; s32 w4c; s32 w50; u8 pad54[0x4c];
} Ent;

typedef struct G {
    u8 pad0[8];
    Ent e[2];
    s32 n148; s32 n14c;
    Ent c;
    u8 b1f0; u8 b1f1; u8 b1f2; u8 pad1f3;
    s32 w1f4; u8 b1f8; u8 b1f9; u8 pad1fa[2];
    s32 w1fc; void *p200;
    u8 pad204[0x5c00 - 0x204];
    s32 n5c00; s32 n5c04;
} G;

extern const f32 lbl_1_rodata_4CA8;
extern u32 fn_1_C3378(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_716C0[2];
Ent fzgx_obj_lbl_1_bss_716C8[2];
s32 fzgx_obj_lbl_1_bss_71808;
s32 lbl_1_bss_7180C;
Ent lbl_1_bss_71810;
u8 lbl_1_bss_71810__fzgx_offset_A0;
u8 fzgx_obj_lbl_1_bss_718B1;
u8 fzgx_pool_lbl_1_bss_716C0_gap_718B2;
u8 fzgx_pool_lbl_1_bss_716C0_gap_718B2_fill_718B3;
s32 fzgx_obj_lbl_1_bss_718B4;
u8 lbl_1_bss_718B8;
u8 lbl_1_bss_718B9;
u16 lbl_1_bss_718B9__fzgx_offset_1;
s32 lbl_1_bss_718B9__fzgx_offset_3;
void *fzgx_obj_lbl_1_bss_718C0;
u32 lbl_1_bss_718C0__fzgx_offset_4[7];
u8 fzgx_obj_lbl_1_bss_718E0;
u8 lbl_1_bss_718E0__fzgx_offset_1;
u16 lbl_1_bss_718E0__fzgx_offset_2;
u32 lbl_1_bss_718E0__fzgx_offset_4[5751];
s32 lbl_1_bss_718E0__fzgx_offset_59E0[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_71808;
    s = *(u8 *)&lbl_1_bss_7180C;
    s = *(u8 *)&lbl_1_bss_71810;
    s = *(u8 *)&lbl_1_bss_71810__fzgx_offset_A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718B1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_716C0_gap_718B2;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_716C0_gap_718B2_fill_718B3;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718B4;
    s = *(u8 *)&lbl_1_bss_718B8;
    s = *(u8 *)&lbl_1_bss_718B9;
    s = *(u8 *)&lbl_1_bss_718B9__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_718B9__fzgx_offset_3;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718C0;
    s = *(u8 *)&lbl_1_bss_718C0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718E0;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_59E0;
}
#pragma section code_type ".text"

void fn_1_AA590(void)
{
    
    int i;
    Ent *e = fzgx_obj_lbl_1_bss_716C8;
    fzgx_obj_lbl_1_bss_71808 = 0;
    lbl_1_bss_7180C = 1;
    for (i = 0; i < 2; i++, e++) {
        e->c = 0;
        e->w24 = 0;
        e->a0 = i;
        e->b2 = 0xff; e->b3 = 0xff; e->b4 = 0xff; e->b5 = 0xff; e->b6 = 0xff;
        e->b7 = 0;
        e->s8_ = -1;
        e->sa = -1;
        e->w30 = 0;
        e->f34 = lbl_1_rodata_4CA8;
        e->f38 = lbl_1_rodata_4CA8;
        e->b2a = 0;
        e->a1 = -3;
        e->b2b = -3;
        e->w3c = -1;
        e->w40 = -1;
        e->w4c = 0;
        e->w48 = 0;
        e->w50 = 0;
    }
    lbl_1_bss_71810 = fzgx_obj_lbl_1_bss_716C8[0];
    lbl_1_bss_71810.a0 = 2;
    lbl_1_bss_71810__fzgx_offset_A0 = 0xff;
    fzgx_obj_lbl_1_bss_718B1 = 5;
    fzgx_pool_lbl_1_bss_716C0_gap_718B2 = 0xff;
    fzgx_obj_lbl_1_bss_718B4 = 0;
    lbl_1_bss_718B8 = 0;
    lbl_1_bss_718B9 = 0;
    lbl_1_bss_718B9__fzgx_offset_3 = 0;
    fn_1_C3378();
    fzgx_obj_lbl_1_bss_718C0 = (u8 *)&fzgx_obj_lbl_1_bss_718E0 + 0x55c2;
    lbl_1_data_3C1E4 = 100;
    lbl_1_bss_718E0__fzgx_offset_59E0[0] = -1;
    lbl_1_bss_718E0__fzgx_offset_59E0[1] = -1;
}
/* fzgx:end fn_1_AA590 */

/* fzgx:begin fn_1_AA6D8 */
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


typedef struct DriverDesc {
    u8 pad_0[0x40];
    u32 unk_40;
    s32 unk_44;
    u32 unk_48;
} DriverDesc; /* 0x4C */

typedef struct DriverSub {
    s32 unk_0;
    u8 unk_4;
    u8 pad_5[0x3];
    DriverDesc *unk_8;
    u8 pad_C[0x20];
    u32 unk_2C;
} DriverSub; /* 0x30 */

typedef struct DriverObj {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x7C];
    DriverDesc *unk_8C;
    u8 pad_90[0x4];
    DriverSub *unk_94;
    char unk_98[0x20];
    u32 unk_B8;
    char unk_BC[0x24];
    s32 unk_E0;
    u32 unk_E4;
    u32 unk_E8;
} DriverObj;

typedef struct DriverParam {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u8 pad_8[0x4];
    DriverSub *unk_C;
    u32 unk_10;
    char *unk_14;
    char *unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
} DriverParam;

typedef struct DriverEntry {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    u8 pad_3[0x21];
    DriverObj *unk_24;
    u8 pad_28[0x78];
} DriverEntry; /* 0xA0 */

typedef struct DriverState {
    u8 unk_0;
    u8 pad_1[0x7];
    DriverEntry unk_8[2];
    u8 pad_148[0x8];
    DriverEntry unk_150;
    u8 pad_1F0;
    u8 unk_1F1;
    u8 unk_1F2;
    u8 pad_1F3[0x5];
    u8 unk_1F8;
    u8 unk_1F9;
    u8 pad_1FA[0x5A0E];
    char unk_5C08[0x20];
} DriverState;

typedef void (*DriverFunc)(DriverParam *, DriverEntry *);

/* View of driver.c's .data block from lbl_1_data_35AC8. */
typedef struct DriverData {
    u8 pad_0[0x6B68];
    DriverFunc handlers[0x62];
    char file[0xC];
    char suffix[0x4];
} DriverData;

extern DriverDesc lbl_1_rodata_4AE0[];
extern void *lbl_801A6410;

extern void *fn_1_4630(void *heap, u32 size, const char *file, u32 line);
extern void *fn_1_45D0(void *heap, u32 size, const char *file, u32 line);
extern char *fn_80083DB0(char *, const char *);
extern unsigned long strlen(const char *);
extern char *fn_80083CF4(char *, const char *, unsigned long);
extern char *strcat(char *, const char *);
extern void fn_80008BEC(void *, int, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_716C0;
u8 lbl_1_bss_716C0__fzgx_offset_1;
u16 lbl_1_bss_716C0__fzgx_offset_2;
u32 lbl_1_bss_716C0__fzgx_offset_4;
DriverEntry fzgx_obj_lbl_1_bss_716C8[2];
u32 fzgx_obj_lbl_1_bss_71808;
u32 lbl_1_bss_7180C;
DriverEntry lbl_1_bss_71810;
u8 lbl_1_bss_71810__fzgx_offset_A0;
u8 fzgx_obj_lbl_1_bss_718B1;
u8 fzgx_pool_lbl_1_bss_716C0_gap_718B2;
u8 fzgx_pool_lbl_1_bss_716C0_gap_718B2_fill_718B3;
u32 fzgx_obj_lbl_1_bss_718B4;
u8 lbl_1_bss_718B8;
u8 lbl_1_bss_718B9;
u16 lbl_1_bss_718B9__fzgx_offset_1;
u32 lbl_1_bss_718B9__fzgx_offset_3;
u32 fzgx_obj_lbl_1_bss_718C0[8];
u32 fzgx_obj_lbl_1_bss_718E0[5754];
char lbl_1_bss_772C8[0x20];
u32 lbl_1_bss_772C8__fzgx_offset_20[8];
u16 lbl_1_bss_772C8__fzgx_offset_40;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C0;
    s = *(u8 *)&lbl_1_bss_716C0__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_716C0__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_716C0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_71808;
    s = *(u8 *)&lbl_1_bss_7180C;
    s = *(u8 *)&lbl_1_bss_71810;
    s = *(u8 *)&lbl_1_bss_71810__fzgx_offset_A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718B1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_716C0_gap_718B2;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_716C0_gap_718B2_fill_718B3;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718B4;
    s = *(u8 *)&lbl_1_bss_718B8;
    s = *(u8 *)&lbl_1_bss_718B9;
    s = *(u8 *)&lbl_1_bss_718B9__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_718B9__fzgx_offset_3;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718E0;
    s = *(u8 *)&lbl_1_bss_772C8;
    s = *(u8 *)&lbl_1_bss_772C8__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_772C8__fzgx_offset_40;
}
#pragma section code_type ".text"

extern u8 fn_1_AAEB0__fzgx_offset_0[];
extern u8 fn_1_AAF18__fzgx_offset_0[];
extern u8 fn_1_AAF1C__fzgx_offset_0[];
extern u8 fn_1_AB434__fzgx_offset_0[];
extern u8 fn_1_AB438__fzgx_offset_0[];
extern u8 fn_1_AB458__fzgx_offset_0[];
extern u8 fn_1_AB478__fzgx_offset_0[];
extern u8 fn_1_AB4F4__fzgx_offset_0[];
extern u8 fn_1_AB598__fzgx_offset_0[];
extern u8 fn_1_AB5CC__fzgx_offset_0[];
extern u8 fn_1_AB61C__fzgx_offset_0[];
extern u8 fn_1_AB64C__fzgx_offset_0[];
extern u8 fn_1_AB75C__fzgx_offset_0[];
extern u8 fn_1_AB7C4__fzgx_offset_0[];
extern u8 fn_1_AB870__fzgx_offset_0[];
extern u8 fn_1_AB880__fzgx_offset_0[];
extern u8 fn_1_AB8D8__fzgx_offset_0[];
extern u8 fn_1_AB93C__fzgx_offset_0[];
extern u8 fn_1_AB98C__fzgx_offset_0[];
extern u8 fn_1_AB99C__fzgx_offset_0[];
extern u8 fn_1_ABA14__fzgx_offset_0[];
extern u8 fn_1_ABA24__fzgx_offset_0[];
extern u8 fn_1_ABA9C__fzgx_offset_0[];
extern u8 fn_1_ABAAC__fzgx_offset_0[];
extern u8 fn_1_ABB24__fzgx_offset_0[];
extern u8 fn_1_ABB4C__fzgx_offset_0[];
extern u8 fn_1_ABC5C__fzgx_offset_0[];
extern u8 fn_1_ABC98__fzgx_offset_0[];
extern u8 fn_1_ABCE8__fzgx_offset_0[];
extern u8 fn_1_ABD58__fzgx_offset_0[];
extern u8 fn_1_ABDA8__fzgx_offset_0[];
extern u8 fn_1_ABDB8__fzgx_offset_0[];
extern u8 fn_1_ABE14__fzgx_offset_0[];
extern u8 fn_1_ABE88__fzgx_offset_0[];
extern u8 fn_1_ABF44__fzgx_offset_0[];
extern u8 fn_1_AC000__fzgx_offset_0[];
extern u8 fn_1_AC12C__fzgx_offset_0[];
extern u8 fn_1_AC188__fzgx_offset_0[];
extern u8 fn_1_AC294__fzgx_offset_0[];
extern u8 fn_1_AC2D8__fzgx_offset_0[];
extern u8 fn_1_AC328__fzgx_offset_0[];
extern u8 fn_1_AC38C__fzgx_offset_0[];
extern u8 fn_1_AC3DC__fzgx_offset_0[];
extern u8 fn_1_AC464__fzgx_offset_0[];
extern u8 fn_1_AC4B4__fzgx_offset_0[];
extern u8 fn_1_AC4C4__fzgx_offset_0[];
extern u8 fn_1_AC53C__fzgx_offset_0[];
extern u8 fn_1_AC6A4__fzgx_offset_0[];
extern u8 fn_1_AC6A8__fzgx_offset_0[];
extern u8 fn_1_AC6C8__fzgx_offset_0[];
extern u8 fn_1_AC6CC__fzgx_offset_0[];
extern u8 fn_1_AC6DC__fzgx_offset_0[];
extern u8 fn_1_AC6E0__fzgx_offset_0[];
extern u8 fn_1_AC700__fzgx_offset_0[];
extern u8 fn_1_AC704__fzgx_offset_0[];
extern u8 fn_1_AC74C__fzgx_offset_0[];
extern u8 fn_1_AC79C__fzgx_offset_0[];
extern u8 fn_1_AC904__fzgx_offset_0[];
extern u8 fn_1_AC908__fzgx_offset_0[];
extern u8 fn_1_AC928__fzgx_offset_0[];
extern u8 fn_1_AC92C__fzgx_offset_0[];
extern u8 fn_1_AC960__fzgx_offset_0[];
extern u8 fn_1_ACA00__fzgx_offset_0[];
extern u8 fn_1_ACA1C__fzgx_offset_0[];
extern u8 fn_1_ACA78__fzgx_offset_0[];
extern u8 fn_1_ACD00__fzgx_offset_0[];
extern u8 fn_1_ACD04__fzgx_offset_0[];
extern u8 fn_1_ACE7C__fzgx_offset_0[];
extern u8 fn_1_ACE80__fzgx_offset_0[];
extern u8 fn_1_ACEBC__fzgx_offset_0[];
extern u8 fn_1_ACF0C__fzgx_offset_0[];
extern u8 fn_1_ACF2C__fzgx_offset_0[];
extern u8 fn_1_ACF30__fzgx_offset_0[];
extern u8 fn_1_AD098__fzgx_offset_0[];
extern u8 fn_1_AD09C__fzgx_offset_0[];
extern u8 fn_1_AD0A0__fzgx_offset_0[];
extern u8 fn_1_AD140__fzgx_offset_0[];
extern u8 fn_1_AD164__fzgx_offset_0[];
extern u8 fn_1_AD168__fzgx_offset_0[];
extern u8 fn_1_AD1AC__fzgx_offset_0[];
extern u8 fn_1_AD1E4__fzgx_offset_0[];
extern u8 fn_1_AD264__fzgx_offset_0[];
extern u8 fn_1_AEC34__fzgx_offset_0[];
extern u8 fn_1_AECCC__fzgx_offset_0[];
extern u8 fn_1_B03A8__fzgx_offset_0[];
extern u8 fn_1_B03CC__fzgx_offset_0[];
extern u8 fn_1_B1710__fzgx_offset_0[];
extern u8 fn_1_B171C__fzgx_offset_0[];
extern u8 fn_1_B2770__fzgx_offset_0[];
extern u8 fn_1_B277C__fzgx_offset_0[];
extern u8 fn_1_B38F4__fzgx_offset_0[];
extern u8 fn_1_B3900__fzgx_offset_0[];
extern u8 fn_1_B40B4__fzgx_offset_0[];
extern u8 fn_1_B40C0__fzgx_offset_0[];
extern u8 lbl_1_data_35ACC__fzgx_offset_0[];
extern u8 lbl_1_data_35AD8__fzgx_offset_0[];
extern u8 lbl_1_data_35AE0__fzgx_offset_0[];
extern u8 lbl_1_data_35AEC__fzgx_offset_0[];
extern u8 lbl_1_data_35AF4__fzgx_offset_0[];
extern u8 lbl_1_data_35B00__fzgx_offset_0[];
extern u8 lbl_1_data_35B08__fzgx_offset_0[];
extern u8 lbl_1_data_35B10__fzgx_offset_0[];
extern u8 lbl_1_data_35B34__fzgx_offset_0[];
extern u8 lbl_1_data_35B48__fzgx_offset_0[];
extern u8 lbl_1_data_35B74__fzgx_offset_0[];
extern u8 lbl_1_data_35B88__fzgx_offset_0[];
extern u8 lbl_1_data_35BB4__fzgx_offset_0[];
extern u8 lbl_1_data_35BC8__fzgx_offset_0[];
extern u8 lbl_1_data_35BF4__fzgx_offset_0[];
extern u8 lbl_1_data_35C44__fzgx_offset_0[];
extern u8 lbl_1_data_35C50__fzgx_offset_0[];
extern u8 lbl_1_data_35C5C__fzgx_offset_0[];
extern u8 lbl_1_data_35C68__fzgx_offset_0[];
extern u8 lbl_1_data_35C74__fzgx_offset_0[];
extern u8 lbl_1_data_35CE0__fzgx_offset_0[];
extern u8 lbl_1_data_35D24__fzgx_offset_0[];
extern u8 lbl_1_data_35D34__fzgx_offset_0[];
extern u8 lbl_1_data_35D44__fzgx_offset_0[];
extern u8 lbl_1_data_35D54__fzgx_offset_0[];
extern u8 lbl_1_data_35D64__fzgx_offset_0[];
extern u8 lbl_1_data_35DC4__fzgx_offset_0[];
extern u8 lbl_1_data_35E34__fzgx_offset_0[];
extern u8 lbl_1_data_35E40__fzgx_offset_0[];
extern u8 lbl_1_data_35E4C__fzgx_offset_0[];
extern u8 lbl_1_data_35E58__fzgx_offset_0[];
extern u8 lbl_1_data_35E64__fzgx_offset_0[];
extern u8 lbl_1_data_35F4C__fzgx_offset_0[];
extern u8 lbl_1_data_35FA4__fzgx_offset_0[];
extern u8 lbl_1_data_35FB0__fzgx_offset_0[];
extern u8 lbl_1_data_35FBC__fzgx_offset_0[];
extern u8 lbl_1_data_35FC8__fzgx_offset_0[];
extern u8 lbl_1_data_35FD4__fzgx_offset_0[];
extern u8 lbl_1_data_3603C__fzgx_offset_0[];
extern u8 lbl_1_data_36070__fzgx_offset_0[];
extern u8 lbl_1_data_36088__fzgx_offset_0[];
extern u8 lbl_1_data_360A0__fzgx_offset_0[];
extern u8 lbl_1_data_360B8__fzgx_offset_0[];
extern u8 lbl_1_data_360D0__fzgx_offset_0[];
extern u8 lbl_1_data_360F8__fzgx_offset_0[];
extern u8 lbl_1_data_36128__fzgx_offset_0[];
extern u8 lbl_1_data_36140__fzgx_offset_0[];
extern u8 lbl_1_data_36158__fzgx_offset_0[];
extern u8 lbl_1_data_36170__fzgx_offset_0[];
extern u8 lbl_1_data_36188__fzgx_offset_0[];
extern u8 lbl_1_data_361B0__fzgx_offset_0[];
extern u8 lbl_1_data_361E0__fzgx_offset_0[];
extern u8 lbl_1_data_361F8__fzgx_offset_0[];
extern u8 lbl_1_data_36210__fzgx_offset_0[];
extern u8 lbl_1_data_36228__fzgx_offset_0[];
extern u8 lbl_1_data_36240__fzgx_offset_0[];
extern u8 lbl_1_data_36270__fzgx_offset_0[];
extern u8 lbl_1_data_362A0__fzgx_offset_0[];
extern u8 lbl_1_data_362BC__fzgx_offset_0[];
extern u8 lbl_1_data_362D8__fzgx_offset_0[];
extern u8 lbl_1_data_362F4__fzgx_offset_0[];
extern u8 lbl_1_data_36310__fzgx_offset_0[];
extern u8 lbl_1_data_36338__fzgx_offset_0[];
extern u8 lbl_1_data_3636C__fzgx_offset_0[];
extern u8 lbl_1_data_36388__fzgx_offset_0[];
extern u8 lbl_1_data_363A4__fzgx_offset_0[];
extern u8 lbl_1_data_363C0__fzgx_offset_0[];
extern u8 lbl_1_data_363DC__fzgx_offset_0[];
extern u8 lbl_1_data_36408__fzgx_offset_0[];
extern u8 lbl_1_data_3644C__fzgx_offset_0[];
extern u8 lbl_1_data_3646C__fzgx_offset_0[];
extern u8 lbl_1_data_3648C__fzgx_offset_0[];
extern u8 lbl_1_data_364AC__fzgx_offset_0[];
extern u8 lbl_1_data_364CC__fzgx_offset_0[];
extern u8 lbl_1_data_36510__fzgx_offset_0[];
extern u8 lbl_1_data_36554__fzgx_offset_0[];
extern u8 lbl_1_data_36574__fzgx_offset_0[];
extern u8 lbl_1_data_36594__fzgx_offset_0[];
extern u8 lbl_1_data_365B4__fzgx_offset_0[];
extern u8 lbl_1_data_365D4__fzgx_offset_0[];
extern u8 lbl_1_data_36618__fzgx_offset_0[];
extern u8 lbl_1_data_36648__fzgx_offset_0[];
extern u8 lbl_1_data_36668__fzgx_offset_0[];
extern u8 lbl_1_data_36688__fzgx_offset_0[];
extern u8 lbl_1_data_366A8__fzgx_offset_0[];
extern u8 lbl_1_data_366C8__fzgx_offset_0[];
extern u8 lbl_1_data_366F8__fzgx_offset_0[];
extern u8 lbl_1_data_3673C__fzgx_offset_0[];
extern u8 lbl_1_data_3675C__fzgx_offset_0[];
extern u8 lbl_1_data_3677C__fzgx_offset_0[];
extern u8 lbl_1_data_3679C__fzgx_offset_0[];
extern u8 lbl_1_data_367BC__fzgx_offset_0[];
extern u8 lbl_1_data_36800__fzgx_offset_0[];
extern u8 lbl_1_data_36844__fzgx_offset_0[];
extern u8 lbl_1_data_36864__fzgx_offset_0[];
extern u8 lbl_1_data_36884__fzgx_offset_0[];
extern u8 lbl_1_data_368A4__fzgx_offset_0[];
extern u8 lbl_1_data_368C4__fzgx_offset_0[];
extern u8 lbl_1_data_36908__fzgx_offset_0[];
extern u8 lbl_1_data_36928__fzgx_offset_0[];
extern u8 lbl_1_data_36938__fzgx_offset_0[];
extern u8 lbl_1_data_36948__fzgx_offset_0[];
extern u8 lbl_1_data_36958__fzgx_offset_0[];
extern u8 lbl_1_data_36968__fzgx_offset_0[];
extern u8 lbl_1_data_36984__fzgx_offset_0[];
extern u8 lbl_1_data_36998__fzgx_offset_0[];
extern u8 lbl_1_data_369A8__fzgx_offset_0[];
extern u8 lbl_1_data_369B8__fzgx_offset_0[];
extern u8 lbl_1_data_369C8__fzgx_offset_0[];
extern u8 lbl_1_data_369D8__fzgx_offset_0[];
extern u8 lbl_1_data_369E8__fzgx_offset_0[];
extern u8 lbl_1_data_36A1C__fzgx_offset_0[];
extern u8 lbl_1_data_36A34__fzgx_offset_0[];
extern u8 lbl_1_data_36A4C__fzgx_offset_0[];
extern u8 lbl_1_data_36A64__fzgx_offset_0[];
extern u8 lbl_1_data_36A7C__fzgx_offset_0[];
extern u8 lbl_1_data_36AB0__fzgx_offset_0[];
extern u8 lbl_1_data_36AE4__fzgx_offset_0[];
extern u8 lbl_1_data_36AFC__fzgx_offset_0[];
extern u8 lbl_1_data_36B14__fzgx_offset_0[];
extern u8 lbl_1_data_36B2C__fzgx_offset_0[];
extern u8 lbl_1_data_36B44__fzgx_offset_0[];
extern u8 lbl_1_data_36B78__fzgx_offset_0[];
extern u8 lbl_1_data_36B98__fzgx_offset_0[];
extern u8 lbl_1_data_36BB0__fzgx_offset_0[];
extern u8 lbl_1_data_36BC8__fzgx_offset_0[];
extern u8 lbl_1_data_36BE0__fzgx_offset_0[];
extern u8 lbl_1_data_36BF8__fzgx_offset_0[];
extern u8 lbl_1_data_36C1C__fzgx_offset_0[];
extern u8 lbl_1_data_36C50__fzgx_offset_0[];
extern u8 lbl_1_data_36C6C__fzgx_offset_0[];
extern u8 lbl_1_data_36C88__fzgx_offset_0[];
extern u8 lbl_1_data_36CA4__fzgx_offset_0[];
extern u8 lbl_1_data_36CC0__fzgx_offset_0[];
extern u8 lbl_1_data_36CF0__fzgx_offset_0[];
extern u8 lbl_1_data_36D28__fzgx_offset_0[];
extern u8 lbl_1_data_36D44__fzgx_offset_0[];
extern u8 lbl_1_data_36D60__fzgx_offset_0[];
extern u8 lbl_1_data_36D7C__fzgx_offset_0[];
extern u8 lbl_1_data_36D98__fzgx_offset_0[];
extern u8 lbl_1_data_36DD0__fzgx_offset_0[];
extern u8 lbl_1_data_36E10__fzgx_offset_0[];
extern u8 lbl_1_data_36E30__fzgx_offset_0[];
extern u8 lbl_1_data_36E50__fzgx_offset_0[];
extern u8 lbl_1_data_36E70__fzgx_offset_0[];
extern u8 lbl_1_data_36E90__fzgx_offset_0[];
extern u8 lbl_1_data_36ED0__fzgx_offset_0[];
extern u8 lbl_1_data_36F0C__fzgx_offset_0[];
extern u8 lbl_1_data_36F2C__fzgx_offset_0[];
extern u8 lbl_1_data_36F4C__fzgx_offset_0[];
extern u8 lbl_1_data_36F6C__fzgx_offset_0[];
extern u8 lbl_1_data_36F8C__fzgx_offset_0[];
extern u8 lbl_1_data_36FCC__fzgx_offset_0[];
extern u8 lbl_1_data_37008__fzgx_offset_0[];
extern u8 lbl_1_data_37028__fzgx_offset_0[];
extern u8 lbl_1_data_37048__fzgx_offset_0[];
extern u8 lbl_1_data_37068__fzgx_offset_0[];
extern u8 lbl_1_data_37088__fzgx_offset_0[];
extern u8 lbl_1_data_370CC__fzgx_offset_0[];
extern u8 lbl_1_data_3710C__fzgx_offset_0[];
extern u8 lbl_1_data_3712C__fzgx_offset_0[];
extern u8 lbl_1_data_3714C__fzgx_offset_0[];
extern u8 lbl_1_data_3716C__fzgx_offset_0[];
extern u8 lbl_1_data_3718C__fzgx_offset_0[];
extern u8 lbl_1_data_371C8__fzgx_offset_0[];
extern u8 lbl_1_data_37208__fzgx_offset_0[];
extern u8 lbl_1_data_37228__fzgx_offset_0[];
extern u8 lbl_1_data_37248__fzgx_offset_0[];
extern u8 lbl_1_data_37268__fzgx_offset_0[];
extern u8 lbl_1_data_37288__fzgx_offset_0[];
extern u8 lbl_1_data_372C8__fzgx_offset_0[];
extern u8 lbl_1_data_372F4__fzgx_offset_0[];
extern u8 lbl_1_data_3730C__fzgx_offset_0[];
extern u8 lbl_1_data_37324__fzgx_offset_0[];
extern u8 lbl_1_data_3733C__fzgx_offset_0[];
extern u8 lbl_1_data_37354__fzgx_offset_0[];
extern u8 lbl_1_data_37380__fzgx_offset_0[];
extern u8 lbl_1_data_373DC__fzgx_offset_0[];
extern u8 lbl_1_data_373F4__fzgx_offset_0[];
extern u8 lbl_1_data_3740C__fzgx_offset_0[];
extern u8 lbl_1_data_37424__fzgx_offset_0[];
extern u8 lbl_1_data_3743C__fzgx_offset_0[];
extern u8 lbl_1_data_374A8__fzgx_offset_0[];
extern u8 lbl_1_data_374D8__fzgx_offset_0[];
extern u8 lbl_1_data_374E8__fzgx_offset_0[];
extern u8 lbl_1_data_374F8__fzgx_offset_0[];
extern u8 lbl_1_data_37508__fzgx_offset_0[];
extern u8 lbl_1_data_37518__fzgx_offset_0[];
extern u8 lbl_1_data_37550__fzgx_offset_0[];
extern u8 lbl_1_data_375A4__fzgx_offset_0[];
extern u8 lbl_1_data_375B8__fzgx_offset_0[];
extern u8 lbl_1_data_375CC__fzgx_offset_0[];
extern u8 lbl_1_data_375E0__fzgx_offset_0[];
extern u8 lbl_1_data_375F4__fzgx_offset_0[];
extern u8 lbl_1_data_3763C__fzgx_offset_0[];
extern u8 lbl_1_data_37680__fzgx_offset_0[];
extern u8 lbl_1_data_37690__fzgx_offset_0[];
extern u8 lbl_1_data_376A0__fzgx_offset_0[];
extern u8 lbl_1_data_376B0__fzgx_offset_0[];
extern u8 lbl_1_data_376C0__fzgx_offset_0[];
extern u8 lbl_1_data_37704__fzgx_offset_0[];
extern u8 lbl_1_data_3773C__fzgx_offset_0[];
extern u8 lbl_1_data_37750__fzgx_offset_0[];
extern u8 lbl_1_data_37764__fzgx_offset_0[];
extern u8 lbl_1_data_37778__fzgx_offset_0[];
extern u8 lbl_1_data_3778C__fzgx_offset_0[];
extern u8 lbl_1_data_377D0__fzgx_offset_0[];
extern u8 lbl_1_data_37808__fzgx_offset_0[];
extern u8 lbl_1_data_37818__fzgx_offset_0[];
extern u8 lbl_1_data_37828__fzgx_offset_0[];
extern u8 lbl_1_data_37838__fzgx_offset_0[];
extern u8 lbl_1_data_37848__fzgx_offset_0[];
extern u8 lbl_1_data_3788C__fzgx_offset_0[];
extern u8 lbl_1_data_378EC__fzgx_offset_0[];
extern u8 lbl_1_data_378FC__fzgx_offset_0[];
extern u8 lbl_1_data_3790C__fzgx_offset_0[];
extern u8 lbl_1_data_3791C__fzgx_offset_0[];
extern u8 lbl_1_data_3792C__fzgx_offset_0[];
extern u8 lbl_1_data_37984__fzgx_offset_0[];
extern u8 lbl_1_data_379C0__fzgx_offset_0[];
extern u8 lbl_1_data_379D0__fzgx_offset_0[];
extern u8 lbl_1_data_379E0__fzgx_offset_0[];
extern u8 lbl_1_data_379F0__fzgx_offset_0[];
extern u8 lbl_1_data_37A00__fzgx_offset_0[];
extern u8 lbl_1_data_37A58__fzgx_offset_0[];
extern u8 lbl_1_data_37AB8__fzgx_offset_0[];
extern u8 lbl_1_data_37ACC__fzgx_offset_0[];
extern u8 lbl_1_data_37AE0__fzgx_offset_0[];
extern u8 lbl_1_data_37AF4__fzgx_offset_0[];
extern u8 lbl_1_data_37B08__fzgx_offset_0[];
extern u8 lbl_1_data_37B74__fzgx_offset_0[];
extern u8 lbl_1_data_37B9C__fzgx_offset_0[];
extern u8 lbl_1_data_37BB0__fzgx_offset_0[];
extern u8 lbl_1_data_37BC4__fzgx_offset_0[];
extern u8 lbl_1_data_37BD8__fzgx_offset_0[];
extern u8 lbl_1_data_37BEC__fzgx_offset_0[];
extern u8 lbl_1_data_37C28__fzgx_offset_0[];
extern u8 lbl_1_data_37C30__fzgx_offset_0[];
extern u8 lbl_1_data_37C3C__fzgx_offset_0[];
extern u8 lbl_1_data_37C48__fzgx_offset_0[];
extern u8 lbl_1_data_37C54__fzgx_offset_0[];
extern u8 lbl_1_data_37C60__fzgx_offset_0[];
extern u8 lbl_1_data_37C6C__fzgx_offset_0[];
extern u8 lbl_1_data_37C74__fzgx_offset_0[];
extern u8 lbl_1_data_37C80__fzgx_offset_0[];
extern u8 lbl_1_data_37C8C__fzgx_offset_0[];
extern u8 lbl_1_data_37C98__fzgx_offset_0[];
extern u8 lbl_1_data_37CA4__fzgx_offset_0[];
extern u8 lbl_1_data_37CB0__fzgx_offset_0[];
extern u8 lbl_1_data_37CB4__fzgx_offset_0[];
extern u8 lbl_1_data_37CBC__fzgx_offset_0[];
extern u8 lbl_1_data_37CC4__fzgx_offset_0[];
extern u8 lbl_1_data_37CCC__fzgx_offset_0[];
extern u8 lbl_1_data_37CD4__fzgx_offset_0[];
extern u8 lbl_1_data_37CDC__fzgx_offset_0[];
extern u8 lbl_1_data_37CE0__fzgx_offset_0[];
extern u8 lbl_1_data_37CE8__fzgx_offset_0[];
extern u8 lbl_1_data_37CF0__fzgx_offset_0[];
extern u8 lbl_1_data_37CF8__fzgx_offset_0[];
extern u8 lbl_1_data_37D00__fzgx_offset_0[];
extern u8 lbl_1_data_37D08__fzgx_offset_0[];
extern u8 lbl_1_data_37D44__fzgx_offset_0[];
extern u8 lbl_1_data_37D58__fzgx_offset_0[];
extern u8 lbl_1_data_37D6C__fzgx_offset_0[];
extern u8 lbl_1_data_37D80__fzgx_offset_0[];
extern u8 lbl_1_data_37D94__fzgx_offset_0[];
extern u8 lbl_1_data_37DD4__fzgx_offset_0[];
extern u8 lbl_1_data_37F64__fzgx_offset_0[];
extern u8 lbl_1_data_37F70__fzgx_offset_0[];
extern u8 lbl_1_data_37F7C__fzgx_offset_0[];
extern u8 lbl_1_data_37F88__fzgx_offset_0[];
extern u8 lbl_1_data_37F94__fzgx_offset_0[];
extern u8 lbl_1_data_381E4__fzgx_offset_0[];
extern u8 lbl_1_data_382C8__fzgx_offset_0[];
extern u8 lbl_1_data_382D4__fzgx_offset_0[];
extern u8 lbl_1_data_382E0__fzgx_offset_0[];
extern u8 lbl_1_data_382EC__fzgx_offset_0[];
extern u8 lbl_1_data_382F8__fzgx_offset_0[];
extern u8 lbl_1_data_38454__fzgx_offset_0[];
extern u8 lbl_1_data_385E4__fzgx_offset_0[];
extern u8 lbl_1_data_385F4__fzgx_offset_0[];
extern u8 lbl_1_data_38604__fzgx_offset_0[];
extern u8 lbl_1_data_38614__fzgx_offset_0[];
extern u8 lbl_1_data_38624__fzgx_offset_0[];
extern u8 lbl_1_data_38874__fzgx_offset_0[];
extern u8 lbl_1_data_38958__fzgx_offset_0[];
extern u8 lbl_1_data_3896C__fzgx_offset_0[];
extern u8 lbl_1_data_38980__fzgx_offset_0[];
extern u8 lbl_1_data_38994__fzgx_offset_0[];
extern u8 lbl_1_data_389A8__fzgx_offset_0[];
extern u8 lbl_1_data_38B04__fzgx_offset_0[];
extern u8 lbl_1_data_38B58__fzgx_offset_0[];
extern u8 lbl_1_data_38B6C__fzgx_offset_0[];
extern u8 lbl_1_data_38B80__fzgx_offset_0[];
extern u8 lbl_1_data_38B94__fzgx_offset_0[];
extern u8 lbl_1_data_38BA8__fzgx_offset_0[];
extern u8 lbl_1_data_38C08__fzgx_offset_0[];
extern u8 lbl_1_data_38C30__fzgx_offset_0[];
extern u8 lbl_1_data_38C48__fzgx_offset_0[];
extern u8 lbl_1_data_38C60__fzgx_offset_0[];
extern u8 lbl_1_data_38C78__fzgx_offset_0[];
extern u8 lbl_1_data_38C90__fzgx_offset_0[];
extern u8 lbl_1_data_38CCC__fzgx_offset_0[];
extern u8 lbl_1_data_38D00__fzgx_offset_0[];
extern u8 lbl_1_data_38D10__fzgx_offset_0[];
extern u8 lbl_1_data_38D20__fzgx_offset_0[];
extern u8 lbl_1_data_38D30__fzgx_offset_0[];
extern u8 lbl_1_data_38D40__fzgx_offset_0[];
extern u8 lbl_1_data_38D80__fzgx_offset_0[];
extern u8 lbl_1_data_38D98__fzgx_offset_0[];
extern u8 lbl_1_data_38DAC__fzgx_offset_0[];
extern u8 lbl_1_data_38DC0__fzgx_offset_0[];
extern u8 lbl_1_data_38DD4__fzgx_offset_0[];
extern u8 lbl_1_data_38DE8__fzgx_offset_0[];
extern u8 lbl_1_data_38E04__fzgx_offset_0[];
extern u8 lbl_1_data_38E0C__fzgx_offset_0[];
extern u8 lbl_1_data_38E18__fzgx_offset_0[];
extern u8 lbl_1_data_38E24__fzgx_offset_0[];
extern u8 lbl_1_data_38E30__fzgx_offset_0[];
extern u8 lbl_1_data_38E3C__fzgx_offset_0[];
extern u8 lbl_1_data_38E48__fzgx_offset_0[];
extern u8 lbl_1_data_38E80__fzgx_offset_0[];
extern u8 lbl_1_data_38E90__fzgx_offset_0[];
extern u8 lbl_1_data_38EA0__fzgx_offset_0[];
extern u8 lbl_1_data_38EB0__fzgx_offset_0[];
extern u8 lbl_1_data_38EC0__fzgx_offset_0[];
extern u8 lbl_1_data_38F04__fzgx_offset_0[];
extern u8 lbl_1_data_38F30__fzgx_offset_0[];
extern u8 lbl_1_data_38F40__fzgx_offset_0[];
extern u8 lbl_1_data_38F50__fzgx_offset_0[];
extern u8 lbl_1_data_38F60__fzgx_offset_0[];
extern u8 lbl_1_data_38F70__fzgx_offset_0[];
extern u8 lbl_1_data_38FA8__fzgx_offset_0[];
extern u8 lbl_1_data_38FE8__fzgx_offset_0[];
extern u8 lbl_1_data_38FF8__fzgx_offset_0[];
extern u8 lbl_1_data_39008__fzgx_offset_0[];
extern u8 lbl_1_data_39018__fzgx_offset_0[];
extern u8 lbl_1_data_39028__fzgx_offset_0[];
extern u8 lbl_1_data_3906C__fzgx_offset_0[];
extern u8 lbl_1_data_390C4__fzgx_offset_0[];
extern u8 lbl_1_data_390D4__fzgx_offset_0[];
extern u8 lbl_1_data_390E4__fzgx_offset_0[];
extern u8 lbl_1_data_390F4__fzgx_offset_0[];
extern u8 lbl_1_data_39104__fzgx_offset_0[];
extern u8 lbl_1_data_39148__fzgx_offset_0[];
extern u8 lbl_1_data_39190__fzgx_offset_0[];
extern u8 lbl_1_data_3919C__fzgx_offset_0[];
extern u8 lbl_1_data_391A8__fzgx_offset_0[];
extern u8 lbl_1_data_391B4__fzgx_offset_0[];
extern u8 lbl_1_data_391C0__fzgx_offset_0[];
extern u8 lbl_1_data_39214__fzgx_offset_0[];
extern u8 lbl_1_data_39248__fzgx_offset_0[];
extern u8 lbl_1_data_39254__fzgx_offset_0[];
extern u8 lbl_1_data_39260__fzgx_offset_0[];
extern u8 lbl_1_data_3926C__fzgx_offset_0[];
extern u8 lbl_1_data_39278__fzgx_offset_0[];
extern u8 lbl_1_data_392AC__fzgx_offset_0[];
extern u8 lbl_1_data_392E4__fzgx_offset_0[];
extern u8 lbl_1_data_392F0__fzgx_offset_0[];
extern u8 lbl_1_data_392FC__fzgx_offset_0[];
extern u8 lbl_1_data_39308__fzgx_offset_0[];
extern u8 lbl_1_data_39314__fzgx_offset_0[];
extern u8 lbl_1_data_39348__fzgx_offset_0[];
extern u8 lbl_1_data_3937C__fzgx_offset_0[];
extern u8 lbl_1_data_39388__fzgx_offset_0[];
extern u8 lbl_1_data_39394__fzgx_offset_0[];
extern u8 lbl_1_data_393A0__fzgx_offset_0[];
extern u8 lbl_1_data_393AC__fzgx_offset_0[];
extern u8 lbl_1_data_393E0__fzgx_offset_0[];
extern u8 lbl_1_data_39418__fzgx_offset_0[];
extern u8 lbl_1_data_39424__fzgx_offset_0[];
extern u8 lbl_1_data_39430__fzgx_offset_0[];
extern u8 lbl_1_data_3943C__fzgx_offset_0[];
extern u8 lbl_1_data_39448__fzgx_offset_0[];
extern u8 lbl_1_data_3947C__fzgx_offset_0[];
extern u8 lbl_1_data_394B8__fzgx_offset_0[];
extern u8 lbl_1_data_394C8__fzgx_offset_0[];
extern u8 lbl_1_data_394D8__fzgx_offset_0[];
extern u8 lbl_1_data_394E8__fzgx_offset_0[];
extern u8 lbl_1_data_394F8__fzgx_offset_0[];
extern u8 lbl_1_data_39520__fzgx_offset_0[];
extern u8 lbl_1_data_39550__fzgx_offset_0[];
extern u8 lbl_1_data_39564__fzgx_offset_0[];
extern u8 lbl_1_data_39578__fzgx_offset_0[];
extern u8 lbl_1_data_3958C__fzgx_offset_0[];
extern u8 lbl_1_data_395A0__fzgx_offset_0[];
extern u8 lbl_1_data_395DC__fzgx_offset_0[];
extern u8 lbl_1_data_39618__fzgx_offset_0[];
extern u8 lbl_1_data_39628__fzgx_offset_0[];
extern u8 lbl_1_data_39638__fzgx_offset_0[];
extern u8 lbl_1_data_39648__fzgx_offset_0[];
extern u8 lbl_1_data_39658__fzgx_offset_0[];
extern u8 lbl_1_data_39694__fzgx_offset_0[];
extern u8 lbl_1_data_396BC__fzgx_offset_0[];
extern u8 lbl_1_data_396CC__fzgx_offset_0[];
extern u8 lbl_1_data_396DC__fzgx_offset_0[];
extern u8 lbl_1_data_396EC__fzgx_offset_0[];
extern u8 lbl_1_data_396FC__fzgx_offset_0[];
extern u8 lbl_1_data_39740__fzgx_offset_0[];
extern u8 lbl_1_data_39780__fzgx_offset_0[];
extern u8 lbl_1_data_39790__fzgx_offset_0[];
extern u8 lbl_1_data_397A0__fzgx_offset_0[];
extern u8 lbl_1_data_397B0__fzgx_offset_0[];
extern u8 lbl_1_data_397C0__fzgx_offset_0[];
extern u8 lbl_1_data_39800__fzgx_offset_0[];
extern u8 lbl_1_data_39838__fzgx_offset_0[];
extern u8 lbl_1_data_39848__fzgx_offset_0[];
extern u8 lbl_1_data_39858__fzgx_offset_0[];
extern u8 lbl_1_data_39868__fzgx_offset_0[];
extern u8 lbl_1_data_39878__fzgx_offset_0[];
extern u8 lbl_1_data_398A0__fzgx_offset_0[];
extern u8 lbl_1_data_398B0__fzgx_offset_0[];
extern u8 lbl_1_data_398C0__fzgx_offset_0[];
extern u8 lbl_1_data_398D0__fzgx_offset_0[];
extern u8 lbl_1_data_398E0__fzgx_offset_0[];
extern u8 lbl_1_data_398F0__fzgx_offset_0[];
extern u8 lbl_1_data_39900__fzgx_offset_0[];
extern u8 lbl_1_data_3990C__fzgx_offset_0[];
extern u8 lbl_1_data_3991C__fzgx_offset_0[];
extern u8 lbl_1_data_3992C__fzgx_offset_0[];
extern u8 lbl_1_data_3993C__fzgx_offset_0[];
extern u8 lbl_1_data_3994C__fzgx_offset_0[];
extern u8 lbl_1_data_39958__fzgx_offset_0[];
extern u8 lbl_1_data_39968__fzgx_offset_0[];
extern u8 lbl_1_data_39978__fzgx_offset_0[];
extern u8 lbl_1_data_39988__fzgx_offset_0[];
extern u8 lbl_1_data_39998__fzgx_offset_0[];
extern u8 lbl_1_data_399A8__fzgx_offset_0[];
extern u8 lbl_1_data_399B8__fzgx_offset_0[];
extern u8 lbl_1_data_399C8__fzgx_offset_0[];
extern u8 lbl_1_data_399D8__fzgx_offset_0[];
extern u8 lbl_1_data_399E8__fzgx_offset_0[];
extern u8 lbl_1_data_399F8__fzgx_offset_0[];
extern u8 lbl_1_data_39A08__fzgx_offset_0[];
extern u8 lbl_1_data_39A18__fzgx_offset_0[];
extern u8 lbl_1_data_39A6C__fzgx_offset_0[];
extern u8 lbl_1_data_39A78__fzgx_offset_0[];
extern u8 lbl_1_data_39A84__fzgx_offset_0[];
extern u8 lbl_1_data_39A90__fzgx_offset_0[];
extern u8 lbl_1_data_39A9C__fzgx_offset_0[];
extern u8 lbl_1_data_39B04__fzgx_offset_0[];
extern u8 lbl_1_data_39B58__fzgx_offset_0[];
extern u8 lbl_1_data_39B64__fzgx_offset_0[];
extern u8 lbl_1_data_39B70__fzgx_offset_0[];
extern u8 lbl_1_data_39B7C__fzgx_offset_0[];
extern u8 lbl_1_data_39B88__fzgx_offset_0[];
extern u8 lbl_1_data_39BF0__fzgx_offset_0[];
extern u8 lbl_1_data_39C1C__fzgx_offset_0[];
extern u8 lbl_1_data_39C2C__fzgx_offset_0[];
extern u8 lbl_1_data_39C3C__fzgx_offset_0[];
extern u8 lbl_1_data_39C4C__fzgx_offset_0[];
extern u8 lbl_1_data_39C5C__fzgx_offset_0[];
extern u8 lbl_1_data_39C88__fzgx_offset_0[];
extern u8 lbl_1_data_39CB8__fzgx_offset_0[];
extern u8 lbl_1_data_39CC8__fzgx_offset_0[];
extern u8 lbl_1_data_39CD8__fzgx_offset_0[];
extern u8 lbl_1_data_39CE8__fzgx_offset_0[];
extern u8 lbl_1_data_39CF8__fzgx_offset_0[];
extern u8 lbl_1_data_39D2C__fzgx_offset_0[];
extern u8 lbl_1_data_39DC4__fzgx_offset_0[];
extern u8 lbl_1_data_39DDC__fzgx_offset_0[];
extern u8 lbl_1_data_39DF4__fzgx_offset_0[];
extern u8 lbl_1_data_39E0C__fzgx_offset_0[];
extern u8 lbl_1_data_39E24__fzgx_offset_0[];
extern u8 lbl_1_data_39EB0__fzgx_offset_0[];
extern u8 lbl_1_data_39EF4__fzgx_offset_0[];
extern u8 lbl_1_data_39F0C__fzgx_offset_0[];
extern u8 lbl_1_data_39F24__fzgx_offset_0[];
extern u8 lbl_1_data_39F3C__fzgx_offset_0[];
extern u8 lbl_1_data_39F54__fzgx_offset_0[];
extern u8 lbl_1_data_39FA4__fzgx_offset_0[];
extern u8 lbl_1_data_3A018__fzgx_offset_0[];
extern u8 lbl_1_data_3A01C__fzgx_offset_0[];
extern u8 lbl_1_data_3A020__fzgx_offset_0[];
extern u8 lbl_1_data_3A024__fzgx_offset_0[];
extern u8 lbl_1_data_3A028__fzgx_offset_0[];
extern u8 lbl_1_data_3A0E4__fzgx_offset_0[];
extern u8 lbl_1_data_3A15C__fzgx_offset_0[];
extern u8 lbl_1_data_3A160__fzgx_offset_0[];
extern u8 lbl_1_data_3A164__fzgx_offset_0[];
extern u8 lbl_1_data_3A168__fzgx_offset_0[];
extern u8 lbl_1_data_3A16C__fzgx_offset_0[];
extern u8 lbl_1_data_3A1C8__fzgx_offset_0[];
extern u8 lbl_1_data_3A1D0__fzgx_offset_0[];
extern u8 lbl_1_data_3A1DC__fzgx_offset_0[];
extern u8 lbl_1_data_3A1E8__fzgx_offset_0[];
extern u8 lbl_1_data_3A1F4__fzgx_offset_0[];
extern u8 lbl_1_data_3A200__fzgx_offset_0[];
extern u8 lbl_1_data_3A208__fzgx_offset_0[];
extern u8 lbl_1_data_3A210__fzgx_offset_0[];
extern u8 lbl_1_data_3A21C__fzgx_offset_0[];
extern u8 lbl_1_data_3A228__fzgx_offset_0[];
extern u8 lbl_1_data_3A234__fzgx_offset_0[];
extern u8 lbl_1_data_3A240__fzgx_offset_0[];
extern u8 lbl_1_data_3A248__fzgx_offset_0[];
extern u8 lbl_1_data_3A250__fzgx_offset_0[];
extern u8 lbl_1_data_3A25C__fzgx_offset_0[];
extern u8 lbl_1_data_3A268__fzgx_offset_0[];
extern u8 lbl_1_data_3A274__fzgx_offset_0[];
extern u8 lbl_1_data_3A280__fzgx_offset_0[];
extern u8 lbl_1_data_3A28C__fzgx_offset_0[];
extern u8 lbl_1_data_3A294__fzgx_offset_0[];
extern u8 lbl_1_data_3A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_3A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_3A2B8__fzgx_offset_0[];
extern u8 lbl_1_data_3A2C4__fzgx_offset_0[];
extern u8 lbl_1_data_3A2D0__fzgx_offset_0[];
extern u8 lbl_1_data_3A2D8__fzgx_offset_0[];
extern u8 lbl_1_data_3A2E4__fzgx_offset_0[];
extern u8 lbl_1_data_3A2F0__fzgx_offset_0[];
extern u8 lbl_1_data_3A2FC__fzgx_offset_0[];
extern u8 lbl_1_data_3A308__fzgx_offset_0[];
extern u8 lbl_1_data_3A314__fzgx_offset_0[];
extern u8 lbl_1_data_3A31C__fzgx_offset_0[];
extern u8 lbl_1_data_3A328__fzgx_offset_0[];
extern u8 lbl_1_data_3A334__fzgx_offset_0[];
extern u8 lbl_1_data_3A340__fzgx_offset_0[];
extern u8 lbl_1_data_3A34C__fzgx_offset_0[];
extern u8 lbl_1_data_3A358__fzgx_offset_0[];
extern u8 lbl_1_data_3A360__fzgx_offset_0[];
extern u8 lbl_1_data_3A36C__fzgx_offset_0[];
extern u8 lbl_1_data_3A378__fzgx_offset_0[];
extern u8 lbl_1_data_3A384__fzgx_offset_0[];
extern u8 lbl_1_data_3A390__fzgx_offset_0[];
extern u8 lbl_1_data_3A39C__fzgx_offset_0[];
extern u8 lbl_1_data_3A3A4__fzgx_offset_0[];
extern u8 lbl_1_data_3A3B0__fzgx_offset_0[];
extern u8 lbl_1_data_3A3BC__fzgx_offset_0[];
extern u8 lbl_1_data_3A3C8__fzgx_offset_0[];
extern u8 lbl_1_data_3A3D4__fzgx_offset_0[];
extern u8 lbl_1_data_3A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_3A520__fzgx_offset_0[];
extern u8 lbl_1_data_3A524__fzgx_offset_0[];
extern u8 lbl_1_data_3A528__fzgx_offset_0[];
extern u8 lbl_1_data_3A52C__fzgx_offset_0[];
extern u8 lbl_1_data_3A530__fzgx_offset_0[];
extern u8 lbl_1_data_3A6A0__fzgx_offset_0[];
extern u8 lbl_1_data_3A6E4__fzgx_offset_0[];
extern u8 lbl_1_data_3A6E8__fzgx_offset_0[];
extern u8 lbl_1_data_3A6EC__fzgx_offset_0[];
extern u8 lbl_1_data_3A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_3A6F4__fzgx_offset_0[];
extern u8 lbl_1_data_3A738__fzgx_offset_0[];
extern u8 lbl_1_data_3A77C__fzgx_offset_0[];
extern u8 lbl_1_data_3A780__fzgx_offset_0[];
extern u8 lbl_1_data_3A784__fzgx_offset_0[];
extern u8 lbl_1_data_3A788__fzgx_offset_0[];
extern u8 lbl_1_data_3A78C__fzgx_offset_0[];
extern u8 lbl_1_data_3A7D4__fzgx_offset_0[];
extern u8 lbl_1_data_3A80C__fzgx_offset_0[];
extern u8 lbl_1_data_3A810__fzgx_offset_0[];
extern u8 lbl_1_data_3A814__fzgx_offset_0[];
extern u8 lbl_1_data_3A818__fzgx_offset_0[];
extern u8 lbl_1_data_3A81C__fzgx_offset_0[];
extern u8 lbl_1_data_3A874__fzgx_offset_0[];
extern u8 lbl_1_data_3A87C__fzgx_offset_0[];
extern u8 lbl_1_data_3A880__fzgx_offset_0[];
extern u8 lbl_1_data_3A884__fzgx_offset_0[];
extern u8 lbl_1_data_3A888__fzgx_offset_0[];
extern u8 lbl_1_data_3A88C__fzgx_offset_0[];
extern u8 lbl_1_data_3A894__fzgx_offset_0[];
extern u8 lbl_1_data_3A89C__fzgx_offset_0[];
extern u8 lbl_1_data_3A8A0__fzgx_offset_0[];
extern u8 lbl_1_data_3A8A4__fzgx_offset_0[];
extern u8 lbl_1_data_3A8A8__fzgx_offset_0[];
extern u8 lbl_1_data_3A8AC__fzgx_offset_0[];
extern u8 lbl_1_data_3A8B4__fzgx_offset_0[];
extern u8 lbl_1_data_3A8BC__fzgx_offset_0[];
extern u8 lbl_1_data_3A8C0__fzgx_offset_0[];
extern u8 lbl_1_data_3A8C4__fzgx_offset_0[];
extern u8 lbl_1_data_3A8C8__fzgx_offset_0[];
extern u8 lbl_1_data_3A8CC__fzgx_offset_0[];
extern u8 lbl_1_data_3A8D4__fzgx_offset_0[];
extern u8 lbl_1_data_3A8DC__fzgx_offset_0[];
extern u8 lbl_1_data_3A8E0__fzgx_offset_0[];
extern u8 lbl_1_data_3A8E4__fzgx_offset_0[];
extern u8 lbl_1_data_3A8E8__fzgx_offset_0[];
extern u8 lbl_1_data_3A8EC__fzgx_offset_0[];
extern u8 lbl_1_data_3A8F4__fzgx_offset_0[];
extern u8 lbl_1_data_3A928__fzgx_offset_0[];
extern u8 lbl_1_data_3A92C__fzgx_offset_0[];
extern u8 lbl_1_data_3A930__fzgx_offset_0[];
extern u8 lbl_1_data_3A934__fzgx_offset_0[];
extern u8 lbl_1_data_3A938__fzgx_offset_0[];
extern u8 lbl_1_data_3A98C__fzgx_offset_0[];
extern u8 lbl_1_data_3A9E0__fzgx_offset_0[];
extern u8 lbl_1_data_3A9E4__fzgx_offset_0[];
extern u8 lbl_1_data_3A9E8__fzgx_offset_0[];
extern u8 lbl_1_data_3A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_3A9F0__fzgx_offset_0[];
extern u8 lbl_1_data_3AA3C__fzgx_offset_0[];
extern u8 lbl_1_data_3AA44__fzgx_offset_0[];
extern u8 lbl_1_data_3AA48__fzgx_offset_0[];
extern u8 lbl_1_data_3AA4C__fzgx_offset_0[];
extern u8 lbl_1_data_3AA50__fzgx_offset_0[];
extern u8 lbl_1_data_3AA54__fzgx_offset_0[];
extern u8 lbl_1_data_3AA60__fzgx_offset_0[];
extern u8 lbl_1_data_3AAA0__fzgx_offset_0[];
extern u8 lbl_1_data_3AAB4__fzgx_offset_0[];
extern u8 lbl_1_data_3AAC8__fzgx_offset_0[];
extern u8 lbl_1_data_3AADC__fzgx_offset_0[];
extern u8 lbl_1_data_3AAF0__fzgx_offset_0[];
extern u8 lbl_1_data_3ABCC__fzgx_offset_0[];
extern u8 lbl_1_data_3AC48__fzgx_offset_0[];
extern u8 lbl_1_data_3AC58__fzgx_offset_0[];
extern u8 lbl_1_data_3AC68__fzgx_offset_0[];
extern u8 lbl_1_data_3AC78__fzgx_offset_0[];
extern u8 lbl_1_data_3AC88__fzgx_offset_0[];
extern u8 lbl_1_data_3AD68__fzgx_offset_0[];
extern u8 lbl_1_data_3ADD8__fzgx_offset_0[];
extern u8 lbl_1_data_3ADEC__fzgx_offset_0[];
extern u8 lbl_1_data_3AE00__fzgx_offset_0[];
extern u8 lbl_1_data_3AE14__fzgx_offset_0[];
extern u8 lbl_1_data_3AE28__fzgx_offset_0[];
extern u8 lbl_1_data_3AE2C__fzgx_offset_0[];
extern u8 lbl_1_data_3AED4__fzgx_offset_0[];
extern u8 lbl_1_data_3AEE4__fzgx_offset_0[];
extern u8 lbl_1_data_3AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_3AF04__fzgx_offset_0[];
extern u8 lbl_1_data_3AF14__fzgx_offset_0[];
extern u8 lbl_1_data_3AF18__fzgx_offset_0[];
extern u8 lbl_1_data_3AFC0__fzgx_offset_0[];
extern u8 lbl_1_data_3AFD0__fzgx_offset_0[];
extern u8 lbl_1_data_3AFE0__fzgx_offset_0[];
extern u8 lbl_1_data_3AFF0__fzgx_offset_0[];
extern u8 lbl_1_data_3B000__fzgx_offset_0[];
extern u8 lbl_1_data_3B0B8__fzgx_offset_0[];
extern u8 lbl_1_data_3B0E0__fzgx_offset_0[];
extern u8 lbl_1_data_3B0F0__fzgx_offset_0[];
extern u8 lbl_1_data_3B100__fzgx_offset_0[];
extern u8 lbl_1_data_3B110__fzgx_offset_0[];
extern u8 lbl_1_data_3B120__fzgx_offset_0[];
extern u8 lbl_1_data_3B150__fzgx_offset_0[];
extern u8 lbl_1_data_3B198__fzgx_offset_0[];
extern u8 lbl_1_data_3B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_3B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_3B1C8__fzgx_offset_0[];
extern u8 lbl_1_data_3B1D8__fzgx_offset_0[];
extern u8 lbl_1_data_3B240__fzgx_offset_0[];
extern u8 lbl_1_data_3B278__fzgx_offset_0[];
extern u8 lbl_1_data_3B288__fzgx_offset_0[];
extern u8 lbl_1_data_3B298__fzgx_offset_0[];
extern u8 lbl_1_data_3B2A8__fzgx_offset_0[];
extern u8 lbl_1_data_3B2B8__fzgx_offset_0[];
extern u8 lbl_1_data_3B300__fzgx_offset_0[];
extern u8 lbl_1_data_3B32C__fzgx_offset_0[];
extern u8 lbl_1_data_3B340__fzgx_offset_0[];
extern u8 lbl_1_data_3B354__fzgx_offset_0[];
extern u8 lbl_1_data_3B368__fzgx_offset_0[];
extern u8 lbl_1_data_3B37C__fzgx_offset_0[];
extern u8 lbl_1_data_3B3AC__fzgx_offset_0[];
extern u8 lbl_1_data_3B3C0__fzgx_offset_0[];
extern u8 lbl_1_data_3B3D0__fzgx_offset_0[];
extern u8 lbl_1_data_3B3E0__fzgx_offset_0[];
extern u8 lbl_1_data_3B3F0__fzgx_offset_0[];
extern u8 lbl_1_data_3B400__fzgx_offset_0[];
extern u8 lbl_1_data_3B40C__fzgx_offset_0[];
extern u8 lbl_1_data_3B420__fzgx_offset_0[];
extern u8 lbl_1_data_3B434__fzgx_offset_0[];
extern u8 lbl_1_data_3B448__fzgx_offset_0[];
extern u8 lbl_1_data_3B45C__fzgx_offset_0[];
extern u8 lbl_1_data_3B470__fzgx_offset_0[];
extern u8 lbl_1_data_3B490__fzgx_offset_0[];
extern u8 lbl_1_data_3B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_3B4C0__fzgx_offset_0[];
extern u8 lbl_1_data_3B4D4__fzgx_offset_0[];
extern u8 lbl_1_data_3B4E8__fzgx_offset_0[];
extern u8 lbl_1_data_3B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_3B520__fzgx_offset_0[];
extern u8 lbl_1_data_3B540__fzgx_offset_0[];
extern u8 lbl_1_data_3B550__fzgx_offset_0[];
extern u8 lbl_1_data_3B560__fzgx_offset_0[];
extern u8 lbl_1_data_3B570__fzgx_offset_0[];
extern u8 lbl_1_data_3B580__fzgx_offset_0[];
extern u8 lbl_1_data_3B594__fzgx_offset_0[];
extern u8 lbl_1_data_3B5C8__fzgx_offset_0[];
extern u8 lbl_1_data_3B5DC__fzgx_offset_0[];
extern u8 lbl_1_data_3B5F0__fzgx_offset_0[];
extern u8 lbl_1_data_3B604__fzgx_offset_0[];
extern u8 lbl_1_data_3B618__fzgx_offset_0[];
extern u8 lbl_1_data_3B63C__fzgx_offset_0[];
extern u8 lbl_1_data_3B64C__fzgx_offset_0[];
extern u8 lbl_1_data_3B65C__fzgx_offset_0[];
extern u8 lbl_1_data_3B66C__fzgx_offset_0[];
extern u8 lbl_1_data_3B67C__fzgx_offset_0[];
extern u8 lbl_1_data_3B68C__fzgx_offset_0[];
extern u8 lbl_1_data_3B69C__fzgx_offset_0[];
extern u8 lbl_1_data_3B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_3B6DC__fzgx_offset_0[];
extern u8 lbl_1_data_3B6F0__fzgx_offset_0[];
extern u8 lbl_1_data_3B704__fzgx_offset_0[];
extern u8 lbl_1_data_3B718__fzgx_offset_0[];
extern u8 lbl_1_data_3C1E8__fzgx_offset_0[];
extern u8 lbl_1_data_3C1F8__fzgx_offset_0[];
extern u8 lbl_1_data_3C20C__fzgx_offset_0[];
extern u8 lbl_1_data_3C21C__fzgx_offset_0[];
extern u8 lbl_1_data_3C22C__fzgx_offset_0[];
extern u8 lbl_1_data_3C244__fzgx_offset_0[];
extern u8 lbl_1_data_3C254__fzgx_offset_0[];
extern u8 lbl_1_data_3C284__fzgx_offset_0[];
extern u8 lbl_1_data_3C290__fzgx_offset_0[];
extern u8 lbl_1_data_3C2A0__fzgx_offset_0[];
extern u8 lbl_1_data_3C2B4__fzgx_offset_0[];
extern u8 lbl_1_data_3C2C4__fzgx_offset_0[];
extern u8 lbl_1_data_3C2D4__fzgx_offset_0[];
extern u8 lbl_1_data_3C2E8__fzgx_offset_0[];
extern u8 lbl_1_data_3C2F8__fzgx_offset_0[];
extern u8 lbl_1_data_3C30C__fzgx_offset_0[];
extern u8 lbl_1_data_3C320__fzgx_offset_0[];
extern u8 lbl_1_data_3C334__fzgx_offset_0[];
extern u8 lbl_1_data_3C348__fzgx_offset_0[];
extern u8 lbl_1_data_3C360__fzgx_offset_0[];
extern u8 lbl_1_data_3C374__fzgx_offset_0[];
extern u8 lbl_1_data_3C388__fzgx_offset_0[];
extern u8 lbl_1_data_3C398__fzgx_offset_0[];
extern u8 lbl_1_data_3C3A8__fzgx_offset_0[];
extern u8 lbl_1_data_3C3B8__fzgx_offset_0[];
extern u8 lbl_1_data_3C3CC__fzgx_offset_0[];
extern u8 lbl_1_data_3C3DC__fzgx_offset_0[];
extern u8 lbl_1_data_3C3F4__fzgx_offset_0[];
extern u8 lbl_1_data_3C404__fzgx_offset_0[];
extern u8 lbl_1_data_3C418__fzgx_offset_0[];
extern u8 lbl_1_data_3C42C__fzgx_offset_0[];
extern u8 lbl_1_data_3C440__fzgx_offset_0[];
extern u8 lbl_1_data_3C450__fzgx_offset_0[];
extern u8 lbl_1_data_3C460__fzgx_offset_0[];
extern u8 lbl_1_data_3C470__fzgx_offset_0[];
extern u8 lbl_1_data_3C484__fzgx_offset_0[];
extern u8 lbl_1_data_3C498__fzgx_offset_0[];
extern u8 lbl_1_data_3C4AC__fzgx_offset_0[];
extern u8 lbl_1_data_3C4C0__fzgx_offset_0[];
extern u8 lbl_1_data_3C4D8__fzgx_offset_0[];
extern u8 lbl_1_data_3C4F4__fzgx_offset_0[];
extern u8 lbl_1_data_3C50C__fzgx_offset_0[];
extern u8 lbl_1_data_3C520__fzgx_offset_0[];
extern u8 lbl_1_data_3C538__fzgx_offset_0[];
extern u8 lbl_1_data_3C550__fzgx_offset_0[];
extern u8 lbl_1_data_3C568__fzgx_offset_0[];
extern u8 lbl_1_data_3C578__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_35AC8[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4040000
};
static u32 fzgx_pool_data_lbl_1_data_35ACC[6873] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x0, 0x4C415000, (u32)lbl_1_data_35ACC__fzgx_offset_0, (u32)lbl_1_data_35AD8__fzgx_offset_0, (u32)lbl_1_data_35AE0__fzgx_offset_0, (u32)lbl_1_data_35AEC__fzgx_offset_0, (u32)lbl_1_data_35AF4__fzgx_offset_0, (u32)lbl_1_data_35B00__fzgx_offset_0,
    (u32)lbl_1_data_35B08__fzgx_offset_0, (u32)lbl_1_data_35B10__fzgx_offset_0, 0x2E2F6D65, 0x6D636172, 0x642F656D, 0x625F652E, 0x62696E00, 0x2E2F6D65,
    0x6D636172, 0x642F656D, 0x622E6269, 0x6E000000, (u32)lbl_1_data_35B34__fzgx_offset_0, (u32)lbl_1_data_35B34__fzgx_offset_0, (u32)lbl_1_data_35B34__fzgx_offset_0, (u32)lbl_1_data_35B34__fzgx_offset_0,
    (u32)lbl_1_data_35B34__fzgx_offset_0, (u32)lbl_1_data_35B48__fzgx_offset_0, 0x2E2F6D65, 0x6D636172, 0x642F6768, 0x6F5F652E, 0x62696E00, 0x2E2F6D65,
    0x6D636172, 0x642F6768, 0x6F2E6269, 0x6E000000, (u32)lbl_1_data_35B74__fzgx_offset_0, (u32)lbl_1_data_35B74__fzgx_offset_0, (u32)lbl_1_data_35B74__fzgx_offset_0, (u32)lbl_1_data_35B74__fzgx_offset_0,
    (u32)lbl_1_data_35B74__fzgx_offset_0, (u32)lbl_1_data_35B88__fzgx_offset_0, 0x2E2F6D65, 0x6D636172, 0x642F7265, 0x705F652E, 0x62696E00, 0x2E2F6D65,
    0x6D636172, 0x642F7265, 0x702E6269, 0x6E000000, (u32)lbl_1_data_35BB4__fzgx_offset_0, (u32)lbl_1_data_35BB4__fzgx_offset_0, (u32)lbl_1_data_35BB4__fzgx_offset_0, (u32)lbl_1_data_35BB4__fzgx_offset_0,
    (u32)lbl_1_data_35BB4__fzgx_offset_0, (u32)lbl_1_data_35BC8__fzgx_offset_0, 0x41204D65, 0x6D6F7279, 0x20436172, 0x64206973, 0x206E6F74, 0x20696E73,
    0x65727465, 0x6420696E, 0x20534C4F, 0x542E0A50, 0x6C656173, 0x65207072, 0x6F706572, 0x6C792069,
    0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x6172642E, 0x0, 0x4E4F4341, 0x52442047,
    0x45520000, 0x4E4F4341, 0x52442046, 0x52410000, 0x4E4F4341, 0x52442053, 0x50410000, 0x4E4F4341,
    0x52442049, 0x54410000, 0x534C4F54, 0x82C98381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82AA8CA9,  /* fzgx-allow: A1 retail data bytes */
    0x5B82DD5D, 0x82C282A9, 0x82E882DC, 0x82B982F1, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83,  /* fzgx-allow: A1 retail data bytes */
    0x6882CC90, 0xDA5B82B9, 0x82C25D91, 0xB15B82BC, 0x82AD5D82, 0xF08A6D5B, 0x82A982AD, 0x5D94465B,
    0x82C982F1, 0x5D82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x64657669, 0x63652069,
    0x6E20534C, 0x4F542069, 0x73206E6F, 0x74207375, 0x70706F72, 0x7465642E, 0xA506C65, 0x61736520,
    0x696E7365, 0x72742061, 0x204D656D, 0x6F727920, 0x43617264, 0x2E000000, 0x57524F4E, 0x47444556,
    0x49434520, 0x47455200, 0x57524F4E, 0x47444556, 0x49434520, 0x46524100, 0x57524F4E, 0x47444556,
    0x49434520, 0x53504100, 0x57524F4E, 0x47444556, 0x49434520, 0x49544100, 0x534C4F54, 0x82C982CD,
    0xA838183, 0x82838A81, 0x5B834A81, 0x5B836888, 0xC85B82A2, 0x5D8A4F5B, 0x82AA82A2, 0x5D82CC82,
    0xE082CC82, 0xAA82B382, 0xB382C182, 0xC482A282, 0xDC82B781, 0x420A8381, 0x8382838A, 0x815B834A,  /* fzgx-allow: A1 retail data bytes */
    0x815B8368, 0x82F082B3, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x41206661, 0x74616C20,  /* fzgx-allow: A1 retail data bytes */
    0x6572726F, 0x72206861, 0x73206F63, 0x63757265, 0x642E0A54, 0x75726E20, 0x74686520, 0x706F7765,
    0x72206F66, 0x6620616E, 0x64207265, 0x66657220, 0x746F2074, 0x6865204E, 0x696E7465, 0x6E646F20,
    0x47616D65, 0x43756265, 0xA686172, 0x64776172, 0x65206D61, 0x6E75616C, 0x20666F72, 0x20646574,
    0x61696C73, 0x2E200000, 0x46415441, 0x4C204745, 0x52000000, 0x46415441, 0x4C204652, 0x41000000,
    0x46415441, 0x4C205350, 0x41000000, 0x46415441, 0x4C204954, 0x41000000, 0x92765B82, 0xBF5D96BD,
    0x5B82DF82, 0xA25D9349, 0x5B82C482, 0xAB5D82C8, 0x83478389, 0x815B82AA, 0x8B4E5B82, 0xA85D82B1,  /* fzgx-allow: A1 retail data bytes */
    0x82E882DC, 0x82B582BD, 0x81420A0A, 0x967B5B82, 0xD982F15D, 0x91CC5B82, 0xBD82A25D, 0x82CC8370,  /* fzgx-allow: A1 retail data bytes */
    0x838F815B, 0x837B835E, 0x839382F0, 0x899F5B82, 0xA85D82B5, 0x82C40A93, 0x645B82C5, 0x82F15D8C,
    0xB95B82B0, 0x82F15D82, 0xF0826E82, 0x65826582, 0xC982B581, 0x410A967B, 0x5B82D982, 0xF15D91CC,
    0x5B82BD82, 0xA25D82CC, 0x8EE65B82, 0xC65D82E8, 0x88B55B82, 0xA082C282, 0xA95D82A2, 0x90E05B82,
    0xB982C25D, 0x96BE5B82, 0xDF82A25D, 0x8F915B82, 0xB582E55D, 0x82CC0A8E, 0x775B82B5, 0x5D8EA65B,
    0x82B65D82, 0xC98F5D5B, 0x82B582BD, 0x82AA5D82, 0xC182C482, 0xAD82BE82, 0xB382A281, 0x42000000,
    0x54686973, 0x20646174, 0x61207665, 0x7273696F, 0x6E206973, 0x20696E63, 0x6F727265, 0x63742E0A,
    0x53617665, 0x2067616D, 0x65206461, 0x74612061, 0x6761696E, 0x20696E20, 0x74686520, 0x47616D65,
    0x20446174, 0x61206D65, 0x6E752069, 0x6E204F70, 0x74696F6E, 0x732E2000, 0x56455253, 0x494F4E20,
    0x47455200, 0x56455253, 0x494F4E20, 0x46524100, 0x56455253, 0x494F4E20, 0x53504100, 0x56455253,
    0x494F4E20, 0x49544100, 0x8366815B, 0x835E82CC, 0x836F815B, 0x83578387, 0x839382AA, 0x88E15B82,
    0xBF82AA5D, 0x82A282DC, 0x82B78142, 0xA834983, 0x76835683, 0x87839382, 0xCC835181, 0x5B838083,
    0x66815B83, 0x5E82C50A, 0x8366815B, 0x835E82F0, 0x835A815B, 0x837582B5, 0x92BC5B82, 0xC882A85D,
    0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077,  /* fzgx-allow: A1 retail data bytes */
    0x6974686F, 0x7574206C, 0x6F616469, 0x6E670A20, 0x2083B220, 0x81632054, 0x72792061, 0x6761696E,  /* fzgx-allow: A1 retail data bytes */
    0x20000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52592047, 0x45520000, 0x43415054,
    0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F, 0x4C4F4144,
    0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52592049,
    0x54410000, 0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083,
    0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F,
    0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E200000, 0x43415054,
    0x494F4E5F, 0x53415645, 0x5F524554, 0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x53415645,
    0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592053,
    0x50410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163,
    0x835A815B, 0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083, 0xB2816383, 0x8A836783,
    0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E,
    0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E000000, 0x43415054, 0x494F4E5F, 0x4C495354,
    0x5F524554, 0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52592046,
    0x52410000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F524554, 0x52592053, 0x50410000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163, 0x838A8358, 0x836782F0,
    0x8EE65B82, 0xC65D82E7, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083, 0xB2816383, 0x8A836783,
    0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742065, 0x72617369,
    0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E2000, 0x43415054, 0x494F4E5F, 0x44454C45,
    0x54455F52, 0x45545259, 0x20474552, 0x0, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52,
    0x45545259, 0x20465241, 0x0, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259,
    0x20535041, 0x0, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20495441,
    0x0, 0x839F8163, 0x8FC15B82, 0xAF5D82B3, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E92083,
    0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F,
    0x75742063, 0x6865636B, 0x696E670A, 0x83B22081, 0x63205472, 0x79206167, 0x61696E20, 0x0,
    0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20474552, 0x0, 0x43415054,
    0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x20465241, 0x0, 0x43415054, 0x494F4E5F,
    0x44454C45, 0x54455F52, 0x45545259, 0x20535041, 0x0, 0x43415054, 0x494F4E5F, 0x44454C45,
    0x54455F52, 0x45545259, 0x20495441, 0x0, 0x839F8163, 0x83608346, 0x8362834E, 0x82B982B8,
    0x82C98F49, 0x5B82A85D, 0x82ED82E9, 0x2083B281, 0x63838A83, 0x67838983, 0x43000000, 0x839F2081,
    0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x7574206C, 0x6F616469, 0x6E670A83, 0xB2208163,
    0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x2043686F, 0x6F736520, 0x536C6F74, 0x20000000,
    0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204745, 0x52000000,
    0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204652, 0x41000000,
    0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45205350, 0x41000000,
    0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204954, 0x41000000,
    0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383,
    0x8A836783, 0x89834320, 0x83B48163, 0x8358838D, 0x83628367, 0x82F09149, 0x5B82A682, 0xE75D82D4,
    0x0, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E,
    0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E0A83B4, 0x20816320, 0x43686F6F, 0x73652053,
    0x6C6F7420, 0x0, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943,
    0x45204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943,
    0x45204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943,
    0x45205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F43, 0x484F4943,
    0x45204954, 0x41000000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED,
    0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x8358838D, 0x83628367, 0x82F09149,
    0x5B82A682, 0xE75D82D4, 0x0, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F,
    0x75742073, 0x6176696E, 0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E200000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204745, 0x52000000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F43, 0x484F4943, 0x45204954, 0x41000000, 0x839F8163,
    0x838A8358, 0x836782F0, 0x8EE65B82, 0xC65D82E7, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83,
    0xB2816383, 0x8A836783, 0x89834300, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F,
    0x75742065, 0x72617369, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163,
    0x2043686F, 0x6F736520, 0x536C6F74, 0x20000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52,
    0x45545259, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52,
    0x45545259, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52,
    0x45545259, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52,
    0x45545259, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x8FC15B82, 0xAF5D82B3, 0x82B882C9,
    0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x8358838D,
    0x83628367, 0x82F09149, 0x5B82A682, 0xE75D82D4, 0x0, 0x839F2081, 0x6320436F, 0x6E74696E,
    0x75652077, 0x6974686F, 0x75742063, 0x6865636B, 0x696E670A, 0x83B22081, 0x63205472, 0x79206167,
    0x61696E0A, 0x83B42081, 0x63204368, 0x6F6F7365, 0x20536C6F, 0x74200000, 0x43415054, 0x494F4E5F,
    0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F,
    0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054, 0x494F4E5F,
    0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F,
    0x44454C45, 0x54455F52, 0x45545259, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x83608346,
    0x8362834E, 0x82B982B8, 0x82C98F49, 0x5B82A85D, 0x82ED82E9, 0xA83B281, 0x63838A83, 0x67838983,
    0x432083B4, 0x81638358, 0x838D8362, 0x836782F0, 0x91495B82, 0xA682E75D, 0x82D40000, 0x506C6561,  /* fzgx-allow: A1 retail data bytes */
    0x73652070, 0x72657373, 0x20746865, 0x20839F20, 0x42757474, 0x6F6E2E20, 0x0, 0x43415054,
    0x494F4E5F, 0x41204745, 0x52000000, 0x43415054, 0x494F4E5F, 0x41204652, 0x41000000, 0x43415054,
    0x494F4E5F, 0x41205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x41204954, 0x41000000, 0x839F82F0,
    0x899F5B82, 0xA85D82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0, 0x839F2081, 0x63204465,
    0x6C657465, 0x2066696C, 0x65000000, 0x43415054, 0x494F4E5F, 0x41204745, 0x52000000, 0x43415054,
    0x494F4E5F, 0x41204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x41205350, 0x41000000, 0x43415054,
    0x494F4E5F, 0x41204954, 0x41000000, 0x839F8163, 0x8FC15B82, 0xAF5D82B7, 0x0, 0x839F2081,
    0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x7574206C, 0x6F616469, 0x6E670A83, 0xB4208163,
    0x2043686F, 0x6F736520, 0x6120536C, 0x6F742000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F43484F,
    0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F43484F, 0x49434520, 0x46524100,
    0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F,
    0x4C4F4144, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9,
    0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB4816383, 0x58838D83, 0x62836782, 0xF091495B, 0x82A682E7,
    0x5D82D400, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E,
    0x670A83B4, 0x20816320, 0x43686F6F, 0x73652061, 0x20536C6F, 0x74200000, 0x43415054, 0x494F4E5F,
    0x53415645, 0x5F43484F, 0x49434520, 0x47455200, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F43484F,
    0x49434520, 0x46524100, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F43484F, 0x49434520, 0x53504100,
    0x43415054, 0x494F4E5F, 0x53415645, 0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x835A815B,
    0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB4816383, 0x58838D83, 0x62836782,
    0xF091495B, 0x82A682E7, 0x5D82D400, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F,
    0x75742073, 0x6176696E, 0x67000000, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F43484F, 0x49434520,
    0x47455200, 0x43415054, 0x494F4E5F, 0x4C495354, 0x5F43484F, 0x49434520, 0x46524100, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F43484F, 0x49434520, 0x53504100, 0x43415054, 0x494F4E5F, 0x4C495354,
    0x5F43484F, 0x49434520, 0x49544100, 0x839F8163, 0x838A8358, 0x836782F0, 0x8EE65B82, 0xC65D82E7,
    0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077,
    0x6974686F, 0x75742065, 0x72617369, 0x6E670A83, 0xB4208163, 0x2043686F, 0x6F736520, 0x6120536C,
    0x6F742000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204745, 0x52000000,
    0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054,
    0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054, 0x494F4E5F,
    0x44454C45, 0x54455F43, 0x484F4943, 0x45204954, 0x41000000, 0x839F8163, 0x82AF82B3, 0x82B882C9,
    0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB4816383, 0x58838D83, 0x62836782, 0xF091495B, 0x82A682E7,
    0x5D82D400, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742063, 0x6865636B,
    0x696E670A, 0x83B42081, 0x63204368, 0x6F6F7365, 0x20612053, 0x6C6F7420, 0x0, 0x43415054,
    0x494F4E5F, 0x44454C45, 0x54455F43, 0x484F4943, 0x45204745, 0x52000000, 0x43415054, 0x494F4E5F,
    0x44454C45, 0x54455F43, 0x484F4943, 0x45204652, 0x41000000, 0x43415054, 0x494F4E5F, 0x44454C45,
    0x54455F43, 0x484F4943, 0x45205350, 0x41000000, 0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F43,
    0x484F4943, 0x45204954, 0x41000000, 0x839F8163, 0x83608346, 0x8362834E, 0x82B982B8, 0x82C98F49,
    0x5B82A85D, 0x82ED82E9, 0xA83B481, 0x63835883, 0x8D836283, 0x6782F091, 0x495B82A6, 0x82E75D82,
    0xD4000000, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x7574206C, 0x6F616469,
    0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x20466F72, 0x6D617420,
    0x0, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204745,
    0x52000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204652,
    0x41000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54205350,
    0x41000000, 0x43415054, 0x494F4E5F, 0x4C4F4144, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204954,
    0x41000000, 0x839F8163, 0x838D815B, 0x836882B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83,
    0xB2816383, 0x8A836783, 0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E,
    0x670A83B2, 0x20816320, 0x54727920, 0x61676169, 0x6E0A83B4, 0x20816320, 0x466F726D, 0x61742000,
    0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204745, 0x52000000,
    0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204652, 0x41000000,
    0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54205350, 0x41000000,
    0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204954, 0x41000000,
    0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383,
    0x8A836783, 0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742073, 0x6176696E, 0x670A83B2,
    0x20816320, 0x54727920, 0x61676169, 0x6E0A83B4, 0x20816320, 0x466F726D, 0x61742000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204745, 0x52000000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204652, 0x41000000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54205350, 0x41000000, 0x43415054,
    0x494F4E5F, 0x4C495354, 0x5F524554, 0x52595F46, 0x4F524D41, 0x54204954, 0x41000000, 0x839F8163,
    0x838A8358, 0x836782F0, 0x82C682E7, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383,
    0x8A836783, 0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x839F2081, 0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742065, 0x72617369, 0x6E670A83,
    0xB2208163, 0x20547279, 0x20616761, 0x696E0A83, 0xB4208163, 0x20466F72, 0x6D617420, 0x0,
    0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x47455200,
    0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x46524100,
    0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x53504100,
    0x43415054, 0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x49544100,
    0x839F8163, 0x82AF82B3, 0x82B882C9, 0x8F495B82, 0xA85D82ED, 0x82E90A83, 0xB2816383, 0x8A836783,
    0x89834320, 0x83B48163, 0x83748348, 0x815B837D, 0x83628367, 0x82B782E9, 0x0, 0x839F2081,  /* fzgx-allow: A1 retail data bytes */
    0x6320436F, 0x6E74696E, 0x75652077, 0x6974686F, 0x75742063, 0x6865636B, 0x696E670A, 0x83B22081,
    0x63205472, 0x79206167, 0x61696E0A, 0x83B42081, 0x6320466F, 0x726D6174, 0x20000000, 0x43415054,
    0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x47455200, 0x43415054,
    0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x46524100, 0x43415054,
    0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x53504100, 0x43415054,
    0x494F4E5F, 0x44454C45, 0x54455F52, 0x45545259, 0x5F464F52, 0x4D415420, 0x49544100, 0x839F8163,
    0x83608346, 0x8362834E, 0x82B982B8, 0x82C98F49, 0x5B82A85D, 0x82ED82E9, 0xA83B281, 0x63838A83,
    0x67838983, 0x432083B4, 0x81638374, 0x8348815B, 0x837D8362, 0x836782B7, 0x82E90000, 0x839F2081,  /* fzgx-allow: A1 retail data bytes */
    0x63204265, 0x67696E20, 0x77697468, 0x6F757420, 0x73617665, 0x696E670A, 0x83B22081, 0x63205472,
    0x79206167, 0x61696E00, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592047, 0x45520000,
    0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592046, 0x52410000, 0x43415054, 0x494F4E5F,
    0x53415645, 0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554,
    0x52592049, 0x54410000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9, 0x8E6E5B82, 0xCD82B65D,
    0x82DF82E9, 0x2083B281, 0x63838A83, 0x67838983, 0x43000000, 0x839F2081, 0x63204265, 0x67696E20,
    0x77697468, 0x6F757420, 0x73617669, 0x6E670A83, 0xB2208163, 0x20547279, 0x20616761, 0x696E0A83,
    0xB4208163, 0x20526573, 0x65742061, 0x6E642061, 0x63636573, 0x73207379, 0x7374656D, 0x204D656D,
    0x6F727920, 0x43617264, 0x20736372, 0x65656E00, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554,
    0x52592047, 0x45520000, 0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592046, 0x52410000,
    0x43415054, 0x494F4E5F, 0x53415645, 0x5F524554, 0x52592053, 0x50410000, 0x43415054, 0x494F4E5F,
    0x53415645, 0x5F524554, 0x52592049, 0x54410000, 0x839F8163, 0x835A815B, 0x837582B9, 0x82B882C9,
    0x8E6E5B82, 0xCD82B65D, 0x82DF82E9, 0x2083B281, 0x63838A83, 0x67838983, 0x430A83B4, 0x8163838A,  /* fzgx-allow: A1 retail data bytes */
    0x835A8362, 0x836782B5, 0x82C4967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D8381, 0x8382838A,
    0x815B834A, 0x815B8368, 0x89E65B82, 0xAA5D96CA, 0x5B82DF82, 0xF15D82D6, 0x0, 0x43686F6F,  /* fzgx-allow: A1 retail data bytes */
    0x73652074, 0x68652053, 0x6C6F7420, 0x77697468, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264,
    0x20696E73, 0x65727465, 0x642E2000, 0x43484F49, 0x43455F53, 0x4C4F5420, 0x47455200, 0x43484F49,
    0x43455F53, 0x4C4F5420, 0x46524100, 0x43484F49, 0x43455F53, 0x4C4F5420, 0x53504100, 0x43484F49,
    0x43455F53, 0x4C4F5420, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x82B382B5,
    0x82BD8358, 0x838D8362, 0x836782F0, 0xA91495B, 0x82A682E7, 0x5D82F182, 0xC582AD82, 0xBE82B382,
    0xA2814200, 0x55736520, 0x2083AD20, 0x6F722083, 0xB5746F20, 0x73656C65, 0x63742E0A, 0x50726573,
    0x73207468, 0x6520839F, 0x20427574, 0x746F6E20, 0x746F2063, 0x6F6E6669, 0x726D2061, 0x6E642074,
    0x68652083, 0xA0204275, 0x74746F6E, 0x2063616E, 0x63656C2E, 0x20000000, 0x43415054, 0x494F4E5F,
    0x43484F49, 0x43452047, 0x45520000, 0x43415054, 0x494F4E5F, 0x43484F49, 0x43452046, 0x52410000,
    0x43415054, 0x494F4E5F, 0x43484F49, 0x43452053, 0x50410000, 0x43415054, 0x494F4E5F, 0x43484F49,
    0x43452049, 0x54410000, 0x83AD82A9, 0x83B582C5, 0x91495B82, 0xA682E75D, 0x82F182C5, 0x8141839F,  /* fzgx-allow: A1 retail data bytes */
    0x82C58C88, 0x5B82AB5D, 0x82DF82C4, 0x82AD82BE, 0x82B382A2, 0x81420A83, 0xA082C583, 0x4C838383,  /* fzgx-allow: A1 retail data bytes */
    0x93835A83, 0x8B82B582, 0xDC82B781, 0x42000000, 0x54686520, 0x46494C45, 0x20446174, 0x61207361,
    0x76652074, 0x6F207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x640A696E, 0x20534C4F, 0x54206861,
    0x73206265, 0x656E2063, 0x616E6365, 0x6C6C6564, 0x2E000000, 0x4E4F5341, 0x56455F45, 0x58495420,
    0x47455200, 0x4E4F5341, 0x56455F45, 0x58495420, 0x46524100, 0x4E4F5341, 0x56455F45, 0x58495420,
    0x53504100, 0x4E4F5341, 0x56455F45, 0x58495420, 0x49544100, 0x46494C45, 0x8366815B, 0x835E82CC,
    0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xD682CC83, 0x5A815B83, 0x7582F092, 0x865B82BF,
    0x82E382A4, 0x5D8E7E5B, 0x82B55D82, 0xB582DC82, 0xB582BD81, 0x42000000, 0x54686520, 0x4D656D6F,
    0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732064, 0x616D6167, 0x65642061, 0x6E642063,
    0x616E6E6F, 0x74206265, 0x20757365, 0x642E0000, 0x57524F4E, 0x475F5345, 0x43544F52, 0x20474552,
    0x0, 0x57524F4E, 0x475F5345, 0x43544F52, 0x20465241, 0x0, 0x57524F4E, 0x475F5345,
    0x43544F52, 0x20535041, 0x0, 0x57524F4E, 0x475F5345, 0x43544F52, 0x20495441, 0x0,
    0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD0A82, 0xB182ED82, 0xEA82C482,  /* fzgx-allow: A1 retail data bytes */
    0xA282E982, 0xCC82C58E, 0x675B82B5, 0x5D97705B, 0x82E682A4, 0x5D82C582, 0xAB82DC82, 0xB982F181,
    0x42000000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732064,
    0x616D6167, 0x65642061, 0x6E642063, 0x616E6E6F, 0x74206265, 0x20757365, 0x642E0000, 0x57524F4E,
    0x475F4341, 0x52442047, 0x45520000, 0x57524F4E, 0x475F4341, 0x52442046, 0x52410000, 0x57524F4E,
    0x475F4341, 0x52442053, 0x50410000, 0x57524F4E, 0x475F4341, 0x52442049, 0x54410000, 0x534C4F54,
    0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD0A82, 0xB182ED82, 0xEA82C482, 0xA282E982,  /* fzgx-allow: A1 retail data bytes */
    0xCC82C58E, 0x675B82B5, 0x5D97705B, 0x82E682A4, 0x5D82C582, 0xAB82DC82, 0xB982F181, 0x42000000,
    0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732063, 0x6F727275,
    0x70746564, 0x20616E64, 0x206D7573, 0x74206265, 0x20666F72, 0x6D617474, 0x65642E0A, 0x4F4B2074,
    0x6F20666F, 0x726D6174, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x206E6F77, 0x3F000000,
    0x454E434F, 0x44494E47, 0x20474552, 0x0, 0x454E434F, 0x44494E47, 0x20465241, 0x0,
    0x454E434F, 0x44494E47, 0x20535041, 0x0, 0x454E434F, 0x44494E47, 0x20495441, 0x0,
    0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD8E67, 0x5B82C282, 0xA95D82A6,  /* fzgx-allow: A1 retail data bytes */
    0x82DC82B9, 0x82F18142, 0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF093FC5B, 0x82A25D82,
    0xEA92BC5B, 0x82C882A8, 0x5D82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x4D656D6F,
    0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732063, 0x6F727275, 0x70746564, 0x20616E64,
    0x206D7573, 0x74206265, 0x20666F72, 0x6D617474, 0x65642E00, 0x454E434F, 0x44494E47, 0x20474552,
    0x0, 0x454E434F, 0x44494E47, 0x20465241, 0x0, 0x454E434F, 0x44494E47, 0x20535041,
    0x0, 0x454E434F, 0x44494E47, 0x20495441, 0x0, 0x534C4F54, 0x82CC8381, 0x8382838A,
    0x815B834A, 0x815B8368, 0x82CD8E67, 0x5B82C282, 0xA95D82A6, 0x82DC82B9, 0x82F18142, 0xA838183,  /* fzgx-allow: A1 retail data bytes */
    0x82838A81, 0x5B834A81, 0x5B836882, 0xF093FC5B, 0x82A25D82, 0xEA92BC5B, 0x82C882A8, 0x5D82B582,
    0xC482AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053,
    0x4C4F540A, 0x69732063, 0x6F727275, 0x70746564, 0x20616E64, 0x206D7573, 0x74206265, 0x20666F72,
    0x6D617474, 0x65642E0A, 0x4F4B2074, 0x6F20666F, 0x726D6174, 0x20746865, 0x204D656D, 0x6F727920,
    0x43617264, 0x206E6F77, 0x3F000000, 0x464F524D, 0x41545F51, 0x55455259, 0x20474552, 0x0,
    0x464F524D, 0x41545F51, 0x55455259, 0x20465241, 0x0, 0x464F524D, 0x41545F51, 0x55455259,
    0x20535041, 0x0, 0x464F524D, 0x41545F51, 0x55455259, 0x20495441, 0x0, 0x534C4F54,
    0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD8366, 0x815B835E, 0x82AA0A82, 0xB182ED82,  /* fzgx-allow: A1 retail data bytes */
    0xEA82C482, 0xA282E982, 0xCC82C583, 0x74834881, 0x5B837D83, 0x62836782, 0xAA954B97, 0x7682C582,
    0xB781420A, 0x83748348, 0x815B837D, 0x83628367, 0x82B582C4, 0x82E082E6, 0x82EB82B5, 0x82A282C5,  /* fzgx-allow: A1 retail data bytes */
    0x82B782A9, 0x81480000, 0x4F4B2074, 0x6F20666F, 0x726D6174, 0x20746865, 0xA4D656D, 0x6F727920,  /* fzgx-allow: A1 retail data bytes */
    0x43617264, 0x20696E20, 0x534C4F54, 0x3F000000, 0x464F524D, 0x41545F51, 0x55455259, 0x32204745,
    0x52000000, 0x464F524D, 0x41545F51, 0x55455259, 0x32204652, 0x41000000, 0x464F524D, 0x41545F51,
    0x55455259, 0x32205350, 0x41000000, 0x464F524D, 0x41545F51, 0x55455259, 0x32204954, 0x41000000,
    0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82F00A83, 0x74834881, 0x5B837D83,  /* fzgx-allow: A1 retail data bytes */
    0x62836782, 0xB582C482, 0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A981, 0x48000000, 0x536C6F74,
    0x20410000, 0x534C4F54, 0x5F412047, 0x45520000, 0x534C4F54, 0x5F412046, 0x52410000, 0x534C4F54,
    0x5F412053, 0x50410000, 0x534C4F54, 0x5F412049, 0x54410000, 0x8358838D, 0x83628367, 0x82600000,
    0x536C6F74, 0x20420000, 0x534C4F54, 0x5F422047, 0x45520000, 0x534C4F54, 0x5F422046, 0x52410000,
    0x534C4F54, 0x5F422053, 0x50410000, 0x534C4F54, 0x5F422049, 0x54410000, 0x8358838D, 0x83628367,
    0x82610000, 0x59455300, 0x48414920, 0x47455200, 0x48414920, 0x46524100, 0x48414920, 0x53504100,
    0x48414920, 0x49544100, 0x82CD82A2, 0x0, 0x4E4F0000, 0x49494520, 0x47455200, 0x49494520,
    0x46524100, 0x49494520, 0x53504100, 0x49494520, 0x49544100, 0x82A282A2, 0x82A60000, 0x466F726D,
    0x61747469, 0x6E67206F, 0x66207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F,
    0x540A6861, 0x73206265, 0x656E2063, 0x616E6365, 0x6C6C6564, 0x2E000000, 0x464F524D, 0x41545F43,
    0x414E4345, 0x4C204745, 0x52000000, 0x464F524D, 0x41545F43, 0x414E4345, 0x4C204652, 0x41000000,
    0x464F524D, 0x41545F43, 0x414E4345, 0x4C205350, 0x41000000, 0x464F524D, 0x41545F43, 0x414E4345,
    0x4C204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83,  /* fzgx-allow: A1 retail data bytes */
    0x74834881, 0x5B837D83, 0x62836782, 0xF092865B, 0x82BF82E3, 0x5D8E7E5B, 0x82A482B5, 0x5D82B582,
    0xDC82B582, 0xBD814200, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420,
    0x646F6573, 0x206E6F74, 0x20686176, 0x650A656E, 0x6F756768, 0x20667265, 0x65207370, 0x6163652E,
    0x20462D5A, 0x45524F20, 0x47582072, 0x65717569, 0x72657320, 0x7468650A, 0x666F6C6C, 0x6F77696E,
    0x6720746F, 0x20736176, 0x65206974, 0x73206469, 0x66666572, 0x656E7420, 0x74797065, 0x73206F66,
    0x20646174, 0x613A0A28, 0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D,
    0x656D6F72, 0x79204361, 0x72642C0A, 0x706C6561, 0x73652067, 0x6F20746F, 0x20746865, 0x204E696E,
    0x74656E64, 0x6F204761, 0x6D654375, 0x62650A4D, 0x656D6F72, 0x79204361, 0x7264206D, 0x616E6167,
    0x656D656E, 0x74207363, 0x7265656E, 0x2E290A47, 0x616D6520, 0x44617461, 0x3A203120, 0x46696C65,
    0x20616E64, 0x20342042, 0x6C6F636B, 0x730A4761, 0x72616765, 0x20446174, 0x613A2031, 0x2046696C,
    0x6520616E, 0x64203138, 0x20426C6F, 0x636B730A, 0x47686F73, 0x74204461, 0x74613A20, 0x31204669,
    0x6C652061, 0x6E642033, 0x20426C6F, 0x636B730A, 0x456D626C, 0x656D2044, 0x6174613A, 0x20312046,
    0x696C6520, 0x616E6420, 0x3320426C, 0x6F636B73, 0xA526570, 0x6C617920, 0x44617461, 0x3A203120,
    0x46696C65, 0x20616E64, 0x20338160, 0x31332042, 0x6C6F636B, 0x73000000, 0x4E4F454E, 0x54204745,
    0x52000000, 0x4E4F454E, 0x54204652, 0x41000000, 0x4E4F454E, 0x54205350, 0x41000000, 0x4E4F454E,
    0x54204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C98BF3,  /* fzgx-allow: A1 retail data bytes */
    0x5B82A05D, 0x82AB9765, 0x5B82E682, 0xA4205D97, 0xCA5B82E8, 0x82E582A4, 0x5D82AA82, 0xC882A282,
    0xA981410A, 0x83748340, 0x8343838B, 0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0,
    0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A46,  /* fzgx-allow: A1 retail data bytes */
    0x2D5A4552, 0x4F204758, 0x82CC8A65, 0x5B82A982, 0xAD5D8374, 0x83408343, 0x838B82F0, 0x835A815B,
    0x837582B7, 0x82E982C9, 0x82CD0A8F, 0xAD5B82B7, 0x82AD5D82, 0xC882AD82, 0xC682E088, 0xC85B82A2,
    0x5D89BA5B, 0x82A95D82, 0xCC8BF35B, 0x82A05D82, 0xAB97655B, 0x82E682A4, 0x205D97CA, 0x5B82E882,
    0xE582A45D, 0x82AA954B, 0x5B82D082, 0xC25D9776, 0x5B82E682, 0xA45D82C5, 0x82B78142, 0xA288381,
    0x8382838A, 0x815B834A, 0x815B8368, 0x82CC93E0, 0x5B82C882, 0xA25D9765, 0x5B82E682, 0xA45D82F0,  /* fzgx-allow: A1 retail data bytes */
    0x90AE5B82, 0xB982A25D, 0x979D5B82, 0xE85D82B7, 0x82E982C9, 0x82CD8141, 0xA967B5B, 0x82D982F1,
    0x5D91CC5B, 0x82BD82A2, 0x5D82CC83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6889E65B, 0x82AA5D96,
    0xCA5B82DF, 0x82F15D82, 0xC58D735B, 0x82A882B1, 0x5D82C882, 0xC182C482, 0xAD82BE82, 0xB382A229,
    0xA202083, 0x51815B83, 0x80836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68253,  /* fzgx-allow: A1 retail data bytes */
    0x8375838D, 0x8362834E, 0xA20834B, 0x838C815B, 0x83578366, 0x815B835E, 0x3A837483, 0x40834383,  /* fzgx-allow: A1 retail data bytes */
    0x8B825082, 0xC282C682, 0x50825783, 0x75838D83, 0x62834E0A, 0x20835381, 0x5B835883, 0x67836681,
    0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68252, 0x8375838D, 0x8362834E, 0xA834783,
    0x93837583, 0x8C838083, 0x66815B83, 0x5E3A8374, 0x83408343, 0x838B8250, 0x82C282C6, 0x82528375,
    0x838D8362, 0x834E0A20, 0x20838A83, 0x76838C83, 0x43836681, 0x5B835E3A, 0x83748340, 0x8343838B,
    0x825082C2, 0x82C68252, 0x81608250, 0x82528375, 0x838D8362, 0x834E0A00, 0x54686572, 0x65206973,  /* fzgx-allow: A1 retail data bytes */
    0x206E6F74, 0x20656E6F, 0x75676820, 0x66726565, 0x20737061, 0x6365206F, 0x6E207468, 0x650A4D65,
    0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E2054, 0x6F207361, 0x76652046, 0x494C4520,
    0x44617461, 0x2C0A796F, 0x75206E65, 0x65642061, 0x74206C65, 0x61737420, 0x31206669, 0x6C652061,
    0x6E642052, 0x45515549, 0x52454420, 0x626C6F63, 0x6B732E0A, 0x28546F20, 0x6D616E61, 0x67652066,
    0x696C6573, 0x206F6E20, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642C, 0xA706C65, 0x61736520,
    0x676F2074, 0x6F207468, 0x65204E69, 0x6E74656E, 0x646F2047, 0x616D6543, 0x7562650A, 0x4D656D6F,
    0x72792043, 0x61726420, 0x6D616E61, 0x67656D65, 0x6E742073, 0x63726565, 0x6E2E2900, 0x4E4F454E,
    0x54204745, 0x52000000, 0x4E4F454E, 0x54204652, 0x41000000, 0x4E4F454E, 0x54205350, 0x41000000,
    0x4E4F454E, 0x54204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82C98BF3, 0x5B82A05D, 0x82AB9765, 0x5B82E682, 0xA4205D97, 0xCA5B82E8, 0x82E582A4, 0x5D82AA82,
    0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982,
    0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7,
    0x81420A46, 0x494C4583, 0x66815B83, 0x5E82F083, 0x5A815B83, 0x7582B782, 0xE982C982, 0xCD0A8FAD,  /* fzgx-allow: A1 retail data bytes */
    0x5B82B782, 0xAD5D82C8, 0x82AD82C6, 0x82E08374, 0x83408343, 0x838B3182, 0xC282C652, 0x45515549,
    0x52454483, 0x75838D83, 0x62834E95, 0x4B5B82D0, 0x82C25D97, 0x765B82E6, 0x82A45D82, 0xC582B781,
    0x420A2883, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CC93, 0xE05B82C8, 0x82A25D97, 0x655B82E6,
    0x82A45D82, 0xF090AE5B, 0x82B982A2, 0x5D979D5B, 0x82E85D82, 0xB782E982, 0xC982CD81, 0x410A967B,
    0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D82CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836889E6,
    0x5B82AA5D, 0x96CA5B82, 0xDF82F15D, 0x82C58D73, 0x5B82A882, 0xB15D82C8, 0x82C182C4, 0x82AD82BE,
    0x82B382A2, 0x290A0000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420,
    0x646F6573, 0x206E6F74, 0x20686176, 0x650A656E, 0x6F756768, 0x20667265, 0x65207370, 0x6163652E,
    0x20462D5A, 0x45524F20, 0x47582072, 0x65717569, 0x72657320, 0x7468650A, 0x666F6C6C, 0x6F77696E,
    0x6720746F, 0x20736176, 0x65206974, 0x73206469, 0x66666572, 0x656E7420, 0x74797065, 0x73206F66,
    0x20646174, 0x613A0A28, 0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D,
    0x656D6F72, 0x79204361, 0x72642C0A, 0x706C6561, 0x73652067, 0x6F20746F, 0x20746865, 0x204E696E,
    0x74656E64, 0x6F204761, 0x6D654375, 0x62650A4D, 0x656D6F72, 0x79204361, 0x7264206D, 0x616E6167,
    0x656D656E, 0x74207363, 0x7265656E, 0x2E290A47, 0x616D6520, 0x44617461, 0x3A203120, 0x46696C65,
    0x20616E64, 0x20342042, 0x6C6F636B, 0x730A4761, 0x72616765, 0x20446174, 0x613A2031, 0x2046696C,
    0x6520616E, 0x64203138, 0x20426C6F, 0x636B730A, 0x47686F73, 0x74204461, 0x74613A20, 0x31204669,
    0x6C652061, 0x6E642033, 0x20426C6F, 0x636B730A, 0x456D626C, 0x656D2044, 0x6174613A, 0x20312046,
    0x696C6520, 0x616E6420, 0x3320426C, 0x6F636B73, 0xA526570, 0x6C617920, 0x44617461, 0x3A203120,
    0x46696C65, 0x20616E64, 0x20338160, 0x31332042, 0x6C6F636B, 0x73000000, 0x494E5353, 0x50414345,
    0x20474552, 0x0, 0x494E5353, 0x50414345, 0x20465241, 0x0, 0x494E5353, 0x50414345,
    0x20535041, 0x0, 0x494E5353, 0x50414345, 0x20495441, 0x0, 0x534C4F54, 0x82CC8381,
    0x8382838A, 0x815B834A, 0x815B8368, 0x82C98BF3, 0x5B82A05D, 0x82AB9765, 0x5B82E682, 0xA4205D97,  /* fzgx-allow: A1 retail data bytes */
    0xCA5B82E8, 0x82E582A4, 0x5D82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82,
    0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6,
    0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A46, 0x2D5A4552, 0x4F204758, 0x82CC8A65, 0x5B82A982,  /* fzgx-allow: A1 retail data bytes */
    0xAD5D8374, 0x83408343, 0x838B82F0, 0x835A815B, 0x837582B7, 0x82E982C9, 0x82CD0A8F, 0xAD5B82B7,
    0x82AD5D82, 0xC882AD82, 0xC682E088, 0xC85B82A2, 0x5D89BA5B, 0x82A95D82, 0xCC8BF35B, 0x82A05D82,
    0xAB97655B, 0x82E682A4, 0x205D97CA, 0x5B82E882, 0xE582A45D, 0x82AA954B, 0x5B82D082, 0xC25D9776,
    0x5B82E682, 0xA45D82C5, 0x82B78142, 0xA288381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC93E0,  /* fzgx-allow: A1 retail data bytes */
    0x5B82C882, 0xA25D9765, 0x5B82E682, 0xA45D82F0, 0x90AE5B82, 0xB982A25D, 0x979D5B82, 0xE85D82B7,
    0x82E982C9, 0x82CD8141, 0xA967B5B, 0x82D982F1, 0x5D91CC5B, 0x82BD82A2, 0x5D82CC83, 0x81838283,
    0x8A815B83, 0x4A815B83, 0x6889E65B, 0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC58D735B, 0x82A882B1,
    0x5D82C882, 0xC182C482, 0xAD82BE82, 0xB382A229, 0xA202083, 0x51815B83, 0x80836681, 0x5B835E3A,  /* fzgx-allow: A1 retail data bytes */
    0x83748340, 0x8343838B, 0x825082C2, 0x82C68253, 0x8375838D, 0x8362834E, 0xA20834B, 0x838C815B,
    0x83578366, 0x815B835E, 0x3A837483, 0x40834383, 0x8B825082, 0xC282C682, 0x50825783, 0x75838D83,  /* fzgx-allow: A1 retail data bytes */
    0x62834E0A, 0x20835381, 0x5B835883, 0x67836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2,
    0x82C68252, 0x8375838D, 0x8362834E, 0xA834783, 0x93837583, 0x8C838083, 0x66815B83, 0x5E3A8374,
    0x83408343, 0x838B8250, 0x82C282C6, 0x82528375, 0x838D8362, 0x834E0A20, 0x20838A83, 0x76838C83,
    0x43836681, 0x5B835E3A, 0x83748340, 0x8343838B, 0x825082C2, 0x82C68252, 0x81608250, 0x82528375,  /* fzgx-allow: A1 retail data bytes */
    0x838D8362, 0x834E0A00, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420,
    0x646F6573, 0x206E6F74, 0xA686176, 0x6520656E, 0x6F756768, 0x20667265, 0x65207370, 0x6163652E,
    0x20417420, 0x6C656173, 0x74203120, 0x66696C65, 0xA616E64, 0x20524551, 0x55495245, 0x4420626C,
    0x6F636B73, 0x20617265, 0x206E6565, 0x64656420, 0x746F2073, 0x6176650A, 0x46494C45, 0x20446174,
    0x612E2028, 0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D, 0x656D6F72,
    0x790A4361, 0x72642C20, 0x706C6561, 0x73652067, 0x6F20746F, 0x20746865, 0x204E696E, 0x74656E64,
    0x6F204761, 0x6D654375, 0x62650A4D, 0x656D6F72, 0x79204361, 0x7264206D, 0x616E6167, 0x656D656E,
    0x74207363, 0x7265656E, 0x2E290000, 0x494E5353, 0x50414345, 0x5F524550, 0x4C415920, 0x47455200,
    0x494E5353, 0x50414345, 0x5F524550, 0x4C415920, 0x46524100, 0x494E5353, 0x50414345, 0x5F524550,
    0x4C415920, 0x53504100, 0x494E5353, 0x50414345, 0x5F524550, 0x4C415920, 0x49544100, 0x534C4F54,
    0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C98BF3, 0x5B82A05D, 0x82AB9765, 0x5B82E682,  /* fzgx-allow: A1 retail data bytes */
    0xA4205D97, 0xCA5B82E8, 0x82E582A4, 0x5D82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B,
    0x90945B82, 0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82,
    0xB15D82A6, 0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A46, 0x494C4583, 0x66815B83, 0x5E82F083,  /* fzgx-allow: A1 retail data bytes */
    0x5A815B83, 0x7582B782, 0xE982C982, 0xCD0A8FAD, 0x5B82B782, 0xAD5D82C8, 0x82AD82C6, 0x82E08374,
    0x83408343, 0x838B3182, 0xC282C652, 0x45515549, 0x52454483, 0x75838D83, 0x62834E95, 0x4B5B82D0,
    0x82C25D97, 0x765B82E6, 0x82A45D82, 0xC582B781, 0x420A2883, 0x81838283, 0x8A815B83, 0x4A815B83,
    0x6882CC93, 0xE05B82C8, 0x82A25D97, 0x655B82E6, 0x82A45D82, 0xF090AE5B, 0x82B982A2, 0x5D979D5B,
    0x82E85D82, 0xB782E982, 0xC982CD81, 0x410A967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D82CC,
    0x83818382, 0x838A815B, 0x834A815B, 0x836889E6, 0x5B82AA5D, 0x96CA5B82, 0xDF82F15D, 0x82C58D73,
    0x5B82A882, 0xB15D82C8, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x290A0000, 0x54686572, 0x65206973,
    0x20616C72, 0x65616479, 0x2046494C, 0x45204461, 0x74610A6F, 0x6E207468, 0x65204D65, 0x6D6F7279,
    0x20436172, 0x6420696E, 0x20534C4F, 0x542E0A4F, 0x4B20746F, 0x20736176, 0x65206F76, 0x65722074,
    0x68697320, 0x64617461, 0x3F000000, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x47455200,
    0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x46524100, 0x4F564552, 0x57524954, 0x455F5155,
    0x45525920, 0x53504100, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x49544100, 0x534C4F54,
    0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0xA82B782, 0xC582C946, 0x494C4583,  /* fzgx-allow: A1 retail data bytes */
    0x66815B83, 0x5E82AA82, 0xA082E882, 0xDC82B781, 0x420A8FE3, 0x5B82A482, 0xED5D8F91, 0x5B82AA5D,
    0x82AB82B5, 0x82C482E0, 0x82E682EB, 0x82B582A2, 0x82C582B7, 0x82A98148, 0x0, 0x54686520,
    0x46494C45, 0x20446174, 0x61206F76, 0x65727772, 0x6974650A, 0x77617320, 0x63616E63, 0x656C6564,
    0x2E000000, 0x4F564552, 0x57524954, 0x455F4341, 0x4E43454C, 0x20474552, 0x0, 0x4F564552,
    0x57524954, 0x455F4341, 0x4E43454C, 0x20465241, 0x0, 0x4F564552, 0x57524954, 0x455F4341,
    0x4E43454C, 0x20535041, 0x0, 0x4F564552, 0x57524954, 0x455F4341, 0x4E43454C, 0x20495441,
    0x0, 0x46494C45, 0x8366815B, 0x835E82CC, 0xA8FE35B, 0x82A482ED, 0x5D8F915B, 0x82AA5D82,
    0xAB82F092, 0x865B82BF, 0x82E35D8E, 0x7E5B82A4, 0x82B55D82, 0xB582DC82, 0xB582BD81, 0x42000000,
    0x46494C45, 0x20446174, 0x61207761, 0x73207361, 0x76656420, 0x746F0A74, 0x6865204D, 0x656D6F72,
    0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x0, 0x53415645, 0x5F454E44, 0x20474552,
    0x0, 0x53415645, 0x5F454E44, 0x20465241, 0x0, 0x53415645, 0x5F454E44, 0x20535041,
    0x0, 0x53415645, 0x5F454E44, 0x20495441, 0x0, 0x534C4F54, 0x82CC8381, 0x8382838A,
    0x815B834A, 0x815B8368, 0x82D60A46, 0x494C4583, 0x66815B83, 0x5E82CC83, 0x5A815B83, 0x7582AA8F,  /* fzgx-allow: A1 retail data bytes */
    0x495B82A8, 0x5D82ED82, 0xE882DC82, 0xB582BD81, 0x42000000, 0x46726565, 0x20626C6F, 0x636B7320,
    0x696E2053, 0x4C4F543A, 0x0, 0x52454D41, 0x494E5F42, 0x4C4F434B, 0x53204745, 0x52000000,
    0x52454D41, 0x494E5F42, 0x4C4F434B, 0x53204652, 0x41000000, 0x52454D41, 0x494E5F42, 0x4C4F434B,
    0x53205350, 0x41000000, 0x52454D41, 0x494E5F42, 0x4C4F434B, 0x53204954, 0x41000000, 0x534C4F54,
    0x82CC8BF3, 0x5B82A05D, 0x82AB8375, 0x838D8362, 0x834E8146, 0x0, 0x426C6F63, 0x6B733A00,
    0x424C4F43, 0x4B532047, 0x45520000, 0x424C4F43, 0x4B532046, 0x52410000, 0x424C4F43, 0x4B532053,
    0x50410000, 0x424C4F43, 0x4B532049, 0x54410000, 0x8375838D, 0x8362834E, 0x81460000, 0x4C6F6164,  /* fzgx-allow: A1 retail data bytes */
    0x696E6720, 0x46494C45, 0x20446174, 0x61206672, 0x6F6D0A74, 0x6865204D, 0x656D6F72, 0x79204361,
    0x72642077, 0x61732063, 0x616E6365, 0x6C6C6564, 0x2E200000, 0x4E4F4C4F, 0x41445F45, 0x58495420,
    0x47455200, 0x4E4F4C4F, 0x41445F45, 0x58495420, 0x46524100, 0x4E4F4C4F, 0x41445F45, 0x58495420,
    0x53504100, 0x4E4F4C4F, 0x41445F45, 0x58495420, 0x49544100, 0x46494C45, 0x8366815B, 0x835E82CC,
    0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xA982E782, 0xCC838D81, 0x5B836882, 0xF092865B,
    0x82BF82E3, 0x82A45D8E, 0x7E5B82B5, 0x5D82B582, 0xDC82B582, 0xBD814200, 0x54686520, 0x4D656D6F,
    0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x68617320, 0x6265656E, 0x20666F72, 0x6D617474,
    0x65642E00, 0x464F524D, 0x41545F45, 0x4E442047, 0x45520000, 0x464F524D, 0x41545F45, 0x4E442046,
    0x52410000, 0x464F524D, 0x41545F45, 0x4E442053, 0x50410000, 0x464F524D, 0x41545F45, 0x4E442049,
    0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83, 0x74834881,  /* fzgx-allow: A1 retail data bytes */
    0x5B837D83, 0x62836782, 0xAA8F495B, 0x82A85D82, 0xED82E882, 0xDC82B582, 0xBD814200, 0x54686520,
    0x46494C45, 0x20446174, 0x61206861, 0x73206265, 0x656E206C, 0x6F616465, 0x640A6672, 0x6F6D2074,
    0x6865204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x0, 0x4C4F4144,
    0x5F454E44, 0x20474552, 0x0, 0x4C4F4144, 0x5F454E44, 0x20465241, 0x0, 0x4C4F4144,
    0x5F454E44, 0x20535041, 0x0, 0x4C4F4144, 0x5F454E44, 0x20495441, 0x0, 0x534C4F54,
    0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82A982E7, 0x82CC0A46, 0x494C4583, 0x66815B83,  /* fzgx-allow: A1 retail data bytes */
    0x5E82CC83, 0x8D815B83, 0x6882AA8F, 0x495B82A8, 0x5D82ED82, 0xE882DC82, 0xB582BD81, 0x42000000,
    0x54686520, 0x462D5A45, 0x524F2047, 0x58204649, 0x4C452044, 0x61746120, 0x6F6E0A74, 0x6865204D,
    0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F540A69, 0x7320636F, 0x72727570, 0x74656420,
    0x616E6420, 0x6D757374, 0x20626520, 0x64656C65, 0x7465642E, 0x0, 0x44415441, 0x5F42524F,
    0x4B454E20, 0x47455200, 0x44415441, 0x5F42524F, 0x4B454E20, 0x46524100, 0x44415441, 0x5F42524F,
    0x4B454E20, 0x53504100, 0x44415441, 0x5F42524F, 0x4B454E20, 0x49544100, 0x46494C45, 0x8366815B,
    0x835E82AA, 0x82B182ED, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0xA837483, 0x40834383, 0x8B82F08F,
    0xC15B82B5, 0x82E582A4, 0x5D8B8E5B, 0x2082AB82, 0xE55D82B5, 0x82DC82B7, 0x81420000, 0x54686520,  /* fzgx-allow: A1 retail data bytes */
    0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F5420, 0x77617320, 0x72656D6F, 0x7665642E,
    0xA4D656D, 0x6F727920, 0x43617264, 0x20616363, 0x65737320, 0x77617320, 0x73746F70, 0x7065642E,
    0x20000000, 0x44455441, 0x43482047, 0x45520000, 0x44455441, 0x43482046, 0x52410000, 0x44455441,
    0x43482053, 0x50410000, 0x44455441, 0x43482049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A,
    0x815B834A, 0x815B8368, 0x82AA94B2, 0x5B82CA5D, 0x82A982EA, 0x82DC82B5, 0x82BD8142, 0xA8DEC5B,  /* fzgx-allow: A1 retail data bytes */
    0x82B382AC, 0x5D8BC65B, 0x82E582A4, 0x5D82F092, 0x865B82BF, 0x82E35D8E, 0x7E5B82A4, 0x82B55D82,
    0xB582DC82, 0xB7814200, 0x54686572, 0x65206973, 0x206E6F20, 0x46494C45, 0x20446174, 0x61206F6E,
    0xA746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20696E20, 0x534C4F54, 0x2E200000, 0x4E4F4649,
    0x4C452047, 0x45520000, 0x4E4F4649, 0x4C452046, 0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000,
    0x4E4F4649, 0x4C452049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82C982CD, 0xA46494C, 0x45836681, 0x5B835E82, 0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000,
    0x54686572, 0x65206973, 0x206E6F20, 0x5265706C, 0x61792044, 0x61746120, 0x6F6E0A74, 0x6865204D,
    0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x0, 0x4E4F4649, 0x4C452047,
    0x45520000, 0x4E4F4649, 0x4C452046, 0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000, 0x4E4F4649,
    0x4C452049, 0x54410000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD,  /* fzgx-allow: A1 retail data bytes */
    0xA46494C, 0x45836681, 0x5B835E82, 0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000, 0x54686572,
    0x65206973, 0x206E6F20, 0x47686F73, 0x74204461, 0x7461206F, 0x6E0A7468, 0x65204D65, 0x6D6F7279,
    0x20436172, 0x6420696E, 0x20534C4F, 0x542E2000, 0x4E4F4649, 0x4C452047, 0x45520000, 0x4E4F4649,
    0x4C452046, 0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000, 0x4E4F4649, 0x4C452049, 0x54410000,
    0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0xA46494C, 0x45836681,  /* fzgx-allow: A1 retail data bytes */
    0x5B835E82, 0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000, 0x54686572, 0x65206973, 0x206E6F20,
    0x456D626C, 0x656D2044, 0x61746120, 0x6F6E0A74, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069,
    0x6E20534C, 0x4F542E20, 0x0, 0x4E4F4649, 0x4C452047, 0x45520000, 0x4E4F4649, 0x4C452046,
    0x52410000, 0x4E4F4649, 0x4C452053, 0x50410000, 0x4E4F4649, 0x4C452049, 0x54410000, 0x534C4F54,
    0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0xA46494C, 0x45836681, 0x5B835E82,  /* fzgx-allow: A1 retail data bytes */
    0xAA82A082, 0xE882DC82, 0xB982F181, 0x42000000, 0x556E6162, 0x6C652074, 0x6F206765, 0x74207468,
    0x65206461, 0x7461206C, 0x6973740A, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642069,
    0x6E20534C, 0x4F542E20, 0x0, 0x4E4F4C49, 0x53545F45, 0x58495420, 0x47455200, 0x4E4F4C49,
    0x53545F45, 0x58495420, 0x46524100, 0x4E4F4C49, 0x53545F45, 0x58495420, 0x53504100, 0x4E4F4C49,
    0x53545F45, 0x58495420, 0x49544100, 0x534C4F54, 0x82CC8366, 0x815B835E, 0x838A8358, 0x836782AA,  /* fzgx-allow: A1 retail data bytes */
    0xA82C682, 0xEA82DC82, 0xB982F182, 0xC582B582, 0xBD814200, 0x54686572, 0x65206973, 0x206E6F20,
    0x64617461, 0x206F6E0A, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F542E,
    0x20000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204745, 0x52000000, 0x4C495354, 0x5F4E4F5F,
    0x45584953, 0x54204652, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54205350, 0x41000000,
    0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A,
    0x815B834A, 0x815B8368, 0x82C982CD, 0xA836681, 0x5B835E82, 0xAA3182C2, 0x82E082A0, 0x82E882DC,  /* fzgx-allow: A1 retail data bytes */
    0x82B982F1, 0x82C582B5, 0x82BD8142, 0x0, 0x54686520, 0x64617461, 0x206C6973, 0x74206F6E,
    0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0xA696E20, 0x534C4F54, 0x20686173, 0x20626565,
    0x6E206C6F, 0x61646564, 0x2E000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x0, 0x4C495354,
    0x5F454E44, 0x20465241, 0x0, 0x4C495354, 0x5F454E44, 0x20535041, 0x0, 0x4C495354,
    0x5F454E44, 0x20495441, 0x0, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82CC0A83, 0x66815B83, 0x5E838A83, 0x58836782, 0xF093C75B, 0x82E65D82, 0xDD82B182, 0xDD82DC82,
    0xB582BD81, 0x42000000, 0x446F6E65, 0x20636865, 0x636B696E, 0x67207468, 0x65204D65, 0x6D6F7279,
    0x20436172, 0x6420696E, 0x20534C4F, 0x542E0000, 0x43484543, 0x4B5F454E, 0x44204745, 0x52000000,
    0x43484543, 0x4B5F454E, 0x44204652, 0x41000000, 0x43484543, 0x4B5F454E, 0x44205350, 0x41000000,
    0x43484543, 0x4B5F454E, 0x44204954, 0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A,  /* fzgx-allow: A1 retail data bytes */
    0x815B8368, 0x82CC0A83, 0x60834683, 0x62834E82, 0xAA5B82B5, 0x5D8F495B, 0x82E382A4, 0x5D97B95B,  /* fzgx-allow: A1 retail data bytes */
    0x82E882E5, 0x5D82B55B, 0x82A45D82, 0xDC82B582, 0xBD814200, 0x46494C45, 0x20446174, 0x61206465,
    0x6C657469, 0x6F6E206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x640A696E, 0x20534C4F,
    0x54207761, 0x73206361, 0x6E63656C, 0x6C65642E, 0x0, 0x4E4F4445, 0x4C5F4558, 0x49542047,
    0x45520000, 0x4E4F4445, 0x4C5F4558, 0x49542046, 0x52410000, 0x4E4F4445, 0x4C5F4558, 0x49542053,
    0x50410000, 0x4E4F4445, 0x4C5F4558, 0x49542049, 0x54410000, 0x534C4F54, 0x82CC4649, 0x4C458366,
    0x815B835E, 0x82CC8DED, 0x5B82B382, 0xAD5D8F9C, 0x5B82B682, 0xE55D82F0, 0x92865B82, 0xBF82E382,  /* fzgx-allow: A1 retail data bytes */
    0xA45D8E7E, 0x5B82B55D, 0x82B582DC, 0x82B582BD, 0x81420000, 0x31204649, 0x4C452044, 0x61746120,  /* fzgx-allow: A1 retail data bytes */
    0x77617320, 0x65726173, 0x65642066, 0x726F6D20, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420,
    0x696E2053, 0x4C4F542E, 0x0, 0x44454C45, 0x54455F45, 0x4E442047, 0x45520000, 0x44454C45,
    0x54455F45, 0x4E442046, 0x52410000, 0x44454C45, 0x54455F45, 0x4E442053, 0x50410000, 0x44454C45,
    0x54455F45, 0x4E442049, 0x54410000, 0x534C4F54, 0x82CC4649, 0x4C458366, 0x815B835E, 0x82F08250,  /* fzgx-allow: A1 retail data bytes */
    0x82C28FC1, 0x5B82AF5D, 0x82B582DC, 0x82B582BD, 0x81420000, 0x4E4F5720, 0x464F524D, 0x41545449,  /* fzgx-allow: A1 retail data bytes */
    0x4E470000, 0x464F524D, 0x41545F4E, 0x4F572047, 0x45520000, 0x464F524D, 0x41545F4E, 0x4F572046,
    0x52410000, 0x464F524D, 0x41545F4E, 0x4F572053, 0x50410000, 0x464F524D, 0x41545F4E, 0x4F572049,
    0x54410000, 0x4E4F5720, 0x464F524D, 0x41545449, 0x4E470000, 0x4E4F5720, 0x53415649, 0x4E470000,
    0x53415645, 0x5F4E4F57, 0x20474552, 0x0, 0x53415645, 0x5F4E4F57, 0x20465241, 0x0,
    0x53415645, 0x5F4E4F57, 0x20535041, 0x0, 0x53415645, 0x5F4E4F57, 0x20495441, 0x0,
    0x4E4F5720, 0x53415649, 0x4E470000, 0x4E4F5720, 0x4D414B49, 0x4E47204C, 0x49535400, 0x4C495354,
    0x5F4E4F57, 0x20474552, 0x0, 0x4C495354, 0x5F4E4F57, 0x20465241, 0x0, 0x4C495354,
    0x5F4E4F57, 0x20535041, 0x0, 0x4C495354, 0x5F4E4F57, 0x20495441, 0x0, 0x4E4F5720,
    0x4D414B49, 0x4E47204C, 0x49535400, 0x4E4F5720, 0x43484543, 0x4B494E47, 0x0, 0x4C495354,
    0x5F4E4F57, 0x20474552, 0x0, 0x4C495354, 0x5F4E4F57, 0x20465241, 0x0, 0x4C495354,
    0x5F4E4F57, 0x20535041, 0x0, 0x4C495354, 0x5F4E4F57, 0x20495441, 0x0, 0x4E4F5720,
    0x43484543, 0x4B494E47, 0x0, 0x41636365, 0x7373696E, 0x67207468, 0x65204D65, 0x6D6F7279,
    0x20436172, 0x6420696E, 0x20534C4F, 0x542E0A44, 0x6F206E6F, 0x7420746F, 0x75636820, 0x74686520,
    0x4D656D6F, 0x72792043, 0x61726420, 0x6F722050, 0x4F574552, 0x20427574, 0x746F6E2E, 0x0,
    0x41434345, 0x53532047, 0x45520000, 0x41434345, 0x53532046, 0x52410000, 0x41434345, 0x53532053,
    0x50410000, 0x41434345, 0x53532049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9,
    0x8341834E, 0x835A8358, 0x92865B82, 0xBF82E382, 0xA45D82C5, 0x82B78142, 0xA838183, 0x82838A81,
    0x5B834A81, 0x5B836882, 0xE293645B, 0x82C582F1, 0x5D8CB95B, 0x82B082F1, 0x5D82C990, 0x475B82B3,
    0x82ED5D82, 0xE782C882, 0xA282C582, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x41636365, 0x7373696E,
    0x67207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E0A44, 0x6F206E6F,
    0x7420746F, 0x75636820, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x6F722050, 0x4F574552,
    0x20427574, 0x746F6E2E, 0x0, 0x41434345, 0x53532047, 0x45520000, 0x41434345, 0x53532046,
    0x52410000, 0x41434345, 0x53532053, 0x50410000, 0x41434345, 0x53532049, 0x54410000, 0x83818382,
    0x838A815B, 0x834A815B, 0x836882C9, 0x8341834E, 0x835A8358, 0x92865B82, 0xBF82E382, 0xA45D82C5,
    0x82B78142, 0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xE293645B, 0x82C582F1, 0x5D8CB95B,
    0x82B082F1, 0x5D82C990, 0x475B82B3, 0x82ED5D82, 0xE782C882, 0xA282C582, 0xAD82BE82, 0xB382A281,
    0x420A0000, 0x4F4B2074, 0x6F207361, 0x76652046, 0x494C4520, 0x746F2074, 0x6865204D, 0x656D6F72,
    0x79204361, 0x72642069, 0x6E20534C, 0x4F543F00, 0x53415645, 0x5F515545, 0x52592047, 0x45520000,
    0x53415645, 0x5F515545, 0x52592046, 0x52410000, 0x53415645, 0x5F515545, 0x52592053, 0x50410000,
    0x53415645, 0x5F515545, 0x52592049, 0x54410000, 0x534C4F54, 0x82C94649, 0x4C4582F0, 0x835A815B,
    0x837582B5, 0x82C482E0, 0xA82E682, 0xEB82B582, 0xA282C582, 0xB782A981, 0x48000000, 0x49662079,
    0x6F752073, 0x74617274, 0x206E6F77, 0x2C0A796F, 0x75207769, 0x6C6C206E, 0x6F742062, 0x65206162,
    0x6C652074, 0x6F207361, 0x76652E00, 0x43414E4E, 0x4F545F53, 0x41564520, 0x47455200, 0x43414E4E,
    0x4F545F53, 0x41564520, 0x46524100, 0x43414E4E, 0x4F545F53, 0x41564520, 0x53504100, 0x43414E4E,
    0x4F545F53, 0x41564520, 0x49544100, 0x82B182CC, 0x82DC82DC, 0x8E6E5B82, 0xCD82B65D, 0x82DF82BD,
    0x8FEA5B82, 0xCE5D8D87, 0x5B82A082, 0xA25D0A83, 0x5A815B83, 0x7582C582, 0xAB82DC82, 0xB982F100,
    0x54686572, 0x65206172, 0x65206E6F, 0x204D656D, 0x6F727920, 0x43617264, 0x7320696E, 0x73657274,
    0x65642070, 0x726F7065, 0x726C792E, 0xA506C65, 0x61736520, 0x63686563, 0x6B20636F, 0x6E6E6563,
    0x74696F6E, 0x73206F72, 0x20696E73, 0x65727420, 0x61204D65, 0x6D6F7279, 0x20436172, 0x642E0A49,
    0x6620796F, 0x75207374, 0x61727420, 0x6E6F772C, 0x20796F75, 0x2077696C, 0x6C206E6F, 0x74206265,
    0x2061626C, 0x6520746F, 0x20736176, 0x65207468, 0x65206761, 0x6D652E00, 0x43414E4E, 0x4F545F53,
    0x4156455F, 0x4E4F4341, 0x52442047, 0x45520000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341,
    0x52442046, 0x52410000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442053, 0x50410000,
    0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442049, 0x54410000, 0x83818382, 0x838A815B,
    0x834A815B, 0x836882AA, 0x8CA95B82, 0xDD5D82C2, 0x82A982E8, 0x82DC82B9, 0x82F18142, 0xA90DA5B,
    0x82B982C2, 0x5D91B15B, 0x82BC82AD, 0x5D82F08A, 0x6D5B82A9, 0x82AD5D94, 0x465B82C9, 0x82F15D82,
    0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A82B1, 0x82CC82DC, 0x82DC8E6E, 0x5B82CD82, 0xB65D82DF,
    0x82BD8FEA, 0x5B82CE5D, 0x8D875B82, 0xA082A25D, 0xA835A81, 0x5B837582, 0xC582AB82, 0xDC82B982,
    0xF1000000, 0x54686520, 0x64657669, 0x63652069, 0x6E20534C, 0x4F542069, 0x73206E6F, 0x74207375,
    0x70706F72, 0x7465642E, 0xA506C65, 0x61736520, 0x696E7365, 0x72742061, 0x204D656D, 0x6F727920,
    0x43617264, 0x2E000000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442047, 0x45520000,
    0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341, 0x52442046, 0x52410000, 0x43414E4E, 0x4F545F53,
    0x4156455F, 0x4E4F4341, 0x52442053, 0x50410000, 0x43414E4E, 0x4F545F53, 0x4156455F, 0x4E4F4341,
    0x52442049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x836888C8, 0x8A4F82CC, 0x82E082CC,
    0x82AA8CA9, 0x5B82DD5D, 0x82C282A9, 0x82E882DC, 0x82B582BD, 0x81420A83, 0x81838283, 0x8A815B83,  /* fzgx-allow: A1 retail data bytes */
    0x4A815B83, 0x6882F082, 0xB382B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x45697468, 0x65722047,
    0x616D6520, 0x44617461, 0x20776173, 0x206E6F74, 0x206C6F61, 0x6465640A, 0x6F722074, 0x6865206F,
    0x72696769, 0x6E616C20, 0x4D656D6F, 0x72792043, 0x6172642C, 0xA66726F, 0x6D207768, 0x69636820,
    0x74686520, 0x47616D65, 0x20646174, 0x61207761, 0x73206C6F, 0x61646564, 0x2C0A6861, 0x73206265,
    0x656E2072, 0x656D6F76, 0x65642E00, 0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x8351815B,
    0x83808366, 0x815B835E, 0x82AA838D, 0x815B8368, 0x82B382EA, 0x82C482A2, 0x82C882A2, 0x82A90A83,  /* fzgx-allow: A1 retail data bytes */
    0x51815B83, 0x80836681, 0x5B835E82, 0xF0838D81, 0x5B836882, 0xB582BD83, 0x81838283, 0x8A815B83,  /* fzgx-allow: A1 retail data bytes */
    0x4A815B83, 0x680A82C5, 0x82CD82A0, 0x82E882DC, 0x82B982F1, 0x81422883, 0x51815B83, 0x80836681,  /* fzgx-allow: A1 retail data bytes */
    0x5B835E82, 0xCC835A81, 0x5B837581, 0x410A838D, 0x815B8368, 0x82CD8141, 0x83498376, 0x83568387,  /* fzgx-allow: A1 retail data bytes */
    0x839382CC, 0x83818382, 0x838A815B, 0x834A815B, 0x83680A83, 0x81836A83, 0x85815B82, 0xA982E789,
    0xC25B82A9, 0x5D945C5B, 0x82CC82A4, 0x5D82C582, 0xB7814229, 0x0, 0x45697468, 0x65722047,
    0x616D6520, 0x44617461, 0x20776173, 0x206E6F74, 0x206C6F61, 0x6465640A, 0x6F722074, 0x6865206F,
    0x72696769, 0x6E616C20, 0x4D656D6F, 0x72792043, 0x6172642C, 0xA66726F, 0x6D207768, 0x69636820,
    0x74686520, 0x47616D65, 0x20646174, 0x61207761, 0x73206C6F, 0x61646564, 0x2C0A2068, 0x61732062,
    0x65656E20, 0x72656D6F, 0x7665642E, 0x0, 0x47455200, 0x46524100, 0x53504100, 0x49544100,
    0x8351815B, 0x83808366, 0x815B835E, 0x82AA838D, 0x815B8368, 0x82B382EA, 0x82C482A2, 0x82C882A2,  /* fzgx-allow: A1 retail data bytes */
    0x82A90A83, 0x51815B83, 0x80836681, 0x5B835E82, 0xF0838D81, 0x5B836882, 0xB582BD83, 0x81838283,  /* fzgx-allow: A1 retail data bytes */
    0x8A815B83, 0x4A815B83, 0x680A82C5, 0x82CD82A0, 0x82E882DC, 0x82B982F1, 0x81420000, 0x44617461,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x46696C65, 0x20474552, 0x0, 0x46696C65, 0x20465241, 0x0, 0x46696C65,
    0x20535041, 0x0, 0x46696C65, 0x20495441, 0x0, 0x8366815B, 0x835E0000, 0x47616D65,
    0x0, 0x53797374, 0x656D2047, 0x45520000, 0x53797374, 0x656D2046, 0x52410000, 0x53797374,
    0x656D2053, 0x50410000, 0x53797374, 0x656D2049, 0x54410000, 0x8351815B, 0x83800000, 0x44656275,
    0x67000000, 0x44656275, 0x67204745, 0x52000000, 0x44656275, 0x67204652, 0x41000000, 0x44656275,
    0x67205350, 0x41000000, 0x44656275, 0x67204954, 0x41000000, 0x8366836F, 0x8362834F, 0x0,
    0x5265706C, 0x61790000, 0x5265706C, 0x61792047, 0x45520000, 0x5265706C, 0x61792046, 0x52410000,
    0x5265706C, 0x61792053, 0x50410000, 0x5265706C, 0x61792049, 0x54410000, 0x838A8376, 0x838C8343,
    0x0, 0x456D626C, 0x656D0000, 0x456D626C, 0x656D2047, 0x45520000, 0x456D626C, 0x656D2046,
    0x52410000, 0x456D626C, 0x656D2053, 0x50410000, 0x456D626C, 0x656D2049, 0x54410000, 0x83478393,
    0x8375838C, 0x83800000, 0x47686F73, 0x74000000, 0x47686F73, 0x74204745, 0x52000000, 0x47686F73,
    0x74204652, 0x41000000, 0x47686F73, 0x74205350, 0x41000000, 0x47686F73, 0x74204954, 0x41000000,
    0x8353815B, 0x83588367, 0x0, 0x47617261, 0x67650000, 0x43757374, 0x6F6D2047, 0x45520000,
    0x43757374, 0x6F6D2046, 0x52410000, 0x43757374, 0x6F6D2053, 0x50410000, 0x43757374, 0x6F6D2049,
    0x54410000, 0x834B838C, 0x815B8357, 0x0, 0x47616D65, 0x0, 0x47616D65, 0x20474552,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x47616D65, 0x20465241, 0x0, 0x47616D65, 0x20535041, 0x0, 0x47616D65,
    0x20495441, 0x0, 0x8351815B, 0x83800000, 0x54686572, 0x65206973, 0x206E6F74, 0x20656E6F,
    0x75676820, 0x66726565, 0x20737061, 0x6365206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172,
    0x640A696E, 0x20257320, 0x746F2073, 0x61766520, 0x616C6C20, 0x74797065, 0x73206F66, 0x206E6577,
    0x2066696C, 0x65732E0A, 0x45786973, 0x74696E67, 0x20462D5A, 0x45524F20, 0x47582066, 0x696C6573,
    0x206D6179, 0x20626520, 0x65726173, 0x6564206F, 0x72206F76, 0x65727772, 0x69747465, 0x6E2E0A28,
    0x546F206D, 0x616E6167, 0x65206669, 0x6C657320, 0x6F6E2074, 0x6865204D, 0x656D6F72, 0x79204361,
    0x72642C20, 0x706C6561, 0x73652067, 0x6F20746F, 0xA746865, 0x204D656D, 0x6F727920, 0x43617264,
    0x206D616E, 0x6167656D, 0x656E7420, 0x73637265, 0x656E2E29, 0x20496E20, 0x6F726465, 0x7220746F,
    0x20736176, 0x650A6120, 0x6E657720, 0x66696C65, 0x2C207468, 0x6520666F, 0x6C6C6F77, 0x696E6720,
    0x6E756D62, 0x6572206F, 0x66206672, 0x65652066, 0x696C6573, 0xA616E64, 0x20626C6F, 0x636B7320,
    0x6D757374, 0x20626520, 0x61766169, 0x6C61626C, 0x653A0000, 0x47455200, 0x46524100, 0x53504100,
    0x49544100, 0x82A282AD, 0x82C282A9, 0x82CC8366, 0x815B835E, 0x82CD835A, 0x815B8375, 0x82C582AB,  /* fzgx-allow: A1 retail data bytes */
    0x82DC82B9, 0x82F18142, 0xA257382, 0xCC838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xC98BF35B,
    0x82A05D82, 0xAB976597, 0xCA82AA82, 0xC882A282, 0xA981410A, 0x83748340, 0x8343838B, 0x90945B82,
    0xB782A45D, 0x82CC90A7, 0x5B82B982, 0xA25D8CC0, 0x5B82B082, 0xF15D82F0, 0x897A5B82, 0xB15D82A6,
    0x82C482B5, 0x82DC82A2, 0x82DC82B7, 0x81420A83, 0x5A815B83, 0x7582B782, 0xE982C982, 0xCD8FAD5B,  /* fzgx-allow: A1 retail data bytes */
    0x82B782AD, 0x5D82C882, 0xAD82C682, 0xE088C85B, 0x82A25D89, 0xBA5B82A9, 0x5D82CC8B, 0xF35B82A0,
    0x5D82AB97, 0x655B82E6, 0x82A4205D, 0x97CA5B82, 0xE882E582, 0xA45D82AA, 0x954B5B82, 0xD082C25D,
    0x97765B82, 0xE682A45D, 0x82C582B7, 0x81420A28, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC,  /* fzgx-allow: A1 retail data bytes */
    0x93E05B82, 0xC882A25D, 0x97655B82, 0xE682A45D, 0x82F090AE, 0x5B82B982, 0xA25D979D, 0x5B82E85D,
    0x82B782E9, 0x82C982CD, 0x81410A96, 0x7B5B82D9, 0x82F15D91, 0xCC5B82BD, 0x82A25D82, 0xCC838183,  /* fzgx-allow: A1 retail data bytes */
    0x82838A81, 0x5B834A81, 0x5B836889, 0xE65B82AA, 0x5D96CA5B, 0x82DF82F1, 0x5D82C58D, 0x735B82A8,
    0x82B15D82, 0xC882C182, 0xC482AD82, 0xBE82B382, 0xA2290A00, 0x2F626366, 0x66613061, 0x302F312F,
    0x62636666, 0x66666666, 0x2F204669, 0x6C652061, 0x6E64202F, 0x62636666, 0x61306130, 0x2F202020,
    0x20202020, 0x202F6263, 0x66666666, 0x66662F20, 0x426C6F63, 0x6B730000, 0x47455200, 0x46524100,
    0x53504100, 0x49544100, 0x83748340, 0x8343838B, 0x2F626366, 0x66613061, 0x302F312F, 0x62636666,
    0x66666666, 0x2F82C220, 0x82C62F62, 0x63666661, 0x3061302F, 0x2534642F, 0x62636666, 0x66666666,
    0x2F837583, 0x8D836283, 0x4E000000, 0x2F626366, 0x66613061, 0x302F312F, 0x62636666, 0x66666666,
    0x2F204669, 0x6C652061, 0x6E64202F, 0x62636666, 0x61306130, 0x2F825281, 0x60253264, 0x2F626366,
    0x66666666, 0x662F2042, 0x6C6F636B, 0x73000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100,
    0x83748340, 0x8343838B, 0x2F626366, 0x66613061, 0x302F312F, 0x62636666, 0x66666666, 0x2F82C220,
    0x82C62F62, 0x63666661, 0x3061302F, 0x82528160, 0x2532642F, 0x62636666, 0x66666666, 0x2F837583,
    0x8D836283, 0x4E000000, 0x4E6F204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E0A,
    0x506C6561, 0x73652069, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x6172642E, 0x0,
    0x47455200, 0x46524100, 0x53504100, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA,
    0x8CA95B82, 0xDD5D82C2, 0x82A982E8, 0x82DC82B9, 0x82F18142, 0xA90DA5B, 0x82B982C2, 0x5D91B15B,
    0x82BC82AD, 0x5D82F08A, 0x6D5B82A9, 0x82AD5D94, 0x465B82C9, 0x82F15D82, 0xB582C482, 0xAD82BE82,
    0xB382A281, 0x42000000, 0x53415645, 0x0, 0x47455200, 0x46524100, 0x53504100, 0x49544100,
    0x835A815B, 0x83750000, 0x4C4F4144, 0x0, 0x47455200, 0x46524100, 0x53504100, 0x49544100,
    0x838D815B, 0x83680000, 0x434F5059, 0x0, 0x47455200, 0x46524100, 0x53504100, 0x49544100,
    0x83528373, 0x815B0000, 0x45524153, 0x45000000, 0x47455200, 0x46524100, 0x53504100, 0x49544100,  /* fzgx-allow: A1 retail data bytes */
    0x82AF2082, 0xB7000000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x6E6F7420,
    0x62652075, 0x7365642E, 0xA506C65, 0x61736520, 0x72656D6F, 0x76652069, 0x742E2000, 0x47455200,
    0x46524100, 0x53504100, 0x49544100, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD,
    0x8E675B82, 0xB55D9770, 0x5B82E682, 0xA45D82C5, 0x82AB82DC, 0x82B982F1, 0x81420A83, 0x81838283,  /* fzgx-allow: A1 retail data bytes */
    0x8A815B83, 0x4A815B83, 0x6882F094, 0xB25B82CA, 0x5D82A282, 0xC482AD82, 0xBE82B382, 0xA2814200,
    0x41636365, 0x7373696E, 0x67207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F,
    0x7420412E, 0x20446F20, 0x6E6F7420, 0x746F7563, 0x68207468, 0x65204D65, 0x6D6F7279, 0x20436172,
    0x64206F72, 0x20504F57, 0x45522042, 0x7574746F, 0x6E2E0000, 0x47455200, 0x46524100, 0x53504100,
    0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8341834E, 0x835A8358, 0x928682C5,
    0x82B78142, 0x83818382, 0x838A815B, 0x834A815B, 0x836882E2, 0x93648CB9, 0x82C99047, 0x82E782C8,
    0x82A282C5, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53617669, 0x6E670000, 0x47455200, 0x46524100,  /* fzgx-allow: A1 retail data bytes */
    0x53504100, 0x49544100, 0x835A815B, 0x83759286, 0x0, 0x536F6D65, 0x20462D5A, 0x45524F20,
    0x47582066, 0x696C6573, 0x206F6E0A, 0x74686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053,
    0x4C4F5420, 0x61726520, 0x636F7272, 0x75707465, 0x642E0A00, 0x4C495354, 0x5F4E4F5F, 0x45584953,
    0x54204745, 0x52000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204652, 0x41000000, 0x4C495354,
    0x5F4E4F5F, 0x45584953, 0x54205350, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204954,
    0x41000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0xA836681,  /* fzgx-allow: A1 retail data bytes */
    0x5B835E82, 0xAA3182C2, 0x82E082A0, 0x82E882DC, 0x82B982F1, 0x82C582B5, 0x82BD8142, 0xA2882B1,
    0x82ED82EA, 0x82BD8366, 0x815B835E, 0x82AA91B6, 0x5B82BB82, 0xF15D8DDD, 0x5B82B482, 0xA25D82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82C482A2, 0x82DC82B7, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882CC93, 0xE05B82C8,  /* fzgx-allow: A1 retail data bytes */
    0x82A25D97, 0x655B82E6, 0x82A45D82, 0xF090AE5B, 0x82B982A2, 0x5D979D5B, 0x82E85D82, 0xB782E982,
    0xC982CD81, 0x410A967B, 0x5B82D982, 0xF15D91CC, 0x5B82BD82, 0xA25D82CC, 0x83818382, 0x838A815B,
    0x834A815B, 0x836889E6, 0x96CA82C5, 0x82A882B1, 0x82C882C1, 0x82C482AD, 0x82BE82B3, 0x82A22900,
    0x54686520, 0x64617461, 0x206C6973, 0x74206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264,
    0x20696E20, 0x534C4F54, 0xA686173, 0x20626565, 0x6E207265, 0x61642E20, 0x28536F6D, 0x6520462D,
    0x5A45524F, 0x20475820, 0x66696C65, 0x73206F6E, 0xA746865, 0x204D656D, 0x6F727920, 0x43617264,
    0x20696E20, 0x534C4F54, 0x20617265, 0x20636F72, 0x72757074, 0x65642E29, 0x0, 0x4C495354,
    0x5F454E44, 0x20474552, 0x0, 0x4C495354, 0x5F454E44, 0x20465241, 0x0, 0x4C495354,
    0x5F454E44, 0x20535041, 0x0, 0x4C495354, 0x5F454E44, 0x20495441, 0x0, 0x534C4F54,
    0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC0A83, 0x66815B83, 0x5E838A83, 0x58836782,  /* fzgx-allow: A1 retail data bytes */
    0xF093C75B, 0x82E65D82, 0xDD82B182, 0xDD82DC82, 0xB582BD81, 0x420A2882, 0xB182ED82, 0xEA82BD83,
    0x66815B83, 0x5E82AA91, 0xB65B82BB, 0x82F15D8D, 0xDD5B82B4, 0x82A25D82, 0xB582C482, 0xA282DC82,
    0xB781420A, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x93E05B82, 0xC882A25D, 0x97655B82,
    0xE682A45D, 0x82F090AE, 0x5B82B982, 0xA25D979D, 0x5B82E85D, 0x82B782E9, 0x82C982CD, 0x81410A96,  /* fzgx-allow: A1 retail data bytes */
    0x7B5B82D9, 0x82F15D91, 0xCC5B82BD, 0x82A25D82, 0xCC838183, 0x82838A81, 0x5B834A81, 0x5B836889,
    0xE696CA82, 0xC582A882, 0xB182C882, 0xC182C482, 0xAD82BE82, 0xB382A229, 0x0, 0x536F6D65,
    0x20462D5A, 0x45524F20, 0x47582066, 0x696C6573, 0x206F6E0A, 0x74686520, 0x4D656D6F, 0x72792043,
    0x61726420, 0x696E2053, 0x4C4F5420, 0x61726520, 0x636F7272, 0x75707465, 0x642E0A50, 0x6C656173,
    0x6520676F, 0x20746F20, 0x4F707469, 0x6F6E7320, 0x746F206D, 0x616E6167, 0x65207468, 0x65204D65,
    0x6D6F7279, 0x20436172, 0x642E0000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204745, 0x52000000,
    0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204652, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953,
    0x54205350, 0x41000000, 0x4C495354, 0x5F4E4F5F, 0x45584953, 0x54204954, 0x41000000, 0x0,
    0x54686520, 0x64617461, 0x206C6973, 0x74206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264,
    0x20696E20, 0x534C4F54, 0xA686173, 0x20626565, 0x6E207265, 0x61642E20, 0x28536F6D, 0x6520462D,
    0x5A45524F, 0x20475820, 0x66696C65, 0x73206F6E, 0xA746865, 0x204D656D, 0x6F727920, 0x43617264,
    0x20696E20, 0x534C4F54, 0x20617265, 0x20636F72, 0x72757074, 0x65642E0A, 0x506C6561, 0x73652067,
    0x6F20746F, 0x204F7074, 0x696F6E73, 0x206D616E, 0x61676520, 0x74686520, 0x4D656D6F, 0x72792043,
    0x6172642E, 0x29000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x0, 0x4C495354, 0x5F454E44,
    0x20465241, 0x0, 0x4C495354, 0x5F454E44, 0x20535041, 0x0, 0x4C495354, 0x5F454E44,
    0x20495441, 0x0, 0x0, 0x4E6F204D, 0x656D6F72, 0x79204361, 0x72642066, 0x6F756E64,
    0x20696E20, 0x536C6F74, 0x20412E20, 0x506C6561, 0x73652072, 0x652D696E, 0x73657274, 0x20746865,
    0xA6F7269, 0x67696E61, 0x6C204D65, 0x6D6F7279, 0x20436172, 0x64206672, 0x6F6D2077, 0x68696368,
    0x20746865, 0x2047616D, 0x65206461, 0x74612077, 0x6173206C, 0x6F616465, 0x642E0A83, 0x9F204275,
    0x74746F6E, 0x20816320, 0x52657472, 0x790A83A0, 0x20427574, 0x746F6E20, 0x81632043, 0x6F6E7469,  /* fzgx-allow: A1 retail data bytes */
    0x6E756520, 0x77697468, 0x6F757420, 0x73617669, 0x6E670000, 0x4C495354, 0x5F454E44, 0x20474552,
    0x0, 0x4C495354, 0x5F454E44, 0x20465241, 0x0, 0x4C495354, 0x5F454E44, 0x20535041,
    0x0, 0x4C495354, 0x5F454E44, 0x20495441, 0x0, 0x8358838D, 0x83628367, 0x826082CC,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x94B25B82, 0xCA5D82A9, 0x82EA82C4, 0x82A282DC,
    0x82B78142, 0xA835181, 0x5B838083, 0x66815B83, 0x5E82F083, 0x8D815B83, 0x6882B582, 0xBD838183,
    0x82838A81, 0x5B834A81, 0x5B836882, 0xF00A8358, 0x838D8362, 0x83678260, 0x82C982B3, 0x82B582C4,
    0x839F837B, 0x835E8393, 0x82F0899F, 0x5B82A85D, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A83,  /* fzgx-allow: A1 retail data bytes */
    0x4C838383, 0x93835A83, 0x8B82B782, 0xE982C982, 0xCD83A082, 0xF0899F5B, 0x82A85D82, 0xB582C482,
    0xAD82BE82, 0xB382A281, 0x42000000, 0x41726520, 0x796F7520, 0x73757265, 0x20796F75, 0xA77616E,
    0x7420746F, 0x2064656C, 0x65746520, 0x74686973, 0x3F000000, 0x4C495354, 0x5F454E44, 0x20474552,
    0x0, 0x4C495354, 0x5F454E44, 0x20465241, 0x0, 0x4C495354, 0x5F454E44, 0x20535041,
    0x0, 0x4C495354, 0x5F454E44, 0x20495441, 0x0, 0x967B5B82, 0xD982F15D, 0x93965B82,
    0xC682A45D, 0x82C98FC1, 0x5B82AF5D, 0x82B582C4, 0x82E00A82, 0xE682EB82, 0xB582A282, 0xC582B782,
    0xA93F0000, 0x54686520, 0x64657669, 0x63652069, 0x6E20534C, 0x4F542069, 0x73206E6F, 0x74206120,
    0x4D656D6F, 0x72792043, 0x6172642E, 0xA506C65, 0x61736520, 0x696E7365, 0x72742061, 0x204D656D,
    0x6F727920, 0x43617264, 0x2E000000, 0x4C495354, 0x5F454E44, 0x20474552, 0x0, 0x4C495354,
    0x5F454E44, 0x20465241, 0x0, 0x4C495354, 0x5F454E44, 0x20535041, 0x0, 0x4C495354,
    0x5F454E44, 0x20495441, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836888C8, 0x8A4F82CC,
    0x82E082CC, 0x82AA8CA9, 0x5B82DD5D, 0x82C282A9, 0x82E882DC, 0x82B582BD, 0x81420A82, 0xB182CC82,  /* fzgx-allow: A1 retail data bytes */
    0xDC82DC82, 0xC582CD8D, 0xEC5B82B3, 0x82AC5D8B, 0xC65B82E5, 0x82A45D82, 0xAA95DB5B, 0x82D95D91,
    0xB65B82BC, 0x82F15D82, 0xC582AB82, 0xDC82B982, 0xF1814200, 0x43726561, 0x74656420, 0x456D626C,
    0x656D7320, 0x63616E6E, 0x6F742062, 0x650A7361, 0x76656420, 0x746F2074, 0x68697320, 0x4D656D6F,
    0x72792043, 0x6172642E, 0x0, 0x4C495354, 0x5F454E44, 0x20474552, 0x0, 0x4C495354,
    0x5F454E44, 0x20465241, 0x0, 0x4C495354, 0x5F454E44, 0x20535041, 0x0, 0x4C495354,
    0x5F454E44, 0x20495441, 0x0, 0x82B182CC, 0x82DC82DC, 0x82C582CD, 0x83478393, 0x8375838C,
    0x838082CC, 0x8DEC5B82, 0xB382AC5D, 0x8BC65B82, 0xE582A45D, 0x82AA95DB, 0x5B82D95D, 0x91B65B82,
    0xBC82F15D, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0, 0x54686520, 0x46494C45, 0x20446174,
    0x61206578, 0x69737473, 0x20696E20, 0x534C4F54, 0x2E200A4F, 0x76657277, 0x72697465, 0x3F000000,
    0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x47455200, 0x4F564552, 0x57524954, 0x455F5155,
    0x45525920, 0x46524100, 0x4F564552, 0x57524954, 0x455F5155, 0x45525920, 0x53504100, 0x4F564552,
    0x57524954, 0x455F5155, 0x45525920, 0x49544100, 0x20202020, 0x8FE35B82, 0xA482ED5D, 0x8F915B82,
    0xAA5D82AB, 0x82B582C4, 0x82E082E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81482020, 0x20200000,  /* fzgx-allow: A1 retail data bytes */
    0x43726561, 0x74652061, 0x204E6577, 0x2046696C, 0x65000000, 0x4E45575F, 0x43524541, 0x54452047,
    0x45520000, 0x4E45575F, 0x43524541, 0x54452046, 0x52410000, 0x4E45575F, 0x43524541, 0x54452053,
    0x50410000, 0x4E45575F, 0x43524541, 0x54452049, 0x54410000, 0x90568B4B, 0x8DEC90AC, 0x0,
    0x43726561, 0x74652061, 0x206E6577, 0x2066696C, 0x652E0000, 0x4E45575F, 0x43524541, 0x54455F44,
    0x4F204745, 0x52000000, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F204652, 0x41000000, 0x4E45575F,
    0x43524541, 0x54455F44, 0x4F205350, 0x41000000, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F204954,
    0x41000000, 0x90568B4B, 0x82C98374, 0x83408343, 0x838B82F0, 0x8DEC90AC, 0x82B582DC, 0x82B78142,
    0x0, 0x43616E6E, 0x6F742063, 0x72656174, 0x65206120, 0x6E657720, 0x66696C65, 0x2E000000,
    0x4E45575F, 0x43524541, 0x54455F44, 0x4F4E5420, 0x47455200, 0x4E45575F, 0x43524541, 0x54455F44,
    0x4F4E5420, 0x46524100, 0x4E45575F, 0x43524541, 0x54455F44, 0x4F4E5420, 0x53504100, 0x4E45575F,
    0x43524541, 0x54455F44, 0x4F4E5420, 0x49544100, 0x90568B4B, 0x82C98374, 0x83408343, 0x838B82F0,
    0x8DEC90AC, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0, 0x25642062, 0x6C6F636B, 0x28732920,
    0x6F662073, 0x70616365, 0x20617661, 0x696C6162, 0x6C652E00, 0x46524545, 0x5F535041, 0x43452047,
    0x45520000, 0x46524545, 0x5F535041, 0x43452046, 0x52410000, 0x46524545, 0x5F535041, 0x43452053,
    0x50410000, 0x46524545, 0x5F535041, 0x43452049, 0x54410000, 0x8BF382AB, 0x976597CA, 0x20256483,
    0x75838D83, 0x62834E00, 0x25642062, 0x6C6F636B, 0x28732920, 0x6E656564, 0x65642E20, 0x28256420,
    0x66726565, 0x20626C6F, 0x636B2873, 0x29206176, 0x61696C61, 0x626C6529, 0x0, 0x46524545,
    0x5F4E4545, 0x445F5350, 0x41434520, 0x47455200, 0x46524545, 0x5F4E4545, 0x445F5350, 0x41434520,
    0x46524100, 0x46524545, 0x5F4E4545, 0x445F5350, 0x41434520, 0x53504100, 0x46524545, 0x5F4E4545,
    0x445F5350, 0x41434520, 0x49544100, 0x25648375, 0x838D8362, 0x834E954B, 0x9776288B, 0xF382AB97,
    0x6597CA20, 0x25648375, 0x838D8362, 0x834E2900, 0x436F7272, 0x75707420, 0x46696C65, 0x0,
    0x42524F4B, 0x454E5F46, 0x494C4520, 0x47455200, 0x42524F4B, 0x454E5F46, 0x494C4520, 0x46524100,
    0x42524F4B, 0x454E5F46, 0x494C4520, 0x53504100, 0x42524F4B, 0x454E5F46, 0x494C4520, 0x49544100,
    0x89F382EA, 0x82BD8374, 0x83408343, 0x838B0000, 0x54686973, 0x2066696C, 0x65206973, 0x20636F72,
    0x72757074, 0x65642061, 0x6E64206D, 0x75737420, 0x62652064, 0x656C6574, 0x65642E00, 0x42524F4B,
    0x454E5F46, 0x494C455F, 0x44454C20, 0x47455200, 0x42524F4B, 0x454E5F46, 0x494C455F, 0x44454C20,
    0x46524100, 0x42524F4B, 0x454E5F46, 0x494C455F, 0x44454C20, 0x53504100, 0x42524F4B, 0x454E5F46,
    0x494C455F, 0x44454C20, 0x49544100, 0x82B182CC, 0x83748340, 0x8343838B, 0x82CD89F3, 0x82EA82C4,
    0x82A282E9, 0x82CC82C5, 0x8FC182B7, 0x954B9776, 0x82AA82A0, 0x82E882DC, 0x82B78142, 0x0,
    (u32)lbl_1_data_35BF4__fzgx_offset_0, (u32)lbl_1_data_35C44__fzgx_offset_0, (u32)lbl_1_data_35C50__fzgx_offset_0, (u32)lbl_1_data_35C5C__fzgx_offset_0, (u32)lbl_1_data_35C68__fzgx_offset_0, (u32)lbl_1_data_35C74__fzgx_offset_0, (u32)lbl_1_data_35CE0__fzgx_offset_0, (u32)lbl_1_data_35D24__fzgx_offset_0,
    (u32)lbl_1_data_35D34__fzgx_offset_0, (u32)lbl_1_data_35D44__fzgx_offset_0, (u32)lbl_1_data_35D54__fzgx_offset_0, (u32)lbl_1_data_35D64__fzgx_offset_0, (u32)lbl_1_data_35DC4__fzgx_offset_0, (u32)lbl_1_data_35E34__fzgx_offset_0, (u32)lbl_1_data_35E40__fzgx_offset_0, (u32)lbl_1_data_35E4C__fzgx_offset_0,
    (u32)lbl_1_data_35E58__fzgx_offset_0, (u32)lbl_1_data_35E64__fzgx_offset_0, (u32)lbl_1_data_35F4C__fzgx_offset_0, (u32)lbl_1_data_35FA4__fzgx_offset_0, (u32)lbl_1_data_35FB0__fzgx_offset_0, (u32)lbl_1_data_35FBC__fzgx_offset_0, (u32)lbl_1_data_35FC8__fzgx_offset_0, (u32)lbl_1_data_35FD4__fzgx_offset_0,
    (u32)lbl_1_data_3603C__fzgx_offset_0, (u32)lbl_1_data_36070__fzgx_offset_0, (u32)lbl_1_data_36088__fzgx_offset_0, (u32)lbl_1_data_360A0__fzgx_offset_0, (u32)lbl_1_data_360B8__fzgx_offset_0, (u32)lbl_1_data_360D0__fzgx_offset_0, (u32)lbl_1_data_360F8__fzgx_offset_0, (u32)lbl_1_data_36128__fzgx_offset_0,
    (u32)lbl_1_data_36140__fzgx_offset_0, (u32)lbl_1_data_36158__fzgx_offset_0, (u32)lbl_1_data_36170__fzgx_offset_0, (u32)lbl_1_data_36188__fzgx_offset_0, (u32)lbl_1_data_361B0__fzgx_offset_0, (u32)lbl_1_data_361E0__fzgx_offset_0, (u32)lbl_1_data_361F8__fzgx_offset_0, (u32)lbl_1_data_36210__fzgx_offset_0,
    (u32)lbl_1_data_36228__fzgx_offset_0, (u32)lbl_1_data_36240__fzgx_offset_0, (u32)lbl_1_data_36270__fzgx_offset_0, (u32)lbl_1_data_362A0__fzgx_offset_0, (u32)lbl_1_data_362BC__fzgx_offset_0, (u32)lbl_1_data_362D8__fzgx_offset_0, (u32)lbl_1_data_362F4__fzgx_offset_0, (u32)lbl_1_data_36310__fzgx_offset_0,
    (u32)lbl_1_data_36338__fzgx_offset_0, (u32)lbl_1_data_3636C__fzgx_offset_0, (u32)lbl_1_data_36388__fzgx_offset_0, (u32)lbl_1_data_363A4__fzgx_offset_0, (u32)lbl_1_data_363C0__fzgx_offset_0, (u32)lbl_1_data_363DC__fzgx_offset_0, (u32)lbl_1_data_36408__fzgx_offset_0, (u32)lbl_1_data_3644C__fzgx_offset_0,
    (u32)lbl_1_data_3646C__fzgx_offset_0, (u32)lbl_1_data_3648C__fzgx_offset_0, (u32)lbl_1_data_364AC__fzgx_offset_0, (u32)lbl_1_data_364CC__fzgx_offset_0, (u32)lbl_1_data_36510__fzgx_offset_0, (u32)lbl_1_data_36554__fzgx_offset_0, (u32)lbl_1_data_36574__fzgx_offset_0, (u32)lbl_1_data_36594__fzgx_offset_0,
    (u32)lbl_1_data_365B4__fzgx_offset_0, (u32)lbl_1_data_365D4__fzgx_offset_0, (u32)lbl_1_data_36618__fzgx_offset_0, (u32)lbl_1_data_36648__fzgx_offset_0, (u32)lbl_1_data_36668__fzgx_offset_0, (u32)lbl_1_data_36688__fzgx_offset_0, (u32)lbl_1_data_366A8__fzgx_offset_0, (u32)lbl_1_data_366C8__fzgx_offset_0,
    (u32)lbl_1_data_366F8__fzgx_offset_0, (u32)lbl_1_data_3673C__fzgx_offset_0, (u32)lbl_1_data_3675C__fzgx_offset_0, (u32)lbl_1_data_3677C__fzgx_offset_0, (u32)lbl_1_data_3679C__fzgx_offset_0, (u32)lbl_1_data_367BC__fzgx_offset_0, (u32)lbl_1_data_36800__fzgx_offset_0, (u32)lbl_1_data_36844__fzgx_offset_0,
    (u32)lbl_1_data_36864__fzgx_offset_0, (u32)lbl_1_data_36884__fzgx_offset_0, (u32)lbl_1_data_368A4__fzgx_offset_0, (u32)lbl_1_data_368C4__fzgx_offset_0, (u32)lbl_1_data_36908__fzgx_offset_0, (u32)lbl_1_data_36928__fzgx_offset_0, (u32)lbl_1_data_36938__fzgx_offset_0, (u32)lbl_1_data_36948__fzgx_offset_0,
    (u32)lbl_1_data_36958__fzgx_offset_0, (u32)lbl_1_data_36968__fzgx_offset_0, (u32)lbl_1_data_36984__fzgx_offset_0, (u32)lbl_1_data_36998__fzgx_offset_0, (u32)lbl_1_data_369A8__fzgx_offset_0, (u32)lbl_1_data_369B8__fzgx_offset_0, (u32)lbl_1_data_369C8__fzgx_offset_0, (u32)lbl_1_data_369D8__fzgx_offset_0,
    (u32)lbl_1_data_369E8__fzgx_offset_0, (u32)lbl_1_data_36A1C__fzgx_offset_0, (u32)lbl_1_data_36A34__fzgx_offset_0, (u32)lbl_1_data_36A4C__fzgx_offset_0, (u32)lbl_1_data_36A64__fzgx_offset_0, (u32)lbl_1_data_36A7C__fzgx_offset_0, (u32)lbl_1_data_36AB0__fzgx_offset_0, (u32)lbl_1_data_36AE4__fzgx_offset_0,
    (u32)lbl_1_data_36AFC__fzgx_offset_0, (u32)lbl_1_data_36B14__fzgx_offset_0, (u32)lbl_1_data_36B2C__fzgx_offset_0, (u32)lbl_1_data_36B44__fzgx_offset_0, (u32)lbl_1_data_36B78__fzgx_offset_0, (u32)lbl_1_data_36B98__fzgx_offset_0, (u32)lbl_1_data_36BB0__fzgx_offset_0, (u32)lbl_1_data_36BC8__fzgx_offset_0,
    (u32)lbl_1_data_36BE0__fzgx_offset_0, (u32)lbl_1_data_36BF8__fzgx_offset_0, (u32)lbl_1_data_36C1C__fzgx_offset_0, (u32)lbl_1_data_36C50__fzgx_offset_0, (u32)lbl_1_data_36C6C__fzgx_offset_0, (u32)lbl_1_data_36C88__fzgx_offset_0, (u32)lbl_1_data_36CA4__fzgx_offset_0, (u32)lbl_1_data_36CC0__fzgx_offset_0,
    (u32)lbl_1_data_36CF0__fzgx_offset_0, (u32)lbl_1_data_36D28__fzgx_offset_0, (u32)lbl_1_data_36D44__fzgx_offset_0, (u32)lbl_1_data_36D60__fzgx_offset_0, (u32)lbl_1_data_36D7C__fzgx_offset_0, (u32)lbl_1_data_36D98__fzgx_offset_0, (u32)lbl_1_data_36DD0__fzgx_offset_0, (u32)lbl_1_data_36E10__fzgx_offset_0,
    (u32)lbl_1_data_36E30__fzgx_offset_0, (u32)lbl_1_data_36E50__fzgx_offset_0, (u32)lbl_1_data_36E70__fzgx_offset_0, (u32)lbl_1_data_36E90__fzgx_offset_0, (u32)lbl_1_data_36ED0__fzgx_offset_0, (u32)lbl_1_data_36F0C__fzgx_offset_0, (u32)lbl_1_data_36F2C__fzgx_offset_0, (u32)lbl_1_data_36F4C__fzgx_offset_0,
    (u32)lbl_1_data_36F6C__fzgx_offset_0, (u32)lbl_1_data_36F8C__fzgx_offset_0, (u32)lbl_1_data_36FCC__fzgx_offset_0, (u32)lbl_1_data_37008__fzgx_offset_0, (u32)lbl_1_data_37028__fzgx_offset_0, (u32)lbl_1_data_37048__fzgx_offset_0, (u32)lbl_1_data_37068__fzgx_offset_0, (u32)lbl_1_data_37088__fzgx_offset_0,
    (u32)lbl_1_data_370CC__fzgx_offset_0, (u32)lbl_1_data_3710C__fzgx_offset_0, (u32)lbl_1_data_3712C__fzgx_offset_0, (u32)lbl_1_data_3714C__fzgx_offset_0, (u32)lbl_1_data_3716C__fzgx_offset_0, (u32)lbl_1_data_3718C__fzgx_offset_0, (u32)lbl_1_data_371C8__fzgx_offset_0, (u32)lbl_1_data_37208__fzgx_offset_0,
    (u32)lbl_1_data_37228__fzgx_offset_0, (u32)lbl_1_data_37248__fzgx_offset_0, (u32)lbl_1_data_37268__fzgx_offset_0, (u32)lbl_1_data_37288__fzgx_offset_0, (u32)lbl_1_data_372C8__fzgx_offset_0, (u32)lbl_1_data_372F4__fzgx_offset_0, (u32)lbl_1_data_3730C__fzgx_offset_0, (u32)lbl_1_data_37324__fzgx_offset_0,
    (u32)lbl_1_data_3733C__fzgx_offset_0, (u32)lbl_1_data_37354__fzgx_offset_0, (u32)lbl_1_data_37380__fzgx_offset_0, (u32)lbl_1_data_373DC__fzgx_offset_0, (u32)lbl_1_data_373F4__fzgx_offset_0, (u32)lbl_1_data_3740C__fzgx_offset_0, (u32)lbl_1_data_37424__fzgx_offset_0, (u32)lbl_1_data_3743C__fzgx_offset_0,
    (u32)lbl_1_data_374A8__fzgx_offset_0, (u32)lbl_1_data_374D8__fzgx_offset_0, (u32)lbl_1_data_374E8__fzgx_offset_0, (u32)lbl_1_data_374F8__fzgx_offset_0, (u32)lbl_1_data_37508__fzgx_offset_0, (u32)lbl_1_data_37518__fzgx_offset_0, (u32)lbl_1_data_37550__fzgx_offset_0, (u32)lbl_1_data_375A4__fzgx_offset_0,
    (u32)lbl_1_data_375B8__fzgx_offset_0, (u32)lbl_1_data_375CC__fzgx_offset_0, (u32)lbl_1_data_375E0__fzgx_offset_0, (u32)lbl_1_data_375F4__fzgx_offset_0, (u32)lbl_1_data_3763C__fzgx_offset_0, (u32)lbl_1_data_37680__fzgx_offset_0, (u32)lbl_1_data_37690__fzgx_offset_0, (u32)lbl_1_data_376A0__fzgx_offset_0,
    (u32)lbl_1_data_376B0__fzgx_offset_0, (u32)lbl_1_data_376C0__fzgx_offset_0, (u32)lbl_1_data_37704__fzgx_offset_0, (u32)lbl_1_data_3773C__fzgx_offset_0, (u32)lbl_1_data_37750__fzgx_offset_0, (u32)lbl_1_data_37764__fzgx_offset_0, (u32)lbl_1_data_37778__fzgx_offset_0, (u32)lbl_1_data_3778C__fzgx_offset_0,
    (u32)lbl_1_data_377D0__fzgx_offset_0, (u32)lbl_1_data_37808__fzgx_offset_0, (u32)lbl_1_data_37818__fzgx_offset_0, (u32)lbl_1_data_37828__fzgx_offset_0, (u32)lbl_1_data_37838__fzgx_offset_0, (u32)lbl_1_data_37848__fzgx_offset_0, (u32)lbl_1_data_3788C__fzgx_offset_0, (u32)lbl_1_data_378EC__fzgx_offset_0,
    (u32)lbl_1_data_378FC__fzgx_offset_0, (u32)lbl_1_data_3790C__fzgx_offset_0, (u32)lbl_1_data_3791C__fzgx_offset_0, (u32)lbl_1_data_3792C__fzgx_offset_0, (u32)lbl_1_data_37984__fzgx_offset_0, (u32)lbl_1_data_379C0__fzgx_offset_0, (u32)lbl_1_data_379D0__fzgx_offset_0, (u32)lbl_1_data_379E0__fzgx_offset_0,
    (u32)lbl_1_data_379F0__fzgx_offset_0, (u32)lbl_1_data_37A00__fzgx_offset_0, (u32)lbl_1_data_37A58__fzgx_offset_0, (u32)lbl_1_data_37AB8__fzgx_offset_0, (u32)lbl_1_data_37ACC__fzgx_offset_0, (u32)lbl_1_data_37AE0__fzgx_offset_0, (u32)lbl_1_data_37AF4__fzgx_offset_0, (u32)lbl_1_data_37B08__fzgx_offset_0,
    (u32)lbl_1_data_37B74__fzgx_offset_0, (u32)lbl_1_data_37B9C__fzgx_offset_0, (u32)lbl_1_data_37BB0__fzgx_offset_0, (u32)lbl_1_data_37BC4__fzgx_offset_0, (u32)lbl_1_data_37BD8__fzgx_offset_0, (u32)lbl_1_data_37BEC__fzgx_offset_0, (u32)lbl_1_data_37C28__fzgx_offset_0, (u32)lbl_1_data_37C30__fzgx_offset_0,
    (u32)lbl_1_data_37C3C__fzgx_offset_0, (u32)lbl_1_data_37C48__fzgx_offset_0, (u32)lbl_1_data_37C54__fzgx_offset_0, (u32)lbl_1_data_37C60__fzgx_offset_0, (u32)lbl_1_data_37C6C__fzgx_offset_0, (u32)lbl_1_data_37C74__fzgx_offset_0, (u32)lbl_1_data_37C80__fzgx_offset_0, (u32)lbl_1_data_37C8C__fzgx_offset_0,
    (u32)lbl_1_data_37C98__fzgx_offset_0, (u32)lbl_1_data_37CA4__fzgx_offset_0, (u32)lbl_1_data_37CB0__fzgx_offset_0, (u32)lbl_1_data_37CB4__fzgx_offset_0, (u32)lbl_1_data_37CBC__fzgx_offset_0, (u32)lbl_1_data_37CC4__fzgx_offset_0, (u32)lbl_1_data_37CCC__fzgx_offset_0, (u32)lbl_1_data_37CD4__fzgx_offset_0,
    (u32)lbl_1_data_37CDC__fzgx_offset_0, (u32)lbl_1_data_37CE0__fzgx_offset_0, (u32)lbl_1_data_37CE8__fzgx_offset_0, (u32)lbl_1_data_37CF0__fzgx_offset_0, (u32)lbl_1_data_37CF8__fzgx_offset_0, (u32)lbl_1_data_37D00__fzgx_offset_0, (u32)lbl_1_data_37D08__fzgx_offset_0, (u32)lbl_1_data_37D44__fzgx_offset_0,
    (u32)lbl_1_data_37D58__fzgx_offset_0, (u32)lbl_1_data_37D6C__fzgx_offset_0, (u32)lbl_1_data_37D80__fzgx_offset_0, (u32)lbl_1_data_37D94__fzgx_offset_0, (u32)lbl_1_data_37DD4__fzgx_offset_0, (u32)lbl_1_data_37F64__fzgx_offset_0, (u32)lbl_1_data_37F70__fzgx_offset_0, (u32)lbl_1_data_37F7C__fzgx_offset_0,
    (u32)lbl_1_data_37F88__fzgx_offset_0, (u32)lbl_1_data_37F94__fzgx_offset_0, (u32)lbl_1_data_381E4__fzgx_offset_0, (u32)lbl_1_data_382C8__fzgx_offset_0, (u32)lbl_1_data_382D4__fzgx_offset_0, (u32)lbl_1_data_382E0__fzgx_offset_0, (u32)lbl_1_data_382EC__fzgx_offset_0, (u32)lbl_1_data_382F8__fzgx_offset_0,
    (u32)lbl_1_data_38454__fzgx_offset_0, (u32)lbl_1_data_385E4__fzgx_offset_0, (u32)lbl_1_data_385F4__fzgx_offset_0, (u32)lbl_1_data_38604__fzgx_offset_0, (u32)lbl_1_data_38614__fzgx_offset_0, (u32)lbl_1_data_38624__fzgx_offset_0, (u32)lbl_1_data_38874__fzgx_offset_0, (u32)lbl_1_data_38958__fzgx_offset_0,
    (u32)lbl_1_data_3896C__fzgx_offset_0, (u32)lbl_1_data_38980__fzgx_offset_0, (u32)lbl_1_data_38994__fzgx_offset_0, (u32)lbl_1_data_389A8__fzgx_offset_0, (u32)lbl_1_data_38B04__fzgx_offset_0, (u32)lbl_1_data_38B58__fzgx_offset_0, (u32)lbl_1_data_38B6C__fzgx_offset_0, (u32)lbl_1_data_38B80__fzgx_offset_0,
    (u32)lbl_1_data_38B94__fzgx_offset_0, (u32)lbl_1_data_38BA8__fzgx_offset_0, (u32)lbl_1_data_38C08__fzgx_offset_0, (u32)lbl_1_data_38C30__fzgx_offset_0, (u32)lbl_1_data_38C48__fzgx_offset_0, (u32)lbl_1_data_38C60__fzgx_offset_0, (u32)lbl_1_data_38C78__fzgx_offset_0, (u32)lbl_1_data_38C90__fzgx_offset_0,
    (u32)lbl_1_data_38CCC__fzgx_offset_0, (u32)lbl_1_data_38D00__fzgx_offset_0, (u32)lbl_1_data_38D10__fzgx_offset_0, (u32)lbl_1_data_38D20__fzgx_offset_0, (u32)lbl_1_data_38D30__fzgx_offset_0, (u32)lbl_1_data_38D40__fzgx_offset_0, (u32)lbl_1_data_38D80__fzgx_offset_0, (u32)lbl_1_data_38D98__fzgx_offset_0,
    (u32)lbl_1_data_38DAC__fzgx_offset_0, (u32)lbl_1_data_38DC0__fzgx_offset_0, (u32)lbl_1_data_38DD4__fzgx_offset_0, (u32)lbl_1_data_38DE8__fzgx_offset_0, (u32)lbl_1_data_38E04__fzgx_offset_0, (u32)lbl_1_data_38E0C__fzgx_offset_0, (u32)lbl_1_data_38E18__fzgx_offset_0, (u32)lbl_1_data_38E24__fzgx_offset_0,
    (u32)lbl_1_data_38E30__fzgx_offset_0, (u32)lbl_1_data_38E3C__fzgx_offset_0, (u32)lbl_1_data_38E48__fzgx_offset_0, (u32)lbl_1_data_38E80__fzgx_offset_0, (u32)lbl_1_data_38E90__fzgx_offset_0, (u32)lbl_1_data_38EA0__fzgx_offset_0, (u32)lbl_1_data_38EB0__fzgx_offset_0, (u32)lbl_1_data_38EC0__fzgx_offset_0,
    (u32)lbl_1_data_38F04__fzgx_offset_0, (u32)lbl_1_data_38F30__fzgx_offset_0, (u32)lbl_1_data_38F40__fzgx_offset_0, (u32)lbl_1_data_38F50__fzgx_offset_0, (u32)lbl_1_data_38F60__fzgx_offset_0, (u32)lbl_1_data_38F70__fzgx_offset_0, (u32)lbl_1_data_38FA8__fzgx_offset_0, (u32)lbl_1_data_38FE8__fzgx_offset_0,
    (u32)lbl_1_data_38FF8__fzgx_offset_0, (u32)lbl_1_data_39008__fzgx_offset_0, (u32)lbl_1_data_39018__fzgx_offset_0, (u32)lbl_1_data_39028__fzgx_offset_0, (u32)lbl_1_data_3906C__fzgx_offset_0, (u32)lbl_1_data_390C4__fzgx_offset_0, (u32)lbl_1_data_390D4__fzgx_offset_0, (u32)lbl_1_data_390E4__fzgx_offset_0,
    (u32)lbl_1_data_390F4__fzgx_offset_0, (u32)lbl_1_data_39104__fzgx_offset_0, (u32)lbl_1_data_39148__fzgx_offset_0, (u32)lbl_1_data_39190__fzgx_offset_0, (u32)lbl_1_data_3919C__fzgx_offset_0, (u32)lbl_1_data_391A8__fzgx_offset_0, (u32)lbl_1_data_391B4__fzgx_offset_0, (u32)lbl_1_data_391C0__fzgx_offset_0,
    (u32)lbl_1_data_39214__fzgx_offset_0, (u32)lbl_1_data_39248__fzgx_offset_0, (u32)lbl_1_data_39254__fzgx_offset_0, (u32)lbl_1_data_39260__fzgx_offset_0, (u32)lbl_1_data_3926C__fzgx_offset_0, (u32)lbl_1_data_39278__fzgx_offset_0, (u32)lbl_1_data_392AC__fzgx_offset_0, (u32)lbl_1_data_392E4__fzgx_offset_0,
    (u32)lbl_1_data_392F0__fzgx_offset_0, (u32)lbl_1_data_392FC__fzgx_offset_0, (u32)lbl_1_data_39308__fzgx_offset_0, (u32)lbl_1_data_39314__fzgx_offset_0, (u32)lbl_1_data_39348__fzgx_offset_0, (u32)lbl_1_data_3937C__fzgx_offset_0, (u32)lbl_1_data_39388__fzgx_offset_0, (u32)lbl_1_data_39394__fzgx_offset_0,
    (u32)lbl_1_data_393A0__fzgx_offset_0, (u32)lbl_1_data_393AC__fzgx_offset_0, (u32)lbl_1_data_393E0__fzgx_offset_0, (u32)lbl_1_data_39418__fzgx_offset_0, (u32)lbl_1_data_39424__fzgx_offset_0, (u32)lbl_1_data_39430__fzgx_offset_0, (u32)lbl_1_data_3943C__fzgx_offset_0, (u32)lbl_1_data_39448__fzgx_offset_0,
    (u32)lbl_1_data_3947C__fzgx_offset_0, (u32)lbl_1_data_394B8__fzgx_offset_0, (u32)lbl_1_data_394C8__fzgx_offset_0, (u32)lbl_1_data_394D8__fzgx_offset_0, (u32)lbl_1_data_394E8__fzgx_offset_0, (u32)lbl_1_data_394F8__fzgx_offset_0, (u32)lbl_1_data_39520__fzgx_offset_0, (u32)lbl_1_data_39550__fzgx_offset_0,
    (u32)lbl_1_data_39564__fzgx_offset_0, (u32)lbl_1_data_39578__fzgx_offset_0, (u32)lbl_1_data_3958C__fzgx_offset_0, (u32)lbl_1_data_395A0__fzgx_offset_0, (u32)lbl_1_data_395DC__fzgx_offset_0, (u32)lbl_1_data_39618__fzgx_offset_0, (u32)lbl_1_data_39628__fzgx_offset_0, (u32)lbl_1_data_39638__fzgx_offset_0,
    (u32)lbl_1_data_39648__fzgx_offset_0, (u32)lbl_1_data_39658__fzgx_offset_0, (u32)lbl_1_data_39694__fzgx_offset_0, (u32)lbl_1_data_396BC__fzgx_offset_0, (u32)lbl_1_data_396CC__fzgx_offset_0, (u32)lbl_1_data_396DC__fzgx_offset_0, (u32)lbl_1_data_396EC__fzgx_offset_0, (u32)lbl_1_data_396FC__fzgx_offset_0,
    (u32)lbl_1_data_39740__fzgx_offset_0, (u32)lbl_1_data_39780__fzgx_offset_0, (u32)lbl_1_data_39790__fzgx_offset_0, (u32)lbl_1_data_397A0__fzgx_offset_0, (u32)lbl_1_data_397B0__fzgx_offset_0, (u32)lbl_1_data_397C0__fzgx_offset_0, (u32)lbl_1_data_39800__fzgx_offset_0, (u32)lbl_1_data_39838__fzgx_offset_0,
    (u32)lbl_1_data_39848__fzgx_offset_0, (u32)lbl_1_data_39858__fzgx_offset_0, (u32)lbl_1_data_39868__fzgx_offset_0, (u32)lbl_1_data_39878__fzgx_offset_0, (u32)lbl_1_data_398A0__fzgx_offset_0, (u32)lbl_1_data_398B0__fzgx_offset_0, (u32)lbl_1_data_398C0__fzgx_offset_0, (u32)lbl_1_data_398D0__fzgx_offset_0,
    (u32)lbl_1_data_398E0__fzgx_offset_0, (u32)lbl_1_data_398F0__fzgx_offset_0, (u32)lbl_1_data_39900__fzgx_offset_0, (u32)lbl_1_data_3990C__fzgx_offset_0, (u32)lbl_1_data_3991C__fzgx_offset_0, (u32)lbl_1_data_3992C__fzgx_offset_0, (u32)lbl_1_data_3993C__fzgx_offset_0, (u32)lbl_1_data_3994C__fzgx_offset_0,
    (u32)lbl_1_data_39958__fzgx_offset_0, (u32)lbl_1_data_39968__fzgx_offset_0, (u32)lbl_1_data_39978__fzgx_offset_0, (u32)lbl_1_data_39988__fzgx_offset_0, (u32)lbl_1_data_39998__fzgx_offset_0, (u32)lbl_1_data_399A8__fzgx_offset_0, (u32)lbl_1_data_399B8__fzgx_offset_0, (u32)lbl_1_data_399C8__fzgx_offset_0,
    (u32)lbl_1_data_399D8__fzgx_offset_0, (u32)lbl_1_data_399E8__fzgx_offset_0, (u32)lbl_1_data_399F8__fzgx_offset_0, (u32)lbl_1_data_39A08__fzgx_offset_0, (u32)lbl_1_data_39A18__fzgx_offset_0, (u32)lbl_1_data_39A6C__fzgx_offset_0, (u32)lbl_1_data_39A78__fzgx_offset_0, (u32)lbl_1_data_39A84__fzgx_offset_0,
    (u32)lbl_1_data_39A90__fzgx_offset_0, (u32)lbl_1_data_39A9C__fzgx_offset_0, (u32)lbl_1_data_39B04__fzgx_offset_0, (u32)lbl_1_data_39B58__fzgx_offset_0, (u32)lbl_1_data_39B64__fzgx_offset_0, (u32)lbl_1_data_39B70__fzgx_offset_0, (u32)lbl_1_data_39B7C__fzgx_offset_0, (u32)lbl_1_data_39B88__fzgx_offset_0,
    (u32)lbl_1_data_39BF0__fzgx_offset_0, (u32)lbl_1_data_39C1C__fzgx_offset_0, (u32)lbl_1_data_39C2C__fzgx_offset_0, (u32)lbl_1_data_39C3C__fzgx_offset_0, (u32)lbl_1_data_39C4C__fzgx_offset_0, (u32)lbl_1_data_39C5C__fzgx_offset_0, (u32)lbl_1_data_39C88__fzgx_offset_0, (u32)lbl_1_data_39CB8__fzgx_offset_0,
    (u32)lbl_1_data_39CC8__fzgx_offset_0, (u32)lbl_1_data_39CD8__fzgx_offset_0, (u32)lbl_1_data_39CE8__fzgx_offset_0, (u32)lbl_1_data_39CF8__fzgx_offset_0, (u32)lbl_1_data_39D2C__fzgx_offset_0, (u32)lbl_1_data_39DC4__fzgx_offset_0, (u32)lbl_1_data_39DDC__fzgx_offset_0, (u32)lbl_1_data_39DF4__fzgx_offset_0,
    (u32)lbl_1_data_39E0C__fzgx_offset_0, (u32)lbl_1_data_39E24__fzgx_offset_0, (u32)lbl_1_data_39EB0__fzgx_offset_0, (u32)lbl_1_data_39EF4__fzgx_offset_0, (u32)lbl_1_data_39F0C__fzgx_offset_0, (u32)lbl_1_data_39F24__fzgx_offset_0, (u32)lbl_1_data_39F3C__fzgx_offset_0, (u32)lbl_1_data_39F54__fzgx_offset_0,
    (u32)lbl_1_data_39FA4__fzgx_offset_0, (u32)lbl_1_data_3A018__fzgx_offset_0, (u32)lbl_1_data_3A01C__fzgx_offset_0, (u32)lbl_1_data_3A020__fzgx_offset_0, (u32)lbl_1_data_3A024__fzgx_offset_0, (u32)lbl_1_data_3A028__fzgx_offset_0, (u32)lbl_1_data_3A0E4__fzgx_offset_0, (u32)lbl_1_data_3A15C__fzgx_offset_0,
    (u32)lbl_1_data_3A160__fzgx_offset_0, (u32)lbl_1_data_3A164__fzgx_offset_0, (u32)lbl_1_data_3A168__fzgx_offset_0, (u32)lbl_1_data_3A16C__fzgx_offset_0, (u32)lbl_1_data_3A1C8__fzgx_offset_0, (u32)lbl_1_data_3A1D0__fzgx_offset_0, (u32)lbl_1_data_3A1DC__fzgx_offset_0, (u32)lbl_1_data_3A1E8__fzgx_offset_0,
    (u32)lbl_1_data_3A1F4__fzgx_offset_0, (u32)lbl_1_data_3A200__fzgx_offset_0, (u32)lbl_1_data_3A208__fzgx_offset_0, (u32)lbl_1_data_3A210__fzgx_offset_0, (u32)lbl_1_data_3A21C__fzgx_offset_0, (u32)lbl_1_data_3A228__fzgx_offset_0, (u32)lbl_1_data_3A234__fzgx_offset_0, (u32)lbl_1_data_3A240__fzgx_offset_0,
    (u32)lbl_1_data_3A248__fzgx_offset_0, (u32)lbl_1_data_3A250__fzgx_offset_0, (u32)lbl_1_data_3A25C__fzgx_offset_0, (u32)lbl_1_data_3A268__fzgx_offset_0, (u32)lbl_1_data_3A274__fzgx_offset_0, (u32)lbl_1_data_3A280__fzgx_offset_0, (u32)lbl_1_data_3A28C__fzgx_offset_0, (u32)lbl_1_data_3A294__fzgx_offset_0,
    (u32)lbl_1_data_3A2A0__fzgx_offset_0, (u32)lbl_1_data_3A2AC__fzgx_offset_0, (u32)lbl_1_data_3A2B8__fzgx_offset_0, (u32)lbl_1_data_3A2C4__fzgx_offset_0, (u32)lbl_1_data_3A2D0__fzgx_offset_0, (u32)lbl_1_data_3A2D8__fzgx_offset_0, (u32)lbl_1_data_3A2E4__fzgx_offset_0, (u32)lbl_1_data_3A2F0__fzgx_offset_0,
    (u32)lbl_1_data_3A2FC__fzgx_offset_0, (u32)lbl_1_data_3A308__fzgx_offset_0, (u32)lbl_1_data_3A314__fzgx_offset_0, (u32)lbl_1_data_3A31C__fzgx_offset_0, (u32)lbl_1_data_3A328__fzgx_offset_0, (u32)lbl_1_data_3A334__fzgx_offset_0, (u32)lbl_1_data_3A340__fzgx_offset_0, (u32)lbl_1_data_3A34C__fzgx_offset_0,
    (u32)lbl_1_data_3A358__fzgx_offset_0, (u32)lbl_1_data_3A360__fzgx_offset_0, (u32)lbl_1_data_3A36C__fzgx_offset_0, (u32)lbl_1_data_3A378__fzgx_offset_0, (u32)lbl_1_data_3A384__fzgx_offset_0, (u32)lbl_1_data_3A390__fzgx_offset_0, (u32)lbl_1_data_3A39C__fzgx_offset_0, (u32)lbl_1_data_3A3A4__fzgx_offset_0,
    (u32)lbl_1_data_3A3B0__fzgx_offset_0, (u32)lbl_1_data_3A3BC__fzgx_offset_0, (u32)lbl_1_data_3A3C8__fzgx_offset_0, (u32)lbl_1_data_3A3D4__fzgx_offset_0, (u32)lbl_1_data_3A3DC__fzgx_offset_0, (u32)lbl_1_data_3A520__fzgx_offset_0, (u32)lbl_1_data_3A524__fzgx_offset_0, (u32)lbl_1_data_3A528__fzgx_offset_0,
    (u32)lbl_1_data_3A52C__fzgx_offset_0, (u32)lbl_1_data_3A530__fzgx_offset_0, (u32)lbl_1_data_3A6A0__fzgx_offset_0, (u32)lbl_1_data_3A6E4__fzgx_offset_0, (u32)lbl_1_data_3A6E8__fzgx_offset_0, (u32)lbl_1_data_3A6EC__fzgx_offset_0, (u32)lbl_1_data_3A6F0__fzgx_offset_0, (u32)lbl_1_data_3A6F4__fzgx_offset_0,
    (u32)lbl_1_data_3A738__fzgx_offset_0, (u32)lbl_1_data_3A77C__fzgx_offset_0, (u32)lbl_1_data_3A780__fzgx_offset_0, (u32)lbl_1_data_3A784__fzgx_offset_0, (u32)lbl_1_data_3A788__fzgx_offset_0, (u32)lbl_1_data_3A78C__fzgx_offset_0, (u32)lbl_1_data_3A7D4__fzgx_offset_0, (u32)lbl_1_data_3A80C__fzgx_offset_0,
    (u32)lbl_1_data_3A810__fzgx_offset_0, (u32)lbl_1_data_3A814__fzgx_offset_0, (u32)lbl_1_data_3A818__fzgx_offset_0, (u32)lbl_1_data_3A81C__fzgx_offset_0, (u32)lbl_1_data_3A874__fzgx_offset_0, (u32)lbl_1_data_3A87C__fzgx_offset_0, (u32)lbl_1_data_3A880__fzgx_offset_0, (u32)lbl_1_data_3A884__fzgx_offset_0,
    (u32)lbl_1_data_3A888__fzgx_offset_0, (u32)lbl_1_data_3A88C__fzgx_offset_0, (u32)lbl_1_data_3A894__fzgx_offset_0, (u32)lbl_1_data_3A89C__fzgx_offset_0, (u32)lbl_1_data_3A8A0__fzgx_offset_0, (u32)lbl_1_data_3A8A4__fzgx_offset_0, (u32)lbl_1_data_3A8A8__fzgx_offset_0, (u32)lbl_1_data_3A8AC__fzgx_offset_0,
    (u32)lbl_1_data_3A8B4__fzgx_offset_0, (u32)lbl_1_data_3A8BC__fzgx_offset_0, (u32)lbl_1_data_3A8C0__fzgx_offset_0, (u32)lbl_1_data_3A8C4__fzgx_offset_0, (u32)lbl_1_data_3A8C8__fzgx_offset_0, (u32)lbl_1_data_3A8CC__fzgx_offset_0, (u32)lbl_1_data_3A8D4__fzgx_offset_0, (u32)lbl_1_data_3A8DC__fzgx_offset_0,
    (u32)lbl_1_data_3A8E0__fzgx_offset_0, (u32)lbl_1_data_3A8E4__fzgx_offset_0, (u32)lbl_1_data_3A8E8__fzgx_offset_0, (u32)lbl_1_data_3A8EC__fzgx_offset_0, (u32)lbl_1_data_3A8F4__fzgx_offset_0, (u32)lbl_1_data_3A928__fzgx_offset_0, (u32)lbl_1_data_3A92C__fzgx_offset_0, (u32)lbl_1_data_3A930__fzgx_offset_0,
    (u32)lbl_1_data_3A934__fzgx_offset_0, (u32)lbl_1_data_3A938__fzgx_offset_0, (u32)lbl_1_data_3A98C__fzgx_offset_0, (u32)lbl_1_data_3A9E0__fzgx_offset_0, (u32)lbl_1_data_3A9E4__fzgx_offset_0, (u32)lbl_1_data_3A9E8__fzgx_offset_0, (u32)lbl_1_data_3A9EC__fzgx_offset_0, (u32)lbl_1_data_3A9F0__fzgx_offset_0,
    (u32)lbl_1_data_3AA3C__fzgx_offset_0, (u32)lbl_1_data_3AA44__fzgx_offset_0, (u32)lbl_1_data_3AA48__fzgx_offset_0, (u32)lbl_1_data_3AA4C__fzgx_offset_0, (u32)lbl_1_data_3AA50__fzgx_offset_0, (u32)lbl_1_data_3AA54__fzgx_offset_0, (u32)lbl_1_data_3AA60__fzgx_offset_0, (u32)lbl_1_data_3AAA0__fzgx_offset_0,
    (u32)lbl_1_data_3AAB4__fzgx_offset_0, (u32)lbl_1_data_3AAC8__fzgx_offset_0, (u32)lbl_1_data_3AADC__fzgx_offset_0, (u32)lbl_1_data_3AAF0__fzgx_offset_0, (u32)lbl_1_data_3ABCC__fzgx_offset_0, (u32)lbl_1_data_3AC48__fzgx_offset_0, (u32)lbl_1_data_3AC58__fzgx_offset_0, (u32)lbl_1_data_3AC68__fzgx_offset_0,
    (u32)lbl_1_data_3AC78__fzgx_offset_0, (u32)lbl_1_data_3AC88__fzgx_offset_0, (u32)lbl_1_data_3AD68__fzgx_offset_0, (u32)lbl_1_data_3ADD8__fzgx_offset_0, (u32)lbl_1_data_3ADEC__fzgx_offset_0, (u32)lbl_1_data_3AE00__fzgx_offset_0, (u32)lbl_1_data_3AE14__fzgx_offset_0, (u32)lbl_1_data_3AE28__fzgx_offset_0,
    (u32)lbl_1_data_3AE2C__fzgx_offset_0, (u32)lbl_1_data_3AED4__fzgx_offset_0, (u32)lbl_1_data_3AEE4__fzgx_offset_0, (u32)lbl_1_data_3AEF4__fzgx_offset_0, (u32)lbl_1_data_3AF04__fzgx_offset_0, (u32)lbl_1_data_3AF14__fzgx_offset_0, (u32)lbl_1_data_3AF18__fzgx_offset_0, (u32)lbl_1_data_3AFC0__fzgx_offset_0,
    (u32)lbl_1_data_3AFD0__fzgx_offset_0, (u32)lbl_1_data_3AFE0__fzgx_offset_0, (u32)lbl_1_data_3AFF0__fzgx_offset_0, (u32)lbl_1_data_3B000__fzgx_offset_0, (u32)lbl_1_data_3B0B8__fzgx_offset_0, (u32)lbl_1_data_3B0E0__fzgx_offset_0, (u32)lbl_1_data_3B0F0__fzgx_offset_0, (u32)lbl_1_data_3B100__fzgx_offset_0,
    (u32)lbl_1_data_3B110__fzgx_offset_0, (u32)lbl_1_data_3B120__fzgx_offset_0, (u32)lbl_1_data_3B150__fzgx_offset_0, (u32)lbl_1_data_3B198__fzgx_offset_0, (u32)lbl_1_data_3B1A8__fzgx_offset_0, (u32)lbl_1_data_3B1B8__fzgx_offset_0, (u32)lbl_1_data_3B1C8__fzgx_offset_0, (u32)lbl_1_data_3B1D8__fzgx_offset_0,
    (u32)lbl_1_data_3B240__fzgx_offset_0, (u32)lbl_1_data_3B278__fzgx_offset_0, (u32)lbl_1_data_3B288__fzgx_offset_0, (u32)lbl_1_data_3B298__fzgx_offset_0, (u32)lbl_1_data_3B2A8__fzgx_offset_0, (u32)lbl_1_data_3B2B8__fzgx_offset_0, (u32)lbl_1_data_3B300__fzgx_offset_0, (u32)lbl_1_data_3B32C__fzgx_offset_0,
    (u32)lbl_1_data_3B340__fzgx_offset_0, (u32)lbl_1_data_3B354__fzgx_offset_0, (u32)lbl_1_data_3B368__fzgx_offset_0, (u32)lbl_1_data_3B37C__fzgx_offset_0, (u32)lbl_1_data_3B3AC__fzgx_offset_0, (u32)lbl_1_data_3B3C0__fzgx_offset_0, (u32)lbl_1_data_3B3D0__fzgx_offset_0, (u32)lbl_1_data_3B3E0__fzgx_offset_0,
    (u32)lbl_1_data_3B3F0__fzgx_offset_0, (u32)lbl_1_data_3B400__fzgx_offset_0, (u32)lbl_1_data_3B40C__fzgx_offset_0, (u32)lbl_1_data_3B420__fzgx_offset_0, (u32)lbl_1_data_3B434__fzgx_offset_0, (u32)lbl_1_data_3B448__fzgx_offset_0, (u32)lbl_1_data_3B45C__fzgx_offset_0, (u32)lbl_1_data_3B470__fzgx_offset_0,
    (u32)lbl_1_data_3B490__fzgx_offset_0, (u32)lbl_1_data_3B4AC__fzgx_offset_0, (u32)lbl_1_data_3B4C0__fzgx_offset_0, (u32)lbl_1_data_3B4D4__fzgx_offset_0, (u32)lbl_1_data_3B4E8__fzgx_offset_0, (u32)lbl_1_data_3B4FC__fzgx_offset_0, (u32)lbl_1_data_3B520__fzgx_offset_0, (u32)lbl_1_data_3B540__fzgx_offset_0,
    (u32)lbl_1_data_3B550__fzgx_offset_0, (u32)lbl_1_data_3B560__fzgx_offset_0, (u32)lbl_1_data_3B570__fzgx_offset_0, (u32)lbl_1_data_3B580__fzgx_offset_0, (u32)lbl_1_data_3B594__fzgx_offset_0, (u32)lbl_1_data_3B5C8__fzgx_offset_0, (u32)lbl_1_data_3B5DC__fzgx_offset_0, (u32)lbl_1_data_3B5F0__fzgx_offset_0,
    (u32)lbl_1_data_3B604__fzgx_offset_0, (u32)lbl_1_data_3B618__fzgx_offset_0, (u32)lbl_1_data_3B63C__fzgx_offset_0, (u32)lbl_1_data_3B64C__fzgx_offset_0, (u32)lbl_1_data_3B65C__fzgx_offset_0, (u32)lbl_1_data_3B66C__fzgx_offset_0, (u32)lbl_1_data_3B67C__fzgx_offset_0, (u32)lbl_1_data_3B68C__fzgx_offset_0,
    (u32)lbl_1_data_3B69C__fzgx_offset_0, (u32)lbl_1_data_3B6C8__fzgx_offset_0, (u32)lbl_1_data_3B6DC__fzgx_offset_0, (u32)lbl_1_data_3B6F0__fzgx_offset_0, (u32)lbl_1_data_3B704__fzgx_offset_0, (u32)lbl_1_data_3B718__fzgx_offset_0, 0x64, 0x4D454D4D,
    0x4F44455F, 0x53415645, 0x0, 0x4D454D4D, 0x4F44455F, 0x53415645, 0x5F534543, 0x544F5200,
    0x4D454D4D, 0x4F44455F, 0x4C4F4144, 0x0, 0x4D454D4D, 0x4F44455F, 0x4C495354, 0x0,
    0x4D454D4D, 0x4F44455F, 0x4C495354, 0x5F414E44, 0x5F4C4F41, 0x44000000, 0x4D454D4D, 0x4F44455F,
    0x44454C45, 0x54450000, 0x4D454D4D, 0x4F44455F, 0x43484543, 0x4B000000, (u32)lbl_1_data_3C1E8__fzgx_offset_0, (u32)lbl_1_data_3C1F8__fzgx_offset_0,
    (u32)lbl_1_data_3C20C__fzgx_offset_0, (u32)lbl_1_data_3C21C__fzgx_offset_0, (u32)lbl_1_data_3C22C__fzgx_offset_0, (u32)lbl_1_data_3C244__fzgx_offset_0, (u32)lbl_1_data_3C254__fzgx_offset_0, 0x0, 0x4D454D53, 0x55425F48,
    0x414C5400, 0x4D454D53, 0x55425F45, 0x52524F52, 0x0, 0x4D454D53, 0x55425F4E, 0x4F534156,
    0x455F4558, 0x49540000, 0x4D454D53, 0x55425F4D, 0x4F554E54, 0x0, 0x4D454D53, 0x55425F43,
    0x4845434B, 0x0, 0x4D454D53, 0x55425F46, 0x4F524D41, 0x545F5155, 0x45525900, 0x4D454D53,
    0x55425F46, 0x4F524D41, 0x54000000, 0x4D454D53, 0x55425F47, 0x45545F53, 0x45524941, 0x4C000000,
    0x4D454D53, 0x55425F44, 0x454C4554, 0x455F544D, 0x50000000, 0x4D454D53, 0x55425F43, 0x4845434B,
    0x5F465245, 0x45000000, 0x4D454D53, 0x55425F43, 0x4845434B, 0x5F455849, 0x53540000, 0x4D454D53,
    0x55425F4F, 0x56455257, 0x52495445, 0x5F515545, 0x52590000, 0x4D454D53, 0x55425F44, 0x454C4554,
    0x455F4649, 0x4C450000, 0x4D454D53, 0x55425F43, 0x52454154, 0x455F544D, 0x50000000, 0x4D454D53,
    0x55425F47, 0x45545F53, 0x54415400, 0x4D454D53, 0x55425F53, 0x4156455F, 0x544D5000, 0x4D454D53,
    0x55425F53, 0x45545F53, 0x54415400, 0x4D454D53, 0x55425F44, 0x454C4554, 0x455F4F4C, 0x44000000,
    0x4D454D53, 0x55425F52, 0x454E414D, 0x45000000, 0x4D454D53, 0x55425F43, 0x4845434B, 0x5F465245,
    0x455F4C41, 0x53540000, 0x4D454D53, 0x55425F53, 0x4156455F, 0x454E4400, 0x4D454D53, 0x55425F4E,
    0x4F4C4F41, 0x445F4558, 0x49540000, 0x4D454D53, 0x55425F46, 0x4F524D41, 0x545F454E, 0x44000000,
    0x4D454D53, 0x55425F4C, 0x4F41445F, 0x46494C45, 0x0, 0x4D454D53, 0x55425F4C, 0x4F41445F,
    0x454E4400, 0x4D454D53, 0x55425F47, 0x45545F4C, 0x49535400, 0x4D454D53, 0x55425F4C, 0x4953545F,
    0x454E4400, 0x4D454D53, 0x55425F4E, 0x4F4C4953, 0x545F4558, 0x49540000, 0x4D454D53, 0x55425F44,
    0x454C4554, 0x455F4E41, 0x4D450000, 0x4D454D53, 0x55425F44, 0x454C4554, 0x455F454E, 0x44000000,
    0x4D454D53, 0x55425F4E, 0x4F44454C, 0x5F455849, 0x54000000, 0x4D454D53, 0x55425F4E, 0x4F46494C,
    0x455F4348, 0x45434B46, 0x52454500, 0x4D454D53, 0x55425F4E, 0x4F4C4F41, 0x445F4558, 0x49545F4E,
    0x4F4D5347, 0x0, 0x4D454D53, 0x55425F47, 0x45545F4C, 0x4953545F, 0x4D494444, 0x4C450000,
    0x4D454D53, 0x55425F43, 0x4845434B, 0x5F454E44, 0x0, 0x4D454D53, 0x55425F47, 0x45545F4C,
    0x4953545F, 0x4E4F4241, 0x52000000, 0x4D454D53, 0x55425F53, 0x4156455F, 0x53454354, 0x4F525F54,
    0x4D500000, 0x4D454D53, 0x55425F53, 0x4156455F, 0x48454144, 0x45525F54, 0x4D500000, 0x4D454D53,
    0x55425F45, 0x4E434F44, 0x494E4700, 0x4D454D53, 0x55425F41, 0x54545249, 0x42555445, 0x0,
    (u32)lbl_1_data_3C284__fzgx_offset_0, (u32)lbl_1_data_3C290__fzgx_offset_0, (u32)lbl_1_data_3C2A0__fzgx_offset_0, (u32)lbl_1_data_3C2B4__fzgx_offset_0, (u32)lbl_1_data_3C2C4__fzgx_offset_0, (u32)lbl_1_data_3C2D4__fzgx_offset_0, (u32)lbl_1_data_3C2E8__fzgx_offset_0, (u32)lbl_1_data_3C2F8__fzgx_offset_0,
    (u32)lbl_1_data_3C30C__fzgx_offset_0, (u32)lbl_1_data_3C320__fzgx_offset_0, (u32)lbl_1_data_3C334__fzgx_offset_0, (u32)lbl_1_data_3C348__fzgx_offset_0, (u32)lbl_1_data_3C360__fzgx_offset_0, (u32)lbl_1_data_3C374__fzgx_offset_0, (u32)lbl_1_data_3C388__fzgx_offset_0, (u32)lbl_1_data_3C398__fzgx_offset_0,
    (u32)lbl_1_data_3C3A8__fzgx_offset_0, (u32)lbl_1_data_3C3B8__fzgx_offset_0, (u32)lbl_1_data_3C3CC__fzgx_offset_0, (u32)lbl_1_data_3C3DC__fzgx_offset_0, (u32)lbl_1_data_3C3F4__fzgx_offset_0, (u32)lbl_1_data_3C404__fzgx_offset_0, (u32)lbl_1_data_3C418__fzgx_offset_0, (u32)lbl_1_data_3C42C__fzgx_offset_0,
    (u32)lbl_1_data_3C440__fzgx_offset_0, (u32)lbl_1_data_3C450__fzgx_offset_0, (u32)lbl_1_data_3C460__fzgx_offset_0, (u32)lbl_1_data_3C470__fzgx_offset_0, (u32)lbl_1_data_3C484__fzgx_offset_0, (u32)lbl_1_data_3C498__fzgx_offset_0, (u32)lbl_1_data_3C4AC__fzgx_offset_0, (u32)lbl_1_data_3C4C0__fzgx_offset_0,
    (u32)lbl_1_data_3C4D8__fzgx_offset_0, (u32)lbl_1_data_3C4F4__fzgx_offset_0, (u32)lbl_1_data_3C50C__fzgx_offset_0, (u32)lbl_1_data_3C520__fzgx_offset_0, (u32)lbl_1_data_3C538__fzgx_offset_0, (u32)lbl_1_data_3C550__fzgx_offset_0, (u32)lbl_1_data_3C568__fzgx_offset_0, (u32)lbl_1_data_3C578__fzgx_offset_0,
    0x0
};
static u32 fzgx_pool_data_lbl_1_data_35AC8_6B68[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_1_AD1E4__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_1_data_35AC8_6B6C[97] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_1_AEC34__fzgx_offset_0, (u32)fn_1_B03A8__fzgx_offset_0, (u32)fn_1_B1710__fzgx_offset_0, (u32)fn_1_B2770__fzgx_offset_0, (u32)fn_1_B38F4__fzgx_offset_0, (u32)fn_1_B40B4__fzgx_offset_0, 0x0, (u32)fn_1_AD264__fzgx_offset_0,
    (u32)fn_1_AECCC__fzgx_offset_0, (u32)fn_1_B03CC__fzgx_offset_0, (u32)fn_1_B171C__fzgx_offset_0, (u32)fn_1_B277C__fzgx_offset_0, (u32)fn_1_B3900__fzgx_offset_0, (u32)fn_1_B40C0__fzgx_offset_0, 0x0, (u32)fn_1_AAEB0__fzgx_offset_0,
    (u32)fn_1_AAF1C__fzgx_offset_0, (u32)fn_1_AB438__fzgx_offset_0, (u32)fn_1_AB478__fzgx_offset_0, (u32)fn_1_AB598__fzgx_offset_0, (u32)fn_1_AB61C__fzgx_offset_0, (u32)fn_1_AB75C__fzgx_offset_0, (u32)fn_1_AB870__fzgx_offset_0, (u32)fn_1_AB8D8__fzgx_offset_0,
    (u32)fn_1_AB98C__fzgx_offset_0, (u32)fn_1_ABA9C__fzgx_offset_0, (u32)fn_1_ABB24__fzgx_offset_0, (u32)fn_1_ABC5C__fzgx_offset_0, (u32)fn_1_ABCE8__fzgx_offset_0, (u32)fn_1_ABDA8__fzgx_offset_0, (u32)fn_1_ABE14__fzgx_offset_0, (u32)fn_1_AC294__fzgx_offset_0,
    (u32)fn_1_AC328__fzgx_offset_0, (u32)fn_1_AC3DC__fzgx_offset_0, (u32)fn_1_AC4B4__fzgx_offset_0, (u32)fn_1_AC53C__fzgx_offset_0, (u32)fn_1_AC6A8__fzgx_offset_0, (u32)fn_1_AC6E0__fzgx_offset_0, (u32)fn_1_AC704__fzgx_offset_0, (u32)fn_1_AC79C__fzgx_offset_0,
    (u32)fn_1_AC92C__fzgx_offset_0, (u32)fn_1_ACA78__fzgx_offset_0, (u32)fn_1_AC908__fzgx_offset_0, (u32)fn_1_ACE80__fzgx_offset_0, (u32)fn_1_ACF30__fzgx_offset_0, (u32)fn_1_ACF0C__fzgx_offset_0, (u32)fn_1_ABA14__fzgx_offset_0, (u32)fn_1_AC6CC__fzgx_offset_0,
    (u32)fn_1_AD09C__fzgx_offset_0, (u32)fn_1_ACD04__fzgx_offset_0, (u32)fn_1_ACA00__fzgx_offset_0, (u32)fn_1_ABF44__fzgx_offset_0, (u32)fn_1_AC12C__fzgx_offset_0, (u32)fn_1_AD140__fzgx_offset_0, (u32)fn_1_AD168__fzgx_offset_0, 0x0,
    (u32)fn_1_AAF18__fzgx_offset_0, (u32)fn_1_AB434__fzgx_offset_0, (u32)fn_1_AB458__fzgx_offset_0, (u32)fn_1_AB4F4__fzgx_offset_0, (u32)fn_1_AB5CC__fzgx_offset_0, (u32)fn_1_AB64C__fzgx_offset_0, (u32)fn_1_AB7C4__fzgx_offset_0, (u32)fn_1_AB880__fzgx_offset_0,
    (u32)fn_1_AB93C__fzgx_offset_0, (u32)fn_1_AB99C__fzgx_offset_0, (u32)fn_1_ABAAC__fzgx_offset_0, (u32)fn_1_ABB4C__fzgx_offset_0, (u32)fn_1_ABC98__fzgx_offset_0, (u32)fn_1_ABD58__fzgx_offset_0, (u32)fn_1_ABDB8__fzgx_offset_0, (u32)fn_1_ABE88__fzgx_offset_0,
    (u32)fn_1_AC2D8__fzgx_offset_0, (u32)fn_1_AC38C__fzgx_offset_0, (u32)fn_1_AC464__fzgx_offset_0, (u32)fn_1_AC4C4__fzgx_offset_0, (u32)fn_1_AC6A4__fzgx_offset_0, (u32)fn_1_AC6C8__fzgx_offset_0, (u32)fn_1_AC700__fzgx_offset_0, (u32)fn_1_AC74C__fzgx_offset_0,
    (u32)fn_1_AC904__fzgx_offset_0, (u32)fn_1_AC960__fzgx_offset_0, (u32)fn_1_ACD00__fzgx_offset_0, (u32)fn_1_AC928__fzgx_offset_0, (u32)fn_1_ACEBC__fzgx_offset_0, (u32)fn_1_AD098__fzgx_offset_0, (u32)fn_1_ACF2C__fzgx_offset_0, (u32)fn_1_ABA24__fzgx_offset_0,
    (u32)fn_1_AC6DC__fzgx_offset_0, (u32)fn_1_AD0A0__fzgx_offset_0, (u32)fn_1_ACE7C__fzgx_offset_0, (u32)fn_1_ACA1C__fzgx_offset_0, (u32)fn_1_AC000__fzgx_offset_0, (u32)fn_1_AC188__fzgx_offset_0, (u32)fn_1_AD164__fzgx_offset_0, (u32)fn_1_AD1AC__fzgx_offset_0,
    0x0
};
static u32 fzgx_pool_data_lbl_1_data_3C7B8[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6D656D63, 0x6172642E, 0x63000000
};
static u32 fzgx_pool_data_lbl_1_data_3C7C4[54] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2E646174, 0x0, 0x462D5A45, 0x524F2047, 0x58000000, 0x2E2F6D65, 0x6D636172, 0x642F0000,
    0x7379732E, 0x62696E00, 0x7379735F, 0x652E6269, 0x6E000000, 0x4456444F, 0x70656E3A, 0x2063616E,
    0x6E6F7420, 0x6F70656E, 0x2E0A0000, 0x61764456, 0x44526561, 0x643A2063, 0x616E6E6F, 0x74207265,
    0x61640000, 0x25316420, 0x57726F6E, 0x67205375, 0x626D6F64, 0x652E0A72, 0x6573756C, 0x743A2025,
    0x640A7375, 0x626D6F64, 0x653A2573, 0xA000000, 0x68616C74, 0x2E0A0000, 0x72657375, 0x6C743A20,
    0x25640A00, 0x57726F6E, 0x67206572, 0x726F7220, 0x6F636375, 0x7265642E, 0xA000000, 0x506C6561,
    0x7365206D, 0x616B6520, 0x63617074, 0x696F6E20, 0x6C697374, 0x2E0A0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_35AC8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_35AC8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_35ACC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_35AC8_6B68;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_35AC8_6B6C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3C7B8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3C7C4;
}
#pragma section code_type ".text"

void fn_1_AA6D8(u8 kind, u8 slot, DriverParam *param) {
    DriverEntry *entry;
    s32 has0;
    s32 has1;
    s32 v;

    
    
    if (param->unk_0 == 1) {
        slot = 0;
    }
    switch (slot) {
    case 0:
    case 1:
        entry = fzgx_obj_lbl_1_bss_716C8;
        fzgx_obj_lbl_1_bss_718B1 = slot;
        entry += slot;
        break;
    case 4:
        if (fzgx_obj_lbl_1_bss_718B1 == 0 || fzgx_obj_lbl_1_bss_718B1 == 1) {
            entry = fzgx_obj_lbl_1_bss_716C8;
            entry += fzgx_obj_lbl_1_bss_718B1;
            break;
        }
        {
            DriverEntry *pair = fzgx_obj_lbl_1_bss_716C8;
            has0 = pair[0].unk_1 != -3;
            has1 = pair[1].unk_1 != -3;
            if (has0 && !has1) {
                fzgx_obj_lbl_1_bss_718B1 = 0;
                entry = pair;
                break;
            }
        }
        if (has1 && !has0) {
            fzgx_obj_lbl_1_bss_718B1 = 1;
            entry = fzgx_obj_lbl_1_bss_716C8;
            entry += 1;
            break;
        }
        fzgx_obj_lbl_1_bss_718B1 = 0;
        /* fallthrough */
    case 2:
    use_extra:
        fzgx_pool_lbl_1_bss_716C0_gap_718B2 = 2;
        entry = &lbl_1_bss_71810;
        break;
    case 3:
        if (fzgx_obj_lbl_1_bss_718B1 == 0 || fzgx_obj_lbl_1_bss_718B1 == 1) {
            entry = fzgx_obj_lbl_1_bss_716C8;
            entry += fzgx_obj_lbl_1_bss_718B1;
            break;
        }
        goto use_extra; /* fzgx-allow: S1 case 3 shares case 2's tail; retail jumps into it rather than duplicating the block */
    }

    entry->unk_24 = fn_1_4630(lbl_801A6410, 0xF0, (char *)((u8 *)fzgx_pool_data_lbl_1_data_3C7B8), 0x33C);
    if (param->unk_0 == 0) {
        param->unk_4 = 4;
    }
    entry->unk_24->unk_8 = param->unk_4;
    entry->unk_24->unk_0 = param->unk_0;
    entry->unk_24->unk_8C = &lbl_1_rodata_4AE0[param->unk_0];
    {
        DriverObj *obj = entry->unk_24;
        v = obj->unk_8C->unk_44;
        if (v == -1) {
            obj->unk_E0 = 0;
        } else {
            obj->unk_E0 = v;
        }
    }
    entry->unk_2 = kind;
    lbl_1_bss_718B8 = 0;
    lbl_1_bss_718B9 = 0;
    lbl_1_bss_772C8[0] = 0;

    if (kind == 6) {
        s32 i;
        entry->unk_24->unk_8 |= 0x20;
        entry->unk_24->unk_94 = param->unk_C;
        for (i = 0; i < 0x7F; i++) {
            DriverSub *sub = &entry->unk_24->unk_94[i];
            if (sub->unk_0 != 0) {
                sub->unk_8 = &lbl_1_rodata_4AE0[sub->unk_4];
                sub->unk_2C = 0;
            }
        }
    } else if (kind == 3 || kind == 4) {
        entry->unk_24->unk_8 |= 0x20;
        entry->unk_24->unk_E8 = param->unk_20;
        entry->unk_24->unk_94 = param->unk_C;
        fzgx_obj_lbl_1_bss_716C0 = 0;
    } else if (kind == 5) {
        entry->unk_24->unk_8 |= 0x20;
        fn_80083DB0(entry->unk_24->unk_98, (char *)entry->unk_24->unk_8C);
        fn_80083CF4(entry->unk_24->unk_98, param->unk_14, 0x1F - strlen(entry->unk_24->unk_98));
        strcat(entry->unk_24->unk_98, (char *)((u8 *)fzgx_pool_data_lbl_1_data_3C7C4));
    } else {
        DriverObj *obj = entry->unk_24;
        u32 size = obj->unk_8C->unk_40;
        if (size == 0) {
            obj->unk_8 |= 0x20;
            entry->unk_24->unk_B8 = param->unk_10;
            entry->unk_24->unk_C = (param->unk_10 + 0x405F) & ~0x1FFF;
            entry->unk_24->unk_E4 = entry->unk_24->unk_C;
            fn_80083DB0(entry->unk_24->unk_98, (char *)entry->unk_24->unk_8C);
            fn_80083CF4(entry->unk_24->unk_98, param->unk_14, 0x1F - strlen(entry->unk_24->unk_98));
            if (kind == 0) {
                fn_80083DB0(lbl_1_bss_772C8, entry->unk_24->unk_98);
            }
            if (entry->unk_24->unk_8 & 0x1000) {
                fn_80083DB0(entry->unk_24->unk_BC, (char *)entry->unk_24->unk_8C);
                fn_80083CF4(entry->unk_24->unk_BC, param->unk_18, 0x1F - strlen(entry->unk_24->unk_BC));
            }
            entry->unk_24->unk_94 = param->unk_C;
        } else {
            obj->unk_B8 = size;
            entry->unk_24->unk_C = (entry->unk_24->unk_8C->unk_40 + 0x405F) & ~0x1FFF;
            if (entry->unk_24->unk_8C->unk_44 != -1) {
                entry->unk_24->unk_E4 = entry->unk_24->unk_8C->unk_48;
            } else {
                entry->unk_24->unk_E4 = entry->unk_24->unk_C;
            }
            fn_80083DB0(entry->unk_24->unk_98, (char *)entry->unk_24->unk_8C);
            if (kind == 0) {
                fn_80083DB0(lbl_1_bss_772C8, entry->unk_24->unk_98);
            }
            entry->unk_24->unk_94 = fn_1_45D0(lbl_801A6410, entry->unk_24->unk_C, (char *)((u8 *)fzgx_pool_data_lbl_1_data_3C7B8), 0x3A8);
            fn_80008BEC(entry->unk_24->unk_94, 0, entry->unk_24->unk_C);
        }
    }

    ((DriverFunc *)(((u8 *)fzgx_pool_data_lbl_1_data_35AC8_6B68)))[kind](param, entry);
}
/* fzgx:end fn_1_AA6D8 */

/* fzgx:begin fn_1_AAB98 */
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


typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    s32 unk_4;
    u32 unk_8;
} fn_1_AAB98_Obj;

typedef struct {
    u8 pad_0[2];
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    s16 unk_8;
    s16 unk_A;
    u8 pad_C[0x18];
    fn_1_AAB98_Obj *unk_24;
    s8 unk_28;
    u8 pad_29;
    u8 unk_2A;
    u8 pad_2B[5];
    s32 unk_30;
    f32 unk_34;
    f32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    u8 pad_44[0x5C];
} fn_1_AAB98_Entry;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_716C0[8];
fn_1_AAB98_Entry fzgx_obj_lbl_1_bss_716C8[2];
u8 lbl_1_bss_71808__fzgx_offset_0[4];
u8 lbl_1_bss_7180C__fzgx_offset_0[4];
fn_1_AAB98_Entry lbl_1_bss_71810;
u8 lbl_1_bss_71810__fzgx_offset_A0;
u8 lbl_1_bss_718B1;
u8 lbl_1_bss_718B2;
u8 fzgx_pool_lbl_1_bss_718B3;
u8 fzgx_pool_lbl_1_bss_718B4_fill[0x5C48 - 0x1F4];
u8 lbl_1_bss_772C8__fzgx_offset_40;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C8;
    s = *(u8 *)&lbl_1_bss_71808__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7180C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_71810;
    s = *(u8 *)&lbl_1_bss_71810__fzgx_offset_A0;
    s = *(u8 *)&lbl_1_bss_718B1;
    s = *(u8 *)&lbl_1_bss_718B2;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_718B3;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_718B4_fill;
    s = *(u8 *)&lbl_1_bss_772C8__fzgx_offset_40;
}
#pragma section code_type ".text"

extern const f32 lbl_1_rodata_4CA8;
extern void fn_1_A2DC4(u32);

static inline int fn_1_AAB98_isActive(fn_1_AAB98_Entry *e) {
    if (e->unk_24->unk_0 == 1) {
        return 1;
    }
    return 0;
}

static inline int fn_1_AAB98_confirm(void) {
    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        fn_1_A2DC4(0xA9011100);
        return 1;
    }
    return 0;
}

static inline void fn_1_AAB98_setTone(fn_1_AAB98_Entry *e) {
    switch (e->unk_2) {
    case 2:
        e->unk_3 = 0x20;
        break;
    case 0:
    case 1:
        e->unk_3 = 2;
        break;
    case 3:
    case 4:
        e->unk_3 = 0x1B;
        break;
    case 5:
        e->unk_3 = 0x1E;
        break;
    }
}

static inline int fn_1_AAB98_tick(fn_1_AAB98_Entry *e) {
    if (!(e->unk_2A & 1)) {
        e->unk_28 = 12;
        e->unk_2A |= 1;
        return 0;
    }
    if (e->unk_28 > 0) {
        e->unk_28--;
        return 0;
    }
    return 1;
}

static inline void fn_1_AAB98_clear(fn_1_AAB98_Entry *e) {
    e->unk_4 = 0xFF;
    e->unk_5 = 0xFF;
    e->unk_6 = 0xFF;
    e->unk_7 = 0;
    e->unk_8 = -1;
    e->unk_A = -1;
    e->unk_30 = 0;
    e->unk_34 = lbl_1_rodata_4CA8;
    e->unk_38 = lbl_1_rodata_4CA8;
    e->unk_2A &= ~4;
    e->unk_3C = -1;
    e->unk_40 = -1;
}

static inline void fn_1_AAB98_commit(void) {
    fn_1_AAB98_Entry *e = &fzgx_obj_lbl_1_bss_716C8[lbl_1_bss_718B2];
    fn_1_AAB98_Entry *cur = &lbl_1_bss_71810;

    e->unk_2 = cur->unk_2;
    e->unk_3 = cur->unk_3;
    e->unk_4 = 0xFF;
    e->unk_5 = 0xFF;
    e->unk_6 = 0xFF;
    e->unk_7 = 0;
    lbl_1_bss_718B1 = lbl_1_bss_718B2;
    e->unk_24 = cur->unk_24;
    if (lbl_1_bss_772C8__fzgx_offset_40 == 2) {
        e->unk_2A |= 4;
        if (e->unk_24 != NULL) {
            e->unk_24->unk_8 &= ~4;
            e->unk_24->unk_4 = -120;
        }
    }
    cur->unk_24->unk_8 &= ~2;
    cur->unk_24 = NULL;
    cur->unk_2 = 0xFF;
    cur->unk_3 = 0xFF;
    fn_1_AAB98_clear(&lbl_1_bss_71810);
    lbl_1_bss_718B2 = 0xFF;
}

static inline fn_1_AAB98_Entry *fn_1_AAB98_array_read(fn_1_AAB98_Entry *array) { return array; }
#pragma opt_common_subs off
void fn_1_AAB98(void) {
    u8 idx;
    int active;
    Obj_1_bss_9F8 *input;

    idx = lbl_1_bss_718B1;
    active = 0;
    if (idx == 0 && fzgx_obj_lbl_1_bss_716C8[0].unk_24 != NULL) {
        if (fn_1_AAB98_array_read(fzgx_obj_lbl_1_bss_716C8)[0].unk_24->unk_0 == 1) {
            active = 1;
        } else {
            active = 0;
        }
    }

    if (idx == 0 && active) {
        lbl_1_bss_772C8__fzgx_offset_40 = 1;
        lbl_1_bss_718B2 = 0;
    } else if (lbl_1_bss_772C8__fzgx_offset_40 == 0) {
        input = &lbl_1_bss_9F8;
        if (((input->unk_10 & 1) || (input->unk_12 & 1)) && lbl_1_bss_718B2 == 1) {
            fn_1_A2DC4(0xA9011300);
            lbl_1_bss_718B2 = 0;
        } else if ((((input->unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) &&
                   lbl_1_bss_718B2 == 0) {
            fn_1_A2DC4(0xA9011300);
            lbl_1_bss_718B2 = 1;
        }
        lbl_1_bss_772C8__fzgx_offset_40 = fn_1_AAB98_confirm();
    }

    switch (lbl_1_bss_772C8__fzgx_offset_40) {
    case 2:
        fn_1_AAB98_setTone(&lbl_1_bss_71810);
        lbl_1_bss_718B2 = 0;
        /* fallthrough */
    case 1:
        if (lbl_1_bss_772C8__fzgx_offset_40 == 1 && !fn_1_AAB98_tick(&lbl_1_bss_71810)) {
            break;
        }
        fn_1_AAB98_commit();
        break;
    case 0:
    default:
        break;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_AAB98 */

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
