#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/accessory.h"
extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void fn_8006E250(void *, void *);
extern void fn_1_10846C(void);
extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern s32 fn_1_14D670(void);
extern u32 lbl_801A66A0;
extern s32 fn_1_86678(s32 arg);
extern u32 lbl_1_bss_897AC[1741];
extern u32 lbl_1_bss_897A4;
extern u32 lbl_1_bss_897A8;
extern void * lbl_801A6410;
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DC20(void);
extern const f64 lbl_1_rodata_7BF8;
extern void fn_80008BA8(void *dst, void *src, int size);
extern void *fn_1_45D0(void *manager, int type, void *data, int code);
extern void fn_1_105744(void);
extern void fn_1_106DB4(void);
extern void fn_1_9D0EC(u32, u32, void*, void*);
extern void fn_1_103AA8(void);
extern u32 lbl_1_bss_85288[2];
extern void fn_1_103AD4(void);
extern void fn_1_105768(void);
extern void fn_1_9E5B8(void *);
extern f32 lbl_1_rodata_7B58[40];
extern u8 lbl_1_rodata_8058[16];
extern int mathutil_mtxA_rotate_z__fzgx_offset_C();
extern struct fn_1_129D9C_system *lbl_801A6D00;
extern void lbl_8006DCA4(void);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006D7B0(void);
extern void lbl_8006D668(void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006DB74(void *);
extern void fn_80072558(void);
extern void fn_80083DB0(void *, void *);
extern void *fn_1_55210(void *);
extern void *fn_1_548AC(u32);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void fn_1_12A0E0(void);

/* fzgx:begin fn_1_108870 */
#include "rel/main_rel/accessory.h"

typedef struct {
    u8 pad_0[0xc];
    u32 unk_c;
    u8 pad_10[0x58];
} fn_1_108870_AccessoryEntry;

fn_1_108870_AccessoryEntry *fn_1_108870(void) {
    u32 i;

    for (i = 0; i < 0x46; i++) {
        if (((fn_1_108870_AccessoryEntry *)&lbl_1_bss_86ED0)[i].unk_c == 0) {
            return &((fn_1_108870_AccessoryEntry *)&lbl_1_bss_86ED0)[i];
        }
    }
    return 0;
}
/* fzgx:end fn_1_108870 */

/* fzgx:begin fn_1_1088B8 */
extern void fn_1_108920(void *arg);

typedef struct {
    u8 pad_0[0xc];
    u32 unk_c;
    u8 pad_10[0x58];
} fn_1_1088B8_AccessoryEntry;

void fn_1_1088B8(void *arg) {
    u32 i;

    for (i = 0; i < 0x46; i++) {
        fn_1_1088B8_AccessoryEntry *entry = ((fn_1_1088B8_AccessoryEntry *)&lbl_1_bss_86ED0) + i;
        if (entry->unk_c == (u32)arg) {
            fn_1_108920(entry);
        }
    }
}
/* fzgx:end fn_1_1088B8 */

/* fzgx:begin fn_1_108920 noprologue */
#include "types.h"

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};


struct fn_1_108920_Copy12 { u32 a[3]; };
struct fn_1_108920_lbl_801A6410 {
    u32 unk_0;
};

extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern struct fn_1_108920_lbl_801A6410 lbl_801A6410;
extern u32 lbl_1_data_40530;
extern void * fn_80077B64(struct Sig_fn_80077B64_fn_80077B64_Arg0 *);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_80008BEC(u32, u32, u32);

void fn_1_108920(u32 accessory) {
    u32 resource;
    s32 matrix_address;
    s32 source_offset;
    s32 entry_index;
    u32 source_address;
    u32 positions;
    u32 entries;
    u32 indices;
    u32 extra_data;
    void * entry_count;
    s32 matrix_base;
    if (accessory != 0) {
        resource = *(u32 *)((u8 *)accessory + 16);
        if (resource != 0) {
            entry_count = (void *)(fn_80077B64((struct Sig_fn_80077B64_fn_80077B64_Arg0 *)resource));
            matrix_base = fn_80077B14((struct Sig_fn_80077B14_fn_80077B14_Arg0 *)resource);
            matrix_address = matrix_base;
            entry_index = 0;
            source_offset = 0;
            while ((u32)entry_index < *(u32 *)((u8 *)entry_count + 0)) {
                entry_index++;
                source_address = (*(u32 *)((u8 *)accessory + 100) + source_offset);
                *(struct fn_1_108920_Copy12 *)matrix_address = *(struct fn_1_108920_Copy12 *)source_address;
                source_offset += 12;
                matrix_address += 64;
            }
        }
    }
    positions = *(u32 *)((u8 *)accessory + 100);
    if (positions != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, positions, (const char *)&lbl_1_data_40530, 1154);
        *(u32 *)((u8 *)accessory + 100) = 0;
    }
    entries = *(u32 *)((u8 *)accessory + 36);
    if (entries != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, entries, (const char *)&lbl_1_data_40530, 1157);
        *(u32 *)((u8 *)accessory + 36) = 0;
    }
    indices = *(u32 *)((u8 *)accessory + 40);
    if (indices != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, indices, (const char *)&lbl_1_data_40530, 1158);
        *(u32 *)((u8 *)accessory + 40) = 0;
    }
    extra_data = *(u32 *)((u8 *)accessory + 44);
    if (extra_data != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, extra_data, (const char *)&lbl_1_data_40530, 1159);
        *(u32 *)((u8 *)accessory + 44) = 0;
    }
    fn_80008BEC(accessory, 0, 104);
}
/* fzgx:end fn_1_108920 */

/* fzgx:begin fn_1_108A90 noprologue */
#include "types.h"
#include "psvec.h"

extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D0E8(f32);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_108A90_Vec3;

typedef struct {
    u8 unk_0;
    u8 pad_1[0xf];
    fn_1_108A90_Vec3 vec;
    u8 pad_1c[0x28];
} fn_1_108A90_Entry;

typedef struct {
    u8 pad_0[0x150];
    u32 *unk_150;
} fn_1_108A90_Mgr;

typedef struct {
    u8 pad_0[0xc];
    fn_1_108A90_Mgr *unk_c;
    u8 pad_10[8];
    u32 count;
    u8 pad_1c[8];
    fn_1_108A90_Entry *entries;
} fn_1_108A90_Self;

