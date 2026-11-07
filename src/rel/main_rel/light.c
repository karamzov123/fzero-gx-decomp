#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/light.h"

extern u16 lbl_1_bss_6D7C0[20];

extern void *lbl_801A6410;
extern u32 fn_1_4630(u32, int, void *, int);
extern void fn_800793D4(u32, int, int);
extern void fn_1_7C13C(void *);
extern void fn_1_7C1E8(u32);
extern u8 fn_1_816E8(void *, u8);
extern const f32 lbl_1_rodata_33A8;
extern void fn_1_495D8(int, int, f32);
extern void fn_1_495FC(void);
extern void OSPanic(const char *, int, const char *, ...);

/* fzgx:begin fn_1_7BCCC */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Triple_80074D28;

typedef struct {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x12];
    u16 unk_16;
    u8 pad_18[0x8];
    u32 unk_20;
} Fn17BCCCState;

extern void fn_80074D28(Triple_80074D28 *);

void fn_1_7BCCC(Triple_80074D28 *arg0) {
    Fn17BCCCState *state;

    state = (Fn17BCCCState *)&lbl_1_bss_6D7A8;
    if (state->unk_16 >= state->unk_2) {
        OSPanic((const char *)lbl_1_data_1EE44, 143, (const char *)lbl_1_data_1EE70);
    }
    *(Triple_80074D28 *)((u8 *)state->unk_20 + state->unk_16 * 12) = *arg0;
    fn_80074D28(arg0);
    state->unk_16++;
    return;
}
/* fzgx:end fn_1_7BCCC */

/* fzgx:begin fn_1_7BE94 */
u16 fn_1_7BE94(void) {
    return lbl_1_bss_6D7C0[0] - 1;
}
/* fzgx:end fn_1_7BE94 */

/* fzgx:begin fn_1_7BEAC */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u8 pad_6[2];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16;
    u8 pad_18[4];
    s32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u16 states[8];
    s32 unk_38;
} LightStateView;

extern u32 fn_800356B8(void *, u32);
extern void fn_80074D28(void *);
extern u32 fn_80074D08(u32);

static inline void update_states(LightStateView *light, u8 *base, s32 *changed) {
    u32 i = 0;
    u8 *entry = base;
    u16 *states = light->states;
    for (; i < 8; i++, states++, entry += 2) {
        u16 value = *(u16 *)(4 + entry);
        if (value != *states) {
            fn_800356B8((u8 *)light->unk_1C + ((u32)value << 6), 1 << i);
            *changed = 1;
            *states = *(u16 *)(entry + 4);
        }
    }
}

void fn_1_7BEAC(u16 index) {
    LightStateView *light = (LightStateView *)&lbl_1_bss_6D7A8;
    u8 *entry_base = (u8 *)light->unk_24 + (u32)index * 0x14;
    s32 changed = 0;
    update_states(light, entry_base, &changed);

    if (light->unk_16 != *(u16 *)(entry_base + 2) &&
        ((0) != (light->unk_16))) {
        fn_80074D28((u8 *)light->unk_20 + (u32)*(u16 *)(entry_base + 2) * 0xc);
        light->unk_16 = *(u16 *)(entry_base + 2);
    }

    if (light->unk_38 != *(u16 *)entry_base || changed != 0) {
        fn_80074D08(*(u16 *)entry_base);
        light->unk_38 = *(u16 *)entry_base;
    }
}
/* fzgx:end fn_1_7BEAC */

/* fzgx:begin fn_1_7BF9C */
typedef struct {
    void *unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    s8 unk_7;
    u8 unk_8;
    u8 unk_9[3];
    void *unk_c;
    void *unk_10;
    void *unk_14;
    void *unk_18;
    void *unk_1c;
    u32 unk_20;
    u8 unk_24;
} LightState;

