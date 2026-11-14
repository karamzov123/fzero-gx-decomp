#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

/* fzgx:begin fn_1_FB798 */
int fn_1_FB798(int mode, u32 *value) {
    Obj_1_data_2A7E0_At3C *entry = lbl_1_data_2A7E0.unk_3C;

    switch (mode) {
    case 0: {
        u8 *cursor = (u8 *)lbl_1_bss_3BE0->unk_54;
        entry->unk_0 = 0;
        while (cursor != (u8 *)value) {
            u32 count = entry->unk_0;
            cursor += 0x40;
            entry->unk_0 = count + 1;
        }
        *value |= 0x80000000;
        break;
    }

    case 1: {
        u8 *p = (u8 *)entry + 4;
        ((u32 *)(p + 4))[*(u8 *)p] = (u32)value;
        *(u8 *)p = *(u8 *)p + 1;
        *value |= 0x80000000;
        if (*(u8 *)p >= 0x10) {
            OSPanic((const char *)lbl_1_data_3EF90, 0x2f2, (const char *)lbl_1_data_3EF9C);
        }
        break;
    }
    }

    return 1;
}
/* fzgx:end fn_1_FB798 */

/* fzgx:begin fn_1_FB870 */
u8 *fn_1_FB870(void) {
    return &lbl_1_bss_84450;
}
/* fzgx:end fn_1_FB870 */

/* fzgx:begin fn_1_FB87C */
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern void fn_80008BEC(void *dst, int value, int size);
extern void GXInitTexObjLOD(void *texObj, int minFilter, int magFilter, f32 minLod,
                            f32 maxLod, f32 lodBias, int biasClamp, int edgeLod, int maxAniso);

typedef struct {
    u8 unk_0[4];
    u8 unk_4;
    u8 unk_5[0x270 - 5];
} Cas_1_Record;

typedef struct {
    u8 unk_0[4];
    Cas_1_Record unk_4[5];
    u8 unk_C34;
    u32 unk_C38[1];
} Cas_1_State;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_84450;
u8 fzgx_pool_lbl_1_bss_84450_gap_84451;
u16 fzgx_pool_lbl_1_bss_84450_gap_84451_fill_84452;
Cas_1_Record fzgx_obj_lbl_1_bss_84454[5];
u8 lbl_1_bss_84454__fzgx_offset_C30;
u8 lbl_1_bss_84454__fzgx_offset_C31;
u16 lbl_1_bss_84454__fzgx_offset_C32;
u32 lbl_1_bss_85088[1];
u32 lbl_1_bss_85088__fzgx_offset_4[13];
u32 fzgx_obj_lbl_1_bss_850C0;
u16 lbl_1_bss_850C0__fzgx_offset_4;
u16 fzgx_obj_lbl_1_bss_850C6;
u32 lbl_1_bss_850C6__fzgx_offset_2[3];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_84450;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_84450_gap_84451;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_84450_gap_84451_fill_84452;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_84454;
    s = *(u8 *)&lbl_1_bss_84454__fzgx_offset_C30;
    s = *(u8 *)&lbl_1_bss_84454__fzgx_offset_C31;
    s = *(u8 *)&lbl_1_bss_84454__fzgx_offset_C32;
    s = *(u8 *)&lbl_1_bss_85088;
    s = *(u8 *)&lbl_1_bss_85088__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850C0;
    s = *(u8 *)&lbl_1_bss_850C0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850C6;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_2;
}
#pragma section code_type ".text"

void fn_1_FB87C(u32 *values, u8 count) {
    u8 buf[5];
    
    u32 *src;
    u32 *dst;
    Cas_1_Record *rec;
    int i;
    volatile const f32 *zero; /* reloaded each iteration: the callee may write */

    *(u32 *)buf = *(u32 *)lbl_1_rodata_7590;
    buf[4] = ((u8 *)lbl_1_rodata_7590)[4];

    fn_80008BEC(fzgx_obj_lbl_1_bss_84454, 0, 0xc30);

    fzgx_obj_lbl_1_bss_84454[0].unk_4 = buf[0];
    fzgx_obj_lbl_1_bss_84454[1].unk_4 = buf[1];
    fzgx_obj_lbl_1_bss_84454[2].unk_4 = buf[2];
    fzgx_obj_lbl_1_bss_84454[3].unk_4 = buf[3];
    fzgx_obj_lbl_1_bss_84454[4].unk_4 = buf[4];
    lbl_1_bss_84454__fzgx_offset_C30 = count;

    dst = lbl_1_bss_85088;
    src = values;
    zero = &lbl_1_rodata_7598;
    for (i = 0; i < lbl_1_bss_84454__fzgx_offset_C30; i++) {
        f32 z = *zero;

        *dst = *src;
        GXInitTexObjLOD((void *)*dst, 1, 1, z, z, z, 0, 0, 0);
        src++;
        dst++;
    }
}
/* fzgx:end fn_1_FB87C */

/* fzgx:begin fn_1_FB96C */
#include "rel/main_rel/bg_cas.h"

// Initializes the selected background-cas state before running its setup stages.
void fn_1_FB96C(int index) {
    u32 *states = &lbl_1_bss_84454.unk_0;

    states[(index & 0xff) * 0x9c] = 1;
    fn_1_FB9DC(index);
    fn_1_FBA88(index);
    fn_1_FBC5C(index);
}
/* fzgx:end fn_1_FB96C */

/* fzgx:begin fn_1_FB9C0 */
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

// Clear the selected CAS state value.
void fn_1_FB9C0(int index) {
    (&lbl_1_bss_84454.unk_0)[(index & 0xff) * 0x9c] = 0;
}
/* fzgx:end fn_1_FB9C0 */

/* fzgx:begin fn_1_FB9DC */
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

// Reset the per-slot flags and enable the flags associated with the selected slot.
void fn_1_FB9DC(int index) {
    u32 slot = index & 0xff;
    Obj_1_bss_84454 *state =
        (Obj_1_bss_84454 *)((u8 *)&lbl_1_bss_84454 + slot * 0x270);

    state->unk_14 = 0;
    state->unk_134 = 0;
    state->unk_74 = 0;
    state->unk_194 = 0;
    state->unk_D4 = 0;
    state->unk_1F4 = 0;

    switch (slot) {
    case 0:
        state->unk_14 = 1;
        state->unk_134 = 1;
        break;
    case 1:
        state->unk_134 = 1;
        state->unk_194 = 1;
        break;
    case 2:
        state->unk_134 = 1;
        state->unk_1F4 = 1;
        break;
    case 3:
        state->unk_134 = 1;
        state->unk_1F4 = 1;
        break;
    case 4:
        state->unk_134 = 1;
        state->unk_194 = 1;
        break;
    default:
        break;
    }
}
/* fzgx:end fn_1_FB9DC */

/* fzgx:begin fn_1_FBA88 */
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

typedef struct {
    s32 flag;
    u8 pad_4[0x54];
    u32 val;
    u8 b0, b1, b2, b3;
} Slot_FBA88;

typedef struct {
    u8 pad_0[0x14];
    Slot_FBA88 s[6];
    u8 pad[0x270 - 0x14 - 6 * 0x60];
} Obj_FBA88;

extern u32 lbl_1_rodata_759C[25];

void fn_1_FBA88(int index) {
    u32 tbl[6];
    u32 *p = tbl;
    Obj_FBA88 *o = (Obj_FBA88 *)&lbl_1_bss_84454 + (index & 0xff);
    int i;
    u32 *q;
    s8 n = 0;
    s8 c0 = 0, c1 = 0, c2 = 0, c3 = 0;

    tbl[0] = lbl_1_rodata_759C[0];
    tbl[1] = lbl_1_rodata_759C[1];
    tbl[2] = lbl_1_rodata_759C[2];
    tbl[3] = lbl_1_rodata_759C[3];
    tbl[4] = lbl_1_rodata_759C[4];
    tbl[5] = lbl_1_rodata_759C[5];

    for (i = 0; i < 3; i++) {
        Slot_FBA88 *slot = (Slot_FBA88 *)((u8 *)o + i * 0x60 + 0x134);
        if (slot->flag != 0) {
            slot->val = *p++;
            n++;
            slot->b0 = c0++;
            slot->b1 = c1++;
            slot->b2 = c2++;
            slot->b3 = c3++;
        }
    }
    q = tbl + n;
    {
    int fzgx_loop_i_1025;
for (fzgx_loop_i_1025 = 0; fzgx_loop_i_1025 < 3; fzgx_loop_i_1025++) {
        Slot_FBA88 *slot = &o->s[fzgx_loop_i_1025];
        if (slot->flag != 0) {
            slot->val = *q++;
            slot->b0 = c0++;
            slot->b1 = -1 - fzgx_loop_i_1025;
        }
    }
    i = fzgx_loop_i_1025;
}
}
/* fzgx:end fn_1_FBA88 */

/* fzgx:begin fn_1_FBC5C noprologue */
#include "types.h"

typedef struct {
    f32 v[27];
} CasPool;
extern CasPool lbl_1_rodata_7590;

typedef struct {
    u8 pad_0[0x18];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    u8 pad_3C[0x24];
} CasSub;

typedef struct {
    CasSub a[3];
    CasSub b[3];
    u8 pad_240[0x14];
    u8 unk_254[3];
    u8 pad_257;
    f32 unk_258[3];
    f32 unk_264[3];
} CasEntry;

extern CasEntry lbl_1_bss_84454[];

void fn_1_FBC5C(u8 idx) {
    CasEntry * p;
    f32 *k = (f32 *)&lbl_1_rodata_7590;
    int i;
    p = &lbl_1_bss_84454[idx];

    for (i = 0; i < 3; i++) {
        p->a[i].unk_18 = k[2];
        p->a[i].unk_1C = k[2];
        p->a[i].unk_20 = k[2];
        p->a[i].unk_30 = k[9];
        p->a[i].unk_34 = k[9];
        p->a[i].unk_38 = k[9];
        p->b[i].unk_18 = (i == 1) ? k[10] : k[2];
        p->b[i].unk_1C = k[2];
        p->b[i].unk_20 = k[2];
        p->b[i].unk_24 = k[2];
        p->b[i].unk_28 = k[2];
        p->b[i].unk_2C = k[2];
        p->unk_258[i] = k[11];
        p->unk_264[i] = k[12];
        p->unk_254[i] = 0;
    }

    for (i = 0; i < 3; i++) {
        switch (idx) {
        case 0:
            p->a[i].unk_24 = k[13];
            p->a[i].unk_28 = k[14];
            p->b[i].unk_30 = k[15];
            p->b[i].unk_34 = k[15];
            break;
        case 1:
            p->a[i].unk_24 = k[16];
            p->a[i].unk_28 = k[17];
            p->b[i].unk_30 = k[18];
            p->b[i].unk_34 = k[15];
            break;
        case 2:
            p->b[i].unk_30 = k[9];
            p->b[i].unk_34 = k[9];
            break;
        case 3:
            p->b[i].unk_30 = k[9];
            p->b[i].unk_34 = k[9];
            break;
        case 4:
            p->b[i].unk_30 = k[9];
            p->b[i].unk_34 = k[15];
            p->unk_258[i] = k[19];
            p->unk_264[i] = k[20];
            break;
        }
        p->b[i].unk_24 = p->a[i].unk_24 / k[21];
        p->b[i].unk_28 = p->a[i].unk_28 / k[21];
    }

    switch (idx) {
    case 0:
        break;
    case 1:
        p->unk_258[0] = k[18];
        p->unk_264[0] = k[18];
        p->b[0].unk_24 = k[22];
        p->b[0].unk_28 = k[22];
        break;
    case 2:
        p->b[0].unk_24 = k[23];
        p->b[0].unk_28 = k[23];
        p->unk_258[0] = k[2];
        p->unk_264[0] = k[18];
        p->unk_264[2] = k[24];
        break;
    case 3:
        p->b[0].unk_24 = k[25];
        p->b[0].unk_28 = k[2];
        p->unk_258[0] = k[11];
        p->unk_264[0] = k[12];
        p->b[2].unk_24 = k[26];
        p->b[2].unk_28 = k[2];
        p->b[2].unk_30 = k[15];
        p->b[2].unk_34 = k[15];
        p->unk_258[2] = k[19];
        p->unk_264[2] = k[19];
        break;
    case 4:
        break;
    }
}
/* fzgx:end fn_1_FBC5C */

/* fzgx:begin fn_1_FBEA8 */
extern void lbl_8006DB74(void *);

void fn_1_FBEA8(void) {
    Obj_1_bss_84454 *base;
    Obj_1_bss_84454 *entry;
    u8 i;
    s32 j;

    base = &lbl_1_bss_84454;
    for (i = 0; i < 5; i++) {
        Obj_1_bss_84454 *slot =
            (Obj_1_bss_84454 *)((u8 *)base + i * 0x270);
        if ((s32)slot->unk_0 != 0) {
            for (j = 0, entry = slot; j < 3;
                 j++, entry = (Obj_1_bss_84454 *)((u8 *)entry + 0x60)) {
                if ((s32)entry->unk_14 != 0) {
                    entry->unk_18 += entry->unk_24;
                    entry->unk_1C += entry->unk_28;
                    entry->unk_20 += entry->unk_2C;
                    lbl_8006D758();
                    lbl_8006E13C(&entry->unk_30);
                    lbl_8006E0A4(&entry->unk_18);
                    lbl_8006DB74(entry->pad_3C);
                }
                if ((s32)entry->unk_134 != 0) {
                    entry->unk_138 += entry->unk_144;
                    entry->unk_13C += entry->unk_148;
                    entry->unk_140 += entry->unk_14C;
                    lbl_8006D758();
                    lbl_8006E13C(&entry->unk_150);
                    lbl_8006E0A4(&entry->unk_138);
                    lbl_8006DB74(&entry->pad_158[4]);
                }
            }
        }
    }
}
/* fzgx:end fn_1_FBEA8 */

/* fzgx:begin fn_1_FBFE4 noprologue */
#include "types.h"

extern const f32 lbl_1_rodata_7598; // 0.0f
extern u32 lbl_1_bss_85088[14];

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

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    s32 active;      // 0x0
    u8 pad_4[0x24];
    f32 mtx[3][4];   // 0x28
    s32 tex;         // 0x58
    s8 off[4];       // 0x5c
} CasLayer;

typedef struct {
    s32 active;      // 0x0
    u8 id;           // 0x4
    u8 pad_5[3];
    s32 flags[3];    // 0x8
    CasLayer lower[3]; // 0x14
    CasLayer upper[3]; // 0x134
    u8 pal[4];       // 0x254
    f32 sx[3];       // 0x258
    f32 sy[3];       // 0x264
} CasEntry;

typedef struct {
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

extern CasEntry lbl_1_bss_84454[5];

void fn_1_FBFE4(CasState *state) {
    CasAlloc base;
    CasAlloc cur;
    f32 mtx[6];
    u8 i;
    CasOwner *owner;
    s32 j;
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
                mtx[1] = lbl_1_rodata_7598;
                mtx[2] = lbl_1_rodata_7598;
                mtx[3] = lbl_1_rodata_7598;
                mtx[4] = entry->sy[j];
                mtx[5] = lbl_1_rodata_7598;
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

/* fzgx:begin fn_1_FC414 noprologue */
#include "types.h"
#include "rel/main_rel/bg_cas.h"

extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;

extern void *GXGetTexBufferSize(int, int, int, int, int);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_FC4E0(void *, void *);
extern void fn_1_FC51C(void);

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1c[4];
    u8 unk_20[0x100];
    u8 unk_120[0x20];
    u32 unk_140;
} Fn1FC414Data;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_850C0;
u16 lbl_1_bss_850C0__fzgx_offset_4;
u16 lbl_1_bss_850C6__fzgx_offset_0;
u32 lbl_1_bss_850C6__fzgx_offset_2[2];
u32 lbl_1_bss_850C6__fzgx_offset_A;
f32 fzgx_obj_lbl_1_bss_850D4;
f32 fzgx_obj_lbl_1_bss_850D8;
u32 lbl_1_bss_850D8__fzgx_offset_4;
u8 lbl_1_bss_850E0[0x100];
u8 lbl_1_bss_851E0[0x20];
u32 lbl_1_bss_851E0__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850C0;
    s = *(u8 *)&lbl_1_bss_850C0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850D4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850D8;
    s = *(u8 *)&lbl_1_bss_850D8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_850E0;
    s = *(u8 *)&lbl_1_bss_851E0;
    s = *(u8 *)&lbl_1_bss_851E0__fzgx_offset_20;
}
#pragma section code_type ".text"

void fn_1_FC414(void *arg0, void *arg1) {
    
    f32 v14 = lbl_1_rodata_7600;
    f32 v18 = lbl_1_rodata_7604;
    void *buffer;

    fzgx_obj_lbl_1_bss_850D4 = v14;
    fzgx_obj_lbl_1_bss_850D8 = v18;
    buffer = GXGetTexBufferSize(0x10, 0x10, 1, 0, 0);
    fn_80008BEC(lbl_1_bss_850E0, 0, (u32)buffer);
    fn_80008BEC(lbl_1_bss_851E0, 0, 0x20);
    lbl_1_bss_851E0__fzgx_offset_20 = (u32)GXGetTexBufferSize(0x80, 0x80, 1, 0, 0);
    fn_1_FC4E0(arg0, arg1);
    lbl_1_bss_850C6__fzgx_offset_A = 0;
    fn_1_FC51C();
}
/* fzgx:end fn_1_FC414 */

/* fzgx:begin fn_1_FC4E0 */
void fn_1_FC4E0(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80008BEC(arg0, 0, (arg1 & 0xff) * 0x10440);
    }
}
/* fzgx:end fn_1_FC4E0 */

/* fzgx:begin fn_1_FC51C */
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, f32, f32, f32, u32, u32, u32, u32, u32);

