#include "types.h"

typedef struct Fn1_1384C_Found Fn1_1384C_Found;

struct Fn1_1384C_Found {
    u8 pad_00[0x1A];
    u16 unk_1A;
    u16 unk_1C;
    u32 unk_20;
    u8 pad_24[0x1C];
};

typedef struct {
    u32 unk_0;
    u8 pad_4[0x1C];
} Fn1_1384C_Bit;

typedef struct {
    Fn1_1384C_Found *unk_0;
    u8 *unk_4;
} Fn1_1384C_Ent;

typedef struct {
    s32 unk_0;
    u32 unk_4;
    Fn1_1384C_Ent *unk_8;
} Fn1_1384C_Sub;

typedef struct {
    Fn1_1384C_Sub *unk_0;
    u32 unk_4;
} Fn1_1384C_List;

typedef struct Fn1_13A28 Fn1_13A28;

struct Fn1_13A28 {
    u8 unk_00[4];
    Fn1_13A28 *unk_04;
    Fn1_13A28 *unk_08;
    s32 unk_0c;
    Fn1_13A28 *unk_10;
    u8 unk_14[0x10];
    Fn1_13A28 *unk_24;
    Fn1_13A28 *unk_28;
    Fn1_13A28 *unk_2c;
    Fn1_13A28 *unk_30;
    Fn1_13A28 *unk_34;
    Fn1_13A28 *unk_38;
    Fn1_13A28 *unk_3c;
    Fn1_13A28 *unk_40;
    Fn1_13A28 *unk_44;
    u8 unk_48[8];
};

typedef struct ColiAnimTrack {
    s32 count;
    void *keys;
} ColiAnimTrack;

typedef struct ColiAnim {
    ColiAnimTrack tracks[6];
} ColiAnim;

typedef struct ColiBank {
    void **first;
    void **second;
} ColiBank;

typedef struct ColiExtra {
    u8 pad_0[0xC];
    f32 unk_C;
} ColiExtra;

typedef struct ColiObject {
    f32 x, y, z;
    s16 rx, ry, rz;
    u8 pad_12[2];
    ColiAnim *anim;
    f32 ox, oy, oz;
    void *unk_24;
    void **banks0[14];
    u8 pad_60[0x10];
    s32 columns;
    s32 rows;
    void *unk_78;
    void **banks1[14];
    u8 pad_B4[4];
    void *unk_B8;
    u8 pad_BC[4];
    void *unk_C0;
    u8 pad_C4[4];
    void *unk_C8;
    u8 pad_CC[4];
    void *unk_D0;
    u8 pad_D4[4];
    void *unk_D8;
    u8 pad_DC[4];
    void *unk_E0;
    u8 pad_E4[4];
    void *unk_E8;
    u8 pad_EC[8];
    ColiExtra *extra;
    u8 pad_F8[0xC];
    u32 flags;
    f32 unk_108;
    f32 unk_10C;
    ColiBank unk_110[2];
    u8 pad_120[0x4B0 - 0x120];
} ColiObject;

typedef struct ColiModelRef {
    s32 count;
    u8 *base;
    void *unk_8;
} ColiModelRef;

typedef struct ColiSub54Anim {
    u8 pad_0[0x30];
    void *unk_30;
    u8 pad_34[0x14];
    void *unk_48;
    u8 pad_4C[0x14];
    void *unk_60;
    u8 pad_64[0x14];
    void *unk_78;
    u8 pad_7C[0x14];
    void *unk_90;
    u8 pad_94[0x14];
    void *unk_A8;
    u8 pad_AC[0x14];
    void *unk_C0;
    u8 pad_C4[0x14];
    void *unk_D8;
    u8 pad_DC[0x14];
    void *unk_F0;
    u8 pad_F4[0x14];
    void *unk_108;
    u8 pad_10C[0x14];
    void *unk_120;
} ColiSub54Anim;

typedef struct ColiSub54Ptrs {
    void *unk_0;
    void *unk_4;
    void *unk_8;
    void *unk_C;
} ColiSub54Ptrs;

typedef struct ColiSub54C {
    u8 pad_0[0xC];
    void *unk_C;
} ColiSub54C;

typedef struct ColiSub54 {
    u8 pad_0[8];
    void *unk_8;
    u8 pad_C[0x24];
    ColiSub54Anim *unk_30;
    ColiSub54Ptrs *unk_34;
    ColiSub54C *unk_38;
    void *unk_3C;
} ColiSub54;

typedef struct ColiRec24 {
    void *unk_0;
    u8 pad_4[0x20];
} ColiRec24;

typedef struct ColiElem {
    u32 unk_0;
    u8 *unk_4;
    Fn1_1384C_Found *unk_8;
    u32 unk_C;
} ColiElem;

typedef struct ColiGroupC {
    u8 pad_0[0x1C];
    void *unk_1C;
    void *unk_20;
} ColiGroupC;

