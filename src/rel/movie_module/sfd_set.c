#include "types.h"

/* fzgx:begin fn_12_2D500 noprologue */
#include "types.h"

extern u32 fn_12_24990(u32, u32, u32);
extern u32 fn_12_24A88(u32, u32);

s32 fn_12_2D500(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_24990(arg0, arg1, arg2);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_24A88(v0, (0xFF000000 + 279));
    v0 = t1;
    } else {
    v0 = (arg0 + (arg1 * 68));
    v0 = *(u32 *)((u8 *)v0 + 6824);
    if (v0 == 0) {
    *(u32 *)((u8 *)arg2 + 0) = 0;
    } else {
    *(u32 *)((u8 *)arg2 + 0) = *(u32 *)((u8 *)v0 + 0);
    }
    v0 = 0;
    }
    return v0;
}
/* fzgx:end fn_12_2D500 */

/* fzgx:begin fn_12_2D58C noprologue */
#include "types.h"

struct fn_12_2D58C_Copy64 { u32 a[16]; };

extern s32 fn_12_24990(u32);
extern s32 fn_12_24A88(void *, s32);

s32 fn_12_2D58C(u32 arg0, u32 arg1) {
    s32 t0;
    t0 = fn_12_24990(arg0);
    if (t0 != 0) {
    return fn_12_24A88(0, 0xFF000000 + 281);
    }
    *(struct fn_12_2D58C_Copy64 *)((u8 *)arg1 + 0) = *(struct fn_12_2D58C_Copy64 *)((u8 *)arg0 + 2380);
    return 0;
}
/* fzgx:end fn_12_2D58C */

/* fzgx:begin fn_12_2D664 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2D664.c --- */
extern int fn_12_24990(u8 *base, u8 *out);
extern int fn_12_24A88(int value, u32 code);

typedef struct MovieData {
    u32 values[16];
} MovieData;

int fn_12_2D664(u8 *base, u8 *out) {
    if (fn_12_24990(base, out) != 0) {
        return fn_12_24A88(0, 0xff000114);
    } else {
        *(MovieData *)out = *(MovieData *)(base + 0x90c);
        return 0;
    }
}
/* fzgx:end fn_12_2D664 */

/* fzgx:begin fn_12_2D73C noprologue */

/* --- rel/movie_module/fn_12_2D73C.c --- */
u32 fn_12_2D73C(u8 *base, int index) {
    u8 *entry = base;
    entry += index << 2;
    return *(u32 *)(entry + 0x9a0);
}
/* fzgx:end fn_12_2D73C */

/* fzgx:begin fn_12_2D74C noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2D74C.c --- */
extern u32 lbl_12_bss_7C64[137];
extern int fn_12_24990(u8 *base, int index, u32 *out);
extern s32 fn_12_24A88(int arg0, u32 arg1);

u32 fn_12_2D74C(u8 *base, int index, u32 *out) {
    u8 *entry = base;

    if (base == 0) {
        *out = lbl_12_bss_7C64[index];
    } else if (fn_12_24990(base, index, out)) {
        return fn_12_24A88(0, 0xff000113u);
    } else {
        entry += index << 2;
        *out = *(u32 *)(entry + 0x9a0);
    }
    return 0;
}
/* fzgx:end fn_12_2D74C */

/* fzgx:begin fn_12_2D7DC noprologue */

/* --- rel/movie_module/fn_12_2D7DC.c --- */
extern int fn_12_2F1B4(u8 *base, int index);

void fn_12_2D7DC(u8 *base, int index, int value) {
    int allowed;

    if (index == 6 && value == 1 && fn_12_2F1B4(base, 3) == 0) {
        allowed = 0;
    } else if (index == 5 && value == 1 && fn_12_2F1B4(base, 2) == 0) {
        allowed = 0;
    } else {
        allowed = 1;
    }

    if (allowed != 0) {
        u8 *entry = base;
        entry += index << 2;
        *(int *)(entry + 0x9a0) = value;
    }
}
/* fzgx:end fn_12_2D7DC */

/* fzgx:begin fn_12_2D888 noprologue */
#include "types.h"

extern u32 lbl_12_bss_7C64[137];
extern int fn_12_2F1B4(u8 *base, int index);
extern int fn_12_24990(void);
extern s32 fn_12_24A88(int, u32);

int fn_12_2D888(u8 *base, int index, int value) {
    int allowed;

    if (base == 0) {
        u32 entry;
        int i;
        u8 **p;
        int offset;

        offset = index << 2;
        p = (u8 **)((u8 *)&lbl_12_bss_7C64 + 0x204);
        for (i = 0; i < 8; i++, p++) {
            entry = (u32)*p;
            if (entry != 0) {
                if (((6) == (index)) && value == 1 &&
                    fn_12_2F1B4((u8 *)entry, 3) == 0) {
                    allowed = 0;
                } else if (index == 5 && value == 1 &&
                           fn_12_2F1B4((u8 *)entry, 2) == 0) {
                    allowed = 0;
                } else {
                    allowed = 1;
                }
                if (allowed != 0) {
                    *(int *)(offset + entry + 0x9a0) = value;
                }
            }
        }
        *(int *)((u8 *)lbl_12_bss_7C64 + offset) = value;
    } else {
        if (fn_12_24990() != 0) {
            return fn_12_24A88(0, 0xff000112);
        } else {
            if (((6) == (index)) && value == 1 &&
                fn_12_2F1B4(base, 3) == 0) {
                allowed = 0;
            } else if (index == 5 && value == 1 &&
                       fn_12_2F1B4(base, 2) == 0) {
                allowed = 0;
            } else {
                allowed = 1;
            }
            if (allowed != 0) {
                u8 *ptr = base;
                ptr += index << 2;
                *(int *)(ptr + 0x9a0) = value;
            }

            if (((6) == (index)) && value == 1 &&
                fn_12_2F1B4(base, 3) == 0) {
                allowed = 0;
            } else if (index == 5 && value == 1 &&
                       fn_12_2F1B4(base, 2) == 0) {
                allowed = 0;
            } else {
                allowed = 1;
            }
            if (allowed != 0) {
                u8 *ptr = base;
                ptr += index << 2;
                *(int *)(ptr + 0xb30) = value;
            }
        }
    }
    return 0;
}

/* fzgx:end fn_12_2D888 */

/* fzgx:begin fn_12_2DA6C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2DA6C.c --- */
typedef struct MovieModule {
    u8 pad_0[0x48];
    u32 value;
} MovieModule;

extern int fn_12_24990(MovieModule *module);
extern void fn_12_24A88(int arg0, int arg1);

u32 fn_12_2DA6C(MovieModule *module) {
    if (fn_12_24990(module) != 0) {
        fn_12_24A88(0, (int)0xff000111);
    }
    return module->value;
}
/* fzgx:end fn_12_2DA6C */
