/* Non-matching: best partial attempt (71.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_8019DF90[132];
extern const f32 lbl_801A7370;
extern const f32 lbl_801A7374;
extern const f32 lbl_801A7378;
extern const f32 lbl_801A737C;
extern const f64 lbl_801A7380;
extern f64 fn_80088598(f32 a, f32 b);

void fn_8006B99C(void) {
    s32 i;
    f32 r;

    for (i = 0; i < 0x81; i++) {
        if (i < 0) {
            r = -(lbl_801A7378 + lbl_801A737C * (f32)fn_80088598((f32)(-i) * lbl_801A7370, lbl_801A7374));
        } else {
            r = lbl_801A7378 + lbl_801A737C * (f32)fn_80088598((f32)i * lbl_801A7370, lbl_801A7374);
        }
        lbl_8019DF90[i] = (s32)r;
    }
}
