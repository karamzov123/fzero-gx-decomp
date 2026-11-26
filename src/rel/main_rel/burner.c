#include "types.h"
#include "rel/main_rel/globals.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"
#include "dolphin/os/OSFastCast.h"
#include "lc_mtx.h"
#include "mathutil_mtxA_set_translate.h"

extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_46B4(void *, void *, char *, u32);
extern void fn_800794F0(void *dst, void *src, s32 size);
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void lbl_8006D7B0(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s32);
extern s32 strlen(const char *);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 fn_8006FC1C(const char *, const char *);
extern u32 fn_1_9D260(void);
extern s32 fn_1_3F0C8(void);
extern u8 lbl_1_bss_8E51D;
extern u8 fn_1_7B074(void);
extern void fn_8006FDEC(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);
extern void *fn_1_12F118(void);
extern void *fn_1_36AD0(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern void fn_80008BA8(void *arg0, const void *arg1, int arg2);

extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern void *fn_1_4630(void *heap, u32 size, char *file, u32 line);
extern void *memset(void *dest, int value, u32 size);
extern u32 fn_1_584AC(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);
extern void fn_1_862D4(u32 arg0, void *arg1);
extern u32 fn_1_1FB80(void *arg0, s32 arg1);
extern u32 fn_1_41488(u32 arg0, void *arg1);
extern void fn_1_4270C(void *arg0, u32 arg1, u32 arg2);
extern f32 lbl_1_rodata_4260[16];
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_9194[10];
extern u8 lbl_1_rodata_85AC[60];
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8A4C;
extern s8 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_91BC;
extern void fn_1_4E724(void *);

typedef struct BurnerObj {
    struct BurnerObj *prev;
    struct BurnerObj *next;
    s32 type;
    u8 body[0x4A0];
} BurnerObj;

typedef struct {
    BurnerObj *prev;
    BurnerObj *next;
    s8 used[120];
    BurnerObj objs[120];
} BurnerPool;

typedef struct BurnerType {
    void (*init)(BurnerObj *obj);
    void (*remove)(BurnerObj *obj, struct BurnerType *type);
    void (*f8)(void);
    void (*draw)(void);
    void (*f10)(void);
} BurnerType;

void fn_1_9885C();
void fn_1_988D8();
void fn_1_988DC();
void fn_1_98E18();
void fn_1_9A0A4();
void *fn_1_986A4(void);
void fn_1_987D0(BurnerObj *obj);
void fn_1_98804(BurnerObj *obj);
void fn_1_98840(BurnerObj *obj);
void fn_1_98640(BurnerObj *src);

/* WARNING: compiler-diff device, not original code. The "burner.c" string stays in its data unit, which also
   holds the .data padding before the next unit. */
extern char lbl_1_data_27E08[];

BurnerType lbl_1_data_27DE0[2] = {
    {fn_1_9885C, fn_1_988D8, fn_1_988DC, fn_1_98E18, fn_1_9A0A4},
};

f32 lbl_1_bss_6EA00 = 0.0f;
BurnerPool *lbl_1_bss_6EA04;
u32 lbl_1_bss_6EA08;
s32 lbl_1_bss_6EA0C;

/* fzgx:begin fn_1_981C4 */
void fn_1_981C4(void) {
    lbl_1_bss_6EA04 = fn_1_4630(lbl_801A6410, sizeof(BurnerPool), lbl_1_data_27E08, 378);
    lbl_1_bss_6EA04->next = NULL;
    lbl_1_bss_6EA04->prev = NULL;
    lbl_1_bss_6EA08 = 0;
    lbl_1_bss_6EA0C = 0;
}
/* fzgx:end fn_1_981C4 */

/* fzgx:begin fn_1_98230 */
typedef struct BurnerNode BurnerNode;
typedef struct BurnerEntry BurnerEntry;
typedef void (*BurnerCallback)(BurnerNode *, BurnerEntry *);

struct BurnerNode {
    u8 pad_0[0x4];
    BurnerNode *next;
    u32 index;
};

struct BurnerEntry {
    u8 pad_0[0x8];
    BurnerCallback callback;
    u8 pad_C[0x8];
};

/* Dispatchs each queued burner callback, then advances the burner frame. */
void fn_1_98230(void) {
    BurnerNode *node = (BurnerNode *)lbl_1_bss_6EA04->next;

    while (node != 0) {
        BurnerNode *next = node->next;
        BurnerEntry *entry =
            (BurnerEntry *)((u8 *)&lbl_1_data_27DE0 + node->index * 0x14);

        entry->callback(node, entry);
        node = next;
    }

    lbl_1_bss_6EA08 += 1;
    if ((s32)lbl_1_bss_6EA08 >= 4) {
        lbl_1_bss_6EA08 = 0;
    }
}
/* fzgx:end fn_1_98230 */

/* fzgx:begin fn_1_982C4 */
  // array of 0x4AC-byte records

typedef struct Fn1982C4Node Fn1982C4Node;

struct Fn1982C4Node {
    u8 pad_0[0x4];
    Fn1982C4Node *next;
    u32 index;
};

typedef struct {
    u8 pad_0[0x4];
    void (*callback)(Fn1982C4Node *);
    u8 pad_8[0xC];
} Fn1982C4Entry;

void fn_1_982C4(void) {
    Fn1982C4Node *node = (Fn1982C4Node *)lbl_1_bss_6EA04->next;

    while (node != 0) {
        Fn1982C4Node *next = node->next;
        Fn1982C4Entry *entry = (Fn1982C4Entry *)&lbl_1_data_27DE0;
        entry = entry + node->index;
        entry->callback(node);
        node = next;
    }

    fn_1_46B4(lbl_801A6410, lbl_1_bss_6EA04, lbl_1_data_27E08, 0x1d0);
}
/* fzgx:end fn_1_982C4 */

/* fzgx:begin fn_1_9835C */
typedef struct BurnerNode_9835C BurnerNode_9835C;
typedef struct BurnerEntry_9835C BurnerEntry_9835C;

struct BurnerNode_9835C {
    u8 pad_0[0x4];
    BurnerNode_9835C *next;
    u32 index;
};

typedef void (*BurnerCallback_9835C)(BurnerNode_9835C *, BurnerEntry_9835C *);

struct BurnerEntry_9835C {
    u8 pad_0[0xC];
    BurnerCallback_9835C callback;
    u8 pad_10[0x4];
};

void fn_1_9835C(void) {
    BurnerNode_9835C *node = (BurnerNode_9835C *)lbl_1_bss_6EA04->next;

    while (node != 0) {
        BurnerNode_9835C *next = node->next;
        BurnerEntry_9835C *entry =
            (BurnerEntry_9835C *)((u8 *)&lbl_1_data_27DE0 + node->index * 0x14);
        entry->callback(node, entry);
        node = next;
    }
}
/* fzgx:end fn_1_9835C */

/* fzgx:begin fn_1_983CC */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Fn1983CCVec3;

typedef struct {
    u8 unk_00[0x03];
    s8 unk_03;
    u8 unk_04[0x3C];
    s8 unk_40;
    u8 unk_41[0x03];
    Fn1983CCVec3 unk_44;
    Fn1983CCVec3 unk_50;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
} Fn1983CCEntry;

typedef struct {
    u8 unk_00[0x08];
    s32 unk_08;
    Fn1983CCVec3 unk_0C;
    Fn1983CCVec3 unk_18;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    u8 unk_40[0x08];
    void *unk_48;
    u8 unk_4C[0x458];
    f32 unk_4A4;
} Fn1983CCWorkData;

typedef union {
    Fn1983CCWorkData data;
    u8 raw[0x4B0];
} Fn1983CCWork;


void fn_1_983CC(void *arg0, Fn1983CCEntry *entries) {
    Fn1983CCWork work;
    Fn1983CCEntry *entry;
    s32 i;

    memset(&work, 0, 0x4AC);
    work.data.unk_48 = arg0;
    entry = entries;
    for (i = 0; i < entries->unk_03; i++) {
        work.data.unk_08 = entry->unk_40;
        work.data.unk_18 = entry->unk_50;
        work.data.unk_0C = entry->unk_44;
        work.data.unk_24 = entry->unk_5C / 14.0f;
        work.data.unk_28 = entry->unk_60;
        work.data.unk_2C = entry->unk_64;
        work.data.unk_30 = entry->unk_68;
        work.data.unk_34 = entry->unk_6C;
        work.data.unk_38 = entry->unk_70;
        work.data.unk_3C = entry->unk_74;
        work.data.unk_4A4 = lbl_1_bss_6EA00;
        fn_1_98640((BurnerObj *)&work);
        entry = (Fn1983CCEntry *)((u8 *)entry + 0x38);
    }
}
/* fzgx:end fn_1_983CC */

/* fzgx:begin fn_1_984F0 */
typedef struct BurnerNode_984F0 BurnerNode_984F0;

struct BurnerNode_984F0 {
    u8 pad_0[0x4];
    BurnerNode_984F0 *next;
    u32 index;
    u8 pad_C[0x3C];
    u32 key;
};

typedef void (*BurnerCallback_984F0)(BurnerNode_984F0 *, void *);


void fn_1_984F0(void *object) {
    BurnerNode_984F0 *node = (BurnerNode_984F0 *)lbl_1_bss_6EA04->next;
    u8 *table = (u8 *)&lbl_1_data_27DE0;

    while (node != 0) {
        BurnerNode_984F0 *next = node->next;

        if (node->key == (u32)object) {
            BurnerCallback_984F0 callback = *(BurnerCallback_984F0 *)(table + node->index * 0x14 + 0x4);
            callback(node, table + node->index * 0x14);
            fn_1_98840((BurnerObj *)node);
            fn_1_987D0((BurnerObj *)node);
        }

        node = next;
    }
}
/* fzgx:end fn_1_984F0 */

/* fzgx:begin fn_1_98590 */
typedef struct Fn198590Node Fn198590Node;

struct Fn198590Node {
    u8 unk_00[0x04];
    Fn198590Node *next;
    u8 unk_08[0x6C];
    f32 unk_74;
    u8 unk_78[0x42C];
    f32 unk_4A4;
};

// Reset each linked burner's timing values and advance the shared update slot.
void fn_1_98590(void) {
    Fn198590Node *node = (Fn198590Node *)lbl_1_bss_6EA04->next;
    f32 value = 0.0f;

    while (node != 0) {
        Fn198590Node *next = node->next;

        node->unk_74 = value;
        node->unk_4A4 = value;
        node = next;
    }

    lbl_1_bss_6EA08 += 1;
    if ((s32)lbl_1_bss_6EA08 >= 4) {
        lbl_1_bss_6EA08 = 0;
    }
}
/* fzgx:end fn_1_98590 */

/* fzgx:begin fn_1_985EC */
typedef struct BurnerEntry_985EC BurnerEntry_985EC;

struct BurnerEntry_985EC {
    u8 unk_00[0x04];
    BurnerEntry_985EC *next;
    u8 unk_08[0x40];
    u32 key;
    u8 unk_4C[0x28];
    f32 value;
    u8 unk_78[0x430];
    u32 flags;
};

// Reset matching burner entries while walking the global entry list.
void fn_1_985EC(u32 key) {
    BurnerEntry_985EC *node = (BurnerEntry_985EC *)lbl_1_bss_6EA04->next;
    f32 value = 0.0f;
    u32 zero = 0;

    while (node != 0) {
        BurnerEntry_985EC *next = node->next;
        if (node->key == key) {
            node->value = value;
            node->flags = zero;
        }
        node = next;
    }
}
/* fzgx:end fn_1_985EC */

/* fzgx:begin fn_1_98634 */
void fn_1_98634(f32 value) {
    lbl_1_bss_6EA00 = value;
}
/* fzgx:end fn_1_98634 */

/* fzgx:begin fn_1_98640 */
void fn_1_98640(BurnerObj *src) {
    BurnerObj *obj = fn_1_986A4();

    fn_800794F0(obj, src, sizeof(BurnerObj));
    fn_1_98804(obj);
    lbl_1_data_27DE0[obj->type].init(obj);
}
/* fzgx:end fn_1_98640 */

/* fzgx:begin fn_1_986A4 */
void *fn_1_986A4(void) {
    BurnerObj *obj;
    s8 *used = lbl_1_bss_6EA04->used;
    s32 n;

    for (n = 120; n != 0; n--, used++) {
        if (*used == 0) {
            break;
        }
    }
    if (n == 0) {
        return NULL;
    }
    *used = 1;
    obj = &lbl_1_bss_6EA04->objs[120 - n];
    obj->prev = NULL;
    obj->next = NULL;
    return obj;
}
/* fzgx:end fn_1_986A4 */

/* fzgx:begin fn_1_987D0 */
void fn_1_987D0(BurnerObj *obj) {
    lbl_1_bss_6EA04->used[((u32)obj - (u32)lbl_1_bss_6EA04->objs) / sizeof(BurnerObj)] = 0;
}
/* fzgx:end fn_1_987D0 */

/* fzgx:begin fn_1_98804 */
void fn_1_98804(BurnerObj *obj) {
    BurnerObj *next = lbl_1_bss_6EA04->next;

    obj->next = next;
    obj->prev = (BurnerObj *)lbl_1_bss_6EA04;
    if (next != NULL) {
        next->prev = obj;
    }
    lbl_1_bss_6EA04->next = obj;
}
/* fzgx:end fn_1_98804 */

/* fzgx:begin fn_1_98840 */
void fn_1_98840(BurnerObj *obj) {
    BurnerObj *next = obj->next;
    BurnerObj *prev = obj->prev;

    prev->next = next;
    if (next != NULL) {
        next->prev = prev;
    }
}
/* fzgx:end fn_1_98840 */

/* fzgx:begin fn_1_9885C */
typedef struct {
    u32 unk_0;
    s32 unk_4;
    u32 unk_8;
} fn_1_9885C_Triple;

struct fn_1_9885C_Arg0 {
    u8 pad_0[0x28];
    fn_1_9885C_Triple unk_28;
    u8 pad_34[0xC];
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u8 pad_4C[0x41C];
    fn_1_9885C_Triple unk_468;
};

void fn_1_9885C(struct fn_1_9885C_Arg0 *arg0) {
    u32 v0 = arg0->unk_48;
    arg0->unk_40 = 0;
    arg0->unk_468 = arg0->unk_28;
    arg0->unk_44 = fn_1_584AC() & 1;
    lbl_8006D7DC((void *)(v0 + 124));
    lbl_8006DFC4((void *)(v0 + 236));
    lbl_8006E1B0((void *)((u32)arg0 + 12), (void *)((u32)arg0 + 88));
}
/* fzgx:end fn_1_9885C */

/* fzgx:begin fn_1_988D8 */
// fn_1_988D8: empty in retail (single blr).
void fn_1_988D8(void) {
}
/* fzgx:end fn_1_988D8 */

/* fzgx:begin fn_1_988DC */
extern s16 camera_get_mode(void);
extern u32 fn_1_58C4(void);
extern u32 fn_1_8645C(s32 arg0, u32 arg1);
extern void lbl_8006E1B0(void *mtx, void *dst);
extern void fn_1_58E3C(void *entry);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E0A4(void *arg0);
extern void *fn_1_868C0(s8 arg0);
extern void *fn_1_14DDF4(u32 arg0);
extern void lbl_8006E1C0(void *mtx, void *dst);
extern void lbl_8006D668(void *dst);
extern u32 fn_1_584AC(void);
extern void lbl_8006DB74(void *arg0);
extern void lbl_8006DD14(void *arg0, void *arg1);
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6D00;


typedef struct BurnerFxEntry {
    u8 pad_00[0x0c];
    u16 unk_0c;
    u8 pad_0e[0x0a];
    s16 unk_18;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    u8 pad_28[0x6c];
    Vec3 unk_94;
    u8 pad_a0[0x48];
} BurnerFxEntry;

/* WARNING: compiler-diff device, not original code. */
#pragma opt_common_subs off
void fn_1_988DC(void *arg0) {
    BurnerFxEntry entry;
    Vec3 newPos;
    Vec3 delta;
    Vec3 prevPos;
    Vec3 mtx;
    Vec3 tgt;
    u8 *p;
    f64 scale;
    f64 var_f0;
    f32 ratio;
    s32 cnt;
    s32 cur;
    s32 prev;
    s32 tmp;
    u32 flags;
    s32 c8;
    s32 c100;
    s32 c20;
    s32 i;
    void *obj;
    void *obj2;
    s16 id;
    f32 old;
    f32 v;

    p = *(u8 **)((u8 *)arg0 + 72);
    i = 0;
    flags = *(u32 *)p;
    c8 = flags & 0x80000;
    tmp = *(s32 *)((u8 *)arg0 + 88);
    c20 = flags & 0x20;
    c100 = flags & 0x100000;
    *(s32 *)&prevPos.x = tmp;
    tmp = *(s32 *)((u8 *)arg0 + 92);
    *(s32 *)&prevPos.y = tmp;
    tmp = *(s32 *)((u8 *)arg0 + 96);
    *(s32 *)&prevPos.z = tmp;
    if (c8 != 0) {
        *(s32 *)((u8 *)arg0 + 1192) = 0x1e;
    }
    if (c100 != 0) {
        *(s32 *)((u8 *)arg0 + 1192) = 0x3c;
    }
    prev = *(s32 *)((u8 *)arg0 + 1192);
    if (prev != 0) {
        i = 1;
        *(s32 *)((u8 *)arg0 + 1192) = prev - 1;
    }
    cnt = *(s32 *)((u8 *)arg0 + 1192);
    cnt = cnt * cnt;
    tmp = *(s32 *)((u8 *)arg0 + 68);
    *(s32 *)((u8 *)arg0 + 68) = tmp + 1;
    cur = *(s32 *)((u8 *)arg0 + 64);
    ratio = cnt / 900.0f;
    switch (cur) {
    case 0:
        if (c20 != 0) {
            *(s32 *)((u8 *)arg0 + 64) = 1;
            *(f32 *)((u8 *)arg0 + 116) *= 2.0f;
            if (*(f32 *)((u8 *)arg0 + 116) > 10.0f) {
                *(f32 *)((u8 *)arg0 + 116) = 10.0f;
            }
        }
        if (c100 != 0) {
            *(s32 *)((u8 *)arg0 + 64) = 2;
        }
        if (i == 0) {
            break;
        }
        if (*(u32 *)((u8 *)arg0 + 64) == 2) {
            scale = 0.8 * ratio;
            old = *(f32 *)((u8 *)arg0 + 116);
            v = (old * (1.0 + scale));
            *(f32 *)((u8 *)arg0 + 116) = v;
        } else {
            scale = 0.1 * ratio;
            old = *(f32 *)((u8 *)arg0 + 116);
            v = (old * (1.0 + scale));
            *(f32 *)((u8 *)arg0 + 116) = v;
        }
        v = *(f32 *)((u8 *)arg0 + 116);
        if (v > 10.0f) {
            *(f32 *)((u8 *)arg0 + 116) = 10.0f;
        }
        if ((c8 | c100) == 0) {
            break;
        }
        if (*(s16 *)(p + 4) != camera_get_mode()) {
            break;
        }
        if (fn_1_58C4() != 1) {
            break;
        }
        memset(&entry, 0, 0xe8);
        entry.unk_0c = 6;
        id = *(s16 *)(p + 4);
        entry.unk_18 = id;
        fn_1_8645C(id, lbl_801A6D00);
        lbl_8006E1B0((u8 *)arg0 + 0xc, (u8 *)&entry + 0x3c);
        entry.unk_94 = *(Vec3 *)((u8 *)arg0 + 0xc);
        entry.unk_1c = 0.003921568859368563f * *(f32 *)((u8 *)arg0 + 40);
        entry.unk_20 = 0.003921568859368563f * *(f32 *)((u8 *)arg0 + 44);
        entry.unk_24 = 0.003921568859368563f * *(f32 *)((u8 *)arg0 + 48);
        fn_1_58E3C(&entry);
        break;
    case 2:
        if (i == 0) {
            *(s32 *)((u8 *)arg0 + 64) = 0;
        }
        break;
    case 1:
        if (c20 == 0) {
            *(s32 *)((u8 *)arg0 + 64) = 0;
        }
        break;
    }
    lbl_8006DBAC(p + 0x14c);
    if (*(s16 *)(p + 6) > 0x28) {
        obj = fn_1_868C0((s8)*(s16 *)(p + 4));
        if (obj != NULL) {
            if (*(u32 *)((u8 *)obj + 928) != 0) {
                lbl_8006E0A4(fn_1_14DDF4(*(u32 *)((u8 *)obj + 928)));
            }
        }
    }
    lbl_8006E1B0((u8 *)arg0 + 0xc, &newPos);
    delta.x = newPos.x - prevPos.x;
    delta.y = newPos.y - prevPos.y;
    delta.z = newPos.z - prevPos.z;
    lbl_8006E1C0((u8 *)arg0 + 0x18, &mtx);
    lbl_8006D668(&mtx);
{
    f32 var_f4;
    var_f4 = *(f32 *)(p + 548);
    if (lbl_1_bss_960 != 0xe) {
        v = *(f32 *)(p + 512);
        var_f0 = v < 0.0 ? 0.0 : (v > 1.0 ? 1.0 : v);
        var_f4 = (var_f4 * var_f0);
    }
    if (*(u16 *)(p + 532) != 0) {
        var_f4 *= 0.0f;
    }
    if (c20 != 0) {
        var_f4 *= 2.0f;
    }
    if (i != 0) {
        if (*(u32 *)((u8 *)arg0 + 64) == 2) {
            scale = 0.8 * ratio;
            var_f4 = (var_f4 * (1.0 + scale));
        } else {
            scale = 0.1 * ratio;
            var_f4 = (var_f4 * (1.0 + scale));
        }
    }
    old = *(f32 *)((u8 *)arg0 + 116);
    v = 0.15f * (var_f4 - old);
}
    *(f32 *)((u8 *)arg0 + 116) = old + v;
    v = *(f32 *)((u8 *)arg0 + 116);
    if (v > 10.0f) {
        *(f32 *)((u8 *)arg0 + 116) = 10.0f;
    }
    *(s16 *)((u8 *)arg0 + 112) = (u16)fn_1_584AC() - 0x8000;
    if ((c20 != 0) || (i != 0)) {
        tgt = *(Vec3 *)((u8 *)arg0 + 52);
    } else {
        tgt = *(Vec3 *)((u8 *)arg0 + 40);
    }
    old = *(f32 *)((u8 *)arg0 + 1128);
    v = 0.1f * (tgt.x - old);
    *(f32 *)((u8 *)arg0 + 1128) = old + v;
    old = *(f32 *)((u8 *)arg0 + 1132);
    v = 0.11f * (tgt.y - old);
    *(f32 *)((u8 *)arg0 + 1132) = old + v;
    old = *(f32 *)((u8 *)arg0 + 1136);
    v = 0.12f * (tgt.z - old);
    *(f32 *)((u8 *)arg0 + 1136) = old + v;
    *(Vec3 *)((u8 *)arg0 + 88) = newPos;
    *(Vec3 *)((u8 *)arg0 + 100) = delta;
    *(Vec3 *)((u8 *)arg0 + 76) = mtx;
    if (*(s16 *)(p + 6) > 0x28) {
        obj2 = fn_1_868C0((s8)*(s16 *)(p + 4));
        if ((obj2 != NULL) && (*(u32 *)((u8 *)obj2 + 928) != 0)) {
            lbl_8006DBAC(p + 0x14c);
            lbl_8006E0A4(fn_1_14DDF4(*(u32 *)((u8 *)obj2 + 928)));
            lbl_8006DB74((u8 *)arg0 + 0x474);
        }
    } else {
        lbl_8006DD14(p + 0x14c, (u8 *)arg0 + 0x474);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_988DC */

/* fzgx:begin fn_1_98E18 */
/* begin game/main_rel/burner_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

// Types (and the externs that name them) of burner.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct Node_98E18 {
    struct Node_98E18 *prev;
    struct Node_98E18 *next;
} Node_98E18;

typedef struct fn_1_984F0_BurnerNode fn_1_984F0_BurnerNode;

struct fn_1_984F0_BurnerNode {
    u8 pad_0[0x4];
    fn_1_984F0_BurnerNode *next;
    u32 index;
    u8 pad_C[0x3C];
    u32 key;
};

typedef struct {
    u8 pad[0x60];
} fn_1_9CD6C_GlobalState;

typedef struct {
    f32 x, y, z;
} fn_1_98E18_Vec;

typedef struct {
    u8 pad0[0x4c];
    fn_1_98E18_Vec dir;
    fn_1_98E18_Vec pos;
    u8 pad64[0x10];
    f32 radius;
} fn_1_98E18_Burner;

typedef struct {
    u8 pad0[0x4];
    void (*callback)(void);
    fn_1_98E18_Burner *entry;
} fn_1_98E18_Event;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CCE8_Vec3;

typedef struct {
    u8 pad[0x1e];
    u8 count;
} Burner;

struct FormatTable {
    const char *fmt[44][6];
};

struct FormatEntry {
    s16 f[5];
};

struct EntryTable {
    struct FormatEntry e[44];
};

struct fn_1_98804_Arg0_98E18 {
    u32 unk_0;
    u32 unk_4;
};

typedef struct {
    u8 pad[8];
    u8 *entries;
} fn_1_9D360_BurnerTable;

extern void *fn_1_5448C(fn_1_98E18_Vec *pos);
extern void fn_8006E294(fn_1_9CCE8_Vec3 *);
extern void fn_80077F8C(Burner *);
extern const struct FormatTable lbl_1_rodata_7050;
extern const struct EntryTable lbl_1_rodata_6E38;

#endif  // GAME_MAIN_REL_BURNER_TYPES_H

/* end game/main_rel/burner_types.h */

extern s16 camera_get_mode(void);
extern u32 fn_1_58C4(void);
extern void *memset(void *dest, int value, u32 size);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E0A4(void *arg0);
extern void *fn_1_868C0(s8 index);
extern void *fn_1_14DDF4(u32 arg0);
extern void lbl_8006E1C0(void *mtx, void *dst);
extern void lbl_8006D668(void *dst);
extern u32 fn_1_584AC(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DD14(void *arg0, void *arg1);
extern u32 lbl_801A6D00;
extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void * fn_1_548AC(u32 amount);
void fn_1_98F28();
extern void fn_1_5489C(void **arg0, void **arg1);
extern int sprintf(char *s, const char *format, ...);
extern s32 fn_1_46DC4(s32 value);
extern u32 fn_80077A18();
extern char *strcpy(char *, const char *);
extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void lbl_8006D7B0(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s32);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 fn_8006FC1C(const char *, const char *);
extern u32 fn_1_9D260(void);
extern u8 lbl_1_bss_8E51D;
extern u8 fn_1_7B074(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);
extern void * fn_1_12F118(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern void *fn_1_4630(void *heap, u32 size, char *file, u32 line);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DFC4(void *);
extern void fn_1_862D4(u32 arg0, void *arg1);
extern u32 fn_1_1FB80(void *arg0, s32 arg1);
extern u32 fn_1_41488(u32 arg0, void *arg1);
extern void fn_1_4270C(void *arg0, u32 arg1, u32 arg2);
extern f32 lbl_1_rodata_4260[16];
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D848(f32);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_9194[10];
extern u8 lbl_1_rodata_85AC[60];
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_91BC;
extern void fn_1_4E724(void *);
extern void fn_1_103054(void);
extern void fn_1_9D2EC(void);






void fn_1_98E18(fn_1_98E18_Burner *b) {
    fn_1_98E18_Vec p;
    void *data;
    fn_1_98E18_Event *event;
    f32 r;

    p = b->pos;
    r = 0.5f * (10.0f * (b->radius / 0.5f));
    p.x = p.x + (f32)(b->dir.x * r);
    p.y = p.y + (f32)(b->dir.y * r);
    p.z = p.z + (f32)(b->dir.z * r);
    r += 1.7f;

    lbl_8006DCA4();
    if (fn_1_54E34( (fn_1_98E18_Vec *)(&p), r)) {
        lbl_8006DCA4();
        data = fn_1_5448C(&b->pos);
        event = (fn_1_98E18_Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->callback = fn_1_98F28;
            event->entry = b;
            fn_1_5489C( (void **)(data), (void **)(event));
        }
    }
}
/* fzgx:end fn_1_98E18 */

/* fzgx:begin fn_1_98F28 */
typedef Vec3 fn_1_98F28_Vec;

typedef struct {
    u8 r, g, b, a;
} fn_1_98F28_Color;

typedef struct {
    fn_1_98F28_Vec pos;
    f32 size;
    s16 rot;
    u16 flags;
    fn_1_98F28_Color color;
} fn_1_98F28_Sprite;

typedef struct {
    u8 pad_0[0x4];
    s16 cam;
    s16 kind;
} fn_1_98F28_Owner;

typedef struct {
    u8 pad_0[0x8];
    fn_1_98F28_Vec pos;
    u8 pad_14[0x10];
    void *tex;
} fn_1_98F28_Emitter;

typedef struct {
    u8 pad_0[0xC];
    u8 rot[0x18];
    f32 scale;
    u8 pad_28[0x1C];
    s32 flags;
    fn_1_98F28_Owner *owner;
    fn_1_98F28_Vec dir;
    fn_1_98F28_Vec pos;
    u8 pad_64[0xC];
    s16 angle;
    f32 speed;
    fn_1_98F28_Vec trail[4][21];
    fn_1_98F28_Vec color;
    u8 mtx[0x30];
    f32 bright;
    s32 boost;
} fn_1_98F28_Burner;

typedef struct {
    u8 pad_0[0x8];
    fn_1_98F28_Burner *burner;
} fn_1_98F28_Event;


extern f32 fn_1_9A0A8(u8 *p);
extern f32 fn_1_A71AC(void);
extern f32 fn_800728A8(s32, s32, s32, s32);
extern f32 lbl_8006D534(void *, void *);
extern s16 camera_get_mode(void);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern u32 fn_1_584AC(void);
extern int fn_1_6EC0(u8);
extern u32 fn_1_5910(void);
extern u32 fn_1_58C4(void);
extern void fn_1_9E608(s32, fn_1_98F28_Sprite *);
extern void fn_1_9EA94(fn_1_98F28_Sprite *);
extern void fn_1_6A0C(u8, u32);
extern u32 fn_800720B0(u32);
extern s32 lbl_8006D9D8(void *);
extern void lbl_8006D7B0(s32);
extern void lbl_8006DCA4(void);
extern void *memset(void *dest, int value, u32 size);
extern void fn_80072864(u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DF44(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *arg0);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1C0(void *mtx, void *dst);
extern u32 lbl_801A6D00;

#define LC_MTX ((f32 *)LC_BASE)

static inline void fn_1_98F28_near_clip(f32 z, f32 depth) {
    if (z < -(depth + 0.1f)) {
        lbl_8006DB74((void *)(lbl_801A6D00 + 0x60));
        lbl_8006D758();
        lbl_8006E14C((depth + z) / z);
        lbl_8006DFC4((void *)(lbl_801A6D00 + 0x60));
    }
}

static inline void fn_1_98F28_min(f32 *v, f32 hi) {
    if (*v > hi) {
        *v = hi;
    }
}

static inline f32 fn_1_98F28_clamp(f32 v, f32 lo, f32 hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

void fn_1_98F28(fn_1_98F28_Event *event) {
    fn_1_98F28_Burner *b = event->burner;
    s16 ang;
    fn_1_98F28_Emitter *em;
    fn_1_98F28_Owner *owner = b->owner;
    s32 i;
    fn_1_98F28_Vec pos;
    fn_1_98F28_Vec dir;
    fn_1_98F28_Vec fwd;
    fn_1_98F28_Vec color;
    f32 size;
    f32 bright;
    f32 speed;
    f32 sz;
    f32 t;
    f32 fade;
    f32 dist;
    f32 z;
    fn_1_98F28_Emitter *emit;

    color = b->color;
    bright = fn_1_9A0A8((u8 *)owner);
    if (1.0f == bright) {
        if (b->bright > 0.0f) {
            bright = b->bright;
        }
    }
    size = b->scale;
    if (b->speed > 1.0) {
        size *= 1.0f + (b->speed - 1.0f) / 40.0f;
    }
    if (b->boost) {
        size *= 1.0f + (b->boost * b->boost) / 900.0f / 5.0f;
    }
    fade = 1.0f - (f32)(0.05f * (b->flags & 1));
    dist = fn_1_A71AC();
    dir = b->dir;
    lbl_8006DCA4();
    lbl_8006E1C0(&dir, &fwd);
    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 14, 12, 15);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    if (fn_1_6EC0(fn_1_5910())) {
        if (owner->cam == camera_get_mode()) {
            fn_80074918(1, 7, 0);
        }
    }

    emit = *(fn_1_98F28_Emitter **)(lbl_1_bss_38458->unk_8 + 0x88);
    if (b->speed > 1.0f) {
        lbl_8006DCA4();
        lbl_8006DFC4(b->mtx);
        lbl_8006E0A4(b->rot);
        sz = size * ((0.8f + 1.6000001f / b->speed) * fade);
        if (owner->kind == 4) {
            sz *= 0.6f;
        }
        if (fn_1_54E34(&emit->pos, sz)) {
            fn_1_98F28_Sprite p;
            fn_1_98F28_Vec c;
            fn_80073778(emit->tex, 0);
            p.flags = 0;
            p.pos = emit->pos;
            p.size = 0.70710677f * sz;
            p.rot = b->angle;
            t = b->speed - 1.0f;
            fn_1_98F28_min(&t, 1.0f);
            c.x = bright * (color.x * t);
            c.y = bright * (color.y * t);
            c.z = bright * (color.z * t);
            p.color.r = __OSf32tou8(c.x);
            p.color.g = __OSf32tou8(c.y);
            p.color.b = __OSf32tou8(c.z);
            p.color.a = 255;
            fn_1_9EA94(&p);
        }
    }

    if ((1.0f + fwd.z) * b->speed > 0.0f) {
        emit = *(fn_1_98F28_Emitter **)(lbl_1_bss_38458->unk_8 + 0x70);
        lbl_8006D7B0(lbl_8006D9D8(&b->pos));
        sz = (1.7f * fade) * size;
        if (owner->kind == 4) {
            sz *= 0.6f;
        }
        if (fn_1_54E34(&emit->pos, sz)) {
            fn_1_98F28_Sprite p;
            fn_1_98F28_Vec c;
            z = LC_MTX[11];
            psvec_set(&pos, z, LC_MTX[7], LC_MTX[3]);
            fn_1_98F28_near_clip(z, 1.7f);
            fn_80073778(emit->tex, 0);
            p.flags = 0;
            p.pos = emit->pos;
            p.size = 0.70710677f * sz;
            p.rot = 0;
            t = b->speed;
            fn_1_98F28_min(&t, 1.0f);
            t = t * (0.5f * (1.0f + fwd.z));
            c.x = bright * (color.x * t);
            c.y = bright * (color.y * t);
            c.z = bright * (color.z * t);
            p.color.r = __OSf32tou8(c.x);
            p.color.g = __OSf32tou8(c.y);
            p.color.b = __OSf32tou8(c.z);
            p.color.a = 255;
            fn_1_9EA94(&p);
        }
    }

    if (fwd.z > 0.0f) {
        speed = b->speed;
        if (speed > 1.2f) {
            f32 ex = speed - 1.2f;
            emit = *(fn_1_98F28_Emitter **)(lbl_1_bss_38458->unk_8 + 0xb8);
            lbl_8006D7B0(lbl_8006D9D8(&b->pos));
            sz = 0.24f + (f32)(0.64f * fwd.z);
            psvec_set(&pos, LC_MTX[11], LC_MTX[7], LC_MTX[3]);
            if (pos.z < 0.0f) {
                sz = dist * (sz * (-0.2f * pos.z));
                if (fn_1_54E34(&emit->pos, sz)) {
                    fn_1_98F28_Sprite p;
                    fn_1_98F28_Vec c;
                    z = pos.z;
                    fn_1_98F28_near_clip(z, 2.0f);
                    fn_80073778(emit->tex, 0);
                    p.flags = 0;
                    p.pos = emit->pos;
                    p.size = 0.70710677f * sz;
                    t = (2.0f * ex) / (-0.2f * pos.z);
                    fn_1_98F28_min(&t, 0.5f);
                    t = t * fwd.z;
                    t = t * (0.5f + (f32)(0.5f * (b->flags & 1)));
                    c.x = bright * (color.x * t);
                    c.y = bright * (color.y * t);
                    c.z = bright * (color.z * t);
                    p.color.r = __OSf32tou8(c.x);
                    p.color.g = __OSf32tou8(c.y);
                    p.color.b = __OSf32tou8(c.z);
                    p.color.a = 255;
                    lbl_8006E15C(1.0f, 0.6f, 1.0f);
                    psvec_set(&pos, LC_MTX[11], LC_MTX[7], LC_MTX[3]);
                    p.rot = ((f32)(32768.0f * pos.x) + (f32)(24576.0f * pos.y)) / pos.z;
                    fn_1_9EA94(&p);
                    p.rot = (s16)(((f32)(53248.0f * pos.x) + (f32)(40960.0f * pos.y)) / pos.z) + 0x6000;
                    p.size *= 0.75f;
                    fn_1_9EA94(&p);
                }
            }
        }
    }

    {
        fn_1_98F28_Sprite buf[21];
        f32 fa;
        f32 edge;
        f32 g;

        memset(buf, 0, 0x1e1);
        lbl_8006DCA4();
        lbl_8006E1B0(&b->pos, &pos);
        edge = (1.0 - __fabs(lbl_8006D534(&pos, &fwd)));
        fa = 0.11313709f * (10.0f + (f32)(80.0f * edge));
        fa = -(fa * size / (pos.z * dist));
        if (fa > 0.05f) {
            fn_1_98F28_Color col;
            fn_1_98F28_Vec c;
            s32 n;
            fn_1_98F28_Sprite *pp;
            f32 rem;
            f32 cy;
            f32 cz;
            f32 sz;

            if (fa > 0.15f) {
                g = 1.0f;
            } else {
                g = 9.999999f * (fa - 0.05f);
            }
            rem = b->speed;
            cy = color.y;
            cz = color.z;
            sz = 0.11313709f * (1.0f + (f32)(0.9f * rem));
            sz *= size;
            em = *(fn_1_98F28_Emitter **)(lbl_1_bss_38458->unk_8 + 0x168);
            c.x = bright * (color.x * g);
            c.y = bright * (cy * g);
            c.z = bright * (cz * g);
            col.r = __OSf32tou8(c.x);
            col.g = __OSf32tou8(c.y);
            col.b = __OSf32tou8(c.z);
            col.a = 255;
            ang = b->angle;
            pp = buf;
            n = 0;
            pos = b->pos;
            fn_1_6A0C(fn_1_5910(), lbl_801A6D00);
            mathutil_mtxA_set_translate(&b->pos);
            lbl_8006DF44();
            while (rem > 0.0f) {
                lbl_8006E1B0(&pos, &b->trail[lbl_1_bss_6EA08][n]);
                pp->pos = pos;
                pp->pos.x += (f32)(0.2f * ((u16)fn_1_584AC() / 32767.0f - 0.5f));
                pp->pos.y += (f32)(0.2f * ((u16)fn_1_584AC() / 32767.0f - 0.5f));
                pp->pos.z += (f32)(0.2f * ((u16)fn_1_584AC() / 32767.0f - 0.5f));
                pp->size = 0.70710677f * sz;
                pp->rot = ang;
                if (rem < 4.0f) {
                                        c.x = bright * (g * (color.x * (rem / 4.0f)));
                    c.y = bright * (g * (cy * (rem / 4.0f)));
                    c.z = bright * (g * (cz * (rem / 4.0f)));
                    pp->color.r = __OSf32tou8(c.x);
                    pp->color.g = __OSf32tou8(c.y);
                    pp->color.b = __OSf32tou8(c.z);
                    pp->color.a = 255;
                } else {
                    pp->color = col;
                }
                rem -= 0.5f;
                pp++;
                pos.x += (f32)(0.4f * (dir.x * sz));
                pos.y += (f32)(0.4f * (dir.y * sz));
                pos.z += (f32)(0.4f * (dir.z * sz));
                n++;
                ang += 0x2345;
                sz *= 0.95f;
            }
            fn_80073778(em->tex, 0);
            lbl_8006DCA4();
            if (n > 0) {
                fn_1_9E608(n, buf);
            }
        }
    }

    if (fn_1_58C4() < 2) {
        if (owner->cam == camera_get_mode()) {
            if (fn_1_6EC0(fn_1_5910())) {
                if (lbl_1_bss_6EA0C == 0 && (s32)lbl_1_bss_6EA08 >= 3) {
                    lbl_1_bss_6EA0C = 1;
                }
                if (lbl_1_bss_6EA0C != 0) {
                    f32 g;
                    f32 rem;
                    f32 cy = color.y;
                    f32 cz = color.z;

                    for (i = 0; i < 4; i++) {
                        fn_1_98F28_Sprite buf2[21];
                        fn_1_98F28_Color col;
                        fn_1_98F28_Vec c;
                        s32 n;
                        fn_1_98F28_Sprite *pp;
                        s32 j;
                        s32 age;
                        f32 sz;

                        memset(buf2, 0, 0x1e1);
                        lbl_8006DCA4();
                        lbl_8006E1B0(&b->pos, &pos);
                        rem = b->speed;
                        g = 1.0f;
                        em = *(fn_1_98F28_Emitter **)(lbl_1_bss_38458->unk_8 + 0x168);
                        sz = 0.11313709f * (1.0f + (f32)(0.9f * rem));
            sz *= size;
                        if (i < (s32)lbl_1_bss_6EA08) {
                            age = i + 4;
                            age -= lbl_1_bss_6EA08;
                        } else {
                            age = i - lbl_1_bss_6EA08;
                        }
                        g = g * (0.25f * age);
                        c.x = bright * (color.x * g);
                        c.y = bright * (cy * g);
                        c.z = bright * (cz * g);
                        col.r = __OSf32tou8(c.x);
                        col.g = __OSf32tou8(c.y);
                        col.b = __OSf32tou8(c.z);
                        col.a = 255;
                        ang = b->angle;
                        pp = buf2;
                        n = 0;
                        pos = b->pos;
                        fn_1_6A0C(fn_1_5910(), lbl_801A6D00);
                        mathutil_mtxA_set_translate(&b->pos);
                        for (j = 0; rem > 0.0f; rem -= 0.5f, j++) {
                            fn_1_98F28_Vec *prev = &b->trail[lbl_1_bss_6EA08][j];
                            fn_1_98F28_Vec *cur = &b->trail[i][j];
                            f32 dz;
                            f32 dy;
                            f32 dx;
                            f32 d2;
                            dx = cur->x;
                            dy = cur->y;
                            dz = cur->z;
                            dx -= prev->x;
                            dy -= prev->y;
                            dz -= prev->z;
                            d2 = dx * dx;
                            d2 += dy * dy;
                            d2 += dz * dz;
                            if (d2 < 0.05) {
                                continue;
                            }
                            {
                                lbl_8006E1B0(cur, pp);
                                pp->pos.x += (f32)(0.15f * ((u16)fn_1_584AC() / 32767.0f - 0.5f));
                                pp->pos.y += (f32)(0.15f * ((u16)fn_1_584AC() / 32767.0f - 0.5f));
                                pp->pos.z += (f32)(0.15f * ((u16)fn_1_584AC() / 32767.0f - 0.5f));
                                pp->size = 0.70710677f * sz * fn_1_98F28_clamp(2.0f * d2, 0.1f, 1.0f);
                                pp->rot = ang;
                                if (rem < 4.0f) {
                                                                        c.x = bright * (g * (color.x * (rem / 4.0f)));
                                    c.y = bright * (g * (cy * (rem / 4.0f)));
                                    c.z = bright * (g * (cz * (rem / 4.0f)));
                                    pp->color.r = __OSf32tou8(c.x);
                                    pp->color.g = __OSf32tou8(c.y);
                                    pp->color.b = __OSf32tou8(c.z);
                                    pp->color.a = 255;
                                } else {
                                    pp->color = col;
                                }
                                ang += 0x2345;
                                n++;
                                pos.x += (f32)(0.4f * (dir.x * sz));
                                pos.y += (f32)(0.4f * (dir.y * sz));
                                pos.z += (f32)(0.4f * (dir.z * sz));
                                pp++;
                                sz *= 0.95f;
                            }
                        }
                        fn_80073778(em->tex, 0);
                        lbl_8006DCA4();
                        if (n > 0) {
                            fn_1_9E608(n, buf2);
                        }
                    }
                }
            }
        }
    }
}
/* fzgx:end fn_1_98F28 */

/* fzgx:begin fn_1_9A0A4 */
// fn_1_9A0A4: empty in retail (single blr).
void fn_1_9A0A4(void) {
}
/* fzgx:end fn_1_9A0A4 */

/* fzgx:begin fn_1_9A0A8 */
extern int fn_1_6EC0(u8);
extern u32 fn_1_5910(void);
extern void fn_1_681C(u32, f32 *);

static inline f32 clampz(f32 t)
{
    if (t > 0.0f) {
        return t;
    }
    return 0.0f;
}

/* WARNING: compiler-diff device, not original code. */
#pragma opt_propagation off
f32 fn_1_9A0A8(u8 *p)
{
    f32 v[3];
    f32 r = 1.0f;
    f32 a, c, b, d;
    u8 id;
    id = p[0x475];
    if (fn_1_6EC0(id)) {
        if ((s8)p[0x475] == fn_1_5910()) {
            fn_1_681C(p[0x475], v);
            a = v[0] - *(f32 *)(p + 0x7c);
            b = v[1];
            b = b - *(f32 *)(p + 0x80);
            c = v[2];
            c = c - *(f32 *)(p + 0x84);
            d = a * a;
            d = d + b * b;
            d = d + c * c;
            if (clampz(d - 15.0f) / 35.0f < 0.0f) {
                r = 0.0f;
            } else if (clampz(d - 15.0f) / 35.0f > 1.0f) {
                r = 1.0f;
            } else {
                r = clampz(d - 15.0f) / 35.0f;
            }
        }
    }
    return r;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_9A0A8 */
