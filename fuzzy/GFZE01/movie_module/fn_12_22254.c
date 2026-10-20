/* Non-matching: best partial attempt (94.58% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieObject MovieObject;

typedef struct MovieVtable {
    char padding[0x18];
    s32 (*fn18)(MovieObject *, s32, s32, void *);
    char padding2[4];
    s32 (*fn1c)(MovieObject *, s32, void *);
} MovieVtable;

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieSub {
    char padding0[4];
    MovieObject *obj;
    char padding1[0x18];
    s32 value;
} MovieSub;

typedef struct MovieEntry {
    char padding0[0x1144];
    s32 field;
    char padding1[8];
    MovieSub sub;
} MovieEntry;

typedef struct MovieModule {
    char padding0[0x44];
    s32 flag;
} MovieModule;

typedef struct MovieState {
    s32 value;
} MovieState;

extern void fn_12_24970(MovieState *state);
extern void fn_12_24950(MovieState *state);
extern s32 fn_12_24A88(MovieModule *module, s32 code);

static inline s32 fn_12_22254_array_read(s32 index, s32 *array) { return array[index]; }
static inline s32 transfer_movie(MovieModule *module, MovieSub *sub,
                                 MovieObject *obj, s32 amount, s32 valid) {
    MovieState state;
    s32 w[2];
    s32 v[2];
    s32 result = 0;
    s32 left;
    if (valid == 0 || obj == NULL) {
        return 0;
    }
    fn_12_24970(&state);
    obj->vtable->fn18(obj, 0, amount, w);
    obj->vtable->fn1c(obj, 1, w);
    if (w[1] < amount) {
        left = amount - w[1];
        obj->vtable->fn18(obj, 0, left, v);
        obj->vtable->fn1c(obj, 1, v);
        if (v[1] < left) {
            result = fn_12_24A88(module, 0xff00040b);
        }
    }
    if (sub->value >= 0) {
        sub->value += amount;
    }
    module->flag = 1;
    fn_12_24950(&state);
    return result;
}

s32 fn_12_22254(MovieModule *module, s32 index, s32 amount) {
    MovieEntry *entry;
    MovieSub *sub;
    MovieObject *obj;
    s32 result = 0;
    entry = (MovieEntry *)((u8 *)module + index * 0x74);
    sub = &entry->sub;
    obj = sub->obj;
    if (amount != 0) {
        result = transfer_movie(module, sub, obj, amount, entry->field);
    }
    return result;
}
