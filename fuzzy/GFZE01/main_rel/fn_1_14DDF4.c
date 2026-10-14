/* Non-matching: best partial attempt (94.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern s16 fn_1_14F344(s16 value);

struct entry {
    s16 id;
    u8 pad[0x226];
    u8 result[0x138];
};

void *fn_1_14DDF4(struct entry *arg0) {
    struct entry *base = arg0;
    s16 i;
    void *result = 0;
    struct entry *p = base;
    s32 tmp_call1;

    for (i = 0; (u32)i < 3; i++) {
        tmp_call1 = fn_1_14F344(p->id);
        if (tmp_call1 == 0) {
            result = &base[i].result;
            break;
        }
        p++;
    }
    return result;
}
