#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/bg_cas.h"
#include "game/vec3.h"






typedef struct SplineEntry {
    u8 pad0[0x104];
    u32 f104;
    u8 pad1[0xC];
    u32 f114;
    u8 pad2[0xC];
    u32 f124;
    u8 pad3[0xC];
    u32 f134;
    u8 pad4[0xC];
    u32 f144;
    u8 pad5[0xC];
    u32 f154;
    u8 pad6[0xC];
    f32 f164;
} SplineEntry;

typedef struct SplineMain {
    u8 pad0[4];
    u8 unk_4;
    u8 pad5[0x163];
    f32 unk_168;
} SplineMain;
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void GXInitTexObjLOD(void *texObj, int minFilter, int magFilter, f32 minLod, f32 maxLod, f32 lodBias, int biasClamp, int edgeLod, int maxAniso);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DB74(void *);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073778(void *obj, s32 index);
extern void fn_800738E0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800739E0(s32 index, s32 arg1, s32 arg2);
extern void fn_80073A58(int index, void *arg, s8 value);
extern void fn_80073C6C(s32 index);
extern void fn_80073D60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_1_FB9DC(u8);
extern void fn_1_FBA88(u8);
extern void fn_1_FBC5C(u8);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void fn_1_563B8(u32 value);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *arg0, u32 arg1, f32 arg2);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void *arg0, f32 arg1);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *arg0, s32 arg1);
extern void fn_1_FF420(void *em_raw);
extern void fn_80074788(u32 arg0);
extern void fn_80072864(u32 arg0);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80073678(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_800720B0(s32 arg0);
extern void fn_1_9A508(void);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(void *obj_raw);
extern void fn_1_FF038(void *owner_raw);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *arg0, u32 arg1, f32 arg2);
extern void fn_1_FFC60(void *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;
void fn_1_FA89C(SplineMain *arg0);

/* fzgx:begin fn_1_FB870 noprologue */
#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/globals.h"

typedef struct {
    s32 active;      // 0x0
    Vec3 pos;        // 0x4
    Vec3 vel;        // 0x10
    Vec3 scale;      // 0x1C
    f32 mtx[3][4];   // 0x28
    s32 tex;         // 0x58
    s8 off[4];       // 0x5C
} CasLayer;

typedef struct {
    s32 active;        // 0x0
    u8 id;             // 0x4
    u8 pad_5[3];
    s32 flags[3];      // 0x8
    CasLayer lower[3]; // 0x14
    CasLayer upper[3]; // 0x134
    u8 pal[4];         // 0x254
    f32 sx[3];         // 0x258
    f32 sy[3];         // 0x264
} CasEntry;

extern void fn_80008BEC(void *dst, int value, u32 size);
extern void GXInitTexObjLOD(void *texObj, int minFilter, int magFilter, f32 minLod,
                            f32 maxLod, f32 lodBias, int biasClamp, int edgeLod, int maxAniso);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DB74(void *);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_800739E0(s32, s32, s32);
extern void fn_80073A58(s32, void *, s32);
extern void fn_80073C6C(s32);
extern void fn_80073D60(s32, s32, s32, s32, s32);
extern void fn_800745A4(s32, s32, s32, s32, u32, u32);

void fn_1_FB9DC(u8 index);
void fn_1_FBA88(u8 index);
void fn_1_FBC5C(u8 index);

u8 lbl_1_bss_84450;
CasEntry lbl_1_bss_84454[5];
u8 lbl_1_bss_85084;
u32 lbl_1_bss_85088[14];

u8 *fn_1_FB870(void) {
    return &lbl_1_bss_84450;
}
/* fzgx:end fn_1_FB870 */

/* fzgx:begin fn_1_FB87C noprologue */
void fn_1_FB87C(u32 *values, u8 count) {
    u8 ids[5] = {0x49, 0x4A, 0x4B, 0x4C, 0x64};
    u32 *src;
    u32 *dst;
    int i;

    fn_80008BEC(lbl_1_bss_84454, 0, 0xc30);
    lbl_1_bss_84454[0].id = ids[0];
    lbl_1_bss_84454[1].id = ids[1];
    lbl_1_bss_84454[2].id = ids[2];
    lbl_1_bss_84454[3].id = ids[3];
    lbl_1_bss_84454[4].id = ids[4];
    lbl_1_bss_85084 = count;

    dst = lbl_1_bss_85088;
    src = values;
    for (i = 0; i < lbl_1_bss_85084; i++) {
        *dst = *src;
        GXInitTexObjLOD((void *)*dst, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);
        src++;
        dst++;
    }
}
/* fzgx:end fn_1_FB87C */

/* fzgx:begin fn_1_FB96C noprologue */
// Initializes the selected background-cas state before running its setup stages.
void fn_1_FB96C(u8 index) {
    lbl_1_bss_84454[index].active = 1;
    fn_1_FB9DC(index);
    fn_1_FBA88(index);
    fn_1_FBC5C(index);
}
/* fzgx:end fn_1_FB96C */

/* fzgx:begin fn_1_FB9C0 noprologue */
// Clear the selected CAS state value.
void fn_1_FB9C0(u8 index) {
    lbl_1_bss_84454[index].active = 0;
}
/* fzgx:end fn_1_FB9C0 */

/* fzgx:begin fn_1_FB9DC noprologue */
// Reset the per-slot flags and enable the flags associated with the selected slot.
void fn_1_FB9DC(u8 index) {
    CasEntry *entry = &lbl_1_bss_84454[index];

    entry->lower[0].active = 0;
    entry->upper[0].active = 0;
    entry->lower[1].active = 0;
    entry->upper[1].active = 0;
    entry->lower[2].active = 0;
    entry->upper[2].active = 0;

    switch (index) {
    case 0:
        entry->lower[0].active = 1;
        entry->upper[0].active = 1;
        break;
    case 1:
        entry->upper[0].active = 1;
        entry->upper[1].active = 1;
        break;
    case 2:
        entry->upper[0].active = 1;
        entry->upper[2].active = 1;
        break;
    case 3:
        entry->upper[0].active = 1;
        entry->upper[2].active = 1;
        break;
    case 4:
        entry->upper[0].active = 1;
        entry->upper[1].active = 1;
        break;
    default:
        break;
    }
}
/* fzgx:end fn_1_FB9DC */

/* fzgx:begin fn_1_FBA88 noprologue */
void fn_1_FBA88(u8 index) {
    s32 *p;
    CasEntry *entry = &lbl_1_bss_84454[index];
    s32 tex[6] = {0x2D, 0x30, 0x2A, 0x27, 0x39, 0x36};
    int i;
    s32 *q;
    s8 n = 0;
    s8 c0 = 0, c1 = 0, c2 = 0, c3 = 0;
    int j;

    p = tex;

    for (i = 0; i < 3; i++) {
        CasLayer *layer = &entry->upper[i];
        if (layer->active != 0) {
            layer->tex = *p++;
            n++;
            layer->off[0] = c0++;
            layer->off[1] = c1++;
            layer->off[2] = c2++;
            layer->off[3] = c3++;
        }
    }
    q = tex + n;
    for (j = 0; j < 3; j++) {
        CasLayer *layer = &entry->lower[j];
        if (layer->active != 0) {
            layer->tex = *q++;
            layer->off[0] = c0++;
            layer->off[1] = -1 - j;
        }
    }
}
/* fzgx:end fn_1_FBA88 */

/* fzgx:begin fn_1_FBC5C noprologue */
void fn_1_FBC5C(u8 idx) {
    CasEntry *p;
    int i;

    p = &lbl_1_bss_84454[idx];

    for (i = 0; i < 3; i++) {
        p->lower[i].pos.x = 0.0f;
        p->lower[i].pos.y = 0.0f;
        p->lower[i].pos.z = 0.0f;
        p->lower[i].scale.x = 1.0f;
        p->lower[i].scale.y = 1.0f;
        p->lower[i].scale.z = 1.0f;
        p->upper[i].pos.x = (i == 1) ? 0.5f : 0.0f;
        p->upper[i].pos.y = 0.0f;
        p->upper[i].pos.z = 0.0f;
        p->upper[i].vel.x = 0.0f;
        p->upper[i].vel.y = 0.0f;
        p->upper[i].vel.z = 0.0f;
        p->sx[i] = 0.1f;
        p->sy[i] = 0.2f;
        p->pal[i] = 0;
    }

    for (i = 0; i < 3; i++) {
        switch (idx) {
        case 0:
            p->lower[i].vel.x = (0.2f / 60.0f);
            p->lower[i].vel.y = (0.3f / 60.0f);
            p->upper[i].scale.x = 0.25f;
            p->upper[i].scale.y = 0.25f;
            break;
        case 1:
            p->lower[i].vel.x = (0.1f / 60.0f);
            p->lower[i].vel.y = (0.15f / 60.0f);
            p->upper[i].scale.x = 0.3f;
            p->upper[i].scale.y = 0.25f;
            break;
        case 2:
            p->upper[i].scale.x = 1.0f;
            p->upper[i].scale.y = 1.0f;
            break;
        case 3:
            p->upper[i].scale.x = 1.0f;
            p->upper[i].scale.y = 1.0f;
            break;
        case 4:
            p->upper[i].scale.x = 1.0f;
            p->upper[i].scale.y = 0.25f;
            p->sx[i] = 0.05f;
            p->sy[i] = 0.03f;
            break;
        }
        p->upper[i].vel.x = p->lower[i].vel.x / 3.0f;
        p->upper[i].vel.y = p->lower[i].vel.y / 3.0f;
    }

    switch (idx) {
    case 0:
        break;
    case 1:
        p->sx[0] = 0.3f;
        p->sy[0] = 0.3f;
        p->upper[0].vel.x = 0.005f;
        p->upper[0].vel.y = 0.005f;
        break;
    case 2:
        p->upper[0].vel.x = 0.001f;
        p->upper[0].vel.y = 0.001f;
        p->sx[0] = 0.0f;
        p->sy[0] = 0.3f;
        p->sy[2] = 0.07f;
        break;
    case 3:
        p->upper[0].vel.x = 0.015f;
        p->upper[0].vel.y = 0.0f;
        p->sx[0] = 0.1f;
        p->sy[0] = 0.2f;
        p->upper[2].vel.x = 0.01f;
        p->upper[2].vel.y = 0.0f;
        p->upper[2].scale.x = 0.25f;
        p->upper[2].scale.y = 0.25f;
        p->sx[2] = 0.05f;
        p->sy[2] = 0.05f;
        break;
    case 4:
        break;
    }
}
/* fzgx:end fn_1_FBC5C */

/* fzgx:begin fn_1_FBEA8 noprologue */
void fn_1_FBEA8(void) {
    CasEntry *entries;
    CasEntry *entry;
    u8 i;
    s32 j;

    entries = lbl_1_bss_84454;
    for (i = 0; i < 5; i++) {
        entry = &entries[i];
        if (entry->active != 0) {
            for (j = 0; j < 3; j++) {
                if (entry->lower[j].active != 0) {
                    entry->lower[j].pos.x += entry->lower[j].vel.x;
                    entry->lower[j].pos.y += entry->lower[j].vel.y;
                    entry->lower[j].pos.z += entry->lower[j].vel.z;
                    lbl_8006D758();
                    lbl_8006E13C(&entry->lower[j].scale);
                    lbl_8006E0A4(&entry->lower[j].pos);
                    lbl_8006DB74(entry->lower[j].mtx);
                }
                if (entry->upper[j].active != 0) {
                    entry->upper[j].pos.x += entry->upper[j].vel.x;
                    entry->upper[j].pos.y += entry->upper[j].vel.y;
                    entry->upper[j].pos.z += entry->upper[j].vel.z;
                    lbl_8006D758();
                    lbl_8006E13C(&entry->upper[j].scale);
                    lbl_8006E0A4(&entry->upper[j].pos);
                    lbl_8006DB74(entry->upper[j].mtx);
                }
            }
        }
    }
}
/* fzgx:end fn_1_FBEA8 */

/* fzgx:begin fn_1_FBFE4 noprologue */
#define MAX(a, b) ((a) > (b) ? (a) : (b))


typedef struct {
    /* WARNING: compiler-diff device, not original code */
    volatile s32 count;  // 0x0: snapshot count must be read before configuring layers
    s32 x;      // 0x4
    s32 tex;    // 0x8
    s32 y;      // 0xc
    s32 z;      // 0x10
    s32 unk_14;
    s32 unk_18;
    s32 w;      // 0x1c
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} CasAlloc;

typedef struct {
    u8 pad_0[0x15];
    u8 id;
} CasOwner;

typedef struct {
    u32 unk_0;
    CasOwner *owner; // 0x4
    u32 unk_8;
    CasAlloc alloc;  // 0xc
} CasState;


void fn_1_FBFE4(CasState *state) {
    CasAlloc base;
    CasAlloc cur;
    f32 mtx[6];
    u8 i;
    CasOwner *owner;
    s32 j;
    /* WARNING: compiler-diff device, not original code */
    struct { s32 value; } count;
    CasEntry *entry;
    s32 k;
    CasLayer *layer;
    s32 x, tex, y, z, w;
    s32 x2, tex2, y2;

    cur = state->alloc;
    base = state->alloc;
    owner = state->owner;
    for (i = 0; i < 5; i++) {
        entry = &lbl_1_bss_84454[i];
        if (entry->active == 0) {
            continue;
        }
        if (owner->id != entry->id) {
            continue;
        }
        count.value = base.count;
        for (j = 0; j < 3; j++) {
            k = count.value - j - 1;
            if (k < 0) {
                continue;
            }
            if (entry->flags[j] != 0) {
                fn_80073C6C(k);
                fn_80072EDC(k, 4);
                fn_800734A8(k, 0xff, 0xff, 0xff);
            }
            layer = &entry->upper[j];
            if (layer->active != 0) {
                x = base.x + layer->off[0];
                y = base.y + layer->off[1];
                z = base.z + layer->off[2];
                w = base.w + layer->off[3];
                tex = layer->tex;
                cur.x = MAX(cur.x, x + 1);
                cur.tex = MAX(cur.tex, tex + 3);
                cur.y = MAX(cur.y, y + 1);
                cur.z = MAX(cur.z, z + 1);
                cur.w = MAX(cur.w, w + 1);
                mtx[0] = entry->sx[j];
                mtx[1] = 0.0f;
                mtx[2] = 0.0f;
                mtx[3] = 0.0f;
                mtx[4] = entry->sy[j];
                mtx[5] = 0.0f;
                GXLoadTexMtxImm(layer->mtx, tex, 1);
                fn_800745A4(x, 1, 4, tex, 0, 0x7d);
                fn_80073778((void *)lbl_1_bss_85088[entry->pal[j]], y);
                fn_800738E0(z, x, y);
                fn_80073D60(k, z, 0, 0, w);
                fn_800739E0(z, 0, 0);
                fn_80073A58(w, mtx, 0);
            } else {
                fn_80073C6C(k);
            }
            layer = &entry->lower[j];
            if (layer->active != 0) {
                x2 = base.x + layer->off[0];
                y2 = base.y + layer->off[1];
                tex2 = layer->tex;
                cur.x = MAX(cur.x, x2 + 1);
                cur.tex = MAX(cur.tex, tex2 + 3);
                cur.y = MAX(cur.y, y2 + 1);
                fn_80073778((void *)lbl_1_bss_85088[entry->pal[j]], y2);
                GXLoadTexMtxImm(layer->mtx, tex2, 1);
                fn_800745A4(x2, 1, 4, tex2, 0, 0x7d);
                fn_800734A8(k, x2, y2, 4);
            }
        }
        state->alloc = cur;
        break;
    }
}
/* fzgx:end fn_1_FBFE4 */

/* fzgx:begin fn_1_FC40C */

// fn_1_FC40C: empty in retail (single blr).
void fn_1_FC40C(void) {
}
/* fzgx:end fn_1_FC40C */

/* fzgx:begin fn_1_FC410 */

// fn_1_FC410: empty in retail (single blr).
void fn_1_FC410(void) {
}
/* fzgx:end fn_1_FC410 */
