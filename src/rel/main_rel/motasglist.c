#include "types.h"
#include "rel/main_rel/motasglist.h"

typedef MotaSignal SigData;

extern const f32 lbl_1_rodata_F30;
extern const f32 lbl_1_rodata_F34;
extern const f32 lbl_1_rodata_F38;

struct fn_1_41BDC_MotasglistData;
struct Fn42044Data;
struct Fn42044Key;
struct Fn42254Data;
struct Fn42254Key;

void *fn_1_41BDC(struct fn_1_41BDC_MotasglistData *data, s32 index);
struct Fn42044Key *fn_1_42044(struct Fn42044Data *data, s32 track);
struct Fn42254Key *fn_1_42254(struct Fn42254Data *data, s32 track);
void fn_1_42458(SigData *dst, const SigData *src);
extern void fn_1_42E74(void *object);
extern void fn_1_46B4(u32 heap, void *ptr, const char *file, int line);

typedef MotaEntry Elem;

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

typedef MotaTrack Ent12;

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

typedef MotaList Out;

struct Pool {
    u32 unk_0;
};

struct SigPtr {
    const SigData *value;
};

extern struct Pool lbl_801A6410;
u8 lbl_1_data_6710[0x10] = {0};
extern void *fn_1_45D0(u32 heap, u32 size, char *file, int line);

