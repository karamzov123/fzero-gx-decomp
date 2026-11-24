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

extern void *fn_1_4630(void *heap, u32 size, const char *file, u32 line);
extern void *fn_800793D4(void *dst, int value, u32 size);
extern void *memset(void *dst, int value, u32 size);
extern s8 fn_1_816E8(Car *car, s8 lod);
extern void fn_1_495D8(s32, s32, f32);
extern void fn_1_495FC(void);

void fn_1_7C13C(Car *cars);
void fn_1_7C1E8(CarTestLight *lights);

typedef struct Line3 {
    Vec3 a;
    Vec3 b;
} Line3;

extern u32 lbl_801A66A0;

extern u32 fn_1_3C18(u32);
extern void fn_1_3BDC(u32);
extern void fn_1_55210(void *);
extern void fn_1_57714(s32);
extern void fn_1_5773C(Vec3 *, Vec3 *, GXColor *);
extern void fn_1_87238(Car *, s8, f32);
extern void fn_1_87610(Car *, Car *);
extern void fn_1_A77DC(Car *);
extern void fn_1_A7854(Car *, void *);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EB0(int, int);
extern void fn_1_A8EF8(u16, u16);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80072558(void);
extern void fn_80074D68(f32, f32, f32);
extern void fn_80074D78(u32);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DAEC(void);
extern u32 lbl_8006DB74();
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DCA4(void);
extern u32 lbl_8006DFC4();
extern void lbl_8006E0A4();
extern void mathutil_mtxA_rotate_y(s32 angle);
extern char *strstr(char *, const char *);

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

extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(GXColor *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_8CB78(CarTexList *);
extern void fn_1_8CC04(CarModel *, u8, s16, s16, u32, f32);
extern u32 fn_80077D40(CarTexList *);
extern u32 fn_80077BD4(CarModelInfo *);

extern void fn_1_7F954(void *, s32);
extern void fn_1_49614(void);
extern void fn_1_46B4(void *heap, void *ptr, const char *file, s32 line);
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

extern u32 lbl_801A6CE0;
extern BgState *lbl_1_bss_38454;

extern void lbl_8006D758(void);
extern void lbl_8006E1B0(Vec3 *src, Vec3 *dst);
extern void mathutil_mtxA_rotate_z(s32 angle);
extern void fn_1_57720(s32, s32, s32, s32);
extern void fn_1_57810(s32 n, Vec3 *pts, GXColor *c);
extern void fn_80077F8C(void *);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void fn_1_7BCCC(Vec3 *v);
extern void fn_80035680(GXLightObj *lt, f32 x, f32 y, f32 z);
extern void fn_80035690(GXLightObj *lt, f32 x, f32 y, f32 z);
extern void fn_80035420(GXLightObj *lt, f32 cutoff, s32 fn);
extern void fn_800356AC(GXLightObj *lt, GXColor *c);
extern void GXInitLightDistAttn(GXLightObj *lt, f32 ref_dist, f32 ref_br, s32 fn);
extern void fn_1_7BB80(GXLightObj *lt, s32 id);
extern void fn_1_7BD6C(s32);
extern void fn_80074CF4(f32 r, f32 g, f32 b);

/* fzgx:begin fn_1_7BF9C */
static char *mode_names[6] = {"CAR_TESTTOP", "CAR_SELECT", "CAR_CHECK", "LIGHT_CHG", "BGCOL_CHG", "ALL_DISP"};
static char *mode_help[6] = {"(Menu:exit)", "(A:Check)\n(B:Top)", "(B:Select)", "(B:Top)", "(B:Top)", "(B:Top)"};

CarTest *lbl_1_bss_6D7E8;

// Initialize the shared light state and its required resources.
void fn_1_7BF9C(Car *cars, s8 flag) {
    u8 *bg_color;
    CarTestLight *lights;
    u32 *masks;

    lbl_1_bss_6D7E8 = fn_1_4630(lbl_801A6410, sizeof(CarTest), "car_test.c", 51);
    bg_color = fn_1_4630(lbl_801A6410, 4, "car_test.c", 52);
    lights = fn_1_4630(lbl_801A6410, 2 * sizeof(CarTestLight), "car_test.c", 53);
    masks = fn_1_4630(lbl_801A6410, 41 * sizeof(u32), "car_test.c", 54);
    fn_800793D4(masks, 0xFF, 41 * sizeof(u32));
    fn_1_7C13C(cars);
    fn_1_7C1E8(lights);
    lbl_1_bss_6D7E8->cars = cars;
    lbl_1_bss_6D7E8->sel = 2;
    lbl_1_bss_6D7E8->mode = 2;
    lbl_1_bss_6D7E8->lod = 0;
    lbl_1_bss_6D7E8->model = fn_1_816E8(lbl_1_bss_6D7E8->cars + lbl_1_bss_6D7E8->car, lbl_1_bss_6D7E8->lod);
    lbl_1_bss_6D7E8->disp_masks = masks;
    lbl_1_bss_6D7E8->mode_names = mode_names;
    lbl_1_bss_6D7E8->mode_help = mode_help;
    lbl_1_bss_6D7E8->bg_color = bg_color;
    lbl_1_bss_6D7E8->lights = lights;
    if (flag == 0) {
        lbl_1_bss_6D7E8->flags |= 0x40000000;
    }
    fn_1_495D8(2, 2, 1.0f);
    fn_1_495FC();
}
/* fzgx:end fn_1_7BF9C */

/* fzgx:begin fn_1_7C13C */
void fn_1_7C13C(Car *cars) {
    f32 unk_184;
    Car *car;
    int i;

    unk_184 = 100.0f;
    car = cars;
    for (i = 0; i < 41; i++) {
        car->body = fn_1_4630(lbl_801A6410, sizeof(CarBody), "car_test.c", 88);
        car->body->unk_6 = i;
        car->body->index = i;
        car->body->unk_184 = unk_184;
        car++;
    }
}
/* fzgx:end fn_1_7C13C */

/* fzgx:begin fn_1_7C1E8 */
void fn_1_7C1E8(CarTestLight *lights) {
    CarTestLight *light;
    s8 i;

    light = lights;
    for (i = 0; i < 2; i++) {
        light->color = fn_1_4630(lbl_801A6410, 4, "car_test.c", 104);
        memset(light->color, 0xFF, 4);
        light->distance = 17.320507f;
        light->rot_x = DEG_TO_S16(315);
        light->rot_y = DEG_TO_S16(45);
        light++;
    }
}
/* fzgx:end fn_1_7C1E8 */

/* fzgx:begin fn_1_7C2A0 */
/* The model and texture statistics of the selected machine. MWCC inlines the two functions in
   fn_1_7C7CC and the link removes these copies. Their strings are made here: they are in .data
   after "car_test.c" and before the strings of fn_1_7C2A0. */
static void disp_model_info(CarTest *test, CarModelInfo *info) {
    s8 n;
    s8 i;
    s8 m;
    CarModel *model;

    n = info->count;
    fn_1_A8EB0(20, 10);
    if (lbl_1_bss_6D7E8->model == n) {
        m = info->count;
        fn_1_A8DD4("nmodel    :%d\n", info->count);
        for (i = 0; i < m; i++) {
            fn_1_A8DD4("%s\n", info->entries[i].name);
        }
        model = info->model;
        fn_1_A8DD4("center    :%2.2f %2.2f %2.2f\n", model->center.x, model->center.y, model->center.z);
        fn_1_A8DD4("radius    :%2.2f\n", model->radius);
        fn_1_A8DD4("ntex      :%d\n", model->ntex);
    } else {
        model = test->cars[test->car].lods[test->lod].models[test->model];
        fn_1_A8DD4("center    :%2.2f %2.2f %2.2f\n", model->center.x, model->center.y, model->center.z);
        fn_1_A8DD4("radius    :%2.2f\n", model->radius);
        fn_1_A8DD4("ntex      :%d\n", model->ntex);
    }
}

static void disp_tex_info(CarTexList *tex) {
    s8 i;

    fn_1_A8EB0(20, 10);
    fn_1_A8DD4("ntex      :%d\n", tex->count);
    for (i = 0; i < tex->count; i++) {
        fn_1_A8DD4("tex[%2d] ", i);
        fn_1_A8DD4("%3dx%3d mip%d\n", tex->items[i].width, tex->items[i].height, tex->items[i].max_lod);
    }
}

void fn_1_7C2A0(Car *car) {
    s8 count;
    Line3 l0, l1, l2;
    s16 i, k;

    if (lbl_1_bss_6D7E8->flags & 0x40000000) {
        return;
    }
    count = car->lods[lbl_1_bss_6D7E8->lod].info->count;
    if (car->body->index == lbl_1_bss_6D7E8->car || lbl_1_bss_6D7E8->mode == 5) {
        lbl_8006DAEC();
        lbl_8006DCA4();
        {
            GXColor c0 = {0x00, 0xFF, 0x00, 0xFF};
            GXColor c1 = {0x00, 0xFF, 0x00, 0xFF};
            GXColor c2 = {0x00, 0xFF, 0x00, 0xFF};

            fn_80008BEC(&l0, 0, sizeof(Line3));
            fn_80008BEC(&l1, 0, sizeof(Line3));
            fn_80008BEC(&l2, 0, sizeof(Line3));
            l0.a.x = -100.0f;
            l0.b.x = 100.0f;
            l1.a.y = -100.0f;
            l1.b.y = 100.0f;
            l2.a.z = -100.0f;
            l2.b.z = 100.0f;
            fn_1_57714(2);
            fn_80072558();
            fn_1_5773C(&l0.a, &l0.b, &c0);
            fn_1_5773C(&l1.a, &l1.b, &c1);
            fn_1_5773C(&l2.a, &l2.b, &c2);
        }
        if (lbl_1_bss_6D7E8->mode == 5) {
            s8 v = car->body->index;
            f32 t0 = 6.0f * (v % 2);
            f32 t1 = 6.0f * (v / 2);
            car->body->pos.x = 3.0f - t0;
            car->body->pos.z = -3.0f + t1;
        }
        lbl_8006E0A4(&car->body->pos);
        if (lbl_1_bss_6D7E8->mode == 5) {
            mathutil_mtxA_rotate_y((182.044449f * (lbl_801A66A0 % 360)));
        }
        {
            u8 *c = lbl_1_bss_6D7E8->lights->color;
            fn_80074D68(c[0] / 255.0f, c[1] / 255.0f, c[2] / 255.0f);
        }
        fn_80074D78((u32)__cntlzw(lbl_1_bss_6D7E8->flags & 0x80000000) >> 5);
        lbl_8006DAEC();
        lbl_8006D7DC(&car->body->pos);
        lbl_8006DB74(car->body->mtx);
        fn_1_A77DC(car);
        fn_1_A7854(car, NULL);
        lbl_8006DB30();
        car->lod = lbl_1_bss_6D7E8->lod;
        fn_1_3BDC(3);
        if (lbl_1_bss_6D7E8->model == count) {
            i = 0;
            k = 0;
            for (; i < count; i++) {
                if (((1 << i) & lbl_1_bss_6D7E8->disp_masks[lbl_1_bss_6D7E8->car]) && i != 0) {
                    if ((s16)k > car->limit - 1) {
                        break;
                    }
                    if (strstr(car->lods[lbl_1_bss_6D7E8->lod].info->entries[i].name, "pos_")
                        != car->lods[lbl_1_bss_6D7E8->lod].info->entries[i].name) {
                        if (car->lods[lbl_1_bss_6D7E8->lod].models[i] == NULL) {
                            k++;
                        } else {
                            lbl_8006DAEC();
                            if (car->parts != NULL) {
                                fn_1_87610(car, car);
                                lbl_8006DBE4();
                                lbl_8006DFC4(car->parts + k * 0x30);
                                fn_80072558();
                                fn_1_55210(car->lods[lbl_1_bss_6D7E8->lod].models[i]);
                            }
                            lbl_8006DB30();
                            k++;
                        }
                    }
                }
            }
            fn_80072558();
            fn_1_87238(car, lbl_1_bss_6D7E8->lod, 1.0f);
        } else {
            fn_80072558();
            fn_1_55210(car->lods[lbl_1_bss_6D7E8->lod].models[lbl_1_bss_6D7E8->model]);
        }
        {
            s16 r = fn_1_3C18(3);
            fn_1_A8EF8(0x140, 0x190);
            fn_1_A8DD4("cpu:%d\n", r);
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_7C2A0 */

/* fzgx:begin fn_1_7C7CC */
void fn_1_7C7CC(CarTest *test) {
    s8 car = test->car;
    s8 i;

    if (test->flags & 0x40000000) {
        fn_1_496FC(160.0f, 100.0f);
        fn_1_4AE0C("\x82\xad\x82\xe9\x82\xdc\x83\x54\x83\x43\x83\x59\x82\xaa\x82\xa8\x82\xa8\x82\xab\x82\xb7\x82\xac\x82\xc4\x83\x71\x81\x5b\x83\x76\n"
                   "\x82\xb1\x82\xa6\x82\xbf\x82\xe1\x82\xa2\x82\xdc\x82\xb5\x82\xbd\x81\x49\n");
        return;
    }
    if ((lbl_1_bss_9F8[1].unk_0 >> 11) & 1) {
        s8 lod;
        u8 level;

        fn_1_A8EB0(20, 3);
        fn_1_A8DD4("%s\n", lbl_1_data_1F318[test->cars[test->car].kind]);
        fn_1_8CB78(test->cars[test->car].tex[test->cars[test->car].cv % 4]);
        for (lod = 0; lod < 5; lod++) {
            if (lod != test->lod && ((1 << lod) & test->cars[test->car].lod_mask)) {
                level = test->lod_level[lod];
                fn_1_8CC04(*test->cars[test->car].lods[lod].models, level, lod * 150 + 10, 300, 0xFFFFFFFF, 0.35f);
            }
        }
        level = test->lod_level[test->lod];
        fn_1_8CC04(*test->cars[test->car].lods[test->lod].models, level, test->lod * 150 + 10, 300, 0xFF000000, 0.5f);
        return;
    }
    fn_1_495C8(1);
    fn_1_496FC(320.0f, 30.0f);
    fn_1_4AE0C("%s\n", test->mode_names[test->mode]);
    fn_1_495C8(0);
    fn_1_4955C(0.5f, 1.0f);
    fn_1_4AE0C("%s\n", test->mode_help[test->mode]);
    fn_1_4955C(1.0f, 1.0f);
    switch (lbl_1_bss_6D7E8->mode) {
    case 0:
        fn_1_495C8(0);
        fn_1_496FC(120.0f, 100.0f);
        for (i = 0; i < 5; i++) {
            if (i != 0) {
                if (test->sel == i) {
                    GXColor c = {0xFF, 0x00, 0x00, 0x00};
                    fn_1_49514(&c);
                } else {
                    GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(&c);
                }
                fn_1_4AE0C("%d %s\n", i, test->mode_names[i]);
            }
        }
        {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_496FC(120.0f, 300.0f);
        fn_1_4955C(0.5f, 1.0f);
        fn_1_4AE0C("[Z]:Reset Car Position\n");
        fn_1_4955C(1.0f, 1.0f);
        break;
    case 2:
        fn_1_495C8(0);
        fn_1_496FC(10.0f, 200.0f);
        fn_1_4955C(0.5f, 1.0f);
        fn_1_4AE0C("[Spec]\n");
        fn_1_4AE0C("(Pad2 Didital)\n");
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 0) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "R", test->lights->color[0]);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 1) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "G", test->lights->color[1]);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 2) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "B", test->lights->color[2]);
        {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("\n[MoveLight]\n");
        fn_1_4AE0C("Pad2 C-STICK,L,R\n");
        fn_1_4955C(1.0f, 1.0f);
        if ((lbl_1_bss_9F8[1].unk_2 >> 3) & 1) {
            CarModelInfo *info = test->cars[test->car].lods[test->lod].info;
            disp_model_info(test, info);
        }
        if ((lbl_1_bss_9F8[1].unk_2 >> 2) & 1) {
            CarTexList *tex = test->cars[test->car].tex[test->cars[test->car].cv % 4];
            disp_tex_info(tex);
        }
        break;
    case 3:
        fn_1_495C8(0);
        fn_1_496FC(10.0f, 200.0f);
        fn_1_4955C(0.5f, 1.0f);
        fn_1_4AE0C("[Spec]\n");
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 0) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "R", test->lights->color[0]);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 1) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "G", test->lights->color[1]);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 2) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "B", test->lights->color[2]);
        {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4955C(1.0f, 1.0f);
        break;
    case 1: {
        CarModelInfo *info = test->cars[test->car].lods[test->lod].info;
        CarTexList *tex = test->cars[test->car].tex[test->cars[test->car].cv % 4];

        fn_1_495C8(0);
        fn_1_496FC(10.0f, 100.0f);
        fn_1_4955C(0.5f, 0.5f);
        if (test->model == info->count) {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("[DISP OBEY FLAGS]\n");
        {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("-----------------\n");
        for (i = 0; i < info->count; i++) {
            if (!((1 << i) & test->disp_masks[test->car]) ||
                strstr(info->entries[i].name, "pos_") == info->entries[i].name) {
                GXColor c = {0x7F, 0x7F, 0x7F, 0x00};
                fn_1_49514(&c);
            }
            if (i == test->model) {
                GXColor c = {0xFF, 0x00, 0x00, 0x00};
                fn_1_49514(&c);
            }
            if (strstr(info->entries[i].name, "pos_") == info->entries[i].name) {
                fn_1_4AE0C("PosData\n");
                {
                    GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(&c);
                }
            } else {
                fn_1_4AE0C("%s[%s]\n", info->entries[i].name, ((1 << i) & test->disp_masks[test->car]) ? "ON" : "OFF");
                {
                    GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(&c);
                }
            }
        }
        {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("\n\n\n(Y:Tggle)\n(X:All Tggle)\n");
        fn_1_4955C(1.0f, 1.0f);
        fn_1_496FC(410.0f, 100.0f);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_4AE0C("TexSize:%7d\n", fn_80077D40(tex));
        fn_1_4AE0C("VtxNum :%7d\n", fn_80077BD4(info));
        fn_1_4955C(1.0f, 1.0f);
        if ((lbl_1_bss_9F8[1].unk_2 >> 3) & 1) {
            CarModelInfo *info = test->cars[test->car].lods[test->lod].info;
            disp_model_info(test, info);
        }
        if ((lbl_1_bss_9F8[1].unk_2 >> 2) & 1) {
            CarTexList *tex = test->cars[test->car].tex[test->cars[test->car].cv % 4];
            disp_tex_info(tex);
        }
        {
            char *lod_names[6] = {"CARLOD_HI", "CARLOD_MHI", "CARLOD_MLOW", "CARLOD_LOW", "CARLOD_CRASH", "CARLOD_NODISP"};
            fn_1_496FC(450.0f, 350.0f);
            fn_1_4955C(0.5f, 1.0f);
            fn_1_4AE0C("(LOD:C-Stick)\n\n");
            fn_1_4AE0C("     %s\n", lod_names[test->lod]);
            fn_1_4955C(1.0f, 1.0f);
        }
        break;
    }
    case 4:
        fn_1_495C8(0);
        fn_1_496FC(120.0f, 200.0f);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 0) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "R", test->bg_color[0]);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 1) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "G", test->bg_color[1]);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 2) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "B", test->bg_color[2]);
        {
            GXColor c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (test->channel != 3) {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "A", test->bg_color[3]);
        {
            GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        break;
    case 5:
        return;
    }
    fn_1_495C8(0);
    fn_1_496FC(120.0f, 420.0f);
    {
        char *cv_names[8] = {"CARCV0", "CARCV1", "CARCV2", "CARCV3",
                            "CARSV0", "CARSV1", "CARSV2", "CARSV3"};
        fn_1_4AE0C("%2d/%2d:[%s](%s)\n", car, 40, lbl_1_data_1F318[car], cv_names[test->cars[test->car].cv] + 3);
    }
}
/* fzgx:end fn_1_7C7CC */

