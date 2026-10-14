/* Non-matching: best partial attempt (97.81% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s32 fn_1_8D5F0(s16);
extern s32 fn_1_F7BE4(s16);

typedef struct {
    s16 id;
    u32 flags;
} Entry;

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_1_152208(s16 *arg0, s16 arg1, Entry *arg2, s16 arg3, s16 arg4) {
    s16 w = arg4;
    s16 i;
    s16 j;
    s16 n;
    s16 k;
    struct { s16 value; } q;
    s16 col;
    s32 flag = 0;
    Entry *e;
    s16 id;

    for (i = 0; i < 41; i++) {
        if ((fn_1_8D5F0(i) & 0x10000000) != 0 && fn_1_F7BE4(i) != 0) {
            flag = 1;
            break;
        }
    }

    for (j = 0; j < arg3; j++) {
        for (n = 0; n < arg4; n++) {
            arg2[j * w + n].flags |= 0x40000000;
            arg2[j * w + n].id = -1;
        }
    }

    for (k = 0; k < arg1; k++) {
        id = arg0[k];
        if (id == -1) {
            continue;
        }
        q.value = k / w;
        col = k % w;
        e = &arg2[q.value * w + col];
        e->id = id;
        e->flags = 0;
        if (flag == 1) {
            e->flags |= 0x80000000;
        } else if ((fn_1_8D5F0(e->id) & 0x10000000) != 0) {
            e->flags |= 0x40000000;
        } else {
            e->flags |= 0x80000000;
        }
        if (fn_1_F7BE4(e->id) != 0) {
            e->flags &= 0x3FFFFFFF;
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

