#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"

extern void fn_1_41328(void *arg0);
extern void fn_1_43264(void *arg0, f32 arg1);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006D668(void *vector);
extern void lbl_8006DBAC(void *value);
extern void fn_1_449A8(void *vector);
extern void lbl_8006DB74(void *value);
extern u32 lbl_1_bss_384CC;
extern struct fn_1_41850_lbl_801A6410 lbl_801A6410;
extern void fn_1_46B4(u32, void *, const char *, int);
extern const f64 lbl_1_rodata_F40;
extern const f32 lbl_1_rodata_F34;
extern const f32 lbl_1_rodata_F30;
extern const f64 lbl_1_rodata_F48;
extern const f32 lbl_1_rodata_F38;
extern void fn_8006E5FC(void *);
extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F54;

/* fzgx:begin fn_1_41518 noprologue */
#include "types.h"
#include "rel/main_rel/motasglist.h"

typedef struct SigData {
    u16 value0;
    u16 value2;
    s16 value4;
    u16 pad6;
    u32 value8;
} SigData;

typedef struct Elem {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    f32 unk_14;
    f32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 *unk_28;
    u32 unk_2C;
    u32 unk_30;
} Elem;

typedef struct In {
    u8 unk_00[4];
    u16 unk_04;
    u8 unk_06;
    u8 unk_07;
    u32 unk_08;
    u32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 unk_20;
    u8 unk_21;
    u16 unk_22;
    u32 unk_24;
} In;

typedef struct Ent12 {
    u8 *unk_00;
    Elem *unk_04;
    u16 unk_08;
    u16 unk_0A;
} Ent12;

typedef struct Src {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} Src;

typedef struct Ent8 {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
} Ent8;

typedef struct Out {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u32 unk_04;
    u32 unk_08;
    Elem *unk_0C;
    u16 unk_10;
    u16 unk_12;
    u8 *unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 *unk_20;
    u16 unk_24;
    u8 unk_26;
    u8 unk_27;
    Ent12 *unk_28;
    SigData *unk_2C;
    SigData *unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u16 unk_48;
    u16 unk_4A;
    u8 unk_4C;
} Out;

struct Pool {
    u32 unk_0;
};

struct SigPtr {
    const SigData *value;
};

extern struct Pool lbl_801A6410;
extern u8 lbl_1_data_6710[16];
extern void *fn_1_45D0(u32 pool, u32 size, u8 *table, u32 id);
extern void fn_1_42458(SigData *dst, const SigData *src);

Out *fn_1_41518(In *p) {
    Out *out = (Out *)fn_1_45D0(lbl_801A6410.unk_0, 0x60, lbl_1_data_6720, 0x63);
    In *arg0 = p;
    struct SigPtr sig;
    s32 i;

    out->unk_00 = arg0->unk_20;
    out->unk_02 = arg0->unk_22 | 4;
    out->unk_0C = (Elem *)fn_1_45D0(lbl_801A6410.unk_0, (arg0->unk_04 * 52 + 31) & ~31, lbl_1_data_6720, 0x67);
    out->unk_10 = arg0->unk_04;
    out->unk_12 = 0;
    out->unk_04 = 0;
    out->unk_01 = arg0->unk_21;
    out->unk_24 = arg0->unk_10;
    out->unk_18 = arg0->unk_18;
    out->unk_26 = arg0->unk_06;
    out->unk_28 = (Ent12 *)fn_1_45D0(lbl_801A6410.unk_0, (arg0->unk_06 * 12 + 31) & ~31, lbl_1_data_6720, 0x70);
    out->unk_14 = (u8 *)arg0 + arg0->unk_1C;
    out->unk_1C = 0;
    out->unk_08 = 0;
    out->unk_34 = 0;
    out->unk_27 = 0;
    out->unk_38 = 0;
    out->unk_3C = 0;
    out->unk_40 = 0;
    out->unk_48 = 0;
    out->unk_4C = 0;
    out->unk_44 = 0;
    out->unk_4A = 0;
    if (out->unk_24 != 0) {
        out->unk_20 = (u8 *)arg0 + arg0->unk_14;
    } else {
        out->unk_20 = 0;
    }
    out->unk_2C = (SigData *)fn_1_45D0(lbl_801A6410.unk_0, ((arg0->unk_21 << 4) + 31) & ~31, lbl_1_data_6720, 0x82);
    out->unk_30 = (SigData *)fn_1_45D0(lbl_801A6410.unk_0, ((arg0->unk_21 << 4) + 31) & ~31, lbl_1_data_6720, 0x83);
    sig.value = (const SigData *)lbl_1_data_6710;
    for (i = 0; i < (s32)arg0->unk_21; i++) {
        fn_1_42458((SigData *)((u8 *)out->unk_2C + i * 16), sig.value);
        fn_1_42458((SigData *)((u8 *)out->unk_30 + i * 16), sig.value);
    }
    {
        s32 k;
        const Src *s = (const Src *)((u8 *)arg0 + arg0->unk_08);
        u32 *paths = (u32 *)((u8 *)arg0 + arg0->unk_0C);
        const Ent8 *e = (const Ent8 *)((u8 *)arg0 + arg0->unk_24);
        for (i = 0; i < (s32)arg0->unk_06; i++) {
            Ent12 *d = &out->unk_28[i];
            d->unk_00 = out->unk_14 + e[i].unk_04;
            d->unk_04 = out->unk_0C + e[i].unk_00;
            d->unk_08 = e[i].unk_02;
            d->unk_0A = 0;
        }
        for (i = 0; i < (s32)arg0->unk_04; i++) {
            Elem *d = &out->unk_0C[k = i];
            d->unk_00 = s[k].unk_00;
            d->unk_04 = s[k].unk_04;
            d->unk_05 = s[k].unk_05;
            d->unk_06 = s[k].unk_06;
            d->unk_08 = s[k].unk_08;
            d->unk_0A = s[k].unk_0A;
            d->unk_0C = s[k].unk_0C;
            d->unk_0E = s[k].unk_0E;
            d->unk_14 = s[k].unk_10;
            d->unk_18 = s[k].unk_14;
            d->unk_1C = s[k].unk_1C;
            d->unk_20 = s[k].unk_18;
            d->unk_24 = s[k].unk_20;
            d->unk_10 = 0;
            d->unk_30 = 0;
            d->unk_2C = 0;
            d->unk_28 = paths + k * arg0->unk_21;
        }
    }
    return out;
}
/* fzgx:end fn_1_41518 */

/* fzgx:begin fn_1_41850 */
struct fn_1_41850_Arg0 {
    u8 pad_0[0x2];
    u16 unk_2;
};
struct fn_1_41850_lbl_801A6410 {
    u32 unk_0;
};
struct fn_1_41850_Node {
    u8 pad_0[0x28];
    void *unk_28;
    u8 pad_2c[0x4];
    void *next;
};

void fn_1_41850(void *arg0, s32 arg_sp0) {
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;
    void *temp_r4_6;
    void *temp_r4_7;
    void *temp_r4_8;
    void *temp_r4_9;
    void *temp_r4_10;
    void *temp_r4_11;
    u16 temp_r3;
    s32 var_r28;
    void *temp_r28;
    s32 var_r27;
    void *var_r27_2;

    temp_r3 = *(u16 *)((u8 *)(arg0) + 2);
    if (temp_r3 & 1) {
        if (!(temp_r3 & 4)) {
            var_r27 = 0;
            var_r28 = 0;
            while (var_r27 < (s32) (*(u16 *)((u8 *)(arg0) + 16))) {
                temp_r4 = (void *)(((struct fn_1_41850_Node *)(*(void **)((u8 *)(arg0) + 12)))[var_r27].unk_28);
                if (temp_r4 != NULL) {
                    fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x123));
                }
                var_r28 += 0x34;
                var_r27 += 1;
                            }
            temp_r4_2 = (void *)(*(void **)((u8 *)(arg0) + 20));
            if (temp_r4_2 != NULL) {
                fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_2), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x125));
            }
            temp_r4_3 = (void *)(*(void **)((u8 *)(arg0) + 32));
            if (temp_r4_3 != NULL) {
                fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_3), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x126));
            }
        }
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(*(void **)((u8 *)(arg0) + 12)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x128));
    } else {
        var_r27_2 = (void *)(*(void **)((u8 *)(arg0) + 12));
        while (var_r27_2 != NULL) {
            temp_r4_4 = (void *)(*(void **)((u8 *)(var_r27_2) + 40));
            temp_r28 = (void *)(*(void **)((u8 *)(var_r27_2) + 48));
            if (temp_r4_4 != NULL) {
                fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_4), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x12E));
            }
            fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(var_r27_2), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x12F));
            var_r27_2 = (void *)(temp_r28);
                    }
        temp_r4_5 = (void *)(*(void **)((u8 *)(arg0) + 32));
        if (temp_r4_5 != NULL) {
            fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_5), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x131));
        }
    }
    temp_r4_6 = (void *)(*(void **)((u8 *)(arg0) + 40));
    if (temp_r4_6 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_6), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x133));
    }
    temp_r4_7 = (void *)(*(void **)((u8 *)(arg0) + 52));
    if (temp_r4_7 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_7), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10B));
    }
    temp_r4_8 = (void *)(*(void **)((u8 *)(arg0) + 56));
    if (temp_r4_8 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_8), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10C));
    }
    temp_r4_9 = (void *)(*(void **)((u8 *)(arg0) + 44));
    if (temp_r4_9 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_9), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10D));
    }
    temp_r4_10 = (void *)(*(void **)((u8 *)(arg0) + 48));
    if (temp_r4_10 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_10), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10E));
    }
    (*(void **)((u8 *)(arg0) + 52)) = (void *)(NULL);
    (*(s8 *)((u8 *)(arg0) + 39)) = 0;
    (*(void **)((u8 *)(arg0) + 56)) = (void *)(NULL);
    (*(s32 *)((u8 *)(arg0) + 60)) = 0;
    (*(s32 *)((u8 *)(arg0) + 64)) = 0;
    (*(s16 *)((u8 *)(arg0) + 72)) = 0;
    (*(s8 *)((u8 *)(arg0) + 76)) = 0;
    temp_r4_11 = (void *)(*(void **)((u8 *)(arg0) + 8));
    if ((temp_r4_11 != NULL) && !((*(u16 *)((u8 *)(arg0) + 2)) & 2)) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(temp_r4_11), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x137));
    }
    fn_1_46B4((u32)(lbl_801A6410.unk_0), (void *)(arg0), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x138));
}
/* fzgx:end fn_1_41850 */

