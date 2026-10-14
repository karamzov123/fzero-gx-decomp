/* Non-matching: best partial attempt (44.41% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void fn_800565FC(const char *, ...);
extern char lbl_80092188[35];
extern char lbl_80092214[35];
extern size_t strlen(const char *);

typedef struct Rec {
    s32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
} Rec;

typedef struct Mgr {
    u8 pad0[1];
    s8 flag1;
    u8 pad2[0x1a];
    s32 field1c;
    u32 field20;
    s32 field24;
    u32 resource;
    u32 field2c;
    u8 pad30[8];
    Rec rec[16];
} Mgr;

s32 fn_80056E9C(Mgr *m, u32 *name, u32 a2, u32 a3, u32 a4) {
    Rec *rec;
    s32 id;
    u32 n;
    u32 i;
    s32 prev;

    if (m == 0) {
        fn_800565FC(lbl_80092188);
        return -1;
    }
    if (m->field24 >= 0x10) {
        return -1;
    }
    if (name == 0) {
        fn_800565FC(lbl_80092214);
        return -1;
    }
    rec = &m->rec[m->field1c];
    prev = m->rec[(m->field1c + 15) & 15].f00;
    id = (prev != 0x7FFFFFFF) ? prev + 1 : 0;
    rec->f00 = id;
    rec->f04 = (u32)name;
    n = strlen((char *)name) >> 2;
    rec->f08 = 0;
    for (i = 0; i < n; i++) {
        rec->f08 += name[i];
    }
    rec->f10 = a3;
    rec->f14 = a4;
    rec->f0c = a2;
    rec->f18 = 0;
    rec->f1c = 0;
    m->field24 = m->field24 + 1;
    m->field1c = (m->field1c + 1) % 16;
    if (m->flag1 == 1) {
        m->flag1 = 2;
    }
    return id;
}