typedef struct ColiGroup {
    u32 unk_0;
    s32 count;
    ColiElem *elems;
    ColiGroupC *unk_C;
} ColiGroup;

typedef struct ColiRec70 {
    void *unk_0;
    u8 pad_4[0x20];
    void *unk_24;
    u8 pad_28[4];
    void *unk_2C;
    u8 pad_30[4];
    void *unk_34;
    u8 pad_38[4];
    void *unk_3C;
    u8 pad_40[4];
    void *unk_44;
    u8 pad_48[4];
    void *unk_4C;
    u8 pad_50[4];
    void *unk_54;
    u8 pad_58[4];
    void *unk_5C;
    u8 pad_60[0x10];
} ColiRec70;

typedef struct ColiRecA0 {
    u8 pad_0[0xC];
    void *unk_C;
    u8 pad_10[4];
    void *unk_14;
    u8 pad_18[4];
    void *unk_1C;
    u8 pad_20[0x80];
} ColiRecA0;

typedef struct ColiRec38 {
    u8 pad_0[0x10];
    ColiAnim *anim;
    u8 pad_14[0x24];
} ColiRec38;

typedef struct ColiHeader {
    f32 unk_0;
    f32 unk_4;
    s32 modelCount;
    ColiModelRef *models;
    u8 pad_10[4];
    void *unk_14;
    s32 objectCount;
    ColiObject *objects;
    void *unk_20;
    void *unk_24;
    u8 pad_28[4];
    void *unk_2C;
    u8 pad_30[0xC];
    void *unk_3C;
    u8 pad_40[4];
    void *unk_44;
    s32 sub54Count;
    u8 pad_4C[8];
    ColiSub54 *sub54;
    u8 pad_58[4];
    s32 rec24Count;
    ColiRec24 *rec24;
    s32 groupCount;
    ColiGroup *groups;
    s32 wordCount;
    void **words;
    s32 rec70Count;
    ColiRec70 *rec70;
    u8 pad_7C[4];
    ColiAnim *unk_80;
    void *unk_84;
    s32 recA0Count;
    ColiRecA0 *recA0;
    f32 *unk_90;
    u8 pad_94[4];
    void *unk_98;
    u8 pad_9C[4];
    void *unk_A0;
    u8 pad_A4[4];
    void *unk_A8;
    u8 pad_AC[4];
    void *unk_B0;
    s32 rec38Count;
    ColiRec38 *rec38;
    void **grid;
    u8 pad_C0[0x10];
    s32 gridColumns;
    s32 gridRows;
} ColiHeader;

typedef struct ColiRuntime {
    u32 flags;
    u8 pad_4[4];
    f32 x, y, z;
    f32 dx, dy, dz;
    s16 rx, ry, rz;
    s16 rx2, ry2, rz2;
    u8 mtx_2C[0x30];
    u8 mtx_5C[0x30];
    u8 pad_8C[0xC];
    f32 unk_98;
    u32 unk_9C;
} ColiRuntime;

extern int sprintf(char *s, const char *format, ...);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern int fn_80083BCC(const u8 *, const u8 *);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_800793D4(void *, int, u32);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006E0C8(void *);
extern void fn_1_12860(void *, void *);
extern int fn_1_45730(void *, void *);
extern int fn_1_45850(void *);
extern int fn_1_458A0(void *, void *, u32, u32);
extern void *fn_1_45D0(u32 heap, u32 size, char *file, s32 line);
extern void fn_1_465D0(char *, int);
extern void fn_1_46B4(u32 heap, void *ptr, const char *file, int line);
extern void fn_1_9D420(void *, s32);
extern void fn_1_9D77C(void *, s32);
extern u32 lbl_801A6410;
extern u8 lbl_1_bss_3BC0[32];
extern f32 lbl_1_bss_7AC88;
extern f32 lbl_1_bss_7AC9C;

void fn_1_13A28(Fn1_13A28 *arg0, s32 arg1);
void fn_1_14DE8(u32 index);

ColiHeader *lbl_1_bss_3BE0;
ColiRuntime *lbl_1_bss_3BE4;

static s8 stcoli_debug_course = -1;

/* fzgx:begin fn_1_1384C */
static inline Fn1_1384C_Found *fn_1_1384C_find(ColiElem *elem, Fn1_1384C_List **list) {
    u32 boff;
    u8 *str;
    Fn1_1384C_List **tab;
    u8 *name;
    s32 k;
    s32 isMV;
    str = elem->unk_4;
    for (tab = list; tab[0] != 0; tab++) {
        if (tab[0]->unk_0 == 0) {
            continue;
        }
        k = 0;
        boff = 0;
        for (; k < tab[0]->unk_0->unk_0; boff += 8, k++) {
            name = *(u8 **)((u8 *)tab[0]->unk_0->unk_8 + boff + 4);
            isMV = 0;
            if (name[0] == 'M' && name[1] == 'V' && name[2] == '_') {
                isMV = 1;
            }
            if ((isMV && fn_80083BCC(name + 3, str) == 0) || (!isMV && fn_80083BCC(name, str) == 0)) {
                return tab[0]->unk_0->unk_8[k].unk_0;
            }
        }
    }
    return 0;
}

