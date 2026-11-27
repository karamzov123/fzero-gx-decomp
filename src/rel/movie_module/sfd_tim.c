#include "types.h"
#include "sofdec/sfd.h"

/* fzgx:begin fn_12_2DAB4 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2DAB4.c --- */
typedef struct MovieModule_u1 {
    u8 pad_0[0xf28];
    int value;
} MovieModule_u1;

int fn_12_2DAB4(MovieModule_u1 *module) {
    return module->value;
}
/* fzgx:end fn_12_2DAB4 */

/* fzgx:begin fn_12_2DABC noprologue */

/* --- rel/movie_module/fn_12_2DABC.c --- */
typedef struct MovieModule_u2 MovieModule_u2;
typedef void (*MovieCallback)(MovieModule_u2 *, int *, int *);

struct MovieModule_u2 {
    union {
        struct {
            u8 pad_0[0x94c];
            int field_94c;
            u8 pad_950[0x5a8];
            int field_ef8;
            int field_efc;
            u8 pad_f00[8];
            int field_f08;
            int field_f0c;
        } fields;
        struct {
            u8 pad_cc0[0xcc0];
            MovieCallback callbacks[16];
        } callback_data;
    } data;
};

extern void fn_12_24970(int *arg0);
extern int fn_12_2D73C(MovieModule_u2 *module, int arg0);
extern void fn_12_2E6AC(MovieModule_u2 *module, int *arg0, int *arg1);
extern void fn_12_24950(int *arg0);
extern int fn_12_332DC(int state, int time, int arg2, int arg3);

int fn_12_2DABC(MovieModule_u2 *module) {
    int work[3];
    int state;
    int time;
    int index;
    struct { MovieCallback value; } callback;

    state = module->data.fields.field_ef8;
    time = module->data.fields.field_efc;
    if (module->data.fields.field_94c == 0) {
        return 1;
    }
    if (state == -5) {
        return 0;
    }
    if (module->data.fields.field_f08 == -5) {
        fn_12_24970(&work[0]);
        index = fn_12_2D73C(module, 15);
        callback.value = module->data.callback_data.callbacks[index];
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        callback.value(module, &work[2], &work[1]);
        fn_12_24950(&work[0]);
    } else {
        work[2] = module->data.fields.field_f08;
        work[1] = module->data.fields.field_f0c;
    }
    state += (time * 2000) / 59940;
    if (fn_12_332DC(state, time, work[2], work[1]) != 0) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_12_2DABC */

/* fzgx:begin fn_12_2DBD4 noprologue */
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

#pragma opt_common_subs reset

/* fzgx:end fn_12_2DBD4 */

/* fzgx:begin fn_12_2DEB0 noprologue */
#include "types.h"

typedef struct MovieModule {
    u8 pad_0[0x9d8];
    s32 state;
    u8 pad_9dc[0x74];
    s32 movie;
} MovieModule;

extern void fn_12_2DBD4(void *, void *, void *, s32 *, s32);

s32 fn_12_2DEB0(MovieModule *module, void *arg1, void *arg2, s32 *arg3, s32 arg4) {
    s32 result;

    if (module->state != 0) {
        return 1;
    }
    fn_12_2DBD4(module, arg1, arg2, &result, module->movie);
    return result;
}
/* fzgx:end fn_12_2DEB0 */

/* fzgx:begin fn_12_2DEF0 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2DEF0.c --- */
typedef struct MovieEntry {
    u8 pad_0[0x14];
    s32 value_14;
    s32 value_18;
} MovieEntry;

extern int fn_12_2DEB0(void *arg0, s32 value_14, s32 value_18);

int fn_12_2DEF0(void *arg0, MovieEntry *entry) {
    if (entry == 0) {
        return 0;
    }
    return fn_12_2DEB0(arg0, entry->value_14, entry->value_18);
}
/* fzgx:end fn_12_2DEF0 */

/* fzgx:begin fn_12_2DF28 noprologue */

/* --- rel/movie_module/fn_12_2DF28.c --- */
extern u32 fn_12_24990(u32, u32);
extern u32 fn_12_24A88(u32, u32);
extern u32 lbl_12_rodata_E10;

struct fn_12_2DF28_Arg1 {
    u32 unk_0;
};

s32 fn_12_2DF28(u32 arg0, struct fn_12_2DF28_Arg1 *arg1) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    arg1->unk_0 = -1;
    t0 = fn_12_24990(arg0, (u32)arg1);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_24A88(v0, (0xFF000000 + 283));
    v0 = t1;
    } else {
    v1 = *(u32 *)((u8 *)arg0 + 2336);
    if ((s32)v1 == 0) {
    v0 = 0;
    } else {
    v0 = 0;
    *(u32 *)((u8 *)(u32)arg1 + 0) = *(u32 *)((u8 *)&lbl_12_rodata_E10 + (v1 << 2));
    }
    }
    return v0;
}
/* fzgx:end fn_12_2DF28 */

/* fzgx:begin SFTIM_GetTimeOneFrmVideo noprologue */
#include "types.h"
#include "sofdec/sfd.h"

extern const int lbl_12_rodata_E10[9];

void SFTIM_GetTimeOneFrmVideo(SfdHandle *handle, int *value, int *scale) {
    int code = handle->playback_settings.frame_rate_code;
    if (code == 0) {
        *value = 0;
        *scale = 29970;
    } else {
        *value = 1000;
        *scale = lbl_12_rodata_E10[code];
    }
}
/* fzgx:end SFTIM_GetTimeOneFrmVideo */

/* fzgx:begin fn_12_2DFF0 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2DFF0.c --- */
typedef struct MovieModule {
    u8 pad_0[0x920];
    s32 movie_index;
    u8 pad_924[0xF24 - 0x924];
    s32 total_a;
    u8 pad_F28[0xF48 - 0xF28];
    s32 total_b;
    u8 pad_F4C[0xF58 - 0xF4C];
    s32 total_c;
    s32 movie_id;
} MovieModule;

