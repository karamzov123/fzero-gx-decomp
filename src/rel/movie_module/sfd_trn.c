#include "types.h"

/* fzgx:begin fn_12_2F1B4 noprologue */
#include "types.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_2F1B4.c --- */
/* --- rel/movie_module/fn_12_2F1B4.c --- */
typedef struct MovieEntry {
    int field_0;
    char unk_4[0x40];
} MovieEntry;

typedef struct MovieModuleState_u3 {
    char unk_0[0x1aac];
    MovieEntry entries[1];
} MovieModuleState_u3;

int fn_12_2F1B4(MovieModuleState_u3 *state, int index) {
    return state->entries[index].field_0 != 0;
}
/* fzgx:end fn_12_2F1B4 */

/* fzgx:begin fn_12_2F1D0 noprologue */

/* --- rel/movie_module/fn_12_2F1D0.c --- */
struct fn_12_2F1D0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct fn_12_2F1D0_Arg0 {
    u8 pad_0[0x1AA4];
    struct fn_12_2F1D0_E68_u32 unk_1AA4[1];
};

u32 fn_12_2F1D0(struct fn_12_2F1D0_Arg0 *arg0, u32 arg1) {
    return arg0->unk_1AA4[arg1].unk_0;
}
/* fzgx:end fn_12_2F1D0 */

/* fzgx:begin fn_12_2F1E0 noprologue */

/* --- rel/movie_module/fn_12_2F1E0.c --- */
struct MovieSlot {
    int value;
    char pad[0x40];
};

struct Movie {
    char pad[0x1aa4];
    struct MovieSlot slots[1];
};

void fn_12_2F1E0(struct Movie *movie, int index, int value) {
    movie->slots[index].value = value;
}
/* fzgx:end fn_12_2F1E0 */

/* fzgx:begin fn_12_2F1F0 noprologue */

/* --- rel/movie_module/fn_12_2F1F0.c --- */
struct fn_12_2F1F0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct fn_12_2F1F0_Arg0 {
    u8 pad_0[0x1AA0];
    struct fn_12_2F1F0_E68_u32 unk_1AA0[1];
};

u32 fn_12_2F1F0(struct fn_12_2F1F0_Arg0 *arg0, u32 arg1) {
    return arg0->unk_1AA0[arg1].unk_0;
}
/* fzgx:end fn_12_2F1F0 */

/* fzgx:begin fn_12_2F200 noprologue */

/* --- rel/movie_module/fn_12_2F200.c --- */
/* --- rel/movie_module/fn_12_2F200.c --- */
struct MovieItem {
    int value;
    char pad[0x40];
};

struct Movie_u4 {
    char pad[0x1aa0];
    struct MovieItem items[1];
};

void fn_12_2F200(struct Movie_u4 *movie, int index, int value) {
    movie->items[index].value = value;
}
/* fzgx:end fn_12_2F200 */

/* fzgx:begin fn_12_2F210 noprologue */

/* --- rel/movie_module/fn_12_2F210.c --- */
typedef u32 (*fn_12_2F210_Fn0)(u32, u32, u32, u32);

struct fn_12_2F210_arg0_1A90_E68 {
    u8 pad_0[0x1C];
    fn_12_2F210_Fn0 *unk_1C;
    u8 pad_20[0x24];
};

struct fn_12_2F210_Arg0 {
    u8 pad_0[0x1A90];
    struct fn_12_2F210_arg0_1A90_E68 unk_1A90[1];
};

u32 fn_12_2F210(struct fn_12_2F210_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    fn_12_2F210_Fn0 *callbacks;

    callbacks = arg0->unk_1A90[arg1].unk_1C;
    if (callbacks == 0) {
        return 0;
    }
    return callbacks[arg2]((u32)arg0, arg3, arg4, 0);
}
/* fzgx:end fn_12_2F210 */

/* fzgx:begin fn_12_2F264 noprologue */

/* --- rel/movie_module/fn_12_2F264.c --- */
struct Movie_u5;

typedef int (*MovieHandler)(struct Movie_u5 *, int, int, int);

struct MovieItem_u5 {
    char pad0[0xc];
    MovieHandler *handlers;
    char pad1[0x30];
    char pad2[4];
};

struct Movie_u5 {
    char pad0[0x1aa0];
    struct MovieItem_u5 items[1];
};

int fn_12_2F264(struct Movie_u5 *movie, int index) {
    int i;
    int result;
    struct MovieItem_u5 *item;

    result = 0;
    item = movie->items;
    for (i = 0; i < 9; i++, item++) {
        if (item->handlers != 0) {
            result = item->handlers[index](movie, 0, 0, 0);
            if (result != 0) {
                break;
            }
        }
    }
    return result;
}
/* fzgx:end fn_12_2F264 */