#pragma opt_common_subs off
void fn_1_FC51C(void) {
    fn_1_FC60C();

    lbl_1_bss_851E0[0] = 0xff;
    lbl_1_bss_851E0[1] = 0xff;
    lbl_1_bss_851E0[2] = 0;
    lbl_1_bss_851E0[3] = 0;
    lbl_1_bss_851E0[4] = 0;
    lbl_1_bss_851E0[5] = 0;
    lbl_1_bss_851E0[6] = 0;
    lbl_1_bss_851E0[7] = 0;

    fn_80008BA8(lbl_1_bss_851E0 + 8, lbl_1_bss_851E0, 8);
    fn_80008BA8(lbl_1_bss_851E0 + 0x10, lbl_1_bss_851E0, 8);
    fn_80008BA8(lbl_1_bss_851E0 + 0x18, lbl_1_bss_851E0, 8);
    DCFlushRange(lbl_1_bss_851E0, 0x20);

    GXInitTexObj((*(u8 (*)[32])&lbl_1_bss_85204), lbl_1_bss_851E0, 8, 4, 1, 0, 0, 0);
    GXInitTexObjLOD((*(u8 (*)[32])&lbl_1_bss_85204),
                *(const f32 *)&lbl_1_rodata_760C,
                *(const f32 *)&lbl_1_rodata_760C,
                *(const f32 *)&lbl_1_rodata_760C,
                1, 1, 0, 0, 0);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FC51C */

/* fzgx:begin fn_1_FC60C */
extern u8 lbl_1_bss_850E0[256];


extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void DCFlushRange(void *, u32);

void fn_1_FC60C(void) {
    u8 *tex;
    u8 *buf;
    u32 size;
    u32 i;

    size = GXGetTexBufferSize(0x10, 0x10, 1, 0, 0);
    tex = lbl_1_bss_85224;
    buf = lbl_1_bss_850E0;

    for (i = 0; i < 0x100; i++) {
        int idx = ((i & 0x80) >> 2) + ((i >> 4) & 7) + ((i & 0xC) << 4) + ((i & 3) << 3);
        if (i >= 0xA) {
            buf[idx] = (u8)i - 0xA;
        } else {
            buf[idx] = 0;
        }
    }

    GXInitTexObj(tex, buf, 0x10, 0x10, 1, 0, 1, 0);
    GXInitTexObjLOD(tex, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    DCFlushRange(buf, size);
}
/* fzgx:end fn_1_FC60C */

/* fzgx:begin fn_1_FC760 */
extern void fn_80038F10(f32 *);
extern void GXGetScissor(u32 *, u32 *, u32 *, u32 *);
extern void GXGetProjectionv(f32 *);
extern void fn_80015C1C(void *, f32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void PSMTXScale(void *,f32,f32,f32);
extern void lbl_8006DFFC(void *,void *,void *);
extern void C_MTXFrustum(void *,f32,f32,f32,f32,f32,f32);
extern void fn_800737E4(void *,s32);
extern void fn_80038EEC(f32,f32,f32,f32,f32,f32);
extern void fn_80074188(u32,u32,u32,u32);
extern void fn_80074300(u16,u16,u16,u16);
extern void fn_80074438(u32,u32,u32,u32);
extern void fn_800744F8(void *,u32);
extern void fn_8003526C(void *,u8);
extern void fn_80007C2C(void);
extern void lbl_8006DBAC(void *);
extern void DCInvalidateRange(void *,u32);
extern void GXInitTexObj(void *,void *,u16,u16,int,int,int,u8);
extern void GXInitTexObjLOD(void *,int,int,f32,f32,f32,u8,u8,int);
extern void GXInvalidateTexAll(void);
extern void fn_80072270(void *);

typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
    u32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
} Pool;
extern Pool lbl_1_rodata_7600;

typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x124];
    u32 unk_140;
} BssPool;

typedef struct { f32 m[12]; } Mat;
typedef struct { f32 m[16]; } Mat44;
typedef struct { f32 m[6]; } View;
typedef struct { f32 m[7]; } Saved;
typedef struct { u8 pad[0x40]; Mat unk_40; Mat unk_70; Mat unk_A0; u8 unk_D0[0x10]; u8 unk_E0[0x4000]; f32 unk_40E0; f32 unk_40E4; f32 unk_40E8; } Texture;
typedef struct {u8 pad[0x10428]; void (*unk_10428)(void *,Texture *); } Owner;

void fn_1_FC760(void *arg0, Texture *arg1) {
Pool *p_ro = (Pool *)&lbl_1_rodata_7600;
BssPool *p_bss = (BssPool *)&lbl_1_bss_850C0;
f32 v0,v1,v2;
f32 near,far,range;
f32 scale,ratio;
Mat44 loc_B8;
Mat loc_88;
Mat loc_58;
View loc_40;
Saved loc_24;
u32 loc_20,loc_1C,loc_18,loc_14;
u32 loc_10;
fn_80038F10(loc_40.m);
GXGetScissor(&loc_20,&loc_1C,&loc_18,&loc_14);
GXGetProjectionv(loc_24.m);
v0=p_ro->unk_14;
v1=arg1->unk_40E4;
v2=arg1->unk_40E8;
fn_80015C1C(&loc_88,-v2,v2,-v1,v1,p_bss->unk_14,v0,v0,v0,v0);
near=p_bss->unk_14;
far=p_bss->unk_18;
range=far-near;
PSMTXScale(&loc_58,p_ro->unk_C,p_ro->unk_C,p_ro->unk_C);
ratio=far/range;
loc_58.m[2]=ratio;
loc_58.m[3]=(far*near)/range;
scale=p_ro->unk_18;
loc_58.m[6]=ratio*scale;
loc_58.m[7]=loc_58.m[3]*scale;
loc_58.m[10]=p_ro->unk_1C;
lbl_8006DFFC(&loc_88,&arg1->unk_A0,&arg1->unk_40);
lbl_8006DFFC(&loc_58,&arg1->unk_A0,&arg1->unk_70);
C_MTXFrustum(&loc_B8,arg1->unk_40E8,-arg1->unk_40E8,-arg1->unk_40E4,arg1->unk_40E4,p_bss->unk_14,p_bss->unk_18);
fn_800737E4(&loc_B8,0);
fn_80038EEC(p_ro->unk_C,p_ro->unk_C,p_ro->unk_20,p_ro->unk_20,p_ro->unk_C,p_ro->unk_1C);
fn_80074188(0,0,128,128);
fn_80074300(0,0,128,128);
fn_80074438(128,128,17,0);
loc_10=p_ro->unk_10;
fn_800744F8(&loc_10,0xffffff);
fn_8003526C(arg1->unk_E0,1);
fn_80007C2C();
lbl_8006DBAC(&arg1->unk_A0);
((Owner *)arg0)->unk_10428(arg0,arg1);
DCInvalidateRange(arg1->unk_E0,p_bss->unk_140);
fn_8003526C(arg1->unk_E0,1);
GXInitTexObj(arg1,arg1->unk_E0,128,128,1,0,0,0);
GXInitTexObjLOD(arg1,1,1,p_ro->unk_C,p_ro->unk_C,p_ro->unk_C,0,0,0);
GXInvalidateTexAll();
fn_80038EEC(loc_40.m[0],loc_40.m[1],loc_40.m[2],loc_40.m[3],loc_40.m[4],loc_40.m[5]);
fn_80074188(loc_20,loc_1C,loc_18,loc_14);
fn_80072270(&loc_24);
}
/* fzgx:end fn_1_FC760 */

/* fzgx:begin fn_1_FCA10 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

/* begin game/main_rel/bg_cas_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

extern void fn_1_FF6B8(CasEmitter *em);

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H

/* end game/main_rel/bg_cas_types.h */

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};

struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;

typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;

typedef u8 Sig_GXInitTexObjLOD_GXBool;

typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FD844_Vec;

typedef struct {
    f32 x, y, z;
} CasVec;

typedef struct {
    CasVec v;
    u8 pad_C[0x34];
} CasMtx;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CasObj;

typedef struct {
    f32 x, y, z;
} CasSparkVec;

typedef struct {
    CasSparkVec pos;
    CasSparkVec base;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} CasSpark;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    u32 unk_10;
    CasSpark sparks[20];
} CasSparkSet;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_1_FC760(void *, void *);
extern void fn_8006F1F0(FD844_Vec *, FD844_Vec *, FD844_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern s32 fn_1_58C4(void);
extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void fn_800736C0(u32, void *);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8();
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(CasEmitter *em);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006E13C(void *);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_FFC60(CasSparkSet *state);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);

typedef f32 Mtx34[3][4];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_FCA10_CasVec;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} CasColor;



#define CAS_VIEW(field) (*(f32 *)(*(u32 *)(lbl_1_data_3EFA8 + 0x40F0) + (field)))

/* Literal pool of the retail TU (lbl_1_rodata_7600): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_layout(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    s = 2.0f;
    s = 8.0f;
}

/* MWCC emits a function's aggregate initializers before its scalar literals,
 * so each retail function with both gets its own primer. */
static void fzgx_pool_layout_1(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    {
        CasColor c = {0xFF, 0xFF, 0xFF, 0xFF};
        w = *(u32 *)&c;
    }
    s = 0.0f;
}

static void fzgx_pool_layout_2(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    {
        CasColor z = {0, 0, 0, 0};
        w = *(u32 *)&z;
    }
    s = 0.5f;
    s = 16.0f;
    s = 1.0f;
    s = 128.0f;
}
#pragma section code_type ".text"

void fn_1_FCA10(void) {
    CasColor color = {0xFF, 0xFF, 0xFF, 0xFF};
    u16 j;
    s32 i;
    u32 obj;

    fn_800736C0(0, &color);

    for (i = 0; (u16)i < 4; i++) {
        j = (u16)i;
        fn_800735C8(j, 12);
        fn_80073620(j, 28);
    }

    fn_80073778(lbl_1_bss_85224, 0);
    fn_80073778((void *)lbl_1_data_3EFA8, 1);
    fn_80073778((void *)(lbl_1_data_3EFA8 + 0x20), 2);
    fn_80073778(lbl_1_bss_85204, 3);

    GXLoadTexMtxImm((void *)(lbl_1_data_3EFA8 + 0x70), 30, 0);
    GXLoadTexMtxImm((void *)(lbl_1_data_3EFA8 + 0x40), 33, 0);

    lbl_8006DAEC();
    {
        fn_1_FCA10_CasVec trans = {0.0f, 0.0f, 0.0f};
        lbl_8006DBAC((void *)(lbl_1_data_3EFA8 + 0xA0));
        lbl_8006E14C(-1.0f);

        /* Translation column of the locked-cache current matrix. */
        *(f32 *)(0xE0000000 + 0x0C) = trans.x;
        *(f32 *)(0xE0000000 + 0x1C) = trans.y;
        *(f32 *)(0xE0000000 + 0x2C) = trans.z;
    }

    GXLoadTexMtxImm((*((Mtx34 * *)&lbl_801A6D00)), 0x24, 0);
    lbl_8006D758();

    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][0] = 0.0f;
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x10) < 0.5f || *(f32 *)(obj + 0x10) >= 1.0f) {
        *(f32 *)(obj + 0x10) = 0.5f;
    }
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x14) <= 0.0f || *(f32 *)(obj + 0x14) > 0.5f) {
        *(f32 *)(obj + 0x14) = 0.5f;
    }

    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][2] = CAS_VIEW(0x10);
    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][3] = CAS_VIEW(0x14);
    (*(*((Mtx34 * *)&lbl_801A6D00)))[1][1] = 0.0f;
    (*(*((Mtx34 * *)&lbl_801A6D00)))[2][2] = 0.0f;
    (*(*((Mtx34 * *)&lbl_801A6D00)))[2][3] = 1.0f;

    GXLoadTexMtxImm((*((Mtx34 * *)&lbl_801A6D00)), 0x46, 0);
    lbl_8006DB30();

    fn_80074660(4);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_800745A4(1, 0, 0, 33, 0, 125);
    fn_800745A4(2, 0, 0, 33, 0, 125);
    fn_80073678(4);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072C24(0, 0xF, 0xF, 0xF, 0xF);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073C6C(1);
    fn_80072AB0(1, 0, 0);
    fn_800734A8(1, 1, 1, 0xFF);
    fn_80072C24(1, 0xF, 0xF, 0xF, 0xF);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 4, 0, 6, 7);
    fn_80072E20(1, 14, 0, 0, 0, 0);
    fn_80073C6C(2);
    fn_80072AB0(2, 0, 0);
    fn_800734A8(2, 2, 2, 4);
    fn_80072C24(2, 0xF, 0xF, 0xF, 8);
    fn_80072D64(2, 0, 0, 0, 1, 0);
    fn_80072CC4(2, 7, 0, 4, 7);
    fn_80072E20(2, 0, 0, 1, 1, 0);
    fn_80073C6C(3);
    fn_80072AB0(3, 0, 0);
    fn_800745A4(3, 0, 1, 36, 1, 70);
    fn_800734A8(3, 3, 3, 4);
    fn_80072C24(3, 0xF, 0xF, 0xF, 0);
    fn_80072D64(3, 0, 0, 0, 1, 0);
    fn_80072CC4(3, 7, 4, 0, 7);
    fn_80072E20(3, 0, 0, 0, 1, 0);
}
/* fzgx:end fn_1_FCA10 */

/* fzgx:begin fn_1_FCF50 */
int fn_1_FCF50(void) {
    fn_1_FCA10();
    return 1;
}
/* fzgx:end fn_1_FCF50 */

/* fzgx:begin fn_1_FCF74 */
void fn_1_FCF74(void) {
    fn_80008BEC(&lbl_1_data_3EFB0, 0, 4);
}
/* fzgx:end fn_1_FCF74 */

/* fzgx:begin fn_1_FCFA4 noprologue */
#include "types.h"
#include "rel/main_rel/bg_cas.h"
extern Obj_1_bss_850C6 lbl_1_bss_850C0__fzgx_offset_6;

typedef struct {
    u8 r, g, b, a;
} Sig_fn_800371F8_GXColor;

typedef s32 (*Fn)(void *);
typedef void (*DrawFn)(void *, void *);

typedef struct {
    u8 pad_0[0x320];
    s16 unk_320;
} Ctx;

typedef struct {
    u8 pad_0[0x40F0];
    u32 unk_40F0;
    u8 pad_4100[0x4100 - 0x40F4];
} Part;

typedef struct {
    u8 pad_0[0x420];
    Fn unk_420;
    Fn unk_424;
    u8 pad_428[4];
    DrawFn unk_42C;
} Sub;

typedef struct {
    s32 unk_0;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_C;
    u8 pad_10[0x10];
    Part part[1];
    u8 pad_4120[0x10000 - 0x4120];
    Sub sub;
} Manager;

extern s16 camera_get_output(void);
extern s32 camera_get_state(void);
extern u32 camera_get_status(void);
extern u32 lbl_1_rodata_7608;
extern u8 fn_1_3F854(void);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_800371F8(s32, Sig_fn_800371F8_GXColor *);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(u32);
extern void fn_80072864(u32);

static inline Fn fn_1_FCFA4_read_pointer(Manager * owner) { return owner->sub.unk_420; }
void fn_1_FCFA4(void *arg0) {
    s32 tmp_call4;
    u32 nxt;
    Fn f0;
    Fn f1;
    u8 cur;
    u32 status;
    u8 state;
    u8 lim;
    Ctx *p;
    Manager *m = arg0;
    u8 ok;
    Sig_fn_800371F8_GXColor c;
    u32 v;
    s32 i;

    if (m == 0) {
        return;
    }
    f0 = fn_1_FCFA4_read_pointer(m);
    if (f0 != 0 && f0((void *)((u8 *)m + 0x10000)) != 0) {
        return;
    }
    if (lbl_1_bss_850C0__fzgx_offset_6.unk_0 != 0) {
        return;
    }
    if ((m->unk_C & 0x40000000) != 0) {
        p = (Ctx *)m->unk_0;
        status = camera_get_status();
        state = (u8)camera_get_state();
        lim = (u8)fn_1_3F854();
        if (p == 0) {
            ok = 0;
        } else {
            cur = ((u8 *)&lbl_1_data_3EFB0)[p->unk_320];
            if ((s16)status == 2 && state == 6) {
                tmp_call4 = camera_get_output();
                if (!((s16)tmp_call4 == p->unk_320)) {
                    ok = 0;
                } else {
                    goto allowed; /* fzgx-allow: S1 shared success block matches retail control flow */
                }
            } else if ((s16)status == 2) {
                goto allowed; /* fzgx-allow: S1 shared success block matches retail control flow */
            } else {
                /* fzgx-allow: S2 retail reloads the counter independently of the saved value */
                nxt = (u8)(((volatile u8 *)&lbl_1_data_3EFB0)[p->unk_320] + 1);
                ((u8 *)&lbl_1_data_3EFB0)[p->unk_320] = nxt;
                if ((u32)nxt >= (u32)lim) {
                    ((u8 *)&lbl_1_data_3EFB0)[p->unk_320] = 0;
                }
                if (!(cur == p->unk_320)) {
                    ok = 0;
                } else {
                    goto allowed; /* fzgx-allow: S1 shared success block matches retail control flow */
                }
            }
        }
    } else {
        if (!((m->unk_C & 0x80000000) == 0)) {
            ok = 0;
        } else {
allowed:
            ok = 1;
        }
    }
    if (ok == 0) {
        return;
    }
    f1 = m->sub.unk_424;
    if (f1 != 0 && f1(m) == 0) {
        return;
    }
    fn_800724C8();
    fn_8007245C(0x2200);
    v = lbl_1_rodata_7608;
    fn_80074788(1);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    c = *(Sig_fn_800371F8_GXColor *)&v;
    fn_800371F8(0, &c);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_80072864(2);
    for (i = 0; (s16)i < m->unk_4; i++) {
        if (m->part[i].unk_40F0 != 0) {
            lbl_1_data_3EFA8 = (u32)&m->part[i];
            m->sub.unk_42C(m, &m->part[i]);
        }
    }
}
/* fzgx:end fn_1_FCFA4 */

/* fzgx:begin fn_1_FD1D4 */
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);

typedef struct {
    void *value;
} fn_1_FD1D4_Fn1FD27CArg0;

typedef struct {
    u8 pad[0x40f0];
    void *value;
} fn_1_FD1D4_Fn1FD27CArg1;

void fn_1_FD1D4(fn_1_FD1D4_Fn1FD27CArg0 *arg0, fn_1_FD1D4_Fn1FD27CArg1 *arg1) {
    fn_1_FD1D4_Fn1FD27CArg1 *persistent;
    void *value;
    void *result;
    s16 mode;
    u8 local[0x30];

    persistent = arg1;
    value = arg0->value;
    lbl_8006DB74(local);
    if (persistent->value != 0 && (*(u32 *)((u8 *)persistent->value + 4) & ~0x7fffffffU) != 0) {
        result = fn_1_563B8((void *)fn_1_FCF50);
        mode = *(s16 *)persistent->value;
        if (mode == 0) {
            fn_1_7EB8C(value, lbl_1_rodata_761C[0]);
        } else {
            fn_1_7F230(value, (s32)mode, lbl_1_rodata_761C[0]);
        }
        lbl_8006DBAC(local);
        fn_1_563B8(result);
    }
}
/* fzgx:end fn_1_FD1D4 */

/* fzgx:begin fn_1_FD27C */
typedef struct {
    void *value;
} fn_1_FD27C_Fn1FD27CArg0;

typedef struct {
    u8 pad[0x40f0];
    void *value;
} fn_1_FD27C_Fn1FD27CArg1;