extern u32 lbl_12_rodata_E10[9];
extern u32 lbl_12_bss_7C64[137];
extern s32 UTY_MulDiv(s32 arg0, s32 arg1, s32 arg2);

void fn_12_2DFF0(MovieModule *module, s32 mode) {
    s32 value;
    s32 duration;
    s32 result;

    switch (mode) {
    case 0:
    case 1:
        break;
    case 2:
        if (module->movie_index == 0) {
            value = 0;
            duration = 0x7512;
        } else {
            value = 0x3e8;
            duration = lbl_12_rodata_E10[module->movie_index];
        }

        result = UTY_MulDiv(lbl_12_bss_7C64[0x6e], value, duration);
        module->total_a += result;
        module->total_b += result;
        result = UTY_MulDiv(module->movie_id, value, duration);
        module->total_c += result;
        break;
    }
}
/* fzgx:end fn_12_2DFF0 */

/* fzgx:begin fn_12_2E0B0 noprologue */

/* --- rel/movie_module/fn_12_2E0B0.c --- */
typedef struct MovieTimeCode {
    u8 pad_0[8];
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 extra_frames;
} MovieTimeCode;

void fn_12_2E0B0(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    *result = (time->hours * 215892 + time->minutes * 3598 + time->minutes / 10 * 2 + time->seconds * 60 +
               (time->frames + time->extra_frames)) * 1000;
    *out_scale = scale;
}
/* fzgx:end fn_12_2E0B0 */

/* fzgx:begin fn_12_2E128 noprologue */

/* --- rel/movie_module/fn_12_2E128.c --- */
void fn_12_2E128(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    *result = (time->hours * 107892 + time->minutes * 1798 + time->minutes / 10 * 2 + time->seconds * 30 +
               (time->frames + time->extra_frames)) * 1000;
    *out_scale = scale;
}
/* fzgx:end fn_12_2E128 */

/* fzgx:begin fn_12_2E1A0 noprologue */

/* --- rel/movie_module/fn_12_2E1A0.c --- */
void fn_12_2E1A0(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    *result = (time->hours * 86292 + time->minutes * 1438 + time->minutes / 10 * 2 + time->seconds * 24 +
               (time->frames + time->extra_frames)) * 1000;
    *out_scale = scale;
}
/* fzgx:end fn_12_2E1A0 */

/* fzgx:begin fn_12_2E218 noprologue */

/* --- rel/movie_module/fn_12_2E218.c --- */
typedef struct FnEntry {
    u8 padding[8];
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
} FnEntry;

void fn_12_2E218(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = entry->field_0c * 3600000;
    b = entry->field_08 * 216000000;
    c = entry->field_10 * 60000;
    d = (entry->field_14 + entry->field_18) * 1000;
    *result = a + b + c + d;
    *out = 60000;
    *out = value;
}
/* fzgx:end fn_12_2E218 */

/* fzgx:begin fn_12_2E284 noprologue */

/* --- rel/movie_module/fn_12_2E284.c --- */
void fn_12_2E284(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = entry->field_0c * 1800000;
    b = entry->field_08 * 108000000;
    c = entry->field_10 * 30000;
    d = (entry->field_14 + entry->field_18) * 1000;
    *result = a + b + c + d;
    *out = 30000;
    *out = value;
}
/* fzgx:end fn_12_2E284 */

/* fzgx:begin fn_12_2E2DC noprologue */

/* --- rel/movie_module/fn_12_2E2DC.c --- */
void fn_12_2E2DC(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = entry->field_0c * 1440000;
    b = entry->field_08 * 86400000;
    c = entry->field_10 * 24000;
    d = (entry->field_14 + entry->field_18) * 1000;
    *result = a + b + c + d;
    *out = 24000;
    *out = value;
}
/* fzgx:end fn_12_2E2DC */

/* fzgx:begin fn_12_2E334 noprologue */

/* --- rel/movie_module/fn_12_2E334.c --- */
typedef struct MovieTime {
    u8 padding0[8];
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 milliseconds;
    s32 extra;
} MovieTime;

void fn_12_2E334(s32 value, MovieTime *time, s32 *result, s32 *out_value) {
    s32 ms;
    s32 total;

    ms = (time->milliseconds + time->extra) * 0x3e8;
    total = time->minutes * 0x3c + time->hours * 0xe10 + time->seconds;
    *result = total * value + ms;
    *out_value = value;
}
/* fzgx:end fn_12_2E334 */

/* fzgx:begin fn_12_2E374 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2E374.c --- */
/* --- rel/movie_module/fn_12_2E374.c --- */
typedef u32 (*fn_12_2E374_Fn0)(u32, u32, u32, u32);

extern u32 lbl_12_rodata_E10;
extern u32 lbl_12_rodata_E34;
extern void fn_12_24A88(void *, int);

void fn_12_2E374(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1;
    v0 = *(u32 *)((u8 *)arg0 + 0);
    v1 = (v0 << 3);
    v2 = (v0 << 2);
    v3 = *(u32 *)((u8 *)&lbl_12_rodata_E10 + v2);
    if (*(u32 *)((u8 *)((u8 *)&lbl_12_rodata_E34 + v1) + (*(u32 *)((u8 *)arg0 + 4) << 2)) == 0) {
    v3 = 0;
    fn_12_24A88((void *)v3, (0xFF000000 + 545));
    v3 = 0;
    *(u32 *)((u8 *)arg1 + 0) = v3;
    *(u32 *)((u8 *)arg2 + 0) = 1;
    } else {
    t1 = ((fn_12_2E374_Fn0)*(u32 *)((u8 *)((u8 *)&lbl_12_rodata_E34 + v1) + (*(u32 *)((u8 *)arg0 + 4) << 2)))(v3, arg0, arg1, arg2);
    v3 = t1;
    }
}
/* fzgx:end fn_12_2E374 */

