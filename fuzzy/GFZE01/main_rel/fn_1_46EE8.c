/* Non-matching: best partial attempt (72.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"

extern void fn_8000659C(void);

typedef struct {
    s32 f0;
    s32 f1;
    s32 f2;
    s32 f3;
} Rec;

void fn_1_46EE8(void) {
    s32 *b = (s32 *)&lbl_1_bss_384C0;
    Rec *rec;
    s32 *w;
    s32 i;
    s32 k;

    fn_8000659C();

    if (b[0] != b[1]) {
        rec = (Rec *)((u8 *)b + 0x18);
        for (i = 0; i < 0x400; i++) {
            if ((((u32)rec[i].f0 + 0x8000) >> 16) == 0) {
                rec[i].f0 = 0;
                *(s32 *)((u8 *)b + 0x5818) = rec[i].f1;
            }
        }
        b[1] = b[0];
    }

    w = (s32 *)((u8 *)b + 0x18);
    for (k = 0; k < 0x400; k++) {
        if (!(w[k] & 0x10000000)) {
            w[k] = 0;
            if (k < *(s32 *)((u8 *)b + 0x5820)) {
                *(s32 *)((u8 *)b + 0x5820) = k;
            }
        }
    }
}