void fn_1_FD27C(fn_1_FD27C_Fn1FD27CArg0 *arg0, fn_1_FD27C_Fn1FD27CArg1 *arg1) {
    fn_1_FD27C_Fn1FD27CArg1 *persistent;
    void *value;
    void *result;
    s16 mode;
    u8 local[0x30];

    persistent = arg1;
    value = arg0->value;
    lbl_8006DB74(local);
    if (persistent->value != 0 && (*(u32 *)((u8 *)persistent->value + 4) & ~0x7fffffffU) != 0) {
        result = fn_1_563B8((void *)fn_1_FCF50);
        mode = *(s16 *)persistent->value;
        if (mode == 0) {
            fn_1_7EB8C(value, lbl_1_rodata_761C[0]);
        } else {
            fn_1_7F20C(value, (s32)mode, lbl_1_rodata_761C[0]);
        }
        lbl_8006DBAC(local);
        fn_1_563B8(result);
    }
}
/* fzgx:end fn_1_FD27C */

/* fzgx:begin fn_1_FD324 */
typedef struct {
	u8 pad390[0x390];
	u32 a;
	u8 pad3a0[0xC];
	u32 b;
	u32 c;
} Obj_fd324;

int fn_1_FD324(void *arg0) {
	Obj_fd324 *p;

	if (arg0 == 0) {
		return 0;
	}
	p = *(Obj_fd324 **)arg0;
	if (p == 0) {
		return 0;
	}
	if ((__rlwnm(p->a, 6, 31, 31) != 0 && p->b == 0)) {
		return 0;
	}
	if (p->c == 0) {
		return 0;
	}
	return 1;
}
/* fzgx:end fn_1_FD324 */

/* fzgx:begin fn_1_FD388 */
void fn_1_FD388(void) {
    fn_1_FD3A8();
}
/* fzgx:end fn_1_FD388 */

/* fzgx:begin fn_1_FD3A8 noprologue */
#include "types.h"
#include "rel/main_rel/bg_cas.h"

typedef enum { TF5 = 5 } Sig_GXInitTexObj_GXTexFmt;
typedef enum { WRAP0 = 0 } Sig_GXInitTexObj_GXTexWrapMode;
typedef enum { FILTER1 = 1 } Sig_GXInitTexObjLOD_GXTexFilter;
typedef enum { ANISO0 = 0 } Sig_GXInitTexObjLOD_GXAnisotropy;
typedef u8 Sig_GXInitTexObjLOD_GXBool;
typedef struct { u32 dummy[8]; } Sig_GXInitTexObj_GXTexObj;
typedef struct { u32 texture_filter, texture_lod, texture_size, texture_address, user_data, texture_format, tlut_name; u16 texture_time_count; u8 texture_tile_type, texture_flags; } Sig_GXInitTexObjLOD_GXTexObj;
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, Sig_GXInitTexObj_GXTexFmt, Sig_GXInitTexObj_GXTexWrapMode, Sig_GXInitTexObj_GXTexWrapMode, u8);
extern void GXInitTexObjLOD(Sig_GXInitTexObjLOD_GXTexObj *, Sig_GXInitTexObjLOD_GXTexFilter, Sig_GXInitTexObjLOD_GXTexFilter, f32, f32, f32, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXAnisotropy);
extern u32 GXLoadTexMtxImm(u32,u32,u32);
struct fn_1_FD3A8_lbl_1_rodata_7600 {
 u8 pad_0[0xC]; f32 unk_C; u8 pad_10[4]; f32 unk_14; u8 pad_18[4]; f32 unk_1C; u8 pad_20[0x28]; u32 unk_48; f32 unk_4C;
};
struct fn_1_FD3A8_lbl_801A6D00 { u32 unk_0; };
extern struct fn_1_FD3A8_lbl_1_rodata_7600 lbl_1_rodata_7600;
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern u32 fn_800371F8(u32,void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32,u32,u32,u32);
extern void fn_80015C1C(void *,f32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void fn_8003462C(u32,u32,u32);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_80072AB0(s32,s32,s32);
extern void fn_80072C24(s32,s32,s32,s32,s32);
extern void fn_80072CC4(s32,s32,s32,s32,s32);
extern void fn_80072D64(s32,s32,s32,s32,u8,s32);
extern void fn_80072E20(s32,s32,s32,s32,u8,s32);
extern void fn_800734A8(u32,s32,s32,s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *,s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32,s32,s32,u32,u32,u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32,u32,s32,s32,u32,s32,s32);
extern void fn_80074918(u8,s32,u8);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
#pragma opt_lifetimes off
void fn_1_FD3A8(void *arg0, f32 arg1) {
    f32 r2;
    f32 r1;
 struct fn_1_FD3A8_lbl_1_rodata_7600 *p_pool;
 f32 v9;
 f32 v0;
 f32 v1;
 f32 v4;
 f32 v3;
 f32 v5;
 f32 v6;
 struct {u32 a[12];} loc_78,loc_48,loc_18;
 u32 loc_10[2]; void *lab_t1;
 v0=*(f32 *)((u8 *)arg0+64);
 p_pool=(struct fn_1_FD3A8_lbl_1_rodata_7600 *)&lbl_1_rodata_7600;
 v1=*(f32 *)((u8 *)arg0+68);
 v3=v0*arg1; v4=(-v0)*arg1; v5=(-v1)*arg1; v6=v1*arg1;
 fn_80072558();
 lbl_8006DB74((void *)(lbl_801A6D00.unk_0+96));
 lbl_8006DD7C(); lbl_8006DB74(&loc_78); lbl_8006DCA4(); lbl_8006DFC4(&loc_78);
 fn_80072558(); fn_1_57720(1,1,1,0);
 {f32 d=lbl_1_bss_850D8-lbl_1_bss_850D4; f32 m=p_pool->unk_C*d; v9=lbl_1_bss_850D4+m;}
 lbl_8006DBAC(&loc_78);
 {
 f32 r0;
 f32 t;


 t=-v9;
 r0=*(f32 *)((u8 *)0xE0000000+8); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=*(f32 *)((u8 *)0xE0000000+0x18); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=*(f32 *)((u8 *)0xE0000000+0x28); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r0=((((r0)) * ((t))))+*(f32 *)((u8 *)0xE0000000+0xc); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=r1*t+*(f32 *)((u8 *)0xE0000000+0x1c); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=((((r2)) * ((t))))+*(f32 *)((u8 *)0xE0000000+0x2c); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0xc)=r0; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x1c)=r1; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x2c)=r2; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 }
 lbl_8006DB74(&loc_48); lbl_8006DCA4(); lbl_8006DFC4(&loc_48); fn_80072558();
 {f32 h=p_pool->unk_14; fn_80015C1C(&loc_18,v5,v6,v4,v3,lbl_1_bss_850D4,h,h,h,h);}
 lbl_8006DBAC(&loc_18); lbl_8006DFC4((void *)(lbl_801A6D00.unk_0+96));
 {
 f32 r0;
 f32 t;


 t=p_pool->unk_4C-v9;
 r0=*(f32 *)((u8 *)0xE0000000+8); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=*(f32 *)((u8 *)0xE0000000+0x18); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=*(f32 *)((u8 *)0xE0000000+0x28); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r0=((((r0)) * ((t))))+*(f32 *)((u8 *)0xE0000000+0xc); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=r1*t+*(f32 *)((u8 *)0xE0000000+0x1c); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=((((r2)) * ((t))))+*(f32 *)(((0x2c) + ((u8 *)0xE0000000))); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0xc)=r0; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x1c)=r1; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x2c)=r2; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 }
 GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)((u8 *)lbl_1_data_3EFA8+0x20),(u8 *)arg0+0x60,64,64,5,0,0,0);
 {f32 z=p_pool->unk_C; GXInitTexObjLOD((Sig_GXInitTexObjLOD_GXTexObj *)((u8 *)lbl_1_data_3EFA8+0x20),1,1,z,z,z,0,0,0);}
 fn_800724C8(); fn_8007245C(0x2200); loc_10[0]=p_pool->unk_48;
 fn_80074788(1); fn_800747D0(4,0,0,0,0,2,2); loc_10[1]=loc_10[0]; lab_t1=&loc_10[1]; fn_800371F8(1,lab_t1);
 fn_80074918(1,7,0); fn_800728A8(1,4,5,0); fn_800720B0(0); fn_80072864(2);
 fn_80073778((void *)((u8 *)lbl_1_data_3EFA8+0x20),0);
 GXLoadTexMtxImm(lbl_801A6D00.unk_0,30,0);
 fn_80074660(1); fn_800745A4(0,0,0,30,0,125); fn_80073678(1); fn_80073898(0); fn_80073C6C(0);
 fn_80072AB0(0,0,0); fn_800734A8(0,0,0,4); fn_80072C24(0,2,8,3,15);
 fn_80072D64(0,0,0,0,1,0); fn_80072CC4(0,7,4,1,7); fn_80072E20(0,0,0,0,1,0);
 {f32 d=lbl_1_bss_850D8-lbl_1_bss_850D4; f32 m=v9*d; f32 n=lbl_1_bss_850D4+m; v9=n/lbl_1_bss_850D4;}
 fn_8003462C(128,0,4);
 {f32 a=v9*v4; f32 c=v9*v6; f32 d=v9*v3; f32 b=v9*v5;
#define FIFO(x) *(volatile f32 *)((u8 *)0xCC010000-32768) = (x) // fzgx-allow: A2,S2 literal is a data constant in this table, not a pointer cast
 FIFO(a); FIFO(b); FIFO(p_pool->unk_C); FIFO(p_pool->unk_C); FIFO(p_pool->unk_C);
 FIFO(a); FIFO(c); FIFO(p_pool->unk_C); FIFO(p_pool->unk_C); FIFO(p_pool->unk_1C);
 FIFO(d); FIFO(c); FIFO(p_pool->unk_C); FIFO(p_pool->unk_1C); FIFO(p_pool->unk_1C);
 FIFO(d); FIFO(b); FIFO(p_pool->unk_C); FIFO(p_pool->unk_1C); FIFO(p_pool->unk_C);
#undef FIFO
 }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_FD3A8 */

/* fzgx:begin fn_1_FD844 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

/* begin game/main_rel/bg_cas_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

extern void fn_1_FF6B8(CasEmitter *em);

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H

/* end game/main_rel/bg_cas_types.h */

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};

struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;

typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;

typedef u8 Sig_GXInitTexObjLOD_GXBool;

typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FD844_Vec;

typedef struct {
    f32 x, y, z;
} CasVec;

typedef struct {
    CasVec v;
    u8 pad_C[0x34];
} CasMtx;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CasObj;

typedef struct {
    f32 x, y, z;
} CasSparkVec;

typedef struct {
    CasSparkVec pos;
    CasSparkVec base;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} CasSpark;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    u32 unk_10;
    CasSpark sparks[20];
} CasSparkSet;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_1_FC760(void *, void *);
extern void fn_8006F1F0(FD844_Vec *, FD844_Vec *, FD844_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern s32 fn_1_58C4(void);
extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void fn_800736C0(u32, void *);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8();
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(CasEmitter *em);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006E13C(void *);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_FFC60(CasSparkSet *state);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);

typedef struct {
    u32 unk_0;
    u8 pad_4[8];
} FD844_Elem12;

/* the loaded cas object referenced by the context */
typedef struct {
    u8 pad_0[0x338];
    FD844_Elem12 elems[7];  /* 0x338 */
    u8 pad_38C[4];
    u32 unk_390;
    u8 pad_394[0xC];
    u32 unk_3A0;            /* table base, 0x360-byte entries */
    u8 pad_3A4[0x16];
    s16 unk_3BA;
} FD844_Obj;

/* texture descriptor at +0x20 of every 0x2060-byte source entry */
typedef struct {
    s16 unk_0;
    u8 pad_2[2];
    u32 flags;              /* 0x4 */
    s16 rot_x;              /* 0x8 */
    s16 rot_y;              /* 0xA */
    u8 pad_C[0x1C];
    FD844_Vec eye;          /* 0x28 */
    FD844_Vec target;       /* 0x34 */
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x18];
    u8 image[0x1FE0];       /* 0x60 */
} FD844_Tex;

typedef struct {
    u8 pad_0[0x20];
    FD844_Tex tex;          /* 0x20 */
} FD844_Src;                /* 0x2060 bytes */

typedef struct {
    u8 pad_0[0x40];
    u8 texobj[0x20];        /* 0x40 */
    u8 pad_60[0x60];
    u8 mtx[0x30];           /* 0xC0 */
    u8 pad_F0[0x4104 - 0xF0];
    f32 unk_4104;
    f32 unk_4108;
    FD844_Obj *obj;         /* 0x410C */
    FD844_Tex *tex;         /* 0x4110 */
    void *sel;              /* 0x4114 */
} FD844_Slot;

typedef struct {
    FD844_Obj *obj;         /* 0x0 */
    u8 count;               /* 0x4 */
    u8 pad_5[0x10428 - 0x5];
    u32 unk_10428;
} FD844_Ctx;

/* slot i of the context: 0x4100 bytes apart, the trailing fields overlap the next slot */
#define FD844_SLOT(ctx, i) ((FD844_Slot *)((u8 *)(ctx) + (i) * 0x4100))


/* Literal pool of the retail TU (lbl_1_rodata_7600): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 2.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
}
static const u32 fzgx_pool_table4[11] = {0x00000000, 0x3F000000, 0x41800000, 0x3F800000, 0x43000000,
                                         0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0xBF800000,
                                         0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

int fn_1_FD844(FD844_Src *src, FD844_Ctx *ctx) {
    u8 i;
    u32 table;
    u8 j;
    FD844_Obj *obj;
    u32 off;
    u8 *texobj;
    FD844_Vec target;
    FD844_Vec eye;

    obj = ctx->obj;
    if (src == NULL) {
        return 0;
    }
    if (ctx == NULL) {
        return 0;
    }
    if (obj == NULL) {
        return 0;
    }
    if (obj->unk_390 & 0x4000000) {
        for (j = 0; j < 3; j++) {
            table = obj->unk_3A0;
            if (table == 0) {
                return 0;
            }
            off = obj->unk_3BA << 2;
            off += j * 0x360;
            if (*(u32 *)(table + off + 0x344) == 0) {
                return 0;
            }
        }
    } else {
        if (obj->elems[obj->unk_3BA].unk_0 == 0) {
            return 0;
        }
    }

    for (i = 0; i < ctx->count; i++) {
        if (!(src[i].tex.flags & 0x80000000)) {
            *(u32 *)((u32)ctx + i * 0x4100 + 0x4110) = 0;
        } else {
            FD844_Vec up;
            FD844_SLOT(ctx, i)->obj = ctx->obj;
            {
                FD844_Vec up_init = {0.0f, 1.0f, 0.0f};
                up = up_init;
            }
            eye = src[i].tex.eye;
            target = src[i].tex.target;
            lbl_1_bss_850D4 = 2.0f;
            lbl_1_bss_850D8 = 8.0f;
            FD844_SLOT(ctx, i)->tex = &src[i].tex;
            FD844_SLOT(ctx, i)->sel = (void *)((u32)src + (src[i].tex.unk_0 << 3) + 0x81A4);
            FD844_SLOT(ctx, i)->unk_4104 = FD844_SLOT(ctx, i)->tex->unk_40;
            FD844_SLOT(ctx, i)->unk_4108 = FD844_SLOT(ctx, i)->tex->unk_44;
            fn_8006F1F0(&eye, &up, &target);
            mathutil_mtxA_rotate_x(FD844_SLOT(ctx, i)->tex->rot_x);
            mathutil_mtxA_rotate_y(FD844_SLOT(ctx, i)->tex->rot_y);
            lbl_8006DB74(FD844_SLOT(ctx, i)->mtx);
            texobj = FD844_SLOT(ctx, i)->texobj;
            GXInitTexObj(texobj, FD844_SLOT(ctx, i)->tex->image, 0x40, 0x40, 5, 0, 0, 0);
            GXInitTexObjLOD(texobj, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);
        }
    }

    for (i = 0; i < ctx->count; i++) {
        FD844_Tex *tex;
        if (ctx->unk_10428 == 0) {
            break;
        }
        tex = FD844_SLOT(ctx, i)->tex;
        if (tex != NULL && (tex->flags & 0x80000000)) {
            if (0.0f == tex->unk_40 || 0.0f == tex->unk_44) {
                tex->flags &= 0x7FFFFFFF;
            } else {
                fn_1_FC760(ctx, &FD844_SLOT(ctx, i)->pad_0[0x20]);
            }
        }
    }
    return 1;
}
/* fzgx:end fn_1_FD844 */

/* fzgx:begin fn_1_FDB40 */
typedef struct {
    u32 b0 : 5;
    u32 b5 : 1;
    u32 rest : 26;
} FDB40Bits;

static inline u32 rotl(u32 x, int n) { return (x >> n) & 1; }