// Initialize the shared light state and its required resources.
void fn_1_7BF9C(void *arg, s8 flag) {
    u8 *resource_table;
    u32 resource_18;
    u32 resource_1c;
    u32 resource_c;

    resource_table = (u8 *)&lbl_1_data_1EEB0;
    lbl_1_bss_6D7E8 = fn_1_4630(
        (u32)lbl_801A6410, 0x2c, resource_table + 0xac, 0x33);
    resource_18 = fn_1_4630(
        (u32)lbl_801A6410, 4, resource_table + 0xac, 0x34);
    resource_1c = fn_1_4630(
        (u32)lbl_801A6410, 0x18, resource_table + 0xac, 0x35);
    resource_c = fn_1_4630(
        (u32)lbl_801A6410, 0xa4, resource_table + 0xac, 0x36);

    fn_800793D4(resource_c, 0xff, 0xa4);
    fn_1_7C13C(arg);
    fn_1_7C1E8(resource_1c);

    ((LightState *)lbl_1_bss_6D7E8)->unk_0 = arg;
    ((LightState *)lbl_1_bss_6D7E8)->unk_4 = 2;
    ((LightState *)lbl_1_bss_6D7E8)->unk_6 = 2;
    ((LightState *)lbl_1_bss_6D7E8)->unk_24 = 0;
    ((LightState *)lbl_1_bss_6D7E8)->unk_8 = fn_1_816E8(
        (u8 *)((LightState *)lbl_1_bss_6D7E8)->unk_0 +
            ((LightState *)lbl_1_bss_6D7E8)->unk_7 * 0x440,
        ((LightState *)lbl_1_bss_6D7E8)->unk_24);

    ((LightState *)lbl_1_bss_6D7E8)->unk_c = (void *)resource_c;
    ((LightState *)lbl_1_bss_6D7E8)->unk_10 = resource_table + 0x48;
    ((LightState *)lbl_1_bss_6D7E8)->unk_14 = resource_table + 0x94;
    ((LightState *)lbl_1_bss_6D7E8)->unk_18 = (void *)resource_18;
    ((LightState *)lbl_1_bss_6D7E8)->unk_1c = (void *)resource_1c;

    if (flag == 0) {
        ((LightState *)lbl_1_bss_6D7E8)->unk_20 |= 0x40000000;
    }

    fn_1_495D8(2, 2, lbl_1_rodata_33A8);
    fn_1_495FC();
}
/* fzgx:end fn_1_7BF9C */

/* fzgx:begin fn_1_7C7CC noprologue */
#include "types.h"

/* the TU's .data ahead of this function, at retail offsets */
char *fzgx_pool_data_48[6] = {"CAR_TESTTOP", "CAR_SELECT", "CAR_CHECK", "LIGHT_CHG", "BGCOL_CHG", "ALL_DISP"};
char *fzgx_pool_data_94[6] = {"(Menu:exit)", "(A:Check)\n(B:Top)", "(B:Select)", "(B:Top)", "(B:Top)", "(B:Top)"};
char fzgx_pool_gap_AC[0xC] = "car_test.c";
/* the TU creates its .data pool before its .rodata pool (fn_1_7C13C addresses "car_test.c" first); MWCC
 * numbers hoisted section bases in pool-creation order, so retail keeps .data in r29 above .rodata in r28 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_data_first(void) {
    const char *volatile s;  /* fzgx-allow: S2 pool primer sink */
    s = "CAR_TESTTOP";
    s = "CAR_SELECT";
    s = "CAR_CHECK";
}
#pragma section code_type ".text"