/* fzgx:begin fn_1_7D694 */
// Compares the object's entry selector with the active global selector.
void fn_1_7D694(Car *car) {
    if (car->body->index == lbl_1_bss_6D7E8->car) {
        return;
    }
}
/* fzgx:end fn_1_7D694 */

/* fzgx:begin fn_1_7D6B8 */
/* WARNING: compiler-diff device, not original code (carried from main: the machine draft of this
   function with two optimizer pragmas and the one-field carriers) */
typedef struct {
    void *info;                 /* -> Fn1_7D6B8Info * */
    s32 *count;
    u32 unk_8;
} Fn1_7D6B8Slot;                /* 0xC */

typedef struct {
    u8 pad_0[0x334];
    Fn1_7D6B8Slot slots[0x16];
    u8 pad_43C[0x440 - 0x43C];
} Fn1_7D6B8Block;               /* 0x440 */

typedef struct {
    u8 *value;
} Fn1_7D6B8ColorContainer;

typedef struct {
    void *base;                 /* 0x00: Fn1_7D6B8Block array */
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 pad_9[3];
    s32 field_c;
    u8 pad_10[0x8];
    void *unk_18;
    u8 **unk_1c;
    s32 field_20;
    u8 field_24;
    s8 field_25;
    s8 field_26;
    s8 field_27;
    s8 field_28;
    s8 field_29;
} Fn1_7D6B8Arg;

