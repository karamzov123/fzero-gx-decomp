#include "types.h"
#include "psvec_quant.h"

extern f32 lbl_801A7194;
extern f32 lbl_801A7198;
extern f32 lbl_801A719C;
extern f32 lbl_801A71A0;

void fn_8003BB30(register void *d, register void *a, register void *b, register void *c, u32 n) {
    register f32 k0 = lbl_801A7194;
    register f32 k1 = lbl_801A7198;
    register f32 k2 = lbl_801A719C;
    register f32 k3 = lbl_801A71A0;
    register f32 t1, t2, t3;
    u32 i;

    psq27_merge2_setup(k1, k2, k3)
    for (i = 0; i < n; i += 2) {
        psq27_merge2(d, a, b, c, k0, t1, t2, t3)
    }
}