/* fzgx:begin fn_1_41B18 */
typedef struct Node Node;
struct Node {
    u8 pad[0x30];
    Node *next;
};

typedef struct Object {
    u8 pad[2];
    u16 flags;
    Node *data;
} Object;

extern Object *fn_1_41BDC(Object *obj);

#pragma opt_propagation off
void *fn_1_41B18(Object *obj, s32 unused, s32 index) {
    Object *result;
    Node *node;
    s32 i;

    result = fn_1_41BDC(obj);
    if ((obj->flags & 1) != 0) {
        return (char *)result->data + index * 0x34;
    }

    node = result->data;
    i = 0;
    while (i < index) {
        node = node->next;
        i++;
    }
    return node;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_41B18 */

/* fzgx:begin fn_1_41BDC */
typedef struct fn_1_41BDC_MotasglistData {
    u8 pad_00[0x26];
    u8 count;
    u8 pad_27;
    void *entries;
    u8 pad_2c[0x08];
    void *fallback;
    u8 pad_38[0x14];
    u8 fallback_base;
} fn_1_41BDC_MotasglistData;

void *fn_1_41BDC(fn_1_41BDC_MotasglistData *data, s32 index) {
    if (index < data->count) {
        return (u8 *)data->entries + index * 0xc;
    }

    if (data->fallback == 0) {
        return data;
    }

    return (u8 *)data->fallback + (index - data->fallback_base) * 0xc;
}
/* fzgx:end fn_1_41BDC */

/* fzgx:begin fn_1_41C18 noprologue */
#include "types.h"

typedef struct Sig_fn_1_41C18_Fn1967A8Resource Sig_fn_1_41C18_Fn1967A8Resource;
struct Sig_fn_1_41C18_Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};
typedef struct Sig_fn_1_41328_RelocData {
    u32 count;
    u32 values[1];
} Sig_fn_1_41328_RelocData;
typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

struct fn_1_41C18_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern void fn_1_41328(Sig_fn_1_41328_RelocData *);

void fn_1_41C18(struct fn_1_41C18_Arg0 *arg0, u32 arg1) {
    struct { u32 value; } v0;
    s32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    int t1;
    arg0->unk_4 = arg1;
    fn_1_41328((Sig_fn_1_41328_RelocData *)arg1);
    if ((*(u16 *)((u8 *)(u32)arg0 + 2) & 0x4) != 0) {
    v0.value = 0;
    v1 = 0;
    v2 = v0.value;
    while (v1 < (s32)*(u16 *)((u8 *)(u32)arg0 + 16)) {
    v3 = arg1;
    v4 = (*(u32 *)((u8 *)(u32)arg0 + 12) + v0.value);
    t1 = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)v3, (const char *)(*(u32 *)((u8 *)(u32)arg0 + 20) + *(u32 *)((u8 *)v4 + 28)));
    v3 = t1;
    *(u16 *)((u8 *)v4 + 2) = v3;
    if (*(u16 *)((u8 *)v4 + 2) == 65535) {
    *(u16 *)((u8 *)v4 + 2) = v2;
    }
    v0.value += 52;
    v1++;
    }
    }
}
/* fzgx:end fn_1_41C18 */

/* fzgx:begin fn_1_41E34 */
typedef struct MotasglistEntry {
    u16 value;
    u16 frame;
    s16 offset;
    u8 pad6[2];
    u32 id;
    u8 padC[4];
} MotasglistEntry;

typedef struct MotasglistObject {
    u8 pad0[0x4c];
    f32 value;
} MotasglistObject;

typedef struct fn_1_41E34_MotasglistData {
    u8 pad0[8];
    MotasglistObject *object;
    u8 padC[0x20];
    MotasglistEntry *entries_a;
    MotasglistEntry *entries_b;
} fn_1_41E34_MotasglistData;

typedef struct MotasglistResult {
    u16 first;
    u16 second;
    f32 value;
    u16 third;
} MotasglistResult;

void fn_1_41E34(fn_1_41E34_MotasglistData *data, u32 index, MotasglistResult *result) {
    MotasglistEntry *entry_a = &data->entries_a[index];
    MotasglistEntry *entry_b = &data->entries_b[index];
    f32 delta;
    f32 start;
    f32 end;
    f32 value;

    result->first = entry_a->id;
    result->second = entry_b->id;
    delta = (f32)(entry_b->frame - entry_a->frame);
    if (lbl_1_rodata_F34 == delta) {
        delta = lbl_1_rodata_F30;
    }
    result->value = (data->object->value - (f32)entry_a->frame) / delta;
    if (result->first == result->second) {
        start = (f32)entry_a->offset;
        end = (f32)entry_b->offset;
        value = result->value * (end - start);
        result->value = start + value;
        result->value = result->value / lbl_1_rodata_F38;
    }
    result->third = entry_b->value;
}
/* fzgx:end fn_1_41E34 */

/* fzgx:begin fn_1_41F58 */
typedef u16 (*Fn41F58Callback)(void *arg, void *entry);

typedef struct Fn41F58Entry {
    u8 pad0[6];
    u8 type;
    u8 pad7;
    u32 value;
} Fn41F58Entry;

typedef struct Fn41F58Data {
    u8 pad0[0x14];
    u32 first_base;
    u8 pad18[8];
    u32 first_data;
    u16 first_count;
    u8 pad26[0x16];
    u32 second_data;
    u32 second_base;
    u8 pad44[6];
    u16 second_count;
} Fn41F58Data;

void fn_1_41F58(Fn41F58Data *data, int type, Fn41F58Callback callback, void *arg) {
    Fn41F58Entry *entry;
    int i;

    for (i = 0; i < data->first_count; i++) {
        entry = (Fn41F58Entry *)(data->first_data + i * 0x10);
        if (entry->type == type) {
            entry->value = callback(arg, (void *)(data->first_base + entry->value));
        }
    }

    for (i = 0; i < data->second_count; i++) {
        entry = (Fn41F58Entry *)(data->second_data + i * 0x10);
        if (entry->type == type) {
            entry->value = callback(arg, (void *)(data->second_base + entry->value));
        }
    }
}
/* fzgx:end fn_1_41F58 */

/* fzgx:begin fn_1_42044 */
extern void fn_1_41328(void *arg0);
extern void fn_1_43264(void *arg0, f32 arg1);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006D668(void *vector);
extern void lbl_8006DBAC(void *value);
extern void fn_1_449A8(void *vector);
extern void lbl_8006DB74(void *value);
extern u32 lbl_1_bss_384CC;
extern struct fn_1_41850_lbl_801A6410 lbl_801A6410;
extern void fn_1_46B4(u32, void *, const char *, int);
extern const f64 lbl_1_rodata_F40;
extern const f32 lbl_1_rodata_F34;
extern const f32 lbl_1_rodata_F30;
extern const f64 lbl_1_rodata_F48;
extern const f32 lbl_1_rodata_F38;
extern void fn_8006E5FC(void *);
extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F54;

typedef struct Fn42044Key {
    u16 unk_0;
    u16 frame;
    u8 pad4[8];
    u16 left;
    u16 right;
} Fn42044Key;

typedef struct Fn42044Track {
    u8 unk_0;
    u8 count;
    u16 start;
} Fn42044Track;

typedef struct Fn42044Node {
    u8 pad0[0x28];
    Fn42044Track *tracks;
    u8 pad2C[4];
    struct Fn42044Node *next;
} Fn42044Node;