/* fzgx:begin fn_12_2E41C noprologue */

/* --- rel/movie_module/fn_12_2E41C.c --- */
typedef struct MovieModuleEntry {
    u8 padding[0xcc0];
    s32 value;
} MovieModuleEntry;

void fn_12_2E41C(MovieModuleEntry *base, s32 value, s32 index) {
    base = (MovieModuleEntry *)((u8 *)base + (index << 2));
    base->value = value;
}
/* fzgx:end fn_12_2E41C */

/* fzgx:begin fn_12_2E42C noprologue */

/* --- rel/movie_module/fn_12_2E42C.c --- */
extern void fn_12_332DC(void);

void fn_12_2E42C(void) {
    fn_12_332DC();
}
/* fzgx:end fn_12_2E42C */

/* fzgx:begin fn_12_2E44C noprologue */

/* --- rel/movie_module/fn_12_2E44C.c --- */
struct fn_12_2E44C_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct fn_12_2E44C_Arg1 {
    u32 unk_0;
};
struct fn_12_2E44C_Arg2 {
    u32 unk_0;
};

s32 fn_12_2E44C(struct fn_12_2E44C_Arg0 *arg0, struct fn_12_2E44C_Arg1 *arg1, struct fn_12_2E44C_Arg2 *arg2) {
    u32 v0;
    u32 v1;
    v0 = arg0->unk_48;
    v1 = (u32)arg0;
    if ((s32)v0 != 4) {
    if ((s32)v0 != -4) {
    if ((s32)v0 != 6) {
    if ((s32)v0 != -6) {
    v1 = -1;
    arg1->unk_0 = v1;
    v1 = 0;
    arg2->unk_0 = 1;
    return v1;
    }
    }
    }
    }
    v1 = 1;
    return v1;
}
/* fzgx:end fn_12_2E44C */

/* fzgx:begin fn_12_2E490 noprologue */

/* --- rel/movie_module/fn_12_2E490.c --- */
/* --- rel/movie_module/fn_12_2E490.c --- */
typedef s32 (*MovieModuleCb)(void *self, u32 *out1, u32 *out2);

typedef struct MovieModuleEntry_u1 {
    u8 pad_0[0x48];
    s32 value;
    u8 pad_4c[4];
    s32 unk_50;
    u8 pad_54[0x910];
    s32 unk_964;
    u8 pad_968[0x5e8];
    MovieModuleCb unk_f50;
    volatile s32 unk_f54; /* retail emits a fresh load here instead of reusing the value compared against -5 */
    volatile s32 unk_f58; /* same: loaded in source order before the subtract, matching retail register order */
    s32 unk_f5c;
} MovieModuleEntry_u1;

struct fn_12_2E490_Arg1 {
    u32 unk_0;
};
struct fn_12_2E490_Arg2 {
    u32 unk_0;
};

s32 fn_12_2E490(MovieModuleEntry_u1 *arg0, struct fn_12_2E490_Arg1 *arg1, struct fn_12_2E490_Arg2 *arg2) {
    u32 o2;
    u32 o1;
    s32 v;
    s32 w;
    s32 ret;
    if ((s32)arg0->value != 4 && (s32)arg0->value != -4 && (s32)arg0->value != 6 && (s32)arg0->value != -6) {
        arg1->unk_0 = -1;
        arg2->unk_0 = 1;
        v = 0;
    } else {
        v = 1;
    }
    if (v == 0) {
        return 0;
    }
    if (arg0->unk_f50 == 0) {
        arg1->unk_0 = -2;
        arg2->unk_0 = 1;
        return 0;
    }
    ret = arg0->unk_f50(arg0, &o2, &o1);
    if ((s32)arg0->value != 4) {
        w = 0;
    } else if (arg0->unk_50 != 0) {
        w = 0;
    } else if (arg0->unk_964 != 0) {
        w = 0;
    } else {
        w = 1;
    }
    if (w != 0) {
        if (arg0->unk_f54 != -5) {
            arg0->unk_f58 = arg0->unk_f58 + (o2 - arg0->unk_f54);
        }
    }
    arg0->unk_f54 = o2;
    arg0->unk_f5c = o1;
    arg1->unk_0 = arg0->unk_f58;
    arg2->unk_0 = arg0->unk_f5c;
    return ret;
}
/* fzgx:end fn_12_2E490 */

/* fzgx:begin fn_12_2E5E4 noprologue */

/* --- rel/movie_module/fn_12_2E5E4.c --- */
struct fn_12_2E5E4_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct fn_12_2E5E4_Arg1 {
    u32 unk_0;
};
struct fn_12_2E5E4_Arg2 {
    u32 unk_0;
};


s32 fn_12_2E5E4(struct fn_12_2E5E4_Arg0 *arg0, struct fn_12_2E5E4_Arg1 *arg1, struct fn_12_2E5E4_Arg2 *arg2) {
    u32 v0;
    s32 v1;
    v0 = arg0->unk_48;
    v1 = (u32)arg0;
    if ((s32)v0 != 4 && (s32)v0 != -4 && (s32)v0 != 6 && (s32)v0 != -6) {
    v1 = -1;
    arg1->unk_0 = v1;
    v1 = 0;
    arg2->unk_0 = 1;
    } else {
    v1 = 1;
    }
    if (v1 == 0) {
    v1 = 0;
    return v1;
    }
    v1 = 0;
    return v1;
}
/* fzgx:end fn_12_2E5E4 */

/* fzgx:begin fn_12_2E63C noprologue */

