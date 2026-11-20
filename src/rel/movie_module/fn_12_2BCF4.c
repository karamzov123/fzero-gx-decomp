#include "types.h"


/* --- rel/movie_module/fn_12_2BCF4.c --- */
struct MovieModule {
    u32 pad_0;
    void *field_4;
    char pad_8[0x38];
    u32 field_40;
};

extern void *lbl_12_bss_7C64[137];
extern s32 fn_12_24A88(int arg0, u32 arg1);
extern void *fn_12_2BAE0(struct MovieModule *module, s32 arg);

void *fn_12_2BCF4(struct MovieModule *module, s32 arg) {
    int index;
    int i;
    void **table;
    void **p;
    int valid;
    void *movie;

    table = &lbl_12_bss_7C64[129];
    if (module->field_4 == 0) {
        valid = -1;
    } else if (module->field_40 < 0x29f8) {
        valid = -1;
    } else {
        valid = 0;
    }
    if (valid != 0) {
        fn_12_24A88(0, 0xff000203);
        return 0;
    }
    p = table;
    for (i = 0; i < 8; i++) {
        if (*p == 0) {
            index = i;
            goto found; /* search result, common exit */
        }
        p++;
    }
    index = -1;
found:
    if (index == -1) {
        return 0;
    }
    movie = fn_12_2BAE0(module, arg);
    table[index] = movie;
    return movie;
}

/* --- rel/movie_module/fn_12_2BE3C.c --- */
typedef struct MovieObj MovieObj;
typedef struct MovieObjVtbl {
    void *pad[9];
    int (*func_24)(MovieObj *obj, int arg);
} MovieObjVtbl;
struct MovieObj {
    MovieObjVtbl *vtbl;
};

typedef struct MovieSub {
    int field_0;
    MovieObj *obj;
    int field_8;
    int field_c;
} MovieSub;

typedef struct MovieEntry {
    int field_0;
    MovieSub sub;
    u8 pad_14[0x60];
} MovieEntry;

typedef struct MovieModule_u1 {
    u8 pad_0000[0x48];
    int field_48;
    int field_4c;
    int field_50;
    u8 pad_0054[0x96c - 0x54];
    int field_96c;
    u8 pad_0970[0xf00 - 0x970];
    int field_f00;
    int field_f04;
    u8 pad_0f08[0x114c - 0xf08];
    MovieEntry entries[1];
    u8 pad_11c0[0x1b38 - 0x11c0];
    int field_1b38;
} MovieModule_u1;

extern int fn_12_2D73C(MovieModule_u1 *module, int value);
extern int fn_12_2F1D0(MovieModule_u1 *module, int value);
extern int fn_12_21D30(MovieModule_u1 *module, int value);
extern int fn_12_21C00(MovieModule_u1 *module, int value);
extern int fn_12_2F1B4(MovieModule_u1 *module, int value);
extern s32 fn_12_2E714(MovieModule_u1 *module, s32 *a, s32 *b);
extern int UTY_MulDiv(int, int, int);
extern int fn_12_2E42C(int, int, int, int);

static inline int busy(MovieModule_u1 *module) {
    int i;

    if (fn_12_2D73C(module, 5) != 0 && fn_12_2F1D0(module, 6) != 0) {
        return 1;
    }
    if (fn_12_2D73C(module, 6) != 0 && fn_12_2F1D0(module, 7) != 0) {
        return 1;
    }
    for (i = 0; i < 8; i++) {
        if (fn_12_21D30(module, i) != 0) {
            return 1;
        }
    }
    return 0;
}

static inline int full(MovieModule_u1 *module) {
    MovieSub *sub = &module->entries[module->field_1b38].sub;
    int v = sub->obj->vtbl->func_24(sub->obj, 1);

    if (v >= sub->field_c * 80 / 100 || v >= fn_12_2D73C(module, 0x46)) {
        return 1;
    }
    return 0;
}

int fn_12_2BE3C(MovieModule_u1 *module) {
    s32 a;
    s32 b;
    int total;
    int rate;

    if (fn_12_2D73C(module, 0x43) == 0) {
        return 0;
    }
    if (fn_12_2D73C(module, 0xf) == 0) {
        return 0;
    }
    if (module->field_50 != 0) {
        return 0;
    }
    if (module->field_48 != 4) {
        return 0;
    }
    if (busy(module)) {
        return 0;
    }
    if (fn_12_2D73C(module, 5) == 1 && module->field_96c == 0) {
        return 0;
    }
    if (fn_12_2D73C(module, 6) == 1 && fn_12_21C00(module, 2) > 0) {
        return 0;
    }
    if (fn_12_2F1B4(module, 1) != 0 && fn_12_21C00(module, 0) > 0) {
        return 0;
    }
    if (fn_12_2D73C(module, 5) == 1 && full(module)) {
        return 0;
    }
    fn_12_2E714(module, &a, &b);
    total = module->field_f00;
    rate = module->field_f04;
    total -= UTY_MulDiv(fn_12_2D73C(module, 0x44), rate, 1000000);
    if (a <= 0 || total <= 0) {
        return 0;
    }
    return fn_12_2E42C(a, b, total, rate) == 0;
}
