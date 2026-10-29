#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/face.h"

extern u32 lbl_801A6410;
extern u32 lbl_1_bss_7ACEC;
extern u32 fn_1_45D0(u32, u32, void*, u32);
extern u32 fn_80008F88(void*, u32);
extern void fn_80009064(u32);
extern void fn_1_46B4(u32, u32, u8*, int);
extern void fn_1_D2F50(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_D2F84(void);
extern s16 fn_1_3F0C8(void *obj);
extern u32 fn_1_864E8(u32 value);
extern void OSPanic(char*, ...);
extern u32 fn_1_86810(u32);
extern void qsort(void*, u32, u32, void*);
extern s32 fn_1_D2E18(u8*, u8*);
extern u32 lbl_1_bss_7AD00;
extern u32 lbl_1_bss_7AD04;
extern u32 lbl_1_bss_7AD08[7];
extern u32 lbl_1_bss_7AD24[9];
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CFC;
extern void* fn_1_48E8(u32, u32);
extern void OSLink(void*, void*);
extern void OSReport(char*, ...);

/* fzgx:begin fn_1_D1780 */
void fn_1_D1780(void) {
    u32 result;

    lbl_1_bss_7ACEC = 0x40000;
    result = fn_1_45D0(lbl_801A6410, 0x40000, lbl_1_data_3DA2C, 0x14a);
    lbl_1_bss_7ACF0 = result;
    lbl_1_data_3D924 = fn_80008F88((void*)result, result + lbl_1_bss_7ACEC);
}
/* fzgx:end fn_1_D1780 */

/* fzgx:begin fn_1_D17E8 */
void fn_1_D17E8(void) {
    fn_80009064(lbl_1_data_3D924);
    fn_1_46B4(lbl_801A6410, lbl_1_bss_7ACF0, lbl_1_data_3DA2C, 0x152);
    lbl_1_data_3D924 = -1;
}
/* fzgx:end fn_1_D17E8 */

/* fzgx:begin fn_1_D1848 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/face.h"

extern u32 lbl_801A6410;
extern u32 lbl_1_rodata_60A0[46];
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern u8 fn_1_86624(void);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_1_D2F50(void);
extern void fn_1_D2F84(void);
extern void *memset(void *, int, u32);
typedef u8 Sig_GXGetTexBufferSize_GXBool;
typedef union {
    u32 w;
    struct { u32 lo : 2; u32 rest : 30; } f;
} FlagU;
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7ACD8;
u32 lbl_1_bss_7ACDC;
u32 lbl_1_bss_7ACE0;
u8 lbl_1_bss_7ACE0__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_7ACE5;
u16 fzgx_pool_lbl_1_bss_7ACD8_gap_7ACE6;
u32 fzgx_obj_lbl_1_bss_7ACE8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ACD8;
    s = *(u8 *)&lbl_1_bss_7ACDC;
    s = *(u8 *)&lbl_1_bss_7ACE0;
    s = *(u8 *)&lbl_1_bss_7ACE0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ACE5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7ACD8_gap_7ACE6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ACE8;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("face.c");
}
#pragma section code_type ".text"

#pragma peephole off
static inline u32 fn_1_D1848_array_read(s32 index, u32 *array) { return array[index]; }
#pragma peephole reset

#pragma opt_loop_invariants off
#pragma opt_propagation off
void fn_1_D1848(void) {
    u32 texsize;
    s32 i;
    Obj_1_bss_7ACD8_Target *obj;
    u32 c0;
    u32 c1;
    u8 idx;

    
    fn_1_D2F50();
    fzgx_obj_lbl_1_bss_7ACD8 = fn_1_4630(lbl_801A6410, 0x258, (u8 *)"face.c", 0x15F);
    fzgx_obj_lbl_1_bss_7ACE8 = 0;
    idx = fn_1_86624();
    *(u8 *)((u8 *)&lbl_1_bss_7ACE0__fzgx_offset_4) = idx;
    lbl_1_bss_7ACDC = fn_1_4630(lbl_801A6410, idx << 2, (u8 *)"face.c", 0x173);
    lbl_1_bss_7ACE0 = fn_1_4630(lbl_801A6410, *(u8 *)((u8 *)&lbl_1_bss_7ACE0__fzgx_offset_4) << 2, (u8 *)"face.c", 0x174);
    texsize = GXGetTexBufferSize(0x40, 0x40, 5, 0, 0);
    obj = (Obj_1_bss_7ACD8_Target *)fzgx_obj_lbl_1_bss_7ACD8;
    for (i = 0; i < 6; i++) {
        u32 c1;
        u32 c0;
        c0 = fn_1_D1848_array_read(0, lbl_1_rodata_60A0);
        c1 = fn_1_D1848_array_read(1, lbl_1_rodata_60A0);
        obj->unk_2C = c0;
        obj->unk_30 = c1;
        obj->unk_34 = fn_1_D1848_array_read(2, lbl_1_rodata_60A0);
        obj->unk_1C = 0;
        obj->unk_4 = 0xFF;
        obj->unk_0 &= 0x7FFFFFFFu;
        obj->unk_0 = __rlwinm(obj->unk_0, 0, 2, 0);
        obj->unk_60 = fn_1_45D0(lbl_801A6410, texsize, (u8 *)"face.c", 0x18A);
        memset((void *)obj->unk_60, 0, 4);
        obj = (Obj_1_bss_7ACD8_Target *)((u8 *)obj + 0x64);
    }
    fn_1_D2F84();
}
#pragma opt_propagation reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_D1848 */

/* fzgx:begin fn_1_D1C94 noprologue */
#include "types.h"

extern u32 lbl_1_data_3D924;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 pad_E[0x2];
    s32 unk_10;
} State_7ACD8;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x18];
    u32 unk_38;
    u32 unk_3C;
    u8 pad_40[0x24];
} Ent;