typedef struct Fn42044Entry {
    u32 unk_0;
    Fn42044Node *nodes;
    u8 pad8[2];
    u16 count;
} Fn42044Entry;

typedef struct Fn42044Timer {
    u8 pad0[0x4C];
    f32 time;
} Fn42044Timer;

typedef struct Fn42044Data {
    u8 pad0[0x2];
    u16 flags;
    u8 pad4[0x4];
    Fn42044Timer *timer;
    u8 padC[0x6];
    u16 index;
    u8 pad14[0xC];
    Fn42044Key *keys;
    u8 pad24[0x2];
    u8 entryCount;
    u8 pad27[0x1];
    Fn42044Entry *entries;
    u8 pad2C[0x8];
    Fn42044Entry *extEntries;
    u8 pad38[0x4];
    Fn42044Key *extKeys;
    u8 pad40[0xC];
    u8 extBase;
} Fn42044Data;

Fn42044Key *fn_1_42044(Fn42044Data *data, s32 track) {
    u16 index = data->index;
    u8 count = data->entryCount;
    Fn42044Entry *entry;
    u16 flags;
    struct { s32 value; } i;
    Fn42044Node *node;
    Fn42044Track *t;
    u8 n;
    Fn42044Key *keys;
    s32 frame;

    if (index < count) {
        entry = &data->entries[index];
    } else if (data->extEntries != NULL) {
        entry = &data->extEntries[index - data->extBase];
    }

    flags = data->flags;
    if (flags & 1) {
        node = (Fn42044Node *)((u8 *)entry->nodes + entry->count * 0x34);
    } else {
        node = entry->nodes;
        for (i.value = 0; i.value < entry->count; i.value++) {
            node = node->next;
        }
    }

    t = &node->tracks[track];
    frame = (s32)data->timer->time;
    if (data->index >= data->entryCount) {
        keys = data->extKeys;
    } else {
        keys = data->keys;
    }

    n = t->count;
    if (n != 0 || keys != NULL) {
        if (data->flags & 4) {
            Fn42044Key *k;
            Fn42044Key *base;
            s32 j;

            if (n == 0) {
                return NULL;
            }
            base = &keys[t->start];
            k = base;
            for (j = 0; j < n; j++) {
                if ((u16)frame < k->frame) {
                    break;
                }
                k++;
            }
            if (j == n) {
                j = 0;
            }
            return &base[j];
        } else {
            u16 start = t->start;
            u16 cur;
            Fn42044Key *k;
            u16 best = 0xFFFF;

            cur = start;

            do {
                k = &keys[cur];
                if ((u16)frame < k->frame) {
                    best = cur;
                    cur = k->left;
                } else {
                    cur = k->right;
                }
            } while (cur != 0xFFFF);

            if (best == 0xFFFF) {
                best = start;
                while (keys[best].left != 0xFFFF) {
                    best = keys[best].left;
                }
            }
            return &keys[best];
        }
    }
    return NULL;
}
/* fzgx:end fn_1_42044 */

/* fzgx:begin fn_1_42254 */
typedef struct Fn42254Key {
    u16 unk_0;
    u16 frame;
    u8 pad4[8];
    u16 left;
    u16 right;
} Fn42254Key;

typedef struct Fn42254Track {
    u8 unk_0;
    u8 count;
    u16 start;
} Fn42254Track;

typedef struct Fn42254Node {
    u8 pad0[0x28];
    Fn42254Track *tracks;
    u8 pad2C[4];
    struct Fn42254Node *next;
} Fn42254Node;

typedef struct Fn42254Entry {
    u32 unk_0;
    Fn42254Node *nodes;
    u8 pad8[2];
    u16 count;
} Fn42254Entry;

typedef struct Fn42254Timer {
    u8 pad0[0x4C];
    f32 time;
} Fn42254Timer;

typedef struct Fn42254Data {
    u8 pad0[0x2];
    u16 flags;
    u8 pad4[0x4];
    Fn42254Timer *timer;
    u8 padC[0x6];
    u16 index;
    u8 pad14[0xC];
    Fn42254Key *keys;
    u8 pad24[0x2];
    u8 entryCount;
    u8 pad27[0x1];
    Fn42254Entry *entries;
    u8 pad2C[0x8];
    Fn42254Entry *extEntries;
    u8 pad38[0x4];
    Fn42254Key *extKeys;
    u8 pad40[0xC];
    u8 extBase;
} Fn42254Data;

static inline Fn42254Node *fn_1_42254_node(Fn42254Entry *entry, u16 flags) {
    Fn42254Node *node;
    s32 i;

    if (flags & 1) {
        node = (Fn42254Node *)((u8 *)entry->nodes + entry->count * 0x34);
    } else {
        node = entry->nodes;
        for (i = 0; i < entry->count; i++) {
            node = node->next;
        }
    }
    return node;
}

Fn42254Key *fn_1_42254(Fn42254Data *data, s32 track) {
    u16 index = data->index;
    u8 count = data->entryCount;
    Fn42254Entry *entry;
    u16 flags;
    Fn42254Node *node;
    Fn42254Track *t;
    u8 n;
    Fn42254Key *keys;
    s32 frame;

    if (index < count) {
        entry = &data->entries[index];
    } else if (data->extEntries != NULL) {
        entry = &data->extEntries[index - data->extBase];
    }

    flags = data->flags;
    node = fn_1_42254_node(entry, flags);

    t = &node->tracks[track];
    frame = (s32)data->timer->time;
    if (data->index >= data->entryCount) {
        keys = data->extKeys;
    } else {
        keys = data->keys;
    }

    n = t->count;
    if (n != 0 || keys != NULL) {
        if (data->flags & 4) {
            Fn42254Key *k;
            Fn42254Key *base;
            s32 j;

            base = &keys[t->start];
            k = base;
            for (j = 0; j < n; j++) {
                if ((u16)frame < k->frame) {
                    break;
                }
                k++;
            }
            if (j == 0) {
                j = n;
            }
            return &base[j - 1];
        } else {
            u16 start = t->start;
            u16 cur;
            Fn42254Key *k;
            u16 best = 0xFFFF;

            cur = start;

            do {
                k = &keys[cur];
                if ((u16)frame < k->frame) {
                    best = cur;
                    cur = k->left;
                } else {
                    cur = k->right;
                }
            } while (cur != 0xFFFF);

            if (best == 0xFFFF) {
                best = start;
                while (keys[best].left != 0xFFFF) {
                    best = keys[best].left;
                }
            }
            return &keys[best];
        }
    }
    return NULL;
}
/* fzgx:end fn_1_42254 */

/* fzgx:begin fn_1_42458 */
typedef struct Fn142458Data {
    u16 value0;
    u16 value2;
    s16 value4;
    u16 pad6;
    u32 value8;
} Fn142458Data;

void fn_1_42458(Fn142458Data *dst, const Fn142458Data *src) {
    dst->value0 = src->value0;
    dst->value8 = src->value8;
    dst->value2 = src->value2;
    dst->value4 = src->value4;
}
/* fzgx:end fn_1_42458 */

/* fzgx:begin fn_1_426AC */
typedef struct Fn1426ACObject {
    u16 count;
    u8 pad2[6];
    u8 *entries;
    u8 padC[0x30];
    void *value;
} Fn1426ACObject;

void fn_1_426AC(Fn1426ACObject *object, void *value) {
    u32 offset;
    s32 i;

    object->value = value;
    i = 0;
    offset = 0;
    for (; i < object->count; i++) {
        *(void **)(object->entries + 0xd0 + offset) = value;
        offset += 0x18c;
        value = (u8 *)value + 8;
    }
}
/* fzgx:end fn_1_426AC */

/* fzgx:begin fn_1_426E4 */
typedef struct Fn1426E4Object {
    u8 pad0[0x24];
    void *value;
} Fn1426E4Object;

void fn_1_426E4(Fn1426E4Object *object, void *value) {
    object->value = value;
    fn_1_41328(value);
}
/* fzgx:end fn_1_426E4 */

