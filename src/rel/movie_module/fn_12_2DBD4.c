#include "types.h"

extern const struct fn_12_2DBD4_lbl_12_rodata_E88_pool {
    f32 unk_0;
} lbl_12_rodata_E88;

typedef struct MovieModule MovieModule;
typedef void (*MovieCallback)(MovieModule *, int *, int *);

struct MovieModule {
    union {
        struct {
            u8 pad_0[0x920];
            int field_920;
            u8 pad_924[0x9dc - 0x924];
            int field_9dc;
            u8 pad_9e0[0xa58 - 0x9e0];
            int field_a58;
            u8 pad_a5c[0xf08 - 0xa5c];
            int field_f08;
            int field_f0c;
            u8 pad_f10[0xf28 - 0xf10];
            int field_f28;
            u8 pad_f2c[0xf38 - 0xf2c];
            int field_f38;
            f32 field_f3c;
            int field_f40;
            f32 field_f44;
            int field_f48;
        } fields;
        struct {
            u8 pad_cc0[0xcc0];
            MovieCallback callbacks[16];
        } callback_data;
    } data;
};

typedef struct MovieGlobals {
    u8 pad_0[0x1b8];
    int rate;
} MovieGlobals;

extern u32 lbl_12_bss_7C64[137];
extern void fn_12_24970(int *arg0);
extern int fn_12_2D73C(MovieModule *module, int arg0);
extern void fn_12_2E6AC(MovieModule *module, int *arg0, int *arg1);
extern void fn_12_24950(int *arg0);
extern int fn_12_332DC(int state, int time, int arg2, int arg3);

static inline int fn_12_2DBD4_is_ntsc(MovieModule *module) {
    int flag = 0;
    if (((MovieGlobals *)lbl_12_bss_7C64)->rate == 59940 && module->data.fields.field_920 <= 2 &&
        module->data.fields.field_f28 == 1000) {
        flag = 1;
    }
    return flag != 0;
}

static inline MovieCallback fn_12_2DBD4_array_read(MovieCallback *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_12_2DBD4(MovieModule *module, int arg1, int arg2, int *out, int arg4) {
    struct { MovieGlobals *value; } gs;
    int work[3];
#define g gs.value
    struct { MovieCallback value; } callback;
    f32 x;
    f32 tol;
    f32 y;
    int count;

    g = (MovieGlobals *)lbl_12_bss_7C64;
    if (module->data.fields.field_f08 == -5) {
        fn_12_24970(&work[0]);
        callback.value = fn_12_2DBD4_array_read(module->data.callback_data.callbacks, fn_12_2D73C(module, 15));
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        callback.value(module, &work[2], &work[1]);
        fn_12_24950(&work[0]);
    } else {
        work[2] = module->data.fields.field_f08;
        work[1] = module->data.fields.field_f0c;
    }
    if (work[1] == 1) {
        if (work[2] == -2) {
            *out = 1;
        } else if (*(volatile int *)&module->data.fields.field_f48 < 0) { /* volatile preserves the separate status read before the call's reload. */
            module->data.fields.field_f48 = 0;
            *out = 1;
        } else if (fn_12_332DC(arg1, arg2, module->data.fields.field_f48, g->rate) != 0) {
            *out = 1;
        } else {
            *out = 0;
        }
        return;
    }
    work[2] += (work[1] * arg4) / g->rate;
    x = lbl_12_rodata_E88.unk_0 * (f32)arg1 / (f32)arg2;
    y = lbl_12_rodata_E88.unk_0 * (f32)work[2] / (f32)work[1];
    if (module->data.fields.field_9dc != 1) {
        tol = (f32)module->data.fields.field_a58;
        if (y + tol < x) {
            *out = 0;
        } else if (y - tol >= x) {
            *out = 1;
            if (module->data.fields.field_f44 != x && module->data.fields.field_f3c != x) {
                module->data.fields.field_f3c = x;
                module->data.fields.field_f38++;
            }
        } else {
            count = module->data.fields.field_f38;
            if (count <= fn_12_2DBD4_is_ntsc(module)) {
                *out = module->data.fields.field_f40;
            } else if (y < x) {
                *out = 0;
            } else {
                *out = 1;
            }
            module->data.fields.field_f38 = 0;
            module->data.fields.field_f40 = *out;
            module->data.fields.field_f44 = x;
        }
    } else if (x <= y) {
        *out = 1;
    } else {
        *out = 0;
    }
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