s32 fn_1_FDB40(void **arg0) {
    u8 *p;
    u8 *q;
    if (arg0 == 0) {
        return 0;
    }
    p = *arg0;
    if (p == 0) {
        return 0;
    }
    if (*(s16 *)(p + 800) >= 4) {
        return 0;
    }
    if (*(u32 *)(p + 932) == 0) {
        return 0;
    }
    if (*(s16 *)(p + 954) == 5) {
        return 0;
    }
    if (__rlwnm(*(u32 *)(p + 912), 6, 31, 31) && *(u32 *)(p + 928) == 0) {
        return 0;
    }
    if ((*(u32 *)(p + 912) & 0x200000) != 0) {
        return 0;
    }
    q = *(u8 **)(p + 812);
    if (q != 0 && (*(u32 *)(q + 1420) & 0x10) != 0) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_FDB40 */

/* fzgx:begin fn_1_FDC00 */
typedef struct Sig_fn_1_14E09C_Fn14E09CValue { void *value; } Sig_fn_1_14E09C_Fn14E09CValue;
typedef struct Sig_fn_1_14E09C_Fn14E09CRef { u8 pad8[8]; Sig_fn_1_14E09C_Fn14E09CValue *value; } Sig_fn_1_14E09C_Fn14E09CRef;
typedef struct Sig_fn_1_14E09C_Fn14E09CObj { u8 pad344[0x344]; Sig_fn_1_14E09C_Fn14E09CRef *ref; } Sig_fn_1_14E09C_Fn14E09CObj;
struct Sig_fn_1_87238_ModelItem { u32 flags; char pad[0x1c]; };
struct Sig_fn_1_87238_Model { char pad[0x18]; u16 count; char pad2[0x26]; struct Sig_fn_1_87238_ModelItem items[1]; };
struct Sig_fn_1_87238_CarSlot { struct Sig_fn_1_87238_Model **model_ptr; char pad[8]; };
struct Sig_fn_1_87238_fn_1_87238_Car { char pad[0x328]; s8 field_0x328; char pad1[0xb]; struct Sig_fn_1_87238_CarSlot slots[1]; char pad2[0x50]; u32 flags; };
struct fn_1_FDC00_Arg1 { u8 pad_0[0x40F0]; s16 *unk_40F0; };
struct fn_1_FDC00_lbl_1_rodata_7650 { u32 unk_0; u32 unk_4; u32 unk_8; };
extern u32 lbl_1_rodata_7650[3];
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_14DE80(void *, void *, void *, s8, f32);
extern void fn_1_14E054(Sig_fn_1_14E09C_Fn14E09CObj *, void *, s8, f32);
extern void fn_1_14E198(void *, void *, s8, f32);
extern void fn_1_55210(void *);
extern void fn_1_87238(struct Sig_fn_1_87238_fn_1_87238_Car *, s8, f32);
void fn_1_FDC00(void *arg0, struct fn_1_FDC00_Arg1 *arg1, f32 arg2) {
    u8 *v0;
    s8 v3;
    s16 v4;
    struct fn_1_FDC00_lbl_1_rodata_7650 loc_10;
    u32 loc_C;
    u32 loc_8;
    if (arg0 != 0) {
        v0 = *(u8 **)arg0;
        v3 = (s8)*(s16 *)(v0 + 954);
        if ((*(u32 *)(v0 + 912) & 0x4000000) != 0) {
            loc_C = 0;
            loc_8 = 0;
            loc_10 = *(struct fn_1_FDC00_lbl_1_rodata_7650 *)lbl_1_rodata_7650;
            v4 = *arg1->unk_40F0;
            v0 = *(u8 **)(v0 + 928);
            switch (v4) {
            case 0:
                fn_1_14DE80(v0, &loc_C, &loc_8, v3, lbl_1_rodata_761C[0]);
                break;
            case 1:
                fn_1_14E054((Sig_fn_1_14E09C_Fn14E09CObj *)v0, &loc_10, v3, lbl_1_rodata_761C[0]);
                break;
            case 2:
                fn_1_14E198(v0, &loc_10, v3, lbl_1_rodata_761C[0]);
                break;
            }
        } else {
            v4 = *arg1->unk_40F0;
            if (v4 == 0) {
                fn_1_87238((struct Sig_fn_1_87238_fn_1_87238_Car *)v0, v3, lbl_1_rodata_761C[0]);
            } else if (*(s8 *)(v0 + 808) == 4) {
                v0 += v3 * 12;
                v0 = *(u8 **)(v0 + 820);
                fn_1_55210(((void **)v0)[v4]);
            } else if (*(s8 *)(v0 + 808) == 40) {
                if (v3 == 0) {
                    v0 += v3 * 12;
                    v0 = *(u8 **)(v0 + 820);
                    v0 += v4 * 4;
                    fn_1_55210(*(void **)(v0 + 8));
                } else {
                    v0 += v3 * 12;
                    v0 = *(u8 **)(v0 + 820);
                    fn_1_55210(((void **)v0)[v4]);
                }
            }
        }
    }
}
/* fzgx:end fn_1_FDC00 */

/* fzgx:begin fn_1_FDD7C */
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern f32 lbl_1_rodata_7614[2];

extern f32 fn_1_843BC(void *);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(s32, s32);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void fn_1_7F1E8(void *, s32, f32);
extern void lbl_8006DFE8(void *);
extern void lbl_8006DCA4(void);

typedef struct {
    u8 pad_0[0x32C];
    u8 *unk_32C;
    u8 pad_330[0x60];
    u32 unk_390;
    u8 pad_394[0x26];
    s16 unk_3BA;
} BgCasRacer;

typedef struct {
    u8 pad_0[0x40E0];
    f32 unk_40E0;
    u8 pad_40E4[0xC];
    s16 *unk_40F0;
} BgCasScene;

void fn_1_FDD7C(BgCasRacer **arg0, BgCasScene *scene) {
    s16 index;
    BgCasRacer *racer;
    f32 value;
    void *saved;
    s16 state;
    s32 mode;

    racer = *arg0;
    state = racer->unk_3BA;
    if (state == 3) {
        racer->unk_3BA = 2;
    }
    if (scene->unk_40F0 == NULL) {
        return;
    }
    index = *scene->unk_40F0;
    if (racer->unk_32C == NULL) {
        value = lbl_1_rodata_7614[0];
    } else {
        value = scene->unk_40E0 = fn_1_843BC(racer);
        if (value <= 0.7f) {
            return;
        }
    }
    saved = fn_1_563B8((void *)fn_1_FCF50);
    mode = index;
    fn_1_566EC(1, 0xFF);
    if (racer->unk_32C != NULL) {
        lbl_8006DFE8(racer->unk_32C + 0x14C);
    } else {
        lbl_8006DCA4();
    }
    if (index == 0) {
        fn_1_7EB8C(racer, value);
    } else if (racer->unk_390 & 0x04000000) {
        fn_1_7F20C(racer, mode, value);
    } else {
        fn_1_7F1E8(racer, mode, value);
    }
    fn_1_566EC(0, 0);
    fn_1_563B8(saved);
    racer->unk_3BA = state;
}
/* fzgx:end fn_1_FDD7C */

/* fzgx:begin fn_1_FDEC8 */
extern f32 lbl_1_rodata_7614[2];
extern f32 lbl_1_rodata_761C[13];
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(s32, s32);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void fn_1_7F1E8(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_80072558(void);

typedef struct {
    u8 pad_0[0x32C];
    u8 *unk_32C;
    u8 pad_330[0x60];
    u32 unk_390;
    u8 pad_394[0x26];
    s16 unk_3BA;
} fn_1_FDEC8_Racer;

typedef struct {
    u8 pad_0[0x40F0];
    s16 *unk_40F0;
} fn_1_FDEC8_Scene;

void fn_1_FDEC8(fn_1_FDEC8_Racer **arg0, fn_1_FDEC8_Scene *scene) {
    s16 index;
    u8 mtx[0x30];
    s32 mode;
    fn_1_FDEC8_Racer *racer;
    void *saved;
    s16 state;
    f32 value;

    lbl_8006DB74(mtx);
    racer = *arg0;
    state = racer->unk_3BA;
    if (state == 3) {
        racer->unk_3BA = 2;
    }
    if (scene->unk_40F0 != NULL) {
        index = *scene->unk_40F0;
        if (racer->unk_32C == NULL) {
            value = lbl_1_rodata_7614[0];
        } else {
            value = lbl_1_rodata_761C[0];
        }
        saved = fn_1_563B8((void *)fn_1_FCF50);
        mode = index;
        fn_1_566EC(1, 0xFF);
        if (index == 0) {
            fn_1_7EB8C(racer, value);
        } else if (racer->unk_390 & 0x04000000) {
            fn_1_7F20C(racer, mode, value);
        } else {
            fn_1_7F1E8(racer, mode, value);
        }
        fn_1_566EC(0, 0);
        fn_1_563B8(saved);
        racer->unk_3BA = state;
    }
    lbl_8006DBAC(mtx);
    fn_80072558();
}
/* fzgx:end fn_1_FDEC8 */

/* fzgx:begin fn_1_FDFF4 */
#include "rel/main_rel/bg_cas.h"
extern Obj_1_bss_850C6 lbl_1_bss_850C0__fzgx_offset_6;

// Mark the background-collision object as active.
void fn_1_FDFF4(void) {
    lbl_1_bss_850C0__fzgx_offset_6.unk_0 = 1;
}
/* fzgx:end fn_1_FDFF4 */

/* fzgx:begin fn_1_FE004 */
#include "rel/main_rel/bg_cas.h"
extern Obj_1_bss_850C6 lbl_1_bss_850C0__fzgx_offset_6;

void fn_1_FE004(void) {
    lbl_1_bss_850C0__fzgx_offset_6.unk_0 = 0;
}
/* fzgx:end fn_1_FE004 */

/* fzgx:begin fn_1_FE014 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x4];
u8 unk_4;
u8 unk_5;
} Obj_1_bss_850C0;
extern Obj_1_bss_850C0 lbl_1_bss_850C0;


extern void fn_80072558(void);


extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);


extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);


typedef struct {
s16 unk_0;
u8 pad_2[0x360 - 2];
} CasTableEntry;
typedef struct {
u8 unk_0;
u8 pad_1[7];
} CasSelEntry;
typedef struct {
u8 pad_0[0x32C];
u32 unk_32C;
u8 pad_330[0x60];
u32 unk_390;
u8 pad_394[0xC];
CasTableEntry *unk_3A0;
u32 unk_3A4;
u8 pad_3A8[0x12];
s16 unk_3BA;
} CasObject;
typedef struct {
CasObject *value;
} CasObjectRef;
typedef struct {
u8 pad_0[0x40F0];
s16 *view;
} CasContext;
typedef struct {
u8 pad_0[0x4];
u8 unk_4;
u8 unk_5;
u8 pad_6[2];
CasSelEntry *unk_8;
u8 *unk_C;
} CasBase;
static inline void cas_draw_inner(CasObjectRef *ref, CasContext *ctx) {
u8 inner[0x30];
CasObject *obj;
void *prev;
s16 mode;
s16 saved;
f32 alpha;
lbl_8006DB74(inner);
obj = ref->value; saved = obj->unk_3BA; if (saved == 3) { obj->unk_3BA = 2; } if (ctx->view != ((void *)0)) { mode = *ctx->view; alpha = (obj->unk_32C == 0) ? 0.5f : 1.0f; prev = fn_1_563B8((void *)fn_1_FCF50); fn_1_566EC(1, 0xff); if (mode == 0) { fn_1_7EB8C(obj, alpha); } else if (obj->unk_390 & 0x4000000) { fn_1_7F20C(obj, mode, alpha); } else { fn_1_7F1E8(obj, mode, alpha); } fn_1_566EC(0, 0); fn_1_563B8(prev); obj->unk_3BA = saved; } ;
lbl_8006DBAC(inner);
}
static inline void cas_draw_nested(CasObjectRef *ref, CasContext *ctx) {
u8 outer[0x30];
lbl_8006DB74(outer);
fn_80072558();
cas_draw_inner(ref, ctx);
fn_80072558();
lbl_8006DBAC(outer);
}
static inline void cas_draw_multi(CasObjectRef *ref, CasContext *ctx) {
CasObject *obj;
void *prev;
s16 mode;
s16 saved;
f32 alpha;
obj = ref->value; saved = obj->unk_3BA; if (saved == 3) { obj->unk_3BA = 2; } if (ctx->view != ((void *)0)) { mode = *ctx->view; alpha = (obj->unk_32C == 0) ? 0.5f : 1.0f; prev = fn_1_563B8((void *)fn_1_FCF50); fn_1_566EC(1, 0xff); if (mode == 0) { fn_1_7EB8C(obj, alpha); } else if (obj->unk_390 & 0x4000000) { fn_1_7F230(obj, mode, alpha); } else { fn_1_7F1E8(obj, mode, alpha); } fn_1_566EC(0, 0); fn_1_563B8(prev); obj->unk_3BA = saved; } ;
}
static inline void cas_draw_single(CasObjectRef *ref, CasContext *ctx, CasBase *base) {
u8 buf[0x30];
void *res;
s16 kind;
res = ((void *)0) ;
lbl_8006DB74(buf);
kind = *ctx->view;
if (kind != 0) {
if (kind == 1) {
res = fn_1_14DD68(base->unk_C + base->unk_8->unk_0 * 0xa20);
} else if (kind == 2) {
res = fn_1_14DDF4(base->unk_C + base->unk_8->unk_0 * 0xa20);
}
lbl_8006E0A4(res);
}
fn_80072558();
cas_draw_multi(ref, ctx);
lbl_8006DBAC(buf);
}
void fn_1_FE014(CasObjectRef *ref, CasContext *ctx) {
CasBase *base = (CasBase *)&lbl_1_bss_850C0;
CasObject *obj;
CasTableEntry *tbl;
CasSelEntry *sel;
s16 idx;
s32 b;
s32 a;
obj = ref->value;
if (obj == ((void *)0) || obj->unk_3A4 == 0 || (tbl = obj->unk_3A0) == ((void *)0) || base->unk_C == ((void *)0) ||
(sel = base->unk_8) == ((void *)0) ) {
return;
}
a = tbl[0].unk_0;
b = sel[0].unk_0;
if (a == b && tbl[1].unk_0 == sel[1].unk_0 && tbl[2].unk_0 == sel[2].unk_0 && base->unk_4 == 0) {
if (base->unk_5 == *ctx->view) {
cas_draw_nested(ref, ctx);
}
} else if (base->unk_4 != 0) {
idx = *ctx->view;
if (tbl[idx].unk_0 == sel[idx].unk_0) {
cas_draw_single(ref, ctx, base);
}
} else {
idx = *ctx->view;
if (base->unk_5 == idx && tbl[idx].unk_0 == sel[idx].unk_0) {
if (a != b) {
cas_draw_single(ref, ctx, base);
} else {
cas_draw_nested(ref, ctx);
}
}
}
}
/* fzgx:end fn_1_FE014 */

/* fzgx:begin fn_1_FE5C4 */
#include "rel/main_rel/bg_cas.h"

void fn_1_FE5C4(u8 arg0, u32 arg1, u32 arg2, u8 arg3) {
    lbl_1_bss_850C0.unk_4 = arg3;
    lbl_1_bss_850C0.unk_5 = arg0;
    *(u32 *)((u8 *)&lbl_1_bss_850C0 + 0x8) = arg2;
    *(u32 *)((u8 *)&lbl_1_bss_850C0 + 0xc) = arg1;
}
/* fzgx:end fn_1_FE5C4 */

/* fzgx:begin fn_1_FE5E0 */
// fn_1_FE5E0: No-op return
void fn_1_FE5E0(void) {
    return;
}
/* fzgx:end fn_1_FE5E0 */

/* fzgx:begin fn_1_FE5E4 */
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);

typedef struct {
    u8 pad_0[0x1B1E4];
    u16 unk_1B1E4;
} Obj_1_data_2A7E0_At3C_Ext;

void fn_1_FE5E4(void) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508(&lbl_1_data_2A7E0);
    fn_1_FFC60(obj);
    fn_1_FEC7C(obj);
    ((Obj_1_data_2A7E0_At3C_Ext *)obj)->unk_1B1E4 = 0;
    obj->unk_430 = lbl_1_rodata_76A8;
}
/* fzgx:end fn_1_FE5E4 */

/* fzgx:begin fn_1_FE640 */
// fn_1_FE640: empty in retail (single blr).
void fn_1_FE640(void) {
}
/* fzgx:end fn_1_FE640 */

/* fzgx:begin fn_1_FE644 */
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern void fn_1_9AD54(void);
extern void fn_1_FFE7C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FED34(Obj_1_data_2A7E0_At3C *);
extern void fn_1_9A7A8(void *);

static const f32 fzgx_pool_fzgx_zero[1] = {0.0f};
static const u32 fzgx_pool_fzgx_color[1] = {0};
static const f32 fzgx_pool_fzgx_one[1] = {1.0f};

typedef struct {
    u8 pad_0[0x1B1E4];
    s16 unk_1B1E4;
} Obj_1_data_2A7E0_At3C_Ext;

typedef union {
    u32 unk_0;
    struct {
        u8 unk_0;
        u8 unk_1;
        u8 unk_2;
    } unk_4;
} Obj_1_FE644_Pack;

typedef struct {
    Obj_1_FE644_Pack unk_0;
    u32 unk_4;
} Obj_1_FE644_Out;

void fn_1_FE644(void) {
    Obj_1_data_2A7E0_At3C_Ext *ext;
    u32 *fzgx_value;
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_FE644_Out out;
    struct { f32 value; } f;
    f32 t;

    obj = lbl_1_data_2A7E0.unk_3C;
    ext = (Obj_1_data_2A7E0_At3C_Ext *)obj;
    fn_1_9AD54();
    if ((s32)obj->unk_10 != 0) {
        fn_1_FFE7C(obj);
    }
    fn_1_FED34(obj);
    f.value = fzgx_pool_fzgx_zero[0];
    if (ext->unk_1B1E4 < 0x1E78) {
        ext->unk_1B1E4++;
    }
    if (ext->unk_1B1E4 > 0x4B0) {
        t = (f32)(s16)(ext->unk_1B1E4 - 0x4B0) / 6600.0f;
        if (t < fzgx_pool_fzgx_zero[0]) {
            f.value = fzgx_pool_fzgx_zero[0];
        } else if (t > fzgx_pool_fzgx_one[0]) {
            f.value = fzgx_pool_fzgx_one[0];
        } else {
            f.value = t;
        }
    }
    out.unk_0.unk_0 = fzgx_pool_fzgx_color[0];
    out.unk_0.unk_4.unk_0 = (u8)(s32)(110.0f * f.value);
    out.unk_0.unk_4.unk_1 = (u8)(s32)(60.0f * f.value);
    out.unk_0.unk_4.unk_2 = (u8)(s32)(15.0f * f.value);
    fzgx_value = &(out.unk_4);
    *fzgx_value = out.unk_0.unk_0;
    fn_1_9A7A8(&out.unk_4);
}
/* fzgx:end fn_1_FE644 */

/* fzgx:begin fn_1_FE780 */
// fn_1_FE780: Empty return
void fn_1_FE780(void) {
}
/* fzgx:end fn_1_FE780 */

/* fzgx:begin fn_1_FE784 */
// Update the background object and process it when its active state is set.
void fn_1_FE784(void) {
    Obj_1_data_2A7E0_At3C *background_object = lbl_1_data_2A7E0.unk_3C;

    fn_1_9AD88();
    if ((s32)background_object->unk_10 != 0) {
        fn_1_10069C(background_object);
    }
    fn_1_FF038(background_object);
}
/* fzgx:end fn_1_FE784 */

/* fzgx:begin fn_1_FE7D4 */
// fn_1_FE7D4: empty in retail (single blr).
void fn_1_FE7D4(void) {
}
/* fzgx:end fn_1_FE7D4 */

/* fzgx:begin fn_1_FE7D8 */
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

typedef struct {
    f32 x, y, z;
} FE7D8_Vec;

/* one 0x24-byte spawn point of the background table */
typedef struct {
    FE7D8_Vec from;  /* 0x00 */
    s16 unk_C;
    s16 unk_E;
    u8 pad_10[4];
    FE7D8_Vec to;    /* 0x14 */
    u8 pad_20[4];
} FE7D8_Spawn;

typedef struct {
    s32 active;      /* 0x00 */
    s32 life;        /* 0x04 */
    FE7D8_Vec pos;   /* 0x08 */
    FE7D8_Vec prev;  /* 0x14 */
    FE7D8_Vec vel;   /* 0x20 */
    u16 rot_x;       /* 0x2C */
    u16 rot_y;       /* 0x2E */
    s16 spin_x;      /* 0x30 */
    s16 spin_y;      /* 0x32 */
    f32 unk_34;
    f32 size;        /* 0x38 */
} FE7D8_Particle;