#pragma opt_dead_assignments off
void fn_1_108A90(fn_1_108A90_Self *self, s32 idx, f32 radius, f32 cx, f32 cy, f32 cz) {
    fn_1_108A90_Self *s = self;
    f32 r = radius;
    f32 sq = r * r;
    struct { u32 value; } i;
    fn_1_108A90_Entry *e;
    fn_1_108A90_Vec3 center;
    fn_1_108A90_Vec3 d;

    center.x = cx;
    center.y = cy;
    center.z = cz;
    lbl_8006DBAC((void *)(((0x88) + (((*((s->unk_c->unk_150) + (2)))) + (idx * 0x18c)))));
    lbl_8006E1B0(&center, &center);
    i.value = 0;
    e = s->entries;
    while (i.value < s->count) {
        f32 dz;
        f32 dy;
        f32 dx;
        f32 d2;

        /* retail keeps the skip flag test as a branch to the common increment tail */
        if ((*e).unk_0 & 1) {
            goto next; /* skip to the loop increment tail */
        }
        dx = (*e).vec.x - center.x;
        dy = (*e).vec.y;
        dy = dy - center.y;
        dz = (*e).vec.z;
        dz = dz - center.z;
        d2 = (f32)(dx * dx);
        d2 = d2 + dy * dy;
        d2 = d2 + dz * dz;
        if (d2 < sq) {
            psvec_sub_scale_add(&e->vec, &center, r * lbl_8006D0E8(d2), &d, &e->vec);
        }
    next:
        i.value = i.value + 1;
        e = (fn_1_108A90_Entry *)((u8 *)e + 0x44);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_108A90 */

/* fzgx:begin fn_1_108EEC */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 w;
    f32 x;
    f32 y;
    f32 z;
} Quat;

typedef struct {
    f32 pad_0[12];
} Mtx;

typedef struct {
    u8 unk_0;
    u8 pad_1[0xF];
    Vec3 unk_10;
    u8 pad_1C[0x28];
} fn_1_108EEC_Node;

typedef struct {
    u8 pad_0[0x8];
    u8 *unk_8;
} fn_1_108EEC_L1;

typedef struct {
    u8 pad_0[0x150];
    fn_1_108EEC_L1 *unk_150;
} fn_1_108EEC_L0;

typedef struct {
    u8 pad_0[0xC];
    fn_1_108EEC_L0 *unk_c;
    u8 pad_10[8];
    u32 unk_18;
    u8 pad_1C[8];
    fn_1_108EEC_Node *unk_24;
} fn_1_108EEC_Arg;

extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E250(void *, void *);
extern void lbl_8006D668(void *);
extern void fn_8006E978(void *, Vec3 *, Vec3 *);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_108EEC(fn_1_108EEC_Arg *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    f32 fzgx_live;
    u8 *p;
    u32 i;
    fn_1_108EEC_Node *n;
    fn_1_108EEC_Arg *self = arg0;
    u32 j;
    fn_1_108EEC_Node *m;
    u8 *e;
    f32 rad2;
    f32 len2;
    struct { f32 value; } scale;
    f32 dx;
    f32 dy;
    f32 dz;
    Vec3 v;
    Vec3 c;
    Vec3 b;
    Quat q;
    Mtx mtx;

    rad2 = arg1 * arg1;
    e = (u8 *)self->unk_c->unk_150->unk_8 + arg5 * 0x18c;
    v.x = arg2;
    v.y = arg3;
    v.z = arg4;
    lbl_8006DBAC(e + 0x88);
    lbl_8006E1B0(&v, &v);
    p = (u8 *)self->unk_c->unk_150->unk_8 + arg6 * 0x18c;
    n = self->unk_24;
    i = 0;
    while (i < self->unk_18) {
        if (!(n->unk_0 & 1)) {
            b = n->unk_10;
            dx = n->unk_10.x - v.x;
            c.x = dx;
            len2 = (f32)(dx * dx);
            dy = n->unk_10.y - v.y;
            c.y = dy;
            len2 = len2 + dy * dy;
            dz = n->unk_10.z - v.z;
            c.z = dz;
            len2 = len2 + dz * dz;
            if (len2 < rad2) {
                scale.value = arg1 / lbl_8006D0B4(len2);
                fzgx_live = c.x;
                c.x = (f32)(fzgx_live * scale.value) + v.x;
                c.y = (f32)(c.y * scale.value) + v.y;
                c.z = (f32)(c.z * scale.value) + v.z;
                lbl_8006DBAC(p + 0x88);
                fn_8006E250(&c, &c);
                fn_8006E250(&b, &b);
                lbl_8006D668(&c);
                lbl_8006D668(&b);
                fn_8006E978(&q, &b, &c);
                mathutil_mtxA_from_quat(&q);
                lbl_8006DB74(&mtx);
                m = self->unk_24;
                j = 0;
                while (j < self->unk_18) {
                    c = m->unk_10;
                    lbl_8006DBAC(p + 0x88);
                    fn_8006E250(&c, &c);
                    lbl_8006DBAC(p + 0x88);
                    lbl_8006DFC4(&mtx);
                    lbl_8006E1B0(&c, &m->unk_10);
                    j++;
                    m++;
                }
            }
        }
        i++;
        n++;
    }
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_108EEC */

/* fzgx:begin fn_1_109114 */
#include "rel/main_rel/accessory.h"

typedef struct {
    u8 pad_0[0x150];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} fn_1_109114_AccessoryData;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    fn_1_109114_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} fn_1_109114_AccessoryObject;

void fn_1_109114(fn_1_109114_AccessoryObject *self) {
    void *base;
    u16 *item;
    int entry_index;
    int item_index;
    u8 *entry;
    
    base = fn_80077B14(self->unk_10);
    lbl_8006DBAC((u8 *)self->unk_C->unk_150->unk_8 +
                 ((u32 *)&lbl_1_data_3FFBC)[self->unk_8] * 0x18c + 0x88);
    entry = self->unk_24;
    entry_index = 0;
    while (entry_index < self->unk_18) {
        item = (u16 *)entry;
        item_index = 0;
        while (item_index < entry[2]) {
            fn_8006E250(entry + 0x10, (u8 *)base + item[2] * 0x40);
            item++;
            item_index++;
        }
        entry_index++;
        entry += 0x44;
    }
}
/* fzgx:end fn_1_109114 */

/* fzgx:begin fn_1_10A43C noprologue */
#include "types.h"

extern void fn_1_10846C(void);
extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20;
extern void fn_1_128884(void *, void *, s32);

typedef struct AccessoryEntry {
    u8 unk_0;
    u8 pad_1[0x13];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} AccessoryEntry;

typedef struct AccessoryObject {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} AccessoryObject;

void fn_1_10A43C(AccessoryObject *self) {
    int i;
    int j;
    AccessoryEntry *entry_i;
    AccessoryEntry *entry_j;

    if (self == NULL) {
        return;
    }

    fn_1_10846C();

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        if (entry_i->unk_0 & 1) {
            entry_i->unk_40 = lbl_1_rodata_7B1C;
            entry_i->unk_0 = 0;
        } else {
            entry_i->unk_40 = lbl_1_rodata_7B20;
            entry_i->unk_0 = 1;
        }
    }

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        for (j = i + 1, entry_j = (AccessoryEntry *)(self->unk_24 + i * 0x44 + 0x44); j < self->unk_18; j++, entry_j++) {
            if ((entry_i->unk_0 & 1) && !(entry_j->unk_0 & 1)) {
                fn_1_128884(entry_i, entry_j, sizeof(AccessoryEntry));
            }
        }
    }

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        for (j = i + 1, entry_j = (AccessoryEntry *)(self->unk_24 + i * 0x44 + 0x44); j < self->unk_18; j++, entry_j++) {
            if (entry_i->unk_0 == entry_j->unk_0) {
                if (entry_i->unk_18 > entry_j->unk_18) {
                    fn_1_128884(entry_i, entry_j, sizeof(AccessoryEntry));
                }
            }
        }
    }

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        for (j = i + 1, entry_j = (AccessoryEntry *)(self->unk_24 + i * 0x44 + 0x44); j < self->unk_18; j++, entry_j++) {
            if (entry_i->unk_0 == entry_j->unk_0) {
                if (entry_i->unk_14 < entry_j->unk_14 && entry_i->unk_18 > lbl_1_rodata_7B20 && entry_j->unk_18 > lbl_1_rodata_7B20) {
                    fn_1_128884(entry_i, entry_j, sizeof(AccessoryEntry));
                } else if (entry_i->unk_14 > entry_j->unk_14 && entry_i->unk_18 < lbl_1_rodata_7B20 && entry_j->unk_18 < lbl_1_rodata_7B20) {
                    fn_1_128884(entry_i, entry_j, sizeof(AccessoryEntry));
                }
            }
        }
    }
}
/* fzgx:end fn_1_10A43C */

/* fzgx:begin fn_1_10B344 */
extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern void fn_1_128884(void *, void *, int);
extern void fn_1_10846C(void);

typedef struct {
    u8 active;
    u8 _pad01[0x13];
    f32 field14;
    f32 field18;
    u8 _pad1c[0x24];
    f32 field40;
} Entry;

typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Entry *entries;
} Doc;

void fn_1_10B344(Doc *obj) {
    u32 i;
    u32 j;
    Entry *a;
    Entry *b;
    f32 zero;
    f32 neg;
    Entry * a_2;
    Entry * b_2;

    if (obj == 0) {
        return;
    }
    fn_1_10846C();
    neg = lbl_1_rodata_7B1C;
    zero = lbl_1_rodata_7B20;
    a = obj->entries;
    for (i = 0; i < obj->count; i++, a++) {
        if ((a->active & 1) != 0) {
            a->field40 = neg;
            a->active = 0;
        } else {
            a->field40 = zero;
            a->active = 1;
        }
    }
    a_2 = obj->entries;
    for (i = 0; i < obj->count; i++, a_2++) {
        b = obj->entries + i + 1;
        for (j = i + 1; j < obj->count; j++, b++) {
            if ((a_2->active & 1) != 0) {
                if ((b->active & 1) == 0) {
                    fn_1_128884(a_2, b, 0x44);
                }
            }
        }
    }
    a_2 = obj->entries;
    for (i = 0; i < obj->count; i++, a_2++) {
        b_2 = obj->entries + i + 1;
        for (j = i + 1; j < obj->count; j++, b_2++) {
            if (a_2->active == b_2->active) {
                if (a_2->field18 > b_2->field18) {
                    fn_1_128884(a_2, b_2, 0x44);
                }
            }
        }
    }
    a_2 = obj->entries;
    for (i = 0; i < obj->count; i++, a_2++) {
        b_2 = obj->entries + i + 1;
        for (j = i + 1; j < obj->count; j++, b_2++) {
            if (a_2->active == b_2->active) {
                if (a_2->field14 < b_2->field14 && a_2->field18 > lbl_1_rodata_7B20 && b_2->field18 > lbl_1_rodata_7B20) {
                    fn_1_128884(a_2, b_2, 0x44);
                } else if (a_2->field14 > b_2->field14 && a_2->field18 < lbl_1_rodata_7B20 && b_2->field18 < lbl_1_rodata_7B20) {
                    fn_1_128884(a_2, b_2, 0x44);
                }
            }
        }
    }
}
/* fzgx:end fn_1_10B344 */

/* fzgx:begin fn_1_10B7D8 */
// Initializes accessory data only when an accessory object is present.
void fn_1_10B7D8(void *accessory) {
    if (accessory != 0) {
        fn_1_10846C();
    }
}
/* fzgx:end fn_1_10B7D8 */

/* fzgx:begin fn_1_10C7B4 */
extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void fn_8006E250(void *, void *);