void fn_1_1384C(Fn1_1384C_List **arg0) {
    Fn1_1384C_Bit *bits;
    u16 *idx;
    u8 *hdr;
    s32 n;
    s32 i;
    Fn1_1384C_Found *found;
    ColiGroup *g;
    ColiElem *e;
    s32 j;
    g = lbl_1_bss_3BE0->groups;
    for (i = 0; i < lbl_1_bss_3BE0->groupCount; i++, g++) {
        e = g->elems;
        for (j = 0; j < g->count; j++, e++) {
            e->unk_8 = found = fn_1_1384C_find(e, arg0);
            if (found != 0 && found->unk_1A == 1 && found->unk_1C == 0) {
                bits = (Fn1_1384C_Bit *)((u8 *)found + 0x40);
                hdr = (u8 *)found + found->unk_20;
                n = hdr[0x12];
                idx = (u16 *)(hdr + 0x16);
                for (; n > 0; n--) {
                    if (bits[*idx].unk_0 & 1) {
                        e->unk_0 |= 0x10;
                    } else {
                        e->unk_0 |= 8;
                    }
                    idx++;
                }
            }
        }
    }
}
/* fzgx:end fn_1_1384C */

/* fzgx:begin fn_1_13A28 */
void fn_1_13A28(Fn1_13A28 *arg0, s32 arg1) {
    Fn1_13A28 *child;

    if (arg0->unk_04 != 0) {
        arg0->unk_04 = (Fn1_13A28 *)((u8 *)arg0->unk_04 + arg1);
    }
    if (arg0->unk_08 != 0) {
        arg0->unk_08 = (Fn1_13A28 *)((u8 *)arg0->unk_08 + arg1);
    }
    if (arg0->unk_10 != 0) {
        arg0->unk_10 = (Fn1_13A28 *)((u8 *)arg0->unk_10 + arg1);
    }

    child = arg0->unk_04;
    if (child->unk_24 != 0) {
        child->unk_24 = (Fn1_13A28 *)((u8 *)child->unk_24 + arg1);
    }
    if (child->unk_28 != 0) {
        child->unk_28 = (Fn1_13A28 *)((u8 *)child->unk_28 + arg1);
    }
    if (child->unk_2c != 0) {
        child->unk_2c = (Fn1_13A28 *)((u8 *)child->unk_2c + arg1);
    }
    if (child->unk_30 != 0) {
        child->unk_30 = (Fn1_13A28 *)((u8 *)child->unk_30 + arg1);
    }
    if (child->unk_34 != 0) {
        child->unk_34 = (Fn1_13A28 *)((u8 *)child->unk_34 + arg1);
    }
    if (child->unk_38 != 0) {
        child->unk_38 = (Fn1_13A28 *)((u8 *)child->unk_38 + arg1);
    }
    if (child->unk_3c != 0) {
        child->unk_3c = (Fn1_13A28 *)((u8 *)child->unk_3c + arg1);
    }
    if (child->unk_40 != 0) {
        child->unk_40 = (Fn1_13A28 *)((u8 *)child->unk_40 + arg1);
    }
    if (child->unk_44 != 0) {
        child->unk_44 = (Fn1_13A28 *)((u8 *)child->unk_44 + arg1);
    }

    if (arg0->unk_0c > 0) {
        s32 i;
        Fn1_13A28 *entry = arg0->unk_10;
        for (i = 0; i < arg0->unk_0c; entry += 1) {
            fn_1_13A28(entry, arg1);
            i++;
        }
    }
}
/* fzgx:end fn_1_13A28 */

/* fzgx:begin fn_1_13B98 */
#define OFFSET_TO_PTR(base, offset) (void *)((u32)(offset) + (u32)(base))

