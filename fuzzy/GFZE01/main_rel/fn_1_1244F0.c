/* Non-matching: best partial attempt (92.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/accessory.h"
#include "rel/main_rel/cloth.h"
#include "psvec.h"
#include "types.h"

/* begin game/main_rel/accessory_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_ACCESSORY_TYPES_H
#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


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

struct fn_1_108920_lbl_801A6410 {
    u32 unk_0;
};

/* game/main_rel/shared_types.h: inlined above */

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
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
};

/* game/main_rel/shared_types.h: inlined above */

struct fn_1_129D9C_system {
    u8 pad_0[0x2C];
    f32 unk_2C;
};

typedef struct Node10C4E4 {
    u8 flag;
    u8 pad[0x13];
    f32 keyA;
    f32 keyB;
    u8 pad2[0x24];
    f32 value;
} Node10C4E4;

typedef struct Edge10C4E4 {
    Node10C4E4 *a;
    Node10C4E4 *b;
    u32 pad;
} Edge10C4E4;

typedef struct Graph10C4E4 {
    u8 pad[0x18];
    u32 nodeCount;
    u32 edgeCount;
    u32 pad2;
    Node10C4E4 *nodes;
    Edge10C4E4 *edges;
} Graph10C4E4;

typedef struct fn_1_10D2F0_Vec3 {
    f32 x, y, z;
} fn_1_10D2F0_Vec3;

typedef struct fn_1_10D2F0_Entry {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0xE];
    fn_1_10D2F0_Vec3 unk_10;
    fn_1_10D2F0_Vec3 unk_1C;
    fn_1_10D2F0_Vec3 unk_28;
    u8 pad_34[0xC];
    f32 unk_40;
} fn_1_10D2F0_Entry;

typedef struct fn_1_10D2F0_Link {
    fn_1_10D2F0_Entry *a;
    fn_1_10D2F0_Entry *b;
    f32 len;
} fn_1_10D2F0_Link;

typedef struct fn_1_10D2F0_Obj {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[4];
    fn_1_10D2F0_Entry *unk_24;
    fn_1_10D2F0_Link *unk_28;
} fn_1_10D2F0_Obj;

struct fn_1_10D2F0_rodata {
    u8 pad_0[0x64];
    f32 unk_64;   /* -1.0f */
    f32 unk_68;   /* 0.0f */
    u8 pad_6C[0xFC];
    f64 unk_168;  /* 0.015 */
    f32 unk_170;  /* -0.5f */
    u8 pad_174[0x4];
    f64 unk_178;  /* 0.045 */
};

typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

typedef struct {
    f32 zero;           /* 0x0 */
    u8 pad_4[0xC];
    f32 one;            /* 0x10 */
    u8 pad_14[0x64];
    u32 tbl3[3];        /* 0x78 */
    u32 tbl4[4];        /* 0x84 */
    u8 str[4];          /* 0x94 */
} Pool_12999C;

typedef struct {
    u8 pad_0[0x9];
    u8 count;           /* 0x9 */
    u8 pad_A[0x14A6];
} Info_12999C;

typedef struct {
    u32 flags;          /* 0x0 */
    u8 pad_4[0x148];
    u8 body[0x329];     /* 0x14c */
    s8 slot;            /* 0x475 */
    u8 pad_476[0x26];
    u8 *info;           /* 0x49c */
} Entry_12999C;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_12999C;

typedef struct {
    u32 words[6];
} Tmp_12999C;