extern State_7ACD8 lbl_1_bss_7ACD8;
extern u32 fn_1_864E8(s32);
extern s32 fn_1_D2E44(u32);
extern s8 fn_1_86690(s8);
extern s16 fn_1_12C7B8(s16);
extern s32 fn_1_D123C(u32);
extern s32 fn_1_3F440(u32);
extern void fn_1_D2F50(void);
extern void fn_1_D2F84(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);

void fn_1_D1C94(void) {
    State_7ACD8 *p;
    Ent *obj;
    s32 count;
    u32 mask;
    s32 i;
    s32 n;

    p = (State_7ACD8 *)&lbl_1_bss_7ACD8;
    if ((s32)lbl_1_data_3D924 != -1) {
        fn_1_D2F50();
        if (p->unk_10 != 0) {
            u8 c = p->unk_C;
            p->unk_D = c;
            if (c > 4) {
                p->unk_D = 4;
            }
        } else {
            p->unk_D = 0;
            mask = 0x20000880;
            n = 0;
            while ((u32)n < p->unk_C) {
                if ((fn_1_864E8(n) & mask) == 0) {
                    p->unk_D++;
                }
                n++;
            }
            if (p->unk_D > 6) {
                p->unk_D = 6;
            }
        }

        obj = (Ent *)p->unk_0;
        i = 0;
        while ((u32)i < p->unk_D) {
            if (obj == 0) {
                fn_1_D2F84();
                return;
            }
            if (obj->unk_4 != 0xff) {
                u32 off = (obj->unk_4 & 0xFF) << 2;
                obj->unk_4 = obj->unk_4;
                if (*(u32 *)(p->unk_8 + off) != 0) {
                    fn_80071718(*(u32 *)(p->unk_8 + off));
                    *(u32 *)(p->unk_8 + off) = 0;
                }
                if (*(u32 *)(p->unk_4 + off) != 0) {
                    fn_800711A8(*(u32 *)(p->unk_4 + off));
                    *(u32 *)(p->unk_4 + off) = 0;
                }
            }
            i++;
            obj++;
        }

        count = 0;
        if (p->unk_10 != 0) {
            i = 0;
            obj = (Ent *)p->unk_0;
            while ((u32)i < p->unk_D) {
                u32 res = fn_1_D2E44(i);
                if (obj == 0) {
                    fn_1_D2F84();
                    return;
                }
                if ((u32)count <= (u32)(p->unk_D - 1)) {
                    u32 v = res & 0xFF;
                    obj->unk_10 = v;
                    obj->unk_14 = v;
                    obj->unk_18 = i;
                    obj->unk_4 = i;
                    obj->unk_8 = (s16)fn_1_12C7B8(fn_1_86690((s8)i));
                    obj->unk_3C = 0;
                    obj->unk_38 = 0;
                    obj->unk_1C = 20;
                    if (fn_1_D123C(obj->unk_4 & 0xFF) != 0) {
                        obj->unk_0 &= 0x7FFFFFFF;
                    } else {
                        obj->unk_0 |= 0x80000000;
                    }
                    count++;
                    obj++;
                }
                i++;
            }
        } else {
{
    s32 fzgx_loop_i_3321;
            obj = (Ent *)p->unk_0;
            fzgx_loop_i_3321 = 0;
            while ((u32)fzgx_loop_i_3321 < p->unk_C) {
                u32 res = fn_1_D2E44(fzgx_loop_i_3321);
                s32 lim;
                if (obj == 0) {
                    fn_1_D2F84();
                    return;
                }
                lim = p->unk_D - 1;
                if ((s32)(res & 0xFF) <= lim && (u32)count <= (u32)lim) {
                    u32 v = res & 0xFF;
                    obj->unk_10 = v;
                    obj->unk_14 = v;
                    obj->unk_18 = fn_1_3F440(res);
                    obj->unk_4 = fzgx_loop_i_3321;
                    obj->unk_8 = (s16)fn_1_12C7B8(fn_1_86690((s8)fzgx_loop_i_3321));
                    obj->unk_3C = 0;
                    obj->unk_38 = 0;
                    obj->unk_1C = 20;
                    if (fn_1_D123C(obj->unk_4 & 0xFF) != 0) {
                        obj->unk_0 &= 0x7FFFFFFF;
                    } else {
                        obj->unk_0 |= 0x80000000;
                    }
                    count++;
                    obj++;
                }
                fzgx_loop_i_3321++;
            }
    i = fzgx_loop_i_3321;
}
        }
        fn_1_D2F84();
    }
}
/* fzgx:end fn_1_D1C94 */

