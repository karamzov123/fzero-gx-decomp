/* Non-matching: best partial attempt (98.25% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s16 fn_1_14F01C(void *arg);
extern s16 fn_1_14F090(void *table, s16 index);
extern void *fn_1_14F344(void *self);

u8 *fn_1_14F608(void *arg0) {
    s16 value;
    s16 index;
    u8 *base;
    void *table;

    table = fn_1_14F344(arg0);

    switch ((s16)table) {
    case 0:
        base = (u8 *)0x23801F04;
        break;
    case 1:
        base = (u8 *)0x23803098;
        break;
    case 2:
        base = (u8 *)0x2380422C;
        break;
    default:
        base = (u8 *)0x23801F04;
        break;
    }

    value = (s16)arg0;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (fn_1_14F090(table, index) == value) {
            continue; /* not the entry we are looking for */
        }
        goto found; /* shared with the not-found exit */
    }
    index = -1;
found:
    return base + index * 0xb4;
}
