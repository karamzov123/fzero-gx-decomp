/* Non-matching: best partial attempt (98.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern int fn_12_24A88(void *module, int code);
extern int fn_12_2F1B4(void *module, int index);
extern void fn_12_24970(void *movie);
extern void fn_12_24950(void *movie);
extern void fn_12_2CFEC(void *rec);

typedef struct MovieParams {
    s32 f0;
    u32 f4;
    u32 f8;
    s32 fc;
    s32 f10;
    s32 f14;
} MovieParams;

typedef struct MovieRec {
    u8 lab_pad[4];
    MovieParams params;
    u32 zeros[4];
} MovieRec;

typedef struct MovieEntry {
    u8 pad_0000[0x1140];
    s32 state;
    s32 flag;
    u8 pad_1148[8];
    MovieRec rec;
} MovieEntry;

#pragma opt_propagation off
#pragma opt_propagation off
static inline u32 * fn_12_226D0_read_pointer(MovieRec * owner) { return owner->zeros; }
int fn_12_226D0(void *arg0, MovieParams *p) {
    s32 tmp_call2;
    s8 movie[8];
    void *m;
    u32 flag;
    s32 err;
    int index;
    MovieRec *rec;
    MovieEntry *entry;

    m = arg0;

    if (p->f4 == 0) {
        err = -1;
    } else if (p->f0 == 0) {
        if (p->f8 == 0) {
            err = -1;
        } else if (p->fc <= 0) {
            err = -1;
        } else if (p->f14 > 0) {
            err = -1;
        }
    } else {
        err = 0;
    }
    if (err != 0) {
        return fn_12_24A88(m, 0xff000408);
    }

    tmp_call2 = fn_12_2F1B4(m, 1);
    if (tmp_call2) {
        index = 0;
    } else if (fn_12_2F1B4(m, 2)) {
        index = 1;
    } else if (fn_12_2F1B4(m, 3)) {
        index = 2;
    } else {
        index = 0;
    }

    entry = (MovieEntry *)((u8 *)m + index * 0x74);
    rec = &entry->rec;
    if (entry->state != 4) {
        return fn_12_24A88(m, 0xff000409);
    }

    err = (0 != p->f4);
    flag = err;
    fn_12_24970(movie);
    entry->flag = flag;
    rec->params = *p;
    fn_12_226D0_read_pointer(rec)[0] = 0;
    fn_12_226D0_read_pointer(rec)[1] = 0;
    fn_12_226D0_read_pointer(rec)[2] = 0;
    fn_12_226D0_read_pointer(rec)[3] = 0;
    fn_12_2CFEC((void *)((u8 *)rec + 0x28));
    fn_12_24950(movie);
    return 0;
}
#pragma opt_propagation reset