/* fzgx:begin fn_12_2F2F4 noprologue */

/* --- rel/movie_module/fn_12_2F2F4.c --- */
extern void fn_12_2D7DC(void *, int, int);

struct MovieItem_u6 {
    char pad0[8];
    void *field8;
    void *fieldC;
    void *field10;
    void *field14;
    char pad1[8];
    void *field20;
};

struct Movie_u6 {
    char pad0[0xB44];
    int fieldB44;
    int fieldB48;
    char pad1[0x644];
    int field1190;
    char pad2[0x6C];
    int field1200;
    int field1204;
    char pad3[0x6C];
    int field1274;
    int field1278;
    char pad4[0x6C];
    int field12E8;
    int field12EC;
    char pad5[0x6C];
    int field135C;
    int field1360;
    char pad6[0x6C];
    int field13D0;
    int field13D4;
    char pad7[0x6C];
    int field1444;
    int field1448;
    char pad8[0x6C];
    int field14B8;
    int field14BC;
    char pad9[0x634];
    int field1AF4;
    int field1AF8;
    int field1AFC;
    int field1B00;
    char pad10[0x34];
    int field1B38;
    int field1B3C;
    char pad11[0x3C];
    int field1B7C;
    int field1B80;
    char pad12[0x3C];
    int field1BC0;
    int field1BC4;
    char pad13[0x3C];
    int field1C04;
    int field1C08;
    char pad14[0x3C];
    int field1C48;
    char pad15[0x40];
    int field1C8C;
    char pad16[0x40];
    int field1CD0;
};

void fn_12_2F2F4(struct Movie_u6 *movie, struct MovieItem_u6 *item) {
    movie->field1190 = 1;
    movie->field1AF4 = 0;
    if (item->field8 != 0) {
        movie->field1AF8 = 1;
        movie->field1200 = 1;
        movie->field1204 = 2;
        movie->field1B38 = 1;
        movie->field1B3C = 3;
        movie->field12E8 = 2;
        if (item->field10 != 0) {
            movie->field12EC = 4;
            movie->field1BC0 = 3;
            movie->field1BC4 = 5;
            movie->field13D0 = 4;
            movie->field13D4 = 6;
            movie->field1C48 = 5;
        } else {
            movie->field12EC = 6;
            movie->field1C48 = 3;
        }
    } else {
        fn_12_2D7DC(movie, 5, 0);
        movie->fieldB44 = 0;
    }
    if (item->fieldC != 0) {
        movie->field1AFC = 2;
        movie->field1274 = 1;
        movie->field1278 = 3;
        movie->field1B7C = 2;
        movie->field1B80 = 4;
        movie->field135C = 3;
        if (item->field14 != 0) {
            movie->field1360 = 5;
            movie->field1C04 = 4;
            movie->field1C08 = 6;
            movie->field1444 = 5;
            movie->field1448 = 7;
            movie->field1C8C = 6;
        } else {
            movie->field1360 = 7;
            movie->field1C8C = 4;
        }
    } else {
        fn_12_2D7DC(movie, 6, 0);
        movie->fieldB48 = 0;
    }
    if (item->field20 != 0) {
        movie->field1B00 = 7;
        movie->field14B8 = 1;
        movie->field14BC = 8;
        movie->field1CD0 = 7;
    }
}
/* fzgx:end fn_12_2F2F4 */

/* fzgx:begin fn_12_2F474 noprologue */
#include "types.h"

struct MovieConfig {
    char pad0[4];
    u32 item0;
    u32 item1;
    u32 item2;
    u32 item3;
    u32 item4;
    char pad1[8];
    u32 item5;
};

struct Movie {
    char pad0[0xb44];
    u32 result0;
    u32 result1;
    char pad1[0x640];
    u32 value118c;
    char pad2[0x70];
    u32 value1200;
    u32 value1204;
    char pad3[0x6c];
    u32 value1274;
    u32 value1278;
    char pad4[0x6c];
    u32 value12e8;
    u32 value12ec;
    char pad5[0x6c];
    u32 value135c;
    u32 value1360;
    char pad6[0x6c];
    u32 value13d0;
    u32 value13d4;
    char pad7[0x6c];
    u32 value1444;
    u32 value1448;
    char pad8[0x6c];
    u32 value14b8;
    u32 value14bc;
    char pad9[0x5f4];
    u32 value1ab4;
    char pad10[0x80];
    u32 value1b38;
    u32 value1b3c;
    char pad11[0x3c];
    u32 value1b7c;
    u32 value1b80;
    char pad12[0x3c];
    u32 value1bc0;
    u32 value1bc4;
    char pad13[0x3c];
    u32 value1c04;
    u32 value1c08;
    char pad14[0x3c];
    u32 value1c48;
    char pad15[0x40];
    u32 value1c8c;
    char pad16[0x40];
    u32 value1cd0;
};

