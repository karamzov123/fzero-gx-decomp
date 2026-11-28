#include "types.h"
#include "ppc_ops.h"
#include "sofdec/mpvabdec.h"
#include "ppc_lc.h"

struct fn_12_CCC4_lbl_12_bss_528C {
    u8 pad_0[0x50];
    u32 unk_50;
};

struct fn_12_CCC4_lbl_12_bss_527C {
    u32 unk_0;
};

struct fn_12_CCC4_lbl_12_bss_6900 {
    u32 unk_0;
};

struct fn_12_CCC4_lbl_12_bss_6904 {
    u32 unk_0;
};

struct fn_12_CCC4_lbl_12_bss_6908 {
    u32 unk_0;
};

typedef s32 MovieCallback;

typedef struct MovieObject {
    u8 pad_0000[0x188];
    s32 state;
    u8 pad_018c[4];
    MovieCallback callbacks[1];
} MovieObject;
extern u32 lbl_12_bss_5280;
extern void fn_12_CBC4(void);
extern u32 lbl_12_bss_528C[25];
extern s32 fn_12_A660(s32, s32);
extern void fn_12_20178();
extern struct fn_12_CCC4_lbl_12_bss_527C lbl_12_bss_527C;
extern struct fn_12_CCC4_lbl_12_bss_6900 lbl_12_bss_6900;
extern struct fn_12_CCC4_lbl_12_bss_6904 lbl_12_bss_6904;
extern struct fn_12_CCC4_lbl_12_bss_6908 lbl_12_bss_6908;
extern void fn_12_33364(u32 *dst, u32 *src, u32 size);
extern u32 fn_12_8B4C(u32);
extern u32 fn_12_A774(u32);
extern void fn_12_CA84(MovieObject *self, u32 value_1338, u32 value_133c);
extern u32 fn_12_CA98(u32, u32, u32, u32, u32);
extern u32 lbl_12_bss_68F0;
extern u32 lbl_12_bss_68F4;
extern u32 lbl_12_bss_68F8;
extern u32 lbl_12_bss_68FC;
extern u32 lbl_12_bss_6914;
extern u32 lbl_12_bss_6918;
extern void fn_12_5548(void *dst);
extern u32 fn_12_CCC4(u32 arg0);
extern int fn_12_2017C(void);
extern void fn_12_20184(void);

/* fzgx:begin fn_12_CAB4 */
/* --- rel/movie_module/fn_12_CAB4.c --- */

s32 fn_12_CAB4(u32 arg0) {
    u32 v0;
    u32 v1;
    lbl_12_bss_5280 = arg0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = -1;
    return v0;
    }
    v1 = *(u32 *)((u8 *)v0 + 392);
    v0 = (v1 - 2);
    v0 = ((s32)(v0 | (2 - v1)) >> 31);
    return v0;
}
/* fzgx:end fn_12_CAB4 */

/* fzgx:begin fn_12_CAE4 */
/* --- rel/movie_module/fn_12_CAE4.c --- */

typedef struct MovieManager {
    u8 pad_0000[0x54];
    s32 count;
    MovieObject *objects;
} MovieManager;


s32 fn_12_CAE4(MovieObject *movie, s32 index, MovieCallback callback) {
    MovieCallback *callbacks = 0;
    MovieManager *manager;
    s32 count;
    MovieObject *object;
    s32 i;
    s32 result;
    MovieCallback value;

    value = callback;
    if (index == 8 && callback == 0) {
        value = (s32)fn_12_CBC4;
    }
    if (movie == 0) {
        manager = (MovieManager *)lbl_12_bss_528C;
        count = manager->count;
        object = manager->objects;
        for (i = 0; i < count; i++) {
            if (object->state == 2) {
                object->callbacks[index] = value;
            }
            object = (MovieObject *)((u8 *)object + 0x2000);
        }
        callbacks = (MovieCallback *)lbl_12_bss_528C;
    } else {
        (((u32 *)&lbl_12_bss_5280))[0] = (u32)movie;
        if (movie == 0) {
            result = -1;
        } else if (movie->state != 2) {
            result = -1;
        } else {
            result = 0;
        }
        if (result != 0) {
            return fn_12_A660(0, 0xff030202);
        }
        callbacks = movie->callbacks;
    }
    callbacks[index] = value;
    return 0;
}
/* fzgx:end fn_12_CAE4 */

/* fzgx:begin fn_12_CBC4 */
/* --- rel/movie_module/fn_12_CBC4.c --- */
// fn_12_CBC4: empty in retail (single blr).
void fn_12_CBC4(void) {
}
/* fzgx:end fn_12_CBC4 */

/* fzgx:begin fn_12_CBC8 */
/* --- rel/movie_module/fn_12_CBC8.c --- */