static inline void adjust_anim_ptrs(ColiAnim **pAnim, ColiHeader *base) {
    *pAnim = OFFSET_TO_PTR(base, *pAnim);
    if ((*pAnim)->tracks[0].keys != NULL)
        (*pAnim)->tracks[0].keys = OFFSET_TO_PTR(base, (*pAnim)->tracks[0].keys);
    if ((*pAnim)->tracks[1].keys != NULL)
        (*pAnim)->tracks[1].keys = OFFSET_TO_PTR(base, (*pAnim)->tracks[1].keys);
    if ((*pAnim)->tracks[2].keys != NULL)
        (*pAnim)->tracks[2].keys = OFFSET_TO_PTR(base, (*pAnim)->tracks[2].keys);
    if ((*pAnim)->tracks[3].keys != NULL)
        (*pAnim)->tracks[3].keys = OFFSET_TO_PTR(base, (*pAnim)->tracks[3].keys);
    if ((*pAnim)->tracks[4].keys != NULL)
        (*pAnim)->tracks[4].keys = OFFSET_TO_PTR(base, (*pAnim)->tracks[4].keys);
    if ((*pAnim)->tracks[5].keys != NULL)
        (*pAnim)->tracks[5].keys = OFFSET_TO_PTR(base, (*pAnim)->tracks[5].keys);
}

static inline void adjust_sub54_anim(ColiSub54Anim **pAnim, ColiHeader *base) {
    *pAnim = OFFSET_TO_PTR(base, *pAnim);
    if ((*pAnim)->unk_30 != NULL) (*pAnim)->unk_30 = OFFSET_TO_PTR(base, (*pAnim)->unk_30);
    if ((*pAnim)->unk_48 != NULL) (*pAnim)->unk_48 = OFFSET_TO_PTR(base, (*pAnim)->unk_48);
    if ((*pAnim)->unk_60 != NULL) (*pAnim)->unk_60 = OFFSET_TO_PTR(base, (*pAnim)->unk_60);
    if ((*pAnim)->unk_78 != NULL) (*pAnim)->unk_78 = OFFSET_TO_PTR(base, (*pAnim)->unk_78);
    if ((*pAnim)->unk_90 != NULL) (*pAnim)->unk_90 = OFFSET_TO_PTR(base, (*pAnim)->unk_90);
    if ((*pAnim)->unk_A8 != NULL) (*pAnim)->unk_A8 = OFFSET_TO_PTR(base, (*pAnim)->unk_A8);
    if ((*pAnim)->unk_C0 != NULL) (*pAnim)->unk_C0 = OFFSET_TO_PTR(base, (*pAnim)->unk_C0);
    if ((*pAnim)->unk_D8 != NULL) (*pAnim)->unk_D8 = OFFSET_TO_PTR(base, (*pAnim)->unk_D8);
    if ((*pAnim)->unk_F0 != NULL) (*pAnim)->unk_F0 = OFFSET_TO_PTR(base, (*pAnim)->unk_F0);
    if ((*pAnim)->unk_108 != NULL) (*pAnim)->unk_108 = OFFSET_TO_PTR(base, (*pAnim)->unk_108);
    if ((*pAnim)->unk_120 != NULL) (*pAnim)->unk_120 = OFFSET_TO_PTR(base, (*pAnim)->unk_120);
}

static inline void adjust_sub54_ptrs(ColiSub54Ptrs **pPtrs, ColiHeader *base) {
    *pPtrs = OFFSET_TO_PTR(base, *pPtrs);
    if ((*pPtrs)->unk_0 != NULL) (*pPtrs)->unk_0 = (void *)((u32)base + (u32)(*pPtrs)->unk_0);
    if ((*pPtrs)->unk_4 != NULL) (*pPtrs)->unk_4 = (void *)((u32)base + (u32)(*pPtrs)->unk_4);
    if ((*pPtrs)->unk_8 != NULL) (*pPtrs)->unk_8 = (void *)((u32)base + (u32)(*pPtrs)->unk_8);
    if ((*pPtrs)->unk_C != NULL) (*pPtrs)->unk_C = (void *)((u32)base + (u32)(*pPtrs)->unk_C);
}

static inline void adjust_sub54_c(ColiSub54C **pC, ColiHeader *base) {
    *pC = OFFSET_TO_PTR(base, *pC);
    if ((*pC)->unk_C != NULL) (*pC)->unk_C = OFFSET_TO_PTR(base, (*pC)->unk_C);
}

#define RELOC(field) if ((field) != NULL) (field) = OFFSET_TO_PTR(lbl_1_bss_3BE0, (field))

static inline void init_runtimes(void) {
    u32 saved;
    ColiRuntime *rt = lbl_1_bss_3BE4;
    ColiObject *obj;
    s32 i;

        for (i = 0, obj = lbl_1_bss_3BE0->objects; i < lbl_1_bss_3BE0->objectCount; i++, obj++, rt++) {
            saved = rt->unk_9C;
            fn_80008BEC(rt, 0, sizeof(ColiRuntime));
            rt->unk_9C = saved;
            rt->x = obj->x;
            rt->y = obj->y;
            rt->z = obj->z;
            rt->dx = obj->x - obj->ox;
            rt->dy = obj->y - obj->oy;
            rt->dz = obj->z - obj->oz;
            rt->rx = obj->rx;
            rt->ry = obj->ry;
            rt->rz = obj->rz;
            rt->rx2 = obj->rx;
            rt->ry2 = obj->ry;
            rt->rz2 = obj->rz;
            lbl_8006D758();
            lbl_8006DB74(rt->mtx_2C);
            lbl_8006E0C8(&obj->ox);
            lbl_8006DB74(rt->mtx_5C);
            if (obj->extra != NULL) {
                rt->unk_98 = obj->extra->unk_C;
            }
            rt->flags |= obj->flags;
        }
}

