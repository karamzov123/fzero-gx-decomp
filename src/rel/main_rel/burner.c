#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"

extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_46B4(void *, Obj_1_bss_6EA04_Target *, u8 *, u32);
extern f32 lbl_1_rodata_4104[59];
extern Obj_1_data_27DE0 *fn_1_986A4(Obj_1_data_27DE0 *obj);
extern void fn_800794F0(Obj_1_data_27DE0 *arg0, Obj_1_data_27DE0 *arg1, s32 arg2);
extern void fn_1_98804(Obj_1_data_27DE0 *obj);
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

extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void fn_1_9D360(void);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern const f32 lbl_1_rodata_4100;
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

/* fzgx:begin fn_1_981C4 */
#include "types.h"

struct fn_1_981C4_lbl_1_bss_6EA00 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_1_981C4_lbl_801A6410 {
    u32 unk_0;
};

void fn_1_981C4(void) {
    struct fn_1_981C4_lbl_1_bss_6EA00 *p_lbl_1_bss_6EA00;
    u32 v0;
    u32 t0;
    p_lbl_1_bss_6EA00 = (struct fn_1_981C4_lbl_1_bss_6EA00 *)&(*(struct fn_1_981C4_lbl_1_bss_6EA00 *)&lbl_1_bss_6EA00);
    t0 = fn_1_4630((*(struct fn_1_981C4_lbl_801A6410 *)&lbl_801A6410).unk_0, (0x20000 + 12576), (u32)&(*(u32 *)&lbl_1_data_27E08), 378);
    p_lbl_1_bss_6EA00->unk_4 = t0;
    *(u32 *)((u8 *)t0 + 4) = 0;
    v0 = p_lbl_1_bss_6EA00->unk_4;
    *(u32 *)((u8 *)v0 + 0) = 0;
    p_lbl_1_bss_6EA00->unk_8 = 0;
    p_lbl_1_bss_6EA00->unk_C = 0;
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
    BurnerNode *node = (BurnerNode *)lbl_1_bss_6EA04->unk_4;

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
    Fn1982C4Node *node = (Fn1982C4Node *)lbl_1_bss_6EA04->unk_4;

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
typedef struct BurnerNode BurnerNode;
typedef struct BurnerEntry BurnerEntry;

struct BurnerNode {
    u8 pad_0[0x4];
    BurnerNode *next;
    u32 index;
};

typedef void (*BurnerCallback)(BurnerNode *, BurnerEntry *);

struct BurnerEntry {
    u8 pad_0[0xC];
    BurnerCallback callback;
    u8 pad_10[0x4];
};

void fn_1_9835C(void) {
    BurnerNode *node = (BurnerNode *)lbl_1_bss_6EA04->unk_4;

    while (node != 0) {
        BurnerNode *next = node->next;
        BurnerEntry *entry =
            (BurnerEntry *)((u8 *)&lbl_1_data_27DE0 + node->index * 0x14);
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

extern void fn_1_98640(Fn1983CCWork *work);

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
        work.data.unk_24 = entry->unk_5C / lbl_1_rodata_4100;
        work.data.unk_28 = entry->unk_60;
        work.data.unk_2C = entry->unk_64;
        work.data.unk_30 = entry->unk_68;
        work.data.unk_34 = entry->unk_6C;
        work.data.unk_38 = entry->unk_70;
        work.data.unk_3C = entry->unk_74;
        work.data.unk_4A4 = lbl_1_bss_6EA00;
        fn_1_98640(&work);
        entry = (Fn1983CCEntry *)((u8 *)entry + 0x38);
    }
}
/* fzgx:end fn_1_983CC */

/* fzgx:begin fn_1_984F0 */
typedef struct BurnerNode BurnerNode;

struct BurnerNode {
    u8 pad_0[0x4];
    BurnerNode *next;
    u32 index;
    u8 pad_C[0x3C];
    u32 key;
};

typedef void (*BurnerCallback)(BurnerNode *, void *);

extern void fn_1_98840(BurnerNode *node);
extern void fn_1_987D0(BurnerNode *node);

void fn_1_984F0(void *object) {
    BurnerNode *node = (BurnerNode *)lbl_1_bss_6EA04->unk_4;
    u8 *table = (u8 *)&lbl_1_data_27DE0;

    while (node != 0) {
        BurnerNode *next = node->next;

        if (node->key == (u32)object) {
            BurnerCallback callback = *(BurnerCallback *)(table + node->index * 0x14 + 0x4);
            callback(node, table + node->index * 0x14);
            fn_1_98840(node);
            fn_1_987D0(node);
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
    Fn198590Node *node = (Fn198590Node *)lbl_1_bss_6EA04->unk_4;
    f32 value = lbl_1_rodata_4104[0];

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
typedef struct BurnerEntry BurnerEntry;

struct BurnerEntry {
    u8 unk_00[0x04];
    BurnerEntry *next;
    u8 unk_08[0x40];
    u32 key;
    u8 unk_4C[0x28];
    f32 value;
    u8 unk_78[0x430];
    u32 flags;
};

// Reset matching burner entries while walking the global entry list.
void fn_1_985EC(u32 key) {
    BurnerEntry *node = (BurnerEntry *)lbl_1_bss_6EA04->unk_4;
    f32 value = lbl_1_rodata_4104[0];
    u32 zero = 0;

    while (node != 0) {
        BurnerEntry *next = node->next;
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
void fn_1_98640(Obj_1_data_27DE0 *obj) {
    Obj_1_data_27DE0 *result = fn_1_986A4(obj);

    fn_800794F0(result, obj, 0x4ac);
    fn_1_98804(result);
    ((void (*)(Obj_1_data_27DE0 *))(*(u32 *)((u8 *)&lbl_1_data_27DE0 +
        result->unk_8 * 0x14)))(result);
}
/* fzgx:end fn_1_98640 */

/* fzgx:begin fn_1_986A4 noprologue */
#include "types.h"

extern u32 lbl_1_bss_6EA04;

void *fn_1_986A4(void) {
    u8 *q;
    s8 *p = (s8 *)lbl_1_bss_6EA04 + 8;
    s32 n = 120;
    s32 i;

    for (i = 12; i != 0; i--) {
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
        if (p[0] == 0) break;
        n--; p++;
    }
    if (n == 0) {
        return 0;
    }
    *p = 1;
    q = (u8 *)lbl_1_bss_6EA04 + (120 - n) * 0x4ac + 0x80;
    *(u32 *)(q + 0) = 0;
    *(u32 *)(q + 4) = 0;
    return q;
}
/* fzgx:end fn_1_986A4 */

/* fzgx:begin fn_1_987D0 */
void fn_1_987D0(u32 address) {
    Obj_1_bss_6EA04_Target *object;
    u32 offset;

    object = lbl_1_bss_6EA04;
    offset = (address - ((u32)object + 0x80)) / 1196;
    object->pad_8[offset] = 0;
}
/* fzgx:end fn_1_987D0 */

/* fzgx:begin fn_1_98804 noprologue */
#include "types.h"

extern struct fn_1_98804_lbl_1_bss_6EA04 lbl_1_bss_6EA04;

struct fn_1_98804_Arg0 {
    u32 unk_0;
    u32 unk_4;
};
struct fn_1_98804_lbl_1_bss_6EA04 {
    u32 unk_0;
};

void fn_1_98804(struct fn_1_98804_Arg0 *arg0) {
    u32 v0;
    v0 = *(u32 *)((u8 *)lbl_1_bss_6EA04.unk_0 + 4);
    arg0->unk_4 = v0;
    arg0->unk_0 = lbl_1_bss_6EA04.unk_0;
    if (v0 != 0) {
    *(u32 *)((u8 *)v0 + 0) = (u32)arg0;
    }
    *(u32 *)((u8 *)lbl_1_bss_6EA04.unk_0 + 4) = (u32)arg0;
}
/* fzgx:end fn_1_98804 */

/* fzgx:begin fn_1_98840 */
typedef struct Node {
    struct Node *prev;
    struct Node *next;
} Node;

void fn_1_98840(Node *node) {
    Node *next = node->next;
    Node *prev = node->prev;

    prev->next = next;
    if (next != 0) {
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

/* fzgx:begin fn_1_988DC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 14.0f;
    s = 0.0f;
    s = 900.0f;
    s = 2.0f;
    s = 10.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.8;
    d = 0.1;
    s = 0.003921568859368563f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.15000000596046448f;
    s = 0.10000000149011612f;
    s = 0.10999999940395355f;
    s = 0.11999999731779099f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

extern s16 camera_get_mode(void);
extern u32 fn_1_58C4(void);
extern u8 *memset(u8 *dst, int value, u32 size);
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
extern u16 lbl_1_bss_960;
extern u32 lbl_801A6D00;

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

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
    ratio = (f32)(cnt) / 900.0f;
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
            v = (f32)((f64)old * (1.0 + scale));
            *(f32 *)((u8 *)arg0 + 116) = v;
        } else {
            scale = 0.1 * ratio;
            old = *(f32 *)((u8 *)arg0 + 116);
            v = (f32)((f64)old * (1.0 + scale));
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
        memset((u8 *)&entry, 0, 0xe8);
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
    if (*(s16 *)&lbl_1_bss_960 != 0xe) {
        v = *(f32 *)(p + 512);
        var_f0 = v < 0.0 ? 0.0 : (v > 1.0 ? 1.0 : (f64)v);
        var_f4 = (f32)((f64)var_f4 * var_f0);
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
            var_f4 = (f32)((f64)var_f4 * (1.0 + scale));
        } else {
            scale = 0.1 * ratio;
            var_f4 = (f32)((f64)var_f4 * (1.0 + scale));
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

/* fzgx:begin fn_1_98E18 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"

/* begin game/main_rel/burner_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

// Types (and the externs that name them) of burner.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct Node {
    struct Node *prev;
    struct Node *next;
} Node;

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

struct fn_1_98804_Arg0 {
    u32 unk_0;
    u32 unk_4;
};

typedef struct {
    u8 pad[8];
    u8 *entries;
} fn_1_9D360_BurnerTable;

extern void fn_1_98840(Node *node);
extern void *fn_1_5448C(fn_1_98E18_Vec *pos);
extern void fn_8006E294(fn_1_9CCE8_Vec3 *);
extern void fn_80077F8C(Burner *);
extern const struct FormatTable lbl_1_rodata_7050;
extern const struct EntryTable lbl_1_rodata_6E38;
extern void fn_1_98804(struct fn_1_98804_Arg0 *arg0);
extern void fn_1_9D360(Burner *burner, fn_1_9D360_BurnerTable *table, u8 *indices);

#endif  // GAME_MAIN_REL_BURNER_TYPES_H

/* end game/main_rel/burner_types.h */

extern void fn_1_98640(Obj_1_data_27DE0 *obj);
extern void fn_1_987D0(u32 address);
extern s16 camera_get_mode(void);
extern u32 fn_1_58C4(void);
extern void *memset(void *dest, int value, u32 size);
extern void fn_1_8645C(int index, void *arg);
extern void lbl_8006E1B0(void *, void *);
extern s16 fn_1_58E3C(void *source);
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
extern void fn_1_98F28(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern int sprintf(char *s, const char *format, ...);
extern s32 fn_1_46DC4(s32 value);
extern u32 fn_80077A18();
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern char *fn_80083DB0(char *, const char *);
extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern f32 lbl_1_rodata_4104[59];
extern void * fn_1_986A4();
extern void fn_800794F0(u8 *dst, u8 *src, s32 len);
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void lbl_8006D7B0(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s32);
extern size_t strlen(const char *str);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 fn_8006FC1C(const char *, const char *);
extern u32 fn_1_9D260(void);
extern s16 fn_1_3F0C8(void);
extern u8 lbl_1_bss_8E51D;
extern u8 fn_1_7B074(void);
extern s32 fn_8006FDEC(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);
extern void * fn_1_12F118(void);
extern u8* fn_1_36AD0(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern const f32 lbl_1_rodata_4100;
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
extern s32 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_91BC;
extern void fn_1_4E724(void *);
extern void fn_1_103054(void);
extern void fn_1_9D2EC(void);
extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
extern u8 lbl_1_data_2B15C__fzgx_offset_0[];
extern u8 lbl_1_data_2B160__fzgx_offset_0[];
extern u8 lbl_1_data_2B16C__fzgx_offset_0[];
extern u8 lbl_1_data_2B178__fzgx_offset_0[];
extern u8 lbl_1_data_2B184__fzgx_offset_0[];
extern u8 lbl_1_data_2B190__fzgx_offset_0[];
extern u8 lbl_1_data_2B19C__fzgx_offset_0[];
extern u8 lbl_1_data_2B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B1D0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1F0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B208__fzgx_offset_0[];
extern u8 lbl_1_data_2B218__fzgx_offset_0[];
extern u8 lbl_1_data_2B220__fzgx_offset_0[];
extern u8 lbl_1_data_2B230__fzgx_offset_0[];
extern u8 lbl_1_data_2B240__fzgx_offset_0[];
extern u8 lbl_1_data_2B248__fzgx_offset_0[];
extern u8 lbl_1_data_2B258__fzgx_offset_0[];
extern u8 lbl_1_data_2B268__fzgx_offset_0[];
extern u8 lbl_1_data_2B274__fzgx_offset_0[];
extern u8 lbl_1_data_2B284__fzgx_offset_0[];
extern u8 lbl_1_data_2B294__fzgx_offset_0[];
extern u8 lbl_1_data_2B2A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B474__fzgx_offset_0[];
extern u8 lbl_1_data_2B47C__fzgx_offset_0[];
extern u8 lbl_1_data_2B48C__fzgx_offset_0[];
extern u8 lbl_1_data_2B49C__fzgx_offset_0[];
extern u8 lbl_1_data_2B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4BC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B50C__fzgx_offset_0[];
extern u8 lbl_1_data_2B520__fzgx_offset_0[];
extern u8 lbl_1_data_2B530__fzgx_offset_0[];
extern u8 lbl_1_data_2B540__fzgx_offset_0[];
extern u8 lbl_1_data_2B550__fzgx_offset_0[];
extern u8 lbl_1_data_2B560__fzgx_offset_0[];
extern u8 lbl_1_data_2B574__fzgx_offset_0[];
extern u8 lbl_1_data_2B584__fzgx_offset_0[];
extern u8 lbl_1_data_2B594__fzgx_offset_0[];
extern u8 lbl_1_data_2B5A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5D4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5E4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B604__fzgx_offset_0[];
extern u8 lbl_1_data_2B614__fzgx_offset_0[];
extern u8 lbl_1_data_2B624__fzgx_offset_0[];
extern u8 lbl_1_data_2B634__fzgx_offset_0[];
extern u8 lbl_1_data_2B644__fzgx_offset_0[];
extern u8 lbl_1_data_2B654__fzgx_offset_0[];
extern u8 lbl_1_data_2B664__fzgx_offset_0[];
extern u8 lbl_1_data_2B678__fzgx_offset_0[];
extern u8 lbl_1_data_2B68C__fzgx_offset_0[];
extern u8 lbl_1_data_2B6A0__fzgx_offset_0[];
extern u8 lbl_1_data_2B6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6E8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2B708__fzgx_offset_0[];
extern u8 lbl_1_data_2B718__fzgx_offset_0[];
extern u8 lbl_1_data_2B728__fzgx_offset_0[];
extern u8 lbl_1_data_2B738__fzgx_offset_0[];
extern u8 lbl_1_data_2B748__fzgx_offset_0[];
extern u8 lbl_1_data_2B758__fzgx_offset_0[];
extern u8 lbl_1_data_2B768__fzgx_offset_0[];
extern u8 lbl_1_data_2B77C__fzgx_offset_0[];
extern u8 lbl_1_data_2B790__fzgx_offset_0[];
extern u8 lbl_1_data_2B7A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B7B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B7CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B7E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B7F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B808__fzgx_offset_0[];
extern u8 lbl_1_data_2B81C__fzgx_offset_0[];
extern u8 lbl_1_data_2B830__fzgx_offset_0[];
extern u8 lbl_1_data_2B840__fzgx_offset_0[];
extern u8 lbl_1_data_2B850__fzgx_offset_0[];
extern u8 lbl_1_data_2B860__fzgx_offset_0[];
extern u8 lbl_1_data_2B870__fzgx_offset_0[];
extern u8 lbl_1_data_2B884__fzgx_offset_0[];
extern u8 lbl_1_data_2B894__fzgx_offset_0[];
extern u8 lbl_1_data_2B8A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B8EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B900__fzgx_offset_0[];
extern u8 lbl_1_data_2B914__fzgx_offset_0[];
extern u8 lbl_1_data_2B928__fzgx_offset_0[];
extern u8 lbl_1_data_2B93C__fzgx_offset_0[];
extern u8 lbl_1_data_2B948__fzgx_offset_0[];
extern u8 lbl_1_data_2B954__fzgx_offset_0[];
extern u8 lbl_1_data_2B960__fzgx_offset_0[];
extern u8 lbl_1_data_2B96C__fzgx_offset_0[];
extern u8 lbl_1_data_2B97C__fzgx_offset_0[];
extern u8 lbl_1_data_2B990__fzgx_offset_0[];
extern u8 lbl_1_data_2B9A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B9CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9F0__fzgx_offset_0[];
extern u8 lbl_1_data_2BA04__fzgx_offset_0[];
extern u8 lbl_1_data_2BA18__fzgx_offset_0[];
extern u8 lbl_1_data_2BA2C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA40__fzgx_offset_0[];
extern u8 lbl_1_data_2BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA58__fzgx_offset_0[];
extern u8 lbl_1_data_2BA64__fzgx_offset_0[];
extern u8 lbl_1_data_2BA70__fzgx_offset_0[];
extern u8 lbl_1_data_2BA80__fzgx_offset_0[];
extern u8 lbl_1_data_2BA94__fzgx_offset_0[];
extern u8 lbl_1_data_2BAA8__fzgx_offset_0[];
extern u8 lbl_1_data_2BABC__fzgx_offset_0[];
extern u8 lbl_1_data_2BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_2BB10__fzgx_offset_0[];
extern u8 lbl_1_data_2BB24__fzgx_offset_0[];
extern u8 lbl_1_data_2BB38__fzgx_offset_0[];
extern u8 lbl_1_data_2BB48__fzgx_offset_0[];
extern u8 lbl_1_data_2BB58__fzgx_offset_0[];
extern u8 lbl_1_data_2BB68__fzgx_offset_0[];
extern u8 lbl_1_data_2BB78__fzgx_offset_0[];
extern u8 lbl_1_data_2BB88__fzgx_offset_0[];
extern u8 lbl_1_data_2BB9C__fzgx_offset_0[];
extern u8 lbl_1_data_2BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_2BBC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BBD8__fzgx_offset_0[];
extern u8 lbl_1_data_2BBEC__fzgx_offset_0[];
extern u8 lbl_1_data_2BC00__fzgx_offset_0[];
extern u8 lbl_1_data_2BC14__fzgx_offset_0[];
extern u8 lbl_1_data_2BC28__fzgx_offset_0[];
extern u8 lbl_1_data_2BC3C__fzgx_offset_0[];
extern u8 lbl_1_data_2BC50__fzgx_offset_0[];
extern u8 lbl_1_data_2BC64__fzgx_offset_0[];
extern u8 lbl_1_data_2BC78__fzgx_offset_0[];
extern u8 lbl_1_data_2BC8C__fzgx_offset_0[];
extern u8 lbl_1_data_2BCA0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCB4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCDC__fzgx_offset_0[];
extern u8 lbl_1_data_2BCE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BCF4__fzgx_offset_0[];
extern u8 lbl_1_data_2BD00__fzgx_offset_0[];
extern u8 lbl_1_data_2BD10__fzgx_offset_0[];
extern u8 lbl_1_data_2BD20__fzgx_offset_0[];
extern u8 lbl_1_data_2BD30__fzgx_offset_0[];
extern u8 lbl_1_data_2BD40__fzgx_offset_0[];
extern u8 lbl_1_data_2C7BC__fzgx_offset_0[];
extern u8 lbl_1_data_2C7C0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E4__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E8__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F8__fzgx_offset_0[];
extern u8 lbl_1_data_2C804__fzgx_offset_0[];
extern u8 lbl_1_data_2C80C__fzgx_offset_0[];
extern u8 lbl_1_data_2C818__fzgx_offset_0[];
extern u8 lbl_1_data_2C824__fzgx_offset_0[];
extern u8 lbl_1_data_2C86C__fzgx_offset_0[];
extern u8 lbl_1_data_2C870__fzgx_offset_0[];
extern u8 lbl_1_data_2C890__fzgx_offset_0[];
extern u8 lbl_1_data_2C8B0__fzgx_offset_0[];
extern u8 lbl_1_data_2C8D0__fzgx_offset_0[];

/* Shared literal pool primer (lbl_1_rodata_4100, retail order): the TU pools its
   float literals in first-use order, so the earlier literals are referenced here. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 14.0f;
    s = 0.0f;
    s = 900.0f;
    s = 2.0f;
    s = 10.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.8;
    d = 0.1;
    s = 0.003921568859368563f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.15000000596046448f;
    s = 0.10000000149011612f;
    s = 0.10999999940395355f;
    s = 0.11999999731779099f;
    d = 4503601774854144.0;
    s = 0.5f;
    s = 1.7f;
}
#pragma section code_type ".text"





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
    if (fn_1_54E34( (void *)(fn_1_98E18_Vec *)(&p), r)) {
        lbl_8006DCA4();
        data = fn_1_5448C(&b->pos);
        event = (fn_1_98E18_Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->callback = fn_1_98F28;
            event->entry = b;
            fn_1_5489C( (void **)(void *)(data), (void **)(void *)(event));
        }
    }
}
/* fzgx:end fn_1_98E18 */

/* fzgx:begin fn_1_98F28 */
#include "psvec.h"
#include "dolphin/hw_regs.h"
#include "dolphin/os/OSFastCast.h"
#include "lc_mtx.h"
#include "mathutil_mtxA_set_translate.h"

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

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 14.0f;
    s = 0.0f;
    s = 900.0f;
    s = 2.0f;
    s = 10.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.8;
    d = 0.1;
    s = 0.003921568859368563f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.15000000596046448f;
    s = 0.10000000149011612f;
    s = 0.10999999940395355f;
    s = 0.11999999731779099f;
    d = 4503601774854144.0;
    s = 0.5f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 40.0f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 0.800000011920929f;
    s = 1.6000001430511475f;
    s = 0.6000000238418579f;
    s = 0.7071067690849304f;
    s = -1.8000000715255737f;
    s = 1.2000000476837158f;
    s = 0.23999999463558197f;
    s = 0.6399999856948853f;
    s = -0.20000000298023224f;
    s = -2.0999999046325684f;
    s = 32768.0f;
    s = 24576.0f;
    s = 53248.0f;
    s = 40960.0f;
    s = 0.75f;
    s = 0.11313708871603012f;
    s = 80.0f;
    s = 9.999999046325684f;
    s = 0.8999999761581421f;
    s = 0.20000000298023224f;
    s = 32767.0f;
    s = 4.0f;
    s = 0.25f;
    s = 0.4000000059604645f;
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern f32 fn_1_9A0A8(void *);
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
extern s32 lbl_1_bss_6EA0C;

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
    bright = fn_1_9A0A8(owner);
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
        size *= 1.0f + (f32)(b->boost * b->boost) / 900.0f / 5.0f;
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
        edge = (f32)(1.0 - __fabs(lbl_8006D534(&pos, &fwd)));
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
                pp->pos.x += (f32)(0.2f * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5f));
                pp->pos.y += (f32)(0.2f * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5f));
                pp->pos.z += (f32)(0.2f * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5f));
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
                            age -= (s32)lbl_1_bss_6EA08;
                        } else {
                            age = i - (s32)lbl_1_bss_6EA08;
                        }
                        g = g * (0.25f * (f32)age);
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
                                pp->pos.x += (f32)(0.15f * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5f));
                                pp->pos.y += (f32)(0.15f * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5f));
                                pp->pos.z += (f32)(0.15f * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5f));
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

/* fzgx:begin fn_1_9A0A8 noprologue */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 14.0f;
    s = 0.0f;
    s = 900.0f;
    s = 2.0f;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.8;
    d = 0.1;
    s = 0.003921568859368563f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.15000000596046448f;
    s = 0.10000000149011612f;
    s = 0.10999999940395355f;
    s = 0.11999999731779099f;
    d = 4503601774854144.0;
    s = 0.5f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 40.0f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 0.800000011920929f;
    s = 1.6000001430511475f;
    s = 0.6000000238418579f;
    s = 0.7071067690849304f;
    s = -1.8000000715255737f;
    s = 1.2000000476837158f;
    s = 0.23999999463558197f;
    s = 0.6399999856948853f;
    s = -0.20000000298023224f;
    s = -2.0999999046325684f;
    s = 32768.0f;
    s = 24576.0f;
    s = 53248.0f;
    s = 40960.0f;
    s = 0.75f;
    s = 0.11313708871603012f;
    s = 80.0f;
    s = 9.999999046325684f;
    s = 0.8999999761581421f;
    s = 0.20000000298023224f;
    s = 32767.0f;
    s = 4.0f;
    s = 0.25f;
    s = 0.4000000059604645f;
    s = 0.949999988079071f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05;
    d = 4503599627370496.0;
    s = 15.0f;
    s = 35.0f;
}
#pragma section code_type ".text"

extern const f32 lbl_1_rodata_4100;
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

#pragma scheduling on
#pragma peephole on
#pragma opt_propagation off
f32 fn_1_9A0A8(u8 *p)
{
    f32 v[3];
    f32 r = 1.0f;
    f32 a, c, b, d;
    u8 id;
    id = p[0x475];
    if (fn_1_6EC0(id)) {
        if ((u32)(s8)p[0x475] == fn_1_5910()) {
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
#pragma peephole reset
/* fzgx:end fn_1_9A0A8 */

/* fzgx:begin fn_1_9A1E8 */
typedef struct {
    f32 x, y, z;
} Vec;

typedef struct {
    u8 a, b, c, d;
} BurnerParam;

typedef struct {
    u32 w[4];
} BurnerColor;

typedef struct {
    s16 unk_0;
    BurnerParam unk_2;
    u8 unk_6[4];
    u8 pad_A[0x2];
    u32 unk_C[4];
    f32 unk_1C[4];
    u8 pad_2C[0x10];
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u8 pad_48[0x28];
    u8 unk_70;
    u8 pad_71[0x7];
    u32 unk_78;
    u32 unk_7C;
    u32 unk_80;
    s32 unk_84;
    u32 unk_88;
    BurnerColor unk_8C;
    f32 unk_9C;
    u16 unk_A0;
    u8 pad_A2[0x2];
} BurnerState;


typedef struct {
    u8 pad_0[0x4];
    void (*init)(void);
    u8 pad_8[0x1C];
} Data2ABAC;

typedef struct {
    u8 pad_0[0x30];
} Data2C8D0;

typedef struct {
    u8 unk_0;
    s8 unk_1;
} Obj9C;

extern u32 lbl_801A63C0;
extern u32 lbl_801A66A0;
extern Vec lbl_1_bss_6EA10[4];
extern u32 lbl_1_bss_6EA40[4];
extern Obj9C lbl_1_bss_9C;
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_9D9E4(void);
extern void fn_1_102FD0(void);
extern void fn_1_9AD20(void);
extern s16 fn_1_7B054(void);
extern u32 fn_1_58C4(void);

u32 fzgx_obj_lbl_1_data_2A0C0[4] = {1};
u8 fzgx_pool_gap_2A0D0[0x2A7E0 - 0x2A0D0] = {1};
BurnerState fzgx_obj_lbl_1_data_2A7E0 = {1};
BurnerParam fzgx_obj_lbl_1_data_2A884[21] = {1};
u8 fzgx_pool_gap_2A8D8[0x2ABAC - 0x2A8D8] = {1};
Data2ABAC fzgx_obj_lbl_1_data_2ABAC[22] = {1};
u8 fzgx_pool_gap_2AEC4[0x2C8D0 - 0x2AEC4] = {1};
Data2C8D0 fzgx_obj_lbl_1_data_2C8D0 = {1};
BurnerColor fzgx_obj_lbl_1_data_2C900 = {1};
BurnerColor fzgx_obj_lbl_1_data_2C910[37] = {1};

static inline s32 rand(void)
{
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline void srand(u32 seed)
{
    lbl_801A63C0 = seed ^ 0xCAE87FB5;
}

static inline Vec vec_zero(void)
{
    Vec v = {0.0f, 0.0f, 0.0f};
    return v;
}

void fn_1_9A1E8(void)
{
    s16 index = fzgx_obj_lbl_1_data_2A7E0.unk_0;
    u32 s3c = fzgx_obj_lbl_1_data_2A7E0.unk_3C;
    u32 seed = fzgx_obj_lbl_1_data_2A7E0.unk_40;
    u32 s78 = fzgx_obj_lbl_1_data_2A7E0.unk_78;
    u32 s7c = fzgx_obj_lbl_1_data_2A7E0.unk_7C;
    u32 s80 = fzgx_obj_lbl_1_data_2A7E0.unk_80;
    u8 s70 = fzgx_obj_lbl_1_data_2A7E0.unk_70;
    u32 next;
    s16 course;
    BurnerColor *color;
    s32 i;
    u32 viewports;
    s16 mode;

    fn_80008BEC(&fzgx_obj_lbl_1_data_2A7E0, 0, sizeof(BurnerState));
    fzgx_obj_lbl_1_data_2A7E0.unk_0 = index;
    fzgx_obj_lbl_1_data_2A7E0.unk_3C = s3c;
    fzgx_obj_lbl_1_data_2A7E0.unk_40 = seed;
    fzgx_obj_lbl_1_data_2A7E0.unk_78 = s78;
    fzgx_obj_lbl_1_data_2A7E0.unk_7C = s7c;
    fzgx_obj_lbl_1_data_2A7E0.unk_80 = s80;
    fzgx_obj_lbl_1_data_2A7E0.unk_70 = s70;
    for (i = 0; i < 4; i++) {
        fzgx_obj_lbl_1_data_2A7E0.unk_6[i] = 0;
        fzgx_obj_lbl_1_data_2A7E0.unk_C[i] = 0;
        fzgx_obj_lbl_1_data_2A7E0.unk_1C[i] = 0.0f;
    }
    fzgx_obj_lbl_1_data_2A7E0.unk_2 = fzgx_obj_lbl_1_data_2A884[fzgx_obj_lbl_1_data_2A7E0.unk_0 > 0 ? fzgx_obj_lbl_1_data_2A7E0.unk_0 : 0];
    for (i = 0; i < 4; i++) {
        lbl_1_bss_6EA10[i] = vec_zero();
        lbl_1_bss_6EA40[i] = 0;
    }
    next = rand();
    srand(seed);
    fzgx_obj_lbl_1_data_2A7E0.unk_44 = rand();
    fn_1_9D9E4();
    fn_1_102FD0();
    if (fzgx_obj_lbl_1_data_2A7E0.unk_0 > 0) {
        fzgx_obj_lbl_1_data_2ABAC[fzgx_obj_lbl_1_data_2A7E0.unk_0].init();
    } else {
        fn_1_9AD20();
    }
    fzgx_obj_lbl_1_data_2A7E0.unk_40 = lbl_801A66A0 + rand();
    srand(next);
    course = fn_1_7B054();
    if (fzgx_obj_lbl_1_data_2A7E0.unk_84 != 0) {
        viewports = 4;
    } else {
        viewports = fn_1_58C4();
    }
    fzgx_obj_lbl_1_data_2A7E0.unk_88 = viewports;
    color = &fzgx_obj_lbl_1_data_2C900;
    if ((u32)course < 37) {
        color = &fzgx_obj_lbl_1_data_2C910[course];
    }
    fzgx_obj_lbl_1_data_2A7E0.unk_8C = *color;
    fzgx_obj_lbl_1_data_2A7E0.unk_9C = 0.0f;
    mode = *(s16 *)&lbl_1_bss_960;
    if (mode == 9 && lbl_1_bss_84.unk_14 != 0) {
        fzgx_obj_lbl_1_data_2A7E0.unk_9C = *(f32 *)lbl_1_bss_84.unk_14;
        lbl_1_bss_84.unk_14 = 0;
    }
    fzgx_obj_lbl_1_data_2A7E0.unk_A0 = 0xF00;
    if (mode == 9) {
        switch (lbl_1_bss_9C.unk_1) {
        case 0:
            fzgx_obj_lbl_1_data_2A7E0.unk_A0 = 0x100;
            break;
        case 1:
            fzgx_obj_lbl_1_data_2A7E0.unk_A0 = 0x200;
            break;
        case 2:
            fzgx_obj_lbl_1_data_2A7E0.unk_A0 = 0x400;
            break;
        }
    }
}
/* fzgx:end fn_1_9A1E8 */

/* fzgx:begin fn_1_9A508 */
extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_46B4(void *, Obj_1_bss_6EA04_Target *, u8 *, u32);
extern f32 lbl_1_rodata_4104[59];
extern Obj_1_data_27DE0 *fn_1_986A4(Obj_1_data_27DE0 *obj);
extern void fn_800794F0(Obj_1_data_27DE0 *arg0, Obj_1_data_27DE0 *arg1, s32 arg2);
extern void fn_1_98804(Obj_1_data_27DE0 *obj);
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

extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void fn_1_9D360(void);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern const f32 lbl_1_rodata_4100;
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

extern void fn_1_9AD20(void);
extern void fn_1_9D0EC(u32, u32, void *, void *);

typedef struct {
    u8 pad[0x20];
    void *callback;
} SelectionRow;

typedef struct {
    s16 index;
    u8 pad[0x3CA];
} SelectionState;

u8 lbl_1_data_2A0C0[0x10] = "OCE_LIGHTMAP_A";
extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
static union { u32 w[452]; u8 v[0x710]; } fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_10 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F43455F, 0x57415645, 0x5F504154, 0x5F420000, 0x4F43455F, 0x4E414D49, 0x5F000000, 0x4F434E5F,
    0x504F4F4C, 0x0, 0x42494742, 0x4C55455F, 0x52454E5A, 0x5F465245, 0x41303100, 0x1,
    (u32)lbl_1_data_2A0C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A0D0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0E0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A0F8__fzgx_offset_0, 0x3, 0x0, 0x5F6C746D, 0x70000000, 0x5F6C746D, 0x70320000, 0x4F43455F,
    0x43415343, 0x4144455F, 0x0, 0x4F43455F, 0x4332375F, 0x43415343, 0x41444500, 0x43554245,
    0x5F474154, 0x455F415F, 0x4C4F4400, 0x43554245, 0x5F425F41, 0x5F4C4F44, 0x0, 0x43554245,
    0x5F445F41, 0x5F4C4F44, 0x0, 0x42494742, 0x4C55455F, 0x53554E30, 0x31000000, 0x2,
    (u32)lbl_1_data_2A13C__fzgx_offset_0, 0x2, (u32)lbl_1_data_2A144__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A14C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A15C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A16C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A17C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A18C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A19C__fzgx_offset_0, 0x3, 0x0, 0x5F5F5F00, 0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3, 0x0,
    0x5041544C, 0x414D505F, 0x41000000, 0x5041544C, 0x414D505F, 0x42000000, 0x5041544C, 0x414D505F,
    0x43000000, 0x5041544C, 0x414D505F, 0x44000000, 0x424E535F, 0x534B595F, 0x4B554D4F, 0x5F000000,
    0x4C49475F, 0x47524F55, 0x4E445F41, 0x0, 0x4330385F, 0x5241494E, 0x524F4144, 0x0,
    0x4330395F, 0x5241494E, 0x524F4144, 0x0, 0x4332335F, 0x5241494E, 0x524F4144, 0x0,
    0x4333345F, 0x5241494E, 0x524F4144, 0x0, 0x52455041, 0x4952504F, 0x494E5400, 0x0,
    (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A240__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A250__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A260__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A270__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A280__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A290__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A2A0__fzgx_offset_0, 0x3, 0x0, 0x3,
    0x0, 0x464C4147, 0x0, 0x0, (u32)lbl_1_data_2A314__fzgx_offset_0, 0x3, 0x0, 0x464F525F,
    0x4546465F, 0x48413031, 0x0, 0x464F525F, 0x52454E5A, 0x5F465245, 0x41000000, 0x464F525F,
    0x4546465F, 0x47524E4C, 0x49470000, 0x1, (u32)lbl_1_data_2A32C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A33C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A34C__fzgx_offset_0, 0x3, 0x0, 0x464F525F, 0x53554E00, 0x0, (u32)lbl_1_data_2A37C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3,
    0x0, 0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3, 0x0, 0x535F5348, 0x49500000, 0x0,
    (u32)lbl_1_data_2A3C4__fzgx_offset_0, 0x3, 0x0, 0x53414E5F, 0x57415645, 0x5F504154, 0x5F4D0000, 0x53414E5F,
    0x57415645, 0x5F504154, 0x5F530000, 0x474F524F, 0x46524147, 0x5F767478, 0x0, 0x474F524F,
    0x46524147, 0x325F7674, 0x78000000, 0x1, (u32)lbl_1_data_2A3DC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3EC__fzgx_offset_0, 0x1,
    (u32)lbl_1_data_2A3FC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A40C__fzgx_offset_0, 0x3, 0x0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x3,
    0x0, 0x3, 0x0, 0x44494345, 0x0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3,
    0x0, 0x434F494E, 0x0, 0x0, (u32)lbl_1_data_2A494__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3,
    0x0, 0x4D45545F, 0x434F4D45, 0x54303200, 0x4546465F, 0x524F434B, 0x46495245, 0x5F415F52,
    0x32533100, 0x4546465F, 0x524F434B, 0x46495245, 0x5F425F52, 0x32533100, 0x1, (u32)lbl_1_data_2A4B4__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2A4C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4D4__fzgx_offset_0, 0x3, 0x0, 0x4D45545F, 0x42494753,
    0x54415230, 0x31000000, 0x0, (u32)lbl_1_data_2A508__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0,
    0x454C565F, 0x544F5000, 0x454C565F, 0x434F4C4F, 0x4E590000, 0x454C565F, 0x544F5745, 0x52424153,
    0x4530315F, 0x415F4C4F, 0x44000000, 0x454C565F, 0x43415247, 0x4F30315F, 0x415F4C4F, 0x44000000,
    0x454C565F, 0x424F5830, 0x315F415F, 0x4C4F4400, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A530__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A538__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A544__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A55C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A570__fzgx_offset_0, 0x3, 0x0,
    0x57494E44, 0x4F573031, 0x0, 0x0, (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x3, 0x0, 0x53454152,
    0x43483031, 0x0, 0x53454152, 0x43485F41, 0x524D3031, 0x0, 0x53454152, 0x43485F41,
    0x524D3032, 0x0, 0x5343414D, 0x504F494E, 0x54303100, 0x464C4153, 0x48303100, 0x0,
    (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A5EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A5F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A608__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A618__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A624__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x43554245,
    0x0, 0x0, (u32)lbl_1_data_2A66C__fzgx_offset_0, 0x3, 0x0, 0x4654565F, 0x4C4F474F, 0x0,
    0x4654565F, 0x52494E47, 0x0, 0x4654565F, 0x52494E47, 0x5F460000, 0x4654565F, 0x45415254,
    0x48000000, 0x4654565F, 0x52494E47, 0x5F540000, 0x0, (u32)lbl_1_data_2A684__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A690__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2A69C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A6A8__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A6B4__fzgx_offset_0, 0x3, 0x0,
    0x43415244, 0x49535000, 0x47414C44, 0x49535000, 0x57494E4E, 0x45523031, 0x0, 0x57494E4E,
    0x45523032, 0x0, 0x57494E4E, 0x45523033, 0x0, 0x57494E4E, 0x45523034, 0x0,
    0x48594F55, 0x53594F55, 0x53504F54, 0x0, 0x48594F55, 0x53594F55, 0x0, 0x4D55545F,
    0x47524F55, 0x4E440000, 0x4D55545F, 0x53544152, 0x53000000, 0x4D55545F, 0x43495459, 0x5F4C4947,
    0x48545300, 0x0, (u32)lbl_1_data_2A6F0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A6F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A700__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A70C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A718__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A724__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A730__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A740__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A74C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A758__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A764__fzgx_offset_0, 0x3,
    0x0, 0x0, 0x0, 0x0
}};
static union { u32 w[243]; SelectionState v; } fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_720 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080, 0x80000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, (u32)lbl_1_data_1E968__fzgx_offset_0, (u32)lbl_1_data_1E974__fzgx_offset_0,
    (u32)lbl_1_data_1E980__fzgx_offset_0, (u32)lbl_1_data_1E98C__fzgx_offset_0, (u32)lbl_1_data_1E998__fzgx_offset_0, (u32)lbl_1_data_1E9A4__fzgx_offset_0, (u32)lbl_1_data_1E9B0__fzgx_offset_0, (u32)lbl_1_data_1E9BC__fzgx_offset_0, (u32)lbl_1_data_1E9C8__fzgx_offset_0, (u32)lbl_1_data_1E9D4__fzgx_offset_0,
    (u32)lbl_1_data_1E9E0__fzgx_offset_0, (u32)lbl_1_data_1E9EC__fzgx_offset_0, (u32)lbl_1_data_1E9F8__fzgx_offset_0, (u32)lbl_1_data_1EA04__fzgx_offset_0, (u32)lbl_1_data_1EA10__fzgx_offset_0, (u32)lbl_1_data_1EA1C__fzgx_offset_0, (u32)lbl_1_data_1EA34__fzgx_offset_0, (u32)lbl_1_data_1EA40__fzgx_offset_0,
    (u32)lbl_1_data_1EA4C__fzgx_offset_0, (u32)lbl_1_data_1EA58__fzgx_offset_0, (u32)lbl_1_data_1EA64__fzgx_offset_0, (u32)lbl_1_data_1ED48__fzgx_offset_0, (u32)lbl_1_data_1ED54__fzgx_offset_0, (u32)lbl_1_data_1ED60__fzgx_offset_0, (u32)lbl_1_data_1ED6C__fzgx_offset_0, (u32)lbl_1_data_1ED78__fzgx_offset_0,
    (u32)lbl_1_data_1ED84__fzgx_offset_0, (u32)lbl_1_data_1ED90__fzgx_offset_0, (u32)lbl_1_data_1ED9C__fzgx_offset_0, (u32)lbl_1_data_1EDA8__fzgx_offset_0, (u32)lbl_1_data_1EDB4__fzgx_offset_0, (u32)lbl_1_data_1EDC0__fzgx_offset_0, (u32)lbl_1_data_1EDCC__fzgx_offset_0, (u32)lbl_1_data_1EDD8__fzgx_offset_0,
    (u32)lbl_1_data_1EDE4__fzgx_offset_0, (u32)lbl_1_data_1EDF0__fzgx_offset_0, (u32)lbl_1_data_1EDFC__fzgx_offset_0, (u32)lbl_1_data_1EE08__fzgx_offset_0, (u32)lbl_1_data_1EE14__fzgx_offset_0, (u32)lbl_1_data_1EE20__fzgx_offset_0, (u32)lbl_1_data_1EE2C__fzgx_offset_0, (u32)lbl_1_data_1EE38__fzgx_offset_0,
    0x4E554C4C, 0x0, 0x4D555445, 0x20434954, 0x59000000, 0x504F5254, 0x20544F57, 0x4E000000,
    0x42494720, 0x424C5545, 0x0, 0x4C494748, 0x544E494E, 0x47000000, 0x53414E44, 0x204F4345,
    0x414E0000, 0x47524545, 0x4E20504C, 0x414E5400, 0x46495245, 0x20464945, 0x4C440000, 0x43415349,
    0x4E4F2050, 0x414C4143, 0x45000000, 0x4F555445, 0x52205350, 0x41434500, 0x4145524F, 0x504F4C49,
    0x53000000, 0x434F534D, 0x4F205445, 0x524D494E, 0x414C0000, 0x5048414E, 0x544F4D20, 0x524F4144,
    0x0, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0,
    (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9C4__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9DC__fzgx_offset_0, (u32)lbl_1_data_2A9EC__fzgx_offset_0,
    (u32)lbl_1_data_2A9F8__fzgx_offset_0, (u32)lbl_1_data_2AA04__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2AA14__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, 0x0, 0x837E8385,
    0x815B8367, 0x20835683, 0x65834200, 0x837C815B, 0x83672083, 0x5E834583, 0x93000000, 0x83728362,  /* fzgx-allow: A1 retail data bytes */
    0x834F2083, 0x75838B81, 0x5B000000, 0x83898343, 0x8367836A, 0x8393834F, 0x0, 0x83548393,
    0x83682083, 0x49815B83, 0x56838383, 0x93000000, 0x834F838A, 0x815B8393, 0x20837683, 0x89839383,  /* fzgx-allow: A1 retail data bytes */
    0x67000000, 0x83748340, 0x83438341, 0x20837483, 0x42815B83, 0x8B836800, 0x834A8357, 0x836D2083,
    0x70838C83, 0x58000000, 0x83418345, 0x835E815B, 0x20835883, 0x79815B83, 0x58000000, 0x83478341,
    0x838D837C, 0x838A8358, 0x0, 0x83528358, 0x83822083, 0x5E815B83, 0x7E836983, 0x8B000000,
    0x83748340, 0x83938367, 0x83802083, 0x8D815B83, 0x68000000, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0,
    (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AAD0__fzgx_offset_0,
    (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAF8__fzgx_offset_0, (u32)lbl_1_data_2AB08__fzgx_offset_0, (u32)lbl_1_data_2AB1C__fzgx_offset_0, (u32)lbl_1_data_2AB2C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0,
    (u32)lbl_1_data_2AB40__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, 0x0
}};
static union { u32 w[306]; SelectionRow v[34]; } fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_AEC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0,
    (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0,
    (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0,
    (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0,
    (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0,
    (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0,
    (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0,
    (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0,
    (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0,
    (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_DC204__fzgx_offset_0, (u32)fn_1_DC208__fzgx_offset_0, (u32)fn_1_DC264__fzgx_offset_0, (u32)fn_1_DC268__fzgx_offset_0, (u32)fn_1_DC2F8__fzgx_offset_0, (u32)fn_1_DC33C__fzgx_offset_0,
    (u32)fn_1_DC3A0__fzgx_offset_0, (u32)fn_1_DCB9C__fzgx_offset_0, (u32)fn_1_DCBF4__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0,
    (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0,
    (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_FA6C0__fzgx_offset_0, (u32)fn_1_FA75C__fzgx_offset_0, (u32)fn_1_FA82C__fzgx_offset_0,
    (u32)fn_1_FA830__fzgx_offset_0, (u32)fn_1_FA854__fzgx_offset_0, (u32)fn_1_FA878__fzgx_offset_0, (u32)fn_1_FA898__fzgx_offset_0, (u32)fn_1_FB770__fzgx_offset_0, (u32)fn_1_FB798__fzgx_offset_0, (u32)fn_1_FE5E0__fzgx_offset_0, (u32)fn_1_FE5E4__fzgx_offset_0,
    (u32)fn_1_FE640__fzgx_offset_0, (u32)fn_1_FE644__fzgx_offset_0, (u32)fn_1_FE780__fzgx_offset_0, (u32)fn_1_FE784__fzgx_offset_0, (u32)fn_1_FE7D4__fzgx_offset_0, (u32)fn_1_101348__fzgx_offset_0, (u32)fn_1_1013A0__fzgx_offset_0, (u32)fn_1_153988__fzgx_offset_0,
    (u32)fn_1_15398C__fzgx_offset_0, (u32)fn_1_1539D0__fzgx_offset_0, (u32)fn_1_153A28__fzgx_offset_0, (u32)fn_1_153AAC__fzgx_offset_0, (u32)fn_1_153AB0__fzgx_offset_0, (u32)fn_1_153AF4__fzgx_offset_0, (u32)fn_1_1543E8__fzgx_offset_0, (u32)fn_1_154410__fzgx_offset_0,
    (u32)fn_1_150500__fzgx_offset_0, (u32)fn_1_150518__fzgx_offset_0, (u32)fn_1_150570__fzgx_offset_0, (u32)fn_1_1505B4__fzgx_offset_0, (u32)fn_1_150574__fzgx_offset_0, (u32)fn_1_150608__fzgx_offset_0, (u32)fn_1_150650__fzgx_offset_0, (u32)fn_1_151764__fzgx_offset_0,
    (u32)fn_1_15176C__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0,
    (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1586A8__fzgx_offset_0, (u32)fn_1_1586AC__fzgx_offset_0, (u32)fn_1_158980__fzgx_offset_0, (u32)fn_1_158984__fzgx_offset_0, (u32)fn_1_15903C__fzgx_offset_0,
    (u32)fn_1_159040__fzgx_offset_0, (u32)fn_1_159060__fzgx_offset_0, (u32)fn_1_159064__fzgx_offset_0, (u32)fn_1_15906C__fzgx_offset_0, (u32)fn_1_15B428__fzgx_offset_0, (u32)fn_1_15B42C__fzgx_offset_0, (u32)fn_1_15B4F8__fzgx_offset_0, (u32)fn_1_15B4FC__fzgx_offset_0,
    (u32)fn_1_15B51C__fzgx_offset_0, (u32)fn_1_15B520__fzgx_offset_0, (u32)fn_1_15B540__fzgx_offset_0, (u32)fn_1_15B698__fzgx_offset_0, (u32)fn_1_15B70C__fzgx_offset_0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x62675F6D, 0x75740000,
    0x62675F70, 0x6F720000, 0x62675F70, 0x6F725F73, 0x0, 0x62675F62, 0x69670000, 0x62675F62,
    0x69675F73, 0x0, 0x62675F6C, 0x69670000, 0x62675F73, 0x616E0000, 0x62675F73, 0x616E5F73,
    0x0, 0x62675F66, 0x6F720000, 0x62675F66, 0x69720000, 0x62675F66, 0x69725F73, 0x0,
    0x62675F63, 0x61730000, 0x62675F6D, 0x65740000, 0x62675F74, 0x6F770000, 0x62675F65, 0x6C650000,
    0x62675F63, 0x6F6D0000, 0x62675F63, 0x6F6D5F73, 0x0, 0x62675F72, 0x61690000, 0x62675F77,
    0x696E5F67, 0x78000000, 0x0, (u32)lbl_1_data_2AEC4__fzgx_offset_0, (u32)lbl_1_data_2AECC__fzgx_offset_0, (u32)lbl_1_data_2AED4__fzgx_offset_0, (u32)lbl_1_data_2AEE0__fzgx_offset_0, (u32)lbl_1_data_2AEE8__fzgx_offset_0,
    (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEFC__fzgx_offset_0, (u32)lbl_1_data_2AF04__fzgx_offset_0, (u32)lbl_1_data_2AF10__fzgx_offset_0, (u32)lbl_1_data_2AF18__fzgx_offset_0, (u32)lbl_1_data_2AF20__fzgx_offset_0, (u32)lbl_1_data_2AF2C__fzgx_offset_0,
    (u32)lbl_1_data_2AF34__fzgx_offset_0, (u32)lbl_1_data_2AF3C__fzgx_offset_0, (u32)lbl_1_data_2AF44__fzgx_offset_0, (u32)lbl_1_data_2AF4C__fzgx_offset_0, (u32)lbl_1_data_2AF54__fzgx_offset_0, (u32)lbl_1_data_2AF60__fzgx_offset_0, (u32)lbl_1_data_2AF68__fzgx_offset_0, 0x0,
    0x0, 0x4, 0x202C0, 0x202C0, 0x18B0, 0x18B0, 0xFD80, 0xFD80,
    0x1C60, 0x1C60, 0x226C, 0x764, 0x764, 0x174, 0x1B1E8, 0x1704,
    0x2748, 0x4, 0x4, 0x157CC, 0x128, 0x0, 0x0, (u32)lbl_1_data_2A30C__fzgx_offset_0,
    (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0,
    (u32)lbl_1_data_2A35C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A484__fzgx_offset_0, (u32)lbl_1_data_2A4E8__fzgx_offset_0, (u32)lbl_1_data_2A5DC__fzgx_offset_0, (u32)lbl_1_data_2A528__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0,
    (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A664__fzgx_offset_0
}};
static union { u32 w[2]; u32 v[2]; } fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_FB4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_2A6C0__fzgx_offset_0, 0x0
}};
static union { u32 w[23]; void *v[23]; } fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_FBC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0,
    (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A384__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A49C__fzgx_offset_0, (u32)lbl_1_data_2A518__fzgx_offset_0, (u32)lbl_1_data_2A62C__fzgx_offset_0,
    (u32)lbl_1_data_2A580__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A674__fzgx_offset_0, (u32)lbl_1_data_2A774__fzgx_offset_0, 0x0, 0x8010101
}};

void fn_1_9A508(void) {
    s32 index = fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_720.v.index;
    fn_1_9AD20();
    fn_1_9D0EC(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48,
                 fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_FBC.v[index], fzgx_pool_init_lbl_1_data_2A0C0__fzgx_offset_AEC.v[index].callback);
}
/* fzgx:end fn_1_9A508 */

/* fzgx:begin fn_1_9A578 */
// Advances the burner state and invokes the callback for the active entry.
void fn_1_9A578(void) {
    void (**callback)(void);

    if (lbl_1_data_2A7E0.unk_0 > 0) {
        fn_1_10302C();
        callback = (void (**)(void))&lbl_1_data_2ABAC;
        callback[lbl_1_data_2A7E0.unk_0 * 9 + 2]();
    }
}
/* fzgx:end fn_1_9A578 */

/* fzgx:begin fn_1_9A5CC */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 6885000.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

/* local view of lbl_1_data_2A7E0 with the fields this function touches (globals.h's type lacks 0x6-0x2B) */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x4];
    u8 unk_6[4];
    u8 pad_A[0x2];
    u32 unk_C[4];
    f32 unk_1C[4];
    u8 pad_2C[0x18];
    u32 unk_44;
    u8 pad_48[0x3C];
    s32 unk_84;
    u32 unk_88;
    u8 pad_8C[0x8];
    f32 unk_94;
    f32 unk_98;
    u8 pad_9C[0x5C];
} fn_1_9A5CC_Data2A7E0;

/* one of the 0x24-byte entries of lbl_1_data_2ABAC (0x318 bytes, 22 entries) */
typedef struct {
    u8 pad_0[0xC];
    void (*unk_C)(void);
    u8 pad_10[0x14];
} fn_1_9A5CC_Data2ABAC;

typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0xC];
    f32 unk_1C;
    u8 pad_20[0x270];
} fn_1_9A5CC_Data2C8D0;

extern u32 fn_1_58C4(void);
extern s32 fn_1_3F0C8(void);
extern void fn_1_103030(void);
extern u32 fn_1_9D260(void);
extern u32 fn_1_9D230(void);
extern void fn_1_9AD54(void);

/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base (lbl_1_data_2A0C0); the fzgx_pool_gap_ objects span the retail objects in between */
u32 fzgx_obj_lbl_1_data_2A0C0[4] = {1};
u8 fzgx_pool_gap_2A0D0[0x2A7E0 - 0x2A0D0] = {1};
fn_1_9A5CC_Data2A7E0 fzgx_obj_lbl_1_data_2A7E0 = {1};
u8 fzgx_pool_gap_2A8D8[0x2ABAC - 0x2A8D8] = {1};
fn_1_9A5CC_Data2ABAC fzgx_obj_lbl_1_data_2ABAC[22] = {1};
u8 fzgx_pool_gap_2AEC4[0x2C8D0 - 0x2AEC4] = {1};
fn_1_9A5CC_Data2C8D0 fzgx_obj_lbl_1_data_2C8D0 = {1};

/* The BackGroundCalc task (priority 23). Stores the viewport count, advances four frame counters (each by its
 * step byte; counter 1 holds while fn_1_3F0C8 returns 0x27) that wrap at 6885000 and are mirrored as floats,
 * then runs entry [0x2A7E0]'s update from lbl_1_data_2ABAC while that index is positive and fn_1_9D230 is 0
 * (fewer than three viewports), and fn_1_9AD54 otherwise. */
void fn_1_9A5CC(void) {
    u32 viewports;
    s32 i;

    if (fzgx_obj_lbl_1_data_2A7E0.unk_84 != 0) {
        viewports = 4;
    } else {
        viewports = fn_1_58C4();
    }
    fzgx_obj_lbl_1_data_2A7E0.unk_88 = viewports;
    fzgx_obj_lbl_1_data_2C8D0.unk_C = fzgx_obj_lbl_1_data_2A7E0.unk_98;
    fzgx_obj_lbl_1_data_2C8D0.unk_1C = fzgx_obj_lbl_1_data_2A7E0.unk_94;
    for (i = 0; i < 4; i++) {
        /* retail stores single bytes at 0x2A7E6 + i (stb), though symbols.txt types lbl_1_data_2A7E0 as 4-byte data */
        fzgx_obj_lbl_1_data_2A7E0.unk_6[i] = 0;
        switch (i) {
        case 1:
            if ((s16)fn_1_3F0C8() != 0x27) {
                fzgx_obj_lbl_1_data_2A7E0.unk_6[i] = 1;
            }
            break;
        default:
            fzgx_obj_lbl_1_data_2A7E0.unk_6[i] = 1;
            break;
        }
        fzgx_obj_lbl_1_data_2A7E0.unk_C[i] += fzgx_obj_lbl_1_data_2A7E0.unk_6[i];
        if (fzgx_obj_lbl_1_data_2A7E0.unk_C[i] >= 6885000) {
            fzgx_obj_lbl_1_data_2A7E0.unk_C[i] = 0;
        }
        fzgx_obj_lbl_1_data_2A7E0.unk_1C[i] = fzgx_obj_lbl_1_data_2A7E0.unk_C[i];
    }
    fzgx_obj_lbl_1_data_2A7E0.unk_44++;
    /* retail reads lbl_1_bss_960 signed (lha); globals.h declares it u16 */
    if (*(s16 *)&lbl_1_bss_960 == 10) {
        fzgx_obj_lbl_1_data_2A7E0.unk_6[1] = 0;
        fzgx_obj_lbl_1_data_2A7E0.unk_C[1] = 6885000;
        fzgx_obj_lbl_1_data_2A7E0.unk_1C[1] = 6885000.0f;
    }
    fn_1_103030();
    if (fzgx_obj_lbl_1_data_2A7E0.unk_0 > 0) {
        fn_1_9D260();
        if ((s32)fn_1_9D230() == 0) {
            fzgx_obj_lbl_1_data_2ABAC[fzgx_obj_lbl_1_data_2A7E0.unk_0].unk_C();
            return;
        }
    }
    fn_1_9AD54();
}
/* fzgx:end fn_1_9A5CC */

/* fzgx:begin fn_1_9A770 */
typedef void (*fn_1_9A770_callback)(void);

// Invokes the registered burner callback when one is installed.
void fn_1_9A770(void) {
    fn_1_9A770_callback callback = (fn_1_9A770_callback)lbl_1_data_2A7E0.unk_38;

    if (callback != 0) {
        callback();
    }
}
/* fzgx:end fn_1_9A770 */

/* fzgx:begin fn_1_9A7A8 */
void fn_1_9A7A8(u32 *value) {
    *(u32 *)((u8 *)&lbl_1_data_2A7E0 + 2) = *value;
}
/* fzgx:end fn_1_9A7A8 */

/* fzgx:begin fn_1_9A7BC */
typedef struct {
    s16 idx;
    u8 pad_02[0x82];
    s32 unk_84;
    s32 unk_88;
    u8 pad_8C[8];
    f32 unk_94;
    f32 unk_98;
} Fn9A7BCA;

typedef struct {
    u8 pad[0xc];
    f32 unk_c;
    u8 pad2[0xc];
    f32 unk_1c;
} Fn9A7BCB;

typedef struct {
    u8 pad[0x14];
    void (*fn)(void);
    u8 pad2[0xc];
} Fn9A7BCC;


extern s32 fn_1_58C4(void);
extern void fn_1_103058(void);
extern u32 fn_1_9D260(void);
extern u32 fn_1_9D230(void);
extern void fn_1_9AD88(void);

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
static inline s32 Fn9A7BC_flag(Fn9A7BCA *a) {
    return a->unk_84;
}

static inline void Fn9A7BC_copy_values(Fn9A7BCB *b, Fn9A7BCA *a, s32 v) {
    b->unk_c = a->unk_98;
    b->unk_1c = a->unk_94;
    a->unk_88 = v;
}

extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
extern u8 lbl_1_data_2B15C__fzgx_offset_0[];
extern u8 lbl_1_data_2B160__fzgx_offset_0[];
extern u8 lbl_1_data_2B16C__fzgx_offset_0[];
extern u8 lbl_1_data_2B178__fzgx_offset_0[];
extern u8 lbl_1_data_2B184__fzgx_offset_0[];
extern u8 lbl_1_data_2B190__fzgx_offset_0[];
extern u8 lbl_1_data_2B19C__fzgx_offset_0[];
extern u8 lbl_1_data_2B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B1D0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1F0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B208__fzgx_offset_0[];
extern u8 lbl_1_data_2B218__fzgx_offset_0[];
extern u8 lbl_1_data_2B220__fzgx_offset_0[];
extern u8 lbl_1_data_2B230__fzgx_offset_0[];
extern u8 lbl_1_data_2B240__fzgx_offset_0[];
extern u8 lbl_1_data_2B248__fzgx_offset_0[];
extern u8 lbl_1_data_2B258__fzgx_offset_0[];
extern u8 lbl_1_data_2B268__fzgx_offset_0[];
extern u8 lbl_1_data_2B274__fzgx_offset_0[];
extern u8 lbl_1_data_2B284__fzgx_offset_0[];
extern u8 lbl_1_data_2B294__fzgx_offset_0[];
extern u8 lbl_1_data_2B2A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B474__fzgx_offset_0[];
extern u8 lbl_1_data_2B47C__fzgx_offset_0[];
extern u8 lbl_1_data_2B48C__fzgx_offset_0[];
extern u8 lbl_1_data_2B49C__fzgx_offset_0[];
extern u8 lbl_1_data_2B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4BC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B50C__fzgx_offset_0[];
extern u8 lbl_1_data_2B520__fzgx_offset_0[];
extern u8 lbl_1_data_2B530__fzgx_offset_0[];
extern u8 lbl_1_data_2B540__fzgx_offset_0[];
extern u8 lbl_1_data_2B550__fzgx_offset_0[];
extern u8 lbl_1_data_2B560__fzgx_offset_0[];
extern u8 lbl_1_data_2B574__fzgx_offset_0[];
extern u8 lbl_1_data_2B584__fzgx_offset_0[];
extern u8 lbl_1_data_2B594__fzgx_offset_0[];
extern u8 lbl_1_data_2B5A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5D4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5E4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B604__fzgx_offset_0[];
extern u8 lbl_1_data_2B614__fzgx_offset_0[];
extern u8 lbl_1_data_2B624__fzgx_offset_0[];
extern u8 lbl_1_data_2B634__fzgx_offset_0[];
extern u8 lbl_1_data_2B644__fzgx_offset_0[];
extern u8 lbl_1_data_2B654__fzgx_offset_0[];
extern u8 lbl_1_data_2B664__fzgx_offset_0[];
extern u8 lbl_1_data_2B678__fzgx_offset_0[];
extern u8 lbl_1_data_2B68C__fzgx_offset_0[];
extern u8 lbl_1_data_2B6A0__fzgx_offset_0[];
extern u8 lbl_1_data_2B6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6E8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2B708__fzgx_offset_0[];
extern u8 lbl_1_data_2B718__fzgx_offset_0[];
extern u8 lbl_1_data_2B728__fzgx_offset_0[];
extern u8 lbl_1_data_2B738__fzgx_offset_0[];
extern u8 lbl_1_data_2B748__fzgx_offset_0[];
extern u8 lbl_1_data_2B758__fzgx_offset_0[];
extern u8 lbl_1_data_2B768__fzgx_offset_0[];
extern u8 lbl_1_data_2B77C__fzgx_offset_0[];
extern u8 lbl_1_data_2B790__fzgx_offset_0[];
extern u8 lbl_1_data_2B7A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B7B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B7CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B7E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B7F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B808__fzgx_offset_0[];
extern u8 lbl_1_data_2B81C__fzgx_offset_0[];
extern u8 lbl_1_data_2B830__fzgx_offset_0[];
extern u8 lbl_1_data_2B840__fzgx_offset_0[];
extern u8 lbl_1_data_2B850__fzgx_offset_0[];
extern u8 lbl_1_data_2B860__fzgx_offset_0[];
extern u8 lbl_1_data_2B870__fzgx_offset_0[];
extern u8 lbl_1_data_2B884__fzgx_offset_0[];
extern u8 lbl_1_data_2B894__fzgx_offset_0[];
extern u8 lbl_1_data_2B8A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B8EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B900__fzgx_offset_0[];
extern u8 lbl_1_data_2B914__fzgx_offset_0[];
extern u8 lbl_1_data_2B928__fzgx_offset_0[];
extern u8 lbl_1_data_2B93C__fzgx_offset_0[];
extern u8 lbl_1_data_2B948__fzgx_offset_0[];
extern u8 lbl_1_data_2B954__fzgx_offset_0[];
extern u8 lbl_1_data_2B960__fzgx_offset_0[];
extern u8 lbl_1_data_2B96C__fzgx_offset_0[];
extern u8 lbl_1_data_2B97C__fzgx_offset_0[];
extern u8 lbl_1_data_2B990__fzgx_offset_0[];
extern u8 lbl_1_data_2B9A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B9CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9F0__fzgx_offset_0[];
extern u8 lbl_1_data_2BA04__fzgx_offset_0[];
extern u8 lbl_1_data_2BA18__fzgx_offset_0[];
extern u8 lbl_1_data_2BA2C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA40__fzgx_offset_0[];
extern u8 lbl_1_data_2BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA58__fzgx_offset_0[];
extern u8 lbl_1_data_2BA64__fzgx_offset_0[];
extern u8 lbl_1_data_2BA70__fzgx_offset_0[];
extern u8 lbl_1_data_2BA80__fzgx_offset_0[];
extern u8 lbl_1_data_2BA94__fzgx_offset_0[];
extern u8 lbl_1_data_2BAA8__fzgx_offset_0[];
extern u8 lbl_1_data_2BABC__fzgx_offset_0[];
extern u8 lbl_1_data_2BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_2BB10__fzgx_offset_0[];
extern u8 lbl_1_data_2BB24__fzgx_offset_0[];
extern u8 lbl_1_data_2BB38__fzgx_offset_0[];
extern u8 lbl_1_data_2BB48__fzgx_offset_0[];
extern u8 lbl_1_data_2BB58__fzgx_offset_0[];
extern u8 lbl_1_data_2BB68__fzgx_offset_0[];
extern u8 lbl_1_data_2BB78__fzgx_offset_0[];
extern u8 lbl_1_data_2BB88__fzgx_offset_0[];
extern u8 lbl_1_data_2BB9C__fzgx_offset_0[];
extern u8 lbl_1_data_2BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_2BBC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BBD8__fzgx_offset_0[];
extern u8 lbl_1_data_2BBEC__fzgx_offset_0[];
extern u8 lbl_1_data_2BC00__fzgx_offset_0[];
extern u8 lbl_1_data_2BC14__fzgx_offset_0[];
extern u8 lbl_1_data_2BC28__fzgx_offset_0[];
extern u8 lbl_1_data_2BC3C__fzgx_offset_0[];
extern u8 lbl_1_data_2BC50__fzgx_offset_0[];
extern u8 lbl_1_data_2BC64__fzgx_offset_0[];
extern u8 lbl_1_data_2BC78__fzgx_offset_0[];
extern u8 lbl_1_data_2BC8C__fzgx_offset_0[];
extern u8 lbl_1_data_2BCA0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCB4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCDC__fzgx_offset_0[];
extern u8 lbl_1_data_2BCE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BCF4__fzgx_offset_0[];
extern u8 lbl_1_data_2BD00__fzgx_offset_0[];
extern u8 lbl_1_data_2BD10__fzgx_offset_0[];
extern u8 lbl_1_data_2BD20__fzgx_offset_0[];
extern u8 lbl_1_data_2BD30__fzgx_offset_0[];
extern u8 lbl_1_data_2BD40__fzgx_offset_0[];
extern u8 lbl_1_data_2C7BC__fzgx_offset_0[];
extern u8 lbl_1_data_2C7C0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E4__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E8__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F8__fzgx_offset_0[];
extern u8 lbl_1_data_2C804__fzgx_offset_0[];
extern u8 lbl_1_data_2C80C__fzgx_offset_0[];
extern u8 lbl_1_data_2C818__fzgx_offset_0[];
extern u8 lbl_1_data_2C824__fzgx_offset_0[];
extern u8 lbl_1_data_2C86C__fzgx_offset_0[];
extern u8 lbl_1_data_2C870__fzgx_offset_0[];
extern u8 lbl_1_data_2C890__fzgx_offset_0[];
extern u8 lbl_1_data_2C8B0__fzgx_offset_0[];
extern u8 lbl_1_data_2C8D0__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_2A0C0[456] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F43455F, 0x4C494748, 0x544D4150, 0x5F410000, 0x4F43455F, 0x57415645, 0x5F504154, 0x5F420000,
    0x4F43455F, 0x4E414D49, 0x5F000000, 0x4F434E5F, 0x504F4F4C, 0x0, 0x42494742, 0x4C55455F,
    0x52454E5A, 0x5F465245, 0x41303100, 0x1, (u32)lbl_1_data_2A0C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A0D0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A0E0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0F8__fzgx_offset_0, 0x3, 0x0, 0x5F6C746D,
    0x70000000, 0x5F6C746D, 0x70320000, 0x4F43455F, 0x43415343, 0x4144455F, 0x0, 0x4F43455F,
    0x4332375F, 0x43415343, 0x41444500, 0x43554245, 0x5F474154, 0x455F415F, 0x4C4F4400, 0x43554245,
    0x5F425F41, 0x5F4C4F44, 0x0, 0x43554245, 0x5F445F41, 0x5F4C4F44, 0x0, 0x42494742,
    0x4C55455F, 0x53554E30, 0x31000000, 0x2, (u32)lbl_1_data_2A13C__fzgx_offset_0, 0x2, (u32)lbl_1_data_2A144__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A14C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A15C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A16C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A17C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A18C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A19C__fzgx_offset_0, 0x3, 0x0, 0x5F5F5F00,
    0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3, 0x0, 0x5041544C, 0x414D505F, 0x41000000, 0x5041544C,
    0x414D505F, 0x42000000, 0x5041544C, 0x414D505F, 0x43000000, 0x5041544C, 0x414D505F, 0x44000000,
    0x424E535F, 0x534B595F, 0x4B554D4F, 0x5F000000, 0x4C49475F, 0x47524F55, 0x4E445F41, 0x0,
    0x4330385F, 0x5241494E, 0x524F4144, 0x0, 0x4330395F, 0x5241494E, 0x524F4144, 0x0,
    0x4332335F, 0x5241494E, 0x524F4144, 0x0, 0x4333345F, 0x5241494E, 0x524F4144, 0x0,
    0x52455041, 0x4952504F, 0x494E5400, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A240__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A250__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A260__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A270__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A280__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A290__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A2A0__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x464C4147, 0x0, 0x0,
    (u32)lbl_1_data_2A314__fzgx_offset_0, 0x3, 0x0, 0x464F525F, 0x4546465F, 0x48413031, 0x0, 0x464F525F,
    0x52454E5A, 0x5F465245, 0x41000000, 0x464F525F, 0x4546465F, 0x47524E4C, 0x49470000, 0x1,
    (u32)lbl_1_data_2A32C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A33C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A34C__fzgx_offset_0, 0x3, 0x0, 0x464F525F,
    0x53554E00, 0x0, (u32)lbl_1_data_2A37C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3,
    0x0, 0x535F5348, 0x49500000, 0x0, (u32)lbl_1_data_2A3C4__fzgx_offset_0, 0x3, 0x0, 0x53414E5F,
    0x57415645, 0x5F504154, 0x5F4D0000, 0x53414E5F, 0x57415645, 0x5F504154, 0x5F530000, 0x474F524F,
    0x46524147, 0x5F767478, 0x0, 0x474F524F, 0x46524147, 0x325F7674, 0x78000000, 0x1,
    (u32)lbl_1_data_2A3DC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3EC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3FC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A40C__fzgx_offset_0, 0x3,
    0x0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x44494345,
    0x0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x434F494E, 0x0, 0x0,
    (u32)lbl_1_data_2A494__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x4D45545F, 0x434F4D45, 0x54303200,
    0x4546465F, 0x524F434B, 0x46495245, 0x5F415F52, 0x32533100, 0x4546465F, 0x524F434B, 0x46495245,
    0x5F425F52, 0x32533100, 0x1, (u32)lbl_1_data_2A4B4__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4D4__fzgx_offset_0,
    0x3, 0x0, 0x4D45545F, 0x42494753, 0x54415230, 0x31000000, 0x0, (u32)lbl_1_data_2A508__fzgx_offset_0,
    0x3, 0x0, 0x3, 0x0, 0x454C565F, 0x544F5000, 0x454C565F, 0x434F4C4F,
    0x4E590000, 0x454C565F, 0x544F5745, 0x52424153, 0x4530315F, 0x415F4C4F, 0x44000000, 0x454C565F,
    0x43415247, 0x4F30315F, 0x415F4C4F, 0x44000000, 0x454C565F, 0x424F5830, 0x315F415F, 0x4C4F4400,
    0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A530__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A538__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A544__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A55C__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A570__fzgx_offset_0, 0x3, 0x0, 0x57494E44, 0x4F573031, 0x0, 0x0,
    (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x3, 0x0, 0x53454152, 0x43483031, 0x0, 0x53454152, 0x43485F41,
    0x524D3031, 0x0, 0x53454152, 0x43485F41, 0x524D3032, 0x0, 0x5343414D, 0x504F494E,
    0x54303100, 0x464C4153, 0x48303100, 0x0, (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A5EC__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A5F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A608__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A618__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A624__fzgx_offset_0, 0x3,
    0x0, 0x3, 0x0, 0x43554245, 0x0, 0x0, (u32)lbl_1_data_2A66C__fzgx_offset_0, 0x3,
    0x0, 0x4654565F, 0x4C4F474F, 0x0, 0x4654565F, 0x52494E47, 0x0, 0x4654565F,
    0x52494E47, 0x5F460000, 0x4654565F, 0x45415254, 0x48000000, 0x4654565F, 0x52494E47, 0x5F540000,
    0x0, (u32)lbl_1_data_2A684__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A690__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A69C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A6A8__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2A6B4__fzgx_offset_0, 0x3, 0x0, 0x43415244, 0x49535000, 0x47414C44, 0x49535000,
    0x57494E4E, 0x45523031, 0x0, 0x57494E4E, 0x45523032, 0x0, 0x57494E4E, 0x45523033,
    0x0, 0x57494E4E, 0x45523034, 0x0, 0x48594F55, 0x53594F55, 0x53504F54, 0x0,
    0x48594F55, 0x53594F55, 0x0, 0x4D55545F, 0x47524F55, 0x4E440000, 0x4D55545F, 0x53544152,
    0x53000000, 0x4D55545F, 0x43495459, 0x5F4C4947, 0x48545300, 0x0, (u32)lbl_1_data_2A6F0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A6F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A700__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A70C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A718__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A724__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A730__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A740__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A74C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A758__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A764__fzgx_offset_0, 0x3, 0x0, 0x0, 0x0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2A7E0[62] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080, 0x80000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
static u32 fzgx_pool_data_lbl_1_data_2A8D8[181] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_1E968__fzgx_offset_0, (u32)lbl_1_data_1E974__fzgx_offset_0, (u32)lbl_1_data_1E980__fzgx_offset_0, (u32)lbl_1_data_1E98C__fzgx_offset_0, (u32)lbl_1_data_1E998__fzgx_offset_0, (u32)lbl_1_data_1E9A4__fzgx_offset_0, (u32)lbl_1_data_1E9B0__fzgx_offset_0, (u32)lbl_1_data_1E9BC__fzgx_offset_0,
    (u32)lbl_1_data_1E9C8__fzgx_offset_0, (u32)lbl_1_data_1E9D4__fzgx_offset_0, (u32)lbl_1_data_1E9E0__fzgx_offset_0, (u32)lbl_1_data_1E9EC__fzgx_offset_0, (u32)lbl_1_data_1E9F8__fzgx_offset_0, (u32)lbl_1_data_1EA04__fzgx_offset_0, (u32)lbl_1_data_1EA10__fzgx_offset_0, (u32)lbl_1_data_1EA1C__fzgx_offset_0,
    (u32)lbl_1_data_1EA34__fzgx_offset_0, (u32)lbl_1_data_1EA40__fzgx_offset_0, (u32)lbl_1_data_1EA4C__fzgx_offset_0, (u32)lbl_1_data_1EA58__fzgx_offset_0, (u32)lbl_1_data_1EA64__fzgx_offset_0, (u32)lbl_1_data_1ED48__fzgx_offset_0, (u32)lbl_1_data_1ED54__fzgx_offset_0, (u32)lbl_1_data_1ED60__fzgx_offset_0,
    (u32)lbl_1_data_1ED6C__fzgx_offset_0, (u32)lbl_1_data_1ED78__fzgx_offset_0, (u32)lbl_1_data_1ED84__fzgx_offset_0, (u32)lbl_1_data_1ED90__fzgx_offset_0, (u32)lbl_1_data_1ED9C__fzgx_offset_0, (u32)lbl_1_data_1EDA8__fzgx_offset_0, (u32)lbl_1_data_1EDB4__fzgx_offset_0, (u32)lbl_1_data_1EDC0__fzgx_offset_0,
    (u32)lbl_1_data_1EDCC__fzgx_offset_0, (u32)lbl_1_data_1EDD8__fzgx_offset_0, (u32)lbl_1_data_1EDE4__fzgx_offset_0, (u32)lbl_1_data_1EDF0__fzgx_offset_0, (u32)lbl_1_data_1EDFC__fzgx_offset_0, (u32)lbl_1_data_1EE08__fzgx_offset_0, (u32)lbl_1_data_1EE14__fzgx_offset_0, (u32)lbl_1_data_1EE20__fzgx_offset_0,
    (u32)lbl_1_data_1EE2C__fzgx_offset_0, (u32)lbl_1_data_1EE38__fzgx_offset_0, 0x4E554C4C, 0x0, 0x4D555445, 0x20434954, 0x59000000, 0x504F5254,
    0x20544F57, 0x4E000000, 0x42494720, 0x424C5545, 0x0, 0x4C494748, 0x544E494E, 0x47000000,
    0x53414E44, 0x204F4345, 0x414E0000, 0x47524545, 0x4E20504C, 0x414E5400, 0x46495245, 0x20464945,
    0x4C440000, 0x43415349, 0x4E4F2050, 0x414C4143, 0x45000000, 0x4F555445, 0x52205350, 0x41434500,
    0x4145524F, 0x504F4C49, 0x53000000, 0x434F534D, 0x4F205445, 0x524D494E, 0x414C0000, 0x5048414E,
    0x544F4D20, 0x524F4144, 0x0, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0,
    (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9C4__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0,
    (u32)lbl_1_data_2A9DC__fzgx_offset_0, (u32)lbl_1_data_2A9EC__fzgx_offset_0, (u32)lbl_1_data_2A9F8__fzgx_offset_0, (u32)lbl_1_data_2AA04__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2AA14__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0,
    0x0, 0x837E8385, 0x815B8367, 0x20835683, 0x65834200, 0x837C815B, 0x83672083, 0x5E834583,  /* fzgx-allow: A1 retail data bytes */
    0x93000000, 0x83728362, 0x834F2083, 0x75838B81, 0x5B000000, 0x83898343, 0x8367836A, 0x8393834F,
    0x0, 0x83548393, 0x83682083, 0x49815B83, 0x56838383, 0x93000000, 0x834F838A, 0x815B8393,  /* fzgx-allow: A1 retail data bytes */
    0x20837683, 0x89839383, 0x67000000, 0x83748340, 0x83438341, 0x20837483, 0x42815B83, 0x8B836800,
    0x834A8357, 0x836D2083, 0x70838C83, 0x58000000, 0x83418345, 0x835E815B, 0x20835883, 0x79815B83,
    0x58000000, 0x83478341, 0x838D837C, 0x838A8358, 0x0, 0x83528358, 0x83822083, 0x5E815B83,
    0x7E836983, 0x8B000000, 0x83748340, 0x83938367, 0x83802083, 0x8D815B83, 0x68000000, (u32)lbl_1_data_2A980__fzgx_offset_0,
    (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0,
    (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AAD0__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAF8__fzgx_offset_0, (u32)lbl_1_data_2AB08__fzgx_offset_0, (u32)lbl_1_data_2AB1C__fzgx_offset_0, (u32)lbl_1_data_2AB2C__fzgx_offset_0,
    (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AB40__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2ABAC[198] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0,
    (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0,
    (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0,
    (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0,
    (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0,
    (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0,
    (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0,
    (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0,
    (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0,
    (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_DC204__fzgx_offset_0, (u32)fn_1_DC208__fzgx_offset_0, (u32)fn_1_DC264__fzgx_offset_0, (u32)fn_1_DC268__fzgx_offset_0, (u32)fn_1_DC2F8__fzgx_offset_0, (u32)fn_1_DC33C__fzgx_offset_0,
    (u32)fn_1_DC3A0__fzgx_offset_0, (u32)fn_1_DCB9C__fzgx_offset_0, (u32)fn_1_DCBF4__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0,
    (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0,
    (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_FA6C0__fzgx_offset_0, (u32)fn_1_FA75C__fzgx_offset_0, (u32)fn_1_FA82C__fzgx_offset_0,
    (u32)fn_1_FA830__fzgx_offset_0, (u32)fn_1_FA854__fzgx_offset_0, (u32)fn_1_FA878__fzgx_offset_0, (u32)fn_1_FA898__fzgx_offset_0, (u32)fn_1_FB770__fzgx_offset_0, (u32)fn_1_FB798__fzgx_offset_0, (u32)fn_1_FE5E0__fzgx_offset_0, (u32)fn_1_FE5E4__fzgx_offset_0,
    (u32)fn_1_FE640__fzgx_offset_0, (u32)fn_1_FE644__fzgx_offset_0, (u32)fn_1_FE780__fzgx_offset_0, (u32)fn_1_FE784__fzgx_offset_0, (u32)fn_1_FE7D4__fzgx_offset_0, (u32)fn_1_101348__fzgx_offset_0, (u32)fn_1_1013A0__fzgx_offset_0, (u32)fn_1_153988__fzgx_offset_0,
    (u32)fn_1_15398C__fzgx_offset_0, (u32)fn_1_1539D0__fzgx_offset_0, (u32)fn_1_153A28__fzgx_offset_0, (u32)fn_1_153AAC__fzgx_offset_0, (u32)fn_1_153AB0__fzgx_offset_0, (u32)fn_1_153AF4__fzgx_offset_0, (u32)fn_1_1543E8__fzgx_offset_0, (u32)fn_1_154410__fzgx_offset_0,
    (u32)fn_1_150500__fzgx_offset_0, (u32)fn_1_150518__fzgx_offset_0, (u32)fn_1_150570__fzgx_offset_0, (u32)fn_1_1505B4__fzgx_offset_0, (u32)fn_1_150574__fzgx_offset_0, (u32)fn_1_150608__fzgx_offset_0, (u32)fn_1_150650__fzgx_offset_0, (u32)fn_1_151764__fzgx_offset_0,
    (u32)fn_1_15176C__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0,
    (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1586A8__fzgx_offset_0, (u32)fn_1_1586AC__fzgx_offset_0, (u32)fn_1_158980__fzgx_offset_0, (u32)fn_1_158984__fzgx_offset_0, (u32)fn_1_15903C__fzgx_offset_0,
    (u32)fn_1_159040__fzgx_offset_0, (u32)fn_1_159060__fzgx_offset_0, (u32)fn_1_159064__fzgx_offset_0, (u32)fn_1_15906C__fzgx_offset_0, (u32)fn_1_15B428__fzgx_offset_0, (u32)fn_1_15B42C__fzgx_offset_0, (u32)fn_1_15B4F8__fzgx_offset_0, (u32)fn_1_15B4FC__fzgx_offset_0,
    (u32)fn_1_15B51C__fzgx_offset_0, (u32)fn_1_15B520__fzgx_offset_0, (u32)fn_1_15B540__fzgx_offset_0, (u32)fn_1_15B698__fzgx_offset_0, (u32)fn_1_15B70C__fzgx_offset_0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2AEC4[1667] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x62675F6D, 0x75740000, 0x62675F70, 0x6F720000, 0x62675F70, 0x6F725F73, 0x0, 0x62675F62,
    0x69670000, 0x62675F62, 0x69675F73, 0x0, 0x62675F6C, 0x69670000, 0x62675F73, 0x616E0000,
    0x62675F73, 0x616E5F73, 0x0, 0x62675F66, 0x6F720000, 0x62675F66, 0x69720000, 0x62675F66,
    0x69725F73, 0x0, 0x62675F63, 0x61730000, 0x62675F6D, 0x65740000, 0x62675F74, 0x6F770000,
    0x62675F65, 0x6C650000, 0x62675F63, 0x6F6D0000, 0x62675F63, 0x6F6D5F73, 0x0, 0x62675F72,
    0x61690000, 0x62675F77, 0x696E5F67, 0x78000000, 0x0, (u32)lbl_1_data_2AEC4__fzgx_offset_0, (u32)lbl_1_data_2AECC__fzgx_offset_0, (u32)lbl_1_data_2AED4__fzgx_offset_0,
    (u32)lbl_1_data_2AEE0__fzgx_offset_0, (u32)lbl_1_data_2AEE8__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEFC__fzgx_offset_0, (u32)lbl_1_data_2AF04__fzgx_offset_0, (u32)lbl_1_data_2AF10__fzgx_offset_0, (u32)lbl_1_data_2AF18__fzgx_offset_0,
    (u32)lbl_1_data_2AF20__fzgx_offset_0, (u32)lbl_1_data_2AF2C__fzgx_offset_0, (u32)lbl_1_data_2AF34__fzgx_offset_0, (u32)lbl_1_data_2AF3C__fzgx_offset_0, (u32)lbl_1_data_2AF44__fzgx_offset_0, (u32)lbl_1_data_2AF4C__fzgx_offset_0, (u32)lbl_1_data_2AF54__fzgx_offset_0, (u32)lbl_1_data_2AF60__fzgx_offset_0,
    (u32)lbl_1_data_2AF68__fzgx_offset_0, 0x0, 0x0, 0x4, 0x202C0, 0x202C0, 0x18B0, 0x18B0,
    0xFD80, 0xFD80, 0x1C60, 0x1C60, 0x226C, 0x764, 0x764, 0x174,
    0x1B1E8, 0x1704, 0x2748, 0x4, 0x4, 0x157CC, 0x128, 0x0,
    0x0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0,
    (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A35C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A484__fzgx_offset_0, (u32)lbl_1_data_2A4E8__fzgx_offset_0, (u32)lbl_1_data_2A5DC__fzgx_offset_0,
    (u32)lbl_1_data_2A528__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A664__fzgx_offset_0, (u32)lbl_1_data_2A6C0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2A31C__fzgx_offset_0,
    (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0,
    (u32)lbl_1_data_2A384__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A49C__fzgx_offset_0, (u32)lbl_1_data_2A518__fzgx_offset_0, (u32)lbl_1_data_2A62C__fzgx_offset_0, (u32)lbl_1_data_2A580__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0,
    (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A674__fzgx_offset_0, (u32)lbl_1_data_2A774__fzgx_offset_0, 0x0, 0x8010101, 0x10F0202, 0x6060A0A, 0x602040B,
    0xD0B0B0E, 0xE0F1006, 0x10080804, 0x130D080F, 0xE02060A, 0x1112090D, 0x5070301, 0xC130000,
    0x141400, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x10202, 0x3030404, 0x5050607, 0x708090A, 0xB0C0C0D, 0x1000000, 0x2D2D2D00, 0x54776973,
    0x7420526F, 0x61640000, 0x53657269, 0x616C2047, 0x61707300, 0x4D756C74, 0x69706C65, 0x78000000,
    0x4165726F, 0x20446976, 0x65000000, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x48616C66, 0x20506970,
    0x65000000, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x4D6F6269, 0x75732052, 0x696E6700,
    0x4C6F6E67, 0x20506970, 0x65000000, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x43796C69,
    0x6E646572, 0x204B6E6F, 0x74000000, 0x53706C69, 0x74204F76, 0x616C0000, 0x556E6475, 0x6C617469,
    0x6F6E0000, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x54726964, 0x656E7400, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x4F726465,
    0x616C0000, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x446F7562, 0x6C652042, 0x72616E63,
    0x68657300, 0x53637265, 0x77204472, 0x69766500, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000,
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x5468756E, 0x64657220, 0x526F6164, 0x0,
    0x53706972, 0x616C0000, 0x536F6E69, 0x63204F76, 0x616C0000, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B1A8__fzgx_offset_0,
    (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B230__fzgx_offset_0,
    (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2B294__fzgx_offset_0,
    (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, 0x96A292E8, 0x0, 0x47455220, 0x54776973,
    0x7420526F, 0x61640000, 0x46524520, 0x54776973, 0x7420526F, 0x61640000, 0x53504120, 0x54776973,
    0x7420526F, 0x61640000, 0x49544120, 0x54776973, 0x7420526F, 0x61640000, 0x83638343, 0x83588367,
    0x838D815B, 0x83680000, 0x47455220, 0x53657269, 0x616C2047, 0x61707300, 0x46524520, 0x53657269,
    0x616C2047, 0x61707300, 0x53504120, 0x53657269, 0x616C2047, 0x61707300, 0x49544120, 0x53657269,
    0x616C2047, 0x61707300, 0x8356838A, 0x8341838B, 0x834D8383, 0x83628376, 0x0, 0x47455220,
    0x4D756C74, 0x69706C65, 0x78000000, 0x46524520, 0x4D756C74, 0x69706C65, 0x78000000, 0x53504120,
    0x4D756C74, 0x69706C65, 0x78000000, 0x49544120, 0x4D756C74, 0x69706C65, 0x78000000, 0x837D838B,
    0x83608376, 0x838C8362, 0x834E8358, 0x0, 0x47455220, 0x4165726F, 0x20446976, 0x65000000,
    0x46524520, 0x4165726F, 0x20446976, 0x65000000, 0x53504120, 0x4165726F, 0x20446976, 0x65000000,
    0x49544120, 0x4165726F, 0x20446976, 0x65000000, 0x83478341, 0x838D835F, 0x83438375, 0x0,
    0x47455220, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x46524520, 0x4C6F6F70, 0x2043726F, 0x73730000,
    0x53504120, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x49544120, 0x4C6F6F70, 0x2043726F, 0x73730000,
    0x838B815B, 0x8376834E, 0x838D8358, 0x0, 0x47455220, 0x48616C66, 0x20506970, 0x65000000,
    0x46524520, 0x48616C66, 0x20506970, 0x65000000, 0x53504120, 0x48616C66, 0x20506970, 0x65000000,
    0x49544120, 0x48616C66, 0x20506970, 0x65000000, 0x836E815B, 0x83748370, 0x83438376, 0x0,
    0x47455220, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x46524520, 0x496E7465, 0x72736563,
    0x74696F6E, 0x0, 0x53504120, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x49544120,
    0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x83438393, 0x835E815B, 0x835A834E, 0x83568387,
    0x83930000, 0x47455220, 0x4D6F6269, 0x75732052, 0x696E6700, 0x46524520, 0x4D6F6269, 0x75732052,
    0x696E6700, 0x53504120, 0x4D6F6269, 0x75732052, 0x696E6700, 0x49544120, 0x4D6F6269, 0x75732052,
    0x696E6700, 0x83818372, 0x83458358, 0x838A8393, 0x834F0000, 0x47455220, 0x4C6F6E67, 0x20506970,
    0x65000000, 0x46524520, 0x4C6F6E67, 0x20506970, 0x65000000, 0x53504120, 0x4C6F6E67, 0x20506970,
    0x65000000, 0x49544120, 0x4C6F6E67, 0x20506970, 0x65000000, 0x838D8393, 0x834F8370, 0x83438376,
    0x0, 0x47455220, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x46524520, 0x44726966,
    0x74204869, 0x67687761, 0x79000000, 0x53504120, 0x44726966, 0x74204869, 0x67687761, 0x79000000,
    0x49544120, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x8368838A, 0x83748367, 0x836E8343,
    0x83458346, 0x83430000, 0x47455220, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x46524520,
    0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x53504120, 0x43796C69, 0x6E646572, 0x204B6E6F,
    0x74000000, 0x49544120, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x8356838A, 0x8393835F,
    0x815B836D, 0x83628367, 0x0, 0x47455220, 0x53706C69, 0x74204F76, 0x616C0000, 0x46524520,  /* fzgx-allow: A1 retail data bytes */
    0x53706C69, 0x74204F76, 0x616C0000, 0x53504120, 0x53706C69, 0x74204F76, 0x616C0000, 0x49544120,
    0x53706C69, 0x74206F76, 0x616C0000, 0x83588376, 0x838A8362, 0x83678349, 0x815B836F, 0x838B0000,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x46524520, 0x556E6475, 0x6C617469, 0x6F6E0000,
    0x53504120, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x49544120, 0x556E6475, 0x6C617469, 0x6F6E0000,
    0x83418393, 0x83668385, 0x838C815B, 0x83568387, 0x83930000, 0x47455220, 0x44726167, 0x6F6E2053,
    0x6C6F7065, 0x0, 0x46524520, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x53504120,
    0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x49544120, 0x44726167, 0x6F6E2053, 0x6C6F7065,
    0x0, 0x83688389, 0x83538393, 0x8358838D, 0x815B8376, 0x0, 0x47455220, 0x54726964,  /* fzgx-allow: A1 retail data bytes */
    0x656E7400, 0x46524520, 0x54726964, 0x656E7400, 0x53504120, 0x54726964, 0x656E7400, 0x49544120,
    0x54726964, 0x656E7400, 0x83678389, 0x83438366, 0x83938367, 0x0, 0x47455220, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x46524520, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000,
    0x53504120, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x49544120, 0x4C617465, 0x72616C20,
    0x53686966, 0x74000000, 0x83898365, 0x8389838B, 0x83568374, 0x83670000, 0x47455220, 0x53757266,
    0x61636520, 0x536C6964, 0x65000000, 0x46524520, 0x53757266, 0x61636520, 0x536C6964, 0x65000000,
    0x53504120, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x49544120, 0x53757266, 0x61636520,
    0x536C6964, 0x65000000, 0x8354815B, 0x83748346, 0x83588358, 0x83898343, 0x83680000, 0x47455220,
    0x4F726465, 0x616C0000, 0x46524520, 0x4F726465, 0x616C0000, 0x53504120, 0x4F726465, 0x616C0000,
    0x49544120, 0x4F726465, 0x616C0000, 0x8349815B, 0x83668342, 0x815B838B, 0x0, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x46524520, 0x536C696D, 0x2D6C696E, 0x6520536C,
    0x69747300, 0x53504120, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x49544120, 0x536C696D,
    0x2D6C696E, 0x6520536C, 0x69747300, 0x8358838A, 0x83808389, 0x83438393, 0x8358838A, 0x83628367,
    0x0, 0x47455220, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x46524520, 0x446F7562,
    0x6C652042, 0x72616E63, 0x68657300, 0x53504120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300,
    0x49544120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x835F8375, 0x838B8375, 0x83898393,
    0x83600000, 0x47455220, 0x53637265, 0x77204472, 0x69766500, 0x46524520, 0x53637265, 0x77204472,
    0x69766500, 0x53504120, 0x53637265, 0x77204472, 0x69766500, 0x49544120, 0x53637265, 0x77204472,
    0x69766500, 0x8358834E, 0x838A8385, 0x815B8368, 0x83898343, 0x83750000, 0x47455220, 0x4D657465,  /* fzgx-allow: A1 retail data bytes */
    0x6F722053, 0x74726561, 0x6D000000, 0x46524520, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000,
    0x53504120, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000, 0x49544120, 0x4D657465, 0x6F722053,
    0x74726561, 0x6D000000, 0x83818365, 0x83498358, 0x8367838A, 0x815B8380, 0x0, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x46524520, 0x43796C69, 0x6E646572, 0x20576176,
    0x65000000, 0x53504120, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x49544120, 0x43796C69,
    0x6E646572, 0x20576176, 0x65000000, 0x8356838A, 0x8393835F, 0x815B8345, 0x8346815B, 0x83750000,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x46524520, 0x5468756E, 0x64657220,
    0x526F6164, 0x0, 0x53504120, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x49544120,
    0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x83548393, 0x835F815B, 0x838D815B, 0x83680000,
    0x47455220, 0x53706972, 0x616C0000, 0x46524520, 0x53706972, 0x616C0000, 0x53504120, 0x53706972,
    0x616C0000, 0x49544120, 0x53706972, 0x616C0000, 0x83588370, 0x83438389, 0x838B0000, 0x47455220,
    0x536F6E69, 0x63204F76, 0x616C0000, 0x46524520, 0x536F6E69, 0x63204F76, 0x616C0000, 0x53504120,
    0x536F6E69, 0x63204F76, 0x616C0000, 0x49544120, 0x536F6E69, 0x63204F76, 0x616C0000, 0x835C836A,
    0x8362834E, 0x8349815B, 0x836F838B, 0x0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B47C__fzgx_offset_0, (u32)lbl_1_data_2B48C__fzgx_offset_0, (u32)lbl_1_data_2B49C__fzgx_offset_0, (u32)lbl_1_data_2B4AC__fzgx_offset_0, (u32)lbl_1_data_2B4BC__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B4CC__fzgx_offset_0,
    (u32)lbl_1_data_2B4DC__fzgx_offset_0, (u32)lbl_1_data_2B4EC__fzgx_offset_0, (u32)lbl_1_data_2B4FC__fzgx_offset_0, (u32)lbl_1_data_2B50C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B520__fzgx_offset_0, (u32)lbl_1_data_2B530__fzgx_offset_0, (u32)lbl_1_data_2B540__fzgx_offset_0, (u32)lbl_1_data_2B550__fzgx_offset_0, (u32)lbl_1_data_2B560__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B574__fzgx_offset_0,
    (u32)lbl_1_data_2B584__fzgx_offset_0, (u32)lbl_1_data_2B594__fzgx_offset_0, (u32)lbl_1_data_2B5A4__fzgx_offset_0, (u32)lbl_1_data_2B5B4__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B5C4__fzgx_offset_0, (u32)lbl_1_data_2B5D4__fzgx_offset_0, (u32)lbl_1_data_2B5E4__fzgx_offset_0,
    (u32)lbl_1_data_2B5F4__fzgx_offset_0, (u32)lbl_1_data_2B604__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B614__fzgx_offset_0, (u32)lbl_1_data_2B624__fzgx_offset_0, (u32)lbl_1_data_2B634__fzgx_offset_0, (u32)lbl_1_data_2B644__fzgx_offset_0, (u32)lbl_1_data_2B654__fzgx_offset_0,
    (u32)lbl_1_data_2B1A8__fzgx_offset_0, (u32)lbl_1_data_2B664__fzgx_offset_0, (u32)lbl_1_data_2B678__fzgx_offset_0, (u32)lbl_1_data_2B68C__fzgx_offset_0, (u32)lbl_1_data_2B6A0__fzgx_offset_0, (u32)lbl_1_data_2B6B4__fzgx_offset_0, (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B6C8__fzgx_offset_0,
    (u32)lbl_1_data_2B6D8__fzgx_offset_0, (u32)lbl_1_data_2B6E8__fzgx_offset_0, (u32)lbl_1_data_2B6F8__fzgx_offset_0, (u32)lbl_1_data_2B708__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B718__fzgx_offset_0, (u32)lbl_1_data_2B728__fzgx_offset_0, (u32)lbl_1_data_2B738__fzgx_offset_0, (u32)lbl_1_data_2B748__fzgx_offset_0, (u32)lbl_1_data_2B758__fzgx_offset_0,
    (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B768__fzgx_offset_0, (u32)lbl_1_data_2B77C__fzgx_offset_0, (u32)lbl_1_data_2B790__fzgx_offset_0, (u32)lbl_1_data_2B7A4__fzgx_offset_0, (u32)lbl_1_data_2B7B8__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B7CC__fzgx_offset_0,
    (u32)lbl_1_data_2B7E0__fzgx_offset_0, (u32)lbl_1_data_2B7F4__fzgx_offset_0, (u32)lbl_1_data_2B808__fzgx_offset_0, (u32)lbl_1_data_2B81C__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B830__fzgx_offset_0, (u32)lbl_1_data_2B840__fzgx_offset_0, (u32)lbl_1_data_2B850__fzgx_offset_0,
    (u32)lbl_1_data_2B860__fzgx_offset_0, (u32)lbl_1_data_2B870__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B884__fzgx_offset_0, (u32)lbl_1_data_2B894__fzgx_offset_0, (u32)lbl_1_data_2B8A4__fzgx_offset_0, (u32)lbl_1_data_2B8B4__fzgx_offset_0, (u32)lbl_1_data_2B8C4__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B8D8__fzgx_offset_0, (u32)lbl_1_data_2B8EC__fzgx_offset_0, (u32)lbl_1_data_2B900__fzgx_offset_0, (u32)lbl_1_data_2B914__fzgx_offset_0, (u32)lbl_1_data_2B928__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B93C__fzgx_offset_0, (u32)lbl_1_data_2B948__fzgx_offset_0, (u32)lbl_1_data_2B954__fzgx_offset_0,
    (u32)lbl_1_data_2B960__fzgx_offset_0, (u32)lbl_1_data_2B96C__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B97C__fzgx_offset_0, (u32)lbl_1_data_2B990__fzgx_offset_0, (u32)lbl_1_data_2B9A4__fzgx_offset_0, (u32)lbl_1_data_2B9B8__fzgx_offset_0, (u32)lbl_1_data_2B9CC__fzgx_offset_0,
    (u32)lbl_1_data_2B230__fzgx_offset_0, (u32)lbl_1_data_2B9DC__fzgx_offset_0, (u32)lbl_1_data_2B9F0__fzgx_offset_0, (u32)lbl_1_data_2BA04__fzgx_offset_0, (u32)lbl_1_data_2BA18__fzgx_offset_0, (u32)lbl_1_data_2BA2C__fzgx_offset_0, (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2BA40__fzgx_offset_0,
    (u32)lbl_1_data_2BA4C__fzgx_offset_0, (u32)lbl_1_data_2BA58__fzgx_offset_0, (u32)lbl_1_data_2BA64__fzgx_offset_0, (u32)lbl_1_data_2BA70__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2BA80__fzgx_offset_0, (u32)lbl_1_data_2BA94__fzgx_offset_0, (u32)lbl_1_data_2BAA8__fzgx_offset_0,
    (u32)lbl_1_data_2BABC__fzgx_offset_0, (u32)lbl_1_data_2BAD0__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2BAE8__fzgx_offset_0, (u32)lbl_1_data_2BAFC__fzgx_offset_0, (u32)lbl_1_data_2BB10__fzgx_offset_0, (u32)lbl_1_data_2BB24__fzgx_offset_0, (u32)lbl_1_data_2BB38__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2BB48__fzgx_offset_0,
    (u32)lbl_1_data_2BB58__fzgx_offset_0, (u32)lbl_1_data_2BB68__fzgx_offset_0, (u32)lbl_1_data_2BB78__fzgx_offset_0, (u32)lbl_1_data_2BB88__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2BB9C__fzgx_offset_0, (u32)lbl_1_data_2BBB0__fzgx_offset_0, (u32)lbl_1_data_2BBC4__fzgx_offset_0,
    (u32)lbl_1_data_2BBD8__fzgx_offset_0, (u32)lbl_1_data_2BBEC__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2BC00__fzgx_offset_0, (u32)lbl_1_data_2BC14__fzgx_offset_0, (u32)lbl_1_data_2BC28__fzgx_offset_0, (u32)lbl_1_data_2BC3C__fzgx_offset_0, (u32)lbl_1_data_2BC50__fzgx_offset_0,
    (u32)lbl_1_data_2B294__fzgx_offset_0, (u32)lbl_1_data_2BC64__fzgx_offset_0, (u32)lbl_1_data_2BC78__fzgx_offset_0, (u32)lbl_1_data_2BC8C__fzgx_offset_0, (u32)lbl_1_data_2BCA0__fzgx_offset_0, (u32)lbl_1_data_2BCB4__fzgx_offset_0, (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2BCC4__fzgx_offset_0,
    (u32)lbl_1_data_2BCD0__fzgx_offset_0, (u32)lbl_1_data_2BCDC__fzgx_offset_0, (u32)lbl_1_data_2BCE8__fzgx_offset_0, (u32)lbl_1_data_2BCF4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0,
    (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0, (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, 0x1020304, 0x10203,
    0x4050607, 0x8090A0B, 0xC0D0E0F, 0x10111213, 0x14151617, 0x18191A1B, 0x1C1D1E1F, 0x20212223,
    0x10200, 0x10203, 0x4050600, 0x10203, 0x4050607, 0x42494746, 0x49534830, 0x31000000,
    0x574F524D, 0x0, 0x4B494E47, 0x5F434F42, 0x52410000, 0x53414E44, 0x5F464953, 0x48000000,
    0x53414E44, 0x5F424952, 0x44000000, (u32)lbl_1_data_2C7F8__fzgx_offset_0, 0x3, (u32)lbl_1_data_2C7BC__fzgx_offset_0, (u32)lbl_1_data_2C804__fzgx_offset_0, 0x9,
    (u32)lbl_1_data_2C7C0__fzgx_offset_0, (u32)lbl_1_data_2C80C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2C7E4__fzgx_offset_0, (u32)lbl_1_data_2C818__fzgx_offset_0, 0x1, (u32)lbl_1_data_2C7E8__fzgx_offset_0, (u32)lbl_1_data_2C824__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2C7F0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x44610000, 0x102,
    0x1, (u32)lbl_1_data_2C870__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43C80000, 0x102,
    0x1, (u32)lbl_1_data_2C890__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43480000, 0x102,
    0x1, (u32)lbl_1_data_2C8B0__fzgx_offset_0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2C8D0[164] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x447A0000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43FA0000,
    0x3, 0x2, (u32)lbl_1_data_2C8D0__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43960000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43C80000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x42C80000, 0x43480000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x447A0000, 0x44BB8000,
    0x0, 0x1, 0x43960000, 0x44160000, 0x1, 0x1, 0x43FA0000, 0x447A0000,
    0x1, 0x1, 0x43480000, 0x43C80000, 0x1, 0x1, 0x43480000, 0x43C80000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43FA0000, 0x442F0000,
    0x1, 0x1, 0x43C80000, 0x44480000, 0x0, 0x1, 0x44BB8000, 0x451C4000,
    0x0, 0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1, 0x447A0000, 0x44BB8000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x42C80000, 0x43480000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x43FA0000, 0x447A0000, 0x0, 0x1, 0x43480000, 0x43C80000,
    0x0, 0x1, 0x43FA0000, 0x447A0000, 0x1, 0x1, 0x447A0000, 0x44BB8000,
    0x0, 0x1, 0x42C80000, 0x43480000, 0x1, 0x1, 0x42C80000, 0x43960000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43FA0000,
    0x1, 0x1, 0x43FA0000, 0x447A0000, 0x0, 0x1, 0x451C4000, 0x453B8000,
    0x1, 0x1, 0x43960000, 0x44160000, 0x1, 0x1, 0x43480000, 0x43960000,
    0x0, 0x1, 0x447A0000, 0x44FA0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_2A0C0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A0C0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A7E0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A8D8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2ABAC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2AEC4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2C8D0;
}
#pragma section code_type ".text"

void fn_1_9A7BC(void) {
    Fn9A7BCB *b;
    Fn9A7BCA *a = (Fn9A7BCA *)((u32)((u8 *)fzgx_pool_data_lbl_1_data_2A7E0));
    Fn9A7BCC *c;
    f32 y, x;
    s32 v;
    if (Fn9A7BC_flag(a) != 0) {
        v = 4;
    } else {
        v = fn_1_58C4();
    }
    b = (Fn9A7BCB *)((u32)((u8 *)fzgx_pool_data_lbl_1_data_2C8D0));
    {
        Fn9A7BCA *src = (Fn9A7BCA *)((u32)((u8 *)fzgx_pool_data_lbl_1_data_2A7E0));
        x = src->unk_98;
        y = src->unk_94;
        src->unk_88 = v;
        b->unk_c = x;
        b->unk_1c = y;
    }
    fn_1_103058();
    if (((Fn9A7BCA *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0)))->idx > 0 && (fn_1_9D260(), (s32)fn_1_9D230() == 0)) {
        c = (Fn9A7BCC *)(((u8 *)fzgx_pool_data_lbl_1_data_2ABAC));
        c += ((Fn9A7BCA *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0)))->idx;
        c->fn();
    } else {
        fn_1_9AD88();
    }
}
/* fzgx:end fn_1_9A7BC */

/* fzgx:begin fn_1_9A864 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"
#include "types.h"

/* begin game/main_rel/burner_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

// Types (and the externs that name them) of burner.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct Node {
    struct Node *prev;
    struct Node *next;
} Node;

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

struct fn_1_98804_Arg0 {
    u32 unk_0;
    u32 unk_4;
};

typedef struct {
    u8 pad[8];
    u8 *entries;
} fn_1_9D360_BurnerTable;

extern void fn_1_98840(Node *node);
extern void *fn_1_5448C(fn_1_98E18_Vec *pos);
extern void fn_8006E294(fn_1_9CCE8_Vec3 *);
extern void fn_80077F8C(Burner *);
extern const struct FormatTable lbl_1_rodata_7050;
extern const struct EntryTable lbl_1_rodata_6E38;
extern void fn_1_98804(struct fn_1_98804_Arg0 *arg0);
extern void fn_1_9D360(Burner *burner, fn_1_9D360_BurnerTable *table, u8 *indices);

#endif  // GAME_MAIN_REL_BURNER_TYPES_H

/* end game/main_rel/burner_types.h */

extern void fn_1_98640(Obj_1_data_27DE0 *obj);
extern void fn_1_987D0(u32 address);
extern s16 camera_get_mode(void);
extern u32 fn_1_58C4(void);
extern void *memset(void *dest, int value, u32 size);
extern void fn_1_8645C(int index, void *arg);
extern void lbl_8006E1B0(void *, void *);
extern s16 fn_1_58E3C(void *source);
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
extern void fn_1_98F28(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern int sprintf(char *s, const char *format, ...);
extern s32 fn_1_46DC4(s32 value);
extern u32 fn_80077A18();
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern char *fn_80083DB0(char *, const char *);
extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern f32 lbl_1_rodata_4104[59];
extern void * fn_1_986A4();
extern void fn_800794F0(u8 *dst, u8 *src, s32 len);
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void lbl_8006D7B0(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s32);
extern size_t strlen(const char *str);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 fn_8006FC1C(const char *, const char *);
extern u32 fn_1_9D260(void);
extern s16 fn_1_3F0C8(void);
extern u8 lbl_1_bss_8E51D;
extern u8 fn_1_7B074(void);
extern s32 fn_8006FDEC(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);
extern void * fn_1_12F118(void);
extern u8* fn_1_36AD0(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern const f32 lbl_1_rodata_4100;
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
extern s32 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_91BC;
extern void fn_1_4E724(void *);
extern void fn_1_103054(void);
extern void fn_1_9D2EC(void);
extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
extern u8 lbl_1_data_2B15C__fzgx_offset_0[];
extern u8 lbl_1_data_2B160__fzgx_offset_0[];
extern u8 lbl_1_data_2B16C__fzgx_offset_0[];
extern u8 lbl_1_data_2B178__fzgx_offset_0[];
extern u8 lbl_1_data_2B184__fzgx_offset_0[];
extern u8 lbl_1_data_2B190__fzgx_offset_0[];
extern u8 lbl_1_data_2B19C__fzgx_offset_0[];
extern u8 lbl_1_data_2B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B1D0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1F0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B208__fzgx_offset_0[];
extern u8 lbl_1_data_2B218__fzgx_offset_0[];
extern u8 lbl_1_data_2B220__fzgx_offset_0[];
extern u8 lbl_1_data_2B230__fzgx_offset_0[];
extern u8 lbl_1_data_2B240__fzgx_offset_0[];
extern u8 lbl_1_data_2B248__fzgx_offset_0[];
extern u8 lbl_1_data_2B258__fzgx_offset_0[];
extern u8 lbl_1_data_2B268__fzgx_offset_0[];
extern u8 lbl_1_data_2B274__fzgx_offset_0[];
extern u8 lbl_1_data_2B284__fzgx_offset_0[];
extern u8 lbl_1_data_2B294__fzgx_offset_0[];
extern u8 lbl_1_data_2B2A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B474__fzgx_offset_0[];
extern u8 lbl_1_data_2B47C__fzgx_offset_0[];
extern u8 lbl_1_data_2B48C__fzgx_offset_0[];
extern u8 lbl_1_data_2B49C__fzgx_offset_0[];
extern u8 lbl_1_data_2B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4BC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B50C__fzgx_offset_0[];
extern u8 lbl_1_data_2B520__fzgx_offset_0[];
extern u8 lbl_1_data_2B530__fzgx_offset_0[];
extern u8 lbl_1_data_2B540__fzgx_offset_0[];
extern u8 lbl_1_data_2B550__fzgx_offset_0[];
extern u8 lbl_1_data_2B560__fzgx_offset_0[];
extern u8 lbl_1_data_2B574__fzgx_offset_0[];
extern u8 lbl_1_data_2B584__fzgx_offset_0[];
extern u8 lbl_1_data_2B594__fzgx_offset_0[];
extern u8 lbl_1_data_2B5A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5D4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5E4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B604__fzgx_offset_0[];
extern u8 lbl_1_data_2B614__fzgx_offset_0[];
extern u8 lbl_1_data_2B624__fzgx_offset_0[];
extern u8 lbl_1_data_2B634__fzgx_offset_0[];
extern u8 lbl_1_data_2B644__fzgx_offset_0[];
extern u8 lbl_1_data_2B654__fzgx_offset_0[];
extern u8 lbl_1_data_2B664__fzgx_offset_0[];
extern u8 lbl_1_data_2B678__fzgx_offset_0[];
extern u8 lbl_1_data_2B68C__fzgx_offset_0[];
extern u8 lbl_1_data_2B6A0__fzgx_offset_0[];
extern u8 lbl_1_data_2B6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6E8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2B708__fzgx_offset_0[];
extern u8 lbl_1_data_2B718__fzgx_offset_0[];
extern u8 lbl_1_data_2B728__fzgx_offset_0[];
extern u8 lbl_1_data_2B738__fzgx_offset_0[];
extern u8 lbl_1_data_2B748__fzgx_offset_0[];
extern u8 lbl_1_data_2B758__fzgx_offset_0[];
extern u8 lbl_1_data_2B768__fzgx_offset_0[];
extern u8 lbl_1_data_2B77C__fzgx_offset_0[];
extern u8 lbl_1_data_2B790__fzgx_offset_0[];
extern u8 lbl_1_data_2B7A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B7B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B7CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B7E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B7F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B808__fzgx_offset_0[];
extern u8 lbl_1_data_2B81C__fzgx_offset_0[];
extern u8 lbl_1_data_2B830__fzgx_offset_0[];
extern u8 lbl_1_data_2B840__fzgx_offset_0[];
extern u8 lbl_1_data_2B850__fzgx_offset_0[];
extern u8 lbl_1_data_2B860__fzgx_offset_0[];
extern u8 lbl_1_data_2B870__fzgx_offset_0[];
extern u8 lbl_1_data_2B884__fzgx_offset_0[];
extern u8 lbl_1_data_2B894__fzgx_offset_0[];
extern u8 lbl_1_data_2B8A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B8EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B900__fzgx_offset_0[];
extern u8 lbl_1_data_2B914__fzgx_offset_0[];
extern u8 lbl_1_data_2B928__fzgx_offset_0[];
extern u8 lbl_1_data_2B93C__fzgx_offset_0[];
extern u8 lbl_1_data_2B948__fzgx_offset_0[];
extern u8 lbl_1_data_2B954__fzgx_offset_0[];
extern u8 lbl_1_data_2B960__fzgx_offset_0[];
extern u8 lbl_1_data_2B96C__fzgx_offset_0[];
extern u8 lbl_1_data_2B97C__fzgx_offset_0[];
extern u8 lbl_1_data_2B990__fzgx_offset_0[];
extern u8 lbl_1_data_2B9A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B9CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9F0__fzgx_offset_0[];
extern u8 lbl_1_data_2BA04__fzgx_offset_0[];
extern u8 lbl_1_data_2BA18__fzgx_offset_0[];
extern u8 lbl_1_data_2BA2C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA40__fzgx_offset_0[];
extern u8 lbl_1_data_2BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA58__fzgx_offset_0[];
extern u8 lbl_1_data_2BA64__fzgx_offset_0[];
extern u8 lbl_1_data_2BA70__fzgx_offset_0[];
extern u8 lbl_1_data_2BA80__fzgx_offset_0[];
extern u8 lbl_1_data_2BA94__fzgx_offset_0[];
extern u8 lbl_1_data_2BAA8__fzgx_offset_0[];
extern u8 lbl_1_data_2BABC__fzgx_offset_0[];
extern u8 lbl_1_data_2BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_2BB10__fzgx_offset_0[];
extern u8 lbl_1_data_2BB24__fzgx_offset_0[];
extern u8 lbl_1_data_2BB38__fzgx_offset_0[];
extern u8 lbl_1_data_2BB48__fzgx_offset_0[];
extern u8 lbl_1_data_2BB58__fzgx_offset_0[];
extern u8 lbl_1_data_2BB68__fzgx_offset_0[];
extern u8 lbl_1_data_2BB78__fzgx_offset_0[];
extern u8 lbl_1_data_2BB88__fzgx_offset_0[];
extern u8 lbl_1_data_2BB9C__fzgx_offset_0[];
extern u8 lbl_1_data_2BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_2BBC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BBD8__fzgx_offset_0[];
extern u8 lbl_1_data_2BBEC__fzgx_offset_0[];
extern u8 lbl_1_data_2BC00__fzgx_offset_0[];
extern u8 lbl_1_data_2BC14__fzgx_offset_0[];
extern u8 lbl_1_data_2BC28__fzgx_offset_0[];
extern u8 lbl_1_data_2BC3C__fzgx_offset_0[];
extern u8 lbl_1_data_2BC50__fzgx_offset_0[];
extern u8 lbl_1_data_2BC64__fzgx_offset_0[];
extern u8 lbl_1_data_2BC78__fzgx_offset_0[];
extern u8 lbl_1_data_2BC8C__fzgx_offset_0[];
extern u8 lbl_1_data_2BCA0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCB4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCDC__fzgx_offset_0[];
extern u8 lbl_1_data_2BCE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BCF4__fzgx_offset_0[];
extern u8 lbl_1_data_2BD00__fzgx_offset_0[];
extern u8 lbl_1_data_2BD10__fzgx_offset_0[];
extern u8 lbl_1_data_2BD20__fzgx_offset_0[];
extern u8 lbl_1_data_2BD30__fzgx_offset_0[];
extern u8 lbl_1_data_2BD40__fzgx_offset_0[];
extern u8 lbl_1_data_2C7BC__fzgx_offset_0[];
extern u8 lbl_1_data_2C7C0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E4__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E8__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F8__fzgx_offset_0[];
extern u8 lbl_1_data_2C804__fzgx_offset_0[];
extern u8 lbl_1_data_2C80C__fzgx_offset_0[];
extern u8 lbl_1_data_2C818__fzgx_offset_0[];
extern u8 lbl_1_data_2C824__fzgx_offset_0[];
extern u8 lbl_1_data_2C86C__fzgx_offset_0[];
extern u8 lbl_1_data_2C870__fzgx_offset_0[];
extern u8 lbl_1_data_2C890__fzgx_offset_0[];
extern u8 lbl_1_data_2C8B0__fzgx_offset_0[];
extern u8 lbl_1_data_2C8D0__fzgx_offset_0[];

/* game/main_rel/burner_types.h: inlined above */

extern u32 lbl_1_bss_384B4;
extern u32 lbl_1_bss_384B8;
extern void *lbl_801A6410;
extern void fn_1_103054(void);
extern void fn_1_9D2EC(void);
extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
extern u8 lbl_1_data_2B15C__fzgx_offset_0[];
extern u8 lbl_1_data_2B160__fzgx_offset_0[];
extern u8 lbl_1_data_2B16C__fzgx_offset_0[];
extern u8 lbl_1_data_2B178__fzgx_offset_0[];
extern u8 lbl_1_data_2B184__fzgx_offset_0[];
extern u8 lbl_1_data_2B190__fzgx_offset_0[];
extern u8 lbl_1_data_2B19C__fzgx_offset_0[];
extern u8 lbl_1_data_2B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B1D0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1F0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B208__fzgx_offset_0[];
extern u8 lbl_1_data_2B218__fzgx_offset_0[];
extern u8 lbl_1_data_2B220__fzgx_offset_0[];
extern u8 lbl_1_data_2B230__fzgx_offset_0[];
extern u8 lbl_1_data_2B240__fzgx_offset_0[];
extern u8 lbl_1_data_2B248__fzgx_offset_0[];
extern u8 lbl_1_data_2B258__fzgx_offset_0[];
extern u8 lbl_1_data_2B268__fzgx_offset_0[];
extern u8 lbl_1_data_2B274__fzgx_offset_0[];
extern u8 lbl_1_data_2B284__fzgx_offset_0[];
extern u8 lbl_1_data_2B294__fzgx_offset_0[];
extern u8 lbl_1_data_2B2A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B474__fzgx_offset_0[];
extern u8 lbl_1_data_2B47C__fzgx_offset_0[];
extern u8 lbl_1_data_2B48C__fzgx_offset_0[];
extern u8 lbl_1_data_2B49C__fzgx_offset_0[];
extern u8 lbl_1_data_2B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4BC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B50C__fzgx_offset_0[];
extern u8 lbl_1_data_2B520__fzgx_offset_0[];
extern u8 lbl_1_data_2B530__fzgx_offset_0[];
extern u8 lbl_1_data_2B540__fzgx_offset_0[];
extern u8 lbl_1_data_2B550__fzgx_offset_0[];
extern u8 lbl_1_data_2B560__fzgx_offset_0[];
extern u8 lbl_1_data_2B574__fzgx_offset_0[];
extern u8 lbl_1_data_2B584__fzgx_offset_0[];
extern u8 lbl_1_data_2B594__fzgx_offset_0[];
extern u8 lbl_1_data_2B5A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5D4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5E4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B604__fzgx_offset_0[];
extern u8 lbl_1_data_2B614__fzgx_offset_0[];
extern u8 lbl_1_data_2B624__fzgx_offset_0[];
extern u8 lbl_1_data_2B634__fzgx_offset_0[];
extern u8 lbl_1_data_2B644__fzgx_offset_0[];
extern u8 lbl_1_data_2B654__fzgx_offset_0[];
extern u8 lbl_1_data_2B664__fzgx_offset_0[];
extern u8 lbl_1_data_2B678__fzgx_offset_0[];
extern u8 lbl_1_data_2B68C__fzgx_offset_0[];
extern u8 lbl_1_data_2B6A0__fzgx_offset_0[];
extern u8 lbl_1_data_2B6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6E8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2B708__fzgx_offset_0[];
extern u8 lbl_1_data_2B718__fzgx_offset_0[];
extern u8 lbl_1_data_2B728__fzgx_offset_0[];
extern u8 lbl_1_data_2B738__fzgx_offset_0[];
extern u8 lbl_1_data_2B748__fzgx_offset_0[];
extern u8 lbl_1_data_2B758__fzgx_offset_0[];
extern u8 lbl_1_data_2B768__fzgx_offset_0[];
extern u8 lbl_1_data_2B77C__fzgx_offset_0[];
extern u8 lbl_1_data_2B790__fzgx_offset_0[];
extern u8 lbl_1_data_2B7A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B7B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B7CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B7E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B7F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B808__fzgx_offset_0[];
extern u8 lbl_1_data_2B81C__fzgx_offset_0[];
extern u8 lbl_1_data_2B830__fzgx_offset_0[];
extern u8 lbl_1_data_2B840__fzgx_offset_0[];
extern u8 lbl_1_data_2B850__fzgx_offset_0[];
extern u8 lbl_1_data_2B860__fzgx_offset_0[];
extern u8 lbl_1_data_2B870__fzgx_offset_0[];
extern u8 lbl_1_data_2B884__fzgx_offset_0[];
extern u8 lbl_1_data_2B894__fzgx_offset_0[];
extern u8 lbl_1_data_2B8A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B8EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B900__fzgx_offset_0[];
extern u8 lbl_1_data_2B914__fzgx_offset_0[];
extern u8 lbl_1_data_2B928__fzgx_offset_0[];
extern u8 lbl_1_data_2B93C__fzgx_offset_0[];
extern u8 lbl_1_data_2B948__fzgx_offset_0[];
extern u8 lbl_1_data_2B954__fzgx_offset_0[];
extern u8 lbl_1_data_2B960__fzgx_offset_0[];
extern u8 lbl_1_data_2B96C__fzgx_offset_0[];
extern u8 lbl_1_data_2B97C__fzgx_offset_0[];
extern u8 lbl_1_data_2B990__fzgx_offset_0[];
extern u8 lbl_1_data_2B9A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B9CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9F0__fzgx_offset_0[];
extern u8 lbl_1_data_2BA04__fzgx_offset_0[];
extern u8 lbl_1_data_2BA18__fzgx_offset_0[];
extern u8 lbl_1_data_2BA2C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA40__fzgx_offset_0[];
extern u8 lbl_1_data_2BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA58__fzgx_offset_0[];
extern u8 lbl_1_data_2BA64__fzgx_offset_0[];
extern u8 lbl_1_data_2BA70__fzgx_offset_0[];
extern u8 lbl_1_data_2BA80__fzgx_offset_0[];
extern u8 lbl_1_data_2BA94__fzgx_offset_0[];
extern u8 lbl_1_data_2BAA8__fzgx_offset_0[];
extern u8 lbl_1_data_2BABC__fzgx_offset_0[];
extern u8 lbl_1_data_2BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_2BB10__fzgx_offset_0[];
extern u8 lbl_1_data_2BB24__fzgx_offset_0[];
extern u8 lbl_1_data_2BB38__fzgx_offset_0[];
extern u8 lbl_1_data_2BB48__fzgx_offset_0[];
extern u8 lbl_1_data_2BB58__fzgx_offset_0[];
extern u8 lbl_1_data_2BB68__fzgx_offset_0[];
extern u8 lbl_1_data_2BB78__fzgx_offset_0[];
extern u8 lbl_1_data_2BB88__fzgx_offset_0[];
extern u8 lbl_1_data_2BB9C__fzgx_offset_0[];
extern u8 lbl_1_data_2BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_2BBC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BBD8__fzgx_offset_0[];
extern u8 lbl_1_data_2BBEC__fzgx_offset_0[];
extern u8 lbl_1_data_2BC00__fzgx_offset_0[];
extern u8 lbl_1_data_2BC14__fzgx_offset_0[];
extern u8 lbl_1_data_2BC28__fzgx_offset_0[];
extern u8 lbl_1_data_2BC3C__fzgx_offset_0[];
extern u8 lbl_1_data_2BC50__fzgx_offset_0[];
extern u8 lbl_1_data_2BC64__fzgx_offset_0[];
extern u8 lbl_1_data_2BC78__fzgx_offset_0[];
extern u8 lbl_1_data_2BC8C__fzgx_offset_0[];
extern u8 lbl_1_data_2BCA0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCB4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCDC__fzgx_offset_0[];
extern u8 lbl_1_data_2BCE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BCF4__fzgx_offset_0[];
extern u8 lbl_1_data_2BD00__fzgx_offset_0[];
extern u8 lbl_1_data_2BD10__fzgx_offset_0[];
extern u8 lbl_1_data_2BD20__fzgx_offset_0[];
extern u8 lbl_1_data_2BD30__fzgx_offset_0[];
extern u8 lbl_1_data_2BD40__fzgx_offset_0[];
extern u8 lbl_1_data_2C7BC__fzgx_offset_0[];
extern u8 lbl_1_data_2C7C0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E4__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E8__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F8__fzgx_offset_0[];
extern u8 lbl_1_data_2C804__fzgx_offset_0[];
extern u8 lbl_1_data_2C80C__fzgx_offset_0[];
extern u8 lbl_1_data_2C818__fzgx_offset_0[];
extern u8 lbl_1_data_2C824__fzgx_offset_0[];
extern u8 lbl_1_data_2C86C__fzgx_offset_0[];
extern u8 lbl_1_data_2C870__fzgx_offset_0[];
extern u8 lbl_1_data_2C890__fzgx_offset_0[];
extern u8 lbl_1_data_2C8B0__fzgx_offset_0[];
extern u8 lbl_1_data_2C8D0__fzgx_offset_0[];

extern void fn_1_46B4(u32, u32, const char *, int);

typedef struct {
    s16 idx;
    u8 pad0[0x36];
    u32 f38;
    u32 f3c;
    u8 pad1[0x38];
    u32 f78;
} BurnS;

typedef struct {
    u8 pad[0x10];
    void (*fn)(void);
    u8 pad2[0x10];
} Ent;

static u32 fzgx_pool_data_lbl_1_data_2A0C0[456] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F43455F, 0x4C494748, 0x544D4150, 0x5F410000, 0x4F43455F, 0x57415645, 0x5F504154, 0x5F420000,
    0x4F43455F, 0x4E414D49, 0x5F000000, 0x4F434E5F, 0x504F4F4C, 0x0, 0x42494742, 0x4C55455F,
    0x52454E5A, 0x5F465245, 0x41303100, 0x1, (u32)lbl_1_data_2A0C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A0D0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A0E0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0F8__fzgx_offset_0, 0x3, 0x0, 0x5F6C746D,
    0x70000000, 0x5F6C746D, 0x70320000, 0x4F43455F, 0x43415343, 0x4144455F, 0x0, 0x4F43455F,
    0x4332375F, 0x43415343, 0x41444500, 0x43554245, 0x5F474154, 0x455F415F, 0x4C4F4400, 0x43554245,
    0x5F425F41, 0x5F4C4F44, 0x0, 0x43554245, 0x5F445F41, 0x5F4C4F44, 0x0, 0x42494742,
    0x4C55455F, 0x53554E30, 0x31000000, 0x2, (u32)lbl_1_data_2A13C__fzgx_offset_0, 0x2, (u32)lbl_1_data_2A144__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A14C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A15C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A16C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A17C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A18C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A19C__fzgx_offset_0, 0x3, 0x0, 0x5F5F5F00,
    0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3, 0x0, 0x5041544C, 0x414D505F, 0x41000000, 0x5041544C,
    0x414D505F, 0x42000000, 0x5041544C, 0x414D505F, 0x43000000, 0x5041544C, 0x414D505F, 0x44000000,
    0x424E535F, 0x534B595F, 0x4B554D4F, 0x5F000000, 0x4C49475F, 0x47524F55, 0x4E445F41, 0x0,
    0x4330385F, 0x5241494E, 0x524F4144, 0x0, 0x4330395F, 0x5241494E, 0x524F4144, 0x0,
    0x4332335F, 0x5241494E, 0x524F4144, 0x0, 0x4333345F, 0x5241494E, 0x524F4144, 0x0,
    0x52455041, 0x4952504F, 0x494E5400, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A240__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A250__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A260__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A270__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A280__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A290__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A2A0__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x464C4147, 0x0, 0x0,
    (u32)lbl_1_data_2A314__fzgx_offset_0, 0x3, 0x0, 0x464F525F, 0x4546465F, 0x48413031, 0x0, 0x464F525F,
    0x52454E5A, 0x5F465245, 0x41000000, 0x464F525F, 0x4546465F, 0x47524E4C, 0x49470000, 0x1,
    (u32)lbl_1_data_2A32C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A33C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A34C__fzgx_offset_0, 0x3, 0x0, 0x464F525F,
    0x53554E00, 0x0, (u32)lbl_1_data_2A37C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3,
    0x0, 0x535F5348, 0x49500000, 0x0, (u32)lbl_1_data_2A3C4__fzgx_offset_0, 0x3, 0x0, 0x53414E5F,
    0x57415645, 0x5F504154, 0x5F4D0000, 0x53414E5F, 0x57415645, 0x5F504154, 0x5F530000, 0x474F524F,
    0x46524147, 0x5F767478, 0x0, 0x474F524F, 0x46524147, 0x325F7674, 0x78000000, 0x1,
    (u32)lbl_1_data_2A3DC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3EC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3FC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A40C__fzgx_offset_0, 0x3,
    0x0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x44494345,
    0x0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x434F494E, 0x0, 0x0,
    (u32)lbl_1_data_2A494__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x4D45545F, 0x434F4D45, 0x54303200,
    0x4546465F, 0x524F434B, 0x46495245, 0x5F415F52, 0x32533100, 0x4546465F, 0x524F434B, 0x46495245,
    0x5F425F52, 0x32533100, 0x1, (u32)lbl_1_data_2A4B4__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4D4__fzgx_offset_0,
    0x3, 0x0, 0x4D45545F, 0x42494753, 0x54415230, 0x31000000, 0x0, (u32)lbl_1_data_2A508__fzgx_offset_0,
    0x3, 0x0, 0x3, 0x0, 0x454C565F, 0x544F5000, 0x454C565F, 0x434F4C4F,
    0x4E590000, 0x454C565F, 0x544F5745, 0x52424153, 0x4530315F, 0x415F4C4F, 0x44000000, 0x454C565F,
    0x43415247, 0x4F30315F, 0x415F4C4F, 0x44000000, 0x454C565F, 0x424F5830, 0x315F415F, 0x4C4F4400,
    0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A530__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A538__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A544__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A55C__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A570__fzgx_offset_0, 0x3, 0x0, 0x57494E44, 0x4F573031, 0x0, 0x0,
    (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x3, 0x0, 0x53454152, 0x43483031, 0x0, 0x53454152, 0x43485F41,
    0x524D3031, 0x0, 0x53454152, 0x43485F41, 0x524D3032, 0x0, 0x5343414D, 0x504F494E,
    0x54303100, 0x464C4153, 0x48303100, 0x0, (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A5EC__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A5F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A608__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A618__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A624__fzgx_offset_0, 0x3,
    0x0, 0x3, 0x0, 0x43554245, 0x0, 0x0, (u32)lbl_1_data_2A66C__fzgx_offset_0, 0x3,
    0x0, 0x4654565F, 0x4C4F474F, 0x0, 0x4654565F, 0x52494E47, 0x0, 0x4654565F,
    0x52494E47, 0x5F460000, 0x4654565F, 0x45415254, 0x48000000, 0x4654565F, 0x52494E47, 0x5F540000,
    0x0, (u32)lbl_1_data_2A684__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A690__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A69C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A6A8__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2A6B4__fzgx_offset_0, 0x3, 0x0, 0x43415244, 0x49535000, 0x47414C44, 0x49535000,
    0x57494E4E, 0x45523031, 0x0, 0x57494E4E, 0x45523032, 0x0, 0x57494E4E, 0x45523033,
    0x0, 0x57494E4E, 0x45523034, 0x0, 0x48594F55, 0x53594F55, 0x53504F54, 0x0,
    0x48594F55, 0x53594F55, 0x0, 0x4D55545F, 0x47524F55, 0x4E440000, 0x4D55545F, 0x53544152,
    0x53000000, 0x4D55545F, 0x43495459, 0x5F4C4947, 0x48545300, 0x0, (u32)lbl_1_data_2A6F0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A6F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A700__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A70C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A718__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A724__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A730__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A740__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A74C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A758__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A764__fzgx_offset_0, 0x3, 0x0, 0x0, 0x0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2A7E0[62] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080, 0x80000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
static u32 fzgx_pool_data_lbl_1_data_2A8D8[181] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_1E968__fzgx_offset_0, (u32)lbl_1_data_1E974__fzgx_offset_0, (u32)lbl_1_data_1E980__fzgx_offset_0, (u32)lbl_1_data_1E98C__fzgx_offset_0, (u32)lbl_1_data_1E998__fzgx_offset_0, (u32)lbl_1_data_1E9A4__fzgx_offset_0, (u32)lbl_1_data_1E9B0__fzgx_offset_0, (u32)lbl_1_data_1E9BC__fzgx_offset_0,
    (u32)lbl_1_data_1E9C8__fzgx_offset_0, (u32)lbl_1_data_1E9D4__fzgx_offset_0, (u32)lbl_1_data_1E9E0__fzgx_offset_0, (u32)lbl_1_data_1E9EC__fzgx_offset_0, (u32)lbl_1_data_1E9F8__fzgx_offset_0, (u32)lbl_1_data_1EA04__fzgx_offset_0, (u32)lbl_1_data_1EA10__fzgx_offset_0, (u32)lbl_1_data_1EA1C__fzgx_offset_0,
    (u32)lbl_1_data_1EA34__fzgx_offset_0, (u32)lbl_1_data_1EA40__fzgx_offset_0, (u32)lbl_1_data_1EA4C__fzgx_offset_0, (u32)lbl_1_data_1EA58__fzgx_offset_0, (u32)lbl_1_data_1EA64__fzgx_offset_0, (u32)lbl_1_data_1ED48__fzgx_offset_0, (u32)lbl_1_data_1ED54__fzgx_offset_0, (u32)lbl_1_data_1ED60__fzgx_offset_0,
    (u32)lbl_1_data_1ED6C__fzgx_offset_0, (u32)lbl_1_data_1ED78__fzgx_offset_0, (u32)lbl_1_data_1ED84__fzgx_offset_0, (u32)lbl_1_data_1ED90__fzgx_offset_0, (u32)lbl_1_data_1ED9C__fzgx_offset_0, (u32)lbl_1_data_1EDA8__fzgx_offset_0, (u32)lbl_1_data_1EDB4__fzgx_offset_0, (u32)lbl_1_data_1EDC0__fzgx_offset_0,
    (u32)lbl_1_data_1EDCC__fzgx_offset_0, (u32)lbl_1_data_1EDD8__fzgx_offset_0, (u32)lbl_1_data_1EDE4__fzgx_offset_0, (u32)lbl_1_data_1EDF0__fzgx_offset_0, (u32)lbl_1_data_1EDFC__fzgx_offset_0, (u32)lbl_1_data_1EE08__fzgx_offset_0, (u32)lbl_1_data_1EE14__fzgx_offset_0, (u32)lbl_1_data_1EE20__fzgx_offset_0,
    (u32)lbl_1_data_1EE2C__fzgx_offset_0, (u32)lbl_1_data_1EE38__fzgx_offset_0, 0x4E554C4C, 0x0, 0x4D555445, 0x20434954, 0x59000000, 0x504F5254,
    0x20544F57, 0x4E000000, 0x42494720, 0x424C5545, 0x0, 0x4C494748, 0x544E494E, 0x47000000,
    0x53414E44, 0x204F4345, 0x414E0000, 0x47524545, 0x4E20504C, 0x414E5400, 0x46495245, 0x20464945,
    0x4C440000, 0x43415349, 0x4E4F2050, 0x414C4143, 0x45000000, 0x4F555445, 0x52205350, 0x41434500,
    0x4145524F, 0x504F4C49, 0x53000000, 0x434F534D, 0x4F205445, 0x524D494E, 0x414C0000, 0x5048414E,
    0x544F4D20, 0x524F4144, 0x0, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0,
    (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9C4__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0,
    (u32)lbl_1_data_2A9DC__fzgx_offset_0, (u32)lbl_1_data_2A9EC__fzgx_offset_0, (u32)lbl_1_data_2A9F8__fzgx_offset_0, (u32)lbl_1_data_2AA04__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2AA14__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0,
    0x0, 0x837E8385, 0x815B8367, 0x20835683, 0x65834200, 0x837C815B, 0x83672083, 0x5E834583,  /* fzgx-allow: A1 retail data bytes */
    0x93000000, 0x83728362, 0x834F2083, 0x75838B81, 0x5B000000, 0x83898343, 0x8367836A, 0x8393834F,
    0x0, 0x83548393, 0x83682083, 0x49815B83, 0x56838383, 0x93000000, 0x834F838A, 0x815B8393,  /* fzgx-allow: A1 retail data bytes */
    0x20837683, 0x89839383, 0x67000000, 0x83748340, 0x83438341, 0x20837483, 0x42815B83, 0x8B836800,
    0x834A8357, 0x836D2083, 0x70838C83, 0x58000000, 0x83418345, 0x835E815B, 0x20835883, 0x79815B83,
    0x58000000, 0x83478341, 0x838D837C, 0x838A8358, 0x0, 0x83528358, 0x83822083, 0x5E815B83,
    0x7E836983, 0x8B000000, 0x83748340, 0x83938367, 0x83802083, 0x8D815B83, 0x68000000, (u32)lbl_1_data_2A980__fzgx_offset_0,
    (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0,
    (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AAD0__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAF8__fzgx_offset_0, (u32)lbl_1_data_2AB08__fzgx_offset_0, (u32)lbl_1_data_2AB1C__fzgx_offset_0, (u32)lbl_1_data_2AB2C__fzgx_offset_0,
    (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AB40__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2ABAC[198] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0,
    (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0,
    (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0,
    (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0,
    (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0,
    (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0,
    (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0,
    (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0,
    (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0,
    (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_DC204__fzgx_offset_0, (u32)fn_1_DC208__fzgx_offset_0, (u32)fn_1_DC264__fzgx_offset_0, (u32)fn_1_DC268__fzgx_offset_0, (u32)fn_1_DC2F8__fzgx_offset_0, (u32)fn_1_DC33C__fzgx_offset_0,
    (u32)fn_1_DC3A0__fzgx_offset_0, (u32)fn_1_DCB9C__fzgx_offset_0, (u32)fn_1_DCBF4__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0,
    (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0,
    (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_FA6C0__fzgx_offset_0, (u32)fn_1_FA75C__fzgx_offset_0, (u32)fn_1_FA82C__fzgx_offset_0,
    (u32)fn_1_FA830__fzgx_offset_0, (u32)fn_1_FA854__fzgx_offset_0, (u32)fn_1_FA878__fzgx_offset_0, (u32)fn_1_FA898__fzgx_offset_0, (u32)fn_1_FB770__fzgx_offset_0, (u32)fn_1_FB798__fzgx_offset_0, (u32)fn_1_FE5E0__fzgx_offset_0, (u32)fn_1_FE5E4__fzgx_offset_0,
    (u32)fn_1_FE640__fzgx_offset_0, (u32)fn_1_FE644__fzgx_offset_0, (u32)fn_1_FE780__fzgx_offset_0, (u32)fn_1_FE784__fzgx_offset_0, (u32)fn_1_FE7D4__fzgx_offset_0, (u32)fn_1_101348__fzgx_offset_0, (u32)fn_1_1013A0__fzgx_offset_0, (u32)fn_1_153988__fzgx_offset_0,
    (u32)fn_1_15398C__fzgx_offset_0, (u32)fn_1_1539D0__fzgx_offset_0, (u32)fn_1_153A28__fzgx_offset_0, (u32)fn_1_153AAC__fzgx_offset_0, (u32)fn_1_153AB0__fzgx_offset_0, (u32)fn_1_153AF4__fzgx_offset_0, (u32)fn_1_1543E8__fzgx_offset_0, (u32)fn_1_154410__fzgx_offset_0,
    (u32)fn_1_150500__fzgx_offset_0, (u32)fn_1_150518__fzgx_offset_0, (u32)fn_1_150570__fzgx_offset_0, (u32)fn_1_1505B4__fzgx_offset_0, (u32)fn_1_150574__fzgx_offset_0, (u32)fn_1_150608__fzgx_offset_0, (u32)fn_1_150650__fzgx_offset_0, (u32)fn_1_151764__fzgx_offset_0,
    (u32)fn_1_15176C__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0,
    (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1586A8__fzgx_offset_0, (u32)fn_1_1586AC__fzgx_offset_0, (u32)fn_1_158980__fzgx_offset_0, (u32)fn_1_158984__fzgx_offset_0, (u32)fn_1_15903C__fzgx_offset_0,
    (u32)fn_1_159040__fzgx_offset_0, (u32)fn_1_159060__fzgx_offset_0, (u32)fn_1_159064__fzgx_offset_0, (u32)fn_1_15906C__fzgx_offset_0, (u32)fn_1_15B428__fzgx_offset_0, (u32)fn_1_15B42C__fzgx_offset_0, (u32)fn_1_15B4F8__fzgx_offset_0, (u32)fn_1_15B4FC__fzgx_offset_0,
    (u32)fn_1_15B51C__fzgx_offset_0, (u32)fn_1_15B520__fzgx_offset_0, (u32)fn_1_15B540__fzgx_offset_0, (u32)fn_1_15B698__fzgx_offset_0, (u32)fn_1_15B70C__fzgx_offset_0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2AEC4[1831] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x62675F6D, 0x75740000, 0x62675F70, 0x6F720000, 0x62675F70, 0x6F725F73, 0x0, 0x62675F62,
    0x69670000, 0x62675F62, 0x69675F73, 0x0, 0x62675F6C, 0x69670000, 0x62675F73, 0x616E0000,
    0x62675F73, 0x616E5F73, 0x0, 0x62675F66, 0x6F720000, 0x62675F66, 0x69720000, 0x62675F66,
    0x69725F73, 0x0, 0x62675F63, 0x61730000, 0x62675F6D, 0x65740000, 0x62675F74, 0x6F770000,
    0x62675F65, 0x6C650000, 0x62675F63, 0x6F6D0000, 0x62675F63, 0x6F6D5F73, 0x0, 0x62675F72,
    0x61690000, 0x62675F77, 0x696E5F67, 0x78000000, 0x0, (u32)lbl_1_data_2AEC4__fzgx_offset_0, (u32)lbl_1_data_2AECC__fzgx_offset_0, (u32)lbl_1_data_2AED4__fzgx_offset_0,
    (u32)lbl_1_data_2AEE0__fzgx_offset_0, (u32)lbl_1_data_2AEE8__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEFC__fzgx_offset_0, (u32)lbl_1_data_2AF04__fzgx_offset_0, (u32)lbl_1_data_2AF10__fzgx_offset_0, (u32)lbl_1_data_2AF18__fzgx_offset_0,
    (u32)lbl_1_data_2AF20__fzgx_offset_0, (u32)lbl_1_data_2AF2C__fzgx_offset_0, (u32)lbl_1_data_2AF34__fzgx_offset_0, (u32)lbl_1_data_2AF3C__fzgx_offset_0, (u32)lbl_1_data_2AF44__fzgx_offset_0, (u32)lbl_1_data_2AF4C__fzgx_offset_0, (u32)lbl_1_data_2AF54__fzgx_offset_0, (u32)lbl_1_data_2AF60__fzgx_offset_0,
    (u32)lbl_1_data_2AF68__fzgx_offset_0, 0x0, 0x0, 0x4, 0x202C0, 0x202C0, 0x18B0, 0x18B0,
    0xFD80, 0xFD80, 0x1C60, 0x1C60, 0x226C, 0x764, 0x764, 0x174,
    0x1B1E8, 0x1704, 0x2748, 0x4, 0x4, 0x157CC, 0x128, 0x0,
    0x0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0,
    (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A35C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A484__fzgx_offset_0, (u32)lbl_1_data_2A4E8__fzgx_offset_0, (u32)lbl_1_data_2A5DC__fzgx_offset_0,
    (u32)lbl_1_data_2A528__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A664__fzgx_offset_0, (u32)lbl_1_data_2A6C0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2A31C__fzgx_offset_0,
    (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0,
    (u32)lbl_1_data_2A384__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A49C__fzgx_offset_0, (u32)lbl_1_data_2A518__fzgx_offset_0, (u32)lbl_1_data_2A62C__fzgx_offset_0, (u32)lbl_1_data_2A580__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0,
    (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A674__fzgx_offset_0, (u32)lbl_1_data_2A774__fzgx_offset_0, 0x0, 0x8010101, 0x10F0202, 0x6060A0A, 0x602040B,
    0xD0B0B0E, 0xE0F1006, 0x10080804, 0x130D080F, 0xE02060A, 0x1112090D, 0x5070301, 0xC130000,
    0x141400, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x10202, 0x3030404, 0x5050607, 0x708090A, 0xB0C0C0D, 0x1000000, 0x2D2D2D00, 0x54776973,
    0x7420526F, 0x61640000, 0x53657269, 0x616C2047, 0x61707300, 0x4D756C74, 0x69706C65, 0x78000000,
    0x4165726F, 0x20446976, 0x65000000, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x48616C66, 0x20506970,
    0x65000000, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x4D6F6269, 0x75732052, 0x696E6700,
    0x4C6F6E67, 0x20506970, 0x65000000, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x43796C69,
    0x6E646572, 0x204B6E6F, 0x74000000, 0x53706C69, 0x74204F76, 0x616C0000, 0x556E6475, 0x6C617469,
    0x6F6E0000, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x54726964, 0x656E7400, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x4F726465,
    0x616C0000, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x446F7562, 0x6C652042, 0x72616E63,
    0x68657300, 0x53637265, 0x77204472, 0x69766500, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000,
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x5468756E, 0x64657220, 0x526F6164, 0x0,
    0x53706972, 0x616C0000, 0x536F6E69, 0x63204F76, 0x616C0000, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B1A8__fzgx_offset_0,
    (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B230__fzgx_offset_0,
    (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2B294__fzgx_offset_0,
    (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, 0x96A292E8, 0x0, 0x47455220, 0x54776973,
    0x7420526F, 0x61640000, 0x46524520, 0x54776973, 0x7420526F, 0x61640000, 0x53504120, 0x54776973,
    0x7420526F, 0x61640000, 0x49544120, 0x54776973, 0x7420526F, 0x61640000, 0x83638343, 0x83588367,
    0x838D815B, 0x83680000, 0x47455220, 0x53657269, 0x616C2047, 0x61707300, 0x46524520, 0x53657269,
    0x616C2047, 0x61707300, 0x53504120, 0x53657269, 0x616C2047, 0x61707300, 0x49544120, 0x53657269,
    0x616C2047, 0x61707300, 0x8356838A, 0x8341838B, 0x834D8383, 0x83628376, 0x0, 0x47455220,
    0x4D756C74, 0x69706C65, 0x78000000, 0x46524520, 0x4D756C74, 0x69706C65, 0x78000000, 0x53504120,
    0x4D756C74, 0x69706C65, 0x78000000, 0x49544120, 0x4D756C74, 0x69706C65, 0x78000000, 0x837D838B,
    0x83608376, 0x838C8362, 0x834E8358, 0x0, 0x47455220, 0x4165726F, 0x20446976, 0x65000000,
    0x46524520, 0x4165726F, 0x20446976, 0x65000000, 0x53504120, 0x4165726F, 0x20446976, 0x65000000,
    0x49544120, 0x4165726F, 0x20446976, 0x65000000, 0x83478341, 0x838D835F, 0x83438375, 0x0,
    0x47455220, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x46524520, 0x4C6F6F70, 0x2043726F, 0x73730000,
    0x53504120, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x49544120, 0x4C6F6F70, 0x2043726F, 0x73730000,
    0x838B815B, 0x8376834E, 0x838D8358, 0x0, 0x47455220, 0x48616C66, 0x20506970, 0x65000000,
    0x46524520, 0x48616C66, 0x20506970, 0x65000000, 0x53504120, 0x48616C66, 0x20506970, 0x65000000,
    0x49544120, 0x48616C66, 0x20506970, 0x65000000, 0x836E815B, 0x83748370, 0x83438376, 0x0,
    0x47455220, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x46524520, 0x496E7465, 0x72736563,
    0x74696F6E, 0x0, 0x53504120, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x49544120,
    0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x83438393, 0x835E815B, 0x835A834E, 0x83568387,
    0x83930000, 0x47455220, 0x4D6F6269, 0x75732052, 0x696E6700, 0x46524520, 0x4D6F6269, 0x75732052,
    0x696E6700, 0x53504120, 0x4D6F6269, 0x75732052, 0x696E6700, 0x49544120, 0x4D6F6269, 0x75732052,
    0x696E6700, 0x83818372, 0x83458358, 0x838A8393, 0x834F0000, 0x47455220, 0x4C6F6E67, 0x20506970,
    0x65000000, 0x46524520, 0x4C6F6E67, 0x20506970, 0x65000000, 0x53504120, 0x4C6F6E67, 0x20506970,
    0x65000000, 0x49544120, 0x4C6F6E67, 0x20506970, 0x65000000, 0x838D8393, 0x834F8370, 0x83438376,
    0x0, 0x47455220, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x46524520, 0x44726966,
    0x74204869, 0x67687761, 0x79000000, 0x53504120, 0x44726966, 0x74204869, 0x67687761, 0x79000000,
    0x49544120, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x8368838A, 0x83748367, 0x836E8343,
    0x83458346, 0x83430000, 0x47455220, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x46524520,
    0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x53504120, 0x43796C69, 0x6E646572, 0x204B6E6F,
    0x74000000, 0x49544120, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x8356838A, 0x8393835F,
    0x815B836D, 0x83628367, 0x0, 0x47455220, 0x53706C69, 0x74204F76, 0x616C0000, 0x46524520,  /* fzgx-allow: A1 retail data bytes */
    0x53706C69, 0x74204F76, 0x616C0000, 0x53504120, 0x53706C69, 0x74204F76, 0x616C0000, 0x49544120,
    0x53706C69, 0x74206F76, 0x616C0000, 0x83588376, 0x838A8362, 0x83678349, 0x815B836F, 0x838B0000,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x46524520, 0x556E6475, 0x6C617469, 0x6F6E0000,
    0x53504120, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x49544120, 0x556E6475, 0x6C617469, 0x6F6E0000,
    0x83418393, 0x83668385, 0x838C815B, 0x83568387, 0x83930000, 0x47455220, 0x44726167, 0x6F6E2053,
    0x6C6F7065, 0x0, 0x46524520, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x53504120,
    0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x49544120, 0x44726167, 0x6F6E2053, 0x6C6F7065,
    0x0, 0x83688389, 0x83538393, 0x8358838D, 0x815B8376, 0x0, 0x47455220, 0x54726964,  /* fzgx-allow: A1 retail data bytes */
    0x656E7400, 0x46524520, 0x54726964, 0x656E7400, 0x53504120, 0x54726964, 0x656E7400, 0x49544120,
    0x54726964, 0x656E7400, 0x83678389, 0x83438366, 0x83938367, 0x0, 0x47455220, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x46524520, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000,
    0x53504120, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x49544120, 0x4C617465, 0x72616C20,
    0x53686966, 0x74000000, 0x83898365, 0x8389838B, 0x83568374, 0x83670000, 0x47455220, 0x53757266,
    0x61636520, 0x536C6964, 0x65000000, 0x46524520, 0x53757266, 0x61636520, 0x536C6964, 0x65000000,
    0x53504120, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x49544120, 0x53757266, 0x61636520,
    0x536C6964, 0x65000000, 0x8354815B, 0x83748346, 0x83588358, 0x83898343, 0x83680000, 0x47455220,
    0x4F726465, 0x616C0000, 0x46524520, 0x4F726465, 0x616C0000, 0x53504120, 0x4F726465, 0x616C0000,
    0x49544120, 0x4F726465, 0x616C0000, 0x8349815B, 0x83668342, 0x815B838B, 0x0, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x46524520, 0x536C696D, 0x2D6C696E, 0x6520536C,
    0x69747300, 0x53504120, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x49544120, 0x536C696D,
    0x2D6C696E, 0x6520536C, 0x69747300, 0x8358838A, 0x83808389, 0x83438393, 0x8358838A, 0x83628367,
    0x0, 0x47455220, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x46524520, 0x446F7562,
    0x6C652042, 0x72616E63, 0x68657300, 0x53504120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300,
    0x49544120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x835F8375, 0x838B8375, 0x83898393,
    0x83600000, 0x47455220, 0x53637265, 0x77204472, 0x69766500, 0x46524520, 0x53637265, 0x77204472,
    0x69766500, 0x53504120, 0x53637265, 0x77204472, 0x69766500, 0x49544120, 0x53637265, 0x77204472,
    0x69766500, 0x8358834E, 0x838A8385, 0x815B8368, 0x83898343, 0x83750000, 0x47455220, 0x4D657465,  /* fzgx-allow: A1 retail data bytes */
    0x6F722053, 0x74726561, 0x6D000000, 0x46524520, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000,
    0x53504120, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000, 0x49544120, 0x4D657465, 0x6F722053,
    0x74726561, 0x6D000000, 0x83818365, 0x83498358, 0x8367838A, 0x815B8380, 0x0, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x46524520, 0x43796C69, 0x6E646572, 0x20576176,
    0x65000000, 0x53504120, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x49544120, 0x43796C69,
    0x6E646572, 0x20576176, 0x65000000, 0x8356838A, 0x8393835F, 0x815B8345, 0x8346815B, 0x83750000,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x46524520, 0x5468756E, 0x64657220,
    0x526F6164, 0x0, 0x53504120, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x49544120,
    0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x83548393, 0x835F815B, 0x838D815B, 0x83680000,
    0x47455220, 0x53706972, 0x616C0000, 0x46524520, 0x53706972, 0x616C0000, 0x53504120, 0x53706972,
    0x616C0000, 0x49544120, 0x53706972, 0x616C0000, 0x83588370, 0x83438389, 0x838B0000, 0x47455220,
    0x536F6E69, 0x63204F76, 0x616C0000, 0x46524520, 0x536F6E69, 0x63204F76, 0x616C0000, 0x53504120,
    0x536F6E69, 0x63204F76, 0x616C0000, 0x49544120, 0x536F6E69, 0x63204F76, 0x616C0000, 0x835C836A,
    0x8362834E, 0x8349815B, 0x836F838B, 0x0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B47C__fzgx_offset_0, (u32)lbl_1_data_2B48C__fzgx_offset_0, (u32)lbl_1_data_2B49C__fzgx_offset_0, (u32)lbl_1_data_2B4AC__fzgx_offset_0, (u32)lbl_1_data_2B4BC__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B4CC__fzgx_offset_0,
    (u32)lbl_1_data_2B4DC__fzgx_offset_0, (u32)lbl_1_data_2B4EC__fzgx_offset_0, (u32)lbl_1_data_2B4FC__fzgx_offset_0, (u32)lbl_1_data_2B50C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B520__fzgx_offset_0, (u32)lbl_1_data_2B530__fzgx_offset_0, (u32)lbl_1_data_2B540__fzgx_offset_0, (u32)lbl_1_data_2B550__fzgx_offset_0, (u32)lbl_1_data_2B560__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B574__fzgx_offset_0,
    (u32)lbl_1_data_2B584__fzgx_offset_0, (u32)lbl_1_data_2B594__fzgx_offset_0, (u32)lbl_1_data_2B5A4__fzgx_offset_0, (u32)lbl_1_data_2B5B4__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B5C4__fzgx_offset_0, (u32)lbl_1_data_2B5D4__fzgx_offset_0, (u32)lbl_1_data_2B5E4__fzgx_offset_0,
    (u32)lbl_1_data_2B5F4__fzgx_offset_0, (u32)lbl_1_data_2B604__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B614__fzgx_offset_0, (u32)lbl_1_data_2B624__fzgx_offset_0, (u32)lbl_1_data_2B634__fzgx_offset_0, (u32)lbl_1_data_2B644__fzgx_offset_0, (u32)lbl_1_data_2B654__fzgx_offset_0,
    (u32)lbl_1_data_2B1A8__fzgx_offset_0, (u32)lbl_1_data_2B664__fzgx_offset_0, (u32)lbl_1_data_2B678__fzgx_offset_0, (u32)lbl_1_data_2B68C__fzgx_offset_0, (u32)lbl_1_data_2B6A0__fzgx_offset_0, (u32)lbl_1_data_2B6B4__fzgx_offset_0, (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B6C8__fzgx_offset_0,
    (u32)lbl_1_data_2B6D8__fzgx_offset_0, (u32)lbl_1_data_2B6E8__fzgx_offset_0, (u32)lbl_1_data_2B6F8__fzgx_offset_0, (u32)lbl_1_data_2B708__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B718__fzgx_offset_0, (u32)lbl_1_data_2B728__fzgx_offset_0, (u32)lbl_1_data_2B738__fzgx_offset_0, (u32)lbl_1_data_2B748__fzgx_offset_0, (u32)lbl_1_data_2B758__fzgx_offset_0,
    (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B768__fzgx_offset_0, (u32)lbl_1_data_2B77C__fzgx_offset_0, (u32)lbl_1_data_2B790__fzgx_offset_0, (u32)lbl_1_data_2B7A4__fzgx_offset_0, (u32)lbl_1_data_2B7B8__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B7CC__fzgx_offset_0,
    (u32)lbl_1_data_2B7E0__fzgx_offset_0, (u32)lbl_1_data_2B7F4__fzgx_offset_0, (u32)lbl_1_data_2B808__fzgx_offset_0, (u32)lbl_1_data_2B81C__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B830__fzgx_offset_0, (u32)lbl_1_data_2B840__fzgx_offset_0, (u32)lbl_1_data_2B850__fzgx_offset_0,
    (u32)lbl_1_data_2B860__fzgx_offset_0, (u32)lbl_1_data_2B870__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B884__fzgx_offset_0, (u32)lbl_1_data_2B894__fzgx_offset_0, (u32)lbl_1_data_2B8A4__fzgx_offset_0, (u32)lbl_1_data_2B8B4__fzgx_offset_0, (u32)lbl_1_data_2B8C4__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B8D8__fzgx_offset_0, (u32)lbl_1_data_2B8EC__fzgx_offset_0, (u32)lbl_1_data_2B900__fzgx_offset_0, (u32)lbl_1_data_2B914__fzgx_offset_0, (u32)lbl_1_data_2B928__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B93C__fzgx_offset_0, (u32)lbl_1_data_2B948__fzgx_offset_0, (u32)lbl_1_data_2B954__fzgx_offset_0,
    (u32)lbl_1_data_2B960__fzgx_offset_0, (u32)lbl_1_data_2B96C__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B97C__fzgx_offset_0, (u32)lbl_1_data_2B990__fzgx_offset_0, (u32)lbl_1_data_2B9A4__fzgx_offset_0, (u32)lbl_1_data_2B9B8__fzgx_offset_0, (u32)lbl_1_data_2B9CC__fzgx_offset_0,
    (u32)lbl_1_data_2B230__fzgx_offset_0, (u32)lbl_1_data_2B9DC__fzgx_offset_0, (u32)lbl_1_data_2B9F0__fzgx_offset_0, (u32)lbl_1_data_2BA04__fzgx_offset_0, (u32)lbl_1_data_2BA18__fzgx_offset_0, (u32)lbl_1_data_2BA2C__fzgx_offset_0, (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2BA40__fzgx_offset_0,
    (u32)lbl_1_data_2BA4C__fzgx_offset_0, (u32)lbl_1_data_2BA58__fzgx_offset_0, (u32)lbl_1_data_2BA64__fzgx_offset_0, (u32)lbl_1_data_2BA70__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2BA80__fzgx_offset_0, (u32)lbl_1_data_2BA94__fzgx_offset_0, (u32)lbl_1_data_2BAA8__fzgx_offset_0,
    (u32)lbl_1_data_2BABC__fzgx_offset_0, (u32)lbl_1_data_2BAD0__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2BAE8__fzgx_offset_0, (u32)lbl_1_data_2BAFC__fzgx_offset_0, (u32)lbl_1_data_2BB10__fzgx_offset_0, (u32)lbl_1_data_2BB24__fzgx_offset_0, (u32)lbl_1_data_2BB38__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2BB48__fzgx_offset_0,
    (u32)lbl_1_data_2BB58__fzgx_offset_0, (u32)lbl_1_data_2BB68__fzgx_offset_0, (u32)lbl_1_data_2BB78__fzgx_offset_0, (u32)lbl_1_data_2BB88__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2BB9C__fzgx_offset_0, (u32)lbl_1_data_2BBB0__fzgx_offset_0, (u32)lbl_1_data_2BBC4__fzgx_offset_0,
    (u32)lbl_1_data_2BBD8__fzgx_offset_0, (u32)lbl_1_data_2BBEC__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2BC00__fzgx_offset_0, (u32)lbl_1_data_2BC14__fzgx_offset_0, (u32)lbl_1_data_2BC28__fzgx_offset_0, (u32)lbl_1_data_2BC3C__fzgx_offset_0, (u32)lbl_1_data_2BC50__fzgx_offset_0,
    (u32)lbl_1_data_2B294__fzgx_offset_0, (u32)lbl_1_data_2BC64__fzgx_offset_0, (u32)lbl_1_data_2BC78__fzgx_offset_0, (u32)lbl_1_data_2BC8C__fzgx_offset_0, (u32)lbl_1_data_2BCA0__fzgx_offset_0, (u32)lbl_1_data_2BCB4__fzgx_offset_0, (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2BCC4__fzgx_offset_0,
    (u32)lbl_1_data_2BCD0__fzgx_offset_0, (u32)lbl_1_data_2BCDC__fzgx_offset_0, (u32)lbl_1_data_2BCE8__fzgx_offset_0, (u32)lbl_1_data_2BCF4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0,
    (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0, (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, 0x1020304, 0x10203,
    0x4050607, 0x8090A0B, 0xC0D0E0F, 0x10111213, 0x14151617, 0x18191A1B, 0x1C1D1E1F, 0x20212223,
    0x10200, 0x10203, 0x4050600, 0x10203, 0x4050607, 0x42494746, 0x49534830, 0x31000000,
    0x574F524D, 0x0, 0x4B494E47, 0x5F434F42, 0x52410000, 0x53414E44, 0x5F464953, 0x48000000,
    0x53414E44, 0x5F424952, 0x44000000, (u32)lbl_1_data_2C7F8__fzgx_offset_0, 0x3, (u32)lbl_1_data_2C7BC__fzgx_offset_0, (u32)lbl_1_data_2C804__fzgx_offset_0, 0x9,
    (u32)lbl_1_data_2C7C0__fzgx_offset_0, (u32)lbl_1_data_2C80C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2C7E4__fzgx_offset_0, (u32)lbl_1_data_2C818__fzgx_offset_0, 0x1, (u32)lbl_1_data_2C7E8__fzgx_offset_0, (u32)lbl_1_data_2C824__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2C7F0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x44610000, 0x102,
    0x1, (u32)lbl_1_data_2C870__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43C80000, 0x102,
    0x1, (u32)lbl_1_data_2C890__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43480000, 0x102,
    0x1, (u32)lbl_1_data_2C8B0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x447A0000, 0x0,
    (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43FA0000, 0x3, 0x2, (u32)lbl_1_data_2C8D0__fzgx_offset_0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43480000, 0x43960000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43480000, 0x43C80000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x42C80000, 0x43480000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1, 0x43960000, 0x44160000, 0x1,
    0x1, 0x43FA0000, 0x447A0000, 0x1, 0x1, 0x43480000, 0x43C80000, 0x1,
    0x1, 0x43480000, 0x43C80000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43FA0000, 0x442F0000, 0x1, 0x1, 0x43C80000, 0x44480000, 0x0,
    0x1, 0x44BB8000, 0x451C4000, 0x0, 0x1, 0x447A0000, 0x44BB8000, 0x0,
    0x1, 0x447A0000, 0x44BB8000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x42C80000, 0x43480000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x43FA0000, 0x447A0000, 0x0,
    0x1, 0x43480000, 0x43C80000, 0x0, 0x1, 0x43FA0000, 0x447A0000, 0x1,
    0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1, 0x42C80000, 0x43480000, 0x1,
    0x1, 0x42C80000, 0x43960000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43480000, 0x43FA0000, 0x1, 0x1, 0x43FA0000, 0x447A0000, 0x0,
    0x1, 0x451C4000, 0x453B8000, 0x1, 0x1, 0x43960000, 0x44160000, 0x1,
    0x1, 0x43480000, 0x43960000, 0x0, 0x1, 0x447A0000, 0x44FA0000
};
static u32 fzgx_pool_data_lbl_1_data_2CB60[11] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6261636B, 0x67726F75, 0x6E642E63, 0x0, 0x25732573, 0x2E74706C, 0x2E6C7A00, 0x62672F00,
    0x25732573, 0x2E676D61, 0x2E6C7A00
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_2A0C0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A0C0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A7E0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A8D8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2ABAC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2AEC4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2CB60;
}
#pragma section code_type ".text"

void fn_1_9A864(void)
{
    
    BurnS *s = (BurnS *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0));

    if (s->f78 != 0) {
        fn_1_46B4((*(u32 *)&lbl_801A6410), s->f78, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_2CB60)), 0x281);
        s->f78 = 0;
    }
    fn_1_103054();
    if (((BurnS *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0)))->idx > 0) {
        Ent *e = (Ent *)(((u8 *)fzgx_pool_data_lbl_1_data_2ABAC));
        e += ((BurnS *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0)))->idx;
        e->fn();
    }
    s = (BurnS *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0));
    if (s->f3c != 0) {
        fn_1_46B4((*(u32 *)&lbl_801A6410), s->f3c, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_2CB60)), 0x28f);
        s->f3c = 0;
    }
    if (lbl_1_bss_384B8 != 0 || lbl_1_bss_384B4 != 0) {
        fn_1_9D2EC();
    }
    s = (BurnS *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0));
    s->f38 = 0;
    ((BurnS *)(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0)))->idx = -1;
}
/* fzgx:end fn_1_9A864 */

/* fzgx:begin fn_1_9A958 noprologue */
#include "types.h"

struct fn_1_9A958_data {
    u8 pad0[0x720];
    s16 current;
    u8 pad1[0x792];
    void *entries[0x58];
    u8 indices[1];
    u8 pad2[0x1A9B];
    char string_a[0xC];
    char string_b[0x4];
    char string_c[0x4];
};

extern struct fn_1_9A958_data lbl_1_data_2A0C0;
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);

#pragma opt_dead_assignments off
#pragma opt_propagation off
static inline void * fn_1_9A958_read_entry(struct fn_1_9A958_data * owner, int i) { return owner->entries[i]; }
void fn_1_9A958(int index, int flag) {
    struct fn_1_9A958_data *data = &lbl_1_data_2A0C0;
    u8 *indices = data->indices;
    u8 buffer_a[0x20];
    u8 buffer_b[0x20];
    int idx = indices[index];
    void *entry;
    struct { void **value; } table;

    if (data->current != idx) {
        int offset = idx * 4;
        table.value = data->entries;
        entry = *(void **)((u8 *)table.value + offset);
        if (entry != 0) {
            sprintf((char *)buffer_a, data->string_a, data->string_b, entry);
            sprintf((char *)buffer_b, data->string_c, data->string_b, entry);
            if (flag != 0) {
                fn_1_465D0((char *)buffer_a, 2);
                fn_1_465D0((char *)buffer_b, 2);
            } else {
                fn_1_465D0((char *)buffer_a, 1);
                fn_1_465D0((char *)buffer_b, 1);
            }
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_9A958 */

/* fzgx:begin fn_1_9AA2C noprologue */
#include "types.h"

struct fn_1_9AA2C_data {
    u8 pad0[0xEB4];
    void *entries[0x58];
    u8 indices[1];
    u8 pad1[0x1A9B];
    char string_a[0xC];
    char string_b[0x4];
    char string_c[0x4];
};

extern struct fn_1_9AA2C_data lbl_1_data_2A0C0;
extern void sprintf(void *buffer, const char *format, const char *arg, ...);
extern void fn_1_46DC4(void *buffer);

#pragma opt_dead_assignments off
static inline void * * fn_1_9AA2C_read_pointer(struct fn_1_9AA2C_data * owner) { return owner->entries; }
void fn_1_9AA2C(int index) {
    struct fn_1_9AA2C_data *data = &lbl_1_data_2A0C0;
    u8 *indices = data->indices;
    void *entry = fn_1_9AA2C_read_pointer(data)[indices[index]];
    u8 buffer_b[0x20];
    u8 buffer_a[0x20];

    if (entry != 0) {
        sprintf(buffer_b, data->string_a, data->string_b, entry);
        sprintf(buffer_a, data->string_c, data->string_b, entry);
        fn_1_46DC4(buffer_b);
        fn_1_46DC4(buffer_a);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_9AA2C */

/* fzgx:begin fn_1_9AABC noprologue */
#include "types.h"

typedef struct fn_1_9AABC_mode {
    void (*enter)(void);
    u8 pad4[0xC];
    void (*leave)(void);
    u8 pad14[0x8];
    u32 filter;
    u8 pad20[0x4];
} fn_1_9AABC_mode;

typedef struct fn_1_9AABC_state {
    s16 current;
    u8 pad2[0x36];
    u32 unk38;
    void *work;
    u8 pad40[0x38];
    void *buffer;
} fn_1_9AABC_state;

/* burner.c's .data block, addressed off one section base */
extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
extern u8 lbl_1_data_2B15C__fzgx_offset_0[];
extern u8 lbl_1_data_2B160__fzgx_offset_0[];
extern u8 lbl_1_data_2B16C__fzgx_offset_0[];
extern u8 lbl_1_data_2B178__fzgx_offset_0[];
extern u8 lbl_1_data_2B184__fzgx_offset_0[];
extern u8 lbl_1_data_2B190__fzgx_offset_0[];
extern u8 lbl_1_data_2B19C__fzgx_offset_0[];
extern u8 lbl_1_data_2B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B1D0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1F0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B208__fzgx_offset_0[];
extern u8 lbl_1_data_2B218__fzgx_offset_0[];
extern u8 lbl_1_data_2B220__fzgx_offset_0[];
extern u8 lbl_1_data_2B230__fzgx_offset_0[];
extern u8 lbl_1_data_2B240__fzgx_offset_0[];
extern u8 lbl_1_data_2B248__fzgx_offset_0[];
extern u8 lbl_1_data_2B258__fzgx_offset_0[];
extern u8 lbl_1_data_2B268__fzgx_offset_0[];
extern u8 lbl_1_data_2B274__fzgx_offset_0[];
extern u8 lbl_1_data_2B284__fzgx_offset_0[];
extern u8 lbl_1_data_2B294__fzgx_offset_0[];
extern u8 lbl_1_data_2B2A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B474__fzgx_offset_0[];
extern u8 lbl_1_data_2B47C__fzgx_offset_0[];
extern u8 lbl_1_data_2B48C__fzgx_offset_0[];
extern u8 lbl_1_data_2B49C__fzgx_offset_0[];
extern u8 lbl_1_data_2B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4BC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B50C__fzgx_offset_0[];
extern u8 lbl_1_data_2B520__fzgx_offset_0[];
extern u8 lbl_1_data_2B530__fzgx_offset_0[];
extern u8 lbl_1_data_2B540__fzgx_offset_0[];
extern u8 lbl_1_data_2B550__fzgx_offset_0[];
extern u8 lbl_1_data_2B560__fzgx_offset_0[];
extern u8 lbl_1_data_2B574__fzgx_offset_0[];
extern u8 lbl_1_data_2B584__fzgx_offset_0[];
extern u8 lbl_1_data_2B594__fzgx_offset_0[];
extern u8 lbl_1_data_2B5A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5D4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5E4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B604__fzgx_offset_0[];
extern u8 lbl_1_data_2B614__fzgx_offset_0[];
extern u8 lbl_1_data_2B624__fzgx_offset_0[];
extern u8 lbl_1_data_2B634__fzgx_offset_0[];
extern u8 lbl_1_data_2B644__fzgx_offset_0[];
extern u8 lbl_1_data_2B654__fzgx_offset_0[];
extern u8 lbl_1_data_2B664__fzgx_offset_0[];
extern u8 lbl_1_data_2B678__fzgx_offset_0[];
extern u8 lbl_1_data_2B68C__fzgx_offset_0[];
extern u8 lbl_1_data_2B6A0__fzgx_offset_0[];
extern u8 lbl_1_data_2B6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6E8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2B708__fzgx_offset_0[];
extern u8 lbl_1_data_2B718__fzgx_offset_0[];
extern u8 lbl_1_data_2B728__fzgx_offset_0[];
extern u8 lbl_1_data_2B738__fzgx_offset_0[];
extern u8 lbl_1_data_2B748__fzgx_offset_0[];
extern u8 lbl_1_data_2B758__fzgx_offset_0[];
extern u8 lbl_1_data_2B768__fzgx_offset_0[];
extern u8 lbl_1_data_2B77C__fzgx_offset_0[];
extern u8 lbl_1_data_2B790__fzgx_offset_0[];
extern u8 lbl_1_data_2B7A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B7B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B7CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B7E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B7F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B808__fzgx_offset_0[];
extern u8 lbl_1_data_2B81C__fzgx_offset_0[];
extern u8 lbl_1_data_2B830__fzgx_offset_0[];
extern u8 lbl_1_data_2B840__fzgx_offset_0[];
extern u8 lbl_1_data_2B850__fzgx_offset_0[];
extern u8 lbl_1_data_2B860__fzgx_offset_0[];
extern u8 lbl_1_data_2B870__fzgx_offset_0[];
extern u8 lbl_1_data_2B884__fzgx_offset_0[];
extern u8 lbl_1_data_2B894__fzgx_offset_0[];
extern u8 lbl_1_data_2B8A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B8EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B900__fzgx_offset_0[];
extern u8 lbl_1_data_2B914__fzgx_offset_0[];
extern u8 lbl_1_data_2B928__fzgx_offset_0[];
extern u8 lbl_1_data_2B93C__fzgx_offset_0[];
extern u8 lbl_1_data_2B948__fzgx_offset_0[];
extern u8 lbl_1_data_2B954__fzgx_offset_0[];
extern u8 lbl_1_data_2B960__fzgx_offset_0[];
extern u8 lbl_1_data_2B96C__fzgx_offset_0[];
extern u8 lbl_1_data_2B97C__fzgx_offset_0[];
extern u8 lbl_1_data_2B990__fzgx_offset_0[];
extern u8 lbl_1_data_2B9A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B9CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9F0__fzgx_offset_0[];
extern u8 lbl_1_data_2BA04__fzgx_offset_0[];
extern u8 lbl_1_data_2BA18__fzgx_offset_0[];
extern u8 lbl_1_data_2BA2C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA40__fzgx_offset_0[];
extern u8 lbl_1_data_2BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA58__fzgx_offset_0[];
extern u8 lbl_1_data_2BA64__fzgx_offset_0[];
extern u8 lbl_1_data_2BA70__fzgx_offset_0[];
extern u8 lbl_1_data_2BA80__fzgx_offset_0[];
extern u8 lbl_1_data_2BA94__fzgx_offset_0[];
extern u8 lbl_1_data_2BAA8__fzgx_offset_0[];
extern u8 lbl_1_data_2BABC__fzgx_offset_0[];
extern u8 lbl_1_data_2BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_2BB10__fzgx_offset_0[];
extern u8 lbl_1_data_2BB24__fzgx_offset_0[];
extern u8 lbl_1_data_2BB38__fzgx_offset_0[];
extern u8 lbl_1_data_2BB48__fzgx_offset_0[];
extern u8 lbl_1_data_2BB58__fzgx_offset_0[];
extern u8 lbl_1_data_2BB68__fzgx_offset_0[];
extern u8 lbl_1_data_2BB78__fzgx_offset_0[];
extern u8 lbl_1_data_2BB88__fzgx_offset_0[];
extern u8 lbl_1_data_2BB9C__fzgx_offset_0[];
extern u8 lbl_1_data_2BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_2BBC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BBD8__fzgx_offset_0[];
extern u8 lbl_1_data_2BBEC__fzgx_offset_0[];
extern u8 lbl_1_data_2BC00__fzgx_offset_0[];
extern u8 lbl_1_data_2BC14__fzgx_offset_0[];
extern u8 lbl_1_data_2BC28__fzgx_offset_0[];
extern u8 lbl_1_data_2BC3C__fzgx_offset_0[];
extern u8 lbl_1_data_2BC50__fzgx_offset_0[];
extern u8 lbl_1_data_2BC64__fzgx_offset_0[];
extern u8 lbl_1_data_2BC78__fzgx_offset_0[];
extern u8 lbl_1_data_2BC8C__fzgx_offset_0[];
extern u8 lbl_1_data_2BCA0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCB4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCDC__fzgx_offset_0[];
extern u8 lbl_1_data_2BCE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BCF4__fzgx_offset_0[];
extern u8 lbl_1_data_2BD00__fzgx_offset_0[];
extern u8 lbl_1_data_2BD10__fzgx_offset_0[];
extern u8 lbl_1_data_2BD20__fzgx_offset_0[];
extern u8 lbl_1_data_2BD30__fzgx_offset_0[];
extern u8 lbl_1_data_2BD40__fzgx_offset_0[];
extern u8 lbl_1_data_2C7BC__fzgx_offset_0[];
extern u8 lbl_1_data_2C7C0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E4__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E8__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F8__fzgx_offset_0[];
extern u8 lbl_1_data_2C804__fzgx_offset_0[];
extern u8 lbl_1_data_2C80C__fzgx_offset_0[];
extern u8 lbl_1_data_2C818__fzgx_offset_0[];
extern u8 lbl_1_data_2C824__fzgx_offset_0[];
extern u8 lbl_1_data_2C86C__fzgx_offset_0[];
extern u8 lbl_1_data_2C870__fzgx_offset_0[];
extern u8 lbl_1_data_2C890__fzgx_offset_0[];
extern u8 lbl_1_data_2C8B0__fzgx_offset_0[];
extern u8 lbl_1_data_2C8D0__fzgx_offset_0[];
static union { u32 w[456]; u8 v[0x720]; } fzgx_pool_init_lbl_1_data_2A0C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F43455F, 0x4C494748, 0x544D4150, 0x5F410000, 0x4F43455F, 0x57415645, 0x5F504154, 0x5F420000,
    0x4F43455F, 0x4E414D49, 0x5F000000, 0x4F434E5F, 0x504F4F4C, 0x0, 0x42494742, 0x4C55455F,
    0x52454E5A, 0x5F465245, 0x41303100, 0x1, (u32)lbl_1_data_2A0C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A0D0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A0E0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0F8__fzgx_offset_0, 0x3, 0x0, 0x5F6C746D,
    0x70000000, 0x5F6C746D, 0x70320000, 0x4F43455F, 0x43415343, 0x4144455F, 0x0, 0x4F43455F,
    0x4332375F, 0x43415343, 0x41444500, 0x43554245, 0x5F474154, 0x455F415F, 0x4C4F4400, 0x43554245,
    0x5F425F41, 0x5F4C4F44, 0x0, 0x43554245, 0x5F445F41, 0x5F4C4F44, 0x0, 0x42494742,
    0x4C55455F, 0x53554E30, 0x31000000, 0x2, (u32)lbl_1_data_2A13C__fzgx_offset_0, 0x2, (u32)lbl_1_data_2A144__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A14C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A15C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A16C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A17C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A18C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A19C__fzgx_offset_0, 0x3, 0x0, 0x5F5F5F00,
    0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3, 0x0, 0x5041544C, 0x414D505F, 0x41000000, 0x5041544C,
    0x414D505F, 0x42000000, 0x5041544C, 0x414D505F, 0x43000000, 0x5041544C, 0x414D505F, 0x44000000,
    0x424E535F, 0x534B595F, 0x4B554D4F, 0x5F000000, 0x4C49475F, 0x47524F55, 0x4E445F41, 0x0,
    0x4330385F, 0x5241494E, 0x524F4144, 0x0, 0x4330395F, 0x5241494E, 0x524F4144, 0x0,
    0x4332335F, 0x5241494E, 0x524F4144, 0x0, 0x4333345F, 0x5241494E, 0x524F4144, 0x0,
    0x52455041, 0x4952504F, 0x494E5400, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A240__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A250__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A260__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A270__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A280__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A290__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A2A0__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x464C4147, 0x0, 0x0,
    (u32)lbl_1_data_2A314__fzgx_offset_0, 0x3, 0x0, 0x464F525F, 0x4546465F, 0x48413031, 0x0, 0x464F525F,
    0x52454E5A, 0x5F465245, 0x41000000, 0x464F525F, 0x4546465F, 0x47524E4C, 0x49470000, 0x1,
    (u32)lbl_1_data_2A32C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A33C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A34C__fzgx_offset_0, 0x3, 0x0, 0x464F525F,
    0x53554E00, 0x0, (u32)lbl_1_data_2A37C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3,
    0x0, 0x535F5348, 0x49500000, 0x0, (u32)lbl_1_data_2A3C4__fzgx_offset_0, 0x3, 0x0, 0x53414E5F,
    0x57415645, 0x5F504154, 0x5F4D0000, 0x53414E5F, 0x57415645, 0x5F504154, 0x5F530000, 0x474F524F,
    0x46524147, 0x5F767478, 0x0, 0x474F524F, 0x46524147, 0x325F7674, 0x78000000, 0x1,
    (u32)lbl_1_data_2A3DC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3EC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3FC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A40C__fzgx_offset_0, 0x3,
    0x0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x44494345,
    0x0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x434F494E, 0x0, 0x0,
    (u32)lbl_1_data_2A494__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x4D45545F, 0x434F4D45, 0x54303200,
    0x4546465F, 0x524F434B, 0x46495245, 0x5F415F52, 0x32533100, 0x4546465F, 0x524F434B, 0x46495245,
    0x5F425F52, 0x32533100, 0x1, (u32)lbl_1_data_2A4B4__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4D4__fzgx_offset_0,
    0x3, 0x0, 0x4D45545F, 0x42494753, 0x54415230, 0x31000000, 0x0, (u32)lbl_1_data_2A508__fzgx_offset_0,
    0x3, 0x0, 0x3, 0x0, 0x454C565F, 0x544F5000, 0x454C565F, 0x434F4C4F,
    0x4E590000, 0x454C565F, 0x544F5745, 0x52424153, 0x4530315F, 0x415F4C4F, 0x44000000, 0x454C565F,
    0x43415247, 0x4F30315F, 0x415F4C4F, 0x44000000, 0x454C565F, 0x424F5830, 0x315F415F, 0x4C4F4400,
    0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A530__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A538__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A544__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A55C__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A570__fzgx_offset_0, 0x3, 0x0, 0x57494E44, 0x4F573031, 0x0, 0x0,
    (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x3, 0x0, 0x53454152, 0x43483031, 0x0, 0x53454152, 0x43485F41,
    0x524D3031, 0x0, 0x53454152, 0x43485F41, 0x524D3032, 0x0, 0x5343414D, 0x504F494E,
    0x54303100, 0x464C4153, 0x48303100, 0x0, (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A5EC__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A5F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A608__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A618__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A624__fzgx_offset_0, 0x3,
    0x0, 0x3, 0x0, 0x43554245, 0x0, 0x0, (u32)lbl_1_data_2A66C__fzgx_offset_0, 0x3,
    0x0, 0x4654565F, 0x4C4F474F, 0x0, 0x4654565F, 0x52494E47, 0x0, 0x4654565F,
    0x52494E47, 0x5F460000, 0x4654565F, 0x45415254, 0x48000000, 0x4654565F, 0x52494E47, 0x5F540000,
    0x0, (u32)lbl_1_data_2A684__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A690__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A69C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A6A8__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2A6B4__fzgx_offset_0, 0x3, 0x0, 0x43415244, 0x49535000, 0x47414C44, 0x49535000,
    0x57494E4E, 0x45523031, 0x0, 0x57494E4E, 0x45523032, 0x0, 0x57494E4E, 0x45523033,
    0x0, 0x57494E4E, 0x45523034, 0x0, 0x48594F55, 0x53594F55, 0x53504F54, 0x0,
    0x48594F55, 0x53594F55, 0x0, 0x4D55545F, 0x47524F55, 0x4E440000, 0x4D55545F, 0x53544152,
    0x53000000, 0x4D55545F, 0x43495459, 0x5F4C4947, 0x48545300, 0x0, (u32)lbl_1_data_2A6F0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A6F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A700__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A70C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A718__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A724__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A730__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A740__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A74C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A758__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A764__fzgx_offset_0, 0x3, 0x0, 0x0, 0x0, 0x0
}};
static union { u32 w[31]; fn_1_9AABC_state v; } fzgx_pool_init_fzgx_burner_state = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080, 0x80000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
}};
static union { u32 w[212]; u8 v[0xAEC - 0x79C]; } fzgx_pool_init_fzgx_burner_pad79C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, (u32)lbl_1_data_1E968__fzgx_offset_0,
    (u32)lbl_1_data_1E974__fzgx_offset_0, (u32)lbl_1_data_1E980__fzgx_offset_0, (u32)lbl_1_data_1E98C__fzgx_offset_0, (u32)lbl_1_data_1E998__fzgx_offset_0, (u32)lbl_1_data_1E9A4__fzgx_offset_0, (u32)lbl_1_data_1E9B0__fzgx_offset_0, (u32)lbl_1_data_1E9BC__fzgx_offset_0, (u32)lbl_1_data_1E9C8__fzgx_offset_0,
    (u32)lbl_1_data_1E9D4__fzgx_offset_0, (u32)lbl_1_data_1E9E0__fzgx_offset_0, (u32)lbl_1_data_1E9EC__fzgx_offset_0, (u32)lbl_1_data_1E9F8__fzgx_offset_0, (u32)lbl_1_data_1EA04__fzgx_offset_0, (u32)lbl_1_data_1EA10__fzgx_offset_0, (u32)lbl_1_data_1EA1C__fzgx_offset_0, (u32)lbl_1_data_1EA34__fzgx_offset_0,
    (u32)lbl_1_data_1EA40__fzgx_offset_0, (u32)lbl_1_data_1EA4C__fzgx_offset_0, (u32)lbl_1_data_1EA58__fzgx_offset_0, (u32)lbl_1_data_1EA64__fzgx_offset_0, (u32)lbl_1_data_1ED48__fzgx_offset_0, (u32)lbl_1_data_1ED54__fzgx_offset_0, (u32)lbl_1_data_1ED60__fzgx_offset_0, (u32)lbl_1_data_1ED6C__fzgx_offset_0,
    (u32)lbl_1_data_1ED78__fzgx_offset_0, (u32)lbl_1_data_1ED84__fzgx_offset_0, (u32)lbl_1_data_1ED90__fzgx_offset_0, (u32)lbl_1_data_1ED9C__fzgx_offset_0, (u32)lbl_1_data_1EDA8__fzgx_offset_0, (u32)lbl_1_data_1EDB4__fzgx_offset_0, (u32)lbl_1_data_1EDC0__fzgx_offset_0, (u32)lbl_1_data_1EDCC__fzgx_offset_0,
    (u32)lbl_1_data_1EDD8__fzgx_offset_0, (u32)lbl_1_data_1EDE4__fzgx_offset_0, (u32)lbl_1_data_1EDF0__fzgx_offset_0, (u32)lbl_1_data_1EDFC__fzgx_offset_0, (u32)lbl_1_data_1EE08__fzgx_offset_0, (u32)lbl_1_data_1EE14__fzgx_offset_0, (u32)lbl_1_data_1EE20__fzgx_offset_0, (u32)lbl_1_data_1EE2C__fzgx_offset_0,
    (u32)lbl_1_data_1EE38__fzgx_offset_0, 0x4E554C4C, 0x0, 0x4D555445, 0x20434954, 0x59000000, 0x504F5254, 0x20544F57,
    0x4E000000, 0x42494720, 0x424C5545, 0x0, 0x4C494748, 0x544E494E, 0x47000000, 0x53414E44,
    0x204F4345, 0x414E0000, 0x47524545, 0x4E20504C, 0x414E5400, 0x46495245, 0x20464945, 0x4C440000,
    0x43415349, 0x4E4F2050, 0x414C4143, 0x45000000, 0x4F555445, 0x52205350, 0x41434500, 0x4145524F,
    0x504F4C49, 0x53000000, 0x434F534D, 0x4F205445, 0x524D494E, 0x414C0000, 0x5048414E, 0x544F4D20,
    0x524F4144, 0x0, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0,
    (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9C4__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9DC__fzgx_offset_0,
    (u32)lbl_1_data_2A9EC__fzgx_offset_0, (u32)lbl_1_data_2A9F8__fzgx_offset_0, (u32)lbl_1_data_2AA04__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2AA14__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, 0x0,
    0x837E8385, 0x815B8367, 0x20835683, 0x65834200, 0x837C815B, 0x83672083, 0x5E834583, 0x93000000,  /* fzgx-allow: A1 retail data bytes */
    0x83728362, 0x834F2083, 0x75838B81, 0x5B000000, 0x83898343, 0x8367836A, 0x8393834F, 0x0,
    0x83548393, 0x83682083, 0x49815B83, 0x56838383, 0x93000000, 0x834F838A, 0x815B8393, 0x20837683,  /* fzgx-allow: A1 retail data bytes */
    0x89839383, 0x67000000, 0x83748340, 0x83438341, 0x20837483, 0x42815B83, 0x8B836800, 0x834A8357,
    0x836D2083, 0x70838C83, 0x58000000, 0x83418345, 0x835E815B, 0x20835883, 0x79815B83, 0x58000000,
    0x83478341, 0x838D837C, 0x838A8358, 0x0, 0x83528358, 0x83822083, 0x5E815B83, 0x7E836983,
    0x8B000000, 0x83748340, 0x83938367, 0x83802083, 0x8D815B83, 0x68000000, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0,
    (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0,
    (u32)lbl_1_data_2AAD0__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAF8__fzgx_offset_0, (u32)lbl_1_data_2AB08__fzgx_offset_0, (u32)lbl_1_data_2AB1C__fzgx_offset_0, (u32)lbl_1_data_2AB2C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0,
    (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AB40__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, 0x0
}};
static union { u32 w[198]; fn_1_9AABC_mode v[0x16]; } fzgx_pool_init_fzgx_burner_modes = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0,
    (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0,
    (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0,
    (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0,
    (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0,
    (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0,
    (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0,
    (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0,
    (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0,
    (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_DC204__fzgx_offset_0, (u32)fn_1_DC208__fzgx_offset_0, (u32)fn_1_DC264__fzgx_offset_0, (u32)fn_1_DC268__fzgx_offset_0, (u32)fn_1_DC2F8__fzgx_offset_0, (u32)fn_1_DC33C__fzgx_offset_0,
    (u32)fn_1_DC3A0__fzgx_offset_0, (u32)fn_1_DCB9C__fzgx_offset_0, (u32)fn_1_DCBF4__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0,
    (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0,
    (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_FA6C0__fzgx_offset_0, (u32)fn_1_FA75C__fzgx_offset_0, (u32)fn_1_FA82C__fzgx_offset_0,
    (u32)fn_1_FA830__fzgx_offset_0, (u32)fn_1_FA854__fzgx_offset_0, (u32)fn_1_FA878__fzgx_offset_0, (u32)fn_1_FA898__fzgx_offset_0, (u32)fn_1_FB770__fzgx_offset_0, (u32)fn_1_FB798__fzgx_offset_0, (u32)fn_1_FE5E0__fzgx_offset_0, (u32)fn_1_FE5E4__fzgx_offset_0,
    (u32)fn_1_FE640__fzgx_offset_0, (u32)fn_1_FE644__fzgx_offset_0, (u32)fn_1_FE780__fzgx_offset_0, (u32)fn_1_FE784__fzgx_offset_0, (u32)fn_1_FE7D4__fzgx_offset_0, (u32)fn_1_101348__fzgx_offset_0, (u32)fn_1_1013A0__fzgx_offset_0, (u32)fn_1_153988__fzgx_offset_0,
    (u32)fn_1_15398C__fzgx_offset_0, (u32)fn_1_1539D0__fzgx_offset_0, (u32)fn_1_153A28__fzgx_offset_0, (u32)fn_1_153AAC__fzgx_offset_0, (u32)fn_1_153AB0__fzgx_offset_0, (u32)fn_1_153AF4__fzgx_offset_0, (u32)fn_1_1543E8__fzgx_offset_0, (u32)fn_1_154410__fzgx_offset_0,
    (u32)fn_1_150500__fzgx_offset_0, (u32)fn_1_150518__fzgx_offset_0, (u32)fn_1_150570__fzgx_offset_0, (u32)fn_1_1505B4__fzgx_offset_0, (u32)fn_1_150574__fzgx_offset_0, (u32)fn_1_150608__fzgx_offset_0, (u32)fn_1_150650__fzgx_offset_0, (u32)fn_1_151764__fzgx_offset_0,
    (u32)fn_1_15176C__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0,
    (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0,
    (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1586A8__fzgx_offset_0, (u32)fn_1_1586AC__fzgx_offset_0, (u32)fn_1_158980__fzgx_offset_0, (u32)fn_1_158984__fzgx_offset_0, (u32)fn_1_15903C__fzgx_offset_0,
    (u32)fn_1_159040__fzgx_offset_0, (u32)fn_1_159060__fzgx_offset_0, (u32)fn_1_159064__fzgx_offset_0, (u32)fn_1_15906C__fzgx_offset_0, (u32)fn_1_15B428__fzgx_offset_0, (u32)fn_1_15B42C__fzgx_offset_0, (u32)fn_1_15B4F8__fzgx_offset_0, (u32)fn_1_15B4FC__fzgx_offset_0,
    (u32)fn_1_15B51C__fzgx_offset_0, (u32)fn_1_15B520__fzgx_offset_0, (u32)fn_1_15B540__fzgx_offset_0, (u32)fn_1_15B698__fzgx_offset_0, (u32)fn_1_15B70C__fzgx_offset_0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0
}};
static union { u32 w[44]; u8 v[0xEB4 - 0xE04]; } fzgx_pool_init_fzgx_burner_padE04 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x62675F6D, 0x75740000, 0x62675F70, 0x6F720000, 0x62675F70, 0x6F725F73, 0x0, 0x62675F62,
    0x69670000, 0x62675F62, 0x69675F73, 0x0, 0x62675F6C, 0x69670000, 0x62675F73, 0x616E0000,
    0x62675F73, 0x616E5F73, 0x0, 0x62675F66, 0x6F720000, 0x62675F66, 0x69720000, 0x62675F66,
    0x69725F73, 0x0, 0x62675F63, 0x61730000, 0x62675F6D, 0x65740000, 0x62675F74, 0x6F770000,
    0x62675F65, 0x6C650000, 0x62675F63, 0x6F6D0000, 0x62675F63, 0x6F6D5F73, 0x0, 0x62675F72,
    0x61690000, 0x62675F77, 0x696E5F67, 0x78000000
}};
static union { u32 w[22]; void *v[0x16]; } fzgx_pool_init_fzgx_burner_entries = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_1_data_2AEC4__fzgx_offset_0, (u32)lbl_1_data_2AECC__fzgx_offset_0, (u32)lbl_1_data_2AED4__fzgx_offset_0, (u32)lbl_1_data_2AEE0__fzgx_offset_0, (u32)lbl_1_data_2AEE8__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0,
    (u32)lbl_1_data_2AEFC__fzgx_offset_0, (u32)lbl_1_data_2AF04__fzgx_offset_0, (u32)lbl_1_data_2AF10__fzgx_offset_0, (u32)lbl_1_data_2AF18__fzgx_offset_0, (u32)lbl_1_data_2AF20__fzgx_offset_0, (u32)lbl_1_data_2AF2C__fzgx_offset_0, (u32)lbl_1_data_2AF34__fzgx_offset_0, (u32)lbl_1_data_2AF3C__fzgx_offset_0,
    (u32)lbl_1_data_2AF44__fzgx_offset_0, (u32)lbl_1_data_2AF4C__fzgx_offset_0, (u32)lbl_1_data_2AF54__fzgx_offset_0, (u32)lbl_1_data_2AF60__fzgx_offset_0, (u32)lbl_1_data_2AF68__fzgx_offset_0, 0x0
}};
static union { u32 w[22]; u32 v[0x16]; } fzgx_pool_init_fzgx_burner_work_sizes = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x4, 0x202C0, 0x202C0, 0x18B0, 0x18B0, 0xFD80, 0xFD80,
    0x1C60, 0x1C60, 0x226C, 0x764, 0x764, 0x174, 0x1B1E8, 0x1704,
    0x2748, 0x4, 0x4, 0x157CC, 0x128, 0x0
}};
static union { u32 w[22]; void *v[0x16]; } fzgx_pool_init_fzgx_burner_filters = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0,
    (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A35C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A484__fzgx_offset_0, (u32)lbl_1_data_2A4E8__fzgx_offset_0, (u32)lbl_1_data_2A5DC__fzgx_offset_0,
    (u32)lbl_1_data_2A528__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A664__fzgx_offset_0, (u32)lbl_1_data_2A6C0__fzgx_offset_0, 0x0
}};
static union { u32 w[22]; u32 v[0x16]; } fzgx_pool_init_fzgx_burner_padFBC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0,
    (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A384__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A49C__fzgx_offset_0, (u32)lbl_1_data_2A518__fzgx_offset_0, (u32)lbl_1_data_2A62C__fzgx_offset_0,
    (u32)lbl_1_data_2A580__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A674__fzgx_offset_0, (u32)lbl_1_data_2A774__fzgx_offset_0, 0x0
}};
static union { u32 w[28]; u8 v[0x70]; } fzgx_pool_init_fzgx_burner_indices = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8010101, 0x10F0202, 0x6060A0A, 0x602040B, 0xD0B0B0E, 0xE0F1006, 0x10080804, 0x130D080F,
    0xE02060A, 0x1112090D, 0x5070301, 0xC130000, 0x141400, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0
}};
static union { u32 w[1671]; u8 v[0x2AA0 - 0x1084]; } fzgx_pool_init_fzgx_burner_pad1084 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10202, 0x3030404, 0x5050607, 0x708090A, 0xB0C0C0D, 0x1000000, 0x2D2D2D00, 0x54776973,
    0x7420526F, 0x61640000, 0x53657269, 0x616C2047, 0x61707300, 0x4D756C74, 0x69706C65, 0x78000000,
    0x4165726F, 0x20446976, 0x65000000, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x48616C66, 0x20506970,
    0x65000000, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x4D6F6269, 0x75732052, 0x696E6700,
    0x4C6F6E67, 0x20506970, 0x65000000, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x43796C69,
    0x6E646572, 0x204B6E6F, 0x74000000, 0x53706C69, 0x74204F76, 0x616C0000, 0x556E6475, 0x6C617469,
    0x6F6E0000, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x54726964, 0x656E7400, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x4F726465,
    0x616C0000, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x446F7562, 0x6C652042, 0x72616E63,
    0x68657300, 0x53637265, 0x77204472, 0x69766500, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000,
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x5468756E, 0x64657220, 0x526F6164, 0x0,
    0x53706972, 0x616C0000, 0x536F6E69, 0x63204F76, 0x616C0000, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B1A8__fzgx_offset_0,
    (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B230__fzgx_offset_0,
    (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2B294__fzgx_offset_0,
    (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, 0x96A292E8, 0x0, 0x47455220, 0x54776973,
    0x7420526F, 0x61640000, 0x46524520, 0x54776973, 0x7420526F, 0x61640000, 0x53504120, 0x54776973,
    0x7420526F, 0x61640000, 0x49544120, 0x54776973, 0x7420526F, 0x61640000, 0x83638343, 0x83588367,
    0x838D815B, 0x83680000, 0x47455220, 0x53657269, 0x616C2047, 0x61707300, 0x46524520, 0x53657269,
    0x616C2047, 0x61707300, 0x53504120, 0x53657269, 0x616C2047, 0x61707300, 0x49544120, 0x53657269,
    0x616C2047, 0x61707300, 0x8356838A, 0x8341838B, 0x834D8383, 0x83628376, 0x0, 0x47455220,
    0x4D756C74, 0x69706C65, 0x78000000, 0x46524520, 0x4D756C74, 0x69706C65, 0x78000000, 0x53504120,
    0x4D756C74, 0x69706C65, 0x78000000, 0x49544120, 0x4D756C74, 0x69706C65, 0x78000000, 0x837D838B,
    0x83608376, 0x838C8362, 0x834E8358, 0x0, 0x47455220, 0x4165726F, 0x20446976, 0x65000000,
    0x46524520, 0x4165726F, 0x20446976, 0x65000000, 0x53504120, 0x4165726F, 0x20446976, 0x65000000,
    0x49544120, 0x4165726F, 0x20446976, 0x65000000, 0x83478341, 0x838D835F, 0x83438375, 0x0,
    0x47455220, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x46524520, 0x4C6F6F70, 0x2043726F, 0x73730000,
    0x53504120, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x49544120, 0x4C6F6F70, 0x2043726F, 0x73730000,
    0x838B815B, 0x8376834E, 0x838D8358, 0x0, 0x47455220, 0x48616C66, 0x20506970, 0x65000000,
    0x46524520, 0x48616C66, 0x20506970, 0x65000000, 0x53504120, 0x48616C66, 0x20506970, 0x65000000,
    0x49544120, 0x48616C66, 0x20506970, 0x65000000, 0x836E815B, 0x83748370, 0x83438376, 0x0,
    0x47455220, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x46524520, 0x496E7465, 0x72736563,
    0x74696F6E, 0x0, 0x53504120, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x49544120,
    0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x83438393, 0x835E815B, 0x835A834E, 0x83568387,
    0x83930000, 0x47455220, 0x4D6F6269, 0x75732052, 0x696E6700, 0x46524520, 0x4D6F6269, 0x75732052,
    0x696E6700, 0x53504120, 0x4D6F6269, 0x75732052, 0x696E6700, 0x49544120, 0x4D6F6269, 0x75732052,
    0x696E6700, 0x83818372, 0x83458358, 0x838A8393, 0x834F0000, 0x47455220, 0x4C6F6E67, 0x20506970,
    0x65000000, 0x46524520, 0x4C6F6E67, 0x20506970, 0x65000000, 0x53504120, 0x4C6F6E67, 0x20506970,
    0x65000000, 0x49544120, 0x4C6F6E67, 0x20506970, 0x65000000, 0x838D8393, 0x834F8370, 0x83438376,
    0x0, 0x47455220, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x46524520, 0x44726966,
    0x74204869, 0x67687761, 0x79000000, 0x53504120, 0x44726966, 0x74204869, 0x67687761, 0x79000000,
    0x49544120, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x8368838A, 0x83748367, 0x836E8343,
    0x83458346, 0x83430000, 0x47455220, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x46524520,
    0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x53504120, 0x43796C69, 0x6E646572, 0x204B6E6F,
    0x74000000, 0x49544120, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x8356838A, 0x8393835F,
    0x815B836D, 0x83628367, 0x0, 0x47455220, 0x53706C69, 0x74204F76, 0x616C0000, 0x46524520,  /* fzgx-allow: A1 retail data bytes */
    0x53706C69, 0x74204F76, 0x616C0000, 0x53504120, 0x53706C69, 0x74204F76, 0x616C0000, 0x49544120,
    0x53706C69, 0x74206F76, 0x616C0000, 0x83588376, 0x838A8362, 0x83678349, 0x815B836F, 0x838B0000,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x46524520, 0x556E6475, 0x6C617469, 0x6F6E0000,
    0x53504120, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x49544120, 0x556E6475, 0x6C617469, 0x6F6E0000,
    0x83418393, 0x83668385, 0x838C815B, 0x83568387, 0x83930000, 0x47455220, 0x44726167, 0x6F6E2053,
    0x6C6F7065, 0x0, 0x46524520, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x53504120,
    0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x49544120, 0x44726167, 0x6F6E2053, 0x6C6F7065,
    0x0, 0x83688389, 0x83538393, 0x8358838D, 0x815B8376, 0x0, 0x47455220, 0x54726964,  /* fzgx-allow: A1 retail data bytes */
    0x656E7400, 0x46524520, 0x54726964, 0x656E7400, 0x53504120, 0x54726964, 0x656E7400, 0x49544120,
    0x54726964, 0x656E7400, 0x83678389, 0x83438366, 0x83938367, 0x0, 0x47455220, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x46524520, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000,
    0x53504120, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x49544120, 0x4C617465, 0x72616C20,
    0x53686966, 0x74000000, 0x83898365, 0x8389838B, 0x83568374, 0x83670000, 0x47455220, 0x53757266,
    0x61636520, 0x536C6964, 0x65000000, 0x46524520, 0x53757266, 0x61636520, 0x536C6964, 0x65000000,
    0x53504120, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x49544120, 0x53757266, 0x61636520,
    0x536C6964, 0x65000000, 0x8354815B, 0x83748346, 0x83588358, 0x83898343, 0x83680000, 0x47455220,
    0x4F726465, 0x616C0000, 0x46524520, 0x4F726465, 0x616C0000, 0x53504120, 0x4F726465, 0x616C0000,
    0x49544120, 0x4F726465, 0x616C0000, 0x8349815B, 0x83668342, 0x815B838B, 0x0, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x46524520, 0x536C696D, 0x2D6C696E, 0x6520536C,
    0x69747300, 0x53504120, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x49544120, 0x536C696D,
    0x2D6C696E, 0x6520536C, 0x69747300, 0x8358838A, 0x83808389, 0x83438393, 0x8358838A, 0x83628367,
    0x0, 0x47455220, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x46524520, 0x446F7562,
    0x6C652042, 0x72616E63, 0x68657300, 0x53504120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300,
    0x49544120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x835F8375, 0x838B8375, 0x83898393,
    0x83600000, 0x47455220, 0x53637265, 0x77204472, 0x69766500, 0x46524520, 0x53637265, 0x77204472,
    0x69766500, 0x53504120, 0x53637265, 0x77204472, 0x69766500, 0x49544120, 0x53637265, 0x77204472,
    0x69766500, 0x8358834E, 0x838A8385, 0x815B8368, 0x83898343, 0x83750000, 0x47455220, 0x4D657465,  /* fzgx-allow: A1 retail data bytes */
    0x6F722053, 0x74726561, 0x6D000000, 0x46524520, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000,
    0x53504120, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000, 0x49544120, 0x4D657465, 0x6F722053,
    0x74726561, 0x6D000000, 0x83818365, 0x83498358, 0x8367838A, 0x815B8380, 0x0, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x46524520, 0x43796C69, 0x6E646572, 0x20576176,
    0x65000000, 0x53504120, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x49544120, 0x43796C69,
    0x6E646572, 0x20576176, 0x65000000, 0x8356838A, 0x8393835F, 0x815B8345, 0x8346815B, 0x83750000,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x46524520, 0x5468756E, 0x64657220,
    0x526F6164, 0x0, 0x53504120, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x49544120,
    0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x83548393, 0x835F815B, 0x838D815B, 0x83680000,
    0x47455220, 0x53706972, 0x616C0000, 0x46524520, 0x53706972, 0x616C0000, 0x53504120, 0x53706972,
    0x616C0000, 0x49544120, 0x53706972, 0x616C0000, 0x83588370, 0x83438389, 0x838B0000, 0x47455220,
    0x536F6E69, 0x63204F76, 0x616C0000, 0x46524520, 0x536F6E69, 0x63204F76, 0x616C0000, 0x53504120,
    0x536F6E69, 0x63204F76, 0x616C0000, 0x49544120, 0x536F6E69, 0x63204F76, 0x616C0000, 0x835C836A,
    0x8362834E, 0x8349815B, 0x836F838B, 0x0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B47C__fzgx_offset_0, (u32)lbl_1_data_2B48C__fzgx_offset_0, (u32)lbl_1_data_2B49C__fzgx_offset_0, (u32)lbl_1_data_2B4AC__fzgx_offset_0, (u32)lbl_1_data_2B4BC__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B4CC__fzgx_offset_0,
    (u32)lbl_1_data_2B4DC__fzgx_offset_0, (u32)lbl_1_data_2B4EC__fzgx_offset_0, (u32)lbl_1_data_2B4FC__fzgx_offset_0, (u32)lbl_1_data_2B50C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B520__fzgx_offset_0, (u32)lbl_1_data_2B530__fzgx_offset_0, (u32)lbl_1_data_2B540__fzgx_offset_0, (u32)lbl_1_data_2B550__fzgx_offset_0, (u32)lbl_1_data_2B560__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B574__fzgx_offset_0,
    (u32)lbl_1_data_2B584__fzgx_offset_0, (u32)lbl_1_data_2B594__fzgx_offset_0, (u32)lbl_1_data_2B5A4__fzgx_offset_0, (u32)lbl_1_data_2B5B4__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B5C4__fzgx_offset_0, (u32)lbl_1_data_2B5D4__fzgx_offset_0, (u32)lbl_1_data_2B5E4__fzgx_offset_0,
    (u32)lbl_1_data_2B5F4__fzgx_offset_0, (u32)lbl_1_data_2B604__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B614__fzgx_offset_0, (u32)lbl_1_data_2B624__fzgx_offset_0, (u32)lbl_1_data_2B634__fzgx_offset_0, (u32)lbl_1_data_2B644__fzgx_offset_0, (u32)lbl_1_data_2B654__fzgx_offset_0,
    (u32)lbl_1_data_2B1A8__fzgx_offset_0, (u32)lbl_1_data_2B664__fzgx_offset_0, (u32)lbl_1_data_2B678__fzgx_offset_0, (u32)lbl_1_data_2B68C__fzgx_offset_0, (u32)lbl_1_data_2B6A0__fzgx_offset_0, (u32)lbl_1_data_2B6B4__fzgx_offset_0, (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B6C8__fzgx_offset_0,
    (u32)lbl_1_data_2B6D8__fzgx_offset_0, (u32)lbl_1_data_2B6E8__fzgx_offset_0, (u32)lbl_1_data_2B6F8__fzgx_offset_0, (u32)lbl_1_data_2B708__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B718__fzgx_offset_0, (u32)lbl_1_data_2B728__fzgx_offset_0, (u32)lbl_1_data_2B738__fzgx_offset_0, (u32)lbl_1_data_2B748__fzgx_offset_0, (u32)lbl_1_data_2B758__fzgx_offset_0,
    (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B768__fzgx_offset_0, (u32)lbl_1_data_2B77C__fzgx_offset_0, (u32)lbl_1_data_2B790__fzgx_offset_0, (u32)lbl_1_data_2B7A4__fzgx_offset_0, (u32)lbl_1_data_2B7B8__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B7CC__fzgx_offset_0,
    (u32)lbl_1_data_2B7E0__fzgx_offset_0, (u32)lbl_1_data_2B7F4__fzgx_offset_0, (u32)lbl_1_data_2B808__fzgx_offset_0, (u32)lbl_1_data_2B81C__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B830__fzgx_offset_0, (u32)lbl_1_data_2B840__fzgx_offset_0, (u32)lbl_1_data_2B850__fzgx_offset_0,
    (u32)lbl_1_data_2B860__fzgx_offset_0, (u32)lbl_1_data_2B870__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B884__fzgx_offset_0, (u32)lbl_1_data_2B894__fzgx_offset_0, (u32)lbl_1_data_2B8A4__fzgx_offset_0, (u32)lbl_1_data_2B8B4__fzgx_offset_0, (u32)lbl_1_data_2B8C4__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B8D8__fzgx_offset_0, (u32)lbl_1_data_2B8EC__fzgx_offset_0, (u32)lbl_1_data_2B900__fzgx_offset_0, (u32)lbl_1_data_2B914__fzgx_offset_0, (u32)lbl_1_data_2B928__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B93C__fzgx_offset_0, (u32)lbl_1_data_2B948__fzgx_offset_0, (u32)lbl_1_data_2B954__fzgx_offset_0,
    (u32)lbl_1_data_2B960__fzgx_offset_0, (u32)lbl_1_data_2B96C__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B97C__fzgx_offset_0, (u32)lbl_1_data_2B990__fzgx_offset_0, (u32)lbl_1_data_2B9A4__fzgx_offset_0, (u32)lbl_1_data_2B9B8__fzgx_offset_0, (u32)lbl_1_data_2B9CC__fzgx_offset_0,
    (u32)lbl_1_data_2B230__fzgx_offset_0, (u32)lbl_1_data_2B9DC__fzgx_offset_0, (u32)lbl_1_data_2B9F0__fzgx_offset_0, (u32)lbl_1_data_2BA04__fzgx_offset_0, (u32)lbl_1_data_2BA18__fzgx_offset_0, (u32)lbl_1_data_2BA2C__fzgx_offset_0, (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2BA40__fzgx_offset_0,
    (u32)lbl_1_data_2BA4C__fzgx_offset_0, (u32)lbl_1_data_2BA58__fzgx_offset_0, (u32)lbl_1_data_2BA64__fzgx_offset_0, (u32)lbl_1_data_2BA70__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2BA80__fzgx_offset_0, (u32)lbl_1_data_2BA94__fzgx_offset_0, (u32)lbl_1_data_2BAA8__fzgx_offset_0,
    (u32)lbl_1_data_2BABC__fzgx_offset_0, (u32)lbl_1_data_2BAD0__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2BAE8__fzgx_offset_0, (u32)lbl_1_data_2BAFC__fzgx_offset_0, (u32)lbl_1_data_2BB10__fzgx_offset_0, (u32)lbl_1_data_2BB24__fzgx_offset_0, (u32)lbl_1_data_2BB38__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2BB48__fzgx_offset_0,
    (u32)lbl_1_data_2BB58__fzgx_offset_0, (u32)lbl_1_data_2BB68__fzgx_offset_0, (u32)lbl_1_data_2BB78__fzgx_offset_0, (u32)lbl_1_data_2BB88__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2BB9C__fzgx_offset_0, (u32)lbl_1_data_2BBB0__fzgx_offset_0, (u32)lbl_1_data_2BBC4__fzgx_offset_0,
    (u32)lbl_1_data_2BBD8__fzgx_offset_0, (u32)lbl_1_data_2BBEC__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2BC00__fzgx_offset_0, (u32)lbl_1_data_2BC14__fzgx_offset_0, (u32)lbl_1_data_2BC28__fzgx_offset_0, (u32)lbl_1_data_2BC3C__fzgx_offset_0, (u32)lbl_1_data_2BC50__fzgx_offset_0,
    (u32)lbl_1_data_2B294__fzgx_offset_0, (u32)lbl_1_data_2BC64__fzgx_offset_0, (u32)lbl_1_data_2BC78__fzgx_offset_0, (u32)lbl_1_data_2BC8C__fzgx_offset_0, (u32)lbl_1_data_2BCA0__fzgx_offset_0, (u32)lbl_1_data_2BCB4__fzgx_offset_0, (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2BCC4__fzgx_offset_0,
    (u32)lbl_1_data_2BCD0__fzgx_offset_0, (u32)lbl_1_data_2BCDC__fzgx_offset_0, (u32)lbl_1_data_2BCE8__fzgx_offset_0, (u32)lbl_1_data_2BCF4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0,
    (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0, (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, 0x1020304, 0x10203,
    0x4050607, 0x8090A0B, 0xC0D0E0F, 0x10111213, 0x14151617, 0x18191A1B, 0x1C1D1E1F, 0x20212223,
    0x10200, 0x10203, 0x4050600, 0x10203, 0x4050607, 0x42494746, 0x49534830, 0x31000000,
    0x574F524D, 0x0, 0x4B494E47, 0x5F434F42, 0x52410000, 0x53414E44, 0x5F464953, 0x48000000,
    0x53414E44, 0x5F424952, 0x44000000, (u32)lbl_1_data_2C7F8__fzgx_offset_0, 0x3, (u32)lbl_1_data_2C7BC__fzgx_offset_0, (u32)lbl_1_data_2C804__fzgx_offset_0, 0x9,
    (u32)lbl_1_data_2C7C0__fzgx_offset_0, (u32)lbl_1_data_2C80C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2C7E4__fzgx_offset_0, (u32)lbl_1_data_2C818__fzgx_offset_0, 0x1, (u32)lbl_1_data_2C7E8__fzgx_offset_0, (u32)lbl_1_data_2C824__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2C7F0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x44610000, 0x102,
    0x1, (u32)lbl_1_data_2C870__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43C80000, 0x102,
    0x1, (u32)lbl_1_data_2C890__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43480000, 0x102,
    0x1, (u32)lbl_1_data_2C8B0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x447A0000, 0x0,
    (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43FA0000, 0x3, 0x2, (u32)lbl_1_data_2C8D0__fzgx_offset_0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43480000, 0x43960000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43480000, 0x43C80000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x42C80000, 0x43480000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1, 0x43960000, 0x44160000, 0x1,
    0x1, 0x43FA0000, 0x447A0000, 0x1, 0x1, 0x43480000, 0x43C80000, 0x1,
    0x1, 0x43480000, 0x43C80000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43FA0000, 0x442F0000, 0x1, 0x1, 0x43C80000, 0x44480000, 0x0,
    0x1, 0x44BB8000, 0x451C4000, 0x0, 0x1, 0x447A0000, 0x44BB8000, 0x0,
    0x1, 0x447A0000, 0x44BB8000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x42C80000, 0x43480000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x43FA0000, 0x447A0000, 0x0,
    0x1, 0x43480000, 0x43C80000, 0x0, 0x1, 0x43FA0000, 0x447A0000, 0x1,
    0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1, 0x42C80000, 0x43480000, 0x1,
    0x1, 0x42C80000, 0x43960000, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x1, 0x43480000, 0x43FA0000, 0x1, 0x1, 0x43FA0000, 0x447A0000, 0x0,
    0x1, 0x451C4000, 0x453B8000, 0x1, 0x1, 0x43960000, 0x44160000, 0x1,
    0x1, 0x43480000, 0x43960000, 0x0, 0x1, 0x447A0000, 0x44FA0000
}};
static union { u32 w[4]; char v[0x10]; } fzgx_pool_init_fzgx_burner_file = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6261636B, 0x67726F75, 0x6E642E63, 0x0
}};
static union { u32 w[3]; char v[0xC]; } fzgx_pool_init_fzgx_burner_string_a = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732573, 0x2E74706C, 0x2E6C7A00
}};
static union { u32 w[1]; char v[0x4]; } fzgx_pool_init_fzgx_burner_string_b = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x62672F00
}};
static union { u32 w[1]; char v[0x4]; } fzgx_pool_init_fzgx_burner_string_c = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732573
}};

extern void *lbl_801A6410;
extern void *lbl_1_bss_384B8;
extern void *lbl_1_bss_384B4;
extern u32 lbl_1_bss_6EA50;
extern u32 lbl_1_bss_6EA54;

extern void sprintf(void *buffer, const char *format, const char *arg, ...);
extern void fn_1_46B4(void *heap, void *ptr, const char *file, int line);
extern void *fn_1_4630(void *heap, u32 size, const char *file, int line);
extern void *fn_1_45D0(void *heap, u32 size, const char *file, int line);
extern void fn_1_103054(void);
extern void fn_1_9D2EC(void);
extern u8 fn_1_7B074(void);
extern void *fn_1_D3A4C(void *name);
extern void *fn_1_D3768(void *name, void *archive);
extern u32 fn_80077D40(void *archive);
extern u32 fn_80077BD4(void *archive);
extern void fn_1_9CF78(void *filter, u32 callback);
extern void fn_1_9D994(int mode);

void fn_1_9AABC(int mode) {
    s32 index = fzgx_pool_init_fzgx_burner_indices.v[mode];
    void *entry;
    u8 buffer_b[0x20];
    u8 buffer_a[0x20];

    if (fzgx_pool_init_fzgx_burner_state.v.current == index) {
        return;
    }

    if (fzgx_pool_init_fzgx_burner_state.v.buffer != 0) {
        fn_1_46B4(lbl_801A6410, fzgx_pool_init_fzgx_burner_state.v.buffer, fzgx_pool_init_fzgx_burner_file.v, 0x281);
        fzgx_pool_init_fzgx_burner_state.v.buffer = 0;
    }
    fn_1_103054();
    if (fzgx_pool_init_fzgx_burner_state.v.current > 0) {
        fzgx_pool_init_fzgx_burner_modes.v[fzgx_pool_init_fzgx_burner_state.v.current].leave();
    }
    if (fzgx_pool_init_fzgx_burner_state.v.work != 0) {
        fn_1_46B4(lbl_801A6410, fzgx_pool_init_fzgx_burner_state.v.work, fzgx_pool_init_fzgx_burner_file.v, 0x28F);
        fzgx_pool_init_fzgx_burner_state.v.work = 0;
    }
    if (lbl_1_bss_384B8 != 0 || lbl_1_bss_384B4 != 0) {
        fn_1_9D2EC();
    }
    fzgx_pool_init_fzgx_burner_state.v.unk38 = 0;
    fzgx_pool_init_fzgx_burner_state.v.current = -1;

    if (index > 0 && (entry = fzgx_pool_init_fzgx_burner_entries.v[index]) != 0 && !fn_1_7B074()) {
        sprintf(buffer_b, fzgx_pool_init_fzgx_burner_string_a.v, fzgx_pool_init_fzgx_burner_string_b.v, entry);
        sprintf(buffer_a, fzgx_pool_init_fzgx_burner_string_c.v, fzgx_pool_init_fzgx_burner_string_b.v, entry);
        lbl_1_bss_6EA50 = fn_80077D40(lbl_1_bss_384B8 = fn_1_D3A4C(buffer_b));
        lbl_1_bss_6EA54 = fn_80077BD4(lbl_1_bss_384B4 = fn_1_D3768(buffer_a, lbl_1_bss_384B8));
        if (lbl_1_bss_384B8 == 0 || lbl_1_bss_384B4 == 0) {
            fn_1_9D2EC();
            index = 0;
        }
    }

    if (index > 0) {
        if (fzgx_pool_init_fzgx_burner_work_sizes.v[index] != 0) {
            fzgx_pool_init_fzgx_burner_state.v.work = fn_1_4630(lbl_801A6410, fzgx_pool_init_fzgx_burner_work_sizes.v[index], fzgx_pool_init_fzgx_burner_file.v, 0x26E);
            fn_1_9CF78(fzgx_pool_init_fzgx_burner_filters.v[index], fzgx_pool_init_fzgx_burner_modes.v[index].filter);
        }
        fzgx_pool_init_fzgx_burner_modes.v[index].enter();
    }
    fzgx_pool_init_fzgx_burner_state.v.buffer = fn_1_45D0(lbl_801A6410, 0x5A0, fzgx_pool_init_fzgx_burner_file.v, 0x278);
    fn_1_9D994(mode);
    fzgx_pool_init_fzgx_burner_state.v.current = index;
}
/* fzgx:end fn_1_9AABC */

/* fzgx:begin fn_1_9AD20 */
void fn_1_9AD20(void) {
    fn_1_9AF80(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48, 1);
}
/* fzgx:end fn_1_9AD20 */

/* fzgx:begin fn_1_9AD54 */
void fn_1_9AD54(void) {
    fn_1_9AF80(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48, 0);
}
/* fzgx:end fn_1_9AD54 */

/* fzgx:begin fn_1_9AD88 */
// Seed the temporary value, then notify the active burner using its shared state.
void fn_1_9AD88(void) {
    u32 value = lbl_1_rodata_4210;

    fn_80007AB4(&value);
    fn_1_9CC6C((void *)lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48);
}
/* fzgx:end fn_1_9AD88 */

/* fzgx:begin fn_1_9ADCC */
typedef struct {
    u8 pad_0[0x8];
    u8 unk_8;
    u8 unk_9;
    u8 pad_A;
    s8 unk_B;
    s32 slots[4];
} BurnerEntry;

typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
} BurnerParent;

void fn_1_9ADCC(Obj_1_data_2A7E0_At3C *arg0, s32 arg1) {
    s32 i;
    BurnerEntry *entry;
    s32 *slotp;
    s32 value;
    u32 temp_word;
    u8 temp[3];
    u32 ret;

    entry = (BurnerEntry *)arg0->unk_C;
    i = 0;
    while (i < (s32)arg0->unk_8) {
        if ((entry->unk_9 & lbl_1_data_2A7E0.unk_48) != 0 &&
            (arg1 == 0 || entry->unk_B >= 0)) {
            slotp = &entry->slots[lbl_1_data_2A7E0.unk_60];
            if (*slotp == -1) {
                if (arg1 == 0) {
                    if (entry->unk_B < 0) {
                        value = 1;
                    } else {
                        value = 0;
                    }
                } else {
                    fn_1_862D4(lbl_1_data_2A7E0.unk_5C, &temp_word);
                    if ((1 << (entry->unk_B + 0x10)) & fn_1_1FB80(&temp_word, -65536)) {
                        value = 1;
                    } else {
                        value = 0;
                    }
                }
                if (value) {
                    s32 j;
                    BurnerEntry *scan;
                    s32 slot;
                    u8 c;

                    scan = (BurnerEntry *)arg0->unk_C;
                    j = 0;
                    while (j < (s32)arg0->unk_8) {
                        slot = lbl_1_data_2A7E0.unk_60;
                        if (scan->slots[slot] >= 0) {
                            if ((scan->unk_9 & 1) != 0) {
                                scan->slots[slot] = -2;
                            } else {
                                scan->slots[slot] = -1;
                            }
                        }
                        j++;
                        scan = (BurnerEntry *)((u8 *)scan + 0x1c);
                    }
                    *slotp = 0;
                    arg0 = (Obj_1_data_2A7E0_At3C *)arg0->unk_4;
                    c = entry->unk_8;
                    temp[0] = 0x4d;
                    temp[1] = (u8)(c + 0x30);
                    temp[2] = 0;
                    ret = fn_1_41488(((BurnerParent *)arg0)->unk_24, temp);
                    if (ret == 0xffffffff) {
                        ret = 0;
                    }
                    fn_1_4270C(arg0, 0, ret & 0xffff);
                    return;
                }
            }
        }
        i++;
        entry = (BurnerEntry *)((u8 *)entry + 0x1c);
    }
}
/* fzgx:end fn_1_9ADCC */

/* fzgx:begin fn_1_9AF80 noprologue */
#include "types.h"
#include "fpscr.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 6885000.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table6[2] = {0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 60.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 1.0;
    s = 182.04444885253906f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct fn_1_9AF80_Vec {
    f32 x, y, z;
} fn_1_9AF80_Vec;

/* one keyframe track: a cursor per player slot, then the key list */
typedef struct fn_1_9AF80_Track {
    s32 cursor[4];
    u32 count;
    void *keys;
} fn_1_9AF80_Track;

typedef struct fn_1_9AF80_Anim {
    f32 start;                      /* 0x00 */
    f32 end;                        /* 0x04 */
    s32 frame[4];                   /* 0x08 */
    u32 mask;                       /* 0x18 */
    fn_1_9AF80_Track scale[3];      /* 0x1C */
    fn_1_9AF80_Track rot[3];        /* 0x64 */
    fn_1_9AF80_Track pos[3];        /* 0xAC */
    fn_1_9AF80_Track visible;       /* 0xF4 */
    fn_1_9AF80_Track alpha;         /* 0x10C */
} fn_1_9AF80_Anim;

typedef struct fn_1_9AF80_Entry {
    s32 lo;
    s32 hi;
    u8 unk_8;
    u8 unk_9;
    u8 pad_A;
    s8 hold;
    s32 frame[4];
} fn_1_9AF80_Entry;

typedef struct fn_1_9AF80_Owner {
    u8 pad_0[0x4C];
    f32 frame;
} fn_1_9AF80_Owner;

typedef struct fn_1_9AF80_List {
    u32 unk_0;
    fn_1_9AF80_Owner *owner;
    s32 count;
    fn_1_9AF80_Entry *entries;
} fn_1_9AF80_List;

typedef struct fn_1_9AF80_Dest {
    u8 pad_0[0x10];
    fn_1_9AF80_Vec pos;
    s16 rot[3];
    fn_1_9AF80_Vec scale;
} fn_1_9AF80_Dest;

typedef struct fn_1_9AF80_Sub {
    u8 pad_0[0x8];
    u32 unk_8;
} fn_1_9AF80_Sub;

typedef struct fn_1_9AF80_Model {
    u8 pad_0[0x8];
    fn_1_9AF80_Sub *sub;
    u32 *flags;
} fn_1_9AF80_Model;

typedef struct fn_1_9AF80_Obj {
    u32 flags;                      /* 0x00 */
    u32 unk_4;
    fn_1_9AF80_Model *model;        /* 0x08 */
    fn_1_9AF80_Vec pos;             /* 0x0C */
    s16 rot[3];                     /* 0x18 */
    u16 mode;                       /* 0x1E */
    fn_1_9AF80_Vec scale;           /* 0x20 */
    f32 alpha;                      /* 0x2C */
    fn_1_9AF80_Anim *anim;          /* 0x30 */
    fn_1_9AF80_Dest *dest;          /* 0x34 */
    fn_1_9AF80_List *list;          /* 0x38 */
    u32 unk_3C;
} fn_1_9AF80_Obj;

extern s8 fn_1_86624(void);
extern void fn_1_9ADCC(Obj_1_data_2A7E0_At3C *list, s32 arg1);
extern void fn_1_42E74(void *object);
extern void fn_1_862D4(u32 index, void *out);
extern u32 fn_1_1FB80(void *pos, s32 mask);
extern f32 fn_1_9E170(u32 count, void *keys, s32 *cursor, f32 t);

static inline void fn_1_9AF80_tick(s32 *frame, s32 start, s32 end, s32 hold, s32 wrap) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (frame[i] != -1 && frame[i] != -2) {
            frame[i]++;
            if (frame[i] >= end) {
                if (wrap) {
                    frame[i] = -2;
                } else if (hold) {
                    frame[i] = -1;
                } else {
                    frame[i] = start;
                }
            }
        }
    }
}

static inline s32 fn_1_9AF80_restart(fn_1_9AF80_List *list) {
    s32 found = 0;
    s32 j = 0;
    fn_1_9AF80_Entry *entry = list->entries;
    fn_1_9AF80_Owner *owner = list->owner;
    s32 *frame;

    for (; j < list->count; j++, entry++) {
        frame = &entry->frame[lbl_1_data_2A7E0.unk_60];
        if (*frame >= 0) {
            owner->frame = (f32)entry->lo + (f32)(*frame % (entry->hi - entry->lo));
            fn_1_42E74(owner);
            found = 1;
            break;
        }
    }
    return found;
}

static inline void fn_1_9AF80_copy(fn_1_9AF80_Obj *obj) {
    fn_1_9AF80_Dest *dest = obj->dest;

    dest->pos = obj->pos;
    dest->rot[0] = obj->rot[0];
    dest->rot[1] = obj->rot[1];
    dest->rot[2] = obj->rot[2];
    dest->scale = obj->scale;
}

void fn_1_9AF80(fn_1_9AF80_Obj *obj, s32 count, s32 reset) {
    s32 j;
    fn_1_9AF80_Obj *first;
    fn_1_9AF80_Anim *anim;
    fn_1_9AF80_List *list;
    fn_1_9AF80_Entry *entry;
    u32 *flags;
    u32 mask;
    u32 bit;
    u32 slot;
    s32 player;
    s32 player2;
    s32 i;
    s32 done;
    s32 frame;
    s32 *cur;
    u32 loc[3];
    f32 t;
    f32 len;
    f32 now;

    if (!obj) {
        return;
    }
    first = obj;
    mask = fn_1_9D260();
    if (reset) {
        s32 n;

        for (n = 0; n < count; n++) {
            obj->flags &= ~0x60000000;
            anim = obj->anim;
            if (anim && (obj->flags & 0x40000)) {
                anim->frame[0] = anim->frame[1] = anim->frame[2] = anim->frame[3] = -1;
            }
            list = obj->list;
            if (list) {
                entry = list->entries;
                for (j = 0; j < list->count; j++, entry++) {
                    if (entry->hold >= 0) {
                        entry->frame[0] = entry->frame[1] = entry->frame[2] = entry->frame[3] = -1;
                    }
                }
            }
            obj++;
        }
        obj = first;
    }

    for (i = 0; i < count; i++, obj++) {
        if (count != 1 && (obj->flags & 0x20000)) {
            flags = obj->model->flags;
            fn_1_9AF80_copy(obj);
            if (obj->flags & 0x20000000) {
                obj->flags &= ~0x20000000;
                obj->flags |= 0x40000000;
            }
            if (flags && (*flags & 0x4000) && !(obj->mode & lbl_1_data_2A7E0.unk_A0)) {
                continue;
            }
        }
        obj->flags &= ~0x800000;
        if (!(obj->flags & mask)) {
            continue;
        }
        bit = (obj->model->sub->unk_8 != 0) ? 0x800000 : 0;
        if (bit == 0 && !obj->model->flags) {
            continue;
        }
        anim = obj->anim;
        list = obj->list;
        if (count != 1) {
            done = 0;
            if (obj->flags & 0x40000) {
                if (lbl_1_data_2A7E0.pad_3[((obj->mode >> 14) & 3) + 3] != 0) {
                    fn_1_9AF80_tick(anim->frame, anim->start, anim->end, 1, obj->mode & 1);
                }
                done = 1;
            }
            if (list) {
                entry = list->entries;
                for (j = 0; j < list->count; j++, entry++) {
                    if (lbl_1_data_2A7E0.pad_3[((obj->mode >> 14) & 3) + 3] != 0) {
                        if (list->entries->lo == 0 && list->entries->hi == 0) {
                            if (list->owner) {
                                frame = (s32)list->owner->frame + 1;
                                entry->frame[0] = entry->frame[1] = entry->frame[2] = entry->frame[3] = frame;
                            }
                        } else if (anim) {
                            fn_1_9AF80_tick(entry->frame, anim->start, anim->end, entry->hold, obj->mode & 1);
                        } else {
                            fn_1_9AF80_tick(entry->frame, entry->lo, entry->hi, entry->hold, obj->mode & 1);
                        }
                    }
                }
                done = 1;
            }
            if (done) {
                continue;
            }
        }
        obj->flags |= bit;
        slot = lbl_1_data_2A7E0.unk_60;
        if (list && list->owner) {
            player = lbl_1_data_2A7E0.unk_5C;
            if (player >= 0 && player < fn_1_86624() && slot < 4) {
                obj->flags &= ~0x800000;
                fn_1_9ADCC((Obj_1_data_2A7E0_At3C *)list, 1);
                if (fn_1_9AF80_restart(list)) {
                    obj->flags |= 0x800000;
                } else {
                    fn_1_9ADCC((Obj_1_data_2A7E0_At3C *)list, 0);
                    if (fn_1_9AF80_restart(list)) {
                        obj->flags |= 0x800000;
                    }
                }
            }
        }
        if (!anim) {
            continue;
        }
        if (obj->flags & 0x40000) {
            player2 = lbl_1_data_2A7E0.unk_5C;
            if ((obj->flags & 0xE0) && !(obj->flags & lbl_1_data_2A7E0.unk_48)) {
                obj->flags &= ~0x800000;
            } else if (player2 >= 0 && player2 < fn_1_86624() && slot < 4) {
                cur = &anim->frame[slot];
                if (*cur == -1) {
                    fn_1_862D4(player2, loc);
                    if (anim->mask & fn_1_1FB80(loc, 0xFFFF0000)) {
                        *cur = 0;
                    }
                }
                if (*cur < 0) {
                    obj->flags &= ~0x800000;
                } else {
                    now = *cur;
                }
            } else {
                obj->flags &= ~0x800000;
            }
            if (!(obj->flags & 0x800000)) {
                continue;
            }
        } else {
            now = (&lbl_1_data_2A7E0.unk_1C)[(obj->mode >> 14) & 3];
        }
        t = now - anim->start;
        len = anim->end - anim->start;
        if (obj->mode & 1) {
            if (t > len) {
                t = len;
            }
        } else {
            t -= (f32)(len * (f32)fpscr_floor(t / len));
        }
        t += anim->start;
        t /= 60.0f;
        if (obj->mode & 0x80) {
            if (*(s16 *)&lbl_1_bss_960 == 9 && lbl_1_bss_84.unk_14 != 0) {
                lbl_1_data_2A7E0.unk_9C -= *(f32 *)lbl_1_bss_84.unk_14;
                lbl_1_bss_84.unk_14 = 0;
            }
            t -= lbl_1_data_2A7E0.unk_9C;
        }
        if (anim->visible.keys &&
            fn_1_9E170(anim->visible.count, anim->visible.keys, &anim->visible.cursor[slot], t) < 0.5) {
            obj->flags &= ~0x800000;
            continue;
        }
        if (anim->alpha.keys) {
            obj->alpha = fn_1_9E170(anim->alpha.count, anim->alpha.keys, &anim->alpha.cursor[slot], t);
            if (obj->alpha >= 1.0) {
                obj->flags &= ~0x800000;
                continue;
            }
        }
        if (anim->scale[0].keys) {
            obj->scale.x = fn_1_9E170(anim->scale[0].count, anim->scale[0].keys, &anim->scale[0].cursor[slot], t);
        }
        if (anim->scale[1].keys) {
            obj->scale.y = fn_1_9E170(anim->scale[1].count, anim->scale[1].keys, &anim->scale[1].cursor[slot], t);
        }
        if (anim->scale[2].keys) {
            obj->scale.z = fn_1_9E170(anim->scale[2].count, anim->scale[2].keys, &anim->scale[2].cursor[slot], t);
        }
        if (anim->rot[0].keys) {
            obj->rot[0] = 182.04444885253906f * fn_1_9E170(anim->rot[0].count, anim->rot[0].keys, &anim->rot[0].cursor[slot], t);
        }
        if (anim->rot[1].keys) {
            obj->rot[1] = 182.04444885253906f * fn_1_9E170(anim->rot[1].count, anim->rot[1].keys, &anim->rot[1].cursor[slot], t);
        }
        if (anim->rot[2].keys) {
            obj->rot[2] = 182.04444885253906f * fn_1_9E170(anim->rot[2].count, anim->rot[2].keys, &anim->rot[2].cursor[slot], t);
        }
        if (anim->pos[0].keys) {
            obj->pos.x = fn_1_9E170(anim->pos[0].count, anim->pos[0].keys, &anim->pos[0].cursor[slot], t);
        }
        if (anim->pos[1].keys) {
            obj->pos.y = fn_1_9E170(anim->pos[1].count, anim->pos[1].keys, &anim->pos[1].cursor[slot], t);
        }
        if (anim->pos[2].keys) {
            obj->pos.z = fn_1_9E170(anim->pos[2].count, anim->pos[2].keys, &anim->pos[2].cursor[slot], t);
        }
    }

    if (reset) {
        obj = first;
        for (i = 0; i < count; i++) {
            if (obj->flags & 0x20000) {
                fn_1_9AF80_copy(obj);
            }
            obj++;
        }
    }
}
/* fzgx:end fn_1_9AF80 */

/* fzgx:begin fn_1_9BBE4 noprologue */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/burner.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
#include "types.h"

/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@8c8d7cc3) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

extern void lbl_8006DFE8(Fn183D28Vec3 *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H
#ifndef GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H
#define GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H

typedef struct {
    u32 flags;
    s32 count;
    void *nodes;
} EffectManager;
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

extern s32 fn_1_79C88(EffectManager *manager, u32 *out, s32 reverse, f32 value);

#endif  // GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H

/* end game/main_rel/screen_effect_types.h */
/* game/vec3.h: inlined above */

typedef struct fn_1_11544_LiveCamVec fn_1_11544_LiveCamVec;
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_D7724_Vec3Bits;

/* burner.c's .data block, defined in retail order so that every object is
   addressed off the section base the way the retail TU addresses it. */
typedef struct {
    u8 pad_0[0x2];
    u8 color[0x1A];
    f32 unk_1C;
    u8 pad_20[0xC];
    u32 lights[3];
    u8 pad_38[0xC];
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    void *unk_58;
    u8 pad_5C[0x8];
    s32 unk_64;
    u8 pad_68[0x20];
    u32 unk_88;
    u32 unk_8C;
    s32 unk_90;
    u8 pad_94[0x2050 - 0x94];
} BurnerState;
typedef struct { u32 a, b, c; } BurnerResourceData;
typedef struct { u32 a, b; BurnerResourceData *data; u32 d; } BurnerSavedResource;
typedef struct { u32 unk_0; u32 unk_4; u32 unk_8; } BurnerTypeEntry;
typedef struct { u8 pad_0[0x88]; u8 unk_88[0x18C - 0x88]; } BurnerModelEntry;

extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
extern u8 lbl_1_data_2B15C__fzgx_offset_0[];
extern u8 lbl_1_data_2B160__fzgx_offset_0[];
extern u8 lbl_1_data_2B16C__fzgx_offset_0[];
extern u8 lbl_1_data_2B178__fzgx_offset_0[];
extern u8 lbl_1_data_2B184__fzgx_offset_0[];
extern u8 lbl_1_data_2B190__fzgx_offset_0[];
extern u8 lbl_1_data_2B19C__fzgx_offset_0[];
extern u8 lbl_1_data_2B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B1D0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1F0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B208__fzgx_offset_0[];
extern u8 lbl_1_data_2B218__fzgx_offset_0[];
extern u8 lbl_1_data_2B220__fzgx_offset_0[];
extern u8 lbl_1_data_2B230__fzgx_offset_0[];
extern u8 lbl_1_data_2B240__fzgx_offset_0[];
extern u8 lbl_1_data_2B248__fzgx_offset_0[];
extern u8 lbl_1_data_2B258__fzgx_offset_0[];
extern u8 lbl_1_data_2B268__fzgx_offset_0[];
extern u8 lbl_1_data_2B274__fzgx_offset_0[];
extern u8 lbl_1_data_2B284__fzgx_offset_0[];
extern u8 lbl_1_data_2B294__fzgx_offset_0[];
extern u8 lbl_1_data_2B2A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B474__fzgx_offset_0[];
extern u8 lbl_1_data_2B47C__fzgx_offset_0[];
extern u8 lbl_1_data_2B48C__fzgx_offset_0[];
extern u8 lbl_1_data_2B49C__fzgx_offset_0[];
extern u8 lbl_1_data_2B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4BC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B50C__fzgx_offset_0[];
extern u8 lbl_1_data_2B520__fzgx_offset_0[];
extern u8 lbl_1_data_2B530__fzgx_offset_0[];
extern u8 lbl_1_data_2B540__fzgx_offset_0[];
extern u8 lbl_1_data_2B550__fzgx_offset_0[];
extern u8 lbl_1_data_2B560__fzgx_offset_0[];
extern u8 lbl_1_data_2B574__fzgx_offset_0[];
extern u8 lbl_1_data_2B584__fzgx_offset_0[];
extern u8 lbl_1_data_2B594__fzgx_offset_0[];
extern u8 lbl_1_data_2B5A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5D4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5E4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B604__fzgx_offset_0[];
extern u8 lbl_1_data_2B614__fzgx_offset_0[];
extern u8 lbl_1_data_2B624__fzgx_offset_0[];
extern u8 lbl_1_data_2B634__fzgx_offset_0[];
extern u8 lbl_1_data_2B644__fzgx_offset_0[];
extern u8 lbl_1_data_2B654__fzgx_offset_0[];
extern u8 lbl_1_data_2B664__fzgx_offset_0[];
extern u8 lbl_1_data_2B678__fzgx_offset_0[];
extern u8 lbl_1_data_2B68C__fzgx_offset_0[];
extern u8 lbl_1_data_2B6A0__fzgx_offset_0[];
extern u8 lbl_1_data_2B6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6E8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2B708__fzgx_offset_0[];
extern u8 lbl_1_data_2B718__fzgx_offset_0[];
extern u8 lbl_1_data_2B728__fzgx_offset_0[];
extern u8 lbl_1_data_2B738__fzgx_offset_0[];
extern u8 lbl_1_data_2B748__fzgx_offset_0[];
extern u8 lbl_1_data_2B758__fzgx_offset_0[];
extern u8 lbl_1_data_2B768__fzgx_offset_0[];
extern u8 lbl_1_data_2B77C__fzgx_offset_0[];
extern u8 lbl_1_data_2B790__fzgx_offset_0[];
extern u8 lbl_1_data_2B7A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B7B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B7CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B7E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B7F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B808__fzgx_offset_0[];
extern u8 lbl_1_data_2B81C__fzgx_offset_0[];
extern u8 lbl_1_data_2B830__fzgx_offset_0[];
extern u8 lbl_1_data_2B840__fzgx_offset_0[];
extern u8 lbl_1_data_2B850__fzgx_offset_0[];
extern u8 lbl_1_data_2B860__fzgx_offset_0[];
extern u8 lbl_1_data_2B870__fzgx_offset_0[];
extern u8 lbl_1_data_2B884__fzgx_offset_0[];
extern u8 lbl_1_data_2B894__fzgx_offset_0[];
extern u8 lbl_1_data_2B8A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B8EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B900__fzgx_offset_0[];
extern u8 lbl_1_data_2B914__fzgx_offset_0[];
extern u8 lbl_1_data_2B928__fzgx_offset_0[];
extern u8 lbl_1_data_2B93C__fzgx_offset_0[];
extern u8 lbl_1_data_2B948__fzgx_offset_0[];
extern u8 lbl_1_data_2B954__fzgx_offset_0[];
extern u8 lbl_1_data_2B960__fzgx_offset_0[];
extern u8 lbl_1_data_2B96C__fzgx_offset_0[];
extern u8 lbl_1_data_2B97C__fzgx_offset_0[];
extern u8 lbl_1_data_2B990__fzgx_offset_0[];
extern u8 lbl_1_data_2B9A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B9CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9F0__fzgx_offset_0[];
extern u8 lbl_1_data_2BA04__fzgx_offset_0[];
extern u8 lbl_1_data_2BA18__fzgx_offset_0[];
extern u8 lbl_1_data_2BA2C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA40__fzgx_offset_0[];
extern u8 lbl_1_data_2BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA58__fzgx_offset_0[];
extern u8 lbl_1_data_2BA64__fzgx_offset_0[];
extern u8 lbl_1_data_2BA70__fzgx_offset_0[];
extern u8 lbl_1_data_2BA80__fzgx_offset_0[];
extern u8 lbl_1_data_2BA94__fzgx_offset_0[];
extern u8 lbl_1_data_2BAA8__fzgx_offset_0[];
extern u8 lbl_1_data_2BABC__fzgx_offset_0[];
extern u8 lbl_1_data_2BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_2BB10__fzgx_offset_0[];
extern u8 lbl_1_data_2BB24__fzgx_offset_0[];
extern u8 lbl_1_data_2BB38__fzgx_offset_0[];
extern u8 lbl_1_data_2BB48__fzgx_offset_0[];
extern u8 lbl_1_data_2BB58__fzgx_offset_0[];
extern u8 lbl_1_data_2BB68__fzgx_offset_0[];
extern u8 lbl_1_data_2BB78__fzgx_offset_0[];
extern u8 lbl_1_data_2BB88__fzgx_offset_0[];
extern u8 lbl_1_data_2BB9C__fzgx_offset_0[];
extern u8 lbl_1_data_2BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_2BBC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BBD8__fzgx_offset_0[];
extern u8 lbl_1_data_2BBEC__fzgx_offset_0[];
extern u8 lbl_1_data_2BC00__fzgx_offset_0[];
extern u8 lbl_1_data_2BC14__fzgx_offset_0[];
extern u8 lbl_1_data_2BC28__fzgx_offset_0[];
extern u8 lbl_1_data_2BC3C__fzgx_offset_0[];
extern u8 lbl_1_data_2BC50__fzgx_offset_0[];
extern u8 lbl_1_data_2BC64__fzgx_offset_0[];
extern u8 lbl_1_data_2BC78__fzgx_offset_0[];
extern u8 lbl_1_data_2BC8C__fzgx_offset_0[];
extern u8 lbl_1_data_2BCA0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCB4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCDC__fzgx_offset_0[];
extern u8 lbl_1_data_2BCE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BCF4__fzgx_offset_0[];
extern u8 lbl_1_data_2BD00__fzgx_offset_0[];
extern u8 lbl_1_data_2BD10__fzgx_offset_0[];
extern u8 lbl_1_data_2BD20__fzgx_offset_0[];
extern u8 lbl_1_data_2BD30__fzgx_offset_0[];
extern u8 lbl_1_data_2BD40__fzgx_offset_0[];
extern u8 lbl_1_data_2C7BC__fzgx_offset_0[];
extern u8 lbl_1_data_2C7C0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E4__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E8__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F8__fzgx_offset_0[];
extern u8 lbl_1_data_2C804__fzgx_offset_0[];
extern u8 lbl_1_data_2C80C__fzgx_offset_0[];
extern u8 lbl_1_data_2C818__fzgx_offset_0[];
extern u8 lbl_1_data_2C824__fzgx_offset_0[];
extern u8 lbl_1_data_2C86C__fzgx_offset_0[];
extern u8 lbl_1_data_2C870__fzgx_offset_0[];
extern u8 lbl_1_data_2C890__fzgx_offset_0[];
extern u8 lbl_1_data_2C8B0__fzgx_offset_0[];
extern u8 lbl_1_data_2C8D0__fzgx_offset_0[];
extern u8 lbl_1_data_2CB8C__fzgx_offset_0[];
extern u8 lbl_1_data_2CBDC__fzgx_offset_0[];
static union { u32 w[456]; u8 v[0x720]; } fzgx_pool_init_fzgx_obj_lbl_1_data_2A0C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F43455F, 0x4C494748, 0x544D4150, 0x5F410000, 0x4F43455F, 0x57415645, 0x5F504154, 0x5F420000,
    0x4F43455F, 0x4E414D49, 0x5F000000, 0x4F434E5F, 0x504F4F4C, 0x0, 0x42494742, 0x4C55455F,
    0x52454E5A, 0x5F465245, 0x41303100, 0x1, (u32)lbl_1_data_2A0C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A0D0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A0E0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0F8__fzgx_offset_0, 0x3, 0x0, 0x5F6C746D,
    0x70000000, 0x5F6C746D, 0x70320000, 0x4F43455F, 0x43415343, 0x4144455F, 0x0, 0x4F43455F,
    0x4332375F, 0x43415343, 0x41444500, 0x43554245, 0x5F474154, 0x455F415F, 0x4C4F4400, 0x43554245,
    0x5F425F41, 0x5F4C4F44, 0x0, 0x43554245, 0x5F445F41, 0x5F4C4F44, 0x0, 0x42494742,
    0x4C55455F, 0x53554E30, 0x31000000, 0x2, (u32)lbl_1_data_2A13C__fzgx_offset_0, 0x2, (u32)lbl_1_data_2A144__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A14C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A15C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A16C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A17C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A18C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A19C__fzgx_offset_0, 0x3, 0x0, 0x5F5F5F00,
    0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3, 0x0, 0x5041544C, 0x414D505F, 0x41000000, 0x5041544C,
    0x414D505F, 0x42000000, 0x5041544C, 0x414D505F, 0x43000000, 0x5041544C, 0x414D505F, 0x44000000,
    0x424E535F, 0x534B595F, 0x4B554D4F, 0x5F000000, 0x4C49475F, 0x47524F55, 0x4E445F41, 0x0,
    0x4330385F, 0x5241494E, 0x524F4144, 0x0, 0x4330395F, 0x5241494E, 0x524F4144, 0x0,
    0x4332335F, 0x5241494E, 0x524F4144, 0x0, 0x4333345F, 0x5241494E, 0x524F4144, 0x0,
    0x52455041, 0x4952504F, 0x494E5400, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A240__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A250__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A260__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A270__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A280__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A290__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A2A0__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x464C4147, 0x0, 0x0,
    (u32)lbl_1_data_2A314__fzgx_offset_0, 0x3, 0x0, 0x464F525F, 0x4546465F, 0x48413031, 0x0, 0x464F525F,
    0x52454E5A, 0x5F465245, 0x41000000, 0x464F525F, 0x4546465F, 0x47524E4C, 0x49470000, 0x1,
    (u32)lbl_1_data_2A32C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A33C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A34C__fzgx_offset_0, 0x3, 0x0, 0x464F525F,
    0x53554E00, 0x0, (u32)lbl_1_data_2A37C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3,
    0x0, 0x535F5348, 0x49500000, 0x0, (u32)lbl_1_data_2A3C4__fzgx_offset_0, 0x3, 0x0, 0x53414E5F,
    0x57415645, 0x5F504154, 0x5F4D0000, 0x53414E5F, 0x57415645, 0x5F504154, 0x5F530000, 0x474F524F,
    0x46524147, 0x5F767478, 0x0, 0x474F524F, 0x46524147, 0x325F7674, 0x78000000, 0x1,
    (u32)lbl_1_data_2A3DC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3EC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3FC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A40C__fzgx_offset_0, 0x3,
    0x0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x44494345,
    0x0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x434F494E, 0x0, 0x0,
    (u32)lbl_1_data_2A494__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x4D45545F, 0x434F4D45, 0x54303200,
    0x4546465F, 0x524F434B, 0x46495245, 0x5F415F52, 0x32533100, 0x4546465F, 0x524F434B, 0x46495245,
    0x5F425F52, 0x32533100, 0x1, (u32)lbl_1_data_2A4B4__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4D4__fzgx_offset_0,
    0x3, 0x0, 0x4D45545F, 0x42494753, 0x54415230, 0x31000000, 0x0, (u32)lbl_1_data_2A508__fzgx_offset_0,
    0x3, 0x0, 0x3, 0x0, 0x454C565F, 0x544F5000, 0x454C565F, 0x434F4C4F,
    0x4E590000, 0x454C565F, 0x544F5745, 0x52424153, 0x4530315F, 0x415F4C4F, 0x44000000, 0x454C565F,
    0x43415247, 0x4F30315F, 0x415F4C4F, 0x44000000, 0x454C565F, 0x424F5830, 0x315F415F, 0x4C4F4400,
    0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A530__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A538__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A544__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A55C__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A570__fzgx_offset_0, 0x3, 0x0, 0x57494E44, 0x4F573031, 0x0, 0x0,
    (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x3, 0x0, 0x53454152, 0x43483031, 0x0, 0x53454152, 0x43485F41,
    0x524D3031, 0x0, 0x53454152, 0x43485F41, 0x524D3032, 0x0, 0x5343414D, 0x504F494E,
    0x54303100, 0x464C4153, 0x48303100, 0x0, (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A5EC__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A5F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A608__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A618__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A624__fzgx_offset_0, 0x3,
    0x0, 0x3, 0x0, 0x43554245, 0x0, 0x0, (u32)lbl_1_data_2A66C__fzgx_offset_0, 0x3,
    0x0, 0x4654565F, 0x4C4F474F, 0x0, 0x4654565F, 0x52494E47, 0x0, 0x4654565F,
    0x52494E47, 0x5F460000, 0x4654565F, 0x45415254, 0x48000000, 0x4654565F, 0x52494E47, 0x5F540000,
    0x0, (u32)lbl_1_data_2A684__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A690__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A69C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A6A8__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2A6B4__fzgx_offset_0, 0x3, 0x0, 0x43415244, 0x49535000, 0x47414C44, 0x49535000,
    0x57494E4E, 0x45523031, 0x0, 0x57494E4E, 0x45523032, 0x0, 0x57494E4E, 0x45523033,
    0x0, 0x57494E4E, 0x45523034, 0x0, 0x48594F55, 0x53594F55, 0x53504F54, 0x0,
    0x48594F55, 0x53594F55, 0x0, 0x4D55545F, 0x47524F55, 0x4E440000, 0x4D55545F, 0x53544152,
    0x53000000, 0x4D55545F, 0x43495459, 0x5F4C4947, 0x48545300, 0x0, (u32)lbl_1_data_2A6F0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A6F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A700__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A70C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A718__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A724__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A730__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A740__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A74C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A758__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A764__fzgx_offset_0, 0x3, 0x0, 0x0, 0x0, 0x0
}};
static union { u32 w[2068]; BurnerState v; } fzgx_pool_init_fzgx_obj_burner_state = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080, 0x80000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, (u32)lbl_1_data_1E968__fzgx_offset_0, (u32)lbl_1_data_1E974__fzgx_offset_0,
    (u32)lbl_1_data_1E980__fzgx_offset_0, (u32)lbl_1_data_1E98C__fzgx_offset_0, (u32)lbl_1_data_1E998__fzgx_offset_0, (u32)lbl_1_data_1E9A4__fzgx_offset_0, (u32)lbl_1_data_1E9B0__fzgx_offset_0, (u32)lbl_1_data_1E9BC__fzgx_offset_0, (u32)lbl_1_data_1E9C8__fzgx_offset_0, (u32)lbl_1_data_1E9D4__fzgx_offset_0,
    (u32)lbl_1_data_1E9E0__fzgx_offset_0, (u32)lbl_1_data_1E9EC__fzgx_offset_0, (u32)lbl_1_data_1E9F8__fzgx_offset_0, (u32)lbl_1_data_1EA04__fzgx_offset_0, (u32)lbl_1_data_1EA10__fzgx_offset_0, (u32)lbl_1_data_1EA1C__fzgx_offset_0, (u32)lbl_1_data_1EA34__fzgx_offset_0, (u32)lbl_1_data_1EA40__fzgx_offset_0,
    (u32)lbl_1_data_1EA4C__fzgx_offset_0, (u32)lbl_1_data_1EA58__fzgx_offset_0, (u32)lbl_1_data_1EA64__fzgx_offset_0, (u32)lbl_1_data_1ED48__fzgx_offset_0, (u32)lbl_1_data_1ED54__fzgx_offset_0, (u32)lbl_1_data_1ED60__fzgx_offset_0, (u32)lbl_1_data_1ED6C__fzgx_offset_0, (u32)lbl_1_data_1ED78__fzgx_offset_0,
    (u32)lbl_1_data_1ED84__fzgx_offset_0, (u32)lbl_1_data_1ED90__fzgx_offset_0, (u32)lbl_1_data_1ED9C__fzgx_offset_0, (u32)lbl_1_data_1EDA8__fzgx_offset_0, (u32)lbl_1_data_1EDB4__fzgx_offset_0, (u32)lbl_1_data_1EDC0__fzgx_offset_0, (u32)lbl_1_data_1EDCC__fzgx_offset_0, (u32)lbl_1_data_1EDD8__fzgx_offset_0,
    (u32)lbl_1_data_1EDE4__fzgx_offset_0, (u32)lbl_1_data_1EDF0__fzgx_offset_0, (u32)lbl_1_data_1EDFC__fzgx_offset_0, (u32)lbl_1_data_1EE08__fzgx_offset_0, (u32)lbl_1_data_1EE14__fzgx_offset_0, (u32)lbl_1_data_1EE20__fzgx_offset_0, (u32)lbl_1_data_1EE2C__fzgx_offset_0, (u32)lbl_1_data_1EE38__fzgx_offset_0,
    0x4E554C4C, 0x0, 0x4D555445, 0x20434954, 0x59000000, 0x504F5254, 0x20544F57, 0x4E000000,
    0x42494720, 0x424C5545, 0x0, 0x4C494748, 0x544E494E, 0x47000000, 0x53414E44, 0x204F4345,
    0x414E0000, 0x47524545, 0x4E20504C, 0x414E5400, 0x46495245, 0x20464945, 0x4C440000, 0x43415349,
    0x4E4F2050, 0x414C4143, 0x45000000, 0x4F555445, 0x52205350, 0x41434500, 0x4145524F, 0x504F4C49,
    0x53000000, 0x434F534D, 0x4F205445, 0x524D494E, 0x414C0000, 0x5048414E, 0x544F4D20, 0x524F4144,
    0x0, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0,
    (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9C4__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9DC__fzgx_offset_0, (u32)lbl_1_data_2A9EC__fzgx_offset_0,
    (u32)lbl_1_data_2A9F8__fzgx_offset_0, (u32)lbl_1_data_2AA04__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2AA14__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, 0x0, 0x837E8385,
    0x815B8367, 0x20835683, 0x65834200, 0x837C815B, 0x83672083, 0x5E834583, 0x93000000, 0x83728362,  /* fzgx-allow: A1 retail data bytes */
    0x834F2083, 0x75838B81, 0x5B000000, 0x83898343, 0x8367836A, 0x8393834F, 0x0, 0x83548393,
    0x83682083, 0x49815B83, 0x56838383, 0x93000000, 0x834F838A, 0x815B8393, 0x20837683, 0x89839383,  /* fzgx-allow: A1 retail data bytes */
    0x67000000, 0x83748340, 0x83438341, 0x20837483, 0x42815B83, 0x8B836800, 0x834A8357, 0x836D2083,
    0x70838C83, 0x58000000, 0x83418345, 0x835E815B, 0x20835883, 0x79815B83, 0x58000000, 0x83478341,
    0x838D837C, 0x838A8358, 0x0, 0x83528358, 0x83822083, 0x5E815B83, 0x7E836983, 0x8B000000,
    0x83748340, 0x83938367, 0x83802083, 0x8D815B83, 0x68000000, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0,
    (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AAD0__fzgx_offset_0,
    (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAF8__fzgx_offset_0, (u32)lbl_1_data_2AB08__fzgx_offset_0, (u32)lbl_1_data_2AB1C__fzgx_offset_0, (u32)lbl_1_data_2AB2C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0,
    (u32)lbl_1_data_2AB40__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0,
    (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0,
    (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0,
    (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0,
    (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0,
    (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0,
    (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0,
    (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0,
    (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0,
    (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0,
    (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_DC204__fzgx_offset_0, (u32)fn_1_DC208__fzgx_offset_0, (u32)fn_1_DC264__fzgx_offset_0,
    (u32)fn_1_DC268__fzgx_offset_0, (u32)fn_1_DC2F8__fzgx_offset_0, (u32)fn_1_DC33C__fzgx_offset_0, (u32)fn_1_DC3A0__fzgx_offset_0, (u32)fn_1_DCB9C__fzgx_offset_0, (u32)fn_1_DCBF4__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0,
    (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0,
    (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0,
    (u32)fn_1_FA6C0__fzgx_offset_0, (u32)fn_1_FA75C__fzgx_offset_0, (u32)fn_1_FA82C__fzgx_offset_0, (u32)fn_1_FA830__fzgx_offset_0, (u32)fn_1_FA854__fzgx_offset_0, (u32)fn_1_FA878__fzgx_offset_0, (u32)fn_1_FA898__fzgx_offset_0, (u32)fn_1_FB770__fzgx_offset_0,
    (u32)fn_1_FB798__fzgx_offset_0, (u32)fn_1_FE5E0__fzgx_offset_0, (u32)fn_1_FE5E4__fzgx_offset_0, (u32)fn_1_FE640__fzgx_offset_0, (u32)fn_1_FE644__fzgx_offset_0, (u32)fn_1_FE780__fzgx_offset_0, (u32)fn_1_FE784__fzgx_offset_0, (u32)fn_1_FE7D4__fzgx_offset_0,
    (u32)fn_1_101348__fzgx_offset_0, (u32)fn_1_1013A0__fzgx_offset_0, (u32)fn_1_153988__fzgx_offset_0, (u32)fn_1_15398C__fzgx_offset_0, (u32)fn_1_1539D0__fzgx_offset_0, (u32)fn_1_153A28__fzgx_offset_0, (u32)fn_1_153AAC__fzgx_offset_0, (u32)fn_1_153AB0__fzgx_offset_0,
    (u32)fn_1_153AF4__fzgx_offset_0, (u32)fn_1_1543E8__fzgx_offset_0, (u32)fn_1_154410__fzgx_offset_0, (u32)fn_1_150500__fzgx_offset_0, (u32)fn_1_150518__fzgx_offset_0, (u32)fn_1_150570__fzgx_offset_0, (u32)fn_1_1505B4__fzgx_offset_0, (u32)fn_1_150574__fzgx_offset_0,
    (u32)fn_1_150608__fzgx_offset_0, (u32)fn_1_150650__fzgx_offset_0, (u32)fn_1_151764__fzgx_offset_0, (u32)fn_1_15176C__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0,
    (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0,
    (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1586A8__fzgx_offset_0, (u32)fn_1_1586AC__fzgx_offset_0,
    (u32)fn_1_158980__fzgx_offset_0, (u32)fn_1_158984__fzgx_offset_0, (u32)fn_1_15903C__fzgx_offset_0, (u32)fn_1_159040__fzgx_offset_0, (u32)fn_1_159060__fzgx_offset_0, (u32)fn_1_159064__fzgx_offset_0, (u32)fn_1_15906C__fzgx_offset_0, (u32)fn_1_15B428__fzgx_offset_0,
    (u32)fn_1_15B42C__fzgx_offset_0, (u32)fn_1_15B4F8__fzgx_offset_0, (u32)fn_1_15B4FC__fzgx_offset_0, (u32)fn_1_15B51C__fzgx_offset_0, (u32)fn_1_15B520__fzgx_offset_0, (u32)fn_1_15B540__fzgx_offset_0, (u32)fn_1_15B698__fzgx_offset_0, (u32)fn_1_15B70C__fzgx_offset_0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x62675F6D, 0x75740000, 0x62675F70, 0x6F720000, 0x62675F70, 0x6F725F73, 0x0,
    0x62675F62, 0x69670000, 0x62675F62, 0x69675F73, 0x0, 0x62675F6C, 0x69670000, 0x62675F73,
    0x616E0000, 0x62675F73, 0x616E5F73, 0x0, 0x62675F66, 0x6F720000, 0x62675F66, 0x69720000,
    0x62675F66, 0x69725F73, 0x0, 0x62675F63, 0x61730000, 0x62675F6D, 0x65740000, 0x62675F74,
    0x6F770000, 0x62675F65, 0x6C650000, 0x62675F63, 0x6F6D0000, 0x62675F63, 0x6F6D5F73, 0x0,
    0x62675F72, 0x61690000, 0x62675F77, 0x696E5F67, 0x78000000, 0x0, (u32)lbl_1_data_2AEC4__fzgx_offset_0, (u32)lbl_1_data_2AECC__fzgx_offset_0,
    (u32)lbl_1_data_2AED4__fzgx_offset_0, (u32)lbl_1_data_2AEE0__fzgx_offset_0, (u32)lbl_1_data_2AEE8__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEFC__fzgx_offset_0, (u32)lbl_1_data_2AF04__fzgx_offset_0, (u32)lbl_1_data_2AF10__fzgx_offset_0,
    (u32)lbl_1_data_2AF18__fzgx_offset_0, (u32)lbl_1_data_2AF20__fzgx_offset_0, (u32)lbl_1_data_2AF2C__fzgx_offset_0, (u32)lbl_1_data_2AF34__fzgx_offset_0, (u32)lbl_1_data_2AF3C__fzgx_offset_0, (u32)lbl_1_data_2AF44__fzgx_offset_0, (u32)lbl_1_data_2AF4C__fzgx_offset_0, (u32)lbl_1_data_2AF54__fzgx_offset_0,
    (u32)lbl_1_data_2AF60__fzgx_offset_0, (u32)lbl_1_data_2AF68__fzgx_offset_0, 0x0, 0x0, 0x4, 0x202C0, 0x202C0, 0x18B0,
    0x18B0, 0xFD80, 0xFD80, 0x1C60, 0x1C60, 0x226C, 0x764, 0x764,
    0x174, 0x1B1E8, 0x1704, 0x2748, 0x4, 0x4, 0x157CC, 0x128,
    0x0, 0x0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0,
    (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A35C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A484__fzgx_offset_0, (u32)lbl_1_data_2A4E8__fzgx_offset_0,
    (u32)lbl_1_data_2A5DC__fzgx_offset_0, (u32)lbl_1_data_2A528__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A664__fzgx_offset_0, (u32)lbl_1_data_2A6C0__fzgx_offset_0, 0x0, 0x0,
    (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0,
    (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A384__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A49C__fzgx_offset_0, (u32)lbl_1_data_2A518__fzgx_offset_0, (u32)lbl_1_data_2A62C__fzgx_offset_0, (u32)lbl_1_data_2A580__fzgx_offset_0,
    (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A674__fzgx_offset_0, (u32)lbl_1_data_2A774__fzgx_offset_0, 0x0, 0x8010101, 0x10F0202, 0x6060A0A,
    0x602040B, 0xD0B0B0E, 0xE0F1006, 0x10080804, 0x130D080F, 0xE02060A, 0x1112090D, 0x5070301,
    0xC130000, 0x141400, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x10202, 0x3030404, 0x5050607, 0x708090A, 0xB0C0C0D, 0x1000000, 0x2D2D2D00,
    0x54776973, 0x7420526F, 0x61640000, 0x53657269, 0x616C2047, 0x61707300, 0x4D756C74, 0x69706C65,
    0x78000000, 0x4165726F, 0x20446976, 0x65000000, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x48616C66,
    0x20506970, 0x65000000, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x4D6F6269, 0x75732052,
    0x696E6700, 0x4C6F6E67, 0x20506970, 0x65000000, 0x44726966, 0x74204869, 0x67687761, 0x79000000,
    0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x53706C69, 0x74204F76, 0x616C0000, 0x556E6475,
    0x6C617469, 0x6F6E0000, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x54726964, 0x656E7400,
    0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x53757266, 0x61636520, 0x536C6964, 0x65000000,
    0x4F726465, 0x616C0000, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x446F7562, 0x6C652042,
    0x72616E63, 0x68657300, 0x53637265, 0x77204472, 0x69766500, 0x4D657465, 0x6F722053, 0x74726561,
    0x6D000000, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x5468756E, 0x64657220, 0x526F6164,
    0x0, 0x53706972, 0x616C0000, 0x536F6E69, 0x63204F76, 0x616C0000, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0,
    (u32)lbl_1_data_2B1A8__fzgx_offset_0, (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0,
    (u32)lbl_1_data_2B230__fzgx_offset_0, (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0,
    (u32)lbl_1_data_2B294__fzgx_offset_0, (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, 0x96A292E8, 0x0, 0x47455220,
    0x54776973, 0x7420526F, 0x61640000, 0x46524520, 0x54776973, 0x7420526F, 0x61640000, 0x53504120,
    0x54776973, 0x7420526F, 0x61640000, 0x49544120, 0x54776973, 0x7420526F, 0x61640000, 0x83638343,
    0x83588367, 0x838D815B, 0x83680000, 0x47455220, 0x53657269, 0x616C2047, 0x61707300, 0x46524520,
    0x53657269, 0x616C2047, 0x61707300, 0x53504120, 0x53657269, 0x616C2047, 0x61707300, 0x49544120,
    0x53657269, 0x616C2047, 0x61707300, 0x8356838A, 0x8341838B, 0x834D8383, 0x83628376, 0x0,
    0x47455220, 0x4D756C74, 0x69706C65, 0x78000000, 0x46524520, 0x4D756C74, 0x69706C65, 0x78000000,
    0x53504120, 0x4D756C74, 0x69706C65, 0x78000000, 0x49544120, 0x4D756C74, 0x69706C65, 0x78000000,
    0x837D838B, 0x83608376, 0x838C8362, 0x834E8358, 0x0, 0x47455220, 0x4165726F, 0x20446976,
    0x65000000, 0x46524520, 0x4165726F, 0x20446976, 0x65000000, 0x53504120, 0x4165726F, 0x20446976,
    0x65000000, 0x49544120, 0x4165726F, 0x20446976, 0x65000000, 0x83478341, 0x838D835F, 0x83438375,
    0x0, 0x47455220, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x46524520, 0x4C6F6F70, 0x2043726F,
    0x73730000, 0x53504120, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x49544120, 0x4C6F6F70, 0x2043726F,
    0x73730000, 0x838B815B, 0x8376834E, 0x838D8358, 0x0, 0x47455220, 0x48616C66, 0x20506970,
    0x65000000, 0x46524520, 0x48616C66, 0x20506970, 0x65000000, 0x53504120, 0x48616C66, 0x20506970,
    0x65000000, 0x49544120, 0x48616C66, 0x20506970, 0x65000000, 0x836E815B, 0x83748370, 0x83438376,
    0x0, 0x47455220, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x46524520, 0x496E7465,
    0x72736563, 0x74696F6E, 0x0, 0x53504120, 0x496E7465, 0x72736563, 0x74696F6E, 0x0,
    0x49544120, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x83438393, 0x835E815B, 0x835A834E,
    0x83568387, 0x83930000, 0x47455220, 0x4D6F6269, 0x75732052, 0x696E6700, 0x46524520, 0x4D6F6269,
    0x75732052, 0x696E6700, 0x53504120, 0x4D6F6269, 0x75732052, 0x696E6700, 0x49544120, 0x4D6F6269,
    0x75732052, 0x696E6700, 0x83818372, 0x83458358, 0x838A8393, 0x834F0000, 0x47455220, 0x4C6F6E67,
    0x20506970, 0x65000000, 0x46524520, 0x4C6F6E67, 0x20506970, 0x65000000, 0x53504120, 0x4C6F6E67,
    0x20506970, 0x65000000, 0x49544120, 0x4C6F6E67, 0x20506970, 0x65000000, 0x838D8393, 0x834F8370,
    0x83438376, 0x0, 0x47455220, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x46524520,
    0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x53504120, 0x44726966, 0x74204869, 0x67687761,
    0x79000000, 0x49544120, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x8368838A, 0x83748367,
    0x836E8343, 0x83458346, 0x83430000, 0x47455220, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000,
    0x46524520, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x53504120, 0x43796C69, 0x6E646572,
    0x204B6E6F, 0x74000000, 0x49544120, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x8356838A,
    0x8393835F, 0x815B836D, 0x83628367, 0x0, 0x47455220, 0x53706C69, 0x74204F76, 0x616C0000,  /* fzgx-allow: A1 retail data bytes */
    0x46524520, 0x53706C69, 0x74204F76, 0x616C0000, 0x53504120, 0x53706C69, 0x74204F76, 0x616C0000,
    0x49544120, 0x53706C69, 0x74206F76, 0x616C0000, 0x83588376, 0x838A8362, 0x83678349, 0x815B836F,  /* fzgx-allow: A1 retail data bytes */
    0x838B0000, 0x47455220, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x46524520, 0x556E6475, 0x6C617469,
    0x6F6E0000, 0x53504120, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x49544120, 0x556E6475, 0x6C617469,
    0x6F6E0000, 0x83418393, 0x83668385, 0x838C815B, 0x83568387, 0x83930000, 0x47455220, 0x44726167,
    0x6F6E2053, 0x6C6F7065, 0x0, 0x46524520, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0,
    0x53504120, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x49544120, 0x44726167, 0x6F6E2053,
    0x6C6F7065, 0x0, 0x83688389, 0x83538393, 0x8358838D, 0x815B8376, 0x0, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x54726964, 0x656E7400, 0x46524520, 0x54726964, 0x656E7400, 0x53504120, 0x54726964, 0x656E7400,
    0x49544120, 0x54726964, 0x656E7400, 0x83678389, 0x83438366, 0x83938367, 0x0, 0x47455220,
    0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x46524520, 0x4C617465, 0x72616C20, 0x53686966,
    0x74000000, 0x53504120, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x49544120, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x83898365, 0x8389838B, 0x83568374, 0x83670000, 0x47455220,
    0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x46524520, 0x53757266, 0x61636520, 0x536C6964,
    0x65000000, 0x53504120, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x49544120, 0x53757266,
    0x61636520, 0x536C6964, 0x65000000, 0x8354815B, 0x83748346, 0x83588358, 0x83898343, 0x83680000,
    0x47455220, 0x4F726465, 0x616C0000, 0x46524520, 0x4F726465, 0x616C0000, 0x53504120, 0x4F726465,
    0x616C0000, 0x49544120, 0x4F726465, 0x616C0000, 0x8349815B, 0x83668342, 0x815B838B, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x46524520, 0x536C696D, 0x2D6C696E,
    0x6520536C, 0x69747300, 0x53504120, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x49544120,
    0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x8358838A, 0x83808389, 0x83438393, 0x8358838A,
    0x83628367, 0x0, 0x47455220, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x46524520,
    0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x53504120, 0x446F7562, 0x6C652042, 0x72616E63,
    0x68657300, 0x49544120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x835F8375, 0x838B8375,
    0x83898393, 0x83600000, 0x47455220, 0x53637265, 0x77204472, 0x69766500, 0x46524520, 0x53637265,
    0x77204472, 0x69766500, 0x53504120, 0x53637265, 0x77204472, 0x69766500, 0x49544120, 0x53637265,
    0x77204472, 0x69766500, 0x8358834E, 0x838A8385, 0x815B8368, 0x83898343, 0x83750000, 0x47455220,  /* fzgx-allow: A1 retail data bytes */
    0x4D657465, 0x6F722053, 0x74726561, 0x6D000000, 0x46524520, 0x4D657465, 0x6F722053, 0x74726561,
    0x6D000000, 0x53504120, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000, 0x49544120, 0x4D657465,
    0x6F722053, 0x74726561, 0x6D000000, 0x83818365, 0x83498358, 0x8367838A, 0x815B8380, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x46524520, 0x43796C69, 0x6E646572,
    0x20576176, 0x65000000, 0x53504120, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x49544120,
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x8356838A, 0x8393835F, 0x815B8345, 0x8346815B,  /* fzgx-allow: A1 retail data bytes */
    0x83750000, 0x47455220, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x46524520, 0x5468756E,
    0x64657220, 0x526F6164, 0x0, 0x53504120, 0x5468756E, 0x64657220, 0x526F6164, 0x0,
    0x49544120, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x83548393, 0x835F815B, 0x838D815B,
    0x83680000, 0x47455220, 0x53706972, 0x616C0000, 0x46524520, 0x53706972, 0x616C0000, 0x53504120,
    0x53706972, 0x616C0000, 0x49544120, 0x53706972, 0x616C0000, 0x83588370, 0x83438389, 0x838B0000,
    0x47455220, 0x536F6E69, 0x63204F76, 0x616C0000, 0x46524520, 0x536F6E69, 0x63204F76, 0x616C0000,
    0x53504120, 0x536F6E69, 0x63204F76, 0x616C0000, 0x49544120, 0x536F6E69, 0x63204F76, 0x616C0000,
    0x835C836A, 0x8362834E, 0x8349815B, 0x836F838B, 0x0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B47C__fzgx_offset_0, (u32)lbl_1_data_2B48C__fzgx_offset_0, (u32)lbl_1_data_2B49C__fzgx_offset_0, (u32)lbl_1_data_2B4AC__fzgx_offset_0,
    (u32)lbl_1_data_2B4BC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B16C__fzgx_offset_0,
    (u32)lbl_1_data_2B4CC__fzgx_offset_0, (u32)lbl_1_data_2B4DC__fzgx_offset_0, (u32)lbl_1_data_2B4EC__fzgx_offset_0, (u32)lbl_1_data_2B4FC__fzgx_offset_0, (u32)lbl_1_data_2B50C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B520__fzgx_offset_0, (u32)lbl_1_data_2B530__fzgx_offset_0, (u32)lbl_1_data_2B540__fzgx_offset_0, (u32)lbl_1_data_2B550__fzgx_offset_0,
    (u32)lbl_1_data_2B560__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0,
    (u32)lbl_1_data_2B574__fzgx_offset_0, (u32)lbl_1_data_2B584__fzgx_offset_0, (u32)lbl_1_data_2B594__fzgx_offset_0, (u32)lbl_1_data_2B5A4__fzgx_offset_0, (u32)lbl_1_data_2B5B4__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B5C4__fzgx_offset_0, (u32)lbl_1_data_2B5D4__fzgx_offset_0,
    (u32)lbl_1_data_2B5E4__fzgx_offset_0, (u32)lbl_1_data_2B5F4__fzgx_offset_0, (u32)lbl_1_data_2B604__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B614__fzgx_offset_0, (u32)lbl_1_data_2B624__fzgx_offset_0, (u32)lbl_1_data_2B634__fzgx_offset_0, (u32)lbl_1_data_2B644__fzgx_offset_0,
    (u32)lbl_1_data_2B654__fzgx_offset_0, (u32)lbl_1_data_2B1A8__fzgx_offset_0, (u32)lbl_1_data_2B664__fzgx_offset_0, (u32)lbl_1_data_2B678__fzgx_offset_0, (u32)lbl_1_data_2B68C__fzgx_offset_0, (u32)lbl_1_data_2B6A0__fzgx_offset_0, (u32)lbl_1_data_2B6B4__fzgx_offset_0, (u32)lbl_1_data_2B1B8__fzgx_offset_0,
    (u32)lbl_1_data_2B6C8__fzgx_offset_0, (u32)lbl_1_data_2B6D8__fzgx_offset_0, (u32)lbl_1_data_2B6E8__fzgx_offset_0, (u32)lbl_1_data_2B6F8__fzgx_offset_0, (u32)lbl_1_data_2B708__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B718__fzgx_offset_0, (u32)lbl_1_data_2B728__fzgx_offset_0, (u32)lbl_1_data_2B738__fzgx_offset_0, (u32)lbl_1_data_2B748__fzgx_offset_0,
    (u32)lbl_1_data_2B758__fzgx_offset_0, (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B768__fzgx_offset_0, (u32)lbl_1_data_2B77C__fzgx_offset_0, (u32)lbl_1_data_2B790__fzgx_offset_0, (u32)lbl_1_data_2B7A4__fzgx_offset_0, (u32)lbl_1_data_2B7B8__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0,
    (u32)lbl_1_data_2B7CC__fzgx_offset_0, (u32)lbl_1_data_2B7E0__fzgx_offset_0, (u32)lbl_1_data_2B7F4__fzgx_offset_0, (u32)lbl_1_data_2B808__fzgx_offset_0, (u32)lbl_1_data_2B81C__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B830__fzgx_offset_0, (u32)lbl_1_data_2B840__fzgx_offset_0,
    (u32)lbl_1_data_2B850__fzgx_offset_0, (u32)lbl_1_data_2B860__fzgx_offset_0, (u32)lbl_1_data_2B870__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B884__fzgx_offset_0, (u32)lbl_1_data_2B894__fzgx_offset_0, (u32)lbl_1_data_2B8A4__fzgx_offset_0, (u32)lbl_1_data_2B8B4__fzgx_offset_0,
    (u32)lbl_1_data_2B8C4__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B8D8__fzgx_offset_0, (u32)lbl_1_data_2B8EC__fzgx_offset_0, (u32)lbl_1_data_2B900__fzgx_offset_0, (u32)lbl_1_data_2B914__fzgx_offset_0,
    (u32)lbl_1_data_2B928__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B93C__fzgx_offset_0, (u32)lbl_1_data_2B948__fzgx_offset_0,
    (u32)lbl_1_data_2B954__fzgx_offset_0, (u32)lbl_1_data_2B960__fzgx_offset_0, (u32)lbl_1_data_2B96C__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B97C__fzgx_offset_0, (u32)lbl_1_data_2B990__fzgx_offset_0, (u32)lbl_1_data_2B9A4__fzgx_offset_0, (u32)lbl_1_data_2B9B8__fzgx_offset_0,
    (u32)lbl_1_data_2B9CC__fzgx_offset_0, (u32)lbl_1_data_2B230__fzgx_offset_0, (u32)lbl_1_data_2B9DC__fzgx_offset_0, (u32)lbl_1_data_2B9F0__fzgx_offset_0, (u32)lbl_1_data_2BA04__fzgx_offset_0, (u32)lbl_1_data_2BA18__fzgx_offset_0, (u32)lbl_1_data_2BA2C__fzgx_offset_0, (u32)lbl_1_data_2B240__fzgx_offset_0,
    (u32)lbl_1_data_2BA40__fzgx_offset_0, (u32)lbl_1_data_2BA4C__fzgx_offset_0, (u32)lbl_1_data_2BA58__fzgx_offset_0, (u32)lbl_1_data_2BA64__fzgx_offset_0, (u32)lbl_1_data_2BA70__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2BA80__fzgx_offset_0, (u32)lbl_1_data_2BA94__fzgx_offset_0,
    (u32)lbl_1_data_2BAA8__fzgx_offset_0, (u32)lbl_1_data_2BABC__fzgx_offset_0, (u32)lbl_1_data_2BAD0__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2BAE8__fzgx_offset_0, (u32)lbl_1_data_2BAFC__fzgx_offset_0, (u32)lbl_1_data_2BB10__fzgx_offset_0, (u32)lbl_1_data_2BB24__fzgx_offset_0,
    (u32)lbl_1_data_2BB38__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0,
    (u32)lbl_1_data_2BB48__fzgx_offset_0, (u32)lbl_1_data_2BB58__fzgx_offset_0, (u32)lbl_1_data_2BB68__fzgx_offset_0, (u32)lbl_1_data_2BB78__fzgx_offset_0, (u32)lbl_1_data_2BB88__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2BB9C__fzgx_offset_0, (u32)lbl_1_data_2BBB0__fzgx_offset_0,
    (u32)lbl_1_data_2BBC4__fzgx_offset_0, (u32)lbl_1_data_2BBD8__fzgx_offset_0, (u32)lbl_1_data_2BBEC__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2BC00__fzgx_offset_0, (u32)lbl_1_data_2BC14__fzgx_offset_0, (u32)lbl_1_data_2BC28__fzgx_offset_0, (u32)lbl_1_data_2BC3C__fzgx_offset_0,
    (u32)lbl_1_data_2BC50__fzgx_offset_0, (u32)lbl_1_data_2B294__fzgx_offset_0, (u32)lbl_1_data_2BC64__fzgx_offset_0, (u32)lbl_1_data_2BC78__fzgx_offset_0, (u32)lbl_1_data_2BC8C__fzgx_offset_0, (u32)lbl_1_data_2BCA0__fzgx_offset_0, (u32)lbl_1_data_2BCB4__fzgx_offset_0, (u32)lbl_1_data_2B2A4__fzgx_offset_0,
    (u32)lbl_1_data_2BCC4__fzgx_offset_0, (u32)lbl_1_data_2BCD0__fzgx_offset_0, (u32)lbl_1_data_2BCDC__fzgx_offset_0, (u32)lbl_1_data_2BCE8__fzgx_offset_0, (u32)lbl_1_data_2BCF4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0,
    (u32)lbl_1_data_2BD20__fzgx_offset_0, (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0, (u32)lbl_1_data_2BD30__fzgx_offset_0,
    (u32)lbl_1_data_2BD40__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, 0x1020304,
    0x10203, 0x4050607, 0x8090A0B, 0xC0D0E0F, 0x10111213, 0x14151617, 0x18191A1B, 0x1C1D1E1F,
    0x20212223, 0x10200, 0x10203, 0x4050600, 0x10203, 0x4050607, 0x42494746, 0x49534830,
    0x31000000, 0x574F524D, 0x0, 0x4B494E47, 0x5F434F42, 0x52410000, 0x53414E44, 0x5F464953,
    0x48000000, 0x53414E44, 0x5F424952, 0x44000000
}};
static union { u32 w[18]; BurnerTypeEntry v[6]; } fzgx_pool_init_fzgx_obj_burner_types = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_2C7F8__fzgx_offset_0, 0x3, (u32)lbl_1_data_2C7BC__fzgx_offset_0, (u32)lbl_1_data_2C804__fzgx_offset_0, 0x9, (u32)lbl_1_data_2C7C0__fzgx_offset_0, (u32)lbl_1_data_2C80C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2C7E4__fzgx_offset_0, (u32)lbl_1_data_2C818__fzgx_offset_0, 0x1, (u32)lbl_1_data_2C7E8__fzgx_offset_0, (u32)lbl_1_data_2C824__fzgx_offset_0, 0x1, (u32)lbl_1_data_2C7F0__fzgx_offset_0, 0x0,
    0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0
}};
static union { u32 w[2]; u8 v[0x8]; } fzgx_pool_init_fzgx_obj_burner_pad_27B8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1, 0x44610000
}};
static union { u32 w[8]; u8 v[0x20]; } fzgx_pool_init_fzgx_obj_burner_fx_27C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x102, 0x1, (u32)lbl_1_data_2C870__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43C80000
}};
static union { u32 w[8]; u8 v[0x20]; } fzgx_pool_init_fzgx_obj_burner_fx_27E0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x102, 0x1, (u32)lbl_1_data_2C890__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x43480000
}};
static union { u32 w[12]; u8 v[0x30]; } fzgx_pool_init_fzgx_obj_burner_fx_2800 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x102, 0x1, (u32)lbl_1_data_2C8B0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x1, 0x447A0000,
    0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43FA0000
}};
static union { u32 w[167]; u8 v[0x29C]; } fzgx_pool_init_fzgx_obj_burner_fx_2830 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3, 0x2, (u32)lbl_1_data_2C8D0__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43960000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43C80000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x42C80000, 0x43480000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x447A0000, 0x44BB8000,
    0x0, 0x1, 0x43960000, 0x44160000, 0x1, 0x1, 0x43FA0000, 0x447A0000,
    0x1, 0x1, 0x43480000, 0x43C80000, 0x1, 0x1, 0x43480000, 0x43C80000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43FA0000, 0x442F0000,
    0x1, 0x1, 0x43C80000, 0x44480000, 0x0, 0x1, 0x44BB8000, 0x451C4000,
    0x0, 0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1, 0x447A0000, 0x44BB8000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x42C80000, 0x43480000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x43FA0000, 0x447A0000, 0x0, 0x1, 0x43480000, 0x43C80000,
    0x0, 0x1, 0x43FA0000, 0x447A0000, 0x1, 0x1, 0x447A0000, 0x44BB8000,
    0x0, 0x1, 0x42C80000, 0x43480000, 0x1, 0x1, 0x42C80000, 0x43960000,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43FA0000,
    0x1, 0x1, 0x43FA0000, 0x447A0000, 0x0, 0x1, 0x451C4000, 0x453B8000,
    0x1, 0x1, 0x43960000, 0x44160000, 0x1, 0x1, 0x43480000, 0x43960000,
    0x0, 0x1, 0x447A0000, 0x44FA0000, 0x6261636B, 0x67726F75, 0x6E642E63, 0x0,
    0x25732573, 0x2E74706C, 0x2E6C7A00, 0x62672F00, 0x25732573, 0x2E676D61, 0x2E6C7A00
}};
static union { u32 w[3]; BurnerResourceData v; } fzgx_pool_init_fzgx_obj_burner_res_a = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0
}};
static union { u32 w[13]; u8 v[0x34]; } fzgx_pool_init_fzgx_obj_burner_pad_2AD8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43700000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43960000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0,
    0x443B8000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x447A0000
}};
static union { u32 w[4]; BurnerSavedResource v; } fzgx_pool_init_fzgx_obj_burner_saved_a = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x41, 0x4, (u32)lbl_1_data_2CB8C__fzgx_offset_0, 0x0
}};
static union { u32 w[3]; BurnerResourceData v; } fzgx_pool_init_fzgx_obj_burner_res_b = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0
}};
static union { u32 w[13]; u8 v[0x34]; } fzgx_pool_init_fzgx_obj_burner_pad_2B28 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43160000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x437A0000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0,
    0x43FA0000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x442F0000
}};
static union { u32 w[4]; BurnerSavedResource v; } fzgx_pool_init_fzgx_obj_burner_saved_b = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x41, 0x4, (u32)lbl_1_data_2CBDC__fzgx_offset_0, 0x0
}};

typedef struct { u8 pad0[0x190]; BurnerSavedResource a; u8 pad1[0x100]; BurnerSavedResource b; } BurnerResourceObject;

extern BurnerSavedResource lbl_1_bss_6EA58;
extern BurnerSavedResource lbl_1_bss_6EA68;
extern u32 lbl_1_bss_38460[21];
extern void *lbl_801A66CC;
extern f32 lbl_8006DAEC(void);
extern s16 fn_1_7B054(void);
extern s32 fn_1_6F84(void);
extern s32 fn_1_79C88(EffectManager *, u32 *, s32, f32);
extern u32 fn_1_20A5C(void *, void *);
extern u32 fn_1_79E54(void *, void *, void *, u32, f32);
extern u32 fn_1_7A240(void *, void *, void *, void *, f32);
extern s32 fn_1_9D230(u32);
extern u32 fn_800720B0(u32);
extern void lbl_8006D1BC(s16, f32 *, f32 *);
extern u32 lbl_8006D9E8(f32, f32, f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void GXInvalidateTexAll(void);
extern void fn_1_566EC(int, int);
extern void fn_1_9AF80(u32, u32, u32);
extern void fn_1_9CCE8(s32);
extern void fn_1_9CD6C(void *, f32);
extern void fn_1_D7724(Sig_fn_1_D7724_Vec3Bits *, s32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern void lbl_8006DCA4(void);
extern void lbl_8006DFC4(u32);
extern void lbl_8006E0A4(u32);
extern void lbl_8006E13C(void *);
extern void mathutil_mtxA_rotate_x(u32);
extern void mathutil_mtxA_rotate_y(u32);
extern void lbl_8006DFE8(Fn183D28Vec3 *);
extern s32 fn_1_15578(void *, fn_1_11544_LiveCamVec *, void *, void *, u32, void *, u32, u32, u32, u32);
extern u32 fn_1_D7758(void *, f32);
extern void fn_1_D76F0(const f32 *, s32);
extern s32 fn_1_54F5C(void *, f32, f32);
extern void lbl_8006DB30(void);
extern void fn_80072558(void);
extern void fn_1_5638C(u32);
extern void fn_1_5631C(const u32 *);
extern void fn_1_5616C(s32, f32, f32);
extern u32 fn_1_56018(s32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern void fn_1_556B8(void *);
extern void fn_1_553C4(void *, void *);
extern void fn_1_55210(void *);
extern void fn_1_9D3E8(void *, void *, void *);
extern void fn_1_55678(void *);
extern void fn_80077E0C(void *);
extern void fn_80076134(void);
extern void fn_80077E7C(void *);

static const union { u32 w[3]; const u32 v[3]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
}};
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41FC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};
static const u32 fzgx_pool_rodata_lbl_1_rodata_4200[12] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4AD21D10, 0x0, 0x43300000, 0x0, 0xFF, 0x0, 0x43300000, 0x80000000,  /* fzgx-allow: A1 retail data bytes */
    0x42700000, 0x0, 0x3FE00000, 0x0
};
static const union { u32 w[3]; const u32 v[3]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_40 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FF00000, 0x0, 0x43360B61
}};
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_4C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_50 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_4244 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000
}};
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_58 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3ECCCCCD
}};
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_5C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3C888889
}};
static const union { u32 w[4]; const u32 v[4]; } fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_60 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC7AFC800, 0x42C80000, 0xC3C88000, 0xBDCCCCCD
}};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_2A0C0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: data section reaches three references first */
    s = fzgx_pool_init_fzgx_obj_lbl_1_data_2A0C0.v[0];
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_burner_state.v;
    s = *(u8 *)fzgx_pool_init_fzgx_obj_burner_types.v;
}
static void fzgx_data_layout_lbl_1_rodata_41F0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41FC.v;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_4200;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_40.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_4C.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_50.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_4244.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_58.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_5C.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_60.v;
}
#pragma section code_type ".text"

#define K_ONE (*(f32 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_4244.v)
#define K_ZERO (*(f32 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41FC.v)
#define STATE (*state)
#define BURNER_MAX(a, b) ((a) > (b) ? (a) : (b))

void fn_1_9BBE4(void *arg0, u32 arg1, u32 arg2, Fn183D28Vec3 *arg3) {
    s32 v0;
    u32 v16;
    BurnerState *state;
    u32 v15;
    s32 texture_active;
    s32 v14;
    s32 light_active;
    u32 previous;
    s32 v33;
    u32 v31;
    u32 v32;
    s32 v18;
#define v19 arg1
    void *v10;
    u32 v12;
#define v13 arg0
    u32 v17;
    f32 v20;
    u32 v21;
    u32 v26, v27, v29;
    void *v30;
#define v28 v31
#define v34 arg1
    u32 v35, v36;
    void *v37;
    u32 *light_table;
    u8 *color;
    Vec3f loc_48;
    Sig_fn_1_D7724_Vec3Bits loc_3C;
    u32 loc_30[3];
    f32 loc_2C;
    u32 loc_28;
    f32 loc_24;
    f32 loc_20;
    u32 loc_1C;
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    s32 loc_54;
    u32 *light;

    previous = 0;
    texture_active = 0;
    v14 = 0;
    v0 = 0;
    if (fzgx_pool_init_fzgx_obj_burner_state.v.unk_90 != 0 && fn_1_9D230(*(u32 *)arg0) != 0) {
        v0 = 1;
    }
    loc_54 = 0;
    fn_1_566EC(1, 255);
    fn_800720B0(0);
    if (arg3 == 0) {
        GXInvalidateTexAll();
        if (fn_1_7B054() == 17 && fn_1_6F84() != 0) {
            /* the pointer is re-read after the first struct store (it may alias) */
#define RES_OBJ ((BurnerResourceObject *)lbl_1_bss_3BE0->unk_68)
            loc_54 = 1;
            fzgx_pool_init_fzgx_obj_burner_res_a.v.c = RES_OBJ->a.data->c;
            fzgx_pool_init_fzgx_obj_burner_res_b.v.c = RES_OBJ->b.data->c;
            lbl_1_bss_6EA58 = RES_OBJ->a;
            lbl_1_bss_6EA68 = RES_OBJ->b;
            RES_OBJ->a = fzgx_pool_init_fzgx_obj_burner_saved_a.v;
            RES_OBJ->b = fzgx_pool_init_fzgx_obj_burner_saved_b.v;
        }
    }
    v10 = (u8 *)arg0 + (arg1 << 6);
    state = &fzgx_pool_init_fzgx_obj_burner_state.v;
    light_table = state->lights;
    color = state->color;
    v12 = arg1 << 12;
    v13 = v10;
    v15 = arg1;
    v16 = v12;
    while ((s32)v15 <= (s32)arg2) {
        if ((*(u32 *)v13 & 0x40000) != 0 || *(u32 *)((u8 *)v13 + 0x38) != 0)
            fn_1_9AF80((u32)v13, 1, 0);
        v17 = *(u32 *)v13;
        if ((v17 & 0x800000) == 0) goto next; /* Keep the verified branch to next. */
        if ((*(u32 *)((u8 *)v13 + 4) & STATE.unk_50) == 0) goto next; /* Keep the verified branch to next. */
        if ((v17 & 0xE0) != 0 && (v17 & STATE.unk_48) == 0) goto next; /* Keep the verified branch to next. */
        if ((v17 & 0x80000000) != 0) goto next; /* Keep the verified branch to next. */
        if (arg3 != 0) {
            lbl_8006DFE8(arg3);
            v20 = K_ONE;
        } else {
            if ((v17 & 0x100000) != 0) {
                lbl_8006D1BC((s16)(v16 + (STATE.unk_44 << 8)), &loc_24, &loc_20);
                lbl_8006D9E8(loc_24, K_ZERO, loc_20);
            } else {
                lbl_8006DCA4();
            }
            v21 = *(u32 *)((u8 *)v13 + 0x3C);
            if (v21 != 0) {
                lbl_8006DFC4(v21);
            } else {
                lbl_8006E0A4((u32)((u8 *)v13 + 0xC));
                mathutil_mtxA_rotate_z(*(s16 *)((u8 *)v13 + 0x1C));
                mathutil_mtxA_rotate_y(*(s16 *)((u8 *)v13 + 0x1A));
                mathutil_mtxA_rotate_x(*(s16 *)((u8 *)v13 + 0x18));
                lbl_8006E13C((u8 *)v13 + 0x20);
            }
            /* the field reads stay expression temporaries (CSE'd by the
               compiler) so the conditional result is copied into v20 */
#define SCALE_X (*(f32 *)((u8 *)v13 + 0x20))
#define SCALE_Y (*(f32 *)((u8 *)v13 + 0x24))
#define SCALE_Z (*(f32 *)((u8 *)v13 + 0x28))
            v20 = BURNER_MAX(BURNER_MAX(SCALE_X, SCALE_Y), SCALE_Z);
            v26 = *(u32 *)v13;
            if ((v26 & 0x300) != 0) fn_1_9CCE8((v26 >> 8) & 3);
        }
        v27 = *(u32 *)((u8 *)v13 + 8);
        if ((*(u32 *)v27 & 0x100) != 0) {
            v29 = STATE.unk_88;
            if (v29 == 1) v30 = fzgx_pool_init_fzgx_obj_burner_fx_27C0.v;
            else {
                v30 = fzgx_pool_init_fzgx_obj_burner_fx_2800.v;
                if (v29 == 2) v30 = fzgx_pool_init_fzgx_obj_burner_fx_27E0.v;
            }
            v28 = fn_1_7A240((void *)v27, &loc_28, &loc_2C, v30, v20);
        } else if (STATE.unk_88 >= 3) {
            if (v0 != 0 && (*(u32 *)v13 & 0x200000) == 0 && (*(u32 *)v27 & 0x40) == 0) {
                v28 = fn_1_7A240((void *)v27, &loc_28, &loc_2C, fzgx_pool_init_fzgx_obj_burner_fx_2830.v, v20);
            } else if ((*(u32 *)v27 & 0x41) != 0) {
                v28 = fn_1_79E54((void *)v27, &loc_28, &loc_2C, STATE.unk_54, v20);
            } else {
                v28 = fn_1_79C88((EffectManager *)v27, &loc_28, STATE.unk_54, v20);
                loc_2C = K_ONE;
            }
        } else if ((*(u32 *)v27 & 0x41) != 0) {
            v28 = fn_1_79E54((void *)v27, &loc_28, &loc_2C, STATE.unk_54, v20);
        } else {
            v28 = fn_1_79C88((EffectManager *)v27, &loc_28, STATE.unk_54, v20);
            loc_2C = K_ONE;
        }
        v31 = v28;
        if ((*(u32 *)v13 & 0x40000000) != 0)
            v31 = *(u32 *)(*(u32 *)(lbl_1_bss_38460[2] + 8) + 0x100);
        if (v31 == 0) goto next; /* Keep the verified branch to next. */
        loc_2C = (f32)(loc_2C * ((*(f64 *)(((u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_40.v))) - *(f32 *)((u8 *)v13 + 0x2C)));
        if ((*(u32 *)v13 & 0x400) != 0)
            fn_1_9CD6C((void *)(v31 + 8), *(f32 *)(v31 + 0x14) * v20);
        v32 = *(u32 *)((u8 *)v13 + 0x34);
        v33 = *(u32 *)(v31 + 4) & 0xC;
        if (v33 != 0) {
            v35 = *(u32 *)((u8 *)v13 + 0x38);
            if (*(u32 *)(v35 + 4) == 0) goto next; /* Keep the verified branch to next. */
            lbl_8006DAEC();
            v36 = *(u32 *)((u8 *)v13 + 0x38);
            if (*(s32 *)v36 == 1) {
                if ((s16)v14 < 4) {
                    lbl_8006DAEC();
                    lbl_8006DFC4(*(u32 *)(*(u32 *)(*(u32 *)((u8 *)v13 + 0x38) + 4) + 8) + 0x2D64);
                    psvec_set(&loc_48, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
                    lbl_8006DCA4();
                    v37 = &loc_48;
                    fn_8006E250((Vec3f *)v37, (Vec3f *)v37);
                    fn_1_D7724(&loc_3C, v14);
                    loc_18 = fn_1_20A5C(&loc_48, &loc_1C);
                    if (fn_1_15578(&loc_48, (fn_1_11544_LiveCamVec *)&loc_3C, &loc_1C, loc_30, 0x440200, &loc_18, 1, 0, 0, 0) != 0)
                        fn_1_D7758(&loc_48, K_ONE);
                    fn_1_D76F0((f32 *)&loc_48, v14);
                    v14++;
                    lbl_8006DB30();
                }
            } else if (*(s32 *)v36 == 3) {
                if ((s16)v14 < 4) {
                    lbl_8006DAEC();
                    lbl_8006DFC4(*(u32 *)(*(u32 *)(*(u32 *)((u8 *)v13 + 0x38) + 4) + 8) + 0x844);
                    psvec_set(&loc_48, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
                    lbl_8006DCA4();
                    fn_8006E250(&loc_48, &loc_48);
                    fn_1_D7724(&loc_3C, v14);
                    loc_18 = fn_1_20A5C(&loc_48, &loc_1C);
                    if (fn_1_15578(&loc_48, (fn_1_11544_LiveCamVec *)&loc_3C, &loc_1C, loc_30, 0x440200, &loc_18, 1, 0, 0, 0) != 0)
                        fn_1_D7758(&loc_48, (*(f32 *)(((u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_58.v))));
                    fn_1_D76F0((f32 *)&loc_48, v14);
                    v14++;
                    lbl_8006DB30();
                }
            }
            v35 = *(u32 *)((u8 *)v13 + 0x38);
            /* the scratch pointer walks from the model table to the entry; the
               in-place advance keeps the member offset out of the index product */
            v37 = (void *)*(u32 *)(*(u32 *)(v35 + 4) + 8);
            v37 = (u8 *)v37 + fzgx_pool_init_fzgx_obj_burner_types.v[*(u32 *)v35].unk_4 * sizeof(BurnerModelEntry);
            lbl_8006DFC4((u32)((BurnerModelEntry *)v37)->unk_88);
            v34 = fn_1_54F5C((void *)(v31 + 8), *(f32 *)(v31 + 0x14), v20);
            lbl_8006DB30();
        } else {
            v34 = fn_1_54F5C((void *)(v31 + 8), *(f32 *)(v31 + 0x14), v20);
        }
        if ((s32)v34 == 0) goto next; /* Keep the verified branch to next. */
        fn_80072558();
        light_active = 0;
        if ((*(u32 *)v13 & 0xE000000) != 0) {
            for (v18 = 0, light = light_table; v18 < 3; v18++, light++) {
                if (*light != 0 && ((__rlwnm(*(u32 *)v13, (32 - (v18 + 25)) & 31, 31, 31))) != 0) {
                    fn_1_5638C(*light);
                    light_active = 1;
                }
            }
        }
        { const u32 *c;
        if ((*(u32 *)v13 & 0x1000000) != 0) {
            c = (const u32 *)color;
        } else {
            loc_14 = (*(u32 *)(((u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_4C.v)));
            c = &loc_14;
        }
        fn_1_5631C(c);
        }
        if (v32 != 0 && (*(u32 *)v13 & 0x1E000) != 0) {
            f32 factor = (*(f32 *)(((u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_5C.v)));
            for (v19 = v32, v18 = 0; v18 < 4; v18++, v19 += 4) {
                u32 p = *(u32 *)v19;
                if (p != 0) {
                    f32 t = factor * STATE.unk_1C;
                    fn_1_5616C(v18, *(f32 *)p * t, *(f32 *)(p + 4) * t);
                }
            }
            texture_active = 1;
        } else if (texture_active != 0) {
            texture_active = 0;
            fn_1_56018(0);
        }
        if ((*(u32 *)v13 & 0x800) != 0) fn_1_56000(1, 3, 0);
        fn_1_55FC4(v20);
        fn_1_55FF0(loc_2C);
        v17 = *(u32 *)v13;
        if ((v17 & 0x400000) != 0) {
            fn_1_56000(1, 3, 0);
            if (v33 == 0) fn_1_556B8((void *)v31);
            fn_1_56000(1, 3, 1);
            fn_1_55FC4(v20);
            fn_1_55FF0(loc_2C);
            if (STATE.unk_64 != 0)
                fn_1_553C4((void *)v31, STATE.unk_58);
            else {
                *(f32 *)((u8 *)lbl_801A66CC + 0x38) = K_ZERO;
                fn_1_55210((void *)v31);
            }
            previous = 0;
        } else if ((v17 & 0x80010) != 0) {
            fn_1_566EC(1, 128);
            if (STATE.unk_64 != 0)
                *(f32 *)((u8 *)lbl_801A66CC + 0x38) = (*(f32 *)(((u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_60.v)));
            if (v33 != 0) {
                v35 = *(u32 *)((u8 *)v13 + 0x38);
                fn_1_9D3E8((void *)v31, *(void **)(v35 + 4), (void *)fzgx_pool_init_fzgx_obj_burner_types.v[*(u32 *)v35].unk_8);
            } else fn_1_55210((void *)v31);
            fn_1_566EC(1, 255);
            previous = 0;
        } else {
            if (STATE.unk_64 != 0)
                *(f32 *)((u8 *)lbl_801A66CC + 0x38) = K_ZERO;
            if (*(u16 *)(v31 + 0x1C) == 0 && (loc_28 & 0x18) != 0 && K_ONE == loc_2C) {
                if (previous != v31) fn_80077E0C((void *)v31);
                if ((loc_28 & 0x10) != 0) fn_80076134();
                fn_1_55678((void *)v31);
                previous = v31;
            } else if (v33 != 0) {
                v35 = *(u32 *)((u8 *)v13 + 0x38);
                fn_1_9D3E8((void *)v31, *(void **)(v35 + 4), (void *)fzgx_pool_init_fzgx_obj_burner_types.v[*(u32 *)v35].unk_8);
                previous = 0;
            } else if ((*(u32 *)v13 & 0x200000) != 0) {
                fn_1_556B8((void *)v31);
                previous = 0;
            } else if ((**(u32 **)((u8 *)v13 + 8) & 0x20) != 0) {
                fn_80077E7C((void *)v31);
                previous = 0;
            } else {
                fn_1_55210((void *)v31);
                previous = 0;
            }
        }
        if ((*(u32 *)v13 & 0x1000000) != 0) {
            loc_10 = (*(u32 *)(((u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_1_rodata_41F0_50.v)));
            fn_1_5631C(&loc_10);
        }
        if ((*(u32 *)v13 & 0x800) != 0) fn_1_56000(1, 3, 1);
        if (light_active != 0) fn_1_5638C(0);
next:
        v16 += 0x1000;
        v15++;
        v13 = (u8 *)v13 + 0x40;
    }
    if (texture_active != 0) fn_1_56018(0);
    if (STATE.unk_64 != 0)
        *(f32 *)((u8 *)lbl_801A66CC + 0x38) = K_ZERO;
    fn_1_566EC(0, 0);
    if (loc_54 != 0) {
        ((BurnerResourceObject *)lbl_1_bss_3BE0->unk_68)->a = lbl_1_bss_6EA58;
        ((BurnerResourceObject *)lbl_1_bss_3BE0->unk_68)->b = lbl_1_bss_6EA68;
    }
}
/* fzgx:end fn_1_9BBE4 */

/* fzgx:begin fn_1_9C724 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 6885000.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[2] = {0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 1.0;
    s = 182.04444885253906f;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static inline void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.4000000059604645f;
    s = 0.01666666753590107f;
    s = -90000.0f;
    s = 100.0f;
    s = -401.0f;
    s = -0.10000000149011612f;
    s = 0.009999999776482582f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9C724_Vec;

typedef struct {
    u8 pad_0[0xB8];
    s32 unk_B8;
    u8 pad_BC[0x84];
    s32 unk_140;
} fn_1_9C724_Progress;

typedef struct {
    u8 pad_0[0x214];
    u16 unk_214;
} fn_1_9C724_Car;

typedef struct {
    u8 pad_0[0x38];
    u32 unk_38;
} fn_1_9C724_Part;

typedef struct {
    u8 pad_0[0x8];
    fn_1_9C724_Part *unk_8;
} fn_1_9C724_Entry;

extern u32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern s16 camera_get_mode(void);
extern s16 fn_1_7B054(void);
extern s8 fn_1_86624(void);
extern s32 fn_1_8C5DC(s32);
extern s32 fn_1_7000(void);
extern fn_1_9C724_Car *fn_1_86254(s32);
extern fn_1_9C724_Progress *fn_1_8627C(s32);
extern void fn_1_862D4(s32, fn_1_9C724_Vec *);
extern u32 fn_1_864E8(s32);
extern s32 fn_1_6F84(void);
extern u32 camera_forward_status(void);
extern u8 fn_1_12850(void);
extern u32 fn_1_1FC98(fn_1_9C724_Vec *, u32);
extern s32 camera_is_mode_0x0b(void);
extern void *fn_1_9D260(Obj_1_data_2A7E0 *);
extern s16 fn_1_3F0C8(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DCA4(void);
extern void fn_8006E294(fn_1_9C724_Vec *);
extern void lbl_8006DB30(void);
extern fn_1_9C724_Vec lbl_1_bss_6EA10[4];
extern u32 lbl_1_bss_6EA40[4];
extern Obj_1_data_2A7E0_At3C *lbl_801A66CC;

#pragma opt_propagation off

/* Builds the draw-group mask placed objects are tested against (Big Blue swaps its above- and under-water
 * groups by camera height) and records the followed machine and viewport slot for this frame. */
void fn_1_9C724(void) {
    fn_1_9C724_Vec eye;
    fn_1_9C724_Vec pos;
    fn_1_9C724_Progress *progress;
    fn_1_9C724_Car *car;
    Obj_1_data_2A7E0 *data;
    u32 viewports;
    s32 slot;
    s32 bits;
    u32 group;
    u32 stored;
    s32 underwater;
    s32 target;
    u32 draw_mask;
    u32 flags;
    u16 car_flag;
    s32 use_alt;
    s32 index;
    fn_1_9C724_Entry *table;
    fn_1_9C724_Part *part;
    s32 t;
    u32 off;
    u32 root_group;
    f32 z;

    viewports = fn_1_58C4();
    slot = fn_1_5910();
    target = camera_get_mode();
    lbl_1_data_2CC2C = target;
    if (target == 0xFF) {
        target = -1;
    }
    underwater = 0;
    if (lbl_1_data_2A7E0.unk_0 == 4) {
        lbl_8006DAEC();
        lbl_8006DCA4();
        fn_8006E294(&eye);
        lbl_8006DB30();
        if ((fn_1_7B054() == 14 && eye.y < 100.0f) || (fn_1_7B054() == 27 && eye.y < -401.0f)) {
            underwater = 1;
        }
    }
    bits = 0x80;
    if (target >= 0 && target < fn_1_86624()) {
        t = fn_1_8C5DC(target) + 1;
        if (t <= 1) {
            bits = 0x20;
        } else if (t == 2) {
            bits = 0x40;
        }
    }
    stored = 0;
    group = 0;
    draw_mask = 0;
    if (((s32)lbl_1_data_2A7E0.unk_8C == 0 && lbl_1_data_2A7E0.unk_88 >= 3) || fn_1_7000() != 0 || target == -1) {
        draw_mask = 0x80000000;
    } else if (lbl_1_bss_3BE0 != NULL && target >= 0) {
        car = fn_1_86254(target);
        progress = fn_1_8627C(target);
        fn_1_862D4(target, &pos);
        flags = fn_1_864E8(target);
        car_flag = car != NULL ? car->unk_214 : 0;
        if (progress != NULL && progress->unk_B8 >= 0) {
            table = (fn_1_9C724_Entry *)lbl_1_bss_3BE0->unk_C;
            use_alt = 0;
            if (car_flag != 0 && progress->unk_140 >= 0) {
                use_alt = 1;
            }
            index = use_alt ? progress->unk_140 : progress->unk_B8;
            part = ((fn_1_9C724_Part **)table)[index * 3 + 2];
            if (part != NULL) {
                group = part->unk_38;
            }
        }
        if (fn_1_6F84() != 0) {
            if (camera_forward_status() & 0x80000000) {
                lbl_1_bss_6EA10[slot] = pos;
                lbl_1_bss_6EA40[slot] = group;
            } else if (fn_1_12850() == 3) {
                pos = lbl_1_bss_6EA10[slot];
                group = lbl_1_bss_6EA40[slot];
            } else {
                lbl_1_bss_6EA40[slot] |= fn_1_1FC98(&pos, 0x7FFFFFFF);
                lbl_1_bss_6EA40[slot] |= group;
                stored = lbl_1_bss_6EA40[slot];
            }
        } else if (camera_is_mode_0x0b() != 0) {
            z = -0.1f;
            pos.y = 1.0f;
            pos.x = 0.0f;
            pos.z = z;
            part = ((fn_1_9C724_Entry *)lbl_1_bss_3BE0->unk_C)->unk_8;
            root_group = part != NULL ? part->unk_38 : 0;
            group = root_group;
        } else if (car_flag == 0 && (flags & 0x800)) {
            pos = lbl_1_bss_6EA10[slot];
            group = lbl_1_bss_6EA40[slot];
        } else {
            lbl_1_bss_6EA10[slot] = pos;
            lbl_1_bss_6EA40[slot] = group;
        }
        draw_mask = fn_1_1FC98(&pos, 0x7FFFFFFF);
        if (lbl_1_data_2A7E0.unk_0 == 4) {
            if (fn_1_7B054() == 27) {
                draw_mask &= 0x7FFFFFF9;
                draw_mask |= underwater ? 4 : 2;
            } else {
                draw_mask &= 0x7FFFFFCF;
                draw_mask |= underwater ? 0x10 : 0x20;
            }
        }
    }
    draw_mask |= group;
    draw_mask |= stored;
    if (draw_mask == 0) {
        draw_mask = 0x80000000;
    }
    lbl_1_data_2A7E0.unk_48 = bits;
    lbl_1_data_2A7E0.unk_4C = (u32)fn_1_9D260(&lbl_1_data_2A7E0);
    data = &lbl_1_data_2A7E0;
    data->unk_50 = draw_mask;
    data->unk_54 = data->unk_88 > 1;
    data->unk_58 = underwater;
    data->unk_5C = target;
    data->unk_60 = slot;
    off = fn_1_6F84() == 0;
    lbl_1_data_2A7E0.unk_64 = off;
    lbl_1_data_2A7E0.unk_68 = lbl_801A66CC->unk_30;
    lbl_1_data_2A7E0.unk_6C = lbl_801A66CC->unk_34;
    if (off) {
        lbl_801A66CC->unk_34 = (s32)lbl_801A66CC->unk_34 >> 1;
        lbl_801A66CC->unk_30 += lbl_801A66CC->unk_34 * 8;
    }
    if (viewports == 1 && fn_1_3F0C8() == 42) {
        data->unk_54 = 1;
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_9C724 */

/* fzgx:begin fn_1_9CC40 */
typedef struct {
    u8 pad[0x30];
    u32 unk_30;
    u32 unk_34;
} fn_1_9CC40_GlobalState;



void fn_1_9CC40(void) {
    (*(fn_1_9CC40_GlobalState * *)&lbl_801A66CC)->unk_30 = lbl_1_data_2A7E0.unk_68;
    (*(fn_1_9CC40_GlobalState * *)&lbl_801A66CC)->unk_34 = lbl_1_data_2A7E0.unk_6C;
}
/* fzgx:end fn_1_9CC40 */

/* fzgx:begin fn_1_9CC6C */
// Initializes the burner state and copies the current burner position into the global state.
void fn_1_9CC6C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_1_9DB04();
        fn_1_9C724();
        fn_1_9BBE4(arg0, 0, arg1 - 1, 0);
        lbl_801A66CC->unk_30 = lbl_1_data_2A7E0.unk_68;
        lbl_801A66CC->unk_34 = lbl_1_data_2A7E0.unk_6C;
    }
}
/* fzgx:end fn_1_9CC6C */

/* fzgx:begin fn_1_9CCE8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CCE8_Vec3;

extern void fn_8006E294(fn_1_9CCE8_Vec3 *);

void fn_1_9CCE8(s32 arg0) {
    fn_1_9CCE8_Vec3 value;
    s32 result;

    switch (arg0) {
    case 1:
        lbl_8006D7B0(arg0);
        break;
    case 2:
        fn_8006E294(&value);
        result = lbl_8006D24C(value.z, value.y);
        mathutil_mtxA_rotate_x((s16)(result - 0x4000));
        break;
    case 3:
        fn_8006E294(&value);
        result = lbl_8006D24C(value.x, value.z);
        mathutil_mtxA_rotate_y(result);
        break;
    default:
        break;
    }
}
/* fzgx:end fn_1_9CCE8 */

/* fzgx:begin fn_1_9CD6C */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CD6C_Vec3;

typedef struct {
    u8 pad[0x60];
} fn_1_9CD6C_GlobalState;

extern fn_1_9CD6C_GlobalState *lbl_801A6D00;

#pragma opt_common_subs off
void fn_1_9CD6C(void *arg0, f32 arg1) {
    fn_1_9CD6C_Vec3 value;
    f32 squared;
    f32 length;

    lbl_8006E1B0(arg0, &value);
    squared = value.x * value.x;
    squared = value.y * value.y + squared;
    squared = value.z * value.z + squared;
    length = lbl_8006D0B4(squared);

    if (length > lbl_1_rodata_4260[0] + arg1) {
        lbl_8006DB74((u8 *)lbl_801A6D00 + 0x60);
        lbl_8006D848((length - arg1) / length);
        lbl_8006DFC4((u8 *)lbl_801A6D00 + 0x60);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_9CD6C */

/* fzgx:begin fn_1_9CE1C */
typedef struct {
    u32 unk_00;
    const char *name;
} fn_1_9CE1C_BurnerEntry;

typedef struct {
    s32 count;
    u32 unk_04;
    fn_1_9CE1C_BurnerEntry *entries;
} fn_1_9CE1C_BurnerTable;

s32 fn_1_9CE1C(const char *arg0, s32 arg1) {
    fn_1_9CE1C_BurnerTable *table;
    fn_1_9CE1C_BurnerEntry *entries;
    s32 found;
    s32 count;
    const char *entry;
    s32 input_length;
    s32 entry_length;

    table = *(fn_1_9CE1C_BurnerTable **)&lbl_1_bss_384B4;
    if (table == 0) {
        return 0;
    }

    entries = table->entries;
    found = 0;

    switch (arg1) {
    case 0:
        count = table->count;
        while (count > 0) {
            entry = entries->name;
            if (fn_8006FC5C(entry, arg0, strlen(arg0)) != 0) {
                found = 1;
                break;
            }
            count--;
            entries++;
        }
        break;
    case 1:
        count = table->count;
        while (count > 0) {
            if (fn_8006FC1C(entries->name, arg0) != 0) {
                found = 1;
                break;
            }
            count--;
            entries++;
        }
        break;
    default:
        count = table->count;
        while (count > 0) {
            entry = entries->name;
            entry_length = strlen(entry);
            input_length = strlen(arg0);
            if (input_length <= entry_length &&
                fn_8006FC5C(entry + (entry_length - input_length), arg0, input_length) != 0) {
                found = 1;
                break;
            }
            count--;
            entries++;
        }
        break;
    }

    if (found != 0) {
        return (s32)entries;
    }
    return 0;
}
/* fzgx:end fn_1_9CE1C */

/* fzgx:begin fn_1_9CF78 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

extern u32 lbl_1_bss_6EA78;
extern u32 lbl_1_bss_6EA7C;
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, void *, s32);
extern const f32 lbl_1_rodata_41FC;
extern u8 fn_1_86624(void);
extern void *fn_1_14F04(void);
extern f32 lbl_1_rodata_4244[7];
extern void fn_1_17920(s32, s32, f32);
extern void fn_1_85C58(s32, f32);
extern void lbl_8006DB74(void *);
extern void fn_1_9DDA8(u32, u32, u32);
extern void fn_1_9DFB8(u32, u32, u32, u32);
extern void GXPeekZ(u32, u32, void *);
extern void GXPokeAlphaRead(u32);
extern void fn_8003432C(u32, u32, u32 *);

extern s32 fn_8006FC1C(const char *, const char *);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 strlen(const char *);

typedef u32 (*FilterCallback)(u32, void *);

typedef struct {
    s32 type;
    const char *str;
} TblEntry;

typedef struct {
    s32 count;
    u32 unk4;
    TblEntry *entries;
} TblGroup;

void fn_1_9CF78(void *arg0, FilterCallback arg1) {
    s32 n;
    u32 idx;
    TblEntry *e;
    TblGroup ***p;
    s32 slen;
    TblEntry *q;
    const char *s;
    s32 ok;
    TblGroup *g;
    s32 res;

    p = (TblGroup ***)&lbl_1_data_2CC30;
    ok = 1;
    while (*p != 0) {
        g = **p;
        if (g == 0) {
            p++;
            continue;
        }
        e = g->entries;
        n = g->count;
        for (; n > 0; n--, e++) {
            s = e->str;
            slen = strlen(s);
            q = (TblEntry *)arg0;
            for (idx = 0; q->str != 0; idx++, q++) {
                switch (q->type) {
                case 0:
                    res = fn_8006FC5C(s, q->str, strlen(q->str));
                    break;
                case 1:
                    res = fn_8006FC1C(s, q->str);
                    break;
                case 2: {
                    s32 len = strlen(q->str);
                    if (len > slen) {
                        res = 0;
                    } else {
                        res = fn_8006FC5C(s + (slen - len), q->str, len);
                    }
                    break;
                }
                default:
                    res = 0;
                    break;
                }
                if (res != 0) {
                    ok = arg1(idx, e);
                }
                if (ok == 0) {
                    break;
                }
            }
            if (ok == 0) {
                break;
            }
        }
        if (ok == 0) {
            break;
        }
        p++;
    }
}
/* fzgx:end fn_1_9CF78 */

/* fzgx:begin fn_1_9D0EC noprologue */
#include "types.h"

typedef struct NameHolder {
    u8 pad[4];
    char *name;
} NameHolder;

typedef struct NameLink {
    u8 pad[8];
    NameHolder *holder;
} NameLink;

typedef struct NameEntry {
    u8 pad[8];
    NameLink *link;
    u8 pad2[0x34];
} NameEntry;

typedef struct NameRule {
    s32 type;
    char *str;
} NameRule;

extern size_t strlen(const char *);
extern s32 fn_8006FC5C(const char *, const char *, size_t);
extern s32 fn_8006FC1C(const char *, const char *);

static inline NameLink * fn_1_9D0EC_read_pointer(NameEntry * owner) { return owner->link; }
void fn_1_9D0EC(NameEntry *arg0, s32 arg1, NameRule *arg2, s32 (*arg3)(s32, NameEntry *)) {
    s32 len;
    s32 (*cb)(s32, NameEntry *) = arg3;
    NameRule *rules = arg2;
    s32 count = arg1;
    s32 i;
    s32 result;
    NameRule *r;
    char *name;

    result = 1;
    while (count > 0) {
        name = fn_1_9D0EC_read_pointer(arg0)->holder->name;
        len = strlen(name);
        r = rules;
        i = 0;
        while (r->str != NULL) {
            s32 ok;
            switch (r->type) {
            case 0:
                ok = fn_8006FC5C(name, r->str, strlen(r->str));
                break;
            case 1:
                ok = fn_8006FC1C(name, r->str);
                break;
            case 2: {
                s32 l = strlen(r->str);
                if (l > len) {
                    ok = 0;
                } else {
                    ok = fn_8006FC5C(name + (len - l), r->str, l);
                }
                break;
            }
            default:
                ok = 0;
                break;
            }
            if (ok) {
                result = cb(i, arg0);
                if (!result) {
                    break;
                }
            }
            if (!result) {
                break;
            }
            i++;
            r++;
        }
        if (!result) {
            break;
        }
        count--;
        arg0++;
    }
}
/* fzgx:end fn_1_9D0EC */

/* fzgx:begin fn_1_9D230 */
u32 fn_1_9D230(void) {
    return (fn_1_9D260() & 0xC) != 0;
}
/* fzgx:end fn_1_9D230 */

/* fzgx:begin fn_1_9D260 */
u32 fn_1_9D260(void) {
    u32 mode;
    u32 result;

    mode = lbl_1_data_2A7E0.unk_88;
    if (mode >= 1 && mode <= 4) {
        result = 1 << (mode - 1);
    } else {
        result = 1;
    }

    if (mode == 1 && (s16)fn_1_3F0C8() == 0x2a &&
        lbl_1_bss_8E51D != 0xa && lbl_1_bss_8E51D != 0x8) {
        result = 2;
    }

    return result;
}
/* fzgx:end fn_1_9D260 */

/* fzgx:begin fn_1_9D2EC */
void fn_1_9D2EC(void) {
    if (!fn_1_7B074()) {
        fn_8006FDEC();
        if (lbl_1_bss_384B8 != 0) {
            fn_80071718(lbl_1_bss_384B8);
            lbl_1_bss_384B8 = 0;
        }
        if (lbl_1_bss_384B4 != 0) {
            fn_800711A8(lbl_1_bss_384B4);
            lbl_1_bss_384B4 = 0;
        }
    }
}
/* fzgx:end fn_1_9D2EC */

/* fzgx:begin fn_1_9D360 noprologue */
#include "types.h"

typedef struct {
    u8 pad[0x1e];
    u8 count;
} Burner;

typedef struct {
    u8 pad[8];
    u8 *entries;
} fn_1_9D360_BurnerTable;

extern void *fn_80077A18(Burner *);
extern void fn_80077F8C(Burner *);

// Builds the burner's entry pointers from its index list, then finalizes it.
void fn_1_9D360(Burner *burner, fn_1_9D360_BurnerTable *table, u8 *indices) {
    void **out;
    s32 i;

    out = (void **)fn_80077A18(burner);
    i = 0;
    while (i < burner->count) {
        *out = table->entries + 0x88 + indices[i] * 0x18c;
        out++;
        i++;
    }
    fn_80077F8C(burner);
}
/* fzgx:end fn_1_9D360 */

/* fzgx:begin fn_1_9D3E8 */
void fn_1_9D3E8(void *arg0, s32 arg1, s32 arg2) {
    fn_1_55A84(fn_1_9D360, arg0, arg1, arg2);
}
/* fzgx:end fn_1_9D3E8 */

/* fzgx:begin fn_1_9D420 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

/* a placed object's skeletal animator (+0x38) */
typedef struct {
    u32 unk_0;
    void *unk_4;
    u8 pad_8[0x4];
    u8 *unk_C;
} fn_1_9D420_Animator;

typedef struct {
    u8 pad_0[0x4];
    char *unk_4;
} fn_1_9D420_Lod;

typedef struct {
    u8 pad_0[0x8];
    fn_1_9D420_Lod *unk_8;
} fn_1_9D420_SceneObject;

/* a placed object (0x40 bytes) */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x4];
    fn_1_9D420_SceneObject *unk_8;
    u8 pad_C[0x2C];
    fn_1_9D420_Animator *unk_38;
    u8 pad_3C[0x4];
} fn_1_9D420_Object;

typedef struct {
    char *unk_0;
    u32 unk_4;
    void *unk_8;
} fn_1_9D420_Entry;

typedef struct {
    u8 pad_0[0x24];
    void *unk_24;
} fn_1_9D420_Skeleton;

extern u32 lbl_801A6410;
extern u32 lbl_1_bss_6EA78;
extern u32 lbl_1_bss_6EA7C;
extern void fn_80006E10(void *);
extern void **fn_1_4630(u32, u32, const char *, s32);
extern u32 strlen(const char *);
extern s32 fn_8006FC5C(const char *, const char *, u32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_45730(void *, void *);
extern s32 fn_1_45B2C(void *);
extern void *fn_1_45D0(u32, u32, const char *, s32);
extern void fn_1_458A0(void *, void *, u32, u32);
extern void fn_1_45850(void *);
extern void fn_1_4247C(void *, void *, void *);
extern void fn_1_426E4(void *, void *);
extern u32 fn_1_41488(void *, char *);
extern void fn_1_4270C(void *, u32, u16);

/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base (lbl_1_data_2A0C0); the fzgx_pool_gap_ objects span the retail objects in between, and the
 * last gap ends where retail's string literals for this function start (0x2CC38) */
u32 fzgx_obj_lbl_1_data_2A0C0[4] = {1};
u8 fzgx_pool_gap_2A0D0[0x2C824 - 0x2A0D0] = {1};
u8 fzgx_obj_lbl_1_data_2C824[0xC] = {1};
fn_1_9D420_Entry lbl_1_data_2C824__fzgx_offset_C[5] = {{NULL, 1}};
u8 fzgx_pool_gap_2C86C[0x2CB60 - 0x2C86C] = {1};
char fzgx_obj_lbl_1_data_2CB60[0x2C] = "background.c";
u8 fzgx_pool_gap_2CB8C[0x2CC38 - 0x2CB8C] = {1};

/* looks up the entry named "M<n>" (n from byte 8 of the animator's +0xC record) in its skeleton's +0x24 table
 * and passes its index to fn_1_4270C, index 0 when there is no such entry */
static inline void fn_1_9D420_motion(fn_1_9D420_Animator *anim) {
    fn_1_9D420_Skeleton *skel;
    char key[3];
    u32 index;
    u8 c;

    c = anim->unk_C[8];
    skel = anim->unk_4;
    key[0] = 'M';
    key[1] = c + '0';
    key[2] = 0;
    index = fn_1_41488(skel->unk_24, key);
    if (index == 0xFFFFFFFF) {
        index = 0;
    }
    fn_1_4270C(skel, 0, index);
}

void fn_1_9D420(fn_1_9D420_Object *obj, s32 count) {
    s32 skl_size;
    s32 mta_size;
    u8 info[0x60];
    char path[0x80];
    s32 i;
    s32 j;
    char *name;
    u32 diff;
    u32 nlen;
    u32 mlen;
    char *model;
    void **skl;
    void **mta;

    fn_80006E10("motion");
    lbl_1_bss_6EA78 = (u32)fn_1_4630(lbl_801A6410, 0x14, fzgx_obj_lbl_1_data_2CB60, 0x8D3);
    lbl_1_bss_6EA7C = (u32)fn_1_4630(lbl_801A6410, 0x14, fzgx_obj_lbl_1_data_2CB60, 0x8D4);
    for (i = 0; i < count; i++, obj++) {
        if ((obj->unk_0 & 0x1000) && obj->unk_38 != NULL) {
            for (j = 0; j < 5; j++) {
                name = lbl_1_data_2C824__fzgx_offset_C[j].unk_0;
                model = obj->unk_8->unk_8->unk_4;
                nlen = strlen(name);
                mlen = strlen(model);
                diff = mlen - nlen;
                if (((diff == 5 && fn_8006FC5C(&model[mlen - 5], "_SKL0", strlen("_SKL0")) != 0) ||
                     (diff == 4 && fn_8006FC5C(&model[mlen - 4], "_SKL", strlen("_SKL")) != 0)) &&
                    fn_8006FC5C(name, model, nlen) != 0) {
                    skl = (void **)lbl_1_bss_6EA7C;
                    if (skl[j] == NULL) {
                        sprintf(path, "%s.skl", name);
                        if (fn_1_45730(path, info) != 0) {
                            skl_size = fn_1_45B2C(info);
                            skl_size = (skl_size + 0x1F) & ~0x1F;
                            skl[j] = fn_1_45D0(lbl_801A6410, skl_size, fzgx_obj_lbl_1_data_2CB60, 0x8F5);
                            fn_1_458A0(info, skl[j], skl_size, 0);
                            fn_1_45850(info);
                        }
                    }
                    if (skl[j] != NULL) {
                        obj->unk_38->unk_0 = j;
                        obj->unk_38->unk_4 =
                            fn_1_45D0(lbl_801A6410, *(u16 *)skl[j] * 0x18C + 0x70, fzgx_obj_lbl_1_data_2CB60, 0x8FC);
                        fn_1_4247C(obj->unk_38->unk_4, (u8 *)obj->unk_38->unk_4 + 0x70, skl[j]);
                    }
                    mta = (void **)lbl_1_bss_6EA78;
                    if (mta[j] == NULL) {
                        sprintf(path, "%s_test.mta", name);
                        if (fn_1_45730(path, info) != 0) {
                            mta_size = fn_1_45B2C(info);
                            mta_size = (mta_size + 0x1F) & ~0x1F;
                            mta[j] = fn_1_45D0(lbl_801A6410, mta_size, fzgx_obj_lbl_1_data_2CB60, 0x907);
                            fn_1_458A0(info, mta[j], mta_size, 0);
                            fn_1_45850(info);
                        }
                    }
                    if (mta[j] != NULL) {
                        fn_1_426E4(obj->unk_38->unk_4, mta[j]);
                        fn_1_9D420_motion(obj->unk_38);
                    }
                    break;
                }
            }
        }
    }
    fn_80006E10("..");
}
/* fzgx:end fn_1_9D420 */