/* --- rel/movie_module/fn_12_2E63C.c --- */
struct fn_12_2E63C_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct fn_12_2E63C_Arg1 {
    u32 unk_0;
};
struct fn_12_2E63C_Arg2 {
    u32 unk_0;
};
struct fn_12_2E63C_lbl_12_bss_7C64 {
    u8 pad_0[0x1B8];
    u32 unk_1B8;
};

extern struct fn_12_2E63C_lbl_12_bss_7C64 lbl_12_bss_7C64;

s32 fn_12_2E63C(struct fn_12_2E63C_Arg0 *arg0, struct fn_12_2E63C_Arg1 *arg1, struct fn_12_2E63C_Arg2 *arg2, u32 arg3) {
    u32 v0;
    s32 v1;
    u32 v2;
    v0 = arg0->unk_48;
    v1 = arg3;
    if ((s32)v0 != 4 && (s32)v0 != -4 && (s32)v0 != 6 && (s32)v0 != -6) {
    v1 = -1;
    arg1->unk_0 = v1;
    v1 = 0;
    arg2->unk_0 = 1;
    } else {
    v1 = 1;
    }
    v2 = (u32)arg0;
    if (v1 == 0) {
    v2 = 0;
    return v2;
    }
    arg1->unk_0 = *(u32 *)((u8 *)v2 + 3876);
    arg2->unk_0 = lbl_12_bss_7C64.unk_1B8;
    return 0;
}
/* fzgx:end fn_12_2E63C */

/* fzgx:begin fn_12_2E6AC noprologue */

/* --- rel/movie_module/fn_12_2E6AC.c --- */
typedef struct MovieModuleState {
    u8 padding[0x48];
    s32 state;
} MovieModuleState;

s32 fn_12_2E6AC(MovieModuleState *movie, s32 *result, s32 *flag) {
    s32 valid;
    s32 state = movie->state;

    if (state != 4 && state != -4 && state != 6 && state != -6) {
        *result = -1;
        valid = 0;
        *flag = 1;
    } else {
        valid = 1;
    }

    if (valid == 0) {
        return 0;
    }

    *result = -2;
    valid = 0;
    *flag = 1;
    return valid;
}
/* fzgx:end fn_12_2E6AC */

/* fzgx:begin fn_12_2E714 noprologue */
#include "types.h"

typedef struct MovieModuleState MovieModuleState;
typedef s32 (*MovieCallback)(MovieModuleState *, s32 *, s32 *);

struct MovieModuleState {
    u8 padding_000[0xcc0];
    MovieCallback callbacks[1];
    u8 padding_001[0x244];
    s32 state;
    s32 value;
};

extern void fn_12_24970(s32 *);
extern s32 fn_12_2D73C(MovieModuleState *, s32);
extern s32 fn_12_24950(s32 *);
extern s32 fn_12_2E6AC(MovieModuleState *, s32 *, s32 *);

s32 fn_12_2E714(MovieModuleState *movie, s32 *result, s32 *flag) {
    s32 local;
    s32 state;
    s32 index;
    struct { MovieCallback value; } callback;

    state = movie->state;
    if (state == -5) {
        fn_12_24970(&local);
        index = fn_12_2D73C(movie, 15);
        callback.value = movie->callbacks[index];
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        state = callback.value(movie, result, flag);
        fn_12_24950(&local);
        return state;
    }

    *result = state;
    *flag = movie->value;
    return 0;
}
/* fzgx:end fn_12_2E714 */

/* fzgx:begin fn_12_2E7C8 noprologue */
#include "types.h"

typedef struct MovieModuleState MovieModuleState;
typedef s32 (*MovieCallback)(MovieModuleState *, s32 *, s32 *);

/* the block at handle+0xda4 (timer+0xe4): flag, then value and scale at +0x20/+0x24 */
typedef struct MovieModuleSnapshot {
    s32 unk_00;
    u8 unk_04[0x1c];
    s32 unk_20;
    s32 unk_24;
} MovieModuleSnapshot;

/* the timer block at handle+0xcc0 (fn_12_27478 reads the same block) */
typedef struct MovieModuleTimer {
    u8 unk_000[0xe4];
    MovieModuleSnapshot unk_e4;
    s32 unk_10c;
    s32 unk_110;
} MovieModuleTimer;

struct MovieModuleState {
    u8 unk_000[0xcc0];
    union {
        MovieCallback callbacks[1];
        MovieModuleTimer timer_state;
    } unk_cc0;
    u8 unk_dd4[0x134];
    s32 unk_f08;
    s32 unk_f0c;
};

extern void fn_12_24970(s32 *);
extern s32 fn_12_2D73C(MovieModuleState *, s32);
extern s32 fn_12_24950(s32 *);
extern s32 fn_12_2E6AC(MovieModuleState *, s32 *, s32 *);
unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);

#pragma use_lmw_stmw on

s32 fn_12_2E7C8(MovieModuleState *movie, s32 *time, s32 *unit) {
    s32 local;
    s32 state;
    s32 result;
    s32 index;
    struct { MovieCallback value; } callback;
    MovieModuleTimer *timer = &movie->unk_cc0.timer_state;
    MovieModuleSnapshot *snapshot = &timer->unk_e4;

    state = movie->unk_f08;
    if (state == -5) {
        fn_12_24970(&local);
        index = fn_12_2D73C(movie, 15);
        callback.value = movie->unk_cc0.callbacks[index];
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        result = callback.value(movie, time, unit);
        fn_12_24950(&local);
    } else {
        *time = state;
        result = 0;
        *unit = movie->unk_f0c;
    }
    if (*unit == 1) {
        return result;
    }
    if (*unit == timer->unk_110) {
        *time += timer->unk_10c;
    } else if (snapshot->unk_00 != 0) {
        *time += UTY_MulDiv(snapshot->unk_20, *unit, snapshot->unk_24);
    }
    return result;
}
/* fzgx:end fn_12_2E7C8 */

