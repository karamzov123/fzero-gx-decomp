#include "types.h"

/* fzgx:begin fn_12_2ACA8 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2AC98.c --- */
/* --- rel/movie_module/fn_12_2AC98.c --- */
typedef struct MovieModule_u5 {
    u8 pad_0000[0x1b30];
    struct MovieState_u5 *state;
} MovieModule_u5;

typedef struct MovieState_u5 {
    u8 pad_0000[0x7c];
    int field_007c;
} MovieState_u5;

/* --- rel/movie_module/fn_12_2ACA8.c --- */
typedef struct MovieModule_u5 MovieModule_u5;

extern int fn_12_24990(MovieModule_u5 *module, const char *name);
extern int fn_12_24A88(int value, u32 address);
extern void fn_12_2D7DC(MovieModule_u5 *module, int value, const char *name);

int fn_12_2ACA8(MovieModule_u5 *module, const char *name) {
    if (fn_12_24990(module, name)) {
        return fn_12_24A88(0, 0xff000146);
    }

    fn_12_2D7DC(module, 0x1d, name);
    return 0;
}
/* fzgx:end fn_12_2ACA8 */

/* fzgx:begin fn_12_2AD10 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2AD10.c --- */
extern int fn_12_24990(void *module);
extern int fn_12_24A88(int value, int code);
extern void fn_12_2D7DC(void *module, int value, int argument);

int fn_12_2AD10(void *module, int argument) {
    if (fn_12_24990(module)) {
        return fn_12_24A88(0, 0xff000145);
    }
    fn_12_2D7DC(module, 0x1e, argument);
    return 0;
}
/* fzgx:end fn_12_2AD10 */

/* fzgx:begin fn_12_2AD78 noprologue */

/* --- rel/movie_module/fn_12_2AD78.c --- */
struct MovieModule {
    char pad_4c[0x4c];
    int value;
};

int fn_12_2AD78(struct MovieModule *module) {
    module->value = 3;
    return 0;
}
/* fzgx:end fn_12_2AD78 */

/* fzgx:begin fn_12_2AD88 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2AD88.c --- */
extern u32 fn_12_24990(u32);
extern u32 fn_12_24A88(u32, u32);

s32 fn_12_2AD88(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_24990(arg0);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_24A88(v0, (0xFF000000 + 323));
    v0 = t1;
    } else {
    v0 = 0;
    *(u32 *)((u8 *)arg0 + 76) = 3;
    }
    return v0;
}
/* fzgx:end fn_12_2AD88 */

/* fzgx:begin fn_12_2ADDC noprologue */

/* --- rel/movie_module/fn_12_2ADDC.c --- */
typedef struct Sig_fn_12_2DFF0_MovieModule {
    u8 pad_0[0x920];
    s32 movie_index;
    u8 pad_924[0xF24 - 0x924];
    s32 total_a;
    u8 pad_F28[0xF48 - 0xF28];
    s32 total_b;
    u8 pad_F4C[0xF58 - 0xF4C];
    s32 total_c;
    s32 movie_id;
} Sig_fn_12_2DFF0_MovieModule;
typedef u32 (*Sig_fn_12_2F210_fn_12_2F210_Fn0)(u32, u32, u32, u32);
struct Sig_fn_12_2F210_fn_12_2F210_arg0_1A90_E68 {
    u8 pad_0[0x1C];
    Sig_fn_12_2F210_fn_12_2F210_Fn0 *unk_1C;
    u8 pad_20[0x24];
};
struct Sig_fn_12_2F210_fn_12_2F210_Arg0 {
    u8 pad_0[0x1A90];
    struct Sig_fn_12_2F210_fn_12_2F210_arg0_1A90_E68 unk_1A90[1];
};
extern u32 fn_12_2F210(struct Sig_fn_12_2F210_fn_12_2F210_Arg0 *, u32, u32, u32, u32);
extern void fn_12_2DFF0(Sig_fn_12_2DFF0_MovieModule *, s32);