s32 fn_12_CBC8(u32 arg0) {
    u32 v0;
    s32 v1;
    s32 t0;
    u32 movie;

    movie = arg0;
    (((u32 *)&lbl_12_bss_5280))[0] = movie;
    if (movie == 0) {
        t0 = -1;
    } else if (*(s32 *)((u8 *)movie + 392) != 2) {
        t0 = -1;
    } else {
        t0 = 0;
    }
    if (t0 != 0) {
        return fn_12_A660(0, 0xFF030201);
    }
    fn_12_20178(movie);
    if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
        v1 = 0;
        for (v0 = 256; v0 != 0; v0--) {
            ppc_dcbi((void *)movie, v1);
            v1 += 32;
        }
    }
    *(u32 *)((u8 *)movie + 392) = 1;
    return 0;
}
/* fzgx:end fn_12_CBC8 */

/* fzgx:begin fn_12_CCB0 */
/* --- rel/movie_module/fn_12_CCB0.c --- */
typedef struct MovieData {
    u8 unk_90[0x90];
    u32 unk_120;
    u32 unk_124;
} MovieData;

void fn_12_CCB0(const MovieData *movie, u32 *first, u32 *second) {
    *first = movie->unk_120;
    *second = movie->unk_124;
}
/* fzgx:end fn_12_CCB0 */

/* fzgx:begin fn_12_CCC4 */
#pragma use_lmw_stmw on



u32 fn_12_CCC4(u32 arg0) {
    struct fn_12_CCC4_lbl_12_bss_6900 *p_lbl_12_bss_6900;
    struct fn_12_CCC4_lbl_12_bss_6904 *p_lbl_12_bss_6904;
    struct fn_12_CCC4_lbl_12_bss_6908 *p_lbl_12_bss_6908;
    struct fn_12_CCC4_lbl_12_bss_527C *p_lbl_12_bss_527C;
    u32 v3;
    u32 v6;
    u32 v7;
    s32 v8;
    v3 = (*((struct fn_12_CCC4_lbl_12_bss_528C *)&lbl_12_bss_528C)).unk_50;
    p_lbl_12_bss_6900 = (struct fn_12_CCC4_lbl_12_bss_6900 *)&lbl_12_bss_6900;
    p_lbl_12_bss_6904 = (struct fn_12_CCC4_lbl_12_bss_6904 *)&lbl_12_bss_6904;
    p_lbl_12_bss_6908 = (struct fn_12_CCC4_lbl_12_bss_6908 *)&lbl_12_bss_6908;
    p_lbl_12_bss_527C = (struct fn_12_CCC4_lbl_12_bss_527C *)&lbl_12_bss_527C;
    *(u32 *)((u8 *)arg0 + 16) = lbl_12_bss_68F0;
    *(u32 *)((u8 *)arg0 + 20) = (lbl_12_bss_68F4 - 16);
    *(u32 *)((u8 *)arg0 + 24) = (lbl_12_bss_68F8 - 32);
    *(u32 *)((u8 *)arg0 + 28) = (lbl_12_bss_68FC - 32);
    *(u32 *)((u8 *)arg0 + 32) = p_lbl_12_bss_6900->unk_0;
    *(u32 *)((u8 *)arg0 + 36) = p_lbl_12_bss_6904->unk_0;
    *(u32 *)((u8 *)arg0 + 40) = p_lbl_12_bss_6908->unk_0;
    *(u32 *)((u8 *)arg0 + 56) = (v3 + 352);
    *(u32 *)((u8 *)arg0 + 60) = (v3 + 384);
    *(u32 *)((u8 *)arg0 + 44) = (v3 + 32);
    *(u32 *)((u8 *)arg0 + 48) = v3;
    *(u32 *)((u8 *)arg0 + 52) = (v3 + 96);
    *(u32 *)((u8 *)arg0 + 64) = p_lbl_12_bss_527C->unk_0;
    *(u32 *)((u8 *)arg0 + 272) = *(u32 *)((u8 *)arg0 + 64);
    *(u32 *)((u8 *)arg0 + 276) = (arg0 + 832);
    *(u32 *)((u8 *)arg0 + 280) = (arg0 + 3264);
    v6 = (*(u32 *)((u8 *)arg0 + 280) + 384);
    *(u32 *)((u8 *)arg0 + 284) = v6;
    *(u32 *)((u8 *)arg0 + 804) = (arg0 + 1088);
    *(u32 *)((u8 *)arg0 + 808) = (arg0 + 1216);
    *(u32 *)((u8 *)arg0 + 812) = (arg0 + 1344);
    *(u32 *)((u8 *)arg0 + 816) = (arg0 + 1472);
    *(u32 *)((u8 *)arg0 + 820) = (arg0 + 832);
    *(u32 *)((u8 *)arg0 + 824) = (arg0 + 960);
    *(u32 *)((u8 *)arg0 + 696) = 0;
    *(u32 *)((u8 *)arg0 + 396) = 0;
    fn_12_33364( (u32 *)(u32)((arg0 + 400)), (u32 *)((u32)&(*((struct fn_12_CCC4_lbl_12_bss_528C *)&lbl_12_bss_528C))), 16);
    fn_12_A774((arg0 + 544));
    fn_12_8B4C(arg0);
    v7 = (arg0 + 120);
    fn_12_5548((void *)v7);
    *(u32 *)((u8 *)v7 + 72) = (arg0 + 3264);
    *(u32 *)((u8 *)v7 + 44) = (arg0 + 1600);
    *(u32 *)((u8 *)v7 + 48) = (arg0 + 804);
    *(u32 *)((u8 *)arg0 + 464) = 0;
    *(u32 *)((u8 *)arg0 + 468) = 0;
    *(u32 *)((u8 *)arg0 + 472) = 0;
    *(u32 *)((u8 *)arg0 + 476) = 0;
    *(u32 *)((u8 *)arg0 + 480) = 0;
    *(u32 *)((u8 *)arg0 + 484) = 0;
    *(u32 *)((u8 *)arg0 + 488) = 0;
    *(u32 *)((u8 *)arg0 + 492) = 0;
    *(u32 *)((u8 *)arg0 + 496) = 0;
    *(u32 *)((u8 *)arg0 + 500) = 0;
    *(u32 *)((u8 *)arg0 + 504) = 0;
    *(u32 *)((u8 *)arg0 + 508) = 0;
    *(u32 *)((u8 *)arg0 + 512) = 0;
    *(u32 *)((u8 *)arg0 + 516) = 3;
    *(u32 *)((u8 *)arg0 + 520) = 1;
    *(u32 *)((u8 *)arg0 + 524) = -1;
    *(u32 *)((u8 *)arg0 + 528) = -1;
    *(u32 *)((u8 *)arg0 + 532) = -1;
    *(u32 *)((u8 *)arg0 + 536) = 1;
    *(u32 *)((u8 *)arg0 + 540) = 1;
    *(u32 *)((u8 *)arg0 + 4800) = 0;
    *(u32 *)((u8 *)arg0 + 4804) = 0;
    *(u32 *)((u8 *)arg0 + 4856) = lbl_12_bss_6918;
    *(u32 *)((u8 *)arg0 + 4860) = lbl_12_bss_6914;
    *(u32 *)((u8 *)arg0 + 4820) = 0;
    *(u32 *)((u8 *)arg0 + 4824) = 0;
    *(u32 *)((u8 *)arg0 + 4828) = 0;
    *(u32 *)((u8 *)arg0 + 4832) = 0;
    *(u32 *)((u8 *)arg0 + 4836) = 0;
    *(u32 *)((u8 *)arg0 + 4840) = (u32)MPVABDEC_IntraBlock;
    *(u32 *)((u8 *)arg0 + 4844) = (u32)MPVABDEC_NintraBlock;
    *(u32 *)((u8 *)arg0 + 4852) = *(u32 *)((u8 *)arg0 + 428);
    v8 = 0;
    do {
    fn_12_CA98(arg0, v8, 0, 0, 0);
    v8++;
    } while ((s32)v8 < 4);
    fn_12_CA84( (MovieObject *)(u32)(arg0), 0, 0);
    *(u32 *)((u8 *)arg0 + 392) = 2;
    return arg0;
}
/* fzgx:end fn_12_CCC4 */