/* fzgx:begin fn_1_D1F88 */
void fn_1_D1F88(void) {
    Obj_1_bss_7ACD8_Target* state;
    s32 i;
    Obj_1_bss_7ACD8_Target* obj;
    u32 index;

    state = (Obj_1_bss_7ACD8_Target*)&lbl_1_bss_7ACD8;
    if ((s32)lbl_1_data_3D924 != -1) {
        fn_1_D2F50();
        i = 0;
        obj = (Obj_1_bss_7ACD8_Target*)state->unk_0;
        for (; i < 6; i++, obj = (Obj_1_bss_7ACD8_Target*)((u8*)obj + 0x64)) {
            if (obj->unk_60 != 0) {
                fn_1_46B4(lbl_801A6410, obj->unk_60, lbl_1_data_3DA2C, 0x271);
                obj->unk_60 = 0;
            }
            if (i < *(u8*)((u8*)state + 0xD)) {
                index = (obj->unk_4 & 0xFF) << 2;
                if (*(u32*)(state->unk_8 + index) != 0) {
                    fn_80071718(*(u32*)(state->unk_8 + index));
                    *(u32*)(state->unk_8 + index) = 0;
                }
                if (*(u32*)(state->unk_4 + index) != 0) {
                    fn_800711A8(*(u32*)(state->unk_4 + index));
                    *(u32*)(state->unk_4 + index) = 0;
                }
            }
        }
        if (state->unk_4 != 0) {
            fn_1_46B4(lbl_801A6410, state->unk_4, lbl_1_data_3DA2C, 0x277);
            state->unk_4 = 0;
        }
        if (state->unk_8 != 0) {
            fn_1_46B4(lbl_801A6410, state->unk_8, lbl_1_data_3DA2C, 0x278);
            state->unk_8 = 0;
        }
        if (state->unk_0 != 0) {
            fn_1_46B4(lbl_801A6410, state->unk_0, lbl_1_data_3DA2C, 0x27B);
            state->unk_0 = 0;
        }
        fn_1_D2F84();
    }
}
/* fzgx:end fn_1_D1F88 */

