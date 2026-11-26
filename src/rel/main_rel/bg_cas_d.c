#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/bg_cas.h"





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

void fn_1_FA89C(SplineMain *arg0);

Obj_1_bss_84428 lbl_1_bss_84428;

Obj_1_data_3EED0 lbl_1_data_3EED0 = {
    0x00U,
    0x01U,
    0x03U,
    0x02U,
    {0x3FU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x04U, 0x05U, 0x01U, 0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x02U, 0x06U, 0x04U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x04U, 0x06U, 0x07U, 0x05U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x02U, 0x03U, 0x07U, 0x06U, 0x00U, 0x00U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x01U, 0x05U, 0x07U, 0x03U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U}
};

Obj_1_data_3EF30 lbl_1_data_3EF30 = {
    0x3F800000U,
    0x3F800000U,
    0x3F800000U,
    {0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U}
};

/* fzgx:begin fn_1_FE5E0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "game/vec3.h"
#include "dolphin/hw_regs.h"
#include "dolphin/gx.h"
#include "psvec.h"
#include "lc_mtx.h"

extern void *lbl_801A66CC;
extern void *lbl_801A6D00;
extern void DCFlushRange(void *, u32);
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_1011CC(int, int);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern u32 fn_1_1FB80(void *, u32);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_55210(void *);
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern u32 fn_1_584AC(void);
extern s32 fn_1_58C4(void);
extern void fn_1_681C(u32, void *);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F1E8();
extern void fn_1_7F20C(void *, s32, f32);
extern void fn_1_7F230(void *, s32, f32);
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_9A7A8(void *);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_9EDE8(void *);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern void fn_1_FC60C(void);
extern void fn_1_FC760(void *, void *);
extern void fn_1_FCA10(void);
extern u32 fn_1_FCF50(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_800371F8(u32, void *);
extern void fn_8006E294(void *);
extern void fn_8006EDBC(void *, void *, s16 *, s16 *);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(int);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(int, int, int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073678(int);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_80074660(int);
extern void fn_80074788(int);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(int, int, int);
extern u8 lbl_1_bss_850E0[256];
extern u8 lbl_1_bss_851E0[36];
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern const f64 lbl_1_rodata_760C;
extern f32 lbl_1_rodata_761C[13];
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D1BC(s32, f32 *, f32 *);
extern s32 lbl_8006D24C(f32, f32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006D758(void);
extern void lbl_8006D7B0(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006D8D8(s16 angle);
extern void lbl_8006D9D8(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *);
extern u32 lbl_8006E0C8(void *);
extern void lbl_8006E13C(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_z_s_c(f32, f32);
extern void *memset(void *, int, u32);
extern void fn_8006F1F0(void *, void *, void *);

void fn_1_FE7D8(u8 *arg0, s32 arg1);
void fn_1_FEC7C(void *object);
void fn_1_FED34(void *arg0);
void fn_1_FF038(void *owner_raw);
void fn_1_FF420(void *em_raw);
void fn_1_FF6B8(void *em_raw);
void fn_1_FFA0C(void *em_raw);
void fn_1_FFC60(void *arg0);
void fn_1_FFE7C(void *arg0);
void fn_1_10069C(void *obj_raw);

// fn_1_FE5E0: No-op return
void fn_1_FE5E0(void) {
    return;
}
/* fzgx:end fn_1_FE5E0 */

/* fzgx:begin fn_1_FE5E4 noprologue */
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
    obj->unk_430 = 0.0f;
}
/* fzgx:end fn_1_FE5E4 */

/* fzgx:begin fn_1_FE640 noprologue */
// fn_1_FE640: empty in retail (single blr).
void fn_1_FE640(void) {
}
/* fzgx:end fn_1_FE640 */