/* fzgx:begin fn_12_2E8C8 noprologue */
#include "types.h"

typedef struct MovieModuleState MovieModuleState;
typedef s32 (*MovieCallback)(MovieModuleState *, s32 *, s32 *);

/* the block at handle+0xda4 (timer+0xe4): flag, then value and scale at +0x20/+0x24 */
typedef struct MovieModuleSnapshot {
    s32 unk_00;
    u8 unk_04[0x1c];
    s32 unk_20;
    s32 unk_24;
} MovieModuleSnapshot;

/* the timer block at handle+0xcc0 (fn_12_27478 reads the same block) */
typedef struct MovieModuleTimer {
    u8 unk_000[0xe4];
    MovieModuleSnapshot unk_e4;
    s32 unk_10c;
    s32 unk_110;
} MovieModuleTimer;

struct MovieModuleState {
    u8 unk_000[0xcc0];
    union {
        MovieCallback callbacks[1];
        MovieModuleTimer timer_state;
    } unk_cc0;
    u8 unk_dd4[0x134];
    s32 unk_f08;
    s32 unk_f0c;
};

extern void fn_12_24970(s32 *);
extern s32 fn_12_2D73C(MovieModuleState *, s32);
extern s32 fn_12_24950(s32 *);
extern s32 fn_12_2E6AC(MovieModuleState *, s32 *, s32 *);
unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);
extern s32 fn_12_24990(MovieModuleState *);
extern s32 fn_12_24A88(MovieModuleState *, s32);

#pragma use_lmw_stmw on

/* the body of fn_12_2E7C8, which retail inlines here */
static inline s32 fn_12_2E7C8_inline(MovieModuleState *movie, s32 *time, s32 *unit) {
    s32 local;
    s32 state;
    s32 result;
    s32 index;
    struct { MovieCallback value; } callback;
    MovieModuleTimer *timer = &movie->unk_cc0.timer_state;
    MovieModuleSnapshot *snapshot = &timer->unk_e4;

    state = movie->unk_f08;
    if (state == -5) {
        fn_12_24970(&local);
        index = fn_12_2D73C(movie, 15);
        callback.value = movie->unk_cc0.callbacks[index];
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        result = callback.value(movie, time, unit);
        fn_12_24950(&local);
    } else {
        *time = state;
        result = 0;
        *unit = movie->unk_f0c;
    }
    if (*unit == 1) {
        return result;
    }
    if (*unit == timer->unk_110) {
        *time += timer->unk_10c;
    } else if (snapshot->unk_00 != 0) {
        *time += UTY_MulDiv(snapshot->unk_20, *unit, snapshot->unk_24);
    }
    return result;
}

s32 fn_12_2E8C8(MovieModuleState *movie, s32 *time, s32 *unit) {
    if (fn_12_24990(movie) != 0) {
        return fn_12_24A88(0, 0xff000121);
    }
    return fn_12_2E7C8_inline(movie, time, unit);
}
/* fzgx:end fn_12_2E8C8 */

/* fzgx:begin fn_12_2E9E4 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2E9E4.c --- */
/* --- rel/movie_module/fn_12_2E9E4.c --- */
/* --- rel/movie_module/fn_12_2E9E4.c --- */
typedef struct MovieModuleState {
    u8 padding_000[0x10c];
    u32 field_10c;
    u32 field_110;
} MovieModuleState;

void fn_12_2E9E4(MovieModuleState *state, u32 value1, u32 value2) {
    state->field_10c = value1;
    state->field_110 = value2;
}
/* fzgx:end fn_12_2E9E4 */

/* fzgx:begin fn_12_2E9F0 noprologue */

/* --- rel/movie_module/fn_12_2E9F0.c --- */
struct fn_12_2E9F0_Arg0 {
    u8 pad_0[0xE4];
    u32 unk_E4;
};
struct fn_12_2E9F0_Arg2 {
    u32 unk_0;
};

extern u32 UTY_MulDiv(u32, u32, u32);
extern u32 lbl_12_bss_1B730;
extern u32 lbl_12_bss_1B734;

u32 fn_12_2E9F0(struct fn_12_2E9F0_Arg0 *arg0, u32 arg1, struct fn_12_2E9F0_Arg2 *arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0;
    arg2->unk_0 = arg0->unk_E4;
    v1 = (u32)arg2;
    v2 = (u32)arg0;
    if ((s32)arg2->unk_0 != 0) {
    v0 = *(u32 *)((u8 *)v2 + 260);
    v1 = *(u32 *)((u8 *)v2 + 264);
    } else {
    v3 = *(u32 *)((u8 *)v2 + 220);
    if ((s32)v3 >= 0) {
    v1 = *(u32 *)((u8 *)v2 + 224);
    v0 = v3;
    } else {
    v2 = -1;
    return v2;
    }
    }
    v2 = v0;
    t0 = UTY_MulDiv(v2, arg1, v1);
    v2 = t0;
    lbl_12_bss_1B734 = v0;
    lbl_12_bss_1B730 = v2;
    return v2;
}
/* fzgx:end fn_12_2E9F0 */

/* fzgx:begin fn_12_2EA6C noprologue */

/* --- rel/movie_module/fn_12_2EA6C.c --- */
typedef struct MovieModuleState_u1 {
    u8 padding_000[0x118];
    int field_118;
} MovieModuleState_u1;

extern u32 lbl_12_bss_1B73C;
extern u32 lbl_12_bss_1B738;

int fn_12_2EA6C(MovieModuleState_u1 *state, int value) {
    int result;

    if (state->field_118 < 0) {
        return -1;
    }

    result = UTY_MulDiv(state->field_118, value, 0x57e4);
    lbl_12_bss_1B73C = state->field_118;
    lbl_12_bss_1B738 = result;
    return result;
}
/* fzgx:end fn_12_2EA6C */