extern u32 fn_1_584AC(void);
extern void lbl_8006D5F0(FE7D8_Vec *src, FE7D8_Vec *dst, f32 scale);
extern void lbl_8006D8D8(s16 angle);
extern void lbl_8006E1C0(FE7D8_Vec *src, FE7D8_Vec *dst);

/* uniform random value in [0, 1] */
#define RANDF() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_layout(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    s = 0.0f;
}

static const u32 fzgx_pool_table_4[1] = {0x00000000};

static void fzgx_pool_layout_1(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile s32 i; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    w = fzgx_pool_table_4[0];
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
    s = (f32)i;
}
#pragma section code_type ".text"

#pragma fp_contract off
void fn_1_FE7D8(u8 *arg0, s32 arg1) {
    FE7D8_Particle *p = (FE7D8_Particle *)arg0;
    FE7D8_Spawn *e;
    FE7D8_Vec d;

    e = (FE7D8_Spawn *)lbl_1_bss_3BE0->unk_A8;
    e += (u16)fn_1_584AC() % (s32)lbl_1_bss_3BE0->unk_A4;
    p->active = arg1;
    if (arg1 != 0) {
        p->life = 100.0f + 300.0f * RANDF();
        p->pos = e->from;
        p->prev = p->pos;
        d.x = e->to.x - e->from.x;
        d.y = e->to.y - e->from.y;
        d.z = e->to.z - e->from.z;
        lbl_8006D5F0(&d, &p->vel, (f32)(e->unk_E >> 7) * (15.0f + 4.0f * RANDF()) / 10.0f);
        p->size = 2.0f + 2.0f * RANDF();
        p->size *= (f32)(e->unk_C >> 7) / 10.0f;
    } else {
        p->life = 200.0f + 400.0f * RANDF();
        {
            FE7D8_Vec dir = {0.0f, 0.0f, -1.0f};

            d = dir;
        }
        lbl_8006D8D8(fn_1_584AC());
        lbl_8006E1C0(&d, &d);
        lbl_8006D5F0(&d, &p->pos, 2500.0f + 1000.0f * RANDF());
        p->pos.y = 1400.0f + 300.0f * RANDF();
        p->vel.x = RANDF() - 0.5 - 5.0;
        p->vel.y = -(4.0f + 7.0f * RANDF());
        p->vel.z = RANDF() - 0.5;
        p->size = 2.0f + 2.5f * RANDF();
    }
    p->rot_x = fn_1_584AC();
    p->rot_y = fn_1_584AC();
    p->spin_x = (s32)(768.0f * RANDF()) + 256;
    p->spin_y = (s32)(768.0f * RANDF()) + 256;
    p->unk_34 = 0.0f;
}
#pragma fp_contract reset
/* fzgx:end fn_1_FE7D8 */

/* fzgx:begin fn_1_FEC7C */
#include "rel/main_rel/bg_cas.h"

void fn_1_FEC7C(void *object) {
    s32 count;
    s32 index;
    u8 *entry;

    entry = (u8 *)object + 0x434;
    memset(entry, 0, 0x1ADB0);
    index = 0;
    while (index < (count = (s32)lbl_1_bss_3BE0->unk_A4)) {
        fn_1_FE7D8(entry, 1);
        fn_1_FF420(entry);
        index++;
        entry += 0x44C;
    }
    while (count < 0x64) {
        fn_1_FE7D8(entry, 0);
        fn_1_FF420(entry);
        count++;
        entry += 0x44C;
    }
}
/* fzgx:end fn_1_FEC7C */

/* fzgx:begin fn_1_FED34 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
}
#pragma section code_type ".text"

typedef struct {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x8];
    f32 unk_14;
    u8 pad_18[0x8];
    f64 unk_20;
    u8 pad_28[0xC];
    f32 unk_34;
    u8 pad_38[0x50];
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
    f32 unk_A0;
} RoData_76A8;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern f32 lbl_1_rodata_76A8[84];
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32, void *);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FE7D8(void *, u32);
extern u32 fn_1_FF6B8(void *);

static inline f32 fn_1_FED34_operand(f32 right, f32 left) { return left + right; }
void fn_1_FED34(void *arg0) {
    u8 sp8[16];
    RoData_76A8 *rd;
    s32 var_r30;
    s32 var_r29;
    u8 *var_r28;
    u32 temp_r3;
    f32 var_f31;
    f32 var_f0;
    f32 temp_delta;
    f32 temp_f1;
    f32 temp_f3;

    rd = (RoData_76A8 *)lbl_1_rodata_76A8;
    var_r28 = (u8 *)arg0 + 0x434;
    temp_r3 = fn_1_904();
    if (temp_r3 < 0xDACU) {
        var_f31 = (0.100000001f);
    } else if (temp_r3 < 0x1388U) {
        var_f31 = (0.5f);
    } else {
        var_f31 = (1.0f);
    }
    if (fn_1_914() > 1U) {
        var_f31 = (0.0f);
    }
    fn_1_681C(0U, sp8);
    if (fn_1_1FB80(sp8, 1U) != 0U) {
        var_f0 = (0.0f);
    } else if (fn_1_1FB80(sp8, 2U) != 0U) {
        var_f0 = (0.25f);
    } else if (fn_1_1FB80(sp8, 4U) != 0U) {
        var_f0 = (0.5f);
    } else {
        var_f0 = (1.0f);
    }
    if (var_f31 > var_f0) {
        var_f31 = var_f0;
    }
    temp_f3 = *(f32 *)((u8 *)arg0 + 0x430);
    var_r30 = 0;
    temp_delta = (0.100000001f) * (var_f31 - temp_f3);
    temp_f1 = (100.0f);
    *(f32 *)((u8 *)arg0 + 0x430) = temp_f3 + temp_delta;
    var_r29 = (s32)(temp_f1 * *(f32 *)((u8 *)arg0 + 0x430));
    do {
        s32 count = *(s32 *)(var_r28 + 4);
        if (count != 0) {
            *(s32 *)(var_r28 + 4) = count - 1;
        }
        if (var_r30 <= var_r29) {
            if (*(s32 *)(var_r28 + 4) <= 0) {
                fn_1_FE7D8(var_r28, *(u32 *)var_r28);
            }
        } else if (*(s32 *)(var_r28 + 4) > 0x1E) {
            *(s32 *)(var_r28 + 4) = 0x1E;
        }
        if (*(s32 *)(var_r28 + 4) > 0) {
            *(f32 *)(var_r28 + 8) = *(f32 *)(var_r28 + 8) + *(f32 *)(var_r28 + 32);
            *(f32 *)(var_r28 + 12) = *(f32 *)(var_r28 + 12) + *(f32 *)(var_r28 + 36);
            *(f32 *)(var_r28 + 16) = *(f32 *)(var_r28 + 16) + *(f32 *)(var_r28 + 40);
            *(s16 *)(var_r28 + 44) = (s16)(*(s16 *)(var_r28 + 44) + *(s16 *)(var_r28 + 48));
            *(s16 *)(var_r28 + 46) = (s16)(*(s16 *)(var_r28 + 46) + *(s16 *)(var_r28 + 50));
            *(Vec3 *)(var_r28 + 20) = *(Vec3 *)(var_r28 + 8);
            if (*(s32 *)(var_r28 + 4) >= 0x3C) {
                if (*(f32 *)(var_r28 + 52) < (1.0f)) {
                    *(f32 *)(var_r28 + 52) = fn_1_FED34_operand(((0.0500000007f)), (*(f32 *)(var_r28 + 52)));
                }
                if (*(f32 *)(var_r28 + 52) > (1.0f)) {
                    *(f32 *)(var_r28 + 52) = (1.0f);
                }
                if (*(f32 *)(var_r28 + 12) < (-2000.0f)) {
                    *(s32 *)(var_r28 + 4) = 0x1E;
                }
            }
            if (*(s32 *)(var_r28 + 4) < 0x3C) {
                if (*(s32 *)var_r28 != 0) {
                    *(f32 *)(var_r28 + 52) *= (f32)*(s32 *)(var_r28 + 4) / (60.0f);
                } else {
                    if (*(s32 *)(var_r28 + 4) < 0x3C) {
                        *(f32 *)(var_r28 + 56) *= (1.01999998f);
                    }
                    if (*(s32 *)(var_r28 + 4) < 0x1E) {
                        *(f32 *)(var_r28 + 52) *= (f32)*(s32 *)(var_r28 + 4) / (30.0f);
                    }
                }
            }
            fn_1_FF6B8(var_r28);
        }
        var_r30 += 1;
        var_r28 += 0x44C;
    } while (var_r30 < 0x64);
}
/* fzgx:end fn_1_FED34 */

/* fzgx:begin fn_1_FF038 noprologue */
#include "types.h"

typedef struct FF038Vec {
    f32 x;
    f32 y;
    f32 z;
} FF038Vec;

typedef struct FF038Entry {
    s32 active;      /* 0x00 */
    s32 count;       /* 0x04 */
    FF038Vec pos;    /* 0x08 */
    u8 pad_14[0x0C];
    FF038Vec dir;    /* 0x20 */
    s16 rotX;        /* 0x2C */
    s16 rotY;        /* 0x2E */
    u8 pad_30[0x04];
    f32 alpha;       /* 0x34 */
    f32 scale;       /* 0x38 */
    u8 pad_3C[0x44C - 0x3C];
} FF038Entry;

typedef struct FF038Tex {
    u8 pad[0x24];
    void *texobj;
} FF038Tex;

typedef struct FF038Owner {
    u8 pad_000[0x424];
    void *unk424;
    FF038Tex *unk428;
    FF038Tex *unk42C;
    u8 pad_430[0x04];
    FF038Entry entries[100];
} FF038Owner;

typedef struct FF038Sprite {
    f32 unk0;
    f32 unk4;
    u8 mtx[0x30];
    u32 flags;       /* 0x38 */
    u8 color[4];     /* 0x3C */
} FF038Sprite;

extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_54E34(void *, f32);
extern u32 fn_1_584AC(void);
extern u32 fn_1_FFA0C(FF038Entry *);
extern s32 lbl_8006D24C(f32, f32);
extern void lbl_8006D7DC(void *);
extern u32 lbl_8006DCA4(void);
extern void *memset(void *, int, u32);
extern void fn_1_1011CC(int, int);
extern void fn_1_55210(void *);
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern void fn_1_9EDE8(void *);
extern void fn_8006EDBC(void *, void *, s16 *, s16 *);
extern void fn_80072558(void);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8006E294(void *);
extern void lbl_8006D9D8(void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);

/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_table2 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_init_fzgx_pool_table2.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_table4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_init_fzgx_pool_table4.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const union { u32 w[3]; const u32 v[3]; } fzgx_pool_init_fzgx_pool_table6 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0xBF800000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_init_fzgx_pool_table6.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_table8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_init_fzgx_pool_table8.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
    s = 0.6f;
    s = 0.4f;
    s = 255.0f;
    s = 0.8f;
    s = 0.3f;
    s = 1.3f;
    s = 0.70710677f;
}
#pragma section code_type ".text"

void fn_1_FF038(FF038Owner *owner, f32 arg1) {
    s32 i;
    FF038Entry *e;
    f32 width;
    f32 len;
    f32 dist;
    f32 dy;
    f32 dx;
    f32 dz;
    f32 k;
    f32 alpha;
    f32 t;
    f32 cr;
    f32 cg;
    f32 cb;
    FF038Sprite sprite;
    FF038Vec end;
    FF038Vec a;
    FF038Vec b;
    FF038Vec mid;
    s16 rx;
    s16 ry;

    e = owner->entries;
    for (i = 0; i < 100; i++, e++) {
        if (e->count > 0) {
            lbl_8006DCA4();
            width = 22.0f * e->scale;
            if (e->active) {
                len = 15.0f * e->scale / 4.0f;
            } else {
                len = 30.0f * e->scale / 4.0f;
            }
            end.x = e->pos.x - (f32)(e->dir.x * len);
            end.y = e->pos.y - (f32)(e->dir.y * len);
            end.z = e->pos.z - (f32)(e->dir.z * len);
            a = end;
            b = e->pos;
            mid.x = 0.5f * (a.x + b.x);
            mid.y = 0.5f * (a.y + b.y);
            mid.z = 0.5f * (a.z + b.z);
            dx = a.x - b.x;
            dy = a.y - b.y;
            dz = a.z - b.z;
            dist = dx * dx;
            dist = dy * dy + dist;
            dist = dz * dz + dist;
            dist = 0.9 * lbl_8006D0B4(dist);
            if (fn_1_54E34(&mid, dist)) {
                lbl_8006E1B0(&mid, &mid);
                lbl_8006E1B0(&a, &a);
                lbl_8006E1B0(&b, &b);
                fn_8006EDBC(&a, &b, &rx, &ry);
                lbl_8006D7DC(&mid);
                mathutil_mtxA_rotate_y(ry);
                mathutil_mtxA_rotate_x(rx);
                lbl_8006E15C(1.0f, 1.0f, dist / width);
                mathutil_mtxA_rotate_x(0x4000);
                fn_8006E294(&end);
                mathutil_mtxA_rotate_y(lbl_8006D24C(end.x, end.z));
                memset(&sprite, 0, sizeof(sprite));
                lbl_8006DB74(sprite.mtx);
                {
                    f32 rgba[4];
                    t = (u16)fn_1_584AC() / 32767.0f;
                    k = 0.4f * t;
                    k = 0.6f + k;
                    cr = 255.0f * (0.5f * (1.0f + k));
                    cg = 255.0f * (0.8f * k);
                    cb = 255.0f * (0.3f * k);
                    sprite.color[0] = (s32)(cr * e->alpha);
                    sprite.color[1] = (s32)(cg * e->alpha);
                    sprite.color[2] = (s32)(cb * e->alpha);
                    sprite.color[3] = 0xFF;
                    sprite.flags |= 4;
                }
                fn_1_1011CC(0, 1);
                fn_800728A8(1, 4, 1, 0);
                if (e->active) {
                    sprite.unk4 = width;
                    sprite.unk0 = 1.3f * (0.70710677f * width);
                    lbl_8006D758();
                    fn_80073778(owner->unk428->texobj, 0);
                    fn_1_9EDE8(&sprite);
                } else {
                    sprite.unk4 = width;
                    sprite.unk0 = 0.6f * (0.70710677f * width);
                    lbl_8006D758();
                    fn_80073778(owner->unk42C->texobj, 0);
                    fn_1_9EDE8(&sprite);
                }
                lbl_8006DCA4();
                if (e->active) {
                    lbl_8006D9D8(&e->pos);
                    lbl_8006E14C(e->scale);
                    fn_1_55FC4(e->scale);
                    mathutil_mtxA_rotate_y(e->rotY);
                    mathutil_mtxA_rotate_x(e->rotX);
                    fn_80072558();
                    fn_1_55FF0(e->alpha);
                    fn_1_55210(owner->unk424);
                    fn_1_FFA0C(e);
                }
            }
        }
    }
}
/* fzgx:end fn_1_FF038 */

/* fzgx:begin fn_1_FF420 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

/* begin game/main_rel/bg_cas_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

extern void fn_1_FF6B8(CasEmitter *em);

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H

/* end game/main_rel/bg_cas_types.h */

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};

struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;

typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;

typedef u8 Sig_GXInitTexObjLOD_GXBool;

typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FD844_Vec;

typedef struct {
    f32 x, y, z;
} CasVec;

typedef struct {
    CasVec v;
    u8 pad_C[0x34];
} CasMtx;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CasObj;

typedef struct {
    f32 x, y, z;
} CasSparkVec;

typedef struct {
    CasSparkVec pos;
    CasSparkVec base;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} CasSpark;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    u32 unk_10;
    CasSpark sparks[20];
} CasSparkSet;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_1_FC760(void *, void *);
extern void fn_8006F1F0(FD844_Vec *, FD844_Vec *, FD844_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern s32 fn_1_58C4(void);
extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void fn_800736C0(u32, void *);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8();
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(CasEmitter *em);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006E13C(void *);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_FFC60(CasSparkSet *state);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);

/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
}
static const u32 fzgx_pool_table10[8] = {0x3F19999A, 0x3ECCCCCD, 0x437F0000, 0x3F4CCCCD, 0x3E99999A, 0x3FA66666, 0x3F3504F3, 0};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
}
#pragma section code_type ".text"

/* random fraction in [0, 1] */
#define RAND_FRAC() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* velocity jittered by up to 10%; the casts keep retail's separate fmul/fadd */
#define JITTER(v) ((f64)(0.9 * (v)) + (f64)(0.1 * (v) * RAND_FRAC()))

void fn_1_FF420(CasEmitter *em) {
    s32 i;
    CasParticle *p;
    f32 v;

    p = em->particles;
    memset(p, 0, sizeof(em->particles));
    for (i = 0; i < 20; i++, p++) {
        p->life = (s32)(30.0f + (f32)(10.0f * RAND_FRAC()));
        p->pos = em->pos;
        p->prev = em->pos;
        v = em->vel.x;
        p->vel.x = JITTER(v);
        v = em->vel.y;
        p->vel.y = JITTER(v);
        v = em->vel.z;
        p->vel.z = JITTER(v);
        p->rot = fn_1_584AC();
        p->rotVel = (s32)(1280.0 * (RAND_FRAC() - 0.5)) + 512;
        p->scale = 1.0f;
        p->size = 22.0f * em->size;
    }
}
/* fzgx:end fn_1_FF420 */

/* fzgx:begin fn_1_FF6B8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

/* begin game/main_rel/bg_cas_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

extern void fn_1_FF6B8(CasEmitter *em);

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H

/* end game/main_rel/bg_cas_types.h */

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};

struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;

typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;

typedef u8 Sig_GXInitTexObjLOD_GXBool;

typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FD844_Vec;

typedef struct {
    f32 x, y, z;
} CasVec;

typedef struct {
    CasVec v;
    u8 pad_C[0x34];
} CasMtx;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CasObj;

typedef struct {
    f32 x, y, z;
} CasSparkVec;

typedef struct {
    CasSparkVec pos;
    CasSparkVec base;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} CasSpark;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    u32 unk_10;
    CasSpark sparks[20];
} CasSparkSet;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_1_FC760(void *, void *);
extern void fn_8006F1F0(FD844_Vec *, FD844_Vec *, FD844_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern s32 fn_1_58C4(void);
extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void fn_800736C0(u32, void *);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8();
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(CasEmitter *em);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006E13C(void *);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_FFC60(CasSparkSet *state);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);

/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
}
static const u32 fzgx_pool_table10[8] = {0x3F19999A, 0x3ECCCCCD, 0x437F0000, 0x3F4CCCCD, 0x3E99999A, 0x3FA66666, 0x3F3504F3, 0};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
    s = 0.9f;
    d = 0.98;
    s = 20.0f;
}
#pragma section code_type ".text"


       /* 0x34 */


