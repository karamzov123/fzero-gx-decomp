#include "types.h"
#include "game/pad.h"

/* car_test.c: the machine test scene (main.rel, one translation unit) */

typedef struct GXColor {
    u8 r, g, b, a;
} GXColor;

typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

/* one model of a machine */
typedef struct CarModel {
    u8 pad_0[8];
    Vec3 center;
    f32 radius;
    u16 ntex;
} CarModel;

typedef struct CarModelEntry {
    u32 unk_0;
    char *name;
} CarModelEntry;

typedef struct CarModelInfo {
    s32 count;
    CarModel *model;
    CarModelEntry *entries;
} CarModelInfo;

/* one level of detail of a machine */
typedef struct CarLod {
    CarModel **models;
    CarModelInfo *info;
    u32 unk_8;
} CarLod;

typedef struct CarTex {
    u32 flags;
    u32 unk_4;
    u16 width;
    u16 height;
    u16 max_lod;
    u16 pad_e;
} CarTex;

typedef struct CarTexList {
    u32 count;
    CarTex *items;
} CarTexList;

/* the body state of a machine (0x620 bytes) */
typedef struct CarBody {
    u8 pad_0[4];
    s16 index;
    u16 unk_6;
    u8 pad_8[0x74];
    Vec3 pos;
    u8 pad_88[0xC4];
    f32 mtx[3][4];
    u8 pad_17C[8];
    f32 unk_184;
    u8 pad_188[0x498];
} CarBody;

/* one machine (0x440 bytes) */
typedef struct Car {
    u8 pad_0[2];
    s8 limit;
    u8 pad_3[0x325];
    s8 kind;
    u8 pad_329[3];
    CarBody *body;
    u8 *parts;
    CarLod lods[6];
    CarTexList *tex[4];
    u8 lod_mask;
    u8 pad_38D[0x2B];
    s16 cv;
    s16 lod;
    u8 pad_3BC[0x84];
} Car;

/* one light of the test scene (0xC bytes) */
typedef struct CarTestLight {
    u8 *color;
    f32 distance;
    s16 rot_x;
    s16 rot_y;
} CarTestLight;

/* the state of the test scene (0x2C bytes) */
typedef struct CarTest {
    Car *cars;
    s8 sel;
    s8 channel;
    s8 mode;
    s8 car;
    s8 model;
    u8 pad_9[3];
    u32 *disp_masks;
    char **mode_names;
    char **mode_help;
    u8 *bg_color;
    CarTestLight *lights;
    u32 flags;
    s8 lod;
    u8 lod_level[5];
} CarTest;

extern void *lbl_801A6410;

extern void *memset(void *dst, int value, u32 size);

void fn_1_7C13C(Car *cars);
void fn_1_7C1E8(CarTestLight *lights);

typedef struct Line3 {
    Vec3 a;
    Vec3 b;
} Line3;


extern void fn_80008BEC(void *, int, u32);

/* one pad's button words */
typedef struct PadInput {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
} PadInput;

extern PadInput lbl_1_bss_9F8[4];
extern char *lbl_1_data_1F318[];


extern void fn_1_7F954(void *, s32);
extern void fn_1_49614(void);
extern void fn_80071ED4(s32, f32, f32);
extern void fn_80072014(void *);
extern void fn_800720B0(s32);
extern void fn_1_5634C(u32);
extern void fn_1_12AB38(const char *);
extern void *fn_1_45D0(void *, s32, const char *, s32);
extern void fn_1_80F80(void *, u8, void *);
extern void fn_1_1502BC(void *, void *, void *);
extern void strcpy(void *, u32);
extern void fn_1_801F8(s16, void *);
void fn_1_7ECB8(void *arg0, u32 arg1, u32 arg2, f32 arg3);

/* degrees to the 0x10000-per-turn angle unit; folds to an int constant (315 gives 0xE000) */
#define DEG_TO_S16(deg) ((s16)(182.04445f * (deg)))

typedef struct GXLightObj {
    u32 dummy[16];
} GXLightObj;

typedef struct BgState {
    u8 pad_0[0x8];
    struct {
        u8 pad_0[0x20];
        void *unk_20;
    } *unk_8;
} BgState;

extern BgState *lbl_1_bss_38454;

/* fzgx:begin fn_1_7E8F4 */
#include "types.h"
#define lbl_1_bss_9F8 _h_9F8
#define lbl_1_bss_38454 _h_38454
#define lbl_1_data_1F318 _h_1F318
#include "rel/main_rel/globals.h"
#undef lbl_1_bss_9F8
#undef lbl_1_bss_38454
#undef lbl_1_data_1F318
#define lbl_1_bss_6D7E8 _h_6D7E8
#include "rel/main_rel/car_test.h"
#undef lbl_1_bss_6D7E8