/* fzgx:begin fn_1_4270C */
typedef struct Sig_fn_1_431B8_Fn1431B8Object {
    u8 pad0[4];
    u16 flags;
    u16 index;
    u8 pad8[0xD8];
    u16 value0;
    u16 value1;
    u16 value2;
} Sig_fn_1_431B8_Fn1431B8Object;
typedef struct Fn14270CEntry {
    u8 pad0[0xD4];
    u16 counts0[6];
    u16 counts1[6];
    u16 counts2[6];
    u16 cursors0[6];
    u16 cursors1[6];
    u16 cursors2[6];
    u32 pointers0[6];
    u32 pointers1[6];
    u32 pointers2[6];
    u8 pad164[0x28];
} Fn14270CEntry;
struct fn_1_4270C_Arg1 {
    u8 pad_0[0x2];
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
};
extern const f32 lbl_1_rodata_F54;
extern const f64 lbl_1_rodata_F58;
extern s32 fn_1_431B8(Sig_fn_1_431B8_Fn1431B8Object *, Sig_fn_1_431B8_Fn1431B8Object *);
#pragma opt_dead_assignments on
#pragma opt_loop_invariants on
void fn_1_4270C(void *arg0, struct fn_1_4270C_Arg1 *arg1, u32 arg2) {
    u32 v0;
    u16 v1;
    u32 v26_2;
    u32 v2;
    u32 v3;
    s32 v4;
    u32 v5;
    s32 v6;
    u16 v7;
    u32 v8;
    s32 v9;
    s32 v10;
    u32 v11;
    u32 v12;
    u16 v13;
    u32 v14;
    u32 v15;
    s32 v16;
    s32 v17;
    u32 v18;
    u32 v19;
    u16 v20;
    u32 v2_2;
    u32 v21;
    u32 v22;
    s32 v23;
    s32 v24;
    u32 v25;
    u32 v26;
    u16 v27;
    u32 v28;
    u32 v29;
    s32 v30;
    struct { u32 value; } v31;
    u32 v32;
    u32 v33;
    v5 = *(u32 *)((((*(u32 *)((u8 *)arg0 + 36)) + (8)) + (((arg2 & 0xFFFF) << 2))));
    *(f32 *)((u8 *)arg0 + 40) = lbl_1_rodata_F54;
    *(f32 *)((u8 *)arg0 + 44) = lbl_1_rodata_F54;
    *(u16 *)((u8 *)arg0 + 2) &= 778;
    *(f32 *)((u8 *)arg0 + 48) = lbl_1_rodata_F54;
    *(f32 *)((u8 *)arg0 + 52) = lbl_1_rodata_F54;
    *(f32 *)((u8 *)arg0 + 56) = lbl_1_rodata_F54;
    if (((0) != (arg1))) {
        if (*(u16 *)((u8 *)arg0 + 68) >= arg1->unk_4) {
            *(u16 *)((u8 *)arg0 + 68) = arg1->unk_4;
        } else {
            *(u16 *)((u8 *)arg0 + 68) = *(u16 *)((u8 *)v5);
        }
        *(u16 *)((u8 *)arg0 + 66) = arg1->unk_2;
        *(u16 *)((u8 *)arg0 + 70) = arg1->unk_6;
        *(u16 *)((u8 *)arg0 + 84) = 0;
    } else {
        *(u16 *)((u8 *)arg0 + 68) = *(u16 *)((u8 *)v5);
        *(u16 *)((u8 *)arg0 + 66) = 0;
        *(u16 *)((u8 *)arg0 + 70) = 0;
        *(u16 *)((u8 *)arg0 + 84) = 0;
    }
    *(u16 *)((u8 *)arg0 + 64) = 0;
    *(f32 *)((u8 *)arg0 + 80) = (f32)(u32)*(u16 *)((u8 *)v5);
    *(f32 *)((u8 *)arg0 + 76) = (f32)(u32)*(u16 *)((u8 *)arg0 + 66);
    v2 = *(u16 *)((u8 *)v5 + 2);
    if (*(u16 *)arg0 < v2) {
        v2 = *(u16 *)arg0;
    }
    v6 = 0;
    v4 = 0;
    v5 += 4;
    while ((u32)v6 < v2) {
        v7 = *(u16 *)((u8 *)v5);
        v9 = 0;
        v10 = 0;
        v11 = v7;
        v5 += 4;
        {
    u32 fzgx_loop_v8_2766;
for (fzgx_loop_v8_2766 = 3; ((0) != (fzgx_loop_v8_2766)); fzgx_loop_v8_2766--) {
            if (((1) & (v11))) {
                v12 = v5;
                v12 = v12 + 4;
                v13 = *(u16 *)((u8 *)v5);
                v5 += 2;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts0[v9] = v13;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].pointers0[v10] = v12;
                v5 += ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts0[v9] << 4;
                v5 += 2;
            } else {
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts0[v9] = 0;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].pointers0[v10] = 0;
            }
            v11 = ((0x7FFF) & ((v11 >> 1)));
            v10++;
            ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].cursors0[v9] = 0;
            v9++;
        }
    v8 = fzgx_loop_v8_2766;
}
        v16 = 0;
        v17 = 0;
        v18 = v11;
        {
    u32 fzgx_loop_v15_3672;
for (fzgx_loop_v15_3672 = 3; ((0) != (fzgx_loop_v15_3672)); fzgx_loop_v15_3672--) {
            if (((1) & (v18))) {
                v19 = v5 + 4;
                v20 = *(u16 *)((u8 *)v5);
                v5 += 2;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts1[v17] = v20;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].pointers1[v16] = v19;
                v5 += ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts1[v17] << 4;
                v5 += 2;
            } else {
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts1[v17] = 0;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].pointers1[v16] = 0;
            }
            v18 = ((0x7FFF) & ((v18 >> 1)));
            v16++;
            ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].cursors1[v17] = 0;
            v17++;
        }
    v15 = fzgx_loop_v15_3672;
}
        v23 = 0;
        v24 = 0;
        {
    u32 fzgx_loop_v22_4540;
for (fzgx_loop_v22_4540 = 3; fzgx_loop_v22_4540 != 0; fzgx_loop_v22_4540--) {
            if (v18 & 1) {
                v26 = v5 + 4;
                v27 = *(u16 *)((u8 *)v5);
                v5 += 2;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts2[v24] = v27;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].pointers2[v23] = v26;
                v5 += ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts2[v24] << 4;
                v5 += 2;
            } else {
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].counts2[v24] = 0;
                ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].pointers2[v23] = 0;
            }
            v18 = (v18 >> 1) & 0x7FFF;
            v23++;
            ((Fn14270CEntry *)*(u32 *)((u8 *)arg0 + 8))[v6].cursors2[v24] = 0;
            v24++;
        }
    v22 = fzgx_loop_v22_4540;
}
        v4 += 396;
        v6++;
    }
    v6 = 0;
    while ((u32)v6 < *(u16 *)arg0) {
        v26_2 = *(u32 *)((u8 *)arg0 + 8);
        v32 = v26_2;
        v33 = v32 + v6 * 396;
        if ((*(u16 *)((u8 *)v33 + 4) & 1) && *(u16 *)((u8 *)v33 + 236) == 0 && *(u16 *)((u8 *)v33 + 238) == 0 && *(u16 *)((u8 *)v33 + 240) == 0 && fn_1_431B8((Sig_fn_1_431B8_Fn1431B8Object *)v32, (Sig_fn_1_431B8_Fn1431B8Object *)v33)) {
            *(u16 *)((u8 *)v33 + 4) |= 256;
        }
        v6++;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4270C */

/* fzgx:begin fn_1_42AD0 */
extern void fn_1_41328(void *arg0);
extern void fn_1_43264(void *arg0, f32 arg1);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006D668(void *vector);
extern void lbl_8006DBAC(void *value);
extern void fn_1_449A8(void *vector);
extern void lbl_8006DB74(void *value);
extern u32 lbl_1_bss_384CC;
extern struct fn_1_41850_lbl_801A6410 lbl_801A6410;
extern void fn_1_46B4(u32, void *, const char *, int);
extern const f64 lbl_1_rodata_F40;
extern const f32 lbl_1_rodata_F34;
extern const f32 lbl_1_rodata_F30;
extern const f64 lbl_1_rodata_F48;
extern const f32 lbl_1_rodata_F38;
extern void fn_8006E5FC(void *);
extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F54;


typedef struct Fn1_42AD0_Vec {
    f32 x;
    f32 y;
    f32 z;
} Fn1_42AD0_Vec;

typedef struct Fn1_42AD0_Key16 {
    u16 cur[3];
    u16 prev[3];
} Fn1_42AD0_Key16;

typedef struct Fn1_42AD0_Key32 {
    s32 cur[3];
    s32 prev[3];
} Fn1_42AD0_Key32;

typedef struct Fn1_42AD0_Bone {
    u8 pad_0[0x88];
    f32 mtx[3][4];
    Fn1_42AD0_Vec pos;
    Fn1_42AD0_Vec scale;
    u8 pad_D0[0x4];
    Fn1_42AD0_Key16 rot[3];
    Fn1_42AD0_Key16 rot2[3];
    Fn1_42AD0_Key32 trans[3];
    u8 pad_164[0x10];
    Fn1_42AD0_Vec prev_pos;
    Fn1_42AD0_Vec prev_scale;
} Fn1_42AD0_Bone;

typedef struct Fn1_42AD0_Anim {
    u16 unk_0;
    u16 start;
    u16 end;
    u16 unk_6;
    f32 speed;
    f32 frame;
    f32 unk_10;
    u8 pad_14[0x4];
} Fn1_42AD0_Anim;

typedef struct Fn1_42AD0_Skel {
    u16 count;
    u16 flags;
    u8 pad_4[0x4];
    Fn1_42AD0_Bone *bones;
    u8 pad_C[0x20];
    f32 blend_frames;
    Fn1_42AD0_Vec root;
    u8 pad_3C[0x4];
    Fn1_42AD0_Anim anim;
    Fn1_42AD0_Anim prev_anim;
} Fn1_42AD0_Skel;

extern void fn_1_4270C(Fn1_42AD0_Skel *, void *, u32);
extern void fn_1_433A4(Fn1_42AD0_Anim *, Fn1_42AD0_Anim *);

extern void fn_8006E5FC(void *);

void fn_1_42AD0(Fn1_42AD0_Skel *skel, void *data, u32 arg2, u16 blend, u32 flags) {
    f32 progress;
    f32 length;
    f32 start;
    f32 new_length;
    s32 i;
    Fn1_42AD0_Bone *bone;
    s32 keep;
    u16 mode;

    if (blend == 0 || (skel->flags & 0x100)) {
        fn_1_4270C(skel, data, arg2);
        return;
    }
    start = skel->anim.start;
    length = (f32)skel->anim.end - start;
    progress = (skel->anim.frame - start) / length;
    fn_1_433A4(&skel->prev_anim, &skel->anim);
    keep = flags & 2;
    mode = flags;
    if (keep) {
        for (i = 0; i < skel->count; i++) {
            bone = &skel->bones[i];
            bone->rot[0].prev[0] = bone->rot[0].cur[0];
            bone->rot[1].prev[0] = bone->rot[1].cur[0];
            bone->rot[2].prev[0] = bone->rot[2].cur[0];
            bone->trans[0].prev[0] = bone->trans[0].cur[0];
            bone->trans[1].prev[0] = bone->trans[1].cur[0];
            bone->trans[2].prev[0] = bone->trans[2].cur[0];
            bone->rot2[0].prev[0] = bone->rot2[0].cur[0];
            bone->rot2[1].prev[0] = bone->rot2[1].cur[0];
            bone->rot2[2].prev[0] = bone->rot2[2].cur[0];
            bone->rot[0].prev[1] = bone->rot[0].cur[1];
            bone->rot[1].prev[1] = bone->rot[1].cur[1];
            bone->rot[2].prev[1] = bone->rot[2].cur[1];
            bone->trans[0].prev[1] = bone->trans[0].cur[1];
            bone->trans[1].prev[1] = bone->trans[1].cur[1];
            bone->trans[2].prev[1] = bone->trans[2].cur[1];
            bone->rot2[0].prev[1] = bone->rot2[0].cur[1];
            bone->rot2[1].prev[1] = bone->rot2[1].cur[1];
            bone->rot2[2].prev[1] = bone->rot2[2].cur[1];
            bone->rot[0].prev[2] = bone->rot[0].cur[2];
            bone->rot[1].prev[2] = bone->rot[1].cur[2];
            bone->rot[2].prev[2] = bone->rot[2].cur[2];
            bone->trans[0].prev[2] = bone->trans[0].cur[2];
            bone->trans[1].prev[2] = bone->trans[1].cur[2];
            bone->trans[2].prev[2] = bone->trans[2].cur[2];
            bone->rot2[0].prev[2] = bone->rot2[0].cur[2];
            bone->rot2[1].prev[2] = bone->rot2[1].cur[2];
            bone->rot2[2].prev[2] = bone->rot2[2].cur[2];
        }
    } else {
        for (i = 0; i < skel->count; i++) {
            bone = &skel->bones[i];
            lbl_8006DBAC(bone->mtx);
            fn_8006E5FC((u8 *)bone + 0x164);
            bone->prev_pos = bone->pos;
            bone->prev_scale = bone->scale;
        }
    }
    fn_1_4270C(skel, data, arg2);
    new_length = (s32)(skel->anim.end - skel->anim.start);
    if (keep) {
        skel->flags |= 1;
        skel->prev_anim.speed *= length / new_length;
    }
    if (mode & 0x20) {
        skel->flags |= 0x400;
    }
    if (mode & 0x80) {
        skel->flags |= 0x800;
    }
    if (mode & 0x40) {
        skel->flags |= 0x200;
    }
    if (mode & 1) {
        f32 offset = new_length * progress;

        skel->anim.frame = (f32)skel->anim.start + offset;
    }
    if (mode & 4) {
        skel->flags |= 0x20;
    }
    if (mode & 8) {
        skel->flags |= 0x40;
    }
    if (mode & 0x10) {
        skel->flags |= 0x80;
    }
    skel->blend_frames = blend;
    skel->root.x = skel->bones->mtx[0][3];
    skel->root.y = skel->bones->mtx[1][3];
    skel->root.z = skel->bones->mtx[2][3];
}
/* fzgx:end fn_1_42AD0 */

/* fzgx:begin fn_1_42E74 */
typedef struct Fn142E74Pair {
    u32 a;
    u32 b;
} Fn142E74Pair;

typedef struct Fn142E74Entry {
    u8 pad0[0xB8];
    Fn142E74Pair sourceB8;
    u32 sourceC0;
    Fn142E74Pair sourceC4;
    u32 sourceCC;
    u8 padD0[0xA4];
    Fn142E74Pair value174;
    u32 value17C;
    Fn142E74Pair value180;
    u32 value188;
} Fn142E74Entry;

typedef struct Fn142E74Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142E74Entry *entries;
    u8 padC[0x0C];
    f32 value0;
    f32 value1;
    f32 value2;
    u8 pad24[0x1C];
    u16 flags40;
} Fn142E74Object;