/* random fraction in [0, 1] */
#define RAND_FRAC() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* velocity jittered by up to 10%; the casts keep retail's separate fmul/fadd */
#define JITTER(v) ((f64)(0.9 * (v)) + (f64)(0.1 * (v) * RAND_FRAC()))

void fn_1_FF6B8(CasEmitter *em) {
    s32 i;
    CasParticle *p;
    f32 v;

    p = em->particles;
    for (i = 0; i < 20; i++, p++) {
        if (p->life != 0) {
            p->life--;
        }
        if (p->life <= 0 && em->active > 0) {
            p->life = (s32)(30.0f + (f32)(10.0f * RAND_FRAC()));
            p->pos = em->pos;
            p->prev = em->pos;
            v = em->vel.x;
            p->vel.x = JITTER(v);
            v = em->vel.y;
            p->vel.y = JITTER(v);
            v = em->vel.z;
            p->vel.z = JITTER(v);
            p->rot = fn_1_584AC();
            p->rotVel = (s32)(1280.0 * (RAND_FRAC() - 0.5)) + 512;
            p->scale = 1.0f;
            p->size = 22.0f * em->size;
        }
        p->vel.x *= 0.9f;
        p->vel.y *= 0.9f;
        p->vel.z *= 0.9f;
        p->pos.x += p->vel.x;
        p->pos.y += p->vel.y;
        p->pos.z += p->vel.z;
        p->prev = p->pos;
        p->rot += p->rotVel;
        p->size *= 0.98;
        if (p->life < 20) {
            p->scale *= (f32)p->life / 20.0f;
        }
    }
}
/* fzgx:end fn_1_FF6B8 */

/* fzgx:begin fn_1_FFA0C */
#include "dolphin/hw_regs.h"
#include "psvec.h"

/* begin game/main_rel/bg_cas_types.h (deltawave784-windows-and-types) */
#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H

/* end game/main_rel/bg_cas_types.h */

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
    s = 0.6000000238418579f;
    s = 0.4000000059604645f;
    s = 255.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
    s = 1.2999999523162842f;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.98;
    s = 20.0f;
    s = 0.20000000298023224f;
}
#pragma section code_type ".text"

typedef struct {
    f32 scale;        /* 0x00 */
    f32 size;         /* 0x04 */
    f32 mtx[3][4];    /* 0x08 */
    u32 flags;        /* 0x38 */
    u8 r, g, b, a;    /* 0x3C */
} CasDrawParams;

extern s32 fn_1_54E34(void *, f32);
extern u32 fn_1_584AC(void);
extern void fn_1_1011CC(int, int);
extern void fn_1_9EDE8(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern void mathutil_mtxA_rotate_z(s16);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void *memset(void *, int, u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006D758(void);
extern void fn_80073778(void *, s32);

#define cas_set_color(P, S, A, Z) do { \
    f32 r, g, b; \
    (S) = 0.2f * (S); \
    (S) = 0.8f + (S); \
    r = 0.5f * (1.0f + (S)); \
    g = 0.8f * (S); \
    b = 0.5f * (S); \
    (P)->r = 255.0f * r * (A); \
    (P)->g = 255.0f * g * (A); \
    (P)->b = 255.0f * b * (A); \
    (P)->a = 0xff; \
    (P)->flags |= 4; \
    (P)->size = (Z); \
} while (0)

void fn_1_FFA0C(CasEmitter *em) {
    CasDrawParams params;
    f32 mtx[3][4];
    f32 vec[3];
    u8 *obj;
    CasParticle *p;
    s32 i;
    f32 size;
    f32 dist;
    f32 shade;
    f32 intensity;

    p = em->particles;
    obj = *(u8 **)(lbl_1_bss_38458->unk_8 + 0x168);
    for (i = 0; i < 20; i++, p++) {
        if (p->life > 0) {
            size = p->size;
            lbl_8006DCA4();
            if (fn_1_54E34(&p->pos, size)) {
                lbl_8006D9D8(&p->pos);
                lbl_8006D7B0();
                mathutil_mtxA_rotate_z(p->rot);
                psvec_set(vec, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0xC));
                {
                    f32 x = vec[0];
                    f32 y = vec[1];
                    f32 z = *(f32 *)(LC_BASE + 0x2C);
                    x = x * x;
                    x = y * y + x;
                    x = z * z + x;
                    dist = lbl_8006D0B4(x);
                }
                if (dist > 0.1f + size) {
                    lbl_8006DB74(mtx);
                    lbl_8006D848((dist - size) / dist);
                    lbl_8006DFC4(mtx);
                }
                memset(&params, 0, sizeof(params));
                lbl_8006DB74(params.mtx);
                params.scale = 0.70710677f * size;
                shade = (f32)(u16)fn_1_584AC() / 32767.0f;
                cas_set_color(&params, shade, p->scale, size);
                fn_1_1011CC(0, 1);
                fn_800728A8(1, 4, 1, 0);
                lbl_8006D758();
                fn_80073778(*(void **)(obj + 0x24), 0);
                fn_1_9EDE8(&params);
            }
        }
    }
}
/* fzgx:end fn_1_FFA0C */

/* fzgx:begin fn_1_FFC60 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
    s = 0.6000000238418579f;
    s = 0.4000000059604645f;
    s = 255.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
    s = 1.2999999523162842f;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.98;
    s = 20.0f;
    s = 0.20000000298023224f;
    s = 6.0f;
    s = 0.019999999552965164f;
}
#pragma section code_type ".text"

struct fn_1_FFC60_lbl_1_rodata_76A8 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0xC];
    f32 unk_18;
    u8 pad_1C[0x20];
    f32 unk_3C;
    u8 pad_40[0x40];
    f64 unk_80;
    u8 pad_88[0x70];
    f32 unk_F8;
    f32 unk_FC;
};
extern u32 fn_1_584AC(void);
extern u32 fn_1_58C4(void);

void fn_1_FFC60(void *arg0) {
    s32 v11;
    void *v2;
    f32 v3;
    f32 v4;
    u32 v5;
    f32 v6;
    f32 v7;
    f32 v8;
    u32 v9;
    f32 v0;
    u32 t2;
    s32 t3;
    u32 t4;
    u32 t5;
    if (fn_1_58C4() < 2) {
        *(u32 *)((u8 *)arg0 + 16) = 1;
    } else {
        *(u32 *)((u8 *)arg0 + 16) = 0;
        return;
    }
    v0 = 0.0f;
    *(f32 *)((u8 *)arg0 + 12) = v0;
    v2 = (u8 *)arg0 + 20;
    v3 = 32767.0f;
    v4 = 6.0f;
    v5 = *(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 160);
    v6 = 1.0f;
    v7 = 0.02f;
    v8 = 15.0f;
    *(u32 *)((u8 *)arg0 + 0) = *(u32 *)((u8 *)v5 + 36);
    *(u32 *)((u8 *)arg0 + 4) = *(u32 *)((u8 *)v5 + 36);
    v11 = 20;
    do {
        *(f32 *)((u8 *)v2 + 0) = v4 * ((f32)(u32)((fn_1_584AC()) & 0xFFFF) / v3);
        t2 = fn_1_584AC();
        *(f32 *)((u8 *)v2 + 4) = v4 * ((f32)(u32)(t2 & 0xFFFF) / v3);
        t3 = fn_1_584AC();
        *(f32 *)((u8 *)v2 + 8) = v4 * ((f32)(u32)(t3 & 0xFFFF) / v3);
        {
            struct Copy3 { u32 x, y, z; };
            *(struct Copy3 *)((u8 *)v2 + 12) = *(struct Copy3 *)v2;
        }
        *(f32 *)((u8 *)v2 + 24) = v0;
        *(f32 *)((u8 *)v2 + 28) = v0;
        *(f32 *)((u8 *)v2 + 32) = v0;
        *(f32 *)((u8 *)v2 + 36) = v0;
        *(f32 *)((u8 *)v2 + 44) = v7 * (v6 + (f32)((f32)(u32)(fn_1_584AC() & 0xFFFF) / v3));
        *(f32 *)((u8 *)v2 + 40) = *(f32 *)((u8 *)v2 + 44);
        t5 = fn_1_584AC();
        --v11;
        *(u32 *)((u8 *)v2 + 48) = (s32)(v8 * ((f32)(u32)(t5 & 0xFFFF) / v3));
        v2 = (u8 *)v2 + 52;
    } while (v11 > 0);
}
/* fzgx:end fn_1_FFC60 */

/* fzgx:begin fn_1_FFE7C noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "types.h"

#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CCE8_Vec3;

extern void fn_8006E294(fn_1_9CCE8_Vec3 *);

#endif  // GAME_MAIN_REL_BURNER_TYPES_H
#ifndef GAME_MAIN_REL_CAMERA_TYPES_H
#define GAME_MAIN_REL_CAMERA_TYPES_H

/* begin game/vec3.h (fork-deltawave784/windows-and-types@215f1cd8) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

#endif  // GAME_VEC3_H

typedef struct Transform {
    u8 pad_08[0x8];
    f32 unk_08;
    u8 pad_0c[0xc];
    f32 unk_18;
    u8 pad_1c[0xc];
    f32 unk_28;
    u8 pad_2c[0x24];
    u8 unk_50[0x2c];
    u32 unk_7C;
} Transform;

typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;

extern Transform *lbl_801A6D00;
extern CameraStateLocal *lbl_801A66CC;

#endif  // GAME_MAIN_REL_CAMERA_TYPES_H

/* end game/main_rel/camera_types.h */

struct fn_1_FFE7C_lbl_1_rodata_76A8 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0xC];
    f32 unk_18;
    u8 pad_1C[0x4];
    f64 unk_20;
    u8 pad_28[0x14];
    f32 unk_3C;
    u8 pad_40[0x8];
    f32 unk_48;
    u8 pad_4C[0x14];
    f64 unk_60;
    u8 pad_68[0xC];
    f32 unk_74;
    u8 pad_78[0x8];
    f64 unk_80;
    u8 pad_88[0x4];
    f32 unk_8C;
    u8 pad_90[0x4];
    f32 unk_94;
    u8 pad_98[0x8];
    f32 unk_A0;
    u8 pad_A4[0x10];
    f32 unk_B4;
    u8 pad_B8[0x38];
    f32 unk_F0;
    f32 unk_F4;
    f32 unk_F8;
    f32 unk_FC;
    f32 unk_100;
    f32 unk_104;
    f32 unk_108;
    f32 unk_10C;
    f32 unk_110;
    f32 unk_114;
    f32 unk_118;
    f32 unk_11C;
    f32 unk_120;
};
struct fn_1_FFE7C_lbl_801A6D00 {
    u32 unk_0;
};

extern f32 lbl_8006D0B4(f32);
extern struct fn_1_FFE7C_lbl_1_rodata_76A8 lbl_1_rodata_76A8;
#define lbl_801A6D00 (*(struct fn_1_FFE7C_lbl_801A6D00 *)&lbl_801A6D00)
extern u32 fn_1_1FB80(u32, u32);
extern u32 fn_1_584AC(void);
#define lbl_801A66CC (*(u32 *)&lbl_801A66CC)
extern void fn_1_681C(u32, u32 *);
extern void lbl_8006DBAC(Vec3 *);

/* Shared constant-pool zero and its alignment word. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_zero(volatile f32 *s) {  /* fzgx-allow: S2 volatile keeps the verified access order */
    *s = 0.0f;
}
#pragma section code_type ".text"
#pragma force_active on
static const u32 fzgx_pool_table_4[1] = {0};
#pragma force_active reset

/* Prime the shared compiler literal pool used by neighbouring routines. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(volatile f32 *s, volatile f64 *d) {  /* fzgx-allow: S2 volatile keeps the verified access order */
    *s = 1.0f;
    *s = 6600.0f;
    *s = 110.0f;
    *s = 60.0f;
    *s = 15.0f;
    *d = 4503601774854144.0;
    *d = 0.0;
    *s = -1.0f;
    *s = 100.0f;
    *s = 300.0f;
    *s = 32767.0f;
    *s = 4.0f;
    *s = 10.0f;
    *s = 2.0f;
    *s = 200.0f;
    *s = 400.0f;
    *s = 2500.0f;
    *s = 1000.0f;
    *s = 1400.0f;
    *d = 0.5;
    *d = 5.0;
    *s = 7.0f;
    *s = 2.5f;
    *s = 768.0f;
    *d = 4503599627370496.0;
    *s = 0.1f;
    *s = 0.5f;
    *s = 0.25f;
    *s = 0.05f;
    *s = -2000.0f;
    *s = 1.02f;
    *s = 30.0f;
    *s = 22.0f;
    *d = 0.9;
    *s = 0.6f;
    *s = 0.4f;
    *s = 255.0f;
    *s = 0.8f;
    *s = 0.3f;
    *s = 1.3f;
    *s = 0.70710677f;
    *d = 0.1;
    *d = 1280.0;
    *s = 0.9f;
    *d = 0.98;
    *s = 20.0f;
    *s = 0.2f;
    *s = 6.0f;
    *s = 0.02f;
    *s = 0.15f;
    *s = 1.5f;
    *s = -0.075f;
    *s = -0.1f;
    *s = 180.0f;
    *s = 0.04f;
    *s = 0.0005f;
    *s = -0.15f;
    *s = -0.2f;
}
#pragma section code_type ".text"

static inline f32 fn_1_FFE7C_clamp(f32 value, f32 minimum, f32 maximum) {
    if (value < minimum) return minimum;
    if (value > maximum) return maximum;
    return value;
}

static inline s32 fn_1_FFE7C_less_equal(s32 quota, s32 index) {
    return quota <= index;
}