typedef struct {
    u8 pad_0[0x150];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} fn_1_10C7B4_AccessoryData;

typedef struct {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    fn_1_10C7B4_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} fn_1_10C7B4_AccessoryObject;

typedef union {
    u32 raw;
    f32 value;
} FloatVal;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Fn1_10C7B4_Triple;

typedef struct {
    u8 pad_0[0x10];
    FloatVal unk_10;
    FloatVal unk_14;
    FloatVal unk_18;
    FloatVal unk_1C;
    FloatVal unk_20;
    FloatVal unk_24;
    u8 pad_28[0xC];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
} AccessoryItem;

void fn_1_10C7B4(fn_1_10C7B4_AccessoryObject *self) {
    if (self != 0) {
        if (self->unk_10 != 0) {
            fn_80077B14(self->unk_10);
            if (self->unk_0 & 2) {
                AccessoryItem *item;
                u32 i;

                self->unk_0 &= ~2;
                lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                    ((u32 *)&lbl_1_data_3FFBC)[self->unk_8] * 0x18c + 0x88);
                lbl_8006DAEC();
                item = (AccessoryItem *)self->unk_24;
                i = 0;
                while (i < self->unk_18) {
                    lbl_8006DBE4();
                    lbl_8006E1B0((u8 *)item + 0x28, (u8 *)item + 0x10);
                    i++;
                    item = (AccessoryItem *)((u8 *)item + 0x44);
                }
                lbl_8006DC20();
            }

            {
                Fn1_10C7B4_Triple *src;
                u32 j;
                AccessoryItem *dst = (AccessoryItem *)self->unk_24;
                j = 0;
                src = (Fn1_10C7B4_Triple *)&lbl_1_bss_88B50;
                while (j < self->unk_18) {
                    *(Fn1_10C7B4_Triple *)&dst->unk_10 = src[j];
                    dst->unk_14.value = dst->unk_14.value - lbl_1_rodata_7BF8;
                    j++;
                    dst = (AccessoryItem *)((u8 *)dst + 0x44);
                }
            }

            {
                u32 k;
                AccessoryItem *dst = (AccessoryItem *)self->unk_24;
                for (k = 0; k < self->unk_18; k++) {
                    dst->unk_34 = dst->unk_10.value - dst->unk_1C.value;
                    dst->unk_38 = dst->unk_14.value - dst->unk_20.value;
                    dst->unk_3C = dst->unk_18.value - dst->unk_24.value;
                    dst = (AccessoryItem *)((u8 *)dst + 0x44);
                }
            }

            {
                u8 *base = (u8 *)fn_80077B14(self->unk_10);
                u8 *entry;
                int m;
                u32 n;
                u8 *p;

                lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                    ((u32 *)&lbl_1_data_3FFBC)[self->unk_8] * 0x18c + 0x88);
                entry = self->unk_24;
                n = 0;
                while (n < self->unk_18) {
                    p = entry;
                    for (m = 0; m < entry[2]; m++) {
                        fn_8006E250(entry + 0x10, base + *(u16 *)(p + 4) * 0x40);
                        p += 2;
                    }
                    n++;
                    entry += 0x44;
                }
            }
        }
    }
}
/* fzgx:end fn_1_10C7B4 */

/* fzgx:begin fn_1_10D2F0 noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3f;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} W3;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0xE];
    V3f v;
    W3 w1;
    W3 w2;
    u8 pad_34[0xC];
    f32 unk_40;
} Elem;

typedef struct {
    u32 a;
    u32 b;
    f32 d;
} Link;

typedef struct {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u32 pad_20;
    Elem *unk_24;
    Link *unk_28;
} Ctx;

typedef struct {
    u8 pad_0[0x64];
    f32 m1;
    f32 zero;
    u8 pad_6C[0xFC];
    f64 d015;
    f32 m05;
    u8 pad_174[4];
    f64 d045;
} Pool;

extern const Pool lbl_1_rodata_7AB8;
extern u32 lbl_801A6410;
extern u32 fn_1_10846C(Ctx *);
extern void fn_1_128884(Elem *, Elem *, int);
extern u8 lbl_1_data_40530[];
extern u32 fn_1_4630(u32, u32, void *, s32);
extern f32 fn_1_1289BC(const Elem *, const Elem *);

void fn_1_10D2F0(Ctx *arg0) {
    const Pool *pool = &lbl_1_rodata_7AB8;
    u32 i, j, k, pairs, q;
    Elem *p, *e, *a, *b, *c, *last;

    if (arg0 != 0) {
    fn_1_10846C(arg0);

    {
    Elem *initial_p;
    for (i = 0, initial_p = arg0->unk_24; i < arg0->unk_18; i++, initial_p++) {
        if (initial_p->unk_0 & 1) {
            initial_p->unk_0 = 0;
            if (initial_p->v.x > pool->d015) {
                initial_p->unk_40 = pool->m05;
                initial_p->unk_1 = 1;
            } else {
                initial_p->unk_40 = pool->m1;
                initial_p->unk_1 = 2;
            }
        } else {
            initial_p->unk_40 = pool->zero;
            initial_p->unk_0 = 1;
            if (initial_p->v.x > pool->d045) {
                initial_p->unk_1 = 0;
            } else {
                initial_p->unk_1 = 3;
            }
        }
    }

    }

    {
    Elem *first_e;
    for (i = 0, p = arg0->unk_24; i < arg0->unk_18; i++, p++) {
        for (j = i + 1, first_e = &arg0->unk_24[i] + 1; j < arg0->unk_18; j++, first_e++) {
            if (p->unk_1 > first_e->unk_1) {
                fn_1_128884(p, first_e, 0x44);
            }
        }
    }

    }

    for (i = 0, p = arg0->unk_24; i < arg0->unk_18; i++, p++) {
        for (j = i + 1, e = &arg0->unk_24[i] + 1; j < arg0->unk_18; j++, e++) {
            if (p->unk_1 == e->unk_1 && p->v.z < e->v.z) {
                fn_1_128884(p, e, 0x44);
            }
        }
    }

    for (i = 0, p = arg0->unk_24; i < arg0->unk_18; i++, p++) {
        for (j = i + 1, e = &arg0->unk_24[i] + 1; j < arg0->unk_18; j++, e++) {
            if (p->unk_1 == e->unk_1) {
                if (p->v.z > pool->zero && e->v.z > pool->zero) {
                        if (p->v.y > e->v.y) {
                            fn_1_128884(p, e, 0x44);
                        }
                } else {
                    /* Reload once for both negative-side tests, as retail does. */
                    f32 negative_zero = *(const volatile f32 *)&pool->zero;
                    if (p->v.z < negative_zero && e->v.z < negative_zero) {
                        if (p->v.y < e->v.y) {
                            fn_1_128884(p, e, 0x44);
                        }
                    }
                }
            }
        }
    }

    b = arg0->unk_24;
    a = b;
    for (k = 0; k < arg0->unk_18; k++) {
        if (a->unk_1 == 1) {
            break;
        }
        a++;
    }
    for (k = 0; k < arg0->unk_18; k++) {
        if (b->unk_1 == 3) {
            break;
        }
        b++;
    }
    a->unk_40 = b->unk_40;
    a->unk_0 = b->unk_0;
    a->w2 = b->w2;
    a->v = b->v;
    a->w1 = b->w1;

    c = arg0->unk_24;
    for (k = 0; k < arg0->unk_18; k++) {
        if (c->unk_1 == 2) {
            break;
        }
        c = c + 1;
    }
    last = &arg0->unk_24[arg0->unk_18 - 1];
    c--;
    c->unk_40 = last->unk_40;
    c->unk_0 = last->unk_0;
    c->w2 = last->w2;
    c->v = last->v;
    c->w1 = last->w1;

    q = arg0->unk_18 >> 2;
    arg0->unk_1C = q * 3 + (q - 1) * 4;
    arg0->unk_28 = (Link *)fn_1_4630(lbl_801A6410, arg0->unk_1C * 12, lbl_1_data_40530, 0xDF0);

    pairs = 0;
    for (i = 0, p = arg0->unk_24; i < arg0->unk_18 - 1; i++, p++) {
        if (p->unk_1 == (*((p) + (1))).unk_1) {
            (*((arg0->unk_28) + (pairs))).a = (u32)p;
            (*((arg0->unk_28) + (pairs))).b = (u32)(p + 1);
            (*((arg0->unk_28) + (pairs))).d = fn_1_1289BC(p, p + 1);
            pairs++;
        }
    }
    for (i = 0, p = arg0->unk_24; i < arg0->unk_18 - q; i++, p++) {
        (*((arg0->unk_28) + (pairs))).a = (u32)p;
        (*((arg0->unk_28) + (pairs))).b = (u32)(p + q);
        (*((arg0->unk_28) + (pairs))).d = fn_1_1289BC(p, p + q);
        pairs++;
    }
    }
}
/* fzgx:end fn_1_10D2F0 */

