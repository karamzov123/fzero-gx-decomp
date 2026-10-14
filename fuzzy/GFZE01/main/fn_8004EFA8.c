/* Non-matching: best partial attempt (82.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_8017B028[];
extern u32 fn_8004F00C(u32, u32, u32, u32, u32, u32, u32, u32, u32, s16, s16);
extern u32 fn_8004F26C(u32, u32, u32, u32, u32, u32, u32, u32, u32, s16, s16);

void fn_8004EFA8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, s16 j, s16 k) {
    if ((s32)lbl_8017B028[0] == 0) {
        fn_8004F00C(a, b, c, d, e, f, g, h, i, j, k);
    } else {
        fn_8004F26C(a, b, c, d, e, f, g, h, i, j, k);
    }
}