void fn_1_FFE7C(void * arg0) {
    struct fn_1_FFE7C_lbl_1_rodata_76A8 *p_lbl_1_rodata_76A8;
    f32 v0;
    register f32 dz;
    f32 v1;
    f32 v2;
    f64 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    u32 v7;
    f32 v9;
    f32 v10;
    f64 v11;
    f32 v12;
    s32 v13;
    void * v14;
    s32 v8;
    u32 v15;
    f32 v16;
    f64 v17;
    f32 v18;
    f64 v19;
    f32 v20;
    f64 v21;
    f32 v22;
    u32 v23;
    f32 v24;
    f32 v25;
    f32 v26;
    f32 v27;
    f32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v32;
    f32 v33;
    f32 v34;
    f32 v35;
    f32 v36;
    f32 v37;
    f32 v38;
    u32 v39;
    f32 v40;
    f32 v41;
    f64 v42;
    f32 v43;
    f32 v44;
    f32 v45;
    f32 v46;
    f32 v47;
    f32 v48;
    f32 v49;
    f32 v50;
    f32 v51;
    f32 v52;
    f32 v53;
    f32 v54;
    f32 v55;
    f32 v56;
    f32 v57;
    f32 v58;
    f32 v59;
    f32 v60;
    u32 v61;
    f32 v62;
    f32 v63;
    f32 v64;
    f32 v65;
    f32 v66;
    f32 v67;
    f32 v68;
    f32 v69;
    f32 v70;
    f32 v71;
    f32 v72;
    f32 v73;
    f32 v74;
    f32 v75;
    f32 v76;
    f32 v77;
    f32 v78;
    f64 v79;
    u32 v80;
    f32 v81;
    struct { f32 a[3]; } loc_20;
    fn_1_9CCE8_Vec3 loc_14;
    u32 loc_8[3];
    /* frame */
    f32 t4;
    u32 t6;
    u32 t7;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    f32 t16;
    u32 t17;
    u32 t18;
    u32 t19;
    u32 t20;
    u32 t21;
    u32 t22;
    u32 t23;
    /* 13 instruction(s) not lifted: see the ??? markers */
    p_lbl_1_rodata_76A8 = (struct fn_1_FFE7C_lbl_1_rodata_76A8 *)&lbl_1_rodata_76A8;
    lbl_8006DBAC((Vec3 *)lbl_801A66CC);
    fn_8006E294((fn_1_9CCE8_Vec3 *)&loc_14);
    lbl_8006DBAC((Vec3 *)(lbl_801A6D00.unk_0 + 48));
    fn_8006E294((fn_1_9CCE8_Vec3 *)&loc_20);
    v0 = loc_20.a[0];
    v2 = loc_20.a[1];
    v1 = loc_20.a[2];
    v0 -= loc_14.x;
    v2 -= loc_14.y;
    v1 -= loc_14.z;
    v0 = v0 * v0;
    v0 = v2 * v2 + v0;
    v0 = v1 * v1 + v0;
    t4 = lbl_8006D0B4(v0);
    *(f32 *)((u8 *)arg0 + 8) = t4;
    fn_1_681C(0, (u32 *)loc_8);
    t6 = fn_1_1FB80((u32)loc_8, 4096);
    if (t6 != 0) {
        v6 = 0.0;
    } else {
        v6 = 1.0f;
    }
    v2 = *(f32 *)((u8 *)arg0 + 12);
    v3 = 0.5;
    v4 = 20.0f;
    *(f32 *)((u8 *)arg0 + 12) = (f32)(v2 + (f32)(0.15f * (f32)(v6 - v2)));
    v5 = *(f32 *)((u8 *)arg0 + 8);
    v6 = (f32)(v4 * *(f32 *)((u8 *)arg0 + 12));
    v7 = t6;
    v8 = (s32)(f32)(v4 * *(f32 *)((u8 *)arg0 + 12));
    if (v5 > v3) {
    v9 = 2.0f;
    v6 = 1.5f;
    v10 = (f32)(v5 - v9);
    v6 = fn_1_FFE7C_clamp(v10, v6, v9);
    v11 = 4503601774854144.0;
    v12 = (f32)(1.0f / v6);
    v6 = (f32)(s32)v8;
    v8 = (s32)(f32)(v6 * v12);
    }
    v14 = (void *)(((u8 *)arg0 + 20));
    v13 = 20;
    do {
    /* Skip spawning when the active-particle quota is exhausted. */
    if (fn_1_FFE7C_less_equal(v8, v13)) goto active;
    if ((s32)*(u32 *)((u8 *)v14 + 48) == 0) {
    *(f32 *)((u8 *)v14 + 0) = 6.0f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
    *(f32 *)((u8 *)v14 + 4) = 6.0f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
    *(f32 *)((u8 *)v14 + 8) = 6.0f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
    *(fn_1_9CCE8_Vec3 *)((u8 *)v14 + 12) = *(fn_1_9CCE8_Vec3 *)v14;
    *(f32 *)((u8 *)v14 + 24) = -0.075f + (f32)(0.4f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
    *(f32 *)((u8 *)v14 + 28) = -0.1f + (f32)(0.4f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
    v16 = 0.0f;
    *(f32 *)((u8 *)v14 + 32) = v16 + (f32)(0.4f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
    *(f32 *)((u8 *)v14 + 36) = v16;
    *(f32 *)((u8 *)v14 + 40) = 0.02f * (f32)(1.0f + (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
    *(f32 *)((u8 *)v14 + 44) = 0.02f * (f32)(1.0f + (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
    *(f32 *)((u8 *)v14 + 40) = *(f32 *)((u8 *)v14 + 44);
    *(u32 *)((u8 *)v14 + 48) = (s32)(30.0f + (f32)(180.0f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f)));
    }
active:
    if ((s32)*(u32 *)((u8 *)v14 + 48) > 0) {
    v40 = *(f32 *)((u8 *)v14 + 24);
    v41 = *(f32 *)((u8 *)v14 + 28);
    v38 = *(f32 *)((u8 *)v14 + 32);
    v0 = v40 * v40;
    v0 = v41 * v41 + v0;
    v0 = v38 * v38 + v0;
    t16 = lbl_8006D0B4(v0);
    v38 = (f32)(t16);
    v43 = v38;
    *(f32 *)((u8 *)v14 + 40) = *(f32 *)((u8 *)v14 + 44) * (f32)(1.0f - (f32)((f32)(1.0f / (f32)(1.0f + (f32)(2.5f * v43))) * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f)));
    *(f32 *)((u8 *)v14 + 24) += (f32)(0.04f * (f32)(v43 * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    *(f32 *)((u8 *)v14 + 28) += (f32)(0.04f * (f32)(v43 * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    *(f32 *)((u8 *)v14 + 32) += (f32)(0.04f * (f32)(v43 * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    v52 = 0.04f;
    v38 = -0.2f;
    v55 = (-0.15f);
    v56 = 0.0f;
    v57 = 0.0005f;
    v58 = *(f32 *)((u8 *)v14 + 28);
    *(f32 *)((u8 *)v14 + 28) = (f32)(v58 - v57);
    v59 = *(f32 *)((u8 *)v14 + 24);
    *(f32 *)((u8 *)v14 + 24) = (f32)(v59 + (f32)(v52 * (f32)(v55 - v59)));
    v60 = *(f32 *)((u8 *)v14 + 28);
    v38 = (f32)((f32)(v38 - v60));
    v38 = (f32)((f32)(v52 * v38));
    v38 = (f32)((f32)(v60 + v38));
    *(f32 *)((u8 *)v14 + 28) = v38;
    v38 = (f32)(*(f32 *)((u8 *)v14 + 32));
    *(f32 *)((u8 *)v14 + 32) = (f32)(v38 + (f32)(v52 * (f32)(v56 - v38)));
    *(fn_1_9CCE8_Vec3 *)((u8 *)v14 + 12) = *(fn_1_9CCE8_Vec3 *)v14;
    *(f32 *)((u8 *)v14 + 0) += (f32)(*(f32 *)((u8 *)v14 + 24) + (f32)(0.05f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    *(f32 *)((u8 *)v14 + 4) += (f32)(*(f32 *)((u8 *)v14 + 28) + (f32)(0.05f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    *(f32 *)((u8 *)v14 + 8) += (f32)(*(f32 *)((u8 *)v14 + 32) + (f32)(0.05f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    v70 = 6.0f;
    v71 = 0.0f;
    while (*(f32 *)((u8 *)v14 + 0) < v71) {
        *(f32 *)((u8 *)v14 + 0) += v70;
    }
    while (*(f32 *)((u8 *)v14 + 0) > 6.0f) {
        *(f32 *)((u8 *)v14 + 0) -= 6.0f;
    }
    while (*(f32 *)((u8 *)v14 + 4) < 0.0f) {
        *(f32 *)((u8 *)v14 + 4) += 6.0f;
    }
    while (*(f32 *)((u8 *)v14 + 4) > 6.0f) {
        *(f32 *)((u8 *)v14 + 4) -= 6.0f;
    }
    while (*(f32 *)((u8 *)v14 + 8) < 0.0f) {
        *(f32 *)((u8 *)v14 + 8) += 6.0f;
    }
    while (*(f32 *)((u8 *)v14 + 8) > 6.0f) {
        *(f32 *)((u8 *)v14 + 8) -= 6.0f;
    }
    (*(s32 *)((u8 *)v14 + 48))--;
    v80 = *(u32 *)((u8 *)v14 + 48);
    if ((f32)(s32)v80 < 15.0f) {
    *(f32 *)((u8 *)v14 + 36) *= (f32)(s32)v80 / (f32)(s32)(v80 + 1);
    } else {
    v81 = *(f32 *)((u8 *)v14 + 36);
    v38 = (f32)(0.2f);
    *(f32 *)((u8 *)v14 + 36) = (f32)(v81 + (f32)(v38 * (f32)(1.0f - v81)));
    }
    if ((s32)*(u32 *)((u8 *)v14 + 48) <= 0) {
    *(f32 *)((u8 *)v14 + 36) = 0.0f;
    *(u32 *)((u8 *)v14 + 48) = 0;
    }
    }
    v14 = (u8 *)v14 + 0x34;
    } while (--v13 > 0);
    return;
}

/* fzgx:end fn_1_FFE7C */

/* fzgx:begin fn_1_10069C noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "game/vec3.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "rel/main_rel/globals.h"
#include "dolphin/gx.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
    s = 0.6000000238418579f;
    s = 0.4000000059604645f;
    s = 255.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
    s = 1.2999999523162842f;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.98;
    s = 20.0f;
    s = 0.20000000298023224f;
    s = 6.0f;
    s = 0.019999999552965164f;
    s = 0.15000000596046448f;
    s = 1.5f;
    s = -0.07500000298023224f;
    s = -0.10000000149011612f;
    s = 180.0f;
    s = 0.03999999910593033f;
    s = 0.0005000000237487257f;
    s = -0.15000000596046448f;
    s = -0.20000000298023224f;
    s = 0.04999999701976776f;
    s = -10.0f;
    s = 0.1666666716337204f;
    s = 3.799999952316284f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.1;
    s = 9.0f;
    s = 127.5f;
    s = 25.5f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CCE8_Vec3;

extern void fn_8006E294(fn_1_9CCE8_Vec3 *);

#endif  // GAME_MAIN_REL_BURNER_TYPES_H
#ifndef GAME_MAIN_REL_CAMERA_TYPES_H
#define GAME_MAIN_REL_CAMERA_TYPES_H


typedef struct Transform {
    u8 pad_08[0x8];
    f32 unk_08;
    u8 pad_0c[0xc];
    f32 unk_18;
    u8 pad_1c[0xc];
    f32 unk_28;
    u8 pad_2c[0x24];
    u8 unk_50[0x2c];
    u32 unk_7C;
} Transform;

typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;

extern Transform *lbl_801A6D00;
extern CameraStateLocal *lbl_801A66CC;

#endif  // GAME_MAIN_REL_CAMERA_TYPES_H

/* end game/main_rel/camera_types.h */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@f88123fa) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H

/* end game/main_rel/car_test_types.h */

typedef struct F65Vec { f32 x, y, z; } F65Vec;

typedef struct F65Node {
    F65Vec pos;     /* 0x00 */
    F65Vec unk_C;   /* 0x0C */
    F65Vec prev;    /* 0x18 */
    f32 alpha;      /* 0x24 */
    f32 size;       /* 0x28 */
    f32 unk_2C;
    s32 unk_30;
} F65Node; /* 0x34 */

struct fn_1_10069C_Arg0 {
    void *unk_0;
    u8 pad_4[4];
    f32 unk_8;
    u8 pad_C[8];
    F65Node nodes[20]; /* 0x14 */
};

typedef struct F65Color { u8 r, g, b, a; } F65Color;
typedef struct F65Mtx { f32 m[3][4]; } F65Mtx;

extern f32 lbl_8006D668(void *);
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_54E34(void *, f32);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800720B0(u32);
extern void fn_800736C0(u32, F65Color);
extern s16 lbl_8006D24C(f32, f32);
extern u32 lbl_8006D7DC(void *);
extern u32 lbl_8006DB74(void *);
extern u32 lbl_8006E0C8(void *);
extern void lbl_8006D1BC(s16, f32 *, f32 *);
extern void mathutil_mtxA_rotate_z__fzgx_offset_C(f32, f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
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
extern void lbl_8006DBAC(Vec3 *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E15C(f32, f32, f32);

static inline F65Color F65AssignColor(F65Color *dst, F65Color src) {
    *dst = src;
    return src;
}


/* Eight dummy vertices that flush the previous draw state. */
#define F65_DUMMY_QUADS()                                                   \
    do {                                                                    \
        F65_DUMMY_VTX(); F65_DUMMY_VTX(); F65_DUMMY_VTX(); F65_DUMMY_VTX(); \
        F65_DUMMY_VTX(); F65_DUMMY_VTX(); F65_DUMMY_VTX(); F65_DUMMY_VTX(); \
    } while (0)
#define F65_DUMMY_VTX()                                                     \
    GXWGFifo.f32 = 0.0f;                                                    \
    GXWGFifo.f32 = 0.0f;                                                    \
    GXWGFifo.f32 = -10.0f;                                                  \
    GXWGFifo.f32 = 0.0f;                                                    \
    GXWGFifo.f32 = 0.0f

/* Byte view of the current colour: indexed access keeps &cur.g/&cur.b live. */
#define CUR(i) (((u8 *)&cur)[i])

static inline f32 F65Scale(f32 factor, f32 age) {
    return 1.0f - (f32)((age - 1.0f) * factor);
}

static inline f32 F65SquaredXY(f32 x, f32 y) {
    return x * x + y * y;
}

static inline f32 F65SquareAdd(f32 value, f32 sum) {
    return sum + value * value;
}

static inline f32 F65LengthSq(const F65Vec *v) {
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

static inline f32 F65SquaredYX(f32 y, f32 x) {
    return x * x + y * y;
}

void fn_1_10069C(struct fn_1_10069C_Arg0 *obj) {
#define arg0 effect
    F65Vec quad[4];
    F65Mtx mtxA;
    F65Mtx mtxB;
    F65Mtx mtxC;
    F65Mtx mtxD;
    F65Vec pos;
    F65Vec dir;
    f32 snap[3];
    f32 offset[3];
    F65Color cur;
    F65Color newColor;
    f32 sn;
    f32 cs;
    s32 n;
    F65Node *node;
    s32 k;
    f32 one;
    f32 scale;
    f32 alpha;
    f32 size;
    f32 grow;
    f32 dist;
    f32 ratio;
    f32 width;
    f32 len;
    f32 ex;
    f32 ey;
    struct fn_1_10069C_Arg0 *effect;
    s32 j;
    s32 i;

    effect = obj;
    scale = F65Scale(0.049999997f, arg0->unk_8);
    scale = scale < 0.8f ? 0.8f : scale > 1.0f ? 1.0f : scale;

    fn_80073778(arg0->unk_0, 0);
    fn_800728A8(1, 1, 1, 0);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_80072864(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80072C24(0, 15, 8, 14, 15);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 4, 6, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80073898(0);
    fn_80074788(0);
    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006D758();
    GXLoadPosMtxImm((u32)lbl_801A6D00, 0);

    CUR(0) = 216;
    CUR(1) = 122;
    CUR(2) = 76;
    CUR(3) = 255;
    fn_800736C0(0, cur);
    fn_8003462C(0x90, 0, 8);
    F65_DUMMY_QUADS();

    lbl_8006DBAC((Vec3 *)((u8 *)lbl_801A6D00 + 0x30));
    fn_8006E294((fn_1_9CCE8_Vec3 *)snap);
    if (snap[0] < 0.0f) {
        snap[0] -= 6.0f;
    }
    if (snap[1] < 0.0f) {
        snap[1] -= 6.0f;
    }
    if (snap[2] < 0.0f) {
        snap[2] -= 6.0f;
    }
    snap[0] = 6.0f * (s32)(0.16666667f * snap[0]);
    snap[1] = 6.0f * (s32)(0.16666667f * snap[1]);
    snap[2] = 6.0f * (s32)(0.16666667f * snap[2]);
    lbl_8006E0A4(snap);
    lbl_8006DB74(&mtxA);
    lbl_8006DBAC((Vec3 *)lbl_801A66CC);
    lbl_8006E0A4(snap);
    lbl_8006DB74(&mtxB);

    for (i = -1; i <= 1; i++) {
        offset[2] = 6.0f * i;
        for (j = -1; j <= 1; j++) {
            offset[1] = 6.0f * j;
            for (k = -1; k <= 1; k++) {
                offset[0] = 6.0f * k;
                lbl_8006DBAC((Vec3 *)&mtxA);
                lbl_8006E0A4(offset);
                lbl_8006DB74(&mtxC);
                lbl_8006DBAC((Vec3 *)&mtxB);
                lbl_8006E0A4(offset);
                lbl_8006DB74(&mtxD);

                node = arg0->nodes;
                n = 20;
                do {
                    alpha = node->alpha * scale;
                    /* goto: shared loop-step exit for every rejected node */
                    if (alpha <= 0.0f) {
                        goto next; /* Keep the verified branch to next. */
                    }
                    size = 2.0f * node->size;
                    ratio = (f32)(3.8f * arg0->unk_8) + 1.0f;
                    grow = ratio < 1.0f ? 1.0f : ratio > 20.0f ? 20.0f : ratio;
                    lbl_8006DBAC((Vec3 *)&mtxC);
                    if (fn_1_54E34(node, size * grow) == 0) {
                        goto next; /* goto: loop step */
                    }
                    lbl_8006E1B0((Fn183D28Vec3 *)node, (Fn183D28Vec3 *)&pos);
                    if (pos.z >= -0.1) {
                        goto next; /* goto: loop step */
                    }
                    dist = pos.x * pos.x;
                    dist = F65SquareAdd(pos.y, dist);
                    dist += pos.z * pos.z;
                    dist = lbl_8006D0B4(dist);
                    if (dist > 10.0f) {
                        goto next; /* goto: loop step */
                    }
                    if (dist > 9.0f) {
                        alpha *= 10.0f - dist;
                    } else if (dist < 1.0f) {
                        alpha *= dist;
                    }
                    lbl_8006DBAC((Vec3 *)&mtxD);
                    dir.x = node->pos.x - node->prev.x;
                    dir.y = node->pos.y - node->prev.y;
                    dir.z = node->pos.z - node->prev.z;
                    lbl_8006E1B0((Fn183D28Vec3 *)&dir, (Fn183D28Vec3 *)&dir);
                    if (dir.z >= -0.1) {
                        goto next; /* goto: loop step */
                    }
                    if (dir.z >= -0.1) {
                        goto next; /* goto: loop step */
                    }
                    {
                        f32 left = pos.x - size;
                        f32 bottom = pos.y - size;
                        f32 right = pos.x + size;
                        f32 top = pos.y + size;
                        quad[0].z = pos.z;
                        quad[1].z = pos.z;
                        quad[2].z = pos.z;
                        quad[3].z = pos.z;
                        quad[0].x = left;
                        quad[0].y = bottom;
                        quad[1].x = right;
                        quad[1].y = bottom;
                        quad[2].x = right;
                        quad[2].y = top;
                        quad[3].x = left;
                        quad[3].y = top;
                        dir.x = dir.x * (pos.z / dir.z);
                        dir.y = dir.y * (pos.z / dir.z);
                        dir.z = pos.z;
                        snap[0] = dir.x - pos.x;
                        snap[1] = dir.y - pos.y;
                    }
                    if (0.0f != snap[0] || 0.0f != snap[1]) {
                        snap[2] = 0.0f;
                        len = lbl_8006D668(snap);
                        pos.x -= (f32)(size * snap[0]);
                        pos.y -= (f32)(size * snap[1]);
                        dir.x += (f32)(size * snap[0]);
                        dir.y += (f32)(size * snap[1]);
                        width = 2.0f * size;
                        len += width;
                        lbl_8006D7DC(&pos);
                        lbl_8006D1BC(lbl_8006D24C(snap[1], snap[0]), &sn, &cs);
                        mathutil_mtxA_rotate_z__fzgx_offset_C(sn, cs);
                        lbl_8006E15C(len / width, 1.0f, 1.0f);
                        mathutil_mtxA_rotate_z__fzgx_offset_C(-sn, cs);
                        lbl_8006E0C8(&pos);
                        lbl_8006E1B0((Fn183D28Vec3 *)&quad[0], (Fn183D28Vec3 *)&quad[0]);
                        lbl_8006E1B0((Fn183D28Vec3 *)&quad[1], (Fn183D28Vec3 *)&quad[1]);
                        lbl_8006E1B0((Fn183D28Vec3 *)&quad[2], (Fn183D28Vec3 *)&quad[2]);
                        lbl_8006E1B0((Fn183D28Vec3 *)&quad[3], (Fn183D28Vec3 *)&quad[3]);
                    }
                    newColor.r = 255.0f * alpha;
                    newColor.g = 127.5f * alpha;
                    newColor.b = 25.5f * alpha;
                    if (CUR(0) != newColor.r || CUR(1) != newColor.g || CUR(2) != newColor.b) {
                        newColor.a = 255;
                        fn_800736C0(0, F65AssignColor(&cur, newColor));
                        fn_8003462C(0x90, 0, 8);
                        F65_DUMMY_QUADS();
                    }
                    fn_8003462C(0x80, 0, 4);
                    GXWGFifo.f32 = quad[0].x;
                    GXWGFifo.f32 = quad[0].y;
                    GXWGFifo.f32 = quad[0].z;
                    GXWGFifo.f32 = 0.0f;
                    GXWGFifo.f32 = 0.0f;
                    GXWGFifo.f32 = quad[1].x;
                    GXWGFifo.f32 = quad[1].y;
                    GXWGFifo.f32 = quad[1].z;
                    GXWGFifo.f32 = 1.0f;
                    GXWGFifo.f32 = 0.0f;
                    GXWGFifo.f32 = quad[2].x;
                    GXWGFifo.f32 = quad[2].y;
                    GXWGFifo.f32 = quad[2].z;
                    GXWGFifo.f32 = 1.0f;
                    GXWGFifo.f32 = 1.0f;
                    GXWGFifo.f32 = quad[3].x;
                    GXWGFifo.f32 = quad[3].y;
                    GXWGFifo.f32 = quad[3].z;
                    GXWGFifo.f32 = 0.0f;
                    GXWGFifo.f32 = 1.0f;
                next:
                    node++;
                } while (--n > 0);
            }
        }
    }
}
/* fzgx:end fn_1_10069C */

/* fzgx:begin fn_1_1011CC */
void fn_1_1011CC(int arg0, int arg1) {
    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 0xc);
    fn_80073620(0, 0x1c);
    fn_80073C6C(0);
    if (arg0 != 0) {
        fn_80072C24(0, 0xf, 0xe, 8, 0xf);
    } else {
        fn_80072C24(0, 0xf, 0xf, 0xf, 0xe);
    }
    fn_80072D64(0, 0, 0, 0, 1, 0);
    if (arg1 != 0) {
        fn_80072CC4(0, 7, 6, 4, 7);
    } else {
        fn_80072CC4(0, 7, 7, 7, 6);
    }
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
}
/* fzgx:end fn_1_1011CC */

/* fzgx:begin fn_1_101348 */
#include "rel/main_rel/bg_cas.h"

int fn_1_101348(int index, u32 *value) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    switch (index) {
    case 0:
        obj->unk_424 = *value;
        break;
    case 1:
        obj->unk_428 = *value;
        break;
    case 2:
        obj->unk_42C = *value;
        break;
    default:
        break;
    }

    return 1;
}
/* fzgx:end fn_1_101348 */

/* fzgx:begin fn_1_1013A0 */
struct fn_1_1013A0_Arg1 {
    u32 unk_0;
};

s32 fn_1_1013A0(s32 arg0, struct fn_1_1013A0_Arg1 *arg1) {
    switch (arg0) {
    case 0:
        arg1->unk_0 |= 0x1000000;
        break;
    }

    return 1;
}
/* fzgx:end fn_1_1013A0 */

/* fzgx:begin fn_1_1013C0 */
// fn_1_1013C0: empty in retail (single blr).
void fn_1_1013C0(void) {
}
/* fzgx:end fn_1_1013C0 */

/* fzgx:begin fn_1_1013C4 */
#include "rel/main_rel/bg_cas.h"

void fn_1_1013C4(void) {
    Obj_1_data_2A7E0_At3C *ptr = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508(&lbl_1_data_2A7E0);
    ptr->unk_0 = -1;
}
/* fzgx:end fn_1_1013C4 */

/* fzgx:begin fn_1_101400 */
// fn_1_101400: empty in retail (single blr).
void fn_1_101400(void) {
}
/* fzgx:end fn_1_101400 */

/* fzgx:begin fn_1_101404 */
void fn_1_101404(void) {
    fn_1_9AD54();
}
/* fzgx:end fn_1_101404 */

/* fzgx:begin fn_1_101424 */
// fn_1_101424: empty in retail (single blr).
void fn_1_101424(void) {
}
/* fzgx:end fn_1_101424 */

/* fzgx:begin fn_1_101428 */
void fn_1_101428(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_101428 */

/* fzgx:begin fn_1_101448 */
// fn_1_101448: Empty function (blr only)
void fn_1_101448(void) {
}
/* fzgx:end fn_1_101448 */

/* fzgx:begin fn_1_10144C */
// fn_1_10144C: returns a constant.
int fn_1_10144C(void) {
    return 0;
}
/* fzgx:end fn_1_10144C */

/* fzgx:begin fn_1_101454 */
int fn_1_101454(int arg0, u32 *arg1) {
    Obj_1_data_2A7E0_At3C *entry;
    u8 *cursor;

    entry = lbl_1_data_2A7E0.unk_3C;
    switch (arg0) {
    case 0:
        cursor = (u8 *)lbl_1_bss_3BE0->unk_54;
        entry->unk_0 = 0;
        while (cursor != (u8 *)arg1) {
            entry->unk_0 += 1;
            cursor += 0x40;
        }
        *arg1 |= 1u << 31;
        break;
    default:
        goto done; /* The default case skips the zero-argument body. */
    }
done:
    return 1;
}
/* fzgx:end fn_1_101454 */

/* fzgx:begin fn_1_1014B4 */
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern int sprintf(char *, const char *, ...);
extern u32 fn_1_435C(u32);
extern u32 fn_1_10161C(void);
extern u32 fn_1_1018BC(void);
extern s32 fn_1_3F8C(u8 *, u32 (*)(void), u32, u32);
extern void fn_1_101BC4(void *);
extern void *fn_80071484(u32);
extern void *fn_80070F44(void *, void *);
extern void GXInvalidateTexAll(void);

extern u8 lbl_1_data_3F0C0__fzgx_offset_0[];
extern u8 lbl_1_data_3F0DC__fzgx_offset_0[];
extern u8 lbl_1_data_3F0F8__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_3EFB8[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x23
};
static u32 fzgx_pool_data_lbl_1_data_3EFB8_4[65] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6D5F6675, 0x74320000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1
};
static u32 fzgx_pool_data_lbl_1_data_3F0C0[23] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x82A482CB, 0x82A482CB, 0x8382815B, 0x83682882, 0xBB82A482, 0xB382C882, 0xB5290000, 0x82D482E7,
    0x82F182D4, 0x82E782F1, 0x8382815B, 0x83682850, 0x41443029, 0x0, 0x82AE82E9, 0x82AE82E9,
    0x8382815B, 0x83682850, 0x41443129, 0x0, (u32)lbl_1_data_3F0C0__fzgx_offset_0, (u32)lbl_1_data_3F0DC__fzgx_offset_0, (u32)lbl_1_data_3F0F8__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_1_data_3EFB8_164[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x74657374, 0x5F6D6F64, 0x656C2F25, 0x732F2573, 0x2E74706C, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3EFB8_17C[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x74657374, 0x5F6D6F64, 0x656C2F25, 0x732F2573, 0x2E676D61, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3EFB8_194[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436C6F74, 0x6843616C, 0x63000000
};
static u32 fzgx_pool_data_lbl_1_data_3EFB8_1A0[9] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436C6F74, 0x68446973, 0x70000000, 0x25730000, 0x436C6F74, 0x68205465, 0x7374205B, 0x25735D20,
    0x25640A00
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_3EFB8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3EFB8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3EFB8_4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F0C0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3EFB8_164;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3EFB8_17C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3EFB8_194;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3EFB8_1A0;
}
#pragma section code_type ".text"

void fn_1_1014B4(u32 arg0, u32 arg1) {
    Obj_1_bss_85250 *p = (Obj_1_bss_85250 *)&lbl_1_bss_85250;
    
    char buf[0x108];
    u32 *obj;
    u32 d;
    u32 idx;

    p->unk_4 = 14;
    p->unk_8 = 0;
    p->unk_C = 0;
    p->unk_10 = 0;
    sprintf(buf, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_3EFB8_164)), ((u8 *)fzgx_pool_data_lbl_1_data_3EFB8) + 4, ((u8 *)fzgx_pool_data_lbl_1_data_3EFB8) + 4);
    p->unk_C = (u32)fn_80071484((u32)buf);
    sprintf(buf, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_3EFB8_17C)), ((u8 *)fzgx_pool_data_lbl_1_data_3EFB8) + p->unk_8 * 0x104 + 4, ((u8 *)fzgx_pool_data_lbl_1_data_3EFB8) + p->unk_8 * 0x104 + 4);
    p->unk_10 = fn_80070F44(buf, (void *)p->unk_C);
    GXInvalidateTexAll();
    fn_1_435C(arg0);
    fn_1_3F8C(((u8 *)fzgx_pool_data_lbl_1_data_3EFB8_194), fn_1_10161C, 0, 5);
    fn_1_435C(arg1);
    fn_1_3F8C(((u8 *)fzgx_pool_data_lbl_1_data_3EFB8_1A0), fn_1_1018BC, 0, 5);
    p->unk_14 = 1;
    d = *(u32 *)(((u8 *)fzgx_pool_data_lbl_1_data_3EFB8) + p->unk_8 * 0x104);
    idx = (p->unk_4 + d) % d;
    p->unk_4 = idx;
    obj = *(u32 **)(((u8 *)p->unk_10) + 8) ;
    obj = *(u32 **)((u8 *)obj + idx * 8);
    if (obj != 0 && (obj[1] & 0x10)) {
        fn_1_101BC4(obj);
    }
}
/* fzgx:end fn_1_1014B4 */

/* fzgx:begin fn_1_10161C noprologue */
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x8];
u32 unk_8;
} Obj_1_bss_85250_At10;
typedef struct {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 pad_3[0x1];
u16 unk_4;
u8 pad_6[0x2];
u32 unk_8;
u8 pad_C[0x4];
u32 unk_10;
f32 unk_14;
f32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u32 unk_28;
u32 unk_2C;
u32 unk_30;
f32 unk_34;
f32 unk_38;
f32 unk_3C;
f32 unk_40;
u8 pad_44[0x1];
u8 unk_45;
u8 pad_46[0x12];
f32 unk_58;
} Obj_1_bss_85250_At18;
typedef struct {
u32 unk_0;
u32 unk_4;
f32 unk_8;
} Obj_1_bss_85250_At20;
typedef struct {
u32 unk_0;
u32 unk_4;
u32 unk_8;
u32 unk_C;
Obj_1_bss_85250_At10 *unk_10;
u32 unk_14;
Obj_1_bss_85250_At18 *unk_18;
u32 unk_1C;
Obj_1_bss_85250_At20 *unk_20;
u32 unk_24;
u32 unk_28;
u32 unk_2C;
} Obj_1_bss_85250;
extern Obj_1_bss_85250 lbl_1_bss_85250;


typedef struct {
u16 unk_0;
u16 unk_2;
u8 pad_4[0x4];
u16 unk_8;
u16 unk_A;
u8 pad_C[0x4];
u16 unk_10;
u16 unk_12;
u8 pad_14[0x4];
} Obj_1_bss_D58;
extern Obj_1_bss_D58 lbl_1_bss_D58;


typedef struct {
f32 x, y, z;
} CasVec;
typedef struct {
CasVec v;
u8 pad_C[0x34];
} CasMtx;
typedef struct {
u32 unk_0;
u32 unk_4;
} CasObj;


extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);


typedef struct {
u8 pad_0[0x8];
CasObj **unk_8;
} CasTable;
typedef struct {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 pad_3;
u16 unk_4[6];
CasVec unk_10;
u8 pad_1C[0xC];
CasVec unk_28;
CasVec unk_34;
u8 pad_40[0x4];
} fn_1_10161C_CasEntry;
typedef struct {
u32 unk_0;
u32 unk_4;
u32 unk_8;
u32 unk_C;
CasTable *unk_10;
s32 unk_14;
fn_1_10161C_CasEntry *unk_18;
u32 unk_1C;
} CasState;
typedef struct {
u8 pad_0[0x8];
u16 unk_8;
} CasInput;
void fn_1_10161C(void) {
CasState *st = &(*((CasState *)&lbl_1_bss_85250));
CasObj *obj;
CasMtx *mtx;
obj = st->unk_10->unk_8[st->unk_4 * 2];
if (obj == ((void *)0) ) {
return;
}
mtx = fn_80077B14(obj);
if (((*((CasInput *)&lbl_1_bss_D58)).unk_8 >> 4) & 1) {
st->unk_0 ^= 1;
}
if (((*((CasInput *)&lbl_1_bss_D58)).unk_8 >> 3) & 1) {
st->unk_14 = ((u32)st->unk_14 + 4) % 3;
if (obj->unk_4 & 0x10) {
u32 i;
u32 j;
for (i = 0; i < st->unk_1C; i++) {
st->unk_18[i].unk_10 = st->unk_18[i].unk_28;
for (j = 0; j < st->unk_18[i].unk_2; j++) {
mtx[st->unk_18[i].unk_4[j]].v = st->unk_18[i].unk_10;
}
st->unk_18[i].unk_34 = lbl_1_rodata_77F8;
}
}
} else if (((*((CasInput *)&lbl_1_bss_D58)).unk_8 >> 2) & 1) {
st->unk_14 = ((u32)st->unk_14 + 2) % 3;
if (obj->unk_4 & 0x10) {
u32 i;
u32 j;
for (i = 0; i < st->unk_1C; i++) {
st->unk_18[i].unk_10 = st->unk_18[i].unk_28;
for (j = 0; j < st->unk_18[i].unk_2; j++) {
mtx[st->unk_18[i].unk_4[j]].v = st->unk_18[i].unk_10;
}
st->unk_18[i].unk_34 = lbl_1_rodata_7804;
}
}
}
if (obj->unk_4 & 0x10) {
switch (st->unk_14) {
case 0:
default:
fn_1_1024F8();
break;
case 1:
fn_1_102750();
break;
case 2:
fn_1_102C08();
break;
}
}
}
/* fzgx:end fn_1_10161C */

/* fzgx:begin fn_1_1018BC */
typedef struct {
    u32 unk_0;
    char unk_4[0x100];
} fn_1_1018BC_Entry;

typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
} fn_1_1018BC_Model;

typedef struct {
    f32 x, y, z;
} fn_1_1018BC_Vec;

typedef struct {
    u8 unk_0;
    u8 pad_1[0xF];
    fn_1_1018BC_Vec unk_10;
} fn_1_1018BC_Node;

typedef struct {
    fn_1_1018BC_Node *unk_0;
    fn_1_1018BC_Node *unk_4;
    u8 pad_8[0x10];
} fn_1_1018BC_Edge;

typedef struct {
    u8 pad_0[0x8];
    fn_1_1018BC_Model **unk_8;
} fn_1_1018BC_Table;

/* lbl_1_bss_85250 seen from here: bg_cas.h types unk_20 as 0xC-byte records, but this function walks it in
 * 0x18-byte steps (two node pointers each) */
typedef struct {
    s32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    fn_1_1018BC_Table *unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    fn_1_1018BC_Edge *unk_20;
    u32 unk_24;
} fn_1_1018BC_State;

typedef struct {
    u8 r, g, b, a;
} fn_1_1018BC_Color;

typedef struct {
    fn_1_1018BC_Vec unk_0;
    fn_1_1018BC_Color unk_C;
} fn_1_1018BC_Vertex;

typedef struct {
    u8 pad_0[0x10];
    u8 unk_10[0x30];
} fn_1_1018BC_Camera;

typedef struct {
    u8 pad_0[0x20];
    void *unk_20;
} fn_1_1018BC_Models;

typedef struct {
    u8 pad_0[0x8];
    fn_1_1018BC_Models *unk_8;
} fn_1_1018BC_Library;

extern fn_1_1018BC_Library *lbl_1_bss_38454;
extern fn_1_1018BC_Camera *camera_get_state_object(void);
extern void fn_80077B14(fn_1_1018BC_Model *);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8EB0(int, int);
extern void fn_1_A8DD4(const char *, ...);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern void fn_1_556B8(void *);
extern void fn_1_57714(u8);
extern void fn_1_57720(u32, u32, u32, u32);
extern void fn_1_57BBC(fn_1_1018BC_Vertex *, fn_1_1018BC_Vertex *);

/* the TU's .data from lbl_1_data_3EFB8, at retail offsets, so MWCC addresses it off one section base: the
 * model entry, the three mode names and their table at +0x158, then this function's two formats at +0x1AC and
 * +0x1B0; the gap objects stand for the retail data in between, which this function does not touch */
fn_1_1018BC_Entry fzgx_obj_lbl_1_data_3EFB8[1] = { { 0x23, "m_fut2" } };
u32 fzgx_pool_gap_104 = 1;
/* the cloth test's three mode names, in Shift-JIS: "uneune (wavy) mode (no control)",
 * "buranburan (dangling) mode (PAD0)", "guruguru (spinning) mode (PAD1)" */
char *fzgx_pool_data_158[3] = {
    "\x82\xa4\x82\xcb\x82\xa4\x82\xcb\x83\x82\x81[\x83h(\x82\xbb\x82\xa4\x82\xb3\x82\xc8\x82\xb5)",
    "\x82\xd4\x82\xe7\x82\xf1\x82\xd4\x82\xe7\x82\xf1\x83\x82\x81[\x83h(PAD0)",
    "\x82\xae\x82\xe9\x82\xae\x82\xe9\x83\x82\x81[\x83h(PAD1)",
};
u32 fzgx_pool_gap_164[0x12] = { 1 };

/* the TU's two zero vectors at lbl_1_rodata_77F8 and 0x7804, ahead of this function's constants */
const f32 fzgx_pool_rodata_77F8[6] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

/* this function's line colours: retail keeps a red/green pair for each end of the line (.rodata 0x7810) */
const fn_1_1018BC_Color fzgx_pool_rodata_7810 = { 0xFF, 0x00, 0x00, 0xFF };
const fn_1_1018BC_Color fzgx_pool_rodata_7814 = { 0x00, 0xFF, 0x00, 0xFF };
const fn_1_1018BC_Color fzgx_pool_rodata_7818 = { 0xFF, 0x00, 0x00, 0xFF };
const fn_1_1018BC_Color fzgx_pool_rodata_781C = { 0x00, 0xFF, 0x00, 0xFF };

/* ClothDisp, the draw task fn_1_1014B4 registers under that name: draws the selected cloth model, then a line
 * per edge between its nodes, red or green by bit 0 of each node's first byte */
/* without this, MWCC colours the section bases and the camera pointer in a different order */
#pragma opt_common_subs off
void fn_1_1018BC(void) {
    fn_1_1018BC_State *st = (fn_1_1018BC_State *)&lbl_1_bss_85250;
    fn_1_1018BC_Camera *cam;
    fn_1_1018BC_Table *table;
    fn_1_1018BC_Model *model;
    fn_1_1018BC_Vertex v[2];
    u32 i;

    cam = camera_get_state_object();
    table = st->unk_10;
    if (table == NULL) {
        return;
    }
    if ((lbl_1_bss_D58.unk_8 & 1) || ((lbl_1_bss_D58.unk_8 >> 1) & 1)) {
        return;
    }
    model = table->unk_8[st->unk_4 * 2];
    if (model == NULL) {
        return;
    }
    fn_80077B14(model);
    fn_1_49410();
    fn_1_496FC(20.0f, 50.0f);
    fn_1_4AE0C("%s", fzgx_pool_data_158[st->unk_14]);
    fn_1_A8EB0(3, 3);
    fn_1_A8DD4("Cloth Test [%s] %d\n", fzgx_obj_lbl_1_data_3EFB8[st->unk_8].unk_4, st->unk_4);
    lbl_8006DCA4();
    lbl_8006E0A4(cam->unk_10);
    lbl_8006E14C(0.5f);
    fn_80072558();
    fn_1_556B8(lbl_1_bss_38454->unk_8->unk_20);
    lbl_8006DCA4();
    fn_80072558();
    fn_1_556B8(model);
    if (!(model->unk_4 & 0x10)) {
        return;
    }
    if (st->unk_0 == 0) {
        return;
    }
    fn_1_57714(0xC);
    fn_1_57720(1, 1, 1, 0);
    lbl_8006DCA4();
    lbl_8006E14C(0.9999f);
    fn_80072558();
    for (i = 0; i < st->unk_24; i++) {
        v[0].unk_0 = st->unk_20[i].unk_0->unk_10;
        if (st->unk_20[i].unk_0->unk_0 & 1) {
            v[0].unk_C = fzgx_pool_rodata_7810;
        } else {
            v[0].unk_C = fzgx_pool_rodata_7814;
        }
        v[1].unk_0 = st->unk_20[i].unk_4->unk_10;
        if (st->unk_20[i].unk_4->unk_0 & 1) {
            v[1].unk_C = fzgx_pool_rodata_7818;
        } else {
            v[1].unk_C = fzgx_pool_rodata_781C;
        }
        fn_1_57BBC(&v[0], &v[1]);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_1018BC */