/* fzgx:begin fn_1_D2110 */
extern u32 lbl_801A6410;
extern u32 lbl_1_bss_7ACEC;
extern u32 fn_1_45D0(u32, u32, void*, u32);
extern u32 fn_80008F88(void*, u32);
extern void fn_80009064(u32);
extern void fn_1_46B4(u32, u32, u8*, int);
extern void fn_1_D2F50(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_D2F84(void);
extern s16 fn_1_3F0C8(void *obj);
extern u32 fn_1_864E8(u32 value);
extern void OSPanic(char*, ...);
extern u32 fn_1_86810(u32);
extern void qsort(void*, u32, u32, void*);
extern s32 fn_1_D2E18(u8*, u8*);
extern u32 lbl_1_bss_7AD00;
extern u32 lbl_1_bss_7AD04;
extern u32 lbl_1_bss_7AD08[7];
extern u32 lbl_1_bss_7AD24[9];
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CFC;
extern void* fn_1_48E8(u32, u32);
extern void OSLink(void*, void*);
extern void OSReport(char*, ...);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FaceVec;

typedef struct {
    u8 pad_0[0x20];
    FaceVec prev;  /* 0x20 */
    FaceVec pos;   /* 0x2C */
    u32 timer;     /* 0x38 */
    u32 state;     /* 0x3C */
} FaceObj;

extern u32 fn_1_584AC(void);

#pragma section code_type ".fzgxpool"
/* layout primer: fn_1_D1848's initializer precedes this function's in the TU pool */
static void fzgx_pool_layout(FaceVec *out) {
    FaceVec v = { 0.0f, 0.0f, 1.8f };
    *out = v;
}
#pragma section code_type ".text"

#pragma fp_contract off
#pragma opt_common_subs off
void fn_1_D2110(FaceObj *o) {
    f32 fzgx_live;
    FaceVec d = { 0.0f, 0.0f, 0.0f };
    f32 tz;
    f32 tx;
    f32 ty;
    f32 s;
    u32 lab_v;

    lab_v = o->state;
    if (lab_v != 0) {
        if (lab_v > 35 && lab_v < 40) {
            d.y = 0.08f;
        }
        if (lab_v > 25 && lab_v < 30) {
            d.y = 0.08f;
        }
        if (lab_v < 20) {
            d.y = 0.08f;
        }
    }
    o->pos.x += d.x;
    o->pos.y -= d.y;
    o->pos.z -= d.z;
    if (o->state != 0) {
        o->pos.x = o->pos.x + 0.1 * -o->pos.x;
        o->pos.y = o->pos.y + 0.1 * -o->pos.y;
        fzgx_live = o->pos.z;
        o->pos.z = fzgx_live + 0.1 * (1.8f - fzgx_live);
    } else if (o->timer != 0) {
        s = (f32)o->timer / 10.0f;
        tx = 0.5 * (s * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5));
        ty = s * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5);
        tz = 1.8f + s * ((f32)(u16)fn_1_584AC() / 32767.0f - 0.5);
        o->pos.x = o->pos.x + 0.2 * (tx - o->pos.x);
        o->pos.y = o->pos.y + 0.2 * (ty - o->pos.y);
        fzgx_live = o->pos.z;
        o->pos.z = fzgx_live + 0.2 * (tz - fzgx_live);
    } else {
        o->pos.x = o->pos.x + 0.1 * -o->pos.x;
        o->pos.y = o->pos.y + 0.1 * -o->pos.y;
        fzgx_live = o->pos.z;
        o->pos.z = fzgx_live + 0.1 * (1.8f - fzgx_live);
    }
    o->prev = o->pos;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_D2110 */