extern void fn_12_2F2F4(struct Movie *movie);
extern void fn_12_2D7DC(struct Movie *movie, int a, int b);

int fn_12_2F474(struct Movie *movie, struct MovieConfig *config) {
    if (config->item0 != 0) {
        movie->value1ab4 = 0;
        movie->value118c = 0;
        fn_12_2F2F4(movie);
    } else if (config->item1 != 0) {
        movie->value1ab4 = 1;
        movie->value1200 = 0;
        movie->value1204 = 2;
        movie->value1b38 = 1;
        movie->value1b3c = 3;
        movie->value12e8 = 2;
        if (config->item3 != 0) {
            movie->value12ec = 4;
            movie->value1bc0 = 3;
            movie->value1bc4 = 5;
            movie->value13d0 = 4;
            movie->value13d4 = 6;
            movie->value1c48 = 5;
        } else {
            movie->value12ec = 6;
            movie->value1c48 = 3;
        }
        fn_12_2D7DC(movie, 6, 0);
        movie->result1 = 0;
    } else if (config->item2 != 0) {
        movie->value1ab4 = 2;
        movie->value1274 = 0;
        movie->value1278 = 3;
        movie->value1b7c = 2;
        movie->value1b80 = 4;
        movie->value135c = 3;
        if (config->item4 != 0) {
            movie->value1360 = 5;
            movie->value1c04 = 4;
            movie->value1c08 = 6;
            movie->value1444 = 5;
            movie->value1448 = 7;
            movie->value1c8c = 6;
        } else {
            movie->value1360 = 7;
            movie->value1c8c = 4;
        }
        fn_12_2D7DC(movie, 5, 0);
        movie->result0 = 0;
    } else if (config->item5 != 0) {
        movie->value1ab4 = 7;
        movie->value14b8 = 0;
        movie->value14bc = 8;
        movie->value1cd0 = 7;
        fn_12_2D7DC(movie, 6, 0);
        fn_12_2D7DC(movie, 5, 0);
        movie->result1 = 0;
        movie->result0 = 0;
    } else {
        return -1;
    }
    return 0;
}
/* fzgx:end fn_12_2F474 */

