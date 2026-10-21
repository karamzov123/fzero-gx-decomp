#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern void fn_1_E4A38(void *base, s32 x, s32 y, void *arg);
extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern u32 fn_80083970(const u8* left, const char* right);
extern u32 strlen(const char* string);
extern void fn_1_8CED0(void* object, s32 value0, s32 value1);
extern void fn_1_8D0A4(void* object);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, s32);
extern void fn_800745A4(u32, s32, s32, u32, s32, s32);
extern void fn_80073778(void *, u32);
extern void fn_80015C1C(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void lbl_8006DFFC(void *, void *, void *);
extern void GXLoadTexMtxImm(void *, u32, s32);
extern f32 lbl_1_rodata_6780[236];
extern f32 fn_1_A6FE8(void);
extern void fn_1_E8938(void);
extern void fn_1_8D1C8(void *object, void (*callback)(void), int arg);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32 value);
extern u32 lbl_1_bss_7C94C[67];
extern void fn_1_EE530(void);
extern u8 lbl_1_bss_7ECB4[72];
extern void fn_1_BC29C(u8 *);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);

extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);

extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
extern void fn_1_9C724(void);
extern void fn_1_DD890(void *);
extern void fn_1_9CC40(void);

/* fzgx:begin fn_1_E1C10 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

typedef struct {
    u8 pad_0[0x8];
    s16 unk_8;
    s16 unk_A;
    u8 pad_C[0x19C];
} Elem1A8;

typedef struct {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x2];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0x2];
    u32 unk_10;
    s16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    s16 unk_1C;
    u8 pad_1E[0x2];
    u32 unk_20;
    s16 unk_24;
    u8 pad_26[0x2];
    u32 unk_28;
    s16 unk_2C;
    u8 pad_2E[0x2];
} State7AE88;

extern State7AE88 lbl_1_bss_7AE88;
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern u32 lbl_801A6410;
extern u8 lbl_1_data_3DDB4[];

#pragma opt_common_subs off
void fn_1_E1C10(void) {
    s16 fzgx_value_;
    s16 kind;
    struct { s16 value; } i;
    s16 count;
    struct { Elem1A8 * value; } cursor;
    Elem1A8 *ptr;
    State7AE88 *base;
    s16 *fzgx_value;

    base = &lbl_1_bss_7AE88;

    count = base->unk_4;
    ptr = (Elem1A8 *)base->unk_0;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 0;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_0 = (u32)ptr;

    count = base->unk_C;
    ptr = (Elem1A8 *)base->unk_8;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 1;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            fzgx_value_ = i.value;
            cursor.value->unk_8 = fzgx_value_;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_8 = (u32)ptr;

    count = base->unk_14;
    ptr = (Elem1A8 *)base->unk_10;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 2;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_10 = (u32)ptr;

    count = base->unk_1C;
    ptr = (Elem1A8 *)base->unk_18;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 3;
        while (i.value < count) {
            fzgx_value = &(cursor.value->unk_A);
            *fzgx_value = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_18 = (u32)ptr;

    count = base->unk_24;
    ptr = (Elem1A8 *)base->unk_20;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 4;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_20 = (u32)ptr;

    count = base->unk_2C;
    ptr = (Elem1A8 *)base->unk_28;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 5;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_28 = (u32)ptr;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_E1C10 */

/* fzgx:begin fn_1_E2AE8 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad_00[0x54];
    Vec3 v_54;
    Vec3 v_60;
    u8 pad_6c[0x18];
    f32 f_84;
    u8 pad_88[0x18];
    Vec3 v_a0;
    u32 u_ac;
    u32 u_b0;
    u32 u_b4;
    u32 u_b8;
    u8 pad_bc[0x44];
    s32 s_100;
    s32 s_104;
    s32 s_108;
    s32 s_10c;
    u8 pad_110[0xC];
    Vec3 v_11c;
    Vec3 v_128;
    u8 pad_134[4];
    u64 flags;
    u32 u_140;
    u8 pad_144[0x64];
} Obj;

typedef struct {
    s16 a[80];
} Arr80;

typedef struct {
    f32 f0;
    u8 pad_04[0x30];
    f32 f34;
    u8 pad_38[0x108];
    Vec3 pv;
    Arr80 pa;
} PoolType;

extern PoolType lbl_1_rodata_6780;
extern s16 fn_1_E5430(s16);
extern Obj *fn_1_E54A8(s16, s16);
extern u8 *fn_1_14F04(void);
extern u32 fn_1_20A5C(void *, void *);
extern void fn_1_17920(u32, u32, f32);
extern s16 fn_1_7B054(void);
extern void fn_80008BA8(void *, void *, u32);
extern f32 lbl_8006D668(void *);

static inline f32 fn_1_E2AE8_read_pointer(PoolType * owner) { return owner->f0; }
#pragma opt_dead_assignments off
static inline void fn_1_E2AE8_call_fn_1_17920(u32 a0, u32 a1, f32 a2) { fn_1_17920(a0, a1, a2); }
void fn_1_E2AE8(void) {
    PoolType *pool;
    s16 n;
    Obj *obj;
    Arr80 arr;
    s16 j;
    u8 *str;
    Obj *list;
    s16 i;
    Vec3 lv;
    s16 *p;
    s16 k;
    Vec3 vtmp;
    f32 ftmp;
    s32 a;
    s32 b;
    s32 c;

    pool = (PoolType *)&lbl_1_rodata_6780;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        list = (Obj *)fn_1_E54A8(i, 0);
        str = (u8 *)fn_1_14F04() + 0x45c;
        obj = list;
        for (j = 0; j < n; ) {
            a = fn_1_20A5C(&obj->v_54.x, &ftmp);
            obj->s_100 = a;
            obj->u_ac = a;
            b = obj->u_ac;
            obj->u_b8 = b;
            obj->u_b4 = b;
            obj->u_b0 = b;
            c = obj->s_100;
            obj->s_10c = c;
            obj->s_108 = c;
            obj->s_104 = c;
            if ((obj->flags & 0x10000ULL) != 0) {
                fn_1_E2AE8_call_fn_1_17920(obj->s_100, 0, ftmp);
                fn_80008BA8(&obj->v_128.x, str, 12);
                lbl_8006D668(&obj->v_128.x);
                fn_80008BA8(&obj->v_a0.x, &obj->v_128.x, 12);
            }
            j++;
            obj = (Obj *)((u8 *)obj + 0x1a8);
        }
        if (i == 0 && fn_1_7B054() == 6) {
            lv = pool->pv;
            arr = pool->pa;
            obj = list;
            p = arr.a;
            for (k = 0; k < n; k++) {
                obj->s_100 = *p;
                c = obj->s_100;
                obj->s_10c = c;
                obj->s_108 = c;
                obj->s_104 = c;
                if (obj->s_100 > 0x50 && obj->s_100 < 0xc8) {
                    psvec_scale(&lv.x, fn_1_E2AE8_read_pointer(pool), &obj->v_128.x);
                    obj->u_140 = 1;
                } else {
                    fn_80008BA8(&obj->v_128.x, &lv.x, 12);
                    obj->u_140 = 2;
                }
                obj = (Obj *)((u8 *)obj + 0x1a8);
                p++;
            }
        }
        obj = list;
        for (j = 0; j < n; j++) {
            if ((obj->flags & 8ULL) == 0) {
                psvec_scale(&obj->v_128.x, pool->f34 * obj->f_84, &vtmp.x);
                psvec_add(&obj->v_54.x, &vtmp.x, &obj->v_54.x);
                psvec_add(&obj->v_60.x, &vtmp.x, &obj->v_60.x);
            }
            fn_80008BA8(&obj->v_11c.x, &obj->v_128.x, 12);
            obj = (Obj *)((u8 *)obj + 0x1a8);
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_E2AE8 */

/* fzgx:begin fn_1_E35F0 noprologue */
#include "types.h"

typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct fn_1_E35F0_lbl_1_bss_7AE88 {
    u32 unk_0;
    u16 unk_4;
    u8 pad_6[0x2];
    u32 unk_8;
    u16 unk_C;
    u8 pad_E[0x2];
    u32 unk_10;
    u16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u16 unk_1C;
    u8 pad_1E[0x2];
    u32 unk_20;
    u16 unk_24;
    u8 pad_26[0x2];
    u32 unk_28;
    u16 unk_2C;
    u8 pad_2E[0x2];
    u32 unk_30;
};
struct fn_1_E35F0_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_1_E35F0_lbl_801A6410 lbl_801A6410;
extern u32 lbl_1_data_3DDB4;
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_7AE88;
u16 lbl_1_bss_7AE88__fzgx_offset_4;
u16 lbl_1_bss_7AE88__fzgx_offset_6;
u32 lbl_1_bss_7AE88__fzgx_offset_8;
u16 lbl_1_bss_7AE88__fzgx_offset_C;
u16 lbl_1_bss_7AE88__fzgx_offset_E;
u32 lbl_1_bss_7AE88__fzgx_offset_10;
u16 lbl_1_bss_7AE88__fzgx_offset_14;
u16 lbl_1_bss_7AE88__fzgx_offset_16;
u32 lbl_1_bss_7AE88__fzgx_offset_18;
u16 lbl_1_bss_7AE88__fzgx_offset_1C;
u16 lbl_1_bss_7AE88__fzgx_offset_1E;
u32 lbl_1_bss_7AE88__fzgx_offset_20;
u16 lbl_1_bss_7AE88__fzgx_offset_24;
u16 lbl_1_bss_7AE88__fzgx_offset_26;
u32 lbl_1_bss_7AE88__fzgx_offset_28;
u16 lbl_1_bss_7AE88__fzgx_offset_2C;
u16 lbl_1_bss_7AE88__fzgx_offset_2E;
u32 lbl_1_bss_7AEB8;
u32 lbl_1_bss_7AEB8__fzgx_offset_4[164];
u32 lbl_1_bss_7B14C[13];
u32 lbl_1_bss_7B180[2];
u32 lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_26;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2E;
    s = *(u8 *)&lbl_1_bss_7AEB8;
    s = *(u8 *)&lbl_1_bss_7AEB8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
}
#pragma section code_type ".text"

void fn_1_E35F0(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    
    if ((lbl_1_bss_7AEB8 & ~0x7FFFFFFF) != 0) {
    fn_1_8D168((Sig_fn_1_8D168_Fn1_8D168State *)((u32 *)&lbl_1_bss_7AEB8 + 132));
    lbl_1_bss_7AEB8 = (lbl_1_bss_7AEB8 & 0x7FFFFFFF);
    }
    v0 = lbl_1_bss_7AE88;
    if (v0 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)&lbl_1_data_3DDB4, 2647);
    lbl_1_bss_7AE88 = 0;
    lbl_1_bss_7AE88__fzgx_offset_4 = 0;
    }
    v1 = lbl_1_bss_7AE88__fzgx_offset_8;
    if (v1 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v1, (const char *)&lbl_1_data_3DDB4, 2648);
    lbl_1_bss_7AE88__fzgx_offset_8 = 0;
    lbl_1_bss_7AE88__fzgx_offset_C = 0;
    }
    v2 = lbl_1_bss_7AE88__fzgx_offset_10;
    if (v2 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v2, (const char *)&lbl_1_data_3DDB4, 2649);
    lbl_1_bss_7AE88__fzgx_offset_10 = 0;
    lbl_1_bss_7AE88__fzgx_offset_14 = 0;
    }
    v3 = lbl_1_bss_7AE88__fzgx_offset_18;
    if (v3 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v3, (const char *)&lbl_1_data_3DDB4, 2650);
    lbl_1_bss_7AE88__fzgx_offset_18 = 0;
    lbl_1_bss_7AE88__fzgx_offset_1C = 0;
    }
    v4 = lbl_1_bss_7AE88__fzgx_offset_20;
    if (v4 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v4, (const char *)&lbl_1_data_3DDB4, 2651);
    lbl_1_bss_7AE88__fzgx_offset_20 = 0;
    lbl_1_bss_7AE88__fzgx_offset_24 = 0;
    }
    v5 = lbl_1_bss_7AE88__fzgx_offset_28;
    if (v5 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v5, (const char *)&lbl_1_data_3DDB4, 2652);
    lbl_1_bss_7AE88__fzgx_offset_28 = 0;
    lbl_1_bss_7AE88__fzgx_offset_2C = 0;
    }
}
/* fzgx:end fn_1_E35F0 */

/* fzgx:begin fn_1_E38D4 */
extern s16 fn_1_E5430(s16);
extern void *fn_1_E54A8(s16, s16);

typedef struct {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[0x2];
    s16 unk_E;
    u8 pad_10[0x128];
    u64 flags_138;
    u8 pad_140[0x68];
} PhysEntry;

void fn_1_E38D4(void) {
    PhysEntry *entry;
    s16 group;
    s16 count;
    s16 i;

    fn_1_9C724();
    for (group = 0; group < 6; group++) {
        count = fn_1_E5430(group);
        entry = (PhysEntry *)fn_1_E54A8(group, 0);
        if (entry != 0 && entry->unk_A == 4 &&
            (entry->flags_138 & 0x80000000000ULL) == 0) {
            fn_80077E0C(*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)lbl_1_bss_3BE0->unk_54 +
                (entry->unk_E << 6) + 8) + 8) + 8));
            fn_80076134();
        }
        for (i = 0; i < count; i++, entry++) {
            if ((entry->flags_138 & 0x80000000000ULL) == 0) {
                fn_1_DD890(entry);
            }
        }
    }
    fn_1_9CC40();
}
/* fzgx:end fn_1_E38D4 */

/* fzgx:begin fn_1_E39F0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
    s = 0.0f;
    d = 1.1920928955078125e-07;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = -1.0099999904632568f;
    s = 9.999999747378752e-05f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9900000095367432f;
    s = 2.0f;
    s = -0.0f;
    d = 216.0;
    d = 3.1415927410125732;
    d = 4.0;
    d = 60.0;
    s = 1.0099999904632568f;
    s = 0.05000000074505806f;
    s = 1.0010000467300415f;
    s = 0.8999999761581421f;
    s = 3.0f;
}
static const u32 fzgx_pool_table12[6] = {0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 0.0016666667070239782f;
    s = 0.30000001192092896f;
    s = 0.01666666753590107f;
    s = 10000000.0f;
    s = 5000000.0f;
    s = 100.0f;
}
static const u32 fzgx_pool_table14[43] = {0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.01745329238474369f;
    s = -3.0f;
}
static const u32 fzgx_pool_table16[8] = {0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 224.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 255.0f;
    s = 640.0f;
    s = 480.0f;
    s = 1.2705882787704468f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct LocalStruct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u8 pad_3C[0x1C];
} LocalStruct;

typedef struct RoData_6780 {
    u8 pad_0[0x34];
    f32 unk_34;
    u8 pad_38[0x8];
    f64 unk_40;
    u8 pad_48[0x1CC];
    f32 unk_214;
    u8 pad_218[0x4];
    u32 unk_21C;
    f32 unk_220;
    f32 unk_224;
    f32 unk_228;
    f32 unk_22C;
    f32 unk_230;
} RoData_6780;

typedef struct Node_80077E0C {
    u8 pad[8];
    struct Node_80077E0C *child;
} Node_80077E0C;

typedef struct Elem_3BE0 {
    u8 pad[8];
    Node_80077E0C *node;
    u8 pad2[0x40 - 12];
} Elem_3BE0;

typedef struct Obj_1A8 {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[2];
    s16 unk_E;
    u8 pad_10[0x128];
    u64 unk_138;
    u8 pad_140[0x1A8 - 0x140];
} Obj_1A8;

extern const LocalStruct lbl_1_rodata_26F8;
extern s8 fn_1_A5DC4(void);
extern void fn_1_4E92C(LocalStruct *, u32, u16, u16, u32);
extern void fn_1_9C724(void);
extern s16 fn_1_E5430(s16);
extern Obj_1A8 *fn_1_E54A8(s16, s32);
extern void fn_1_DD890(Obj_1A8 *);
extern void fn_1_9CC40(void);
extern void fn_80077E0C(void *);
extern void fn_80076134(void);

void fn_1_E39F0(void) {

    if (lbl_1_bss_7AEB8.unk_0 & (1U << 31)) {
        LocalStruct sp8 = lbl_1_rodata_26F8;
        sp8.unk_4 = (320.0f);
        sp8.unk_8 = (240.0f);
        sp8.unk_C = (255.0f);
        sp8.unk_10 *= ((640.0f) / (f32)lbl_1_bss_7AEB8.unk_240);
        sp8.unk_14 *= ((480.0f) / (f32)lbl_1_bss_7AEB8.unk_242);
        if (fn_1_A5DC4()) {
            sp8.unk_10 *= (1.27058828f);
            sp8.unk_14 *= (1.27058828f);
        }
        sp8.unk_38 = fzgx_pool_table18[0];
        sp8.unk_2C = (0.5f);
        sp8.unk_30 = 10;
        fn_1_4E92C(&sp8, lbl_1_bss_7AEB8.unk_244,
                   lbl_1_bss_7AEB8.unk_240, lbl_1_bss_7AEB8.unk_242,
                   lbl_1_bss_7AEB8.unk_270);
    }

    fn_1_9C724();
    {
        s16 i;
        for (i = 0; i < 6; i++) {
            s16 count = fn_1_E5430(i);
            Obj_1A8 *obj = fn_1_E54A8(i, 0);
            if (obj != NULL && obj->unk_A == 4 &&
                (obj->unk_138 & (0x800ULL << 32))) {
                Elem_3BE0 *arr = (Elem_3BE0 *)lbl_1_bss_3BE0->unk_54;
                fn_80077E0C(arr[obj->unk_E].node->child->child);
                fn_80076134();
            }
            obj = fn_1_E54A8(i, 0);
            {
                s16 j;
                for (j = 0; j < count; j++, obj++) {
                    if (obj->unk_138 & (0x800ULL << 32)) {
                        fn_1_DD890(obj);
                    }
                }
            }
        }
    }
    fn_1_9CC40();
}
/* fzgx:end fn_1_E39F0 */

