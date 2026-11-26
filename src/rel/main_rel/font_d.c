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
extern void fn_80072558(void);
extern void fn_800720B0(int);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern u8 *lbl_801A66CC;
extern void lbl_8006E1B0();
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);

/* fzgx:begin fn_1_549F4 noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Angles;

typedef struct {
    f32 s;
    f32 c;
} Vec2;

typedef struct {
    u8 pad_0[0x50];
    Vec3 v50;
    Vec3 aim[4];
    Vec3 dir[4];
    Angles rot;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
} State;

typedef struct {
    f32 zero;
    f32 deg;
    f32 half;
    f32 pad_c;
    f64 one;
    f64 degd;
    f64 halfd;
} K;

extern State *lbl_801A66CC;
extern K lbl_1_rodata_2880;
extern f32 lbl_8006D21C(s32);
extern s16 lbl_8006D2AC(f32);
extern void lbl_8006D7DC(Vec3 *);
extern u32 mathutil_mtxA_rotate_x(s32);
extern u32 mathutil_mtxA_rotate_y(s32);
extern u32 mathutil_mtxA_rotate_z(s32);
extern void lbl_8006D1B8(s16, Vec2 *);
extern void lbl_8006E1C0(Vec3 *, Vec3 *);

void fn_1_549F4(Vec3 *arg0, Angles *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 fzgx_live_;
    f32 h;
    K *p = (K *)&lbl_1_rodata_2880;
    s16 t1, t2;
    Angles *a1 = arg1;
    Vec3 *a0 = arg0;
    s16 t3, t4;
    Vec2 v;

    lbl_801A66CC->v50 = *a0;
    lbl_801A66CC->rot = *a1;
    lbl_801A66CC->f1 = arg2;
    lbl_801A66CC->f2 = arg3;
    lbl_801A66CC->f3 = arg4;
    lbl_801A66CC->f4 = arg5;

    if ((0.0f) == arg5) {
        s32 t = (s16)((182.044449f) * arg2);
        t1 = -t / 2;
        t2 = t / 2;
    } else {
        h = lbl_8006D21C(((182.044449f) * ((0.5f) * arg2)));
        t1 = -lbl_8006D2AC(h * ((1.0) - arg5));
        t2 = lbl_8006D2AC(h * ((1.0) + arg5));
    }

    if ((0.0f) == arg4) {
        s16 x = lbl_8006D2AC(arg3 * lbl_8006D21C(((182.04444885253906) * ((0.5) * arg2))));
        s32 t = (s16)(x * 2);
        t3 = t / 2;
        t4 = -t / 2;
    } else {
        f32 s;
        if ((0.0f) == arg5) {
            s = arg3 * lbl_8006D21C(((182.044449f) * ((0.5f) * arg2)));
        } else {
            s = h * arg3;
        }
        t3 = lbl_8006D2AC(s * ((1.0) + arg4));
        t4 = -lbl_8006D2AC(s * ((1.0) - arg4));
    }

    lbl_8006D7DC(a0);
    mathutil_mtxA_rotate_y(a1->y);
    mathutil_mtxA_rotate_x(a1->x);
    mathutil_mtxA_rotate_z(a1->z);

    lbl_8006D1B8((t3 - 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[0].x = -fzgx_live_;
    lbl_801A66CC->dir[0].y = (0.0f);
    lbl_801A66CC->dir[0].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[0], &lbl_801A66CC->aim[0]);

    lbl_8006D1B8((t4 + 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[1].x = -fzgx_live_;
    lbl_801A66CC->dir[1].y = (0.0f);
    lbl_801A66CC->dir[1].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[1], &lbl_801A66CC->aim[1]);

    lbl_8006D1B8((t1 + 0x4000), &v);
    lbl_801A66CC->dir[2].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[2].y = -fzgx_live_;
    lbl_801A66CC->dir[2].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[2], &lbl_801A66CC->aim[2]);

    lbl_8006D1B8((t2 - 0x4000), &v);
    lbl_801A66CC->dir[3].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[3].y = -fzgx_live_;
    lbl_801A66CC->dir[3].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[3], &lbl_801A66CC->aim[3]);
}
/* fzgx:end fn_1_549F4 */

/* fzgx:begin fn_1_54DCC */
void fn_1_54DCC(u8 *data) {
    fn_800794F0(data, lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_54DCC */

/* fzgx:begin fn_1_54E00 */
void fn_1_54E00(void *value) {
    fn_800794F0(lbl_801A66CC + 0x50, value, 0x84);
}
/* fzgx:end fn_1_54E00 */

/* fzgx:begin fn_1_54E34 */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
} Fn154E34Data;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vector;



s32 fn_1_54E34(void *arg0, f32 arg1) {
    Vector vector;
    Fn154E34Data *data;
    f32 *p;
    f32 x;
    f32 y;
    f32 z;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    lbl_8006E1B0(arg0, &vector, arg1);
    z = vector.z;
    x = vector.x;
    y = vector.y;
    if (z > arg1) {
        return 0;
    }
    arg1 = -arg1;
    data = (Fn154E34Data *)(*(void * *)&lbl_801A66CC);
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = x * p[0];
        m1 = y * p[1];
        m2 = z * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54E34 */

/* fzgx:begin fn_1_54F5C */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
    u8 pad_bc[0x18];
    f32 value_d4;
    f32 value_d8;
    f32 value_dc;
} Fn154F5CData;



s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2) {
    Fn154F5CData *data;
    f32 *p;
    f32 d4;
    f32 d8;
    f32 dc;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    lbl_8006E1B0(arg0, (Vec3 *)(&data->value_d4));
    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    arg1 = arg1 * arg2;
    dc = data->value_dc;
    if (dc > arg1) {
        return 0;
    }
    d4 = data->value_d4;
    d8 = data->value_d8;
    arg1 = -arg1;
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = d4 * p[0];
        m1 = d8 * p[1];
        m2 = dc * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54F5C */

/* fzgx:begin fn_1_550A8 */
void fn_1_550A8(void) {
    fn_800794F0(lbl_1_bss_6C710, lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_550A8 */

/* fzgx:begin fn_1_550E0 */
void fn_1_550E0(void) {
    fn_800794F0(lbl_801A66CC + 0x50, lbl_1_bss_6C710, 0x84);
}
/* fzgx:end fn_1_550E0 */