/* fzgx:begin fn_1_D2404 noprologue */
#include "types.h"

typedef struct FaceEntry {
    u32 flags;
    u32 id;
    s32 unk8;
    u8 padC[4];
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u8 pad20[0x18];
    u32 unk38;
    u32 unk3C;
    u8 pad40[0x24];
} FaceEntry;

typedef struct FaceManager {
    FaceEntry *entries;
    void **list4;
    void **list8;
    u8 countC;
    u8 countD;
    u8 padE[2];
    s32 unk10;
} FaceManager;

extern FaceManager lbl_1_bss_7ACD8;
extern s32 lbl_1_data_3D924;

extern u32 fn_1_58C4(void);
extern void fn_1_D2F50(void);
extern void fn_1_D2F84(void);
extern u8 fn_1_D2E44(u8);
extern void fn_1_D2110(FaceEntry *);
extern u32 fn_1_864E8(u32);
extern s16 fn_1_3F0C8(void);
extern u32 fn_1_3F440(u8);
extern s8 fn_1_86690(s8);
extern s16 fn_1_12C7B8(s16);
extern s32 fn_1_D123C(u8);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);

void fn_1_D2404(void) {
    FaceManager *mgr = &lbl_1_bss_7ACD8;
    s8 player;
    s32 id;
    u8 j;
    FaceEntry *e_2;
    FaceEntry *g;
    u32 idx;
    u8 m;
    FaceEntry *f;
    FaceEntry *e;
    u8 i;
    u8 n;
    u8 slot;
    s32 found;
    s32 pending;
    u8 q;
    u8 k;

    if (fn_1_58C4() <= 1 && lbl_1_data_3D924 != -1) {
        fn_1_D2F50();
        e = mgr->entries;
        for (i = 0; i < mgr->countD; i++, e++) {
            e->unk14 = fn_1_D2E44(e->id);
        }
        e_2 = mgr->entries;
        for (j = 0; j < mgr->countD; j++, e_2++) {
            fn_1_D2110(e_2);
            if (e_2->unk3C != 0) {
                e_2->unk3C--;
            }
            if (e_2->unk38 != 0) {
                e_2->unk38--;
            }
            if ((fn_1_864E8(e_2->id) & 0x2800000) && fn_1_3F0C8() == 41) {
                e_2->unk38 = 10;
            }
            if (e_2->unk10 != e_2->unk14) {
                e_2->unk1C--;
            } else {
                e_2->unk1C = 20;
            }
            if (e_2->unk1C != 0) {
                continue;
            }
            f = mgr->entries;
            for (k = 0; k < mgr->countD; k++, f++) {
                if (mgr->unk10 == 0 && f->unk10 < 6 && f->unk14 >= 6) {
                    idx = (u8)f->id;
                    if (mgr->list8[idx] != NULL) {
                        fn_80071718(mgr->list8[idx]);
                        mgr->list8[idx] = NULL;
                    }
                    if (mgr->list4[idx] != NULL) {
                        fn_800711A8(mgr->list4[idx]);
                        mgr->list4[idx] = NULL;
                    }
                }
                if (f->unk10 != 0 && f->unk14 == 0 && fn_1_3F0C8() == 41) {
                    f->unk3C = 70;
                } else {
                    f->unk3C = 0;
                }
                f->unk10 = f->unk14;
                if (mgr->unk10 != 0) {
                    f->unk18 = f->id;
                } else {
                    f->unk18 = fn_1_3F440(f->unk14);
                }
            }
            if (mgr->unk10 != 0) {
                continue;
            }
            player = (s8)j;
            for (m = 0; m < mgr->countC; m++) {
                id = m;
                slot = fn_1_D2E44(id);
                if (slot >= 6) {
                    continue;
                }
                g = mgr->entries;
                found = 1;
                f = g;
                for (n = 0; n < mgr->countD; n++, f++) {
                    if (f->unk10 < 6 && found && m == f->id) {
                        found = 0;
                    }
                }
                if (!found) {
                    continue;
                }
                pending = 1;
                for (q = 0; q < mgr->countD; q++, g++) {
                    if (g->unk10 >= 6 && pending) {
                        g->unk10 = slot;
                        g->unk14 = slot;
                        g->id = id;
                        g->unk8 = fn_1_12C7B8(fn_1_86690(player));
                        if (mgr->unk10 != 0) {
                            g->unk18 = m;
                        } else {
                            g->unk18 = fn_1_3F440(g->unk14);
                        }
                        if (fn_1_D123C(m)) {
                            g->flags &= ~0x80000000;
                        } else {
                            g->flags |= 0x80000000;
                        }
                        if (g->unk14 == 0) {
                            g->unk3C = 70;
                        } else {
                            g->unk3C = 0;
                        }
                        pending = 0;
                    }
                }
            }
        }
        fn_1_D2F84();
    }
}
/* fzgx:end fn_1_D2404 */