/* fzgx:begin fn_1_41518 */
Out *fn_1_41518(In *p) {
    Out *out = (Out *)fn_1_45D0(lbl_801A6410.unk_0, 0x60, "motasglist.c", 0x63);
    In *arg0 = p;
    struct SigPtr sig;
    s32 i;

    out->unk_00 = arg0->unk_20;
    out->unk_02 = arg0->unk_22 | 4;
    out->unk_0C = (Elem *)fn_1_45D0(lbl_801A6410.unk_0, (arg0->unk_04 * 52 + 31) & ~31, "motasglist.c", 0x67);
    out->unk_10 = arg0->unk_04;
    out->unk_12 = 0;
    out->unk_04 = 0;
    out->unk_01 = arg0->unk_21;
    out->unk_24 = arg0->unk_10;
    out->unk_18 = arg0->unk_18;
    out->unk_26 = arg0->unk_06;
    out->unk_28 = (Ent12 *)fn_1_45D0(lbl_801A6410.unk_0, (arg0->unk_06 * 12 + 31) & ~31, "motasglist.c", 0x70);
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
    out->unk_2C = (SigData *)fn_1_45D0(lbl_801A6410.unk_0, ((arg0->unk_21 << 4) + 31) & ~31, "motasglist.c", 0x82);
    out->unk_30 = (SigData *)fn_1_45D0(lbl_801A6410.unk_0, ((arg0->unk_21 << 4) + 31) & ~31, "motasglist.c", 0x83);
    sig.value = (const SigData *)lbl_1_data_6710;
    for (i = 0; i < arg0->unk_21; i++) {
        fn_1_42458((SigData *)((u8 *)out->unk_2C + i * 16), sig.value);
        fn_1_42458((SigData *)((u8 *)out->unk_30 + i * 16), sig.value);
    }
    {
        s32 k;
        const Src *s = (const Src *)((u8 *)arg0 + arg0->unk_08);
        u32 *paths = (u32 *)((u8 *)arg0 + arg0->unk_0C);
        const Ent8 *e = (const Ent8 *)((u8 *)arg0 + arg0->unk_24);
        for (i = 0; i < arg0->unk_06; i++) {
            Ent12 *d = &out->unk_28[i];
            d->unk_00 = out->unk_14 + e[i].unk_04;
            d->unk_04 = out->unk_0C + e[i].unk_00;
            d->unk_08 = e[i].unk_02;
            d->unk_0A = 0;
        }
        for (i = 0; i < arg0->unk_04; i++) {
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
            while (var_r27 < (*(u16 *)((u8 *)(arg0) + 16))) {
                temp_r4 = (((struct fn_1_41850_Node *)(*(void **)((u8 *)(arg0) + 12)))[var_r27].unk_28);
                if (temp_r4 != NULL) {
                    fn_1_46B4(lbl_801A6410.unk_0, temp_r4, "motasglist.c", (0x123));
                }
                var_r28 += 0x34;
                var_r27 += 1;
                            }
            temp_r4_2 = (*(void **)((u8 *)(arg0) + 20));
            if (temp_r4_2 != NULL) {
                fn_1_46B4(lbl_801A6410.unk_0, temp_r4_2, "motasglist.c", (0x125));
            }
            temp_r4_3 = (*(void **)((u8 *)(arg0) + 32));
            if (temp_r4_3 != NULL) {
                fn_1_46B4(lbl_801A6410.unk_0, temp_r4_3, "motasglist.c", (0x126));
            }
        }
        fn_1_46B4(lbl_801A6410.unk_0, (*(void **)((u8 *)(arg0) + 12)), "motasglist.c", (0x128));
    } else {
        var_r27_2 = (*(void **)((u8 *)(arg0) + 12));
        while (var_r27_2 != NULL) {
            temp_r4_4 = (*(void **)((u8 *)(var_r27_2) + 40));
            temp_r28 = (*(void **)((u8 *)(var_r27_2) + 48));
            if (temp_r4_4 != NULL) {
                fn_1_46B4(lbl_801A6410.unk_0, temp_r4_4, "motasglist.c", (0x12E));
            }
            fn_1_46B4(lbl_801A6410.unk_0, var_r27_2, "motasglist.c", (0x12F));
            var_r27_2 = temp_r28;
                    }
        temp_r4_5 = (*(void **)((u8 *)(arg0) + 32));
        if (temp_r4_5 != NULL) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_5, "motasglist.c", (0x131));
        }
    }
    temp_r4_6 = (*(void **)((u8 *)(arg0) + 40));
    if (temp_r4_6 != NULL) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_6, "motasglist.c", (0x133));
    }
    temp_r4_7 = (*(void **)((u8 *)(arg0) + 52));
    if (temp_r4_7 != NULL) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_7, "motasglist.c", (0x10B));
    }
    temp_r4_8 = (*(void **)((u8 *)(arg0) + 56));
    if (temp_r4_8 != NULL) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_8, "motasglist.c", (0x10C));
    }
    temp_r4_9 = (*(void **)((u8 *)(arg0) + 44));
    if (temp_r4_9 != NULL) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_9, "motasglist.c", (0x10D));
    }
    temp_r4_10 = (*(void **)((u8 *)(arg0) + 48));
    if (temp_r4_10 != NULL) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_10, "motasglist.c", (0x10E));
    }
    (*(void **)((u8 *)(arg0) + 52)) = NULL;
    (*((u8 *)(arg0) + 39)) = 0;
    (*(void **)((u8 *)(arg0) + 56)) = NULL;
    (*(s32 *)((u8 *)(arg0) + 60)) = 0;
    (*(s32 *)((u8 *)(arg0) + 64)) = 0;
    (*(s16 *)((u8 *)(arg0) + 72)) = 0;
    (*((u8 *)(arg0) + 76)) = 0;
    temp_r4_11 = (*(void **)((u8 *)(arg0) + 8));
    if ((temp_r4_11 != NULL) && !((*(u16 *)((u8 *)(arg0) + 2)) & 2)) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_11, "motasglist.c", (0x137));
    }
    fn_1_46B4(lbl_801A6410.unk_0, arg0, "motasglist.c", (0x138));
}
/* fzgx:end fn_1_41850 */

/* fzgx:begin fn_1_41B18 */
typedef struct Node_41B18 Node_41B18;
struct Node_41B18 {
    u8 pad[0x30];
    Node_41B18 *next;
};

typedef struct Object {
    u8 pad[2];
    u16 flags;
    Node_41B18 *data;
} Object;


void *fn_1_41B18(Object *obj, s32 track, s32 index) {
    Object *result;
    Node_41B18 *node;
    int i;

    result = fn_1_41BDC((struct fn_1_41BDC_MotasglistData *)obj, track);
    if ((obj->flags & 1) != 0) {
        return (char *)result->data + index * 0x34;
    }

    node = result->data;
    for (i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}
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

/* fzgx:begin fn_1_41C18 */
#include "types.h"
#include "rel/main_rel/motasglist.h"

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


extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern void fn_1_41328(Sig_fn_1_41328_RelocData *);

void fn_1_41C18(MotaList *arg0, u32 arg1) {
    s32 i;
    MotaEntry *entry;
    s32 index;

    arg0->unk_04 = arg1;
    fn_1_41328((Sig_fn_1_41328_RelocData *)arg1);
    if (arg0->unk_02 & 4) {
        for (i = 0; i < arg0->unk_10; i++) {
            entry = &arg0->unk_0C[i];
            index = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)arg1,
                             (const char *)arg0->unk_14 + entry->unk_1C);
            entry->unk_02 = index;
            if (entry->unk_02 == 65535) {
                entry->unk_02 = 0;
            }
        }
    }
}
/* fzgx:end fn_1_41C18 */