/* fzgx:begin fn_12_2F63C noprologue */
#include "types.h"
struct Sig_fn_12_2F474_Movie {
    char pad0[0xb44];
    u32 result0;
    u32 result1;
    char pad1[0x640];
    u32 value118c;
    char pad2[0x70];
    u32 value1200;
    u32 value1204;
    char pad3[0x6c];
    u32 value1274;
    u32 value1278;
    char pad4[0x6c];
    u32 value12e8;
    u32 value12ec;
    char pad5[0x6c];
    u32 value135c;
    u32 value1360;
    char pad6[0x6c];
    u32 value13d0;
    u32 value13d4;
    char pad7[0x6c];
    u32 value1444;
    u32 value1448;
    char pad8[0x6c];
    u32 value14b8;
    u32 value14bc;
    char pad9[0x5f4];
    u32 value1ab4;
    char pad10[0x80];
    u32 value1b38;
    u32 value1b3c;
    char pad11[0x3c];
    u32 value1b7c;
    u32 value1b80;
    char pad12[0x3c];
    u32 value1bc0;
    u32 value1bc4;
    char pad13[0x3c];
    u32 value1c04;
    u32 value1c08;
    char pad14[0x3c];
    u32 value1c48;
    char pad15[0x40];
    u32 value1c8c;
    char pad16[0x40];
    u32 value1cd0;
};
struct Sig_fn_12_2F474_MovieConfig {
    char pad0[4];
    u32 item0;
    u32 item1;
    u32 item2;
    u32 item3;
    u32 item4;
    char pad1[8];
    u32 item5;
};
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
struct fn_12_2F63C_Arg2 { u32 unk_0; };
extern int fn_12_2F474(struct Sig_fn_12_2F474_Movie *, struct Sig_fn_12_2F474_MovieConfig *);
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
#pragma opt_propagation off
s32 fn_12_2F63C(s32 arg0, s32 arg1, struct fn_12_2F63C_Arg2 *arg2, s32 arg3) {
    s32 neg = -1;
    u32 eight;
    s32 t1;
    u32 zero = 0;
    int t0;
    u32 v6;
    int v7;
    u32 v5;
    u32 v4;
    s32 v2;
    u32 v3;
    u32 v1;
    u32 v0;
    eight = 8;
    v0 = arg2->unk_0;
    v3 = v0;
    v2 = arg1;
    for (v1 = 3; v1 != 0; v1--) {
        *(u32 *)((u8 *)v2 + 8) = zero;
        v4 = *(u32 *)((u8 *)v3 + 0);
        *(u32 *)((u8 *)v2 + 4) = zero;
        *(u32 *)((u8 *)v2 + 0) = zero;
        *(u32 *)((u8 *)v2 + 12) = v4;
        *(u32 *)((u8 *)v2 + 16) = eight;
        *(u32 *)((u8 *)v2 + 20) = eight;
        *(u32 *)((u8 *)v2 + 24) = eight;
        *(u32 *)((u8 *)v2 + 28) = eight;
        *(u32 *)((u8 *)v2 + 32) = neg;
        *(u32 *)((u8 *)v2 + 76) = zero;
        v5 = *(u32 *)((u8 *)v3 + 4);
        *(u32 *)((u8 *)v2 + 72) = zero;
        *(u32 *)((u8 *)v2 + 68) = zero;
        *(u32 *)((u8 *)v2 + 80) = v5;
        *(u32 *)((u8 *)v2 + 84) = eight;
        *(u32 *)((u8 *)v2 + 88) = eight;
        *(u32 *)((u8 *)v2 + 92) = eight;
        *(u32 *)((u8 *)v2 + 96) = eight;
        *(u32 *)((u8 *)v2 + 100) = neg;
        *(u32 *)((u8 *)v2 + 144) = zero;
        v6 = *(u32 *)((u8 *)v3 + 8);
        *(u32 *)((u8 *)v2 + 140) = zero;
        v3 += 12;
        *(u32 *)((u8 *)v2 + 136) = zero;
        *(u32 *)((u8 *)v2 + 148) = v6;
        *(u32 *)((u8 *)v2 + 152) = eight;
        *(u32 *)((u8 *)v2 + 156) = eight;
        *(u32 *)((u8 *)v2 + 160) = eight;
        *(u32 *)((u8 *)v2 + 164) = eight;
        *(u32 *)((u8 *)v2 + 168) = neg;
        v2 += 204;
    }
    t0 = fn_12_2F474((struct Sig_fn_12_2F474_Movie *)arg0, (struct Sig_fn_12_2F474_MovieConfig *)v0);
    v7 = t0;
    if ((s32)t0 != 0) {
        v7 = arg0;
        t1 = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)v7, 0xFF000302);
        v7 = t1;
    } else {
        v7 = 0;
    }
    return v7;
}
/* fzgx:end fn_12_2F63C */

/* fzgx:begin fn_12_2F730 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2F730.c --- */
/* --- rel/movie_module/fn_12_2F730.c --- */
typedef int (*movie_callback_fn)(void *, int, int, int);
typedef struct {
    void *unk_0;
    movie_callback_fn fn_4;
} movie_callback_t;

int fn_12_2F730(movie_callback_t **arg0) {
    struct { int result; int i; } fzgx_copy_state;
    movie_callback_t ** p;
    fzgx_copy_state.result = 0;
    p = arg0;
    fzgx_copy_state.i = fzgx_copy_state.result;
    do {
        movie_callback_t *entry = *p;
        if (entry == 0) {
            break;
        }
        fzgx_copy_state.result = entry->fn_4(0, 0, 0, 0);
        if (fzgx_copy_state.result != 0) {
            break;
        }
        fzgx_copy_state.i++;
        p++;
    } while (fzgx_copy_state.i < 15);
    return fzgx_copy_state.result;
}
/* fzgx:end fn_12_2F730 */

/* fzgx:begin fn_12_2F7AC noprologue */

/* --- rel/movie_module/fn_12_2F7AC.c --- */
typedef struct {
    int (*m_callback)(int, int, int, int);
} movie_object;

typedef struct {
    movie_object *m_objs[15];
} movie_hook_table;

typedef struct {
    int result;
    int index;
} loop_state;

int fn_12_2F7AC(movie_hook_table *arg0, movie_hook_table *arg1) {
    loop_state s;
    movie_object **table = arg1->m_objs;

    s.result = 0;
    s.index = s.result;
    *arg0 = *arg1;
    do {
        movie_object *obj = *table;
        if (obj == NULL) {
            break;
        }
        s.result = obj->m_callback(0, 0, 0, 0);
        if (s.result != 0) {
            break;
        }
        s.index++;
        table++;
    } while (s.index < 15);
    return s.result;
}
/* fzgx:end fn_12_2F7AC */
