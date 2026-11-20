#include "types.h"


/* --- rel/movie_module/fn_12_22390.c --- */
typedef struct MovieObject MovieObject;

typedef struct MovieVtable {
    char padding[0x18];
    u32 (*fn18)(MovieObject *, int, int, void *);
    u32 (*fn1c)(MovieObject *, int, void *);
    char padding2[4];
    u32 (*fn24)(MovieObject *, int);
} MovieVtable;

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieEntry {
    char padding0[0x1144];
    int field;
    char padding1[0xc];
    MovieObject *obj;
} MovieEntry;

typedef struct MovieState {
    u8 data[4];
} MovieState;

extern void fn_12_24970(MovieState *state);
extern void fn_12_24950(MovieState *state);

int fn_12_22390(u8 *module, int index, u32 *out) {
    MovieState state;
    u32 w[2];
    u32 v[2];
    MovieEntry *entry;
    MovieObject *obj;
    int result;

    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 0;
    entry = (MovieEntry *)(module + index * 0x74);
    obj = entry->obj;
    if (entry->field == 0 || obj == 0) {
        return 0;
    }
    fn_12_24970(&state);
    result = obj->vtable->fn24(obj, 1);
    obj->vtable->fn18(obj, 1, 0x7fffffff, v);
    if ((int)v[1] < result) {
        obj->vtable->fn18(obj, 1, 0x7fffffff, w);
        obj->vtable->fn1c(obj, 1, w);
    } else {
        w[0] = 0;
        w[1] = 0;
    }
    obj->vtable->fn1c(obj, 1, v);
    out[0] = v[0];
    out[1] = v[1];
    out[2] = w[0];
    out[3] = w[1];
    fn_12_24950(&state);
    return 0;
}

/* --- rel/movie_module/fn_12_224FC.c --- */
s32 fn_12_224FC(u8 *arg0, int arg1, u32 *arg2) {
    MovieState loc_8;
    MovieEntry *v0;
    struct { u32 a[2]; } loc_14;
    u32 loc_C[2];
    MovieObject *v1;
    int v4;
    arg2[0] = 0;
    v0 = (MovieEntry *)(arg0 + arg1 * 116);
    arg2[1] = 0;
    arg2[2] = 0;
    arg2[3] = 0;
    arg2[4] = 0;
    arg2[5] = 0;
    arg2[6] = 0;
    v1 = v0->obj;
    if (v0->field == 0 || v1 == 0) {
        return 0;
    }
    fn_12_24970(&loc_8);
    v4 = v1->vtable->fn24(v1, 0);
    v1->vtable->fn18(v1, 0, 0x7fffffff, loc_C);
    if ((s32)loc_C[1] < v4) {
        v1->vtable->fn18(v1, 0, 0x7fffffff, &loc_14);
        v1->vtable->fn1c(v1, 0, &loc_14);
    } else {
        loc_14.a[0] = 0;
        loc_14.a[1] = 0;
    }
    v1->vtable->fn1c(v1, 0, loc_C);
    arg2[0] = loc_C[0];
    arg2[1] = loc_C[1];
    arg2[2] = loc_14.a[0];
    arg2[3] = loc_14.a[1];
    fn_12_24950(&loc_8);
    return 0;
}

/* --- rel/movie_module/fn_12_22668.c --- */
struct fn_12_22668_Copy16 {
    u32 a[4];
};

struct fn_12_22668_Entry {
    u8 pad[0x1150];
};

void fn_12_22668(u8 *module, int index, int subindex, struct fn_12_22668_Copy16 *dst) {
    struct fn_12_22668_Entry *entry;

    entry = (struct fn_12_22668_Entry *)(module + index * 0x74);
    entry = (struct fn_12_22668_Entry *)((u8 *)entry + subindex * 0x10);
    *dst = *(struct fn_12_22668_Copy16 *)((u8 *)entry + 0x1150);
}

/* --- rel/movie_module/fn_12_2269C.c --- */
struct fn_12_2269C_Copy16 {
    u32 a[4];
};

struct fn_12_2269C_Entry {
    u8 pad[0x1150];
};

void fn_12_2269C(u8 *module, int index, int subindex,
                 struct fn_12_2269C_Copy16 *src) {
    struct fn_12_2269C_Entry *entry;

    entry = (struct fn_12_2269C_Entry *)(module + index * 0x74);
    entry = (struct fn_12_2269C_Entry *)((u8 *)entry + subindex * 0x10);
    *(struct fn_12_2269C_Copy16 *)((u8 *)entry + 0x1150) = *src;
}