/* fzgx:begin fn_1_E49D4 */
extern u32 fn_1_E3C38(u32, u32);
extern u32 fn_1_E5430(u32);
extern u32 fn_1_E54A8(u32, u32);

void fn_1_E49D4(void) {
    s32 v0;
    u32 t0, t1;
    v0 = 0;
    while ((s16)v0 < 6) {
    fn_1_E3C38((fn_1_E54A8(v0, 0)), (fn_1_E5430(v0)));
    v0++;
    }
}
/* fzgx:end fn_1_E49D4 */

/* fzgx:begin fn_1_E4A38 noprologue */
#include "types.h"

typedef struct {
    u8 unk0[0x100];
    s32 value;
} Sig_fn_1_E573C_E573CObj;

struct D {
    u8 pad0[0x30];
    u32 unk_30[1];
    u8 pad1[0x1b0 - 0x34];
    u8 s1b0[8];
    u8 s1b8[8];
    u8 s1c0[4];
    u8 s1c4[0xc];
    u8 s1d0[0x10];
    u8 s1e0[0x10];
    u8 s1f0[0x10];
    u8 s200[0x10];
    u8 s210[0x10];
    u8 s220[8];
    u8 s228[8];
    u8 s230[8];
    u8 s238[8];
    u8 s240[8];
    u8 s248[0x10];
    u8 s258[8];
    u8 s260[8];
    u8 s268[8];
    u8 s270[0x10];
    u8 s280[8];
    u8 s288[0xc];
    u8 s294[8];
    u8 s29c[8];
    u8 s2a4[8];
    u8 s2ac[8];
    u8 s2b4[0xc];
    u8 s2c0[8];
    u8 s2c8[4];
    u8 s2cc[4];
};

typedef void (*Cb)(void *, ...);