/* fzgx:begin fn_1_1154D0 */
typedef struct {
    u8 active;
    u8 _pad01[0x33];
    f32 field34;
    u8 _pad38[4];
    f32 field3c;
    f32 field40;
} Fn1154D0Entry;

typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Fn1154D0Entry *entries;
} Fn1154D0Object;

void fn_1_1154D0(Fn1154D0Object *obj) {
    f32 inactive_value;
    f32 active_value;
    u32 i;
    Fn1154D0Entry *entry;

    if (obj != 0) {
        fn_1_10846C();
        active_value = lbl_1_rodata_7B1C;
        inactive_value = lbl_1_rodata_7B20;
        entry = obj->entries;
        for (i = 0; i < obj->count; i++, entry++) {
            if ((entry->active & 1) != 0) {
                entry->active = 0;
                entry->field40 = active_value;
            } else {
                entry->active = 1;
                entry->field40 = inactive_value;
                entry->field34 = inactive_value;
                entry->field3c = inactive_value;
            }
        }
    }
}
/* fzgx:end fn_1_1154D0 */

/* fzgx:begin fn_1_115B58 */
typedef struct {
    u8 active;
    u8 _pad01[0x33];
    f32 field34;
    u8 _pad38[4];
    f32 field3c;
    f32 field40;
} Fn115B58Entry;

typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Fn115B58Entry *entries;
} Fn115B58Object;

void fn_1_115B58(Fn115B58Object *obj) {
    f32 inactive_value;
    f32 active_value;
    u32 i;
    Fn115B58Entry *entry;

    if (obj != 0) {
        fn_1_10846C();
        active_value = lbl_1_rodata_7B1C;
        inactive_value = lbl_1_rodata_7B20;
        entry = obj->entries;
        for (i = 0; i < obj->count; i++, entry++) {
            if ((entry->active & 1) != 0) {
                entry->active = 1;
                entry->field40 = active_value;
            } else {
                entry->active = 0;
                entry->field40 = inactive_value;
                entry->field34 = inactive_value;
                entry->field3c = inactive_value;
            }
        }
    }
}
/* fzgx:end fn_1_115B58 */

/* fzgx:begin fn_1_1166EC */
typedef struct {
    u8 active;
    u8 _pad01[0x33];
    f32 field34;
    u8 _pad38[4];
    f32 field3c;
    f32 field40;
} Fn1166ECEntry;

typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Fn1166ECEntry *entries;
} Fn1166ECObject;

void fn_1_1166EC(Fn1166ECObject *obj) {
    f32 inactive_value;
    f32 active_value;
    u32 i;
    Fn1166ECEntry *entry;

    if (obj != 0) {
        fn_1_10846C();
        active_value = lbl_1_rodata_7B1C;
        inactive_value = lbl_1_rodata_7B20;
        entry = obj->entries;
        for (i = 0; i < obj->count; i++, entry++) {
            if ((entry->active & 1) != 0) {
                entry->active = 1;
                entry->field40 = active_value;
            } else {
                entry->active = 0;
                entry->field40 = inactive_value;
                entry->field34 = inactive_value;
                entry->field3c = inactive_value;
            }
        }
    }
}
/* fzgx:end fn_1_1166EC */

/* fzgx:begin fn_1_125CE8 noprologue */
#include "types.h"

extern f32 lbl_1_rodata_7AB8[];
extern void fn_1_10846C(void *);

typedef struct {
    u8 active;
    u8 pad_1[0x0f];
    f32 value;
    u8 pad_14[0x2c];
    f32 result;
} fn_1_125CE8_AccessoryEntry;

typedef struct {
    u8 pad_0[0x18];
    u32 count;
    u8 pad_1c[0x08];
    fn_1_125CE8_AccessoryEntry *entries;
} fn_1_125CE8_AccessoryData;

void fn_1_125CE8(fn_1_125CE8_AccessoryData *data) {
    f32 *constants;
    u32 i;
    fn_1_125CE8_AccessoryEntry *entry;
    f32 min_value;
    f32 max_value;
    f32 range;
    f32 value_off;
    f32 value_on;

    constants = lbl_1_rodata_7AB8;
    if (data != 0) {
        fn_1_10846C(data);

        i = 0;
        entry = data->entries;
        value_on = constants[25];
        value_off = constants[26];
        while (i < data->count) {
            if ((entry->active & 1) != 0) {
                entry->result = value_on;
                entry->active = 0;
            } else {
                entry->result = value_off;
                entry->active = 1;
            }
            i++;
            entry++;
        }

        entry = data->entries;
        min_value = constants[329];
        max_value = constants[330];
        i = 0;
        while (i < data->count) {
            if (entry->value < min_value) {
                min_value = entry->value;
            }
            if (entry->value > max_value) {
                max_value = entry->value;
            }
            i++;
            entry++;
        }

        range = max_value - min_value;
        value_on = constants[25];
        entry = data->entries;
        i = 0;
        while (i < data->count) {
            entry->result = value_on +
                (entry->value - min_value) / range;
            i++;
            entry++;
        }
    }
}
/* fzgx:end fn_1_125CE8 */

/* fzgx:begin fn_1_127FB8 */
extern void fn_1_10846C(void);
extern f32 lbl_1_rodata_7B20;

typedef struct {
    u8 active;
    u8 _pad01[0x3f];
    f32 value;
} Fn127FB8Entry;

typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Fn127FB8Entry *entries;
} Fn127FB8Object;

void fn_1_127FB8(Fn127FB8Object *obj) {
    f32 value;
    u32 i;
    Fn127FB8Entry *entry;

    if (obj != 0) {
        fn_1_10846C();
        entry = obj->entries;
        value = lbl_1_rodata_7B20;
        i = 0;
        while (i < obj->count) {
            if ((entry->active & 1) != 0) {
                entry->active = 0;
                entry->value = value;
            } else {
                entry->active = 1;
                entry->value = value;
            }
            i++;
            entry++;
        }
    }
}
/* fzgx:end fn_1_127FB8 */