extern void fn_1_438AC(Fn142E74Object *object, Fn142E74Entry *entry, s32 arg2);
extern void fn_1_433E0(Fn142E74Object *object);
extern void fn_1_4300C(Fn142E74Object *object);

void fn_1_42E74(Fn142E74Object *object) {
    s32 i;
    Fn142E74Entry *entry;

    lbl_8006DAEC();
    if (object->flags & 1) {
        for (i = 0; i < object->count; i++) {
            fn_1_438AC(object, (Fn142E74Entry *)((u8 *)object->entries + i * 0x18c), 1);
        }

        for (i = 0; i < object->count; i++) {
            entry = (Fn142E74Entry *)((u8 *)object->entries + i * 0x18c);
            lbl_8006DBAC((u8 *)entry + 0x88);
            fn_8006E5FC((u8 *)entry + 0x164);
            entry->value174 = entry->sourceB8;
            entry->value17C = entry->sourceC0;
            entry->value180 = entry->sourceC4;
            entry->value188 = entry->sourceCC;
        }
    }

    for (i = 0; i < object->count; i++) {
        fn_1_438AC(object, (Fn142E74Entry *)((u8 *)object->entries + i * 0x18c), 0);
    }
    object->value0 = *(f32 *)((u8 *)object->entries + 0x94);
    object->value1 = *(f32 *)((u8 *)object->entries + 0xa4);
    object->value2 = *(f32 *)((u8 *)object->entries + 0xb4);
    fn_1_433E0(object);
    lbl_8006DB30();
    if (!(object->flags & 0x10)) {
        fn_1_4300C(object);
    }
    if (object->flags40 & 2) {
        object->flags |= 4;
    } else {
        object->flags &= ~4;
    }
    object->flags &= ~0x100;
}
/* fzgx:end fn_1_42E74 */

/* fzgx:begin fn_1_4300C */
typedef struct Fn14300CObject {
    u8 pad0[2];
    u16 flags;
    f32 value;
    u8 pad1[0x38];
} Fn14300CObject;

void fn_1_4300C(Fn14300CObject *object) {
    fn_1_43264((u8 *)object + 0x40, object->value);
    if (object->flags & 1) {
        fn_1_43264((u8 *)object + 0x58, object->value);
    }
}
/* fzgx:end fn_1_4300C */

/* fzgx:begin fn_1_43058 */
typedef struct Fn143058Entry {
    u8 pad0[0x94];
    f32 value0;
    u8 pad98[0x0C];
    f32 value1;
    u8 padA8[0x0C];
    f32 value2;
} Fn143058Entry;

typedef struct Fn143058Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    u8 *entries;
    u8 padC[0xC];
    f32 value0;
    f32 value1;
    f32 value2;
} Fn143058Object;

extern void fn_1_43E08(Fn143058Object *object, u8 *entry, void *arg2, void *arg3, f32 value);
extern void fn_1_433E0(Fn143058Object *object);

void fn_1_43058(Fn143058Object *object, void *arg2, void *arg3, f32 value) {
    u32 offset;
    s32 i;

    lbl_8006DAEC();
    i = 0;
    offset = 0;
    for (; i < object->count; i++) {
        fn_1_43E08(object, object->entries + offset, arg2, arg3, value);
        offset += 0x18c;
    }
    object->value0 = ((Fn143058Entry *)object->entries)->value0;
    object->value1 = ((Fn143058Entry *)object->entries)->value1;
    object->value2 = ((Fn143058Entry *)object->entries)->value2;
    fn_1_433E0(object);
    lbl_8006DB30();
    object->flags &= ~0x100;
}
/* fzgx:end fn_1_43058 */

/* fzgx:begin fn_1_43120 */
typedef struct Fn143120Entry {
    u8 pad0[0x88];
    u8 value0[8];
    f32 x;
    u8 pad94[0x0c];
    f32 y;
    u8 padA4[0x0c];
    f32 z;
} Fn143120Entry;