/* fzgx:begin fn_1_FE644 noprologue */
#define BG_CAS_CLAMP(lo, hi, v) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))
typedef struct {
    u8 pad_0[0x1B1E4];
    s16 unk_1B1E4;
} Obj_1_FE644_Ext;

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
    Obj_1_FE644_Ext *ext;
    u32 *fzgx_value;
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_FE644_Out out;
    struct { f32 value; } f;

    obj = lbl_1_data_2A7E0.unk_3C;
    ext = (Obj_1_FE644_Ext *)obj;
    fn_1_9AD54();
    if ((s32)obj->unk_10 != 0) {
        fn_1_FFE7C(obj);
    }
    fn_1_FED34(obj);
    f.value = 0.0f;
    if (ext->unk_1B1E4 < 0x1E78) {
        ext->unk_1B1E4++;
    }
    if (ext->unk_1B1E4 > 0x4B0) {
        f.value = BG_CAS_CLAMP(0.0f, 1.0f, (s16)(ext->unk_1B1E4 - 0x4B0) / 6600.0f);
    }
    { Obj_1_FE644_Pack zero = {0}; out.unk_0 = zero; }
    out.unk_0.unk_4.unk_0 = (110.0f * f.value);
    out.unk_0.unk_4.unk_1 = (60.0f * f.value);
    out.unk_0.unk_4.unk_2 = (15.0f * f.value);
    fzgx_value = &out.unk_4;
    *fzgx_value = out.unk_0.unk_0;
    fn_1_9A7A8(&out.unk_4);
}
/* fzgx:end fn_1_FE644 */

/* fzgx:begin fn_1_FE780 noprologue */
// fn_1_FE780: Empty return
void fn_1_FE780(void) {
}
/* fzgx:end fn_1_FE780 */

/* fzgx:begin fn_1_FE784 noprologue */
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

/* fzgx:begin fn_1_FE7D4 noprologue */
// fn_1_FE7D4: empty in retail (single blr).
void fn_1_FE7D4(void) {
}
/* fzgx:end fn_1_FE7D4 */

/* fzgx:begin fn_1_FE7D8 noprologue */
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
/* uniform random value in [0, 1] */
#define RANDF() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */

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
        lbl_8006D5F0(&d, &p->vel, (e->unk_E >> 7) * (15.0f + 4.0f * RANDF()) / 10.0f);
        p->size = 2.0f + 2.0f * RANDF();
        p->size *= (e->unk_C >> 7) / 10.0f;
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

