/* Non-matching: best partial attempt (92.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieContext {
    int state;
    u8 *group;
    u8 _pad[4];
    int kind;
} MovieContext;

#pragma peephole off
static inline u8 *fn_12_31DFC_array_read(u8 *array) { return array; }
static inline u8 *fn_12_31DFC_array_read_(u8 *array) { return array; }
#pragma opt_common_subs off
#pragma opt_strength_reduction off
int fn_12_31DFC(MovieContext *self, u32 arg1, u32 *result) {
    int kind_ok;
    int kind;
    int ok;
    int i;
    u32 mapped;
    u8 id;
    u8 *found;
    u8 *p = self->group;

    switch (self->state) {
    case -1: case 0: case 1: {
        ok = 0;
    } break;
    default: {
        ok = 1;
    } break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        found = 0;
    } else {
        found = 0;
        for (i = 0; i < 0; i++, p += 0x80) {
            if ((*((0x198) + (p))) == (u8)arg1) {
                found = p + 0x180;
                break;
            }
            if ((*((0x1d8) + (p))) == (u8)arg1) {
                found = p + 0x1c0;
                break;
            }
        }
    }

    if (!(found)) {
        return 0;
    }

    id = (u8)arg1;
    if (id >= 0xc0 && id <= 0xdf) {
        mapped = 0xc0;
    } else if (id >= 0xe0 && id <= 0xef) {
        mapped = 0xe0;
    } else if (id == 0xbd || id == 0xbf) {
        mapped = 0xbd;
    } else {
        mapped = 0;
    }

    if (mapped != 0xc0) {
        return 0;
    }

    *result = (*((0x1b) + (found)));
    return 1;
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma peephole reset