struct fn_1_129D9C_vec {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

struct fn_1_129D9C_obj {
    u8 pad_0[0x10];
    u8 unk_10;
};

typedef struct {
    f32 value0;
    f32 value1;
    f32 value2;
} Sig_fn_8006F78C_Fn8006F78CData;

extern const struct fn_1_10D2F0_rodata lbl_1_rodata_7AB8;
extern f32 fn_1_1289BC(const Point1024C4 *a, const Point1024C4 *b);
extern const struct fn_1_129D9C_rodata lbl_1_rodata_8068;
extern u32 fn_1_862A8(u32, Vec3_12999C *);
extern void fn_8006F78C(void *, Sig_fn_8006F78C_Fn8006F78CData *, f32);
extern void * fn_80077B64(struct Sig_fn_80077B64_fn_80077B64_Arg0 *);
extern void C_MTXOrtho(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern struct fn_1_129D9C_system *lbl_801A6D00;

#endif  // GAME_MAIN_REL_ACCESSORY_TYPES_H

/* end game/main_rel/accessory_types.h */

extern void fn_1_10846C(fn_1_10D2F0_Obj *);
extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20;
extern void fn_1_128884(void *, void *, s32);
extern void *fn_1_4630(u32, u32, const char *, s32);
extern u32 lbl_801A6410;

#define W 9
#define FN fn_1_1244F0
#define LINE 0x2904
#define ZROW(ROW) \
        for (i = 0, b = (ROW); i < W; i++, b++) { \
            for (m = i + 1, e = b + 1; m < W; m++, e++) { \
                if (b->unk_10.z > 0.0f && e->unk_10.z > 0.0f && b->unk_10.y > e->unk_10.y) { \
                    fn_1_128884(b, e, sizeof(fn_1_10D2F0_Entry)); \
                } else if (b->unk_10.z <= 0.0f && e->unk_10.z <= 0.0f && b->unk_10.y < e->unk_10.y) { \
                    fn_1_128884(b, e, sizeof(fn_1_10D2F0_Entry)); \
                } \
            } \
        }

void FN(fn_1_10D2F0_Obj *obj) {
    u32 i;
    u32 j;
    u32 m;
    fn_1_10D2F0_Entry *b;
    fn_1_10D2F0_Entry *a;
    fn_1_10D2F0_Entry *e;
    u32 n;
    u32 rows;
    u32 k;
    u32 c;
    fn_1_10D2F0_Entry *p;

    if (obj != NULL) {
        fn_1_10846C(obj);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, p++) {
            if (p->unk_0 & 1) {
                p->unk_0 = 0;
                p->unk_40 = lbl_1_rodata_7B1C;
            } else {
                p->unk_0 = 1;
                p->unk_40 = lbl_1_rodata_7B20;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == 0 && b->unk_0 != 0) {
                    fn_1_128884(a, b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == b->unk_0 && a->unk_10.x < b->unk_10.x) {
                    fn_1_128884(a, b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        for (k = 0; k < obj->unk_18 / W; k++, a += W) {
            for (i = 0, b = a; i < W; i++, b++) {
                for (m = i + 1, e = b + 1; m < W; m++, e++) {
                    if (b->unk_10.z < e->unk_10.z) {
                        fn_1_128884(b, e, sizeof(fn_1_10D2F0_Entry));
                    }
                }
            }
        }

        ZROW(obj->unk_24)

        a = obj->unk_24;
        n = obj->unk_18;
        for (i = 0; i < n; i++, a++) {
            if (a->unk_0 != 0 && a[1].unk_0 == 0) {
                break;
            }
        }
        a++;
        rows = (n - (a - obj->unk_24)) / W;

        for (k = 0; k < rows; k++, a += W) {
            for (i = 0; i < W; i++) {
                a[i].unk_40 = -(f32)(k + 1) / (f32)(rows + 1);
            }
            ZROW(a)
        }

        obj->unk_1C = (obj->unk_18 / W) * (W - 1) + (obj->unk_18 / W - 1) * W;
        obj->unk_28 = fn_1_4630(lbl_801A6410, obj->unk_1C * sizeof(fn_1_10D2F0_Link), ((const char *)&lbl_1_data_40530), LINE);

        c = 0;
        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 1; i++, a++) {
            if ((i + 1) % W != 0) {
                obj->unk_28[c].a = a;
                obj->unk_28[c].b = a + 1;
                obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 1));
                c++;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - W; i++, a++) {
            obj->unk_28[c].a = a;
            obj->unk_28[c].b = a + W;
            obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + W));
            c++;
        }
    }
}