extern void fn_1_5634C(u32 arg0);
extern void *lbl_801A6410;
extern const f64 lbl_1_rodata_3588;
extern void fn_1_12AB38(const char *);
extern void *fn_1_45D0(void *, s32, const char *, s32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_80F80(void *, u8, void *);
extern void fn_1_1502BC(void *, void *, void *);

extern void strcpy(void* arg0, u32 arg1);
extern void fn_1_801F8(s16 arg0, void* arg1);
extern const f32 lbl_1_rodata_33AC;
extern const f32 lbl_1_rodata_33B0[84];
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_7F954(void *arg0, s32 arg1);
extern void fn_1_49614(void);
extern const f32 lbl_1_rodata_33A8;
extern void fn_80071ED4(s32 arg0, f32 arg1, f32 arg2);
extern void fn_80072014(void *arg0);
extern void fn_800720B0(s32 arg0);

extern void fn_1_5634C(u32 arg0);
extern void *lbl_801A6410;
extern const f64 lbl_1_rodata_3588;
extern void fn_1_12AB38(const char *);
extern void *fn_1_45D0(void *, s32, const char *, s32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_80F80(void *, u8, void *);
extern void fn_1_1502BC(void *, void *, void *);

extern void strcpy(void* arg0, u32 arg1);
extern void fn_1_801F8(s16 arg0, void* arg1);
extern const f32 lbl_1_rodata_33AC;
extern const f32 lbl_1_rodata_33B0[84];
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_7F954(void *arg0, s32 arg1);
extern void fn_1_49614(void);
extern const f32 lbl_1_rodata_33A8;
extern void fn_80071ED4(s32 arg0, f32 arg1, f32 arg2);
extern void fn_80072014(void *arg0);
extern void fn_800720B0(s32 arg0);

extern const f32 lbl_1_rodata_3500;
extern const f32 lbl_1_rodata_3504;

typedef struct lbl_1_bss_6D620_t {
    u8 unk_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u32 unk_10;
    u8 pad_14[0x124];
} lbl_1_bss_6D620_t;

typedef struct lbl_1_bss_6D7F4_t {
    u8 unk_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    u8 pad_10[0x1c];
} lbl_1_bss_6D7F4_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_6D620_t fzgx_obj_lbl_1_bss_6D620;
extern u32 lbl_1_bss_6D758[6];
lbl_1_bss_6D7F4_t fzgx_obj_lbl_1_bss_6D7F4;

#pragma opt_propagation off
void fn_1_7E8F4(void) {
    f32 fzgx_live;
    s32 sel = 0;
    lbl_1_bss_6D7F0 = sel;
    if (lbl_1_bss_3BE0 != 0) {
        if ((s8)fzgx_obj_lbl_1_bss_6D620.unk_F != 0 || (s32)fzgx_obj_lbl_1_bss_6D620.unk_10 < 0x20) {
            sel = 1;
        }
        fzgx_obj_lbl_1_bss_6D7F4.unk_F = sel != 0;
        fzgx_obj_lbl_1_bss_6D7F4.unk_0 = fzgx_obj_lbl_1_bss_6D620.unk_0;
        fzgx_live = fzgx_obj_lbl_1_bss_6D620.unk_4;
        fzgx_obj_lbl_1_bss_6D7F4.unk_4 = fzgx_live;
        fzgx_obj_lbl_1_bss_6D7F4.unk_8 = fzgx_obj_lbl_1_bss_6D620.unk_8;
        fzgx_obj_lbl_1_bss_6D7F4.unk_C = fzgx_obj_lbl_1_bss_6D620.unk_C;
        fzgx_obj_lbl_1_bss_6D7F4.unk_D = fzgx_obj_lbl_1_bss_6D620.unk_D;
        fzgx_obj_lbl_1_bss_6D7F4.unk_E = fzgx_obj_lbl_1_bss_6D620.unk_E;
    } else {
        fzgx_obj_lbl_1_bss_6D7F4.unk_F = sel;
        fzgx_obj_lbl_1_bss_6D7F4.unk_0 = 5;
        fzgx_obj_lbl_1_bss_6D7F4.unk_4 = lbl_1_rodata_3500;
        fzgx_obj_lbl_1_bss_6D7F4.unk_8 = lbl_1_rodata_3504;
        fzgx_obj_lbl_1_bss_6D7F4.unk_C = sel;
        fzgx_obj_lbl_1_bss_6D7F4.unk_D = sel;
        fzgx_obj_lbl_1_bss_6D7F4.unk_E = sel;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_7E8F4 */

/* fzgx:begin fn_1_7E9C4 */
#include "types.h"
#define lbl_1_bss_9F8 _h_9F8
#define lbl_1_bss_38454 _h_38454
#define lbl_1_data_1F318 _h_1F318
#include "rel/main_rel/globals.h"
#undef lbl_1_bss_9F8
#undef lbl_1_bss_38454
#undef lbl_1_data_1F318
#define lbl_1_bss_6D7E8 _h_6D7E8
#include "rel/main_rel/car_test.h"
#undef lbl_1_bss_6D7E8

extern u32 fn_1_5910(void);
extern void fn_1_5634C(u32 arg0);
extern void fn_1_5635C(s32 arg0, f32 arg1, f32 arg2);
extern void fn_1_56374(u8 arg0, u8 arg1, u8 arg2);
extern void fn_1_7EB0C(void);

typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    s32 unk_10;
    s32 unk_14;
} Entry7E9C4;

typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
} Cur7E9C4;


void fn_1_7E9C4(void) {
    s32 sel;
    if (lbl_1_bss_3BE0 != 0 && (s8)lbl_1_bss_6D7F0 == 0) {
        u32 off;

        off = fn_1_5910() * 0x18;
        sel = 0;
        if (*((s8 *)&lbl_1_bss_6D620 + off + 0xF) != 0 ||
            *(s32 *)((s8 *)&lbl_1_bss_6D620 + off + 0x10) < 0x20) {
            sel = 1;
        }
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_F = sel != 0;
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_0 = ((u8 *)&lbl_1_bss_6D620)[off];
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_4 = *(f32 *)((u8 *)&lbl_1_bss_6D620 + off + 0x4);
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_8 = *(f32 *)((((off) + (0x8)) + ((u8 *)&lbl_1_bss_6D620)));
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_C = *((u8 *)&lbl_1_bss_6D620 + off + 0xC);
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_D = *((u8 *)&lbl_1_bss_6D620 + off + 0xD);
        ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_E = *((u8 *)&lbl_1_bss_6D620 + off + 0xE);
    }

    fn_1_5634C(((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_F);
    if (((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_F != 0) {
        fn_1_5635C(((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_0,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_4,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_8);
        fn_1_56374(((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_C,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_D,
                   ((Cur7E9C4 *)&lbl_1_bss_6D7F4)->unk_E);
    }
    fn_1_7EB0C();
}
/* fzgx:end fn_1_7E9C4 */

/* fzgx:begin fn_1_7EAE8 */
extern void *lbl_801A6410;
extern const f64 lbl_1_rodata_3588;

extern const f32 lbl_1_rodata_33AC;
extern const f32 lbl_1_rodata_33B0[84];
extern void *memset(void *dst, int value, u32 size);
extern const f32 lbl_1_rodata_33A8;

// fn_1_7EAE8: main_rel .text:0x0007EAE8 size 0x24
// Wrapper that calls fn_1_5634C with argument 0.

void fn_1_7EAE8(void) {
    fn_1_5634C(0);
}
/* fzgx:end fn_1_7EAE8 */

/* fzgx:begin fn_1_7EB0C */
#include "types.h"
#define lbl_1_bss_9F8 _h_9F8
#define lbl_1_bss_38454 _h_38454
#define lbl_1_data_1F318 _h_1F318
#include "rel/main_rel/globals.h"
#undef lbl_1_bss_9F8
#undef lbl_1_bss_38454
#undef lbl_1_data_1F318
#define lbl_1_bss_6D7E8 _h_6D7E8
#include "rel/main_rel/car_test.h"
#undef lbl_1_bss_6D7E8

extern void fn_1_5634C(u32 arg0);
extern void *lbl_801A6410;
extern const f64 lbl_1_rodata_3588;
extern void fn_1_12AB38(const char *);
extern void *fn_1_45D0(void *, s32, const char *, s32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_80F80(void *, u8, void *);
extern void fn_1_1502BC(void *, void *, void *);

extern void strcpy(void* arg0, u32 arg1);
extern void fn_1_801F8(s16 arg0, void* arg1);
extern const f32 lbl_1_rodata_33AC;
extern const f32 lbl_1_rodata_33B0[84];
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_7F954(void *arg0, s32 arg1);
extern void fn_1_49614(void);
extern const f32 lbl_1_rodata_33A8;
extern void fn_80071ED4(s32 arg0, f32 arg1, f32 arg2);
extern void fn_80072014(void *arg0);
extern void fn_800720B0(s32 arg0);

typedef struct {
    s8 unk_0;
} SignedByteView;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
} LocalBytes;

void fn_1_7EB0C(void) {
    LocalBytes local0;
    LocalBytes local1;

    local0.unk_0 = lbl_1_bss_6D7F4.unk_C;
    local0.unk_1 = lbl_1_bss_6D7F4.unk_D;
    local0.unk_2 = lbl_1_bss_6D7F4.unk_E;
    if ((s8)lbl_1_bss_6D7F4.unk_F != 0) {
        fn_80071ED4(((SignedByteView *)&lbl_1_bss_6D7F4)->unk_0 + 0,
                    lbl_1_bss_6D7F4.unk_4,
                    lbl_1_bss_6D7F4.unk_8);
        local1 = local0;
        fn_80072014(&local1);
        fn_800720B0(1);
    } else {
        fn_800720B0(0);
    }
}
/* fzgx:end fn_1_7EB0C */