typedef struct Fn143120Object {
    u8 pad0[8];
    Fn143120Entry *entries;
} Fn143120Object;

void fn_1_43120(Fn143120Object *object, u32 index, f32 *vector) {
    Fn143120Entry *entry;
    f32 delta[3];

    entry = (Fn143120Entry *)((u8 *)object->entries + (index & 0xffff) * 0x18c);
    lbl_8006DAEC();
    delta[0] = vector[0] - entry->x;
    delta[1] = vector[1] - entry->y;
    delta[2] = vector[2] - entry->z;
    lbl_8006D668(delta);
    lbl_8006DBAC(entry->value0);
    fn_1_449A8(delta);
    lbl_8006DB74(entry->value0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_43120 */

/* fzgx:begin fn_1_431B8 */
typedef enum Fn1431B8Index {
    FN1431B8_INVALID = -1
} Fn1431B8Index;

typedef struct Fn1431B8Object {
    u8 pad0[4];
    u16 flags;
    u16 index;
    u8 pad8[0xD8];
    u16 value0;
    u16 value1;
    u16 value2;
} Fn1431B8Object;

s32 fn_1_431B8(Fn1431B8Object *base, Fn1431B8Object *object) {
    Fn1431B8Object *entry;
    s32 count;

    entry = (Fn1431B8Object *)((u8 *)base + object->index * 0x18c);
    count = 0;
    while (!(entry->flags & 2)) {
        if (count == 2) {
            // The retail loop shares one exit for both termination checks.
            goto done;
        }
        if (entry->index == FN1431B8_INVALID) {
            // The retail loop shares one exit for both termination checks.
            goto done;
        }
        count++;
        if (entry->value0 != 0 || entry->value1 != 0 || entry->value2 != 0) {
            return 1;
        }
        entry = (Fn1431B8Object *)((u8 *)base + entry->index * 0x18c);
    }
done:
    return 0;
}
/* fzgx:end fn_1_431B8 */

/* fzgx:begin fn_1_4322C */
struct fn_1_4322C_Arg0 {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
};

void fn_1_4322C(struct fn_1_4322C_Arg0 *arg0) {
    const f32 *value;
    f32 v0;
    u16 zero;

    value = &lbl_1_rodata_F50;
    zero = 0;
    arg0->unk_0 = zero;
    v0 = *value;
    arg0->unk_8 = v0;
    arg0->unk_C = lbl_1_rodata_F54;
    arg0->unk_10 = lbl_1_rodata_F54;
    arg0->unk_2 = zero;
    arg0->unk_4 = zero;
    arg0->unk_6 = zero;
}
/* fzgx:end fn_1_4322C */

/* fzgx:begin fn_1_43264 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"

extern const f64 lbl_1_rodata_F58;
struct Fn143264Object {
    u16 flags;
    u16 start;
    u16 end;
    u16 restart;
    f32 speed;
    f32 position;
    f32 unk10;
    u16 count;
};
void fn_1_43264(struct Fn143264Object *arg0, f32 arg1) {
    f32 restart;
    f32 start;
    f32 end;
    f32 step;
    if (arg0->flags & 2) return;
    step = arg1 * arg0->speed;
    start = (f32)arg0->start;
    end = (f32)arg0->end;
    arg0->flags &= ~4;
    if ((arg0->position += step) > end) {
        if (arg0->flags & 1) {
            arg0->position = end;
            arg0->flags |= 2;
        } else {
            restart = (f32)arg0->restart;
            arg0->start = (s32)restart;
            arg0->position -= end + step - restart;
            arg0->count++;
            arg0->flags |= 4;
        }
    } else if (arg0->position < start) {
        if (arg0->flags & 1) {
            arg0->position = start;
            arg0->flags |= 2;
        } else {
            arg0->position += end - step - start;
            arg0->start = arg0->restart;
            arg0->count++;
            arg0->flags |= 4;
        }
    }
}
/* fzgx:end fn_1_43264 */

/* fzgx:begin fn_1_433A4 */
typedef struct Fn1433A4Object {
    u16 value0;
    u16 value1;
    u16 value2;
    u16 value3;
    f32 value4;
    f32 value5;
    f32 value6;
} Fn1433A4Object;

void fn_1_433A4(Fn1433A4Object *dst, Fn1433A4Object *src) {
    dst->value0 = src->value0;
    dst->value5 = src->value5;
    dst->value6 = src->value6;
    dst->value4 = src->value4;
    dst->value1 = src->value1;
    dst->value3 = src->value3;
    dst->value2 = src->value2;
}
/* fzgx:end fn_1_433A4 */

/* fzgx:begin fn_1_433E0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"
#include "dolphin/hw_regs.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"
#include "dolphin/hw_regs.h"
#include "types.h"

/* begin game/main_rel/motasglist_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_MOTASGLIST_TYPES_H
#define GAME_MAIN_REL_MOTASGLIST_TYPES_H

// Types (and the externs that name them) of motasglist.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct fn_1_41BDC_MotasglistData {
    u8 pad_00[0x26];
    u8 count;
    u8 pad_27;
    void *entries;
    u8 pad_2c[0x08];
    void *fallback;
    u8 pad_38[0x14];
    u8 fallback_base;
} fn_1_41BDC_MotasglistData;

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

typedef struct Sig_fn_1_41328_RelocData {
    u32 count;
    u32 values[1];
} Sig_fn_1_41328_RelocData;

typedef struct Fn142AD0Pair {
    u32 a;
    u32 b;
} Fn142AD0Pair;

typedef struct Fn142AD0Entry {
    u8 pad0[0x88];
    u8 value88[0x0C];
    f32 x;
    u8 pad98[0x0C];
    f32 y;
    u8 padA8[0x0C];
    f32 z;
    Fn142AD0Pair sourceB8;
    u32 sourceC0;
    Fn142AD0Pair sourceC4;
    u32 sourceCC;
    u8 padD0[4];
    u16 keys[6][2][3];
    u32 keysF[3][2][3];
    u8 quat[0x10];
    Fn142AD0Pair value174;
    u32 value17C;
    Fn142AD0Pair value180;
    u32 value188;
} Fn142AD0Entry;

typedef struct Fn142AD0Key {
    u16 value0;
    u16 value1;
    u16 value2;
    u16 value3;
    f32 value4;
    f32 value5;
    f32 value6;
} Fn142AD0Key;

typedef struct Fn142AD0Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142AD0Entry *entries;
    u8 padC[0x20];
    f32 value2C;
    f32 value30;
    f32 value34;
    f32 value38;
    u8 pad3C[4];
    Fn142AD0Key cur;
    u8 pad54[4];
    Fn142AD0Key prev;
} Fn142AD0Object;

typedef struct Fn1433A4Object {
    u16 value0;
    u16 value1;
    u16 value2;
    u16 value3;
    f32 value4;
    f32 value5;
    f32 value6;
} Fn1433A4Object;

typedef struct Fn142E74Pair {
    u32 a;
    u32 b;
} Fn142E74Pair;

typedef struct Fn142E74Entry {
    u8 pad0[0xB8];
    Fn142E74Pair sourceB8;
    u32 sourceC0;
    Fn142E74Pair sourceC4;
    u32 sourceCC;
    u8 padD0[0xA4];
    Fn142E74Pair value174;
    u32 value17C;
    Fn142E74Pair value180;
    u32 value188;
} Fn142E74Entry;

typedef struct Fn142E74Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142E74Entry *entries;
    u8 padC[0x0C];
    f32 value0;
    f32 value1;
    f32 value2;
    u8 pad24[0x1C];
    u16 flags40;
} Fn142E74Object;

typedef struct Fn1433E0Vec {
    f32 x;
    f32 y;
    f32 z;
} Fn1433E0Vec;

typedef struct Fn1433E0Quat {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Fn1433E0Quat;

typedef struct Fn1433E0Entry {
    u8 pad0[4];
    u16 flags;
    u16 parent;
    u8 pad8[0xC];
    f32 value14;
    Fn1433E0Vec offset18;
    f32 value24;
    u8 pad28[0x60];
    u8 mtx[0x30];
    Fn1433E0Vec scale;
    Fn1433E0Vec offsetC4;
    u8 padD0[0x94];
    Fn1433E0Quat quat;
    Fn1433E0Vec value174;
    Fn1433E0Vec value180;
} Fn1433E0Entry;

typedef struct Fn1433E0Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn1433E0Entry *entries;
    Fn1433E0Vec scale;
    Fn1433E0Vec offset;
    u8 pad24[4];
    f32 frame;
    f32 duration;
    Fn1433E0Vec prev;
} Fn1433E0Object;

typedef struct Fn14300CObject {
    u8 pad0[2];
    u16 flags;
    f32 value;
    u8 pad1[0x38];
} Fn14300CObject;

typedef struct Fn143058Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    u8 *entries;
    u8 padC[0xC];
    f32 value0;
    f32 value1;
    f32 value2;
} Fn143058Object;

struct fn_1_41850_lbl_801A6410 {
    u32 unk_0;
};

extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern void fn_1_4270C(Fn142AD0Object *object, void *arg1, u32 arg2);
extern void fn_1_433A4(Fn1433A4Object *dst, Fn1433A4Object *src);
extern void fn_1_438AC(Fn142E74Object *object, Fn142E74Entry *entry, s32 arg2);
extern void fn_1_433E0(Fn1433E0Object *object);
extern void fn_1_4300C(Fn14300CObject *object);
extern void fn_1_43E08(Fn143058Object *object, u8 *entry, void *arg2, void *arg3, f32 value);
extern struct fn_1_41850_lbl_801A6410 lbl_801A6410;
extern void fn_8006E8DC(Fn1433E0Quat *);
extern void fn_8006EB4C(Fn1433E0Quat *, Fn1433E0Quat *, Fn1433E0Quat *, f32);

#endif  // GAME_MAIN_REL_MOTASGLIST_TYPES_H

/* end game/main_rel/motasglist_types.h */

extern void * fn_1_41BDC();
extern void fn_1_41328(void *arg0);
extern void lbl_8006DBAC(void *value);
extern void fn_8006E5FC(f32 *arg0);
extern void fn_1_43264(void *arg0, f32 arg1);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006D668(void *vector);
extern void fn_1_449A8(void *vector);
extern void lbl_8006DB74(void *value);
extern u32 lbl_1_bss_384CC;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern const f64 lbl_1_rodata_F40;
extern const f32 lbl_1_rodata_F34;
extern const f32 lbl_1_rodata_F30;
extern const f64 lbl_1_rodata_F48;
extern const f32 lbl_1_rodata_F38;
extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F54;
extern const f32 lbl_1_rodata_F68;
extern const f32 lbl_1_rodata_F6C;
extern f32 lbl_8006D188(s32);
extern void lbl_8006D758(void);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006E15C(f32, f32, f32);

// Matrix A lives at the start of the locked-cache window.
#define MTXA ((f32 *)(LC_BASE + 0x0))

static inline void mtxA_clear_translation(void) {
    f32 *m = MTXA;
    m[3] = lbl_1_rodata_F54;
    m[7] = lbl_1_rodata_F54;
    m[11] = lbl_1_rodata_F54;
}

#pragma opt_propagation off
void fn_1_433E0(Fn1433E0Object *object) {
    f32 *mtxA;
    Fn1433E0Entry *entry;
    Fn1433E0Entry *entries;
    s32 i;
    Fn1433E0Entry *parent;
    f32 t;
    Fn1433E0Vec tmp;
    u8 mtx[0x30];
    Fn1433E0Vec vec;
    Fn1433E0Quat q1;
    Fn1433E0Quat q0;
    f32 base;
    f32 z;
    f32 y;
    f32 x;

    if (object->frame < object->duration) {
        t = object->frame / object->duration;
        if (object->flags & 0xC00) {
            t = lbl_8006D188((s32)(lbl_1_rodata_F68 * (lbl_1_rodata_F6C * t)));
            if (object->flags & 0x800) {
                t = t * t;
            }
        }
        object->frame = object->frame + lbl_1_rodata_F50;
    } else {
        t = lbl_1_rodata_F50;
        object->frame = lbl_1_rodata_F54;
        object->duration = lbl_1_rodata_F54;
        object->flags &= ~1;
    }

    entries = object->entries;
    entry = entries;
    for (i = 0; i < object->count; i++) {
        parent = NULL;
        if (i == 0) {
            vec.x = object->offset.x * object->scale.x;
            vec.y = object->offset.y * object->scale.y;
            vec.z = object->offset.z * object->scale.z;
            if (!(object->flags & 0x20)) {
                base = object->prev.x;
                vec.x = base + (f32)(t * (vec.x - base));
            }
            if (!(object->flags & 0x40)) {
                base = object->prev.y;
                vec.y = base + (f32)(t * (vec.y - base));
            }
            if (!(object->flags & 0x80)) {
                base = object->prev.z;
                vec.z = base + (f32)(t * (vec.z - base));
            }
        } else {
            if (entry->parent == 0xFFFF) {
                lbl_8006D758();
            } else {
                parent = (Fn1433E0Entry *)((u8 *)entries + entry->parent * 0x18c);
                lbl_8006DBAC(parent->mtx);
            }
            if (entry->flags & 0x11) {
                base = entry->value14 * object->scale.x;
                vec.y = lbl_1_rodata_F54;
                vec.x = base;
                vec.z = lbl_1_rodata_F54;
                if (object->flags & 8) {
                    vec.x = base * entry->value24;
                }
            } else {
                if (object->flags & 8) {
                    tmp = entry->offset18;
                } else {
                    tmp = entry->offsetC4;
                }
                vec = tmp;
                if (t < lbl_1_rodata_F50 && (entry->flags & 0x40)) {
                    base = entry->value180.x * (entry->value174.x / entry->scale.x);
                    vec.x = base + (f32)(t * (vec.x - base));
                    base = entry->value180.y * (entry->value174.y / entry->scale.y);
                    vec.y = base + (f32)(t * (vec.y - base));
                    base = entry->value180.z * (entry->value174.z / entry->scale.z);
                    vec.z = base + (f32)(t * (vec.z - base));
                }
            }
            lbl_8006E1B0(&vec, &vec);
        }

        entry->scale.x = entry->scale.x * object->scale.x;
        entry->scale.y = entry->scale.y * object->scale.y;
        entry->scale.z = entry->scale.z * object->scale.z;

        if (t < lbl_1_rodata_F50) {
            if ((object->flags & 0x200) && parent != NULL && entry->parent != 0) {
                mathutil_mtxA_from_quat(&entry->quat);
                lbl_8006DB74(mtx);
                mathutil_mtxA_from_quat(&parent->quat);
                lbl_8006DD7C();
                lbl_8006DFC4(mtx);
                fn_8006E5FC( (f32 *)(void *)(&q0));
                lbl_8006DBAC(parent->mtx);
                mtxA_clear_translation();
                lbl_8006DD7C();
                lbl_8006DFC4(entry->mtx);
                mtxA_clear_translation();
                fn_8006E5FC( (f32 *)(void *)(&q1));
                fn_8006E8DC(&q1);
                fn_8006E8DC(&q0);
                fn_8006EB4C(&q1, &q0, &q1, t);
                fn_8006E8DC(&q1);
                mathutil_mtxA_from_quat(&q1);
                lbl_8006DB74(mtx);
                lbl_8006DBAC(parent->mtx);
                mtxA_clear_translation();
                lbl_8006DFC4(mtx);
            } else {
                lbl_8006DBAC(entry->mtx);
                fn_8006E5FC( (f32 *)(void *)(&q1));
                fn_8006EB4C(&q1, &entry->quat, &q1, t);
                mathutil_mtxA_from_quat(&q1);
            }
        } else {
            lbl_8006DBAC(entry->mtx);
        }

        x = vec.x;
        y = vec.y;
        z = vec.z;
        mtxA = MTXA;
        mtxA[3] = x;
        mtxA[7] = y;
        mtxA[11] = z;
        lbl_8006E15C(entry->scale.x, entry->scale.y, entry->scale.z);
        lbl_8006DB74(entry->mtx);
        entry++;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_433E0 */

/* fzgx:begin fn_1_43E08 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

extern const struct fn_1_43E08_lbl_1_rodata_F50_pool {
    f32 unk_0;
} lbl_1_rodata_F50;

extern const struct fn_1_43E08_lbl_1_rodata_F68_pool {
    f32 unk_0;
} lbl_1_rodata_F68;

typedef struct Vec { f32 x, y, z; } Vec;
typedef struct Entry {
    u8 pad0[4];
    u16 flags;
    u16 parent;
    Vec pos;
    u8 pad14[0x14];
    u8 rot28[0x30];
    u8 rot58[0x30];
    u8 mtx[0x30];
    Vec scale;
    Vec offsetC4;
} Entry;
typedef struct Obj {
    u16 count;
    u16 flags;
    u8 pad4[4];
    u8 *entries;
} Obj;

extern void lbl_8006D758(void);
extern void lbl_8006D7B0(void);
extern void lbl_8006DBAC(void *mtx);
extern void lbl_8006DB74(void *mtx);
extern void lbl_8006E1B0(void *src, void *dst);
extern void lbl_8006DFC4(void *quat);
extern void lbl_8006D5A4(void *a, void *b, void *out, f32 t);
extern void fn_8006E250(void *src, void *dst);
extern int fn_1_442D8(void *out, Entry *entry, u32 channel, u32 arg3, f32 frame);
extern void fn_1_44A74(Obj *object, Entry *entry);
extern void mathutil_mtxA_rotate_z(s32 angle);
extern void mathutil_mtxA_rotate_y(s32 angle);
extern void mathutil_mtxA_rotate_x(s32 angle);

#define LC_MTX ((f32 *)LC_BASE)

#pragma opt_propagation off
void fn_1_43E08(Obj *object, Entry *entry, u16 frameA, u16 frameB, f32 value) {
    f32 *fzgx_value;
    Vec scale;
    Vec rot;
    Vec unit;
    Vec pos;
    Vec start;
    u16 parent;

    parent = entry->parent;
    if (parent == 0xFFFF) {
        lbl_8006D758();
        scale.x = lbl_1_rodata_F50.unk_0;
        scale.y = lbl_1_rodata_F50.unk_0;
        scale.z = lbl_1_rodata_F50.unk_0;
    } else if (entry->flags & 4) {
        lbl_8006D7B0();
        scale.x = lbl_1_rodata_F50.unk_0;
        scale.y = lbl_1_rodata_F50.unk_0;
        scale.z = lbl_1_rodata_F50.unk_0;
    } else {
        Entry *parentEntry = (Entry *)(object->entries + parent * 0x18C);
        lbl_8006DBAC(parentEntry->mtx);
        scale = parentEntry->scale;
    }

    if (entry->flags & 1) {
        lbl_8006E1B0(&entry->pos, &pos);
        start = pos;
        fn_1_442D8(&start, entry, 12, 0, frameA);
        fn_1_442D8(&pos, entry, 12, 0, frameB);
        lbl_8006D5A4(&start, &pos, &pos, value);
    } else {
        pos = entry->pos;
        start = pos;
        fn_1_442D8(&start, entry, 12, 0, frameA);
        fn_1_442D8(&pos, entry, 12, 0, frameB);
        lbl_8006D5A4(&start, &pos, &pos, value);
        lbl_8006E1B0(&pos, &pos);
    }

    {
        f32 z, y, x;
        /* volatile read keeps x's load ahead of y and z, as retail schedules it */
        x = *(volatile f32 *)&pos.x;
        y = pos.y;
        z = pos.z;
        LC_MTX[3] = x;
        LC_MTX[7] = y;
        LC_MTX[11] = z;
    }
    psvec_set(&entry->offsetC4, LC_MTX[11], LC_MTX[7], LC_MTX[3]);

    lbl_8006DFC4(entry->rot28);
    if (fn_1_442D8(&rot, entry, 6, 0, frameB)) {
        fn_1_442D8(&start, entry, 6, 0, frameA);
        lbl_8006D5A4(&start, &rot, &rot, value);
        if (object->flags & 2) {
            rot.x = -rot.x;
            rot.y = -rot.y;
        }
        mathutil_mtxA_rotate_z((s32)(lbl_1_rodata_F68.unk_0 * rot.z));
        mathutil_mtxA_rotate_y((s32)(lbl_1_rodata_F68.unk_0 * rot.y));
        mathutil_mtxA_rotate_x((s32)(lbl_1_rodata_F68.unk_0 * rot.x));
    } else {
        lbl_8006DFC4(entry->rot58);
    }

    fzgx_value = &(unit.x);
    *fzgx_value = lbl_1_rodata_F50.unk_0;
    unit.y = lbl_1_rodata_F50.unk_0;
    unit.z = lbl_1_rodata_F50.unk_0;
    entry->scale.x = lbl_1_rodata_F50.unk_0;
    entry->scale.y = lbl_1_rodata_F50.unk_0;
    entry->scale.z = lbl_1_rodata_F50.unk_0;
    fn_1_442D8(&unit, entry, 0, 0, frameA);
    fn_1_442D8(&entry->scale, entry, 0, 0, frameB);
    lbl_8006D5A4(&unit, &entry->scale, &entry->scale, value);
    entry->scale.x *= scale.x;
    entry->scale.y *= scale.y;
    entry->scale.z *= scale.z;

    if (entry->flags & 1) {
        fn_1_44A74(object, entry);
    } else {
        lbl_8006DB74(entry->mtx);
        if (entry->parent != 0xFFFF) {
            lbl_8006DBAC(((Entry *)(object->entries + entry->parent * 0x18C))->mtx);
            fn_8006E250(&entry->offsetC4, &entry->offsetC4);
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_43E08 */

/* fzgx:begin fn_1_442D8 */
typedef struct fn_1_442D8_Key {
    u16 flags;
    u16 frame;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} fn_1_442D8_Key;
struct fn_1_442D8_Arg0 { f32 unk_0, unk_4, unk_8; };
struct fn_1_442D8_Arg1 { u8 pad_0[0xD4]; u16 unk_D4[36]; fn_1_442D8_Key *unk_11C[1]; };
extern const f32 lbl_1_rodata_F50, lbl_1_rodata_F70, lbl_1_rodata_F74, lbl_1_rodata_F78, lbl_1_rodata_F7C;
extern const f64 lbl_1_rodata_F58, lbl_1_rodata_F60;

/* Evaluate a keyframe track: linear (mode 1) or Hermite (mode 0) between the bracketing keys. */
#define EVAL_TRACK(idx, dst)                                                                        \
    {                                                                                               \
        s32 i;                                                                                      \
        u32 count = arg1->unk_D4[idx];                                                              \
        if (count != 0) {                                                                           \
            fn_1_442D8_Key *keys = arg1->unk_11C[idx];                                              \
            fn_1_442D8_Key *key;                                                                    \
            u32 start;                                                                              \
            f32 c, b, a, value, duration, t, t3, t2, three, negprod;                                \
            if (arg3 < (f32)keys[0].frame) {                                                        \
                value = keys[0].value;                                                              \
            } else if (arg3 >= (f32)keys[count - 1].frame) {                                        \
                value = keys[count - 1].value;                                                      \
            } else {                                                                                \
                key = keys;                                                                         \
                i = 0;                                                                              \
                while (arg3 >= (f32)key[1].frame) {                                                 \
                    key++;                                                                          \
                    i++;                                                                            \
                }                                                                                   \
                keys += i;                                                                          \
                key = keys;                                                                         \
                start = key[0].frame;                                                               \
                duration = (f32)((s32)key[1].frame - (s32)start);                                   \
                t = (arg3 - (f32)start) / duration;                                                 \
                value = key[0].value;                                                               \
                a = key[1].value;                                                                   \
                b = key[0].tanOut;                                                                  \
                c = key[1].tanIn;                                                                   \
                switch (key[0].flags & 3) {                                                         \
                case 1:                                                                             \
                    value = value + (f32)(t * (a - value));                                         \
                    break;                                                                          \
                case 0:                                                                             \
                    t2 = t * t;                                                                     \
                    t3 = t2 * t;                                                                    \
                    three = lbl_1_rodata_F70 * t2;                                                  \
                    negprod = lbl_1_rodata_F78 * t3;                                                \
                    value = (f32)(value * (lbl_1_rodata_F50 + ((f32)(2.0f * t3) - three))) +        \
                            (f32)(a * (negprod + three));                                           \
                    value = value + (f32)((f32)(lbl_1_rodata_F7C * duration) *                      \
                                          ((f32)(b * (t + (t3 - (f32)(2.0f * t2)))) +               \
                                           (f32)(c * (t3 - t2))));                                  \
                    break;                                                                          \
                }                                                                                   \
            }                                                                                       \
            dst = value;                                                                            \
            result = 1;                                                                             \
        }                                                                                           \
    }

s32 fn_1_442D8(struct fn_1_442D8_Arg0 *arg0, struct fn_1_442D8_Arg1 *arg1, u32 arg2, f32 arg3) {
    s32 result = 0;

    EVAL_TRACK((u16)arg2, arg0->unk_0)
    EVAL_TRACK((u16)((u16)arg2 + 1), arg0->unk_4)
    EVAL_TRACK((u16)((u16)arg2 + 2), arg0->unk_8)
    return result;
}
/* fzgx:end fn_1_442D8 */

/* fzgx:begin fn_1_449A8 noprologue */
#include "types.h"
#include "psvec.h"

extern void lbl_8006DB74(void *mtx);
extern void fn_8006E978(void *out, void *a, void *b);
extern void mathutil_mtxA_from_quat(void *q);
extern void lbl_8006DFC4(void *mtx);
extern f32 *lbl_801A6D00;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Quat;

typedef struct {
    u8 data[56];
} TmpMtx;

void fn_1_449A8(void *vector) {
    Vec3 src;
    Vec3 v;
    Quat q;
    TmpMtx m;
    Vec4 *p;

    p = (Vec4 *)lbl_801A6D00;
    src.x = p[0].x;
    src.y = p[1].x;
    src.z = p[2].x;

    lbl_8006DB74(&m);

    psvec_set(&v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C),
        *(f32 *)(0xE0000000 + 0x0C));

    fn_8006E978(&q, &src, vector);
    mathutil_mtxA_from_quat(&q);
    lbl_8006DFC4(&m);

    *(f32 *)(0xE0000000 + 0x0C) = v.x;
    *(f32 *)(0xE0000000 + 0x1C) = v.y;
    *(f32 *)(0xE0000000 + 0x2C) = v.z;
}
/* fzgx:end fn_1_449A8 */

/* fzgx:begin fn_1_451D4 */
void fn_1_451D4(void) {
    lbl_1_bss_384CC = 0;
}
/* fzgx:end fn_1_451D4 */