typedef struct {
    u8 pad_18[0x18];
    u16 unk_18;
} Fn1_7D6B8Info;

/* Halfword fields not yet named in car_test.h. */
#define INPUT_14 (lbl_1_bss_9F8[1].unk_0)
#define INPUT_24 (lbl_1_bss_9F8[1].unk_10)
#define INPUT_26 (lbl_1_bss_9F8[1].unk_12)

/* saturate a u8 channel at 0xFF after a signed step */
#define CLAMP_U8(x) (((x) > 0xFFU) ? 0xFF : (x))

#pragma opt_dead_assignments off
#pragma opt_propagation off
void fn_1_7D6B8(Fn1_7D6B8Arg *arg0) {
    s32 *temp_r3_2;
    Fn1_7D6B8Block *block_entry;
    Fn1_7D6B8Block *block_entry2;
    s32 temp_r0_2;
    s32 temp_r3_4;
    s32 temp_r4;
    s32 shift_idx;
    s32 temp_r5;
    s32 temp_r8;
    s8 temp_r10;
    struct { s32 value; } var_r0;
    s32 var_r6_2;
    s8 var_r4;
    s8 var_r4_2;
    s8 var_r5;
    s8 var_r6;
    u8 *temp_r3_14;
    u8 *temp_r3_15;
    u8 *temp_r3_16;
    u8 *temp_r3_6;
    u8 *temp_r3_7;
    u8 *temp_r3_8;
    u8 *temp_r4_19;
    u8 *temp_r4_21;
    u8 *temp_r4_23;
    u8 *temp_r4_25;
    u8 *temp_r4_3;
    u8 *temp_r4_5;
    u8 *temp_r4_7;
    u8 *temp_r4_9;
    void *temp_r3_10;
    void *temp_r3_11;
    void *temp_r3_12;
    u8 temp_r0;
    u8 temp_r0_3;
    u8 temp_r0_4;
    u8 temp_r0_5;
    u8 temp_r3;
    u8 temp_r3_13;
    u8 temp_r3_5;
    u8 temp_r3_9;
    u8 temp_r4_10;
    u8 temp_r4_14;
    u8 temp_r4_16;
    u8 temp_r4_18;
    u8 temp_r4_22;
    u8 temp_r4_24;
    u8 temp_r4_26;
    s8 temp_r4_2;
    u8 temp_r4_6;
    u8 temp_r4_8;
    u8 *temp_r4_20;
    u8 *temp_r4_4;
    void *temp_r3_3;
    void *temp_r4_11;
    void *temp_r4_12;
    void *temp_r4_13;
    void *temp_r4_15;
    void *temp_r4_17;
    void *temp_r9;

    var_r5 = 0;
    var_r6 = 0;
    var_r4 = 0;
    if (!((*(s32 *)((u8 *)(lbl_1_bss_6D7E8) + 32)) & 0x40000000)) {
        temp_r0 = *((u8 *)(arg0) + 6);
        switch ((s8) temp_r0) {                     /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 3)) {
                var_r4 = -1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 2)) {
                var_r4 += 1;
            }
            (*((u8 *)(arg0) + 4)) = ((*((u8 *)(arg0) + 4)) + var_r4);
            if ((s8) (*((u8 *)(arg0) + 4)) < 1) {
                (*((u8 *)(arg0) + 4)) = 4U;
            }
            if ((s8) (*((u8 *)(arg0) + 4)) > 4) {
                (*((u8 *)(arg0) + 4)) = 1U;
            }
            if ((lbl_1_bss_9F8[0].unk_8 >> 8U) & 1) {
                (*((u8 *)(arg0) + 6)) = (*((u8 *)(arg0) + 4));
                return;
            }
            break;
        case 1:                                     /* switch 1 */
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 0) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 0)) {
                var_r4 = -1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 1) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 1)) {
                var_r4 += 1;
            }
            (*((u8 *)(arg0) + 7)) = ((*((u8 *)(arg0) + 7)) + var_r4);
            if ((s8) (*((u8 *)(arg0) + 7)) < 0) {
                (*((u8 *)(arg0) + 7)) = 0x28U;
            }
            if ((s8) (*((u8 *)(arg0) + 7)) > 0x28) {
                (*((u8 *)(arg0) + 7)) = 0U;
            }
            block_entry = &((Fn1_7D6B8Block *)(arg0->base))[(s8) *((u8 *)arg0 + 7)];
            temp_r0_2 = (s8) *block_entry->slots[(s8) *((u8 *)arg0 + 36)].count;
            if ((INPUT_14 >> 0xBU) & 1) {
                if (PAD_BIT(INPUT_26, 3)) {
                    var_r6 = -1;
                }
                if (PAD_BIT(INPUT_26, 2)) {
                    var_r6 += 1;
                }
                block_entry2 = &((Fn1_7D6B8Block *)(((u32)arg0->base)))[*(s8 *)((u8 *)arg0 + 7)];
                temp_r10 = *(s8 *)((u8 *)(arg0) + 36);
                temp_r8 = (s8) (*(Fn1_7D6B8Info **)block_entry2->slots[temp_r10].info)->unk_18;
                if (var_r6 != 0) {
                    temp_r9 = ((u8 *)(arg0) + temp_r10);
                    temp_r8 -= 1;
                    var_r6_2 = (s8) (*((u8 *)(temp_r9) + 37)) + var_r6;
                    if (var_r6_2 > temp_r8) {
                        var_r6_2 = 0;
                    } else if (var_r6_2 < 0) {
                        var_r6_2 = temp_r8;
                    }
                    (*((u8 *)(temp_r9) + 37)) = var_r6_2;
                }
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 3)) {
                var_r5 = -1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 2)) {
                var_r5 += 1;
            }
            (*((u8 *)(arg0) + 8)) = ((*((u8 *)(arg0) + 8)) + var_r5);
            if ((s8) (*((u8 *)(arg0) + 8)) < 0) {
                (*((u8 *)(arg0) + 8)) = temp_r0_2;
            }
            if ((s8) (*((u8 *)(arg0) + 8)) > temp_r0_2) {
                (*((u8 *)(arg0) + 8)) = 0U;
            }
            if (var_r4 != 0) {
                (*((u8 *)(arg0) + 8)) = temp_r0_2;
                arg0->field_25 = 0;
                arg0->field_26 = 0;
                arg0->field_27 = 0;
                arg0->field_28 = 0;
                arg0->field_29 = 0;
            }
            temp_r3 = *((u8 *)(arg0) + 8);
            shift_idx = (s8) temp_r3;
            if ((shift_idx != temp_r0_2) && ((lbl_1_bss_9F8[0].unk_8 >> 0xBU) & 1)) {
                temp_r5 = arg0->field_c;
                temp_r4 = (s8) (*((u8 *)(arg0) + 7)) * 4;
                (*(s32 *)(((temp_r5 + temp_r4)))) ^= (1 << shift_idx);
            }
            if ((lbl_1_bss_9F8[0].unk_8 >> 0xAU) & 1) {
                temp_r3_2 = (s32 *)((arg0->field_c) + ((s8) (*((u8 *)(arg0) + 7)) * 4));
                if ((*temp_r3_2) & 0x80000000) {
                    memset(temp_r3_2, (0), (4U));
                } else {
                    memset(temp_r3_2, (-1), (4U));
                }
            }
            if ((lbl_1_bss_9F8[0].unk_8 >> 8U) & 1) {
                (*((u8 *)(arg0) + 6)) = 2U;
            }
            if ((lbl_1_bss_9F8[0].unk_8 >> 9U) & 1) {
                (*((u8 *)(arg0) + 6)) = 0U;
                (*((u8 *)(arg0) + 5)) = 0U;
            }
            if (((*(u16 *)((u8 *)(&lbl_1_bss_9F8) + 28)) >> 4U) & 1) {
                (*(s32 *)((u8 *)(arg0) + 32)) = ((*(s32 *)((u8 *)(arg0) + 32)) ^ 0x80000000);
            }
            var_r4_2 = 0;
            if ((INPUT_14 >> 0xBU) & 1) {
                if (PAD_BIT(INPUT_26, 1)) {
                    var_r4_2 = 1;
                } else if (PAD_BIT(INPUT_26, 0)) {
                    var_r4_2 = -1;
                }
            } else if (PAD_BIT(lbl_1_bss_9F8[0].unk_12, 6) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 5)) {
                var_r4_2 = 1;
            } else if (PAD_BIT(lbl_1_bss_9F8[0].unk_12, 7) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 4)) {
                var_r4_2 = -1;
            }
            if (var_r4_2 != 0) {
                u8 mask;
                do {
                    temp_r3_4 = (s8) (*((u8 *)(arg0) + 36)) + var_r4_2;
                    if (temp_r3_4 > 4) {
                        var_r0.value = 0;
                    } else {
                        var_r0.value = 4;
                        if (temp_r3_4 >= 0) {
                            var_r0.value = temp_r3_4;
                        }
                    }
                    (*((u8 *)(arg0) + 36)) = var_r0.value;
                    temp_r4_2 = *(s8 *)((u8 *)(arg0) + 36);
                    mask = 1;
                    temp_r4 = mask << temp_r4_2;
                    mask = temp_r4;
                    temp_r3_3 = (void *)((((s32)arg0->base)) + ((s8) (*((u8 *)(arg0) + 7)) * 0x440));
                } while (!(temp_r4 & (*((u8 *)(temp_r3_3) + 908))));
                (*((u8 *)(arg0) + 8)) = fn_1_816E8(temp_r3_3, temp_r4_2);
                return;
            }
            break;
        case 2:                                     /* switch 1 */
            if ((lbl_1_bss_9F8[0].unk_8 >> 9U) & 1) {
                (*((u8 *)(arg0) + 6)) = 1U;
            }
            if (PAD_BIT(INPUT_24, 3)) {
                var_r4 = -1;
            }
            if (PAD_BIT(INPUT_24, 2)) {
                var_r4 += 1;
            }
            if (PAD_BIT(INPUT_24, 0)) {
                var_r5 = -1;
            }
            if (PAD_BIT(INPUT_24, 1)) {
                var_r5 += 1;
            }
            (*((u8 *)(arg0) + 5)) = ((*((u8 *)(arg0) + 5)) + var_r4);
            if ((s8) (*((u8 *)(arg0) + 5)) < 0) {
                (*((u8 *)(arg0) + 5)) = 2U;
            }
            if ((s8) (*((u8 *)(arg0) + 5)) > 2) {
                (*((u8 *)(arg0) + 5)) = 0U;
            }
            temp_r0_3 = *((u8 *)(arg0) + 5);
            switch ((s8) temp_r0_3) {               /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                temp_r4_3 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*temp_r4_3) = ((*temp_r4_3) + var_r5);
                temp_r4_4 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r3_5 = *temp_r4_4;
                (*temp_r4_4) = CLAMP_U8(temp_r3_5);
                break;
            case 1:                                 /* switch 2 */
                temp_r4_5 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*((u8 *)(temp_r4_5) + 1)) = ((*((u8 *)(temp_r4_5) + 1)) + var_r5);
                temp_r3_6 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r4_6 = *((u8 *)(temp_r3_6) + 1);
                (*((u8 *)(temp_r3_6) + 1)) = CLAMP_U8(temp_r4_6);
                break;
            case 2:                                 /* switch 2 */
                temp_r4_7 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*((u8 *)(temp_r4_7) + 2)) = ((*((u8 *)(temp_r4_7) + 2)) + var_r5);
                temp_r3_7 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r4_8 = *((u8 *)(temp_r3_7) + 2);
                (*((u8 *)(temp_r3_7) + 2)) = CLAMP_U8(temp_r4_8);
                break;
            case 3:                                 /* switch 2 */
                temp_r4_9 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*((u8 *)(temp_r4_9) + 3)) = ((*((u8 *)(temp_r4_9) + 3)) + var_r5);
                temp_r3_8 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r4_10 = *((u8 *)(temp_r3_8) + 3);
                (*((u8 *)(temp_r3_8) + 3)) = CLAMP_U8(temp_r4_10);
                break;
            }
            if (((*(u16 *)((u8 *)(&lbl_1_bss_9F8) + 28)) >> 4U) & 1) {
                (*(s32 *)((u8 *)(arg0) + 32)) = ((*(s32 *)((u8 *)(arg0) + 32)) ^ 0x80000000);
                return;
            }
            break;
        case 4:                                     /* switch 1 */
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 3)) {
                var_r4 = -1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 2)) {
                var_r4 += 1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 0) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 0)) {
                var_r5 = -1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 1) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 1)) {
                var_r5 += 1;
            }
            (*((u8 *)(arg0) + 5)) = ((*((u8 *)(arg0) + 5)) + var_r4);
            if ((s8) (*((u8 *)(arg0) + 5)) < 0) {
                (*((u8 *)(arg0) + 5)) = 3U;
            }
            if ((s8) (*((u8 *)(arg0) + 5)) > 3) {
                (*((u8 *)(arg0) + 5)) = 0U;
            }
            temp_r0_4 = *((u8 *)(arg0) + 5);
            switch ((s8) temp_r0_4) {               /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                temp_r4_11 = (*(void **)((u8 *)(arg0) + 24));
                (*(u8 *)(temp_r4_11)) = ((*(u8 *)(temp_r4_11)) + var_r5);
                temp_r4_12 = (*(void **)((u8 *)(arg0) + 24));
                temp_r3_9 = *(u8 *)(temp_r4_12);
                (*(u8 *)(temp_r4_12)) = CLAMP_U8(temp_r3_9);
                break;
            case 1:                                 /* switch 3 */
                temp_r4_13 = (*(void **)((u8 *)(arg0) + 24));
                (*((u8 *)(temp_r4_13) + 1)) = ((*((u8 *)(temp_r4_13) + 1)) + var_r5);
                temp_r3_10 = (*(void **)((u8 *)(arg0) + 24));
                temp_r4_14 = *((u8 *)(temp_r3_10) + 1);
                (*((u8 *)(temp_r3_10) + 1)) = CLAMP_U8(temp_r4_14);
                break;
            case 2:                                 /* switch 3 */
                temp_r4_15 = (*(void **)((u8 *)(arg0) + 24));
                (*((u8 *)(temp_r4_15) + 2)) = ((*((u8 *)(temp_r4_15) + 2)) + var_r5);
                temp_r3_11 = (*(void **)((u8 *)(arg0) + 24));
                temp_r4_16 = *((u8 *)(temp_r3_11) + 2);
                (*((u8 *)(temp_r3_11) + 2)) = CLAMP_U8(temp_r4_16);
                break;
            case 3:                                 /* switch 3 */
                temp_r4_17 = (*(void **)((u8 *)(arg0) + 24));
                (*((u8 *)(temp_r4_17) + 3)) = ((*((u8 *)(temp_r4_17) + 3)) + var_r5);
                temp_r3_12 = (*(void **)((u8 *)(arg0) + 24));
                temp_r4_18 = *((u8 *)(temp_r3_12) + 3);
                (*((u8 *)(temp_r3_12) + 3)) = CLAMP_U8(temp_r4_18);
                break;
            }
            if ((lbl_1_bss_9F8[0].unk_8 >> 0xBU) & 1) {
                fn_800793D4((*(void **)((u8 *)(arg0) + 24)), (0), (4U));
            }
            if ((lbl_1_bss_9F8[0].unk_8 >> 9U) & 1) {
                (*((u8 *)(arg0) + 6)) = 0U;
                (*((u8 *)(arg0) + 5)) = 0U;
                return;
            }
            break;
        case 3:                                     /* switch 1 */
            if ((lbl_1_bss_9F8[0].unk_8 >> 9U) & 1) {
                (*((u8 *)(arg0) + 6)) = 0U;
                (*((u8 *)(arg0) + 5)) = 0U;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 3) || PAD_BIT(INPUT_24, 3) || PAD_BIT(INPUT_26, 3)) {
                var_r4 = -1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 2) || PAD_BIT(INPUT_24, 2) || PAD_BIT(INPUT_26, 2)) {
                var_r4 += 1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 0) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 0) || PAD_BIT(INPUT_24, 0) || PAD_BIT(INPUT_26, 0)) {
                var_r5 = -1;
            }
            if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 1) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 1) || PAD_BIT(INPUT_24, 1) || PAD_BIT(INPUT_26, 1)) {
                var_r5 += 1;
            }
            (*((u8 *)(arg0) + 5)) = ((*((u8 *)(arg0) + 5)) + var_r4);
            if ((s8) (*((u8 *)(arg0) + 5)) < 0) {
                (*((u8 *)(arg0) + 5)) = 2U;
            }
            if ((s8) (*((u8 *)(arg0) + 5)) > 2) {
                (*((u8 *)(arg0) + 5)) = 0U;
            }
            temp_r0_5 = *((u8 *)(arg0) + 5);
            switch ((s8) temp_r0_5) {               /* switch 4; irregular */
            case 0:                                 /* switch 4 */
                temp_r4_19 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*temp_r4_19) += var_r5;
                temp_r4_20 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r3_13 = *temp_r4_20;
                (*temp_r4_20) = CLAMP_U8(temp_r3_13);
                return;
            case 1:                                 /* switch 4 */
                temp_r4_21 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*((u8 *)(temp_r4_21) + 1)) = ((*((u8 *)(temp_r4_21) + 1)) + var_r5);
                temp_r3_14 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r4_22 = *((u8 *)(temp_r3_14) + 1);
                (*((u8 *)(temp_r3_14) + 1)) = CLAMP_U8(temp_r4_22);
                return;
            case 2:                                 /* switch 4 */
                temp_r4_23 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*((u8 *)(temp_r4_23) + 2)) = ((*((u8 *)(temp_r4_23) + 2)) + var_r5);
                temp_r3_15 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r4_24 = *((u8 *)(temp_r3_15) + 2);
                (*((u8 *)(temp_r3_15) + 2)) = CLAMP_U8(temp_r4_24);
                return;
            case 3:                                 /* switch 4 */
                temp_r4_25 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                (*((u8 *)(temp_r4_25) + 3)) = ((*((u8 *)(temp_r4_25) + 3)) + var_r5);
                temp_r3_16 = (*(u8 **)(((*(u8 ***)((u8 *)(arg0) + 28)))));
                temp_r4_26 = *((u8 *)(temp_r3_16) + 3);
                (*((u8 *)(temp_r3_16) + 3)) = CLAMP_U8(temp_r4_26);
                break;
            }
            break;
        case 5:                                     /* switch 1 */
            break;
        }
    }
}
#pragma opt_propagation reset
#pragma opt_dead_assignments reset
#undef INPUT_14
#undef INPUT_24
#undef INPUT_26
#undef CLAMP_U8
/* fzgx:end fn_1_7D6B8 */