static inline u32 movie_action(u32 arg0, s32 action) {
    u32 result;
    u32 t;
    if ((s32)*(u32 *)((u8 *)arg0 + 76) != 3 && (s32)*(u32 *)((u8 *)arg0 + 76) != 4) {
        result = 0;
    } else {
        fn_12_2DFF0((Sig_fn_12_2DFF0_MovieModule *)arg0, action);
        t = fn_12_2F210((struct Sig_fn_12_2F210_fn_12_2F210_Arg0 *)arg0, 7, 8, action, 0);
        result = 0;
        if ((s32)t != 0) {
            result = t;
        }
    }
    return result;
}

u32 fn_12_2ADDC(u32 arg0, u32 arg1) {
    s32 v0;
    u32 v1;
    v0 = 0;
    switch ((s32)arg1) {
    case 2:
        if ((s32)*(u32 *)((u8 *)arg0 + 72) == 4) {
            v0 = movie_action(arg0, 2);
        }
        break;
    case 1:
        v1 = *(u32 *)((u8 *)arg0 + 84);
        *(u32 *)((u8 *)arg0 + 84) = v1 + 1;
        if ((s32)v1 == 0) {
            v0 = movie_action(arg0, 1);
        }
        break;
    case 0:
        if (--*(u32 *)((u8 *)arg0 + 84) == 0) {
            v0 = movie_action(arg0, 0);
        }
        break;
    }
    return v0;
}
/* fzgx:end fn_12_2ADDC */

/* fzgx:begin fn_12_2AF5C noprologue */
#include "types.h"

struct MovieModule {
    char pad_44[0x44];
    int flag_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
};

extern int fn_12_24990(struct MovieModule *module);
extern int fn_12_24A88(int value, u32 code);
extern void fn_12_2DFF0(struct MovieModule *module, int value);
extern int fn_12_2F210(struct MovieModule *module, int value, int size, int data, int flags);

int fn_12_2AF5C(struct MovieModule *module, int flag) {
    int result;
    int state;
    int v;
    int cur;

    if (fn_12_24990(module)) {
        return fn_12_24A88(0, 0xff000142);
    }

    cur = module->field_50;
    if (flag == 0) {
        if (cur == 0) {
            return 0;
        }
        state = 0;
    } else if (cur == 0) {
        state = 1;
    } else {
        state = 2;
    }

    result = 0;
    module->field_50 = flag;

    switch (state) {
    case 2:
        if (module->field_48 == 4) {
            switch (module->field_4C) {
            case 3:
                /* shared action block: the two accepted field_4C values dispatch here */
                goto action2;
            default:
                switch (module->field_4C) {
                case 4:
                    /* shared action block: the second accepted field_4C value dispatches here */
                    goto action2;
                }
            }
            break;
        action2:
            fn_12_2DFF0(module, 2);
            v = fn_12_2F210(module, 7, 8, 2, 0);
            result = 0;
            if (v != 0) {
                result = v;
            }
        }
        break;
    case 1:
        if (module->field_54++ == 0) {
            switch (module->field_4C) {
            case 3:
                /* shared action block: the two accepted field_4C values dispatch here */
                goto action1;
            default:
                switch (module->field_4C) {
                case 4:
                    /* shared action block: the second accepted field_4C value dispatches here */
                    goto action1;
                }
            }
            break;
        action1:
            fn_12_2DFF0(module, 1);
            v = fn_12_2F210(module, 7, 8, 1, 0);
            result = 0;
            if (v != 0) {
                result = v;
            }
        }
        break;
    case 0:
        if (--module->field_54 == 0) {
            switch (module->field_4C) {
            case 3:
                /* shared action block: the two accepted field_4C values dispatch here */
                goto action0;
            default:
                switch (module->field_4C) {
                case 4:
                    /* shared action block: the second accepted field_4C value dispatches here */
                    goto action0;
                }
            }
            break;
        action0:
            fn_12_2DFF0(module, 0);
            v = fn_12_2F210(module, 7, 8, 0, 0);
            result = 0;
            if (v != 0) {
                result = v;
            }
        }
        break;
    }

    module->flag_44 = 1;
    return result;
}
/* fzgx:end fn_12_2AF5C */