void fn_1_13B98(s32 course, s32 initModels) {
    char path[32];
    u8 file[0x5C];
    u32 compSize;
    u32 uncompSize;
    void *compData;
    void *uncompData;
    s32 i;

    if (stcoli_debug_course != -1) {
        course = stcoli_debug_course;
        stcoli_debug_course = -1;
    }
    sprintf((void *)path, (void *)("stage/COLI_COURSE%02d.lz"), course);
    if (fn_1_45730(path, file) == 0) {
        fn_1_45730("stage/COLI_COURSE01.lz", file);
    }
    fn_1_458A0(file, lbl_1_bss_3BC0, 0x20, 0);
    compSize = (__lwbrx(lbl_1_bss_3BC0, 0) + 0x27) & ~0x1F;
    uncompSize = (__lwbrx(lbl_1_bss_3BC0, 4) + 0x1F) & ~0x1F;
    uncompData = fn_1_45D0(lbl_801A6410, uncompSize, "stcoli.c", 0x181);
    compData = fn_1_45D0(lbl_801A6410, compSize, "stcoli.c", 0x182);
    if (fn_1_458A0(file, compData, compSize, 0) < 0) {
        OSPanic((void *)("stcoli.c"), 0x184, (void *)("cannot Read"));
    }
    if (fn_1_45850(file) == 0) {
        OSPanic((void *)("stcoli.c"), 0x185, (void *)("cannot Close"));
    }
    fn_1_12860(compData, uncompData);
    fn_1_46B4(lbl_801A6410, compData, "stcoli.c", 0x189);

    lbl_1_bss_3BE0 = uncompData;
    if (lbl_1_bss_3BE0->models != NULL) {
        ColiModelRef *model;
        void *prev = NULL;

        RELOC(lbl_1_bss_3BE0->models);
        for (i = 0, model = lbl_1_bss_3BE0->models; i < lbl_1_bss_3BE0->modelCount; i++, model++) {
            RELOC(model->base);
            RELOC(model->unk_8);
            if (prev != model->unk_8) {
                fn_1_13A28((struct Fn1_13A28 *)model->unk_8, (s32)lbl_1_bss_3BE0);
            }
            prev = model->unk_8;
        }
    }
    RELOC(lbl_1_bss_3BE0->unk_14);
    lbl_1_bss_3BE0->objects = OFFSET_TO_PTR(lbl_1_bss_3BE0, lbl_1_bss_3BE0->objects);
    {
        ColiObject *obj;

        for (i = 0, obj = lbl_1_bss_3BE0->objects; i < lbl_1_bss_3BE0->objectCount; i++, obj++) {
            s32 j;

            if (0.0f == obj->unk_108 && 0.0f == obj->unk_10C) {
                obj->unk_108 = lbl_1_bss_3BE0->unk_0;
                obj->unk_10C = lbl_1_bss_3BE0->unk_4;
            }
            if (obj->anim != NULL) {
                adjust_anim_ptrs(&obj->anim, lbl_1_bss_3BE0);
            }
            RELOC(obj->unk_24);
            for (j = 0; j < 14; j++) {
                if (obj->banks0[j] != NULL) {
                    s32 k;
                    void **q;

                    obj->banks0[j] = OFFSET_TO_PTR(lbl_1_bss_3BE0, obj->banks0[j]);
                    for (k = 0, q = obj->banks0[j]; k < obj->columns * obj->rows; k++, q++) {
                        RELOC(*q);
                    }
                }
            }
            RELOC(obj->unk_78);
            for (j = 0; j < 14; j++) {
                if (obj->banks1[j] != NULL) {
                    s32 k;
                    void **q;

                    obj->banks1[j] = OFFSET_TO_PTR(lbl_1_bss_3BE0, obj->banks1[j]);
                    for (k = 0, q = obj->banks1[j]; k < obj->columns * obj->rows; k++, q++) {
                        RELOC(*q);
                    }
                }
            }
            RELOC(obj->unk_B8);
            RELOC(obj->unk_C0);
            RELOC(obj->unk_C8);
            RELOC(obj->unk_D0);
            RELOC(obj->unk_D8);
            RELOC(obj->unk_E0);
            RELOC(obj->extra);
            RELOC(obj->unk_E8);
            for (j = 0; j < 2; j++) {
                RELOC(obj->unk_110[j].first);
                RELOC(obj->unk_110[j].second);
            }
        }
    }
    RELOC(lbl_1_bss_3BE0->unk_20);
    RELOC(lbl_1_bss_3BE0->unk_24);
    RELOC(lbl_1_bss_3BE0->unk_2C);
    RELOC(lbl_1_bss_3BE0->unk_3C);
    RELOC(lbl_1_bss_3BE0->unk_44);
    RELOC(lbl_1_bss_3BE0->rec24);
    for (i = 0; i < lbl_1_bss_3BE0->rec24Count; i++) {
        lbl_1_bss_3BE0->rec24[i].unk_0 = (void *)((u32)lbl_1_bss_3BE0 + (u32)lbl_1_bss_3BE0->rec24[i].unk_0);
    }
    RELOC(lbl_1_bss_3BE0->words);
    for (i = 0; i < lbl_1_bss_3BE0->wordCount; i++) {
        lbl_1_bss_3BE0->words[i] = (void *)((u32)lbl_1_bss_3BE0 + (u32)lbl_1_bss_3BE0->words[i]);
    }
    if (lbl_1_bss_3BE0->unk_80 != NULL) {
        ColiAnim *anim;

        lbl_1_bss_3BE0->unk_80 = OFFSET_TO_PTR(lbl_1_bss_3BE0, lbl_1_bss_3BE0->unk_80);
        anim = lbl_1_bss_3BE0->unk_80;
        anim->tracks[0].keys = OFFSET_TO_PTR(lbl_1_bss_3BE0, anim->tracks[0].keys);
        anim->tracks[1].keys = OFFSET_TO_PTR(lbl_1_bss_3BE0, anim->tracks[1].keys);
        anim->tracks[2].keys = OFFSET_TO_PTR(lbl_1_bss_3BE0, anim->tracks[2].keys);
        anim->tracks[3].keys = OFFSET_TO_PTR(lbl_1_bss_3BE0, anim->tracks[3].keys);
        anim->tracks[4].keys = OFFSET_TO_PTR(lbl_1_bss_3BE0, anim->tracks[4].keys);
        anim->tracks[5].keys = OFFSET_TO_PTR(lbl_1_bss_3BE0, anim->tracks[5].keys);
    }
    RELOC(lbl_1_bss_3BE0->unk_84);
    RELOC(lbl_1_bss_3BE0->recA0);
    for (i = 0; i < lbl_1_bss_3BE0->recA0Count; i++) {
        ColiRecA0 *rec = &lbl_1_bss_3BE0->recA0[i];

        RELOC(rec->unk_C);
        RELOC(rec->unk_14);
        RELOC(rec->unk_1C);
    }
    RELOC(lbl_1_bss_3BE0->rec70);
    for (i = 0; i < lbl_1_bss_3BE0->rec70Count; i++) {
        ColiRec70 *rec = &lbl_1_bss_3BE0->rec70[i];

        rec->unk_0 = OFFSET_TO_PTR(lbl_1_bss_3BE0, rec->unk_0);
        RELOC(rec->unk_24);
        RELOC(rec->unk_2C);
        RELOC(rec->unk_34);
        RELOC(rec->unk_3C);
        RELOC(rec->unk_44);
        RELOC(rec->unk_4C);
        RELOC(rec->unk_54);
        if (rec->unk_4C != NULL) {
            rec->unk_5C = OFFSET_TO_PTR(lbl_1_bss_3BE0, rec->unk_5C);
        }
    }
    RELOC(lbl_1_bss_3BE0->unk_90);
    RELOC(lbl_1_bss_3BE0->unk_98);
    RELOC(lbl_1_bss_3BE0->unk_A0);
    RELOC(lbl_1_bss_3BE0->unk_A8);
    RELOC(lbl_1_bss_3BE0->unk_B0);
    if (lbl_1_bss_3BE0->rec38 != NULL) {
        ColiRec38 *rec;

        lbl_1_bss_3BE0->rec38 = OFFSET_TO_PTR(lbl_1_bss_3BE0, lbl_1_bss_3BE0->rec38);
        for (i = 0, rec = lbl_1_bss_3BE0->rec38; i < lbl_1_bss_3BE0->rec38Count; i++, rec++) {
            if (rec->anim != NULL) {
                adjust_anim_ptrs(&rec->anim, lbl_1_bss_3BE0);
            }
        }
    }
    if (lbl_1_bss_3BE0->grid != NULL) {
        void **cell;

        lbl_1_bss_3BE0->grid = OFFSET_TO_PTR(lbl_1_bss_3BE0, lbl_1_bss_3BE0->grid);
        for (i = 0, cell = lbl_1_bss_3BE0->grid; i < lbl_1_bss_3BE0->gridColumns * lbl_1_bss_3BE0->gridRows; i++, cell++) {
            RELOC(*cell);
        }
    }
    if (lbl_1_bss_3BE0->sub54 != NULL) {
        ColiSub54 *sub;

        lbl_1_bss_3BE0->sub54 = OFFSET_TO_PTR(lbl_1_bss_3BE0, lbl_1_bss_3BE0->sub54);
        for (i = 0, sub = lbl_1_bss_3BE0->sub54; i < lbl_1_bss_3BE0->sub54Count; i++, sub++) {
            if (sub->unk_30 != NULL) {
                adjust_sub54_anim(&sub->unk_30, lbl_1_bss_3BE0);
            }
            if (sub->unk_34 != NULL) {
                adjust_sub54_ptrs(&sub->unk_34, lbl_1_bss_3BE0);
            }
            if (sub->unk_38 != NULL) {
                adjust_sub54_c(&sub->unk_38, lbl_1_bss_3BE0);
            }
            RELOC(sub->unk_3C);
            sub->unk_8 = OFFSET_TO_PTR(lbl_1_bss_3BE0, sub->unk_8);
        }
    }
    if (lbl_1_bss_3BE0->groupCount > 0) {
        ColiGroup *group;

        lbl_1_bss_3BE0->groups = OFFSET_TO_PTR(lbl_1_bss_3BE0, lbl_1_bss_3BE0->groups);
        for (i = 0, group = lbl_1_bss_3BE0->groups; i < lbl_1_bss_3BE0->groupCount; i++, group++) {
            ColiElem *elem;
            s32 j;

            group->elems = OFFSET_TO_PTR(lbl_1_bss_3BE0, group->elems);
            for (j = 0, elem = group->elems; j < group->count; j++, elem++) {
                elem->unk_4 = OFFSET_TO_PTR(lbl_1_bss_3BE0, elem->unk_4);
            }
            if (group->unk_C != NULL) {
                ColiGroupC *c;

                group->unk_C = OFFSET_TO_PTR(lbl_1_bss_3BE0, group->unk_C);
                c = group->unk_C;
                RELOC(c->unk_1C);
                RELOC(c->unk_20);
            }
        }
    }

    lbl_1_bss_3BE4 = fn_1_45D0(lbl_801A6410, lbl_1_bss_3BE0->objectCount * sizeof(ColiRuntime), "stcoli.c", 0x2A7);
    fn_800793D4(lbl_1_bss_3BE4, 0, lbl_1_bss_3BE0->objectCount * sizeof(ColiRuntime));
    init_runtimes();
    if (initModels != 0 && lbl_1_bss_3BE0->sub54 != NULL) {
        fn_1_9D420(lbl_1_bss_3BE0->sub54, lbl_1_bss_3BE0->sub54Count);
    }
    lbl_1_bss_7AC88 = *lbl_1_bss_3BE0->unk_90 / 512.0f;
    lbl_1_bss_7AC9C = 512.0f / *lbl_1_bss_3BE0->unk_90;
    if (lbl_1_bss_3BE0->models != NULL) {
        fn_1_14DE8(course);
    }
}
#undef OFFSET_TO_PTR
#undef RELOC
/* fzgx:end fn_1_13B98 */