/* fzgx:begin fn_1_7E1DC */
/* .bss 0x9F8 is four 0x14-byte button records (held, previous, pressed, released); this reads the second */
#define CLAMP(x, lo, hi) (((x) < (lo)) ? (lo) : (((x) > (hi)) ? (hi) : (x)))

void fn_1_7E1DC(void) {
    /* WARNING: compiler-diff device, not original code: the cast view of the state pointer (as main) */
    CarTest *test = *(CarTest **)&lbl_1_bss_6D7E8;
    Vec3 v;
    GXLightObj light;
    Vec3 pts[21];
    s8 i;

    if (test->flags & 0x40000000) {
        return;
    }
    if ((lbl_1_bss_9F8[1].unk_2 >> 4) & 1) {
        lbl_1_bss_6D7E8->lights->rot_x += DEG_TO_S16(1);
    }
    if ((lbl_1_bss_9F8[1].unk_2 >> 5) & 1) {
        lbl_1_bss_6D7E8->lights->rot_x += DEG_TO_S16(359);
    }
    if ((lbl_1_bss_9F8[1].unk_2 >> 7) & 1) {
        lbl_1_bss_6D7E8->lights->rot_y += DEG_TO_S16(1);
    }
    if ((lbl_1_bss_9F8[1].unk_2 >> 6) & 1) {
        lbl_1_bss_6D7E8->lights->rot_y += DEG_TO_S16(359);
    }
    if ((lbl_1_bss_9F8[1].unk_2 >> 8) & 1) {
        lbl_1_bss_6D7E8->lights->distance += 0.1f;
    }
    if ((lbl_1_bss_9F8[1].unk_2 >> 9) & 1) {
        lbl_1_bss_6D7E8->lights->distance -= 0.1f;
    }
    lbl_1_bss_6D7E8->lights->rot_x %= DEG_TO_S16(360);
    lbl_1_bss_6D7E8->lights->rot_y %= DEG_TO_S16(360);
    lbl_1_bss_6D7E8->lights->distance = CLAMP(lbl_1_bss_6D7E8->lights->distance, 0.01f, 17.320507f);
    if ((lbl_1_bss_9F8[1].unk_8 >> 9) & 1) {
        lbl_1_bss_6D7E8->lights->distance = 17.320507f;
        lbl_1_bss_6D7E8->lights->rot_x = DEG_TO_S16(315);
        lbl_1_bss_6D7E8->lights->rot_y = DEG_TO_S16(45);
    }

    v.x = lbl_1_bss_6D7E8->lights->distance;
    v.z = 0.0f;
    v.y = 0.0f;
    lbl_8006D758();
    mathutil_mtxA_rotate_y(lbl_1_bss_6D7E8->lights->rot_x);
    mathutil_mtxA_rotate_z(lbl_1_bss_6D7E8->lights->rot_y);
    lbl_8006E1B0(&v, &v);

    if (((lbl_1_bss_9F8[1].unk_2 >> 7) & 1) || ((lbl_1_bss_9F8[1].unk_2 >> 4) & 1) || ((lbl_1_bss_9F8[1].unk_2 >> 6) & 1) || ((lbl_1_bss_9F8[1].unk_2 >> 5) & 1) ||
        ((lbl_1_bss_9F8[1].unk_2 >> 8) & 1) || ((lbl_1_bss_9F8[1].unk_2 >> 9) & 1) || ((lbl_1_bss_9F8[1].unk_0 >> 8) & 1)) {
        Vec3 origin = {0.0f, 0.0f, 0.0f};
        GXColor green = {0x00, 0xFF, 0x00, 0xFF};
        GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
        Vec3 w;

        w.x = lbl_1_bss_6D7E8->lights->distance;
        w.z = 0.0f;
        w.y = 0.0f;
        lbl_8006DCA4();
        fn_1_57714(6);
        fn_1_57720(1, 1, 1, 0);
        fn_1_5773C(&origin, &v, &green);
        lbl_8006E0A4(&v);
        fn_80072558();
        if (lbl_801A6CE0 & 1) {
            fn_80077F8C(lbl_1_bss_38454->unk_8->unk_20);
        }
        /* a 20-point circle about each axis, closed by repeating the first point */
        for (i = 0; i < 20; i++) {
            lbl_8006D758();
            mathutil_mtxA_rotate_y(182.04445f * (i * 360 / 20));
            mathutil_mtxA_rotate_z(lbl_1_bss_6D7E8->lights->rot_y);
            lbl_8006E1B0(&w, &pts[i]);
        }
        memcpy(&pts[20], &pts[0], sizeof(Vec3));
        lbl_8006DCA4();
        fn_1_57810(21, pts, &white);
        for (i = 0; i < 20; i++) {
            lbl_8006D758();
            mathutil_mtxA_rotate_y(lbl_1_bss_6D7E8->lights->rot_x);
            mathutil_mtxA_rotate_z(182.04445f * (i * 360 / 20));
            lbl_8006E1B0(&w, &pts[i]);
        }
        memcpy(&pts[20], &pts[0], sizeof(Vec3));
        lbl_8006DCA4();
        fn_1_57810(21, pts, &white);
    }

    lbl_8006DCA4();
    lbl_8006E1B0(&v, &v);
    fn_1_7BCCC(&v);
    fn_80035680(&light, v.x, v.y, v.z);
    fn_80035690(&light, v.x, v.y, v.z);
    fn_80035420(&light, 0.0f, 0);
    {
        GXColor c = *(GXColor *)lbl_1_bss_6D7E8->lights->color;
        fn_800356AC(&light, &c);
    }
    GXInitLightDistAttn(&light, 0.0f, 0.0f, 0);
    fn_1_7BB80(&light, 1);
    fn_1_7BD6C(1);
    fn_80074CF4(0.6f, 0.6f, 0.6f);
}
/* fzgx:end fn_1_7E1DC */

/* fzgx:begin fn_1_7E7A4 */
void fn_1_7E7A4(CarTest *test) {
    s8 i;

    for (i = 0; i < 41; i++) {
        fn_1_46B4(lbl_801A6410, test->cars[i].body, "car_test.c", 787);
    }
    fn_1_7F954(test->cars, 41);
    for (i = 0; i < 2; i++) {
        fn_1_46B4(lbl_801A6410, test->lights[i].color, "car_test.c", 801);
    }
    fn_1_46B4(lbl_801A6410, test->bg_color, "car_test.c", 804);
    fn_1_46B4(lbl_801A6410, test->disp_masks, "car_test.c", 805);
    fn_1_46B4(lbl_801A6410, test, "car_test.c", 806);
    fn_1_49614();
    fn_80074D68(1.0f, 1.0f, 1.0f);
    fn_80074D78(1);
}
/* fzgx:end fn_1_7E7A4 */

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