/* fzgx:begin fn_1_FEC7C noprologue */
void fn_1_FEC7C(void *object) {
    s32 count;
    s32 index;
    u8 *entry;

    entry = (u8 *)object + 0x434;
    memset(entry, 0, 0x1ADB0);
    index = 0;
    while (index < (count = lbl_1_bss_3BE0->unk_A4)) {
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
static inline f32 fn_1_FED34_operand(f32 right, f32 left) { return left + right; }
void fn_1_FED34(void *arg0) {
    u8 sp8[16];
    s32 var_r30;
    s32 var_r29;
    u8 *var_r28;
    u32 temp_r3;
    f32 var_f31;
    f32 var_f0;
    f32 temp_delta;
    f32 temp_f1;
    f32 temp_f3;

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
    var_r29 = (temp_f1 * *(f32 *)((u8 *)arg0 + 0x430));
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
/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */

void fn_1_FF038(void *owner_raw) {
    FF038Owner *owner = (FF038Owner *)owner_raw;
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
                    k = 0.6f + (f32)(0.4f * ((u16)fn_1_584AC() / 32767.0f));
                    cr = 255.0f * (0.5f * (1.0f + k));
                    cg = 255.0f * (0.8f * k);
                    cb = 255.0f * (0.3f * k);
                    sprite.color[0] = (cr * e->alpha);
                    sprite.color[1] = (cg * e->alpha);
                    sprite.color[2] = (cb * e->alpha);
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
/* Literal pool of the retail TU (lbl_1_rodata_76A8): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */

/* random fraction in [0, 1] */
#define RAND_FRAC() ((f32)(u16)fn_1_584AC() / 32767.0f)

/* velocity jittered by up to 10%; the casts keep retail's separate fmul/fadd */
#define JITTER(v) ((f64)(0.9 * (v)) + (f64)(0.1 * (v) * RAND_FRAC()))

void fn_1_FF420(void *em_raw) {
    CasEmitter *em = (CasEmitter *)em_raw;
    s32 i;
    CasParticle *p;
    f32 v;

    p = em->particles;
    memset(p, 0, sizeof(em->particles));
    for (i = 0; i < 20; i++, p++) {
        p->life = (30.0f + (f32)(10.0f * RAND_FRAC()));
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
void fn_1_FF6B8(void *em_raw) {
    CasEmitter *em = (CasEmitter *)em_raw;
    s32 i;
    CasParticle *p;
    f32 v;

    p = em->particles;
    for (i = 0; i < 20; i++, p++) {
        if (p->life != 0) {
            p->life--;
        }
        if (p->life <= 0 && em->active > 0) {
            p->life = (30.0f + (f32)(10.0f * RAND_FRAC()));
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
            p->scale *= p->life / 20.0f;
        }
    }
}
/* fzgx:end fn_1_FF6B8 */

/* fzgx:begin fn_1_FFA0C noprologue */
typedef struct {
    f32 scale;        /* 0x00 */
    f32 size;         /* 0x04 */
    f32 mtx[3][4];    /* 0x08 */
    u32 flags;        /* 0x38 */
    u8 r, g, b, a;    /* 0x3C */
} CasDrawParams;
#define cas_set_color(P, S, A, Z) do { \
    f32 r, g, b; \
    S = 0.2f * S; \
    S = 0.8f + S; \
    r = 0.5f * (1.0f + S); \
    g = 0.8f * S; \
    b = 0.5f * S; \
    (P)->r = 255.0f * r * A; \
    (P)->g = 255.0f * g * A; \
    (P)->b = 255.0f * b * A; \
    (P)->a = 0xff; \
    (P)->flags |= 4; \
    (P)->size = Z; \
} while (0)

void fn_1_FFA0C(void *em_raw) {
    CasEmitter *em = (CasEmitter *)em_raw;
    CasDrawParams params;
    f32 mtx[3][4];
    f32 vec[3];
    u8 *obj;
    CasParticle *p;
    s32 i;
    f32 size;
    f32 dist;
    f32 shade;

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
                shade = (u16)fn_1_584AC() / 32767.0f;
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
void fn_1_FFC60(void *arg0) {
    s32 v11;
    void *v2;
    f32 v3;
    f32 v4;
    u32 v5;
    f32 v6;
    f32 v7;
    f32 v8;
    f32 v0;
    u32 t2;
    s32 t3;
    u32 t5;
    if ((u32)fn_1_58C4() < 2) {
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
    v5 = *(u32 *)(lbl_1_bss_38458->unk_8 + 160);
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
#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CCE8_Vec3;
#endif  // GAME_MAIN_REL_BURNER_TYPES_H
#ifndef GAME_MAIN_REL_CAMERA_TYPES_H
#define GAME_MAIN_REL_CAMERA_TYPES_H

/* begin game/vec3.h (fork-deltawave784/windows-and-types@215f1cd8) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).

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
#define lbl_801A6D00 (*(struct fn_1_FFE7C_lbl_801A6D00 *)&lbl_801A6D00)
#define lbl_801A66CC (*(u32 *)&lbl_801A66CC)
/* Shared constant-pool zero and its alignment word. */

#pragma force_active on
#pragma force_active reset

/* Prime the shared compiler literal pool used by neighbouring routines. */

static inline f32 fn_1_FFE7C_clamp(f32 value, f32 minimum, f32 maximum) {
    if (value < minimum) return minimum;
    if (value > maximum) return maximum;
    return value;
}

static inline s32 fn_1_FFE7C_less_equal(s32 quota, s32 index) {
    return quota <= index;
}

void fn_1_FFE7C(void * arg0) {
    f32 v0;
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
    f32 v16;
    f32 v38;
    f32 v40;
    f32 v41;
    f32 v43;
    f32 v52;
    f32 v55;
    f32 v56;
    f32 v57;
    f32 v58;
    f32 v59;
    f32 v60;
    f32 v70;
    f32 v71;
    u32 v80;
    f32 v81;
    struct { f32 a[3]; } loc_20;
    fn_1_9CCE8_Vec3 loc_14;
    u32 loc_8[3];
    /* frame */
    f32 t4;
    u32 t6;
    f32 t16;
    /* 13 instruction(s) not lifted: see the ??? markers */

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
    fn_1_681C(0, loc_8);
    t6 = fn_1_1FB80(loc_8, 4096);
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
    v6 = (v4 * *((u8 *)arg0 + 12));
    v7 = t6;
    v8 = (v4 * *(f32 *)((u8 *)arg0 + 12));
    if (v5 > v3) {
    v9 = 2.0f;
    v6 = 1.5f;
    v10 = (v5 - v9);
    v6 = fn_1_FFE7C_clamp(v10, v6, v9);
    v11 = 4503601774854144.0;
    v12 = (1.0f / v6);
    v6 = v8;
    v8 = (v6 * v12);
    }
    v14 = (((u8 *)arg0 + 20));
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
    v38 = (f32)((v38 - v60));
    v38 = ((v52 * v38));
    v38 = ((v60 + v38));
    *(f32 *)((u8 *)v14 + 28) = v38;
    v38 = (*(f32 *)((u8 *)v14 + 32));
    *(f32 *)((u8 *)v14 + 32) = (f32)(v38 + (f32)(v52 * (f32)(v56 - v38)));
    *(fn_1_9CCE8_Vec3 *)((u8 *)v14 + 12) = *(fn_1_9CCE8_Vec3 *)v14;
    *(f32 *)((u8 *)v14 + 0) += (f32)(*(f32 *)((u8 *)v14 + 24) + (f32)(0.05f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    *(f32 *)((u8 *)v14 + 4) += (f32)(*(f32 *)((u8 *)v14 + 28) + (f32)(0.05f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    *(f32 *)((u8 *)v14 + 8) += (f32)(*(f32 *)((u8 *)v14 + 32) + (f32)(0.05f * (f32)((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
    v70 = 6.0f;
    v71 = 0.0f;
    while (*(f32 *)(v14) < v71) {
        *(f32 *)((u8 *)v14 + 0) += v70;
    }
    while (*(f32 *)(v14) > 6.0f) {
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
    if ((s32)v80 < 15.0f) {
    *(f32 *)((u8 *)v14 + 36) *= (f32)(s32)v80 / (f32)(s32)(v80 + 1);
    } else {
    v81 = *(f32 *)((u8 *)v14 + 36);
    v38 = (0.2f);
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

#undef lbl_801A6D00
#undef lbl_801A66CC
/* fzgx:end fn_1_FFE7C */

/* fzgx:begin fn_1_10069C noprologue */
#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CCE8_Vec3;
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

static inline f32 F65SquareAdd(f32 value, f32 sum) {
    return sum + value * value;
}
extern void fn_800736C0(u32, F65Color);
void fn_1_10069C(void *obj_raw) {
    struct fn_1_10069C_Arg0 *obj = (struct fn_1_10069C_Arg0 *)obj_raw;
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
    f32 scale;
    f32 alpha;
    f32 size;
    f32 grow;
    f32 dist;
    f32 ratio;
    f32 width;
    f32 len;
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
                        mathutil_mtxA_rotate_z_s_c(sn, cs);
                        lbl_8006E15C(len / width, 1.0f, 1.0f);
                        mathutil_mtxA_rotate_z_s_c(-sn, cs);
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

/* fzgx:begin fn_1_1011CC noprologue */
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

/* fzgx:begin fn_1_101348 noprologue */
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

/* fzgx:begin fn_1_1013A0 noprologue */
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

/* fzgx:begin fn_1_1013C0 noprologue */
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

// fn_1_1013C0: empty in retail (single blr).
void fn_1_1013C0(void) {
}
/* fzgx:end fn_1_1013C0 */

/* fzgx:begin fn_1_1013C4 noprologue */
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

#include "rel/main_rel/bg_cas.h"

void fn_1_1013C4(void) {
    Obj_1_data_2A7E0_At3C *ptr = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508(&lbl_1_data_2A7E0);
    ptr->unk_0 = -1;
}
/* fzgx:end fn_1_1013C4 */

/* fzgx:begin fn_1_101400 noprologue */
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

// fn_1_101400: empty in retail (single blr).
void fn_1_101400(void) {
}
/* fzgx:end fn_1_101400 */

/* fzgx:begin fn_1_101404 noprologue */
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

void fn_1_101404(void) {
    fn_1_9AD54();
}
/* fzgx:end fn_1_101404 */

/* fzgx:begin fn_1_101424 noprologue */
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

// fn_1_101424: empty in retail (single blr).
void fn_1_101424(void) {
}
/* fzgx:end fn_1_101424 */

/* fzgx:begin fn_1_101428 noprologue */
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

void fn_1_101428(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_101428 */

/* fzgx:begin fn_1_101448 noprologue */
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

// fn_1_101448: Empty function (blr only)
void fn_1_101448(void) {
}
/* fzgx:end fn_1_101448 */

/* fzgx:begin fn_1_10144C noprologue */
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

// fn_1_10144C: returns a constant.
int fn_1_10144C(void) {
    return 0;
}
/* fzgx:end fn_1_10144C */

/* fzgx:begin fn_1_101454 noprologue */
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

/* fzgx:begin fn_1_1014B4 noprologue */
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

/* fzgx:begin fn_1_1018BC noprologue */
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
