#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void fn_1_A71CC(void);
extern void fn_800724C8(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800720B0(int);
extern void fn_80072864(u32 arg0);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);
extern int fn_1_159588(int arg);
extern void OSReport(const char *format, ...);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 *lbl_801A66CC;
extern void lbl_8006DB74(void *value);
extern void fn_1_4E500(void);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern const f32 lbl_1_rodata_2750;
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern f64 lbl_1_rodata_2778[2];
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_80038F10(f32* out);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f32 lbl_1_rodata_2770;
extern const f32 lbl_1_rodata_276C;
extern const f32 lbl_1_rodata_2754;
extern void lbl_8006D7F4(f32 arg0, f32 arg1, f32 arg2);
extern void lbl_8006E15C(f32 arg0, f32 arg1, f32 arg2);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern void lbl_8006DD7C(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern f32 lbl_8006D188(s16);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern u32 lbl_801A66B4;
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;

/* fzgx:begin fn_1_4DCD0 */
// Returns the address of the font data embedded in the global object.
u8 *fn_1_4DCD0(void) {
    return (u8 *)&lbl_1_bss_4C688.unk_C;
}
/* fzgx:end fn_1_4DCD0 */

/* fzgx:begin fn_1_4DCE0 */
u8 *fn_1_4DCE0(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x10;
}
/* fzgx:end fn_1_4DCE0 */

/* fzgx:begin fn_1_4DCF0 */
u8 *fn_1_4DCF0(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x14;
}
/* fzgx:end fn_1_4DCF0 */

/* fzgx:begin fn_1_4DD00 */
u8 *fn_1_4DD00(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x18;
}
/* fzgx:end fn_1_4DD00 */

/* fzgx:begin fn_1_4DD10 */
u8 *fn_1_4DD10(void) {
    return &lbl_1_bss_4C688.pad_10[0xc];
}
/* fzgx:end fn_1_4DD10 */

/* fzgx:begin fn_1_4DD20 */
u8 *fn_1_4DD20(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x30;
}
/* fzgx:end fn_1_4DD20 */

/* fzgx:begin fn_1_4DD30 */
u8 *fn_1_4DD30(void) {
    return &lbl_1_bss_4C688.pad_4[0x30];
}
/* fzgx:end fn_1_4DD30 */

/* fzgx:begin fn_1_4DD40 */
u8 *fn_1_4DD40(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x40;
}
/* fzgx:end fn_1_4DD40 */

/* fzgx:begin fn_1_4DD50 */
u8 *fn_1_4DD50(void) {
    // Return the byte address used by the font data at offset 0x41.
    return &lbl_1_bss_4C688.pad_4[0x3d];
}
/* fzgx:end fn_1_4DD50 */

/* fzgx:begin fn_1_4DD60 */
u8 *fn_1_4DD60(void) {
    return &lbl_1_bss_4C688.pad_4[0x3e];
}
/* fzgx:end fn_1_4DD60 */

/* fzgx:begin fn_1_4DD70 */
u8 *fn_1_4DD70(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x44;
}
/* fzgx:end fn_1_4DD70 */

/* fzgx:begin fn_1_4DD80 */
u8 *fn_1_4DD80(void) {
    return &lbl_1_bss_4C688.pad_4[0x41];
}
/* fzgx:end fn_1_4DD80 */

/* fzgx:begin fn_1_4DD90 */
u8 *fn_1_4DD90(void) {
    return &lbl_1_bss_4C688.pad_4[0x42];
}
/* fzgx:end fn_1_4DD90 */

/* fzgx:begin fn_1_4DDA0 */
 // Return the byte address six bytes into the shared font state.
u8 *fn_1_4DDA0(void) {
    return &lbl_1_bss_4C688.pad_4[2];
}
/* fzgx:end fn_1_4DDA0 */

/* fzgx:begin fn_1_4DDB0 */
u8 *fn_1_4DDB0(void) {
    return &lbl_1_bss_4C688.pad_10[0x50];
}
/* fzgx:end fn_1_4DDB0 */

/* fzgx:begin fn_1_4DDC0 */
#include "rel/main_rel/font.h"

#pragma opt_unroll_loops off
void fn_1_4DDC0(void) {
    Obj_1_bss_4C688 *ptr;
    int count;
    ptr = &lbl_1_bss_4C688;
    for (count = 0; count < 64; count++) {
        ptr->unk_0 = 0;
        ptr = (Obj_1_bss_4C688 *)((u8 *)ptr + 0x80);
    }
}
/* fzgx:end fn_1_4DDC0 */

/* fzgx:begin fn_1_4DE04 */
#include "rel/main_rel/font.h"

u32 fn_1_4DE04(void) {
    Obj_1_bss_4C688 *p = &lbl_1_bss_4C688;
    s32 i;

    for (i = 0; i < 64; i++, p = (Obj_1_bss_4C688 *)((u8 *)p + 0x80)) {
        p->unk_0 = 0;
    }
    return (u32)p;
}
/* fzgx:end fn_1_4DE04 */

/* fzgx:begin fn_1_4DE44 */
// Dispatch callbacks for each active font entry.
void fn_1_4DE44(void) {
    int i;
    u32 *entry;

    if (fn_1_3F164() == 0) {
        entry = &lbl_1_bss_4C688.unk_0;
        for (i = 0; i < 0x40; i++, entry += 0x20) {
            if ((int)entry[0] != 0 && entry[0x1e] != 0) {
                ((void (*)(u32 *))entry[0x1e])(entry);
            }
        }
    }
}
/* fzgx:end fn_1_4DE44 */

/* fzgx:begin fn_1_4DEC0 */
typedef u32 (*fn_1_4DEC0_Fn0)(u32);
struct fn_1_4DEC0_Copy88 { u32 a[22]; };



void fn_1_4DEC0(void) {
    struct FzgxCopy_88 loc_8;
    s32 (*temp_r12)(u32 *);
    s32 var_r31;
    u32 *var_r30;

    var_r31 = 0;
    var_r30 = (u32 *)(&lbl_1_bss_4C688);
    do {
        if ((s32) (*var_r30) != 0) {
            temp_r12 = (s32 (*)(u32 *))(*(s32 (**)(u32 *))((u8 *)(var_r30) + 124));
            if (temp_r12 == NULL) {
                loc_8 = *(const struct FzgxCopy_88 *)((((((u8 *)(var_r30) + 4))) + 4));
                fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
            } else {
                temp_r12(var_r30);
            }
        }
        var_r31 += 1;
        var_r30 = (u32 *)((u8 *)(var_r30) + 0x80);
    } while (var_r31 < 0x40);
}
/* fzgx:end fn_1_4DEC0 */

/* fzgx:begin fn_1_4DF60 */
typedef struct {
    u32 values[22];
} InitData;

typedef struct {
    s32 unk_0;
    u8 pad[0x7c];
} Slot;

Slot *fn_1_4DF60(void) {
    int i;
    Slot *p;

    p = (Slot *)&lbl_1_bss_4C688;
    for (i = 0; i < 64; i++, p++) {
        if (p->unk_0 == 0) {
            break;
        }
    }

    if (p->unk_0 != 0) {
        return 0;
    }

    *(s32 *)((u8 *)p + 0) = 1;
    *(InitData *)((u8 *)p + 8) = *(InitData *)lbl_1_rodata_26F8;
    *(u16 *)((u8 *)p + 6) = 0;
    *(u32 *)((u8 *)p + 0x68) = 0;
    *(u32 *)((u8 *)p + 0x64) = 0;
    *(u32 *)((u8 *)p + 0x60) = 0;
    *(f32 *)((u8 *)p + 0x74) = lbl_1_rodata_2750;
    *(f32 *)((u8 *)p + 0x70) = lbl_1_rodata_2750;
    *(f32 *)((u8 *)p + 0x6c) = lbl_1_rodata_2750;
    *(u32 *)((u8 *)p + 0x7c) = 0;
    *(u32 *)((u8 *)p + 0x78) = 0;
    *(u8 *)((u8 *)p + 4) = 0;
    return p;
}
/* fzgx:end fn_1_4DF60 */

/* fzgx:begin fn_1_4E060 */
#include "rel/main_rel/font.h"

void fn_1_4E060(void) {
    Obj_1_bss_4C688 *p;
    u32 count;
    u32 zero;

    p = &lbl_1_bss_4C688;
    zero = 0;
    for (count = 0; count < 64; count++) {
        p->unk_0 = zero;
        p = (Obj_1_bss_4C688 *)((u8 *)p + 0x80);
    }
}
/* fzgx:end fn_1_4E060 */

/* fzgx:begin fn_1_4E0A4 */
typedef struct FontMetric {
    f32 value;
    u8 pad[0x54];
} FontMetric;

int fn_1_4E0A4(u16 *left, u16 *right) {
    u16 left_index;
    FontMetric *metrics;
    u16 right_index;
    f32 left_value;
    f32 right_value;

    left_index = *left;
    metrics = (FontMetric *)(*(u32 *)&lbl_1_data_1C504 + 0xc);
    right_index = *right;

    left_value = metrics[left_index].value;
    right_value = metrics[right_index].value;
    if (left_value > right_value) {
        return -1;
    }
    if (left_value == right_value) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_4E0A4 */

/* fzgx:begin fn_1_4E0F4 */
void fn_1_4E0F4(void) {
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
}
/* fzgx:end fn_1_4E0F4 */

/* fzgx:begin fn_1_4E220 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

typedef enum {
    GX_TF_I4 = 0x0,
    GX_TF_I8 = 0x1,
    GX_TF_IA4 = 0x2,
    GX_TF_IA8 = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8 = 0x6,
    GX_TF_CMPR = 0xE,
    GX_CTF_R4 = 0x0 | 0x20,
    GX_CTF_RA4 = 0x2 | 0x20,
    GX_CTF_RA8 = 0x3 | 0x20,
    GX_CTF_YUVA8 = 0x6 | 0x20,
    GX_CTF_A8 = 0x7 | 0x20,
    GX_CTF_R8 = 0x8 | 0x20,
    GX_CTF_G8 = 0x9 | 0x20,
    GX_CTF_B8 = 0xA | 0x20,
    GX_CTF_RG8 = 0xB | 0x20,
    GX_CTF_GB8 = 0xC | 0x20,
    GX_TF_Z8 = 0x1 | 0x10,
    GX_TF_Z16 = 0x3 | 0x10,
    GX_TF_Z24X8 = 0x6 | 0x10,
    GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    GX_TF_A8 = GX_CTF_A8,
} GXTexFmt;

typedef struct {
    u32 dummy[8];
} GXTexObj;

typedef enum {
    GX_CLAMP,
    GX_REPEAT,
    GX_MIRROR,
    GX_MAX_TEXWRAPMODE,
} GXTexWrapMode;

typedef struct {
    f32 m[12];
} Mtx;

struct Arg0 {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    s16 unk_28;
    u8 pad_2A[0x6];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    s32 unk_40;
    u16 unk_44;
    u16 unk_46;
    u32 unk_48;
};

extern const f32 lbl_1_rodata_2750;
extern const f32 lbl_1_rodata_2754;
extern const f64 lbl_1_rodata_2758;
extern f32 fn_1_519AC(u32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006DD7C(void);
extern void lbl_8006DB74(Mtx *);
extern void mathutil_mtxA_rotate_z(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern u16 GXLoadTexMtxImm(Mtx *, u32, u32);
extern u32 __cvt_fp2unsigned(f32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, GXTexFmt, GXTexWrapMode, GXTexWrapMode, u8);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_80073C6C(s32);
extern GXTexObj lbl_1_bss_4E688;

void fn_1_4E220(struct Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    f32 fzgx_live;
    Mtx loc_8;
    u32 v1;
    s32 v2;
    u32 v5;
    BitmapImages *v6;
    u32 v7;
    f32 scale;
    f32 f44;
    f32 f46;
    struct { f32 v; } prod;
    struct { f32 v; } total;
    s32 lab_t1;
    u32 lab_t2;
    Mtx * lab_t0;
    s32 lab_t3;
    u32 lab_t3_;

    lbl_8006D7F4(arg0->unk_4, arg0->unk_8, lbl_1_rodata_2750);
    fzgx_live = arg0->unk_14;
    lbl_8006E15C(arg0->unk_10, fzgx_live, lbl_1_rodata_2754);
    if (arg0->unk_28 != 0) {
        mathutil_mtxA_rotate_z(arg0->unk_28);
    }
    lbl_8006DD7C();
    lbl_8006DB74(&loc_8);
    v1 = arg2 & 0xFF;
    v2 = arg4 & 0xFF;
    fn_800745A4(v1, 1, 4, v2, 0, 125);
    lab_t2 = 1;
    lab_t0 = &loc_8;
    GXLoadTexMtxImm(lab_t0, v2, lab_t2);
    if (arg0->unk_30 & 0x800000) {
        scale = fn_1_519AC(arg0->unk_40);
        f44 = arg0->unk_44;
        f46 = arg0->unk_46;
        scale = f44 * scale;
        scale = f46 * scale;
        DCFlushRange((void *)arg0->unk_48, __cvt_fp2unsigned(scale));
        lab_t3_ = arg0->unk_46;
        GXInitTexObj(&lbl_1_bss_4E688, (void *)arg0->unk_48, ((u16)(arg0->unk_44)), lab_t3_, (GXTexFmt)arg0->unk_40, GX_CLAMP, GX_CLAMP, 0);
        lab_t1 = arg3 & 0xFF;
        fn_80073778(&lbl_1_bss_4E688, lab_t1);
    } else {
        lab_t2 = arg0->unk_0;
        v5 = lab_t2;
        v6 = lbl_1_data_FCD4[(v5 >> 8) & 0xFFFF].images;
        if (!(lbl_1_rodata_2750 != arg0->unk_10 && lbl_1_rodata_2750 != arg0->unk_14 && v6 != 0)) {
            return;
        } else {
            fn_80073778(v6->textures[v5 & 0xFF], arg3 & 0xFF);
        }
    }
    v7 = arg1 & 0xFF;
    fn_80073C6C(v7);
    fn_800734A8(v7, v1, arg3 & 0xFF, 255);
    if (((0) == arg0->unk_40) || ((arg0->unk_40 == ((1))))) {
        fn_80072C24(v7, 15, 15, 15, 0);
        fn_80072D64(v7, 0, 0, 0, 1, 0);
        fn_80072CC4(v7, 7, 0, 4, 7);
        lab_t3 = 0;
        fn_80072E20(v7, 0, 0, lab_t3, 1, 0);
    } else {
        fn_800729B0(2, 0, 0, 0, 0);
        fn_80072AB0(v7, 0, 2);
        fn_80072C24(v7, 8, 15, 0, 15);
        fn_80072D64(v7, 8, 0, 0, 1, 0);
        fn_80072CC4(v7, 4, 7, 0, 7);
        lab_t3 = 0;
        fn_80072E20(v7, 14, 0, lab_t3, 1, 0);
    }
}
/* fzgx:end fn_1_4E220 */

/* fzgx:begin fn_1_4E500 */
void fn_1_4E500(void) {
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();
}
/* fzgx:end fn_1_4E500 */

/* fzgx:begin fn_1_4E638 */
void fn_1_4E638(s32 arg) {
    f32 *values;

    values = lbl_1_rodata_26F8;
    if (arg != 0) {
        C_MTXPerspective( (f32 *)((u8 *)lbl_801A6D00 + 0xc8),
                    values[26], fn_1_A6FE8(), values[27], values[28]);
        fn_800737E4((u8 *)lbl_801A6D00 + 0xc8, 0);
    } else {
        C_MTXOrtho((u8 *)lbl_801A6D00 + 0xc8,
                    values[22], values[29], values[22], values[30],
                    values[22], values[28]);
        fn_800737E4((u8 *)lbl_801A6D00 + 0xc8, 1);
    }
}
/* fzgx:end fn_1_4E638 */

/* fzgx:begin fn_1_4E6F4 */
void fn_1_4E6F4(void) {
    fn_1_A722C();
    fn_80074918(1, 3, 1);
}
/* fzgx:end fn_1_4E6F4 */

/* fzgx:begin fn_1_4E724 */
// Initialize the font system and return the selected font resource.
s32 fn_1_4E724(FontParams *arg) {
    FontParams local = *arg;
    s32 ret;

    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();

    if ((s32)lbl_1_bss_4E6A8 != 0) {
        local.unk_30 |= 0x08000000;
        local.unk_34 = (s32)lbl_1_bss_4E6AC;
    }

    ((u8 *)lbl_801A6D00)[0x197] = 0xff;

    if (local.unk_30 & 0x00800000) {
        ret = fn_1_4EC74(&local);
    } else {
        ret = fn_1_4EB74( (fn_1_4EB74_FontObject *)(FontParams *)(&local));
    }

    fn_1_A722C();
    fn_80074918(1, 3, 1);

    return ret;
}
/* fzgx:end fn_1_4E724 */

/* fzgx:begin fn_1_4E92C */
typedef struct Sig_fn_1_4EC74_FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} Sig_fn_1_4EC74_FontParams;

typedef struct Sig_fn_1_4EB74_FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} Sig_fn_1_4EB74_FontParams;