/* fzgx:begin fn_1_D2D24 */
Obj_1_bss_7ACD8_Target *fn_1_D2D24(s32 index) {
    return &lbl_1_bss_7ACD8[index];
}
/* fzgx:end fn_1_D2D24 */

/* fzgx:begin fn_1_D2D38 */
u32 fn_1_D2D38(void) {
    return lbl_1_bss_7ACE8;
}
/* fzgx:end fn_1_D2D38 */

/* fzgx:begin fn_1_D2D48 */
u8 fn_1_D2D48(void) {
    return lbl_1_bss_7ACE5;
}
/* fzgx:end fn_1_D2D48 */

/* fzgx:begin fn_1_D2D58 */
Obj_1_bss_7ACD8_Target *fn_1_D2D58(void *obj) {
    s32 i;

    for (i = 0; i < lbl_1_bss_7ACE5; i++) {
        if ((u32)obj == lbl_1_bss_7ACD8[i].unk_10) {
            if (fn_1_3F0C8(obj) == 0x29 &&
                (fn_1_864E8(lbl_1_bss_7ACD8[i].unk_4) & 0x20000880) != 0) {
                return 0;
            }
            return &lbl_1_bss_7ACD8[i];
        }
    }
    return 0;
}
/* fzgx:end fn_1_D2D58 */

/* fzgx:begin fn_1_D2E18 */
// fn_1_D2E18: 3-way byte comparison (a > b returns 1, a < b returns -1, a == b returns 0)
s32 fn_1_D2E18(u8* a, u8* b) {
    u8 va = *a;
    u8 vb = *b;
    s32 d1;
    s32 d2;
    if (va > vb) {
        return 1;
    }
    d1 = va - vb;
    d2 = vb - va;
    return (d1 | d2) >> 31;
}
/* fzgx:end fn_1_D2E18 */

/* fzgx:begin fn_1_D2E44 */
s32 fn_1_D2E44(u32 index) {
    u8 values[4];
    u32 j;
    u32 i;

    if ((s32)lbl_1_bss_7ACE8 != 0) {
        if (index >= 4) {
            OSPanic((char*)lbl_1_data_3DA2C, 0x4f3, (char*)lbl_1_data_3DB2C);
        }
        for (i = 0; (u8)i < lbl_1_bss_7ACE5; i++) {
            values[(u8)i] = fn_1_86810((u8)i);
        }
        qsort(values, lbl_1_bss_7ACE5, 1, fn_1_D2E18);
        for (j = 0; (u8)j < lbl_1_bss_7ACE5; j++) {
            if (values[(u8)j] == (u8)fn_1_86810(index)) {
                return j;
            }
        }
        return values[index];
    }
    return fn_1_86810(index);
}
/* fzgx:end fn_1_D2E44 */

