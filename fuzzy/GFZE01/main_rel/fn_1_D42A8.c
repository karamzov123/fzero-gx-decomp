/* Non-matching: best partial attempt (78.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 fn_1_681C(u32 index, void *out);
extern u32 fn_1_6898(u32 index, void *out);
extern f32 lbl_1_rodata_6168[112];

typedef struct { f32 x, y, z; } D42A8Vec;

#pragma opt_common_subs off
void fn_1_D42A8(f32 *base, u32 index) {
    D42A8Vec a;
    D42A8Vec b;
    f32 value;
    fn_1_681C(index & 0xff, &a);
    fn_1_6898(index & 0xff, &b);
    value = lbl_1_rodata_6168[0];
    if ((f32)((a.x-b.x)*(a.x-b.x)) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z) < value) {
        value = (f32)((a.x-b.x)*(a.x-b.x)) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
    }
    base[index] = value;
}
#pragma opt_common_subs reset