/* the TU's .rodata ahead of this function: fn_1_7C2A0's literals and colours */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 100.0f;
    s = 17.320507049560547f;
}
static const u32 fzgx_pool_table2[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table3[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -100.0f;
    s = 3.0f;
    s = 6.0f;
    s = -3.0f;
    s = 182.04444885253906f;
    s = 255.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} Color;

typedef struct {
    f32 x, y, z;
} Vec;

typedef struct {
    u8 pad_0[8];
    Vec center;
    f32 radius;
    u16 ntex;
} CarModel;

typedef struct {
    u32 unk_0;
    char *name;
} CarModelEntry;

typedef struct {
    s32 count;
    CarModel *model;
    CarModelEntry *entries;
} CarModelInfo;

typedef struct {
    CarModel **models;
    CarModelInfo *info;
    u32 unk_8;
} CarLod;

typedef struct {
    u32 flags;
    u32 unk_4;
    u16 width;
    u16 height;
    u16 max_lod;
    u16 pad_e;
} CarTex;

typedef struct {
    u32 count;
    CarTex *items;
} CarTexList;

typedef struct {
    u8 pad_0[0x328];
    s8 kind;
    u8 pad_329[0xB];
    CarLod lods[6];
    CarTexList *tex[4];
    u8 lod_mask;
    u8 pad_38D[0x2B];
    s16 cv;
    u8 pad_3BA[0x86];
} Car;

typedef struct {
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
    u8 **light_color;
    u32 flags;
    s8 lod;
    u8 lod_level[5];
} CarTest;

typedef struct {
    u8 pad_0[0x14];
    u16 hold;
    u16 trig;
} PadInput;

extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(Color *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EB0(int, int);
extern void fn_1_8CB78(CarTexList *);
extern void fn_1_8CC04(CarModel *, u8, s16, s16, u32, f32);
extern char *fn_80083970(char *, const char *);
extern u32 fn_80077D40(CarTexList *);
extern u32 fn_80077BD4(CarModelInfo *);

extern char *lbl_1_data_1F318[];
extern PadInput lbl_1_bss_9F8;
extern CarTest *lbl_1_bss_6D7E8;


/* model and texture statistics of the selected car (compiled out of line in retail and stripped) */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void disp_model_info(CarTest *g, CarModelInfo *info) {
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
        model = g->cars[g->car].lods[g->lod].models[g->model];
        fn_1_A8DD4("center    :%2.2f %2.2f %2.2f\n", model->center.x, model->center.y, model->center.z);
        fn_1_A8DD4("radius    :%2.2f\n", model->radius);
        fn_1_A8DD4("ntex      :%d\n", model->ntex);
    }
}

__declspec(section ".fzgxpool") static void disp_tex_info(CarTexList *tex) {
    s8 i;

    fn_1_A8EB0(20, 10);
    fn_1_A8DD4("ntex      :%d\n", tex->count);
    for (i = 0; i < tex->count; i++) {
        fn_1_A8DD4("tex[%2d] ", i);
        fn_1_A8DD4("%3dx%3d mip%d\n", tex->items[i].width, tex->items[i].height, tex->items[i].max_lod);
    }
}
#pragma section code_type ".text"

/* fn_1_7C2A0's two strings */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime_str(void) {
    const char *volatile s;  /* fzgx-allow: S2 pool primer sink */
    s = "pos_";
    s = "cpu:%d\n";
}
#pragma section code_type ".text"

/* the TU's .data between fn_1_7C2A0's strings and this function's: the CARLOD/CARCV name strings
 * that lod_names/cv_names point at (retail lbl_1_data_1EFEC..1F074) */
char fzgx_pool_gap_13C[0x90] = "CARLOD_HI\0\0\0" "CARLOD_MHI\0\0" "CARLOD_MLOW\0" "CARLOD_LOW\0\0"
                               "CARLOD_CRASH\0\0\0\0" "CARLOD_NODISP\0\0\0"
                               "CARCV0\0\0" "CARCV1\0\0" "CARCV2\0\0" "CARCV3\0\0"
                               "CARSV0\0\0" "CARSV1\0\0" "CARSV2\0\0" "CARSV3\0";
extern char lbl_1_data_1EFEC[];  /* "CARLOD_HI" */
extern char lbl_1_data_1EFF8[];  /* "CARLOD_MHI" */
extern char lbl_1_data_1F004[];  /* "CARLOD_MLOW" */
extern char lbl_1_data_1F010[];  /* "CARLOD_LOW" */
extern char lbl_1_data_1F01C[];  /* "CARLOD_CRASH" */
extern char lbl_1_data_1F02C[];  /* "CARLOD_NODISP" */
extern char lbl_1_data_1F03C[];  /* "CARCV0" */
extern char lbl_1_data_1F044[];  /* "CARCV1" */
extern char lbl_1_data_1F04C[];  /* "CARCV2" */
extern char lbl_1_data_1F054[];  /* "CARCV3" */
extern char lbl_1_data_1F05C[];  /* "CARSV0" */
extern char lbl_1_data_1F064[];  /* "CARSV1" */
extern char lbl_1_data_1F06C[];  /* "CARSV2" */
extern char lbl_1_data_1F074[];  /* "CARSV3" */

void fn_1_7C7CC(CarTest *g) {
    s8 car = g->car;
    s8 i;

    if (g->flags & 0x40000000) {
        fn_1_496FC(160.0f, 100.0f);
        fn_1_4AE0C("\x82\xad\x82\xe9\x82\xdc\x83\x54\x83\x43\x83\x59\x82\xaa\x82\xa8\x82\xa8\x82\xab\x82\xb7\x82\xac\x82\xc4\x83\x71\x81\x5b\x83\x76\n"
                   "\x82\xb1\x82\xa6\x82\xbf\x82\xe1\x82\xa2\x82\xdc\x82\xb5\x82\xbd\x81\x49\n");
        return;
    }
    if ((lbl_1_bss_9F8.hold >> 11) & 1) {
        s8 lod;
        u8 level;

        fn_1_A8EB0(20, 3);
        fn_1_A8DD4("%s\n", lbl_1_data_1F318[g->cars[g->car].kind]);
        fn_1_8CB78(g->cars[g->car].tex[g->cars[g->car].cv % 4]);
        for (lod = 0; lod < 5; lod++) {
            if (lod != g->lod && ((1 << lod) & g->cars[g->car].lod_mask)) {
                level = g->lod_level[lod];
                fn_1_8CC04(*g->cars[g->car].lods[lod].models, level, lod * 150 + 10, 300, 0xFFFFFFFF, 0.35f);
            }
        }
        level = g->lod_level[g->lod];
        fn_1_8CC04(*g->cars[g->car].lods[g->lod].models, level, g->lod * 150 + 10, 300, 0xFF000000, 0.5f);
        return;
    }
    fn_1_495C8(1);
    fn_1_496FC(320.0f, 30.0f);
    fn_1_4AE0C("%s\n", g->mode_names[g->mode]);
    fn_1_495C8(0);
    fn_1_4955C(0.5f, 1.0f);
    fn_1_4AE0C("%s\n", g->mode_help[g->mode]);
    fn_1_4955C(1.0f, 1.0f);
    switch (lbl_1_bss_6D7E8->mode) {
    case 0:
        fn_1_495C8(0);
        fn_1_496FC(120.0f, 100.0f);
        for (i = 0; i < 5; i++) {
            if (i != 0) {
                if (g->sel == i) {
                    Color c = {0xFF, 0x00, 0x00, 0x00};
                    fn_1_49514(&c);
                } else {
                    Color c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(&c);
                }
                fn_1_4AE0C("%d %s\n", i, g->mode_names[i]);
            }
        }
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
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
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 0) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "R", g->light_color[0][0]);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 1) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "G", g->light_color[0][1]);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 2) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "B", g->light_color[0][2]);
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("\n[MoveLight]\n");
        fn_1_4AE0C("Pad2 C-STICK,L,R\n");
        fn_1_4955C(1.0f, 1.0f);
        if ((lbl_1_bss_9F8.trig >> 3) & 1) {
            CarModelInfo *info = g->cars[g->car].lods[g->lod].info;
            disp_model_info(g, info);
        }
        if ((lbl_1_bss_9F8.trig >> 2) & 1) {
            CarTexList *tex = g->cars[g->car].tex[g->cars[g->car].cv % 4];
            disp_tex_info(tex);
        }
        break;
    case 3:
        fn_1_495C8(0);
        fn_1_496FC(10.0f, 200.0f);
        fn_1_4955C(0.5f, 1.0f);
        fn_1_4AE0C("[Spec]\n");
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 0) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "R", g->light_color[0][0]);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 1) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "G", g->light_color[0][1]);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 2) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "B", g->light_color[0][2]);
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4955C(1.0f, 1.0f);
        break;
    case 1: {
        CarModelInfo *info = g->cars[g->car].lods[g->lod].info;
        CarTexList *tex = g->cars[g->car].tex[g->cars[g->car].cv % 4];

        fn_1_495C8(0);
        fn_1_496FC(10.0f, 100.0f);
        fn_1_4955C(0.5f, 0.5f);
        if (g->model == info->count) {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("[DISP OBEY FLAGS]\n");
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("-----------------\n");
        for (i = 0; i < info->count; i++) {
            if (!((1 << i) & g->disp_masks[g->car]) ||
                fn_80083970(info->entries[i].name, "pos_") == info->entries[i].name) {
                Color c = {0x7F, 0x7F, 0x7F, 0x00};
                fn_1_49514(&c);
            }
            if (i == g->model) {
                Color c = {0xFF, 0x00, 0x00, 0x00};
                fn_1_49514(&c);
            }
            if (fn_80083970(info->entries[i].name, "pos_") == info->entries[i].name) {
                fn_1_4AE0C("PosData\n");
                {
                    Color c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(&c);
                }
            } else {
                fn_1_4AE0C("%s[%s]\n", info->entries[i].name, ((1 << i) & g->disp_masks[g->car]) ? "ON" : "OFF");
                {
                    Color c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(&c);
                }
            }
        }
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("\n\n\n(Y:Tggle)\n(X:All Tggle)\n");
        fn_1_4955C(1.0f, 1.0f);
        fn_1_496FC(410.0f, 100.0f);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_4AE0C("TexSize:%7d\n", fn_80077D40(tex));
        fn_1_4AE0C("VtxNum :%7d\n", fn_80077BD4(info));
        fn_1_4955C(1.0f, 1.0f);
        if ((lbl_1_bss_9F8.trig >> 3) & 1) {
            CarModelInfo *info = g->cars[g->car].lods[g->lod].info;
            disp_model_info(g, info);
        }
        if ((lbl_1_bss_9F8.trig >> 2) & 1) {
            CarTexList *tex = g->cars[g->car].tex[g->cars[g->car].cv % 4];
            disp_tex_info(tex);
        }
        {
            char *lod_names[6] = {lbl_1_data_1EFEC, lbl_1_data_1EFF8, lbl_1_data_1F004, lbl_1_data_1F010, lbl_1_data_1F01C, lbl_1_data_1F02C};
            fn_1_496FC(450.0f, 350.0f);
            fn_1_4955C(0.5f, 1.0f);
            fn_1_4AE0C("(LOD:C-Stick)\n\n");
            fn_1_4AE0C("     %s\n", lod_names[g->lod]);
            fn_1_4955C(1.0f, 1.0f);
        }
        break;
    }
    case 4:
        fn_1_495C8(0);
        fn_1_496FC(120.0f, 200.0f);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 0) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "R", g->bg_color[0]);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 1) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "G", g->bg_color[1]);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 2) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "B", g->bg_color[2]);
        {
            Color c = {0xFF, 0x00, 0x00, 0x00};
            fn_1_49514(&c);
        }
        if (g->channel != 3) {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s:%3d\n", "A", g->bg_color[3]);
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(&c);
        }
        break;
    case 5:
        return;
    }
    fn_1_495C8(0);
    fn_1_496FC(120.0f, 420.0f);
    {
        char *cv_names[8] = {lbl_1_data_1F03C, lbl_1_data_1F044, lbl_1_data_1F04C, lbl_1_data_1F054,
                            lbl_1_data_1F05C, lbl_1_data_1F064, lbl_1_data_1F06C, lbl_1_data_1F074};
        fn_1_4AE0C("%2d/%2d:[%s](%s)\n", car, 40, lbl_1_data_1F318[car], cv_names[g->cars[g->car].cv] + 3);
    }
}
/* fzgx:end fn_1_7C7CC */