/* fzgx:begin fn_1_14CB4 */
void fn_1_14CB4(void) {
    if (lbl_1_bss_3BE0 != NULL) {
        if (lbl_1_bss_3BE0->sub54 != NULL) {
            fn_1_9D77C(lbl_1_bss_3BE0->sub54, lbl_1_bss_3BE0->sub54Count);
        }

        fn_1_46B4(lbl_801A6410, lbl_1_bss_3BE4, "stcoli.c", 0x2c9);
        lbl_1_bss_3BE4 = NULL;
        fn_1_46B4(lbl_801A6410, lbl_1_bss_3BE0, "stcoli.c", 0x2cb);
        lbl_1_bss_3BE0 = NULL;
    }
}
/* fzgx:end fn_1_14CB4 */

/* fzgx:begin fn_1_14D5C */
void fn_1_14D5C(char *arg0, int arg1) {
    char buffer[32];

    sprintf(buffer, "stage/COLI_COURSE%02d.lz", arg0);
    if (arg1 != 0) {
        fn_1_465D0(buffer, 2);
    } else {
        fn_1_465D0(buffer, 1);
    }
}
/* fzgx:end fn_1_14D5C */

/* fzgx:begin fn_1_14DC4 */
u32 fn_1_14DC4(void) {
    if (lbl_1_bss_3BE0 != 0) {
        return (u32)lbl_1_bss_3BE0->unk_14;
    }
    return 0;
}
/* fzgx:end fn_1_14DC4 */

