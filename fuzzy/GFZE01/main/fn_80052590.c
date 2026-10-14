/* Non-matching: best partial attempt (84.16% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f32 lbl_80091338[6];

void fn_80052590(f32 *arg0, f32 *arg1, u16 *arg2) {
    s32 n = 32;

    do {
        f32 f;
        f = lbl_80091338[0];
        f += arg1[0] * arg0[0];
        f += arg1[1] * arg0[96];
        f += arg1[2] * arg0[-896];
        f += arg1[3] * arg0[-800];
        f += arg1[4] * arg0[-768];
        f += arg1[5] * arg0[-672];
        f += arg1[6] * arg0[-640];
        f += arg1[7] * arg0[-544];
        f += arg1[8] * arg0[-512];
        f += arg1[9] * arg0[-416];
        f += arg1[10] * arg0[-384];
        f += arg1[11] * arg0[-288];
        f += arg1[12] * arg0[-256];
        f += arg1[13] * arg0[-160];
        f += arg1[14] * arg0[-128];
        f += arg1[15] * arg0[-32];
        if (f > 2147483648.0f) {
            f = 2147483648.0f;
        } else if (f < -2147483648.0f) {
            f = -2147483648.0f;
        }
        *arg2 = (u16)(f32)(s16)f;
        arg2++;
        arg0++;
        arg1 += 16;
    } while (--n != 0);
}
