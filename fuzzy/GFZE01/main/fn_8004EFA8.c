/* Non-matching: best partial attempt (83.40% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const u32 lbl_8017B028[];
extern u32 fn_8004F00C(u64, u32, u32, u64, u32, u32, u32, s16, s16);
extern u32 fn_8004F26C(u64, u32, u32, u64, u32, u32, u32, s16, s16);

void fn_8004EFA8(u64 a_b, u32 c, u32 d, u64 e_f, u32 g, u32 h, u32 i, s16 j, s16 k) {
    if ((u32)lbl_8017B028[0] == 0) {
        fn_8004F00C(a_b, c, d, e_f, g, h, i, j, k);
    } else {
        fn_8004F26C(a_b, c, d, e_f, g, h, i, j, k);
    }
}