struct fn_1_4E92C_Copy88 { u32 a[22]; };
struct fn_1_4E92C_lbl_1_bss_4E6AC {
    s32 unk_0;
};
struct fn_1_4E92C_lbl_1_rodata_2778 {
    f64 unk_0;
};
struct fn_1_4E92C_lbl_801A6D00 {
    u32 unk_0;
};

s32 fn_1_4E92C(s32 arg0, u32 arg1, s16 arg2, s16 arg3, u32 arg4) {
    struct FzgxCopy_88 loc_60;
    struct FzgxCopy_88 loc_8;
    s32 var_r31;

    loc_60 = *(const struct FzgxCopy_88 *)((arg0 - 4 + 4));
    loc_60.words[0x10] = arg1;
    loc_60.words[0xC] |= 0x800000;
    (*(s16 *)((u8 *)(&loc_60) + 68)) = arg2;
    (*(s16 *)((u8 *)(&loc_60) + 70)) = arg3;
    loc_60.words[0x12] = arg4;
    loc_8 = *(const struct FzgxCopy_88 *)((((s32)(&loc_8.words[0x15])) + 4));
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C((0x2200U));
    fn_80074788((0U));
    fn_80074660((1U));
    fn_80073678((1U));
    fn_80073898((0U));
    fn_80073C6C((0));
    fn_800745A4((0U), (1), (4), (0x3CU), (0U), (0x7DU));
    fn_800734A8((0U), (0U), (0U), (0xFFU));
    fn_80072AB0((0), (0), (0));
    fn_80072C24((0), (0xF), (2), (8), (4));
    fn_80072D64((0U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((0U), (7U), (1U), (4U), (2U));
    fn_80072E20((0), (0), (0), (0), (1U), (0));
    fn_80074918((1U), (7), (0U));
    fn_800728A8((1), (4), (5), (0));
    fn_800720B0((0U));
    fn_80072864((2U));
    lbl_8006D758();
    fn_80072558();
    if ((s32) (lbl_1_bss_4E6A8) != 0) {
        loc_8.words[0xC] |= 0x08000000;
        (*(f32 *)((u8 *)(&loc_8) + 52)) = (*((struct fn_1_4E92C_lbl_1_bss_4E6AC *)&lbl_1_bss_4E6AC)).unk_0;
    }
    (*(u8 *)(((*((struct fn_1_4E92C_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 407)) = 0xFF;
    if (loc_8.words[0xC] & 0x800000) {
        var_r31 = fn_1_4EC74( (FontParams *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
    } else {
        var_r31 = fn_1_4EB74( (fn_1_4EB74_FontObject *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
    }
    fn_1_A722C();
    fn_80074918((1U), (3), (1U));
    return var_r31;
}
/* fzgx:end fn_1_4E92C */

/* fzgx:begin fn_1_4EB74 */
s32 fn_1_4EB74(fn_1_4EB74_FontObject *self) {
    BitmapResource *table;
    BitmapImages *data;
    u32 value;
    u32 index;
    BitmapImageInfo *info;
    f32 x;
    f32 y;

    if (self->unk_30 & 0x02000000) {
        return 0;
    }

    value = self->unk_0;
    fn_1_159588(value);
    value = self->unk_0;

    index = (value >> 8) & 0xffff;
    table = lbl_1_data_FCD4;
    if (table[index].loaded == 0) {
        return 0;
    }

    data = table[index].images;
    info = &data->info[value & 0xff];
    x = info->width;
    y = info->height;
    fn_80073778(data->textures[value & 0xff], 0);
    fn_1_4EDAC( (FontDrawPacket*)(self), x, y);
    return 1;
}
/* fzgx:end fn_1_4EB74 */

/* fzgx:begin fn_1_4EC74 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"
#include "font.h"

extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *, s32);

/* the const packet lets MWCC (GC/2.x) load packet->flags ahead of the r31 save, as retail does */
s32 fn_1_4EC74(const FontDrawPacket *packet) {
    if (packet->flags & 0x2000000) {
        return 0;
    }
    DCFlushRange(packet->pixels,
                 (packet->height * (packet->width * fn_1_519AC(packet->format))));
    {
        u32 width = packet->width, height = packet->height;
        GXInitTexObj(lbl_1_bss_4E6B0, packet->pixels, width, height, packet->format, 0, 0, 0);
    }
    GXInitTexObjLOD(lbl_1_bss_4E6B0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_80073778(lbl_1_bss_4E6B0, 0);
    fn_1_4EDAC((FontDrawPacket *)packet, packet->width, packet->height);
    return 1;
}
/* fzgx:end fn_1_4EC74 */

/* fzgx:begin fn_1_4EDAC noprologue */
#include "types.h"
#include "font.h"
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "psvec_fill.h"
#include "dolphin/gx.h"

struct fn_1_4EDAC_lbl_801A6D00 {
    u32 unk_0;
};

const u32 lbl_1_rodata_26F8[22] = {
0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,
0x3f800000,0x3f800000,0,0x3f800000,5,0,0xffffffff,0,0,0,0,0,0,0
};

#pragma section code_type ".fzgxpool"
static void fn_1_4EDAC_pool_primer(f32 *f, f64 *d) {
    f[0] = 0.0f;
    f[1] = 1.0f;
    d[0] = 4503599627370496.0;
    f[2] = 55.0f;
    f[3] = 0.1f;
    f[4] = 90000.0f;
    f[5] = 480.0f;
    f[6] = 640.0f;
    d[1] = 4503601774854144.0;
    d[2] = 0.5;
    f[7] = 0.75f;
    d[3] = 0.002405626;
    f[8] = 320.0f;
    f[9] = 240.0f;
    f[10] = 255.0f;
}
#pragma section code_type
extern struct fn_1_4EDAC_lbl_801A6D00 lbl_801A6D00;

typedef struct DrawVertex { f32 x, y, z; } DrawVertex;
typedef struct DrawColor { u8 r, g, b, a; } DrawColor;
typedef struct DrawFields {
    u32 id;
    f32 x, y, depth;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 angle_z, angle_y;
    f32 alpha;
    u32 flags;
    f32 pivot;
    DrawColor color, add_color;
    s32 format;
    u16 width, height;
    u32 image;
    FontDrawPacket *texture;
    void (*callback)(FontDrawPacket *, DrawVertex *);
} DrawFields;

extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(void *, f32, f32, f32, f32);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_1_4E220(FontDrawPacket *, u32, u32, u32, u32);
extern s32 fn_1_A6F1C(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void lbl_8006E1B0(void *, void *);
extern void fn_1_492F0(FontDrawPacket *, void *);
extern s32 fn_1_486F8(u32);
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800728A8(s32, s32, s32, s32);
extern u32 fn_800720B0(u32);
extern void fn_80072864(u32);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 fn_80074188(u32, u32, u32, u32);

static inline void draw_vertex(DrawVertex *v, f32 u, f32 t) {
    f32 z = v->z;
    f32 y = v->y;
    f32 x = v->x;
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
    GXWGFifo.f32 = u;
    GXWGFifo.f32 = t;
}

static inline void draw_reset(void) {
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
}

static inline u32 draw_perspective(FontDrawPacket *packet) {
    u32 result = (packet->flags >> 18) & 1;
    return result;
}

static inline u8 draw_min255(s32 value) {
    u8 result = value < 255 ? value : 255;
    return result;
}


void fn_1_4EDAC(FontDrawPacket *arg0, f32 arg1, f32 arg2) {
    u32 v0;
    f32 v1;
    DrawVertex *v2;
    u8 perspective;
#define v3 perspective
    f32 y, depth, u0, u1, t0, t1;
    DrawColor add_color, color;
    u32 flags;
    DrawFields *packet = (DrawFields *)arg0;
    perspective = draw_perspective(arg0);
    v0 = lbl_801A6D00.unk_0;
    v1 = 0.0f;
    v2 = (DrawVertex *)(v0 + 152);
    psvec_fill4(v2, v1);
    if (v3) {
        C_MTXPerspective((void *)(lbl_801A6D00.unk_0 + 0xc8), 55.0f, fn_1_A6FE8(),
            0.1f, 90000.0f);
        fn_800737E4((void *)(lbl_801A6D00.unk_0 + 0xc8), 0);
    } else {
        C_MTXOrtho((void *)(lbl_801A6D00.unk_0 + 0xc8), v1, 480.0f,
            v1, 640.0f, v1, 90000.0f);
        fn_800737E4((void *)(lbl_801A6D00.unk_0 + 0xc8), 1);
    }
    flags = arg0->flags;
    *(u8 *)(lbl_801A6D00.unk_0 + 0x197) = v3;
    if ((flags & 0x1000000) && packet->texture) {
        fn_80074660(2);
        fn_80073678(2);
        fn_1_4E220(packet->texture, 1, 1, 1, 0x21);
    } else {
        fn_80073678(1);
    }
    v1 = packet->x;
    y = packet->y;
    depth = -packet->depth;
    u0 = packet->u0;
    u1 = packet->u1;
    t0 = packet->v0;
    t1 = packet->v1;
    switch (arg0->flags & 3) {
    case 0:
    case 1:
    default:
        v2[0].x = v2[2].x = 0.0f;
        v2[1].x = v2[3].x = arg1;
        break;
    case 2: {
        f32 right;
        f32 left;
        left = -arg1 / 2.0;
        right = arg1 / 2.0;
        v2[0].x = v2[2].x = left;
        v2[1].x = v2[3].x = right;
        break;
    }
    case 3: {
        f32 right;
        f32 left;
        left = -arg1;
        right = 0.0f;
        v2[0].x = v2[2].x = left;
        v2[1].x = v2[3].x = right;
        break;
    }
    }
    switch ((arg0->flags >> 2) & 3) {
    case 0:
    case 1:
    default:
        v2[0].y = v2[1].y = 0.0f;
        v2[2].y = v2[3].y = arg2;
        break;
    case 2: {
        f32 right;
        f32 left;
        left = -arg2 / 2.0;
        right = arg2 / 2.0;
        v2[0].y = v2[1].y = left;
        v2[2].y = v2[3].y = right;
        break;
    }
    case 3: {
        f32 right;
        f32 left;
        left = -arg2;
        right = 0.0f;
        v2[0].y = v2[1].y = left;
        v2[2].y = v2[3].y = right;
        break;
    }
    }
    if ((arg0->flags & 0x8000000) && (fn_1_A6F1C() == 1 || fn_1_A6F1C() == 2)) {
        lbl_8006D7F4(packet->pivot, 0.0f, 0.0f);
        lbl_8006E15C(0.75f, 1.0f, 1.0f);
        lbl_8006E0B4(v1 - packet->pivot, y, 0.0f);
    } else {
        lbl_8006D7F4(v1, y, 0.0f);
    }
    if (packet->angle_z)
        mathutil_mtxA_rotate_z((s16)-packet->angle_z);
    if (packet->angle_y)
        mathutil_mtxA_rotate_y((s16)-packet->angle_y);
    lbl_8006E15C(packet->scale_x, packet->scale_y, 1.0f);
    lbl_8006E1B0(&v2[0], &v2[0]);
    lbl_8006E1B0(&v2[1], &v2[1]);
    lbl_8006E1B0(&v2[2], &v2[2]);
    lbl_8006E1B0(&v2[3], &v2[3]);
    fn_1_492F0(arg0, v2);
    if (v3) {
        f32 scratch;
        f32 scale;
        f32 cy;
        f32 cx;
        f32 vx;
        scale = 0.002405626 * packet->depth;
        vx = v2[0].x;
        cx = 320.0f;
        cy = 240.0f;
        scratch = vx - cx;
        v2[0].x = scratch * scale;
        scratch = v2[0].y - cy;
        v2[0].y = -(scratch * scale);
        scratch = v2[1].x - cx;
        v2[1].x = scratch * scale;
        scratch = v2[1].y - cy;
        v2[1].y = -(scratch * scale);
        scratch = v2[2].x - cx;
        v2[2].x = scratch * scale;
        scratch = v2[2].y - cy;
        v2[2].y = -(scratch * scale);
        scratch = v2[3].x - cx;
        v2[3].x = scratch * scale;
        scratch = v2[3].y - cy;
        v2[3].y = -(scratch * scale);
    }
    if (arg0->flags & 0x80000) {
        u0 = packet->u1;
        u1 = packet->u0;
    }
    if (arg0->flags & 0x100000) {
        t0 = packet->v1;
        t1 = packet->v0;
    }
    if (!(arg0->flags & 0x800000) && !(arg0->flags & 0x10000000) &&
        (fn_1_486F8(packet->id) == 0 || fn_1_486F8(packet->id) == 1)) {
        u32 sum;
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = (255.0f * packet->alpha);
        sum = packet->color.r + packet->add_color.r;
        add_color.r = (s32)sum < 255 ? sum : 255;
        sum = packet->color.g + packet->add_color.g;
        add_color.g = (s32)sum < 255 ? sum : 255;
        sum = packet->color.b + packet->add_color.b;
        add_color.b = draw_min255(sum);
        add_color.a = 0;
        { DrawColor copy = color; fn_800371F8(1, &copy); }
        { DrawColor copy = add_color; fn_800371F8(2, &copy); }
    } else {
        u32 blue, red;
        s8 green;
        /* volatile: preserve the retail RGB channel read order. */
        red = *(volatile u8 *)&packet->color.r;
        /* volatile: preserve the retail RGB channel read order. */
        green = *(volatile u8 *)&packet->color.g;
        /* volatile: preserve the retail RGB channel read order. */
        blue = packet->color.b;
        /* volatile: retain the retail red-before-green stack stores. */
        *(volatile u8 *)&color.r = red;
        /* volatile: retain the retail red-before-green stack stores. */
        *(volatile u8 *)&color.g = green;
        color.b = blue;
        color.a = (255.0f * packet->alpha);
        { DrawColor copy = color; fn_800371F8(1, &copy); }
        { DrawColor copy = packet->add_color; fn_800371F8(2, &copy); }
    }
    if ((arg0->flags & 0x4000000) && packet->callback)
        packet->callback(arg0, v2);
    if (!v3) {
        v2[0].z = v2[1].z = v2[2].z = v2[3].z = depth;
    }
    fn_8003462C(0x80, 7, 4);
    draw_vertex(&v2[0], u0, t0);
    draw_vertex(&v2[1], u1, t0);
    draw_vertex(&v2[3], u1, t1);
    draw_vertex(&v2[2], u0, t1);
    fn_80072AB0(1, 0, 0);
    if ((arg0->flags & 0x1000000) && packet->texture) {
        draw_reset();
        fn_80074660(1);
        fn_80072AB0(1, 0, 0);
    }
    if (arg0->flags & 0x4000000) {
        struct { u32 value; } height;
        draw_reset();
        height.value = fn_1_A5DB0();
        fn_80074188(0, 0, fn_1_A5D88(), height.value);
    }
}
/* fzgx:end fn_1_4EDAC */

/* fzgx:begin fn_1_4F724 */
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;
// Clear the font state value before the next initialization.
void fn_1_4F724(void) {
    lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0 = 0;
}
/* fzgx:end fn_1_4F724 */

/* fzgx:begin fn_1_4F734 noprologue */
#include "types.h"
#include "rel/main_rel/bitmap_resource.h"
#include "font.h"

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;
typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;
extern State lbl_1_bss_4C678;
extern Config lbl_1_data_1C500;
extern u16 lbl_1_bss_4E6D0__fzgx_offset_16002;
extern u8 *lbl_801A6D00;
extern void fn_1_A71CC(void), fn_800724C8(void), lbl_8006D758(void), fn_80072558(void),
    fn_1_A722C(void);
extern void fn_8007245C(u32), fn_80074788(u32), fn_80074660(u32), fn_80073678(u32),
    fn_80073898(u32), fn_80073C6C(u32), fn_800720B0(u32), fn_80072864(u32);
extern void fn_800745A4(u32, u32, u32, u32, u32, u32), fn_80072D64(u32, u32, u32, u32, u32, u32),
    fn_80072E20(u32, u32, u32, u32, u32, u32);
extern void fn_800734A8(u32, u32, u32, u32), fn_800728A8(u32, u32, u32, u32);
extern void fn_80072AB0(u32, u32, u32), fn_80074918(u32, u32, u32);
extern void fn_80072C24(u32, u32, u32, u32, u32), fn_80072CC4(u32, u32, u32, u32, u32);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *, u32);
extern void fn_1_4EDAC(FontDrawPacket *, f32, f32);
extern void fn_1_159588(u32);
extern void OSReport(const char *, ...);
extern void *fn_80008BA8(void *, const void *, u32);
extern s32 fn_1_54298(void), fn_1_542A8(void);
extern f32 fn_1_542B8(void);
int fn_1_4F734(FontDrawPacket *input) {
    State *state = &lbl_1_bss_4C678;
    Config *config = &lbl_1_data_1C500;
    if (input->image >= 0xffff0000u)
        return 0;
    if (input->flags & 0x20000) {
        FontDrawPacket local = *input;
        int result;
        fn_1_A71CC();
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(1);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
        fn_800734A8(0, 0, 0, 0xff);
        fn_80072AB0(0, 0, 0);
        fn_80072C24(0, 0xf, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        lbl_8006D758();
        fn_80072558();
        if (state->override_enabled) {
            local.flags |= 0x08000000;
            local.depth = state->override_value;
        }
        lbl_801A6D00[0x197] = 0xff;
        if (local.flags & 0x800000) {
            if (local.flags & 0x2000000)
                result = 0;
            else {

                DCFlushRange(local.pixels, (local.height *
                                                 (local.width * fn_1_519AC(local.format))));
                {
                    u32 width = local.width, height = local.height;
                    GXInitTexObj(state->texture, local.pixels, width, height, local.format, 0, 0, 0);
                }
                GXInitTexObjLOD(state->texture, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
                fn_80073778(state->texture, 0);
                fn_1_4EDAC(&local, local.width, local.height);
                result = 1;
            }
        } else {
            if (local.flags & 0x2000000)
                result = 0;
            else {
                BitmapResource *resource;
                BitmapResource *table;
                u32 id, index;
                fn_1_159588(local.image);
                table = lbl_1_data_FCD4;
                id = local.image;
                index = (id >> 8) & 0xffff;
                if (!table[index].loaded)
                    result = 0;
                else {
                    BitmapImageInfo *info;
                    f32 height, width;
                    resource = table;
                    resource += index;
                    info = &resource->images->info[(u8)id];
                    width = info->width;
                    height = info->height;
                    fn_80073778(resource->images->textures[(u8)id], 0);
                    fn_1_4EDAC(&local, width, height);
                    result = 1;
                }
            }
        }
        fn_1_A722C();
        fn_80074918(1, 3, 1);
        return result;
    } else {
        u16 count = lbl_1_bss_4E6D0__fzgx_offset_16002;
        FontDrawPacket *dst;
        if (count >= config->capacity) {
            if (!state->warned) {
                OSReport(config->warning);
                state->warned = 1;
            }
            return 0;
        }
        dst = &config->packets[count];
        fn_80008BA8(dst, input, 0x58);
        dst->x += fn_1_54298();
        dst->y += fn_1_542A8();
        dst->alpha *= fn_1_542B8();
        if (state->override_enabled) {
            dst->flags |= 0x08000000;
            dst->depth = state->override_value;
        }
        lbl_1_bss_4E6D0__fzgx_offset_16002++;
        return 1;
    }
}
/* fzgx:end fn_1_4F734 */

/* fzgx:begin fn_1_4FC50 */
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;
typedef struct {
    u32 unk_0;
} InputObject;

s32 fn_1_4FC50(InputObject *obj, u32 arg1, u16 arg2, u16 arg3, u32 arg4) {
    Obj_1_data_1C504_Target *entry;
    u16 index;

    if (obj->unk_0 >= 0xffff0000) {
        return 0;
    }
    index = lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0;
    if (index >= lbl_1_data_1C500) {
        return 0;
    }

    entry = (Obj_1_data_1C504_Target *)((u8 *)lbl_1_data_1C504 + index * 0x58);
    fn_80008BA8( (u32)(entry), (u32)(obj), 0x58);
    entry->unk_30 |= (u32)1 << 23;
    entry->unk_40 = arg1;
    entry->unk_44 = arg2;
    entry->unk_46 = arg3;
    entry->unk_48 = arg4;

    if ((s32)lbl_1_bss_4E6A8 != 0) {
        entry->unk_30 |= (u32)1 << 27;
        entry->unk_34 = (s32)lbl_1_bss_4E6AC;
    }

    lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0++;
    return 1;
}
/* fzgx:end fn_1_4FC50 */

/* fzgx:begin fn_1_4FD64 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;

typedef void FontDrawPacket;
extern u8 *lbl_801A66CC;
extern u8 *lbl_801A6D00;
extern const f64 lbl_1_rodata_2758;
extern f32 lbl_1_rodata_2750;
extern f32 fn_1_519AC(u32);
extern int fn_1_4E0A4(u16 *, u16 *);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_800720B0(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(void *, int, int, f32, f32, f32, u8, u8, int);
extern void fn_80073778(void *, s32);
extern void fn_1_4EDAC(FontDrawPacket *, f32, f32);
extern int fn_1_159588(int);
extern void fn_1_48D80(u32);
extern void fn_1_A71CC(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
static inline void fn_1_4FD64_call_GXInitTexObj(u8 a7, int a6, int a5, int a4, u16 a3, s16 a2, void *a1, void *a0) {
    GXInitTexObj(a0, a1, a2, a3, a4, a5, a6, a7);
}
void fn_1_4FD64(f32 arg0) {
    u16 *a;
    s32 i;
    u32 lab_t4;
    u32 lab_t0;
    a = (u16 *)(lbl_801A66CC + 0x8B8);
    for (i = 0; i < lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0; i++) {
        a[i] = i;
    }
    qsort(a, lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0, 2, (int (*)(const void *, const void *))fn_1_4E0A4);
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    lab_t0 = 0;
    fn_800734A8(lab_t0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xF, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();
    lbl_801A6D00[0x197] = 0xFF;
    for (i = 0; i < lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0; i++) {
        Obj_1_data_1C504_Target *e = (Obj_1_data_1C504_Target *)((u8 *)lbl_1_data_1C504 + a[i] * 0x58);
        u32 fl = *(volatile u32 *)&e->unk_30; // volatile: retail reads packet flags anew in each drawing path.
        if (fl & 0x2000000) continue;
        if (fl & 0x400000) {
            fn_1_48D80((u32)e);
        } else if (fl & 0x800000) {
            if (e->unk_30 & 0x2000000) continue;
            {
                f32 sc = fn_1_519AC(e->unk_40);
                sc = e->unk_44 * sc;
                sc = e->unk_46 * sc;
                DCFlushRange((void *)e->unk_48, __cvt_fp2unsigned(sc));
                lab_t4 = e->unk_46;
                fn_1_4FD64_call_GXInitTexObj(0, 0, 0, e->unk_40, lab_t4, e->unk_44, (void *)e->unk_48, lbl_1_bss_4E6B0);
                GXInitTexObjLOD(lbl_1_bss_4E6B0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
                fn_80073778(lbl_1_bss_4E6B0, 0);
                fn_1_4EDAC((FontDrawPacket *)e, e->unk_44, e->unk_46);
            }
        } else {
            if (e->unk_30 & 0x2000000) continue;
            {
                u32 pk;
                BitmapImages *q;
                BitmapImageInfo *p1;
                u8 *p2;
                f32 fh;
                f32 fw;
                BitmapResource *o;
                fn_1_159588(e->unk_0);
                pk = e->unk_0;
                o = &lbl_1_data_FCD4[(u16)(pk >> 8)];
                if (o->loaded != 0) {
                    q = o->images;
                    p1 = &q->info[pk & 0xFF];
                    p2 = (u8 *)q->textures[pk & 0xFF];
                    fw = p1->width;
                    fh = p1->height;
                    fn_80073778(p2, 0);
                    fn_1_4EDAC((FontDrawPacket *)e, fw, fh);
                }
            }
        }
    }
    fn_1_A722C();
    fn_80074918(1, 3, 1);
    lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0 = 0;
}
/* fzgx:end fn_1_4FD64 */

/* fzgx:begin fn_1_50164 */
void fn_1_50164(f32 a, f32 b, f32 c, f32 d) {
    fn_1_50190(a, b, c, c, d, d);
}
/* fzgx:end fn_1_50164 */

/* fzgx:begin fn_1_50190 noprologue */
#include "types.h"
#include "font.h"

struct Pkt88 { u32 words[22]; };

extern const f32 lbl_1_rodata_2750;
extern const f32 lbl_1_rodata_27A4;
extern const f64 lbl_1_rodata_2758;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    struct Pkt88 loc_8;
    f32 temp_f31;
    f32 var_f30;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f28_2;
    f32 temp_f30_2;
    f32 half;
    f32 temp_f24;
    f32 temp_f23;
    f32 var_f22;
    f32 temp_f30;
    u32 temp_r4;
    u32 temp_r0;
    u32 temp_r0_2;

    temp_f23 = fn_1_48690((*(u32 *)(arg0)));
    temp_f24 = (fn_1_486C4((*(u32 *)(arg0))) - farg4) - farg5;
    temp_f25 = (temp_f23 - farg2) - farg3;
    temp_f26 = (farg0 - farg2) - farg3;
    temp_f23 = (farg1 - farg4) - farg5;
    if (farg0 <= lbl_1_rodata_2750 || farg1 <= lbl_1_rodata_2750 || temp_f25 <= lbl_1_rodata_2750 || temp_f24 <= lbl_1_rodata_2750 || temp_f26 <= lbl_1_rodata_2750 || temp_f23 <= lbl_1_rodata_2750 || farg2 < lbl_1_rodata_2750 || farg3 < lbl_1_rodata_2750 || farg4 < lbl_1_rodata_2750 || farg5 < lbl_1_rodata_2750) {
        return;
    }
    {
        temp_r4 = *(u32 *)((u8 *)(arg0) + 48);
        temp_r0 = temp_r4 & 3;
        switch (temp_r0) {
        case 1:
        default:
            var_f22 = *(f32 *)((u8 *)(arg0) + 4);
            break;
        case 2:
            half = farg0 * lbl_1_rodata_27A4;
            var_f22 = (*(f32 *)((u8 *)(arg0) + 4)) - half;
            break;
        case 3:
            var_f22 = (*(f32 *)((u8 *)(arg0) + 4)) - farg0;
            break;
        }
        temp_r0_2 = (temp_r4 >> 2U) & 3;
        switch (temp_r0_2) {
        case 1:
        default:
            var_f30 = *(f32 *)((u8 *)(arg0) + 8);
            break;
        case 2:
            half = farg1 * lbl_1_rodata_27A4;
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - half;
            break;
        case 3:
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - farg1;
            break;
        }
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), (0), (0), farg2, farg4);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), farg2, (0), temp_f25, farg4);
        temp_f29 = temp_f26;
        temp_f29 /= temp_f25;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        temp_f31 = var_f22 + farg2;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f27 = farg2;
        temp_f27 += temp_f25;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), temp_f27, (0), farg3, farg4);
        temp_f26 = temp_f26 + temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), (0), farg4, farg2, temp_f24);
        temp_f28 = temp_f23 / temp_f24;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        temp_f30 = var_f30 + farg4;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), farg2, farg4, temp_f25, temp_f24);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), temp_f27, farg4, farg3, temp_f24);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f28_2 = farg4 + temp_f24;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), (0), temp_f28_2, farg2, farg5);
        temp_f30_2 = temp_f23 + temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), farg2, temp_f28_2, temp_f25, farg5);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (*(u32 *)(arg0)), temp_f27, temp_f28_2, farg3, farg5);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
    }
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_50190 */

