/* Non-matching: best partial attempt (42.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct RNAResEntry {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} RNAResEntry;

typedef struct fn_8005C120_Globals {
    u32 count;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    RNAResEntry entries[32];
} fn_8005C120_Globals;

extern fn_8005C120_Globals lbl_80192BD0;
extern u32 fn_8001E954(u32);
extern void *memset(void *, int, u32);

void fn_8005C120(void) {
    fn_8005C120_Globals *p = (fn_8005C120_Globals *)&lbl_80192BD0;
    RNAResEntry *e;
    u8 *bp;
    u32 count;
    u32 i;

    if (p->count == 0) {
        if (p->unk_4 == 0) {
            p->unk_8 = 0x20;
            p->unk_C = 0x40000;
            p->unk_10 = fn_8001E954(0x40000);
        }
        memset(p->entries, 0, 0x180);
    }
    count = p->unk_8;
    e = p->entries;
    bp = (u8 *)p->unk_10;
    for (i = 0; i < count; i++) {
        e[i].unk_4 = (u32)(bp + i * 0x2000) >> 1;
        e[i].unk_8 = 0x1000;
    }
    p->count++;
}
