#include "types.h"
#include "ppc_ops.h"

extern u32 lbl_12_bss_528C[25];
extern void fn_12_20184(void);

void fn_12_D038(void) {
    u32 v0;
    s32 v1;
    void *buffer;

    fn_12_20184();
    buffer = (void *)lbl_12_bss_528C[20];
    if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
        v1 = 0;
        for (v0 = 13; v0 != 0; v0--) {
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
            ppc_dcbi(buffer, v1);
            v1 += 32;
        }
    }
}