/* fzgx:begin fn_1_14DE8 */
typedef struct StcoliEntry {
    s32 unk_0;
    s32 unk_4;
    s8 unk_8;
    s8 unk_9;
} StcoliEntry;

StcoliEntry lbl_1_data_51F0[] = { {0x8B, 0, 0, 1}, {0x8C, 0, 1, 0}, {-1, 0, 0, 0} };
StcoliEntry lbl_1_data_5214[] = {
    {0x20, 0, 1, 0}, {0x21, 0, 1, 0}, {0x22, 0, 1, 0}, {0x23, 0, 1, 0}, {0x24, 0, 1, 0}, {0x25, 0, 1, 0},
    {0x26, 0, 1, 0}, {0x27, 0, 1, 0}, {0x28, 0, 1, 0}, {0x29, 0, 1, 0}, {0x2A, 0, 1, 0}, {-1, 0, 0, 0},
};
StcoliEntry lbl_1_data_52A4[] = {
    {0x5E, 0, 0, 1}, {0x5F, 0, 1, 0}, {0x5F, 1, 1, 0}, {0x5F, 2, 1, 0}, {0x79, 0, 0, 1}, {0x79, 1, 0, 1},
    {0x79, 2, 0, 1}, {0x7A, 0, 1, 0}, {-1, 0, 0, 0},
};
StcoliEntry lbl_1_data_5310[] = {
    {0x43, 0, 0, 1}, {0x44, 0, 1, 0}, {0x4F, 0, 0, 1}, {0x50, 0, 1, 0}, {0x5B, 0, 0, 1}, {0x5C, 0, 1, 0},
    {-1, 0, 0, 0},
};
StcoliEntry lbl_1_data_5364[] = {
    {0xA, 0, 0, 1}, {0xB, 1, 1, 0}, {0xB, 0, 1, 0}, {0x14, 0, 0, 1}, {0x15, 0, 1, 0}, {-1, 0, 0, 0},
};
StcoliEntry lbl_1_data_53AC[] = {
    {0x73, 0, 0, 1}, {0x74, 0, 1, 0}, {0x74, 1, 1, 0}, {0x74, 2, 1, 0}, {0x90, 0, 0, 1}, {0x90, 1, 0, 1},
    {0x90, 2, 0, 1}, {0x91, 0, 1, 0}, {0xA7, 0, 0, 1}, {0xA8, 0, 1, 0}, {0xA8, 1, 1, 0}, {0xA8, 2, 1, 0},
    {0xC6, 0, 0, 1}, {0xC6, 1, 0, 1}, {0xC6, 2, 0, 1}, {0xC7, 0, 1, 0}, {-1, 0, 0, 0},
};
/* No entry of lbl_1_data_54B4 points to this table. */
StcoliEntry lbl_1_data_5478[] = { {0x9, 0, 0, 1}, {0xA, 0, 1, 0}, {0x13, 0, 0, 1}, {0x14, 0, 1, 0}, {-1, 0, 0, 0} };