/* fzgx:begin fn_1_508C4 */
typedef struct fn_1_508C4_FontObject {
    u32 unk0;
    f32 start_x;
    f32 start_y;
    f32 pos_x;
    f32 scale_x;
    f32 scale_y;
    u8 data[0x40];
} fn_1_508C4_FontObject;


#pragma opt_propagation off
void fn_1_508C4(fn_1_508C4_FontObject *obj, f32 dx, f32 dy) {
    fn_1_508C4_FontObject work;
    s32 x;
    s32 y;
    s32 x_start;
    s32 x_end;
    s32 y_end;
    s32 width;
    s32 height;
    s32 y_start;

    x_start = obj->start_x;
    x_end = (obj->start_x + dx);
    y_start = obj->start_y;
    y_end = (obj->start_y + dy);

    width = (obj->scale_x * fn_1_48690(obj->unk0));
    height = (obj->scale_y * fn_1_486C4(obj->unk0));

    for (y = y_start; y < y_end; y += height) {
        for (x = x_start; x < x_end; x += width) {
            s32 h;
            s32 w;

            work = *obj;
            h = y_end - y;
            h = h < height ? h : height;
            w = x_end - x;
            w = w < width ? w : width;
            fn_1_51678((FontDrawPacket *)&work, obj->unk0, 0, 0, w, h);
            work.start_x = x;
            work.start_y = y;
            fn_1_4F734((FontDrawPacket *)&work);
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_508C4 */

/* fzgx:begin fn_1_50A90 */
struct fn_1_50A90_Copy88 { u32 a[22]; };
struct fn_1_50A90_lbl_1_rodata_2758 { f64 unk_0; };
struct fn_1_50A90_lbl_1_rodata_2778 { f64 unk_0; };


#define PF(o) (*(f32 *)((u8 *)&packet + (o)))
#define FLAGS (*(u32 *)((u8 *)&packet + 48))
#define COPY() (packet = *(struct fn_1_50A90_Copy88 *)arg0)
#define SETUP(a,b,c,d) fn_1_51678((FontDrawPacket *)&packet, *(u32 *)arg0, (s16)(a), (s16)(b), (s16)(c), (s16)(d))
#define DRAW() fn_1_4F734((FontDrawPacket *)&packet)

#pragma opt_lifetimes off
void fn_1_50A90(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v6;
    u32 v4;
    s32 v0;
    u32 v1;
    u32 v3;
    u32 v2;
    u32 v5;
    f32 texRight;
    f32 rightX;
    f32 bottomY;
    f32 innerX;
    f32 innerY;
    f32 endTex;
    f32 v13;
    f32 ratioY;
    f32 endTexY;
    f32 v8;
    f64 v7;
    u32 v9;
    u32 v10;
    u32 v11;
    f64 v12;
    f32 v14;
    f32 v15;
    f32 v16;
    f32 v17;
    f32 v18;
    f32 y;
    f32 texBottom;
    f32 ratioX;
    f32 remainderY;
    f32 posX;
    f32 posRX;
    f32 posY;
    f32 posRY;
    s16 i;
    s16 count;
    struct fn_1_50A90_Copy88 packet;
    u16 t0;
    u16 t1;
    v0 = ((s32)((-arg1) & ~arg1) >> 31);
    v1 = (arg1 & v0);
    v2 = (v1 << 1);
    v3 = (arg2 & ((s32)((-arg2) & ~arg2) >> 31));
    v4 = v2;
    if ((s32)arg3 > (s32)v2) {
        v4 = arg3;
    }
    v5 = (v3 << 1);
    v6 = v5;
    if ((s32)arg4 > (s32)v5) {
        v6 = arg4;
    }
    t0 = fn_1_48690(*(u32 *)(arg0));
    v7 = ((struct fn_1_50A90_lbl_1_rodata_2758 *)&lbl_1_rodata_2758)->unk_0;
    v8 = (u32)(t0 & 0xFFFF);
    t1 = fn_1_486C4(*(u32 *)(arg0));
    v9 = (t1 & 0xFFFF);
    v10 = *(u32 *)((u8 *)arg0 + 48);
    v11 = (v10 & 0x3);
    v12 = ((struct fn_1_50A90_lbl_1_rodata_2778 *)&lbl_1_rodata_2778)->unk_0;
    v13 = v9;
    v14 = (v8 - (s32)v2);
    v15 = (v13 - (s32)v5);
    v16 = (s32)(v4 - v2);
    v17 = (s32)(v6 - v5);
    switch (v11) {
    case 1:
    default: v18 = *(f32 *)((u8 *)arg0 + 4); break;
    case 2: v18 = *(f32 *)((u8 *)arg0 + 4) - ((s32)v4 / 2); break;
    case 3: v18 = *(f32 *)((u8 *)arg0 + 4) - (s32)v4; break;
    }
    switch ((v10 >> 2) & 3) {
    case 1:
    default: y = *(f32 *)((u8 *)arg0 + 8); break;
    case 2: y = *(f32 *)((u8 *)arg0 + 8) - ((s32)v6 / 2); break;
    case 3: y = *(f32 *)((u8 *)arg0 + 8) - (s32)v6; break;
    }
    COPY();
    SETUP(0, 0, v1, v3);
    PF(4) = v18;
    PF(8) = y;
    FLAGS &= ~15;
    DRAW();

    COPY();
    texRight = v8 - (s32)v1;
    SETUP(texRight, 0, v1, v3);
    innerX = v18 + (s32)v1;
    rightX = v16 + innerX;
    PF(4) = rightX;
    PF(8) = y;
    FLAGS &= ~15;
    DRAW();

    COPY();
    texBottom = v13 - (s32)v3;
    SETUP(0, texBottom, v1, v3);
    innerY = y + (s32)v3;
    bottomY = v17 + innerY;
    PF(4) = v18;
    PF(8) = bottomY;
    FLAGS &= ~15;
    DRAW();

    COPY();
    SETUP(texRight, texBottom, v1, v3);
    PF(4) = rightX;
    PF(8) = bottomY;
    FLAGS &= ~15;
    DRAW();

    COPY();
    SETUP(v1, v3, v14, v15);
    ratioX = v16 / v14;
    ratioY = v17 / v15;
    PF(4) = innerX;
    PF(8) = innerY;
    FLAGS &= ~15;
    PF(16) *= ratioX;
    PF(20) *= ratioY;
    DRAW();

    if ((lbl_1_rodata_2750) != v16) {
        count = ratioX;
        i = 0;
        endTex = (s32)v3 + v15;
        while (i < count) {
            COPY();
            SETUP(v1, 0, v14, v3);
            posX = innerX + (f32)(i * v14);
            PF(4) = posX;
            PF(8) = y;
            FLAGS &= ~15;
            DRAW();
            COPY();
            SETUP(v1, endTex, v14, v3);
            PF(4) = posX;
            PF(8) = bottomY;
            FLAGS &= ~15;
            DRAW();
            i++;
        }
        texRight = v16 - (f32)(v14 * count);
        COPY();
        SETUP(v1, 0, texRight, v3);
        posRX = innerX + (f32)(i * v14);
        PF(4) = posRX;
        PF(8) = y;
        FLAGS &= ~15;
        DRAW();
        COPY();
        SETUP(v1, endTex, texRight, v3);
        PF(4) = posRX;
        PF(8) = bottomY;
        FLAGS &= ~15;
        DRAW();
    }
    if ((lbl_1_rodata_2750) != v17) {
        s16 iY;
        s16 countY;
        countY = ratioY;
        iY = 0;
        endTexY = (s32)v1 + v14;
        while (iY < countY) {
            COPY();
            SETUP(0, v3, v1, v15);
            posY = innerY + (f32)(iY * v15);
            PF(4) = v18;
            PF(8) = posY;
            FLAGS &= ~15;
            DRAW();
            COPY();
            SETUP(endTexY, v3, v1, v15);
            PF(4) = rightX;
            PF(8) = posY;
            FLAGS &= ~15;
            DRAW();
            iY++;
        }
        remainderY = v17 - (f32)(v15 * countY);
        COPY();
        SETUP(0, v3, v1, remainderY);
        posRY = innerY + (f32)(iY * v15);
        PF(4) = v18;
        PF(8) = posRY;
        FLAGS &= ~15;
        DRAW();
        COPY();
        SETUP(endTexY, v3, v1, remainderY);
        PF(4) = rightX;
        PF(8) = posRY;
        FLAGS &= ~15;
        DRAW();
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_50A90 */

/* fzgx:begin fn_1_51564 */
// Update the six halfwords that define the active font state.
void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth) {
    ((u16 *)&lbl_1_bss_4C678)[0xC02e] = first;
    ((u16 *)&lbl_1_bss_4C678)[0xC02f] = second;
    ((u16 *)&lbl_1_bss_4C678)[0xC030] = third;
    ((u16 *)&lbl_1_bss_4C678)[0xC031] = fourth;
    ((u16 *)&lbl_1_bss_4C678)[0xC032] = fifth;
    ((u16 *)&lbl_1_bss_4C678)[0xC033] = sixth;
}
/* fzgx:end fn_1_51564 */

/* fzgx:begin fn_1_5158C */
#include "rel/main_rel/font.h"

typedef struct FontDrawPacket FontDrawPacket;

extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

static inline int in_range(int value, int lower, int upper)
{
    if (value > upper) {
        return 0;
    }
    return value >= lower;
}


void fn_1_5158C(FontDrawPacket *packet, u32 color, s16 x, s16 y)
{
    s16 *state = (s16 *)((u8 *)&lbl_1_bss_4C678 + 0x20000);
    int max_x = state[-0x7f9c / 2] - 1;
    int max_y;
    int coordinate = x;
    if (!in_range(coordinate, 0, max_x)) {
        if (x < 0) {
            coordinate = 0;
        } else if (coordinate > max_x) {
            coordinate = max_x;
        }
        x = coordinate;
    }
    max_y = state[-0x7f9a / 2] - 1;
    coordinate = y;
    if (!in_range(coordinate, 0, max_y)) {
        if (y < 0) {
            coordinate = 0;
        } else if (coordinate > max_y) {
            coordinate = max_y;
        }
        y = coordinate;
    }
    fn_1_51678(packet, color, state[-0x7fa4 / 2] + x * state[-0x7fa0 / 2],
        state[-0x7fa2 / 2] + y * state[-0x7f9e / 2],
        state[-0x7fa0 / 2], state[-0x7f9e / 2]);
}
/* fzgx:end fn_1_5158C */

/* fzgx:begin fn_1_51678 */
void fn_1_51678(FontDrawPacket *p, u32 image, s16 x, s16 y, s16 width, s16 height) {
    f32 inv_height, inv_width;
    s32 texture_height, texture_width;
    p->image = image;
    texture_height = (s16)fn_1_486C4(image);
    texture_width = (s16)fn_1_48690(image);
    inv_width = 1.0f / texture_width;
    inv_height = 1.0f / texture_height;
    {
        f32 v, u, sy, sx;
        sx = width * inv_width;
        sy = height * inv_height;
        u = x * inv_width;
        v = y * inv_height;
        p->scale_x *= sx;
        p->scale_y *= sy;
        p->u0 = u;
        p->v0 = v;
    }
    p->u1 = inv_width * (x + width);
    p->v1 = inv_height * (y + height);
}
/* fzgx:end fn_1_51678 */

/* fzgx:begin fn_1_517EC */
void fn_1_517EC(FontDrawPacket *p, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height) { f32 inv_height, inv_width;
    inv_width = 1.0f / texture_width;
    inv_height = 1.0f / texture_height;
    p->scale_x *= width * inv_width;
    p->scale_y *= height * inv_height;
    p->u0 = x * inv_width;
    p->v0 = y * inv_height;
    p->u1 = inv_width * (x + width);
    p->v1 = inv_height * (y + height);
}
/* fzgx:end fn_1_517EC */

/* fzgx:begin fn_1_51914 */
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;
typedef struct {
    u32 words[22];
} fn_1_51914_state;


void fn_1_51914(const fn_1_51914_state *src) {
    fn_1_51914_state state = *src;

    lbl_1_bss_4C678 = (u32)lbl_1_data_1C504 +
        lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0 * 0x58;
    state.words[12] |= 0x2000000;
    fn_1_4F734( (FontDrawPacket *)(&state));
}
/* fzgx:end fn_1_51914 */

/* fzgx:begin fn_1_51990 */
// Copy the font state value and enable the corresponding object flag.
void fn_1_51990(void *obj) {
    *(u32 *)((u8 *)obj + 0x4c) = lbl_1_bss_4C678;
    *(u32 *)((u8 *)obj + 0x30) |= 0x01000000;
}
/* fzgx:end fn_1_51990 */

/* fzgx:begin fn_1_519AC */
struct fn_1_519AC_lbl_1_rodata_26F8 {
    u8 pad_0[0x58];
    f32 unk_58;
    f32 unk_5C;
    u8 pad_60[0x4C];
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
};



f32 fn_1_519AC(u32 value) {
    struct fn_1_519AC_lbl_1_rodata_26F8 *base = &(*(struct fn_1_519AC_lbl_1_rodata_26F8 *)&lbl_1_rodata_26F8);

    switch (value) {
    case 0:
    case 14:
        return base->unk_AC;
    case 1:
    case 2:
    case 17:
        return base->unk_5C;
    case 3:
    case 4:
    case 5:
    case 19:
        return base->unk_B0;
    case 6:
    case 22:
        return base->unk_B4;
    default:
        return base->unk_58;
    }
}

/* ordinal suffixes: rows 1st, 2nd, 3rd, nth; one column per language */
char *font_ordinal_suffix[4][6] = {
    {"st", ".", ".", ".", ".", ""},
    {"nd", ".", ".", ".", ".", ""},
    {"rd", ".", ".", ".", ".", ""},
    {"th", ".", ".", ".", ".", ""},
};
/* fzgx:end fn_1_519AC */

/* fzgx:begin fn_1_519FC */
typedef struct {
    f32 width;
    u8 pad0[4];
    f32 height;
    u8 pad1[8];
} FontViewport;

f32 fn_1_519FC(f32 value) {
    FontViewport viewport;
    f32 width;
    f32 height;

    fn_80038F10( (f32*)(&viewport));

    width = viewport.width;
    height = viewport.height;

    return value * height / fn_1_A5D88()
         + lbl_1_rodata_2770 * width / fn_1_A5D88();
}
/* fzgx:end fn_1_519FC */

/* fzgx:begin fn_1_51AC0 */
typedef struct {
    u8 unk0[4];
    f32 value0;
    u8 unk10[4];
    f32 value1;
    u8 tail[8];
} FnData;

f32 fn_1_51AC0(f32 value) {
    f32 input = value;
    f32 value0;
    f32 value1;
    f32 part;
    f32 denom;
    f32 result;
    FnData data;

    fn_80038F10( (f32*)(&data));
    value0 = data.value0;
    value1 = data.value1;
    denom = ((u32)fn_1_A5DB0() & 0xffff);
    part = lbl_1_rodata_276C * value0 / denom;
    denom = ((u32)fn_1_A5DB0() & 0xffff);
    result = input * value1 / denom;
    return result + part;
}
/* fzgx:end fn_1_51AC0 */

/* fzgx:begin fn_1_51B84 */
typedef struct Fn151B84Tmp {
    u8 unk[8];
    f32 value;
    u8 rest[12];
} Fn151B84Tmp;

f32 fn_1_51B84(f32 value) {
    Fn151B84Tmp tmp;
    f32 factor;
    f32 input;
    input = value;
    fn_80038F10( (f32*)(&tmp));
    factor = tmp.value;
    return input * factor / fn_1_A5D88();
}
/* fzgx:end fn_1_51B84 */

/* fzgx:begin fn_1_51BFC */
typedef struct {
    u8 pad[0x0c];
    f32 value;
    u8 tail[8];
} Fn51BFCData;

f32 fn_1_51BFC(f32 value) {
    Fn51BFCData data;
    f32 factor;

    fn_80038F10( (f32*)(&data));
    factor = data.value;
    return value * factor / ((u32)fn_1_A5DB0() & 0xffff);
}
/* fzgx:end fn_1_51BFC */

/* fzgx:begin fn_1_51C74 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    Vec4 value;
    u32 pad[2];
} Temp;


typedef struct {
    u8 pad0[0xc];
    f32 x;
    f32 y;
    u8 pad1[4];
    f32 z;
    f32 w;
} fn_1_51C74_FontData;

void fn_1_51C74(fn_1_51C74_FontData *obj) {
    f32 a0;
    f32 fzgx_live;
    f32 fzgx_live_;
    f32 fzgx_live__;
    Temp t0;
    Temp t1;
    Temp t2;
    f32 a1;
    Temp t3;
    f32 x;
    f32 b1;
    f32 w;
    struct { f32 value; } b0;
    f32 fzgx_live___;
    f32 y;
    f32 b2;
    f32 a2;

    fzgx_live___ = obj->x;
    fzgx_live = fzgx_live___;
    x = fzgx_live;
    fn_80038F10( (f32*)(Vec4 *)(&t0.value));
    fzgx_live__ = t0.value.x;
    fzgx_live_ = fzgx_live__;
    a0 = fzgx_live_;
{
    f32 z;
    b0.value = t0.value.z;
    obj->x = (((x) * b0.value)) / ((u32)fn_1_A5D88() & 0xffff)
        + lbl_1_rodata_2770 * a0 / ((u32)fn_1_A5D88() & 0xffff);

    y = obj->y;
    fn_80038F10( (f32*)(Vec4 *)(&t1.value));
    a1 = t1.value.y;
    b1 = t1.value.w;
    obj->y = ((y) * b1) / ((u32)fn_1_A5DB0() & 0xffff)
        + lbl_1_rodata_276C * a1 / ((u32)fn_1_A5DB0() & 0xffff);

    z = obj->z;
    fn_80038F10( (f32*)(Vec4 *)(&t2.value));
    a2 = t2.value.z;
    obj->z = z * a2 / ((u32)fn_1_A5D88() & 0xffff);
}

    w = obj->w;
    fn_80038F10( (f32*)(Vec4 *)(&t3.value));
    b2 = t3.value.w;
    obj->w = w * b2 / ((u32)fn_1_A5DB0() & 0xffff);
}
/* fzgx:end fn_1_51C74 */

/* fzgx:begin fn_1_51E60 */
typedef struct FontParams_fn_1_51E60 {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams_fn_1_51E60;

typedef struct fn_1_4EB74_FontObject_fn_1_51E60 {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject_fn_1_51E60;

typedef struct fn_1_54668_node_fn_1_51E60 {
    struct fn_1_54668_node_fn_1_51E60 *next;
    void *data;
} fn_1_54668_node_fn_1_51E60;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_fn_1_51E60;

typedef struct fn_1_547F8_node_fn_1_51E60 {
    struct fn_1_547F8_node_fn_1_51E60 *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_51E60 *);
} fn_1_547F8_node_fn_1_51E60;

typedef struct fn_1_563E4_FontState_fn_1_51E60 {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState_fn_1_51E60;

typedef struct State_fn_1_51E60 {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State_fn_1_51E60;

typedef struct Config_fn_1_51E60 {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config_fn_1_51E60;

typedef struct ImageInfo_fn_1_51E60 {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo_fn_1_51E60;

typedef struct Images_fn_1_51E60 {
    u32 unk_0;
    ImageInfo_fn_1_51E60 *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images_fn_1_51E60;

typedef struct Resource_fn_1_51E60 {
    s32 loaded;
    u8 unk_4[0x1c];
    Images_fn_1_51E60 *images;
    u32 unk_24;
} Resource_fn_1_51E60;

struct fn_1_530C8_lbl_1_rodata_282C_fn_1_51E60 {
    f32 unk_0;
};

struct FzgxCopy_88_fn_1_51E60 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void OSReport(const char *format, ...);
extern u8 *lbl_801A66CC;
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);



static inline f32 fn_1_51E60_x(f32 x) {
    f32 viewport[6];
    f32 left;
    f32 width;

    fn_80038F10(viewport);
    left = viewport[0];
    width = viewport[2];
    return x * width / fn_1_A5D88() + 640.0f * left / fn_1_A5D88();
}

static inline f32 fn_1_51E60_y(f32 y) {
    f32 viewport[6];
    f32 top;
    f32 height;

    fn_80038F10(viewport);
    top = viewport[1];
    height = viewport[3];
    return y * height / fn_1_A5DB0() + 480.0f * top / fn_1_A5DB0();
}

static inline f32 fn_1_51E60_w(f32 w) {
    f32 viewport[6];
    f32 width;

    fn_80038F10(viewport);
    width = viewport[2];
    return w * width / fn_1_A5D88();
}

static inline f32 fn_1_51E60_h(f32 h) {
    f32 viewport[6];
    f32 height;

    fn_80038F10(viewport);
    height = viewport[3];
    return h * height / fn_1_A5DB0();
}

void fn_1_51E60(FontDrawPacket *src) {
    FontDrawPacket packet;

    packet = *src;
    packet.x = fn_1_51E60_x(packet.x);
    packet.y = fn_1_51E60_y(packet.y);
    packet.scale_x = fn_1_51E60_w(packet.scale_x);
    packet.scale_y = fn_1_51E60_h(packet.scale_y);
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_51E60 */

/* fzgx:begin fn_1_52070 */
void fn_1_52070(u32 value) {
    lbl_1_bss_4E6A8 = 1;
    lbl_1_bss_4E6AC = value;
}
/* fzgx:end fn_1_52070 */

/* fzgx:begin fn_1_52088 */
void fn_1_52088(void) {
    lbl_1_bss_4E6A8 = 0;
    lbl_1_bss_4E6AC = 0;
}
/* fzgx:end fn_1_52088 */

/* fzgx:begin fn_1_520A0 */
void fn_1_520A0(void) {
    u32 value_a;
    u32 value_b;

    value_a = lbl_1_bss_4E6A8;
    value_b = lbl_1_bss_4E6AC;
    lbl_1_bss_646E0 = value_a;
    lbl_1_bss_646E4 = value_b;
}
/* fzgx:end fn_1_520A0 */

/* fzgx:begin fn_1_520CC */
void fn_1_520CC(void) {
    u32 value_a;
    u32 value_b;

    value_a = lbl_1_bss_646E0;
    value_b = lbl_1_bss_646E4;
    lbl_1_bss_4E6A8 = value_a;
    lbl_1_bss_4E6AC = value_b;
}
/* fzgx:end fn_1_520CC */

/* fzgx:begin fn_1_520F8 */
f32 fn_1_520F8(s32 value) {
    s32 base;
    f32 scaled;

    if ((s8)fn_1_A5DC4(value) && (*(s32 *)&lbl_1_bss_4E6A8) != 0) {
        base = lbl_1_bss_4E6AC;
        scaled = (value - base) * lbl_1_rodata_2788[0];
        return base + scaled;
    }
    return value;
}
/* fzgx:end fn_1_520F8 */

/* fzgx:begin fn_1_521B8 */
// Convert a font value to its scaled coordinate when the font system is active.
f32 fn_1_521B8(s32 value) {
    if ((s8)fn_1_A5DC4(value) && (s32)lbl_1_bss_4E6A8 != 0) {
        return lbl_1_rodata_2788[0] * value;
    }

    return value;
}
/* fzgx:end fn_1_521B8 */

/* fzgx:begin fn_1_52250 */
struct fn_1_52250_Arg0 {
    u8 pad_0[0x54];
    f32 unk_54;
};

struct fn_1_52250_Arg1 {
    f32 unk_0;
    u8 pad_4[0x8];
    f32 unk_C;
};

void fn_1_52250(struct fn_1_52250_Arg0 *arg0, struct fn_1_52250_Arg1 *arg1) {
    f32 addend;
    f32 current;

    current = arg1->unk_0;
    addend = arg0->unk_54;
    current = current + addend;
    arg1->unk_0 = current;
    current = arg1->unk_C;
    current = current + addend;
    arg1->unk_C = current;
}
/* fzgx:end fn_1_52250 */

/* fzgx:begin fn_1_52270 */
struct Color {
    u8 r, g, b, a;
};

extern void fn_800371F8(s32 id, struct Color color);

/* __restrict lets MWCC load the packet fields before the LR save, as retail does */
void fn_1_52270(FontDrawPacket * __restrict packet) {
    struct Color add;
    struct Color color;

    color.r = packet->color[0];
    color.g = packet->color[1];
    color.b = packet->color[2];
    color.a = 255.0f * packet->alpha;
    add.r = packet->color_add[0];
    add.g = packet->color_add[1];
    add.b = packet->color_add[2];
    add.a = 0;
    fn_800371F8(1, color);
    fn_800371F8(2, add);
    fn_80072C24(0, 4, 2, 8, 15);
    fn_80072CC4(0, 7, 7, 7, 1);
}
/* fzgx:end fn_1_52270 */

/* fzgx:begin fn_1_5233C */
#include "sdk_addresses.h"

typedef struct FontParams_fn_1_5233C {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams_fn_1_5233C;

typedef struct fn_1_4EB74_FontObject_fn_1_5233C {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject_fn_1_5233C;

typedef struct fn_1_54668_node_fn_1_5233C {
    struct fn_1_54668_node_fn_1_5233C *next;
    void *data;
} fn_1_54668_node_fn_1_5233C;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_fn_1_5233C;

typedef struct fn_1_547F8_node_fn_1_5233C {
    struct fn_1_547F8_node_fn_1_5233C *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_5233C *);
} fn_1_547F8_node_fn_1_5233C;

typedef struct fn_1_563E4_FontState_fn_1_5233C {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState_fn_1_5233C;

typedef struct State_fn_1_5233C {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State_fn_1_5233C;

typedef struct Config_fn_1_5233C {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config_fn_1_5233C;

typedef struct ImageInfo_fn_1_5233C {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo_fn_1_5233C;

typedef struct Images_fn_1_5233C {
    u32 unk_0;
    ImageInfo_fn_1_5233C *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images_fn_1_5233C;

typedef struct Resource_fn_1_5233C {
    s32 loaded;
    u8 unk_4[0x1c];
    Images_fn_1_5233C *images;
    u32 unk_24;
} Resource_fn_1_5233C;

struct fn_1_530C8_lbl_1_rodata_282C_fn_1_5233C {
    f32 unk_0;
};

struct FzgxCopy_88_fn_1_5233C { u32 words[22]; };
extern void *lbl_801A6D00;
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void OSReport(const char *format, ...);
extern u8 *lbl_801A66CC;
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);


struct fn_1_5233C_Copy88 { u32 a[22]; };
struct ShadowEntry { u32 color; f32 x, y; };
struct ShadowTable { struct ShadowEntry e[9]; };
struct Color { u8 r,g,b,a; };
extern u32 lbl_1_rodata_27B0;
extern f32 lbl_1_rodata_2764[2];
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
#define FIFO (*(volatile f32 *)FZGX_ADDR___GXFifo) /* GX write-gather FIFO */
static inline void pos(f32 x, f32 y, f32 z) { FIFO=x; FIFO=y; FIFO=z; }
static inline f32 xy(f32 x, f32 y, f32 bias) { FIFO=x; FIFO=y; return bias; }
#define VERT(X,Y,U,V) pos((X),(Y),z); FIFO=(U); FIFO=(V)
void fn_1_5233C(void *arg0, void *arg1) {
    struct ShadowTable table;
    struct fn_1_5233C_Copy88 copy;
    struct Color color;
    u32 c0;
    struct Color c1;
    struct ShadowEntry *entry;
    f32 dx,dy,z,v0,u1,u0,v1;
    f32 bias;
    f32 *p = arg1;
    table = *(struct ShadowTable *)&lbl_1_rodata_27B0;
    entry = &table.e[(u32)*(f32 *)((u8 *)arg0+0x54)];
    if (!(*(u32 *)((u8 *)arg0+0x30) & 0x10000000)) {
        copy = *(struct fn_1_5233C_Copy88 *)arg0;
        c0 = entry->color;
        dx = entry->x;
        dy = entry->y;
        fn_800371F8(2, &c0);
        fn_8003462C(0x80,7,16);
        xy(p[0],p[1]-dy,0.0f);
        z = -(0.1f+*(f32 *)((u8 *)&copy+0xc)); FIFO=z;
        u0=*(f32 *)((u8 *)&copy+0x18); FIFO=u0;
        v0=*(f32 *)((u8 *)&copy+0x1c); FIFO=v0;
        pos(p[3],p[4]-dy,z);
        u1=*(f32 *)((u8 *)&copy+0x20); FIFO=u1; FIFO=v0;
        pos(p[9],p[10]-dy,z); FIFO=u1;
        v1=*(f32 *)((u8 *)&copy+0x24); FIFO=v1;
        VERT(p[6],p[7]-dy,u0,v1);
        VERT(p[0],p[1]+dy,u0,v0);
        VERT(p[3],p[4]+dy,u1,v0);
        VERT(p[9],p[10]+dy,u1,v1);
        VERT(p[6],p[7]+dy,u0,v1);
        color.a=0;
        VERT(p[0]-dx,p[1],u0,v0);
        VERT(p[3]-dx,p[4],u1,v0);
        VERT(p[9]-dx,p[10],u1,v1);
        VERT(p[6]-dx,p[7],u0,v1);
        VERT(p[0]+dx,p[1],u0,v0);
        VERT(p[3]+dx,p[4],u1,v0);
        VERT(p[9]+dx,p[10],u1,v1);
        VERT(p[6]+dx,p[7],u0,v1);
        color.r=*((u8 *)&copy+0x38);
        color.g=*((u8 *)&copy+0x39);
        color.b=*((u8 *)&copy+0x3a);
        c1=color;
        fn_800371F8(2,&c1);
    }
}
/* fzgx:end fn_1_5233C */

/* fzgx:begin fn_1_52690 */
extern u8 lbl_1_bss_646E8[40];
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);

/* __restrict lets MWCC load the packet fields before the LR save, as retail does */
void fn_1_52690(FontDrawPacket * __restrict packet) {
    u32 width = packet->width, height = packet->height;

    GXInitTexObj(lbl_1_bss_646E8, packet->pixels, width, height, packet->format, 0, 0, 0);
    GXInitTexObjLOD(lbl_1_bss_646E8, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_80073778(lbl_1_bss_646E8, 0);
}
/* fzgx:end fn_1_52690 */

/* fzgx:begin fn_1_52718 */
struct Color {
    u8 r, g, b, a;
};

extern void fn_800371F8(s32 id, struct Color color);

/* __restrict lets MWCC load the packet fields before the LR save, as retail does */
void fn_1_52718(FontDrawPacket * __restrict packet) {
    struct Color color;

    color.r = packet->color[0];
    color.g = packet->color[1];
    color.b = packet->color[2];
    color.a = 255.0f * packet->alpha;
    fn_800371F8(1, color);
    fn_800371F8(2, *(struct Color *)packet->color_add);
    fn_800728A8(1, 1, 1, 0);
}
/* fzgx:end fn_1_52718 */

/* fzgx:begin fn_1_527B4 */
typedef struct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x4];
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x10];
    s16 unk_28;
} FontState;



void fn_1_527B4(void) {
    u8 scratch[0x30];
    FontState *state;
    BitmapResource *entry;
    BitmapImages *obj;
    u32 value;
    u32 index;

    state = (FontState *)lbl_1_bss_4C678;
    if (state != 0) {
        fn_80074918(1, 3, 1);
        lbl_8006D7F4(state->unk_4, state->unk_8, lbl_1_rodata_2750);
        lbl_8006E15C(state->unk_10, state->unk_14, lbl_1_rodata_2754);
        mathutil_mtxA_rotate_z(state->unk_28);
        lbl_8006DD7C();
        lbl_8006DB74(&scratch[0]);
        fn_800745A4(1, 1, 4, 0x21, 0, 0x7d);
        GXLoadTexMtxImm( (u32)(&scratch[0]), 0x21, 1);
        value = state->unk_0;
        index = (value >> 8) & 0xffff;
        entry = lbl_1_data_FCD4;
        entry += index;
        obj = entry->images;
        if (lbl_1_rodata_2750 == state->unk_10 ||
            lbl_1_rodata_2750 == state->unk_14 ||
            obj == 0) {
            return;
        }
        fn_80073778(((u8 *)obj->textures + ((value & 0xff) << 5)), 1);
    }
    fn_80074660(2);
    fn_80073678(2);
    fn_80073C6C(1);
    fn_800734A8(1, 1, 1, 0xff);
    fn_80072C24(0, 0xf, 0xf, 0xf, 0xf);
    fn_80072C24(1, 4, 0xc, 8, 0xf);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 7, 7, 7, 0);
    fn_80072E20(1, 0, 0, 0, 1, 0);
}
/* fzgx:end fn_1_527B4 */

/* fzgx:begin fn_1_52968 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const unsigned long fzgx_pool_table4[19] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 55.0f;
    s = 0.10000000149011612f;
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[27] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern void fn_1_4954C(f32 value);
extern void fn_1_52B68(void *arg0, void *arg1);
extern void fn_1_52B8C(void *arg0, void *arg1);
extern void fn_1_52BB0(void *arg0, void *arg1);
extern void fn_1_52BD4(void *arg0, void *arg1);
extern void fn_1_530C8(void *arg0);

// Draw formatted text as four rotated layers (one vertex callback each, each
// slightly deeper), then the top layer through fn_1_530C8 unless mode 5.
void fn_1_52968(s32 x, s32 y, f32 depth, const char *format, ...) {
    char buffer[4096];
    __va_list args;
    void (*callbacks[4])(void *, void *) = { fn_1_52B68, fn_1_52B8C, fn_1_52BB0, fn_1_52BD4 };
    u32 i;
    f32 step;

    __builtin_va_info(&args);
    fn_8008077C((u32)buffer, (u32)format, (u32)&args);

    for (i = 0; i < 4; i++) {
        fn_1_496FC(x, y);
        fn_1_49738((u32)callbacks[i]);
        step = 0.1f * (s32)i;
        fn_1_4954C(depth + step);
        fn_1_4A0D8(buffer);
    }

    if ((s32)(lbl_801A66B4) != 5) {
        fn_1_496FC(x, (y + 3));
        fn_1_49738((u32)fn_1_530C8);
        fn_1_4954C(0.5f + depth);
        fn_1_4A0D8(buffer);
    }
}
/* fzgx:end fn_1_52968 */

/* fzgx:begin fn_1_52B68 */
void fn_1_52B68(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0);
}
/* fzgx:end fn_1_52B68 */

/* fzgx:begin fn_1_52B8C */
void fn_1_52B8C(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0x1000);
}
/* fzgx:end fn_1_52B8C */

/* fzgx:begin fn_1_52BB0 */
void fn_1_52BB0(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0x2000);
}
/* fzgx:end fn_1_52BB0 */

/* fzgx:begin fn_1_52BD4 */
void fn_1_52BD4(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0x3000);
}
/* fzgx:end fn_1_52BD4 */

/* fzgx:begin fn_1_52BF8 */
struct fn_1_52BF8_lbl_801A6D00 {
    u32 unk_0;
};




void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2) {
    s16 s = arg2;
    s32 t1;
    s32 t2;

    (void)arg1;
    lbl_8006D758();
    t1 = s + 0x4000;
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(arg2));
    GXLoadTexMtxImm(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (0x1EU), (1U));
    t2 = s + 0x8000;
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (0x21U), (1U));
    t1 = s + 0xC000;
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    GXLoadTexMtxImm(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (0x24U), (1U));
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188((s + 0x10000)));
    (*(f32 *)(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm(((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (0x27U), (1U));
    fn_8007245C((0x2200U));
    fn_80073678((5U));
    fn_80074660((4U));
    fn_800745A4((0U), (1), (4), (0x1EU), (0U), (0x7DU));
    fn_800745A4((1U), (1), (4), (0x21U), (0U), (0x7DU));
    fn_800745A4((2U), (1), (4), (0x24U), (0U), (0x7DU));
    fn_800745A4((3U), (1), (4), (0x27U), (0U), (0x7DU));
    fn_80073C6C((0));
    fn_80073C6C((1));
    fn_80073C6C((2));
    fn_80073C6C((3));
    fn_80073C6C((4));
    fn_800734A8((0U), (0U), (0U), (0xFFU));
    fn_800734A8((1U), (1U), (0U), (0xFFU));
    fn_800734A8((2U), (2U), (0U), (0xFFU));
    fn_800734A8((3U), (3U), (0U), (0xFFU));
    fn_800734A8((4U), (0xFFU), (0xFFU), (0xFFU));
    fn_80072C24((0), (0xF), (0xF), (0xF), (8));
    fn_80072D64((0U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((0U), (7U), (7U), (7U), (4U));
    fn_80072E20((0), (0), (0), (0), (1U), (0));
    fn_80072C24((1), (0xF), (8), (0xC), (0));
    fn_80072D64((1U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((1U), (4U), (7U), (7U), (0U));
    fn_80072E20((1), (0), (0), (0), (1U), (0));
    fn_80072C24((2), (0xF), (8), (0xC), (0));
    fn_80072D64((2U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((2U), (4U), (7U), (7U), (0U));
    fn_80072E20((2), (0), (0), (0), (1U), (0));
    fn_80072C24((3), (0xF), (8), (0xC), (0));
    fn_80072D64((3U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((3U), (4U), (7U), (7U), (0U));
    fn_80072E20((3), (0), (0), (0), (1U), (0));
    fn_80072C24((4), (0xF), (2), (0), (4));
    fn_80072D64((4U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((4U), (7U), (1U), (0U), (2U));
    fn_80072E20((4), (0), (0), (0), (1U), (0));
    fn_80074918((1U), (3), (1U));
}
/* fzgx:end fn_1_52BF8 */

/* fzgx:begin fn_1_530C8 */
struct fn_1_530C8_lbl_801A6D00 {
    u32 unk_0;
};




#pragma opt_propagation off
void fn_1_530C8(void * arg0) {
    u32 v0;
    f32 v1;
    u32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    u32 v6;
    f32 v7;
    f32 t1;
    f32 t2;
    f32 t4;
    f32 t5;
    f32 t7;
    f32 t8;
    f32 t10;
    f32 t11;
    lbl_8006D758();
    t1 = lbl_8006D188(-6144);
    v0 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v0 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t1);
    t2 = lbl_8006D188(-22528);
    v1 = (*(f32 *)((u8 *)arg0 + 84) * t2);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v1)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 30, 1);
    t4 = lbl_8006D188(-2048);
    v2 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v2 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t4);
    t5 = lbl_8006D188(-18432);
    v3 = (*(f32 *)((u8 *)arg0 + 84) * t5);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v3)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 33, 1);
    t7 = lbl_8006D188(2048);
    v4 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v4 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t7);
    t8 = lbl_8006D188(-14336);
    v5 = (*(f32 *)((u8 *)arg0 + 84) * t8);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v5)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 36, 1);
    t10 = lbl_8006D188(6144);
    v6 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v6 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t10);
    t11 = lbl_8006D188(-10240);
    v7 = (*(f32 *)((u8 *)arg0 + 84) * t11);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v7)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 39, 1);
    fn_8007245C(8704);
    fn_80073678(5);
    fn_80074660(4);
    fn_800745A4(0, 1, 4, 30, 0, 125);
    fn_800745A4(1, 1, 4, 33, 0, 125);
    fn_800745A4(2, 1, 4, 36, 0, 125);
    fn_800745A4(3, 1, 4, 39, 0, 125);
    fn_80073C6C(0);
    fn_80073C6C(1);
    fn_80073C6C(2);
    fn_80073C6C(3);
    fn_80073C6C(4);
    fn_800734A8(0, 0, 0, 255);
    fn_800734A8(1, 1, 0, 255);
    fn_800734A8(2, 2, 0, 255);
    fn_800734A8(3, 3, 0, 255);
    fn_800734A8(4, 255, 255, 255);
    fn_80072C24(0, 15, 15, 15, 8);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80072C24(1, 15, 8, 12, 0);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 4, 7, 7, 0);
    fn_80072E20(1, 0, 0, 0, 1, 0);
    fn_80072C24(2, 15, 8, 12, 0);
    fn_80072D64(2, 0, 0, 0, 1, 0);
    fn_80072CC4(2, 4, 7, 7, 0);
    fn_80072E20(2, 0, 0, 0, 1, 0);
    fn_80072C24(3, 15, 8, 12, 0);
    fn_80072D64(3, 0, 0, 0, 1, 0);
    fn_80072CC4(3, 4, 7, 7, 0);
    fn_80072E20(3, 0, 0, 0, 1, 0);
    fn_80072C24(4, 15, 2, 0, 4);
    fn_80072D64(4, 0, 0, 0, 1, 0);
    fn_80072CC4(4, 7, 1, 0, 2);
    fn_80072E20(4, 0, 0, 0, 1, 0);
    fn_80074918(1, 3, 1);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_530C8 */

/* fzgx:begin fn_1_535A0 */
typedef struct FontParams_fn_1_535A0 {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams_fn_1_535A0;

typedef struct fn_1_4EB74_FontObject_fn_1_535A0 {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject_fn_1_535A0;

typedef struct fn_1_54668_node_fn_1_535A0 {
    struct fn_1_54668_node_fn_1_535A0 *next;
    void *data;
} fn_1_54668_node_fn_1_535A0;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_fn_1_535A0;

typedef struct fn_1_547F8_node_fn_1_535A0 {
    struct fn_1_547F8_node_fn_1_535A0 *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_535A0 *);
} fn_1_547F8_node_fn_1_535A0;

typedef struct fn_1_563E4_FontState_fn_1_535A0 {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState_fn_1_535A0;

typedef struct State_fn_1_535A0 {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State_fn_1_535A0;

typedef struct Config_fn_1_535A0 {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config_fn_1_535A0;

typedef struct ImageInfo_fn_1_535A0 {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo_fn_1_535A0;

typedef struct Images_fn_1_535A0 {
    u32 unk_0;
    ImageInfo_fn_1_535A0 *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images_fn_1_535A0;

typedef struct Resource_fn_1_535A0 {
    s32 loaded;
    u8 unk_4[0x1c];
    Images_fn_1_535A0 *images;
    u32 unk_24;
} Resource_fn_1_535A0;

struct fn_1_530C8_lbl_1_rodata_282C_fn_1_535A0 {
    f32 unk_0;
};

struct FzgxCopy_88_fn_1_535A0 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void OSReport(const char *format, ...);
extern u8 *lbl_801A66CC;
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);


typedef struct Fn1_535A0_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn1_535A0_Color;


/* font.h declares the packet colour as u8[4]; it holds a GXColor */
#define FN_1_535A0_COLOR(packet) (*(Fn1_535A0_Color *)(packet).color)

void fn_1_535A0(Fn1_535A0_Color color, f32 x, f32 y, f32 z, f32 width, f32 height, f32 thickness) {
    FontDrawPacket packet;

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= thickness / 8.0f;
    packet.scale_y *= height / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y + height;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    packet.flags = 0xD;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x + width;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= thickness / 8.0f;
    packet.scale_y *= height / 8.0f;
    packet.flags = 0x7;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_535A0 */

/* fzgx:begin fn_1_53830 noprologue */
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef float f32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.0f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table2[19] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    d = 4503599627370496.0;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table4[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[31] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
}
static const unsigned long fzgx_pool_table12[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 80.0f;
}
#pragma section code_type ".text"

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern u32 lbl_1_rodata_26F8_w138[1];
extern u32 lbl_1_rodata_26F8_w13c[1];

/* Volatile views preserve the order of color updates and pool reads. */
void fn_1_53830(u32 period, f32 x, u8 val, volatile u8 *a, volatile u8 *b) {
    u32 t = lbl_801A66A0 % period;
    f32 f;
    u8 c;
    if (t < period / 2) {
        f = lbl_8006D188((65536.0f * t / period));
        c = (val * f);
        a[2] = c;
        a[1] = c;
        a[0] = c;
        a[3] = 0;
        *(u32 *)b = *(volatile u32 *)fzgx_pool_table12; /* fzgx-allow: S2 ordered packed-color read after component stores */
    } else {
        f = lbl_8006D188((65536.0f * t / period));
        f = ((1.0f - x) * f);
        f = 1.0f + f;
        c = (255.0f * f);
        b[2] = c;
        b[1] = c;
        b[0] = c;
        b[3] = 0;
        *(u32 *)a = *(volatile u32 *)fzgx_pool_table13; /* fzgx-allow: S2 ordered packed-color read after component stores */
    }
}
/* fzgx:end fn_1_53830 */

/* fzgx:begin fn_1_539CC */
typedef struct FrameColor {
    u8 r, g, b, a;
} FrameColor;

#pragma fp_contract off
FrameColor fn_1_539CC(const FrameColor *a, const FrameColor *b, f32 t) {
    FrameColor color;
    color.r = a->r * t + b->r * ((lbl_1_rodata_2754) - t);
    color.g = a->g * t + b->g * ((lbl_1_rodata_2754) - t);
    color.b = a->b * t + b->b * ((lbl_1_rodata_2754) - t);
    color.a = a->a * t + b->a * ((lbl_1_rodata_2754) - t);
    return color;
}
/* fzgx:end fn_1_539CC */

/* fzgx:begin fn_1_53B14 noprologue */
#include "types.h"

extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10[7];
    f32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    s32 unk3C[7];
} Fn53B14Params;

/* retail .rodata block [lbl_1_rodata_26F8, +0x15C): the function copies the 0x58-byte
   record through the pool base and reads its constants at fixed displacements. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 8.0f;
}
#pragma section code_type ".text"

void fn_1_53B14(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
    Fn53B14Params params = *(const Fn53B14Params *)fzgx_pool_table1;

    params.unk0 = 12;
    params.unk4 = a;
    params.unk8 = b;
    params.unkC = e;
    if (color != NULL) {
        params.unk2C = color[3] / 255.0;
        params.unk38 = *(u32 *)color;
    }
    params.unk30 = 10;
    fn_1_50190(&params, c, d, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53B14 */

/* fzgx:begin fn_1_53BD8 noprologue */
#include "types.h"

extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10[7];
    f32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    s32 unk3C[7];
} Fn53BD8Params;

/* retail .rodata block [lbl_1_rodata_26F8, +0x164): the function copies the 0x58-byte
   record through the pool base and reads its constants at fixed displacements. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
static const u32 fzgx_pool_table4[1] = {
	0x41000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
	s = 13.0f;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
	volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
	s = 26.0f;
}
#pragma section code_type ".text"

void fn_1_53BD8(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
	Fn53BD8Params params = *(const Fn53BD8Params *)fzgx_pool_table1;

	params.unk0 = 2;
	params.unk4 = a;
	params.unk8 = b;
	params.unkC = e;
	if (color != NULL) {
		params.unk2C = ((f64)*(color + 3) / 255.0);
		params.unk38 = *(u32 *)color;
	}
	params.unk30 = 10;
	fn_1_50190(&params, c, d, 13.0f, 13.0f, 26.0f, 26.0f);
}
/* fzgx:end fn_1_53BD8 */

/* fzgx:begin fn_1_53C9C noprologue */
#include "dolphin/types.h"

#pragma pool_data on
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table2[24] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table4[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[31] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
}
static const unsigned long fzgx_pool_table12[2] = {0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 80.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 255.0;
    s = 8.0f;
    s = 13.0f;
    s = 26.0f;
    s = 0.009999999776482582f;
    d = 0.0005;
}
#pragma section code_type ".text"
typedef struct Pk {
    s32 a;
    f32 x, y, z;
    s32 pad1[7];
    f32 al;
    s32 b;
    s32 pad2;
    s32 col;
    s32 pad3[7];
} Pk;

extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(s32);
extern f32 fn_1_4B090(s32);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

void fn_1_53C9C(u8 *color, s32 id, f32 x, f32 y, f32 z, f32 s, f32 t)
{
    f32 s_local = s;
    Pk p;
    f32 tmp_call5;
    f32 a, b;
    if (z < 0.01f) {
        z = 0.01f;
    }
    fn_1_496FC(x, y);
    fn_1_4954C(z - 0.0005);
    fn_1_4955C(t, t);
    fn_1_495C8(9);
    fn_1_4A0D8((const char *)id);
    tmp_call5 = fn_1_4B068(id);
    a = tmp_call5;
    s_local = s_local * t;
    a = s_local + a;
    b = s_local + fn_1_4B090(id);
    p = *(const Pk *)fzgx_pool_table2;
    p.a = 12;
    p.x = x;
    p.y = y;
    p.z = z;
    if (color != 0) {
        p.al = color[3] / 255.0;
        p.col = *(s32 *)color;
    }
    p.b = 10;
    fn_1_50190(&p, a, b, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53C9C */

/* fzgx:begin fn_1_53E40 noprologue */
#include "types.h"

extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(const char *);
extern f32 fn_1_4B090(const char *);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
	u32 field_0;
	f32 field_4;
	f32 field_8;
	f32 field_c;
	u8 pad_10[0x1c];
	f32 field_2c;
	u32 field_30;
	u8 pad_34[4];
	u32 field_38;
	u8 pad_3c[0x1c];
} Record;

/* retail .rodata block [lbl_1_rodata_26F8, +0x170): the function reads the 0x58-byte
   record through the pool base, the share of the TU pool after it is baked below. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
static const u32 fzgx_pool_table4[1] = {
	0x41000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 13.0f;
	s = 26.0f;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 0.009999999776482582f;
	d = 0.0005;
}
#pragma section code_type ".text"

void fn_1_53E40(u8 *color, const char *name, f32 x, f32 y, f32 z, f32 w, f32 h)
{
	f32 total;
	f32 delta;

	if (z < 0.01f) {
		z = 0.01f;
	}
	fn_1_496FC(x, y);
	fn_1_4954C((z - 0.0005));
	fn_1_4955C(h, h);
	fn_1_495C8(9);
	fn_1_4A0D8(name);
	total = w * h + fn_1_4B068(name);
	delta = w * h + fn_1_4B090(name);

	{
		Record rec = *(const Record *)fzgx_pool_table1;

		rec.field_0 = 2;
		rec.field_4 = x;
		rec.field_8 = y;
		rec.field_c = z;
		if (color != 0) {
			rec.field_2c = (color[3] / 255.0);
			rec.field_38 = *(u32 *)color;
		}
		rec.field_30 = 10;

		fn_1_50190(&rec, total, delta, 13.0f, 13.0f, 26.0f, 26.0f);
	}
}
/* fzgx:end fn_1_53E40 */

/* fzgx:begin fn_1_53FE4 noprologue */
#include "font.h"

extern const struct fn_1_53FE4_lbl_1_rodata_2754_pool {
    f32 unk_0;
} lbl_1_rodata_2754;

extern const struct fn_1_53FE4_lbl_1_rodata_2868_pool {
    f32 unk_0;
} lbl_1_rodata_2868;
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

typedef struct {
    u32 p;
    u8 pad[0xC];
    f32 f10, f14, f18, f1c, f20, f24;
} Fn53Obj;

#pragma opt_propagation off
void fn_1_53FE4(Fn53Obj *arg, u8 idx) {
    u32 p;
    s16 h;
    s16 w;
    f32 iw;
    f32 ih;
    s16 x;
    s16 y;
    Fn53Obj *obj;
    obj = arg;
    p = obj->p;
    x = (idx % 10) * 20;
    y = (idx / 10) * 20;
    w = fn_1_486C4(p);
    h = fn_1_48690(p);
    ih = lbl_1_rodata_2754.unk_0 / h;
    iw = lbl_1_rodata_2754.unk_0 / w;
    obj->f10 = obj->f10 * (lbl_1_rodata_2868.unk_0 * ih);
    obj->f14 = obj->f14 * (lbl_1_rodata_2868.unk_0 * iw);
    obj->f18 = x * ih;
    obj->f1c = y * iw;
    obj->f20 = ih * (x + 20);
    obj->f24 = iw * (y + 20);
    fn_1_4F734((FontDrawPacket *)obj);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_53FE4 */

/* fzgx:begin fn_1_5415C noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_5489C(void **arg0, void **arg1);
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);

void fn_1_5415C(void *arg, s32 value) {
    fn_1_541A8(arg, value);
}
/* fzgx:end fn_1_5415C */

/* fzgx:begin fn_1_5417C noprologue */
void fn_1_5417C(void *arg) {
    fn_1_541A8(arg, lbl_801A66B4);
}
/* fzgx:end fn_1_5417C */

/* fzgx:begin fn_1_541A8 noprologue */
// Select the localized form for a number and column, including the special 10–20 range.
void *fn_1_541A8(void *arg, s32 column) {
    s32 is_special;
    u32 remainder;
    s32 row_index;
    u32 *row;
    u32 number = (u32)arg;

    if (number == 0) {
        return &lbl_1_data_1C5DC;
    }

    remainder = number - (number / 100) * 100;
    is_special = 0;
    if (remainder >= 10 && remainder <= 20) {
        is_special = 1;
    }

    if (is_special != 0) {
        row_index = 3;
    } else {
        number = remainder - (remainder / 10) * 10;
        is_special = 0;
        if (number >= 4 || number == 0) {
            is_special = 1;
        }
        row_index = 3;
        if (is_special == 0) {
            row_index = number - 1;
        }
    }

    row = (u32 *)(lbl_1_data_1C5EC + row_index * 24);
    return (void *)row[column < 0 ? 0 : (column > 5 ? 5 : column)];
}
/* fzgx:end fn_1_541A8 */

/* fzgx:begin fn_1_54278 noprologue */
void fn_1_54278(u32 arg0, u32 arg1) {
    lbl_1_bss_4C680 = arg0;
    lbl_1_bss_4C684 = arg1;
}
/* fzgx:end fn_1_54278 */

/* fzgx:begin fn_1_5428C noprologue */
void fn_1_5428C(f32 value) {
    lbl_1_data_1C508.unk_0 = value;
}
/* fzgx:end fn_1_5428C */

/* fzgx:begin fn_1_54298 noprologue */
u32 fn_1_54298(void) {
    return lbl_1_bss_4C680;
}
/* fzgx:end fn_1_54298 */

/* fzgx:begin fn_1_542A8 noprologue */
u32 fn_1_542A8(void) {
    return lbl_1_bss_4C684;
}
/* fzgx:end fn_1_542A8 */

/* fzgx:begin fn_1_542B8 noprologue */
f32 fn_1_542B8(void) {
    return lbl_1_data_1C508.unk_0;
}
/* fzgx:end fn_1_542B8 */