/* fzgx:begin fn_1_D2FB0 */
u32 fn_1_D2FB0(void) {
    return lbl_1_data_3D924;
}
/* fzgx:end fn_1_D2FB0 */

/* fzgx:begin fn_1_D2FC0 noprologue */
#include "types.h"

extern u32 fn_1_D3020(void *, void *);
extern u8 lbl_1_bss_7ACF8[8];
extern void fn_80083DB0(void *, void *);
extern void strcat(void *, void *);

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("fze.");
    OSReport("window");
    OSReport(".rel");
}
#pragma section code_type ".text"

void fn_1_D2FC0(void) {
    struct {
        u32 a[16];
    } loc_8;

    
    fn_80083DB0((void *)&loc_8, (void *)(u32)("fze."));
    strcat((void *)&loc_8, (void *)(u32)("window"));
    strcat((void *)&loc_8, (void *)(u32)(".rel"));
    fn_1_D3020((void *)&loc_8, (void *)&lbl_1_bss_7ACF8);
}
/* fzgx:end fn_1_D2FC0 */

/* fzgx:begin fn_1_D3020 */
#include "types.h"

typedef struct LocalData {
    u8 unk_0[0x34];
    u32 size;
} LocalData;

typedef struct Output {
    void* data;
    void* aux;
} Output;

typedef struct Allocated {
    u8 unk_0[0x20];
    u32 size;
    u8 unk_24[0x10];
    void (*init)(void);
} Allocated;

extern int DVDOpen(void*, LocalData*);
extern int fn_80006354(LocalData*, void*, u32, u32);
extern void DVDClose(LocalData*);

void fn_1_D3020(void* unused, Output* output) {
    LocalData local;
    Allocated* object;
    s32 size;

    if ((lbl_801A6CE0 & 0x8) == 0) {
        return;
    }
    output->data = 0;
    output->aux = 0;
    if (DVDOpen(unused, &local) == 0) {
        return;
    }
    size = (local.size + 0x1f) & ~0x1f;
    if (lbl_801A6CFC < 0x82000000) {
        object = fn_1_48E8(size, 0x20);
        output->data = object;
    } else {
        OSReport((*(char (*)[51])&lbl_1_data_3DB58));
        return;
    }
    if (fn_80006354(&local, output->data, size, 0) != 0) {
        object = output->data;
        size = 0x20;
        if (object->size != 0) {
            size = object->size;
        }
        output->aux = fn_1_48E8(size, 0x20);
        OSLink(output->data, output->aux);
        object = output->data;
        object->init();
    } else {
        OSReport((*(char (*)[51])&lbl_1_data_3DB8C));
        output->data = 0;
    }
    DVDClose(&local);
}
/* fzgx:end fn_1_D3020 */

/* fzgx:begin fn_1_D3144 */
// fn_1_D3144: Conditionally call function pointer from BSS
void fn_1_D3144(void) {
    u32 fn_ptr = lbl_1_bss_7AD00;
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D3144 */

/* fzgx:begin fn_1_D3178 */
void fn_1_D3178(void) {
    u32 fn_ptr = lbl_1_bss_7AD04;
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D3178 */

/* fzgx:begin fn_1_D31AC */
void fn_1_D31AC(void) {
    u32 fn_ptr = lbl_1_bss_7AD08[0];
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D31AC */

/* fzgx:begin fn_1_D31E0 */
void fn_1_D31E0(void) {
    u32 fn_ptr = lbl_1_bss_7AD24[0];
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D31E0 */