StcoliEntry *lbl_1_data_54B4[36] = {
    NULL, NULL, NULL, lbl_1_data_51F0, NULL, NULL, NULL, lbl_1_data_5214, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, lbl_1_data_52A4, NULL, NULL, NULL, NULL, lbl_1_data_5310, NULL, NULL,
    NULL, NULL, NULL, lbl_1_data_5364, lbl_1_data_53AC, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

typedef struct StcoliPart {
    u8 pad_0[8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[8];
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    u8 pad_34[8];
    f32 unk_3C;
    u8 pad_40[0xC];
    s8 unk_4C;
    s8 unk_4D;
    u8 pad_4E[2];
} StcoliPart;

/* WARNING: compiler-diff device, not original code */
#pragma opt_loop_invariants off
/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

void fn_1_14DE8(u32 index) {
    StcoliEntry *entry;
    ColiModelRef *record;
    StcoliPart *part;
    f32 zero;
    f32 value;

    if (lbl_1_bss_3BE0 == NULL) {
        return;
    }
    if (index >= 0x24) {
        return;
    }
    entry = lbl_1_data_54B4[index];
    if (entry == NULL) {
        return;
    }
    while (entry->unk_0 >= 0) {
        record = lbl_1_bss_3BE0->models + entry->unk_0;
        if (entry->unk_4 >= record->count) {
            return;
        }
        part = (StcoliPart *)record->base + entry->unk_4;
        if (entry->unk_8) {
            if ((s32)index == 7) {
                zero = 0.0f;
                value = 1.0f;
                part->unk_C = zero;
                part->unk_10 = zero;
                part->unk_14 = value;
                part->unk_8 = -part->unk_20;
            } else if (!part->unk_4C) {
                part->unk_4C = 1;
            }
        }
        if (entry->unk_9) {
            if ((s32)index == 7) {
                zero = 0.0f;
                value = -1.0f;
                part->unk_28 = zero;
                part->unk_2C = zero;
                part->unk_30 = value;
                part->unk_24 = part->unk_3C;
            } else if (!part->unk_4D) {
                part->unk_4D = 1;
            }
        }
        entry++;
    }
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_14DE8 */