extern char * strcat(char *, const char *);
extern f32 lbl_1_rodata_6808;
extern f32 lbl_1_rodata_69CC;
extern f64 lbl_1_rodata_6800;
extern s16 fn_1_E5724(void *);
extern s16 fn_1_E572C(void *);
extern s16 fn_1_E573C(Sig_fn_1_E573C_E573CObj *);
extern struct D lbl_1_data_3DC98;
extern u32 fn_1_E57C4(void *);
extern void * fn_1_E5748(void *);
extern void * fn_1_E5750(void *);
extern f32 fn_1_E5758(void *);
extern void * fn_1_E5760(void *);
extern void * fn_1_E5768(void *);
extern f32 fn_1_E57A4(void *);
extern f32 fn_1_E57AC(void *);
extern f32 fn_1_E57B4(void *);
extern f32 fn_1_E57BC(void *);
extern void * fn_1_E57CC(void *);
extern void * fn_1_E57D4(void *);
extern void * fn_1_E57DC(void *);
extern f32 fn_1_E57E4(void *);
extern f32 fn_1_E57EC(void *);
extern char * fn_80083DB0(char *, const char *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(u16, u16);

static inline u32 *fn_1_E4A38_array_read(u32 *array) { return array; }
#pragma opt_propagation off
static inline u32 fn_1_E4A38_array_read_(u32 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
static inline u32 * fn_1_E4A38_read_pointer(struct D * owner) { return owner->unk_30; }
static inline char * fn_1_E4A38_call_strcat(const char * a1, char * a0) { return strcat(a0, a1); }
void fn_1_E4A38(u32 arg0, u16 arg1, u16 arg2, Cb arg3) {
    u8 * fzgx_live;
    struct D *p_lbl_1_data_3DC98;
    u32 v0;
    u32 v1;
    u32 v2;
    s32 v3;
    s16 v4;
    u32 t24;
    f32 *fv;
    char loc_8[0x20];

    p_lbl_1_data_3DC98 = (struct D *)&lbl_1_data_3DC98;
    if ((u32)arg3 == (u32)fn_1_4AE0C) {
        fn_1_496FC((f32)(s32)(s16)arg1, (f32)(s32)(s16)arg2);
        fn_1_4955C(lbl_1_rodata_69CC, lbl_1_rodata_69CC);
    } else {
        if ((u32)arg3 == (u32)fn_1_A8DD4) {
            fn_1_A8EF8(arg1, arg2);
        }
    }
    v0 = *(u32 *)((u8 *)arg0 + 316);
    if ((*(u64 *)((u8 *)arg0 + 312) & 0x20000) != 0) {
        arg3(p_lbl_1_data_3DC98->s1b0, (s32)(s16)fn_1_E5724((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1b0, (s32)(s16)fn_1_E573C((Sig_fn_1_E573C_E573CObj *)arg0));
    } else {
        arg3(p_lbl_1_data_3DC98->s1b8, (s32)(s16)fn_1_E5724((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1c4, fn_1_E4A38_array_read_(fn_1_E4A38_read_pointer(p_lbl_1_data_3DC98), (s32)(s16)fn_1_E572C((void *)arg0)));
        arg3(p_lbl_1_data_3DC98->s1d0, fn_1_E57A4((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1e0, fn_1_E57AC((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1f0, fn_1_E57B4((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s200, fn_1_E57BC((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s210, lbl_1_rodata_6808 * fn_1_E57EC((void *)arg0));
        fv = (f32 *)fn_1_E57CC((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s220);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E57D4((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s238);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E5750((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s240);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        arg3(p_lbl_1_data_3DC98->s248, fn_1_E5758((void *)arg0));
        fv = (f32 *)fn_1_E5748((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s258);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E57DC((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s260);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E5760((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s268);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, ((1)[fv]));
        arg3(p_lbl_1_data_3DC98->s230, ((2)[fv]));
        arg3(p_lbl_1_data_3DC98->s270, fn_1_E57E4((void *)arg0));
        fv = (f32 *)fn_1_E5768((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s280);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        arg3(p_lbl_1_data_3DC98->s288, *(u32 *)((u8 *)arg0 + 0x100));
        arg3(p_lbl_1_data_3DC98->s294);
        arg3(p_lbl_1_data_3DC98->s228, *(f32 *)((u8 *)arg0 + 0x128));
        arg3(p_lbl_1_data_3DC98->s228, *(f32 *)((u8 *)arg0 + 0x12c));
        arg3(p_lbl_1_data_3DC98->s230, *(f32 *)((u8 *)arg0 + 0x130));
        loc_8[0] = 0;
        v1 = *(u32 *)((u8 *)arg0 + 316);
        if ((*(u64 *)((u8 *)arg0 + 312) & 0x80000000) != 0) {
            fn_80083DB0(loc_8, (const char *)p_lbl_1_data_3DC98->s29c);
        }
        v2 = *(u32 *)((u8 *)arg0 + 316);
        if ((*(u64 *)((u8 *)arg0 + 312) & 0x40000000) != 0) {
            fn_1_E4A38_call_strcat((const char *)p_lbl_1_data_3DC98->s2a4, loc_8);
        }
        v0 = *(u32 *)((u8 *)arg0 + 316);
        if ((*(u64 *)((u8 *)arg0 + 312) & 0x20000000) != 0) {
            strcat(loc_8, (const char *)(p_lbl_1_data_3DC98->s2ac));
        }
        arg3(p_lbl_1_data_3DC98->s2b4, loc_8);
        arg3(p_lbl_1_data_3DC98->s2c0);
        v3 = 0;
        while ((s16)v3 < 32) {
            t24 = fn_1_E57C4((void *)arg0);
            v4 = (s16)v3;
            if (((1 << v4) & t24) != 0) {
                arg3(p_lbl_1_data_3DC98->s2c8, v4);
            }
            v3++;
        }
        arg3(p_lbl_1_data_3DC98->s2cc);
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_1_E4A38 */

/* fzgx:begin fn_1_E50F0 */
void fn_1_E50F0(void *base, void *arg) {
    struct {
        f32 values[2];
        u32 pad[2];
    } locals;

    lbl_8006DCA4(base, arg);
    fn_1_A71AC();
    fn_8006F828((char *)base + 0x54, locals.values);
    fn_1_E4A38(base, (s32)locals.values[0], (s32)locals.values[1], arg);
}
/* fzgx:end fn_1_E50F0 */

/* fzgx:begin fn_1_E5164 */
typedef struct {
    f32 v0;
    f32 v1;
    f32 v2;
} Out;

typedef struct {
    u32 v[47];
} Tab;

typedef struct {
    u8 pad[0x138];
    u64 flags;
} Obj;

extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern u8 lbl_1_rodata_69D0[188];
extern void fn_1_4AE0C(const char *, ...);
extern const f64 lbl_1_rodata_6800;
extern void fn_1_496FC(f32, f32);
extern const f32 lbl_1_rodata_69CC;
extern void fn_1_4955C(f32, f32);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(s32, s32);

void fn_1_E5164(void *arg0, void *arg1) {
    Out out;
    struct { s16 value; } i;
    Tab tab;
    s32 v1;
    s32 v0;

    lbl_8006DCA4(arg0, arg1);
    fn_1_A71AC();
    fn_8006F828((u8 *)arg0 + 0x54, &out.v0);
    v1 = (s32)out.v1;
    v0 = (s32)out.v0;
    tab = *(Tab *)&lbl_1_rodata_69D0;

    if (arg1 == (void *)fn_1_4AE0C) {
        fn_1_496FC((f32)(s16)v0, (f32)(s16)v1);
        fn_1_4955C(lbl_1_rodata_69CC, lbl_1_rodata_69CC);
    } else if (arg1 == (void *)fn_1_A8DD4) {
        fn_1_A8EF8(v0, v1);
    }

    for (i.value = 0; i.value < 0x40; i.value++) {
        if (((Obj *)arg0)->flags & (1 << i.value)) {
            ((void (*)(void *, u32, ...))arg1)(&lbl_1_data_3E150, tab.v[i.value]);
        }
    }
}
/* fzgx:end fn_1_E5164 */

/* fzgx:begin fn_1_E52F8 noprologue */
#include "types.h"
#include "rel/main_rel/phys.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
    s = 0.0f;
    d = 1.1920928955078125e-07;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = -1.0099999904632568f;
    s = 9.999999747378752e-05f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9900000095367432f;
    s = 2.0f;
    s = -0.0f;
    d = 216.0;
    d = 3.1415927410125732;
    d = 4.0;
    d = 60.0;
    s = 1.0099999904632568f;
    s = 0.05000000074505806f;
    s = 1.0010000467300415f;
    s = 0.8999999761581421f;
    s = 3.0f;
}
static const u32 fzgx_pool_table12[6] = {0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 0.0016666667070239782f;
    s = 0.30000001192092896f;
    s = 0.01666666753590107f;
    s = 10000000.0f;
    s = 5000000.0f;
    s = 100.0f;
}
static const u32 fzgx_pool_table14[43] = {0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.01745329238474369f;
    s = -3.0f;
}
static const u32 fzgx_pool_table16[8] = {0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 224.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 255.0f;
    s = 640.0f;
    s = 480.0f;
    s = 1.2705882787704468f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -10000.0f;
    s = 22500.0f;
    s = 10430.3779296875f;
    s = 0.4000000059604645f;
}
#pragma section code_type ".text"

typedef struct {
    u8 unk_00[0x50];
    f32 unk_50;
    u8 unk_54[0x10];
} Sig_fn_1_E52F8_Arg;

typedef struct {
    f32 value0;
    f32 value1;
    f32 value2;
} Sig_fn_8006F828_Fn8006F828Data;

extern void lbl_8006DCA4(void *base, void *arg);
extern f32 fn_1_A71AC(void);
extern void fn_8006F828(void *base, Sig_fn_8006F828_Fn8006F828Data *out);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(s16 a, s16 b);
extern void fn_1_496FC(f32 a, f32 b);
extern void fn_1_4955C(f32 a, f32 b);
extern f32 __fabsf(f32);

static inline f32 fn_1_E52F8_read_pointer(Sig_fn_8006F828_Fn8006F828Data * owner) { return owner->value1; }
#pragma opt_dead_assignments off
void fn_1_E52F8(Sig_fn_1_E52F8_Arg *arg0, void (*fmt)(const char *, ...))
{
    Sig_fn_8006F828_Fn8006F828Data v;
    s16 b;
    s16 a;

    lbl_8006DCA4(arg0, (void *)fmt);
    fn_1_A71AC();
    fn_8006F828(arg0->unk_54, &v);
    b = (s16)fn_1_E52F8_read_pointer(&v);
    a = (s16)v.value0;
    if (fmt == fn_1_4AE0C) {
        fn_1_496FC((f32)a, (f32)b);
        fn_1_4955C(0.4f, 0.4f);
    } else if (fmt == fn_1_A8DD4) {
        fn_1_A8EF8(a, b);
    }
    if (__fabsf(arg0->unk_50) < 1.1920928955078125e-07) {
        return;
    }
    fmt((const char *)lbl_1_data_3E154, 216.0 * arg0->unk_50);
    fmt((const char *)lbl_1_data_3E160, arg0->unk_50);
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_E52F8 */

/* fzgx:begin fn_1_E5430 */
s16 fn_1_E5430(s16 index) {
    Obj_1_bss_7AE88 *obj = &lbl_1_bss_7AE88;

    switch (index) {
    case 0:
        return obj->unk_4;
    case 1:
        return obj->unk_C;
    case 2:
        return obj->unk_14;
    case 3:
        return obj->unk_1C;
    case 4:
        return obj->unk_24;
    case 5:
        return obj->unk_2C;
    default:
        return -1;
    }
}
/* fzgx:end fn_1_E5430 */

/* fzgx:begin fn_1_E54A8 */
void *fn_1_E54A8(s16 type, s16 index) {
    Obj_1_bss_7AE88 *base = &lbl_1_bss_7AE88;

    switch (type) {
    case 0:
        return (void *)((char *)base->unk_0 + index * 0x1a8);
    case 1:
        return (void *)((char *)base->unk_8 + index * 0x1a8);
    case 2:
        return (void *)((char *)base->unk_10 + index * 0x1a8);
    case 3:
        return (void *)((char *)base->unk_18 + index * 0x1a8);
    case 4:
        return (void *)((char *)base->unk_20 + index * 0x1a8);
    case 5:
        return (void *)((char *)base->unk_28 + index * 0x1a8);
    default:
        return (void *)0;
    }
}
/* fzgx:end fn_1_E54A8 */

/* fzgx:begin fn_1_E5568 */
extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern void fn_1_E4A38(void *base, s32 x, s32 y, void *arg);
extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern u32 fn_80083970(const u8* left, const char* right);
extern u32 strlen(const char* string);
extern void fn_1_8CED0(void* object, s32 value0, s32 value1);
extern void fn_1_8D0A4(void* object);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, s32);
extern void fn_800745A4(u32, s32, s32, u32, s32, s32);
extern void fn_80073778(void *, u32);
extern void fn_80015C1C(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void lbl_8006DFFC(void *, void *, void *);
extern void GXLoadTexMtxImm(void *, u32, s32);
extern f32 lbl_1_rodata_6780[236];
extern f32 fn_1_A6FE8(void);
extern void fn_1_E8938(void);
extern void fn_1_8D1C8(void *object, void (*callback)(void), int arg);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32 value);
extern u32 lbl_1_bss_7C94C[67];
extern void fn_1_EE530(void);
extern u8 lbl_1_bss_7ECB4[72];
extern void fn_1_BC29C(u8 *);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);

extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);

extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
extern void fn_1_9C724(void);
extern void fn_1_DD890(void *);
extern void fn_1_9CC40(void);

typedef struct { u8 pad[0x138]; u64 flags; u8 tail[0x68]; } E5568Entry;
static inline s16 E5568Count(s16 id, Obj_1_bss_7AE88 *p) {
 switch(id) {
 case 0: return p->unk_4;
 case 1: return p->unk_C;
 case 2: return p->unk_14;
 case 3: return p->unk_1C;
 case 4: return p->unk_24;
 case 5: return p->unk_2C;
 default: return -1;
 }
}
static inline E5568Entry *E5568Base(s16 id, Obj_1_bss_7AE88 *p) {
 switch(id) {
 case 0: return (E5568Entry *)p->unk_0;
 case 1: return (E5568Entry *)p->unk_8;
 case 2: return (E5568Entry *)p->unk_10;
 case 3: return (E5568Entry *)p->unk_18;
 case 4: return (E5568Entry *)p->unk_20;
 case 5: return (E5568Entry *)p->unk_28;
 default: return 0;
 }
}
static inline s16 E5568FlagCount(s16 id, Obj_1_bss_7AE88 *p, u64 mask, u64 zero) {
 s32 i;
 s16 count = 0;
 s16 n = E5568Count(id, p);
 E5568Entry *base = E5568Base(id, p);
 for(i = 0; (s16)i < n; i++, base++) {
  if((base->flags & mask) != zero) count++;
 }
 return count;
}
s16 fn_1_E5568(s16 id) {
 Obj_1_bss_7AE88 *p = &lbl_1_bss_7AE88;
 s16 total = E5568Count(id, p);
 s16 count = E5568FlagCount(id, p, 0x800000000ULL, 0);
 return count == -1 ? count : (s16)(total - count);
}
/* fzgx:end fn_1_E5568 */

/* fzgx:begin fn_1_E5724 */
s16 fn_1_E5724(void *base) {
    return *(s16 *)((char *)base + 0x8);
}
/* fzgx:end fn_1_E5724 */

/* fzgx:begin fn_1_E572C */
s16 fn_1_E572C(void *base) {
    return *(s16 *)((char *)base + 0xA);
}
/* fzgx:end fn_1_E572C */

/* fzgx:begin fn_1_E5734 */
typedef struct {
    u32 unk0;
    f32 value;
} E5734Obj;

// Returns the float at offset 4 of the object.
f32 fn_1_E5734(E5734Obj *self) {
    return self->value;
}
/* fzgx:end fn_1_E5734 */

/* fzgx:begin fn_1_E573C */
typedef struct {
    u8 unk0[0x100];
    s32 value;
} E573CObj;

s16 fn_1_E573C(E573CObj *self) {
    return self->value;
}
/* fzgx:end fn_1_E573C */

/* fzgx:begin fn_1_E5748 */
// Returns a pointer to the member at offset 0x54.
u8 *fn_1_E5748(u8 *self) {
    return self + 0x54;
}
/* fzgx:end fn_1_E5748 */

/* fzgx:begin fn_1_E5750 */
// Returns a pointer to the member at offset 0x44.
u8 *fn_1_E5750(u8 *self) {
    return self + 0x44;
}
/* fzgx:end fn_1_E5750 */

/* fzgx:begin fn_1_E5758 */
f32 fn_1_E5758(u8 *self) {
    return *(f32 *)(self + 0x50);
}
/* fzgx:end fn_1_E5758 */

/* fzgx:begin fn_1_E5760 */
u8 *fn_1_E5760(u8 *self) {
    return self + 0x78;
}
/* fzgx:end fn_1_E5760 */

/* fzgx:begin fn_1_E5768 */
u8 *fn_1_E5768(u8 *self) {
    return self + 0xF4;
}
/* fzgx:end fn_1_E5768 */

/* fzgx:begin fn_1_E5770 */
struct fn_1_E5770_Arg0 {
    u8 pad_0[0x138];
    u64 unk_138;
};

s32 fn_1_E5770(struct fn_1_E5770_Arg0 *arg0, u32 arg1, u64 mask) {
    return (arg0->unk_138 & mask) ? 1 : 0;
}
/* fzgx:end fn_1_E5770 */

/* fzgx:begin fn_1_E57A4 */
f32 fn_1_E57A4(void *base) {
    return *(f32 *)((char *)base + 0x18);
}
/* fzgx:end fn_1_E57A4 */

/* fzgx:begin fn_1_E57AC */
f32 fn_1_E57AC(void *base) {
    return *(f32 *)((char *)base + 0x1c);
}
/* fzgx:end fn_1_E57AC */

/* fzgx:begin fn_1_E57B4 */
f32 fn_1_E57B4(void *base) {
    return *(f32 *)((char *)base + 0x20);
}
/* fzgx:end fn_1_E57B4 */

/* fzgx:begin fn_1_E57BC */
f32 fn_1_E57BC(void *base) {
    return *(f32 *)((char *)base + 0x24);
}
/* fzgx:end fn_1_E57BC */

/* fzgx:begin fn_1_E57C4 */
u32 fn_1_E57C4(void *base) {
    return *(u32 *)((char *)base + 0x148);
}
/* fzgx:end fn_1_E57C4 */

/* fzgx:begin fn_1_E57CC */
void *fn_1_E57CC(void *base) {
    return (char *)base + 0x2c;
}
/* fzgx:end fn_1_E57CC */

/* fzgx:begin fn_1_E57D4 */
void *fn_1_E57D4(void *base) {
    return (char *)base + 0x38;
}
/* fzgx:end fn_1_E57D4 */

/* fzgx:begin fn_1_E57DC */
void *fn_1_E57DC(void *base) {
    return (char *)base + 0x6c;
}
/* fzgx:end fn_1_E57DC */

/* fzgx:begin fn_1_E57E4 */
f32 fn_1_E57E4(void *base) {
    return *(f32 *)((char *)base + 0x84);
}
/* fzgx:end fn_1_E57E4 */

/* fzgx:begin fn_1_E57EC */
f32 fn_1_E57EC(void *base) {
    return *(f32 *)((char *)base + 0x28);
}
/* fzgx:end fn_1_E57EC */

/* fzgx:begin fn_1_E57F4 */
void fn_1_E57F4(void *base, f32 value) {
    *(f32 *)((char *)base + 0x4) = value;
}
/* fzgx:end fn_1_E57F4 */

/* fzgx:begin fn_1_E57FC */
// Initializes the object's 12-byte value, clearing it or copying from the source.
void fn_1_E57FC(void *object, void *source) {
    if (source == 0) {
        fn_80008BEC((u8 *)object + 0x44, 0, 0xc);
    } else {
        fn_80008BA8((u8 *)object + 0x44, source, 0xc);
    }
}
/* fzgx:end fn_1_E57FC */

/* fzgx:begin fn_1_E5840 */
// Clears or copies the object's 12-byte value at offset 0x78.
void fn_1_E5840(void *base, const void *value) {
    if (value == 0) {
        fn_80008BEC((char *)base + 0x78, 0, 0xc);
    } else {
        fn_80008BA8((char *)base + 0x78, (void *)value, 0xc);
    }
}
/* fzgx:end fn_1_E5840 */

/* fzgx:begin fn_1_E5884 */
// Resets the object's three-component value or copies a replacement into it.
void fn_1_E5884(void *base, void *value) {
    if (value == 0) {
        f32 reset_value = lbl_1_rodata_67A8;

        *(f32 *)((char *)base + 0xfc) = reset_value;
        *(f32 *)((char *)base + 0xf8) = reset_value;
        *(f32 *)((char *)base + 0xf4) = reset_value;
    } else {
        fn_80008BA8((char *)base + 0xf4, value, 0xc);
    }
}
/* fzgx:end fn_1_E5884 */

/* fzgx:begin fn_1_E58CC */
// Copies the supplied three-word value, or the shared default when no value is provided.
void fn_1_E58CC(void *base, const void *value) {
    if (value == 0) {
        u32 default_value[3];

        default_value[0] = lbl_1_rodata_6A8C[0];
        default_value[1] = lbl_1_rodata_6A8C[1];
        default_value[2] = lbl_1_rodata_6A8C[2];
        fn_80008BA8((char *)base + 0x128, default_value, 0xc);
    } else {
        fn_80008BA8((char *)base + 0x128, (void *)value, 0xc);
    }
}
/* fzgx:end fn_1_E58CC */

/* fzgx:begin fn_1_E5930 */
void fn_1_E5930(void *base, u32 unused, u32 mask138, u32 mask13c) {
    u32 value13c = *(u32 *)((char *)base + 0x13c);
    u32 value138 = *(u32 *)((char *)base + 0x138);
    *(u32 *)((char *)base + 0x13c) = value13c | mask13c;
    *(u32 *)((char *)base + 0x138) = value138 | mask138;
}
/* fzgx:end fn_1_E5930 */

/* fzgx:begin fn_1_E594C */
struct fn_1_E594C_Arg0 {
    u8 pad_0[0x138];
    u32 unk_138;
    u32 unk_13C;
};

#pragma opt_propagation off
#pragma peephole off
void fn_1_E594C(struct fn_1_E594C_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 inv2;
    u32 value138;
    s32 inv3;
    u32 value13c;

    value13c = arg0->unk_13C;
    inv3 = ~(s32)arg3;
    value138 = arg0->unk_138;
    inv2 = ~(s32)arg2;
    arg0->unk_13C = ((value13c) & ((u32)inv3));
    arg0->unk_138 = ((value138) & ((u32)inv2));
}
#pragma peephole reset

#pragma opt_propagation reset
/* fzgx:end fn_1_E594C */

/* fzgx:begin fn_1_E5970 */
void fn_1_E5970(void *base, f32 value) {
    *(f32 *)((char *)base + 0x18) = value;
}
/* fzgx:end fn_1_E5970 */

/* fzgx:begin fn_1_E5978 */
void fn_1_E5978(void *base, f32 value) {
    *(f32 *)((char *)base + 0x1c) = value;
}
/* fzgx:end fn_1_E5978 */

/* fzgx:begin fn_1_E5980 */
// fn_1_E5980: Store float value at offset 0x20 in base pointer
void fn_1_E5980(void *base, f32 value) {
    *(f32 *)((char *)base + 0x20) = value;
}
/* fzgx:end fn_1_E5980 */

/* fzgx:begin fn_1_E5988 */
void fn_1_E5988(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x54), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x54), value, 0xC);
    }

    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x60), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x60), value, 0xC);
    }
}
/* fzgx:end fn_1_E5988 */

/* fzgx:begin fn_1_E5A0C */
void fn_1_E5A0C(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x2C), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x2C), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A0C */

/* fzgx:begin fn_1_E5A50 */
void fn_1_E5A50(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x38), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x38), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A50 */

/* fzgx:begin fn_1_E5A94 */
void fn_1_E5A94(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x6C), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x6C), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A94 */

/* fzgx:begin fn_1_E5AD8 */
void fn_1_E5AD8(void *base, f32 value) {
    *(f32 *)((char *)base + 0x28) = value;
}
/* fzgx:end fn_1_E5AD8 */

/* fzgx:begin fn_1_E5AE0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern u32 lbl_1_rodata_6A98[50];
extern void fn_1_57714(u8 arg);
extern f32 lbl_1_rodata_67B4[19];
extern const f64 lbl_1_rodata_6800;
typedef struct { f32 x; f32 y; f32 z; } E5AE0Vec;
extern void fn_1_5773C(E5AE0Vec *a, E5AE0Vec *b, u8 *c);
extern void fn_80008BEC(void *dst, int value, u32 size);

static inline u32 fn_1_E5AE0_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void fn_1_E5AE0(s16 a, s16 b, f32 w, f32 h) {
    u32 flag = fn_1_E5AE0_array_read(lbl_1_rodata_6A98, 0);
    E5AE0Vec o1;
    E5AE0Vec o2;
    s16 i;
    f32 xpos;
    f32 zpos;
    f32 stepx;
    f32 stepz;
    f32 cur;

    fn_1_57714(6);
    stepx = w / (f32)a;
    stepz = h / (f32)b;
    xpos = lbl_1_rodata_67B4[0] * -w;
    zpos = lbl_1_rodata_67B4[0] * -h;
    cur = xpos;
    for (i = 0; i < a + 1; i++) {
        fn_80008BEC(&o1, 0, 0xC);
        fn_80008BEC(&o2, 0, 0xC);
        o2.x = cur;
        o1.x = cur;
        o1.z = zpos;
        o2.z = -zpos;
        fn_1_5773C(&o1, &o2, (u8 *)&flag);
        cur += stepx;
    }
    for (i = 0; i < b + 1; i++) {
        fn_80008BEC(&o1, 0, 0xC);
        fn_80008BEC(&o2, 0, 0xC);
        o2.z = zpos;
        o1.z = zpos;
        o1.x = xpos;
        o2.x = -xpos;
        fn_1_5773C(&o1, &o2, (u8 *)&flag);
        zpos += stepz;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_E5AE0 */

/* fzgx:begin fn_1_E7E00 noprologue */
#include "types.h"

typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct fn_1_E7E00_lbl_1_bss_7AE88 {
    u32 unk_0;
    u16 unk_4;
    u8 pad_6[0x2];
    u32 unk_8;
    u16 unk_C;
    u8 pad_E[0x2];
    u32 unk_10;
    u16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u16 unk_1C;
    u8 pad_1E[0x2];
    u32 unk_20;
    u16 unk_24;
    u8 pad_26[0x2];
    u32 unk_28;
    u16 unk_2C;
    u8 pad_2E[0x2];
    u32 unk_30;
};
struct fn_1_E7E00_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_1_E7E00_lbl_801A6410 lbl_801A6410;
extern u32 lbl_1_data_3DDB4;
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_7AE88;
u16 lbl_1_bss_7AE88__fzgx_offset_4;
u16 lbl_1_bss_7AE88__fzgx_offset_6;
u32 lbl_1_bss_7AE88__fzgx_offset_8;
u16 lbl_1_bss_7AE88__fzgx_offset_C;
u16 lbl_1_bss_7AE88__fzgx_offset_E;
u32 lbl_1_bss_7AE88__fzgx_offset_10;
u16 lbl_1_bss_7AE88__fzgx_offset_14;
u16 lbl_1_bss_7AE88__fzgx_offset_16;
u32 lbl_1_bss_7AE88__fzgx_offset_18;
u16 lbl_1_bss_7AE88__fzgx_offset_1C;
u16 lbl_1_bss_7AE88__fzgx_offset_1E;
u32 lbl_1_bss_7AE88__fzgx_offset_20;
u16 lbl_1_bss_7AE88__fzgx_offset_24;
u16 lbl_1_bss_7AE88__fzgx_offset_26;
u32 lbl_1_bss_7AE88__fzgx_offset_28;
u16 lbl_1_bss_7AE88__fzgx_offset_2C;
u16 lbl_1_bss_7AE88__fzgx_offset_2E;
u32 lbl_1_bss_7AEB8;
u32 lbl_1_bss_7AEB8__fzgx_offset_4[164];
u32 lbl_1_bss_7B14C[13];
u32 lbl_1_bss_7B180[2];
u32 lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_26;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2E;
    s = *(u8 *)&lbl_1_bss_7AEB8;
    s = *(u8 *)&lbl_1_bss_7AEB8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
}
#pragma section code_type ".text"

void fn_1_E7E00(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    
    if ((lbl_1_bss_7AEB8 & ~0x7FFFFFFF) != 0) {
    fn_1_8D168((Sig_fn_1_8D168_Fn1_8D168State *)((u8 *)((u8 *)&lbl_1_bss_7AEB8) + 528));
    lbl_1_bss_7AEB8 = (lbl_1_bss_7AEB8 & 0x7FFFFFFF);
    }
    v0 = lbl_1_bss_7AE88;
    if (v0 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)&lbl_1_data_3DDB4, 2647);
    lbl_1_bss_7AE88 = 0;
    lbl_1_bss_7AE88__fzgx_offset_4 = 0;
    }
    v1 = lbl_1_bss_7AE88__fzgx_offset_8;
    if (v1 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v1, (const char *)&lbl_1_data_3DDB4, 2648);
    lbl_1_bss_7AE88__fzgx_offset_8 = 0;
    lbl_1_bss_7AE88__fzgx_offset_C = 0;
    }
    v2 = lbl_1_bss_7AE88__fzgx_offset_10;
    if (v2 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v2, (const char *)&lbl_1_data_3DDB4, 2649);
    lbl_1_bss_7AE88__fzgx_offset_10 = 0;
    lbl_1_bss_7AE88__fzgx_offset_14 = 0;
    }
    v3 = lbl_1_bss_7AE88__fzgx_offset_18;
    if (v3 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v3, (const char *)&lbl_1_data_3DDB4, 2650);
    lbl_1_bss_7AE88__fzgx_offset_18 = 0;
    lbl_1_bss_7AE88__fzgx_offset_1C = 0;
    }
    v4 = lbl_1_bss_7AE88__fzgx_offset_20;
    if (v4 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v4, (const char *)&lbl_1_data_3DDB4, 2651);
    lbl_1_bss_7AE88__fzgx_offset_20 = 0;
    lbl_1_bss_7AE88__fzgx_offset_24 = 0;
    }
    v5 = lbl_1_bss_7AE88__fzgx_offset_28;
    if (v5 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v5, (const char *)&lbl_1_data_3DDB4, 2652);
    lbl_1_bss_7AE88__fzgx_offset_28 = 0;
    lbl_1_bss_7AE88__fzgx_offset_2C = 0;
    }
}
/* fzgx:end fn_1_E7E00 */