/* fzgx:begin fn_1_41CB8 */
typedef struct Fn41CB8Node {
    u8 pad0[0x30];
    struct Fn41CB8Node *next;
} Fn41CB8Node;

typedef struct Fn41CB8Entry {
    u8 pad0[4];
    Fn41CB8Node *next;
    u8 pad8[2];
    u16 count;
} Fn41CB8Entry;

typedef struct Fn41CB8Data {
    u8 pad0[1];
    u8 count;
    u16 flags;
    u8 pad4[4];
    void *resource;
    u8 padC[6];
    u16 index;
    u8 pad14[18];
    u8 limit;
    u8 pad27[1];
    Fn41CB8Entry *table_a;
    void *items_a;
    void *items_b;
    Fn41CB8Entry *table_b;
    u8 pad38[20];
    u8 base_index;
} Fn41CB8Data;


static inline void fn_1_41CB8_walk(Fn41CB8Entry *entry, int n) {
    Fn41CB8Node *node;
    int j;
    node = entry->next;
    j = 0;
    while (j < n) {
        node = node->next;
        j++;
    }
}


void fn_1_41CB8(Fn41CB8Data *data) {
    Fn41CB8Entry *entry;
    u32 offset;
    int i;
    void *a;
    void *b;
    void *c;
    void *resource;

    fn_1_42E74(data->resource);

    if (data->index < data->limit) {
        entry = (Fn41CB8Entry *)((u8 *)data->table_a + data->index * 12);

    } else if (data->table_b != 0) {
        entry = (Fn41CB8Entry *)((u8 *)data->table_b
            + (data->index - data->base_index) * 12);
    }

    if ((data->flags & 1) == 0) {
        fn_1_41CB8_walk(entry, entry->count);
    }

    i = 0;
    offset = 0;
    while (i < data->count) {
        a = fn_1_42044((struct Fn42044Data *)data, i);
        b = (u8 *)data->items_a + offset;
        c = (u8 *)data->items_b + offset;
        if (a != 0) {
            resource = fn_1_42254((struct Fn42254Data *)data, i);
        } else {
            a = lbl_1_data_6710;
            resource = lbl_1_data_6710;
        }
        if (((0) == ((*(u16 *)b & 4)))) {
            fn_1_42458(b, resource);
        }
        fn_1_42458(c, a);
        offset += 16;
        i++;
    }
}
/* fzgx:end fn_1_41CB8 */

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
    delta = (entry_b->frame - entry_a->frame);
    if (lbl_1_rodata_F34 == delta) {
        delta = lbl_1_rodata_F30;
    }
    result->value = (data->object->value - entry_a->frame) / delta;
    if (result->first == result->second) {
        start = entry_a->offset;
        end = entry_b->offset;
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

static inline Fn42044Node *fn_1_42044_node(Fn42044Entry *entry, u16 flags) {
    Fn42044Node *node;
    s32 i;

    if (flags & 1) {
        node = (Fn42044Node *)((u8 *)entry->nodes + entry->count * 0x34);
    } else {
        node = entry->nodes;
        for (i = 0; i < entry->count; i++) {
            node = node->next;
        }
    }
    return node;
}

Fn42044Key *fn_1_42044(Fn42044Data *data, s32 track) {
    u16 index = data->index;
    u8 count = data->entryCount;
    Fn42044Entry *entry;
    u16 flags;
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
    node = fn_1_42044_node(entry, flags);

    t = &node->tracks[track];
    frame = data->timer->time;
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
    frame = data->timer->time;
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
void fn_1_42458(SigData *dst, const SigData *src) {
    dst->value0 = src->value0;
    dst->value8 = src->value8;
    dst->value2 = src->value2;
    dst->value4 = src->value4;
}
/* fzgx:end fn_1_42458 */