/* fzgx:begin fn_12_2EAC4 noprologue */

/* --- rel/movie_module/fn_12_2EAC4.c --- */
typedef struct MovieObject {
    u8 pad_0000[0xf24];
    s32 field_f24;
    u8 pad_f28[0x24];
    s32 field_f4c;
    u8 pad_f50[0x8];
    s32 field_f58;
    s32 field_f5c;
} MovieObject;

extern int fn_12_2D73C(MovieObject *obj, int id);
extern u32 lbl_12_bss_7C64[137];
extern int fn_12_24A88(MovieObject *obj, int value);

#pragma opt_propagation off
int fn_12_2EAC4(MovieObject *obj) {
    u32 *table;
    int result;
    int num;
    int den;
    int flag;

    if (!fn_12_2D73C(obj, 6)) {
        flag = 0;
    } else {
        result = fn_12_2D73C(obj, 0x33);
        if (!result) {
            flag = 0;
        } else {
            table = (u32 *)&lbl_12_bss_7C64[0];

            if (fn_12_2D73C(obj, 0x47) == 1) {
                num = obj->field_f24 - obj->field_f4c;
                den = ((table)[110]);
            } else {
                s32 a = obj->field_f58;
                s32 b = obj->field_f4c;
                num = a - b;
                den = obj->field_f5c;
            }

            num = num / den;

            if (num > result) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
    }

    if (flag) {
        fn_12_24A88(obj, 0xff000222);
        return 1;
    }

    return 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_12_2EAC4 */

/* fzgx:begin fn_12_2EBAC noprologue */
#include "types.h"

typedef struct MovieObject MovieObject;
typedef s32 (*MovieCallback)(MovieObject *, s32 *, s32 *);

struct MovieObject {
    u8 pad_000[0x44];
    s32 field_044;
    s32 field_048;
    s32 field_04c;
    s32 field_050;
    u8 pad_054[0x910];
    s32 field_964;
    u8 pad_968[0x358];
    MovieCallback callbacks[16];
    u8 pad_d00[0x208];
    s32 field_f08;
    s32 field_f0c;
    u8 pad_f10[0x14];
    s32 field_f24;
    s32 field_f28;
    u8 pad_f2c[0x1c];
    s32 field_f48;
    s32 field_f4c;
    u8 pad_f50[0x8];
    s32 field_f58;
};

extern u32 lbl_12_bss_7C64[137];
extern s32 fn_12_2D73C(MovieObject *obj, s32 id);
extern void fn_12_24970(s32 *);
extern void fn_12_24950(s32 *);
extern s32 fn_12_2E6AC(MovieObject *obj, s32 *, s32 *);

void fn_12_2EBAC(void) {
    MovieObject **table = (MovieObject **)&lbl_12_bss_7C64[129];
    s32 i;
    s32 flag;
    MovieObject *obj;
    s32 w2;
    s32 w1;
    s32 w0;
    s32 index;
    struct { MovieCallback value; } callback;

    lbl_12_bss_7C64[108]++;

    for (i = 0; i < 8; i++) {
        obj = table[i];
        if (obj != 0) {
            if (obj->field_048 != 4) {
                flag = 0;
            } else if (obj->field_050 != 0) {
                flag = 0;
            } else if (obj->field_964 != 0) {
                flag = 0;
            } else {
                flag = 1;
            }
            if (flag) {
                obj->field_f24 = obj->field_f24 + obj->field_f28;
            }
            if (obj->field_f48 == -1) {
                flag = 0;
            } else if (obj->field_04c != 4) {
                flag = 0;
            } else {
                flag = 1;
            }
            if (flag) {
                obj->field_f48 = obj->field_f48 + obj->field_f28;
            }
            if (fn_12_2D73C(obj, 0x47) == 1) {
                fn_12_24970(&w0);
                index = fn_12_2D73C(obj, 15);
                callback.value = obj->callbacks[index];
                if (callback.value == 0) {
                    callback.value = fn_12_2E6AC;
                }
                callback.value(obj, &w1, &w2);
                fn_12_24950(&w0);
                if (obj->field_f08 != w1 || obj->field_f0c != w2) {
                    if (fn_12_2D73C(obj, 0x47) == 1) {
                        obj->field_f4c = obj->field_f24;
                    } else {
                        obj->field_f4c = obj->field_f58;
                    }
                    obj->field_f08 = w1;
                    obj->field_f0c = w2;
                }
                obj->field_044 = 1;
            }
        }
    }
}
/* fzgx:end fn_12_2EBAC */

/* fzgx:begin fn_12_2ED74 noprologue */
#include "types.h"

typedef struct MovieModuleState {
    u8 padding_000[0x250];
    s32 field_250;
    s32 field_254;
    s32 field_258;
} MovieModuleState;

s32 fn_12_2ED74(MovieModuleState *state, s32 value) {
    s32 first = state->field_250;
    s32 second = state->field_254;
    s32 third = state->field_258;
    s32 first_sum;
    s32 second_sum;

    first_sum = first + second;
    second_sum = first + third;
    if (value < first_sum) {
        return first_sum;
    }
    if (value < second_sum) {
        return second_sum;
    }
    return 0x7fffffff;
}
/* fzgx:end fn_12_2ED74 */

/* fzgx:begin fn_12_2EDAC noprologue */
#include "types.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_2EDAC.c --- */
typedef struct MovieModuleState {
    u8 padding_000[0x250];
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
} MovieModuleState;

void fn_12_2EDAC(MovieModuleState *state, int value) {
    int difference;
    int result;
    int current;

    if (state->field_250 == -5) {
        state->field_250 = value;
        return;
    }

    difference = value - state->field_250;
    if (difference == 0) {
        return;
    }

    state->field_250 = value;

    result = difference;
    current = state->field_258;
    if (current > difference) {
        result = current;
    }
    state->field_258 = result;

    result = difference;
    current = state->field_25C;
    if (current < difference) {
        result = current;
    }
    state->field_25C = result;

    current = state->field_254;
    if (current == 0x7fffffff) {
        state->field_254 = difference;
        return;
    }

    if (current <= difference) {
        state->field_254 = difference;
        return;
    }

    result = (current - difference) / 8;
    if (result != 0) {
        state->field_254 = current - result;
        return;
    }

    state->field_254 = difference;
}
/* fzgx:end fn_12_2EDAC */

/* fzgx:begin fn_12_2EE48 noprologue */

/* --- rel/movie_module/fn_12_2EE48.c --- */
/* --- rel/movie_module/fn_12_2EE48.c --- */
typedef struct MovieModuleState_u1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
} MovieModuleState_u1;

void fn_12_2EE48(MovieModuleState_u1 *state, int value) {
    state->field_0 = 0;
    state->field_4 = 0;
    state->field_8 = 0;
    state->field_C = 0;
    state->field_10 = 0;
    state->field_14 = 0;
    state->field_18 = 0;
    state->field_1C = 0;
    state->field_20 = value;
    state->field_24 = 1;
}
/* fzgx:end fn_12_2EE48 */

/* fzgx:begin fn_12_2EE7C noprologue */

/* --- rel/movie_module/fn_12_2EE7C.c --- */
extern s32 fn_12_2E6AC();
extern s32 fn_12_2E63C();
extern s32 fn_12_2E5E4();
extern u32 fn_12_2E490();
extern const f32 lbl_12_rodata_E8C;
struct fn_12_2EE7C_Arg0 { u8 pad_0[0xCC0]; u32 unk_CC0, unk_CC4, unk_CC8, unk_CCC, unk_CD0, unk_CD4; };
struct fn_12_2EE7C_Arg1 { u8 pad_0[0x18];
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u32 unk_28;
u32 unk_2C;
u32 unk_30;
u32 unk_34;
u32 unk_38;
u32 unk_3C;
u32 unk_40;
u32 unk_44;
u32 unk_48;
u32 unk_4C;
u32 unk_50;
u32 unk_54;
u32 unk_58;
u32 unk_5C;
u32 unk_60;
u32 unk_64;
u32 unk_68;
u32 unk_6C;
u32 unk_70;
u32 unk_74;
u32 unk_78;
u32 unk_7C;
u32 unk_80;
u32 unk_84;
u32 unk_88;
u32 unk_8C;
u32 unk_90;
u32 unk_94;
u32 unk_98;
u32 unk_9C;
u32 unk_A0;
u32 unk_A4;
u32 unk_A8;
u32 unk_AC;
u32 unk_B0;
u32 unk_B4;
u32 unk_B8;
u32 unk_BC;
u32 unk_C0;
u32 unk_C4;
u32 unk_C8;
u32 unk_CC;
u32 unk_D0;
u32 unk_D4;
u32 unk_D8;
u32 unk_DC;
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u32 array_128[32];
u32 unk_1A8;
u32 unk_1AC;
u32 unk_1B0;
u32 unk_1B4;
u32 array_1B8[32];
u32 unk_238;
u32 unk_23C;
u32 unk_240;
u32 unk_244;
u32 unk_248;
u32 unk_24C;
u32 unk_250;
u32 unk_254;
u32 unk_258;
u32 unk_25C;
u32 unk_260;
u32 unk_264;
u32 unk_268;
u32 unk_26C;
u32 unk_270;
u32 unk_274;
u32 unk_278;
f32 unk_27C;
u32 unk_280;
f32 unk_284;
u32 unk_288;
u32 unk_28C;
u32 unk_290;
u32 unk_294;
u32 unk_298;
u32 unk_29C;
};
void fn_12_2EE7C(struct fn_12_2EE7C_Arg0 *arg0, struct fn_12_2EE7C_Arg1 *arg1) {
int i;
arg0->unk_CC0 = (u32)fn_12_2E6AC;
arg0->unk_CC4 = (u32)fn_12_2E63C;
arg0->unk_CC8 = 0;
arg0->unk_CCC = (u32)fn_12_2E5E4;
arg0->unk_CD0 = 0;
arg0->unk_CD4 = (u32)fn_12_2E490;
arg1->unk_18 = 0;
arg1->unk_94 = 0;
arg1->unk_98 = 0;
arg1->unk_9C = 0;
arg1->unk_A0 = 0;
arg1->unk_A4 = 0;
arg1->unk_A8 = 0;
arg1->unk_AC = 0;
arg1->unk_B0 = 0;
arg1->unk_B4 = 0;
arg1->unk_B8 = 1;
arg1->unk_1C = 0;
arg1->unk_20 = 0;
arg1->unk_24 = 0;
arg1->unk_28 = 0;
arg1->unk_2C = 0;
arg1->unk_30 = 0;
arg1->unk_34 = 0;
arg1->unk_38 = 0;
arg1->unk_3C = 0x7fffffff;
arg1->unk_40 = 1;
arg1->unk_44 = 0;
arg1->unk_48 = 0;
arg1->unk_4C = 0;
arg1->unk_50 = 0;
arg1->unk_54 = 0;
arg1->unk_58 = 0;
arg1->unk_5C = 0;
arg1->unk_60 = 0;
arg1->unk_64 = -1;
arg1->unk_68 = 1;
arg1->unk_6C = 0;
arg1->unk_70 = 0;
arg1->unk_74 = 0;
arg1->unk_78 = 0;
arg1->unk_7C = 0;
arg1->unk_80 = 0;
arg1->unk_84 = 0;
arg1->unk_88 = 0;
arg1->unk_8C = -1;
arg1->unk_90 = 1;
arg1->unk_BC = 0;
arg1->unk_C0 = 0;
arg1->unk_C4 = 0;
arg1->unk_C8 = 0;
arg1->unk_CC = 0;
arg1->unk_D0 = 0;
arg1->unk_D4 = 0;
arg1->unk_D8 = 0;
arg1->unk_DC = -1;
arg1->unk_E0 = 1;
arg1->unk_E4 = 0;
arg1->unk_E8 = 0;
arg1->unk_EC = 0;
arg1->unk_F0 = 0;
arg1->unk_F4 = 0;
arg1->unk_F8 = 0;
arg1->unk_FC = 0;
arg1->unk_100 = 0;
arg1->unk_104 = 0x7fffffff;
arg1->unk_108 = 1;
arg1->unk_10C = 0;
arg1->unk_110 = 0;
arg1->unk_114 = -1;
arg1->unk_118 = -1;
arg1->unk_11C = 0;
arg1->unk_120 = 0;
arg1->unk_124 = 0;
i = 0;
if (i < 32) {
arg1->array_128[0] = 0;
arg1->array_128[1] = 0;
arg1->array_128[2] = 0;
arg1->array_128[3] = 0;
arg1->array_128[4] = 0;
arg1->array_128[5] = 0;
arg1->array_128[6] = 0;
arg1->array_128[7] = 0;
arg1->array_128[8] = 0;
arg1->array_128[9] = 0;
arg1->array_128[10] = 0;
arg1->array_128[11] = 0;
arg1->array_128[12] = 0;
arg1->array_128[13] = 0;
arg1->array_128[14] = 0;
arg1->array_128[15] = 0;
arg1->array_128[16] = 0;
arg1->array_128[17] = 0;
arg1->array_128[18] = 0;
arg1->array_128[19] = 0;
arg1->array_128[20] = 0;
arg1->array_128[21] = 0;
arg1->array_128[22] = 0;
arg1->array_128[23] = 0;
arg1->array_128[24] = 0;
arg1->array_128[25] = 0;
arg1->array_128[26] = 0;
arg1->array_128[27] = 0;
arg1->array_128[28] = 0;
arg1->array_128[29] = 0;
arg1->array_128[30] = 0;
arg1->array_128[31] = 0;
}
arg1->unk_1A8 = 1;
arg1->unk_1AC = 0;
arg1->unk_1B0 = 0;
arg1->unk_1B4 = 0;
i = 0;
if (i < 32) {
arg1->array_1B8[0] = 0;
arg1->array_1B8[1] = 0;
arg1->array_1B8[2] = 0;
arg1->array_1B8[3] = 0;
arg1->array_1B8[4] = 0;
arg1->array_1B8[5] = 0;
arg1->array_1B8[6] = 0;
arg1->array_1B8[7] = 0;
arg1->array_1B8[8] = 0;
arg1->array_1B8[9] = 0;
arg1->array_1B8[10] = 0;
arg1->array_1B8[11] = 0;
arg1->array_1B8[12] = 0;
arg1->array_1B8[13] = 0;
arg1->array_1B8[14] = 0;
arg1->array_1B8[15] = 0;
arg1->array_1B8[16] = 0;
arg1->array_1B8[17] = 0;
arg1->array_1B8[18] = 0;
arg1->array_1B8[19] = 0;
arg1->array_1B8[20] = 0;
arg1->array_1B8[21] = 0;
arg1->array_1B8[22] = 0;
arg1->array_1B8[23] = 0;
arg1->array_1B8[24] = 0;
arg1->array_1B8[25] = 0;
arg1->array_1B8[26] = 0;
arg1->array_1B8[27] = 0;
arg1->array_1B8[28] = 0;
arg1->array_1B8[29] = 0;
arg1->array_1B8[30] = 0;
arg1->array_1B8[31] = 0;
}
arg1->unk_238 = -5;
arg1->unk_23C = 1;
arg1->unk_240 = -5;
arg1->unk_244 = 1;
arg1->unk_248 = -5;
arg1->unk_24C = 1;
arg1->unk_250 = -5;
arg1->unk_254 = 0x7fffffff;
arg1->unk_258 = 0;
arg1->unk_25C = 0x7fffffff;
arg1->unk_260 = 0;
arg1->unk_264 = 0;
arg1->unk_268 = 1000;
arg1->unk_26C = 0;
arg1->unk_270 = 0;
arg1->unk_274 = 1;
arg1->unk_278 = 100;
arg1->unk_27C = lbl_12_rodata_E8C;
arg1->unk_280 = 0;
arg1->unk_284 = lbl_12_rodata_E8C;
arg1->unk_288 = -1;
arg1->unk_28C = arg1->unk_264;
arg1->unk_290 = 0;
arg1->unk_294 = -5;
arg1->unk_298 = 0;
arg1->unk_29C = 1;
}
/* fzgx:end fn_12_2EE7C */

/* fzgx:begin fn_12_2F19C noprologue */

/* --- rel/movie_module/fn_12_2F19C.c --- */
// fn_12_2F19C: empty in retail (single blr).
void fn_12_2F19C(void) {
}
/* fzgx:end fn_12_2F19C */

/* fzgx:begin fn_12_2F1A0 noprologue */

/* --- rel/movie_module/fn_12_2F1A0.c --- */
typedef struct MovieModuleState_u2 {
    int field_0;
    int field_4;
    int field_8;
} MovieModuleState_u2;

void fn_12_2F1A0(MovieModuleState_u2 *state, int value) {
    state->field_0 = 0;
    state->field_4 = 0;
    state->field_8 = value;
}
/* fzgx:end fn_12_2F1A0 */