/* fzgx:begin fn_1_E86FC */
typedef struct StringValueEntry {
    u32 value;
    const u8* string;
} StringValueEntry;

typedef struct StringValueTable {
    s32 count;
    u32 unused;
    StringValueEntry* entries;
} StringValueTable;

u32 fn_1_E86FC(StringValueTable* table, const char* string) {
    StringValueEntry* entry;
    u32 best_value;
    s32 best_length;
    s32 count;

    if (table == 0) {
        return 0;
    }

    entry = table->entries;
    count = table->count;
    best_length = 0;
    best_value = 0;

    while (count > 0) {
        u32 length;

        if (fn_80083970(entry->string, string) != 0) {
            length = strlen(string);
            if (entry->string[length] == 0) {
                length++;
            }
            if ((s32)length > best_length) {
                best_value = entry->value;
                best_length = length;
            }
        }

        count--;
        entry++;
    }

    return best_value;
}
/* fzgx:end fn_1_E86FC */

/* fzgx:begin fn_1_E87A4 */
void fn_1_E87A4(f64 value0, f64 value1) {
    s32 converted0;
    s32 converted1;
    void* object;

    converted0 = (s32)value0;
    converted1 = (s32)value1;
    object = (u8*)&lbl_1_bss_7AEB8 + 0x210;
    fn_1_8CED0(object, converted0, converted1);
    fn_1_8D0A4(object);
}
/* fzgx:end fn_1_E87A4 */