/* fzgx:begin fn_12_CF2C */
/* --- rel/movie_module/fn_12_CF2C.c --- */
typedef struct MovieSlot {
    u8 pad_0[0x188];
    s32 active;
    u8 pad_18C[0x1300 - 0x18C];
    u32 unk_1300;
} MovieSlot;


static inline MovieSlot *movie_find_slot(void) {
    MovieSlot *slot;
    s32 n;

    slot = (MovieSlot *)lbl_12_bss_528C[22];
    for (n = lbl_12_bss_528C[21]; n > 0; n--) {
        if (slot->active == 1) {
            return slot;
        }
        slot = (MovieSlot *)((u8 *)slot + 0x2000);
    }
    return NULL;
}

static inline void movie_lc_clear(void *slot) {
    void *p;
    s32 off;
    u32 i;
    p = slot;

    if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
        off = 0;
        for (i = 32; i != 0; i--) {
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
        }
    }
}

void *fn_12_CF2C(void) {
    MovieSlot *slot;

    slot = movie_find_slot();
    if (!slot) {
        return NULL;
    }
    movie_lc_clear(slot);
    slot = (MovieSlot *)fn_12_CCC4((u32)slot);
    slot->unk_1300 = ((u32)fn_12_2017C());
    return slot;
}
/* fzgx:end fn_12_CF2C */

/* fzgx:begin fn_12_D038 */
/* --- rel/movie_module/fn_12_D038.c --- */

void fn_12_D038(void) {
    u32 v0;
    s32 v1;
    void *buffer;

    fn_12_20184();
    buffer = (void *)lbl_12_bss_528C[20];
    if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
        v1 = 0;
        for (v0 = 13; v0 != 0; v0--) {
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
        }
    }
}
/* fzgx:end fn_12_D038 */