/* fzgx:begin fn_1_1286F4 */
extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void fn_8006E250(void *, void *);
extern void fn_1_10846C(void);
extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern s32 fn_1_14D670(void);
extern u32 lbl_801A66A0;
extern s32 fn_1_86678(s32 arg);
extern u32 lbl_1_bss_897AC[1741];
extern u32 lbl_1_bss_897A4;
extern u32 lbl_1_bss_897A8;
extern void * lbl_801A6410;
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DC20(void);
extern const f64 lbl_1_rodata_7BF8;
extern void fn_80008BA8(void *dst, void *src, int size);
extern void *fn_1_45D0(void *manager, int type, void *data, int code);
extern void fn_1_105744(void);
extern void fn_1_106DB4(void);
extern void fn_1_9D0EC(u32, u32, void*, void*);
extern void fn_1_103AA8(void);
extern u32 lbl_1_bss_85288[2];
extern void fn_1_103AD4(void);
extern void fn_1_105768(void);
extern void fn_1_9E5B8(void *);
extern f32 lbl_1_rodata_7B58[40];
extern u8 lbl_1_rodata_8058[16];
extern int mathutil_mtxA_rotate_z__fzgx_offset_C();
extern struct fn_1_129D9C_system *lbl_801A6D00;
extern void lbl_8006DCA4(void);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006D7B0(void);
extern void lbl_8006D668(void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006DB74(void *);
extern void fn_80072558(void);
extern void fn_80083DB0(void *, void *);
extern void *fn_1_55210(void *);
extern void *fn_1_548AC(u32);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void fn_1_12A0E0(void);

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.009999999776482582f;
}
static const unsigned long fzgx_pool_table5[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1e-07;
}
static const unsigned long fzgx_pool_table7[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 0.0013611111376020642;
    s = 0.0027222223579883575f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 2.0f;
    s = 1.1920928955078125e-07f;
    s = -1.0000001192092896f;
}
static const unsigned long fzgx_pool_table13[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.0013611111789941788f;
    s = -0.0027222223579883575f;
    s = 9.999999747378752e-05f;
    s = 1.0f;
    s = 0.00039999998989515007f;
    s = 0.02500000037252903f;
    s = 0.004224999807775021f;
    d = 0.0749999976158142;
    d = 0.3;
    s = -0.01899999938905239f;
    s = 0.05700000002980232f;
    s = 0.0009609999833628535f;
}
static const unsigned long fzgx_pool_table15[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04099999949336052;
    d = -1.0;
    s = 0.75f;
    s = -0.25f;
}
static const unsigned long fzgx_pool_table17[9] = {0xBF800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3E0D4FDF, 0x3B83126F, 0x3DED9168};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.06499999761581421f;
    s = 0.06500999629497528f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 8.0;
    s = 0.00390625f;
}
static const unsigned long fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05;
    d = 0.0027222223579883575;
    d = 0.02;
    d = 0.0001;
}
static const unsigned long fzgx_pool_table23[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.04899999871850014f;
    s = 0.002500000176951289f;
    s = 0.05000000074505806f;
    s = -0.125f;
}
static const unsigned long fzgx_pool_table25[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.015;
    s = -0.5f;
}
static const unsigned long fzgx_pool_table27[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.045;
    s = 0.00022499999613501132f;
}
static const unsigned long fzgx_pool_table29[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    d = 0.8;
    d = 0.5;
    s = 0.029999999329447746f;
    s = 0.0010000000474974513f;
    s = 0.11500000208616257f;
    s = 0.02016400173306465f;
    s = 0.1420000046491623f;
    s = 0.017160998657345772f;
    s = 0.13099999725818634f;
    s = 0.07999999821186066f;
    s = 0.02250000089406967f;
    s = 0.15000000596046448f;
    s = 0.20000000298023224f;
    s = 0.04000000283122063f;
    s = 0.027000000700354576f;
    s = 0.016384001821279526f;
    s = 0.12800000607967377f;
    s = 0.14100000262260437f;
    s = 0.016899999231100082f;
    s = 0.12999999523162842f;
    s = 0.050999999046325684f;
    s = 0.014161000959575176f;
    s = 0.11900000274181366f;
    s = 0.18299999833106995f;
    s = 0.013225000351667404f;
    s = 0.2980000078678131f;
    s = 0.800000011920929f;
    s = 9.0f;
    s = 0.0012000000569969416f;
    s = 32767.0f;
    s = 0.004800000227987766f;
    s = 0.0006000000284984708f;
    s = -32768.0f;
    s = 65536.0f;
    s = 39.0f;
    s = 0.0020000000949949026f;
    s = 29.0f;
    s = -0.0010000000474974513f;
    s = 0.550000011920929f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table31[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 9.999999747378752e-06f;
    s = 0.00279999990016222f;
    s = 0.002300000051036477f;
    s = 0.021904001012444496f;
    s = 0.14800000190734863f;
    s = 0.02890000119805336f;
    s = 0.17000000178813934f;
    s = 0.010000000707805157f;
    d = 1.0;
    s = 32768.0f;
    s = 12.0f;
    s = 0.11999999731779099f;
    s = 0.07000000029802322f;
    s = -0.03700000047683716f;
    s = 0.09000000357627869f;
    s = 0.07699999958276749f;
    s = 0.1120000034570694f;
    s = 0.18000000715255737f;
    s = -0.013000000268220901f;
    s = 0.0689999982714653f;
    s = -0.0020000000949949026f;
    s = 0.020999999716877937f;
    s = -0.020999999716877937f;
    s = 0.05999999865889549f;
    s = 0.07500000298023224f;
    s = 0.08500000089406967f;
    s = 0.09200000017881393f;
    s = 0.05900000035762787f;
    s = 0.054999999701976776f;
    s = 0.07400000095367432f;
    s = 0.11699999868869781f;
    s = -0.04800000041723251f;
    s = 0.04800000041723251f;
    s = 0.03200000151991844f;
    s = 0.06599999964237213f;
    s = -0.019999999552965164f;
    s = 0.0989999994635582f;
    s = 0.13300000131130219f;
    s = -0.05000000074505806f;
    s = 0.07100000232458115f;
    s = 0.0949999988079071f;
    s = -0.008999999612569809f;
    s = 0.006000000052154064f;
    s = 0.04500000178813934f;
    s = 0.04399999976158142f;
    s = 0.07199999690055847f;
    s = 0.09700000286102295f;
    s = -0.014999999664723873f;
    s = 0.11400000005960464f;
    s = 0.3109999895095825f;
    s = 0.039000000804662704f;
    s = -0.22100000083446503f;
    s = 0.5379999876022339f;
    s = 0.08100000023841858f;
    s = -0.4699999988079071f;
    s = 0.08399999886751175f;
    s = 0.10499999672174454f;
    s = 0.03099999949336052f;
    s = 0.10599999874830246f;
    s = -0.03099999949336052f;
}
static const unsigned long fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const unsigned long *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.76;
    s = 0.04699999839067459f;
    s = 0.1080000028014183f;
    s = 0.0860000029206276f;
    s = 0.06800000369548798f;
    s = 0.003000000026077032f;
    s = 0.0035000001080334187f;
    s = 0.004100000020116568f;
}
static const unsigned long fzgx_pool_table35[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const unsigned long *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0004083333412806193;
    d = 0.0008166666825612386;
}
static const unsigned long fzgx_pool_table37[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const unsigned long *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime38(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.003599999938160181f;
    s = 0.12399999797344208f;
    s = 0.00774399982765317f;
    s = 0.08799999952316284f;
    s = 0.06400000303983688f;
    s = 0.006888999603688717f;
    s = 0.08299999684095383f;
    s = 0.01600000075995922f;
    s = 0.00608400022611022f;
    s = 0.07800000160932541f;
    s = 0.03700000047683716f;
}
static const unsigned long fzgx_pool_table39[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const unsigned long *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime40(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.11999999731779099f;
}
static const unsigned long fzgx_pool_table41[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const unsigned long *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 6.0f;
    s = -0.699999988079071f;
    s = 0.8999999761581421f;
    s = 1.2000000476837158f;
    s = 0.004356000106781721f;
    s = 0.003721000161021948f;
    s = 0.061000000685453415f;
    s = 0.005041000433266163f;
    s = 0.5910000205039978f;
    s = 0.2540160119533539f;
    s = 0.5040000081062317f;
    s = -0.017999999225139618f;
    s = -0.014000000432133675f;
    s = 0.017999999225139618f;
    s = 0.06199999898672104f;
    s = 0.003249000059440732f;
    s = -0.024000000208616257f;
    s = 0.3499999940395355f;
}
static const unsigned long fzgx_pool_table43[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep43(void) { const unsigned long *volatile cp; cp = fzgx_pool_table43; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime44(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0499999523162842;
    d = 0.7;
}
static const unsigned long fzgx_pool_table45[15] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep45(void) { const unsigned long *volatile cp; cp = fzgx_pool_table45; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime46(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.004000000189989805f;
    s = -0.004000000189989805f;
    s = 0.004900000058114529f;
    s = 0.2529999911785126f;
    s = 0.047523997724056244f;
    s = 0.21799999475479126f;
    s = -0.2529999911785126f;
    s = 0.1224999949336052f;
    s = 0.010201000608503819f;
    s = 0.10100000351667404f;
    s = -0.6420000195503235f;
    s = 0.5490000247955322f;
    s = 0.5055210590362549f;
    s = 0.7110000252723694f;
    s = 350.0f;
    s = 30.0f;
    s = 0.003800000064074993f;
    s = 0.001500000013038516f;
    s = 0.0005000000237487257f;
    s = 0.0820000022649765f;
    s = 0.01040400005877018f;
    s = 0.10199999809265137f;
    s = 0.005625000223517418f;
    s = -0.02800000086426735f;
    s = 0.26499998569488525f;
    s = 0.01209999993443489f;
    s = 0.10999999940395355f;
    s = 0.006399999838322401f;
    s = -0.02500000037252903f;
    s = 0.1379999965429306f;
    s = 0.011024999432265759f;
    d = 0.59;
    d = 0.4;
    s = -0.01600000075995922f;
    s = 0.006560999900102615f;
    s = -0.00800000037997961f;
    s = 0.03799999877810478f;
    s = 0.004760999698191881f;
    s = 100000.0f;
    s = -100000.0f;
    s = 0.9800000190734863f;
    d = 0.98;
    s = 0.949999988079071f;
    s = 0.12700000405311584f;
    s = 0.021024998277425766f;
    s = 0.14499999582767487f;
    s = 0.00722500029951334f;
    s = 0.005775999743491411f;
    s = 0.07599999755620956f;
    s = 2.2249999046325684f;
    s = 4.596736431121826f;
    s = 2.1440000534057617f;
    s = -0.023000000044703484f;
    s = 0.03400000184774399f;
    s = 0.06700000166893005f;
    s = -0.007000000216066837f;
    s = 0.10300000011920929f;
    s = 0.004999999888241291f;
    s = 0.04100000113248825f;
    s = -0.012000000104308128f;
    s = 0.09600000083446503f;
    s = 0.03999999910593033f;
    s = 0.03500000014901161f;
    s = 0.014000000432133675f;
    s = -0.00019999999494757503f;
    s = -9.999999747378752e-05f;
    s = 0.00019999999494757503f;
    s = 1.6000001778593287e-05f;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } Vec3f;
extern u32 lbl_801A66A0;
extern u32 lbl_801A63C0;
extern Vec3f lbl_1_bss_88B40;
extern f32 lbl_8006D0B4(f32);

#pragma opt_dead_assignments off
void fn_1_1286F4(Vec3f *out) {
    if ((lbl_801A66A0 & 0xF) == 0) {
        u32 c;
        u32 b;
        u32 a;
        f32 fx;
        f32 fy;
        f32 fz;
        f32 len;
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        a = lbl_801A63C0;
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        b = lbl_801A63C0;
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        c = lbl_801A63C0;
        fx = -0.00019999999494757503f + (f32)(0.00039999998989515007f * ((f32)(s32)((a >> 16) & 0x7FFF) / 32767.0f));
        lbl_1_bss_88B40.x = fx;
        fy = -9.999999747378752e-05f + (f32)(0.00019999999494757503f * ((f32)(s32)((b >> 16) & 0x7FFF) / 32767.0f));
        lbl_1_bss_88B40.y = fy;
        fz = -0.00019999999494757503f + (f32)(0.00039999998989515007f * ((f32)(s32)((c >> 16) & 0x7FFF) / 32767.0f));
        lbl_1_bss_88B40.z = fz;
        len = (f32)(fx * fx) + fy * fy + fz * fz;
        if (len > 1.6000001778593287e-05f) {
            f32 s = 0.004000000189989805f / lbl_8006D0B4(len);
            lbl_1_bss_88B40.x *= s;
            lbl_1_bss_88B40.y *= s;
            lbl_1_bss_88B40.z *= s;
        }
    }
    *out = lbl_1_bss_88B40;
}
/* fzgx:end fn_1_1286F4 */

/* fzgx:begin fn_1_128884 */
extern void fn_1_46B4(void *manager, void *object, void *data, int code);

void fn_1_128884(void *arg0, void *arg1, int type) {
    u8 tmp1[0x44];
    u8 tmp2[0x0c];
    void *object;

    switch (type) {
    case 0x44: {
        u32 size = type;
        fn_80008BA8(tmp1, arg0, size);
        fn_80008BA8(arg0, arg1, size);
        fn_80008BA8(arg1, tmp1, size);
        break;
    }
    case 0x0c: {
        u32 size = type;
        fn_80008BA8(tmp2, arg0, size);
        fn_80008BA8(arg0, arg1, size);
        fn_80008BA8(arg1, tmp2, size);
        break;
    }
    default:
        object = fn_1_45D0(lbl_801A6410, type, &lbl_1_data_40530, 0x308d);
        fn_80008BA8(object, arg0, type);
        fn_80008BA8(arg0, arg1, type);
        fn_80008BA8(arg1, object, type);
        fn_1_46B4(lbl_801A6410, object, &lbl_1_data_40530, 0x3091);
        break;
    }
}
/* fzgx:end fn_1_128884 */

/* fzgx:begin fn_1_1289BC */
#include "rel/main_rel/cloth.h"

extern u32 fn_1_46B4(u32, u32, void *, u32);

typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

f32 fn_1_1289BC(const Point1024C4 *a, const Point1024C4 *b) {
    f32 dz = a->v[2] - b->v[2];
    f32 dy = a->v[1] - b->v[1];
    f32 dx = a->v[0] - b->v[0];
    f32 result = dx * dx;
    result += dy * dy;
    result += dz * dz;
    return result;
}
/* fzgx:end fn_1_1289BC */

/* fzgx:begin fn_1_1289F0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/accessory.h"
#include "psvec.h"

#pragma fp_contract on
extern f32 lbl_1_rodata_7B58[40];
extern f32 lbl_8006D6FC(void *, void *);
extern f32 lbl_8006D0B4(f32);

typedef struct Vec1289F0 { f32 x, y, z; } Vec1289F0;
#pragma opt_common_subs off
f32 fn_1_1289F0(Vec1289F0 *a, Vec1289F0 *b, Vec1289F0 *c) {
    Vec1289F0 ac;
    Vec1289F0 ab;
    f32 cosine;
    f32 length;
    psvec_sub(c, a, &ac);
    psvec_sub(b, a, &ab);
    ab.x = lbl_8006D6FC(&ac, &ab);
    cosine = ac.x * ac.x;
    cosine = ac.y * ac.y + cosine;
    cosine = ac.z * ac.z + cosine;
    length = lbl_8006D0B4(cosine);
    return length * lbl_8006D0B4((*((lbl_1_rodata_7B58) + (0))) - (f32)(ab.x * ab.x));
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_1289F0 */

/* fzgx:begin fn_1_128AAC */
f32 fn_1_128AAC(s32 exponent, f32 value) {
    s32 sign;
    s32 n;
    f32 result = 1.0f;

    sign = exponent >> 31;
    n = sign ^ exponent;
    n -= sign;
    while (n != 0) {
        if (n & 1) {
            result *= value;
        }
        value *= value;
        n >>= 1;
    }
    if (exponent >= 0) {
        return result;
    }
    return lbl_1_rodata_7B58[0] / result;
}
/* fzgx:end fn_1_128AAC */

/* fzgx:begin fn_1_128B00 */
s32 fn_1_128B00(s16 value) {
    switch (value) {
    case 0:
        return 7;
    case 1:
        return 10;
    case 2:
        return 4;
    default:
        return fn_1_14D670();
    }
}
/* fzgx:end fn_1_128B00 */

/* fzgx:begin fn_1_128DD8 */
// Return the table index for a matching accessory value, or the first unused index.
u8 fn_1_128DD8(u8 value) {
    u8 *table;
    u8 index;
    u8 entry;

    table = (u8 *)&lbl_1_data_405C0;
    for (index = 0; index < 6; index++) {
        entry = table[index];
        if (entry == value) {
            return index;
        }
    }

    return index;
}
/* fzgx:end fn_1_128DD8 */

/* fzgx:begin fn_1_128E10 */
#pragma pack(push, 1)
typedef struct {
    u32 word_0;
    u32 word_4;
    u32 word_8;
    u16 half_c;
    u8 byte_e;
} LookupTable;
#pragma pack(pop)

u8 fn_1_128E10(u8 value) {
    LookupTable table = *(LookupTable *)lbl_1_rodata_8058;
    u8 i;
    u8 entry;

    i = 1;
    while (i < 15) {
        entry = ((u8 *)&table)[i];
        if ((s32)entry == (s32)(value & 0xFF)) {
            break;
        }
        i++;
    }
    if (i == 15) {
        i = 0;
    }
    return i;
}
/* fzgx:end fn_1_128E10 */

/* fzgx:begin fn_1_128E8C */
typedef struct {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u8 field_4;
    u8 pad_5[3];
    u8 field_8;
    u8 field_9;
    u16 field_a;
    u8 field_c[3];
    u8 field_f;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 pad_13;
    u16 field_14;
    u8 pad_16[2];
    u16 field_18;
} FnData;

void fn_1_128E8C(u32 unused, FnData *data) {
    data->field_0 = 1;
    data->field_1 = 2;
    data->field_2 = 3;
    data->field_4 = 0;
    data->field_8 = lbl_801A66A0 % 255;
    data->field_9 = 1;
    data->field_f = 2;
    data->field_a = 1234;
    data->field_11 = 5;
    data->field_12 = 6;
    data->field_14 = 7;
    data->field_10 = 4;
    data->field_18 = 982;
}
/* fzgx:end fn_1_128E8C */

/* fzgx:begin fn_1_128F10 noprologue */
#include "types.h"

extern const f32 lbl_1_rodata_8068;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 unk_20;
} Obj_1_bss_89760;


typedef struct lbl_1_bss_89760_t {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} lbl_1_bss_89760_t;

typedef struct lbl_1_bss_89770_t {
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} lbl_1_bss_89770_t;

typedef struct lbl_1_bss_89780_t {
    u8 unk_20;
    u8 pad_1[0x1f];
} lbl_1_bss_89780_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_89760_t fzgx_obj_lbl_1_bss_89760;
lbl_1_bss_89770_t fzgx_obj_lbl_1_bss_89770;
lbl_1_bss_89780_t lbl_1_bss_89780;
u32 fzgx_obj_lbl_1_bss_897A0;
u32 lbl_1_bss_897A4;
u32 lbl_1_bss_897A8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_89760;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_89770;
    s = *(u8 *)&lbl_1_bss_89780;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897A0;
    s = *(u8 *)&lbl_1_bss_897A4;
    s = *(u8 *)&lbl_1_bss_897A8;
}
#pragma section code_type ".text"

void fn_1_128F10(void) {
    fzgx_obj_lbl_1_bss_89760.unk_0 = 0;
    fzgx_obj_lbl_1_bss_89770.unk_10 = lbl_1_rodata_8068;
    fzgx_obj_lbl_1_bss_89760.unk_4 = 0;
    fzgx_obj_lbl_1_bss_89770.unk_14 = lbl_1_rodata_8068;
    fzgx_obj_lbl_1_bss_89760.unk_8 = 0;
    fzgx_obj_lbl_1_bss_89770.unk_18 = lbl_1_rodata_8068;
    fzgx_obj_lbl_1_bss_89760.unk_C = 0;
    fzgx_obj_lbl_1_bss_89770.unk_1C = lbl_1_rodata_8068;
    lbl_1_bss_89780.unk_20 = 0;
}
/* fzgx:end fn_1_128F10 */

/* fzgx:begin fn_1_128F54 */
extern s8 fn_1_86624(void);
extern u32 fn_1_58C4(void);
extern s32 fn_1_6B48(u32 index);
extern const f32 lbl_1_rodata_8068;
extern f32 lbl_1_rodata_806C[61];
extern f32 fn_1_8CAF4(s16, u32);

void fn_1_128F54(void) {
    struct { u32 value; } inner_count;
    u32 outer_count;
    struct { s16 value; } item;
    u32 i;
    u32 j;
    int found;
    f32 limit;
    u32 spell_call;

{
    struct { u32 value; } fzgx_loop_inner_count_553;
    u32 fzgx_loop_outer_count_553;
    spell_call = fn_1_86624();

    fzgx_loop_inner_count_553.value = spell_call;
    fzgx_loop_outer_count_553 = fn_1_58C4();
    i = 0;
    while (i < fzgx_loop_outer_count_553) {
        item.value = fn_1_6B48(i);
        if ((u32)item.value == 0xFFFFFFFF) {
            ((f32 *)&lbl_1_bss_89770)[i] = lbl_1_rodata_8068;
            ((u32 *)&lbl_1_bss_89760)[i] = 0;
        } else {
{
    int fzgx_loop_found_1003;
    f32 fzgx_loop_limit_1003;
            fzgx_loop_found_1003 = 0;
            fzgx_loop_limit_1003 = lbl_1_rodata_806C[0];
            j = 0;
            while (j < fzgx_loop_inner_count_553.value) {
                if (item.value != j) {
                    f32 value = fn_1_8CAF4(item.value, j);
                    if (!(value > fzgx_loop_limit_1003)) {
                        if (!fzgx_loop_found_1003) {
                            ((f32 *)&lbl_1_bss_89770)[i] = value;
                            fzgx_loop_found_1003 = 1;
                            ((u32 *)&lbl_1_bss_89760)[i] = j;
                        }
                        if (value > ((f32 *)&lbl_1_bss_89770)[i]) {
                            ((u32 *)&lbl_1_bss_89760)[i] = j;
                            ((f32 *)&lbl_1_bss_89770)[i] = value;
                        }
                    }
                }
                j++;
            }
    found = fzgx_loop_found_1003;
    limit = fzgx_loop_limit_1003;
}
            if (!found) {
                ((u32 *)&lbl_1_bss_89760)[i] = 0;
                ((f32 *)&lbl_1_bss_89770)[i] = lbl_1_rodata_8068;
            }
        }
        i++;
    }
    inner_count.value = fzgx_loop_inner_count_553.value;
    outer_count = fzgx_loop_outer_count_553;
}
}
/* fzgx:end fn_1_128F54 */

/* fzgx:begin fn_1_12999C noprologue */
#include "types.h"

extern s16 lbl_1_bss_960;
typedef struct { u8 pad_0[8]; u32 unk_8; } Obj_1_bss_38458_Target;
extern Obj_1_bss_38458_Target *lbl_1_bss_38458;
extern u32 lbl_1_data_405EC;
struct Vec3 { f32 x; f32 y; f32 z; };
struct Obj_t {
 u32 unk_0; u8 pad_4[0x148]; u8 unk_14C[4]; u8 pad_150[0x325];
 s8 unk_475; u8 pad_476[0x26]; u32 unk_49C;
};
struct Ref { u8 pad_0[0x10]; u8 unk_10; u8 pad_11[7]; };
struct E30 { u8 pad[0x30]; };
struct Pool {
 f32 f0; u8 pad_4[0xC]; f32 f10; u8 pad_14[0x64];
 u32 v78; u32 v7C; u32 v80; u32 v84; u32 v88; u32 v8C; s32 v90; u32 v94;
};
extern struct Pool lbl_1_rodata_8068;
extern struct E30 lbl_1_bss_7CA58[168];
extern s8 lbl_1_bss_9C[8];
extern u8 lbl_1_bss_89780[32];
extern s32 lbl_801A66B4;
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_F2F34(void);
extern void fn_1_3EF14(void *);
extern f32 fn_1_A71AC(void);
extern s32 fn_1_40B20(void);
extern void *fn_1_86254(s32);
extern u32 fn_1_5910(void);
extern s32 fn_1_12A24C(s8);
extern void fn_1_862A8(s32, struct Vec3 *);
extern u8 fn_1_D66BC(void *, void *);
extern void fn_1_129D9C(void *, void *, void *, void *, s32, s32, s32, f32);
extern s32 fn_1_F1D60(void);
extern s32 fn_1_4C10(void);
extern u8 *fn_1_F1C54(u32);
extern u32 fn_1_EB0B0(void);
extern u8 *fn_80083970(u8 *, const u8 *);
void fn_1_12999C(void) {
 s32 i;
 u32 t3C[3];
 u32 t2C[4];
 struct Vec3 v20;
 struct Vec3 v14;
 struct Vec3 v8;
 struct Ref o48;
 u8 buf[5296];
 struct Pool *p = (struct Pool *)&lbl_1_rodata_8068;
 u8 *sub;
 s32 n;
 s32 mode = 1;
 struct Obj_t *o;
 f32 val;
 s8 idx;
 u8 self;
 u32 j;
 u8 *q;
 f32 lab_t7;
 t3C[0]=p->v78; t3C[1]=p->v7C; t3C[2]=p->v80;
 t2C[0]=p->v84; t2C[1]=p->v88; t2C[2]=p->v8C; t2C[3]=p->v90;
 if (lbl_1_bss_960 != 2 && lbl_1_bss_960 != 9) return;
 if (fn_1_3F0C8() != 41) {
 switch (fn_1_3F0C8()) {
 case 40: break;
 /* Unsupported machine: branch to the shared function exit. */
 default: goto end;
 }
 }
 {
 if (fn_1_F2F34() != 0) return;
 fn_1_3EF14(buf);
 val=fn_1_A71AC();
 n=fn_1_40B20();
 if (lbl_1_bss_960 == 9) mode=lbl_1_bss_9C[7];
 for(i=0;i<(s32)buf[9];i++) {
 o=(struct Obj_t *)fn_1_86254(i);
 if(o->unk_0 & 0x8000880) continue;
 sub=(u8 *)o->unk_49C;
 if(o->unk_475 != -1 && fn_1_5910() == (u32)o->unk_475) continue;
 idx=fn_1_12A24C((s8)i);
 self=(i==n);
 if(mode==0 || sub[0x115]>=3) {
 if(idx==-1 && !self) continue;
 }
 if(o->unk_0 & 0x10000) continue;
 fn_1_862A8(i,&v20);
 if(idx!=-1) {
 if(((0)[lbl_1_bss_89780]) != 0) {
 if(fn_1_D66BC((void *)(u32)(u8)idx,&o48)!=0) {
 fn_1_129D9C(o->unk_14C,&v20,&o48,0,0,self,0,val);
 continue;
 }
 }
 fn_1_129D9C(o->unk_14C,&v20,0,*(void **)(lbl_1_bss_38458->unk_8+t2C[idx]*8),0,self,0,val);
 continue;
 }
 if(mode!=0) {
 u8 lvl=sub[0x115];
 if(lvl<3) {
 fn_1_129D9C(o->unk_14C,&v20,0,*(void **)(lbl_1_bss_38458->unk_8+t3C[lvl]*8),0,self,0,val);
 continue;
 }
 }
 if(!self) continue;
 fn_1_129D9C(o->unk_14C,&v20,0,0,0,self,0,val);
 }
 if(fn_1_F1D60()!=0) {
 if(lbl_1_bss_960==9 && lbl_1_bss_9C[6]==-2) {
 v14.x=p->f0; v14.y=p->f10; v14.z=p->f0;
 fn_1_129D9C(lbl_1_bss_7CA58,&v14,0,0,1,1,0,val);
 return;
 }
 }
 if(fn_1_F1D60()!=0) {
 v8.x=p->f0; v8.y=p->f10; v8.z=p->f0;
 if(fn_1_4C10()==0) {
 for(j=0;j<fn_1_EB0B0();j++) {
 q=fn_1_F1C54(j);
 if(lbl_801A66B4!=5 && fn_80083970(q,(const u8 *)&lbl_1_data_405EC)!=0) q=(u8 *)&p->v94;
 fn_1_129D9C(&lbl_1_bss_7CA58[j],&v8,q,0,1,0,0,val);
 }
 }
 }
 }
end:
 return;
}
/* fzgx:end fn_1_12999C */

/* fzgx:begin fn_1_129D9C */
#include "types.h"
#include "rel/main_rel/accessory.h"

struct fn_1_129D9C_rodata {
    f32 unk_0;
    u8 pad_4[0xC];
    f32 unk_10;
    u8 pad_14[0x8C];
    u32 unk_A0;
    u32 unk_A4;
    s32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x4];
    f64 unk_B8;
    f32 unk_C0;
    f32 unk_C4;
    f32 unk_C8;
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
};
struct fn_1_129D9C_system {
    u8 pad_0[0x2C];
    f32 unk_2C;
};
struct fn_1_129D9C_vec {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};
struct fn_1_129D9C_obj {
    u8 pad_0[0x10];
    u8 unk_10;
};
struct fn_1_129D9C_chain {
    u8 pad_0[0x38];
    u32 unk_38;
    u8 pad_3C[0xC];
    u32 unk_48;
};

extern struct fn_1_129D9C_rodata lbl_1_rodata_8068;
extern void lbl_8006DBAC(void *);

#pragma opt_common_subs off
void fn_1_129D9C(void *arg0, struct fn_1_129D9C_vec *arg1, struct fn_1_129D9C_obj *arg2,
                 f32 arg3, void *arg4, u8 arg5,
                 u8 arg6, u8 arg7, f32 arg8) {
    struct fn_1_129D9C_rodata *p;
    f32 v1;
    f32 v2;
    f32 d;

    p = (struct fn_1_129D9C_rodata *)&lbl_1_rodata_8068;
    if (arg2 != 0) {
        v1 = p->unk_AC;
    } else {
        v1 = p->unk_B0;
    }
    if (arg7) {
        v1 = p->unk_AC;
    }
    v2 = p->unk_B0 * v1;
    if (!arg5) {
        lbl_8006DCA4();
        lbl_8006E1C0(arg1, arg1);
        lbl_8006DFC4(arg0);
    } else {
        lbl_8006DBAC(arg0);
    }
    lbl_8006D7B0();
    if (__fabsf(arg1->unk_0) > p->unk_B8 ||
        __fabsf(arg1->unk_4) > p->unk_B8) {
        arg1->unk_8 = p->unk_0;
        lbl_8006D668(arg1);
        mathutil_mtxA_rotate_z__fzgx_offset_C(-arg1->unk_0, arg1->unk_4);
    }
    lbl_8006E0B4(p->unk_0, p->unk_C0, p->unk_0);
    lbl_8006E14C(v1);
    d = -lbl_801A6D00->unk_2C;
    d *= arg3;
    {
        f32 q = p->unk_C4 / d;
        if ((q * v2) < p->unk_C8) {
            v2 = d * (p->unk_C8 / v2 / p->unk_C4);
        } else if ((q * v2) > p->unk_CC) {
            v2 = d * (p->unk_CC / v2 / p->unk_C4);
        } else {
            v2 = p->unk_10;
        }
    }
    lbl_8006E14C(v2);
    if (arg7) {
        lbl_8006E0B4(p->unk_0, p->unk_D0, p->unk_0);
    }
    lbl_8006E0B4(p->unk_0, p->unk_10, p->unk_0);
    fn_80072558();
    fn_1_55210((void *)((struct fn_1_129D9C_chain *)lbl_1_bss_38458->unk_8)->unk_38);
    if (arg6) {
        lbl_8006E0B4(p->unk_0, p->unk_10, p->unk_0);
        lbl_8006D7B0();
        lbl_8006E14C(v1);
        lbl_8006E14C(v2);
        fn_80072558();
        fn_1_55210((void *)((struct fn_1_129D9C_chain *)lbl_1_bss_38458->unk_8)->unk_48);
        lbl_8006E0B4(p->unk_0, p->unk_D4, p->unk_0);
        if (arg4 == 0) {
            return;
        }
    }
    lbl_8006E0B4(p->unk_0, p->unk_10, p->unk_0);
    lbl_8006D7B0();
    lbl_8006E14C(v1);
    lbl_8006E14C(v2);
    if (arg2 != 0) {
        arg2->unk_10 = 0;
        arg4 = fn_1_548AC(0x50);
        if (arg4 != 0) {
{
    u32 loc_8[3];
            loc_8[0] = p->unk_A0;
            loc_8[1] = p->unk_A4;
            loc_8[2] = p->unk_A8;
            lbl_8006DB74((u8 *)arg4 + 8);
            *(f32 *)((u8 *)arg4 + 56) = p->unk_10 / v2;
            *(void **)((u8 *)arg4 + 4) = (void *)fn_1_12A0E0;
            fn_80083DB0((u8 *)arg4 + 60, arg2);
            fn_1_5489C(fn_1_5448C(loc_8), arg4);
}
        }
    } else {
        fn_80072558();
        fn_1_55210(arg4);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_129D9C */

/* fzgx:begin fn_1_12A080 */
extern const struct fn_1_12A080_lbl_1_rodata_8068_pool {
    f32 unk_0;
    u8 pad_4[0x4C];
    f32 unk_50;
    u8 pad_54[0x84];
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
} lbl_1_rodata_8068;

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

extern void fn_80015EE8(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_80074918(u8, s32, u8);

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_12A080(void) {
    f32 fzgx_live;
    struct fn_1_12A080_lbl_1_rodata_8068_pool *pool_lbl_1_rodata_8068 = (struct fn_1_12A080_lbl_1_rodata_8068_pool *)&lbl_1_rodata_8068;
    Sig_fn_80015EE8_Fn80015EE8Out out;

    fzgx_live = pool_lbl_1_rodata_8068->unk_50;
    fn_80015EE8(&out, pool_lbl_1_rodata_8068->unk_0, fzgx_live, pool_lbl_1_rodata_8068->unk_0, pool_lbl_1_rodata_8068->unk_D8, pool_lbl_1_rodata_8068->unk_DC, pool_lbl_1_rodata_8068->unk_E0);
    fn_800737E4(&out, 1);
    fn_80074918(1, 3, 1);
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_12A080 */

/* fzgx:begin fn_1_12A0E0 noprologue */
#include "dolphin/hw_regs.h"
#include "dolphin/types.h"
#include "rel/main_rel/accessory.h"
#include "psvec.h"

extern u32 lbl_1_rodata_8068;
extern void fn_1_520A0(void);
extern void fn_1_52070(u32);
extern f32 fn_1_A71AC(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_12A080(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_495FC(void);
extern void fn_1_495C8(u8);
extern void fn_1_495A0(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_520CC(void);
extern void lbl_8006DBAC(void *);
extern int fn_80083BCC(const char *, const char *);
typedef struct { f32 value0, value1, value2; } Sig_fn_8006F78C_Fn8006F78CData;
extern void fn_8006F78C(void *, Sig_fn_8006F78C_Fn8006F78CData *, f32);
typedef struct {
    u8 unk_00[8];
    u8 unk_08[0x30];
    f32 unk_38;
    char unk_3C[1];
} DisplayData;

static inline f32 fn_1_12A0E0_read_pointer(Sig_fn_8006F78C_Fn8006F78CData * owner) { return owner->value1; }
#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_12A0E0(DisplayData *arg0)
{
    f32 fzgx_live;
    f32 z;
    f32 scale;
    f32 x;
    f32 y;
    u8 *pool = (u8 *)&lbl_1_rodata_8068;
    f32 depth;
    f32 size;
    Sig_fn_8006F78C_Fn8006F78CData vec;
    u32 color;
    fn_1_520A0();
    fn_1_52070(0x140);
    scale = fn_1_A71AC();
    lbl_8006DBAC(arg0->unk_08);
    fn_1_49410();
    fn_1_494DC(5);
    if (fn_80083BCC(arg0->unk_3C, (const char *)&lbl_1_data_405F4) == 0) {
        color = *(u32 *)(pool + 0xE4);
        fn_1_49514(&color);
    }
    z = *(f32 *)(LC_BASE + 0x2C);
    x = *(f32 *)(LC_BASE + 0xC);
    y = *(f32 *)(LC_BASE + 0x1C);
    depth = (f32)(*(f64 *)(pool + 0xE8) - *(f64 *)(pool + 0xF0) / z);
    psvec_set(&vec, z, y, x);
    fn_1_4954C(-depth);
    fn_8006F78C(&vec, &vec, scale);
    fzgx_live = vec.value0;
    fn_1_496FC(fzgx_live, fn_1_12A0E0_read_pointer(&vec));
    fn_1_49738(fn_1_12A080);
    fn_1_495FC();
    fn_1_495C8(0x11);
    if (arg0->unk_38 < *(f32 *)(pool + 0x60)) {
        arg0->unk_38 = *(f32 *)(pool + 0x60);
    }
    fn_1_495A0(*(f32 *)(pool + 0x6C));
    size = *(f32 *)(pool + 0xB0) * arg0->unk_38;
    fn_1_4955C(size, size);
    fn_1_4966C(*(f32 *)pool, *(f32 *)pool);
    fn_1_4A0D8(arg0->unk_3C);
    fn_1_520CC();
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_12A0E0 */

/* fzgx:begin fn_1_12A24C */
s8 fn_1_12A24C(s8 arg) {
    if ((s8)fn_1_86678((s32)arg) == -1) {
        return -1;
    }
    return arg;
}
/* fzgx:end fn_1_12A24C */

/* fzgx:begin fn_1_12A290 */
u32 fn_1_12A290(s32 index) {
    if (index == -1) {
        return 0;
    }
    return lbl_1_bss_897AC[index * 27 + 26];
}
/* fzgx:end fn_1_12A290 */

/* fzgx:begin fn_1_12A2B8 */
void fn_1_12A2B8(u32 value) {
    lbl_1_bss_897A4 = value;
}
/* fzgx:end fn_1_12A2B8 */

/* fzgx:begin fn_1_12A2C4 */
void fn_1_12A2C4(u32 value) {
    lbl_1_bss_897A8 = value;
}
/* fzgx:end fn_1_12A2C4 */