/* fzgx:begin fn_1_E87FC */
typedef struct {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} PhysObj;

void fn_1_E87FC(PhysObj *obj) {
    u8 *entry;
    s16 i;
    Obj_1_bss_7AEB8 *global;
    u8 work[0x30];

    fn_800734A8(obj->unk_C, obj->unk_10, obj->unk_18, 4);
    fn_80072EDC(obj->unk_C, 1);
    fn_800745A4(obj->unk_10, 0, 0, obj->unk_14, 0, 0x7d);
    fn_80073778((u8 *)&lbl_1_bss_7AEB8 + 0x274, obj->unk_18);
    global = &lbl_1_bss_7AEB8;

    i = 0;
    entry = (u8 *)global;
    while (i < global->unk_1E4) {
        f32 value = global->unk_20C;
        fn_80015C1C(work, global->unk_1EC, global->unk_1F0,
                    global->unk_1F4, global->unk_1F8, global->unk_1FC,
                    global->unk_200, global->unk_204, global->unk_208, value);
        lbl_8006DFFC(work, entry + 4, work);
        GXLoadTexMtxImm(work, obj->unk_14, 0);
        entry += 0x30;
        i++;
    }

    obj->unk_C++;
    obj->unk_18++;
    obj->unk_14++;
    obj->unk_10++;
}
/* fzgx:end fn_1_E87FC */

