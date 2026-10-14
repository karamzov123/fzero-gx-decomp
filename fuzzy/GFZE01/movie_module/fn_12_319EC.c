/* Non-matching: best partial attempt (95.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieContext {
    int state;
    void *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

typedef struct MovieSlot {
    u8 prefix[0x18];
    u8 key;
    u8 suffix[0x27];
} MovieSlot;

typedef struct MovieEntry {
    MovieSlot first;
    MovieSlot second;
} MovieEntry;

typedef struct MovieData {
    u8 prefix[0x180];
    MovieEntry entries[13];
} MovieData;

#pragma opt_dead_assignments off
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
static inline u8 *fn_12_319EC_find(MovieData *movie, u32 code_in) {
    u8 *found = 0;
    s32 i;

    for (i = 0; i < 13; i++) {
        MovieSlot *a = &movie->entries[i].first;
        MovieSlot *b;

        if (a->key == (u8)code_in) {
            found = (u8 *)a;
            break;
        }

        b = &movie->entries[i].second;
        if (b->key == (u8)code_in) {
            found = (u8 *)b;
            break;
        }
    }

    return found;
}

#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
int fn_12_319EC(MovieContext *self, u8 code_in, u32 *result) {
    MovieData *movie = (MovieData *)self->movie;
    struct { int value; } kind_ok;
    int ok;
    struct { u8 *value; } found;
    u32 key;
    u32 klass;
    s16 raw;
    s32 value;

    switch (self->state) {
    case -1:
    case 0:
    case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind_ok.value = 0;
        if (self->kind == 0x6b || self->kind >= 0x6e) {
            kind_ok.value = 1;
            (void) kind_ok;
        }
        if (!(kind_ok.value != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        found.value = 0;
    } else {
        found.value = fn_12_319EC_find(movie, code_in);
    }

    if (0 == found.value) {
        return 0;
    }

    key = (u8)code_in;
    if (key >= 0xc0 && key <= 0xdf) {
        klass = 0xc0;
    } else if (key >= 0xe0 && key <= 0xef) {
        klass = 0xe0;
    } else if (key == 0xbd || key == 0xbf) {
        klass = 0xbd;
    } else {
        klass = 0;
    }

    if (klass != 0xe0) {
        return 0;
    }

    raw = *(u16 *)(found.value + 0x1a);
    value = (u32)(s16)(u16)((((0xFF00) & ((raw << 8)))) | ((raw >> 8) & 0xFF));
    if (value == 0xffff) {
        value = 0;
    }

    *result = value;
    return 1;
}
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