/* fzgx:begin fn_1_E95B4 */
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
} Camera;

extern Camera *game_camera_get(void);

void fn_1_E95B4(void) {
    f32 *table = lbl_1_rodata_6780;
    Obj_1_bss_7AEB8 *state;
    Obj_1_bss_7AEB8 *state_after;
    Obj_1_bss_7AEB8 *state_final;
    Camera *camera;
    f32 camera_y;

    if ((lbl_1_bss_7AEB8.unk_0 & (0xFFFFFFFFu << 31)) == 0) {
        return;
    }

    camera = game_camera_get();
    state = &lbl_1_bss_7AEB8;
    state->unk_254 = camera->unk_8;
    camera = game_camera_get();
    camera_y = state->unk_254;
    state_after = &lbl_1_bss_7AEB8;
    state_after->unk_258 = camera->unk_C;

    if (camera_y < table[10] || camera_y > table[233]) {
        state->unk_254 = table[234];
        state_after->unk_258 = fn_1_A6FE8();
    }

    state_final = &lbl_1_bss_7AEB8;
    state_final->unk_25C = table[12];
    state_final->unk_260 = table[235];
    fn_1_8D1C8((u8 *)state_final + 0x210, fn_1_E8938, 0);
}
/* fzgx:end fn_1_E95B4 */

/* fzgx:begin fn_1_E9680 noprologue */
#include "types.h"
#include "rel/main_rel/phys.h"

extern void fn_80008BEC(void* dst, int value, int size);

void fn_1_E9680(void) {
    u8* base = (u8*)&lbl_1_bss_7B180;
    u32* p0;
    u32* p1;
    u32* p2;
    u32* p3;
    u32* p4;
    u32* p5;
    u32* p6;
    u32* p7;
    u32* p8;
    u32* p9;
    int i;

    fn_80008BEC(base + 0x2c, 0, 0x13d8);
    fn_80008BEC(base + 0x1404, 0, 0x1fc);

    p0 = (u32*)(base + 0x1600);
    p1 = (u32*)(base + 0x1614);
    p2 = (u32*)(base + 0x1628);
    p3 = (u32*)(base + 0x163c);
    p4 = (u32*)(base + 0x1650);
    p5 = (u32*)(base + 0x1664);
    p6 = (u32*)(base + 0x1678);
    p7 = (u32*)(base + 0x168c);
    p8 = (u32*)(base + 0x16a0);
    p9 = (u32*)(base + 0x16b4);

    for (i = 5; i != 0; i--) {
        *p0++ = 0;
        *p1++ = 0;
        *p2++ = 0;
        *p3++ = 0;
        *p4++ = 0;
        *p5++ = 0;
        *p6++ = 0;
        *p7++ = 0;
        *p8++ = 0;
        *p9++ = 0;
    }

    *(s32*)(base + 0x16c8) = -1;
    *(u8*)(base + 0x16cc) = 0xff;
    *(u32*)(base + 0x16d0) = 0;
}
/* fzgx:end fn_1_E9680 */

/* fzgx:begin fn_1_E9C68 */
// Updates the active physics callback and refreshes its associated state.
void fn_1_E9C68(void) {
    u32 value;

    if ((s32)lbl_1_bss_7B188 == 0) {
        return;
    }

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        value = fn_80008E84(fn_1_3F8C0());
        lbl_1_bss_7C85C.unk_0 = value;
    }

    if ((s32)lbl_1_data_3E52C >= 0) {
        ((void (**)(void))lbl_1_data_3E434)[lbl_1_data_3E52C]();
    }

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        fn_80008E84(lbl_1_bss_7C85C.unk_0);
    }
}
/* fzgx:end fn_1_E9C68 */

/* fzgx:begin fn_1_EB074 */
void fn_1_EB074(u32 value) {
    lbl_1_bss_7C94C[0] = value;
}
/* fzgx:end fn_1_EB074 */

/* fzgx:begin fn_1_EB080 */
// Preserve the previous mode when switching to mode 11, then update the active mode.
void fn_1_EB080(int mode) {
    u32* state = (u32*)lbl_1_data_3E358;

    if ((int)lbl_1_bss_7B188 == 0) {
        return;
    }

    if (mode == 11) {
        state[0x1e0 / 4] = state[0x1d4 / 4];
    }

    state[0x1d8 / 4] = mode;
}
/* fzgx:end fn_1_EB080 */

/* fzgx:begin fn_1_EB0B0 */
extern u32 lbl_1_bss_7B188;
extern u8 lbl_1_bss_7C8CE;

int fn_1_EB0B0(void) {
    return (lbl_1_bss_7B188 != 0) ? lbl_1_bss_7C8CE : 0;
}
/* fzgx:end fn_1_EB0B0 */

/* fzgx:begin fn_1_EB200 */
// Return whether the active state is one of the physics states.
int fn_1_EB200(void) {
    if ((s32)lbl_1_bss_7B188 == 0) {
        return 0;
    }

    if ((s32)lbl_1_data_3E52C == 14 ||
        (s32)lbl_1_data_3E52C == 16 ||
        (s32)lbl_1_data_3E52C == 15) {
        return 1;
    }

    return 0;
}
/* fzgx:end fn_1_EB200 */

/* fzgx:begin fn_1_EB248 */
// Return whether the current state is one of the supported race states.
int fn_1_EB248(void) {
    if ((s32)lbl_1_bss_7B188 == 0) {
        return 0;
    }

    {
        s32 state = lbl_1_data_3E52C;

        if ((u32)(state - 9) <= 4 ||
            (u32)(state - 5) <= 2 ||
            state == 8) {
            return 1;
        }
    }

    return 0;
}
/* fzgx:end fn_1_EB248 */

/* fzgx:begin fn_1_EB29C pool */
typedef struct {
    u8 pad_0[0x16CC];
    u8 unk_16CC;
    u8 pad_16CD[0x174E - 0x16CD];
    u8 unk_174E;
    u8 pad_174F[0x1754 - 0x174F];
    u8 unk_1754;
    u8 pad_1755[0x17D0 - 0x1755];
    s16 unk_17D0[5];
    u32 unk_17DC[5];
    u8 unk_17F0[15];
} PhysState_7B180;

// Reset the per-track physics state table.
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[177];
u32 lbl_1_bss_7C848_fill_7C848;
u8 lbl_1_bss_7C848_4;
u8 lbl_1_bss_7C848_fill_7C84D;
u16 lbl_1_bss_7C848_fill_7C84E;
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C_fill_7C8CC;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE_fill_7C8CF;
u32 lbl_1_bss_7C8CE_fill_7C8D0;
u8 lbl_1_bss_7C8CE_6;
u8 lbl_1_bss_7C8CE_fill_7C8D5;
u16 lbl_1_bss_7C8CE_fill_7C8D6;
u32 lbl_1_bss_7C8CE_fill_7C8D8[15];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C_fill_7C94C;
s16 lbl_1_bss_7C94C_4[5];
u16 lbl_1_bss_7C94C_fill_7C95A;
u32 lbl_1_bss_7C94C_10[5];
u8 lbl_1_bss_7C94C_24[15];
u8 lbl_1_bss_7C94C_fill_7C97F;
u32 lbl_1_bss_7C94C_fill_7C980[54];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C848;
    s = *(u8 *)&lbl_1_bss_7C848_4;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C84D;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C84E;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8CC;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8CF;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D0;
    s = *(u8 *)&lbl_1_bss_7C8CE_6;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D5;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D6;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D8;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C94C;
    s = *(u8 *)&lbl_1_bss_7C94C_4;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C95A;
    s = *(u8 *)&lbl_1_bss_7C94C_10;
    s = *(u8 *)&lbl_1_bss_7C94C_24;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C97F;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C980;
}
#pragma section code_type ".text"

void fn_1_EB29C(void) {
    

    lbl_1_bss_7C848_4 = 0xFF;
    lbl_1_bss_7C8CE = 0;
    lbl_1_bss_7C8CE_6 = 0;
    lbl_1_bss_7C94C_4[0] = -1;
    lbl_1_bss_7C94C_10[0] = 0;
    lbl_1_bss_7C94C_24[0] = 0;
    lbl_1_bss_7C94C_24[1] = 0;
    lbl_1_bss_7C94C_24[2] = 0;
    lbl_1_bss_7C94C_4[1] = -1;
    lbl_1_bss_7C94C_10[1] = 0;
    lbl_1_bss_7C94C_24[3] = 0;
    lbl_1_bss_7C94C_24[4] = 0;
    lbl_1_bss_7C94C_24[5] = 0;
    lbl_1_bss_7C94C_4[2] = -1;
    lbl_1_bss_7C94C_10[2] = 0;
    lbl_1_bss_7C94C_24[6] = 0;
    lbl_1_bss_7C94C_24[7] = 0;
    lbl_1_bss_7C94C_24[8] = 0;
    lbl_1_bss_7C94C_4[3] = -1;
    lbl_1_bss_7C94C_10[3] = 0;
    lbl_1_bss_7C94C_24[9] = 0;
    lbl_1_bss_7C94C_24[10] = 0;
    lbl_1_bss_7C94C_24[11] = 0;
    lbl_1_bss_7C94C_4[4] = -1;
    lbl_1_bss_7C94C_10[4] = 0;
    lbl_1_bss_7C94C_24[12] = 0;
    lbl_1_bss_7C94C_24[13] = 0;
    lbl_1_bss_7C94C_24[14] = 0;
}
/* fzgx:end fn_1_EB29C */

/* fzgx:begin fn_1_EF924 */
void fn_1_EF924(void) {
    fn_1_EE530();
    lbl_1_data_3E52C = lbl_1_data_3E538;
    fn_1_BC29C(lbl_1_bss_7ECB4);
    fn_1_B9C0C();
    fn_1_1596DC(2);
    fn_1_484CC(2);
}
/* fzgx:end fn_1_EF924 */

/* fzgx:begin fn_1_EFA1C */
void fn_1_EFA1C(void) {
    fn_1_EE530();
    lbl_1_data_3E52C = lbl_1_data_3E538;
}
/* fzgx:end fn_1_EFA1C */

/* fzgx:begin fn_1_F22E4 */
// Maps a course selection to its associated data value.
s16 fn_1_F22E4(s32 arg) {
    s16 group;
    s16 entry;
    s32 index;

    fn_1_12EF80((s16)arg, &group, &entry);
    index = (group - 1) * 6 + entry;
    return (s16)((s32 *)lbl_1_data_3E53C)[index];
}
/* fzgx:end fn_1_F22E4 */

/* fzgx:begin fn_1_F2338 */
#include "types.h"

extern void fn_1_12EF80(s16 value, s16 *arg1, s16 *arg2);



u32 fn_1_F2338(s32 value, u32 target) {
    s16 group;
    s16 entry;
    u32 packed;
    u32 hour;
    u32 minute;
    u32 low;

    value = (s16)value;
    fn_1_12EF80(value, &group, &entry);
    packed = (*(u32 (*)[30])&lbl_1_data_3E5B4)[(group - 1) * 6 + entry];
    minute = (packed >> 12) & 0xff;
    hour = (packed >> 20) & 0xff;
    minute += 0xa;
    low = packed & 0xfff;

    if (minute > 0x3c) {
        minute -= 0x3c;
        hour += 1;
    }

    packed = (hour << 20) | (minute << 12) | low;
    if (packed > target) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_F2338 */

/* fzgx:begin fn_1_F2740 */
u32 fn_1_F2740(u32 a, u32 b) {
    if (a >= 6) {
        return 0;
    }
    if (b >= 6) {
        return 0;
    }
    return ((u32 *)lbl_1_data_3E5B4)[(a - 1) * 6 + b];
}
/* fzgx:end fn_1_F2740 */
